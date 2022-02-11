static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
return V_5 -> V_8 [ V_2 -> V_9 ] + ( 4 * V_3 ) ;
}
static T_1 F_2 ( struct V_10 * V_11 , unsigned int V_3 )
{
struct V_12 * V_13 = F_3 ( V_11 -> V_2 -> V_6 -> V_14 ) ;
unsigned int V_15 = F_1 ( V_11 -> V_2 , V_3 ) ;
T_1 V_16 ;
F_4 ( V_13 , V_15 , & V_16 ) ;
return V_16 ;
}
static void F_5 ( struct V_10 * V_11 , unsigned int V_17 , T_1 V_16 )
{
struct V_12 * V_13 = F_3 ( V_11 -> V_2 -> V_6 -> V_14 ) ;
unsigned int V_15 = F_1 ( V_11 -> V_2 , V_17 ) ;
F_6 ( V_13 , V_15 , V_16 ) ;
}
static int F_7 ( struct V_10 * V_11 , unsigned int V_3 , T_1 * V_16 )
{
if ( V_3 > V_18 )
return - V_19 ;
* V_16 = F_2 ( V_11 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 , unsigned int V_3 , T_1 V_16 )
{
if ( V_3 > V_18 )
return - V_19 ;
F_5 ( V_11 , V_3 , V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 , const struct V_20 * V_21 )
{
const struct V_22 * V_23 [] = { & V_24 , NULL } ;
unsigned int V_25 = ( unsigned int ) V_21 -> V_26 ;
struct V_27 * V_6 ;
struct V_4 * V_5 ;
void T_2 * const * V_28 ;
struct V_29 * V_30 ;
int V_31 , V_32 ;
F_10 ( & V_13 -> V_14 , V_33 ) ;
V_32 = F_11 ( V_13 ) ;
if ( V_32 )
return V_32 ;
V_31 = 2 ;
if ( V_25 == V_34 )
V_31 = 4 ;
V_6 = F_12 ( & V_13 -> V_14 , V_23 , V_31 ) ;
if ( ! V_6 )
return - V_35 ;
V_5 = F_13 ( & V_13 -> V_14 , sizeof( * V_5 ) , V_36 ) ;
if ( ! V_5 )
return - V_35 ;
V_6 -> V_7 = V_5 ;
V_32 = F_14 ( V_6 ) ;
if ( V_32 )
return V_32 ;
F_15 ( V_6 ) ;
V_28 = V_6 -> V_28 ;
switch ( V_25 ) {
case V_34 :
V_5 -> V_8 [ 0 ] = V_37 ;
V_5 -> V_8 [ 1 ] = V_37 + V_38 ;
V_30 = & V_6 -> V_39 [ 2 ] -> V_30 ;
V_30 -> V_40 = V_28 [ 0 ] + 8 ;
V_30 -> V_41 =
V_30 -> V_42 = ( void T_2 * )
( ( unsigned long ) V_28 [ 1 ] | V_43 ) + 4 ;
V_30 -> V_44 = V_28 [ 4 ] + 16 ;
V_5 -> V_8 [ 2 ] = V_37 + V_38 * 4 ;
F_16 ( V_30 ) ;
F_17 ( V_6 -> V_39 [ 2 ] ,
L_1 ,
( unsigned long long ) F_18 ( V_13 , 0 ) + 8 ,
( ( unsigned long long ) F_18 ( V_13 , 1 ) | V_43 ) + 4 ,
( unsigned long long ) F_18 ( V_13 , 4 ) + 16 ) ;
V_30 = & V_6 -> V_39 [ 3 ] -> V_30 ;
V_30 -> V_40 = V_28 [ 2 ] + 8 ;
V_30 -> V_41 =
V_30 -> V_42 = ( void T_2 * )
( ( unsigned long ) V_28 [ 3 ] | V_43 ) + 4 ;
V_30 -> V_44 = V_28 [ 4 ] + 24 ;
V_5 -> V_8 [ 3 ] = V_37 + V_38 * 5 ;
F_16 ( V_30 ) ;
F_17 ( V_6 -> V_39 [ 2 ] ,
L_1 ,
( unsigned long long ) F_18 ( V_13 , 2 ) + 9 ,
( ( unsigned long long ) F_18 ( V_13 , 3 ) | V_43 ) + 4 ,
( unsigned long long ) F_18 ( V_13 , 4 ) + 24 ) ;
break;
case V_45 :
V_5 -> V_8 [ 0 ] = V_37 ;
V_5 -> V_8 [ 1 ] = V_37 + V_38 ;
break;
case V_46 :
V_5 -> V_8 [ 0 ] = V_47 ;
V_5 -> V_8 [ 1 ] = V_47 + V_48 ;
break;
default:
F_19 () ;
break;
}
F_20 ( V_13 ) ;
F_21 ( V_13 , 1 ) ;
return F_22 ( V_6 , V_13 -> V_49 , V_50 ,
V_51 , & V_52 ) ;
}
