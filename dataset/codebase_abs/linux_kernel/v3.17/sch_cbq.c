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
struct V_25 V_26 ;
if ( F_7 ( V_23 ^ V_18 -> V_27 ) == 0 &&
( V_12 = F_1 ( V_3 , V_23 ) ) != NULL )
return V_12 ;
* V_19 = V_28 | V_29 ;
for (; ; ) {
int V_30 = 0 ;
V_22 = V_20 -> V_15 ;
if ( ! V_20 -> V_31 ||
( V_30 = F_8 ( V_10 , V_20 -> V_31 , & V_26 ) ) < 0 )
goto V_32;
V_12 = ( void * ) V_26 . V_33 ;
if ( ! V_12 ) {
if ( F_7 ( V_26 . V_4 ) )
V_12 = F_1 ( V_3 , V_26 . V_4 ) ;
else if ( ( V_12 = V_22 [ V_26 . V_4 & V_34 ] ) == NULL )
V_12 = V_22 [ V_16 ] ;
if ( V_12 == NULL )
goto V_32;
}
if ( V_12 -> V_35 >= V_20 -> V_35 )
goto V_32;
#ifdef F_9
switch ( V_30 ) {
case V_36 :
case V_37 :
* V_19 = V_28 | V_38 ;
case V_39 :
return NULL ;
case V_40 :
return F_4 ( V_10 , V_12 ) ;
}
#endif
if ( V_12 -> V_35 == 0 )
return V_12 ;
V_20 = V_12 ;
}
V_32:
V_12 = V_20 ;
if ( F_7 ( V_23 ) == 0 &&
! ( V_12 = V_20 -> V_15 [ V_23 & V_34 ] ) &&
! ( V_12 = V_20 -> V_15 [ V_16 ] ) )
return V_20 ;
return V_12 ;
}
static inline void F_10 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
int V_23 = V_12 -> V_42 ;
struct V_1 * V_43 ;
V_43 = V_3 -> V_44 [ V_23 ] ;
V_3 -> V_44 [ V_23 ] = V_12 ;
if ( V_43 != NULL ) {
V_12 -> V_45 = V_43 -> V_45 ;
V_43 -> V_45 = V_12 ;
} else {
V_12 -> V_45 = V_12 ;
V_3 -> V_46 |= ( 1 << V_23 ) ;
}
}
static void F_11 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 -> V_41 ) ;
int V_23 = V_11 -> V_42 ;
struct V_1 * V_12 ;
struct V_1 * V_47 = V_3 -> V_44 [ V_23 ] ;
do {
V_12 = V_47 -> V_45 ;
if ( V_12 == V_11 ) {
V_47 -> V_45 = V_12 -> V_45 ;
V_12 -> V_45 = NULL ;
if ( V_12 == V_3 -> V_44 [ V_23 ] ) {
V_3 -> V_44 [ V_23 ] = V_47 ;
if ( V_12 == V_3 -> V_44 [ V_23 ] ) {
V_3 -> V_44 [ V_23 ] = NULL ;
V_3 -> V_46 &= ~ ( 1 << V_23 ) ;
return;
}
}
return;
}
} while ( ( V_47 = V_12 ) != V_3 -> V_44 [ V_23 ] );
}
static void
F_12 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
int V_48 = V_3 -> V_48 ;
if ( V_48 > V_12 -> V_35 && ! ( F_13 ( V_12 -> V_3 ) ) ) {
T_2 V_49 = F_14 () ;
do {
if ( V_12 -> V_50 < V_49 ) {
V_3 -> V_48 = V_12 -> V_35 ;
return;
}
} while ( ( V_12 = V_12 -> V_51 ) != NULL && V_48 > V_12 -> V_35 );
}
}
static int
F_15 ( struct V_9 * V_10 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
int V_52 ( V_53 ) ;
struct V_1 * V_12 = F_5 ( V_10 , V_18 , & V_53 ) ;
#ifdef F_9
V_3 -> V_54 = V_12 ;
#endif
if ( V_12 == NULL ) {
if ( V_53 & V_29 )
V_18 -> V_55 . V_56 ++ ;
F_16 ( V_10 ) ;
return V_53 ;
}
#ifdef F_9
V_12 -> V_3 -> V_57 = V_18 ;
#endif
V_53 = F_17 ( V_10 , V_12 -> V_3 ) ;
if ( V_53 == V_28 ) {
V_18 -> V_3 . V_58 ++ ;
F_12 ( V_3 , V_12 ) ;
if ( ! V_12 -> V_45 )
F_10 ( V_12 ) ;
return V_53 ;
}
if ( F_18 ( V_53 ) ) {
V_18 -> V_55 . V_56 ++ ;
F_12 ( V_3 , V_12 ) ;
V_12 -> V_55 . V_56 ++ ;
}
return V_53 ;
}
static void F_19 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
T_3 V_59 = V_12 -> V_50 - V_3 -> V_49 ;
if ( ! V_12 -> V_60 ) {
V_59 += V_12 -> V_61 ;
if ( V_12 -> V_62 < 0 )
V_59 -= ( - V_12 -> V_62 ) - ( ( - V_12 -> V_62 ) >> V_12 -> V_63 ) ;
if ( V_12 -> V_62 < V_12 -> V_64 )
V_12 -> V_62 = V_12 -> V_64 ;
if ( V_59 <= 0 )
V_59 = 1 ;
V_12 -> V_50 = V_3 -> V_49 + V_59 ;
V_12 -> V_65 . V_66 ++ ;
V_12 -> V_60 = 1 ;
}
if ( V_3 -> V_67 == 0 || V_3 -> V_67 > V_59 )
V_3 -> V_67 = V_59 ;
if ( V_3 -> V_48 == V_68 ) {
struct V_1 * V_69 ;
T_3 V_70 = V_3 -> V_67 ;
for ( V_69 = V_12 -> V_51 ; V_69 ; V_69 = V_69 -> V_51 ) {
V_59 = V_69 -> V_50 - V_3 -> V_49 ;
if ( V_59 < V_70 ) {
if ( V_59 <= 0 )
V_59 = 1 ;
V_70 = V_59 ;
}
}
V_3 -> V_67 = V_70 ;
}
}
static void F_20 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
struct V_1 * V_11 = V_12 ;
do {
if ( V_12 -> V_35 > V_3 -> V_48 ) {
V_12 = NULL ;
break;
}
} while ( ( V_12 = V_12 -> V_51 ) != NULL );
if ( V_12 == NULL )
V_12 = V_11 ;
F_19 ( V_12 ) ;
}
static void F_21 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
T_3 V_59 = V_12 -> V_50 - V_3 -> V_49 ;
if ( F_22 ( V_71 ,
& F_23 ( V_12 -> V_41 ) -> V_72 ) )
return;
if ( ! V_12 -> V_60 ) {
T_2 V_73 = V_3 -> V_49 ;
T_4 V_74 ;
V_59 += V_12 -> V_61 ;
if ( V_12 -> V_62 < 0 )
V_59 -= ( - V_12 -> V_62 ) - ( ( - V_12 -> V_62 ) >> V_12 -> V_63 ) ;
if ( V_12 -> V_62 < V_12 -> V_64 )
V_12 -> V_62 = V_12 -> V_64 ;
V_12 -> V_50 = V_3 -> V_49 + V_59 ;
if ( V_59 > 0 ) {
V_73 += V_59 + V_12 -> V_75 ;
V_12 -> V_76 = V_73 ;
V_12 -> V_42 = V_77 ;
V_3 -> V_78 |= ( 1 << V_77 ) ;
V_74 = F_24 ( F_25 ( V_73 ) ) ;
if ( F_26 ( & V_3 -> V_79 ) &&
F_27 ( F_28 (
F_29 ( & V_3 -> V_79 ) ,
V_74 ) ) > 0 )
F_30 ( & V_3 -> V_79 , V_74 ) ;
F_31 ( & V_3 -> V_79 ) ;
V_12 -> V_60 = 1 ;
V_12 -> V_65 . V_66 ++ ;
return;
}
V_59 = 1 ;
}
if ( V_3 -> V_67 == 0 || V_3 -> V_67 > V_59 )
V_3 -> V_67 = V_59 ;
}
static void F_32 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
V_12 -> V_76 = V_3 -> V_49 + V_12 -> V_75 ;
if ( V_12 -> V_42 != V_12 -> V_80 ) {
V_12 -> V_42 = V_12 -> V_80 ;
V_3 -> V_78 |= ( 1 << V_12 -> V_42 ) ;
V_12 -> V_65 . V_66 ++ ;
}
F_19 ( V_12 ) ;
}
static void F_33 ( struct V_1 * V_12 )
{
if ( V_12 -> V_3 -> V_81 -> V_82 )
if ( V_12 -> V_3 -> V_81 -> V_82 ( V_12 -> V_3 ) )
V_12 -> V_41 -> V_3 . V_58 -- ;
V_12 -> V_65 . V_66 ++ ;
F_19 ( V_12 ) ;
}
static T_3 F_34 ( struct V_2 * V_3 , int V_23 ,
T_2 V_49 )
{
struct V_1 * V_12 ;
struct V_1 * V_47 = V_3 -> V_44 [ V_23 ] ;
T_2 V_73 = V_49 ;
if ( V_47 == NULL )
return 0 ;
do {
V_12 = V_47 -> V_45 ;
if ( V_49 - V_12 -> V_76 > 0 ) {
V_47 -> V_45 = V_12 -> V_45 ;
V_12 -> V_45 = NULL ;
V_12 -> V_42 = V_12 -> V_24 ;
V_12 -> V_60 = 0 ;
F_10 ( V_12 ) ;
if ( V_12 == V_3 -> V_44 [ V_23 ] ) {
V_3 -> V_44 [ V_23 ] = V_47 ;
if ( V_12 == V_3 -> V_44 [ V_23 ] ) {
V_3 -> V_44 [ V_23 ] = NULL ;
return 0 ;
}
}
V_12 = V_47 -> V_45 ;
} else if ( V_73 - V_12 -> V_76 > 0 )
V_73 = V_12 -> V_76 ;
} while ( ( V_47 = V_12 ) != V_3 -> V_44 [ V_23 ] );
return V_73 - V_49 ;
}
static enum F_31 F_35 ( struct V_83 * V_84 )
{
struct V_2 * V_3 = F_3 ( V_84 , struct V_2 ,
V_79 ) ;
struct V_17 * V_18 = V_3 -> V_85 . V_41 ;
T_2 V_49 ;
T_3 V_59 = 0 ;
unsigned int V_78 ;
V_49 = F_14 () ;
V_78 = V_3 -> V_78 ;
V_3 -> V_78 = 0 ;
while ( V_78 ) {
int V_23 = F_36 ( ~ V_78 ) ;
T_3 V_86 ;
V_78 &= ~ ( 1 << V_23 ) ;
V_86 = F_34 ( V_3 , V_23 , V_49 ) ;
if ( V_86 > 0 ) {
V_3 -> V_78 |= 1 << V_23 ;
if ( V_86 < V_59 || V_59 == 0 )
V_59 = V_86 ;
}
}
if ( V_59 ) {
T_4 time ;
time = F_37 ( 0 , 0 ) ;
time = F_38 ( time , F_25 ( V_49 + V_59 ) ) ;
F_39 ( & V_3 -> V_79 , time , V_87 ) ;
}
F_40 ( V_18 ) ;
F_41 ( F_42 ( V_18 ) ) ;
return V_88 ;
}
static int F_43 ( struct V_9 * V_10 , struct V_17 * V_89 )
{
struct V_17 * V_18 = V_89 -> V_57 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = V_3 -> V_54 ;
V_3 -> V_54 = NULL ;
if ( V_12 && ( V_12 = F_4 ( V_10 , V_12 ) ) != NULL ) {
int V_53 ;
F_12 ( V_3 , V_12 ) ;
V_3 -> V_54 = V_12 ;
V_12 -> V_3 -> V_57 = V_18 ;
V_53 = F_17 ( V_10 , V_12 -> V_3 ) ;
if ( V_53 == V_28 ) {
V_18 -> V_3 . V_58 ++ ;
if ( ! V_12 -> V_45 )
F_10 ( V_12 ) ;
return 0 ;
}
if ( F_18 ( V_53 ) )
V_18 -> V_55 . V_56 ++ ;
return 0 ;
}
V_18 -> V_55 . V_56 ++ ;
return - 1 ;
}
static inline void
F_44 ( struct V_2 * V_3 , struct V_1 * V_12 ,
struct V_1 * V_90 )
{
if ( V_12 && V_3 -> V_48 >= V_90 -> V_35 ) {
if ( V_12 -> V_3 -> V_3 . V_58 > 1 ) {
do {
if ( V_90 -> V_50 == V_91 ) {
V_3 -> V_48 = V_90 -> V_35 ;
return;
}
} while ( ( V_90 = V_90 -> V_51 ) != NULL );
}
#if 0
q->toplevel = TC_CBQ_MAXLEVEL;
#endif
}
}
static void
F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = V_3 -> V_92 ;
struct V_1 * V_12 = V_11 ;
int V_93 = V_3 -> V_94 ;
T_2 V_49 ;
V_3 -> V_92 = NULL ;
V_49 = V_3 -> V_49 + F_46 ( & V_3 -> V_21 , V_93 ) ;
for ( ; V_12 ; V_12 = V_12 -> V_95 ) {
long V_62 = V_12 -> V_62 ;
long V_96 ;
V_12 -> V_97 . V_98 ++ ;
V_12 -> V_97 . V_99 += V_93 ;
V_96 = V_49 - V_12 -> V_100 ;
if ( ( unsigned long ) V_96 > 128 * 1024 * 1024 ) {
V_62 = V_12 -> V_101 ;
} else {
V_96 -= F_46 ( V_12 , V_93 ) ;
V_62 += V_96 - ( V_62 >> V_12 -> V_63 ) ;
}
if ( V_62 <= 0 ) {
if ( V_62 < V_12 -> V_64 )
V_62 = V_12 -> V_64 ;
V_12 -> V_62 = V_62 ;
V_96 = ( - V_62 ) - ( ( - V_62 ) >> V_12 -> V_63 ) ;
V_96 -= F_46 ( & V_3 -> V_21 , V_93 ) ;
V_96 += F_46 ( V_12 , V_93 ) ;
V_12 -> V_50 = V_49 + V_96 ;
} else {
V_12 -> V_50 = V_91 ;
if ( V_62 > V_12 -> V_101 )
V_12 -> V_62 = V_12 -> V_101 ;
else
V_12 -> V_62 = V_62 ;
}
if ( ( V_102 ) ( V_49 - V_12 -> V_100 ) > 0 )
V_12 -> V_100 = V_49 ;
}
F_44 ( V_3 , V_11 , V_3 -> V_103 ) ;
}
static inline struct V_1 *
F_47 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
struct V_1 * V_104 = V_12 ;
if ( V_12 -> V_13 == NULL )
return V_12 ;
if ( V_12 -> V_50 == V_91 || V_3 -> V_49 >= V_12 -> V_50 ) {
V_12 -> V_60 = 0 ;
return V_12 ;
}
do {
V_12 = V_12 -> V_51 ;
if ( ! V_12 ) {
V_104 -> V_55 . V_105 ++ ;
V_104 -> V_106 ( V_104 ) ;
return NULL ;
}
if ( V_12 -> V_35 > V_3 -> V_48 )
return NULL ;
} while ( V_12 -> V_50 != V_91 && V_3 -> V_49 < V_12 -> V_50 );
V_12 -> V_60 = 0 ;
return V_12 ;
}
static inline struct V_9 *
F_48 ( struct V_17 * V_18 , int V_23 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_43 , * V_47 , * V_12 ;
struct V_9 * V_10 ;
int V_107 ;
V_43 = V_47 = V_3 -> V_44 [ V_23 ] ;
V_12 = V_47 -> V_45 ;
do {
V_107 = 0 ;
do {
struct V_1 * V_51 = V_12 ;
if ( V_12 -> V_3 -> V_3 . V_58 &&
( V_51 = F_47 ( V_12 ) ) == NULL )
goto V_108;
if ( V_12 -> V_107 <= 0 ) {
V_107 = 1 ;
V_12 -> V_107 += V_12 -> V_109 ;
goto V_110;
}
V_10 = V_12 -> V_3 -> V_111 ( V_12 -> V_3 ) ;
if ( V_10 == NULL )
goto V_108;
V_12 -> V_107 -= F_49 ( V_10 ) ;
V_3 -> V_92 = V_12 ;
V_3 -> V_103 = V_51 ;
if ( V_51 != V_12 ) {
#ifndef F_50
V_51 -> V_65 . V_112 ++ ;
V_12 -> V_65 . V_112 ++ ;
#else
V_51 -> V_65 . V_112 += F_49 ( V_10 ) ;
V_12 -> V_65 . V_112 += F_49 ( V_10 ) ;
#endif
}
V_3 -> V_94 = F_49 ( V_10 ) ;
if ( V_12 -> V_107 <= 0 ) {
V_3 -> V_44 [ V_23 ] = V_12 ;
V_12 = V_12 -> V_45 ;
V_12 -> V_107 += V_12 -> V_109 ;
}
return V_10 ;
V_108:
if ( V_12 -> V_3 -> V_3 . V_58 == 0 || V_23 != V_12 -> V_42 ) {
V_47 -> V_45 = V_12 -> V_45 ;
V_12 -> V_45 = NULL ;
if ( V_12 == V_43 ) {
V_43 = V_47 ;
if ( V_12 == V_43 ) {
V_3 -> V_44 [ V_23 ] = NULL ;
V_3 -> V_46 &= ~ ( 1 << V_23 ) ;
if ( V_12 -> V_3 -> V_3 . V_58 )
F_10 ( V_12 ) ;
return NULL ;
}
V_3 -> V_44 [ V_23 ] = V_43 ;
}
if ( V_12 -> V_3 -> V_3 . V_58 )
F_10 ( V_12 ) ;
V_12 = V_47 ;
}
V_110:
V_47 = V_12 ;
V_12 = V_12 -> V_45 ;
} while ( V_47 != V_43 );
} while ( V_107 );
V_3 -> V_44 [ V_23 ] = V_47 ;
return NULL ;
}
static inline struct V_9 *
F_51 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_9 * V_10 ;
unsigned int V_46 ;
V_46 = V_3 -> V_46 & 0xFF ;
while ( V_46 ) {
int V_23 = F_36 ( ~ V_46 ) ;
V_46 &= ~ ( 1 << V_23 ) ;
V_10 = F_48 ( V_18 , V_23 ) ;
if ( V_10 )
return V_10 ;
}
return NULL ;
}
static struct V_9 *
F_52 ( struct V_17 * V_18 )
{
struct V_9 * V_10 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
T_2 V_49 ;
V_49 = F_14 () ;
if ( V_3 -> V_92 )
F_45 ( V_3 ) ;
V_3 -> V_49 = V_49 ;
for (; ; ) {
V_3 -> V_67 = 0 ;
V_10 = F_51 ( V_18 ) ;
if ( V_10 ) {
F_53 ( V_18 , V_10 ) ;
V_18 -> V_3 . V_58 -- ;
F_40 ( V_18 ) ;
return V_10 ;
}
if ( V_3 -> V_48 == V_68 &&
V_3 -> V_21 . V_50 == V_91 )
break;
V_3 -> V_48 = V_68 ;
V_3 -> V_21 . V_50 = V_91 ;
}
if ( V_18 -> V_3 . V_58 ) {
V_18 -> V_55 . V_105 ++ ;
if ( V_3 -> V_67 )
F_54 ( & V_3 -> V_85 ,
V_49 + V_3 -> V_67 ) ;
}
return NULL ;
}
static void F_55 ( struct V_1 * V_11 )
{
if ( V_11 == NULL )
return;
do {
int V_35 = 0 ;
struct V_1 * V_12 ;
V_12 = V_11 -> V_113 ;
if ( V_12 ) {
do {
if ( V_12 -> V_35 > V_35 )
V_35 = V_12 -> V_35 ;
} while ( ( V_12 = V_12 -> V_114 ) != V_11 -> V_113 );
}
V_11 -> V_35 = V_35 + 1 ;
} while ( ( V_11 = V_11 -> V_13 ) != NULL );
}
static void F_56 ( struct V_2 * V_3 , int V_23 )
{
struct V_1 * V_12 ;
unsigned int V_115 ;
if ( V_3 -> V_116 [ V_23 ] == 0 )
return;
for ( V_115 = 0 ; V_115 < V_3 -> V_7 . V_117 ; V_115 ++ ) {
F_57 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_12 -> V_24 == V_23 ) {
V_12 -> V_109 = ( V_12 -> V_118 * V_12 -> V_119 * V_3 -> V_120 [ V_23 ] ) /
V_3 -> V_116 [ V_23 ] ;
}
if ( V_12 -> V_109 <= 0 ||
V_12 -> V_109 > 32 * F_58 ( V_12 -> V_41 ) -> V_121 ) {
F_59 ( L_1 ,
V_12 -> V_8 . V_4 , V_12 -> V_109 ) ;
V_12 -> V_109 = F_58 ( V_12 -> V_41 ) -> V_121 / 2 + 1 ;
}
}
}
}
static void F_60 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
struct V_1 * V_122 = V_12 -> V_122 ;
unsigned int V_115 ;
int V_123 ;
if ( V_122 == NULL )
return;
for ( V_123 = 0 ; V_123 <= V_34 ; V_123 ++ ) {
if ( V_122 -> V_15 [ V_123 ] == V_12 && ! ( V_12 -> V_22 & ( 1 << V_123 ) ) )
V_122 -> V_15 [ V_123 ] = NULL ;
}
for ( V_123 = 0 ; V_123 <= V_34 ; V_123 ++ ) {
int V_35 = V_122 -> V_35 ;
if ( V_122 -> V_15 [ V_123 ] )
continue;
for ( V_115 = 0 ; V_115 < V_3 -> V_7 . V_117 ; V_115 ++ ) {
struct V_1 * V_124 ;
F_57 (c, &q->clhash.hash[h],
common.hnode) {
if ( V_124 -> V_122 == V_122 && V_124 -> V_35 < V_35 &&
V_124 -> V_22 & ( 1 << V_123 ) ) {
V_122 -> V_15 [ V_123 ] = V_124 ;
V_35 = V_124 -> V_35 ;
}
}
}
}
}
static void F_61 ( struct V_1 * V_12 , T_1 V_125 , T_1 V_126 , T_1 V_127 )
{
struct V_1 * V_122 = NULL ;
if ( V_125 == 0 ) {
V_122 = V_12 -> V_122 ;
if ( ! V_122 )
return;
V_125 = V_122 -> V_8 . V_4 ;
}
if ( V_122 == NULL || V_122 -> V_8 . V_4 != V_125 ) {
for ( V_122 = V_12 -> V_13 ; V_122 ; V_122 = V_122 -> V_13 )
if ( V_122 -> V_8 . V_4 == V_125 )
break;
}
if ( V_122 == NULL )
return;
if ( V_12 -> V_122 != V_122 ) {
V_12 -> V_22 = 0 ;
F_60 ( V_12 ) ;
V_12 -> V_122 = V_122 ;
V_12 -> V_22 = V_126 & V_127 ;
} else
V_12 -> V_22 = ( V_12 -> V_22 & ~ V_127 ) | ( V_126 & V_127 ) ;
F_60 ( V_12 ) ;
}
static void F_62 ( struct V_1 * V_11 )
{
struct V_1 * V_12 , * * V_128 ;
struct V_2 * V_3 = F_6 ( V_11 -> V_41 ) ;
F_63 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_11 -> V_13 ) {
V_128 = & V_11 -> V_114 ;
V_12 = * V_128 ;
do {
if ( V_12 == V_11 ) {
* V_128 = V_12 -> V_114 ;
break;
}
V_128 = & V_12 -> V_114 ;
} while ( ( V_12 = * V_128 ) != V_11 -> V_114 );
if ( V_11 -> V_13 -> V_113 == V_11 ) {
V_11 -> V_13 -> V_113 = V_11 -> V_114 ;
if ( V_11 -> V_114 == V_11 )
V_11 -> V_13 -> V_113 = NULL ;
}
} else {
F_64 ( V_11 -> V_114 != V_11 ) ;
}
}
static void F_65 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 -> V_41 ) ;
struct V_1 * V_129 = V_11 -> V_13 ;
V_11 -> V_114 = V_11 ;
F_66 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_129 == NULL )
return;
if ( V_129 -> V_113 == NULL ) {
V_129 -> V_113 = V_11 ;
} else {
V_11 -> V_114 = V_129 -> V_113 -> V_114 ;
V_129 -> V_113 -> V_114 = V_11 ;
}
}
static unsigned int F_67 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 , * V_130 ;
int V_23 ;
unsigned int V_93 ;
for ( V_23 = V_77 ; V_23 >= 0 ; V_23 -- ) {
V_130 = V_3 -> V_44 [ V_23 ] ;
if ( ! V_130 )
continue;
V_12 = V_130 ;
do {
if ( V_12 -> V_3 -> V_81 -> V_82 && ( V_93 = V_12 -> V_3 -> V_81 -> V_82 ( V_12 -> V_3 ) ) ) {
V_18 -> V_3 . V_58 -- ;
if ( ! V_12 -> V_3 -> V_3 . V_58 )
F_11 ( V_12 ) ;
return V_93 ;
}
} while ( ( V_12 = V_12 -> V_45 ) != V_130 );
}
return 0 ;
}
static void
F_68 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
int V_23 ;
unsigned int V_115 ;
V_3 -> V_46 = 0 ;
V_3 -> V_78 = 0 ;
V_3 -> V_92 = NULL ;
V_3 -> V_103 = NULL ;
F_69 ( & V_3 -> V_85 ) ;
F_70 ( & V_3 -> V_79 ) ;
V_3 -> V_48 = V_68 ;
V_3 -> V_49 = F_14 () ;
for ( V_23 = 0 ; V_23 <= V_77 ; V_23 ++ )
V_3 -> V_44 [ V_23 ] = NULL ;
for ( V_115 = 0 ; V_115 < V_3 -> V_7 . V_117 ; V_115 ++ ) {
F_57 (cl, &q->clhash.hash[h], common.hnode) {
F_71 ( V_12 -> V_3 ) ;
V_12 -> V_45 = NULL ;
V_12 -> V_50 = V_91 ;
V_12 -> V_62 = V_12 -> V_101 ;
V_12 -> V_107 = V_12 -> V_109 ;
V_12 -> V_42 = V_12 -> V_24 ;
}
}
V_18 -> V_3 . V_58 = 0 ;
}
static int F_72 ( struct V_1 * V_12 , struct V_131 * V_132 )
{
if ( V_132 -> V_133 & V_134 ) {
V_12 -> V_95 = ( V_132 -> V_135 & V_136 ) ? NULL : V_12 -> V_13 ;
V_12 -> V_51 = ( V_132 -> V_135 & V_137 ) ? NULL : V_12 -> V_13 ;
}
if ( V_132 -> V_133 & V_138 )
V_12 -> V_63 = V_132 -> V_63 ;
if ( V_132 -> V_133 & V_139 )
V_12 -> V_140 = V_132 -> V_140 ;
if ( V_132 -> V_133 & V_141 )
V_12 -> V_64 = - ( long ) V_132 -> V_64 ;
if ( V_132 -> V_133 & V_142 ) {
V_12 -> V_101 = V_132 -> V_101 ;
V_12 -> V_62 = V_132 -> V_101 ;
}
if ( V_132 -> V_133 & V_143 )
V_12 -> V_61 = V_132 -> V_61 ;
return 0 ;
}
static void F_73 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_120 [ V_12 -> V_24 ] -- ;
V_3 -> V_116 [ V_12 -> V_24 ] -= V_12 -> V_118 ;
F_56 ( V_3 , V_12 -> V_24 ) ;
}
static void F_74 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_120 [ V_12 -> V_24 ] ++ ;
V_3 -> V_116 [ V_12 -> V_24 ] += V_12 -> V_118 ;
F_56 ( V_3 , V_12 -> V_24 ) ;
}
static int F_75 ( struct V_1 * V_12 , struct V_144 * V_145 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_41 ) ;
if ( V_145 -> V_119 )
V_12 -> V_119 = V_145 -> V_119 ;
if ( V_145 -> V_118 )
V_12 -> V_118 = V_145 -> V_118 ;
if ( V_145 -> V_24 ) {
V_12 -> V_24 = V_145 -> V_24 - 1 ;
V_12 -> V_42 = V_12 -> V_24 ;
if ( V_12 -> V_24 >= V_12 -> V_80 )
V_12 -> V_80 = V_77 - 1 ;
}
F_74 ( V_3 , V_12 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_12 , struct V_146 * V_147 )
{
switch ( V_147 -> V_148 ) {
case V_149 :
V_12 -> V_106 = F_19 ;
break;
case V_150 :
V_12 -> V_106 = F_21 ;
break;
case V_151 :
if ( V_147 -> V_80 - 1 >= V_77 ||
V_147 -> V_80 - 1 <= V_12 -> V_24 )
return - V_152 ;
V_12 -> V_80 = V_147 -> V_80 - 1 ;
V_12 -> V_106 = F_32 ;
break;
case V_153 :
V_12 -> V_106 = F_33 ;
break;
case V_154 :
V_12 -> V_106 = F_20 ;
break;
default:
return - V_152 ;
}
V_12 -> V_75 = V_147 -> V_75 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_12 , struct V_155 * V_156 )
{
V_12 -> V_157 = V_156 -> V_157 ;
if ( V_12 -> V_3 -> V_27 ) {
if ( V_156 -> V_157 == V_158 )
V_12 -> V_3 -> V_159 = F_43 ;
else
V_12 -> V_3 -> V_159 = NULL ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_12 , struct V_160 * V_161 )
{
F_61 ( V_12 , V_161 -> V_122 , V_161 -> V_22 , V_161 -> V_162 ) ;
return 0 ;
}
static int F_79 ( struct V_17 * V_18 , struct V_163 * V_164 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_163 * V_165 [ V_166 + 1 ] ;
struct V_167 * V_168 ;
int V_169 ;
V_169 = F_80 ( V_165 , V_166 , V_164 , V_170 ) ;
if ( V_169 < 0 )
return V_169 ;
if ( V_165 [ V_171 ] == NULL || V_165 [ V_172 ] == NULL )
return - V_152 ;
V_168 = F_81 ( V_165 [ V_172 ] ) ;
if ( ( V_3 -> V_21 . V_173 = F_82 ( V_168 , V_165 [ V_171 ] ) ) == NULL )
return - V_152 ;
V_169 = F_83 ( & V_3 -> V_7 ) ;
if ( V_169 < 0 )
goto V_174;
V_3 -> V_21 . V_175 = 1 ;
V_3 -> V_21 . V_114 = & V_3 -> V_21 ;
V_3 -> V_21 . V_8 . V_4 = V_18 -> V_27 ;
V_3 -> V_21 . V_41 = V_18 ;
V_3 -> V_21 . V_3 = F_84 ( V_18 -> V_176 , & V_177 ,
V_18 -> V_27 ) ;
if ( ! V_3 -> V_21 . V_3 )
V_3 -> V_21 . V_3 = & V_178 ;
V_3 -> V_21 . V_24 = V_77 - 1 ;
V_3 -> V_21 . V_80 = V_77 - 1 ;
V_3 -> V_21 . V_42 = V_77 - 1 ;
V_3 -> V_21 . V_179 = V_149 ;
V_3 -> V_21 . V_106 = F_19 ;
V_3 -> V_21 . V_119 = F_85 ( F_58 ( V_18 ) ) ;
V_3 -> V_21 . V_109 = V_3 -> V_21 . V_119 ;
V_3 -> V_21 . V_118 = V_3 -> V_21 . V_173 -> V_180 . V_180 ;
V_3 -> V_21 . V_63 = V_181 ;
V_3 -> V_21 . V_140 = V_3 -> V_21 . V_119 / 2 ;
V_3 -> V_21 . V_64 = - 0x7FFFFFFF ;
F_86 ( & V_3 -> V_85 , V_18 ) ;
F_87 ( & V_3 -> V_79 , V_182 , V_87 ) ;
V_3 -> V_79 . V_183 = F_35 ;
V_3 -> V_48 = V_68 ;
V_3 -> V_49 = F_14 () ;
F_65 ( & V_3 -> V_21 ) ;
if ( V_165 [ V_184 ] )
F_72 ( & V_3 -> V_21 , F_81 ( V_165 [ V_184 ] ) ) ;
F_74 ( V_3 , & V_3 -> V_21 ) ;
return 0 ;
V_174:
F_88 ( V_3 -> V_21 . V_173 ) ;
return V_169 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_69 = F_90 ( V_10 ) ;
if ( F_91 ( V_10 , V_172 , sizeof( V_12 -> V_173 -> V_180 ) , & V_12 -> V_173 -> V_180 ) )
goto V_185;
return V_10 -> V_93 ;
V_185:
F_92 ( V_10 , V_69 ) ;
return - 1 ;
}
static int F_93 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_69 = F_90 ( V_10 ) ;
struct V_131 V_164 ;
V_164 . V_135 = 0 ;
if ( V_12 -> V_51 == NULL )
V_164 . V_135 |= V_137 ;
if ( V_12 -> V_95 == NULL )
V_164 . V_135 |= V_136 ;
V_164 . V_63 = V_12 -> V_63 ;
V_164 . V_35 = V_12 -> V_35 ;
V_164 . V_140 = V_12 -> V_140 ;
V_164 . V_101 = V_12 -> V_101 ;
V_164 . V_64 = ( T_1 ) ( - V_12 -> V_64 ) ;
V_164 . V_61 = V_12 -> V_61 ;
V_164 . V_133 = ~ 0 ;
if ( F_91 ( V_10 , V_184 , sizeof( V_164 ) , & V_164 ) )
goto V_185;
return V_10 -> V_93 ;
V_185:
F_92 ( V_10 , V_69 ) ;
return - 1 ;
}
static int F_94 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_69 = F_90 ( V_10 ) ;
struct V_144 V_164 ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_135 = 0 ;
V_164 . V_119 = V_12 -> V_119 ;
V_164 . V_24 = V_12 -> V_24 + 1 ;
V_164 . V_42 = V_12 -> V_42 + 1 ;
V_164 . V_118 = V_12 -> V_118 ;
if ( F_91 ( V_10 , V_186 , sizeof( V_164 ) , & V_164 ) )
goto V_185;
return V_10 -> V_93 ;
V_185:
F_92 ( V_10 , V_69 ) ;
return - 1 ;
}
static int F_95 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_69 = F_90 ( V_10 ) ;
struct V_146 V_164 ;
V_164 . V_148 = V_12 -> V_179 ;
V_164 . V_80 = V_12 -> V_80 + 1 ;
V_164 . V_187 = 0 ;
V_164 . V_75 = V_12 -> V_75 ;
if ( F_91 ( V_10 , V_188 , sizeof( V_164 ) , & V_164 ) )
goto V_185;
return V_10 -> V_93 ;
V_185:
F_92 ( V_10 , V_69 ) ;
return - 1 ;
}
static int F_96 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_69 = F_90 ( V_10 ) ;
struct V_160 V_164 ;
if ( V_12 -> V_122 || V_12 -> V_22 ) {
V_164 . V_122 = V_12 -> V_122 ? V_12 -> V_122 -> V_8 . V_4 : 0 ;
V_164 . V_22 = V_12 -> V_22 ;
V_164 . V_162 = ~ 0 ;
if ( F_91 ( V_10 , V_189 , sizeof( V_164 ) , & V_164 ) )
goto V_185;
}
return V_10 -> V_93 ;
V_185:
F_92 ( V_10 , V_69 ) ;
return - 1 ;
}
static int F_97 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_69 = F_90 ( V_10 ) ;
struct V_155 V_164 ;
if ( V_12 -> V_157 ) {
V_164 . V_157 = V_12 -> V_157 ;
V_164 . V_190 = 0 ;
V_164 . V_191 = 0 ;
if ( F_91 ( V_10 , V_192 , sizeof( V_164 ) , & V_164 ) )
goto V_185;
}
return V_10 -> V_93 ;
V_185:
F_92 ( V_10 , V_69 ) ;
return - 1 ;
}
static int F_98 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
if ( F_93 ( V_10 , V_12 ) < 0 ||
F_89 ( V_10 , V_12 ) < 0 ||
F_94 ( V_10 , V_12 ) < 0 ||
F_95 ( V_10 , V_12 ) < 0 ||
#ifdef F_9
F_97 ( V_10 , V_12 ) < 0 ||
#endif
F_96 ( V_10 , V_12 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_99 ( struct V_17 * V_18 , struct V_9 * V_10 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_163 * V_193 ;
V_193 = F_100 ( V_10 , V_194 ) ;
if ( V_193 == NULL )
goto V_185;
if ( F_98 ( V_10 , & V_3 -> V_21 ) < 0 )
goto V_185;
return F_101 ( V_10 , V_193 ) ;
V_185:
F_102 ( V_10 , V_193 ) ;
return - 1 ;
}
static int
F_103 ( struct V_17 * V_18 , struct V_195 * V_196 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
V_3 -> V_21 . V_65 . V_62 = V_3 -> V_21 . V_62 ;
return F_104 ( V_196 , & V_3 -> V_21 . V_65 , sizeof( V_3 -> V_21 . V_65 ) ) ;
}
static int
F_105 ( struct V_17 * V_18 , unsigned long V_197 ,
struct V_9 * V_10 , struct V_198 * V_199 )
{
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
struct V_163 * V_193 ;
if ( V_12 -> V_13 )
V_199 -> V_200 = V_12 -> V_13 -> V_8 . V_4 ;
else
V_199 -> V_200 = V_201 ;
V_199 -> V_202 = V_12 -> V_8 . V_4 ;
V_199 -> V_203 = V_12 -> V_3 -> V_27 ;
V_193 = F_100 ( V_10 , V_194 ) ;
if ( V_193 == NULL )
goto V_185;
if ( F_98 ( V_10 , V_12 ) < 0 )
goto V_185;
return F_101 ( V_10 , V_193 ) ;
V_185:
F_102 ( V_10 , V_193 ) ;
return - 1 ;
}
static int
F_106 ( struct V_17 * V_18 , unsigned long V_197 ,
struct V_195 * V_196 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
V_12 -> V_55 . V_58 = V_12 -> V_3 -> V_3 . V_58 ;
V_12 -> V_65 . V_62 = V_12 -> V_62 ;
V_12 -> V_65 . V_50 = 0 ;
if ( V_12 -> V_50 != V_91 )
V_12 -> V_65 . V_50 = V_12 -> V_50 - V_3 -> V_49 ;
if ( F_107 ( V_196 , & V_12 -> V_97 ) < 0 ||
F_108 ( V_196 , & V_12 -> V_97 , & V_12 -> V_204 ) < 0 ||
F_109 ( V_196 , & V_12 -> V_55 ) < 0 )
return - 1 ;
return F_104 ( V_196 , & V_12 -> V_65 , sizeof( V_12 -> V_65 ) ) ;
}
static int F_110 ( struct V_17 * V_18 , unsigned long V_197 , struct V_17 * V_14 ,
struct V_17 * * V_205 )
{
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
if ( V_14 == NULL ) {
V_14 = F_84 ( V_18 -> V_176 ,
& V_177 , V_12 -> V_8 . V_4 ) ;
if ( V_14 == NULL )
return - V_206 ;
} else {
#ifdef F_9
if ( V_12 -> V_157 == V_158 )
V_14 -> V_159 = F_43 ;
#endif
}
F_111 ( V_18 ) ;
* V_205 = V_12 -> V_3 ;
V_12 -> V_3 = V_14 ;
F_112 ( * V_205 , ( * V_205 ) -> V_3 . V_58 ) ;
F_71 ( * V_205 ) ;
F_113 ( V_18 ) ;
return 0 ;
}
static struct V_17 * F_114 ( struct V_17 * V_18 , unsigned long V_197 )
{
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
return V_12 -> V_3 ;
}
static void F_115 ( struct V_17 * V_18 , unsigned long V_197 )
{
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
if ( V_12 -> V_3 -> V_3 . V_58 == 0 )
F_11 ( V_12 ) ;
}
static unsigned long F_116 ( struct V_17 * V_18 , T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = F_1 ( V_3 , V_4 ) ;
if ( V_12 ) {
V_12 -> V_175 ++ ;
return ( unsigned long ) V_12 ;
}
return 0 ;
}
static void F_117 ( struct V_17 * V_18 , struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
F_64 ( V_12 -> V_207 ) ;
F_118 ( & V_12 -> V_31 ) ;
F_119 ( V_12 -> V_3 ) ;
F_88 ( V_12 -> V_173 ) ;
F_120 ( & V_12 -> V_97 , & V_12 -> V_204 ) ;
if ( V_12 != & V_3 -> V_21 )
F_121 ( V_12 ) ;
}
static void F_122 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_208 * V_209 ;
struct V_1 * V_12 ;
unsigned int V_115 ;
#ifdef F_9
V_3 -> V_54 = NULL ;
#endif
for ( V_115 = 0 ; V_115 < V_3 -> V_7 . V_117 ; V_115 ++ ) {
F_57 (cl, &q->clhash.hash[h], common.hnode)
F_118 ( & V_12 -> V_31 ) ;
}
for ( V_115 = 0 ; V_115 < V_3 -> V_7 . V_117 ; V_115 ++ ) {
F_123 (cl, next, &q->clhash.hash[h],
common.hnode)
F_117 ( V_18 , V_12 ) ;
}
F_124 ( & V_3 -> V_7 ) ;
}
static void F_125 ( struct V_17 * V_18 , unsigned long V_197 )
{
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
if ( -- V_12 -> V_175 == 0 ) {
#ifdef F_9
T_5 * V_210 = F_126 ( V_18 ) ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
F_127 ( V_210 ) ;
if ( V_3 -> V_54 == V_12 )
V_3 -> V_54 = NULL ;
F_128 ( V_210 ) ;
#endif
F_117 ( V_18 , V_12 ) ;
}
}
static int
F_129 ( struct V_17 * V_18 , T_1 V_4 , T_1 V_211 , struct V_163 * * V_212 ,
unsigned long * V_197 )
{
int V_169 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) * V_197 ;
struct V_163 * V_164 = V_212 [ V_194 ] ;
struct V_163 * V_165 [ V_166 + 1 ] ;
struct V_1 * V_129 ;
struct V_213 * V_214 = NULL ;
if ( V_164 == NULL )
return - V_152 ;
V_169 = F_80 ( V_165 , V_166 , V_164 , V_170 ) ;
if ( V_169 < 0 )
return V_169 ;
if ( V_12 ) {
if ( V_211 ) {
if ( V_12 -> V_13 &&
V_12 -> V_13 -> V_8 . V_4 != V_211 )
return - V_152 ;
if ( ! V_12 -> V_13 && V_211 != V_201 )
return - V_152 ;
}
if ( V_165 [ V_172 ] ) {
V_214 = F_82 ( F_81 ( V_165 [ V_172 ] ) ,
V_165 [ V_171 ] ) ;
if ( V_214 == NULL )
return - V_152 ;
}
if ( V_212 [ V_215 ] ) {
V_169 = F_130 ( & V_12 -> V_97 , & V_12 -> V_204 ,
F_126 ( V_18 ) ,
V_212 [ V_215 ] ) ;
if ( V_169 ) {
F_88 ( V_214 ) ;
return V_169 ;
}
}
F_111 ( V_18 ) ;
if ( V_12 -> V_45 != NULL )
F_11 ( V_12 ) ;
if ( V_214 ) {
F_88 ( V_12 -> V_173 ) ;
V_12 -> V_173 = V_214 ;
}
if ( V_165 [ V_184 ] )
F_72 ( V_12 , F_81 ( V_165 [ V_184 ] ) ) ;
if ( V_165 [ V_186 ] ) {
F_73 ( V_3 , V_12 ) ;
F_75 ( V_12 , F_81 ( V_165 [ V_186 ] ) ) ;
}
if ( V_165 [ V_188 ] )
F_76 ( V_12 , F_81 ( V_165 [ V_188 ] ) ) ;
#ifdef F_9
if ( V_165 [ V_192 ] )
F_77 ( V_12 , F_81 ( V_165 [ V_192 ] ) ) ;
#endif
if ( V_165 [ V_189 ] )
F_78 ( V_12 , F_81 ( V_165 [ V_189 ] ) ) ;
if ( V_12 -> V_3 -> V_3 . V_58 )
F_10 ( V_12 ) ;
F_113 ( V_18 ) ;
return 0 ;
}
if ( V_211 == V_201 )
return - V_152 ;
if ( V_165 [ V_186 ] == NULL || V_165 [ V_172 ] == NULL ||
V_165 [ V_184 ] == NULL )
return - V_152 ;
V_214 = F_82 ( F_81 ( V_165 [ V_172 ] ) , V_165 [ V_171 ] ) ;
if ( V_214 == NULL )
return - V_152 ;
if ( V_4 ) {
V_169 = - V_152 ;
if ( F_7 ( V_4 ^ V_18 -> V_27 ) ||
F_1 ( V_3 , V_4 ) )
goto V_216;
} else {
int V_123 ;
V_4 = F_131 ( V_18 -> V_27 , 0x8000 ) ;
for ( V_123 = 0 ; V_123 < 0x8000 ; V_123 ++ ) {
if ( ++ V_3 -> V_217 >= 0x8000 )
V_3 -> V_217 = 1 ;
if ( F_1 ( V_3 , V_4 | V_3 -> V_217 ) == NULL )
break;
}
V_169 = - V_218 ;
if ( V_123 >= 0x8000 )
goto V_216;
V_4 = V_4 | V_3 -> V_217 ;
}
V_129 = & V_3 -> V_21 ;
if ( V_211 ) {
V_129 = F_1 ( V_3 , V_211 ) ;
V_169 = - V_152 ;
if ( V_129 == NULL )
goto V_216;
}
V_169 = - V_206 ;
V_12 = F_132 ( sizeof( * V_12 ) , V_219 ) ;
if ( V_12 == NULL )
goto V_216;
if ( V_212 [ V_215 ] ) {
V_169 = F_133 ( & V_12 -> V_97 , & V_12 -> V_204 ,
F_126 ( V_18 ) ,
V_212 [ V_215 ] ) ;
if ( V_169 ) {
F_121 ( V_12 ) ;
goto V_216;
}
}
V_12 -> V_173 = V_214 ;
V_214 = NULL ;
V_12 -> V_175 = 1 ;
V_12 -> V_3 = F_84 ( V_18 -> V_176 , & V_177 , V_4 ) ;
if ( ! V_12 -> V_3 )
V_12 -> V_3 = & V_178 ;
V_12 -> V_8 . V_4 = V_4 ;
V_12 -> V_13 = V_129 ;
V_12 -> V_41 = V_18 ;
V_12 -> V_119 = V_129 -> V_119 ;
V_12 -> V_109 = V_12 -> V_119 ;
V_12 -> V_118 = V_12 -> V_173 -> V_180 . V_180 ;
F_111 ( V_18 ) ;
F_65 ( V_12 ) ;
V_12 -> V_51 = V_12 -> V_13 ;
if ( V_12 -> V_13 != & V_3 -> V_21 )
V_12 -> V_95 = V_12 -> V_13 ;
F_55 ( V_129 ) ;
V_12 -> V_64 = - 0x7FFFFFFF ;
F_72 ( V_12 , F_81 ( V_165 [ V_184 ] ) ) ;
F_75 ( V_12 , F_81 ( V_165 [ V_186 ] ) ) ;
if ( V_12 -> V_63 == 0 )
V_12 -> V_63 = V_3 -> V_21 . V_63 ;
if ( V_12 -> V_101 == 0 )
V_12 -> V_101 = V_3 -> V_21 . V_101 ;
if ( V_12 -> V_140 == 0 )
V_12 -> V_140 = V_3 -> V_21 . V_140 ;
V_12 -> V_106 = F_19 ;
if ( V_165 [ V_188 ] )
F_76 ( V_12 , F_81 ( V_165 [ V_188 ] ) ) ;
#ifdef F_9
if ( V_165 [ V_192 ] )
F_77 ( V_12 , F_81 ( V_165 [ V_192 ] ) ) ;
#endif
if ( V_165 [ V_189 ] )
F_78 ( V_12 , F_81 ( V_165 [ V_189 ] ) ) ;
F_113 ( V_18 ) ;
F_134 ( V_18 , & V_3 -> V_7 ) ;
* V_197 = ( unsigned long ) V_12 ;
return 0 ;
V_216:
F_88 ( V_214 ) ;
return V_169 ;
}
static int F_135 ( struct V_17 * V_18 , unsigned long V_197 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
unsigned int V_58 ;
if ( V_12 -> V_207 || V_12 -> V_113 || V_12 == & V_3 -> V_21 )
return - V_220 ;
F_111 ( V_18 ) ;
V_58 = V_12 -> V_3 -> V_3 . V_58 ;
F_71 ( V_12 -> V_3 ) ;
F_112 ( V_12 -> V_3 , V_58 ) ;
if ( V_12 -> V_45 )
F_11 ( V_12 ) ;
if ( V_3 -> V_103 == V_12 )
V_3 -> V_103 = V_3 -> V_92 ;
if ( V_3 -> V_92 == V_12 ) {
V_3 -> V_92 = NULL ;
V_3 -> V_103 = NULL ;
}
#ifdef F_9
if ( V_3 -> V_54 == V_12 )
V_3 -> V_54 = NULL ;
#endif
F_62 ( V_12 ) ;
F_55 ( V_12 -> V_13 ) ;
V_12 -> V_22 = 0 ;
F_60 ( V_12 ) ;
F_73 ( V_3 , V_12 ) ;
F_113 ( V_18 ) ;
F_136 ( -- V_12 -> V_175 == 0 ) ;
return 0 ;
}
static struct V_221 * * F_137 ( struct V_17 * V_18 , unsigned long V_197 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
if ( V_12 == NULL )
V_12 = & V_3 -> V_21 ;
return & V_12 -> V_31 ;
}
static unsigned long F_138 ( struct V_17 * V_18 , unsigned long V_129 ,
T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_156 = (struct V_1 * ) V_129 ;
struct V_1 * V_12 = F_1 ( V_3 , V_4 ) ;
if ( V_12 ) {
if ( V_156 && V_156 -> V_35 <= V_12 -> V_35 )
return 0 ;
V_12 -> V_207 ++ ;
return ( unsigned long ) V_12 ;
}
return 0 ;
}
static void F_139 ( struct V_17 * V_18 , unsigned long V_197 )
{
struct V_1 * V_12 = (struct V_1 * ) V_197 ;
V_12 -> V_207 -- ;
}
static void F_140 ( struct V_17 * V_18 , struct V_222 * V_197 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
unsigned int V_115 ;
if ( V_197 -> V_223 )
return;
for ( V_115 = 0 ; V_115 < V_3 -> V_7 . V_117 ; V_115 ++ ) {
F_57 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_197 -> V_224 < V_197 -> V_225 ) {
V_197 -> V_224 ++ ;
continue;
}
if ( V_197 -> V_226 ( V_18 , ( unsigned long ) V_12 , V_197 ) < 0 ) {
V_197 -> V_223 = 1 ;
return;
}
V_197 -> V_224 ++ ;
}
}
}
static int T_6 F_141 ( void )
{
return F_142 ( & V_227 ) ;
}
static void T_7 F_143 ( void )
{
F_144 ( & V_227 ) ;
}
