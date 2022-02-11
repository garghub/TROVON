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
V_57 = V_85 | V_86 ;
V_50 = V_47 -> V_87 ( V_45 , V_21 -> V_62 , V_57 ) ;
if ( V_50 == NULL ) {
F_25 ( & V_23 -> V_60 , L_6 ) ;
return;
}
if ( V_40 ) {
V_50 -> V_88 = F_15 ;
V_50 -> V_89 = V_21 ;
}
V_21 -> V_90 = F_26 ( V_50 ) ;
if ( F_27 ( V_21 -> V_90 ) ) {
F_25 ( & V_23 -> V_60 ,
L_7 ,
V_21 -> V_90 , ( unsigned ) V_54 , ( unsigned ) V_55 ,
V_53 * 3 / 2 ) ;
return;
}
F_28 ( V_45 ) ;
}
static void F_29 ( void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_1 * V_91 ;
F_16 ( & V_21 -> V_24 -> V_26 , 1 ) ;
F_8 ( V_21 -> V_24 , L_8 , V_92 ) ;
V_91 = F_1 ( V_6 ) ;
switch ( V_91 -> V_11 -> V_16 ) {
case V_93 :
switch ( V_91 -> V_94 ) {
case V_95 :
case V_96 :
F_8 ( V_21 -> V_24 , L_9 ,
V_92 ) ;
F_20 ( V_21 , V_61 , 0 ) ;
F_20 ( V_21 , V_69 , 0 ) ;
F_20 ( V_21 , V_70 , 0 ) ;
F_20 ( V_21 , V_71 , 0 ) ;
F_20 ( V_21 , V_72 , 0 ) ;
F_20 ( V_21 , V_73 , 1 ) ;
break;
case V_97 :
default:
F_8 ( V_21 -> V_24 , L_10 ,
V_92 ) ;
F_20 ( V_21 , V_61 , 0 ) ;
F_20 ( V_21 , V_74 , 0 ) ;
F_20 ( V_21 , V_70 , 0 ) ;
F_20 ( V_21 , V_75 , 0 ) ;
F_20 ( V_21 , V_72 , 0 ) ;
F_20 ( V_21 , V_76 , 1 ) ;
break;
}
break;
case V_98 :
default:
switch ( V_91 -> V_94 ) {
case V_95 :
case V_96 :
F_8 ( V_21 -> V_24 , L_11 ,
V_92 ) ;
F_20 ( V_21 , V_77 , 0 ) ;
F_20 ( V_21 , V_78 , 1 ) ;
break;
case V_97 :
default:
F_8 ( V_21 -> V_24 , L_12 ,
V_92 ) ;
F_20 ( V_21 , V_77 , 0 ) ;
F_20 ( V_21 , V_79 , 1 ) ;
break;
}
break;
}
F_8 ( V_21 -> V_24 , L_13 , V_92 ) ;
}
static int F_30 ( struct V_99 * V_99 , void * V_19 ,
struct V_100 * V_101 )
{
F_31 ( V_101 -> V_102 , V_103 , sizeof( V_101 -> V_102 ) ) ;
F_31 ( V_101 -> V_104 , V_103 , sizeof( V_101 -> V_104 ) ) ;
F_31 ( V_101 -> V_105 , V_103 , sizeof( V_101 -> V_104 ) ) ;
V_101 -> V_106 = V_107 | V_108 |
V_109 | V_110 ;
V_101 -> V_111 = V_101 -> V_106 | V_112 ;
return 0 ;
}
static int F_32 ( struct V_113 * V_10 , T_2 type )
{
int V_114 , V_115 ;
struct V_8 * V_11 ;
V_115 = 0 ;
for ( V_114 = 0 ; V_114 < V_13 ; ++ V_114 ) {
if ( V_14 [ V_114 ] . V_15 & type ) {
if ( V_115 == V_10 -> V_116 )
break;
++ V_115 ;
}
}
if ( V_114 < V_13 ) {
V_11 = & V_14 [ V_114 ] ;
F_31 ( V_10 -> V_117 , V_11 -> V_118 , sizeof( V_10 -> V_117 ) ) ;
V_10 -> V_18 = V_11 -> V_16 ;
return 0 ;
}
return - V_119 ;
}
static int F_33 ( struct V_99 * V_99 , void * V_19 ,
struct V_113 * V_10 )
{
return F_32 ( V_10 , V_120 ) ;
}
static int F_34 ( struct V_99 * V_99 , void * V_19 ,
struct V_113 * V_10 )
{
return F_32 ( V_10 , V_121 ) ;
}
static int F_35 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_122 * V_123 ;
struct V_1 * V_4 ;
V_123 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_123 )
return - V_119 ;
V_4 = F_1 ( V_10 -> type ) ;
V_10 -> V_11 . V_17 . V_58 = V_4 -> V_58 ;
V_10 -> V_11 . V_17 . V_59 = V_4 -> V_59 ;
V_10 -> V_11 . V_17 . V_94 = V_4 -> V_94 ;
V_10 -> V_11 . V_17 . V_18 = V_4 -> V_11 -> V_16 ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_93 :
V_10 -> V_11 . V_17 . V_124 = V_4 -> V_58 * 3 / 2 ;
break;
case V_98 :
default:
V_10 -> V_11 . V_17 . V_124 = V_4 -> V_58 * 2 ;
}
V_10 -> V_11 . V_17 . V_125 = V_4 -> V_125 ;
V_10 -> V_11 . V_17 . V_126 = V_21 -> V_126 ;
return 0 ;
}
static int F_37 ( struct V_99 * V_99 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_38 ( struct V_99 * V_99 , void * V_19 ,
struct V_9 * V_10 )
{
return F_35 ( V_19 , V_10 ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_8 * V_11 )
{
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_93 :
V_10 -> V_11 . V_17 . V_124 = V_10 -> V_11 . V_17 . V_58 * 3 / 2 ;
break;
case V_98 :
default:
V_10 -> V_11 . V_17 . V_124 = V_10 -> V_11 . V_17 . V_58 * 2 ;
}
V_10 -> V_11 . V_17 . V_125 = V_10 -> V_11 . V_17 . V_59 * V_10 -> V_11 . V_17 . V_124 ;
return 0 ;
}
static int F_40 ( struct V_99 * V_99 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
struct V_20 * V_21 = V_19 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_120 ) )
V_10 -> V_11 . V_17 . V_18 = V_93 ;
V_10 -> V_11 . V_17 . V_126 = V_21 -> V_126 ;
if ( V_10 -> V_11 . V_17 . V_94 != V_95 &&
V_10 -> V_11 . V_17 . V_94 != V_96 &&
V_10 -> V_11 . V_17 . V_94 != V_97 )
V_10 -> V_11 . V_17 . V_94 = V_95 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_41 ( struct V_99 * V_99 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( ! V_11 || ! ( V_11 -> V_15 & V_121 ) )
V_10 -> V_11 . V_17 . V_18 = V_93 ;
if ( ! V_10 -> V_11 . V_17 . V_126 )
V_10 -> V_11 . V_17 . V_126 = V_127 ;
if ( V_10 -> V_11 . V_17 . V_94 != V_128 &&
V_10 -> V_11 . V_17 . V_94 != V_129 )
V_10 -> V_11 . V_17 . V_94 = V_128 ;
return F_39 ( V_10 , V_11 ) ;
}
static int F_42 ( struct V_20 * V_21 , struct V_9 * V_10 )
{
struct V_1 * V_4 ;
struct V_122 * V_123 ;
V_123 = F_36 ( V_21 -> V_25 , V_10 -> type ) ;
if ( ! V_123 )
return - V_119 ;
V_4 = F_1 ( V_10 -> type ) ;
if ( ! V_4 )
return - V_119 ;
if ( F_43 ( V_123 ) ) {
F_24 ( & V_21 -> V_24 -> V_60 , L_14 , V_92 ) ;
return - V_130 ;
}
V_4 -> V_11 = F_3 ( V_10 ) ;
if ( ! V_4 -> V_11 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_15 ,
V_10 -> type , V_10 -> V_11 . V_17 . V_58 , V_10 -> V_11 . V_17 . V_59 ,
V_10 -> V_11 . V_17 . V_18 , V_10 -> V_11 . V_17 . V_94 ) ;
return - V_119 ;
}
V_4 -> V_58 = V_10 -> V_11 . V_17 . V_58 ;
V_4 -> V_59 = V_10 -> V_11 . V_17 . V_59 ;
V_4 -> V_94 = V_10 -> V_11 . V_17 . V_94 ;
switch ( V_10 -> V_11 . V_17 . V_18 ) {
case V_93 :
V_10 -> V_11 . V_17 . V_124 = V_10 -> V_11 . V_17 . V_58 * 3 / 2 ;
V_4 -> V_125 = ( V_4 -> V_58 * V_4 -> V_59 * 3 ) / 2 ;
break;
case V_98 :
default:
V_10 -> V_11 . V_17 . V_124 = V_10 -> V_11 . V_17 . V_58 * 2 ;
V_4 -> V_125 = V_4 -> V_58 * V_4 -> V_59 * 2 ;
}
F_8 ( V_21 -> V_24 ,
L_16 ,
V_10 -> type , V_4 -> V_58 , V_4 -> V_59 , V_4 -> V_11 -> V_16 ,
V_4 -> V_94 ) ;
return 0 ;
}
static int F_44 ( struct V_99 * V_99 , void * V_19 ,
struct V_9 * V_10 )
{
int V_131 ;
V_131 = F_40 ( V_99 , V_19 , V_10 ) ;
if ( V_131 )
return V_131 ;
return F_42 ( V_19 , V_10 ) ;
}
static int F_45 ( struct V_99 * V_99 , void * V_19 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 = V_19 ;
int V_131 ;
V_131 = F_41 ( V_99 , V_19 , V_10 ) ;
if ( V_131 )
return V_131 ;
V_131 = F_42 ( V_19 , V_10 ) ;
if ( ! V_131 )
V_21 -> V_126 = V_10 -> V_11 . V_17 . V_126 ;
return V_131 ;
}
static int F_46 ( struct V_99 * V_99 , void * V_19 ,
struct V_132 * V_133 )
{
struct V_20 * V_21 = V_19 ;
return F_47 ( V_99 , V_21 -> V_25 , V_133 ) ;
}
static int F_48 ( struct V_99 * V_99 , void * V_19 ,
struct V_134 * V_135 )
{
struct V_20 * V_21 = V_19 ;
return F_49 ( V_99 , V_21 -> V_25 , V_135 ) ;
}
static int F_50 ( struct V_99 * V_99 , void * V_19 , struct V_134 * V_135 )
{
struct V_20 * V_21 = V_19 ;
return F_51 ( V_99 , V_21 -> V_25 , V_135 ) ;
}
static int F_52 ( struct V_99 * V_99 , void * V_19 , struct V_134 * V_135 )
{
struct V_20 * V_21 = V_19 ;
return F_53 ( V_99 , V_21 -> V_25 , V_135 ) ;
}
static int F_54 ( struct V_99 * V_99 , void * V_19 ,
enum V_2 type )
{
struct V_1 * V_41 , * V_136 ;
struct V_20 * V_21 = V_19 ;
V_41 = F_1 ( V_3 ) ;
V_136 = F_1 ( V_6 ) ;
if ( V_41 -> V_11 -> V_16 != V_136 -> V_11 -> V_16 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_17 ) ;
return - V_119 ;
}
switch ( V_41 -> V_94 ) {
case V_129 :
if ( V_136 -> V_94 != V_97 &&
V_136 -> V_94 != V_96 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_18 ,
V_41 -> V_94 , V_136 -> V_94 ) ;
return - V_119 ;
}
break;
case V_128 :
if ( V_136 -> V_94 != V_97 &&
V_136 -> V_94 != V_95 ) {
F_24 ( & V_21 -> V_24 -> V_60 ,
L_18 ,
V_41 -> V_94 , V_136 -> V_94 ) ;
return - V_119 ;
}
break;
default:
return - V_119 ;
}
return F_55 ( V_99 , V_21 -> V_25 , type ) ;
}
static int F_56 ( struct V_99 * V_99 , void * V_19 ,
enum V_2 type )
{
struct V_20 * V_21 = V_19 ;
return F_57 ( V_99 , V_21 -> V_25 , type ) ;
}
static int F_58 ( struct V_122 * V_123 ,
const struct V_9 * V_11 ,
unsigned int * V_137 , unsigned int * V_138 ,
unsigned int V_139 [] , void * V_140 [] )
{
struct V_20 * V_21 = F_59 ( V_123 ) ;
struct V_1 * V_4 ;
unsigned int V_65 , V_141 = * V_137 ;
V_4 = F_1 ( V_123 -> type ) ;
switch ( V_4 -> V_11 -> V_16 ) {
case V_93 :
V_65 = V_4 -> V_58 * V_4 -> V_59 * 3 / 2 ;
break;
case V_98 :
default:
V_65 = V_4 -> V_58 * V_4 -> V_59 * 2 ;
}
* V_138 = 1 ;
* V_137 = V_141 ;
V_139 [ 0 ] = V_65 ;
V_140 [ 0 ] = V_21 -> V_24 -> V_142 ;
F_8 ( V_21 -> V_24 , L_19 , V_141 , V_65 ) ;
return 0 ;
}
static int F_60 ( struct V_32 * V_143 )
{
struct V_20 * V_21 = F_59 ( V_143 -> V_122 ) ;
struct V_1 * V_4 ;
F_8 ( V_21 -> V_24 , L_20 , V_143 -> V_122 -> type ) ;
V_4 = F_1 ( V_143 -> V_122 -> type ) ;
if ( F_61 ( V_143 , 0 ) < V_4 -> V_125 ) {
F_8 ( V_21 -> V_24 , L_21 ,
V_92 , F_61 ( V_143 , 0 ) , ( long ) V_4 -> V_125 ) ;
return - V_119 ;
}
F_62 ( V_143 , 0 , V_4 -> V_125 ) ;
return 0 ;
}
static void F_63 ( struct V_32 * V_143 )
{
struct V_20 * V_21 = F_59 ( V_143 -> V_122 ) ;
F_64 ( V_21 -> V_25 , V_143 ) ;
}
static int F_65 ( void * V_19 , struct V_122 * V_144 ,
struct V_122 * V_145 )
{
struct V_20 * V_21 = V_19 ;
int V_131 ;
V_144 -> type = V_3 ;
V_144 -> V_146 = V_147 | V_148 ;
V_144 -> V_149 = V_21 ;
V_144 -> V_150 = sizeof( struct V_151 ) ;
V_144 -> V_152 = & V_153 ;
V_144 -> V_154 = & V_155 ;
V_144 -> V_156 = V_157 ;
V_4 [ V_5 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_5 ] . V_58 = 640 ;
V_4 [ V_5 ] . V_59 = 480 ;
V_4 [ V_5 ] . V_125 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_94 = V_128 ;
V_131 = F_66 ( V_144 ) ;
if ( V_131 )
return V_131 ;
V_145 -> type = V_6 ;
V_145 -> V_146 = V_147 | V_148 ;
V_145 -> V_149 = V_21 ;
V_145 -> V_150 = sizeof( struct V_151 ) ;
V_145 -> V_152 = & V_153 ;
V_145 -> V_154 = & V_155 ;
V_145 -> V_156 = V_157 ;
V_4 [ V_7 ] . V_11 = & V_14 [ 0 ] ;
V_4 [ V_7 ] . V_58 = 640 ;
V_4 [ V_7 ] . V_59 = 480 ;
V_4 [ V_7 ] . V_125 = ( 640 * 480 * 3 ) / 2 ;
V_4 [ V_5 ] . V_94 = V_95 ;
return F_66 ( V_145 ) ;
}
static int F_67 ( struct V_99 * V_99 )
{
struct V_22 * V_23 = F_68 ( V_99 ) ;
struct V_20 * V_21 = NULL ;
V_21 = F_69 ( sizeof *V_21 , V_158 ) ;
if ( ! V_21 )
return - V_159 ;
V_99 -> V_160 = V_21 ;
V_21 -> V_24 = V_23 ;
V_21 -> V_25 = F_70 ( V_23 -> V_28 , V_21 , & F_65 ) ;
if ( F_71 ( V_21 -> V_25 ) ) {
int V_131 = F_72 ( V_21 -> V_25 ) ;
F_73 ( V_21 ) ;
return V_131 ;
}
V_21 -> V_62 = F_69 ( sizeof( struct V_161 ) +
sizeof( struct V_162 ) , V_158 ) ;
if ( ! V_21 -> V_62 ) {
F_73 ( V_21 ) ;
return - V_159 ;
}
V_21 -> V_126 = V_127 ;
F_8 ( V_23 , L_22 , V_21 , V_21 -> V_25 ) ;
return 0 ;
}
static int F_74 ( struct V_99 * V_99 )
{
struct V_22 * V_23 = F_68 ( V_99 ) ;
struct V_20 * V_21 = V_99 -> V_160 ;
F_8 ( V_23 , L_23 , V_21 ) ;
F_75 ( V_21 -> V_25 ) ;
F_73 ( V_21 -> V_62 ) ;
F_73 ( V_21 ) ;
return 0 ;
}
static unsigned int F_76 ( struct V_99 * V_99 ,
struct V_163 * V_164 )
{
struct V_20 * V_21 = V_99 -> V_160 ;
int V_131 ;
F_11 ( V_21 ) ;
V_131 = F_77 ( V_99 , V_21 -> V_25 , V_164 ) ;
F_13 ( V_21 ) ;
return V_131 ;
}
static int F_78 ( struct V_99 * V_99 , struct V_165 * V_166 )
{
struct V_20 * V_21 = V_99 -> V_160 ;
return F_79 ( V_99 , V_21 -> V_25 , V_166 ) ;
}
static int F_80 ( struct V_167 * V_168 )
{
struct V_22 * V_23 ;
struct V_169 * V_170 ;
T_3 V_171 ;
int V_131 = 0 ;
V_23 = F_69 ( sizeof *V_23 , V_158 ) ;
if ( ! V_23 )
return - V_159 ;
F_81 ( & V_23 -> V_172 ) ;
F_82 ( V_171 ) ;
F_83 ( V_173 , V_171 ) ;
V_23 -> V_44 = F_84 ( V_171 , NULL , V_23 ) ;
if ( ! V_23 -> V_44 )
goto V_174;
if ( ! F_85 ( V_173 , V_23 -> V_44 -> V_48 -> V_175 ) ) {
F_24 ( & V_23 -> V_60 , L_24 ) ;
goto V_176;
}
V_131 = F_86 ( & V_168 -> V_24 , & V_23 -> V_60 ) ;
if ( V_131 )
goto V_176;
F_16 ( & V_23 -> V_26 , 0 ) ;
F_87 ( & V_23 -> V_29 ) ;
V_170 = F_88 () ;
if ( ! V_170 ) {
F_24 ( & V_23 -> V_60 , L_25 ) ;
V_131 = - V_159 ;
goto V_177;
}
* V_170 = V_178 ;
V_170 -> V_179 = & V_23 -> V_29 ;
V_170 -> V_60 = & V_23 -> V_60 ;
V_131 = F_89 ( V_170 , V_180 , 0 ) ;
if ( V_131 ) {
F_24 ( & V_23 -> V_60 , L_26 ) ;
goto V_181;
}
F_90 ( V_170 , V_23 ) ;
snprintf ( V_170 -> V_118 , sizeof( V_170 -> V_118 ) , L_27 , V_178 . V_118 ) ;
V_23 -> V_170 = V_170 ;
F_91 ( & V_23 -> V_60 , V_182
L_28 , V_170 -> V_115 ) ;
F_92 ( V_168 , V_23 ) ;
V_23 -> V_142 = F_93 ( & V_168 -> V_24 ) ;
if ( F_71 ( V_23 -> V_142 ) ) {
F_24 ( & V_23 -> V_60 , L_29 ) ;
V_131 = F_72 ( V_23 -> V_142 ) ;
goto V_183;
}
V_23 -> V_28 = F_94 ( & V_184 ) ;
if ( F_71 ( V_23 -> V_28 ) ) {
F_24 ( & V_23 -> V_60 , L_30 ) ;
V_131 = F_72 ( V_23 -> V_28 ) ;
goto V_185;
}
return 0 ;
F_95 ( V_23 -> V_28 ) ;
V_185:
F_96 ( V_23 -> V_170 ) ;
V_183:
F_97 ( V_23 -> V_142 ) ;
V_181:
F_98 ( V_170 ) ;
V_177:
F_99 ( & V_23 -> V_60 ) ;
V_176:
F_100 ( V_23 -> V_44 ) ;
V_174:
F_73 ( V_23 ) ;
return V_131 ;
}
static int F_101 ( struct V_167 * V_168 )
{
struct V_22 * V_23 = F_102 ( V_168 ) ;
F_91 ( & V_23 -> V_60 , L_31 V_182 ) ;
F_95 ( V_23 -> V_28 ) ;
F_96 ( V_23 -> V_170 ) ;
F_99 ( & V_23 -> V_60 ) ;
F_97 ( V_23 -> V_142 ) ;
F_100 ( V_23 -> V_44 ) ;
F_73 ( V_23 ) ;
return 0 ;
}
