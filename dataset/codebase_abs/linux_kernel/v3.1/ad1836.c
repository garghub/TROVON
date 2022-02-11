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
static int F_5 ( struct V_20 * V_21 , T_1 V_35 )
{
return F_4 ( V_21 , V_32 ,
V_36 , 0 ) ;
}
static int F_6 ( struct V_20 * V_21 )
{
return F_4 ( V_21 , V_32 ,
V_36 , V_37 ) ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_38 * V_39 = F_8 ( V_21 ) ;
struct V_40 * V_41 = & V_21 -> V_41 ;
int V_42 , V_43 ;
int V_44 = 0 ;
int V_45 ;
V_42 = V_46 [ V_39 -> type ] . V_47 . V_48 / 2 ;
V_43 = V_46 [ V_39 -> type ] . V_49 . V_48 / 2 ;
V_44 = F_9 ( V_21 , 4 , 12 , V_50 ) ;
if ( V_44 < 0 ) {
F_10 ( V_21 -> V_51 , L_1 ,
V_44 ) ;
return V_44 ;
}
F_11 ( V_21 , V_29 , 0x300 ) ;
F_11 ( V_21 , V_52 , 0x0 ) ;
F_11 ( V_21 , V_53 , 0x100 ) ;
F_11 ( V_21 , V_32 , 0x180 ) ;
for ( V_45 = 1 ; V_45 <= V_42 ; ++ V_45 ) {
F_11 ( V_21 , F_12 ( V_45 ) , 0x3FF ) ;
F_11 ( V_21 , F_13 ( V_45 ) , 0x3FF ) ;
}
if ( V_39 -> type == V_54 ) {
F_11 ( V_21 , V_55 , 0x3A ) ;
V_44 = F_14 ( V_21 , V_56 ,
F_15 ( V_56 ) ) ;
if ( V_44 )
return V_44 ;
} else {
F_11 ( V_21 , V_55 , 0x00 ) ;
}
V_44 = F_14 ( V_21 , V_57 , V_42 * 2 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_14 ( V_21 , V_58 , V_43 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_16 ( V_41 , V_59 , V_42 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_16 ( V_41 , V_60 , V_43 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_17 ( V_41 , V_61 , V_42 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_17 ( V_41 , V_62 , V_43 ) ;
if ( V_44 )
return V_44 ;
return V_44 ;
}
static int F_18 ( struct V_20 * V_21 )
{
return F_4 ( V_21 , V_32 ,
V_36 , 0 ) ;
}
static int T_2 F_19 ( struct V_63 * V_64 )
{
struct V_38 * V_39 ;
int V_44 ;
V_39 = F_20 ( sizeof( struct V_38 ) , V_65 ) ;
if ( V_39 == NULL )
return - V_66 ;
V_39 -> type = F_21 ( V_64 ) -> V_67 ;
F_22 ( V_64 , V_39 ) ;
V_44 = F_23 ( & V_64 -> V_51 ,
& V_68 , & V_46 [ V_39 -> type ] , 1 ) ;
if ( V_44 < 0 )
F_24 ( V_39 ) ;
return V_44 ;
}
static int T_3 F_25 ( struct V_63 * V_64 )
{
F_26 ( & V_64 -> V_51 ) ;
F_24 ( F_27 ( V_64 ) ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_69 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_69 ) ;
}
