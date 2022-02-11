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
if ( F_10 ( V_6 , & V_12 , 1 , 0 , V_8 , V_15 ) < 0 )
F_11 () ;
F_12 ( V_6 ) ;
F_13 ( & V_8 -> V_10 ) ;
}
static void F_14 ( struct V_7 * V_8 , T_2 V_16 )
{
V_16 = F_15 ( V_16 , F_16 ( V_8 -> V_13 ) ) ;
for ( V_8 -> V_14 = 0 ; V_8 -> V_14 < V_16 ; V_8 -> V_14 ++ ) {
struct V_1 * V_1 = F_17 ( V_17 | V_18 |
V_19 | V_20 ) ;
if ( ! V_1 ) {
if ( F_18 () )
F_19 ( V_21 , & V_8 -> V_22 -> V_23 ,
L_1 ,
V_16 ) ;
F_20 ( 200 ) ;
break;
}
V_8 -> V_13 [ V_8 -> V_14 ] = F_1 ( V_1 ) ;
V_24 -- ;
V_8 -> V_25 ++ ;
F_21 ( & V_1 -> V_26 , & V_8 -> V_27 ) ;
}
if ( V_8 -> V_14 == 0 )
return;
F_7 ( V_8 , V_8 -> V_28 ) ;
}
static void F_22 ( const T_1 V_13 [] , unsigned int V_16 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_16 ; V_29 ++ ) {
F_23 ( F_24 ( V_13 [ V_29 ] ) ) ;
V_24 ++ ;
}
}
static void F_25 ( struct V_7 * V_8 , T_2 V_16 )
{
struct V_1 * V_1 ;
V_16 = F_15 ( V_16 , F_16 ( V_8 -> V_13 ) ) ;
for ( V_8 -> V_14 = 0 ; V_8 -> V_14 < V_16 ; V_8 -> V_14 ++ ) {
V_1 = F_26 ( & V_8 -> V_27 , struct V_1 , V_26 ) ;
F_27 ( & V_1 -> V_26 ) ;
V_8 -> V_13 [ V_8 -> V_14 ] = F_1 ( V_1 ) ;
V_8 -> V_25 -- ;
}
F_7 ( V_8 , V_8 -> V_30 ) ;
F_22 ( V_8 -> V_13 , V_8 -> V_14 ) ;
}
static inline void F_28 ( struct V_7 * V_8 , int V_31 ,
T_3 V_32 , T_4 V_33 )
{
F_29 ( V_31 >= V_34 ) ;
V_8 -> V_35 [ V_31 ] . V_32 = V_32 ;
V_8 -> V_35 [ V_31 ] . V_33 = V_33 ;
}
static void F_30 ( struct V_7 * V_8 )
{
unsigned long V_36 [ V_37 ] ;
struct V_38 V_29 ;
int V_31 = 0 ;
F_31 ( V_36 ) ;
F_32 ( & V_29 ) ;
F_28 ( V_8 , V_31 ++ , V_39 ,
F_33 ( V_36 [ V_40 ] ) ) ;
F_28 ( V_8 , V_31 ++ , V_41 ,
F_33 ( V_36 [ V_42 ] ) ) ;
F_28 ( V_8 , V_31 ++ , V_43 , V_36 [ V_44 ] ) ;
F_28 ( V_8 , V_31 ++ , V_45 , V_36 [ V_46 ] ) ;
F_28 ( V_8 , V_31 ++ , V_47 ,
F_33 ( V_29 . V_48 ) ) ;
F_28 ( V_8 , V_31 ++ , V_49 ,
F_33 ( V_29 . V_50 ) ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
V_8 = F_5 ( V_6 , & V_9 ) ;
if ( ! V_8 )
return;
V_8 -> V_51 = 1 ;
F_35 ( & V_8 -> V_52 ) ;
}
static void F_36 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_11 V_12 ;
V_8 -> V_51 = 0 ;
F_30 ( V_8 ) ;
V_6 = V_8 -> V_53 ;
F_8 ( & V_12 , V_8 -> V_35 , sizeof( V_8 -> V_35 ) ) ;
if ( F_10 ( V_6 , & V_12 , 1 , 0 , V_8 , V_15 ) < 0 )
F_11 () ;
F_12 ( V_6 ) ;
}
static void F_37 ( struct V_54 * V_22 )
{
struct V_7 * V_8 = V_22 -> V_55 ;
F_35 ( & V_8 -> V_52 ) ;
}
static inline T_5 F_38 ( struct V_7 * V_8 )
{
T_1 V_56 ;
V_8 -> V_22 -> V_57 -> V_58 ( V_8 -> V_22 ,
F_39 ( struct V_59 , V_25 ) ,
& V_56 , sizeof( V_56 ) ) ;
return ( T_5 ) V_56 - V_8 -> V_25 ;
}
static void F_40 ( struct V_7 * V_8 )
{
T_6 V_60 = F_41 ( V_8 -> V_25 ) ;
V_8 -> V_22 -> V_57 -> V_61 ( V_8 -> V_22 ,
F_39 ( struct V_59 , V_60 ) ,
& V_60 , sizeof( V_60 ) ) ;
}
static int F_42 ( void * V_62 )
{
struct V_7 * V_8 = V_62 ;
F_43 () ;
while ( ! F_44 () ) {
T_5 V_63 ;
F_45 () ;
F_46 ( V_8 -> V_52 ,
( V_63 = F_38 ( V_8 ) ) != 0
|| V_8 -> V_51
|| F_44 ()
|| F_47 ( V_64 ) ) ;
if ( V_8 -> V_51 )
F_36 ( V_8 ) ;
if ( V_63 > 0 )
F_14 ( V_8 , V_63 ) ;
else if ( V_63 < 0 )
F_25 ( V_8 , - V_63 ) ;
F_40 ( V_8 ) ;
}
return 0 ;
}
static int F_48 ( struct V_7 * V_8 )
{
struct V_5 * V_65 [ 3 ] ;
T_7 * V_66 [] = { F_4 , F_4 , F_34 } ;
const char * V_67 [] = { L_2 , L_3 , L_4 } ;
int V_68 , V_69 ;
V_69 = F_49 ( V_8 -> V_22 , V_70 ) ? 3 : 2 ;
V_68 = V_8 -> V_22 -> V_57 -> V_71 ( V_8 -> V_22 , V_69 , V_65 , V_66 , V_67 ) ;
if ( V_68 )
return V_68 ;
V_8 -> V_28 = V_65 [ 0 ] ;
V_8 -> V_30 = V_65 [ 1 ] ;
if ( F_49 ( V_8 -> V_22 , V_70 ) ) {
struct V_11 V_12 ;
V_8 -> V_53 = V_65 [ 2 ] ;
F_8 ( & V_12 , V_8 -> V_35 , sizeof V_8 -> V_35 ) ;
if ( F_10 ( V_8 -> V_53 , & V_12 , 1 , 0 , V_8 , V_15 )
< 0 )
F_11 () ;
F_12 ( V_8 -> V_53 ) ;
}
return 0 ;
}
static int F_50 ( struct V_54 * V_22 )
{
struct V_7 * V_8 ;
int V_68 ;
V_22 -> V_55 = V_8 = F_51 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 ) {
V_68 = - V_72 ;
goto V_73;
}
F_52 ( & V_8 -> V_27 ) ;
V_8 -> V_25 = 0 ;
F_53 ( & V_8 -> V_52 ) ;
V_8 -> V_22 = V_22 ;
V_8 -> V_51 = 0 ;
V_68 = F_48 ( V_8 ) ;
if ( V_68 )
goto V_74;
V_8 -> V_75 = F_54 ( F_42 , V_8 , L_5 ) ;
if ( F_55 ( V_8 -> V_75 ) ) {
V_68 = F_56 ( V_8 -> V_75 ) ;
goto V_76;
}
return 0 ;
V_76:
V_22 -> V_57 -> V_77 ( V_22 ) ;
V_74:
F_57 ( V_8 ) ;
V_73:
return V_68 ;
}
static void T_8 F_58 ( struct V_54 * V_22 )
{
struct V_7 * V_8 = V_22 -> V_55 ;
F_59 ( V_8 -> V_75 ) ;
while ( V_8 -> V_25 )
F_25 ( V_8 , V_8 -> V_25 ) ;
V_22 -> V_57 -> V_78 ( V_22 ) ;
V_22 -> V_57 -> V_77 ( V_22 ) ;
F_57 ( V_8 ) ;
}
static int F_60 ( struct V_54 * V_22 )
{
struct V_7 * V_8 = V_22 -> V_55 ;
while ( V_8 -> V_25 )
F_25 ( V_8 , V_8 -> V_25 ) ;
F_40 ( V_8 ) ;
V_22 -> V_57 -> V_78 ( V_22 ) ;
V_22 -> V_57 -> V_77 ( V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_54 * V_22 )
{
struct V_7 * V_8 = V_22 -> V_55 ;
int V_79 ;
V_79 = F_48 ( V_22 -> V_55 ) ;
if ( V_79 )
return V_79 ;
F_14 ( V_8 , F_38 ( V_8 ) ) ;
F_40 ( V_8 ) ;
return 0 ;
}
static int F_62 ( struct V_54 * V_22 )
{
return F_61 ( V_22 ) ;
}
static int F_63 ( struct V_54 * V_22 )
{
struct V_7 * V_8 = V_22 -> V_55 ;
V_8 -> V_51 = 0 ;
return F_61 ( V_22 ) ;
}
static int T_9 F_64 ( void )
{
return F_65 ( & V_80 ) ;
}
static void T_10 F_66 ( void )
{
F_67 ( & V_80 ) ;
}
