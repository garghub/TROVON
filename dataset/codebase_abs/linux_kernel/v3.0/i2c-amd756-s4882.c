static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
int error ;
if ( V_3 == 0x4c || ( V_3 & 0xfc ) == 0x50 || ( V_3 & 0xfc ) == 0x30
|| V_3 == 0x18 )
return - V_10 ;
F_2 ( & V_11 ) ;
error = V_12 . V_13 -> V_14 ( V_2 , V_3 , V_4 , V_5 ,
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
if ( V_3 != 0x4c && ( V_3 & 0xfc ) != 0x50 && ( V_3 & 0xfc ) != 0x30 )
return - V_10 ;
F_2 ( & V_11 ) ;
if ( V_16 != V_15 ) {
union V_8 V_17 ;
V_17 . V_18 = V_15 ;
error = V_12 . V_13 -> V_14 ( V_2 , 0x18 , 0 ,
V_19 , 0x01 ,
V_20 ,
& V_17 ) ;
if ( error )
goto V_21;
V_16 = V_15 ;
}
error = V_12 . V_13 -> V_14 ( V_2 , V_3 , V_4 , V_5 ,
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
V_7 , V_9 , 0x03 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_9 , 0x24 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_9 , 0x48 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned short V_4 , char V_5 ,
T_3 V_6 , int V_7 ,
union V_8 * V_9 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_9 , 0x90 ) ;
}
static int T_4 F_9 ( void )
{
int V_22 , error ;
union V_8 V_23 ;
if ( ! V_12 . V_24 . V_25 )
return - V_26 ;
V_23 . V_18 = 0x00 ;
error = F_10 ( & V_12 , 0x18 , 0 , V_19 , 0x03 ,
V_20 , & V_23 ) ;
if ( error ) {
F_11 ( & V_12 . V_24 , L_1 ) ;
error = - V_27 ;
goto V_28;
}
error = F_12 ( & V_12 ) ;
if ( error ) {
F_11 ( & V_12 . V_24 , L_2 ) ;
goto V_28;
}
F_13 ( V_29 L_3 ) ;
if ( ! ( V_30 = F_14 ( 5 * sizeof( struct V_1 ) ,
V_31 ) ) ) {
error = - V_32 ;
goto V_33;
}
if ( ! ( V_34 = F_14 ( 5 * sizeof( struct V_35 ) ,
V_31 ) ) ) {
error = - V_32 ;
goto V_36;
}
V_34 [ 0 ] = * ( V_12 . V_13 ) ;
V_34 [ 0 ] . V_14 = F_1 ;
V_30 [ 0 ] = V_12 ;
V_30 [ 0 ] . V_13 = V_34 ;
V_30 [ 0 ] . V_24 . V_25 = V_12 . V_24 . V_25 ;
for ( V_22 = 1 ; V_22 < 5 ; V_22 ++ ) {
V_34 [ V_22 ] = * ( V_12 . V_13 ) ;
V_30 [ V_22 ] = V_12 ;
snprintf ( V_30 [ V_22 ] . V_37 , sizeof( V_30 [ V_22 ] . V_37 ) ,
L_4 , V_22 - 1 ) ;
V_30 [ V_22 ] . V_13 = V_34 + V_22 ;
V_30 [ V_22 ] . V_24 . V_25 = V_12 . V_24 . V_25 ;
}
V_34 [ 1 ] . V_14 = F_5 ;
V_34 [ 2 ] . V_14 = F_6 ;
V_34 [ 3 ] . V_14 = F_7 ;
V_34 [ 4 ] . V_14 = F_8 ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
error = F_15 ( V_30 + V_22 ) ;
if ( error ) {
F_13 ( V_38 L_5
L_6
L_7 , V_22 ) ;
for ( V_22 -- ; V_22 >= 0 ; V_22 -- )
F_12 ( V_30 + V_22 ) ;
goto V_39;
}
}
return 0 ;
V_39:
F_16 ( V_34 ) ;
V_34 = NULL ;
V_36:
F_16 ( V_30 ) ;
V_30 = NULL ;
V_33:
F_15 ( & V_12 ) ;
V_28:
return error ;
}
static void T_5 F_17 ( void )
{
if ( V_30 ) {
int V_22 ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_12 ( V_30 + V_22 ) ;
F_16 ( V_30 ) ;
V_30 = NULL ;
}
F_16 ( V_34 ) ;
V_34 = NULL ;
if ( F_15 ( & V_12 ) )
F_13 ( V_38 L_5
L_8 ) ;
}
