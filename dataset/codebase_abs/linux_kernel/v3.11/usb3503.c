static int F_1 ( struct V_1 * V_2 ,
char V_3 , char V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , char V_3 )
{
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , char V_3 , char V_5 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_2 , V_3 , V_6 | V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , char V_3 , char V_5 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_2 , V_3 , V_6 & ~ V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_7 ( int V_7 , int V_8 )
{
if ( F_8 ( V_7 ) )
F_9 ( V_7 , V_8 ) ;
if ( V_8 )
F_10 ( 4000 , 10000 ) ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 , enum V_11 V_12 )
{
struct V_1 * V_13 = V_10 -> V_2 ;
int V_6 = 0 ;
switch ( V_12 ) {
case V_14 :
F_7 ( V_10 -> V_7 , 1 ) ;
V_6 = F_1 ( V_13 , V_15 ,
( V_16
| V_17 ) ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_1 , V_6 ) ;
goto V_19;
}
if ( V_10 -> V_20 ) {
V_6 = F_5 ( V_13 , V_21 ,
V_10 -> V_20 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_2 , V_6 ) ;
goto V_19;
}
}
V_6 = F_5 ( V_13 , V_22 , V_23 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_3 , V_6 ) ;
goto V_19;
}
V_6 = F_6 ( V_13 , V_15 ,
( V_16
| V_17 ) ) ;
if ( V_6 < 0 ) {
F_12 ( & V_13 -> V_18 , L_1 , V_6 ) ;
goto V_19;
}
V_10 -> V_12 = V_12 ;
F_13 ( & V_13 -> V_18 , L_4 ) ;
break;
case V_24 :
F_7 ( V_10 -> V_7 , 0 ) ;
V_10 -> V_12 = V_12 ;
F_13 ( & V_13 -> V_18 , L_5 ) ;
break;
default:
F_12 ( & V_13 -> V_18 , L_6 ) ;
V_6 = - V_25 ;
break;
}
V_19:
return V_6 ;
}
static int F_14 ( struct V_1 * V_13 , const struct V_26 * V_27 )
{
struct V_28 * V_29 = V_13 -> V_18 . V_30 ;
struct V_31 * V_32 = V_13 -> V_18 . V_33 ;
struct V_9 * V_10 ;
int V_6 = - V_34 ;
T_1 V_12 = V_35 ;
const T_1 * V_36 ;
int V_37 ;
V_10 = F_15 ( sizeof( struct V_9 ) , V_38 ) ;
if ( ! V_10 ) {
F_12 ( & V_13 -> V_18 , L_7 ) ;
return V_6 ;
}
F_16 ( V_13 , V_10 ) ;
V_10 -> V_2 = V_13 ;
if ( V_29 ) {
V_10 -> V_20 = V_29 -> V_20 ;
V_10 -> V_39 = V_29 -> V_39 ;
V_10 -> V_40 = V_29 -> V_40 ;
V_10 -> V_7 = V_29 -> V_7 ;
V_10 -> V_12 = V_29 -> V_41 ;
} else if ( V_32 ) {
V_10 -> V_20 = 0 ;
V_36 = F_17 ( V_32 , L_8 , & V_37 ) ;
if ( V_36 && ( V_37 / sizeof( T_1 ) ) > 0 ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < V_37 / sizeof( T_1 ) ; V_42 ++ ) {
T_1 V_43 = F_18 ( V_36 [ V_42 ] ) ;
if ( ( 1 <= V_43 ) && ( V_43 <= 3 ) )
V_10 -> V_20 |= ( 1 << V_43 ) ;
}
}
V_10 -> V_39 = F_19 ( V_32 , L_9 , 0 ) ;
if ( V_10 -> V_39 == - V_44 )
return - V_44 ;
V_10 -> V_40 = F_19 ( V_32 , L_10 , 0 ) ;
if ( V_10 -> V_40 == - V_44 )
return - V_44 ;
V_10 -> V_7 = F_19 ( V_32 , L_11 , 0 ) ;
if ( V_10 -> V_7 == - V_44 )
return - V_44 ;
F_20 ( V_32 , L_12 , & V_12 ) ;
V_10 -> V_12 = V_12 ;
}
if ( F_8 ( V_10 -> V_39 ) ) {
V_6 = F_21 ( V_10 -> V_39 ,
V_45 , L_13 ) ;
if ( V_6 ) {
F_12 ( & V_13 -> V_18 ,
L_14 ,
V_10 -> V_39 , V_6 ) ;
goto V_46;
}
}
if ( F_8 ( V_10 -> V_40 ) ) {
V_6 = F_21 ( V_10 -> V_40 ,
V_45 , L_15 ) ;
if ( V_6 ) {
F_12 ( & V_13 -> V_18 ,
L_14 ,
V_10 -> V_40 , V_6 ) ;
goto V_47;
}
}
if ( F_8 ( V_10 -> V_7 ) ) {
V_6 = F_21 ( V_10 -> V_7 ,
V_48 , L_16 ) ;
if ( V_6 ) {
F_12 ( & V_13 -> V_18 ,
L_17 ,
V_10 -> V_7 , V_6 ) ;
goto V_49;
}
}
F_11 ( V_10 , V_10 -> V_12 ) ;
F_13 ( & V_13 -> V_18 , L_18 , V_50 ,
( V_10 -> V_12 == V_14 ) ? L_19 : L_20 ) ;
return 0 ;
V_49:
if ( F_8 ( V_10 -> V_40 ) )
F_22 ( V_10 -> V_40 ) ;
V_47:
if ( F_8 ( V_10 -> V_39 ) )
F_22 ( V_10 -> V_39 ) ;
V_46:
F_23 ( V_10 ) ;
return V_6 ;
}
static int F_24 ( struct V_1 * V_13 )
{
struct V_9 * V_10 = F_25 ( V_13 ) ;
if ( F_8 ( V_10 -> V_39 ) )
F_22 ( V_10 -> V_39 ) ;
if ( F_8 ( V_10 -> V_40 ) )
F_22 ( V_10 -> V_40 ) ;
if ( F_8 ( V_10 -> V_7 ) )
F_22 ( V_10 -> V_7 ) ;
F_23 ( V_10 ) ;
return 0 ;
}
