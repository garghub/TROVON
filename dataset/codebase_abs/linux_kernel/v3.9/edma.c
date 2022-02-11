static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_9 ) ;
}
static inline struct V_10
* F_4 ( struct V_11 * V_12 )
{
return F_2 ( V_12 , struct V_10 , V_13 . V_12 ) ;
}
static void F_5 ( struct V_14 * V_13 )
{
F_6 ( F_2 ( V_13 , struct V_10 , V_13 ) ) ;
}
static void F_7 ( struct V_5 * V_15 )
{
struct V_14 * V_13 = F_8 ( & V_15 -> V_8 ) ;
struct V_10 * V_16 ;
int V_17 ;
if ( ! V_13 ) {
V_15 -> V_16 = NULL ;
return;
}
F_9 ( & V_13 -> V_18 ) ;
V_15 -> V_16 = V_16 = F_4 ( & V_13 -> V_12 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_19 ; V_17 ++ ) {
F_10 ( V_15 -> V_20 [ V_17 ] , & V_16 -> V_21 [ V_17 ] ) ;
F_11 ( V_15 -> V_8 . V_9 . V_22 -> V_23 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11 ,
V_17 , V_15 -> V_24 , V_15 -> V_20 [ V_17 ] ,
V_16 -> V_21 [ V_17 ] . V_25 ,
V_16 -> V_21 [ V_17 ] . V_26 ,
V_16 -> V_21 [ V_17 ] . V_27 ,
V_16 -> V_21 [ V_17 ] . V_28 ,
V_16 -> V_21 [ V_17 ] . V_29 ,
V_16 -> V_21 [ V_17 ] . V_30 ,
V_16 -> V_21 [ V_17 ] . V_31 ,
V_16 -> V_21 [ V_17 ] . V_32 ) ;
if ( V_17 != ( V_16 -> V_19 - 1 ) )
F_12 ( V_15 -> V_20 [ V_17 ] , V_15 -> V_20 [ V_17 + 1 ] ) ;
else
F_12 ( V_15 -> V_20 [ V_17 ] , V_15 -> V_33 -> V_34 ) ;
}
F_13 ( V_15 -> V_24 ) ;
}
static int F_14 ( struct V_5 * V_15 )
{
unsigned long V_35 ;
F_15 ( V_36 ) ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
if ( V_15 -> V_16 ) {
V_15 -> V_16 = NULL ;
F_17 ( V_15 -> V_24 ) ;
}
F_18 ( & V_15 -> V_8 , & V_36 ) ;
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
F_20 ( & V_15 -> V_8 , & V_36 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_15 ,
struct V_38 * V_39 )
{
if ( V_39 -> V_40 == V_41 ||
V_39 -> V_42 == V_41 )
return - V_43 ;
memcpy ( & V_15 -> V_39 , V_39 , sizeof( V_15 -> V_39 ) ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_9 , enum V_44 V_45 ,
unsigned long V_46 )
{
int V_47 = 0 ;
struct V_38 * V_48 ;
struct V_5 * V_15 = F_3 ( V_9 ) ;
switch ( V_45 ) {
case V_49 :
F_14 ( V_15 ) ;
break;
case V_50 :
V_48 = (struct V_38 * ) V_46 ;
V_47 = F_21 ( V_15 , V_48 ) ;
break;
default:
V_47 = - V_51 ;
}
return V_47 ;
}
static struct V_11 * F_23 (
struct V_6 * V_9 , struct V_52 * V_53 ,
unsigned int V_54 , enum V_55 V_56 ,
unsigned long V_57 , void * V_58 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_22 -> V_23 ;
struct V_10 * V_16 ;
T_1 V_59 ;
enum V_60 V_61 ;
T_2 V_62 ;
struct V_52 * V_63 ;
int V_17 ;
int V_64 , V_65 , V_29 , V_26 , V_27 , V_66 ;
int V_67 , V_68 , V_69 , V_70 ;
if ( F_24 ( ! V_15 || ! V_53 || ! V_54 ) )
return NULL ;
if ( V_56 == V_71 ) {
V_59 = V_15 -> V_39 . V_72 ;
V_61 = V_15 -> V_39 . V_40 ;
V_62 = V_15 -> V_39 . V_73 ;
} else if ( V_56 == V_74 ) {
V_59 = V_15 -> V_39 . V_75 ;
V_61 = V_15 -> V_39 . V_42 ;
V_62 = V_15 -> V_39 . V_76 ;
} else {
F_25 ( V_23 , L_12 , V_77 ) ;
return NULL ;
}
if ( V_61 == V_78 ) {
F_25 ( V_23 , L_13 ) ;
return NULL ;
}
if ( V_54 > V_79 ) {
F_25 ( V_23 , L_14 ,
V_54 , V_79 ) ;
return NULL ;
}
V_16 = F_26 ( sizeof( * V_16 ) + V_54 *
sizeof( V_16 -> V_21 [ 0 ] ) , V_80 ) ;
if ( ! V_16 ) {
F_11 ( V_23 , L_15 ) ;
return NULL ;
}
V_16 -> V_19 = V_54 ;
F_27 (sgl, sg, sg_len, i) {
if ( V_15 -> V_20 [ V_17 ] < 0 ) {
V_15 -> V_20 [ V_17 ] =
F_28 ( F_29 ( V_15 -> V_24 ) ,
V_81 ) ;
if ( V_15 -> V_20 [ V_17 ] < 0 ) {
F_25 ( V_23 , L_16 ) ;
return NULL ;
}
}
V_64 = V_61 ;
if ( V_62 == 1 ) {
V_16 -> V_82 = false ;
V_29 = F_30 ( V_63 ) / V_64 / ( V_83 - 1 ) ;
V_65 = F_30 ( V_63 ) / V_64 - V_29 * ( V_83 - 1 ) ;
if ( V_65 )
V_29 ++ ;
else
V_65 = V_83 - 1 ;
V_66 = V_64 ;
} else {
V_16 -> V_82 = true ;
V_65 = V_62 ;
V_29 = F_30 ( V_63 ) / ( V_64 * V_65 ) ;
if ( V_29 > ( V_83 - 1 ) ) {
F_25 ( V_23 , L_17 ) ;
return NULL ;
}
V_66 = V_64 * V_65 ;
}
if ( V_56 == V_74 ) {
V_26 = F_31 ( V_63 ) ;
V_27 = V_59 ;
V_67 = V_64 ;
V_69 = V_66 ;
V_68 = 0 ;
V_70 = 0 ;
} else {
V_26 = V_59 ;
V_27 = F_31 ( V_63 ) ;
V_67 = 0 ;
V_69 = 0 ;
V_68 = V_64 ;
V_70 = V_66 ;
}
V_16 -> V_21 [ V_17 ] . V_25 = F_32 ( F_33 ( V_15 -> V_24 ) ) ;
if ( V_16 -> V_82 )
V_16 -> V_21 [ V_17 ] . V_25 |= V_84 ;
if ( V_17 == V_54 - 1 )
V_16 -> V_21 [ V_17 ] . V_25 |= V_85 ;
V_16 -> V_21 [ V_17 ] . V_26 = V_26 ;
V_16 -> V_21 [ V_17 ] . V_27 = V_27 ;
V_16 -> V_21 [ V_17 ] . V_30 = ( V_68 << 16 ) | V_67 ;
V_16 -> V_21 [ V_17 ] . V_31 = ( V_70 << 16 ) | V_69 ;
V_16 -> V_21 [ V_17 ] . V_28 = V_65 << 16 | V_64 ;
V_16 -> V_21 [ V_17 ] . V_29 = V_29 ;
V_16 -> V_21 [ V_17 ] . V_32 = 0xffffffff ;
}
return F_34 ( & V_15 -> V_8 , & V_16 -> V_13 , V_57 ) ;
}
static void F_35 ( unsigned V_24 , T_3 V_86 , void * V_87 )
{
struct V_5 * V_15 = V_87 ;
struct V_22 * V_23 = V_15 -> V_8 . V_9 . V_22 -> V_23 ;
struct V_10 * V_16 ;
unsigned long V_35 ;
F_17 ( V_15 -> V_24 ) ;
switch ( V_86 ) {
case V_88 :
F_11 ( V_23 , L_18 , V_24 ) ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
V_16 = V_15 -> V_16 ;
if ( V_16 ) {
F_7 ( V_15 ) ;
F_36 ( & V_16 -> V_13 ) ;
}
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
break;
case V_89 :
F_11 ( V_23 , L_19 , V_24 ) ;
break;
default:
break;
}
}
static int F_37 ( struct V_6 * V_9 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_22 -> V_23 ;
int V_47 ;
int V_90 ;
F_15 ( V_91 ) ;
V_90 = F_38 ( V_15 -> V_24 , F_35 ,
V_9 , V_92 ) ;
if ( V_90 < 0 ) {
V_47 = - V_93 ;
goto V_94;
}
if ( V_90 != V_15 -> V_24 ) {
F_25 ( V_23 , L_20 ,
F_29 ( V_15 -> V_24 ) ,
F_33 ( V_15 -> V_24 ) ) ;
V_47 = - V_93 ;
goto V_95;
}
V_15 -> V_96 = true ;
V_15 -> V_20 [ 0 ] = V_15 -> V_24 ;
F_39 ( V_23 , L_21 ,
F_29 ( V_15 -> V_24 ) , F_33 ( V_15 -> V_24 ) ) ;
return 0 ;
V_95:
F_40 ( V_90 ) ;
V_94:
return V_47 ;
}
static void F_41 ( struct V_6 * V_9 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_22 -> V_23 ;
int V_17 ;
F_17 ( V_15 -> V_24 ) ;
F_42 ( & V_15 -> V_8 ) ;
for ( V_17 = 1 ; V_17 < V_97 ; V_17 ++ ) {
if ( V_15 -> V_20 [ V_17 ] >= 0 ) {
F_43 ( V_15 -> V_20 [ V_17 ] ) ;
V_15 -> V_20 [ V_17 ] = - 1 ;
}
}
if ( V_15 -> V_96 ) {
F_40 ( V_15 -> V_24 ) ;
V_15 -> V_96 = false ;
}
F_39 ( V_23 , L_22 , V_15 -> V_24 ) ;
}
static void F_44 ( struct V_6 * V_9 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
unsigned long V_35 ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
if ( F_45 ( & V_15 -> V_8 ) && ! V_15 -> V_16 )
F_7 ( V_15 ) ;
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
}
static T_4 F_46 ( struct V_10 * V_16 )
{
int V_17 ;
T_4 V_98 ;
if ( V_16 -> V_82 )
for ( V_98 = V_17 = 0 ; V_17 < V_16 -> V_19 ; V_17 ++ )
V_98 += ( V_16 -> V_21 [ V_17 ] . V_28 & 0xffff ) *
( V_16 -> V_21 [ V_17 ] . V_28 >> 16 ) *
V_16 -> V_21 [ V_17 ] . V_29 ;
else
V_98 = ( V_16 -> V_21 [ 0 ] . V_28 & 0xffff ) *
( V_16 -> V_21 [ 0 ] . V_28 >> 16 ) +
( V_16 -> V_21 [ 0 ] . V_28 & 0xffff ) *
( V_83 - 1 ) * V_16 -> V_21 [ 0 ] . V_29 ;
return V_98 ;
}
static enum V_99 F_47 ( struct V_6 * V_9 ,
T_5 V_100 ,
struct V_101 * V_102 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_14 * V_13 ;
enum V_99 V_47 ;
unsigned long V_35 ;
V_47 = F_48 ( V_9 , V_100 , V_102 ) ;
if ( V_47 == V_103 || ! V_102 )
return V_47 ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
V_13 = F_49 ( & V_15 -> V_8 , V_100 ) ;
if ( V_13 ) {
V_102 -> V_104 = F_46 ( F_4 ( & V_13 -> V_12 ) ) ;
} else if ( V_15 -> V_16 && V_15 -> V_16 -> V_13 . V_12 . V_100 == V_100 ) {
struct V_10 * V_16 = V_15 -> V_16 ;
V_102 -> V_104 = F_46 ( V_16 ) ;
} else {
V_102 -> V_104 = 0 ;
}
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
return V_47 ;
}
static void T_6 F_50 ( struct V_1 * V_33 ,
struct V_2 * V_105 ,
struct V_5 * V_106 )
{
int V_17 , V_107 ;
for ( V_17 = 0 ; V_17 < V_108 ; V_17 ++ ) {
struct V_5 * V_15 = & V_106 [ V_17 ] ;
V_15 -> V_24 = F_51 ( V_33 -> V_109 , V_17 ) ;
V_15 -> V_33 = V_33 ;
V_15 -> V_8 . V_110 = F_5 ;
F_52 ( & V_15 -> V_8 , V_105 ) ;
F_53 ( & V_15 -> V_18 ) ;
for ( V_107 = 0 ; V_107 < V_97 ; V_107 ++ )
V_15 -> V_20 [ V_107 ] = - 1 ;
}
}
static void F_54 ( struct V_1 * V_33 , struct V_2 * V_105 ,
struct V_22 * V_23 )
{
V_105 -> V_111 = F_23 ;
V_105 -> V_112 = F_37 ;
V_105 -> V_113 = F_41 ;
V_105 -> V_114 = F_44 ;
V_105 -> V_115 = F_47 ;
V_105 -> V_116 = F_22 ;
V_105 -> V_23 = V_23 ;
F_53 ( & V_105 -> V_117 ) ;
}
static int F_55 ( struct V_118 * V_119 )
{
struct V_1 * V_33 ;
int V_47 ;
V_33 = F_56 ( & V_119 -> V_23 , sizeof( * V_33 ) , V_120 ) ;
if ( ! V_33 ) {
F_25 ( & V_119 -> V_23 , L_23 ) ;
return - V_121 ;
}
V_33 -> V_109 = V_119 -> V_122 ;
V_33 -> V_34 = F_28 ( V_33 -> V_109 , V_81 ) ;
if ( V_33 -> V_34 < 0 ) {
F_25 ( & V_119 -> V_23 , L_24 ) ;
return - V_123 ;
}
F_57 ( V_33 -> V_4 . V_124 ) ;
F_58 ( V_125 , V_33 -> V_4 . V_124 ) ;
F_54 ( V_33 , & V_33 -> V_4 , & V_119 -> V_23 ) ;
F_50 ( V_33 , & V_33 -> V_4 , V_33 -> V_126 ) ;
V_47 = F_59 ( & V_33 -> V_4 ) ;
if ( V_47 )
goto V_127;
F_60 ( V_119 , V_33 ) ;
F_39 ( & V_119 -> V_23 , L_25 ) ;
return 0 ;
V_127:
F_43 ( V_33 -> V_34 ) ;
return V_47 ;
}
static int F_61 ( struct V_118 * V_119 )
{
struct V_22 * V_23 = & V_119 -> V_23 ;
struct V_1 * V_33 = F_62 ( V_23 ) ;
F_63 ( & V_33 -> V_4 ) ;
F_43 ( V_33 -> V_34 ) ;
return 0 ;
}
bool F_64 ( struct V_6 * V_9 , void * V_128 )
{
if ( V_9 -> V_22 -> V_23 -> V_129 == & V_130 . V_129 ) {
struct V_5 * V_15 = F_3 ( V_9 ) ;
unsigned V_131 = * ( unsigned * ) V_128 ;
return V_131 == V_15 -> V_24 ;
}
return false ;
}
static int F_65 ( void )
{
int V_47 = F_66 ( & V_130 ) ;
if ( V_47 == 0 ) {
V_132 = F_67 ( & V_133 ) ;
if ( F_68 ( V_132 ) ) {
F_69 ( & V_130 ) ;
V_47 = F_70 ( V_132 ) ;
goto V_134;
}
V_132 -> V_23 . V_135 = & V_132 -> V_23 . V_136 ;
V_132 -> V_23 . V_136 = F_71 ( 32 ) ;
}
if ( V_137 == 2 ) {
V_138 = F_67 ( & V_139 ) ;
if ( F_68 ( V_138 ) ) {
F_69 ( & V_130 ) ;
F_72 ( V_132 ) ;
V_47 = F_70 ( V_138 ) ;
}
V_138 -> V_23 . V_135 = & V_138 -> V_23 . V_136 ;
V_138 -> V_23 . V_136 = F_71 ( 32 ) ;
}
V_134:
return V_47 ;
}
static void T_7 F_73 ( void )
{
F_72 ( V_132 ) ;
if ( V_138 )
F_72 ( V_138 ) ;
F_69 ( & V_130 ) ;
}
