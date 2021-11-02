cd Home/Desktop/week11/
mkdir ex1
cd ex1/
fallocate -l 50M lofs.img
losetup -f
sudo losetup -f lofs.img
losetup -f
losetup -a
sudo mkfs.ext4 /dev/loop0
sudo mount /dev/loop0 lofsdisk/
ls
mkdir lofsdisk
sudo mount /dev/loop0 lofsdisk/
history > ex1.sh