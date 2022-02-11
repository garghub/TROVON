static unsigned int
F_1 ( unsigned long V_1 , unsigned char V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
unsigned long V_6 = F_2 ( V_4 -> V_7 ) ;
unsigned int V_8 , V_9 , V_10 ;
V_10 = F_3 () ;
F_4 ( V_5 ) ;
F_5 ( ( L_1 ,
V_1 , V_2 , V_6 ) ) ;
V_8 = * ( V_11 ) F_6 ( V_6 ) ;
* ( V_11 ) F_6 ( V_6 ) = V_8 ;
F_7 () ;
* ( V_11 ) F_6 ( V_6 ) ;
F_5 ( ( L_2 , V_6 , V_8 ) ) ;
F_7 () ;
F_8 () ;
F_9 ( V_10 ) = 1 ;
F_10 ( V_10 ) = 0 ;
F_11 ( V_10 ) = V_6 ;
F_7 () ;
V_9 = * ( ( V_11 ) V_1 ) ;
F_7 () ;
F_7 () ;
if ( F_10 ( V_10 ) ) {
F_10 ( V_10 ) = 0 ;
V_9 = 0xffffffffU ;
F_7 () ;
}
F_9 ( V_10 ) = 0 ;
F_7 () ;
F_5 ( ( L_3 ) ) ;
F_12 ( V_5 ) ;
return V_9 ;
}
static void
F_13 ( unsigned long V_1 , unsigned int V_9 , unsigned char V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
unsigned long V_6 = F_2 ( V_4 -> V_7 ) ;
unsigned int V_8 , V_10 ;
V_10 = F_3 () ;
F_4 ( V_5 ) ;
V_8 = * ( V_11 ) F_6 ( V_6 ) ;
* ( V_11 ) F_6 ( V_6 ) = V_8 ; F_7 () ;
* ( V_11 ) F_6 ( V_6 ) ;
F_5 ( ( L_4 , V_6 , V_8 ) ) ;
F_8 () ;
F_9 ( V_10 ) = 1 ;
F_11 ( V_10 ) = V_6 ;
F_7 () ;
* ( ( V_11 ) V_1 ) = V_9 ;
F_7 () ;
F_7 () ;
* ( V_11 ) F_6 ( V_6 ) ;
F_9 ( V_10 ) = 0 ;
F_7 () ;
F_5 ( ( L_5 ) ) ;
F_12 ( V_5 ) ;
}
static int
F_14 ( struct V_12 * V_13 , unsigned int V_14 , int V_15 ,
struct V_3 * V_4 , unsigned long * V_16 ,
unsigned char * V_2 )
{
T_1 V_17 = V_13 -> V_18 ;
unsigned long V_1 ;
F_5 ( ( L_6
L_7 ,
V_17 , V_14 , V_4 -> V_7 , V_15 , V_16 , V_2 ) ) ;
* V_2 = 1 ;
if ( ! V_13 -> V_19 )
V_17 = 0 ;
V_1 = ( V_17 << 16 ) | ( V_14 << 8 ) | ( V_15 ) ;
V_1 <<= 5 ;
V_1 |= V_4 -> V_20 ;
* V_16 = V_1 ;
F_5 ( ( L_8 , V_1 ) ) ;
return 0 ;
}
static int
F_15 ( struct V_12 * V_17 , unsigned int V_14 , int V_15 ,
int V_21 , T_2 * V_9 )
{
struct V_3 * V_4 = V_17 -> V_22 ;
unsigned long V_1 , V_23 ;
unsigned char V_2 ;
if ( F_14 ( V_17 , V_14 , V_15 , V_4 , & V_1 , & V_2 ) )
return V_24 ;
V_1 |= ( V_21 - 1 ) * 8 ;
V_23 = F_1 ( V_1 , V_2 , V_4 ) ;
switch ( V_21 ) {
case 1 :
* V_9 = F_16 ( V_23 , V_15 & 3 ) ;
break;
case 2 :
* V_9 = F_17 ( V_23 , V_15 & 3 ) ;
break;
case 4 :
* V_9 = V_23 ;
break;
}
return V_25 ;
}
static int
F_18 ( struct V_12 * V_17 , unsigned int V_14 , int V_15 ,
int V_21 , T_2 V_9 )
{
struct V_3 * V_4 = V_17 -> V_22 ;
unsigned long V_1 ;
unsigned char V_2 ;
if ( F_14 ( V_17 , V_14 , V_15 , V_4 , & V_1 , & V_2 ) )
return V_24 ;
V_1 |= ( V_21 - 1 ) * 8 ;
V_9 = F_19 ( V_9 , V_15 & 3 ) ;
F_13 ( V_1 , V_9 , V_2 , V_4 ) ;
return V_25 ;
}
void
F_20 ( struct V_3 * V_4 , T_3 V_26 , T_3 V_27 )
{
F_21 () ;
* ( V_11 ) F_22 ( F_2 ( V_4 -> V_7 ) ) = 0 ;
F_7 () ;
}
static int T_4
F_23 ( int V_28 )
{
int V_10 = F_3 () ;
int V_6 = F_2 ( V_28 ) ;
unsigned int V_29 ;
F_7 () ;
F_7 () ;
F_8 () ;
F_24 ( 7 ) ;
F_9 ( V_10 ) = 2 ;
F_10 ( V_10 ) = 0 ;
F_11 ( V_10 ) = V_6 ;
F_7 () ;
V_29 = * ( V_11 ) F_25 ( V_6 ) ;
F_7 () ;
F_7 () ;
if ( F_10 ( V_10 ) ) {
F_10 ( V_10 ) = 0 ;
V_29 = 0xffffffff ;
F_7 () ;
}
F_9 ( V_10 ) = 0 ;
F_7 () ;
return ( V_29 >> 16 ) == V_30 ;
}
static void T_4
F_26 ( int V_28 )
{
struct V_3 * V_4 ;
struct V_31 * V_32 , * V_33 , * V_34 ;
int V_6 = F_2 ( V_28 ) ;
V_4 = F_27 () ;
if ( V_28 == 0 )
V_35 = V_4 ;
V_32 = F_28 () ;
V_33 = F_28 () ;
V_34 = F_28 () ;
V_4 -> V_36 = V_32 ;
V_4 -> V_37 = V_34 ;
V_4 -> V_38 = F_29 ( V_6 ) - V_39 ;
V_4 -> V_40 = F_30 ( V_6 ) - V_39 ;
V_4 -> V_41 = F_31 ( V_6 ) - V_39 ;
V_4 -> V_42 = 0 ;
V_4 -> V_20 = F_32 ( V_6 ) ;
V_4 -> V_7 = V_28 ;
V_32 -> V_26 = F_31 ( V_6 ) - V_43 ;
V_32 -> V_27 = V_32 -> V_26 + 0xffff ;
V_32 -> V_44 = V_45 [ V_28 ] ;
V_32 -> V_5 = V_46 ;
V_33 -> V_26 = F_30 ( V_6 ) - V_47 ;
V_33 -> V_27 = V_33 -> V_26 + 0xffffffff ;
V_33 -> V_44 = V_48 [ V_28 ] ;
V_33 -> V_5 = V_49 ;
V_34 -> V_26 = V_33 -> V_26 ;
V_34 -> V_27 = V_33 -> V_26 + V_50 ;
V_34 -> V_44 = V_51 ;
V_34 -> V_5 = V_49 ;
if ( F_33 ( & V_52 , V_32 ) < 0 )
F_34 ( V_53 L_9 , V_28 ) ;
if ( F_33 ( & V_54 , V_33 ) < 0 )
F_34 ( V_53 L_10 , V_28 ) ;
if ( F_33 ( V_33 , V_34 ) < 0 )
F_34 ( V_53 L_11 , V_28 ) ;
}
static void
F_35 ( int V_6 )
{
* ( V_11 ) F_6 ( V_6 ) ;
* ( V_11 ) F_6 ( V_6 ) = 0xffffffff ;
F_7 () ;
* ( V_11 ) F_6 ( V_6 ) ;
}
static void T_4
F_36 ( struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 -> V_7 ) ;
unsigned int V_55 ;
F_35 ( V_6 ) ;
V_55 = * ( V_11 ) F_6 ( V_6 ) ;
V_55 |= 0x0006 ;
* ( V_11 ) F_6 ( V_6 ) = V_55 ;
F_7 () ;
V_55 = * ( V_11 ) F_6 ( V_6 ) ;
V_4 -> V_56 = F_37 ( V_4 , 0x00800000 , 0x00800000 , 0 ) ;
V_4 -> V_57 = F_37 ( V_4 , 0x40000000 ,
F_38 ( 0x40000000 ) , 0 ) ;
V_58 = 0x80000000 ;
V_59 = 0x80000000 ;
* ( V_11 ) F_39 ( V_6 ) = V_4 -> V_56 -> V_60 | 3 ;
* ( V_11 ) F_40 ( V_6 ) = ( V_4 -> V_56 -> V_21 - 1 ) & 0xfff00000 ;
* ( V_11 ) F_41 ( V_6 ) = F_42 ( V_4 -> V_56 -> V_61 ) >> 8 ;
* ( V_11 ) F_43 ( V_6 ) = V_4 -> V_57 -> V_60 | 3 ;
* ( V_11 ) F_44 ( V_6 ) = ( V_4 -> V_57 -> V_21 - 1 ) & 0xfff00000 ;
* ( V_11 ) F_45 ( V_6 ) = F_42 ( V_4 -> V_57 -> V_61 ) >> 8 ;
* ( V_11 ) F_46 ( V_6 ) = V_58 | 1 ;
* ( V_11 ) F_47 ( V_6 ) = ( V_59 - 1 ) & 0xfff00000 ;
* ( V_11 ) F_48 ( V_6 ) = 0 ;
* ( V_11 ) F_49 ( V_6 ) = 0x0 ;
F_20 ( V_4 , 0 , - 1 ) ;
* ( V_11 ) F_50 ( V_6 ) = 0x0 ;
F_7 () ;
* ( V_11 ) F_51 ( V_6 ) = 0U ;
F_7 () ;
* ( V_11 ) F_51 ( V_6 ) ;
* ( V_11 ) F_52 ( V_6 ) = 0 ;
F_7 () ;
* ( V_11 ) F_52 ( V_6 ) ;
}
void T_4
F_53 ( void )
{
V_52 . V_27 = ~ 0UL ;
F_26 ( 0 ) ;
}
void T_4
F_54 ( void )
{
struct V_3 * V_4 ;
int V_62 ;
int V_28 ;
V_62 = 0 ;
for ( V_28 = 0 ; V_28 < V_63 ; ++ V_28 ) {
if ( F_23 ( V_28 ) ) {
if ( V_28 != 0 )
F_26 ( V_28 ) ;
V_62 ++ ;
}
}
F_34 ( L_12 , V_62 ) ;
for ( V_4 = V_64 ; V_4 ; V_4 = V_4 -> V_65 )
F_36 ( V_4 ) ;
}
static void
F_55 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
int V_70 ;
V_69 = & V_67 -> V_71 ;
for ( V_70 = 0 ; V_70 < 24 ; V_70 += 2 ) {
F_34 ( L_13 ,
V_70 , V_70 + 1 , V_69 -> V_72 [ V_70 ] , V_69 -> V_72 [ V_70 + 1 ] ) ;
}
for ( V_70 = 0 ; V_70 < 8 ; V_70 += 2 ) {
F_34 ( L_14 ,
V_70 , V_70 + 1 , V_69 -> V_73 [ V_70 ] ,
V_69 -> V_73 [ V_70 + 1 ] ) ;
}
F_34 ( L_15 ,
V_69 -> V_74 ) ;
F_34 ( L_16 ,
V_69 -> V_75 ) ;
F_34 ( L_17 ,
V_69 -> V_76 ) ;
F_34 ( L_18 ,
V_69 -> V_77 ) ;
F_34 ( L_19 ,
V_69 -> V_78 ) ;
F_34 ( L_20 ,
V_69 -> V_79 ) ;
F_34 ( L_21 ,
( V_69 -> V_80 & 0x800L ) ?
L_22 : L_23 ,
V_69 -> V_80 ) ;
F_34 ( L_24 ,
V_69 -> V_81 ) ;
if ( V_69 -> V_81 & 0x2 ) {
switch ( V_69 -> V_81 & 0x03c ) {
case 8 :
F_34 ( L_25 ) ;
break;
case 4 :
F_34 ( L_26 ) ;
break;
case 20 :
F_34 ( L_27 ) ;
break;
case 10 :
F_34 ( L_28 ) ;
break;
}
}
F_34 ( L_29 ,
V_69 -> V_82 ) ;
F_34 ( L_30 ,
V_69 -> V_83 ) ;
F_34 ( L_31 ,
V_69 -> V_84 ) ;
F_34 ( L_32 ,
V_69 -> V_85 ) ;
F_34 ( L_33 ,
V_69 -> V_86 ) ;
F_34 ( L_34 ,
V_69 -> V_87 ) ;
F_34 ( L_35 ,
V_69 -> V_88 ) ;
F_34 ( L_36 ,
V_69 -> V_89 ) ;
F_34 ( L_37 ,
V_69 -> V_90 ) ;
}
static void
F_56 ( unsigned long V_91 )
{
struct V_92 * V_69 ;
struct V_3 * V_4 ;
struct V_93 {
unsigned long V_94 ;
unsigned int V_95 ;
unsigned int V_96 ;
unsigned int V_29 ;
unsigned int V_97 ;
unsigned int V_34 ;
unsigned int V_98 ;
unsigned int V_99 ;
unsigned int V_100 ;
unsigned int V_101 ;
unsigned int V_102 ;
unsigned int V_103 ;
unsigned int V_104 ;
unsigned int V_105 ;
unsigned int V_106 ;
unsigned int V_107 ;
unsigned int V_108 ;
unsigned int V_109 ;
unsigned int V_110 ;
unsigned int V_111 ;
unsigned int V_112 ;
unsigned int V_113 ;
unsigned int V_114 ;
} * V_115 ;
V_69 = (struct V_92 * ) V_91 ;
V_115 = (struct V_93 * ) ( V_91 + V_69 -> V_116 ) ;
for ( V_4 = V_64 ; V_4 ; V_4 = V_4 -> V_65 , V_115 ++ ) {
F_34 ( L_38 ,
V_4 -> V_7 , V_115 -> V_94 ) ;
F_34 ( L_39 , V_115 -> V_95 ) ;
F_34 ( L_40 , V_115 -> V_29 ) ;
F_34 ( L_41 , V_115 -> V_97 ) ;
F_34 ( L_42 , V_115 -> V_34 ) ;
F_34 ( L_43 , V_115 -> V_98 ) ;
F_34 ( L_44 , V_115 -> V_99 ) ;
F_34 ( L_45 , V_115 -> V_100 ) ;
F_34 ( L_46 , V_115 -> V_101 ) ;
F_34 ( L_47 , V_115 -> V_102 ) ;
F_34 ( L_48 , V_115 -> V_103 ) ;
F_34 ( L_49 , V_115 -> V_104 ) ;
F_34 ( L_50 , V_115 -> V_105 ) ;
F_34 ( L_51 , V_115 -> V_107 ) ;
F_34 ( L_52 , V_115 -> V_108 ) ;
F_34 ( L_53 , V_115 -> V_109 ) ;
F_34 ( L_54 , V_115 -> V_110 ) ;
F_34 ( L_55 , V_115 -> V_111 ) ;
}
}
void
F_57 ( unsigned long V_117 , unsigned long V_91 )
{
struct V_66 * V_118 ;
unsigned int V_10 = F_3 () ;
int V_119 ;
V_118 = (struct V_66 * ) V_91 ;
V_119 = F_9 ( V_10 ) ;
F_7 () ;
F_7 () ;
F_8 () ;
switch ( V_119 ) {
case 0 :
{
struct V_3 * V_4 ;
for ( V_4 = V_64 ; V_4 ; V_4 = V_4 -> V_65 )
F_35 ( F_2 ( V_4 -> V_7 ) ) ;
break;
}
case 1 :
F_35 ( F_11 ( V_10 ) ) ;
break;
default:
break;
}
F_24 ( 0x7 ) ;
F_7 () ;
F_58 ( V_117 , V_91 , L_56 , V_119 != 0 ) ;
if ( ! V_119 && V_117 != 0x620 && V_117 != 0x630 ) {
F_55 ( V_118 ) ;
F_56 ( V_91 ) ;
}
}
