static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_9 [ V_6 ] ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_10 [ V_6 ] ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_11 [ V_6 ] ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_12 ,
char * V_5 )
{
int V_6 = F_2 ( V_12 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( V_8 -> V_13 >> V_6 ) & 1 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_12 ,
char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_8 -> V_13 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_15 * V_16 = F_9 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_16 ) ;
long V_9 = F_11 ( V_5 , NULL , 10 ) / 1000 ;
F_12 ( & V_8 -> V_17 ) ;
V_8 -> V_10 [ V_6 ] = F_13 ( V_9 , - 128 , 127 ) ;
if ( ! V_18 )
F_14 ( V_16 , F_15 ( V_6 ) ,
V_8 -> V_10 [ V_6 ] ) ;
F_16 ( & V_8 -> V_17 ) ;
return V_14 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_15 * V_16 = F_9 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_16 ) ;
long V_9 = F_11 ( V_5 , NULL , 10 ) / 1000 ;
F_12 ( & V_8 -> V_17 ) ;
V_8 -> V_11 [ V_6 ] = F_13 ( V_9 , - 128 , 127 ) ;
if ( ! V_18 )
F_14 ( V_16 , F_18 ( V_6 ) ,
V_8 -> V_11 [ V_6 ] ) ;
F_16 ( & V_8 -> V_17 ) ;
return V_14 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_19 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_15 * V_16 = F_9 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_16 ) ;
int V_19 = F_11 ( V_5 , NULL , 10 ) != 0 ;
F_12 ( & V_8 -> V_17 ) ;
if ( V_19 != V_8 -> V_19 ) {
int V_20 = F_21 (
V_16 , V_21 ) ;
V_8 -> V_19 = V_19 ;
F_14 ( V_16 , V_22 ,
( V_20 & 0xBF ) | ( V_19 << 6 ) ) ;
}
F_16 ( & V_8 -> V_17 ) ;
return V_14 ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_16 -> V_26 ;
const char * V_27 ;
int V_28 , V_29 , V_20 , V_30 , V_31 ;
if ( ! F_23 ( V_26 , V_32 ) ) {
F_24 ( L_3
L_4 ) ;
return - V_33 ;
}
V_29 = F_21 ( V_16 , V_34 ) ;
V_28 = F_21 ( V_16 ,
V_35 ) ;
V_20 = F_21 ( V_16 , V_21 ) ;
if ( ( V_29 & 0x03 ) || ( V_20 & 0x3F ) || ( V_28 & 0xF8 ) ) {
F_24 ( L_5 ) ;
return - V_33 ;
}
V_30 = F_21 ( V_16 , V_36 ) ;
V_31 = F_21 ( V_16 , V_37 ) ;
if ( V_30 == 0x4d && V_31 == 0x01 )
V_27 = L_6 ;
else if ( V_30 == 0x41 ) {
if ( ( V_31 & 0xF0 ) == 0x30 )
V_27 = L_7 ;
else
V_27 = L_8 ;
} else if ( V_30 == 0x49 )
V_27 = L_9 ;
else if ( V_30 == 0x23 )
V_27 = L_10 ;
else if ( V_30 == 0x54 )
V_27 = L_11 ;
else if ( V_28 == 0x00
&& ( V_20 & 0x7F ) == 0x00
&& ( V_29 & 0xAB ) == 0x00 )
V_27 = L_12 ;
else
V_27 = L_13 ;
F_24 ( L_14 ,
V_27 , F_25 ( V_26 ) , V_16 -> V_38 ) ;
F_26 ( V_24 -> type , V_27 , V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_15 * V_16 ,
const struct V_40 * V_41 )
{
struct V_7 * V_8 ;
int V_42 ;
V_8 = F_28 ( sizeof( struct V_7 ) , V_43 ) ;
if ( ! V_8 ) {
F_24 ( L_15 ) ;
V_42 = - V_44 ;
goto V_45;
}
F_29 ( V_16 , V_8 ) ;
V_8 -> type = V_41 -> V_46 ;
F_30 ( & V_8 -> V_17 ) ;
if ( V_8 -> type != V_47 && ! V_18 )
F_31 ( V_16 ) ;
if ( ( V_42 = F_32 ( & V_16 -> V_2 . V_48 , & V_49 ) ) )
goto V_50;
V_8 -> V_51 = F_33 ( & V_16 -> V_2 ) ;
if ( F_34 ( V_8 -> V_51 ) ) {
V_42 = F_35 ( V_8 -> V_51 ) ;
goto V_52;
}
return 0 ;
V_52:
F_36 ( & V_16 -> V_2 . V_48 , & V_49 ) ;
V_50:
F_37 ( V_8 ) ;
V_45:
return V_42 ;
}
static void F_31 ( struct V_15 * V_16 )
{
F_14 ( V_16 , V_22 ,
F_21 ( V_16 , V_21 ) & 0xBF ) ;
F_14 ( V_16 , V_53 , 0x04 ) ;
}
static int F_38 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = F_10 ( V_16 ) ;
F_39 ( V_8 -> V_51 ) ;
F_36 ( & V_16 -> V_2 . V_48 , & V_49 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
static struct V_7 * F_3 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_9 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_16 ) ;
F_12 ( & V_8 -> V_17 ) ;
if ( F_40 ( V_54 , V_8 -> V_55 + V_56 + V_56 / 2 )
|| ! V_8 -> V_57 ) {
int V_58 ;
F_41 ( & V_16 -> V_2 , L_16 ) ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
V_8 -> V_9 [ V_58 ] = 1000 *
( V_59 ) F_21 (
V_16 , F_42 ( V_58 ) ) ;
V_8 -> V_10 [ V_58 ] = 1000 *
( V_59 ) F_21 (
V_16 , F_43 ( V_58 ) ) ;
V_8 -> V_11 [ V_58 ] = 1000 *
( V_59 ) F_21 (
V_16 , F_44 ( V_58 ) ) ;
}
V_8 -> V_13 = F_21 ( V_16 ,
V_34 ) & 0x7c ;
if ( V_8 -> type == V_60 ) {
V_8 -> V_9 [ 1 ] += 125 * ( F_21 (
V_16 , V_61 ) >> 5 ) ;
V_8 -> V_10 [ 1 ] += 125 * ( F_21 (
V_16 , V_62 ) >> 5 ) ;
V_8 -> V_11 [ 1 ] += 125 * ( F_21 (
V_16 , V_63 ) >> 5 ) ;
V_8 -> V_64 =
F_21 ( V_16 ,
V_65 ) ;
V_8 -> V_66 =
F_21 ( V_16 ,
V_67 ) ;
}
V_8 -> V_55 = V_54 ;
V_8 -> V_57 = 1 ;
}
F_16 ( & V_8 -> V_17 ) ;
return V_8 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_68 ) ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_68 ) ;
}
