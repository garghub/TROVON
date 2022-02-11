static int F_1 ( T_1 V_1 )
{
if ( V_1 < 0x10000000 || V_1 > 0x14000000 )
return - V_2 ;
return 0 ;
}
static struct V_3 * F_2 ( void )
{
struct V_3 * * V_4 , * V_5 ;
V_4 = (struct V_3 * * ) 0x13fffffc ;
if ( F_1 ( ( T_1 ) V_4 ) ) {
printf ( L_1 , ( T_1 ) V_4 ) ;
V_5 = NULL ;
goto V_6;
}
V_5 = * V_4 ;
if ( F_1 ( ( T_1 ) V_5 ) ) {
printf ( L_2 , ( T_1 ) V_5 ) ;
V_5 = NULL ;
goto V_6;
}
if ( memcmp ( V_5 -> V_7 , L_3 , 3 ) ) {
printf ( L_4 ) ;
V_5 = NULL ;
goto V_6;
}
V_6:
return V_5 ;
}
static int F_3 ( T_1 * V_8 )
{
struct V_3 * V_5 ;
int error ;
V_5 = F_2 () ;
if ( ! V_5 ) {
error = - 1 ;
goto V_6;
}
if ( F_1 ( V_5 -> V_8 ) ) {
printf ( L_5 ,
V_5 -> V_8 ) ;
error = - V_2 ;
goto V_6;
}
* V_8 = V_5 -> V_8 ;
error = 0 ;
V_6:
return error ;
}
static void F_4 ( void )
{
void * V_9 ;
T_1 V_10 [ 4 ] ;
T_1 V_8 ;
int V_11 ;
int error ;
V_9 = F_5 ( L_6 ) ;
if ( ! V_9 )
F_6 ( L_7 ) ;
V_11 = F_7 ( V_9 , L_8 , V_10 , sizeof( V_10 ) ) ;
if ( V_11 != sizeof( V_10 ) ) {
goto V_6;
}
error = F_3 ( & V_8 ) ;
if ( error ) {
V_8 = V_12 - V_13 ;
}
if ( V_8 > V_10 [ 2 ] && V_8 < V_10 [ 2 ] + V_10 [ 3 ] ) {
V_10 [ 3 ] = V_8 - V_10 [ 2 ] ;
printf ( L_9 , V_10 [ 2 ] + V_10 [ 3 ] ) ;
F_8 ( V_9 , L_8 , V_10 , sizeof( V_10 ) ) ;
}
V_6:
return;
}
void F_9 ( unsigned long V_14 , unsigned long V_15 , unsigned long V_16 )
{
T_1 V_17 = 24 * 1024 * 1024 - ( T_1 ) V_18 ;
F_10 ( V_18 , V_17 , 32 , 64 ) ;
F_11 ( V_19 ) ;
F_12 ( V_20 , F_13 ( V_20 ) | V_21 ) ;
if ( F_14 () )
V_22 . V_23 = V_24 ;
V_25 . V_26 = F_4 ;
}
