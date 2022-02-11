static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 = V_4 -> V_6 + V_7 ;
unsigned long V_8 = V_4 -> V_6 + V_9 ;
unsigned long V_10 , V_11 , V_12 ;
int V_13 ;
V_11 = F_2 ( V_8 ) ;
V_10 = F_2 ( V_5 ) ;
V_12 = V_10 &
( V_14 | V_15 |
V_16 | V_17 |
V_18 | V_19 ) ;
if ( ! V_12 )
return V_20 ;
F_3 ( V_12 , V_5 ) ;
F_4 ( L_1 ,
V_4 -> V_21 ,
( ( V_12 & V_14 ) ?
L_2 :
( ( V_12 & V_15 ) ?
L_3 : L_4 ) ) ,
( ( V_12 & V_19 ) ?
L_5 : L_6 ) ) ;
F_4 ( L_7 ,
V_4 -> V_21 ,
( V_10 & V_22 ) >> 32UL ,
( V_10 & V_23 ) >> 29UL ,
( ( V_10 & V_24 ) ? 1 : 0 ) ) ;
F_4 ( L_8 , V_4 -> V_21 , V_11 ) ;
F_4 ( L_9 , V_4 -> V_21 ) ;
V_13 = 0 ;
if ( V_10 & V_16 ) {
V_13 ++ ;
F_4 ( L_10 ) ;
}
if ( V_10 & V_17 ) {
V_13 ++ ;
F_4 ( L_11 ) ;
}
if ( V_10 & V_18 ) {
V_13 ++ ;
F_4 ( L_12 ) ;
}
if ( ! V_13 )
F_4 ( L_13 ) ;
F_4 ( L_14 ) ;
F_5 ( V_4 , V_10 , V_11 , V_25 ) ;
return V_26 ;
}
static T_1 F_6 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 = V_4 -> V_6 + V_27 ;
unsigned long V_8 = V_4 -> V_6 + V_9 ;
unsigned long V_10 , V_11 , V_12 ;
int V_13 ;
V_11 = F_2 ( V_8 ) ;
V_10 = F_2 ( V_5 ) ;
V_12 = V_10 &
( V_28 | V_29 |
V_30 | V_31 ) ;
if ( ! V_12 )
return V_20 ;
F_3 ( V_12 , V_5 ) ;
F_4 ( L_15 ,
V_4 -> V_21 ,
( ( V_12 & V_28 ) ?
L_2 :
( ( V_12 & V_29 ) ?
L_3 : L_4 ) ) ) ;
F_4 ( L_16
L_17 ,
V_4 -> V_21 ,
( V_10 & V_32 ) >> 48UL ,
( V_10 & V_33 ) >> 32UL ,
( V_10 & V_34 ) >> 29UL ,
( ( V_10 & V_35 ) ? 1 : 0 ) ) ;
F_4 ( L_18 , V_4 -> V_21 , V_11 ) ;
F_4 ( L_19 , V_4 -> V_21 ) ;
V_13 = 0 ;
if ( V_10 & V_30 ) {
V_13 ++ ;
F_4 ( L_10 ) ;
}
if ( V_10 & V_31 ) {
V_13 ++ ;
F_4 ( L_11 ) ;
}
if ( ! V_13 )
F_4 ( L_13 ) ;
F_4 ( L_14 ) ;
return V_26 ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_38 -> V_39 . V_40 ;
struct V_41 * V_38 ;
unsigned long V_42 = V_4 -> V_6 ;
T_2 V_43 ;
int V_44 ;
if ( V_4 -> V_45 == V_46 )
V_37 = V_37 -> V_47 ;
V_38 = F_8 ( V_37 ) ;
if ( ! V_38 )
return;
if ( V_38 -> V_48 . V_49 < 4 )
return;
F_3 ( ( V_14 | V_15 |
V_16 | V_17 |
V_18 | V_19 ) ,
V_42 + V_7 ) ;
V_44 = F_9 ( V_38 -> V_48 . V_50 [ 1 ] , F_1 , 0 , L_20 , V_4 ) ;
if ( V_44 )
F_4 ( V_51 L_21 ,
V_4 -> V_21 , V_44 ) ;
F_3 ( ( V_28 | V_29 |
V_30 | V_31 ) ,
V_42 + V_27 ) ;
V_44 = F_9 ( V_38 -> V_48 . V_50 [ 2 ] , F_6 , 0 , L_22 , V_4 ) ;
if ( V_44 )
F_4 ( V_51 L_23 ,
V_4 -> V_21 , V_44 ) ;
V_44 = F_9 ( V_38 -> V_48 . V_50 [ 0 ] , V_52 , 0 ,
L_24 , V_4 ) ;
if ( V_44 )
F_4 ( V_51 L_25 ,
V_4 -> V_21 , V_44 ) ;
V_43 = F_2 ( V_42 + V_53 ) ;
V_43 |= V_54 ;
F_3 ( V_43 , V_42 + V_53 ) ;
}
static void F_10 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
F_11 (pdev, &sabre_bus->devices, bus_list) {
if ( V_58 -> V_59 == V_60 &&
V_58 -> V_61 == V_62 ) {
T_3 V_63 ;
F_12 ( V_58 , V_64 , & V_63 ) ;
V_63 |= V_65 | V_66 |
V_67 | V_68 |
V_69 ;
F_13 ( V_58 , V_64 , V_63 ) ;
F_13 ( V_58 , V_70 , 0xffff ) ;
F_13 ( V_58 , V_71 , 0xffff ) ;
F_14 ( V_58 , V_72 , 64 ) ;
F_14 ( V_58 , V_73 , 64 ) ;
F_14 ( V_58 , V_74 ,
( V_75 |
V_76 |
V_77 ) ) ;
}
}
}
static void T_4 F_15 ( struct V_3 * V_4 ,
struct V_61 * V_47 )
{
static int V_78 ;
if ( V_79 )
V_4 -> V_80 = 1 ;
else
V_4 -> V_80 = 0 ;
if ( V_78 != 0 ) {
F_4 (KERN_ERR PFX L_26 ) ;
return;
}
V_78 ++ ;
V_4 -> V_55 = F_16 ( V_4 , V_47 ) ;
if ( ! V_4 -> V_55 )
return;
V_81 = V_4 -> V_55 ;
F_10 ( V_4 -> V_55 ) ;
F_7 ( V_4 ) ;
}
static void T_4 F_17 ( struct V_3 * V_4 ,
struct V_41 * V_38 )
{
F_18 ( V_4 , V_38 , L_27 , V_46 ) ;
V_4 -> V_82 = V_4 -> V_6 + V_83 ;
V_4 -> V_84 = V_4 -> V_6 + V_85 ;
V_4 -> V_86 = V_4 -> V_6 + V_53 ;
F_15 ( V_4 , & V_38 -> V_39 ) ;
}
static int T_4 F_19 ( struct V_41 * V_38 )
{
const struct V_87 * V_88 ;
const struct V_89 * V_90 ;
struct V_36 * V_37 = V_38 -> V_39 . V_40 ;
struct V_3 * V_4 ;
T_5 V_91 , V_92 ;
struct V_93 * V_93 ;
int V_94 , V_44 ;
const T_5 * V_95 ;
T_2 V_96 ;
V_88 = F_20 ( V_97 , & V_38 -> V_39 ) ;
V_79 = V_88 && ( V_88 -> V_98 != NULL ) ;
if ( ! V_79 ) {
struct V_36 * V_99 ;
F_21 (cpu_dp, L_28 ) {
if ( ! strcmp ( V_99 -> V_21 , L_29 ) )
V_79 = 1 ;
}
}
V_44 = - V_100 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_101 ) ;
if ( ! V_4 ) {
F_4 (KERN_ERR PFX L_30 ) ;
goto V_102;
}
V_93 = F_22 ( sizeof( * V_93 ) , V_101 ) ;
if ( ! V_93 ) {
F_4 (KERN_ERR PFX L_31 ) ;
goto V_103;
}
V_4 -> V_93 = V_93 ;
V_91 = F_23 ( V_37 , L_32 , 0xff ) ;
V_4 -> V_104 = V_91 ;
V_90 = F_24 ( V_37 , L_33 , NULL ) ;
V_44 = - V_105 ;
if ( ! V_90 ) {
F_4 (KERN_ERR PFX L_34 ) ;
goto V_106;
}
V_4 -> V_6 = V_90 [ 0 ] . V_107 ;
for ( V_96 = V_108 ; V_96 < V_109 + 0x80 ; V_96 += 8 )
F_3 ( 0x0UL , V_4 -> V_6 + V_96 ) ;
for ( V_96 = V_110 ; V_96 < V_110 + 0x80 ; V_96 += 8 )
F_3 ( 0x0UL , V_4 -> V_6 + V_96 ) ;
F_3 ( ( V_111 | V_112 |
V_113 | V_114 ) ,
V_4 -> V_6 + V_53 ) ;
V_4 -> V_115 = V_4 -> V_6 + V_116 ;
V_95 = F_24 ( V_37 , L_35 , NULL ) ;
if ( ! V_95 ) {
F_4 (KERN_ERR PFX L_36 ) ;
goto V_106;
}
V_92 = V_95 [ 0 ] ;
switch( V_95 [ 1 ] ) {
case 0x20000000 :
V_92 |= 0x1fffffff ;
V_94 = 64 ;
break;
case 0x40000000 :
V_92 |= 0x3fffffff ;
V_94 = 128 ;
break;
case 0x80000000 :
V_92 |= 0x7fffffff ;
V_94 = 128 ;
break;
default:
F_4 (KERN_ERR PFX L_37 ) ;
goto V_106;
}
V_44 = F_25 ( V_4 , V_94 , V_95 [ 0 ] , V_92 , V_117 ) ;
if ( V_44 )
goto V_106;
F_17 ( V_4 , V_38 ) ;
V_4 -> V_118 = V_119 ;
V_119 = V_4 ;
F_26 ( & V_38 -> V_39 , V_4 ) ;
return 0 ;
V_106:
F_27 ( V_4 -> V_93 ) ;
V_103:
F_27 ( V_4 ) ;
V_102:
return V_44 ;
}
static int T_6 F_28 ( void )
{
return F_29 ( & V_120 ) ;
}
