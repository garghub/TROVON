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
F_6 (sgl, sg, n, i)
F_7 ( F_8 ( V_8 ) ) ;
F_4 ( V_2 -> V_12 ) ;
}
static void F_9 ( struct V_13 * V_14 , int V_15 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_17 * V_18 = V_2 -> V_18 ;
F_10 ( V_2 -> V_19 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
V_18 -> V_20 ( V_18 , V_15 , V_15 ) ;
}
static inline int F_12 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
return F_14 ( int , F_14 ( int , V_22 -> V_28 & V_29 , V_30 ) -
V_26 -> V_31 , 0 ) ;
}
static inline bool F_15 ( struct V_21 * V_22 )
{
return V_30 <= F_12 ( V_22 ) ;
}
static int F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_32 * V_7 ;
struct V_6 * V_8 = NULL ;
V_7 = F_17 ( V_26 -> V_33 . V_34 , struct V_32 , V_35 ) ;
if ( ! F_18 ( & V_26 -> V_33 ) )
V_8 = V_7 -> V_8 ;
if ( ! V_8 || V_7 -> V_36 >= V_37 ) {
V_7 = F_19 ( V_22 , sizeof( * V_7 ) +
sizeof( V_7 -> V_8 [ 0 ] ) * ( V_37 + 1 ) ,
V_38 ) ;
if ( ! V_7 )
return - V_39 ;
F_20 ( V_7 -> V_8 , V_37 + 1 ) ;
V_7 -> V_36 = 0 ;
if ( V_8 )
F_21 ( V_8 , V_37 + 1 , V_7 -> V_8 ) ;
F_22 ( & V_7 -> V_35 , & V_26 -> V_33 ) ;
}
return 0 ;
}
static void F_23 ( struct V_21 * V_22 , T_1 V_31 , int V_40 )
{
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_32 * V_7 ;
struct V_6 * V_8 ;
int V_9 ;
while ( ! F_18 ( & V_26 -> V_33 ) ) {
V_7 = F_24 ( & V_26 -> V_33 , struct V_32 ,
V_35 ) ;
V_8 = V_7 -> V_8 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_36 ; V_9 ++ ) {
T_1 V_41 = F_25 ( T_1 , V_31 , V_8 [ V_9 ] . V_42 ) ;
if ( ! F_8 ( V_8 + V_9 ) )
continue;
V_8 [ V_9 ] . V_42 -= V_41 ;
V_8 [ V_9 ] . V_43 += V_41 ;
V_31 -= V_41 ;
V_26 -> V_31 -= V_41 ;
if ( V_8 [ V_9 ] . V_42 )
return;
if ( V_40 )
F_7 ( F_8 ( V_8 + V_9 ) ) ;
F_26 ( V_8 + V_9 , NULL ) ;
}
F_27 ( & V_7 -> V_35 ) ;
F_28 ( V_22 , V_7 ,
sizeof( * V_7 ) + sizeof( V_7 -> V_8 [ 0 ] ) *
( V_37 + 1 ) ) ;
}
if ( ! V_26 -> V_31 )
V_26 -> V_44 = 0 ;
}
static void F_29 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
F_23 ( V_22 , V_26 -> V_31 , 1 ) ;
}
static int F_30 ( struct V_21 * V_22 , unsigned V_45 )
{
F_31 ( V_46 , V_47 ) ;
int V_15 = - V_48 ;
long V_49 ;
if ( V_45 & V_50 )
return - V_51 ;
F_32 ( V_52 , V_22 ) ;
F_33 ( F_34 ( V_22 ) , & V_46 ) ;
for (; ; ) {
if ( F_35 ( V_53 ) )
break;
V_49 = V_54 ;
if ( F_36 ( V_22 , & V_49 , F_15 ( V_22 ) , & V_46 ) ) {
V_15 = 0 ;
break;
}
}
F_37 ( F_34 ( V_22 ) , & V_46 ) ;
return V_15 ;
}
static void F_38 ( struct V_21 * V_22 )
{
struct V_55 * V_56 ;
if ( ! F_15 ( V_22 ) )
return;
F_39 () ;
V_56 = F_40 ( V_22 -> V_57 ) ;
if ( F_41 ( V_56 ) )
F_42 ( & V_56 -> V_46 , V_58 |
V_59 |
V_60 ) ;
F_43 ( V_22 , V_61 , V_62 ) ;
F_44 () ;
}
static int F_45 ( struct V_21 * V_22 , unsigned V_45 )
{
F_31 ( V_46 , V_47 ) ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
long V_49 ;
int V_15 = - V_48 ;
if ( V_45 & V_50 ) {
return - V_51 ;
}
F_32 ( V_63 , V_22 ) ;
F_33 ( F_34 ( V_22 ) , & V_46 ) ;
for (; ; ) {
if ( F_35 ( V_53 ) )
break;
V_49 = V_54 ;
if ( F_36 ( V_22 , & V_49 , V_26 -> V_31 , & V_46 ) ) {
V_15 = 0 ;
break;
}
}
F_37 ( F_34 ( V_22 ) , & V_46 ) ;
F_46 ( V_63 , V_22 ) ;
return V_15 ;
}
static void F_47 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_55 * V_56 ;
if ( ! V_26 -> V_31 )
return;
F_39 () ;
V_56 = F_40 ( V_22 -> V_57 ) ;
if ( F_41 ( V_56 ) )
F_42 ( & V_56 -> V_46 , V_64 |
V_59 |
V_60 ) ;
F_43 ( V_22 , V_65 , V_66 ) ;
F_44 () ;
}
static int F_48 ( struct V_67 * V_21 , struct V_68 * V_69 ,
T_1 V_70 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_21 * V_71 = V_24 -> V_72 ;
struct V_23 * V_73 = F_13 ( V_71 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_74 * V_75 = V_73 -> V_27 ;
struct V_76 * V_77 = V_75 -> V_78 ;
unsigned V_79 = F_49 ( V_77 ) ;
struct V_32 * V_7 ;
struct V_80 V_81 = {} ;
long V_82 = 0 ;
bool V_83 = 0 ;
bool V_84 = 0 ;
int V_15 ;
int V_9 ;
if ( V_69 -> V_85 ) {
V_15 = F_50 ( V_69 , & V_81 ) ;
if ( V_15 )
return V_15 ;
V_84 = 1 ;
switch ( V_81 . V_86 ) {
case V_87 :
V_83 = 1 ;
break;
case V_88 :
V_83 = 0 ;
break;
default:
return - V_89 ;
}
if ( V_81 . V_90 && V_81 . V_90 -> V_91 != V_79 )
return - V_89 ;
}
V_15 = - V_89 ;
F_51 ( V_22 ) ;
if ( ! V_26 -> V_92 && V_26 -> V_31 )
goto V_93;
if ( V_84 ) {
V_26 -> V_83 = V_83 ;
if ( V_81 . V_90 )
memcpy ( V_26 -> V_90 , V_81 . V_90 -> V_90 , V_79 ) ;
}
while ( V_70 ) {
struct V_6 * V_8 ;
unsigned long V_94 = V_70 ;
T_1 V_41 ;
if ( V_26 -> V_44 ) {
V_7 = F_17 ( V_26 -> V_33 . V_34 ,
struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 + V_7 -> V_36 - 1 ;
V_94 = F_25 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_15 = F_52 ( F_53 ( F_8 ( V_8 ) ) +
V_8 -> V_43 + V_8 -> V_42 ,
V_69 , V_94 ) ;
if ( V_15 )
goto V_93;
V_8 -> V_42 += V_94 ;
V_26 -> V_44 = ( V_8 -> V_43 + V_8 -> V_42 ) &
( V_30 - 1 ) ;
V_26 -> V_31 += V_94 ;
V_82 += V_94 ;
V_70 -= V_94 ;
continue;
}
if ( ! F_15 ( V_22 ) ) {
V_15 = F_30 ( V_22 , V_69 -> V_95 ) ;
if ( V_15 )
goto V_93;
}
V_94 = F_25 (unsigned long, len, skcipher_sndbuf(sk)) ;
V_15 = F_16 ( V_22 ) ;
if ( V_15 )
goto V_93;
V_7 = F_17 ( V_26 -> V_33 . V_34 , struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 ;
if ( V_7 -> V_36 )
F_54 ( V_8 + V_7 -> V_36 - 1 ) ;
do {
V_9 = V_7 -> V_36 ;
V_41 = F_25 ( T_1 , V_94 , V_30 ) ;
F_26 ( V_8 + V_9 , F_55 ( V_38 ) ) ;
V_15 = - V_39 ;
if ( ! F_8 ( V_8 + V_9 ) )
goto V_93;
V_15 = F_52 ( F_53 ( F_8 ( V_8 + V_9 ) ) ,
V_69 , V_41 ) ;
if ( V_15 ) {
F_56 ( F_8 ( V_8 + V_9 ) ) ;
F_26 ( V_8 + V_9 , NULL ) ;
goto V_93;
}
V_8 [ V_9 ] . V_42 = V_41 ;
V_94 -= V_41 ;
V_26 -> V_31 += V_41 ;
V_82 += V_41 ;
V_70 -= V_41 ;
V_7 -> V_36 ++ ;
} while ( V_94 && V_7 -> V_36 < V_37 );
if ( ! V_70 )
F_57 ( V_8 + V_7 -> V_36 - 1 ) ;
V_26 -> V_44 = V_41 & ( V_30 - 1 ) ;
}
V_15 = 0 ;
V_26 -> V_92 = V_69 -> V_95 & V_96 ;
V_93:
F_47 ( V_22 ) ;
F_58 ( V_22 ) ;
return V_82 ? : V_15 ;
}
static T_2 F_59 ( struct V_67 * V_21 , struct V_97 * V_97 ,
int V_43 , T_1 V_70 , int V_45 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_32 * V_7 ;
int V_15 = - V_89 ;
if ( V_45 & V_98 )
V_45 |= V_96 ;
F_51 ( V_22 ) ;
if ( ! V_26 -> V_92 && V_26 -> V_31 )
goto V_93;
if ( ! V_70 )
goto V_99;
if ( ! F_15 ( V_22 ) ) {
V_15 = F_30 ( V_22 , V_45 ) ;
if ( V_15 )
goto V_93;
}
V_15 = F_16 ( V_22 ) ;
if ( V_15 )
goto V_93;
V_26 -> V_44 = 0 ;
V_7 = F_17 ( V_26 -> V_33 . V_34 , struct V_32 , V_35 ) ;
if ( V_7 -> V_36 )
F_54 ( V_7 -> V_8 + V_7 -> V_36 - 1 ) ;
F_57 ( V_7 -> V_8 + V_7 -> V_36 ) ;
F_60 ( V_97 ) ;
F_61 ( V_7 -> V_8 + V_7 -> V_36 , V_97 , V_70 , V_43 ) ;
V_7 -> V_36 ++ ;
V_26 -> V_31 += V_70 ;
V_99:
V_26 -> V_92 = V_45 & V_96 ;
V_93:
F_47 ( V_22 ) ;
F_58 ( V_22 ) ;
return V_15 ? : V_70 ;
}
static int F_62 ( struct V_25 * V_26 )
{
struct V_32 * V_7 ;
struct V_6 * V_8 ;
int V_100 = 0 ;
F_63 (sgl, &ctx->tsgl, list) {
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_42 )
V_8 ++ ;
V_100 += F_5 ( V_8 ) ;
}
return V_100 ;
}
static int F_64 ( struct V_67 * V_21 , struct V_68 * V_69 ,
int V_45 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_21 * V_71 = V_24 -> V_72 ;
struct V_23 * V_73 = F_13 ( V_71 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_74 * V_75 = V_73 -> V_27 ;
struct V_76 * V_77 = V_75 -> V_78 ;
struct V_32 * V_7 ;
struct V_6 * V_8 ;
struct V_1 * V_2 ;
struct V_101 * V_14 ;
struct V_3 * V_102 = NULL ;
unsigned int V_103 = 0 , V_94 = 0 , V_104 ;
unsigned int V_105 = F_65 ( V_77 ) ;
unsigned int V_79 = F_49 ( V_77 ) ;
int V_15 = - V_39 ;
bool V_106 = false ;
char * V_90 ;
V_2 = F_66 ( sizeof( * V_2 ) + V_105 + V_79 , V_38 ) ;
if ( F_67 ( ! V_2 ) )
goto V_107;
V_14 = & V_2 -> V_14 ;
V_90 = ( char * ) ( V_14 + 1 ) + V_105 ;
V_2 -> V_18 = V_69 -> V_108 ;
F_68 ( & V_2 -> V_35 ) ;
V_2 -> V_19 = & V_26 -> V_19 ;
F_51 ( V_22 ) ;
V_104 = F_62 ( V_26 ) ;
V_2 -> V_12 = F_69 ( V_104 , sizeof( * V_8 ) , V_38 ) ;
if ( F_67 ( ! V_2 -> V_12 ) )
goto V_93;
F_20 ( V_2 -> V_12 , V_104 ) ;
memcpy ( V_90 , V_26 -> V_90 , V_79 ) ;
F_70 ( V_14 , V_77 ) ;
F_71 ( V_14 , V_109 ,
F_9 , V_2 ) ;
while ( F_72 ( & V_69 -> V_110 ) ) {
struct V_3 * V_4 ;
int V_31 ;
if ( ! V_26 -> V_31 ) {
V_15 = F_45 ( V_22 , V_45 ) ;
if ( V_15 )
goto free;
}
V_7 = F_24 ( & V_26 -> V_33 ,
struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_42 )
V_8 ++ ;
V_31 = F_25 (unsigned long, ctx->used,
iov_iter_count(&msg->msg_iter)) ;
V_31 = F_25 (unsigned long, used, sg->length) ;
if ( V_103 == V_104 ) {
struct V_6 * V_5 ;
int V_111 ;
V_5 = F_69 ( V_104 * 2 , sizeof( * V_5 ) ,
V_38 ) ;
if ( ! V_5 ) {
V_15 = - V_39 ;
goto free;
}
F_20 ( V_5 , V_104 * 2 ) ;
for ( V_111 = 0 ; V_111 < V_104 ; V_111 ++ )
F_61 ( & V_5 [ V_111 ] , F_8 ( & V_2 -> V_12 [ V_111 ] ) ,
V_2 -> V_12 [ V_111 ] . V_42 ,
V_2 -> V_12 [ V_111 ] . V_43 ) ;
F_4 ( V_2 -> V_12 ) ;
V_2 -> V_12 = V_5 ;
V_104 *= 2 ;
V_106 = true ;
}
F_61 ( V_2 -> V_12 + V_103 ++ , F_8 ( V_8 ) , V_8 -> V_42 ,
V_8 -> V_43 ) ;
if ( F_18 ( & V_2 -> V_35 ) ) {
V_4 = & V_2 -> V_11 ;
F_22 ( & V_4 -> V_35 , & V_2 -> V_35 ) ;
} else {
V_4 = F_73 ( sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 ) {
V_15 = - V_39 ;
goto free;
}
F_22 ( & V_4 -> V_35 , & V_2 -> V_35 ) ;
}
V_31 = F_74 ( & V_4 -> V_7 , & V_69 -> V_110 , V_31 ) ;
V_15 = V_31 ;
if ( V_31 < 0 )
goto free;
if ( V_102 )
F_75 ( & V_102 -> V_7 , & V_4 -> V_7 ) ;
V_102 = V_4 ;
V_94 += V_31 ;
F_23 ( V_22 , V_31 , 0 ) ;
F_76 ( & V_69 -> V_110 , V_31 ) ;
}
if ( V_106 )
F_57 ( V_2 -> V_12 + V_103 - 1 ) ;
F_77 ( V_14 , V_2 -> V_12 , V_2 -> V_11 . V_7 . V_8 ,
V_94 , V_90 ) ;
V_15 = V_26 -> V_83 ? F_78 ( V_14 ) :
F_79 ( V_14 ) ;
if ( V_15 == - V_112 ) {
F_80 ( & V_26 -> V_19 ) ;
V_15 = - V_113 ;
V_2 = NULL ;
goto V_93;
}
free:
F_1 ( V_2 ) ;
V_93:
F_38 ( V_22 ) ;
F_58 ( V_22 ) ;
F_11 ( V_2 ) ;
V_107:
return V_15 ;
}
static int F_81 ( struct V_67 * V_21 , struct V_68 * V_69 ,
int V_45 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_21 * V_71 = V_24 -> V_72 ;
struct V_23 * V_73 = F_13 ( V_71 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_74 * V_75 = V_73 -> V_27 ;
struct V_76 * V_77 = V_75 -> V_78 ;
unsigned V_114 = F_82 ( V_77 ) ;
struct V_32 * V_7 ;
struct V_6 * V_8 ;
int V_15 = - V_51 ;
int V_31 ;
long V_82 = 0 ;
F_51 ( V_22 ) ;
while ( F_83 ( V_69 ) ) {
if ( ! V_26 -> V_31 ) {
V_15 = F_45 ( V_22 , V_45 ) ;
if ( V_15 )
goto V_93;
}
V_31 = F_25 (unsigned long, ctx->used, msg_data_left(msg)) ;
V_31 = F_74 ( & V_26 -> V_4 , & V_69 -> V_110 , V_31 ) ;
V_15 = V_31 ;
if ( V_15 < 0 )
goto V_93;
if ( V_26 -> V_92 || V_31 < V_26 -> V_31 )
V_31 -= V_31 % V_114 ;
V_15 = - V_89 ;
if ( ! V_31 )
goto free;
V_7 = F_24 ( & V_26 -> V_33 ,
struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_42 )
V_8 ++ ;
F_77 ( & V_26 -> V_14 , V_8 , V_26 -> V_4 . V_8 , V_31 ,
V_26 -> V_90 ) ;
V_15 = F_84 (
V_26 -> V_83 ?
F_78 ( & V_26 -> V_14 ) :
F_79 ( & V_26 -> V_14 ) ,
& V_26 -> V_115 ) ;
free:
F_3 ( & V_26 -> V_4 ) ;
if ( V_15 )
goto V_93;
V_82 += V_31 ;
F_23 ( V_22 , V_31 , 1 ) ;
F_76 ( & V_69 -> V_110 , V_31 ) ;
}
V_15 = 0 ;
V_93:
F_38 ( V_22 ) ;
F_58 ( V_22 ) ;
return V_82 ? : V_15 ;
}
static int F_85 ( struct V_67 * V_21 , struct V_68 * V_69 ,
T_1 V_116 , int V_45 )
{
return ( V_69 -> V_108 && ! F_86 ( V_69 -> V_108 ) ) ?
F_64 ( V_21 , V_69 , V_45 ) :
F_81 ( V_21 , V_69 , V_45 ) ;
}
static unsigned int F_87 ( struct V_117 * V_117 , struct V_67 * V_21 ,
T_3 * V_46 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
unsigned int V_118 ;
F_88 ( V_117 , F_34 ( V_22 ) , V_46 ) ;
V_118 = 0 ;
if ( V_26 -> V_31 )
V_118 |= V_58 | V_59 ;
if ( F_15 ( V_22 ) )
V_118 |= V_64 | V_119 | V_120 ;
return V_118 ;
}
static int F_89 ( struct V_67 * V_21 )
{
int V_15 = 0 ;
struct V_21 * V_71 ;
struct V_23 * V_73 ;
struct V_74 * V_77 ;
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
F_51 ( V_22 ) ;
if ( V_24 -> V_121 )
goto V_122;
V_71 = V_24 -> V_72 ;
V_73 = F_13 ( V_24 -> V_72 ) ;
V_77 = V_73 -> V_27 ;
V_15 = - V_123 ;
F_90 ( V_71 , V_124 ) ;
if ( ! V_77 -> V_125 )
goto V_93;
if ( ! V_73 -> V_121 ++ )
F_91 ( V_71 ) ;
V_24 -> V_121 = 1 ;
F_92 ( V_71 ) ;
V_15 = 0 ;
V_93:
F_58 ( V_71 ) ;
V_122:
F_58 ( V_22 ) ;
return V_15 ;
}
static int F_93 ( struct V_67 * V_21 , struct V_68 * V_69 ,
T_1 V_70 )
{
int V_15 ;
V_15 = F_89 ( V_21 ) ;
if ( V_15 )
return V_15 ;
return F_48 ( V_21 , V_69 , V_70 ) ;
}
static T_2 F_94 ( struct V_67 * V_21 , struct V_97 * V_97 ,
int V_43 , T_1 V_70 , int V_45 )
{
int V_15 ;
V_15 = F_89 ( V_21 ) ;
if ( V_15 )
return V_15 ;
return F_59 ( V_21 , V_97 , V_43 , V_70 , V_45 ) ;
}
static int F_95 ( struct V_67 * V_21 , struct V_68 * V_69 ,
T_1 V_116 , int V_45 )
{
int V_15 ;
V_15 = F_89 ( V_21 ) ;
if ( V_15 )
return V_15 ;
return F_85 ( V_21 , V_69 , V_116 , V_45 ) ;
}
static void * F_96 ( const char * V_126 , T_4 type , T_4 V_118 )
{
struct V_74 * V_77 ;
struct V_76 * V_78 ;
V_77 = F_66 ( sizeof( * V_77 ) , V_38 ) ;
if ( ! V_77 )
return F_97 ( - V_39 ) ;
V_78 = F_98 ( V_126 , type , V_118 ) ;
if ( F_99 ( V_78 ) ) {
F_4 ( V_77 ) ;
return F_100 ( V_78 ) ;
}
V_77 -> V_78 = V_78 ;
return V_77 ;
}
static void F_101 ( void * V_27 )
{
struct V_74 * V_77 = V_27 ;
F_102 ( V_77 -> V_78 ) ;
F_4 ( V_77 ) ;
}
static int F_103 ( void * V_27 , const T_5 * V_127 , unsigned int V_128 )
{
struct V_74 * V_77 = V_27 ;
int V_15 ;
V_15 = F_104 ( V_77 -> V_78 , V_127 , V_128 ) ;
V_77 -> V_125 = ! V_15 ;
return V_15 ;
}
static void F_105 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
int V_129 = 0 ;
while ( F_106 ( & V_26 -> V_19 ) && V_129 ++ < 100 )
F_107 ( 100 ) ;
}
static void F_108 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_76 * V_77 = F_109 ( & V_26 -> V_14 ) ;
if ( F_106 ( & V_26 -> V_19 ) )
F_105 ( V_22 ) ;
F_29 ( V_22 ) ;
F_110 ( V_22 , V_26 -> V_90 , F_49 ( V_77 ) ) ;
F_28 ( V_22 , V_26 , V_26 -> V_94 ) ;
F_111 ( V_22 ) ;
}
static int F_112 ( void * V_27 , struct V_21 * V_22 )
{
struct V_25 * V_26 ;
struct V_23 * V_24 = F_13 ( V_22 ) ;
struct V_74 * V_77 = V_27 ;
struct V_76 * V_78 = V_77 -> V_78 ;
unsigned int V_94 = sizeof( * V_26 ) + F_65 ( V_78 ) ;
V_26 = F_19 ( V_22 , V_94 , V_38 ) ;
if ( ! V_26 )
return - V_39 ;
V_26 -> V_90 = F_19 ( V_22 , F_49 ( V_78 ) ,
V_38 ) ;
if ( ! V_26 -> V_90 ) {
F_28 ( V_22 , V_26 , V_94 ) ;
return - V_39 ;
}
memset ( V_26 -> V_90 , 0 , F_49 ( V_78 ) ) ;
F_68 ( & V_26 -> V_33 ) ;
V_26 -> V_94 = V_94 ;
V_26 -> V_31 = 0 ;
V_26 -> V_92 = 0 ;
V_26 -> V_44 = 0 ;
V_26 -> V_83 = 0 ;
F_113 ( & V_26 -> V_19 , 0 ) ;
F_114 ( & V_26 -> V_115 ) ;
V_24 -> V_27 = V_26 ;
F_70 ( & V_26 -> V_14 , V_78 ) ;
F_71 ( & V_26 -> V_14 , V_109 |
V_130 ,
V_131 , & V_26 -> V_115 ) ;
V_22 -> V_132 = F_108 ;
return 0 ;
}
static int F_115 ( void * V_27 , struct V_21 * V_22 )
{
struct V_74 * V_77 = V_27 ;
if ( ! V_77 -> V_125 && F_116 ( V_77 -> V_78 ) )
return - V_123 ;
return F_112 ( V_27 , V_22 ) ;
}
static int T_6 F_117 ( void )
{
return F_118 ( & V_133 ) ;
}
static void T_7 F_119 ( void )
{
int V_15 = F_120 ( & V_133 ) ;
F_121 ( V_15 ) ;
}
