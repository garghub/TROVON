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
case V_48 :
* V_42 = V_49 | V_50 ;
case V_51 :
return false ;
}
#endif
* V_43 = F_23 ( V_9 . V_52 ) ;
return true ;
}
return false ;
}
static int F_24 ( struct V_2 * V_3 , struct V_53 * V_54 ,
struct V_2 * * V_55 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
struct V_53 * V_56 = V_13 -> V_57 ;
struct V_40 * V_41 ;
int V_14 ;
T_1 V_58 = ~ 0 ;
T_1 V_59 = ~ 0 ;
T_1 V_60 , V_11 ;
T_1 V_5 = V_13 -> V_5 ;
int V_61 = V_49 | V_62 ;
if ( F_26 ( V_54 -> V_13 . V_22 >= V_13 -> V_63 ) ) {
F_27 ( V_54 ) ;
V_13 -> V_64 . V_65 ++ ;
goto V_66;
}
if ( V_13 -> V_67 > 0 ) {
unsigned long V_63 = V_13 -> V_68 + V_13 -> V_67 ;
if ( F_26 ( F_28 ( V_38 , V_63 ) ) ) {
F_17 ( V_13 ) ;
V_13 -> V_68 = V_38 ;
} else if ( F_26 ( ! V_13 -> V_32 && V_13 -> V_69 > 0 &&
F_28 ( V_38 , V_63 - V_13 -> V_69 ) ) ) {
V_13 -> V_32 = true ;
}
}
V_41 = F_29 ( V_13 -> V_70 ) ;
if ( V_41 ) {
T_1 V_43 ;
if ( ! F_20 ( V_3 , V_41 , & V_61 , & V_43 ) )
goto V_71;
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
else if ( V_16 -> V_22 >= V_13 -> V_72 )
F_12 ( V_16 , V_13 ) ;
if ( V_59 > V_16 -> V_22 )
V_59 = V_16 -> V_22 ;
if ( V_58 > V_16 -> V_24 )
V_58 = V_16 -> V_24 ;
}
V_5 ^= 1 ;
V_1 ( V_3 ) -> V_6 [ V_5 ] = 0 ;
if ( F_26 ( V_59 >= V_13 -> V_73 ) ) {
F_27 ( V_54 ) ;
V_13 -> V_64 . V_74 ++ ;
goto V_66;
}
if ( F_26 ( V_58 >= V_10 ) ) {
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
else if ( V_16 -> V_22 >= V_13 -> V_72 )
F_12 ( V_16 , V_13 ) ;
}
}
if ( F_18 ( V_3 , V_13 ) ) {
F_27 ( V_54 ) ;
V_13 -> V_64 . V_75 ++ ;
goto V_66;
}
goto V_76;
}
V_60 = F_16 () & V_10 ;
if ( F_26 ( V_60 < V_58 ) ) {
if ( F_26 ( V_58 > V_10 / 2 ) ) {
if ( V_60 < ( V_58 - V_10 / 2 ) * 2 ) {
V_13 -> V_64 . V_77 ++ ;
goto V_66;
}
}
if ( F_32 ( V_3 ) ) {
V_13 -> V_64 . V_78 ++ ;
} else {
V_13 -> V_64 . V_77 ++ ;
goto V_66;
}
}
V_76:
V_61 = F_33 ( V_3 , V_56 , V_55 ) ;
if ( F_34 ( V_61 == V_49 ) ) {
F_35 ( V_54 , V_3 ) ;
V_54 -> V_13 . V_22 ++ ;
F_8 ( V_3 , V_13 ) ;
} else if ( F_36 ( V_61 ) ) {
V_13 -> V_64 . V_79 ++ ;
F_37 ( V_54 ) ;
}
return V_61 ;
V_66:
F_38 ( V_3 , V_54 , V_55 ) ;
return V_80 ;
V_71:
if ( V_61 & V_62 )
F_37 ( V_54 ) ;
F_39 ( V_3 ) ;
return V_61 ;
}
static struct V_2 * F_40 ( struct V_53 * V_54 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
struct V_53 * V_56 = V_13 -> V_57 ;
struct V_2 * V_3 ;
V_3 = V_56 -> V_81 ( V_13 -> V_57 ) ;
if ( V_3 ) {
F_41 ( V_54 , V_3 ) ;
F_42 ( V_54 , V_3 ) ;
V_54 -> V_13 . V_22 -- ;
F_10 ( V_3 , V_13 ) ;
}
return V_3 ;
}
static struct V_2 * F_43 ( struct V_53 * V_54 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
struct V_53 * V_56 = V_13 -> V_57 ;
return V_56 -> V_82 -> V_83 ( V_56 ) ;
}
static void F_44 ( struct V_53 * V_54 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
F_45 ( V_13 -> V_57 ) ;
V_54 -> V_84 . V_85 = 0 ;
V_54 -> V_13 . V_22 = 0 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
}
static void F_46 ( struct V_53 * V_54 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
F_47 ( V_13 -> V_86 ) ;
F_48 ( V_13 -> V_57 ) ;
}
static int F_49 ( struct V_53 * V_54 , struct V_87 * V_88 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
struct V_53 * V_56 ;
struct V_87 * V_89 [ V_90 + 1 ] ;
const struct V_91 * V_92 = & V_93 ;
T_1 V_63 ;
int V_94 ;
if ( V_88 ) {
V_94 = F_50 ( V_89 , V_90 , V_88 , V_95 , NULL ) ;
if ( V_94 < 0 )
return - V_96 ;
if ( V_89 [ V_97 ] == NULL )
return - V_96 ;
V_92 = F_51 ( V_89 [ V_97 ] ) ;
}
V_63 = V_92 -> V_63 ;
if ( V_63 == 0 )
V_63 = F_52 ( V_54 ) -> V_98 ;
V_56 = F_53 ( V_54 , & V_99 , V_63 ) ;
if ( F_54 ( V_56 ) )
return F_55 ( V_56 ) ;
if ( V_56 != & V_100 )
F_56 ( V_56 , true ) ;
F_57 ( V_54 ) ;
F_58 ( V_13 -> V_57 , V_13 -> V_57 -> V_13 . V_22 ,
V_13 -> V_57 -> V_84 . V_85 ) ;
F_48 ( V_13 -> V_57 ) ;
V_13 -> V_57 = V_56 ;
V_13 -> V_67 = F_59 ( V_92 -> V_67 ) ;
V_13 -> V_69 = F_59 ( V_92 -> V_69 ) ;
V_13 -> V_68 = V_38 ;
V_13 -> V_63 = V_63 ;
V_13 -> V_26 = V_92 -> V_26 ;
V_13 -> V_25 = V_92 -> V_25 ;
V_13 -> V_73 = V_92 -> V_73 ;
V_13 -> V_72 = V_92 -> V_72 ;
V_13 -> V_33 = V_92 -> V_33 ;
V_13 -> V_34 = V_92 -> V_34 ;
V_13 -> V_35 = V_92 -> V_34 ;
V_13 -> V_39 = V_38 ;
V_13 -> V_5 = 0 ;
V_13 -> V_32 = false ;
F_13 ( V_13 ) ;
F_15 ( 0 , V_13 ) ;
F_15 ( 1 , V_13 ) ;
F_60 ( V_54 ) ;
return 0 ;
}
static int F_61 ( struct V_53 * V_54 , struct V_87 * V_88 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
int V_94 ;
V_94 = F_62 ( & V_13 -> V_86 , & V_13 -> V_70 ) ;
if ( V_94 )
return V_94 ;
V_13 -> V_57 = & V_100 ;
return F_49 ( V_54 , V_88 ) ;
}
static int F_63 ( struct V_53 * V_54 , struct V_2 * V_3 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
struct V_87 * V_101 ;
struct V_91 V_88 = {
. V_67 = F_64 ( V_13 -> V_67 ) ,
. V_69 = F_64 ( V_13 -> V_69 ) ,
. V_63 = V_13 -> V_63 ,
. V_73 = V_13 -> V_73 ,
. V_72 = V_13 -> V_72 ,
. V_26 = V_13 -> V_26 ,
. V_25 = V_13 -> V_25 ,
. V_33 = V_13 -> V_33 ,
. V_34 = V_13 -> V_34 ,
} ;
V_54 -> V_84 . V_85 = V_13 -> V_57 -> V_84 . V_85 ;
V_101 = F_65 ( V_3 , V_102 ) ;
if ( V_101 == NULL )
goto V_103;
if ( F_66 ( V_3 , V_97 , sizeof( V_88 ) , & V_88 ) )
goto V_103;
return F_67 ( V_3 , V_101 ) ;
V_103:
F_68 ( V_3 , V_101 ) ;
return - V_104 ;
}
static int F_69 ( struct V_53 * V_54 , struct V_105 * V_106 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
struct V_107 V_108 = {
. V_77 = V_13 -> V_64 . V_77 ,
. V_75 = V_13 -> V_64 . V_75 ,
. V_74 = V_13 -> V_64 . V_74 ,
. V_65 = V_13 -> V_64 . V_65 ,
. V_79 = V_13 -> V_64 . V_79 ,
. V_78 = V_13 -> V_64 . V_78 ,
} ;
V_108 . V_109 = F_14 ( & V_108 . V_110 , & V_108 . V_111 , V_13 ) ;
return F_70 ( V_106 , & V_108 , sizeof( V_108 ) ) ;
}
static int F_71 ( struct V_53 * V_54 , unsigned long V_112 ,
struct V_2 * V_3 , struct V_113 * V_114 )
{
return - V_115 ;
}
static int F_72 ( struct V_53 * V_54 , unsigned long V_116 , struct V_53 * V_117 ,
struct V_53 * * V_118 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
if ( V_117 == NULL )
V_117 = & V_100 ;
* V_118 = F_73 ( V_54 , V_117 , & V_13 -> V_57 ) ;
return 0 ;
}
static struct V_53 * F_74 ( struct V_53 * V_54 , unsigned long V_116 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
return V_13 -> V_57 ;
}
static unsigned long F_75 ( struct V_53 * V_54 , T_1 V_52 )
{
return 1 ;
}
static void F_76 ( struct V_53 * V_54 , unsigned long V_116 )
{
}
static int F_77 ( struct V_53 * V_54 , T_1 V_52 , T_1 V_119 ,
struct V_87 * * V_120 , unsigned long * V_116 )
{
return - V_115 ;
}
static int F_78 ( struct V_53 * V_54 , unsigned long V_112 )
{
return - V_115 ;
}
static void F_79 ( struct V_53 * V_54 , struct V_121 * V_122 )
{
if ( ! V_122 -> V_123 ) {
if ( V_122 -> V_124 >= V_122 -> V_125 )
if ( V_122 -> V_126 ( V_54 , 1 , V_122 ) < 0 ) {
V_122 -> V_123 = 1 ;
return;
}
V_122 -> V_124 ++ ;
}
}
static struct V_127 * F_80 ( struct V_53 * V_54 , unsigned long V_112 )
{
struct V_12 * V_13 = F_25 ( V_54 ) ;
if ( V_112 )
return NULL ;
return V_13 -> V_86 ;
}
static unsigned long F_81 ( struct V_53 * V_54 , unsigned long V_128 ,
T_1 V_52 )
{
return 0 ;
}
static int T_2 F_82 ( void )
{
return F_83 ( & V_129 ) ;
}
static void T_3 F_84 ( void )
{
F_85 ( & V_129 ) ;
}
