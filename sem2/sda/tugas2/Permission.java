public class Permission {
    public static final int READ = 1; // 0001
    public static final int WRITE = 2; // 0010
    public static final int EXECUTE = 3; // 0011

    private int permission;

    public Permission() {
        this.permission = 0;
    }

    public int getPermission() {
        return permission;
    }

    public String getBinaryPermission() {
        return Integer.toBinaryString(this.permission);
    }

    public void setPermission(int permission) {
        this.permission = permission;
    }
}
