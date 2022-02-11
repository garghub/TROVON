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
struct V_10 args ;
int V_11 ;
int V_12 ;
int V_13 = 0 ;
if ( V_9 -> V_14 > V_15 ||
V_9 -> V_16 > V_15 ) {
F_6 ( V_7 -> V_17 ,
L_1 ,
V_9 -> V_14 , V_9 -> V_16 ) ;
return - V_18 ;
}
args . V_19 = V_20 ;
args . V_21 = V_9 -> V_22 ;
args . V_23 = V_9 -> V_14 ;
V_11 = V_9 -> V_24 + args . V_19 +
args . V_21 + args . V_23 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_14 ; V_12 ++ ) {
F_7 ( V_9 -> V_25 [ V_12 ] , V_26 + V_12 ) ;
V_11 += V_9 -> V_25 [ V_12 ] ;
}
args . V_27 = V_11 & 0xFF ;
F_7 ( args . V_19 , V_28 ) ;
F_7 ( args . V_21 , V_28 + 1 ) ;
F_7 ( args . V_23 , V_28 + 2 ) ;
F_7 ( args . V_27 , V_28 + 3 ) ;
F_7 ( V_9 -> V_24 , V_4 ) ;
if ( F_1 () ) {
F_8 ( V_7 -> V_17 , L_2 ) ;
V_13 = - V_29 ;
goto V_30;
}
V_9 -> V_31 = F_3 ( V_32 ) ;
switch ( V_9 -> V_31 ) {
case V_33 :
break;
case V_34 :
V_13 = - V_35 ;
F_9 ( V_7 -> V_17 , L_3 ,
V_9 -> V_24 ) ;
goto V_30;
default:
F_9 ( V_7 -> V_17 , L_4 ,
V_9 -> V_24 , V_9 -> V_31 ) ;
}
args . V_19 = F_3 ( V_28 ) ;
args . V_21 = F_3 ( V_28 + 1 ) ;
args . V_23 = F_3 ( V_28 + 2 ) ;
args . V_27 = F_3 ( V_28 + 3 ) ;
if ( args . V_23 > V_9 -> V_16 ) {
F_6 ( V_7 -> V_17 ,
L_5 ,
args . V_23 , V_9 -> V_16 ) ;
V_13 = - V_36 ;
goto V_30;
}
V_11 = V_9 -> V_24 + args . V_19 +
args . V_21 + args . V_23 ;
for ( V_12 = 0 ; V_12 < args . V_23 ; V_12 ++ ) {
V_9 -> V_37 [ V_12 ] = F_3 ( V_26 + V_12 ) ;
V_11 += V_9 -> V_37 [ V_12 ] ;
}
if ( args . V_27 != ( V_11 & 0xFF ) ) {
F_6 ( V_7 -> V_17 ,
L_6 ,
args . V_27 , V_11 & 0xFF ) ;
V_13 = - V_38 ;
goto V_30;
}
V_13 = args . V_23 ;
V_30:
return V_13 ;
}
static int F_10 ( struct V_6 * V_7 , unsigned int V_39 ,
unsigned int V_40 , void * V_41 )
{
int V_12 = V_39 ;
char * V_42 = V_41 ;
int V_43 = 0 ;
if ( V_39 >= V_44 - V_40 )
return - V_18 ;
if ( V_40 ) {
for (; V_43 < V_40 ; V_12 ++ , V_42 ++ , V_43 ++ )
* V_42 = F_3 ( V_45 + V_12 ) ;
return V_43 ;
}
for (; V_12 < V_44 ; V_12 ++ , V_42 ++ ) {
* V_42 = F_3 ( V_45 + V_12 ) ;
V_43 ++ ;
if ( ! * V_42 )
break;
}
return V_43 ;
}
static int F_11 ( struct V_46 * V_47 )
{
struct V_48 * V_17 = & V_47 -> V_17 ;
struct V_6 * V_49 ;
int V_13 ;
if ( ! F_12 ( V_17 , V_45 , V_44 ,
F_13 ( V_17 ) ) ) {
F_6 ( V_17 , L_7 ) ;
return - V_50 ;
}
if ( ( F_3 ( V_45 + V_51 ) != 'E' ) ||
( F_3 ( V_45 + V_51 + 1 ) != 'C' ) ) {
F_6 ( V_17 , L_8 ) ;
return - V_52 ;
}
if ( ! F_12 ( V_17 , V_53 ,
V_54 , F_13 ( V_17 ) ) ) {
F_6 ( V_17 , L_9 ) ;
return - V_50 ;
}
if ( ! F_12 ( V_17 , V_55 ,
V_54 , F_13 ( V_17 ) ) ) {
F_6 ( V_17 , L_10 ) ;
return - V_50 ;
}
V_49 = F_14 ( V_17 , sizeof( * V_49 ) , V_56 ) ;
if ( ! V_49 )
return - V_57 ;
F_15 ( V_47 , V_49 ) ;
V_49 -> V_17 = V_17 ;
V_49 -> V_58 = V_47 -> V_59 ;
V_49 -> V_60 = F_13 ( V_17 ) ;
V_49 -> V_61 = V_17 ;
V_49 -> V_62 = F_5 ;
V_49 -> V_63 = F_10 ;
V_13 = F_16 ( V_49 ) ;
if ( V_13 ) {
F_6 ( V_17 , L_11 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_17 ( struct V_46 * V_47 )
{
struct V_6 * V_49 ;
V_49 = F_18 ( V_47 ) ;
F_19 ( V_49 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_13 ;
if ( ! F_21 ( V_64 ) ) {
F_22 ( V_65 L_12 ) ;
return - V_52 ;
}
V_13 = F_23 ( & V_66 ) ;
if ( V_13 ) {
F_22 ( V_65 L_13 , V_13 ) ;
return V_13 ;
}
V_13 = F_24 ( & V_67 ) ;
if ( V_13 ) {
F_22 ( V_65 L_14 , V_13 ) ;
F_25 ( & V_66 ) ;
return V_13 ;
}
return 0 ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_67 ) ;
F_25 ( & V_66 ) ;
}
