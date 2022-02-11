static bool F_1 ( struct V_1 * V_2 )
{
const char * const V_3 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 } ;
char V_4 [ 32 ] ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return false ;
for ( V_5 = 0 ; V_5 < F_3 ( V_3 ) ; V_5 ++ ) {
if ( strcmp ( V_3 [ V_5 ] , V_4 ) == 0 )
break;
}
return ( V_5 < F_3 ( V_3 ) ) ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 -> V_2 ) ;
char V_13 [ 24 ] ;
char V_4 [ 32 ] ;
const char * V_14 , * V_15 , * V_16 ;
T_1 V_17 ;
int V_6 ;
V_6 = F_2 ( V_12 -> V_18 + 5 , V_19 ,
V_13 , sizeof( V_13 ) ) ;
if ( V_6 < 0 )
goto V_20;
V_6 = F_2 ( V_10 -> V_2 -> V_7 , V_8 ,
V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
goto V_20;
V_6 = F_6 ( V_10 -> V_2 , V_21 ,
V_22 , & V_17 , 4 , 0 ) ;
if ( V_6 < 0 )
goto V_20;
F_7 ( & V_17 ) ;
if ( V_10 -> V_23 ) {
V_14 = V_10 -> V_23 -> V_24 ;
V_15 = V_10 -> V_23 -> V_25 ;
V_16 = V_10 -> V_23 -> V_26 ;
} else {
V_14 = L_7 ;
V_15 = V_13 ;
V_16 = V_4 ;
}
strcpy ( V_10 -> V_27 -> V_28 , V_14 ) ;
strcpy ( V_10 -> V_27 -> V_29 , V_16 ) ;
strcpy ( V_10 -> V_27 -> V_30 , V_16 ) ;
snprintf ( V_10 -> V_27 -> V_31 , sizeof( V_10 -> V_27 -> V_31 ) ,
L_8 ,
V_15 , V_16 , V_17 >> 20 , V_17 & 0xffff ,
V_12 -> V_18 [ 3 ] , V_12 -> V_18 [ 4 ] ,
F_8 ( & V_10 -> V_2 -> V_32 ) , 100 << V_12 -> V_33 ) ;
V_20:
return V_6 ;
}
static void F_9 ( struct V_34 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_35 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_36 ; V_5 ++ ) {
F_10 ( V_10 -> V_37 [ V_5 ] ) ;
F_10 ( V_10 -> V_38 [ V_5 ] ) ;
}
F_11 ( & V_10 -> V_39 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
struct V_34 * V_27 ;
struct V_9 * V_10 ;
int V_6 ;
if ( ( V_41 -> V_42 == V_43 ) && ! F_1 ( V_2 ) )
return - V_44 ;
V_6 = F_13 ( & V_2 -> V_32 , - 1 , NULL , V_45 ,
sizeof( * V_10 ) , & V_27 ) ;
if ( V_6 < 0 )
return V_6 ;
V_27 -> V_46 = F_9 ;
V_10 = V_27 -> V_35 ;
V_10 -> V_27 = V_27 ;
F_14 ( & V_10 -> V_39 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_23 = ( const struct V_23 * ) V_41 -> V_47 ;
F_15 ( & V_10 -> V_48 ) ;
F_16 ( & V_10 -> V_49 ) ;
V_6 = F_17 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_4 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_18 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
if ( V_10 -> V_23 ) {
V_6 = F_19 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
}
F_20 ( V_10 ) ;
V_6 = F_21 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_22 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_23 ( V_10 , & V_10 -> V_50 ) ;
if ( V_6 < 0 )
goto error;
if ( V_10 -> V_51 ) {
V_6 = F_23 ( V_10 , & V_10 -> V_52 ) ;
if ( V_6 < 0 )
goto error;
}
V_6 = F_24 ( V_27 ) ;
if ( V_6 < 0 ) {
F_25 ( V_10 , & V_10 -> V_50 ) ;
if ( V_10 -> V_51 )
F_25 ( V_10 , & V_10 -> V_52 ) ;
goto error;
}
F_26 ( & V_2 -> V_32 , V_10 ) ;
return 0 ;
error:
F_27 ( V_27 ) ;
return V_6 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_29 ( & V_2 -> V_32 ) ;
F_30 ( V_10 -> V_2 ) ;
F_31 ( & V_10 -> V_39 ) ;
F_32 ( V_10 , & V_10 -> V_50 ) ;
if ( V_10 -> V_51 )
F_32 ( V_10 , & V_10 -> V_52 ) ;
F_33 ( & V_10 -> V_39 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_29 ( & V_2 -> V_32 ) ;
F_35 ( V_10 -> V_27 ) ;
F_25 ( V_10 , & V_10 -> V_50 ) ;
if ( V_10 -> V_51 )
F_25 ( V_10 , & V_10 -> V_52 ) ;
F_36 ( V_10 -> V_27 ) ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_53 . V_28 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_53 . V_28 ) ;
}
