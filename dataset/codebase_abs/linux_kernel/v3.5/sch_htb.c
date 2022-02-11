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
if ( V_14 && V_14 -> V_22 == 0 )
return V_14 ;
* V_13 = V_23 | V_24 ;
V_18 = V_6 -> V_25 ;
while ( V_18 && ( V_19 = F_6 ( V_12 , V_18 , & V_16 ) ) >= 0 ) {
#ifdef F_7
switch ( V_19 ) {
case V_26 :
case V_27 :
* V_13 = V_23 | V_28 ;
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
V_18 = V_14 -> V_25 ;
}
V_14 = F_1 ( F_8 ( F_9 ( V_4 -> V_2 ) , V_6 -> V_32 ) , V_4 ) ;
if ( ! V_14 || V_14 -> V_22 )
return V_21 ;
return V_14 ;
}
static void F_10 ( struct V_33 * V_34 ,
struct V_1 * V_14 , int V_35 )
{
struct V_36 * * V_37 = & V_34 -> V_36 , * V_38 = NULL ;
while ( * V_37 ) {
struct V_1 * V_39 ;
V_38 = * V_37 ;
V_39 = F_11 ( V_38 , struct V_1 , V_40 [ V_35 ] ) ;
if ( V_14 -> V_10 . V_31 > V_39 -> V_10 . V_31 )
V_37 = & V_38 -> V_41 ;
else
V_37 = & V_38 -> V_42 ;
}
F_12 ( & V_14 -> V_40 [ V_35 ] , V_38 , V_37 ) ;
F_13 ( & V_14 -> V_40 [ V_35 ] , V_34 ) ;
}
static void F_14 ( struct V_5 * V_6 ,
struct V_1 * V_14 , long V_43 )
{
struct V_36 * * V_37 = & V_6 -> V_44 [ V_14 -> V_22 ] . V_36 , * V_38 = NULL ;
V_14 -> V_45 = V_6 -> V_46 + V_43 ;
if ( V_14 -> V_45 == V_6 -> V_46 )
V_14 -> V_45 ++ ;
if ( V_6 -> V_47 [ V_14 -> V_22 ] > V_14 -> V_45 )
V_6 -> V_47 [ V_14 -> V_22 ] = V_14 -> V_45 ;
while ( * V_37 ) {
struct V_1 * V_39 ;
V_38 = * V_37 ;
V_39 = F_11 ( V_38 , struct V_1 , V_48 ) ;
if ( V_14 -> V_45 >= V_39 -> V_45 )
V_37 = & V_38 -> V_41 ;
else
V_37 = & V_38 -> V_42 ;
}
F_12 ( & V_14 -> V_48 , V_38 , V_37 ) ;
F_13 ( & V_14 -> V_48 , & V_6 -> V_44 [ V_14 -> V_22 ] ) ;
}
static inline void F_15 ( struct V_36 * * V_49 )
{
* V_49 = F_16 ( * V_49 ) ;
}
static inline void F_17 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_50 )
{
V_6 -> V_51 [ V_14 -> V_22 ] |= V_50 ;
while ( V_50 ) {
int V_35 = F_18 ( ~ V_50 ) ;
V_50 &= ~ ( 1 << V_35 ) ;
F_10 ( V_6 -> V_52 [ V_14 -> V_22 ] + V_35 , V_14 , V_35 ) ;
}
}
static void F_19 ( struct V_36 * V_53 , struct V_33 * V_34 )
{
if ( F_20 ( V_53 ) ) {
F_21 ( 1 ) ;
} else {
F_22 ( V_53 , V_34 ) ;
F_23 ( V_53 ) ;
}
}
static inline void F_24 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_50 )
{
int V_54 = 0 ;
while ( V_50 ) {
int V_35 = F_18 ( ~ V_50 ) ;
V_50 &= ~ ( 1 << V_35 ) ;
if ( V_6 -> V_55 [ V_14 -> V_22 ] [ V_35 ] == V_14 -> V_40 + V_35 )
F_15 ( V_6 -> V_55 [ V_14 -> V_22 ] + V_35 ) ;
F_19 ( V_14 -> V_40 + V_35 , V_6 -> V_52 [ V_14 -> V_22 ] + V_35 ) ;
if ( ! V_6 -> V_52 [ V_14 -> V_22 ] [ V_35 ] . V_36 )
V_54 |= 1 << V_35 ;
}
V_6 -> V_51 [ V_14 -> V_22 ] &= ~ V_54 ;
}
static void F_25 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_37 = V_14 -> V_38 ;
long V_54 , V_50 = V_14 -> V_56 ;
while ( V_14 -> V_57 == V_58 && V_37 && V_50 ) {
V_54 = V_50 ;
while ( V_54 ) {
int V_35 = F_18 ( ~ V_54 ) ;
V_54 &= ~ ( 1 << V_35 ) ;
if ( V_37 -> V_59 . V_60 . V_61 [ V_35 ] . V_36 )
V_50 &= ~ ( 1 << V_35 ) ;
F_10 ( V_37 -> V_59 . V_60 . V_61 + V_35 , V_14 , V_35 ) ;
}
V_37 -> V_56 |= V_50 ;
V_14 = V_37 ;
V_37 = V_14 -> V_38 ;
}
if ( V_14 -> V_57 == V_62 && V_50 )
F_17 ( V_6 , V_14 , V_50 ) ;
}
static void F_26 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_37 = V_14 -> V_38 ;
long V_54 , V_50 = V_14 -> V_56 ;
while ( V_14 -> V_57 == V_58 && V_37 && V_50 ) {
V_54 = V_50 ;
V_50 = 0 ;
while ( V_54 ) {
int V_35 = F_18 ( ~ V_54 ) ;
V_54 &= ~ ( 1 << V_35 ) ;
if ( V_37 -> V_59 . V_60 . V_55 [ V_35 ] == V_14 -> V_40 + V_35 ) {
V_37 -> V_59 . V_60 . V_63 [ V_35 ] = V_14 -> V_10 . V_31 ;
V_37 -> V_59 . V_60 . V_55 [ V_35 ] = NULL ;
}
F_19 ( V_14 -> V_40 + V_35 , V_37 -> V_59 . V_60 . V_61 + V_35 ) ;
if ( ! V_37 -> V_59 . V_60 . V_61 [ V_35 ] . V_36 )
V_50 |= 1 << V_35 ;
}
V_37 -> V_56 &= ~ V_50 ;
V_14 = V_37 ;
V_37 = V_14 -> V_38 ;
}
if ( V_14 -> V_57 == V_62 && V_50 )
F_24 ( V_6 , V_14 , V_50 ) ;
}
static inline long F_27 ( const struct V_1 * V_14 )
{
if ( V_64 )
return V_14 -> V_57 != V_65 ? - V_14 -> V_66 : 0 ;
else
return 0 ;
}
static inline long F_28 ( const struct V_1 * V_14 )
{
if ( V_64 )
return V_14 -> V_57 == V_62 ? - V_14 -> V_67 : 0 ;
else
return 0 ;
}
static inline enum V_68
F_29 ( struct V_1 * V_14 , long * V_69 )
{
long V_70 ;
if ( ( V_70 = ( V_14 -> V_71 + * V_69 ) ) < F_27 ( V_14 ) ) {
* V_69 = - V_70 ;
return V_65 ;
}
if ( ( V_70 = ( V_14 -> V_72 + * V_69 ) ) >= F_28 ( V_14 ) )
return V_62 ;
* V_69 = - V_70 ;
return V_58 ;
}
static void
F_30 ( struct V_5 * V_6 , struct V_1 * V_14 , long * V_69 )
{
enum V_68 V_73 = F_29 ( V_14 , V_69 ) ;
if ( V_73 == V_14 -> V_57 )
return;
if ( V_14 -> V_56 ) {
if ( V_14 -> V_57 != V_65 )
F_26 ( V_6 , V_14 ) ;
V_14 -> V_57 = V_73 ;
if ( V_73 != V_65 )
F_25 ( V_6 , V_14 ) ;
} else
V_14 -> V_57 = V_73 ;
}
static inline void F_31 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_21 ( V_14 -> V_22 || ! V_14 -> V_59 . V_74 . V_6 || ! V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 ) ;
if ( ! V_14 -> V_56 ) {
V_14 -> V_56 = 1 << V_14 -> V_35 ;
F_25 ( V_6 , V_14 ) ;
F_32 ( & V_14 -> V_59 . V_74 . V_76 ,
V_6 -> V_77 + V_14 -> V_35 ) ;
}
}
static inline void F_33 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_21 ( ! V_14 -> V_56 ) ;
F_26 ( V_6 , V_14 ) ;
V_14 -> V_56 = 0 ;
F_34 ( & V_14 -> V_59 . V_74 . V_76 ) ;
}
static int F_35 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
int V_78 ( V_79 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = F_5 ( V_12 , V_4 , & V_79 ) ;
if ( V_14 == V_21 ) {
if ( V_6 -> V_80 . V_75 < V_6 -> V_81 ) {
F_36 ( & V_6 -> V_80 , V_12 ) ;
V_6 -> V_82 ++ ;
} else {
return F_37 ( V_12 , V_4 ) ;
}
#ifdef F_7
} else if ( ! V_14 ) {
if ( V_79 & V_24 )
V_4 -> V_83 . V_77 ++ ;
F_38 ( V_12 ) ;
return V_79 ;
#endif
} else if ( ( V_79 = F_39 ( V_12 , V_14 -> V_59 . V_74 . V_6 ) ) != V_23 ) {
if ( F_40 ( V_79 ) ) {
V_4 -> V_83 . V_77 ++ ;
V_14 -> V_83 . V_77 ++ ;
}
return V_79 ;
} else {
F_31 ( V_6 , V_14 ) ;
}
V_4 -> V_6 . V_75 ++ ;
return V_23 ;
}
static inline void F_41 ( struct V_1 * V_14 , int V_84 , long V_69 )
{
long V_70 = V_69 + V_14 -> V_72 ;
if ( V_70 > V_14 -> V_67 )
V_70 = V_14 -> V_67 ;
V_70 -= ( long ) F_42 ( V_14 -> V_85 , V_84 ) ;
if ( V_70 <= - V_14 -> V_86 )
V_70 = 1 - V_14 -> V_86 ;
V_14 -> V_72 = V_70 ;
}
static inline void F_43 ( struct V_1 * V_14 , int V_84 , long V_69 )
{
long V_70 = V_69 + V_14 -> V_71 ;
if ( V_70 > V_14 -> V_66 )
V_70 = V_14 -> V_66 ;
V_70 -= ( long ) F_42 ( V_14 -> ceil , V_84 ) ;
if ( V_70 <= - V_14 -> V_86 )
V_70 = 1 - V_14 -> V_86 ;
V_14 -> V_71 = V_70 ;
}
static void F_44 ( struct V_5 * V_6 , struct V_1 * V_14 ,
int V_22 , struct V_11 * V_12 )
{
int V_84 = F_45 ( V_12 ) ;
enum V_68 V_87 ;
long V_69 ;
while ( V_14 ) {
V_69 = F_46 ( V_6 -> V_46 , V_14 -> V_88 , V_14 -> V_86 ) ;
if ( V_14 -> V_22 >= V_22 ) {
if ( V_14 -> V_22 == V_22 )
V_14 -> V_89 . V_90 ++ ;
F_41 ( V_14 , V_84 , V_69 ) ;
} else {
V_14 -> V_89 . V_91 ++ ;
V_14 -> V_72 += V_69 ;
}
F_43 ( V_14 , V_84 , V_69 ) ;
V_14 -> V_88 = V_6 -> V_46 ;
V_87 = V_14 -> V_57 ;
V_69 = 0 ;
F_30 ( V_6 , V_14 , & V_69 ) ;
if ( V_87 != V_14 -> V_57 ) {
if ( V_87 != V_62 )
F_19 ( & V_14 -> V_48 , V_6 -> V_44 + V_14 -> V_22 ) ;
if ( V_14 -> V_57 != V_62 )
F_14 ( V_6 , V_14 , V_69 ) ;
}
if ( V_14 -> V_22 )
F_47 ( & V_14 -> V_92 , V_12 ) ;
V_14 = V_14 -> V_38 ;
}
}
static T_2 F_48 ( struct V_5 * V_6 , int V_22 ,
unsigned long V_93 )
{
unsigned long V_94 = V_93 + 2 ;
while ( F_49 ( V_95 , V_94 ) ) {
struct V_1 * V_14 ;
long V_69 ;
struct V_36 * V_37 = F_50 ( & V_6 -> V_44 [ V_22 ] ) ;
if ( ! V_37 )
return 0 ;
V_14 = F_11 ( V_37 , struct V_1 , V_48 ) ;
if ( V_14 -> V_45 > V_6 -> V_46 )
return V_14 -> V_45 ;
F_19 ( V_37 , V_6 -> V_44 + V_22 ) ;
V_69 = F_46 ( V_6 -> V_46 , V_14 -> V_88 , V_14 -> V_86 ) ;
F_30 ( V_6 , V_14 , & V_69 ) ;
if ( V_14 -> V_57 != V_62 )
F_14 ( V_6 , V_14 , V_69 ) ;
}
if ( ! ( V_6 -> V_96 & V_97 ) ) {
F_51 ( L_1 ) ;
V_6 -> V_96 |= V_97 ;
}
return V_6 -> V_46 ;
}
static struct V_36 * F_52 ( int V_35 , struct V_36 * V_49 ,
T_1 V_98 )
{
struct V_36 * V_99 = NULL ;
while ( V_49 ) {
struct V_1 * V_14 =
F_11 ( V_49 , struct V_1 , V_40 [ V_35 ] ) ;
if ( V_98 > V_14 -> V_10 . V_31 ) {
V_49 = V_49 -> V_41 ;
} else if ( V_98 < V_14 -> V_10 . V_31 ) {
V_99 = V_49 ;
V_49 = V_49 -> V_42 ;
} else {
return V_49 ;
}
}
return V_99 ;
}
static struct V_1 * F_53 ( struct V_33 * V_100 , int V_35 ,
struct V_36 * * V_101 , T_1 * V_102 )
{
int V_103 ;
struct {
struct V_36 * V_34 ;
struct V_36 * * V_101 ;
T_1 * V_102 ;
} V_104 [ V_105 ] , * V_106 = V_104 ;
F_54 ( ! V_100 -> V_36 ) ;
V_106 -> V_34 = V_100 -> V_36 ;
V_106 -> V_101 = V_101 ;
V_106 -> V_102 = V_102 ;
for ( V_103 = 0 ; V_103 < 65535 ; V_103 ++ ) {
if ( ! * V_106 -> V_101 && * V_106 -> V_102 ) {
* V_106 -> V_101 =
F_52 ( V_35 , V_106 -> V_34 , * V_106 -> V_102 ) ;
}
* V_106 -> V_102 = 0 ;
if ( ! * V_106 -> V_101 ) {
* V_106 -> V_101 = V_106 -> V_34 ;
while ( ( * V_106 -> V_101 ) -> V_42 )
* V_106 -> V_101 = ( * V_106 -> V_101 ) -> V_42 ;
if ( V_106 > V_104 ) {
V_106 -- ;
if ( ! * V_106 -> V_101 ) {
F_21 ( 1 ) ;
return NULL ;
}
F_15 ( V_106 -> V_101 ) ;
}
} else {
struct V_1 * V_14 ;
V_14 = F_11 ( * V_106 -> V_101 , struct V_1 , V_40 [ V_35 ] ) ;
if ( ! V_14 -> V_22 )
return V_14 ;
( ++ V_106 ) -> V_34 = V_14 -> V_59 . V_60 . V_61 [ V_35 ] . V_36 ;
V_106 -> V_101 = V_14 -> V_59 . V_60 . V_55 + V_35 ;
V_106 -> V_102 = V_14 -> V_59 . V_60 . V_63 + V_35 ;
}
}
F_21 ( 1 ) ;
return NULL ;
}
static struct V_11 * F_55 ( struct V_5 * V_6 , int V_35 ,
int V_22 )
{
struct V_11 * V_12 = NULL ;
struct V_1 * V_14 , * V_93 ;
V_93 = V_14 = F_53 ( V_6 -> V_52 [ V_22 ] + V_35 , V_35 ,
V_6 -> V_55 [ V_22 ] + V_35 ,
V_6 -> V_63 [ V_22 ] + V_35 ) ;
do {
V_107:
if ( F_56 ( ! V_14 ) )
return NULL ;
if ( F_56 ( V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 == 0 ) ) {
struct V_1 * V_107 ;
F_33 ( V_6 , V_14 ) ;
if ( ( V_6 -> V_51 [ V_22 ] & ( 1 << V_35 ) ) == 0 )
return NULL ;
V_107 = F_53 ( V_6 -> V_52 [ V_22 ] + V_35 ,
V_35 , V_6 -> V_55 [ V_22 ] + V_35 ,
V_6 -> V_63 [ V_22 ] + V_35 ) ;
if ( V_14 == V_93 )
V_93 = V_107 ;
V_14 = V_107 ;
goto V_107;
}
V_12 = V_14 -> V_59 . V_74 . V_6 -> V_108 ( V_14 -> V_59 . V_74 . V_6 ) ;
if ( F_57 ( V_12 != NULL ) )
break;
F_58 ( L_2 , V_14 -> V_59 . V_74 . V_6 ) ;
F_15 ( ( V_22 ? V_14 -> V_38 -> V_59 . V_60 . V_55 : V_6 ->
V_55 [ 0 ] ) + V_35 ) ;
V_14 = F_53 ( V_6 -> V_52 [ V_22 ] + V_35 , V_35 ,
V_6 -> V_55 [ V_22 ] + V_35 ,
V_6 -> V_63 [ V_22 ] + V_35 ) ;
} while ( V_14 != V_93 );
if ( F_57 ( V_12 != NULL ) ) {
F_47 ( & V_14 -> V_92 , V_12 ) ;
V_14 -> V_59 . V_74 . V_109 [ V_22 ] -= F_45 ( V_12 ) ;
if ( V_14 -> V_59 . V_74 . V_109 [ V_22 ] < 0 ) {
V_14 -> V_59 . V_74 . V_109 [ V_22 ] += V_14 -> V_110 ;
F_15 ( ( V_22 ? V_14 -> V_38 -> V_59 . V_60 . V_55 : V_6 ->
V_55 [ 0 ] ) + V_35 ) ;
}
if ( ! V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 )
F_33 ( V_6 , V_14 ) ;
F_44 ( V_6 , V_14 , V_22 , V_12 ) ;
}
return V_12 ;
}
static struct V_11 * F_59 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_22 ;
T_2 V_111 ;
unsigned long V_112 ;
V_12 = F_60 ( & V_6 -> V_80 ) ;
if ( V_12 != NULL ) {
V_113:
F_61 ( V_4 , V_12 ) ;
F_62 ( V_4 ) ;
V_4 -> V_6 . V_75 -- ;
return V_12 ;
}
if ( ! V_4 -> V_6 . V_75 )
goto V_114;
V_6 -> V_46 = F_63 () ;
V_112 = V_95 ;
V_111 = V_6 -> V_46 + 5 * V_115 ;
for ( V_22 = 0 ; V_22 < V_105 ; V_22 ++ ) {
int V_54 ;
T_2 V_116 ;
if ( V_6 -> V_46 >= V_6 -> V_47 [ V_22 ] ) {
V_116 = F_48 ( V_6 , V_22 , V_112 ) ;
if ( ! V_116 )
V_116 = V_6 -> V_46 + V_115 ;
V_6 -> V_47 [ V_22 ] = V_116 ;
} else
V_116 = V_6 -> V_47 [ V_22 ] ;
if ( V_111 > V_116 )
V_111 = V_116 ;
V_54 = ~ V_6 -> V_51 [ V_22 ] ;
while ( V_54 != ( int ) ( - 1 ) ) {
int V_35 = F_18 ( V_54 ) ;
V_54 |= 1 << V_35 ;
V_12 = F_55 ( V_6 , V_35 , V_22 ) ;
if ( F_57 ( V_12 != NULL ) )
goto V_113;
}
}
V_4 -> V_83 . V_117 ++ ;
if ( F_57 ( V_111 > V_6 -> V_46 ) )
F_64 ( & V_6 -> V_118 , V_111 ) ;
else
F_65 ( & V_6 -> V_119 ) ;
V_114:
return V_12 ;
}
static unsigned int F_66 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_35 ;
for ( V_35 = V_120 - 1 ; V_35 >= 0 ; V_35 -- ) {
struct V_121 * V_37 ;
F_67 (p, q->drops + prio) {
struct V_1 * V_14 = F_68 ( V_37 , struct V_1 ,
V_59 . V_74 . V_76 ) ;
unsigned int V_122 ;
if ( V_14 -> V_59 . V_74 . V_6 -> V_123 -> V_124 &&
( V_122 = V_14 -> V_59 . V_74 . V_6 -> V_123 -> V_124 ( V_14 -> V_59 . V_74 . V_6 ) ) ) {
V_4 -> V_6 . V_75 -- ;
if ( ! V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 )
F_33 ( V_6 , V_14 ) ;
return V_122 ;
}
}
}
return 0 ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
struct V_125 * V_49 ;
unsigned int V_103 ;
for ( V_103 = 0 ; V_103 < V_6 -> V_9 . V_126 ; V_103 ++ ) {
F_70 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_14 -> V_22 )
memset ( & V_14 -> V_59 . V_60 , 0 , sizeof( V_14 -> V_59 . V_60 ) ) ;
else {
if ( V_14 -> V_59 . V_74 . V_6 )
F_71 ( V_14 -> V_59 . V_74 . V_6 ) ;
F_72 ( & V_14 -> V_59 . V_74 . V_76 ) ;
}
V_14 -> V_56 = 0 ;
V_14 -> V_57 = V_62 ;
}
}
F_73 ( & V_6 -> V_118 ) ;
F_74 ( & V_6 -> V_80 ) ;
V_4 -> V_6 . V_75 = 0 ;
memset ( V_6 -> V_52 , 0 , sizeof( V_6 -> V_52 ) ) ;
memset ( V_6 -> V_51 , 0 , sizeof( V_6 -> V_51 ) ) ;
memset ( V_6 -> V_44 , 0 , sizeof( V_6 -> V_44 ) ) ;
memset ( V_6 -> V_55 , 0 , sizeof( V_6 -> V_55 ) ) ;
for ( V_103 = 0 ; V_103 < V_120 ; V_103 ++ )
F_72 ( V_6 -> V_77 + V_103 ) ;
}
static void F_75 ( struct V_127 * V_119 )
{
struct V_5 * V_6 = F_4 ( V_119 , struct V_5 , V_119 ) ;
struct V_3 * V_4 = V_6 -> V_118 . V_128 ;
F_76 ( F_77 ( V_4 ) ) ;
}
static int F_78 ( struct V_3 * V_4 , struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_129 * V_131 [ V_132 + 1 ] ;
struct V_133 * V_134 ;
int V_135 ;
int V_103 ;
if ( ! V_130 )
return - V_136 ;
V_135 = F_79 ( V_131 , V_132 , V_130 , V_137 ) ;
if ( V_135 < 0 )
return V_135 ;
if ( V_131 [ V_132 ] == NULL ) {
F_80 ( L_3 ) ;
return - V_136 ;
}
V_134 = F_81 ( V_131 [ V_132 ] ) ;
if ( V_134 -> V_138 != V_139 >> 16 ) {
F_80 ( L_4 ,
V_139 >> 16 , V_139 & 0xffff , V_134 -> V_138 ) ;
return - V_136 ;
}
V_135 = F_82 ( & V_6 -> V_9 ) ;
if ( V_135 < 0 )
return V_135 ;
for ( V_103 = 0 ; V_103 < V_120 ; V_103 ++ )
F_72 ( V_6 -> V_77 + V_103 ) ;
F_83 ( & V_6 -> V_118 , V_4 ) ;
F_84 ( & V_6 -> V_119 , F_75 ) ;
F_85 ( & V_6 -> V_80 ) ;
V_6 -> V_81 = F_86 ( V_4 ) -> V_140 ;
if ( V_6 -> V_81 < 2 )
V_6 -> V_81 = 2 ;
if ( ( V_6 -> V_141 = V_134 -> V_141 ) < 1 )
V_6 -> V_141 = 1 ;
V_6 -> V_32 = V_134 -> V_32 ;
return 0 ;
}
static int F_87 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
T_3 * V_142 = F_88 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_129 * V_143 ;
struct V_133 V_134 ;
F_89 ( V_142 ) ;
V_134 . V_82 = V_6 -> V_82 ;
V_134 . V_138 = V_139 ;
V_134 . V_141 = V_6 -> V_141 ;
V_134 . V_32 = V_6 -> V_32 ;
V_134 . V_144 = 0 ;
V_143 = F_90 ( V_12 , V_145 ) ;
if ( V_143 == NULL )
goto V_146;
if ( F_91 ( V_12 , V_132 , sizeof( V_134 ) , & V_134 ) )
goto V_146;
F_92 ( V_12 , V_143 ) ;
F_93 ( V_142 ) ;
return V_12 -> V_122 ;
V_146:
F_93 ( V_142 ) ;
F_94 ( V_12 , V_143 ) ;
return - 1 ;
}
static int F_95 ( struct V_3 * V_4 , unsigned long V_147 ,
struct V_11 * V_12 , struct V_148 * V_149 )
{
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
T_3 * V_142 = F_88 ( V_4 ) ;
struct V_129 * V_143 ;
struct V_150 V_130 ;
F_89 ( V_142 ) ;
V_149 -> V_151 = V_14 -> V_38 ? V_14 -> V_38 -> V_10 . V_31 : V_152 ;
V_149 -> V_153 = V_14 -> V_10 . V_31 ;
if ( ! V_14 -> V_22 && V_14 -> V_59 . V_74 . V_6 )
V_149 -> V_154 = V_14 -> V_59 . V_74 . V_6 -> V_2 ;
V_143 = F_90 ( V_12 , V_145 ) ;
if ( V_143 == NULL )
goto V_146;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . V_85 = V_14 -> V_85 -> V_85 ;
V_130 . V_67 = V_14 -> V_67 ;
V_130 . ceil = V_14 -> ceil -> V_85 ;
V_130 . V_66 = V_14 -> V_66 ;
V_130 . V_110 = V_14 -> V_110 ;
V_130 . V_35 = V_14 -> V_35 ;
V_130 . V_22 = V_14 -> V_22 ;
if ( F_91 ( V_12 , V_155 , sizeof( V_130 ) , & V_130 ) )
goto V_146;
F_92 ( V_12 , V_143 ) ;
F_93 ( V_142 ) ;
return V_12 -> V_122 ;
V_146:
F_93 ( V_142 ) ;
F_94 ( V_12 , V_143 ) ;
return - 1 ;
}
static int
F_96 ( struct V_3 * V_4 , unsigned long V_147 , struct V_156 * V_157 )
{
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
if ( ! V_14 -> V_22 && V_14 -> V_59 . V_74 . V_6 )
V_14 -> V_83 . V_75 = V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 ;
V_14 -> V_89 . V_72 = V_14 -> V_72 ;
V_14 -> V_89 . V_71 = V_14 -> V_71 ;
if ( F_97 ( V_157 , & V_14 -> V_92 ) < 0 ||
F_98 ( V_157 , NULL , & V_14 -> V_158 ) < 0 ||
F_99 ( V_157 , & V_14 -> V_83 ) < 0 )
return - 1 ;
return F_100 ( V_157 , & V_14 -> V_89 , sizeof( V_14 -> V_89 ) ) ;
}
static int F_101 ( struct V_3 * V_4 , unsigned long V_147 , struct V_3 * V_159 ,
struct V_3 * * V_160 )
{
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
if ( V_14 -> V_22 )
return - V_136 ;
if ( V_159 == NULL &&
( V_159 = F_102 ( V_4 -> V_161 , & V_162 ,
V_14 -> V_10 . V_31 ) ) == NULL )
return - V_163 ;
F_103 ( V_4 ) ;
* V_160 = V_14 -> V_59 . V_74 . V_6 ;
V_14 -> V_59 . V_74 . V_6 = V_159 ;
if ( * V_160 != NULL ) {
F_104 ( * V_160 , ( * V_160 ) -> V_6 . V_75 ) ;
F_71 ( * V_160 ) ;
}
F_105 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_106 ( struct V_3 * V_4 , unsigned long V_147 )
{
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
return ! V_14 -> V_22 ? V_14 -> V_59 . V_74 . V_6 : NULL ;
}
static void F_107 ( struct V_3 * V_4 , unsigned long V_147 )
{
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
if ( V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 == 0 )
F_33 ( F_2 ( V_4 ) , V_14 ) ;
}
static unsigned long F_108 ( struct V_3 * V_4 , T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_164 ++ ;
return ( unsigned long ) V_14 ;
}
static inline int F_109 ( struct V_1 * V_14 )
{
if ( ! V_14 -> V_38 )
return 0 ;
if ( V_14 -> V_38 -> V_165 > 1 )
return 0 ;
return 1 ;
}
static void F_110 ( struct V_5 * V_6 , struct V_1 * V_14 ,
struct V_3 * V_166 )
{
struct V_1 * V_38 = V_14 -> V_38 ;
F_21 ( V_14 -> V_22 || ! V_14 -> V_59 . V_74 . V_6 || V_14 -> V_56 ) ;
if ( V_38 -> V_57 != V_62 )
F_19 ( & V_38 -> V_48 , V_6 -> V_44 + V_38 -> V_22 ) ;
V_38 -> V_22 = 0 ;
memset ( & V_38 -> V_59 . V_60 , 0 , sizeof( V_38 -> V_59 . V_60 ) ) ;
F_72 ( & V_38 -> V_59 . V_74 . V_76 ) ;
V_38 -> V_59 . V_74 . V_6 = V_166 ? V_166 : & V_167 ;
V_38 -> V_72 = V_38 -> V_67 ;
V_38 -> V_71 = V_38 -> V_66 ;
V_38 -> V_88 = F_63 () ;
V_38 -> V_57 = V_62 ;
}
static void F_111 ( struct V_3 * V_4 , struct V_1 * V_14 )
{
if ( ! V_14 -> V_22 ) {
F_21 ( ! V_14 -> V_59 . V_74 . V_6 ) ;
F_112 ( V_14 -> V_59 . V_74 . V_6 ) ;
}
F_113 ( & V_14 -> V_92 , & V_14 -> V_158 ) ;
F_114 ( V_14 -> V_85 ) ;
F_114 ( V_14 -> ceil ) ;
F_115 ( & V_14 -> V_25 ) ;
F_116 ( V_14 ) ;
}
static void F_117 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_125 * V_49 , * V_107 ;
struct V_1 * V_14 ;
unsigned int V_103 ;
F_118 ( & V_6 -> V_119 ) ;
F_73 ( & V_6 -> V_118 ) ;
F_115 ( & V_6 -> V_25 ) ;
for ( V_103 = 0 ; V_103 < V_6 -> V_9 . V_126 ; V_103 ++ ) {
F_70 (cl, n, &q->clhash.hash[i], common.hnode)
F_115 ( & V_14 -> V_25 ) ;
}
for ( V_103 = 0 ; V_103 < V_6 -> V_9 . V_126 ; V_103 ++ ) {
F_119 (cl, n, next, &q->clhash.hash[i],
common.hnode)
F_111 ( V_4 , V_14 ) ;
}
F_120 ( & V_6 -> V_9 ) ;
F_74 ( & V_6 -> V_80 ) ;
}
static int F_121 ( struct V_3 * V_4 , unsigned long V_147 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
unsigned int V_75 ;
struct V_3 * V_166 = NULL ;
int V_168 = 0 ;
if ( V_14 -> V_165 || V_14 -> V_169 )
return - V_170 ;
if ( ! V_14 -> V_22 && F_109 ( V_14 ) ) {
V_166 = F_102 ( V_4 -> V_161 , & V_162 ,
V_14 -> V_38 -> V_10 . V_31 ) ;
V_168 = 1 ;
}
F_103 ( V_4 ) ;
if ( ! V_14 -> V_22 ) {
V_75 = V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 ;
F_71 ( V_14 -> V_59 . V_74 . V_6 ) ;
F_104 ( V_14 -> V_59 . V_74 . V_6 , V_75 ) ;
}
F_122 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_14 -> V_38 )
V_14 -> V_38 -> V_165 -- ;
if ( V_14 -> V_56 )
F_33 ( V_6 , V_14 ) ;
if ( V_14 -> V_57 != V_62 )
F_19 ( & V_14 -> V_48 , V_6 -> V_44 + V_14 -> V_22 ) ;
if ( V_168 )
F_110 ( V_6 , V_14 , V_166 ) ;
F_54 ( -- V_14 -> V_164 == 0 ) ;
F_105 ( V_4 ) ;
return 0 ;
}
static void F_123 ( struct V_3 * V_4 , unsigned long V_147 )
{
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
if ( -- V_14 -> V_164 == 0 )
F_111 ( V_4 , V_14 ) ;
}
static int F_124 ( struct V_3 * V_4 , T_1 V_31 ,
T_1 V_171 , struct V_129 * * V_172 ,
unsigned long * V_147 )
{
int V_135 = - V_136 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) * V_147 , * V_38 ;
struct V_129 * V_130 = V_172 [ V_145 ] ;
struct V_173 * V_174 = NULL , * V_175 = NULL ;
struct V_129 * V_131 [ V_176 ] ;
struct V_150 * V_177 ;
if ( ! V_130 )
goto V_178;
V_135 = F_79 ( V_131 , V_179 , V_130 , V_137 ) ;
if ( V_135 < 0 )
goto V_178;
V_135 = - V_136 ;
if ( V_131 [ V_155 ] == NULL )
goto V_178;
V_38 = V_171 == V_152 ? NULL : F_1 ( V_171 , V_4 ) ;
V_177 = F_81 ( V_131 [ V_155 ] ) ;
V_174 = F_125 ( & V_177 -> V_85 , V_131 [ V_180 ] ) ;
V_175 = F_125 ( & V_177 -> ceil , V_131 [ V_181 ] ) ;
if ( ! V_174 || ! V_175 )
goto V_178;
if ( ! V_14 ) {
struct V_3 * V_166 ;
int V_35 ;
struct {
struct V_129 V_182 ;
struct V_183 V_130 ;
} V_184 = {
. V_182 = {
. V_185 = F_126 ( sizeof( V_184 . V_130 ) ) ,
. V_186 = V_187 ,
} ,
. V_130 = {
. V_188 = 2 ,
. V_189 = 2 ,
} ,
} ;
if ( ! V_31 || F_9 ( V_31 ^ V_4 -> V_2 ) ||
F_1 ( V_31 , V_4 ) )
goto V_178;
if ( V_38 && V_38 -> V_38 && V_38 -> V_38 -> V_22 < 2 ) {
F_80 ( L_5 ) ;
goto V_178;
}
V_135 = - V_163 ;
V_14 = F_127 ( sizeof( * V_14 ) , V_190 ) ;
if ( ! V_14 )
goto V_178;
V_135 = F_128 ( & V_14 -> V_92 , & V_14 -> V_158 ,
F_88 ( V_4 ) ,
V_172 [ V_187 ] ? : & V_184 . V_182 ) ;
if ( V_135 ) {
F_116 ( V_14 ) ;
goto V_178;
}
V_14 -> V_164 = 1 ;
V_14 -> V_165 = 0 ;
F_72 ( & V_14 -> V_59 . V_74 . V_76 ) ;
F_23 ( & V_14 -> V_48 ) ;
for ( V_35 = 0 ; V_35 < V_120 ; V_35 ++ )
F_23 ( & V_14 -> V_40 [ V_35 ] ) ;
V_166 = F_102 ( V_4 -> V_161 ,
& V_162 , V_31 ) ;
F_103 ( V_4 ) ;
if ( V_38 && ! V_38 -> V_22 ) {
unsigned int V_75 = V_38 -> V_59 . V_74 . V_6 -> V_6 . V_75 ;
F_71 ( V_38 -> V_59 . V_74 . V_6 ) ;
F_104 ( V_38 -> V_59 . V_74 . V_6 , V_75 ) ;
F_112 ( V_38 -> V_59 . V_74 . V_6 ) ;
if ( V_38 -> V_56 )
F_33 ( V_6 , V_38 ) ;
if ( V_38 -> V_57 != V_62 ) {
F_19 ( & V_38 -> V_48 , V_6 -> V_44 ) ;
V_38 -> V_57 = V_62 ;
}
V_38 -> V_22 = ( V_38 -> V_38 ? V_38 -> V_38 -> V_22
: V_105 ) - 1 ;
memset ( & V_38 -> V_59 . V_60 , 0 , sizeof( V_38 -> V_59 . V_60 ) ) ;
}
V_14 -> V_59 . V_74 . V_6 = V_166 ? V_166 : & V_167 ;
V_14 -> V_10 . V_31 = V_31 ;
V_14 -> V_38 = V_38 ;
V_14 -> V_72 = V_177 -> V_67 ;
V_14 -> V_71 = V_177 -> V_66 ;
V_14 -> V_86 = 60 * V_115 ;
V_14 -> V_88 = F_63 () ;
V_14 -> V_57 = V_62 ;
F_129 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_38 )
V_38 -> V_165 ++ ;
} else {
if ( V_172 [ V_187 ] ) {
V_135 = F_130 ( & V_14 -> V_92 , & V_14 -> V_158 ,
F_88 ( V_4 ) ,
V_172 [ V_187 ] ) ;
if ( V_135 )
return V_135 ;
}
F_103 ( V_4 ) ;
}
if ( ! V_14 -> V_22 ) {
V_14 -> V_110 = V_174 -> V_85 . V_85 / V_6 -> V_141 ;
if ( ! V_177 -> V_110 && V_14 -> V_110 < 1000 ) {
F_51 (
L_6 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_110 = 1000 ;
}
if ( ! V_177 -> V_110 && V_14 -> V_110 > 200000 ) {
F_51 (
L_7 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_110 = 200000 ;
}
if ( V_177 -> V_110 )
V_14 -> V_110 = V_177 -> V_110 ;
if ( ( V_14 -> V_35 = V_177 -> V_35 ) >= V_120 )
V_14 -> V_35 = V_120 - 1 ;
}
V_14 -> V_67 = V_177 -> V_67 ;
V_14 -> V_66 = V_177 -> V_66 ;
if ( V_14 -> V_85 )
F_114 ( V_14 -> V_85 ) ;
V_14 -> V_85 = V_174 ;
if ( V_14 -> ceil )
F_114 ( V_14 -> ceil ) ;
V_14 -> ceil = V_175 ;
F_105 ( V_4 ) ;
F_131 ( V_4 , & V_6 -> V_9 ) ;
* V_147 = ( unsigned long ) V_14 ;
return 0 ;
V_178:
if ( V_174 )
F_114 ( V_174 ) ;
if ( V_175 )
F_114 ( V_175 ) ;
return V_135 ;
}
static struct V_17 * * F_132 ( struct V_3 * V_4 , unsigned long V_147 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
struct V_17 * * V_191 = V_14 ? & V_14 -> V_25 : & V_6 -> V_25 ;
return V_191 ;
}
static unsigned long F_133 ( struct V_3 * V_4 , unsigned long V_38 ,
T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_169 ++ ;
return ( unsigned long ) V_14 ;
}
static void F_134 ( struct V_3 * V_4 , unsigned long V_147 )
{
struct V_1 * V_14 = (struct V_1 * ) V_147 ;
if ( V_14 )
V_14 -> V_169 -- ;
}
static void F_135 ( struct V_3 * V_4 , struct V_192 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
struct V_125 * V_49 ;
unsigned int V_103 ;
if ( V_147 -> V_193 )
return;
for ( V_103 = 0 ; V_103 < V_6 -> V_9 . V_126 ; V_103 ++ ) {
F_70 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_147 -> V_194 < V_147 -> V_195 ) {
V_147 -> V_194 ++ ;
continue;
}
if ( V_147 -> V_196 ( V_4 , ( unsigned long ) V_14 , V_147 ) < 0 ) {
V_147 -> V_193 = 1 ;
return;
}
V_147 -> V_194 ++ ;
}
}
}
static int T_4 F_136 ( void )
{
return F_137 ( & V_197 ) ;
}
static void T_5 F_138 ( void )
{
F_139 ( & V_197 ) ;
}
