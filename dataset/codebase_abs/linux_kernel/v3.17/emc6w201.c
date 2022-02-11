static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_4 , V_5 ;
V_4 = F_2 ( V_2 , V_3 ) ;
V_5 = F_2 ( V_2 , V_3 + 1 ) ;
if ( F_3 ( V_4 < 0 || V_5 < 0 ) ) {
F_4 ( & V_2 -> V_6 , L_1 ,
16 , L_2 , V_3 ) ;
return 0xFFFF ;
}
return ( V_5 << 8 ) | V_4 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_7 )
{
int V_8 ;
V_8 = F_6 ( V_2 , V_3 , V_7 & 0xff ) ;
if ( F_7 ( ! V_8 ) )
V_8 = F_6 ( V_2 , V_3 + 1 , V_7 >> 8 ) ;
if ( F_3 ( V_8 < 0 ) )
F_4 ( & V_2 -> V_6 , L_1 ,
16 , L_3 , V_3 ) ;
return V_8 ;
}
static T_2 F_8 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_7 ;
V_7 = F_2 ( V_2 , V_3 ) ;
if ( F_3 ( V_7 < 0 ) ) {
F_4 ( & V_2 -> V_6 , L_1 ,
8 , L_2 , V_3 ) ;
return 0x00 ;
}
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_7 )
{
int V_8 ;
V_8 = F_6 ( V_2 , V_3 , V_7 ) ;
if ( F_3 ( V_8 < 0 ) )
F_4 ( & V_2 -> V_6 , L_1 ,
8 , L_3 , V_3 ) ;
return V_8 ;
}
static struct V_9 * F_10 ( struct V_10 * V_6 )
{
struct V_9 * V_11 = F_11 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_12 ;
F_12 ( & V_11 -> V_13 ) ;
if ( F_13 ( V_14 , V_11 -> V_15 + V_16 ) || ! V_11 -> V_17 ) {
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
V_11 -> V_18 [ V_19 ] [ V_12 ] =
F_8 ( V_2 ,
F_14 ( V_12 ) ) ;
V_11 -> V_18 [ V_20 ] [ V_12 ] =
F_8 ( V_2 ,
F_15 ( V_12 ) ) ;
V_11 -> V_18 [ V_21 ] [ V_12 ] =
F_8 ( V_2 ,
F_16 ( V_12 ) ) ;
}
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
V_11 -> V_22 [ V_19 ] [ V_12 ] =
F_8 ( V_2 ,
F_17 ( V_12 ) ) ;
V_11 -> V_22 [ V_20 ] [ V_12 ] =
F_8 ( V_2 ,
F_18 ( V_12 ) ) ;
V_11 -> V_22 [ V_21 ] [ V_12 ] =
F_8 ( V_2 ,
F_19 ( V_12 ) ) ;
}
for ( V_12 = 0 ; V_12 < 5 ; V_12 ++ ) {
V_11 -> V_23 [ V_19 ] [ V_12 ] =
F_1 ( V_2 ,
F_20 ( V_12 ) ) ;
V_11 -> V_23 [ V_20 ] [ V_12 ] =
F_1 ( V_2 ,
F_21 ( V_12 ) ) ;
}
V_11 -> V_15 = V_14 ;
V_11 -> V_17 = 1 ;
}
F_22 ( & V_11 -> V_13 ) ;
return V_11 ;
}
static T_3 F_23 ( struct V_10 * V_6 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_9 * V_11 = F_10 ( V_6 ) ;
int V_27 = F_24 ( V_25 ) -> V_28 ;
int V_12 = F_24 ( V_25 ) -> V_12 ;
return sprintf ( V_26 , L_4 ,
( unsigned ) V_11 -> V_18 [ V_27 ] [ V_12 ] * V_29 [ V_12 ] / 0xC0 ) ;
}
static T_3 F_25 ( struct V_10 * V_6 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_30 )
{
struct V_9 * V_11 = F_11 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_27 = F_24 ( V_25 ) -> V_28 ;
int V_12 = F_24 ( V_25 ) -> V_12 ;
int V_8 ;
long V_7 ;
T_2 V_3 ;
V_8 = F_26 ( V_26 , 10 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 = F_27 ( V_7 * 0xC0 , V_29 [ V_12 ] ) ;
V_3 = ( V_27 == V_20 ) ? F_15 ( V_12 )
: F_16 ( V_12 ) ;
F_12 ( & V_11 -> V_13 ) ;
V_11 -> V_18 [ V_27 ] [ V_12 ] = F_28 ( V_7 , 0 , 255 ) ;
V_8 = F_9 ( V_2 , V_3 , V_11 -> V_18 [ V_27 ] [ V_12 ] ) ;
F_22 ( & V_11 -> V_13 ) ;
return V_8 < 0 ? V_8 : V_30 ;
}
static T_3 F_29 ( struct V_10 * V_6 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_9 * V_11 = F_10 ( V_6 ) ;
int V_27 = F_24 ( V_25 ) -> V_28 ;
int V_12 = F_24 ( V_25 ) -> V_12 ;
return sprintf ( V_26 , L_5 , ( int ) V_11 -> V_22 [ V_27 ] [ V_12 ] * 1000 ) ;
}
static T_3 F_30 ( struct V_10 * V_6 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_30 )
{
struct V_9 * V_11 = F_11 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_27 = F_24 ( V_25 ) -> V_28 ;
int V_12 = F_24 ( V_25 ) -> V_12 ;
int V_8 ;
long V_7 ;
T_2 V_3 ;
V_8 = F_26 ( V_26 , 10 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 = F_27 ( V_7 , 1000 ) ;
V_3 = ( V_27 == V_20 ) ? F_18 ( V_12 )
: F_19 ( V_12 ) ;
F_12 ( & V_11 -> V_13 ) ;
V_11 -> V_22 [ V_27 ] [ V_12 ] = F_28 ( V_7 , - 127 , 127 ) ;
V_8 = F_9 ( V_2 , V_3 , V_11 -> V_22 [ V_27 ] [ V_12 ] ) ;
F_22 ( & V_11 -> V_13 ) ;
return V_8 < 0 ? V_8 : V_30 ;
}
static T_3 F_31 ( struct V_10 * V_6 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_9 * V_11 = F_10 ( V_6 ) ;
int V_27 = F_24 ( V_25 ) -> V_28 ;
int V_12 = F_24 ( V_25 ) -> V_12 ;
unsigned V_31 ;
if ( V_11 -> V_23 [ V_27 ] [ V_12 ] == 0 || V_11 -> V_23 [ V_27 ] [ V_12 ] == 0xFFFF )
V_31 = 0 ;
else
V_31 = 5400000U / V_11 -> V_23 [ V_27 ] [ V_12 ] ;
return sprintf ( V_26 , L_4 , V_31 ) ;
}
static T_3 F_32 ( struct V_10 * V_6 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_30 )
{
struct V_9 * V_11 = F_11 ( V_6 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_27 = F_24 ( V_25 ) -> V_28 ;
int V_12 = F_24 ( V_25 ) -> V_12 ;
int V_8 ;
unsigned long V_7 ;
V_8 = F_33 ( V_26 , 10 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_7 == 0 ) {
V_7 = 0xFFFF ;
} else {
V_7 = F_27 ( 5400000U , V_7 ) ;
V_7 = F_28 ( V_7 , 0 , 0xFFFE ) ;
}
F_12 ( & V_11 -> V_13 ) ;
V_11 -> V_23 [ V_27 ] [ V_12 ] = V_7 ;
V_8 = F_5 ( V_2 , F_21 ( V_12 ) ,
V_11 -> V_23 [ V_27 ] [ V_12 ] ) ;
F_22 ( & V_11 -> V_13 ) ;
return V_8 < 0 ? V_8 : V_30 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
int V_36 , V_37 , V_38 ;
if ( ! F_35 ( V_35 , V_39 ) )
return - V_40 ;
V_36 = F_2 ( V_2 , V_41 ) ;
if ( V_36 != 0x5C )
return - V_40 ;
V_37 = F_2 ( V_2 , V_42 ) ;
if ( V_37 < 0 || ( V_37 & 0xF0 ) != 0xB0 )
return - V_40 ;
if ( ( V_37 & 0x0F ) > 2 ) {
F_36 ( & V_2 -> V_6 , L_6 ,
V_37 & 0x0F ) ;
return - V_40 ;
}
V_38 = F_2 ( V_2 , V_43 ) ;
if ( V_38 < 0 || ( V_38 & 0xF4 ) != 0x04 )
return - V_40 ;
if ( ! ( V_38 & 0x01 ) ) {
F_4 ( & V_2 -> V_6 , L_7 ) ;
return - V_40 ;
}
F_37 ( V_33 -> type , L_8 , V_44 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_10 * V_6 = & V_2 -> V_6 ;
struct V_9 * V_11 ;
struct V_10 * V_47 ;
V_11 = F_39 ( V_6 , sizeof( struct V_9 ) , V_48 ) ;
if ( ! V_11 )
return - V_49 ;
V_11 -> V_2 = V_2 ;
F_40 ( & V_11 -> V_13 ) ;
V_47 = F_41 ( V_6 , V_2 -> V_50 ,
V_11 ,
V_51 ) ;
return F_42 ( V_47 ) ;
}
