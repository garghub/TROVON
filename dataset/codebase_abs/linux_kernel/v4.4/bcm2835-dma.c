static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_9 ) ;
}
static inline struct V_10 * F_4 (
struct V_11 * V_12 )
{
return F_2 ( V_12 , struct V_10 , V_13 . V_14 ) ;
}
static void F_5 ( struct V_15 * V_13 )
{
struct V_10 * V_16 = F_2 ( V_13 , struct V_10 , V_13 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ )
F_6 ( V_16 -> V_7 -> V_19 , V_16 -> V_20 [ V_17 ] . V_21 ,
V_16 -> V_20 [ V_17 ] . V_22 ) ;
F_7 ( V_16 -> V_20 ) ;
F_7 ( V_16 ) ;
}
static int F_8 ( void T_1 * V_23 )
{
unsigned long V_24 ;
long int V_25 = 10000 ;
V_24 = F_9 ( V_23 + V_26 ) ;
if ( ! ( V_24 & V_27 ) )
return 0 ;
F_10 ( 0 , V_23 + V_26 ) ;
while ( ( V_24 & V_28 ) && -- V_25 ) {
F_11 () ;
V_24 = F_9 ( V_23 + V_26 ) ;
}
if ( ! V_25 )
return - V_29 ;
if ( ! ( V_24 & V_27 ) )
return 0 ;
F_10 ( 0 , V_23 + V_30 ) ;
F_10 ( V_31 | V_27 ,
V_23 + V_26 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_13 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
if ( ! V_13 ) {
V_7 -> V_16 = NULL ;
return;
}
F_14 ( & V_13 -> V_32 ) ;
V_7 -> V_16 = V_3 = F_4 ( & V_13 -> V_14 ) ;
F_10 ( V_3 -> V_20 [ 0 ] . V_22 , V_7 -> V_23 + V_33 ) ;
F_10 ( V_27 , V_7 -> V_23 + V_26 ) ;
}
static T_2 F_15 ( int V_34 , void * V_35 )
{
struct V_5 * V_7 = V_35 ;
struct V_10 * V_3 ;
unsigned long V_36 ;
F_16 ( & V_7 -> V_8 . V_37 , V_36 ) ;
F_10 ( V_38 , V_7 -> V_23 + V_26 ) ;
V_3 = V_7 -> V_16 ;
if ( V_3 ) {
F_17 ( & V_3 -> V_13 ) ;
}
F_10 ( V_27 , V_7 -> V_23 + V_26 ) ;
F_18 ( & V_7 -> V_8 . V_37 , V_36 ) ;
return V_39 ;
}
static int F_19 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_40 * V_41 = V_7 -> V_8 . V_9 . V_40 -> V_41 ;
F_20 ( V_41 , L_1 , V_7 -> V_42 ) ;
V_7 -> V_19 = F_21 ( F_22 ( V_41 ) , V_41 ,
sizeof( struct V_43 ) , 0 , 0 ) ;
if ( ! V_7 -> V_19 ) {
F_23 ( V_41 , L_2 ) ;
return - V_44 ;
}
return F_24 ( V_7 -> V_45 ,
F_15 , 0 , L_3 , V_7 ) ;
}
static void F_25 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_26 ( & V_7 -> V_8 ) ;
F_27 ( V_7 -> V_45 , V_7 ) ;
F_28 ( V_7 -> V_19 ) ;
F_20 ( V_7 -> V_8 . V_9 . V_40 -> V_41 , L_4 , V_7 -> V_42 ) ;
}
static T_3 F_29 ( struct V_10 * V_3 )
{
return V_3 -> V_46 ;
}
static T_3 F_30 ( struct V_10 * V_3 , T_4 V_47 )
{
unsigned int V_17 ;
T_3 V_46 ;
for ( V_46 = V_17 = 0 ; V_17 < V_3 -> V_18 ; V_17 ++ ) {
struct V_43 * V_48 = V_3 -> V_20 [ V_17 ] . V_21 ;
T_3 V_49 = V_48 -> V_50 ;
T_4 V_51 ;
if ( V_3 -> V_52 == V_53 )
V_51 = V_48 -> V_54 ;
else
V_51 = V_48 -> V_55 ;
if ( V_46 )
V_46 += V_49 ;
else if ( V_47 >= V_51 && V_47 < V_51 + V_49 )
V_46 += V_51 + V_49 - V_47 ;
}
return V_46 ;
}
static enum V_56 F_31 ( struct V_6 * V_9 ,
T_5 V_57 , struct V_58 * V_59 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_56 V_60 ;
unsigned long V_36 ;
V_60 = F_32 ( V_9 , V_57 , V_59 ) ;
if ( V_60 == V_61 || ! V_59 )
return V_60 ;
F_16 ( & V_7 -> V_8 . V_37 , V_36 ) ;
V_13 = F_33 ( & V_7 -> V_8 , V_57 ) ;
if ( V_13 ) {
V_59 -> V_62 =
F_29 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_16 && V_7 -> V_16 -> V_13 . V_14 . V_57 == V_57 ) {
struct V_10 * V_3 = V_7 -> V_16 ;
T_4 V_63 ;
if ( V_3 -> V_52 == V_64 )
V_63 = F_9 ( V_7 -> V_23 + V_65 ) ;
else if ( V_3 -> V_52 == V_53 )
V_63 = F_9 ( V_7 -> V_23 + V_66 ) ;
else
V_63 = 0 ;
V_59 -> V_62 = F_30 ( V_3 , V_63 ) ;
} else {
V_59 -> V_62 = 0 ;
}
F_18 ( & V_7 -> V_8 . V_37 , V_36 ) ;
return V_60 ;
}
static void F_34 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_36 ;
V_7 -> V_67 = true ;
F_16 ( & V_7 -> V_8 . V_37 , V_36 ) ;
if ( F_35 ( & V_7 -> V_8 ) && ! V_7 -> V_16 )
F_12 ( V_7 ) ;
F_18 ( & V_7 -> V_8 . V_37 , V_36 ) ;
}
static struct V_11 * F_36 (
struct V_6 * V_9 , T_4 V_68 , T_3 V_69 ,
T_3 V_70 , enum V_71 V_72 ,
unsigned long V_36 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_73 V_74 ;
struct V_10 * V_3 ;
T_4 V_75 ;
unsigned int V_76 , V_77 ;
unsigned int V_78 ;
int V_17 ;
if ( ! F_37 ( V_72 ) ) {
F_23 ( V_9 -> V_40 -> V_41 , L_5 , V_79 ) ;
return NULL ;
}
if ( V_72 == V_53 ) {
V_75 = V_7 -> V_80 . V_81 ;
V_74 = V_7 -> V_80 . V_82 ;
V_77 = V_83 ;
} else {
V_75 = V_7 -> V_80 . V_84 ;
V_74 = V_7 -> V_80 . V_85 ;
V_77 = V_86 ;
}
switch ( V_74 ) {
case V_87 :
V_76 = V_88 ;
break;
default:
return NULL ;
}
V_3 = F_38 ( sizeof( * V_3 ) , V_89 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_7 = V_7 ;
V_3 -> V_52 = V_72 ;
V_3 -> V_18 = V_69 / V_70 ;
V_3 -> V_20 = F_39 ( V_3 -> V_18 , sizeof( * V_3 -> V_20 ) , V_90 ) ;
if ( ! V_3 -> V_20 ) {
F_7 ( V_3 ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_3 -> V_18 ; V_17 ++ ) {
struct V_91 * V_92 = & V_3 -> V_20 [ V_17 ] ;
V_92 -> V_21 = F_40 ( V_7 -> V_19 , V_93 ,
& V_92 -> V_22 ) ;
if ( ! V_92 -> V_21 )
goto V_94;
}
for ( V_78 = 0 ; V_78 < V_3 -> V_18 ; V_78 ++ ) {
struct V_43 * V_48 = V_3 -> V_20 [ V_78 ] . V_21 ;
if ( V_3 -> V_52 == V_53 ) {
V_48 -> V_95 = V_96 ;
V_48 -> V_55 = V_75 ;
V_48 -> V_54 = V_68 + V_78 * V_70 ;
} else {
V_48 -> V_95 = V_97 ;
V_48 -> V_55 = V_68 + V_78 * V_70 ;
V_48 -> V_54 = V_75 ;
}
V_48 -> V_95 |= V_98 ;
if ( V_77 != 0 )
V_48 -> V_95 |= V_77 ;
if ( V_7 -> V_99 != 0 )
V_48 -> V_95 |=
F_41 ( V_7 -> V_99 ) ;
V_48 -> V_50 = V_70 ;
V_3 -> V_46 += V_48 -> V_50 ;
V_48 -> V_100 = V_3 -> V_20 [ ( ( V_78 + 1 ) % V_3 -> V_18 ) ] . V_22 ;
}
return F_42 ( & V_7 -> V_8 , & V_3 -> V_13 , V_36 ) ;
V_94:
V_17 -- ;
for (; V_17 >= 0 ; V_17 -- ) {
struct V_91 * V_92 = & V_3 -> V_20 [ V_17 ] ;
F_6 ( V_7 -> V_19 , V_92 -> V_21 , V_92 -> V_22 ) ;
}
F_7 ( V_3 -> V_20 ) ;
F_7 ( V_3 ) ;
return NULL ;
}
static int F_43 ( struct V_6 * V_9 ,
struct V_101 * V_80 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ( V_80 -> V_72 == V_53 &&
V_80 -> V_82 != V_87 ) ||
( V_80 -> V_72 == V_64 &&
V_80 -> V_85 != V_87 ) ||
! F_37 ( V_80 -> V_72 ) ) {
return - V_102 ;
}
V_7 -> V_80 = * V_80 ;
return 0 ;
}
static int F_44 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_1 * V_3 = F_1 ( V_7 -> V_8 . V_9 . V_40 ) ;
unsigned long V_36 ;
int V_25 = 10000 ;
F_45 ( V_103 ) ;
F_16 ( & V_7 -> V_8 . V_37 , V_36 ) ;
F_46 ( & V_3 -> V_37 ) ;
F_47 ( & V_7 -> V_32 ) ;
F_48 ( & V_3 -> V_37 ) ;
if ( V_7 -> V_16 ) {
F_5 ( & V_7 -> V_16 -> V_13 ) ;
V_7 -> V_16 = NULL ;
F_8 ( V_7 -> V_23 ) ;
while ( -- V_25 ) {
if ( ! ( F_9 ( V_7 -> V_23 + V_26 ) &
V_27 ) )
break;
F_11 () ;
}
if ( ! V_25 )
F_23 ( V_3 -> V_4 . V_41 , L_6 ) ;
}
F_49 ( & V_7 -> V_8 , & V_103 ) ;
F_18 ( & V_7 -> V_8 . V_37 , V_36 ) ;
F_50 ( & V_7 -> V_8 , & V_103 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_3 , int V_104 , int V_34 )
{
struct V_5 * V_7 ;
V_7 = F_52 ( V_3 -> V_4 . V_41 , sizeof( * V_7 ) , V_90 ) ;
if ( ! V_7 )
return - V_44 ;
V_7 -> V_8 . V_105 = F_5 ;
F_53 ( & V_7 -> V_8 , & V_3 -> V_4 ) ;
F_54 ( & V_7 -> V_32 ) ;
V_7 -> V_23 = F_55 ( V_3 -> V_106 , V_104 ) ;
V_7 -> V_42 = V_104 ;
V_7 -> V_45 = V_34 ;
return 0 ;
}
static void F_56 ( struct V_1 * V_107 )
{
struct V_5 * V_7 , * V_100 ;
F_57 (c, next, &od->ddev.channels,
vc.chan.device_node) {
F_14 ( & V_7 -> V_8 . V_9 . V_108 ) ;
F_58 ( & V_7 -> V_8 . V_109 ) ;
}
}
static struct V_6 * F_59 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_1 * V_3 = V_113 -> V_114 ;
struct V_6 * V_9 ;
V_9 = F_60 ( & V_3 -> V_4 ) ;
if ( ! V_9 )
return NULL ;
F_3 ( V_9 ) -> V_99 = V_111 -> args [ 0 ] ;
return V_9 ;
}
static int F_61 ( struct V_115 * V_116 )
{
struct V_1 * V_107 ;
struct V_117 * V_118 ;
void T_1 * V_106 ;
int V_119 ;
int V_17 ;
int V_34 ;
T_6 V_120 ;
if ( ! V_116 -> V_41 . V_121 )
V_116 -> V_41 . V_121 = & V_116 -> V_41 . V_122 ;
V_119 = F_62 ( & V_116 -> V_41 , F_63 ( 32 ) ) ;
if ( V_119 )
return V_119 ;
V_107 = F_52 ( & V_116 -> V_41 , sizeof( * V_107 ) , V_90 ) ;
if ( ! V_107 )
return - V_44 ;
V_116 -> V_41 . V_123 = & V_107 -> V_123 ;
F_64 ( & V_116 -> V_41 , 0x3FFFFFFF ) ;
V_118 = F_65 ( V_116 , V_124 , 0 ) ;
V_106 = F_66 ( & V_116 -> V_41 , V_118 ) ;
if ( F_67 ( V_106 ) )
return F_68 ( V_106 ) ;
V_107 -> V_106 = V_106 ;
F_69 ( V_125 , V_107 -> V_4 . V_126 ) ;
F_69 ( V_127 , V_107 -> V_4 . V_126 ) ;
F_69 ( V_128 , V_107 -> V_4 . V_126 ) ;
V_107 -> V_4 . V_129 = F_19 ;
V_107 -> V_4 . V_130 = F_25 ;
V_107 -> V_4 . V_131 = F_31 ;
V_107 -> V_4 . V_132 = F_34 ;
V_107 -> V_4 . V_133 = F_36 ;
V_107 -> V_4 . V_134 = F_43 ;
V_107 -> V_4 . V_135 = F_44 ;
V_107 -> V_4 . V_136 = F_70 ( V_87 ) ;
V_107 -> V_4 . V_137 = F_70 ( V_87 ) ;
V_107 -> V_4 . V_138 = F_70 ( V_53 ) | F_70 ( V_64 ) ;
V_107 -> V_4 . V_41 = & V_116 -> V_41 ;
F_54 ( & V_107 -> V_4 . V_139 ) ;
F_71 ( & V_107 -> V_37 ) ;
F_72 ( V_116 , V_107 ) ;
if ( F_73 ( V_116 -> V_41 . V_140 ,
L_7 ,
& V_120 ) ) {
F_23 ( & V_116 -> V_41 , L_8 ) ;
V_119 = - V_102 ;
goto V_141;
}
V_120 &= ~ ( V_142 | V_143 ) ;
for ( V_17 = 0 ; V_17 < V_116 -> V_144 ; V_17 ++ ) {
V_34 = F_74 ( V_116 , V_17 ) ;
if ( V_34 < 0 )
break;
if ( V_120 & ( 1 << V_17 ) ) {
V_119 = F_51 ( V_107 , V_17 , V_34 ) ;
if ( V_119 )
goto V_141;
}
}
F_20 ( & V_116 -> V_41 , L_9 , V_17 ) ;
V_119 = F_75 ( V_116 -> V_41 . V_140 ,
F_59 , V_107 ) ;
if ( V_119 ) {
F_23 ( & V_116 -> V_41 , L_10 ) ;
goto V_141;
}
V_119 = F_76 ( & V_107 -> V_4 ) ;
if ( V_119 ) {
F_23 ( & V_116 -> V_41 ,
L_11 , V_119 ) ;
goto V_141;
}
F_20 ( & V_116 -> V_41 , L_12 ) ;
return 0 ;
V_141:
F_56 ( V_107 ) ;
return V_119 ;
}
static int F_77 ( struct V_115 * V_116 )
{
struct V_1 * V_107 = F_78 ( V_116 ) ;
F_79 ( & V_107 -> V_4 ) ;
F_56 ( V_107 ) ;
return 0 ;
}
