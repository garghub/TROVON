static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
unsigned int V_6 = V_7 ;
T_4 V_8 = * V_5 ;
int V_9 = 0 ;
if ( * V_5 >= V_6 )
return 0 ;
if ( * V_5 + V_4 >= V_6 ) {
V_6 -= * V_5 ;
V_4 = V_6 ;
} else
V_6 = V_4 ;
while ( V_6 ) {
T_5 V_10 ;
V_9 = F_2 ( * V_5 , & V_10 ) ;
if ( V_9 )
return V_9 ;
if ( F_3 ( V_10 , V_3 + * V_5 - V_8 ) ) {
if ( * V_5 - V_8 )
return * V_5 - V_8 ;
return - V_11 ;
}
* V_5 += 1 ;
V_6 -- ;
}
return V_4 ;
}
static T_1 F_4 ( struct V_1 * V_2 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
unsigned int V_6 = V_4 ;
T_4 V_8 = * V_5 ;
int V_9 = 0 ;
if ( * V_5 >= V_7 )
return 0 ;
if ( * V_5 + V_4 >= V_7 ) {
V_6 = V_7 - * V_5 ;
V_4 = V_6 ;
}
while ( V_6 ) {
T_5 V_12 ;
if ( F_5 ( V_12 , V_3 + * V_5 - V_8 ) ) {
if ( * V_5 - V_8 )
return * V_5 - V_8 ;
return - V_11 ;
}
V_9 = F_6 ( * V_5 , V_12 ) ;
if ( V_9 )
return V_9 ;
* V_5 += 1 ;
V_6 -- ;
}
return V_4 ;
}
static int F_7 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_16 * V_17 ;
char V_18 [ 64 ] ;
T_6 V_19 = 0400 ;
if ( V_15 == 0 ) {
V_20 = F_8 ( L_1 , NULL ) ;
if ( ! V_20 )
return - V_21 ;
}
sprintf ( V_18 , L_2 , V_15 ) ;
V_17 = F_8 ( V_18 , V_20 ) ;
if ( ! V_17 ) {
if ( V_15 != 0 )
goto error;
return - V_21 ;
}
if ( ! F_9 ( L_3 , 0444 , V_17 , ( V_22 * ) & V_23 -> V_24 ) )
goto error;
if ( ! F_10 ( L_4 , 0444 , V_17 ,
& V_23 -> V_25 ) )
goto error;
if ( V_26 )
V_19 = 0600 ;
if ( ! F_11 ( L_5 , V_19 , V_17 , V_14 , & V_27 ) )
goto error;
return 0 ;
error:
F_12 ( V_20 ) ;
return - V_21 ;
}
static int T_7 F_13 ( void )
{
int V_9 = 0 ;
if ( V_23 )
V_9 = F_7 ( V_23 , 0 ) ;
else
V_9 = - V_28 ;
return V_9 ;
}
static void T_8 F_14 ( void )
{
F_12 ( V_20 ) ;
}
