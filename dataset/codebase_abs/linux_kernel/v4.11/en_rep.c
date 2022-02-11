static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 ,
sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_9 , T_2 * V_10 )
{
int V_11 ;
switch ( V_9 ) {
case V_12 :
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
strcpy ( V_10 + ( V_11 * V_14 ) ,
V_15 [ V_11 ] . V_16 ) ;
break;
}
}
static void F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 ;
struct V_28 V_29 ;
int V_30 ;
V_30 = F_5 ( V_20 , V_24 -> V_31 , & V_29 ) ;
if ( V_30 ) {
F_6 ( L_1 , V_24 -> V_31 , V_30 ) ;
return;
}
V_27 = & V_18 -> V_32 . V_33 ;
V_27 -> V_34 = V_29 . V_35 ;
V_27 -> V_36 = V_29 . V_37 ;
V_27 -> V_35 = V_29 . V_34 ;
V_27 -> V_37 = V_29 . V_36 ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_38 * V_39 = & V_18 -> V_32 . V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_11 , V_45 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
for ( V_11 = 0 ; V_11 < V_18 -> V_46 . V_47 ; V_11 ++ ) {
V_42 = & V_18 -> V_48 [ V_11 ] -> V_49 . V_32 ;
V_39 -> V_34 += V_42 -> V_50 ;
V_39 -> V_36 += V_42 -> V_51 ;
for ( V_45 = 0 ; V_45 < V_18 -> V_46 . V_52 ; V_45 ++ ) {
V_44 = & V_18 -> V_48 [ V_11 ] -> V_53 [ V_45 ] . V_32 ;
V_39 -> V_35 += V_44 -> V_50 ;
V_39 -> V_37 += V_44 -> V_51 ;
}
}
}
static void F_8 ( struct V_17 * V_18 )
{
F_7 ( V_18 ) ;
F_4 ( V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_54 * V_32 , T_3 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
int V_11 ;
if ( ! V_10 )
return;
F_11 ( & V_18 -> V_55 ) ;
if ( F_12 ( V_56 , & V_18 -> V_57 ) )
F_7 ( V_18 ) ;
F_13 ( & V_18 -> V_55 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_10 [ V_11 ] = F_14 ( & V_18 -> V_32 . V_40 ,
V_15 , V_11 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_58 )
{
switch ( V_58 ) {
case V_12 :
return V_13 ;
default:
return - V_59 ;
}
}
int F_16 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
if ( V_20 -> V_62 == V_63 )
return - V_59 ;
switch ( V_61 -> V_64 ) {
case V_65 :
V_61 -> V_66 . V_67 . V_68 = V_69 ;
F_17 ( V_61 -> V_66 . V_67 . V_64 , V_24 -> V_70 ) ;
break;
default:
return - V_59 ;
}
return 0 ;
}
int F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_71 * V_72 ;
int V_73 , V_74 , V_30 , V_75 = 0 ;
T_4 * V_76 ;
V_76 = F_19 ( V_18 -> V_46 . V_47 * V_18 -> V_46 . V_52 , sizeof( T_4 ) , V_77 ) ;
if ( ! V_76 )
return - V_78 ;
for ( V_73 = 0 ; V_73 < V_18 -> V_46 . V_47 ; V_73 ++ ) {
V_72 = V_18 -> V_48 [ V_73 ] ;
for ( V_74 = 0 ; V_74 < V_72 -> V_52 ; V_74 ++ )
V_76 [ V_75 ++ ] = V_72 -> V_53 [ V_74 ] . V_79 ;
}
V_30 = F_20 ( V_20 , V_24 , V_76 , V_75 ) ;
F_21 ( V_76 ) ;
return V_30 ;
}
int F_22 ( struct V_19 * V_20 , struct V_23 * V_24 )
{
struct V_1 * V_80 = V_24 -> V_80 ;
struct V_17 * V_18 = F_10 ( V_80 ) ;
if ( F_12 ( V_56 , & V_18 -> V_57 ) )
return F_18 ( V_18 ) ;
return 0 ;
}
void F_23 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
F_24 ( V_20 , V_24 ) ;
}
void F_25 ( struct V_19 * V_20 ,
struct V_23 * V_24 )
{
struct V_1 * V_80 = V_24 -> V_80 ;
struct V_17 * V_18 = F_10 ( V_80 ) ;
if ( F_12 ( V_56 , & V_18 -> V_57 ) )
F_23 ( V_18 ) ;
F_26 ( V_18 ) ;
F_27 ( V_18 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
int V_30 ;
V_30 = F_29 ( V_2 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_30 ( V_20 , V_24 -> V_31 , V_81 ) ;
if ( ! V_30 )
F_31 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
( void ) F_30 ( V_20 , V_24 -> V_31 , V_82 ) ;
return F_33 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
char * V_83 , T_5 V_84 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
int V_85 ;
V_85 = snprintf ( V_83 , V_84 , L_2 , V_24 -> V_31 - 1 ) ;
if ( V_85 >= V_84 )
return - V_59 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_86 ,
T_6 V_87 , struct V_88 * V_74 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
if ( F_36 ( V_86 ) != F_36 ( V_89 ) )
return - V_59 ;
if ( V_74 -> V_90 ) {
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_1 * V_91 = F_37 ( V_20 ) ;
return V_91 -> V_92 -> V_93 ( V_91 , V_86 ,
V_87 , V_74 ) ;
}
switch ( V_74 -> type ) {
case V_94 :
switch ( V_74 -> V_95 -> V_96 ) {
case V_97 :
return F_38 ( V_18 , V_87 , V_74 -> V_95 ) ;
case V_98 :
return F_39 ( V_18 , V_74 -> V_95 ) ;
case V_99 :
return F_40 ( V_18 , V_74 -> V_95 ) ;
}
default:
return - V_59 ;
}
}
bool F_41 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = (struct V_23 * ) V_18 -> V_25 ;
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
if ( V_24 && V_24 -> V_31 == V_100 && V_20 -> V_62 == V_101 )
return true ;
return false ;
}
bool F_42 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = (struct V_23 * ) V_18 -> V_25 ;
if ( V_24 && V_24 -> V_31 != V_100 )
return true ;
return false ;
}
bool F_43 ( const struct V_1 * V_2 , int V_102 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
switch ( V_102 ) {
case V_103 :
if ( F_42 ( V_18 ) || F_41 ( V_18 ) )
return true ;
}
return false ;
}
static int
F_44 ( const struct V_1 * V_2 ,
struct V_26 * V_32 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_38 * V_104 = & V_18 -> V_32 . V_40 ;
V_32 -> V_34 = V_104 -> V_34 ;
V_32 -> V_36 = V_104 -> V_36 ;
V_32 -> V_35 = V_104 -> V_35 ;
V_32 -> V_37 = V_104 -> V_37 ;
V_32 -> V_105 = V_104 -> V_106 ;
return 0 ;
}
int F_45 ( int V_102 , const struct V_1 * V_2 ,
void * V_107 )
{
switch ( V_102 ) {
case V_103 :
return F_44 ( V_2 , V_107 ) ;
}
return - V_108 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_26 * V_32 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
memcpy ( V_32 , & V_18 -> V_32 . V_33 , sizeof( * V_32 ) ) ;
}
static void F_47 ( struct V_109 * V_21 ,
struct V_1 * V_80 ,
const struct V_110 * V_111 ,
void * V_25 )
{
struct V_17 * V_18 = F_10 ( V_80 ) ;
T_7 V_112 = F_48 ( V_21 , V_113 ) ?
V_114 :
V_115 ;
V_18 -> V_46 . V_116 =
V_117 ;
V_18 -> V_46 . V_118 = V_119 ;
V_18 -> V_46 . V_120 = V_121 ;
V_18 -> V_46 . V_122 = F_49 ( V_18 -> V_46 . V_118 ,
F_50 ( V_18 -> V_46 . V_120 ) ) ;
V_18 -> V_46 . V_123 = F_48 ( V_21 , V_124 ) ;
F_51 ( & V_18 -> V_46 , V_112 ) ;
V_18 -> V_46 . V_125 = F_52 ( V_21 ) ;
V_18 -> V_46 . V_52 = 1 ;
V_18 -> V_46 . V_126 =
V_127 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_80 = V_80 ;
V_18 -> V_46 . V_47 = V_111 -> V_128 ( V_21 ) ;
V_18 -> V_111 = V_111 ;
V_18 -> V_25 = V_25 ;
F_53 ( & V_18 -> V_55 ) ;
F_54 ( & V_18 -> V_129 , V_130 ) ;
}
static void F_55 ( struct V_1 * V_80 )
{
V_80 -> V_92 = & V_131 ;
V_80 -> V_132 = 15 * V_133 ;
V_80 -> V_134 = & V_135 ;
#ifdef F_56
V_80 -> V_136 = & V_137 ;
#endif
V_80 -> V_138 |= V_139 | V_140 | V_141 ;
V_80 -> V_142 |= V_140 ;
F_57 ( V_80 ) ;
}
static void F_58 ( struct V_109 * V_21 ,
struct V_1 * V_80 ,
const struct V_110 * V_111 ,
void * V_25 )
{
F_47 ( V_21 , V_80 , V_111 , V_25 ) ;
F_55 ( V_80 ) ;
}
static int F_59 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_109 * V_21 = V_18 -> V_21 ;
struct V_143 * V_144 ;
int V_30 ;
int V_11 ;
V_30 = F_60 ( V_18 ) ;
if ( V_30 ) {
F_61 ( V_21 , L_3 , V_30 ) ;
return V_30 ;
}
V_30 = F_62 ( V_18 ) ;
if ( V_30 ) {
F_61 ( V_21 , L_4 , V_30 ) ;
goto V_145;
}
V_144 = F_63 ( V_20 ,
V_24 -> V_31 ,
V_18 -> V_146 [ 0 ] . V_147 ) ;
if ( F_64 ( V_144 ) ) {
V_30 = F_65 ( V_144 ) ;
goto V_148;
}
V_24 -> V_149 = V_144 ;
V_30 = F_27 ( V_18 ) ;
if ( V_30 )
goto V_150;
return 0 ;
V_150:
F_66 ( V_24 -> V_149 ) ;
V_148:
F_67 ( V_18 ) ;
V_145:
for ( V_11 = 0 ; V_11 < V_18 -> V_46 . V_47 ; V_11 ++ )
F_68 ( V_18 , & V_18 -> V_146 [ V_11 ] . V_151 ) ;
return V_30 ;
}
static void F_69 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_25 ;
int V_11 ;
F_26 ( V_18 ) ;
F_66 ( V_24 -> V_149 ) ;
F_67 ( V_18 ) ;
for ( V_11 = 0 ; V_11 < V_18 -> V_46 . V_47 ; V_11 ++ )
F_68 ( V_18 , & V_18 -> V_146 [ V_11 ] . V_151 ) ;
}
static int F_70 ( struct V_17 * V_18 )
{
int V_30 ;
V_30 = F_71 ( V_18 ) ;
if ( V_30 ) {
F_61 ( V_18 -> V_21 , L_5 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int F_72 ( struct V_109 * V_21 )
{
#define F_73 1
return F_73 ;
}
int F_74 ( struct V_19 * V_20 ,
struct V_23 * V_24 )
{
struct V_1 * V_80 ;
int V_30 ;
V_80 = F_75 ( V_20 -> V_2 , & V_152 , V_24 ) ;
if ( ! V_80 ) {
F_6 ( L_6 ,
V_24 -> V_31 ) ;
return - V_108 ;
}
V_24 -> V_80 = V_80 ;
V_30 = F_76 ( V_20 -> V_2 , V_80 ) ;
if ( V_30 ) {
F_6 ( L_7 ,
V_24 -> V_31 ) ;
goto V_153;
}
V_30 = F_77 ( V_80 ) ;
if ( V_30 ) {
F_6 ( L_8 ,
V_24 -> V_31 ) ;
goto V_154;
}
return 0 ;
V_154:
F_78 ( V_20 -> V_2 , V_80 ) ;
V_153:
F_79 ( V_20 -> V_2 , F_10 ( V_80 ) ) ;
return V_30 ;
}
void F_80 ( struct V_19 * V_20 ,
struct V_23 * V_24 )
{
struct V_1 * V_80 = V_24 -> V_80 ;
F_81 ( V_80 ) ;
F_78 ( V_20 -> V_2 , V_80 ) ;
F_79 ( V_20 -> V_2 , F_10 ( V_80 ) ) ;
}
