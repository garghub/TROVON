static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] ;
}
static int F_2 ( struct V_5 * V_6 ,
struct V_1 * V_2 , unsigned int V_3 ,
struct V_7 * * V_8 )
{
static long V_9 [] = { 0x220 , 0x230 , 0x240 , 0x250 , 0x260 } ;
static int V_10 [] = { 5 , 11 , 12 , 9 , 7 , 15 , 3 , 4 , - 1 } ;
static int V_11 [] = { 5 , 6 , 7 , 1 , 3 , - 1 } ;
int V_12 , error ;
if ( V_13 [ V_3 ] == V_14 ) {
V_13 [ V_3 ] = F_3 ( V_10 ) ;
if ( V_13 [ V_3 ] < 0 ) {
F_4 ( V_2 , L_1 ) ;
return - V_15 ;
}
}
if ( V_16 [ V_3 ] == V_17 ) {
V_16 [ V_3 ] = F_5 ( V_11 ) ;
if ( V_16 [ V_3 ] < 0 ) {
F_4 ( V_2 , L_2 ) ;
return - V_15 ;
}
}
if ( V_18 [ V_3 ] == V_17 ) {
V_18 [ V_3 ] = F_5 ( V_11 ) ;
if ( V_18 [ V_3 ] < 0 ) {
F_4 ( V_2 , L_3 ) ;
return - V_15 ;
}
}
if ( V_19 [ V_3 ] != V_20 )
return F_6 ( V_6 , V_19 [ V_3 ] , V_13 [ V_3 ] , V_16 [ V_3 ] , V_18 [ V_3 ] ,
0 , V_21 [ V_3 ] , V_22 [ V_3 ] , 0 , V_8 ) ;
V_12 = 0 ;
do {
V_19 [ V_3 ] = V_9 [ V_12 ] ;
error = F_6 ( V_6 , V_19 [ V_3 ] , V_13 [ V_3 ] , V_16 [ V_3 ] , V_18 [ V_3 ] ,
0 , V_21 [ V_3 ] , V_22 [ V_3 ] , 0 , V_8 ) ;
} while ( error < 0 && ++ V_12 < F_7 ( V_9 ) );
return error ;
}
static int F_8 ( struct V_7 * V_23 )
{
unsigned char V_24 ;
F_9 ( V_23 , V_25 , 0 ) ;
if ( ( ( V_24 = F_10 ( V_23 , V_25 ) ) & 0x07 ) != 0 ) {
F_11 ( L_4 , V_23 -> V_26 . V_19 , V_24 ) ;
return - V_27 ;
}
F_12 ( 160 ) ;
F_9 ( V_23 , V_25 , 1 ) ;
F_12 ( 160 ) ;
if ( ( ( V_24 = F_10 ( V_23 , V_25 ) ) & 0x07 ) != 1 ) {
F_11 ( L_5 , V_23 -> V_26 . V_19 , V_24 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_23 ;
int error ;
error = F_14 ( V_2 , V_28 [ V_3 ] , V_29 [ V_3 ] , V_30 , 0 , & V_6 ) ;
if ( error < 0 )
return error ;
if ( V_22 [ V_3 ] < 2 )
V_22 [ V_3 ] = 2 ;
error = F_2 ( V_6 , V_2 , V_3 , & V_23 ) ;
if ( error < 0 )
goto V_31;
error = F_8 ( V_23 ) ;
if ( error < 0 )
goto V_31;
V_23 -> V_32 = V_32 [ V_3 ] ;
error = F_15 ( V_23 ) ;
if ( error < 0 )
goto V_31;
error = - V_27 ;
if ( V_23 -> V_33 || V_23 -> V_34 ) {
F_4 ( V_2 , L_6
L_7 , V_23 -> V_26 . V_19 ) ;
goto V_31;
}
error = F_16 ( V_23 ) ;
if ( error < 0 )
goto V_31;
error = F_17 ( V_23 , 0 , 0 ) ;
if ( error < 0 )
goto V_31;
if ( ! V_23 -> V_35 ) {
error = F_18 ( V_23 , 0 ) ;
if ( error < 0 )
goto V_31;
}
sprintf ( V_6 -> V_36 + strlen ( V_6 -> V_36 ) ,
L_8 ,
V_23 -> V_26 . V_19 , V_23 -> V_26 . V_13 , V_23 -> V_26 . V_16 ) ;
if ( V_23 -> V_26 . V_18 >= 0 )
sprintf ( V_6 -> V_36 + strlen ( V_6 -> V_36 ) ,
L_9 , V_23 -> V_26 . V_18 ) ;
error = F_19 ( V_6 ) ;
if ( error < 0 )
goto V_31;
F_20 ( V_2 , V_6 ) ;
return 0 ;
V_31: F_21 ( V_6 ) ;
return error ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_21 ( F_23 ( V_2 ) ) ;
return 0 ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_37 , V_38 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_37 ) ;
}
