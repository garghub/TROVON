static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
unsigned int V_6 = V_7 ;
T_5 * V_8 = ( T_5 * ) V_3 ;
T_4 V_9 = * V_5 ;
int V_10 = 0 ;
if ( * V_5 >= V_6 )
return 0 ;
if ( * V_5 + V_4 >= V_6 ) {
V_6 -= * V_5 ;
V_4 = V_6 ;
} else
V_6 = V_4 ;
while ( V_6 ) {
V_10 = F_2 ( * V_5 , & V_8 [ * V_5 - V_9 ] ) ;
if ( V_10 )
return V_10 ;
* V_5 += 1 ;
V_6 -- ;
}
return V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
unsigned int V_6 = V_4 ;
T_4 V_9 = * V_5 ;
T_5 * V_8 = ( T_5 * ) V_3 ;
int V_10 = 0 ;
if ( * V_5 >= V_7 )
return 0 ;
if ( * V_5 + V_4 >= V_7 ) {
V_6 = V_7 - * V_5 ;
V_4 = V_6 ;
}
while ( V_6 ) {
T_5 V_11 = V_8 [ * V_5 - V_9 ] ;
V_10 = F_4 ( * V_5 , V_11 ) ;
if ( V_10 )
return V_10 ;
* V_5 += 1 ;
V_6 -- ;
}
return V_4 ;
}
int F_5 ( struct V_12 * V_13 , unsigned int V_14 )
{
struct V_15 * V_16 ;
char V_17 [ 64 ] ;
T_6 V_18 = 0400 ;
if ( V_14 == 0 ) {
V_19 = F_6 ( L_1 , NULL ) ;
if ( ! V_19 )
return - V_20 ;
}
sprintf ( V_17 , L_2 , V_14 ) ;
V_16 = F_6 ( V_17 , V_19 ) ;
if ( ! V_16 ) {
if ( V_14 != 0 )
goto error;
return - V_20 ;
}
if ( ! F_7 ( L_3 , 0444 , V_16 , ( V_21 * ) & V_22 -> V_23 ) )
goto error;
if ( ! F_8 ( L_4 , 0444 , V_16 ,
( V_21 * ) & V_22 -> V_24 ) )
goto error;
if ( V_25 )
V_18 = 0600 ;
if ( ! F_9 ( L_5 , V_18 , V_16 , V_13 , & V_26 ) )
goto error;
return 0 ;
error:
F_10 ( V_19 ) ;
return - V_20 ;
}
static int T_7 F_11 ( void )
{
int V_10 = 0 ;
if ( V_22 )
V_10 = F_5 ( V_22 , 0 ) ;
else
V_10 = - V_27 ;
return V_10 ;
}
static void T_8 F_12 ( void )
{
F_10 ( V_19 ) ;
}
