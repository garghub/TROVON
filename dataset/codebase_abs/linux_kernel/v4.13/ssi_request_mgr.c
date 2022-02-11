void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 )
return;
if ( V_4 -> V_6 != 0 ) {
F_2 ( & V_2 -> V_7 -> V_8 ,
sizeof( V_9 ) , V_4 -> V_10 ,
V_4 -> V_6 ) ;
}
F_3 ( L_1 , ( V_4 -> V_11 -
V_4 -> V_12 ) ) ;
F_3 ( L_2 , V_4 -> V_13 ) ;
#ifdef F_4
F_5 ( V_4 -> V_14 ) ;
F_6 ( V_4 -> V_14 ) ;
#else
F_7 ( & V_4 -> V_15 ) ;
#endif
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
F_8 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_16 = 0 ;
V_4 = F_10 ( sizeof( struct V_3 ) , V_17 ) ;
if ( ! V_4 ) {
V_16 = - V_18 ;
goto V_19;
}
V_2 -> V_5 = V_4 ;
F_11 ( & V_4 -> V_20 ) ;
#ifdef F_4
F_3 ( L_3 ) ;
V_4 -> V_14 = F_12 ( L_4 ) ;
if ( F_13 ( ! V_4 -> V_14 ) ) {
F_14 ( L_5 ) ;
V_16 = - V_18 ;
goto V_19;
}
F_15 ( & V_4 -> V_21 , V_22 ) ;
#else
F_3 ( L_6 ) ;
F_16 ( & V_4 -> V_15 , V_23 , ( unsigned long ) V_2 ) ;
#endif
V_4 -> V_11 = F_17 ( V_2 -> V_24 +
F_18 ( V_25 , V_26 ) ) ;
F_3 ( L_7 , V_4 -> V_11 ) ;
if ( V_4 -> V_11 < V_27 ) {
F_14 ( L_8 ,
V_4 -> V_11 , V_27 ) ;
V_16 = - V_18 ;
goto V_19;
}
V_4 -> V_12 = V_4 -> V_11 ;
V_4 -> V_13 = 0 ;
V_4 -> V_10 = F_19 ( & V_2 -> V_7 -> V_8 ,
sizeof( V_9 ) , & V_4 -> V_6 , V_17 ) ;
if ( ! V_4 -> V_10 ) {
F_14 ( L_9
L_10 , sizeof( V_9 ) ) ;
V_16 = - V_18 ;
goto V_19;
}
F_20 ( & V_4 -> V_28 ) ;
F_21 ( & V_4 -> V_28 , 0 , sizeof( V_9 ) ) ;
F_22 ( & V_4 -> V_28 , V_4 -> V_6 ,
sizeof( V_9 ) , V_29 , 1 ) ;
F_23 ( & V_4 -> V_28 , V_30 ) ;
F_24 ( & V_4 -> V_28 ) ;
return 0 ;
V_19:
F_1 ( V_2 ) ;
return V_16 ;
}
static inline void F_25 (
void T_1 * V_24 ,
struct V_31 V_32 [] , unsigned int V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
F_26 ( V_32 [ V_34 ] . V_35 [ 0 ] , ( volatile void T_1 * ) ( V_24 + F_18 ( V_25 , V_36 ) ) ) ;
F_26 ( V_32 [ V_34 ] . V_35 [ 1 ] , ( volatile void T_1 * ) ( V_24 + F_18 ( V_25 , V_36 ) ) ) ;
F_26 ( V_32 [ V_34 ] . V_35 [ 2 ] , ( volatile void T_1 * ) ( V_24 + F_18 ( V_25 , V_36 ) ) ) ;
F_26 ( V_32 [ V_34 ] . V_35 [ 3 ] , ( volatile void T_1 * ) ( V_24 + F_18 ( V_25 , V_36 ) ) ) ;
F_26 ( V_32 [ V_34 ] . V_35 [ 4 ] , ( volatile void T_1 * ) ( V_24 + F_18 ( V_25 , V_36 ) ) ) ;
F_27 () ;
F_26 ( V_32 [ V_34 ] . V_35 [ 5 ] , ( volatile void T_1 * ) ( V_24 + F_18 ( V_25 , V_36 ) ) ) ;
#ifdef F_28
F_3 ( L_11 , V_34 ,
V_32 [ V_34 ] . V_35 [ 0 ] , V_32 [ V_34 ] . V_35 [ 1 ] , V_32 [ V_34 ] . V_35 [ 2 ] , V_32 [ V_34 ] . V_35 [ 3 ] , V_32 [ V_34 ] . V_35 [ 4 ] , V_32 [ V_34 ] . V_35 [ 5 ] ) ;
#endif
}
}
static void F_29 ( struct V_37 * V_8 , void * V_38 , void T_1 * V_24 )
{
struct V_39 * V_40 = V_38 ;
F_30 ( V_40 ) ;
}
static inline int F_31 (
struct V_3 * V_4 ,
void T_1 * V_24 ,
unsigned int V_41 )
{
unsigned long V_42 ;
if ( F_13 ( ( ( V_4 -> V_43 + 1 ) &
( V_44 - 1 ) ) ==
V_4 -> V_45 ) ) {
F_14 ( L_12 ,
V_4 -> V_43 , V_44 ) ;
return - V_46 ;
}
if ( ( F_32 ( V_4 -> V_47 >= V_41 ) ) )
return 0 ;
for ( V_42 = 0 ; V_42 < V_48 ; V_42 ++ ) {
V_4 -> V_47 =
F_33 (
F_18 ( V_25 ,
V_49 ) ) ;
if ( F_13 ( V_4 -> V_47 <
V_4 -> V_12 ) ) {
V_4 -> V_12 = V_4 -> V_47 ;
}
if ( F_32 ( V_4 -> V_47 >= V_41 ) ) {
return 0 ;
}
F_3 ( L_13 ,
V_4 -> V_47 , V_41 ) ;
}
F_3 ( L_14
L_15 ,
V_4 -> V_43 ,
V_44 ,
V_4 -> V_47 ,
V_41 ) ;
return - V_50 ;
}
int F_34 (
struct V_1 * V_2 , struct V_51 * V_52 ,
struct V_31 * V_53 , unsigned int V_54 , bool V_55 )
{
void T_1 * V_24 = V_2 -> V_24 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_56 ;
unsigned int V_57 = 0 ;
unsigned int V_41 = V_54 ;
struct V_31 V_58 [ V_59 ] ;
int V_16 ;
unsigned int V_60 = ( V_41 +
( ( V_52 -> V_61 == 0 ) ? 0 :
V_59 ) +
( ( V_55 == 0 ) ? 1 : 0 ) ) ;
#if F_35 ( V_62 ) || F_35 ( V_63 )
V_16 = F_36 ( & V_2 -> V_7 -> V_8 ) ;
if ( V_16 != 0 ) {
F_14 ( L_16 , V_16 ) ;
return V_16 ;
}
#endif
do {
F_37 ( & V_4 -> V_20 ) ;
V_16 = F_31 ( V_4 ,
V_24 ,
V_60 ) ;
if ( F_32 ( V_16 == 0 ) )
break;
F_38 ( & V_4 -> V_20 ) ;
if ( V_16 != - V_50 ) {
#if F_35 ( V_62 ) || F_35 ( V_63 )
F_39 ( & V_2 -> V_7 -> V_8 ) ;
#endif
return V_16 ;
}
F_40 ( 1 ) ;
} while ( 1 );
if ( ! V_55 ) {
F_41 ( & V_52 -> V_64 ) ;
V_52 -> V_65 = F_29 ;
V_52 -> V_66 = & ( V_52 -> V_64 ) ;
V_41 ++ ;
}
if ( V_52 -> V_61 > 0 ) {
F_3 ( L_17 ,
V_52 -> V_61 ,
( unsigned long long ) V_52 -> V_67 [ 0 ] ,
( unsigned long long ) V_52 -> V_67 [ 1 ] ,
( unsigned long long ) V_52 -> V_67 [ 2 ] ,
V_52 -> V_68 ) ;
V_16 = F_42 ( V_2 , V_52 -> V_67 , V_52 -> V_61 ,
V_52 -> V_68 , V_58 , & V_57 ) ;
if ( F_13 ( V_16 != 0 ) ) {
F_14 ( L_18 , V_16 ) ;
F_38 ( & V_4 -> V_20 ) ;
#if F_35 ( V_62 ) || F_35 ( V_63 )
F_39 ( & V_2 -> V_7 -> V_8 ) ;
#endif
return V_16 ;
}
V_41 += V_57 ;
}
V_56 = ( ( V_4 -> V_43 - V_4 -> V_45 ) & ( V_44 - 1 ) ) ;
if ( F_13 ( V_56 > V_4 -> V_13 ) )
V_4 -> V_13 = V_56 ;
V_4 -> V_69 [ V_4 -> V_43 ] = * V_52 ;
V_4 -> V_43 = ( V_4 -> V_43 + 1 ) & ( V_44 - 1 ) ;
F_3 ( L_19 , V_4 -> V_43 ) ;
#ifdef F_43
F_44 () ;
#endif
F_25 ( V_24 , V_58 , V_57 ) ;
F_25 ( V_24 , V_53 , V_54 ) ;
F_25 ( V_24 , & V_4 -> V_28 , ( V_55 ? 0 : 1 ) ) ;
if ( F_13 ( V_4 -> V_47 < V_41 ) ) {
F_45 () ;
}
V_4 -> V_47 -= V_41 ;
F_38 ( & V_4 -> V_20 ) ;
if ( ! V_55 ) {
F_46 ( & V_52 -> V_64 ) ;
return 0 ;
} else {
return - V_70 ;
}
}
int F_47 (
struct V_1 * V_2 , struct V_31 * V_53 , unsigned int V_54 )
{
void T_1 * V_24 = V_2 -> V_24 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_41 = V_54 ;
int V_16 = 0 ;
V_16 = F_31 ( V_4 , V_24 , V_41 ) ;
if ( F_13 ( V_16 != 0 ) )
return V_16 ;
F_24 ( & V_53 [ ( V_54 - 1 ) ] ) ;
F_25 ( V_24 , V_53 , V_54 ) ;
V_4 -> V_47 = F_33 (
F_18 ( V_25 ,
V_49 ) ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_5 =
V_2 -> V_5 ;
#ifdef F_4
F_49 ( V_5 -> V_14 , & V_5 -> V_21 , 0 ) ;
#else
F_50 ( & V_5 -> V_15 ) ;
#endif
}
static void V_22 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
F_51 ( V_72 , struct V_1 , V_21 . V_72 ) ;
V_23 ( ( unsigned long ) V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_73 * V_7 = V_2 -> V_7 ;
struct V_3 * V_5 =
V_2 -> V_5 ;
#if F_35 ( V_62 ) || F_35 ( V_63 )
int V_16 = 0 ;
#endif
while ( V_5 -> V_74 ) {
V_5 -> V_74 -- ;
if ( F_13 ( V_5 -> V_43 == V_5 -> V_45 ) ) {
F_14 ( L_20 , V_5 -> V_43 ) ;
F_45 () ;
}
V_52 = & V_5 -> V_69 [ V_5 -> V_45 ] ;
#ifdef F_43
F_44 () ;
#endif
#ifdef F_53
{
V_9 V_75 ;
int V_34 ;
F_54 ( L_21 ) ;
for ( V_34 = 0 ; V_34 < 1000000 ; V_34 ++ )
V_75 = F_17 ( V_2 -> V_24 + F_18 ( V_25 , V_76 ) ) ;
}
#endif
if ( F_32 ( V_52 -> V_65 ) )
V_52 -> V_65 ( & V_7 -> V_8 , V_52 -> V_66 , V_2 -> V_24 ) ;
V_5 -> V_45 = ( V_5 -> V_45 + 1 ) & ( V_44 - 1 ) ;
F_3 ( L_22 , V_5 -> V_45 ) ;
F_3 ( L_23 , V_5 -> V_74 ) ;
#if F_35 ( V_62 ) || F_35 ( V_63 )
V_16 = F_39 ( & V_7 -> V_8 ) ;
if ( V_16 != 0 )
F_14 ( L_24 , V_16 ) ;
#endif
}
}
static inline V_9 F_55 ( void T_1 * V_24 )
{
return F_56 ( V_77 ,
F_33 ( V_78 ) ) ;
}
static void V_23 ( unsigned long V_79 )
{
struct V_1 * V_2 = (struct V_1 * ) V_79 ;
void T_1 * V_24 = V_2 -> V_24 ;
struct V_3 * V_5 =
V_2 -> V_5 ;
V_9 V_80 ;
V_80 = ( V_2 -> V_80 & V_81 ) ;
if ( V_80 & V_81 ) {
F_57 ( F_18 ( V_82 , V_83 ) , V_81 ) ;
V_5 -> V_74 +=
F_55 ( V_24 ) ;
while ( V_5 -> V_74 ) {
do {
F_52 ( V_2 ) ;
V_5 -> V_74 =
F_55 ( V_24 ) ;
} while ( V_5 -> V_74 > 0 );
F_57 ( F_18 ( V_82 , V_83 ) , V_81 ) ;
V_5 -> V_74 +=
F_55 ( V_24 ) ;
}
}
F_57 ( F_18 ( V_82 , V_84 ) ,
F_33 (
F_18 ( V_82 , V_84 ) ) & ~ V_80 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = V_2 -> V_5 ;
F_37 ( & V_5 -> V_20 ) ;
V_5 -> V_85 = false ;
F_38 ( & V_5 -> V_20 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_5 =
V_2 -> V_5 ;
F_37 ( & V_5 -> V_20 ) ;
if ( V_5 -> V_43 !=
V_5 -> V_45 ) {
F_38 ( & V_5 -> V_20 ) ;
return - V_46 ;
}
V_5 -> V_85 = true ;
F_38 ( & V_5 -> V_20 ) ;
return 0 ;
}
bool F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_5 =
V_2 -> V_5 ;
return V_5 -> V_85 ;
}
