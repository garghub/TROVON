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
struct V_1 * V_38 ;
struct V_32 * V_39 , * V_40 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_41 * V_42 = V_23 -> V_41 ;
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_46 * V_47 ;
unsigned int V_48 , V_49 ;
unsigned int V_50 ;
T_1 V_51 , V_52 ;
enum V_53 V_54 ;
V_39 = F_21 ( V_21 -> V_25 ) ;
V_40 = F_22 ( V_21 -> V_25 ) ;
V_38 = F_1 ( V_3 ) ;
V_48 = V_38 -> V_55 ;
V_49 = V_38 -> V_56 ;
V_50 = V_48 * V_49 ;
V_51 = ( T_1 ) F_23 ( V_39 , 0 ) ;
V_52 = ( T_1 ) F_23 ( V_40 , 0 ) ;
if ( ! V_51 || ! V_52 ) {
F_24 ( & V_23 -> V_57 ,
L_5 ) ;
return;
}
switch ( V_36 ) {
case V_58 :
V_21 -> V_59 -> V_60 = V_49 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 ;
V_21 -> V_59 -> V_64 = V_51 ;
V_21 -> V_59 -> V_65 = V_52 ;
break;
case V_66 :
V_21 -> V_59 -> V_60 = V_49 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 ;
V_21 -> V_59 -> V_64 = V_51 + V_50 / 2 ;
V_21 -> V_59 -> V_65 = V_52 + V_48 ;
break;
case V_67 :
V_21 -> V_59 -> V_60 = V_49 / 4 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 / 2 ;
V_21 -> V_59 -> V_64 = V_51 + V_50 ;
V_21 -> V_59 -> V_65 = V_52 + V_50 ;
break;
case V_68 :
V_21 -> V_59 -> V_60 = V_49 / 4 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 / 2 ;
V_21 -> V_59 -> V_64 = V_51 + ( 9 * V_50 ) / 8 ;
V_21 -> V_59 -> V_65 = V_52 + V_50 + V_48 / 2 ;
break;
case V_69 :
V_21 -> V_59 -> V_60 = V_49 / 4 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 / 2 ;
V_21 -> V_59 -> V_64 = V_51 + ( 5 * V_50 ) / 4 ;
V_21 -> V_59 -> V_65 = V_52 + ( 5 * V_50 ) / 4 ;
break;
case V_70 :
V_21 -> V_59 -> V_60 = V_49 / 4 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 / 2 ;
V_21 -> V_59 -> V_64 = V_51 + ( 11 * V_50 ) / 8 ;
V_21 -> V_59 -> V_65 = V_52 + ( 5 * V_50 ) / 4 + V_48 / 2 ;
break;
case V_71 :
V_21 -> V_59 -> V_60 = V_49 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 ;
V_21 -> V_59 -> V_64 = V_51 ;
V_21 -> V_59 -> V_65 = V_52 + V_48 ;
break;
case V_72 :
V_21 -> V_59 -> V_60 = V_49 / 4 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 / 2 ;
V_21 -> V_59 -> V_64 = V_51 + V_50 ;
V_21 -> V_59 -> V_65 = V_52 + V_50 + V_48 / 2 ;
break;
case V_73 :
V_21 -> V_59 -> V_60 = V_49 / 4 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 / 2 ;
V_21 -> V_59 -> V_64 = V_51 + ( 5 * V_50 ) / 4 ;
V_21 -> V_59 -> V_65 = V_52 + ( 5 * V_50 ) / 4 + V_48 / 2 ;
break;
case V_74 :
V_21 -> V_59 -> V_60 = V_49 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 * 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 * 2 ;
V_21 -> V_59 -> V_64 = V_51 ;
V_21 -> V_59 -> V_65 = V_52 ;
break;
case V_75 :
V_21 -> V_59 -> V_60 = V_49 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 * 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 * 2 ;
V_21 -> V_59 -> V_64 = V_51 + V_50 ;
V_21 -> V_59 -> V_65 = V_52 + V_48 * 2 ;
break;
case V_76 :
default:
V_21 -> V_59 -> V_60 = V_49 / 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_62 = V_48 * 2 ;
V_21 -> V_59 -> V_61 [ 0 ] . V_63 = V_48 * 2 ;
V_21 -> V_59 -> V_64 = V_51 ;
V_21 -> V_59 -> V_65 = V_52 + V_48 * 2 ;
break;
}
V_21 -> V_59 -> V_77 = 1 ;
V_21 -> V_59 -> V_78 = V_79 ;
V_21 -> V_59 -> V_80 = false ;
V_21 -> V_59 -> V_81 = true ;
V_54 = V_82 | V_83 |
V_84 | V_85 ;
V_47 = V_44 -> V_86 ( V_42 , V_21 -> V_59 , V_54 ) ;
if ( V_47 == NULL ) {
F_25 ( & V_23 -> V_57 , L_6 ) ;
return;
}
if ( V_37 ) {
V_47 -> V_87 = F_15 ;
V_47 -> V_88 = V_21 ;
}
V_21 -> V_89 = F_26 ( V_47 ) ;
if ( F_27 ( V_21 -> V_89 ) ) {
F_25 ( & V_23 -> V_57 ,
L_7 ,
V_21 -> V_89 , ( unsigned ) V_51 , ( unsigned ) V_52 ,
V_50 * 3 / 2 ) ;
return;
}
F_28 ( V_42 ) ;
}
static void F_29 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_90 ;
F_16 ( & V_21 -> V_24 -> V_26 , 1 ) ;
F_8 ( V_21 -> V_24 , L_8 , V_91 ) ;
V_90 = F_1 ( V_6 ) ;
switch ( V_90 -> V_11 -> V_16 ) {
case V_92 :
switch ( V_90 -> V_93 ) {
case V_94 :
case V_95 :
F_8 ( V_21 -> V_24 , L_9 ,
V_91 ) ;
F_20 ( V_21 , V_58 , 0 ) ;
F_20 ( V_21 , V_66 , 0 ) ;
F_20 ( V_21 , V_67 , 0 ) ;
F_20 ( V_21 , V_68 , 0 ) ;
F_20 ( V_21 , V_69 , 0 ) ;
F_20 ( V_21 , V_70 , 1 ) ;
break;
case V_96 :
default:
F_8 ( V_21 -> V_24 , L_10 ,
V_91 ) ;
F_20 ( V_21 , V_58 , 0 ) ;
F_20 ( V_21 , V_71 , 0 ) ;
F_20 ( V_21 , V_67 , 0 ) ;
F_20 ( V_21 , V_72 , 0 ) ;
F_20 ( V_21 , V_69 , 0 ) ;
F_20 ( V_21 , V_73 , 1 ) ;
break;
}
break;
case V_97 :
default:
switch ( V_90 -> V_93 ) {
case V_94 :
case V_95 :
F_8 ( V_21 -> V_24 , L_11 ,
V_91 ) ;
F_20 ( V_21 , V_74 , 0 ) ;
F_20 ( V_21 , V_75 , 1 ) ;
break;
case V_96 :
default:
F_8 ( V_21 -> V_24 , L_12 ,
V_91 ) ;
F_20 ( V_21 , V_74 , 0 ) ;
F_20 ( V_21 , V_76 , 1 ) ;
break;
}
break;
}
F_8 ( V_21 -> V_24 , L_13 , V_91 ) ;
}
static int F_30 ( struct V_98 * V_98 , void * V_19 ,
struct V_99 * V_100 )
{
F_31 ( V_100 -> V_101 , V_102 , sizeof( V_100 -> V_101 ) ) ;
F_31 ( V_100 -> V_103 , V_102 , sizeof( V_100 -> V_103 ) ) ;
F_31 ( V_100 -> V_104 , V_102 , sizeof( V_100 -> V_103 ) ) ;
V_100 -> V_105 = V_106 | V_107 |
V_108 | V_109 ;
V_100 -> V_110 = V_100 -> V_105 | V_111 ;
return 0 ;
}
static int F_32 ( struct V_112 * V_10 , T_2 type )
{
int V_113 , V_114 ;
struct V_8 * V_11 ;
V_114 = 0 ;
for ( V_113 = 0 ; V_113 < V_13 ; ++ V_113 ) {
if ( V_14 [ V_113 ] . V_15 & type ) {
if ( V_114 == V_10 -> V_115 )
break;
++ V_114 ;
}
}
if ( V_113 < V_13 ) {
V_11 = & V_14 [ V_113 ] ;
F_31 ( V_10 -> V_116 , V_11 -> V_117 , sizeof( V_10 -> V_116 ) ) ;
V_10 -> V_18 = V_11 -> V_16 ;
return 0 ;
}
return - V_118 ;
}
static int F_33 ( struct V_98 * V_98 , void * V_19 ,
struct V_112 * V_10 )
{
return F_32 ( V_10 , V_119 ) ;
}
static int F_34 ( struct V_98 * V_98 , void * V_19 ,
struct V_112 * V_10 )
{
return F_32 ( V_10 , V_120 ) ;
}
static int F_35 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_121 * V_122 ;
struct V_1 * V_4 ;
V_122 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_122 )
return - V_118 ;
V_4 = F_1 ( V_10 -> type ) ;
V_10 -> V_11 . V_17 . V_55 = V_4 -> V_55 ;
V_10 -> V_11 . V_17 . V_56 = V_4 -> V_56 ;
V_10 -> V_11 . V_17 . V_93 = V_4 -> V_93 ;
V_10 -> V_11 . V_17 . V_18 = V_4 -> V_11 -> V_16 ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_92 :
V_10 -> V_11 . V_17 . V_123 = V_4 -> V_55 * 3 / 2 ;
break;
case V_97 :
default:
V_10 -> V_11 . V_17 . V_123 = V_4 -> V_55 * 2 ;
}
V_10 -> V_11 . V_17 . V_124 = V_4 -> V_124 ;
V_10 -> V_11 . V_17 . V_125 = V_21 -> V_125 ;
return 0 ;
}
static int F_37 ( struct V_98 * V_98 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_38 ( struct V_98 * V_98 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_8 * V_11 )
{
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_92 :
V_10 -> V_11 . V_17 . V_123 = V_10 -> V_11 . V_17 . V_55 * 3 / 2 ;
break;
case V_97 :
default:
V_10 -> V_11 . V_17 . V_123 = V_10 -> V_11 . V_17 . V_55 * 2 ;
}
V_10 -> V_11 . V_17 . V_124 = V_10 -> V_11 . V_17 . V_56 * V_10 -> V_11 . V_17 . V_123 ;
return 0 ;
}
static int F_40 ( struct V_98 * V_98 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
struct V_20 * V_21 = V_19 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_119 ) )
V_10 -> V_11 . V_17 . V_18 = V_92 ;
V_10 -> V_11 . V_17 . V_125 = V_21 -> V_125 ;
if ( V_10 -> V_11 . V_17 . V_93 != V_94 &&
V_10 -> V_11 . V_17 . V_93 != V_95 &&
V_10 -> V_11 . V_17 . V_93 != V_96 )
V_10 -> V_11 . V_17 . V_93 = V_94 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_41 ( struct V_98 * V_98 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_120 ) )
V_10 -> V_11 . V_17 . V_18 = V_92 ;
if ( ! V_10 -> V_11 . V_17 . V_125 )
V_10 -> V_11 . V_17 . V_125 = V_126 ;
if ( V_10 -> V_11 . V_17 . V_93 != V_127 &&
V_10 -> V_11 . V_17 . V_93 != V_128 )
V_10 -> V_11 . V_17 . V_93 = V_127 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_42 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_1 * V_4 ;
struct V_121 * V_122 ;
V_122 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_122 )
return - V_118 ;
V_4 = F_1 ( V_10 -> type ) ;
if ( ! V_4 )
return - V_118 ;
if ( F_43 ( V_122 ) ) {
F_24 ( & V_21 -> V_24 -> V_57 , L_14 , V_91 ) ;
return - V_129 ;
}
V_4 -> V_11 = F_3 ( V_10 ) ;
if ( ! V_4 -> V_11 ) {
F_24 ( & V_21 -> V_24 -> V_57 ,
L_15 ,
V_10 -> type , V_10 -> V_11 . V_17 . V_55 , V_10 -> V_11 . V_17 . V_56 ,
V_10 -> V_11 . V_17 . V_18 , V_10 -> V_11 . V_17 . V_93 ) ;
return - V_118 ;
}
V_4 -> V_55 = V_10 -> V_11 . V_17 . V_55 ;
V_4 -> V_56 = V_10 -> V_11 . V_17 . V_56 ;
V_4 -> V_93 = V_10 -> V_11 . V_17 . V_93 ;
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_92 :
V_10 -> V_11 . V_17 . V_123 = V_10 -> V_11 . V_17 . V_55 * 3 / 2 ;
V_4 -> V_124 = ( V_4 -> V_55 * V_4 -> V_56 * 3 ) / 2 ;
break;
case V_97 :
default:
V_10 -> V_11 . V_17 . V_123 = V_10 -> V_11 . V_17 . V_55 * 2 ;
V_4 -> V_124 = V_4 -> V_55 * V_4 -> V_56 * 2 ;
}
F_8 ( V_21 -> V_24 ,
L_16 ,
V_10 -> type , V_4 -> V_55 , V_4 -> V_56 , V_4 -> V_11 -> V_16 ,
V_4 -> V_93 ) ;
return 0 ;
}
static int F_44 ( struct V_98 * V_98 , void * V_19 ,
struct V_9 * V_10 )
{
int V_130 ;
V_130 = F_40 ( V_98 , V_19 , V_10 ) ;
if ( V_130 )
return V_130 ;
return F_42 ( V_19 , V_10 ) ;
}
static int F_45 ( struct V_98 * V_98 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 = V_19 ;
int V_130 ;
V_130 = F_41 ( V_98 , V_19 , V_10 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_42 ( V_19 , V_10 ) ;
if ( ! V_130 )
V_21 -> V_125 = V_10 -> V_11 . V_17 . V_125 ;
return V_130 ;
}
static int F_46 ( struct V_98 * V_98 , void * V_19 ,
struct V_131 * V_132 )
{
struct V_20 * V_21 = V_19 ;
return F_47 ( V_98 , V_21 -> V_25 , V_132 ) ;
}
static int F_48 ( struct V_98 * V_98 , void * V_19 ,
struct V_133 * V_134 )
{
struct V_20 * V_21 = V_19 ;
return F_49 ( V_98 , V_21 -> V_25 , V_134 ) ;
}
static int F_50 ( struct V_98 * V_98 , void * V_19 , struct V_133 * V_134 )
{
struct V_20 * V_21 = V_19 ;
return F_51 ( V_98 , V_21 -> V_25 , V_134 ) ;
}
static int F_52 ( struct V_98 * V_98 , void * V_19 , struct V_133 * V_134 )
{
struct V_20 * V_21 = V_19 ;
return F_53 ( V_98 , V_21 -> V_25 , V_134 ) ;
}
static int F_54 ( struct V_98 * V_98 , void * V_19 ,
enum V_2 type )
{
struct V_1 * V_38 , * V_135 ;
struct V_20 * V_21 = V_19 ;
V_38 = F_1 ( V_3 ) ;
V_135 = F_1 ( V_6 ) ;
if ( V_38 -> V_11 -> V_16 != V_135 -> V_11 -> V_16 ) {
F_24 ( & V_21 -> V_24 -> V_57 ,
L_17 ) ;
return - V_118 ;
}
switch ( V_38 -> V_93 ) {
case V_128 :
if ( V_135 -> V_93 != V_96 &&
V_135 -> V_93 != V_95 ) {
F_24 ( & V_21 -> V_24 -> V_57 ,
L_18 ,
V_38 -> V_93 , V_135 -> V_93 ) ;
return - V_118 ;
}
break;
case V_127 :
if ( V_135 -> V_93 != V_96 &&
V_135 -> V_93 != V_94 ) {
F_24 ( & V_21 -> V_24 -> V_57 ,
L_18 ,
V_38 -> V_93 , V_135 -> V_93 ) ;
return - V_118 ;
}
break;
default:
return - V_118 ;
}
return F_55 ( V_98 , V_21 -> V_25 , type ) ;
}
static int F_56 ( struct V_98 * V_98 , void * V_19 ,
enum V_2 type )
{
struct V_20 * V_21 = V_19 ;
return F_57 ( V_98 , V_21 -> V_25 , type ) ;
}
static int F_58 ( struct V_121 * V_122 ,
const struct V_9 * V_11 ,
unsigned int * V_136 , unsigned int * V_137 ,
unsigned int V_138 [] , void * V_139 [] )
{
struct V_20 * V_21 = F_59 ( V_122 ) ;
struct V_1 * V_4 ;
unsigned int V_62 , V_140 = * V_136 ;
V_4 = F_1 ( V_122 -> type ) ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_92 :
V_62 = V_4 -> V_55 * V_4 -> V_56 * 3 / 2 ;
break;
case V_97 :
default:
V_62 = V_4 -> V_55 * V_4 -> V_56 * 2 ;
}
* V_137 = 1 ;
* V_136 = V_140 ;
V_138 [ 0 ] = V_62 ;
V_139 [ 0 ] = V_21 -> V_24 -> V_141 ;
F_8 ( V_21 -> V_24 , L_19 , V_140 , V_62 ) ;
return 0 ;
}
static int F_60 ( struct V_32 * V_142 )
{
struct V_20 * V_21 = F_59 ( V_142 -> V_121 ) ;
struct V_1 * V_4 ;
F_8 ( V_21 -> V_24 , L_20 , V_142 -> V_121 -> type ) ;
V_4 = F_1 ( V_142 -> V_121 -> type ) ;
if ( F_61 ( V_142 , 0 ) < V_4 -> V_124 ) {
F_8 ( V_21 -> V_24 , L_21 ,
V_91 , F_61 ( V_142 , 0 ) , ( long ) V_4 -> V_124 ) ;
return - V_118 ;
}
F_62 ( V_142 , 0 , V_4 -> V_124 ) ;
return 0 ;
}
static void F_63 ( struct V_32 * V_142 )
{
struct V_20 * V_21 = F_59 ( V_142 -> V_121 ) ;
F_64 ( V_21 -> V_25 , V_142 ) ;
}
static int F_65 ( void * V_19 , struct V_121 * V_143 ,
struct V_121 * V_144 )
{
struct V_20 * V_21 = V_19 ;
int V_130 ;
V_143 -> type = V_3 ;
V_143 -> V_145 = V_146 | V_147 ;
V_143 -> V_148 = V_21 ;
V_143 -> V_149 = sizeof( struct V_150 ) ;
V_143 -> V_151 = & V_152 ;
V_143 -> V_153 = & V_154 ;
V_4 [ V_5 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_5 ] . V_55 = 640 ;
V_4 [ V_5 ] . V_56 = 480 ;
V_4 [ V_5 ] . V_124 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_93 = V_127 ;
V_130 = F_66 ( V_143 ) ;
if ( V_130 )
return V_130 ;
V_144 -> type = V_6 ;
V_144 -> V_145 = V_146 | V_147 ;
V_144 -> V_148 = V_21 ;
V_144 -> V_149 = sizeof( struct V_150 ) ;
V_144 -> V_151 = & V_152 ;
V_144 -> V_153 = & V_154 ;
V_4 [ V_7 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_7 ] . V_55 = 640 ;
V_4 [ V_7 ] . V_56 = 480 ;
V_4 [ V_7 ] . V_124 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_93 = V_94 ;
return F_66 ( V_144 ) ;
}
static int F_67 ( struct V_98 * V_98 )
{
struct V_22 * V_23 = F_68 ( V_98 ) ;
struct V_20 * V_21 = NULL ;
V_21 = F_69 ( sizeof *V_21 , V_155 ) ;
if ( ! V_21 )
return - V_156 ;
V_98 -> V_157 = V_21 ;
V_21 -> V_24 = V_23 ;
V_21 -> V_25 = F_70 ( V_23 -> V_28 , V_21 , & F_65 ) ;
if ( F_71 ( V_21 -> V_25 ) ) {
int V_130 = F_72 ( V_21 -> V_25 ) ;
F_73 ( V_21 ) ;
return V_130 ;
}
V_21 -> V_59 = F_69 ( sizeof( struct V_46 ) +
sizeof( struct V_158 ) , V_155 ) ;
if ( ! V_21 -> V_59 ) {
F_73 ( V_21 ) ;
return - V_156 ;
}
V_21 -> V_125 = V_126 ;
F_8 ( V_23 , L_22 , V_21 , V_21 -> V_25 ) ;
return 0 ;
}
static int F_74 ( struct V_98 * V_98 )
{
struct V_22 * V_23 = F_68 ( V_98 ) ;
struct V_20 * V_21 = V_98 -> V_157 ;
F_8 ( V_23 , L_23 , V_21 ) ;
F_75 ( V_21 -> V_25 ) ;
F_73 ( V_21 -> V_59 ) ;
F_73 ( V_21 ) ;
return 0 ;
}
static unsigned int F_76 ( struct V_98 * V_98 ,
struct V_159 * V_160 )
{
struct V_20 * V_21 = V_98 -> V_157 ;
int V_130 ;
F_11 ( V_21 ) ;
V_130 = F_77 ( V_98 , V_21 -> V_25 , V_160 ) ;
F_13 ( V_21 ) ;
return V_130 ;
}
static int F_78 ( struct V_98 * V_98 , struct V_161 * V_162 )
{
struct V_20 * V_21 = V_98 -> V_157 ;
return F_79 ( V_98 , V_21 -> V_25 , V_162 ) ;
}
static int F_80 ( struct V_163 * V_164 )
{
struct V_22 * V_23 ;
struct V_165 * V_166 ;
T_3 V_167 ;
int V_130 = 0 ;
V_23 = F_69 ( sizeof *V_23 , V_155 ) ;
if ( ! V_23 )
return - V_156 ;
F_81 ( & V_23 -> V_168 ) ;
F_82 ( V_167 ) ;
F_83 ( V_169 , V_167 ) ;
V_23 -> V_41 = F_84 ( V_167 , NULL , V_23 ) ;
if ( ! V_23 -> V_41 )
goto V_170;
if ( ! F_85 ( V_169 , V_23 -> V_41 -> V_45 -> V_171 ) ) {
F_24 ( & V_23 -> V_57 , L_24 ) ;
goto V_172;
}
V_130 = F_86 ( & V_164 -> V_24 , & V_23 -> V_57 ) ;
if ( V_130 )
goto V_172;
F_16 ( & V_23 -> V_26 , 0 ) ;
F_87 ( & V_23 -> V_29 ) ;
V_166 = F_88 () ;
if ( ! V_166 ) {
F_24 ( & V_23 -> V_57 , L_25 ) ;
V_130 = - V_156 ;
goto V_173;
}
* V_166 = V_174 ;
V_166 -> V_175 = & V_23 -> V_29 ;
V_130 = F_89 ( V_166 , V_176 , 0 ) ;
if ( V_130 ) {
F_24 ( & V_23 -> V_57 , L_26 ) ;
goto V_177;
}
F_90 ( V_166 , V_23 ) ;
snprintf ( V_166 -> V_117 , sizeof( V_166 -> V_117 ) , L_27 , V_174 . V_117 ) ;
V_23 -> V_166 = V_166 ;
F_91 ( & V_23 -> V_57 , V_178
L_28 , V_166 -> V_114 ) ;
F_92 ( V_164 , V_23 ) ;
V_23 -> V_141 = F_93 ( & V_164 -> V_24 ) ;
if ( F_71 ( V_23 -> V_141 ) ) {
F_24 ( & V_23 -> V_57 , L_29 ) ;
V_130 = F_72 ( V_23 -> V_141 ) ;
goto V_179;
}
V_23 -> V_28 = F_94 ( & V_180 ) ;
if ( F_71 ( V_23 -> V_28 ) ) {
F_24 ( & V_23 -> V_57 , L_30 ) ;
V_130 = F_72 ( V_23 -> V_28 ) ;
goto V_181;
}
return 0 ;
F_95 ( V_23 -> V_28 ) ;
V_181:
F_96 ( V_23 -> V_166 ) ;
V_179:
F_97 ( V_23 -> V_141 ) ;
V_177:
F_98 ( V_166 ) ;
V_173:
F_99 ( & V_23 -> V_57 ) ;
V_172:
F_100 ( V_23 -> V_41 ) ;
V_170:
F_73 ( V_23 ) ;
return V_130 ;
}
static int F_101 ( struct V_163 * V_164 )
{
struct V_22 * V_23 =
(struct V_22 * ) F_102 ( V_164 ) ;
F_91 ( & V_23 -> V_57 , L_31 V_178 ) ;
F_95 ( V_23 -> V_28 ) ;
F_96 ( V_23 -> V_166 ) ;
F_99 ( & V_23 -> V_57 ) ;
F_97 ( V_23 -> V_141 ) ;
F_100 ( V_23 -> V_41 ) ;
F_73 ( V_23 ) ;
return 0 ;
}
