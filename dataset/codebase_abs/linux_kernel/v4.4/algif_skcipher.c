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
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_1 * V_2 = F_11 ( V_14 , V_22 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
F_12 ( & V_22 -> V_26 ) ;
F_1 ( V_2 ) ;
F_4 ( V_14 ) ;
V_25 -> V_27 ( V_25 , V_15 , V_15 ) ;
}
static inline int F_13 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
return F_14 ( int , F_14 ( int , V_17 -> V_28 & V_29 , V_30 ) -
V_22 -> V_31 , 0 ) ;
}
static inline bool F_15 ( struct V_16 * V_17 )
{
return V_30 <= F_13 ( V_17 ) ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_32 * V_7 ;
struct V_6 * V_8 = NULL ;
V_7 = F_17 ( V_22 -> V_33 . V_34 , struct V_32 , V_35 ) ;
if ( ! F_18 ( & V_22 -> V_33 ) )
V_8 = V_7 -> V_8 ;
if ( ! V_8 || V_7 -> V_36 >= V_37 ) {
V_7 = F_19 ( V_17 , sizeof( * V_7 ) +
sizeof( V_7 -> V_8 [ 0 ] ) * ( V_37 + 1 ) ,
V_38 ) ;
if ( ! V_7 )
return - V_39 ;
F_20 ( V_7 -> V_8 , V_37 + 1 ) ;
V_7 -> V_36 = 0 ;
if ( V_8 )
F_21 ( V_8 , V_37 + 1 , V_7 -> V_8 ) ;
F_22 ( & V_7 -> V_35 , & V_22 -> V_33 ) ;
}
return 0 ;
}
static void F_23 ( struct V_16 * V_17 , int V_31 , int V_40 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_32 * V_7 ;
struct V_6 * V_8 ;
int V_9 ;
while ( ! F_18 ( & V_22 -> V_33 ) ) {
V_7 = F_24 ( & V_22 -> V_33 , struct V_32 ,
V_35 ) ;
V_8 = V_7 -> V_8 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_36 ; V_9 ++ ) {
int V_41 = F_25 ( int , V_31 , V_8 [ V_9 ] . V_42 ) ;
if ( ! F_8 ( V_8 + V_9 ) )
continue;
V_8 [ V_9 ] . V_42 -= V_41 ;
V_8 [ V_9 ] . V_43 += V_41 ;
V_31 -= V_41 ;
V_22 -> V_31 -= V_41 ;
if ( V_8 [ V_9 ] . V_42 )
return;
if ( V_40 )
F_7 ( F_8 ( V_8 + V_9 ) ) ;
F_26 ( V_8 + V_9 , NULL ) ;
}
F_27 ( & V_7 -> V_35 ) ;
F_28 ( V_17 , V_7 ,
sizeof( * V_7 ) + sizeof( V_7 -> V_8 [ 0 ] ) *
( V_37 + 1 ) ) ;
}
if ( ! V_22 -> V_31 )
V_22 -> V_44 = 0 ;
}
static void F_29 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
F_23 ( V_17 , V_22 -> V_31 , 1 ) ;
}
static int F_30 ( struct V_16 * V_17 , unsigned V_45 )
{
long V_46 ;
F_31 ( V_47 ) ;
int V_15 = - V_48 ;
if ( V_45 & V_49 )
return - V_50 ;
F_32 ( V_51 , V_17 ) ;
for (; ; ) {
if ( F_33 ( V_52 ) )
break;
F_34 ( F_35 ( V_17 ) , & V_47 , V_53 ) ;
V_46 = V_54 ;
if ( F_36 ( V_17 , & V_46 , F_15 ( V_17 ) ) ) {
V_15 = 0 ;
break;
}
}
F_37 ( F_35 ( V_17 ) , & V_47 ) ;
return V_15 ;
}
static void F_38 ( struct V_16 * V_17 )
{
struct V_55 * V_56 ;
if ( ! F_15 ( V_17 ) )
return;
F_39 () ;
V_56 = F_40 ( V_17 -> V_57 ) ;
if ( F_41 ( V_56 ) )
F_42 ( & V_56 -> V_47 , V_58 |
V_59 |
V_60 ) ;
F_43 ( V_17 , V_61 , V_62 ) ;
F_44 () ;
}
static int F_45 ( struct V_16 * V_17 , unsigned V_45 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
long V_46 ;
F_31 ( V_47 ) ;
int V_15 = - V_48 ;
if ( V_45 & V_49 ) {
return - V_50 ;
}
F_32 ( V_63 , V_17 ) ;
for (; ; ) {
if ( F_33 ( V_52 ) )
break;
F_34 ( F_35 ( V_17 ) , & V_47 , V_53 ) ;
V_46 = V_54 ;
if ( F_36 ( V_17 , & V_46 , V_22 -> V_31 ) ) {
V_15 = 0 ;
break;
}
}
F_37 ( F_35 ( V_17 ) , & V_47 ) ;
F_46 ( V_63 , V_17 ) ;
return V_15 ;
}
static void F_47 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_55 * V_56 ;
if ( ! V_22 -> V_31 )
return;
F_39 () ;
V_56 = F_40 ( V_17 -> V_57 ) ;
if ( F_41 ( V_56 ) )
F_42 ( & V_56 -> V_47 , V_64 |
V_59 |
V_60 ) ;
F_43 ( V_17 , V_65 , V_66 ) ;
F_44 () ;
}
static int F_48 ( struct V_67 * V_16 , struct V_68 * V_69 ,
T_1 V_70 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_71 * V_72 = F_49 ( & V_22 -> V_14 ) ;
unsigned V_73 = F_50 ( V_72 ) ;
struct V_32 * V_7 ;
struct V_74 V_75 = {} ;
long V_76 = 0 ;
bool V_77 = 0 ;
bool V_78 = 0 ;
int V_15 ;
int V_9 ;
if ( V_69 -> V_79 ) {
V_15 = F_51 ( V_69 , & V_75 ) ;
if ( V_15 )
return V_15 ;
V_78 = 1 ;
switch ( V_75 . V_80 ) {
case V_81 :
V_77 = 1 ;
break;
case V_82 :
V_77 = 0 ;
break;
default:
return - V_83 ;
}
if ( V_75 . V_84 && V_75 . V_84 -> V_85 != V_73 )
return - V_83 ;
}
V_15 = - V_83 ;
F_52 ( V_17 ) ;
if ( ! V_22 -> V_86 && V_22 -> V_31 )
goto V_87;
if ( V_78 ) {
V_22 -> V_77 = V_77 ;
if ( V_75 . V_84 )
memcpy ( V_22 -> V_84 , V_75 . V_84 -> V_84 , V_73 ) ;
}
while ( V_70 ) {
struct V_6 * V_8 ;
unsigned long V_88 = V_70 ;
int V_41 ;
if ( V_22 -> V_44 ) {
V_7 = F_17 ( V_22 -> V_33 . V_34 ,
struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 + V_7 -> V_36 - 1 ;
V_88 = F_25 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_15 = F_53 ( F_54 ( F_8 ( V_8 ) ) +
V_8 -> V_43 + V_8 -> V_42 ,
V_69 , V_88 ) ;
if ( V_15 )
goto V_87;
V_8 -> V_42 += V_88 ;
V_22 -> V_44 = ( V_8 -> V_43 + V_8 -> V_42 ) &
( V_30 - 1 ) ;
V_22 -> V_31 += V_88 ;
V_76 += V_88 ;
V_70 -= V_88 ;
continue;
}
if ( ! F_15 ( V_17 ) ) {
V_15 = F_30 ( V_17 , V_69 -> V_89 ) ;
if ( V_15 )
goto V_87;
}
V_88 = F_25 (unsigned long, len, skcipher_sndbuf(sk)) ;
V_15 = F_16 ( V_17 ) ;
if ( V_15 )
goto V_87;
V_7 = F_17 ( V_22 -> V_33 . V_34 , struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 ;
F_55 ( V_8 + V_7 -> V_36 ) ;
do {
V_9 = V_7 -> V_36 ;
V_41 = F_25 ( int , V_88 , V_30 ) ;
F_26 ( V_8 + V_9 , F_56 ( V_38 ) ) ;
V_15 = - V_39 ;
if ( ! F_8 ( V_8 + V_9 ) )
goto V_87;
V_15 = F_53 ( F_54 ( F_8 ( V_8 + V_9 ) ) ,
V_69 , V_41 ) ;
if ( V_15 ) {
F_57 ( F_8 ( V_8 + V_9 ) ) ;
F_26 ( V_8 + V_9 , NULL ) ;
goto V_87;
}
V_8 [ V_9 ] . V_42 = V_41 ;
V_88 -= V_41 ;
V_22 -> V_31 += V_41 ;
V_76 += V_41 ;
V_70 -= V_41 ;
V_7 -> V_36 ++ ;
} while ( V_88 && V_7 -> V_36 < V_37 );
if ( ! V_70 )
F_58 ( V_8 + V_7 -> V_36 - 1 ) ;
V_22 -> V_44 = V_41 & ( V_30 - 1 ) ;
}
V_15 = 0 ;
V_22 -> V_86 = V_69 -> V_89 & V_90 ;
V_87:
F_47 ( V_17 ) ;
F_59 ( V_17 ) ;
return V_76 ? : V_15 ;
}
static T_2 F_60 ( struct V_67 * V_16 , struct V_91 * V_91 ,
int V_43 , T_1 V_70 , int V_45 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_32 * V_7 ;
int V_15 = - V_83 ;
if ( V_45 & V_92 )
V_45 |= V_90 ;
F_52 ( V_17 ) ;
if ( ! V_22 -> V_86 && V_22 -> V_31 )
goto V_87;
if ( ! V_70 )
goto V_93;
if ( ! F_15 ( V_17 ) ) {
V_15 = F_30 ( V_17 , V_45 ) ;
if ( V_15 )
goto V_87;
}
V_15 = F_16 ( V_17 ) ;
if ( V_15 )
goto V_87;
V_22 -> V_44 = 0 ;
V_7 = F_17 ( V_22 -> V_33 . V_34 , struct V_32 , V_35 ) ;
if ( V_7 -> V_36 )
F_55 ( V_7 -> V_8 + V_7 -> V_36 - 1 ) ;
F_58 ( V_7 -> V_8 + V_7 -> V_36 ) ;
F_61 ( V_91 ) ;
F_62 ( V_7 -> V_8 + V_7 -> V_36 , V_91 , V_70 , V_43 ) ;
V_7 -> V_36 ++ ;
V_22 -> V_31 += V_70 ;
V_93:
V_22 -> V_86 = V_45 & V_90 ;
V_87:
F_47 ( V_17 ) ;
F_59 ( V_17 ) ;
return V_15 ? : V_70 ;
}
static int F_63 ( struct V_21 * V_22 )
{
struct V_32 * V_7 ;
struct V_6 * V_8 ;
int V_94 = 0 ;
F_64 (sgl, &ctx->tsgl, list) {
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_42 )
V_8 ++ ;
V_94 += F_5 ( V_8 ) ;
}
return V_94 ;
}
static int F_65 ( struct V_67 * V_16 , struct V_68 * V_69 ,
int V_45 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_32 * V_7 ;
struct V_6 * V_8 ;
struct V_1 * V_2 ;
struct V_95 * V_14 ;
struct V_3 * V_96 = NULL ;
unsigned int V_97 = 0 , V_88 = 0 , V_98 = F_63 ( V_22 ) ;
unsigned int V_99 = sizeof( struct V_1 ) +
F_66 ( V_22 ) + F_67 ( V_22 ) ;
int V_15 = - V_39 ;
bool V_100 = false ;
F_52 ( V_17 ) ;
V_14 = F_68 ( V_99 , V_38 ) ;
if ( F_69 ( ! V_14 ) )
goto V_87;
V_2 = F_11 ( V_14 , V_22 ) ;
V_2 -> V_25 = V_69 -> V_101 ;
memset ( & V_2 -> V_11 , '\0' , sizeof( struct V_3 ) ) ;
F_70 ( & V_2 -> V_35 ) ;
V_2 -> V_12 = F_71 ( V_98 , sizeof( * V_8 ) , V_38 ) ;
if ( F_69 ( ! V_2 -> V_12 ) ) {
F_4 ( V_14 ) ;
goto V_87;
}
F_20 ( V_2 -> V_12 , V_98 ) ;
memcpy ( V_2 -> V_84 , V_22 -> V_84 , F_67 ( V_22 ) ) ;
F_72 ( V_14 , F_49 ( & V_22 -> V_14 ) ) ;
F_73 ( V_14 , V_102 ,
F_9 , V_17 ) ;
while ( F_74 ( & V_69 -> V_103 ) ) {
struct V_3 * V_4 ;
int V_31 ;
if ( ! V_22 -> V_31 ) {
V_15 = F_45 ( V_17 , V_45 ) ;
if ( V_15 )
goto free;
}
V_7 = F_24 ( & V_22 -> V_33 ,
struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_42 )
V_8 ++ ;
V_31 = F_25 (unsigned long, ctx->used,
iov_iter_count(&msg->msg_iter)) ;
V_31 = F_25 (unsigned long, used, sg->length) ;
if ( V_97 == V_98 ) {
struct V_6 * V_5 ;
int V_104 ;
V_5 = F_71 ( V_98 * 2 , sizeof( * V_5 ) ,
V_38 ) ;
if ( ! V_5 )
goto free;
F_20 ( V_5 , V_98 * 2 ) ;
for ( V_104 = 0 ; V_104 < V_98 ; V_104 ++ )
F_62 ( & V_5 [ V_104 ] , F_8 ( & V_2 -> V_12 [ V_104 ] ) ,
V_2 -> V_12 [ V_104 ] . V_42 ,
V_2 -> V_12 [ V_104 ] . V_43 ) ;
F_4 ( V_2 -> V_12 ) ;
V_2 -> V_12 = V_5 ;
V_98 *= 2 ;
V_100 = true ;
}
F_62 ( V_2 -> V_12 + V_97 ++ , F_8 ( V_8 ) , V_8 -> V_42 ,
V_8 -> V_43 ) ;
if ( F_18 ( & V_2 -> V_35 ) ) {
V_4 = & V_2 -> V_11 ;
F_22 ( & V_4 -> V_35 , & V_2 -> V_35 ) ;
} else {
V_4 = F_68 ( sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 ) {
V_15 = - V_39 ;
goto free;
}
F_22 ( & V_4 -> V_35 , & V_2 -> V_35 ) ;
}
V_31 = F_75 ( & V_4 -> V_7 , & V_69 -> V_103 , V_31 ) ;
V_15 = V_31 ;
if ( V_31 < 0 )
goto free;
if ( V_96 )
F_76 ( & V_96 -> V_7 , & V_4 -> V_7 ) ;
V_96 = V_4 ;
V_88 += V_31 ;
F_23 ( V_17 , V_31 , 0 ) ;
F_77 ( & V_69 -> V_103 , V_31 ) ;
}
if ( V_100 )
F_58 ( V_2 -> V_12 + V_97 - 1 ) ;
F_78 ( V_14 , V_2 -> V_12 , V_2 -> V_11 . V_7 . V_8 ,
V_88 , V_2 -> V_84 ) ;
V_15 = V_22 -> V_77 ? F_79 ( V_14 ) :
F_80 ( V_14 ) ;
if ( V_15 == - V_105 ) {
F_81 ( & V_22 -> V_26 ) ;
V_15 = - V_106 ;
goto V_87;
}
free:
F_1 ( V_2 ) ;
F_4 ( V_14 ) ;
V_87:
F_38 ( V_17 ) ;
F_59 ( V_17 ) ;
return V_15 ;
}
static int F_82 ( struct V_67 * V_16 , struct V_68 * V_69 ,
int V_45 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
unsigned V_107 = F_83 ( F_49 (
& V_22 -> V_14 ) ) ;
struct V_32 * V_7 ;
struct V_6 * V_8 ;
int V_15 = - V_50 ;
int V_31 ;
long V_76 = 0 ;
F_52 ( V_17 ) ;
while ( F_84 ( V_69 ) ) {
V_7 = F_24 ( & V_22 -> V_33 ,
struct V_32 , V_35 ) ;
V_8 = V_7 -> V_8 ;
while ( ! V_8 -> V_42 )
V_8 ++ ;
if ( ! V_22 -> V_31 ) {
V_15 = F_45 ( V_17 , V_45 ) ;
if ( V_15 )
goto V_87;
}
V_31 = F_25 (unsigned long, ctx->used, msg_data_left(msg)) ;
V_31 = F_75 ( & V_22 -> V_4 , & V_69 -> V_103 , V_31 ) ;
V_15 = V_31 ;
if ( V_15 < 0 )
goto V_87;
if ( V_22 -> V_86 || V_31 < V_22 -> V_31 )
V_31 -= V_31 % V_107 ;
V_15 = - V_83 ;
if ( ! V_31 )
goto free;
F_78 ( & V_22 -> V_14 , V_8 , V_22 -> V_4 . V_8 , V_31 ,
V_22 -> V_84 ) ;
V_15 = F_85 (
V_22 -> V_77 ?
F_79 ( & V_22 -> V_14 ) :
F_80 ( & V_22 -> V_14 ) ,
& V_22 -> V_108 ) ;
free:
F_3 ( & V_22 -> V_4 ) ;
if ( V_15 )
goto V_87;
V_76 += V_31 ;
F_23 ( V_17 , V_31 , 1 ) ;
F_77 ( & V_69 -> V_103 , V_31 ) ;
}
V_15 = 0 ;
V_87:
F_38 ( V_17 ) ;
F_59 ( V_17 ) ;
return V_76 ? : V_15 ;
}
static int F_86 ( struct V_67 * V_16 , struct V_68 * V_69 ,
T_1 V_109 , int V_45 )
{
return ( V_69 -> V_101 && ! F_87 ( V_69 -> V_101 ) ) ?
F_65 ( V_16 , V_69 , V_45 ) :
F_82 ( V_16 , V_69 , V_45 ) ;
}
static unsigned int F_88 ( struct V_110 * V_110 , struct V_67 * V_16 ,
T_3 * V_47 )
{
struct V_16 * V_17 = V_16 -> V_17 ;
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
unsigned int V_111 ;
F_89 ( V_110 , F_35 ( V_17 ) , V_47 ) ;
V_111 = 0 ;
if ( V_22 -> V_31 )
V_111 |= V_58 | V_59 ;
if ( F_15 ( V_17 ) )
V_111 |= V_64 | V_112 | V_113 ;
return V_111 ;
}
static void * F_90 ( const char * V_114 , T_4 type , T_4 V_111 )
{
return F_91 ( V_114 , type , V_111 ) ;
}
static void F_92 ( void * V_23 )
{
F_93 ( V_23 ) ;
}
static int F_94 ( void * V_23 , const T_5 * V_115 , unsigned int V_116 )
{
return F_95 ( V_23 , V_115 , V_116 ) ;
}
static void F_96 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
int V_117 = 0 ;
while ( F_97 ( & V_22 -> V_26 ) && V_117 ++ < 100 )
F_98 ( 100 ) ;
}
static void F_99 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_10 ( V_17 ) ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_71 * V_72 = F_49 ( & V_22 -> V_14 ) ;
if ( F_97 ( & V_22 -> V_26 ) )
F_96 ( V_17 ) ;
F_29 ( V_17 ) ;
F_100 ( V_17 , V_22 -> V_84 , F_50 ( V_72 ) ) ;
F_28 ( V_17 , V_22 , V_22 -> V_88 ) ;
F_101 ( V_17 ) ;
}
static int F_102 ( void * V_23 , struct V_16 * V_17 )
{
struct V_21 * V_22 ;
struct V_19 * V_20 = F_10 ( V_17 ) ;
unsigned int V_88 = sizeof( * V_22 ) + F_103 ( V_23 ) ;
V_22 = F_19 ( V_17 , V_88 , V_38 ) ;
if ( ! V_22 )
return - V_39 ;
V_22 -> V_84 = F_19 ( V_17 , F_50 ( V_23 ) ,
V_38 ) ;
if ( ! V_22 -> V_84 ) {
F_28 ( V_17 , V_22 , V_88 ) ;
return - V_39 ;
}
memset ( V_22 -> V_84 , 0 , F_50 ( V_23 ) ) ;
F_70 ( & V_22 -> V_33 ) ;
V_22 -> V_88 = V_88 ;
V_22 -> V_31 = 0 ;
V_22 -> V_86 = 0 ;
V_22 -> V_44 = 0 ;
V_22 -> V_77 = 0 ;
F_104 ( & V_22 -> V_26 , 0 ) ;
F_105 ( & V_22 -> V_108 ) ;
V_20 -> V_23 = V_22 ;
F_72 ( & V_22 -> V_14 , V_23 ) ;
F_73 ( & V_22 -> V_14 , V_102 ,
V_118 , & V_22 -> V_108 ) ;
V_17 -> V_119 = F_99 ;
return 0 ;
}
static int T_6 F_106 ( void )
{
return F_107 ( & V_120 ) ;
}
static void T_7 F_108 ( void )
{
int V_15 = F_109 ( & V_120 ) ;
F_110 ( V_15 ) ;
}
