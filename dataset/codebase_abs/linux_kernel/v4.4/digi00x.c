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
static void F_6 ( struct V_19 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_20 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_21 ) ;
}
static int F_11 ( struct V_22 * V_5 ,
const struct V_23 * V_24 )
{
struct V_19 * V_11 ;
struct V_1 * V_2 ;
int V_8 ;
V_8 = F_12 ( & V_5 -> V_17 , - 1 , NULL , V_25 ,
sizeof( struct V_1 ) , & V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_11 -> V_26 = F_6 ;
V_2 = V_11 -> V_20 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_5 = F_13 ( V_5 ) ;
F_14 ( & V_2 -> V_21 ) ;
F_15 ( & V_2 -> V_27 ) ;
F_16 ( & V_2 -> V_28 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_17 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
F_18 ( V_2 ) ;
V_8 = F_19 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_20 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_21 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_22 ( V_2 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_23 ( V_11 ) ;
if ( V_8 < 0 )
goto error;
F_24 ( & V_5 -> V_17 , V_2 ) ;
return V_8 ;
error:
F_25 ( V_11 ) ;
return V_8 ;
}
static void F_26 ( struct V_22 * V_5 )
{
struct V_1 * V_2 = F_27 ( & V_5 -> V_17 ) ;
F_28 ( V_2 ) ;
F_29 ( & V_2 -> V_21 ) ;
F_30 ( V_2 ) ;
F_31 ( & V_2 -> V_21 ) ;
}
static void F_32 ( struct V_22 * V_5 )
{
struct V_1 * V_2 = F_27 ( & V_5 -> V_17 ) ;
F_33 ( V_2 -> V_11 ) ;
}
static int T_1 F_34 ( void )
{
return F_35 ( & V_29 . V_12 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_29 . V_12 ) ;
}
