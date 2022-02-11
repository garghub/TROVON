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
V_23 -> V_27 = V_28 ;
V_23 -> V_29 = V_30 | V_31 ;
return 0 ;
}
static int F_12 ( struct V_20 * V_20 , void * V_21 ,
struct V_32 * V_23 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
if ( V_23 -> V_33 > 0 )
return - V_34 ;
F_11 ( V_23 -> V_35 , L_4 , sizeof( V_23 -> V_35 ) ) ;
V_23 -> type = V_36 ;
V_23 -> V_37 = 87 * 16000 ;
V_23 -> V_38 = 108 * 16000 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = V_42 ;
V_23 -> V_43 = V_44 ;
V_23 -> signal = 0xFFFF * F_8 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_20 , void * V_21 ,
struct V_32 * V_23 )
{
return V_23 -> V_33 ? - V_34 : 0 ;
}
static int F_15 ( struct V_20 * V_20 , void * V_21 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
if ( V_46 -> V_47 != 0 || V_46 -> type != V_36 )
return - V_34 ;
F_7 ( V_2 , V_46 -> V_48 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_20 , void * V_21 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
if ( V_46 -> V_47 != 0 )
return - V_34 ;
V_46 -> type = V_36 ;
V_46 -> V_48 = V_2 -> V_16 ;
return 0 ;
}
static int F_17 ( struct V_20 * V_20 , void * V_21 ,
struct V_49 * V_50 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_18 ( V_51 ) ; V_4 ++ ) {
if ( V_50 -> V_52 && V_50 -> V_52 == V_51 [ V_4 ] . V_52 ) {
memcpy ( V_50 , & ( V_51 [ V_4 ] ) , sizeof( * V_50 ) ) ;
return 0 ;
}
}
return - V_34 ;
}
static int F_19 ( struct V_20 * V_20 , void * V_21 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
switch ( V_54 -> V_52 ) {
case V_55 :
if ( V_2 -> V_7 )
V_54 -> V_56 = 1 ;
else
V_54 -> V_56 = 0 ;
return 0 ;
case V_57 :
V_54 -> V_56 = V_2 -> V_9 * 6554 ;
return 0 ;
}
return - V_34 ;
}
static int F_20 ( struct V_20 * V_20 , void * V_21 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
switch ( V_54 -> V_52 ) {
case V_55 :
if ( V_54 -> V_56 )
F_5 ( V_2 ) ;
else
F_6 ( V_2 , V_2 -> V_9 ) ;
return 0 ;
case V_57 :
F_6 ( V_2 , V_54 -> V_56 ) ;
return 0 ;
}
return - V_34 ;
}
static int F_21 ( struct V_20 * V_58 , void * V_21 , unsigned int * V_4 )
{
* V_4 = 0 ;
return 0 ;
}
static int F_22 ( struct V_20 * V_58 , void * V_21 , unsigned int V_4 )
{
return V_4 ? - V_34 : 0 ;
}
static int F_23 ( struct V_20 * V_20 , void * V_21 ,
struct V_59 * V_60 )
{
V_60 -> V_33 = 0 ;
F_11 ( V_60 -> V_35 , L_5 , sizeof( V_60 -> V_35 ) ) ;
V_60 -> V_41 = V_61 ;
return 0 ;
}
static int F_24 ( struct V_20 * V_20 , void * V_21 ,
struct V_59 * V_60 )
{
return V_60 -> V_33 ? - V_34 : 0 ;
}
static int T_1 F_25 ( void )
{
struct V_1 * V_2 = & V_62 ;
struct V_63 * V_64 = & V_2 -> V_64 ;
int V_65 ;
F_11 ( V_64 -> V_35 , L_6 , sizeof( V_64 -> V_35 ) ) ;
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_6 == - 1 ) {
F_26 ( V_64 , L_7 ) ;
return - V_34 ;
}
if ( ! F_27 ( V_2 -> V_6 , 2 , L_6 ) ) {
F_26 ( V_64 , L_8 , V_6 ) ;
return - V_66 ;
}
V_65 = F_28 ( NULL , V_64 ) ;
if ( V_65 < 0 ) {
F_29 ( V_2 -> V_6 , 2 ) ;
F_26 ( V_64 , L_9 ) ;
return V_65 ;
}
F_11 ( V_2 -> V_67 . V_35 , V_64 -> V_35 , sizeof( V_2 -> V_67 . V_35 ) ) ;
V_2 -> V_67 . V_64 = V_64 ;
V_2 -> V_67 . V_68 = & V_69 ;
V_2 -> V_67 . V_70 = & V_71 ;
V_2 -> V_67 . V_72 = V_73 ;
F_30 ( & V_2 -> V_67 , V_2 ) ;
F_31 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , 0 ) ;
if ( F_32 ( & V_2 -> V_67 , V_74 , V_75 ) < 0 ) {
F_33 ( & V_2 -> V_64 ) ;
F_29 ( V_2 -> V_6 , 2 ) ;
return - V_34 ;
}
F_34 ( V_64 , L_10 ) ;
return 0 ;
}
static void T_2 F_35 ( void )
{
struct V_1 * V_2 = & V_62 ;
struct V_63 * V_64 = & V_2 -> V_64 ;
F_36 ( & V_2 -> V_67 ) ;
F_33 ( & V_2 -> V_64 ) ;
F_29 ( V_2 -> V_6 , 2 ) ;
F_34 ( V_64 , L_11 ) ;
}
