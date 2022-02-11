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
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_15 * V_16 = & V_6 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_19 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_16 -> V_21 ; V_20 ++ ) {
if ( ! F_9 ( V_19 + V_20 ) )
continue;
F_10 ( F_9 ( V_19 + V_20 ) ) ;
F_11 ( V_19 + V_20 , NULL ) ;
}
F_12 ( V_19 , V_22 ) ;
V_16 -> V_21 = 0 ;
V_6 -> V_11 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ! F_4 ( V_2 ) )
return;
F_14 () ;
V_26 = F_15 ( V_2 -> V_27 ) ;
if ( F_16 ( V_26 ) )
F_17 ( & V_26 -> V_28 , V_29 |
V_30 |
V_31 ) ;
F_18 ( V_2 , V_32 , V_33 ) ;
F_19 () ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
long V_35 ;
F_21 ( V_28 ) ;
int V_36 = - V_37 ;
if ( V_34 & V_38 )
return - V_39 ;
F_22 ( V_40 , & V_2 -> V_41 -> V_34 ) ;
for (; ; ) {
if ( F_23 ( V_42 ) )
break;
F_24 ( F_25 ( V_2 ) , & V_28 , V_43 ) ;
V_35 = V_44 ;
if ( F_26 ( V_2 , & V_35 , ! V_6 -> V_23 ) ) {
V_36 = 0 ;
break;
}
}
F_27 ( F_25 ( V_2 ) , & V_28 ) ;
F_28 ( V_40 , & V_2 -> V_41 -> V_34 ) ;
return V_36 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_25 * V_26 ;
if ( V_6 -> V_23 )
return;
if ( ! V_6 -> V_11 )
return;
F_14 () ;
V_26 = F_15 ( V_2 -> V_27 ) ;
if ( F_16 ( V_26 ) )
F_17 ( & V_26 -> V_28 , V_45 |
V_30 |
V_31 ) ;
F_18 ( V_2 , V_46 , V_47 ) ;
F_19 () ;
}
static int F_30 ( struct V_48 * V_1 , struct V_49 * V_50 , T_1 V_51 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_52 =
F_31 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_15 * V_16 = & V_6 -> V_17 ;
struct V_53 V_54 = {} ;
long V_55 = 0 ;
bool V_56 = 0 ;
bool V_57 = 0 ;
int V_36 = - V_58 ;
if ( V_50 -> V_59 ) {
V_36 = F_32 ( V_50 , & V_54 ) ;
if ( V_36 )
return V_36 ;
V_57 = 1 ;
switch ( V_54 . V_60 ) {
case V_61 :
V_56 = 1 ;
break;
case V_62 :
V_56 = 0 ;
break;
default:
return - V_58 ;
}
if ( V_54 . V_63 && V_54 . V_63 -> V_64 != V_52 )
return - V_58 ;
}
F_33 ( V_2 ) ;
if ( ! V_6 -> V_23 && V_6 -> V_11 )
goto V_65;
if ( V_57 ) {
V_6 -> V_56 = V_56 ;
if ( V_54 . V_63 )
memcpy ( V_6 -> V_63 , V_54 . V_63 -> V_63 , V_52 ) ;
V_6 -> V_14 = V_54 . V_14 ;
}
while ( V_51 ) {
unsigned long V_66 = V_51 ;
struct V_18 * V_19 = NULL ;
if ( V_6 -> V_24 ) {
V_19 = V_16 -> V_19 + V_16 -> V_21 - 1 ;
V_66 = F_34 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_36 = F_35 ( F_36 ( F_9 ( V_19 ) ) +
V_19 -> V_67 + V_19 -> V_68 ,
V_50 , V_66 ) ;
if ( V_36 )
goto V_65;
V_19 -> V_68 += V_66 ;
V_6 -> V_24 = ( V_19 -> V_67 + V_19 -> V_68 ) &
( V_10 - 1 ) ;
V_6 -> V_11 += V_66 ;
V_55 += V_66 ;
V_51 -= V_66 ;
continue;
}
if ( ! F_4 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_69 ;
goto V_65;
}
V_66 = F_34 (unsigned long, size, aead_sndbuf(sk)) ;
while ( V_66 ) {
int V_70 = 0 ;
if ( V_16 -> V_21 >= V_22 ) {
F_8 ( V_2 ) ;
V_36 = - V_71 ;
goto V_65;
}
V_19 = V_16 -> V_19 + V_16 -> V_21 ;
V_70 = F_34 ( int , V_66 , V_10 ) ;
F_11 ( V_19 , F_37 ( V_72 ) ) ;
V_36 = - V_73 ;
if ( ! F_9 ( V_19 ) )
goto V_65;
V_36 = F_35 ( F_36 ( F_9 ( V_19 ) ) ,
V_50 , V_70 ) ;
if ( V_36 ) {
F_38 ( F_9 ( V_19 ) ) ;
F_11 ( V_19 , NULL ) ;
goto V_65;
}
V_19 -> V_67 = 0 ;
V_19 -> V_68 = V_70 ;
V_66 -= V_70 ;
V_6 -> V_11 += V_70 ;
V_55 += V_70 ;
V_16 -> V_21 ++ ;
V_51 -= V_70 ;
V_6 -> V_24 = V_70 & ( V_10 - 1 ) ;
}
}
V_36 = 0 ;
V_6 -> V_23 = V_50 -> V_74 & V_75 ;
if ( ! V_6 -> V_23 && ! F_5 ( V_6 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_69 ;
}
V_65:
F_29 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_36 ? : V_55 ;
}
static T_2 F_40 ( struct V_48 * V_1 , struct V_76 * V_76 ,
int V_67 , T_1 V_51 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_15 * V_16 = & V_6 -> V_17 ;
int V_36 = - V_58 ;
if ( V_34 & V_77 )
V_34 |= V_75 ;
if ( V_16 -> V_21 >= V_22 )
return - V_71 ;
F_33 ( V_2 ) ;
if ( ! V_6 -> V_23 && V_6 -> V_11 )
goto V_65;
if ( ! V_51 )
goto V_78;
if ( ! F_4 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_69 ;
goto V_65;
}
V_6 -> V_24 = 0 ;
F_41 ( V_76 ) ;
F_42 ( V_16 -> V_19 + V_16 -> V_21 , V_76 , V_51 , V_67 ) ;
V_16 -> V_21 ++ ;
V_6 -> V_11 += V_51 ;
V_36 = 0 ;
V_78:
V_6 -> V_23 = V_34 & V_75 ;
if ( ! V_6 -> V_23 && ! F_5 ( V_6 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_69 ;
}
V_65:
F_29 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_36 ? : V_51 ;
}
static int F_43 ( struct V_48 * V_1 , struct V_49 * V_50 , T_1 V_79 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_12 = F_6 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_15 * V_16 = & V_6 -> V_17 ;
unsigned int V_20 = 0 ;
int V_36 = - V_58 ;
unsigned long V_11 = 0 ;
T_1 V_80 = 0 ;
T_1 V_81 = 0 ;
unsigned int V_82 = 0 ;
if ( V_50 -> V_83 . V_84 > V_85 )
return - V_86 ;
F_33 ( V_2 ) ;
if ( V_6 -> V_23 ) {
V_36 = F_20 ( V_2 , V_34 ) ;
if ( V_36 )
goto V_65;
}
V_11 = V_6 -> V_11 ;
if ( ! F_5 ( V_6 ) )
goto V_65;
V_80 = V_11 ;
V_11 -= V_6 -> V_14 + ( V_6 -> V_56 ? V_12 : 0 ) ;
while ( F_44 ( & V_50 -> V_83 ) ) {
T_1 V_87 = F_34 ( T_1 , F_44 ( & V_50 -> V_83 ) ,
( V_80 - V_81 ) ) ;
V_36 = F_45 ( & V_6 -> V_88 [ V_82 ] , & V_50 -> V_83 ,
V_87 ) ;
if ( V_36 < 0 )
goto V_65;
V_81 += V_36 ;
if ( V_82 )
F_46 ( & V_6 -> V_88 [ V_82 - 1 ] , & V_6 -> V_88 [ V_82 ] ) ;
if ( V_80 <= V_81 )
break;
F_47 ( & V_50 -> V_83 , V_36 ) ;
V_82 ++ ;
}
V_36 = - V_58 ;
if ( V_81 < V_80 )
goto V_65;
F_48 ( V_16 -> V_19 + V_16 -> V_21 - 1 ) ;
F_49 ( & V_6 -> V_13 , V_16 -> V_19 , V_6 -> V_88 [ 0 ] . V_19 ,
V_11 , V_6 -> V_63 ) ;
F_50 ( & V_6 -> V_13 , V_6 -> V_14 ) ;
V_36 = F_51 ( V_6 -> V_56 ?
F_52 ( & V_6 -> V_13 ) :
F_53 ( & V_6 -> V_13 ) ,
& V_6 -> V_89 ) ;
if ( V_36 ) {
if ( V_36 == - V_90 )
F_8 ( V_2 ) ;
goto V_65;
}
F_8 ( V_2 ) ;
V_36 = 0 ;
V_65:
for ( V_20 = 0 ; V_20 < V_82 ; V_20 ++ )
F_54 ( & V_6 -> V_88 [ V_20 ] ) ;
F_13 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_36 ? V_36 : V_80 ;
}
static unsigned int F_55 ( struct V_91 * V_91 , struct V_48 * V_1 ,
T_3 * V_28 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_92 ;
F_56 ( V_91 , F_25 ( V_2 ) , V_28 ) ;
V_92 = 0 ;
if ( ! V_6 -> V_23 )
V_92 |= V_29 | V_30 ;
if ( F_4 ( V_2 ) )
V_92 |= V_45 | V_93 | V_94 ;
return V_92 ;
}
static void * F_57 ( const char * V_95 , T_4 type , T_4 V_92 )
{
return F_58 ( V_95 , type , V_92 ) ;
}
static void F_59 ( void * V_7 )
{
F_60 ( V_7 ) ;
}
static int F_61 ( void * V_7 , unsigned int V_96 )
{
return F_62 ( V_7 , V_96 ) ;
}
static int F_63 ( void * V_7 , const T_5 * V_97 , unsigned int V_98 )
{
return F_64 ( V_7 , V_97 , V_98 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_64 = F_31 (
F_7 ( & V_6 -> V_13 ) ) ;
F_8 ( V_2 ) ;
F_66 ( V_2 , V_6 -> V_63 , V_64 ) ;
F_67 ( V_2 , V_6 , V_6 -> V_66 ) ;
F_68 ( V_2 ) ;
}
static int F_69 ( void * V_7 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_66 = sizeof( * V_6 ) + F_70 ( V_7 ) ;
unsigned int V_64 = F_31 ( V_7 ) ;
V_6 = F_71 ( V_2 , V_66 , V_72 ) ;
if ( ! V_6 )
return - V_73 ;
memset ( V_6 , 0 , V_66 ) ;
V_6 -> V_63 = F_71 ( V_2 , V_64 , V_72 ) ;
if ( ! V_6 -> V_63 ) {
F_67 ( V_2 , V_6 , V_66 ) ;
return - V_73 ;
}
memset ( V_6 -> V_63 , 0 , V_64 ) ;
V_6 -> V_66 = V_66 ;
V_6 -> V_11 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_56 = 0 ;
V_6 -> V_17 . V_21 = 0 ;
V_6 -> V_14 = 0 ;
F_72 ( & V_6 -> V_89 ) ;
F_12 ( V_6 -> V_17 . V_19 , V_22 ) ;
V_4 -> V_7 = V_6 ;
F_73 ( & V_6 -> V_13 , V_7 ) ;
F_74 ( & V_6 -> V_13 , V_99 ,
V_100 , & V_6 -> V_89 ) ;
V_2 -> V_101 = F_65 ;
return 0 ;
}
static int T_6 F_75 ( void )
{
return F_76 ( & V_102 ) ;
}
static void T_7 F_77 ( void )
{
int V_36 = F_78 ( & V_102 ) ;
F_79 ( V_36 ) ;
}
