static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
T_2 V_12 ;
if ( V_9 -> V_13 [ V_7 -> V_11 ] == 0
|| ( V_9 -> V_14 [ V_7 -> V_11 ] & 0xC0 ) == 0
|| V_9 -> V_13 [ V_7 -> V_11 ] == 255 ) {
return sprintf ( V_5 , L_2 ) ;
}
V_12 = 1880 * 120 / F_6 ( V_9 -> V_14 [ V_7 -> V_11 ] )
/ V_9 -> V_13 [ V_7 -> V_11 ] ;
return sprintf ( V_5 , L_1 , V_12 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( ( V_9 -> V_14 [ V_7 -> V_11 ] & 0xC0 ) == 0 )
return sprintf ( V_5 , L_2 ) ;
return sprintf ( V_5 , L_1 , F_6 ( V_9 -> V_14 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_3 V_15 )
{
struct V_16 * V_17 = F_9 ( V_2 ) ;
struct V_8 * V_9 = F_10 ( V_17 ) ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
T_4 V_18 ;
long V_12 ;
int V_19 = F_11 ( V_5 , 10 , & V_12 ) ;
if ( V_19 < 0 )
return V_19 ;
F_12 ( & V_9 -> V_20 ) ;
V_18 = F_13 ( V_17 ,
V_21 [ V_7 -> V_11 ] ) ;
switch ( V_12 ) {
case 1 :
V_12 = 1 ;
break;
case 2 :
V_12 = 2 ;
break;
case 4 :
V_12 = 3 ;
break;
default:
F_14 ( & V_9 -> V_20 ) ;
F_15 ( & V_17 -> V_2 , L_3
L_4 , V_12 ) ;
return - V_22 ;
}
V_18 = ( V_18 & 0x3F ) | ( V_12 << 6 ) ;
F_16 ( V_17 ,
V_21 [ V_7 -> V_11 ] , V_18 ) ;
F_14 ( & V_9 -> V_20 ) ;
return V_15 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_17 -> V_26 ;
T_4 V_27 , V_28 , V_29 , V_30 ;
if ( ! F_18 ( V_26 , V_31 ) )
return - V_32 ;
V_27 = F_13 ( V_17 , V_33 ) ;
V_28 = F_13 ( V_17 , V_34 ) ;
V_29 = F_13 ( V_17 ,
V_35 ) ;
V_30 = F_13 ( V_17 ,
V_36 ) ;
if ( V_27 != 0x41 || ( V_29 & 0xf9 ) != 0x01
|| V_30 != 0x03 )
return - V_32 ;
if ( ( V_28 & 0xF0 ) != 0x00 ) {
F_19 ( L_5
L_6 , V_28 ) ;
return - V_32 ;
}
F_20 ( V_24 -> type , L_7 , V_37 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 ,
const struct V_38 * V_39 )
{
struct V_8 * V_9 ;
int V_40 ;
V_9 = F_22 ( & V_17 -> V_2 , sizeof( struct V_8 ) ,
V_41 ) ;
if ( ! V_9 )
return - V_42 ;
F_23 ( V_17 , V_9 ) ;
F_24 ( & V_9 -> V_20 ) ;
if ( F_25 ( V_17 ) == 0 )
return - V_32 ;
V_40 = F_26 ( & V_17 -> V_2 . V_43 , & V_44 ) ;
if ( V_40 )
return V_40 ;
V_9 -> V_45 = F_27 ( & V_17 -> V_2 ) ;
if ( F_28 ( V_9 -> V_45 ) ) {
V_40 = F_29 ( V_9 -> V_45 ) ;
goto V_46;
}
return 0 ;
V_46:
F_30 ( & V_17 -> V_2 . V_43 , & V_44 ) ;
return V_40 ;
}
static int F_25 ( struct V_16 * V_17 )
{
T_4 V_47 ;
V_47 = F_13 ( V_17 , V_48 ) ;
if ( ( V_47 & 0x10 ) == 0 ) {
F_16 ( V_17 , V_48 ,
V_47 | 0x10 ) ;
}
V_47 = F_13 ( V_17 , V_48 ) ;
if ( ( V_47 & 0x10 ) == 0 ) {
F_15 ( & V_17 -> V_2 , L_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_31 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = F_10 ( V_17 ) ;
F_32 ( V_9 -> V_45 ) ;
F_30 ( & V_17 -> V_2 . V_43 , & V_44 ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_9 ( V_2 ) ;
struct V_8 * V_9 = F_10 ( V_17 ) ;
F_12 ( & V_9 -> V_20 ) ;
if ( F_33 ( V_49 , V_9 -> V_50 + V_51 * 2 )
|| ! V_9 -> V_52 ) {
int V_53 ;
F_34 ( & V_17 -> V_2 , L_9 ) ;
for ( V_53 = 0 ; V_53 < F_35 ( V_54 ) ; V_53 ++ ) {
V_9 -> V_10 [ V_53 ] =
F_13 ( V_17 ,
V_54 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < F_35 ( V_55 ) ; V_53 ++ ) {
V_9 -> V_13 [ V_53 ] =
F_13 ( V_17 ,
V_55 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < F_35 ( V_21 ) ; V_53 ++ ) {
V_9 -> V_14 [ V_53 ] =
F_13 ( V_17 ,
V_21 [ V_53 ] ) ;
}
V_9 -> V_50 = V_49 ;
V_9 -> V_52 = 1 ;
}
F_14 ( & V_9 -> V_20 ) ;
return V_9 ;
}
