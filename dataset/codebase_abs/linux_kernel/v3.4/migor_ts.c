static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned short V_5 , V_6 ;
unsigned char V_7 ;
T_2 V_8 [ 16 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ 0 ] = 0 ;
if ( F_2 ( V_4 -> V_9 , V_8 , 1 ) != 1 ) {
F_3 ( & V_4 -> V_9 -> V_10 , L_1 ) ;
goto V_11;
}
if ( F_4 ( V_4 -> V_9 , V_8 , sizeof( V_8 ) ) != sizeof( V_8 ) ) {
F_3 ( & V_4 -> V_9 -> V_10 , L_2 ) ;
goto V_11;
}
V_6 = ( ( V_8 [ 9 ] & 0x03 ) << 8 | V_8 [ 8 ] ) ;
V_5 = ( ( V_8 [ 11 ] & 0x03 ) << 8 | V_8 [ 10 ] ) ;
V_7 = V_8 [ 12 ] ;
switch ( V_7 ) {
case V_12 :
case V_13 :
F_5 ( V_4 -> V_14 , V_15 , 1 ) ;
F_6 ( V_4 -> V_14 , V_16 , V_6 ) ;
F_6 ( V_4 -> V_14 , V_17 , V_5 ) ;
F_7 ( V_4 -> V_14 ) ;
break;
case V_18 :
F_5 ( V_4 -> V_14 , V_15 , 0 ) ;
F_7 ( V_4 -> V_14 ) ;
break;
}
V_11:
return V_19 ;
}
static int F_8 ( struct V_20 * V_10 )
{
struct V_3 * V_4 = F_9 ( V_10 ) ;
struct V_21 * V_9 = V_4 -> V_9 ;
int V_22 ;
V_22 = F_2 ( V_9 , V_23 ,
sizeof( V_23 ) ) ;
if ( V_22 != sizeof( V_23 ) ) {
F_3 ( & V_9 -> V_10 , L_3 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_10 ( struct V_20 * V_10 )
{
struct V_3 * V_4 = F_9 ( V_10 ) ;
struct V_21 * V_9 = V_4 -> V_9 ;
F_11 ( V_4 -> V_1 ) ;
F_2 ( V_9 , V_25 , sizeof( V_25 ) ) ;
F_12 ( V_4 -> V_1 ) ;
}
static int F_13 ( struct V_21 * V_9 ,
const struct V_26 * V_27 )
{
struct V_3 * V_4 ;
struct V_20 * V_14 ;
int error ;
V_4 = F_14 ( sizeof( * V_4 ) , V_28 ) ;
V_14 = F_15 () ;
if ( ! V_4 || ! V_14 ) {
F_3 ( & V_9 -> V_10 , L_4 ) ;
error = - V_29 ;
goto V_30;
}
V_4 -> V_9 = V_9 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_1 = V_9 -> V_1 ;
V_14 -> V_31 [ 0 ] = F_16 ( V_32 ) | F_16 ( V_33 ) ;
F_17 ( V_15 , V_14 -> V_34 ) ;
F_18 ( V_14 , V_16 , 95 , 955 , 0 , 0 ) ;
F_18 ( V_14 , V_17 , 85 , 935 , 0 , 0 ) ;
V_14 -> V_35 = V_9 -> V_35 ;
V_14 -> V_36 . V_37 = V_38 ;
V_14 -> V_10 . V_39 = & V_9 -> V_10 ;
V_14 -> V_40 = F_8 ;
V_14 -> V_41 = F_10 ;
F_19 ( V_14 , V_4 ) ;
error = F_20 ( V_4 -> V_1 , NULL , F_1 ,
V_42 | V_43 ,
V_9 -> V_35 , V_4 ) ;
if ( error ) {
F_3 ( & V_9 -> V_10 , L_5 ) ;
goto V_30;
}
error = F_21 ( V_14 ) ;
if ( error )
goto V_44;
F_22 ( V_9 , V_4 ) ;
F_23 ( & V_9 -> V_10 , 1 ) ;
return 0 ;
V_44:
F_24 ( V_4 -> V_1 , V_4 ) ;
V_30:
F_25 ( V_14 ) ;
F_26 ( V_4 ) ;
return error ;
}
static int F_27 ( struct V_21 * V_9 )
{
struct V_3 * V_4 = F_28 ( V_9 ) ;
F_24 ( V_4 -> V_1 , V_4 ) ;
F_29 ( V_4 -> V_14 ) ;
F_26 ( V_4 ) ;
F_30 ( & V_9 -> V_10 , NULL ) ;
return 0 ;
}
static int F_31 ( struct V_45 * V_10 )
{
struct V_21 * V_9 = F_32 ( V_10 ) ;
struct V_3 * V_4 = F_28 ( V_9 ) ;
if ( F_33 ( & V_9 -> V_10 ) )
F_34 ( V_4 -> V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_45 * V_10 )
{
struct V_21 * V_9 = F_32 ( V_10 ) ;
struct V_3 * V_4 = F_28 ( V_9 ) ;
if ( F_33 ( & V_9 -> V_10 ) )
F_36 ( V_4 -> V_1 ) ;
return 0 ;
}
