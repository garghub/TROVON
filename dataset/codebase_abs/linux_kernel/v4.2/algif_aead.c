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
V_16 -> V_21 = 0 ;
V_6 -> V_11 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
if ( ! F_4 ( V_2 ) )
return;
F_13 () ;
V_25 = F_14 ( V_2 -> V_26 ) ;
if ( F_15 ( V_25 ) )
F_16 ( & V_25 -> V_27 , V_28 |
V_29 |
V_30 ) ;
F_17 ( V_2 , V_31 , V_32 ) ;
F_18 () ;
}
static int F_19 ( struct V_1 * V_2 , unsigned V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
long V_34 ;
F_20 ( V_27 ) ;
int V_35 = - V_36 ;
if ( V_33 & V_37 )
return - V_38 ;
F_21 ( V_39 , & V_2 -> V_40 -> V_33 ) ;
for (; ; ) {
if ( F_22 ( V_41 ) )
break;
F_23 ( F_24 ( V_2 ) , & V_27 , V_42 ) ;
V_34 = V_43 ;
if ( F_25 ( V_2 , & V_34 , ! V_6 -> V_22 ) ) {
V_35 = 0 ;
break;
}
}
F_26 ( F_24 ( V_2 ) , & V_27 ) ;
F_27 ( V_39 , & V_2 -> V_40 -> V_33 ) ;
return V_35 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_24 * V_25 ;
if ( V_6 -> V_22 )
return;
if ( ! V_6 -> V_11 )
return;
F_13 () ;
V_25 = F_14 ( V_2 -> V_26 ) ;
if ( F_15 ( V_25 ) )
F_16 ( & V_25 -> V_27 , V_44 |
V_29 |
V_30 ) ;
F_17 ( V_2 , V_45 , V_46 ) ;
F_18 () ;
}
static int F_29 ( struct V_47 * V_1 , struct V_48 * V_49 , T_1 V_50 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_51 =
F_30 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_15 * V_16 = & V_6 -> V_17 ;
struct V_52 V_53 = {} ;
long V_54 = 0 ;
bool V_55 = 0 ;
bool V_56 = 0 ;
int V_35 = - V_57 ;
if ( V_49 -> V_58 ) {
V_35 = F_31 ( V_49 , & V_53 ) ;
if ( V_35 )
return V_35 ;
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
F_32 ( V_2 ) ;
if ( ! V_6 -> V_22 && V_6 -> V_11 )
goto V_64;
if ( V_56 ) {
V_6 -> V_55 = V_55 ;
if ( V_53 . V_62 )
memcpy ( V_6 -> V_62 , V_53 . V_62 -> V_62 , V_51 ) ;
V_6 -> V_14 = V_53 . V_14 ;
}
while ( V_50 ) {
unsigned long V_65 = V_50 ;
struct V_18 * V_19 = NULL ;
if ( V_6 -> V_23 ) {
V_19 = V_16 -> V_19 + V_16 -> V_21 - 1 ;
V_65 = F_33 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_35 = F_34 ( F_35 ( F_9 ( V_19 ) ) +
V_19 -> V_66 + V_19 -> V_67 ,
V_49 , V_65 ) ;
if ( V_35 )
goto V_64;
V_19 -> V_67 += V_65 ;
V_6 -> V_23 = ( V_19 -> V_66 + V_19 -> V_67 ) &
( V_10 - 1 ) ;
V_6 -> V_11 += V_65 ;
V_54 += V_65 ;
V_50 -= V_65 ;
continue;
}
if ( ! F_4 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_35 = - V_68 ;
goto V_64;
}
V_65 = F_33 (unsigned long, size, aead_sndbuf(sk)) ;
while ( V_65 ) {
int V_69 = 0 ;
if ( V_16 -> V_21 >= V_70 ) {
F_8 ( V_2 ) ;
V_35 = - V_71 ;
goto V_64;
}
V_19 = V_16 -> V_19 + V_16 -> V_21 ;
V_69 = F_33 ( int , V_65 , V_10 ) ;
F_11 ( V_19 , F_36 ( V_72 ) ) ;
V_35 = - V_73 ;
if ( ! F_9 ( V_19 ) )
goto V_64;
V_35 = F_34 ( F_35 ( F_9 ( V_19 ) ) ,
V_49 , V_69 ) ;
if ( V_35 ) {
F_37 ( F_9 ( V_19 ) ) ;
F_11 ( V_19 , NULL ) ;
goto V_64;
}
V_19 -> V_66 = 0 ;
V_19 -> V_67 = V_69 ;
V_65 -= V_69 ;
V_6 -> V_11 += V_69 ;
V_54 += V_69 ;
V_16 -> V_21 ++ ;
V_50 -= V_69 ;
V_6 -> V_23 = V_69 & ( V_10 - 1 ) ;
}
}
V_35 = 0 ;
V_6 -> V_22 = V_49 -> V_74 & V_75 ;
if ( ! V_6 -> V_22 && ! F_5 ( V_6 ) ) {
F_8 ( V_2 ) ;
V_35 = - V_68 ;
}
V_64:
F_28 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_35 ? : V_54 ;
}
static T_2 F_39 ( struct V_47 * V_1 , struct V_76 * V_76 ,
int V_66 , T_1 V_50 , int V_33 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_15 * V_16 = & V_6 -> V_17 ;
int V_35 = - V_57 ;
if ( V_33 & V_77 )
V_33 |= V_75 ;
if ( V_16 -> V_21 >= V_70 )
return - V_71 ;
F_32 ( V_2 ) ;
if ( ! V_6 -> V_22 && V_6 -> V_11 )
goto V_64;
if ( ! V_50 )
goto V_78;
if ( ! F_4 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_35 = - V_68 ;
goto V_64;
}
V_6 -> V_23 = 0 ;
F_40 ( V_76 ) ;
F_41 ( V_16 -> V_19 + V_16 -> V_21 , V_76 , V_50 , V_66 ) ;
V_16 -> V_21 ++ ;
V_6 -> V_11 += V_50 ;
V_35 = 0 ;
V_78:
V_6 -> V_22 = V_33 & V_75 ;
if ( ! V_6 -> V_22 && ! F_5 ( V_6 ) ) {
F_8 ( V_2 ) ;
V_35 = - V_68 ;
}
V_64:
F_28 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_35 ? : V_50 ;
}
static int F_42 ( struct V_47 * V_1 , struct V_48 * V_49 , T_1 V_79 , int V_33 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_12 = F_6 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_15 * V_16 = & V_6 -> V_17 ;
unsigned int V_20 = 0 ;
int V_35 = - V_57 ;
unsigned long V_11 = 0 ;
T_1 V_80 = 0 ;
T_1 V_81 = 0 ;
unsigned int V_82 = 0 ;
if ( V_49 -> V_83 . V_84 > V_85 )
return - V_86 ;
F_32 ( V_2 ) ;
if ( V_6 -> V_22 ) {
V_35 = F_19 ( V_2 , V_33 ) ;
if ( V_35 )
goto V_64;
}
V_11 = V_6 -> V_11 ;
if ( ! F_5 ( V_6 ) )
goto V_64;
V_80 = V_11 ;
V_11 -= V_6 -> V_14 + ( V_6 -> V_55 ? V_12 : 0 ) ;
while ( F_43 ( & V_49 -> V_83 ) ) {
T_1 V_87 = F_33 ( T_1 , F_43 ( & V_49 -> V_83 ) ,
( V_80 - V_81 ) ) ;
V_35 = F_44 ( & V_6 -> V_88 [ V_82 ] , & V_49 -> V_83 ,
V_87 ) ;
if ( V_35 < 0 )
goto V_64;
V_81 += V_35 ;
if ( V_82 )
F_45 ( & V_6 -> V_88 [ V_82 - 1 ] , & V_6 -> V_88 [ V_82 ] ) ;
if ( V_80 <= V_81 )
break;
F_46 ( & V_49 -> V_83 , V_35 ) ;
V_82 ++ ;
}
V_35 = - V_57 ;
if ( V_81 < V_80 )
goto V_64;
F_47 ( V_16 -> V_19 + V_16 -> V_21 - 1 ) ;
F_48 ( & V_6 -> V_13 , V_16 -> V_19 , V_6 -> V_88 [ 0 ] . V_19 ,
V_11 , V_6 -> V_62 ) ;
F_49 ( & V_6 -> V_13 , V_6 -> V_14 ) ;
V_35 = F_50 ( V_6 -> V_55 ?
F_51 ( & V_6 -> V_13 ) :
F_52 ( & V_6 -> V_13 ) ,
& V_6 -> V_89 ) ;
if ( V_35 ) {
if ( V_35 == - V_90 )
F_8 ( V_2 ) ;
goto V_64;
}
F_8 ( V_2 ) ;
V_35 = 0 ;
V_64:
for ( V_20 = 0 ; V_20 < V_82 ; V_20 ++ )
F_53 ( & V_6 -> V_88 [ V_20 ] ) ;
F_12 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_35 ? V_35 : V_80 ;
}
static unsigned int F_54 ( struct V_91 * V_91 , struct V_47 * V_1 ,
T_3 * V_27 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_92 ;
F_55 ( V_91 , F_24 ( V_2 ) , V_27 ) ;
V_92 = 0 ;
if ( ! V_6 -> V_22 )
V_92 |= V_28 | V_29 ;
if ( F_4 ( V_2 ) )
V_92 |= V_44 | V_93 | V_94 ;
return V_92 ;
}
static void * F_56 ( const char * V_95 , T_4 type , T_4 V_92 )
{
return F_57 ( V_95 , type | V_96 ,
V_92 | V_96 ) ;
}
static void F_58 ( void * V_7 )
{
F_59 ( V_7 ) ;
}
static int F_60 ( void * V_7 , unsigned int V_97 )
{
return F_61 ( V_7 , V_97 ) ;
}
static int F_62 ( void * V_7 , const T_5 * V_98 , unsigned int V_99 )
{
return F_63 ( V_7 , V_98 , V_99 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_63 = F_30 (
F_7 ( & V_6 -> V_13 ) ) ;
F_8 ( V_2 ) ;
F_65 ( V_2 , V_6 -> V_62 , V_63 ) ;
F_66 ( V_2 , V_6 , V_6 -> V_65 ) ;
F_67 ( V_2 ) ;
}
static int F_68 ( void * V_7 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_65 = sizeof( * V_6 ) + F_69 ( V_7 ) ;
unsigned int V_63 = F_30 ( V_7 ) ;
V_6 = F_70 ( V_2 , V_65 , V_72 ) ;
if ( ! V_6 )
return - V_73 ;
memset ( V_6 , 0 , V_65 ) ;
V_6 -> V_62 = F_70 ( V_2 , V_63 , V_72 ) ;
if ( ! V_6 -> V_62 ) {
F_66 ( V_2 , V_6 , V_65 ) ;
return - V_73 ;
}
memset ( V_6 -> V_62 , 0 , V_63 ) ;
V_6 -> V_65 = V_65 ;
V_6 -> V_11 = 0 ;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_55 = 0 ;
V_6 -> V_17 . V_21 = 0 ;
V_6 -> V_14 = 0 ;
F_71 ( & V_6 -> V_89 ) ;
F_72 ( V_6 -> V_17 . V_19 , V_70 ) ;
V_4 -> V_7 = V_6 ;
F_73 ( & V_6 -> V_13 , V_7 ) ;
F_74 ( & V_6 -> V_13 , V_100 ,
V_101 , & V_6 -> V_89 ) ;
V_2 -> V_102 = F_64 ;
return 0 ;
}
static int T_6 F_75 ( void )
{
return F_76 ( & V_103 ) ;
}
static void T_7 F_77 ( void )
{
int V_35 = F_78 ( & V_103 ) ;
F_79 ( V_35 ) ;
}
