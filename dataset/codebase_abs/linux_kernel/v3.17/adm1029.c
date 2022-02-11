static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( & V_4 -> V_7 ) ;
if ( F_4 ( V_8 , V_4 -> V_9 + V_10 * 2 )
|| ! V_4 -> V_11 ) {
int V_12 ;
F_5 ( & V_6 -> V_3 , L_1 ) ;
for ( V_12 = 0 ; V_12 < F_6 ( V_13 ) ; V_12 ++ ) {
V_4 -> V_14 [ V_12 ] =
F_7 ( V_6 ,
V_13 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < F_6 ( V_15 ) ; V_12 ++ ) {
V_4 -> V_16 [ V_12 ] =
F_7 ( V_6 ,
V_15 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < F_6 ( V_17 ) ; V_12 ++ ) {
V_4 -> V_18 [ V_12 ] =
F_7 ( V_6 ,
V_17 [ V_12 ] ) ;
}
V_4 -> V_9 = V_8 ;
V_4 -> V_11 = 1 ;
}
F_8 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static T_1
F_9 ( struct V_2 * V_3 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_10 ( V_20 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_21 , L_2 , F_11 ( V_4 -> V_14 [ V_23 -> V_24 ] ) ) ;
}
static T_1
F_12 ( struct V_2 * V_3 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_10 ( V_20 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_25 ;
if ( V_4 -> V_16 [ V_23 -> V_24 ] == 0
|| ( V_4 -> V_18 [ V_23 -> V_24 ] & 0xC0 ) == 0
|| V_4 -> V_16 [ V_23 -> V_24 ] == 255 ) {
return sprintf ( V_21 , L_3 ) ;
}
V_25 = 1880 * 120 / F_13 ( V_4 -> V_18 [ V_23 -> V_24 ] )
/ V_4 -> V_16 [ V_23 -> V_24 ] ;
return sprintf ( V_21 , L_2 , V_25 ) ;
}
static T_1
F_14 ( struct V_2 * V_3 , struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_10 ( V_20 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ( V_4 -> V_18 [ V_23 -> V_24 ] & 0xC0 ) == 0 )
return sprintf ( V_21 , L_3 ) ;
return sprintf ( V_21 , L_2 , F_13 ( V_4 -> V_18 [ V_23 -> V_24 ] ) ) ;
}
static T_1 F_15 ( struct V_2 * V_3 ,
struct V_19 * V_20 , const char * V_21 , T_3 V_26 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_22 * V_23 = F_10 ( V_20 ) ;
T_4 V_27 ;
long V_25 ;
int V_28 = F_16 ( V_21 , 10 , & V_25 ) ;
if ( V_28 < 0 )
return V_28 ;
F_3 ( & V_4 -> V_7 ) ;
V_27 = F_7 ( V_6 ,
V_17 [ V_23 -> V_24 ] ) ;
switch ( V_25 ) {
case 1 :
V_25 = 1 ;
break;
case 2 :
V_25 = 2 ;
break;
case 4 :
V_25 = 3 ;
break;
default:
F_8 ( & V_4 -> V_7 ) ;
F_17 ( & V_6 -> V_3 ,
L_4 ,
V_25 ) ;
return - V_29 ;
}
V_27 = ( V_27 & 0x3F ) | ( V_25 << 6 ) ;
V_4 -> V_18 [ V_23 -> V_24 ] = V_27 ;
F_18 ( V_6 ,
V_17 [ V_23 -> V_24 ] , V_27 ) ;
F_8 ( & V_4 -> V_7 ) ;
return V_26 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_6 -> V_33 ;
T_4 V_34 , V_35 , V_36 , V_37 ;
if ( ! F_20 ( V_33 , V_38 ) )
return - V_39 ;
V_34 = F_7 ( V_6 , V_40 ) ;
V_35 = F_7 ( V_6 , V_41 ) ;
V_36 = F_7 ( V_6 ,
V_42 ) ;
V_37 = F_7 ( V_6 ,
V_43 ) ;
if ( V_34 != 0x41 || ( V_36 & 0xf9 ) != 0x01
|| V_37 != 0x03 )
return - V_39 ;
if ( ( V_35 & 0xF0 ) != 0x00 ) {
F_21 ( L_5 ,
V_35 ) ;
return - V_39 ;
}
F_22 ( V_31 -> type , L_6 , V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 )
{
T_4 V_45 ;
V_45 = F_7 ( V_6 , V_46 ) ;
if ( ( V_45 & 0x10 ) == 0 ) {
F_18 ( V_6 , V_46 ,
V_45 | 0x10 ) ;
}
V_45 = F_7 ( V_6 , V_46 ) ;
if ( ( V_45 & 0x10 ) == 0 ) {
F_17 ( & V_6 -> V_3 , L_7 ) ;
return 0 ;
}
return 1 ;
}
static int F_24 ( struct V_5 * V_6 ,
const struct V_47 * V_48 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_49 ;
V_4 = F_25 ( V_3 , sizeof( struct V_1 ) , V_50 ) ;
if ( ! V_4 )
return - V_51 ;
V_4 -> V_6 = V_6 ;
F_26 ( & V_4 -> V_7 ) ;
if ( F_23 ( V_6 ) == 0 )
return - V_39 ;
V_49 = F_27 ( V_3 , V_6 -> V_52 ,
V_4 ,
V_53 ) ;
return F_28 ( V_49 ) ;
}
