static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_3 = V_3 + ( V_3 * 32 ) ;
F_2 ( & V_2 -> V_5 ) ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
if ( V_3 & ( 0x80 >> V_4 ) )
F_3 ( 0x80 , V_2 -> V_6 + 1 ) ;
else
F_3 ( 0x00 , V_2 -> V_6 + 1 ) ;
}
F_4 ( & V_2 -> V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_7 = 1 ;
F_1 ( V_2 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_8 )
{
if ( V_8 == V_2 -> V_9 ) {
if ( V_2 -> V_7 ) {
V_2 -> V_7 = 0 ;
F_1 ( V_2 , V_8 ) ;
}
return 0 ;
}
if ( V_8 == 0 ) {
F_1 ( V_2 , 0 ) ;
V_2 -> V_9 = V_8 ;
return 0 ;
}
V_2 -> V_7 = 0 ;
F_1 ( V_2 , V_8 ) ;
V_2 -> V_9 = V_8 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long V_10 )
{
int V_11 ;
int V_4 ;
int V_12 ;
int V_13 ;
long V_14 ;
unsigned char V_15 [ 25 ] ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_16 = V_10 ;
V_11 = V_10 / 160 ;
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
V_14 = V_11 * 10 + 10700 ;
V_4 = 13 ;
V_12 = 10 ;
V_13 = 102400 ;
while ( V_14 != 0 ) {
if ( V_14 % V_13 == V_14 )
V_15 [ V_4 ] = 0 ;
else {
V_15 [ V_4 ] = 1 ;
V_14 = V_14 - V_13 ;
}
V_4 -- ;
V_12 -- ;
V_13 = V_13 / 2 ;
}
for ( V_4 = 24 ; V_4 > - 1 ; V_4 -- ) {
if ( V_15 [ V_4 ] == 1 ) {
F_3 ( V_17 | V_18 , V_2 -> V_6 ) ;
F_3 ( V_17 | V_18 | V_19 , V_2 -> V_6 ) ;
F_3 ( V_17 | V_18 , V_2 -> V_6 ) ;
} else {
F_3 ( V_17 | 0x00 , V_2 -> V_6 ) ;
F_3 ( V_17 | 0x00 | V_19 , V_2 -> V_6 ) ;
}
}
F_3 ( 0x00 , V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 -> V_6 ) & 2 )
return 0 ;
return 1 ;
}
static int F_10 ( struct V_20 * V_20 , void * V_21 ,
struct V_22 * V_23 )
{
F_11 ( V_23 -> V_24 , L_1 , sizeof( V_23 -> V_24 ) ) ;
F_11 ( V_23 -> V_25 , L_2 , sizeof( V_23 -> V_25 ) ) ;
F_11 ( V_23 -> V_26 , L_3 , sizeof( V_23 -> V_26 ) ) ;
V_23 -> V_27 = V_28 | V_29 ;
return 0 ;
}
static int F_12 ( struct V_20 * V_20 , void * V_21 ,
struct V_30 * V_23 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
if ( V_23 -> V_31 > 0 )
return - V_32 ;
F_11 ( V_23 -> V_33 , L_4 , sizeof( V_23 -> V_33 ) ) ;
V_23 -> type = V_34 ;
V_23 -> V_35 = 87 * 16000 ;
V_23 -> V_36 = 108 * 16000 ;
V_23 -> V_37 = V_38 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = V_42 ;
V_23 -> signal = 0xFFFF * F_8 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_20 , void * V_21 ,
struct V_30 * V_23 )
{
return V_23 -> V_31 ? - V_32 : 0 ;
}
static int F_15 ( struct V_20 * V_20 , void * V_21 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
if ( V_44 -> V_45 != 0 || V_44 -> type != V_34 )
return - V_32 ;
F_7 ( V_2 , V_44 -> V_46 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_20 , void * V_21 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
if ( V_44 -> V_45 != 0 )
return - V_32 ;
V_44 -> type = V_34 ;
V_44 -> V_46 = V_2 -> V_16 ;
return 0 ;
}
static int F_17 ( struct V_20 * V_20 , void * V_21 ,
struct V_47 * V_48 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_18 ( V_49 ) ; V_4 ++ ) {
if ( V_48 -> V_50 && V_48 -> V_50 == V_49 [ V_4 ] . V_50 ) {
memcpy ( V_48 , & ( V_49 [ V_4 ] ) , sizeof( * V_48 ) ) ;
return 0 ;
}
}
return - V_32 ;
}
static int F_19 ( struct V_20 * V_20 , void * V_21 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
switch ( V_52 -> V_50 ) {
case V_53 :
if ( V_2 -> V_7 )
V_52 -> V_54 = 1 ;
else
V_52 -> V_54 = 0 ;
return 0 ;
case V_55 :
V_52 -> V_54 = V_2 -> V_9 * 6554 ;
return 0 ;
}
return - V_32 ;
}
static int F_20 ( struct V_20 * V_20 , void * V_21 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
switch ( V_52 -> V_50 ) {
case V_53 :
if ( V_52 -> V_54 )
F_5 ( V_2 ) ;
else
F_6 ( V_2 , V_2 -> V_9 ) ;
return 0 ;
case V_55 :
F_6 ( V_2 , V_52 -> V_54 ) ;
return 0 ;
}
return - V_32 ;
}
static int F_21 ( struct V_20 * V_56 , void * V_21 , unsigned int * V_4 )
{
* V_4 = 0 ;
return 0 ;
}
static int F_22 ( struct V_20 * V_56 , void * V_21 , unsigned int V_4 )
{
return V_4 ? - V_32 : 0 ;
}
static int F_23 ( struct V_20 * V_20 , void * V_21 ,
struct V_57 * V_58 )
{
V_58 -> V_31 = 0 ;
F_11 ( V_58 -> V_33 , L_5 , sizeof( V_58 -> V_33 ) ) ;
V_58 -> V_39 = V_59 ;
return 0 ;
}
static int F_24 ( struct V_20 * V_20 , void * V_21 ,
struct V_57 * V_58 )
{
return V_58 -> V_31 ? - V_32 : 0 ;
}
static int T_1 F_25 ( void )
{
struct V_1 * V_2 = & V_60 ;
struct V_61 * V_62 = & V_2 -> V_62 ;
int V_63 ;
F_11 ( V_62 -> V_33 , L_6 , sizeof( V_62 -> V_33 ) ) ;
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_6 == - 1 ) {
F_26 ( V_62 , L_7 ) ;
return - V_32 ;
}
if ( ! F_27 ( V_2 -> V_6 , 2 , L_6 ) ) {
F_26 ( V_62 , L_8 , V_6 ) ;
return - V_64 ;
}
V_63 = F_28 ( NULL , V_62 ) ;
if ( V_63 < 0 ) {
F_29 ( V_2 -> V_6 , 2 ) ;
F_26 ( V_62 , L_9 ) ;
return V_63 ;
}
F_11 ( V_2 -> V_65 . V_33 , V_62 -> V_33 , sizeof( V_2 -> V_65 . V_33 ) ) ;
V_2 -> V_65 . V_62 = V_62 ;
V_2 -> V_65 . V_66 = & V_67 ;
V_2 -> V_65 . V_68 = & V_69 ;
V_2 -> V_65 . V_70 = V_71 ;
F_30 ( & V_2 -> V_65 , V_2 ) ;
F_31 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , 0 ) ;
if ( F_32 ( & V_2 -> V_65 , V_72 , V_73 ) < 0 ) {
F_33 ( & V_2 -> V_62 ) ;
F_29 ( V_2 -> V_6 , 2 ) ;
return - V_32 ;
}
F_34 ( V_62 , L_10 ) ;
return 0 ;
}
static void T_2 F_35 ( void )
{
struct V_1 * V_2 = & V_60 ;
struct V_61 * V_62 = & V_2 -> V_62 ;
F_36 ( & V_2 -> V_65 ) ;
F_33 ( & V_2 -> V_62 ) ;
F_29 ( V_2 -> V_6 , 2 ) ;
F_34 ( V_62 , L_11 ) ;
}
