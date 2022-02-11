static void T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 ;
int V_6 = V_3 ;
T_2 V_7 ;
if ( ! V_5 -> V_8 )
return;
while ( V_6 > sizeof( struct V_1 ) ) {
if ( F_2 ( V_5 ) ) {
F_3 ( V_9 L_1 ) ;
return;
}
V_7 = F_4 ( V_5 ) ;
if ( V_6 < V_7 ) {
F_3 ( V_9 L_2 ,
V_7 ) ;
return;
}
F_5 ( L_3 ) ;
F_6 (KERN_INFO HW_ERR, estatus) ;
V_5 -> V_8 = 0 ;
V_5 = ( void * ) V_5 + V_7 ;
if ( ! V_5 -> V_8 )
return;
V_6 -= V_7 ;
}
}
static int T_1 F_7 ( char * V_10 )
{
V_11 = 1 ;
return 0 ;
}
static int T_1 F_8 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 . V_15 < sizeof( struct V_12 ) ||
V_13 -> V_16 < sizeof( struct V_1 ) )
return - V_17 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
struct V_1 * V_18 ;
struct V_12 * V_13 ;
unsigned int V_3 ;
T_3 V_19 ;
int V_20 = 0 ;
if ( V_21 )
return 0 ;
if ( V_11 ) {
F_10 ( L_4 ) ;
return 0 ;
}
V_19 = F_11 ( V_22 , 0 , (struct V_23 * * ) & V_13 ) ;
if ( V_19 == V_24 )
return 0 ;
if ( F_12 ( V_19 ) ) {
F_3 ( L_5 , F_13 ( V_19 ) ) ;
return - V_17 ;
}
V_20 = F_8 ( V_13 ) ;
if ( V_20 ) {
F_3 ( V_9 L_6 ) ;
return V_20 ;
}
V_3 = V_13 -> V_16 ;
if ( ! F_14 ( V_13 -> V_25 , V_3 , L_7 ) ) {
F_3 ( L_8 ,
( unsigned long long ) V_13 -> V_25 ,
( unsigned long long ) V_13 -> V_25 + V_3 - 1 ) ;
return - V_26 ;
}
V_18 = F_15 ( V_13 -> V_25 , V_3 ) ;
if ( V_18 ) {
F_1 ( V_18 , V_3 ) ;
F_16 ( V_18 ) ;
} else {
V_20 = - V_27 ;
}
F_17 ( V_13 -> V_25 , V_3 ) ;
return V_20 ;
}
