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
struct V_7 * V_8 = F_9 ( V_2 ) ;
struct V_15 * V_16 = V_8 -> V_16 ;
long V_9 ;
int V_17 , V_18 ;
V_18 = F_10 ( V_5 , 10 , & V_9 ) ;
if ( V_18 )
return V_18 ;
V_9 /= 1000 ;
F_11 ( & V_8 -> V_19 ) ;
V_17 = F_12 ( V_9 , - 128 , 127 ) ;
V_8 -> V_10 [ V_6 ] = V_17 * 1000 ;
if ( ! V_20 )
F_13 ( V_16 , F_14 ( V_6 ) ,
V_17 ) ;
F_15 ( & V_8 -> V_19 ) ;
return V_14 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_9 ( V_2 ) ;
struct V_15 * V_16 = V_8 -> V_16 ;
long V_9 ;
int V_17 , V_18 ;
V_18 = F_10 ( V_5 , 10 , & V_9 ) ;
if ( V_18 )
return V_18 ;
V_9 /= 1000 ;
F_11 ( & V_8 -> V_19 ) ;
V_17 = F_12 ( V_9 , - 128 , 127 ) ;
V_8 -> V_11 [ V_6 ] = V_17 * 1000 ;
if ( ! V_20 )
F_13 ( V_16 , F_17 ( V_6 ) ,
V_17 ) ;
F_15 ( & V_8 -> V_19 ) ;
return V_14 ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_21 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_7 * V_8 = F_9 ( V_2 ) ;
struct V_15 * V_16 = V_8 -> V_16 ;
char V_21 ;
unsigned long V_22 ;
int V_18 ;
V_18 = F_20 ( V_5 , 10 , & V_22 ) ;
if ( V_18 )
return V_18 ;
V_21 = V_22 != 0 ;
F_11 ( & V_8 -> V_19 ) ;
if ( V_21 != V_8 -> V_21 ) {
int V_23 = F_21 (
V_16 , V_24 ) ;
V_8 -> V_21 = V_21 ;
F_13 ( V_16 , V_25 ,
( V_23 & 0xBF ) | ( V_21 << 6 ) ) ;
}
F_15 ( & V_8 -> V_19 ) ;
return V_14 ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_16 -> V_29 ;
const char * V_30 ;
int V_31 , V_32 , V_23 , V_33 , V_34 ;
if ( ! F_23 ( V_29 , V_35 ) ) {
F_24 ( L_3 ) ;
return - V_36 ;
}
V_32 = F_21 ( V_16 , V_37 ) ;
V_31 = F_21 ( V_16 ,
V_38 ) ;
V_23 = F_21 ( V_16 , V_24 ) ;
if ( ( V_32 & 0x03 ) || ( V_23 & 0x3F ) || ( V_31 & 0xF8 ) ) {
F_24 ( L_4 ) ;
return - V_36 ;
}
V_33 = F_21 ( V_16 , V_39 ) ;
V_34 = F_21 ( V_16 , V_40 ) ;
if ( V_33 < 0 || V_34 < 0 )
return - V_36 ;
if ( V_33 == 0x4d && V_34 == 0x01 )
V_30 = L_5 ;
else if ( V_33 == 0x41 ) {
if ( ( V_34 & 0xF0 ) == 0x30 )
V_30 = L_6 ;
else if ( ( V_34 & 0xF0 ) == 0x00 )
V_30 = L_7 ;
else
return - V_36 ;
} else if ( V_33 == 0x49 )
V_30 = L_8 ;
else if ( V_33 == 0x23 )
V_30 = L_9 ;
else if ( V_33 == 0x54 )
V_30 = L_10 ;
else {
int V_41 , V_42 , V_43 , V_44 , V_45 , V_46 ;
V_45 = F_21 ( V_16 , F_25 ( 0 ) ) ;
V_46 = F_21 ( V_16 , F_25 ( 1 ) ) ;
if ( V_45 < 0 || V_46 < 0 )
return - V_36 ;
V_41 = F_21 ( V_16 , F_26 ( 0 ) ) ;
V_42 = F_21 ( V_16 , F_26 ( 1 ) ) ;
V_43 = F_21 ( V_16 , F_27 ( 0 ) ) ;
V_44 = F_21 ( V_16 , F_27 ( 1 ) ) ;
if ( ( V_47 ) V_41 < 0 || ( V_47 ) V_42 < 0 || ( V_47 ) V_43 < 0 || ( V_47 ) V_44 < 0 )
return - V_36 ;
if ( V_41 == V_42 && V_41 == V_43 && V_41 == V_44 && V_41 == V_45
&& V_41 == V_46 )
return - V_36 ;
if ( V_31 == 0x00
&& ( V_23 & 0x7F ) == 0x00
&& ( V_32 & 0xAB ) == 0x00 ) {
V_30 = L_11 ;
} else {
if ( ( V_47 ) V_45 > V_43 || ( V_47 ) V_46 > V_44 )
return - V_36 ;
V_30 = L_12 ;
}
}
F_24 ( L_13 ,
V_30 , F_28 ( V_29 ) , V_16 -> V_48 ) ;
F_29 ( V_27 -> type , V_30 , V_49 ) ;
return 0 ;
}
static int F_30 ( struct V_15 * V_16 ,
const struct V_50 * V_51 )
{
struct V_1 * V_2 = & V_16 -> V_2 ;
struct V_7 * V_8 ;
struct V_1 * V_52 ;
V_8 = F_31 ( V_2 , sizeof( struct V_7 ) , V_53 ) ;
if ( ! V_8 )
return - V_54 ;
V_8 -> V_16 = V_16 ;
V_8 -> type = V_51 -> V_55 ;
F_32 ( & V_8 -> V_19 ) ;
if ( V_8 -> type != V_56 && ! V_20 )
F_33 ( V_16 ) ;
V_8 -> V_57 [ 0 ] = & V_58 ;
if ( V_8 -> type != V_56 )
V_8 -> V_57 [ 1 ] = & V_59 ;
V_52 = F_34 ( V_2 , V_16 -> V_60 ,
V_8 , V_8 -> V_57 ) ;
return F_35 ( V_52 ) ;
}
static void F_33 ( struct V_15 * V_16 )
{
F_13 ( V_16 , V_25 ,
F_21 ( V_16 , V_24 ) & 0xBF ) ;
F_13 ( V_16 , V_61 , 0x04 ) ;
}
static struct V_7 * F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_9 ( V_2 ) ;
struct V_15 * V_16 = V_8 -> V_16 ;
F_11 ( & V_8 -> V_19 ) ;
if ( F_36 ( V_62 , V_8 -> V_63 + V_64 + V_64 / 2 )
|| ! V_8 -> V_65 ) {
int V_66 ;
F_37 ( V_2 , L_14 ) ;
for ( V_66 = 0 ; V_66 < 2 ; V_66 ++ ) {
V_8 -> V_9 [ V_66 ] = 1000 *
( V_47 ) F_21 (
V_16 , F_26 ( V_66 ) ) ;
V_8 -> V_10 [ V_66 ] = 1000 *
( V_47 ) F_21 (
V_16 , F_27 ( V_66 ) ) ;
if ( V_8 -> type != V_56 ) {
V_8 -> V_11 [ V_66 ] = 1000 *
( V_47 ) F_21 ( V_16 ,
F_25 ( V_66 ) ) ;
}
}
V_8 -> V_13 = F_21 ( V_16 ,
V_37 ) & 0x7c ;
if ( V_8 -> type == V_67 ) {
V_8 -> V_9 [ 1 ] += 125 * ( F_21 (
V_16 , V_68 ) >> 5 ) ;
V_8 -> V_10 [ 1 ] += 125 * ( F_21 (
V_16 , V_69 ) >> 5 ) ;
V_8 -> V_11 [ 1 ] += 125 * ( F_21 (
V_16 , V_70 ) >> 5 ) ;
V_8 -> V_71 =
F_21 ( V_16 ,
V_72 ) ;
V_8 -> V_73 =
F_21 ( V_16 ,
V_74 ) ;
}
V_8 -> V_63 = V_62 ;
V_8 -> V_65 = 1 ;
}
F_15 ( & V_8 -> V_19 ) ;
return V_8 ;
}
