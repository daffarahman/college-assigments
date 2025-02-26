class Main {
    public static void main(String[] args) {
        Permission perm = new Permission();
        perm.setPermission(Permission.READ | Permission.EXECUTE);
        System.out.println(perm.getBinaryPermission());
    }
}