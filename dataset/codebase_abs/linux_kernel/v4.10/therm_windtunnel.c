static void
F_1 ( const char * V_1 , int V_2 )
{
F_2 ( L_1 , V_1 ? V_1 : L_2 , V_2 >> 8 , ( V_2 & 255 ) * 10 / 256 ) ;
}
static T_1
F_3 ( struct V_3 * V_4 , struct V_5 * V_6 , char * V_7 )
{
return sprintf ( V_7 , L_3 , V_8 . V_2 >> 8 , ( V_8 . V_2 & 255 ) * 10 / 256 ) ;
}
static T_1
F_4 ( struct V_3 * V_4 , struct V_5 * V_6 , char * V_7 )
{
return sprintf ( V_7 , L_3 , V_8 . V_9 >> 8 , ( V_8 . V_9 & 255 ) * 10 / 256 ) ;
}
static int
F_5 ( struct V_10 * V_11 , int V_12 , int V_13 , int V_14 )
{
T_2 V_15 [ 3 ] ;
if( V_14 < 1 || V_14 > 2 || V_13 < 0 )
return - V_16 ;
V_15 [ 0 ] = V_12 ;
V_15 [ 1 ] = ( V_14 == 1 ) ? V_13 : ( V_13 >> 8 ) ;
V_15 [ 2 ] = V_13 ;
V_14 ++ ;
if( F_6 ( V_11 , V_15 , V_14 ) != V_14 )
return - V_17 ;
return 0 ;
}
static int
F_7 ( struct V_10 * V_11 , int V_12 , int V_14 )
{
T_2 V_7 [ 2 ] ;
if( V_14 != 1 && V_14 != 2 )
return - V_16 ;
V_7 [ 0 ] = V_12 ;
if( F_6 ( V_11 , V_7 , 1 ) != 1 )
return - V_17 ;
if( F_8 ( V_11 , V_7 , V_14 ) != V_14 )
return - V_17 ;
return ( V_14 == 2 ) ? ( ( unsigned int ) V_7 [ 0 ] << 8 ) | V_7 [ 1 ] : V_7 [ 0 ] ;
}
static void
F_9 ( int V_18 )
{
int V_19 = ( V_18 << 3 ) | 7 ;
F_5 ( V_8 . V_20 , 0x25 , V_19 , 1 ) ;
F_5 ( V_8 . V_20 , 0x20 , 0 , 1 ) ;
F_1 ( L_4 , V_8 . V_2 ) ;
if( V_8 . V_9 )
F_1 ( L_5 , V_8 . V_9 ) ;
F_2 ( L_6 , 11 - V_18 , V_8 . V_21 - V_18 ) ;
V_8 . V_21 = V_18 ;
}
static void
F_10 ( void )
{
int V_2 , V_22 , V_23 , V_9 ;
V_2 = F_7 ( V_8 . V_24 , 0 , 2 ) ;
if( V_2 < 0 )
return;
V_9 = F_7 ( V_8 . V_20 , 0x0b , 1 ) << 8 ;
V_9 |= ( F_7 ( V_8 . V_20 , 0x06 , 1 ) & 0x7 ) << 5 ;
if( V_25 && V_8 . V_2 != V_2 ) {
F_1 ( L_4 , V_2 ) ;
F_1 ( L_5 , V_9 ) ;
F_2 ( L_7 , 11 - V_8 . V_21 ) ;
}
V_8 . V_2 = V_2 ;
V_8 . V_9 = V_9 ;
V_23 = - 1 ;
for( V_22 = 0 ; ( V_2 & 0xffff ) > V_26 [ V_22 ] . V_2 ; V_22 ++ )
;
if( V_22 < V_8 . V_27 )
V_23 = V_26 [ V_22 ] . V_28 ;
V_8 . V_27 = V_22 ;
for( V_22 = 0 ; ( V_2 & 0xffff ) >= V_26 [ V_22 + 1 ] . V_2 ; V_22 ++ )
;
if( V_8 . V_29 < V_22 )
V_23 = V_26 [ V_22 ] . V_30 ;
V_8 . V_29 = V_22 ;
if( V_23 >= 0 )
F_9 ( V_23 ) ;
}
static void
F_11 ( void )
{
int V_19 ;
int V_31 ;
V_8 . V_32 = F_7 ( V_8 . V_20 , 0x00 , 1 ) ;
V_8 . V_33 = F_7 ( V_8 . V_20 , 0x01 , 1 ) ;
V_8 . V_34 = F_7 ( V_8 . V_20 , 0x20 , 1 ) ;
V_8 . V_35 = F_7 ( V_8 . V_20 , 0x23 , 1 ) ;
V_8 . V_36 = F_7 ( V_8 . V_20 , 0x25 , 1 ) ;
if( ( V_19 = F_7 ( V_8 . V_24 , 1 , 1 ) ) >= 0 ) {
V_19 |= 0x60 ;
if( F_5 ( V_8 . V_24 , 1 , V_19 , 1 ) )
F_2 ( L_8 ) ;
}
F_5 ( V_8 . V_20 , 0x01 , 0x01 , 1 ) ;
F_5 ( V_8 . V_20 , 0x23 , 0x91 , 1 ) ;
F_5 ( V_8 . V_20 , 0x00 , 0x95 , 1 ) ;
if( V_8 . V_37 == ( 80 << 8 ) ) {
V_8 . V_37 = 75 << 8 ;
V_8 . V_38 = 70 << 8 ;
F_5 ( V_8 . V_24 , 2 , V_8 . V_38 , 2 ) ;
F_5 ( V_8 . V_24 , 3 , V_8 . V_37 , 2 ) ;
F_1 ( L_9 , V_8 . V_37 ) ;
F_1 ( L_10 , V_8 . V_38 ) ;
F_2 ( L_11 ) ;
}
V_8 . V_27 = 0xffff ;
V_8 . V_29 = - 1 ;
V_31 = F_12 ( & V_8 . V_39 -> V_4 , & V_40 ) ;
V_31 |= F_12 ( & V_8 . V_39 -> V_4 , & V_41 ) ;
if ( V_31 )
F_2 ( V_42
L_12 ) ;
}
static void
F_13 ( void )
{
F_14 ( & V_8 . V_39 -> V_4 , & V_40 ) ;
F_14 ( & V_8 . V_39 -> V_4 , & V_41 ) ;
F_5 ( V_8 . V_20 , 0x01 , V_8 . V_33 , 1 ) ;
F_5 ( V_8 . V_20 , 0x20 , V_8 . V_34 , 1 ) ;
F_5 ( V_8 . V_20 , 0x23 , V_8 . V_35 , 1 ) ;
F_5 ( V_8 . V_20 , 0x25 , V_8 . V_36 , 1 ) ;
F_5 ( V_8 . V_20 , 0x00 , V_8 . V_32 , 1 ) ;
}
static int F_15 ( void * V_43 )
{
F_16 ( & V_8 . V_44 ) ;
F_11 () ;
F_17 ( & V_8 . V_44 ) ;
for (; ; ) {
F_18 ( 8000 ) ;
if ( F_19 () )
break;
F_16 ( & V_8 . V_44 ) ;
F_10 () ;
F_17 ( & V_8 . V_44 ) ;
}
F_16 ( & V_8 . V_44 ) ;
F_13 () ;
F_17 ( & V_8 . V_44 ) ;
return 0 ;
}
static int
F_20 ( struct V_45 * V_46 )
{
static const unsigned short V_47 [] = {
0x48 , 0x49 , 0x4a , 0x4b , 0x4c , 0x4d , 0x4e , 0x4f ,
V_48
} ;
static const unsigned short V_49 [] = {
0x2c , 0x2d , 0x2e , 0x2f ,
V_48
} ;
if( strncmp ( V_46 -> V_50 , L_13 , 5 ) )
return 0 ;
if( ! V_8 . V_51 ) {
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
F_21 ( V_53 . type , L_14 , V_54 ) ;
F_22 ( V_46 , & V_53 , V_47 , NULL ) ;
F_21 ( V_53 . type , L_15 , V_54 ) ;
F_22 ( V_46 , & V_53 , V_49 , NULL ) ;
if( V_8 . V_24 && V_8 . V_20 ) {
V_8 . V_51 = 1 ;
V_8 . V_55 = F_23 ( F_15 , NULL , L_16 ) ;
}
}
return 0 ;
}
static int
F_24 ( struct V_10 * V_56 )
{
if ( V_8 . V_51 ) {
V_8 . V_51 = 0 ;
F_25 ( V_8 . V_55 ) ;
V_8 . V_55 = NULL ;
}
if ( V_56 == V_8 . V_24 )
V_8 . V_24 = NULL ;
else if ( V_56 == V_8 . V_20 )
V_8 . V_20 = NULL ;
else
F_2 ( V_57 L_17 ) ;
return 0 ;
}
static int
F_26 ( struct V_10 * V_11 )
{
if( V_8 . V_20 )
goto V_58;
if( F_7 ( V_11 , 0x3d , 1 ) != 0x30 || F_7 ( V_11 , 0x3e , 1 ) != 0x41 )
goto V_58;
F_2 ( L_18 , V_11 -> V_59 ) ;
V_8 . V_20 = V_11 ;
V_58:
return 0 ;
}
static int
F_27 ( struct V_10 * V_11 )
{
int V_60 , V_61 , V_2 ;
if( V_8 . V_24 )
goto V_58;
if( ( V_2 = F_7 ( V_11 , 0 , 2 ) ) < 0 )
goto V_58;
if( V_2 < 0x1600 || V_2 > 0x3c00 )
goto V_58;
V_60 = F_7 ( V_11 , 2 , 2 ) ;
V_61 = F_7 ( V_11 , 3 , 2 ) ;
if( V_60 < 0 || V_61 < 0 )
goto V_58;
F_2 ( L_19 , V_11 -> V_59 ) ;
F_1 ( L_20 , V_2 ) ;
F_1 ( L_21 , V_60 ) ;
F_1 ( L_22 , V_61 ) ;
F_2 ( L_23 ) ;
V_8 . V_2 = V_2 ;
V_8 . V_37 = V_61 ;
V_8 . V_38 = V_60 ;
V_8 . V_24 = V_11 ;
V_58:
return 0 ;
}
static int
F_28 ( struct V_10 * V_11 , const struct V_62 * V_63 )
{
struct V_45 * V_46 = V_11 -> V_46 ;
if( ! F_29 ( V_46 , V_64
| V_65 ) )
return 0 ;
switch ( V_63 -> V_66 ) {
case V_67 :
return F_26 ( V_11 ) ;
case V_68 :
return F_27 ( V_11 ) ;
}
return 0 ;
}
static int F_30 ( struct V_69 * V_4 )
{
return F_31 ( & V_70 ) ;
}
static int
F_32 ( struct V_69 * V_4 )
{
F_33 ( & V_70 ) ;
return 0 ;
}
static int T_3
F_34 ( void )
{
const struct V_71 * V_53 ;
struct V_72 * V_73 ;
F_35 ( & V_8 . V_44 ) ;
if( ! ( V_73 = F_36 ( NULL , L_24 ) ) )
return - V_17 ;
V_53 = F_37 ( V_73 , L_25 , NULL ) ;
F_38 ( V_73 ) ;
if( ! V_53 || ! F_39 ( L_26 ) )
return - V_17 ;
if( V_53 -> V_63 != 3 ) {
F_2 ( V_57 L_27 , V_53 -> V_63 ) ;
return - V_17 ;
}
if( ! ( V_73 = F_36 ( NULL , L_28 ) ) )
return - V_17 ;
V_8 . V_39 = F_40 ( V_73 , L_29 , NULL ) ;
F_38 ( V_73 ) ;
if( ! V_8 . V_39 ) {
F_2 ( V_57 L_30 ) ;
return - V_17 ;
}
F_41 ( & V_74 ) ;
return 0 ;
}
static void T_4
F_42 ( void )
{
F_43 ( & V_74 ) ;
if( V_8 . V_39 )
F_44 ( V_8 . V_39 ) ;
}
