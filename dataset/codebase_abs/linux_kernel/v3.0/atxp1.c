static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = F_3 ( V_5 ) ;
F_4 ( & V_6 -> V_7 ) ;
if ( F_5 ( V_8 , V_6 -> V_9 + V_10 ) || ! V_6 -> V_11 ) {
V_6 -> V_12 . V_13 = F_6 ( V_5 , V_14 ) ;
V_6 -> V_12 . V_15 = F_6 ( V_5 , V_16 ) ;
V_6 -> V_12 . V_17 = F_6 ( V_5 , V_18 ) ;
V_6 -> V_12 . V_19 = F_6 ( V_5 , V_20 ) ;
V_6 -> V_11 = 1 ;
}
F_7 ( & V_6 -> V_7 ) ;
return ( V_6 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 , struct V_21 * V_22 , char * V_23 )
{
int V_24 ;
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
V_24 = sprintf ( V_23 , L_1 , F_9 ( V_6 -> V_12 . V_13 & V_25 , V_6 -> V_26 ) ) ;
return V_24 ;
}
static T_1 F_10 ( struct V_2 * V_3 , struct V_21 * V_22 , const char * V_23 , T_2 V_27 )
{
struct V_1 * V_6 ;
struct V_4 * V_5 ;
int V_13 , V_28 ;
unsigned int V_29 ;
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_29 = F_11 ( V_23 , NULL , 10 ) ;
V_29 /= 25 ;
V_29 *= 25 ;
V_13 = F_12 ( V_29 , V_6 -> V_26 ) ;
if ( V_13 < 0 ) {
F_13 ( V_3 , L_2 ) ;
return - 1 ;
}
if ( V_6 -> V_12 . V_13 & V_30 )
V_28 = V_6 -> V_12 . V_13 & V_25 ;
else
V_28 = V_6 -> V_12 . V_15 ;
if ( V_13 == V_28 )
return V_27 ;
F_14 ( V_3 , L_3 , V_29 , V_13 ) ;
if ( V_28 > V_13 ) {
for (; V_28 >= V_13 ; V_28 -- ) {
F_15 ( V_5 , V_14 , V_28 | V_30 ) ;
}
}
else {
for (; V_28 <= V_13 ; V_28 ++ ) {
F_15 ( V_5 , V_14 , V_28 | V_30 ) ;
}
}
V_6 -> V_11 = 0 ;
return V_27 ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_21 * V_22 , char * V_23 )
{
int V_24 ;
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
V_24 = sprintf ( V_23 , L_4 , V_6 -> V_12 . V_17 & V_31 ) ;
return V_24 ;
}
static T_1 F_17 ( struct V_2 * V_3 , struct V_21 * V_22 , const char * V_23 , T_2 V_27 )
{
struct V_1 * V_6 ;
struct V_4 * V_5 ;
unsigned int V_32 ;
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_32 = F_11 ( V_23 , NULL , 16 ) ;
V_32 &= V_31 ;
if ( V_32 != ( V_6 -> V_12 . V_17 & V_31 ) ) {
F_18 ( V_3 , L_5 , V_32 ) ;
F_15 ( V_5 , V_18 , V_32 ) ;
V_6 -> V_11 = 0 ;
}
return V_27 ;
}
static T_1 F_19 ( struct V_2 * V_3 , struct V_21 * V_22 , char * V_23 )
{
int V_24 ;
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
V_24 = sprintf ( V_23 , L_4 , V_6 -> V_12 . V_19 ) ;
return V_24 ;
}
static T_1 F_20 ( struct V_2 * V_3 , struct V_21 * V_22 , const char * V_23 , T_2 V_27 )
{
struct V_1 * V_6 ;
struct V_4 * V_5 ;
unsigned int V_32 ;
V_5 = F_2 ( V_3 ) ;
V_6 = F_1 ( V_3 ) ;
V_32 = F_11 ( V_23 , NULL , 16 ) & 0xff ;
if ( V_32 != V_6 -> V_12 . V_19 ) {
F_18 ( V_3 , L_5 , V_32 ) ;
F_15 ( V_5 , V_20 , V_32 ) ;
V_6 -> V_11 = 0 ;
}
return V_27 ;
}
static int F_21 ( struct V_4 * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = V_33 -> V_37 ;
T_3 V_38 ;
if ( ! F_22 ( V_37 , V_39 ) )
return - V_40 ;
if ( ! ( ( F_6 ( V_33 , 0x3e ) == 0 ) &&
( F_6 ( V_33 , 0x3f ) == 0 ) &&
( F_6 ( V_33 , 0xfe ) == 0 ) &&
( F_6 ( V_33 , 0xff ) == 0 ) ) )
return - V_40 ;
V_38 = F_6 ( V_33 , 0x00 ) ;
if ( ! ( ( F_6 ( V_33 , 0x10 ) == V_38 ) &&
( F_6 ( V_33 , 0x11 ) == V_38 ) ) )
return - V_40 ;
V_38 = F_23 () ;
if ( ( V_38 != 90 ) && ( V_38 != 91 ) ) {
F_13 ( & V_37 -> V_3 , L_6 ,
V_38 / 10 , V_38 % 10 ) ;
return - V_40 ;
}
F_24 ( V_35 -> type , L_7 , V_41 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_33 ,
const struct V_42 * V_43 )
{
struct V_1 * V_6 ;
int V_44 ;
V_6 = F_26 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_6 ) {
V_44 = - V_46 ;
goto exit;
}
V_6 -> V_26 = F_23 () ;
F_27 ( V_33 , V_6 ) ;
V_6 -> V_11 = 0 ;
F_28 ( & V_6 -> V_7 ) ;
if ( ( V_44 = F_29 ( & V_33 -> V_3 . V_47 , & V_48 ) ) )
goto V_49;
V_6 -> V_50 = F_30 ( & V_33 -> V_3 ) ;
if ( F_31 ( V_6 -> V_50 ) ) {
V_44 = F_32 ( V_6 -> V_50 ) ;
goto V_51;
}
F_18 ( & V_33 -> V_3 , L_8 ,
V_6 -> V_26 / 10 , V_6 -> V_26 % 10 ) ;
return 0 ;
V_51:
F_33 ( & V_33 -> V_3 . V_47 , & V_48 ) ;
V_49:
F_34 ( V_6 ) ;
exit:
return V_44 ;
}
static int F_35 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_36 ( V_6 -> V_50 ) ;
F_33 ( & V_5 -> V_3 . V_47 , & V_48 ) ;
F_34 ( V_6 ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
return F_38 ( & V_52 ) ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_52 ) ;
}
