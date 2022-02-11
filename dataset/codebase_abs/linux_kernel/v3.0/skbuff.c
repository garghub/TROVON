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
V_13 = F_14 ( V_18 + sizeof( struct V_24 ) ,
V_19 , V_21 ) ;
if ( ! V_13 )
goto V_30;
F_12 ( V_13 + V_18 ) ;
memset ( V_7 , 0 , F_15 ( struct V_6 , V_14 ) ) ;
V_7 -> V_31 = V_18 + sizeof( struct V_6 ) ;
F_16 ( & V_7 -> V_32 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_17 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_18
V_7 -> V_33 = ~ 0U ;
#endif
V_25 = F_19 ( V_7 ) ;
memset ( V_25 , 0 , F_15 ( struct V_24 , V_34 ) ) ;
F_16 ( & V_25 -> V_34 , 1 ) ;
F_20 ( V_25 -> V_35 ) ;
if ( V_20 ) {
struct V_6 * V_36 = V_7 + 1 ;
T_3 * V_37 = ( T_3 * ) ( V_36 + 1 ) ;
F_21 ( V_36 , V_38 ) ;
F_21 ( V_36 , V_39 ) ;
V_7 -> V_20 = V_40 ;
F_16 ( V_37 , 1 ) ;
V_36 -> V_20 = V_41 ;
}
V_29:
return V_7 ;
V_30:
F_22 ( V_23 , V_7 ) ;
V_7 = NULL ;
goto V_29;
}
struct V_6 * F_23 ( struct V_42 * V_16 ,
unsigned int V_43 , T_1 V_19 )
{
struct V_6 * V_7 ;
V_7 = F_10 ( V_43 + V_44 , V_19 , 0 , V_45 ) ;
if ( F_24 ( V_7 ) ) {
F_25 ( V_7 , V_44 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_26 ( struct V_6 * V_7 , int V_46 , struct V_5 * V_5 , int V_47 ,
int V_18 )
{
F_27 ( V_7 , V_46 , V_5 , V_47 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_48 += V_18 ;
V_7 -> V_31 += V_18 ;
}
struct V_6 * F_28 ( unsigned int V_43 )
{
return F_29 ( V_43 , V_49 ) ;
}
static void F_30 ( struct V_6 * * V_50 )
{
struct V_6 * V_51 = * V_50 ;
* V_50 = NULL ;
do {
struct V_6 * V_52 = V_51 ;
V_51 = V_51 -> V_53 ;
F_31 ( V_52 ) ;
} while ( V_51 );
}
static inline void F_32 ( struct V_6 * V_7 )
{
F_30 ( & F_19 ( V_7 ) -> V_54 ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_6 * V_51 ;
F_34 (skb, list)
F_35 ( V_51 ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_55 ||
! F_37 ( V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ,
& F_19 ( V_7 ) -> V_34 ) ) {
if ( F_19 ( V_7 ) -> V_58 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ )
F_2 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
}
if ( F_38 ( V_7 ) )
F_32 ( V_7 ) ;
F_39 ( V_7 -> V_12 ) ;
}
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_6 * V_60 ;
T_3 * V_37 ;
switch ( V_7 -> V_20 ) {
case V_41 :
F_22 ( V_27 , V_7 ) ;
break;
case V_40 :
V_37 = ( T_3 * ) ( V_7 + 2 ) ;
if ( F_41 ( V_37 ) )
F_22 ( V_26 , V_7 ) ;
break;
case V_61 :
V_37 = ( T_3 * ) ( V_7 + 1 ) ;
V_60 = V_7 - 1 ;
V_7 -> V_20 = V_41 ;
if ( F_41 ( V_37 ) )
F_22 ( V_26 , V_60 ) ;
break;
}
}
static void F_42 ( struct V_6 * V_7 )
{
F_43 ( V_7 ) ;
#ifdef F_44
F_45 ( V_7 -> V_62 ) ;
#endif
if ( V_7 -> V_63 ) {
F_46 ( F_47 () ) ;
V_7 -> V_63 ( V_7 ) ;
}
#if F_48 ( V_64 ) || F_48 ( V_65 )
F_49 ( V_7 -> V_66 ) ;
#endif
#ifdef F_50
F_51 ( V_7 -> V_67 ) ;
#endif
#ifdef F_52
F_53 ( V_7 -> V_68 ) ;
#endif
#ifdef F_54
V_7 -> V_69 = 0 ;
#ifdef F_55
V_7 -> V_70 = 0 ;
#endif
#endif
}
static void F_56 ( struct V_6 * V_7 )
{
F_42 ( V_7 ) ;
F_36 ( V_7 ) ;
}
void F_57 ( struct V_6 * V_7 )
{
F_56 ( V_7 ) ;
F_40 ( V_7 ) ;
}
void F_31 ( struct V_6 * V_7 )
{
if ( F_58 ( ! V_7 ) )
return;
if ( F_24 ( F_59 ( & V_7 -> V_32 ) == 1 ) )
F_60 () ;
else if ( F_24 ( ! F_41 ( & V_7 -> V_32 ) ) )
return;
F_61 ( V_7 , F_62 ( 0 ) ) ;
F_57 ( V_7 ) ;
}
void F_63 ( struct V_6 * V_7 )
{
if ( F_58 ( ! V_7 ) )
return;
if ( F_24 ( F_59 ( & V_7 -> V_32 ) == 1 ) )
F_60 () ;
else if ( F_24 ( ! F_41 ( & V_7 -> V_32 ) ) )
return;
F_64 ( V_7 ) ;
F_57 ( V_7 ) ;
}
bool F_65 ( struct V_6 * V_7 , int V_71 )
{
struct V_24 * V_25 ;
if ( F_66 () )
return false ;
if ( F_67 ( V_7 ) || V_7 -> V_20 != V_41 )
return false ;
V_71 = F_13 ( V_71 + V_44 ) ;
if ( F_68 ( V_7 ) - V_7 -> V_12 < V_71 )
return false ;
if ( F_69 ( V_7 ) || F_70 ( V_7 ) )
return false ;
F_42 ( V_7 ) ;
V_25 = F_19 ( V_7 ) ;
memset ( V_25 , 0 , F_15 ( struct V_24 , V_34 ) ) ;
F_16 ( & V_25 -> V_34 , 1 ) ;
memset ( V_7 , 0 , F_15 ( struct V_6 , V_14 ) ) ;
V_7 -> V_13 = V_7 -> V_12 + V_44 ;
F_17 ( V_7 ) ;
return true ;
}
static void F_71 ( struct V_6 * V_72 , const struct V_6 * V_73 )
{
V_72 -> V_74 = V_73 -> V_74 ;
V_72 -> V_16 = V_73 -> V_16 ;
V_72 -> V_75 = V_73 -> V_75 ;
V_72 -> V_76 = V_73 -> V_76 ;
V_72 -> V_33 = V_73 -> V_33 ;
F_72 ( V_72 , V_73 ) ;
V_72 -> V_77 = V_73 -> V_77 ;
#ifdef F_44
V_72 -> V_62 = F_73 ( V_73 -> V_62 ) ;
#endif
memcpy ( V_72 -> V_78 , V_73 -> V_78 , sizeof( V_73 -> V_78 ) ) ;
V_72 -> V_79 = V_73 -> V_79 ;
V_72 -> V_80 = V_73 -> V_80 ;
V_72 -> V_81 = V_73 -> V_81 ;
V_72 -> V_82 = V_73 -> V_82 ;
F_74 ( V_72 , V_73 ) ;
V_72 -> V_83 = V_73 -> V_83 ;
#if F_48 ( V_84 ) || F_48 ( V_85 )
V_72 -> V_86 = V_73 -> V_86 ;
#endif
V_72 -> V_87 = V_73 -> V_87 ;
V_72 -> V_88 = V_73 -> V_88 ;
V_72 -> V_89 = V_73 -> V_89 ;
F_75 ( V_72 , V_73 ) ;
#if F_48 ( V_90 ) || \
F_48 ( V_91 )
V_72 -> V_92 = V_73 -> V_92 ;
#endif
#ifdef F_54
V_72 -> V_69 = V_73 -> V_69 ;
#ifdef F_55
V_72 -> V_70 = V_73 -> V_70 ;
#endif
#endif
V_72 -> V_93 = V_73 -> V_93 ;
F_76 ( V_72 , V_73 ) ;
}
static struct V_6 * F_77 ( struct V_6 * V_94 , struct V_6 * V_7 )
{
#define F_78 ( T_4 ) n->x = skb->x
V_94 -> V_53 = V_94 -> V_95 = NULL ;
V_94 -> V_96 = NULL ;
F_71 ( V_94 , V_7 ) ;
F_78 ( V_11 ) ;
F_78 ( V_48 ) ;
F_78 ( V_97 ) ;
V_94 -> V_98 = V_7 -> V_56 ? F_79 ( V_7 ) : V_7 -> V_98 ;
V_94 -> V_55 = 1 ;
V_94 -> V_56 = 0 ;
V_94 -> V_63 = NULL ;
F_78 ( V_14 ) ;
F_78 ( V_15 ) ;
F_78 ( V_12 ) ;
F_78 ( V_13 ) ;
F_78 ( V_31 ) ;
F_16 ( & V_94 -> V_32 , 1 ) ;
F_80 ( & ( F_19 ( V_7 ) -> V_34 ) ) ;
V_7 -> V_55 = 1 ;
return V_94 ;
#undef F_78
}
struct V_6 * F_81 ( struct V_6 * V_99 , struct V_6 * V_100 )
{
F_56 ( V_99 ) ;
return F_77 ( V_99 , V_100 ) ;
}
struct V_6 * F_82 ( struct V_6 * V_7 , T_1 V_19 )
{
struct V_6 * V_94 ;
V_94 = V_7 + 1 ;
if ( V_7 -> V_20 == V_40 &&
V_94 -> V_20 == V_41 ) {
T_3 * V_37 = ( T_3 * ) ( V_94 + 1 ) ;
V_94 -> V_20 = V_61 ;
F_80 ( V_37 ) ;
} else {
V_94 = F_83 ( V_27 , V_19 ) ;
if ( ! V_94 )
return NULL ;
F_21 ( V_94 , V_38 ) ;
F_21 ( V_94 , V_39 ) ;
V_94 -> V_20 = V_41 ;
}
return F_77 ( V_94 , V_7 ) ;
}
static void F_84 ( struct V_6 * V_72 , const struct V_6 * V_73 )
{
#ifndef F_18
unsigned long V_101 = V_72 -> V_13 - V_73 -> V_13 ;
#endif
F_71 ( V_72 , V_73 ) ;
#ifndef F_18
V_72 -> V_75 += V_101 ;
V_72 -> V_76 += V_101 ;
if ( F_85 ( V_72 ) )
V_72 -> V_33 += V_101 ;
#endif
F_19 ( V_72 ) -> V_102 = F_19 ( V_73 ) -> V_102 ;
F_19 ( V_72 ) -> V_103 = F_19 ( V_73 ) -> V_103 ;
F_19 ( V_72 ) -> V_104 = F_19 ( V_73 ) -> V_104 ;
}
struct V_6 * F_86 ( const struct V_6 * V_7 , T_1 V_19 )
{
int V_105 = F_79 ( V_7 ) ;
unsigned int V_18 = ( F_68 ( V_7 ) - V_7 -> V_12 ) + V_7 -> V_48 ;
struct V_6 * V_94 = F_87 ( V_18 , V_19 ) ;
if ( ! V_94 )
return NULL ;
F_25 ( V_94 , V_105 ) ;
F_88 ( V_94 , V_7 -> V_11 ) ;
if ( F_89 ( V_7 , - V_105 , V_94 -> V_12 , V_105 + V_7 -> V_11 ) )
F_8 () ;
F_84 ( V_94 , V_7 ) ;
return V_94 ;
}
struct V_6 * F_90 ( struct V_6 * V_7 , T_1 V_19 )
{
unsigned int V_18 = F_68 ( V_7 ) - V_7 -> V_12 ;
struct V_6 * V_94 = F_87 ( V_18 , V_19 ) ;
if ( ! V_94 )
goto V_29;
F_25 ( V_94 , F_79 ( V_7 ) ) ;
F_88 ( V_94 , F_91 ( V_7 ) ) ;
F_92 ( V_7 , V_94 -> V_13 , V_94 -> V_11 ) ;
V_94 -> V_31 += V_7 -> V_48 ;
V_94 -> V_48 = V_7 -> V_48 ;
V_94 -> V_11 = V_7 -> V_11 ;
if ( F_19 ( V_7 ) -> V_58 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
F_19 ( V_94 ) -> V_59 [ V_46 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
F_4 ( F_19 ( V_94 ) -> V_59 [ V_46 ] . V_5 ) ;
}
F_19 ( V_94 ) -> V_58 = V_46 ;
}
if ( F_38 ( V_7 ) ) {
F_19 ( V_94 ) -> V_54 = F_19 ( V_7 ) -> V_54 ;
F_33 ( V_94 ) ;
}
F_84 ( V_94 , V_7 ) ;
V_29:
return V_94 ;
}
int F_93 ( struct V_6 * V_7 , int V_106 , int V_107 ,
T_1 V_19 )
{
int V_46 ;
T_2 * V_13 ;
int V_18 = V_106 + ( F_68 ( V_7 ) - V_7 -> V_12 ) + V_107 ;
long V_47 ;
bool V_108 ;
F_94 ( V_106 < 0 ) ;
if ( F_69 ( V_7 ) )
F_8 () ;
V_18 = F_13 ( V_18 ) ;
if ( ! V_7 -> V_55 )
V_108 = true ;
else {
int V_109 = V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ;
V_108 = F_59 ( & F_19 ( V_7 ) -> V_34 ) == V_109 ;
}
if ( V_108 &&
V_18 + sizeof( struct V_24 ) <= F_95 ( V_7 -> V_12 ) ) {
memmove ( V_7 -> V_12 + V_18 , F_19 ( V_7 ) ,
F_15 ( struct V_24 ,
V_59 [ F_19 ( V_7 ) -> V_58 ] ) ) ;
memmove ( V_7 -> V_12 + V_106 , V_7 -> V_12 ,
F_96 ( V_7 ) - V_7 -> V_12 ) ;
V_47 = V_106 ;
goto V_110;
}
V_13 = F_97 ( V_18 + sizeof( struct V_24 ) , V_19 ) ;
if ( ! V_13 )
goto V_30;
memcpy ( V_13 + V_106 , V_7 -> V_12 , F_96 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_24 * ) ( V_13 + V_18 ) ,
F_19 ( V_7 ) ,
F_15 ( struct V_24 , V_59 [ F_19 ( V_7 ) -> V_58 ] ) ) ;
if ( V_108 ) {
F_39 ( V_7 -> V_12 ) ;
} else {
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ )
F_4 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
if ( F_38 ( V_7 ) )
F_33 ( V_7 ) ;
F_36 ( V_7 ) ;
}
V_47 = ( V_13 + V_106 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_110:
V_7 -> V_13 += V_47 ;
#ifdef F_18
V_7 -> V_15 = V_18 ;
V_47 = V_106 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_47 ;
V_7 -> V_75 += V_47 ;
V_7 -> V_76 += V_47 ;
if ( F_85 ( V_7 ) )
V_7 -> V_33 += V_47 ;
if ( V_7 -> V_82 == V_111 )
V_7 -> V_112 += V_106 ;
V_7 -> V_55 = 0 ;
V_7 -> V_98 = 0 ;
V_7 -> V_56 = 0 ;
F_16 ( & F_19 ( V_7 ) -> V_34 , 1 ) ;
return 0 ;
V_30:
return - V_113 ;
}
struct V_6 * F_98 ( struct V_6 * V_7 , unsigned int V_114 )
{
struct V_6 * V_115 ;
int V_109 = V_114 - F_79 ( V_7 ) ;
if ( V_109 <= 0 )
V_115 = F_90 ( V_7 , V_49 ) ;
else {
V_115 = F_82 ( V_7 , V_49 ) ;
if ( V_115 && F_93 ( V_115 , F_13 ( V_109 ) , 0 ,
V_49 ) ) {
F_31 ( V_115 ) ;
V_115 = NULL ;
}
}
return V_115 ;
}
struct V_6 * F_99 ( const struct V_6 * V_7 ,
int V_116 , int V_117 ,
T_1 V_19 )
{
struct V_6 * V_94 = F_87 ( V_116 + V_7 -> V_11 + V_117 ,
V_19 ) ;
int V_118 = F_79 ( V_7 ) ;
int V_119 , V_120 ;
int V_47 ;
if ( ! V_94 )
return NULL ;
F_25 ( V_94 , V_116 ) ;
F_88 ( V_94 , V_7 -> V_11 ) ;
V_119 = V_118 ;
V_120 = 0 ;
if ( V_116 <= V_119 )
V_119 = V_116 ;
else
V_120 = V_116 - V_119 ;
if ( F_89 ( V_7 , - V_119 , V_94 -> V_12 + V_120 ,
V_7 -> V_11 + V_119 ) )
F_8 () ;
F_84 ( V_94 , V_7 ) ;
V_47 = V_116 - V_118 ;
if ( V_94 -> V_82 == V_111 )
V_94 -> V_112 += V_47 ;
#ifdef F_18
V_94 -> V_75 += V_47 ;
V_94 -> V_76 += V_47 ;
if ( F_85 ( V_7 ) )
V_94 -> V_33 += V_47 ;
#endif
return V_94 ;
}
int F_100 ( struct V_6 * V_7 , int V_121 )
{
int V_122 ;
int V_107 ;
if ( ! F_70 ( V_7 ) && F_101 ( V_7 ) >= V_121 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_121 ) ;
return 0 ;
}
V_107 = V_7 -> V_48 + V_121 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_24 ( F_70 ( V_7 ) || V_107 > 0 ) ) {
V_122 = F_93 ( V_7 , 0 , V_107 , V_49 ) ;
if ( F_58 ( V_122 ) )
goto V_123;
}
V_122 = F_102 ( V_7 ) ;
if ( F_58 ( V_122 ) )
goto V_123;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_121 ) ;
return 0 ;
V_123:
F_31 ( V_7 ) ;
return V_122 ;
}
unsigned char * F_88 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_124 = F_96 ( V_7 ) ;
F_103 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_58 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_62 ( 0 ) ) ;
return V_124 ;
}
unsigned char * F_104 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_58 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_62 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_105 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_106 ( V_7 , V_11 ) ;
}
void F_107 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_108 ( V_7 , V_11 ) ;
}
int F_109 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_125 ;
struct V_6 * V_126 ;
int V_101 = F_91 ( V_7 ) ;
int V_127 = F_19 ( V_7 ) -> V_58 ;
int V_46 ;
int V_122 ;
if ( F_70 ( V_7 ) &&
F_58 ( ( V_122 = F_93 ( V_7 , 0 , 0 , V_49 ) ) ) )
return V_122 ;
V_46 = 0 ;
if ( V_101 >= V_11 )
goto V_128;
for (; V_46 < V_127 ; V_46 ++ ) {
int V_15 = V_101 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( V_15 < V_11 ) {
V_101 = V_15 ;
continue;
}
F_19 ( V_7 ) -> V_59 [ V_46 ++ ] . V_18 = V_11 - V_101 ;
V_128:
F_19 ( V_7 ) -> V_58 = V_46 ;
for (; V_46 < V_127 ; V_46 ++ )
F_2 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
if ( F_38 ( V_7 ) )
F_32 ( V_7 ) ;
goto V_129;
}
for ( V_125 = & F_19 ( V_7 ) -> V_54 ; ( V_126 = * V_125 ) ;
V_125 = & V_126 -> V_53 ) {
int V_15 = V_101 + V_126 -> V_11 ;
if ( F_69 ( V_126 ) ) {
struct V_6 * V_130 ;
V_130 = F_82 ( V_126 , V_49 ) ;
if ( F_58 ( ! V_130 ) )
return - V_113 ;
V_130 -> V_53 = V_126 -> V_53 ;
F_31 ( V_126 ) ;
V_126 = V_130 ;
* V_125 = V_126 ;
}
if ( V_15 < V_11 ) {
V_101 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_58 ( ( V_122 = F_110 ( V_126 , V_11 - V_101 ) ) ) )
return V_122 ;
if ( V_126 -> V_53 )
F_30 ( & V_126 -> V_53 ) ;
break;
}
V_129:
if ( V_11 > F_91 ( V_7 ) ) {
V_7 -> V_48 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_48 = 0 ;
F_111 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_112 ( struct V_6 * V_7 , int V_109 )
{
int V_46 , V_131 , V_132 = ( V_7 -> V_14 + V_109 ) - V_7 -> V_15 ;
if ( V_132 > 0 || F_70 ( V_7 ) ) {
if ( F_93 ( V_7 , 0 , V_132 > 0 ? V_132 + 128 : 0 ,
V_49 ) )
return NULL ;
}
if ( F_89 ( V_7 , F_91 ( V_7 ) , F_96 ( V_7 ) , V_109 ) )
F_8 () ;
if ( ! F_38 ( V_7 ) )
goto V_133;
V_132 = V_109 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
if ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 >= V_132 )
goto V_133;
V_132 -= F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
}
if ( V_132 ) {
struct V_6 * V_51 = F_19 ( V_7 ) -> V_54 ;
struct V_6 * V_134 = NULL ;
struct V_6 * V_135 = NULL ;
do {
F_94 ( ! V_51 ) ;
if ( V_51 -> V_11 <= V_132 ) {
V_132 -= V_51 -> V_11 ;
V_51 = V_51 -> V_53 ;
V_135 = V_51 ;
} else {
if ( F_69 ( V_51 ) ) {
V_134 = F_82 ( V_51 , V_49 ) ;
if ( ! V_134 )
return NULL ;
V_135 = V_51 -> V_53 ;
V_51 = V_134 ;
} else {
V_135 = V_51 ;
}
if ( ! F_113 ( V_51 , V_132 ) ) {
F_31 ( V_134 ) ;
return NULL ;
}
break;
}
} while ( V_132 );
while ( ( V_51 = F_19 ( V_7 ) -> V_54 ) != V_135 ) {
F_19 ( V_7 ) -> V_54 = V_51 -> V_53 ;
F_31 ( V_51 ) ;
}
if ( V_134 ) {
V_134 -> V_53 = V_51 ;
F_19 ( V_7 ) -> V_54 = V_134 ;
}
}
V_133:
V_132 = V_109 ;
V_131 = 0 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
if ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 <= V_132 ) {
F_2 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
V_132 -= F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
} else {
F_19 ( V_7 ) -> V_59 [ V_131 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_132 ) {
F_19 ( V_7 ) -> V_59 [ V_131 ] . V_136 += V_132 ;
F_19 ( V_7 ) -> V_59 [ V_131 ] . V_18 -= V_132 ;
V_132 = 0 ;
}
V_131 ++ ;
}
}
F_19 ( V_7 ) -> V_58 = V_131 ;
V_7 -> V_14 += V_109 ;
V_7 -> V_48 -= V_109 ;
return F_96 ( V_7 ) ;
}
int F_89 ( const struct V_6 * V_7 , int V_101 , void * V_137 , int V_11 )
{
int V_138 = F_91 ( V_7 ) ;
struct V_6 * V_139 ;
int V_46 , V_140 ;
if ( V_101 > ( int ) V_7 -> V_11 - V_11 )
goto V_141;
if ( ( V_140 = V_138 - V_101 ) > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
F_114 ( V_7 , V_101 , V_137 , V_140 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return 0 ;
V_101 += V_140 ;
V_137 += V_140 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
T_2 * V_142 ;
if ( V_140 > V_11 )
V_140 = V_11 ;
V_142 = F_115 ( & F_19 ( V_7 ) -> V_59 [ V_46 ] ) ;
memcpy ( V_137 ,
V_142 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_136 +
V_101 - V_138 , V_140 ) ;
F_116 ( V_142 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return 0 ;
V_101 += V_140 ;
V_137 += V_140 ;
}
V_138 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + V_139 -> V_11 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
if ( F_89 ( V_139 , V_101 - V_138 , V_137 , V_140 ) )
goto V_141;
if ( ( V_11 -= V_140 ) == 0 )
return 0 ;
V_101 += V_140 ;
V_137 += V_140 ;
}
V_138 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_141:
return - V_143 ;
}
static void F_117 ( struct V_144 * V_145 , unsigned int V_46 )
{
F_2 ( V_145 -> V_146 [ V_46 ] ) ;
}
static inline struct V_5 * F_118 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_101 ,
struct V_6 * V_7 , struct V_147 * V_96 )
{
struct V_5 * V_148 = V_96 -> V_149 ;
unsigned int V_47 ;
if ( ! V_148 ) {
V_150:
V_148 = V_96 -> V_149 = F_119 ( V_96 -> V_151 , 0 ) ;
if ( ! V_148 )
return NULL ;
V_47 = V_96 -> V_152 = 0 ;
} else {
unsigned int V_153 ;
V_47 = V_96 -> V_152 ;
V_153 = V_154 - V_47 ;
if ( V_153 < 64 && V_153 < * V_11 ) {
F_2 ( V_148 ) ;
goto V_150;
}
* V_11 = F_120 (unsigned int, *len, mlen) ;
}
memcpy ( F_121 ( V_148 ) + V_47 , F_121 ( V_5 ) + * V_101 , * V_11 ) ;
V_96 -> V_152 += * V_11 ;
* V_101 = V_47 ;
F_4 ( V_148 ) ;
return V_148 ;
}
static inline int F_122 ( struct V_144 * V_145 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_101 ,
struct V_6 * V_7 , int V_155 ,
struct V_147 * V_96 )
{
if ( F_58 ( V_145 -> V_156 == V_2 -> V_157 ) )
return 1 ;
if ( V_155 ) {
V_5 = F_118 ( V_5 , V_11 , & V_101 , V_7 , V_96 ) ;
if ( ! V_5 )
return 1 ;
} else
F_4 ( V_5 ) ;
V_145 -> V_146 [ V_145 -> V_156 ] = V_5 ;
V_145 -> V_158 [ V_145 -> V_156 ] . V_11 = * V_11 ;
V_145 -> V_158 [ V_145 -> V_156 ] . V_101 = V_101 ;
V_145 -> V_156 ++ ;
return 0 ;
}
static inline void F_123 ( struct V_5 * * V_5 , unsigned int * V_159 ,
unsigned int * V_160 , unsigned int V_47 )
{
unsigned long V_94 ;
* V_159 += V_47 ;
V_94 = * V_159 / V_154 ;
if ( V_94 )
* V_5 = F_124 ( * V_5 , V_94 ) ;
* V_159 = * V_159 % V_154 ;
* V_160 -= V_47 ;
}
static inline int F_125 ( struct V_5 * V_5 , unsigned int V_159 ,
unsigned int V_160 , unsigned int * V_47 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_144 * V_145 , int V_155 ,
struct V_147 * V_96 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return 1 ;
if ( * V_47 >= V_160 ) {
* V_47 -= V_160 ;
return 0 ;
}
if ( * V_47 ) {
F_123 ( & V_5 , & V_159 , & V_160 , * V_47 ) ;
* V_47 = 0 ;
}
do {
unsigned int V_161 = F_126 ( * V_11 , V_160 ) ;
V_161 = F_120 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_122 ( V_145 , V_2 , V_5 , & V_161 , V_159 , V_7 , V_155 , V_96 ) )
return 1 ;
F_123 ( & V_5 , & V_159 , & V_160 , V_161 ) ;
* V_11 -= V_161 ;
} while ( * V_11 && V_160 );
return 0 ;
}
static int F_127 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_101 , unsigned int * V_11 ,
struct V_144 * V_145 , struct V_147 * V_96 )
{
int V_162 ;
if ( F_125 ( F_128 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_154 - 1 ) ,
F_91 ( V_7 ) ,
V_101 , V_11 , V_7 , V_145 , 1 , V_96 , V_2 ) )
return 1 ;
for ( V_162 = 0 ; V_162 < F_19 ( V_7 ) -> V_58 ; V_162 ++ ) {
const T_5 * V_163 = & F_19 ( V_7 ) -> V_59 [ V_162 ] ;
if ( F_125 ( V_163 -> V_5 , V_163 -> V_136 , V_163 -> V_18 ,
V_101 , V_11 , V_7 , V_145 , 0 , V_96 , V_2 ) )
return 1 ;
}
return 0 ;
}
int F_129 ( struct V_6 * V_7 , unsigned int V_101 ,
struct V_1 * V_2 , unsigned int V_164 ,
unsigned int V_165 )
{
struct V_166 V_158 [ V_167 ] ;
struct V_5 * V_146 [ V_167 ] ;
struct V_144 V_145 = {
. V_146 = V_146 ,
. V_158 = V_158 ,
. V_165 = V_165 ,
. V_168 = & V_169 ,
. V_170 = F_117 ,
} ;
struct V_6 * V_139 ;
struct V_147 * V_96 = V_7 -> V_96 ;
int V_171 = 0 ;
if ( F_130 ( V_2 , & V_145 ) )
return - V_113 ;
if ( F_127 ( V_7 , V_2 , & V_101 , & V_164 , & V_145 , V_96 ) )
goto V_129;
else if ( ! V_164 )
goto V_129;
F_34 (skb, frag_iter) {
if ( ! V_164 )
break;
if ( F_127 ( V_139 , V_2 , & V_101 , & V_164 , & V_145 , V_96 ) )
break;
}
V_129:
if ( V_145 . V_156 ) {
F_131 ( V_96 ) ;
V_171 = F_132 ( V_2 , & V_145 ) ;
F_133 ( V_96 ) ;
}
F_134 ( V_2 , & V_145 ) ;
return V_171 ;
}
int F_135 ( struct V_6 * V_7 , int V_101 , const void * V_172 , int V_11 )
{
int V_138 = F_91 ( V_7 ) ;
struct V_6 * V_139 ;
int V_46 , V_140 ;
if ( V_101 > ( int ) V_7 -> V_11 - V_11 )
goto V_141;
if ( ( V_140 = V_138 - V_101 ) > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
F_136 ( V_7 , V_101 , V_172 , V_140 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return 0 ;
V_101 += V_140 ;
V_172 += V_140 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
T_5 * V_126 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + V_126 -> V_18 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
T_2 * V_142 ;
if ( V_140 > V_11 )
V_140 = V_11 ;
V_142 = F_115 ( V_126 ) ;
memcpy ( V_142 + V_126 -> V_136 + V_101 - V_138 ,
V_172 , V_140 ) ;
F_116 ( V_142 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return 0 ;
V_101 += V_140 ;
V_172 += V_140 ;
}
V_138 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + V_139 -> V_11 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
if ( F_135 ( V_139 , V_101 - V_138 ,
V_172 , V_140 ) )
goto V_141;
if ( ( V_11 -= V_140 ) == 0 )
return 0 ;
V_101 += V_140 ;
V_172 += V_140 ;
}
V_138 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_141:
return - V_143 ;
}
T_6 F_137 ( const struct V_6 * V_7 , int V_101 ,
int V_11 , T_6 V_79 )
{
int V_138 = F_91 ( V_7 ) ;
int V_46 , V_140 = V_138 - V_101 ;
struct V_6 * V_139 ;
int V_173 = 0 ;
if ( V_140 > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
V_79 = F_138 ( V_7 -> V_13 + V_101 , V_140 , V_79 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return V_79 ;
V_101 += V_140 ;
V_173 = V_140 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
T_6 V_174 ;
T_2 * V_142 ;
T_5 * V_126 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_140 > V_11 )
V_140 = V_11 ;
V_142 = F_115 ( V_126 ) ;
V_174 = F_138 ( V_142 + V_126 -> V_136 +
V_101 - V_138 , V_140 , 0 ) ;
F_116 ( V_142 ) ;
V_79 = F_139 ( V_79 , V_174 , V_173 ) ;
if ( ! ( V_11 -= V_140 ) )
return V_79 ;
V_101 += V_140 ;
V_173 += V_140 ;
}
V_138 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + V_139 -> V_11 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
T_6 V_174 ;
if ( V_140 > V_11 )
V_140 = V_11 ;
V_174 = F_137 ( V_139 , V_101 - V_138 ,
V_140 , 0 ) ;
V_79 = F_139 ( V_79 , V_174 , V_173 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return V_79 ;
V_101 += V_140 ;
V_173 += V_140 ;
}
V_138 = V_15 ;
}
F_94 ( V_11 ) ;
return V_79 ;
}
T_6 F_140 ( const struct V_6 * V_7 , int V_101 ,
T_2 * V_137 , int V_11 , T_6 V_79 )
{
int V_138 = F_91 ( V_7 ) ;
int V_46 , V_140 = V_138 - V_101 ;
struct V_6 * V_139 ;
int V_173 = 0 ;
if ( V_140 > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
V_79 = F_141 ( V_7 -> V_13 + V_101 , V_137 ,
V_140 , V_79 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return V_79 ;
V_101 += V_140 ;
V_137 += V_140 ;
V_173 = V_140 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
T_6 V_174 ;
T_2 * V_142 ;
T_5 * V_126 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_140 > V_11 )
V_140 = V_11 ;
V_142 = F_115 ( V_126 ) ;
V_174 = F_141 ( V_142 +
V_126 -> V_136 +
V_101 - V_138 , V_137 ,
V_140 , 0 ) ;
F_116 ( V_142 ) ;
V_79 = F_139 ( V_79 , V_174 , V_173 ) ;
if ( ! ( V_11 -= V_140 ) )
return V_79 ;
V_101 += V_140 ;
V_137 += V_140 ;
V_173 += V_140 ;
}
V_138 = V_15 ;
}
F_34 (skb, frag_iter) {
T_6 V_174 ;
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + V_139 -> V_11 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
V_174 = F_140 ( V_139 ,
V_101 - V_138 ,
V_137 , V_140 , 0 ) ;
V_79 = F_139 ( V_79 , V_174 , V_173 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return V_79 ;
V_101 += V_140 ;
V_137 += V_140 ;
V_173 += V_140 ;
}
V_138 = V_15 ;
}
F_94 ( V_11 ) ;
return V_79 ;
}
void F_142 ( const struct V_6 * V_7 , T_2 * V_137 )
{
T_6 V_79 ;
long V_175 ;
if ( V_7 -> V_82 == V_111 )
V_175 = F_143 ( V_7 ) ;
else
V_175 = F_91 ( V_7 ) ;
F_94 ( V_175 > F_91 ( V_7 ) ) ;
F_92 ( V_7 , V_137 , V_175 ) ;
V_79 = 0 ;
if ( V_175 != V_7 -> V_11 )
V_79 = F_140 ( V_7 , V_175 , V_137 + V_175 ,
V_7 -> V_11 - V_175 , 0 ) ;
if ( V_7 -> V_82 == V_111 ) {
long V_176 = V_175 + V_7 -> V_177 ;
* ( ( V_178 * ) ( V_137 + V_176 ) ) = F_144 ( V_79 ) ;
}
}
struct V_6 * F_145 ( struct V_179 * V_51 )
{
unsigned long V_165 ;
struct V_6 * V_180 ;
F_146 ( & V_51 -> V_181 , V_165 ) ;
V_180 = F_147 ( V_51 ) ;
F_148 ( & V_51 -> V_181 , V_165 ) ;
return V_180 ;
}
struct V_6 * F_149 ( struct V_179 * V_51 )
{
unsigned long V_165 ;
struct V_6 * V_180 ;
F_146 ( & V_51 -> V_181 , V_165 ) ;
V_180 = F_150 ( V_51 ) ;
F_148 ( & V_51 -> V_181 , V_165 ) ;
return V_180 ;
}
void F_151 ( struct V_179 * V_51 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_145 ( V_51 ) ) != NULL )
F_31 ( V_7 ) ;
}
void F_152 ( struct V_179 * V_51 , struct V_6 * V_182 )
{
unsigned long V_165 ;
F_146 ( & V_51 -> V_181 , V_165 ) ;
F_153 ( V_51 , V_182 ) ;
F_148 ( & V_51 -> V_181 , V_165 ) ;
}
void F_154 ( struct V_179 * V_51 , struct V_6 * V_182 )
{
unsigned long V_165 ;
F_146 ( & V_51 -> V_181 , V_165 ) ;
F_155 ( V_51 , V_182 ) ;
F_148 ( & V_51 -> V_181 , V_165 ) ;
}
void F_156 ( struct V_6 * V_7 , struct V_179 * V_51 )
{
unsigned long V_165 ;
F_146 ( & V_51 -> V_181 , V_165 ) ;
F_157 ( V_7 , V_51 ) ;
F_148 ( & V_51 -> V_181 , V_165 ) ;
}
void F_158 ( struct V_6 * V_73 , struct V_6 * V_182 , struct V_179 * V_51 )
{
unsigned long V_165 ;
F_146 ( & V_51 -> V_181 , V_165 ) ;
F_159 ( V_51 , V_73 , V_182 ) ;
F_148 ( & V_51 -> V_181 , V_165 ) ;
}
void F_160 ( struct V_6 * V_73 , struct V_6 * V_182 , struct V_179 * V_51 )
{
unsigned long V_165 ;
F_146 ( & V_51 -> V_181 , V_165 ) ;
F_161 ( V_182 , V_73 -> V_95 , V_73 , V_51 ) ;
F_148 ( & V_51 -> V_181 , V_165 ) ;
}
static inline void F_162 ( struct V_6 * V_7 ,
struct V_6 * V_183 ,
const T_7 V_11 , const int V_173 )
{
int V_46 ;
F_114 ( V_7 , V_11 , F_88 ( V_183 , V_173 - V_11 ) ,
V_173 - V_11 ) ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ )
F_19 ( V_183 ) -> V_59 [ V_46 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
F_19 ( V_183 ) -> V_58 = F_19 ( V_7 ) -> V_58 ;
F_19 ( V_7 ) -> V_58 = 0 ;
V_183 -> V_48 = V_7 -> V_48 ;
V_183 -> V_11 += V_183 -> V_48 ;
V_7 -> V_48 = 0 ;
V_7 -> V_11 = V_11 ;
F_111 ( V_7 , V_11 ) ;
}
static inline void F_163 ( struct V_6 * V_7 ,
struct V_6 * V_183 ,
const T_7 V_11 , int V_173 )
{
int V_46 , V_131 = 0 ;
const int V_127 = F_19 ( V_7 ) -> V_58 ;
F_19 ( V_7 ) -> V_58 = 0 ;
V_183 -> V_11 = V_183 -> V_48 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_48 = V_11 - V_173 ;
for ( V_46 = 0 ; V_46 < V_127 ; V_46 ++ ) {
int V_18 = F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( V_173 + V_18 > V_11 ) {
F_19 ( V_183 ) -> V_59 [ V_131 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_173 < V_11 ) {
F_4 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
F_19 ( V_183 ) -> V_59 [ 0 ] . V_136 += V_11 - V_173 ;
F_19 ( V_183 ) -> V_59 [ 0 ] . V_18 -= V_11 - V_173 ;
F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 = V_11 - V_173 ;
F_19 ( V_7 ) -> V_58 ++ ;
}
V_131 ++ ;
} else
F_19 ( V_7 ) -> V_58 ++ ;
V_173 += V_18 ;
}
F_19 ( V_183 ) -> V_58 = V_131 ;
}
void F_164 ( struct V_6 * V_7 , struct V_6 * V_183 , const T_7 V_11 )
{
int V_173 = F_91 ( V_7 ) ;
if ( V_11 < V_173 )
F_162 ( V_7 , V_183 , V_11 , V_173 ) ;
else
F_163 ( V_7 , V_183 , V_11 , V_173 ) ;
}
static int F_165 ( struct V_6 * V_7 )
{
return F_70 ( V_7 ) && F_93 ( V_7 , 0 , 0 , V_49 ) ;
}
int F_166 ( struct V_6 * V_184 , struct V_6 * V_7 , int V_185 )
{
int V_172 , V_137 , V_186 , V_187 ;
struct V_188 * V_189 , * V_190 ;
F_94 ( V_185 > V_7 -> V_11 ) ;
F_94 ( F_91 ( V_7 ) ) ;
V_187 = V_185 ;
V_172 = 0 ;
V_137 = F_19 ( V_184 ) -> V_58 ;
V_189 = & F_19 ( V_7 ) -> V_59 [ V_172 ] ;
if ( ! V_137 ||
! F_167 ( V_184 , V_137 , V_189 -> V_5 , V_189 -> V_136 ) ) {
V_186 = - 1 ;
} else {
V_186 = V_137 - 1 ;
V_187 -= V_189 -> V_18 ;
if ( V_187 < 0 ) {
if ( F_165 ( V_7 ) ||
F_165 ( V_184 ) )
return 0 ;
V_189 = & F_19 ( V_7 ) -> V_59 [ V_172 ] ;
V_190 = & F_19 ( V_184 ) -> V_59 [ V_186 ] ;
V_190 -> V_18 += V_185 ;
V_189 -> V_18 -= V_185 ;
V_189 -> V_136 += V_185 ;
goto V_191;
}
V_172 ++ ;
}
if ( ( V_185 == V_7 -> V_11 ) &&
( F_19 ( V_7 ) -> V_58 - V_172 ) > ( V_192 - V_137 ) )
return 0 ;
if ( F_165 ( V_7 ) || F_165 ( V_184 ) )
return 0 ;
while ( ( V_187 > 0 ) && ( V_172 < F_19 ( V_7 ) -> V_58 ) ) {
if ( V_137 == V_192 )
return 0 ;
V_189 = & F_19 ( V_7 ) -> V_59 [ V_172 ] ;
V_190 = & F_19 ( V_184 ) -> V_59 [ V_137 ] ;
if ( V_187 >= V_189 -> V_18 ) {
* V_190 = * V_189 ;
V_187 -= V_189 -> V_18 ;
V_172 ++ ;
V_137 ++ ;
} else {
F_4 ( V_189 -> V_5 ) ;
V_190 -> V_5 = V_189 -> V_5 ;
V_190 -> V_136 = V_189 -> V_136 ;
V_190 -> V_18 = V_187 ;
V_189 -> V_136 += V_187 ;
V_189 -> V_18 -= V_187 ;
V_187 = 0 ;
V_137 ++ ;
break;
}
}
F_19 ( V_184 ) -> V_58 = V_137 ;
if ( V_186 >= 0 ) {
V_189 = & F_19 ( V_7 ) -> V_59 [ 0 ] ;
V_190 = & F_19 ( V_184 ) -> V_59 [ V_186 ] ;
V_190 -> V_18 += V_189 -> V_18 ;
F_2 ( V_189 -> V_5 ) ;
}
V_137 = 0 ;
while ( V_172 < F_19 ( V_7 ) -> V_58 )
F_19 ( V_7 ) -> V_59 [ V_137 ++ ] = F_19 ( V_7 ) -> V_59 [ V_172 ++ ] ;
F_19 ( V_7 ) -> V_58 = V_137 ;
F_94 ( V_187 > 0 && ! F_19 ( V_7 ) -> V_58 ) ;
V_191:
V_184 -> V_82 = V_111 ;
V_7 -> V_82 = V_111 ;
V_7 -> V_11 -= V_185 ;
V_7 -> V_48 -= V_185 ;
V_7 -> V_31 -= V_185 ;
V_184 -> V_11 += V_185 ;
V_184 -> V_48 += V_185 ;
V_184 -> V_31 += V_185 ;
return V_185 ;
}
void F_168 ( struct V_6 * V_7 , unsigned int V_172 ,
unsigned int V_137 , struct V_193 * V_194 )
{
V_194 -> V_195 = V_172 ;
V_194 -> V_196 = V_137 ;
V_194 -> V_197 = V_194 -> V_198 = V_7 ;
V_194 -> V_199 = V_194 -> V_200 = 0 ;
V_194 -> V_201 = NULL ;
}
unsigned int F_169 ( unsigned int V_202 , const T_2 * * V_13 ,
struct V_193 * V_194 )
{
unsigned int V_203 , V_204 = V_202 + V_194 -> V_195 ;
T_5 * V_126 ;
if ( F_58 ( V_204 >= V_194 -> V_196 ) )
return 0 ;
V_205:
V_203 = F_91 ( V_194 -> V_198 ) + V_194 -> V_200 ;
if ( V_204 < V_203 && ! V_194 -> V_201 ) {
* V_13 = V_194 -> V_198 -> V_13 + ( V_204 - V_194 -> V_200 ) ;
return V_203 - V_204 ;
}
if ( V_194 -> V_199 == 0 && ! V_194 -> V_201 )
V_194 -> V_200 += F_91 ( V_194 -> V_198 ) ;
while ( V_194 -> V_199 < F_19 ( V_194 -> V_198 ) -> V_58 ) {
V_126 = & F_19 ( V_194 -> V_198 ) -> V_59 [ V_194 -> V_199 ] ;
V_203 = V_126 -> V_18 + V_194 -> V_200 ;
if ( V_204 < V_203 ) {
if ( ! V_194 -> V_201 )
V_194 -> V_201 = F_115 ( V_126 ) ;
* V_13 = ( T_2 * ) V_194 -> V_201 + V_126 -> V_136 +
( V_204 - V_194 -> V_200 ) ;
return V_203 - V_204 ;
}
if ( V_194 -> V_201 ) {
F_116 ( V_194 -> V_201 ) ;
V_194 -> V_201 = NULL ;
}
V_194 -> V_199 ++ ;
V_194 -> V_200 += V_126 -> V_18 ;
}
if ( V_194 -> V_201 ) {
F_116 ( V_194 -> V_201 ) ;
V_194 -> V_201 = NULL ;
}
if ( V_194 -> V_197 == V_194 -> V_198 && F_38 ( V_194 -> V_197 ) ) {
V_194 -> V_198 = F_19 ( V_194 -> V_197 ) -> V_54 ;
V_194 -> V_199 = 0 ;
goto V_205;
} else if ( V_194 -> V_198 -> V_53 ) {
V_194 -> V_198 = V_194 -> V_198 -> V_53 ;
V_194 -> V_199 = 0 ;
goto V_205;
}
return 0 ;
}
void F_170 ( struct V_193 * V_194 )
{
if ( V_194 -> V_201 )
F_116 ( V_194 -> V_201 ) ;
}
static unsigned int F_171 ( unsigned int V_101 , const T_2 * * V_206 ,
struct V_207 * V_208 ,
struct V_209 * V_210 )
{
return F_169 ( V_101 , V_206 , F_172 ( V_210 ) ) ;
}
static void F_173 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
F_170 ( F_172 ( V_210 ) ) ;
}
unsigned int F_174 ( struct V_6 * V_7 , unsigned int V_172 ,
unsigned int V_137 , struct V_207 * V_211 ,
struct V_209 * V_210 )
{
unsigned int V_171 ;
V_211 -> V_212 = F_171 ;
V_211 -> V_213 = F_173 ;
F_168 ( V_7 , V_172 , V_137 , F_172 ( V_210 ) ) ;
V_171 = F_175 ( V_211 , V_210 ) ;
return ( V_171 <= V_137 - V_172 ? V_171 : V_214 ) ;
}
int F_176 ( struct V_147 * V_96 , struct V_6 * V_7 ,
int (* F_177)( void * V_172 , char * V_137 , int V_101 ,
int V_11 , int V_215 , struct V_6 * V_7 ) ,
void * V_172 , int V_43 )
{
int V_216 = 0 ;
T_5 * V_126 = NULL ;
struct V_5 * V_5 = NULL ;
int V_140 , V_217 ;
int V_101 = 0 ;
int V_171 ;
do {
V_216 = F_19 ( V_7 ) -> V_58 ;
if ( V_216 >= V_192 )
return - V_143 ;
V_5 = F_119 ( V_96 -> V_151 , 0 ) ;
if ( V_5 == NULL )
return - V_113 ;
F_27 ( V_7 , V_216 , V_5 , 0 , 0 ) ;
V_7 -> V_31 += V_154 ;
F_178 ( V_154 , & V_96 -> V_218 ) ;
V_216 = F_19 ( V_7 ) -> V_58 ;
V_126 = & F_19 ( V_7 ) -> V_59 [ V_216 - 1 ] ;
V_217 = V_154 - V_126 -> V_136 ;
V_140 = ( V_43 > V_217 ) ? V_217 : V_43 ;
V_171 = F_177 ( V_172 , ( F_121 ( V_126 -> V_5 ) +
V_126 -> V_136 + V_126 -> V_18 ) ,
V_101 , V_140 , 0 , V_7 ) ;
if ( V_171 < 0 )
return - V_143 ;
V_126 -> V_18 += V_140 ;
V_7 -> V_11 += V_140 ;
V_7 -> V_48 += V_140 ;
V_101 += V_140 ;
V_43 -= V_140 ;
} while ( V_43 > 0 );
return 0 ;
}
unsigned char * F_179 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_94 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_94 ( V_7 -> V_11 < V_7 -> V_48 ) ;
F_180 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_181 ( struct V_6 * V_7 , T_7 V_219 )
{
struct V_6 * V_220 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_221 = F_19 ( V_7 ) -> V_54 ;
unsigned int V_222 = F_19 ( V_7 ) -> V_102 ;
unsigned int V_223 = V_7 -> V_13 - F_182 ( V_7 ) ;
unsigned int V_101 = V_223 ;
unsigned int V_114 ;
unsigned int V_11 ;
int V_224 = ! ! ( V_219 & V_225 ) ;
int V_127 = F_19 ( V_7 ) -> V_58 ;
int V_122 = - V_113 ;
int V_46 = 0 ;
int V_173 ;
F_183 ( V_7 , V_223 ) ;
V_114 = F_79 ( V_7 ) ;
V_173 = F_91 ( V_7 ) ;
do {
struct V_6 * V_226 ;
T_5 * V_126 ;
int V_227 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_101 ;
if ( V_11 > V_222 )
V_11 = V_222 ;
V_227 = F_91 ( V_7 ) - V_101 ;
if ( V_227 < 0 )
V_227 = 0 ;
if ( V_227 > V_11 || ! V_224 )
V_227 = V_11 ;
if ( ! V_227 && V_46 >= V_127 ) {
F_94 ( V_221 -> V_11 != V_11 ) ;
V_173 += V_11 ;
V_226 = F_82 ( V_221 , V_49 ) ;
V_221 = V_221 -> V_53 ;
if ( F_58 ( ! V_226 ) )
goto V_122;
V_227 = F_68 ( V_226 ) - V_226 -> V_12 ;
if ( F_184 ( V_226 , V_223 + V_114 ) ) {
F_31 ( V_226 ) ;
goto V_122;
}
V_226 -> V_31 += F_68 ( V_226 ) - V_226 -> V_12 -
V_227 ;
F_42 ( V_226 ) ;
F_183 ( V_226 , V_223 ) ;
} else {
V_226 = F_87 ( V_227 + V_223 + V_114 ,
V_49 ) ;
if ( F_58 ( ! V_226 ) )
goto V_122;
F_25 ( V_226 , V_114 ) ;
F_185 ( V_226 , V_223 ) ;
}
if ( V_220 )
V_14 -> V_53 = V_226 ;
else
V_220 = V_226 ;
V_14 = V_226 ;
F_71 ( V_226 , V_7 ) ;
V_226 -> V_97 = V_7 -> V_97 ;
if ( V_226 -> V_82 == V_111 )
V_226 -> V_112 += F_79 ( V_226 ) - V_114 ;
F_186 ( V_226 ) ;
F_187 ( V_226 , V_7 -> V_97 ) ;
V_226 -> V_75 = ( V_226 -> V_76 +
F_188 ( V_7 ) ) ;
F_92 ( V_7 , V_226 -> V_13 , V_223 ) ;
if ( V_221 != F_19 ( V_7 ) -> V_54 )
continue;
if ( ! V_224 ) {
V_226 -> V_82 = V_228 ;
V_226 -> V_79 = F_140 ( V_7 , V_101 ,
F_88 ( V_226 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_126 = F_19 ( V_226 ) -> V_59 ;
F_114 ( V_7 , V_101 ,
F_88 ( V_226 , V_227 ) , V_227 ) ;
while ( V_173 < V_101 + V_11 && V_46 < V_127 ) {
* V_126 = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
F_4 ( V_126 -> V_5 ) ;
V_18 = V_126 -> V_18 ;
if ( V_173 < V_101 ) {
V_126 -> V_136 += V_101 - V_173 ;
V_126 -> V_18 -= V_101 - V_173 ;
}
F_19 ( V_226 ) -> V_58 ++ ;
if ( V_173 + V_18 <= V_101 + V_11 ) {
V_46 ++ ;
V_173 += V_18 ;
} else {
V_126 -> V_18 -= V_173 + V_18 - ( V_101 + V_11 ) ;
goto V_229;
}
V_126 ++ ;
}
if ( V_173 < V_101 + V_11 ) {
struct V_6 * V_230 = V_221 ;
F_94 ( V_173 + V_221 -> V_11 != V_101 + V_11 ) ;
V_173 += V_221 -> V_11 ;
V_221 = V_221 -> V_53 ;
if ( V_230 -> V_53 ) {
V_230 = F_82 ( V_230 , V_49 ) ;
if ( ! V_230 )
goto V_122;
} else
F_35 ( V_230 ) ;
F_189 ( V_226 ) ;
F_19 ( V_226 ) -> V_54 = V_230 ;
}
V_229:
V_226 -> V_48 = V_11 - V_227 ;
V_226 -> V_11 += V_226 -> V_48 ;
V_226 -> V_31 += V_226 -> V_48 ;
} while ( ( V_101 += V_11 ) < V_7 -> V_11 );
return V_220 ;
V_122:
while ( ( V_7 = V_220 ) ) {
V_220 = V_7 -> V_53 ;
F_31 ( V_7 ) ;
}
return F_190 ( V_122 ) ;
}
int F_191 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_148 = * V_12 ;
struct V_6 * V_226 ;
struct V_24 * V_231 = F_19 ( V_7 ) ;
struct V_24 * V_232 = F_19 ( V_148 ) ;
unsigned int V_114 ;
unsigned int V_11 = F_192 ( V_7 ) ;
unsigned int V_101 = F_193 ( V_7 ) ;
unsigned int V_233 = F_91 ( V_7 ) ;
if ( V_148 -> V_11 + V_11 >= 65536 )
return - V_234 ;
if ( V_232 -> V_54 )
goto V_186;
else if ( V_233 <= V_101 ) {
T_5 * V_126 ;
T_5 * V_235 ;
int V_46 = V_231 -> V_58 ;
int V_58 = V_232 -> V_58 + V_46 ;
V_101 -= V_233 ;
if ( V_58 > V_192 )
return - V_234 ;
V_232 -> V_58 = V_58 ;
V_231 -> V_58 = 0 ;
V_126 = V_232 -> V_59 + V_58 ;
V_235 = V_231 -> V_59 + V_46 ;
do {
* -- V_126 = * -- V_235 ;
} while ( -- V_46 );
V_126 -> V_136 += V_101 ;
V_126 -> V_18 -= V_101 ;
V_7 -> V_31 -= V_7 -> V_48 ;
V_7 -> V_11 -= V_7 -> V_48 ;
V_7 -> V_48 = 0 ;
F_194 ( V_7 ) -> free = 1 ;
goto V_129;
} else if ( F_192 ( V_148 ) != V_232 -> V_102 )
return - V_234 ;
V_114 = F_79 ( V_148 ) ;
V_226 = F_87 ( V_114 + F_193 ( V_148 ) , V_49 ) ;
if ( F_58 ( ! V_226 ) )
return - V_113 ;
F_71 ( V_226 , V_148 ) ;
V_226 -> V_97 = V_148 -> V_97 ;
F_25 ( V_226 , V_114 ) ;
F_185 ( V_226 , F_193 ( V_148 ) ) ;
F_195 ( V_226 , F_182 ( V_148 ) - V_148 -> V_13 ) ;
F_187 ( V_226 , F_196 ( V_148 ) ) ;
F_197 ( V_226 , F_198 ( V_148 ) ) ;
F_199 ( V_148 , F_193 ( V_148 ) ) ;
memcpy ( F_182 ( V_226 ) , F_182 ( V_148 ) ,
V_148 -> V_13 - F_182 ( V_148 ) ) ;
* F_194 ( V_226 ) = * F_194 ( V_148 ) ;
F_19 ( V_226 ) -> V_54 = V_148 ;
F_19 ( V_226 ) -> V_102 = V_232 -> V_102 ;
V_232 -> V_102 = 0 ;
F_200 ( V_148 ) ;
V_226 -> V_95 = V_148 ;
V_226 -> V_48 += V_148 -> V_11 ;
V_226 -> V_31 += V_148 -> V_11 ;
V_226 -> V_11 += V_148 -> V_11 ;
* V_12 = V_226 ;
V_226 -> V_53 = V_148 -> V_53 ;
V_148 -> V_53 = NULL ;
V_148 = V_226 ;
V_186:
if ( V_101 > V_233 ) {
unsigned int V_132 = V_101 - V_233 ;
V_231 -> V_59 [ 0 ] . V_136 += V_132 ;
V_231 -> V_59 [ 0 ] . V_18 -= V_132 ;
V_7 -> V_48 -= V_132 ;
V_7 -> V_11 -= V_132 ;
V_101 = V_233 ;
}
F_199 ( V_7 , V_101 ) ;
V_148 -> V_95 -> V_53 = V_7 ;
V_148 -> V_95 = V_7 ;
F_200 ( V_7 ) ;
V_129:
F_194 ( V_148 ) -> V_236 ++ ;
V_148 -> V_48 += V_11 ;
V_148 -> V_31 += V_11 ;
V_148 -> V_11 += V_11 ;
F_194 ( V_7 ) -> V_237 = 1 ;
return 0 ;
}
void T_8 F_201 ( void )
{
V_27 = F_202 ( L_5 ,
sizeof( struct V_6 ) ,
0 ,
V_238 | V_239 ,
NULL ) ;
V_26 = F_202 ( L_6 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_3 ) ,
0 ,
V_238 | V_239 ,
NULL ) ;
}
static int
F_203 ( struct V_6 * V_7 , struct V_240 * V_224 , int V_101 , int V_11 )
{
int V_138 = F_91 ( V_7 ) ;
int V_46 , V_140 = V_138 - V_101 ;
struct V_6 * V_139 ;
int V_241 = 0 ;
if ( V_140 > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
F_204 ( V_224 , V_7 -> V_13 + V_101 , V_140 ) ;
V_241 ++ ;
if ( ( V_11 -= V_140 ) == 0 )
return V_241 ;
V_101 += V_140 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
T_5 * V_126 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_140 > V_11 )
V_140 = V_11 ;
F_205 ( & V_224 [ V_241 ] , V_126 -> V_5 , V_140 ,
V_126 -> V_136 + V_101 - V_138 ) ;
V_241 ++ ;
if ( ! ( V_11 -= V_140 ) )
return V_241 ;
V_101 += V_140 ;
}
V_138 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_138 > V_101 + V_11 ) ;
V_15 = V_138 + V_139 -> V_11 ;
if ( ( V_140 = V_15 - V_101 ) > 0 ) {
if ( V_140 > V_11 )
V_140 = V_11 ;
V_241 += F_203 ( V_139 , V_224 + V_241 , V_101 - V_138 ,
V_140 ) ;
if ( ( V_11 -= V_140 ) == 0 )
return V_241 ;
V_101 += V_140 ;
}
V_138 = V_15 ;
}
F_94 ( V_11 ) ;
return V_241 ;
}
int F_206 ( struct V_6 * V_7 , struct V_240 * V_224 , int V_101 , int V_11 )
{
int V_242 = F_203 ( V_7 , V_224 , V_101 , V_11 ) ;
F_207 ( & V_224 [ V_242 - 1 ] ) ;
return V_242 ;
}
int F_208 ( struct V_6 * V_7 , int V_243 , struct V_6 * * V_244 )
{
int V_245 ;
int V_241 ;
struct V_6 * V_183 , * * V_246 ;
if ( ( F_70 ( V_7 ) || F_19 ( V_7 ) -> V_58 ) &&
F_112 ( V_7 , F_209 ( V_7 ) - F_91 ( V_7 ) ) == NULL )
return - V_113 ;
if ( ! F_38 ( V_7 ) ) {
if ( F_101 ( V_7 ) < V_243 &&
F_93 ( V_7 , 0 , V_243 - F_101 ( V_7 ) + 128 , V_49 ) )
return - V_113 ;
* V_244 = V_7 ;
return 1 ;
}
V_241 = 1 ;
V_246 = & F_19 ( V_7 ) -> V_54 ;
V_245 = 0 ;
while ( ( V_183 = * V_246 ) != NULL ) {
int V_107 = 0 ;
if ( F_69 ( V_183 ) )
V_245 = 1 ;
if ( V_183 -> V_53 == NULL && V_243 ) {
if ( F_19 ( V_183 ) -> V_58 ||
F_38 ( V_183 ) ||
F_101 ( V_183 ) < V_243 )
V_107 = V_243 + 128 ;
}
if ( V_245 ||
F_70 ( V_183 ) ||
V_107 ||
F_19 ( V_183 ) -> V_58 ||
F_38 ( V_183 ) ) {
struct V_6 * V_115 ;
if ( V_107 == 0 )
V_115 = F_86 ( V_183 , V_49 ) ;
else
V_115 = F_99 ( V_183 ,
F_79 ( V_183 ) ,
V_107 ,
V_49 ) ;
if ( F_58 ( V_115 == NULL ) )
return - V_113 ;
if ( V_183 -> V_96 )
F_210 ( V_115 , V_183 -> V_96 ) ;
V_115 -> V_53 = V_183 -> V_53 ;
* V_246 = V_115 ;
F_31 ( V_183 ) ;
V_183 = V_115 ;
}
V_241 ++ ;
* V_244 = V_183 ;
V_246 = & V_183 -> V_53 ;
}
return V_241 ;
}
static void F_211 ( struct V_6 * V_7 )
{
struct V_147 * V_96 = V_7 -> V_96 ;
F_212 ( V_7 -> V_31 , & V_96 -> V_247 ) ;
}
int F_213 ( struct V_147 * V_96 , struct V_6 * V_7 )
{
if ( F_59 ( & V_96 -> V_247 ) + V_7 -> V_31 >=
( unsigned ) V_96 -> V_248 )
return - V_113 ;
F_214 ( V_7 ) ;
V_7 -> V_96 = V_96 ;
V_7 -> V_63 = F_211 ;
F_178 ( V_7 -> V_31 , & V_96 -> V_247 ) ;
F_215 ( V_7 ) ;
F_154 ( & V_96 -> V_249 , V_7 ) ;
if ( ! F_216 ( V_96 , V_250 ) )
V_96 -> V_251 ( V_96 , V_7 -> V_11 ) ;
return 0 ;
}
void F_217 ( struct V_6 * V_252 ,
struct V_253 * V_254 )
{
struct V_147 * V_96 = V_252 -> V_96 ;
struct V_255 * V_256 ;
struct V_6 * V_7 ;
int V_122 ;
if ( ! V_96 )
return;
V_7 = F_82 ( V_252 , V_49 ) ;
if ( ! V_7 )
return;
if ( V_254 ) {
* F_218 ( V_7 ) =
* V_254 ;
} else {
V_7 -> V_74 = F_219 () ;
}
V_256 = F_220 ( V_7 ) ;
memset ( V_256 , 0 , sizeof( * V_256 ) ) ;
V_256 -> V_257 . V_258 = V_259 ;
V_256 -> V_257 . V_260 = V_261 ;
V_122 = F_213 ( V_96 , V_7 ) ;
if ( V_122 )
F_31 ( V_7 ) ;
}
bool F_221 ( struct V_6 * V_7 , T_9 V_138 , T_9 V_47 )
{
if ( F_58 ( V_138 > F_91 ( V_7 ) ) ||
F_58 ( ( int ) V_138 + V_47 > F_91 ( V_7 ) - 2 ) ) {
if ( F_222 () )
F_7 ( V_262
L_7 ,
V_138 , V_47 , F_91 ( V_7 ) ) ;
return false ;
}
V_7 -> V_82 = V_111 ;
V_7 -> V_112 = F_79 ( V_7 ) + V_138 ;
V_7 -> V_177 = V_47 ;
return true ;
}
void F_223 ( const struct V_6 * V_7 )
{
if ( F_222 () )
F_224 ( L_8
L_9 , V_7 -> V_16 -> V_17 ) ;
}
