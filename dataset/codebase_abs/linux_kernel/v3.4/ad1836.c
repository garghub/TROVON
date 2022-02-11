static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 & V_4 ) {
case V_5 :
break;
default:
return - V_6 ;
}
switch ( V_3 & V_7 ) {
case V_8 :
break;
default:
return - V_6 ;
}
switch ( V_3 & V_9 ) {
case V_10 :
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_1 * V_15 )
{
int V_16 = 0 ;
struct V_17 * V_18 = V_12 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
switch ( F_3 ( V_14 ) ) {
case V_22 :
V_16 = V_23 ;
break;
case V_24 :
V_16 = V_25 ;
break;
case V_26 :
case V_27 :
V_16 = V_28 ;
break;
}
F_4 ( V_21 , V_29 , V_30 ,
V_16 << V_31 ) ;
F_4 ( V_21 , V_32 , V_33 ,
V_16 << V_34 ) ;
return 0 ;
}
static int F_5 ( struct V_20 * V_21 )
{
return F_4 ( V_21 , V_32 ,
V_35 , 0 ) ;
}
static int F_6 ( struct V_20 * V_21 )
{
return F_4 ( V_21 , V_32 ,
V_35 , V_36 ) ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_37 * V_38 = F_8 ( V_21 ) ;
struct V_39 * V_40 = & V_21 -> V_40 ;
int V_41 , V_42 ;
int V_43 = 0 ;
int V_44 ;
V_41 = V_45 [ V_38 -> type ] . V_46 . V_47 / 2 ;
V_42 = V_45 [ V_38 -> type ] . V_48 . V_47 / 2 ;
V_43 = F_9 ( V_21 , 4 , 12 , V_49 ) ;
if ( V_43 < 0 ) {
F_10 ( V_21 -> V_50 , L_1 ,
V_43 ) ;
return V_43 ;
}
F_11 ( V_21 , V_29 , 0x300 ) ;
F_11 ( V_21 , V_51 , 0x0 ) ;
F_11 ( V_21 , V_52 , 0x100 ) ;
F_11 ( V_21 , V_32 , 0x180 ) ;
for ( V_44 = 1 ; V_44 <= V_41 ; ++ V_44 ) {
F_11 ( V_21 , F_12 ( V_44 ) , 0x3FF ) ;
F_11 ( V_21 , F_13 ( V_44 ) , 0x3FF ) ;
}
if ( V_38 -> type == V_53 ) {
F_11 ( V_21 , V_54 , 0x3A ) ;
V_43 = F_14 ( V_21 , V_55 ,
F_15 ( V_55 ) ) ;
if ( V_43 )
return V_43 ;
} else {
F_11 ( V_21 , V_54 , 0x00 ) ;
}
V_43 = F_14 ( V_21 , V_56 , V_41 * 2 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_21 , V_57 , V_42 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_16 ( V_40 , V_58 , V_41 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_16 ( V_40 , V_59 , V_42 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_17 ( V_40 , V_60 , V_41 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_17 ( V_40 , V_61 , V_42 ) ;
if ( V_43 )
return V_43 ;
return V_43 ;
}
static int F_18 ( struct V_20 * V_21 )
{
return F_4 ( V_21 , V_32 ,
V_35 , 0 ) ;
}
static int T_1 F_19 ( struct V_62 * V_63 )
{
struct V_37 * V_38 ;
int V_43 ;
V_38 = F_20 ( & V_63 -> V_50 , sizeof( struct V_37 ) ,
V_64 ) ;
if ( V_38 == NULL )
return - V_65 ;
V_38 -> type = F_21 ( V_63 ) -> V_66 ;
F_22 ( V_63 , V_38 ) ;
V_43 = F_23 ( & V_63 -> V_50 ,
& V_67 , & V_45 [ V_38 -> type ] , 1 ) ;
return V_43 ;
}
static int T_2 F_24 ( struct V_62 * V_63 )
{
F_25 ( & V_63 -> V_50 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_68 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_68 ) ;
}
