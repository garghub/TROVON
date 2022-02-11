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
return ( V_6 -> V_11 >= ( V_6 -> V_14 + ( V_6 -> V_15 ? 0 : V_12 ) ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_16 * V_17 = & V_6 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_17 -> V_22 ; V_21 ++ ) {
if ( ! F_9 ( V_20 + V_21 ) )
continue;
F_10 ( F_9 ( V_20 + V_21 ) ) ;
F_11 ( V_20 + V_21 , NULL ) ;
}
V_17 -> V_22 = 0 ;
V_6 -> V_11 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ! F_4 ( V_2 ) )
return;
F_13 () ;
V_26 = F_14 ( V_2 -> V_27 ) ;
if ( F_15 ( V_26 ) )
F_16 ( & V_26 -> V_28 , V_29 |
V_30 |
V_31 ) ;
F_17 ( V_2 , V_32 , V_33 ) ;
F_18 () ;
}
static int F_19 ( struct V_1 * V_2 , unsigned V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
long V_35 ;
F_20 ( V_28 ) ;
int V_36 = - V_37 ;
if ( V_34 & V_38 )
return - V_39 ;
F_21 ( V_40 , & V_2 -> V_41 -> V_34 ) ;
for (; ; ) {
if ( F_22 ( V_42 ) )
break;
F_23 ( F_24 ( V_2 ) , & V_28 , V_43 ) ;
V_35 = V_44 ;
if ( F_25 ( V_2 , & V_35 , ! V_6 -> V_23 ) ) {
V_36 = 0 ;
break;
}
}
F_26 ( F_24 ( V_2 ) , & V_28 ) ;
F_27 ( V_40 , & V_2 -> V_41 -> V_34 ) ;
return V_36 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_25 * V_26 ;
if ( V_6 -> V_23 )
return;
if ( ! V_6 -> V_11 )
return;
F_13 () ;
V_26 = F_14 ( V_2 -> V_27 ) ;
if ( F_15 ( V_26 ) )
F_16 ( & V_26 -> V_28 , V_45 |
V_30 |
V_31 ) ;
F_17 ( V_2 , V_46 , V_47 ) ;
F_18 () ;
}
static int F_29 ( struct V_48 * V_1 , struct V_49 * V_50 , T_1 V_51 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_52 =
F_30 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_16 * V_17 = & V_6 -> V_18 ;
struct V_53 V_54 = {} ;
long V_55 = 0 ;
bool V_15 = 0 ;
bool V_56 = 0 ;
int V_36 = - V_57 ;
if ( V_50 -> V_58 ) {
V_36 = F_31 ( V_50 , & V_54 ) ;
if ( V_36 )
return V_36 ;
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
F_32 ( V_2 ) ;
if ( ! V_6 -> V_23 && V_6 -> V_11 )
goto V_64;
if ( V_56 ) {
V_6 -> V_15 = V_15 ;
if ( V_54 . V_62 )
memcpy ( V_6 -> V_62 , V_54 . V_62 -> V_62 , V_52 ) ;
V_6 -> V_14 = V_54 . V_14 ;
}
while ( V_51 ) {
unsigned long V_65 = V_51 ;
struct V_19 * V_20 = NULL ;
if ( V_6 -> V_24 ) {
V_20 = V_17 -> V_20 + V_17 -> V_22 - 1 ;
V_65 = F_33 (unsigned long, len,
PAGE_SIZE - sg->offset - sg->length) ;
V_36 = F_34 ( F_35 ( F_9 ( V_20 ) ) +
V_20 -> V_66 + V_20 -> V_67 ,
V_50 , V_65 ) ;
if ( V_36 )
goto V_64;
V_20 -> V_67 += V_65 ;
V_6 -> V_24 = ( V_20 -> V_66 + V_20 -> V_67 ) &
( V_10 - 1 ) ;
V_6 -> V_11 += V_65 ;
V_55 += V_65 ;
V_51 -= V_65 ;
continue;
}
if ( ! F_4 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_68 ;
goto V_64;
}
V_65 = F_33 (unsigned long, size, aead_sndbuf(sk)) ;
while ( V_65 ) {
int V_69 = 0 ;
if ( V_17 -> V_22 >= V_70 ) {
F_8 ( V_2 ) ;
V_36 = - V_71 ;
goto V_64;
}
V_20 = V_17 -> V_20 + V_17 -> V_22 ;
V_69 = F_33 ( int , V_65 , V_10 ) ;
F_11 ( V_20 , F_36 ( V_72 ) ) ;
V_36 = - V_73 ;
if ( ! F_9 ( V_20 ) )
goto V_64;
V_36 = F_34 ( F_35 ( F_9 ( V_20 ) ) ,
V_50 , V_69 ) ;
if ( V_36 ) {
F_37 ( F_9 ( V_20 ) ) ;
F_11 ( V_20 , NULL ) ;
goto V_64;
}
V_20 -> V_66 = 0 ;
V_20 -> V_67 = V_69 ;
V_65 -= V_69 ;
V_6 -> V_11 += V_69 ;
V_55 += V_69 ;
V_17 -> V_22 ++ ;
V_51 -= V_69 ;
V_6 -> V_24 = V_69 & ( V_10 - 1 ) ;
}
}
V_36 = 0 ;
V_6 -> V_23 = V_50 -> V_74 & V_75 ;
if ( ! V_6 -> V_23 && ! F_5 ( V_6 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_68 ;
}
V_64:
F_28 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_36 ? : V_55 ;
}
static T_2 F_39 ( struct V_48 * V_1 , struct V_76 * V_76 ,
int V_66 , T_1 V_51 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_16 * V_17 = & V_6 -> V_18 ;
int V_36 = - V_57 ;
if ( V_34 & V_77 )
V_34 |= V_75 ;
if ( V_17 -> V_22 >= V_70 )
return - V_71 ;
F_32 ( V_2 ) ;
if ( ! V_6 -> V_23 && V_6 -> V_11 )
goto V_64;
if ( ! V_51 )
goto V_78;
if ( ! F_4 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_68 ;
goto V_64;
}
V_6 -> V_24 = 0 ;
F_40 ( V_76 ) ;
F_41 ( V_17 -> V_20 + V_17 -> V_22 , V_76 , V_51 , V_66 ) ;
V_17 -> V_22 ++ ;
V_6 -> V_11 += V_51 ;
V_36 = 0 ;
V_78:
V_6 -> V_23 = V_34 & V_75 ;
if ( ! V_6 -> V_23 && ! F_5 ( V_6 ) ) {
F_8 ( V_2 ) ;
V_36 = - V_68 ;
}
V_64:
F_28 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_36 ? : V_51 ;
}
static int F_42 ( struct V_48 * V_1 , struct V_49 * V_50 , T_1 V_79 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_80 = F_43 ( F_7 ( & V_6 -> V_13 ) ) ;
unsigned V_12 = F_6 ( F_7 ( & V_6 -> V_13 ) ) ;
struct V_16 * V_17 = & V_6 -> V_18 ;
struct V_19 * V_20 = NULL ;
struct V_19 V_81 [ V_70 ] ;
T_1 V_82 = 0 ;
unsigned int V_21 = 0 ;
int V_36 = - V_57 ;
unsigned long V_11 = 0 ;
T_1 V_83 = 0 ;
T_1 V_84 = 0 ;
unsigned int V_85 = 0 ;
if ( V_50 -> V_86 . V_87 > V_88 )
return - V_89 ;
F_32 ( V_2 ) ;
if ( V_6 -> V_23 ) {
V_36 = F_19 ( V_2 , V_34 ) ;
if ( V_36 )
goto V_64;
}
V_11 = V_6 -> V_11 ;
if ( ! F_5 ( V_6 ) )
goto V_64;
V_11 -= V_6 -> V_14 ;
if ( V_6 -> V_15 ) {
V_83 = ( ( V_11 + V_80 - 1 ) / V_80 * V_80 ) ;
V_83 += V_12 ;
} else {
V_83 = V_11 - V_12 ;
V_83 = ( ( V_83 + V_80 - 1 ) / V_80 * V_80 ) ;
}
while ( F_44 ( & V_50 -> V_86 ) ) {
T_1 V_90 = F_33 ( T_1 , F_44 ( & V_50 -> V_86 ) ,
( V_83 - V_84 ) ) ;
V_36 = F_45 ( & V_6 -> V_91 [ V_85 ] , & V_50 -> V_86 ,
V_90 ) ;
if ( V_36 < 0 )
goto V_64;
V_84 += V_36 ;
if ( V_85 )
F_46 ( & V_6 -> V_91 [ V_85 - 1 ] , & V_6 -> V_91 [ V_85 ] ) ;
if ( V_83 <= V_84 )
break;
F_47 ( & V_50 -> V_86 , V_36 ) ;
V_85 ++ ;
}
V_36 = - V_57 ;
if ( V_84 < V_83 )
goto V_64;
F_48 ( V_81 , V_70 ) ;
V_82 = V_6 -> V_14 ;
for ( V_21 = 0 ; V_21 < V_6 -> V_18 . V_22 ; V_21 ++ ) {
V_20 = V_17 -> V_20 + V_21 ;
if ( V_20 -> V_67 <= V_82 ) {
F_41 ( V_81 + V_21 , F_9 ( V_20 ) ,
V_20 -> V_67 , V_20 -> V_66 ) ;
V_82 -= V_20 -> V_67 ;
if ( V_21 >= V_6 -> V_18 . V_22 )
goto V_64;
} else if ( ! V_82 ) {
if ( V_21 )
F_49 ( V_81 + V_21 - 1 ) ;
else
F_49 ( V_81 ) ;
break;
} else {
F_41 ( V_81 + V_21 , F_9 ( V_20 ) ,
V_82 , V_20 -> V_66 ) ;
F_49 ( V_81 + V_21 ) ;
V_20 -> V_67 -= V_82 ;
V_20 -> V_66 += V_82 ;
break;
}
}
F_50 ( & V_6 -> V_13 , V_81 , V_6 -> V_14 ) ;
F_51 ( & V_6 -> V_13 , V_20 , V_6 -> V_91 [ 0 ] . V_20 , V_11 ,
V_6 -> V_62 ) ;
V_36 = F_52 ( V_6 -> V_15 ?
F_53 ( & V_6 -> V_13 ) :
F_54 ( & V_6 -> V_13 ) ,
& V_6 -> V_92 ) ;
if ( V_36 ) {
if ( V_36 == - V_93 )
F_8 ( V_2 ) ;
goto V_64;
}
F_8 ( V_2 ) ;
V_36 = 0 ;
V_64:
for ( V_21 = 0 ; V_21 < V_85 ; V_21 ++ )
F_55 ( & V_6 -> V_91 [ V_21 ] ) ;
F_12 ( V_2 ) ;
F_38 ( V_2 ) ;
return V_36 ? V_36 : V_83 ;
}
static unsigned int F_56 ( struct V_94 * V_94 , struct V_48 * V_1 ,
T_3 * V_28 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_95 ;
F_57 ( V_94 , F_24 ( V_2 ) , V_28 ) ;
V_95 = 0 ;
if ( ! V_6 -> V_23 )
V_95 |= V_29 | V_30 ;
if ( F_4 ( V_2 ) )
V_95 |= V_45 | V_96 | V_97 ;
return V_95 ;
}
static void * F_58 ( const char * V_98 , T_4 type , T_4 V_95 )
{
return F_59 ( V_98 , type , V_95 ) ;
}
static void F_60 ( void * V_7 )
{
F_61 ( V_7 ) ;
}
static int F_62 ( void * V_7 , unsigned int V_99 )
{
return F_63 ( V_7 , V_99 ) ;
}
static int F_64 ( void * V_7 , const T_5 * V_100 , unsigned int V_101 )
{
return F_65 ( V_7 , V_100 , V_101 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_63 = F_30 (
F_7 ( & V_6 -> V_13 ) ) ;
F_8 ( V_2 ) ;
F_67 ( V_2 , V_6 -> V_62 , V_63 ) ;
F_68 ( V_2 , V_6 , V_6 -> V_65 ) ;
F_69 ( V_2 ) ;
}
static int F_70 ( void * V_7 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_65 = sizeof( * V_6 ) + F_71 ( V_7 ) ;
unsigned int V_63 = F_30 ( V_7 ) ;
V_6 = F_72 ( V_2 , V_65 , V_72 ) ;
if ( ! V_6 )
return - V_73 ;
memset ( V_6 , 0 , V_65 ) ;
V_6 -> V_62 = F_72 ( V_2 , V_63 , V_72 ) ;
if ( ! V_6 -> V_62 ) {
F_68 ( V_2 , V_6 , V_65 ) ;
return - V_73 ;
}
memset ( V_6 -> V_62 , 0 , V_63 ) ;
V_6 -> V_65 = V_65 ;
V_6 -> V_11 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_15 = 0 ;
V_6 -> V_18 . V_22 = 0 ;
V_6 -> V_14 = 0 ;
F_73 ( & V_6 -> V_92 ) ;
F_48 ( V_6 -> V_18 . V_20 , V_70 ) ;
V_4 -> V_7 = V_6 ;
F_74 ( & V_6 -> V_13 , V_7 ) ;
F_75 ( & V_6 -> V_13 , V_102 ,
V_103 , & V_6 -> V_92 ) ;
V_2 -> V_104 = F_66 ;
return 0 ;
}
static int T_6 F_76 ( void )
{
return F_77 ( & V_105 ) ;
}
static void T_7 F_78 ( void )
{
int V_36 = F_79 ( & V_105 ) ;
F_80 ( V_36 ) ;
}
