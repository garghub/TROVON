static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = V_4 -> V_7 + V_5 ;
V_4 -> V_8 = NULL ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = F_2 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_4 ->
V_6 ,
( V_14 * ) & V_4 ->
V_9 ,
V_15 ) ;
if ( V_4 -> V_10 == NULL ) {
F_3 ( V_16 ,
L_1 ,
( long
unsigned
int ) V_4 -> V_6 ) ;
return false ;
}
V_4 -> V_8 = F_4 ( V_4 -> V_10 , V_5 ) ;
V_4 -> V_9 = F_5 ( V_4 -> V_9 , V_5 ) ;
memset ( V_4 -> V_8 , 0 , V_4 -> V_7 ) ;
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_8 == NULL )
return;
if ( V_4 -> V_9 ) {
int V_17 = ( ( V_18 * ) V_4 -> V_8 ) -
( ( V_18 * ) V_4 -> V_10 ) ;
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_4 -> V_6 ,
V_4 -> V_10 ,
( V_14 ) ( V_4 -> V_9 - V_17 ) ) ;
} else {
F_8 ( V_4 -> V_10 ) ;
}
V_4 -> V_8 = NULL ;
}
static bool F_9 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_3 * V_21 = F_10 (
sizeof( struct V_3 ) , V_15 ) ;
if ( V_21 == NULL ) {
F_11 ( L_2 ) ;
return false ;
}
V_21 -> V_7 = sizeof( union V_22 ) +
V_23 ;
if ( ! F_1 ( V_2 , V_21 , 256 ) ) {
F_11 ( L_3 ) ;
F_8 ( V_21 ) ;
return false ;
}
V_2 -> V_24 ++ ;
F_12 ( & V_21 -> V_25 , & V_2 -> V_26 ) ;
V_20 -> V_27 = V_21 ;
V_20 -> V_28 = (union V_22 * ) V_21 -> V_8 ;
V_20 -> V_28 -> V_29 . V_30 = V_2 -> V_24 ;
return true ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 )
F_14 ( ( void V_32 * ) V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
F_15 ( V_2 -> V_11 , 2 ) ;
if ( V_2 -> V_33 )
F_14 ( ( void V_32 * ) V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
F_15 ( V_2 -> V_11 , 0 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int error ;
V_2 -> V_31 = NULL ;
V_2 -> V_33 = NULL ;
error = F_17 ( V_2 -> V_11 , 2 , V_2 -> V_34 ) ;
if ( error != 0 ) {
F_3 ( V_16 ,
L_4 ,
error ) ;
return error ;
}
V_2 -> V_31 = ( void V_35 * ) F_18 ( F_19 ( V_2 -> V_11 , 2 ) ,
F_20 ( V_2 -> V_11 , 2 ) ) ;
if ( V_2 -> V_31 == NULL ) {
F_3 ( V_16 ,
L_5 ) ;
F_15 ( V_2 -> V_11 , 2 ) ;
return - V_36 ;
}
error = F_17 ( V_2 -> V_11 , 0 , V_2 -> V_34 ) ;
if ( error != 0 ) {
F_3 ( V_16 ,
L_4 ,
error ) ;
F_13 ( V_2 ) ;
return error ;
}
V_2 -> V_33 = ( void V_35 * ) F_18 ( F_19 ( V_2 -> V_11 ,
0 ) ,
F_20 ( V_2 -> V_11 , 0 ) ) ;
if ( V_2 -> V_33 == NULL ) {
F_3 ( V_16 ,
L_6 ) ;
F_13 ( V_2 ) ;
return - V_36 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_37 )
{
int V_38 ;
switch ( V_37 ) {
case V_39 :
V_40:
V_2 -> V_37 = V_39 ;
break;
case V_41 :
V_38 = F_22 ( V_2 -> V_11 ) ;
if ( V_38 != 0 ) {
F_3 ( V_42 ,
L_7
L_8
L_9 , V_2 -> V_43 ,
V_38 ) ;
goto V_40;
}
V_2 -> V_37 = V_41 ;
F_23 ( & V_2 -> V_44 , V_45 ) ;
break;
default:
F_3 ( V_42 ,
L_10
L_11 ,
V_46 ) ;
goto V_40;
}
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned long V_47 = V_48 ;
if ( V_2 -> V_37 == V_39 )
V_47 |= V_49 ;
F_3 ( V_50 ,
L_12 ,
V_2 -> V_11 -> V_51 , V_2 , V_2 -> V_34 , V_47 ) ;
if ( F_25 ( V_2 -> V_11 -> V_51 ,
( V_2 -> V_37 ==
V_39 ) ? V_52 :
V_53 ,
V_47 ,
V_2 -> V_34 ,
V_2 ) ) {
F_3 ( V_16 , L_13 ,
V_2 -> V_11 -> V_51 ) ;
return;
}
F_23 ( & V_2 -> V_44 , V_54 ) ;
F_3 ( V_50 ,
L_14 ,
V_2 -> V_11 -> V_51 , V_47 ) ;
}
int F_26 ( struct V_55 * V_56 , struct V_57 * V_11 ,
int V_43 )
{
struct V_1 * V_2 ;
T_2 V_58 = 0 ;
int V_38 ;
void * V_59 ;
struct V_19 * V_60 , * V_61 ;
if ( V_43 >= V_62 ) {
F_3 ( V_16 ,
L_15 ,
V_43 ) ;
return 0 ;
}
if ( V_63 [ V_43 ] ) {
F_3 ( V_16 ,
L_16 ,
V_43 ) ;
return 0 ;
}
V_2 = (struct V_1 * ) V_56 -> V_64 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_56 = V_56 ;
if ( sizeof( V_14 ) > 4 ) {
const T_3 V_65 = F_27
( & V_11 -> V_12 ) ;
if ( V_65 > F_28 ( 32 )
&& ! F_29 ( V_11 , F_28 ( 64 ) )
&& ! F_30 ( V_11 ,
F_28 ( 64 ) ) ) {
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_17 ) ;
} else if ( ! F_29 ( V_11 , F_28 ( 32 ) )
&& ! F_30 ( V_11 ,
F_28 ( 32 ) ) ) {
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_18 ) ;
} else {
F_3 ( V_16 ,
L_19 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
} else {
if ( ! F_29 ( V_11 , F_28 ( 32 ) )
&& ! F_30 ( V_11 ,
F_28 ( 32 ) ) ) {
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_18 ) ;
} else {
F_3 ( V_16 ,
L_19 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
}
V_63 [ V_43 ] = V_2 ;
sprintf ( V_2 -> V_34 , V_66 L_20 , V_43 ) ;
F_33 ( L_21 , V_2 , V_2 -> V_34 ) ;
F_34 ( & V_2 -> V_67 ) ;
F_34 ( & V_2 -> V_68 ) ;
F_35 ( & V_2 -> V_69 , 1 ) ;
F_35 ( & V_2 -> V_70 , 1 ) ;
F_35 ( & V_2 -> V_71 , 1 ) ;
F_36 ( V_2 ) ;
snprintf ( V_2 -> V_72 , V_73 , L_22 ,
V_2 -> V_43 ) ;
V_2 -> V_74 = F_37 ( V_2 -> V_72 ) ;
F_38 ( & V_2 -> V_75 ) ;
F_38 ( & V_2 -> V_76 ) ;
F_38 ( & V_2 -> V_77 ) ;
F_38 ( & V_2 -> V_78 ) ;
F_38 ( & V_2 -> V_79 ) ;
F_39 ( & V_2 -> V_80 . V_81 ) ;
F_39 ( & V_2 -> V_82 ) ;
F_39 ( & V_2 -> V_83 ) ;
F_39 ( & V_2 -> V_84 ) ;
F_39 ( & V_2 -> V_85 ) ;
F_39 ( & V_2 -> V_26 ) ;
F_39 ( & V_2 -> V_86 ) ;
V_60 = (struct V_19 * ) ( ( V_18 * ) ( V_2 + 1 ) ) ;
for ( V_61 = V_60 , V_38 = 1 ; V_38 < V_87 ;
V_61 ++ , V_38 ++ ) {
F_39 ( & V_61 -> V_81 ) ;
F_40 ( & V_61 -> V_88 , & V_2 -> V_85 ) ;
if ( ! F_9 ( V_2 , V_61 ) ) {
F_3 ( V_16 ,
L_23 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
}
F_33 ( L_24 , V_60 ,
V_61 ,
sizeof( * V_60 ) ,
V_87 ) ;
if ( F_16 ( V_2 ) != 0 ) {
F_3 ( V_16 , L_25 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
V_2 -> V_43 = V_43 ;
F_41 ( & V_2 -> V_89 ) ;
F_41 ( & V_2 -> V_90 ) ;
V_2 -> V_47 |= V_91
| V_92
| V_93
| V_94 ;
V_2 -> V_95 = V_96 ;
V_2 -> V_97 = 128 ;
V_2 -> V_98 = V_99 ;
F_21 ( V_2 , V_46 ) ;
V_2 -> V_100 = F_42 ( V_2 ) ;
V_2 -> V_101 = F_2 ( & V_11 -> V_12 ,
( V_13 ) V_2 -> V_100 ,
( V_14 * ) & V_58 ,
V_15 ) ;
if ( V_2 -> V_101 == NULL ) {
F_3 ( V_16 ,
L_26 ,
V_2 -> V_100 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
V_2 -> V_102 = V_58 ;
F_33 ( L_27 ,
V_2 -> V_100 ,
V_2 -> V_101 ,
F_43 ( V_58 ) ,
F_44 ( V_58 ) ) ;
memset ( V_2 -> V_101 , 0 , V_2 -> V_100 ) ;
V_59 = V_2 -> V_101 ;
if ( ! F_45 ( V_2 ,
& V_59 ) ) {
F_3 ( V_16 ,
L_28 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
F_46 ( & V_2 -> V_103 ,
V_104 ,
( unsigned long ) V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( ! F_49 ( V_2 , true ) )
F_3 ( V_16 , L_29 ) ;
else
F_33 ( L_30 ) ;
F_24 ( V_2 ) ;
if ( V_2 -> V_44 & V_54 )
F_50 ( V_2 ) ;
F_23 ( & V_2 -> V_44 , V_105 ) ;
if ( ! ( V_2 -> V_47 & V_106 ) )
F_51 ( V_2 ) ;
F_33 ( L_31 ,
V_2 , V_2 -> V_90 ) ;
return 1 ;
}
static void F_52 ( struct V_1 * V_2 ,
int V_107 )
{
struct V_3 * V_21 , * V_108 ;
if ( ( V_2 -> V_44 & V_105 )
&& ( ! ( V_2 -> V_47 & V_106 ) ) ) {
if ( ! V_107 ) {
F_53 ( & V_2 -> V_109 ) ;
F_54 ( & V_2 -> V_103 ) ;
}
F_55 ( V_2 ) ;
F_56 ( 500 ) ;
F_33 ( L_32 ) ;
}
if ( V_2 -> V_110 ) {
F_57 ( & V_2 -> V_56 -> V_111 . V_112 , & V_113 ) ;
V_2 -> V_110 = 0 ;
}
if ( V_2 -> V_114 ) {
F_57 ( & V_2 -> V_56 -> V_111 . V_112 , & V_115 ) ;
V_2 -> V_114 = 0 ;
}
if ( V_2 -> V_116 ) {
F_57 ( & V_2 -> V_56 -> V_111 . V_112 , & V_117 ) ;
V_2 -> V_116 = 0 ;
}
if ( V_2 -> V_118 ) {
F_57 ( & V_2 -> V_56 -> V_111 . V_112 , & V_119 ) ;
V_2 -> V_118 = 0 ;
}
if ( V_2 -> V_120 ) {
F_57 ( & V_2 -> V_56 -> V_111 . V_112 ,
& V_121 ) ;
V_2 -> V_120 = 0 ;
}
if ( V_2 -> V_122 ) {
F_57 ( & V_2 -> V_56 -> V_111 . V_112 ,
& V_123 ) ;
V_2 -> V_122 = 0 ;
}
if ( V_2 -> V_44 & V_54 ) {
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_33 , V_2 -> V_11 -> V_51 ) ;
F_58 ( V_2 -> V_11 -> V_51 , V_2 ) ;
F_33 ( L_34 ) ;
F_59 ( & V_2 -> V_44 , V_54 ) ;
}
if ( V_2 -> V_44 & V_45 ) {
F_60 ( V_2 -> V_11 ) ;
F_59 ( & V_2 -> V_44 , V_45 ) ;
F_33 ( L_35 ) ;
}
if ( V_2 -> V_124 . V_8 )
F_6 ( V_2 , & V_2 -> V_124 ) ;
if ( V_2 -> V_125 . V_8 )
F_6 ( V_2 , & V_2 -> V_125 ) ;
F_61 (memdesc, next, &a->free_sg_list_head,
next_desc) {
F_6 ( V_2 , V_21 ) ;
}
F_61 (memdesc, next, &a->vrq_mds_head, next_desc) {
F_6 ( V_2 , V_21 ) ;
F_62 ( & V_21 -> V_25 ) ;
F_8 ( V_21 ) ;
}
F_8 ( V_2 -> V_126 ) ;
V_2 -> V_126 = NULL ;
F_8 ( V_2 -> V_127 ) ;
V_2 -> V_127 = NULL ;
F_8 ( V_2 -> V_128 ) ;
V_2 -> V_128 = NULL ;
if ( V_2 -> V_31 ) {
F_13 ( V_2 ) ;
V_2 -> V_31 = NULL ;
V_2 -> V_33 = NULL ;
F_33 ( L_36 ) ;
}
}
void F_32 ( int V_38 )
{
struct V_1 * V_2 = V_63 [ V_38 ] ;
if ( V_2 ) {
unsigned long V_47 ;
struct V_129 * V_130 ;
F_33 ( L_37 , V_2 , V_38 ) ;
F_36 ( V_2 ) ;
F_52 ( V_2 , 0 ) ;
if ( V_131 &&
( V_2 -> V_11 == V_132 ) ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_133 ,
V_131 ,
V_134 ) ;
V_131 = NULL ;
}
if ( V_2 -> V_135 ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_136 ,
V_2 -> V_135 ,
( V_14 ) V_2 -> V_137 ) ;
V_2 -> V_135 = NULL ;
}
if ( V_2 -> V_138 ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_2 -> V_139 ,
V_2 -> V_138 ,
( V_14 ) V_2 -> V_140 ) ;
V_2 -> V_138 = NULL ;
}
F_8 ( V_2 -> V_141 ) ;
V_2 -> V_141 = NULL ;
F_63 ( & V_2 -> V_68 , V_47 ) ;
V_130 = V_2 -> V_74 ;
V_2 -> V_74 = NULL ;
F_64 ( & V_2 -> V_68 , V_47 ) ;
if ( V_130 )
F_65 ( V_130 ) ;
if ( V_2 -> V_101 ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_2 -> V_100 ,
V_2 -> V_101 ,
( V_14 ) V_2 -> V_102 ) ;
V_2 -> V_101 = NULL ;
F_33 ( L_38 ) ;
}
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_39
L_40 ,
V_2 -> V_11 -> V_142 ,
V_2 -> V_11 -> V_143 ,
V_2 -> V_11 -> V_51 ,
V_2 -> V_11 -> V_144 ) ;
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_41 ,
V_2 -> V_11 -> V_145 . V_146 ) ;
F_66 ( V_2 -> V_11 ) ;
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_42 ,
V_2 -> V_11 -> V_145 . V_146 ) ;
F_31 ( V_50 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_43 ,
V_2 -> V_11 ) ;
F_67 ( V_2 -> V_11 , NULL ) ;
V_63 [ V_38 ] = NULL ;
if ( V_2 -> V_44 & V_105 ) {
F_59 ( & V_2 -> V_44 ,
V_105 ) ;
F_23 ( & V_2 -> V_47 ,
V_106 ) ;
F_31 ( V_50 ,
& ( V_2 -> V_56 -> V_147 ) ,
L_44 ) ;
F_68 ( V_2 -> V_56 ) ;
F_31 ( V_50 ,
& ( V_2 -> V_56 -> V_147 ) ,
L_45 ) ;
F_69 ( V_2 -> V_56 ) ;
}
}
}
int F_70 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_56 == NULL ) {
int V_38 ;
F_33 ( L_46 ) ;
for ( V_38 = 0 ; V_38 < V_62 ; V_38 ++ )
F_32 ( V_38 ) ;
return - 1 ;
}
F_33 ( L_47 , V_56 ) ;
V_2 = (struct V_1 * ) V_56 -> V_64 ;
V_43 = V_2 -> V_43 ;
F_32 ( V_43 ) ;
return V_43 ;
}
int F_71 ( struct V_57 * V_148 , T_4 V_149 )
{
struct V_55 * V_56 = F_72 ( V_148 ) ;
T_1 V_150 ;
struct V_1 * V_2 = (struct V_1 * ) V_56 -> V_64 ;
F_31 ( V_50 , & ( V_148 -> V_12 ) , L_48 ) ;
if ( ! V_2 )
return - V_151 ;
F_52 ( V_2 , 1 ) ;
V_150 = F_73 ( V_148 , V_149 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) ,
L_49 ) ;
F_74 ( V_148 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) ,
L_50 ) ;
F_66 ( V_148 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) ,
L_51 ) ;
F_75 ( V_148 , V_150 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) , L_52 ) ;
return 0 ;
}
int F_76 ( struct V_57 * V_148 )
{
struct V_55 * V_56 = F_72 ( V_148 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_56 -> V_64 ;
int V_152 ;
F_31 ( V_50 , & ( V_148 -> V_12 ) , L_53 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) ,
L_54
L_55 ) ;
F_75 ( V_148 , V_153 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) ,
L_56
L_55 ) ;
F_77 ( V_148 , V_153 , 0 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) ,
L_57 ) ;
F_78 ( V_148 ) ;
F_31 ( V_50 , & ( V_148 -> V_12 ) ,
L_58 ) ;
V_152 = F_79 ( V_148 ) ;
F_80 ( V_148 ) ;
if ( ! V_2 ) {
V_152 = - V_151 ;
goto V_154;
}
if ( F_16 ( V_2 ) != 0 ) {
F_3 ( V_16 , L_59 ) ;
V_152 = - V_155 ;
goto V_154;
}
F_21 ( V_2 , V_2 -> V_37 ) ;
F_47 ( V_2 ) ;
if ( ! F_81 ( V_2 , true ) ) {
F_33 ( L_60 ) ;
V_152 = - V_155 ;
goto V_154;
}
F_24 ( V_2 ) ;
if ( V_2 -> V_44 & V_54 ) {
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
} else {
F_33 ( L_61 ) ;
F_3 ( V_16 , L_62 ) ;
V_152 = - V_155 ;
goto V_154;
}
V_154:
F_31 ( V_16 , & ( V_148 -> V_12 ) , L_63 ,
V_152 ) ;
return V_152 ;
}
bool F_82 ( struct V_1 * V_2 , char * V_156 )
{
F_23 ( & V_2 -> V_47 , V_106 ) ;
F_3 ( V_16 ,
L_64 , V_156 ) ;
return false ;
}
T_1 F_42 ( struct V_1 * V_2 )
{
return sizeof( struct V_157 )
+ F_5 ( V_158 , 8 )
+ F_5 ( sizeof( T_1 ) , 8 )
+ 8
+ ( V_159 * ( V_160 ) V_161 )
+ F_5 ( ( V_87 + V_162 + 1 +
V_163 ) *
sizeof( struct V_164 ) ,
8 )
+ F_5 ( ( V_87 + V_162 + 1 +
V_163 ) *
sizeof( struct V_165 ) , 8 )
+ 256 ;
}
static void F_83 ( struct V_1 * V_2 )
{
int V_166 ;
V_166 = F_84 ( V_2 -> V_11 , V_167 ) ;
if ( 0xffff & V_166 ) {
V_160 V_168 ;
F_85 ( V_2 -> V_11 , V_166 + V_169 ,
& V_168 ) ;
if ( ( V_168 & V_170 ) > 0x2000 ) {
F_3 ( V_50 ,
L_65 ) ;
V_168 &= ~ V_170 ;
V_168 |= 0x2000 ;
F_86 ( V_2 -> V_11 ,
V_166 + V_169 ,
V_168 ) ;
}
}
}
bool F_45 ( struct V_1 * V_2 ,
void * * V_171 )
{
T_1 V_38 ;
V_18 * V_172 ;
struct V_164 * V_173 ;
struct V_19 * V_20 ;
struct V_3 * V_174 ;
F_34 ( & V_2 -> V_175 ) ;
F_34 ( & V_2 -> V_176 ) ;
F_34 ( & V_2 -> V_177 ) ;
V_2 -> V_178 = & V_2 -> V_179 [ V_180 ] ;
if ( ! F_9 ( V_2 , & V_2 -> V_80 ) ) {
F_11 (
L_66 ) ;
return false ;
}
V_2 -> V_126 =
F_10 ( V_162 * sizeof( struct V_19 ) ,
V_15 ) ;
if ( V_2 -> V_126 == NULL ) {
F_3 ( V_16 ,
L_67 ) ;
return false ;
}
V_2 -> V_127 = F_10 (
V_159 * sizeof( struct V_3 ) , V_15 ) ;
if ( V_2 -> V_127 == NULL ) {
F_3 ( V_16 ,
L_68 ) ;
return false ;
}
V_2 -> V_128 =
F_10 ( ( V_87 + V_162 +
1 ) * sizeof( struct V_19 * ) , V_15 ) ;
if ( V_2 -> V_128 == NULL ) {
F_3 ( V_16 ,
L_69 ) ;
return false ;
}
F_83 ( V_2 ) ;
if ( ( V_2 -> V_11 -> V_181 == V_182 )
&& ( V_2 -> V_11 -> V_183 & V_184 ) )
V_2 -> V_44 |= V_185 ;
if ( V_2 -> V_44 & V_185 )
V_2 -> V_44 |= V_186 ;
if ( V_2 -> V_11 -> V_183 == V_187 )
V_2 -> V_44 |= V_188 ;
V_172 = ( V_18 * ) * V_171 ;
for ( V_38 = 0 , V_174 = V_2 -> V_127 ; V_38 < V_159 ; V_38 ++ , V_174 ++ ) {
V_174 -> V_7 = V_161 ;
F_40 ( & V_174 -> V_25 , & V_2 -> V_84 ) ;
if ( ! F_1 ( V_2 , V_174 , V_189 ) ) {
if ( V_38 < V_190 )
return false ;
break;
}
}
V_2 -> V_191 = V_87 + V_163 ;
V_2 -> V_124 . V_7 = V_2 -> V_191 *
sizeof( struct
V_164 ) ;
if ( ! F_1 ( V_2 , & V_2 -> V_124 , V_192 ) ) {
F_11 ( L_70 ) ;
return false ;
}
V_2 -> V_125 . V_7 = V_2 -> V_191 *
sizeof( struct V_165 ) ;
if ( ! F_1 ( V_2 , & V_2 -> V_125 ,
V_192 ) ) {
F_11 ( L_70 ) ;
return false ;
}
V_2 -> V_193 = (struct V_157 * ) V_172 ;
V_172 += sizeof( struct V_157 ) ;
V_2 -> V_194 = V_172 ;
V_172 += V_158 ;
V_172 = F_4 ( V_172 , 8 ) ;
V_2 -> V_195 = ( T_1 volatile * ) V_172 ;
V_172 += sizeof( T_1 ) ;
if ( ! ( V_2 -> V_47 & V_196 ) )
F_87 ( V_2 ) ;
* V_171 = ( void * ) V_172 ;
if ( V_2 -> V_47 & V_93 ) {
memset ( V_2 -> V_128 , 0 ,
( V_87 + V_162 +
1 ) * sizeof( struct V_19 * ) ) ;
F_88 ( V_2 ) ;
V_173 =
(struct V_164 * ) V_2 ->
V_124 .
V_8 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_191 ; V_38 ++ ) {
V_173 -> V_197 = 0 ;
V_173 -> V_198 = 0 ;
V_173 -> V_199 = F_89 ( V_200
| ( sizeof( union
V_22 )
/
sizeof( T_1 ) ) ) ;
V_173 ++ ;
}
for ( V_20 = V_2 -> V_126 , V_38 = 0 ; V_38 < V_162 ; V_20 ++ ,
V_38 ++ ) {
F_39 ( & V_20 -> V_81 ) ;
if ( ! F_9 ( V_2 , V_20 ) ) {
F_11 (
L_23 ) ;
return false ;
}
F_90 ( V_20 , V_2 ) ;
V_20 -> V_201 = V_202 ;
}
}
return true ;
}
bool F_48 ( struct V_1 * V_2 )
{
T_1 V_203 ;
T_1 V_204 ;
T_2 V_205 ;
T_1 V_206 ;
if ( V_2 -> V_47 & V_207 )
goto V_208;
F_91 ( V_2 , V_209 , V_210 ) ;
F_92 ( V_2 , V_209 ) ;
V_203 = F_93 ( V_211 ) ;
while ( true ) {
F_94 ( V_2 ) ;
V_204 = F_95 ( V_2 , V_212 ) ;
if ( V_204 == 0xFFFFFFFF ) {
if ( ( F_93 ( V_211 ) - V_203 ) > 2000 )
return F_82 ( V_2 ,
L_71 ) ;
} else if ( V_204 & V_213 ) {
T_1 V_214 = ( V_204 & V_215 ) ;
F_91 ( V_2 , V_212 ,
V_204 ) ;
if ( V_214 == V_216 ) {
F_23 ( & V_2 -> V_47 ,
V_94 ) ;
V_2 -> V_97 = 128 ;
V_2 -> V_98 = V_99 ;
} else if ( V_214 == V_217 ) {
F_59 ( & V_2 -> V_47 ,
V_94 ) ;
V_2 -> V_97 = 1024 ;
V_2 -> V_98 = V_218 ;
} else {
return F_82 ( V_2 ,
L_72 ) ;
}
break;
}
F_96 ( F_97 ( 100 ) ) ;
if ( ( F_93 ( V_211 ) - V_203 ) > 180000 ) {
F_11 ( L_73 ) ;
F_98 () ;
return F_82 ( V_2 ,
L_74 ) ;
}
}
F_91 ( V_2 , V_219 , V_220 ) ;
V_203 = F_93 ( V_211 ) ;
while ( true ) {
V_204 = F_95 ( V_2 , V_212 ) ;
if ( V_204 & V_220 ) {
F_91 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_96 ( F_97 ( 50 ) ) ;
if ( ( F_93 ( V_211 ) - V_203 ) > 3000 ) {
F_11 ( L_75 ) ;
break;
}
}
V_208:
V_206 = F_95 ( V_2 , V_221 ) ;
V_206 &= ~ V_222 ;
F_91 ( V_2 , V_221 , V_206 ) ;
V_206 = F_95 ( V_2 , V_223 ) ;
V_206 &= ~ V_224 ;
F_91 ( V_2 , V_223 , V_206 ) ;
V_205 = V_2 -> V_124 . V_9 ;
F_91 ( V_2 , V_225 ,
F_44 ( V_205 ) ) ;
F_91 ( V_2 , V_226 ,
F_43 ( V_205 ) ) ;
V_205 = V_2 -> V_125 . V_9 ;
F_91 ( V_2 , V_227 ,
F_44 ( V_205 ) ) ;
F_91 ( V_2 , V_228 ,
F_43 ( V_205 ) ) ;
V_205 = V_2 -> V_102 +
( ( V_18 * ) V_2 -> V_195 - V_2 -> V_101 ) ;
F_91 ( V_2 , V_229 ,
F_44 ( V_205 ) ) ;
F_91 ( V_2 , V_230 ,
F_43 ( V_205 ) ) ;
* V_2 -> V_195 =
V_2 -> V_231 =
V_2 -> V_232 = V_2 -> V_191 - 1 ;
F_23 ( & V_2 -> V_47 , V_233 ) ;
F_91 ( V_2 , V_234 , V_235 |
V_2 -> V_231 ) ;
F_91 ( V_2 , V_236 , V_237 |
V_2 -> V_231 ) ;
F_91 ( V_2 , V_238 , V_239 |
V_2 -> V_231 ) ;
F_91 ( V_2 , V_240 ,
V_241 | V_2 -> V_231 ) ;
V_206 = F_95 ( V_2 , V_242 ) ;
V_206 &= ~ ( V_243 | V_244 ) ;
F_91 ( V_2 , V_242 ,
( V_206 | V_245 | V_246 ) ) ;
V_206 = F_95 ( V_2 , V_247 ) ;
V_206 &= ~ ( V_248 | V_249 ) ;
F_91 ( V_2 , V_247 ,
( V_206 | V_250 |
V_251 ) ) ;
V_206 = F_95 ( V_2 , V_221 ) ;
V_206 &= ~ ( V_252 | V_253 ) ;
V_206 |= V_254 | V_255
| ( V_2 -> V_191 << V_256 ) ;
F_91 ( V_2 , V_221 , V_206 ) ;
V_206 = F_95 ( V_2 , V_223 ) ;
V_206 &= ~ ( V_257 | V_258 ) ;
V_206 |= V_259 | ( V_2 -> V_191 << V_260 ) ;
F_91 ( V_2 , V_223 , V_206 ) ;
F_91 ( V_2 , V_219 , V_261 ) ;
V_203 = F_93 ( V_211 ) ;
while ( true ) {
V_204 = F_95 ( V_2 , V_212 ) ;
if ( V_204 & V_261 ) {
F_91 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_96 ( F_97 ( 100 ) ) ;
if ( ( F_93 ( V_211 ) - V_203 ) > 3000 ) {
F_11 (
L_76 ) ;
F_98 () ;
return F_82 ( V_2 ,
L_76 ) ;
}
}
V_204 = F_95 ( V_2 , V_262 ) ;
if ( V_204 & V_263 )
F_23 ( & V_2 -> V_44 , V_264 ) ;
else
F_59 ( & V_2 -> V_44 , V_264 ) ;
F_91 ( V_2 , V_265 , V_266 ) ;
F_91 ( V_2 , V_267 , V_268 ) ;
return true ;
}
static bool F_99 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_1 V_269 = V_2 -> V_95 ;
struct V_270 * V_271 ;
V_2 -> V_95 = 0 ;
switch ( V_269 ) {
case V_96 :
case V_272 :
{
struct V_273 V_274 ;
F_100 ( & V_274 ) ;
F_11 ( L_77 ) ;
F_101 ( V_2 ,
V_20 ,
V_275 ,
0 ,
NULL ) ;
V_271 = (struct V_270 * ) & V_20 -> V_28 -> V_276 . V_277 . V_278 ;
V_271 -> V_161 = V_161 ;
V_271 -> V_279 = V_274 . V_280 ;
V_20 -> V_47 |= V_281 ;
V_2 -> V_95 = V_282 ;
break;
}
case V_282 :
if ( V_20 -> V_283 == V_284 ) {
T_1 V_285 ;
T_1 V_286 ;
V_2 -> V_287 = F_102 (
V_20 -> V_288 . V_289 . V_290 ) ;
V_2 -> V_291 = V_20 -> V_288 . V_289 . V_291 ;
V_285 = F_103 ( V_20 -> V_288 . V_289 . V_292 ) ;
V_286 = F_104 ( V_20 -> V_288 . V_289 . V_292 ) ;
V_2 -> V_287 += ( V_285 << 16 ) + ( V_286 << 24 ) ;
} else {
F_11 ( L_78 ) ;
}
if ( ( V_2 -> V_44 & V_185 )
|| ( F_105 ( V_2 -> V_287 ) >
F_105 ( 0x47020052 ) ) ) {
F_11 ( L_79 ) ;
F_101 ( V_2 ,
V_20 ,
V_293 ,
sizeof( struct V_270 ) ,
NULL ) ;
V_20 -> V_28 -> V_276 . V_294 = F_106 (
struct V_295 ,
V_277 . V_296 ) ;
V_20 -> V_28 -> V_276 . V_277 . V_297 . V_298 =
F_89 ( sizeof( struct V_270 ) ) ;
V_20 -> V_28 -> V_276 . V_277 . V_297 . V_197 = F_107 (
V_20 -> V_27 -> V_9 +
sizeof( union V_22 ) ) ;
V_20 -> V_47 |= V_281 ;
V_2 -> V_95 = V_299 ;
break;
}
case V_299 :
if ( V_269 == V_299 ) {
V_271 = (struct V_270 * ) V_20 -> V_300 ;
if ( V_20 -> V_283 == V_284 ) {
V_2 -> V_301 =
F_108 ( V_271 -> V_301 ) ;
V_2 -> V_302 =
F_108 ( V_271 -> V_302 ) ;
} else {
F_11 ( L_78 ) ;
}
}
default:
V_20 -> V_283 = V_284 ;
return false ;
}
return true ;
}
bool F_109 ( struct V_1 * V_2 )
{
bool V_303 = true ;
struct V_19 * V_20 = & V_2 -> V_80 ;
F_90 ( V_20 , V_2 ) ;
V_20 -> V_201 = V_304 ;
if ( V_2 -> V_95 == 0 )
V_2 -> V_95 = V_272 ;
while ( V_2 -> V_95 ) {
if ( F_99 ( V_2 , V_20 ) ) {
unsigned long V_47 ;
while ( true ) {
F_63 ( & V_2 -> V_177 , V_47 ) ;
F_110 ( V_2 , V_20 ) ;
F_64 ( & V_2 -> V_177 , V_47 ) ;
F_111 ( V_2 , V_20 ) ;
if ( V_20 -> V_283 != V_305 )
break;
}
}
if ( V_20 -> V_283 == V_284
|| ( ( V_20 -> V_47 & V_281 )
&& V_20 -> V_283 != V_306 ) )
continue;
F_3 ( V_16 , L_80 ,
V_2 -> V_95 , V_20 -> V_283 , V_20 -> V_47 ) ;
V_2 -> V_95 = V_96 ;
V_303 = false ;
break;
}
F_112 ( V_20 , V_2 ) ;
return V_303 ;
}
bool F_49 ( struct V_1 * V_2 , bool V_307 )
{
bool V_308 = false ;
struct V_19 * V_20 ;
T_1 V_38 ;
if ( V_2 -> V_47 & V_106 )
goto exit;
if ( ! ( V_2 -> V_47 & V_196 ) ) {
if ( ! F_113 ( V_2 ) )
F_3 ( V_42 ,
L_81 ) ;
}
if ( ! F_109 ( V_2 ) ) {
F_82 ( V_2 , L_82 ) ;
goto exit;
}
F_59 ( & V_2 -> V_47 , V_106 ) ;
F_59 ( & V_2 -> V_47 , V_91 ) ;
for ( V_38 = 0 , V_20 = V_2 -> V_126 ; V_38 < V_162 ; V_38 ++ , V_20 ++ )
F_114 ( V_2 , V_20 ) ;
if ( ! V_2 -> V_309 [ 0 ] )
F_115 ( V_2 ) ;
if ( ! V_2 -> V_310 [ 0 ] )
F_116 ( V_2 ) ;
if ( V_2 -> V_287 == 0 )
V_2 -> V_311 [ 0 ] = 0 ;
else
sprintf ( V_2 -> V_311 , L_83 ,
( int ) F_103 ( F_117 ( V_2 -> V_287 ) ) ,
( int ) F_104 ( F_117 ( V_2 -> V_287 ) ) ) ;
F_11 ( L_84 , V_2 -> V_311 ) ;
if ( ( V_2 -> V_47 & V_207 )
&& ( V_2 -> V_47 & V_93 ) ) {
F_50 ( V_2 ) ;
return true ;
}
F_118 ( V_2 ) ;
if ( V_307 ) {
T_1 V_312 = V_2 -> V_313 ;
T_1 V_314 = 100 ;
T_1 V_315 ;
F_23 ( & V_2 -> V_47 , V_316 ) ;
F_23 ( & V_2 -> V_47 , V_317 ) ;
if ( V_2 -> V_47 & V_93 )
F_119 ( & V_2 -> V_90 ) ;
while ( V_2 -> V_47 & V_92 ) {
F_96 ( F_97 ( 100 ) ) ;
V_315 = F_93 ( V_211 ) - V_312 ;
V_312 += V_315 ;
if ( ! ( V_2 -> V_47 & V_91 ) )
F_120 ( V_2 ) ;
if ( V_314 <= V_315 ) {
V_314 += 100 ;
F_121 ( V_2 ) ;
}
if ( V_314 > V_315 )
V_314 -= V_315 ;
if ( F_122 ( V_2 ) )
F_123 ( V_2 ) ;
}
if ( V_2 -> V_47 & V_93 )
F_41 ( & V_2 -> V_90 ) ;
F_59 ( & V_2 -> V_47 , V_317 ) ;
F_59 ( & V_2 -> V_47 , V_316 ) ;
}
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
V_2 -> V_318 = V_319 ;
F_50 ( V_2 ) ;
F_126 ( V_2 ) ;
V_308 = true ;
exit:
if ( ( V_2 -> V_47 & V_207 )
&& ( V_2 -> V_47 & V_93 ) ) {
if ( ! V_308 )
F_59 ( & V_2 -> V_47 , V_91 ) ;
} else {
if ( ! V_308 ) {
F_59 ( & V_2 -> V_47 , V_91 ) ;
F_59 ( & V_2 -> V_47 , V_92 ) ;
}
if ( V_2 -> V_47 & V_93 ) {
F_59 ( & V_2 -> V_47 , V_93 ) ;
if ( F_127 ( & V_2 -> V_90 ) == 0 )
F_128 ( V_2 ) ;
}
}
return V_308 ;
}
void F_129 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_47 , V_320 ) ;
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( ! F_133 ( V_2 ) )
return;
if ( ( V_2 -> V_44 & V_321 )
&& ! ( V_2 -> V_44 & V_322 ) ) {
F_134 ( V_2 ,
V_2 -> V_323 ,
V_324 + 0x80000 ,
V_325 ) ;
F_23 ( & V_2 -> V_44 , V_322 ) ;
}
F_59 ( & V_2 -> V_44 , V_321 ) ;
if ( V_2 -> V_11 -> V_326 == V_327 )
F_91 ( V_2 , V_328 ,
V_329 ) ;
else
F_91 ( V_2 , V_330 ,
V_331 ) ;
F_56 ( 10 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_203 ;
T_1 V_204 ;
F_91 ( V_2 , V_219 , V_263 ) ;
V_203 = F_93 ( V_211 ) ;
while ( true ) {
V_204 = F_95 ( V_2 , V_212 ) ;
if ( V_204 & V_263 ) {
F_91 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_96 ( F_97 ( 100 ) ) ;
if ( ( F_93 ( V_211 ) - V_203 ) > 30000 ) {
F_11 ( L_85 ) ;
break;
}
}
}
void F_55 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_47 , V_332 ) ;
F_23 ( & V_2 -> V_47 , V_333 ) ;
if ( ! ( V_2 -> V_47 & V_106 ) ) {
T_1 V_203 ;
T_1 V_204 ;
F_47 ( V_2 ) ;
F_136 ( V_2 ) ;
F_91 ( V_2 , V_219 ,
V_220 ) ;
V_203 = F_93 ( V_211 ) ;
while ( true ) {
V_204 =
F_95 ( V_2 , V_212 ) ;
if ( V_204 & V_220 ) {
F_91 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_96 ( F_97 ( 100 ) ) ;
if ( ( F_93 ( V_211 ) - V_203 ) > 3000 ) {
F_11 (
L_75 ) ;
break;
}
}
if ( V_2 -> V_44 & V_264 )
F_135 ( V_2 ) ;
}
F_23 ( & V_2 -> V_47 , V_320 ) ;
F_23 ( & V_2 -> V_47 , V_92 ) ;
F_23 ( & V_2 -> V_47 , V_91 ) ;
F_137 ( V_2 ) ;
V_2 -> V_334 = F_138 ( V_2 ) ;
F_139 ( V_2 , false ) ;
}
bool F_81 ( struct V_1 * V_2 , bool V_307 )
{
bool V_335 ;
F_59 ( & V_2 -> V_47 , V_333 ) ;
F_83 ( V_2 ) ;
F_23 ( & V_2 -> V_47 , V_93 ) ;
F_41 ( & V_2 -> V_90 ) ;
V_335 = F_48 ( V_2 ) ;
if ( ! F_49 ( V_2 , V_307 ) )
V_335 = false ;
F_140 ( V_2 , true ) ;
F_59 ( & V_2 -> V_47 , V_332 ) ;
return V_335 ;
}
bool F_133 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 & V_336 )
return false ;
if ( F_95 ( V_2 , V_212 ) == 0xFFFFFFFF ) {
F_23 ( & V_2 -> V_47 , V_336 ) ;
return false ;
}
return true ;
}
const char * F_141 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_11 -> V_183 ) {
case V_337 :
return L_86 ;
case V_338 :
return L_87 ;
case V_339 :
return L_88 ;
case V_340 :
return L_89 ;
case V_341 :
return L_90 ;
case V_342 :
return L_91 ;
case V_343 :
return L_92 ;
case V_344 :
return L_93 ;
case V_187 :
return L_94 ;
}
return L_95 ;
}
const char * F_142 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_11 -> V_183 ) {
case V_337 :
return L_96 ;
case V_338 :
return L_97 ;
case V_339 :
return L_98 ;
case V_340 :
return L_99 ;
case V_341 :
return L_100 ;
case V_342 :
return L_101 ;
case V_343 :
return L_102 ;
case V_344 :
return L_103 ;
case V_187 :
return L_104 ;
}
return L_105 ;
}
