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
F_23 ( V_44 , & V_2 -> V_45 ) ;
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
unsigned long V_47 = 0 ;
if ( V_2 -> V_37 == V_39 )
V_47 |= V_48 ;
F_3 ( V_49 ,
L_12 ,
V_2 -> V_11 -> V_50 , V_2 , V_2 -> V_34 , V_47 ) ;
if ( F_25 ( V_2 -> V_11 -> V_50 ,
( V_2 -> V_37 ==
V_39 ) ? V_51 :
V_52 ,
V_47 ,
V_2 -> V_34 ,
V_2 ) ) {
F_3 ( V_16 , L_13 ,
V_2 -> V_11 -> V_50 ) ;
return;
}
F_23 ( V_53 , & V_2 -> V_45 ) ;
F_3 ( V_49 ,
L_14 ,
V_2 -> V_11 -> V_50 , V_47 ) ;
}
int F_26 ( struct V_54 * V_55 , struct V_56 * V_11 ,
int V_43 )
{
struct V_1 * V_2 ;
T_2 V_57 = 0 ;
int V_38 ;
void * V_58 ;
struct V_19 * V_59 , * V_60 ;
if ( V_43 >= V_61 ) {
F_3 ( V_16 ,
L_15 ,
V_43 ) ;
return 0 ;
}
if ( V_62 [ V_43 ] ) {
F_3 ( V_16 ,
L_16 ,
V_43 ) ;
return 0 ;
}
V_2 = (struct V_1 * ) V_55 -> V_63 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_55 = V_55 ;
if ( sizeof( V_14 ) > 4 ) {
const T_3 V_64 = F_27
( & V_11 -> V_12 ) ;
if ( V_64 > F_28 ( 32 )
&& ! F_29 ( V_11 , F_28 ( 64 ) )
&& ! F_30 ( V_11 ,
F_28 ( 64 ) ) ) {
F_31 ( V_49 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_17 ) ;
} else if ( ! F_29 ( V_11 , F_28 ( 32 ) )
&& ! F_30 ( V_11 ,
F_28 ( 32 ) ) ) {
F_31 ( V_49 ,
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
F_31 ( V_49 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_18 ) ;
} else {
F_3 ( V_16 ,
L_19 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
}
V_62 [ V_43 ] = V_2 ;
sprintf ( V_2 -> V_34 , V_65 L_20 , V_43 ) ;
F_33 ( L_21 , V_2 , V_2 -> V_34 ) ;
F_34 ( & V_2 -> V_66 ) ;
F_34 ( & V_2 -> V_67 ) ;
F_35 ( & V_2 -> V_68 , 1 ) ;
F_35 ( & V_2 -> V_69 , 1 ) ;
F_35 ( & V_2 -> V_70 , 1 ) ;
F_36 ( V_2 ) ;
snprintf ( V_2 -> V_71 , V_72 , L_22 ,
V_2 -> V_43 ) ;
V_2 -> V_73 = F_37 ( V_2 -> V_71 ) ;
F_38 ( & V_2 -> V_74 ) ;
F_38 ( & V_2 -> V_75 ) ;
F_38 ( & V_2 -> V_76 ) ;
F_38 ( & V_2 -> V_77 ) ;
F_38 ( & V_2 -> V_78 ) ;
F_39 ( & V_2 -> V_79 . V_80 ) ;
F_39 ( & V_2 -> V_81 ) ;
F_39 ( & V_2 -> V_82 ) ;
F_39 ( & V_2 -> V_83 ) ;
F_39 ( & V_2 -> V_84 ) ;
F_39 ( & V_2 -> V_26 ) ;
F_39 ( & V_2 -> V_85 ) ;
V_59 = (struct V_19 * ) ( ( V_18 * ) ( V_2 + 1 ) ) ;
for ( V_60 = V_59 , V_38 = 1 ; V_38 < V_86 ;
V_60 ++ , V_38 ++ ) {
F_39 ( & V_60 -> V_80 ) ;
F_40 ( & V_60 -> V_87 , & V_2 -> V_84 ) ;
if ( ! F_9 ( V_2 , V_60 ) ) {
F_3 ( V_16 ,
L_23 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
}
F_33 ( L_24 , V_59 ,
V_60 ,
sizeof( * V_59 ) ,
V_86 ) ;
if ( F_16 ( V_2 ) != 0 ) {
F_3 ( V_16 , L_25 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
V_2 -> V_43 = V_43 ;
F_41 ( & V_2 -> V_88 ) ;
F_41 ( & V_2 -> V_89 ) ;
F_23 ( V_90 , & V_2 -> V_47 ) ;
F_23 ( V_91 , & V_2 -> V_47 ) ;
F_23 ( V_92 , & V_2 -> V_47 ) ;
F_23 ( V_93 , & V_2 -> V_47 ) ;
V_2 -> V_94 = V_95 ;
V_2 -> V_96 = 128 ;
V_2 -> V_97 = V_98 ;
F_21 ( V_2 , V_46 ) ;
V_2 -> V_99 = F_42 ( V_2 ) ;
V_2 -> V_100 = F_2 ( & V_11 -> V_12 ,
( V_13 ) V_2 -> V_99 ,
( V_14 * ) & V_57 ,
V_15 ) ;
if ( V_2 -> V_100 == NULL ) {
F_3 ( V_16 ,
L_26 ,
V_2 -> V_99 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
V_2 -> V_101 = V_57 ;
F_33 ( L_27 ,
V_2 -> V_99 ,
V_2 -> V_100 ,
F_43 ( V_57 ) ,
F_44 ( V_57 ) ) ;
memset ( V_2 -> V_100 , 0 , V_2 -> V_99 ) ;
V_58 = V_2 -> V_100 ;
if ( ! F_45 ( V_2 ,
& V_58 ) ) {
F_3 ( V_16 ,
L_28 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
F_46 ( & V_2 -> V_102 ,
V_103 ,
( unsigned long ) V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( ! F_49 ( V_2 , true ) )
F_3 ( V_16 , L_29 ) ;
else
F_33 ( L_30 ) ;
F_24 ( V_2 ) ;
if ( F_50 ( V_53 , & V_2 -> V_45 ) )
F_51 ( V_2 ) ;
F_23 ( V_104 , & V_2 -> V_45 ) ;
if ( ! F_50 ( V_105 , & V_2 -> V_47 ) )
F_52 ( V_2 ) ;
F_33 ( L_31 ,
V_2 , V_2 -> V_89 ) ;
return 1 ;
}
static void F_53 ( struct V_1 * V_2 ,
int V_106 )
{
struct V_3 * V_21 , * V_107 ;
if ( ( F_50 ( V_104 , & V_2 -> V_45 ) )
&& ( ! F_50 ( V_105 , & V_2 -> V_47 ) ) ) {
if ( ! V_106 ) {
F_54 ( & V_2 -> V_108 ) ;
F_55 ( & V_2 -> V_102 ) ;
}
F_56 ( V_2 ) ;
F_57 ( 500 ) ;
F_33 ( L_32 ) ;
}
if ( V_2 -> V_109 ) {
F_58 ( & V_2 -> V_55 -> V_110 . V_111 , & V_112 ) ;
V_2 -> V_109 = 0 ;
}
if ( V_2 -> V_113 ) {
F_58 ( & V_2 -> V_55 -> V_110 . V_111 , & V_114 ) ;
V_2 -> V_113 = 0 ;
}
if ( V_2 -> V_115 ) {
F_58 ( & V_2 -> V_55 -> V_110 . V_111 , & V_116 ) ;
V_2 -> V_115 = 0 ;
}
if ( V_2 -> V_117 ) {
F_58 ( & V_2 -> V_55 -> V_110 . V_111 , & V_118 ) ;
V_2 -> V_117 = 0 ;
}
if ( V_2 -> V_119 ) {
F_58 ( & V_2 -> V_55 -> V_110 . V_111 ,
& V_120 ) ;
V_2 -> V_119 = 0 ;
}
if ( V_2 -> V_121 ) {
F_58 ( & V_2 -> V_55 -> V_110 . V_111 ,
& V_122 ) ;
V_2 -> V_121 = 0 ;
}
if ( F_50 ( V_53 , & V_2 -> V_45 ) ) {
F_31 ( V_49 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_33 , V_2 -> V_11 -> V_50 ) ;
F_59 ( V_2 -> V_11 -> V_50 , V_2 ) ;
F_33 ( L_34 ) ;
F_60 ( V_53 , & V_2 -> V_45 ) ;
}
if ( F_50 ( V_44 , & V_2 -> V_45 ) ) {
F_61 ( V_2 -> V_11 ) ;
F_60 ( V_44 , & V_2 -> V_45 ) ;
F_33 ( L_35 ) ;
}
if ( V_2 -> V_123 . V_8 )
F_6 ( V_2 , & V_2 -> V_123 ) ;
if ( V_2 -> V_124 . V_8 )
F_6 ( V_2 , & V_2 -> V_124 ) ;
F_62 (memdesc, next, &a->free_sg_list_head,
next_desc) {
F_6 ( V_2 , V_21 ) ;
}
F_62 (memdesc, next, &a->vrq_mds_head, next_desc) {
F_6 ( V_2 , V_21 ) ;
F_63 ( & V_21 -> V_25 ) ;
F_8 ( V_21 ) ;
}
F_8 ( V_2 -> V_125 ) ;
V_2 -> V_125 = NULL ;
F_8 ( V_2 -> V_126 ) ;
V_2 -> V_126 = NULL ;
F_8 ( V_2 -> V_127 ) ;
V_2 -> V_127 = NULL ;
if ( V_2 -> V_31 ) {
F_13 ( V_2 ) ;
V_2 -> V_31 = NULL ;
V_2 -> V_33 = NULL ;
F_33 ( L_36 ) ;
}
}
void F_32 ( int V_38 )
{
struct V_1 * V_2 = V_62 [ V_38 ] ;
if ( V_2 ) {
unsigned long V_47 ;
struct V_128 * V_129 ;
F_33 ( L_37 , V_2 , V_38 ) ;
F_36 ( V_2 ) ;
F_53 ( V_2 , 0 ) ;
if ( V_130 &&
( V_2 -> V_11 == V_131 ) ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_132 ,
V_130 ,
V_133 ) ;
V_130 = NULL ;
}
if ( V_2 -> V_134 ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_135 ,
V_2 -> V_134 ,
( V_14 ) V_2 -> V_136 ) ;
V_2 -> V_134 = NULL ;
}
if ( V_2 -> V_137 ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_2 -> V_138 ,
V_2 -> V_137 ,
( V_14 ) V_2 -> V_139 ) ;
V_2 -> V_137 = NULL ;
}
F_8 ( V_2 -> V_140 ) ;
V_2 -> V_140 = NULL ;
F_64 ( & V_2 -> V_67 , V_47 ) ;
V_129 = V_2 -> V_73 ;
V_2 -> V_73 = NULL ;
F_65 ( & V_2 -> V_67 , V_47 ) ;
if ( V_129 )
F_66 ( V_129 ) ;
if ( V_2 -> V_100 ) {
F_7 ( & V_2 -> V_11 -> V_12 ,
( V_13 ) V_2 -> V_99 ,
V_2 -> V_100 ,
( V_14 ) V_2 -> V_101 ) ;
V_2 -> V_100 = NULL ;
F_33 ( L_38 ) ;
}
F_31 ( V_49 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_39
L_40 ,
V_2 -> V_11 -> V_141 ,
V_2 -> V_11 -> V_142 ,
V_2 -> V_11 -> V_50 ,
V_2 -> V_11 -> V_143 ) ;
F_31 ( V_49 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_41 ,
V_2 -> V_11 -> V_144 . V_145 ) ;
F_67 ( V_2 -> V_11 ) ;
F_31 ( V_49 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_42 ,
V_2 -> V_11 -> V_144 . V_145 ) ;
F_31 ( V_49 ,
& ( V_2 -> V_11 -> V_12 ) ,
L_43 ,
V_2 -> V_11 ) ;
F_68 ( V_2 -> V_11 , NULL ) ;
V_62 [ V_38 ] = NULL ;
if ( F_50 ( V_104 , & V_2 -> V_45 ) ) {
F_60 ( V_104 , & V_2 -> V_45 ) ;
F_23 ( V_105 , & V_2 -> V_47 ) ;
F_31 ( V_49 ,
& ( V_2 -> V_55 -> V_146 ) ,
L_44 ) ;
F_69 ( V_2 -> V_55 ) ;
F_31 ( V_49 ,
& ( V_2 -> V_55 -> V_146 ) ,
L_45 ) ;
F_70 ( V_2 -> V_55 ) ;
}
}
}
int F_71 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_55 == NULL ) {
int V_38 ;
F_33 ( L_46 ) ;
for ( V_38 = 0 ; V_38 < V_61 ; V_38 ++ )
F_32 ( V_38 ) ;
return - 1 ;
}
F_33 ( L_47 , V_55 ) ;
V_2 = (struct V_1 * ) V_55 -> V_63 ;
V_43 = V_2 -> V_43 ;
F_32 ( V_43 ) ;
return V_43 ;
}
int F_72 ( struct V_56 * V_147 , T_4 V_148 )
{
struct V_54 * V_55 = F_73 ( V_147 ) ;
T_1 V_149 ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_63 ;
F_31 ( V_49 , & ( V_147 -> V_12 ) , L_48 ) ;
if ( ! V_2 )
return - V_150 ;
F_53 ( V_2 , 1 ) ;
V_149 = F_74 ( V_147 , V_148 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) ,
L_49 ) ;
F_75 ( V_147 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) ,
L_50 ) ;
F_67 ( V_147 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) ,
L_51 ) ;
F_76 ( V_147 , V_149 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) , L_52 ) ;
return 0 ;
}
int F_77 ( struct V_56 * V_147 )
{
struct V_54 * V_55 = F_73 ( V_147 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_55 -> V_63 ;
int V_151 ;
F_31 ( V_49 , & ( V_147 -> V_12 ) , L_53 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) ,
L_54
L_55 ) ;
F_76 ( V_147 , V_152 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) ,
L_56
L_55 ) ;
F_78 ( V_147 , V_152 , 0 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) ,
L_57 ) ;
F_79 ( V_147 ) ;
F_31 ( V_49 , & ( V_147 -> V_12 ) ,
L_58 ) ;
V_151 = F_80 ( V_147 ) ;
F_81 ( V_147 ) ;
if ( ! V_2 ) {
V_151 = - V_150 ;
goto V_153;
}
if ( F_16 ( V_2 ) != 0 ) {
F_3 ( V_16 , L_59 ) ;
V_151 = - V_154 ;
goto V_153;
}
F_21 ( V_2 , V_2 -> V_37 ) ;
F_47 ( V_2 ) ;
if ( ! F_82 ( V_2 , true ) ) {
F_33 ( L_60 ) ;
V_151 = - V_154 ;
goto V_153;
}
F_24 ( V_2 ) ;
if ( F_50 ( V_53 , & V_2 -> V_45 ) ) {
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
} else {
F_33 ( L_61 ) ;
F_3 ( V_16 , L_62 ) ;
V_151 = - V_154 ;
goto V_153;
}
V_153:
F_31 ( V_16 , & ( V_147 -> V_12 ) , L_63 ,
V_151 ) ;
return V_151 ;
}
bool F_83 ( struct V_1 * V_2 , char * V_155 )
{
F_23 ( V_105 , & V_2 -> V_47 ) ;
F_3 ( V_16 ,
L_64 , V_155 ) ;
return false ;
}
T_1 F_42 ( struct V_1 * V_2 )
{
return sizeof( struct V_156 )
+ F_5 ( V_157 , 8 )
+ F_5 ( sizeof( T_1 ) , 8 )
+ 8
+ ( V_158 * ( V_159 ) V_160 )
+ F_5 ( ( V_86 + V_161 + 1 +
V_162 ) *
sizeof( struct V_163 ) ,
8 )
+ F_5 ( ( V_86 + V_161 + 1 +
V_162 ) *
sizeof( struct V_164 ) , 8 )
+ 256 ;
}
static void F_84 ( struct V_1 * V_2 )
{
int V_165 ;
V_165 = F_85 ( V_2 -> V_11 , V_166 ) ;
if ( V_165 ) {
V_159 V_167 ;
F_86 ( V_2 -> V_11 , V_165 + V_168 ,
& V_167 ) ;
if ( ( V_167 & V_169 ) >
V_170 ) {
F_3 ( V_49 ,
L_65 ) ;
V_167 &= ~ V_169 ;
V_167 |= V_170 ;
F_87 ( V_2 -> V_11 ,
V_165 + V_168 ,
V_167 ) ;
}
}
}
bool F_45 ( struct V_1 * V_2 ,
void * * V_171 )
{
T_1 V_38 ;
V_18 * V_172 ;
struct V_163 * V_173 ;
struct V_19 * V_20 ;
struct V_3 * V_174 ;
F_34 ( & V_2 -> V_175 ) ;
F_34 ( & V_2 -> V_176 ) ;
F_34 ( & V_2 -> V_177 ) ;
V_2 -> V_178 = & V_2 -> V_179 [ V_180 ] ;
if ( ! F_9 ( V_2 , & V_2 -> V_79 ) ) {
F_11 (
L_66 ) ;
return false ;
}
V_2 -> V_125 =
F_10 ( V_161 * sizeof( struct V_19 ) ,
V_15 ) ;
if ( V_2 -> V_125 == NULL ) {
F_3 ( V_16 ,
L_67 ) ;
return false ;
}
V_2 -> V_126 = F_10 (
V_158 * sizeof( struct V_3 ) , V_15 ) ;
if ( V_2 -> V_126 == NULL ) {
F_3 ( V_16 ,
L_68 ) ;
return false ;
}
V_2 -> V_127 =
F_10 ( ( V_86 + V_161 +
1 ) * sizeof( struct V_19 * ) , V_15 ) ;
if ( V_2 -> V_127 == NULL ) {
F_3 ( V_16 ,
L_69 ) ;
return false ;
}
F_84 ( V_2 ) ;
if ( ( V_2 -> V_11 -> V_181 == V_182 )
&& ( V_2 -> V_11 -> V_183 & V_184 ) )
V_2 -> V_45 |= V_185 ;
if ( F_50 ( V_185 , & V_2 -> V_45 ) )
V_2 -> V_45 |= V_186 ;
if ( V_2 -> V_11 -> V_183 == V_187 )
V_2 -> V_45 |= V_188 ;
V_172 = ( V_18 * ) * V_171 ;
for ( V_38 = 0 , V_174 = V_2 -> V_126 ; V_38 < V_158 ; V_38 ++ , V_174 ++ ) {
V_174 -> V_7 = V_160 ;
F_40 ( & V_174 -> V_25 , & V_2 -> V_83 ) ;
if ( ! F_1 ( V_2 , V_174 , V_189 ) ) {
if ( V_38 < V_190 )
return false ;
break;
}
}
V_2 -> V_191 = V_86 + V_162 ;
V_2 -> V_123 . V_7 = V_2 -> V_191 *
sizeof( struct
V_163 ) ;
if ( ! F_1 ( V_2 , & V_2 -> V_123 , V_192 ) ) {
F_11 ( L_70 ) ;
return false ;
}
V_2 -> V_124 . V_7 = V_2 -> V_191 *
sizeof( struct V_164 ) ;
if ( ! F_1 ( V_2 , & V_2 -> V_124 ,
V_192 ) ) {
F_11 ( L_70 ) ;
return false ;
}
V_2 -> V_193 = (struct V_156 * ) V_172 ;
V_172 += sizeof( struct V_156 ) ;
V_2 -> V_194 = V_172 ;
V_172 += V_157 ;
V_172 = F_4 ( V_172 , 8 ) ;
V_2 -> V_195 = ( T_1 volatile * ) V_172 ;
V_172 += sizeof( T_1 ) ;
if ( ! F_50 ( V_196 , & V_2 -> V_47 ) )
F_88 ( V_2 ) ;
* V_171 = ( void * ) V_172 ;
if ( F_50 ( V_92 , & V_2 -> V_47 ) ) {
memset ( V_2 -> V_127 , 0 ,
( V_86 + V_161 +
1 ) * sizeof( struct V_19 * ) ) ;
F_89 ( V_2 ) ;
V_173 =
(struct V_163 * ) V_2 ->
V_123 .
V_8 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_191 ; V_38 ++ ) {
V_173 -> V_197 = 0 ;
V_173 -> V_198 = 0 ;
V_173 -> V_199 = F_90 ( V_200
| ( sizeof( union
V_22 )
/
sizeof( T_1 ) ) ) ;
V_173 ++ ;
}
for ( V_20 = V_2 -> V_125 , V_38 = 0 ; V_38 < V_161 ; V_20 ++ ,
V_38 ++ ) {
F_39 ( & V_20 -> V_80 ) ;
if ( ! F_9 ( V_2 , V_20 ) ) {
F_11 (
L_23 ) ;
return false ;
}
F_91 ( V_20 , V_2 ) ;
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
if ( F_50 ( V_207 , & V_2 -> V_47 ) )
goto V_208;
F_92 ( V_2 , V_209 , V_210 ) ;
F_93 ( V_2 , V_209 ) ;
V_203 = F_94 ( V_211 ) ;
while ( true ) {
F_95 ( V_2 ) ;
V_204 = F_96 ( V_2 , V_212 ) ;
if ( V_204 == 0xFFFFFFFF ) {
if ( ( F_94 ( V_211 ) - V_203 ) > 2000 )
return F_83 ( V_2 ,
L_71 ) ;
} else if ( V_204 & V_213 ) {
T_1 V_214 = ( V_204 & V_215 ) ;
F_92 ( V_2 , V_212 ,
V_204 ) ;
if ( V_214 == V_216 ) {
F_23 ( V_93 , & V_2 -> V_47 ) ;
V_2 -> V_96 = 128 ;
V_2 -> V_97 = V_98 ;
} else if ( V_214 == V_217 ) {
F_60 ( V_93 , & V_2 -> V_47 ) ;
V_2 -> V_96 = 1024 ;
V_2 -> V_97 = V_218 ;
} else {
return F_83 ( V_2 ,
L_72 ) ;
}
break;
}
F_97 ( F_98 ( 100 ) ) ;
if ( ( F_94 ( V_211 ) - V_203 ) > 180000 ) {
F_11 ( L_73 ) ;
F_99 () ;
return F_83 ( V_2 ,
L_74 ) ;
}
}
F_92 ( V_2 , V_219 , V_220 ) ;
V_203 = F_94 ( V_211 ) ;
while ( true ) {
V_204 = F_96 ( V_2 , V_212 ) ;
if ( V_204 & V_220 ) {
F_92 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_97 ( F_98 ( 50 ) ) ;
if ( ( F_94 ( V_211 ) - V_203 ) > 3000 ) {
F_11 ( L_75 ) ;
break;
}
}
V_208:
V_206 = F_96 ( V_2 , V_221 ) ;
V_206 &= ~ V_222 ;
F_92 ( V_2 , V_221 , V_206 ) ;
V_206 = F_96 ( V_2 , V_223 ) ;
V_206 &= ~ V_224 ;
F_92 ( V_2 , V_223 , V_206 ) ;
V_205 = V_2 -> V_123 . V_9 ;
F_92 ( V_2 , V_225 ,
F_44 ( V_205 ) ) ;
F_92 ( V_2 , V_226 ,
F_43 ( V_205 ) ) ;
V_205 = V_2 -> V_124 . V_9 ;
F_92 ( V_2 , V_227 ,
F_44 ( V_205 ) ) ;
F_92 ( V_2 , V_228 ,
F_43 ( V_205 ) ) ;
V_205 = V_2 -> V_101 +
( ( V_18 * ) V_2 -> V_195 - V_2 -> V_100 ) ;
F_92 ( V_2 , V_229 ,
F_44 ( V_205 ) ) ;
F_92 ( V_2 , V_230 ,
F_43 ( V_205 ) ) ;
* V_2 -> V_195 =
V_2 -> V_231 =
V_2 -> V_232 = V_2 -> V_191 - 1 ;
F_23 ( V_233 , & V_2 -> V_47 ) ;
F_92 ( V_2 , V_234 , V_235 |
V_2 -> V_231 ) ;
F_92 ( V_2 , V_236 , V_237 |
V_2 -> V_231 ) ;
F_92 ( V_2 , V_238 , V_239 |
V_2 -> V_231 ) ;
F_92 ( V_2 , V_240 ,
V_241 | V_2 -> V_231 ) ;
V_206 = F_96 ( V_2 , V_242 ) ;
V_206 &= ~ ( V_243 | V_244 ) ;
F_92 ( V_2 , V_242 ,
( V_206 | V_245 | V_246 ) ) ;
V_206 = F_96 ( V_2 , V_247 ) ;
V_206 &= ~ ( V_248 | V_249 ) ;
F_92 ( V_2 , V_247 ,
( V_206 | V_250 |
V_251 ) ) ;
V_206 = F_96 ( V_2 , V_221 ) ;
V_206 &= ~ ( V_252 | V_253 ) ;
V_206 |= V_254 | V_255
| ( V_2 -> V_191 << V_256 ) ;
F_92 ( V_2 , V_221 , V_206 ) ;
V_206 = F_96 ( V_2 , V_223 ) ;
V_206 &= ~ ( V_257 | V_258 ) ;
V_206 |= V_259 | ( V_2 -> V_191 << V_260 ) ;
F_92 ( V_2 , V_223 , V_206 ) ;
F_92 ( V_2 , V_219 , V_261 ) ;
V_203 = F_94 ( V_211 ) ;
while ( true ) {
V_204 = F_96 ( V_2 , V_212 ) ;
if ( V_204 & V_261 ) {
F_92 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_97 ( F_98 ( 100 ) ) ;
if ( ( F_94 ( V_211 ) - V_203 ) > 3000 ) {
F_11 (
L_76 ) ;
F_99 () ;
return F_83 ( V_2 ,
L_76 ) ;
}
}
V_204 = F_96 ( V_2 , V_262 ) ;
if ( V_204 & V_263 )
F_23 ( V_264 , & V_2 -> V_45 ) ;
else
F_60 ( V_264 , & V_2 -> V_45 ) ;
F_92 ( V_2 , V_265 , V_266 ) ;
F_92 ( V_2 , V_267 , V_268 ) ;
return true ;
}
static bool F_100 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_1 V_269 = V_2 -> V_94 ;
struct V_270 * V_271 ;
V_2 -> V_94 = 0 ;
switch ( V_269 ) {
case V_95 :
case V_272 :
{
struct V_273 V_274 ;
F_101 ( & V_274 ) ;
F_11 ( L_77 ) ;
F_102 ( V_2 ,
V_20 ,
V_275 ,
0 ,
NULL ) ;
V_271 = (struct V_270 * ) & V_20 -> V_28 -> V_276 . V_277 . V_278 ;
V_271 -> V_160 = F_90 ( V_160 ) ;
V_271 -> V_279 = F_90 ( V_274 . V_280 ) ;
V_20 -> V_47 |= V_281 ;
V_2 -> V_94 = V_282 ;
break;
}
case V_282 :
if ( V_20 -> V_283 == V_284 ) {
T_1 V_285 ;
T_1 V_286 ;
V_159 V_287 ;
V_2 -> V_288 = F_103 (
V_20 -> V_289 . V_290 . V_291 ) ;
V_2 -> V_292 = V_20 -> V_289 . V_290 . V_292 ;
V_287 = F_103 (
V_20 -> V_289 . V_290 . V_287 ) ;
V_285 = F_104 ( V_287 ) ;
V_286 = F_105 ( V_287 ) ;
V_2 -> V_288 += ( V_285 << 16 ) + ( V_286 << 24 ) ;
} else {
F_11 ( L_78 ) ;
}
if ( ( F_50 ( V_185 , & V_2 -> V_45 ) )
|| ( F_106 ( V_2 -> V_288 ) > 0x00524702 ) ) {
F_11 ( L_79 ) ;
F_102 ( V_2 ,
V_20 ,
V_293 ,
sizeof( struct V_270 ) ,
NULL ) ;
V_20 -> V_28 -> V_276 . V_294 = F_107 (
struct V_295 ,
V_277 . V_296 ) ;
V_20 -> V_28 -> V_276 . V_277 . V_297 . V_298 =
F_90 ( sizeof( struct V_270 ) ) ;
V_20 -> V_28 -> V_276 . V_277 . V_297 . V_197 = F_108 (
V_20 -> V_27 -> V_9 +
sizeof( union V_22 ) ) ;
V_20 -> V_47 |= V_281 ;
V_2 -> V_94 = V_299 ;
break;
}
case V_299 :
if ( V_269 == V_299 ) {
V_271 = (struct V_270 * ) V_20 -> V_300 ;
if ( V_20 -> V_283 == V_284 ) {
V_2 -> V_301 =
F_109 ( V_271 -> V_301 ) ;
V_2 -> V_302 =
F_109 ( V_271 -> V_302 ) ;
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
bool F_110 ( struct V_1 * V_2 )
{
bool V_303 = true ;
struct V_19 * V_20 = & V_2 -> V_79 ;
F_91 ( V_20 , V_2 ) ;
V_20 -> V_201 = V_304 ;
if ( V_2 -> V_94 == 0 )
V_2 -> V_94 = V_272 ;
while ( V_2 -> V_94 ) {
if ( F_100 ( V_2 , V_20 ) ) {
unsigned long V_47 ;
while ( true ) {
F_64 ( & V_2 -> V_177 , V_47 ) ;
F_111 ( V_2 , V_20 ) ;
F_65 ( & V_2 -> V_177 , V_47 ) ;
F_112 ( V_2 , V_20 ) ;
if ( V_20 -> V_283 != V_305 )
break;
}
}
if ( V_20 -> V_283 == V_284
|| ( ( V_20 -> V_47 & V_281 )
&& V_20 -> V_283 != V_306 ) )
continue;
F_3 ( V_16 , L_80 ,
V_2 -> V_94 , V_20 -> V_283 , V_20 -> V_47 ) ;
V_2 -> V_94 = V_95 ;
V_303 = false ;
break;
}
F_113 ( V_20 , V_2 ) ;
return V_303 ;
}
bool F_49 ( struct V_1 * V_2 , bool V_307 )
{
bool V_308 = false ;
struct V_19 * V_20 ;
T_1 V_38 ;
if ( F_50 ( V_105 , & V_2 -> V_47 ) )
goto exit;
if ( ! F_50 ( V_196 , & V_2 -> V_47 ) ) {
if ( ! F_114 ( V_2 ) )
F_3 ( V_42 ,
L_81 ) ;
}
if ( ! F_110 ( V_2 ) ) {
F_83 ( V_2 , L_82 ) ;
goto exit;
}
F_60 ( V_105 , & V_2 -> V_47 ) ;
F_60 ( V_90 , & V_2 -> V_47 ) ;
for ( V_38 = 0 , V_20 = V_2 -> V_125 ; V_38 < V_161 ; V_38 ++ , V_20 ++ )
F_115 ( V_2 , V_20 ) ;
if ( ! V_2 -> V_309 [ 0 ] )
F_116 ( V_2 ) ;
if ( ! V_2 -> V_310 [ 0 ] )
F_117 ( V_2 ) ;
if ( V_2 -> V_288 == 0 )
V_2 -> V_311 [ 0 ] = 0 ;
else
sprintf ( V_2 -> V_311 , L_83 ,
( int ) F_104 ( F_118 ( V_2 -> V_288 ) ) ,
( int ) F_105 ( F_118 ( V_2 -> V_288 ) ) ) ;
F_11 ( L_84 , V_2 -> V_311 ) ;
if ( F_50 ( V_207 , & V_2 -> V_47 )
&& ( F_50 ( V_92 , & V_2 -> V_47 ) ) ) {
F_51 ( V_2 ) ;
return true ;
}
F_119 ( V_2 ) ;
if ( V_307 ) {
T_1 V_312 = V_2 -> V_313 ;
T_1 V_314 = 100 ;
T_1 V_315 ;
F_23 ( V_316 , & V_2 -> V_47 ) ;
F_23 ( V_317 , & V_2 -> V_47 ) ;
if ( F_50 ( V_92 , & V_2 -> V_47 ) )
F_120 ( & V_2 -> V_89 ) ;
while ( F_50 ( V_91 , & V_2 -> V_47 ) ) {
F_97 ( F_98 ( 100 ) ) ;
V_315 = F_94 ( V_211 ) - V_312 ;
V_312 += V_315 ;
if ( ! F_50 ( V_90 , & V_2 -> V_47 ) )
F_121 ( V_2 ) ;
if ( V_314 <= V_315 ) {
V_314 += 100 ;
F_122 ( V_2 ) ;
}
if ( V_314 > V_315 )
V_314 -= V_315 ;
if ( F_123 ( V_2 ) )
F_124 ( V_2 ) ;
}
if ( F_50 ( V_92 , & V_2 -> V_47 ) )
F_41 ( & V_2 -> V_89 ) ;
F_60 ( V_317 , & V_2 -> V_47 ) ;
F_60 ( V_316 , & V_2 -> V_47 ) ;
}
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> V_318 = V_319 ;
F_51 ( V_2 ) ;
F_127 ( V_2 ) ;
V_308 = true ;
exit:
if ( F_50 ( V_207 , & V_2 -> V_47 ) &&
F_50 ( V_92 , & V_2 -> V_47 ) ) {
if ( ! V_308 )
F_60 ( V_90 , & V_2 -> V_47 ) ;
} else {
if ( ! V_308 ) {
F_60 ( V_90 , & V_2 -> V_47 ) ;
F_60 ( V_91 , & V_2 -> V_47 ) ;
}
if ( F_50 ( V_92 , & V_2 -> V_47 ) ) {
F_60 ( V_92 , & V_2 -> V_47 ) ;
if ( F_128 ( & V_2 -> V_89 ) == 0 )
F_129 ( V_2 ) ;
}
}
return V_308 ;
}
void F_130 ( struct V_1 * V_2 )
{
F_23 ( V_320 , & V_2 -> V_47 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
if ( ! F_134 ( V_2 ) )
return;
if ( F_50 ( V_321 , & V_2 -> V_45 ) &&
! F_50 ( V_322 , & V_2 -> V_45 ) ) {
F_135 ( V_2 ,
V_2 -> V_323 ,
V_324 + 0x80000 ,
V_325 ) ;
F_23 ( V_322 , & V_2 -> V_45 ) ;
}
F_60 ( V_321 , & V_2 -> V_45 ) ;
if ( V_2 -> V_11 -> V_326 == V_327 )
F_92 ( V_2 , V_328 ,
V_329 ) ;
else
F_92 ( V_2 , V_330 ,
V_331 ) ;
F_57 ( 10 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
T_1 V_203 ;
T_1 V_204 ;
F_92 ( V_2 , V_219 , V_263 ) ;
V_203 = F_94 ( V_211 ) ;
while ( true ) {
V_204 = F_96 ( V_2 , V_212 ) ;
if ( V_204 & V_263 ) {
F_92 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_97 ( F_98 ( 100 ) ) ;
if ( ( F_94 ( V_211 ) - V_203 ) > 30000 ) {
F_11 ( L_85 ) ;
break;
}
}
}
void F_56 ( struct V_1 * V_2 )
{
F_23 ( V_332 , & V_2 -> V_47 ) ;
F_23 ( V_333 , & V_2 -> V_47 ) ;
if ( ! F_50 ( V_105 , & V_2 -> V_47 ) ) {
T_1 V_203 ;
T_1 V_204 ;
F_47 ( V_2 ) ;
F_137 ( V_2 ) ;
F_92 ( V_2 , V_219 ,
V_220 ) ;
V_203 = F_94 ( V_211 ) ;
while ( true ) {
V_204 =
F_96 ( V_2 , V_212 ) ;
if ( V_204 & V_220 ) {
F_92 ( V_2 , V_212 ,
V_204 ) ;
break;
}
F_97 ( F_98 ( 100 ) ) ;
if ( ( F_94 ( V_211 ) - V_203 ) > 3000 ) {
F_11 (
L_75 ) ;
break;
}
}
if ( F_50 ( V_264 , & V_2 -> V_45 ) )
F_136 ( V_2 ) ;
}
F_23 ( V_320 , & V_2 -> V_47 ) ;
F_23 ( V_91 , & V_2 -> V_47 ) ;
F_23 ( V_90 , & V_2 -> V_47 ) ;
F_138 ( V_2 ) ;
V_2 -> V_334 = F_139 ( V_2 ) ;
F_140 ( V_2 , false ) ;
}
bool F_82 ( struct V_1 * V_2 , bool V_307 )
{
bool V_335 ;
F_60 ( V_333 , & V_2 -> V_47 ) ;
F_84 ( V_2 ) ;
F_23 ( V_92 , & V_2 -> V_47 ) ;
F_41 ( & V_2 -> V_89 ) ;
V_335 = F_48 ( V_2 ) ;
if ( ! F_49 ( V_2 , V_307 ) )
V_335 = false ;
F_141 ( V_2 , true ) ;
F_60 ( V_332 , & V_2 -> V_47 ) ;
return V_335 ;
}
bool F_134 ( struct V_1 * V_2 )
{
if ( F_50 ( V_336 , & V_2 -> V_47 ) )
return false ;
if ( F_96 ( V_2 , V_212 ) == 0xFFFFFFFF ) {
F_23 ( V_336 , & V_2 -> V_47 ) ;
return false ;
}
return true ;
}
const char * F_142 ( struct V_1 * V_2 )
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
const char * F_143 ( struct V_1 * V_2 )
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
