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
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
V_13 = F_6 ( V_6 -> V_16 . V_17 , struct V_12 , V_18 ) ;
if ( ! F_7 ( & V_6 -> V_16 ) )
V_15 = V_13 -> V_15 ;
if ( ! V_15 || V_13 -> V_19 >= V_20 ) {
V_13 = F_8 ( V_2 , sizeof( * V_13 ) +
sizeof( V_13 -> V_15 [ 0 ] ) * ( V_20 + 1 ) ,
V_21 ) ;
if ( ! V_13 )
return - V_22 ;
F_9 ( V_13 -> V_15 , V_20 + 1 ) ;
V_13 -> V_19 = 0 ;
if ( V_15 )
F_10 ( V_15 , V_20 + 1 , V_13 -> V_15 ) ;
F_11 ( & V_13 -> V_18 , & V_6 -> V_16 ) ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_23 ;
while ( ! F_7 ( & V_6 -> V_16 ) ) {
V_13 = F_13 ( & V_6 -> V_16 , struct V_12 ,
V_18 ) ;
V_15 = V_13 -> V_15 ;
for ( V_23 = 0 ; V_23 < V_13 -> V_19 ; V_23 ++ ) {
int V_24 = F_14 ( int , V_11 , V_15 [ V_23 ] . V_25 ) ;
if ( ! F_15 ( V_15 + V_23 ) )
continue;
V_15 [ V_23 ] . V_25 -= V_24 ;
V_15 [ V_23 ] . V_26 += V_24 ;
V_11 -= V_24 ;
V_6 -> V_11 -= V_24 ;
if ( V_15 [ V_23 ] . V_25 )
return;
F_16 ( F_15 ( V_15 + V_23 ) ) ;
F_17 ( V_15 + V_23 , NULL ) ;
}
F_18 ( & V_13 -> V_18 ) ;
F_19 ( V_2 , V_13 ,
sizeof( * V_13 ) + sizeof( V_13 -> V_15 [ 0 ] ) *
( V_20 + 1 ) ) ;
}
if ( ! V_6 -> V_11 )
V_6 -> V_27 = 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_12 ( V_2 , V_6 -> V_11 ) ;
}
static int F_21 ( struct V_1 * V_2 , unsigned V_28 )
{
long V_29 ;
F_22 ( V_30 ) ;
int V_31 = - V_32 ;
if ( V_28 & V_33 )
return - V_34 ;
F_23 ( V_35 , & V_2 -> V_36 -> V_28 ) ;
for (; ; ) {
if ( F_24 ( V_37 ) )
break;
F_25 ( F_26 ( V_2 ) , & V_30 , V_38 ) ;
V_29 = V_39 ;
if ( F_27 ( V_2 , & V_29 , F_4 ( V_2 ) ) ) {
V_31 = 0 ;
break;
}
}
F_28 ( F_26 ( V_2 ) , & V_30 ) ;
return V_31 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_40 * V_41 ;
if ( ! F_4 ( V_2 ) )
return;
F_30 () ;
V_41 = F_31 ( V_2 -> V_42 ) ;
if ( F_32 ( V_41 ) )
F_33 ( & V_41 -> V_30 , V_43 |
V_44 |
V_45 ) ;
F_34 ( V_2 , V_46 , V_47 ) ;
F_35 () ;
}
static int F_36 ( struct V_1 * V_2 , unsigned V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
long V_29 ;
F_22 ( V_30 ) ;
int V_31 = - V_32 ;
if ( V_28 & V_33 ) {
return - V_34 ;
}
F_23 ( V_48 , & V_2 -> V_36 -> V_28 ) ;
for (; ; ) {
if ( F_24 ( V_37 ) )
break;
F_25 ( F_26 ( V_2 ) , & V_30 , V_38 ) ;
V_29 = V_39 ;
if ( F_27 ( V_2 , & V_29 , V_6 -> V_11 ) ) {
V_31 = 0 ;
break;
}
}
F_28 ( F_26 ( V_2 ) , & V_30 ) ;
F_37 ( V_48 , & V_2 -> V_36 -> V_28 ) ;
return V_31 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_40 * V_41 ;
if ( ! V_6 -> V_11 )
return;
F_30 () ;
V_41 = F_31 ( V_2 -> V_42 ) ;
if ( F_32 ( V_41 ) )
F_33 ( & V_41 -> V_30 , V_49 |
V_44 |
V_45 ) ;
F_34 ( V_2 , V_50 , V_51 ) ;
F_35 () ;
}
static int F_39 ( struct V_52 * V_53 , struct V_54 * V_1 ,
struct V_55 * V_56 , T_1 V_57 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_58 * V_59 = F_40 ( & V_6 -> V_60 ) ;
unsigned V_61 = F_41 ( V_59 ) ;
struct V_12 * V_13 ;
struct V_62 V_63 = {} ;
long V_64 = 0 ;
bool V_65 = 0 ;
bool V_66 = 0 ;
int V_31 ;
int V_23 ;
if ( V_56 -> V_67 ) {
V_31 = F_42 ( V_56 , & V_63 ) ;
if ( V_31 )
return V_31 ;
V_66 = 1 ;
switch ( V_63 . V_68 ) {
case V_69 :
V_65 = 1 ;
break;
case V_70 :
V_65 = 0 ;
break;
default:
return - V_71 ;
}
if ( V_63 . V_72 && V_63 . V_72 -> V_73 != V_61 )
return - V_71 ;
}
V_31 = - V_71 ;
F_43 ( V_2 ) ;
if ( ! V_6 -> V_74 && V_6 -> V_11 )
goto V_75;
if ( V_66 ) {
V_6 -> V_65 = V_65 ;
if ( V_63 . V_72 )
memcpy ( V_6 -> V_72 , V_63 . V_72 -> V_72 , V_61 ) ;
}
while ( V_57 ) {
struct V_14 * V_15 ;
unsigned long V_76 = V_57 ;
int V_24 ;
if ( V_6 -> V_27 ) {
V_13 = F_6 ( V_6 -> V_16 . V_17 ,
struct V_12 , V_18 ) ;
V_15 = V_13 -> V_15 + V_13 -> V_19 - 1 ;
V_76 = F_14 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_31 = F_44 ( F_45 ( F_15 ( V_15 ) ) +
V_15 -> V_26 + V_15 -> V_25 ,
V_56 , V_76 ) ;
if ( V_31 )
goto V_75;
V_15 -> V_25 += V_76 ;
V_6 -> V_27 = ( V_15 -> V_26 + V_15 -> V_25 ) &
( V_10 - 1 ) ;
V_6 -> V_11 += V_76 ;
V_64 += V_76 ;
V_57 -= V_76 ;
continue;
}
if ( ! F_4 ( V_2 ) ) {
V_31 = F_21 ( V_2 , V_56 -> V_77 ) ;
if ( V_31 )
goto V_75;
}
V_76 = F_14 (unsigned long, len, skcipher_sndbuf(sk)) ;
V_31 = F_5 ( V_2 ) ;
if ( V_31 )
goto V_75;
V_13 = F_6 ( V_6 -> V_16 . V_17 , struct V_12 , V_18 ) ;
V_15 = V_13 -> V_15 ;
F_46 ( V_15 + V_13 -> V_19 ) ;
do {
V_23 = V_13 -> V_19 ;
V_24 = F_14 ( int , V_76 , V_10 ) ;
F_17 ( V_15 + V_23 , F_47 ( V_21 ) ) ;
V_31 = - V_22 ;
if ( ! F_15 ( V_15 + V_23 ) )
goto V_75;
V_31 = F_44 ( F_45 ( F_15 ( V_15 + V_23 ) ) ,
V_56 , V_24 ) ;
if ( V_31 ) {
F_48 ( F_15 ( V_15 + V_23 ) ) ;
F_17 ( V_15 + V_23 , NULL ) ;
goto V_75;
}
V_15 [ V_23 ] . V_25 = V_24 ;
V_76 -= V_24 ;
V_6 -> V_11 += V_24 ;
V_64 += V_24 ;
V_57 -= V_24 ;
V_13 -> V_19 ++ ;
} while ( V_76 && V_13 -> V_19 < V_20 );
if ( ! V_57 )
F_49 ( V_15 + V_13 -> V_19 - 1 ) ;
V_6 -> V_27 = V_24 & ( V_10 - 1 ) ;
}
V_31 = 0 ;
V_6 -> V_74 = V_56 -> V_77 & V_78 ;
V_75:
F_38 ( V_2 ) ;
F_50 ( V_2 ) ;
return V_64 ? : V_31 ;
}
static T_2 F_51 ( struct V_54 * V_1 , struct V_79 * V_79 ,
int V_26 , T_1 V_57 , int V_28 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_12 * V_13 ;
int V_31 = - V_71 ;
if ( V_28 & V_80 )
V_28 |= V_78 ;
F_43 ( V_2 ) ;
if ( ! V_6 -> V_74 && V_6 -> V_11 )
goto V_75;
if ( ! V_57 )
goto V_81;
if ( ! F_4 ( V_2 ) ) {
V_31 = F_21 ( V_2 , V_28 ) ;
if ( V_31 )
goto V_75;
}
V_31 = F_5 ( V_2 ) ;
if ( V_31 )
goto V_75;
V_6 -> V_27 = 0 ;
V_13 = F_6 ( V_6 -> V_16 . V_17 , struct V_12 , V_18 ) ;
if ( V_13 -> V_19 )
F_46 ( V_13 -> V_15 + V_13 -> V_19 - 1 ) ;
F_49 ( V_13 -> V_15 + V_13 -> V_19 ) ;
F_52 ( V_79 ) ;
F_53 ( V_13 -> V_15 + V_13 -> V_19 , V_79 , V_57 , V_26 ) ;
V_13 -> V_19 ++ ;
V_6 -> V_11 += V_57 ;
V_81:
V_6 -> V_74 = V_28 & V_78 ;
V_75:
F_38 ( V_2 ) ;
F_50 ( V_2 ) ;
return V_31 ? : V_57 ;
}
static int F_54 ( struct V_52 * V_53 , struct V_54 * V_1 ,
struct V_55 * V_56 , T_1 V_82 , int V_28 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_83 = F_55 ( F_40 (
& V_6 -> V_60 ) ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_31 = - V_34 ;
int V_11 ;
long V_64 = 0 ;
F_43 ( V_2 ) ;
while ( F_56 ( & V_56 -> V_84 ) ) {
V_13 = F_13 ( & V_6 -> V_16 ,
struct V_12 , V_18 ) ;
V_15 = V_13 -> V_15 ;
while ( ! V_15 -> V_25 )
V_15 ++ ;
if ( ! V_6 -> V_11 ) {
V_31 = F_36 ( V_2 , V_28 ) ;
if ( V_31 )
goto V_75;
}
V_11 = F_14 (unsigned long, ctx->used, iov_iter_count(&msg->msg_iter)) ;
V_11 = F_57 ( & V_6 -> V_85 , & V_56 -> V_84 , V_11 ) ;
V_31 = V_11 ;
if ( V_31 < 0 )
goto V_75;
if ( V_6 -> V_74 || V_11 < V_6 -> V_11 )
V_11 -= V_11 % V_83 ;
V_31 = - V_71 ;
if ( ! V_11 )
goto free;
F_58 ( & V_6 -> V_60 , V_15 ,
V_6 -> V_85 . V_15 , V_11 ,
V_6 -> V_72 ) ;
V_31 = F_59 (
V_6 -> V_65 ?
F_60 ( & V_6 -> V_60 ) :
F_61 ( & V_6 -> V_60 ) ,
& V_6 -> V_86 ) ;
free:
F_62 ( & V_6 -> V_85 ) ;
if ( V_31 )
goto V_75;
V_64 += V_11 ;
F_12 ( V_2 , V_11 ) ;
F_63 ( & V_56 -> V_84 , V_11 ) ;
}
V_31 = 0 ;
V_75:
F_29 ( V_2 ) ;
F_50 ( V_2 ) ;
return V_64 ? : V_31 ;
}
static unsigned int F_64 ( struct V_87 * V_87 , struct V_54 * V_1 ,
T_3 * V_30 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_88 ;
F_65 ( V_87 , F_26 ( V_2 ) , V_30 ) ;
V_88 = 0 ;
if ( V_6 -> V_11 )
V_88 |= V_43 | V_44 ;
if ( F_4 ( V_2 ) )
V_88 |= V_49 | V_89 | V_90 ;
return V_88 ;
}
static void * F_66 ( const char * V_91 , T_4 type , T_4 V_88 )
{
return F_67 ( V_91 , type , V_88 ) ;
}
static void F_68 ( void * V_7 )
{
F_69 ( V_7 ) ;
}
static int F_70 ( void * V_7 , const T_5 * V_92 , unsigned int V_93 )
{
return F_71 ( V_7 , V_92 , V_93 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_58 * V_59 = F_40 ( & V_6 -> V_60 ) ;
F_20 ( V_2 ) ;
F_73 ( V_2 , V_6 -> V_72 , F_41 ( V_59 ) ) ;
F_19 ( V_2 , V_6 , V_6 -> V_76 ) ;
F_74 ( V_2 ) ;
}
static int F_75 ( void * V_7 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_76 = sizeof( * V_6 ) + F_76 ( V_7 ) ;
V_6 = F_8 ( V_2 , V_76 , V_21 ) ;
if ( ! V_6 )
return - V_22 ;
V_6 -> V_72 = F_8 ( V_2 , F_41 ( V_7 ) ,
V_21 ) ;
if ( ! V_6 -> V_72 ) {
F_19 ( V_2 , V_6 , V_76 ) ;
return - V_22 ;
}
memset ( V_6 -> V_72 , 0 , F_41 ( V_7 ) ) ;
F_77 ( & V_6 -> V_16 ) ;
V_6 -> V_76 = V_76 ;
V_6 -> V_11 = 0 ;
V_6 -> V_74 = 0 ;
V_6 -> V_27 = 0 ;
V_6 -> V_65 = 0 ;
F_78 ( & V_6 -> V_86 ) ;
V_4 -> V_7 = V_6 ;
F_79 ( & V_6 -> V_60 , V_7 ) ;
F_80 ( & V_6 -> V_60 , V_94 ,
V_95 , & V_6 -> V_86 ) ;
V_2 -> V_96 = F_72 ;
return 0 ;
}
static int T_6 F_81 ( void )
{
return F_82 ( & V_97 ) ;
}
static void T_7 F_83 ( void )
{
int V_31 = F_84 ( & V_97 ) ;
F_85 ( V_31 ) ;
}
