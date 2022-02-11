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
}
static int F_28 ( struct V_23 * V_24 ,
unsigned int V_36 ,
unsigned int V_37 , void * V_38 )
{
struct V_6 * V_7 = V_24 -> V_29 ;
struct V_30 * V_31 = F_26 ( V_7 -> V_13 . V_32 ) ;
struct V_17 * V_18 = V_38 ;
struct V_17 V_39 ;
T_2 V_25 ;
int V_15 ;
V_25 = V_18 -> V_21 [ 0 ] ;
V_39 . V_19 = V_24 -> V_32 -> V_19 ;
V_39 . V_20 = 2 ;
V_39 . V_21 [ 0 ] = V_18 -> V_21 [ 0 ] ;
V_39 . V_21 [ 1 ] = V_18 -> V_21 [ 1 ] ;
F_29 ( V_24 , V_36 , V_25 , & V_40 ,
V_7 ) ;
V_15 = F_30 ( & V_7 -> V_13 , V_25 ) ;
if ( V_15 ) {
F_31 ( V_31 -> V_41 , L_1 ,
V_7 -> V_13 . V_42 , V_25 ) ;
return V_15 ;
}
V_15 = F_32 ( V_24 , V_36 , V_37 , & V_39 ) ;
if ( V_15 )
F_33 ( & V_7 -> V_13 , V_25 ) ;
return V_15 ;
}
static void F_34 ( struct V_23 * V_24 , unsigned int V_36 ,
unsigned int V_37 )
{
struct V_6 * V_7 = V_24 -> V_29 ;
struct V_28 * V_38 = F_35 ( V_36 ) ;
F_36 ( V_24 , V_36 , V_37 ) ;
F_33 ( & V_7 -> V_13 , V_38 -> V_25 ) ;
}
static struct V_43 *
F_37 ( struct V_30 * V_31 , T_1 V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_31 -> V_46 ; V_45 ++ ) {
struct V_43 * V_47 = V_31 -> V_48 + V_45 ;
if ( V_47 -> V_44 == V_44 )
return V_47 ;
}
return NULL ;
}
static bool F_38 ( struct V_30 * V_31 ,
T_1 V_49 , T_1 V_50 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_31 -> V_51 -> V_52 ; V_45 ++ ) {
const struct V_53 * V_44 = V_31 -> V_51 -> V_54 + V_45 ;
const struct V_55 * V_56 = V_44 -> V_57 ;
if ( V_44 -> V_44 . V_58 != V_49 )
continue;
while ( V_56 && V_56 -> V_59 ) {
if ( V_56 -> V_60 == V_50 )
return true ;
V_56 ++ ;
}
break;
}
return false ;
}
static int F_39 ( struct V_30 * V_31 ,
T_1 V_44 , T_1 V_50 , struct V_43 * V_47 ,
struct V_61 * * V_62 , unsigned * V_63 ,
unsigned * V_64 )
{
if ( * V_64 == * V_63 )
return - V_65 ;
( * V_62 ) [ * V_64 ] . type = V_66 ;
( * V_62 ) [ * V_64 ] . V_38 . V_67 . V_68 = V_47 -> V_59 ;
if ( ! F_38 ( V_31 , V_44 , V_50 ) ) {
F_31 ( V_31 -> V_41 , L_2 ,
V_50 , V_44 ) ;
return - V_27 ;
}
( * V_62 ) [ * V_64 ] . V_38 . V_67 . V_3 = V_69 [ V_50 ] ;
( * V_64 ) ++ ;
return 0 ;
}
static int F_40 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
struct V_61 * * V_62 ,
unsigned * V_63 ,
unsigned * V_64 )
{
struct V_30 * V_31 ;
struct V_43 * V_47 ;
struct V_74 * V_54 ;
T_1 V_75 , V_44 , V_56 ;
unsigned long * V_76 ;
unsigned int V_77 ;
bool V_78 = 0 ;
unsigned V_79 = 0 ;
int V_80 , V_81 , V_82 , V_45 , V_83 ;
V_31 = F_41 ( V_71 ) ;
V_54 = F_42 ( V_73 , L_3 , NULL ) ;
if ( ! V_54 ) {
F_31 ( V_31 -> V_41 , L_4 ,
V_73 -> V_59 ) ;
return - V_27 ;
}
V_83 = F_43 ( V_73 , V_71 , & V_76 ,
& V_77 ) ;
if ( V_83 )
return V_83 ;
if ( V_77 )
V_78 = 1 ;
V_80 = V_54 -> V_84 / sizeof( T_1 ) ;
V_81 = V_80 ;
V_82 = 0 ;
if ( V_81 )
V_82 ++ ;
if ( V_78 && V_80 >= 1 )
V_82 ++ ;
if ( ! V_80 || ! V_82 )
return - V_27 ;
V_79 = V_80 * V_82 ;
V_83 = F_44 ( V_71 , V_62 ,
V_63 , V_64 , V_79 ) ;
if ( V_83 )
return V_83 ;
for ( V_45 = 0 ; V_45 < V_80 ; V_45 ++ ) {
V_83 = F_45 ( V_73 , L_3 ,
V_45 , & V_75 ) ;
if ( V_83 )
return V_83 ;
V_44 = F_46 ( V_75 ) ;
V_56 = F_47 ( V_75 ) ;
if ( V_44 >= V_31 -> V_51 -> V_52 ) {
F_31 ( V_31 -> V_41 , L_5 ) ;
return - V_27 ;
}
if ( ! F_38 ( V_31 , V_44 , V_56 ) ) {
F_31 ( V_31 -> V_41 , L_6 ) ;
return - V_27 ;
}
V_47 = F_37 ( V_31 , V_44 ) ;
if ( ! V_47 ) {
F_31 ( V_31 -> V_41 , L_7 ,
V_44 ) ;
return - V_27 ;
}
V_83 = F_39 ( V_31 , V_44 , V_56 , V_47 , V_62 ,
V_63 , V_64 ) ;
if ( V_83 )
return V_83 ;
if ( V_78 ) {
V_83 = F_48 ( V_71 , V_62 ,
V_63 , V_64 , V_47 -> V_59 ,
V_76 , V_77 ,
V_85 ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
static int F_49 ( struct V_70 * V_71 ,
struct V_72 * V_86 ,
struct V_61 * * V_62 , unsigned * V_64 )
{
struct V_72 * V_87 ;
unsigned V_63 ;
int V_15 ;
* V_62 = NULL ;
* V_64 = 0 ;
V_63 = 0 ;
F_50 (np_config, np) {
V_15 = F_40 ( V_71 , V_87 , V_62 ,
& V_63 , V_64 ) ;
if ( V_15 < 0 ) {
F_51 ( V_71 , * V_62 , * V_64 ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_52 ( struct V_70 * V_71 )
{
struct V_30 * V_31 = F_41 ( V_71 ) ;
return V_31 -> V_46 ;
}
static const char * F_53 ( struct V_70 * V_71 ,
unsigned V_68 )
{
struct V_30 * V_31 = F_41 ( V_71 ) ;
return V_31 -> V_48 [ V_68 ] . V_59 ;
}
static int F_54 ( struct V_70 * V_71 ,
unsigned V_68 ,
const unsigned * * V_54 ,
unsigned * V_80 )
{
struct V_30 * V_31 = F_41 ( V_71 ) ;
* V_54 = ( unsigned * ) & V_31 -> V_48 [ V_68 ] . V_44 ;
* V_80 = 1 ;
return 0 ;
}
static int F_55 ( struct V_70 * V_71 )
{
return F_56 ( V_69 ) ;
}
static const char * F_57 ( struct V_70 * V_71 ,
unsigned V_88 )
{
return V_69 [ V_88 ] ;
}
static int F_58 ( struct V_70 * V_71 ,
unsigned V_3 ,
const char * const * * V_48 ,
unsigned * const V_89 )
{
struct V_30 * V_31 = F_41 ( V_71 ) ;
* V_48 = V_31 -> V_90 ;
* V_89 = V_31 -> V_46 ;
return 0 ;
}
static void F_59 ( struct V_6 * V_7 ,
int V_44 , T_1 V_91 , T_1 V_92 )
{
T_1 V_93 ;
int V_94 = ( V_44 % 8 ) * 4 ;
int V_95 = V_96 + ( V_44 / 8 ) * 4 ;
unsigned long V_97 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_95 ) ;
V_93 &= ~ F_61 ( V_94 + 3 , V_94 ) ;
V_93 |= ( V_92 << V_94 ) ;
F_7 ( V_93 , V_7 -> V_11 + V_95 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_99 ) ;
V_93 &= ~ F_61 ( V_44 * 2 + 1 , V_44 * 2 ) ;
V_93 |= V_91 << ( V_44 * 2 ) ;
F_7 ( V_93 , V_7 -> V_11 + V_99 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static void F_63 ( struct V_6 * V_7 ,
int V_44 , T_1 * V_91 , T_1 * V_92 )
{
T_1 V_93 ;
int V_94 = ( V_44 % 8 ) * 4 ;
int V_95 = V_96 + ( V_44 / 8 ) * 4 ;
unsigned long V_97 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_95 ) ;
V_93 &= F_61 ( V_94 + 3 , V_94 ) ;
* V_92 = V_93 >> V_94 ;
V_93 = F_16 ( V_7 -> V_11 + V_99 ) ;
V_93 &= F_61 ( V_44 * 2 + 1 , V_44 * 2 ) ;
* V_91 = V_93 >> ( V_44 * 2 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static int F_64 ( struct V_70 * V_71 ,
unsigned V_3 ,
unsigned V_68 )
{
bool V_15 ;
struct V_30 * V_31 = F_41 ( V_71 ) ;
struct V_43 * V_100 = V_31 -> V_48 + V_68 ;
struct V_101 * V_34 ;
struct V_6 * V_7 ;
T_1 V_91 , V_92 ;
int V_44 ;
V_15 = F_38 ( V_31 , V_100 -> V_44 , V_3 ) ;
if ( ! V_15 ) {
F_31 ( V_31 -> V_41 , L_8 ,
V_3 , V_68 ) ;
return - V_27 ;
}
V_34 = F_65 ( V_71 , V_100 -> V_44 ) ;
V_7 = F_66 ( V_34 ) ;
V_44 = F_1 ( V_100 -> V_44 ) ;
V_91 = F_2 ( V_3 ) ;
V_92 = F_4 ( V_3 ) ;
F_59 ( V_7 , V_44 , V_91 , V_92 ) ;
return 0 ;
}
static int F_67 ( struct V_70 * V_71 ,
struct V_101 * V_34 , unsigned V_1 ,
bool V_102 )
{
struct V_6 * V_7 = F_66 ( V_34 ) ;
int V_44 = F_1 ( V_1 ) ;
F_59 ( V_7 , V_44 , ! V_102 , 0 ) ;
return 0 ;
}
static void F_68 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_103 )
{
unsigned long V_97 ;
T_1 V_93 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_104 ) ;
V_93 &= ~ F_8 ( V_8 ) ;
V_93 |= V_103 << V_8 ;
F_7 ( V_93 , V_7 -> V_11 + V_104 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_69 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_97 ;
T_1 V_93 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_104 ) ;
V_93 &= F_8 ( V_8 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_93 >> V_8 ) ;
}
static void F_70 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_105 )
{
unsigned long V_97 ;
T_1 V_93 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_106 ) ;
V_93 &= ~ F_61 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_93 |= V_105 << ( V_8 * 2 ) ;
F_7 ( V_93 , V_7 -> V_11 + V_106 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_71 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_97 ;
T_1 V_93 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_106 ) ;
V_93 &= F_61 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_93 >> ( V_8 * 2 ) ) ;
}
static void F_72 ( struct V_6 * V_7 ,
unsigned V_8 , T_1 V_107 )
{
unsigned long V_97 ;
T_1 V_93 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_108 ) ;
V_93 &= ~ F_61 ( V_8 * 2 + 1 , V_8 * 2 ) ;
V_93 |= V_107 << ( V_8 * 2 ) ;
F_7 ( V_93 , V_7 -> V_11 + V_108 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
}
static T_1 F_73 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_97 ;
T_1 V_93 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
V_93 = F_16 ( V_7 -> V_11 + V_108 ) ;
V_93 &= F_61 ( V_8 * 2 + 1 , V_8 * 2 ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
return ( V_93 >> ( V_8 * 2 ) ) ;
}
static bool F_74 ( struct V_6 * V_7 ,
unsigned int V_8 , bool V_109 )
{
unsigned long V_97 ;
T_1 V_93 ;
F_6 ( V_7 -> V_10 ) ;
F_60 ( & V_7 -> V_98 , V_97 ) ;
if ( V_109 )
V_93 = ! ! ( F_16 ( V_7 -> V_11 + V_16 ) &
F_8 ( V_8 ) ) ;
else
V_93 = ! ! ( F_16 ( V_7 -> V_11 + V_110 ) &
F_8 ( V_8 ) ) ;
F_62 ( & V_7 -> V_98 , V_97 ) ;
F_9 ( V_7 -> V_10 ) ;
return V_93 ;
}
static int F_75 ( struct V_70 * V_71 ,
unsigned int V_44 , enum V_111 V_21 ,
enum V_111 V_112 )
{
struct V_101 * V_34 ;
struct V_6 * V_7 ;
int V_8 , V_15 = 0 ;
V_34 = F_65 ( V_71 , V_44 ) ;
V_7 = F_66 ( V_34 ) ;
V_8 = F_1 ( V_44 ) ;
switch ( V_21 ) {
case V_113 :
F_68 ( V_7 , V_8 , 0 ) ;
break;
case V_114 :
F_68 ( V_7 , V_8 , 1 ) ;
break;
case V_115 :
F_70 ( V_7 , V_8 , V_112 ) ;
break;
case V_116 :
F_72 ( V_7 , V_8 , 0 ) ;
break;
case V_117 :
F_72 ( V_7 , V_8 , 1 ) ;
break;
case V_118 :
F_72 ( V_7 , V_8 , 2 ) ;
break;
case V_119 :
F_5 ( V_7 , V_8 , V_112 ) ;
V_15 = F_67 ( V_71 , NULL , V_44 , false ) ;
break;
default:
V_15 = - V_27 ;
}
return V_15 ;
}
static int F_76 ( struct V_70 * V_71 ,
unsigned V_68 ,
unsigned long * V_120 )
{
struct V_30 * V_31 = F_41 ( V_71 ) ;
* V_120 = V_31 -> V_48 [ V_68 ] . V_120 ;
return 0 ;
}
static int F_77 ( struct V_70 * V_71 , unsigned V_68 ,
unsigned long * V_76 , unsigned V_77 )
{
struct V_30 * V_31 = F_41 ( V_71 ) ;
struct V_43 * V_100 = & V_31 -> V_48 [ V_68 ] ;
int V_45 , V_15 ;
for ( V_45 = 0 ; V_45 < V_77 ; V_45 ++ ) {
V_15 = F_75 ( V_71 , V_100 -> V_44 ,
F_78 ( V_76 [ V_45 ] ) ,
F_79 ( V_76 [ V_45 ] ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_100 -> V_120 = V_76 [ V_45 ] ;
}
return 0 ;
}
static void F_80 ( struct V_70 * V_71 ,
struct V_121 * V_122 ,
unsigned int V_44 )
{
struct V_101 * V_34 ;
struct V_6 * V_7 ;
int V_8 ;
T_1 V_91 , V_92 , V_103 , V_105 , V_107 ;
static const char * const V_123 [] = {
L_9 , L_10 , L_11 , L_12 } ;
static const char * const V_124 [] = {
L_13 , L_14 , L_15 , L_16 } ;
static const char * const V_125 [] = {
L_17 , L_18 , L_19 , L_20 } ;
bool V_93 ;
V_34 = F_81 ( V_71 , V_44 ) ;
V_7 = F_66 ( V_34 ) ;
V_8 = F_1 ( V_44 ) ;
F_63 ( V_7 , V_8 , & V_91 , & V_92 ) ;
V_107 = F_73 ( V_7 , V_8 ) ;
F_82 ( V_122 , L_21 , V_123 [ V_91 ] ) ;
switch ( V_91 ) {
case 0 :
V_93 = F_74 ( V_7 , V_8 , true ) ;
F_82 ( V_122 , L_22 ,
V_93 ? L_15 : L_13 ,
V_125 [ V_107 ] ) ;
break;
case 1 :
V_103 = F_69 ( V_7 , V_8 ) ;
V_105 = F_71 ( V_7 , V_8 ) ;
V_93 = F_74 ( V_7 , V_8 , false ) ;
F_82 ( V_122 , L_23 ,
V_93 ? L_15 : L_13 ,
V_103 ? L_24 : L_25 ,
V_125 [ V_107 ] ,
V_124 [ V_105 ] , L_26 ) ;
break;
case 2 :
V_103 = F_69 ( V_7 , V_8 ) ;
V_105 = F_71 ( V_7 , V_8 ) ;
F_82 ( V_122 , L_27 , V_92 ,
V_103 ? L_24 : L_25 ,
V_125 [ V_107 ] ,
V_124 [ V_105 ] , L_26 ) ;
break;
case 3 :
break;
}
}
static int F_83 ( struct V_30 * V_31 ,
struct V_72 * V_87 )
{
int V_126 = V_31 -> V_127 ;
struct V_6 * V_7 = & V_31 -> V_128 [ V_126 ] ;
struct V_101 * V_34 = & V_7 -> V_34 ;
struct V_129 * V_41 = V_31 -> V_41 ;
struct V_130 V_131 ;
struct V_132 * V_133 ;
int V_83 , V_52 ;
V_133 = F_84 ( V_87 , NULL ) ;
if ( ! F_85 ( V_133 ) )
F_86 ( V_133 ) ;
if ( F_87 ( V_87 , 0 , & V_131 ) )
return - V_134 ;
V_7 -> V_11 = F_88 ( V_41 , & V_131 ) ;
if ( F_85 ( V_7 -> V_11 ) )
return F_89 ( V_7 -> V_11 ) ;
V_7 -> V_10 = F_90 ( V_87 , NULL ) ;
if ( F_85 ( V_7 -> V_10 ) ) {
F_31 ( V_41 , L_28 , F_89 ( V_7 -> V_10 ) ) ;
return F_89 ( V_7 -> V_10 ) ;
}
V_83 = F_91 ( V_7 -> V_10 ) ;
if ( V_83 ) {
F_31 ( V_41 , L_29 , V_83 ) ;
return V_83 ;
}
V_52 = V_31 -> V_51 -> V_52 ;
V_52 -= V_126 * V_2 ;
if ( V_52 < 0 )
return - V_27 ;
else if ( V_52 > V_2 )
V_52 = V_2 ;
V_7 -> V_13 = V_135 ;
V_7 -> V_13 . V_11 = V_126 * V_2 ;
V_7 -> V_13 . V_136 = V_52 ;
V_7 -> V_13 . V_137 = V_87 ;
V_7 -> V_13 . V_32 = V_41 ;
F_92 ( & V_7 -> V_98 ) ;
F_93 ( V_87 , L_30 , & V_34 -> V_59 ) ;
V_7 -> V_13 . V_42 = V_34 -> V_59 ;
V_34 -> V_35 = V_126 ;
V_34 -> V_138 = V_34 -> V_11 = V_34 -> V_35 * V_2 ;
V_34 -> V_52 = V_7 -> V_13 . V_136 ;
V_34 -> V_139 = & V_7 -> V_13 ;
V_7 -> V_19 = F_94 ( V_87 ) ;
V_7 -> V_140 = F_95 ( V_31 -> V_140 , 0 ,
V_26 , V_7 -> V_19 ,
& V_141 , V_7 ) ;
if ( ! V_7 -> V_140 )
return - V_134 ;
V_83 = F_96 ( & V_7 -> V_13 , V_7 ) ;
if ( V_83 ) {
F_31 ( V_41 , L_31 , V_126 ) ;
return V_83 ;
}
F_97 ( V_41 , L_32 , V_34 -> V_59 ) ;
return 0 ;
}
static int F_98 ( struct V_142 * V_143 ,
struct V_30 * V_31 )
{
struct V_72 * V_87 = V_143 -> V_41 . V_137 , * V_32 ;
struct V_129 * V_41 = & V_143 -> V_41 ;
struct V_144 * V_145 ;
int V_8 , V_15 , V_45 ;
V_32 = F_99 ( V_87 ) ;
if ( ! V_32 )
return - V_146 ;
V_31 -> V_140 = F_100 ( V_32 ) ;
if ( ! V_31 -> V_140 )
return - V_146 ;
V_31 -> V_144 = F_101 ( V_87 , L_33 ) ;
if ( F_85 ( V_31 -> V_144 ) )
return F_89 ( V_31 -> V_144 ) ;
V_145 = V_31 -> V_144 ;
V_15 = F_45 ( V_87 , L_33 , 1 , & V_8 ) ;
if ( V_15 )
return V_15 ;
for ( V_45 = 0 ; V_45 < V_2 ; V_45 ++ ) {
struct V_147 V_67 ;
V_67 . V_148 = V_8 + ( V_45 / 4 ) * 4 ;
V_67 . V_149 = ( V_45 % 4 ) * 4 ;
V_67 . V_150 = V_67 . V_149 + 3 ;
V_31 -> V_33 [ V_45 ] = F_102 ( V_41 , V_145 , V_67 ) ;
if ( F_85 ( V_31 -> V_33 [ V_45 ] ) )
return F_89 ( V_31 -> V_33 [ V_45 ] ) ;
}
return 0 ;
}
static int F_103 ( struct V_142 * V_143 )
{
struct V_30 * V_31 = F_104 ( V_143 ) ;
int V_45 ;
V_31 -> V_46 = V_31 -> V_51 -> V_52 ;
V_31 -> V_48 = F_105 ( & V_143 -> V_41 , V_31 -> V_46 ,
sizeof( * V_31 -> V_48 ) , V_151 ) ;
if ( ! V_31 -> V_48 )
return - V_152 ;
V_31 -> V_90 = F_105 ( & V_143 -> V_41 , V_31 -> V_46 ,
sizeof( * V_31 -> V_90 ) , V_151 ) ;
if ( ! V_31 -> V_90 )
return - V_152 ;
for ( V_45 = 0 ; V_45 < V_31 -> V_51 -> V_52 ; V_45 ++ ) {
const struct V_53 * V_44 = V_31 -> V_51 -> V_54 + V_45 ;
struct V_43 * V_68 = V_31 -> V_48 + V_45 ;
V_68 -> V_59 = V_44 -> V_44 . V_59 ;
V_68 -> V_44 = V_44 -> V_44 . V_58 ;
V_31 -> V_90 [ V_45 ] = V_44 -> V_44 . V_59 ;
}
return 0 ;
}
int F_106 ( struct V_142 * V_143 )
{
struct V_72 * V_87 = V_143 -> V_41 . V_137 ;
struct V_72 * V_153 ;
const struct V_154 * V_155 ;
struct V_129 * V_41 = & V_143 -> V_41 ;
struct V_30 * V_31 ;
struct V_156 * V_54 ;
int V_45 , V_15 , V_128 = 0 ;
if ( ! V_87 )
return - V_27 ;
V_155 = F_107 ( V_41 -> V_157 -> V_158 , V_41 ) ;
if ( ! V_155 || ! V_155 -> V_38 )
return - V_27 ;
if ( ! F_42 ( V_87 , L_34 , NULL ) ) {
F_31 ( V_41 , L_35 ) ;
return - V_27 ;
}
V_31 = F_108 ( V_41 , sizeof( * V_31 ) , V_151 ) ;
if ( ! V_31 )
return - V_152 ;
F_109 ( V_143 , V_31 ) ;
V_31 -> V_41 = V_41 ;
V_31 -> V_51 = V_155 -> V_38 ;
V_15 = F_103 ( V_143 ) ;
if ( V_15 ) {
F_31 ( V_41 , L_36 , V_15 ) ;
return - V_27 ;
}
if ( F_42 ( V_87 , L_37 , NULL ) ) {
V_15 = F_98 ( V_143 , V_31 ) ;
if ( V_15 )
return V_15 ;
}
F_50 (np, child)
if ( F_110 ( V_153 , L_38 ) )
V_128 ++ ;
if ( ! V_128 ) {
F_31 ( V_41 , L_39 ) ;
return - V_27 ;
}
V_31 -> V_128 = F_105 ( V_41 , V_128 , sizeof( * V_31 -> V_128 ) ,
V_151 ) ;
if ( ! V_31 -> V_128 )
return - V_152 ;
F_50 (np, child) {
if ( F_110 ( V_153 , L_38 ) ) {
V_15 = F_83 ( V_31 , V_153 ) ;
if ( V_15 )
return V_15 ;
V_31 -> V_127 ++ ;
}
}
V_54 = F_105 ( & V_143 -> V_41 , V_31 -> V_51 -> V_52 , sizeof( * V_54 ) ,
V_151 ) ;
if ( ! V_54 )
return - V_152 ;
for ( V_45 = 0 ; V_45 < V_31 -> V_51 -> V_52 ; V_45 ++ )
V_54 [ V_45 ] = V_31 -> V_51 -> V_54 [ V_45 ] . V_44 ;
V_31 -> V_159 . V_59 = F_111 ( & V_143 -> V_41 ) ;
V_31 -> V_159 . V_160 = V_161 ;
V_31 -> V_159 . V_54 = V_54 ;
V_31 -> V_159 . V_52 = V_31 -> V_51 -> V_52 ;
V_31 -> V_159 . V_162 = & V_163 ;
V_31 -> V_159 . V_164 = & V_165 ;
V_31 -> V_159 . V_166 = & V_167 ;
V_31 -> V_41 = & V_143 -> V_41 ;
V_31 -> V_168 = F_112 ( & V_143 -> V_41 , & V_31 -> V_159 ,
V_31 ) ;
if ( F_85 ( V_31 -> V_168 ) ) {
F_31 ( & V_143 -> V_41 , L_40 ) ;
return F_89 ( V_31 -> V_168 ) ;
}
for ( V_45 = 0 ; V_45 < V_31 -> V_127 ; V_45 ++ )
F_113 ( V_31 -> V_168 , & V_31 -> V_128 [ V_45 ] . V_34 ) ;
F_97 ( V_41 , L_41 ) ;
return 0 ;
}
