static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 -> V_6 ;
return 0 ;
}
static T_1 F_2 ( struct V_3 * V_4 , char T_2 * V_7 ,
T_3 V_8 , T_4 * V_9 )
{
unsigned int V_10 = V_11 ;
T_5 * V_12 = ( T_5 * ) V_7 ;
T_4 V_13 = * V_9 ;
int V_14 = 0 ;
if ( * V_9 >= V_10 )
return 0 ;
if ( * V_9 + V_8 >= V_10 ) {
V_10 -= * V_9 ;
V_8 = V_10 ;
} else
V_10 = V_8 ;
while ( V_10 ) {
V_14 = F_3 ( * V_9 , & V_12 [ * V_9 - V_13 ] ) ;
if ( V_14 )
return V_14 ;
* V_9 += 1 ;
V_10 -- ;
}
return V_8 ;
}
static T_1 F_4 ( struct V_3 * V_4 , const char T_2 * V_7 ,
T_3 V_8 , T_4 * V_9 )
{
unsigned int V_10 = V_8 ;
T_4 V_13 = * V_9 ;
T_5 * V_12 = ( T_5 * ) V_7 ;
int V_14 = 0 ;
if ( * V_9 >= V_11 )
return 0 ;
if ( * V_9 + V_8 >= V_11 ) {
V_10 = V_11 - * V_9 ;
V_8 = V_10 ;
}
while ( V_10 ) {
T_5 V_15 = V_12 [ * V_9 - V_13 ] ;
V_14 = F_5 ( * V_9 , V_15 ) ;
if ( V_14 )
return V_14 ;
* V_9 += 1 ;
V_10 -- ;
}
return V_8 ;
}
int F_6 ( struct V_16 * V_17 , unsigned int V_18 )
{
struct V_19 * V_20 ;
char V_21 [ 64 ] ;
T_6 V_22 = 0400 ;
if ( V_18 == 0 ) {
V_23 = F_7 ( L_1 , NULL ) ;
if ( ! V_23 )
return - V_24 ;
}
sprintf ( V_21 , L_2 , V_18 ) ;
V_20 = F_7 ( V_21 , V_23 ) ;
if ( ! V_20 ) {
if ( V_18 != 0 )
goto error;
return - V_24 ;
}
if ( ! F_8 ( L_3 , 0444 , V_20 , ( V_25 * ) & V_26 -> V_27 ) )
goto error;
if ( ! F_9 ( L_4 , 0444 , V_20 ,
( V_25 * ) & V_26 -> V_28 ) )
goto error;
if ( V_29 )
V_22 = 0600 ;
if ( ! F_10 ( L_5 , V_22 , V_20 , V_17 , & V_30 ) )
goto error;
return 0 ;
error:
F_11 ( V_23 ) ;
return - V_24 ;
}
static int T_7 F_12 ( void )
{
int V_14 = 0 ;
if ( V_26 )
V_14 = F_6 ( V_26 , 0 ) ;
else
V_14 = - V_31 ;
return V_14 ;
}
static void T_8 F_13 ( void )
{
F_11 ( V_23 ) ;
}
