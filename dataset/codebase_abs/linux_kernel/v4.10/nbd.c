static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static bool F_3 ( struct V_2 * V_3 )
{
return ! ! V_3 -> V_5 ;
}
static const char * F_4 ( int V_6 )
{
switch ( V_6 ) {
case V_7 : return L_1 ;
case V_8 : return L_2 ;
case V_9 : return L_3 ;
case V_10 : return L_4 ;
case V_11 : return L_5 ;
}
return L_6 ;
}
static int F_5 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
V_13 -> V_14 -> V_15 = 0 ;
F_6 ( V_3 -> V_4 , 0 ) ;
F_7 ( & F_1 ( V_3 ) -> V_16 , V_17 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( ! F_3 ( V_3 ) )
return;
V_13 -> V_14 -> V_15 = V_3 -> V_18 ;
F_6 ( V_3 -> V_4 , V_3 -> V_18 >> 9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_16 , V_17 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_12 * V_13 ,
T_1 V_19 , T_1 V_20 )
{
int V_21 ;
V_21 = F_10 ( V_13 , V_19 ) ;
if ( V_21 )
return V_21 ;
V_3 -> V_22 = V_19 ;
V_3 -> V_18 = V_19 * V_20 ;
F_8 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_11 ( struct V_23 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_24 * V_25 = F_12 ( V_6 ) ;
int error = V_25 -> V_26 ? - V_27 : 0 ;
F_13 ( F_1 ( V_3 ) , L_7 , V_6 ,
error ? L_8 : L_9 ) ;
F_14 ( V_25 , error ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
int V_28 ;
if ( V_3 -> V_29 == 0 )
return;
if ( F_16 ( V_30 , & V_3 -> V_31 ) )
return;
for ( V_28 = 0 ; V_28 < V_3 -> V_29 ; V_28 ++ ) {
struct V_32 * V_33 = V_3 -> V_34 [ V_28 ] ;
F_17 ( & V_33 -> V_35 ) ;
F_18 ( V_33 -> V_36 , V_37 ) ;
F_19 ( & V_33 -> V_35 ) ;
}
F_20 ( F_2 ( V_3 -> V_4 ) , L_10 ) ;
}
static enum V_38 F_21 ( struct V_24 * V_25 ,
bool V_39 )
{
struct V_23 * V_6 = F_22 ( V_25 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
F_23 ( F_1 ( V_3 ) , L_11 ) ;
F_24 ( V_40 , & V_3 -> V_31 ) ;
V_25 -> V_26 ++ ;
if ( V_25 -> V_41 == V_42 )
return V_43 ;
F_17 ( & V_3 -> V_44 ) ;
F_15 ( V_3 ) ;
F_19 ( & V_3 -> V_44 ) ;
return V_43 ;
}
static int F_25 ( struct V_2 * V_3 , int V_45 , int V_46 , void * V_47 ,
int V_48 , int V_49 )
{
struct V_50 * V_36 = V_3 -> V_34 [ V_45 ] -> V_36 ;
int V_51 ;
struct V_52 V_53 ;
struct V_54 V_55 ;
unsigned long V_56 = V_57 -> V_58 ;
if ( F_26 ( ! V_36 ) ) {
F_27 ( F_2 ( V_3 -> V_4 ) ,
L_12 ,
( V_46 ? L_13 : L_14 ) ) ;
return - V_59 ;
}
V_57 -> V_58 |= V_60 ;
do {
V_36 -> V_61 -> V_62 = V_63 | V_64 ;
V_55 . V_65 = V_47 ;
V_55 . V_66 = V_48 ;
V_53 . V_67 = NULL ;
V_53 . V_68 = 0 ;
V_53 . V_69 = NULL ;
V_53 . V_70 = 0 ;
V_53 . V_49 = V_49 | V_71 ;
if ( V_46 )
V_51 = F_28 ( V_36 , & V_53 , & V_55 , 1 , V_48 ) ;
else
V_51 = F_29 ( V_36 , & V_53 , & V_55 , 1 , V_48 ,
V_53 . V_49 ) ;
if ( V_51 <= 0 ) {
if ( V_51 == 0 )
V_51 = - V_72 ;
break;
}
V_48 -= V_51 ;
V_47 += V_51 ;
} while ( V_48 > 0 );
F_30 ( V_57 , V_56 , V_60 ) ;
return V_51 ;
}
static inline int F_31 ( struct V_2 * V_3 , int V_45 ,
struct V_73 * V_74 , int V_58 )
{
int V_51 ;
void * V_75 = F_32 ( V_74 -> V_76 ) ;
V_51 = F_25 ( V_3 , V_45 , 1 , V_75 + V_74 -> V_77 ,
V_74 -> V_78 , V_58 ) ;
F_33 ( V_74 -> V_76 ) ;
return V_51 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_23 * V_6 , int V_45 )
{
struct V_24 * V_25 = F_12 ( V_6 ) ;
int V_51 ;
struct V_79 V_24 ;
unsigned long V_48 = F_35 ( V_25 ) ;
struct V_80 * V_80 ;
T_2 type ;
T_2 V_81 = F_36 ( V_25 ) ;
if ( F_37 ( V_25 ) == V_82 )
type = V_11 ;
else if ( F_37 ( V_25 ) == V_83 )
type = V_10 ;
else if ( F_38 ( V_25 ) == V_84 )
type = V_8 ;
else
type = V_7 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_85 = F_39 ( V_86 ) ;
V_24 . type = F_39 ( type ) ;
if ( type != V_10 ) {
V_24 . V_87 = F_40 ( ( V_88 ) F_41 ( V_25 ) << 9 ) ;
V_24 . V_89 = F_39 ( V_48 ) ;
}
memcpy ( V_24 . V_90 , & V_81 , sizeof( V_81 ) ) ;
F_13 ( F_1 ( V_3 ) , L_15 ,
V_6 , F_4 ( type ) ,
( unsigned long long ) F_41 ( V_25 ) << 9 , F_35 ( V_25 ) ) ;
V_51 = F_25 ( V_3 , V_45 , 1 , & V_24 , sizeof( V_24 ) ,
( type == V_8 ) ? V_91 : 0 ) ;
if ( V_51 <= 0 ) {
F_27 ( F_2 ( V_3 -> V_4 ) ,
L_16 , V_51 ) ;
return - V_27 ;
}
if ( type != V_8 )
return 0 ;
V_80 = V_25 -> V_80 ;
while ( V_80 ) {
struct V_80 * V_92 = V_80 -> V_93 ;
struct V_94 V_95 ;
struct V_73 V_74 ;
F_42 (bvec, bio, iter) {
bool V_96 = ! V_92 && F_43 ( V_74 , V_95 ) ;
int V_58 = V_96 ? 0 : V_91 ;
F_13 ( F_1 ( V_3 ) , L_17 ,
V_6 , V_74 . V_78 ) ;
V_51 = F_31 ( V_3 , V_45 , & V_74 , V_58 ) ;
if ( V_51 <= 0 ) {
F_23 ( F_2 ( V_3 -> V_4 ) ,
L_18 ,
V_51 ) ;
return - V_27 ;
}
if ( V_96 )
break;
}
V_80 = V_92 ;
}
return 0 ;
}
static inline int F_44 ( struct V_2 * V_3 , int V_45 ,
struct V_73 * V_74 )
{
int V_51 ;
void * V_75 = F_32 ( V_74 -> V_76 ) ;
V_51 = F_25 ( V_3 , V_45 , 0 , V_75 + V_74 -> V_77 ,
V_74 -> V_78 , V_97 ) ;
F_33 ( V_74 -> V_76 ) ;
return V_51 ;
}
static struct V_23 * F_45 ( struct V_2 * V_3 , int V_45 )
{
int V_51 ;
struct V_98 V_99 ;
struct V_23 * V_6 ;
struct V_24 * V_25 = NULL ;
T_3 V_100 ;
T_2 V_81 ;
V_99 . V_85 = 0 ;
V_51 = F_25 ( V_3 , V_45 , 0 , & V_99 , sizeof( V_99 ) , V_97 ) ;
if ( V_51 <= 0 ) {
if ( ! F_46 ( V_30 , & V_3 -> V_31 ) &&
! F_46 ( V_101 , & V_3 -> V_31 ) )
F_23 ( F_2 ( V_3 -> V_4 ) ,
L_19 , V_51 ) ;
return F_47 ( V_51 ) ;
}
if ( F_48 ( V_99 . V_85 ) != V_102 ) {
F_23 ( F_2 ( V_3 -> V_4 ) , L_20 ,
( unsigned long ) F_48 ( V_99 . V_85 ) ) ;
return F_47 ( - V_103 ) ;
}
memcpy ( & V_81 , V_99 . V_90 , sizeof( T_2 ) ) ;
V_100 = F_49 ( V_81 ) ;
if ( V_100 < V_3 -> V_104 . V_105 )
V_25 = F_50 ( V_3 -> V_104 . V_106 [ V_100 ] ,
F_51 ( V_81 ) ) ;
if ( ! V_25 || ! F_52 ( V_25 ) ) {
F_23 ( F_2 ( V_3 -> V_4 ) , L_21 ,
V_81 , V_25 ) ;
return F_47 ( - V_107 ) ;
}
V_6 = F_22 ( V_25 ) ;
if ( F_48 ( V_99 . error ) ) {
F_23 ( F_2 ( V_3 -> V_4 ) , L_22 ,
F_48 ( V_99 . error ) ) ;
V_25 -> V_26 ++ ;
return V_6 ;
}
F_13 ( F_1 ( V_3 ) , L_23 , V_6 ) ;
if ( F_38 ( V_25 ) != V_84 ) {
struct V_108 V_95 ;
struct V_73 V_74 ;
F_53 (bvec, req, iter) {
V_51 = F_44 ( V_3 , V_45 , & V_74 ) ;
if ( V_51 <= 0 ) {
F_23 ( F_2 ( V_3 -> V_4 ) , L_24 ,
V_51 ) ;
V_25 -> V_26 ++ ;
return V_6 ;
}
F_13 ( F_1 ( V_3 ) , L_25 ,
V_6 , V_74 . V_78 ) ;
}
} else {
F_54 ( & V_6 -> V_109 ) ;
}
return V_6 ;
}
static T_4 F_55 ( struct V_1 * V_110 ,
struct V_111 * V_112 , char * V_47 )
{
struct V_113 * V_4 = F_56 ( V_110 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_4 -> V_114 ;
return sprintf ( V_47 , L_26 , F_57 ( V_3 -> V_5 ) ) ;
}
static void F_58 ( struct V_115 * V_116 )
{
struct V_117 * args = F_59 ( V_116 ,
struct V_117 ,
V_116 ) ;
struct V_2 * V_3 = args -> V_3 ;
struct V_23 * V_6 ;
int V_21 = 0 ;
F_60 ( V_3 -> V_85 != V_118 ) ;
while ( 1 ) {
V_6 = F_45 ( V_3 , args -> V_45 ) ;
if ( F_61 ( V_6 ) ) {
V_21 = F_62 ( V_6 ) ;
break;
}
F_11 ( V_6 ) ;
}
if ( V_21 && ! F_46 ( V_101 , & V_3 -> V_31 ) )
F_15 ( V_3 ) ;
F_63 ( & V_3 -> V_119 ) ;
F_64 ( & V_3 -> V_120 ) ;
}
static void F_65 ( struct V_24 * V_25 , void * V_121 , bool V_39 )
{
struct V_23 * V_6 ;
if ( ! F_52 ( V_25 ) )
return;
V_6 = F_22 ( V_25 ) ;
V_25 -> V_26 ++ ;
F_11 ( V_6 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
F_60 ( V_3 -> V_85 != V_118 ) ;
F_67 ( & V_3 -> V_104 , F_65 , NULL ) ;
F_13 ( F_2 ( V_3 -> V_4 ) , L_27 ) ;
}
static void F_68 ( struct V_23 * V_6 , int V_45 )
{
struct V_24 * V_25 = F_12 ( V_6 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_32 * V_33 ;
if ( V_45 >= V_3 -> V_29 ) {
F_27 ( F_2 ( V_3 -> V_4 ) ,
L_28 ) ;
goto V_122;
}
if ( F_46 ( V_30 , & V_3 -> V_31 ) ) {
F_27 ( F_2 ( V_3 -> V_4 ) ,
L_29 ) ;
goto V_122;
}
if ( V_25 -> V_41 != V_123 &&
V_25 -> V_41 != V_42 )
goto V_122;
if ( V_25 -> V_41 == V_123 &&
F_38 ( V_25 ) == V_84 &&
( V_3 -> V_58 & V_124 ) ) {
F_27 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
goto V_122;
}
V_25 -> V_26 = 0 ;
V_33 = V_3 -> V_34 [ V_45 ] ;
F_17 ( & V_33 -> V_35 ) ;
if ( F_26 ( ! V_33 -> V_36 ) ) {
F_19 ( & V_33 -> V_35 ) ;
F_27 ( F_2 ( V_3 -> V_4 ) ,
L_29 ) ;
goto V_122;
}
if ( F_34 ( V_3 , V_6 , V_45 ) != 0 ) {
F_27 ( F_2 ( V_3 -> V_4 ) ,
L_31 ) ;
V_25 -> V_26 ++ ;
F_11 ( V_6 ) ;
}
F_19 ( & V_33 -> V_35 ) ;
return;
V_122:
V_25 -> V_26 ++ ;
F_11 ( V_6 ) ;
}
static int F_69 ( struct V_125 * V_126 ,
const struct V_127 * V_128 )
{
struct V_23 * V_6 = F_22 ( V_128 -> V_129 ) ;
F_70 ( & V_6 -> V_109 ) ;
F_71 ( V_128 -> V_129 ) ;
F_68 ( V_6 , V_126 -> V_130 ) ;
F_72 ( & V_6 -> V_109 ) ;
return V_131 ;
}
static int F_73 ( struct V_2 * V_3 , struct V_50 * V_36 )
{
struct V_32 * * V_34 ;
struct V_32 * V_33 ;
if ( ! V_3 -> V_132 )
V_3 -> V_132 = V_57 ;
if ( V_3 -> V_132 != V_57 ) {
F_23 ( F_2 ( V_3 -> V_4 ) ,
L_32 ) ;
return - V_59 ;
}
V_34 = F_74 ( V_3 -> V_34 , ( V_3 -> V_29 + 1 ) *
sizeof( struct V_32 * ) , V_133 ) ;
if ( ! V_34 )
return - V_134 ;
V_33 = F_75 ( sizeof( struct V_32 ) , V_133 ) ;
if ( ! V_33 )
return - V_134 ;
V_3 -> V_34 = V_34 ;
F_76 ( & V_33 -> V_35 ) ;
V_33 -> V_36 = V_36 ;
V_34 [ V_3 -> V_29 ++ ] = V_33 ;
return 0 ;
}
static void F_77 ( struct V_2 * V_3 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_29 ; V_28 ++ )
F_78 ( V_3 -> V_34 [ V_28 ] ) ;
F_78 ( V_3 -> V_34 ) ;
V_3 -> V_34 = NULL ;
V_3 -> V_31 = 0 ;
V_3 -> V_22 = 1024 ;
V_3 -> V_18 = 0 ;
F_6 ( V_3 -> V_4 , 0 ) ;
V_3 -> V_58 = 0 ;
V_3 -> V_104 . V_135 = 0 ;
V_3 -> V_29 = 0 ;
V_3 -> V_132 = NULL ;
F_79 ( V_136 , V_3 -> V_4 -> V_137 ) ;
}
static void F_80 ( struct V_12 * V_13 )
{
F_81 ( V_13 , false ) ;
V_13 -> V_14 -> V_15 = 0 ;
if ( V_138 > 0 ) {
F_82 ( V_13 ) ;
V_13 -> V_139 = 1 ;
}
}
static void F_83 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( V_3 -> V_58 & V_124 )
F_81 ( V_13 , true ) ;
if ( V_3 -> V_58 & V_140 )
F_84 ( V_136 , V_3 -> V_4 -> V_137 ) ;
if ( V_3 -> V_58 & V_141 )
F_85 ( V_3 -> V_4 -> V_137 , true , false ) ;
else
F_85 ( V_3 -> V_4 -> V_137 , false , false ) ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_79 V_24 = {} ;
int V_28 , V_21 ;
V_24 . V_85 = F_39 ( V_86 ) ;
V_24 . type = F_39 ( V_9 ) ;
for ( V_28 = 0 ; V_28 < V_3 -> V_29 ; V_28 ++ ) {
V_21 = F_25 ( V_3 , V_28 , 1 , & V_24 , sizeof( V_24 ) , 0 ) ;
if ( V_21 <= 0 )
F_23 ( F_2 ( V_3 -> V_4 ) ,
L_33 , V_21 ) ;
}
}
static int F_87 ( struct V_12 * V_13 , struct V_2 * V_3 ,
unsigned int V_6 , unsigned long V_142 )
{
switch ( V_6 ) {
case V_143 : {
F_88 ( F_2 ( V_3 -> V_4 ) , L_34 ) ;
if ( ! V_3 -> V_34 )
return - V_59 ;
F_19 ( & V_3 -> V_44 ) ;
F_89 ( V_13 ) ;
F_17 ( & V_3 -> V_44 ) ;
if ( ! V_3 -> V_34 )
return - V_59 ;
if ( ! F_16 ( V_101 ,
& V_3 -> V_31 ) )
F_86 ( V_3 ) ;
return 0 ;
}
case V_144 :
F_15 ( V_3 ) ;
F_66 ( V_3 ) ;
F_90 ( V_13 ) ;
F_80 ( V_13 ) ;
if ( ! F_46 ( V_145 , & V_3 -> V_31 ) ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_3 -> V_29 ; V_28 ++ )
F_78 ( V_3 -> V_34 [ V_28 ] ) ;
F_78 ( V_3 -> V_34 ) ;
V_3 -> V_34 = NULL ;
V_3 -> V_29 = 0 ;
V_3 -> V_132 = NULL ;
}
return 0 ;
case V_146 : {
int V_147 ;
struct V_50 * V_36 = F_91 ( V_142 , & V_147 ) ;
if ( ! V_36 )
return V_147 ;
V_147 = F_73 ( V_3 , V_36 ) ;
if ( ! V_147 && V_138 )
V_13 -> V_139 = 1 ;
return V_147 ;
}
case V_148 : {
T_1 V_149 = F_92 ( V_3 -> V_18 , V_142 ) ;
return F_9 ( V_3 , V_13 , V_142 , V_149 ) ;
}
case V_150 :
return F_9 ( V_3 , V_13 , V_3 -> V_22 ,
F_92 ( V_142 , V_3 -> V_22 ) ) ;
case V_151 :
return F_9 ( V_3 , V_13 , V_3 -> V_22 , V_142 ) ;
case V_152 :
V_3 -> V_104 . V_135 = V_142 * V_153 ;
return 0 ;
case V_154 :
V_3 -> V_58 = V_142 ;
return 0 ;
case V_155 : {
struct V_117 * args ;
int V_29 = V_3 -> V_29 ;
int error = 0 , V_28 ;
if ( V_3 -> V_5 )
return - V_156 ;
if ( ! V_3 -> V_34 )
return - V_59 ;
if ( V_29 > 1 &&
! ( V_3 -> V_58 & V_157 ) ) {
F_23 ( F_2 ( V_3 -> V_4 ) , L_35 ) ;
error = - V_59 ;
goto V_158;
}
F_24 ( V_145 , & V_3 -> V_31 ) ;
F_93 ( & V_3 -> V_104 , V_3 -> V_29 ) ;
args = F_94 ( V_29 , sizeof( * args ) , V_133 ) ;
if ( ! args ) {
error = - V_134 ;
goto V_158;
}
V_3 -> V_5 = V_57 ;
F_19 ( & V_3 -> V_44 ) ;
F_83 ( V_3 , V_13 ) ;
error = F_95 ( F_2 ( V_3 -> V_4 ) , & V_159 ) ;
if ( error ) {
F_23 ( F_2 ( V_3 -> V_4 ) , L_36 ) ;
goto V_160;
}
F_8 ( V_3 , V_13 ) ;
F_96 ( V_3 ) ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
F_97 ( V_3 -> V_34 [ V_28 ] -> V_36 -> V_61 ) ;
F_98 ( & V_3 -> V_119 ) ;
F_99 ( & args [ V_28 ] . V_116 , F_58 ) ;
args [ V_28 ] . V_3 = V_3 ;
args [ V_28 ] . V_45 = V_28 ;
F_100 ( V_161 , & args [ V_28 ] . V_116 ) ;
}
F_101 ( V_3 -> V_120 ,
F_102 ( & V_3 -> V_119 ) == 0 ) ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ )
F_103 ( & args [ V_28 ] . V_116 ) ;
F_104 ( V_3 ) ;
F_5 ( V_3 , V_13 ) ;
F_105 ( F_2 ( V_3 -> V_4 ) , & V_159 ) ;
V_160:
F_17 ( & V_3 -> V_44 ) ;
V_3 -> V_5 = NULL ;
V_158:
F_15 ( V_3 ) ;
F_66 ( V_3 ) ;
F_90 ( V_13 ) ;
F_80 ( V_13 ) ;
if ( F_46 ( V_101 , & V_3 -> V_31 ) )
error = 0 ;
if ( F_46 ( V_40 , & V_3 -> V_31 ) )
error = - V_162 ;
F_77 ( V_3 ) ;
return error ;
}
case V_163 :
return 0 ;
case V_164 :
return 0 ;
}
return - V_165 ;
}
static int F_106 ( struct V_12 * V_13 , T_5 V_166 ,
unsigned int V_6 , unsigned long V_142 )
{
struct V_2 * V_3 = V_13 -> V_167 -> V_114 ;
int error ;
if ( ! F_107 ( V_168 ) )
return - V_169 ;
F_60 ( V_3 -> V_85 != V_118 ) ;
F_17 ( & V_3 -> V_44 ) ;
error = F_87 ( V_13 , V_3 , V_6 , V_142 ) ;
F_19 ( & V_3 -> V_44 ) ;
return error ;
}
static int F_108 ( struct V_170 * V_171 , void * V_172 )
{
struct V_2 * V_3 = V_171 -> V_173 ;
if ( V_3 -> V_5 )
F_109 ( V_171 , L_37 , F_57 ( V_3 -> V_5 ) ) ;
return 0 ;
}
static int F_110 ( struct V_174 * V_174 , struct V_175 * V_175 )
{
return F_111 ( V_175 , F_108 , V_174 -> V_176 ) ;
}
static int F_112 ( struct V_170 * V_171 , void * V_172 )
{
struct V_2 * V_3 = V_171 -> V_173 ;
T_2 V_58 = V_3 -> V_58 ;
F_109 ( V_171 , L_38 , V_58 ) ;
F_113 ( V_171 , L_39 ) ;
if ( V_58 & V_177 )
F_113 ( V_171 , L_40 ) ;
if ( V_58 & V_124 )
F_113 ( V_171 , L_41 ) ;
if ( V_58 & V_141 )
F_113 ( V_171 , L_42 ) ;
if ( V_58 & V_140 )
F_113 ( V_171 , L_43 ) ;
return 0 ;
}
static int F_114 ( struct V_174 * V_174 , struct V_175 * V_175 )
{
return F_111 ( V_175 , F_112 , V_174 -> V_176 ) ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_178 * V_179 ;
if ( ! V_180 )
return - V_27 ;
V_179 = F_115 ( F_116 ( V_3 ) , V_180 ) ;
if ( ! V_179 ) {
F_23 ( F_1 ( V_3 ) , L_44 ,
F_116 ( V_3 ) ) ;
return - V_27 ;
}
V_3 -> V_181 = V_179 ;
F_117 ( L_45 , 0444 , V_179 , V_3 , & V_182 ) ;
F_118 ( L_46 , 0444 , V_179 , & V_3 -> V_18 ) ;
F_119 ( L_47 , 0444 , V_179 , & V_3 -> V_104 . V_135 ) ;
F_118 ( L_48 , 0444 , V_179 , & V_3 -> V_22 ) ;
F_117 ( L_49 , 0444 , V_179 , V_3 , & V_183 ) ;
return 0 ;
}
static void F_104 ( struct V_2 * V_3 )
{
F_120 ( V_3 -> V_181 ) ;
}
static int F_121 ( void )
{
struct V_178 * V_181 ;
V_181 = F_115 ( L_50 , NULL ) ;
if ( ! V_181 )
return - V_27 ;
V_180 = V_181 ;
return 0 ;
}
static void F_122 ( void )
{
F_120 ( V_180 ) ;
}
static int F_96 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_104 ( struct V_2 * V_3 )
{
}
static int F_121 ( void )
{
return 0 ;
}
static void F_122 ( void )
{
}
static int F_123 ( void * V_121 , struct V_24 * V_129 ,
unsigned int V_184 , unsigned int V_185 ,
unsigned int V_186 )
{
struct V_23 * V_6 = F_22 ( V_129 ) ;
V_6 -> V_3 = V_121 ;
return 0 ;
}
static int T_6 F_124 ( void )
{
int V_147 = - V_134 ;
int V_28 ;
int V_187 ;
F_125 ( sizeof( struct V_79 ) != 28 ) ;
if ( V_138 < 0 ) {
F_126 ( V_188 L_51 ) ;
return - V_59 ;
}
V_187 = 0 ;
if ( V_138 > 0 ) {
V_187 = F_127 ( V_138 ) ;
V_138 = ( 1UL << V_187 ) - 1 ;
}
if ( ( 1UL << V_187 ) > V_189 )
return - V_59 ;
if ( V_190 > 1UL << ( V_191 - V_187 ) )
return - V_59 ;
V_192 = F_94 ( V_190 , sizeof( * V_192 ) , V_133 ) ;
if ( ! V_192 )
return - V_134 ;
for ( V_28 = 0 ; V_28 < V_190 ; V_28 ++ ) {
struct V_193 * V_194 ;
struct V_113 * V_4 = F_128 ( 1 << V_187 ) ;
if ( ! V_4 )
goto V_195;
V_192 [ V_28 ] . V_4 = V_4 ;
V_192 [ V_28 ] . V_104 . V_196 = & V_197 ;
V_192 [ V_28 ] . V_104 . V_105 = 1 ;
V_192 [ V_28 ] . V_104 . V_198 = 128 ;
V_192 [ V_28 ] . V_104 . V_186 = V_199 ;
V_192 [ V_28 ] . V_104 . V_200 = sizeof( struct V_23 ) ;
V_192 [ V_28 ] . V_104 . V_58 = V_201 |
V_202 | V_203 ;
V_192 [ V_28 ] . V_104 . V_204 = & V_192 [ V_28 ] ;
V_147 = F_129 ( & V_192 [ V_28 ] . V_104 ) ;
if ( V_147 ) {
F_130 ( V_4 ) ;
goto V_195;
}
V_194 = F_131 ( & V_192 [ V_28 ] . V_104 ) ;
if ( F_61 ( V_194 ) ) {
F_132 ( & V_192 [ V_28 ] . V_104 ) ;
F_130 ( V_4 ) ;
goto V_195;
}
V_4 -> V_137 = V_194 ;
F_84 ( V_205 , V_4 -> V_137 ) ;
F_79 ( V_206 , V_4 -> V_137 ) ;
V_4 -> V_137 -> V_207 . V_208 = 512 ;
F_133 ( V_4 -> V_137 , V_209 ) ;
V_4 -> V_137 -> V_207 . V_210 = 0 ;
F_134 ( V_4 -> V_137 , 65536 ) ;
V_4 -> V_137 -> V_207 . V_211 = 256 ;
}
if ( F_135 ( V_212 , L_50 ) ) {
V_147 = - V_27 ;
goto V_195;
}
F_126 ( V_213 L_52 , V_212 ) ;
F_121 () ;
for ( V_28 = 0 ; V_28 < V_190 ; V_28 ++ ) {
struct V_113 * V_4 = V_192 [ V_28 ] . V_4 ;
V_192 [ V_28 ] . V_85 = V_118 ;
F_76 ( & V_192 [ V_28 ] . V_44 ) ;
V_4 -> V_214 = V_212 ;
V_4 -> V_215 = V_28 << V_187 ;
V_4 -> V_216 = & V_217 ;
V_4 -> V_114 = & V_192 [ V_28 ] ;
sprintf ( V_4 -> V_218 , L_53 , V_28 ) ;
F_136 ( & V_192 [ V_28 ] . V_120 ) ;
F_77 ( & V_192 [ V_28 ] ) ;
F_137 ( V_4 ) ;
}
return 0 ;
V_195:
while ( V_28 -- ) {
F_132 ( & V_192 [ V_28 ] . V_104 ) ;
F_138 ( V_192 [ V_28 ] . V_4 -> V_137 ) ;
F_130 ( V_192 [ V_28 ] . V_4 ) ;
}
F_78 ( V_192 ) ;
return V_147 ;
}
static void T_7 F_139 ( void )
{
int V_28 ;
F_122 () ;
for ( V_28 = 0 ; V_28 < V_190 ; V_28 ++ ) {
struct V_113 * V_4 = V_192 [ V_28 ] . V_4 ;
V_192 [ V_28 ] . V_85 = 0 ;
if ( V_4 ) {
F_140 ( V_4 ) ;
F_138 ( V_4 -> V_137 ) ;
F_132 ( & V_192 [ V_28 ] . V_104 ) ;
F_130 ( V_4 ) ;
}
}
F_141 ( V_212 , L_50 ) ;
F_78 ( V_192 ) ;
F_126 ( V_213 L_54 , V_212 ) ;
}
