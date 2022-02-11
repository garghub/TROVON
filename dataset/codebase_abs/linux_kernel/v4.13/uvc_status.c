static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 () ;
if ( V_4 == NULL )
return - V_6 ;
F_3 ( V_2 -> V_7 , V_2 -> V_8 , sizeof( V_2 -> V_8 ) ) ;
F_4 ( V_2 -> V_8 , L_1 , sizeof( V_2 -> V_8 ) ) ;
V_4 -> V_9 = V_2 -> V_9 ;
V_4 -> V_10 = V_2 -> V_8 ;
F_5 ( V_2 -> V_7 , & V_4 -> V_11 ) ;
V_4 -> V_2 . V_12 = & V_2 -> V_13 -> V_2 ;
F_6 ( V_14 , V_4 -> V_15 ) ;
F_6 ( V_16 , V_4 -> V_17 ) ;
if ( ( V_5 = F_7 ( V_4 ) ) < 0 )
goto error;
V_2 -> V_4 = V_4 ;
return 0 ;
error:
F_8 ( V_4 ) ;
return V_5 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_10 ( V_2 -> V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_18 ,
int V_19 )
{
if ( V_2 -> V_4 ) {
F_12 ( V_2 -> V_4 , V_18 , V_19 ) ;
F_13 ( V_2 -> V_4 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_20 , int V_21 )
{
if ( V_21 < 3 ) {
F_15 ( V_22 , L_2
L_3 ) ;
return;
}
if ( V_20 [ 2 ] == 0 ) {
if ( V_21 < 4 )
return;
F_15 ( V_22 , L_4 ,
V_20 [ 1 ] , V_20 [ 3 ] ? L_5 : L_6 , V_21 ) ;
F_11 ( V_2 , V_16 , V_20 [ 3 ] ) ;
} else {
F_15 ( V_22 , L_7
L_8 , V_20 [ 1 ] , V_20 [ 2 ] , V_20 [ 3 ] , V_21 ) ;
}
}
static void F_16 ( struct V_1 * V_2 , T_1 * V_20 , int V_21 )
{
char * V_23 [ 3 ] = { L_9 , L_10 , L_11 } ;
if ( V_21 < 6 || V_20 [ 2 ] != 0 || V_20 [ 4 ] > 2 ) {
F_15 ( V_22 , L_12
L_3 ) ;
return;
}
F_15 ( V_22 , L_13 ,
V_20 [ 1 ] , V_20 [ 3 ] , V_23 [ V_20 [ 4 ] ] , V_21 ) ;
}
static void F_17 ( struct V_24 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
int V_21 , V_5 ;
switch ( V_24 -> V_26 ) {
case 0 :
break;
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
return;
default:
F_18 ( V_31 , L_14
L_15 , V_24 -> V_26 ) ;
return;
}
V_21 = V_24 -> V_32 ;
if ( V_21 > 0 ) {
switch ( V_2 -> V_26 [ 0 ] & 0x0f ) {
case V_33 :
F_16 ( V_2 , V_2 -> V_26 , V_21 ) ;
break;
case V_34 :
F_14 ( V_2 , V_2 -> V_26 , V_21 ) ;
break;
default:
F_15 ( V_22 , L_16
L_17 , V_2 -> V_26 [ 0 ] ) ;
break;
}
}
V_24 -> V_35 = V_2 -> V_36 -> V_37 . V_38 ;
if ( ( V_5 = F_19 ( V_24 , V_39 ) ) < 0 ) {
F_18 ( V_40 , L_18 ,
V_5 ) ;
}
}
int F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_36 ;
unsigned int V_43 ;
int V_35 ;
if ( V_42 == NULL )
return 0 ;
F_1 ( V_2 ) ;
V_2 -> V_26 = F_21 ( V_44 , V_45 ) ;
if ( V_2 -> V_26 == NULL )
return - V_6 ;
V_2 -> V_46 = F_22 ( 0 , V_45 ) ;
if ( V_2 -> V_46 == NULL ) {
F_23 ( V_2 -> V_26 ) ;
return - V_6 ;
}
V_43 = F_24 ( V_2 -> V_7 , V_42 -> V_37 . V_47 ) ;
V_35 = V_42 -> V_37 . V_38 ;
if ( V_35 > 16 && V_2 -> V_7 -> V_48 == V_49 &&
( V_2 -> V_50 & V_51 ) )
V_35 = F_25 ( V_35 ) - 1 ;
F_26 ( V_2 -> V_46 , V_2 -> V_7 , V_43 ,
V_2 -> V_26 , V_44 , F_17 ,
V_2 , V_35 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_46 ) ;
F_29 ( V_2 -> V_46 ) ;
F_23 ( V_2 -> V_26 ) ;
F_9 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_52 )
{
if ( V_2 -> V_46 == NULL )
return 0 ;
return F_19 ( V_2 -> V_46 , V_52 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_46 ) ;
}
