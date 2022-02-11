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
F_7 ( V_10 L_1
L_2 ,
V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_3 ) ;
F_8 () ;
}
static void F_9 ( struct V_6 * V_7 , int V_8 , void * V_9 )
{
F_7 ( V_10 L_4
L_2 ,
V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_3 ) ;
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
struct V_6 * F_26 ( void * V_13 )
{
struct V_24 * V_25 ;
struct V_6 * V_7 ;
unsigned int V_18 ;
V_7 = F_27 ( V_27 , V_42 ) ;
if ( ! V_7 )
return NULL ;
V_18 = F_16 ( V_13 ) - F_13 ( sizeof( struct V_24 ) ) ;
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
return V_7 ;
}
struct V_6 * F_28 ( struct V_43 * V_16 ,
unsigned int V_44 , T_1 V_19 )
{
struct V_6 * V_7 ;
V_7 = F_10 ( V_44 + V_45 , V_19 , 0 , V_46 ) ;
if ( F_29 ( V_7 ) ) {
F_30 ( V_7 , V_45 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_31 ( struct V_6 * V_7 , int V_47 , struct V_5 * V_5 , int V_48 ,
int V_18 , unsigned int V_31 )
{
F_32 ( V_7 , V_47 , V_5 , V_48 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_49 += V_18 ;
V_7 -> V_31 += V_31 ;
}
struct V_6 * F_33 ( unsigned int V_44 )
{
return F_34 ( V_44 , V_42 ) ;
}
static void F_35 ( struct V_6 * * V_50 )
{
struct V_6 * V_51 = * V_50 ;
* V_50 = NULL ;
do {
struct V_6 * V_52 = V_51 ;
V_51 = V_51 -> V_53 ;
F_36 ( V_52 ) ;
} while ( V_51 );
}
static inline void F_37 ( struct V_6 * V_7 )
{
F_35 ( & F_22 ( V_7 ) -> V_54 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_6 * V_51 ;
F_39 (skb, list)
F_40 ( V_51 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_55 ||
! F_42 ( V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ,
& F_22 ( V_7 ) -> V_34 ) ) {
if ( F_22 ( V_7 ) -> V_58 ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_43 ( V_7 , V_47 ) ;
}
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
struct V_61 * V_62 ;
V_62 = F_22 ( V_7 ) -> V_35 ;
if ( V_62 -> V_63 )
V_62 -> V_63 ( V_62 ) ;
}
if ( F_44 ( V_7 ) )
F_37 ( V_7 ) ;
F_45 ( V_7 -> V_12 ) ;
}
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_6 * V_64 ;
T_3 * V_37 ;
switch ( V_7 -> V_20 ) {
case V_41 :
F_25 ( V_27 , V_7 ) ;
break;
case V_40 :
V_37 = ( T_3 * ) ( V_7 + 2 ) ;
if ( F_47 ( V_37 ) )
F_25 ( V_26 , V_7 ) ;
break;
case V_65 :
V_37 = ( T_3 * ) ( V_7 + 1 ) ;
V_64 = V_7 - 1 ;
V_7 -> V_20 = V_41 ;
if ( F_47 ( V_37 ) )
F_25 ( V_26 , V_64 ) ;
break;
}
}
static void F_48 ( struct V_6 * V_7 )
{
F_49 ( V_7 ) ;
#ifdef F_50
F_51 ( V_7 -> V_66 ) ;
#endif
if ( V_7 -> V_67 ) {
F_52 ( F_53 () ) ;
V_7 -> V_67 ( V_7 ) ;
}
#if F_54 ( V_68 )
F_55 ( V_7 -> V_69 ) ;
#endif
#ifdef F_56
F_57 ( V_7 -> V_70 ) ;
#endif
#ifdef F_58
F_59 ( V_7 -> V_71 ) ;
#endif
#ifdef F_60
V_7 -> V_72 = 0 ;
#ifdef F_61
V_7 -> V_73 = 0 ;
#endif
#endif
}
static void F_62 ( struct V_6 * V_7 )
{
F_48 ( V_7 ) ;
F_41 ( V_7 ) ;
}
void F_63 ( struct V_6 * V_7 )
{
F_62 ( V_7 ) ;
F_46 ( V_7 ) ;
}
void F_36 ( struct V_6 * V_7 )
{
if ( F_64 ( ! V_7 ) )
return;
if ( F_29 ( F_65 ( & V_7 -> V_32 ) == 1 ) )
F_66 () ;
else if ( F_29 ( ! F_47 ( & V_7 -> V_32 ) ) )
return;
F_67 ( V_7 , F_68 ( 0 ) ) ;
F_63 ( V_7 ) ;
}
void F_69 ( struct V_6 * V_7 )
{
if ( F_64 ( ! V_7 ) )
return;
if ( F_29 ( F_65 ( & V_7 -> V_32 ) == 1 ) )
F_66 () ;
else if ( F_29 ( ! F_47 ( & V_7 -> V_32 ) ) )
return;
F_70 ( V_7 ) ;
F_63 ( V_7 ) ;
}
void F_71 ( struct V_6 * V_7 )
{
struct V_24 * V_25 ;
F_48 ( V_7 ) ;
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_13 = V_7 -> V_12 + V_45 ;
F_20 ( V_7 ) ;
}
bool F_72 ( struct V_6 * V_7 , int V_74 )
{
if ( ! F_73 ( V_7 , V_74 ) )
return false ;
F_71 ( V_7 ) ;
return true ;
}
static void F_74 ( struct V_6 * V_75 , const struct V_6 * V_76 )
{
V_75 -> V_77 = V_76 -> V_77 ;
V_75 -> V_16 = V_76 -> V_16 ;
V_75 -> V_78 = V_76 -> V_78 ;
V_75 -> V_79 = V_76 -> V_79 ;
V_75 -> V_33 = V_76 -> V_33 ;
F_75 ( V_75 , V_76 ) ;
V_75 -> V_80 = V_76 -> V_80 ;
V_75 -> V_81 = V_76 -> V_81 ;
V_75 -> V_82 = V_76 -> V_82 ;
V_75 -> V_83 = V_76 -> V_83 ;
#ifdef F_50
V_75 -> V_66 = F_76 ( V_76 -> V_66 ) ;
#endif
memcpy ( V_75 -> V_84 , V_76 -> V_84 , sizeof( V_76 -> V_84 ) ) ;
V_75 -> V_85 = V_76 -> V_85 ;
V_75 -> V_86 = V_76 -> V_86 ;
V_75 -> V_87 = V_76 -> V_87 ;
V_75 -> V_88 = V_76 -> V_88 ;
F_77 ( V_75 , V_76 ) ;
V_75 -> V_89 = V_76 -> V_89 ;
#if F_54 ( V_90 )
V_75 -> V_91 = V_76 -> V_91 ;
#endif
V_75 -> V_92 = V_76 -> V_92 ;
V_75 -> V_93 = V_76 -> V_93 ;
V_75 -> V_94 = V_76 -> V_94 ;
F_78 ( V_75 , V_76 ) ;
#if F_54 ( V_95 )
V_75 -> V_96 = V_76 -> V_96 ;
#endif
#ifdef F_60
V_75 -> V_72 = V_76 -> V_72 ;
#ifdef F_61
V_75 -> V_73 = V_76 -> V_73 ;
#endif
#endif
V_75 -> V_97 = V_76 -> V_97 ;
F_79 ( V_75 , V_76 ) ;
}
static struct V_6 * F_80 ( struct V_6 * V_98 , struct V_6 * V_7 )
{
#define F_81 ( T_4 ) n->x = skb->x
V_98 -> V_53 = V_98 -> V_99 = NULL ;
V_98 -> V_100 = NULL ;
F_74 ( V_98 , V_7 ) ;
F_81 ( V_11 ) ;
F_81 ( V_49 ) ;
F_81 ( V_101 ) ;
V_98 -> V_102 = V_7 -> V_56 ? F_82 ( V_7 ) : V_7 -> V_102 ;
V_98 -> V_55 = 1 ;
V_98 -> V_56 = 0 ;
V_98 -> V_67 = NULL ;
F_81 ( V_14 ) ;
F_81 ( V_15 ) ;
F_81 ( V_12 ) ;
F_81 ( V_13 ) ;
F_81 ( V_31 ) ;
F_19 ( & V_98 -> V_32 , 1 ) ;
F_83 ( & ( F_22 ( V_7 ) -> V_34 ) ) ;
V_7 -> V_55 = 1 ;
return V_98 ;
#undef F_81
}
struct V_6 * F_84 ( struct V_6 * V_103 , struct V_6 * V_104 )
{
F_62 ( V_103 ) ;
return F_80 ( V_103 , V_104 ) ;
}
int F_85 ( struct V_6 * V_7 , T_1 V_19 )
{
int V_47 ;
int V_105 = F_22 ( V_7 ) -> V_58 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_61 * V_62 = F_22 ( V_7 ) -> V_35 ;
for ( V_47 = 0 ; V_47 < V_105 ; V_47 ++ ) {
T_2 * V_106 ;
T_5 * V_107 = & F_22 ( V_7 ) -> V_108 [ V_47 ] ;
V_5 = F_86 ( V_42 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_53 = (struct V_5 * ) V_12 -> V_109 ;
F_2 ( V_12 ) ;
V_12 = V_53 ;
}
return - V_110 ;
}
V_106 = F_87 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
memcpy ( F_88 ( V_5 ) ,
V_106 + V_107 -> V_111 , F_89 ( V_107 ) ) ;
F_90 ( V_106 ) ;
V_5 -> V_109 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_43 ( V_7 , V_47 ) ;
V_62 -> V_63 ( V_62 ) ;
for ( V_47 = F_22 ( V_7 ) -> V_58 ; V_47 > 0 ; V_47 -- ) {
F_91 ( V_7 , V_47 - 1 , V_12 , 0 ,
F_22 ( V_7 ) -> V_108 [ V_47 - 1 ] . V_18 ) ;
V_12 = (struct V_5 * ) V_12 -> V_109 ;
}
F_22 ( V_7 ) -> V_59 &= ~ V_60 ;
return 0 ;
}
struct V_6 * F_92 ( struct V_6 * V_7 , T_1 V_19 )
{
struct V_6 * V_98 ;
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_85 ( V_7 , V_19 ) )
return NULL ;
}
V_98 = V_7 + 1 ;
if ( V_7 -> V_20 == V_40 &&
V_98 -> V_20 == V_41 ) {
T_3 * V_37 = ( T_3 * ) ( V_98 + 1 ) ;
V_98 -> V_20 = V_65 ;
F_83 ( V_37 ) ;
} else {
V_98 = F_27 ( V_27 , V_19 ) ;
if ( ! V_98 )
return NULL ;
F_24 ( V_98 , V_38 ) ;
F_24 ( V_98 , V_39 ) ;
V_98 -> V_20 = V_41 ;
}
return F_80 ( V_98 , V_7 ) ;
}
static void F_93 ( struct V_6 * V_75 , const struct V_6 * V_76 )
{
#ifndef F_21
unsigned long V_112 = V_75 -> V_13 - V_76 -> V_13 ;
#endif
F_74 ( V_75 , V_76 ) ;
#ifndef F_21
V_75 -> V_78 += V_112 ;
V_75 -> V_79 += V_112 ;
if ( F_94 ( V_75 ) )
V_75 -> V_33 += V_112 ;
#endif
F_22 ( V_75 ) -> V_113 = F_22 ( V_76 ) -> V_113 ;
F_22 ( V_75 ) -> V_114 = F_22 ( V_76 ) -> V_114 ;
F_22 ( V_75 ) -> V_115 = F_22 ( V_76 ) -> V_115 ;
}
struct V_6 * F_95 ( const struct V_6 * V_7 , T_1 V_19 )
{
int V_116 = F_82 ( V_7 ) ;
unsigned int V_18 = ( F_96 ( V_7 ) - V_7 -> V_12 ) + V_7 -> V_49 ;
struct V_6 * V_98 = F_97 ( V_18 , V_19 ) ;
if ( ! V_98 )
return NULL ;
F_30 ( V_98 , V_116 ) ;
F_98 ( V_98 , V_7 -> V_11 ) ;
if ( F_99 ( V_7 , - V_116 , V_98 -> V_12 , V_116 + V_7 -> V_11 ) )
F_8 () ;
F_93 ( V_98 , V_7 ) ;
return V_98 ;
}
struct V_6 * F_100 ( struct V_6 * V_7 , int V_117 , T_1 V_19 )
{
unsigned int V_18 = F_101 ( V_7 ) + V_117 ;
struct V_6 * V_98 = F_97 ( V_18 , V_19 ) ;
if ( ! V_98 )
goto V_29;
F_30 ( V_98 , V_117 ) ;
F_98 ( V_98 , F_101 ( V_7 ) ) ;
F_102 ( V_7 , V_98 -> V_13 , V_98 -> V_11 ) ;
V_98 -> V_31 += V_7 -> V_49 ;
V_98 -> V_49 = V_7 -> V_49 ;
V_98 -> V_11 = V_7 -> V_11 ;
if ( F_22 ( V_7 ) -> V_58 ) {
int V_47 ;
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_85 ( V_7 , V_19 ) ) {
F_36 ( V_98 ) ;
V_98 = NULL ;
goto V_29;
}
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
F_22 ( V_98 ) -> V_108 [ V_47 ] = F_22 ( V_7 ) -> V_108 [ V_47 ] ;
F_103 ( V_7 , V_47 ) ;
}
F_22 ( V_98 ) -> V_58 = V_47 ;
}
if ( F_44 ( V_7 ) ) {
F_22 ( V_98 ) -> V_54 = F_22 ( V_7 ) -> V_54 ;
F_38 ( V_98 ) ;
}
F_93 ( V_98 , V_7 ) ;
V_29:
return V_98 ;
}
int F_104 ( struct V_6 * V_7 , int V_118 , int V_119 ,
T_1 V_19 )
{
int V_47 ;
T_2 * V_13 ;
int V_18 = V_118 + ( F_96 ( V_7 ) - V_7 -> V_12 ) + V_119 ;
long V_48 ;
bool V_120 ;
F_105 ( V_118 < 0 ) ;
if ( F_106 ( V_7 ) )
F_8 () ;
V_18 = F_13 ( V_18 ) ;
if ( ! V_7 -> V_55 )
V_120 = true ;
else {
int V_121 = V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ;
V_120 = F_65 ( & F_22 ( V_7 ) -> V_34 ) == V_121 ;
}
if ( V_120 &&
V_18 + sizeof( struct V_24 ) <= F_16 ( V_7 -> V_12 ) ) {
memmove ( V_7 -> V_12 + V_18 , F_22 ( V_7 ) ,
F_17 ( struct V_24 ,
V_108 [ F_22 ( V_7 ) -> V_58 ] ) ) ;
memmove ( V_7 -> V_12 + V_118 , V_7 -> V_12 ,
F_107 ( V_7 ) - V_7 -> V_12 ) ;
V_48 = V_118 ;
goto V_122;
}
V_13 = F_108 ( V_18 + F_13 ( sizeof( struct V_24 ) ) ,
V_19 ) ;
if ( ! V_13 )
goto V_30;
V_18 = F_15 ( F_16 ( V_13 ) ) ;
memcpy ( V_13 + V_118 , V_7 -> V_12 , F_107 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_24 * ) ( V_13 + V_18 ) ,
F_22 ( V_7 ) ,
F_17 ( struct V_24 , V_108 [ F_22 ( V_7 ) -> V_58 ] ) ) ;
if ( V_120 ) {
F_45 ( V_7 -> V_12 ) ;
} else {
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_85 ( V_7 , V_19 ) )
goto V_123;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_103 ( V_7 , V_47 ) ;
if ( F_44 ( V_7 ) )
F_38 ( V_7 ) ;
F_41 ( V_7 ) ;
}
V_48 = ( V_13 + V_118 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_122:
V_7 -> V_13 += V_48 ;
#ifdef F_21
V_7 -> V_15 = V_18 ;
V_48 = V_118 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_48 ;
V_7 -> V_78 += V_48 ;
V_7 -> V_79 += V_48 ;
if ( F_94 ( V_7 ) )
V_7 -> V_33 += V_48 ;
if ( V_7 -> V_88 == V_124 )
V_7 -> V_125 += V_118 ;
V_7 -> V_55 = 0 ;
V_7 -> V_102 = 0 ;
V_7 -> V_56 = 0 ;
F_19 ( & F_22 ( V_7 ) -> V_34 , 1 ) ;
return 0 ;
V_123:
F_45 ( V_13 ) ;
V_30:
return - V_110 ;
}
struct V_6 * F_109 ( struct V_6 * V_7 , unsigned int V_117 )
{
struct V_6 * V_126 ;
int V_121 = V_117 - F_82 ( V_7 ) ;
if ( V_121 <= 0 )
V_126 = F_110 ( V_7 , V_42 ) ;
else {
V_126 = F_92 ( V_7 , V_42 ) ;
if ( V_126 && F_104 ( V_126 , F_13 ( V_121 ) , 0 ,
V_42 ) ) {
F_36 ( V_126 ) ;
V_126 = NULL ;
}
}
return V_126 ;
}
struct V_6 * F_111 ( const struct V_6 * V_7 ,
int V_127 , int V_128 ,
T_1 V_19 )
{
struct V_6 * V_98 = F_97 ( V_127 + V_7 -> V_11 + V_128 ,
V_19 ) ;
int V_129 = F_82 ( V_7 ) ;
int V_130 , V_131 ;
int V_48 ;
if ( ! V_98 )
return NULL ;
F_30 ( V_98 , V_127 ) ;
F_98 ( V_98 , V_7 -> V_11 ) ;
V_130 = V_129 ;
V_131 = 0 ;
if ( V_127 <= V_130 )
V_130 = V_127 ;
else
V_131 = V_127 - V_130 ;
if ( F_99 ( V_7 , - V_130 , V_98 -> V_12 + V_131 ,
V_7 -> V_11 + V_130 ) )
F_8 () ;
F_93 ( V_98 , V_7 ) ;
V_48 = V_127 - V_129 ;
if ( V_98 -> V_88 == V_124 )
V_98 -> V_125 += V_48 ;
#ifdef F_21
V_98 -> V_78 += V_48 ;
V_98 -> V_79 += V_48 ;
if ( F_94 ( V_7 ) )
V_98 -> V_33 += V_48 ;
#endif
return V_98 ;
}
int F_112 ( struct V_6 * V_7 , int V_132 )
{
int V_133 ;
int V_119 ;
if ( ! F_113 ( V_7 ) && F_114 ( V_7 ) >= V_132 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_132 ) ;
return 0 ;
}
V_119 = V_7 -> V_49 + V_132 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_29 ( F_113 ( V_7 ) || V_119 > 0 ) ) {
V_133 = F_104 ( V_7 , 0 , V_119 , V_42 ) ;
if ( F_64 ( V_133 ) )
goto V_134;
}
V_133 = F_115 ( V_7 ) ;
if ( F_64 ( V_133 ) )
goto V_134;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_132 ) ;
return 0 ;
V_134:
F_36 ( V_7 ) ;
return V_133 ;
}
unsigned char * F_98 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_135 = F_107 ( V_7 ) ;
F_116 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_64 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_68 ( 0 ) ) ;
return V_135 ;
}
unsigned char * F_117 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_64 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_68 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_118 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_119 ( V_7 , V_11 ) ;
}
void F_120 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_121 ( V_7 , V_11 ) ;
}
int F_122 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_136 ;
struct V_6 * V_137 ;
int V_112 = F_101 ( V_7 ) ;
int V_138 = F_22 ( V_7 ) -> V_58 ;
int V_47 ;
int V_133 ;
if ( F_113 ( V_7 ) &&
F_64 ( ( V_133 = F_104 ( V_7 , 0 , 0 , V_42 ) ) ) )
return V_133 ;
V_47 = 0 ;
if ( V_112 >= V_11 )
goto V_139;
for (; V_47 < V_138 ; V_47 ++ ) {
int V_15 = V_112 + F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( V_15 < V_11 ) {
V_112 = V_15 ;
continue;
}
F_123 ( & F_22 ( V_7 ) -> V_108 [ V_47 ++ ] , V_11 - V_112 ) ;
V_139:
F_22 ( V_7 ) -> V_58 = V_47 ;
for (; V_47 < V_138 ; V_47 ++ )
F_43 ( V_7 , V_47 ) ;
if ( F_44 ( V_7 ) )
F_37 ( V_7 ) ;
goto V_140;
}
for ( V_136 = & F_22 ( V_7 ) -> V_54 ; ( V_137 = * V_136 ) ;
V_136 = & V_137 -> V_53 ) {
int V_15 = V_112 + V_137 -> V_11 ;
if ( F_106 ( V_137 ) ) {
struct V_6 * V_141 ;
V_141 = F_92 ( V_137 , V_42 ) ;
if ( F_64 ( ! V_141 ) )
return - V_110 ;
V_141 -> V_53 = V_137 -> V_53 ;
F_36 ( V_137 ) ;
V_137 = V_141 ;
* V_136 = V_137 ;
}
if ( V_15 < V_11 ) {
V_112 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_64 ( ( V_133 = F_124 ( V_137 , V_11 - V_112 ) ) ) )
return V_133 ;
if ( V_137 -> V_53 )
F_35 ( & V_137 -> V_53 ) ;
break;
}
V_140:
if ( V_11 > F_101 ( V_7 ) ) {
V_7 -> V_49 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_49 = 0 ;
F_125 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_126 ( struct V_6 * V_7 , int V_121 )
{
int V_47 , V_142 , V_143 = ( V_7 -> V_14 + V_121 ) - V_7 -> V_15 ;
if ( V_143 > 0 || F_113 ( V_7 ) ) {
if ( F_104 ( V_7 , 0 , V_143 > 0 ? V_143 + 128 : 0 ,
V_42 ) )
return NULL ;
}
if ( F_99 ( V_7 , F_101 ( V_7 ) , F_107 ( V_7 ) , V_121 ) )
F_8 () ;
if ( ! F_44 ( V_7 ) )
goto V_144;
V_143 = V_121 ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_18 = F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( V_18 >= V_143 )
goto V_144;
V_143 -= V_18 ;
}
if ( V_143 ) {
struct V_6 * V_51 = F_22 ( V_7 ) -> V_54 ;
struct V_6 * V_145 = NULL ;
struct V_6 * V_146 = NULL ;
do {
F_105 ( ! V_51 ) ;
if ( V_51 -> V_11 <= V_143 ) {
V_143 -= V_51 -> V_11 ;
V_51 = V_51 -> V_53 ;
V_146 = V_51 ;
} else {
if ( F_106 ( V_51 ) ) {
V_145 = F_92 ( V_51 , V_42 ) ;
if ( ! V_145 )
return NULL ;
V_146 = V_51 -> V_53 ;
V_51 = V_145 ;
} else {
V_146 = V_51 ;
}
if ( ! F_127 ( V_51 , V_143 ) ) {
F_36 ( V_145 ) ;
return NULL ;
}
break;
}
} while ( V_143 );
while ( ( V_51 = F_22 ( V_7 ) -> V_54 ) != V_146 ) {
F_22 ( V_7 ) -> V_54 = V_51 -> V_53 ;
F_36 ( V_51 ) ;
}
if ( V_145 ) {
V_145 -> V_53 = V_51 ;
F_22 ( V_7 ) -> V_54 = V_145 ;
}
}
V_144:
V_143 = V_121 ;
V_142 = 0 ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_18 = F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( V_18 <= V_143 ) {
F_43 ( V_7 , V_47 ) ;
V_143 -= V_18 ;
} else {
F_22 ( V_7 ) -> V_108 [ V_142 ] = F_22 ( V_7 ) -> V_108 [ V_47 ] ;
if ( V_143 ) {
F_22 ( V_7 ) -> V_108 [ V_142 ] . V_111 += V_143 ;
F_128 ( & F_22 ( V_7 ) -> V_108 [ V_142 ] , V_143 ) ;
V_143 = 0 ;
}
V_142 ++ ;
}
}
F_22 ( V_7 ) -> V_58 = V_142 ;
V_7 -> V_14 += V_121 ;
V_7 -> V_49 -= V_121 ;
return F_107 ( V_7 ) ;
}
int F_99 ( const struct V_6 * V_7 , int V_112 , void * V_147 , int V_11 )
{
int V_148 = F_101 ( V_7 ) ;
struct V_6 * V_149 ;
int V_47 , V_150 ;
if ( V_112 > ( int ) V_7 -> V_11 - V_11 )
goto V_151;
if ( ( V_150 = V_148 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
F_129 ( V_7 , V_112 , V_147 , V_150 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_147 += V_150 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_2 * V_106 ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_106 = F_87 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
memcpy ( V_147 ,
V_106 + F_22 ( V_7 ) -> V_108 [ V_47 ] . V_111 +
V_112 - V_148 , V_150 ) ;
F_90 ( V_106 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_147 += V_150 ;
}
V_148 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
if ( F_99 ( V_149 , V_112 - V_148 , V_147 , V_150 ) )
goto V_151;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_147 += V_150 ;
}
V_148 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_151:
return - V_152 ;
}
static void F_130 ( struct V_153 * V_154 , unsigned int V_47 )
{
F_2 ( V_154 -> V_155 [ V_47 ] ) ;
}
static inline struct V_5 * F_131 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_112 ,
struct V_6 * V_7 , struct V_156 * V_100 )
{
struct V_5 * V_157 = V_100 -> V_158 ;
unsigned int V_48 ;
if ( ! V_157 ) {
V_159:
V_157 = V_100 -> V_158 = F_132 ( V_100 -> V_160 , 0 ) ;
if ( ! V_157 )
return NULL ;
V_48 = V_100 -> V_161 = 0 ;
} else {
unsigned int V_162 ;
V_48 = V_100 -> V_161 ;
V_162 = V_163 - V_48 ;
if ( V_162 < 64 && V_162 < * V_11 ) {
F_2 ( V_157 ) ;
goto V_159;
}
* V_11 = F_133 (unsigned int, *len, mlen) ;
}
memcpy ( F_88 ( V_157 ) + V_48 , F_88 ( V_5 ) + * V_112 , * V_11 ) ;
V_100 -> V_161 += * V_11 ;
* V_112 = V_48 ;
F_4 ( V_157 ) ;
return V_157 ;
}
static inline int F_134 ( struct V_153 * V_154 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_112 ,
struct V_6 * V_7 , int V_164 ,
struct V_156 * V_100 )
{
if ( F_64 ( V_154 -> V_165 == V_2 -> V_166 ) )
return 1 ;
if ( V_164 ) {
V_5 = F_131 ( V_5 , V_11 , & V_112 , V_7 , V_100 ) ;
if ( ! V_5 )
return 1 ;
} else
F_4 ( V_5 ) ;
V_154 -> V_155 [ V_154 -> V_165 ] = V_5 ;
V_154 -> V_167 [ V_154 -> V_165 ] . V_11 = * V_11 ;
V_154 -> V_167 [ V_154 -> V_165 ] . V_112 = V_112 ;
V_154 -> V_165 ++ ;
return 0 ;
}
static inline void F_135 ( struct V_5 * * V_5 , unsigned int * V_168 ,
unsigned int * V_169 , unsigned int V_48 )
{
unsigned long V_98 ;
* V_168 += V_48 ;
V_98 = * V_168 / V_163 ;
if ( V_98 )
* V_5 = F_136 ( * V_5 , V_98 ) ;
* V_168 = * V_168 % V_163 ;
* V_169 -= V_48 ;
}
static inline int F_137 ( struct V_5 * V_5 , unsigned int V_168 ,
unsigned int V_169 , unsigned int * V_48 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_153 * V_154 , int V_164 ,
struct V_156 * V_100 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return 1 ;
if ( * V_48 >= V_169 ) {
* V_48 -= V_169 ;
return 0 ;
}
if ( * V_48 ) {
F_135 ( & V_5 , & V_168 , & V_169 , * V_48 ) ;
* V_48 = 0 ;
}
do {
unsigned int V_170 = F_138 ( * V_11 , V_169 ) ;
V_170 = F_133 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_134 ( V_154 , V_2 , V_5 , & V_170 , V_168 , V_7 , V_164 , V_100 ) )
return 1 ;
F_135 ( & V_5 , & V_168 , & V_169 , V_170 ) ;
* V_11 -= V_170 ;
} while ( * V_11 && V_169 );
return 0 ;
}
static int F_139 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_112 , unsigned int * V_11 ,
struct V_153 * V_154 , struct V_156 * V_100 )
{
int V_171 ;
if ( F_137 ( F_140 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_163 - 1 ) ,
F_101 ( V_7 ) ,
V_112 , V_11 , V_7 , V_154 , 1 , V_100 , V_2 ) )
return 1 ;
for ( V_171 = 0 ; V_171 < F_22 ( V_7 ) -> V_58 ; V_171 ++ ) {
const T_5 * V_107 = & F_22 ( V_7 ) -> V_108 [ V_171 ] ;
if ( F_137 ( F_141 ( V_107 ) ,
V_107 -> V_111 , F_89 ( V_107 ) ,
V_112 , V_11 , V_7 , V_154 , 0 , V_100 , V_2 ) )
return 1 ;
}
return 0 ;
}
int F_142 ( struct V_6 * V_7 , unsigned int V_112 ,
struct V_1 * V_2 , unsigned int V_172 ,
unsigned int V_173 )
{
struct V_174 V_167 [ V_175 ] ;
struct V_5 * V_155 [ V_175 ] ;
struct V_153 V_154 = {
. V_155 = V_155 ,
. V_167 = V_167 ,
. V_173 = V_173 ,
. V_176 = & V_177 ,
. V_178 = F_130 ,
} ;
struct V_6 * V_149 ;
struct V_156 * V_100 = V_7 -> V_100 ;
int V_179 = 0 ;
if ( F_143 ( V_2 , & V_154 ) )
return - V_110 ;
if ( F_139 ( V_7 , V_2 , & V_112 , & V_172 , & V_154 , V_100 ) )
goto V_140;
else if ( ! V_172 )
goto V_140;
F_39 (skb, frag_iter) {
if ( ! V_172 )
break;
if ( F_139 ( V_149 , V_2 , & V_112 , & V_172 , & V_154 , V_100 ) )
break;
}
V_140:
if ( V_154 . V_165 ) {
F_144 ( V_100 ) ;
V_179 = F_145 ( V_2 , & V_154 ) ;
F_146 ( V_100 ) ;
}
F_147 ( V_2 , & V_154 ) ;
return V_179 ;
}
int F_148 ( struct V_6 * V_7 , int V_112 , const void * V_180 , int V_11 )
{
int V_148 = F_101 ( V_7 ) ;
struct V_6 * V_149 ;
int V_47 , V_150 ;
if ( V_112 > ( int ) V_7 -> V_11 - V_11 )
goto V_151;
if ( ( V_150 = V_148 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
F_149 ( V_7 , V_112 , V_180 , V_150 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_180 += V_150 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
T_5 * V_137 = & F_22 ( V_7 ) -> V_108 [ V_47 ] ;
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_89 ( V_137 ) ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_2 * V_106 ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_106 = F_87 ( V_137 ) ;
memcpy ( V_106 + V_137 -> V_111 + V_112 - V_148 ,
V_180 , V_150 ) ;
F_90 ( V_106 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_180 += V_150 ;
}
V_148 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
if ( F_148 ( V_149 , V_112 - V_148 ,
V_180 , V_150 ) )
goto V_151;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_180 += V_150 ;
}
V_148 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_151:
return - V_152 ;
}
T_6 F_150 ( const struct V_6 * V_7 , int V_112 ,
int V_11 , T_6 V_85 )
{
int V_148 = F_101 ( V_7 ) ;
int V_47 , V_150 = V_148 - V_112 ;
struct V_6 * V_149 ;
int V_181 = 0 ;
if ( V_150 > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_85 = F_151 ( V_7 -> V_13 + V_112 , V_150 , V_85 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_85 ;
V_112 += V_150 ;
V_181 = V_150 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_6 V_182 ;
T_2 * V_106 ;
T_5 * V_137 = & F_22 ( V_7 ) -> V_108 [ V_47 ] ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_106 = F_87 ( V_137 ) ;
V_182 = F_151 ( V_106 + V_137 -> V_111 +
V_112 - V_148 , V_150 , 0 ) ;
F_90 ( V_106 ) ;
V_85 = F_152 ( V_85 , V_182 , V_181 ) ;
if ( ! ( V_11 -= V_150 ) )
return V_85 ;
V_112 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_6 V_182 ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_182 = F_150 ( V_149 , V_112 - V_148 ,
V_150 , 0 ) ;
V_85 = F_152 ( V_85 , V_182 , V_181 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_85 ;
V_112 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_105 ( V_11 ) ;
return V_85 ;
}
T_6 F_153 ( const struct V_6 * V_7 , int V_112 ,
T_2 * V_147 , int V_11 , T_6 V_85 )
{
int V_148 = F_101 ( V_7 ) ;
int V_47 , V_150 = V_148 - V_112 ;
struct V_6 * V_149 ;
int V_181 = 0 ;
if ( V_150 > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_85 = F_154 ( V_7 -> V_13 + V_112 , V_147 ,
V_150 , V_85 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_85 ;
V_112 += V_150 ;
V_147 += V_150 ;
V_181 = V_150 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_6 V_182 ;
T_2 * V_106 ;
T_5 * V_137 = & F_22 ( V_7 ) -> V_108 [ V_47 ] ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_106 = F_87 ( V_137 ) ;
V_182 = F_154 ( V_106 +
V_137 -> V_111 +
V_112 - V_148 , V_147 ,
V_150 , 0 ) ;
F_90 ( V_106 ) ;
V_85 = F_152 ( V_85 , V_182 , V_181 ) ;
if ( ! ( V_11 -= V_150 ) )
return V_85 ;
V_112 += V_150 ;
V_147 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_39 (skb, frag_iter) {
T_6 V_182 ;
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_182 = F_153 ( V_149 ,
V_112 - V_148 ,
V_147 , V_150 , 0 ) ;
V_85 = F_152 ( V_85 , V_182 , V_181 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_85 ;
V_112 += V_150 ;
V_147 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_105 ( V_11 ) ;
return V_85 ;
}
void F_155 ( const struct V_6 * V_7 , T_2 * V_147 )
{
T_6 V_85 ;
long V_183 ;
if ( V_7 -> V_88 == V_124 )
V_183 = F_156 ( V_7 ) ;
else
V_183 = F_101 ( V_7 ) ;
F_105 ( V_183 > F_101 ( V_7 ) ) ;
F_102 ( V_7 , V_147 , V_183 ) ;
V_85 = 0 ;
if ( V_183 != V_7 -> V_11 )
V_85 = F_153 ( V_7 , V_183 , V_147 + V_183 ,
V_7 -> V_11 - V_183 , 0 ) ;
if ( V_7 -> V_88 == V_124 ) {
long V_184 = V_183 + V_7 -> V_185 ;
* ( ( V_186 * ) ( V_147 + V_184 ) ) = F_157 ( V_85 ) ;
}
}
struct V_6 * F_158 ( struct V_187 * V_51 )
{
unsigned long V_173 ;
struct V_6 * V_188 ;
F_159 ( & V_51 -> V_189 , V_173 ) ;
V_188 = F_160 ( V_51 ) ;
F_161 ( & V_51 -> V_189 , V_173 ) ;
return V_188 ;
}
struct V_6 * F_162 ( struct V_187 * V_51 )
{
unsigned long V_173 ;
struct V_6 * V_188 ;
F_159 ( & V_51 -> V_189 , V_173 ) ;
V_188 = F_163 ( V_51 ) ;
F_161 ( & V_51 -> V_189 , V_173 ) ;
return V_188 ;
}
void F_164 ( struct V_187 * V_51 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_158 ( V_51 ) ) != NULL )
F_36 ( V_7 ) ;
}
void F_165 ( struct V_187 * V_51 , struct V_6 * V_190 )
{
unsigned long V_173 ;
F_159 ( & V_51 -> V_189 , V_173 ) ;
F_166 ( V_51 , V_190 ) ;
F_161 ( & V_51 -> V_189 , V_173 ) ;
}
void F_167 ( struct V_187 * V_51 , struct V_6 * V_190 )
{
unsigned long V_173 ;
F_159 ( & V_51 -> V_189 , V_173 ) ;
F_168 ( V_51 , V_190 ) ;
F_161 ( & V_51 -> V_189 , V_173 ) ;
}
void F_169 ( struct V_6 * V_7 , struct V_187 * V_51 )
{
unsigned long V_173 ;
F_159 ( & V_51 -> V_189 , V_173 ) ;
F_170 ( V_7 , V_51 ) ;
F_161 ( & V_51 -> V_189 , V_173 ) ;
}
void F_171 ( struct V_6 * V_76 , struct V_6 * V_190 , struct V_187 * V_51 )
{
unsigned long V_173 ;
F_159 ( & V_51 -> V_189 , V_173 ) ;
F_172 ( V_51 , V_76 , V_190 ) ;
F_161 ( & V_51 -> V_189 , V_173 ) ;
}
void F_173 ( struct V_6 * V_76 , struct V_6 * V_190 , struct V_187 * V_51 )
{
unsigned long V_173 ;
F_159 ( & V_51 -> V_189 , V_173 ) ;
F_174 ( V_190 , V_76 -> V_99 , V_76 , V_51 ) ;
F_161 ( & V_51 -> V_189 , V_173 ) ;
}
static inline void F_175 ( struct V_6 * V_7 ,
struct V_6 * V_191 ,
const T_7 V_11 , const int V_181 )
{
int V_47 ;
F_129 ( V_7 , V_11 , F_98 ( V_191 , V_181 - V_11 ) ,
V_181 - V_11 ) ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_22 ( V_191 ) -> V_108 [ V_47 ] = F_22 ( V_7 ) -> V_108 [ V_47 ] ;
F_22 ( V_191 ) -> V_58 = F_22 ( V_7 ) -> V_58 ;
F_22 ( V_7 ) -> V_58 = 0 ;
V_191 -> V_49 = V_7 -> V_49 ;
V_191 -> V_11 += V_191 -> V_49 ;
V_7 -> V_49 = 0 ;
V_7 -> V_11 = V_11 ;
F_125 ( V_7 , V_11 ) ;
}
static inline void F_176 ( struct V_6 * V_7 ,
struct V_6 * V_191 ,
const T_7 V_11 , int V_181 )
{
int V_47 , V_142 = 0 ;
const int V_138 = F_22 ( V_7 ) -> V_58 ;
F_22 ( V_7 ) -> V_58 = 0 ;
V_191 -> V_11 = V_191 -> V_49 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_49 = V_11 - V_181 ;
for ( V_47 = 0 ; V_47 < V_138 ; V_47 ++ ) {
int V_18 = F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( V_181 + V_18 > V_11 ) {
F_22 ( V_191 ) -> V_108 [ V_142 ] = F_22 ( V_7 ) -> V_108 [ V_47 ] ;
if ( V_181 < V_11 ) {
F_103 ( V_7 , V_47 ) ;
F_22 ( V_191 ) -> V_108 [ 0 ] . V_111 += V_11 - V_181 ;
F_128 ( & F_22 ( V_191 ) -> V_108 [ 0 ] , V_11 - V_181 ) ;
F_123 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] , V_11 - V_181 ) ;
F_22 ( V_7 ) -> V_58 ++ ;
}
V_142 ++ ;
} else
F_22 ( V_7 ) -> V_58 ++ ;
V_181 += V_18 ;
}
F_22 ( V_191 ) -> V_58 = V_142 ;
}
void F_177 ( struct V_6 * V_7 , struct V_6 * V_191 , const T_7 V_11 )
{
int V_181 = F_101 ( V_7 ) ;
if ( V_11 < V_181 )
F_175 ( V_7 , V_191 , V_11 , V_181 ) ;
else
F_176 ( V_7 , V_191 , V_11 , V_181 ) ;
}
static int F_178 ( struct V_6 * V_7 )
{
return F_113 ( V_7 ) && F_104 ( V_7 , 0 , 0 , V_42 ) ;
}
int F_179 ( struct V_6 * V_192 , struct V_6 * V_7 , int V_193 )
{
int V_180 , V_147 , V_194 , V_195 ;
struct V_196 * V_197 , * V_198 ;
F_105 ( V_193 > V_7 -> V_11 ) ;
F_105 ( F_101 ( V_7 ) ) ;
V_195 = V_193 ;
V_180 = 0 ;
V_147 = F_22 ( V_192 ) -> V_58 ;
V_197 = & F_22 ( V_7 ) -> V_108 [ V_180 ] ;
if ( ! V_147 ||
! F_180 ( V_192 , V_147 , F_141 ( V_197 ) ,
V_197 -> V_111 ) ) {
V_194 = - 1 ;
} else {
V_194 = V_147 - 1 ;
V_195 -= F_89 ( V_197 ) ;
if ( V_195 < 0 ) {
if ( F_178 ( V_7 ) ||
F_178 ( V_192 ) )
return 0 ;
V_197 = & F_22 ( V_7 ) -> V_108 [ V_180 ] ;
V_198 = & F_22 ( V_192 ) -> V_108 [ V_194 ] ;
F_181 ( V_198 , V_193 ) ;
F_128 ( V_197 , V_193 ) ;
V_197 -> V_111 += V_193 ;
goto V_199;
}
V_180 ++ ;
}
if ( ( V_193 == V_7 -> V_11 ) &&
( F_22 ( V_7 ) -> V_58 - V_180 ) > ( V_200 - V_147 ) )
return 0 ;
if ( F_178 ( V_7 ) || F_178 ( V_192 ) )
return 0 ;
while ( ( V_195 > 0 ) && ( V_180 < F_22 ( V_7 ) -> V_58 ) ) {
if ( V_147 == V_200 )
return 0 ;
V_197 = & F_22 ( V_7 ) -> V_108 [ V_180 ] ;
V_198 = & F_22 ( V_192 ) -> V_108 [ V_147 ] ;
if ( V_195 >= F_89 ( V_197 ) ) {
* V_198 = * V_197 ;
V_195 -= F_89 ( V_197 ) ;
V_180 ++ ;
V_147 ++ ;
} else {
F_182 ( V_197 ) ;
V_198 -> V_5 = V_197 -> V_5 ;
V_198 -> V_111 = V_197 -> V_111 ;
F_123 ( V_198 , V_195 ) ;
V_197 -> V_111 += V_195 ;
F_128 ( V_197 , V_195 ) ;
V_195 = 0 ;
V_147 ++ ;
break;
}
}
F_22 ( V_192 ) -> V_58 = V_147 ;
if ( V_194 >= 0 ) {
V_197 = & F_22 ( V_7 ) -> V_108 [ 0 ] ;
V_198 = & F_22 ( V_192 ) -> V_108 [ V_194 ] ;
F_181 ( V_198 , F_89 ( V_197 ) ) ;
F_183 ( V_197 ) ;
}
V_147 = 0 ;
while ( V_180 < F_22 ( V_7 ) -> V_58 )
F_22 ( V_7 ) -> V_108 [ V_147 ++ ] = F_22 ( V_7 ) -> V_108 [ V_180 ++ ] ;
F_22 ( V_7 ) -> V_58 = V_147 ;
F_105 ( V_195 > 0 && ! F_22 ( V_7 ) -> V_58 ) ;
V_199:
V_192 -> V_88 = V_124 ;
V_7 -> V_88 = V_124 ;
V_7 -> V_11 -= V_193 ;
V_7 -> V_49 -= V_193 ;
V_7 -> V_31 -= V_193 ;
V_192 -> V_11 += V_193 ;
V_192 -> V_49 += V_193 ;
V_192 -> V_31 += V_193 ;
return V_193 ;
}
void F_184 ( struct V_6 * V_7 , unsigned int V_180 ,
unsigned int V_147 , struct V_201 * V_202 )
{
V_202 -> V_203 = V_180 ;
V_202 -> V_204 = V_147 ;
V_202 -> V_205 = V_202 -> V_206 = V_7 ;
V_202 -> V_207 = V_202 -> V_208 = 0 ;
V_202 -> V_209 = NULL ;
}
unsigned int F_185 ( unsigned int V_210 , const T_2 * * V_13 ,
struct V_201 * V_202 )
{
unsigned int V_211 , V_212 = V_210 + V_202 -> V_203 ;
T_5 * V_137 ;
if ( F_64 ( V_212 >= V_202 -> V_204 ) )
return 0 ;
V_213:
V_211 = F_101 ( V_202 -> V_206 ) + V_202 -> V_208 ;
if ( V_212 < V_211 && ! V_202 -> V_209 ) {
* V_13 = V_202 -> V_206 -> V_13 + ( V_212 - V_202 -> V_208 ) ;
return V_211 - V_212 ;
}
if ( V_202 -> V_207 == 0 && ! V_202 -> V_209 )
V_202 -> V_208 += F_101 ( V_202 -> V_206 ) ;
while ( V_202 -> V_207 < F_22 ( V_202 -> V_206 ) -> V_58 ) {
V_137 = & F_22 ( V_202 -> V_206 ) -> V_108 [ V_202 -> V_207 ] ;
V_211 = F_89 ( V_137 ) + V_202 -> V_208 ;
if ( V_212 < V_211 ) {
if ( ! V_202 -> V_209 )
V_202 -> V_209 = F_87 ( V_137 ) ;
* V_13 = ( T_2 * ) V_202 -> V_209 + V_137 -> V_111 +
( V_212 - V_202 -> V_208 ) ;
return V_211 - V_212 ;
}
if ( V_202 -> V_209 ) {
F_90 ( V_202 -> V_209 ) ;
V_202 -> V_209 = NULL ;
}
V_202 -> V_207 ++ ;
V_202 -> V_208 += F_89 ( V_137 ) ;
}
if ( V_202 -> V_209 ) {
F_90 ( V_202 -> V_209 ) ;
V_202 -> V_209 = NULL ;
}
if ( V_202 -> V_205 == V_202 -> V_206 && F_44 ( V_202 -> V_205 ) ) {
V_202 -> V_206 = F_22 ( V_202 -> V_205 ) -> V_54 ;
V_202 -> V_207 = 0 ;
goto V_213;
} else if ( V_202 -> V_206 -> V_53 ) {
V_202 -> V_206 = V_202 -> V_206 -> V_53 ;
V_202 -> V_207 = 0 ;
goto V_213;
}
return 0 ;
}
void F_186 ( struct V_201 * V_202 )
{
if ( V_202 -> V_209 )
F_90 ( V_202 -> V_209 ) ;
}
static unsigned int F_187 ( unsigned int V_112 , const T_2 * * V_214 ,
struct V_215 * V_216 ,
struct V_217 * V_218 )
{
return F_185 ( V_112 , V_214 , F_188 ( V_218 ) ) ;
}
static void F_189 ( struct V_215 * V_216 , struct V_217 * V_218 )
{
F_186 ( F_188 ( V_218 ) ) ;
}
unsigned int F_190 ( struct V_6 * V_7 , unsigned int V_180 ,
unsigned int V_147 , struct V_215 * V_219 ,
struct V_217 * V_218 )
{
unsigned int V_179 ;
V_219 -> V_220 = F_187 ;
V_219 -> V_221 = F_189 ;
F_184 ( V_7 , V_180 , V_147 , F_188 ( V_218 ) ) ;
V_179 = F_191 ( V_219 , V_218 ) ;
return ( V_179 <= V_147 - V_180 ? V_179 : V_222 ) ;
}
int F_192 ( struct V_156 * V_100 , struct V_6 * V_7 ,
int (* F_193)( void * V_180 , char * V_147 , int V_112 ,
int V_11 , int V_223 , struct V_6 * V_7 ) ,
void * V_180 , int V_44 )
{
int V_224 = 0 ;
T_5 * V_137 = NULL ;
struct V_5 * V_5 = NULL ;
int V_150 , V_225 ;
int V_112 = 0 ;
int V_179 ;
do {
V_224 = F_22 ( V_7 ) -> V_58 ;
if ( V_224 >= V_200 )
return - V_152 ;
V_5 = F_132 ( V_100 -> V_160 , 0 ) ;
if ( V_5 == NULL )
return - V_110 ;
F_32 ( V_7 , V_224 , V_5 , 0 , 0 ) ;
V_7 -> V_31 += V_163 ;
F_194 ( V_163 , & V_100 -> V_226 ) ;
V_224 = F_22 ( V_7 ) -> V_58 ;
V_137 = & F_22 ( V_7 ) -> V_108 [ V_224 - 1 ] ;
V_225 = V_163 - V_137 -> V_111 ;
V_150 = ( V_44 > V_225 ) ? V_225 : V_44 ;
V_179 = F_193 ( V_180 , F_195 ( V_137 ) + F_89 ( V_137 ) ,
V_112 , V_150 , 0 , V_7 ) ;
if ( V_179 < 0 )
return - V_152 ;
F_181 ( V_137 , V_150 ) ;
V_7 -> V_11 += V_150 ;
V_7 -> V_49 += V_150 ;
V_112 += V_150 ;
V_44 -= V_150 ;
} while ( V_44 > 0 );
return 0 ;
}
unsigned char * F_196 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_105 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_105 ( V_7 -> V_11 < V_7 -> V_49 ) ;
F_197 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_198 ( struct V_6 * V_7 , T_8 V_227 )
{
struct V_6 * V_228 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_229 = F_22 ( V_7 ) -> V_54 ;
unsigned int V_230 = F_22 ( V_7 ) -> V_113 ;
unsigned int V_231 = V_7 -> V_13 - F_199 ( V_7 ) ;
unsigned int V_112 = V_231 ;
unsigned int V_117 ;
unsigned int V_11 ;
int V_232 = ! ! ( V_227 & V_233 ) ;
int V_138 = F_22 ( V_7 ) -> V_58 ;
int V_133 = - V_110 ;
int V_47 = 0 ;
int V_181 ;
F_200 ( V_7 , V_231 ) ;
V_117 = F_82 ( V_7 ) ;
V_181 = F_101 ( V_7 ) ;
do {
struct V_6 * V_234 ;
T_5 * V_137 ;
int V_235 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_112 ;
if ( V_11 > V_230 )
V_11 = V_230 ;
V_235 = F_101 ( V_7 ) - V_112 ;
if ( V_235 < 0 )
V_235 = 0 ;
if ( V_235 > V_11 || ! V_232 )
V_235 = V_11 ;
if ( ! V_235 && V_47 >= V_138 ) {
F_105 ( V_229 -> V_11 != V_11 ) ;
V_181 += V_11 ;
V_234 = F_92 ( V_229 , V_42 ) ;
V_229 = V_229 -> V_53 ;
if ( F_64 ( ! V_234 ) )
goto V_133;
V_235 = F_96 ( V_234 ) - V_234 -> V_12 ;
if ( F_201 ( V_234 , V_231 + V_117 ) ) {
F_36 ( V_234 ) ;
goto V_133;
}
V_234 -> V_31 += F_96 ( V_234 ) - V_234 -> V_12 -
V_235 ;
F_48 ( V_234 ) ;
F_200 ( V_234 , V_231 ) ;
} else {
V_234 = F_97 ( V_235 + V_231 + V_117 ,
V_42 ) ;
if ( F_64 ( ! V_234 ) )
goto V_133;
F_30 ( V_234 , V_117 ) ;
F_202 ( V_234 , V_231 ) ;
}
if ( V_228 )
V_14 -> V_53 = V_234 ;
else
V_228 = V_234 ;
V_14 = V_234 ;
F_74 ( V_234 , V_7 ) ;
V_234 -> V_101 = V_7 -> V_101 ;
if ( V_234 -> V_88 == V_124 )
V_234 -> V_125 += F_82 ( V_234 ) - V_117 ;
F_203 ( V_234 ) ;
F_204 ( V_234 , V_7 -> V_101 ) ;
V_234 -> V_78 = ( V_234 -> V_79 +
F_205 ( V_7 ) ) ;
F_102 ( V_7 , V_234 -> V_13 , V_231 ) ;
if ( V_229 != F_22 ( V_7 ) -> V_54 )
continue;
if ( ! V_232 ) {
V_234 -> V_88 = V_236 ;
V_234 -> V_85 = F_153 ( V_7 , V_112 ,
F_98 ( V_234 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_137 = F_22 ( V_234 ) -> V_108 ;
F_129 ( V_7 , V_112 ,
F_98 ( V_234 , V_235 ) , V_235 ) ;
while ( V_181 < V_112 + V_11 && V_47 < V_138 ) {
* V_137 = F_22 ( V_7 ) -> V_108 [ V_47 ] ;
F_182 ( V_137 ) ;
V_18 = F_89 ( V_137 ) ;
if ( V_181 < V_112 ) {
V_137 -> V_111 += V_112 - V_181 ;
F_128 ( V_137 , V_112 - V_181 ) ;
}
F_22 ( V_234 ) -> V_58 ++ ;
if ( V_181 + V_18 <= V_112 + V_11 ) {
V_47 ++ ;
V_181 += V_18 ;
} else {
F_128 ( V_137 , V_181 + V_18 - ( V_112 + V_11 ) ) ;
goto V_237;
}
V_137 ++ ;
}
if ( V_181 < V_112 + V_11 ) {
struct V_6 * V_238 = V_229 ;
F_105 ( V_181 + V_229 -> V_11 != V_112 + V_11 ) ;
V_181 += V_229 -> V_11 ;
V_229 = V_229 -> V_53 ;
if ( V_238 -> V_53 ) {
V_238 = F_92 ( V_238 , V_42 ) ;
if ( ! V_238 )
goto V_133;
} else
F_40 ( V_238 ) ;
F_206 ( V_234 ) ;
F_22 ( V_234 ) -> V_54 = V_238 ;
}
V_237:
V_234 -> V_49 = V_11 - V_235 ;
V_234 -> V_11 += V_234 -> V_49 ;
V_234 -> V_31 += V_234 -> V_49 ;
} while ( ( V_112 += V_11 ) < V_7 -> V_11 );
return V_228 ;
V_133:
while ( ( V_7 = V_228 ) ) {
V_228 = V_7 -> V_53 ;
F_36 ( V_7 ) ;
}
return F_207 ( V_133 ) ;
}
int F_208 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_157 = * V_12 ;
struct V_6 * V_234 ;
struct V_24 * V_239 = F_22 ( V_7 ) ;
struct V_24 * V_240 = F_22 ( V_157 ) ;
unsigned int V_117 ;
unsigned int V_11 = F_209 ( V_7 ) ;
unsigned int V_112 = F_210 ( V_7 ) ;
unsigned int V_241 = F_101 ( V_7 ) ;
if ( V_157 -> V_11 + V_11 >= 65536 )
return - V_242 ;
if ( V_240 -> V_54 )
goto V_194;
else if ( V_241 <= V_112 ) {
T_5 * V_137 ;
T_5 * V_243 ;
int V_47 = V_239 -> V_58 ;
int V_58 = V_240 -> V_58 + V_47 ;
V_112 -= V_241 ;
if ( V_58 > V_200 )
return - V_242 ;
V_240 -> V_58 = V_58 ;
V_239 -> V_58 = 0 ;
V_137 = V_240 -> V_108 + V_58 ;
V_243 = V_239 -> V_108 + V_47 ;
do {
* -- V_137 = * -- V_243 ;
} while ( -- V_47 );
V_137 -> V_111 += V_112 ;
F_128 ( V_137 , V_112 ) ;
V_7 -> V_31 -= V_7 -> V_49 ;
V_7 -> V_11 -= V_7 -> V_49 ;
V_7 -> V_49 = 0 ;
F_211 ( V_7 ) -> free = 1 ;
goto V_140;
} else if ( F_209 ( V_157 ) != V_240 -> V_113 )
return - V_242 ;
V_117 = F_82 ( V_157 ) ;
V_234 = F_97 ( V_117 + F_210 ( V_157 ) , V_42 ) ;
if ( F_64 ( ! V_234 ) )
return - V_110 ;
F_74 ( V_234 , V_157 ) ;
V_234 -> V_101 = V_157 -> V_101 ;
F_30 ( V_234 , V_117 ) ;
F_202 ( V_234 , F_210 ( V_157 ) ) ;
F_212 ( V_234 , F_199 ( V_157 ) - V_157 -> V_13 ) ;
F_204 ( V_234 , F_213 ( V_157 ) ) ;
F_214 ( V_234 , F_215 ( V_157 ) ) ;
F_216 ( V_157 , F_210 ( V_157 ) ) ;
memcpy ( F_199 ( V_234 ) , F_199 ( V_157 ) ,
V_157 -> V_13 - F_199 ( V_157 ) ) ;
* F_211 ( V_234 ) = * F_211 ( V_157 ) ;
F_22 ( V_234 ) -> V_54 = V_157 ;
F_22 ( V_234 ) -> V_113 = V_240 -> V_113 ;
V_240 -> V_113 = 0 ;
F_217 ( V_157 ) ;
V_234 -> V_99 = V_157 ;
V_234 -> V_49 += V_157 -> V_11 ;
V_234 -> V_31 += V_157 -> V_31 ;
V_234 -> V_11 += V_157 -> V_11 ;
* V_12 = V_234 ;
V_234 -> V_53 = V_157 -> V_53 ;
V_157 -> V_53 = NULL ;
V_157 = V_234 ;
V_194:
V_157 -> V_31 += V_7 -> V_31 - V_11 ;
if ( V_112 > V_241 ) {
unsigned int V_143 = V_112 - V_241 ;
V_239 -> V_108 [ 0 ] . V_111 += V_143 ;
F_128 ( & V_239 -> V_108 [ 0 ] , V_143 ) ;
V_7 -> V_49 -= V_143 ;
V_7 -> V_11 -= V_143 ;
V_112 = V_241 ;
}
F_216 ( V_7 , V_112 ) ;
V_157 -> V_99 -> V_53 = V_7 ;
V_157 -> V_99 = V_7 ;
F_217 ( V_7 ) ;
V_140:
F_211 ( V_157 ) -> V_244 ++ ;
V_157 -> V_49 += V_11 ;
V_157 -> V_31 += V_11 ;
V_157 -> V_11 += V_11 ;
F_211 ( V_7 ) -> V_245 = 1 ;
return 0 ;
}
void T_9 F_218 ( void )
{
V_27 = F_219 ( L_5 ,
sizeof( struct V_6 ) ,
0 ,
V_246 | V_247 ,
NULL ) ;
V_26 = F_219 ( L_6 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_3 ) ,
0 ,
V_246 | V_247 ,
NULL ) ;
}
static int
F_220 ( struct V_6 * V_7 , struct V_248 * V_232 , int V_112 , int V_11 )
{
int V_148 = F_101 ( V_7 ) ;
int V_47 , V_150 = V_148 - V_112 ;
struct V_6 * V_149 ;
int V_249 = 0 ;
if ( V_150 > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
F_221 ( V_232 , V_7 -> V_13 + V_112 , V_150 ) ;
V_249 ++ ;
if ( ( V_11 -= V_150 ) == 0 )
return V_249 ;
V_112 += V_150 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_89 ( & F_22 ( V_7 ) -> V_108 [ V_47 ] ) ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_5 * V_137 = & F_22 ( V_7 ) -> V_108 [ V_47 ] ;
if ( V_150 > V_11 )
V_150 = V_11 ;
F_222 ( & V_232 [ V_249 ] , F_141 ( V_137 ) , V_150 ,
V_137 -> V_111 + V_112 - V_148 ) ;
V_249 ++ ;
if ( ! ( V_11 -= V_150 ) )
return V_249 ;
V_112 += V_150 ;
}
V_148 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_249 += F_220 ( V_149 , V_232 + V_249 , V_112 - V_148 ,
V_150 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_249 ;
V_112 += V_150 ;
}
V_148 = V_15 ;
}
F_105 ( V_11 ) ;
return V_249 ;
}
int F_223 ( struct V_6 * V_7 , struct V_248 * V_232 , int V_112 , int V_11 )
{
int V_250 = F_220 ( V_7 , V_232 , V_112 , V_11 ) ;
F_224 ( & V_232 [ V_250 - 1 ] ) ;
return V_250 ;
}
int F_225 ( struct V_6 * V_7 , int V_251 , struct V_6 * * V_252 )
{
int V_253 ;
int V_249 ;
struct V_6 * V_191 , * * V_254 ;
if ( ( F_113 ( V_7 ) || F_22 ( V_7 ) -> V_58 ) &&
F_126 ( V_7 , F_226 ( V_7 ) - F_101 ( V_7 ) ) == NULL )
return - V_110 ;
if ( ! F_44 ( V_7 ) ) {
if ( F_114 ( V_7 ) < V_251 &&
F_104 ( V_7 , 0 , V_251 - F_114 ( V_7 ) + 128 , V_42 ) )
return - V_110 ;
* V_252 = V_7 ;
return 1 ;
}
V_249 = 1 ;
V_254 = & F_22 ( V_7 ) -> V_54 ;
V_253 = 0 ;
while ( ( V_191 = * V_254 ) != NULL ) {
int V_119 = 0 ;
if ( F_106 ( V_191 ) )
V_253 = 1 ;
if ( V_191 -> V_53 == NULL && V_251 ) {
if ( F_22 ( V_191 ) -> V_58 ||
F_44 ( V_191 ) ||
F_114 ( V_191 ) < V_251 )
V_119 = V_251 + 128 ;
}
if ( V_253 ||
F_113 ( V_191 ) ||
V_119 ||
F_22 ( V_191 ) -> V_58 ||
F_44 ( V_191 ) ) {
struct V_6 * V_126 ;
if ( V_119 == 0 )
V_126 = F_95 ( V_191 , V_42 ) ;
else
V_126 = F_111 ( V_191 ,
F_82 ( V_191 ) ,
V_119 ,
V_42 ) ;
if ( F_64 ( V_126 == NULL ) )
return - V_110 ;
if ( V_191 -> V_100 )
F_227 ( V_126 , V_191 -> V_100 ) ;
V_126 -> V_53 = V_191 -> V_53 ;
* V_254 = V_126 ;
F_36 ( V_191 ) ;
V_191 = V_126 ;
}
V_249 ++ ;
* V_252 = V_191 ;
V_254 = & V_191 -> V_53 ;
}
return V_249 ;
}
static void F_228 ( struct V_6 * V_7 )
{
struct V_156 * V_100 = V_7 -> V_100 ;
F_229 ( V_7 -> V_31 , & V_100 -> V_255 ) ;
}
int F_230 ( struct V_156 * V_100 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_65 ( & V_100 -> V_255 ) + V_7 -> V_31 >=
( unsigned ) V_100 -> V_256 )
return - V_110 ;
F_231 ( V_7 ) ;
V_7 -> V_100 = V_100 ;
V_7 -> V_67 = F_228 ;
F_194 ( V_7 -> V_31 , & V_100 -> V_255 ) ;
F_232 ( V_7 ) ;
F_167 ( & V_100 -> V_257 , V_7 ) ;
if ( ! F_233 ( V_100 , V_258 ) )
V_100 -> V_259 ( V_100 , V_11 ) ;
return 0 ;
}
void F_234 ( struct V_6 * V_260 ,
struct V_261 * V_262 )
{
struct V_156 * V_100 = V_260 -> V_100 ;
struct V_263 * V_264 ;
struct V_6 * V_7 ;
int V_133 ;
if ( ! V_100 )
return;
V_7 = F_92 ( V_260 , V_42 ) ;
if ( ! V_7 )
return;
if ( V_262 ) {
* F_235 ( V_7 ) =
* V_262 ;
} else {
V_7 -> V_77 = F_236 () ;
}
V_264 = F_237 ( V_7 ) ;
memset ( V_264 , 0 , sizeof( * V_264 ) ) ;
V_264 -> V_265 . V_266 = V_267 ;
V_264 -> V_265 . V_268 = V_269 ;
V_133 = F_230 ( V_100 , V_7 ) ;
if ( V_133 )
F_36 ( V_7 ) ;
}
void F_238 ( struct V_6 * V_7 , bool V_270 )
{
struct V_156 * V_100 = V_7 -> V_100 ;
struct V_263 * V_264 ;
int V_133 ;
V_7 -> V_271 = 1 ;
V_7 -> V_272 = V_270 ;
V_264 = F_237 ( V_7 ) ;
memset ( V_264 , 0 , sizeof( * V_264 ) ) ;
V_264 -> V_265 . V_266 = V_267 ;
V_264 -> V_265 . V_268 = V_273 ;
V_133 = F_230 ( V_100 , V_7 ) ;
if ( V_133 )
F_36 ( V_7 ) ;
}
bool F_239 ( struct V_6 * V_7 , T_10 V_148 , T_10 V_48 )
{
if ( F_64 ( V_148 > F_101 ( V_7 ) ) ||
F_64 ( ( int ) V_148 + V_48 > F_101 ( V_7 ) - 2 ) ) {
if ( F_240 () )
F_7 ( V_274
L_7 ,
V_148 , V_48 , F_101 ( V_7 ) ) ;
return false ;
}
V_7 -> V_88 = V_124 ;
V_7 -> V_125 = F_82 ( V_7 ) + V_148 ;
V_7 -> V_185 = V_48 ;
return true ;
}
void F_241 ( const struct V_6 * V_7 )
{
if ( F_240 () )
F_242 ( L_8
L_9 , V_7 -> V_16 -> V_17 ) ;
}
