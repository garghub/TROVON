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
F_19 ( & V_4 -> V_20 -> V_70 ) ;
return 0 ;
}
static int F_20 ( struct V_67 * V_67 , struct V_1 * V_1 )
{
struct V_3 * V_4 = F_18 ( V_67 -> V_68 ,
struct V_3 , V_69 ) ;
F_21 ( & V_4 -> V_20 -> V_70 ) ;
return 0 ;
}
static void F_22 ( struct V_71 * V_20 )
{
struct V_3 * V_4 = F_23 ( V_20 ) ;
F_24 ( & V_4 -> V_69 ) ;
F_25 ( L_13 , V_4 -> V_72 ) ;
F_26 ( & V_73 ) ;
F_27 ( & V_74 , V_4 -> V_72 ) ;
F_28 ( & V_73 ) ;
F_29 ( V_20 ) ;
F_29 ( V_4 ) ;
}
int F_30 ( struct V_3 * V_4 )
{
int V_18 ;
T_3 V_75 ;
F_26 ( & V_73 ) ;
V_18 = F_31 ( & V_74 , V_4 , 0 , V_76 , V_77 ) ;
if ( V_18 < 0 ) {
if ( V_18 == - V_78 ) {
F_32 ( L_14 ,
V_4 -> V_30 . V_79 ) ;
V_18 = - V_80 ;
}
goto V_81;
}
V_4 -> V_72 = V_18 ;
F_28 ( & V_73 ) ;
V_75 = F_33 ( F_34 ( V_82 ) , V_4 -> V_72 ) ;
F_35 ( & V_4 -> V_69 , & V_83 ) ;
V_4 -> V_69 . V_84 = V_4 -> V_30 . V_84 ;
V_18 = F_36 ( & V_4 -> V_69 , V_75 , 1 ) ;
if ( V_18 ) {
F_32 ( L_15 ,
V_4 -> V_30 . V_79 , F_34 ( V_82 ) , V_4 -> V_72 ) ;
goto V_85;
}
V_4 -> V_20 = F_37 ( V_86 , V_4 -> V_30 . V_20 , V_75 , V_4 ,
L_16 , V_4 -> V_72 ) ;
if ( F_38 ( V_4 -> V_20 ) ) {
V_18 = F_39 ( V_4 -> V_20 ) ;
goto V_87;
}
V_4 -> V_20 -> V_88 = F_22 ;
F_25 ( L_17 , V_4 -> V_30 . V_79 ,
F_34 ( V_82 ) , V_4 -> V_72 ) ;
return 0 ;
V_87:
F_24 ( & V_4 -> V_69 ) ;
V_85:
F_26 ( & V_73 ) ;
F_27 ( & V_74 , V_4 -> V_72 ) ;
V_81:
F_28 ( & V_73 ) ;
return V_18 ;
}
void F_40 ( struct V_3 * V_4 )
{
F_25 ( L_18 , V_4 -> V_72 ) ;
V_4 -> V_89 = NULL ;
F_41 ( V_86 , V_4 -> V_20 -> V_75 ) ;
}
struct V_3 * F_42 ( void const * V_90 )
{
struct V_3 * V_4 ;
unsigned V_72 ;
F_43 () ;
F_44 (&pps_idr, pps, id)
if ( V_90 == V_4 -> V_89 )
break;
F_45 () ;
return V_4 ;
}
static void T_4 F_46 ( void )
{
F_47 ( V_86 ) ;
F_48 ( V_82 , V_76 ) ;
}
static int T_5 F_49 ( void )
{
int V_18 ;
V_86 = F_50 ( V_91 , L_19 ) ;
if ( F_38 ( V_86 ) ) {
F_32 ( L_20 ) ;
return F_39 ( V_86 ) ;
}
V_86 -> V_92 = V_93 ;
V_18 = F_51 ( & V_82 , 0 , V_76 , L_19 ) ;
if ( V_18 < 0 ) {
F_32 ( L_21 ) ;
goto V_94;
}
F_52 ( L_22 , V_35 ) ;
F_52 ( L_23
L_24 , V_95 ) ;
return 0 ;
V_94:
F_47 ( V_86 ) ;
return V_18 ;
}
