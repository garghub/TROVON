static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_3 ) {
F_2 ( V_2 , V_3 , V_5 ) ;
if ( F_3 ( V_2 , V_3 ) & V_6 )
F_4 ( V_2 , V_3 , 0 ,
V_7 ,
V_8 ) ;
}
if ( V_4 && ( F_3 ( V_2 , V_4 ) & V_6 ) )
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
if ( V_10 && ( F_3 ( V_2 , V_10 ) & V_12 ) )
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
if ( ( F_10 ( V_2 , V_13 , type ) & V_22 ) == 0 ) {
F_11 ( L_1 , V_14 , V_23 [ V_16 ] , V_13 ) ;
return 0 ;
}
sprintf ( V_17 , L_2 , V_14 , V_23 [ V_16 ] ) ;
return F_12 ( V_2 , V_13 , F_13 ( & V_21 , V_2 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_13 , const char * V_14 ,
int V_15 , int V_16 )
{
char V_17 [ 44 ] ;
int type = V_16 ? V_18 : V_19 ;
struct V_20 V_21 =
F_15 ( V_17 , V_13 , V_15 , 0 , type ) ;
if ( ( F_10 ( V_2 , V_13 , type ) & V_24 ) == 0 ) {
F_11 ( L_3 , V_14 , V_23 [ V_16 ] , V_13 ) ;
return 0 ;
}
sprintf ( V_17 , L_4 , V_14 , V_23 [ V_16 ] ) ;
return F_12 ( V_2 , V_13 , F_13 ( & V_21 , V_2 ) ) ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_25 ,
unsigned int V_26 )
{
unsigned int V_27 ;
int V_28 = 50 ;
do {
V_27 = F_17 ( V_2 , V_29 , 0 ,
V_25 , V_26 ) ;
if ( V_27 == V_30 )
return 0 ;
} while ( -- V_28 );
return - V_31 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_32 )
{
int V_27 ;
V_27 = F_16 ( V_2 , V_33 ,
V_32 & 0xffff ) ;
if ( V_27 != - V_31 ) {
V_27 = F_16 ( V_2 , V_34 ,
V_32 >> 16 ) ;
}
return V_27 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_26 )
{
int V_27 ;
V_27 = F_16 ( V_2 , V_35 , V_26 & 0xffff ) ;
if ( V_27 != - V_31 ) {
V_27 = F_16 ( V_2 , V_36 ,
V_26 >> 16 ) ;
}
return V_27 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned int * V_26 )
{
int V_27 ;
V_27 = F_16 ( V_2 , V_37 , 0 ) ;
if ( V_27 != - V_31 ) {
V_27 = F_16 ( V_2 , V_38 , 0 ) ;
}
if ( V_27 != - V_31 ) {
* V_26 = F_17 ( V_2 , V_29 , 0 ,
V_39 ,
0 ) ;
}
return V_27 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned int V_32 , const unsigned int V_26 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
int V_42 ;
F_22 ( & V_41 -> V_43 ) ;
V_42 = F_18 ( V_2 , V_32 ) ;
if ( V_42 < 0 )
goto exit;
V_42 = F_19 ( V_2 , V_26 ) ;
if ( V_42 < 0 )
goto exit;
exit:
F_23 ( & V_41 -> V_43 ) ;
return V_42 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int V_32 , unsigned int * V_26 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
int V_42 ;
F_22 ( & V_41 -> V_43 ) ;
V_42 = F_18 ( V_2 , V_32 ) ;
if ( V_42 < 0 )
goto exit;
V_42 = F_20 ( V_2 , V_26 ) ;
if ( V_42 < 0 )
goto exit;
exit:
F_23 ( & V_41 -> V_43 ) ;
return V_42 ;
}
static int F_25 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
return F_26 ( V_2 , & V_41 -> V_48 , V_47 ,
V_45 ) ;
}
static int F_27 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
unsigned int V_49 ,
unsigned int V_50 ,
struct V_46 * V_47 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
return F_28 ( V_2 , & V_41 -> V_48 ,
V_49 , V_50 , V_47 ) ;
}
static int F_29 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
return F_30 ( V_2 , & V_41 -> V_48 ) ;
}
static int F_31 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
return F_32 ( V_2 , & V_41 -> V_48 ) ;
}
static int F_33 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
unsigned int V_49 ,
unsigned int V_50 ,
struct V_46 * V_47 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
return F_34 ( V_2 , & V_41 -> V_48 ,
V_49 , V_50 , V_47 ) ;
}
static int F_35 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
return F_36 ( V_2 , & V_41 -> V_48 ) ;
}
static int F_37 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
return F_38 ( V_2 , & V_41 -> V_48 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
struct V_51 * V_52 = V_41 -> V_53 ;
V_2 -> V_54 = V_52 ;
V_2 -> V_55 = 0 ;
V_52 -> V_56 = L_5 ;
V_52 -> V_57 [ V_58 ] = V_59 ;
V_52 -> V_57 [ V_58 ] . V_13 = V_41 -> V_60 [ 0 ] ;
V_52 -> V_57 [ V_58 ] . V_61 =
V_41 -> V_48 . V_62 ;
V_52 -> V_57 [ V_63 ] = V_64 ;
V_52 -> V_57 [ V_63 ] . V_65 = V_41 -> V_66 ;
V_52 -> V_57 [ V_63 ] . V_13 = V_41 -> V_67 [ 0 ] ;
V_2 -> V_55 ++ ;
if ( ! V_41 -> V_68 && ! V_41 -> V_69 )
return 0 ;
V_52 ++ ;
V_52 -> V_56 = L_6 ;
V_52 -> V_70 = V_71 ;
if ( V_41 -> V_68 ) {
V_52 -> V_57 [ V_58 ] =
V_72 ;
V_52 -> V_57 [ V_58 ] . V_13 = V_41 -> V_68 ;
}
if ( V_41 -> V_69 ) {
V_52 -> V_57 [ V_63 ] =
V_73 ;
V_52 -> V_57 [ V_63 ] . V_13 = V_41 -> V_69 ;
}
V_2 -> V_55 ++ ;
return 0 ;
}
static int F_40 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_40 * V_41 = V_2 -> V_41 ;
long * V_78 = V_77 -> V_79 . integer . V_79 ;
* V_78 = V_41 -> V_80 ;
return 0 ;
}
static int F_42 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_40 * V_41 = V_2 -> V_41 ;
long * V_78 = V_77 -> V_79 . integer . V_79 ;
unsigned int V_26 ;
int V_42 ;
if ( V_41 -> V_80 == * V_78 )
return 0 ;
F_43 ( V_2 ) ;
V_42 = F_24 ( V_2 , V_81 , & V_26 ) ;
if ( V_42 < 0 )
goto exit;
V_26 = ( V_26 & 0x7f ) | ( * V_78 ? 0 : 0x80 ) ;
V_42 = F_21 ( V_2 , V_81 , V_26 ) ;
if ( V_42 < 0 )
goto exit;
V_41 -> V_80 = * V_78 ;
exit:
F_44 ( V_2 ) ;
return V_42 < 0 ? V_42 : 1 ;
}
static int F_45 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_40 * V_41 = V_2 -> V_41 ;
long * V_78 = V_77 -> V_79 . integer . V_79 ;
* V_78 = V_41 -> V_82 ;
return 0 ;
}
static int F_46 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_40 * V_41 = V_2 -> V_41 ;
long * V_78 = V_77 -> V_79 . integer . V_79 ;
unsigned int V_26 ;
int V_42 ;
if ( V_41 -> V_82 == * V_78 )
return 0 ;
F_43 ( V_2 ) ;
V_42 = F_24 ( V_2 , V_81 , & V_26 ) ;
if ( V_42 < 0 )
goto exit;
V_26 = ( V_26 & 0xef ) | ( * V_78 ? 0 : 0x10 ) ;
V_42 = F_21 ( V_2 , V_81 , V_26 ) ;
if ( V_42 < 0 )
goto exit;
V_41 -> V_82 = * V_78 ;
exit:
F_44 ( V_2 ) ;
return V_42 < 0 ? V_42 : 1 ;
}
static int F_47 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_40 * V_41 = V_2 -> V_41 ;
long * V_78 = V_77 -> V_79 . integer . V_79 ;
* V_78 ++ = V_41 -> V_83 [ 0 ] ;
* V_78 = V_41 -> V_83 [ 1 ] ;
return 0 ;
}
static int F_48 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_41 ( V_75 ) ;
struct V_40 * V_41 = V_2 -> V_41 ;
long * V_78 = V_77 -> V_79 . integer . V_79 ;
long V_84 , V_85 ;
unsigned int V_26 ;
int V_86 ;
int V_42 ;
V_84 = * V_78 ++ ;
V_85 = * V_78 ;
if ( ( V_41 -> V_83 [ 0 ] == V_84 ) &&
( V_41 -> V_83 [ 1 ] == V_85 ) )
return 0 ;
F_43 ( V_2 ) ;
V_42 = F_24 ( V_2 , V_87 , & V_26 ) ;
if ( V_42 < 0 )
goto exit;
V_86 = 31 - V_84 ;
V_26 = ( V_26 & 0xe0 ) | V_86 ;
V_42 = F_21 ( V_2 , V_87 , V_26 ) ;
if ( V_42 < 0 )
goto exit;
V_86 = 31 - V_85 ;
V_26 = ( V_26 & 0xe0 ) | V_86 ;
V_42 = F_21 ( V_2 , V_88 , V_26 ) ;
if ( V_42 < 0 )
goto exit;
V_41 -> V_83 [ 0 ] = V_84 ;
V_41 -> V_83 [ 1 ] = V_85 ;
exit:
F_44 ( V_2 ) ;
return V_42 < 0 ? V_42 : 1 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_20 V_21 =
F_9 ( L_7 ,
V_13 , 1 , 0 , V_19 ) ;
V_21 . V_89 = F_40 ;
V_21 . V_90 = F_42 ;
return F_12 ( V_2 , V_13 , F_13 ( & V_21 , V_2 ) ) ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_20 V_21 =
F_15 ( L_8 ,
V_13 , 3 , 0 , V_19 ) ;
V_21 . V_89 = F_47 ;
V_21 . V_90 = F_48 ;
return F_12 ( V_2 , V_13 , F_13 ( & V_21 , V_2 ) ) ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_20 V_21 =
F_9 ( L_9 ,
V_13 , 1 , 0 , V_19 ) ;
V_21 . V_89 = F_45 ;
V_21 . V_90 = F_46 ;
return F_12 ( V_2 , V_13 , F_13 ( & V_21 , V_2 ) ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
struct V_91 * V_92 = & V_41 -> V_93 ;
unsigned int V_94 ;
V_94 = 0x80031f06 ;
F_53 ( V_2 , V_92 -> V_95 [ 0 ] , V_19 , V_94 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
struct V_91 * V_92 = & V_41 -> V_93 ;
int V_96 , V_42 ;
if ( V_41 -> V_48 . V_97 ) {
V_42 = F_51 ( V_2 , V_41 -> V_98 [ 0 ] ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_92 -> V_99 ) {
F_52 ( V_2 ) ;
V_42 = F_49 ( V_2 , V_92 -> V_95 [ 0 ] ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_50 ( V_2 , V_92 -> V_95 [ 0 ] ) ;
if ( V_42 < 0 )
return V_42 ;
}
for ( V_96 = 0 ; V_96 < V_41 -> V_66 ; V_96 ++ ) {
const char * V_100 = V_41 -> V_101 [ V_96 ] ;
V_42 = F_55 ( V_2 , V_41 -> V_67 [ V_96 ] , V_100 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_56 ( V_2 , V_41 -> V_67 [ V_96 ] , V_100 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_92 -> V_102 [ V_96 ] . type == V_103 ) {
V_42 = F_57 ( V_2 , V_41 -> V_104 [ V_96 ] ,
L_10 , 1 ) ;
if ( V_42 < 0 )
return V_42 ;
}
}
if ( V_41 -> V_68 ) {
V_42 = F_58 ( V_2 , V_41 -> V_68 ,
V_41 -> V_68 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_59 ( V_2 , & V_41 -> V_48 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_41 -> V_69 ) {
V_42 = F_60 ( V_2 , V_41 -> V_69 ) ;
if ( V_42 < 0 )
return V_42 ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , int V_105 )
{
F_11 ( L_11 ) ;
F_4 ( V_2 , V_29 , 0 ,
V_106 ,
V_105 ) ;
F_62 ( 20 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
struct V_91 * V_92 = & V_41 -> V_93 ;
V_2 -> V_107 = 1 ;
V_2 -> V_108 = 1 ;
V_92 -> V_109 = 1 ;
V_92 -> V_110 [ 0 ] = 0x0b ;
V_92 -> V_111 = V_112 ;
V_41 -> V_60 [ 0 ] = 0x02 ;
V_41 -> V_98 [ 0 ] = 0x0b ;
V_41 -> V_48 . V_113 = V_41 -> V_60 ;
V_41 -> V_48 . V_97 = 1 ;
V_41 -> V_48 . V_62 = 2 ;
V_92 -> V_99 = 1 ;
V_92 -> V_95 [ 0 ] = 0x0f ;
V_41 -> V_114 = 0 ;
V_41 -> V_48 . V_115 = 0 ;
V_92 -> V_66 = 2 ;
V_92 -> V_102 [ 0 ] . V_3 = 0x12 ;
V_92 -> V_102 [ 0 ] . type = V_103 ;
V_92 -> V_102 [ 1 ] . V_3 = 0x11 ;
V_92 -> V_102 [ 1 ] . type = V_116 ;
V_41 -> V_104 [ 0 ] = 0x12 ;
V_41 -> V_101 [ 0 ] = L_12 ;
V_41 -> V_67 [ 0 ] = 0x07 ;
V_41 -> V_104 [ 1 ] = 0x11 ;
V_41 -> V_101 [ 1 ] = L_13 ;
V_41 -> V_67 [ 1 ] = 0x08 ;
V_41 -> V_66 = 2 ;
V_41 -> V_68 = 0x05 ;
V_41 -> V_48 . V_117 = V_41 -> V_68 ;
V_92 -> V_118 [ 0 ] = 0x0c ;
V_92 -> V_119 = 1 ;
V_92 -> V_120 [ 0 ] = V_71 ;
V_41 -> V_69 = 0x09 ;
V_92 -> V_121 = 0x0e ;
V_92 -> V_122 = V_71 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
F_65 ( & V_41 -> V_43 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = V_2 -> V_41 ;
struct V_91 * V_92 = & V_41 -> V_93 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_41 -> V_48 . V_97 ; V_96 ++ ) {
F_1 ( V_2 , V_41 -> V_98 [ V_96 ] ,
V_41 -> V_48 . V_113 [ V_96 ] ) ;
}
F_1 ( V_2 , V_92 -> V_95 [ 0 ] , V_41 -> V_114 ) ;
F_1 ( V_2 , V_92 -> V_118 [ 0 ] , V_41 -> V_68 ) ;
for ( V_96 = 0 ; V_96 < V_41 -> V_66 ; V_96 ++ )
F_5 ( V_2 , V_41 -> V_104 [ V_96 ] , V_41 -> V_67 [ V_96 ] ) ;
F_5 ( V_2 , V_92 -> V_121 , V_41 -> V_69 ) ;
F_61 ( V_2 , 1 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_61 ( V_2 , 0 ) ;
F_66 ( V_2 ) ;
F_69 ( V_2 -> V_41 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_40 * V_41 ;
F_11 ( L_14 ) ;
V_41 = F_71 ( sizeof( * V_41 ) , V_123 ) ;
if ( ! V_41 )
return - V_124 ;
V_2 -> V_41 = V_41 ;
F_64 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_125 = V_126 ;
return 0 ;
}
static int T_2 F_72 ( void )
{
return F_73 ( & V_127 ) ;
}
static void T_3 F_74 ( void )
{
F_75 ( & V_127 ) ;
}
