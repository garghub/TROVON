static inline struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( & V_3 -> V_7 , V_4 ) ;
if ( V_6 == NULL )
return NULL ;
return F_3 ( V_6 , struct V_1 , V_8 ) ;
}
static struct V_1 *
F_4 ( struct V_9 * V_10 , struct V_1 * V_11 )
{
struct V_1 * V_12 ;
for ( V_12 = V_11 -> V_13 ; V_12 ; V_12 = V_12 -> V_13 ) {
struct V_1 * V_14 = V_12 -> V_15 [ V_16 ] ;
if ( V_14 != NULL && V_14 != V_11 )
return V_14 ;
}
return NULL ;
}
static struct V_1 *
F_5 ( struct V_9 * V_10 , struct V_17 * V_18 , int * V_19 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_20 = & V_3 -> V_21 ;
struct V_1 * * V_22 ;
struct V_1 * V_12 = NULL ;
T_1 V_23 = V_10 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
if ( F_7 ( V_23 ^ V_18 -> V_29 ) == 0 &&
( V_12 = F_1 ( V_3 , V_23 ) ) != NULL )
return V_12 ;
* V_19 = V_30 | V_31 ;
for (; ; ) {
int V_32 = 0 ;
V_22 = V_20 -> V_15 ;
V_26 = F_8 ( V_20 -> V_33 ) ;
V_32 = F_9 ( V_10 , V_26 , & V_28 , true ) ;
if ( ! V_26 || V_32 < 0 )
goto V_34;
V_12 = ( void * ) V_28 . V_35 ;
if ( ! V_12 ) {
if ( F_7 ( V_28 . V_4 ) )
V_12 = F_1 ( V_3 , V_28 . V_4 ) ;
else if ( ( V_12 = V_22 [ V_28 . V_4 & V_36 ] ) == NULL )
V_12 = V_22 [ V_16 ] ;
if ( V_12 == NULL )
goto V_34;
}
if ( V_12 -> V_37 >= V_20 -> V_37 )
goto V_34;
#ifdef F_10
switch ( V_32 ) {
case V_38 :
case V_39 :
case V_40 :
* V_19 = V_30 | V_41 ;
case V_42 :
return NULL ;
case V_43 :
return F_4 ( V_10 , V_12 ) ;
}
#endif
if ( V_12 -> V_37 == 0 )
return V_12 ;
V_20 = V_12 ;
}
V_34:
V_12 = V_20 ;
if ( F_7 ( V_23 ) == 0 &&
! ( V_12 = V_20 -> V_15 [ V_23 & V_36 ] ) &&
! ( V_12 = V_20 -> V_15 [ V_16 ] ) )
return V_20 ;
return V_12 ;
}
static inline void F_11 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_44 ) ;
int V_23 = V_12 -> V_45 ;
struct V_1 * V_46 ;
V_46 = V_3 -> V_47 [ V_23 ] ;
V_3 -> V_47 [ V_23 ] = V_12 ;
if ( V_46 != NULL ) {
V_12 -> V_48 = V_46 -> V_48 ;
V_46 -> V_48 = V_12 ;
} else {
V_12 -> V_48 = V_12 ;
V_3 -> V_49 |= ( 1 << V_23 ) ;
}
}
static void F_12 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 -> V_44 ) ;
int V_23 = V_11 -> V_45 ;
struct V_1 * V_12 ;
struct V_1 * V_50 = V_3 -> V_47 [ V_23 ] ;
do {
V_12 = V_50 -> V_48 ;
if ( V_12 == V_11 ) {
V_50 -> V_48 = V_12 -> V_48 ;
V_12 -> V_48 = NULL ;
if ( V_12 == V_3 -> V_47 [ V_23 ] ) {
V_3 -> V_47 [ V_23 ] = V_50 ;
if ( V_12 == V_3 -> V_47 [ V_23 ] ) {
V_3 -> V_47 [ V_23 ] = NULL ;
V_3 -> V_49 &= ~ ( 1 << V_23 ) ;
return;
}
}
return;
}
} while ( ( V_50 = V_12 ) != V_3 -> V_47 [ V_23 ] );
}
static void
F_13 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
int V_51 = V_3 -> V_51 ;
if ( V_51 > V_12 -> V_37 ) {
T_2 V_52 = F_14 () ;
do {
if ( V_12 -> V_53 < V_52 ) {
V_3 -> V_51 = V_12 -> V_37 ;
return;
}
} while ( ( V_12 = V_12 -> V_54 ) != NULL && V_51 > V_12 -> V_37 );
}
}
static int
F_15 ( struct V_9 * V_10 , struct V_17 * V_18 ,
struct V_9 * * V_55 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
int V_56 ( V_57 ) ;
struct V_1 * V_12 = F_5 ( V_10 , V_18 , & V_57 ) ;
#ifdef F_10
V_3 -> V_58 = V_12 ;
#endif
if ( V_12 == NULL ) {
if ( V_57 & V_31 )
F_16 ( V_18 ) ;
F_17 ( V_10 , V_55 ) ;
return V_57 ;
}
V_57 = F_18 ( V_10 , V_12 -> V_3 , V_55 ) ;
if ( V_57 == V_30 ) {
V_18 -> V_3 . V_59 ++ ;
F_13 ( V_3 , V_12 ) ;
if ( ! V_12 -> V_48 )
F_11 ( V_12 ) ;
return V_57 ;
}
if ( F_19 ( V_57 ) ) {
F_16 ( V_18 ) ;
F_13 ( V_3 , V_12 ) ;
V_12 -> V_60 . V_61 ++ ;
}
return V_57 ;
}
static void F_20 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_44 ) ;
T_3 V_62 = V_12 -> V_53 - V_3 -> V_52 ;
if ( ! V_12 -> V_63 ) {
V_62 += V_12 -> V_64 ;
if ( V_12 -> V_65 < 0 )
V_62 -= ( - V_12 -> V_65 ) - ( ( - V_12 -> V_65 ) >> V_12 -> V_66 ) ;
if ( V_12 -> V_65 < V_12 -> V_67 )
V_12 -> V_65 = V_12 -> V_67 ;
if ( V_62 <= 0 )
V_62 = 1 ;
V_12 -> V_53 = V_3 -> V_52 + V_62 ;
V_12 -> V_68 . V_69 ++ ;
V_12 -> V_63 = 1 ;
}
if ( V_3 -> V_70 == 0 || V_3 -> V_70 > V_62 )
V_3 -> V_70 = V_62 ;
if ( V_3 -> V_51 == V_71 ) {
struct V_1 * V_72 ;
T_3 V_73 = V_3 -> V_70 ;
for ( V_72 = V_12 -> V_54 ; V_72 ; V_72 = V_72 -> V_54 ) {
V_62 = V_72 -> V_53 - V_3 -> V_52 ;
if ( V_62 < V_73 ) {
if ( V_62 <= 0 )
V_62 = 1 ;
V_73 = V_62 ;
}
}
V_3 -> V_70 = V_73 ;
}
}
static T_3 F_21 ( struct V_2 * V_3 , int V_23 ,
T_2 V_52 )
{
struct V_1 * V_12 ;
struct V_1 * V_50 = V_3 -> V_47 [ V_23 ] ;
T_2 V_74 = V_52 ;
if ( V_50 == NULL )
return 0 ;
do {
V_12 = V_50 -> V_48 ;
if ( V_52 - V_12 -> V_75 > 0 ) {
V_50 -> V_48 = V_12 -> V_48 ;
V_12 -> V_48 = NULL ;
V_12 -> V_45 = V_12 -> V_24 ;
V_12 -> V_63 = 0 ;
F_11 ( V_12 ) ;
if ( V_12 == V_3 -> V_47 [ V_23 ] ) {
V_3 -> V_47 [ V_23 ] = V_50 ;
if ( V_12 == V_3 -> V_47 [ V_23 ] ) {
V_3 -> V_47 [ V_23 ] = NULL ;
return 0 ;
}
}
V_12 = V_50 -> V_48 ;
} else if ( V_74 - V_12 -> V_75 > 0 )
V_74 = V_12 -> V_75 ;
} while ( ( V_50 = V_12 ) != V_3 -> V_47 [ V_23 ] );
return V_74 - V_52 ;
}
static enum V_76 F_22 ( struct V_77 * V_78 )
{
struct V_2 * V_3 = F_3 ( V_78 , struct V_2 ,
V_79 ) ;
struct V_17 * V_18 = V_3 -> V_80 . V_44 ;
T_2 V_52 ;
T_3 V_62 = 0 ;
unsigned int V_81 ;
V_52 = F_14 () ;
V_81 = V_3 -> V_81 ;
V_3 -> V_81 = 0 ;
while ( V_81 ) {
int V_23 = F_23 ( ~ V_81 ) ;
T_3 V_82 ;
V_81 &= ~ ( 1 << V_23 ) ;
V_82 = F_21 ( V_3 , V_23 , V_52 ) ;
if ( V_82 > 0 ) {
V_3 -> V_81 |= 1 << V_23 ;
if ( V_82 < V_62 || V_62 == 0 )
V_62 = V_82 ;
}
}
if ( V_62 ) {
T_4 time ;
time = 0 ;
time = F_24 ( time , F_25 ( V_52 + V_62 ) ) ;
F_26 ( & V_3 -> V_79 , time , V_83 ) ;
}
F_27 ( F_28 ( V_18 ) ) ;
return V_84 ;
}
static inline void
F_29 ( struct V_2 * V_3 , struct V_1 * V_12 ,
struct V_1 * V_85 )
{
if ( V_12 && V_3 -> V_51 >= V_85 -> V_37 ) {
if ( V_12 -> V_3 -> V_3 . V_59 > 1 ) {
do {
if ( V_85 -> V_53 == V_86 ) {
V_3 -> V_51 = V_85 -> V_37 ;
return;
}
} while ( ( V_85 = V_85 -> V_54 ) != NULL );
}
#if 0
q->toplevel = TC_CBQ_MAXLEVEL;
#endif
}
}
static void
F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = V_3 -> V_87 ;
struct V_1 * V_12 = V_11 ;
int V_88 = V_3 -> V_89 ;
T_2 V_52 ;
V_3 -> V_87 = NULL ;
V_52 = V_3 -> V_52 + F_31 ( & V_3 -> V_21 , V_88 ) ;
for ( ; V_12 ; V_12 = V_12 -> V_90 ) {
long V_65 = V_12 -> V_65 ;
long V_91 ;
V_12 -> V_92 . V_93 ++ ;
V_12 -> V_92 . V_94 += V_88 ;
V_91 = V_52 - V_12 -> V_95 ;
if ( ( unsigned long ) V_91 > 128 * 1024 * 1024 ) {
V_65 = V_12 -> V_96 ;
} else {
V_91 -= F_31 ( V_12 , V_88 ) ;
V_65 += V_91 - ( V_65 >> V_12 -> V_66 ) ;
}
if ( V_65 <= 0 ) {
if ( V_65 < V_12 -> V_67 )
V_65 = V_12 -> V_67 ;
V_12 -> V_65 = V_65 ;
V_91 = ( - V_65 ) - ( ( - V_65 ) >> V_12 -> V_66 ) ;
V_91 -= F_31 ( & V_3 -> V_21 , V_88 ) ;
V_91 += F_31 ( V_12 , V_88 ) ;
V_12 -> V_53 = V_52 + V_91 ;
} else {
V_12 -> V_53 = V_86 ;
if ( V_65 > V_12 -> V_96 )
V_12 -> V_65 = V_12 -> V_96 ;
else
V_12 -> V_65 = V_65 ;
}
if ( ( V_97 ) ( V_52 - V_12 -> V_95 ) > 0 )
V_12 -> V_95 = V_52 ;
}
F_29 ( V_3 , V_11 , V_3 -> V_98 ) ;
}
static inline struct V_1 *
F_32 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_44 ) ;
struct V_1 * V_99 = V_12 ;
if ( V_12 -> V_13 == NULL )
return V_12 ;
if ( V_12 -> V_53 == V_86 || V_3 -> V_52 >= V_12 -> V_53 ) {
V_12 -> V_63 = 0 ;
return V_12 ;
}
do {
V_12 = V_12 -> V_54 ;
if ( ! V_12 ) {
V_99 -> V_60 . V_100 ++ ;
F_20 ( V_99 ) ;
return NULL ;
}
if ( V_12 -> V_37 > V_3 -> V_51 )
return NULL ;
} while ( V_12 -> V_53 != V_86 && V_3 -> V_52 < V_12 -> V_53 );
V_12 -> V_63 = 0 ;
return V_12 ;
}
static inline struct V_9 *
F_33 ( struct V_17 * V_18 , int V_23 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_46 , * V_50 , * V_12 ;
struct V_9 * V_10 ;
int V_101 ;
V_46 = V_50 = V_3 -> V_47 [ V_23 ] ;
V_12 = V_50 -> V_48 ;
do {
V_101 = 0 ;
do {
struct V_1 * V_54 = V_12 ;
if ( V_12 -> V_3 -> V_3 . V_59 &&
( V_54 = F_32 ( V_12 ) ) == NULL )
goto V_102;
if ( V_12 -> V_101 <= 0 ) {
V_101 = 1 ;
V_12 -> V_101 += V_12 -> V_103 ;
goto V_104;
}
V_10 = V_12 -> V_3 -> V_105 ( V_12 -> V_3 ) ;
if ( V_10 == NULL )
goto V_102;
V_12 -> V_101 -= F_34 ( V_10 ) ;
V_3 -> V_87 = V_12 ;
V_3 -> V_98 = V_54 ;
if ( V_54 != V_12 ) {
#ifndef F_35
V_54 -> V_68 . V_106 ++ ;
V_12 -> V_68 . V_106 ++ ;
#else
V_54 -> V_68 . V_106 += F_34 ( V_10 ) ;
V_12 -> V_68 . V_106 += F_34 ( V_10 ) ;
#endif
}
V_3 -> V_89 = F_34 ( V_10 ) ;
if ( V_12 -> V_101 <= 0 ) {
V_3 -> V_47 [ V_23 ] = V_12 ;
V_12 = V_12 -> V_48 ;
V_12 -> V_101 += V_12 -> V_103 ;
}
return V_10 ;
V_102:
if ( V_12 -> V_3 -> V_3 . V_59 == 0 || V_23 != V_12 -> V_45 ) {
V_50 -> V_48 = V_12 -> V_48 ;
V_12 -> V_48 = NULL ;
if ( V_12 == V_46 ) {
V_46 = V_50 ;
if ( V_12 == V_46 ) {
V_3 -> V_47 [ V_23 ] = NULL ;
V_3 -> V_49 &= ~ ( 1 << V_23 ) ;
if ( V_12 -> V_3 -> V_3 . V_59 )
F_11 ( V_12 ) ;
return NULL ;
}
V_3 -> V_47 [ V_23 ] = V_46 ;
}
if ( V_12 -> V_3 -> V_3 . V_59 )
F_11 ( V_12 ) ;
V_12 = V_50 ;
}
V_104:
V_50 = V_12 ;
V_12 = V_12 -> V_48 ;
} while ( V_50 != V_46 );
} while ( V_101 );
V_3 -> V_47 [ V_23 ] = V_50 ;
return NULL ;
}
static inline struct V_9 *
F_36 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_9 * V_10 ;
unsigned int V_49 ;
V_49 = V_3 -> V_49 & 0xFF ;
while ( V_49 ) {
int V_23 = F_23 ( ~ V_49 ) ;
V_49 &= ~ ( 1 << V_23 ) ;
V_10 = F_33 ( V_18 , V_23 ) ;
if ( V_10 )
return V_10 ;
}
return NULL ;
}
static struct V_9 *
F_37 ( struct V_17 * V_18 )
{
struct V_9 * V_10 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
T_2 V_52 ;
V_52 = F_14 () ;
if ( V_3 -> V_87 )
F_30 ( V_3 ) ;
V_3 -> V_52 = V_52 ;
for (; ; ) {
V_3 -> V_70 = 0 ;
V_10 = F_36 ( V_18 ) ;
if ( V_10 ) {
F_38 ( V_18 , V_10 ) ;
V_18 -> V_3 . V_59 -- ;
return V_10 ;
}
if ( V_3 -> V_51 == V_71 &&
V_3 -> V_21 . V_53 == V_86 )
break;
V_3 -> V_51 = V_71 ;
V_3 -> V_21 . V_53 = V_86 ;
}
if ( V_18 -> V_3 . V_59 ) {
F_39 ( V_18 ) ;
if ( V_3 -> V_70 )
F_40 ( & V_3 -> V_80 ,
V_52 + V_3 -> V_70 ) ;
}
return NULL ;
}
static void F_41 ( struct V_1 * V_11 )
{
if ( V_11 == NULL )
return;
do {
int V_37 = 0 ;
struct V_1 * V_12 ;
V_12 = V_11 -> V_107 ;
if ( V_12 ) {
do {
if ( V_12 -> V_37 > V_37 )
V_37 = V_12 -> V_37 ;
} while ( ( V_12 = V_12 -> V_108 ) != V_11 -> V_107 );
}
V_11 -> V_37 = V_37 + 1 ;
} while ( ( V_11 = V_11 -> V_13 ) != NULL );
}
static void F_42 ( struct V_2 * V_3 , int V_23 )
{
struct V_1 * V_12 ;
unsigned int V_109 ;
if ( V_3 -> V_110 [ V_23 ] == 0 )
return;
for ( V_109 = 0 ; V_109 < V_3 -> V_7 . V_111 ; V_109 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_12 -> V_24 == V_23 ) {
V_12 -> V_103 = ( V_12 -> V_112 * V_12 -> V_113 * V_3 -> V_114 [ V_23 ] ) /
V_3 -> V_110 [ V_23 ] ;
}
if ( V_12 -> V_103 <= 0 ||
V_12 -> V_103 > 32 * F_44 ( V_12 -> V_44 ) -> V_115 ) {
F_45 ( L_1 ,
V_12 -> V_8 . V_4 , V_12 -> V_103 ) ;
V_12 -> V_103 = F_44 ( V_12 -> V_44 ) -> V_115 / 2 + 1 ;
}
}
}
}
static void F_46 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_44 ) ;
struct V_1 * V_116 = V_12 -> V_116 ;
unsigned int V_109 ;
int V_117 ;
if ( V_116 == NULL )
return;
for ( V_117 = 0 ; V_117 <= V_36 ; V_117 ++ ) {
if ( V_116 -> V_15 [ V_117 ] == V_12 && ! ( V_12 -> V_22 & ( 1 << V_117 ) ) )
V_116 -> V_15 [ V_117 ] = NULL ;
}
for ( V_117 = 0 ; V_117 <= V_36 ; V_117 ++ ) {
int V_37 = V_116 -> V_37 ;
if ( V_116 -> V_15 [ V_117 ] )
continue;
for ( V_109 = 0 ; V_109 < V_3 -> V_7 . V_111 ; V_109 ++ ) {
struct V_1 * V_118 ;
F_43 (c, &q->clhash.hash[h],
common.hnode) {
if ( V_118 -> V_116 == V_116 && V_118 -> V_37 < V_37 &&
V_118 -> V_22 & ( 1 << V_117 ) ) {
V_116 -> V_15 [ V_117 ] = V_118 ;
V_37 = V_118 -> V_37 ;
}
}
}
}
}
static void F_47 ( struct V_1 * V_12 , T_1 V_119 , T_1 V_120 , T_1 V_121 )
{
struct V_1 * V_116 = NULL ;
if ( V_119 == 0 ) {
V_116 = V_12 -> V_116 ;
if ( ! V_116 )
return;
V_119 = V_116 -> V_8 . V_4 ;
}
if ( V_116 == NULL || V_116 -> V_8 . V_4 != V_119 ) {
for ( V_116 = V_12 -> V_13 ; V_116 ; V_116 = V_116 -> V_13 )
if ( V_116 -> V_8 . V_4 == V_119 )
break;
}
if ( V_116 == NULL )
return;
if ( V_12 -> V_116 != V_116 ) {
V_12 -> V_22 = 0 ;
F_46 ( V_12 ) ;
V_12 -> V_116 = V_116 ;
V_12 -> V_22 = V_120 & V_121 ;
} else
V_12 -> V_22 = ( V_12 -> V_22 & ~ V_121 ) | ( V_120 & V_121 ) ;
F_46 ( V_12 ) ;
}
static void F_48 ( struct V_1 * V_11 )
{
struct V_1 * V_12 , * * V_122 ;
struct V_2 * V_3 = F_6 ( V_11 -> V_44 ) ;
F_49 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_11 -> V_13 ) {
V_122 = & V_11 -> V_108 ;
V_12 = * V_122 ;
do {
if ( V_12 == V_11 ) {
* V_122 = V_12 -> V_108 ;
break;
}
V_122 = & V_12 -> V_108 ;
} while ( ( V_12 = * V_122 ) != V_11 -> V_108 );
if ( V_11 -> V_13 -> V_107 == V_11 ) {
V_11 -> V_13 -> V_107 = V_11 -> V_108 ;
if ( V_11 -> V_108 == V_11 )
V_11 -> V_13 -> V_107 = NULL ;
}
} else {
F_50 ( V_11 -> V_108 != V_11 ) ;
}
}
static void F_51 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 -> V_44 ) ;
struct V_1 * V_123 = V_11 -> V_13 ;
V_11 -> V_108 = V_11 ;
F_52 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_123 == NULL )
return;
if ( V_123 -> V_107 == NULL ) {
V_123 -> V_107 = V_11 ;
} else {
V_11 -> V_108 = V_123 -> V_107 -> V_108 ;
V_123 -> V_107 -> V_108 = V_11 ;
}
}
static void
F_53 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
int V_23 ;
unsigned int V_109 ;
V_3 -> V_49 = 0 ;
V_3 -> V_81 = 0 ;
V_3 -> V_87 = NULL ;
V_3 -> V_98 = NULL ;
F_54 ( & V_3 -> V_80 ) ;
F_55 ( & V_3 -> V_79 ) ;
V_3 -> V_51 = V_71 ;
V_3 -> V_52 = F_14 () ;
for ( V_23 = 0 ; V_23 <= V_124 ; V_23 ++ )
V_3 -> V_47 [ V_23 ] = NULL ;
for ( V_109 = 0 ; V_109 < V_3 -> V_7 . V_111 ; V_109 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode) {
F_56 ( V_12 -> V_3 ) ;
V_12 -> V_48 = NULL ;
V_12 -> V_53 = V_86 ;
V_12 -> V_65 = V_12 -> V_96 ;
V_12 -> V_101 = V_12 -> V_103 ;
V_12 -> V_45 = V_12 -> V_24 ;
}
}
V_18 -> V_3 . V_59 = 0 ;
}
static int F_57 ( struct V_1 * V_12 , struct V_125 * V_126 )
{
if ( V_126 -> V_127 & V_128 ) {
V_12 -> V_90 = ( V_126 -> V_129 & V_130 ) ? NULL : V_12 -> V_13 ;
V_12 -> V_54 = ( V_126 -> V_129 & V_131 ) ? NULL : V_12 -> V_13 ;
}
if ( V_126 -> V_127 & V_132 )
V_12 -> V_66 = V_126 -> V_66 ;
if ( V_126 -> V_127 & V_133 )
V_12 -> V_134 = V_126 -> V_134 ;
if ( V_126 -> V_127 & V_135 )
V_12 -> V_67 = - ( long ) V_126 -> V_67 ;
if ( V_126 -> V_127 & V_136 ) {
V_12 -> V_96 = V_126 -> V_96 ;
V_12 -> V_65 = V_126 -> V_96 ;
}
if ( V_126 -> V_127 & V_137 )
V_12 -> V_64 = V_126 -> V_64 ;
return 0 ;
}
static void F_58 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_114 [ V_12 -> V_24 ] -- ;
V_3 -> V_110 [ V_12 -> V_24 ] -= V_12 -> V_112 ;
F_42 ( V_3 , V_12 -> V_24 ) ;
}
static void F_59 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_114 [ V_12 -> V_24 ] ++ ;
V_3 -> V_110 [ V_12 -> V_24 ] += V_12 -> V_112 ;
F_42 ( V_3 , V_12 -> V_24 ) ;
}
static int F_60 ( struct V_1 * V_12 , struct V_138 * V_139 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_44 ) ;
if ( V_139 -> V_113 )
V_12 -> V_113 = V_139 -> V_113 ;
if ( V_139 -> V_112 )
V_12 -> V_112 = V_139 -> V_112 ;
if ( V_139 -> V_24 ) {
V_12 -> V_24 = V_139 -> V_24 - 1 ;
V_12 -> V_45 = V_12 -> V_24 ;
if ( V_12 -> V_24 >= V_12 -> V_140 )
V_12 -> V_140 = V_124 - 1 ;
}
F_59 ( V_3 , V_12 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_12 , struct V_141 * V_142 )
{
F_47 ( V_12 , V_142 -> V_116 , V_142 -> V_22 , V_142 -> V_143 ) ;
return 0 ;
}
static int F_62 ( struct V_17 * V_18 , struct V_144 * V_145 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_144 * V_146 [ V_147 + 1 ] ;
struct V_148 * V_149 ;
int V_150 ;
F_63 ( & V_3 -> V_80 , V_18 ) ;
F_64 ( & V_3 -> V_79 , V_151 , V_83 ) ;
V_3 -> V_79 . V_152 = F_22 ;
if ( ! V_145 )
return - V_153 ;
V_150 = F_65 ( V_146 , V_147 , V_145 , V_154 , NULL ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_146 [ V_155 ] == NULL || V_146 [ V_156 ] == NULL )
return - V_153 ;
V_149 = F_66 ( V_146 [ V_156 ] ) ;
if ( ( V_3 -> V_21 . V_157 = F_67 ( V_149 , V_146 [ V_155 ] ) ) == NULL )
return - V_153 ;
V_150 = F_68 ( & V_3 -> V_7 ) ;
if ( V_150 < 0 )
goto V_158;
V_3 -> V_21 . V_108 = & V_3 -> V_21 ;
V_3 -> V_21 . V_8 . V_4 = V_18 -> V_29 ;
V_3 -> V_21 . V_44 = V_18 ;
V_3 -> V_21 . V_3 = F_69 ( V_18 -> V_159 , & V_160 ,
V_18 -> V_29 ) ;
if ( ! V_3 -> V_21 . V_3 )
V_3 -> V_21 . V_3 = & V_161 ;
else
F_70 ( V_3 -> V_21 . V_3 , true ) ;
V_3 -> V_21 . V_24 = V_124 - 1 ;
V_3 -> V_21 . V_140 = V_124 - 1 ;
V_3 -> V_21 . V_45 = V_124 - 1 ;
V_3 -> V_21 . V_113 = F_71 ( F_44 ( V_18 ) ) ;
V_3 -> V_21 . V_103 = V_3 -> V_21 . V_113 ;
V_3 -> V_21 . V_112 = V_3 -> V_21 . V_157 -> V_162 . V_162 ;
V_3 -> V_21 . V_66 = V_163 ;
V_3 -> V_21 . V_134 = V_3 -> V_21 . V_113 / 2 ;
V_3 -> V_21 . V_67 = - 0x7FFFFFFF ;
V_3 -> V_51 = V_71 ;
V_3 -> V_52 = F_14 () ;
F_51 ( & V_3 -> V_21 ) ;
if ( V_146 [ V_164 ] )
F_57 ( & V_3 -> V_21 , F_66 ( V_146 [ V_164 ] ) ) ;
F_59 ( V_3 , & V_3 -> V_21 ) ;
return 0 ;
V_158:
F_72 ( V_3 -> V_21 . V_157 ) ;
return V_150 ;
}
static int F_73 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_72 = F_74 ( V_10 ) ;
if ( F_75 ( V_10 , V_156 , sizeof( V_12 -> V_157 -> V_162 ) , & V_12 -> V_157 -> V_162 ) )
goto V_165;
return V_10 -> V_88 ;
V_165:
F_76 ( V_10 , V_72 ) ;
return - 1 ;
}
static int F_77 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_72 = F_74 ( V_10 ) ;
struct V_125 V_145 ;
V_145 . V_129 = 0 ;
if ( V_12 -> V_54 == NULL )
V_145 . V_129 |= V_131 ;
if ( V_12 -> V_90 == NULL )
V_145 . V_129 |= V_130 ;
V_145 . V_66 = V_12 -> V_66 ;
V_145 . V_37 = V_12 -> V_37 ;
V_145 . V_134 = V_12 -> V_134 ;
V_145 . V_96 = V_12 -> V_96 ;
V_145 . V_67 = ( T_1 ) ( - V_12 -> V_67 ) ;
V_145 . V_64 = V_12 -> V_64 ;
V_145 . V_127 = ~ 0 ;
if ( F_75 ( V_10 , V_164 , sizeof( V_145 ) , & V_145 ) )
goto V_165;
return V_10 -> V_88 ;
V_165:
F_76 ( V_10 , V_72 ) ;
return - 1 ;
}
static int F_78 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_72 = F_74 ( V_10 ) ;
struct V_138 V_145 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_129 = 0 ;
V_145 . V_113 = V_12 -> V_113 ;
V_145 . V_24 = V_12 -> V_24 + 1 ;
V_145 . V_45 = V_12 -> V_45 + 1 ;
V_145 . V_112 = V_12 -> V_112 ;
if ( F_75 ( V_10 , V_166 , sizeof( V_145 ) , & V_145 ) )
goto V_165;
return V_10 -> V_88 ;
V_165:
F_76 ( V_10 , V_72 ) ;
return - 1 ;
}
static int F_79 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_72 = F_74 ( V_10 ) ;
struct V_141 V_145 ;
if ( V_12 -> V_116 || V_12 -> V_22 ) {
V_145 . V_116 = V_12 -> V_116 ? V_12 -> V_116 -> V_8 . V_4 : 0 ;
V_145 . V_22 = V_12 -> V_22 ;
V_145 . V_143 = ~ 0 ;
if ( F_75 ( V_10 , V_167 , sizeof( V_145 ) , & V_145 ) )
goto V_165;
}
return V_10 -> V_88 ;
V_165:
F_76 ( V_10 , V_72 ) ;
return - 1 ;
}
static int F_80 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
if ( F_77 ( V_10 , V_12 ) < 0 ||
F_73 ( V_10 , V_12 ) < 0 ||
F_78 ( V_10 , V_12 ) < 0 ||
F_79 ( V_10 , V_12 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_81 ( struct V_17 * V_18 , struct V_9 * V_10 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_144 * V_168 ;
V_168 = F_82 ( V_10 , V_169 ) ;
if ( V_168 == NULL )
goto V_165;
if ( F_80 ( V_10 , & V_3 -> V_21 ) < 0 )
goto V_165;
return F_83 ( V_10 , V_168 ) ;
V_165:
F_84 ( V_10 , V_168 ) ;
return - 1 ;
}
static int
F_85 ( struct V_17 * V_18 , struct V_170 * V_171 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
V_3 -> V_21 . V_68 . V_65 = V_3 -> V_21 . V_65 ;
return F_86 ( V_171 , & V_3 -> V_21 . V_68 , sizeof( V_3 -> V_21 . V_68 ) ) ;
}
static int
F_87 ( struct V_17 * V_18 , unsigned long V_172 ,
struct V_9 * V_10 , struct V_173 * V_174 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
struct V_144 * V_168 ;
if ( V_12 -> V_13 )
V_174 -> V_175 = V_12 -> V_13 -> V_8 . V_4 ;
else
V_174 -> V_175 = V_176 ;
V_174 -> V_177 = V_12 -> V_8 . V_4 ;
V_174 -> V_178 = V_12 -> V_3 -> V_29 ;
V_168 = F_82 ( V_10 , V_169 ) ;
if ( V_168 == NULL )
goto V_165;
if ( F_80 ( V_10 , V_12 ) < 0 )
goto V_165;
return F_83 ( V_10 , V_168 ) ;
V_165:
F_84 ( V_10 , V_168 ) ;
return - 1 ;
}
static int
F_88 ( struct V_17 * V_18 , unsigned long V_172 ,
struct V_170 * V_171 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
V_12 -> V_68 . V_65 = V_12 -> V_65 ;
V_12 -> V_68 . V_53 = 0 ;
if ( V_12 -> V_53 != V_86 )
V_12 -> V_68 . V_53 = V_12 -> V_53 - V_3 -> V_52 ;
if ( F_89 ( F_90 ( V_18 ) ,
V_171 , NULL , & V_12 -> V_92 ) < 0 ||
F_91 ( V_171 , & V_12 -> V_179 ) < 0 ||
F_92 ( V_171 , NULL , & V_12 -> V_60 , V_12 -> V_3 -> V_3 . V_59 ) < 0 )
return - 1 ;
return F_86 ( V_171 , & V_12 -> V_68 , sizeof( V_12 -> V_68 ) ) ;
}
static int F_93 ( struct V_17 * V_18 , unsigned long V_172 , struct V_17 * V_14 ,
struct V_17 * * V_180 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
if ( V_14 == NULL ) {
V_14 = F_69 ( V_18 -> V_159 ,
& V_160 , V_12 -> V_8 . V_4 ) ;
if ( V_14 == NULL )
return - V_181 ;
}
* V_180 = F_94 ( V_18 , V_14 , & V_12 -> V_3 ) ;
return 0 ;
}
static struct V_17 * F_95 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
return V_12 -> V_3 ;
}
static void F_96 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
F_12 ( V_12 ) ;
}
static unsigned long F_97 ( struct V_17 * V_18 , T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
return ( unsigned long ) F_1 ( V_3 , V_4 ) ;
}
static void F_98 ( struct V_17 * V_18 , struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
F_50 ( V_12 -> V_182 ) ;
F_99 ( V_12 -> V_183 ) ;
F_100 ( V_12 -> V_3 ) ;
F_72 ( V_12 -> V_157 ) ;
F_101 ( & V_12 -> V_179 ) ;
if ( V_12 != & V_3 -> V_21 )
F_102 ( V_12 ) ;
}
static void F_103 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_184 * V_185 ;
struct V_1 * V_12 ;
unsigned int V_109 ;
#ifdef F_10
V_3 -> V_58 = NULL ;
#endif
for ( V_109 = 0 ; V_109 < V_3 -> V_7 . V_111 ; V_109 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode) {
F_99 ( V_12 -> V_183 ) ;
V_12 -> V_183 = NULL ;
}
}
for ( V_109 = 0 ; V_109 < V_3 -> V_7 . V_111 ; V_109 ++ ) {
F_104 (cl, next, &q->clhash.hash[h],
common.hnode)
F_98 ( V_18 , V_12 ) ;
}
F_105 ( & V_3 -> V_7 ) ;
}
static int
F_106 ( struct V_17 * V_18 , T_1 V_4 , T_1 V_186 , struct V_144 * * V_187 ,
unsigned long * V_172 )
{
int V_150 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) * V_172 ;
struct V_144 * V_145 = V_187 [ V_169 ] ;
struct V_144 * V_146 [ V_147 + 1 ] ;
struct V_1 * V_123 ;
struct V_188 * V_189 = NULL ;
if ( V_145 == NULL )
return - V_153 ;
V_150 = F_65 ( V_146 , V_147 , V_145 , V_154 , NULL ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_146 [ V_190 ] || V_146 [ V_191 ] )
return - V_192 ;
if ( V_12 ) {
if ( V_186 ) {
if ( V_12 -> V_13 &&
V_12 -> V_13 -> V_8 . V_4 != V_186 )
return - V_153 ;
if ( ! V_12 -> V_13 && V_186 != V_176 )
return - V_153 ;
}
if ( V_146 [ V_156 ] ) {
V_189 = F_67 ( F_66 ( V_146 [ V_156 ] ) ,
V_146 [ V_155 ] ) ;
if ( V_189 == NULL )
return - V_153 ;
}
if ( V_187 [ V_193 ] ) {
V_150 = F_107 ( & V_12 -> V_92 , NULL ,
& V_12 -> V_179 ,
NULL ,
F_90 ( V_18 ) ,
V_187 [ V_193 ] ) ;
if ( V_150 ) {
F_72 ( V_189 ) ;
return V_150 ;
}
}
F_108 ( V_18 ) ;
if ( V_12 -> V_48 != NULL )
F_12 ( V_12 ) ;
if ( V_189 ) {
F_72 ( V_12 -> V_157 ) ;
V_12 -> V_157 = V_189 ;
}
if ( V_146 [ V_164 ] )
F_57 ( V_12 , F_66 ( V_146 [ V_164 ] ) ) ;
if ( V_146 [ V_166 ] ) {
F_58 ( V_3 , V_12 ) ;
F_60 ( V_12 , F_66 ( V_146 [ V_166 ] ) ) ;
}
if ( V_146 [ V_167 ] )
F_61 ( V_12 , F_66 ( V_146 [ V_167 ] ) ) ;
if ( V_12 -> V_3 -> V_3 . V_59 )
F_11 ( V_12 ) ;
F_109 ( V_18 ) ;
return 0 ;
}
if ( V_186 == V_176 )
return - V_153 ;
if ( V_146 [ V_166 ] == NULL || V_146 [ V_156 ] == NULL ||
V_146 [ V_164 ] == NULL )
return - V_153 ;
V_189 = F_67 ( F_66 ( V_146 [ V_156 ] ) , V_146 [ V_155 ] ) ;
if ( V_189 == NULL )
return - V_153 ;
if ( V_4 ) {
V_150 = - V_153 ;
if ( F_7 ( V_4 ^ V_18 -> V_29 ) ||
F_1 ( V_3 , V_4 ) )
goto V_194;
} else {
int V_117 ;
V_4 = F_110 ( V_18 -> V_29 , 0x8000 ) ;
for ( V_117 = 0 ; V_117 < 0x8000 ; V_117 ++ ) {
if ( ++ V_3 -> V_195 >= 0x8000 )
V_3 -> V_195 = 1 ;
if ( F_1 ( V_3 , V_4 | V_3 -> V_195 ) == NULL )
break;
}
V_150 = - V_196 ;
if ( V_117 >= 0x8000 )
goto V_194;
V_4 = V_4 | V_3 -> V_195 ;
}
V_123 = & V_3 -> V_21 ;
if ( V_186 ) {
V_123 = F_1 ( V_3 , V_186 ) ;
V_150 = - V_153 ;
if ( V_123 == NULL )
goto V_194;
}
V_150 = - V_181 ;
V_12 = F_111 ( sizeof( * V_12 ) , V_197 ) ;
if ( V_12 == NULL )
goto V_194;
V_150 = F_112 ( & V_12 -> V_183 , & V_12 -> V_33 ) ;
if ( V_150 ) {
F_102 ( V_12 ) ;
return V_150 ;
}
if ( V_187 [ V_193 ] ) {
V_150 = F_113 ( & V_12 -> V_92 , NULL , & V_12 -> V_179 ,
NULL ,
F_90 ( V_18 ) ,
V_187 [ V_193 ] ) ;
if ( V_150 ) {
F_99 ( V_12 -> V_183 ) ;
F_102 ( V_12 ) ;
goto V_194;
}
}
V_12 -> V_157 = V_189 ;
V_189 = NULL ;
V_12 -> V_3 = F_69 ( V_18 -> V_159 , & V_160 , V_4 ) ;
if ( ! V_12 -> V_3 )
V_12 -> V_3 = & V_161 ;
else
F_70 ( V_12 -> V_3 , true ) ;
V_12 -> V_8 . V_4 = V_4 ;
V_12 -> V_13 = V_123 ;
V_12 -> V_44 = V_18 ;
V_12 -> V_113 = V_123 -> V_113 ;
V_12 -> V_103 = V_12 -> V_113 ;
V_12 -> V_112 = V_12 -> V_157 -> V_162 . V_162 ;
F_108 ( V_18 ) ;
F_51 ( V_12 ) ;
V_12 -> V_54 = V_12 -> V_13 ;
if ( V_12 -> V_13 != & V_3 -> V_21 )
V_12 -> V_90 = V_12 -> V_13 ;
F_41 ( V_123 ) ;
V_12 -> V_67 = - 0x7FFFFFFF ;
F_57 ( V_12 , F_66 ( V_146 [ V_164 ] ) ) ;
F_60 ( V_12 , F_66 ( V_146 [ V_166 ] ) ) ;
if ( V_12 -> V_66 == 0 )
V_12 -> V_66 = V_3 -> V_21 . V_66 ;
if ( V_12 -> V_96 == 0 )
V_12 -> V_96 = V_3 -> V_21 . V_96 ;
if ( V_12 -> V_134 == 0 )
V_12 -> V_134 = V_3 -> V_21 . V_134 ;
if ( V_146 [ V_167 ] )
F_61 ( V_12 , F_66 ( V_146 [ V_167 ] ) ) ;
F_109 ( V_18 ) ;
F_114 ( V_18 , & V_3 -> V_7 ) ;
* V_172 = ( unsigned long ) V_12 ;
return 0 ;
V_194:
F_72 ( V_189 ) ;
return V_150 ;
}
static int F_115 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
unsigned int V_59 , V_198 ;
if ( V_12 -> V_182 || V_12 -> V_107 || V_12 == & V_3 -> V_21 )
return - V_199 ;
F_108 ( V_18 ) ;
V_59 = V_12 -> V_3 -> V_3 . V_59 ;
V_198 = V_12 -> V_3 -> V_60 . V_198 ;
F_56 ( V_12 -> V_3 ) ;
F_116 ( V_12 -> V_3 , V_59 , V_198 ) ;
if ( V_12 -> V_48 )
F_12 ( V_12 ) ;
if ( V_3 -> V_98 == V_12 )
V_3 -> V_98 = V_3 -> V_87 ;
if ( V_3 -> V_87 == V_12 ) {
V_3 -> V_87 = NULL ;
V_3 -> V_98 = NULL ;
}
#ifdef F_10
if ( V_3 -> V_58 == V_12 )
V_3 -> V_58 = NULL ;
#endif
F_48 ( V_12 ) ;
F_41 ( V_12 -> V_13 ) ;
V_12 -> V_22 = 0 ;
F_46 ( V_12 ) ;
F_58 ( V_3 , V_12 ) ;
F_109 ( V_18 ) ;
F_98 ( V_18 , V_12 ) ;
return 0 ;
}
static struct V_200 * F_117 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
if ( V_12 == NULL )
V_12 = & V_3 -> V_21 ;
return V_12 -> V_183 ;
}
static unsigned long F_118 ( struct V_17 * V_18 , unsigned long V_123 ,
T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_201 = (struct V_1 * ) V_123 ;
struct V_1 * V_12 = F_1 ( V_3 , V_4 ) ;
if ( V_12 ) {
if ( V_201 && V_201 -> V_37 <= V_12 -> V_37 )
return 0 ;
V_12 -> V_182 ++ ;
return ( unsigned long ) V_12 ;
}
return 0 ;
}
static void F_119 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
V_12 -> V_182 -- ;
}
static void F_120 ( struct V_17 * V_18 , struct V_202 * V_172 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
unsigned int V_109 ;
if ( V_172 -> V_203 )
return;
for ( V_109 = 0 ; V_109 < V_3 -> V_7 . V_111 ; V_109 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_172 -> V_204 < V_172 -> V_205 ) {
V_172 -> V_204 ++ ;
continue;
}
if ( V_172 -> V_206 ( V_18 , ( unsigned long ) V_12 , V_172 ) < 0 ) {
V_172 -> V_203 = 1 ;
return;
}
V_172 -> V_204 ++ ;
}
}
}
static int T_5 F_121 ( void )
{
return F_122 ( & V_207 ) ;
}
static void T_6 F_123 ( void )
{
F_124 ( & V_207 ) ;
}
