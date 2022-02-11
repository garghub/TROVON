static void * F_1 ( T_1 V_1 )
{
if ( V_1 & ( 1UL << 63 ) )
return ( void * ) ( V_2 | V_1 ) ;
return F_2 ( V_1 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 V_6 ;
T_2 V_7 ;
V_6 . V_8 = F_1 ( V_4 -> V_8 ) ;
V_6 . V_9 = F_1 ( V_4 -> V_9 ) ;
V_7 = ( T_2 ) & V_6 ;
F_4 ( V_7 , V_4 -> V_10 ,
V_4 -> V_11 [ 0 ] , V_4 -> V_11 [ 1 ] , V_4 -> V_11 [ 2 ] , V_4 -> V_11 [ 3 ] ,
V_4 -> V_11 [ 4 ] , V_4 -> V_11 [ 5 ] , V_4 -> V_11 [ 6 ] , V_4 -> V_11 [ 7 ] ) ;
}
static void F_5 ( T_3 * V_12 , T_4 V_13 , T_1 * V_14 )
{
switch ( V_13 ) {
case 8 :
* V_14 = * ( T_3 * ) V_12 ;
break;
case 16 :
* V_14 = * ( V_15 * ) V_12 ;
break;
case 32 :
* V_14 = * ( T_4 * ) V_12 ;
break;
case 64 :
* V_14 = * ( T_1 * ) V_12 ;
break;
}
}
static void F_6 ( T_3 * V_12 , T_4 V_13 , T_1 * V_14 )
{
switch ( V_13 ) {
case 8 :
* ( T_3 * ) V_12 = * V_14 ;
break;
case 16 :
* ( V_15 * ) V_12 = * V_14 ;
break;
case 32 :
* ( T_4 * ) V_12 = * V_14 ;
break;
case 64 :
* ( T_1 * ) V_12 = * V_14 ;
break;
}
}
static T_5 F_7 ( T_4 V_16 , T_6 V_1 ,
T_4 V_13 , T_1 * V_14 , void * V_17 ,
void * V_18 )
{
struct V_3 * V_19 = V_17 ;
T_3 * V_12 = ( T_3 * ) V_19 + V_1 ;
if ( V_13 != 8 && V_13 != 16 &&
V_13 != 32 && V_13 != 64 )
return V_20 ;
if ( V_1 + ( V_13 >> 3 ) > sizeof( struct V_3 ) )
return V_20 ;
switch ( V_16 ) {
case V_21 :
if ( V_1 == F_8 ( struct V_3 , V_10 ) )
F_3 ( V_19 ) ;
F_5 ( V_12 , V_13 , V_14 ) ;
break;
case V_22 :
F_6 ( V_12 , V_13 , V_14 ) ;
break;
}
return V_23 ;
}
static int F_9 ( void )
{
T_5 V_24 ;
if ( V_25 )
return 0 ;
V_24 = F_10 ( V_26 ,
V_27 , F_7 , NULL , & V_28 ) ;
if ( F_11 ( V_24 ) )
return - V_29 ;
V_25 = 1 ;
F_12 ( V_30 L_1 ,
V_27 ) ;
return 0 ;
}
static int F_13 ( void )
{
T_5 V_24 ;
if ( ! V_25 )
return 0 ;
V_24 = F_14 ( V_26 ,
V_27 , F_7 ) ;
if ( F_11 ( V_24 ) )
return - V_29 ;
V_25 = 0 ;
F_12 ( V_30 L_2 ,
V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_31 * V_32 )
{
return F_9 () ;
}
static int F_16 ( struct V_31 * V_32 )
{
return F_13 () ;
}
static int T_7 F_17 ( void )
{
int V_33 ;
if ( V_34 )
F_9 () ;
V_33 = F_18 ( & V_35 ) ;
if ( V_33 < 0 ) {
F_13 () ;
return V_33 ;
}
return 0 ;
}
static void T_8 F_19 ( void )
{
F_20 ( & V_35 ) ;
F_13 () ;
}
