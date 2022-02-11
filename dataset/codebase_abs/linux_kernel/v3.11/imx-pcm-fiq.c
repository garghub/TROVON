static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 V_11 ;
unsigned long V_12 ;
if ( ! F_3 ( & V_5 -> V_13 ) )
return V_14 ;
F_4 ( & V_11 ) ;
if ( V_7 -> V_15 == V_16 )
V_5 -> V_17 = V_11 . V_18 & 0xffff ;
else
V_5 -> V_17 = V_11 . V_19 & 0xffff ;
if ( V_5 -> V_17 >= V_5 -> V_20 )
V_12 = V_5 -> V_17 - V_5 -> V_20 ;
else
V_12 = V_9 -> V_21 + V_5 -> V_17
- V_5 -> V_20 ;
if ( V_12 >= V_5 -> V_22 ) {
F_5 ( V_7 ) ;
V_5 -> V_20 = V_5 -> V_17 ;
}
F_6 ( V_3 , F_7 ( V_5 -> V_23 ) ) ;
return V_24 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
V_5 -> V_28 = F_9 ( V_26 ) ;
V_5 -> V_29 = F_10 ( V_26 ) ;
V_5 -> V_22 = F_11 ( V_26 ) ;
V_5 -> V_17 = 0 ;
V_5 -> V_20 = 0 ;
V_5 -> V_23 = 1000000000 / F_12 ( V_26 ) *
F_13 ( V_26 ) ;
F_14 ( V_7 , & V_7 -> V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
struct V_10 V_11 ;
F_4 ( & V_11 ) ;
if ( V_7 -> V_15 == V_16 )
V_11 . V_18 = ( V_5 -> V_22 * V_5 -> V_29 - 1 ) << 16 ;
else
V_11 . V_19 = ( V_5 -> V_22 * V_5 -> V_29 - 1 ) << 16 ;
F_16 ( & V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , int V_31 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
switch ( V_31 ) {
case V_32 :
case V_33 :
case V_34 :
F_18 ( & V_5 -> V_13 , 1 ) ;
F_19 ( & V_5 -> V_3 , F_7 ( V_5 -> V_23 ) ,
V_35 ) ;
if ( ++ V_36 == 1 )
F_20 ( V_37 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
F_18 ( & V_5 -> V_13 , 0 ) ;
if ( -- V_36 == 0 )
F_21 ( V_37 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static T_1 F_22 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
return F_23 ( V_7 -> V_9 , V_5 -> V_17 ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 ;
int V_42 ;
V_5 = F_25 ( sizeof( * V_5 ) , V_43 ) ;
if ( V_5 == NULL )
return - V_44 ;
V_9 -> V_27 = V_5 ;
V_5 -> V_7 = V_7 ;
F_18 ( & V_5 -> V_13 , 0 ) ;
F_26 ( & V_5 -> V_3 , V_45 , V_35 ) ;
V_5 -> V_3 . V_46 = F_1 ;
V_42 = F_27 ( V_7 -> V_9 ,
V_47 ) ;
if ( V_42 < 0 ) {
F_28 ( V_5 ) ;
return V_42 ;
}
F_29 ( V_7 , & V_48 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = V_9 -> V_27 ;
F_31 ( & V_5 -> V_3 ) ;
F_28 ( V_5 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_49 * V_50 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
int V_42 ;
V_42 = F_33 ( V_7 -> V_51 -> V_52 -> V_53 , V_50 ,
V_9 -> V_54 , V_9 -> V_55 , V_9 -> V_56 ) ;
F_34 ( L_1 , V_57 , V_42 ,
V_9 -> V_54 ,
V_9 -> V_55 ,
V_9 -> V_56 ) ;
return V_42 ;
}
static int F_35 ( struct V_58 * V_51 , int V_15 )
{
struct V_6 * V_7 = V_51 -> V_59 [ V_15 ] . V_7 ;
struct V_60 * V_61 = & V_7 -> V_30 ;
T_2 V_28 = V_62 ;
V_61 -> V_53 . type = V_63 ;
V_61 -> V_53 . V_53 = V_51 -> V_52 -> V_53 ;
V_61 -> V_27 = NULL ;
V_61 -> V_64 = F_36 ( V_51 -> V_52 -> V_53 , V_28 ,
& V_61 -> V_65 , V_43 ) ;
if ( ! V_61 -> V_64 )
return - V_44 ;
V_61 -> V_66 = V_28 ;
return 0 ;
}
static int F_37 ( struct V_67 * V_68 )
{
struct V_69 * V_52 = V_68 -> V_52 -> V_69 ;
struct V_58 * V_51 = V_68 -> V_51 ;
int V_42 = 0 ;
if ( ! V_52 -> V_53 -> V_70 )
V_52 -> V_53 -> V_70 = & V_71 ;
if ( ! V_52 -> V_53 -> V_72 )
V_52 -> V_53 -> V_72 = F_38 ( 32 ) ;
if ( V_51 -> V_59 [ V_16 ] . V_7 ) {
V_42 = F_35 ( V_51 ,
V_16 ) ;
if ( V_42 )
goto V_73;
}
if ( V_51 -> V_59 [ V_74 ] . V_7 ) {
V_42 = F_35 ( V_51 ,
V_74 ) ;
if ( V_42 )
goto V_73;
}
V_73:
return V_42 ;
}
static int F_39 ( struct V_67 * V_68 )
{
struct V_58 * V_51 = V_68 -> V_51 ;
struct V_6 * V_7 ;
int V_42 ;
V_42 = F_37 ( V_68 ) ;
if ( V_42 )
return V_42 ;
V_7 = V_51 -> V_59 [ V_16 ] . V_7 ;
if ( V_7 ) {
struct V_60 * V_61 = & V_7 -> V_30 ;
V_75 = ( unsigned long ) V_61 -> V_64 ;
}
V_7 = V_51 -> V_59 [ V_74 ] . V_7 ;
if ( V_7 ) {
struct V_60 * V_61 = & V_7 -> V_30 ;
V_76 = ( unsigned long ) V_61 -> V_64 ;
}
F_40 ( & V_77 ,
& V_78 - & V_77 ) ;
return 0 ;
}
static void F_41 ( struct V_58 * V_51 )
{
struct V_6 * V_7 ;
struct V_60 * V_61 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_7 = V_51 -> V_59 [ V_15 ] . V_7 ;
if ( ! V_7 )
continue;
V_61 = & V_7 -> V_30 ;
if ( ! V_61 -> V_64 )
continue;
F_42 ( V_51 -> V_52 -> V_53 , V_61 -> V_66 ,
V_61 -> V_64 , V_61 -> V_65 ) ;
V_61 -> V_64 = NULL ;
}
}
static void F_43 ( struct V_58 * V_51 )
{
F_44 ( V_79 , 0 ) ;
F_45 ( & V_80 ) ;
F_41 ( V_51 ) ;
}
int F_46 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = F_47 ( V_82 ) ;
int V_42 ;
V_42 = F_48 ( & V_80 ) ;
if ( V_42 ) {
F_49 ( & V_82 -> V_53 , L_2 , V_42 ) ;
return V_42 ;
}
F_44 ( V_84 -> V_85 , 1 ) ;
V_79 = V_84 -> V_85 ;
V_37 = V_84 -> V_85 ;
V_86 = ( unsigned long ) V_84 -> V_87 ;
V_84 -> V_88 . V_89 = 4 ;
V_84 -> V_90 . V_89 = 6 ;
V_42 = F_50 ( & V_82 -> V_53 , & V_91 ) ;
if ( V_42 )
goto V_92;
return 0 ;
V_92:
F_44 ( V_79 , 0 ) ;
F_45 ( & V_80 ) ;
return V_42 ;
}
void F_51 ( struct V_81 * V_82 )
{
F_52 ( & V_82 -> V_53 ) ;
}
