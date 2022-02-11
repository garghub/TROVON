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
return V_6 -> V_11 >= V_6 -> V_14 + ( V_6 -> V_15 ? 0 : V_12 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_16 * V_17 = & V_6 -> V_18 ;
F_9 ( V_17 -> V_19 , V_20 ) ;
V_17 -> V_21 = 0 ;
V_6 -> V_11 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_16 * V_17 = & V_6 -> V_18 ;
struct V_24 * V_19 = V_17 -> V_19 ;
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_21 ; V_25 ++ ) {
if ( ! F_11 ( V_19 + V_25 ) )
continue;
F_12 ( F_11 ( V_19 + V_25 ) ) ;
F_13 ( V_19 + V_25 , NULL ) ;
}
F_8 ( V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
if ( ! F_4 ( V_2 ) )
return;
F_15 () ;
V_27 = F_16 ( V_2 -> V_28 ) ;
if ( F_17 ( V_27 ) )
F_18 ( & V_27 -> V_29 , V_30 |
V_31 |
V_32 ) ;
F_19 ( V_2 , V_33 , V_34 ) ;
F_20 () ;
}
static int F_21 ( struct V_1 * V_2 , unsigned V_35 )
{
F_22 ( V_29 , V_36 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
long V_37 ;
int V_38 = - V_39 ;
if ( V_35 & V_40 )
return - V_41 ;
F_23 ( V_42 , V_2 ) ;
F_24 ( F_25 ( V_2 ) , & V_29 ) ;
for (; ; ) {
if ( F_26 ( V_43 ) )
break;
V_37 = V_44 ;
if ( F_27 ( V_2 , & V_37 , ! V_6 -> V_22 , & V_29 ) ) {
V_38 = 0 ;
break;
}
}
F_28 ( F_25 ( V_2 ) , & V_29 ) ;
F_29 ( V_42 , V_2 ) ;
return V_38 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_26 * V_27 ;
if ( V_6 -> V_22 )
return;
if ( ! V_6 -> V_11 )
return;
F_15 () ;
V_27 = F_16 ( V_2 -> V_28 ) ;
if ( F_17 ( V_27 ) )
F_18 ( & V_27 -> V_29 , V_45 |
V_31 |
V_32 ) ;
F_19 ( V_2 , V_46 , V_47 ) ;
F_20 () ;
}
static int F_31 ( struct V_48 * V_1 , struct V_49 * V_50 , T_1 V_51 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_52 =
F_32 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_16 * V_17 = & V_6 -> V_18 ;
struct V_53 V_54 = {} ;
long V_55 = 0 ;
bool V_15 = 0 ;
bool V_56 = 0 ;
int V_38 = - V_57 ;
if ( V_50 -> V_58 ) {
V_38 = F_33 ( V_50 , & V_54 ) ;
if ( V_38 )
return V_38 ;
V_56 = 1 ;
switch ( V_54 . V_59 ) {
case V_60 :
V_15 = 1 ;
break;
case V_61 :
V_15 = 0 ;
break;
default:
return - V_57 ;
}
if ( V_54 . V_62 && V_54 . V_62 -> V_63 != V_52 )
return - V_57 ;
}
F_34 ( V_2 ) ;
if ( ! V_6 -> V_22 && V_6 -> V_11 )
goto V_64;
if ( V_56 ) {
V_6 -> V_15 = V_15 ;
if ( V_54 . V_62 )
memcpy ( V_6 -> V_62 , V_54 . V_62 -> V_62 , V_52 ) ;
V_6 -> V_14 = V_54 . V_14 ;
}
while ( V_51 ) {
T_1 V_65 = V_51 ;
struct V_24 * V_19 = NULL ;
if ( V_6 -> V_23 ) {
V_19 = V_17 -> V_19 + V_17 -> V_21 - 1 ;
V_65 = F_35 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_38 = F_36 ( F_37 ( F_11 ( V_19 ) ) +
V_19 -> V_66 + V_19 -> V_67 ,
V_50 , V_65 ) ;
if ( V_38 )
goto V_64;
V_19 -> V_67 += V_65 ;
V_6 -> V_23 = ( V_19 -> V_66 + V_19 -> V_67 ) &
( V_10 - 1 ) ;
V_6 -> V_11 += V_65 ;
V_55 += V_65 ;
V_51 -= V_65 ;
continue;
}
if ( ! F_4 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_38 = - V_68 ;
goto V_64;
}
V_65 = F_35 (unsigned long, size, aead_sndbuf(sk)) ;
while ( V_65 ) {
T_1 V_69 = 0 ;
if ( V_17 -> V_21 >= V_20 ) {
F_10 ( V_2 ) ;
V_38 = - V_70 ;
goto V_64;
}
V_19 = V_17 -> V_19 + V_17 -> V_21 ;
V_69 = F_35 ( T_1 , V_65 , V_10 ) ;
F_13 ( V_19 , F_38 ( V_71 ) ) ;
V_38 = - V_72 ;
if ( ! F_11 ( V_19 ) )
goto V_64;
V_38 = F_36 ( F_37 ( F_11 ( V_19 ) ) ,
V_50 , V_69 ) ;
if ( V_38 ) {
F_39 ( F_11 ( V_19 ) ) ;
F_13 ( V_19 , NULL ) ;
goto V_64;
}
V_19 -> V_66 = 0 ;
V_19 -> V_67 = V_69 ;
V_65 -= V_69 ;
V_6 -> V_11 += V_69 ;
V_55 += V_69 ;
V_17 -> V_21 ++ ;
V_51 -= V_69 ;
V_6 -> V_23 = V_69 & ( V_10 - 1 ) ;
}
}
V_38 = 0 ;
V_6 -> V_22 = V_50 -> V_73 & V_74 ;
if ( ! V_6 -> V_22 && ! F_5 ( V_6 ) ) {
F_10 ( V_2 ) ;
V_38 = - V_68 ;
}
V_64:
F_30 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_38 ? : V_55 ;
}
static T_2 F_41 ( struct V_48 * V_1 , struct V_75 * V_75 ,
int V_66 , T_1 V_51 , int V_35 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_16 * V_17 = & V_6 -> V_18 ;
int V_38 = - V_57 ;
if ( V_35 & V_76 )
V_35 |= V_74 ;
if ( V_17 -> V_21 >= V_20 )
return - V_70 ;
F_34 ( V_2 ) ;
if ( ! V_6 -> V_22 && V_6 -> V_11 )
goto V_64;
if ( ! V_51 )
goto V_77;
if ( ! F_4 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_38 = - V_68 ;
goto V_64;
}
V_6 -> V_23 = 0 ;
F_42 ( V_75 ) ;
F_43 ( V_17 -> V_19 + V_17 -> V_21 , V_75 , V_51 , V_66 ) ;
V_17 -> V_21 ++ ;
V_6 -> V_11 += V_51 ;
V_38 = 0 ;
V_77:
V_6 -> V_22 = V_35 & V_74 ;
if ( ! V_6 -> V_22 && ! F_5 ( V_6 ) ) {
F_10 ( V_2 ) ;
V_38 = - V_68 ;
}
V_64:
F_30 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_38 ? : V_51 ;
}
static void F_44 ( struct V_78 * V_79 , int V_38 )
{
struct V_80 * V_81 = V_79 -> V_82 ;
struct V_83 * V_84 = F_7 ( V_81 ) ;
struct V_85 * V_86 = F_45 ( V_81 , V_84 ) ;
struct V_1 * V_2 = V_86 -> V_2 ;
struct V_24 * V_19 = V_86 -> V_18 ;
struct V_87 * V_88 ;
struct V_89 * V_90 = V_86 -> V_90 ;
unsigned int V_25 , V_91 = F_46 ( V_84 ) ;
F_47 (rsgl, &areq->list, list) {
F_48 ( & V_88 -> V_17 ) ;
if ( V_88 != & V_86 -> V_92 )
F_49 ( V_2 , V_88 , sizeof( * V_88 ) ) ;
}
for ( V_25 = 0 ; V_25 < V_86 -> V_93 ; V_25 ++ )
F_12 ( F_11 ( V_19 + V_25 ) ) ;
F_49 ( V_2 , V_86 -> V_18 , sizeof( * V_86 -> V_18 ) * V_86 -> V_93 ) ;
F_49 ( V_2 , V_81 , V_91 ) ;
F_50 ( V_2 ) ;
V_90 -> V_94 ( V_90 , V_38 , V_38 ) ;
}
static int F_51 ( struct V_48 * V_1 , struct V_49 * V_50 ,
int V_35 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_83 * V_84 = F_7 ( & V_6 -> V_13 ) ;
struct V_85 * V_86 ;
struct V_80 * V_81 = NULL ;
struct V_16 * V_17 = & V_6 -> V_18 ;
struct V_87 * V_95 = NULL , * V_88 ;
unsigned int V_12 = F_6 ( V_84 ) ;
unsigned int V_25 , V_91 = F_46 ( V_84 ) ;
int V_38 = - V_72 ;
unsigned long V_11 ;
T_1 V_96 = 0 ;
T_1 V_97 = 0 ;
F_34 ( V_2 ) ;
if ( V_6 -> V_22 ) {
V_38 = F_21 ( V_2 , V_35 ) ;
if ( V_38 )
goto V_64;
}
if ( ! F_5 ( V_6 ) )
goto V_64;
V_11 = V_6 -> V_11 ;
if ( V_6 -> V_15 )
V_96 = V_11 + V_12 ;
else
V_96 = V_11 - V_12 ;
V_81 = F_52 ( V_2 , V_91 , V_71 ) ;
if ( F_53 ( ! V_81 ) )
goto V_64;
V_86 = F_45 ( V_81 , V_84 ) ;
memset ( & V_86 -> V_92 , '\0' , sizeof( V_86 -> V_92 ) ) ;
F_54 ( & V_86 -> V_98 ) ;
V_86 -> V_90 = V_50 -> V_99 ;
V_86 -> V_2 = V_2 ;
memcpy ( V_86 -> V_62 , V_6 -> V_62 , F_32 ( V_84 ) ) ;
F_55 ( V_81 , V_84 ) ;
F_56 ( V_81 , V_6 -> V_14 ) ;
F_57 ( V_81 , V_100 ,
F_44 , V_81 ) ;
V_11 -= V_6 -> V_14 ;
V_86 -> V_18 = F_52 ( V_2 ,
sizeof( * V_86 -> V_18 ) * F_3 ( V_101 , V_17 -> V_21 , 1 ) ,
V_71 ) ;
if ( F_53 ( ! V_86 -> V_18 ) )
goto free;
F_9 ( V_86 -> V_18 , F_3 ( V_101 , V_17 -> V_21 , 1 ) ) ;
for ( V_25 = 0 ; V_25 < V_17 -> V_21 ; V_25 ++ )
F_43 ( & V_86 -> V_18 [ V_25 ] , F_11 ( & V_17 -> V_19 [ V_25 ] ) ,
V_17 -> V_19 [ V_25 ] . V_67 , V_17 -> V_19 [ V_25 ] . V_66 ) ;
V_86 -> V_93 = V_17 -> V_21 ;
while ( V_96 > V_97 && F_58 ( & V_50 -> V_102 ) ) {
T_1 V_103 = F_35 ( T_1 , F_58 ( & V_50 -> V_102 ) ,
( V_96 - V_97 ) ) ;
if ( F_59 ( & V_86 -> V_98 ) ) {
V_88 = & V_86 -> V_92 ;
} else {
V_88 = F_52 ( V_2 , sizeof( * V_88 ) , V_71 ) ;
if ( F_53 ( ! V_88 ) ) {
V_38 = - V_72 ;
goto free;
}
}
V_88 -> V_17 . V_104 = 0 ;
F_60 ( & V_88 -> V_98 , & V_86 -> V_98 ) ;
V_38 = F_61 ( & V_88 -> V_17 , & V_50 -> V_102 , V_103 ) ;
if ( V_38 < 0 )
goto free;
V_97 += V_38 ;
if ( V_95 )
F_62 ( & V_95 -> V_17 , & V_88 -> V_17 ) ;
V_95 = V_88 ;
F_63 ( & V_50 -> V_102 , V_38 ) ;
}
if ( V_97 < V_96 ) {
V_38 = - V_57 ;
goto V_64;
}
F_64 ( V_81 , V_86 -> V_18 , V_86 -> V_92 . V_17 . V_19 , V_11 ,
V_86 -> V_62 ) ;
V_38 = V_6 -> V_15 ? F_65 ( V_81 ) : F_66 ( V_81 ) ;
if ( V_38 ) {
if ( V_38 == - V_105 ) {
F_67 ( V_2 ) ;
V_38 = - V_106 ;
F_8 ( V_6 ) ;
goto V_64;
} else if ( V_38 == - V_107 ) {
F_10 ( V_2 ) ;
}
goto free;
}
F_10 ( V_2 ) ;
free:
F_47 (rsgl, &areq->list, list) {
F_48 ( & V_88 -> V_17 ) ;
if ( V_88 != & V_86 -> V_92 )
F_49 ( V_2 , V_88 , sizeof( * V_88 ) ) ;
}
if ( V_86 -> V_18 )
F_49 ( V_2 , V_86 -> V_18 , sizeof( * V_86 -> V_18 ) * V_86 -> V_93 ) ;
if ( V_81 )
F_49 ( V_2 , V_81 , V_91 ) ;
V_64:
F_14 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_38 ? V_38 : V_96 ;
}
static int F_68 ( struct V_48 * V_1 , struct V_49 * V_50 , int V_35 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_12 = F_6 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_16 * V_17 = & V_6 -> V_18 ;
struct V_87 * V_95 = NULL ;
struct V_87 * V_88 , * V_108 ;
int V_38 = - V_57 ;
unsigned long V_11 = 0 ;
T_1 V_96 = 0 ;
T_1 V_97 = 0 ;
F_34 ( V_2 ) ;
if ( V_6 -> V_22 ) {
V_38 = F_21 ( V_2 , V_35 ) ;
if ( V_38 )
goto V_64;
}
V_11 = V_6 -> V_11 ;
if ( ! F_5 ( V_6 ) )
goto V_64;
if ( V_6 -> V_15 )
V_96 = V_11 + V_12 ;
else
V_96 = V_11 - V_12 ;
V_11 -= V_6 -> V_14 ;
while ( V_96 > V_97 && F_58 ( & V_50 -> V_102 ) ) {
T_1 V_103 = F_35 ( T_1 , F_58 ( & V_50 -> V_102 ) ,
( V_96 - V_97 ) ) ;
if ( F_59 ( & V_6 -> V_98 ) ) {
V_88 = & V_6 -> V_92 ;
} else {
V_88 = F_52 ( V_2 , sizeof( * V_88 ) , V_71 ) ;
if ( F_53 ( ! V_88 ) ) {
V_38 = - V_72 ;
goto V_64;
}
}
V_88 -> V_17 . V_104 = 0 ;
F_60 ( & V_88 -> V_98 , & V_6 -> V_98 ) ;
V_38 = F_61 ( & V_88 -> V_17 , & V_50 -> V_102 , V_103 ) ;
if ( V_38 < 0 )
goto V_64;
V_97 += V_38 ;
if ( V_95 )
F_62 ( & V_95 -> V_17 , & V_88 -> V_17 ) ;
V_95 = V_88 ;
F_63 ( & V_50 -> V_102 , V_38 ) ;
}
if ( V_97 < V_96 ) {
V_38 = - V_57 ;
goto V_64;
}
F_69 ( V_17 -> V_19 + V_17 -> V_21 - 1 ) ;
F_64 ( & V_6 -> V_13 , V_17 -> V_19 , V_6 -> V_92 . V_17 . V_19 ,
V_11 , V_6 -> V_62 ) ;
F_56 ( & V_6 -> V_13 , V_6 -> V_14 ) ;
V_38 = F_70 ( V_6 -> V_15 ?
F_65 ( & V_6 -> V_13 ) :
F_66 ( & V_6 -> V_13 ) ,
& V_6 -> V_109 ) ;
if ( V_38 ) {
if ( V_38 == - V_107 )
F_10 ( V_2 ) ;
goto V_64;
}
F_10 ( V_2 ) ;
V_38 = 0 ;
V_64:
F_71 (rsgl, tmp, &ctx->list, list) {
F_48 ( & V_88 -> V_17 ) ;
F_72 ( & V_88 -> V_98 ) ;
if ( V_88 != & V_6 -> V_92 )
F_49 ( V_2 , V_88 , sizeof( * V_88 ) ) ;
}
F_54 ( & V_6 -> V_98 ) ;
F_14 ( V_2 ) ;
F_40 ( V_2 ) ;
return V_38 ? V_38 : V_96 ;
}
static int F_73 ( struct V_48 * V_1 , struct V_49 * V_50 , T_1 V_110 ,
int V_35 )
{
return ( V_50 -> V_99 && ! F_74 ( V_50 -> V_99 ) ) ?
F_51 ( V_1 , V_50 , V_35 ) :
F_68 ( V_1 , V_50 , V_35 ) ;
}
static unsigned int F_75 ( struct V_111 * V_111 , struct V_48 * V_1 ,
T_3 * V_29 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_112 ;
F_76 ( V_111 , F_25 ( V_2 ) , V_29 ) ;
V_112 = 0 ;
if ( ! V_6 -> V_22 )
V_112 |= V_30 | V_31 ;
if ( F_4 ( V_2 ) )
V_112 |= V_45 | V_113 | V_114 ;
return V_112 ;
}
static void * F_77 ( const char * V_115 , V_101 type , V_101 V_112 )
{
return F_78 ( V_115 , type , V_112 ) ;
}
static void F_79 ( void * V_7 )
{
F_80 ( V_7 ) ;
}
static int F_81 ( void * V_7 , unsigned int V_116 )
{
return F_82 ( V_7 , V_116 ) ;
}
static int F_83 ( void * V_7 , const T_4 * V_117 , unsigned int V_118 )
{
return F_84 ( V_7 , V_117 , V_118 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_63 = F_32 (
F_7 ( & V_6 -> V_13 ) ) ;
F_86 ( F_87 ( & V_2 -> V_119 ) != 0 ) ;
F_10 ( V_2 ) ;
F_88 ( V_2 , V_6 -> V_62 , V_63 ) ;
F_49 ( V_2 , V_6 , V_6 -> V_65 ) ;
F_89 ( V_2 ) ;
}
static int F_90 ( void * V_7 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_65 = sizeof( * V_6 ) + F_91 ( V_7 ) ;
unsigned int V_63 = F_32 ( V_7 ) ;
V_6 = F_52 ( V_2 , V_65 , V_71 ) ;
if ( ! V_6 )
return - V_72 ;
memset ( V_6 , 0 , V_65 ) ;
V_6 -> V_62 = F_52 ( V_2 , V_63 , V_71 ) ;
if ( ! V_6 -> V_62 ) {
F_49 ( V_2 , V_6 , V_65 ) ;
return - V_72 ;
}
memset ( V_6 -> V_62 , 0 , V_63 ) ;
V_6 -> V_65 = V_65 ;
V_6 -> V_11 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_15 = 0 ;
V_6 -> V_18 . V_21 = 0 ;
V_6 -> V_14 = 0 ;
F_92 ( & V_6 -> V_109 ) ;
F_9 ( V_6 -> V_18 . V_19 , V_20 ) ;
F_54 ( & V_6 -> V_98 ) ;
V_4 -> V_7 = V_6 ;
F_55 ( & V_6 -> V_13 , V_7 ) ;
F_57 ( & V_6 -> V_13 , V_100 ,
V_120 , & V_6 -> V_109 ) ;
V_2 -> V_121 = F_85 ;
return 0 ;
}
static int T_5 F_93 ( void )
{
return F_94 ( & V_122 ) ;
}
static void T_6 F_95 ( void )
{
int V_38 = F_96 ( & V_122 ) ;
F_97 ( V_38 ) ;
}
