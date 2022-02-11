static inline struct V_1 * V_1 ( const struct V_2 * V_3 )
{
F_1 ( sizeof( V_3 -> V_4 ) <
sizeof( struct V_5 ) + sizeof( struct V_1 ) ) ;
return (struct V_1 * ) V_5 ( V_3 ) -> V_6 ;
}
static T_1 F_2 ( const struct V_2 * V_3 , T_1 V_7 )
{
return V_1 ( V_3 ) -> V_8 [ V_7 ] ;
}
static T_1 F_3 ( T_1 V_9 , T_1 V_10 )
{
T_1 V_11 = V_9 + V_10 ;
return F_4 ( T_1 , V_11 , V_12 ) ;
}
static T_1 F_5 ( T_1 V_9 , T_1 V_10 )
{
return V_9 > V_10 ? V_9 - V_10 : 0 ;
}
static void F_6 ( T_1 V_13 , T_1 V_7 , struct V_14 * V_15 )
{
int V_16 ;
struct V_17 * V_18 = & V_15 -> V_19 [ V_7 ] . V_19 [ 0 ] [ 0 ] ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
T_1 V_21 = V_13 & V_22 ;
V_13 >>= V_23 ;
if ( V_18 [ V_21 ] . V_24 < 0xFFFF )
V_18 [ V_21 ] . V_24 ++ ;
V_18 += V_25 ;
}
}
static void F_7 ( const struct V_2 * V_3 , struct V_14 * V_15 )
{
T_1 V_13 ;
V_13 = F_2 ( V_3 , 0 ) ;
if ( V_13 )
F_6 ( V_13 , 0 , V_15 ) ;
V_13 = F_2 ( V_3 , 1 ) ;
if ( V_13 )
F_6 ( V_13 , 1 , V_15 ) ;
}
static void F_8 ( T_1 V_13 , T_1 V_7 ,
struct V_14 * V_15 )
{
int V_16 ;
struct V_17 * V_18 = & V_15 -> V_19 [ V_7 ] . V_19 [ 0 ] [ 0 ] ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
T_1 V_21 = V_13 & V_22 ;
V_13 >>= V_23 ;
if ( V_18 [ V_21 ] . V_24 > 0 )
V_18 [ V_21 ] . V_24 -- ;
V_18 += V_25 ;
}
}
static void F_9 ( const struct V_2 * V_3 , struct V_14 * V_15 )
{
T_1 V_13 ;
V_13 = F_2 ( V_3 , 0 ) ;
if ( V_13 )
F_8 ( V_13 , 0 , V_15 ) ;
V_13 = F_2 ( V_3 , 1 ) ;
if ( V_13 )
F_8 ( V_13 , 1 , V_15 ) ;
}
static void F_10 ( struct V_17 * V_18 , struct V_14 * V_15 )
{
V_18 -> V_26 = F_5 ( V_18 -> V_26 , V_15 -> V_27 ) ;
}
static void F_11 ( struct V_17 * V_18 , struct V_14 * V_15 )
{
V_18 -> V_26 = F_3 ( V_18 -> V_26 , V_15 -> V_28 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
memset ( & V_15 -> V_19 , 0 , sizeof( V_15 -> V_19 ) ) ;
}
static T_1 F_13 ( T_1 * V_29 , T_1 * V_30 , const struct V_14 * V_15 )
{
int V_16 ;
T_1 V_24 = 0 , V_31 = 0 , V_32 = 0 ;
const struct V_17 * V_18 = & V_15 -> V_19 [ V_15 -> V_7 ] . V_19 [ 0 ] [ 0 ] ;
for ( V_16 = 0 ; V_16 < V_20 * V_25 ; V_16 ++ ) {
if ( V_24 < V_18 -> V_24 )
V_24 = V_18 -> V_24 ;
V_32 += V_18 -> V_26 ;
if ( V_31 < V_18 -> V_26 )
V_31 = V_18 -> V_26 ;
V_18 ++ ;
}
* V_29 = V_31 ;
* V_30 = V_32 / ( V_20 * V_25 ) ;
return V_24 ;
}
static void F_14 ( T_1 V_7 , struct V_14 * V_15 )
{
V_15 -> V_19 [ V_7 ] . V_33 = F_15 () ;
}
static void F_16 ( struct V_14 * V_15 )
{
F_14 ( V_15 -> V_7 , V_15 ) ;
V_15 -> V_7 ^= 1 ;
V_15 -> V_34 = false ;
}
static bool F_17 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
if ( V_15 -> V_35 == 0 || V_15 -> V_36 == 0 )
return true ;
if ( V_15 -> V_37 < 1 ) {
unsigned long V_38 = F_18 ( 10UL * V_39 , V_40 - V_15 -> V_41 ) ;
V_15 -> V_37 = ( V_38 * V_15 -> V_35 ) / V_39 ;
if ( V_15 -> V_37 > V_15 -> V_36 )
V_15 -> V_37 = V_15 -> V_36 ;
V_15 -> V_41 = V_40 ;
if ( V_15 -> V_37 < 1 )
return true ;
}
V_15 -> V_37 -- ;
return false ;
}
static bool F_19 ( struct V_2 * V_3 , struct V_14 * V_15 ,
int * V_42 , T_1 * V_43 )
{
struct V_44 V_11 ;
int V_45 ;
V_45 = F_20 ( V_3 , V_15 -> V_46 , & V_11 ) ;
if ( V_45 >= 0 ) {
#ifdef F_21
switch ( V_45 ) {
case V_47 :
case V_48 :
* V_42 = V_49 | V_50 ;
case V_51 :
return false ;
}
#endif
* V_43 = F_22 ( V_11 . V_52 ) ;
return true ;
}
return false ;
}
static int F_23 ( struct V_2 * V_3 , struct V_53 * V_54 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
struct V_53 * V_55 = V_15 -> V_56 ;
int V_16 ;
T_1 V_57 = ~ 0 ;
T_1 V_58 = ~ 0 ;
T_1 V_59 , V_7 , V_43 , V_13 ;
int V_60 = V_49 | V_61 ;
if ( F_25 ( V_54 -> V_15 . V_24 >= V_15 -> V_62 ) ) {
V_54 -> V_63 . V_64 ++ ;
V_15 -> V_65 . V_66 ++ ;
goto V_67;
}
if ( V_15 -> V_68 > 0 ) {
unsigned long V_62 = V_15 -> V_69 + V_15 -> V_68 ;
if ( F_25 ( F_26 ( V_40 , V_62 ) ) ) {
F_16 ( V_15 ) ;
V_15 -> V_69 = V_40 ;
} else if ( F_25 ( ! V_15 -> V_34 && V_15 -> V_70 > 0 &&
F_26 ( V_40 , V_62 - V_15 -> V_70 ) ) ) {
V_15 -> V_34 = true ;
}
}
if ( V_15 -> V_46 ) {
if ( ! F_19 ( V_3 , V_15 , & V_60 , & V_43 ) )
goto V_71;
} else {
V_43 = F_27 ( V_3 ) ;
}
V_7 = V_15 -> V_7 ;
V_13 = F_28 ( V_43 , V_15 -> V_19 [ V_7 ] . V_33 ) ;
if ( ! V_13 )
V_13 = 1 ;
V_1 ( V_3 ) -> V_8 [ V_7 ] = V_13 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
T_1 V_21 = V_13 & V_22 ;
struct V_17 * V_18 = & V_15 -> V_19 [ V_7 ] . V_19 [ V_16 ] [ V_21 ] ;
V_13 >>= V_23 ;
if ( V_18 -> V_24 == 0 )
F_10 ( V_18 , V_15 ) ;
else if ( V_18 -> V_24 >= V_15 -> V_72 )
F_11 ( V_18 , V_15 ) ;
if ( V_58 > V_18 -> V_24 )
V_58 = V_18 -> V_24 ;
if ( V_57 > V_18 -> V_26 )
V_57 = V_18 -> V_26 ;
}
V_7 ^= 1 ;
V_1 ( V_3 ) -> V_8 [ V_7 ] = 0 ;
if ( F_25 ( V_58 >= V_15 -> V_73 ) ) {
V_54 -> V_63 . V_64 ++ ;
V_15 -> V_65 . V_74 ++ ;
goto V_67;
}
if ( F_25 ( V_57 >= V_12 ) ) {
if ( V_15 -> V_34 ) {
V_13 = F_28 ( V_43 , V_15 -> V_19 [ V_7 ] . V_33 ) ;
if ( ! V_13 )
V_13 = 1 ;
V_1 ( V_3 ) -> V_8 [ V_7 ] = V_13 ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
T_1 V_21 = V_13 & V_22 ;
struct V_17 * V_18 = & V_15 -> V_19 [ V_7 ] . V_19 [ V_16 ] [ V_21 ] ;
V_13 >>= V_23 ;
if ( V_18 -> V_24 == 0 )
F_10 ( V_18 , V_15 ) ;
else if ( V_18 -> V_24 >= V_15 -> V_72 )
F_11 ( V_18 , V_15 ) ;
}
}
if ( F_17 ( V_3 , V_15 ) ) {
V_54 -> V_63 . V_64 ++ ;
V_15 -> V_65 . V_75 ++ ;
goto V_67;
}
goto V_76;
}
V_59 = F_15 () & V_12 ;
if ( F_25 ( V_59 < V_57 ) ) {
if ( F_25 ( V_57 > V_12 / 2 ) ) {
if ( V_59 < ( V_57 - V_12 / 2 ) * 2 ) {
V_15 -> V_65 . V_77 ++ ;
goto V_67;
}
}
if ( F_29 ( V_3 ) ) {
V_15 -> V_65 . V_78 ++ ;
} else {
V_15 -> V_65 . V_77 ++ ;
goto V_67;
}
}
V_76:
V_60 = F_30 ( V_3 , V_55 ) ;
if ( F_31 ( V_60 == V_49 ) ) {
V_54 -> V_15 . V_24 ++ ;
F_7 ( V_3 , V_15 ) ;
} else if ( F_32 ( V_60 ) ) {
V_15 -> V_65 . V_79 ++ ;
V_54 -> V_63 . V_80 ++ ;
}
return V_60 ;
V_67:
F_33 ( V_3 , V_54 ) ;
return V_81 ;
V_71:
if ( V_60 & V_61 )
V_54 -> V_63 . V_80 ++ ;
F_34 ( V_3 ) ;
return V_60 ;
}
static struct V_2 * F_35 ( struct V_53 * V_54 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
struct V_53 * V_55 = V_15 -> V_56 ;
struct V_2 * V_3 ;
V_3 = V_55 -> V_82 ( V_15 -> V_56 ) ;
if ( V_3 ) {
F_36 ( V_54 , V_3 ) ;
V_54 -> V_15 . V_24 -- ;
F_9 ( V_3 , V_15 ) ;
}
return V_3 ;
}
static struct V_2 * F_37 ( struct V_53 * V_54 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
struct V_53 * V_55 = V_15 -> V_56 ;
return V_55 -> V_83 -> V_84 ( V_55 ) ;
}
static void F_38 ( struct V_53 * V_54 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
F_39 ( V_15 -> V_56 ) ;
V_54 -> V_15 . V_24 = 0 ;
V_15 -> V_7 = 0 ;
V_15 -> V_34 = false ;
F_12 ( V_15 ) ;
F_14 ( 0 , V_15 ) ;
}
static void F_40 ( struct V_53 * V_54 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
F_41 ( & V_15 -> V_46 ) ;
F_42 ( V_15 -> V_56 ) ;
}
static int F_43 ( struct V_53 * V_54 , struct V_85 * V_86 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
struct V_53 * V_55 ;
struct V_85 * V_87 [ V_88 + 1 ] ;
const struct V_89 * V_90 = & V_91 ;
T_1 V_62 ;
int V_92 ;
if ( V_86 ) {
V_92 = F_44 ( V_87 , V_88 , V_86 , V_93 ) ;
if ( V_92 < 0 )
return - V_94 ;
if ( V_87 [ V_95 ] == NULL )
return - V_94 ;
V_90 = F_45 ( V_87 [ V_95 ] ) ;
}
V_62 = V_90 -> V_62 ;
if ( V_62 == 0 )
V_62 = F_46 ( T_1 , F_47 ( V_54 ) -> V_96 , 1 ) ;
V_55 = F_48 ( V_54 , & V_97 , V_62 ) ;
if ( F_49 ( V_55 ) )
return F_50 ( V_55 ) ;
F_51 ( V_54 ) ;
F_52 ( V_15 -> V_56 , V_15 -> V_56 -> V_15 . V_24 ) ;
F_42 ( V_15 -> V_56 ) ;
V_15 -> V_56 = V_55 ;
V_15 -> V_68 = F_53 ( V_90 -> V_68 ) ;
V_15 -> V_70 = F_53 ( V_90 -> V_70 ) ;
V_15 -> V_69 = V_40 ;
V_15 -> V_62 = V_62 ;
V_15 -> V_28 = V_90 -> V_28 ;
V_15 -> V_27 = V_90 -> V_27 ;
V_15 -> V_73 = V_90 -> V_73 ;
V_15 -> V_72 = V_90 -> V_72 ;
V_15 -> V_35 = V_90 -> V_35 ;
V_15 -> V_36 = V_90 -> V_36 ;
V_15 -> V_37 = V_90 -> V_36 ;
V_15 -> V_41 = V_40 ;
V_15 -> V_7 = 0 ;
V_15 -> V_34 = false ;
F_12 ( V_15 ) ;
F_14 ( 0 , V_15 ) ;
F_14 ( 1 , V_15 ) ;
F_54 ( V_54 ) ;
return 0 ;
}
static int F_55 ( struct V_53 * V_54 , struct V_85 * V_86 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
V_15 -> V_56 = & V_98 ;
return F_43 ( V_54 , V_86 ) ;
}
static int F_56 ( struct V_53 * V_54 , struct V_2 * V_3 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
struct V_85 * V_99 ;
struct V_89 V_86 = {
. V_68 = F_57 ( V_15 -> V_68 ) ,
. V_70 = F_57 ( V_15 -> V_70 ) ,
. V_62 = V_15 -> V_62 ,
. V_73 = V_15 -> V_73 ,
. V_72 = V_15 -> V_72 ,
. V_28 = V_15 -> V_28 ,
. V_27 = V_15 -> V_27 ,
. V_35 = V_15 -> V_35 ,
. V_36 = V_15 -> V_36 ,
} ;
V_54 -> V_63 . V_100 = V_15 -> V_56 -> V_63 . V_100 ;
V_99 = F_58 ( V_3 , V_101 ) ;
F_59 ( V_3 , V_95 , sizeof( V_86 ) , & V_86 ) ;
return F_60 ( V_3 , V_99 ) ;
V_102:
F_61 ( V_3 , V_99 ) ;
return - V_103 ;
}
static int F_62 ( struct V_53 * V_54 , struct V_104 * V_105 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
struct V_106 V_107 = {
. V_77 = V_15 -> V_65 . V_77 ,
. V_75 = V_15 -> V_65 . V_75 ,
. V_74 = V_15 -> V_65 . V_74 ,
. V_66 = V_15 -> V_65 . V_66 ,
. V_79 = V_15 -> V_65 . V_79 ,
. V_78 = V_15 -> V_65 . V_78 ,
} ;
V_107 . V_108 = F_13 ( & V_107 . V_109 , & V_107 . V_110 , V_15 ) ;
return F_63 ( V_105 , & V_107 , sizeof( V_107 ) ) ;
}
static int F_64 ( struct V_53 * V_54 , unsigned long V_111 ,
struct V_2 * V_3 , struct V_112 * V_113 )
{
return - V_114 ;
}
static int F_65 ( struct V_53 * V_54 , unsigned long V_115 , struct V_53 * V_116 ,
struct V_53 * * V_117 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
if ( V_116 == NULL )
V_116 = & V_98 ;
F_51 ( V_54 ) ;
* V_117 = V_15 -> V_56 ;
V_15 -> V_56 = V_116 ;
F_52 ( * V_117 , ( * V_117 ) -> V_15 . V_24 ) ;
F_39 ( * V_117 ) ;
F_54 ( V_54 ) ;
return 0 ;
}
static struct V_53 * F_66 ( struct V_53 * V_54 , unsigned long V_115 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
return V_15 -> V_56 ;
}
static unsigned long F_67 ( struct V_53 * V_54 , T_1 V_52 )
{
return 1 ;
}
static void F_68 ( struct V_53 * V_54 , unsigned long V_115 )
{
}
static int F_69 ( struct V_53 * V_54 , T_1 V_52 , T_1 V_118 ,
struct V_85 * * V_119 , unsigned long * V_115 )
{
return - V_114 ;
}
static int F_70 ( struct V_53 * V_54 , unsigned long V_111 )
{
return - V_114 ;
}
static void F_71 ( struct V_53 * V_54 , struct V_120 * V_121 )
{
if ( ! V_121 -> V_122 ) {
if ( V_121 -> V_123 >= V_121 -> V_124 )
if ( V_121 -> V_125 ( V_54 , 1 , V_121 ) < 0 ) {
V_121 -> V_122 = 1 ;
return;
}
V_121 -> V_123 ++ ;
}
}
static struct V_126 * * F_72 ( struct V_53 * V_54 , unsigned long V_111 )
{
struct V_14 * V_15 = F_24 ( V_54 ) ;
if ( V_111 )
return NULL ;
return & V_15 -> V_46 ;
}
static unsigned long F_73 ( struct V_53 * V_54 , unsigned long V_127 ,
T_1 V_52 )
{
return 0 ;
}
static int T_2 F_74 ( void )
{
return F_75 ( & V_128 ) ;
}
static void T_3 F_76 ( void )
{
F_77 ( & V_128 ) ;
}
