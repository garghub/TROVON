static void F_1 ( struct V_1 * V_1 , unsigned char V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
V_1 -> V_2 [ V_1 -> V_5 ] = V_2 ;
switch ( V_1 -> V_5 ++ ) {
case 0 :
V_1 -> V_6 = 0xaa ;
if ( V_2 != V_7 ) {
F_2 ( & V_1 -> V_8 -> V_4 ,
L_1 , V_2 ) ;
V_1 -> V_5 = 0 ;
}
break;
case 9 :
V_1 -> V_5 = 0 ;
if ( V_2 != V_1 -> V_6 ) {
F_2 ( & V_1 -> V_8 -> V_4 ,
L_2 ,
V_2 , V_1 -> V_6 ) ;
break;
}
if ( V_1 -> V_2 [ 1 ] != V_1 -> V_9 ) {
if ( V_1 -> V_2 [ 1 ] != V_10 )
F_2 ( & V_1 -> V_8 -> V_4 ,
L_3 ,
V_1 -> V_2 [ 1 ] ) ;
break;
}
if ( F_3 ( V_1 -> V_2 [ 1 ] == V_10 ) ) {
F_4 ( V_4 , V_11 , ( V_1 -> V_2 [ 4 ] << 8 ) | V_1 -> V_2 [ 3 ] ) ;
F_4 ( V_4 , V_12 , ( V_1 -> V_2 [ 6 ] << 8 ) | V_1 -> V_2 [ 5 ] ) ;
if ( V_1 -> V_2 [ 2 ] & V_13 )
F_4 ( V_4 , V_14 ,
( V_1 -> V_2 [ 8 ] << 8 ) | V_1 -> V_2 [ 7 ] ) ;
F_5 ( V_4 , V_15 , V_1 -> V_2 [ 2 ] & V_16 ) ;
F_6 ( V_4 ) ;
} else if ( V_1 -> V_2 [ 1 ] == V_17 ) {
if ( V_1 -> V_2 [ 2 ] == '0' )
V_1 -> V_9 = V_10 ;
F_7 ( & V_1 -> V_18 ) ;
} else {
memcpy ( V_1 -> V_19 , & V_1 -> V_2 [ 1 ] , V_20 ) ;
V_1 -> V_9 = V_17 ;
}
break;
}
V_1 -> V_6 += V_2 ;
}
static void F_8 ( struct V_1 * V_1 , unsigned char V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
V_1 -> V_2 [ V_1 -> V_5 ] = V_2 ;
switch ( V_1 -> V_5 ++ ) {
case 0 :
if ( ( V_2 & 0xc0 ) != 0xc0 )
V_1 -> V_5 = 0 ;
break;
case 1 :
if ( ( V_2 & 0xc0 ) != 0x80 )
V_1 -> V_5 = 0 ;
break;
case 2 :
if ( ( V_2 & 0xc0 ) != 0x40 )
V_1 -> V_5 = 0 ;
break;
case 3 :
if ( V_2 & 0xc0 ) {
V_1 -> V_5 = 0 ;
break;
}
F_4 ( V_4 , V_11 , ( ( V_1 -> V_2 [ 0 ] & 0x3f ) << 6 ) | ( V_1 -> V_2 [ 1 ] & 0x3f ) ) ;
F_4 ( V_4 , V_12 , ( ( V_1 -> V_2 [ 2 ] & 0x3f ) << 6 ) | ( V_1 -> V_2 [ 3 ] & 0x3f ) ) ;
if ( V_1 -> V_21 == 2 ) {
F_5 ( V_4 , V_15 , 1 ) ;
F_6 ( V_4 ) ;
V_1 -> V_5 = 0 ;
}
break;
case 4 :
if ( V_2 ) {
F_6 ( V_4 ) ;
V_1 -> V_5 = 0 ;
}
break;
case 5 :
if ( ( V_2 & 0xf0 ) == 0 ) {
F_4 ( V_4 , V_14 , V_1 -> V_2 [ 5 ] ) ;
F_5 ( V_4 , V_15 , ! ! V_1 -> V_2 [ 5 ] ) ;
}
F_6 ( V_4 ) ;
V_1 -> V_5 = 0 ;
break;
}
}
static void F_9 ( struct V_1 * V_1 , unsigned char V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
V_1 -> V_2 [ V_1 -> V_5 ] = V_2 ;
switch ( V_1 -> V_5 ++ ) {
case 0 :
if ( ( V_2 & 0x7f ) != 0x01 )
V_1 -> V_5 = 0 ;
break;
case 2 :
F_5 ( V_4 , V_15 , ! ( V_1 -> V_2 [ 1 ] & 0x80 ) ) ;
F_4 ( V_4 , V_11 , V_1 -> V_2 [ 1 ] ) ;
F_4 ( V_4 , V_12 , V_1 -> V_2 [ 2 ] ) ;
F_6 ( V_4 ) ;
V_1 -> V_5 = 0 ;
break;
}
}
static T_1 F_10 ( struct V_8 * V_8 ,
unsigned char V_2 , unsigned int V_22 )
{
struct V_1 * V_1 = F_11 ( V_8 ) ;
switch ( V_1 -> V_21 ) {
case 0 :
F_1 ( V_1 , V_2 ) ;
break;
case 1 :
case 2 :
F_8 ( V_1 , V_2 ) ;
break;
case 3 :
F_9 ( V_1 , V_2 ) ;
break;
}
return V_23 ;
}
static int F_12 ( struct V_1 * V_1 , unsigned char * V_24 )
{
int V_25 = - 1 ;
int V_26 ;
unsigned char V_6 = 0xaa + V_7 ;
F_13 ( & V_1 -> V_27 ) ;
F_14 ( V_1 -> V_8 ) ;
V_1 -> V_9 = toupper ( V_24 [ 0 ] ) ;
F_15 ( & V_1 -> V_18 ) ;
F_16 ( V_1 -> V_8 ) ;
if ( F_17 ( V_1 -> V_8 , V_7 ) )
goto V_28;
for ( V_26 = 0 ; V_26 < V_20 ; V_26 ++ ) {
V_6 += V_24 [ V_26 ] ;
if ( F_17 ( V_1 -> V_8 , V_24 [ V_26 ] ) )
goto V_28;
}
if ( F_17 ( V_1 -> V_8 , V_6 ) )
goto V_28;
F_18 ( & V_1 -> V_18 , V_29 ) ;
if ( V_1 -> V_9 == V_10 ) {
memcpy ( V_24 , V_1 -> V_19 , V_20 ) ;
V_25 = 0 ;
}
V_28:
F_19 ( & V_1 -> V_27 ) ;
return V_25 ;
}
static int F_20 ( struct V_1 * V_1 )
{
static const char * V_30 [] = { L_4 , L_5 , L_6 , L_7 } ;
struct V_3 * V_4 = V_1 -> V_4 ;
unsigned char V_24 [ V_20 ] = { V_31 } ;
if ( F_12 ( V_1 , V_24 ) )
return - 1 ;
V_4 -> V_21 . V_32 = ( V_24 [ 5 ] << 8 ) | V_24 [ 4 ] ;
F_21 ( V_4 , V_11 , 96 , 4000 , 0 , 0 ) ;
F_21 ( V_4 , V_12 , 96 , 4000 , 0 , 0 ) ;
if ( V_24 [ 3 ] & V_13 )
F_21 ( V_4 , V_14 , 0 , 255 , 0 , 0 ) ;
F_22 ( & V_1 -> V_8 -> V_4 ,
L_8 ,
V_30 [ ( V_24 [ 1 ] - '0' ) & 0x03 ] ,
V_24 [ 5 ] , V_24 [ 4 ] , V_24 [ 3 ] , V_24 [ 7 ] ) ;
return 0 ;
}
static void F_23 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_11 ( V_8 ) ;
F_24 ( V_1 -> V_4 ) ;
F_25 ( V_1 -> V_4 ) ;
F_26 ( V_8 ) ;
F_27 ( V_8 , NULL ) ;
F_28 ( V_1 -> V_4 ) ;
F_29 ( V_1 ) ;
}
static int F_30 ( struct V_8 * V_8 , struct V_33 * V_34 )
{
struct V_1 * V_1 ;
struct V_3 * V_3 ;
int V_35 ;
V_1 = F_31 ( sizeof( struct V_1 ) , V_36 ) ;
V_3 = F_32 () ;
if ( ! V_1 || ! V_3 ) {
V_35 = - V_37 ;
goto V_38;
}
V_1 -> V_8 = V_8 ;
V_1 -> V_21 = V_8 -> V_21 . V_21 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_9 = V_10 ;
F_33 ( & V_1 -> V_27 ) ;
F_15 ( & V_1 -> V_18 ) ;
snprintf ( V_1 -> V_39 , sizeof( V_1 -> V_39 ) , L_9 , V_8 -> V_39 ) ;
V_3 -> V_40 = L_10 ;
V_3 -> V_39 = V_1 -> V_39 ;
V_3 -> V_21 . V_41 = V_42 ;
V_3 -> V_21 . V_43 = V_44 ;
V_3 -> V_21 . V_45 = V_1 -> V_21 ;
V_3 -> V_21 . V_32 = 0x0100 ;
V_3 -> V_4 . V_46 = & V_8 -> V_4 ;
V_3 -> V_47 [ 0 ] = F_34 ( V_48 ) | F_34 ( V_49 ) ;
V_3 -> V_50 [ F_35 ( V_15 ) ] = F_34 ( V_15 ) ;
F_27 ( V_8 , V_1 ) ;
V_35 = F_36 ( V_8 , V_34 ) ;
if ( V_35 )
goto V_51;
switch ( V_1 -> V_21 ) {
case 0 :
if ( F_20 ( V_1 ) )
goto V_52;
break;
case 1 :
F_21 ( V_3 , V_14 , 0 , 15 , 0 , 0 ) ;
case 2 :
F_21 ( V_3 , V_11 , 96 , 4000 , 0 , 0 ) ;
F_21 ( V_3 , V_12 , 96 , 4000 , 0 , 0 ) ;
break;
case 3 :
F_21 ( V_3 , V_11 , 0 , 255 , 0 , 0 ) ;
F_21 ( V_3 , V_12 , 0 , 255 , 0 , 0 ) ;
break;
}
V_35 = F_37 ( V_1 -> V_4 ) ;
if ( V_35 )
goto V_52;
return 0 ;
V_52: F_26 ( V_8 ) ;
V_51: F_27 ( V_8 , NULL ) ;
V_38: F_38 ( V_3 ) ;
F_29 ( V_1 ) ;
return V_35 ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_53 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_53 ) ;
}
