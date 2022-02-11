static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
const T_1 * V_6 = V_4 -> V_6 ;
char V_7 [ 9 ] ;
unsigned int V_8 ;
T_2 V_9 ;
if ( V_4 -> V_10 < 30 ) {
F_3 ( & V_2 -> V_5 -> V_11 ,
L_1 ) ;
return - V_12 ;
}
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_9 = V_6 [ 28 + V_8 / 4 ] >> ( 24 - 8 * ( V_8 % 4 ) ) ;
if ( V_9 == '\0' )
break;
V_7 [ V_8 ] = V_9 ;
}
V_7 [ V_8 ] = '\0' ;
for ( V_8 = 0 ; V_8 < F_4 ( V_13 ) ; V_8 ++ ) {
if ( strcmp ( V_7 , V_13 [ V_8 ] . V_14 ) == 0 ) {
V_2 -> V_15 = & V_13 [ V_8 ] ;
break;
}
}
if ( V_2 -> V_15 == NULL )
return - V_12 ;
strcpy ( V_2 -> V_16 -> V_17 , L_2 ) ;
strcpy ( V_2 -> V_16 -> V_18 , V_7 ) ;
strcpy ( V_2 -> V_16 -> V_19 , V_7 ) ;
snprintf ( V_2 -> V_16 -> V_20 , sizeof( V_2 -> V_16 -> V_20 ) ,
L_3 , V_7 ,
V_4 -> V_6 [ 3 ] , V_4 -> V_6 [ 4 ] ,
F_5 ( & V_2 -> V_5 -> V_11 ) , 100 << V_4 -> V_21 ) ;
return 0 ;
}
static void F_6 ( struct V_22 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_23 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_24 ) ;
}
static int F_11 ( struct V_25 * V_5 ,
const struct V_26 * V_27 )
{
struct V_22 * V_16 ;
struct V_1 * V_2 ;
int V_28 ;
V_28 = F_12 ( & V_5 -> V_11 , - 1 , NULL , V_29 ,
sizeof( struct V_1 ) , & V_16 ) ;
if ( V_28 < 0 )
return V_28 ;
V_16 -> V_30 = F_6 ;
V_2 = V_16 -> V_23 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_5 = F_13 ( V_5 ) ;
F_14 ( & V_2 -> V_24 ) ;
F_15 ( & V_2 -> V_31 ) ;
F_16 ( & V_2 -> V_32 ) ;
V_28 = F_1 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
F_17 ( V_2 ) ;
V_28 = F_18 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_19 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_20 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_21 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_22 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_23 ( V_16 ) ;
if ( V_28 < 0 )
goto error;
F_24 ( & V_5 -> V_11 , V_2 ) ;
return V_28 ;
error:
F_25 ( V_16 ) ;
return V_28 ;
}
static void F_26 ( struct V_25 * V_5 )
{
struct V_1 * V_2 = F_27 ( & V_5 -> V_11 ) ;
F_28 ( V_2 ) ;
F_29 ( & V_2 -> V_24 ) ;
F_30 ( V_2 ) ;
F_31 ( & V_2 -> V_24 ) ;
}
static void F_32 ( struct V_25 * V_5 )
{
struct V_1 * V_2 = F_27 ( & V_5 -> V_11 ) ;
F_33 ( V_2 -> V_16 ) ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_33 . V_17 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_33 . V_17 ) ;
}
