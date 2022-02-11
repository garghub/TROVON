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
V_2 -> V_13 = 0 ;
V_27 = F_13 ( V_25 , L_7 , & V_28 ) ;
if ( V_27 && ( V_28 / sizeof( T_1 ) ) > 0 ) {
int V_31 ;
for ( V_31 = 0 ; V_31 < V_28 / sizeof( T_1 ) ; V_31 ++ ) {
T_1 V_32 = F_14 ( V_27 [ V_31 ] ) ;
if ( ( 1 <= V_32 ) && ( V_32 <= 3 ) )
V_2 -> V_13 |= ( 1 << V_32 ) ;
}
}
V_2 -> V_29 = F_15 ( V_25 , L_8 , 0 ) ;
if ( V_2 -> V_29 == - V_33 )
return - V_33 ;
V_2 -> V_4 = F_15 ( V_25 , L_9 , 0 ) ;
if ( V_2 -> V_4 == - V_33 )
return - V_33 ;
V_2 -> V_5 = F_15 ( V_25 , L_10 , 0 ) ;
if ( V_2 -> V_5 == - V_33 )
return - V_33 ;
F_16 ( V_25 , L_11 , & V_17 ) ;
V_2 -> V_17 = V_17 ;
}
if ( V_2 -> V_13 && ! V_2 -> V_9 )
F_7 ( V_7 , L_12 ) ;
if ( F_2 ( V_2 -> V_29 ) ) {
V_8 = F_17 ( V_7 , V_2 -> V_29 ,
V_34 , L_13 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_14 ,
V_2 -> V_29 , V_8 ) ;
return V_8 ;
}
}
if ( F_2 ( V_2 -> V_4 ) ) {
V_8 = F_17 ( V_7 , V_2 -> V_4 ,
V_35 , L_15 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_14 ,
V_2 -> V_4 , V_8 ) ;
return V_8 ;
}
}
if ( F_2 ( V_2 -> V_5 ) ) {
V_8 = F_17 ( V_7 , V_2 -> V_5 ,
V_35 , L_16 ) ;
if ( V_8 ) {
F_7 ( V_7 ,
L_17 ,
V_2 -> V_5 , V_8 ) ;
return V_8 ;
}
}
F_10 ( V_2 , V_2 -> V_17 ) ;
F_9 ( V_7 , L_18 , V_36 ,
( V_2 -> V_17 == V_18 ) ? L_19 : L_20 ) ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_19 ( & V_38 -> V_7 , sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
F_7 ( & V_38 -> V_7 , L_21 ) ;
return - V_42 ;
}
F_20 ( V_38 , V_2 ) ;
V_2 -> V_9 = F_21 ( V_38 , & V_43 ) ;
if ( F_22 ( V_2 -> V_9 ) ) {
V_8 = F_23 ( V_2 -> V_9 ) ;
F_7 ( & V_38 -> V_7 , L_22 , V_8 ) ;
return V_8 ;
}
V_2 -> V_7 = & V_38 -> V_7 ;
return F_11 ( V_2 ) ;
}
static int F_24 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( & V_45 -> V_7 , sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 ) {
F_7 ( & V_45 -> V_7 , L_21 ) ;
return - V_42 ;
}
V_2 -> V_7 = & V_45 -> V_7 ;
return F_11 ( V_2 ) ;
}
static int T_2 F_25 ( void )
{
int V_8 ;
V_8 = F_26 ( V_46 , & V_47 ) ;
if ( V_8 != 0 )
F_27 ( L_23 , V_8 ) ;
V_8 = F_28 ( & V_48 ) ;
if ( V_8 != 0 )
F_27 ( L_24 ,
V_8 ) ;
return 0 ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_48 ) ;
F_31 ( & V_47 ) ;
}
