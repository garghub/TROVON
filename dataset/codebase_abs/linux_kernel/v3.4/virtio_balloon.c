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
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = F_8 ( V_7 , & V_10 ) ;
if ( V_9 )
F_9 ( & V_9 -> V_11 ) ;
}
static void F_10 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_12 V_13 ;
F_11 ( & V_13 , V_9 -> V_14 , sizeof( V_9 -> V_14 [ 0 ] ) * V_9 -> V_15 ) ;
F_12 ( & V_9 -> V_11 ) ;
if ( F_13 ( V_7 , & V_13 , 1 , 0 , V_9 , V_16 ) < 0 )
F_14 () ;
F_15 ( V_7 ) ;
F_16 ( & V_9 -> V_11 ) ;
}
static void F_17 ( T_1 V_14 [] , struct V_1 * V_1 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 ; V_17 ++ )
V_14 [ V_17 ] = F_1 ( V_1 ) + V_17 ;
}
static void F_18 ( struct V_8 * V_9 , T_2 V_18 )
{
V_18 = F_19 ( V_18 , F_20 ( V_9 -> V_14 ) ) ;
for ( V_9 -> V_15 = 0 ; V_9 -> V_15 < V_18 ;
V_9 -> V_15 += V_5 ) {
struct V_1 * V_1 = F_21 ( V_19 | V_20 |
V_21 | V_22 ) ;
if ( ! V_1 ) {
if ( F_22 () )
F_23 ( V_23 , & V_9 -> V_24 -> V_25 ,
L_1 ,
V_18 ) ;
F_24 ( 200 ) ;
break;
}
F_17 ( V_9 -> V_14 + V_9 -> V_15 , V_1 ) ;
V_9 -> V_26 += V_5 ;
V_27 -- ;
F_25 ( & V_1 -> V_28 , & V_9 -> V_29 ) ;
}
if ( V_9 -> V_15 == 0 )
return;
F_10 ( V_9 , V_9 -> V_30 ) ;
}
static void F_26 ( const T_1 V_14 [] , unsigned int V_18 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 += V_5 ) {
F_27 ( F_4 ( V_14 [ V_17 ] ) ) ;
V_27 ++ ;
}
}
static void F_28 ( struct V_8 * V_9 , T_2 V_18 )
{
struct V_1 * V_1 ;
V_18 = F_19 ( V_18 , F_20 ( V_9 -> V_14 ) ) ;
for ( V_9 -> V_15 = 0 ; V_9 -> V_15 < V_18 ;
V_9 -> V_15 += V_5 ) {
V_1 = F_29 ( & V_9 -> V_29 , struct V_1 , V_28 ) ;
F_30 ( & V_1 -> V_28 ) ;
F_17 ( V_9 -> V_14 + V_9 -> V_15 , V_1 ) ;
V_9 -> V_26 -= V_5 ;
}
F_10 ( V_9 , V_9 -> V_31 ) ;
F_26 ( V_9 -> V_14 , V_9 -> V_15 ) ;
}
static inline void F_31 ( struct V_8 * V_9 , int V_32 ,
T_3 V_33 , T_4 V_34 )
{
F_5 ( V_32 >= V_35 ) ;
V_9 -> V_36 [ V_32 ] . V_33 = V_33 ;
V_9 -> V_36 [ V_32 ] . V_34 = V_34 ;
}
static void F_32 ( struct V_8 * V_9 )
{
unsigned long V_37 [ V_38 ] ;
struct V_39 V_17 ;
int V_32 = 0 ;
F_33 ( V_37 ) ;
F_34 ( & V_17 ) ;
F_31 ( V_9 , V_32 ++ , V_40 ,
F_35 ( V_37 [ V_41 ] ) ) ;
F_31 ( V_9 , V_32 ++ , V_42 ,
F_35 ( V_37 [ V_43 ] ) ) ;
F_31 ( V_9 , V_32 ++ , V_44 , V_37 [ V_45 ] ) ;
F_31 ( V_9 , V_32 ++ , V_46 , V_37 [ V_47 ] ) ;
F_31 ( V_9 , V_32 ++ , V_48 ,
F_35 ( V_17 . V_49 ) ) ;
F_31 ( V_9 , V_32 ++ , V_50 ,
F_35 ( V_17 . V_51 ) ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = F_8 ( V_7 , & V_10 ) ;
if ( ! V_9 )
return;
V_9 -> V_52 = 1 ;
F_37 ( & V_9 -> V_53 ) ;
}
static void F_38 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_12 V_13 ;
V_9 -> V_52 = 0 ;
F_32 ( V_9 ) ;
V_7 = V_9 -> V_54 ;
F_11 ( & V_13 , V_9 -> V_36 , sizeof( V_9 -> V_36 ) ) ;
if ( F_13 ( V_7 , & V_13 , 1 , 0 , V_9 , V_16 ) < 0 )
F_14 () ;
F_15 ( V_7 ) ;
}
static void F_39 ( struct V_55 * V_24 )
{
struct V_8 * V_9 = V_24 -> V_56 ;
F_37 ( & V_9 -> V_53 ) ;
}
static inline T_5 F_40 ( struct V_8 * V_9 )
{
T_6 V_57 ;
T_5 V_58 ;
V_9 -> V_24 -> V_59 -> V_60 ( V_9 -> V_24 ,
F_41 ( struct V_61 , V_26 ) ,
& V_57 , sizeof( V_57 ) ) ;
V_58 = F_42 ( V_57 ) ;
return V_58 - V_9 -> V_26 ;
}
static void F_43 ( struct V_8 * V_9 )
{
T_6 V_62 = F_44 ( V_9 -> V_26 ) ;
V_9 -> V_24 -> V_59 -> V_63 ( V_9 -> V_24 ,
F_41 ( struct V_61 , V_62 ) ,
& V_62 , sizeof( V_62 ) ) ;
}
static int F_45 ( void * V_64 )
{
struct V_8 * V_9 = V_64 ;
F_46 () ;
while ( ! F_47 () ) {
T_5 V_65 ;
F_48 () ;
F_49 ( V_9 -> V_53 ,
( V_65 = F_40 ( V_9 ) ) != 0
|| V_9 -> V_52
|| F_47 ()
|| F_50 ( V_66 ) ) ;
if ( V_9 -> V_52 )
F_38 ( V_9 ) ;
if ( V_65 > 0 )
F_18 ( V_9 , V_65 ) ;
else if ( V_65 < 0 )
F_28 ( V_9 , - V_65 ) ;
F_43 ( V_9 ) ;
}
return 0 ;
}
static int F_51 ( struct V_8 * V_9 )
{
struct V_6 * V_67 [ 3 ] ;
T_7 * V_68 [] = { F_7 , F_7 , F_36 } ;
const char * V_69 [] = { L_2 , L_3 , L_4 } ;
int V_70 , V_71 ;
V_71 = F_52 ( V_9 -> V_24 , V_72 ) ? 3 : 2 ;
V_70 = V_9 -> V_24 -> V_59 -> V_73 ( V_9 -> V_24 , V_71 , V_67 , V_68 , V_69 ) ;
if ( V_70 )
return V_70 ;
V_9 -> V_30 = V_67 [ 0 ] ;
V_9 -> V_31 = V_67 [ 1 ] ;
if ( F_52 ( V_9 -> V_24 , V_72 ) ) {
struct V_12 V_13 ;
V_9 -> V_54 = V_67 [ 2 ] ;
F_11 ( & V_13 , V_9 -> V_36 , sizeof V_9 -> V_36 ) ;
if ( F_13 ( V_9 -> V_54 , & V_13 , 1 , 0 , V_9 , V_16 )
< 0 )
F_14 () ;
F_15 ( V_9 -> V_54 ) ;
}
return 0 ;
}
static int F_53 ( struct V_55 * V_24 )
{
struct V_8 * V_9 ;
int V_70 ;
V_24 -> V_56 = V_9 = F_54 ( sizeof( * V_9 ) , V_16 ) ;
if ( ! V_9 ) {
V_70 = - V_74 ;
goto V_75;
}
F_55 ( & V_9 -> V_29 ) ;
V_9 -> V_26 = 0 ;
F_56 ( & V_9 -> V_53 ) ;
V_9 -> V_24 = V_24 ;
V_9 -> V_52 = 0 ;
V_70 = F_51 ( V_9 ) ;
if ( V_70 )
goto V_76;
V_9 -> V_77 = F_57 ( F_45 , V_9 , L_5 ) ;
if ( F_58 ( V_9 -> V_77 ) ) {
V_70 = F_59 ( V_9 -> V_77 ) ;
goto V_78;
}
return 0 ;
V_78:
V_24 -> V_59 -> V_79 ( V_24 ) ;
V_76:
F_60 ( V_9 ) ;
V_75:
return V_70 ;
}
static void T_8 F_61 ( struct V_55 * V_24 )
{
struct V_8 * V_9 = V_24 -> V_56 ;
F_62 ( V_9 -> V_77 ) ;
while ( V_9 -> V_26 )
F_28 ( V_9 , V_9 -> V_26 ) ;
F_43 ( V_9 ) ;
V_24 -> V_59 -> V_80 ( V_24 ) ;
V_24 -> V_59 -> V_79 ( V_24 ) ;
F_60 ( V_9 ) ;
}
static int F_63 ( struct V_55 * V_24 )
{
struct V_8 * V_9 = V_24 -> V_56 ;
while ( V_9 -> V_26 )
F_28 ( V_9 , V_9 -> V_26 ) ;
F_43 ( V_9 ) ;
V_24 -> V_59 -> V_80 ( V_24 ) ;
V_24 -> V_59 -> V_79 ( V_24 ) ;
return 0 ;
}
static int F_64 ( struct V_55 * V_24 )
{
struct V_8 * V_9 = V_24 -> V_56 ;
int V_81 ;
V_81 = F_51 ( V_24 -> V_56 ) ;
if ( V_81 )
return V_81 ;
F_18 ( V_9 , F_40 ( V_9 ) ) ;
F_43 ( V_9 ) ;
return 0 ;
}
static int F_65 ( struct V_55 * V_24 )
{
return F_64 ( V_24 ) ;
}
static int T_9 F_66 ( void )
{
return F_67 ( & V_82 ) ;
}
static void T_10 F_68 ( void )
{
F_69 ( & V_82 ) ;
}
