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
V_15 -> V_19 = V_20 | V_21 ;
return 0 ;
}
static int F_17 ( struct V_12 * V_12 , void * V_13 ,
struct V_22 * V_15 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
if ( V_15 -> V_23 > 0 )
return - V_24 ;
F_16 ( V_15 -> V_25 , L_4 , sizeof( V_15 -> V_25 ) ) ;
V_15 -> type = V_26 ;
V_15 -> V_27 = 87 * 16000 ;
V_15 -> V_28 = 108 * 16000 ;
V_15 -> V_29 = V_30 ;
V_15 -> V_31 = V_32 ;
V_15 -> V_33 = V_34 ;
V_15 -> signal = 0xffff * F_13 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_12 , void * V_13 ,
struct V_22 * V_15 )
{
return V_15 -> V_23 ? - V_24 : 0 ;
}
static int F_20 ( struct V_12 * V_12 , void * V_13 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
if ( V_36 -> V_37 != 0 || V_36 -> type != V_26 )
return - V_24 ;
F_12 ( V_2 , V_36 -> V_38 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_12 , void * V_13 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
if ( V_36 -> V_37 != 0 )
return - V_24 ;
V_36 -> type = V_26 ;
V_36 -> V_38 = V_2 -> V_10 ;
return 0 ;
}
static int F_22 ( struct V_12 * V_12 , void * V_13 ,
struct V_39 * V_40 )
{
switch ( V_40 -> V_41 ) {
case V_42 :
return F_23 ( V_40 , 0 , 1 , 1 , 1 ) ;
case V_43 :
return F_23 ( V_40 , 0 , 0xff , 1 , 0xff ) ;
}
return - V_24 ;
}
static int F_24 ( struct V_12 * V_12 , void * V_13 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
switch ( V_45 -> V_41 ) {
case V_42 :
V_45 -> V_46 = V_2 -> V_4 ;
return 0 ;
case V_43 :
V_45 -> V_46 = V_2 -> V_8 ;
return 0 ;
}
return - V_24 ;
}
static int F_25 ( struct V_12 * V_12 , void * V_13 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_18 ( V_12 ) ;
switch ( V_45 -> V_41 ) {
case V_42 :
if ( V_45 -> V_46 )
F_5 ( V_2 ) ;
else
F_8 ( V_2 , V_2 -> V_8 ) ;
return 0 ;
case V_43 :
F_8 ( V_2 , V_45 -> V_46 ) ;
return 0 ;
}
return - V_24 ;
}
static int F_26 ( struct V_12 * V_47 , void * V_13 , unsigned int * V_7 )
{
* V_7 = 0 ;
return 0 ;
}
static int F_27 ( struct V_12 * V_47 , void * V_13 , unsigned int V_7 )
{
return V_7 ? - V_24 : 0 ;
}
static int F_28 ( struct V_12 * V_12 , void * V_13 ,
struct V_48 * V_49 )
{
V_49 -> V_23 = 0 ;
F_16 ( V_49 -> V_25 , L_5 , sizeof( V_49 -> V_25 ) ) ;
V_49 -> V_31 = V_50 ;
return 0 ;
}
static int F_29 ( struct V_12 * V_12 , void * V_13 ,
struct V_48 * V_49 )
{
return V_49 -> V_23 ? - V_24 : 0 ;
}
static int T_1 F_30 ( void )
{
struct V_1 * V_2 = & V_51 ;
struct V_52 * V_53 = & V_2 -> V_53 ;
int V_54 ;
F_16 ( V_53 -> V_25 , L_6 , sizeof( V_53 -> V_25 ) ) ;
V_2 -> V_3 = V_3 ;
if ( V_2 -> V_3 == - 1 ) {
F_31 ( V_53 , L_7 ) ;
return - V_24 ;
}
if ( ! F_32 ( V_2 -> V_3 , 2 , L_6 ) ) {
F_31 ( V_53 , L_8 , V_2 -> V_3 ) ;
return - V_55 ;
}
V_54 = F_33 ( NULL , V_53 ) ;
if ( V_54 < 0 ) {
F_34 ( V_2 -> V_3 , 2 ) ;
F_31 ( V_53 , L_9 ) ;
return V_54 ;
}
F_16 ( V_2 -> V_56 . V_25 , V_53 -> V_25 , sizeof( V_2 -> V_56 . V_25 ) ) ;
V_2 -> V_56 . V_53 = V_53 ;
V_2 -> V_56 . V_57 = & V_58 ;
V_2 -> V_56 . V_59 = & V_60 ;
V_2 -> V_56 . V_61 = V_62 ;
F_35 ( & V_2 -> V_56 , V_2 ) ;
F_36 ( & V_2 -> V_5 ) ;
F_2 ( 0x48 , V_2 -> V_3 ) ;
F_3 ( 2000 ) ;
F_2 ( 0xc0 , V_2 -> V_3 ) ;
if ( F_37 ( & V_2 -> V_56 , V_63 , V_64 ) < 0 ) {
F_38 ( & V_2 -> V_53 ) ;
F_34 ( V_2 -> V_3 , 2 ) ;
return - V_24 ;
}
F_39 ( V_53 , L_10 ) ;
return 0 ;
}
static void T_2 F_40 ( void )
{
struct V_1 * V_2 = & V_51 ;
F_41 ( & V_2 -> V_56 ) ;
F_38 ( & V_2 -> V_53 ) ;
F_34 ( V_2 -> V_3 , 2 ) ;
}
