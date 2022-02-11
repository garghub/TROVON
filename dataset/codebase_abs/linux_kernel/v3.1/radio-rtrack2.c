static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( 1 , V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_4 ) ;
V_2 -> V_3 = 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
if( V_2 -> V_3 == 0 )
return;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( 0 , V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_4 ) ;
V_2 -> V_3 = 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( 1 , V_2 -> V_5 ) ;
F_7 ( 3 , V_2 -> V_5 ) ;
F_7 ( 1 , V_2 -> V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_7 ( 5 , V_2 -> V_5 ) ;
F_7 ( 7 , V_2 -> V_5 ) ;
F_7 ( 5 , V_2 -> V_5 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_6 )
{
int V_7 ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_8 = V_6 ;
V_6 = V_6 / 200 + 856 ;
F_7 ( 0xc8 , V_2 -> V_5 ) ;
F_7 ( 0xc9 , V_2 -> V_5 ) ;
F_7 ( 0xc9 , V_2 -> V_5 ) ;
for ( V_7 = 0 ; V_7 < 10 ; V_7 ++ )
F_6 ( V_2 ) ;
for ( V_7 = 14 ; V_7 >= 0 ; V_7 -- )
if ( V_6 & ( 1 << V_7 ) )
F_8 ( V_2 ) ;
else
F_6 ( V_2 ) ;
F_7 ( 0xc8 , V_2 -> V_5 ) ;
if ( ! V_2 -> V_3 )
F_7 ( 0 , V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_9 , void * V_10 ,
struct V_11 * V_12 )
{
F_11 ( V_12 -> V_13 , L_1 , sizeof( V_12 -> V_13 ) ) ;
F_11 ( V_12 -> V_14 , L_2 , sizeof( V_12 -> V_14 ) ) ;
F_11 ( V_12 -> V_15 , L_3 , sizeof( V_12 -> V_15 ) ) ;
V_12 -> V_16 = V_17 | V_18 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_9 , void * V_10 ,
struct V_19 * V_12 )
{
return V_12 -> V_20 ? - V_21 : 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_22 = 1 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_14 ( V_2 -> V_5 ) & 2 )
V_22 = 0 ;
F_4 ( & V_2 -> V_4 ) ;
return V_22 ;
}
static int F_15 ( struct V_9 * V_9 , void * V_10 ,
struct V_19 * V_12 )
{
struct V_1 * V_23 = F_16 ( V_9 ) ;
if ( V_12 -> V_20 > 0 )
return - V_21 ;
F_11 ( V_12 -> V_24 , L_4 , sizeof( V_12 -> V_24 ) ) ;
V_12 -> type = V_25 ;
V_12 -> V_26 = 88 * 16000 ;
V_12 -> V_27 = 108 * 16000 ;
V_12 -> V_28 = V_29 ;
V_12 -> V_30 = V_31 ;
V_12 -> V_32 = V_33 ;
V_12 -> signal = 0xFFFF * F_13 ( V_23 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_9 , void * V_10 ,
struct V_34 * V_35 )
{
struct V_1 * V_23 = F_16 ( V_9 ) ;
if ( V_35 -> V_36 != 0 || V_35 -> type != V_25 )
return - V_21 ;
F_9 ( V_23 , V_35 -> V_37 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_9 , void * V_10 ,
struct V_34 * V_35 )
{
struct V_1 * V_23 = F_16 ( V_9 ) ;
if ( V_35 -> V_36 != 0 )
return - V_21 ;
V_35 -> type = V_25 ;
V_35 -> V_37 = V_23 -> V_8 ;
return 0 ;
}
static int F_19 ( struct V_9 * V_9 , void * V_10 ,
struct V_38 * V_39 )
{
switch ( V_39 -> V_40 ) {
case V_41 :
return F_20 ( V_39 , 0 , 1 , 1 , 1 ) ;
case V_42 :
return F_20 ( V_39 , 0 , 65535 , 65535 , 65535 ) ;
}
return - V_21 ;
}
static int F_21 ( struct V_9 * V_9 , void * V_10 ,
struct V_43 * V_44 )
{
struct V_1 * V_23 = F_16 ( V_9 ) ;
switch ( V_44 -> V_40 ) {
case V_41 :
V_44 -> V_45 = V_23 -> V_3 ;
return 0 ;
case V_42 :
if ( V_23 -> V_3 )
V_44 -> V_45 = 0 ;
else
V_44 -> V_45 = 65535 ;
return 0 ;
}
return - V_21 ;
}
static int F_22 ( struct V_9 * V_9 , void * V_10 ,
struct V_43 * V_44 )
{
struct V_1 * V_23 = F_16 ( V_9 ) ;
switch ( V_44 -> V_40 ) {
case V_41 :
if ( V_44 -> V_45 )
F_1 ( V_23 ) ;
else
F_5 ( V_23 ) ;
return 0 ;
case V_42 :
if ( V_44 -> V_45 )
F_5 ( V_23 ) ;
else
F_1 ( V_23 ) ;
return 0 ;
}
return - V_21 ;
}
static int F_23 ( struct V_9 * V_46 , void * V_10 , unsigned int * V_7 )
{
* V_7 = 0 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_46 , void * V_10 , unsigned int V_7 )
{
return V_7 ? - V_21 : 0 ;
}
static int F_25 ( struct V_9 * V_9 , void * V_10 ,
struct V_47 * V_48 )
{
V_48 -> V_20 = 0 ;
F_11 ( V_48 -> V_24 , L_5 , sizeof( V_48 -> V_24 ) ) ;
V_48 -> V_30 = V_49 ;
return 0 ;
}
static int F_26 ( struct V_9 * V_9 , void * V_10 ,
struct V_47 * V_48 )
{
return V_48 -> V_20 ? - V_21 : 0 ;
}
static int T_1 F_27 ( void )
{
struct V_1 * V_2 = & V_50 ;
struct V_51 * V_52 = & V_2 -> V_52 ;
int V_53 ;
F_11 ( V_52 -> V_24 , L_6 , sizeof( V_52 -> V_24 ) ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_5 == - 1 ) {
F_28 ( V_52 , L_7 ) ;
return - V_21 ;
}
if ( ! F_29 ( V_2 -> V_5 , 4 , L_6 ) ) {
F_28 ( V_52 , L_8 , V_2 -> V_5 ) ;
return - V_54 ;
}
V_53 = F_30 ( NULL , V_52 ) ;
if ( V_53 < 0 ) {
F_31 ( V_2 -> V_5 , 4 ) ;
F_28 ( V_52 , L_9 ) ;
return V_53 ;
}
F_11 ( V_2 -> V_55 . V_24 , V_52 -> V_24 , sizeof( V_2 -> V_55 . V_24 ) ) ;
V_2 -> V_55 . V_52 = V_52 ;
V_2 -> V_55 . V_56 = & V_57 ;
V_2 -> V_55 . V_58 = & V_59 ;
V_2 -> V_55 . V_60 = V_61 ;
F_32 ( & V_2 -> V_55 , V_2 ) ;
F_3 ( 1 , V_2 -> V_5 ) ;
V_2 -> V_3 = 1 ;
F_33 ( & V_2 -> V_4 ) ;
if ( F_34 ( & V_2 -> V_55 , V_62 , V_63 ) < 0 ) {
F_35 ( V_52 ) ;
F_31 ( V_2 -> V_5 , 4 ) ;
return - V_21 ;
}
F_36 ( V_52 , L_10 ) ;
return 0 ;
}
static void T_2 F_37 ( void )
{
struct V_1 * V_2 = & V_50 ;
F_38 ( & V_2 -> V_55 ) ;
F_35 ( & V_2 -> V_52 ) ;
F_31 ( V_2 -> V_5 , 4 ) ;
}
