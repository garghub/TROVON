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
long V_9 ;
int V_17 ;
V_17 = F_11 ( V_5 , 10 , & V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 /= 1000 ;
F_12 ( & V_8 -> V_18 ) ;
V_8 -> V_10 [ V_6 ] = F_13 ( V_9 , - 128 , 127 ) ;
if ( ! V_19 )
F_14 ( V_16 , F_15 ( V_6 ) ,
V_8 -> V_10 [ V_6 ] ) ;
F_16 ( & V_8 -> V_18 ) ;
return V_14 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_15 * V_16 = F_9 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_16 ) ;
long V_9 ;
int V_17 ;
V_17 = F_11 ( V_5 , 10 , & V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 /= 1000 ;
F_12 ( & V_8 -> V_18 ) ;
V_8 -> V_11 [ V_6 ] = F_13 ( V_9 , - 128 , 127 ) ;
if ( ! V_19 )
F_14 ( V_16 , F_18 ( V_6 ) ,
V_8 -> V_11 [ V_6 ] ) ;
F_16 ( & V_8 -> V_18 ) ;
return V_14 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_20 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_15 * V_16 = F_9 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_16 ) ;
char V_20 ;
unsigned long V_21 ;
int V_17 ;
V_17 = F_21 ( V_5 , 10 , & V_21 ) ;
if ( V_17 )
return V_17 ;
V_20 = V_21 != 0 ;
F_12 ( & V_8 -> V_18 ) ;
if ( V_20 != V_8 -> V_20 ) {
int V_22 = F_22 (
V_16 , V_23 ) ;
V_8 -> V_20 = V_20 ;
F_14 ( V_16 , V_24 ,
( V_22 & 0xBF ) | ( V_20 << 6 ) ) ;
}
F_16 ( & V_8 -> V_18 ) ;
return V_14 ;
}
static int F_23 ( struct V_15 * V_16 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = V_16 -> V_28 ;
const char * V_29 ;
int V_30 , V_31 , V_22 , V_32 , V_33 ;
if ( ! F_24 ( V_28 , V_34 ) ) {
F_25 ( L_3
L_4 ) ;
return - V_35 ;
}
V_31 = F_22 ( V_16 , V_36 ) ;
V_30 = F_22 ( V_16 ,
V_37 ) ;
V_22 = F_22 ( V_16 , V_23 ) ;
if ( ( V_31 & 0x03 ) || ( V_22 & 0x3F ) || ( V_30 & 0xF8 ) ) {
F_25 ( L_5 ) ;
return - V_35 ;
}
V_32 = F_22 ( V_16 , V_38 ) ;
V_33 = F_22 ( V_16 , V_39 ) ;
if ( V_32 == 0x4d && V_33 == 0x01 )
V_29 = L_6 ;
else if ( V_32 == 0x41 ) {
if ( ( V_33 & 0xF0 ) == 0x30 )
V_29 = L_7 ;
else
V_29 = L_8 ;
} else if ( V_32 == 0x49 )
V_29 = L_9 ;
else if ( V_32 == 0x23 )
V_29 = L_10 ;
else if ( V_32 == 0x54 )
V_29 = L_11 ;
else if ( V_30 == 0x00
&& ( V_22 & 0x7F ) == 0x00
&& ( V_31 & 0xAB ) == 0x00 )
V_29 = L_12 ;
else
V_29 = L_13 ;
F_25 ( L_14 ,
V_29 , F_26 ( V_28 ) , V_16 -> V_40 ) ;
F_27 ( V_26 -> type , V_29 , V_41 ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 ,
const struct V_42 * V_43 )
{
struct V_7 * V_8 ;
int V_17 ;
V_8 = F_29 ( & V_16 -> V_2 , sizeof( struct V_7 ) ,
V_44 ) ;
if ( ! V_8 ) {
F_25 ( L_15 ) ;
return - V_45 ;
}
F_30 ( V_16 , V_8 ) ;
V_8 -> type = V_43 -> V_46 ;
F_31 ( & V_8 -> V_18 ) ;
if ( V_8 -> type != V_47 && ! V_19 )
F_32 ( V_16 ) ;
V_17 = F_33 ( & V_16 -> V_2 . V_48 , & V_49 ) ;
if ( V_17 )
return V_17 ;
V_8 -> V_50 = F_34 ( & V_16 -> V_2 ) ;
if ( F_35 ( V_8 -> V_50 ) ) {
V_17 = F_36 ( V_8 -> V_50 ) ;
goto error;
}
return 0 ;
error:
F_37 ( & V_16 -> V_2 . V_48 , & V_49 ) ;
return V_17 ;
}
static void F_32 ( struct V_15 * V_16 )
{
F_14 ( V_16 , V_24 ,
F_22 ( V_16 , V_23 ) & 0xBF ) ;
F_14 ( V_16 , V_51 , 0x04 ) ;
}
static int F_38 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = F_10 ( V_16 ) ;
F_39 ( V_8 -> V_50 ) ;
F_37 ( & V_16 -> V_2 . V_48 , & V_49 ) ;
return 0 ;
}
static struct V_7 * F_3 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_9 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_16 ) ;
F_12 ( & V_8 -> V_18 ) ;
if ( F_40 ( V_52 , V_8 -> V_53 + V_54 + V_54 / 2 )
|| ! V_8 -> V_55 ) {
int V_56 ;
F_41 ( & V_16 -> V_2 , L_16 ) ;
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
V_8 -> V_9 [ V_56 ] = 1000 *
( V_57 ) F_22 (
V_16 , F_42 ( V_56 ) ) ;
V_8 -> V_10 [ V_56 ] = 1000 *
( V_57 ) F_22 (
V_16 , F_43 ( V_56 ) ) ;
V_8 -> V_11 [ V_56 ] = 1000 *
( V_57 ) F_22 (
V_16 , F_44 ( V_56 ) ) ;
}
V_8 -> V_13 = F_22 ( V_16 ,
V_36 ) & 0x7c ;
if ( V_8 -> type == V_58 ) {
V_8 -> V_9 [ 1 ] += 125 * ( F_22 (
V_16 , V_59 ) >> 5 ) ;
V_8 -> V_10 [ 1 ] += 125 * ( F_22 (
V_16 , V_60 ) >> 5 ) ;
V_8 -> V_11 [ 1 ] += 125 * ( F_22 (
V_16 , V_61 ) >> 5 ) ;
V_8 -> V_62 =
F_22 ( V_16 ,
V_63 ) ;
V_8 -> V_64 =
F_22 ( V_16 ,
V_65 ) ;
}
V_8 -> V_53 = V_52 ;
V_8 -> V_55 = 1 ;
}
F_16 ( & V_8 -> V_18 ) ;
return V_8 ;
}
