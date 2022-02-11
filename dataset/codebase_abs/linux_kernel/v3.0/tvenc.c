static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
F_3 ( V_5 ) ;
if ( V_6 && V_6 -> V_7 )
V_3 = V_6 -> V_7 ( 0 ) ;
if ( V_3 )
F_4 ( V_8 L_1 ,
V_9 , V_3 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_6 && V_6 -> V_7 )
V_3 = V_6 -> V_7 ( 1 ) ;
if ( V_3 ) {
F_4 ( V_8 L_2 ,
V_9 , V_3 ) ;
return V_3 ;
}
F_6 ( V_4 ) ;
F_6 ( V_5 ) ;
V_3 = F_7 ( V_2 ) ;
return V_3 ;
}
void F_8 ( struct V_10 * V_11 )
{
T_1 V_12 = 0 , V_13 ;
V_12 = F_9 ( V_14 ) ;
V_12 |= V_15 ;
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
F_10 ( V_16 , 0 ) ;
switch ( V_13 ) {
case 0 :
V_12 |= V_17 ;
break;
case 1 :
V_12 |= V_18 ;
break;
default:
V_12 |= V_19 ;
break;
}
F_10 ( V_16 , V_12 ) ;
F_11 ( 5000 ) ;
switch ( V_13 ) {
case 0 :
V_12 &= ~ V_17 ;
break;
case 1 :
V_12 &= ~ V_18 ;
break;
default:
V_12 &= ~ V_19 ;
break;
}
}
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_1 * V_20 = NULL ;
struct V_21 * V_22 = NULL ;
int V_23 ;
if ( V_2 -> V_24 == 0 ) {
V_25 = F_13 ( V_2 -> V_26 [ 0 ] . V_27 ,
V_2 -> V_26 [ 0 ] . V_28 -
V_2 -> V_26 [ 0 ] . V_27 + 1 ) ;
if ( ! V_25 ) {
F_4 ( V_8
L_3 ) ;
return - V_29 ;
}
V_6 = V_2 -> V_30 . V_31 ;
V_32 = 1 ;
return 0 ;
}
if ( ! V_32 )
return - V_33 ;
V_11 = F_14 ( V_2 ) ;
if ( ! V_11 )
return - V_34 ;
if ( V_11 -> V_35 != V_36 )
return - V_37 ;
if ( V_38 >= V_39 )
return - V_29 ;
if ( V_25 == NULL )
return - V_29 ;
V_20 = F_15 ( L_4 , V_2 -> V_24 ) ;
if ( ! V_20 )
return - V_29 ;
V_11 -> V_2 = V_20 ;
V_11 -> V_40 = V_41 ;
if ( F_16
( V_20 , V_2 -> V_30 . V_31 ,
sizeof( struct V_21 ) ) ) {
F_4 ( V_8 L_5 ) ;
F_17 ( V_20 ) ;
return - V_29 ;
}
V_22 = V_20 -> V_30 . V_31 ;
V_22 -> V_42 = F_5 ;
V_22 -> V_43 = F_1 ;
V_22 -> V_44 = V_2 ;
V_11 -> V_45 = V_22 -> V_45 ;
V_11 -> V_46 = V_47 ;
F_18 ( V_20 , V_11 ) ;
V_23 = F_19 ( V_20 ) ;
if ( V_23 )
goto V_48;
V_49 [ V_38 ++ ] = V_2 ;
return 0 ;
V_48:
F_17 ( V_20 ) ;
return V_23 ;
}
static int F_20 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_21 ( void )
{
return F_22 ( & V_50 ) ;
}
static int T_2 F_23 ( void )
{
V_4 = F_24 ( NULL , L_6 ) ;
V_5 = F_24 ( NULL , L_7 ) ;
if ( F_25 ( V_4 ) ) {
F_4 ( V_8 L_8 ) ;
return F_26 ( V_4 ) ;
}
if ( F_25 ( V_5 ) ) {
F_4 ( V_8 L_9 ) ;
F_27 ( V_4 ) ;
return F_26 ( V_5 ) ;
}
return F_21 () ;
}
