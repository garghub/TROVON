static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 V_9 ;
if ( ! F_3 ( & V_5 -> V_10 ) && ! F_3 ( & V_5 -> V_11 ) )
return V_12 ;
F_4 ( & V_9 ) ;
if ( V_7 -> V_13 == V_14 )
V_5 -> V_15 = V_9 . V_16 & 0xffff ;
else
V_5 -> V_15 = V_9 . V_17 & 0xffff ;
F_5 ( V_7 ) ;
F_6 ( V_3 , F_7 ( V_5 -> V_18 ) ) ;
return V_19 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_23 -> V_24 ;
V_5 -> V_25 = F_9 ( V_21 ) ;
V_5 -> V_26 = F_10 ( V_21 ) ;
V_5 -> V_15 = 0 ;
V_5 -> V_18 = 1000000000 / F_11 ( V_21 ) *
F_12 ( V_21 ) ;
F_13 ( V_7 , & V_7 -> V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_23 -> V_24 ;
struct V_8 V_9 ;
F_4 ( & V_9 ) ;
if ( V_7 -> V_13 == V_14 )
V_9 . V_16 = ( V_5 -> V_26 * V_5 -> V_25 - 1 ) << 16 ;
else
V_9 . V_17 = ( V_5 -> V_26 * V_5 -> V_25 - 1 ) << 16 ;
F_15 ( & V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , int V_28 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_23 -> V_24 ;
switch ( V_28 ) {
case V_29 :
case V_30 :
case V_31 :
if ( V_7 -> V_13 == V_14 )
F_17 ( & V_5 -> V_10 , 1 ) ;
else
F_17 ( & V_5 -> V_11 , 1 ) ;
F_18 ( & V_5 -> V_3 , F_7 ( V_5 -> V_18 ) ,
V_32 ) ;
F_19 ( V_33 ) ;
break;
case V_34 :
case V_35 :
case V_36 :
if ( V_7 -> V_13 == V_14 )
F_17 ( & V_5 -> V_10 , 0 ) ;
else
F_17 ( & V_5 -> V_11 , 0 ) ;
if ( ! F_3 ( & V_5 -> V_10 ) &&
! F_3 ( & V_5 -> V_11 ) )
F_20 ( V_33 ) ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static T_1 F_21 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_23 -> V_24 ;
return F_22 ( V_7 -> V_23 , V_5 -> V_15 ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 ;
int V_38 ;
V_5 = F_24 ( sizeof( * V_5 ) , V_39 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_23 -> V_24 = V_5 ;
V_5 -> V_7 = V_7 ;
F_17 ( & V_5 -> V_10 , 0 ) ;
F_17 ( & V_5 -> V_11 , 0 ) ;
F_25 ( & V_5 -> V_3 , V_41 , V_32 ) ;
V_5 -> V_3 . V_42 = F_1 ;
V_38 = F_26 ( V_7 -> V_23 ,
V_43 ) ;
if ( V_38 < 0 ) {
F_27 ( V_5 ) ;
return V_38 ;
}
F_28 ( V_7 , & V_44 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_23 -> V_24 ;
F_30 ( & V_5 -> V_3 ) ;
F_27 ( V_5 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_45 * V_46 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
int V_38 ;
V_38 = F_32 ( V_7 -> V_47 -> V_48 -> V_49 , V_46 , V_23 -> V_50 ,
V_23 -> V_51 , V_23 -> V_52 ) ;
F_33 ( L_1 , V_53 , V_38 ,
V_23 -> V_50 ,
& V_23 -> V_51 ,
V_23 -> V_52 ) ;
return V_38 ;
}
static int F_34 ( struct V_54 * V_47 , int V_13 )
{
struct V_6 * V_7 = V_47 -> V_55 [ V_13 ] . V_7 ;
struct V_56 * V_57 = & V_7 -> V_27 ;
T_2 V_58 = V_59 ;
V_57 -> V_49 . type = V_60 ;
V_57 -> V_49 . V_49 = V_47 -> V_48 -> V_49 ;
V_57 -> V_24 = NULL ;
V_57 -> V_61 = F_35 ( V_47 -> V_48 -> V_49 , V_58 , & V_57 -> V_62 , V_39 ) ;
if ( ! V_57 -> V_61 )
return - V_40 ;
V_57 -> V_63 = V_58 ;
return 0 ;
}
static int F_36 ( struct V_64 * V_65 )
{
struct V_66 * V_48 = V_65 -> V_48 -> V_66 ;
struct V_54 * V_47 = V_65 -> V_47 ;
int V_38 ;
V_38 = F_37 ( V_48 -> V_49 , F_38 ( 32 ) ) ;
if ( V_38 )
return V_38 ;
if ( V_47 -> V_55 [ V_14 ] . V_7 ) {
V_38 = F_34 ( V_47 ,
V_14 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_47 -> V_55 [ V_67 ] . V_7 ) {
V_38 = F_34 ( V_47 ,
V_67 ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_39 ( struct V_64 * V_65 )
{
struct V_54 * V_47 = V_65 -> V_47 ;
struct V_6 * V_7 ;
int V_38 ;
V_38 = F_36 ( V_65 ) ;
if ( V_38 )
return V_38 ;
V_7 = V_47 -> V_55 [ V_14 ] . V_7 ;
if ( V_7 ) {
struct V_56 * V_57 = & V_7 -> V_27 ;
V_68 = ( unsigned long ) V_57 -> V_61 ;
}
V_7 = V_47 -> V_55 [ V_67 ] . V_7 ;
if ( V_7 ) {
struct V_56 * V_57 = & V_7 -> V_27 ;
V_69 = ( unsigned long ) V_57 -> V_61 ;
}
F_40 ( & V_70 ,
& V_71 - & V_70 ) ;
return 0 ;
}
static void F_41 ( struct V_54 * V_47 )
{
struct V_6 * V_7 ;
struct V_56 * V_57 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
V_7 = V_47 -> V_55 [ V_13 ] . V_7 ;
if ( ! V_7 )
continue;
V_57 = & V_7 -> V_27 ;
if ( ! V_57 -> V_61 )
continue;
F_42 ( V_47 -> V_48 -> V_49 , V_57 -> V_63 , V_57 -> V_61 , V_57 -> V_62 ) ;
V_57 -> V_61 = NULL ;
}
}
static void F_43 ( struct V_54 * V_47 )
{
F_44 ( V_72 , 0 ) ;
F_45 ( & V_73 ) ;
F_41 ( V_47 ) ;
}
int F_46 ( struct V_74 * V_75 ,
struct V_76 * V_21 )
{
int V_38 ;
V_38 = F_47 ( & V_73 ) ;
if ( V_38 ) {
F_48 ( & V_75 -> V_49 , L_2 , V_38 ) ;
return V_38 ;
}
F_44 ( V_21 -> V_77 , 1 ) ;
V_72 = V_21 -> V_77 ;
V_33 = V_21 -> V_77 ;
V_78 = ( unsigned long ) V_21 -> V_79 ;
V_21 -> V_80 -> V_81 = 4 ;
V_21 -> V_82 -> V_81 = 6 ;
V_38 = F_49 ( & V_75 -> V_49 , & V_83 ) ;
if ( V_38 )
goto V_84;
return 0 ;
V_84:
F_44 ( V_72 , 0 ) ;
F_45 ( & V_73 ) ;
return V_38 ;
}
void F_50 ( struct V_74 * V_75 )
{
F_51 ( & V_75 -> V_49 ) ;
}
