static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return F_3 ( int , F_3 ( int , V_2 -> V_8 & V_9 , V_10 ) -
V_6 -> V_11 , 0 ) ;
}
static inline bool F_4 ( struct V_1 * V_2 )
{
return V_10 <= F_1 ( V_2 ) ;
}
static inline bool F_5 ( struct V_5 * V_6 )
{
unsigned V_12 = F_6 ( F_7 ( & V_6 -> V_13 ) ) ;
return V_6 -> V_11 >= V_6 -> V_14 + V_12 ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = & V_6 -> V_17 ;
F_9 ( V_16 -> V_18 , V_19 ) ;
V_16 -> V_20 = 0 ;
V_6 -> V_11 = 0 ;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_15 * V_16 = & V_6 -> V_17 ;
struct V_23 * V_18 = V_16 -> V_18 ;
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_16 -> V_20 ; V_24 ++ ) {
if ( ! F_11 ( V_18 + V_24 ) )
continue;
F_12 ( F_11 ( V_18 + V_24 ) ) ;
F_13 ( V_18 + V_24 , NULL ) ;
}
F_8 ( V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ! F_4 ( V_2 ) )
return;
F_15 () ;
V_26 = F_16 ( V_2 -> V_27 ) ;
if ( F_17 ( V_26 ) )
F_18 ( & V_26 -> V_28 , V_29 |
V_30 |
V_31 ) ;
F_19 ( V_2 , V_32 , V_33 ) ;
F_20 () ;
}
static int F_21 ( struct V_1 * V_2 , unsigned V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
long V_35 ;
F_22 ( V_28 ) ;
int V_36 = - V_37 ;
if ( V_34 & V_38 )
return - V_39 ;
F_23 ( V_40 , V_2 ) ;
for (; ; ) {
if ( F_24 ( V_41 ) )
break;
F_25 ( F_26 ( V_2 ) , & V_28 , V_42 ) ;
V_35 = V_43 ;
if ( F_27 ( V_2 , & V_35 , ! V_6 -> V_21 ) ) {
V_36 = 0 ;
break;
}
}
F_28 ( F_26 ( V_2 ) , & V_28 ) ;
F_29 ( V_40 , V_2 ) ;
return V_36 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_25 * V_26 ;
if ( V_6 -> V_21 )
return;
if ( ! V_6 -> V_11 )
return;
F_15 () ;
V_26 = F_16 ( V_2 -> V_27 ) ;
if ( F_17 ( V_26 ) )
F_18 ( & V_26 -> V_28 , V_44 |
V_30 |
V_31 ) ;
F_19 ( V_2 , V_45 , V_46 ) ;
F_20 () ;
}
static int F_31 ( struct V_47 * V_1 , struct V_48 * V_49 , T_1 V_50 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_51 =
F_32 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_15 * V_16 = & V_6 -> V_17 ;
struct V_52 V_53 = {} ;
long V_54 = 0 ;
bool V_55 = 0 ;
bool V_56 = 0 ;
int V_36 = - V_57 ;
if ( V_49 -> V_58 ) {
V_36 = F_33 ( V_49 , & V_53 ) ;
if ( V_36 )
return V_36 ;
V_56 = 1 ;
switch ( V_53 . V_59 ) {
case V_60 :
V_55 = 1 ;
break;
case V_61 :
V_55 = 0 ;
break;
default:
return - V_57 ;
}
if ( V_53 . V_62 && V_53 . V_62 -> V_63 != V_51 )
return - V_57 ;
}
F_34 ( V_2 ) ;
if ( ! V_6 -> V_21 && V_6 -> V_11 )
goto V_64;
if ( V_56 ) {
V_6 -> V_55 = V_55 ;
if ( V_53 . V_62 )
memcpy ( V_6 -> V_62 , V_53 . V_62 -> V_62 , V_51 ) ;
V_6 -> V_14 = V_53 . V_14 ;
}
while ( V_50 ) {
T_1 V_65 = V_50 ;
struct V_23 * V_18 = NULL ;
if ( V_6 -> V_22 ) {
V_18 = V_16 -> V_18 + V_16 -> V_20 - 1 ;
V_65 = F_35 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_36 = F_36 ( F_37 ( F_11 ( V_18 ) ) +
V_18 -> V_66 + V_18 -> V_67 ,
V_49 , V_65 ) ;
if ( V_36 )
goto V_64;
V_18 -> V_67 += V_65 ;
V_6 -> V_22 = ( V_18 -> V_66 + V_18 -> V_67 ) &
( V_10 - 1 ) ;
V_6 -> V_11 += V_65 ;
V_54 += V_65 ;
V_50 -= V_65 ;
continue;
}
if ( ! F_4 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_36 = - V_68 ;
goto V_64;
}
V_65 = F_35 (unsigned long, size, aead_sndbuf(sk)) ;
while ( V_65 ) {
T_1 V_69 = 0 ;
if ( V_16 -> V_20 >= V_19 ) {
F_10 ( V_2 ) ;
V_36 = - V_70 ;
goto V_64;
}
V_18 = V_16 -> V_18 + V_16 -> V_20 ;
V_69 = F_35 ( T_1 , V_65 , V_10 ) ;
F_13 ( V_18 , F_38 ( V_71 ) ) ;
V_36 = - V_72 ;
if ( ! F_11 ( V_18 ) )
goto V_64;
V_36 = F_36 ( F_37 ( F_11 ( V_18 ) ) ,
V_49 , V_69 ) ;
if ( V_36 ) {
F_39 ( F_11 ( V_18 ) ) ;
F_13 ( V_18 , NULL ) ;
goto V_64;
}
V_18 -> V_66 = 0 ;
V_18 -> V_67 = V_69 ;
V_65 -= V_69 ;
V_6 -> V_11 += V_69 ;
V_54 += V_69 ;
V_16 -> V_20 ++ ;
V_50 -= V_69 ;
V_6 -> V_22 = V_69 & ( V_10 - 1 ) ;
}
}
V_36 = 0 ;
V_6 -> V_21 = V_49 -> V_73 & V_74 ;
if ( ! V_6 -> V_21 && ! F_5 ( V_6 ) ) {
F_10 ( V_2 ) ;
V_36 = - V_68 ;
}
V_64:
F_30 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_36 ? : V_54 ;
}
static T_2 F_41 ( struct V_47 * V_1 , struct V_75 * V_75 ,
int V_66 , T_1 V_50 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_15 * V_16 = & V_6 -> V_17 ;
int V_36 = - V_57 ;
if ( V_34 & V_76 )
V_34 |= V_74 ;
if ( V_16 -> V_20 >= V_19 )
return - V_70 ;
F_34 ( V_2 ) ;
if ( ! V_6 -> V_21 && V_6 -> V_11 )
goto V_64;
if ( ! V_50 )
goto V_77;
if ( ! F_4 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_36 = - V_68 ;
goto V_64;
}
V_6 -> V_22 = 0 ;
F_42 ( V_75 ) ;
F_43 ( V_16 -> V_18 + V_16 -> V_20 , V_75 , V_50 , V_66 ) ;
V_16 -> V_20 ++ ;
V_6 -> V_11 += V_50 ;
V_36 = 0 ;
V_77:
V_6 -> V_21 = V_34 & V_74 ;
if ( ! V_6 -> V_21 && ! F_5 ( V_6 ) ) {
F_10 ( V_2 ) ;
V_36 = - V_68 ;
}
V_64:
F_30 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_36 ? : V_50 ;
}
static void F_44 ( struct V_78 * V_79 , int V_36 )
{
struct V_1 * V_2 = V_79 -> V_80 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_81 * V_82 = F_7 ( & V_6 -> V_13 ) ;
struct V_83 * V_84 = F_45 ( V_79 ) ;
struct V_85 * V_86 = F_46 ( V_84 , V_82 ) ;
struct V_23 * V_18 = V_86 -> V_17 ;
struct V_87 * V_88 ;
struct V_89 * V_90 = V_86 -> V_90 ;
unsigned int V_24 , V_91 = F_47 ( V_82 ) ;
F_48 (rsgl, &areq->list, list) {
F_49 ( & V_88 -> V_16 ) ;
if ( V_88 != & V_86 -> V_92 )
F_50 ( V_2 , V_88 , sizeof( * V_88 ) ) ;
}
for ( V_24 = 0 ; V_24 < V_86 -> V_93 ; V_24 ++ )
F_12 ( F_11 ( V_18 + V_24 ) ) ;
F_50 ( V_2 , V_86 -> V_17 , sizeof( * V_86 -> V_17 ) * V_86 -> V_93 ) ;
F_50 ( V_2 , V_84 , V_91 ) ;
F_51 ( V_2 ) ;
V_90 -> V_94 ( V_90 , V_36 , V_36 ) ;
}
static int F_52 ( struct V_47 * V_1 , struct V_48 * V_49 ,
int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_81 * V_82 = F_7 ( & V_6 -> V_13 ) ;
struct V_85 * V_86 ;
struct V_83 * V_84 = NULL ;
struct V_15 * V_16 = & V_6 -> V_17 ;
struct V_87 * V_95 = NULL , * V_88 ;
unsigned int V_12 = F_6 ( V_82 ) ;
unsigned int V_24 , V_91 = F_47 ( V_82 ) ;
int V_36 = - V_72 ;
unsigned long V_11 ;
T_1 V_96 ;
T_1 V_97 = 0 ;
F_34 ( V_2 ) ;
if ( V_6 -> V_21 ) {
V_36 = F_21 ( V_2 , V_34 ) ;
if ( V_36 )
goto V_64;
}
V_11 = V_6 -> V_11 ;
V_96 = V_11 ;
if ( ! F_5 ( V_6 ) )
goto V_64;
V_84 = F_53 ( V_2 , V_91 , V_71 ) ;
if ( F_54 ( ! V_84 ) )
goto V_64;
V_86 = F_46 ( V_84 , V_82 ) ;
memset ( & V_86 -> V_92 , '\0' , sizeof( V_86 -> V_92 ) ) ;
F_55 ( & V_86 -> V_98 ) ;
V_86 -> V_90 = V_49 -> V_99 ;
memcpy ( V_86 -> V_62 , V_6 -> V_62 , F_32 ( V_82 ) ) ;
F_56 ( V_84 , V_82 ) ;
F_57 ( V_84 , V_6 -> V_14 ) ;
F_58 ( V_84 , V_100 ,
F_44 , V_2 ) ;
V_11 -= V_6 -> V_14 + ( V_6 -> V_55 ? V_12 : 0 ) ;
V_86 -> V_17 = F_53 ( V_2 , sizeof( * V_86 -> V_17 ) * V_16 -> V_20 ,
V_71 ) ;
if ( F_54 ( ! V_86 -> V_17 ) )
goto free;
F_9 ( V_86 -> V_17 , V_16 -> V_20 ) ;
for ( V_24 = 0 ; V_24 < V_16 -> V_20 ; V_24 ++ )
F_43 ( & V_86 -> V_17 [ V_24 ] , F_11 ( & V_16 -> V_18 [ V_24 ] ) ,
V_16 -> V_18 [ V_24 ] . V_67 , V_16 -> V_18 [ V_24 ] . V_66 ) ;
V_86 -> V_93 = V_16 -> V_20 ;
while ( F_59 ( & V_49 -> V_101 ) ) {
T_1 V_102 = F_35 ( T_1 , F_59 ( & V_49 -> V_101 ) ,
( V_96 - V_97 ) ) ;
if ( F_60 ( & V_86 -> V_98 ) ) {
V_88 = & V_86 -> V_92 ;
} else {
V_88 = F_53 ( V_2 , sizeof( * V_88 ) , V_71 ) ;
if ( F_54 ( ! V_88 ) ) {
V_36 = - V_72 ;
goto free;
}
}
V_88 -> V_16 . V_103 = 0 ;
F_61 ( & V_88 -> V_98 , & V_86 -> V_98 ) ;
V_36 = F_62 ( & V_88 -> V_16 , & V_49 -> V_101 , V_102 ) ;
if ( V_36 < 0 )
goto free;
V_97 += V_36 ;
if ( V_95 )
F_63 ( & V_95 -> V_16 , & V_88 -> V_16 ) ;
V_95 = V_88 ;
if ( V_96 <= V_97 )
break;
F_64 ( & V_49 -> V_101 , V_36 ) ;
}
V_36 = - V_57 ;
if ( V_97 < V_96 )
goto free;
F_65 ( V_84 , V_86 -> V_17 , V_86 -> V_92 . V_16 . V_18 , V_11 ,
V_86 -> V_62 ) ;
V_36 = V_6 -> V_55 ? F_66 ( V_84 ) : F_67 ( V_84 ) ;
if ( V_36 ) {
if ( V_36 == - V_104 ) {
F_68 ( V_2 ) ;
V_36 = - V_105 ;
F_8 ( V_6 ) ;
goto V_64;
} else if ( V_36 == - V_106 ) {
F_10 ( V_2 ) ;
}
goto free;
}
F_10 ( V_2 ) ;
free:
F_48 (rsgl, &areq->list, list) {
F_49 ( & V_88 -> V_16 ) ;
if ( V_88 != & V_86 -> V_92 )
F_50 ( V_2 , V_88 , sizeof( * V_88 ) ) ;
}
if ( V_86 -> V_17 )
F_50 ( V_2 , V_86 -> V_17 , sizeof( * V_86 -> V_17 ) * V_86 -> V_93 ) ;
if ( V_84 )
F_50 ( V_2 , V_84 , V_91 ) ;
V_64:
F_14 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_36 ? V_36 : V_96 ;
}
static int F_69 ( struct V_47 * V_1 , struct V_48 * V_49 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_12 = F_6 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_15 * V_16 = & V_6 -> V_17 ;
struct V_87 * V_95 = NULL ;
struct V_87 * V_88 , * V_107 ;
int V_36 = - V_57 ;
unsigned long V_11 = 0 ;
T_1 V_96 = 0 ;
T_1 V_97 = 0 ;
F_34 ( V_2 ) ;
if ( V_6 -> V_21 ) {
V_36 = F_21 ( V_2 , V_34 ) ;
if ( V_36 )
goto V_64;
}
V_11 = V_6 -> V_11 ;
if ( ! F_5 ( V_6 ) )
goto V_64;
V_96 = V_11 ;
V_11 -= V_6 -> V_14 + ( V_6 -> V_55 ? V_12 : 0 ) ;
while ( F_59 ( & V_49 -> V_101 ) ) {
T_1 V_102 = F_35 ( T_1 , F_59 ( & V_49 -> V_101 ) ,
( V_96 - V_97 ) ) ;
if ( F_60 ( & V_6 -> V_98 ) ) {
V_88 = & V_6 -> V_92 ;
} else {
V_88 = F_53 ( V_2 , sizeof( * V_88 ) , V_71 ) ;
if ( F_54 ( ! V_88 ) ) {
V_36 = - V_72 ;
goto V_64;
}
}
V_88 -> V_16 . V_103 = 0 ;
F_61 ( & V_88 -> V_98 , & V_6 -> V_98 ) ;
V_36 = F_62 ( & V_88 -> V_16 , & V_49 -> V_101 , V_102 ) ;
if ( V_36 < 0 )
goto V_64;
V_97 += V_36 ;
if ( V_95 )
F_63 ( & V_95 -> V_16 , & V_88 -> V_16 ) ;
V_95 = V_88 ;
if ( V_96 <= V_97 )
break;
F_64 ( & V_49 -> V_101 , V_36 ) ;
}
V_36 = - V_57 ;
if ( V_97 < V_96 )
goto V_64;
F_70 ( V_16 -> V_18 + V_16 -> V_20 - 1 ) ;
F_65 ( & V_6 -> V_13 , V_16 -> V_18 , V_6 -> V_92 . V_16 . V_18 ,
V_11 , V_6 -> V_62 ) ;
F_57 ( & V_6 -> V_13 , V_6 -> V_14 ) ;
V_36 = F_71 ( V_6 -> V_55 ?
F_66 ( & V_6 -> V_13 ) :
F_67 ( & V_6 -> V_13 ) ,
& V_6 -> V_108 ) ;
if ( V_36 ) {
if ( V_36 == - V_106 )
F_10 ( V_2 ) ;
goto V_64;
}
F_10 ( V_2 ) ;
V_36 = 0 ;
V_64:
F_72 (rsgl, tmp, &ctx->list, list) {
F_49 ( & V_88 -> V_16 ) ;
if ( V_88 != & V_6 -> V_92 )
F_50 ( V_2 , V_88 , sizeof( * V_88 ) ) ;
F_73 ( & V_88 -> V_98 ) ;
}
F_55 ( & V_6 -> V_98 ) ;
F_14 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_36 ? V_36 : V_96 ;
}
static int F_74 ( struct V_47 * V_1 , struct V_48 * V_49 , T_1 V_109 ,
int V_34 )
{
return ( V_49 -> V_99 && ! F_75 ( V_49 -> V_99 ) ) ?
F_52 ( V_1 , V_49 , V_34 ) :
F_69 ( V_1 , V_49 , V_34 ) ;
}
static unsigned int F_76 ( struct V_110 * V_110 , struct V_47 * V_1 ,
T_3 * V_28 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_111 ;
F_77 ( V_110 , F_26 ( V_2 ) , V_28 ) ;
V_111 = 0 ;
if ( ! V_6 -> V_21 )
V_111 |= V_29 | V_30 ;
if ( F_4 ( V_2 ) )
V_111 |= V_44 | V_112 | V_113 ;
return V_111 ;
}
static void * F_78 ( const char * V_114 , T_4 type , T_4 V_111 )
{
return F_79 ( V_114 , type , V_111 ) ;
}
static void F_80 ( void * V_7 )
{
F_81 ( V_7 ) ;
}
static int F_82 ( void * V_7 , unsigned int V_115 )
{
return F_83 ( V_7 , V_115 ) ;
}
static int F_84 ( void * V_7 , const T_5 * V_116 , unsigned int V_117 )
{
return F_85 ( V_7 , V_116 , V_117 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_63 = F_32 (
F_7 ( & V_6 -> V_13 ) ) ;
F_87 ( F_88 ( & V_2 -> V_118 ) != 0 ) ;
F_10 ( V_2 ) ;
F_89 ( V_2 , V_6 -> V_62 , V_63 ) ;
F_50 ( V_2 , V_6 , V_6 -> V_65 ) ;
F_90 ( V_2 ) ;
}
static int F_91 ( void * V_7 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_65 = sizeof( * V_6 ) + F_92 ( V_7 ) ;
unsigned int V_63 = F_32 ( V_7 ) ;
V_6 = F_53 ( V_2 , V_65 , V_71 ) ;
if ( ! V_6 )
return - V_72 ;
memset ( V_6 , 0 , V_65 ) ;
V_6 -> V_62 = F_53 ( V_2 , V_63 , V_71 ) ;
if ( ! V_6 -> V_62 ) {
F_50 ( V_2 , V_6 , V_65 ) ;
return - V_72 ;
}
memset ( V_6 -> V_62 , 0 , V_63 ) ;
V_6 -> V_65 = V_65 ;
V_6 -> V_11 = 0 ;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_55 = 0 ;
V_6 -> V_17 . V_20 = 0 ;
V_6 -> V_14 = 0 ;
F_93 ( & V_6 -> V_108 ) ;
F_9 ( V_6 -> V_17 . V_18 , V_19 ) ;
F_55 ( & V_6 -> V_98 ) ;
V_4 -> V_7 = V_6 ;
F_56 ( & V_6 -> V_13 , V_7 ) ;
F_58 ( & V_6 -> V_13 , V_100 ,
V_119 , & V_6 -> V_108 ) ;
V_2 -> V_120 = F_86 ;
return 0 ;
}
static int T_6 F_94 ( void )
{
return F_95 ( & V_121 ) ;
}
static void T_7 F_96 ( void )
{
int V_36 = F_97 ( & V_121 ) ;
F_98 ( V_36 ) ;
}
