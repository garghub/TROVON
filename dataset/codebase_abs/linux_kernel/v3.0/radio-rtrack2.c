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
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = V_19 | V_20 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_9 , void * V_10 ,
struct V_21 * V_12 )
{
return V_12 -> V_22 ? - V_23 : 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_24 = 1 ;
F_2 ( & V_2 -> V_4 ) ;
if ( F_14 ( V_2 -> V_5 ) & 2 )
V_24 = 0 ;
F_4 ( & V_2 -> V_4 ) ;
return V_24 ;
}
static int F_15 ( struct V_9 * V_9 , void * V_10 ,
struct V_21 * V_12 )
{
struct V_1 * V_25 = F_16 ( V_9 ) ;
if ( V_12 -> V_22 > 0 )
return - V_23 ;
F_11 ( V_12 -> V_26 , L_4 , sizeof( V_12 -> V_26 ) ) ;
V_12 -> type = V_27 ;
V_12 -> V_28 = 88 * 16000 ;
V_12 -> V_29 = 108 * 16000 ;
V_12 -> V_30 = V_31 ;
V_12 -> V_32 = V_33 ;
V_12 -> V_34 = V_35 ;
V_12 -> signal = 0xFFFF * F_13 ( V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_9 , void * V_10 ,
struct V_36 * V_37 )
{
struct V_1 * V_25 = F_16 ( V_9 ) ;
if ( V_37 -> V_38 != 0 || V_37 -> type != V_27 )
return - V_23 ;
F_9 ( V_25 , V_37 -> V_39 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_9 , void * V_10 ,
struct V_36 * V_37 )
{
struct V_1 * V_25 = F_16 ( V_9 ) ;
if ( V_37 -> V_38 != 0 )
return - V_23 ;
V_37 -> type = V_27 ;
V_37 -> V_39 = V_25 -> V_8 ;
return 0 ;
}
static int F_19 ( struct V_9 * V_9 , void * V_10 ,
struct V_40 * V_41 )
{
switch ( V_41 -> V_42 ) {
case V_43 :
return F_20 ( V_41 , 0 , 1 , 1 , 1 ) ;
case V_44 :
return F_20 ( V_41 , 0 , 65535 , 65535 , 65535 ) ;
}
return - V_23 ;
}
static int F_21 ( struct V_9 * V_9 , void * V_10 ,
struct V_45 * V_46 )
{
struct V_1 * V_25 = F_16 ( V_9 ) ;
switch ( V_46 -> V_42 ) {
case V_43 :
V_46 -> V_47 = V_25 -> V_3 ;
return 0 ;
case V_44 :
if ( V_25 -> V_3 )
V_46 -> V_47 = 0 ;
else
V_46 -> V_47 = 65535 ;
return 0 ;
}
return - V_23 ;
}
static int F_22 ( struct V_9 * V_9 , void * V_10 ,
struct V_45 * V_46 )
{
struct V_1 * V_25 = F_16 ( V_9 ) ;
switch ( V_46 -> V_42 ) {
case V_43 :
if ( V_46 -> V_47 )
F_1 ( V_25 ) ;
else
F_5 ( V_25 ) ;
return 0 ;
case V_44 :
if ( V_46 -> V_47 )
F_5 ( V_25 ) ;
else
F_1 ( V_25 ) ;
return 0 ;
}
return - V_23 ;
}
static int F_23 ( struct V_9 * V_48 , void * V_10 , unsigned int * V_7 )
{
* V_7 = 0 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_48 , void * V_10 , unsigned int V_7 )
{
return V_7 ? - V_23 : 0 ;
}
static int F_25 ( struct V_9 * V_9 , void * V_10 ,
struct V_49 * V_50 )
{
V_50 -> V_22 = 0 ;
F_11 ( V_50 -> V_26 , L_5 , sizeof( V_50 -> V_26 ) ) ;
V_50 -> V_32 = V_51 ;
return 0 ;
}
static int F_26 ( struct V_9 * V_9 , void * V_10 ,
struct V_49 * V_50 )
{
return V_50 -> V_22 ? - V_23 : 0 ;
}
static int T_1 F_27 ( void )
{
struct V_1 * V_2 = & V_52 ;
struct V_53 * V_54 = & V_2 -> V_54 ;
int V_55 ;
F_11 ( V_54 -> V_26 , L_6 , sizeof( V_54 -> V_26 ) ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_5 == - 1 ) {
F_28 ( V_54 , L_7 ) ;
return - V_23 ;
}
if ( ! F_29 ( V_2 -> V_5 , 4 , L_6 ) ) {
F_28 ( V_54 , L_8 , V_2 -> V_5 ) ;
return - V_56 ;
}
V_55 = F_30 ( NULL , V_54 ) ;
if ( V_55 < 0 ) {
F_31 ( V_2 -> V_5 , 4 ) ;
F_28 ( V_54 , L_9 ) ;
return V_55 ;
}
F_11 ( V_2 -> V_57 . V_26 , V_54 -> V_26 , sizeof( V_2 -> V_57 . V_26 ) ) ;
V_2 -> V_57 . V_54 = V_54 ;
V_2 -> V_57 . V_58 = & V_59 ;
V_2 -> V_57 . V_60 = & V_61 ;
V_2 -> V_57 . V_62 = V_63 ;
F_32 ( & V_2 -> V_57 , V_2 ) ;
F_3 ( 1 , V_2 -> V_5 ) ;
V_2 -> V_3 = 1 ;
F_33 ( & V_2 -> V_4 ) ;
if ( F_34 ( & V_2 -> V_57 , V_64 , V_65 ) < 0 ) {
F_35 ( V_54 ) ;
F_31 ( V_2 -> V_5 , 4 ) ;
return - V_23 ;
}
F_36 ( V_54 , L_10 ) ;
return 0 ;
}
static void T_2 F_37 ( void )
{
struct V_1 * V_2 = & V_52 ;
F_38 ( & V_2 -> V_57 ) ;
F_35 ( & V_2 -> V_54 ) ;
F_31 ( V_2 -> V_5 , 4 ) ;
}
