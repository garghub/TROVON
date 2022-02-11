static int F_1 ( void )
{
unsigned long V_1 = V_2 + V_3 ;
F_2 ( 200 , 300 ) ;
do {
if ( ! ( F_3 ( V_4 ) & V_5 ) )
return 0 ;
F_2 ( 100 , 200 ) ;
} while ( F_4 ( V_2 , V_1 ) );
return 1 ;
}
static int F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 V_13 ;
T_1 V_14 = 0 ;
int V_15 ;
int V_16 = 0 ;
T_1 * V_17 ;
V_16 = F_6 ( V_7 , V_9 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_7 ( V_7 -> V_17 [ V_15 ] , V_18 + V_15 ) ;
V_11 = (struct V_10 * ) V_7 -> V_17 ;
F_7 ( V_19 , V_4 ) ;
if ( F_1 () ) {
F_8 ( V_7 -> V_20 , L_1 ) ;
V_16 = - V_21 ;
goto V_22;
}
V_9 -> V_23 = F_3 ( V_24 ) ;
V_16 = F_9 ( V_7 , V_9 ) ;
if ( V_16 )
goto V_22;
V_17 = ( T_1 * ) & V_13 ;
for ( V_15 = 0 ; V_15 < sizeof( V_13 ) ; V_15 ++ ) {
V_17 [ V_15 ] = F_3 ( V_18 + V_15 ) ;
V_14 += V_17 [ V_15 ] ;
}
V_9 -> V_23 = V_13 . V_23 ;
if ( V_13 . V_25 > V_9 -> V_26 ) {
F_10 ( V_7 -> V_20 ,
L_2 ,
V_13 . V_25 , V_9 -> V_26 ) ;
V_16 = - V_27 ;
goto V_22;
}
for ( V_15 = 0 ; V_15 < V_13 . V_25 ; V_15 ++ ) {
V_9 -> V_28 [ V_15 ] =
F_3 ( V_18 + sizeof( V_13 ) + V_15 ) ;
V_14 += V_9 -> V_28 [ V_15 ] ;
}
if ( V_14 ) {
F_10 ( V_7 -> V_20 ,
L_3 ,
V_13 . V_29 ) ;
V_16 = - V_30 ;
goto V_22;
}
V_16 = V_13 . V_25 ;
V_22:
return V_16 ;
}
static int F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_31 args ;
int V_32 ;
int V_15 ;
int V_16 = 0 ;
if ( V_9 -> V_33 > V_34 ||
V_9 -> V_26 > V_34 ) {
F_10 ( V_7 -> V_20 ,
L_4 ,
V_9 -> V_33 , V_9 -> V_26 ) ;
return - V_35 ;
}
args . V_36 = V_37 ;
args . V_38 = V_9 -> V_39 ;
args . V_40 = V_9 -> V_33 ;
V_32 = V_9 -> V_41 + args . V_36 +
args . V_38 + args . V_40 ;
for ( V_15 = 0 ; V_15 < V_9 -> V_33 ; V_15 ++ ) {
F_7 ( V_9 -> V_28 [ V_15 ] , V_42 + V_15 ) ;
V_32 += V_9 -> V_28 [ V_15 ] ;
}
args . V_29 = V_32 & 0xFF ;
F_7 ( args . V_36 , V_43 ) ;
F_7 ( args . V_38 , V_43 + 1 ) ;
F_7 ( args . V_40 , V_43 + 2 ) ;
F_7 ( args . V_29 , V_43 + 3 ) ;
F_7 ( V_9 -> V_41 , V_4 ) ;
if ( F_1 () ) {
F_8 ( V_7 -> V_20 , L_1 ) ;
V_16 = - V_21 ;
goto V_22;
}
V_9 -> V_23 = F_3 ( V_24 ) ;
switch ( V_9 -> V_23 ) {
case V_44 :
break;
case V_45 :
V_16 = - V_46 ;
F_12 ( V_7 -> V_20 , L_5 ,
V_9 -> V_41 ) ;
goto V_22;
default:
F_12 ( V_7 -> V_20 , L_6 ,
V_9 -> V_41 , V_9 -> V_23 ) ;
}
args . V_36 = F_3 ( V_43 ) ;
args . V_38 = F_3 ( V_43 + 1 ) ;
args . V_40 = F_3 ( V_43 + 2 ) ;
args . V_29 = F_3 ( V_43 + 3 ) ;
if ( args . V_40 > V_9 -> V_26 ) {
F_10 ( V_7 -> V_20 ,
L_2 ,
args . V_40 , V_9 -> V_26 ) ;
V_16 = - V_47 ;
goto V_22;
}
V_32 = V_9 -> V_41 + args . V_36 +
args . V_38 + args . V_40 ;
for ( V_15 = 0 ; V_15 < args . V_40 ; V_15 ++ ) {
V_9 -> V_28 [ V_15 ] = F_3 ( V_42 + V_15 ) ;
V_32 += V_9 -> V_28 [ V_15 ] ;
}
if ( args . V_29 != ( V_32 & 0xFF ) ) {
F_10 ( V_7 -> V_20 ,
L_7 ,
args . V_29 , V_32 & 0xFF ) ;
V_16 = - V_30 ;
goto V_22;
}
V_16 = args . V_40 ;
V_22:
return V_16 ;
}
static int F_13 ( struct V_6 * V_7 , unsigned int V_48 ,
unsigned int V_49 , void * V_50 )
{
int V_15 = V_48 ;
char * V_51 = V_50 ;
int V_52 = 0 ;
if ( V_48 >= V_53 - V_49 )
return - V_35 ;
if ( V_49 ) {
for (; V_52 < V_49 ; V_15 ++ , V_51 ++ , V_52 ++ )
* V_51 = F_3 ( V_54 + V_15 ) ;
return V_52 ;
}
for (; V_15 < V_53 ; V_15 ++ , V_51 ++ ) {
* V_51 = F_3 ( V_54 + V_15 ) ;
V_52 ++ ;
if ( ! * V_51 )
break;
}
return V_52 ;
}
static int F_14 ( struct V_55 * V_56 )
{
struct V_57 * V_20 = & V_56 -> V_20 ;
struct V_6 * V_58 ;
int V_16 ;
if ( ! F_15 ( V_20 , V_54 , V_53 ,
F_16 ( V_20 ) ) ) {
F_10 ( V_20 , L_8 ) ;
return - V_59 ;
}
if ( ( F_3 ( V_54 + V_60 ) != 'E' ) ||
( F_3 ( V_54 + V_60 + 1 ) != 'C' ) ) {
F_10 ( V_20 , L_9 ) ;
return - V_61 ;
}
if ( ! F_15 ( V_20 , V_62 ,
V_63 , F_16 ( V_20 ) ) ) {
F_10 ( V_20 , L_10 ) ;
return - V_59 ;
}
if ( ! F_15 ( V_20 , V_64 ,
V_63 , F_16 ( V_20 ) ) ) {
F_10 ( V_20 , L_11 ) ;
return - V_59 ;
}
V_58 = F_17 ( V_20 , sizeof( * V_58 ) , V_65 ) ;
if ( ! V_58 )
return - V_66 ;
F_18 ( V_56 , V_58 ) ;
V_58 -> V_20 = V_20 ;
V_58 -> V_67 = F_16 ( V_20 ) ;
V_58 -> V_68 = F_11 ;
V_58 -> V_69 = F_5 ;
V_58 -> V_70 = F_13 ;
V_58 -> V_71 = sizeof( struct V_12 ) +
sizeof( struct V_72 ) ;
V_58 -> V_73 = sizeof( struct V_10 ) ;
V_16 = F_19 ( V_58 ) ;
if ( V_16 ) {
F_10 ( V_20 , L_12 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_20 ( struct V_55 * V_56 )
{
struct V_6 * V_58 ;
V_58 = F_21 ( V_56 ) ;
F_22 ( V_58 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
int V_16 ;
if ( ! F_24 ( V_74 ) ) {
F_25 ( V_75 L_13 ) ;
return - V_61 ;
}
V_16 = F_26 ( & V_76 ) ;
if ( V_16 ) {
F_25 ( V_75 L_14 , V_16 ) ;
return V_16 ;
}
V_16 = F_27 ( & V_77 ) ;
if ( V_16 ) {
F_25 ( V_75 L_15 , V_16 ) ;
F_28 ( & V_76 ) ;
return V_16 ;
}
return 0 ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_77 ) ;
F_28 ( & V_76 ) ;
}
