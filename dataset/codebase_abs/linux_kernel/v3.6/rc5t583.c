static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
if ( V_3 == V_10 ) {
F_2 ( V_2 , L_1 , V_3 ) ;
return - V_11 ;
}
V_8 = V_12 [ V_3 ] . V_13 ;
V_9 = V_8 + 1 ;
V_6 = F_3 ( V_2 , V_12 [ V_3 ] . V_14 , & V_7 ) ;
if ( V_6 < 0 ) {
F_2 ( V_2 , L_2 ,
V_12 [ V_3 ] . V_14 ) ;
return V_6 ;
}
V_7 &= ~ ( 0xF << V_8 ) ;
V_7 |= F_4 ( V_8 ) ;
V_7 |= ( ( V_5 & 0x7 ) << V_9 ) ;
V_6 = F_5 ( V_2 , V_15 , F_4 ( 1 ) ) ;
if ( V_6 < 0 ) {
F_2 ( V_2 , L_3 ,
V_15 ) ;
return V_6 ;
}
V_6 = F_6 ( V_2 , V_12 [ V_3 ] . V_14 , V_7 ) ;
if ( V_6 < 0 ) {
F_2 ( V_2 , L_4 ,
V_12 [ V_3 ] . V_14 ) ;
return V_6 ;
}
if ( V_3 == V_16 ) {
V_6 = F_6 ( V_2 , V_17 , 0x1 ) ;
if ( V_6 < 0 )
F_2 ( V_2 , L_4 ,
V_17 ) ;
}
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_6 ;
if ( V_3 != V_10 ) {
F_2 ( V_2 , L_5 , V_3 ) ;
return - V_11 ;
}
V_6 = F_5 ( V_2 , V_15 , F_4 ( 2 ) ) ;
if ( V_6 < 0 )
F_2 ( V_2 , L_6 ) ;
return V_6 ;
}
int F_8 ( struct V_1 * V_2 , int V_18 ,
int V_19 , int V_20 )
{
if ( ( V_19 & V_21 ) == V_21 )
return - V_11 ;
if ( V_19 & V_22 )
return F_1 ( V_2 , V_18 ,
V_19 , V_20 ) ;
if ( V_19 & V_23 )
return F_7 ( V_2 ,
V_18 , V_19 ) ;
return 0 ;
}
static int F_9 ( struct V_24 * V_24 ,
struct V_25 * V_26 )
{
int V_6 ;
int V_27 ;
T_1 V_28 = 0 ;
if ( V_26 -> V_29 )
V_28 = 0x1 ;
V_6 = F_6 ( V_24 -> V_2 , V_15 , V_28 ) ;
if ( V_6 < 0 )
F_10 ( V_24 -> V_2 , L_7 ,
V_15 , V_6 ) ;
V_6 = F_6 ( V_24 -> V_2 , V_17 , 0x0 ) ;
if ( V_6 < 0 )
F_10 ( V_24 -> V_2 , L_7 ,
V_17 , V_6 ) ;
for ( V_27 = V_30 ; V_27 <= V_31 ; ++ V_27 ) {
V_6 = F_6 ( V_24 -> V_2 , V_27 , 0x0 ) ;
if ( V_6 < 0 )
F_10 ( V_24 -> V_2 ,
L_8 ,
V_27 , V_6 ) ;
}
return 0 ;
}
static bool F_11 ( struct V_1 * V_2 , unsigned int V_32 )
{
switch ( V_32 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
return false ;
case V_43 :
return true ;
default:
if ( ( V_32 >= V_44 ) &&
( V_32 <= V_45 ) )
return false ;
if ( ( V_32 >= V_30 ) && ( V_32 <= V_31 ) )
return false ;
if ( ( V_32 >= V_46 ) && ( V_32 <= V_47 ) )
return false ;
if ( ( V_32 >= V_48 ) &&
( V_32 <= V_49 ) )
return false ;
break;
}
return true ;
}
static int T_2 F_12 ( struct V_50 * V_51 ,
const struct V_52 * V_3 )
{
struct V_24 * V_24 ;
struct V_25 * V_26 = V_51 -> V_2 . V_53 ;
int V_6 ;
bool V_54 = false ;
if ( ! V_26 ) {
F_2 ( & V_51 -> V_2 , L_9 ) ;
return - V_11 ;
}
V_24 = F_13 ( & V_51 -> V_2 , sizeof( struct V_24 ) , V_55 ) ;
if ( ! V_24 ) {
F_2 ( & V_51 -> V_2 , L_10 ) ;
return - V_56 ;
}
V_24 -> V_2 = & V_51 -> V_2 ;
F_14 ( V_51 , V_24 ) ;
V_24 -> V_57 = F_15 ( V_51 , & V_58 ) ;
if ( F_16 ( V_24 -> V_57 ) ) {
V_6 = F_17 ( V_24 -> V_57 ) ;
F_2 ( & V_51 -> V_2 , L_11 , V_6 ) ;
return V_6 ;
}
V_6 = F_9 ( V_24 , V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_51 -> V_59 ) {
V_6 = F_18 ( V_24 , V_51 -> V_59 , V_26 -> V_60 ) ;
if ( V_6 )
F_10 ( & V_51 -> V_2 , L_12 , V_6 ) ;
else
V_54 = true ;
}
V_6 = F_19 ( V_24 -> V_2 , - 1 , V_61 ,
F_20 ( V_61 ) , NULL , 0 , NULL ) ;
if ( V_6 ) {
F_2 ( & V_51 -> V_2 , L_13 , V_6 ) ;
goto V_62;
}
return 0 ;
V_62:
if ( V_54 )
F_21 ( V_24 ) ;
return V_6 ;
}
static int T_3 F_22 ( struct V_50 * V_51 )
{
struct V_24 * V_24 = F_23 ( V_51 ) ;
F_24 ( V_24 -> V_2 ) ;
F_21 ( V_24 ) ;
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_63 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_63 ) ;
}
