static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 V_7 ;
union V_8 V_9 ;
T_2 V_10 ;
V_7 . V_11 = 1 ;
V_7 . V_12 = & V_9 ;
V_9 . type = V_13 ;
V_9 . integer . V_14 = V_3 ;
V_10 = F_2 ( V_1 , ( char * ) V_2 , & V_7 , V_5 ) ;
return ( V_10 == V_15 ) ;
}
static int F_3 ( T_1 V_1 , const char * V_2 , int * V_3 )
{
struct V_4 V_5 ;
union V_8 V_16 ;
T_2 V_10 ;
V_5 . V_17 = sizeof( V_16 ) ;
V_5 . V_12 = & V_16 ;
V_10 = F_2 ( V_1 , ( char * ) V_2 , NULL , & V_5 ) ;
* V_3 = V_16 . integer . V_14 ;
return ( V_10 == V_15 ) && ( V_16 . type == V_13 ) ;
}
static int F_4 ( struct V_18 * V_19 , void * V_20 )
{
int V_21 ;
F_5 ( V_19 , V_22 L_1 V_23 L_2 ) ;
F_5 ( V_19 , L_3 , V_24 -> V_25 -> V_26 ) ;
if ( F_3 ( V_24 -> V_1 , L_4 , & V_21 ) )
F_5 ( V_19 , L_5 , V_21 ) ;
if ( F_3 ( V_24 -> V_1 , L_6 , & V_21 ) )
F_5 ( V_19 , L_7 , V_21 ) ;
if ( V_27 ) {
F_5 ( V_19 , L_8 , V_27 -> V_17 ) ;
F_5 ( V_19 , L_9 , V_27 -> V_28 ) ;
F_5 ( V_19 , L_10 , V_27 -> V_29 ) ;
F_5 ( V_19 , L_11 , V_30 , V_27 -> V_31 ) ;
F_5 ( V_19 , L_12 , V_32 , V_27 -> V_33 ) ;
F_5 ( V_19 , L_13 , V_27 -> V_34 ) ;
F_5 ( V_19 , L_14 , V_35 , V_27 -> V_36 ) ;
F_5 ( V_19 , L_15 , V_27 -> V_37 ) ;
}
return 0 ;
}
static int F_6 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_4 , NULL ) ;
}
static int F_8 ( const char * V_40 , int V_41 )
{
if ( V_40 ) {
int V_42 ;
if ( F_3 ( NULL , V_40 , & V_42 ) )
return V_42 ;
else
F_9 ( L_16 ) ;
}
return ( V_24 -> V_10 & V_41 ) ? 1 : 0 ;
}
static int F_10 ( const char T_3 * V_43 , unsigned long V_11 , int * V_3 )
{
char V_44 [ 32 ] ;
if ( ! V_11 )
return 0 ;
if ( V_11 > 31 )
return - V_45 ;
if ( F_11 ( V_44 , V_43 , V_11 ) )
return - V_46 ;
V_44 [ V_11 ] = 0 ;
if ( sscanf ( V_44 , L_17 , V_3 ) != 1 )
return - V_45 ;
return V_11 ;
}
static int
F_12 ( const char T_3 * V_47 , unsigned long V_11 ,
char * V_40 , int V_41 , int V_48 )
{
int V_49 , V_14 ;
int V_50 = 0 ;
V_49 = F_10 ( V_47 , V_11 , & V_14 ) ;
if ( V_49 > 0 )
V_50 = V_14 ? 1 : 0 ;
V_24 -> V_10 =
( V_50 ) ? ( V_24 -> V_10 | V_41 ) : ( V_24 -> V_10 & ~ V_41 ) ;
if ( V_48 )
V_50 = ! V_50 ;
if ( ! F_1 ( V_24 -> V_1 , V_40 , V_50 , NULL ) )
F_9 ( L_18 , V_40 ) ;
return V_49 ;
}
static int F_13 ( struct V_18 * V_19 , void * V_20 )
{
F_5 ( V_19 , L_19 , F_8 ( V_24 -> V_25 -> V_51 , V_52 ) ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_13 , NULL ) ;
}
static T_4 F_15 ( struct V_39 * V_39 , const char T_3 * V_47 ,
T_5 V_11 , T_6 * V_53 )
{
return F_12 ( V_47 , V_11 , V_24 -> V_25 -> V_54 , V_52 , 1 ) ;
}
static int F_16 ( struct V_18 * V_19 , void * V_20 )
{
F_5 ( V_19 , L_20 , V_24 -> V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_16 , NULL ) ;
}
static T_4 F_18 ( struct V_39 * V_39 , const char T_3 * V_47 ,
T_5 V_11 , T_6 * V_53 )
{
int V_49 , V_14 ;
V_49 = F_10 ( V_47 , V_11 , & V_14 ) ;
if ( V_49 > 0 ) {
if ( ! F_1
( V_24 -> V_1 , V_24 -> V_25 -> V_56 , V_14 , NULL ) )
F_9 ( L_21 ) ;
else
V_24 -> V_55 = ( V_57 ) V_14 ;
}
return V_49 ;
}
static int F_19 ( struct V_18 * V_19 , void * V_20 )
{
F_5 ( V_19 , L_19 , F_8 ( V_24 -> V_25 -> V_58 , V_59 ) ) ;
return 0 ;
}
static int F_20 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_19 , NULL ) ;
}
static T_4 F_21 ( struct V_39 * V_39 , const char T_3 * V_47 ,
T_5 V_11 , T_6 * V_53 )
{
return F_12 ( V_47 , V_11 , V_24 -> V_25 -> V_60 , V_59 , 0 ) ;
}
static int F_22 ( struct V_18 * V_19 , void * V_20 )
{
F_5 ( V_19 , L_19 , F_8 ( V_24 -> V_25 -> V_61 , V_62 ) ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_22 , NULL ) ;
}
static T_4 F_24 ( struct V_39 * V_39 ,
const char T_3 * V_47 , T_5 V_11 , T_6 * V_53 )
{
return F_12 ( V_47 , V_11 , V_24 -> V_25 -> V_63 , V_62 , 0 ) ;
}
static int F_25 ( struct V_18 * V_19 , void * V_20 )
{
F_5 ( V_19 , L_19 , F_8 ( V_24 -> V_25 -> V_64 , V_65 ) ) ;
return 0 ;
}
static int F_26 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_25 , NULL ) ;
}
static T_4 F_27 ( struct V_39 * V_39 , const char T_3 * V_47 ,
T_5 V_11 , T_6 * V_53 )
{
return F_12 ( V_47 , V_11 , V_24 -> V_25 -> V_66 , V_65 , 0 ) ;
}
static int F_28 ( void )
{
int V_67 = 0 ;
if ( V_24 -> V_68 == V_69 ) {
T_2 V_10 = 0 ;
struct V_6 V_70 ;
union V_8 V_71 [ 2 ] ;
struct V_4 V_5 ;
union V_8 V_16 ;
V_70 . V_11 = 2 ;
V_70 . V_12 = V_71 ;
V_71 [ 0 ] . type = V_13 ;
V_71 [ 0 ] . integer . V_14 = 0x02 ;
V_71 [ 1 ] . type = V_13 ;
V_71 [ 1 ] . integer . V_14 = 0x02 ;
V_5 . V_17 = sizeof( V_16 ) ;
V_5 . V_12 = & V_16 ;
V_10 =
F_2 ( NULL , V_24 -> V_25 -> V_72 ,
& V_70 , & V_5 ) ;
if ( V_10 != V_15 )
return - 1 ;
if ( V_16 . type == V_13 )
V_67 = V_16 . integer . V_14 >> 8 ;
} else if ( V_24 -> V_68 == V_73 ) {
unsigned long long V_74 ;
union V_8 V_75 ;
struct V_6 V_70 ;
T_2 V_10 ;
V_75 . type = V_13 ;
V_75 . integer . V_14 = 0x11 ;
V_70 . V_11 = 1 ;
V_70 . V_12 = & V_75 ;
V_10 = F_29 ( NULL , V_24 -> V_25 -> V_72 ,
& V_70 , & V_74 ) ;
if ( V_10 != V_15 )
return - 1 ;
V_67 = V_74 ;
} else {
if ( ! F_3 ( NULL , V_24 -> V_25 -> V_72 , & V_67 ) )
F_9 ( L_22 ) ;
if ( V_24 -> V_68 == V_76 )
V_67 = ~ V_67 ;
}
return ( V_67 & 1 ) ;
}
static int F_30 ( int V_14 )
{
int V_67 = 0 ;
T_2 V_10 = 0 ;
V_67 = V_14 ? 1 : 0 ;
if ( V_67 != F_28 () ) {
if ( V_24 -> V_68 != V_69 ) {
V_10 =
F_2 ( NULL ,
V_24 -> V_25 -> V_77 ,
NULL , NULL ) ;
} else {
if ( ! F_1
( V_24 -> V_1 , V_24 -> V_25 -> V_77 , 0x07 ,
NULL ) )
V_10 = V_78 ;
}
if ( F_31 ( V_10 ) )
F_9 ( L_23 ) ;
}
return 0 ;
}
static int F_32 ( struct V_18 * V_19 , void * V_20 )
{
F_5 ( V_19 , L_19 , F_28 () ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_32 , NULL ) ;
}
static T_4 F_34 ( struct V_39 * V_39 , const char T_3 * V_47 ,
T_5 V_11 , T_6 * V_53 )
{
int V_49 , V_14 ;
V_49 = F_10 ( V_47 , V_11 , & V_14 ) ;
if ( V_49 > 0 )
F_30 ( V_14 ) ;
return V_49 ;
}
static int F_35 ( struct V_79 * V_80 )
{
int V_14 ;
if ( V_24 -> V_25 -> V_81 ) {
if ( ! F_3 ( V_24 -> V_1 , V_24 -> V_25 -> V_81 ,
& V_14 ) )
F_9 ( L_24 ) ;
} else if ( V_24 -> V_25 -> V_82 ) {
if ( ! F_3 ( NULL , V_24 -> V_25 -> V_82 ,
& V_14 ) )
F_9 ( L_24 ) ;
} else
V_14 = V_24 -> V_83 ;
return V_14 ;
}
static int F_36 ( int V_14 )
{
T_2 V_10 = 0 ;
int V_84 = 0 ;
if ( V_24 -> V_25 -> V_85 ) {
if ( ! F_1 ( V_24 -> V_1 , V_24 -> V_25 -> V_85 ,
V_14 , NULL ) ) {
F_9 ( L_25 ) ;
V_84 = - V_86 ;
}
goto V_87;
}
V_14 -= F_35 ( NULL ) ;
while ( V_14 != 0 ) {
V_10 = F_2 ( NULL , ( V_14 > 0 ) ?
V_24 -> V_25 -> V_88 :
V_24 -> V_25 -> V_89 ,
NULL , NULL ) ;
( V_14 > 0 ) ? V_14 -- : V_14 ++ ;
if ( F_31 ( V_10 ) ) {
F_9 ( L_25 ) ;
V_84 = - V_86 ;
}
}
V_87:
return V_84 ;
}
static int F_37 ( struct V_79 * V_80 )
{
return F_36 ( V_80 -> V_90 . V_83 ) ;
}
static int F_38 ( struct V_18 * V_19 , void * V_20 )
{
F_5 ( V_19 , L_19 , F_35 ( NULL ) ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_38 , NULL ) ;
}
static T_4 F_40 ( struct V_39 * V_39 , const char T_3 * V_47 ,
T_5 V_11 , T_6 * V_53 )
{
int V_49 , V_14 ;
V_49 = F_10 ( V_47 , V_11 , & V_14 ) ;
if ( V_49 > 0 ) {
V_14 = ( 0 < V_14 ) ? ( ( 15 < V_14 ) ? 15 : V_14 ) : 0 ;
F_36 ( V_14 ) ;
}
return V_49 ;
}
static void F_41 ( int V_14 )
{
if ( ! F_1 ( V_24 -> V_1 , V_24 -> V_25 -> V_91 ,
V_14 , NULL ) )
F_9 ( L_26 ) ;
return;
}
static int F_42 ( struct V_18 * V_19 , void * V_20 )
{
int V_14 = 0 ;
if ( ! F_3 ( V_24 -> V_1 , V_24 -> V_25 -> V_92 , & V_14 ) )
F_9 ( L_27 ) ;
V_14 &= 0x07 ;
F_5 ( V_19 , L_19 , V_14 ) ;
return 0 ;
}
static int F_43 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_7 ( V_39 , F_42 , NULL ) ;
}
static T_4 F_44 ( struct V_39 * V_39 , const char T_3 * V_47 ,
T_5 V_11 , T_6 * V_53 )
{
int V_49 , V_14 ;
V_49 = F_10 ( V_47 , V_11 , & V_14 ) ;
if ( V_49 > 0 )
F_41 ( V_14 ) ;
return V_49 ;
}
static int
F_45 ( char * V_26 , const struct V_93 * V_94 , T_7 V_95 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 ;
V_99 = F_46 ( V_26 , V_95 , F_47 ( V_97 ) ,
V_94 , F_48 ( V_97 ) ) ;
if ( ! V_99 ) {
F_9 ( L_28 , V_26 ) ;
return - 1 ;
}
V_99 -> V_100 = V_101 ;
V_99 -> V_102 = V_103 ;
return 0 ;
}
static int F_49 ( struct V_96 * V_97 )
{
struct V_98 * V_99 ;
T_7 V_95 ;
if ( ( V_101 == 0 ) && ( V_103 == 0 ) ) {
V_95 = V_104 | V_105 | V_106 | V_107 ;
} else {
V_95 = V_104 | V_108 | V_109 | V_106 | V_107 ;
F_9 ( L_29
L_30 ) ;
}
F_47 ( V_97 ) = V_110 ;
if ( ! F_47 ( V_97 ) )
return - V_111 ;
V_99 = F_50 ( V_112 , V_95 , F_47 ( V_97 ) ,
& V_113 ) ;
if ( V_99 ) {
V_99 -> V_100 = V_101 ;
V_99 -> V_102 = V_103 ;
} else {
F_9 ( L_31 V_112 L_32 ) ;
}
if ( V_24 -> V_25 -> V_60 ) {
F_45 ( V_114 , & V_115 , V_95 , V_97 ) ;
}
if ( V_24 -> V_25 -> V_56 ) {
F_45 ( V_116 , & V_117 , V_95 , V_97 ) ;
}
if ( V_24 -> V_25 -> V_54 ) {
F_45 ( V_118 , & V_119 , V_95 , V_97 ) ;
}
if ( V_24 -> V_25 -> V_66 ) {
F_45 ( V_120 , & V_121 , V_95 , V_97 ) ;
}
if ( V_24 -> V_25 -> V_63 ) {
F_45 ( V_122 , & V_123 , V_95 , V_97 ) ;
}
if ( V_24 -> V_25 -> V_77 && V_24 -> V_25 -> V_72 ) {
F_45 ( V_124 , & V_125 , V_95 , V_97 ) ;
}
if ( ( V_24 -> V_25 -> V_88 && V_24 -> V_25 -> V_89 ) ||
( V_24 -> V_25 -> V_81 && V_24 -> V_25 -> V_85 ) ) {
F_45 ( V_126 , & V_127 , V_95 , V_97 ) ;
}
if ( V_24 -> V_25 -> V_91 ) {
F_45 ( V_128 , & V_129 , V_95 , V_97 ) ;
}
return 0 ;
}
static int F_51 ( struct V_96 * V_97 )
{
if ( F_47 ( V_97 ) ) {
F_52 ( V_112 , F_47 ( V_97 ) ) ;
if ( V_24 -> V_25 -> V_60 )
F_52 ( V_114 , F_47 ( V_97 ) ) ;
if ( V_24 -> V_25 -> V_54 )
F_52 ( V_118 , F_47 ( V_97 ) ) ;
if ( V_24 -> V_25 -> V_66 )
F_52 ( V_120 , F_47 ( V_97 ) ) ;
if ( V_24 -> V_25 -> V_56 )
F_52 ( V_116 , F_47 ( V_97 ) ) ;
if ( V_24 -> V_25 -> V_63 )
F_52 ( V_122 , F_47 ( V_97 ) ) ;
if ( V_24 -> V_25 -> V_77 && V_24 -> V_25 -> V_72 )
F_52 ( V_124 , F_47 ( V_97 ) ) ;
if ( ( V_24 -> V_25 -> V_88
&& V_24 -> V_25 -> V_89 )
|| ( V_24 -> V_25 -> V_81
&& V_24 -> V_25 -> V_85 ) )
F_52 ( V_126 , F_47 ( V_97 ) ) ;
if ( V_24 -> V_25 -> V_91 )
F_52 ( V_128 , F_47 ( V_97 ) ) ;
}
return 0 ;
}
static void F_53 ( struct V_96 * V_97 , V_57 V_130 )
{
if ( ! V_24 )
return;
if ( V_130 > V_131 )
return;
if ( ( V_130 & ~ ( ( V_57 ) V_132 ) ) < 16 )
V_24 -> V_83 = ( V_130 & ~ ( ( V_57 ) V_132 ) ) ;
else if ( ( V_130 & ~ ( ( V_57 ) V_133 ) ) < 16 )
V_24 -> V_83 = ( V_130 & ~ ( ( V_57 ) V_133 ) ) ;
F_54 ( V_24 -> V_97 , V_130 ,
V_24 -> V_134 [ V_130 % 128 ] ++ ) ;
return;
}
static int F_55 ( char * V_68 )
{
if ( V_68 == NULL )
return V_135 ;
if ( strncmp ( V_68 , L_33 , 3 ) == 0 )
return V_136 ;
else if ( strncmp ( V_68 , L_34 , 3 ) == 0 ||
strncmp ( V_68 , L_35 , 3 ) == 0 || strncmp ( V_68 , L_36 , 3 ) == 0 )
return V_69 ;
else if ( strncmp ( V_68 , L_37 , 2 ) == 0 || strncmp ( V_68 , L_38 , 3 ) == 0 )
return V_137 ;
else if ( strncmp ( V_68 , L_39 , 3 ) == 0 )
return V_138 ;
else if ( strncmp ( V_68 , L_40 , 3 ) == 0 )
return V_139 ;
else if ( strncmp ( V_68 , L_41 , 3 ) == 0 || strncmp ( V_68 , L_42 , 3 ) == 0 )
return V_140 ;
else if ( strncmp ( V_68 , L_43 , 3 ) == 0 || strncmp ( V_68 , L_44 , 3 ) == 0 )
return V_141 ;
else if ( strncmp ( V_68 , L_45 , 3 ) == 0 ||
strncmp ( V_68 , L_46 , 3 ) == 0 ||
strncmp ( V_68 , L_47 , 3 ) == 0 ||
strncmp ( V_68 , L_48 , 3 ) == 0 ||
strncmp ( V_68 , L_49 , 3 ) == 0 )
return V_142 ;
else if ( strncmp ( V_68 , L_50 , 2 ) == 0 )
return V_143 ;
else if ( strncmp ( V_68 , L_51 , 2 ) == 0 || strncmp ( V_68 , L_52 , 3 ) == 0 )
return V_144 ;
else if ( strncmp ( V_68 , L_53 , 2 ) == 0 )
return V_76 ;
else if ( strncmp ( V_68 , L_54 , 2 ) == 0 )
return V_145 ;
else if ( strncmp ( V_68 , L_55 , 2 ) == 0 )
return V_146 ;
else if ( strncmp ( V_68 , L_56 , 2 ) == 0 )
return V_147 ;
else if ( strncmp ( V_68 , L_57 , 2 ) == 0 )
return V_148 ;
else if ( strncmp ( V_68 , L_58 , 2 ) == 0 )
return V_149 ;
else if ( strncmp ( V_68 , L_59 , 2 ) == 0 )
return V_150 ;
else if ( strncmp ( V_68 , L_60 , 3 ) == 0 )
return V_151 ;
else if ( strncmp ( V_68 , L_61 , 3 ) == 0 )
return V_152 ;
else if ( strncmp ( V_68 , L_62 , 3 ) == 0 )
return V_153 ;
else if ( strncmp ( V_68 , L_63 , 3 ) == 0 )
return V_154 ;
else if ( strncmp ( V_68 , L_64 , 3 ) == 0 )
return V_155 ;
else if ( strncmp ( V_68 , L_65 , 3 ) == 0 )
return V_156 ;
else if ( strncmp ( V_68 , L_66 , 4 ) == 0 )
return V_73 ;
else
return V_135 ;
}
static int F_56 ( void )
{
struct V_4 V_47 = { V_157 , NULL } ;
union V_8 * V_68 = NULL ;
int V_158 ;
char * string = NULL ;
T_2 V_10 ;
V_10 = F_57 ( V_159 , 1 , & V_27 ) ;
if ( F_31 ( V_10 ) )
F_9 ( L_67 ) ;
if ( ! F_1 ( V_24 -> V_1 , L_68 , 0 , & V_47 ) ) {
F_58 ( L_69 ) ;
return - V_111 ;
}
if ( ! F_3 ( V_24 -> V_1 , L_70 , & V_158 ) )
F_9 ( L_71 ) ;
else if ( V_158 )
F_59 ( L_72 , V_158 ) ;
if ( V_47 . V_12 ) {
V_68 = V_47 . V_12 ;
switch ( V_68 -> type ) {
case V_160 :
string = V_68 -> string . V_12 ;
break;
case V_161 :
string = V_68 -> V_47 . V_12 ;
break;
default:
F_60 ( V_68 ) ;
V_68 = NULL ;
break;
}
}
V_24 -> V_68 = F_55 ( string ) ;
if ( V_24 -> V_68 == V_135 ) {
if ( V_27 &&
strncmp ( V_27 -> V_33 , L_73 , 4 ) == 0 ) {
V_24 -> V_68 = V_162 ;
F_59 ( L_74 ) ;
V_24 -> V_25 = & V_163 [ V_24 -> V_68 ] ;
F_60 ( V_68 ) ;
return 0 ;
} else {
V_24 -> V_68 = V_144 ;
F_59 ( L_75 ,
string ) ;
F_59 ( L_76 ) ;
F_60 ( V_68 ) ;
return - V_111 ;
}
}
V_24 -> V_25 = & V_163 [ V_24 -> V_68 ] ;
F_59 ( L_77 , string ) ;
if ( strncmp ( string , L_38 , 3 ) == 0 )
V_24 -> V_25 -> V_72 = NULL ;
else if ( strncmp ( string , L_44 , 3 ) == 0 )
V_24 -> V_25 -> V_72 = L_78 ;
else if ( strncmp ( string , L_49 , 3 ) == 0 ||
strncmp ( string , L_47 , 3 ) == 0 ||
strncmp ( string , L_42 , 3 ) == 0 )
V_24 -> V_25 -> V_54 = NULL ;
else if ( strncmp ( string , L_36 , 3 ) == 0 )
V_24 -> V_25 -> V_60 = NULL ;
else if ( strncmp ( string , L_45 , 3 ) == 0 ||
strncmp ( string , L_62 , 3 ) == 0 ||
strncmp ( string , L_48 , 3 ) == 0 )
V_24 -> V_25 -> V_60 = L_79 ;
else if ( V_27 ) {
if ( strncmp ( V_27 -> V_33 , L_80 , 2 ) == 0 )
V_24 -> V_25 -> V_51 = NULL ;
}
F_60 ( V_68 ) ;
return 0 ;
}
static int F_61 ( void )
{
int V_164 = 0 ;
V_164 = F_62 ( V_24 -> V_97 ) ;
if ( V_164 )
return V_164 ;
if ( V_24 -> V_97 -> V_10 . V_165 ) {
V_164 = F_56 () ;
} else {
F_58 ( L_81 ) ;
return - V_45 ;
}
return V_164 ;
}
static int F_63 ( struct V_96 * V_97 )
{
T_2 V_10 = V_15 ;
int V_164 ;
F_59 ( L_82 , V_23 ) ;
V_24 = F_64 ( sizeof( struct V_166 ) , V_167 ) ;
if ( ! V_24 )
return - V_168 ;
V_24 -> V_1 = V_97 -> V_1 ;
strcpy ( F_65 ( V_97 ) , V_169 ) ;
strcpy ( F_66 ( V_97 ) , V_170 ) ;
V_97 -> V_171 = V_24 ;
V_24 -> V_97 = V_97 ;
V_164 = F_61 () ;
if ( V_164 )
goto V_172;
V_164 = F_49 ( V_97 ) ;
if ( V_164 )
goto V_172;
if ( ( ! V_24 -> V_25 -> V_81 )
&& ( ! V_24 -> V_25 -> V_82 )
&& ( V_24 -> V_25 -> V_88 && V_24 -> V_25 -> V_89 ) ) {
V_10 =
F_2 ( NULL , V_24 -> V_25 -> V_89 ,
NULL , NULL ) ;
if ( F_31 ( V_10 ) )
F_9 ( L_83 ) ;
else {
V_10 =
F_2 ( NULL ,
V_24 -> V_25 -> V_88 ,
NULL , NULL ) ;
if ( F_31 ( V_10 ) )
F_9 ( L_84 ) ;
}
}
V_173 = 1 ;
V_24 -> V_55 = 0xFFF ;
V_172:
if ( V_164 )
F_60 ( V_24 ) ;
return V_164 ;
}
static int F_67 ( struct V_96 * V_97 , int type )
{
F_51 ( V_97 ) ;
F_60 ( V_24 ) ;
return 0 ;
}
static void F_68 ( void )
{
if ( V_174 )
F_69 ( V_174 ) ;
F_70 ( & V_175 ) ;
F_52 ( V_176 , V_177 ) ;
return;
}
static int T_8 F_71 ( void )
{
struct V_178 V_90 ;
int V_164 ;
V_164 = F_72 ( & V_175 ) ;
if ( V_164 < 0 )
return V_164 ;
V_110 = F_73 ( V_176 , V_177 ) ;
if ( ! V_110 ) {
F_58 ( L_85 ) ;
F_70 ( & V_175 ) ;
return - V_111 ;
}
if ( ! V_173 ) {
F_70 ( & V_175 ) ;
F_52 ( V_176 , V_177 ) ;
return - V_111 ;
}
memset ( & V_90 , 0 , sizeof( struct V_178 ) ) ;
V_90 . type = V_179 ;
V_90 . V_180 = 15 ;
V_174 = F_74 ( L_86 , NULL , NULL ,
& V_181 ,
& V_90 ) ;
if ( F_75 ( V_174 ) ) {
F_58 ( L_87 ) ;
V_174 = NULL ;
F_68 () ;
return - V_111 ;
}
return 0 ;
}
