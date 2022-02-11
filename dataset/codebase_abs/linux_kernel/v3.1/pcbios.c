static inline void F_1 ( void )
{
V_1 = 1 ;
F_2 ( V_2 + V_3 , ( V_4 - V_3 ) >> V_5 ) ;
if ( V_6 & V_7 )
F_3 ( V_8 L_1 ) ;
}
static unsigned long F_4 ( unsigned long V_9 )
{
unsigned char V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
F_5 ( V_14 ) ;
__asm__("lcall *(%%edi); cld"
: "=a" (return_code),
"=b" (address),
"=c" (length),
"=d" (entry)
: "0" (service),
"1" (0),
"D" (&bios32_indirect));
F_6 ( V_14 ) ;
switch ( V_10 ) {
case 0 :
return V_11 + V_13 ;
case 0x80 :
F_3 ( V_15 L_2 , V_9 ) ;
return 0 ;
default:
F_3 ( V_15 L_3 ,
V_9 , V_10 ) ;
return 0 ;
}
}
static int T_1 F_7 ( void )
{
T_2 V_16 , V_17 , V_18 , V_19 ;
T_3 V_20 , V_21 , V_22 , V_23 ;
unsigned long V_14 , V_24 ;
if ( ( V_24 = F_4 ( V_25 ) ) ) {
V_26 . V_11 = V_24 + V_2 ;
F_5 ( V_14 ) ;
__asm__(
"lcall *(%%edi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=d" (signature),
"=a" (eax),
"=b" (ebx),
"=c" (ecx)
: "1" (PCIBIOS_PCI_BIOS_PRESENT),
"D" (&pci_indirect)
: "memory");
F_6 ( V_14 ) ;
V_20 = ( V_17 >> 8 ) & 0xff ;
V_23 = V_17 & 0xff ;
V_21 = ( V_18 >> 8 ) & 0xff ;
V_22 = V_18 & 0xff ;
if ( V_27 < 0 )
V_27 = V_19 & 0xff ;
F_8 ( L_4 ,
V_20 , V_23 , V_21 , V_22 , V_27 ) ;
if ( V_20 || V_16 != V_28 ) {
F_3 ( V_29 L_5 ,
V_20 , V_16 ) ;
return 0 ;
}
F_3 ( V_8 L_6 ,
V_21 , V_22 , V_24 , V_27 ) ;
#ifdef F_9
if ( ! ( V_23 & V_30 ) )
V_31 &= ~ V_32 ;
if ( ! ( V_23 & V_33 ) )
V_31 &= ~ V_34 ;
#endif
return 1 ;
}
return 0 ;
}
static int F_10 ( unsigned int V_35 , unsigned int V_36 ,
unsigned int V_37 , int V_38 , int V_39 , T_2 * V_40 )
{
unsigned long V_41 = 0 ;
unsigned long V_14 ;
unsigned long V_42 = ( V_36 << 8 ) | V_37 ;
F_11 ( V_35 ) ;
if ( ! V_40 || ( V_36 > 255 ) || ( V_37 > 255 ) || ( V_38 > 255 ) )
return - V_43 ;
F_12 ( & V_44 , V_14 ) ;
switch ( V_39 ) {
case 1 :
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=c" (*value),
"=a" (result)
: "1" (PCIBIOS_READ_CONFIG_BYTE),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
* V_40 &= 0xff ;
break;
case 2 :
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=c" (*value),
"=a" (result)
: "1" (PCIBIOS_READ_CONFIG_WORD),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
* V_40 &= 0xffff ;
break;
case 4 :
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=c" (*value),
"=a" (result)
: "1" (PCIBIOS_READ_CONFIG_DWORD),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
}
F_13 ( & V_44 , V_14 ) ;
return ( int ) ( ( V_41 & 0xff00 ) >> 8 ) ;
}
static int F_14 ( unsigned int V_35 , unsigned int V_36 ,
unsigned int V_37 , int V_38 , int V_39 , T_2 V_40 )
{
unsigned long V_41 = 0 ;
unsigned long V_14 ;
unsigned long V_42 = ( V_36 << 8 ) | V_37 ;
F_11 ( V_35 ) ;
if ( ( V_36 > 255 ) || ( V_37 > 255 ) || ( V_38 > 255 ) )
return - V_43 ;
F_12 ( & V_44 , V_14 ) ;
switch ( V_39 ) {
case 1 :
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (result)
: "0" (PCIBIOS_WRITE_CONFIG_BYTE),
"c" (value),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
case 2 :
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (result)
: "0" (PCIBIOS_WRITE_CONFIG_WORD),
"c" (value),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
case 4 :
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (result)
: "0" (PCIBIOS_WRITE_CONFIG_DWORD),
"c" (value),
"b" (bx),
"D" ((long)reg),
"S" (&pci_indirect));
break;
}
F_13 ( & V_44 , V_14 ) ;
return ( int ) ( ( V_41 & 0xff00 ) >> 8 ) ;
}
static struct V_45 * T_1 F_15 ( void )
{
union V_46 * V_47 ;
unsigned char V_48 ;
int V_49 , V_12 ;
for ( V_47 = (union V_46 * ) F_16 ( 0xe0000 ) ;
V_47 <= (union V_46 * ) F_16 ( 0xffff0 ) ;
++ V_47 ) {
long V_50 ;
if ( F_17 ( & V_47 -> V_51 . V_16 , V_50 ) )
continue;
if ( V_47 -> V_51 . V_16 != V_52 )
continue;
V_12 = V_47 -> V_51 . V_12 * 16 ;
if ( ! V_12 )
continue;
V_48 = 0 ;
for ( V_49 = 0 ; V_49 < V_12 ; ++ V_49 )
V_48 += V_47 -> V_53 [ V_49 ] ;
if ( V_48 != 0 )
continue;
if ( V_47 -> V_51 . V_54 != 0 ) {
F_3 ( L_7 ,
V_47 -> V_51 . V_54 , V_47 ) ;
continue;
}
F_8 ( L_8 , V_47 ) ;
if ( V_47 -> V_51 . V_13 >= 0x100000 ) {
F_3 ( L_9
L_10 , V_47 ) ;
return NULL ;
} else {
unsigned long V_55 = V_47 -> V_51 . V_13 ;
F_8 ( L_11 ,
V_55 ) ;
V_56 . V_11 = V_55 + V_2 ;
F_1 () ;
if ( F_7 () )
return & V_57 ;
}
break;
}
return NULL ;
}
struct V_58 * F_18 ( void )
{
struct V_59 V_60 ;
struct V_58 * V_61 = NULL ;
int V_62 , V_63 ;
unsigned long V_64 ;
if ( ! V_65 )
return NULL ;
V_64 = F_19 ( V_66 ) ;
if ( ! V_64 )
return NULL ;
V_60 . V_67 = (struct V_68 * ) V_64 ;
V_60 . V_69 = V_70 ;
V_60 . V_71 = V_72 ;
F_8 ( L_12 ) ;
__asm__("push %%es\n\t"
"push %%ds\n\t"
"pop %%es\n\t"
"lcall *(%%esi); cld\n\t"
"pop %%es\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (ret),
"=b" (map),
"=m" (opt)
: "0" (PCIBIOS_GET_ROUTING_OPTIONS),
"1" (0),
"D" ((long) &opt),
"S" (&pci_indirect),
"m" (opt)
: "memory");
F_8 ( L_13 , V_62 , V_60 . V_69 , V_63 ) ;
if ( V_62 & 0xff00 )
F_3 ( V_29 L_14 , ( V_62 >> 8 ) & 0xff ) ;
else if ( V_60 . V_69 ) {
V_61 = F_20 ( sizeof( struct V_58 ) + V_60 . V_69 , V_66 ) ;
if ( V_61 ) {
memset ( V_61 , 0 , sizeof( struct V_58 ) ) ;
V_61 -> V_69 = V_60 . V_69 + sizeof( struct V_58 ) ;
V_61 -> V_73 = V_63 ;
memcpy ( V_61 -> V_74 , ( void * ) V_64 , V_60 . V_69 ) ;
F_3 ( V_8 L_15 ) ;
}
}
F_21 ( V_64 ) ;
return V_61 ;
}
int F_22 ( struct V_75 * V_76 , int V_77 , int V_78 )
{
int V_62 ;
__asm__("lcall *(%%esi); cld\n\t"
"jc 1f\n\t"
"xor %%ah, %%ah\n"
"1:"
: "=a" (ret)
: "0" (PCIBIOS_SET_PCI_HW_INT),
"b" ((dev->bus->number << 8) | dev->devfn),
"c" ((irq << 8) | (pin + 10)),
"S" (&pci_indirect));
return ! ( V_62 & 0xff00 ) ;
}
void T_4 F_23 ( void )
{
if ( ( V_31 & V_79 )
&& ( ( V_80 = F_15 () ) ) ) {
V_65 = 1 ;
}
}
