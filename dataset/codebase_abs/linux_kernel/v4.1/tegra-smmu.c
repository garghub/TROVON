static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( struct V_5 * V_6 , T_1 V_7 ,
unsigned long V_8 )
{
F_4 ( V_7 , V_6 -> V_9 + V_8 ) ;
}
static inline T_1 F_5 ( struct V_5 * V_6 , unsigned long V_8 )
{
return F_6 ( V_6 -> V_9 + V_8 ) ;
}
static inline void F_7 ( struct V_5 * V_6 , struct V_10 * V_10 ,
unsigned long V_8 )
{
T_2 V_11 = V_10 ? F_8 ( V_10 ) : 0 ;
T_1 V_7 ;
if ( V_10 ) {
V_8 &= ~ ( V_6 -> V_12 -> V_13 -> V_14 - 1 ) ;
if ( V_6 -> V_12 -> V_13 -> V_15 > 32 ) {
#ifdef F_9
V_7 = ( V_11 >> 32 ) & V_16 ;
#else
V_7 = 0 ;
#endif
F_3 ( V_6 , V_7 , V_17 ) ;
}
V_7 = ( V_11 + V_8 ) | V_18 ;
} else {
V_7 = V_19 ;
}
F_3 ( V_6 , V_7 , V_20 ) ;
}
static inline void F_10 ( struct V_5 * V_6 )
{
F_3 ( V_6 , V_21 , V_22 ) ;
}
static inline void F_11 ( struct V_5 * V_6 ,
unsigned long V_23 )
{
T_1 V_7 ;
V_7 = V_24 | F_12 ( V_23 ) |
V_21 ;
F_3 ( V_6 , V_7 , V_22 ) ;
}
static inline void F_13 ( struct V_5 * V_6 ,
unsigned long V_23 ,
unsigned long V_25 )
{
T_1 V_7 ;
V_7 = V_24 | F_12 ( V_23 ) |
F_14 ( V_25 ) ;
F_3 ( V_6 , V_7 , V_22 ) ;
}
static inline void F_15 ( struct V_5 * V_6 ,
unsigned long V_23 ,
unsigned long V_25 )
{
T_1 V_7 ;
V_7 = V_24 | F_12 ( V_23 ) |
F_16 ( V_25 ) ;
F_3 ( V_6 , V_7 , V_22 ) ;
}
static inline void F_17 ( struct V_5 * V_6 )
{
F_5 ( V_6 , V_26 ) ;
}
static int F_18 ( struct V_5 * V_6 , unsigned int * V_27 )
{
unsigned long V_28 ;
F_19 ( & V_6 -> V_29 ) ;
V_28 = F_20 ( V_6 -> V_30 , V_6 -> V_13 -> V_31 ) ;
if ( V_28 >= V_6 -> V_13 -> V_31 ) {
F_21 ( & V_6 -> V_29 ) ;
return - V_32 ;
}
F_22 ( V_28 , V_6 -> V_30 ) ;
* V_27 = V_28 ;
F_21 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_23 ( struct V_5 * V_6 , unsigned int V_28 )
{
F_19 ( & V_6 -> V_29 ) ;
F_24 ( V_28 , V_6 -> V_30 ) ;
F_21 ( & V_6 -> V_29 ) ;
}
static bool F_25 ( enum V_33 V_34 )
{
return false ;
}
static struct V_2 * F_26 ( unsigned type )
{
struct V_1 * V_35 ;
unsigned int V_36 ;
T_3 * V_37 ;
if ( type != V_38 )
return NULL ;
V_35 = F_27 ( sizeof( * V_35 ) , V_39 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_40 = V_41 | V_42 | V_43 ;
V_35 -> V_37 = F_28 ( V_39 | V_44 ) ;
if ( ! V_35 -> V_37 ) {
F_29 ( V_35 ) ;
return NULL ;
}
V_35 -> V_45 = F_28 ( V_39 ) ;
if ( ! V_35 -> V_45 ) {
F_30 ( V_35 -> V_37 ) ;
F_29 ( V_35 ) ;
return NULL ;
}
V_37 = F_31 ( V_35 -> V_37 ) ;
F_32 ( V_35 -> V_37 ) ;
for ( V_36 = 0 ; V_36 < V_46 ; V_36 ++ )
V_37 [ V_36 ] = 0 ;
V_37 = F_31 ( V_35 -> V_45 ) ;
F_32 ( V_35 -> V_45 ) ;
for ( V_36 = 0 ; V_36 < V_46 ; V_36 ++ )
V_37 [ V_36 ] = 0 ;
V_35 -> V_4 . V_47 . V_48 = 0 ;
V_35 -> V_4 . V_47 . V_49 = 0xffffffff ;
V_35 -> V_4 . V_47 . V_50 = true ;
return & V_35 -> V_4 ;
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_35 = F_1 ( V_4 ) ;
F_34 ( V_35 -> V_37 ) ;
F_29 ( V_35 ) ;
}
static const struct V_51 *
F_35 ( struct V_5 * V_6 , unsigned int V_52 )
{
const struct V_51 * V_53 = NULL ;
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_6 -> V_13 -> V_54 ; V_36 ++ ) {
if ( V_6 -> V_13 -> V_55 [ V_36 ] . V_52 == V_52 ) {
V_53 = & V_6 -> V_13 -> V_55 [ V_36 ] ;
break;
}
}
return V_53 ;
}
static void F_36 ( struct V_5 * V_6 , unsigned int V_52 ,
unsigned int V_23 )
{
const struct V_51 * V_53 ;
unsigned int V_36 ;
T_1 V_7 ;
for ( V_36 = 0 ; V_36 < V_6 -> V_13 -> V_56 ; V_36 ++ ) {
const struct V_57 * V_58 = & V_6 -> V_13 -> V_59 [ V_36 ] ;
if ( V_58 -> V_52 != V_52 )
continue;
V_7 = F_5 ( V_6 , V_58 -> V_6 . V_60 ) ;
V_7 |= F_37 ( V_58 -> V_6 . V_61 ) ;
F_3 ( V_6 , V_7 , V_58 -> V_6 . V_60 ) ;
}
V_53 = F_35 ( V_6 , V_52 ) ;
if ( V_53 ) {
V_7 = F_5 ( V_6 , V_53 -> V_60 ) ;
V_7 &= ~ V_62 ;
V_7 |= F_38 ( V_23 ) ;
V_7 |= V_63 ;
F_3 ( V_6 , V_7 , V_53 -> V_60 ) ;
}
}
static void F_39 ( struct V_5 * V_6 , unsigned int V_52 ,
unsigned int V_23 )
{
const struct V_51 * V_53 ;
unsigned int V_36 ;
T_1 V_7 ;
V_53 = F_35 ( V_6 , V_52 ) ;
if ( V_53 ) {
V_7 = F_5 ( V_6 , V_53 -> V_60 ) ;
V_7 &= ~ V_62 ;
V_7 |= F_38 ( V_23 ) ;
V_7 &= ~ V_63 ;
F_3 ( V_6 , V_7 , V_53 -> V_60 ) ;
}
for ( V_36 = 0 ; V_36 < V_6 -> V_13 -> V_56 ; V_36 ++ ) {
const struct V_57 * V_58 = & V_6 -> V_13 -> V_59 [ V_36 ] ;
if ( V_58 -> V_52 != V_52 )
continue;
V_7 = F_5 ( V_6 , V_58 -> V_6 . V_60 ) ;
V_7 &= ~ F_37 ( V_58 -> V_6 . V_61 ) ;
F_3 ( V_6 , V_7 , V_58 -> V_6 . V_60 ) ;
}
}
static int F_40 ( struct V_5 * V_6 ,
struct V_1 * V_35 )
{
T_1 V_7 ;
int V_64 ;
if ( V_35 -> V_65 > 0 ) {
V_35 -> V_65 ++ ;
return 0 ;
}
V_64 = F_18 ( V_6 , & V_35 -> V_28 ) ;
if ( V_64 < 0 )
return V_64 ;
V_6 -> V_13 -> V_66 -> V_67 ( V_35 -> V_37 , 0 , V_68 ) ;
F_7 ( V_6 , V_35 -> V_37 , 0 ) ;
F_11 ( V_6 , V_35 -> V_28 ) ;
F_3 ( V_6 , V_35 -> V_28 & 0x7f , V_69 ) ;
V_7 = F_41 ( V_35 -> V_37 , V_35 -> V_40 ) ;
F_3 ( V_6 , V_7 , V_70 ) ;
F_17 ( V_6 ) ;
V_35 -> V_6 = V_6 ;
V_35 -> V_65 ++ ;
return 0 ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_1 * V_35 )
{
if ( -- V_35 -> V_65 > 0 )
return;
F_23 ( V_6 , V_35 -> V_28 ) ;
V_35 -> V_6 = NULL ;
}
static int F_43 ( struct V_2 * V_4 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = V_72 -> V_73 . V_74 ;
struct V_1 * V_35 = F_1 ( V_4 ) ;
struct V_75 * V_76 = V_72 -> V_77 ;
struct V_78 args ;
unsigned int V_79 = 0 ;
int V_64 = 0 ;
while ( ! F_44 ( V_76 , L_1 , L_2 , V_79 ,
& args ) ) {
unsigned int V_52 = args . args [ 0 ] ;
if ( args . V_76 != V_6 -> V_72 -> V_77 ) {
F_45 ( args . V_76 ) ;
continue;
}
F_45 ( args . V_76 ) ;
V_64 = F_40 ( V_6 , V_35 ) ;
if ( V_64 < 0 )
return V_64 ;
F_36 ( V_6 , V_52 , V_35 -> V_28 ) ;
V_79 ++ ;
}
if ( V_79 == 0 )
return - V_80 ;
return 0 ;
}
static void F_46 ( struct V_2 * V_4 , struct V_71 * V_72 )
{
struct V_1 * V_35 = F_1 ( V_4 ) ;
struct V_75 * V_76 = V_72 -> V_77 ;
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_78 args ;
unsigned int V_79 = 0 ;
while ( ! F_44 ( V_76 , L_1 , L_2 , V_79 ,
& args ) ) {
unsigned int V_52 = args . args [ 0 ] ;
if ( args . V_76 != V_6 -> V_72 -> V_77 ) {
F_45 ( args . V_76 ) ;
continue;
}
F_45 ( args . V_76 ) ;
F_39 ( V_6 , V_52 , V_35 -> V_28 ) ;
F_42 ( V_6 , V_35 ) ;
V_79 ++ ;
}
}
static T_1 * F_47 ( struct V_1 * V_35 , T_4 V_25 ,
struct V_10 * * V_81 )
{
T_1 * V_37 = F_31 ( V_35 -> V_37 ) , * V_82 , * V_45 ;
T_1 V_83 = ( V_25 >> V_84 ) & 0x3ff ;
T_1 V_85 = ( V_25 >> V_86 ) & 0x3ff ;
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_10 * V_10 ;
unsigned int V_36 ;
if ( V_37 [ V_83 ] == 0 ) {
V_10 = F_28 ( V_39 | V_44 ) ;
if ( ! V_10 )
return NULL ;
V_82 = F_31 ( V_10 ) ;
F_32 ( V_10 ) ;
for ( V_36 = 0 ; V_36 < V_87 ; V_36 ++ )
V_82 [ V_36 ] = 0 ;
V_6 -> V_13 -> V_66 -> V_67 ( V_10 , 0 , V_88 ) ;
V_37 [ V_83 ] = F_48 ( V_10 , V_89 | V_90 ) ;
V_6 -> V_13 -> V_66 -> V_67 ( V_35 -> V_37 , V_83 << 2 , 4 ) ;
F_7 ( V_6 , V_35 -> V_37 , V_83 << 2 ) ;
F_13 ( V_6 , V_35 -> V_28 , V_25 ) ;
F_17 ( V_6 ) ;
} else {
V_10 = F_49 ( V_37 [ V_83 ] & V_6 -> V_91 ) ;
V_82 = F_31 ( V_10 ) ;
}
* V_81 = V_10 ;
V_45 = F_31 ( V_35 -> V_45 ) ;
if ( V_82 [ V_85 ] == 0 )
V_45 [ V_83 ] ++ ;
return & V_82 [ V_85 ] ;
}
static void F_50 ( struct V_1 * V_35 , T_4 V_25 )
{
T_1 V_83 = ( V_25 >> V_84 ) & 0x3ff ;
T_1 V_85 = ( V_25 >> V_86 ) & 0x3ff ;
T_1 * V_45 = F_31 ( V_35 -> V_45 ) ;
T_1 * V_37 = F_31 ( V_35 -> V_37 ) , * V_82 ;
struct V_10 * V_10 ;
V_10 = F_49 ( V_37 [ V_83 ] & V_35 -> V_6 -> V_91 ) ;
V_82 = F_31 ( V_10 ) ;
if ( V_82 [ V_85 ] != 0 ) {
if ( -- V_45 [ V_83 ] == 0 ) {
F_34 ( V_10 ) ;
F_30 ( V_10 ) ;
V_37 [ V_83 ] = 0 ;
}
V_82 [ V_85 ] = 0 ;
}
}
static int F_51 ( struct V_2 * V_4 , unsigned long V_25 ,
T_2 V_92 , T_5 V_93 , int V_94 )
{
struct V_1 * V_35 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_35 -> V_6 ;
unsigned long V_8 ;
struct V_10 * V_10 ;
T_1 * V_85 ;
V_85 = F_47 ( V_35 , V_25 , & V_10 ) ;
if ( ! V_85 )
return - V_95 ;
* V_85 = F_52 ( V_92 ) | V_96 ;
V_8 = F_53 ( V_85 ) ;
V_6 -> V_13 -> V_66 -> V_67 ( V_10 , V_8 , 4 ) ;
F_7 ( V_6 , V_10 , V_8 ) ;
F_15 ( V_6 , V_35 -> V_28 , V_25 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static T_5 F_54 ( struct V_2 * V_4 , unsigned long V_25 ,
T_5 V_93 )
{
struct V_1 * V_35 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_35 -> V_6 ;
unsigned long V_8 ;
struct V_10 * V_10 ;
T_1 * V_85 ;
V_85 = F_47 ( V_35 , V_25 , & V_10 ) ;
if ( ! V_85 )
return 0 ;
V_8 = F_53 ( V_85 ) ;
F_50 ( V_35 , V_25 ) ;
V_6 -> V_13 -> V_66 -> V_67 ( V_10 , V_8 , 4 ) ;
F_7 ( V_6 , V_10 , V_8 ) ;
F_15 ( V_6 , V_35 -> V_28 , V_25 ) ;
F_17 ( V_6 ) ;
return V_93 ;
}
static T_2 F_55 ( struct V_2 * V_4 ,
T_4 V_25 )
{
struct V_1 * V_35 = F_1 ( V_4 ) ;
struct V_10 * V_10 ;
unsigned long V_97 ;
T_1 * V_85 ;
V_85 = F_47 ( V_35 , V_25 , & V_10 ) ;
V_97 = * V_85 & V_35 -> V_6 -> V_91 ;
return F_56 ( V_97 ) ;
}
static struct V_5 * F_57 ( struct V_75 * V_76 )
{
struct V_98 * V_99 ;
struct V_100 * V_12 ;
V_99 = F_58 ( V_76 ) ;
if ( ! V_99 )
return NULL ;
V_12 = F_59 ( V_99 ) ;
if ( ! V_12 )
return NULL ;
return V_12 -> V_6 ;
}
static int F_60 ( struct V_71 * V_72 )
{
struct V_75 * V_76 = V_72 -> V_77 ;
struct V_78 args ;
unsigned int V_79 = 0 ;
while ( F_44 ( V_76 , L_1 , L_2 , V_79 ,
& args ) == 0 ) {
struct V_5 * V_6 ;
V_6 = F_57 ( args . V_76 ) ;
if ( V_6 ) {
V_72 -> V_73 . V_74 = V_6 ;
break;
}
V_79 ++ ;
}
return 0 ;
}
static void F_61 ( struct V_71 * V_72 )
{
V_72 -> V_73 . V_74 = NULL ;
}
static void F_62 ( void )
{
static const struct V_101 V_102 [] = {
{ . V_103 = L_3 , } ,
{ }
} ;
struct V_75 * V_104 ;
V_104 = F_63 ( NULL , V_102 ) ;
if ( V_104 ) {
F_64 ( V_104 ) ;
F_45 ( V_104 ) ;
}
}
struct V_5 * F_65 ( struct V_71 * V_72 ,
const struct V_105 * V_13 ,
struct V_100 * V_12 )
{
struct V_5 * V_6 ;
T_5 V_93 ;
T_1 V_7 ;
int V_64 ;
if ( ! V_13 )
return NULL ;
V_6 = F_66 ( V_72 , sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return F_67 ( - V_95 ) ;
V_12 -> V_6 = V_6 ;
V_93 = F_68 ( V_13 -> V_31 ) * sizeof( long ) ;
V_6 -> V_30 = F_66 ( V_72 , V_93 , V_39 ) ;
if ( ! V_6 -> V_30 )
return F_67 ( - V_95 ) ;
F_69 ( & V_6 -> V_29 ) ;
V_6 -> V_9 = V_12 -> V_9 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_72 = V_72 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_91 = F_70 ( V_12 -> V_13 -> V_15 - V_106 ) - 1 ;
F_71 ( V_72 , L_4 ,
V_12 -> V_13 -> V_15 , V_6 -> V_91 ) ;
V_7 = V_107 | F_72 ( 0x3f ) ;
if ( V_13 -> V_108 )
V_7 |= F_73 ( 8 ) ;
F_3 ( V_6 , V_7 , V_109 ) ;
V_7 = V_110 |
F_74 ( 0x20 ) ;
if ( V_13 -> V_111 )
V_7 |= V_112 ;
F_3 ( V_6 , V_7 , V_113 ) ;
F_7 ( V_6 , NULL , 0 ) ;
F_10 ( V_6 ) ;
F_3 ( V_6 , V_114 , V_26 ) ;
F_17 ( V_6 ) ;
F_62 () ;
V_64 = F_75 ( & V_115 , & V_116 ) ;
if ( V_64 < 0 )
return F_67 ( V_64 ) ;
return V_6 ;
}
