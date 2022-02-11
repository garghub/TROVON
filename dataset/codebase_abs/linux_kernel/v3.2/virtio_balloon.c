static T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = F_2 ( V_1 ) ;
F_3 ( V_3 < V_4 ) ;
return V_2 >> ( V_3 - V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
V_8 = F_5 ( V_6 , & V_9 ) ;
if ( V_8 )
F_6 ( & V_8 -> V_10 ) ;
}
static void F_7 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
struct V_11 V_12 ;
F_8 ( & V_12 , V_8 -> V_13 , sizeof( V_8 -> V_13 [ 0 ] ) * V_8 -> V_14 ) ;
F_9 ( & V_8 -> V_10 ) ;
if ( F_10 ( V_6 , & V_12 , 1 , 0 , V_8 ) < 0 )
F_11 () ;
F_12 ( V_6 ) ;
F_13 ( & V_8 -> V_10 ) ;
}
static void F_14 ( struct V_7 * V_8 , T_2 V_15 )
{
V_15 = F_15 ( V_15 , F_16 ( V_8 -> V_13 ) ) ;
for ( V_8 -> V_14 = 0 ; V_8 -> V_14 < V_15 ; V_8 -> V_14 ++ ) {
struct V_1 * V_1 = F_17 ( V_16 | V_17 |
V_18 | V_19 ) ;
if ( ! V_1 ) {
if ( F_18 () )
F_19 ( V_20 , & V_8 -> V_21 -> V_22 ,
L_1 ,
V_15 ) ;
F_20 ( 200 ) ;
break;
}
V_8 -> V_13 [ V_8 -> V_14 ] = F_1 ( V_1 ) ;
V_23 -- ;
V_8 -> V_24 ++ ;
F_21 ( & V_1 -> V_25 , & V_8 -> V_26 ) ;
}
if ( V_8 -> V_14 == 0 )
return;
F_7 ( V_8 , V_8 -> V_27 ) ;
}
static void F_22 ( const T_1 V_13 [] , unsigned int V_15 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_15 ; V_28 ++ ) {
F_23 ( F_24 ( V_13 [ V_28 ] ) ) ;
V_23 ++ ;
}
}
static void F_25 ( struct V_7 * V_8 , T_2 V_15 )
{
struct V_1 * V_1 ;
V_15 = F_15 ( V_15 , F_16 ( V_8 -> V_13 ) ) ;
for ( V_8 -> V_14 = 0 ; V_8 -> V_14 < V_15 ; V_8 -> V_14 ++ ) {
V_1 = F_26 ( & V_8 -> V_26 , struct V_1 , V_25 ) ;
F_27 ( & V_1 -> V_25 ) ;
V_8 -> V_13 [ V_8 -> V_14 ] = F_1 ( V_1 ) ;
V_8 -> V_24 -- ;
}
F_7 ( V_8 , V_8 -> V_29 ) ;
F_22 ( V_8 -> V_13 , V_8 -> V_14 ) ;
}
static inline void F_28 ( struct V_7 * V_8 , int V_30 ,
T_3 V_31 , T_4 V_32 )
{
F_29 ( V_30 >= V_33 ) ;
V_8 -> V_34 [ V_30 ] . V_31 = V_31 ;
V_8 -> V_34 [ V_30 ] . V_32 = V_32 ;
}
static void F_30 ( struct V_7 * V_8 )
{
unsigned long V_35 [ V_36 ] ;
struct V_37 V_28 ;
int V_30 = 0 ;
F_31 ( V_35 ) ;
F_32 ( & V_28 ) ;
F_28 ( V_8 , V_30 ++ , V_38 ,
F_33 ( V_35 [ V_39 ] ) ) ;
F_28 ( V_8 , V_30 ++ , V_40 ,
F_33 ( V_35 [ V_41 ] ) ) ;
F_28 ( V_8 , V_30 ++ , V_42 , V_35 [ V_43 ] ) ;
F_28 ( V_8 , V_30 ++ , V_44 , V_35 [ V_45 ] ) ;
F_28 ( V_8 , V_30 ++ , V_46 ,
F_33 ( V_28 . V_47 ) ) ;
F_28 ( V_8 , V_30 ++ , V_48 ,
F_33 ( V_28 . V_49 ) ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
V_8 = F_5 ( V_6 , & V_9 ) ;
if ( ! V_8 )
return;
V_8 -> V_50 = 1 ;
F_35 ( & V_8 -> V_51 ) ;
}
static void F_36 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_11 V_12 ;
V_8 -> V_50 = 0 ;
F_30 ( V_8 ) ;
V_6 = V_8 -> V_52 ;
F_8 ( & V_12 , V_8 -> V_34 , sizeof( V_8 -> V_34 ) ) ;
if ( F_10 ( V_6 , & V_12 , 1 , 0 , V_8 ) < 0 )
F_11 () ;
F_12 ( V_6 ) ;
}
static void F_37 ( struct V_53 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_54 ;
F_35 ( & V_8 -> V_51 ) ;
}
static inline T_5 F_38 ( struct V_7 * V_8 )
{
T_1 V_55 ;
V_8 -> V_21 -> V_56 -> V_57 ( V_8 -> V_21 ,
F_39 ( struct V_58 , V_24 ) ,
& V_55 , sizeof( V_55 ) ) ;
return ( T_5 ) V_55 - V_8 -> V_24 ;
}
static void F_40 ( struct V_7 * V_8 )
{
T_6 V_59 = F_41 ( V_8 -> V_24 ) ;
V_8 -> V_21 -> V_56 -> V_60 ( V_8 -> V_21 ,
F_39 ( struct V_58 , V_59 ) ,
& V_59 , sizeof( V_59 ) ) ;
}
static int F_42 ( void * V_61 )
{
struct V_7 * V_8 = V_61 ;
F_43 () ;
while ( ! F_44 () ) {
T_5 V_62 ;
F_45 () ;
F_46 ( V_8 -> V_51 ,
( V_62 = F_38 ( V_8 ) ) != 0
|| V_8 -> V_50
|| F_44 ()
|| F_47 ( V_63 ) ) ;
if ( V_8 -> V_50 )
F_36 ( V_8 ) ;
if ( V_62 > 0 )
F_14 ( V_8 , V_62 ) ;
else if ( V_62 < 0 )
F_25 ( V_8 , - V_62 ) ;
F_40 ( V_8 ) ;
}
return 0 ;
}
static int F_48 ( struct V_53 * V_21 )
{
struct V_7 * V_8 ;
struct V_5 * V_64 [ 3 ] ;
T_7 * V_65 [] = { F_4 , F_4 , F_34 } ;
const char * V_66 [] = { L_2 , L_3 , L_4 } ;
int V_67 , V_68 ;
V_21 -> V_54 = V_8 = F_49 ( sizeof( * V_8 ) , V_69 ) ;
if ( ! V_8 ) {
V_67 = - V_70 ;
goto V_71;
}
F_50 ( & V_8 -> V_26 ) ;
V_8 -> V_24 = 0 ;
F_51 ( & V_8 -> V_51 ) ;
V_8 -> V_21 = V_21 ;
V_8 -> V_50 = 0 ;
V_68 = F_52 ( V_8 -> V_21 , V_72 ) ? 3 : 2 ;
V_67 = V_21 -> V_56 -> V_73 ( V_21 , V_68 , V_64 , V_65 , V_66 ) ;
if ( V_67 )
goto V_74;
V_8 -> V_27 = V_64 [ 0 ] ;
V_8 -> V_29 = V_64 [ 1 ] ;
if ( F_52 ( V_8 -> V_21 , V_72 ) ) {
struct V_11 V_12 ;
V_8 -> V_52 = V_64 [ 2 ] ;
F_8 ( & V_12 , V_8 -> V_34 , sizeof V_8 -> V_34 ) ;
if ( F_10 ( V_8 -> V_52 , & V_12 , 1 , 0 , V_8 ) < 0 )
F_11 () ;
F_12 ( V_8 -> V_52 ) ;
}
V_8 -> V_75 = F_53 ( F_42 , V_8 , L_5 ) ;
if ( F_54 ( V_8 -> V_75 ) ) {
V_67 = F_55 ( V_8 -> V_75 ) ;
goto V_76;
}
return 0 ;
V_76:
V_21 -> V_56 -> V_77 ( V_21 ) ;
V_74:
F_56 ( V_8 ) ;
V_71:
return V_67 ;
}
static void T_8 F_57 ( struct V_53 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_54 ;
F_58 ( V_8 -> V_75 ) ;
while ( V_8 -> V_24 )
F_25 ( V_8 , V_8 -> V_24 ) ;
V_21 -> V_56 -> V_78 ( V_21 ) ;
V_21 -> V_56 -> V_77 ( V_21 ) ;
F_56 ( V_8 ) ;
}
static int T_9 F_59 ( void )
{
return F_60 ( & V_79 ) ;
}
static void T_10 F_61 ( void )
{
F_62 ( & V_79 ) ;
}
