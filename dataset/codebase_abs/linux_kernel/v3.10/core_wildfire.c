void T_1
F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 ;
T_2 * V_5 ;
V_4 = F_2 () ;
V_4 -> V_6 = F_3 () ;
V_4 -> V_7 = F_3 () ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = F_4 ( V_1 , V_2 ) ;
V_4 -> V_11 = F_5 ( V_1 , V_2 ) ;
V_4 -> V_12 = F_6 ( V_1 , V_2 ) ;
V_4 -> V_13 = ( V_1 << 3 ) + V_2 ;
V_4 -> V_6 -> V_14 = F_5 ( V_1 , V_2 ) - V_15 ;
V_4 -> V_6 -> V_16 = V_4 -> V_6 -> V_14 + V_17 - 1 ;
V_4 -> V_6 -> V_18 = V_19 [ V_2 ] ;
V_4 -> V_6 -> V_20 = V_21 ;
V_4 -> V_7 -> V_14 = F_4 ( V_1 , V_2 ) - V_22 ;
V_4 -> V_7 -> V_16 = V_4 -> V_7 -> V_14 + 0xffffffff ;
V_4 -> V_7 -> V_18 = V_23 [ V_2 ] ;
V_4 -> V_7 -> V_20 = V_24 ;
if ( F_7 ( & V_25 , V_4 -> V_6 ) < 0 )
F_8 ( V_26 L_1 ,
V_1 , V_2 ) ;
if ( F_7 ( & V_27 , V_4 -> V_7 ) < 0 )
F_8 ( V_26 L_2 ,
V_1 , V_2 ) ;
#if V_28
F_9 ( V_1 , V_2 ) ;
#endif
V_4 -> V_29 = F_10 ( V_4 , 0x00800000 , 0x00800000 , 0 ) ;
V_4 -> V_30 = F_10 ( V_4 , 0xc0000000 , 0x08000000 , 0 ) ;
V_5 = F_11 ( V_1 , V_2 ) ;
V_5 -> V_31 [ 0 ] . V_32 . V_33 = V_4 -> V_29 -> V_34 | 3 ;
V_5 -> V_31 [ 0 ] . V_35 . V_33 = ( V_4 -> V_29 -> V_36 - 1 ) & 0xfff00000 ;
V_5 -> V_31 [ 0 ] . V_37 . V_33 = F_12 ( V_4 -> V_29 -> V_38 ) ;
V_5 -> V_31 [ 1 ] . V_32 . V_33 = 0x40000000 | 1 ;
V_5 -> V_31 [ 1 ] . V_35 . V_33 = ( 0x40000000 - 1 ) & 0xfff00000 ;
V_5 -> V_31 [ 1 ] . V_37 . V_33 = 0 ;
V_5 -> V_31 [ 2 ] . V_32 . V_33 = 0x80000000 | 1 ;
V_5 -> V_31 [ 2 ] . V_35 . V_33 = ( 0x40000000 - 1 ) & 0xfff00000 ;
V_5 -> V_31 [ 2 ] . V_37 . V_33 = 0x40000000 ;
V_5 -> V_31 [ 3 ] . V_32 . V_33 = V_4 -> V_30 -> V_34 | 3 ;
V_5 -> V_31 [ 3 ] . V_35 . V_33 = ( V_4 -> V_30 -> V_36 - 1 ) & 0xfff00000 ;
V_5 -> V_31 [ 3 ] . V_37 . V_33 = F_12 ( V_4 -> V_30 -> V_38 ) ;
F_13 ( V_4 , 0 , 0 ) ;
}
void T_1
F_14 ( int V_1 , int V_39 )
{
if ( ! F_15 ( V_1 , V_39 ) )
return;
#if V_28
F_16 ( V_1 , V_39 ) ;
#endif
F_1 ( V_1 , ( V_39 << 1 ) + 0 ) ;
F_1 ( V_1 , ( V_39 << 1 ) + 1 ) ;
}
void T_1
F_17 ( int V_1 )
{
int V_39 ;
if ( ! F_18 ( V_1 ) )
return;
#if V_28
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
#endif
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
F_14 ( V_1 , V_39 ) ;
}
}
void T_1
F_23 ( void )
{
unsigned long V_41 ;
unsigned int V_42 , V_43 ;
T_3 * V_44 = F_24 () ;
T_4 * V_45 ;
T_5 * V_46 ;
T_6 * V_47 ;
T_7 * V_48 ;
T_8 * V_49 ;
T_9 * V_50 ;
int V_51 ;
V_41 = V_44 -> V_52 . V_33 ;
#if 0
printk(KERN_ERR "fast QSD_WHAMI at base %p is 0x%lx\n", fast, temp);
#endif
V_42 = ( V_41 >> 8 ) & 7 ;
V_43 = ( V_41 >> 4 ) & 7 ;
V_53 = ( 1 << V_42 ) ;
V_54 = ( 1 << V_43 ) ;
V_55 = 0 ;
V_56 = 0 ;
V_57 = 0 ;
V_58 = 0 ;
V_59 = 0 ;
V_60 = 0 ;
V_61 = 0 ;
memset ( V_62 , V_63 , V_64 ) ;
memset ( V_65 , V_63 , V_64 ) ;
V_46 = F_25 ( V_43 ) ;
V_41 = V_46 -> V_66 . V_33 ;
#if 0
printk(KERN_ERR "QSA_QBB_ID at base %p is 0x%lx\n", qsa, temp);
#endif
if ( V_41 & 0x40 )
V_56 = 1 ;
if ( V_41 & 0x20 ) {
V_48 = F_26 ( V_43 ) ;
V_41 = 0 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
V_41 |= V_48 -> V_67 [ V_51 ] . V_33 << ( V_51 * 8 ) ;
#if 0
printk(KERN_ERR "GPA_QBB_MAP[%d] at base %p is 0x%lx\n",
i, gp, temp);
#endif
}
for ( V_42 = 0 ; V_42 < V_64 ; V_42 ++ ) {
if ( V_41 & 8 ) {
V_43 = V_41 & 7 ;
V_53 |= ( 1 << V_42 ) ;
V_54 |= ( 1 << V_43 ) ;
}
V_41 >>= 4 ;
}
V_55 = V_54 ;
}
for ( V_43 = 0 ; V_43 < V_64 ; V_43 ++ ) {
if ( F_18 ( V_43 ) ) {
V_45 = F_27 ( V_43 ) ;
V_41 = V_45 -> V_52 . V_33 ;
#if 0
printk(KERN_ERR "QSD_WHAMI at base %p is 0x%lx\n", qsd, temp);
#endif
V_42 = ( V_41 >> 8 ) & 7 ;
V_62 [ V_42 ] = V_43 ;
V_65 [ V_43 ] = V_42 ;
V_46 = F_25 ( V_43 ) ;
V_41 = V_46 -> V_68 [ 0 ] . V_33 ;
#if 0
printk(KERN_ERR "QSA_QBB_POP_0 at base %p is 0x%lx\n", qsa, temp);
#endif
V_60 |= ( ( V_41 >> 0 ) & 0xf ) << ( V_43 << 2 ) ;
V_61 |= ( ( V_41 >> 4 ) & 0xf ) << ( V_43 << 2 ) ;
V_41 = V_46 -> V_68 [ 1 ] . V_33 ;
#if 0
printk(KERN_ERR "QSA_QBB_POP_1 at base %p is 0x%lx\n", qsa, temp);
#endif
V_57 |= ( 1 << V_43 ) ;
V_58 |= ( ( V_41 >> 4 ) & 0xf ) << ( V_43 << 2 ) ;
V_41 = V_46 -> V_66 . V_33 ;
#if 0
printk(KERN_ERR "QSA_QBB_ID at %p is 0x%lx\n", qsa, temp);
#endif
if ( V_41 & 0x20 )
V_55 |= ( 1 << V_43 ) ;
for ( V_51 = 0 ; V_51 < V_40 ; V_51 ++ ) {
V_47 = F_28 ( V_43 ) ;
V_49 = F_29 ( V_43 , V_51 ) ;
V_50 = F_30 ( V_43 , V_51 ) ;
if ( ( V_47 -> V_69 [ V_51 ] . V_70 . V_33 & 1 ) == 1 &&
( ( V_49 -> V_71 . V_33 & 0xf00000300UL ) == 0x100000300UL ) &&
( ( V_50 -> V_72 . V_33 & 0xf00000300UL ) == 0x100000200UL ) )
{
V_59 |= 1 << ( ( V_43 << 2 ) + V_51 ) ;
}
}
}
}
#if V_73
F_31 () ;
#endif
}
void T_1
F_32 ( void )
{
int V_1 ;
V_25 . V_16 = ~ 0UL ;
F_23 () ;
for ( V_1 = 0 ; V_1 < V_64 ; V_1 ++ ) {
F_17 ( V_1 ) ;
}
V_74 = 0x40000000UL ;
V_75 = 0x80000000UL ;
}
void
F_33 ( unsigned long V_76 , unsigned long V_77 )
{
F_34 () ;
F_34 () ;
F_35 () ;
F_36 ( 0x7 ) ;
F_34 () ;
F_37 ( V_76 , V_77 , L_3 ,
F_38 ( F_39 () ) ) ;
}
void
F_40 ( int V_78 )
{
}
void
F_13 ( struct V_3 * V_4 , T_10 V_14 , T_10 V_16 )
{
int V_1 = V_4 -> V_13 >> 3 ;
int V_2 = V_4 -> V_13 & 7 ;
T_2 * V_5 = F_11 ( V_1 , V_2 ) ;
F_34 () ;
V_5 -> V_79 . V_33 ;
}
static int
F_41 ( struct V_80 * V_81 , unsigned int V_82 , int V_83 ,
unsigned long * V_84 , unsigned char * V_85 )
{
struct V_3 * V_4 = V_81 -> V_86 ;
unsigned long V_87 ;
T_11 V_88 = V_81 -> V_89 ;
F_42 ( ( L_4
L_5 ,
V_88 , V_82 , V_83 , V_84 , V_85 ) ) ;
if ( ! V_81 -> V_90 )
V_88 = 0 ;
* V_85 = ( V_88 != 0 ) ;
V_87 = ( V_88 << 16 ) | ( V_82 << 8 ) | V_83 ;
V_87 |= V_4 -> V_12 ;
* V_84 = V_87 ;
F_42 ( ( L_6 , V_87 ) ) ;
return 0 ;
}
static int
F_43 ( struct V_80 * V_88 , unsigned int V_91 , int V_83 ,
int V_36 , T_12 * V_92 )
{
unsigned long V_87 ;
unsigned char V_85 ;
if ( F_41 ( V_88 , V_91 , V_83 , & V_87 , & V_85 ) )
return V_93 ;
switch ( V_36 ) {
case 1 :
* V_92 = F_44 ( * ( V_94 ) V_87 ) ;
break;
case 2 :
* V_92 = F_45 ( * ( V_95 ) V_87 ) ;
break;
case 4 :
* V_92 = * ( V_96 ) V_87 ;
break;
}
return V_97 ;
}
static int
F_46 ( struct V_80 * V_88 , unsigned int V_91 , int V_83 ,
int V_36 , T_12 V_92 )
{
unsigned long V_87 ;
unsigned char V_85 ;
if ( F_41 ( V_88 , V_91 , V_83 , & V_87 , & V_85 ) )
return V_93 ;
switch ( V_36 ) {
case 1 :
F_47 ( V_92 , * ( V_94 ) V_87 ) ;
F_34 () ;
F_44 ( * ( V_94 ) V_87 ) ;
break;
case 2 :
F_48 ( V_92 , * ( V_95 ) V_87 ) ;
F_34 () ;
F_45 ( * ( V_95 ) V_87 ) ;
break;
case 4 :
* ( V_96 ) V_87 = V_92 ;
F_34 () ;
* ( V_96 ) V_87 ;
break;
}
return V_97 ;
}
int F_49 ( unsigned long V_98 )
{
return V_98 >> 36 ;
}
int F_50 ( int V_99 )
{
return V_99 >> 2 ;
}
unsigned long F_51 ( int V_100 )
{
return ( unsigned long ) V_100 * ( 64UL * 1024 * 1024 * 1024 ) ;
}
unsigned long F_52 ( int V_100 )
{
return 64UL * 1024 * 1024 * 1024 ;
}
static void T_1
F_9 ( int V_1 , int V_2 )
{
T_2 * V_5 = F_11 ( V_1 , V_2 ) ;
int V_51 ;
F_8 ( V_26 L_7 ,
V_1 , V_2 , V_5 ) ;
F_8 ( V_26 L_8 ,
V_5 -> V_101 . V_33 ) ;
F_8 ( V_26 L_9 , V_5 -> V_102 . V_33 ) ;
F_8 ( V_26 L_10 , V_5 -> V_103 . V_33 ) ;
F_8 ( V_26 L_11 , V_5 -> V_104 . V_33 ) ;
F_8 ( V_26 L_12 , V_5 -> V_105 . V_33 ) ;
F_8 ( V_26 L_13 , V_5 -> V_106 . V_33 ) ;
F_8 ( V_26 L_14 , V_5 -> V_107 . V_33 ) ;
F_8 ( V_26 L_15 ,
V_1 , V_2 , V_5 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
F_8 ( V_26 L_16 , V_51 ,
V_5 -> V_31 [ V_51 ] . V_32 . V_33 ,
V_5 -> V_31 [ V_51 ] . V_35 . V_33 ,
V_5 -> V_31 [ V_51 ] . V_37 . V_33 ) ;
}
F_8 ( V_26 L_17 ) ;
}
static void T_1
F_16 ( int V_1 , int V_39 )
{
T_13 * V_108 = F_53 ( V_1 , V_39 ) ;
int V_51 ;
F_8 ( V_26 L_18 ,
V_1 , V_39 , V_108 ) ;
F_8 ( V_26 L_19 , V_108 -> V_109 . V_33 ) ;
F_8 ( V_26 L_20 , V_108 -> V_110 . V_33 ) ;
F_8 ( V_26 L_21 , V_108 -> V_111 . V_33 ) ;
F_8 ( V_26 L_22 , V_108 -> V_112 . V_33 ) ;
F_8 ( V_26 L_23 ,
V_108 -> V_113 . V_33 ) ;
F_8 ( V_26 L_24 ,
V_1 , V_39 , V_108 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
F_8 ( V_26 L_25 , V_51 ,
V_108 -> V_114 [ V_51 ] . V_115 . V_33 ,
V_108 -> V_114 [ V_51 ] . V_116 . V_33 ) ;
}
F_8 ( V_26 L_17 ) ;
}
static void T_1
F_19 ( int V_1 )
{
T_5 * V_46 = F_25 ( V_1 ) ;
int V_51 ;
F_8 ( V_26 L_26 , V_1 , V_46 ) ;
F_8 ( V_26 L_27 , V_46 -> V_66 . V_33 ) ;
F_8 ( V_26 L_28 , V_46 -> V_117 . V_33 ) ;
F_8 ( V_26 L_29 , V_46 -> V_118 . V_33 ) ;
for ( V_51 = 0 ; V_51 < 5 ; V_51 ++ )
F_8 ( V_26 L_30 ,
V_51 , V_46 -> V_119 [ V_51 ] . V_33 ) ;
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ )
F_8 ( V_26 L_31 ,
V_51 , V_46 -> V_68 [ 0 ] . V_33 ) ;
F_8 ( V_26 L_17 ) ;
}
static void T_1
F_20 ( int V_1 )
{
T_4 * V_45 = F_27 ( V_1 ) ;
F_8 ( V_26 L_32 , V_1 , V_45 ) ;
F_8 ( V_26 L_33 , V_45 -> V_52 . V_33 ) ;
F_8 ( V_26 L_34 , V_45 -> V_120 . V_33 ) ;
F_8 ( V_26 L_35 ,
V_45 -> V_121 . V_33 ) ;
F_8 ( V_26 L_36 ,
V_45 -> V_122 . V_33 ) ;
F_8 ( V_26 L_37 ,
V_45 -> V_123 . V_33 ) ;
F_8 ( V_26 L_38 ,
V_45 -> V_124 . V_33 ) ;
F_8 ( V_26 L_39 ,
V_45 -> V_125 . V_33 ) ;
F_8 ( V_26 L_40 ,
V_45 -> V_126 . V_33 ) ;
F_8 ( V_26 L_17 ) ;
}
static void T_1
F_21 ( int V_1 )
{
T_6 * V_47 = F_28 ( V_1 ) ;
int V_51 ;
F_8 ( V_26 L_41 , V_1 , V_47 ) ;
F_8 ( V_26 L_42 , V_47 -> V_127 . V_33 ) ;
F_8 ( V_26 L_43 , V_47 -> V_128 . V_33 ) ;
F_8 ( V_26 L_44 ,
V_47 -> V_129 . V_33 ) ;
F_8 ( V_26 L_45 ,
V_47 -> V_130 . V_33 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
F_8 ( V_26 L_46 ,
V_51 , V_47 -> V_69 [ V_51 ] . V_70 . V_33 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
F_8 ( V_26 L_47 ,
V_51 , V_47 -> V_131 [ V_51 ] . V_115 . V_33 ) ;
F_8 ( V_26 L_17 ) ;
}
static void T_1
F_22 ( int V_1 )
{
T_7 * V_48 = F_26 ( V_1 ) ;
int V_51 ;
F_8 ( V_26 L_48 , V_1 , V_48 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
F_8 ( V_26 L_49 ,
V_51 , V_48 -> V_67 [ V_51 ] . V_33 ) ;
F_8 ( V_26 L_50 ,
V_48 -> V_132 . V_33 ) ;
F_8 ( V_26 L_51 , V_48 -> V_133 . V_33 ) ;
F_8 ( V_26 L_52 , V_48 -> V_134 . V_33 ) ;
F_8 ( V_26 L_53 , V_48 -> V_135 . V_33 ) ;
F_8 ( V_26 L_54 , V_48 -> V_136 . V_33 ) ;
F_8 ( V_26 L_55 , V_48 -> V_137 . V_33 ) ;
F_8 ( V_26 L_17 ) ;
}
static void T_1
F_31 ( void )
{
int V_51 ;
F_8 ( V_26 L_56 ) ;
F_8 ( V_26 L_57 , V_53 ) ;
F_8 ( V_26 L_58 , V_54 ) ;
F_8 ( V_26 L_59 , V_55 ) ;
F_8 ( V_26 L_60 , V_56 ) ;
F_8 ( V_26 L_61 , V_57 ) ;
F_8 ( V_26 L_62 , V_58 ) ;
F_8 ( V_26 L_63 , V_59 ) ;
F_8 ( V_26 L_64 , V_60 ) ;
F_8 ( V_26 L_65 , V_61 ) ;
F_8 ( L_66 ) ;
for ( V_51 = 0 ; V_51 < V_64 ; V_51 ++ )
if ( V_62 [ V_51 ] == V_63 )
F_8 ( L_67 ) ;
else
F_8 ( L_68 , V_62 [ V_51 ] ) ;
F_8 ( L_17 ) ;
F_8 ( L_69 ) ;
for ( V_51 = 0 ; V_51 < V_64 ; V_51 ++ )
if ( V_65 [ V_51 ] == V_63 )
F_8 ( L_67 ) ;
else
F_8 ( L_68 , V_65 [ V_51 ] ) ;
F_8 ( L_17 ) ;
}
