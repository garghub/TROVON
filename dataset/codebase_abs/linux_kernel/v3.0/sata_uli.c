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
static int V_22 ;
const struct V_23 * V_24 [] = { & V_25 , NULL } ;
unsigned int V_26 = ( unsigned int ) V_21 -> V_27 ;
struct V_28 * V_6 ;
struct V_4 * V_5 ;
void T_2 * const * V_29 ;
struct V_30 * V_31 ;
int V_32 , V_33 ;
if ( ! V_22 ++ )
F_10 ( V_34 , & V_13 -> V_14 , L_1 V_35 L_2 ) ;
V_33 = F_11 ( V_13 ) ;
if ( V_33 )
return V_33 ;
V_32 = 2 ;
if ( V_26 == V_36 )
V_32 = 4 ;
V_6 = F_12 ( & V_13 -> V_14 , V_24 , V_32 ) ;
if ( ! V_6 )
return - V_37 ;
V_5 = F_13 ( & V_13 -> V_14 , sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return - V_37 ;
V_6 -> V_7 = V_5 ;
V_33 = F_14 ( V_6 ) ;
if ( V_33 )
return V_33 ;
F_15 ( V_6 ) ;
V_29 = V_6 -> V_29 ;
switch ( V_26 ) {
case V_36 :
V_5 -> V_8 [ 0 ] = V_39 ;
V_5 -> V_8 [ 1 ] = V_39 + V_40 ;
V_31 = & V_6 -> V_41 [ 2 ] -> V_31 ;
V_31 -> V_42 = V_29 [ 0 ] + 8 ;
V_31 -> V_43 =
V_31 -> V_44 = ( void T_2 * )
( ( unsigned long ) V_29 [ 1 ] | V_45 ) + 4 ;
V_31 -> V_46 = V_29 [ 4 ] + 16 ;
V_5 -> V_8 [ 2 ] = V_39 + V_40 * 4 ;
F_16 ( V_31 ) ;
F_17 ( V_6 -> V_41 [ 2 ] ,
L_3 ,
( unsigned long long ) F_18 ( V_13 , 0 ) + 8 ,
( ( unsigned long long ) F_18 ( V_13 , 1 ) | V_45 ) + 4 ,
( unsigned long long ) F_18 ( V_13 , 4 ) + 16 ) ;
V_31 = & V_6 -> V_41 [ 3 ] -> V_31 ;
V_31 -> V_42 = V_29 [ 2 ] + 8 ;
V_31 -> V_43 =
V_31 -> V_44 = ( void T_2 * )
( ( unsigned long ) V_29 [ 3 ] | V_45 ) + 4 ;
V_31 -> V_46 = V_29 [ 4 ] + 24 ;
V_5 -> V_8 [ 3 ] = V_39 + V_40 * 5 ;
F_16 ( V_31 ) ;
F_17 ( V_6 -> V_41 [ 2 ] ,
L_3 ,
( unsigned long long ) F_18 ( V_13 , 2 ) + 9 ,
( ( unsigned long long ) F_18 ( V_13 , 3 ) | V_45 ) + 4 ,
( unsigned long long ) F_18 ( V_13 , 4 ) + 24 ) ;
break;
case V_47 :
V_5 -> V_8 [ 0 ] = V_39 ;
V_5 -> V_8 [ 1 ] = V_39 + V_40 ;
break;
case V_48 :
V_5 -> V_8 [ 0 ] = V_49 ;
V_5 -> V_8 [ 1 ] = V_49 + V_50 ;
break;
default:
F_19 () ;
break;
}
F_20 ( V_13 ) ;
F_21 ( V_13 , 1 ) ;
return F_22 ( V_6 , V_13 -> V_51 , V_52 ,
V_53 , & V_54 ) ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_55 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_55 ) ;
}
