static inline struct V_1 * F_1 ( T_1 V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( & V_6 -> V_9 , V_2 ) ;
if ( V_8 == NULL )
return NULL ;
return F_4 ( V_8 , struct V_1 , V_10 ) ;
}
static unsigned long F_5 ( struct V_3 * V_4 , T_1 V_2 )
{
return ( unsigned long ) F_1 ( V_2 , V_4 ) ;
}
static struct V_1 * F_6 ( struct V_11 * V_12 , struct V_3 * V_4 ,
int * V_13 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
struct V_15 V_16 ;
struct V_17 * V_18 ;
int V_19 ;
if ( V_12 -> V_20 == V_4 -> V_2 )
return V_21 ;
V_14 = F_1 ( V_12 -> V_20 , V_4 ) ;
if ( V_14 ) {
if ( V_14 -> V_22 == 0 )
return V_14 ;
V_18 = F_7 ( V_14 -> V_23 ) ;
} else {
V_18 = F_7 ( V_6 -> V_23 ) ;
}
* V_13 = V_24 | V_25 ;
while ( V_18 && ( V_19 = F_8 ( V_12 , V_18 , & V_16 , false ) ) >= 0 ) {
#ifdef F_9
switch ( V_19 ) {
case V_26 :
case V_27 :
case V_28 :
* V_13 = V_24 | V_29 ;
case V_30 :
return NULL ;
}
#endif
V_14 = ( void * ) V_16 . V_31 ;
if ( ! V_14 ) {
if ( V_16 . V_32 == V_4 -> V_2 )
return V_21 ;
V_14 = F_1 ( V_16 . V_32 , V_4 ) ;
if ( ! V_14 )
break;
}
if ( ! V_14 -> V_22 )
return V_14 ;
V_18 = F_7 ( V_14 -> V_23 ) ;
}
V_14 = F_1 ( F_10 ( F_11 ( V_4 -> V_2 ) , V_6 -> V_33 ) , V_4 ) ;
if ( ! V_14 || V_14 -> V_22 )
return V_21 ;
return V_14 ;
}
static void F_12 ( struct V_34 * V_35 ,
struct V_1 * V_14 , int V_36 )
{
struct V_37 * * V_38 = & V_35 -> V_37 , * V_39 = NULL ;
while ( * V_38 ) {
struct V_1 * V_40 ;
V_39 = * V_38 ;
V_40 = F_13 ( V_39 , struct V_1 , V_41 [ V_36 ] ) ;
if ( V_14 -> V_10 . V_32 > V_40 -> V_10 . V_32 )
V_38 = & V_39 -> V_42 ;
else
V_38 = & V_39 -> V_43 ;
}
F_14 ( & V_14 -> V_41 [ V_36 ] , V_39 , V_38 ) ;
F_15 ( & V_14 -> V_41 [ V_36 ] , V_35 ) ;
}
static void F_16 ( struct V_5 * V_6 ,
struct V_1 * V_14 , T_2 V_44 )
{
struct V_37 * * V_38 = & V_6 -> V_45 [ V_14 -> V_22 ] . V_46 . V_37 , * V_39 = NULL ;
V_14 -> V_47 = V_6 -> V_48 + V_44 ;
if ( V_14 -> V_47 == V_6 -> V_48 )
V_14 -> V_47 ++ ;
if ( V_6 -> V_49 [ V_14 -> V_22 ] > V_14 -> V_47 )
V_6 -> V_49 [ V_14 -> V_22 ] = V_14 -> V_47 ;
while ( * V_38 ) {
struct V_1 * V_40 ;
V_39 = * V_38 ;
V_40 = F_13 ( V_39 , struct V_1 , V_50 ) ;
if ( V_14 -> V_47 >= V_40 -> V_47 )
V_38 = & V_39 -> V_42 ;
else
V_38 = & V_39 -> V_43 ;
}
F_14 ( & V_14 -> V_50 , V_39 , V_38 ) ;
F_15 ( & V_14 -> V_50 , & V_6 -> V_45 [ V_14 -> V_22 ] . V_46 ) ;
}
static inline void F_17 ( struct V_37 * * V_51 )
{
* V_51 = F_18 ( * V_51 ) ;
}
static inline void F_19 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_52 )
{
V_6 -> V_53 [ V_14 -> V_22 ] |= V_52 ;
while ( V_52 ) {
int V_36 = F_20 ( ~ V_52 ) ;
V_52 &= ~ ( 1 << V_36 ) ;
F_12 ( & V_6 -> V_45 [ V_14 -> V_22 ] . V_54 [ V_36 ] . V_55 , V_14 , V_36 ) ;
}
}
static void F_21 ( struct V_37 * V_56 , struct V_34 * V_35 )
{
if ( F_22 ( V_56 ) ) {
F_23 ( 1 ) ;
} else {
F_24 ( V_56 , V_35 ) ;
F_25 ( V_56 ) ;
}
}
static inline void F_26 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_52 )
{
int V_57 = 0 ;
struct V_58 * V_45 = & V_6 -> V_45 [ V_14 -> V_22 ] ;
while ( V_52 ) {
int V_36 = F_20 ( ~ V_52 ) ;
struct V_59 * V_54 = & V_45 -> V_54 [ V_36 ] ;
V_52 &= ~ ( 1 << V_36 ) ;
if ( V_54 -> V_60 == V_14 -> V_41 + V_36 )
F_17 ( & V_54 -> V_60 ) ;
F_21 ( V_14 -> V_41 + V_36 , & V_54 -> V_55 ) ;
if ( ! V_54 -> V_55 . V_37 )
V_57 |= 1 << V_36 ;
}
V_6 -> V_53 [ V_14 -> V_22 ] &= ~ V_57 ;
}
static void F_27 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_38 = V_14 -> V_39 ;
long V_57 , V_52 = V_14 -> V_61 ;
while ( V_14 -> V_62 == V_63 && V_38 && V_52 ) {
V_57 = V_52 ;
while ( V_57 ) {
int V_36 = F_20 ( ~ V_57 ) ;
V_57 &= ~ ( 1 << V_36 ) ;
if ( V_38 -> V_64 . V_65 . V_66 [ V_36 ] . V_67 . V_37 )
V_52 &= ~ ( 1 << V_36 ) ;
F_12 ( & V_38 -> V_64 . V_65 . V_66 [ V_36 ] . V_67 , V_14 , V_36 ) ;
}
V_38 -> V_61 |= V_52 ;
V_14 = V_38 ;
V_38 = V_14 -> V_39 ;
}
if ( V_14 -> V_62 == V_68 && V_52 )
F_19 ( V_6 , V_14 , V_52 ) ;
}
static void F_28 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_38 = V_14 -> V_39 ;
long V_57 , V_52 = V_14 -> V_61 ;
while ( V_14 -> V_62 == V_63 && V_38 && V_52 ) {
V_57 = V_52 ;
V_52 = 0 ;
while ( V_57 ) {
int V_36 = F_20 ( ~ V_57 ) ;
V_57 &= ~ ( 1 << V_36 ) ;
if ( V_38 -> V_64 . V_65 . V_66 [ V_36 ] . V_60 == V_14 -> V_41 + V_36 ) {
V_38 -> V_64 . V_65 . V_66 [ V_36 ] . V_69 = V_14 -> V_10 . V_32 ;
V_38 -> V_64 . V_65 . V_66 [ V_36 ] . V_60 = NULL ;
}
F_21 ( V_14 -> V_41 + V_36 ,
& V_38 -> V_64 . V_65 . V_66 [ V_36 ] . V_67 ) ;
if ( ! V_38 -> V_64 . V_65 . V_66 [ V_36 ] . V_67 . V_37 )
V_52 |= 1 << V_36 ;
}
V_38 -> V_61 &= ~ V_52 ;
V_14 = V_38 ;
V_38 = V_14 -> V_39 ;
}
if ( V_14 -> V_62 == V_68 && V_52 )
F_26 ( V_6 , V_14 , V_52 ) ;
}
static inline T_2 F_29 ( const struct V_1 * V_14 )
{
if ( V_70 )
return V_14 -> V_62 != V_71 ? - V_14 -> V_72 : 0 ;
else
return 0 ;
}
static inline T_2 F_30 ( const struct V_1 * V_14 )
{
if ( V_70 )
return V_14 -> V_62 == V_68 ? - V_14 -> V_73 : 0 ;
else
return 0 ;
}
static inline enum V_74
F_31 ( struct V_1 * V_14 , T_2 * V_75 )
{
T_2 V_76 ;
if ( ( V_76 = ( V_14 -> V_77 + * V_75 ) ) < F_29 ( V_14 ) ) {
* V_75 = - V_76 ;
return V_71 ;
}
if ( ( V_76 = ( V_14 -> V_78 + * V_75 ) ) >= F_30 ( V_14 ) )
return V_68 ;
* V_75 = - V_76 ;
return V_63 ;
}
static void
F_32 ( struct V_5 * V_6 , struct V_1 * V_14 , T_2 * V_75 )
{
enum V_74 V_79 = F_31 ( V_14 , V_75 ) ;
if ( V_79 == V_14 -> V_62 )
return;
if ( V_14 -> V_61 ) {
if ( V_14 -> V_62 != V_71 )
F_28 ( V_6 , V_14 ) ;
V_14 -> V_62 = V_79 ;
if ( V_79 != V_71 )
F_27 ( V_6 , V_14 ) ;
} else
V_14 -> V_62 = V_79 ;
}
static inline void F_33 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_23 ( V_14 -> V_22 || ! V_14 -> V_64 . V_80 . V_6 || ! V_14 -> V_64 . V_80 . V_6 -> V_6 . V_81 ) ;
if ( ! V_14 -> V_61 ) {
V_14 -> V_61 = 1 << V_14 -> V_36 ;
F_27 ( V_6 , V_14 ) ;
F_34 ( & V_14 -> V_64 . V_80 . V_82 ,
V_6 -> V_83 + V_14 -> V_36 ) ;
}
}
static inline void F_35 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_23 ( ! V_14 -> V_61 ) ;
F_28 ( V_6 , V_14 ) ;
V_14 -> V_61 = 0 ;
F_36 ( & V_14 -> V_64 . V_80 . V_82 ) ;
}
static void F_37 ( struct V_11 * V_12 , struct V_3 * V_4 ,
struct V_84 * V_85 )
{
struct V_11 * V_86 = V_85 -> V_87 ;
if ( V_86 ) {
V_12 -> V_88 = NULL ;
V_86 -> V_88 = V_12 ;
V_85 -> V_87 = V_12 ;
} else {
V_85 -> V_87 = V_12 ;
V_85 -> V_89 = V_12 ;
}
V_85 -> V_81 ++ ;
}
static int F_38 ( struct V_11 * V_12 , struct V_3 * V_4 ,
struct V_11 * * V_90 )
{
int V_91 ( V_92 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = F_6 ( V_12 , V_4 , & V_92 ) ;
if ( V_14 == V_21 ) {
if ( V_6 -> V_93 . V_81 < V_6 -> V_94 ) {
F_37 ( V_12 , V_4 , & V_6 -> V_93 ) ;
V_6 -> V_95 ++ ;
} else {
return F_39 ( V_12 , V_4 , V_90 ) ;
}
#ifdef F_9
} else if ( ! V_14 ) {
if ( V_92 & V_25 )
F_40 ( V_4 ) ;
F_41 ( V_12 , V_90 ) ;
return V_92 ;
#endif
} else if ( ( V_92 = F_42 ( V_12 , V_14 -> V_64 . V_80 . V_6 ,
V_90 ) ) != V_24 ) {
if ( F_43 ( V_92 ) ) {
F_40 ( V_4 ) ;
V_14 -> V_83 ++ ;
}
return V_92 ;
} else {
F_33 ( V_6 , V_14 ) ;
}
F_44 ( V_4 , V_12 ) ;
V_4 -> V_6 . V_81 ++ ;
return V_24 ;
}
static inline void F_45 ( struct V_1 * V_14 , int V_96 , T_2 V_75 )
{
T_2 V_76 = V_75 + V_14 -> V_78 ;
if ( V_76 > V_14 -> V_73 )
V_76 = V_14 -> V_73 ;
V_76 -= ( T_2 ) F_46 ( & V_14 -> V_97 , V_96 ) ;
if ( V_76 <= - V_14 -> V_98 )
V_76 = 1 - V_14 -> V_98 ;
V_14 -> V_78 = V_76 ;
}
static inline void F_47 ( struct V_1 * V_14 , int V_96 , T_2 V_75 )
{
T_2 V_76 = V_75 + V_14 -> V_77 ;
if ( V_76 > V_14 -> V_72 )
V_76 = V_14 -> V_72 ;
V_76 -= ( T_2 ) F_46 ( & V_14 -> ceil , V_96 ) ;
if ( V_76 <= - V_14 -> V_98 )
V_76 = 1 - V_14 -> V_98 ;
V_14 -> V_77 = V_76 ;
}
static void F_48 ( struct V_5 * V_6 , struct V_1 * V_14 ,
int V_22 , struct V_11 * V_12 )
{
int V_96 = F_49 ( V_12 ) ;
enum V_74 V_99 ;
T_2 V_75 ;
while ( V_14 ) {
V_75 = F_50 ( T_2 , V_6 -> V_48 - V_14 -> V_100 , V_14 -> V_98 ) ;
if ( V_14 -> V_22 >= V_22 ) {
if ( V_14 -> V_22 == V_22 )
V_14 -> V_101 . V_102 ++ ;
F_45 ( V_14 , V_96 , V_75 ) ;
} else {
V_14 -> V_101 . V_103 ++ ;
V_14 -> V_78 += V_75 ;
}
F_47 ( V_14 , V_96 , V_75 ) ;
V_14 -> V_100 = V_6 -> V_48 ;
V_99 = V_14 -> V_62 ;
V_75 = 0 ;
F_32 ( V_6 , V_14 , & V_75 ) ;
if ( V_99 != V_14 -> V_62 ) {
if ( V_99 != V_68 )
F_21 ( & V_14 -> V_50 , & V_6 -> V_45 [ V_14 -> V_22 ] . V_46 ) ;
if ( V_14 -> V_62 != V_68 )
F_16 ( V_6 , V_14 , V_75 ) ;
}
if ( V_14 -> V_22 )
F_51 ( & V_14 -> V_104 , V_12 ) ;
V_14 = V_14 -> V_39 ;
}
}
static T_2 F_52 ( struct V_5 * V_6 , const int V_22 ,
unsigned long V_105 )
{
unsigned long V_106 = V_105 + 2 ;
struct V_34 * V_46 = & V_6 -> V_45 [ V_22 ] . V_46 ;
while ( F_53 ( V_107 , V_106 ) ) {
struct V_1 * V_14 ;
T_2 V_75 ;
struct V_37 * V_38 = F_54 ( V_46 ) ;
if ( ! V_38 )
return 0 ;
V_14 = F_13 ( V_38 , struct V_1 , V_50 ) ;
if ( V_14 -> V_47 > V_6 -> V_48 )
return V_14 -> V_47 ;
F_21 ( V_38 , V_46 ) ;
V_75 = F_50 ( T_2 , V_6 -> V_48 - V_14 -> V_100 , V_14 -> V_98 ) ;
F_32 ( V_6 , V_14 , & V_75 ) ;
if ( V_14 -> V_62 != V_68 )
F_16 ( V_6 , V_14 , V_75 ) ;
}
if ( ! ( V_6 -> V_108 & V_109 ) ) {
F_55 ( L_1 ) ;
V_6 -> V_108 |= V_109 ;
}
return V_6 -> V_48 ;
}
static struct V_37 * F_56 ( int V_36 , struct V_37 * V_51 ,
T_1 V_110 )
{
struct V_37 * V_111 = NULL ;
while ( V_51 ) {
struct V_1 * V_14 =
F_13 ( V_51 , struct V_1 , V_41 [ V_36 ] ) ;
if ( V_110 > V_14 -> V_10 . V_32 ) {
V_51 = V_51 -> V_42 ;
} else if ( V_110 < V_14 -> V_10 . V_32 ) {
V_111 = V_51 ;
V_51 = V_51 -> V_43 ;
} else {
return V_51 ;
}
}
return V_111 ;
}
static struct V_1 * F_57 ( struct V_59 * V_54 , const int V_36 )
{
int V_112 ;
struct {
struct V_37 * V_35 ;
struct V_37 * * V_113 ;
T_1 * V_114 ;
} V_115 [ V_116 ] , * V_117 = V_115 ;
F_58 ( ! V_54 -> V_55 . V_37 ) ;
V_117 -> V_35 = V_54 -> V_55 . V_37 ;
V_117 -> V_113 = & V_54 -> V_60 ;
V_117 -> V_114 = & V_54 -> V_69 ;
for ( V_112 = 0 ; V_112 < 65535 ; V_112 ++ ) {
if ( ! * V_117 -> V_113 && * V_117 -> V_114 ) {
* V_117 -> V_113 =
F_56 ( V_36 , V_117 -> V_35 , * V_117 -> V_114 ) ;
}
* V_117 -> V_114 = 0 ;
if ( ! * V_117 -> V_113 ) {
* V_117 -> V_113 = V_117 -> V_35 ;
while ( ( * V_117 -> V_113 ) -> V_43 )
* V_117 -> V_113 = ( * V_117 -> V_113 ) -> V_43 ;
if ( V_117 > V_115 ) {
V_117 -- ;
if ( ! * V_117 -> V_113 ) {
F_23 ( 1 ) ;
return NULL ;
}
F_17 ( V_117 -> V_113 ) ;
}
} else {
struct V_1 * V_14 ;
struct V_59 * V_118 ;
V_14 = F_13 ( * V_117 -> V_113 , struct V_1 , V_41 [ V_36 ] ) ;
if ( ! V_14 -> V_22 )
return V_14 ;
V_118 = & V_14 -> V_64 . V_65 . V_66 [ V_36 ] ;
( ++ V_117 ) -> V_35 = V_118 -> V_67 . V_37 ;
V_117 -> V_113 = & V_118 -> V_60 ;
V_117 -> V_114 = & V_118 -> V_69 ;
}
}
F_23 ( 1 ) ;
return NULL ;
}
static struct V_11 * F_59 ( struct V_5 * V_6 , const int V_36 ,
const int V_22 )
{
struct V_11 * V_12 = NULL ;
struct V_1 * V_14 , * V_105 ;
struct V_58 * V_45 = & V_6 -> V_45 [ V_22 ] ;
struct V_59 * V_54 = & V_45 -> V_54 [ V_36 ] ;
V_105 = V_14 = F_57 ( V_54 , V_36 ) ;
do {
V_88:
if ( F_60 ( ! V_14 ) )
return NULL ;
if ( F_60 ( V_14 -> V_64 . V_80 . V_6 -> V_6 . V_81 == 0 ) ) {
struct V_1 * V_88 ;
F_35 ( V_6 , V_14 ) ;
if ( ( V_6 -> V_53 [ V_22 ] & ( 1 << V_36 ) ) == 0 )
return NULL ;
V_88 = F_57 ( V_54 , V_36 ) ;
if ( V_14 == V_105 )
V_105 = V_88 ;
V_14 = V_88 ;
goto V_88;
}
V_12 = V_14 -> V_64 . V_80 . V_6 -> V_119 ( V_14 -> V_64 . V_80 . V_6 ) ;
if ( F_61 ( V_12 != NULL ) )
break;
F_62 ( L_2 , V_14 -> V_64 . V_80 . V_6 ) ;
F_17 ( V_22 ? & V_14 -> V_39 -> V_64 . V_65 . V_66 [ V_36 ] . V_60 :
& V_6 -> V_45 [ 0 ] . V_54 [ V_36 ] . V_60 ) ;
V_14 = F_57 ( V_54 , V_36 ) ;
} while ( V_14 != V_105 );
if ( F_61 ( V_12 != NULL ) ) {
F_51 ( & V_14 -> V_104 , V_12 ) ;
V_14 -> V_64 . V_80 . V_120 [ V_22 ] -= F_49 ( V_12 ) ;
if ( V_14 -> V_64 . V_80 . V_120 [ V_22 ] < 0 ) {
V_14 -> V_64 . V_80 . V_120 [ V_22 ] += V_14 -> V_121 ;
F_17 ( V_22 ? & V_14 -> V_39 -> V_64 . V_65 . V_66 [ V_36 ] . V_60 :
& V_6 -> V_45 [ 0 ] . V_54 [ V_36 ] . V_60 ) ;
}
if ( ! V_14 -> V_64 . V_80 . V_6 -> V_6 . V_81 )
F_35 ( V_6 , V_14 ) ;
F_48 ( V_6 , V_14 , V_22 , V_12 ) ;
}
return V_12 ;
}
static struct V_11 * F_63 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_22 ;
T_2 V_122 ;
unsigned long V_123 ;
V_12 = F_64 ( & V_6 -> V_93 ) ;
if ( V_12 != NULL ) {
V_124:
F_65 ( V_4 , V_12 ) ;
F_66 ( V_4 , V_12 ) ;
V_4 -> V_6 . V_81 -- ;
return V_12 ;
}
if ( ! V_4 -> V_6 . V_81 )
goto V_125;
V_6 -> V_48 = F_67 () ;
V_123 = V_107 ;
V_122 = V_6 -> V_48 + 5LLU * V_126 ;
for ( V_22 = 0 ; V_22 < V_116 ; V_22 ++ ) {
int V_57 ;
T_2 V_127 = V_6 -> V_49 [ V_22 ] ;
if ( V_6 -> V_48 >= V_127 ) {
V_127 = F_52 ( V_6 , V_22 , V_123 ) ;
if ( ! V_127 )
V_127 = V_6 -> V_48 + V_126 ;
V_6 -> V_49 [ V_22 ] = V_127 ;
}
if ( V_122 > V_127 )
V_122 = V_127 ;
V_57 = ~ V_6 -> V_53 [ V_22 ] ;
while ( V_57 != ( int ) ( - 1 ) ) {
int V_36 = F_20 ( V_57 ) ;
V_57 |= 1 << V_36 ;
V_12 = F_59 ( V_6 , V_36 , V_22 ) ;
if ( F_61 ( V_12 != NULL ) )
goto V_124;
}
}
F_68 ( V_4 ) ;
if ( F_61 ( V_122 > V_6 -> V_48 ) )
F_69 ( & V_6 -> V_128 , V_122 ) ;
else
F_70 ( & V_6 -> V_129 ) ;
V_125:
return V_12 ;
}
static void F_71 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
unsigned int V_112 ;
for ( V_112 = 0 ; V_112 < V_6 -> V_9 . V_130 ; V_112 ++ ) {
F_72 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_14 -> V_22 )
memset ( & V_14 -> V_64 . V_65 , 0 , sizeof( V_14 -> V_64 . V_65 ) ) ;
else {
if ( V_14 -> V_64 . V_80 . V_6 )
F_73 ( V_14 -> V_64 . V_80 . V_6 ) ;
F_74 ( & V_14 -> V_64 . V_80 . V_82 ) ;
}
V_14 -> V_61 = 0 ;
V_14 -> V_62 = V_68 ;
}
}
F_75 ( & V_6 -> V_128 ) ;
F_76 ( & V_6 -> V_93 ) ;
V_4 -> V_6 . V_81 = 0 ;
V_4 -> V_131 . V_132 = 0 ;
memset ( V_6 -> V_45 , 0 , sizeof( V_6 -> V_45 ) ) ;
memset ( V_6 -> V_53 , 0 , sizeof( V_6 -> V_53 ) ) ;
for ( V_112 = 0 ; V_112 < V_133 ; V_112 ++ )
F_74 ( V_6 -> V_83 + V_112 ) ;
}
static void F_77 ( struct V_134 * V_129 )
{
struct V_5 * V_6 = F_4 ( V_129 , struct V_5 , V_129 ) ;
struct V_3 * V_4 = V_6 -> V_128 . V_135 ;
F_78 () ;
F_79 ( F_80 ( V_4 ) ) ;
F_81 () ;
}
static int F_82 ( struct V_3 * V_4 , struct V_136 * V_137 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_136 * V_138 [ V_139 + 1 ] ;
struct V_140 * V_141 ;
int V_142 ;
int V_112 ;
F_83 ( & V_6 -> V_128 , V_4 ) ;
F_84 ( & V_6 -> V_129 , F_77 ) ;
if ( ! V_137 )
return - V_143 ;
V_142 = F_85 ( & V_6 -> V_144 , & V_6 -> V_23 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_86 ( V_138 , V_139 , V_137 , V_145 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! V_138 [ V_146 ] )
return - V_143 ;
V_141 = F_87 ( V_138 [ V_146 ] ) ;
if ( V_141 -> V_147 != V_148 >> 16 )
return - V_143 ;
V_142 = F_88 ( & V_6 -> V_9 ) ;
if ( V_142 < 0 )
return V_142 ;
for ( V_112 = 0 ; V_112 < V_133 ; V_112 ++ )
F_74 ( V_6 -> V_83 + V_112 ) ;
F_89 ( & V_6 -> V_93 ) ;
if ( V_138 [ V_149 ] )
V_6 -> V_94 = F_90 ( V_138 [ V_149 ] ) ;
else
V_6 -> V_94 = F_91 ( V_4 ) -> V_150 ;
if ( ( V_6 -> V_151 = V_141 -> V_151 ) < 1 )
V_6 -> V_151 = 1 ;
V_6 -> V_33 = V_141 -> V_33 ;
return 0 ;
}
static int F_92 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_136 * V_152 ;
struct V_140 V_141 ;
V_141 . V_95 = V_6 -> V_95 ;
V_141 . V_147 = V_148 ;
V_141 . V_151 = V_6 -> V_151 ;
V_141 . V_33 = V_6 -> V_33 ;
V_141 . V_153 = 0 ;
V_152 = F_93 ( V_12 , V_154 ) ;
if ( V_152 == NULL )
goto V_155;
if ( F_94 ( V_12 , V_146 , sizeof( V_141 ) , & V_141 ) ||
F_95 ( V_12 , V_149 , V_6 -> V_94 ) )
goto V_155;
return F_96 ( V_12 , V_152 ) ;
V_155:
F_97 ( V_12 , V_152 ) ;
return - 1 ;
}
static int F_98 ( struct V_3 * V_4 , unsigned long V_156 ,
struct V_11 * V_12 , struct V_157 * V_158 )
{
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
struct V_136 * V_152 ;
struct V_159 V_137 ;
V_158 -> V_160 = V_14 -> V_39 ? V_14 -> V_39 -> V_10 . V_32 : V_161 ;
V_158 -> V_162 = V_14 -> V_10 . V_32 ;
if ( ! V_14 -> V_22 && V_14 -> V_64 . V_80 . V_6 )
V_158 -> V_163 = V_14 -> V_64 . V_80 . V_6 -> V_2 ;
V_152 = F_93 ( V_12 , V_154 ) ;
if ( V_152 == NULL )
goto V_155;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
F_99 ( & V_137 . V_97 , & V_14 -> V_97 ) ;
V_137 . V_73 = F_100 ( V_14 -> V_73 ) ;
F_99 ( & V_137 . ceil , & V_14 -> ceil ) ;
V_137 . V_72 = F_100 ( V_14 -> V_72 ) ;
V_137 . V_121 = V_14 -> V_121 ;
V_137 . V_36 = V_14 -> V_36 ;
V_137 . V_22 = V_14 -> V_22 ;
if ( F_94 ( V_12 , V_164 , sizeof( V_137 ) , & V_137 ) )
goto V_155;
if ( ( V_14 -> V_97 . V_165 >= ( 1ULL << 32 ) ) &&
F_101 ( V_12 , V_166 , V_14 -> V_97 . V_165 ,
V_167 ) )
goto V_155;
if ( ( V_14 -> ceil . V_165 >= ( 1ULL << 32 ) ) &&
F_101 ( V_12 , V_168 , V_14 -> ceil . V_165 ,
V_167 ) )
goto V_155;
return F_96 ( V_12 , V_152 ) ;
V_155:
F_97 ( V_12 , V_152 ) ;
return - 1 ;
}
static int
F_102 ( struct V_3 * V_4 , unsigned long V_156 , struct V_169 * V_170 )
{
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
struct V_171 V_172 = {
. V_83 = V_14 -> V_83 ,
} ;
T_3 V_81 = 0 ;
if ( ! V_14 -> V_22 && V_14 -> V_64 . V_80 . V_6 ) {
V_81 = V_14 -> V_64 . V_80 . V_6 -> V_6 . V_81 ;
V_172 . V_132 = V_14 -> V_64 . V_80 . V_6 -> V_131 . V_132 ;
}
V_14 -> V_101 . V_78 = F_103 ( T_2 , F_100 ( V_14 -> V_78 ) ,
V_173 , V_174 ) ;
V_14 -> V_101 . V_77 = F_103 ( T_2 , F_100 ( V_14 -> V_77 ) ,
V_173 , V_174 ) ;
if ( F_104 ( F_105 ( V_4 ) ,
V_170 , NULL , & V_14 -> V_104 ) < 0 ||
F_106 ( V_170 , & V_14 -> V_175 ) < 0 ||
F_107 ( V_170 , NULL , & V_172 , V_81 ) < 0 )
return - 1 ;
return F_108 ( V_170 , & V_14 -> V_101 , sizeof( V_14 -> V_101 ) ) ;
}
static int F_109 ( struct V_3 * V_4 , unsigned long V_156 , struct V_3 * V_176 ,
struct V_3 * * V_177 )
{
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
if ( V_14 -> V_22 )
return - V_143 ;
if ( V_176 == NULL &&
( V_176 = F_110 ( V_4 -> V_178 , & V_179 ,
V_14 -> V_10 . V_32 ) ) == NULL )
return - V_180 ;
* V_177 = F_111 ( V_4 , V_176 , & V_14 -> V_64 . V_80 . V_6 ) ;
return 0 ;
}
static struct V_3 * F_112 ( struct V_3 * V_4 , unsigned long V_156 )
{
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
return ! V_14 -> V_22 ? V_14 -> V_64 . V_80 . V_6 : NULL ;
}
static void F_113 ( struct V_3 * V_4 , unsigned long V_156 )
{
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
F_35 ( F_2 ( V_4 ) , V_14 ) ;
}
static inline int F_114 ( struct V_1 * V_14 )
{
if ( ! V_14 -> V_39 )
return 0 ;
if ( V_14 -> V_39 -> V_181 > 1 )
return 0 ;
return 1 ;
}
static void F_115 ( struct V_5 * V_6 , struct V_1 * V_14 ,
struct V_3 * V_182 )
{
struct V_1 * V_39 = V_14 -> V_39 ;
F_23 ( V_14 -> V_22 || ! V_14 -> V_64 . V_80 . V_6 || V_14 -> V_61 ) ;
if ( V_39 -> V_62 != V_68 )
F_21 ( & V_39 -> V_50 ,
& V_6 -> V_45 [ V_39 -> V_22 ] . V_46 ) ;
V_39 -> V_22 = 0 ;
memset ( & V_39 -> V_64 . V_65 , 0 , sizeof( V_39 -> V_64 . V_65 ) ) ;
F_74 ( & V_39 -> V_64 . V_80 . V_82 ) ;
V_39 -> V_64 . V_80 . V_6 = V_182 ? V_182 : & V_183 ;
V_39 -> V_78 = V_39 -> V_73 ;
V_39 -> V_77 = V_39 -> V_72 ;
V_39 -> V_100 = F_67 () ;
V_39 -> V_62 = V_68 ;
}
static void F_116 ( struct V_3 * V_4 , struct V_1 * V_14 )
{
if ( ! V_14 -> V_22 ) {
F_23 ( ! V_14 -> V_64 . V_80 . V_6 ) ;
F_117 ( V_14 -> V_64 . V_80 . V_6 ) ;
}
F_118 ( & V_14 -> V_175 ) ;
F_119 ( V_14 -> V_144 ) ;
F_120 ( V_14 ) ;
}
static void F_121 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_184 * V_88 ;
struct V_1 * V_14 ;
unsigned int V_112 ;
F_122 ( & V_6 -> V_129 ) ;
F_75 ( & V_6 -> V_128 ) ;
F_119 ( V_6 -> V_144 ) ;
for ( V_112 = 0 ; V_112 < V_6 -> V_9 . V_130 ; V_112 ++ ) {
F_72 (cl, &q->clhash.hash[i], common.hnode) {
F_119 ( V_14 -> V_144 ) ;
V_14 -> V_144 = NULL ;
}
}
for ( V_112 = 0 ; V_112 < V_6 -> V_9 . V_130 ; V_112 ++ ) {
F_123 (cl, next, &q->clhash.hash[i],
common.hnode)
F_116 ( V_4 , V_14 ) ;
}
F_124 ( & V_6 -> V_9 ) ;
F_76 ( & V_6 -> V_93 ) ;
}
static int F_125 ( struct V_3 * V_4 , unsigned long V_156 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
struct V_3 * V_182 = NULL ;
int V_185 = 0 ;
if ( V_14 -> V_181 || V_14 -> V_186 )
return - V_187 ;
if ( ! V_14 -> V_22 && F_114 ( V_14 ) ) {
V_182 = F_110 ( V_4 -> V_178 , & V_179 ,
V_14 -> V_39 -> V_10 . V_32 ) ;
V_185 = 1 ;
}
F_126 ( V_4 ) ;
if ( ! V_14 -> V_22 ) {
unsigned int V_81 = V_14 -> V_64 . V_80 . V_6 -> V_6 . V_81 ;
unsigned int V_132 = V_14 -> V_64 . V_80 . V_6 -> V_131 . V_132 ;
F_73 ( V_14 -> V_64 . V_80 . V_6 ) ;
F_127 ( V_14 -> V_64 . V_80 . V_6 , V_81 , V_132 ) ;
}
F_128 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_14 -> V_39 )
V_14 -> V_39 -> V_181 -- ;
if ( V_14 -> V_61 )
F_35 ( V_6 , V_14 ) ;
if ( V_14 -> V_62 != V_68 )
F_21 ( & V_14 -> V_50 ,
& V_6 -> V_45 [ V_14 -> V_22 ] . V_46 ) ;
if ( V_185 )
F_115 ( V_6 , V_14 , V_182 ) ;
F_129 ( V_4 ) ;
F_116 ( V_4 , V_14 ) ;
return 0 ;
}
static int F_130 ( struct V_3 * V_4 , T_1 V_32 ,
T_1 V_188 , struct V_136 * * V_189 ,
unsigned long * V_156 )
{
int V_142 = - V_143 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) * V_156 , * V_39 ;
struct V_136 * V_137 = V_189 [ V_154 ] ;
struct V_136 * V_138 [ V_139 + 1 ] ;
struct V_159 * V_190 ;
T_4 V_191 , V_192 ;
if ( ! V_137 )
goto V_193;
V_142 = F_86 ( V_138 , V_139 , V_137 , V_145 , NULL ) ;
if ( V_142 < 0 )
goto V_193;
V_142 = - V_143 ;
if ( V_138 [ V_164 ] == NULL )
goto V_193;
V_39 = V_188 == V_161 ? NULL : F_1 ( V_188 , V_4 ) ;
V_190 = F_87 ( V_138 [ V_164 ] ) ;
if ( ! V_190 -> V_97 . V_97 || ! V_190 -> ceil . V_97 )
goto V_193;
if ( V_190 -> V_97 . V_194 == V_195 )
F_131 ( F_132 ( & V_190 -> V_97 , V_138 [ V_196 ] ) ) ;
if ( V_190 -> ceil . V_194 == V_195 )
F_131 ( F_132 ( & V_190 -> ceil , V_138 [ V_197 ] ) ) ;
if ( ! V_14 ) {
struct V_3 * V_182 ;
int V_36 ;
struct {
struct V_136 V_198 ;
struct V_199 V_137 ;
} V_200 = {
. V_198 = {
. V_201 = F_133 ( sizeof( V_200 . V_137 ) ) ,
. V_202 = V_203 ,
} ,
. V_137 = {
. V_204 = 2 ,
. V_205 = 2 ,
} ,
} ;
if ( ! V_32 || F_11 ( V_32 ^ V_4 -> V_2 ) ||
F_1 ( V_32 , V_4 ) )
goto V_193;
if ( V_39 && V_39 -> V_39 && V_39 -> V_39 -> V_22 < 2 ) {
F_134 ( L_3 ) ;
goto V_193;
}
V_142 = - V_180 ;
V_14 = F_135 ( sizeof( * V_14 ) , V_206 ) ;
if ( ! V_14 )
goto V_193;
V_142 = F_85 ( & V_14 -> V_144 , & V_14 -> V_23 ) ;
if ( V_142 ) {
F_120 ( V_14 ) ;
goto V_193;
}
if ( V_207 || V_189 [ V_203 ] ) {
V_142 = F_136 ( & V_14 -> V_104 , NULL ,
& V_14 -> V_175 ,
NULL ,
F_105 ( V_4 ) ,
V_189 [ V_203 ] ? : & V_200 . V_198 ) ;
if ( V_142 ) {
F_119 ( V_14 -> V_144 ) ;
F_120 ( V_14 ) ;
goto V_193;
}
}
V_14 -> V_181 = 0 ;
F_74 ( & V_14 -> V_64 . V_80 . V_82 ) ;
F_25 ( & V_14 -> V_50 ) ;
for ( V_36 = 0 ; V_36 < V_133 ; V_36 ++ )
F_25 ( & V_14 -> V_41 [ V_36 ] ) ;
V_182 = F_110 ( V_4 -> V_178 ,
& V_179 , V_32 ) ;
F_126 ( V_4 ) ;
if ( V_39 && ! V_39 -> V_22 ) {
unsigned int V_81 = V_39 -> V_64 . V_80 . V_6 -> V_6 . V_81 ;
unsigned int V_132 = V_39 -> V_64 . V_80 . V_6 -> V_131 . V_132 ;
F_73 ( V_39 -> V_64 . V_80 . V_6 ) ;
F_127 ( V_39 -> V_64 . V_80 . V_6 , V_81 , V_132 ) ;
F_117 ( V_39 -> V_64 . V_80 . V_6 ) ;
if ( V_39 -> V_61 )
F_35 ( V_6 , V_39 ) ;
if ( V_39 -> V_62 != V_68 ) {
F_21 ( & V_39 -> V_50 , & V_6 -> V_45 [ 0 ] . V_46 ) ;
V_39 -> V_62 = V_68 ;
}
V_39 -> V_22 = ( V_39 -> V_39 ? V_39 -> V_39 -> V_22
: V_116 ) - 1 ;
memset ( & V_39 -> V_64 . V_65 , 0 , sizeof( V_39 -> V_64 . V_65 ) ) ;
}
V_14 -> V_64 . V_80 . V_6 = V_182 ? V_182 : & V_183 ;
V_14 -> V_10 . V_32 = V_32 ;
V_14 -> V_39 = V_39 ;
V_14 -> V_78 = F_137 ( V_190 -> V_73 ) ;
V_14 -> V_77 = F_137 ( V_190 -> V_72 ) ;
V_14 -> V_98 = 60ULL * V_126 ;
V_14 -> V_100 = F_67 () ;
V_14 -> V_62 = V_68 ;
F_138 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_39 )
V_39 -> V_181 ++ ;
if ( V_14 -> V_64 . V_80 . V_6 != & V_183 )
F_139 ( V_14 -> V_64 . V_80 . V_6 , true ) ;
} else {
if ( V_189 [ V_203 ] ) {
V_142 = F_140 ( & V_14 -> V_104 , NULL ,
& V_14 -> V_175 ,
NULL ,
F_105 ( V_4 ) ,
V_189 [ V_203 ] ) ;
if ( V_142 )
return V_142 ;
}
F_126 ( V_4 ) ;
}
V_191 = V_138 [ V_166 ] ? F_141 ( V_138 [ V_166 ] ) : 0 ;
V_192 = V_138 [ V_168 ] ? F_141 ( V_138 [ V_168 ] ) : 0 ;
F_142 ( & V_14 -> V_97 , & V_190 -> V_97 , V_191 ) ;
F_142 ( & V_14 -> ceil , & V_190 -> ceil , V_192 ) ;
if ( ! V_14 -> V_22 ) {
T_4 V_121 = V_14 -> V_97 . V_165 ;
F_143 ( V_121 , V_6 -> V_151 ) ;
V_14 -> V_121 = F_50 ( T_4 , V_121 , V_174 ) ;
if ( ! V_190 -> V_121 && V_14 -> V_121 < 1000 ) {
F_55 ( L_4 ,
V_14 -> V_10 . V_32 ) ;
V_14 -> V_121 = 1000 ;
}
if ( ! V_190 -> V_121 && V_14 -> V_121 > 200000 ) {
F_55 ( L_5 ,
V_14 -> V_10 . V_32 ) ;
V_14 -> V_121 = 200000 ;
}
if ( V_190 -> V_121 )
V_14 -> V_121 = V_190 -> V_121 ;
if ( ( V_14 -> V_36 = V_190 -> V_36 ) >= V_133 )
V_14 -> V_36 = V_133 - 1 ;
}
V_14 -> V_73 = F_137 ( V_190 -> V_73 ) ;
V_14 -> V_72 = F_137 ( V_190 -> V_72 ) ;
F_129 ( V_4 ) ;
F_144 ( V_4 , & V_6 -> V_9 ) ;
* V_156 = ( unsigned long ) V_14 ;
return 0 ;
V_193:
return V_142 ;
}
static struct V_208 * F_145 ( struct V_3 * V_4 , unsigned long V_156 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
return V_14 ? V_14 -> V_144 : V_6 -> V_144 ;
}
static unsigned long F_146 ( struct V_3 * V_4 , unsigned long V_39 ,
T_1 V_32 )
{
struct V_1 * V_14 = F_1 ( V_32 , V_4 ) ;
if ( V_14 )
V_14 -> V_186 ++ ;
return ( unsigned long ) V_14 ;
}
static void F_147 ( struct V_3 * V_4 , unsigned long V_156 )
{
struct V_1 * V_14 = (struct V_1 * ) V_156 ;
if ( V_14 )
V_14 -> V_186 -- ;
}
static void F_148 ( struct V_3 * V_4 , struct V_209 * V_156 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
unsigned int V_112 ;
if ( V_156 -> V_210 )
return;
for ( V_112 = 0 ; V_112 < V_6 -> V_9 . V_130 ; V_112 ++ ) {
F_72 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_156 -> V_211 < V_156 -> V_212 ) {
V_156 -> V_211 ++ ;
continue;
}
if ( V_156 -> V_213 ( V_4 , ( unsigned long ) V_14 , V_156 ) < 0 ) {
V_156 -> V_210 = 1 ;
return;
}
V_156 -> V_211 ++ ;
}
}
}
static int T_5 F_149 ( void )
{
return F_150 ( & V_214 ) ;
}
static void T_6 F_151 ( void )
{
F_152 ( & V_214 ) ;
}
