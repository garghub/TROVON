static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 , T_1 V_3 )
{
return F_4 ( V_7 -> V_5 + V_3 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_7 -> V_5 + V_3 ) ;
}
static bool F_7 ( struct V_6 * V_7 )
{
T_1 V_8 = F_5 ( V_7 , V_9 ) ;
return ( V_8 & ( V_10 | V_11 ) ) == V_10 ;
}
static T_1 F_8 ( T_1 V_12 )
{
return 0xffffffff << ( 32 - ( V_12 % V_13 ? :
V_13 ) ) ;
}
static void F_9 ( struct V_6 * V_7 ,
unsigned int V_14 )
{
struct V_15 * V_16 = V_7 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_18 + V_14 ;
T_2 V_19 = 0 , V_20 = 0 ;
F_10 ( F_7 ( V_7 ) ) ;
if ( V_16 -> V_21 == V_22 )
V_20 = V_18 -> V_23 ;
else
V_19 = V_18 -> V_23 ;
F_11 ( V_7 -> V_24 . V_7 . V_25 -> V_26 ,
L_1 ,
V_7 -> V_14 , V_18 , V_18 -> V_12 , & V_19 , & V_20 ) ;
F_6 ( V_7 , V_27 , V_19 & 0xffffffff ) ;
F_6 ( V_7 , V_28 , V_20 & 0xffffffff ) ;
F_6 ( V_7 , V_29 ,
F_12 ( V_18 -> V_12 , V_13 ) ) ;
F_6 ( V_7 , V_30 , F_8 ( V_18 -> V_12 ) ) ;
F_6 ( V_7 , V_9 , V_31 |
V_32 | V_33 | V_10 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_34 * V_35 ;
V_35 = F_14 ( & V_7 -> V_24 ) ;
if ( ! V_35 ) {
V_7 -> V_16 = NULL ;
return;
}
F_15 ( & V_35 -> V_36 ) ;
V_7 -> V_16 = F_16 ( V_35 ) ;
V_7 -> V_16 -> V_37 = 0 ;
F_9 ( V_7 , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_3 V_38 ;
F_1 ( V_2 , V_39 , V_40 ) ;
V_38 = F_3 ( V_2 , V_39 ) ;
if ( ( V_38 & ( V_41 | V_40 ) ) != V_40 ) {
F_18 ( V_2 -> V_26 , L_2 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , unsigned int V_43 ,
T_4 V_44 )
{
struct V_15 * V_16 ;
unsigned long V_45 ;
V_16 = F_20 ( sizeof( * V_16 ) + V_43 * sizeof( V_16 -> V_18 [ 0 ] ) , V_44 ) ;
if ( ! V_16 )
return - V_46 ;
V_16 -> V_47 = V_43 ;
F_21 ( & V_16 -> V_36 ) ;
F_22 ( & V_7 -> V_24 . V_48 , V_45 ) ;
F_23 ( & V_16 -> V_36 , & V_7 -> V_49 ) ;
F_24 ( & V_7 -> V_24 . V_48 , V_45 ) ;
return 0 ;
}
static void F_25 ( struct V_6 * V_7 )
{
struct V_15 * V_16 , * V_50 ;
F_26 ( V_51 ) ;
F_27 ( & V_7 -> V_49 , & V_51 ) ;
F_27 ( & V_7 -> V_52 , & V_51 ) ;
F_28 (desc, _desc, &list, node) {
F_15 ( & V_16 -> V_36 ) ;
F_29 ( V_16 ) ;
}
V_7 -> V_53 = 0 ;
}
static struct V_15 * F_30 ( struct V_6 * V_7 ,
unsigned int V_43 , T_4 V_44 )
{
struct V_15 * V_16 = NULL ;
unsigned long V_45 ;
F_22 ( & V_7 -> V_24 . V_48 , V_45 ) ;
F_31 (desc, &chan->desc_freed, node) {
if ( V_43 <= V_16 -> V_47 ) {
F_32 ( & V_16 -> V_36 , & V_7 -> V_52 ) ;
F_24 ( & V_7 -> V_24 . V_48 , V_45 ) ;
return V_16 ;
}
}
F_24 ( & V_7 -> V_24 . V_48 , V_45 ) ;
if ( ! F_19 ( V_7 , V_43 , V_44 ) ) {
F_22 ( & V_7 -> V_24 . V_48 , V_45 ) ;
V_16 = F_33 ( & V_7 -> V_49 , struct V_15 ,
V_36 ) ;
F_32 ( & V_16 -> V_36 , & V_7 -> V_52 ) ;
F_24 ( & V_7 -> V_24 . V_48 , V_45 ) ;
return V_16 ;
}
return NULL ;
}
static void F_34 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
unsigned long V_45 ;
F_22 ( & V_7 -> V_24 . V_48 , V_45 ) ;
F_32 ( & V_16 -> V_36 , & V_7 -> V_49 ) ;
F_24 ( & V_7 -> V_24 . V_48 , V_45 ) ;
}
static void F_35 ( struct V_6 * V_54 )
{
struct V_55 * V_7 = & V_54 -> V_24 . V_7 ;
struct V_1 * V_2 = F_36 ( V_7 -> V_25 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_57 ; ++ V_56 ) {
if ( F_7 ( V_54 ) )
return;
}
F_1 ( V_2 , V_39 , 0 ) ;
F_1 ( V_2 , V_58 , V_59 ) ;
F_37 ( 100 ) ;
F_1 ( V_2 , V_58 , 0 ) ;
F_1 ( V_2 , V_39 , 1 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
T_1 V_8 = F_5 ( V_7 , V_9 ) ;
V_8 &= ~ ( V_33 | V_11 | V_10 ) ;
F_6 ( V_7 , V_9 , V_8 ) ;
F_35 ( V_7 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_39 , 0 ) ;
}
static int F_40 ( struct V_55 * V_7 )
{
struct V_6 * V_54 = F_41 ( V_7 ) ;
int V_60 ;
while ( V_54 -> V_53 < V_61 ) {
V_60 = F_19 ( V_54 , V_62 ,
V_63 ) ;
if ( V_60 < 0 ) {
F_25 ( V_54 ) ;
return V_60 ;
}
V_54 -> V_53 ++ ;
}
return F_42 ( V_7 -> V_25 -> V_26 ) ;
}
static void F_43 ( struct V_55 * V_7 )
{
struct V_6 * V_54 = F_41 ( V_7 ) ;
unsigned long V_45 ;
F_22 ( & V_54 -> V_24 . V_48 , V_45 ) ;
F_38 ( V_54 ) ;
F_24 ( & V_54 -> V_24 . V_48 , V_45 ) ;
F_25 ( V_54 ) ;
F_44 ( & V_54 -> V_24 ) ;
F_45 ( V_7 -> V_25 -> V_26 ) ;
}
static struct V_64 *
F_46 ( struct V_55 * V_7 , struct V_65 * V_66 ,
unsigned int V_43 , enum V_67 V_68 ,
unsigned long V_69 , void * V_70 )
{
struct V_6 * V_54 = F_41 ( V_7 ) ;
struct V_15 * V_16 ;
struct V_65 * V_18 ;
int V_56 ;
if ( ! V_43 ) {
F_18 ( V_7 -> V_25 -> V_26 ,
L_3 , V_71 , V_43 ) ;
return NULL ;
}
V_16 = F_30 ( V_54 , V_43 , V_72 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_21 = V_68 ;
V_16 -> V_43 = V_43 ;
F_47 (sgl, sg, sg_len, i) {
V_16 -> V_18 [ V_56 ] . V_23 = F_48 ( V_18 ) ;
V_16 -> V_18 [ V_56 ] . V_12 = F_49 ( V_18 ) ;
}
return F_50 ( & V_54 -> V_24 , & V_16 -> V_35 , V_69 ) ;
}
static int F_51 ( struct V_55 * V_7 )
{
struct V_6 * V_54 = F_41 ( V_7 ) ;
struct V_15 * V_16 , * V_50 ;
unsigned long V_45 ;
F_26 ( V_73 ) ;
F_26 ( V_51 ) ;
F_22 ( & V_54 -> V_24 . V_48 , V_45 ) ;
F_38 ( V_54 ) ;
F_52 ( & V_54 -> V_24 , & V_73 ) ;
if ( V_54 -> V_16 )
V_54 -> V_16 = NULL ;
F_27 ( & V_54 -> V_52 , & V_51 ) ;
F_28 (desc, _desc, &list, node)
F_32 ( & V_16 -> V_36 , & V_54 -> V_49 ) ;
F_24 ( & V_54 -> V_24 . V_48 , V_45 ) ;
F_53 ( & V_54 -> V_24 , & V_73 ) ;
return 0 ;
}
static unsigned int F_54 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
int V_37 )
{
struct V_17 * V_18 = V_16 -> V_18 + V_37 ;
T_1 V_23 = V_18 -> V_23 & 0xffffffff ;
unsigned int V_74 = V_18 -> V_12 ;
if ( V_16 -> V_21 == V_22 )
V_74 -= F_5 ( V_7 , V_28 ) - V_23 ;
else
V_74 -= F_5 ( V_7 , V_27 ) - V_23 ;
return V_74 ;
}
static T_1 F_55 ( struct V_6 * V_7 ,
T_5 V_75 )
{
struct V_15 * V_16 ;
T_1 V_74 = 0 ;
F_56 (desc, &chan->desc_freed, node) {
if ( V_16 -> V_76 == V_75 ) {
V_74 = V_16 -> V_74 ;
break;
}
}
return V_74 ;
}
static T_1 F_57 ( struct V_6 * V_7 ,
T_5 V_75 )
{
T_1 V_74 = 0 ;
struct V_34 * V_35 ;
struct V_15 * V_16 = V_7 -> V_16 ;
int V_56 ;
if ( ! V_16 ) {
V_35 = F_58 ( & V_7 -> V_24 , V_75 ) ;
if ( ! V_35 )
return 0 ;
V_16 = F_16 ( V_35 ) ;
}
for ( V_56 = V_16 -> V_37 + 1 ; V_56 < V_16 -> V_43 ; V_56 ++ )
V_74 += V_16 -> V_18 [ V_56 ] . V_12 ;
V_74 += F_54 ( V_7 , V_16 , V_16 -> V_37 ) ;
return V_74 ;
}
static enum V_77 F_59 ( struct V_55 * V_7 ,
T_5 V_75 ,
struct V_78 * V_79 )
{
struct V_6 * V_54 = F_41 ( V_7 ) ;
enum V_77 V_80 ;
unsigned int V_74 = 0 ;
unsigned long V_45 ;
V_80 = F_60 ( V_7 , V_75 , V_79 ) ;
if ( ! V_79 )
return V_80 ;
F_22 ( & V_54 -> V_24 . V_48 , V_45 ) ;
if ( V_80 == V_81 )
V_74 = F_55 ( V_54 , V_75 ) ;
else
V_74 = F_57 ( V_54 , V_75 ) ;
F_24 ( & V_54 -> V_24 . V_48 , V_45 ) ;
F_61 ( V_79 , V_74 ) ;
return V_80 ;
}
static void F_62 ( struct V_55 * V_7 )
{
struct V_6 * V_54 = F_41 ( V_7 ) ;
unsigned long V_45 ;
F_22 ( & V_54 -> V_24 . V_48 , V_45 ) ;
if ( F_63 ( & V_54 -> V_24 ) && ! V_54 -> V_16 )
F_13 ( V_54 ) ;
F_24 ( & V_54 -> V_24 . V_48 , V_45 ) ;
}
static void F_64 ( struct V_34 * V_35 )
{
struct V_15 * V_16 = F_16 ( V_35 ) ;
struct V_6 * V_7 = F_41 ( V_35 -> V_82 . V_7 ) ;
F_34 ( V_7 , V_16 ) ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_16 ;
F_66 ( ! V_16 ) ;
if ( ++ V_16 -> V_37 < V_16 -> V_43 ) {
F_9 ( V_7 , V_16 -> V_37 ) ;
} else {
V_16 -> V_74 = F_54 ( V_7 , V_16 ,
V_16 -> V_37 - 1 ) ;
V_16 -> V_76 = V_16 -> V_35 . V_82 . V_75 ;
F_67 ( & V_16 -> V_35 ) ;
F_13 ( V_7 ) ;
}
}
static T_6 F_68 ( int V_83 , void * V_26 )
{
struct V_6 * V_7 = V_26 ;
T_6 V_60 = V_84 ;
T_1 V_85 = V_11 ;
T_1 V_86 = V_11 | V_87 ;
T_1 V_8 ;
F_69 ( & V_7 -> V_24 . V_48 ) ;
V_8 = F_5 ( V_7 , V_9 ) ;
if ( V_8 & V_86 )
V_85 |= V_10 | V_86 ;
if ( V_8 & V_88 ) {
V_85 |= V_88 ;
V_8 |= V_89 ;
V_60 |= V_90 ;
}
F_6 ( V_7 , V_9 , V_8 & ~ V_85 ) ;
if ( V_8 & V_86 ) {
F_65 ( V_7 ) ;
V_60 |= V_90 ;
}
F_70 ( & V_7 -> V_24 . V_48 ) ;
return V_60 ;
}
static bool F_71 ( struct V_55 * V_7 , void * V_91 )
{
struct V_6 * V_54 = F_41 ( V_7 ) ;
struct V_92 * V_93 = V_91 ;
if ( V_93 -> V_94 != V_7 -> V_25 -> V_26 -> V_95 )
return false ;
if ( V_54 -> V_14 != V_93 -> args [ 0 ] )
return false ;
return true ;
}
static struct V_55 * F_72 ( struct V_92 * V_93 ,
struct V_96 * V_97 )
{
struct V_6 * V_54 ;
struct V_55 * V_7 ;
T_7 V_85 ;
if ( V_93 -> V_98 != 1 )
return NULL ;
F_73 ( V_85 ) ;
F_74 ( V_99 , V_85 ) ;
V_7 = F_75 ( V_85 , F_71 , V_93 ) ;
if ( ! V_7 )
return NULL ;
V_54 = F_41 ( V_7 ) ;
return V_7 ;
}
static int F_76 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_77 ( V_26 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_57 ; ++ V_56 ) {
if ( ! V_2 -> V_100 [ V_56 ] . V_5 )
break;
F_38 ( & V_2 -> V_100 [ V_56 ] ) ;
}
return 0 ;
}
static int F_78 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_77 ( V_26 ) ;
return F_17 ( V_2 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_6 * V_54 ,
unsigned int V_14 )
{
struct V_101 * V_102 = F_80 ( V_2 -> V_26 ) ;
char V_103 [ 5 ] ;
char * V_104 ;
int V_60 ;
V_54 -> V_14 = V_14 ;
V_54 -> V_5 = V_2 -> V_5 + F_81 ( V_14 ) ;
sprintf ( V_103 , L_4 , V_14 ) ;
V_54 -> V_83 = F_82 ( V_102 , V_103 ) ;
if ( V_54 -> V_83 < 0 ) {
F_83 ( V_2 -> V_26 , L_5 , V_14 ) ;
return - V_105 ;
}
V_104 = F_84 ( V_2 -> V_26 , V_63 , L_6 ,
F_85 ( V_2 -> V_26 ) , V_14 ) ;
if ( ! V_104 )
return - V_46 ;
V_60 = F_86 ( V_2 -> V_26 , V_54 -> V_83 , F_68 ,
V_106 , V_104 , V_54 ) ;
if ( V_60 ) {
F_83 ( V_2 -> V_26 , L_7 ,
V_54 -> V_83 , V_60 ) ;
return V_60 ;
}
V_54 -> V_24 . V_107 = F_64 ;
F_87 ( & V_54 -> V_24 , & V_2 -> V_108 ) ;
F_21 ( & V_54 -> V_49 ) ;
F_21 ( & V_54 -> V_52 ) ;
return 0 ;
}
static int F_88 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_109 * V_94 = V_26 -> V_95 ;
int V_60 ;
V_60 = F_89 ( V_94 , L_8 , & V_2 -> V_57 ) ;
if ( V_60 < 0 ) {
F_83 ( V_26 , L_9 ) ;
return V_60 ;
}
if ( V_2 -> V_57 <= 0 || V_2 -> V_57 >= 100 ) {
F_83 ( V_26 , L_10 ,
V_2 -> V_57 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_90 ( struct V_101 * V_102 )
{
const enum V_111 V_112 = V_113 ;
struct V_114 * V_108 ;
struct V_1 * V_2 ;
struct V_115 * V_116 ;
unsigned int V_56 ;
int V_60 ;
V_2 = F_91 ( & V_102 -> V_26 , sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_26 = & V_102 -> V_26 ;
F_92 ( V_102 , V_2 ) ;
V_60 = F_88 ( & V_102 -> V_26 , V_2 ) ;
if ( V_60 < 0 )
return V_60 ;
V_2 -> V_100 = F_93 ( & V_102 -> V_26 , V_2 -> V_57 ,
sizeof( * V_2 -> V_100 ) , V_63 ) ;
if ( ! V_2 -> V_100 )
return - V_46 ;
V_116 = F_94 ( V_102 , V_117 , 0 ) ;
V_2 -> V_5 = F_95 ( & V_102 -> V_26 , V_116 ) ;
if ( F_96 ( V_2 -> V_5 ) )
return F_97 ( V_2 -> V_5 ) ;
F_98 ( & V_102 -> V_26 ) ;
V_60 = F_42 ( & V_102 -> V_26 ) ;
if ( V_60 < 0 ) {
F_83 ( & V_102 -> V_26 , L_11 , V_60 ) ;
goto V_118;
}
V_60 = F_17 ( V_2 ) ;
if ( V_60 ) {
F_83 ( & V_102 -> V_26 , L_12 ) ;
goto error;
}
F_21 ( & V_2 -> V_108 . V_100 ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_57 ; ++ V_56 ) {
V_60 = F_79 ( V_2 , & V_2 -> V_100 [ V_56 ] , V_56 ) ;
if ( V_60 < 0 )
goto error;
}
V_60 = F_99 ( V_102 -> V_26 . V_95 , F_72 ,
NULL ) ;
if ( V_60 < 0 )
goto error;
V_108 = & V_2 -> V_108 ;
F_74 ( V_99 , V_108 -> V_119 ) ;
V_108 -> V_26 = & V_102 -> V_26 ;
V_108 -> V_120 = V_112 ;
V_108 -> V_121 = V_112 ;
V_108 -> V_122 = F_100 ( V_123 ) | F_100 ( V_22 ) ;
V_108 -> V_124 = V_125 ;
V_108 -> V_126 = F_40 ;
V_108 -> V_127 = F_43 ;
V_108 -> V_128 = F_46 ;
V_108 -> V_129 = F_51 ;
V_108 -> V_130 = F_59 ;
V_108 -> V_131 = F_62 ;
V_60 = F_101 ( V_108 ) ;
if ( V_60 < 0 )
goto error;
F_45 ( & V_102 -> V_26 ) ;
return 0 ;
error:
F_102 ( V_102 -> V_26 . V_95 ) ;
F_45 ( & V_102 -> V_26 ) ;
V_118:
F_103 ( & V_102 -> V_26 ) ;
return V_60 ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_6 * V_54 )
{
F_38 ( V_54 ) ;
F_105 ( V_2 -> V_26 , V_54 -> V_83 , V_54 ) ;
}
static int F_106 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_107 ( V_102 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_57 ; ++ V_56 )
F_104 ( V_2 , & V_2 -> V_100 [ V_56 ] ) ;
F_102 ( V_102 -> V_26 . V_95 ) ;
F_108 ( & V_2 -> V_108 ) ;
F_103 ( & V_102 -> V_26 ) ;
return 0 ;
}
static void F_109 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_107 ( V_102 ) ;
F_39 ( V_2 ) ;
}
