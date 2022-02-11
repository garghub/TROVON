static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 = 0 ;
T_1 V_7 = 0 ;
T_2 V_8 ;
T_3 V_9 ;
T_4 V_10 ;
struct V_11 * V_12 = F_2 ( F_3 ( V_2 ) ) ;
struct V_13 * V_14 = F_4 ( V_4 ) ;
F_5 ( & V_12 -> V_15 ) ;
F_6 ( V_12 -> V_16 , 0 ) ;
F_7 ( 1 ) ;
F_6 ( V_12 -> V_16 , 1 ) ;
F_6 ( V_12 -> V_17 , V_14 -> V_18 ) ;
V_6 = F_8 ( V_12 -> V_19 , V_12 -> V_20 , 2 ) ;
if ( V_6 < 0 )
goto V_21;
V_10 = V_12 -> V_20 [ 1 ] ;
if ( V_14 -> V_18 )
V_8 = ( ( ( T_2 ) ( V_12 -> V_20 [ 0 ] ) ) << 4 ) | ( ( V_12 -> V_20 [ 1 ] & 0xF0 ) >> 4 ) ;
else {
V_9 = ( V_12 -> V_20 [ 0 ] & 0x80 ) ? 0xf000 : 0 ;
V_9 |= ( ( ( T_3 ) ( V_12 -> V_20 [ 0 ] ) ) << 4 ) | ( ( V_12 -> V_20 [ 1 ] & 0xF0 ) >> 4 ) ;
}
V_7 = sprintf ( V_5 , L_1 , V_14 -> V_18 ? V_8 : V_9 ,
( V_10 & 0x8 ) ? 'P' : 'V' ,
( V_10 & 0x4 ) ? 'd' : '_' ,
( V_10 & 0x2 ) ? 'l' : '_' ,
( V_10 & 0x1 ) ? '1' : '0' ) ;
V_21:
F_7 ( 1 ) ;
F_9 ( & V_12 -> V_15 ) ;
return V_6 ? V_6 : V_7 ;
}
static int T_5 F_10 ( struct V_22 * V_23 )
{
struct V_11 * V_12 ;
struct V_24 * V_25 ;
int V_26 , V_6 = 0 ;
unsigned short * V_27 = V_23 -> V_2 . V_28 ;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ )
if ( F_11 ( V_27 [ V_26 ] , V_30 , V_31 ) ) {
F_12 ( L_2 ,
V_31 , V_27 [ V_26 ] ) ;
goto V_21;
}
V_25 = F_13 ( sizeof( * V_12 ) ) ;
if ( V_25 == NULL ) {
V_6 = - V_32 ;
goto V_21;
}
F_14 ( V_23 , V_25 ) ;
V_12 = F_2 ( V_25 ) ;
F_15 ( & V_12 -> V_15 ) ;
V_12 -> V_19 = V_23 ;
V_12 -> V_16 = V_27 [ 0 ] ;
V_12 -> V_17 = V_27 [ 1 ] ;
V_25 -> V_2 . V_33 = & V_23 -> V_2 ;
V_25 -> V_34 = & V_35 ;
V_25 -> V_36 = V_37 ;
V_6 = F_16 ( V_25 ) ;
if ( V_6 )
goto V_38;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = V_42 ;
F_17 ( V_23 ) ;
return 0 ;
V_38:
F_18 ( V_25 ) ;
V_21:
for ( -- V_26 ; V_26 >= 0 ; V_26 -- )
F_19 ( V_27 [ V_26 ] ) ;
return V_6 ;
}
static int T_6 F_20 ( struct V_22 * V_23 )
{
F_21 ( F_22 ( V_23 ) ) ;
return 0 ;
}
static T_7 int F_23 ( void )
{
return F_24 ( & V_43 ) ;
}
static T_8 void F_25 ( void )
{
F_26 ( & V_43 ) ;
}
