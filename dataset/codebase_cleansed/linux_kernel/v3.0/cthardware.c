int __devinit create_hw_obj(struct pci_dev *pci, enum CHIPTYP chip_type,
enum CTCARDS model, struct hw **rhw)
{
int err;
switch (chip_type) {
case ATC20K1:
err = create_20k1_hw_obj(rhw);
break;
case ATC20K2:
err = create_20k2_hw_obj(rhw);
break;
default:
err = -ENODEV;
break;
}
if (err)
return err;
(*rhw)->pci = pci;
(*rhw)->chip_type = chip_type;
(*rhw)->model = model;
return 0;
}
int destroy_hw_obj(struct hw *hw)
{
int err;
switch (hw->pci->device) {
case 0x0005:
err = destroy_20k1_hw_obj(hw);
break;
case 0x000B:
err = destroy_20k2_hw_obj(hw);
break;
default:
err = -ENODEV;
break;
}
return err;
}
unsigned int get_field(unsigned int data, unsigned int field)
{
int i;
BUG_ON(!field);
for (i = 0; !(field & (1 << i)); )
i++;
return (data & field) >> i;
}
void set_field(unsigned int *data, unsigned int field, unsigned int value)
{
int i;
BUG_ON(!field);
for (i = 0; !(field & (1 << i)); )
i++;
*data = (*data & (~field)) | ((value << i) & field);
}
