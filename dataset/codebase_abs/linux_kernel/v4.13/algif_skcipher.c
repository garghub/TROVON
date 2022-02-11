static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 ;
struct V_6 * V_8 ;
int V_9 , V_10 ;
F_2 (rsgl, tmp, &sreq->list, list) {
F_3 ( & V_4 -> V_7 ) ;
if ( V_4 != & V_2 -> V_11 )
F_4 ( V_4 ) ;
}
V_7 = V_2 -> V_12 ;
V_10 = F_5 ( V_7 ) ;
F_6 (sgl, sg, n, i) {
struct V_13 * V_13 = F_7 ( V_8 ) ;
if ( V_13 && F_8 ( V_13 ) )
F_9 ( V_13 ) ;
}
F_4 ( V_2 -> V_12 ) ;
}
static void F_10 ( struct V_14 * V_15 , int V_16 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
struct V_18 * V_19 = V_2 -> V_19 ;
F_11 ( V_2 -> V_20 ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
V_19 -> V_21 ( V_19 , V_16 , V_16 ) ;
}
static inline int F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
return F_15 ( int , F_15 ( int , V_23 -> V_29 & V_30 , V_31 ) -
V_27 -> V_32 , 0 ) ;
}
static inline bool F_16 ( struct V_22 * V_23 )
{
return V_31 <= F_13 ( V_23 ) ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_33 * V_7 ;
struct V_6 * V_8 = NULL ;
V_7 = F_18 ( V_27 -> V_34 . V_35 , struct V_33 , V_36 ) ;
if ( ! F_19 ( & V_27 -> V_34 ) )
V_8 = V_7 -> V_8 ;
if ( ! V_8 || V_7 -> V_37 >= V_38 ) {
V_7 = F_20 ( V_23 , sizeof( * V_7 ) +
sizeof( V_7 -> V_8 [ 0 ] ) * ( V_38 + 1 ) ,
V_39 ) ;
if ( ! V_7 )
return - V_40 ;
F_21 ( V_7 -> V_8 , V_38 + 1 ) ;
V_7 -> V_37 = 0 ;
if ( V_8 )
F_22 ( V_8 , V_38 + 1 , V_7 -> V_8 ) ;
F_23 ( & V_7 -> V_36 , & V_27 -> V_34 ) ;
}
return 0 ;
}
static void F_24 ( struct V_22 * V_23 , T_1 V_32 , int V_41 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_33 * V_7 ;
struct V_6 * V_8 ;
int V_9 ;
while ( ! F_19 ( & V_27 -> V_34 ) ) {
V_7 = F_25 ( & V_27 -> V_34 , struct V_33 ,
V_36 ) ;
V_8 = V_7 -> V_8 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_37 ; V_9 ++ ) {
T_1 V_42 = F_26 ( T_1 , V_32 , V_8 [ V_9 ] . V_43 ) ;
if ( ! F_7 ( V_8 + V_9 ) )
continue;
V_8 [ V_9 ] . V_43 -= V_42 ;
V_8 [ V_9 ] . V_44 += V_42 ;
V_32 -= V_42 ;
V_27 -> V_32 -= V_42 ;
if ( V_8 [ V_9 ] . V_43 )
return;
if ( V_41 )
F_9 ( F_7 ( V_8 + V_9 ) ) ;
F_27 ( V_8 + V_9 , NULL ) ;
}
F_28 ( & V_7 -> V_36 ) ;
F_29 ( V_23 , V_7 ,
sizeof( * V_7 ) + sizeof( V_7 -> V_8 [ 0 ] ) *
( V_38 + 1 ) ) ;
}
if ( ! V_27 -> V_32 )
V_27 -> V_45 = 0 ;
}
static void F_30 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
F_24 ( V_23 , V_27 -> V_32 , 1 ) ;
}
static int F_31 ( struct V_22 * V_23 , unsigned V_46 )
{
F_32 ( V_47 , V_48 ) ;
int V_16 = - V_49 ;
long V_50 ;
if ( V_46 & V_51 )
return - V_52 ;
F_33 ( V_53 , V_23 ) ;
F_34 ( F_35 ( V_23 ) , & V_47 ) ;
for (; ; ) {
if ( F_36 ( V_54 ) )
break;
V_50 = V_55 ;
if ( F_37 ( V_23 , & V_50 , F_16 ( V_23 ) , & V_47 ) ) {
V_16 = 0 ;
break;
}
}
F_38 ( F_35 ( V_23 ) , & V_47 ) ;
return V_16 ;
}
static void F_39 ( struct V_22 * V_23 )
{
struct V_56 * V_57 ;
if ( ! F_16 ( V_23 ) )
return;
F_40 () ;
V_57 = F_41 ( V_23 -> V_58 ) ;
if ( F_42 ( V_57 ) )
F_43 ( & V_57 -> V_47 , V_59 |
V_60 |
V_61 ) ;
F_44 ( V_23 , V_62 , V_63 ) ;
F_45 () ;
}
static int F_46 ( struct V_22 * V_23 , unsigned V_46 )
{
F_32 ( V_47 , V_48 ) ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
long V_50 ;
int V_16 = - V_49 ;
if ( V_46 & V_51 ) {
return - V_52 ;
}
F_33 ( V_64 , V_23 ) ;
F_34 ( F_35 ( V_23 ) , & V_47 ) ;
for (; ; ) {
if ( F_36 ( V_54 ) )
break;
V_50 = V_55 ;
if ( F_37 ( V_23 , & V_50 , V_27 -> V_32 , & V_47 ) ) {
V_16 = 0 ;
break;
}
}
F_38 ( F_35 ( V_23 ) , & V_47 ) ;
F_47 ( V_64 , V_23 ) ;
return V_16 ;
}
static void F_48 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_56 * V_57 ;
if ( ! V_27 -> V_32 )
return;
F_40 () ;
V_57 = F_41 ( V_23 -> V_58 ) ;
if ( F_42 ( V_57 ) )
F_43 ( & V_57 -> V_47 , V_65 |
V_60 |
V_61 ) ;
F_44 ( V_23 , V_66 , V_67 ) ;
F_45 () ;
}
static int F_49 ( struct V_68 * V_22 , struct V_69 * V_70 ,
T_1 V_71 )
{
struct V_22 * V_23 = V_22 -> V_23 ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_22 * V_72 = V_25 -> V_73 ;
struct V_24 * V_74 = F_14 ( V_72 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_75 * V_76 = V_74 -> V_28 ;
struct V_77 * V_78 = V_76 -> V_79 ;
unsigned V_80 = F_50 ( V_78 ) ;
struct V_33 * V_7 ;
struct V_81 V_82 = {} ;
long V_83 = 0 ;
bool V_84 = 0 ;
bool V_85 = 0 ;
int V_16 ;
int V_9 ;
if ( V_70 -> V_86 ) {
V_16 = F_51 ( V_70 , & V_82 ) ;
if ( V_16 )
return V_16 ;
V_85 = 1 ;
switch ( V_82 . V_87 ) {
case V_88 :
V_84 = 1 ;
break;
case V_89 :
V_84 = 0 ;
break;
default:
return - V_90 ;
}
if ( V_82 . V_91 && V_82 . V_91 -> V_92 != V_80 )
return - V_90 ;
}
V_16 = - V_90 ;
F_52 ( V_23 ) ;
if ( ! V_27 -> V_93 && V_27 -> V_32 )
goto V_94;
if ( V_85 ) {
V_27 -> V_84 = V_84 ;
if ( V_82 . V_91 )
memcpy ( V_27 -> V_91 , V_82 . V_91 -> V_91 , V_80 ) ;
}
while ( V_71 ) {
struct V_6 * V_8 ;
unsigned long V_95 = V_71 ;
T_1 V_42 ;
if ( V_27 -> V_45 ) {
V_7 = F_18 ( V_27 -> V_34 . V_35 ,
struct V_33 , V_36 ) ;
V_8 = V_7 -> V_8 + V_7 -> V_37 - 1 ;
V_95 = F_26 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_16 = F_53 ( F_54 ( F_7 ( V_8 ) ) +
V_8 -> V_44 + V_8 -> V_43 ,
V_70 , V_95 ) ;
if ( V_16 )
goto V_94;
V_8 -> V_43 += V_95 ;
V_27 -> V_45 = ( V_8 -> V_44 + V_8 -> V_43 ) &
( V_31 - 1 ) ;
V_27 -> V_32 += V_95 ;
V_83 += V_95 ;
V_71 -= V_95 ;
continue;
}
if ( ! F_16 ( V_23 ) ) {
V_16 = F_31 ( V_23 , V_70 -> V_96 ) ;
if ( V_16 )
goto V_94;
}
V_95 = F_26 (unsigned long, len, skcipher_sndbuf(sk)) ;
V_16 = F_17 ( V_23 ) ;
if ( V_16 )
goto V_94;
V_7 = F_18 ( V_27 -> V_34 . V_35 , struct V_33 , V_36 ) ;
V_8 = V_7 -> V_8 ;
if ( V_7 -> V_37 )
F_55 ( V_8 + V_7 -> V_37 - 1 ) ;
do {
V_9 = V_7 -> V_37 ;
V_42 = F_26 ( T_1 , V_95 , V_31 ) ;
F_27 ( V_8 + V_9 , F_56 ( V_39 ) ) ;
V_16 = - V_40 ;
if ( ! F_7 ( V_8 + V_9 ) )
goto V_94;
V_16 = F_53 ( F_54 ( F_7 ( V_8 + V_9 ) ) ,
V_70 , V_42 ) ;
if ( V_16 ) {
F_57 ( F_7 ( V_8 + V_9 ) ) ;
F_27 ( V_8 + V_9 , NULL ) ;
goto V_94;
}
V_8 [ V_9 ] . V_43 = V_42 ;
V_95 -= V_42 ;
V_27 -> V_32 += V_42 ;
V_83 += V_42 ;
V_71 -= V_42 ;
V_7 -> V_37 ++ ;
} while ( V_95 && V_7 -> V_37 < V_38 );
if ( ! V_71 )
F_58 ( V_8 + V_7 -> V_37 - 1 ) ;
V_27 -> V_45 = V_42 & ( V_31 - 1 ) ;
}
V_16 = 0 ;
V_27 -> V_93 = V_70 -> V_96 & V_97 ;
V_94:
F_48 ( V_23 ) ;
F_59 ( V_23 ) ;
return V_83 ? : V_16 ;
}
static T_2 F_60 ( struct V_68 * V_22 , struct V_13 * V_13 ,
int V_44 , T_1 V_71 , int V_46 )
{
struct V_22 * V_23 = V_22 -> V_23 ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_33 * V_7 ;
int V_16 = - V_90 ;
if ( V_46 & V_98 )
V_46 |= V_97 ;
F_52 ( V_23 ) ;
if ( ! V_27 -> V_93 && V_27 -> V_32 )
goto V_94;
if ( ! V_71 )
goto V_99;
if ( ! F_16 ( V_23 ) ) {
V_16 = F_31 ( V_23 , V_46 ) ;
if ( V_16 )
goto V_94;
}
V_16 = F_17 ( V_23 ) ;
if ( V_16 )
goto V_94;
V_27 -> V_45 = 0 ;
V_7 = F_18 ( V_27 -> V_34 . V_35 , struct V_33 , V_36 ) ;
if ( V_7 -> V_37 )
F_55 ( V_7 -> V_8 + V_7 -> V_37 - 1 ) ;
F_58 ( V_7 -> V_8 + V_7 -> V_37 ) ;
F_61 ( V_13 ) ;
F_62 ( V_7 -> V_8 + V_7 -> V_37 , V_13 , V_71 , V_44 ) ;
V_7 -> V_37 ++ ;
V_27 -> V_32 += V_71 ;
V_99:
V_27 -> V_93 = V_46 & V_97 ;
V_94:
F_48 ( V_23 ) ;
F_59 ( V_23 ) ;
return V_16 ? : V_71 ;
}
static int F_63 ( struct V_26 * V_27 )
{
struct V_33 * V_7 ;
struct V_6 * V_8 ;
int V_100 = 0 ;
F_64 (sgl, &ctx->tsgl, list) {
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_43 )
V_8 ++ ;
V_100 += F_5 ( V_8 ) ;
}
return V_100 ;
}
static int F_65 ( struct V_68 * V_22 , struct V_69 * V_70 ,
int V_46 )
{
struct V_22 * V_23 = V_22 -> V_23 ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_22 * V_72 = V_25 -> V_73 ;
struct V_24 * V_74 = F_14 ( V_72 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_75 * V_76 = V_74 -> V_28 ;
struct V_77 * V_78 = V_76 -> V_79 ;
struct V_33 * V_7 ;
struct V_6 * V_8 ;
struct V_1 * V_2 ;
struct V_101 * V_15 ;
struct V_3 * V_102 = NULL ;
unsigned int V_103 = 0 , V_95 = 0 , V_104 ;
unsigned int V_105 = F_66 ( V_78 ) ;
unsigned int V_80 = F_50 ( V_78 ) ;
int V_16 = - V_40 ;
bool V_106 = false ;
char * V_91 ;
V_2 = F_67 ( sizeof( * V_2 ) + V_105 + V_80 , V_39 ) ;
if ( F_68 ( ! V_2 ) )
goto V_107;
V_15 = & V_2 -> V_15 ;
V_91 = ( char * ) ( V_15 + 1 ) + V_105 ;
V_2 -> V_19 = V_70 -> V_108 ;
F_69 ( & V_2 -> V_36 ) ;
V_2 -> V_20 = & V_27 -> V_20 ;
F_52 ( V_23 ) ;
V_104 = F_63 ( V_27 ) ;
V_2 -> V_12 = F_70 ( V_104 , sizeof( * V_8 ) , V_39 ) ;
if ( F_68 ( ! V_2 -> V_12 ) )
goto V_94;
F_21 ( V_2 -> V_12 , V_104 ) ;
memcpy ( V_91 , V_27 -> V_91 , V_80 ) ;
F_71 ( V_15 , V_78 ) ;
F_72 ( V_15 , V_109 ,
F_10 , V_2 ) ;
while ( F_73 ( & V_70 -> V_110 ) ) {
struct V_3 * V_4 ;
int V_32 ;
if ( ! V_27 -> V_32 ) {
V_16 = F_46 ( V_23 , V_46 ) ;
if ( V_16 )
goto free;
}
V_7 = F_25 ( & V_27 -> V_34 ,
struct V_33 , V_36 ) ;
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_43 )
V_8 ++ ;
V_32 = F_26 (unsigned long, ctx->used,
iov_iter_count(&msg->msg_iter)) ;
V_32 = F_26 (unsigned long, used, sg->length) ;
if ( V_103 == V_104 ) {
struct V_6 * V_5 ;
int V_111 ;
V_5 = F_70 ( V_104 * 2 , sizeof( * V_5 ) ,
V_39 ) ;
if ( ! V_5 ) {
V_16 = - V_40 ;
goto free;
}
F_21 ( V_5 , V_104 * 2 ) ;
for ( V_111 = 0 ; V_111 < V_104 ; V_111 ++ )
F_62 ( & V_5 [ V_111 ] , F_7 ( & V_2 -> V_12 [ V_111 ] ) ,
V_2 -> V_12 [ V_111 ] . V_43 ,
V_2 -> V_12 [ V_111 ] . V_44 ) ;
F_4 ( V_2 -> V_12 ) ;
V_2 -> V_12 = V_5 ;
V_104 *= 2 ;
V_106 = true ;
}
F_62 ( V_2 -> V_12 + V_103 ++ , F_7 ( V_8 ) , V_8 -> V_43 ,
V_8 -> V_44 ) ;
if ( F_19 ( & V_2 -> V_36 ) ) {
V_4 = & V_2 -> V_11 ;
F_23 ( & V_4 -> V_36 , & V_2 -> V_36 ) ;
} else {
V_4 = F_74 ( sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 ) {
V_16 = - V_40 ;
goto free;
}
F_23 ( & V_4 -> V_36 , & V_2 -> V_36 ) ;
}
V_32 = F_75 ( & V_4 -> V_7 , & V_70 -> V_110 , V_32 ) ;
V_16 = V_32 ;
if ( V_32 < 0 )
goto free;
if ( V_102 )
F_76 ( & V_102 -> V_7 , & V_4 -> V_7 ) ;
V_102 = V_4 ;
V_95 += V_32 ;
F_24 ( V_23 , V_32 , 0 ) ;
F_77 ( & V_70 -> V_110 , V_32 ) ;
}
if ( V_106 )
F_58 ( V_2 -> V_12 + V_103 - 1 ) ;
F_78 ( V_15 , V_2 -> V_12 , V_2 -> V_11 . V_7 . V_8 ,
V_95 , V_91 ) ;
V_16 = V_27 -> V_84 ? F_79 ( V_15 ) :
F_80 ( V_15 ) ;
if ( V_16 == - V_112 ) {
F_81 ( & V_27 -> V_20 ) ;
V_16 = - V_113 ;
V_2 = NULL ;
goto V_94;
}
free:
F_1 ( V_2 ) ;
V_94:
F_39 ( V_23 ) ;
F_59 ( V_23 ) ;
F_12 ( V_2 ) ;
V_107:
return V_16 ;
}
static int F_82 ( struct V_68 * V_22 , struct V_69 * V_70 ,
int V_46 )
{
struct V_22 * V_23 = V_22 -> V_23 ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_22 * V_72 = V_25 -> V_73 ;
struct V_24 * V_74 = F_14 ( V_72 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_75 * V_76 = V_74 -> V_28 ;
struct V_77 * V_78 = V_76 -> V_79 ;
unsigned V_114 = F_83 ( V_78 ) ;
struct V_33 * V_7 ;
struct V_6 * V_8 ;
int V_16 = - V_52 ;
int V_32 ;
long V_83 = 0 ;
F_52 ( V_23 ) ;
while ( F_84 ( V_70 ) ) {
if ( ! V_27 -> V_32 ) {
V_16 = F_46 ( V_23 , V_46 ) ;
if ( V_16 )
goto V_94;
}
V_32 = F_26 (unsigned long, ctx->used, msg_data_left(msg)) ;
V_32 = F_75 ( & V_27 -> V_4 , & V_70 -> V_110 , V_32 ) ;
V_16 = V_32 ;
if ( V_16 < 0 )
goto V_94;
if ( V_27 -> V_93 || V_32 < V_27 -> V_32 )
V_32 -= V_32 % V_114 ;
V_16 = - V_90 ;
if ( ! V_32 )
goto free;
V_7 = F_25 ( & V_27 -> V_34 ,
struct V_33 , V_36 ) ;
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_43 )
V_8 ++ ;
F_78 ( & V_27 -> V_15 , V_8 , V_27 -> V_4 . V_8 , V_32 ,
V_27 -> V_91 ) ;
V_16 = F_85 (
V_27 -> V_84 ?
F_79 ( & V_27 -> V_15 ) :
F_80 ( & V_27 -> V_15 ) ,
& V_27 -> V_115 ) ;
free:
F_3 ( & V_27 -> V_4 ) ;
if ( V_16 )
goto V_94;
V_83 += V_32 ;
F_24 ( V_23 , V_32 , 1 ) ;
F_77 ( & V_70 -> V_110 , V_32 ) ;
}
V_16 = 0 ;
V_94:
F_39 ( V_23 ) ;
F_59 ( V_23 ) ;
return V_83 ? : V_16 ;
}
static int F_86 ( struct V_68 * V_22 , struct V_69 * V_70 ,
T_1 V_116 , int V_46 )
{
return ( V_70 -> V_108 && ! F_87 ( V_70 -> V_108 ) ) ?
F_65 ( V_22 , V_70 , V_46 ) :
F_82 ( V_22 , V_70 , V_46 ) ;
}
static unsigned int F_88 ( struct V_117 * V_117 , struct V_68 * V_22 ,
T_3 * V_47 )
{
struct V_22 * V_23 = V_22 -> V_23 ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
unsigned int V_118 ;
F_89 ( V_117 , F_35 ( V_23 ) , V_47 ) ;
V_118 = 0 ;
if ( V_27 -> V_32 )
V_118 |= V_59 | V_60 ;
if ( F_16 ( V_23 ) )
V_118 |= V_65 | V_119 | V_120 ;
return V_118 ;
}
static int F_90 ( struct V_68 * V_22 )
{
int V_16 = 0 ;
struct V_22 * V_72 ;
struct V_24 * V_74 ;
struct V_75 * V_78 ;
struct V_22 * V_23 = V_22 -> V_23 ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
F_52 ( V_23 ) ;
if ( V_25 -> V_121 )
goto V_122;
V_72 = V_25 -> V_73 ;
V_74 = F_14 ( V_25 -> V_73 ) ;
V_78 = V_74 -> V_28 ;
V_16 = - V_123 ;
F_91 ( V_72 , V_124 ) ;
if ( ! V_78 -> V_125 )
goto V_94;
if ( ! V_74 -> V_121 ++ )
F_92 ( V_72 ) ;
V_25 -> V_121 = 1 ;
F_93 ( V_72 ) ;
V_16 = 0 ;
V_94:
F_59 ( V_72 ) ;
V_122:
F_59 ( V_23 ) ;
return V_16 ;
}
static int F_94 ( struct V_68 * V_22 , struct V_69 * V_70 ,
T_1 V_71 )
{
int V_16 ;
V_16 = F_90 ( V_22 ) ;
if ( V_16 )
return V_16 ;
return F_49 ( V_22 , V_70 , V_71 ) ;
}
static T_2 F_95 ( struct V_68 * V_22 , struct V_13 * V_13 ,
int V_44 , T_1 V_71 , int V_46 )
{
int V_16 ;
V_16 = F_90 ( V_22 ) ;
if ( V_16 )
return V_16 ;
return F_60 ( V_22 , V_13 , V_44 , V_71 , V_46 ) ;
}
static int F_96 ( struct V_68 * V_22 , struct V_69 * V_70 ,
T_1 V_116 , int V_46 )
{
int V_16 ;
V_16 = F_90 ( V_22 ) ;
if ( V_16 )
return V_16 ;
return F_86 ( V_22 , V_70 , V_116 , V_46 ) ;
}
static void * F_97 ( const char * V_126 , T_4 type , T_4 V_118 )
{
struct V_75 * V_78 ;
struct V_77 * V_79 ;
V_78 = F_67 ( sizeof( * V_78 ) , V_39 ) ;
if ( ! V_78 )
return F_98 ( - V_40 ) ;
V_79 = F_99 ( V_126 , type , V_118 ) ;
if ( F_100 ( V_79 ) ) {
F_4 ( V_78 ) ;
return F_101 ( V_79 ) ;
}
V_78 -> V_79 = V_79 ;
return V_78 ;
}
static void F_102 ( void * V_28 )
{
struct V_75 * V_78 = V_28 ;
F_103 ( V_78 -> V_79 ) ;
F_4 ( V_78 ) ;
}
static int F_104 ( void * V_28 , const T_5 * V_127 , unsigned int V_128 )
{
struct V_75 * V_78 = V_28 ;
int V_16 ;
V_16 = F_105 ( V_78 -> V_79 , V_127 , V_128 ) ;
V_78 -> V_125 = ! V_16 ;
return V_16 ;
}
static void F_106 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
int V_129 = 0 ;
while ( F_107 ( & V_27 -> V_20 ) && V_129 ++ < 100 )
F_108 ( 100 ) ;
}
static void F_109 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_77 * V_78 = F_110 ( & V_27 -> V_15 ) ;
if ( F_107 ( & V_27 -> V_20 ) )
F_106 ( V_23 ) ;
F_30 ( V_23 ) ;
F_111 ( V_23 , V_27 -> V_91 , F_50 ( V_78 ) ) ;
F_29 ( V_23 , V_27 , V_27 -> V_95 ) ;
F_112 ( V_23 ) ;
}
static int F_113 ( void * V_28 , struct V_22 * V_23 )
{
struct V_26 * V_27 ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
struct V_75 * V_78 = V_28 ;
struct V_77 * V_79 = V_78 -> V_79 ;
unsigned int V_95 = sizeof( * V_27 ) + F_66 ( V_79 ) ;
V_27 = F_20 ( V_23 , V_95 , V_39 ) ;
if ( ! V_27 )
return - V_40 ;
V_27 -> V_91 = F_20 ( V_23 , F_50 ( V_79 ) ,
V_39 ) ;
if ( ! V_27 -> V_91 ) {
F_29 ( V_23 , V_27 , V_95 ) ;
return - V_40 ;
}
memset ( V_27 -> V_91 , 0 , F_50 ( V_79 ) ) ;
F_69 ( & V_27 -> V_34 ) ;
V_27 -> V_95 = V_95 ;
V_27 -> V_32 = 0 ;
V_27 -> V_93 = 0 ;
V_27 -> V_45 = 0 ;
V_27 -> V_84 = 0 ;
F_114 ( & V_27 -> V_20 , 0 ) ;
F_115 ( & V_27 -> V_115 ) ;
V_25 -> V_28 = V_27 ;
F_71 ( & V_27 -> V_15 , V_79 ) ;
F_72 ( & V_27 -> V_15 , V_109 |
V_130 ,
V_131 , & V_27 -> V_115 ) ;
V_23 -> V_132 = F_109 ;
return 0 ;
}
static int F_116 ( void * V_28 , struct V_22 * V_23 )
{
struct V_75 * V_78 = V_28 ;
if ( ! V_78 -> V_125 && F_117 ( V_78 -> V_79 ) )
return - V_123 ;
return F_113 ( V_28 , V_23 ) ;
}
static int T_6 F_118 ( void )
{
return F_119 ( & V_133 ) ;
}
static void T_7 F_120 ( void )
{
int V_16 = F_121 ( & V_133 ) ;
F_122 ( V_16 ) ;
}
