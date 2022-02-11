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
V_33 -> V_35 . V_36 = V_34 -> V_35 . V_36 ;
V_33 -> V_35 . V_37 = V_34 -> V_35 . V_37 ;
F_19 ( V_33 , V_38 ) ;
F_19 ( V_34 , V_38 ) ;
F_10 ( V_23 -> V_28 , V_31 -> V_25 ) ;
F_8 ( V_23 , L_4 ) ;
}
static void F_20 ( struct V_20 * V_21 , int V_39 ,
int V_40 )
{
struct V_1 * V_41 ;
struct V_32 * V_42 , * V_43 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_44 * V_45 = V_23 -> V_44 ;
struct V_46 * V_47 = V_45 -> V_48 ;
struct V_49 * V_50 ;
unsigned int V_51 , V_52 ;
unsigned int V_53 ;
T_1 V_54 , V_55 ;
enum V_56 V_57 ;
V_42 = F_21 ( V_21 -> V_25 ) ;
V_43 = F_22 ( V_21 -> V_25 ) ;
V_41 = F_1 ( V_3 ) ;
V_51 = V_41 -> V_58 ;
V_52 = V_41 -> V_59 ;
V_53 = V_51 * V_52 ;
V_54 = ( T_1 ) F_23 ( V_42 , 0 ) ;
V_55 = ( T_1 ) F_23 ( V_43 , 0 ) ;
if ( ! V_54 || ! V_55 ) {
F_24 ( & V_23 -> V_60 ,
L_5 ) ;
return;
}
switch ( V_39 ) {
case V_61 :
V_21 -> V_62 -> V_63 = V_52 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 ;
V_21 -> V_62 -> V_67 = V_54 ;
V_21 -> V_62 -> V_68 = V_55 ;
break;
case V_69 :
V_21 -> V_62 -> V_63 = V_52 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 ;
V_21 -> V_62 -> V_67 = V_54 + V_53 / 2 ;
V_21 -> V_62 -> V_68 = V_55 + V_51 ;
break;
case V_70 :
V_21 -> V_62 -> V_63 = V_52 / 4 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 / 2 ;
V_21 -> V_62 -> V_67 = V_54 + V_53 ;
V_21 -> V_62 -> V_68 = V_55 + V_53 ;
break;
case V_71 :
V_21 -> V_62 -> V_63 = V_52 / 4 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 / 2 ;
V_21 -> V_62 -> V_67 = V_54 + ( 9 * V_53 ) / 8 ;
V_21 -> V_62 -> V_68 = V_55 + V_53 + V_51 / 2 ;
break;
case V_72 :
V_21 -> V_62 -> V_63 = V_52 / 4 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 / 2 ;
V_21 -> V_62 -> V_67 = V_54 + ( 5 * V_53 ) / 4 ;
V_21 -> V_62 -> V_68 = V_55 + ( 5 * V_53 ) / 4 ;
break;
case V_73 :
V_21 -> V_62 -> V_63 = V_52 / 4 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 / 2 ;
V_21 -> V_62 -> V_67 = V_54 + ( 11 * V_53 ) / 8 ;
V_21 -> V_62 -> V_68 = V_55 + ( 5 * V_53 ) / 4 + V_51 / 2 ;
break;
case V_74 :
V_21 -> V_62 -> V_63 = V_52 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 ;
V_21 -> V_62 -> V_67 = V_54 ;
V_21 -> V_62 -> V_68 = V_55 + V_51 ;
break;
case V_75 :
V_21 -> V_62 -> V_63 = V_52 / 4 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 / 2 ;
V_21 -> V_62 -> V_67 = V_54 + V_53 ;
V_21 -> V_62 -> V_68 = V_55 + V_53 + V_51 / 2 ;
break;
case V_76 :
V_21 -> V_62 -> V_63 = V_52 / 4 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 / 2 ;
V_21 -> V_62 -> V_67 = V_54 + ( 5 * V_53 ) / 4 ;
V_21 -> V_62 -> V_68 = V_55 + ( 5 * V_53 ) / 4 + V_51 / 2 ;
break;
case V_77 :
V_21 -> V_62 -> V_63 = V_52 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 * 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 * 2 ;
V_21 -> V_62 -> V_67 = V_54 ;
V_21 -> V_62 -> V_68 = V_55 ;
break;
case V_78 :
V_21 -> V_62 -> V_63 = V_52 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 * 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 * 2 ;
V_21 -> V_62 -> V_67 = V_54 + V_53 ;
V_21 -> V_62 -> V_68 = V_55 + V_51 * 2 ;
break;
case V_79 :
default:
V_21 -> V_62 -> V_63 = V_52 / 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_65 = V_51 * 2 ;
V_21 -> V_62 -> V_64 [ 0 ] . V_66 = V_51 * 2 ;
V_21 -> V_62 -> V_67 = V_54 ;
V_21 -> V_62 -> V_68 = V_55 + V_51 * 2 ;
break;
}
V_21 -> V_62 -> V_80 = 1 ;
V_21 -> V_62 -> V_81 = V_82 ;
V_21 -> V_62 -> V_83 = false ;
V_21 -> V_62 -> V_84 = true ;
V_57 = V_85 | V_86 |
V_87 | V_88 ;
V_50 = V_47 -> V_89 ( V_45 , V_21 -> V_62 , V_57 ) ;
if ( V_50 == NULL ) {
F_25 ( & V_23 -> V_60 , L_6 ) ;
return;
}
if ( V_40 ) {
V_50 -> V_90 = F_15 ;
V_50 -> V_91 = V_21 ;
}
V_21 -> V_92 = F_26 ( V_50 ) ;
if ( F_27 ( V_21 -> V_92 ) ) {
F_25 ( & V_23 -> V_60 ,
L_7 ,
V_21 -> V_92 , ( unsigned ) V_54 , ( unsigned ) V_55 ,
V_53 * 3 / 2 ) ;
return;
}
F_28 ( V_45 ) ;
}
static void F_29 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_93 ;
F_16 ( & V_21 -> V_24 -> V_26 , 1 ) ;
F_8 ( V_21 -> V_24 , L_8 , V_94 ) ;
V_93 = F_1 ( V_6 ) ;
switch ( V_93 -> V_11 -> V_16 ) {
case V_95 :
switch ( V_93 -> V_96 ) {
case V_97 :
case V_98 :
F_8 ( V_21 -> V_24 , L_9 ,
V_94 ) ;
F_20 ( V_21 , V_61 , 0 ) ;
F_20 ( V_21 , V_69 , 0 ) ;
F_20 ( V_21 , V_70 , 0 ) ;
F_20 ( V_21 , V_71 , 0 ) ;
F_20 ( V_21 , V_72 , 0 ) ;
F_20 ( V_21 , V_73 , 1 ) ;
break;
case V_99 :
default:
F_8 ( V_21 -> V_24 , L_10 ,
V_94 ) ;
F_20 ( V_21 , V_61 , 0 ) ;
F_20 ( V_21 , V_74 , 0 ) ;
F_20 ( V_21 , V_70 , 0 ) ;
F_20 ( V_21 , V_75 , 0 ) ;
F_20 ( V_21 , V_72 , 0 ) ;
F_20 ( V_21 , V_76 , 1 ) ;
break;
}
break;
case V_100 :
default:
switch ( V_93 -> V_96 ) {
case V_97 :
case V_98 :
F_8 ( V_21 -> V_24 , L_11 ,
V_94 ) ;
F_20 ( V_21 , V_77 , 0 ) ;
F_20 ( V_21 , V_78 , 1 ) ;
break;
case V_99 :
default:
F_8 ( V_21 -> V_24 , L_12 ,
V_94 ) ;
F_20 ( V_21 , V_77 , 0 ) ;
F_20 ( V_21 , V_79 , 1 ) ;
break;
}
break;
}
F_8 ( V_21 -> V_24 , L_13 , V_94 ) ;
}
static int F_30 ( struct V_101 * V_101 , void * V_19 ,
struct V_102 * V_103 )
{
F_31 ( V_103 -> V_104 , V_105 , sizeof( V_103 -> V_104 ) ) ;
F_31 ( V_103 -> V_106 , V_105 , sizeof( V_103 -> V_106 ) ) ;
F_31 ( V_103 -> V_107 , V_105 , sizeof( V_103 -> V_106 ) ) ;
V_103 -> V_108 = V_109 | V_110 |
V_111 | V_112 ;
V_103 -> V_113 = V_103 -> V_108 | V_114 ;
return 0 ;
}
static int F_32 ( struct V_115 * V_10 , T_2 type )
{
int V_116 , V_117 ;
struct V_8 * V_11 ;
V_117 = 0 ;
for ( V_116 = 0 ; V_116 < V_13 ; ++ V_116 ) {
if ( V_14 [ V_116 ] . V_15 & type ) {
if ( V_117 == V_10 -> V_118 )
break;
++ V_117 ;
}
}
if ( V_116 < V_13 ) {
V_11 = & V_14 [ V_116 ] ;
F_31 ( V_10 -> V_119 , V_11 -> V_120 , sizeof( V_10 -> V_119 ) ) ;
V_10 -> V_18 = V_11 -> V_16 ;
return 0 ;
}
return - V_121 ;
}
static int F_33 ( struct V_101 * V_101 , void * V_19 ,
struct V_115 * V_10 )
{
return F_32 ( V_10 , V_122 ) ;
}
static int F_34 ( struct V_101 * V_101 , void * V_19 ,
struct V_115 * V_10 )
{
return F_32 ( V_10 , V_123 ) ;
}
static int F_35 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_124 * V_125 ;
struct V_1 * V_4 ;
V_125 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_125 )
return - V_121 ;
V_4 = F_1 ( V_10 -> type ) ;
V_10 -> V_11 . V_17 . V_58 = V_4 -> V_58 ;
V_10 -> V_11 . V_17 . V_59 = V_4 -> V_59 ;
V_10 -> V_11 . V_17 . V_96 = V_4 -> V_96 ;
V_10 -> V_11 . V_17 . V_18 = V_4 -> V_11 -> V_16 ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_95 :
V_10 -> V_11 . V_17 . V_126 = V_4 -> V_58 * 3 / 2 ;
break;
case V_100 :
default:
V_10 -> V_11 . V_17 . V_126 = V_4 -> V_58 * 2 ;
}
V_10 -> V_11 . V_17 . V_127 = V_4 -> V_127 ;
V_10 -> V_11 . V_17 . V_128 = V_21 -> V_128 ;
return 0 ;
}
static int F_37 ( struct V_101 * V_101 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_38 ( struct V_101 * V_101 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_8 * V_11 )
{
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_95 :
V_10 -> V_11 . V_17 . V_126 = V_10 -> V_11 . V_17 . V_58 * 3 / 2 ;
break;
case V_100 :
default:
V_10 -> V_11 . V_17 . V_126 = V_10 -> V_11 . V_17 . V_58 * 2 ;
}
V_10 -> V_11 . V_17 . V_127 = V_10 -> V_11 . V_17 . V_59 * V_10 -> V_11 . V_17 . V_126 ;
return 0 ;
}
static int F_40 ( struct V_101 * V_101 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
struct V_20 * V_21 = V_19 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_122 ) )
V_10 -> V_11 . V_17 . V_18 = V_95 ;
V_10 -> V_11 . V_17 . V_128 = V_21 -> V_128 ;
if ( V_10 -> V_11 . V_17 . V_96 != V_97 &&
V_10 -> V_11 . V_17 . V_96 != V_98 &&
V_10 -> V_11 . V_17 . V_96 != V_99 )
V_10 -> V_11 . V_17 . V_96 = V_97 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_41 ( struct V_101 * V_101 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_123 ) )
V_10 -> V_11 . V_17 . V_18 = V_95 ;
if ( ! V_10 -> V_11 . V_17 . V_128 )
V_10 -> V_11 . V_17 . V_128 = V_129 ;
if ( V_10 -> V_11 . V_17 . V_96 != V_130 &&
V_10 -> V_11 . V_17 . V_96 != V_131 )
V_10 -> V_11 . V_17 . V_96 = V_130 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_42 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_1 * V_4 ;
struct V_124 * V_125 ;
V_125 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_125 )
return - V_121 ;
V_4 = F_1 ( V_10 -> type ) ;
if ( ! V_4 )
return - V_121 ;
if ( F_43 ( V_125 ) ) {
F_24 ( & V_21 -> V_24 -> V_60 , L_14 , V_94 ) ;
return - V_132 ;
}
V_4 -> V_11 = F_3 ( V_10 ) ;
if ( ! V_4 -> V_11 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_15 ,
V_10 -> type , V_10 -> V_11 . V_17 . V_58 , V_10 -> V_11 . V_17 . V_59 ,
V_10 -> V_11 . V_17 . V_18 , V_10 -> V_11 . V_17 . V_96 ) ;
return - V_121 ;
}
V_4 -> V_58 = V_10 -> V_11 . V_17 . V_58 ;
V_4 -> V_59 = V_10 -> V_11 . V_17 . V_59 ;
V_4 -> V_96 = V_10 -> V_11 . V_17 . V_96 ;
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_95 :
V_10 -> V_11 . V_17 . V_126 = V_10 -> V_11 . V_17 . V_58 * 3 / 2 ;
V_4 -> V_127 = ( V_4 -> V_58 * V_4 -> V_59 * 3 ) / 2 ;
break;
case V_100 :
default:
V_10 -> V_11 . V_17 . V_126 = V_10 -> V_11 . V_17 . V_58 * 2 ;
V_4 -> V_127 = V_4 -> V_58 * V_4 -> V_59 * 2 ;
}
F_8 ( V_21 -> V_24 ,
L_16 ,
V_10 -> type , V_4 -> V_58 , V_4 -> V_59 , V_4 -> V_11 -> V_16 ,
V_4 -> V_96 ) ;
return 0 ;
}
static int F_44 ( struct V_101 * V_101 , void * V_19 ,
struct V_9 * V_10 )
{
int V_133 ;
V_133 = F_40 ( V_101 , V_19 , V_10 ) ;
if ( V_133 )
return V_133 ;
return F_42 ( V_19 , V_10 ) ;
}
static int F_45 ( struct V_101 * V_101 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 = V_19 ;
int V_133 ;
V_133 = F_41 ( V_101 , V_19 , V_10 ) ;
if ( V_133 )
return V_133 ;
V_133 = F_42 ( V_19 , V_10 ) ;
if ( ! V_133 )
V_21 -> V_128 = V_10 -> V_11 . V_17 . V_128 ;
return V_133 ;
}
static int F_46 ( struct V_101 * V_101 , void * V_19 ,
struct V_134 * V_135 )
{
struct V_20 * V_21 = V_19 ;
return F_47 ( V_101 , V_21 -> V_25 , V_135 ) ;
}
static int F_48 ( struct V_101 * V_101 , void * V_19 ,
struct V_136 * V_137 )
{
struct V_20 * V_21 = V_19 ;
return F_49 ( V_101 , V_21 -> V_25 , V_137 ) ;
}
static int F_50 ( struct V_101 * V_101 , void * V_19 , struct V_136 * V_137 )
{
struct V_20 * V_21 = V_19 ;
return F_51 ( V_101 , V_21 -> V_25 , V_137 ) ;
}
static int F_52 ( struct V_101 * V_101 , void * V_19 , struct V_136 * V_137 )
{
struct V_20 * V_21 = V_19 ;
return F_53 ( V_101 , V_21 -> V_25 , V_137 ) ;
}
static int F_54 ( struct V_101 * V_101 , void * V_19 ,
enum V_2 type )
{
struct V_1 * V_41 , * V_138 ;
struct V_20 * V_21 = V_19 ;
V_41 = F_1 ( V_3 ) ;
V_138 = F_1 ( V_6 ) ;
if ( V_41 -> V_11 -> V_16 != V_138 -> V_11 -> V_16 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_17 ) ;
return - V_121 ;
}
switch ( V_41 -> V_96 ) {
case V_131 :
if ( V_138 -> V_96 != V_99 &&
V_138 -> V_96 != V_98 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_18 ,
V_41 -> V_96 , V_138 -> V_96 ) ;
return - V_121 ;
}
break;
case V_130 :
if ( V_138 -> V_96 != V_99 &&
V_138 -> V_96 != V_97 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_18 ,
V_41 -> V_96 , V_138 -> V_96 ) ;
return - V_121 ;
}
break;
default:
return - V_121 ;
}
return F_55 ( V_101 , V_21 -> V_25 , type ) ;
}
static int F_56 ( struct V_101 * V_101 , void * V_19 ,
enum V_2 type )
{
struct V_20 * V_21 = V_19 ;
return F_57 ( V_101 , V_21 -> V_25 , type ) ;
}
static int F_58 ( struct V_124 * V_125 ,
const struct V_9 * V_11 ,
unsigned int * V_139 , unsigned int * V_140 ,
unsigned int V_141 [] , void * V_142 [] )
{
struct V_20 * V_21 = F_59 ( V_125 ) ;
struct V_1 * V_4 ;
unsigned int V_65 , V_143 = * V_139 ;
V_4 = F_1 ( V_125 -> type ) ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_95 :
V_65 = V_4 -> V_58 * V_4 -> V_59 * 3 / 2 ;
break;
case V_100 :
default:
V_65 = V_4 -> V_58 * V_4 -> V_59 * 2 ;
}
* V_140 = 1 ;
* V_139 = V_143 ;
V_141 [ 0 ] = V_65 ;
V_142 [ 0 ] = V_21 -> V_24 -> V_144 ;
F_8 ( V_21 -> V_24 , L_19 , V_143 , V_65 ) ;
return 0 ;
}
static int F_60 ( struct V_32 * V_145 )
{
struct V_20 * V_21 = F_59 ( V_145 -> V_124 ) ;
struct V_1 * V_4 ;
F_8 ( V_21 -> V_24 , L_20 , V_145 -> V_124 -> type ) ;
V_4 = F_1 ( V_145 -> V_124 -> type ) ;
if ( F_61 ( V_145 , 0 ) < V_4 -> V_127 ) {
F_8 ( V_21 -> V_24 , L_21 ,
V_94 , F_61 ( V_145 , 0 ) , ( long ) V_4 -> V_127 ) ;
return - V_121 ;
}
F_62 ( V_145 , 0 , V_4 -> V_127 ) ;
return 0 ;
}
static void F_63 ( struct V_32 * V_145 )
{
struct V_20 * V_21 = F_59 ( V_145 -> V_124 ) ;
F_64 ( V_21 -> V_25 , V_145 ) ;
}
static int F_65 ( void * V_19 , struct V_124 * V_146 ,
struct V_124 * V_147 )
{
struct V_20 * V_21 = V_19 ;
int V_133 ;
V_146 -> type = V_3 ;
V_146 -> V_148 = V_149 | V_150 ;
V_146 -> V_151 = V_21 ;
V_146 -> V_152 = sizeof( struct V_153 ) ;
V_146 -> V_154 = & V_155 ;
V_146 -> V_156 = & V_157 ;
V_146 -> V_158 = V_159 ;
V_4 [ V_5 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_5 ] . V_58 = 640 ;
V_4 [ V_5 ] . V_59 = 480 ;
V_4 [ V_5 ] . V_127 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_96 = V_130 ;
V_133 = F_66 ( V_146 ) ;
if ( V_133 )
return V_133 ;
V_147 -> type = V_6 ;
V_147 -> V_148 = V_149 | V_150 ;
V_147 -> V_151 = V_21 ;
V_147 -> V_152 = sizeof( struct V_153 ) ;
V_147 -> V_154 = & V_155 ;
V_147 -> V_156 = & V_157 ;
V_147 -> V_158 = V_159 ;
V_4 [ V_7 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_7 ] . V_58 = 640 ;
V_4 [ V_7 ] . V_59 = 480 ;
V_4 [ V_7 ] . V_127 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_96 = V_97 ;
return F_66 ( V_147 ) ;
}
static int F_67 ( struct V_101 * V_101 )
{
struct V_22 * V_23 = F_68 ( V_101 ) ;
struct V_20 * V_21 = NULL ;
V_21 = F_69 ( sizeof *V_21 , V_160 ) ;
if ( ! V_21 )
return - V_161 ;
V_101 -> V_162 = V_21 ;
V_21 -> V_24 = V_23 ;
V_21 -> V_25 = F_70 ( V_23 -> V_28 , V_21 , & F_65 ) ;
if ( F_71 ( V_21 -> V_25 ) ) {
int V_133 = F_72 ( V_21 -> V_25 ) ;
F_73 ( V_21 ) ;
return V_133 ;
}
V_21 -> V_62 = F_69 ( sizeof( struct V_49 ) +
sizeof( struct V_163 ) , V_160 ) ;
if ( ! V_21 -> V_62 ) {
F_73 ( V_21 ) ;
return - V_161 ;
}
V_21 -> V_128 = V_129 ;
F_8 ( V_23 , L_22 , V_21 , V_21 -> V_25 ) ;
return 0 ;
}
static int F_74 ( struct V_101 * V_101 )
{
struct V_22 * V_23 = F_68 ( V_101 ) ;
struct V_20 * V_21 = V_101 -> V_162 ;
F_8 ( V_23 , L_23 , V_21 ) ;
F_75 ( V_21 -> V_25 ) ;
F_73 ( V_21 -> V_62 ) ;
F_73 ( V_21 ) ;
return 0 ;
}
static unsigned int F_76 ( struct V_101 * V_101 ,
struct V_164 * V_165 )
{
struct V_20 * V_21 = V_101 -> V_162 ;
int V_133 ;
F_11 ( V_21 ) ;
V_133 = F_77 ( V_101 , V_21 -> V_25 , V_165 ) ;
F_13 ( V_21 ) ;
return V_133 ;
}
static int F_78 ( struct V_101 * V_101 , struct V_166 * V_167 )
{
struct V_20 * V_21 = V_101 -> V_162 ;
return F_79 ( V_101 , V_21 -> V_25 , V_167 ) ;
}
static int F_80 ( struct V_168 * V_169 )
{
struct V_22 * V_23 ;
struct V_170 * V_171 ;
T_3 V_172 ;
int V_133 = 0 ;
V_23 = F_69 ( sizeof *V_23 , V_160 ) ;
if ( ! V_23 )
return - V_161 ;
F_81 ( & V_23 -> V_173 ) ;
F_82 ( V_172 ) ;
F_83 ( V_174 , V_172 ) ;
V_23 -> V_44 = F_84 ( V_172 , NULL , V_23 ) ;
if ( ! V_23 -> V_44 )
goto V_175;
if ( ! F_85 ( V_174 , V_23 -> V_44 -> V_48 -> V_176 ) ) {
F_24 ( & V_23 -> V_60 , L_24 ) ;
goto V_177;
}
V_133 = F_86 ( & V_169 -> V_24 , & V_23 -> V_60 ) ;
if ( V_133 )
goto V_177;
F_16 ( & V_23 -> V_26 , 0 ) ;
F_87 ( & V_23 -> V_29 ) ;
V_171 = F_88 () ;
if ( ! V_171 ) {
F_24 ( & V_23 -> V_60 , L_25 ) ;
V_133 = - V_161 ;
goto V_178;
}
* V_171 = V_179 ;
V_171 -> V_180 = & V_23 -> V_29 ;
V_133 = F_89 ( V_171 , V_181 , 0 ) ;
if ( V_133 ) {
F_24 ( & V_23 -> V_60 , L_26 ) ;
goto V_182;
}
F_90 ( V_171 , V_23 ) ;
snprintf ( V_171 -> V_120 , sizeof( V_171 -> V_120 ) , L_27 , V_179 . V_120 ) ;
V_23 -> V_171 = V_171 ;
F_91 ( & V_23 -> V_60 , V_183
L_28 , V_171 -> V_117 ) ;
F_92 ( V_169 , V_23 ) ;
V_23 -> V_144 = F_93 ( & V_169 -> V_24 ) ;
if ( F_71 ( V_23 -> V_144 ) ) {
F_24 ( & V_23 -> V_60 , L_29 ) ;
V_133 = F_72 ( V_23 -> V_144 ) ;
goto V_184;
}
V_23 -> V_28 = F_94 ( & V_185 ) ;
if ( F_71 ( V_23 -> V_28 ) ) {
F_24 ( & V_23 -> V_60 , L_30 ) ;
V_133 = F_72 ( V_23 -> V_28 ) ;
goto V_186;
}
return 0 ;
F_95 ( V_23 -> V_28 ) ;
V_186:
F_96 ( V_23 -> V_171 ) ;
V_184:
F_97 ( V_23 -> V_144 ) ;
V_182:
F_98 ( V_171 ) ;
V_178:
F_99 ( & V_23 -> V_60 ) ;
V_177:
F_100 ( V_23 -> V_44 ) ;
V_175:
F_73 ( V_23 ) ;
return V_133 ;
}
static int F_101 ( struct V_168 * V_169 )
{
struct V_22 * V_23 =
(struct V_22 * ) F_102 ( V_169 ) ;
F_91 ( & V_23 -> V_60 , L_31 V_183 ) ;
F_95 ( V_23 -> V_28 ) ;
F_96 ( V_23 -> V_171 ) ;
F_99 ( & V_23 -> V_60 ) ;
F_97 ( V_23 -> V_144 ) ;
F_100 ( V_23 -> V_44 ) ;
F_73 ( V_23 ) ;
return 0 ;
}
