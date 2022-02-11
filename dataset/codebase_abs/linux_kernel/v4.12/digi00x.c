static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
char V_6 [ 32 ] = { 0 } ;
char * V_7 ;
int V_8 ;
V_8 = F_3 ( V_2 -> V_5 -> V_9 , V_10 , V_6 ,
sizeof( V_6 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 = F_4 ( V_6 ) ;
strcpy ( V_2 -> V_11 -> V_12 , L_1 ) ;
strcpy ( V_2 -> V_11 -> V_13 , V_7 ) ;
strcpy ( V_2 -> V_11 -> V_14 , V_7 ) ;
snprintf ( V_2 -> V_11 -> V_15 , sizeof( V_2 -> V_11 -> V_15 ) ,
L_2 , V_7 ,
V_4 -> V_16 [ 3 ] , V_4 -> V_16 [ 4 ] ,
F_5 ( & V_2 -> V_5 -> V_17 ) , 100 << V_4 -> V_18 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_19 ) ;
}
static void F_11 ( struct V_20 * V_11 )
{
F_6 ( V_11 -> V_21 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_1 * V_2 =
F_13 ( V_23 , struct V_1 , V_24 . V_23 ) ;
int V_8 ;
if ( V_2 -> V_25 )
return;
V_8 = F_14 ( & V_2 -> V_5 -> V_17 , - 1 , NULL , V_26 , 0 ,
& V_2 -> V_11 ) ;
if ( V_8 < 0 )
return;
V_8 = F_1 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_15 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
F_16 ( V_2 ) ;
V_8 = F_17 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_18 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_19 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_20 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_21 ( V_2 -> V_11 ) ;
if ( V_8 < 0 )
goto error;
V_2 -> V_11 -> V_27 = F_11 ;
V_2 -> V_11 -> V_21 = V_2 ;
V_2 -> V_25 = true ;
return;
error:
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
F_22 ( V_2 -> V_11 ) ;
F_23 ( & V_2 -> V_5 -> V_17 ,
L_3 , V_8 ) ;
}
static int F_24 ( struct V_28 * V_5 ,
const struct V_29 * V_30 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_31 ) ;
if ( V_2 == NULL )
return - V_32 ;
V_2 -> V_5 = F_26 ( V_5 ) ;
F_27 ( & V_5 -> V_17 , V_2 ) ;
F_28 ( & V_2 -> V_19 ) ;
F_29 ( & V_2 -> V_33 ) ;
F_30 ( & V_2 -> V_34 ) ;
V_2 -> V_35 = V_30 -> V_36 == V_37 ;
F_31 ( & V_2 -> V_24 , F_12 ) ;
F_32 ( V_5 , & V_2 -> V_24 ) ;
return 0 ;
}
static void F_33 ( struct V_28 * V_5 )
{
struct V_1 * V_2 = F_34 ( & V_5 -> V_17 ) ;
if ( ! V_2 -> V_25 )
F_32 ( V_5 , & V_2 -> V_24 ) ;
F_35 ( V_2 ) ;
if ( V_2 -> V_25 ) {
F_36 ( & V_2 -> V_19 ) ;
F_37 ( V_2 ) ;
F_38 ( & V_2 -> V_19 ) ;
}
}
static void F_39 ( struct V_28 * V_5 )
{
struct V_1 * V_2 = F_34 ( & V_5 -> V_17 ) ;
F_40 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_25 ) {
F_41 ( V_2 -> V_11 ) ;
} else {
F_6 ( V_2 ) ;
}
}
static int T_1 F_42 ( void )
{
return F_43 ( & V_38 . V_12 ) ;
}
static void T_2 F_44 ( void )
{
F_45 ( & V_38 . V_12 ) ;
}
