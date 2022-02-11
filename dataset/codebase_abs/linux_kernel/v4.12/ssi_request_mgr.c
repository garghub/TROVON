void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_6 != 0 ) {
F_2 ( V_4 -> V_6 ) ;
F_3 ( & V_2 -> V_7 -> V_8 ,
sizeof( V_9 ) , V_4 -> V_10 ,
V_4 -> V_6 ) ;
}
F_4 ( L_1 , ( V_4 -> V_11 -
V_4 -> V_12 ) ) ;
F_4 ( L_2 , V_4 -> V_13 ) ;
#ifdef F_5
F_6 ( V_4 -> V_14 ) ;
F_7 ( V_4 -> V_14 ) ;
#else
F_8 ( & V_4 -> V_15 ) ;
#endif
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
F_9 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_10 ( struct V_1 * V_2 )
{
#ifdef F_11
T_1 V_16 [ 2 ] ;
struct V_17 V_18 = { 0 } ;
#endif
struct V_3 * V_4 ;
int V_19 = 0 ;
V_4 = F_12 ( sizeof( struct V_3 ) , V_20 ) ;
if ( V_4 == NULL ) {
V_19 = - V_21 ;
goto V_22;
}
V_2 -> V_5 = V_4 ;
F_13 ( & V_4 -> V_23 ) ;
#ifdef F_5
F_4 ( L_3 ) ;
V_4 -> V_14 = F_14 ( L_4 ) ;
if ( F_15 ( V_4 -> V_14 == NULL ) ) {
F_16 ( L_5 ) ;
V_19 = - V_21 ;
goto V_22;
}
F_17 ( & V_4 -> V_24 , V_25 ) ;
#else
F_4 ( L_6 ) ;
F_18 ( & V_4 -> V_15 , V_26 , ( unsigned long ) V_2 ) ;
#endif
V_4 -> V_11 = F_19 ( V_2 -> V_27 +
F_20 ( V_28 , V_29 ) ) ;
F_4 ( L_7 , V_4 -> V_11 ) ;
if ( V_4 -> V_11 < V_30 ) {
F_16 ( L_8 ,
V_4 -> V_11 , V_30 ) ;
V_19 = - V_21 ;
goto V_22;
}
V_4 -> V_12 = V_4 -> V_11 ;
V_4 -> V_13 = 0 ;
V_4 -> V_10 = F_21 ( & V_2 -> V_7 -> V_8 ,
sizeof( V_9 ) , & V_4 -> V_6 , V_20 ) ;
if ( ! V_4 -> V_10 ) {
F_16 ( L_9
L_10 , sizeof( V_9 ) ) ;
V_19 = - V_21 ;
goto V_22;
}
F_22 ( V_4 -> V_6 ,
sizeof( V_9 ) ) ;
F_23 ( & V_4 -> V_31 ) ;
F_24 ( & V_4 -> V_31 , 0 , sizeof( V_9 ) ) ;
F_25 ( & V_4 -> V_31 ,
V_4 -> V_6 ,
sizeof( V_9 ) , V_32 , 1 ) ;
F_26 ( & V_4 -> V_31 , V_33 ) ;
F_27 ( & V_4 -> V_31 ) ;
#ifdef F_11
F_28 ( & V_4 -> V_16 ) ;
F_29 ( V_34 , & V_4 -> V_35 ) ;
V_16 [ 0 ] = V_4 -> V_16 ;
V_16 [ 1 ] = V_4 -> V_16 ;
V_19 = F_30 ( V_2 , & V_18 , V_16 , 2 , 0 ) ;
if ( F_15 ( V_19 != 0 ) )
goto V_22;
V_2 -> V_36 = F_19 ( V_2 -> V_27 +
F_20 ( V_28 , V_37 ) ) ;
F_16 ( L_11 , V_2 -> V_36 ) ;
F_31 ( V_34 , & V_4 -> V_35 ) ;
#endif
return 0 ;
V_22:
F_1 ( V_2 ) ;
return V_19 ;
}
static inline void F_32 (
void T_2 * V_27 ,
T_1 V_38 [] , unsigned int V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
F_33 ( V_38 [ V_40 ] . V_41 [ 0 ] , ( volatile void T_2 * ) ( V_27 + F_20 ( V_28 , V_42 ) ) ) ;
F_33 ( V_38 [ V_40 ] . V_41 [ 1 ] , ( volatile void T_2 * ) ( V_27 + F_20 ( V_28 , V_42 ) ) ) ;
F_33 ( V_38 [ V_40 ] . V_41 [ 2 ] , ( volatile void T_2 * ) ( V_27 + F_20 ( V_28 , V_42 ) ) ) ;
F_33 ( V_38 [ V_40 ] . V_41 [ 3 ] , ( volatile void T_2 * ) ( V_27 + F_20 ( V_28 , V_42 ) ) ) ;
F_33 ( V_38 [ V_40 ] . V_41 [ 4 ] , ( volatile void T_2 * ) ( V_27 + F_20 ( V_28 , V_42 ) ) ) ;
F_34 () ;
F_33 ( V_38 [ V_40 ] . V_41 [ 5 ] , ( volatile void T_2 * ) ( V_27 + F_20 ( V_28 , V_42 ) ) ) ;
#ifdef F_35
F_4 ( L_12 , V_40 ,
V_38 [ V_40 ] . V_41 [ 0 ] , V_38 [ V_40 ] . V_41 [ 1 ] , V_38 [ V_40 ] . V_41 [ 2 ] , V_38 [ V_40 ] . V_41 [ 3 ] , V_38 [ V_40 ] . V_41 [ 4 ] , V_38 [ V_40 ] . V_41 [ 5 ] ) ;
#endif
}
}
static void F_36 ( struct V_43 * V_8 , void * V_44 , void T_2 * V_27 )
{
struct V_45 * V_46 = V_44 ;
F_37 ( V_46 ) ;
}
static inline int F_38 (
struct V_3 * V_4 ,
void T_2 * V_27 ,
unsigned int V_47 )
{
unsigned long V_48 ;
if ( F_15 ( ( ( V_4 -> V_49 + 1 ) &
( V_50 - 1 ) ) ==
V_4 -> V_51 ) ) {
F_16 ( L_13 ,
V_4 -> V_49 , V_50 ) ;
return - V_52 ;
}
if ( ( F_39 ( V_4 -> V_53 >= V_47 ) ) ) {
return 0 ;
}
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ ) {
V_4 -> V_53 =
F_40 (
F_20 ( V_28 ,
V_55 ) ) ;
if ( F_15 ( V_4 -> V_53 <
V_4 -> V_12 ) ) {
V_4 -> V_12 = V_4 -> V_53 ;
}
if ( F_39 ( V_4 -> V_53 >= V_47 ) ) {
return 0 ;
}
F_4 ( L_14 ,
V_4 -> V_53 , V_47 ) ;
}
F_4 ( L_15
L_16 ,
V_4 -> V_49 ,
V_50 ,
V_4 -> V_53 ,
V_47 ) ;
return - V_56 ;
}
int F_30 (
struct V_1 * V_2 , struct V_17 * V_57 ,
T_1 * V_58 , unsigned int V_59 , bool V_60 )
{
void T_2 * V_27 = V_2 -> V_27 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_61 ;
unsigned int V_62 = 0 ;
unsigned int V_47 = V_59 ;
T_1 V_63 [ V_64 ] ;
int V_19 ;
unsigned int V_65 = ( V_47 +
( ( V_57 -> V_66 == 0 ) ? 0 :
V_64 ) +
( ( V_60 == 0 ) ? 1 : 0 ) ) ;
V_67 ;
#if F_41 ( V_68 ) || F_41 ( V_69 )
V_19 = F_42 ( & V_2 -> V_7 -> V_8 ) ;
if ( V_19 != 0 ) {
F_16 ( L_17 , V_19 ) ;
return V_19 ;
}
#endif
do {
F_43 ( & V_4 -> V_23 ) ;
V_19 = F_38 ( V_4 ,
V_27 ,
V_65 ) ;
if ( F_39 ( V_19 == 0 ) )
break;
F_44 ( & V_4 -> V_23 ) ;
if ( V_19 != - V_56 ) {
#if F_41 ( V_68 ) || F_41 ( V_69 )
F_45 ( & V_2 -> V_7 -> V_8 ) ;
#endif
return V_19 ;
}
F_46 ( 1 ) ;
} while ( 1 );
if ( ! V_60 ) {
F_47 ( & V_57 -> V_70 ) ;
V_57 -> V_71 = F_36 ;
V_57 -> V_72 = & ( V_57 -> V_70 ) ;
V_47 ++ ;
}
if ( V_57 -> V_66 > 0 ) {
F_4 ( L_18 ,
V_57 -> V_66 ,
( unsigned long long ) V_57 -> V_73 [ 0 ] ,
( unsigned long long ) V_57 -> V_73 [ 1 ] ,
( unsigned long long ) V_57 -> V_73 [ 2 ] ,
V_57 -> V_74 ) ;
V_19 = F_48 ( V_2 , V_57 -> V_73 , V_57 -> V_66 ,
V_57 -> V_74 , V_63 , & V_62 ) ;
if ( F_15 ( V_19 != 0 ) ) {
F_16 ( L_19 , V_19 ) ;
F_44 ( & V_4 -> V_23 ) ;
#if F_41 ( V_68 ) || F_41 ( V_69 )
F_45 ( & V_2 -> V_7 -> V_8 ) ;
#endif
return V_19 ;
}
V_47 += V_62 ;
}
V_61 = ( ( V_4 -> V_49 - V_4 -> V_51 ) & ( V_50 - 1 ) ) ;
if ( F_15 ( V_61 > V_4 -> V_13 ) ) {
V_4 -> V_13 = V_61 ;
}
F_49 ( V_27 , & V_4 -> V_16 ,
& V_4 -> V_35 , & V_57 -> V_75 ) ;
V_4 -> V_76 [ V_4 -> V_49 ] = * V_57 ;
F_50 ( V_4 -> V_76 [ V_4 -> V_49 ] . V_77 ) ;
V_4 -> V_49 = ( V_4 -> V_49 + 1 ) & ( V_50 - 1 ) ;
F_4 ( L_20 , V_4 -> V_49 ) ;
#ifdef F_51
F_52 () ;
#endif
F_53 () ;
F_32 ( V_27 , V_63 , V_62 ) ;
F_32 ( V_27 , V_58 , V_59 ) ;
F_32 ( V_27 , & V_4 -> V_31 , ( V_60 ? 0 : 1 ) ) ;
F_54 ( V_57 -> V_78 , V_79 ) ;
F_55 ( V_27 , & V_4 -> V_16 , V_57 -> V_75 ) ;
if ( F_15 ( V_4 -> V_53 < V_47 ) ) {
F_56 () ;
}
V_4 -> V_53 -= V_47 ;
F_44 ( & V_4 -> V_23 ) ;
if ( ! V_60 ) {
return F_57 ( & V_57 -> V_70 ) ;
} else {
return - V_80 ;
}
}
int F_58 (
struct V_1 * V_2 , T_1 * V_58 , unsigned int V_59 )
{
void T_2 * V_27 = V_2 -> V_27 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_47 = V_59 ;
int V_19 = 0 ;
V_19 = F_38 ( V_4 , V_27 , V_47 ) ;
if ( F_15 ( V_19 != 0 ) ) {
return V_19 ;
}
F_27 ( & V_58 [ V_59 - 1 ] ) ;
F_32 ( V_27 , V_58 , V_59 ) ;
V_4 -> V_53 = F_40 (
F_20 ( V_28 ,
V_55 ) ) ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_5 =
V_2 -> V_5 ;
#ifdef F_5
F_60 ( V_5 -> V_14 , & V_5 -> V_24 , 0 ) ;
#else
F_61 ( & V_5 -> V_15 ) ;
#endif
}
static void V_25 ( struct V_81 * V_82 )
{
struct V_1 * V_2 =
F_62 ( V_82 , struct V_1 , V_24 . V_82 ) ;
V_26 ( ( unsigned long ) V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_17 * V_57 ;
struct V_83 * V_7 = V_2 -> V_7 ;
struct V_3 * V_5 =
V_2 -> V_5 ;
#if F_41 ( V_68 ) || F_41 ( V_69 )
int V_19 = 0 ;
#endif
V_67 ;
while( V_5 -> V_84 ) {
V_5 -> V_84 -- ;
if ( F_15 ( V_5 -> V_49 == V_5 -> V_51 ) ) {
F_16 ( L_21 , V_5 -> V_49 ) ;
F_56 () ;
}
V_57 = & V_5 -> V_76 [ V_5 -> V_51 ] ;
F_64 ( V_57 -> V_77 , V_57 -> V_78 , V_85 ) ;
F_65 ( V_2 -> V_27 , V_57 -> V_78 , V_86 ,
V_2 -> V_36 , & V_5 -> V_35 , V_57 -> V_75 ) ;
#ifdef F_51
F_52 () ;
#endif
#ifdef F_66
{
V_9 V_87 ;
int V_40 ;
F_67 ( L_22 ) ;
for ( V_40 = 0 ; V_40 < 1000000 ; V_40 ++ ) {
V_87 = F_19 ( V_2 -> V_27 + F_20 ( V_28 , V_88 ) ) ;
}
}
#endif
if ( F_39 ( V_57 -> V_71 != NULL ) ) {
F_53 () ;
V_57 -> V_71 ( & V_7 -> V_8 , V_57 -> V_72 , V_2 -> V_27 ) ;
F_54 ( V_89 , V_90 ) ;
}
V_5 -> V_51 = ( V_5 -> V_51 + 1 ) & ( V_50 - 1 ) ;
F_4 ( L_23 , V_5 -> V_51 ) ;
F_4 ( L_24 , V_5 -> V_84 ) ;
#if F_41 ( V_68 ) || F_41 ( V_69 )
V_19 = F_45 ( & V_7 -> V_8 ) ;
if ( V_19 != 0 ) {
F_16 ( L_25 , V_19 ) ;
}
#endif
}
}
static void V_26 ( unsigned long V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_91 ;
void T_2 * V_27 = V_2 -> V_27 ;
struct V_3 * V_5 =
V_2 -> V_5 ;
V_9 V_92 ;
V_67 ;
F_53 () ;
V_92 = ( V_2 -> V_92 & V_93 ) ;
if ( V_92 & V_93 ) {
F_68 ( F_20 ( V_94 , V_95 ) , V_93 ) ;
V_5 -> V_84 += F_69 ( V_28 , V_96 , V_97 ,
F_40 ( V_98 ) ) ;
if ( V_5 -> V_84 ) {
F_64 ( V_2 -> V_99 , V_89 , V_100 ) ;
}
while ( V_5 -> V_84 ) {
do {
F_63 ( V_2 ) ;
V_5 -> V_84 = F_69 ( V_28 , V_96 , V_97 ,
F_40 ( V_98 ) ) ;
} while ( V_5 -> V_84 > 0 );
F_68 ( F_20 ( V_94 , V_95 ) , V_93 ) ;
V_5 -> V_84 += F_69 ( V_28 , V_96 , V_97 ,
F_40 ( V_98 ) ) ;
}
}
F_68 ( F_20 ( V_94 , V_101 ) ,
F_40 (
F_20 ( V_94 , V_101 ) ) & ~ V_92 ) ;
F_54 ( V_89 , V_102 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = V_2 -> V_5 ;
F_43 ( & V_5 -> V_23 ) ;
V_5 -> V_103 = false ;
F_44 ( & V_5 -> V_23 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_5 =
V_2 -> V_5 ;
F_43 ( & V_5 -> V_23 ) ;
if ( V_5 -> V_49 !=
V_5 -> V_51 ) {
F_44 ( & V_5 -> V_23 ) ;
return - V_52 ;
}
V_5 -> V_103 = true ;
F_44 ( & V_5 -> V_23 ) ;
return 0 ;
}
bool F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_5 =
V_2 -> V_5 ;
return V_5 -> V_103 ;
}
