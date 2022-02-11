static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 , V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_12 * V_9 = V_11 -> V_9 ;
unsigned char * V_13 = V_2 -> V_14 -> V_15 ;
V_3 = ~ V_13 [ 8 ] ;
V_4 = * ( unsigned short * ) ( V_13 + 12 ) - 512 ;
V_5 = * ( unsigned short * ) ( V_13 + 14 ) - 512 ;
V_6 = * ( unsigned short * ) ( V_13 + 16 ) - 512 ;
F_3 ( V_9 , V_16 , V_3 & 4 ) ;
F_3 ( V_9 , V_17 , V_3 & 9 ) ;
F_3 ( V_9 , V_18 , V_3 & 2 ) ;
F_4 ( V_9 , V_19 , V_4 ) ;
F_4 ( V_9 , V_20 , V_5 ) ;
F_4 ( V_9 , V_21 , V_6 ) ;
F_5 ( V_9 ) ;
}
static int F_6 ( struct V_12 * V_9 )
{
struct V_10 * V_11 = F_2 ( F_7 ( & V_9 -> V_9 ) ) ;
F_8 ( V_11 -> V_22 , F_1 , V_23 / 50 ,
V_24 ) ;
return 0 ;
}
static void F_9 ( struct V_12 * V_9 )
{
struct V_10 * V_11 = F_2 ( F_7 ( & V_9 -> V_9 ) ) ;
F_8 ( V_11 -> V_22 , F_1 , 0 ,
V_24 ) ;
}
static int F_10 ( struct V_25 * V_9 )
{
struct V_7 * V_22 = F_7 ( V_9 ) ;
struct V_26 * V_27 = F_11 ( V_9 -> V_28 ) ;
int error ;
struct V_12 * V_12 ;
struct V_10 * V_11 ;
V_11 = F_12 ( sizeof( struct V_10 ) , V_29 ) ;
if ( ! V_11 ) {
error = - V_30 ;
goto V_31;
}
V_12 = F_13 () ;
if ( ! V_12 ) {
error = - V_30 ;
goto V_32;
}
V_11 -> V_9 = V_12 ;
V_11 -> V_22 = V_22 ;
V_12 -> V_33 [ 0 ] = F_14 ( V_34 ) | F_14 ( V_35 ) ;
V_12 -> V_36 [ F_15 ( V_37 ) ] = F_14 ( V_16 ) |
F_14 ( V_18 ) | F_14 ( V_17 ) ;
V_12 -> V_38 [ 0 ] = F_14 ( V_19 ) | F_14 ( V_20 ) |
F_14 ( V_21 ) ;
V_12 -> V_39 = F_6 ;
V_12 -> V_40 = F_9 ;
V_12 -> V_41 = V_22 -> V_42 ;
V_12 -> V_43 . V_44 = V_45 ;
error = F_16 ( V_12 ) ;
if ( error )
goto V_46;
V_22 -> V_28 = V_27 ;
F_17 ( V_22 , V_11 ) ;
return error ;
V_46:
F_18 ( V_12 ) ;
V_32:
F_19 ( V_11 ) ;
V_31:
return error ;
}
static int F_20 ( struct V_25 * V_9 )
{
struct V_7 * V_22 = F_7 ( V_9 ) ;
struct V_10 * V_11 = F_2 ( V_22 ) ;
V_22 -> V_47 = NULL ;
F_21 ( V_11 -> V_9 ) ;
F_17 ( V_22 , NULL ) ;
F_19 ( V_11 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_48 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_48 ) ;
}
