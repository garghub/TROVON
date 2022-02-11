static int F_1 ( void )
{
unsigned long V_1 = V_2 + V_3 ;
T_1 V_4 ;
F_2 ( 200 , 300 ) ;
do {
if ( ! ( F_3 ( V_5 , 1 , & V_4 ) &
V_6 ) )
return 0 ;
F_2 ( 100 , 200 ) ;
} while ( F_4 ( V_2 , V_1 ) );
return 1 ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 V_14 ;
T_1 V_15 ;
int V_16 = 0 ;
T_1 * V_17 ;
V_16 = F_6 ( V_8 , V_10 ) ;
F_7 ( V_18 , V_16 , V_8 -> V_17 ) ;
V_12 = (struct V_11 * ) V_8 -> V_17 ;
V_15 = V_19 ;
F_7 ( V_5 , 1 , & V_15 ) ;
if ( F_1 () ) {
F_8 ( V_8 -> V_20 , L_1 ) ;
V_16 = - V_21 ;
goto V_22;
}
V_10 -> V_23 = F_3 ( V_24 , 1 , & V_15 ) ;
V_16 = F_9 ( V_8 , V_10 ) ;
if ( V_16 )
goto V_22;
V_17 = ( T_1 * ) & V_14 ;
V_15 = F_3 ( V_18 , sizeof( V_14 ) ,
V_17 ) ;
V_10 -> V_23 = V_14 . V_23 ;
if ( V_14 . V_25 > V_10 -> V_26 ) {
F_10 ( V_8 -> V_20 ,
L_2 ,
V_14 . V_25 , V_10 -> V_26 ) ;
V_16 = - V_27 ;
goto V_22;
}
V_15 += F_3 ( V_18 +
sizeof( V_14 ) , V_14 . V_25 ,
V_10 -> V_4 ) ;
if ( V_15 ) {
F_10 ( V_8 -> V_20 ,
L_3 ,
V_14 . V_28 ) ;
V_16 = - V_29 ;
goto V_22;
}
V_16 = V_14 . V_25 ;
V_22:
return V_16 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_30 args ;
T_1 V_15 ;
int V_16 = 0 ;
if ( V_10 -> V_31 > V_32 ||
V_10 -> V_26 > V_32 ) {
F_10 ( V_8 -> V_20 ,
L_4 ,
V_10 -> V_31 , V_10 -> V_26 ) ;
return - V_33 ;
}
args . V_34 = V_35 ;
args . V_36 = V_10 -> V_37 ;
args . V_38 = V_10 -> V_31 ;
V_15 = V_10 -> V_39 + args . V_34 + args . V_36 + args . V_38 ;
V_15 += F_7 ( V_40 , V_10 -> V_31 ,
V_10 -> V_4 ) ;
args . V_28 = V_15 ;
F_7 ( V_41 , sizeof( args ) ,
( T_1 * ) & args ) ;
V_15 = V_10 -> V_39 ;
F_7 ( V_5 , 1 , & V_15 ) ;
if ( F_1 () ) {
F_8 ( V_8 -> V_20 , L_1 ) ;
V_16 = - V_21 ;
goto V_22;
}
V_10 -> V_23 = F_3 ( V_24 , 1 , & V_15 ) ;
V_16 = F_9 ( V_8 , V_10 ) ;
if ( V_16 )
goto V_22;
F_3 ( V_41 , sizeof( args ) ,
( T_1 * ) & args ) ;
if ( args . V_38 > V_10 -> V_26 ) {
F_10 ( V_8 -> V_20 ,
L_2 ,
args . V_38 , V_10 -> V_26 ) ;
V_16 = - V_42 ;
goto V_22;
}
V_15 = V_10 -> V_39 + args . V_34 + args . V_36 + args . V_38 ;
V_15 += F_3 ( V_40 , args . V_38 ,
V_10 -> V_4 ) ;
if ( args . V_28 != V_15 ) {
F_10 ( V_8 -> V_20 ,
L_5 ,
args . V_28 , V_15 ) ;
V_16 = - V_29 ;
goto V_22;
}
V_16 = args . V_38 ;
V_22:
return V_16 ;
}
static int F_12 ( struct V_7 * V_8 , unsigned int V_43 ,
unsigned int V_44 , void * V_45 )
{
int V_46 = V_43 ;
char * V_47 = V_45 ;
int V_48 = 0 ;
if ( V_43 >= V_49 - V_44 )
return - V_33 ;
if ( V_44 ) {
F_3 ( V_50 + V_43 , V_44 , V_47 ) ;
return V_44 ;
}
for (; V_46 < V_49 ; V_46 ++ , V_47 ++ ) {
F_3 ( V_50 + V_46 , 1 , V_47 ) ;
V_48 ++ ;
if ( ! * V_47 )
break;
}
return V_48 ;
}
static void F_13 ( T_2 V_51 , T_3 V_52 , void * V_4 )
{
struct V_7 * V_53 = V_4 ;
if ( V_53 -> V_54 &&
F_14 ( V_53 , NULL ) > 0 )
F_15 ( & V_53 -> V_55 , 0 ,
V_53 ) ;
}
static int F_16 ( struct V_56 * V_57 )
{
struct V_51 * V_20 = & V_57 -> V_20 ;
struct V_58 * V_59 ;
T_4 V_60 ;
struct V_7 * V_53 ;
T_1 V_61 [ 2 ] ;
int V_16 ;
if ( ! F_17 ( V_20 , V_50 , V_49 ,
F_18 ( V_20 ) ) ) {
F_10 ( V_20 , L_6 ) ;
return - V_62 ;
}
F_3 ( V_50 + V_63 , 2 , V_61 ) ;
if ( V_61 [ 0 ] != 'E' || V_61 [ 1 ] != 'C' ) {
F_10 ( V_20 , L_7 ) ;
return - V_64 ;
}
if ( ! F_17 ( V_20 , V_65 ,
V_66 , F_18 ( V_20 ) ) ) {
F_10 ( V_20 , L_8 ) ;
return - V_62 ;
}
if ( ! F_17 ( V_20 , V_67 ,
V_66 , F_18 ( V_20 ) ) ) {
F_10 ( V_20 , L_9 ) ;
return - V_62 ;
}
V_53 = F_19 ( V_20 , sizeof( * V_53 ) , V_68 ) ;
if ( ! V_53 )
return - V_69 ;
F_20 ( V_57 , V_53 ) ;
V_53 -> V_20 = V_20 ;
V_53 -> V_70 = F_18 ( V_20 ) ;
V_53 -> V_71 = F_11 ;
V_53 -> V_72 = F_5 ;
V_53 -> V_73 = F_12 ;
V_53 -> V_74 = sizeof( struct V_13 ) +
sizeof( struct V_75 ) ;
V_53 -> V_76 = sizeof( struct V_11 ) ;
V_16 = F_21 ( V_53 ) ;
if ( V_16 ) {
F_10 ( V_20 , L_10 , V_16 ) ;
return V_16 ;
}
V_59 = F_22 ( V_20 ) ;
if ( V_59 ) {
V_60 = F_23 ( V_59 -> V_77 ,
V_78 ,
F_13 ,
V_53 ) ;
if ( F_24 ( V_60 ) )
F_8 ( V_20 , L_11 ,
V_60 ) ;
}
return 0 ;
}
static int F_25 ( struct V_56 * V_57 )
{
struct V_7 * V_53 ;
struct V_58 * V_59 ;
V_59 = F_22 ( & V_57 -> V_20 ) ;
if ( V_59 )
F_26 ( V_59 -> V_77 , V_78 ,
F_13 ) ;
V_53 = F_27 ( V_57 ) ;
F_28 ( V_53 ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_20 )
{
struct V_7 * V_53 = F_30 ( V_20 ) ;
return F_31 ( V_53 ) ;
}
static int F_32 ( struct V_51 * V_20 )
{
struct V_7 * V_53 = F_30 ( V_20 ) ;
return F_33 ( V_53 ) ;
}
static int T_5 F_34 ( void )
{
int V_16 ;
if ( ! F_35 ( V_79 ) ) {
F_36 ( V_80 L_12 ) ;
return - V_64 ;
}
F_37 () ;
V_16 = F_38 ( & V_81 ) ;
if ( V_16 ) {
F_36 ( V_80 L_13 , V_16 ) ;
F_39 () ;
return V_16 ;
}
return 0 ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_81 ) ;
F_39 () ;
}
