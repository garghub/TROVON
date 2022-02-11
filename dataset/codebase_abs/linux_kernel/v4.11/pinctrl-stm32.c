static inline int F_1 ( int V_1 )
{
return V_1 % V_2 ;
}
static inline T_1 F_2 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case F_3 ( 0 ) ... F_3 ( 15 ) :
return 2 ;
case V_5 :
return 3 ;
}
return 0 ;
}
static inline T_1 F_4 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case F_3 ( 0 ) ... F_3 ( 15 ) :
return V_3 - 1 ;
case V_5 :
return 0 ;
}
return 0 ;
}
static inline void F_5 ( struct V_6 * V_7 ,
unsigned V_8 , int V_9 )
{
if ( ! V_9 )
V_8 += V_2 ;
F_6 ( V_7 -> V_10 ) ;
F_7 ( F_8 ( V_8 ) , V_7 -> V_11 + V_12 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_10 ( struct V_13 * V_14 , unsigned V_8 )
{
return F_11 ( V_14 -> V_11 + V_8 ) ;
}
static void F_12 ( struct V_13 * V_14 , unsigned V_8 )
{
F_13 ( V_14 -> V_11 + V_8 ) ;
}
static int F_14 ( struct V_13 * V_14 , unsigned V_8 )
{
struct V_6 * V_7 = F_15 ( V_14 ) ;
int V_15 ;
F_6 ( V_7 -> V_10 ) ;
V_15 = ! ! ( F_16 ( V_7 -> V_11 + V_16 ) & F_8 ( V_8 ) ) ;
F_9 ( V_7 -> V_10 ) ;
return V_15 ;
}
static void F_17 ( struct V_13 * V_14 , unsigned V_8 , int V_9 )
{
struct V_6 * V_7 = F_15 ( V_14 ) ;
F_5 ( V_7 , V_8 , V_9 ) ;
}
static int F_18 ( struct V_13 * V_14 , unsigned V_8 )
{
return F_19 ( V_14 -> V_11 + V_8 ) ;
}
static int F_20 ( struct V_13 * V_14 ,
unsigned V_8 , int V_9 )
{
struct V_6 * V_7 = F_15 ( V_14 ) ;
F_5 ( V_7 , V_8 , V_9 ) ;
F_21 ( V_14 -> V_11 + V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 , unsigned int V_8 )
{
struct V_6 * V_7 = F_15 ( V_14 ) ;
struct V_17 V_18 ;
V_18 . V_19 = V_7 -> V_19 ;
V_18 . V_20 = 2 ;
V_18 . V_21 [ 0 ] = V_8 ;
V_18 . V_21 [ 1 ] = V_22 ;
return F_23 ( & V_18 ) ;
}
static int F_24 ( struct V_23 * V_24 ,
struct V_17 * V_18 ,
unsigned long * V_25 ,
unsigned int * type )
{
if ( ( V_18 -> V_20 != 2 ) ||
( V_18 -> V_21 [ 0 ] >= V_26 ) )
return - V_27 ;
* V_25 = V_18 -> V_21 [ 0 ] ;
* type = V_18 -> V_21 [ 1 ] ;
return 0 ;
}
static void F_25 ( struct V_23 * V_24 ,
struct V_28 * V_28 )
{
struct V_6 * V_7 = V_24 -> V_29 ;
struct V_30 * V_31 = F_26 ( V_7 -> V_13 . V_32 ) ;
F_27 ( V_31 -> V_33 [ V_28 -> V_25 ] , V_7 -> V_34 . V_35 ) ;
F_28 ( & V_7 -> V_13 , V_28 -> V_25 ) ;
}
static void F_29 ( struct V_23 * V_24 ,
struct V_28 * V_28 )
{
struct V_6 * V_7 = V_24 -> V_29 ;
F_30 ( & V_7 -> V_13 , V_28 -> V_25 ) ;
}
static int F_31 ( struct V_23 * V_24 ,
unsigned int V_36 ,
unsigned int V_37 , void * V_38 )
{
struct V_6 * V_7 = V_24 -> V_29 ;
struct V_17 * V_18 = V_38 ;
struct V_17 V_39 ;
T_2 V_25 ;
V_25 = V_18 -> V_21 [ 0 ] ;
V_39 . V_19 = V_24 -> V_32 -> V_19 ;
V_39 . V_20 = 2 ;
V_39 . V_21 [ 0 ] = V_18 -> V_21 [ 0 ] ;
V_39 . V_21 [ 1 ] = V_18 -> V_21 [ 1 ] ;
F_32 ( V_24 , V_36 , V_25 , & V_40 ,
V_7 ) ;
return F_33 ( V_24 , V_36 , V_37 , & V_39 ) ;
}
static struct V_41 *
F_34 ( struct V_30 * V_31 , T_1 V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_44 ; V_43 ++ ) {
struct V_41 * V_45 = V_31 -> V_46 + V_43 ;
if ( V_45 -> V_42 == V_42 )
return V_45 ;
}
return NULL ;
}
static bool F_35 ( struct V_30 * V_31 ,
T_1 V_47 , T_1 V_48 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_49 -> V_50 ; V_43 ++ ) {
const struct V_51 * V_42 = V_31 -> V_49 -> V_52 + V_43 ;
const struct V_53 * V_54 = V_42 -> V_55 ;
if ( V_42 -> V_42 . V_56 != V_47 )
continue;
while ( V_54 && V_54 -> V_57 ) {
if ( V_54 -> V_58 == V_48 )
return true ;
V_54 ++ ;
}
break;
}
return false ;
}
static int F_36 ( struct V_30 * V_31 ,
T_1 V_42 , T_1 V_48 , struct V_41 * V_45 ,
struct V_59 * * V_60 , unsigned * V_61 ,
unsigned * V_62 )
{
if ( * V_62 == * V_61 )
return - V_63 ;
( * V_60 ) [ * V_62 ] . type = V_64 ;
( * V_60 ) [ * V_62 ] . V_38 . V_65 . V_66 = V_45 -> V_57 ;
if ( ! F_35 ( V_31 , V_42 , V_48 ) ) {
F_37 ( V_31 -> V_67 , L_1 ,
V_48 , V_42 ) ;
return - V_27 ;
}
( * V_60 ) [ * V_62 ] . V_38 . V_65 . V_3 = V_68 [ V_48 ] ;
( * V_62 ) ++ ;
return 0 ;
}
static int F_38 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_59 * * V_60 ,
unsigned * V_61 ,
unsigned * V_62 )
{
struct V_30 * V_31 ;
struct V_41 * V_45 ;
struct V_73 * V_52 ;
T_1 V_74 , V_42 , V_54 ;
unsigned long * V_75 ;
unsigned int V_76 ;
bool V_77 = 0 ;
unsigned V_78 = 0 ;
int V_79 , V_80 , V_81 , V_43 , V_82 ;
V_31 = F_39 ( V_70 ) ;
V_52 = F_40 ( V_72 , L_2 , NULL ) ;
if ( ! V_52 ) {
F_37 ( V_31 -> V_67 , L_3 ,
V_72 -> V_57 ) ;
return - V_27 ;
}
V_82 = F_41 ( V_72 , V_70 , & V_75 ,
& V_76 ) ;
if ( V_82 )
return V_82 ;
if ( V_76 )
V_77 = 1 ;
V_79 = V_52 -> V_83 / sizeof( T_1 ) ;
V_80 = V_79 ;
V_81 = 0 ;
if ( V_80 )
V_81 ++ ;
if ( V_77 && V_79 >= 1 )
V_81 ++ ;
if ( ! V_79 || ! V_81 )
return - V_27 ;
V_78 = V_79 * V_81 ;
V_82 = F_42 ( V_70 , V_60 ,
V_61 , V_62 , V_78 ) ;
if ( V_82 )
return V_82 ;
for ( V_43 = 0 ; V_43 < V_79 ; V_43 ++ ) {
V_82 = F_43 ( V_72 , L_2 ,
V_43 , & V_74 ) ;
if ( V_82 )
return V_82 ;
V_42 = F_44 ( V_74 ) ;
V_54 = F_45 ( V_74 ) ;
if ( V_42 >= V_31 -> V_49 -> V_50 ) {
F_37 ( V_31 -> V_67 , L_4 ) ;
return - V_27 ;
}
if ( ! F_35 ( V_31 , V_42 , V_54 ) ) {
F_37 ( V_31 -> V_67 , L_5 ) ;
return - V_27 ;
}
V_45 = F_34 ( V_31 , V_42 ) ;
if ( ! V_45 ) {
F_37 ( V_31 -> V_67 , L_6 ,
V_42 ) ;
return - V_27 ;
}
V_82 = F_36 ( V_31 , V_42 , V_54 , V_45 , V_60 ,
V_61 , V_62 ) ;
if ( V_82 )
return V_82 ;
if ( V_77 ) {
V_82 = F_46 ( V_70 , V_60 ,
V_61 , V_62 , V_45 -> V_57 ,
V_75 , V_76 ,
V_84 ) ;
if ( V_82 )
return V_82 ;
}
}
return 0 ;
}
static int F_47 ( struct V_69 * V_70 ,
struct V_71 * V_85 ,
struct V_59 * * V_60 , unsigned * V_62 )
{
struct V_71 * V_86 ;
unsigned V_61 ;
int V_15 ;
* V_60 = NULL ;
* V_62 = 0 ;
V_61 = 0 ;
F_48 (np_config, np) {
V_15 = F_38 ( V_70 , V_86 , V_60 ,
& V_61 , V_62 ) ;
if ( V_15 < 0 ) {
F_49 ( V_70 , * V_60 , * V_62 ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_50 ( struct V_69 * V_70 )
{
struct V_30 * V_31 = F_39 ( V_70 ) ;
return V_31 -> V_44 ;
}
static const char * F_51 ( struct V_69 * V_70 ,
unsigned V_66 )
{
struct V_30 * V_31 = F_39 ( V_70 ) ;
return V_31 -> V_46 [ V_66 ] . V_57 ;
}
static int F_52 ( struct V_69 * V_70 ,
unsigned V_66 ,
const unsigned * * V_52 ,
unsigned * V_79 )
{
struct V_30 * V_31 = F_39 ( V_70 ) ;
* V_52 = ( unsigned * ) & V_31 -> V_46 [ V_66 ] . V_42 ;
* V_79 = 1 ;
return 0 ;
}
static int F_53 ( struct V_69 * V_70 )
{
return F_54 ( V_68 ) ;
}
static const char * F_55 ( struct V_69 * V_70 ,
unsigned V_87 )
{
return V_68 [ V_87 ] ;
}
static int F_56 ( struct V_69 * V_70 ,
unsigned V_3 ,
const char * const * * V_46 ,
unsigned * const V_88 )
{
struct V_30 * V_31 = F_39 ( V_70 ) ;
* V_46 = V_31 -> V_89 ;
* V_88 = V_31 -> V_44 ;
return 0 ;
}
static void F_57 ( struct V_6 * V_7 ,
int V_42 , T_1 V_90 , T_1 V_91 )
{
T_1 V_92 ;
int V_93 = ( V_42 % 8 ) * 4 ;
int V_94 = V_95 + ( V_42 / 8 ) * 4 ;
unsigned long V_96 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_94 ) ;
V_92 &= ~ F_59 ( V_93 + 3 , V_93 ) ;
V_92 |= ( V_91 << V_93 ) ;
F_7 ( V_92 , V_7 -> V_11 + V_94 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_98 ) ;
V_92 &= ~ F_59 ( V_42 * 2 + 1 , V_42 * 2 ) ;
V_92 |= V_90 << ( V_42 * 2 ) ;
F_7 ( V_92 , V_7 -> V_11 + V_98 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static void F_61 ( struct V_6 * V_7 ,
int V_42 , T_1 * V_90 , T_1 * V_91 )
{
T_1 V_92 ;
int V_93 = ( V_42 % 8 ) * 4 ;
int V_94 = V_95 + ( V_42 / 8 ) * 4 ;
unsigned long V_96 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_94 ) ;
V_92 &= F_59 ( V_93 + 3 , V_93 ) ;
* V_91 = V_92 >> V_93 ;
V_92 = F_16 ( V_7 -> V_11 + V_98 ) ;
V_92 &= F_59 ( V_42 * 2 + 1 , V_42 * 2 ) ;
* V_90 = V_92 >> ( V_42 * 2 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_62 ( struct V_69 * V_70 ,
unsigned V_3 ,
unsigned V_66 )
{
bool V_15 ;
struct V_30 * V_31 = F_39 ( V_70 ) ;
struct V_41 * V_99 = V_31 -> V_46 + V_66 ;
struct V_100 * V_34 ;
struct V_6 * V_7 ;
T_1 V_90 , V_91 ;
int V_42 ;
V_15 = F_35 ( V_31 , V_99 -> V_42 , V_3 ) ;
if ( ! V_15 ) {
F_37 ( V_31 -> V_67 , L_7 ,
V_3 , V_66 ) ;
return - V_27 ;
}
V_34 = F_63 ( V_70 , V_99 -> V_42 ) ;
V_7 = F_64 ( V_34 ) ;
V_42 = F_1 ( V_99 -> V_42 ) ;
V_90 = F_2 ( V_3 ) ;
V_91 = F_4 ( V_3 ) ;
F_57 ( V_7 , V_42 , V_90 , V_91 ) ;
return 0 ;
}
static int F_65 ( struct V_69 * V_70 ,
struct V_100 * V_34 , unsigned V_1 ,
bool V_101 )
{
struct V_6 * V_7 = F_64 ( V_34 ) ;
int V_42 = F_1 ( V_1 ) ;
F_57 ( V_7 , V_42 , ! V_101 , 0 ) ;
return 0 ;
}
static void F_66 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_102 )
{
unsigned long V_96 ;
T_1 V_92 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_103 ) ;
V_92 &= ~ F_8 ( V_8 ) ;
V_92 |= V_102 << V_8 ;
F_7 ( V_92 , V_7 -> V_11 + V_103 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_67 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_96 ;
T_1 V_92 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_103 ) ;
V_92 &= F_8 ( V_8 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_92 >> V_8 ) ;
}
static void F_68 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_104 )
{
unsigned long V_96 ;
T_1 V_92 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_105 ) ;
V_92 &= ~ F_59 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_92 |= V_104 << ( V_8 * 2 ) ;
F_7 ( V_92 , V_7 -> V_11 + V_105 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_69 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_96 ;
T_1 V_92 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_105 ) ;
V_92 &= F_59 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_92 >> ( V_8 * 2 ) ) ;
}
static void F_70 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_106 )
{
unsigned long V_96 ;
T_1 V_92 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_107 ) ;
V_92 &= ~ F_59 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_92 |= V_106 << ( V_8 * 2 ) ;
F_7 ( V_92 , V_7 -> V_11 + V_107 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_71 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_96 ;
T_1 V_92 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
V_92 = F_16 ( V_7 -> V_11 + V_107 ) ;
V_92 &= F_59 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_92 >> ( V_8 * 2 ) ) ;
}
static bool F_72 ( struct V_6 * V_7 ,
unsigned int V_8 , bool V_108 )
{
unsigned long V_96 ;
T_1 V_92 ;
F_6 ( V_7 -> V_10 ) ;
F_58 ( & V_7 -> V_97 , V_96 ) ;
if ( V_108 )
V_92 = ! ! ( F_16 ( V_7 -> V_11 + V_16 ) &
F_8 ( V_8 ) ) ;
else
V_92 = ! ! ( F_16 ( V_7 -> V_11 + V_109 ) &
F_8 ( V_8 ) ) ;
F_60 ( & V_7 -> V_97 , V_96 ) ;
F_9 ( V_7 -> V_10 ) ;
return V_92 ;
}
static int F_73 ( struct V_69 * V_70 ,
unsigned int V_42 , enum V_110 V_21 ,
enum V_110 V_111 )
{
struct V_100 * V_34 ;
struct V_6 * V_7 ;
int V_8 , V_15 = 0 ;
V_34 = F_63 ( V_70 , V_42 ) ;
V_7 = F_64 ( V_34 ) ;
V_8 = F_1 ( V_42 ) ;
switch ( V_21 ) {
case V_112 :
F_66 ( V_7 , V_8 , 0 ) ;
break;
case V_113 :
F_66 ( V_7 , V_8 , 1 ) ;
break;
case V_114 :
F_68 ( V_7 , V_8 , V_111 ) ;
break;
case V_115 :
F_70 ( V_7 , V_8 , 0 ) ;
break;
case V_116 :
F_70 ( V_7 , V_8 , 1 ) ;
break;
case V_117 :
F_70 ( V_7 , V_8 , 2 ) ;
break;
case V_118 :
F_5 ( V_7 , V_8 , V_111 ) ;
V_15 = F_65 ( V_70 , NULL , V_42 , false ) ;
break;
default:
V_15 = - V_27 ;
}
return V_15 ;
}
static int F_74 ( struct V_69 * V_70 ,
unsigned V_66 ,
unsigned long * V_119 )
{
struct V_30 * V_31 = F_39 ( V_70 ) ;
* V_119 = V_31 -> V_46 [ V_66 ] . V_119 ;
return 0 ;
}
static int F_75 ( struct V_69 * V_70 , unsigned V_66 ,
unsigned long * V_75 , unsigned V_76 )
{
struct V_30 * V_31 = F_39 ( V_70 ) ;
struct V_41 * V_99 = & V_31 -> V_46 [ V_66 ] ;
int V_43 , V_15 ;
for ( V_43 = 0 ; V_43 < V_76 ; V_43 ++ ) {
V_15 = F_73 ( V_70 , V_99 -> V_42 ,
F_76 ( V_75 [ V_43 ] ) ,
F_77 ( V_75 [ V_43 ] ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_99 -> V_119 = V_75 [ V_43 ] ;
}
return 0 ;
}
static void F_78 ( struct V_69 * V_70 ,
struct V_120 * V_121 ,
unsigned int V_42 )
{
struct V_100 * V_34 ;
struct V_6 * V_7 ;
int V_8 ;
T_1 V_90 , V_91 , V_102 , V_104 , V_106 ;
static const char * const V_122 [] = {
L_8 , L_9 , L_10 , L_11 } ;
static const char * const V_123 [] = {
L_12 , L_13 , L_14 , L_15 } ;
static const char * const V_124 [] = {
L_16 , L_17 , L_18 , L_19 } ;
bool V_92 ;
V_34 = F_79 ( V_70 , V_42 ) ;
V_7 = F_64 ( V_34 ) ;
V_8 = F_1 ( V_42 ) ;
F_61 ( V_7 , V_8 , & V_90 , & V_91 ) ;
V_106 = F_71 ( V_7 , V_8 ) ;
F_80 ( V_121 , L_20 , V_122 [ V_90 ] ) ;
switch ( V_90 ) {
case 0 :
V_92 = F_72 ( V_7 , V_8 , true ) ;
F_80 ( V_121 , L_21 ,
V_92 ? L_14 : L_12 ,
V_124 [ V_106 ] ) ;
break;
case 1 :
V_102 = F_67 ( V_7 , V_8 ) ;
V_104 = F_69 ( V_7 , V_8 ) ;
V_92 = F_72 ( V_7 , V_8 , false ) ;
F_80 ( V_121 , L_22 ,
V_92 ? L_14 : L_12 ,
V_102 ? L_23 : L_24 ,
V_124 [ V_106 ] ,
V_123 [ V_104 ] , L_25 ) ;
break;
case 2 :
V_102 = F_67 ( V_7 , V_8 ) ;
V_104 = F_69 ( V_7 , V_8 ) ;
F_80 ( V_121 , L_26 , V_91 ,
V_102 ? L_23 : L_24 ,
V_124 [ V_106 ] ,
V_123 [ V_104 ] , L_25 ) ;
break;
case 3 :
break;
}
}
static int F_81 ( struct V_30 * V_31 ,
struct V_71 * V_86 )
{
int V_125 = V_31 -> V_126 ;
struct V_6 * V_7 = & V_31 -> V_127 [ V_125 ] ;
struct V_100 * V_34 = & V_7 -> V_34 ;
struct V_128 * V_67 = V_31 -> V_67 ;
struct V_129 V_130 ;
struct V_131 * V_132 ;
int V_82 , V_50 ;
V_132 = F_82 ( V_86 , NULL ) ;
if ( ! F_83 ( V_132 ) )
F_84 ( V_132 ) ;
if ( F_85 ( V_86 , 0 , & V_130 ) )
return - V_133 ;
V_7 -> V_11 = F_86 ( V_67 , & V_130 ) ;
if ( F_83 ( V_7 -> V_11 ) )
return F_87 ( V_7 -> V_11 ) ;
V_7 -> V_10 = F_88 ( V_86 , NULL ) ;
if ( F_83 ( V_7 -> V_10 ) ) {
F_37 ( V_67 , L_27 , F_87 ( V_7 -> V_10 ) ) ;
return F_87 ( V_7 -> V_10 ) ;
}
V_82 = F_89 ( V_7 -> V_10 ) ;
if ( V_82 ) {
F_37 ( V_67 , L_28 , V_82 ) ;
return V_82 ;
}
V_50 = V_31 -> V_49 -> V_50 ;
V_50 -= V_125 * V_2 ;
if ( V_50 < 0 )
return - V_27 ;
else if ( V_50 > V_2 )
V_50 = V_2 ;
V_7 -> V_13 = V_134 ;
V_7 -> V_13 . V_11 = V_125 * V_2 ;
V_7 -> V_13 . V_135 = V_50 ;
V_7 -> V_13 . V_136 = V_86 ;
V_7 -> V_13 . V_32 = V_67 ;
F_90 ( & V_7 -> V_97 ) ;
F_91 ( V_86 , L_29 , & V_34 -> V_57 ) ;
V_7 -> V_13 . V_137 = V_34 -> V_57 ;
V_34 -> V_35 = V_125 ;
V_34 -> V_138 = V_34 -> V_11 = V_34 -> V_35 * V_2 ;
V_34 -> V_50 = V_7 -> V_13 . V_135 ;
V_34 -> V_139 = & V_7 -> V_13 ;
V_7 -> V_19 = F_92 ( V_86 ) ;
V_7 -> V_140 = F_93 ( V_31 -> V_140 , 0 ,
V_26 , V_7 -> V_19 ,
& V_141 , V_7 ) ;
if ( ! V_7 -> V_140 )
return - V_133 ;
V_82 = F_94 ( & V_7 -> V_13 , V_7 ) ;
if ( V_82 ) {
F_37 ( V_67 , L_30 , V_125 ) ;
return V_82 ;
}
F_95 ( V_67 , L_31 , V_34 -> V_57 ) ;
return 0 ;
}
static int F_96 ( struct V_142 * V_143 ,
struct V_30 * V_31 )
{
struct V_71 * V_86 = V_143 -> V_67 . V_136 , * V_32 ;
struct V_128 * V_67 = & V_143 -> V_67 ;
struct V_144 * V_145 ;
int V_8 , V_15 , V_43 ;
V_32 = F_97 ( V_86 ) ;
if ( ! V_32 )
return - V_146 ;
V_31 -> V_140 = F_98 ( V_32 ) ;
if ( ! V_31 -> V_140 )
return - V_146 ;
V_31 -> V_144 = F_99 ( V_86 , L_32 ) ;
if ( F_83 ( V_31 -> V_144 ) )
return F_87 ( V_31 -> V_144 ) ;
V_145 = V_31 -> V_144 ;
V_15 = F_43 ( V_86 , L_32 , 1 , & V_8 ) ;
if ( V_15 )
return V_15 ;
for ( V_43 = 0 ; V_43 < V_2 ; V_43 ++ ) {
struct V_147 V_65 ;
V_65 . V_148 = V_8 + ( V_43 / 4 ) * 4 ;
V_65 . V_149 = ( V_43 % 4 ) * 4 ;
V_65 . V_150 = V_65 . V_149 + 3 ;
V_31 -> V_33 [ V_43 ] = F_100 ( V_67 , V_145 , V_65 ) ;
if ( F_83 ( V_31 -> V_33 [ V_43 ] ) )
return F_87 ( V_31 -> V_33 [ V_43 ] ) ;
}
return 0 ;
}
static int F_101 ( struct V_142 * V_143 )
{
struct V_30 * V_31 = F_102 ( V_143 ) ;
int V_43 ;
V_31 -> V_44 = V_31 -> V_49 -> V_50 ;
V_31 -> V_46 = F_103 ( & V_143 -> V_67 , V_31 -> V_44 ,
sizeof( * V_31 -> V_46 ) , V_151 ) ;
if ( ! V_31 -> V_46 )
return - V_152 ;
V_31 -> V_89 = F_103 ( & V_143 -> V_67 , V_31 -> V_44 ,
sizeof( * V_31 -> V_89 ) , V_151 ) ;
if ( ! V_31 -> V_89 )
return - V_152 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_49 -> V_50 ; V_43 ++ ) {
const struct V_51 * V_42 = V_31 -> V_49 -> V_52 + V_43 ;
struct V_41 * V_66 = V_31 -> V_46 + V_43 ;
V_66 -> V_57 = V_42 -> V_42 . V_57 ;
V_66 -> V_42 = V_42 -> V_42 . V_56 ;
V_31 -> V_89 [ V_43 ] = V_42 -> V_42 . V_57 ;
}
return 0 ;
}
int F_104 ( struct V_142 * V_143 )
{
struct V_71 * V_86 = V_143 -> V_67 . V_136 ;
struct V_71 * V_153 ;
const struct V_154 * V_155 ;
struct V_128 * V_67 = & V_143 -> V_67 ;
struct V_30 * V_31 ;
struct V_156 * V_52 ;
int V_43 , V_15 , V_127 = 0 ;
if ( ! V_86 )
return - V_27 ;
V_155 = F_105 ( V_67 -> V_157 -> V_158 , V_67 ) ;
if ( ! V_155 || ! V_155 -> V_38 )
return - V_27 ;
if ( ! F_40 ( V_86 , L_33 , NULL ) ) {
F_37 ( V_67 , L_34 ) ;
return - V_27 ;
}
V_31 = F_106 ( V_67 , sizeof( * V_31 ) , V_151 ) ;
if ( ! V_31 )
return - V_152 ;
F_107 ( V_143 , V_31 ) ;
V_31 -> V_67 = V_67 ;
V_31 -> V_49 = V_155 -> V_38 ;
V_15 = F_101 ( V_143 ) ;
if ( V_15 ) {
F_37 ( V_67 , L_35 , V_15 ) ;
return - V_27 ;
}
if ( F_40 ( V_86 , L_36 , NULL ) ) {
V_15 = F_96 ( V_143 , V_31 ) ;
if ( V_15 )
return V_15 ;
}
F_48 (np, child)
if ( F_108 ( V_153 , L_37 ) )
V_127 ++ ;
if ( ! V_127 ) {
F_37 ( V_67 , L_38 ) ;
return - V_27 ;
}
V_31 -> V_127 = F_103 ( V_67 , V_127 , sizeof( * V_31 -> V_127 ) ,
V_151 ) ;
if ( ! V_31 -> V_127 )
return - V_152 ;
F_48 (np, child) {
if ( F_108 ( V_153 , L_37 ) ) {
V_15 = F_81 ( V_31 , V_153 ) ;
if ( V_15 )
return V_15 ;
V_31 -> V_126 ++ ;
}
}
V_52 = F_103 ( & V_143 -> V_67 , V_31 -> V_49 -> V_50 , sizeof( * V_52 ) ,
V_151 ) ;
if ( ! V_52 )
return - V_152 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_49 -> V_50 ; V_43 ++ )
V_52 [ V_43 ] = V_31 -> V_49 -> V_52 [ V_43 ] . V_42 ;
V_31 -> V_159 . V_57 = F_109 ( & V_143 -> V_67 ) ;
V_31 -> V_159 . V_160 = V_161 ;
V_31 -> V_159 . V_52 = V_52 ;
V_31 -> V_159 . V_50 = V_31 -> V_49 -> V_50 ;
V_31 -> V_159 . V_162 = & V_163 ;
V_31 -> V_159 . V_164 = & V_165 ;
V_31 -> V_159 . V_166 = & V_167 ;
V_31 -> V_67 = & V_143 -> V_67 ;
V_31 -> V_168 = F_110 ( & V_143 -> V_67 , & V_31 -> V_159 ,
V_31 ) ;
if ( F_83 ( V_31 -> V_168 ) ) {
F_37 ( & V_143 -> V_67 , L_39 ) ;
return F_87 ( V_31 -> V_168 ) ;
}
for ( V_43 = 0 ; V_43 < V_31 -> V_126 ; V_43 ++ )
F_111 ( V_31 -> V_168 , & V_31 -> V_127 [ V_43 ] . V_34 ) ;
F_95 ( V_67 , L_40 ) ;
return 0 ;
}
