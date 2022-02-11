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
* V_19 = V_30 | V_40 ;
case V_41 :
return NULL ;
case V_42 :
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
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
int V_23 = V_12 -> V_44 ;
struct V_1 * V_45 ;
V_45 = V_3 -> V_46 [ V_23 ] ;
V_3 -> V_46 [ V_23 ] = V_12 ;
if ( V_45 != NULL ) {
V_12 -> V_47 = V_45 -> V_47 ;
V_45 -> V_47 = V_12 ;
} else {
V_12 -> V_47 = V_12 ;
V_3 -> V_48 |= ( 1 << V_23 ) ;
}
}
static void F_12 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 -> V_43 ) ;
int V_23 = V_11 -> V_44 ;
struct V_1 * V_12 ;
struct V_1 * V_49 = V_3 -> V_46 [ V_23 ] ;
do {
V_12 = V_49 -> V_47 ;
if ( V_12 == V_11 ) {
V_49 -> V_47 = V_12 -> V_47 ;
V_12 -> V_47 = NULL ;
if ( V_12 == V_3 -> V_46 [ V_23 ] ) {
V_3 -> V_46 [ V_23 ] = V_49 ;
if ( V_12 == V_3 -> V_46 [ V_23 ] ) {
V_3 -> V_46 [ V_23 ] = NULL ;
V_3 -> V_48 &= ~ ( 1 << V_23 ) ;
return;
}
}
return;
}
} while ( ( V_49 = V_12 ) != V_3 -> V_46 [ V_23 ] );
}
static void
F_13 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
int V_50 = V_3 -> V_50 ;
if ( V_50 > V_12 -> V_37 && ! ( F_14 ( V_12 -> V_3 ) ) ) {
T_2 V_51 = F_15 () ;
do {
if ( V_12 -> V_52 < V_51 ) {
V_3 -> V_50 = V_12 -> V_37 ;
return;
}
} while ( ( V_12 = V_12 -> V_53 ) != NULL && V_50 > V_12 -> V_37 );
}
}
static int
F_16 ( struct V_9 * V_10 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
int V_54 ( V_55 ) ;
struct V_1 * V_12 = F_5 ( V_10 , V_18 , & V_55 ) ;
#ifdef F_10
V_3 -> V_56 = V_12 ;
#endif
if ( V_12 == NULL ) {
if ( V_55 & V_31 )
F_17 ( V_18 ) ;
F_18 ( V_10 ) ;
return V_55 ;
}
#ifdef F_10
V_12 -> V_3 -> V_57 = V_18 ;
#endif
V_55 = F_19 ( V_10 , V_12 -> V_3 ) ;
if ( V_55 == V_30 ) {
V_18 -> V_3 . V_58 ++ ;
F_13 ( V_3 , V_12 ) ;
if ( ! V_12 -> V_47 )
F_11 ( V_12 ) ;
return V_55 ;
}
if ( F_20 ( V_55 ) ) {
F_17 ( V_18 ) ;
F_13 ( V_3 , V_12 ) ;
V_12 -> V_59 . V_60 ++ ;
}
return V_55 ;
}
static void F_21 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
T_3 V_61 = V_12 -> V_52 - V_3 -> V_51 ;
if ( ! V_12 -> V_62 ) {
V_61 += V_12 -> V_63 ;
if ( V_12 -> V_64 < 0 )
V_61 -= ( - V_12 -> V_64 ) - ( ( - V_12 -> V_64 ) >> V_12 -> V_65 ) ;
if ( V_12 -> V_64 < V_12 -> V_66 )
V_12 -> V_64 = V_12 -> V_66 ;
if ( V_61 <= 0 )
V_61 = 1 ;
V_12 -> V_52 = V_3 -> V_51 + V_61 ;
V_12 -> V_67 . V_68 ++ ;
V_12 -> V_62 = 1 ;
}
if ( V_3 -> V_69 == 0 || V_3 -> V_69 > V_61 )
V_3 -> V_69 = V_61 ;
if ( V_3 -> V_50 == V_70 ) {
struct V_1 * V_71 ;
T_3 V_72 = V_3 -> V_69 ;
for ( V_71 = V_12 -> V_53 ; V_71 ; V_71 = V_71 -> V_53 ) {
V_61 = V_71 -> V_52 - V_3 -> V_51 ;
if ( V_61 < V_72 ) {
if ( V_61 <= 0 )
V_61 = 1 ;
V_72 = V_61 ;
}
}
V_3 -> V_69 = V_72 ;
}
}
static void F_22 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
struct V_1 * V_11 = V_12 ;
do {
if ( V_12 -> V_37 > V_3 -> V_50 ) {
V_12 = NULL ;
break;
}
} while ( ( V_12 = V_12 -> V_53 ) != NULL );
if ( V_12 == NULL )
V_12 = V_11 ;
F_21 ( V_12 ) ;
}
static void F_23 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
T_3 V_61 = V_12 -> V_52 - V_3 -> V_51 ;
if ( F_24 ( V_73 ,
& F_25 ( V_12 -> V_43 ) -> V_74 ) )
return;
if ( ! V_12 -> V_62 ) {
T_2 V_75 = V_3 -> V_51 ;
T_4 V_76 ;
V_61 += V_12 -> V_63 ;
if ( V_12 -> V_64 < 0 )
V_61 -= ( - V_12 -> V_64 ) - ( ( - V_12 -> V_64 ) >> V_12 -> V_65 ) ;
if ( V_12 -> V_64 < V_12 -> V_66 )
V_12 -> V_64 = V_12 -> V_66 ;
V_12 -> V_52 = V_3 -> V_51 + V_61 ;
if ( V_61 > 0 ) {
V_75 += V_61 + V_12 -> V_77 ;
V_12 -> V_78 = V_75 ;
V_12 -> V_44 = V_79 ;
V_3 -> V_80 |= ( 1 << V_79 ) ;
V_76 = F_26 ( F_27 ( V_75 ) ) ;
if ( F_28 ( & V_3 -> V_81 ) &&
F_29 ( F_30 (
F_31 ( & V_3 -> V_81 ) ,
V_76 ) ) > 0 )
F_32 ( & V_3 -> V_81 , V_76 ) ;
F_33 ( & V_3 -> V_81 ) ;
V_12 -> V_62 = 1 ;
V_12 -> V_67 . V_68 ++ ;
return;
}
V_61 = 1 ;
}
if ( V_3 -> V_69 == 0 || V_3 -> V_69 > V_61 )
V_3 -> V_69 = V_61 ;
}
static void F_34 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
V_12 -> V_78 = V_3 -> V_51 + V_12 -> V_77 ;
if ( V_12 -> V_44 != V_12 -> V_82 ) {
V_12 -> V_44 = V_12 -> V_82 ;
V_3 -> V_80 |= ( 1 << V_12 -> V_44 ) ;
V_12 -> V_67 . V_68 ++ ;
}
F_21 ( V_12 ) ;
}
static void F_35 ( struct V_1 * V_12 )
{
if ( V_12 -> V_3 -> V_83 -> V_84 )
if ( V_12 -> V_3 -> V_83 -> V_84 ( V_12 -> V_3 ) )
V_12 -> V_43 -> V_3 . V_58 -- ;
V_12 -> V_67 . V_68 ++ ;
F_21 ( V_12 ) ;
}
static T_3 F_36 ( struct V_2 * V_3 , int V_23 ,
T_2 V_51 )
{
struct V_1 * V_12 ;
struct V_1 * V_49 = V_3 -> V_46 [ V_23 ] ;
T_2 V_75 = V_51 ;
if ( V_49 == NULL )
return 0 ;
do {
V_12 = V_49 -> V_47 ;
if ( V_51 - V_12 -> V_78 > 0 ) {
V_49 -> V_47 = V_12 -> V_47 ;
V_12 -> V_47 = NULL ;
V_12 -> V_44 = V_12 -> V_24 ;
V_12 -> V_62 = 0 ;
F_11 ( V_12 ) ;
if ( V_12 == V_3 -> V_46 [ V_23 ] ) {
V_3 -> V_46 [ V_23 ] = V_49 ;
if ( V_12 == V_3 -> V_46 [ V_23 ] ) {
V_3 -> V_46 [ V_23 ] = NULL ;
return 0 ;
}
}
V_12 = V_49 -> V_47 ;
} else if ( V_75 - V_12 -> V_78 > 0 )
V_75 = V_12 -> V_78 ;
} while ( ( V_49 = V_12 ) != V_3 -> V_46 [ V_23 ] );
return V_75 - V_51 ;
}
static enum F_33 F_37 ( struct V_85 * V_86 )
{
struct V_2 * V_3 = F_3 ( V_86 , struct V_2 ,
V_81 ) ;
struct V_17 * V_18 = V_3 -> V_87 . V_43 ;
T_2 V_51 ;
T_3 V_61 = 0 ;
unsigned int V_80 ;
V_51 = F_15 () ;
V_80 = V_3 -> V_80 ;
V_3 -> V_80 = 0 ;
while ( V_80 ) {
int V_23 = F_38 ( ~ V_80 ) ;
T_3 V_88 ;
V_80 &= ~ ( 1 << V_23 ) ;
V_88 = F_36 ( V_3 , V_23 , V_51 ) ;
if ( V_88 > 0 ) {
V_3 -> V_80 |= 1 << V_23 ;
if ( V_88 < V_61 || V_61 == 0 )
V_61 = V_88 ;
}
}
if ( V_61 ) {
T_4 time ;
time = F_39 ( 0 , 0 ) ;
time = F_40 ( time , F_27 ( V_51 + V_61 ) ) ;
F_41 ( & V_3 -> V_81 , time , V_89 ) ;
}
F_42 ( V_18 ) ;
F_43 ( F_44 ( V_18 ) ) ;
return V_90 ;
}
static int F_45 ( struct V_9 * V_10 , struct V_17 * V_91 )
{
struct V_17 * V_18 = V_91 -> V_57 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = V_3 -> V_56 ;
V_3 -> V_56 = NULL ;
if ( V_12 && ( V_12 = F_4 ( V_10 , V_12 ) ) != NULL ) {
int V_55 ;
F_13 ( V_3 , V_12 ) ;
V_3 -> V_56 = V_12 ;
V_12 -> V_3 -> V_57 = V_18 ;
V_55 = F_19 ( V_10 , V_12 -> V_3 ) ;
if ( V_55 == V_30 ) {
V_18 -> V_3 . V_58 ++ ;
if ( ! V_12 -> V_47 )
F_11 ( V_12 ) ;
return 0 ;
}
if ( F_20 ( V_55 ) )
F_17 ( V_18 ) ;
return 0 ;
}
F_17 ( V_18 ) ;
return - 1 ;
}
static inline void
F_46 ( struct V_2 * V_3 , struct V_1 * V_12 ,
struct V_1 * V_92 )
{
if ( V_12 && V_3 -> V_50 >= V_92 -> V_37 ) {
if ( V_12 -> V_3 -> V_3 . V_58 > 1 ) {
do {
if ( V_92 -> V_52 == V_93 ) {
V_3 -> V_50 = V_92 -> V_37 ;
return;
}
} while ( ( V_92 = V_92 -> V_53 ) != NULL );
}
#if 0
q->toplevel = TC_CBQ_MAXLEVEL;
#endif
}
}
static void
F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = V_3 -> V_94 ;
struct V_1 * V_12 = V_11 ;
int V_95 = V_3 -> V_96 ;
T_2 V_51 ;
V_3 -> V_94 = NULL ;
V_51 = V_3 -> V_51 + F_48 ( & V_3 -> V_21 , V_95 ) ;
for ( ; V_12 ; V_12 = V_12 -> V_97 ) {
long V_64 = V_12 -> V_64 ;
long V_98 ;
V_12 -> V_99 . V_100 ++ ;
V_12 -> V_99 . V_101 += V_95 ;
V_98 = V_51 - V_12 -> V_102 ;
if ( ( unsigned long ) V_98 > 128 * 1024 * 1024 ) {
V_64 = V_12 -> V_103 ;
} else {
V_98 -= F_48 ( V_12 , V_95 ) ;
V_64 += V_98 - ( V_64 >> V_12 -> V_65 ) ;
}
if ( V_64 <= 0 ) {
if ( V_64 < V_12 -> V_66 )
V_64 = V_12 -> V_66 ;
V_12 -> V_64 = V_64 ;
V_98 = ( - V_64 ) - ( ( - V_64 ) >> V_12 -> V_65 ) ;
V_98 -= F_48 ( & V_3 -> V_21 , V_95 ) ;
V_98 += F_48 ( V_12 , V_95 ) ;
V_12 -> V_52 = V_51 + V_98 ;
} else {
V_12 -> V_52 = V_93 ;
if ( V_64 > V_12 -> V_103 )
V_12 -> V_64 = V_12 -> V_103 ;
else
V_12 -> V_64 = V_64 ;
}
if ( ( V_104 ) ( V_51 - V_12 -> V_102 ) > 0 )
V_12 -> V_102 = V_51 ;
}
F_46 ( V_3 , V_11 , V_3 -> V_105 ) ;
}
static inline struct V_1 *
F_49 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
struct V_1 * V_106 = V_12 ;
if ( V_12 -> V_13 == NULL )
return V_12 ;
if ( V_12 -> V_52 == V_93 || V_3 -> V_51 >= V_12 -> V_52 ) {
V_12 -> V_62 = 0 ;
return V_12 ;
}
do {
V_12 = V_12 -> V_53 ;
if ( ! V_12 ) {
V_106 -> V_59 . V_107 ++ ;
V_106 -> V_108 ( V_106 ) ;
return NULL ;
}
if ( V_12 -> V_37 > V_3 -> V_50 )
return NULL ;
} while ( V_12 -> V_52 != V_93 && V_3 -> V_51 < V_12 -> V_52 );
V_12 -> V_62 = 0 ;
return V_12 ;
}
static inline struct V_9 *
F_50 ( struct V_17 * V_18 , int V_23 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_45 , * V_49 , * V_12 ;
struct V_9 * V_10 ;
int V_109 ;
V_45 = V_49 = V_3 -> V_46 [ V_23 ] ;
V_12 = V_49 -> V_47 ;
do {
V_109 = 0 ;
do {
struct V_1 * V_53 = V_12 ;
if ( V_12 -> V_3 -> V_3 . V_58 &&
( V_53 = F_49 ( V_12 ) ) == NULL )
goto V_110;
if ( V_12 -> V_109 <= 0 ) {
V_109 = 1 ;
V_12 -> V_109 += V_12 -> V_111 ;
goto V_112;
}
V_10 = V_12 -> V_3 -> V_113 ( V_12 -> V_3 ) ;
if ( V_10 == NULL )
goto V_110;
V_12 -> V_109 -= F_51 ( V_10 ) ;
V_3 -> V_94 = V_12 ;
V_3 -> V_105 = V_53 ;
if ( V_53 != V_12 ) {
#ifndef F_52
V_53 -> V_67 . V_114 ++ ;
V_12 -> V_67 . V_114 ++ ;
#else
V_53 -> V_67 . V_114 += F_51 ( V_10 ) ;
V_12 -> V_67 . V_114 += F_51 ( V_10 ) ;
#endif
}
V_3 -> V_96 = F_51 ( V_10 ) ;
if ( V_12 -> V_109 <= 0 ) {
V_3 -> V_46 [ V_23 ] = V_12 ;
V_12 = V_12 -> V_47 ;
V_12 -> V_109 += V_12 -> V_111 ;
}
return V_10 ;
V_110:
if ( V_12 -> V_3 -> V_3 . V_58 == 0 || V_23 != V_12 -> V_44 ) {
V_49 -> V_47 = V_12 -> V_47 ;
V_12 -> V_47 = NULL ;
if ( V_12 == V_45 ) {
V_45 = V_49 ;
if ( V_12 == V_45 ) {
V_3 -> V_46 [ V_23 ] = NULL ;
V_3 -> V_48 &= ~ ( 1 << V_23 ) ;
if ( V_12 -> V_3 -> V_3 . V_58 )
F_11 ( V_12 ) ;
return NULL ;
}
V_3 -> V_46 [ V_23 ] = V_45 ;
}
if ( V_12 -> V_3 -> V_3 . V_58 )
F_11 ( V_12 ) ;
V_12 = V_49 ;
}
V_112:
V_49 = V_12 ;
V_12 = V_12 -> V_47 ;
} while ( V_49 != V_45 );
} while ( V_109 );
V_3 -> V_46 [ V_23 ] = V_49 ;
return NULL ;
}
static inline struct V_9 *
F_53 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_9 * V_10 ;
unsigned int V_48 ;
V_48 = V_3 -> V_48 & 0xFF ;
while ( V_48 ) {
int V_23 = F_38 ( ~ V_48 ) ;
V_48 &= ~ ( 1 << V_23 ) ;
V_10 = F_50 ( V_18 , V_23 ) ;
if ( V_10 )
return V_10 ;
}
return NULL ;
}
static struct V_9 *
F_54 ( struct V_17 * V_18 )
{
struct V_9 * V_10 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
T_2 V_51 ;
V_51 = F_15 () ;
if ( V_3 -> V_94 )
F_47 ( V_3 ) ;
V_3 -> V_51 = V_51 ;
for (; ; ) {
V_3 -> V_69 = 0 ;
V_10 = F_53 ( V_18 ) ;
if ( V_10 ) {
F_55 ( V_18 , V_10 ) ;
V_18 -> V_3 . V_58 -- ;
F_42 ( V_18 ) ;
return V_10 ;
}
if ( V_3 -> V_50 == V_70 &&
V_3 -> V_21 . V_52 == V_93 )
break;
V_3 -> V_50 = V_70 ;
V_3 -> V_21 . V_52 = V_93 ;
}
if ( V_18 -> V_3 . V_58 ) {
F_56 ( V_18 ) ;
if ( V_3 -> V_69 )
F_57 ( & V_3 -> V_87 ,
V_51 + V_3 -> V_69 ) ;
}
return NULL ;
}
static void F_58 ( struct V_1 * V_11 )
{
if ( V_11 == NULL )
return;
do {
int V_37 = 0 ;
struct V_1 * V_12 ;
V_12 = V_11 -> V_115 ;
if ( V_12 ) {
do {
if ( V_12 -> V_37 > V_37 )
V_37 = V_12 -> V_37 ;
} while ( ( V_12 = V_12 -> V_116 ) != V_11 -> V_115 );
}
V_11 -> V_37 = V_37 + 1 ;
} while ( ( V_11 = V_11 -> V_13 ) != NULL );
}
static void F_59 ( struct V_2 * V_3 , int V_23 )
{
struct V_1 * V_12 ;
unsigned int V_117 ;
if ( V_3 -> V_118 [ V_23 ] == 0 )
return;
for ( V_117 = 0 ; V_117 < V_3 -> V_7 . V_119 ; V_117 ++ ) {
F_60 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_12 -> V_24 == V_23 ) {
V_12 -> V_111 = ( V_12 -> V_120 * V_12 -> V_121 * V_3 -> V_122 [ V_23 ] ) /
V_3 -> V_118 [ V_23 ] ;
}
if ( V_12 -> V_111 <= 0 ||
V_12 -> V_111 > 32 * F_61 ( V_12 -> V_43 ) -> V_123 ) {
F_62 ( L_1 ,
V_12 -> V_8 . V_4 , V_12 -> V_111 ) ;
V_12 -> V_111 = F_61 ( V_12 -> V_43 ) -> V_123 / 2 + 1 ;
}
}
}
}
static void F_63 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
struct V_1 * V_124 = V_12 -> V_124 ;
unsigned int V_117 ;
int V_125 ;
if ( V_124 == NULL )
return;
for ( V_125 = 0 ; V_125 <= V_36 ; V_125 ++ ) {
if ( V_124 -> V_15 [ V_125 ] == V_12 && ! ( V_12 -> V_22 & ( 1 << V_125 ) ) )
V_124 -> V_15 [ V_125 ] = NULL ;
}
for ( V_125 = 0 ; V_125 <= V_36 ; V_125 ++ ) {
int V_37 = V_124 -> V_37 ;
if ( V_124 -> V_15 [ V_125 ] )
continue;
for ( V_117 = 0 ; V_117 < V_3 -> V_7 . V_119 ; V_117 ++ ) {
struct V_1 * V_126 ;
F_60 (c, &q->clhash.hash[h],
common.hnode) {
if ( V_126 -> V_124 == V_124 && V_126 -> V_37 < V_37 &&
V_126 -> V_22 & ( 1 << V_125 ) ) {
V_124 -> V_15 [ V_125 ] = V_126 ;
V_37 = V_126 -> V_37 ;
}
}
}
}
}
static void F_64 ( struct V_1 * V_12 , T_1 V_127 , T_1 V_128 , T_1 V_129 )
{
struct V_1 * V_124 = NULL ;
if ( V_127 == 0 ) {
V_124 = V_12 -> V_124 ;
if ( ! V_124 )
return;
V_127 = V_124 -> V_8 . V_4 ;
}
if ( V_124 == NULL || V_124 -> V_8 . V_4 != V_127 ) {
for ( V_124 = V_12 -> V_13 ; V_124 ; V_124 = V_124 -> V_13 )
if ( V_124 -> V_8 . V_4 == V_127 )
break;
}
if ( V_124 == NULL )
return;
if ( V_12 -> V_124 != V_124 ) {
V_12 -> V_22 = 0 ;
F_63 ( V_12 ) ;
V_12 -> V_124 = V_124 ;
V_12 -> V_22 = V_128 & V_129 ;
} else
V_12 -> V_22 = ( V_12 -> V_22 & ~ V_129 ) | ( V_128 & V_129 ) ;
F_63 ( V_12 ) ;
}
static void F_65 ( struct V_1 * V_11 )
{
struct V_1 * V_12 , * * V_130 ;
struct V_2 * V_3 = F_6 ( V_11 -> V_43 ) ;
F_66 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_11 -> V_13 ) {
V_130 = & V_11 -> V_116 ;
V_12 = * V_130 ;
do {
if ( V_12 == V_11 ) {
* V_130 = V_12 -> V_116 ;
break;
}
V_130 = & V_12 -> V_116 ;
} while ( ( V_12 = * V_130 ) != V_11 -> V_116 );
if ( V_11 -> V_13 -> V_115 == V_11 ) {
V_11 -> V_13 -> V_115 = V_11 -> V_116 ;
if ( V_11 -> V_116 == V_11 )
V_11 -> V_13 -> V_115 = NULL ;
}
} else {
F_67 ( V_11 -> V_116 != V_11 ) ;
}
}
static void F_68 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 -> V_43 ) ;
struct V_1 * V_131 = V_11 -> V_13 ;
V_11 -> V_116 = V_11 ;
F_69 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_131 == NULL )
return;
if ( V_131 -> V_115 == NULL ) {
V_131 -> V_115 = V_11 ;
} else {
V_11 -> V_116 = V_131 -> V_115 -> V_116 ;
V_131 -> V_115 -> V_116 = V_11 ;
}
}
static unsigned int F_70 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 , * V_132 ;
int V_23 ;
unsigned int V_95 ;
for ( V_23 = V_79 ; V_23 >= 0 ; V_23 -- ) {
V_132 = V_3 -> V_46 [ V_23 ] ;
if ( ! V_132 )
continue;
V_12 = V_132 ;
do {
if ( V_12 -> V_3 -> V_83 -> V_84 && ( V_95 = V_12 -> V_3 -> V_83 -> V_84 ( V_12 -> V_3 ) ) ) {
V_18 -> V_3 . V_58 -- ;
if ( ! V_12 -> V_3 -> V_3 . V_58 )
F_12 ( V_12 ) ;
return V_95 ;
}
} while ( ( V_12 = V_12 -> V_47 ) != V_132 );
}
return 0 ;
}
static void
F_71 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
int V_23 ;
unsigned int V_117 ;
V_3 -> V_48 = 0 ;
V_3 -> V_80 = 0 ;
V_3 -> V_94 = NULL ;
V_3 -> V_105 = NULL ;
F_72 ( & V_3 -> V_87 ) ;
F_73 ( & V_3 -> V_81 ) ;
V_3 -> V_50 = V_70 ;
V_3 -> V_51 = F_15 () ;
for ( V_23 = 0 ; V_23 <= V_79 ; V_23 ++ )
V_3 -> V_46 [ V_23 ] = NULL ;
for ( V_117 = 0 ; V_117 < V_3 -> V_7 . V_119 ; V_117 ++ ) {
F_60 (cl, &q->clhash.hash[h], common.hnode) {
F_74 ( V_12 -> V_3 ) ;
V_12 -> V_47 = NULL ;
V_12 -> V_52 = V_93 ;
V_12 -> V_64 = V_12 -> V_103 ;
V_12 -> V_109 = V_12 -> V_111 ;
V_12 -> V_44 = V_12 -> V_24 ;
}
}
V_18 -> V_3 . V_58 = 0 ;
}
static int F_75 ( struct V_1 * V_12 , struct V_133 * V_134 )
{
if ( V_134 -> V_135 & V_136 ) {
V_12 -> V_97 = ( V_134 -> V_137 & V_138 ) ? NULL : V_12 -> V_13 ;
V_12 -> V_53 = ( V_134 -> V_137 & V_139 ) ? NULL : V_12 -> V_13 ;
}
if ( V_134 -> V_135 & V_140 )
V_12 -> V_65 = V_134 -> V_65 ;
if ( V_134 -> V_135 & V_141 )
V_12 -> V_142 = V_134 -> V_142 ;
if ( V_134 -> V_135 & V_143 )
V_12 -> V_66 = - ( long ) V_134 -> V_66 ;
if ( V_134 -> V_135 & V_144 ) {
V_12 -> V_103 = V_134 -> V_103 ;
V_12 -> V_64 = V_134 -> V_103 ;
}
if ( V_134 -> V_135 & V_145 )
V_12 -> V_63 = V_134 -> V_63 ;
return 0 ;
}
static void F_76 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_122 [ V_12 -> V_24 ] -- ;
V_3 -> V_118 [ V_12 -> V_24 ] -= V_12 -> V_120 ;
F_59 ( V_3 , V_12 -> V_24 ) ;
}
static void F_77 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_122 [ V_12 -> V_24 ] ++ ;
V_3 -> V_118 [ V_12 -> V_24 ] += V_12 -> V_120 ;
F_59 ( V_3 , V_12 -> V_24 ) ;
}
static int F_78 ( struct V_1 * V_12 , struct V_146 * V_147 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
if ( V_147 -> V_121 )
V_12 -> V_121 = V_147 -> V_121 ;
if ( V_147 -> V_120 )
V_12 -> V_120 = V_147 -> V_120 ;
if ( V_147 -> V_24 ) {
V_12 -> V_24 = V_147 -> V_24 - 1 ;
V_12 -> V_44 = V_12 -> V_24 ;
if ( V_12 -> V_24 >= V_12 -> V_82 )
V_12 -> V_82 = V_79 - 1 ;
}
F_77 ( V_3 , V_12 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_12 , struct V_148 * V_149 )
{
switch ( V_149 -> V_150 ) {
case V_151 :
V_12 -> V_108 = F_21 ;
break;
case V_152 :
V_12 -> V_108 = F_23 ;
break;
case V_153 :
if ( V_149 -> V_82 - 1 >= V_79 ||
V_149 -> V_82 - 1 <= V_12 -> V_24 )
return - V_154 ;
V_12 -> V_82 = V_149 -> V_82 - 1 ;
V_12 -> V_108 = F_34 ;
break;
case V_155 :
V_12 -> V_108 = F_35 ;
break;
case V_156 :
V_12 -> V_108 = F_22 ;
break;
default:
return - V_154 ;
}
V_12 -> V_77 = V_149 -> V_77 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_12 , struct V_157 * V_158 )
{
V_12 -> V_159 = V_158 -> V_159 ;
if ( V_12 -> V_3 -> V_29 ) {
if ( V_158 -> V_159 == V_160 )
V_12 -> V_3 -> V_161 = F_45 ;
else
V_12 -> V_3 -> V_161 = NULL ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_12 , struct V_162 * V_163 )
{
F_64 ( V_12 , V_163 -> V_124 , V_163 -> V_22 , V_163 -> V_164 ) ;
return 0 ;
}
static int F_82 ( struct V_17 * V_18 , struct V_165 * V_166 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_165 * V_167 [ V_168 + 1 ] ;
struct V_169 * V_170 ;
int V_171 ;
V_171 = F_83 ( V_167 , V_168 , V_166 , V_172 ) ;
if ( V_171 < 0 )
return V_171 ;
if ( V_167 [ V_173 ] == NULL || V_167 [ V_174 ] == NULL )
return - V_154 ;
V_170 = F_84 ( V_167 [ V_174 ] ) ;
if ( ( V_3 -> V_21 . V_175 = F_85 ( V_170 , V_167 [ V_173 ] ) ) == NULL )
return - V_154 ;
V_171 = F_86 ( & V_3 -> V_7 ) ;
if ( V_171 < 0 )
goto V_176;
V_3 -> V_21 . V_177 = 1 ;
V_3 -> V_21 . V_116 = & V_3 -> V_21 ;
V_3 -> V_21 . V_8 . V_4 = V_18 -> V_29 ;
V_3 -> V_21 . V_43 = V_18 ;
V_3 -> V_21 . V_3 = F_87 ( V_18 -> V_178 , & V_179 ,
V_18 -> V_29 ) ;
if ( ! V_3 -> V_21 . V_3 )
V_3 -> V_21 . V_3 = & V_180 ;
V_3 -> V_21 . V_24 = V_79 - 1 ;
V_3 -> V_21 . V_82 = V_79 - 1 ;
V_3 -> V_21 . V_44 = V_79 - 1 ;
V_3 -> V_21 . V_181 = V_151 ;
V_3 -> V_21 . V_108 = F_21 ;
V_3 -> V_21 . V_121 = F_88 ( F_61 ( V_18 ) ) ;
V_3 -> V_21 . V_111 = V_3 -> V_21 . V_121 ;
V_3 -> V_21 . V_120 = V_3 -> V_21 . V_175 -> V_182 . V_182 ;
V_3 -> V_21 . V_65 = V_183 ;
V_3 -> V_21 . V_142 = V_3 -> V_21 . V_121 / 2 ;
V_3 -> V_21 . V_66 = - 0x7FFFFFFF ;
F_89 ( & V_3 -> V_87 , V_18 ) ;
F_90 ( & V_3 -> V_81 , V_184 , V_89 ) ;
V_3 -> V_81 . V_185 = F_37 ;
V_3 -> V_50 = V_70 ;
V_3 -> V_51 = F_15 () ;
F_68 ( & V_3 -> V_21 ) ;
if ( V_167 [ V_186 ] )
F_75 ( & V_3 -> V_21 , F_84 ( V_167 [ V_186 ] ) ) ;
F_77 ( V_3 , & V_3 -> V_21 ) ;
return 0 ;
V_176:
F_91 ( V_3 -> V_21 . V_175 ) ;
return V_171 ;
}
static int F_92 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_93 ( V_10 ) ;
if ( F_94 ( V_10 , V_174 , sizeof( V_12 -> V_175 -> V_182 ) , & V_12 -> V_175 -> V_182 ) )
goto V_187;
return V_10 -> V_95 ;
V_187:
F_95 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_96 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_93 ( V_10 ) ;
struct V_133 V_166 ;
V_166 . V_137 = 0 ;
if ( V_12 -> V_53 == NULL )
V_166 . V_137 |= V_139 ;
if ( V_12 -> V_97 == NULL )
V_166 . V_137 |= V_138 ;
V_166 . V_65 = V_12 -> V_65 ;
V_166 . V_37 = V_12 -> V_37 ;
V_166 . V_142 = V_12 -> V_142 ;
V_166 . V_103 = V_12 -> V_103 ;
V_166 . V_66 = ( T_1 ) ( - V_12 -> V_66 ) ;
V_166 . V_63 = V_12 -> V_63 ;
V_166 . V_135 = ~ 0 ;
if ( F_94 ( V_10 , V_186 , sizeof( V_166 ) , & V_166 ) )
goto V_187;
return V_10 -> V_95 ;
V_187:
F_95 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_97 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_93 ( V_10 ) ;
struct V_146 V_166 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_137 = 0 ;
V_166 . V_121 = V_12 -> V_121 ;
V_166 . V_24 = V_12 -> V_24 + 1 ;
V_166 . V_44 = V_12 -> V_44 + 1 ;
V_166 . V_120 = V_12 -> V_120 ;
if ( F_94 ( V_10 , V_188 , sizeof( V_166 ) , & V_166 ) )
goto V_187;
return V_10 -> V_95 ;
V_187:
F_95 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_98 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_93 ( V_10 ) ;
struct V_148 V_166 ;
V_166 . V_150 = V_12 -> V_181 ;
V_166 . V_82 = V_12 -> V_82 + 1 ;
V_166 . V_189 = 0 ;
V_166 . V_77 = V_12 -> V_77 ;
if ( F_94 ( V_10 , V_190 , sizeof( V_166 ) , & V_166 ) )
goto V_187;
return V_10 -> V_95 ;
V_187:
F_95 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_99 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_93 ( V_10 ) ;
struct V_162 V_166 ;
if ( V_12 -> V_124 || V_12 -> V_22 ) {
V_166 . V_124 = V_12 -> V_124 ? V_12 -> V_124 -> V_8 . V_4 : 0 ;
V_166 . V_22 = V_12 -> V_22 ;
V_166 . V_164 = ~ 0 ;
if ( F_94 ( V_10 , V_191 , sizeof( V_166 ) , & V_166 ) )
goto V_187;
}
return V_10 -> V_95 ;
V_187:
F_95 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_100 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_93 ( V_10 ) ;
struct V_157 V_166 ;
if ( V_12 -> V_159 ) {
V_166 . V_159 = V_12 -> V_159 ;
V_166 . V_192 = 0 ;
V_166 . V_193 = 0 ;
if ( F_94 ( V_10 , V_194 , sizeof( V_166 ) , & V_166 ) )
goto V_187;
}
return V_10 -> V_95 ;
V_187:
F_95 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_101 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
if ( F_96 ( V_10 , V_12 ) < 0 ||
F_92 ( V_10 , V_12 ) < 0 ||
F_97 ( V_10 , V_12 ) < 0 ||
F_98 ( V_10 , V_12 ) < 0 ||
#ifdef F_10
F_100 ( V_10 , V_12 ) < 0 ||
#endif
F_99 ( V_10 , V_12 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_102 ( struct V_17 * V_18 , struct V_9 * V_10 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_165 * V_195 ;
V_195 = F_103 ( V_10 , V_196 ) ;
if ( V_195 == NULL )
goto V_187;
if ( F_101 ( V_10 , & V_3 -> V_21 ) < 0 )
goto V_187;
return F_104 ( V_10 , V_195 ) ;
V_187:
F_105 ( V_10 , V_195 ) ;
return - 1 ;
}
static int
F_106 ( struct V_17 * V_18 , struct V_197 * V_198 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
V_3 -> V_21 . V_67 . V_64 = V_3 -> V_21 . V_64 ;
return F_107 ( V_198 , & V_3 -> V_21 . V_67 , sizeof( V_3 -> V_21 . V_67 ) ) ;
}
static int
F_108 ( struct V_17 * V_18 , unsigned long V_199 ,
struct V_9 * V_10 , struct V_200 * V_201 )
{
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
struct V_165 * V_195 ;
if ( V_12 -> V_13 )
V_201 -> V_202 = V_12 -> V_13 -> V_8 . V_4 ;
else
V_201 -> V_202 = V_203 ;
V_201 -> V_204 = V_12 -> V_8 . V_4 ;
V_201 -> V_205 = V_12 -> V_3 -> V_29 ;
V_195 = F_103 ( V_10 , V_196 ) ;
if ( V_195 == NULL )
goto V_187;
if ( F_101 ( V_10 , V_12 ) < 0 )
goto V_187;
return F_104 ( V_10 , V_195 ) ;
V_187:
F_105 ( V_10 , V_195 ) ;
return - 1 ;
}
static int
F_109 ( struct V_17 * V_18 , unsigned long V_199 ,
struct V_197 * V_198 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
V_12 -> V_67 . V_64 = V_12 -> V_64 ;
V_12 -> V_67 . V_52 = 0 ;
if ( V_12 -> V_52 != V_93 )
V_12 -> V_67 . V_52 = V_12 -> V_52 - V_3 -> V_51 ;
if ( F_110 ( V_198 , NULL , & V_12 -> V_99 ) < 0 ||
F_111 ( V_198 , & V_12 -> V_99 , & V_12 -> V_206 ) < 0 ||
F_112 ( V_198 , NULL , & V_12 -> V_59 , V_12 -> V_3 -> V_3 . V_58 ) < 0 )
return - 1 ;
return F_107 ( V_198 , & V_12 -> V_67 , sizeof( V_12 -> V_67 ) ) ;
}
static int F_113 ( struct V_17 * V_18 , unsigned long V_199 , struct V_17 * V_14 ,
struct V_17 * * V_207 )
{
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
if ( V_14 == NULL ) {
V_14 = F_87 ( V_18 -> V_178 ,
& V_179 , V_12 -> V_8 . V_4 ) ;
if ( V_14 == NULL )
return - V_208 ;
} else {
#ifdef F_10
if ( V_12 -> V_159 == V_160 )
V_14 -> V_161 = F_45 ;
#endif
}
F_114 ( V_18 ) ;
* V_207 = V_12 -> V_3 ;
V_12 -> V_3 = V_14 ;
F_115 ( * V_207 , ( * V_207 ) -> V_3 . V_58 ) ;
F_74 ( * V_207 ) ;
F_116 ( V_18 ) ;
return 0 ;
}
static struct V_17 * F_117 ( struct V_17 * V_18 , unsigned long V_199 )
{
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
return V_12 -> V_3 ;
}
static void F_118 ( struct V_17 * V_18 , unsigned long V_199 )
{
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
if ( V_12 -> V_3 -> V_3 . V_58 == 0 )
F_12 ( V_12 ) ;
}
static unsigned long F_119 ( struct V_17 * V_18 , T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = F_1 ( V_3 , V_4 ) ;
if ( V_12 ) {
V_12 -> V_177 ++ ;
return ( unsigned long ) V_12 ;
}
return 0 ;
}
static void F_120 ( struct V_17 * V_18 , struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
F_67 ( V_12 -> V_209 ) ;
F_121 ( & V_12 -> V_33 ) ;
F_122 ( V_12 -> V_3 ) ;
F_91 ( V_12 -> V_175 ) ;
F_123 ( & V_12 -> V_99 , & V_12 -> V_206 ) ;
if ( V_12 != & V_3 -> V_21 )
F_124 ( V_12 ) ;
}
static void F_125 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_210 * V_211 ;
struct V_1 * V_12 ;
unsigned int V_117 ;
#ifdef F_10
V_3 -> V_56 = NULL ;
#endif
for ( V_117 = 0 ; V_117 < V_3 -> V_7 . V_119 ; V_117 ++ ) {
F_60 (cl, &q->clhash.hash[h], common.hnode)
F_121 ( & V_12 -> V_33 ) ;
}
for ( V_117 = 0 ; V_117 < V_3 -> V_7 . V_119 ; V_117 ++ ) {
F_126 (cl, next, &q->clhash.hash[h],
common.hnode)
F_120 ( V_18 , V_12 ) ;
}
F_127 ( & V_3 -> V_7 ) ;
}
static void F_128 ( struct V_17 * V_18 , unsigned long V_199 )
{
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
if ( -- V_12 -> V_177 == 0 ) {
#ifdef F_10
T_5 * V_212 = F_129 ( V_18 ) ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
F_130 ( V_212 ) ;
if ( V_3 -> V_56 == V_12 )
V_3 -> V_56 = NULL ;
F_131 ( V_212 ) ;
#endif
F_120 ( V_18 , V_12 ) ;
}
}
static int
F_132 ( struct V_17 * V_18 , T_1 V_4 , T_1 V_213 , struct V_165 * * V_214 ,
unsigned long * V_199 )
{
int V_171 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) * V_199 ;
struct V_165 * V_166 = V_214 [ V_196 ] ;
struct V_165 * V_167 [ V_168 + 1 ] ;
struct V_1 * V_131 ;
struct V_215 * V_216 = NULL ;
if ( V_166 == NULL )
return - V_154 ;
V_171 = F_83 ( V_167 , V_168 , V_166 , V_172 ) ;
if ( V_171 < 0 )
return V_171 ;
if ( V_12 ) {
if ( V_213 ) {
if ( V_12 -> V_13 &&
V_12 -> V_13 -> V_8 . V_4 != V_213 )
return - V_154 ;
if ( ! V_12 -> V_13 && V_213 != V_203 )
return - V_154 ;
}
if ( V_167 [ V_174 ] ) {
V_216 = F_85 ( F_84 ( V_167 [ V_174 ] ) ,
V_167 [ V_173 ] ) ;
if ( V_216 == NULL )
return - V_154 ;
}
if ( V_214 [ V_217 ] ) {
V_171 = F_133 ( & V_12 -> V_99 , NULL ,
& V_12 -> V_206 ,
F_129 ( V_18 ) ,
V_214 [ V_217 ] ) ;
if ( V_171 ) {
F_91 ( V_216 ) ;
return V_171 ;
}
}
F_114 ( V_18 ) ;
if ( V_12 -> V_47 != NULL )
F_12 ( V_12 ) ;
if ( V_216 ) {
F_91 ( V_12 -> V_175 ) ;
V_12 -> V_175 = V_216 ;
}
if ( V_167 [ V_186 ] )
F_75 ( V_12 , F_84 ( V_167 [ V_186 ] ) ) ;
if ( V_167 [ V_188 ] ) {
F_76 ( V_3 , V_12 ) ;
F_78 ( V_12 , F_84 ( V_167 [ V_188 ] ) ) ;
}
if ( V_167 [ V_190 ] )
F_79 ( V_12 , F_84 ( V_167 [ V_190 ] ) ) ;
#ifdef F_10
if ( V_167 [ V_194 ] )
F_80 ( V_12 , F_84 ( V_167 [ V_194 ] ) ) ;
#endif
if ( V_167 [ V_191 ] )
F_81 ( V_12 , F_84 ( V_167 [ V_191 ] ) ) ;
if ( V_12 -> V_3 -> V_3 . V_58 )
F_11 ( V_12 ) ;
F_116 ( V_18 ) ;
return 0 ;
}
if ( V_213 == V_203 )
return - V_154 ;
if ( V_167 [ V_188 ] == NULL || V_167 [ V_174 ] == NULL ||
V_167 [ V_186 ] == NULL )
return - V_154 ;
V_216 = F_85 ( F_84 ( V_167 [ V_174 ] ) , V_167 [ V_173 ] ) ;
if ( V_216 == NULL )
return - V_154 ;
if ( V_4 ) {
V_171 = - V_154 ;
if ( F_7 ( V_4 ^ V_18 -> V_29 ) ||
F_1 ( V_3 , V_4 ) )
goto V_218;
} else {
int V_125 ;
V_4 = F_134 ( V_18 -> V_29 , 0x8000 ) ;
for ( V_125 = 0 ; V_125 < 0x8000 ; V_125 ++ ) {
if ( ++ V_3 -> V_219 >= 0x8000 )
V_3 -> V_219 = 1 ;
if ( F_1 ( V_3 , V_4 | V_3 -> V_219 ) == NULL )
break;
}
V_171 = - V_220 ;
if ( V_125 >= 0x8000 )
goto V_218;
V_4 = V_4 | V_3 -> V_219 ;
}
V_131 = & V_3 -> V_21 ;
if ( V_213 ) {
V_131 = F_1 ( V_3 , V_213 ) ;
V_171 = - V_154 ;
if ( V_131 == NULL )
goto V_218;
}
V_171 = - V_208 ;
V_12 = F_135 ( sizeof( * V_12 ) , V_221 ) ;
if ( V_12 == NULL )
goto V_218;
if ( V_214 [ V_217 ] ) {
V_171 = F_136 ( & V_12 -> V_99 , NULL , & V_12 -> V_206 ,
F_129 ( V_18 ) ,
V_214 [ V_217 ] ) ;
if ( V_171 ) {
F_124 ( V_12 ) ;
goto V_218;
}
}
V_12 -> V_175 = V_216 ;
V_216 = NULL ;
V_12 -> V_177 = 1 ;
V_12 -> V_3 = F_87 ( V_18 -> V_178 , & V_179 , V_4 ) ;
if ( ! V_12 -> V_3 )
V_12 -> V_3 = & V_180 ;
V_12 -> V_8 . V_4 = V_4 ;
V_12 -> V_13 = V_131 ;
V_12 -> V_43 = V_18 ;
V_12 -> V_121 = V_131 -> V_121 ;
V_12 -> V_111 = V_12 -> V_121 ;
V_12 -> V_120 = V_12 -> V_175 -> V_182 . V_182 ;
F_114 ( V_18 ) ;
F_68 ( V_12 ) ;
V_12 -> V_53 = V_12 -> V_13 ;
if ( V_12 -> V_13 != & V_3 -> V_21 )
V_12 -> V_97 = V_12 -> V_13 ;
F_58 ( V_131 ) ;
V_12 -> V_66 = - 0x7FFFFFFF ;
F_75 ( V_12 , F_84 ( V_167 [ V_186 ] ) ) ;
F_78 ( V_12 , F_84 ( V_167 [ V_188 ] ) ) ;
if ( V_12 -> V_65 == 0 )
V_12 -> V_65 = V_3 -> V_21 . V_65 ;
if ( V_12 -> V_103 == 0 )
V_12 -> V_103 = V_3 -> V_21 . V_103 ;
if ( V_12 -> V_142 == 0 )
V_12 -> V_142 = V_3 -> V_21 . V_142 ;
V_12 -> V_108 = F_21 ;
if ( V_167 [ V_190 ] )
F_79 ( V_12 , F_84 ( V_167 [ V_190 ] ) ) ;
#ifdef F_10
if ( V_167 [ V_194 ] )
F_80 ( V_12 , F_84 ( V_167 [ V_194 ] ) ) ;
#endif
if ( V_167 [ V_191 ] )
F_81 ( V_12 , F_84 ( V_167 [ V_191 ] ) ) ;
F_116 ( V_18 ) ;
F_137 ( V_18 , & V_3 -> V_7 ) ;
* V_199 = ( unsigned long ) V_12 ;
return 0 ;
V_218:
F_91 ( V_216 ) ;
return V_171 ;
}
static int F_138 ( struct V_17 * V_18 , unsigned long V_199 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
unsigned int V_58 ;
if ( V_12 -> V_209 || V_12 -> V_115 || V_12 == & V_3 -> V_21 )
return - V_222 ;
F_114 ( V_18 ) ;
V_58 = V_12 -> V_3 -> V_3 . V_58 ;
F_74 ( V_12 -> V_3 ) ;
F_115 ( V_12 -> V_3 , V_58 ) ;
if ( V_12 -> V_47 )
F_12 ( V_12 ) ;
if ( V_3 -> V_105 == V_12 )
V_3 -> V_105 = V_3 -> V_94 ;
if ( V_3 -> V_94 == V_12 ) {
V_3 -> V_94 = NULL ;
V_3 -> V_105 = NULL ;
}
#ifdef F_10
if ( V_3 -> V_56 == V_12 )
V_3 -> V_56 = NULL ;
#endif
F_65 ( V_12 ) ;
F_58 ( V_12 -> V_13 ) ;
V_12 -> V_22 = 0 ;
F_63 ( V_12 ) ;
F_76 ( V_3 , V_12 ) ;
F_116 ( V_18 ) ;
F_139 ( -- V_12 -> V_177 == 0 ) ;
return 0 ;
}
static struct V_25 T_6 * * F_140 ( struct V_17 * V_18 ,
unsigned long V_199 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
if ( V_12 == NULL )
V_12 = & V_3 -> V_21 ;
return & V_12 -> V_33 ;
}
static unsigned long F_141 ( struct V_17 * V_18 , unsigned long V_131 ,
T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_158 = (struct V_1 * ) V_131 ;
struct V_1 * V_12 = F_1 ( V_3 , V_4 ) ;
if ( V_12 ) {
if ( V_158 && V_158 -> V_37 <= V_12 -> V_37 )
return 0 ;
V_12 -> V_209 ++ ;
return ( unsigned long ) V_12 ;
}
return 0 ;
}
static void F_142 ( struct V_17 * V_18 , unsigned long V_199 )
{
struct V_1 * V_12 = (struct V_1 * ) V_199 ;
V_12 -> V_209 -- ;
}
static void F_143 ( struct V_17 * V_18 , struct V_223 * V_199 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
unsigned int V_117 ;
if ( V_199 -> V_224 )
return;
for ( V_117 = 0 ; V_117 < V_3 -> V_7 . V_119 ; V_117 ++ ) {
F_60 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_199 -> V_225 < V_199 -> V_226 ) {
V_199 -> V_225 ++ ;
continue;
}
if ( V_199 -> V_227 ( V_18 , ( unsigned long ) V_12 , V_199 ) < 0 ) {
V_199 -> V_224 = 1 ;
return;
}
V_199 -> V_225 ++ ;
}
}
}
static int T_7 F_144 ( void )
{
return F_145 ( & V_228 ) ;
}
static void T_8 F_146 ( void )
{
F_147 ( & V_228 ) ;
}
