static unsigned long
F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 = 0 ;
if ( V_2 -> V_5 == 0 ) {
if ( F_2 ( V_3 ) == 0 )
V_4 = V_6 ;
else {
V_3 -= 1 << 3 ;
if ( V_3 < F_3 ( V_7 , 0 ) )
V_4 = V_8 | 0xc00000 | ( V_3 << 8 ) ;
}
} else
V_4 = V_9 | ( V_2 -> V_5 << 16 ) | ( V_3 << 8 ) ;
return V_4 ;
}
static int
F_4 ( struct V_1 * V_2 , unsigned int V_3 , int V_10 ,
int V_11 , T_1 * V_12 )
{
unsigned long V_4 = F_1 ( V_2 , V_3 ) ;
T_1 V_13 = 0xffffffff ;
if ( V_4 )
switch ( V_11 ) {
case 1 :
asm("ldrb %0, [%1, %2]"
: "=r" (v) : "r" (addr), "r" (where) : "cc");
break;
case 2 :
asm("ldrh %0, [%1, %2]"
: "=r" (v) : "r" (addr), "r" (where) : "cc");
break;
case 4 :
asm("ldr %0, [%1, %2]"
: "=r" (v) : "r" (addr), "r" (where) : "cc");
break;
}
* V_12 = V_13 ;
V_13 = * V_14 ;
if ( V_13 & V_15 ) {
* V_14 = V_13 & ( 0xffff | V_15 ) ;
return - 1 ;
}
return V_16 ;
}
static int
F_5 ( struct V_1 * V_2 , unsigned int V_3 , int V_10 ,
int V_11 , T_1 V_12 )
{
unsigned long V_4 = F_1 ( V_2 , V_3 ) ;
T_1 V_13 ;
if ( V_4 )
switch ( V_11 ) {
case 1 :
asm("strb %0, [%1, %2]"
: : "r" (value), "r" (addr), "r" (where)
: "cc");
break;
case 2 :
asm("strh %0, [%1, %2]"
: : "r" (value), "r" (addr), "r" (where)
: "cc");
break;
case 4 :
asm("str %0, [%1, %2]"
: : "r" (value), "r" (addr), "r" (where)
: "cc");
break;
}
V_13 = * V_14 ;
if ( V_13 & V_15 ) {
* V_14 = V_13 & ( 0xffff | V_15 ) ;
return - 1 ;
}
return V_16 ;
}
static void F_6 ( unsigned long V_17 )
{
switch ( V_17 ) {
case V_18 :
F_7 ( & V_19 ) ;
break;
case V_20 :
F_7 ( & V_21 ) ;
break;
}
F_8 ( V_17 ) ;
}
static T_2 F_9 ( int V_22 , void * V_23 )
{
unsigned int V_24 ;
unsigned int V_25 ;
V_24 = * V_14 ;
V_25 = V_24 >> 16 ;
V_24 = V_24 & 0xffff ;
if ( V_25 & V_26 ) {
F_10 ( V_27 L_1 ,
F_11 ( F_12 () ) ) ;
V_24 |= V_26 << 16 ;
}
if ( V_25 & V_28 ) {
F_10 ( V_27 L_2 ) ;
F_13 ( V_26 |
V_29 |
V_28 , 1 ) ;
F_10 ( L_3 ) ;
V_24 |= V_28 << 16 ;
}
* V_14 = V_24 ;
return V_30 ;
}
static T_2 F_14 ( int V_22 , void * V_23 )
{
struct V_31 * V_32 = V_23 ;
unsigned int V_33 ;
F_10 ( V_27 L_4 ) ;
F_13 ( V_34 , 1 ) ;
F_10 ( L_3 ) ;
V_33 = * V_35 & 0xffffdf07 ;
* V_35 = V_33 | V_36 ;
F_15 ( V_22 ) ;
V_32 -> V_37 = V_38 + V_39 ;
F_16 ( V_32 ) ;
return V_30 ;
}
static T_2 F_17 ( int V_22 , void * V_23 )
{
F_10 ( V_27 L_5 ) ;
* V_35 &= 0xffffde07 ;
return V_30 ;
}
static T_2 F_18 ( int V_22 , void * V_23 )
{
unsigned int V_24 ;
F_10 ( V_27 L_6 ) ;
F_13 ( V_40 | V_41 , 1 ) ;
F_10 ( L_3 ) ;
V_24 = * V_14 & 0xffff ;
* V_14 = V_24 | 1 << 24 ;
return V_30 ;
}
static T_2 F_19 ( int V_22 , void * V_23 )
{
struct V_31 * V_32 = V_23 ;
unsigned int V_24 ;
F_10 ( V_27 L_7 ) ;
F_13 ( V_40 | V_41 , 1 ) ;
F_10 ( L_3 ) ;
V_24 = * V_14 & 0xffff ;
* V_14 = V_24 | 1 << 31 ;
F_15 ( V_22 ) ;
V_32 -> V_37 = V_38 + V_39 ;
F_16 ( V_32 ) ;
return V_30 ;
}
int T_3 F_20 ( int V_42 , struct V_43 * V_44 )
{
struct V_45 * V_46 ;
if ( V_42 || ! F_21 () )
return 0 ;
V_46 = F_22 ( sizeof( struct V_45 ) * 2 , V_47 ) ;
if ( ! V_46 ) {
F_10 ( L_8 ) ;
return 0 ;
}
V_46 [ 0 ] . V_48 = V_49 ;
V_46 [ 0 ] . V_50 = L_9 ;
V_46 [ 1 ] . V_48 = V_49 | V_51 ;
V_46 [ 1 ] . V_50 = L_10 ;
F_23 ( & V_52 , & V_46 [ 1 ] , 0x20000000 ,
0xa0000000 , 0xffffffff , 0x20000000 , NULL , NULL ) ;
F_23 ( & V_52 , & V_46 [ 0 ] , 0x40000000 ,
0x80000000 , 0xffffffff , 0x40000000 , NULL , NULL ) ;
F_24 ( & V_44 -> V_53 , & V_54 ) ;
F_24 ( & V_44 -> V_53 , & V_46 [ 0 ] ) ;
F_24 ( & V_44 -> V_53 , & V_46 [ 1 ] ) ;
V_44 -> V_55 = V_56 ;
return 1 ;
}
struct V_1 * T_3 F_25 ( int V_42 , struct V_43 * V_44 )
{
return F_26 ( NULL , 0 , & V_57 , V_44 , & V_44 -> V_53 ) ;
}
void T_3 F_27 ( void )
{
unsigned int V_58 , V_59 ;
int V_60 ;
V_61 = 0x81000000 ;
V_62 = V_63 ;
V_58 = ( unsigned int ) V_64 - V_65 ;
for ( V_59 = 0x00100000 ; V_59 < 0x10000000 ; V_59 <<= 1 )
if ( V_59 >= V_58 )
break;
* V_66 = ( V_59 - 1 ) & 0x0ffc0000 ;
* V_67 = 0 ;
* V_68 = 0x80000000 ;
* V_69 = 0 ;
* V_70 = 0 ;
* V_71 = 0 ;
V_60 = F_28 () ;
F_10 ( V_72 L_11
L_12 , * V_73 & 0xff , V_60 ?
L_13 : L_14 ) ;
if ( F_21 () ) {
* V_35 = ( * V_35 & 0xffffde07 ) |
V_36 ;
* V_14 = ( * V_14 & 0xffff ) | V_74 ;
}
F_29 ( & V_19 ) ;
F_29 ( & V_21 ) ;
V_19 . V_75 = V_18 ;
V_19 . V_76 = F_6 ;
V_21 . V_75 = V_20 ;
V_21 . V_76 = F_6 ;
F_30 ( V_18 , F_14 , V_77 ,
L_15 , & V_19 ) ;
F_30 ( V_20 , F_19 , V_77 ,
L_16 , & V_21 ) ;
F_30 ( V_78 , F_9 , V_77 ,
L_17 , NULL ) ;
F_30 ( V_79 , F_17 , V_77 ,
L_18 , NULL ) ;
F_30 ( V_80 , F_18 , V_77 ,
L_19 , NULL ) ;
if ( V_60 ) {
static struct V_45 V_81 ;
V_81 . V_48 = V_82 ;
V_81 . V_50 = L_20 ;
F_23 ( & V_54 , & V_81 , 128 ,
0xff00 , 0xffff , 128 , NULL , NULL ) ;
* V_83 = 0xf4000000 ;
* V_84 = V_81 . V_85 ;
* V_86 = F_31 ( V_65 ) ;
* V_87 = 0 ;
* V_14 = V_88 | V_89 |
V_90 | V_74 ;
} else if ( F_21 () != 0 ) {
F_32 ( L_21
L_22 ) ;
}
}
void T_3 F_33 ( void )
{
F_34 ( V_56 , V_91 , 0 ) ;
}
