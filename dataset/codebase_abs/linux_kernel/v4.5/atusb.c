static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
T_1 V_3 , T_1 V_4 ,
T_2 V_5 , T_2 V_6 ,
void * V_7 , T_2 V_8 , int V_9 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
int V_12 ;
if ( V_1 -> V_13 )
return V_1 -> V_13 ;
V_12 = F_2 ( V_11 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_12 < 0 ) {
V_1 -> V_13 = V_12 ;
F_3 ( & V_11 -> V_14 ,
L_1 ,
V_3 , V_5 , V_6 , V_12 ) ;
}
return V_12 ;
}
static int F_4 ( struct V_1 * V_1 , T_3 V_15 , T_3 V_16 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
F_5 ( & V_11 -> V_14 , L_2 , V_15 ) ;
return F_1 ( V_1 , F_6 ( V_11 , 0 ) ,
V_15 , V_17 , V_16 , 0 , NULL , 0 , 1000 ) ;
}
static int F_7 ( struct V_1 * V_1 , T_3 V_18 , T_3 V_5 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
F_5 ( & V_11 -> V_14 , L_3 ,
V_18 , V_5 ) ;
return F_1 ( V_1 , F_6 ( V_11 , 0 ) ,
V_19 , V_17 ,
V_5 , V_18 , NULL , 0 , 1000 ) ;
}
static int F_8 ( struct V_1 * V_1 , T_3 V_18 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
int V_12 ;
T_3 V_5 ;
F_5 ( & V_11 -> V_14 , L_4 , V_18 ) ;
V_12 = F_1 ( V_1 , F_9 ( V_11 , 0 ) ,
V_20 , V_21 ,
0 , V_18 , & V_5 , 1 , 1000 ) ;
return V_12 >= 0 ? V_5 : V_12 ;
}
static int F_10 ( struct V_1 * V_1 , T_3 V_18 , T_3 V_22 ,
T_3 V_23 , T_3 V_5 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
T_3 V_24 , V_25 ;
int V_12 = 0 ;
F_5 ( & V_11 -> V_14 , L_5 ,
V_18 , V_5 ) ;
V_24 = F_8 ( V_1 , V_18 ) ;
V_25 = V_24 & ~ V_22 ;
V_25 |= ( V_5 << V_23 ) & V_22 ;
if ( V_25 != V_24 )
V_12 = F_7 ( V_1 , V_18 , V_25 ) ;
return V_12 ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_13 = V_1 -> V_13 ;
V_1 -> V_13 = 0 ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_26 * V_26 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
struct V_27 * V_28 = V_26 -> V_29 ;
int V_12 ;
if ( ! V_28 ) {
V_28 = F_13 ( V_30 , V_31 ) ;
if ( ! V_28 ) {
F_14 ( & V_11 -> V_14 ,
L_6 ) ;
return - V_32 ;
}
F_15 ( V_28 , V_30 ) ;
F_16 ( V_28 ) = V_1 ;
}
F_17 ( V_26 , V_11 , F_18 ( V_11 , 1 ) ,
V_28 -> V_7 , V_30 , V_33 , V_28 ) ;
F_19 ( V_26 , & V_1 -> V_34 ) ;
V_12 = F_20 ( V_26 , V_31 ) ;
if ( V_12 ) {
F_21 ( V_26 ) ;
F_22 ( V_28 ) ;
V_26 -> V_29 = NULL ;
}
return V_12 ;
}
static void F_23 ( struct V_35 * V_36 )
{
struct V_1 * V_1 =
F_24 ( F_25 ( V_36 ) , struct V_1 , V_36 ) ;
struct V_10 * V_11 = V_1 -> V_11 ;
struct V_26 * V_26 ;
int V_12 ;
if ( V_1 -> V_37 )
return;
do {
V_26 = F_26 ( & V_1 -> V_38 ) ;
if ( ! V_26 )
return;
V_12 = F_12 ( V_1 , V_26 ) ;
} while ( ! V_12 );
F_19 ( V_26 , & V_1 -> V_38 ) ;
F_14 ( & V_11 -> V_14 ,
L_7 , V_12 ) ;
F_27 ( & V_1 -> V_36 ,
F_28 ( V_39 ) + 1 ) ;
}
static void F_29 ( struct V_1 * V_1 , T_3 V_40 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
T_3 V_41 = V_1 -> V_42 ;
F_5 ( & V_11 -> V_14 , L_8 , V_40 , V_41 ) ;
if ( V_40 == V_41 ) {
F_30 ( V_1 -> V_43 , V_1 -> V_44 , false ) ;
} else {
F_31 ( V_1 -> V_43 ) ;
if ( V_1 -> V_44 )
F_32 ( V_1 -> V_44 ) ;
}
}
static void F_33 ( struct V_26 * V_26 )
{
struct V_10 * V_11 = V_26 -> V_14 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_1 * V_1 = F_16 ( V_28 ) ;
T_3 V_45 , V_46 ;
if ( ! V_26 -> V_47 ) {
F_5 ( & V_11 -> V_14 , L_9 ) ;
return;
}
V_45 = * V_28 -> V_7 ;
if ( V_26 -> V_47 == 1 ) {
F_29 ( V_1 , V_45 ) ;
return;
}
if ( V_45 + 1 > V_26 -> V_47 - 1 ) {
F_5 ( & V_11 -> V_14 , L_10 ,
V_45 , V_26 -> V_47 ) ;
return;
}
if ( ! F_34 ( V_45 ) ) {
F_5 ( & V_11 -> V_14 , L_11 ) ;
return;
}
V_46 = V_28 -> V_7 [ V_45 + 1 ] ;
F_5 ( & V_11 -> V_14 , L_12 , V_45 , V_46 ) ;
F_35 ( V_28 , 1 ) ;
F_36 ( V_28 , V_45 ) ;
F_37 ( V_1 -> V_43 , V_28 , V_46 ) ;
V_26 -> V_29 = NULL ;
}
static void V_33 ( struct V_26 * V_26 )
{
struct V_10 * V_11 = V_26 -> V_14 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_1 * V_1 = F_16 ( V_28 ) ;
F_5 ( & V_11 -> V_14 , L_13 ,
V_26 -> V_48 , V_26 -> V_47 ) ;
if ( V_26 -> V_48 ) {
if ( V_26 -> V_48 == - V_49 ) {
F_22 ( V_28 ) ;
V_26 -> V_29 = NULL ;
return;
}
F_5 ( & V_11 -> V_14 , L_14 , V_26 -> V_48 ) ;
} else {
F_33 ( V_26 ) ;
}
F_19 ( V_26 , & V_1 -> V_38 ) ;
if ( ! V_1 -> V_37 )
F_27 ( & V_1 -> V_36 , 0 ) ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_26 * V_26 ;
while ( 1 ) {
V_26 = F_26 ( & V_1 -> V_38 ) ;
if ( ! V_26 )
break;
F_22 ( V_26 -> V_29 ) ;
F_39 ( V_26 ) ;
}
}
static int F_40 ( struct V_1 * V_1 , int V_50 )
{
struct V_26 * V_26 ;
while ( V_50 ) {
V_26 = F_41 ( 0 , V_31 ) ;
if ( ! V_26 ) {
F_38 ( V_1 ) ;
return - V_32 ;
}
F_19 ( V_26 , & V_1 -> V_38 ) ;
V_50 -- ;
}
return 0 ;
}
static void F_42 ( struct V_26 * V_26 )
{
F_5 ( & V_26 -> V_14 -> V_14 , L_15 ) ;
}
static int F_43 ( struct V_51 * V_43 , struct V_27 * V_28 )
{
struct V_1 * V_1 = V_43 -> V_52 ;
struct V_10 * V_11 = V_1 -> V_11 ;
int V_12 ;
F_5 ( & V_11 -> V_14 , L_16 , V_28 -> V_45 ) ;
V_1 -> V_44 = V_28 ;
V_1 -> V_42 ++ ;
V_1 -> V_53 . V_54 = F_44 ( V_1 -> V_42 ) ;
V_1 -> V_53 . V_55 = F_44 ( V_28 -> V_45 ) ;
F_45 ( V_1 -> V_56 , V_11 ,
F_6 ( V_11 , 0 ) ,
( unsigned char * ) & V_1 -> V_53 , V_28 -> V_7 ,
V_28 -> V_45 , F_42 , NULL ) ;
V_12 = F_20 ( V_1 -> V_56 , V_57 ) ;
F_5 ( & V_11 -> V_14 , L_17 , V_12 ) ;
return V_12 ;
}
static int F_46 ( struct V_51 * V_43 , T_4 V_58 , T_4 V_59 )
{
struct V_1 * V_1 = V_43 -> V_52 ;
int V_12 ;
V_12 = F_7 ( V_1 , V_60 , V_59 ) ;
if ( V_12 < 0 )
return V_12 ;
F_47 ( 1 ) ;
return 0 ;
}
static int F_48 ( struct V_51 * V_43 , T_4 * V_61 )
{
F_49 ( ! V_61 ) ;
* V_61 = 0xbe ;
return 0 ;
}
static int F_50 ( struct V_51 * V_43 ,
struct V_62 * V_63 ,
unsigned long V_64 )
{
struct V_1 * V_1 = V_43 -> V_52 ;
struct V_65 * V_14 = & V_1 -> V_11 -> V_14 ;
if ( V_64 & V_66 ) {
T_5 V_67 = F_51 ( V_63 -> V_68 ) ;
F_52 ( V_14 , L_18 ) ;
F_7 ( V_1 , V_69 , V_67 ) ;
F_7 ( V_1 , V_70 , V_67 >> 8 ) ;
}
if ( V_64 & V_71 ) {
T_5 V_72 = F_51 ( V_63 -> V_73 ) ;
F_52 ( V_14 , L_19 ) ;
F_7 ( V_1 , V_74 , V_72 ) ;
F_7 ( V_1 , V_75 , V_72 >> 8 ) ;
}
if ( V_64 & V_76 ) {
T_4 V_77 , V_67 [ V_78 ] ;
memcpy ( V_67 , & V_63 -> V_79 , V_78 ) ;
F_52 ( V_14 , L_20 ) ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ )
F_7 ( V_1 , V_80 + V_77 , V_67 [ V_77 ] ) ;
}
if ( V_64 & V_81 ) {
F_52 ( V_14 ,
L_21 ) ;
if ( V_63 -> V_82 )
F_10 ( V_1 , V_83 , 1 ) ;
else
F_10 ( V_1 , V_83 , 0 ) ;
}
return F_11 ( V_1 ) ;
}
static int F_53 ( struct V_51 * V_43 )
{
struct V_1 * V_1 = V_43 -> V_52 ;
struct V_10 * V_11 = V_1 -> V_11 ;
int V_12 ;
F_5 ( & V_11 -> V_14 , L_22 ) ;
F_27 ( & V_1 -> V_36 , 0 ) ;
F_4 ( V_1 , V_84 , 1 ) ;
V_12 = F_11 ( V_1 ) ;
if ( V_12 < 0 )
F_54 ( & V_1 -> V_38 ) ;
return V_12 ;
}
static void F_55 ( struct V_51 * V_43 )
{
struct V_1 * V_1 = V_43 -> V_52 ;
struct V_10 * V_11 = V_1 -> V_11 ;
F_5 ( & V_11 -> V_14 , L_23 ) ;
F_54 ( & V_1 -> V_38 ) ;
F_4 ( V_1 , V_84 , 0 ) ;
F_11 ( V_1 ) ;
}
static int
F_56 ( struct V_51 * V_43 , T_6 V_85 )
{
struct V_1 * V_1 = V_43 -> V_52 ;
T_7 V_77 ;
for ( V_77 = 0 ; V_77 < V_43 -> V_86 -> V_87 . V_88 ; V_77 ++ ) {
if ( V_43 -> V_86 -> V_87 . V_89 [ V_77 ] == V_85 )
return F_10 ( V_1 , V_90 , V_77 ) ;
}
return - V_91 ;
}
static int
F_57 ( struct V_51 * V_43 , const bool V_92 )
{
struct V_1 * V_1 = V_43 -> V_52 ;
int V_12 ;
if ( V_92 ) {
V_12 = F_10 ( V_1 , V_93 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_1 , V_94 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
} else {
V_12 = F_10 ( V_1 , V_94 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_1 , V_93 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
unsigned char V_95 [ 3 ] ;
int V_12 ;
V_12 = F_1 ( V_1 , F_9 ( V_11 , 0 ) ,
V_96 , V_21 , 0 , 0 ,
V_95 , 3 , 1000 ) ;
if ( V_12 >= 0 )
F_59 ( & V_11 -> V_14 ,
L_24 ,
V_95 [ 0 ] , V_95 [ 1 ] , V_95 [ 2 ] ) ;
if ( V_95 [ 0 ] == 0 && V_95 [ 1 ] < 2 ) {
F_59 ( & V_11 -> V_14 ,
L_25 ,
V_95 [ 0 ] , V_95 [ 1 ] ) ;
F_59 ( & V_11 -> V_14 , L_26 ) ;
}
return V_12 ;
}
static int F_60 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
char V_97 [ V_98 + 1 ] ;
int V_12 ;
V_12 = F_1 ( V_1 , F_9 ( V_11 , 0 ) ,
V_99 , V_21 , 0 , 0 ,
V_97 , V_98 , 1000 ) ;
if ( V_12 >= 0 ) {
V_97 [ V_12 ] = 0 ;
F_59 ( & V_11 -> V_14 , L_27 , V_97 ) ;
}
return V_12 ;
}
static int F_61 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
T_3 V_100 , V_101 , V_102 , V_103 ;
const char * V_104 ;
V_100 = F_8 ( V_1 , V_105 ) ;
V_101 = F_8 ( V_1 , V_106 ) ;
V_102 = F_8 ( V_1 , V_107 ) ;
V_103 = F_8 ( V_1 , V_108 ) ;
if ( V_1 -> V_13 )
return V_1 -> V_13 ;
if ( ( V_101 << 8 | V_100 ) != V_109 ) {
F_3 ( & V_11 -> V_14 ,
L_28 ,
V_101 , V_100 ) ;
goto V_110;
}
switch ( V_102 ) {
case 2 :
V_104 = L_29 ;
break;
case 3 :
V_104 = L_30 ;
break;
default:
F_3 ( & V_11 -> V_14 ,
L_31 ,
V_102 , V_103 ) ;
goto V_110;
}
F_59 ( & V_11 -> V_14 , L_32 , V_104 , V_103 ) ;
return 0 ;
V_110:
V_1 -> V_13 = - V_111 ;
return - V_111 ;
}
static int F_62 ( struct V_112 * V_113 ,
const struct V_114 * V_115 )
{
struct V_10 * V_11 = F_63 ( V_113 ) ;
struct V_51 * V_43 ;
struct V_1 * V_1 = NULL ;
int V_12 = - V_32 ;
V_43 = F_64 ( sizeof( struct V_1 ) , & V_116 ) ;
if ( ! V_43 )
return - V_32 ;
V_1 = V_43 -> V_52 ;
V_1 -> V_43 = V_43 ;
V_1 -> V_11 = F_65 ( V_11 ) ;
F_66 ( V_113 , V_1 ) ;
V_1 -> V_37 = 0 ;
V_1 -> V_13 = 0 ;
F_67 ( & V_1 -> V_36 , F_23 ) ;
F_68 ( & V_1 -> V_38 ) ;
F_68 ( & V_1 -> V_34 ) ;
if ( F_40 ( V_1 , V_117 ) )
goto V_110;
V_1 -> V_53 . V_118 = V_17 ;
V_1 -> V_53 . V_119 = V_120 ;
V_1 -> V_53 . V_121 = F_44 ( 0 ) ;
V_1 -> V_56 = F_41 ( 0 , V_57 ) ;
if ( ! V_1 -> V_56 )
goto V_110;
V_43 -> V_122 = & V_11 -> V_14 ;
V_43 -> V_123 = V_124 | V_125 |
V_126 ;
V_43 -> V_86 -> V_123 = V_127 ;
V_43 -> V_86 -> V_128 = 0 ;
V_43 -> V_86 -> V_129 = 11 ;
V_43 -> V_86 -> V_87 . V_130 [ 0 ] = 0x7FFF800 ;
V_43 -> V_86 -> V_87 . V_89 = V_131 ;
V_43 -> V_86 -> V_87 . V_88 = F_69 ( V_131 ) ;
V_43 -> V_86 -> V_132 = V_43 -> V_86 -> V_87 . V_89 [ 0 ] ;
F_70 ( & V_43 -> V_86 -> V_133 ) ;
F_4 ( V_1 , V_134 , 0 ) ;
F_61 ( V_1 ) ;
F_58 ( V_1 ) ;
F_60 ( V_1 ) ;
V_12 = F_11 ( V_1 ) ;
if ( V_12 ) {
F_3 ( & V_1 -> V_11 -> V_14 ,
L_33 ,
V_135 , V_12 ) ;
goto V_110;
}
V_12 = F_71 ( V_43 ) ;
if ( V_12 )
goto V_110;
F_7 ( V_1 , V_136 , V_137 ) ;
F_47 ( 1 ) ;
#if 0
atusb_write_subreg(atusb, SR_RX_SAFE_MODE, 1);
#endif
F_7 ( V_1 , V_138 , 0xff ) ;
V_12 = F_11 ( V_1 ) ;
if ( ! V_12 )
return 0 ;
F_3 ( & V_1 -> V_11 -> V_14 ,
L_34 ,
V_135 , V_12 ) ;
F_72 ( V_43 ) ;
V_110:
F_38 ( V_1 ) ;
F_73 ( V_1 -> V_56 ) ;
F_39 ( V_1 -> V_56 ) ;
F_74 ( V_11 ) ;
F_75 ( V_43 ) ;
return V_12 ;
}
static void F_76 ( struct V_112 * V_113 )
{
struct V_1 * V_1 = F_77 ( V_113 ) ;
F_5 ( & V_1 -> V_11 -> V_14 , L_35 ) ;
V_1 -> V_37 = 1 ;
F_78 ( & V_1 -> V_36 ) ;
F_54 ( & V_1 -> V_34 ) ;
F_38 ( V_1 ) ;
F_73 ( V_1 -> V_56 ) ;
F_39 ( V_1 -> V_56 ) ;
F_72 ( V_1 -> V_43 ) ;
F_75 ( V_1 -> V_43 ) ;
F_66 ( V_113 , NULL ) ;
F_74 ( V_1 -> V_11 ) ;
F_79 ( L_36 ) ;
}
