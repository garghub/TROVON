static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
if ( * V_4 >= 253 &&
V_3 [ 0x96 ] == 0xbc && V_3 [ 0x97 ] == 0xff &&
V_3 [ 0xca ] == 0xbc && V_3 [ 0xcb ] == 0xff &&
V_3 [ 0xe1 ] == 0xbc && V_3 [ 0xe2 ] == 0xff ) {
F_2 ( V_2 ,
L_1 ) ;
V_3 [ 0x96 ] = V_3 [ 0xca ] = V_3 [ 0xe1 ] = 0x0c ;
V_3 [ 0x97 ] = V_3 [ 0xcb ] = V_3 [ 0xe2 ] = 0x00 ;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
int V_13 ;
struct V_14 * V_15 = F_4 ( V_2 ) ;
V_15 -> V_16 = V_6 -> V_17 ;
if ( ( V_10 -> V_18 & V_19 ) != V_20 )
return 0 ;
F_5 ( L_2 ,
V_10 -> V_18 & V_21 ) ;
switch ( V_10 -> V_18 & V_21 ) {
case 0x10 :
F_6 ( V_22 ) ;
break;
case 0x30 :
F_6 ( V_23 ) ;
break;
case 0x70 :
F_6 ( V_24 ) ;
break;
case 0x04 :
F_6 ( V_25 ) ;
break;
case 0x0d :
F_6 ( V_26 ) ;
break;
case 0x25 :
F_6 ( V_27 ) ;
break;
case 0x47 :
F_6 ( V_28 ) ;
break;
case 0x49 :
F_6 ( V_29 ) ;
break;
case 0x4a :
F_6 ( V_30 ) ;
break;
case 0x48 :
F_6 ( V_31 ) ;
break;
case 0x24 :
F_6 ( V_32 ) ;
break;
case 0x32 :
F_6 ( V_33 ) ;
break;
default:
return 0 ;
}
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
V_15 -> V_34 [ V_13 ] = 0 ;
return 1 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_35 * V_36 ,
T_2 * V_37 , int V_38 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
int V_39 = 0 ;
unsigned V_40 ;
unsigned short V_41 ;
if ( V_36 -> V_42 == V_37 [ 0 ] ) {
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
V_40 = V_15 -> V_34 [ V_41 ] ;
if ( V_40 ) {
F_8 ( V_15 -> V_16 , V_43 , V_40 , 0 ) ;
V_15 -> V_34 [ V_41 ] = 0 ;
}
}
V_40 = 0 ;
switch ( V_36 -> V_42 ) {
case 0x02 :
case 0x03 :
switch ( V_37 [ 1 ] ) {
case 0x10 :
V_40 = V_22 ;
V_41 = 0 ;
break;
case 0x30 :
V_40 = V_23 ;
V_41 = 1 ;
break;
case 0x70 :
V_40 = V_24 ;
V_41 = 2 ;
break;
case 0x04 :
V_40 = V_25 ;
V_41 = 3 ;
break;
}
if ( V_40 ) {
F_8 ( V_15 -> V_16 , V_43 , V_40 , 1 ) ;
V_15 -> V_34 [ V_41 ] = V_40 ;
}
V_39 = 1 ;
break;
}
}
return V_39 ;
}
static int F_9 ( struct V_1 * V_2 , const struct V_44 * V_42 )
{
int V_39 ;
struct V_14 * V_15 ;
V_15 = F_10 ( sizeof( * V_15 ) , V_45 ) ;
if ( V_15 == NULL ) {
F_11 ( V_2 , L_3 ) ;
return - V_46 ;
}
F_12 ( V_2 , V_15 ) ;
V_39 = F_13 ( V_2 ) ;
if ( V_39 ) {
F_11 ( V_2 , L_4 ) ;
goto V_47;
}
V_39 = F_14 ( V_2 , V_48 ) ;
if ( V_39 ) {
F_11 ( V_2 , L_5 ) ;
goto V_47;
}
return 0 ;
V_47:
F_15 ( V_15 ) ;
return V_39 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
F_17 ( V_2 ) ;
if ( NULL != V_15 )
F_15 ( V_15 ) ;
}
static int T_3 F_18 ( void )
{
return F_19 ( & V_49 ) ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_49 ) ;
}
