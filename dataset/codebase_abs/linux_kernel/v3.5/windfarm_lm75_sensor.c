static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 -> V_7 == NULL )
return - V_8 ;
if ( ! V_5 -> V_9 ) {
T_2 V_10 , V_11 = ( T_2 ) F_3 ( V_5 -> V_7 , 1 ) ;
F_4 ( L_1 ,
V_2 -> V_12 , V_11 ) ;
V_10 = V_11 & ~ 0x01 ;
F_5 ( V_5 -> V_7 , 1 , V_10 ) ;
V_5 -> V_9 = 1 ;
F_6 ( 200 ) ;
}
V_6 = ( T_1 ) F_7 ( F_8 ( V_5 -> V_7 , 0 ) ) ;
V_6 <<= 8 ;
* V_3 = V_6 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( V_5 ) ;
}
static int F_11 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
struct V_4 * V_5 ;
int V_17 , V_18 = V_16 -> V_19 ;
const char * V_12 , * V_20 ;
F_4 ( L_2 ,
V_18 ? L_3 : L_4 , V_14 -> V_21 ) ;
V_20 = F_12 ( V_14 -> V_22 . V_23 , L_5 , NULL ) ;
if ( ! V_20 ) {
F_13 ( & V_14 -> V_22 , L_6 ) ;
return - V_24 ;
}
if ( ! strcmp ( V_20 , L_7 ) || ! strcmp ( V_20 , L_8 ) )
V_12 = L_9 ;
else if ( ! strcmp ( V_20 , L_10 ) )
V_12 = L_11 ;
else if ( ! strcmp ( V_20 , L_12 ) )
V_12 = L_13 ;
else if ( ! strcmp ( V_20 , L_14 ) )
V_12 = L_15 ;
else if ( ! strcmp ( V_20 , L_16 ) )
V_12 = L_17 ;
else if ( ! strcmp ( V_20 , L_18 ) )
V_12 = L_19 ;
else if ( ! strcmp ( V_20 , L_20 ) )
V_12 = L_21 ;
else
return - V_24 ;
V_5 = F_14 ( sizeof( struct V_4 ) , V_25 ) ;
if ( V_5 == NULL )
return - V_8 ;
V_5 -> V_9 = 0 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_7 = V_14 ;
V_5 -> V_26 . V_12 = ( char * ) V_12 ;
V_5 -> V_26 . V_27 = & V_28 ;
F_15 ( V_14 , V_5 ) ;
V_17 = F_16 ( & V_5 -> V_26 ) ;
if ( V_17 )
F_10 ( V_5 ) ;
return V_17 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = F_18 ( V_14 ) ;
F_4 ( L_22 , V_5 -> V_26 . V_12 ) ;
V_5 -> V_7 = NULL ;
F_19 ( & V_5 -> V_26 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_29 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_29 ) ;
}
