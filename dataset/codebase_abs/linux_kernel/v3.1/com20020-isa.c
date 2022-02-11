static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 (D_NORMAL) F_4 ( V_8 ) ;
V_3 = V_2 -> V_9 ;
if ( ! V_3 ) {
F_5 ( V_10 , L_1
L_2 ) ;
return - V_11 ;
}
if ( ! F_6 ( V_3 , V_12 , L_3 ) ) {
F_5 ( V_10 , L_4 ,
V_3 , V_3 + V_12 - 1 ) ;
return - V_13 ;
}
if ( F_7 () == 0xFF ) {
F_5 ( V_10 , L_5 , V_3 ) ;
V_7 = - V_11 ;
goto V_14;
}
if ( F_8 ( V_2 ) ) {
V_7 = - V_11 ;
goto V_14;
}
if ( ! V_2 -> V_15 ) {
F_5 ( V_16 , L_6 , F_9 ( V_17 ) ) ;
F_10 ( 0 , V_17 ) ;
V_4 = F_11 () ;
F_10 ( V_18 , V_17 ) ;
F_12 ( 1 ) ;
F_10 ( 0 , V_17 ) ;
V_2 -> V_15 = F_13 ( V_4 ) ;
if ( ( int ) V_2 -> V_15 <= 0 ) {
F_5 ( V_16 , L_7 ) ;
V_4 = F_11 () ;
F_10 ( V_18 , V_17 ) ;
F_12 ( 5 ) ;
F_10 ( 0 , V_17 ) ;
V_2 -> V_15 = F_13 ( V_4 ) ;
if ( ( int ) V_2 -> V_15 <= 0 ) {
F_5 ( V_10 , L_8 ) ;
V_7 = - V_11 ;
goto V_14;
}
}
}
V_6 -> V_19 = L_9 ;
if ( ( V_7 = F_14 ( V_2 , 0 ) ) != 0 )
goto V_14;
return 0 ;
V_14:
F_15 ( V_3 , V_12 ) ;
return V_7 ;
}
static int T_1 F_16 ( void )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = F_17 ( V_20 ) ;
if ( ! V_2 )
return - V_21 ;
if ( V_22 && V_22 != 0xff )
V_2 -> V_23 [ 0 ] = V_22 ;
V_2 -> V_24 = & V_25 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_26 = V_26 ;
V_6 -> V_27 = V_27 & 7 ;
V_6 -> V_28 = V_28 & 3 ;
V_6 -> V_29 = V_29 & 3 ;
V_6 -> V_30 . V_31 = V_32 ;
V_2 -> V_9 = V_33 ;
V_2 -> V_15 = V_15 ;
if ( V_2 -> V_15 == 2 )
V_2 -> V_15 = 9 ;
if ( F_1 ( V_2 ) ) {
F_18 ( V_2 ) ;
return - V_34 ;
}
V_35 = V_2 ;
return 0 ;
}
static void T_2 F_19 ( void )
{
F_20 ( V_35 ) ;
F_21 ( V_35 -> V_15 , V_35 ) ;
F_15 ( V_35 -> V_9 , V_12 ) ;
F_18 ( V_35 ) ;
}
static int T_1 F_22 ( char * V_36 )
{
int V_37 [ 8 ] ;
V_36 = F_23 ( V_36 , 8 , V_37 ) ;
if ( ! V_37 [ 0 ] )
return 1 ;
switch ( V_37 [ 0 ] ) {
default:
F_4 ( L_10 ) ;
case 6 :
V_29 = V_37 [ 6 ] ;
case 5 :
V_27 = V_37 [ 5 ] ;
case 4 :
V_26 = V_37 [ 4 ] ;
case 3 :
V_22 = V_37 [ 3 ] ;
case 2 :
V_15 = V_37 [ 2 ] ;
case 1 :
V_33 = V_37 [ 1 ] ;
}
if ( * V_36 )
snprintf ( V_20 , sizeof( V_20 ) , L_11 , V_36 ) ;
return 1 ;
}
