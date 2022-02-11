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
F_37 ( V_12 ) ;
V_4 -> V_83 . V_77 ++ ;
return V_84 ;
}
#ifdef F_7
} else if ( ! V_14 ) {
if ( V_79 & V_24 )
V_4 -> V_83 . V_77 ++ ;
F_37 ( V_12 ) ;
return V_79 ;
#endif
} else if ( ( V_79 = F_38 ( V_12 , V_14 -> V_59 . V_74 . V_6 ) ) != V_23 ) {
if ( F_39 ( V_79 ) ) {
V_4 -> V_83 . V_77 ++ ;
V_14 -> V_83 . V_77 ++ ;
}
return V_79 ;
} else {
F_40 ( & V_14 -> V_85 , V_12 ) ;
F_31 ( V_6 , V_14 ) ;
}
V_4 -> V_6 . V_75 ++ ;
return V_23 ;
}
static inline void F_41 ( struct V_1 * V_14 , int V_86 , long V_69 )
{
long V_70 = V_69 + V_14 -> V_72 ;
if ( V_70 > V_14 -> V_67 )
V_70 = V_14 -> V_67 ;
V_70 -= ( long ) F_42 ( V_14 -> V_87 , V_86 ) ;
if ( V_70 <= - V_14 -> V_88 )
V_70 = 1 - V_14 -> V_88 ;
V_14 -> V_72 = V_70 ;
}
static inline void F_43 ( struct V_1 * V_14 , int V_86 , long V_69 )
{
long V_70 = V_69 + V_14 -> V_71 ;
if ( V_70 > V_14 -> V_66 )
V_70 = V_14 -> V_66 ;
V_70 -= ( long ) F_42 ( V_14 -> ceil , V_86 ) ;
if ( V_70 <= - V_14 -> V_88 )
V_70 = 1 - V_14 -> V_88 ;
V_14 -> V_71 = V_70 ;
}
static void F_44 ( struct V_5 * V_6 , struct V_1 * V_14 ,
int V_22 , struct V_11 * V_12 )
{
int V_86 = F_45 ( V_12 ) ;
enum V_68 V_89 ;
long V_69 ;
while ( V_14 ) {
V_69 = F_46 ( V_6 -> V_46 , V_14 -> V_90 , V_14 -> V_88 ) ;
if ( V_14 -> V_22 >= V_22 ) {
if ( V_14 -> V_22 == V_22 )
V_14 -> V_91 . V_92 ++ ;
F_41 ( V_14 , V_86 , V_69 ) ;
} else {
V_14 -> V_91 . V_93 ++ ;
V_14 -> V_72 += V_69 ;
}
F_43 ( V_14 , V_86 , V_69 ) ;
V_14 -> V_90 = V_6 -> V_46 ;
V_89 = V_14 -> V_57 ;
V_69 = 0 ;
F_30 ( V_6 , V_14 , & V_69 ) ;
if ( V_89 != V_14 -> V_57 ) {
if ( V_89 != V_62 )
F_19 ( & V_14 -> V_48 , V_6 -> V_44 + V_14 -> V_22 ) ;
if ( V_14 -> V_57 != V_62 )
F_14 ( V_6 , V_14 , V_69 ) ;
}
if ( V_14 -> V_22 )
F_40 ( & V_14 -> V_85 , V_12 ) ;
V_14 = V_14 -> V_38 ;
}
}
static T_2 F_47 ( struct V_5 * V_6 , int V_22 ,
unsigned long V_94 )
{
unsigned long V_95 = V_94 + 2 ;
while ( F_48 ( V_96 , V_95 ) ) {
struct V_1 * V_14 ;
long V_69 ;
struct V_36 * V_37 = F_49 ( & V_6 -> V_44 [ V_22 ] ) ;
if ( ! V_37 )
return 0 ;
V_14 = F_11 ( V_37 , struct V_1 , V_48 ) ;
if ( V_14 -> V_45 > V_6 -> V_46 )
return V_14 -> V_45 ;
F_19 ( V_37 , V_6 -> V_44 + V_22 ) ;
V_69 = F_46 ( V_6 -> V_46 , V_14 -> V_90 , V_14 -> V_88 ) ;
F_30 ( V_6 , V_14 , & V_69 ) ;
if ( V_14 -> V_57 != V_62 )
F_14 ( V_6 , V_14 , V_69 ) ;
}
if ( ! ( V_6 -> V_97 & V_98 ) ) {
F_50 ( L_1 ) ;
V_6 -> V_97 |= V_98 ;
}
return V_6 -> V_46 ;
}
static struct V_36 * F_51 ( int V_35 , struct V_36 * V_49 ,
T_1 V_99 )
{
struct V_36 * V_100 = NULL ;
while ( V_49 ) {
struct V_1 * V_14 =
F_11 ( V_49 , struct V_1 , V_40 [ V_35 ] ) ;
if ( V_99 > V_14 -> V_10 . V_31 ) {
V_49 = V_49 -> V_41 ;
} else if ( V_99 < V_14 -> V_10 . V_31 ) {
V_100 = V_49 ;
V_49 = V_49 -> V_42 ;
} else {
return V_49 ;
}
}
return V_100 ;
}
static struct V_1 * F_52 ( struct V_33 * V_101 , int V_35 ,
struct V_36 * * V_102 , T_1 * V_103 )
{
int V_104 ;
struct {
struct V_36 * V_34 ;
struct V_36 * * V_102 ;
T_1 * V_103 ;
} V_105 [ V_106 ] , * V_107 = V_105 ;
F_53 ( ! V_101 -> V_36 ) ;
V_107 -> V_34 = V_101 -> V_36 ;
V_107 -> V_102 = V_102 ;
V_107 -> V_103 = V_103 ;
for ( V_104 = 0 ; V_104 < 65535 ; V_104 ++ ) {
if ( ! * V_107 -> V_102 && * V_107 -> V_103 ) {
* V_107 -> V_102 =
F_51 ( V_35 , V_107 -> V_34 , * V_107 -> V_103 ) ;
}
* V_107 -> V_103 = 0 ;
if ( ! * V_107 -> V_102 ) {
* V_107 -> V_102 = V_107 -> V_34 ;
while ( ( * V_107 -> V_102 ) -> V_42 )
* V_107 -> V_102 = ( * V_107 -> V_102 ) -> V_42 ;
if ( V_107 > V_105 ) {
V_107 -- ;
if ( ! * V_107 -> V_102 ) {
F_21 ( 1 ) ;
return NULL ;
}
F_15 ( V_107 -> V_102 ) ;
}
} else {
struct V_1 * V_14 ;
V_14 = F_11 ( * V_107 -> V_102 , struct V_1 , V_40 [ V_35 ] ) ;
if ( ! V_14 -> V_22 )
return V_14 ;
( ++ V_107 ) -> V_34 = V_14 -> V_59 . V_60 . V_61 [ V_35 ] . V_36 ;
V_107 -> V_102 = V_14 -> V_59 . V_60 . V_55 + V_35 ;
V_107 -> V_103 = V_14 -> V_59 . V_60 . V_63 + V_35 ;
}
}
F_21 ( 1 ) ;
return NULL ;
}
static struct V_11 * F_54 ( struct V_5 * V_6 , int V_35 ,
int V_22 )
{
struct V_11 * V_12 = NULL ;
struct V_1 * V_14 , * V_94 ;
V_94 = V_14 = F_52 ( V_6 -> V_52 [ V_22 ] + V_35 , V_35 ,
V_6 -> V_55 [ V_22 ] + V_35 ,
V_6 -> V_63 [ V_22 ] + V_35 ) ;
do {
V_108:
if ( F_55 ( ! V_14 ) )
return NULL ;
if ( F_55 ( V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 == 0 ) ) {
struct V_1 * V_108 ;
F_33 ( V_6 , V_14 ) ;
if ( ( V_6 -> V_51 [ V_22 ] & ( 1 << V_35 ) ) == 0 )
return NULL ;
V_108 = F_52 ( V_6 -> V_52 [ V_22 ] + V_35 ,
V_35 , V_6 -> V_55 [ V_22 ] + V_35 ,
V_6 -> V_63 [ V_22 ] + V_35 ) ;
if ( V_14 == V_94 )
V_94 = V_108 ;
V_14 = V_108 ;
goto V_108;
}
V_12 = V_14 -> V_59 . V_74 . V_6 -> V_109 ( V_14 -> V_59 . V_74 . V_6 ) ;
if ( F_56 ( V_12 != NULL ) )
break;
F_57 ( L_2 , V_14 -> V_59 . V_74 . V_6 ) ;
F_15 ( ( V_22 ? V_14 -> V_38 -> V_59 . V_60 . V_55 : V_6 ->
V_55 [ 0 ] ) + V_35 ) ;
V_14 = F_52 ( V_6 -> V_52 [ V_22 ] + V_35 , V_35 ,
V_6 -> V_55 [ V_22 ] + V_35 ,
V_6 -> V_63 [ V_22 ] + V_35 ) ;
} while ( V_14 != V_94 );
if ( F_56 ( V_12 != NULL ) ) {
V_14 -> V_59 . V_74 . V_110 [ V_22 ] -= F_45 ( V_12 ) ;
if ( V_14 -> V_59 . V_74 . V_110 [ V_22 ] < 0 ) {
V_14 -> V_59 . V_74 . V_110 [ V_22 ] += V_14 -> V_111 ;
F_15 ( ( V_22 ? V_14 -> V_38 -> V_59 . V_60 . V_55 : V_6 ->
V_55 [ 0 ] ) + V_35 ) ;
}
if ( ! V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 )
F_33 ( V_6 , V_14 ) ;
F_44 ( V_6 , V_14 , V_22 , V_12 ) ;
}
return V_12 ;
}
static struct V_11 * F_58 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_22 ;
T_2 V_112 ;
unsigned long V_113 ;
V_12 = F_59 ( & V_6 -> V_80 ) ;
if ( V_12 != NULL ) {
V_114:
F_60 ( V_4 , V_12 ) ;
F_61 ( V_4 ) ;
V_4 -> V_6 . V_75 -- ;
return V_12 ;
}
if ( ! V_4 -> V_6 . V_75 )
goto V_115;
V_6 -> V_46 = F_62 () ;
V_113 = V_96 ;
V_112 = V_6 -> V_46 + 5 * V_116 ;
for ( V_22 = 0 ; V_22 < V_106 ; V_22 ++ ) {
int V_54 ;
T_2 V_117 ;
if ( V_6 -> V_46 >= V_6 -> V_47 [ V_22 ] ) {
V_117 = F_47 ( V_6 , V_22 , V_113 ) ;
if ( ! V_117 )
V_117 = V_6 -> V_46 + V_116 ;
V_6 -> V_47 [ V_22 ] = V_117 ;
} else
V_117 = V_6 -> V_47 [ V_22 ] ;
if ( V_112 > V_117 )
V_112 = V_117 ;
V_54 = ~ V_6 -> V_51 [ V_22 ] ;
while ( V_54 != ( int ) ( - 1 ) ) {
int V_35 = F_18 ( V_54 ) ;
V_54 |= 1 << V_35 ;
V_12 = F_54 ( V_6 , V_35 , V_22 ) ;
if ( F_56 ( V_12 != NULL ) )
goto V_114;
}
}
V_4 -> V_83 . V_118 ++ ;
if ( F_56 ( V_112 > V_6 -> V_46 ) )
F_63 ( & V_6 -> V_119 , V_112 ) ;
else
F_64 ( & V_6 -> V_120 ) ;
V_115:
return V_12 ;
}
static unsigned int F_65 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_35 ;
for ( V_35 = V_121 - 1 ; V_35 >= 0 ; V_35 -- ) {
struct V_122 * V_37 ;
F_66 (p, q->drops + prio) {
struct V_1 * V_14 = F_67 ( V_37 , struct V_1 ,
V_59 . V_74 . V_76 ) ;
unsigned int V_123 ;
if ( V_14 -> V_59 . V_74 . V_6 -> V_124 -> V_125 &&
( V_123 = V_14 -> V_59 . V_74 . V_6 -> V_124 -> V_125 ( V_14 -> V_59 . V_74 . V_6 ) ) ) {
V_4 -> V_6 . V_75 -- ;
if ( ! V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 )
F_33 ( V_6 , V_14 ) ;
return V_123 ;
}
}
}
return 0 ;
}
static void F_68 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
struct V_126 * V_49 ;
unsigned int V_104 ;
for ( V_104 = 0 ; V_104 < V_6 -> V_9 . V_127 ; V_104 ++ ) {
F_69 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_14 -> V_22 )
memset ( & V_14 -> V_59 . V_60 , 0 , sizeof( V_14 -> V_59 . V_60 ) ) ;
else {
if ( V_14 -> V_59 . V_74 . V_6 )
F_70 ( V_14 -> V_59 . V_74 . V_6 ) ;
F_71 ( & V_14 -> V_59 . V_74 . V_76 ) ;
}
V_14 -> V_56 = 0 ;
V_14 -> V_57 = V_62 ;
}
}
F_72 ( & V_6 -> V_119 ) ;
F_73 ( & V_6 -> V_80 ) ;
V_4 -> V_6 . V_75 = 0 ;
memset ( V_6 -> V_52 , 0 , sizeof( V_6 -> V_52 ) ) ;
memset ( V_6 -> V_51 , 0 , sizeof( V_6 -> V_51 ) ) ;
memset ( V_6 -> V_44 , 0 , sizeof( V_6 -> V_44 ) ) ;
memset ( V_6 -> V_55 , 0 , sizeof( V_6 -> V_55 ) ) ;
for ( V_104 = 0 ; V_104 < V_121 ; V_104 ++ )
F_71 ( V_6 -> V_77 + V_104 ) ;
}
static void F_74 ( struct V_128 * V_120 )
{
struct V_5 * V_6 = F_4 ( V_120 , struct V_5 , V_120 ) ;
struct V_3 * V_4 = V_6 -> V_119 . V_129 ;
F_75 ( F_76 ( V_4 ) ) ;
}
static int F_77 ( struct V_3 * V_4 , struct V_130 * V_131 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_130 * V_132 [ V_133 + 1 ] ;
struct V_134 * V_135 ;
int V_136 ;
int V_104 ;
if ( ! V_131 )
return - V_137 ;
V_136 = F_78 ( V_132 , V_133 , V_131 , V_138 ) ;
if ( V_136 < 0 )
return V_136 ;
if ( V_132 [ V_133 ] == NULL ) {
F_79 ( L_3 ) ;
return - V_137 ;
}
V_135 = F_80 ( V_132 [ V_133 ] ) ;
if ( V_135 -> V_139 != V_140 >> 16 ) {
F_79 ( L_4 ,
V_140 >> 16 , V_140 & 0xffff , V_135 -> V_139 ) ;
return - V_137 ;
}
V_136 = F_81 ( & V_6 -> V_9 ) ;
if ( V_136 < 0 )
return V_136 ;
for ( V_104 = 0 ; V_104 < V_121 ; V_104 ++ )
F_71 ( V_6 -> V_77 + V_104 ) ;
F_82 ( & V_6 -> V_119 , V_4 ) ;
F_83 ( & V_6 -> V_120 , F_74 ) ;
F_84 ( & V_6 -> V_80 ) ;
V_6 -> V_81 = F_85 ( V_4 ) -> V_141 ;
if ( V_6 -> V_81 < 2 )
V_6 -> V_81 = 2 ;
if ( ( V_6 -> V_142 = V_135 -> V_142 ) < 1 )
V_6 -> V_142 = 1 ;
V_6 -> V_32 = V_135 -> V_32 ;
return 0 ;
}
static int F_86 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
T_3 * V_143 = F_87 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_130 * V_144 ;
struct V_134 V_135 ;
F_88 ( V_143 ) ;
V_135 . V_82 = V_6 -> V_82 ;
V_135 . V_139 = V_140 ;
V_135 . V_142 = V_6 -> V_142 ;
V_135 . V_32 = V_6 -> V_32 ;
V_135 . V_145 = 0 ;
V_144 = F_89 ( V_12 , V_146 ) ;
if ( V_144 == NULL )
goto V_147;
F_90 ( V_12 , V_133 , sizeof( V_135 ) , & V_135 ) ;
F_91 ( V_12 , V_144 ) ;
F_92 ( V_143 ) ;
return V_12 -> V_123 ;
V_147:
F_92 ( V_143 ) ;
F_93 ( V_12 , V_144 ) ;
return - 1 ;
}
static int F_94 ( struct V_3 * V_4 , unsigned long V_148 ,
struct V_11 * V_12 , struct V_149 * V_150 )
{
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
T_3 * V_143 = F_87 ( V_4 ) ;
struct V_130 * V_144 ;
struct V_151 V_131 ;
F_88 ( V_143 ) ;
V_150 -> V_152 = V_14 -> V_38 ? V_14 -> V_38 -> V_10 . V_31 : V_153 ;
V_150 -> V_154 = V_14 -> V_10 . V_31 ;
if ( ! V_14 -> V_22 && V_14 -> V_59 . V_74 . V_6 )
V_150 -> V_155 = V_14 -> V_59 . V_74 . V_6 -> V_2 ;
V_144 = F_89 ( V_12 , V_146 ) ;
if ( V_144 == NULL )
goto V_147;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_87 = V_14 -> V_87 -> V_87 ;
V_131 . V_67 = V_14 -> V_67 ;
V_131 . ceil = V_14 -> ceil -> V_87 ;
V_131 . V_66 = V_14 -> V_66 ;
V_131 . V_111 = V_14 -> V_111 ;
V_131 . V_35 = V_14 -> V_35 ;
V_131 . V_22 = V_14 -> V_22 ;
F_90 ( V_12 , V_156 , sizeof( V_131 ) , & V_131 ) ;
F_91 ( V_12 , V_144 ) ;
F_92 ( V_143 ) ;
return V_12 -> V_123 ;
V_147:
F_92 ( V_143 ) ;
F_93 ( V_12 , V_144 ) ;
return - 1 ;
}
static int
F_95 ( struct V_3 * V_4 , unsigned long V_148 , struct V_157 * V_158 )
{
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
if ( ! V_14 -> V_22 && V_14 -> V_59 . V_74 . V_6 )
V_14 -> V_83 . V_75 = V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 ;
V_14 -> V_91 . V_72 = V_14 -> V_72 ;
V_14 -> V_91 . V_71 = V_14 -> V_71 ;
if ( F_96 ( V_158 , & V_14 -> V_85 ) < 0 ||
F_97 ( V_158 , NULL , & V_14 -> V_159 ) < 0 ||
F_98 ( V_158 , & V_14 -> V_83 ) < 0 )
return - 1 ;
return F_99 ( V_158 , & V_14 -> V_91 , sizeof( V_14 -> V_91 ) ) ;
}
static int F_100 ( struct V_3 * V_4 , unsigned long V_148 , struct V_3 * V_160 ,
struct V_3 * * V_161 )
{
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
if ( V_14 -> V_22 )
return - V_137 ;
if ( V_160 == NULL &&
( V_160 = F_101 ( V_4 -> V_162 , & V_163 ,
V_14 -> V_10 . V_31 ) ) == NULL )
return - V_164 ;
F_102 ( V_4 ) ;
* V_161 = V_14 -> V_59 . V_74 . V_6 ;
V_14 -> V_59 . V_74 . V_6 = V_160 ;
if ( * V_161 != NULL ) {
F_103 ( * V_161 , ( * V_161 ) -> V_6 . V_75 ) ;
F_70 ( * V_161 ) ;
}
F_104 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_105 ( struct V_3 * V_4 , unsigned long V_148 )
{
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
return ! V_14 -> V_22 ? V_14 -> V_59 . V_74 . V_6 : NULL ;
}
static void F_106 ( struct V_3 * V_4 , unsigned long V_148 )
{
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
if ( V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 == 0 )
F_33 ( F_2 ( V_4 ) , V_14 ) ;
}
static unsigned long F_107 ( struct V_3 * V_4 , T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_165 ++ ;
return ( unsigned long ) V_14 ;
}
static inline int F_108 ( struct V_1 * V_14 )
{
if ( ! V_14 -> V_38 )
return 0 ;
if ( V_14 -> V_38 -> V_166 > 1 )
return 0 ;
return 1 ;
}
static void F_109 ( struct V_5 * V_6 , struct V_1 * V_14 ,
struct V_3 * V_167 )
{
struct V_1 * V_38 = V_14 -> V_38 ;
F_21 ( V_14 -> V_22 || ! V_14 -> V_59 . V_74 . V_6 || V_14 -> V_56 ) ;
if ( V_38 -> V_57 != V_62 )
F_19 ( & V_38 -> V_48 , V_6 -> V_44 + V_38 -> V_22 ) ;
V_38 -> V_22 = 0 ;
memset ( & V_38 -> V_59 . V_60 , 0 , sizeof( V_38 -> V_59 . V_60 ) ) ;
F_71 ( & V_38 -> V_59 . V_74 . V_76 ) ;
V_38 -> V_59 . V_74 . V_6 = V_167 ? V_167 : & V_168 ;
V_38 -> V_72 = V_38 -> V_67 ;
V_38 -> V_71 = V_38 -> V_66 ;
V_38 -> V_90 = F_62 () ;
V_38 -> V_57 = V_62 ;
}
static void F_110 ( struct V_3 * V_4 , struct V_1 * V_14 )
{
if ( ! V_14 -> V_22 ) {
F_21 ( ! V_14 -> V_59 . V_74 . V_6 ) ;
F_111 ( V_14 -> V_59 . V_74 . V_6 ) ;
}
F_112 ( & V_14 -> V_85 , & V_14 -> V_159 ) ;
F_113 ( V_14 -> V_87 ) ;
F_113 ( V_14 -> ceil ) ;
F_114 ( & V_14 -> V_25 ) ;
F_115 ( V_14 ) ;
}
static void F_116 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_126 * V_49 , * V_108 ;
struct V_1 * V_14 ;
unsigned int V_104 ;
F_117 ( & V_6 -> V_120 ) ;
F_72 ( & V_6 -> V_119 ) ;
F_114 ( & V_6 -> V_25 ) ;
for ( V_104 = 0 ; V_104 < V_6 -> V_9 . V_127 ; V_104 ++ ) {
F_69 (cl, n, &q->clhash.hash[i], common.hnode)
F_114 ( & V_14 -> V_25 ) ;
}
for ( V_104 = 0 ; V_104 < V_6 -> V_9 . V_127 ; V_104 ++ ) {
F_118 (cl, n, next, &q->clhash.hash[i],
common.hnode)
F_110 ( V_4 , V_14 ) ;
}
F_119 ( & V_6 -> V_9 ) ;
F_73 ( & V_6 -> V_80 ) ;
}
static int F_120 ( struct V_3 * V_4 , unsigned long V_148 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
unsigned int V_75 ;
struct V_3 * V_167 = NULL ;
int V_169 = 0 ;
if ( V_14 -> V_166 || V_14 -> V_170 )
return - V_171 ;
if ( ! V_14 -> V_22 && F_108 ( V_14 ) ) {
V_167 = F_101 ( V_4 -> V_162 , & V_163 ,
V_14 -> V_38 -> V_10 . V_31 ) ;
V_169 = 1 ;
}
F_102 ( V_4 ) ;
if ( ! V_14 -> V_22 ) {
V_75 = V_14 -> V_59 . V_74 . V_6 -> V_6 . V_75 ;
F_70 ( V_14 -> V_59 . V_74 . V_6 ) ;
F_103 ( V_14 -> V_59 . V_74 . V_6 , V_75 ) ;
}
F_121 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_14 -> V_38 )
V_14 -> V_38 -> V_166 -- ;
if ( V_14 -> V_56 )
F_33 ( V_6 , V_14 ) ;
if ( V_14 -> V_57 != V_62 )
F_19 ( & V_14 -> V_48 , V_6 -> V_44 + V_14 -> V_22 ) ;
if ( V_169 )
F_109 ( V_6 , V_14 , V_167 ) ;
F_53 ( -- V_14 -> V_165 == 0 ) ;
F_104 ( V_4 ) ;
return 0 ;
}
static void F_122 ( struct V_3 * V_4 , unsigned long V_148 )
{
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
if ( -- V_14 -> V_165 == 0 )
F_110 ( V_4 , V_14 ) ;
}
static int F_123 ( struct V_3 * V_4 , T_1 V_31 ,
T_1 V_172 , struct V_130 * * V_173 ,
unsigned long * V_148 )
{
int V_136 = - V_137 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) * V_148 , * V_38 ;
struct V_130 * V_131 = V_173 [ V_146 ] ;
struct V_174 * V_175 = NULL , * V_176 = NULL ;
struct V_130 * V_132 [ V_177 ] ;
struct V_151 * V_178 ;
if ( ! V_131 )
goto V_179;
V_136 = F_78 ( V_132 , V_180 , V_131 , V_138 ) ;
if ( V_136 < 0 )
goto V_179;
V_136 = - V_137 ;
if ( V_132 [ V_156 ] == NULL )
goto V_179;
V_38 = V_172 == V_153 ? NULL : F_1 ( V_172 , V_4 ) ;
V_178 = F_80 ( V_132 [ V_156 ] ) ;
V_175 = F_124 ( & V_178 -> V_87 , V_132 [ V_181 ] ) ;
V_176 = F_124 ( & V_178 -> ceil , V_132 [ V_182 ] ) ;
if ( ! V_175 || ! V_176 )
goto V_179;
if ( ! V_14 ) {
struct V_3 * V_167 ;
int V_35 ;
struct {
struct V_130 V_183 ;
struct V_184 V_131 ;
} V_185 = {
. V_183 = {
. V_186 = F_125 ( sizeof( V_185 . V_131 ) ) ,
. V_187 = V_188 ,
} ,
. V_131 = {
. V_189 = 2 ,
. V_190 = 2 ,
} ,
} ;
if ( ! V_31 || F_9 ( V_31 ^ V_4 -> V_2 ) ||
F_1 ( V_31 , V_4 ) )
goto V_179;
if ( V_38 && V_38 -> V_38 && V_38 -> V_38 -> V_22 < 2 ) {
F_79 ( L_5 ) ;
goto V_179;
}
V_136 = - V_164 ;
V_14 = F_126 ( sizeof( * V_14 ) , V_191 ) ;
if ( ! V_14 )
goto V_179;
V_136 = F_127 ( & V_14 -> V_85 , & V_14 -> V_159 ,
F_87 ( V_4 ) ,
V_173 [ V_188 ] ? : & V_185 . V_183 ) ;
if ( V_136 ) {
F_115 ( V_14 ) ;
goto V_179;
}
V_14 -> V_165 = 1 ;
V_14 -> V_166 = 0 ;
F_71 ( & V_14 -> V_59 . V_74 . V_76 ) ;
F_23 ( & V_14 -> V_48 ) ;
for ( V_35 = 0 ; V_35 < V_121 ; V_35 ++ )
F_23 ( & V_14 -> V_40 [ V_35 ] ) ;
V_167 = F_101 ( V_4 -> V_162 ,
& V_163 , V_31 ) ;
F_102 ( V_4 ) ;
if ( V_38 && ! V_38 -> V_22 ) {
unsigned int V_75 = V_38 -> V_59 . V_74 . V_6 -> V_6 . V_75 ;
F_70 ( V_38 -> V_59 . V_74 . V_6 ) ;
F_103 ( V_38 -> V_59 . V_74 . V_6 , V_75 ) ;
F_111 ( V_38 -> V_59 . V_74 . V_6 ) ;
if ( V_38 -> V_56 )
F_33 ( V_6 , V_38 ) ;
if ( V_38 -> V_57 != V_62 ) {
F_19 ( & V_38 -> V_48 , V_6 -> V_44 ) ;
V_38 -> V_57 = V_62 ;
}
V_38 -> V_22 = ( V_38 -> V_38 ? V_38 -> V_38 -> V_22
: V_106 ) - 1 ;
memset ( & V_38 -> V_59 . V_60 , 0 , sizeof( V_38 -> V_59 . V_60 ) ) ;
}
V_14 -> V_59 . V_74 . V_6 = V_167 ? V_167 : & V_168 ;
V_14 -> V_10 . V_31 = V_31 ;
V_14 -> V_38 = V_38 ;
V_14 -> V_72 = V_178 -> V_67 ;
V_14 -> V_71 = V_178 -> V_66 ;
V_14 -> V_88 = 60 * V_116 ;
V_14 -> V_90 = F_62 () ;
V_14 -> V_57 = V_62 ;
F_128 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_38 )
V_38 -> V_166 ++ ;
} else {
if ( V_173 [ V_188 ] ) {
V_136 = F_129 ( & V_14 -> V_85 , & V_14 -> V_159 ,
F_87 ( V_4 ) ,
V_173 [ V_188 ] ) ;
if ( V_136 )
return V_136 ;
}
F_102 ( V_4 ) ;
}
if ( ! V_14 -> V_22 ) {
V_14 -> V_111 = V_175 -> V_87 . V_87 / V_6 -> V_142 ;
if ( ! V_178 -> V_111 && V_14 -> V_111 < 1000 ) {
F_50 (
L_6 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_111 = 1000 ;
}
if ( ! V_178 -> V_111 && V_14 -> V_111 > 200000 ) {
F_50 (
L_7 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_111 = 200000 ;
}
if ( V_178 -> V_111 )
V_14 -> V_111 = V_178 -> V_111 ;
if ( ( V_14 -> V_35 = V_178 -> V_35 ) >= V_121 )
V_14 -> V_35 = V_121 - 1 ;
}
V_14 -> V_67 = V_178 -> V_67 ;
V_14 -> V_66 = V_178 -> V_66 ;
if ( V_14 -> V_87 )
F_113 ( V_14 -> V_87 ) ;
V_14 -> V_87 = V_175 ;
if ( V_14 -> ceil )
F_113 ( V_14 -> ceil ) ;
V_14 -> ceil = V_176 ;
F_104 ( V_4 ) ;
F_130 ( V_4 , & V_6 -> V_9 ) ;
* V_148 = ( unsigned long ) V_14 ;
return 0 ;
V_179:
if ( V_175 )
F_113 ( V_175 ) ;
if ( V_176 )
F_113 ( V_176 ) ;
return V_136 ;
}
static struct V_17 * * F_131 ( struct V_3 * V_4 , unsigned long V_148 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
struct V_17 * * V_192 = V_14 ? & V_14 -> V_25 : & V_6 -> V_25 ;
return V_192 ;
}
static unsigned long F_132 ( struct V_3 * V_4 , unsigned long V_38 ,
T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_170 ++ ;
return ( unsigned long ) V_14 ;
}
static void F_133 ( struct V_3 * V_4 , unsigned long V_148 )
{
struct V_1 * V_14 = (struct V_1 * ) V_148 ;
if ( V_14 )
V_14 -> V_170 -- ;
}
static void F_134 ( struct V_3 * V_4 , struct V_193 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
struct V_126 * V_49 ;
unsigned int V_104 ;
if ( V_148 -> V_194 )
return;
for ( V_104 = 0 ; V_104 < V_6 -> V_9 . V_127 ; V_104 ++ ) {
F_69 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_148 -> V_195 < V_148 -> V_196 ) {
V_148 -> V_195 ++ ;
continue;
}
if ( V_148 -> V_197 ( V_4 , ( unsigned long ) V_14 , V_148 ) < 0 ) {
V_148 -> V_194 = 1 ;
return;
}
V_148 -> V_195 ++ ;
}
}
}
static int T_4 F_135 ( void )
{
return F_136 ( & V_198 ) ;
}
static void T_5 F_137 ( void )
{
F_138 ( & V_198 ) ;
}
