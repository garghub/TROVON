static struct V_1 * F_1 ( enum V_2 type )
{
switch ( type ) {
case V_3 :
return & V_4 [ V_5 ] ;
case V_6 :
return & V_4 [ V_7 ] ;
default:
F_2 () ;
}
return NULL ;
}
static struct V_8 * F_3 ( struct V_9 * V_10 )
{
struct V_8 * V_11 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = & V_14 [ V_12 ] ;
if ( ( V_11 -> V_15 & V_10 -> type ) &&
( V_11 -> V_16 == V_10 -> V_11 . V_17 . V_18 ) )
break;
}
if ( V_12 == V_13 )
return NULL ;
return & V_14 [ V_12 ] ;
}
static int F_4 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 = V_21 -> V_24 ;
if ( ( F_5 ( V_21 -> V_25 ) > 0 )
&& ( F_6 ( V_21 -> V_25 ) > 0 )
&& ( F_7 ( & V_21 -> V_24 -> V_26 ) == 0 ) ) {
F_8 ( V_23 , L_1 ) ;
return 1 ;
}
F_8 ( V_23 , L_2 ) ;
return 0 ;
}
static void F_9 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 = V_21 -> V_24 ;
V_21 -> V_27 = 1 ;
F_8 ( V_23 , L_3 ) ;
F_10 ( V_23 -> V_28 , V_21 -> V_25 ) ;
}
static void F_11 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 = V_21 -> V_24 ;
F_12 ( & V_23 -> V_29 ) ;
}
static void F_13 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 = V_21 -> V_24 ;
F_14 ( & V_23 -> V_29 ) ;
}
static void F_15 ( void * V_30 )
{
struct V_20 * V_31 = V_30 ;
struct V_22 * V_23 = V_31 -> V_24 ;
struct V_32 * V_33 , * V_34 ;
F_16 ( & V_23 -> V_26 , 0 ) ;
V_33 = F_17 ( V_31 -> V_25 ) ;
V_34 = F_18 ( V_31 -> V_25 ) ;
F_19 ( V_33 , V_35 ) ;
F_19 ( V_34 , V_35 ) ;
F_10 ( V_23 -> V_28 , V_31 -> V_25 ) ;
F_8 ( V_23 , L_4 ) ;
}
static void F_20 ( struct V_20 * V_21 , int V_36 ,
int V_37 )
{
struct V_1 * V_38 , * V_39 ;
struct V_32 * V_40 , * V_41 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_42 * V_43 = V_23 -> V_42 ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_47 * V_48 ;
unsigned int V_49 , V_50 ;
unsigned int V_51 , V_52 ;
unsigned int V_53 , V_54 ;
T_1 V_55 , V_56 ;
enum V_57 V_58 ;
V_40 = F_21 ( V_21 -> V_25 ) ;
V_41 = F_22 ( V_21 -> V_25 ) ;
V_38 = F_1 ( V_3 ) ;
V_49 = V_38 -> V_59 ;
V_50 = V_38 -> V_60 ;
V_54 = V_49 * V_50 ;
V_39 = F_1 ( V_6 ) ;
V_51 = V_39 -> V_59 ;
V_52 = V_39 -> V_60 ;
V_53 = V_51 * V_52 ;
V_55 = ( T_1 ) F_23 ( V_40 , 0 ) ;
V_56 = ( T_1 ) F_23 ( V_41 , 0 ) ;
if ( ! V_55 || ! V_56 ) {
F_24 ( & V_23 -> V_61 ,
L_5 ) ;
return;
}
switch ( V_36 ) {
case V_62 :
V_21 -> V_63 -> V_64 = V_50 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 ;
break;
case V_70 :
V_21 -> V_63 -> V_64 = V_50 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 / 2 ;
V_21 -> V_63 -> V_69 = V_56 + V_49 ;
break;
case V_71 :
V_21 -> V_63 -> V_64 = V_50 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 ;
V_21 -> V_63 -> V_69 = V_56 + V_54 ;
break;
case V_72 :
V_21 -> V_63 -> V_64 = V_50 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 9 * V_54 ) / 8 ;
V_21 -> V_63 -> V_69 = V_56 + V_54 + V_49 / 2 ;
break;
case V_73 :
V_21 -> V_63 -> V_64 = V_50 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 5 * V_54 ) / 4 ;
V_21 -> V_63 -> V_69 = V_56 + ( 5 * V_54 ) / 4 ;
break;
case V_74 :
V_21 -> V_63 -> V_64 = V_50 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 11 * V_54 ) / 8 ;
V_21 -> V_63 -> V_69 = V_56 + ( 5 * V_54 ) / 4 + V_49 / 2 ;
break;
case V_75 :
V_21 -> V_63 -> V_64 = V_50 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 + V_49 ;
break;
case V_76 :
V_21 -> V_63 -> V_64 = V_50 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 ;
V_21 -> V_63 -> V_69 = V_56 + V_54 + V_49 / 2 ;
break;
case V_77 :
V_21 -> V_63 -> V_64 = V_50 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 5 * V_54 ) / 4 ;
V_21 -> V_63 -> V_69 = V_56 + ( 5 * V_54 ) / 4 + V_49 / 2 ;
break;
case V_78 :
V_21 -> V_63 -> V_64 = V_50 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 * 2 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 ;
break;
case V_79 :
V_21 -> V_63 -> V_64 = V_50 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 * 2 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 ;
V_21 -> V_63 -> V_69 = V_56 + V_49 * 2 ;
break;
case V_80 :
default:
V_21 -> V_63 -> V_64 = V_50 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_49 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_49 * 2 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 + V_49 * 2 ;
break;
}
V_21 -> V_63 -> V_81 = 1 ;
V_21 -> V_63 -> V_82 = V_83 ;
V_21 -> V_63 -> V_84 = false ;
V_21 -> V_63 -> V_85 = true ;
V_58 = V_86 | V_87 |
V_88 | V_89 ;
V_48 = V_45 -> V_90 ( V_43 , V_21 -> V_63 , V_58 ) ;
if ( V_48 == NULL ) {
F_25 ( & V_23 -> V_61 , L_6 ) ;
return;
}
if ( V_37 ) {
V_48 -> V_91 = F_15 ;
V_48 -> V_92 = V_21 ;
}
V_21 -> V_93 = F_26 ( V_48 ) ;
if ( F_27 ( V_21 -> V_93 ) ) {
F_25 ( & V_23 -> V_61 ,
L_7 ,
V_21 -> V_93 , ( unsigned ) V_55 , ( unsigned ) V_56 ,
V_54 * 3 / 2 ) ;
return;
}
F_28 ( V_43 ) ;
}
static void F_29 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_94 ;
F_16 ( & V_21 -> V_24 -> V_26 , 1 ) ;
F_8 ( V_21 -> V_24 , L_8 , V_95 ) ;
V_94 = F_1 ( V_6 ) ;
switch ( V_94 -> V_11 -> V_16 ) {
case V_96 :
switch ( V_94 -> V_97 ) {
case V_98 :
case V_99 :
F_8 ( V_21 -> V_24 , L_9 ,
V_95 ) ;
F_20 ( V_21 , V_62 , 0 ) ;
F_20 ( V_21 , V_70 , 0 ) ;
F_20 ( V_21 , V_71 , 0 ) ;
F_20 ( V_21 , V_72 , 0 ) ;
F_20 ( V_21 , V_73 , 0 ) ;
F_20 ( V_21 , V_74 , 1 ) ;
break;
case V_100 :
default:
F_8 ( V_21 -> V_24 , L_10 ,
V_95 ) ;
F_20 ( V_21 , V_62 , 0 ) ;
F_20 ( V_21 , V_75 , 0 ) ;
F_20 ( V_21 , V_71 , 0 ) ;
F_20 ( V_21 , V_76 , 0 ) ;
F_20 ( V_21 , V_73 , 0 ) ;
F_20 ( V_21 , V_77 , 1 ) ;
break;
}
break;
case V_101 :
default:
switch ( V_94 -> V_97 ) {
case V_98 :
case V_99 :
F_8 ( V_21 -> V_24 , L_11 ,
V_95 ) ;
F_20 ( V_21 , V_78 , 0 ) ;
F_20 ( V_21 , V_79 , 1 ) ;
break;
case V_100 :
default:
F_8 ( V_21 -> V_24 , L_12 ,
V_95 ) ;
F_20 ( V_21 , V_78 , 0 ) ;
F_20 ( V_21 , V_80 , 1 ) ;
break;
}
break;
}
F_8 ( V_21 -> V_24 , L_13 , V_95 ) ;
}
static int F_30 ( struct V_102 * V_102 , void * V_19 ,
struct V_103 * V_104 )
{
F_31 ( V_104 -> V_105 , V_106 , sizeof( V_104 -> V_105 ) ) ;
F_31 ( V_104 -> V_107 , V_106 , sizeof( V_104 -> V_107 ) ) ;
F_31 ( V_104 -> V_108 , V_106 , sizeof( V_104 -> V_107 ) ) ;
V_104 -> V_109 = V_110 | V_111 |
V_112 | V_113 ;
V_104 -> V_114 = V_104 -> V_109 | V_115 ;
return 0 ;
}
static int F_32 ( struct V_116 * V_10 , T_2 type )
{
int V_117 , V_118 ;
struct V_8 * V_11 ;
V_118 = 0 ;
for ( V_117 = 0 ; V_117 < V_13 ; ++ V_117 ) {
if ( V_14 [ V_117 ] . V_15 & type ) {
if ( V_118 == V_10 -> V_119 )
break;
++ V_118 ;
}
}
if ( V_117 < V_13 ) {
V_11 = & V_14 [ V_117 ] ;
F_31 ( V_10 -> V_120 , V_11 -> V_121 , sizeof( V_10 -> V_120 ) ) ;
V_10 -> V_18 = V_11 -> V_16 ;
return 0 ;
}
return - V_122 ;
}
static int F_33 ( struct V_102 * V_102 , void * V_19 ,
struct V_116 * V_10 )
{
return F_32 ( V_10 , V_123 ) ;
}
static int F_34 ( struct V_102 * V_102 , void * V_19 ,
struct V_116 * V_10 )
{
return F_32 ( V_10 , V_124 ) ;
}
static int F_35 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_125 * V_126 ;
struct V_1 * V_4 ;
V_126 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_126 )
return - V_122 ;
V_4 = F_1 ( V_10 -> type ) ;
V_10 -> V_11 . V_17 . V_59 = V_4 -> V_59 ;
V_10 -> V_11 . V_17 . V_60 = V_4 -> V_60 ;
V_10 -> V_11 . V_17 . V_97 = V_4 -> V_97 ;
V_10 -> V_11 . V_17 . V_18 = V_4 -> V_11 -> V_16 ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_96 :
V_10 -> V_11 . V_17 . V_127 = V_4 -> V_59 * 3 / 2 ;
break;
case V_101 :
default:
V_10 -> V_11 . V_17 . V_127 = V_4 -> V_59 * 2 ;
}
V_10 -> V_11 . V_17 . V_128 = V_4 -> V_128 ;
V_10 -> V_11 . V_17 . V_129 = V_21 -> V_129 ;
return 0 ;
}
static int F_37 ( struct V_102 * V_102 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_38 ( struct V_102 * V_102 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_8 * V_11 )
{
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_96 :
V_10 -> V_11 . V_17 . V_127 = V_10 -> V_11 . V_17 . V_59 * 3 / 2 ;
break;
case V_101 :
default:
V_10 -> V_11 . V_17 . V_127 = V_10 -> V_11 . V_17 . V_59 * 2 ;
}
V_10 -> V_11 . V_17 . V_128 = V_10 -> V_11 . V_17 . V_60 * V_10 -> V_11 . V_17 . V_127 ;
return 0 ;
}
static int F_40 ( struct V_102 * V_102 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
struct V_20 * V_21 = V_19 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_123 ) )
V_10 -> V_11 . V_17 . V_18 = V_96 ;
V_10 -> V_11 . V_17 . V_129 = V_21 -> V_129 ;
if ( V_10 -> V_11 . V_17 . V_97 != V_98 &&
V_10 -> V_11 . V_17 . V_97 != V_99 &&
V_10 -> V_11 . V_17 . V_97 != V_100 )
V_10 -> V_11 . V_17 . V_97 = V_98 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_41 ( struct V_102 * V_102 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_124 ) )
V_10 -> V_11 . V_17 . V_18 = V_96 ;
if ( ! V_10 -> V_11 . V_17 . V_129 )
V_10 -> V_11 . V_17 . V_129 = V_130 ;
if ( V_10 -> V_11 . V_17 . V_97 != V_131 &&
V_10 -> V_11 . V_17 . V_97 != V_132 )
V_10 -> V_11 . V_17 . V_97 = V_131 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_42 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_1 * V_4 ;
struct V_125 * V_126 ;
V_126 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_126 )
return - V_122 ;
V_4 = F_1 ( V_10 -> type ) ;
if ( ! V_4 )
return - V_122 ;
if ( F_43 ( V_126 ) ) {
F_24 ( & V_21 -> V_24 -> V_61 , L_14 , V_95 ) ;
return - V_133 ;
}
V_4 -> V_11 = F_3 ( V_10 ) ;
if ( ! V_4 -> V_11 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_15 ,
V_10 -> type , V_10 -> V_11 . V_17 . V_59 , V_10 -> V_11 . V_17 . V_60 ,
V_10 -> V_11 . V_17 . V_18 , V_10 -> V_11 . V_17 . V_97 ) ;
return - V_122 ;
}
V_4 -> V_59 = V_10 -> V_11 . V_17 . V_59 ;
V_4 -> V_60 = V_10 -> V_11 . V_17 . V_60 ;
V_4 -> V_97 = V_10 -> V_11 . V_17 . V_97 ;
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_96 :
V_10 -> V_11 . V_17 . V_127 = V_10 -> V_11 . V_17 . V_59 * 3 / 2 ;
V_4 -> V_128 = ( V_4 -> V_59 * V_4 -> V_60 * 3 ) / 2 ;
break;
case V_101 :
default:
V_10 -> V_11 . V_17 . V_127 = V_10 -> V_11 . V_17 . V_59 * 2 ;
V_4 -> V_128 = V_4 -> V_59 * V_4 -> V_60 * 2 ;
}
F_8 ( V_21 -> V_24 ,
L_16 ,
V_10 -> type , V_4 -> V_59 , V_4 -> V_60 , V_4 -> V_11 -> V_16 ,
V_4 -> V_97 ) ;
return 0 ;
}
static int F_44 ( struct V_102 * V_102 , void * V_19 ,
struct V_9 * V_10 )
{
int V_134 ;
V_134 = F_40 ( V_102 , V_19 , V_10 ) ;
if ( V_134 )
return V_134 ;
return F_42 ( V_19 , V_10 ) ;
}
static int F_45 ( struct V_102 * V_102 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 = V_19 ;
int V_134 ;
V_134 = F_41 ( V_102 , V_19 , V_10 ) ;
if ( V_134 )
return V_134 ;
V_134 = F_42 ( V_19 , V_10 ) ;
if ( ! V_134 )
V_21 -> V_129 = V_10 -> V_11 . V_17 . V_129 ;
return V_134 ;
}
static int F_46 ( struct V_102 * V_102 , void * V_19 ,
struct V_135 * V_136 )
{
struct V_20 * V_21 = V_19 ;
return F_47 ( V_102 , V_21 -> V_25 , V_136 ) ;
}
static int F_48 ( struct V_102 * V_102 , void * V_19 ,
struct V_137 * V_138 )
{
struct V_20 * V_21 = V_19 ;
return F_49 ( V_102 , V_21 -> V_25 , V_138 ) ;
}
static int F_50 ( struct V_102 * V_102 , void * V_19 , struct V_137 * V_138 )
{
struct V_20 * V_21 = V_19 ;
return F_51 ( V_102 , V_21 -> V_25 , V_138 ) ;
}
static int F_52 ( struct V_102 * V_102 , void * V_19 , struct V_137 * V_138 )
{
struct V_20 * V_21 = V_19 ;
return F_53 ( V_102 , V_21 -> V_25 , V_138 ) ;
}
static int F_54 ( struct V_102 * V_102 , void * V_19 ,
enum V_2 type )
{
struct V_1 * V_38 , * V_39 ;
struct V_20 * V_21 = V_19 ;
V_38 = F_1 ( V_3 ) ;
V_39 = F_1 ( V_6 ) ;
if ( V_38 -> V_11 -> V_16 != V_39 -> V_11 -> V_16 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_17 ) ;
return - V_122 ;
}
switch ( V_38 -> V_97 ) {
case V_132 :
if ( V_39 -> V_97 != V_100 &&
V_39 -> V_97 != V_99 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_18 ,
V_38 -> V_97 , V_39 -> V_97 ) ;
return - V_122 ;
}
break;
case V_131 :
if ( V_39 -> V_97 != V_100 &&
V_39 -> V_97 != V_98 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_18 ,
V_38 -> V_97 , V_39 -> V_97 ) ;
return - V_122 ;
}
break;
default:
return - V_122 ;
}
return F_55 ( V_102 , V_21 -> V_25 , type ) ;
}
static int F_56 ( struct V_102 * V_102 , void * V_19 ,
enum V_2 type )
{
struct V_20 * V_21 = V_19 ;
return F_57 ( V_102 , V_21 -> V_25 , type ) ;
}
static int F_58 ( struct V_125 * V_126 ,
const struct V_9 * V_11 ,
unsigned int * V_139 , unsigned int * V_140 ,
unsigned int V_141 [] , void * V_142 [] )
{
struct V_20 * V_21 = F_59 ( V_126 ) ;
struct V_1 * V_4 ;
unsigned int V_66 , V_143 = * V_139 ;
V_4 = F_1 ( V_126 -> type ) ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_96 :
V_66 = V_4 -> V_59 * V_4 -> V_60 * 3 / 2 ;
break;
case V_101 :
default:
V_66 = V_4 -> V_59 * V_4 -> V_60 * 2 ;
}
* V_140 = 1 ;
* V_139 = V_143 ;
V_141 [ 0 ] = V_66 ;
V_142 [ 0 ] = V_21 -> V_24 -> V_144 ;
F_8 ( V_21 -> V_24 , L_19 , V_143 , V_66 ) ;
return 0 ;
}
static int F_60 ( struct V_32 * V_145 )
{
struct V_20 * V_21 = F_59 ( V_145 -> V_125 ) ;
struct V_1 * V_4 ;
F_8 ( V_21 -> V_24 , L_20 , V_145 -> V_125 -> type ) ;
V_4 = F_1 ( V_145 -> V_125 -> type ) ;
if ( F_61 ( V_145 , 0 ) < V_4 -> V_128 ) {
F_8 ( V_21 -> V_24 , L_21 ,
V_95 , F_61 ( V_145 , 0 ) , ( long ) V_4 -> V_128 ) ;
return - V_122 ;
}
F_62 ( V_145 , 0 , V_4 -> V_128 ) ;
return 0 ;
}
static void F_63 ( struct V_32 * V_145 )
{
struct V_20 * V_21 = F_59 ( V_145 -> V_125 ) ;
F_64 ( V_21 -> V_25 , V_145 ) ;
}
static int F_65 ( void * V_19 , struct V_125 * V_146 ,
struct V_125 * V_147 )
{
struct V_20 * V_21 = V_19 ;
int V_134 ;
V_146 -> type = V_3 ;
V_146 -> V_148 = V_149 | V_150 ;
V_146 -> V_151 = V_21 ;
V_146 -> V_152 = sizeof( struct V_153 ) ;
V_146 -> V_154 = & V_155 ;
V_146 -> V_156 = & V_157 ;
V_4 [ V_5 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_5 ] . V_59 = 640 ;
V_4 [ V_5 ] . V_60 = 480 ;
V_4 [ V_5 ] . V_128 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_97 = V_131 ;
V_134 = F_66 ( V_146 ) ;
if ( V_134 )
return V_134 ;
V_147 -> type = V_6 ;
V_147 -> V_148 = V_149 | V_150 ;
V_147 -> V_151 = V_21 ;
V_147 -> V_152 = sizeof( struct V_153 ) ;
V_147 -> V_154 = & V_155 ;
V_147 -> V_156 = & V_157 ;
V_4 [ V_7 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_7 ] . V_59 = 640 ;
V_4 [ V_7 ] . V_60 = 480 ;
V_4 [ V_7 ] . V_128 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_97 = V_98 ;
return F_66 ( V_147 ) ;
}
static int F_67 ( struct V_102 * V_102 )
{
struct V_22 * V_23 = F_68 ( V_102 ) ;
struct V_20 * V_21 = NULL ;
V_21 = F_69 ( sizeof *V_21 , V_158 ) ;
if ( ! V_21 )
return - V_159 ;
V_102 -> V_160 = V_21 ;
V_21 -> V_24 = V_23 ;
V_21 -> V_25 = F_70 ( V_23 -> V_28 , V_21 , & F_65 ) ;
if ( F_71 ( V_21 -> V_25 ) ) {
int V_134 = F_72 ( V_21 -> V_25 ) ;
F_73 ( V_21 ) ;
return V_134 ;
}
V_21 -> V_63 = F_69 ( sizeof( struct V_47 ) +
sizeof( struct V_161 ) , V_158 ) ;
if ( ! V_21 -> V_63 ) {
int V_134 = F_72 ( V_21 -> V_63 ) ;
F_73 ( V_21 ) ;
return V_134 ;
}
V_21 -> V_129 = V_130 ;
F_8 ( V_23 , L_22 , V_21 , V_21 -> V_25 ) ;
return 0 ;
}
static int F_74 ( struct V_102 * V_102 )
{
struct V_22 * V_23 = F_68 ( V_102 ) ;
struct V_20 * V_21 = V_102 -> V_160 ;
F_8 ( V_23 , L_23 , V_21 ) ;
F_75 ( V_21 -> V_25 ) ;
F_73 ( V_21 -> V_63 ) ;
F_73 ( V_21 ) ;
return 0 ;
}
static unsigned int F_76 ( struct V_102 * V_102 ,
struct V_162 * V_163 )
{
struct V_20 * V_21 = V_102 -> V_160 ;
int V_134 ;
F_11 ( V_21 ) ;
V_134 = F_77 ( V_102 , V_21 -> V_25 , V_163 ) ;
F_13 ( V_21 ) ;
return V_134 ;
}
static int F_78 ( struct V_102 * V_102 , struct V_164 * V_165 )
{
struct V_20 * V_21 = V_102 -> V_160 ;
return F_79 ( V_102 , V_21 -> V_25 , V_165 ) ;
}
static int F_80 ( struct V_166 * V_167 )
{
struct V_22 * V_23 ;
struct V_168 * V_169 ;
T_3 V_170 ;
int V_134 = 0 ;
V_23 = F_69 ( sizeof *V_23 , V_158 ) ;
if ( ! V_23 )
return - V_159 ;
F_81 ( & V_23 -> V_171 ) ;
F_82 ( V_170 ) ;
F_83 ( V_172 , V_170 ) ;
V_23 -> V_42 = F_84 ( V_170 , NULL , V_23 ) ;
if ( ! V_23 -> V_42 )
goto V_173;
if ( ! F_85 ( V_172 , V_23 -> V_42 -> V_46 -> V_174 ) ) {
F_24 ( & V_23 -> V_61 , L_24 ) ;
goto V_175;
}
V_134 = F_86 ( & V_167 -> V_24 , & V_23 -> V_61 ) ;
if ( V_134 )
goto V_175;
F_16 ( & V_23 -> V_26 , 0 ) ;
F_87 ( & V_23 -> V_29 ) ;
V_169 = F_88 () ;
if ( ! V_169 ) {
F_24 ( & V_23 -> V_61 , L_25 ) ;
V_134 = - V_159 ;
goto V_176;
}
* V_169 = V_177 ;
V_169 -> V_178 = & V_23 -> V_29 ;
V_134 = F_89 ( V_169 , V_179 , 0 ) ;
if ( V_134 ) {
F_24 ( & V_23 -> V_61 , L_26 ) ;
goto V_180;
}
F_90 ( V_169 , V_23 ) ;
snprintf ( V_169 -> V_121 , sizeof( V_169 -> V_121 ) , L_27 , V_177 . V_121 ) ;
V_23 -> V_169 = V_169 ;
F_91 ( & V_23 -> V_61 , V_181
L_28 , V_169 -> V_118 ) ;
F_92 ( V_167 , V_23 ) ;
V_23 -> V_144 = F_93 ( & V_167 -> V_24 ) ;
if ( F_71 ( V_23 -> V_144 ) ) {
F_24 ( & V_23 -> V_61 , L_29 ) ;
V_134 = F_72 ( V_23 -> V_144 ) ;
goto V_182;
}
V_23 -> V_28 = F_94 ( & V_183 ) ;
if ( F_71 ( V_23 -> V_28 ) ) {
F_24 ( & V_23 -> V_61 , L_30 ) ;
V_134 = F_72 ( V_23 -> V_28 ) ;
goto V_184;
}
return 0 ;
F_95 ( V_23 -> V_28 ) ;
V_184:
F_96 ( V_23 -> V_169 ) ;
V_182:
F_97 ( V_23 -> V_144 ) ;
V_180:
F_98 ( V_169 ) ;
V_176:
F_99 ( & V_23 -> V_61 ) ;
V_175:
F_100 ( V_23 -> V_42 ) ;
V_173:
F_73 ( V_23 ) ;
return V_134 ;
}
static int F_101 ( struct V_166 * V_167 )
{
struct V_22 * V_23 =
(struct V_22 * ) F_102 ( V_167 ) ;
F_91 ( & V_23 -> V_61 , L_31 V_181 ) ;
F_95 ( V_23 -> V_28 ) ;
F_96 ( V_23 -> V_169 ) ;
F_99 ( & V_23 -> V_61 ) ;
F_97 ( V_23 -> V_144 ) ;
F_100 ( V_23 -> V_42 ) ;
F_73 ( V_23 ) ;
return 0 ;
}
static void T_4 F_103 ( void )
{
F_104 ( & V_185 ) ;
}
static int T_5 F_105 ( void )
{
return F_106 ( & V_185 ) ;
}
