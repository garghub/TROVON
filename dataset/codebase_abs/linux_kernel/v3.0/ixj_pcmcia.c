static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 ) ;
V_2 -> V_4 = F_3 ( sizeof( struct V_5 ) , V_6 ) ;
if ( ! V_2 -> V_4 ) {
return - V_7 ;
}
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_8 )
{
F_2 ( & V_8 -> V_3 , L_2 ) ;
F_6 ( V_8 ) ;
F_7 ( V_8 -> V_4 ) ;
}
static void F_8 ( struct V_1 * V_8 , T_1 * V_9 )
{
char * V_10 ;
int V_11 , V_12 ;
F_2 ( & V_8 -> V_3 , L_3 ) ;
V_10 = V_8 -> V_13 [ 0 ] ;
if ( ! V_10 )
goto V_14;
F_9 ( L_4 , V_10 ) ;
V_10 = V_8 -> V_13 [ 1 ] ;
if ( ! V_10 )
goto V_14;
F_9 ( L_5 , V_10 ) ;
V_10 = V_8 -> V_13 [ 2 ] ;
if ( ! V_10 )
goto V_14;
V_12 = 1 ;
for ( V_11 = strlen ( V_10 ) - 1 ; V_11 >= 0 ; V_11 -- ) {
switch ( V_10 [ V_11 ] ) {
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
case '8' :
case '9' :
V_9 -> V_15 += ( V_10 [ V_11 ] - 48 ) * V_12 ;
break;
case 'A' :
case 'B' :
case 'C' :
case 'D' :
case 'E' :
case 'F' :
V_9 -> V_15 += ( V_10 [ V_11 ] - 55 ) * V_12 ;
break;
case 'a' :
case 'b' :
case 'c' :
case 'd' :
case 'e' :
case 'f' :
V_9 -> V_15 += ( V_10 [ V_11 ] - 87 ) * V_12 ;
break;
}
V_12 = V_12 * 0x10 ;
}
V_10 = V_8 -> V_13 [ 3 ] ;
if ( ! V_10 )
goto V_14;
F_9 ( L_6 , V_10 ) ;
V_14:
return;
}
static int F_10 ( struct V_1 * V_2 , void * V_16 )
{
V_2 -> V_17 [ 0 ] -> V_18 &= ~ V_19 ;
V_2 -> V_17 [ 0 ] -> V_18 |= V_20 ;
V_2 -> V_17 [ 1 ] -> V_18 &= ~ V_19 ;
V_2 -> V_17 [ 1 ] -> V_18 |= V_20 ;
V_2 -> V_21 = 3 ;
return F_11 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_8 )
{
T_1 * V_9 ;
V_5 * V_22 ;
V_22 = V_8 -> V_4 ;
F_2 ( & V_8 -> V_3 , L_7 ) ;
V_8 -> V_23 = V_24 ;
if ( F_12 ( V_8 , F_10 , NULL ) )
goto V_14;
if ( F_13 ( V_8 ) )
goto V_14;
V_9 = F_14 ( V_8 -> V_17 [ 0 ] -> V_25 ,
V_8 -> V_17 [ 0 ] -> V_25 + 0x10 ) ;
V_22 -> V_26 = 1 ;
F_8 ( V_8 , V_9 ) ;
return 0 ;
V_14:
F_6 ( V_8 ) ;
return - V_27 ;
}
static void F_6 ( struct V_1 * V_8 )
{
V_5 * V_22 = V_8 -> V_4 ;
F_2 ( & V_8 -> V_3 , L_8 ) ;
V_22 -> V_26 = 0 ;
F_15 ( V_8 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_28 ) ;
}
static void F_18 ( void )
{
F_19 ( & V_28 ) ;
}
