static unsigned int F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
F_2 ( V_1 , & V_4 -> V_6 , V_2 ) ;
return V_7 | V_8 ;
}
static int F_3 ( int V_9 , struct V_1 * V_1 , int V_10 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_4 ( V_9 , V_1 , V_10 , & V_4 -> V_11 ) ;
}
static long F_5 ( struct V_1 * V_1 ,
unsigned int V_12 , unsigned long V_13 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_14 V_15 ;
void T_2 * V_16 = ( void T_2 * ) V_13 ;
int T_2 * V_17 = ( int T_2 * ) V_13 ;
int V_18 ;
switch ( V_12 ) {
case V_19 :
F_6 ( V_4 -> V_20 , L_1 ) ;
F_7 ( & V_4 -> V_21 ) ;
V_15 = V_4 -> V_15 ;
F_8 ( & V_4 -> V_21 ) ;
V_18 = F_9 ( V_16 , & V_15 , sizeof( struct V_14 ) ) ;
if ( V_18 )
return - V_22 ;
break;
case V_23 :
F_6 ( V_4 -> V_20 , L_2 ) ;
if ( ! F_10 ( V_24 ) )
return - V_25 ;
V_18 = F_11 ( & V_15 , V_16 , sizeof( struct V_14 ) ) ;
if ( V_18 )
return - V_22 ;
if ( ! ( V_15 . V_26 & ( V_27 | V_28 ) ) ) {
F_6 ( V_4 -> V_20 , L_3 ,
V_15 . V_26 ) ;
return - V_29 ;
}
if ( ( V_15 . V_26 & ~ V_4 -> V_30 . V_26 ) != 0 ) {
F_6 ( V_4 -> V_20 , L_4 ,
V_15 . V_26 ) ;
return - V_29 ;
}
F_7 ( & V_4 -> V_21 ) ;
V_4 -> V_15 = V_15 ;
if ( ( V_15 . V_26 & ( V_31 | V_32 ) ) == 0 ) {
F_6 ( V_4 -> V_20 , L_5 ,
V_15 . V_26 ) ;
V_4 -> V_15 . V_26 |= V_31 ;
}
if ( V_4 -> V_30 . V_26 & V_33 )
V_4 -> V_15 . V_26 |= V_33 ;
V_4 -> V_15 . V_34 = V_35 ;
F_8 ( & V_4 -> V_21 ) ;
break;
case V_36 :
F_6 ( V_4 -> V_20 , L_6 ) ;
V_18 = F_12 ( V_4 -> V_30 . V_26 , V_17 ) ;
if ( V_18 )
return - V_22 ;
break;
case V_37 : {
struct V_38 V_39 ;
unsigned int V_40 ;
F_6 ( V_4 -> V_20 , L_7 ) ;
V_18 = F_11 ( & V_39 , V_16 , sizeof( struct V_38 ) ) ;
if ( V_18 )
return - V_22 ;
V_40 = V_4 -> V_41 ;
if ( V_39 . V_42 . V_43 & V_44 )
V_18 = F_13 ( V_4 -> V_6 ,
V_40 != V_4 -> V_41 ) ;
else {
unsigned long V_45 ;
F_6 ( V_4 -> V_20 , L_8 ,
( long long ) V_39 . V_42 . V_46 ,
V_39 . V_42 . V_47 ) ;
V_45 = V_39 . V_42 . V_46 * V_48 ;
V_45 += V_39 . V_42 . V_47 / ( V_49 / V_48 ) ;
if ( V_45 != 0 ) {
V_18 = F_14 (
V_4 -> V_6 ,
V_40 != V_4 -> V_41 ,
V_45 ) ;
if ( V_18 == 0 )
return - V_50 ;
}
}
if ( V_18 == - V_51 ) {
F_6 ( V_4 -> V_20 , L_9 ) ;
return - V_52 ;
}
F_7 ( & V_4 -> V_21 ) ;
V_39 . V_30 . V_53 = V_4 -> V_53 ;
V_39 . V_30 . V_54 = V_4 -> V_54 ;
V_39 . V_30 . V_55 = V_4 -> V_55 ;
V_39 . V_30 . V_56 = V_4 -> V_56 ;
V_39 . V_30 . V_57 = V_4 -> V_57 ;
F_8 ( & V_4 -> V_21 ) ;
V_18 = F_9 ( V_16 , & V_39 , sizeof( struct V_38 ) ) ;
if ( V_18 )
return - V_22 ;
break;
}
case V_58 : {
struct V_59 V_60 ;
F_6 ( V_4 -> V_20 , L_10 ) ;
if ( ! F_10 ( V_24 ) )
return - V_25 ;
if ( F_11 ( & V_60 , V_16 ,
sizeof( struct V_59 ) ) )
return - V_22 ;
if ( ( V_60 . V_61 & ~ V_4 -> V_30 . V_26 ) != 0 ) {
F_15 ( V_4 -> V_20 , L_4 ,
V_60 . V_61 ) ;
return - V_29 ;
}
if ( V_60 . V_62 != V_31 ||
( V_60 . V_61 & ~ V_63 ) != 0 ||
V_60 . V_64 != V_65 ) {
F_15 ( V_4 -> V_20 , L_11
L_12 , V_60 . V_61 ) ;
return - V_29 ;
}
V_18 = F_16 ( V_4 , & V_60 ) ;
if ( V_18 < 0 )
return V_18 ;
break;
}
default:
return - V_66 ;
}
return 0 ;
}
static int F_17 ( struct V_67 * V_67 , struct V_1 * V_1 )
{
struct V_3 * V_4 = F_18 ( V_67 -> V_68 ,
struct V_3 , V_69 ) ;
V_1 -> V_5 = V_4 ;
return 0 ;
}
static int F_19 ( struct V_67 * V_67 , struct V_1 * V_1 )
{
return 0 ;
}
static void F_20 ( struct V_70 * V_20 )
{
struct V_3 * V_4 = F_21 ( V_20 ) ;
F_22 ( & V_71 ) ;
F_23 ( & V_72 , V_4 -> V_73 ) ;
F_24 ( & V_71 ) ;
F_25 ( V_20 ) ;
F_25 ( V_4 ) ;
}
int F_26 ( struct V_3 * V_4 )
{
int V_18 ;
T_3 V_74 ;
F_22 ( & V_71 ) ;
if ( F_27 ( & V_72 , V_75 ) == 0 ) {
F_24 ( & V_71 ) ;
return - V_76 ;
}
V_18 = F_28 ( & V_72 , V_4 , & V_4 -> V_73 ) ;
F_24 ( & V_71 ) ;
if ( V_18 < 0 )
return V_18 ;
V_4 -> V_73 &= V_77 ;
if ( V_4 -> V_73 >= V_78 ) {
F_29 ( L_13 ,
V_4 -> V_30 . V_79 ) ;
V_18 = - V_80 ;
goto V_81;
}
V_74 = F_30 ( F_31 ( V_82 ) , V_4 -> V_73 ) ;
F_32 ( & V_4 -> V_69 , & V_83 ) ;
V_4 -> V_69 . V_84 = V_4 -> V_30 . V_84 ;
V_18 = F_33 ( & V_4 -> V_69 , V_74 , 1 ) ;
if ( V_18 ) {
F_29 ( L_14 ,
V_4 -> V_30 . V_79 , F_31 ( V_82 ) , V_4 -> V_73 ) ;
goto V_81;
}
V_4 -> V_20 = F_34 ( V_85 , V_4 -> V_30 . V_20 , V_74 , V_4 ,
L_15 , V_4 -> V_73 ) ;
if ( F_35 ( V_4 -> V_20 ) )
goto V_86;
V_4 -> V_20 -> V_87 = F_20 ;
F_36 ( L_16 , V_4 -> V_30 . V_79 ,
F_31 ( V_82 ) , V_4 -> V_73 ) ;
return 0 ;
V_86:
F_37 ( & V_4 -> V_69 ) ;
V_81:
F_22 ( & V_71 ) ;
F_23 ( & V_72 , V_4 -> V_73 ) ;
F_24 ( & V_71 ) ;
return V_18 ;
}
void F_38 ( struct V_3 * V_4 )
{
F_39 ( V_85 , V_4 -> V_20 -> V_74 ) ;
F_37 ( & V_4 -> V_69 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( V_85 ) ;
F_42 ( V_82 , V_78 ) ;
}
static int T_5 F_43 ( void )
{
int V_18 ;
V_85 = F_44 ( V_88 , L_17 ) ;
if ( F_35 ( V_85 ) ) {
F_29 ( L_18 ) ;
return F_45 ( V_85 ) ;
}
V_85 -> V_89 = V_90 ;
V_18 = F_46 ( & V_82 , 0 , V_78 , L_17 ) ;
if ( V_18 < 0 ) {
F_29 ( L_19 ) ;
goto V_91;
}
F_47 ( L_20 , V_35 ) ;
F_47 ( L_21
L_22 , V_92 ) ;
return 0 ;
V_91:
F_41 ( V_85 ) ;
return V_18 ;
}
