static inline struct V_1 * V_1 ( const struct V_2 * V_3 )
{
F_1 ( V_3 , sizeof( struct V_1 ) ) ;
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static T_1 F_3 ( const struct V_2 * V_3 , T_1 V_5 )
{
return V_1 ( V_3 ) -> V_6 [ V_5 ] ;
}
static T_1 F_4 ( T_1 V_7 , T_1 V_8 )
{
T_1 V_9 = V_7 + V_8 ;
return F_5 ( T_1 , V_9 , V_10 ) ;
}
static T_1 F_6 ( T_1 V_7 , T_1 V_8 )
{
return V_7 > V_8 ? V_7 - V_8 : 0 ;
}
static void F_7 ( T_1 V_11 , T_1 V_5 , struct V_12 * V_13 )
{
int V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ 0 ] [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
V_11 >>= V_21 ;
if ( V_16 [ V_19 ] . V_22 < 0xFFFF )
V_16 [ V_19 ] . V_22 ++ ;
V_16 += V_23 ;
}
}
static void F_8 ( const struct V_2 * V_3 , struct V_12 * V_13 )
{
T_1 V_11 ;
V_11 = F_3 ( V_3 , 0 ) ;
if ( V_11 )
F_7 ( V_11 , 0 , V_13 ) ;
V_11 = F_3 ( V_3 , 1 ) ;
if ( V_11 )
F_7 ( V_11 , 1 , V_13 ) ;
}
static void F_9 ( T_1 V_11 , T_1 V_5 ,
struct V_12 * V_13 )
{
int V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ 0 ] [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
V_11 >>= V_21 ;
if ( V_16 [ V_19 ] . V_22 > 0 )
V_16 [ V_19 ] . V_22 -- ;
V_16 += V_23 ;
}
}
static void F_10 ( const struct V_2 * V_3 , struct V_12 * V_13 )
{
T_1 V_11 ;
V_11 = F_3 ( V_3 , 0 ) ;
if ( V_11 )
F_9 ( V_11 , 0 , V_13 ) ;
V_11 = F_3 ( V_3 , 1 ) ;
if ( V_11 )
F_9 ( V_11 , 1 , V_13 ) ;
}
static void F_11 ( struct V_15 * V_16 , struct V_12 * V_13 )
{
V_16 -> V_24 = F_6 ( V_16 -> V_24 , V_13 -> V_25 ) ;
}
static void F_12 ( struct V_15 * V_16 , struct V_12 * V_13 )
{
V_16 -> V_24 = F_4 ( V_16 -> V_24 , V_13 -> V_26 ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
memset ( & V_13 -> V_17 , 0 , sizeof( V_13 -> V_17 ) ) ;
}
static T_1 F_14 ( T_1 * V_27 , T_1 * V_28 , const struct V_12 * V_13 )
{
int V_14 ;
T_1 V_22 = 0 , V_29 = 0 , V_30 = 0 ;
const struct V_15 * V_16 = & V_13 -> V_17 [ V_13 -> V_5 ] . V_17 [ 0 ] [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_18 * V_23 ; V_14 ++ ) {
if ( V_22 < V_16 -> V_22 )
V_22 = V_16 -> V_22 ;
V_30 += V_16 -> V_24 ;
if ( V_29 < V_16 -> V_24 )
V_29 = V_16 -> V_24 ;
V_16 ++ ;
}
* V_27 = V_29 ;
* V_28 = V_30 / ( V_18 * V_23 ) ;
return V_22 ;
}
static void F_15 ( T_1 V_5 , struct V_12 * V_13 )
{
V_13 -> V_17 [ V_5 ] . V_31 = F_16 () ;
}
static void F_17 ( struct V_12 * V_13 )
{
F_15 ( V_13 -> V_5 , V_13 ) ;
V_13 -> V_5 ^= 1 ;
V_13 -> V_32 = false ;
}
static bool F_18 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( V_13 -> V_33 == 0 || V_13 -> V_34 == 0 )
return true ;
if ( V_13 -> V_35 < 1 ) {
unsigned long V_36 = F_19 ( 10UL * V_37 , V_38 - V_13 -> V_39 ) ;
V_13 -> V_35 = ( V_36 * V_13 -> V_33 ) / V_37 ;
if ( V_13 -> V_35 > V_13 -> V_34 )
V_13 -> V_35 = V_13 -> V_34 ;
V_13 -> V_39 = V_38 ;
if ( V_13 -> V_35 < 1 )
return true ;
}
V_13 -> V_35 -- ;
return false ;
}
static bool F_20 ( struct V_2 * V_3 , struct V_40 * V_41 ,
int * V_42 , T_1 * V_43 )
{
struct V_44 V_9 ;
int V_45 ;
V_45 = F_21 ( V_3 , V_41 , & V_9 , false ) ;
if ( V_45 >= 0 ) {
#ifdef F_22
switch ( V_45 ) {
case V_46 :
case V_47 :
* V_42 = V_48 | V_49 ;
case V_50 :
return false ;
}
#endif
* V_43 = F_23 ( V_9 . V_51 ) ;
return true ;
}
return false ;
}
static int F_24 ( struct V_2 * V_3 , struct V_52 * V_53 ,
struct V_2 * * V_54 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_55 = V_13 -> V_56 ;
struct V_40 * V_41 ;
int V_14 ;
T_1 V_57 = ~ 0 ;
T_1 V_58 = ~ 0 ;
T_1 V_59 , V_11 ;
T_1 V_5 = V_13 -> V_5 ;
int V_60 = V_48 | V_61 ;
if ( F_26 ( V_53 -> V_13 . V_22 >= V_13 -> V_62 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_63 . V_64 ++ ;
goto V_65;
}
if ( V_13 -> V_66 > 0 ) {
unsigned long V_62 = V_13 -> V_67 + V_13 -> V_66 ;
if ( F_26 ( F_28 ( V_38 , V_62 ) ) ) {
F_17 ( V_13 ) ;
V_13 -> V_67 = V_38 ;
} else if ( F_26 ( ! V_13 -> V_32 && V_13 -> V_68 > 0 &&
F_28 ( V_38 , V_62 - V_13 -> V_68 ) ) ) {
V_13 -> V_32 = true ;
}
}
V_41 = F_29 ( V_13 -> V_69 ) ;
if ( V_41 ) {
T_1 V_43 ;
if ( ! F_20 ( V_3 , V_41 , & V_60 , & V_43 ) )
goto V_70;
V_11 = F_30 ( V_43 , V_13 -> V_17 [ V_5 ] . V_31 ) ;
} else {
V_11 = F_31 ( V_3 , V_13 -> V_17 [ V_5 ] . V_31 ) ;
}
if ( ! V_11 )
V_11 = 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = V_11 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ V_14 ] [ V_19 ] ;
V_11 >>= V_21 ;
if ( V_16 -> V_22 == 0 )
F_11 ( V_16 , V_13 ) ;
else if ( V_16 -> V_22 >= V_13 -> V_71 )
F_12 ( V_16 , V_13 ) ;
if ( V_58 > V_16 -> V_22 )
V_58 = V_16 -> V_22 ;
if ( V_57 > V_16 -> V_24 )
V_57 = V_16 -> V_24 ;
}
V_5 ^= 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = 0 ;
if ( F_26 ( V_58 >= V_13 -> V_72 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_63 . V_73 ++ ;
goto V_65;
}
if ( F_26 ( V_57 >= V_10 ) ) {
if ( V_13 -> V_32 ) {
V_11 = F_31 ( V_3 ,
V_13 -> V_17 [ V_5 ] . V_31 ) ;
if ( ! V_11 )
V_11 = 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = V_11 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
T_1 V_19 = V_11 & V_20 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_5 ] . V_17 [ V_14 ] [ V_19 ] ;
V_11 >>= V_21 ;
if ( V_16 -> V_22 == 0 )
F_11 ( V_16 , V_13 ) ;
else if ( V_16 -> V_22 >= V_13 -> V_71 )
F_12 ( V_16 , V_13 ) ;
}
}
if ( F_18 ( V_3 , V_13 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_63 . V_74 ++ ;
goto V_65;
}
goto V_75;
}
V_59 = F_16 () & V_10 ;
if ( F_26 ( V_59 < V_57 ) ) {
if ( F_26 ( V_57 > V_10 / 2 ) ) {
if ( V_59 < ( V_57 - V_10 / 2 ) * 2 ) {
V_13 -> V_63 . V_76 ++ ;
goto V_65;
}
}
if ( F_32 ( V_3 ) ) {
V_13 -> V_63 . V_77 ++ ;
} else {
V_13 -> V_63 . V_76 ++ ;
goto V_65;
}
}
V_75:
V_60 = F_33 ( V_3 , V_55 , V_54 ) ;
if ( F_34 ( V_60 == V_48 ) ) {
F_35 ( V_53 , V_3 ) ;
V_53 -> V_13 . V_22 ++ ;
F_8 ( V_3 , V_13 ) ;
} else if ( F_36 ( V_60 ) ) {
V_13 -> V_63 . V_78 ++ ;
F_37 ( V_53 ) ;
}
return V_60 ;
V_65:
F_38 ( V_3 , V_53 , V_54 ) ;
return V_79 ;
V_70:
if ( V_60 & V_61 )
F_37 ( V_53 ) ;
F_39 ( V_3 ) ;
return V_60 ;
}
static struct V_2 * F_40 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_55 = V_13 -> V_56 ;
struct V_2 * V_3 ;
V_3 = V_55 -> V_80 ( V_13 -> V_56 ) ;
if ( V_3 ) {
F_41 ( V_53 , V_3 ) ;
F_42 ( V_53 , V_3 ) ;
V_53 -> V_13 . V_22 -- ;
F_10 ( V_3 , V_13 ) ;
}
return V_3 ;
}
static struct V_2 * F_43 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_55 = V_13 -> V_56 ;
return V_55 -> V_81 -> V_82 ( V_55 ) ;
}
static void F_44 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
F_45 ( V_13 -> V_56 ) ;
V_53 -> V_83 . V_84 = 0 ;
V_53 -> V_13 . V_22 = 0 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
}
static void F_46 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
F_47 ( & V_13 -> V_69 ) ;
F_48 ( V_13 -> V_56 ) ;
}
static int F_49 ( struct V_52 * V_53 , struct V_85 * V_86 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_55 ;
struct V_85 * V_87 [ V_88 + 1 ] ;
const struct V_89 * V_90 = & V_91 ;
T_1 V_62 ;
int V_92 ;
if ( V_86 ) {
V_92 = F_50 ( V_87 , V_88 , V_86 , V_93 ) ;
if ( V_92 < 0 )
return - V_94 ;
if ( V_87 [ V_95 ] == NULL )
return - V_94 ;
V_90 = F_51 ( V_87 [ V_95 ] ) ;
}
V_62 = V_90 -> V_62 ;
if ( V_62 == 0 )
V_62 = F_52 ( V_53 ) -> V_96 ;
V_55 = F_53 ( V_53 , & V_97 , V_62 ) ;
if ( F_54 ( V_55 ) )
return F_55 ( V_55 ) ;
F_56 ( V_53 ) ;
F_57 ( V_13 -> V_56 , V_13 -> V_56 -> V_13 . V_22 ,
V_13 -> V_56 -> V_83 . V_84 ) ;
F_48 ( V_13 -> V_56 ) ;
V_13 -> V_56 = V_55 ;
V_13 -> V_66 = F_58 ( V_90 -> V_66 ) ;
V_13 -> V_68 = F_58 ( V_90 -> V_68 ) ;
V_13 -> V_67 = V_38 ;
V_13 -> V_62 = V_62 ;
V_13 -> V_26 = V_90 -> V_26 ;
V_13 -> V_25 = V_90 -> V_25 ;
V_13 -> V_72 = V_90 -> V_72 ;
V_13 -> V_71 = V_90 -> V_71 ;
V_13 -> V_33 = V_90 -> V_33 ;
V_13 -> V_34 = V_90 -> V_34 ;
V_13 -> V_35 = V_90 -> V_34 ;
V_13 -> V_39 = V_38 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
F_15 ( 1 , V_13 ) ;
F_59 ( V_53 ) ;
return 0 ;
}
static int F_60 ( struct V_52 * V_53 , struct V_85 * V_86 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
V_13 -> V_56 = & V_98 ;
return F_49 ( V_53 , V_86 ) ;
}
static int F_61 ( struct V_52 * V_53 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_85 * V_99 ;
struct V_89 V_86 = {
. V_66 = F_62 ( V_13 -> V_66 ) ,
. V_68 = F_62 ( V_13 -> V_68 ) ,
. V_62 = V_13 -> V_62 ,
. V_72 = V_13 -> V_72 ,
. V_71 = V_13 -> V_71 ,
. V_26 = V_13 -> V_26 ,
. V_25 = V_13 -> V_25 ,
. V_33 = V_13 -> V_33 ,
. V_34 = V_13 -> V_34 ,
} ;
V_53 -> V_83 . V_84 = V_13 -> V_56 -> V_83 . V_84 ;
V_99 = F_63 ( V_3 , V_100 ) ;
if ( V_99 == NULL )
goto V_101;
if ( F_64 ( V_3 , V_95 , sizeof( V_86 ) , & V_86 ) )
goto V_101;
return F_65 ( V_3 , V_99 ) ;
V_101:
F_66 ( V_3 , V_99 ) ;
return - V_102 ;
}
static int F_67 ( struct V_52 * V_53 , struct V_103 * V_104 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_105 V_106 = {
. V_76 = V_13 -> V_63 . V_76 ,
. V_74 = V_13 -> V_63 . V_74 ,
. V_73 = V_13 -> V_63 . V_73 ,
. V_64 = V_13 -> V_63 . V_64 ,
. V_78 = V_13 -> V_63 . V_78 ,
. V_77 = V_13 -> V_63 . V_77 ,
} ;
V_106 . V_107 = F_14 ( & V_106 . V_108 , & V_106 . V_109 , V_13 ) ;
return F_68 ( V_104 , & V_106 , sizeof( V_106 ) ) ;
}
static int F_69 ( struct V_52 * V_53 , unsigned long V_110 ,
struct V_2 * V_3 , struct V_111 * V_112 )
{
return - V_113 ;
}
static int F_70 ( struct V_52 * V_53 , unsigned long V_114 , struct V_52 * V_115 ,
struct V_52 * * V_116 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
if ( V_115 == NULL )
V_115 = & V_98 ;
* V_116 = F_71 ( V_53 , V_115 , & V_13 -> V_56 ) ;
return 0 ;
}
static struct V_52 * F_72 ( struct V_52 * V_53 , unsigned long V_114 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
return V_13 -> V_56 ;
}
static unsigned long F_73 ( struct V_52 * V_53 , T_1 V_51 )
{
return 1 ;
}
static void F_74 ( struct V_52 * V_53 , unsigned long V_114 )
{
}
static int F_75 ( struct V_52 * V_53 , T_1 V_51 , T_1 V_117 ,
struct V_85 * * V_118 , unsigned long * V_114 )
{
return - V_113 ;
}
static int F_76 ( struct V_52 * V_53 , unsigned long V_110 )
{
return - V_113 ;
}
static void F_77 ( struct V_52 * V_53 , struct V_119 * V_120 )
{
if ( ! V_120 -> V_121 ) {
if ( V_120 -> V_122 >= V_120 -> V_123 )
if ( V_120 -> V_124 ( V_53 , 1 , V_120 ) < 0 ) {
V_120 -> V_121 = 1 ;
return;
}
V_120 -> V_122 ++ ;
}
}
static struct V_40 T_2 * * F_78 ( struct V_52 * V_53 ,
unsigned long V_110 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
if ( V_110 )
return NULL ;
return & V_13 -> V_69 ;
}
static unsigned long F_79 ( struct V_52 * V_53 , unsigned long V_125 ,
T_1 V_51 )
{
return 0 ;
}
static int T_3 F_80 ( void )
{
return F_81 ( & V_126 ) ;
}
static void T_4 F_82 ( void )
{
F_83 ( & V_126 ) ;
}
