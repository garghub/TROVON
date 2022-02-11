int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_2 ( V_3 , V_4 , L_1 ) )
return ( V_5 ) ;
V_2 -> V_6 = V_7 ;
V_2 -> V_8 . V_9 = V_3 ;
return ( 0 ) ;
}
int
F_3 ( struct V_1 * V_2 , T_1 V_10 )
{
int error ;
int V_11 ;
V_11 = 0 ;
if ( ( V_2 -> V_12 & V_13 ) == 0 )
V_11 = V_14 ;
error = F_4 ( V_10 , V_15 , V_11 , L_1 , V_2 ) ;
if ( error == 0 )
V_2 -> V_16 -> V_10 = V_10 ;
return ( - error ) ;
}
static int
F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_6 ( V_18 ) ;
T_1 V_21 = V_20 -> V_22 + V_23 ;
struct V_1 * V_2 ;
char V_24 [ 80 ] ;
char * V_25 ;
int error ;
sprintf ( V_24 , L_2 , V_21 >> 12 ) ;
V_25 = F_7 ( strlen ( V_24 ) + 1 , V_26 ) ;
if ( V_25 == NULL )
return ( V_5 ) ;
strcpy ( V_25 , V_24 ) ;
V_2 = F_8 ( & V_27 , V_25 ) ;
if ( V_2 == NULL )
return ( V_5 ) ;
error = F_9 ( V_2 , V_28 + V_20 -> V_29 . V_30 ,
V_21 ) ;
if ( error != 0 ) {
V_2 -> V_8 . V_9 = 0 ;
F_10 ( V_2 ) ;
return ( error ) ;
}
F_11 ( V_18 , V_2 ) ;
error = F_12 ( V_2 , & V_27 ) ;
return ( error ) ;
}
static int
F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
T_2 V_31 ;
if ( V_2 -> V_16 && V_2 -> V_16 -> V_32 )
F_15 ( V_2 -> V_16 -> V_32 ) ;
F_16 ( V_2 , & V_31 ) ;
F_17 ( V_2 , FALSE ) ;
F_18 ( V_2 , & V_31 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
int
F_19 ( void )
{
return F_20 ( & V_33 ) ;
}
void
F_21 ( void )
{
F_22 ( & V_33 ) ;
}
