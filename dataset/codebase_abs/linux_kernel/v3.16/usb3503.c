static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_3 && F_2 ( V_2 -> V_4 ) )
F_3 ( V_2 -> V_4 , 0 ) ;
if ( F_2 ( V_2 -> V_5 ) )
F_3 ( V_2 -> V_5 , V_3 ) ;
if ( V_3 )
F_4 ( 4000 , 10000 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_1 ( V_2 , 1 ) ;
if ( V_2 -> V_9 ) {
V_8 = F_6 ( V_2 -> V_9 , V_10 ,
( V_11
| V_12 ) ) ;
if ( V_8 < 0 ) {
F_7 ( V_7 , L_1 , V_8 ) ;
return V_8 ;
}
if ( V_2 -> V_13 ) {
V_8 = F_8 ( V_2 -> V_9 , V_14 ,
V_2 -> V_13 ,
V_2 -> V_13 ) ;
if ( V_8 < 0 ) {
F_7 ( V_7 , L_2 , V_8 ) ;
return V_8 ;
}
}
V_8 = F_8 ( V_2 -> V_9 , V_15 ,
V_16 ,
V_16 ) ;
if ( V_8 < 0 ) {
F_7 ( V_7 , L_3 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_2 -> V_9 , V_10 ,
( V_11
| V_12 ) , 0 ) ;
if ( V_8 < 0 ) {
F_7 ( V_7 , L_1 , V_8 ) ;
return V_8 ;
}
}
if ( F_2 ( V_2 -> V_4 ) )
F_3 ( V_2 -> V_4 , 1 ) ;
V_2 -> V_17 = V_18 ;
F_9 ( V_7 , L_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , enum V_19 V_17 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 = 0 ;
switch ( V_17 ) {
case V_18 :
V_8 = F_5 ( V_2 ) ;
break;
case V_20 :
F_1 ( V_2 , 0 ) ;
V_2 -> V_17 = V_17 ;
F_9 ( V_7 , L_5 ) ;
break;
default:
F_7 ( V_7 , L_6 ) ;
V_8 = - V_21 ;
break;
}
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_22 * V_23 = F_12 ( V_7 ) ;
struct V_24 * V_25 = V_7 -> V_26 ;
int V_8 ;
T_1 V_17 = V_18 ;
const T_1 * V_27 ;
int V_28 ;
if ( V_23 ) {
V_2 -> V_13 = V_23 -> V_13 ;
V_2 -> V_29 = V_23 -> V_29 ;
V_2 -> V_4 = V_23 -> V_4 ;
V_2 -> V_5 = V_23 -> V_5 ;
V_2 -> V_17 = V_23 -> V_30 ;
} else if ( V_25 ) {
struct V_31 * V_31 ;
V_2 -> V_13 = 0 ;
V_31 = F_13 ( V_7 , L_7 ) ;
if ( F_14 ( V_31 ) && F_15 ( V_31 ) != - V_32 ) {
F_7 ( V_7 , L_8 , V_8 ) ;
return F_15 ( V_31 ) ;
}
if ( ! F_14 ( V_31 ) ) {
T_1 V_33 = 0 ;
V_2 -> V_31 = V_31 ;
if ( ! F_16 ( V_25 , L_9 ,
& V_33 ) ) {
switch ( V_33 ) {
case 38400000 :
case 26000000 :
case 19200000 :
case 12000000 :
V_2 -> V_34 = 0 ;
break;
case 24000000 :
case 27000000 :
case 25000000 :
case 50000000 :
V_2 -> V_34 = 1 ;
break;
default:
F_7 ( V_7 ,
L_10 ,
( int ) V_33 ) ;
return - V_21 ;
}
V_8 = F_17 ( V_2 -> V_31 , V_33 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_11 ,
( int ) V_33 ) ;
return V_8 ;
}
}
V_8 = F_18 ( V_2 -> V_31 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_12 ) ;
return V_8 ;
}
}
V_27 = F_19 ( V_25 , L_13 , & V_28 ) ;
if ( V_27 && ( V_28 / sizeof( T_1 ) ) > 0 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < V_28 / sizeof( T_1 ) ; V_35 ++ ) {
T_1 V_36 = F_20 ( V_27 [ V_35 ] ) ;
if ( ( 1 <= V_36 ) && ( V_36 <= 3 ) )
V_2 -> V_13 |= ( 1 << V_36 ) ;
}
}
V_2 -> V_29 = F_21 ( V_25 , L_14 , 0 ) ;
if ( V_2 -> V_29 == - V_37 )
return - V_37 ;
V_2 -> V_4 = F_21 ( V_25 , L_15 , 0 ) ;
if ( V_2 -> V_4 == - V_37 )
return - V_37 ;
V_2 -> V_5 = F_21 ( V_25 , L_16 , 0 ) ;
if ( V_2 -> V_5 == - V_37 )
return - V_37 ;
F_16 ( V_25 , L_17 , & V_17 ) ;
V_2 -> V_17 = V_17 ;
}
if ( V_2 -> V_13 && ! V_2 -> V_9 )
F_7 ( V_7 , L_18 ) ;
if ( F_2 ( V_2 -> V_29 ) ) {
int V_38 = V_2 -> V_34 ? V_39 :
V_40 ;
V_8 = F_22 ( V_7 , V_2 -> V_29 , V_38 ,
L_19 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_20 ,
V_2 -> V_29 , V_8 ) ;
return V_8 ;
}
}
if ( F_2 ( V_2 -> V_4 ) ) {
V_8 = F_22 ( V_7 , V_2 -> V_4 ,
V_39 , L_21 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_20 ,
V_2 -> V_4 , V_8 ) ;
return V_8 ;
}
}
if ( F_2 ( V_2 -> V_5 ) ) {
V_8 = F_22 ( V_7 , V_2 -> V_5 ,
V_39 , L_22 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_23 ,
V_2 -> V_5 , V_8 ) ;
return V_8 ;
}
}
F_10 ( V_2 , V_2 -> V_17 ) ;
F_9 ( V_7 , L_24 , V_41 ,
( V_2 -> V_17 == V_18 ) ? L_25 : L_26 ) ;
return 0 ;
}
static int F_23 ( struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_24 ( & V_43 -> V_7 , sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_2 ) {
F_7 ( & V_43 -> V_7 , L_27 ) ;
return - V_47 ;
}
F_25 ( V_43 , V_2 ) ;
V_2 -> V_9 = F_26 ( V_43 , & V_48 ) ;
if ( F_14 ( V_2 -> V_9 ) ) {
V_8 = F_15 ( V_2 -> V_9 ) ;
F_7 ( & V_43 -> V_7 , L_28 , V_8 ) ;
return V_8 ;
}
V_2 -> V_7 = & V_43 -> V_7 ;
return F_11 ( V_2 ) ;
}
static int F_27 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( & V_50 -> V_7 , sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_2 ) {
F_7 ( & V_50 -> V_7 , L_27 ) ;
return - V_47 ;
}
V_2 -> V_7 = & V_50 -> V_7 ;
return F_11 ( V_2 ) ;
}
static int T_2 F_28 ( void )
{
int V_8 ;
V_8 = F_29 ( V_51 , & V_52 ) ;
if ( V_8 != 0 )
F_30 ( L_29 , V_8 ) ;
V_8 = F_31 ( & V_53 ) ;
if ( V_8 != 0 )
F_30 ( L_30 ,
V_8 ) ;
return 0 ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_53 ) ;
F_34 ( & V_52 ) ;
}
