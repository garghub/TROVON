static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_3 ) {
F_2 ( V_2 , V_3 , 0 ,
V_5 , V_6 ) ;
if ( F_3 ( V_2 , V_3 ) & V_7 )
F_2 ( V_2 , V_3 , 0 ,
V_8 ,
V_9 ) ;
}
if ( V_4 )
F_2 ( V_2 , V_4 , 0 ,
V_8 , V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
if ( V_3 ) {
F_2 ( V_2 , V_3 , 0 ,
V_5 ,
V_12 ) ;
if ( F_3 ( V_2 , V_3 ) & V_13 )
F_2 ( V_2 , V_3 , 0 ,
V_8 ,
F_5 ( 0 ) ) ;
}
if ( V_11 )
F_2 ( V_2 , V_11 , 0 , V_8 ,
F_5 ( 0 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_14 , const char * V_15 ,
int V_16 , int V_17 )
{
char V_18 [ 44 ] ;
int type = V_17 ? V_19 : V_20 ;
struct V_21 V_22 =
F_7 ( V_18 , V_14 , V_16 , 0 , type ) ;
sprintf ( V_18 , L_1 , V_15 , V_23 [ V_17 ] ) ;
return F_8 ( V_2 , V_14 , F_9 ( & V_22 , V_2 ) ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_14 , const char * V_15 ,
int V_16 , int V_17 )
{
char V_18 [ 44 ] ;
int type = V_17 ? V_19 : V_20 ;
struct V_21 V_22 =
F_11 ( V_18 , V_14 , V_16 , 0 , type ) ;
sprintf ( V_18 , L_2 , V_15 , V_23 [ V_17 ] ) ;
return F_8 ( V_2 , V_14 , F_9 ( & V_22 , V_2 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_24 ,
unsigned int V_25 )
{
unsigned int V_26 ;
int V_27 = 50 ;
do {
V_26 = F_13 ( V_2 , V_28 , 0 ,
V_24 , V_25 ) ;
if ( V_26 == V_29 )
return 0 ;
} while ( -- V_27 );
return - V_30 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_31 )
{
int V_26 ;
V_26 = F_12 ( V_2 , V_32 ,
V_31 & 0xffff ) ;
if ( V_26 != - V_30 ) {
V_26 = F_12 ( V_2 , V_33 ,
V_31 >> 16 ) ;
}
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_25 )
{
int V_26 ;
V_26 = F_12 ( V_2 , V_34 , V_25 & 0xffff ) ;
if ( V_26 != - V_30 ) {
V_26 = F_12 ( V_2 , V_35 ,
V_25 >> 16 ) ;
}
return V_26 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int * V_25 )
{
int V_26 ;
V_26 = F_12 ( V_2 , V_36 , 0 ) ;
if ( V_26 != - V_30 ) {
V_26 = F_12 ( V_2 , V_37 , 0 ) ;
}
if ( V_26 != - V_30 ) {
* V_25 = F_13 ( V_2 , V_28 , 0 ,
V_38 ,
0 ) ;
}
return V_26 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_31 , const unsigned int V_25 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
int V_41 ;
F_18 ( & V_40 -> V_42 ) ;
V_41 = F_14 ( V_2 , V_31 ) ;
if ( V_41 < 0 )
goto exit;
V_41 = F_15 ( V_2 , V_25 ) ;
if ( V_41 < 0 )
goto exit;
exit:
F_19 ( & V_40 -> V_42 ) ;
return V_41 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned int V_31 , unsigned int * V_25 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
int V_41 ;
F_18 ( & V_40 -> V_42 ) ;
V_41 = F_14 ( V_2 , V_31 ) ;
if ( V_41 < 0 )
goto exit;
V_41 = F_16 ( V_2 , V_25 ) ;
if ( V_41 < 0 )
goto exit;
exit:
F_19 ( & V_40 -> V_42 ) ;
return V_41 ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_14 ,
T_2 V_43 ,
int V_44 , int V_45 )
{
unsigned int V_46 , V_47 ;
if ( ! V_14 )
return;
F_22 ( L_3
L_4 ,
V_14 , V_43 , V_44 , V_45 ) ;
V_46 = F_13 ( V_2 , V_14 , 0 ,
V_48 ,
0 ) ;
if ( V_46 != V_45 ) {
F_23 ( 20 ) ;
F_2 ( V_2 , V_14 , 0 ,
V_49 ,
V_45 ) ;
}
V_46 = F_13 ( V_2 , V_14 , 0 , V_50 , 0 ) ;
V_47 = ( V_43 << 4 ) | V_44 ;
if ( V_46 != V_47 ) {
F_2 ( V_2 , V_14 , 0 ,
V_51 ,
V_47 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , T_1 V_14 )
{
F_2 ( V_2 , V_14 , 0 , V_49 , 0 ) ;
F_2 ( V_2 , V_14 , 0 , V_51 , 0 ) ;
}
static int F_25 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
unsigned int V_43 ,
unsigned int V_45 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_21 ( V_2 , V_40 -> V_56 [ 0 ] , V_43 , 0 , V_45 ) ;
return 0 ;
}
static int F_26 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_24 ( V_2 , V_40 -> V_56 [ 0 ] ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
unsigned int V_43 ,
unsigned int V_45 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_21 ( V_2 , V_40 -> V_57 , V_43 , 0 , V_45 ) ;
return 0 ;
}
static int F_28 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_24 ( V_2 , V_40 -> V_57 ) ;
return 0 ;
}
static int F_29 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
unsigned int V_43 ,
unsigned int V_45 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_21 ( V_2 , V_40 -> V_58 [ V_55 -> V_59 ] ,
V_43 , 0 , V_45 ) ;
return 0 ;
}
static int F_30 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_24 ( V_2 , V_40 -> V_58 [ V_55 -> V_59 ] ) ;
return 0 ;
}
static int F_31 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
unsigned int V_43 ,
unsigned int V_45 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_21 ( V_2 , V_40 -> V_60 , V_43 , 0 , V_45 ) ;
return 0 ;
}
static int F_32 ( struct V_52 * V_53 ,
struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_24 ( V_2 , V_40 -> V_60 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_61 * V_62 = V_40 -> V_63 ;
V_2 -> V_64 = V_62 ;
V_2 -> V_65 = 0 ;
V_62 -> V_66 = L_5 ;
V_62 -> V_67 [ V_68 ] = V_69 ;
V_62 -> V_67 [ V_68 ] . V_14 = V_40 -> V_56 [ 0 ] ;
V_62 -> V_67 [ V_68 ] . V_70 =
V_40 -> V_71 . V_72 ;
V_62 -> V_67 [ V_73 ] = V_74 ;
V_62 -> V_67 [ V_73 ] . V_75 = V_40 -> V_76 ;
V_62 -> V_67 [ V_73 ] . V_14 = V_40 -> V_58 [ 0 ] ;
V_2 -> V_65 ++ ;
if ( ! V_40 -> V_57 && ! V_40 -> V_60 )
return 0 ;
V_62 ++ ;
V_62 -> V_66 = L_6 ;
V_62 -> V_77 = V_78 ;
if ( V_40 -> V_57 ) {
V_62 -> V_67 [ V_68 ] =
V_79 ;
V_62 -> V_67 [ V_68 ] . V_14 = V_40 -> V_57 ;
}
if ( V_40 -> V_60 ) {
V_62 -> V_67 [ V_73 ] =
V_80 ;
V_62 -> V_67 [ V_73 ] . V_14 = V_40 -> V_60 ;
}
V_2 -> V_65 ++ ;
return 0 ;
}
static int F_34 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_35 ( V_82 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
long * V_85 = V_84 -> V_86 . integer . V_86 ;
* V_85 = V_40 -> V_87 ;
return 0 ;
}
static int F_36 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_35 ( V_82 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
long * V_85 = V_84 -> V_86 . integer . V_86 ;
unsigned int V_25 ;
int V_41 ;
if ( V_40 -> V_87 == * V_85 )
return 0 ;
F_37 ( V_2 ) ;
V_41 = F_20 ( V_2 , V_88 , & V_25 ) ;
if ( V_41 < 0 )
goto exit;
V_25 = ( V_25 & 0x7f ) | ( * V_85 ? 0 : 0x80 ) ;
V_41 = F_17 ( V_2 , V_88 , V_25 ) ;
if ( V_41 < 0 )
goto exit;
V_40 -> V_87 = * V_85 ;
exit:
F_38 ( V_2 ) ;
return V_41 < 0 ? V_41 : 1 ;
}
static int F_39 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_35 ( V_82 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
long * V_85 = V_84 -> V_86 . integer . V_86 ;
* V_85 = V_40 -> V_89 ;
return 0 ;
}
static int F_40 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_35 ( V_82 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
long * V_85 = V_84 -> V_86 . integer . V_86 ;
unsigned int V_25 ;
int V_41 ;
if ( V_40 -> V_89 == * V_85 )
return 0 ;
F_37 ( V_2 ) ;
V_41 = F_20 ( V_2 , V_88 , & V_25 ) ;
if ( V_41 < 0 )
goto exit;
V_25 = ( V_25 & 0xef ) | ( * V_85 ? 0 : 0x10 ) ;
V_41 = F_17 ( V_2 , V_88 , V_25 ) ;
if ( V_41 < 0 )
goto exit;
V_40 -> V_89 = * V_85 ;
exit:
F_38 ( V_2 ) ;
return V_41 < 0 ? V_41 : 1 ;
}
static int F_41 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_35 ( V_82 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
long * V_85 = V_84 -> V_86 . integer . V_86 ;
* V_85 ++ = V_40 -> V_90 [ 0 ] ;
* V_85 = V_40 -> V_90 [ 1 ] ;
return 0 ;
}
static int F_42 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_35 ( V_82 ) ;
struct V_39 * V_40 = V_2 -> V_40 ;
long * V_85 = V_84 -> V_86 . integer . V_86 ;
long V_91 , V_92 ;
unsigned int V_25 ;
int V_93 ;
int V_41 ;
V_91 = * V_85 ++ ;
V_92 = * V_85 ;
if ( ( V_40 -> V_90 [ 0 ] == V_91 ) &&
( V_40 -> V_90 [ 1 ] == V_92 ) )
return 0 ;
F_37 ( V_2 ) ;
V_41 = F_20 ( V_2 , V_94 , & V_25 ) ;
if ( V_41 < 0 )
goto exit;
V_93 = 31 - V_91 ;
V_25 = ( V_25 & 0xe0 ) | V_93 ;
V_41 = F_17 ( V_2 , V_94 , V_25 ) ;
if ( V_41 < 0 )
goto exit;
V_93 = 31 - V_92 ;
V_25 = ( V_25 & 0xe0 ) | V_93 ;
V_41 = F_17 ( V_2 , V_95 , V_25 ) ;
if ( V_41 < 0 )
goto exit;
V_40 -> V_90 [ 0 ] = V_91 ;
V_40 -> V_90 [ 1 ] = V_92 ;
exit:
F_38 ( V_2 ) ;
return V_41 < 0 ? V_41 : 1 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_21 V_22 =
F_7 ( L_7 ,
V_14 , 1 , 0 , V_20 ) ;
V_22 . V_96 = F_34 ;
V_22 . V_97 = F_36 ;
return F_8 ( V_2 , V_14 , F_9 ( & V_22 , V_2 ) ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_21 V_22 =
F_11 ( L_8 ,
V_14 , 3 , 0 , V_20 ) ;
V_22 . V_96 = F_41 ;
V_22 . V_97 = F_42 ;
return F_8 ( V_2 , V_14 , F_9 ( & V_22 , V_2 ) ) ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_21 V_22 =
F_7 ( L_9 ,
V_14 , 1 , 0 , V_20 ) ;
V_22 . V_96 = F_39 ;
V_22 . V_97 = F_40 ;
return F_8 ( V_2 , V_14 , F_9 ( & V_22 , V_2 ) ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_98 * V_99 = & V_40 -> V_100 ;
unsigned int V_101 ;
V_101 = 0x80031f06 ;
F_47 ( V_2 , V_99 -> V_102 [ 0 ] , V_20 , V_101 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_98 * V_99 = & V_40 -> V_100 ;
int V_103 , V_41 ;
if ( V_40 -> V_71 . V_104 ) {
V_41 = F_45 ( V_2 , V_40 -> V_105 [ 0 ] ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_99 -> V_106 ) {
F_46 ( V_2 ) ;
V_41 = F_43 ( V_2 , V_99 -> V_102 [ 0 ] ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_44 ( V_2 , V_99 -> V_102 [ 0 ] ) ;
if ( V_41 < 0 )
return V_41 ;
}
for ( V_103 = 0 ; V_103 < V_40 -> V_76 ; V_103 ++ ) {
const char * V_107 = V_40 -> V_108 [ V_103 ] ;
V_41 = F_49 ( V_2 , V_40 -> V_58 [ V_103 ] , V_107 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_50 ( V_2 , V_40 -> V_58 [ V_103 ] , V_107 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_99 -> V_109 [ V_103 ] . type == V_110 ) {
V_41 = F_51 ( V_2 , V_40 -> V_111 [ V_103 ] ,
L_10 , 1 ) ;
if ( V_41 < 0 )
return V_41 ;
}
}
if ( V_40 -> V_57 ) {
V_41 = F_52 ( V_2 , V_40 -> V_57 ,
V_40 -> V_57 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_53 ( V_2 , V_40 -> V_57 , L_11 ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_40 -> V_60 ) {
V_41 = F_54 ( V_2 , V_40 -> V_60 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_50 ( V_2 , V_40 -> V_60 , L_11 ) ;
if ( V_41 < 0 )
return V_41 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , int V_112 )
{
F_22 ( L_12 ) ;
F_2 ( V_2 , V_28 , 0 ,
V_113 ,
V_112 ) ;
F_23 ( 20 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_98 * V_99 = & V_40 -> V_100 ;
V_99 -> V_114 = 1 ;
V_99 -> V_115 [ 0 ] = 0x0b ;
V_99 -> V_116 = V_117 ;
V_40 -> V_56 [ 0 ] = 0x02 ;
V_40 -> V_105 [ 0 ] = 0x0b ;
V_40 -> V_71 . V_118 = V_40 -> V_56 ;
V_40 -> V_71 . V_104 = 1 ;
V_40 -> V_71 . V_72 = 2 ;
V_99 -> V_106 = 1 ;
V_99 -> V_102 [ 0 ] = 0x0f ;
V_40 -> V_119 = 0 ;
V_40 -> V_71 . V_120 = 0 ;
V_99 -> V_76 = 2 ;
V_99 -> V_109 [ 0 ] . V_3 = 0x12 ;
V_99 -> V_109 [ 0 ] . type = V_110 ;
V_99 -> V_109 [ 1 ] . V_3 = 0x11 ;
V_99 -> V_109 [ 1 ] . type = V_121 ;
V_40 -> V_111 [ 0 ] = 0x12 ;
V_40 -> V_108 [ 0 ] = L_13 ;
V_40 -> V_58 [ 0 ] = 0x07 ;
V_40 -> V_111 [ 1 ] = 0x11 ;
V_40 -> V_108 [ 1 ] = L_14 ;
V_40 -> V_58 [ 1 ] = 0x08 ;
V_40 -> V_76 = 2 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
F_58 ( & V_40 -> V_42 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_98 * V_99 = & V_40 -> V_100 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_40 -> V_71 . V_104 ; V_103 ++ ) {
F_1 ( V_2 , V_40 -> V_105 [ V_103 ] ,
V_40 -> V_71 . V_118 [ V_103 ] ) ;
}
F_1 ( V_2 , V_99 -> V_102 [ 0 ] , V_40 -> V_119 ) ;
F_1 ( V_2 , V_99 -> V_122 [ 0 ] , V_40 -> V_57 ) ;
for ( V_103 = 0 ; V_103 < V_40 -> V_76 ; V_103 ++ )
F_4 ( V_2 , V_40 -> V_111 [ V_103 ] , V_40 -> V_58 [ V_103 ] ) ;
F_4 ( V_2 , V_99 -> V_123 , V_40 -> V_60 ) ;
F_55 ( V_2 , 1 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_55 ( V_2 , 0 ) ;
F_59 ( V_2 ) ;
F_62 ( V_2 -> V_40 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
F_22 ( L_15 ) ;
V_40 = F_64 ( sizeof( * V_40 ) , V_124 ) ;
if ( ! V_40 )
return - V_125 ;
V_2 -> V_40 = V_40 ;
F_57 ( V_2 ) ;
F_56 ( V_2 ) ;
V_2 -> V_126 = V_127 ;
return 0 ;
}
static int T_3 F_65 ( void )
{
return F_66 ( & V_128 ) ;
}
static void T_4 F_67 ( void )
{
F_68 ( & V_128 ) ;
}
