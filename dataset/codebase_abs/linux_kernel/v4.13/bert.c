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
struct V_18 V_19 ;
struct V_1 * V_20 ;
struct V_12 * V_13 ;
unsigned int V_3 ;
T_3 V_21 ;
int V_22 = 0 ;
if ( V_23 )
return 0 ;
if ( V_11 ) {
F_10 ( L_4 ) ;
return 0 ;
}
V_21 = F_11 ( V_24 , 0 , (struct V_25 * * ) & V_13 ) ;
if ( V_21 == V_26 )
return 0 ;
if ( F_12 ( V_21 ) ) {
F_3 ( L_5 , F_13 ( V_21 ) ) ;
return - V_17 ;
}
V_22 = F_8 ( V_13 ) ;
if ( V_22 ) {
F_3 ( V_9 L_6 ) ;
return V_22 ;
}
V_3 = V_13 -> V_16 ;
F_14 ( & V_19 ) ;
V_22 = F_15 ( & V_19 , V_13 -> V_27 ,
V_3 , true ) ;
if ( V_22 )
return V_22 ;
V_22 = F_16 ( & V_19 , L_7 ) ;
if ( V_22 )
goto V_28;
V_20 = F_17 ( V_13 -> V_27 , V_3 ) ;
if ( V_20 ) {
F_1 ( V_20 , V_3 ) ;
F_18 ( V_20 ) ;
} else {
V_22 = - V_29 ;
}
F_19 ( & V_19 ) ;
V_28:
F_20 ( & V_19 ) ;
return V_22 ;
}
