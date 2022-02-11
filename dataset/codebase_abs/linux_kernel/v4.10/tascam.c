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
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_22 ) ;
}
static void F_11 ( struct V_23 * V_16 )
{
F_6 ( V_16 -> V_24 ) ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_26 , struct V_1 , V_27 . V_26 ) ;
int V_28 ;
V_28 = F_14 ( & V_2 -> V_5 -> V_11 , - 1 , NULL , V_29 , 0 ,
& V_2 -> V_16 ) ;
if ( V_28 < 0 )
return;
V_28 = F_1 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_15 ( V_2 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_16 ( V_2 ) ;
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
V_28 = F_21 ( V_2 -> V_16 ) ;
if ( V_28 < 0 )
goto error;
V_2 -> V_16 -> V_30 = F_11 ;
V_2 -> V_16 -> V_24 = V_2 ;
V_2 -> V_31 = true ;
return;
error:
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_22 ( V_2 -> V_16 ) ;
F_23 ( & V_2 -> V_5 -> V_11 ,
L_4 , V_28 ) ;
}
static int F_24 ( struct V_32 * V_5 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_35 ) ;
if ( V_2 == NULL )
return - V_36 ;
V_2 -> V_5 = F_26 ( V_5 ) ;
F_27 ( & V_5 -> V_11 , V_2 ) ;
F_28 ( & V_2 -> V_22 ) ;
F_29 ( & V_2 -> V_37 ) ;
F_30 ( & V_2 -> V_38 ) ;
F_31 ( & V_2 -> V_27 , F_12 ) ;
F_32 ( V_5 , & V_2 -> V_27 ) ;
return 0 ;
}
static void F_33 ( struct V_32 * V_5 )
{
struct V_1 * V_2 = F_34 ( & V_5 -> V_11 ) ;
if ( ! V_2 -> V_31 )
F_32 ( V_5 , & V_2 -> V_27 ) ;
F_35 ( V_2 ) ;
if ( V_2 -> V_31 ) {
F_36 ( & V_2 -> V_22 ) ;
F_37 ( V_2 ) ;
F_38 ( & V_2 -> V_22 ) ;
}
}
static void F_39 ( struct V_32 * V_5 )
{
struct V_1 * V_2 = F_34 ( & V_5 -> V_11 ) ;
F_40 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_31 ) {
F_41 ( V_2 -> V_16 ) ;
} else {
F_6 ( V_2 ) ;
}
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_39 . V_17 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_39 . V_17 ) ;
}
