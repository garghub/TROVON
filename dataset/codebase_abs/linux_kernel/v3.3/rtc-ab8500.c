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
if ( F_6 ( V_8 ) == 0 ) {
F_7 ( 1000 , 1000 ) ;
} else {
while ( F_8 ( V_10 , V_9 ) ) {
V_12 = F_9 ( V_8 ,
V_18 , V_19 , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_17 & V_20 ) )
break;
F_7 ( 1000 , 5000 ) ;
}
}
for ( V_13 = 0 ; V_13 < F_4 ( V_16 ) ; V_13 ++ ) {
V_12 = F_9 ( V_8 ,
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
F_10 ( V_2 , V_4 ) ;
return F_11 ( V_4 ) ;
}
static int F_12 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
int V_12 , V_13 ;
unsigned char V_15 [ F_4 ( V_16 ) ] ;
unsigned long V_23 , V_24 , V_2 = 0 ;
if ( V_4 -> V_5 < ( V_22 - 1900 ) ) {
F_13 ( V_8 , L_1 ,
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
static int F_14 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_12 , V_13 ;
T_1 V_29 , V_17 ;
unsigned char V_15 [ F_4 ( V_30 ) ] ;
unsigned long V_2 , V_14 ;
V_12 = F_9 ( V_8 , V_18 ,
V_31 , & V_29 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_29 & V_32 )
V_28 -> V_33 = 1 ;
else
V_28 -> V_33 = 0 ;
V_28 -> V_34 = 0 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_30 ) ; V_13 ++ ) {
V_12 = F_9 ( V_8 , V_18 ,
V_30 [ V_13 ] , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 [ V_13 ] = V_17 ;
}
V_14 = ( V_15 [ 0 ] << 16 ) | ( V_15 [ 1 ] << 8 ) | ( V_15 [ 2 ] ) ;
V_2 = V_14 * 60 ;
V_2 += F_1 ( V_22 ) ;
F_10 ( V_2 , & V_28 -> time ) ;
return F_11 ( & V_28 -> time ) ;
}
static int F_15 ( struct V_7 * V_8 , unsigned int V_33 )
{
return F_16 ( V_8 , V_18 ,
V_31 , V_32 ,
V_33 ? V_32 : 0 ) ;
}
static int F_17 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_12 , V_13 ;
unsigned char V_15 [ F_4 ( V_30 ) ] ;
unsigned long V_14 , V_2 = 0 ;
if ( V_28 -> time . V_5 < ( V_22 - 1900 ) ) {
F_13 ( V_8 , L_1 ,
V_22 ) ;
return - V_25 ;
}
F_2 ( & V_28 -> time , & V_2 ) ;
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
return F_15 ( V_8 , V_28 -> V_33 ) ;
}
static int F_18 ( struct V_7 * V_8 , int V_35 )
{
int V_12 ;
T_1 V_36 = 0 ;
if ( ( V_35 < - 127 ) || ( V_35 > 127 ) ) {
F_19 ( V_8 , L_2 ) ;
return - V_25 ;
}
if ( V_35 >= 0 )
V_36 = 0x7F & V_35 ;
else
V_36 = ~ ( V_35 - 1 ) | 0x80 ;
V_12 = F_5 ( V_8 , V_18 ,
V_37 , V_36 ) ;
return V_12 ;
}
static int F_20 ( struct V_7 * V_8 , int * V_35 )
{
int V_12 ;
T_1 V_36 = 0 ;
V_12 = F_9 ( V_8 , V_18 ,
V_37 , & V_36 ) ;
if ( V_12 >= 0 ) {
if ( V_36 & 0x80 )
* V_35 = 0 - ( V_36 & 0x7F ) ;
else
* V_35 = 0x7F & V_36 ;
}
return V_12 ;
}
static T_2 F_21 ( struct V_7 * V_8 ,
struct V_38 * V_39 ,
const char * V_15 , T_3 V_40 )
{
int V_12 ;
int V_35 = 0 ;
if ( sscanf ( V_15 , L_3 , & V_35 ) != 1 ) {
F_19 ( V_8 , L_4 ) ;
return - V_25 ;
}
V_12 = F_18 ( V_8 , V_35 ) ;
return V_12 ? V_12 : V_40 ;
}
static T_2 F_22 ( struct V_7 * V_8 ,
struct V_38 * V_39 , char * V_15 )
{
int V_12 = 0 ;
int V_35 = 0 ;
V_12 = F_20 ( V_8 , & V_35 ) ;
if ( V_12 < 0 ) {
F_19 ( V_8 , L_5 ) ;
sprintf ( V_15 , L_6 ) ;
return V_12 ;
}
return sprintf ( V_15 , L_7 , V_35 ) ;
}
static int F_23 ( struct V_7 * V_8 )
{
return F_24 ( V_8 , & V_41 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
F_26 ( V_8 , & V_41 ) ;
}
static T_4 F_27 ( int V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
unsigned long V_46 = V_47 | V_48 ;
F_13 ( & V_45 -> V_8 , L_8 , V_49 ) ;
F_28 ( V_45 , 1 , V_46 ) ;
return V_50 ;
}
static int T_5 F_29 ( struct V_51 * V_52 )
{
int V_53 ;
struct V_44 * V_45 ;
T_1 V_29 ;
int V_42 ;
V_42 = F_30 ( V_52 , L_9 ) ;
if ( V_42 < 0 )
return V_42 ;
V_53 = F_16 ( & V_52 -> V_8 , V_18 ,
V_31 , V_54 , V_54 ) ;
if ( V_53 < 0 )
return V_53 ;
F_7 ( 1000 , 5000 ) ;
V_53 = F_9 ( & V_52 -> V_8 , V_18 ,
V_31 , & V_29 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( ! ( V_29 & V_54 ) ) {
F_19 ( & V_52 -> V_8 , L_10 ) ;
return - V_55 ;
}
F_31 ( & V_52 -> V_8 , true ) ;
V_45 = F_32 ( L_11 , & V_52 -> V_8 , & V_56 ,
V_57 ) ;
if ( F_33 ( V_45 ) ) {
F_19 ( & V_52 -> V_8 , L_12 ) ;
V_53 = F_34 ( V_45 ) ;
return V_53 ;
}
V_53 = F_35 ( V_42 , NULL , F_27 ,
V_58 , L_11 , V_45 ) ;
if ( V_53 < 0 ) {
F_36 ( V_45 ) ;
return V_53 ;
}
F_37 ( V_52 , V_45 ) ;
V_53 = F_23 ( & V_52 -> V_8 ) ;
if ( V_53 ) {
F_19 ( & V_52 -> V_8 , L_13 ) ;
return V_53 ;
}
return 0 ;
}
static int T_6 F_38 ( struct V_51 * V_52 )
{
struct V_44 * V_45 = F_39 ( V_52 ) ;
int V_42 = F_30 ( V_52 , L_9 ) ;
F_25 ( & V_52 -> V_8 ) ;
F_40 ( V_42 , V_45 ) ;
F_36 ( V_45 ) ;
F_37 ( V_52 , NULL ) ;
return 0 ;
}
