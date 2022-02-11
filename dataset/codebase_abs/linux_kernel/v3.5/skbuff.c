static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_4 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 1 ;
}
static void F_6 ( struct V_6 * V_7 , int V_8 , void * V_9 )
{
F_7 ( L_1 ,
V_10 , V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_2 ) ;
F_8 () ;
}
static void F_9 ( struct V_6 * V_7 , int V_8 , void * V_9 )
{
F_7 ( L_1 ,
V_10 , V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_2 ) ;
F_8 () ;
}
struct V_6 * F_10 ( unsigned int V_18 , T_1 V_19 ,
int V_20 , int V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_6 * V_7 ;
T_2 * V_13 ;
V_23 = V_20 ? V_26 : V_27 ;
V_7 = F_11 ( V_23 , V_19 & ~ V_28 , V_21 ) ;
if ( ! V_7 )
goto V_29;
F_12 ( V_7 ) ;
V_18 = F_13 ( V_18 ) ;
V_18 += F_13 ( sizeof( struct V_24 ) ) ;
V_13 = F_14 ( V_18 , V_19 , V_21 ) ;
if ( ! V_13 )
goto V_30;
V_18 = F_15 ( F_16 ( V_13 ) ) ;
F_12 ( V_13 + V_18 ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_31 = F_18 ( V_18 ) ;
F_19 ( & V_7 -> V_32 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_20 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_21
V_7 -> V_33 = ~ 0U ;
#endif
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
F_23 ( V_25 -> V_35 ) ;
if ( V_20 ) {
struct V_6 * V_36 = V_7 + 1 ;
T_3 * V_37 = ( T_3 * ) ( V_36 + 1 ) ;
F_24 ( V_36 , V_38 ) ;
F_24 ( V_36 , V_39 ) ;
V_7 -> V_20 = V_40 ;
F_19 ( V_37 , 1 ) ;
V_36 -> V_20 = V_41 ;
}
V_29:
return V_7 ;
V_30:
F_25 ( V_23 , V_7 ) ;
V_7 = NULL ;
goto V_29;
}
struct V_6 * F_26 ( void * V_13 , unsigned int V_42 )
{
struct V_24 * V_25 ;
struct V_6 * V_7 ;
unsigned int V_18 = V_42 ? : F_16 ( V_13 ) ;
V_7 = F_27 ( V_27 , V_43 ) ;
if ( ! V_7 )
return NULL ;
V_18 -= F_13 ( sizeof( struct V_24 ) ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_31 = F_18 ( V_18 ) ;
V_7 -> V_44 = V_42 != 0 ;
F_19 ( & V_7 -> V_32 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_20 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_21
V_7 -> V_33 = ~ 0U ;
#endif
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
F_23 ( V_25 -> V_35 ) ;
return V_7 ;
}
void * F_28 ( unsigned int V_45 )
{
struct V_46 * V_47 ;
void * V_13 = NULL ;
unsigned long V_48 ;
F_29 ( V_48 ) ;
V_47 = & F_30 ( V_46 ) ;
if ( F_31 ( ! V_47 -> V_5 ) ) {
V_49:
V_47 -> V_5 = F_32 ( V_43 | V_50 ) ;
V_47 -> V_51 = 0 ;
}
if ( F_33 ( V_47 -> V_5 ) ) {
if ( V_47 -> V_51 + V_45 > V_52 ) {
F_2 ( V_47 -> V_5 ) ;
goto V_49;
}
V_13 = F_34 ( V_47 -> V_5 ) + V_47 -> V_51 ;
V_47 -> V_51 += V_45 ;
F_4 ( V_47 -> V_5 ) ;
}
F_35 ( V_48 ) ;
return V_13 ;
}
struct V_6 * F_36 ( struct V_53 * V_16 ,
unsigned int V_54 , T_1 V_19 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_45 = F_13 ( V_54 + V_55 ) +
F_13 ( sizeof( struct V_24 ) ) ;
if ( V_45 <= V_52 && ! ( V_19 & ( V_56 | V_57 ) ) ) {
void * V_13 = F_28 ( V_45 ) ;
if ( F_33 ( V_13 ) ) {
V_7 = F_26 ( V_13 , V_45 ) ;
if ( F_31 ( ! V_7 ) )
F_2 ( F_37 ( V_13 ) ) ;
}
} else {
V_7 = F_10 ( V_54 + V_55 , V_19 , 0 , V_58 ) ;
}
if ( F_33 ( V_7 ) ) {
F_38 ( V_7 , V_55 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_39 ( struct V_6 * V_7 , int V_59 , struct V_5 * V_5 , int V_60 ,
int V_18 , unsigned int V_31 )
{
F_40 ( V_7 , V_59 , V_5 , V_60 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_61 += V_18 ;
V_7 -> V_31 += V_31 ;
}
static void F_41 ( struct V_6 * * V_62 )
{
struct V_6 * V_63 = * V_62 ;
* V_62 = NULL ;
do {
struct V_6 * V_64 = V_63 ;
V_63 = V_63 -> V_65 ;
F_42 ( V_64 ) ;
} while ( V_63 );
}
static inline void F_43 ( struct V_6 * V_7 )
{
F_41 ( & F_22 ( V_7 ) -> V_66 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_6 * V_63 ;
F_45 (skb, list)
F_46 ( V_63 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
if ( V_7 -> V_44 )
F_2 ( F_37 ( V_7 -> V_12 ) ) ;
else
F_48 ( V_7 -> V_12 ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_67 ||
! F_50 ( V_7 -> V_68 ? ( 1 << V_69 ) + 1 : 1 ,
& F_22 ( V_7 ) -> V_34 ) ) {
if ( F_22 ( V_7 ) -> V_70 ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ )
F_51 ( V_7 , V_59 ) ;
}
if ( F_22 ( V_7 ) -> V_71 & V_72 ) {
struct V_73 * V_74 ;
V_74 = F_22 ( V_7 ) -> V_35 ;
if ( V_74 -> V_75 )
V_74 -> V_75 ( V_74 ) ;
}
if ( F_52 ( V_7 ) )
F_43 ( V_7 ) ;
F_47 ( V_7 ) ;
}
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_6 * V_76 ;
T_3 * V_37 ;
switch ( V_7 -> V_20 ) {
case V_41 :
F_25 ( V_27 , V_7 ) ;
break;
case V_40 :
V_37 = ( T_3 * ) ( V_7 + 2 ) ;
if ( F_54 ( V_37 ) )
F_25 ( V_26 , V_7 ) ;
break;
case V_77 :
V_37 = ( T_3 * ) ( V_7 + 1 ) ;
V_76 = V_7 - 1 ;
V_7 -> V_20 = V_41 ;
if ( F_54 ( V_37 ) )
F_25 ( V_26 , V_76 ) ;
break;
}
}
static void F_55 ( struct V_6 * V_7 )
{
F_56 ( V_7 ) ;
#ifdef F_57
F_58 ( V_7 -> V_78 ) ;
#endif
if ( V_7 -> V_79 ) {
F_59 ( F_60 () ) ;
V_7 -> V_79 ( V_7 ) ;
}
#if F_61 ( V_80 )
F_62 ( V_7 -> V_81 ) ;
#endif
#ifdef F_63
F_64 ( V_7 -> V_82 ) ;
#endif
#ifdef F_65
F_66 ( V_7 -> V_83 ) ;
#endif
#ifdef F_67
V_7 -> V_84 = 0 ;
#ifdef F_68
V_7 -> V_85 = 0 ;
#endif
#endif
}
static void F_69 ( struct V_6 * V_7 )
{
F_55 ( V_7 ) ;
F_49 ( V_7 ) ;
}
void F_70 ( struct V_6 * V_7 )
{
F_69 ( V_7 ) ;
F_53 ( V_7 ) ;
}
void F_42 ( struct V_6 * V_7 )
{
if ( F_31 ( ! V_7 ) )
return;
if ( F_33 ( F_71 ( & V_7 -> V_32 ) == 1 ) )
F_72 () ;
else if ( F_33 ( ! F_54 ( & V_7 -> V_32 ) ) )
return;
F_73 ( V_7 , F_74 ( 0 ) ) ;
F_70 ( V_7 ) ;
}
void F_75 ( struct V_6 * V_7 )
{
if ( F_31 ( ! V_7 ) )
return;
if ( F_33 ( F_71 ( & V_7 -> V_32 ) == 1 ) )
F_72 () ;
else if ( F_33 ( ! F_54 ( & V_7 -> V_32 ) ) )
return;
F_76 ( V_7 ) ;
F_70 ( V_7 ) ;
}
void F_77 ( struct V_6 * V_7 )
{
struct V_24 * V_25 ;
F_55 ( V_7 ) ;
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_13 = V_7 -> V_12 + V_55 ;
F_20 ( V_7 ) ;
}
bool F_78 ( struct V_6 * V_7 , int V_86 )
{
if ( ! F_79 ( V_7 , V_86 ) )
return false ;
F_77 ( V_7 ) ;
return true ;
}
static void F_80 ( struct V_6 * V_87 , const struct V_6 * V_88 )
{
V_87 -> V_89 = V_88 -> V_89 ;
V_87 -> V_16 = V_88 -> V_16 ;
V_87 -> V_90 = V_88 -> V_90 ;
V_87 -> V_91 = V_88 -> V_91 ;
V_87 -> V_33 = V_88 -> V_33 ;
F_81 ( V_87 , V_88 ) ;
V_87 -> V_92 = V_88 -> V_92 ;
V_87 -> V_93 = V_88 -> V_93 ;
V_87 -> V_94 = V_88 -> V_94 ;
V_87 -> V_95 = V_88 -> V_95 ;
#ifdef F_57
V_87 -> V_78 = F_82 ( V_88 -> V_78 ) ;
#endif
memcpy ( V_87 -> V_96 , V_88 -> V_96 , sizeof( V_88 -> V_96 ) ) ;
V_87 -> V_97 = V_88 -> V_97 ;
V_87 -> V_98 = V_88 -> V_98 ;
V_87 -> V_99 = V_88 -> V_99 ;
V_87 -> V_100 = V_88 -> V_100 ;
F_83 ( V_87 , V_88 ) ;
V_87 -> V_101 = V_88 -> V_101 ;
#if F_61 ( V_102 )
V_87 -> V_103 = V_88 -> V_103 ;
#endif
V_87 -> V_104 = V_88 -> V_104 ;
V_87 -> V_105 = V_88 -> V_105 ;
V_87 -> V_106 = V_88 -> V_106 ;
F_84 ( V_87 , V_88 ) ;
#if F_61 ( V_107 )
V_87 -> V_108 = V_88 -> V_108 ;
#endif
#ifdef F_67
V_87 -> V_84 = V_88 -> V_84 ;
#ifdef F_68
V_87 -> V_85 = V_88 -> V_85 ;
#endif
#endif
V_87 -> V_109 = V_88 -> V_109 ;
F_85 ( V_87 , V_88 ) ;
}
static struct V_6 * F_86 ( struct V_6 * V_110 , struct V_6 * V_7 )
{
#define F_87 ( T_4 ) n->x = skb->x
V_110 -> V_65 = V_110 -> V_111 = NULL ;
V_110 -> V_112 = NULL ;
F_80 ( V_110 , V_7 ) ;
F_87 ( V_11 ) ;
F_87 ( V_61 ) ;
F_87 ( V_113 ) ;
V_110 -> V_114 = V_7 -> V_68 ? F_88 ( V_7 ) : V_7 -> V_114 ;
V_110 -> V_67 = 1 ;
V_110 -> V_68 = 0 ;
V_110 -> V_79 = NULL ;
F_87 ( V_14 ) ;
F_87 ( V_15 ) ;
F_87 ( V_12 ) ;
F_87 ( V_44 ) ;
F_87 ( V_13 ) ;
F_87 ( V_31 ) ;
F_19 ( & V_110 -> V_32 , 1 ) ;
F_89 ( & ( F_22 ( V_7 ) -> V_34 ) ) ;
V_7 -> V_67 = 1 ;
return V_110 ;
#undef F_87
}
struct V_6 * F_90 ( struct V_6 * V_115 , struct V_6 * V_116 )
{
F_69 ( V_115 ) ;
return F_86 ( V_115 , V_116 ) ;
}
int F_91 ( struct V_6 * V_7 , T_1 V_19 )
{
int V_59 ;
int V_117 = F_22 ( V_7 ) -> V_70 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_73 * V_74 = F_22 ( V_7 ) -> V_35 ;
for ( V_59 = 0 ; V_59 < V_117 ; V_59 ++ ) {
T_2 * V_118 ;
T_5 * V_119 = & F_22 ( V_7 ) -> V_120 [ V_59 ] ;
V_5 = F_32 ( V_43 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_65 = (struct V_5 * ) V_12 -> V_121 ;
F_2 ( V_12 ) ;
V_12 = V_65 ;
}
return - V_122 ;
}
V_118 = F_92 ( F_93 ( V_119 ) ) ;
memcpy ( F_34 ( V_5 ) ,
V_118 + V_119 -> V_123 , F_94 ( V_119 ) ) ;
F_95 ( V_118 ) ;
V_5 -> V_121 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ )
F_51 ( V_7 , V_59 ) ;
V_74 -> V_75 ( V_74 ) ;
for ( V_59 = F_22 ( V_7 ) -> V_70 ; V_59 > 0 ; V_59 -- ) {
F_96 ( V_7 , V_59 - 1 , V_12 , 0 ,
F_22 ( V_7 ) -> V_120 [ V_59 - 1 ] . V_18 ) ;
V_12 = (struct V_5 * ) V_12 -> V_121 ;
}
F_22 ( V_7 ) -> V_71 &= ~ V_72 ;
return 0 ;
}
struct V_6 * F_97 ( struct V_6 * V_7 , T_1 V_19 )
{
struct V_6 * V_110 ;
if ( F_22 ( V_7 ) -> V_71 & V_72 ) {
if ( F_91 ( V_7 , V_19 ) )
return NULL ;
}
V_110 = V_7 + 1 ;
if ( V_7 -> V_20 == V_40 &&
V_110 -> V_20 == V_41 ) {
T_3 * V_37 = ( T_3 * ) ( V_110 + 1 ) ;
V_110 -> V_20 = V_77 ;
F_89 ( V_37 ) ;
} else {
V_110 = F_27 ( V_27 , V_19 ) ;
if ( ! V_110 )
return NULL ;
F_24 ( V_110 , V_38 ) ;
F_24 ( V_110 , V_39 ) ;
V_110 -> V_20 = V_41 ;
}
return F_86 ( V_110 , V_7 ) ;
}
static void F_98 ( struct V_6 * V_87 , const struct V_6 * V_88 )
{
#ifndef F_21
unsigned long V_51 = V_87 -> V_13 - V_88 -> V_13 ;
#endif
F_80 ( V_87 , V_88 ) ;
#ifndef F_21
V_87 -> V_90 += V_51 ;
V_87 -> V_91 += V_51 ;
if ( F_99 ( V_87 ) )
V_87 -> V_33 += V_51 ;
#endif
F_22 ( V_87 ) -> V_124 = F_22 ( V_88 ) -> V_124 ;
F_22 ( V_87 ) -> V_125 = F_22 ( V_88 ) -> V_125 ;
F_22 ( V_87 ) -> V_126 = F_22 ( V_88 ) -> V_126 ;
}
struct V_6 * F_100 ( const struct V_6 * V_7 , T_1 V_19 )
{
int V_127 = F_88 ( V_7 ) ;
unsigned int V_18 = F_101 ( V_7 ) + V_7 -> V_61 ;
struct V_6 * V_110 = F_102 ( V_18 , V_19 ) ;
if ( ! V_110 )
return NULL ;
F_38 ( V_110 , V_127 ) ;
F_103 ( V_110 , V_7 -> V_11 ) ;
if ( F_104 ( V_7 , - V_127 , V_110 -> V_12 , V_127 + V_7 -> V_11 ) )
F_8 () ;
F_98 ( V_110 , V_7 ) ;
return V_110 ;
}
struct V_6 * F_105 ( struct V_6 * V_7 , int V_128 , T_1 V_19 )
{
unsigned int V_18 = F_106 ( V_7 ) + V_128 ;
struct V_6 * V_110 = F_102 ( V_18 , V_19 ) ;
if ( ! V_110 )
goto V_29;
F_38 ( V_110 , V_128 ) ;
F_103 ( V_110 , F_106 ( V_7 ) ) ;
F_107 ( V_7 , V_110 -> V_13 , V_110 -> V_11 ) ;
V_110 -> V_31 += V_7 -> V_61 ;
V_110 -> V_61 = V_7 -> V_61 ;
V_110 -> V_11 = V_7 -> V_11 ;
if ( F_22 ( V_7 ) -> V_70 ) {
int V_59 ;
if ( F_22 ( V_7 ) -> V_71 & V_72 ) {
if ( F_91 ( V_7 , V_19 ) ) {
F_42 ( V_110 ) ;
V_110 = NULL ;
goto V_29;
}
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
F_22 ( V_110 ) -> V_120 [ V_59 ] = F_22 ( V_7 ) -> V_120 [ V_59 ] ;
F_108 ( V_7 , V_59 ) ;
}
F_22 ( V_110 ) -> V_70 = V_59 ;
}
if ( F_52 ( V_7 ) ) {
F_22 ( V_110 ) -> V_66 = F_22 ( V_7 ) -> V_66 ;
F_44 ( V_110 ) ;
}
F_98 ( V_110 , V_7 ) ;
V_29:
return V_110 ;
}
int F_109 ( struct V_6 * V_7 , int V_129 , int V_130 ,
T_1 V_19 )
{
int V_59 ;
T_2 * V_13 ;
int V_18 = V_129 + F_101 ( V_7 ) + V_130 ;
long V_60 ;
F_110 ( V_129 < 0 ) ;
if ( F_111 ( V_7 ) )
F_8 () ;
V_18 = F_13 ( V_18 ) ;
V_13 = F_112 ( V_18 + F_13 ( sizeof( struct V_24 ) ) ,
V_19 ) ;
if ( ! V_13 )
goto V_30;
V_18 = F_15 ( F_16 ( V_13 ) ) ;
memcpy ( V_13 + V_129 , V_7 -> V_12 , F_113 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_24 * ) ( V_13 + V_18 ) ,
F_22 ( V_7 ) ,
F_17 ( struct V_24 , V_120 [ F_22 ( V_7 ) -> V_70 ] ) ) ;
if ( F_114 ( V_7 ) ) {
if ( F_22 ( V_7 ) -> V_71 & V_72 ) {
if ( F_91 ( V_7 , V_19 ) )
goto V_131;
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ )
F_108 ( V_7 , V_59 ) ;
if ( F_52 ( V_7 ) )
F_44 ( V_7 ) ;
F_49 ( V_7 ) ;
} else {
F_47 ( V_7 ) ;
}
V_60 = ( V_13 + V_129 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_44 = 0 ;
V_7 -> V_13 += V_60 ;
#ifdef F_21
V_7 -> V_15 = V_18 ;
V_60 = V_129 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_60 ;
V_7 -> V_90 += V_60 ;
V_7 -> V_91 += V_60 ;
if ( F_99 ( V_7 ) )
V_7 -> V_33 += V_60 ;
if ( V_7 -> V_100 == V_132 )
V_7 -> V_133 += V_129 ;
V_7 -> V_67 = 0 ;
V_7 -> V_114 = 0 ;
V_7 -> V_68 = 0 ;
F_19 ( & F_22 ( V_7 ) -> V_34 , 1 ) ;
return 0 ;
V_131:
F_48 ( V_13 ) ;
V_30:
return - V_122 ;
}
struct V_6 * F_115 ( struct V_6 * V_7 , unsigned int V_128 )
{
struct V_6 * V_134 ;
int V_135 = V_128 - F_88 ( V_7 ) ;
if ( V_135 <= 0 )
V_134 = F_116 ( V_7 , V_43 ) ;
else {
V_134 = F_97 ( V_7 , V_43 ) ;
if ( V_134 && F_109 ( V_134 , F_13 ( V_135 ) , 0 ,
V_43 ) ) {
F_42 ( V_134 ) ;
V_134 = NULL ;
}
}
return V_134 ;
}
struct V_6 * F_117 ( const struct V_6 * V_7 ,
int V_136 , int V_137 ,
T_1 V_19 )
{
struct V_6 * V_110 = F_102 ( V_136 + V_7 -> V_11 + V_137 ,
V_19 ) ;
int V_138 = F_88 ( V_7 ) ;
int V_139 , V_140 ;
int V_60 ;
if ( ! V_110 )
return NULL ;
F_38 ( V_110 , V_136 ) ;
F_103 ( V_110 , V_7 -> V_11 ) ;
V_139 = V_138 ;
V_140 = 0 ;
if ( V_136 <= V_139 )
V_139 = V_136 ;
else
V_140 = V_136 - V_139 ;
if ( F_104 ( V_7 , - V_139 , V_110 -> V_12 + V_140 ,
V_7 -> V_11 + V_139 ) )
F_8 () ;
F_98 ( V_110 , V_7 ) ;
V_60 = V_136 - V_138 ;
if ( V_110 -> V_100 == V_132 )
V_110 -> V_133 += V_60 ;
#ifdef F_21
V_110 -> V_90 += V_60 ;
V_110 -> V_91 += V_60 ;
if ( F_99 ( V_7 ) )
V_110 -> V_33 += V_60 ;
#endif
return V_110 ;
}
int F_118 ( struct V_6 * V_7 , int V_141 )
{
int V_142 ;
int V_130 ;
if ( ! F_114 ( V_7 ) && F_119 ( V_7 ) >= V_141 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_141 ) ;
return 0 ;
}
V_130 = V_7 -> V_61 + V_141 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_33 ( F_114 ( V_7 ) || V_130 > 0 ) ) {
V_142 = F_109 ( V_7 , 0 , V_130 , V_43 ) ;
if ( F_31 ( V_142 ) )
goto V_143;
}
V_142 = F_120 ( V_7 ) ;
if ( F_31 ( V_142 ) )
goto V_143;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_141 ) ;
return 0 ;
V_143:
F_42 ( V_7 ) ;
return V_142 ;
}
unsigned char * F_103 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_144 = F_113 ( V_7 ) ;
F_121 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_31 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_74 ( 0 ) ) ;
return V_144 ;
}
unsigned char * F_122 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_31 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_74 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_123 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_124 ( V_7 , V_11 ) ;
}
void F_125 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_126 ( V_7 , V_11 ) ;
}
int F_127 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_145 ;
struct V_6 * V_146 ;
int V_51 = F_106 ( V_7 ) ;
int V_147 = F_22 ( V_7 ) -> V_70 ;
int V_59 ;
int V_142 ;
if ( F_114 ( V_7 ) &&
F_31 ( ( V_142 = F_109 ( V_7 , 0 , 0 , V_43 ) ) ) )
return V_142 ;
V_59 = 0 ;
if ( V_51 >= V_11 )
goto V_148;
for (; V_59 < V_147 ; V_59 ++ ) {
int V_15 = V_51 + F_94 ( & F_22 ( V_7 ) -> V_120 [ V_59 ] ) ;
if ( V_15 < V_11 ) {
V_51 = V_15 ;
continue;
}
F_128 ( & F_22 ( V_7 ) -> V_120 [ V_59 ++ ] , V_11 - V_51 ) ;
V_148:
F_22 ( V_7 ) -> V_70 = V_59 ;
for (; V_59 < V_147 ; V_59 ++ )
F_51 ( V_7 , V_59 ) ;
if ( F_52 ( V_7 ) )
F_43 ( V_7 ) ;
goto V_149;
}
for ( V_145 = & F_22 ( V_7 ) -> V_66 ; ( V_146 = * V_145 ) ;
V_145 = & V_146 -> V_65 ) {
int V_15 = V_51 + V_146 -> V_11 ;
if ( F_111 ( V_146 ) ) {
struct V_6 * V_150 ;
V_150 = F_97 ( V_146 , V_43 ) ;
if ( F_31 ( ! V_150 ) )
return - V_122 ;
V_150 -> V_65 = V_146 -> V_65 ;
F_75 ( V_146 ) ;
V_146 = V_150 ;
* V_145 = V_146 ;
}
if ( V_15 < V_11 ) {
V_51 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_31 ( ( V_142 = F_129 ( V_146 , V_11 - V_51 ) ) ) )
return V_142 ;
if ( V_146 -> V_65 )
F_41 ( & V_146 -> V_65 ) ;
break;
}
V_149:
if ( V_11 > F_106 ( V_7 ) ) {
V_7 -> V_61 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_61 = 0 ;
F_130 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_131 ( struct V_6 * V_7 , int V_135 )
{
int V_59 , V_151 , V_152 = ( V_7 -> V_14 + V_135 ) - V_7 -> V_15 ;
if ( V_152 > 0 || F_114 ( V_7 ) ) {
if ( F_109 ( V_7 , 0 , V_152 > 0 ? V_152 + 128 : 0 ,
V_43 ) )
return NULL ;
}
if ( F_104 ( V_7 , F_106 ( V_7 ) , F_113 ( V_7 ) , V_135 ) )
F_8 () ;
if ( ! F_52 ( V_7 ) )
goto V_153;
V_152 = V_135 ;
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
int V_18 = F_94 ( & F_22 ( V_7 ) -> V_120 [ V_59 ] ) ;
if ( V_18 >= V_152 )
goto V_153;
V_152 -= V_18 ;
}
if ( V_152 ) {
struct V_6 * V_63 = F_22 ( V_7 ) -> V_66 ;
struct V_6 * V_154 = NULL ;
struct V_6 * V_155 = NULL ;
do {
F_110 ( ! V_63 ) ;
if ( V_63 -> V_11 <= V_152 ) {
V_152 -= V_63 -> V_11 ;
V_63 = V_63 -> V_65 ;
V_155 = V_63 ;
} else {
if ( F_111 ( V_63 ) ) {
V_154 = F_97 ( V_63 , V_43 ) ;
if ( ! V_154 )
return NULL ;
V_155 = V_63 -> V_65 ;
V_63 = V_154 ;
} else {
V_155 = V_63 ;
}
if ( ! F_132 ( V_63 , V_152 ) ) {
F_42 ( V_154 ) ;
return NULL ;
}
break;
}
} while ( V_152 );
while ( ( V_63 = F_22 ( V_7 ) -> V_66 ) != V_155 ) {
F_22 ( V_7 ) -> V_66 = V_63 -> V_65 ;
F_42 ( V_63 ) ;
}
if ( V_154 ) {
V_154 -> V_65 = V_63 ;
F_22 ( V_7 ) -> V_66 = V_154 ;
}
}
V_153:
V_152 = V_135 ;
V_151 = 0 ;
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
int V_18 = F_94 ( & F_22 ( V_7 ) -> V_120 [ V_59 ] ) ;
if ( V_18 <= V_152 ) {
F_51 ( V_7 , V_59 ) ;
V_152 -= V_18 ;
} else {
F_22 ( V_7 ) -> V_120 [ V_151 ] = F_22 ( V_7 ) -> V_120 [ V_59 ] ;
if ( V_152 ) {
F_22 ( V_7 ) -> V_120 [ V_151 ] . V_123 += V_152 ;
F_133 ( & F_22 ( V_7 ) -> V_120 [ V_151 ] , V_152 ) ;
V_152 = 0 ;
}
V_151 ++ ;
}
}
F_22 ( V_7 ) -> V_70 = V_151 ;
V_7 -> V_14 += V_135 ;
V_7 -> V_61 -= V_135 ;
return F_113 ( V_7 ) ;
}
int F_104 ( const struct V_6 * V_7 , int V_51 , void * V_156 , int V_11 )
{
int V_157 = F_106 ( V_7 ) ;
struct V_6 * V_158 ;
int V_59 , V_159 ;
if ( V_51 > ( int ) V_7 -> V_11 - V_11 )
goto V_160;
if ( ( V_159 = V_157 - V_51 ) > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
F_134 ( V_7 , V_51 , V_156 , V_159 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return 0 ;
V_51 += V_159 ;
V_156 += V_159 ;
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
int V_15 ;
T_5 * V_119 = & F_22 ( V_7 ) -> V_120 [ V_59 ] ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + F_94 ( V_119 ) ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
T_2 * V_118 ;
if ( V_159 > V_11 )
V_159 = V_11 ;
V_118 = F_92 ( F_93 ( V_119 ) ) ;
memcpy ( V_156 ,
V_118 + V_119 -> V_123 + V_51 - V_157 ,
V_159 ) ;
F_95 ( V_118 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return 0 ;
V_51 += V_159 ;
V_156 += V_159 ;
}
V_157 = V_15 ;
}
F_45 (skb, frag_iter) {
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + V_158 -> V_11 ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
if ( F_104 ( V_158 , V_51 - V_157 , V_156 , V_159 ) )
goto V_160;
if ( ( V_11 -= V_159 ) == 0 )
return 0 ;
V_51 += V_159 ;
V_156 += V_159 ;
}
V_157 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_160:
return - V_161 ;
}
static void F_135 ( struct V_162 * V_163 , unsigned int V_59 )
{
F_2 ( V_163 -> V_164 [ V_59 ] ) ;
}
static struct V_5 * F_136 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_51 ,
struct V_6 * V_7 , struct V_165 * V_112 )
{
struct V_5 * V_166 = V_112 -> V_167 ;
unsigned int V_60 ;
if ( ! V_166 ) {
V_168:
V_166 = V_112 -> V_167 = F_137 ( V_112 -> V_169 , 0 ) ;
if ( ! V_166 )
return NULL ;
V_60 = V_112 -> V_170 = 0 ;
} else {
unsigned int V_171 ;
if ( F_138 ( V_166 ) == 1 )
V_112 -> V_170 = 0 ;
V_60 = V_112 -> V_170 ;
V_171 = V_52 - V_60 ;
if ( V_171 < 64 && V_171 < * V_11 ) {
F_2 ( V_166 ) ;
goto V_168;
}
* V_11 = F_139 (unsigned int, *len, mlen) ;
}
memcpy ( F_34 ( V_166 ) + V_60 , F_34 ( V_5 ) + * V_51 , * V_11 ) ;
V_112 -> V_170 += * V_11 ;
* V_51 = V_60 ;
return V_166 ;
}
static bool F_140 ( const struct V_162 * V_163 ,
struct V_5 * V_5 ,
unsigned int V_51 )
{
return V_163 -> V_172 &&
V_163 -> V_164 [ V_163 -> V_172 - 1 ] == V_5 &&
( V_163 -> V_173 [ V_163 -> V_172 - 1 ] . V_51 +
V_163 -> V_173 [ V_163 -> V_172 - 1 ] . V_11 == V_51 ) ;
}
static bool F_141 ( struct V_162 * V_163 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_51 ,
struct V_6 * V_7 , bool V_174 ,
struct V_165 * V_112 )
{
if ( F_31 ( V_163 -> V_172 == V_175 ) )
return true ;
if ( V_174 ) {
V_5 = F_136 ( V_5 , V_11 , & V_51 , V_7 , V_112 ) ;
if ( ! V_5 )
return true ;
}
if ( F_140 ( V_163 , V_5 , V_51 ) ) {
V_163 -> V_173 [ V_163 -> V_172 - 1 ] . V_11 += * V_11 ;
return false ;
}
F_4 ( V_5 ) ;
V_163 -> V_164 [ V_163 -> V_172 ] = V_5 ;
V_163 -> V_173 [ V_163 -> V_172 ] . V_11 = * V_11 ;
V_163 -> V_173 [ V_163 -> V_172 ] . V_51 = V_51 ;
V_163 -> V_172 ++ ;
return false ;
}
static inline void F_142 ( struct V_5 * * V_5 , unsigned int * V_176 ,
unsigned int * V_177 , unsigned int V_60 )
{
unsigned long V_110 ;
* V_176 += V_60 ;
V_110 = * V_176 / V_52 ;
if ( V_110 )
* V_5 = F_143 ( * V_5 , V_110 ) ;
* V_176 = * V_176 % V_52 ;
* V_177 -= V_60 ;
}
static bool F_144 ( struct V_5 * V_5 , unsigned int V_176 ,
unsigned int V_177 , unsigned int * V_60 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_162 * V_163 , bool V_174 ,
struct V_165 * V_112 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return true ;
if ( * V_60 >= V_177 ) {
* V_60 -= V_177 ;
return false ;
}
if ( * V_60 ) {
F_142 ( & V_5 , & V_176 , & V_177 , * V_60 ) ;
* V_60 = 0 ;
}
do {
unsigned int V_178 = F_145 ( * V_11 , V_177 ) ;
V_178 = F_139 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_141 ( V_163 , V_2 , V_5 , & V_178 , V_176 , V_7 , V_174 , V_112 ) )
return true ;
F_142 ( & V_5 , & V_176 , & V_177 , V_178 ) ;
* V_11 -= V_178 ;
} while ( * V_11 && V_177 );
return false ;
}
static bool F_146 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_51 , unsigned int * V_11 ,
struct V_162 * V_163 , struct V_165 * V_112 )
{
int V_179 ;
if ( F_144 ( F_147 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_52 - 1 ) ,
F_106 ( V_7 ) ,
V_51 , V_11 , V_7 , V_163 ,
F_148 ( V_7 ) ,
V_112 , V_2 ) )
return true ;
for ( V_179 = 0 ; V_179 < F_22 ( V_7 ) -> V_70 ; V_179 ++ ) {
const T_5 * V_119 = & F_22 ( V_7 ) -> V_120 [ V_179 ] ;
if ( F_144 ( F_93 ( V_119 ) ,
V_119 -> V_123 , F_94 ( V_119 ) ,
V_51 , V_11 , V_7 , V_163 , false , V_112 , V_2 ) )
return true ;
}
return false ;
}
int F_149 ( struct V_6 * V_7 , unsigned int V_51 ,
struct V_1 * V_2 , unsigned int V_180 ,
unsigned int V_48 )
{
struct V_181 V_173 [ V_175 ] ;
struct V_5 * V_164 [ V_175 ] ;
struct V_162 V_163 = {
. V_164 = V_164 ,
. V_173 = V_173 ,
. V_182 = V_175 ,
. V_48 = V_48 ,
. V_183 = & V_184 ,
. V_185 = F_135 ,
} ;
struct V_6 * V_158 ;
struct V_165 * V_112 = V_7 -> V_112 ;
int V_186 = 0 ;
if ( F_146 ( V_7 , V_2 , & V_51 , & V_180 , & V_163 , V_112 ) )
goto V_149;
else if ( ! V_180 )
goto V_149;
F_45 (skb, frag_iter) {
if ( ! V_180 )
break;
if ( F_146 ( V_158 , V_2 , & V_51 , & V_180 , & V_163 , V_112 ) )
break;
}
V_149:
if ( V_163 . V_172 ) {
F_150 ( V_112 ) ;
V_186 = F_151 ( V_2 , & V_163 ) ;
F_152 ( V_112 ) ;
}
return V_186 ;
}
int F_153 ( struct V_6 * V_7 , int V_51 , const void * V_187 , int V_11 )
{
int V_157 = F_106 ( V_7 ) ;
struct V_6 * V_158 ;
int V_59 , V_159 ;
if ( V_51 > ( int ) V_7 -> V_11 - V_11 )
goto V_160;
if ( ( V_159 = V_157 - V_51 ) > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
F_154 ( V_7 , V_51 , V_187 , V_159 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return 0 ;
V_51 += V_159 ;
V_187 += V_159 ;
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
T_5 * V_146 = & F_22 ( V_7 ) -> V_120 [ V_59 ] ;
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + F_94 ( V_146 ) ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
T_2 * V_118 ;
if ( V_159 > V_11 )
V_159 = V_11 ;
V_118 = F_92 ( F_93 ( V_146 ) ) ;
memcpy ( V_118 + V_146 -> V_123 + V_51 - V_157 ,
V_187 , V_159 ) ;
F_95 ( V_118 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return 0 ;
V_51 += V_159 ;
V_187 += V_159 ;
}
V_157 = V_15 ;
}
F_45 (skb, frag_iter) {
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + V_158 -> V_11 ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
if ( F_153 ( V_158 , V_51 - V_157 ,
V_187 , V_159 ) )
goto V_160;
if ( ( V_11 -= V_159 ) == 0 )
return 0 ;
V_51 += V_159 ;
V_187 += V_159 ;
}
V_157 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_160:
return - V_161 ;
}
T_6 F_155 ( const struct V_6 * V_7 , int V_51 ,
int V_11 , T_6 V_97 )
{
int V_157 = F_106 ( V_7 ) ;
int V_59 , V_159 = V_157 - V_51 ;
struct V_6 * V_158 ;
int V_188 = 0 ;
if ( V_159 > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
V_97 = F_156 ( V_7 -> V_13 + V_51 , V_159 , V_97 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return V_97 ;
V_51 += V_159 ;
V_188 = V_159 ;
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
int V_15 ;
T_5 * V_146 = & F_22 ( V_7 ) -> V_120 [ V_59 ] ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + F_94 ( V_146 ) ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
T_6 V_189 ;
T_2 * V_118 ;
if ( V_159 > V_11 )
V_159 = V_11 ;
V_118 = F_92 ( F_93 ( V_146 ) ) ;
V_189 = F_156 ( V_118 + V_146 -> V_123 +
V_51 - V_157 , V_159 , 0 ) ;
F_95 ( V_118 ) ;
V_97 = F_157 ( V_97 , V_189 , V_188 ) ;
if ( ! ( V_11 -= V_159 ) )
return V_97 ;
V_51 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_15 ;
}
F_45 (skb, frag_iter) {
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + V_158 -> V_11 ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
T_6 V_189 ;
if ( V_159 > V_11 )
V_159 = V_11 ;
V_189 = F_155 ( V_158 , V_51 - V_157 ,
V_159 , 0 ) ;
V_97 = F_157 ( V_97 , V_189 , V_188 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return V_97 ;
V_51 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_15 ;
}
F_110 ( V_11 ) ;
return V_97 ;
}
T_6 F_158 ( const struct V_6 * V_7 , int V_51 ,
T_2 * V_156 , int V_11 , T_6 V_97 )
{
int V_157 = F_106 ( V_7 ) ;
int V_59 , V_159 = V_157 - V_51 ;
struct V_6 * V_158 ;
int V_188 = 0 ;
if ( V_159 > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
V_97 = F_159 ( V_7 -> V_13 + V_51 , V_156 ,
V_159 , V_97 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return V_97 ;
V_51 += V_159 ;
V_156 += V_159 ;
V_188 = V_159 ;
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + F_94 ( & F_22 ( V_7 ) -> V_120 [ V_59 ] ) ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
T_6 V_189 ;
T_2 * V_118 ;
T_5 * V_146 = & F_22 ( V_7 ) -> V_120 [ V_59 ] ;
if ( V_159 > V_11 )
V_159 = V_11 ;
V_118 = F_92 ( F_93 ( V_146 ) ) ;
V_189 = F_159 ( V_118 +
V_146 -> V_123 +
V_51 - V_157 , V_156 ,
V_159 , 0 ) ;
F_95 ( V_118 ) ;
V_97 = F_157 ( V_97 , V_189 , V_188 ) ;
if ( ! ( V_11 -= V_159 ) )
return V_97 ;
V_51 += V_159 ;
V_156 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_15 ;
}
F_45 (skb, frag_iter) {
T_6 V_189 ;
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + V_158 -> V_11 ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
V_189 = F_158 ( V_158 ,
V_51 - V_157 ,
V_156 , V_159 , 0 ) ;
V_97 = F_157 ( V_97 , V_189 , V_188 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return V_97 ;
V_51 += V_159 ;
V_156 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_15 ;
}
F_110 ( V_11 ) ;
return V_97 ;
}
void F_160 ( const struct V_6 * V_7 , T_2 * V_156 )
{
T_6 V_97 ;
long V_190 ;
if ( V_7 -> V_100 == V_132 )
V_190 = F_161 ( V_7 ) ;
else
V_190 = F_106 ( V_7 ) ;
F_110 ( V_190 > F_106 ( V_7 ) ) ;
F_107 ( V_7 , V_156 , V_190 ) ;
V_97 = 0 ;
if ( V_190 != V_7 -> V_11 )
V_97 = F_158 ( V_7 , V_190 , V_156 + V_190 ,
V_7 -> V_11 - V_190 , 0 ) ;
if ( V_7 -> V_100 == V_132 ) {
long V_191 = V_190 + V_7 -> V_192 ;
* ( ( V_193 * ) ( V_156 + V_191 ) ) = F_162 ( V_97 ) ;
}
}
struct V_6 * F_163 ( struct V_194 * V_63 )
{
unsigned long V_48 ;
struct V_6 * V_195 ;
F_164 ( & V_63 -> V_196 , V_48 ) ;
V_195 = F_165 ( V_63 ) ;
F_166 ( & V_63 -> V_196 , V_48 ) ;
return V_195 ;
}
struct V_6 * F_167 ( struct V_194 * V_63 )
{
unsigned long V_48 ;
struct V_6 * V_195 ;
F_164 ( & V_63 -> V_196 , V_48 ) ;
V_195 = F_168 ( V_63 ) ;
F_166 ( & V_63 -> V_196 , V_48 ) ;
return V_195 ;
}
void F_169 ( struct V_194 * V_63 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_163 ( V_63 ) ) != NULL )
F_42 ( V_7 ) ;
}
void F_170 ( struct V_194 * V_63 , struct V_6 * V_197 )
{
unsigned long V_48 ;
F_164 ( & V_63 -> V_196 , V_48 ) ;
F_171 ( V_63 , V_197 ) ;
F_166 ( & V_63 -> V_196 , V_48 ) ;
}
void F_172 ( struct V_194 * V_63 , struct V_6 * V_197 )
{
unsigned long V_48 ;
F_164 ( & V_63 -> V_196 , V_48 ) ;
F_173 ( V_63 , V_197 ) ;
F_166 ( & V_63 -> V_196 , V_48 ) ;
}
void F_174 ( struct V_6 * V_7 , struct V_194 * V_63 )
{
unsigned long V_48 ;
F_164 ( & V_63 -> V_196 , V_48 ) ;
F_175 ( V_7 , V_63 ) ;
F_166 ( & V_63 -> V_196 , V_48 ) ;
}
void F_176 ( struct V_6 * V_88 , struct V_6 * V_197 , struct V_194 * V_63 )
{
unsigned long V_48 ;
F_164 ( & V_63 -> V_196 , V_48 ) ;
F_177 ( V_63 , V_88 , V_197 ) ;
F_166 ( & V_63 -> V_196 , V_48 ) ;
}
void F_178 ( struct V_6 * V_88 , struct V_6 * V_197 , struct V_194 * V_63 )
{
unsigned long V_48 ;
F_164 ( & V_63 -> V_196 , V_48 ) ;
F_179 ( V_197 , V_88 -> V_111 , V_88 , V_63 ) ;
F_166 ( & V_63 -> V_196 , V_48 ) ;
}
static inline void F_180 ( struct V_6 * V_7 ,
struct V_6 * V_198 ,
const T_7 V_11 , const int V_188 )
{
int V_59 ;
F_134 ( V_7 , V_11 , F_103 ( V_198 , V_188 - V_11 ) ,
V_188 - V_11 ) ;
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ )
F_22 ( V_198 ) -> V_120 [ V_59 ] = F_22 ( V_7 ) -> V_120 [ V_59 ] ;
F_22 ( V_198 ) -> V_70 = F_22 ( V_7 ) -> V_70 ;
F_22 ( V_7 ) -> V_70 = 0 ;
V_198 -> V_61 = V_7 -> V_61 ;
V_198 -> V_11 += V_198 -> V_61 ;
V_7 -> V_61 = 0 ;
V_7 -> V_11 = V_11 ;
F_130 ( V_7 , V_11 ) ;
}
static inline void F_181 ( struct V_6 * V_7 ,
struct V_6 * V_198 ,
const T_7 V_11 , int V_188 )
{
int V_59 , V_151 = 0 ;
const int V_147 = F_22 ( V_7 ) -> V_70 ;
F_22 ( V_7 ) -> V_70 = 0 ;
V_198 -> V_11 = V_198 -> V_61 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_61 = V_11 - V_188 ;
for ( V_59 = 0 ; V_59 < V_147 ; V_59 ++ ) {
int V_18 = F_94 ( & F_22 ( V_7 ) -> V_120 [ V_59 ] ) ;
if ( V_188 + V_18 > V_11 ) {
F_22 ( V_198 ) -> V_120 [ V_151 ] = F_22 ( V_7 ) -> V_120 [ V_59 ] ;
if ( V_188 < V_11 ) {
F_108 ( V_7 , V_59 ) ;
F_22 ( V_198 ) -> V_120 [ 0 ] . V_123 += V_11 - V_188 ;
F_133 ( & F_22 ( V_198 ) -> V_120 [ 0 ] , V_11 - V_188 ) ;
F_128 ( & F_22 ( V_7 ) -> V_120 [ V_59 ] , V_11 - V_188 ) ;
F_22 ( V_7 ) -> V_70 ++ ;
}
V_151 ++ ;
} else
F_22 ( V_7 ) -> V_70 ++ ;
V_188 += V_18 ;
}
F_22 ( V_198 ) -> V_70 = V_151 ;
}
void F_182 ( struct V_6 * V_7 , struct V_6 * V_198 , const T_7 V_11 )
{
int V_188 = F_106 ( V_7 ) ;
if ( V_11 < V_188 )
F_180 ( V_7 , V_198 , V_11 , V_188 ) ;
else
F_181 ( V_7 , V_198 , V_11 , V_188 ) ;
}
static int F_183 ( struct V_6 * V_7 )
{
return F_114 ( V_7 ) && F_109 ( V_7 , 0 , 0 , V_43 ) ;
}
int F_184 ( struct V_6 * V_199 , struct V_6 * V_7 , int V_200 )
{
int V_187 , V_156 , V_201 , V_202 ;
struct V_203 * V_204 , * V_205 ;
F_110 ( V_200 > V_7 -> V_11 ) ;
F_110 ( F_106 ( V_7 ) ) ;
V_202 = V_200 ;
V_187 = 0 ;
V_156 = F_22 ( V_199 ) -> V_70 ;
V_204 = & F_22 ( V_7 ) -> V_120 [ V_187 ] ;
if ( ! V_156 ||
! F_185 ( V_199 , V_156 , F_93 ( V_204 ) ,
V_204 -> V_123 ) ) {
V_201 = - 1 ;
} else {
V_201 = V_156 - 1 ;
V_202 -= F_94 ( V_204 ) ;
if ( V_202 < 0 ) {
if ( F_183 ( V_7 ) ||
F_183 ( V_199 ) )
return 0 ;
V_204 = & F_22 ( V_7 ) -> V_120 [ V_187 ] ;
V_205 = & F_22 ( V_199 ) -> V_120 [ V_201 ] ;
F_186 ( V_205 , V_200 ) ;
F_133 ( V_204 , V_200 ) ;
V_204 -> V_123 += V_200 ;
goto V_206;
}
V_187 ++ ;
}
if ( ( V_200 == V_7 -> V_11 ) &&
( F_22 ( V_7 ) -> V_70 - V_187 ) > ( V_175 - V_156 ) )
return 0 ;
if ( F_183 ( V_7 ) || F_183 ( V_199 ) )
return 0 ;
while ( ( V_202 > 0 ) && ( V_187 < F_22 ( V_7 ) -> V_70 ) ) {
if ( V_156 == V_175 )
return 0 ;
V_204 = & F_22 ( V_7 ) -> V_120 [ V_187 ] ;
V_205 = & F_22 ( V_199 ) -> V_120 [ V_156 ] ;
if ( V_202 >= F_94 ( V_204 ) ) {
* V_205 = * V_204 ;
V_202 -= F_94 ( V_204 ) ;
V_187 ++ ;
V_156 ++ ;
} else {
F_187 ( V_204 ) ;
V_205 -> V_5 = V_204 -> V_5 ;
V_205 -> V_123 = V_204 -> V_123 ;
F_128 ( V_205 , V_202 ) ;
V_204 -> V_123 += V_202 ;
F_133 ( V_204 , V_202 ) ;
V_202 = 0 ;
V_156 ++ ;
break;
}
}
F_22 ( V_199 ) -> V_70 = V_156 ;
if ( V_201 >= 0 ) {
V_204 = & F_22 ( V_7 ) -> V_120 [ 0 ] ;
V_205 = & F_22 ( V_199 ) -> V_120 [ V_201 ] ;
F_186 ( V_205 , F_94 ( V_204 ) ) ;
F_188 ( V_204 ) ;
}
V_156 = 0 ;
while ( V_187 < F_22 ( V_7 ) -> V_70 )
F_22 ( V_7 ) -> V_120 [ V_156 ++ ] = F_22 ( V_7 ) -> V_120 [ V_187 ++ ] ;
F_22 ( V_7 ) -> V_70 = V_156 ;
F_110 ( V_202 > 0 && ! F_22 ( V_7 ) -> V_70 ) ;
V_206:
V_199 -> V_100 = V_132 ;
V_7 -> V_100 = V_132 ;
V_7 -> V_11 -= V_200 ;
V_7 -> V_61 -= V_200 ;
V_7 -> V_31 -= V_200 ;
V_199 -> V_11 += V_200 ;
V_199 -> V_61 += V_200 ;
V_199 -> V_31 += V_200 ;
return V_200 ;
}
void F_189 ( struct V_6 * V_7 , unsigned int V_187 ,
unsigned int V_156 , struct V_207 * V_208 )
{
V_208 -> V_209 = V_187 ;
V_208 -> V_210 = V_156 ;
V_208 -> V_211 = V_208 -> V_212 = V_7 ;
V_208 -> V_213 = V_208 -> V_214 = 0 ;
V_208 -> V_215 = NULL ;
}
unsigned int F_190 ( unsigned int V_216 , const T_2 * * V_13 ,
struct V_207 * V_208 )
{
unsigned int V_217 , V_218 = V_216 + V_208 -> V_209 ;
T_5 * V_146 ;
if ( F_31 ( V_218 >= V_208 -> V_210 ) )
return 0 ;
V_219:
V_217 = F_106 ( V_208 -> V_212 ) + V_208 -> V_214 ;
if ( V_218 < V_217 && ! V_208 -> V_215 ) {
* V_13 = V_208 -> V_212 -> V_13 + ( V_218 - V_208 -> V_214 ) ;
return V_217 - V_218 ;
}
if ( V_208 -> V_213 == 0 && ! V_208 -> V_215 )
V_208 -> V_214 += F_106 ( V_208 -> V_212 ) ;
while ( V_208 -> V_213 < F_22 ( V_208 -> V_212 ) -> V_70 ) {
V_146 = & F_22 ( V_208 -> V_212 ) -> V_120 [ V_208 -> V_213 ] ;
V_217 = F_94 ( V_146 ) + V_208 -> V_214 ;
if ( V_218 < V_217 ) {
if ( ! V_208 -> V_215 )
V_208 -> V_215 = F_92 ( F_93 ( V_146 ) ) ;
* V_13 = ( T_2 * ) V_208 -> V_215 + V_146 -> V_123 +
( V_218 - V_208 -> V_214 ) ;
return V_217 - V_218 ;
}
if ( V_208 -> V_215 ) {
F_95 ( V_208 -> V_215 ) ;
V_208 -> V_215 = NULL ;
}
V_208 -> V_213 ++ ;
V_208 -> V_214 += F_94 ( V_146 ) ;
}
if ( V_208 -> V_215 ) {
F_95 ( V_208 -> V_215 ) ;
V_208 -> V_215 = NULL ;
}
if ( V_208 -> V_211 == V_208 -> V_212 && F_52 ( V_208 -> V_211 ) ) {
V_208 -> V_212 = F_22 ( V_208 -> V_211 ) -> V_66 ;
V_208 -> V_213 = 0 ;
goto V_219;
} else if ( V_208 -> V_212 -> V_65 ) {
V_208 -> V_212 = V_208 -> V_212 -> V_65 ;
V_208 -> V_213 = 0 ;
goto V_219;
}
return 0 ;
}
void F_191 ( struct V_207 * V_208 )
{
if ( V_208 -> V_215 )
F_95 ( V_208 -> V_215 ) ;
}
static unsigned int F_192 ( unsigned int V_51 , const T_2 * * V_220 ,
struct V_221 * V_222 ,
struct V_223 * V_224 )
{
return F_190 ( V_51 , V_220 , F_193 ( V_224 ) ) ;
}
static void F_194 ( struct V_221 * V_222 , struct V_223 * V_224 )
{
F_191 ( F_193 ( V_224 ) ) ;
}
unsigned int F_195 ( struct V_6 * V_7 , unsigned int V_187 ,
unsigned int V_156 , struct V_221 * V_225 ,
struct V_223 * V_224 )
{
unsigned int V_186 ;
V_225 -> V_226 = F_192 ;
V_225 -> V_227 = F_194 ;
F_189 ( V_7 , V_187 , V_156 , F_193 ( V_224 ) ) ;
V_186 = F_196 ( V_225 , V_224 ) ;
return ( V_186 <= V_156 - V_187 ? V_186 : V_228 ) ;
}
int F_197 ( struct V_165 * V_112 , struct V_6 * V_7 ,
int (* F_198)( void * V_187 , char * V_156 , int V_51 ,
int V_11 , int V_229 , struct V_6 * V_7 ) ,
void * V_187 , int V_54 )
{
int V_230 = 0 ;
T_5 * V_146 = NULL ;
struct V_5 * V_5 = NULL ;
int V_159 , V_231 ;
int V_51 = 0 ;
int V_186 ;
do {
V_230 = F_22 ( V_7 ) -> V_70 ;
if ( V_230 >= V_175 )
return - V_161 ;
V_5 = F_137 ( V_112 -> V_169 , 0 ) ;
if ( V_5 == NULL )
return - V_122 ;
F_40 ( V_7 , V_230 , V_5 , 0 , 0 ) ;
V_7 -> V_31 += V_52 ;
F_199 ( V_52 , & V_112 -> V_232 ) ;
V_230 = F_22 ( V_7 ) -> V_70 ;
V_146 = & F_22 ( V_7 ) -> V_120 [ V_230 - 1 ] ;
V_231 = V_52 - V_146 -> V_123 ;
V_159 = ( V_54 > V_231 ) ? V_231 : V_54 ;
V_186 = F_198 ( V_187 , F_200 ( V_146 ) + F_94 ( V_146 ) ,
V_51 , V_159 , 0 , V_7 ) ;
if ( V_186 < 0 )
return - V_161 ;
F_186 ( V_146 , V_159 ) ;
V_7 -> V_11 += V_159 ;
V_7 -> V_61 += V_159 ;
V_51 += V_159 ;
V_54 -= V_159 ;
} while ( V_54 > 0 );
return 0 ;
}
unsigned char * F_201 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_110 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_110 ( V_7 -> V_11 < V_7 -> V_61 ) ;
F_202 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_203 ( struct V_6 * V_7 , T_8 V_233 )
{
struct V_6 * V_234 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_235 = F_22 ( V_7 ) -> V_66 ;
unsigned int V_236 = F_22 ( V_7 ) -> V_124 ;
unsigned int V_237 = V_7 -> V_13 - F_204 ( V_7 ) ;
unsigned int V_51 = V_237 ;
unsigned int V_128 ;
unsigned int V_11 ;
int V_238 = ! ! ( V_233 & V_239 ) ;
int V_147 = F_22 ( V_7 ) -> V_70 ;
int V_142 = - V_122 ;
int V_59 = 0 ;
int V_188 ;
F_205 ( V_7 , V_237 ) ;
V_128 = F_88 ( V_7 ) ;
V_188 = F_106 ( V_7 ) ;
do {
struct V_6 * V_240 ;
T_5 * V_146 ;
int V_241 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_51 ;
if ( V_11 > V_236 )
V_11 = V_236 ;
V_241 = F_106 ( V_7 ) - V_51 ;
if ( V_241 < 0 )
V_241 = 0 ;
if ( V_241 > V_11 || ! V_238 )
V_241 = V_11 ;
if ( ! V_241 && V_59 >= V_147 ) {
F_110 ( V_235 -> V_11 != V_11 ) ;
V_188 += V_11 ;
V_240 = F_97 ( V_235 , V_43 ) ;
V_235 = V_235 -> V_65 ;
if ( F_31 ( ! V_240 ) )
goto V_142;
V_241 = F_101 ( V_240 ) ;
if ( F_206 ( V_240 , V_237 + V_128 ) ) {
F_42 ( V_240 ) ;
goto V_142;
}
V_240 -> V_31 += F_101 ( V_240 ) - V_241 ;
F_55 ( V_240 ) ;
F_205 ( V_240 , V_237 ) ;
} else {
V_240 = F_102 ( V_241 + V_237 + V_128 ,
V_43 ) ;
if ( F_31 ( ! V_240 ) )
goto V_142;
F_38 ( V_240 , V_128 ) ;
F_207 ( V_240 , V_237 ) ;
}
if ( V_234 )
V_14 -> V_65 = V_240 ;
else
V_234 = V_240 ;
V_14 = V_240 ;
F_80 ( V_240 , V_7 ) ;
V_240 -> V_113 = V_7 -> V_113 ;
if ( V_240 -> V_100 == V_132 )
V_240 -> V_133 += F_88 ( V_240 ) - V_128 ;
F_208 ( V_240 ) ;
F_209 ( V_240 , V_7 -> V_113 ) ;
V_240 -> V_90 = ( V_240 -> V_91 +
F_210 ( V_7 ) ) ;
F_107 ( V_7 , V_240 -> V_13 , V_237 ) ;
if ( V_235 != F_22 ( V_7 ) -> V_66 )
continue;
if ( ! V_238 ) {
V_240 -> V_100 = V_242 ;
V_240 -> V_97 = F_158 ( V_7 , V_51 ,
F_103 ( V_240 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_146 = F_22 ( V_240 ) -> V_120 ;
F_134 ( V_7 , V_51 ,
F_103 ( V_240 , V_241 ) , V_241 ) ;
while ( V_188 < V_51 + V_11 && V_59 < V_147 ) {
* V_146 = F_22 ( V_7 ) -> V_120 [ V_59 ] ;
F_187 ( V_146 ) ;
V_18 = F_94 ( V_146 ) ;
if ( V_188 < V_51 ) {
V_146 -> V_123 += V_51 - V_188 ;
F_133 ( V_146 , V_51 - V_188 ) ;
}
F_22 ( V_240 ) -> V_70 ++ ;
if ( V_188 + V_18 <= V_51 + V_11 ) {
V_59 ++ ;
V_188 += V_18 ;
} else {
F_133 ( V_146 , V_188 + V_18 - ( V_51 + V_11 ) ) ;
goto V_243;
}
V_146 ++ ;
}
if ( V_188 < V_51 + V_11 ) {
struct V_6 * V_244 = V_235 ;
F_110 ( V_188 + V_235 -> V_11 != V_51 + V_11 ) ;
V_188 += V_235 -> V_11 ;
V_235 = V_235 -> V_65 ;
if ( V_244 -> V_65 ) {
V_244 = F_97 ( V_244 , V_43 ) ;
if ( ! V_244 )
goto V_142;
} else
F_46 ( V_244 ) ;
F_211 ( V_240 ) ;
F_22 ( V_240 ) -> V_66 = V_244 ;
}
V_243:
V_240 -> V_61 = V_11 - V_241 ;
V_240 -> V_11 += V_240 -> V_61 ;
V_240 -> V_31 += V_240 -> V_61 ;
} while ( ( V_51 += V_11 ) < V_7 -> V_11 );
return V_234 ;
V_142:
while ( ( V_7 = V_234 ) ) {
V_234 = V_7 -> V_65 ;
F_42 ( V_7 ) ;
}
return F_212 ( V_142 ) ;
}
int F_213 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_166 = * V_12 ;
struct V_6 * V_240 ;
struct V_24 * V_245 = F_22 ( V_7 ) ;
struct V_24 * V_246 = F_22 ( V_166 ) ;
unsigned int V_128 ;
unsigned int V_11 = F_214 ( V_7 ) ;
unsigned int V_51 = F_215 ( V_7 ) ;
unsigned int V_247 = F_106 ( V_7 ) ;
unsigned int V_248 ;
if ( V_166 -> V_11 + V_11 >= 65536 )
return - V_249 ;
if ( V_246 -> V_66 )
goto V_201;
else if ( V_247 <= V_51 ) {
T_5 * V_146 ;
T_5 * V_250 ;
int V_59 = V_245 -> V_70 ;
int V_70 = V_246 -> V_70 + V_59 ;
V_51 -= V_247 ;
if ( V_70 > V_175 )
return - V_249 ;
V_246 -> V_70 = V_70 ;
V_245 -> V_70 = 0 ;
V_146 = V_246 -> V_120 + V_70 ;
V_250 = V_245 -> V_120 + V_59 ;
do {
* -- V_146 = * -- V_250 ;
} while ( -- V_59 );
V_146 -> V_123 += V_51 ;
F_133 ( V_146 , V_51 ) ;
V_248 = V_7 -> V_31 -
F_18 ( F_101 ( V_7 ) ) ;
V_7 -> V_31 -= V_7 -> V_61 ;
V_7 -> V_11 -= V_7 -> V_61 ;
V_7 -> V_61 = 0 ;
F_216 ( V_7 ) -> free = V_251 ;
goto V_149;
} else if ( V_7 -> V_44 ) {
int V_70 = V_246 -> V_70 ;
T_5 * V_146 = V_246 -> V_120 + V_70 ;
struct V_5 * V_5 = F_37 ( V_7 -> V_12 ) ;
unsigned int V_252 = V_247 - V_51 ;
unsigned int V_253 ;
if ( V_70 + 1 + V_245 -> V_70 > V_175 )
return - V_249 ;
V_253 = V_7 -> V_13 -
( unsigned char * ) F_34 ( V_5 ) +
V_51 ;
V_246 -> V_70 = V_70 + 1 + V_245 -> V_70 ;
V_146 -> V_5 . V_166 = V_5 ;
V_146 -> V_123 = V_253 ;
F_128 ( V_146 , V_252 ) ;
memcpy ( V_146 + 1 , V_245 -> V_120 , sizeof( * V_146 ) * V_245 -> V_70 ) ;
V_248 = V_7 -> V_31 - F_13 ( sizeof( struct V_6 ) ) ;
F_216 ( V_7 ) -> free = V_254 ;
goto V_149;
} else if ( F_214 ( V_166 ) != V_246 -> V_124 )
return - V_249 ;
V_128 = F_88 ( V_166 ) ;
V_240 = F_102 ( V_128 + F_215 ( V_166 ) , V_43 ) ;
if ( F_31 ( ! V_240 ) )
return - V_122 ;
F_80 ( V_240 , V_166 ) ;
V_240 -> V_113 = V_166 -> V_113 ;
F_38 ( V_240 , V_128 ) ;
F_207 ( V_240 , F_215 ( V_166 ) ) ;
F_217 ( V_240 , F_204 ( V_166 ) - V_166 -> V_13 ) ;
F_209 ( V_240 , F_218 ( V_166 ) ) ;
F_219 ( V_240 , F_220 ( V_166 ) ) ;
F_221 ( V_166 , F_215 ( V_166 ) ) ;
memcpy ( F_204 ( V_240 ) , F_204 ( V_166 ) ,
V_166 -> V_13 - F_204 ( V_166 ) ) ;
* F_216 ( V_240 ) = * F_216 ( V_166 ) ;
F_22 ( V_240 ) -> V_66 = V_166 ;
F_22 ( V_240 ) -> V_124 = V_246 -> V_124 ;
V_246 -> V_124 = 0 ;
F_222 ( V_166 ) ;
V_240 -> V_111 = V_166 ;
V_240 -> V_61 += V_166 -> V_11 ;
V_240 -> V_31 += V_166 -> V_31 ;
V_240 -> V_11 += V_166 -> V_11 ;
* V_12 = V_240 ;
V_240 -> V_65 = V_166 -> V_65 ;
V_166 -> V_65 = NULL ;
V_166 = V_240 ;
V_201:
V_248 = V_7 -> V_31 ;
if ( V_51 > V_247 ) {
unsigned int V_152 = V_51 - V_247 ;
V_245 -> V_120 [ 0 ] . V_123 += V_152 ;
F_133 ( & V_245 -> V_120 [ 0 ] , V_152 ) ;
V_7 -> V_61 -= V_152 ;
V_7 -> V_11 -= V_152 ;
V_51 = V_247 ;
}
F_221 ( V_7 , V_51 ) ;
V_166 -> V_111 -> V_65 = V_7 ;
V_166 -> V_111 = V_7 ;
F_222 ( V_7 ) ;
V_149:
F_216 ( V_166 ) -> V_255 ++ ;
V_166 -> V_61 += V_11 ;
V_166 -> V_31 += V_248 ;
V_166 -> V_11 += V_11 ;
F_216 ( V_7 ) -> V_256 = 1 ;
return 0 ;
}
void T_9 F_223 ( void )
{
V_27 = F_224 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_257 | V_258 ,
NULL ) ;
V_26 = F_224 ( L_4 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_3 ) ,
0 ,
V_257 | V_258 ,
NULL ) ;
}
static int
F_225 ( struct V_6 * V_7 , struct V_259 * V_238 , int V_51 , int V_11 )
{
int V_157 = F_106 ( V_7 ) ;
int V_59 , V_159 = V_157 - V_51 ;
struct V_6 * V_158 ;
int V_260 = 0 ;
if ( V_159 > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
F_226 ( V_238 , V_7 -> V_13 + V_51 , V_159 ) ;
V_260 ++ ;
if ( ( V_11 -= V_159 ) == 0 )
return V_260 ;
V_51 += V_159 ;
}
for ( V_59 = 0 ; V_59 < F_22 ( V_7 ) -> V_70 ; V_59 ++ ) {
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + F_94 ( & F_22 ( V_7 ) -> V_120 [ V_59 ] ) ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
T_5 * V_146 = & F_22 ( V_7 ) -> V_120 [ V_59 ] ;
if ( V_159 > V_11 )
V_159 = V_11 ;
F_227 ( & V_238 [ V_260 ] , F_93 ( V_146 ) , V_159 ,
V_146 -> V_123 + V_51 - V_157 ) ;
V_260 ++ ;
if ( ! ( V_11 -= V_159 ) )
return V_260 ;
V_51 += V_159 ;
}
V_157 = V_15 ;
}
F_45 (skb, frag_iter) {
int V_15 ;
F_59 ( V_157 > V_51 + V_11 ) ;
V_15 = V_157 + V_158 -> V_11 ;
if ( ( V_159 = V_15 - V_51 ) > 0 ) {
if ( V_159 > V_11 )
V_159 = V_11 ;
V_260 += F_225 ( V_158 , V_238 + V_260 , V_51 - V_157 ,
V_159 ) ;
if ( ( V_11 -= V_159 ) == 0 )
return V_260 ;
V_51 += V_159 ;
}
V_157 = V_15 ;
}
F_110 ( V_11 ) ;
return V_260 ;
}
int F_228 ( struct V_6 * V_7 , struct V_259 * V_238 , int V_51 , int V_11 )
{
int V_261 = F_225 ( V_7 , V_238 , V_51 , V_11 ) ;
F_229 ( & V_238 [ V_261 - 1 ] ) ;
return V_261 ;
}
int F_230 ( struct V_6 * V_7 , int V_262 , struct V_6 * * V_263 )
{
int V_264 ;
int V_260 ;
struct V_6 * V_198 , * * V_265 ;
if ( ( F_114 ( V_7 ) || F_22 ( V_7 ) -> V_70 ) &&
F_131 ( V_7 , F_231 ( V_7 ) - F_106 ( V_7 ) ) == NULL )
return - V_122 ;
if ( ! F_52 ( V_7 ) ) {
if ( F_119 ( V_7 ) < V_262 &&
F_109 ( V_7 , 0 , V_262 - F_119 ( V_7 ) + 128 , V_43 ) )
return - V_122 ;
* V_263 = V_7 ;
return 1 ;
}
V_260 = 1 ;
V_265 = & F_22 ( V_7 ) -> V_66 ;
V_264 = 0 ;
while ( ( V_198 = * V_265 ) != NULL ) {
int V_130 = 0 ;
if ( F_111 ( V_198 ) )
V_264 = 1 ;
if ( V_198 -> V_65 == NULL && V_262 ) {
if ( F_22 ( V_198 ) -> V_70 ||
F_52 ( V_198 ) ||
F_119 ( V_198 ) < V_262 )
V_130 = V_262 + 128 ;
}
if ( V_264 ||
F_114 ( V_198 ) ||
V_130 ||
F_22 ( V_198 ) -> V_70 ||
F_52 ( V_198 ) ) {
struct V_6 * V_134 ;
if ( V_130 == 0 )
V_134 = F_100 ( V_198 , V_43 ) ;
else
V_134 = F_117 ( V_198 ,
F_88 ( V_198 ) ,
V_130 ,
V_43 ) ;
if ( F_31 ( V_134 == NULL ) )
return - V_122 ;
if ( V_198 -> V_112 )
F_232 ( V_134 , V_198 -> V_112 ) ;
V_134 -> V_65 = V_198 -> V_65 ;
* V_265 = V_134 ;
F_42 ( V_198 ) ;
V_198 = V_134 ;
}
V_260 ++ ;
* V_263 = V_198 ;
V_265 = & V_198 -> V_65 ;
}
return V_260 ;
}
static void F_233 ( struct V_6 * V_7 )
{
struct V_165 * V_112 = V_7 -> V_112 ;
F_234 ( V_7 -> V_31 , & V_112 -> V_266 ) ;
}
int F_235 ( struct V_165 * V_112 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_71 ( & V_112 -> V_266 ) + V_7 -> V_31 >=
( unsigned int ) V_112 -> V_267 )
return - V_122 ;
F_236 ( V_7 ) ;
V_7 -> V_112 = V_112 ;
V_7 -> V_79 = F_233 ;
F_199 ( V_7 -> V_31 , & V_112 -> V_266 ) ;
F_237 ( V_7 ) ;
F_172 ( & V_112 -> V_268 , V_7 ) ;
if ( ! F_238 ( V_112 , V_269 ) )
V_112 -> V_270 ( V_112 , V_11 ) ;
return 0 ;
}
void F_239 ( struct V_6 * V_271 ,
struct V_272 * V_273 )
{
struct V_165 * V_112 = V_271 -> V_112 ;
struct V_274 * V_275 ;
struct V_6 * V_7 ;
int V_142 ;
if ( ! V_112 )
return;
V_7 = F_97 ( V_271 , V_43 ) ;
if ( ! V_7 )
return;
if ( V_273 ) {
* F_240 ( V_7 ) =
* V_273 ;
} else {
V_7 -> V_89 = F_241 () ;
}
V_275 = F_242 ( V_7 ) ;
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
V_275 -> V_276 . V_277 = V_278 ;
V_275 -> V_276 . V_279 = V_280 ;
V_142 = F_235 ( V_112 , V_7 ) ;
if ( V_142 )
F_42 ( V_7 ) ;
}
void F_243 ( struct V_6 * V_7 , bool V_281 )
{
struct V_165 * V_112 = V_7 -> V_112 ;
struct V_274 * V_275 ;
int V_142 ;
V_7 -> V_282 = 1 ;
V_7 -> V_283 = V_281 ;
V_275 = F_242 ( V_7 ) ;
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
V_275 -> V_276 . V_277 = V_278 ;
V_275 -> V_276 . V_279 = V_284 ;
V_142 = F_235 ( V_112 , V_7 ) ;
if ( V_142 )
F_42 ( V_7 ) ;
}
bool F_244 ( struct V_6 * V_7 , T_10 V_157 , T_10 V_60 )
{
if ( F_31 ( V_157 > F_106 ( V_7 ) ) ||
F_31 ( ( int ) V_157 + V_60 > F_106 ( V_7 ) - 2 ) ) {
F_245 ( L_5 ,
V_157 , V_60 , F_106 ( V_7 ) ) ;
return false ;
}
V_7 -> V_100 = V_132 ;
V_7 -> V_133 = F_88 ( V_7 ) + V_157 ;
V_7 -> V_192 = V_60 ;
return true ;
}
void F_246 ( const struct V_6 * V_7 )
{
F_245 ( L_6 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_247 ( struct V_6 * V_7 , bool V_285 )
{
if ( V_285 )
F_25 ( V_27 , V_7 ) ;
else
F_70 ( V_7 ) ;
}
bool F_248 ( struct V_6 * V_156 , struct V_6 * V_187 ,
bool * V_286 , int * V_248 )
{
int V_59 , V_135 , V_11 = V_187 -> V_11 ;
* V_286 = false ;
if ( F_114 ( V_156 ) )
return false ;
if ( V_11 <= F_119 ( V_156 ) ) {
F_110 ( F_104 ( V_187 , 0 , F_103 ( V_156 , V_11 ) , V_11 ) ) ;
* V_248 = 0 ;
return true ;
}
if ( F_52 ( V_156 ) || F_52 ( V_187 ) )
return false ;
if ( F_106 ( V_187 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_51 ;
if ( F_22 ( V_156 ) -> V_70 +
F_22 ( V_187 ) -> V_70 >= V_175 )
return false ;
if ( F_148 ( V_187 ) )
return false ;
V_135 = V_187 -> V_31 - F_13 ( sizeof( struct V_6 ) ) ;
V_5 = F_37 ( V_187 -> V_12 ) ;
V_51 = V_187 -> V_13 - ( unsigned char * ) F_34 ( V_5 ) ;
F_40 ( V_156 , F_22 ( V_156 ) -> V_70 ,
V_5 , V_51 , F_106 ( V_187 ) ) ;
* V_286 = true ;
} else {
if ( F_22 ( V_156 ) -> V_70 +
F_22 ( V_187 ) -> V_70 > V_175 )
return false ;
V_135 = V_187 -> V_31 -
F_18 ( F_249 ( V_187 ) - V_187 -> V_12 ) ;
}
F_250 ( V_135 < V_11 ) ;
memcpy ( F_22 ( V_156 ) -> V_120 + F_22 ( V_156 ) -> V_70 ,
F_22 ( V_187 ) -> V_120 ,
F_22 ( V_187 ) -> V_70 * sizeof( T_5 ) ) ;
F_22 ( V_156 ) -> V_70 += F_22 ( V_187 ) -> V_70 ;
if ( ! F_114 ( V_187 ) )
F_22 ( V_187 ) -> V_70 = 0 ;
for ( V_59 = 0 ; V_59 < F_22 ( V_187 ) -> V_70 ; V_59 ++ )
F_108 ( V_187 , V_59 ) ;
V_156 -> V_31 += V_135 ;
V_156 -> V_11 += V_11 ;
V_156 -> V_61 += V_11 ;
* V_248 = V_135 ;
return true ;
}
