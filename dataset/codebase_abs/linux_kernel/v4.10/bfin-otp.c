static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_1 V_5 ;
T_5 V_6 , V_7 , V_8 ;
T_6 V_9 ;
F_2 () ;
if ( V_3 % sizeof( T_6 ) )
return - V_10 ;
if ( F_3 ( & V_11 ) )
return - V_12 ;
V_5 = 0 ;
V_6 = * V_4 / ( sizeof( T_6 ) * 2 ) ;
while ( V_5 < V_3 ) {
V_7 = ( * V_4 % ( sizeof( T_6 ) * 2 ) ? V_13 : V_14 ) ;
F_4 ( L_1 , V_6 , V_7 ,
( V_7 & V_13 ? L_2 : L_3 ) ) ;
V_8 = F_5 ( V_6 , V_7 , & V_9 ) ;
if ( V_8 & V_15 ) {
F_4 ( L_4 , V_8 ) ;
V_5 = - V_16 ;
break;
}
if ( F_6 ( V_2 + V_5 , & V_9 , sizeof( V_9 ) ) ) {
V_5 = - V_17 ;
break;
}
if ( V_7 & V_13 )
++ V_6 ;
V_5 += sizeof( V_9 ) ;
* V_4 += sizeof( V_9 ) ;
}
F_7 ( & V_11 ) ;
return V_5 ;
}
static T_5 F_8 ( void )
{
T_5 V_18 , V_19 , V_20 , V_21 ;
V_18 = F_9 () / 1000000 ;
V_19 = ( 2 * F_9 () / 10000000 ) << 8 ;
V_20 = ( 0x1401 ) << 15 ;
V_21 = V_18 | V_19 | V_20 ;
if ( F_10 ( V_22 , V_21 ) )
return 0 ;
return V_21 ;
}
static void F_11 ( T_5 V_21 )
{
F_10 ( V_23 , 0 ) ;
F_10 ( V_22 , V_21 & ~ ( - 1 << 15 ) ) ;
F_10 ( V_23 , 0 ) ;
}
static T_1 F_12 ( struct V_1 * V_24 , const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
T_1 V_5 ;
T_5 V_21 , V_6 , V_25 , V_7 , V_8 ;
T_6 V_9 ;
if ( ! V_26 )
return - V_27 ;
if ( V_3 % sizeof( T_6 ) )
return - V_10 ;
if ( F_3 ( & V_11 ) )
return - V_12 ;
F_2 () ;
V_21 = F_8 () ;
if ( V_21 == 0 ) {
F_7 ( & V_11 ) ;
return - V_16 ;
}
V_25 = V_28 ;
V_5 = 0 ;
V_6 = * V_4 / ( sizeof( T_6 ) * 2 ) ;
while ( V_5 < V_3 ) {
V_7 = V_25 | ( * V_4 % ( sizeof( T_6 ) * 2 ) ? V_13 : V_14 ) ;
F_4 ( L_5 , V_6 , V_7 ,
( V_7 & V_13 ? L_2 : L_3 ) , V_2 + V_5 ) ;
if ( F_13 ( & V_9 , V_2 + V_5 , sizeof( V_9 ) ) ) {
V_5 = - V_17 ;
break;
}
V_8 = F_14 ( V_6 , V_7 , & V_9 ) ;
if ( V_8 & V_15 ) {
F_4 ( L_4 , V_8 ) ;
V_5 = - V_16 ;
break;
}
if ( V_7 & V_13 )
++ V_6 ;
V_5 += sizeof( V_9 ) ;
* V_4 += sizeof( V_9 ) ;
}
F_11 ( V_21 ) ;
F_7 ( & V_11 ) ;
return V_5 ;
}
static long F_15 ( struct V_1 * V_24 , unsigned V_29 , unsigned long V_30 )
{
F_2 () ;
switch ( V_29 ) {
case V_31 : {
T_5 V_21 ;
int V_8 = - V_16 ;
if ( ! V_26 )
return - V_27 ;
if ( F_3 ( & V_11 ) )
return - V_12 ;
V_21 = F_8 () ;
if ( V_21 ) {
T_5 V_32 = F_14 ( V_30 , V_33 , NULL ) ;
F_4 ( L_6 , V_30 , V_32 ) ;
if ( ! ( V_32 & V_15 ) )
V_8 = 0 ;
F_11 ( V_21 ) ;
}
F_7 ( & V_11 ) ;
return V_8 ;
}
case V_34 :
V_26 = false ;
return 0 ;
case V_35 :
V_26 = true ;
return 0 ;
}
return - V_36 ;
}
