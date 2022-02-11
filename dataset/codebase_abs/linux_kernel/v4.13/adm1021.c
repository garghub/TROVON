static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( & V_4 -> V_7 ) ;
if ( F_4 ( V_8 , V_4 -> V_9 + V_10 + V_10 / 2 )
|| ! V_4 -> V_11 ) {
int V_12 ;
F_5 ( V_3 , L_1 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_4 -> V_13 [ V_12 ] = 1000 *
( V_14 ) F_6 (
V_6 , F_7 ( V_12 ) ) ;
V_4 -> V_15 [ V_12 ] = 1000 *
( V_14 ) F_6 (
V_6 , F_8 ( V_12 ) ) ;
if ( V_4 -> type != V_16 ) {
V_4 -> V_17 [ V_12 ] = 1000 *
( V_14 ) F_6 ( V_6 ,
F_9 ( V_12 ) ) ;
}
}
V_4 -> V_18 = F_6 ( V_6 ,
V_19 ) & 0x7c ;
if ( V_4 -> type == V_20 ) {
V_4 -> V_13 [ 1 ] += 125 * ( F_6 (
V_6 , V_21 ) >> 5 ) ;
V_4 -> V_15 [ 1 ] += 125 * ( F_6 (
V_6 , V_22 ) >> 5 ) ;
V_4 -> V_17 [ 1 ] += 125 * ( F_6 (
V_6 , V_23 ) >> 5 ) ;
V_4 -> V_24 =
F_6 ( V_6 ,
V_25 ) ;
V_4 -> V_26 =
F_6 ( V_6 ,
V_27 ) ;
}
V_4 -> V_9 = V_8 ;
V_4 -> V_11 = 1 ;
}
F_10 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_28 * V_29 , char * V_30 )
{
int V_31 = F_12 ( V_29 ) -> V_31 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_30 , L_2 , V_4 -> V_13 [ V_31 ] ) ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_28 * V_29 , char * V_30 )
{
int V_31 = F_12 ( V_29 ) -> V_31 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_30 , L_2 , V_4 -> V_15 [ V_31 ] ) ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_28 * V_29 , char * V_30 )
{
int V_31 = F_12 ( V_29 ) -> V_31 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_30 , L_2 , V_4 -> V_17 [ V_31 ] ) ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_28 * V_32 ,
char * V_30 )
{
int V_31 = F_12 ( V_32 ) -> V_31 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_30 , L_3 , ( V_4 -> V_18 >> V_31 ) & 1 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 ,
struct V_28 * V_32 ,
char * V_30 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_30 , L_3 , V_4 -> V_18 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
struct V_28 * V_29 ,
const char * V_30 , T_2 V_33 )
{
int V_31 = F_12 ( V_29 ) -> V_31 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_13 ;
int V_34 , V_35 ;
V_35 = F_18 ( V_30 , 10 , & V_13 ) ;
if ( V_35 )
return V_35 ;
V_13 /= 1000 ;
F_3 ( & V_4 -> V_7 ) ;
V_34 = F_19 ( V_13 , - 128 , 127 ) ;
V_4 -> V_15 [ V_31 ] = V_34 * 1000 ;
if ( ! V_36 )
F_20 ( V_6 , F_21 ( V_31 ) ,
V_34 ) ;
F_10 ( & V_4 -> V_7 ) ;
return V_33 ;
}
static T_1 F_22 ( struct V_2 * V_3 ,
struct V_28 * V_29 ,
const char * V_30 , T_2 V_33 )
{
int V_31 = F_12 ( V_29 ) -> V_31 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_13 ;
int V_34 , V_35 ;
V_35 = F_18 ( V_30 , 10 , & V_13 ) ;
if ( V_35 )
return V_35 ;
V_13 /= 1000 ;
F_3 ( & V_4 -> V_7 ) ;
V_34 = F_19 ( V_13 , - 128 , 127 ) ;
V_4 -> V_17 [ V_31 ] = V_34 * 1000 ;
if ( ! V_36 )
F_20 ( V_6 , F_23 ( V_31 ) ,
V_34 ) ;
F_10 ( & V_4 -> V_7 ) ;
return V_33 ;
}
static T_1 F_24 ( struct V_2 * V_3 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_30 , L_2 , V_4 -> V_37 ) ;
}
static T_1 F_25 ( struct V_2 * V_3 ,
struct V_28 * V_29 ,
const char * V_30 , T_2 V_33 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
char V_37 ;
unsigned long V_38 ;
int V_35 ;
V_35 = F_26 ( V_30 , 10 , & V_38 ) ;
if ( V_35 )
return V_35 ;
V_37 = V_38 != 0 ;
F_3 ( & V_4 -> V_7 ) ;
if ( V_37 != V_4 -> V_37 ) {
int V_39 = F_6 (
V_6 , V_40 ) ;
V_4 -> V_37 = V_37 ;
F_20 ( V_6 , V_41 ,
( V_39 & 0xBF ) | ( V_37 << 6 ) ) ;
}
F_10 ( & V_4 -> V_7 ) ;
return V_33 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_6 -> V_45 ;
const char * V_46 ;
int V_47 , V_48 , V_39 , V_49 , V_50 ;
if ( ! F_28 ( V_45 , V_51 ) ) {
F_29 ( L_4 ) ;
return - V_52 ;
}
V_48 = F_6 ( V_6 , V_19 ) ;
V_47 = F_6 ( V_6 ,
V_53 ) ;
V_39 = F_6 ( V_6 , V_40 ) ;
if ( ( V_48 & 0x03 ) || ( V_39 & 0x3F ) || ( V_47 & 0xF8 ) ) {
F_29 ( L_5 ) ;
return - V_52 ;
}
V_49 = F_6 ( V_6 , V_54 ) ;
V_50 = F_6 ( V_6 , V_55 ) ;
if ( V_49 < 0 || V_50 < 0 )
return - V_52 ;
if ( V_49 == 0x4d && V_50 == 0x01 )
V_46 = L_6 ;
else if ( V_49 == 0x41 ) {
if ( ( V_50 & 0xF0 ) == 0x30 )
V_46 = L_7 ;
else if ( ( V_50 & 0xF0 ) == 0x00 )
V_46 = L_8 ;
else
return - V_52 ;
} else if ( V_49 == 0x49 )
V_46 = L_9 ;
else if ( V_49 == 0x23 )
V_46 = L_10 ;
else if ( V_49 == 0x54 )
V_46 = L_11 ;
else {
int V_56 , V_57 , V_58 , V_59 , V_60 , V_61 ;
V_60 = F_6 ( V_6 , F_9 ( 0 ) ) ;
V_61 = F_6 ( V_6 , F_9 ( 1 ) ) ;
if ( V_60 < 0 || V_61 < 0 )
return - V_52 ;
V_56 = F_6 ( V_6 , F_7 ( 0 ) ) ;
V_57 = F_6 ( V_6 , F_7 ( 1 ) ) ;
V_58 = F_6 ( V_6 , F_8 ( 0 ) ) ;
V_59 = F_6 ( V_6 , F_8 ( 1 ) ) ;
if ( ( V_14 ) V_56 < 0 || ( V_14 ) V_57 < 0 || ( V_14 ) V_58 < 0 || ( V_14 ) V_59 < 0 )
return - V_52 ;
if ( V_56 == V_57 && V_56 == V_58 && V_56 == V_59 && V_56 == V_60
&& V_56 == V_61 )
return - V_52 ;
if ( V_47 == 0x00
&& ( V_39 & 0x7F ) == 0x00
&& ( V_48 & 0xAB ) == 0x00 ) {
V_46 = L_12 ;
} else {
if ( ( V_14 ) V_60 > V_58 || ( V_14 ) V_61 > V_59 )
return - V_52 ;
V_46 = L_13 ;
}
}
F_29 ( L_14 ,
V_46 , F_30 ( V_45 ) , V_6 -> V_62 ) ;
F_31 ( V_43 -> type , V_46 , V_63 ) ;
return 0 ;
}
static void F_32 ( struct V_5 * V_6 )
{
F_20 ( V_6 , V_41 ,
F_6 ( V_6 , V_40 ) & 0xBF ) ;
F_20 ( V_6 , V_64 , 0x04 ) ;
}
static int F_33 ( struct V_5 * V_6 ,
const struct V_65 * V_66 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_67 ;
V_4 = F_34 ( V_3 , sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_4 )
return - V_69 ;
V_4 -> V_6 = V_6 ;
V_4 -> type = V_66 -> V_70 ;
F_35 ( & V_4 -> V_7 ) ;
if ( V_4 -> type != V_16 && ! V_36 )
F_32 ( V_6 ) ;
V_4 -> V_71 [ 0 ] = & V_72 ;
if ( V_4 -> type != V_16 )
V_4 -> V_71 [ 1 ] = & V_73 ;
V_67 = F_36 ( V_3 , V_6 -> V_74 ,
V_4 , V_4 -> V_71 ) ;
return F_37 ( V_67 ) ;
}
