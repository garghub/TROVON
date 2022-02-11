static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
int error ;
if ( ( V_3 & 0xfc ) == 0x50 || ( V_3 & 0xfc ) == 0x30
|| V_3 == 0x18 )
return - V_10 ;
F_2 ( & V_11 ) ;
error = V_12 -> V_13 -> V_14 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_9 ) ;
F_3 ( & V_11 ) ;
return error ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 ,
T_3 V_15 )
{
int error ;
if ( ( V_3 & 0xfc ) != 0x50 && ( V_3 & 0xfc ) != 0x30 )
return - V_10 ;
F_2 ( & V_11 ) ;
if ( V_16 != V_15 ) {
union V_8 V_17 ;
V_17 . V_18 = V_15 ;
error = V_12 -> V_13 -> V_14 ( V_2 , 0x18 , 0 ,
V_19 , 0x01 ,
V_20 ,
& V_17 ) ;
if ( error )
goto V_21;
V_16 = V_15 ;
}
error = V_12 -> V_13 -> V_14 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_9 ) ;
V_21:
F_3 ( & V_11 ) ;
return error ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_9 , 0x02 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_9 , 0x04 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_9 , 0x08 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_9 , 0x10 ) ;
}
static int T_4 F_9 ( void )
{
int V_22 , error ;
union V_8 V_23 ;
if ( ! V_12 )
return - V_24 ;
V_23 . V_18 = 0x00 ;
error = F_10 ( V_12 , 0x18 , 0 , V_19 , 0x03 ,
V_20 , & V_23 ) ;
if ( error ) {
F_11 ( & V_12 -> V_25 , L_1 ) ;
error = - V_26 ;
goto V_27;
}
error = F_12 ( V_12 ) ;
if ( error ) {
F_11 ( & V_12 -> V_25 , L_2 ) ;
goto V_27;
}
F_13 ( V_28 L_3 ) ;
V_29 = F_14 ( 5 * sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_29 ) {
error = - V_31 ;
goto V_32;
}
V_33 = F_14 ( 5 * sizeof( struct V_34 ) , V_30 ) ;
if ( ! V_33 ) {
error = - V_31 ;
goto V_35;
}
V_33 [ 0 ] = * ( V_12 -> V_13 ) ;
V_33 [ 0 ] . V_14 = F_1 ;
V_29 [ 0 ] = * V_12 ;
V_29 [ 0 ] . V_13 = V_33 ;
V_29 [ 0 ] . V_25 . V_36 = V_12 -> V_25 . V_36 ;
for ( V_22 = 1 ; V_22 < 5 ; V_22 ++ ) {
V_33 [ V_22 ] = * ( V_12 -> V_13 ) ;
V_29 [ V_22 ] = * V_12 ;
snprintf ( V_29 [ V_22 ] . V_37 , sizeof( V_29 [ V_22 ] . V_37 ) ,
L_4 , V_22 - 1 ) ;
V_29 [ V_22 ] . V_13 = V_33 + V_22 ;
V_29 [ V_22 ] . V_25 . V_36 = V_12 -> V_25 . V_36 ;
}
V_33 [ 1 ] . V_14 = F_5 ;
V_33 [ 2 ] . V_14 = F_6 ;
V_33 [ 3 ] . V_14 = F_7 ;
V_33 [ 4 ] . V_14 = F_8 ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
error = F_15 ( V_29 + V_22 ) ;
if ( error ) {
F_13 ( V_38 L_5
L_6
L_7 , V_22 ) ;
for ( V_22 -- ; V_22 >= 0 ; V_22 -- )
F_12 ( V_29 + V_22 ) ;
goto V_39;
}
}
return 0 ;
V_39:
F_16 ( V_33 ) ;
V_33 = NULL ;
V_35:
F_16 ( V_29 ) ;
V_29 = NULL ;
V_32:
F_15 ( V_12 ) ;
V_27:
return error ;
}
static void T_5 F_17 ( void )
{
if ( V_29 ) {
int V_22 ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_12 ( V_29 + V_22 ) ;
F_16 ( V_29 ) ;
V_29 = NULL ;
}
F_16 ( V_33 ) ;
V_33 = NULL ;
if ( F_15 ( V_12 ) )
F_13 ( V_38 L_5
L_8 ) ;
}
