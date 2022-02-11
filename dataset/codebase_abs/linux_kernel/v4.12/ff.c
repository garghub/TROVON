static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
strcpy ( V_2 -> V_6 -> V_7 , L_1 ) ;
strcpy ( V_2 -> V_6 -> V_8 , V_2 -> V_9 -> V_10 ) ;
strcpy ( V_2 -> V_6 -> V_11 , V_2 -> V_9 -> V_10 ) ;
snprintf ( V_2 -> V_6 -> V_12 , sizeof( V_2 -> V_6 -> V_12 ) ,
L_2 , V_2 -> V_9 -> V_10 ,
V_4 -> V_13 [ 3 ] , V_4 -> V_13 [ 4 ] ,
F_3 ( & V_2 -> V_5 -> V_14 ) , 100 << V_4 -> V_15 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_5 ) ;
F_8 ( & V_2 -> V_16 ) ;
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_17 * V_6 )
{
F_4 ( V_6 -> V_18 ) ;
}
static void F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_12 ( V_20 , struct V_1 , V_21 . V_20 ) ;
int V_22 ;
if ( V_2 -> V_23 )
return;
V_22 = F_13 ( & V_2 -> V_5 -> V_14 , - 1 , NULL , V_24 , 0 ,
& V_2 -> V_6 ) ;
if ( V_22 < 0 )
return;
V_22 = F_14 ( V_2 ) ;
if ( V_22 < 0 )
goto error;
F_1 ( V_2 ) ;
V_22 = F_15 ( V_2 ) ;
if ( V_22 < 0 )
goto error;
F_16 ( V_2 ) ;
V_22 = F_17 ( V_2 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_18 ( V_2 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_19 ( V_2 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_20 ( V_2 -> V_6 ) ;
if ( V_22 < 0 )
goto error;
V_2 -> V_6 -> V_25 = F_10 ;
V_2 -> V_6 -> V_18 = V_2 ;
V_2 -> V_23 = true ;
return;
error:
F_6 ( V_2 ) ;
F_5 ( V_2 ) ;
F_21 ( V_2 -> V_6 ) ;
F_22 ( & V_2 -> V_5 -> V_14 ,
L_3 , V_22 ) ;
}
static int F_23 ( struct V_26 * V_5 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_29 ) ;
if ( V_2 == NULL )
return - V_30 ;
V_2 -> V_5 = F_25 ( V_5 ) ;
F_26 ( & V_5 -> V_14 , V_2 ) ;
F_27 ( & V_2 -> V_16 ) ;
F_28 ( & V_2 -> V_31 ) ;
F_29 ( & V_2 -> V_32 ) ;
V_2 -> V_9 = ( const struct V_33 * ) V_28 -> V_34 ;
F_30 ( & V_2 -> V_21 , F_11 ) ;
F_31 ( V_5 , & V_2 -> V_21 ) ;
return 0 ;
}
static void F_32 ( struct V_26 * V_5 )
{
struct V_1 * V_2 = F_33 ( & V_5 -> V_14 ) ;
if ( ! V_2 -> V_23 )
F_31 ( V_5 , & V_2 -> V_21 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_23 )
F_35 ( V_2 ) ;
}
static void F_36 ( struct V_26 * V_5 )
{
struct V_1 * V_2 = F_33 ( & V_5 -> V_14 ) ;
F_37 ( & V_2 -> V_21 . V_20 ) ;
if ( V_2 -> V_23 ) {
F_38 ( V_2 -> V_6 ) ;
} else {
F_4 ( V_2 ) ;
}
}
static int T_1 F_39 ( void )
{
return F_40 ( & V_35 . V_7 ) ;
}
static void T_2 F_41 ( void )
{
F_42 ( & V_35 . V_7 ) ;
}
