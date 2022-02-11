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
struct V_6 * F_26 ( struct V_42 * V_16 ,
unsigned int V_43 , T_1 V_19 )
{
struct V_6 * V_7 ;
V_7 = F_10 ( V_43 + V_44 , V_19 , 0 , V_45 ) ;
if ( F_27 ( V_7 ) ) {
F_28 ( V_7 , V_44 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_29 ( struct V_6 * V_7 , int V_46 , struct V_5 * V_5 , int V_47 ,
int V_18 )
{
F_30 ( V_7 , V_46 , V_5 , V_47 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_48 += V_18 ;
V_7 -> V_31 += V_18 ;
}
struct V_6 * F_31 ( unsigned int V_43 )
{
return F_32 ( V_43 , V_49 ) ;
}
static void F_33 ( struct V_6 * * V_50 )
{
struct V_6 * V_51 = * V_50 ;
* V_50 = NULL ;
do {
struct V_6 * V_52 = V_51 ;
V_51 = V_51 -> V_53 ;
F_34 ( V_52 ) ;
} while ( V_51 );
}
static inline void F_35 ( struct V_6 * V_7 )
{
F_33 ( & F_22 ( V_7 ) -> V_54 ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_6 * V_51 ;
F_37 (skb, list)
F_38 ( V_51 ) ;
}
static void F_39 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_55 ||
! F_40 ( V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ,
& F_22 ( V_7 ) -> V_34 ) ) {
if ( F_22 ( V_7 ) -> V_58 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ )
F_41 ( V_7 , V_46 ) ;
}
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
struct V_61 * V_62 ;
V_62 = F_22 ( V_7 ) -> V_35 ;
if ( V_62 -> V_63 )
V_62 -> V_63 ( V_62 ) ;
}
if ( F_42 ( V_7 ) )
F_35 ( V_7 ) ;
F_43 ( V_7 -> V_12 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_6 * V_64 ;
T_3 * V_37 ;
switch ( V_7 -> V_20 ) {
case V_41 :
F_25 ( V_27 , V_7 ) ;
break;
case V_40 :
V_37 = ( T_3 * ) ( V_7 + 2 ) ;
if ( F_45 ( V_37 ) )
F_25 ( V_26 , V_7 ) ;
break;
case V_65 :
V_37 = ( T_3 * ) ( V_7 + 1 ) ;
V_64 = V_7 - 1 ;
V_7 -> V_20 = V_41 ;
if ( F_45 ( V_37 ) )
F_25 ( V_26 , V_64 ) ;
break;
}
}
static void F_46 ( struct V_6 * V_7 )
{
F_47 ( V_7 ) ;
#ifdef F_48
F_49 ( V_7 -> V_66 ) ;
#endif
if ( V_7 -> V_67 ) {
F_50 ( F_51 () ) ;
V_7 -> V_67 ( V_7 ) ;
}
#if F_52 ( V_68 ) || F_52 ( V_69 )
F_53 ( V_7 -> V_70 ) ;
#endif
#ifdef F_54
F_55 ( V_7 -> V_71 ) ;
#endif
#ifdef F_56
F_57 ( V_7 -> V_72 ) ;
#endif
#ifdef F_58
V_7 -> V_73 = 0 ;
#ifdef F_59
V_7 -> V_74 = 0 ;
#endif
#endif
}
static void F_60 ( struct V_6 * V_7 )
{
F_46 ( V_7 ) ;
F_39 ( V_7 ) ;
}
void F_61 ( struct V_6 * V_7 )
{
F_60 ( V_7 ) ;
F_44 ( V_7 ) ;
}
void F_34 ( struct V_6 * V_7 )
{
if ( F_62 ( ! V_7 ) )
return;
if ( F_27 ( F_63 ( & V_7 -> V_32 ) == 1 ) )
F_64 () ;
else if ( F_27 ( ! F_45 ( & V_7 -> V_32 ) ) )
return;
F_65 ( V_7 , F_66 ( 0 ) ) ;
F_61 ( V_7 ) ;
}
void F_67 ( struct V_6 * V_7 )
{
if ( F_62 ( ! V_7 ) )
return;
if ( F_27 ( F_63 ( & V_7 -> V_32 ) == 1 ) )
F_64 () ;
else if ( F_27 ( ! F_45 ( & V_7 -> V_32 ) ) )
return;
F_68 ( V_7 ) ;
F_61 ( V_7 ) ;
}
void F_69 ( struct V_6 * V_7 )
{
struct V_24 * V_25 ;
F_46 ( V_7 ) ;
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_13 = V_7 -> V_12 + V_44 ;
F_20 ( V_7 ) ;
}
bool F_70 ( struct V_6 * V_7 , int V_75 )
{
if ( ! F_71 ( V_7 , V_75 ) )
return false ;
F_69 ( V_7 ) ;
return true ;
}
static void F_72 ( struct V_6 * V_76 , const struct V_6 * V_77 )
{
V_76 -> V_78 = V_77 -> V_78 ;
V_76 -> V_16 = V_77 -> V_16 ;
V_76 -> V_79 = V_77 -> V_79 ;
V_76 -> V_80 = V_77 -> V_80 ;
V_76 -> V_33 = V_77 -> V_33 ;
F_73 ( V_76 , V_77 ) ;
V_76 -> V_81 = V_77 -> V_81 ;
V_76 -> V_82 = V_77 -> V_82 ;
V_76 -> V_83 = V_77 -> V_83 ;
#ifdef F_48
V_76 -> V_66 = F_74 ( V_77 -> V_66 ) ;
#endif
memcpy ( V_76 -> V_84 , V_77 -> V_84 , sizeof( V_77 -> V_84 ) ) ;
V_76 -> V_85 = V_77 -> V_85 ;
V_76 -> V_86 = V_77 -> V_86 ;
V_76 -> V_87 = V_77 -> V_87 ;
V_76 -> V_88 = V_77 -> V_88 ;
F_75 ( V_76 , V_77 ) ;
V_76 -> V_89 = V_77 -> V_89 ;
#if F_52 ( V_90 ) || F_52 ( V_91 )
V_76 -> V_92 = V_77 -> V_92 ;
#endif
V_76 -> V_93 = V_77 -> V_93 ;
V_76 -> V_94 = V_77 -> V_94 ;
V_76 -> V_95 = V_77 -> V_95 ;
F_76 ( V_76 , V_77 ) ;
#if F_52 ( V_96 ) || \
F_52 ( V_97 )
V_76 -> V_98 = V_77 -> V_98 ;
#endif
#ifdef F_58
V_76 -> V_73 = V_77 -> V_73 ;
#ifdef F_59
V_76 -> V_74 = V_77 -> V_74 ;
#endif
#endif
V_76 -> V_99 = V_77 -> V_99 ;
F_77 ( V_76 , V_77 ) ;
}
static struct V_6 * F_78 ( struct V_6 * V_100 , struct V_6 * V_7 )
{
#define F_79 ( T_4 ) n->x = skb->x
V_100 -> V_53 = V_100 -> V_101 = NULL ;
V_100 -> V_102 = NULL ;
F_72 ( V_100 , V_7 ) ;
F_79 ( V_11 ) ;
F_79 ( V_48 ) ;
F_79 ( V_103 ) ;
V_100 -> V_104 = V_7 -> V_56 ? F_80 ( V_7 ) : V_7 -> V_104 ;
V_100 -> V_55 = 1 ;
V_100 -> V_56 = 0 ;
V_100 -> V_67 = NULL ;
F_79 ( V_14 ) ;
F_79 ( V_15 ) ;
F_79 ( V_12 ) ;
F_79 ( V_13 ) ;
F_79 ( V_31 ) ;
F_19 ( & V_100 -> V_32 , 1 ) ;
F_81 ( & ( F_22 ( V_7 ) -> V_34 ) ) ;
V_7 -> V_55 = 1 ;
return V_100 ;
#undef F_79
}
struct V_6 * F_82 ( struct V_6 * V_105 , struct V_6 * V_106 )
{
F_60 ( V_105 ) ;
return F_78 ( V_105 , V_106 ) ;
}
int F_83 ( struct V_6 * V_7 , T_1 V_19 )
{
int V_46 ;
int V_107 = F_22 ( V_7 ) -> V_58 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_61 * V_62 = F_22 ( V_7 ) -> V_35 ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ ) {
T_2 * V_108 ;
T_5 * V_109 = & F_22 ( V_7 ) -> V_110 [ V_46 ] ;
V_5 = F_84 ( V_49 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_53 = (struct V_5 * ) V_12 -> V_111 ;
F_2 ( V_12 ) ;
V_12 = V_53 ;
}
return - V_112 ;
}
V_108 = F_85 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
memcpy ( F_86 ( V_5 ) ,
V_108 + V_109 -> V_113 , F_87 ( V_109 ) ) ;
F_88 ( V_108 ) ;
V_5 -> V_111 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ )
F_41 ( V_7 , V_46 ) ;
V_62 -> V_63 ( V_62 ) ;
for ( V_46 = F_22 ( V_7 ) -> V_58 ; V_46 > 0 ; V_46 -- ) {
F_89 ( V_7 , V_46 - 1 , V_12 , 0 ,
F_22 ( V_7 ) -> V_110 [ V_46 - 1 ] . V_18 ) ;
V_12 = (struct V_5 * ) V_12 -> V_111 ;
}
F_22 ( V_7 ) -> V_59 &= ~ V_60 ;
return 0 ;
}
struct V_6 * F_90 ( struct V_6 * V_7 , T_1 V_19 )
{
struct V_6 * V_100 ;
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_83 ( V_7 , V_19 ) )
return NULL ;
}
V_100 = V_7 + 1 ;
if ( V_7 -> V_20 == V_40 &&
V_100 -> V_20 == V_41 ) {
T_3 * V_37 = ( T_3 * ) ( V_100 + 1 ) ;
V_100 -> V_20 = V_65 ;
F_81 ( V_37 ) ;
} else {
V_100 = F_91 ( V_27 , V_19 ) ;
if ( ! V_100 )
return NULL ;
F_24 ( V_100 , V_38 ) ;
F_24 ( V_100 , V_39 ) ;
V_100 -> V_20 = V_41 ;
}
return F_78 ( V_100 , V_7 ) ;
}
static void F_92 ( struct V_6 * V_76 , const struct V_6 * V_77 )
{
#ifndef F_21
unsigned long V_114 = V_76 -> V_13 - V_77 -> V_13 ;
#endif
F_72 ( V_76 , V_77 ) ;
#ifndef F_21
V_76 -> V_79 += V_114 ;
V_76 -> V_80 += V_114 ;
if ( F_93 ( V_76 ) )
V_76 -> V_33 += V_114 ;
#endif
F_22 ( V_76 ) -> V_115 = F_22 ( V_77 ) -> V_115 ;
F_22 ( V_76 ) -> V_116 = F_22 ( V_77 ) -> V_116 ;
F_22 ( V_76 ) -> V_117 = F_22 ( V_77 ) -> V_117 ;
}
struct V_6 * F_94 ( const struct V_6 * V_7 , T_1 V_19 )
{
int V_118 = F_80 ( V_7 ) ;
unsigned int V_18 = ( F_95 ( V_7 ) - V_7 -> V_12 ) + V_7 -> V_48 ;
struct V_6 * V_100 = F_96 ( V_18 , V_19 ) ;
if ( ! V_100 )
return NULL ;
F_28 ( V_100 , V_118 ) ;
F_97 ( V_100 , V_7 -> V_11 ) ;
if ( F_98 ( V_7 , - V_118 , V_100 -> V_12 , V_118 + V_7 -> V_11 ) )
F_8 () ;
F_92 ( V_100 , V_7 ) ;
return V_100 ;
}
struct V_6 * F_99 ( struct V_6 * V_7 , T_1 V_19 )
{
unsigned int V_18 = F_95 ( V_7 ) - V_7 -> V_12 ;
struct V_6 * V_100 = F_96 ( V_18 , V_19 ) ;
if ( ! V_100 )
goto V_29;
F_28 ( V_100 , F_80 ( V_7 ) ) ;
F_97 ( V_100 , F_100 ( V_7 ) ) ;
F_101 ( V_7 , V_100 -> V_13 , V_100 -> V_11 ) ;
V_100 -> V_31 += V_7 -> V_48 ;
V_100 -> V_48 = V_7 -> V_48 ;
V_100 -> V_11 = V_7 -> V_11 ;
if ( F_22 ( V_7 ) -> V_58 ) {
int V_46 ;
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_83 ( V_7 , V_19 ) ) {
F_34 ( V_100 ) ;
V_100 = NULL ;
goto V_29;
}
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
F_22 ( V_100 ) -> V_110 [ V_46 ] = F_22 ( V_7 ) -> V_110 [ V_46 ] ;
F_102 ( V_7 , V_46 ) ;
}
F_22 ( V_100 ) -> V_58 = V_46 ;
}
if ( F_42 ( V_7 ) ) {
F_22 ( V_100 ) -> V_54 = F_22 ( V_7 ) -> V_54 ;
F_36 ( V_100 ) ;
}
F_92 ( V_100 , V_7 ) ;
V_29:
return V_100 ;
}
int F_103 ( struct V_6 * V_7 , int V_119 , int V_120 ,
T_1 V_19 )
{
int V_46 ;
T_2 * V_13 ;
int V_18 = V_119 + ( F_95 ( V_7 ) - V_7 -> V_12 ) + V_120 ;
long V_47 ;
bool V_121 ;
F_104 ( V_119 < 0 ) ;
if ( F_105 ( V_7 ) )
F_8 () ;
V_18 = F_13 ( V_18 ) ;
if ( ! V_7 -> V_55 )
V_121 = true ;
else {
int V_122 = V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ;
V_121 = F_63 ( & F_22 ( V_7 ) -> V_34 ) == V_122 ;
}
if ( V_121 &&
V_18 + sizeof( struct V_24 ) <= F_16 ( V_7 -> V_12 ) ) {
memmove ( V_7 -> V_12 + V_18 , F_22 ( V_7 ) ,
F_17 ( struct V_24 ,
V_110 [ F_22 ( V_7 ) -> V_58 ] ) ) ;
memmove ( V_7 -> V_12 + V_119 , V_7 -> V_12 ,
F_106 ( V_7 ) - V_7 -> V_12 ) ;
V_47 = V_119 ;
goto V_123;
}
V_13 = F_107 ( V_18 + sizeof( struct V_24 ) , V_19 ) ;
if ( ! V_13 )
goto V_30;
memcpy ( V_13 + V_119 , V_7 -> V_12 , F_106 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_24 * ) ( V_13 + V_18 ) ,
F_22 ( V_7 ) ,
F_17 ( struct V_24 , V_110 [ F_22 ( V_7 ) -> V_58 ] ) ) ;
if ( V_121 ) {
F_43 ( V_7 -> V_12 ) ;
} else {
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_83 ( V_7 , V_19 ) )
goto V_124;
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ )
F_102 ( V_7 , V_46 ) ;
if ( F_42 ( V_7 ) )
F_36 ( V_7 ) ;
F_39 ( V_7 ) ;
}
V_47 = ( V_13 + V_119 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_123:
V_7 -> V_13 += V_47 ;
#ifdef F_21
V_7 -> V_15 = V_18 ;
V_47 = V_119 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_47 ;
V_7 -> V_79 += V_47 ;
V_7 -> V_80 += V_47 ;
if ( F_93 ( V_7 ) )
V_7 -> V_33 += V_47 ;
if ( V_7 -> V_88 == V_125 )
V_7 -> V_126 += V_119 ;
V_7 -> V_55 = 0 ;
V_7 -> V_104 = 0 ;
V_7 -> V_56 = 0 ;
F_19 ( & F_22 ( V_7 ) -> V_34 , 1 ) ;
return 0 ;
V_124:
F_43 ( V_13 ) ;
V_30:
return - V_112 ;
}
struct V_6 * F_108 ( struct V_6 * V_7 , unsigned int V_127 )
{
struct V_6 * V_128 ;
int V_122 = V_127 - F_80 ( V_7 ) ;
if ( V_122 <= 0 )
V_128 = F_99 ( V_7 , V_49 ) ;
else {
V_128 = F_90 ( V_7 , V_49 ) ;
if ( V_128 && F_103 ( V_128 , F_13 ( V_122 ) , 0 ,
V_49 ) ) {
F_34 ( V_128 ) ;
V_128 = NULL ;
}
}
return V_128 ;
}
struct V_6 * F_109 ( const struct V_6 * V_7 ,
int V_129 , int V_130 ,
T_1 V_19 )
{
struct V_6 * V_100 = F_96 ( V_129 + V_7 -> V_11 + V_130 ,
V_19 ) ;
int V_131 = F_80 ( V_7 ) ;
int V_132 , V_133 ;
int V_47 ;
if ( ! V_100 )
return NULL ;
F_28 ( V_100 , V_129 ) ;
F_97 ( V_100 , V_7 -> V_11 ) ;
V_132 = V_131 ;
V_133 = 0 ;
if ( V_129 <= V_132 )
V_132 = V_129 ;
else
V_133 = V_129 - V_132 ;
if ( F_98 ( V_7 , - V_132 , V_100 -> V_12 + V_133 ,
V_7 -> V_11 + V_132 ) )
F_8 () ;
F_92 ( V_100 , V_7 ) ;
V_47 = V_129 - V_131 ;
if ( V_100 -> V_88 == V_125 )
V_100 -> V_126 += V_47 ;
#ifdef F_21
V_100 -> V_79 += V_47 ;
V_100 -> V_80 += V_47 ;
if ( F_93 ( V_7 ) )
V_100 -> V_33 += V_47 ;
#endif
return V_100 ;
}
int F_110 ( struct V_6 * V_7 , int V_134 )
{
int V_135 ;
int V_120 ;
if ( ! F_111 ( V_7 ) && F_112 ( V_7 ) >= V_134 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_134 ) ;
return 0 ;
}
V_120 = V_7 -> V_48 + V_134 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_27 ( F_111 ( V_7 ) || V_120 > 0 ) ) {
V_135 = F_103 ( V_7 , 0 , V_120 , V_49 ) ;
if ( F_62 ( V_135 ) )
goto V_136;
}
V_135 = F_113 ( V_7 ) ;
if ( F_62 ( V_135 ) )
goto V_136;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_134 ) ;
return 0 ;
V_136:
F_34 ( V_7 ) ;
return V_135 ;
}
unsigned char * F_97 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_137 = F_106 ( V_7 ) ;
F_114 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_62 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_66 ( 0 ) ) ;
return V_137 ;
}
unsigned char * F_115 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_62 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_66 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_116 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_117 ( V_7 , V_11 ) ;
}
void F_118 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_119 ( V_7 , V_11 ) ;
}
int F_120 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_138 ;
struct V_6 * V_139 ;
int V_114 = F_100 ( V_7 ) ;
int V_140 = F_22 ( V_7 ) -> V_58 ;
int V_46 ;
int V_135 ;
if ( F_111 ( V_7 ) &&
F_62 ( ( V_135 = F_103 ( V_7 , 0 , 0 , V_49 ) ) ) )
return V_135 ;
V_46 = 0 ;
if ( V_114 >= V_11 )
goto V_141;
for (; V_46 < V_140 ; V_46 ++ ) {
int V_15 = V_114 + F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( V_15 < V_11 ) {
V_114 = V_15 ;
continue;
}
F_121 ( & F_22 ( V_7 ) -> V_110 [ V_46 ++ ] , V_11 - V_114 ) ;
V_141:
F_22 ( V_7 ) -> V_58 = V_46 ;
for (; V_46 < V_140 ; V_46 ++ )
F_41 ( V_7 , V_46 ) ;
if ( F_42 ( V_7 ) )
F_35 ( V_7 ) ;
goto V_142;
}
for ( V_138 = & F_22 ( V_7 ) -> V_54 ; ( V_139 = * V_138 ) ;
V_138 = & V_139 -> V_53 ) {
int V_15 = V_114 + V_139 -> V_11 ;
if ( F_105 ( V_139 ) ) {
struct V_6 * V_143 ;
V_143 = F_90 ( V_139 , V_49 ) ;
if ( F_62 ( ! V_143 ) )
return - V_112 ;
V_143 -> V_53 = V_139 -> V_53 ;
F_34 ( V_139 ) ;
V_139 = V_143 ;
* V_138 = V_139 ;
}
if ( V_15 < V_11 ) {
V_114 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_62 ( ( V_135 = F_122 ( V_139 , V_11 - V_114 ) ) ) )
return V_135 ;
if ( V_139 -> V_53 )
F_33 ( & V_139 -> V_53 ) ;
break;
}
V_142:
if ( V_11 > F_100 ( V_7 ) ) {
V_7 -> V_48 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_48 = 0 ;
F_123 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_124 ( struct V_6 * V_7 , int V_122 )
{
int V_46 , V_144 , V_145 = ( V_7 -> V_14 + V_122 ) - V_7 -> V_15 ;
if ( V_145 > 0 || F_111 ( V_7 ) ) {
if ( F_103 ( V_7 , 0 , V_145 > 0 ? V_145 + 128 : 0 ,
V_49 ) )
return NULL ;
}
if ( F_98 ( V_7 , F_100 ( V_7 ) , F_106 ( V_7 ) , V_122 ) )
F_8 () ;
if ( ! F_42 ( V_7 ) )
goto V_146;
V_145 = V_122 ;
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_18 = F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( V_18 >= V_145 )
goto V_146;
V_145 -= V_18 ;
}
if ( V_145 ) {
struct V_6 * V_51 = F_22 ( V_7 ) -> V_54 ;
struct V_6 * V_147 = NULL ;
struct V_6 * V_148 = NULL ;
do {
F_104 ( ! V_51 ) ;
if ( V_51 -> V_11 <= V_145 ) {
V_145 -= V_51 -> V_11 ;
V_51 = V_51 -> V_53 ;
V_148 = V_51 ;
} else {
if ( F_105 ( V_51 ) ) {
V_147 = F_90 ( V_51 , V_49 ) ;
if ( ! V_147 )
return NULL ;
V_148 = V_51 -> V_53 ;
V_51 = V_147 ;
} else {
V_148 = V_51 ;
}
if ( ! F_125 ( V_51 , V_145 ) ) {
F_34 ( V_147 ) ;
return NULL ;
}
break;
}
} while ( V_145 );
while ( ( V_51 = F_22 ( V_7 ) -> V_54 ) != V_148 ) {
F_22 ( V_7 ) -> V_54 = V_51 -> V_53 ;
F_34 ( V_51 ) ;
}
if ( V_147 ) {
V_147 -> V_53 = V_51 ;
F_22 ( V_7 ) -> V_54 = V_147 ;
}
}
V_146:
V_145 = V_122 ;
V_144 = 0 ;
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_18 = F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( V_18 <= V_145 ) {
F_41 ( V_7 , V_46 ) ;
V_145 -= V_18 ;
} else {
F_22 ( V_7 ) -> V_110 [ V_144 ] = F_22 ( V_7 ) -> V_110 [ V_46 ] ;
if ( V_145 ) {
F_22 ( V_7 ) -> V_110 [ V_144 ] . V_113 += V_145 ;
F_126 ( & F_22 ( V_7 ) -> V_110 [ V_144 ] , V_145 ) ;
V_145 = 0 ;
}
V_144 ++ ;
}
}
F_22 ( V_7 ) -> V_58 = V_144 ;
V_7 -> V_14 += V_122 ;
V_7 -> V_48 -= V_122 ;
return F_106 ( V_7 ) ;
}
int F_98 ( const struct V_6 * V_7 , int V_114 , void * V_149 , int V_11 )
{
int V_150 = F_100 ( V_7 ) ;
struct V_6 * V_151 ;
int V_46 , V_152 ;
if ( V_114 > ( int ) V_7 -> V_11 - V_11 )
goto V_153;
if ( ( V_152 = V_150 - V_114 ) > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
F_127 ( V_7 , V_114 , V_149 , V_152 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return 0 ;
V_114 += V_152 ;
V_149 += V_152 ;
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
T_2 * V_108 ;
if ( V_152 > V_11 )
V_152 = V_11 ;
V_108 = F_85 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
memcpy ( V_149 ,
V_108 + F_22 ( V_7 ) -> V_110 [ V_46 ] . V_113 +
V_114 - V_150 , V_152 ) ;
F_88 ( V_108 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return 0 ;
V_114 += V_152 ;
V_149 += V_152 ;
}
V_150 = V_15 ;
}
F_37 (skb, frag_iter) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + V_151 -> V_11 ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
if ( F_98 ( V_151 , V_114 - V_150 , V_149 , V_152 ) )
goto V_153;
if ( ( V_11 -= V_152 ) == 0 )
return 0 ;
V_114 += V_152 ;
V_149 += V_152 ;
}
V_150 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_153:
return - V_154 ;
}
static void F_128 ( struct V_155 * V_156 , unsigned int V_46 )
{
F_2 ( V_156 -> V_157 [ V_46 ] ) ;
}
static inline struct V_5 * F_129 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_114 ,
struct V_6 * V_7 , struct V_158 * V_102 )
{
struct V_5 * V_159 = V_102 -> V_160 ;
unsigned int V_47 ;
if ( ! V_159 ) {
V_161:
V_159 = V_102 -> V_160 = F_130 ( V_102 -> V_162 , 0 ) ;
if ( ! V_159 )
return NULL ;
V_47 = V_102 -> V_163 = 0 ;
} else {
unsigned int V_164 ;
V_47 = V_102 -> V_163 ;
V_164 = V_165 - V_47 ;
if ( V_164 < 64 && V_164 < * V_11 ) {
F_2 ( V_159 ) ;
goto V_161;
}
* V_11 = F_131 (unsigned int, *len, mlen) ;
}
memcpy ( F_86 ( V_159 ) + V_47 , F_86 ( V_5 ) + * V_114 , * V_11 ) ;
V_102 -> V_163 += * V_11 ;
* V_114 = V_47 ;
F_4 ( V_159 ) ;
return V_159 ;
}
static inline int F_132 ( struct V_155 * V_156 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_114 ,
struct V_6 * V_7 , int V_166 ,
struct V_158 * V_102 )
{
if ( F_62 ( V_156 -> V_167 == V_2 -> V_168 ) )
return 1 ;
if ( V_166 ) {
V_5 = F_129 ( V_5 , V_11 , & V_114 , V_7 , V_102 ) ;
if ( ! V_5 )
return 1 ;
} else
F_4 ( V_5 ) ;
V_156 -> V_157 [ V_156 -> V_167 ] = V_5 ;
V_156 -> V_169 [ V_156 -> V_167 ] . V_11 = * V_11 ;
V_156 -> V_169 [ V_156 -> V_167 ] . V_114 = V_114 ;
V_156 -> V_167 ++ ;
return 0 ;
}
static inline void F_133 ( struct V_5 * * V_5 , unsigned int * V_170 ,
unsigned int * V_171 , unsigned int V_47 )
{
unsigned long V_100 ;
* V_170 += V_47 ;
V_100 = * V_170 / V_165 ;
if ( V_100 )
* V_5 = F_134 ( * V_5 , V_100 ) ;
* V_170 = * V_170 % V_165 ;
* V_171 -= V_47 ;
}
static inline int F_135 ( struct V_5 * V_5 , unsigned int V_170 ,
unsigned int V_171 , unsigned int * V_47 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_155 * V_156 , int V_166 ,
struct V_158 * V_102 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return 1 ;
if ( * V_47 >= V_171 ) {
* V_47 -= V_171 ;
return 0 ;
}
if ( * V_47 ) {
F_133 ( & V_5 , & V_170 , & V_171 , * V_47 ) ;
* V_47 = 0 ;
}
do {
unsigned int V_172 = F_136 ( * V_11 , V_171 ) ;
V_172 = F_131 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_132 ( V_156 , V_2 , V_5 , & V_172 , V_170 , V_7 , V_166 , V_102 ) )
return 1 ;
F_133 ( & V_5 , & V_170 , & V_171 , V_172 ) ;
* V_11 -= V_172 ;
} while ( * V_11 && V_171 );
return 0 ;
}
static int F_137 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_114 , unsigned int * V_11 ,
struct V_155 * V_156 , struct V_158 * V_102 )
{
int V_173 ;
if ( F_135 ( F_138 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_165 - 1 ) ,
F_100 ( V_7 ) ,
V_114 , V_11 , V_7 , V_156 , 1 , V_102 , V_2 ) )
return 1 ;
for ( V_173 = 0 ; V_173 < F_22 ( V_7 ) -> V_58 ; V_173 ++ ) {
const T_5 * V_109 = & F_22 ( V_7 ) -> V_110 [ V_173 ] ;
if ( F_135 ( F_139 ( V_109 ) ,
V_109 -> V_113 , F_87 ( V_109 ) ,
V_114 , V_11 , V_7 , V_156 , 0 , V_102 , V_2 ) )
return 1 ;
}
return 0 ;
}
int F_140 ( struct V_6 * V_7 , unsigned int V_114 ,
struct V_1 * V_2 , unsigned int V_174 ,
unsigned int V_175 )
{
struct V_176 V_169 [ V_177 ] ;
struct V_5 * V_157 [ V_177 ] ;
struct V_155 V_156 = {
. V_157 = V_157 ,
. V_169 = V_169 ,
. V_175 = V_175 ,
. V_178 = & V_179 ,
. V_180 = F_128 ,
} ;
struct V_6 * V_151 ;
struct V_158 * V_102 = V_7 -> V_102 ;
int V_181 = 0 ;
if ( F_141 ( V_2 , & V_156 ) )
return - V_112 ;
if ( F_137 ( V_7 , V_2 , & V_114 , & V_174 , & V_156 , V_102 ) )
goto V_142;
else if ( ! V_174 )
goto V_142;
F_37 (skb, frag_iter) {
if ( ! V_174 )
break;
if ( F_137 ( V_151 , V_2 , & V_114 , & V_174 , & V_156 , V_102 ) )
break;
}
V_142:
if ( V_156 . V_167 ) {
F_142 ( V_102 ) ;
V_181 = F_143 ( V_2 , & V_156 ) ;
F_144 ( V_102 ) ;
}
F_145 ( V_2 , & V_156 ) ;
return V_181 ;
}
int F_146 ( struct V_6 * V_7 , int V_114 , const void * V_182 , int V_11 )
{
int V_150 = F_100 ( V_7 ) ;
struct V_6 * V_151 ;
int V_46 , V_152 ;
if ( V_114 > ( int ) V_7 -> V_11 - V_11 )
goto V_153;
if ( ( V_152 = V_150 - V_114 ) > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
F_147 ( V_7 , V_114 , V_182 , V_152 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return 0 ;
V_114 += V_152 ;
V_182 += V_152 ;
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
T_5 * V_139 = & F_22 ( V_7 ) -> V_110 [ V_46 ] ;
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + F_87 ( V_139 ) ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
T_2 * V_108 ;
if ( V_152 > V_11 )
V_152 = V_11 ;
V_108 = F_85 ( V_139 ) ;
memcpy ( V_108 + V_139 -> V_113 + V_114 - V_150 ,
V_182 , V_152 ) ;
F_88 ( V_108 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return 0 ;
V_114 += V_152 ;
V_182 += V_152 ;
}
V_150 = V_15 ;
}
F_37 (skb, frag_iter) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + V_151 -> V_11 ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
if ( F_146 ( V_151 , V_114 - V_150 ,
V_182 , V_152 ) )
goto V_153;
if ( ( V_11 -= V_152 ) == 0 )
return 0 ;
V_114 += V_152 ;
V_182 += V_152 ;
}
V_150 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_153:
return - V_154 ;
}
T_6 F_148 ( const struct V_6 * V_7 , int V_114 ,
int V_11 , T_6 V_85 )
{
int V_150 = F_100 ( V_7 ) ;
int V_46 , V_152 = V_150 - V_114 ;
struct V_6 * V_151 ;
int V_183 = 0 ;
if ( V_152 > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
V_85 = F_149 ( V_7 -> V_13 + V_114 , V_152 , V_85 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return V_85 ;
V_114 += V_152 ;
V_183 = V_152 ;
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
T_6 V_184 ;
T_2 * V_108 ;
T_5 * V_139 = & F_22 ( V_7 ) -> V_110 [ V_46 ] ;
if ( V_152 > V_11 )
V_152 = V_11 ;
V_108 = F_85 ( V_139 ) ;
V_184 = F_149 ( V_108 + V_139 -> V_113 +
V_114 - V_150 , V_152 , 0 ) ;
F_88 ( V_108 ) ;
V_85 = F_150 ( V_85 , V_184 , V_183 ) ;
if ( ! ( V_11 -= V_152 ) )
return V_85 ;
V_114 += V_152 ;
V_183 += V_152 ;
}
V_150 = V_15 ;
}
F_37 (skb, frag_iter) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + V_151 -> V_11 ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
T_6 V_184 ;
if ( V_152 > V_11 )
V_152 = V_11 ;
V_184 = F_148 ( V_151 , V_114 - V_150 ,
V_152 , 0 ) ;
V_85 = F_150 ( V_85 , V_184 , V_183 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return V_85 ;
V_114 += V_152 ;
V_183 += V_152 ;
}
V_150 = V_15 ;
}
F_104 ( V_11 ) ;
return V_85 ;
}
T_6 F_151 ( const struct V_6 * V_7 , int V_114 ,
T_2 * V_149 , int V_11 , T_6 V_85 )
{
int V_150 = F_100 ( V_7 ) ;
int V_46 , V_152 = V_150 - V_114 ;
struct V_6 * V_151 ;
int V_183 = 0 ;
if ( V_152 > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
V_85 = F_152 ( V_7 -> V_13 + V_114 , V_149 ,
V_152 , V_85 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return V_85 ;
V_114 += V_152 ;
V_149 += V_152 ;
V_183 = V_152 ;
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
T_6 V_184 ;
T_2 * V_108 ;
T_5 * V_139 = & F_22 ( V_7 ) -> V_110 [ V_46 ] ;
if ( V_152 > V_11 )
V_152 = V_11 ;
V_108 = F_85 ( V_139 ) ;
V_184 = F_152 ( V_108 +
V_139 -> V_113 +
V_114 - V_150 , V_149 ,
V_152 , 0 ) ;
F_88 ( V_108 ) ;
V_85 = F_150 ( V_85 , V_184 , V_183 ) ;
if ( ! ( V_11 -= V_152 ) )
return V_85 ;
V_114 += V_152 ;
V_149 += V_152 ;
V_183 += V_152 ;
}
V_150 = V_15 ;
}
F_37 (skb, frag_iter) {
T_6 V_184 ;
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + V_151 -> V_11 ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
V_184 = F_151 ( V_151 ,
V_114 - V_150 ,
V_149 , V_152 , 0 ) ;
V_85 = F_150 ( V_85 , V_184 , V_183 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return V_85 ;
V_114 += V_152 ;
V_149 += V_152 ;
V_183 += V_152 ;
}
V_150 = V_15 ;
}
F_104 ( V_11 ) ;
return V_85 ;
}
void F_153 ( const struct V_6 * V_7 , T_2 * V_149 )
{
T_6 V_85 ;
long V_185 ;
if ( V_7 -> V_88 == V_125 )
V_185 = F_154 ( V_7 ) ;
else
V_185 = F_100 ( V_7 ) ;
F_104 ( V_185 > F_100 ( V_7 ) ) ;
F_101 ( V_7 , V_149 , V_185 ) ;
V_85 = 0 ;
if ( V_185 != V_7 -> V_11 )
V_85 = F_151 ( V_7 , V_185 , V_149 + V_185 ,
V_7 -> V_11 - V_185 , 0 ) ;
if ( V_7 -> V_88 == V_125 ) {
long V_186 = V_185 + V_7 -> V_187 ;
* ( ( V_188 * ) ( V_149 + V_186 ) ) = F_155 ( V_85 ) ;
}
}
struct V_6 * F_156 ( struct V_189 * V_51 )
{
unsigned long V_175 ;
struct V_6 * V_190 ;
F_157 ( & V_51 -> V_191 , V_175 ) ;
V_190 = F_158 ( V_51 ) ;
F_159 ( & V_51 -> V_191 , V_175 ) ;
return V_190 ;
}
struct V_6 * F_160 ( struct V_189 * V_51 )
{
unsigned long V_175 ;
struct V_6 * V_190 ;
F_157 ( & V_51 -> V_191 , V_175 ) ;
V_190 = F_161 ( V_51 ) ;
F_159 ( & V_51 -> V_191 , V_175 ) ;
return V_190 ;
}
void F_162 ( struct V_189 * V_51 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_156 ( V_51 ) ) != NULL )
F_34 ( V_7 ) ;
}
void F_163 ( struct V_189 * V_51 , struct V_6 * V_192 )
{
unsigned long V_175 ;
F_157 ( & V_51 -> V_191 , V_175 ) ;
F_164 ( V_51 , V_192 ) ;
F_159 ( & V_51 -> V_191 , V_175 ) ;
}
void F_165 ( struct V_189 * V_51 , struct V_6 * V_192 )
{
unsigned long V_175 ;
F_157 ( & V_51 -> V_191 , V_175 ) ;
F_166 ( V_51 , V_192 ) ;
F_159 ( & V_51 -> V_191 , V_175 ) ;
}
void F_167 ( struct V_6 * V_7 , struct V_189 * V_51 )
{
unsigned long V_175 ;
F_157 ( & V_51 -> V_191 , V_175 ) ;
F_168 ( V_7 , V_51 ) ;
F_159 ( & V_51 -> V_191 , V_175 ) ;
}
void F_169 ( struct V_6 * V_77 , struct V_6 * V_192 , struct V_189 * V_51 )
{
unsigned long V_175 ;
F_157 ( & V_51 -> V_191 , V_175 ) ;
F_170 ( V_51 , V_77 , V_192 ) ;
F_159 ( & V_51 -> V_191 , V_175 ) ;
}
void F_171 ( struct V_6 * V_77 , struct V_6 * V_192 , struct V_189 * V_51 )
{
unsigned long V_175 ;
F_157 ( & V_51 -> V_191 , V_175 ) ;
F_172 ( V_192 , V_77 -> V_101 , V_77 , V_51 ) ;
F_159 ( & V_51 -> V_191 , V_175 ) ;
}
static inline void F_173 ( struct V_6 * V_7 ,
struct V_6 * V_193 ,
const T_7 V_11 , const int V_183 )
{
int V_46 ;
F_127 ( V_7 , V_11 , F_97 ( V_193 , V_183 - V_11 ) ,
V_183 - V_11 ) ;
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ )
F_22 ( V_193 ) -> V_110 [ V_46 ] = F_22 ( V_7 ) -> V_110 [ V_46 ] ;
F_22 ( V_193 ) -> V_58 = F_22 ( V_7 ) -> V_58 ;
F_22 ( V_7 ) -> V_58 = 0 ;
V_193 -> V_48 = V_7 -> V_48 ;
V_193 -> V_11 += V_193 -> V_48 ;
V_7 -> V_48 = 0 ;
V_7 -> V_11 = V_11 ;
F_123 ( V_7 , V_11 ) ;
}
static inline void F_174 ( struct V_6 * V_7 ,
struct V_6 * V_193 ,
const T_7 V_11 , int V_183 )
{
int V_46 , V_144 = 0 ;
const int V_140 = F_22 ( V_7 ) -> V_58 ;
F_22 ( V_7 ) -> V_58 = 0 ;
V_193 -> V_11 = V_193 -> V_48 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_48 = V_11 - V_183 ;
for ( V_46 = 0 ; V_46 < V_140 ; V_46 ++ ) {
int V_18 = F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( V_183 + V_18 > V_11 ) {
F_22 ( V_193 ) -> V_110 [ V_144 ] = F_22 ( V_7 ) -> V_110 [ V_46 ] ;
if ( V_183 < V_11 ) {
F_102 ( V_7 , V_46 ) ;
F_22 ( V_193 ) -> V_110 [ 0 ] . V_113 += V_11 - V_183 ;
F_126 ( & F_22 ( V_193 ) -> V_110 [ 0 ] , V_11 - V_183 ) ;
F_121 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] , V_11 - V_183 ) ;
F_22 ( V_7 ) -> V_58 ++ ;
}
V_144 ++ ;
} else
F_22 ( V_7 ) -> V_58 ++ ;
V_183 += V_18 ;
}
F_22 ( V_193 ) -> V_58 = V_144 ;
}
void F_175 ( struct V_6 * V_7 , struct V_6 * V_193 , const T_7 V_11 )
{
int V_183 = F_100 ( V_7 ) ;
if ( V_11 < V_183 )
F_173 ( V_7 , V_193 , V_11 , V_183 ) ;
else
F_174 ( V_7 , V_193 , V_11 , V_183 ) ;
}
static int F_176 ( struct V_6 * V_7 )
{
return F_111 ( V_7 ) && F_103 ( V_7 , 0 , 0 , V_49 ) ;
}
int F_177 ( struct V_6 * V_194 , struct V_6 * V_7 , int V_195 )
{
int V_182 , V_149 , V_196 , V_197 ;
struct V_198 * V_199 , * V_200 ;
F_104 ( V_195 > V_7 -> V_11 ) ;
F_104 ( F_100 ( V_7 ) ) ;
V_197 = V_195 ;
V_182 = 0 ;
V_149 = F_22 ( V_194 ) -> V_58 ;
V_199 = & F_22 ( V_7 ) -> V_110 [ V_182 ] ;
if ( ! V_149 ||
! F_178 ( V_194 , V_149 , F_139 ( V_199 ) ,
V_199 -> V_113 ) ) {
V_196 = - 1 ;
} else {
V_196 = V_149 - 1 ;
V_197 -= F_87 ( V_199 ) ;
if ( V_197 < 0 ) {
if ( F_176 ( V_7 ) ||
F_176 ( V_194 ) )
return 0 ;
V_199 = & F_22 ( V_7 ) -> V_110 [ V_182 ] ;
V_200 = & F_22 ( V_194 ) -> V_110 [ V_196 ] ;
F_179 ( V_200 , V_195 ) ;
F_126 ( V_199 , V_195 ) ;
V_199 -> V_113 += V_195 ;
goto V_201;
}
V_182 ++ ;
}
if ( ( V_195 == V_7 -> V_11 ) &&
( F_22 ( V_7 ) -> V_58 - V_182 ) > ( V_202 - V_149 ) )
return 0 ;
if ( F_176 ( V_7 ) || F_176 ( V_194 ) )
return 0 ;
while ( ( V_197 > 0 ) && ( V_182 < F_22 ( V_7 ) -> V_58 ) ) {
if ( V_149 == V_202 )
return 0 ;
V_199 = & F_22 ( V_7 ) -> V_110 [ V_182 ] ;
V_200 = & F_22 ( V_194 ) -> V_110 [ V_149 ] ;
if ( V_197 >= F_87 ( V_199 ) ) {
* V_200 = * V_199 ;
V_197 -= F_87 ( V_199 ) ;
V_182 ++ ;
V_149 ++ ;
} else {
F_180 ( V_199 ) ;
V_200 -> V_5 = V_199 -> V_5 ;
V_200 -> V_113 = V_199 -> V_113 ;
F_121 ( V_200 , V_197 ) ;
V_199 -> V_113 += V_197 ;
F_126 ( V_199 , V_197 ) ;
V_197 = 0 ;
V_149 ++ ;
break;
}
}
F_22 ( V_194 ) -> V_58 = V_149 ;
if ( V_196 >= 0 ) {
V_199 = & F_22 ( V_7 ) -> V_110 [ 0 ] ;
V_200 = & F_22 ( V_194 ) -> V_110 [ V_196 ] ;
F_179 ( V_200 , F_87 ( V_199 ) ) ;
F_181 ( V_199 ) ;
}
V_149 = 0 ;
while ( V_182 < F_22 ( V_7 ) -> V_58 )
F_22 ( V_7 ) -> V_110 [ V_149 ++ ] = F_22 ( V_7 ) -> V_110 [ V_182 ++ ] ;
F_22 ( V_7 ) -> V_58 = V_149 ;
F_104 ( V_197 > 0 && ! F_22 ( V_7 ) -> V_58 ) ;
V_201:
V_194 -> V_88 = V_125 ;
V_7 -> V_88 = V_125 ;
V_7 -> V_11 -= V_195 ;
V_7 -> V_48 -= V_195 ;
V_7 -> V_31 -= V_195 ;
V_194 -> V_11 += V_195 ;
V_194 -> V_48 += V_195 ;
V_194 -> V_31 += V_195 ;
return V_195 ;
}
void F_182 ( struct V_6 * V_7 , unsigned int V_182 ,
unsigned int V_149 , struct V_203 * V_204 )
{
V_204 -> V_205 = V_182 ;
V_204 -> V_206 = V_149 ;
V_204 -> V_207 = V_204 -> V_208 = V_7 ;
V_204 -> V_209 = V_204 -> V_210 = 0 ;
V_204 -> V_211 = NULL ;
}
unsigned int F_183 ( unsigned int V_212 , const T_2 * * V_13 ,
struct V_203 * V_204 )
{
unsigned int V_213 , V_214 = V_212 + V_204 -> V_205 ;
T_5 * V_139 ;
if ( F_62 ( V_214 >= V_204 -> V_206 ) )
return 0 ;
V_215:
V_213 = F_100 ( V_204 -> V_208 ) + V_204 -> V_210 ;
if ( V_214 < V_213 && ! V_204 -> V_211 ) {
* V_13 = V_204 -> V_208 -> V_13 + ( V_214 - V_204 -> V_210 ) ;
return V_213 - V_214 ;
}
if ( V_204 -> V_209 == 0 && ! V_204 -> V_211 )
V_204 -> V_210 += F_100 ( V_204 -> V_208 ) ;
while ( V_204 -> V_209 < F_22 ( V_204 -> V_208 ) -> V_58 ) {
V_139 = & F_22 ( V_204 -> V_208 ) -> V_110 [ V_204 -> V_209 ] ;
V_213 = F_87 ( V_139 ) + V_204 -> V_210 ;
if ( V_214 < V_213 ) {
if ( ! V_204 -> V_211 )
V_204 -> V_211 = F_85 ( V_139 ) ;
* V_13 = ( T_2 * ) V_204 -> V_211 + V_139 -> V_113 +
( V_214 - V_204 -> V_210 ) ;
return V_213 - V_214 ;
}
if ( V_204 -> V_211 ) {
F_88 ( V_204 -> V_211 ) ;
V_204 -> V_211 = NULL ;
}
V_204 -> V_209 ++ ;
V_204 -> V_210 += F_87 ( V_139 ) ;
}
if ( V_204 -> V_211 ) {
F_88 ( V_204 -> V_211 ) ;
V_204 -> V_211 = NULL ;
}
if ( V_204 -> V_207 == V_204 -> V_208 && F_42 ( V_204 -> V_207 ) ) {
V_204 -> V_208 = F_22 ( V_204 -> V_207 ) -> V_54 ;
V_204 -> V_209 = 0 ;
goto V_215;
} else if ( V_204 -> V_208 -> V_53 ) {
V_204 -> V_208 = V_204 -> V_208 -> V_53 ;
V_204 -> V_209 = 0 ;
goto V_215;
}
return 0 ;
}
void F_184 ( struct V_203 * V_204 )
{
if ( V_204 -> V_211 )
F_88 ( V_204 -> V_211 ) ;
}
static unsigned int F_185 ( unsigned int V_114 , const T_2 * * V_216 ,
struct V_217 * V_218 ,
struct V_219 * V_220 )
{
return F_183 ( V_114 , V_216 , F_186 ( V_220 ) ) ;
}
static void F_187 ( struct V_217 * V_218 , struct V_219 * V_220 )
{
F_184 ( F_186 ( V_220 ) ) ;
}
unsigned int F_188 ( struct V_6 * V_7 , unsigned int V_182 ,
unsigned int V_149 , struct V_217 * V_221 ,
struct V_219 * V_220 )
{
unsigned int V_181 ;
V_221 -> V_222 = F_185 ;
V_221 -> V_223 = F_187 ;
F_182 ( V_7 , V_182 , V_149 , F_186 ( V_220 ) ) ;
V_181 = F_189 ( V_221 , V_220 ) ;
return ( V_181 <= V_149 - V_182 ? V_181 : V_224 ) ;
}
int F_190 ( struct V_158 * V_102 , struct V_6 * V_7 ,
int (* F_191)( void * V_182 , char * V_149 , int V_114 ,
int V_11 , int V_225 , struct V_6 * V_7 ) ,
void * V_182 , int V_43 )
{
int V_226 = 0 ;
T_5 * V_139 = NULL ;
struct V_5 * V_5 = NULL ;
int V_152 , V_227 ;
int V_114 = 0 ;
int V_181 ;
do {
V_226 = F_22 ( V_7 ) -> V_58 ;
if ( V_226 >= V_202 )
return - V_154 ;
V_5 = F_130 ( V_102 -> V_162 , 0 ) ;
if ( V_5 == NULL )
return - V_112 ;
F_30 ( V_7 , V_226 , V_5 , 0 , 0 ) ;
V_7 -> V_31 += V_165 ;
F_192 ( V_165 , & V_102 -> V_228 ) ;
V_226 = F_22 ( V_7 ) -> V_58 ;
V_139 = & F_22 ( V_7 ) -> V_110 [ V_226 - 1 ] ;
V_227 = V_165 - V_139 -> V_113 ;
V_152 = ( V_43 > V_227 ) ? V_227 : V_43 ;
V_181 = F_191 ( V_182 , F_193 ( V_139 ) + F_87 ( V_139 ) ,
V_114 , V_152 , 0 , V_7 ) ;
if ( V_181 < 0 )
return - V_154 ;
F_179 ( V_139 , V_152 ) ;
V_7 -> V_11 += V_152 ;
V_7 -> V_48 += V_152 ;
V_114 += V_152 ;
V_43 -= V_152 ;
} while ( V_43 > 0 );
return 0 ;
}
unsigned char * F_194 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_104 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_104 ( V_7 -> V_11 < V_7 -> V_48 ) ;
F_195 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_196 ( struct V_6 * V_7 , T_7 V_229 )
{
struct V_6 * V_230 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_231 = F_22 ( V_7 ) -> V_54 ;
unsigned int V_232 = F_22 ( V_7 ) -> V_115 ;
unsigned int V_233 = V_7 -> V_13 - F_197 ( V_7 ) ;
unsigned int V_114 = V_233 ;
unsigned int V_127 ;
unsigned int V_11 ;
int V_234 = ! ! ( V_229 & V_235 ) ;
int V_140 = F_22 ( V_7 ) -> V_58 ;
int V_135 = - V_112 ;
int V_46 = 0 ;
int V_183 ;
F_198 ( V_7 , V_233 ) ;
V_127 = F_80 ( V_7 ) ;
V_183 = F_100 ( V_7 ) ;
do {
struct V_6 * V_236 ;
T_5 * V_139 ;
int V_237 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_114 ;
if ( V_11 > V_232 )
V_11 = V_232 ;
V_237 = F_100 ( V_7 ) - V_114 ;
if ( V_237 < 0 )
V_237 = 0 ;
if ( V_237 > V_11 || ! V_234 )
V_237 = V_11 ;
if ( ! V_237 && V_46 >= V_140 ) {
F_104 ( V_231 -> V_11 != V_11 ) ;
V_183 += V_11 ;
V_236 = F_90 ( V_231 , V_49 ) ;
V_231 = V_231 -> V_53 ;
if ( F_62 ( ! V_236 ) )
goto V_135;
V_237 = F_95 ( V_236 ) - V_236 -> V_12 ;
if ( F_199 ( V_236 , V_233 + V_127 ) ) {
F_34 ( V_236 ) ;
goto V_135;
}
V_236 -> V_31 += F_95 ( V_236 ) - V_236 -> V_12 -
V_237 ;
F_46 ( V_236 ) ;
F_198 ( V_236 , V_233 ) ;
} else {
V_236 = F_96 ( V_237 + V_233 + V_127 ,
V_49 ) ;
if ( F_62 ( ! V_236 ) )
goto V_135;
F_28 ( V_236 , V_127 ) ;
F_200 ( V_236 , V_233 ) ;
}
if ( V_230 )
V_14 -> V_53 = V_236 ;
else
V_230 = V_236 ;
V_14 = V_236 ;
F_72 ( V_236 , V_7 ) ;
V_236 -> V_103 = V_7 -> V_103 ;
if ( V_236 -> V_88 == V_125 )
V_236 -> V_126 += F_80 ( V_236 ) - V_127 ;
F_201 ( V_236 ) ;
F_202 ( V_236 , V_7 -> V_103 ) ;
V_236 -> V_79 = ( V_236 -> V_80 +
F_203 ( V_7 ) ) ;
F_101 ( V_7 , V_236 -> V_13 , V_233 ) ;
if ( V_231 != F_22 ( V_7 ) -> V_54 )
continue;
if ( ! V_234 ) {
V_236 -> V_88 = V_238 ;
V_236 -> V_85 = F_151 ( V_7 , V_114 ,
F_97 ( V_236 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_139 = F_22 ( V_236 ) -> V_110 ;
F_127 ( V_7 , V_114 ,
F_97 ( V_236 , V_237 ) , V_237 ) ;
while ( V_183 < V_114 + V_11 && V_46 < V_140 ) {
* V_139 = F_22 ( V_7 ) -> V_110 [ V_46 ] ;
F_180 ( V_139 ) ;
V_18 = F_87 ( V_139 ) ;
if ( V_183 < V_114 ) {
V_139 -> V_113 += V_114 - V_183 ;
F_126 ( V_139 , V_114 - V_183 ) ;
}
F_22 ( V_236 ) -> V_58 ++ ;
if ( V_183 + V_18 <= V_114 + V_11 ) {
V_46 ++ ;
V_183 += V_18 ;
} else {
F_126 ( V_139 , V_183 + V_18 - ( V_114 + V_11 ) ) ;
goto V_239;
}
V_139 ++ ;
}
if ( V_183 < V_114 + V_11 ) {
struct V_6 * V_240 = V_231 ;
F_104 ( V_183 + V_231 -> V_11 != V_114 + V_11 ) ;
V_183 += V_231 -> V_11 ;
V_231 = V_231 -> V_53 ;
if ( V_240 -> V_53 ) {
V_240 = F_90 ( V_240 , V_49 ) ;
if ( ! V_240 )
goto V_135;
} else
F_38 ( V_240 ) ;
F_204 ( V_236 ) ;
F_22 ( V_236 ) -> V_54 = V_240 ;
}
V_239:
V_236 -> V_48 = V_11 - V_237 ;
V_236 -> V_11 += V_236 -> V_48 ;
V_236 -> V_31 += V_236 -> V_48 ;
} while ( ( V_114 += V_11 ) < V_7 -> V_11 );
return V_230 ;
V_135:
while ( ( V_7 = V_230 ) ) {
V_230 = V_7 -> V_53 ;
F_34 ( V_7 ) ;
}
return F_205 ( V_135 ) ;
}
int F_206 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_159 = * V_12 ;
struct V_6 * V_236 ;
struct V_24 * V_241 = F_22 ( V_7 ) ;
struct V_24 * V_242 = F_22 ( V_159 ) ;
unsigned int V_127 ;
unsigned int V_11 = F_207 ( V_7 ) ;
unsigned int V_114 = F_208 ( V_7 ) ;
unsigned int V_243 = F_100 ( V_7 ) ;
if ( V_159 -> V_11 + V_11 >= 65536 )
return - V_244 ;
if ( V_242 -> V_54 )
goto V_196;
else if ( V_243 <= V_114 ) {
T_5 * V_139 ;
T_5 * V_245 ;
int V_46 = V_241 -> V_58 ;
int V_58 = V_242 -> V_58 + V_46 ;
V_114 -= V_243 ;
if ( V_58 > V_202 )
return - V_244 ;
V_242 -> V_58 = V_58 ;
V_241 -> V_58 = 0 ;
V_139 = V_242 -> V_110 + V_58 ;
V_245 = V_241 -> V_110 + V_46 ;
do {
* -- V_139 = * -- V_245 ;
} while ( -- V_46 );
V_139 -> V_113 += V_114 ;
F_126 ( V_139 , V_114 ) ;
V_7 -> V_31 -= V_7 -> V_48 ;
V_7 -> V_11 -= V_7 -> V_48 ;
V_7 -> V_48 = 0 ;
F_209 ( V_7 ) -> free = 1 ;
goto V_142;
} else if ( F_207 ( V_159 ) != V_242 -> V_115 )
return - V_244 ;
V_127 = F_80 ( V_159 ) ;
V_236 = F_96 ( V_127 + F_208 ( V_159 ) , V_49 ) ;
if ( F_62 ( ! V_236 ) )
return - V_112 ;
F_72 ( V_236 , V_159 ) ;
V_236 -> V_103 = V_159 -> V_103 ;
F_28 ( V_236 , V_127 ) ;
F_200 ( V_236 , F_208 ( V_159 ) ) ;
F_210 ( V_236 , F_197 ( V_159 ) - V_159 -> V_13 ) ;
F_202 ( V_236 , F_211 ( V_159 ) ) ;
F_212 ( V_236 , F_213 ( V_159 ) ) ;
F_214 ( V_159 , F_208 ( V_159 ) ) ;
memcpy ( F_197 ( V_236 ) , F_197 ( V_159 ) ,
V_159 -> V_13 - F_197 ( V_159 ) ) ;
* F_209 ( V_236 ) = * F_209 ( V_159 ) ;
F_22 ( V_236 ) -> V_54 = V_159 ;
F_22 ( V_236 ) -> V_115 = V_242 -> V_115 ;
V_242 -> V_115 = 0 ;
F_215 ( V_159 ) ;
V_236 -> V_101 = V_159 ;
V_236 -> V_48 += V_159 -> V_11 ;
V_236 -> V_31 += V_159 -> V_11 ;
V_236 -> V_11 += V_159 -> V_11 ;
* V_12 = V_236 ;
V_236 -> V_53 = V_159 -> V_53 ;
V_159 -> V_53 = NULL ;
V_159 = V_236 ;
V_196:
if ( V_114 > V_243 ) {
unsigned int V_145 = V_114 - V_243 ;
V_241 -> V_110 [ 0 ] . V_113 += V_145 ;
F_126 ( & V_241 -> V_110 [ 0 ] , V_145 ) ;
V_7 -> V_48 -= V_145 ;
V_7 -> V_11 -= V_145 ;
V_114 = V_243 ;
}
F_214 ( V_7 , V_114 ) ;
V_159 -> V_101 -> V_53 = V_7 ;
V_159 -> V_101 = V_7 ;
F_215 ( V_7 ) ;
V_142:
F_209 ( V_159 ) -> V_246 ++ ;
V_159 -> V_48 += V_11 ;
V_159 -> V_31 += V_11 ;
V_159 -> V_11 += V_11 ;
F_209 ( V_7 ) -> V_247 = 1 ;
return 0 ;
}
void T_8 F_216 ( void )
{
V_27 = F_217 ( L_5 ,
sizeof( struct V_6 ) ,
0 ,
V_248 | V_249 ,
NULL ) ;
V_26 = F_217 ( L_6 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_3 ) ,
0 ,
V_248 | V_249 ,
NULL ) ;
}
static int
F_218 ( struct V_6 * V_7 , struct V_250 * V_234 , int V_114 , int V_11 )
{
int V_150 = F_100 ( V_7 ) ;
int V_46 , V_152 = V_150 - V_114 ;
struct V_6 * V_151 ;
int V_251 = 0 ;
if ( V_152 > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
F_219 ( V_234 , V_7 -> V_13 + V_114 , V_152 ) ;
V_251 ++ ;
if ( ( V_11 -= V_152 ) == 0 )
return V_251 ;
V_114 += V_152 ;
}
for ( V_46 = 0 ; V_46 < F_22 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + F_87 ( & F_22 ( V_7 ) -> V_110 [ V_46 ] ) ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
T_5 * V_139 = & F_22 ( V_7 ) -> V_110 [ V_46 ] ;
if ( V_152 > V_11 )
V_152 = V_11 ;
F_220 ( & V_234 [ V_251 ] , F_139 ( V_139 ) , V_152 ,
V_139 -> V_113 + V_114 - V_150 ) ;
V_251 ++ ;
if ( ! ( V_11 -= V_152 ) )
return V_251 ;
V_114 += V_152 ;
}
V_150 = V_15 ;
}
F_37 (skb, frag_iter) {
int V_15 ;
F_50 ( V_150 > V_114 + V_11 ) ;
V_15 = V_150 + V_151 -> V_11 ;
if ( ( V_152 = V_15 - V_114 ) > 0 ) {
if ( V_152 > V_11 )
V_152 = V_11 ;
V_251 += F_218 ( V_151 , V_234 + V_251 , V_114 - V_150 ,
V_152 ) ;
if ( ( V_11 -= V_152 ) == 0 )
return V_251 ;
V_114 += V_152 ;
}
V_150 = V_15 ;
}
F_104 ( V_11 ) ;
return V_251 ;
}
int F_221 ( struct V_6 * V_7 , struct V_250 * V_234 , int V_114 , int V_11 )
{
int V_252 = F_218 ( V_7 , V_234 , V_114 , V_11 ) ;
F_222 ( & V_234 [ V_252 - 1 ] ) ;
return V_252 ;
}
int F_223 ( struct V_6 * V_7 , int V_253 , struct V_6 * * V_254 )
{
int V_255 ;
int V_251 ;
struct V_6 * V_193 , * * V_256 ;
if ( ( F_111 ( V_7 ) || F_22 ( V_7 ) -> V_58 ) &&
F_124 ( V_7 , F_224 ( V_7 ) - F_100 ( V_7 ) ) == NULL )
return - V_112 ;
if ( ! F_42 ( V_7 ) ) {
if ( F_112 ( V_7 ) < V_253 &&
F_103 ( V_7 , 0 , V_253 - F_112 ( V_7 ) + 128 , V_49 ) )
return - V_112 ;
* V_254 = V_7 ;
return 1 ;
}
V_251 = 1 ;
V_256 = & F_22 ( V_7 ) -> V_54 ;
V_255 = 0 ;
while ( ( V_193 = * V_256 ) != NULL ) {
int V_120 = 0 ;
if ( F_105 ( V_193 ) )
V_255 = 1 ;
if ( V_193 -> V_53 == NULL && V_253 ) {
if ( F_22 ( V_193 ) -> V_58 ||
F_42 ( V_193 ) ||
F_112 ( V_193 ) < V_253 )
V_120 = V_253 + 128 ;
}
if ( V_255 ||
F_111 ( V_193 ) ||
V_120 ||
F_22 ( V_193 ) -> V_58 ||
F_42 ( V_193 ) ) {
struct V_6 * V_128 ;
if ( V_120 == 0 )
V_128 = F_94 ( V_193 , V_49 ) ;
else
V_128 = F_109 ( V_193 ,
F_80 ( V_193 ) ,
V_120 ,
V_49 ) ;
if ( F_62 ( V_128 == NULL ) )
return - V_112 ;
if ( V_193 -> V_102 )
F_225 ( V_128 , V_193 -> V_102 ) ;
V_128 -> V_53 = V_193 -> V_53 ;
* V_256 = V_128 ;
F_34 ( V_193 ) ;
V_193 = V_128 ;
}
V_251 ++ ;
* V_254 = V_193 ;
V_256 = & V_193 -> V_53 ;
}
return V_251 ;
}
static void F_226 ( struct V_6 * V_7 )
{
struct V_158 * V_102 = V_7 -> V_102 ;
F_227 ( V_7 -> V_31 , & V_102 -> V_257 ) ;
}
int F_228 ( struct V_158 * V_102 , struct V_6 * V_7 )
{
if ( F_63 ( & V_102 -> V_257 ) + V_7 -> V_31 >=
( unsigned ) V_102 -> V_258 )
return - V_112 ;
F_229 ( V_7 ) ;
V_7 -> V_102 = V_102 ;
V_7 -> V_67 = F_226 ;
F_192 ( V_7 -> V_31 , & V_102 -> V_257 ) ;
F_230 ( V_7 ) ;
F_165 ( & V_102 -> V_259 , V_7 ) ;
if ( ! F_231 ( V_102 , V_260 ) )
V_102 -> V_261 ( V_102 , V_7 -> V_11 ) ;
return 0 ;
}
void F_232 ( struct V_6 * V_262 ,
struct V_263 * V_264 )
{
struct V_158 * V_102 = V_262 -> V_102 ;
struct V_265 * V_266 ;
struct V_6 * V_7 ;
int V_135 ;
if ( ! V_102 )
return;
V_7 = F_90 ( V_262 , V_49 ) ;
if ( ! V_7 )
return;
if ( V_264 ) {
* F_233 ( V_7 ) =
* V_264 ;
} else {
V_7 -> V_78 = F_234 () ;
}
V_266 = F_235 ( V_7 ) ;
memset ( V_266 , 0 , sizeof( * V_266 ) ) ;
V_266 -> V_267 . V_268 = V_269 ;
V_266 -> V_267 . V_270 = V_271 ;
V_135 = F_228 ( V_102 , V_7 ) ;
if ( V_135 )
F_34 ( V_7 ) ;
}
bool F_236 ( struct V_6 * V_7 , T_9 V_150 , T_9 V_47 )
{
if ( F_62 ( V_150 > F_100 ( V_7 ) ) ||
F_62 ( ( int ) V_150 + V_47 > F_100 ( V_7 ) - 2 ) ) {
if ( F_237 () )
F_7 ( V_272
L_7 ,
V_150 , V_47 , F_100 ( V_7 ) ) ;
return false ;
}
V_7 -> V_88 = V_125 ;
V_7 -> V_126 = F_80 ( V_7 ) + V_150 ;
V_7 -> V_187 = V_47 ;
return true ;
}
void F_238 ( const struct V_6 * V_7 )
{
if ( F_237 () )
F_239 ( L_8
L_9 , V_7 -> V_16 -> V_17 ) ;
}
