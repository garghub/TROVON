static void F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 | 0x80 ;
V_7 [ 1 ] = V_4 ;
F_3 ( V_6 , V_7 , 2 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
int V_10 ;
if ( ! V_4 )
return - V_11 ;
V_9 -> V_12 [ 0 ] = V_3 & 0x7f ;
V_10 = F_6 ( V_6 , V_9 -> V_12 , 1 , V_9 -> V_12 , 1 ) ;
if ( V_10 != 0 )
return V_10 ;
* V_4 = V_9 -> V_12 [ 0 ] ;
return 0 ;
}
static void F_7 ( struct V_5 * V_6 )
{
T_1 V_13 = 0 ;
T_2 V_14 ;
if ( F_8 ( V_6 -> V_2 . V_15 , L_1 ,
& V_13 ) )
goto V_16;
V_14 = V_17 ;
if ( F_9 ( V_6 -> V_2 . V_15 , L_2 ) )
V_14 |= V_18 ;
else
V_14 |= V_19 ;
switch ( V_13 ) {
case 250 :
V_14 |= V_20 ;
break;
case 2000 :
V_14 |= V_21 ;
break;
case 4000 :
V_14 |= V_22 ;
break;
default:
F_10 ( & V_6 -> V_2 ,
L_3 , V_13 ) ;
return;
}
F_1 ( & V_6 -> V_2 , V_23 , V_14 ) ;
V_16:
return;
}
static int F_11 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
int V_10 ;
V_9 -> V_12 [ 0 ] = V_26 ;
V_10 = F_6 ( V_6 , V_9 -> V_12 , 1 , V_9 -> V_12 , 8 ) ;
if ( V_10 != 0 )
return V_10 ;
V_25 -> V_27 = F_12 ( V_9 -> V_12 [ 0 ] ) ;
V_25 -> V_28 = F_12 ( V_9 -> V_12 [ 1 ] ) ;
V_25 -> V_29 = F_12 ( V_9 -> V_12 [ 2 ] ) ;
V_25 -> V_30 = F_12 ( V_9 -> V_12 [ 3 ] ) ;
V_25 -> V_31 = F_12 ( V_9 -> V_12 [ 4 ] ) ;
V_25 -> V_32 = F_12 ( V_9 -> V_12 [ 5 ] & 0x7f ) - 1 ;
V_25 -> V_33 = F_12 ( V_9 -> V_12 [ 6 ] ) + ( ( V_9 -> V_12 [ 5 ] & 0x80 ) ? 100 : 0 ) ;
return F_13 ( V_25 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
V_9 -> V_12 [ 0 ] = V_26 | 0x80 ;
V_9 -> V_12 [ 1 ] = F_15 ( V_25 -> V_27 ) ;
V_9 -> V_12 [ 2 ] = F_15 ( V_25 -> V_28 ) ;
V_9 -> V_12 [ 3 ] = F_15 ( V_25 -> V_29 ) ;
V_9 -> V_12 [ 4 ] = F_15 ( V_25 -> V_30 ) ;
V_9 -> V_12 [ 5 ] = F_15 ( V_25 -> V_31 ) ;
V_9 -> V_12 [ 6 ] = F_15 ( V_25 -> V_32 + 1 ) |
( ( V_25 -> V_33 > 99 ) ? 0x80 : 0x00 ) ;
V_9 -> V_12 [ 7 ] = F_15 ( V_25 -> V_33 % 100 ) ;
return F_6 ( V_6 , V_9 -> V_12 , 8 , NULL , 0 ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
unsigned char V_34 ;
struct V_8 * V_9 ;
int V_35 ;
V_6 -> V_36 = V_37 ;
V_6 -> V_38 = 8 ;
F_17 ( V_6 ) ;
V_9 = F_18 ( & V_6 -> V_2 , sizeof( * V_9 ) , V_39 ) ;
if ( ! V_9 )
return - V_40 ;
F_19 ( V_6 , V_9 ) ;
V_35 = F_4 ( & V_6 -> V_2 , V_26 , & V_34 ) ;
if ( V_35 != 0 ) {
F_20 ( & V_6 -> V_2 , L_4 ) ;
return V_35 ;
}
if ( V_6 -> V_2 . V_15 )
F_7 ( V_6 ) ;
V_9 -> V_41 = F_21 ( & V_6 -> V_2 , L_5 ,
& V_42 , V_43 ) ;
if ( F_22 ( V_9 -> V_41 ) ) {
F_20 ( & V_6 -> V_2 , L_6 ) ;
V_35 = F_23 ( V_9 -> V_41 ) ;
}
return V_35 ;
}
