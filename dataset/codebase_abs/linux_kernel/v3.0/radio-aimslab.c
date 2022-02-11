static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x58 , V_2 -> V_3 ) ;
F_3 ( 100 ) ;
F_2 ( 0xd8 , V_2 -> V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( 0x98 , V_2 -> V_3 ) ;
F_3 ( 100 ) ;
F_2 ( 0xd8 , V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_4 = 1 ;
F_6 ( & V_2 -> V_5 ) ;
F_2 ( 0xd0 , V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_6 )
{
int V_7 ;
F_6 ( & V_2 -> V_5 ) ;
if ( V_6 == V_2 -> V_8 ) {
if ( V_2 -> V_4 ) {
V_2 -> V_4 = 0 ;
F_2 ( 0xd8 , V_2 -> V_3 ) ;
}
F_7 ( & V_2 -> V_5 ) ;
return 0 ;
}
if ( V_6 == 0 ) {
F_2 ( 0x48 , V_2 -> V_3 ) ;
F_3 ( 2000 ) ;
F_2 ( 0xd0 , V_2 -> V_3 ) ;
V_2 -> V_8 = 0 ;
F_7 ( & V_2 -> V_5 ) ;
return 0 ;
}
V_2 -> V_4 = 0 ;
if ( V_6 > V_2 -> V_8 )
for ( V_7 = V_2 -> V_8 ; V_7 < V_6 ; V_7 ++ )
F_4 ( V_2 ) ;
else
for ( V_7 = V_2 -> V_8 ; V_7 > V_6 ; V_7 -- )
F_1 ( V_2 ) ;
V_2 -> V_8 = V_6 ;
F_7 ( & V_2 -> V_5 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == 0 || V_2 -> V_4 ) {
F_10 ( 128 + 64 + 16 + 1 , V_2 -> V_3 ) ;
F_10 ( 128 + 64 + 16 + 2 + 1 , V_2 -> V_3 ) ;
}
else {
F_10 ( 128 + 64 + 16 + 8 + 1 , V_2 -> V_3 ) ;
F_10 ( 128 + 64 + 16 + 8 + 2 + 1 , V_2 -> V_3 ) ;
}
F_3 ( 1 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == 0 || V_2 -> V_4 ) {
F_10 ( 128 + 64 + 16 + 4 + 1 , V_2 -> V_3 ) ;
F_10 ( 128 + 64 + 16 + 4 + 2 + 1 , V_2 -> V_3 ) ;
}
else {
F_10 ( 128 + 64 + 16 + 8 + 4 + 1 , V_2 -> V_3 ) ;
F_10 ( 128 + 64 + 16 + 8 + 4 + 2 + 1 , V_2 -> V_3 ) ;
}
F_3 ( 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_9 )
{
int V_7 ;
F_6 ( & V_2 -> V_5 ) ;
V_2 -> V_10 = V_9 ;
V_9 += 171200 ;
V_9 /= 800 ;
F_9 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < 13 ; V_7 ++ )
if ( V_9 & ( 1 << V_7 ) )
F_11 ( V_2 ) ;
else
F_9 ( V_2 ) ;
F_9 ( V_2 ) ;
F_9 ( V_2 ) ;
F_9 ( V_2 ) ;
F_9 ( V_2 ) ;
F_9 ( V_2 ) ;
F_9 ( V_2 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_8 == 0 || V_2 -> V_4 )
F_2 ( 0xd0 , V_2 -> V_3 ) ;
else
F_2 ( 0xd8 , V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_11 = 1 ;
F_6 ( & V_2 -> V_5 ) ;
if ( F_14 ( V_2 -> V_3 ) & 2 )
V_11 = 0 ;
F_7 ( & V_2 -> V_5 ) ;
return V_11 ;
}
static int F_15 ( struct V_12 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
F_16 ( V_15 -> V_16 , L_1 , sizeof( V_15 -> V_16 ) ) ;
F_16 ( V_15 -> V_17 , L_2 , sizeof( V_15 -> V_17 ) ) ;
F_16 ( V_15 -> V_18 , L_3 , sizeof( V_15 -> V_18 ) ) ;
V_15 -> V_19 = V_20 ;
V_15 -> V_21 = V_22 | V_23 ;
return 0 ;
}
static int F_17 ( struct V_12 * V_12 , void * V_13 ,
struct V_24 * V_15 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
if ( V_15 -> V_25 > 0 )
return - V_26 ;
F_16 ( V_15 -> V_27 , L_4 , sizeof( V_15 -> V_27 ) ) ;
V_15 -> type = V_28 ;
V_15 -> V_29 = 87 * 16000 ;
V_15 -> V_30 = 108 * 16000 ;
V_15 -> V_31 = V_32 ;
V_15 -> V_33 = V_34 ;
V_15 -> V_35 = V_36 ;
V_15 -> signal = 0xffff * F_13 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_12 , void * V_13 ,
struct V_24 * V_15 )
{
return V_15 -> V_25 ? - V_26 : 0 ;
}
static int F_20 ( struct V_12 * V_12 , void * V_13 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
if ( V_38 -> V_39 != 0 || V_38 -> type != V_28 )
return - V_26 ;
F_12 ( V_2 , V_38 -> V_40 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_12 , void * V_13 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
if ( V_38 -> V_39 != 0 )
return - V_26 ;
V_38 -> type = V_28 ;
V_38 -> V_40 = V_2 -> V_10 ;
return 0 ;
}
static int F_22 ( struct V_12 * V_12 , void * V_13 ,
struct V_41 * V_42 )
{
switch ( V_42 -> V_43 ) {
case V_44 :
return F_23 ( V_42 , 0 , 1 , 1 , 1 ) ;
case V_45 :
return F_23 ( V_42 , 0 , 0xff , 1 , 0xff ) ;
}
return - V_26 ;
}
static int F_24 ( struct V_12 * V_12 , void * V_13 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
switch ( V_47 -> V_43 ) {
case V_44 :
V_47 -> V_48 = V_2 -> V_4 ;
return 0 ;
case V_45 :
V_47 -> V_48 = V_2 -> V_8 ;
return 0 ;
}
return - V_26 ;
}
static int F_25 ( struct V_12 * V_12 , void * V_13 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
switch ( V_47 -> V_43 ) {
case V_44 :
if ( V_47 -> V_48 )
F_5 ( V_2 ) ;
else
F_8 ( V_2 , V_2 -> V_8 ) ;
return 0 ;
case V_45 :
F_8 ( V_2 , V_47 -> V_48 ) ;
return 0 ;
}
return - V_26 ;
}
static int F_26 ( struct V_12 * V_49 , void * V_13 , unsigned int * V_7 )
{
* V_7 = 0 ;
return 0 ;
}
static int F_27 ( struct V_12 * V_49 , void * V_13 , unsigned int V_7 )
{
return V_7 ? - V_26 : 0 ;
}
static int F_28 ( struct V_12 * V_12 , void * V_13 ,
struct V_50 * V_51 )
{
V_51 -> V_25 = 0 ;
F_16 ( V_51 -> V_27 , L_5 , sizeof( V_51 -> V_27 ) ) ;
V_51 -> V_33 = V_52 ;
return 0 ;
}
static int F_29 ( struct V_12 * V_12 , void * V_13 ,
struct V_50 * V_51 )
{
return V_51 -> V_25 ? - V_26 : 0 ;
}
static int T_1 F_30 ( void )
{
struct V_1 * V_2 = & V_53 ;
struct V_54 * V_55 = & V_2 -> V_55 ;
int V_56 ;
F_16 ( V_55 -> V_27 , L_6 , sizeof( V_55 -> V_27 ) ) ;
V_2 -> V_3 = V_3 ;
if ( V_2 -> V_3 == - 1 ) {
F_31 ( V_55 , L_7 ) ;
return - V_26 ;
}
if ( ! F_32 ( V_2 -> V_3 , 2 , L_6 ) ) {
F_31 ( V_55 , L_8 , V_2 -> V_3 ) ;
return - V_57 ;
}
V_56 = F_33 ( NULL , V_55 ) ;
if ( V_56 < 0 ) {
F_34 ( V_2 -> V_3 , 2 ) ;
F_31 ( V_55 , L_9 ) ;
return V_56 ;
}
F_16 ( V_2 -> V_58 . V_27 , V_55 -> V_27 , sizeof( V_2 -> V_58 . V_27 ) ) ;
V_2 -> V_58 . V_55 = V_55 ;
V_2 -> V_58 . V_59 = & V_60 ;
V_2 -> V_58 . V_61 = & V_62 ;
V_2 -> V_58 . V_63 = V_64 ;
F_35 ( & V_2 -> V_58 , V_2 ) ;
F_36 ( & V_2 -> V_5 ) ;
F_2 ( 0x48 , V_2 -> V_3 ) ;
F_3 ( 2000 ) ;
F_2 ( 0xc0 , V_2 -> V_3 ) ;
if ( F_37 ( & V_2 -> V_58 , V_65 , V_66 ) < 0 ) {
F_38 ( & V_2 -> V_55 ) ;
F_34 ( V_2 -> V_3 , 2 ) ;
return - V_26 ;
}
F_39 ( V_55 , L_10 ) ;
return 0 ;
}
static void T_2 F_40 ( void )
{
struct V_1 * V_2 = & V_53 ;
F_41 ( & V_2 -> V_58 ) ;
F_38 ( & V_2 -> V_55 ) ;
F_34 ( V_2 -> V_3 , 2 ) ;
}
