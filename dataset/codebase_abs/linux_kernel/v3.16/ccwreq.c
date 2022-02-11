int F_1 ( int V_1 , int V_2 )
{
while ( V_1 && ( ( V_1 & V_2 ) == 0 ) )
V_1 >>= 1 ;
return V_1 ;
}
static T_1 F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
if ( ! V_6 -> V_8 ) {
V_6 -> V_2 = 0 ;
goto V_9;
}
V_6 -> V_10 = V_6 -> V_11 ;
V_6 -> V_2 = F_1 ( V_6 -> V_2 >> 1 , V_6 -> V_1 ) ;
V_9:
return V_6 -> V_2 ;
}
static void F_3 ( struct V_3 * V_4 , int V_12 )
{
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
if ( V_6 -> V_13 )
return;
V_6 -> V_13 = 1 ;
F_4 ( V_4 , 0 ) ;
memset ( & V_4 -> V_7 -> V_14 , 0 , sizeof( struct V_14 ) ) ;
if ( V_12 && V_12 != - V_15 && V_6 -> V_16 )
V_12 = V_6 -> V_16 ;
V_6 -> V_17 ( V_4 , V_6 -> V_18 , V_12 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
struct V_19 * V_20 = F_6 ( V_4 -> V_21 . V_22 ) ;
struct V_23 * V_24 = V_6 -> V_24 ;
int V_12 = - V_25 ;
while ( V_6 -> V_2 ) {
if ( V_6 -> V_10 -- == 0 ) {
F_2 ( V_4 ) ;
continue;
}
memset ( & V_4 -> V_7 -> V_14 , 0 , sizeof( struct V_14 ) ) ;
V_12 = F_7 ( V_20 , V_24 , ( V_26 ) V_6 -> V_2 ) ;
if ( V_12 == 0 ) {
F_4 ( V_4 , V_6 -> V_27 ) ;
return;
}
if ( V_12 == - V_15 ) {
break;
}
if ( V_12 == - V_25 ) {
F_2 ( V_4 ) ;
continue;
}
V_12 = F_8 ( V_20 ) ;
if ( V_12 )
break;
return;
}
F_3 ( V_4 , V_12 ) ;
}
void F_9 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
if ( V_6 -> V_8 ) {
V_6 -> V_2 = 0x8080 ;
} else
V_6 -> V_2 = V_6 -> V_1 ;
V_6 -> V_10 = V_6 -> V_11 ;
V_6 -> V_2 = F_1 ( V_6 -> V_2 , V_6 -> V_1 ) ;
V_6 -> V_16 = 0 ;
V_6 -> V_13 = 0 ;
V_6 -> V_28 = 0 ;
if ( ! V_6 -> V_2 )
goto V_29;
F_5 ( V_4 ) ;
return;
V_29:
F_3 ( V_4 , - V_25 ) ;
}
int F_10 ( struct V_3 * V_4 )
{
struct V_19 * V_20 = F_6 ( V_4 -> V_21 . V_22 ) ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
int V_12 ;
if ( V_6 -> V_13 )
return 1 ;
V_6 -> V_28 = 1 ;
V_12 = F_8 ( V_20 ) ;
if ( V_12 )
F_3 ( V_4 , V_12 ) ;
return 0 ;
}
static enum V_30 F_11 ( struct V_3 * V_4 , struct V_14 * V_31 )
{
struct V_14 * V_14 = & V_4 -> V_7 -> V_14 ;
struct V_32 * V_33 = & V_14 -> V_33 . V_34 ;
enum V_35 V_36 ;
if ( F_12 ( V_4 , V_31 ) )
return V_37 ;
if ( V_33 -> V_38 & ( V_39 | V_40 ) )
return V_41 ;
if ( V_33 -> V_42 == 3 || V_33 -> V_43 )
return V_44 ;
if ( V_14 -> V_45 . V_46 . V_47 . V_48 ) {
F_13 ( 2 , L_1 ) ;
F_14 ( 2 , & V_4 -> V_7 -> V_49 ,
sizeof( struct V_50 ) ) ;
F_14 ( 2 , & V_4 -> V_7 -> V_14 . V_51 , V_52 ) ;
if ( V_14 -> V_51 [ 0 ] & V_53 )
return V_54 ;
if ( V_4 -> V_55 && V_4 -> V_55 -> V_56 ) {
V_36 = V_4 -> V_55 -> V_56 ( V_4 , V_31 ) ;
F_13 ( 2 , L_2 ) ;
F_14 ( 2 , & V_36 , sizeof( V_36 ) ) ;
switch ( V_36 ) {
case V_57 :
return V_58 ;
case V_59 :
return V_44 ;
case V_60 :
return V_54 ;
default:
return V_58 ;
}
}
return V_58 ;
}
if ( V_33 -> V_61 != 0 )
return V_58 ;
if ( V_33 -> V_62 & ~ ( V_63 | V_64 ) )
return V_58 ;
if ( ! ( V_33 -> V_62 & V_64 ) )
return V_37 ;
if ( V_33 -> V_42 == 1 && ( V_33 -> V_65 & V_66 ) )
return V_58 ;
return V_67 ;
}
static void F_15 ( struct V_3 * V_4 , enum V_30 V_68 )
{
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
struct {
struct V_50 V_49 ;
T_1 V_10 ;
V_26 V_1 ;
V_26 V_68 ;
} V_69 ( ( V_70 ) ) V_18 ;
V_18 . V_49 = V_4 -> V_7 -> V_49 ;
V_18 . V_10 = V_6 -> V_10 ;
V_18 . V_1 = ( V_26 ) V_6 -> V_2 ;
V_18 . V_68 = ( V_26 ) V_68 ;
F_13 ( 2 , L_3 ) ;
F_14 ( 2 , & V_18 , sizeof( V_18 ) ) ;
}
void F_16 ( struct V_3 * V_4 )
{
struct V_14 * V_14 = & F_17 ( V_71 ) ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
enum V_30 V_68 ;
int V_12 = - V_72 ;
V_68 = F_11 ( V_4 , V_14 ) ;
if ( V_6 -> V_73 )
V_68 = V_6 -> V_73 ( V_4 , V_6 -> V_18 , V_14 , V_68 ) ;
if ( V_68 != V_37 )
F_4 ( V_4 , 0 ) ;
if ( V_68 != V_67 && V_68 != V_37 )
F_15 ( V_4 , V_68 ) ;
switch ( V_68 ) {
case V_67 :
break;
case V_37 :
return;
case V_54 :
goto V_74;
case V_44 :
goto V_75;
case V_58 :
goto V_76;
case V_41 :
if ( V_6 -> V_28 ) {
V_12 = - V_77 ;
goto V_74;
}
goto V_76;
}
if ( ! V_6 -> V_78 )
goto V_9;
switch ( V_6 -> V_78 ( V_4 , V_6 -> V_18 ) ) {
case 0 :
break;
case - V_79 :
goto V_76;
case - V_25 :
goto V_75;
default:
goto V_74;
}
V_9:
F_3 ( V_4 , 0 ) ;
return;
V_75:
if ( ! F_2 ( V_4 ) ) {
V_12 = - V_25 ;
goto V_74;
}
V_76:
F_5 ( V_4 ) ;
return;
V_74:
F_3 ( V_4 , V_12 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
struct V_19 * V_20 = F_6 ( V_4 -> V_21 . V_22 ) ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
int V_12 = - V_15 , V_80 ;
if ( F_19 ( V_20 ) )
goto V_74;
for ( V_80 = 0 ; V_80 < 8 ; V_80 ++ ) {
if ( ( 0x80 >> V_80 ) & V_20 -> V_81 . V_82 . V_83 )
F_20 ( L_4
L_5 ,
F_21 ( & V_4 -> V_21 ) , V_6 -> V_27 / V_84 ,
F_22 ( & V_20 -> V_81 . V_33 ) ,
F_23 ( & V_20 -> V_81 . V_33 ) ,
V_20 -> V_85 . V_86 ,
V_20 -> V_81 . V_82 . V_87 [ V_80 ] ) ;
}
if ( ! F_2 ( V_4 ) ) {
V_6 -> V_16 = - V_88 ;
}
V_12 = F_8 ( V_20 ) ;
if ( V_12 )
goto V_74;
return;
V_74:
F_3 ( V_4 , V_12 ) ;
}
void F_24 ( struct V_3 * V_4 )
{
F_3 ( V_4 , - V_15 ) ;
}
