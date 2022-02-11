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
V_34 -> V_35 = V_33 -> V_35 ;
V_34 -> V_36 &= ~ V_37 ;
V_34 -> V_36 |=
V_33 -> V_36 & V_37 ;
V_34 -> V_38 = V_33 -> V_38 ;
F_19 ( V_33 , V_39 ) ;
F_19 ( V_34 , V_39 ) ;
F_10 ( V_23 -> V_28 , V_31 -> V_25 ) ;
F_8 ( V_23 , L_4 ) ;
}
static void F_20 ( struct V_20 * V_21 , int V_40 ,
int V_41 )
{
struct V_1 * V_42 ;
struct V_32 * V_43 , * V_44 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_45 * V_46 = V_23 -> V_45 ;
struct V_47 * V_48 = V_46 -> V_49 ;
struct V_50 * V_51 ;
unsigned int V_52 , V_53 ;
unsigned int V_54 ;
T_1 V_55 , V_56 ;
enum V_57 V_36 ;
V_43 = F_21 ( V_21 -> V_25 ) ;
V_44 = F_22 ( V_21 -> V_25 ) ;
V_42 = F_1 ( V_3 ) ;
V_52 = V_42 -> V_58 ;
V_53 = V_42 -> V_59 ;
V_54 = V_52 * V_53 ;
V_55 = ( T_1 ) F_23 ( & V_43 -> V_60 , 0 ) ;
V_56 = ( T_1 ) F_23 ( & V_44 -> V_60 ,
0 ) ;
if ( ! V_55 || ! V_56 ) {
F_24 ( & V_23 -> V_61 ,
L_5 ) ;
return;
}
switch ( V_40 ) {
case V_62 :
V_21 -> V_63 -> V_64 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 ;
break;
case V_70 :
V_21 -> V_63 -> V_64 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 / 2 ;
V_21 -> V_63 -> V_69 = V_56 + V_52 ;
break;
case V_71 :
V_21 -> V_63 -> V_64 = V_53 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 ;
V_21 -> V_63 -> V_69 = V_56 + V_54 ;
break;
case V_72 :
V_21 -> V_63 -> V_64 = V_53 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 9 * V_54 ) / 8 ;
V_21 -> V_63 -> V_69 = V_56 + V_54 + V_52 / 2 ;
break;
case V_73 :
V_21 -> V_63 -> V_64 = V_53 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 5 * V_54 ) / 4 ;
V_21 -> V_63 -> V_69 = V_56 + ( 5 * V_54 ) / 4 ;
break;
case V_74 :
V_21 -> V_63 -> V_64 = V_53 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 11 * V_54 ) / 8 ;
V_21 -> V_63 -> V_69 = V_56 + ( 5 * V_54 ) / 4 + V_52 / 2 ;
break;
case V_75 :
V_21 -> V_63 -> V_64 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 + V_52 ;
break;
case V_76 :
V_21 -> V_63 -> V_64 = V_53 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 ;
V_21 -> V_63 -> V_69 = V_56 + V_54 + V_52 / 2 ;
break;
case V_77 :
V_21 -> V_63 -> V_64 = V_53 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 / 2 ;
V_21 -> V_63 -> V_68 = V_55 + ( 5 * V_54 ) / 4 ;
V_21 -> V_63 -> V_69 = V_56 + ( 5 * V_54 ) / 4 + V_52 / 2 ;
break;
case V_78 :
V_21 -> V_63 -> V_64 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 * 2 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 ;
break;
case V_79 :
V_21 -> V_63 -> V_64 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 * 2 ;
V_21 -> V_63 -> V_68 = V_55 + V_54 ;
V_21 -> V_63 -> V_69 = V_56 + V_52 * 2 ;
break;
case V_80 :
default:
V_21 -> V_63 -> V_64 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_52 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_52 * 2 ;
V_21 -> V_63 -> V_68 = V_55 ;
V_21 -> V_63 -> V_69 = V_56 + V_52 * 2 ;
break;
}
V_21 -> V_63 -> V_81 = 1 ;
V_21 -> V_63 -> V_82 = V_83 ;
V_21 -> V_63 -> V_84 = false ;
V_21 -> V_63 -> V_85 = true ;
V_36 = V_86 | V_87 ;
V_51 = V_48 -> V_88 ( V_46 , V_21 -> V_63 , V_36 ) ;
if ( V_51 == NULL ) {
F_25 ( & V_23 -> V_61 , L_6 ) ;
return;
}
if ( V_41 ) {
V_51 -> V_89 = F_15 ;
V_51 -> V_90 = V_21 ;
}
V_21 -> V_91 = F_26 ( V_51 ) ;
if ( F_27 ( V_21 -> V_91 ) ) {
F_25 ( & V_23 -> V_61 ,
L_7 ,
V_21 -> V_91 , ( unsigned ) V_55 , ( unsigned ) V_56 ,
V_54 * 3 / 2 ) ;
return;
}
F_28 ( V_46 ) ;
}
static void F_29 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_92 ;
F_16 ( & V_21 -> V_24 -> V_26 , 1 ) ;
F_8 ( V_21 -> V_24 , L_8 , V_93 ) ;
V_92 = F_1 ( V_6 ) ;
switch ( V_92 -> V_11 -> V_16 ) {
case V_94 :
switch ( V_92 -> V_95 ) {
case V_96 :
case V_97 :
F_8 ( V_21 -> V_24 , L_9 ,
V_93 ) ;
F_20 ( V_21 , V_62 , 0 ) ;
F_20 ( V_21 , V_70 , 0 ) ;
F_20 ( V_21 , V_71 , 0 ) ;
F_20 ( V_21 , V_72 , 0 ) ;
F_20 ( V_21 , V_73 , 0 ) ;
F_20 ( V_21 , V_74 , 1 ) ;
break;
case V_98 :
default:
F_8 ( V_21 -> V_24 , L_10 ,
V_93 ) ;
F_20 ( V_21 , V_62 , 0 ) ;
F_20 ( V_21 , V_75 , 0 ) ;
F_20 ( V_21 , V_71 , 0 ) ;
F_20 ( V_21 , V_76 , 0 ) ;
F_20 ( V_21 , V_73 , 0 ) ;
F_20 ( V_21 , V_77 , 1 ) ;
break;
}
break;
case V_99 :
default:
switch ( V_92 -> V_95 ) {
case V_96 :
case V_97 :
F_8 ( V_21 -> V_24 , L_11 ,
V_93 ) ;
F_20 ( V_21 , V_78 , 0 ) ;
F_20 ( V_21 , V_79 , 1 ) ;
break;
case V_98 :
default:
F_8 ( V_21 -> V_24 , L_12 ,
V_93 ) ;
F_20 ( V_21 , V_78 , 0 ) ;
F_20 ( V_21 , V_80 , 1 ) ;
break;
}
break;
}
F_8 ( V_21 -> V_24 , L_13 , V_93 ) ;
}
static int F_30 ( struct V_100 * V_100 , void * V_19 ,
struct V_101 * V_102 )
{
F_31 ( V_102 -> V_103 , V_104 , sizeof( V_102 -> V_103 ) ) ;
F_31 ( V_102 -> V_105 , V_104 , sizeof( V_102 -> V_105 ) ) ;
F_31 ( V_102 -> V_106 , V_104 , sizeof( V_102 -> V_105 ) ) ;
V_102 -> V_107 = V_108 | V_109 |
V_110 | V_111 ;
V_102 -> V_112 = V_102 -> V_107 | V_113 ;
return 0 ;
}
static int F_32 ( struct V_114 * V_10 , T_2 type )
{
int V_115 , V_116 ;
struct V_8 * V_11 ;
V_116 = 0 ;
for ( V_115 = 0 ; V_115 < V_13 ; ++ V_115 ) {
if ( V_14 [ V_115 ] . V_15 & type ) {
if ( V_116 == V_10 -> V_117 )
break;
++ V_116 ;
}
}
if ( V_115 < V_13 ) {
V_11 = & V_14 [ V_115 ] ;
F_31 ( V_10 -> V_118 , V_11 -> V_119 , sizeof( V_10 -> V_118 ) ) ;
V_10 -> V_18 = V_11 -> V_16 ;
return 0 ;
}
return - V_120 ;
}
static int F_33 ( struct V_100 * V_100 , void * V_19 ,
struct V_114 * V_10 )
{
return F_32 ( V_10 , V_121 ) ;
}
static int F_34 ( struct V_100 * V_100 , void * V_19 ,
struct V_114 * V_10 )
{
return F_32 ( V_10 , V_122 ) ;
}
static int F_35 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_123 * V_124 ;
struct V_1 * V_4 ;
V_124 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_124 )
return - V_120 ;
V_4 = F_1 ( V_10 -> type ) ;
V_10 -> V_11 . V_17 . V_58 = V_4 -> V_58 ;
V_10 -> V_11 . V_17 . V_59 = V_4 -> V_59 ;
V_10 -> V_11 . V_17 . V_95 = V_4 -> V_95 ;
V_10 -> V_11 . V_17 . V_18 = V_4 -> V_11 -> V_16 ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_94 :
V_10 -> V_11 . V_17 . V_125 = V_4 -> V_58 * 3 / 2 ;
break;
case V_99 :
default:
V_10 -> V_11 . V_17 . V_125 = V_4 -> V_58 * 2 ;
}
V_10 -> V_11 . V_17 . V_126 = V_4 -> V_126 ;
V_10 -> V_11 . V_17 . V_127 = V_21 -> V_127 ;
return 0 ;
}
static int F_37 ( struct V_100 * V_100 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_38 ( struct V_100 * V_100 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_8 * V_11 )
{
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_94 :
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_58 * 3 / 2 ;
break;
case V_99 :
default:
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_58 * 2 ;
}
V_10 -> V_11 . V_17 . V_126 = V_10 -> V_11 . V_17 . V_59 * V_10 -> V_11 . V_17 . V_125 ;
return 0 ;
}
static int F_40 ( struct V_100 * V_100 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
struct V_20 * V_21 = V_19 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_121 ) )
V_10 -> V_11 . V_17 . V_18 = V_94 ;
V_10 -> V_11 . V_17 . V_127 = V_21 -> V_127 ;
if ( V_10 -> V_11 . V_17 . V_95 != V_96 &&
V_10 -> V_11 . V_17 . V_95 != V_97 &&
V_10 -> V_11 . V_17 . V_95 != V_98 )
V_10 -> V_11 . V_17 . V_95 = V_96 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_41 ( struct V_100 * V_100 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_122 ) )
V_10 -> V_11 . V_17 . V_18 = V_94 ;
if ( ! V_10 -> V_11 . V_17 . V_127 )
V_10 -> V_11 . V_17 . V_127 = V_128 ;
if ( V_10 -> V_11 . V_17 . V_95 != V_129 &&
V_10 -> V_11 . V_17 . V_95 != V_130 )
V_10 -> V_11 . V_17 . V_95 = V_129 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_42 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_1 * V_4 ;
struct V_123 * V_124 ;
V_124 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_124 )
return - V_120 ;
V_4 = F_1 ( V_10 -> type ) ;
if ( ! V_4 )
return - V_120 ;
if ( F_43 ( V_124 ) ) {
F_24 ( & V_21 -> V_24 -> V_61 , L_14 , V_93 ) ;
return - V_131 ;
}
V_4 -> V_11 = F_3 ( V_10 ) ;
if ( ! V_4 -> V_11 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_15 ,
V_10 -> type , V_10 -> V_11 . V_17 . V_58 , V_10 -> V_11 . V_17 . V_59 ,
V_10 -> V_11 . V_17 . V_18 , V_10 -> V_11 . V_17 . V_95 ) ;
return - V_120 ;
}
V_4 -> V_58 = V_10 -> V_11 . V_17 . V_58 ;
V_4 -> V_59 = V_10 -> V_11 . V_17 . V_59 ;
V_4 -> V_95 = V_10 -> V_11 . V_17 . V_95 ;
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_94 :
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_58 * 3 / 2 ;
V_4 -> V_126 = ( V_4 -> V_58 * V_4 -> V_59 * 3 ) / 2 ;
break;
case V_99 :
default:
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_58 * 2 ;
V_4 -> V_126 = V_4 -> V_58 * V_4 -> V_59 * 2 ;
}
F_8 ( V_21 -> V_24 ,
L_16 ,
V_10 -> type , V_4 -> V_58 , V_4 -> V_59 , V_4 -> V_11 -> V_16 ,
V_4 -> V_95 ) ;
return 0 ;
}
static int F_44 ( struct V_100 * V_100 , void * V_19 ,
struct V_9 * V_10 )
{
int V_132 ;
V_132 = F_40 ( V_100 , V_19 , V_10 ) ;
if ( V_132 )
return V_132 ;
return F_42 ( V_19 , V_10 ) ;
}
static int F_45 ( struct V_100 * V_100 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 = V_19 ;
int V_132 ;
V_132 = F_41 ( V_100 , V_19 , V_10 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_42 ( V_19 , V_10 ) ;
if ( ! V_132 )
V_21 -> V_127 = V_10 -> V_11 . V_17 . V_127 ;
return V_132 ;
}
static int F_46 ( struct V_100 * V_100 , void * V_19 ,
struct V_133 * V_134 )
{
struct V_20 * V_21 = V_19 ;
return F_47 ( V_100 , V_21 -> V_25 , V_134 ) ;
}
static int F_48 ( struct V_100 * V_100 , void * V_19 ,
struct V_135 * V_136 )
{
struct V_20 * V_21 = V_19 ;
return F_49 ( V_100 , V_21 -> V_25 , V_136 ) ;
}
static int F_50 ( struct V_100 * V_100 , void * V_19 , struct V_135 * V_136 )
{
struct V_20 * V_21 = V_19 ;
return F_51 ( V_100 , V_21 -> V_25 , V_136 ) ;
}
static int F_52 ( struct V_100 * V_100 , void * V_19 , struct V_135 * V_136 )
{
struct V_20 * V_21 = V_19 ;
return F_53 ( V_100 , V_21 -> V_25 , V_136 ) ;
}
static int F_54 ( struct V_100 * V_100 , void * V_19 ,
enum V_2 type )
{
struct V_1 * V_42 , * V_137 ;
struct V_20 * V_21 = V_19 ;
V_42 = F_1 ( V_3 ) ;
V_137 = F_1 ( V_6 ) ;
if ( V_42 -> V_11 -> V_16 != V_137 -> V_11 -> V_16 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_17 ) ;
return - V_120 ;
}
switch ( V_42 -> V_95 ) {
case V_130 :
if ( V_137 -> V_95 != V_98 &&
V_137 -> V_95 != V_97 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_18 ,
V_42 -> V_95 , V_137 -> V_95 ) ;
return - V_120 ;
}
break;
case V_129 :
if ( V_137 -> V_95 != V_98 &&
V_137 -> V_95 != V_96 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_18 ,
V_42 -> V_95 , V_137 -> V_95 ) ;
return - V_120 ;
}
break;
default:
return - V_120 ;
}
return F_55 ( V_100 , V_21 -> V_25 , type ) ;
}
static int F_56 ( struct V_100 * V_100 , void * V_19 ,
enum V_2 type )
{
struct V_20 * V_21 = V_19 ;
return F_57 ( V_100 , V_21 -> V_25 , type ) ;
}
static int F_58 ( struct V_123 * V_124 ,
const void * V_138 ,
unsigned int * V_139 , unsigned int * V_140 ,
unsigned int V_141 [] , void * V_142 [] )
{
struct V_20 * V_21 = F_59 ( V_124 ) ;
struct V_1 * V_4 ;
unsigned int V_66 , V_143 = * V_139 ;
V_4 = F_1 ( V_124 -> type ) ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_94 :
V_66 = V_4 -> V_58 * V_4 -> V_59 * 3 / 2 ;
break;
case V_99 :
default:
V_66 = V_4 -> V_58 * V_4 -> V_59 * 2 ;
}
* V_140 = 1 ;
* V_139 = V_143 ;
V_141 [ 0 ] = V_66 ;
V_142 [ 0 ] = V_21 -> V_24 -> V_144 ;
F_8 ( V_21 -> V_24 , L_19 , V_143 , V_66 ) ;
return 0 ;
}
static int F_60 ( struct V_145 * V_146 )
{
struct V_20 * V_21 = F_59 ( V_146 -> V_123 ) ;
struct V_1 * V_4 ;
F_8 ( V_21 -> V_24 , L_20 , V_146 -> V_123 -> type ) ;
V_4 = F_1 ( V_146 -> V_123 -> type ) ;
if ( F_61 ( V_146 , 0 ) < V_4 -> V_126 ) {
F_8 ( V_21 -> V_24 , L_21 ,
V_93 , F_61 ( V_146 , 0 ) , ( long ) V_4 -> V_126 ) ;
return - V_120 ;
}
F_62 ( V_146 , 0 , V_4 -> V_126 ) ;
return 0 ;
}
static void F_63 ( struct V_145 * V_146 )
{
struct V_32 * V_147 = F_64 ( V_146 ) ;
struct V_20 * V_21 = F_59 ( V_146 -> V_123 ) ;
F_65 ( V_21 -> V_25 , V_147 ) ;
}
static int F_66 ( void * V_19 , struct V_123 * V_148 ,
struct V_123 * V_149 )
{
struct V_20 * V_21 = V_19 ;
int V_132 ;
V_148 -> type = V_3 ;
V_148 -> V_150 = V_151 | V_152 ;
V_148 -> V_153 = V_21 ;
V_148 -> V_154 = sizeof( struct V_155 ) ;
V_148 -> V_156 = & V_157 ;
V_148 -> V_158 = & V_159 ;
V_148 -> V_160 = V_161 ;
V_4 [ V_5 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_5 ] . V_58 = 640 ;
V_4 [ V_5 ] . V_59 = 480 ;
V_4 [ V_5 ] . V_126 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_95 = V_129 ;
V_132 = F_67 ( V_148 ) ;
if ( V_132 )
return V_132 ;
V_149 -> type = V_6 ;
V_149 -> V_150 = V_151 | V_152 ;
V_149 -> V_153 = V_21 ;
V_149 -> V_154 = sizeof( struct V_155 ) ;
V_149 -> V_156 = & V_157 ;
V_149 -> V_158 = & V_159 ;
V_149 -> V_160 = V_161 ;
V_4 [ V_7 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_7 ] . V_58 = 640 ;
V_4 [ V_7 ] . V_59 = 480 ;
V_4 [ V_7 ] . V_126 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_95 = V_96 ;
return F_67 ( V_149 ) ;
}
static int F_68 ( struct V_100 * V_100 )
{
struct V_22 * V_23 = F_69 ( V_100 ) ;
struct V_20 * V_21 = NULL ;
V_21 = F_70 ( sizeof *V_21 , V_162 ) ;
if ( ! V_21 )
return - V_163 ;
V_100 -> V_164 = V_21 ;
V_21 -> V_24 = V_23 ;
V_21 -> V_25 = F_71 ( V_23 -> V_28 , V_21 , & F_66 ) ;
if ( F_72 ( V_21 -> V_25 ) ) {
int V_132 = F_73 ( V_21 -> V_25 ) ;
F_74 ( V_21 ) ;
return V_132 ;
}
V_21 -> V_63 = F_70 ( sizeof( struct V_165 ) +
sizeof( struct V_166 ) , V_162 ) ;
if ( ! V_21 -> V_63 ) {
F_74 ( V_21 ) ;
return - V_163 ;
}
V_21 -> V_127 = V_128 ;
F_8 ( V_23 , L_22 , V_21 , V_21 -> V_25 ) ;
return 0 ;
}
static int F_75 ( struct V_100 * V_100 )
{
struct V_22 * V_23 = F_69 ( V_100 ) ;
struct V_20 * V_21 = V_100 -> V_164 ;
F_8 ( V_23 , L_23 , V_21 ) ;
F_76 ( V_21 -> V_25 ) ;
F_74 ( V_21 -> V_63 ) ;
F_74 ( V_21 ) ;
return 0 ;
}
static unsigned int F_77 ( struct V_100 * V_100 ,
struct V_167 * V_168 )
{
struct V_20 * V_21 = V_100 -> V_164 ;
int V_132 ;
F_11 ( V_21 ) ;
V_132 = F_78 ( V_100 , V_21 -> V_25 , V_168 ) ;
F_13 ( V_21 ) ;
return V_132 ;
}
static int F_79 ( struct V_100 * V_100 , struct V_169 * V_170 )
{
struct V_20 * V_21 = V_100 -> V_164 ;
return F_80 ( V_100 , V_21 -> V_25 , V_170 ) ;
}
static int F_81 ( struct V_171 * V_172 )
{
struct V_22 * V_23 ;
struct V_173 * V_174 ;
T_3 V_175 ;
int V_132 = 0 ;
V_23 = F_82 ( & V_172 -> V_24 , sizeof( * V_23 ) , V_162 ) ;
if ( ! V_23 )
return - V_163 ;
F_83 ( & V_23 -> V_176 ) ;
F_84 ( V_175 ) ;
F_85 ( V_177 , V_175 ) ;
V_23 -> V_45 = F_86 ( V_175 , NULL , V_23 ) ;
if ( ! V_23 -> V_45 )
return - V_178 ;
if ( ! F_87 ( V_177 , V_23 -> V_45 -> V_49 -> V_179 ) ) {
F_24 ( & V_23 -> V_61 , L_24 ) ;
goto V_180;
}
V_132 = F_88 ( & V_172 -> V_24 , & V_23 -> V_61 ) ;
if ( V_132 )
goto V_180;
F_16 ( & V_23 -> V_26 , 0 ) ;
F_89 ( & V_23 -> V_29 ) ;
V_174 = & V_23 -> V_174 ;
* V_174 = V_181 ;
V_174 -> V_182 = & V_23 -> V_29 ;
V_174 -> V_61 = & V_23 -> V_61 ;
V_132 = F_90 ( V_174 , V_183 , 0 ) ;
if ( V_132 ) {
F_24 ( & V_23 -> V_61 , L_25 ) ;
goto V_184;
}
F_91 ( V_174 , V_23 ) ;
snprintf ( V_174 -> V_119 , sizeof( V_174 -> V_119 ) , L_26 , V_181 . V_119 ) ;
F_92 ( & V_23 -> V_61 , V_185
L_27 , V_174 -> V_116 ) ;
F_93 ( V_172 , V_23 ) ;
V_23 -> V_144 = F_94 ( & V_172 -> V_24 ) ;
if ( F_72 ( V_23 -> V_144 ) ) {
F_24 ( & V_23 -> V_61 , L_28 ) ;
V_132 = F_73 ( V_23 -> V_144 ) ;
goto V_186;
}
V_23 -> V_28 = F_95 ( & V_187 ) ;
if ( F_72 ( V_23 -> V_28 ) ) {
F_24 ( & V_23 -> V_61 , L_29 ) ;
V_132 = F_73 ( V_23 -> V_28 ) ;
goto V_188;
}
return 0 ;
V_188:
F_96 ( & V_23 -> V_174 ) ;
V_186:
F_97 ( V_23 -> V_144 ) ;
V_184:
F_98 ( & V_23 -> V_61 ) ;
V_180:
F_99 ( V_23 -> V_45 ) ;
return V_132 ;
}
static int F_100 ( struct V_171 * V_172 )
{
struct V_22 * V_23 = F_101 ( V_172 ) ;
F_92 ( & V_23 -> V_61 , L_30 V_185 ) ;
F_102 ( V_23 -> V_28 ) ;
F_96 ( & V_23 -> V_174 ) ;
F_98 ( & V_23 -> V_61 ) ;
F_97 ( V_23 -> V_144 ) ;
F_99 ( V_23 -> V_45 ) ;
return 0 ;
}
