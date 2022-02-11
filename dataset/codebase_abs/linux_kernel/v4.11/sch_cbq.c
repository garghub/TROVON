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
if ( V_50 > V_12 -> V_37 ) {
T_2 V_51 = F_14 () ;
do {
if ( V_12 -> V_52 < V_51 ) {
V_3 -> V_50 = V_12 -> V_37 ;
return;
}
} while ( ( V_12 = V_12 -> V_53 ) != NULL && V_50 > V_12 -> V_37 );
}
}
static int
F_15 ( struct V_9 * V_10 , struct V_17 * V_18 ,
struct V_9 * * V_54 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
int V_55 ( V_56 ) ;
struct V_1 * V_12 = F_5 ( V_10 , V_18 , & V_56 ) ;
#ifdef F_10
V_3 -> V_57 = V_12 ;
#endif
if ( V_12 == NULL ) {
if ( V_56 & V_31 )
F_16 ( V_18 ) ;
F_17 ( V_10 , V_54 ) ;
return V_56 ;
}
V_56 = F_18 ( V_10 , V_12 -> V_3 , V_54 ) ;
if ( V_56 == V_30 ) {
V_18 -> V_3 . V_58 ++ ;
F_13 ( V_3 , V_12 ) ;
if ( ! V_12 -> V_47 )
F_11 ( V_12 ) ;
return V_56 ;
}
if ( F_19 ( V_56 ) ) {
F_16 ( V_18 ) ;
F_13 ( V_3 , V_12 ) ;
V_12 -> V_59 . V_60 ++ ;
}
return V_56 ;
}
static void F_20 ( struct V_1 * V_12 )
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
static T_3 F_21 ( struct V_2 * V_3 , int V_23 ,
T_2 V_51 )
{
struct V_1 * V_12 ;
struct V_1 * V_49 = V_3 -> V_46 [ V_23 ] ;
T_2 V_73 = V_51 ;
if ( V_49 == NULL )
return 0 ;
do {
V_12 = V_49 -> V_47 ;
if ( V_51 - V_12 -> V_74 > 0 ) {
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
} else if ( V_73 - V_12 -> V_74 > 0 )
V_73 = V_12 -> V_74 ;
} while ( ( V_49 = V_12 ) != V_3 -> V_46 [ V_23 ] );
return V_73 - V_51 ;
}
static enum V_75 F_22 ( struct V_76 * V_77 )
{
struct V_2 * V_3 = F_3 ( V_77 , struct V_2 ,
V_78 ) ;
struct V_17 * V_18 = V_3 -> V_79 . V_43 ;
T_2 V_51 ;
T_3 V_61 = 0 ;
unsigned int V_80 ;
V_51 = F_14 () ;
V_80 = V_3 -> V_80 ;
V_3 -> V_80 = 0 ;
while ( V_80 ) {
int V_23 = F_23 ( ~ V_80 ) ;
T_3 V_81 ;
V_80 &= ~ ( 1 << V_23 ) ;
V_81 = F_21 ( V_3 , V_23 , V_51 ) ;
if ( V_81 > 0 ) {
V_3 -> V_80 |= 1 << V_23 ;
if ( V_81 < V_61 || V_61 == 0 )
V_61 = V_81 ;
}
}
if ( V_61 ) {
T_4 time ;
time = 0 ;
time = F_24 ( time , F_25 ( V_51 + V_61 ) ) ;
F_26 ( & V_3 -> V_78 , time , V_82 ) ;
}
F_27 ( F_28 ( V_18 ) ) ;
return V_83 ;
}
static inline void
F_29 ( struct V_2 * V_3 , struct V_1 * V_12 ,
struct V_1 * V_84 )
{
if ( V_12 && V_3 -> V_50 >= V_84 -> V_37 ) {
if ( V_12 -> V_3 -> V_3 . V_58 > 1 ) {
do {
if ( V_84 -> V_52 == V_85 ) {
V_3 -> V_50 = V_84 -> V_37 ;
return;
}
} while ( ( V_84 = V_84 -> V_53 ) != NULL );
}
#if 0
q->toplevel = TC_CBQ_MAXLEVEL;
#endif
}
}
static void
F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = V_3 -> V_86 ;
struct V_1 * V_12 = V_11 ;
int V_87 = V_3 -> V_88 ;
T_2 V_51 ;
V_3 -> V_86 = NULL ;
V_51 = V_3 -> V_51 + F_31 ( & V_3 -> V_21 , V_87 ) ;
for ( ; V_12 ; V_12 = V_12 -> V_89 ) {
long V_64 = V_12 -> V_64 ;
long V_90 ;
V_12 -> V_91 . V_92 ++ ;
V_12 -> V_91 . V_93 += V_87 ;
V_90 = V_51 - V_12 -> V_94 ;
if ( ( unsigned long ) V_90 > 128 * 1024 * 1024 ) {
V_64 = V_12 -> V_95 ;
} else {
V_90 -= F_31 ( V_12 , V_87 ) ;
V_64 += V_90 - ( V_64 >> V_12 -> V_65 ) ;
}
if ( V_64 <= 0 ) {
if ( V_64 < V_12 -> V_66 )
V_64 = V_12 -> V_66 ;
V_12 -> V_64 = V_64 ;
V_90 = ( - V_64 ) - ( ( - V_64 ) >> V_12 -> V_65 ) ;
V_90 -= F_31 ( & V_3 -> V_21 , V_87 ) ;
V_90 += F_31 ( V_12 , V_87 ) ;
V_12 -> V_52 = V_51 + V_90 ;
} else {
V_12 -> V_52 = V_85 ;
if ( V_64 > V_12 -> V_95 )
V_12 -> V_64 = V_12 -> V_95 ;
else
V_12 -> V_64 = V_64 ;
}
if ( ( V_96 ) ( V_51 - V_12 -> V_94 ) > 0 )
V_12 -> V_94 = V_51 ;
}
F_29 ( V_3 , V_11 , V_3 -> V_97 ) ;
}
static inline struct V_1 *
F_32 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
struct V_1 * V_98 = V_12 ;
if ( V_12 -> V_13 == NULL )
return V_12 ;
if ( V_12 -> V_52 == V_85 || V_3 -> V_51 >= V_12 -> V_52 ) {
V_12 -> V_62 = 0 ;
return V_12 ;
}
do {
V_12 = V_12 -> V_53 ;
if ( ! V_12 ) {
V_98 -> V_59 . V_99 ++ ;
F_20 ( V_98 ) ;
return NULL ;
}
if ( V_12 -> V_37 > V_3 -> V_50 )
return NULL ;
} while ( V_12 -> V_52 != V_85 && V_3 -> V_51 < V_12 -> V_52 );
V_12 -> V_62 = 0 ;
return V_12 ;
}
static inline struct V_9 *
F_33 ( struct V_17 * V_18 , int V_23 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_45 , * V_49 , * V_12 ;
struct V_9 * V_10 ;
int V_100 ;
V_45 = V_49 = V_3 -> V_46 [ V_23 ] ;
V_12 = V_49 -> V_47 ;
do {
V_100 = 0 ;
do {
struct V_1 * V_53 = V_12 ;
if ( V_12 -> V_3 -> V_3 . V_58 &&
( V_53 = F_32 ( V_12 ) ) == NULL )
goto V_101;
if ( V_12 -> V_100 <= 0 ) {
V_100 = 1 ;
V_12 -> V_100 += V_12 -> V_102 ;
goto V_103;
}
V_10 = V_12 -> V_3 -> V_104 ( V_12 -> V_3 ) ;
if ( V_10 == NULL )
goto V_101;
V_12 -> V_100 -= F_34 ( V_10 ) ;
V_3 -> V_86 = V_12 ;
V_3 -> V_97 = V_53 ;
if ( V_53 != V_12 ) {
#ifndef F_35
V_53 -> V_67 . V_105 ++ ;
V_12 -> V_67 . V_105 ++ ;
#else
V_53 -> V_67 . V_105 += F_34 ( V_10 ) ;
V_12 -> V_67 . V_105 += F_34 ( V_10 ) ;
#endif
}
V_3 -> V_88 = F_34 ( V_10 ) ;
if ( V_12 -> V_100 <= 0 ) {
V_3 -> V_46 [ V_23 ] = V_12 ;
V_12 = V_12 -> V_47 ;
V_12 -> V_100 += V_12 -> V_102 ;
}
return V_10 ;
V_101:
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
V_103:
V_49 = V_12 ;
V_12 = V_12 -> V_47 ;
} while ( V_49 != V_45 );
} while ( V_100 );
V_3 -> V_46 [ V_23 ] = V_49 ;
return NULL ;
}
static inline struct V_9 *
F_36 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_9 * V_10 ;
unsigned int V_48 ;
V_48 = V_3 -> V_48 & 0xFF ;
while ( V_48 ) {
int V_23 = F_23 ( ~ V_48 ) ;
V_48 &= ~ ( 1 << V_23 ) ;
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
T_2 V_51 ;
V_51 = F_14 () ;
if ( V_3 -> V_86 )
F_30 ( V_3 ) ;
V_3 -> V_51 = V_51 ;
for (; ; ) {
V_3 -> V_69 = 0 ;
V_10 = F_36 ( V_18 ) ;
if ( V_10 ) {
F_38 ( V_18 , V_10 ) ;
V_18 -> V_3 . V_58 -- ;
return V_10 ;
}
if ( V_3 -> V_50 == V_70 &&
V_3 -> V_21 . V_52 == V_85 )
break;
V_3 -> V_50 = V_70 ;
V_3 -> V_21 . V_52 = V_85 ;
}
if ( V_18 -> V_3 . V_58 ) {
F_39 ( V_18 ) ;
if ( V_3 -> V_69 )
F_40 ( & V_3 -> V_79 ,
V_51 + V_3 -> V_69 ) ;
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
V_12 = V_11 -> V_106 ;
if ( V_12 ) {
do {
if ( V_12 -> V_37 > V_37 )
V_37 = V_12 -> V_37 ;
} while ( ( V_12 = V_12 -> V_107 ) != V_11 -> V_106 );
}
V_11 -> V_37 = V_37 + 1 ;
} while ( ( V_11 = V_11 -> V_13 ) != NULL );
}
static void F_42 ( struct V_2 * V_3 , int V_23 )
{
struct V_1 * V_12 ;
unsigned int V_108 ;
if ( V_3 -> V_109 [ V_23 ] == 0 )
return;
for ( V_108 = 0 ; V_108 < V_3 -> V_7 . V_110 ; V_108 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_12 -> V_24 == V_23 ) {
V_12 -> V_102 = ( V_12 -> V_111 * V_12 -> V_112 * V_3 -> V_113 [ V_23 ] ) /
V_3 -> V_109 [ V_23 ] ;
}
if ( V_12 -> V_102 <= 0 ||
V_12 -> V_102 > 32 * F_44 ( V_12 -> V_43 ) -> V_114 ) {
F_45 ( L_1 ,
V_12 -> V_8 . V_4 , V_12 -> V_102 ) ;
V_12 -> V_102 = F_44 ( V_12 -> V_43 ) -> V_114 / 2 + 1 ;
}
}
}
}
static void F_46 ( struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
struct V_1 * V_115 = V_12 -> V_115 ;
unsigned int V_108 ;
int V_116 ;
if ( V_115 == NULL )
return;
for ( V_116 = 0 ; V_116 <= V_36 ; V_116 ++ ) {
if ( V_115 -> V_15 [ V_116 ] == V_12 && ! ( V_12 -> V_22 & ( 1 << V_116 ) ) )
V_115 -> V_15 [ V_116 ] = NULL ;
}
for ( V_116 = 0 ; V_116 <= V_36 ; V_116 ++ ) {
int V_37 = V_115 -> V_37 ;
if ( V_115 -> V_15 [ V_116 ] )
continue;
for ( V_108 = 0 ; V_108 < V_3 -> V_7 . V_110 ; V_108 ++ ) {
struct V_1 * V_117 ;
F_43 (c, &q->clhash.hash[h],
common.hnode) {
if ( V_117 -> V_115 == V_115 && V_117 -> V_37 < V_37 &&
V_117 -> V_22 & ( 1 << V_116 ) ) {
V_115 -> V_15 [ V_116 ] = V_117 ;
V_37 = V_117 -> V_37 ;
}
}
}
}
}
static void F_47 ( struct V_1 * V_12 , T_1 V_118 , T_1 V_119 , T_1 V_120 )
{
struct V_1 * V_115 = NULL ;
if ( V_118 == 0 ) {
V_115 = V_12 -> V_115 ;
if ( ! V_115 )
return;
V_118 = V_115 -> V_8 . V_4 ;
}
if ( V_115 == NULL || V_115 -> V_8 . V_4 != V_118 ) {
for ( V_115 = V_12 -> V_13 ; V_115 ; V_115 = V_115 -> V_13 )
if ( V_115 -> V_8 . V_4 == V_118 )
break;
}
if ( V_115 == NULL )
return;
if ( V_12 -> V_115 != V_115 ) {
V_12 -> V_22 = 0 ;
F_46 ( V_12 ) ;
V_12 -> V_115 = V_115 ;
V_12 -> V_22 = V_119 & V_120 ;
} else
V_12 -> V_22 = ( V_12 -> V_22 & ~ V_120 ) | ( V_119 & V_120 ) ;
F_46 ( V_12 ) ;
}
static void F_48 ( struct V_1 * V_11 )
{
struct V_1 * V_12 , * * V_121 ;
struct V_2 * V_3 = F_6 ( V_11 -> V_43 ) ;
F_49 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_11 -> V_13 ) {
V_121 = & V_11 -> V_107 ;
V_12 = * V_121 ;
do {
if ( V_12 == V_11 ) {
* V_121 = V_12 -> V_107 ;
break;
}
V_121 = & V_12 -> V_107 ;
} while ( ( V_12 = * V_121 ) != V_11 -> V_107 );
if ( V_11 -> V_13 -> V_106 == V_11 ) {
V_11 -> V_13 -> V_106 = V_11 -> V_107 ;
if ( V_11 -> V_107 == V_11 )
V_11 -> V_13 -> V_106 = NULL ;
}
} else {
F_50 ( V_11 -> V_107 != V_11 ) ;
}
}
static void F_51 ( struct V_1 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 -> V_43 ) ;
struct V_1 * V_122 = V_11 -> V_13 ;
V_11 -> V_107 = V_11 ;
F_52 ( & V_3 -> V_7 , & V_11 -> V_8 ) ;
if ( V_122 == NULL )
return;
if ( V_122 -> V_106 == NULL ) {
V_122 -> V_106 = V_11 ;
} else {
V_11 -> V_107 = V_122 -> V_106 -> V_107 ;
V_122 -> V_106 -> V_107 = V_11 ;
}
}
static void
F_53 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
int V_23 ;
unsigned int V_108 ;
V_3 -> V_48 = 0 ;
V_3 -> V_80 = 0 ;
V_3 -> V_86 = NULL ;
V_3 -> V_97 = NULL ;
F_54 ( & V_3 -> V_79 ) ;
F_55 ( & V_3 -> V_78 ) ;
V_3 -> V_50 = V_70 ;
V_3 -> V_51 = F_14 () ;
for ( V_23 = 0 ; V_23 <= V_123 ; V_23 ++ )
V_3 -> V_46 [ V_23 ] = NULL ;
for ( V_108 = 0 ; V_108 < V_3 -> V_7 . V_110 ; V_108 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode) {
F_56 ( V_12 -> V_3 ) ;
V_12 -> V_47 = NULL ;
V_12 -> V_52 = V_85 ;
V_12 -> V_64 = V_12 -> V_95 ;
V_12 -> V_100 = V_12 -> V_102 ;
V_12 -> V_44 = V_12 -> V_24 ;
}
}
V_18 -> V_3 . V_58 = 0 ;
}
static int F_57 ( struct V_1 * V_12 , struct V_124 * V_125 )
{
if ( V_125 -> V_126 & V_127 ) {
V_12 -> V_89 = ( V_125 -> V_128 & V_129 ) ? NULL : V_12 -> V_13 ;
V_12 -> V_53 = ( V_125 -> V_128 & V_130 ) ? NULL : V_12 -> V_13 ;
}
if ( V_125 -> V_126 & V_131 )
V_12 -> V_65 = V_125 -> V_65 ;
if ( V_125 -> V_126 & V_132 )
V_12 -> V_133 = V_125 -> V_133 ;
if ( V_125 -> V_126 & V_134 )
V_12 -> V_66 = - ( long ) V_125 -> V_66 ;
if ( V_125 -> V_126 & V_135 ) {
V_12 -> V_95 = V_125 -> V_95 ;
V_12 -> V_64 = V_125 -> V_95 ;
}
if ( V_125 -> V_126 & V_136 )
V_12 -> V_63 = V_125 -> V_63 ;
return 0 ;
}
static void F_58 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_113 [ V_12 -> V_24 ] -- ;
V_3 -> V_109 [ V_12 -> V_24 ] -= V_12 -> V_111 ;
F_42 ( V_3 , V_12 -> V_24 ) ;
}
static void F_59 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
V_3 -> V_113 [ V_12 -> V_24 ] ++ ;
V_3 -> V_109 [ V_12 -> V_24 ] += V_12 -> V_111 ;
F_42 ( V_3 , V_12 -> V_24 ) ;
}
static int F_60 ( struct V_1 * V_12 , struct V_137 * V_138 )
{
struct V_2 * V_3 = F_6 ( V_12 -> V_43 ) ;
if ( V_138 -> V_112 )
V_12 -> V_112 = V_138 -> V_112 ;
if ( V_138 -> V_111 )
V_12 -> V_111 = V_138 -> V_111 ;
if ( V_138 -> V_24 ) {
V_12 -> V_24 = V_138 -> V_24 - 1 ;
V_12 -> V_44 = V_12 -> V_24 ;
if ( V_12 -> V_24 >= V_12 -> V_139 )
V_12 -> V_139 = V_123 - 1 ;
}
F_59 ( V_3 , V_12 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_12 , struct V_140 * V_141 )
{
F_47 ( V_12 , V_141 -> V_115 , V_141 -> V_22 , V_141 -> V_142 ) ;
return 0 ;
}
static int F_62 ( struct V_17 * V_18 , struct V_143 * V_144 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_143 * V_145 [ V_146 + 1 ] ;
struct V_147 * V_148 ;
int V_149 ;
V_149 = F_63 ( V_145 , V_146 , V_144 , V_150 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_145 [ V_151 ] == NULL || V_145 [ V_152 ] == NULL )
return - V_153 ;
V_148 = F_64 ( V_145 [ V_152 ] ) ;
if ( ( V_3 -> V_21 . V_154 = F_65 ( V_148 , V_145 [ V_151 ] ) ) == NULL )
return - V_153 ;
V_149 = F_66 ( & V_3 -> V_7 ) ;
if ( V_149 < 0 )
goto V_155;
V_3 -> V_21 . V_156 = 1 ;
V_3 -> V_21 . V_107 = & V_3 -> V_21 ;
V_3 -> V_21 . V_8 . V_4 = V_18 -> V_29 ;
V_3 -> V_21 . V_43 = V_18 ;
V_3 -> V_21 . V_3 = F_67 ( V_18 -> V_157 , & V_158 ,
V_18 -> V_29 ) ;
if ( ! V_3 -> V_21 . V_3 )
V_3 -> V_21 . V_3 = & V_159 ;
V_3 -> V_21 . V_24 = V_123 - 1 ;
V_3 -> V_21 . V_139 = V_123 - 1 ;
V_3 -> V_21 . V_44 = V_123 - 1 ;
V_3 -> V_21 . V_112 = F_68 ( F_44 ( V_18 ) ) ;
V_3 -> V_21 . V_102 = V_3 -> V_21 . V_112 ;
V_3 -> V_21 . V_111 = V_3 -> V_21 . V_154 -> V_160 . V_160 ;
V_3 -> V_21 . V_65 = V_161 ;
V_3 -> V_21 . V_133 = V_3 -> V_21 . V_112 / 2 ;
V_3 -> V_21 . V_66 = - 0x7FFFFFFF ;
F_69 ( & V_3 -> V_79 , V_18 ) ;
F_70 ( & V_3 -> V_78 , V_162 , V_82 ) ;
V_3 -> V_78 . V_163 = F_22 ;
V_3 -> V_50 = V_70 ;
V_3 -> V_51 = F_14 () ;
F_51 ( & V_3 -> V_21 ) ;
if ( V_145 [ V_164 ] )
F_57 ( & V_3 -> V_21 , F_64 ( V_145 [ V_164 ] ) ) ;
F_59 ( V_3 , & V_3 -> V_21 ) ;
return 0 ;
V_155:
F_71 ( V_3 -> V_21 . V_154 ) ;
return V_149 ;
}
static int F_72 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_73 ( V_10 ) ;
if ( F_74 ( V_10 , V_152 , sizeof( V_12 -> V_154 -> V_160 ) , & V_12 -> V_154 -> V_160 ) )
goto V_165;
return V_10 -> V_87 ;
V_165:
F_75 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_76 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_73 ( V_10 ) ;
struct V_124 V_144 ;
V_144 . V_128 = 0 ;
if ( V_12 -> V_53 == NULL )
V_144 . V_128 |= V_130 ;
if ( V_12 -> V_89 == NULL )
V_144 . V_128 |= V_129 ;
V_144 . V_65 = V_12 -> V_65 ;
V_144 . V_37 = V_12 -> V_37 ;
V_144 . V_133 = V_12 -> V_133 ;
V_144 . V_95 = V_12 -> V_95 ;
V_144 . V_66 = ( T_1 ) ( - V_12 -> V_66 ) ;
V_144 . V_63 = V_12 -> V_63 ;
V_144 . V_126 = ~ 0 ;
if ( F_74 ( V_10 , V_164 , sizeof( V_144 ) , & V_144 ) )
goto V_165;
return V_10 -> V_87 ;
V_165:
F_75 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_77 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_73 ( V_10 ) ;
struct V_137 V_144 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_128 = 0 ;
V_144 . V_112 = V_12 -> V_112 ;
V_144 . V_24 = V_12 -> V_24 + 1 ;
V_144 . V_44 = V_12 -> V_44 + 1 ;
V_144 . V_111 = V_12 -> V_111 ;
if ( F_74 ( V_10 , V_166 , sizeof( V_144 ) , & V_144 ) )
goto V_165;
return V_10 -> V_87 ;
V_165:
F_75 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_78 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
unsigned char * V_71 = F_73 ( V_10 ) ;
struct V_140 V_144 ;
if ( V_12 -> V_115 || V_12 -> V_22 ) {
V_144 . V_115 = V_12 -> V_115 ? V_12 -> V_115 -> V_8 . V_4 : 0 ;
V_144 . V_22 = V_12 -> V_22 ;
V_144 . V_142 = ~ 0 ;
if ( F_74 ( V_10 , V_167 , sizeof( V_144 ) , & V_144 ) )
goto V_165;
}
return V_10 -> V_87 ;
V_165:
F_75 ( V_10 , V_71 ) ;
return - 1 ;
}
static int F_79 ( struct V_9 * V_10 , struct V_1 * V_12 )
{
if ( F_76 ( V_10 , V_12 ) < 0 ||
F_72 ( V_10 , V_12 ) < 0 ||
F_77 ( V_10 , V_12 ) < 0 ||
F_78 ( V_10 , V_12 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_80 ( struct V_17 * V_18 , struct V_9 * V_10 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_143 * V_168 ;
V_168 = F_81 ( V_10 , V_169 ) ;
if ( V_168 == NULL )
goto V_165;
if ( F_79 ( V_10 , & V_3 -> V_21 ) < 0 )
goto V_165;
return F_82 ( V_10 , V_168 ) ;
V_165:
F_83 ( V_10 , V_168 ) ;
return - 1 ;
}
static int
F_84 ( struct V_17 * V_18 , struct V_170 * V_171 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
V_3 -> V_21 . V_67 . V_64 = V_3 -> V_21 . V_64 ;
return F_85 ( V_171 , & V_3 -> V_21 . V_67 , sizeof( V_3 -> V_21 . V_67 ) ) ;
}
static int
F_86 ( struct V_17 * V_18 , unsigned long V_172 ,
struct V_9 * V_10 , struct V_173 * V_174 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
struct V_143 * V_168 ;
if ( V_12 -> V_13 )
V_174 -> V_175 = V_12 -> V_13 -> V_8 . V_4 ;
else
V_174 -> V_175 = V_176 ;
V_174 -> V_177 = V_12 -> V_8 . V_4 ;
V_174 -> V_178 = V_12 -> V_3 -> V_29 ;
V_168 = F_81 ( V_10 , V_169 ) ;
if ( V_168 == NULL )
goto V_165;
if ( F_79 ( V_10 , V_12 ) < 0 )
goto V_165;
return F_82 ( V_10 , V_168 ) ;
V_165:
F_83 ( V_10 , V_168 ) ;
return - 1 ;
}
static int
F_87 ( struct V_17 * V_18 , unsigned long V_172 ,
struct V_170 * V_171 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
V_12 -> V_67 . V_64 = V_12 -> V_64 ;
V_12 -> V_67 . V_52 = 0 ;
if ( V_12 -> V_52 != V_85 )
V_12 -> V_67 . V_52 = V_12 -> V_52 - V_3 -> V_51 ;
if ( F_88 ( F_89 ( V_18 ) ,
V_171 , NULL , & V_12 -> V_91 ) < 0 ||
F_90 ( V_171 , & V_12 -> V_179 ) < 0 ||
F_91 ( V_171 , NULL , & V_12 -> V_59 , V_12 -> V_3 -> V_3 . V_58 ) < 0 )
return - 1 ;
return F_85 ( V_171 , & V_12 -> V_67 , sizeof( V_12 -> V_67 ) ) ;
}
static int F_92 ( struct V_17 * V_18 , unsigned long V_172 , struct V_17 * V_14 ,
struct V_17 * * V_180 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
if ( V_14 == NULL ) {
V_14 = F_67 ( V_18 -> V_157 ,
& V_158 , V_12 -> V_8 . V_4 ) ;
if ( V_14 == NULL )
return - V_181 ;
}
* V_180 = F_93 ( V_18 , V_14 , & V_12 -> V_3 ) ;
return 0 ;
}
static struct V_17 * F_94 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
return V_12 -> V_3 ;
}
static void F_95 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
if ( V_12 -> V_3 -> V_3 . V_58 == 0 )
F_12 ( V_12 ) ;
}
static unsigned long F_96 ( struct V_17 * V_18 , T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = F_1 ( V_3 , V_4 ) ;
if ( V_12 ) {
V_12 -> V_156 ++ ;
return ( unsigned long ) V_12 ;
}
return 0 ;
}
static void F_97 ( struct V_17 * V_18 , struct V_1 * V_12 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
F_50 ( V_12 -> V_182 ) ;
F_98 ( & V_12 -> V_33 ) ;
F_99 ( V_12 -> V_3 ) ;
F_71 ( V_12 -> V_154 ) ;
F_100 ( & V_12 -> V_179 ) ;
if ( V_12 != & V_3 -> V_21 )
F_101 ( V_12 ) ;
}
static void F_102 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_183 * V_184 ;
struct V_1 * V_12 ;
unsigned int V_108 ;
#ifdef F_10
V_3 -> V_57 = NULL ;
#endif
for ( V_108 = 0 ; V_108 < V_3 -> V_7 . V_110 ; V_108 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode)
F_98 ( & V_12 -> V_33 ) ;
}
for ( V_108 = 0 ; V_108 < V_3 -> V_7 . V_110 ; V_108 ++ ) {
F_103 (cl, next, &q->clhash.hash[h],
common.hnode)
F_97 ( V_18 , V_12 ) ;
}
F_104 ( & V_3 -> V_7 ) ;
}
static void F_105 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
if ( -- V_12 -> V_156 == 0 ) {
#ifdef F_10
T_5 * V_185 = F_106 ( V_18 ) ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
F_107 ( V_185 ) ;
if ( V_3 -> V_57 == V_12 )
V_3 -> V_57 = NULL ;
F_108 ( V_185 ) ;
#endif
F_97 ( V_18 , V_12 ) ;
}
}
static int
F_109 ( struct V_17 * V_18 , T_1 V_4 , T_1 V_186 , struct V_143 * * V_187 ,
unsigned long * V_172 )
{
int V_149 ;
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) * V_172 ;
struct V_143 * V_144 = V_187 [ V_169 ] ;
struct V_143 * V_145 [ V_146 + 1 ] ;
struct V_1 * V_122 ;
struct V_188 * V_189 = NULL ;
if ( V_144 == NULL )
return - V_153 ;
V_149 = F_63 ( V_145 , V_146 , V_144 , V_150 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_145 [ V_190 ] || V_145 [ V_191 ] )
return - V_192 ;
if ( V_12 ) {
if ( V_186 ) {
if ( V_12 -> V_13 &&
V_12 -> V_13 -> V_8 . V_4 != V_186 )
return - V_153 ;
if ( ! V_12 -> V_13 && V_186 != V_176 )
return - V_153 ;
}
if ( V_145 [ V_152 ] ) {
V_189 = F_65 ( F_64 ( V_145 [ V_152 ] ) ,
V_145 [ V_151 ] ) ;
if ( V_189 == NULL )
return - V_153 ;
}
if ( V_187 [ V_193 ] ) {
V_149 = F_110 ( & V_12 -> V_91 , NULL ,
& V_12 -> V_179 ,
NULL ,
F_89 ( V_18 ) ,
V_187 [ V_193 ] ) ;
if ( V_149 ) {
F_71 ( V_189 ) ;
return V_149 ;
}
}
F_111 ( V_18 ) ;
if ( V_12 -> V_47 != NULL )
F_12 ( V_12 ) ;
if ( V_189 ) {
F_71 ( V_12 -> V_154 ) ;
V_12 -> V_154 = V_189 ;
}
if ( V_145 [ V_164 ] )
F_57 ( V_12 , F_64 ( V_145 [ V_164 ] ) ) ;
if ( V_145 [ V_166 ] ) {
F_58 ( V_3 , V_12 ) ;
F_60 ( V_12 , F_64 ( V_145 [ V_166 ] ) ) ;
}
if ( V_145 [ V_167 ] )
F_61 ( V_12 , F_64 ( V_145 [ V_167 ] ) ) ;
if ( V_12 -> V_3 -> V_3 . V_58 )
F_11 ( V_12 ) ;
F_112 ( V_18 ) ;
return 0 ;
}
if ( V_186 == V_176 )
return - V_153 ;
if ( V_145 [ V_166 ] == NULL || V_145 [ V_152 ] == NULL ||
V_145 [ V_164 ] == NULL )
return - V_153 ;
V_189 = F_65 ( F_64 ( V_145 [ V_152 ] ) , V_145 [ V_151 ] ) ;
if ( V_189 == NULL )
return - V_153 ;
if ( V_4 ) {
V_149 = - V_153 ;
if ( F_7 ( V_4 ^ V_18 -> V_29 ) ||
F_1 ( V_3 , V_4 ) )
goto V_194;
} else {
int V_116 ;
V_4 = F_113 ( V_18 -> V_29 , 0x8000 ) ;
for ( V_116 = 0 ; V_116 < 0x8000 ; V_116 ++ ) {
if ( ++ V_3 -> V_195 >= 0x8000 )
V_3 -> V_195 = 1 ;
if ( F_1 ( V_3 , V_4 | V_3 -> V_195 ) == NULL )
break;
}
V_149 = - V_196 ;
if ( V_116 >= 0x8000 )
goto V_194;
V_4 = V_4 | V_3 -> V_195 ;
}
V_122 = & V_3 -> V_21 ;
if ( V_186 ) {
V_122 = F_1 ( V_3 , V_186 ) ;
V_149 = - V_153 ;
if ( V_122 == NULL )
goto V_194;
}
V_149 = - V_181 ;
V_12 = F_114 ( sizeof( * V_12 ) , V_197 ) ;
if ( V_12 == NULL )
goto V_194;
if ( V_187 [ V_193 ] ) {
V_149 = F_115 ( & V_12 -> V_91 , NULL , & V_12 -> V_179 ,
NULL ,
F_89 ( V_18 ) ,
V_187 [ V_193 ] ) ;
if ( V_149 ) {
F_101 ( V_12 ) ;
goto V_194;
}
}
V_12 -> V_154 = V_189 ;
V_189 = NULL ;
V_12 -> V_156 = 1 ;
V_12 -> V_3 = F_67 ( V_18 -> V_157 , & V_158 , V_4 ) ;
if ( ! V_12 -> V_3 )
V_12 -> V_3 = & V_159 ;
V_12 -> V_8 . V_4 = V_4 ;
V_12 -> V_13 = V_122 ;
V_12 -> V_43 = V_18 ;
V_12 -> V_112 = V_122 -> V_112 ;
V_12 -> V_102 = V_12 -> V_112 ;
V_12 -> V_111 = V_12 -> V_154 -> V_160 . V_160 ;
F_111 ( V_18 ) ;
F_51 ( V_12 ) ;
V_12 -> V_53 = V_12 -> V_13 ;
if ( V_12 -> V_13 != & V_3 -> V_21 )
V_12 -> V_89 = V_12 -> V_13 ;
F_41 ( V_122 ) ;
V_12 -> V_66 = - 0x7FFFFFFF ;
F_57 ( V_12 , F_64 ( V_145 [ V_164 ] ) ) ;
F_60 ( V_12 , F_64 ( V_145 [ V_166 ] ) ) ;
if ( V_12 -> V_65 == 0 )
V_12 -> V_65 = V_3 -> V_21 . V_65 ;
if ( V_12 -> V_95 == 0 )
V_12 -> V_95 = V_3 -> V_21 . V_95 ;
if ( V_12 -> V_133 == 0 )
V_12 -> V_133 = V_3 -> V_21 . V_133 ;
if ( V_145 [ V_167 ] )
F_61 ( V_12 , F_64 ( V_145 [ V_167 ] ) ) ;
F_112 ( V_18 ) ;
F_116 ( V_18 , & V_3 -> V_7 ) ;
* V_172 = ( unsigned long ) V_12 ;
return 0 ;
V_194:
F_71 ( V_189 ) ;
return V_149 ;
}
static int F_117 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
unsigned int V_58 , V_198 ;
if ( V_12 -> V_182 || V_12 -> V_106 || V_12 == & V_3 -> V_21 )
return - V_199 ;
F_111 ( V_18 ) ;
V_58 = V_12 -> V_3 -> V_3 . V_58 ;
V_198 = V_12 -> V_3 -> V_59 . V_198 ;
F_56 ( V_12 -> V_3 ) ;
F_118 ( V_12 -> V_3 , V_58 , V_198 ) ;
if ( V_12 -> V_47 )
F_12 ( V_12 ) ;
if ( V_3 -> V_97 == V_12 )
V_3 -> V_97 = V_3 -> V_86 ;
if ( V_3 -> V_86 == V_12 ) {
V_3 -> V_86 = NULL ;
V_3 -> V_97 = NULL ;
}
#ifdef F_10
if ( V_3 -> V_57 == V_12 )
V_3 -> V_57 = NULL ;
#endif
F_48 ( V_12 ) ;
F_41 ( V_12 -> V_13 ) ;
V_12 -> V_22 = 0 ;
F_46 ( V_12 ) ;
F_58 ( V_3 , V_12 ) ;
F_112 ( V_18 ) ;
F_119 ( -- V_12 -> V_156 == 0 ) ;
return 0 ;
}
static struct V_25 T_6 * * F_120 ( struct V_17 * V_18 ,
unsigned long V_172 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
if ( V_12 == NULL )
V_12 = & V_3 -> V_21 ;
return & V_12 -> V_33 ;
}
static unsigned long F_121 ( struct V_17 * V_18 , unsigned long V_122 ,
T_1 V_4 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_200 = (struct V_1 * ) V_122 ;
struct V_1 * V_12 = F_1 ( V_3 , V_4 ) ;
if ( V_12 ) {
if ( V_200 && V_200 -> V_37 <= V_12 -> V_37 )
return 0 ;
V_12 -> V_182 ++ ;
return ( unsigned long ) V_12 ;
}
return 0 ;
}
static void F_122 ( struct V_17 * V_18 , unsigned long V_172 )
{
struct V_1 * V_12 = (struct V_1 * ) V_172 ;
V_12 -> V_182 -- ;
}
static void F_123 ( struct V_17 * V_18 , struct V_201 * V_172 )
{
struct V_2 * V_3 = F_6 ( V_18 ) ;
struct V_1 * V_12 ;
unsigned int V_108 ;
if ( V_172 -> V_202 )
return;
for ( V_108 = 0 ; V_108 < V_3 -> V_7 . V_110 ; V_108 ++ ) {
F_43 (cl, &q->clhash.hash[h], common.hnode) {
if ( V_172 -> V_203 < V_172 -> V_204 ) {
V_172 -> V_203 ++ ;
continue;
}
if ( V_172 -> V_205 ( V_18 , ( unsigned long ) V_12 , V_172 ) < 0 ) {
V_172 -> V_202 = 1 ;
return;
}
V_172 -> V_203 ++ ;
}
}
}
static int T_7 F_124 ( void )
{
return F_125 ( & V_206 ) ;
}
static void T_8 F_126 ( void )
{
F_127 ( & V_206 ) ;
}
