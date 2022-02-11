static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( ( T_1 ) V_3 * V_2 -> V_4 ) >> V_2 -> V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
T_1 V_6 ;
T_1 V_4 ;
int V_5 ;
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 1 ;
if ( V_2 -> V_7 > 0 ) {
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
V_2 -> V_5 = V_5 ;
V_6 = 8LLU * V_8 * ( 1 << V_2 -> V_5 ) ;
V_4 = F_3 ( V_6 , V_2 -> V_7 ) ;
if ( V_4 > V_9 )
break;
}
V_2 -> V_5 = V_5 - 1 ;
V_6 = 8LLU * V_8 * ( 1 << V_2 -> V_5 ) ;
V_2 -> V_4 = F_3 ( V_6 , V_2 -> V_7 ) ;
}
}
static inline struct V_10 * F_4 ( T_2 V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_16 * V_17 ;
V_17 = F_6 ( & V_15 -> V_18 , V_11 ) ;
if ( V_17 == NULL )
return NULL ;
return F_7 ( V_17 , struct V_10 , V_19 ) ;
}
static struct V_10 * F_8 ( struct V_20 * V_21 , struct V_12 * V_13 ,
int * V_22 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_10 * V_23 ;
struct V_24 V_25 ;
struct V_26 * V_27 ;
int V_28 ;
if ( V_21 -> V_29 == V_13 -> V_11 )
return V_30 ;
V_23 = F_4 ( V_21 -> V_29 , V_13 ) ;
if ( V_23 && V_23 -> V_31 == 0 )
return V_23 ;
* V_22 = V_32 | V_33 ;
V_27 = V_15 -> V_34 ;
while ( V_27 && ( V_28 = F_9 ( V_21 , V_27 , & V_25 ) ) >= 0 ) {
#ifdef F_10
switch ( V_28 ) {
case V_35 :
case V_36 :
* V_22 = V_32 | V_37 ;
case V_38 :
return NULL ;
}
#endif
V_23 = ( void * ) V_25 . V_39 ;
if ( ! V_23 ) {
if ( V_25 . V_40 == V_13 -> V_11 )
return V_30 ;
V_23 = F_4 ( V_25 . V_40 , V_13 ) ;
if ( ! V_23 )
break;
}
if ( ! V_23 -> V_31 )
return V_23 ;
V_27 = V_23 -> V_34 ;
}
V_23 = F_4 ( F_11 ( F_12 ( V_13 -> V_11 ) , V_15 -> V_41 ) , V_13 ) ;
if ( ! V_23 || V_23 -> V_31 )
return V_30 ;
return V_23 ;
}
static void F_13 ( struct V_42 * V_43 ,
struct V_10 * V_23 , int V_44 )
{
struct V_45 * * V_46 = & V_43 -> V_45 , * V_47 = NULL ;
while ( * V_46 ) {
struct V_10 * V_48 ;
V_47 = * V_46 ;
V_48 = F_14 ( V_47 , struct V_10 , V_49 [ V_44 ] ) ;
if ( V_23 -> V_19 . V_40 > V_48 -> V_19 . V_40 )
V_46 = & V_47 -> V_50 ;
else
V_46 = & V_47 -> V_51 ;
}
F_15 ( & V_23 -> V_49 [ V_44 ] , V_47 , V_46 ) ;
F_16 ( & V_23 -> V_49 [ V_44 ] , V_43 ) ;
}
static void F_17 ( struct V_14 * V_15 ,
struct V_10 * V_23 , T_3 V_52 )
{
struct V_45 * * V_46 = & V_15 -> V_53 [ V_23 -> V_31 ] . V_45 , * V_47 = NULL ;
V_23 -> V_54 = V_15 -> V_55 + V_52 ;
if ( V_23 -> V_54 == V_15 -> V_55 )
V_23 -> V_54 ++ ;
if ( V_15 -> V_56 [ V_23 -> V_31 ] > V_23 -> V_54 )
V_15 -> V_56 [ V_23 -> V_31 ] = V_23 -> V_54 ;
while ( * V_46 ) {
struct V_10 * V_48 ;
V_47 = * V_46 ;
V_48 = F_14 ( V_47 , struct V_10 , V_57 ) ;
if ( V_23 -> V_54 >= V_48 -> V_54 )
V_46 = & V_47 -> V_50 ;
else
V_46 = & V_47 -> V_51 ;
}
F_15 ( & V_23 -> V_57 , V_47 , V_46 ) ;
F_16 ( & V_23 -> V_57 , & V_15 -> V_53 [ V_23 -> V_31 ] ) ;
}
static inline void F_18 ( struct V_45 * * V_58 )
{
* V_58 = F_19 ( * V_58 ) ;
}
static inline void F_20 ( struct V_14 * V_15 ,
struct V_10 * V_23 , int V_59 )
{
V_15 -> V_60 [ V_23 -> V_31 ] |= V_59 ;
while ( V_59 ) {
int V_44 = F_21 ( ~ V_59 ) ;
V_59 &= ~ ( 1 << V_44 ) ;
F_13 ( V_15 -> V_61 [ V_23 -> V_31 ] + V_44 , V_23 , V_44 ) ;
}
}
static void F_22 ( struct V_45 * V_62 , struct V_42 * V_43 )
{
if ( F_23 ( V_62 ) ) {
F_24 ( 1 ) ;
} else {
F_25 ( V_62 , V_43 ) ;
F_26 ( V_62 ) ;
}
}
static inline void F_27 ( struct V_14 * V_15 ,
struct V_10 * V_23 , int V_59 )
{
int V_63 = 0 ;
while ( V_59 ) {
int V_44 = F_21 ( ~ V_59 ) ;
V_59 &= ~ ( 1 << V_44 ) ;
if ( V_15 -> V_64 [ V_23 -> V_31 ] [ V_44 ] == V_23 -> V_49 + V_44 )
F_18 ( V_15 -> V_64 [ V_23 -> V_31 ] + V_44 ) ;
F_22 ( V_23 -> V_49 + V_44 , V_15 -> V_61 [ V_23 -> V_31 ] + V_44 ) ;
if ( ! V_15 -> V_61 [ V_23 -> V_31 ] [ V_44 ] . V_45 )
V_63 |= 1 << V_44 ;
}
V_15 -> V_60 [ V_23 -> V_31 ] &= ~ V_63 ;
}
static void F_28 ( struct V_14 * V_15 , struct V_10 * V_23 )
{
struct V_10 * V_46 = V_23 -> V_47 ;
long V_63 , V_59 = V_23 -> V_65 ;
while ( V_23 -> V_66 == V_67 && V_46 && V_59 ) {
V_63 = V_59 ;
while ( V_63 ) {
int V_44 = F_21 ( ~ V_63 ) ;
V_63 &= ~ ( 1 << V_44 ) ;
if ( V_46 -> V_68 . V_69 . V_70 [ V_44 ] . V_45 )
V_59 &= ~ ( 1 << V_44 ) ;
F_13 ( V_46 -> V_68 . V_69 . V_70 + V_44 , V_23 , V_44 ) ;
}
V_46 -> V_65 |= V_59 ;
V_23 = V_46 ;
V_46 = V_23 -> V_47 ;
}
if ( V_23 -> V_66 == V_71 && V_59 )
F_20 ( V_15 , V_23 , V_59 ) ;
}
static void F_29 ( struct V_14 * V_15 , struct V_10 * V_23 )
{
struct V_10 * V_46 = V_23 -> V_47 ;
long V_63 , V_59 = V_23 -> V_65 ;
while ( V_23 -> V_66 == V_67 && V_46 && V_59 ) {
V_63 = V_59 ;
V_59 = 0 ;
while ( V_63 ) {
int V_44 = F_21 ( ~ V_63 ) ;
V_63 &= ~ ( 1 << V_44 ) ;
if ( V_46 -> V_68 . V_69 . V_64 [ V_44 ] == V_23 -> V_49 + V_44 ) {
V_46 -> V_68 . V_69 . V_72 [ V_44 ] = V_23 -> V_19 . V_40 ;
V_46 -> V_68 . V_69 . V_64 [ V_44 ] = NULL ;
}
F_22 ( V_23 -> V_49 + V_44 , V_46 -> V_68 . V_69 . V_70 + V_44 ) ;
if ( ! V_46 -> V_68 . V_69 . V_70 [ V_44 ] . V_45 )
V_59 |= 1 << V_44 ;
}
V_46 -> V_65 &= ~ V_59 ;
V_23 = V_46 ;
V_46 = V_23 -> V_47 ;
}
if ( V_23 -> V_66 == V_71 && V_59 )
F_27 ( V_15 , V_23 , V_59 ) ;
}
static inline T_3 F_30 ( const struct V_10 * V_23 )
{
if ( V_73 )
return V_23 -> V_66 != V_74 ? - V_23 -> V_75 : 0 ;
else
return 0 ;
}
static inline T_3 F_31 ( const struct V_10 * V_23 )
{
if ( V_73 )
return V_23 -> V_66 == V_71 ? - V_23 -> V_76 : 0 ;
else
return 0 ;
}
static inline enum V_77
F_32 ( struct V_10 * V_23 , T_3 * V_78 )
{
T_3 V_79 ;
if ( ( V_79 = ( V_23 -> V_80 + * V_78 ) ) < F_30 ( V_23 ) ) {
* V_78 = - V_79 ;
return V_74 ;
}
if ( ( V_79 = ( V_23 -> V_81 + * V_78 ) ) >= F_31 ( V_23 ) )
return V_71 ;
* V_78 = - V_79 ;
return V_67 ;
}
static void
F_33 ( struct V_14 * V_15 , struct V_10 * V_23 , T_3 * V_78 )
{
enum V_77 V_82 = F_32 ( V_23 , V_78 ) ;
if ( V_82 == V_23 -> V_66 )
return;
if ( V_23 -> V_65 ) {
if ( V_23 -> V_66 != V_74 )
F_29 ( V_15 , V_23 ) ;
V_23 -> V_66 = V_82 ;
if ( V_82 != V_74 )
F_28 ( V_15 , V_23 ) ;
} else
V_23 -> V_66 = V_82 ;
}
static inline void F_34 ( struct V_14 * V_15 , struct V_10 * V_23 )
{
F_24 ( V_23 -> V_31 || ! V_23 -> V_68 . V_83 . V_15 || ! V_23 -> V_68 . V_83 . V_15 -> V_15 . V_84 ) ;
if ( ! V_23 -> V_65 ) {
V_23 -> V_65 = 1 << V_23 -> V_44 ;
F_28 ( V_15 , V_23 ) ;
F_35 ( & V_23 -> V_68 . V_83 . V_85 ,
V_15 -> V_86 + V_23 -> V_44 ) ;
}
}
static inline void F_36 ( struct V_14 * V_15 , struct V_10 * V_23 )
{
F_24 ( ! V_23 -> V_65 ) ;
F_29 ( V_15 , V_23 ) ;
V_23 -> V_65 = 0 ;
F_37 ( & V_23 -> V_68 . V_83 . V_85 ) ;
}
static int F_38 ( struct V_20 * V_21 , struct V_12 * V_13 )
{
int V_87 ( V_88 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_10 * V_23 = F_8 ( V_21 , V_13 , & V_88 ) ;
if ( V_23 == V_30 ) {
if ( V_15 -> V_89 . V_84 < V_15 -> V_90 ) {
F_39 ( & V_15 -> V_89 , V_21 ) ;
V_15 -> V_91 ++ ;
} else {
return F_40 ( V_21 , V_13 ) ;
}
#ifdef F_10
} else if ( ! V_23 ) {
if ( V_88 & V_33 )
V_13 -> V_92 . V_86 ++ ;
F_41 ( V_21 ) ;
return V_88 ;
#endif
} else if ( ( V_88 = F_42 ( V_21 , V_23 -> V_68 . V_83 . V_15 ) ) != V_32 ) {
if ( F_43 ( V_88 ) ) {
V_13 -> V_92 . V_86 ++ ;
V_23 -> V_92 . V_86 ++ ;
}
return V_88 ;
} else {
F_34 ( V_15 , V_23 ) ;
}
V_13 -> V_15 . V_84 ++ ;
return V_32 ;
}
static inline void F_44 ( struct V_10 * V_23 , int V_93 , T_3 V_78 )
{
T_3 V_79 = V_78 + V_23 -> V_81 ;
if ( V_79 > V_23 -> V_76 )
V_79 = V_23 -> V_76 ;
V_79 -= ( T_3 ) F_1 ( & V_23 -> V_94 , V_93 ) ;
if ( V_79 <= - V_23 -> V_95 )
V_79 = 1 - V_23 -> V_95 ;
V_23 -> V_81 = V_79 ;
}
static inline void F_45 ( struct V_10 * V_23 , int V_93 , T_3 V_78 )
{
T_3 V_79 = V_78 + V_23 -> V_80 ;
if ( V_79 > V_23 -> V_75 )
V_79 = V_23 -> V_75 ;
V_79 -= ( T_3 ) F_1 ( & V_23 -> ceil , V_93 ) ;
if ( V_79 <= - V_23 -> V_95 )
V_79 = 1 - V_23 -> V_95 ;
V_23 -> V_80 = V_79 ;
}
static void F_46 ( struct V_14 * V_15 , struct V_10 * V_23 ,
int V_31 , struct V_20 * V_21 )
{
int V_93 = F_47 ( V_21 ) ;
enum V_77 V_96 ;
T_3 V_78 ;
while ( V_23 ) {
V_78 = F_48 ( T_3 , V_15 -> V_55 - V_23 -> V_97 , V_23 -> V_95 ) ;
if ( V_23 -> V_31 >= V_31 ) {
if ( V_23 -> V_31 == V_31 )
V_23 -> V_98 . V_99 ++ ;
F_44 ( V_23 , V_93 , V_78 ) ;
} else {
V_23 -> V_98 . V_100 ++ ;
V_23 -> V_81 += V_78 ;
}
F_45 ( V_23 , V_93 , V_78 ) ;
V_23 -> V_97 = V_15 -> V_55 ;
V_96 = V_23 -> V_66 ;
V_78 = 0 ;
F_33 ( V_15 , V_23 , & V_78 ) ;
if ( V_96 != V_23 -> V_66 ) {
if ( V_96 != V_71 )
F_22 ( & V_23 -> V_57 , V_15 -> V_53 + V_23 -> V_31 ) ;
if ( V_23 -> V_66 != V_71 )
F_17 ( V_15 , V_23 , V_78 ) ;
}
if ( V_23 -> V_31 )
F_49 ( & V_23 -> V_101 , V_21 ) ;
V_23 = V_23 -> V_47 ;
}
}
static T_4 F_50 ( struct V_14 * V_15 , int V_31 ,
unsigned long V_102 )
{
unsigned long V_103 = V_102 + 2 ;
while ( F_51 ( V_104 , V_103 ) ) {
struct V_10 * V_23 ;
T_3 V_78 ;
struct V_45 * V_46 = F_52 ( & V_15 -> V_53 [ V_31 ] ) ;
if ( ! V_46 )
return 0 ;
V_23 = F_14 ( V_46 , struct V_10 , V_57 ) ;
if ( V_23 -> V_54 > V_15 -> V_55 )
return V_23 -> V_54 ;
F_22 ( V_46 , V_15 -> V_53 + V_31 ) ;
V_78 = F_48 ( T_3 , V_15 -> V_55 - V_23 -> V_97 , V_23 -> V_95 ) ;
F_33 ( V_15 , V_23 , & V_78 ) ;
if ( V_23 -> V_66 != V_71 )
F_17 ( V_15 , V_23 , V_78 ) ;
}
if ( ! ( V_15 -> V_105 & V_106 ) ) {
F_53 ( L_1 ) ;
V_15 -> V_105 |= V_106 ;
}
return V_15 -> V_55 ;
}
static struct V_45 * F_54 ( int V_44 , struct V_45 * V_58 ,
T_2 V_107 )
{
struct V_45 * V_2 = NULL ;
while ( V_58 ) {
struct V_10 * V_23 =
F_14 ( V_58 , struct V_10 , V_49 [ V_44 ] ) ;
if ( V_107 > V_23 -> V_19 . V_40 ) {
V_58 = V_58 -> V_50 ;
} else if ( V_107 < V_23 -> V_19 . V_40 ) {
V_2 = V_58 ;
V_58 = V_58 -> V_51 ;
} else {
return V_58 ;
}
}
return V_2 ;
}
static struct V_10 * F_55 ( struct V_42 * V_108 , int V_44 ,
struct V_45 * * V_109 , T_2 * V_110 )
{
int V_111 ;
struct {
struct V_45 * V_43 ;
struct V_45 * * V_109 ;
T_2 * V_110 ;
} V_112 [ V_113 ] , * V_114 = V_112 ;
F_56 ( ! V_108 -> V_45 ) ;
V_114 -> V_43 = V_108 -> V_45 ;
V_114 -> V_109 = V_109 ;
V_114 -> V_110 = V_110 ;
for ( V_111 = 0 ; V_111 < 65535 ; V_111 ++ ) {
if ( ! * V_114 -> V_109 && * V_114 -> V_110 ) {
* V_114 -> V_109 =
F_54 ( V_44 , V_114 -> V_43 , * V_114 -> V_110 ) ;
}
* V_114 -> V_110 = 0 ;
if ( ! * V_114 -> V_109 ) {
* V_114 -> V_109 = V_114 -> V_43 ;
while ( ( * V_114 -> V_109 ) -> V_51 )
* V_114 -> V_109 = ( * V_114 -> V_109 ) -> V_51 ;
if ( V_114 > V_112 ) {
V_114 -- ;
if ( ! * V_114 -> V_109 ) {
F_24 ( 1 ) ;
return NULL ;
}
F_18 ( V_114 -> V_109 ) ;
}
} else {
struct V_10 * V_23 ;
V_23 = F_14 ( * V_114 -> V_109 , struct V_10 , V_49 [ V_44 ] ) ;
if ( ! V_23 -> V_31 )
return V_23 ;
( ++ V_114 ) -> V_43 = V_23 -> V_68 . V_69 . V_70 [ V_44 ] . V_45 ;
V_114 -> V_109 = V_23 -> V_68 . V_69 . V_64 + V_44 ;
V_114 -> V_110 = V_23 -> V_68 . V_69 . V_72 + V_44 ;
}
}
F_24 ( 1 ) ;
return NULL ;
}
static struct V_20 * F_57 ( struct V_14 * V_15 , int V_44 ,
int V_31 )
{
struct V_20 * V_21 = NULL ;
struct V_10 * V_23 , * V_102 ;
V_102 = V_23 = F_55 ( V_15 -> V_61 [ V_31 ] + V_44 , V_44 ,
V_15 -> V_64 [ V_31 ] + V_44 ,
V_15 -> V_72 [ V_31 ] + V_44 ) ;
do {
V_115:
if ( F_58 ( ! V_23 ) )
return NULL ;
if ( F_58 ( V_23 -> V_68 . V_83 . V_15 -> V_15 . V_84 == 0 ) ) {
struct V_10 * V_115 ;
F_36 ( V_15 , V_23 ) ;
if ( ( V_15 -> V_60 [ V_31 ] & ( 1 << V_44 ) ) == 0 )
return NULL ;
V_115 = F_55 ( V_15 -> V_61 [ V_31 ] + V_44 ,
V_44 , V_15 -> V_64 [ V_31 ] + V_44 ,
V_15 -> V_72 [ V_31 ] + V_44 ) ;
if ( V_23 == V_102 )
V_102 = V_115 ;
V_23 = V_115 ;
goto V_115;
}
V_21 = V_23 -> V_68 . V_83 . V_15 -> V_116 ( V_23 -> V_68 . V_83 . V_15 ) ;
if ( F_59 ( V_21 != NULL ) )
break;
F_60 ( L_2 , V_23 -> V_68 . V_83 . V_15 ) ;
F_18 ( ( V_31 ? V_23 -> V_47 -> V_68 . V_69 . V_64 : V_15 ->
V_64 [ 0 ] ) + V_44 ) ;
V_23 = F_55 ( V_15 -> V_61 [ V_31 ] + V_44 , V_44 ,
V_15 -> V_64 [ V_31 ] + V_44 ,
V_15 -> V_72 [ V_31 ] + V_44 ) ;
} while ( V_23 != V_102 );
if ( F_59 ( V_21 != NULL ) ) {
F_49 ( & V_23 -> V_101 , V_21 ) ;
V_23 -> V_68 . V_83 . V_117 [ V_31 ] -= F_47 ( V_21 ) ;
if ( V_23 -> V_68 . V_83 . V_117 [ V_31 ] < 0 ) {
V_23 -> V_68 . V_83 . V_117 [ V_31 ] += V_23 -> V_118 ;
F_18 ( ( V_31 ? V_23 -> V_47 -> V_68 . V_69 . V_64 : V_15 ->
V_64 [ 0 ] ) + V_44 ) ;
}
if ( ! V_23 -> V_68 . V_83 . V_15 -> V_15 . V_84 )
F_36 ( V_15 , V_23 ) ;
F_46 ( V_15 , V_23 , V_31 , V_21 ) ;
}
return V_21 ;
}
static struct V_20 * F_61 ( struct V_12 * V_13 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_31 ;
T_4 V_119 ;
unsigned long V_120 ;
V_21 = F_62 ( & V_15 -> V_89 ) ;
if ( V_21 != NULL ) {
V_121:
F_63 ( V_13 , V_21 ) ;
F_64 ( V_13 ) ;
V_13 -> V_15 . V_84 -- ;
return V_21 ;
}
if ( ! V_13 -> V_15 . V_84 )
goto V_122;
V_15 -> V_55 = F_65 ( F_66 () ) ;
V_120 = V_104 ;
V_119 = V_15 -> V_55 + 5LLU * V_8 ;
for ( V_31 = 0 ; V_31 < V_113 ; V_31 ++ ) {
int V_63 ;
T_4 V_123 ;
if ( V_15 -> V_55 >= V_15 -> V_56 [ V_31 ] ) {
V_123 = F_50 ( V_15 , V_31 , V_120 ) ;
if ( ! V_123 )
V_123 = V_15 -> V_55 + V_8 ;
V_15 -> V_56 [ V_31 ] = V_123 ;
} else
V_123 = V_15 -> V_56 [ V_31 ] ;
if ( V_119 > V_123 )
V_119 = V_123 ;
V_63 = ~ V_15 -> V_60 [ V_31 ] ;
while ( V_63 != ( int ) ( - 1 ) ) {
int V_44 = F_21 ( V_63 ) ;
V_63 |= 1 << V_44 ;
V_21 = F_57 ( V_15 , V_44 , V_31 ) ;
if ( F_59 ( V_21 != NULL ) )
goto V_121;
}
}
V_13 -> V_92 . V_124 ++ ;
if ( F_59 ( V_119 > V_15 -> V_55 ) ) {
if ( ! F_67 ( V_125 ,
& F_68 ( V_15 -> V_126 . V_127 ) -> V_128 ) ) {
T_5 time = F_69 ( V_119 ) ;
F_70 ( V_15 -> V_126 . V_127 ) ;
F_71 ( & V_15 -> V_126 . V_129 , time ,
V_130 ) ;
}
} else {
F_72 ( & V_15 -> V_131 ) ;
}
V_122:
return V_21 ;
}
static unsigned int F_73 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_44 ;
for ( V_44 = V_132 - 1 ; V_44 >= 0 ; V_44 -- ) {
struct V_133 * V_46 ;
F_74 (p, q->drops + prio) {
struct V_10 * V_23 = F_75 ( V_46 , struct V_10 ,
V_68 . V_83 . V_85 ) ;
unsigned int V_3 ;
if ( V_23 -> V_68 . V_83 . V_15 -> V_134 -> V_135 &&
( V_3 = V_23 -> V_68 . V_83 . V_15 -> V_134 -> V_135 ( V_23 -> V_68 . V_83 . V_15 ) ) ) {
V_13 -> V_15 . V_84 -- ;
if ( ! V_23 -> V_68 . V_83 . V_15 -> V_15 . V_84 )
F_36 ( V_15 , V_23 ) ;
return V_3 ;
}
}
}
return 0 ;
}
static void F_76 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_10 * V_23 ;
struct V_136 * V_58 ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_15 -> V_18 . V_137 ; V_111 ++ ) {
F_77 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_23 -> V_31 )
memset ( & V_23 -> V_68 . V_69 , 0 , sizeof( V_23 -> V_68 . V_69 ) ) ;
else {
if ( V_23 -> V_68 . V_83 . V_15 )
F_78 ( V_23 -> V_68 . V_83 . V_15 ) ;
F_79 ( & V_23 -> V_68 . V_83 . V_85 ) ;
}
V_23 -> V_65 = 0 ;
V_23 -> V_66 = V_71 ;
}
}
F_80 ( & V_15 -> V_126 ) ;
F_81 ( & V_15 -> V_89 ) ;
V_13 -> V_15 . V_84 = 0 ;
memset ( V_15 -> V_61 , 0 , sizeof( V_15 -> V_61 ) ) ;
memset ( V_15 -> V_60 , 0 , sizeof( V_15 -> V_60 ) ) ;
memset ( V_15 -> V_53 , 0 , sizeof( V_15 -> V_53 ) ) ;
memset ( V_15 -> V_64 , 0 , sizeof( V_15 -> V_64 ) ) ;
for ( V_111 = 0 ; V_111 < V_132 ; V_111 ++ )
F_79 ( V_15 -> V_86 + V_111 ) ;
}
static void F_82 ( struct V_138 * V_131 )
{
struct V_14 * V_15 = F_7 ( V_131 , struct V_14 , V_131 ) ;
struct V_12 * V_13 = V_15 -> V_126 . V_127 ;
F_83 ( F_84 ( V_13 ) ) ;
}
static int F_85 ( struct V_12 * V_13 , struct V_139 * V_140 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_139 * V_141 [ V_142 + 1 ] ;
struct V_143 * V_144 ;
int V_145 ;
int V_111 ;
if ( ! V_140 )
return - V_146 ;
V_145 = F_86 ( V_141 , V_142 , V_140 , V_147 ) ;
if ( V_145 < 0 )
return V_145 ;
if ( V_141 [ V_142 ] == NULL ) {
F_87 ( L_3 ) ;
return - V_146 ;
}
V_144 = F_88 ( V_141 [ V_142 ] ) ;
if ( V_144 -> V_148 != V_149 >> 16 ) {
F_87 ( L_4 ,
V_149 >> 16 , V_149 & 0xffff , V_144 -> V_148 ) ;
return - V_146 ;
}
V_145 = F_89 ( & V_15 -> V_18 ) ;
if ( V_145 < 0 )
return V_145 ;
for ( V_111 = 0 ; V_111 < V_132 ; V_111 ++ )
F_79 ( V_15 -> V_86 + V_111 ) ;
F_90 ( & V_15 -> V_126 , V_13 ) ;
F_91 ( & V_15 -> V_131 , F_82 ) ;
F_92 ( & V_15 -> V_89 ) ;
V_15 -> V_90 = F_93 ( V_13 ) -> V_150 ;
if ( V_15 -> V_90 < 2 )
V_15 -> V_90 = 2 ;
if ( ( V_15 -> V_151 = V_144 -> V_151 ) < 1 )
V_15 -> V_151 = 1 ;
V_15 -> V_41 = V_144 -> V_41 ;
return 0 ;
}
static int F_94 ( struct V_12 * V_13 , struct V_20 * V_21 )
{
T_6 * V_152 = F_95 ( V_13 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_139 * V_153 ;
struct V_143 V_144 ;
F_96 ( V_152 ) ;
V_144 . V_91 = V_15 -> V_91 ;
V_144 . V_148 = V_149 ;
V_144 . V_151 = V_15 -> V_151 ;
V_144 . V_41 = V_15 -> V_41 ;
V_144 . V_154 = 0 ;
V_153 = F_97 ( V_21 , V_155 ) ;
if ( V_153 == NULL )
goto V_156;
if ( F_98 ( V_21 , V_142 , sizeof( V_144 ) , & V_144 ) )
goto V_156;
F_99 ( V_21 , V_153 ) ;
F_100 ( V_152 ) ;
return V_21 -> V_3 ;
V_156:
F_100 ( V_152 ) ;
F_101 ( V_21 , V_153 ) ;
return - 1 ;
}
static int F_102 ( struct V_12 * V_13 , unsigned long V_157 ,
struct V_20 * V_21 , struct V_158 * V_159 )
{
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
T_6 * V_152 = F_95 ( V_13 ) ;
struct V_139 * V_153 ;
struct V_160 V_140 ;
F_96 ( V_152 ) ;
V_159 -> V_161 = V_23 -> V_47 ? V_23 -> V_47 -> V_19 . V_40 : V_162 ;
V_159 -> V_163 = V_23 -> V_19 . V_40 ;
if ( ! V_23 -> V_31 && V_23 -> V_68 . V_83 . V_15 )
V_159 -> V_164 = V_23 -> V_68 . V_83 . V_15 -> V_11 ;
V_153 = F_97 ( V_21 , V_155 ) ;
if ( V_153 == NULL )
goto V_156;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_94 . V_94 = V_23 -> V_94 . V_7 >> 3 ;
V_140 . V_76 = F_103 ( V_23 -> V_76 ) ;
V_140 . ceil . V_94 = V_23 -> ceil . V_7 >> 3 ;
V_140 . V_75 = F_103 ( V_23 -> V_75 ) ;
V_140 . V_118 = V_23 -> V_118 ;
V_140 . V_44 = V_23 -> V_44 ;
V_140 . V_31 = V_23 -> V_31 ;
if ( F_98 ( V_21 , V_165 , sizeof( V_140 ) , & V_140 ) )
goto V_156;
F_99 ( V_21 , V_153 ) ;
F_100 ( V_152 ) ;
return V_21 -> V_3 ;
V_156:
F_100 ( V_152 ) ;
F_101 ( V_21 , V_153 ) ;
return - 1 ;
}
static int
F_104 ( struct V_12 * V_13 , unsigned long V_157 , struct V_166 * V_167 )
{
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
if ( ! V_23 -> V_31 && V_23 -> V_68 . V_83 . V_15 )
V_23 -> V_92 . V_84 = V_23 -> V_68 . V_83 . V_15 -> V_15 . V_84 ;
V_23 -> V_98 . V_81 = V_23 -> V_81 ;
V_23 -> V_98 . V_80 = V_23 -> V_80 ;
if ( F_105 ( V_167 , & V_23 -> V_101 ) < 0 ||
F_106 ( V_167 , NULL , & V_23 -> V_168 ) < 0 ||
F_107 ( V_167 , & V_23 -> V_92 ) < 0 )
return - 1 ;
return F_108 ( V_167 , & V_23 -> V_98 , sizeof( V_23 -> V_98 ) ) ;
}
static int F_109 ( struct V_12 * V_13 , unsigned long V_157 , struct V_12 * V_169 ,
struct V_12 * * V_170 )
{
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
if ( V_23 -> V_31 )
return - V_146 ;
if ( V_169 == NULL &&
( V_169 = F_110 ( V_13 -> V_171 , & V_172 ,
V_23 -> V_19 . V_40 ) ) == NULL )
return - V_173 ;
F_111 ( V_13 ) ;
* V_170 = V_23 -> V_68 . V_83 . V_15 ;
V_23 -> V_68 . V_83 . V_15 = V_169 ;
if ( * V_170 != NULL ) {
F_112 ( * V_170 , ( * V_170 ) -> V_15 . V_84 ) ;
F_78 ( * V_170 ) ;
}
F_113 ( V_13 ) ;
return 0 ;
}
static struct V_12 * F_114 ( struct V_12 * V_13 , unsigned long V_157 )
{
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
return ! V_23 -> V_31 ? V_23 -> V_68 . V_83 . V_15 : NULL ;
}
static void F_115 ( struct V_12 * V_13 , unsigned long V_157 )
{
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
if ( V_23 -> V_68 . V_83 . V_15 -> V_15 . V_84 == 0 )
F_36 ( F_5 ( V_13 ) , V_23 ) ;
}
static unsigned long F_116 ( struct V_12 * V_13 , T_2 V_40 )
{
struct V_10 * V_23 = F_4 ( V_40 , V_13 ) ;
if ( V_23 )
V_23 -> V_174 ++ ;
return ( unsigned long ) V_23 ;
}
static inline int F_117 ( struct V_10 * V_23 )
{
if ( ! V_23 -> V_47 )
return 0 ;
if ( V_23 -> V_47 -> V_175 > 1 )
return 0 ;
return 1 ;
}
static void F_118 ( struct V_14 * V_15 , struct V_10 * V_23 ,
struct V_12 * V_176 )
{
struct V_10 * V_47 = V_23 -> V_47 ;
F_24 ( V_23 -> V_31 || ! V_23 -> V_68 . V_83 . V_15 || V_23 -> V_65 ) ;
if ( V_47 -> V_66 != V_71 )
F_22 ( & V_47 -> V_57 , V_15 -> V_53 + V_47 -> V_31 ) ;
V_47 -> V_31 = 0 ;
memset ( & V_47 -> V_68 . V_69 , 0 , sizeof( V_47 -> V_68 . V_69 ) ) ;
F_79 ( & V_47 -> V_68 . V_83 . V_85 ) ;
V_47 -> V_68 . V_83 . V_15 = V_176 ? V_176 : & V_177 ;
V_47 -> V_81 = V_47 -> V_76 ;
V_47 -> V_80 = V_47 -> V_75 ;
V_47 -> V_97 = F_119 () ;
V_47 -> V_66 = V_71 ;
}
static void F_120 ( struct V_12 * V_13 , struct V_10 * V_23 )
{
if ( ! V_23 -> V_31 ) {
F_24 ( ! V_23 -> V_68 . V_83 . V_15 ) ;
F_121 ( V_23 -> V_68 . V_83 . V_15 ) ;
}
F_122 ( & V_23 -> V_101 , & V_23 -> V_168 ) ;
F_123 ( & V_23 -> V_34 ) ;
F_124 ( V_23 ) ;
}
static void F_125 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_136 * V_58 , * V_115 ;
struct V_10 * V_23 ;
unsigned int V_111 ;
F_126 ( & V_15 -> V_131 ) ;
F_80 ( & V_15 -> V_126 ) ;
F_123 ( & V_15 -> V_34 ) ;
for ( V_111 = 0 ; V_111 < V_15 -> V_18 . V_137 ; V_111 ++ ) {
F_77 (cl, n, &q->clhash.hash[i], common.hnode)
F_123 ( & V_23 -> V_34 ) ;
}
for ( V_111 = 0 ; V_111 < V_15 -> V_18 . V_137 ; V_111 ++ ) {
F_127 (cl, n, next, &q->clhash.hash[i],
common.hnode)
F_120 ( V_13 , V_23 ) ;
}
F_128 ( & V_15 -> V_18 ) ;
F_81 ( & V_15 -> V_89 ) ;
}
static int F_129 ( struct V_12 * V_13 , unsigned long V_157 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
unsigned int V_84 ;
struct V_12 * V_176 = NULL ;
int V_178 = 0 ;
if ( V_23 -> V_175 || V_23 -> V_179 )
return - V_180 ;
if ( ! V_23 -> V_31 && F_117 ( V_23 ) ) {
V_176 = F_110 ( V_13 -> V_171 , & V_172 ,
V_23 -> V_47 -> V_19 . V_40 ) ;
V_178 = 1 ;
}
F_111 ( V_13 ) ;
if ( ! V_23 -> V_31 ) {
V_84 = V_23 -> V_68 . V_83 . V_15 -> V_15 . V_84 ;
F_78 ( V_23 -> V_68 . V_83 . V_15 ) ;
F_112 ( V_23 -> V_68 . V_83 . V_15 , V_84 ) ;
}
F_130 ( & V_15 -> V_18 , & V_23 -> V_19 ) ;
if ( V_23 -> V_47 )
V_23 -> V_47 -> V_175 -- ;
if ( V_23 -> V_65 )
F_36 ( V_15 , V_23 ) ;
if ( V_23 -> V_66 != V_71 )
F_22 ( & V_23 -> V_57 , V_15 -> V_53 + V_23 -> V_31 ) ;
if ( V_178 )
F_118 ( V_15 , V_23 , V_176 ) ;
F_56 ( -- V_23 -> V_174 == 0 ) ;
F_113 ( V_13 ) ;
return 0 ;
}
static void F_131 ( struct V_12 * V_13 , unsigned long V_157 )
{
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
if ( -- V_23 -> V_174 == 0 )
F_120 ( V_13 , V_23 ) ;
}
static int F_132 ( struct V_12 * V_13 , T_2 V_40 ,
T_2 V_181 , struct V_139 * * V_182 ,
unsigned long * V_157 )
{
int V_145 = - V_146 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_10 * V_23 = (struct V_10 * ) * V_157 , * V_47 ;
struct V_139 * V_140 = V_182 [ V_155 ] ;
struct V_139 * V_141 [ V_183 ] ;
struct V_160 * V_184 ;
if ( ! V_140 )
goto V_185;
V_145 = F_86 ( V_141 , V_186 , V_140 , V_147 ) ;
if ( V_145 < 0 )
goto V_185;
V_145 = - V_146 ;
if ( V_141 [ V_165 ] == NULL )
goto V_185;
V_47 = V_181 == V_162 ? NULL : F_4 ( V_181 , V_13 ) ;
V_184 = F_88 ( V_141 [ V_165 ] ) ;
if ( ! V_184 -> V_94 . V_94 || ! V_184 -> ceil . V_94 )
goto V_185;
if ( ! V_23 ) {
struct V_12 * V_176 ;
int V_44 ;
struct {
struct V_139 V_187 ;
struct V_188 V_140 ;
} V_189 = {
. V_187 = {
. V_190 = F_133 ( sizeof( V_189 . V_140 ) ) ,
. V_191 = V_192 ,
} ,
. V_140 = {
. V_193 = 2 ,
. V_194 = 2 ,
} ,
} ;
if ( ! V_40 || F_12 ( V_40 ^ V_13 -> V_11 ) ||
F_4 ( V_40 , V_13 ) )
goto V_185;
if ( V_47 && V_47 -> V_47 && V_47 -> V_47 -> V_31 < 2 ) {
F_87 ( L_5 ) ;
goto V_185;
}
V_145 = - V_173 ;
V_23 = F_134 ( sizeof( * V_23 ) , V_195 ) ;
if ( ! V_23 )
goto V_185;
V_145 = F_135 ( & V_23 -> V_101 , & V_23 -> V_168 ,
F_95 ( V_13 ) ,
V_182 [ V_192 ] ? : & V_189 . V_187 ) ;
if ( V_145 ) {
F_124 ( V_23 ) ;
goto V_185;
}
V_23 -> V_174 = 1 ;
V_23 -> V_175 = 0 ;
F_79 ( & V_23 -> V_68 . V_83 . V_85 ) ;
F_26 ( & V_23 -> V_57 ) ;
for ( V_44 = 0 ; V_44 < V_132 ; V_44 ++ )
F_26 ( & V_23 -> V_49 [ V_44 ] ) ;
V_176 = F_110 ( V_13 -> V_171 ,
& V_172 , V_40 ) ;
F_111 ( V_13 ) ;
if ( V_47 && ! V_47 -> V_31 ) {
unsigned int V_84 = V_47 -> V_68 . V_83 . V_15 -> V_15 . V_84 ;
F_78 ( V_47 -> V_68 . V_83 . V_15 ) ;
F_112 ( V_47 -> V_68 . V_83 . V_15 , V_84 ) ;
F_121 ( V_47 -> V_68 . V_83 . V_15 ) ;
if ( V_47 -> V_65 )
F_36 ( V_15 , V_47 ) ;
if ( V_47 -> V_66 != V_71 ) {
F_22 ( & V_47 -> V_57 , V_15 -> V_53 ) ;
V_47 -> V_66 = V_71 ;
}
V_47 -> V_31 = ( V_47 -> V_47 ? V_47 -> V_47 -> V_31
: V_113 ) - 1 ;
memset ( & V_47 -> V_68 . V_69 , 0 , sizeof( V_47 -> V_68 . V_69 ) ) ;
}
V_23 -> V_68 . V_83 . V_15 = V_176 ? V_176 : & V_177 ;
V_23 -> V_19 . V_40 = V_40 ;
V_23 -> V_47 = V_47 ;
V_23 -> V_81 = V_184 -> V_76 ;
V_23 -> V_80 = V_184 -> V_75 ;
V_23 -> V_95 = 60 * V_196 ;
V_23 -> V_97 = F_119 () ;
V_23 -> V_66 = V_71 ;
F_136 ( & V_15 -> V_18 , & V_23 -> V_19 ) ;
if ( V_47 )
V_47 -> V_175 ++ ;
} else {
if ( V_182 [ V_192 ] ) {
V_145 = F_137 ( & V_23 -> V_101 , & V_23 -> V_168 ,
F_95 ( V_13 ) ,
V_182 [ V_192 ] ) ;
if ( V_145 )
return V_145 ;
}
F_111 ( V_13 ) ;
}
if ( ! V_23 -> V_31 ) {
V_23 -> V_118 = V_184 -> V_94 . V_94 / V_15 -> V_151 ;
if ( ! V_184 -> V_118 && V_23 -> V_118 < 1000 ) {
F_53 (
L_6 ,
V_23 -> V_19 . V_40 ) ;
V_23 -> V_118 = 1000 ;
}
if ( ! V_184 -> V_118 && V_23 -> V_118 > 200000 ) {
F_53 (
L_7 ,
V_23 -> V_19 . V_40 ) ;
V_23 -> V_118 = 200000 ;
}
if ( V_184 -> V_118 )
V_23 -> V_118 = V_184 -> V_118 ;
if ( ( V_23 -> V_44 = V_184 -> V_44 ) >= V_132 )
V_23 -> V_44 = V_132 - 1 ;
}
V_23 -> V_76 = V_184 -> V_76 ;
V_23 -> V_75 = V_184 -> V_75 ;
V_23 -> V_94 . V_7 = ( T_1 ) V_184 -> V_94 . V_94 << 3 ;
V_23 -> ceil . V_7 = ( T_1 ) V_184 -> ceil . V_94 << 3 ;
F_2 ( & V_23 -> V_94 ) ;
F_2 ( & V_23 -> ceil ) ;
V_23 -> V_76 = V_184 -> V_76 << V_197 ;
V_23 -> V_75 = V_184 -> V_76 << V_197 ;
F_113 ( V_13 ) ;
F_138 ( V_13 , & V_15 -> V_18 ) ;
* V_157 = ( unsigned long ) V_23 ;
return 0 ;
V_185:
return V_145 ;
}
static struct V_26 * * F_139 ( struct V_12 * V_13 , unsigned long V_157 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
struct V_26 * * V_198 = V_23 ? & V_23 -> V_34 : & V_15 -> V_34 ;
return V_198 ;
}
static unsigned long F_140 ( struct V_12 * V_13 , unsigned long V_47 ,
T_2 V_40 )
{
struct V_10 * V_23 = F_4 ( V_40 , V_13 ) ;
if ( V_23 )
V_23 -> V_179 ++ ;
return ( unsigned long ) V_23 ;
}
static void F_141 ( struct V_12 * V_13 , unsigned long V_157 )
{
struct V_10 * V_23 = (struct V_10 * ) V_157 ;
if ( V_23 )
V_23 -> V_179 -- ;
}
static void F_142 ( struct V_12 * V_13 , struct V_199 * V_157 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
struct V_10 * V_23 ;
struct V_136 * V_58 ;
unsigned int V_111 ;
if ( V_157 -> V_200 )
return;
for ( V_111 = 0 ; V_111 < V_15 -> V_18 . V_137 ; V_111 ++ ) {
F_77 (cl, n, &q->clhash.hash[i], common.hnode) {
if ( V_157 -> V_201 < V_157 -> V_202 ) {
V_157 -> V_201 ++ ;
continue;
}
if ( V_157 -> V_203 ( V_13 , ( unsigned long ) V_23 , V_157 ) < 0 ) {
V_157 -> V_200 = 1 ;
return;
}
V_157 -> V_201 ++ ;
}
}
}
static int T_7 F_143 ( void )
{
return F_144 ( & V_204 ) ;
}
static void T_8 F_145 ( void )
{
F_146 ( & V_204 ) ;
}
