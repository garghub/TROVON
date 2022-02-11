static unsigned long F_1 ( int V_1 )
{
unsigned long V_2 ;
struct V_3 V_4 = {
. V_5 = V_1 - 1900 ,
. V_6 = 1 ,
} ;
F_2 ( & V_4 , & V_2 ) ;
return V_2 ;
}
static int F_3 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
unsigned long V_9 = V_10 + V_11 ;
int V_12 , V_13 ;
unsigned long V_14 , V_2 ;
unsigned char V_15 [ F_4 ( V_16 ) ] ;
T_1 V_17 ;
V_12 = F_5 ( V_8 ,
V_18 , V_19 , V_20 ) ;
if ( V_12 < 0 )
return V_12 ;
while ( F_6 ( V_10 , V_9 ) ) {
V_12 = F_7 ( V_8 ,
V_18 , V_19 , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_17 & V_20 ) )
break;
F_8 ( 1000 , 5000 ) ;
}
for ( V_13 = 0 ; V_13 < F_4 ( V_16 ) ; V_13 ++ ) {
V_12 = F_7 ( V_8 ,
V_18 , V_16 [ V_13 ] , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 [ V_13 ] = V_17 ;
}
V_14 = ( V_15 [ 0 ] << 16 ) | ( V_15 [ 1 ] << 8 ) | V_15 [ 2 ] ;
V_2 = ( V_15 [ 3 ] << 8 ) | V_15 [ 4 ] ;
V_2 = V_2 / V_21 ;
V_2 = V_2 + ( V_14 * 60 ) ;
V_2 += F_1 ( V_22 ) ;
F_9 ( V_2 , V_4 ) ;
return F_10 ( V_4 ) ;
}
static int F_11 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
int V_12 , V_13 ;
unsigned char V_15 [ F_4 ( V_16 ) ] ;
unsigned long V_23 , V_24 , V_2 = 0 ;
if ( V_4 -> V_5 < ( V_22 - 1900 ) ) {
F_12 ( V_8 , L_1 ,
V_22 ) ;
return - V_25 ;
}
F_2 ( V_4 , & V_2 ) ;
V_2 -= F_1 ( V_22 ) ;
V_24 = V_2 / 60 ;
V_23 = V_2 % 60 ;
V_23 = V_23 * V_21 ;
V_15 [ 4 ] = V_23 & 0xFF ;
V_15 [ 3 ] = ( V_23 >> 8 ) & 0xFF ;
V_15 [ 2 ] = V_24 & 0xFF ;
V_15 [ 1 ] = ( V_24 >> 8 ) & 0xFF ;
V_15 [ 0 ] = ( V_24 >> 16 ) & 0xFF ;
for ( V_13 = 0 ; V_13 < F_4 ( V_16 ) ; V_13 ++ ) {
V_12 = F_5 ( V_8 , V_18 ,
V_16 [ V_13 ] , V_15 [ V_13 ] ) ;
if ( V_12 < 0 )
return V_12 ;
}
return F_5 ( V_8 , V_18 ,
V_19 , V_26 ) ;
}
static int F_13 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_12 , V_13 ;
T_1 V_29 , V_17 ;
unsigned char V_15 [ F_4 ( V_30 ) ] ;
unsigned long V_2 , V_14 ;
V_12 = F_7 ( V_8 , V_18 ,
V_31 , & V_29 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_29 & V_32 )
V_28 -> V_33 = 1 ;
else
V_28 -> V_33 = 0 ;
V_28 -> V_34 = 0 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_30 ) ; V_13 ++ ) {
V_12 = F_7 ( V_8 , V_18 ,
V_30 [ V_13 ] , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 [ V_13 ] = V_17 ;
}
V_14 = ( V_15 [ 0 ] << 16 ) | ( V_15 [ 1 ] << 8 ) | ( V_15 [ 2 ] ) ;
V_2 = V_14 * 60 ;
V_2 += F_1 ( V_22 ) ;
F_9 ( V_2 , & V_28 -> time ) ;
return F_10 ( & V_28 -> time ) ;
}
static int F_14 ( struct V_7 * V_8 , unsigned int V_33 )
{
return F_15 ( V_8 , V_18 ,
V_31 , V_32 ,
V_33 ? V_32 : 0 ) ;
}
static int F_16 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_12 , V_13 ;
unsigned char V_15 [ F_4 ( V_30 ) ] ;
unsigned long V_14 , V_2 = 0 , V_35 = 0 ;
struct V_3 V_36 ;
if ( V_28 -> time . V_5 < ( V_22 - 1900 ) ) {
F_12 ( V_8 , L_1 ,
V_22 ) ;
return - V_25 ;
}
F_2 ( & V_28 -> time , & V_2 ) ;
F_3 ( V_8 , & V_36 ) ;
F_2 ( & V_36 , & V_35 ) ;
if ( ( V_2 - V_35 ) < 59 ) {
F_12 ( V_8 , L_2 ) ;
return - V_25 ;
}
V_2 -= F_1 ( V_22 ) ;
V_14 = V_2 / 60 ;
V_15 [ 2 ] = V_14 & 0xFF ;
V_15 [ 1 ] = ( V_14 >> 8 ) & 0xFF ;
V_15 [ 0 ] = ( V_14 >> 16 ) & 0xFF ;
for ( V_13 = 0 ; V_13 < F_4 ( V_30 ) ; V_13 ++ ) {
V_12 = F_5 ( V_8 , V_18 ,
V_30 [ V_13 ] , V_15 [ V_13 ] ) ;
if ( V_12 < 0 )
return V_12 ;
}
return F_14 ( V_8 , V_28 -> V_33 ) ;
}
static int F_17 ( struct V_7 * V_8 , int V_37 )
{
int V_12 ;
T_1 V_38 = 0 ;
if ( ( V_37 < - 127 ) || ( V_37 > 127 ) ) {
F_18 ( V_8 , L_3 ) ;
return - V_25 ;
}
if ( V_37 >= 0 )
V_38 = 0x7F & V_37 ;
else
V_38 = ~ ( V_37 - 1 ) | 0x80 ;
V_12 = F_5 ( V_8 , V_18 ,
V_39 , V_38 ) ;
return V_12 ;
}
static int F_19 ( struct V_7 * V_8 , int * V_37 )
{
int V_12 ;
T_1 V_38 = 0 ;
V_12 = F_7 ( V_8 , V_18 ,
V_39 , & V_38 ) ;
if ( V_12 >= 0 ) {
if ( V_38 & 0x80 )
* V_37 = 0 - ( V_38 & 0x7F ) ;
else
* V_37 = 0x7F & V_38 ;
}
return V_12 ;
}
static T_2 F_20 ( struct V_7 * V_8 ,
struct V_40 * V_41 ,
const char * V_15 , T_3 V_42 )
{
int V_12 ;
int V_37 = 0 ;
if ( sscanf ( V_15 , L_4 , & V_37 ) != 1 ) {
F_18 ( V_8 , L_5 ) ;
return - V_25 ;
}
V_12 = F_17 ( V_8 , V_37 ) ;
return V_12 ? V_12 : V_42 ;
}
static T_2 F_21 ( struct V_7 * V_8 ,
struct V_40 * V_41 , char * V_15 )
{
int V_12 = 0 ;
int V_37 = 0 ;
V_12 = F_19 ( V_8 , & V_37 ) ;
if ( V_12 < 0 ) {
F_18 ( V_8 , L_6 ) ;
sprintf ( V_15 , L_7 ) ;
return V_12 ;
}
return sprintf ( V_15 , L_8 , V_37 ) ;
}
static int F_22 ( struct V_7 * V_8 )
{
return F_23 ( V_8 , & V_43 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
F_25 ( V_8 , & V_43 ) ;
}
static T_4 F_26 ( int V_44 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
unsigned long V_48 = V_49 | V_50 ;
F_12 ( & V_47 -> V_8 , L_9 , V_51 ) ;
F_27 ( V_47 , 1 , V_48 ) ;
return V_52 ;
}
static int F_28 ( struct V_53 * V_54 )
{
int V_55 ;
struct V_46 * V_47 ;
T_1 V_29 ;
int V_44 ;
V_44 = F_29 ( V_54 , L_10 ) ;
if ( V_44 < 0 )
return V_44 ;
V_55 = F_15 ( & V_54 -> V_8 , V_18 ,
V_31 , V_56 , V_56 ) ;
if ( V_55 < 0 )
return V_55 ;
F_8 ( 1000 , 5000 ) ;
V_55 = F_7 ( & V_54 -> V_8 , V_18 ,
V_31 , & V_29 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! ( V_29 & V_56 ) ) {
F_18 ( & V_54 -> V_8 , L_11 ) ;
return - V_57 ;
}
F_30 ( & V_54 -> V_8 , true ) ;
V_47 = F_31 ( L_12 , & V_54 -> V_8 , & V_58 ,
V_59 ) ;
if ( F_32 ( V_47 ) ) {
F_18 ( & V_54 -> V_8 , L_13 ) ;
V_55 = F_33 ( V_47 ) ;
return V_55 ;
}
V_55 = F_34 ( V_44 , NULL , F_26 ,
V_60 | V_61 , L_12 , V_47 ) ;
if ( V_55 < 0 ) {
F_35 ( V_47 ) ;
return V_55 ;
}
F_36 ( V_54 , V_47 ) ;
V_55 = F_22 ( & V_54 -> V_8 ) ;
if ( V_55 ) {
F_18 ( & V_54 -> V_8 , L_14 ) ;
return V_55 ;
}
return 0 ;
}
static int F_37 ( struct V_53 * V_54 )
{
struct V_46 * V_47 = F_38 ( V_54 ) ;
int V_44 = F_29 ( V_54 , L_10 ) ;
F_24 ( & V_54 -> V_8 ) ;
F_39 ( V_44 , V_47 ) ;
F_35 ( V_47 ) ;
F_36 ( V_54 , NULL ) ;
return 0 ;
}
