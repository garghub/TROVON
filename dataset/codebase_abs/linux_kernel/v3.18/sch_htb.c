static inline struct V_1 * F_1 ( T_1 V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( & V_6 -> V_9 , V_2 ) ;
if ( V_8 == NULL )
return NULL ;
return F_4 ( V_8 , struct V_1 , V_10 ) ;
}
static struct V_1 * F_5 ( struct V_11 * V_12 , struct V_3 * V_4 ,
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
V_18 = F_6 ( V_14 -> V_23 ) ;
} else {
V_18 = F_6 ( V_6 -> V_23 ) ;
}
* V_13 = V_24 | V_25 ;
while ( V_18 && ( V_19 = F_7 ( V_12 , V_18 , & V_16 ) ) >= 0 ) {
#ifdef F_8
switch ( V_19 ) {
case V_26 :
case V_27 :
* V_13 = V_24 | V_28 ;
case V_29 :
return NULL ;
}
#endif
V_14 = ( void * ) V_16 . V_30 ;
if ( ! V_14 ) {
if ( V_16 . V_31 == V_4 -> V_2 )
return V_21 ;
V_14 = F_1 ( V_16 . V_31 , V_4 ) ;
if ( ! V_14 )
break;
}
if ( ! V_14 -> V_22 )
return V_14 ;
V_18 = F_6 ( V_14 -> V_23 ) ;
}
V_14 = F_1 ( F_9 ( F_10 ( V_4 -> V_2 ) , V_6 -> V_32 ) , V_4 ) ;
if ( ! V_14 || V_14 -> V_22 )
return V_21 ;
return V_14 ;
}
static void F_11 ( struct V_33 * V_34 ,
struct V_1 * V_14 , int V_35 )
{
struct V_36 * * V_37 = & V_34 -> V_36 , * V_38 = NULL ;
while ( * V_37 ) {
struct V_1 * V_39 ;
V_38 = * V_37 ;
V_39 = F_12 ( V_38 , struct V_1 , V_40 [ V_35 ] ) ;
if ( V_14 -> V_10 . V_31 > V_39 -> V_10 . V_31 )
V_37 = & V_38 -> V_41 ;
else
V_37 = & V_38 -> V_42 ;
}
F_13 ( & V_14 -> V_40 [ V_35 ] , V_38 , V_37 ) ;
F_14 ( & V_14 -> V_40 [ V_35 ] , V_34 ) ;
}
static void F_15 ( struct V_5 * V_6 ,
struct V_1 * V_14 , T_2 V_43 )
{
struct V_36 * * V_37 = & V_6 -> V_44 [ V_14 -> V_22 ] . V_45 . V_36 , * V_38 = NULL ;
V_14 -> V_46 = V_6 -> V_47 + V_43 ;
if ( V_14 -> V_46 == V_6 -> V_47 )
V_14 -> V_46 ++ ;
if ( V_6 -> V_48 [ V_14 -> V_22 ] > V_14 -> V_46 )
V_6 -> V_48 [ V_14 -> V_22 ] = V_14 -> V_46 ;
while ( * V_37 ) {
struct V_1 * V_39 ;
V_38 = * V_37 ;
V_39 = F_12 ( V_38 , struct V_1 , V_49 ) ;
if ( V_14 -> V_46 >= V_39 -> V_46 )
V_37 = & V_38 -> V_41 ;
else
V_37 = & V_38 -> V_42 ;
}
F_13 ( & V_14 -> V_49 , V_38 , V_37 ) ;
F_14 ( & V_14 -> V_49 , & V_6 -> V_44 [ V_14 -> V_22 ] . V_45 ) ;
}
static inline void F_16 ( struct V_36 * * V_50 )
{
* V_50 = F_17 ( * V_50 ) ;
}
static inline void F_18 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_51 )
{
V_6 -> V_52 [ V_14 -> V_22 ] |= V_51 ;
while ( V_51 ) {
int V_35 = F_19 ( ~ V_51 ) ;
V_51 &= ~ ( 1 << V_35 ) ;
F_11 ( & V_6 -> V_44 [ V_14 -> V_22 ] . V_53 [ V_35 ] . V_54 , V_14 , V_35 ) ;
}
}
static void F_20 ( struct V_36 * V_55 , struct V_33 * V_34 )
{
if ( F_21 ( V_55 ) ) {
F_22 ( 1 ) ;
} else {
F_23 ( V_55 , V_34 ) ;
F_24 ( V_55 ) ;
}
}
static inline void F_25 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_51 )
{
int V_56 = 0 ;
struct V_57 * V_44 = & V_6 -> V_44 [ V_14 -> V_22 ] ;
while ( V_51 ) {
int V_35 = F_19 ( ~ V_51 ) ;
struct V_58 * V_53 = & V_44 -> V_53 [ V_35 ] ;
V_51 &= ~ ( 1 << V_35 ) ;
if ( V_53 -> V_59 == V_14 -> V_40 + V_35 )
F_16 ( & V_53 -> V_59 ) ;
F_20 ( V_14 -> V_40 + V_35 , & V_53 -> V_54 ) ;
if ( ! V_53 -> V_54 . V_36 )
V_56 |= 1 << V_35 ;
}
V_6 -> V_52 [ V_14 -> V_22 ] &= ~ V_56 ;
}
static void F_26 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_37 = V_14 -> V_38 ;
long V_56 , V_51 = V_14 -> V_60 ;
while ( V_14 -> V_61 == V_62 && V_37 && V_51 ) {
V_56 = V_51 ;
while ( V_56 ) {
int V_35 = F_19 ( ~ V_56 ) ;
V_56 &= ~ ( 1 << V_35 ) ;
if ( V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 . V_36 )
V_51 &= ~ ( 1 << V_35 ) ;
F_11 ( & V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 , V_14 , V_35 ) ;
}
V_37 -> V_60 |= V_51 ;
V_14 = V_37 ;
V_37 = V_14 -> V_38 ;
}
if ( V_14 -> V_61 == V_67 && V_51 )
F_18 ( V_6 , V_14 , V_51 ) ;
}
static void F_27 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_37 = V_14 -> V_38 ;
long V_56 , V_51 = V_14 -> V_60 ;
while ( V_14 -> V_61 == V_62 && V_37 && V_51 ) {
V_56 = V_51 ;
V_51 = 0 ;
while ( V_56 ) {
int V_35 = F_19 ( ~ V_56 ) ;
V_56 &= ~ ( 1 << V_35 ) ;
if ( V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 == V_14 -> V_40 + V_35 ) {
V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_68 = V_14 -> V_10 . V_31 ;
V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 = NULL ;
}
F_20 ( V_14 -> V_40 + V_35 ,
& V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 ) ;
if ( ! V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 . V_36 )
V_51 |= 1 << V_35 ;
}
V_37 -> V_60 &= ~ V_51 ;
V_14 = V_37 ;
V_37 = V_14 -> V_38 ;
}
if ( V_14 -> V_61 == V_67 && V_51 )
F_25 ( V_6 , V_14 , V_51 ) ;
}
static inline T_2 F_28 ( const struct V_1 * V_14 )
{
if ( V_69 )
return V_14 -> V_61 != V_70 ? - V_14 -> V_71 : 0 ;
else
return 0 ;
}
static inline T_2 F_29 ( const struct V_1 * V_14 )
{
if ( V_69 )
return V_14 -> V_61 == V_67 ? - V_14 -> V_72 : 0 ;
else
return 0 ;
}
static inline enum V_73
F_30 ( struct V_1 * V_14 , T_2 * V_74 )
{
T_2 V_75 ;
if ( ( V_75 = ( V_14 -> V_76 + * V_74 ) ) < F_28 ( V_14 ) ) {
* V_74 = - V_75 ;
return V_70 ;
}
if ( ( V_75 = ( V_14 -> V_77 + * V_74 ) ) >= F_29 ( V_14 ) )
return V_67 ;
* V_74 = - V_75 ;
return V_62 ;
}
static void
F_31 ( struct V_5 * V_6 , struct V_1 * V_14 , T_2 * V_74 )
{
enum V_73 V_78 = F_30 ( V_14 , V_74 ) ;
if ( V_78 == V_14 -> V_61 )
return;
if ( V_14 -> V_60 ) {
if ( V_14 -> V_61 != V_70 )
F_27 ( V_6 , V_14 ) ;
V_14 -> V_61 = V_78 ;
if ( V_78 != V_70 )
F_26 ( V_6 , V_14 ) ;
} else
V_14 -> V_61 = V_78 ;
}
static inline void F_32 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_22 ( V_14 -> V_22 || ! V_14 -> V_63 . V_79 . V_6 || ! V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 ) ;
if ( ! V_14 -> V_60 ) {
V_14 -> V_60 = 1 << V_14 -> V_35 ;
F_26 ( V_6 , V_14 ) ;
F_33 ( & V_14 -> V_63 . V_79 . V_81 ,
V_6 -> V_82 + V_14 -> V_35 ) ;
}
}
static inline void F_34 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_22 ( ! V_14 -> V_60 ) ;
F_27 ( V_6 , V_14 ) ;
V_14 -> V_60 = 0 ;
F_35 ( & V_14 -> V_63 . V_79 . V_81 ) ;
}
static int F_36 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
int V_83 ( V_84 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = F_5 ( V_12 , V_4 , & V_84 ) ;
if ( V_14 == V_21 ) {
if ( V_6 -> V_85 . V_80 < V_6 -> V_86 ) {
F_37 ( & V_6 -> V_85 , V_12 ) ;
V_6 -> V_87 ++ ;
} else {
return F_38 ( V_12 , V_4 ) ;
}
#ifdef F_8
} else if ( ! V_14 ) {
if ( V_84 & V_25 )
F_39 ( V_4 ) ;
F_40 ( V_12 ) ;
return V_84 ;
#endif
} else if ( ( V_84 = F_41 ( V_12 , V_14 -> V_63 . V_79 . V_6 ) ) != V_24 ) {
if ( F_42 ( V_84 ) ) {
F_39 ( V_4 ) ;
V_14 -> V_88 . V_82 ++ ;
}
return V_84 ;
} else {
F_32 ( V_6 , V_14 ) ;
}
V_4 -> V_6 . V_80 ++ ;
return V_24 ;
}
static inline void F_43 ( struct V_1 * V_14 , int V_89 , T_2 V_74 )
{
T_2 V_75 = V_74 + V_14 -> V_77 ;
if ( V_75 > V_14 -> V_72 )
V_75 = V_14 -> V_72 ;
V_75 -= ( T_2 ) F_44 ( & V_14 -> V_90 , V_89 ) ;
if ( V_75 <= - V_14 -> V_91 )
V_75 = 1 - V_14 -> V_91 ;
V_14 -> V_77 = V_75 ;
}
static inline void F_45 ( struct V_1 * V_14 , int V_89 , T_2 V_74 )
{
T_2 V_75 = V_74 + V_14 -> V_76 ;
if ( V_75 > V_14 -> V_71 )
V_75 = V_14 -> V_71 ;
V_75 -= ( T_2 ) F_44 ( & V_14 -> ceil , V_89 ) ;
if ( V_75 <= - V_14 -> V_91 )
V_75 = 1 - V_14 -> V_91 ;
V_14 -> V_76 = V_75 ;
}
static void F_46 ( struct V_5 * V_6 , struct V_1 * V_14 ,
int V_22 , struct V_11 * V_12 )
{
int V_89 = F_47 ( V_12 ) ;
enum V_73 V_92 ;
T_2 V_74 ;
while ( V_14 ) {
V_74 = F_48 ( T_2 , V_6 -> V_47 - V_14 -> V_93 , V_14 -> V_91 ) ;
if ( V_14 -> V_22 >= V_22 ) {
if ( V_14 -> V_22 == V_22 )
V_14 -> V_94 . V_95 ++ ;
F_43 ( V_14 , V_89 , V_74 ) ;
} else {
V_14 -> V_94 . V_96 ++ ;
V_14 -> V_77 += V_74 ;
}
F_45 ( V_14 , V_89 , V_74 ) ;
V_14 -> V_93 = V_6 -> V_47 ;
V_92 = V_14 -> V_61 ;
V_74 = 0 ;
F_31 ( V_6 , V_14 , & V_74 ) ;
if ( V_92 != V_14 -> V_61 ) {
if ( V_92 != V_67 )
F_20 ( & V_14 -> V_49 , & V_6 -> V_44 [ V_14 -> V_22 ] . V_45 ) ;
if ( V_14 -> V_61 != V_67 )
F_15 ( V_6 , V_14 , V_74 ) ;
}
if ( V_14 -> V_22 )
F_49 ( & V_14 -> V_97 , V_12 ) ;
V_14 = V_14 -> V_38 ;
}
}
static T_2 F_50 ( struct V_5 * V_6 , const int V_22 ,
unsigned long V_98 )
{
unsigned long V_99 = V_98 + 2 ;
struct V_33 * V_45 = & V_6 -> V_44 [ V_22 ] . V_45 ;
while ( F_51 ( V_100 , V_99 ) ) {
struct V_1 * V_14 ;
T_2 V_74 ;
struct V_36 * V_37 = F_52 ( V_45 ) ;
if ( ! V_37 )
return 0 ;
V_14 = F_12 ( V_37 , struct V_1 , V_49 ) ;
if ( V_14 -> V_46 > V_6 -> V_47 )
return V_14 -> V_46 ;
F_20 ( V_37 , V_45 ) ;
V_74 = F_48 ( T_2 , V_6 -> V_47 - V_14 -> V_93 , V_14 -> V_91 ) ;
F_31 ( V_6 , V_14 , & V_74 ) ;
if ( V_14 -> V_61 != V_67 )
F_15 ( V_6 , V_14 , V_74 ) ;
}
if ( ! ( V_6 -> V_101 & V_102 ) ) {
F_53 ( L_1 ) ;
V_6 -> V_101 |= V_102 ;
}
return V_6 -> V_47 ;
}
static struct V_36 * F_54 ( int V_35 , struct V_36 * V_50 ,
T_1 V_103 )
{
struct V_36 * V_104 = NULL ;
while ( V_50 ) {
struct V_1 * V_14 =
F_12 ( V_50 , struct V_1 , V_40 [ V_35 ] ) ;
if ( V_103 > V_14 -> V_10 . V_31 ) {
V_50 = V_50 -> V_41 ;
} else if ( V_103 < V_14 -> V_10 . V_31 ) {
V_104 = V_50 ;
V_50 = V_50 -> V_42 ;
} else {
return V_50 ;
}
}
return V_104 ;
}
static struct V_1 * F_55 ( struct V_58 * V_53 , const int V_35 )
{
int V_105 ;
struct {
struct V_36 * V_34 ;
struct V_36 * * V_106 ;
T_1 * V_107 ;
} V_108 [ V_109 ] , * V_110 = V_108 ;
F_56 ( ! V_53 -> V_54 . V_36 ) ;
V_110 -> V_34 = V_53 -> V_54 . V_36 ;
V_110 -> V_106 = & V_53 -> V_59 ;
V_110 -> V_107 = & V_53 -> V_68 ;
for ( V_105 = 0 ; V_105 < 65535 ; V_105 ++ ) {
if ( ! * V_110 -> V_106 && * V_110 -> V_107 ) {
* V_110 -> V_106 =
F_54 ( V_35 , V_110 -> V_34 , * V_110 -> V_107 ) ;
}
* V_110 -> V_107 = 0 ;
if ( ! * V_110 -> V_106 ) {
* V_110 -> V_106 = V_110 -> V_34 ;
while ( ( * V_110 -> V_106 ) -> V_42 )
* V_110 -> V_106 = ( * V_110 -> V_106 ) -> V_42 ;
if ( V_110 > V_108 ) {
V_110 -- ;
if ( ! * V_110 -> V_106 ) {
F_22 ( 1 ) ;
return NULL ;
}
F_16 ( V_110 -> V_106 ) ;
}
} else {
struct V_1 * V_14 ;
struct V_58 * V_111 ;
V_14 = F_12 ( * V_110 -> V_106 , struct V_1 , V_40 [ V_35 ] ) ;
if ( ! V_14 -> V_22 )
return V_14 ;
V_111 = & V_14 -> V_63 . V_64 . V_65 [ V_35 ] ;
( ++ V_110 ) -> V_34 = V_111 -> V_66 . V_36 ;
V_110 -> V_106 = & V_111 -> V_59 ;
V_110 -> V_107 = & V_111 -> V_68 ;
}
}
F_22 ( 1 ) ;
return NULL ;
}
static struct V_11 * F_57 ( struct V_5 * V_6 , const int V_35 ,
const int V_22 )
{
struct V_11 * V_12 = NULL ;
struct V_1 * V_14 , * V_98 ;
struct V_57 * V_44 = & V_6 -> V_44 [ V_22 ] ;
struct V_58 * V_53 = & V_44 -> V_53 [ V_35 ] ;
V_98 = V_14 = F_55 ( V_53 , V_35 ) ;
do {
V_112:
if ( F_58 ( ! V_14 ) )
return NULL ;
if ( F_58 ( V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 == 0 ) ) {
struct V_1 * V_112 ;
F_34 ( V_6 , V_14 ) ;
if ( ( V_6 -> V_52 [ V_22 ] & ( 1 << V_35 ) ) == 0 )
return NULL ;
V_112 = F_55 ( V_53 , V_35 ) ;
if ( V_14 == V_98 )
V_98 = V_112 ;
V_14 = V_112 ;
goto V_112;
}
V_12 = V_14 -> V_63 . V_79 . V_6 -> V_113 ( V_14 -> V_63 . V_79 . V_6 ) ;
if ( F_59 ( V_12 != NULL ) )
break;
F_60 ( L_2 , V_14 -> V_63 . V_79 . V_6 ) ;
F_16 ( V_22 ? & V_14 -> V_38 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 :
& V_6 -> V_44 [ 0 ] . V_53 [ V_35 ] . V_59 ) ;
V_14 = F_55 ( V_53 , V_35 ) ;
} while ( V_14 != V_98 );
if ( F_59 ( V_12 != NULL ) ) {
F_49 ( & V_14 -> V_97 , V_12 ) ;
V_14 -> V_63 . V_79 . V_114 [ V_22 ] -= F_47 ( V_12 ) ;
if ( V_14 -> V_63 . V_79 . V_114 [ V_22 ] < 0 ) {
V_14 -> V_63 . V_79 . V_114 [ V_22 ] += V_14 -> V_115 ;
F_16 ( V_22 ? & V_14 -> V_38 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 :
& V_6 -> V_44 [ 0 ] . V_53 [ V_35 ] . V_59 ) ;
}
if ( ! V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 )
F_34 ( V_6 , V_14 ) ;
F_46 ( V_6 , V_14 , V_22 , V_12 ) ;
}
return V_12 ;
}
static struct V_11 * F_61 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_22 ;
T_2 V_116 ;
unsigned long V_117 ;
V_12 = F_62 ( & V_6 -> V_85 ) ;
if ( V_12 != NULL ) {
V_118:
F_63 ( V_4 , V_12 ) ;
F_64 ( V_4 ) ;
V_4 -> V_6 . V_80 -- ;
return V_12 ;
}
if ( ! V_4 -> V_6 . V_80 )
goto V_119;
V_6 -> V_47 = F_65 () ;
V_117 = V_100 ;
V_116 = V_6 -> V_47 + 5LLU * V_120 ;
for ( V_22 = 0 ; V_22 < V_109 ; V_22 ++ ) {
int V_56 ;
T_2 V_121 = V_6 -> V_48 [ V_22 ] ;
if ( V_6 -> V_47 >= V_121 ) {
V_121 = F_50 ( V_6 , V_22 , V_117 ) ;
if ( ! V_121 )
V_121 = V_6 -> V_47 + V_120 ;
V_6 -> V_48 [ V_22 ] = V_121 ;
}
if ( V_116 > V_121 )
V_116 = V_121 ;
V_56 = ~ V_6 -> V_52 [ V_22 ] ;
while ( V_56 != ( int ) ( - 1 ) ) {
int V_35 = F_19 ( V_56 ) ;
V_56 |= 1 << V_35 ;
V_12 = F_57 ( V_6 , V_35 , V_22 ) ;
if ( F_59 ( V_12 != NULL ) )
goto V_118;
}
}
F_66 ( V_4 ) ;
if ( F_59 ( V_116 > V_6 -> V_47 ) ) {
if ( ! F_67 ( V_122 ,
& F_68 ( V_6 -> V_123 . V_124 ) -> V_125 ) ) {
T_3 time = F_69 ( V_116 ) ;
F_70 ( V_6 -> V_123 . V_124 ) ;
F_71 ( & V_6 -> V_123 . V_126 , time ,
V_127 ) ;
}
} else {
F_72 ( & V_6 -> V_128 ) ;
}
V_119:
return V_12 ;
}
static unsigned int F_73 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_35 ;
for ( V_35 = V_129 - 1 ; V_35 >= 0 ; V_35 -- ) {
struct V_130 * V_37 ;
F_74 (p, q->drops + prio) {
struct V_1 * V_14 = F_75 ( V_37 , struct V_1 ,
V_63 . V_79 . V_81 ) ;
unsigned int V_131 ;
if ( V_14 -> V_63 . V_79 . V_6 -> V_132 -> V_133 &&
( V_131 = V_14 -> V_63 . V_79 . V_6 -> V_132 -> V_133 ( V_14 -> V_63 . V_79 . V_6 ) ) ) {
V_4 -> V_6 . V_80 -- ;
if ( ! V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 )
F_34 ( V_6 , V_14 ) ;
return V_131 ;
}
}
}
return 0 ;
}
static void F_76 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < V_6 -> V_9 . V_134 ; V_105 ++ ) {
F_77 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_14 -> V_22 )
memset ( & V_14 -> V_63 . V_64 , 0 , sizeof( V_14 -> V_63 . V_64 ) ) ;
else {
if ( V_14 -> V_63 . V_79 . V_6 )
F_78 ( V_14 -> V_63 . V_79 . V_6 ) ;
F_79 ( & V_14 -> V_63 . V_79 . V_81 ) ;
}
V_14 -> V_60 = 0 ;
V_14 -> V_61 = V_67 ;
}
}
F_80 ( & V_6 -> V_123 ) ;
F_81 ( & V_6 -> V_85 ) ;
V_4 -> V_6 . V_80 = 0 ;
memset ( V_6 -> V_44 , 0 , sizeof( V_6 -> V_44 ) ) ;
memset ( V_6 -> V_52 , 0 , sizeof( V_6 -> V_52 ) ) ;
for ( V_105 = 0 ; V_105 < V_129 ; V_105 ++ )
F_79 ( V_6 -> V_82 + V_105 ) ;
}
static void F_82 ( struct V_135 * V_128 )
{
struct V_5 * V_6 = F_4 ( V_128 , struct V_5 , V_128 ) ;
struct V_3 * V_4 = V_6 -> V_123 . V_124 ;
F_83 ( F_84 ( V_4 ) ) ;
}
static int F_85 ( struct V_3 * V_4 , struct V_136 * V_137 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_136 * V_138 [ V_139 + 1 ] ;
struct V_140 * V_141 ;
int V_142 ;
int V_105 ;
if ( ! V_137 )
return - V_143 ;
V_142 = F_86 ( V_138 , V_139 , V_137 , V_144 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! V_138 [ V_145 ] )
return - V_143 ;
V_141 = F_87 ( V_138 [ V_145 ] ) ;
if ( V_141 -> V_146 != V_147 >> 16 )
return - V_143 ;
V_142 = F_88 ( & V_6 -> V_9 ) ;
if ( V_142 < 0 )
return V_142 ;
for ( V_105 = 0 ; V_105 < V_129 ; V_105 ++ )
F_79 ( V_6 -> V_82 + V_105 ) ;
F_89 ( & V_6 -> V_123 , V_4 ) ;
F_90 ( & V_6 -> V_128 , F_82 ) ;
F_91 ( & V_6 -> V_85 ) ;
if ( V_138 [ V_148 ] )
V_6 -> V_86 = F_92 ( V_138 [ V_148 ] ) ;
else {
V_6 -> V_86 = F_93 ( V_4 ) -> V_149 ;
if ( V_6 -> V_86 < 2 )
V_6 -> V_86 = 2 ;
}
if ( ( V_6 -> V_150 = V_141 -> V_150 ) < 1 )
V_6 -> V_150 = 1 ;
V_6 -> V_32 = V_141 -> V_32 ;
return 0 ;
}
static int F_94 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_136 * V_151 ;
struct V_140 V_141 ;
V_141 . V_87 = V_6 -> V_87 ;
V_141 . V_146 = V_147 ;
V_141 . V_150 = V_6 -> V_150 ;
V_141 . V_32 = V_6 -> V_32 ;
V_141 . V_152 = 0 ;
V_151 = F_95 ( V_12 , V_153 ) ;
if ( V_151 == NULL )
goto V_154;
if ( F_96 ( V_12 , V_145 , sizeof( V_141 ) , & V_141 ) ||
F_97 ( V_12 , V_148 , V_6 -> V_86 ) )
goto V_154;
return F_98 ( V_12 , V_151 ) ;
V_154:
F_99 ( V_12 , V_151 ) ;
return - 1 ;
}
static int F_100 ( struct V_3 * V_4 , unsigned long V_155 ,
struct V_11 * V_12 , struct V_156 * V_157 )
{
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
struct V_136 * V_151 ;
struct V_158 V_137 ;
V_157 -> V_159 = V_14 -> V_38 ? V_14 -> V_38 -> V_10 . V_31 : V_160 ;
V_157 -> V_161 = V_14 -> V_10 . V_31 ;
if ( ! V_14 -> V_22 && V_14 -> V_63 . V_79 . V_6 )
V_157 -> V_162 = V_14 -> V_63 . V_79 . V_6 -> V_2 ;
V_151 = F_95 ( V_12 , V_153 ) ;
if ( V_151 == NULL )
goto V_154;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
F_101 ( & V_137 . V_90 , & V_14 -> V_90 ) ;
V_137 . V_72 = F_102 ( V_14 -> V_72 ) ;
F_101 ( & V_137 . ceil , & V_14 -> ceil ) ;
V_137 . V_71 = F_102 ( V_14 -> V_71 ) ;
V_137 . V_115 = V_14 -> V_115 ;
V_137 . V_35 = V_14 -> V_35 ;
V_137 . V_22 = V_14 -> V_22 ;
if ( F_96 ( V_12 , V_163 , sizeof( V_137 ) , & V_137 ) )
goto V_154;
if ( ( V_14 -> V_90 . V_164 >= ( 1ULL << 32 ) ) &&
F_103 ( V_12 , V_165 , V_14 -> V_90 . V_164 ) )
goto V_154;
if ( ( V_14 -> ceil . V_164 >= ( 1ULL << 32 ) ) &&
F_103 ( V_12 , V_166 , V_14 -> ceil . V_164 ) )
goto V_154;
return F_98 ( V_12 , V_151 ) ;
V_154:
F_99 ( V_12 , V_151 ) ;
return - 1 ;
}
static int
F_104 ( struct V_3 * V_4 , unsigned long V_155 , struct V_167 * V_168 )
{
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
T_4 V_80 = 0 ;
if ( ! V_14 -> V_22 && V_14 -> V_63 . V_79 . V_6 )
V_80 = V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 ;
V_14 -> V_94 . V_77 = F_102 ( V_14 -> V_77 ) ;
V_14 -> V_94 . V_76 = F_102 ( V_14 -> V_76 ) ;
if ( F_105 ( V_168 , NULL , & V_14 -> V_97 ) < 0 ||
F_106 ( V_168 , NULL , & V_14 -> V_169 ) < 0 ||
F_107 ( V_168 , NULL , & V_14 -> V_88 , V_80 ) < 0 )
return - 1 ;
return F_108 ( V_168 , & V_14 -> V_94 , sizeof( V_14 -> V_94 ) ) ;
}
static int F_109 ( struct V_3 * V_4 , unsigned long V_155 , struct V_3 * V_170 ,
struct V_3 * * V_171 )
{
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
if ( V_14 -> V_22 )
return - V_143 ;
if ( V_170 == NULL &&
( V_170 = F_110 ( V_4 -> V_172 , & V_173 ,
V_14 -> V_10 . V_31 ) ) == NULL )
return - V_174 ;
F_111 ( V_4 ) ;
* V_171 = V_14 -> V_63 . V_79 . V_6 ;
V_14 -> V_63 . V_79 . V_6 = V_170 ;
if ( * V_171 != NULL ) {
F_112 ( * V_171 , ( * V_171 ) -> V_6 . V_80 ) ;
F_78 ( * V_171 ) ;
}
F_113 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_114 ( struct V_3 * V_4 , unsigned long V_155 )
{
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
return ! V_14 -> V_22 ? V_14 -> V_63 . V_79 . V_6 : NULL ;
}
static void F_115 ( struct V_3 * V_4 , unsigned long V_155 )
{
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
if ( V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 == 0 )
F_34 ( F_2 ( V_4 ) , V_14 ) ;
}
static unsigned long F_116 ( struct V_3 * V_4 , T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_175 ++ ;
return ( unsigned long ) V_14 ;
}
static inline int F_117 ( struct V_1 * V_14 )
{
if ( ! V_14 -> V_38 )
return 0 ;
if ( V_14 -> V_38 -> V_176 > 1 )
return 0 ;
return 1 ;
}
static void F_118 ( struct V_5 * V_6 , struct V_1 * V_14 ,
struct V_3 * V_177 )
{
struct V_1 * V_38 = V_14 -> V_38 ;
F_22 ( V_14 -> V_22 || ! V_14 -> V_63 . V_79 . V_6 || V_14 -> V_60 ) ;
if ( V_38 -> V_61 != V_67 )
F_20 ( & V_38 -> V_49 ,
& V_6 -> V_44 [ V_38 -> V_22 ] . V_45 ) ;
V_38 -> V_22 = 0 ;
memset ( & V_38 -> V_63 . V_64 , 0 , sizeof( V_38 -> V_63 . V_64 ) ) ;
F_79 ( & V_38 -> V_63 . V_79 . V_81 ) ;
V_38 -> V_63 . V_79 . V_6 = V_177 ? V_177 : & V_178 ;
V_38 -> V_77 = V_38 -> V_72 ;
V_38 -> V_76 = V_38 -> V_71 ;
V_38 -> V_93 = F_65 () ;
V_38 -> V_61 = V_67 ;
}
static void F_119 ( struct V_3 * V_4 , struct V_1 * V_14 )
{
if ( ! V_14 -> V_22 ) {
F_22 ( ! V_14 -> V_63 . V_79 . V_6 ) ;
F_120 ( V_14 -> V_63 . V_79 . V_6 ) ;
}
F_121 ( & V_14 -> V_97 , & V_14 -> V_169 ) ;
F_122 ( & V_14 -> V_23 ) ;
F_123 ( V_14 ) ;
}
static void F_124 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_179 * V_112 ;
struct V_1 * V_14 ;
unsigned int V_105 ;
F_125 ( & V_6 -> V_128 ) ;
F_80 ( & V_6 -> V_123 ) ;
F_122 ( & V_6 -> V_23 ) ;
for ( V_105 = 0 ; V_105 < V_6 -> V_9 . V_134 ; V_105 ++ ) {
F_77 (cl, &q->clhash.hash[i], common.hnode)
F_122 ( & V_14 -> V_23 ) ;
}
for ( V_105 = 0 ; V_105 < V_6 -> V_9 . V_134 ; V_105 ++ ) {
F_126 (cl, next, &q->clhash.hash[i],
common.hnode)
F_119 ( V_4 , V_14 ) ;
}
F_127 ( & V_6 -> V_9 ) ;
F_81 ( & V_6 -> V_85 ) ;
}
static int F_128 ( struct V_3 * V_4 , unsigned long V_155 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
unsigned int V_80 ;
struct V_3 * V_177 = NULL ;
int V_180 = 0 ;
if ( V_14 -> V_176 || V_14 -> V_181 )
return - V_182 ;
if ( ! V_14 -> V_22 && F_117 ( V_14 ) ) {
V_177 = F_110 ( V_4 -> V_172 , & V_173 ,
V_14 -> V_38 -> V_10 . V_31 ) ;
V_180 = 1 ;
}
F_111 ( V_4 ) ;
if ( ! V_14 -> V_22 ) {
V_80 = V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 ;
F_78 ( V_14 -> V_63 . V_79 . V_6 ) ;
F_112 ( V_14 -> V_63 . V_79 . V_6 , V_80 ) ;
}
F_129 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_14 -> V_38 )
V_14 -> V_38 -> V_176 -- ;
if ( V_14 -> V_60 )
F_34 ( V_6 , V_14 ) ;
if ( V_14 -> V_61 != V_67 )
F_20 ( & V_14 -> V_49 ,
& V_6 -> V_44 [ V_14 -> V_22 ] . V_45 ) ;
if ( V_180 )
F_118 ( V_6 , V_14 , V_177 ) ;
F_56 ( -- V_14 -> V_175 == 0 ) ;
F_113 ( V_4 ) ;
return 0 ;
}
static void F_130 ( struct V_3 * V_4 , unsigned long V_155 )
{
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
if ( -- V_14 -> V_175 == 0 )
F_119 ( V_4 , V_14 ) ;
}
static int F_131 ( struct V_3 * V_4 , T_1 V_31 ,
T_1 V_183 , struct V_136 * * V_184 ,
unsigned long * V_155 )
{
int V_142 = - V_143 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) * V_155 , * V_38 ;
struct V_136 * V_137 = V_184 [ V_153 ] ;
struct V_136 * V_138 [ V_139 + 1 ] ;
struct V_158 * V_185 ;
T_5 V_186 , V_187 ;
if ( ! V_137 )
goto V_188;
V_142 = F_86 ( V_138 , V_139 , V_137 , V_144 ) ;
if ( V_142 < 0 )
goto V_188;
V_142 = - V_143 ;
if ( V_138 [ V_163 ] == NULL )
goto V_188;
V_38 = V_183 == V_160 ? NULL : F_1 ( V_183 , V_4 ) ;
V_185 = F_87 ( V_138 [ V_163 ] ) ;
if ( ! V_185 -> V_90 . V_90 || ! V_185 -> ceil . V_90 )
goto V_188;
if ( V_185 -> V_90 . V_189 == V_190 )
F_132 ( F_133 ( & V_185 -> V_90 , V_138 [ V_191 ] ) ) ;
if ( V_185 -> ceil . V_189 == V_190 )
F_132 ( F_133 ( & V_185 -> ceil , V_138 [ V_192 ] ) ) ;
if ( ! V_14 ) {
struct V_3 * V_177 ;
int V_35 ;
struct {
struct V_136 V_193 ;
struct V_194 V_137 ;
} V_195 = {
. V_193 = {
. V_196 = F_134 ( sizeof( V_195 . V_137 ) ) ,
. V_197 = V_198 ,
} ,
. V_137 = {
. V_199 = 2 ,
. V_200 = 2 ,
} ,
} ;
if ( ! V_31 || F_10 ( V_31 ^ V_4 -> V_2 ) ||
F_1 ( V_31 , V_4 ) )
goto V_188;
if ( V_38 && V_38 -> V_38 && V_38 -> V_38 -> V_22 < 2 ) {
F_135 ( L_3 ) ;
goto V_188;
}
V_142 = - V_174 ;
V_14 = F_136 ( sizeof( * V_14 ) , V_201 ) ;
if ( ! V_14 )
goto V_188;
if ( V_202 || V_184 [ V_198 ] ) {
V_142 = F_137 ( & V_14 -> V_97 , NULL ,
& V_14 -> V_169 ,
F_138 ( V_4 ) ,
V_184 [ V_198 ] ? : & V_195 . V_193 ) ;
if ( V_142 ) {
F_123 ( V_14 ) ;
goto V_188;
}
}
V_14 -> V_175 = 1 ;
V_14 -> V_176 = 0 ;
F_79 ( & V_14 -> V_63 . V_79 . V_81 ) ;
F_24 ( & V_14 -> V_49 ) ;
for ( V_35 = 0 ; V_35 < V_129 ; V_35 ++ )
F_24 ( & V_14 -> V_40 [ V_35 ] ) ;
V_177 = F_110 ( V_4 -> V_172 ,
& V_173 , V_31 ) ;
F_111 ( V_4 ) ;
if ( V_38 && ! V_38 -> V_22 ) {
unsigned int V_80 = V_38 -> V_63 . V_79 . V_6 -> V_6 . V_80 ;
F_78 ( V_38 -> V_63 . V_79 . V_6 ) ;
F_112 ( V_38 -> V_63 . V_79 . V_6 , V_80 ) ;
F_120 ( V_38 -> V_63 . V_79 . V_6 ) ;
if ( V_38 -> V_60 )
F_34 ( V_6 , V_38 ) ;
if ( V_38 -> V_61 != V_67 ) {
F_20 ( & V_38 -> V_49 , & V_6 -> V_44 [ 0 ] . V_45 ) ;
V_38 -> V_61 = V_67 ;
}
V_38 -> V_22 = ( V_38 -> V_38 ? V_38 -> V_38 -> V_22
: V_109 ) - 1 ;
memset ( & V_38 -> V_63 . V_64 , 0 , sizeof( V_38 -> V_63 . V_64 ) ) ;
}
V_14 -> V_63 . V_79 . V_6 = V_177 ? V_177 : & V_178 ;
V_14 -> V_10 . V_31 = V_31 ;
V_14 -> V_38 = V_38 ;
V_14 -> V_77 = F_139 ( V_185 -> V_72 ) ;
V_14 -> V_76 = F_139 ( V_185 -> V_71 ) ;
V_14 -> V_91 = 60ULL * V_120 ;
V_14 -> V_93 = F_65 () ;
V_14 -> V_61 = V_67 ;
F_140 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_38 )
V_38 -> V_176 ++ ;
} else {
if ( V_184 [ V_198 ] ) {
T_6 * V_203 = F_138 ( V_4 ) ;
V_142 = F_141 ( & V_14 -> V_97 , NULL ,
& V_14 -> V_169 ,
V_203 ,
V_184 [ V_198 ] ) ;
if ( V_142 )
return V_142 ;
}
F_111 ( V_4 ) ;
}
V_186 = V_138 [ V_165 ] ? F_142 ( V_138 [ V_165 ] ) : 0 ;
V_187 = V_138 [ V_166 ] ? F_142 ( V_138 [ V_166 ] ) : 0 ;
F_143 ( & V_14 -> V_90 , & V_185 -> V_90 , V_186 ) ;
F_143 ( & V_14 -> ceil , & V_185 -> ceil , V_187 ) ;
if ( ! V_14 -> V_22 ) {
T_5 V_115 = V_14 -> V_90 . V_164 ;
F_144 ( V_115 , V_6 -> V_150 ) ;
V_14 -> V_115 = F_48 ( T_5 , V_115 , V_204 ) ;
if ( ! V_185 -> V_115 && V_14 -> V_115 < 1000 ) {
F_53 ( L_4 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_115 = 1000 ;
}
if ( ! V_185 -> V_115 && V_14 -> V_115 > 200000 ) {
F_53 ( L_5 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_115 = 200000 ;
}
if ( V_185 -> V_115 )
V_14 -> V_115 = V_185 -> V_115 ;
if ( ( V_14 -> V_35 = V_185 -> V_35 ) >= V_129 )
V_14 -> V_35 = V_129 - 1 ;
}
V_14 -> V_72 = F_139 ( V_185 -> V_72 ) ;
V_14 -> V_71 = F_139 ( V_185 -> V_71 ) ;
F_113 ( V_4 ) ;
F_145 ( V_4 , & V_6 -> V_9 ) ;
* V_155 = ( unsigned long ) V_14 ;
return 0 ;
V_188:
return V_142 ;
}
static struct V_17 T_7 * * F_146 ( struct V_3 * V_4 ,
unsigned long V_155 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
struct V_17 T_7 * * V_205 = V_14 ? & V_14 -> V_23 : & V_6 -> V_23 ;
return V_205 ;
}
static unsigned long F_147 ( struct V_3 * V_4 , unsigned long V_38 ,
T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_181 ++ ;
return ( unsigned long ) V_14 ;
}
static void F_148 ( struct V_3 * V_4 , unsigned long V_155 )
{
struct V_1 * V_14 = (struct V_1 * ) V_155 ;
if ( V_14 )
V_14 -> V_181 -- ;
}
static void F_149 ( struct V_3 * V_4 , struct V_206 * V_155 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
unsigned int V_105 ;
if ( V_155 -> V_207 )
return;
for ( V_105 = 0 ; V_105 < V_6 -> V_9 . V_134 ; V_105 ++ ) {
F_77 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_155 -> V_208 < V_155 -> V_209 ) {
V_155 -> V_208 ++ ;
continue;
}
if ( V_155 -> V_210 ( V_4 , ( unsigned long ) V_14 , V_155 ) < 0 ) {
V_155 -> V_207 = 1 ;
return;
}
V_155 -> V_208 ++ ;
}
}
}
static int T_8 F_150 ( void )
{
return F_151 ( & V_211 ) ;
}
static void T_9 F_152 ( void )
{
F_153 ( & V_211 ) ;
}
