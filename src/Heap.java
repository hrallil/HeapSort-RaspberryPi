import java.util.ArrayList;
import java.util.HashMap;

class MinHeap<T extends Comparable<T> >{
    HashMap<T,Integer> positionTable=new HashMap<>();

    // root is at index 0
    ArrayList<T> memmory;
    private int size;

    public MinHeap(){
        this.memmory =new ArrayList<T>();
        this.size=0;
    }

    public int getPosition(T item){
        return positionTable.get(item);
    }
    public boolean isEmpty(){
        return size <= 0;
    }

    private int Parent(int pos){
        return (pos-1)/2;
    }

    private int leftChild(int pos){
        return pos*2 +1;
    }

    private int rightChild(int pos){
        return pos*2 +2;
    }

    private void swap(int pos1, int pos2){
        T dummy= memmory.get(pos1);

        memmory.set(pos1, memmory.get(pos2));
        memmory.set(pos2,dummy);
        positionTable.put(memmory.get(pos1),pos1);
        positionTable.put(memmory.get(pos2),pos2);
    }
    public void Insert(T item){
        memmory.add(item);
        positionTable.put(item,size);
        size++;
        decreasekey(size-1);
    }
    public void decreasekey(int pos){
        int currentpos=pos;
        while (memmory.get(currentpos).compareTo(memmory.get(Parent(currentpos)))<0){
            swap(currentpos,Parent(currentpos));
            currentpos=Parent(currentpos);
        }
    }

    public T viewMin(){
        return memmory.get(0);
    }
    private boolean movedown(int pos){
        boolean leftsmaller = leftChild(pos)<size
                && (memmory.get(leftChild(pos)).compareTo(memmory.get(pos))<0);
        boolean rightsmaller = rightChild(pos)<size
                && (memmory.get(rightChild(pos)).compareTo(memmory.get(pos))<0);
        return leftsmaller || rightsmaller;
    }
    public void increasekey(int pos){
        int currentpos=pos;
        while (movedown(currentpos))
        {
            int rpos= rightChild(currentpos);
            int lpos= leftChild(currentpos);
            if (rpos< size && memmory.get(rpos).compareTo(memmory.get(lpos))<0){
                swap(rpos,currentpos);
                currentpos=rpos;
            }
            else{
                swap(lpos,currentpos);
                currentpos=lpos;
            }
        }
    }
    public T extractMin(){
        T min = memmory.get(0);
        memmory.set(0, memmory.get(size-1));
        positionTable.put(memmory.get(0),0);
        size--;
        increasekey(0);
        return min;
    }
}
