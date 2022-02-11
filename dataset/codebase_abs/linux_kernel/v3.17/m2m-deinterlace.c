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
V_34 -> V_35 . V_36 = V_33 -> V_35 . V_36 ;
V_34 -> V_35 . V_37 &= ~ V_38 ;
V_34 -> V_35 . V_37 |=
V_33 -> V_35 . V_37 & V_38 ;
V_34 -> V_35 . V_39 = V_33 -> V_35 . V_39 ;
F_19 ( V_33 , V_40 ) ;
F_19 ( V_34 , V_40 ) ;
F_10 ( V_23 -> V_28 , V_31 -> V_25 ) ;
F_8 ( V_23 , L_4 ) ;
}
static void F_20 ( struct V_20 * V_21 , int V_41 ,
int V_42 )
{
struct V_1 * V_43 ;
struct V_32 * V_44 , * V_45 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_46 * V_47 = V_23 -> V_46 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_51 * V_52 ;
unsigned int V_53 , V_54 ;
unsigned int V_55 ;
T_1 V_56 , V_57 ;
enum V_58 V_37 ;
V_44 = F_21 ( V_21 -> V_25 ) ;
V_45 = F_22 ( V_21 -> V_25 ) ;
V_43 = F_1 ( V_3 ) ;
V_53 = V_43 -> V_59 ;
V_54 = V_43 -> V_60 ;
V_55 = V_53 * V_54 ;
V_56 = ( T_1 ) F_23 ( V_44 , 0 ) ;
V_57 = ( T_1 ) F_23 ( V_45 , 0 ) ;
if ( ! V_56 || ! V_57 ) {
F_24 ( & V_23 -> V_61 ,
L_5 ) ;
return;
}
switch ( V_41 ) {
case V_62 :
V_21 -> V_63 -> V_64 = V_54 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 ;
V_21 -> V_63 -> V_68 = V_56 ;
V_21 -> V_63 -> V_69 = V_57 ;
break;
case V_70 :
V_21 -> V_63 -> V_64 = V_54 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 ;
V_21 -> V_63 -> V_68 = V_56 + V_55 / 2 ;
V_21 -> V_63 -> V_69 = V_57 + V_53 ;
break;
case V_71 :
V_21 -> V_63 -> V_64 = V_54 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 / 2 ;
V_21 -> V_63 -> V_68 = V_56 + V_55 ;
V_21 -> V_63 -> V_69 = V_57 + V_55 ;
break;
case V_72 :
V_21 -> V_63 -> V_64 = V_54 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 / 2 ;
V_21 -> V_63 -> V_68 = V_56 + ( 9 * V_55 ) / 8 ;
V_21 -> V_63 -> V_69 = V_57 + V_55 + V_53 / 2 ;
break;
case V_73 :
V_21 -> V_63 -> V_64 = V_54 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 / 2 ;
V_21 -> V_63 -> V_68 = V_56 + ( 5 * V_55 ) / 4 ;
V_21 -> V_63 -> V_69 = V_57 + ( 5 * V_55 ) / 4 ;
break;
case V_74 :
V_21 -> V_63 -> V_64 = V_54 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 / 2 ;
V_21 -> V_63 -> V_68 = V_56 + ( 11 * V_55 ) / 8 ;
V_21 -> V_63 -> V_69 = V_57 + ( 5 * V_55 ) / 4 + V_53 / 2 ;
break;
case V_75 :
V_21 -> V_63 -> V_64 = V_54 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 ;
V_21 -> V_63 -> V_68 = V_56 ;
V_21 -> V_63 -> V_69 = V_57 + V_53 ;
break;
case V_76 :
V_21 -> V_63 -> V_64 = V_54 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 / 2 ;
V_21 -> V_63 -> V_68 = V_56 + V_55 ;
V_21 -> V_63 -> V_69 = V_57 + V_55 + V_53 / 2 ;
break;
case V_77 :
V_21 -> V_63 -> V_64 = V_54 / 4 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 / 2 ;
V_21 -> V_63 -> V_68 = V_56 + ( 5 * V_55 ) / 4 ;
V_21 -> V_63 -> V_69 = V_57 + ( 5 * V_55 ) / 4 + V_53 / 2 ;
break;
case V_78 :
V_21 -> V_63 -> V_64 = V_54 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 * 2 ;
V_21 -> V_63 -> V_68 = V_56 ;
V_21 -> V_63 -> V_69 = V_57 ;
break;
case V_79 :
V_21 -> V_63 -> V_64 = V_54 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 * 2 ;
V_21 -> V_63 -> V_68 = V_56 + V_55 ;
V_21 -> V_63 -> V_69 = V_57 + V_53 * 2 ;
break;
case V_80 :
default:
V_21 -> V_63 -> V_64 = V_54 / 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_66 = V_53 * 2 ;
V_21 -> V_63 -> V_65 [ 0 ] . V_67 = V_53 * 2 ;
V_21 -> V_63 -> V_68 = V_56 ;
V_21 -> V_63 -> V_69 = V_57 + V_53 * 2 ;
break;
}
V_21 -> V_63 -> V_81 = 1 ;
V_21 -> V_63 -> V_82 = V_83 ;
V_21 -> V_63 -> V_84 = false ;
V_21 -> V_63 -> V_85 = true ;
V_37 = V_86 | V_87 ;
V_52 = V_49 -> V_88 ( V_47 , V_21 -> V_63 , V_37 ) ;
if ( V_52 == NULL ) {
F_25 ( & V_23 -> V_61 , L_6 ) ;
return;
}
if ( V_42 ) {
V_52 -> V_89 = F_15 ;
V_52 -> V_90 = V_21 ;
}
V_21 -> V_91 = F_26 ( V_52 ) ;
if ( F_27 ( V_21 -> V_91 ) ) {
F_25 ( & V_23 -> V_61 ,
L_7 ,
V_21 -> V_91 , ( unsigned ) V_56 , ( unsigned ) V_57 ,
V_55 * 3 / 2 ) ;
return;
}
F_28 ( V_47 ) ;
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
V_10 -> V_11 . V_17 . V_59 = V_4 -> V_59 ;
V_10 -> V_11 . V_17 . V_60 = V_4 -> V_60 ;
V_10 -> V_11 . V_17 . V_95 = V_4 -> V_95 ;
V_10 -> V_11 . V_17 . V_18 = V_4 -> V_11 -> V_16 ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_94 :
V_10 -> V_11 . V_17 . V_125 = V_4 -> V_59 * 3 / 2 ;
break;
case V_99 :
default:
V_10 -> V_11 . V_17 . V_125 = V_4 -> V_59 * 2 ;
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
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_59 * 3 / 2 ;
break;
case V_99 :
default:
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_59 * 2 ;
}
V_10 -> V_11 . V_17 . V_126 = V_10 -> V_11 . V_17 . V_60 * V_10 -> V_11 . V_17 . V_125 ;
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
V_10 -> type , V_10 -> V_11 . V_17 . V_59 , V_10 -> V_11 . V_17 . V_60 ,
V_10 -> V_11 . V_17 . V_18 , V_10 -> V_11 . V_17 . V_95 ) ;
return - V_120 ;
}
V_4 -> V_59 = V_10 -> V_11 . V_17 . V_59 ;
V_4 -> V_60 = V_10 -> V_11 . V_17 . V_60 ;
V_4 -> V_95 = V_10 -> V_11 . V_17 . V_95 ;
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_94 :
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_59 * 3 / 2 ;
V_4 -> V_126 = ( V_4 -> V_59 * V_4 -> V_60 * 3 ) / 2 ;
break;
case V_99 :
default:
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_59 * 2 ;
V_4 -> V_126 = V_4 -> V_59 * V_4 -> V_60 * 2 ;
}
F_8 ( V_21 -> V_24 ,
L_16 ,
V_10 -> type , V_4 -> V_59 , V_4 -> V_60 , V_4 -> V_11 -> V_16 ,
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
struct V_1 * V_43 , * V_137 ;
struct V_20 * V_21 = V_19 ;
V_43 = F_1 ( V_3 ) ;
V_137 = F_1 ( V_6 ) ;
if ( V_43 -> V_11 -> V_16 != V_137 -> V_11 -> V_16 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_17 ) ;
return - V_120 ;
}
switch ( V_43 -> V_95 ) {
case V_130 :
if ( V_137 -> V_95 != V_98 &&
V_137 -> V_95 != V_97 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_18 ,
V_43 -> V_95 , V_137 -> V_95 ) ;
return - V_120 ;
}
break;
case V_129 :
if ( V_137 -> V_95 != V_98 &&
V_137 -> V_95 != V_96 ) {
F_24 ( & V_21 -> V_24 -> V_61 ,
L_18 ,
V_43 -> V_95 , V_137 -> V_95 ) ;
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
const struct V_9 * V_11 ,
unsigned int * V_138 , unsigned int * V_139 ,
unsigned int V_140 [] , void * V_141 [] )
{
struct V_20 * V_21 = F_59 ( V_124 ) ;
struct V_1 * V_4 ;
unsigned int V_66 , V_142 = * V_138 ;
V_4 = F_1 ( V_124 -> type ) ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_94 :
V_66 = V_4 -> V_59 * V_4 -> V_60 * 3 / 2 ;
break;
case V_99 :
default:
V_66 = V_4 -> V_59 * V_4 -> V_60 * 2 ;
}
* V_139 = 1 ;
* V_138 = V_142 ;
V_140 [ 0 ] = V_66 ;
V_141 [ 0 ] = V_21 -> V_24 -> V_143 ;
F_8 ( V_21 -> V_24 , L_19 , V_142 , V_66 ) ;
return 0 ;
}
static int F_60 ( struct V_32 * V_144 )
{
struct V_20 * V_21 = F_59 ( V_144 -> V_123 ) ;
struct V_1 * V_4 ;
F_8 ( V_21 -> V_24 , L_20 , V_144 -> V_123 -> type ) ;
V_4 = F_1 ( V_144 -> V_123 -> type ) ;
if ( F_61 ( V_144 , 0 ) < V_4 -> V_126 ) {
F_8 ( V_21 -> V_24 , L_21 ,
V_93 , F_61 ( V_144 , 0 ) , ( long ) V_4 -> V_126 ) ;
return - V_120 ;
}
F_62 ( V_144 , 0 , V_4 -> V_126 ) ;
return 0 ;
}
static void F_63 ( struct V_32 * V_144 )
{
struct V_20 * V_21 = F_59 ( V_144 -> V_123 ) ;
F_64 ( V_21 -> V_25 , V_144 ) ;
}
static int F_65 ( void * V_19 , struct V_123 * V_145 ,
struct V_123 * V_146 )
{
struct V_20 * V_21 = V_19 ;
int V_132 ;
V_145 -> type = V_3 ;
V_145 -> V_147 = V_148 | V_149 ;
V_145 -> V_150 = V_21 ;
V_145 -> V_151 = sizeof( struct V_152 ) ;
V_145 -> V_153 = & V_154 ;
V_145 -> V_155 = & V_156 ;
V_145 -> V_157 = V_158 ;
V_4 [ V_5 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_5 ] . V_59 = 640 ;
V_4 [ V_5 ] . V_60 = 480 ;
V_4 [ V_5 ] . V_126 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_95 = V_129 ;
V_132 = F_66 ( V_145 ) ;
if ( V_132 )
return V_132 ;
V_146 -> type = V_6 ;
V_146 -> V_147 = V_148 | V_149 ;
V_146 -> V_150 = V_21 ;
V_146 -> V_151 = sizeof( struct V_152 ) ;
V_146 -> V_153 = & V_154 ;
V_146 -> V_155 = & V_156 ;
V_146 -> V_157 = V_158 ;
V_4 [ V_7 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_7 ] . V_59 = 640 ;
V_4 [ V_7 ] . V_60 = 480 ;
V_4 [ V_7 ] . V_126 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_95 = V_96 ;
return F_66 ( V_146 ) ;
}
static int F_67 ( struct V_100 * V_100 )
{
struct V_22 * V_23 = F_68 ( V_100 ) ;
struct V_20 * V_21 = NULL ;
V_21 = F_69 ( sizeof *V_21 , V_159 ) ;
if ( ! V_21 )
return - V_160 ;
V_100 -> V_161 = V_21 ;
V_21 -> V_24 = V_23 ;
V_21 -> V_25 = F_70 ( V_23 -> V_28 , V_21 , & F_65 ) ;
if ( F_71 ( V_21 -> V_25 ) ) {
int V_132 = F_72 ( V_21 -> V_25 ) ;
F_73 ( V_21 ) ;
return V_132 ;
}
V_21 -> V_63 = F_69 ( sizeof( struct V_162 ) +
sizeof( struct V_163 ) , V_159 ) ;
if ( ! V_21 -> V_63 ) {
F_73 ( V_21 ) ;
return - V_160 ;
}
V_21 -> V_127 = V_128 ;
F_8 ( V_23 , L_22 , V_21 , V_21 -> V_25 ) ;
return 0 ;
}
static int F_74 ( struct V_100 * V_100 )
{
struct V_22 * V_23 = F_68 ( V_100 ) ;
struct V_20 * V_21 = V_100 -> V_161 ;
F_8 ( V_23 , L_23 , V_21 ) ;
F_75 ( V_21 -> V_25 ) ;
F_73 ( V_21 -> V_63 ) ;
F_73 ( V_21 ) ;
return 0 ;
}
static unsigned int F_76 ( struct V_100 * V_100 ,
struct V_164 * V_165 )
{
struct V_20 * V_21 = V_100 -> V_161 ;
int V_132 ;
F_11 ( V_21 ) ;
V_132 = F_77 ( V_100 , V_21 -> V_25 , V_165 ) ;
F_13 ( V_21 ) ;
return V_132 ;
}
static int F_78 ( struct V_100 * V_100 , struct V_166 * V_167 )
{
struct V_20 * V_21 = V_100 -> V_161 ;
return F_79 ( V_100 , V_21 -> V_25 , V_167 ) ;
}
static int F_80 ( struct V_168 * V_169 )
{
struct V_22 * V_23 ;
struct V_170 * V_171 ;
T_3 V_172 ;
int V_132 = 0 ;
V_23 = F_81 ( & V_169 -> V_24 , sizeof( * V_23 ) , V_159 ) ;
if ( ! V_23 )
return - V_160 ;
F_82 ( & V_23 -> V_173 ) ;
F_83 ( V_172 ) ;
F_84 ( V_174 , V_172 ) ;
V_23 -> V_46 = F_85 ( V_172 , NULL , V_23 ) ;
if ( ! V_23 -> V_46 )
return - V_175 ;
if ( ! F_86 ( V_174 , V_23 -> V_46 -> V_50 -> V_176 ) ) {
F_24 ( & V_23 -> V_61 , L_24 ) ;
goto V_177;
}
V_132 = F_87 ( & V_169 -> V_24 , & V_23 -> V_61 ) ;
if ( V_132 )
goto V_177;
F_16 ( & V_23 -> V_26 , 0 ) ;
F_88 ( & V_23 -> V_29 ) ;
V_171 = F_89 () ;
if ( ! V_171 ) {
F_24 ( & V_23 -> V_61 , L_25 ) ;
V_132 = - V_160 ;
goto V_178;
}
* V_171 = V_179 ;
V_171 -> V_180 = & V_23 -> V_29 ;
V_171 -> V_61 = & V_23 -> V_61 ;
V_132 = F_90 ( V_171 , V_181 , 0 ) ;
if ( V_132 ) {
F_24 ( & V_23 -> V_61 , L_26 ) ;
goto V_182;
}
F_91 ( V_171 , V_23 ) ;
snprintf ( V_171 -> V_119 , sizeof( V_171 -> V_119 ) , L_27 , V_179 . V_119 ) ;
V_23 -> V_171 = V_171 ;
F_92 ( & V_23 -> V_61 , V_183
L_28 , V_171 -> V_116 ) ;
F_93 ( V_169 , V_23 ) ;
V_23 -> V_143 = F_94 ( & V_169 -> V_24 ) ;
if ( F_71 ( V_23 -> V_143 ) ) {
F_24 ( & V_23 -> V_61 , L_29 ) ;
V_132 = F_72 ( V_23 -> V_143 ) ;
goto V_184;
}
V_23 -> V_28 = F_95 ( & V_185 ) ;
if ( F_71 ( V_23 -> V_28 ) ) {
F_24 ( & V_23 -> V_61 , L_30 ) ;
V_132 = F_72 ( V_23 -> V_28 ) ;
goto V_186;
}
return 0 ;
F_96 ( V_23 -> V_28 ) ;
V_186:
F_97 ( V_23 -> V_171 ) ;
V_184:
F_98 ( V_23 -> V_143 ) ;
V_182:
F_99 ( V_171 ) ;
V_178:
F_100 ( & V_23 -> V_61 ) ;
V_177:
F_101 ( V_23 -> V_46 ) ;
return V_132 ;
}
static int F_102 ( struct V_168 * V_169 )
{
struct V_22 * V_23 = F_103 ( V_169 ) ;
F_92 ( & V_23 -> V_61 , L_31 V_183 ) ;
F_96 ( V_23 -> V_28 ) ;
F_97 ( V_23 -> V_171 ) ;
F_100 ( & V_23 -> V_61 ) ;
F_98 ( V_23 -> V_143 ) ;
F_101 ( V_23 -> V_46 ) ;
return 0 ;
}
