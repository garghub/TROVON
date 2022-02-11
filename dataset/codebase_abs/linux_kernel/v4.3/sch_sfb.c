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
static int F_24 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 = V_13 -> V_55 ;
struct V_40 * V_41 ;
int V_14 ;
T_1 V_56 = ~ 0 ;
T_1 V_57 = ~ 0 ;
T_1 V_58 , V_11 ;
T_1 V_5 = V_13 -> V_5 ;
int V_59 = V_48 | V_60 ;
if ( F_26 ( V_53 -> V_13 . V_22 >= V_13 -> V_61 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_62 . V_63 ++ ;
goto V_64;
}
if ( V_13 -> V_65 > 0 ) {
unsigned long V_61 = V_13 -> V_66 + V_13 -> V_65 ;
if ( F_26 ( F_28 ( V_38 , V_61 ) ) ) {
F_17 ( V_13 ) ;
V_13 -> V_66 = V_38 ;
} else if ( F_26 ( ! V_13 -> V_32 && V_13 -> V_67 > 0 &&
F_28 ( V_38 , V_61 - V_13 -> V_67 ) ) ) {
V_13 -> V_32 = true ;
}
}
V_41 = F_29 ( V_13 -> V_68 ) ;
if ( V_41 ) {
T_1 V_43 ;
if ( ! F_20 ( V_3 , V_41 , & V_59 , & V_43 ) )
goto V_69;
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
else if ( V_16 -> V_22 >= V_13 -> V_70 )
F_12 ( V_16 , V_13 ) ;
if ( V_57 > V_16 -> V_22 )
V_57 = V_16 -> V_22 ;
if ( V_56 > V_16 -> V_24 )
V_56 = V_16 -> V_24 ;
}
V_5 ^= 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = 0 ;
if ( F_26 ( V_57 >= V_13 -> V_71 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_62 . V_72 ++ ;
goto V_64;
}
if ( F_26 ( V_56 >= V_10 ) ) {
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
else if ( V_16 -> V_22 >= V_13 -> V_70 )
F_12 ( V_16 , V_13 ) ;
}
}
if ( F_18 ( V_3 , V_13 ) ) {
F_27 ( V_53 ) ;
V_13 -> V_62 . V_73 ++ ;
goto V_64;
}
goto V_74;
}
V_58 = F_16 () & V_10 ;
if ( F_26 ( V_58 < V_56 ) ) {
if ( F_26 ( V_56 > V_10 / 2 ) ) {
if ( V_58 < ( V_56 - V_10 / 2 ) * 2 ) {
V_13 -> V_62 . V_75 ++ ;
goto V_64;
}
}
if ( F_32 ( V_3 ) ) {
V_13 -> V_62 . V_76 ++ ;
} else {
V_13 -> V_62 . V_75 ++ ;
goto V_64;
}
}
V_74:
V_59 = F_33 ( V_3 , V_54 ) ;
if ( F_34 ( V_59 == V_48 ) ) {
V_53 -> V_13 . V_22 ++ ;
F_8 ( V_3 , V_13 ) ;
} else if ( F_35 ( V_59 ) ) {
V_13 -> V_62 . V_77 ++ ;
F_36 ( V_53 ) ;
}
return V_59 ;
V_64:
F_37 ( V_3 , V_53 ) ;
return V_78 ;
V_69:
if ( V_59 & V_60 )
F_36 ( V_53 ) ;
F_38 ( V_3 ) ;
return V_59 ;
}
static struct V_2 * F_39 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 = V_13 -> V_55 ;
struct V_2 * V_3 ;
V_3 = V_54 -> V_79 ( V_13 -> V_55 ) ;
if ( V_3 ) {
F_40 ( V_53 , V_3 ) ;
V_53 -> V_13 . V_22 -- ;
F_10 ( V_3 , V_13 ) ;
}
return V_3 ;
}
static struct V_2 * F_41 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 = V_13 -> V_55 ;
return V_54 -> V_80 -> V_81 ( V_54 ) ;
}
static void F_42 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
F_43 ( V_13 -> V_55 ) ;
V_53 -> V_13 . V_22 = 0 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
}
static void F_44 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
F_45 ( & V_13 -> V_68 ) ;
F_46 ( V_13 -> V_55 ) ;
}
static int F_47 ( struct V_52 * V_53 , struct V_82 * V_83 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_52 * V_54 ;
struct V_82 * V_84 [ V_85 + 1 ] ;
const struct V_86 * V_87 = & V_88 ;
T_1 V_61 ;
int V_89 ;
if ( V_83 ) {
V_89 = F_48 ( V_84 , V_85 , V_83 , V_90 ) ;
if ( V_89 < 0 )
return - V_91 ;
if ( V_84 [ V_92 ] == NULL )
return - V_91 ;
V_87 = F_49 ( V_84 [ V_92 ] ) ;
}
V_61 = V_87 -> V_61 ;
if ( V_61 == 0 )
V_61 = F_50 ( V_53 ) -> V_93 ;
V_54 = F_51 ( V_53 , & V_94 , V_61 ) ;
if ( F_52 ( V_54 ) )
return F_53 ( V_54 ) ;
F_54 ( V_53 ) ;
F_55 ( V_13 -> V_55 , V_13 -> V_55 -> V_13 . V_22 ) ;
F_46 ( V_13 -> V_55 ) ;
V_13 -> V_55 = V_54 ;
V_13 -> V_65 = F_56 ( V_87 -> V_65 ) ;
V_13 -> V_67 = F_56 ( V_87 -> V_67 ) ;
V_13 -> V_66 = V_38 ;
V_13 -> V_61 = V_61 ;
V_13 -> V_26 = V_87 -> V_26 ;
V_13 -> V_25 = V_87 -> V_25 ;
V_13 -> V_71 = V_87 -> V_71 ;
V_13 -> V_70 = V_87 -> V_70 ;
V_13 -> V_33 = V_87 -> V_33 ;
V_13 -> V_34 = V_87 -> V_34 ;
V_13 -> V_35 = V_87 -> V_34 ;
V_13 -> V_39 = V_38 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
F_15 ( 1 , V_13 ) ;
F_57 ( V_53 ) ;
return 0 ;
}
static int F_58 ( struct V_52 * V_53 , struct V_82 * V_83 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
V_13 -> V_55 = & V_95 ;
return F_47 ( V_53 , V_83 ) ;
}
static int F_59 ( struct V_52 * V_53 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_82 * V_96 ;
struct V_86 V_83 = {
. V_65 = F_60 ( V_13 -> V_65 ) ,
. V_67 = F_60 ( V_13 -> V_67 ) ,
. V_61 = V_13 -> V_61 ,
. V_71 = V_13 -> V_71 ,
. V_70 = V_13 -> V_70 ,
. V_26 = V_13 -> V_26 ,
. V_25 = V_13 -> V_25 ,
. V_33 = V_13 -> V_33 ,
. V_34 = V_13 -> V_34 ,
} ;
V_53 -> V_97 . V_98 = V_13 -> V_55 -> V_97 . V_98 ;
V_96 = F_61 ( V_3 , V_99 ) ;
if ( V_96 == NULL )
goto V_100;
if ( F_62 ( V_3 , V_92 , sizeof( V_83 ) , & V_83 ) )
goto V_100;
return F_63 ( V_3 , V_96 ) ;
V_100:
F_64 ( V_3 , V_96 ) ;
return - V_101 ;
}
static int F_65 ( struct V_52 * V_53 , struct V_102 * V_103 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
struct V_104 V_105 = {
. V_75 = V_13 -> V_62 . V_75 ,
. V_73 = V_13 -> V_62 . V_73 ,
. V_72 = V_13 -> V_62 . V_72 ,
. V_63 = V_13 -> V_62 . V_63 ,
. V_77 = V_13 -> V_62 . V_77 ,
. V_76 = V_13 -> V_62 . V_76 ,
} ;
V_105 . V_106 = F_14 ( & V_105 . V_107 , & V_105 . V_108 , V_13 ) ;
return F_66 ( V_103 , & V_105 , sizeof( V_105 ) ) ;
}
static int F_67 ( struct V_52 * V_53 , unsigned long V_109 ,
struct V_2 * V_3 , struct V_110 * V_111 )
{
return - V_112 ;
}
static int F_68 ( struct V_52 * V_53 , unsigned long V_113 , struct V_52 * V_114 ,
struct V_52 * * V_115 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
if ( V_114 == NULL )
V_114 = & V_95 ;
F_54 ( V_53 ) ;
* V_115 = V_13 -> V_55 ;
V_13 -> V_55 = V_114 ;
F_55 ( * V_115 , ( * V_115 ) -> V_13 . V_22 ) ;
F_43 ( * V_115 ) ;
F_57 ( V_53 ) ;
return 0 ;
}
static struct V_52 * F_69 ( struct V_52 * V_53 , unsigned long V_113 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
return V_13 -> V_55 ;
}
static unsigned long F_70 ( struct V_52 * V_53 , T_1 V_51 )
{
return 1 ;
}
static void F_71 ( struct V_52 * V_53 , unsigned long V_113 )
{
}
static int F_72 ( struct V_52 * V_53 , T_1 V_51 , T_1 V_116 ,
struct V_82 * * V_117 , unsigned long * V_113 )
{
return - V_112 ;
}
static int F_73 ( struct V_52 * V_53 , unsigned long V_109 )
{
return - V_112 ;
}
static void F_74 ( struct V_52 * V_53 , struct V_118 * V_119 )
{
if ( ! V_119 -> V_120 ) {
if ( V_119 -> V_121 >= V_119 -> V_122 )
if ( V_119 -> V_123 ( V_53 , 1 , V_119 ) < 0 ) {
V_119 -> V_120 = 1 ;
return;
}
V_119 -> V_121 ++ ;
}
}
static struct V_40 T_2 * * F_75 ( struct V_52 * V_53 ,
unsigned long V_109 )
{
struct V_12 * V_13 = F_25 ( V_53 ) ;
if ( V_109 )
return NULL ;
return & V_13 -> V_68 ;
}
static unsigned long F_76 ( struct V_52 * V_53 , unsigned long V_124 ,
T_1 V_51 )
{
return 0 ;
}
static int T_3 F_77 ( void )
{
return F_78 ( & V_125 ) ;
}
static void T_4 F_79 ( void )
{
F_80 ( & V_125 ) ;
}
