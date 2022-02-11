static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_3 ) {
F_2 ( V_2 , V_3 , V_5 ) ;
if ( F_3 ( V_2 , V_3 ) & V_6 )
F_4 ( V_2 , V_3 , 0 ,
V_7 ,
V_8 ) ;
}
if ( V_4 )
F_4 ( V_2 , V_4 , 0 ,
V_7 , V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 )
{
if ( V_3 ) {
F_2 ( V_2 , V_3 , V_11 |
F_6 ( V_2 , V_3 ) ) ;
if ( F_3 ( V_2 , V_3 ) & V_12 )
F_4 ( V_2 , V_3 , 0 ,
V_7 ,
F_7 ( 0 ) ) ;
}
if ( V_10 )
F_4 ( V_2 , V_10 , 0 , V_7 ,
F_7 ( 0 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_13 , const char * V_14 ,
int V_15 , int V_16 )
{
char V_17 [ 44 ] ;
int type = V_16 ? V_18 : V_19 ;
struct V_20 V_21 =
F_9 ( V_17 , V_13 , V_15 , 0 , type ) ;
sprintf ( V_17 , L_1 , V_14 , V_22 [ V_16 ] ) ;
return F_10 ( V_2 , V_13 , F_11 ( & V_21 , V_2 ) ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_13 , const char * V_14 ,
int V_15 , int V_16 )
{
char V_17 [ 44 ] ;
int type = V_16 ? V_18 : V_19 ;
struct V_20 V_21 =
F_13 ( V_17 , V_13 , V_15 , 0 , type ) ;
sprintf ( V_17 , L_2 , V_14 , V_22 [ V_16 ] ) ;
return F_10 ( V_2 , V_13 , F_11 ( & V_21 , V_2 ) ) ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_23 ,
unsigned int V_24 )
{
unsigned int V_25 ;
int V_26 = 50 ;
do {
V_25 = F_15 ( V_2 , V_27 , 0 ,
V_23 , V_24 ) ;
if ( V_25 == V_28 )
return 0 ;
} while ( -- V_26 );
return - V_29 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_30 )
{
int V_25 ;
V_25 = F_14 ( V_2 , V_31 ,
V_30 & 0xffff ) ;
if ( V_25 != - V_29 ) {
V_25 = F_14 ( V_2 , V_32 ,
V_30 >> 16 ) ;
}
return V_25 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_24 )
{
int V_25 ;
V_25 = F_14 ( V_2 , V_33 , V_24 & 0xffff ) ;
if ( V_25 != - V_29 ) {
V_25 = F_14 ( V_2 , V_34 ,
V_24 >> 16 ) ;
}
return V_25 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int * V_24 )
{
int V_25 ;
V_25 = F_14 ( V_2 , V_35 , 0 ) ;
if ( V_25 != - V_29 ) {
V_25 = F_14 ( V_2 , V_36 , 0 ) ;
}
if ( V_25 != - V_29 ) {
* V_24 = F_15 ( V_2 , V_27 , 0 ,
V_37 ,
0 ) ;
}
return V_25 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned int V_30 , const unsigned int V_24 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
int V_40 ;
F_20 ( & V_39 -> V_41 ) ;
V_40 = F_16 ( V_2 , V_30 ) ;
if ( V_40 < 0 )
goto exit;
V_40 = F_17 ( V_2 , V_24 ) ;
if ( V_40 < 0 )
goto exit;
exit:
F_21 ( & V_39 -> V_41 ) ;
return V_40 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int V_30 , unsigned int * V_24 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
int V_40 ;
F_20 ( & V_39 -> V_41 ) ;
V_40 = F_16 ( V_2 , V_30 ) ;
if ( V_40 < 0 )
goto exit;
V_40 = F_18 ( V_2 , V_24 ) ;
if ( V_40 < 0 )
goto exit;
exit:
F_21 ( & V_39 -> V_41 ) ;
return V_40 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_13 ,
T_2 V_42 ,
int V_43 , int V_44 )
{
unsigned int V_45 , V_46 ;
if ( ! V_13 )
return;
F_24 ( L_3
L_4 ,
V_13 , V_42 , V_43 , V_44 ) ;
V_45 = F_15 ( V_2 , V_13 , 0 ,
V_47 ,
0 ) ;
if ( V_45 != V_44 ) {
F_25 ( 20 ) ;
F_4 ( V_2 , V_13 , 0 ,
V_48 ,
V_44 ) ;
}
V_45 = F_15 ( V_2 , V_13 , 0 , V_49 , 0 ) ;
V_46 = ( V_42 << 4 ) | V_43 ;
if ( V_45 != V_46 ) {
F_4 ( V_2 , V_13 , 0 ,
V_50 ,
V_46 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 V_13 )
{
F_4 ( V_2 , V_13 , 0 , V_48 , 0 ) ;
F_4 ( V_2 , V_13 , 0 , V_50 , 0 ) ;
}
static int F_27 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
unsigned int V_42 ,
unsigned int V_44 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_23 ( V_2 , V_39 -> V_55 [ 0 ] , V_42 , 0 , V_44 ) ;
return 0 ;
}
static int F_28 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_26 ( V_2 , V_39 -> V_55 [ 0 ] ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
unsigned int V_42 ,
unsigned int V_44 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_23 ( V_2 , V_39 -> V_56 , V_42 , 0 , V_44 ) ;
return 0 ;
}
static int F_30 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_26 ( V_2 , V_39 -> V_56 ) ;
return 0 ;
}
static int F_31 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
unsigned int V_42 ,
unsigned int V_44 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_23 ( V_2 , V_39 -> V_57 [ V_54 -> V_58 ] ,
V_42 , 0 , V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_26 ( V_2 , V_39 -> V_57 [ V_54 -> V_58 ] ) ;
return 0 ;
}
static int F_33 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
unsigned int V_42 ,
unsigned int V_44 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_23 ( V_2 , V_39 -> V_59 , V_42 , 0 , V_44 ) ;
return 0 ;
}
static int F_34 ( struct V_51 * V_52 ,
struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_26 ( V_2 , V_39 -> V_59 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_60 * V_61 = V_39 -> V_62 ;
V_2 -> V_63 = V_61 ;
V_2 -> V_64 = 0 ;
V_61 -> V_65 = L_5 ;
V_61 -> V_66 [ V_67 ] = V_68 ;
V_61 -> V_66 [ V_67 ] . V_13 = V_39 -> V_55 [ 0 ] ;
V_61 -> V_66 [ V_67 ] . V_69 =
V_39 -> V_70 . V_71 ;
V_61 -> V_66 [ V_72 ] = V_73 ;
V_61 -> V_66 [ V_72 ] . V_74 = V_39 -> V_75 ;
V_61 -> V_66 [ V_72 ] . V_13 = V_39 -> V_57 [ 0 ] ;
V_2 -> V_64 ++ ;
if ( ! V_39 -> V_56 && ! V_39 -> V_59 )
return 0 ;
V_61 ++ ;
V_61 -> V_65 = L_6 ;
V_61 -> V_76 = V_77 ;
if ( V_39 -> V_56 ) {
V_61 -> V_66 [ V_67 ] =
V_78 ;
V_61 -> V_66 [ V_67 ] . V_13 = V_39 -> V_56 ;
}
if ( V_39 -> V_59 ) {
V_61 -> V_66 [ V_72 ] =
V_79 ;
V_61 -> V_66 [ V_72 ] . V_13 = V_39 -> V_59 ;
}
V_2 -> V_64 ++ ;
return 0 ;
}
static int F_36 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_37 ( V_81 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
long * V_84 = V_83 -> V_85 . integer . V_85 ;
* V_84 = V_39 -> V_86 ;
return 0 ;
}
static int F_38 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_37 ( V_81 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
long * V_84 = V_83 -> V_85 . integer . V_85 ;
unsigned int V_24 ;
int V_40 ;
if ( V_39 -> V_86 == * V_84 )
return 0 ;
F_39 ( V_2 ) ;
V_40 = F_22 ( V_2 , V_87 , & V_24 ) ;
if ( V_40 < 0 )
goto exit;
V_24 = ( V_24 & 0x7f ) | ( * V_84 ? 0 : 0x80 ) ;
V_40 = F_19 ( V_2 , V_87 , V_24 ) ;
if ( V_40 < 0 )
goto exit;
V_39 -> V_86 = * V_84 ;
exit:
F_40 ( V_2 ) ;
return V_40 < 0 ? V_40 : 1 ;
}
static int F_41 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_37 ( V_81 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
long * V_84 = V_83 -> V_85 . integer . V_85 ;
* V_84 = V_39 -> V_88 ;
return 0 ;
}
static int F_42 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_37 ( V_81 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
long * V_84 = V_83 -> V_85 . integer . V_85 ;
unsigned int V_24 ;
int V_40 ;
if ( V_39 -> V_88 == * V_84 )
return 0 ;
F_39 ( V_2 ) ;
V_40 = F_22 ( V_2 , V_87 , & V_24 ) ;
if ( V_40 < 0 )
goto exit;
V_24 = ( V_24 & 0xef ) | ( * V_84 ? 0 : 0x10 ) ;
V_40 = F_19 ( V_2 , V_87 , V_24 ) ;
if ( V_40 < 0 )
goto exit;
V_39 -> V_88 = * V_84 ;
exit:
F_40 ( V_2 ) ;
return V_40 < 0 ? V_40 : 1 ;
}
static int F_43 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_37 ( V_81 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
long * V_84 = V_83 -> V_85 . integer . V_85 ;
* V_84 ++ = V_39 -> V_89 [ 0 ] ;
* V_84 = V_39 -> V_89 [ 1 ] ;
return 0 ;
}
static int F_44 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_37 ( V_81 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
long * V_84 = V_83 -> V_85 . integer . V_85 ;
long V_90 , V_91 ;
unsigned int V_24 ;
int V_92 ;
int V_40 ;
V_90 = * V_84 ++ ;
V_91 = * V_84 ;
if ( ( V_39 -> V_89 [ 0 ] == V_90 ) &&
( V_39 -> V_89 [ 1 ] == V_91 ) )
return 0 ;
F_39 ( V_2 ) ;
V_40 = F_22 ( V_2 , V_93 , & V_24 ) ;
if ( V_40 < 0 )
goto exit;
V_92 = 31 - V_90 ;
V_24 = ( V_24 & 0xe0 ) | V_92 ;
V_40 = F_19 ( V_2 , V_93 , V_24 ) ;
if ( V_40 < 0 )
goto exit;
V_92 = 31 - V_91 ;
V_24 = ( V_24 & 0xe0 ) | V_92 ;
V_40 = F_19 ( V_2 , V_94 , V_24 ) ;
if ( V_40 < 0 )
goto exit;
V_39 -> V_89 [ 0 ] = V_90 ;
V_39 -> V_89 [ 1 ] = V_91 ;
exit:
F_40 ( V_2 ) ;
return V_40 < 0 ? V_40 : 1 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_20 V_21 =
F_9 ( L_7 ,
V_13 , 1 , 0 , V_19 ) ;
V_21 . V_95 = F_36 ;
V_21 . V_96 = F_38 ;
return F_10 ( V_2 , V_13 , F_11 ( & V_21 , V_2 ) ) ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_20 V_21 =
F_13 ( L_8 ,
V_13 , 3 , 0 , V_19 ) ;
V_21 . V_95 = F_43 ;
V_21 . V_96 = F_44 ;
return F_10 ( V_2 , V_13 , F_11 ( & V_21 , V_2 ) ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_20 V_21 =
F_9 ( L_9 ,
V_13 , 1 , 0 , V_19 ) ;
V_21 . V_95 = F_41 ;
V_21 . V_96 = F_42 ;
return F_10 ( V_2 , V_13 , F_11 ( & V_21 , V_2 ) ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_97 * V_98 = & V_39 -> V_99 ;
unsigned int V_100 ;
V_100 = 0x80031f06 ;
F_49 ( V_2 , V_98 -> V_101 [ 0 ] , V_19 , V_100 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_97 * V_98 = & V_39 -> V_99 ;
int V_102 , V_40 ;
if ( V_39 -> V_70 . V_103 ) {
V_40 = F_47 ( V_2 , V_39 -> V_104 [ 0 ] ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_98 -> V_105 ) {
F_48 ( V_2 ) ;
V_40 = F_45 ( V_2 , V_98 -> V_101 [ 0 ] ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_46 ( V_2 , V_98 -> V_101 [ 0 ] ) ;
if ( V_40 < 0 )
return V_40 ;
}
for ( V_102 = 0 ; V_102 < V_39 -> V_75 ; V_102 ++ ) {
const char * V_106 = V_39 -> V_107 [ V_102 ] ;
V_40 = F_51 ( V_2 , V_39 -> V_57 [ V_102 ] , V_106 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_52 ( V_2 , V_39 -> V_57 [ V_102 ] , V_106 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_98 -> V_108 [ V_102 ] . type == V_109 ) {
V_40 = F_53 ( V_2 , V_39 -> V_110 [ V_102 ] ,
L_10 , 1 ) ;
if ( V_40 < 0 )
return V_40 ;
}
}
if ( V_39 -> V_56 ) {
V_40 = F_54 ( V_2 , V_39 -> V_56 ,
V_39 -> V_56 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_55 ( V_2 , V_39 -> V_56 , L_11 ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_39 -> V_59 ) {
V_40 = F_56 ( V_2 , V_39 -> V_59 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_52 ( V_2 , V_39 -> V_59 , L_11 ) ;
if ( V_40 < 0 )
return V_40 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , int V_111 )
{
F_24 ( L_12 ) ;
F_4 ( V_2 , V_27 , 0 ,
V_112 ,
V_111 ) ;
F_25 ( 20 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_97 * V_98 = & V_39 -> V_99 ;
V_98 -> V_113 = 1 ;
V_98 -> V_114 [ 0 ] = 0x0b ;
V_98 -> V_115 = V_116 ;
V_39 -> V_55 [ 0 ] = 0x02 ;
V_39 -> V_104 [ 0 ] = 0x0b ;
V_39 -> V_70 . V_117 = V_39 -> V_55 ;
V_39 -> V_70 . V_103 = 1 ;
V_39 -> V_70 . V_71 = 2 ;
V_98 -> V_105 = 1 ;
V_98 -> V_101 [ 0 ] = 0x0f ;
V_39 -> V_118 = 0 ;
V_39 -> V_70 . V_119 = 0 ;
V_98 -> V_75 = 2 ;
V_98 -> V_108 [ 0 ] . V_3 = 0x12 ;
V_98 -> V_108 [ 0 ] . type = V_109 ;
V_98 -> V_108 [ 1 ] . V_3 = 0x11 ;
V_98 -> V_108 [ 1 ] . type = V_120 ;
V_39 -> V_110 [ 0 ] = 0x12 ;
V_39 -> V_107 [ 0 ] = L_13 ;
V_39 -> V_57 [ 0 ] = 0x07 ;
V_39 -> V_110 [ 1 ] = 0x11 ;
V_39 -> V_107 [ 1 ] = L_14 ;
V_39 -> V_57 [ 1 ] = 0x08 ;
V_39 -> V_75 = 2 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
F_60 ( & V_39 -> V_41 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_97 * V_98 = & V_39 -> V_99 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_39 -> V_70 . V_103 ; V_102 ++ ) {
F_1 ( V_2 , V_39 -> V_104 [ V_102 ] ,
V_39 -> V_70 . V_117 [ V_102 ] ) ;
}
F_1 ( V_2 , V_98 -> V_101 [ 0 ] , V_39 -> V_118 ) ;
F_1 ( V_2 , V_98 -> V_121 [ 0 ] , V_39 -> V_56 ) ;
for ( V_102 = 0 ; V_102 < V_39 -> V_75 ; V_102 ++ )
F_5 ( V_2 , V_39 -> V_110 [ V_102 ] , V_39 -> V_57 [ V_102 ] ) ;
F_5 ( V_2 , V_98 -> V_122 , V_39 -> V_59 ) ;
F_57 ( V_2 , 1 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_57 ( V_2 , 0 ) ;
F_61 ( V_2 ) ;
F_64 ( V_2 -> V_39 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
F_24 ( L_15 ) ;
V_39 = F_66 ( sizeof( * V_39 ) , V_123 ) ;
if ( ! V_39 )
return - V_124 ;
V_2 -> V_39 = V_39 ;
F_59 ( V_2 ) ;
F_58 ( V_2 ) ;
V_2 -> V_125 = V_126 ;
return 0 ;
}
static int T_3 F_67 ( void )
{
return F_68 ( & V_127 ) ;
}
static void T_4 F_69 ( void )
{
F_70 ( & V_127 ) ;
}
