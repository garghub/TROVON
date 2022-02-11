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
struct V_17 * V_18 = V_15 -> V_18 ;
switch ( F_3 ( V_14 ) ) {
case V_19 :
V_16 = V_20 ;
break;
case V_21 :
V_16 = V_22 ;
break;
case V_23 :
case V_24 :
V_16 = V_25 ;
break;
}
F_4 ( V_18 , V_26 , V_27 ,
V_16 << V_28 ) ;
F_4 ( V_18 , V_29 , V_30 ,
V_16 << V_31 ) ;
return 0 ;
}
static int F_5 ( struct V_17 * V_18 )
{
return F_4 ( V_18 , V_29 ,
V_32 , 0 ) ;
}
static int F_6 ( struct V_17 * V_18 )
{
return F_4 ( V_18 , V_29 ,
V_32 , V_33 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_34 * V_35 = F_8 ( V_18 ) ;
struct V_36 * V_37 = & V_18 -> V_37 ;
int V_38 , V_39 ;
int V_40 = 0 ;
int V_41 ;
V_38 = V_42 [ V_35 -> type ] . V_43 . V_44 / 2 ;
V_39 = V_42 [ V_35 -> type ] . V_45 . V_44 / 2 ;
V_40 = F_9 ( V_18 , 4 , 12 , V_46 ) ;
if ( V_40 < 0 ) {
F_10 ( V_18 -> V_47 , L_1 ,
V_40 ) ;
return V_40 ;
}
F_11 ( V_18 , V_26 , 0x300 ) ;
F_11 ( V_18 , V_48 , 0x0 ) ;
F_11 ( V_18 , V_49 , 0x100 ) ;
F_11 ( V_18 , V_29 , 0x180 ) ;
for ( V_41 = 1 ; V_41 <= V_38 ; ++ V_41 ) {
F_11 ( V_18 , F_12 ( V_41 ) , 0x3FF ) ;
F_11 ( V_18 , F_13 ( V_41 ) , 0x3FF ) ;
}
if ( V_35 -> type == V_50 ) {
F_11 ( V_18 , V_51 , 0x3A ) ;
V_40 = F_14 ( V_18 , V_52 ,
F_15 ( V_52 ) ) ;
if ( V_40 )
return V_40 ;
} else {
F_11 ( V_18 , V_51 , 0x00 ) ;
}
V_40 = F_14 ( V_18 , V_53 , V_38 * 2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_14 ( V_18 , V_54 , V_39 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_16 ( V_37 , V_55 , V_38 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_16 ( V_37 , V_56 , V_39 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_17 ( V_37 , V_57 , V_38 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_17 ( V_37 , V_58 , V_39 ) ;
if ( V_40 )
return V_40 ;
return V_40 ;
}
static int F_18 ( struct V_17 * V_18 )
{
return F_4 ( V_18 , V_29 ,
V_32 , 0 ) ;
}
static int T_1 F_19 ( struct V_59 * V_60 )
{
struct V_34 * V_35 ;
int V_40 ;
V_35 = F_20 ( & V_60 -> V_47 , sizeof( struct V_34 ) ,
V_61 ) ;
if ( V_35 == NULL )
return - V_62 ;
V_35 -> type = F_21 ( V_60 ) -> V_63 ;
F_22 ( V_60 , V_35 ) ;
V_40 = F_23 ( & V_60 -> V_47 ,
& V_64 , & V_42 [ V_35 -> type ] , 1 ) ;
return V_40 ;
}
static int T_2 F_24 ( struct V_59 * V_60 )
{
F_25 ( & V_60 -> V_47 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_65 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_65 ) ;
}
