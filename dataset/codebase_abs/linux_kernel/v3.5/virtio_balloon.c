static T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = F_2 ( V_1 ) ;
F_3 ( V_3 < V_4 ) ;
return V_2 * V_5 ;
}
static struct V_1 * F_4 ( T_1 V_2 )
{
F_5 ( V_2 % V_5 ) ;
return F_6 ( V_2 / V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_8 ( & V_9 -> V_12 ) ;
}
static void F_9 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_13 V_14 ;
unsigned int V_15 ;
F_10 ( & V_14 , V_9 -> V_16 , sizeof( V_9 -> V_16 [ 0 ] ) * V_9 -> V_17 ) ;
if ( F_11 ( V_7 , & V_14 , 1 , 0 , V_9 , V_18 ) < 0 )
F_12 () ;
F_13 ( V_7 ) ;
F_14 ( V_9 -> V_12 , F_15 ( V_7 , & V_15 ) ) ;
}
static void F_16 ( T_1 V_16 [] , struct V_1 * V_1 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_16 [ V_19 ] = F_1 ( V_1 ) + V_19 ;
}
static void F_17 ( struct V_8 * V_9 , T_2 V_20 )
{
V_20 = F_18 ( V_20 , F_19 ( V_9 -> V_16 ) ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
struct V_1 * V_1 = F_20 ( V_21 | V_22 |
V_23 | V_24 ) ;
if ( ! V_1 ) {
if ( F_21 () )
F_22 ( V_25 , & V_9 -> V_10 -> V_26 ,
L_1 ,
V_20 ) ;
F_23 ( 200 ) ;
break;
}
F_16 ( V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_27 += V_5 ;
V_28 -- ;
F_24 ( & V_1 -> V_29 , & V_9 -> V_30 ) ;
}
if ( V_9 -> V_17 == 0 )
return;
F_9 ( V_9 , V_9 -> V_31 ) ;
}
static void F_25 ( const T_1 V_16 [] , unsigned int V_20 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 += V_5 ) {
F_26 ( F_4 ( V_16 [ V_19 ] ) ) ;
V_28 ++ ;
}
}
static void F_27 ( struct V_8 * V_9 , T_2 V_20 )
{
struct V_1 * V_1 ;
V_20 = F_18 ( V_20 , F_19 ( V_9 -> V_16 ) ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
V_1 = F_28 ( & V_9 -> V_30 , struct V_1 , V_29 ) ;
F_29 ( & V_1 -> V_29 ) ;
F_16 ( V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_27 -= V_5 ;
}
F_9 ( V_9 , V_9 -> V_32 ) ;
F_25 ( V_9 -> V_16 , V_9 -> V_17 ) ;
}
static inline void F_30 ( struct V_8 * V_9 , int V_33 ,
T_3 V_34 , T_4 V_35 )
{
F_5 ( V_33 >= V_36 ) ;
V_9 -> V_37 [ V_33 ] . V_34 = V_34 ;
V_9 -> V_37 [ V_33 ] . V_35 = V_35 ;
}
static void F_31 ( struct V_8 * V_9 )
{
unsigned long V_38 [ V_39 ] ;
struct V_40 V_19 ;
int V_33 = 0 ;
F_32 ( V_38 ) ;
F_33 ( & V_19 ) ;
F_30 ( V_9 , V_33 ++ , V_41 ,
F_34 ( V_38 [ V_42 ] ) ) ;
F_30 ( V_9 , V_33 ++ , V_43 ,
F_34 ( V_38 [ V_44 ] ) ) ;
F_30 ( V_9 , V_33 ++ , V_45 , V_38 [ V_46 ] ) ;
F_30 ( V_9 , V_33 ++ , V_47 , V_38 [ V_48 ] ) ;
F_30 ( V_9 , V_33 ++ , V_49 ,
F_34 ( V_19 . V_50 ) ) ;
F_30 ( V_9 , V_33 ++ , V_51 ,
F_34 ( V_19 . V_52 ) ) ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
V_9 -> V_53 = 1 ;
F_8 ( & V_9 -> V_54 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_13 V_14 ;
unsigned int V_15 ;
V_9 -> V_53 = 0 ;
F_31 ( V_9 ) ;
V_7 = V_9 -> V_55 ;
if ( ! F_15 ( V_7 , & V_15 ) )
return;
F_10 ( & V_14 , V_9 -> V_37 , sizeof( V_9 -> V_37 ) ) ;
if ( F_11 ( V_7 , & V_14 , 1 , 0 , V_9 , V_18 ) < 0 )
F_12 () ;
F_13 ( V_7 ) ;
}
static void F_37 ( struct V_56 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_8 ( & V_9 -> V_54 ) ;
}
static inline T_5 F_38 ( struct V_8 * V_9 )
{
T_6 V_57 ;
T_5 V_58 ;
V_9 -> V_10 -> V_59 -> V_60 ( V_9 -> V_10 ,
F_39 ( struct V_61 , V_27 ) ,
& V_57 , sizeof( V_57 ) ) ;
V_58 = F_40 ( V_57 ) ;
return V_58 - V_9 -> V_27 ;
}
static void F_41 ( struct V_8 * V_9 )
{
T_6 V_62 = F_42 ( V_9 -> V_27 ) ;
V_9 -> V_10 -> V_59 -> V_63 ( V_9 -> V_10 ,
F_39 ( struct V_61 , V_62 ) ,
& V_62 , sizeof( V_62 ) ) ;
}
static int F_43 ( void * V_64 )
{
struct V_8 * V_9 = V_64 ;
F_44 () ;
while ( ! F_45 () ) {
T_5 V_65 ;
F_46 () ;
F_47 ( V_9 -> V_54 ,
( V_65 = F_38 ( V_9 ) ) != 0
|| V_9 -> V_53
|| F_45 ()
|| F_48 ( V_66 ) ) ;
if ( V_9 -> V_53 )
F_36 ( V_9 ) ;
if ( V_65 > 0 )
F_17 ( V_9 , V_65 ) ;
else if ( V_65 < 0 )
F_27 ( V_9 , - V_65 ) ;
F_41 ( V_9 ) ;
}
return 0 ;
}
static int F_49 ( struct V_8 * V_9 )
{
struct V_6 * V_67 [ 3 ] ;
T_7 * V_68 [] = { F_7 , F_7 , F_35 } ;
const char * V_69 [] = { L_2 , L_3 , L_4 } ;
int V_70 , V_71 ;
V_71 = F_50 ( V_9 -> V_10 , V_72 ) ? 3 : 2 ;
V_70 = V_9 -> V_10 -> V_59 -> V_73 ( V_9 -> V_10 , V_71 , V_67 , V_68 , V_69 ) ;
if ( V_70 )
return V_70 ;
V_9 -> V_31 = V_67 [ 0 ] ;
V_9 -> V_32 = V_67 [ 1 ] ;
if ( F_50 ( V_9 -> V_10 , V_72 ) ) {
struct V_13 V_14 ;
V_9 -> V_55 = V_67 [ 2 ] ;
F_10 ( & V_14 , V_9 -> V_37 , sizeof V_9 -> V_37 ) ;
if ( F_11 ( V_9 -> V_55 , & V_14 , 1 , 0 , V_9 , V_18 )
< 0 )
F_12 () ;
F_13 ( V_9 -> V_55 ) ;
}
return 0 ;
}
static int F_51 ( struct V_56 * V_10 )
{
struct V_8 * V_9 ;
int V_70 ;
V_10 -> V_11 = V_9 = F_52 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_70 = - V_74 ;
goto V_75;
}
F_53 ( & V_9 -> V_30 ) ;
V_9 -> V_27 = 0 ;
F_54 ( & V_9 -> V_54 ) ;
F_54 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_53 = 0 ;
V_70 = F_49 ( V_9 ) ;
if ( V_70 )
goto V_76;
V_9 -> V_77 = F_55 ( F_43 , V_9 , L_5 ) ;
if ( F_56 ( V_9 -> V_77 ) ) {
V_70 = F_57 ( V_9 -> V_77 ) ;
goto V_78;
}
return 0 ;
V_78:
V_10 -> V_59 -> V_79 ( V_10 ) ;
V_76:
F_58 ( V_9 ) ;
V_75:
return V_70 ;
}
static void F_59 ( struct V_8 * V_9 )
{
while ( V_9 -> V_27 )
F_27 ( V_9 , V_9 -> V_27 ) ;
F_41 ( V_9 ) ;
V_9 -> V_10 -> V_59 -> V_80 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_59 -> V_79 ( V_9 -> V_10 ) ;
}
static void T_8 F_60 ( struct V_56 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_61 ( V_9 -> V_77 ) ;
F_59 ( V_9 ) ;
F_58 ( V_9 ) ;
}
static int F_62 ( struct V_56 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_59 ( V_9 ) ;
return 0 ;
}
static int F_63 ( struct V_56 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_81 ;
V_81 = F_49 ( V_10 -> V_11 ) ;
if ( V_81 )
return V_81 ;
F_17 ( V_9 , F_38 ( V_9 ) ) ;
F_41 ( V_9 ) ;
return 0 ;
}
static int T_9 F_64 ( void )
{
return F_65 ( & V_82 ) ;
}
static void T_10 F_66 ( void )
{
F_67 ( & V_82 ) ;
}
