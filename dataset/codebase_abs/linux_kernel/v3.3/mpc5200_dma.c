static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 T_2 * V_5 = V_3 -> V_6 ;
T_3 V_7 ;
V_7 = F_2 ( & V_5 -> V_8 ) ;
if ( V_3 -> V_9 . V_10 && ( V_7 & V_11 ) )
V_3 -> V_12 . V_13 ++ ;
if ( V_3 -> V_14 . V_10 && ( V_7 & V_15 ) )
V_3 -> V_12 . V_16 ++ ;
F_3 ( & V_5 -> V_17 , V_18 ) ;
return V_19 ;
}
static void F_4 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
V_23 = F_5 ( V_21 -> V_24 ) ;
V_23 -> V_25 = V_21 -> V_26 ;
V_23 -> V_27 [ 0 ] = V_21 -> V_28 -> V_29 + ( V_21 -> V_30 * V_21 -> V_26 ) ;
F_6 ( V_21 -> V_24 , NULL ) ;
V_21 -> V_30 = ( V_21 -> V_30 + 1 ) % V_21 -> V_28 -> V_31 ;
}
static T_1 F_7 ( int V_1 , void * V_32 )
{
struct V_20 * V_21 = V_32 ;
F_8 ( & V_21 -> V_3 -> V_33 ) ;
while ( F_9 ( V_21 -> V_24 ) ) {
F_10 ( V_21 -> V_24 , NULL , NULL ) ;
V_21 -> V_34 = ( V_21 -> V_34 + 1 ) % V_21 -> V_28 -> V_31 ;
V_21 -> V_35 ++ ;
F_4 ( V_21 ) ;
}
F_11 ( & V_21 -> V_3 -> V_33 ) ;
if ( V_21 -> V_10 )
F_12 ( V_21 -> V_36 ) ;
return V_19 ;
}
static int F_13 ( struct V_37 * V_38 )
{
F_14 ( V_38 , NULL ) ;
return 0 ;
}
static int F_15 ( struct V_37 * V_38 , int V_39 )
{
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_3 * V_3 = F_16 ( V_41 -> V_43 ) ;
struct V_44 * V_28 = V_38 -> V_28 ;
struct V_20 * V_21 = F_17 ( V_38 , V_3 ) ;
struct V_4 T_2 * V_5 = V_3 -> V_6 ;
T_3 V_45 ;
unsigned long V_46 ;
int V_47 ;
switch ( V_39 ) {
case V_48 :
F_18 ( V_3 -> V_49 , L_1 ,
V_38 -> V_50 -> V_36 , V_28 -> V_51 ,
( int ) V_28 -> V_52 , V_28 -> V_31 ) ;
V_21 -> V_26 = F_19 ( V_28 ,
V_28 -> V_52 ) ;
V_21 -> V_30 = 0 ;
V_21 -> V_34 = 0 ;
V_21 -> V_10 = 1 ;
V_21 -> V_35 = 0 ;
V_21 -> V_28 = V_28 ;
F_20 ( & V_3 -> V_33 , V_46 ) ;
if ( V_38 -> V_50 -> V_36 == V_53 )
F_21 ( V_21 -> V_24 ) ;
else
F_22 ( V_21 -> V_24 ) ;
for ( V_47 = 0 ; V_47 < V_28 -> V_31 ; V_47 ++ )
if ( ! F_23 ( V_21 -> V_24 ) )
F_4 ( V_21 ) ;
F_24 ( V_21 -> V_24 ) ;
F_25 ( & V_3 -> V_33 , V_46 ) ;
F_3 ( & V_5 -> V_17 , V_18 ) ;
break;
case V_54 :
F_18 ( V_3 -> V_49 , L_2 ,
V_38 -> V_50 -> V_36 , V_21 -> V_35 ) ;
V_21 -> V_10 = 0 ;
F_20 ( & V_3 -> V_33 , V_46 ) ;
F_26 ( V_21 -> V_24 ) ;
if ( V_38 -> V_50 -> V_36 == V_53 )
F_21 ( V_21 -> V_24 ) ;
else
F_22 ( V_21 -> V_24 ) ;
F_25 ( & V_3 -> V_33 , V_46 ) ;
break;
default:
F_18 ( V_3 -> V_49 , L_3 ,
V_38 -> V_50 -> V_36 , V_39 ) ;
return - V_55 ;
}
V_45 = 0 ;
if ( V_3 -> V_9 . V_10 )
V_45 |= V_11 ;
if ( V_3 -> V_14 . V_10 )
V_45 |= V_15 ;
F_27 ( & V_5 -> V_56 . V_45 , V_3 -> V_45 | V_45 ) ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 )
{
struct V_44 * V_28 = V_38 -> V_28 ;
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_3 * V_3 = F_16 ( V_41 -> V_43 ) ;
struct V_20 * V_21 ;
int V_57 ;
F_18 ( V_3 -> V_49 , L_4 , V_38 ) ;
if ( V_38 -> V_50 -> V_36 == V_53 )
V_21 = & V_3 -> V_14 ;
else
V_21 = & V_3 -> V_9 ;
F_29 ( V_38 , & V_58 ) ;
V_57 = F_30 ( V_28 ,
V_59 ) ;
if ( V_57 < 0 ) {
F_31 ( V_38 -> V_60 -> V_61 -> V_49 , L_5 ) ;
return V_57 ;
}
V_21 -> V_36 = V_38 ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 )
{
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_3 * V_3 = F_16 ( V_41 -> V_43 ) ;
struct V_20 * V_21 ;
F_18 ( V_3 -> V_49 , L_6 , V_38 ) ;
if ( V_38 -> V_50 -> V_36 == V_53 )
V_21 = & V_3 -> V_14 ;
else
V_21 = & V_3 -> V_9 ;
if ( ! V_3 -> V_9 . V_10 &&
! V_3 -> V_14 . V_10 ) {
F_27 ( & V_3 -> V_6 -> V_56 . V_45 , V_3 -> V_45 ) ;
F_3 ( & V_3 -> V_6 -> V_17 , 4 << 4 ) ;
}
V_21 -> V_36 = NULL ;
return 0 ;
}
static T_4
F_33 ( struct V_37 * V_38 )
{
struct V_40 * V_41 = V_38 -> V_42 ;
struct V_3 * V_3 = F_16 ( V_41 -> V_43 ) ;
struct V_20 * V_21 ;
T_5 V_62 ;
if ( V_38 -> V_50 -> V_36 == V_53 )
V_21 = & V_3 -> V_14 ;
else
V_21 = & V_3 -> V_9 ;
V_62 = V_21 -> V_34 * V_21 -> V_26 ;
return F_34 ( V_38 -> V_28 , V_62 ) ;
}
static int
F_35 ( struct V_37 * V_38 ,
struct V_63 * V_64 )
{
F_14 ( V_38 , & V_38 -> V_65 ) ;
return 0 ;
}
static int F_36 ( struct V_40 * V_41 )
{
struct V_66 * V_61 = V_41 -> V_61 -> V_66 ;
struct V_67 * V_68 = V_41 -> V_43 ;
struct V_69 * V_60 = V_41 -> V_60 ;
struct V_3 * V_3 = F_16 ( V_41 -> V_43 ) ;
T_6 V_70 = V_58 . V_71 ;
int V_57 = 0 ;
F_18 ( V_41 -> V_72 -> V_49 , L_7 ,
V_61 , V_68 , V_60 ) ;
if ( ! V_61 -> V_49 -> V_73 )
V_61 -> V_49 -> V_73 = & V_74 ;
if ( ! V_61 -> V_49 -> V_75 )
V_61 -> V_49 -> V_75 = 0xffffffff ;
if ( V_60 -> V_76 [ 0 ] . V_38 ) {
V_57 = F_37 ( V_77 , V_60 -> V_61 -> V_49 ,
V_70 , & V_60 -> V_76 [ 0 ] . V_38 -> V_65 ) ;
if ( V_57 )
goto V_78;
}
if ( V_60 -> V_76 [ 1 ] . V_38 ) {
V_57 = F_37 ( V_77 , V_60 -> V_61 -> V_49 ,
V_70 , & V_60 -> V_76 [ 1 ] . V_38 -> V_65 ) ;
if ( V_57 )
goto V_79;
}
if ( V_41 -> V_80 -> V_81 )
V_41 -> V_80 -> V_81 -> V_42 = V_3 ;
return 0 ;
V_79:
if ( V_60 -> V_76 [ 0 ] . V_38 )
F_38 ( & V_60 -> V_76 [ 0 ] . V_38 -> V_65 ) ;
V_78:
F_31 ( V_61 -> V_49 , L_8 ) ;
return - V_82 ;
}
static void F_39 ( struct V_69 * V_60 )
{
struct V_40 * V_41 = V_60 -> V_42 ;
struct V_37 * V_38 ;
int V_36 ;
F_18 ( V_41 -> V_72 -> V_49 , L_9 , V_60 ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
V_38 = V_60 -> V_76 [ V_36 ] . V_38 ;
if ( V_38 ) {
F_38 ( & V_38 -> V_65 ) ;
V_38 -> V_65 . V_83 = NULL ;
V_38 -> V_65 . V_84 = 0 ;
}
}
}
static int F_40 ( struct V_85 * V_86 )
{
T_7 V_87 ;
struct V_3 * V_3 ;
struct V_88 V_89 ;
int V_70 , V_1 , V_57 ;
const T_8 * V_90 ;
void T_2 * V_5 ;
int V_91 ;
V_1 = F_41 ( V_86 -> V_49 . V_92 , 0 ) ;
if ( F_42 ( V_86 -> V_49 . V_92 , 0 , & V_89 ) ) {
F_31 ( & V_86 -> V_49 , L_10 ) ;
return - V_93 ;
}
V_5 = F_43 ( V_89 . V_94 , F_44 ( & V_89 ) ) ;
if ( ! V_5 ) {
F_31 ( & V_86 -> V_49 , L_11 ) ;
return - V_93 ;
}
V_3 = F_45 ( sizeof *V_3 , V_95 ) ;
if ( ! V_3 ) {
V_91 = - V_82 ;
goto V_96;
}
V_90 = F_46 ( V_86 -> V_49 . V_92 , L_12 , & V_70 ) ;
if ( ! V_90 || V_70 < sizeof *V_90 ) {
V_91 = - V_93 ;
goto V_97;
}
F_47 ( & V_3 -> V_33 ) ;
F_48 ( & V_3 -> V_98 ) ;
V_3 -> V_99 = F_49 ( * V_90 ) ;
V_3 -> V_1 = V_1 ;
V_3 -> V_6 = V_5 ;
V_3 -> V_100 = V_5 + sizeof * V_3 -> V_6 ;
V_3 -> V_49 = & V_86 -> V_49 ;
V_3 -> V_9 . V_3 = V_3 ;
V_3 -> V_14 . V_3 = V_3 ;
snprintf ( V_3 -> V_101 , sizeof V_3 -> V_101 , L_13 , V_3 -> V_99 ) ;
V_87 = V_89 . V_94 + F_50 ( struct V_4 , V_102 . V_103 ) ;
V_3 -> V_14 . V_24 =
F_51 ( V_3 -> V_99 , 10 , V_87 , 512 ) ;
V_3 -> V_9 . V_24 =
F_52 ( V_3 -> V_99 , 10 , V_87 ) ;
if ( ! V_3 -> V_14 . V_24 ||
! V_3 -> V_9 . V_24 ) {
F_31 ( & V_86 -> V_49 , L_14 ) ;
V_91 = - V_93 ;
goto V_97;
}
F_27 ( & V_3 -> V_6 -> V_56 . V_45 , V_3 -> V_45 ) ;
F_3 ( & V_3 -> V_6 -> V_17 , V_104 ) ;
F_3 ( & V_3 -> V_6 -> V_17 , V_105 ) ;
F_3 ( & V_3 -> V_6 -> V_17 , V_18 ) ;
F_3 ( & V_3 -> V_6 -> V_17 , V_106 ) ;
F_3 ( & V_3 -> V_6 -> V_107 , 0 ) ;
F_3 ( & V_3 -> V_6 -> V_107 , 0 ) ;
F_27 ( & V_3 -> V_100 -> V_108 , 0x100 ) ;
F_3 ( & V_3 -> V_100 -> V_109 , 0x4 ) ;
F_27 ( & V_3 -> V_100 -> V_110 , 0x100 ) ;
F_3 ( & V_3 -> V_100 -> V_111 , 0x7 ) ;
V_3 -> V_9 . V_1 =
F_53 ( V_3 -> V_9 . V_24 ) ;
V_3 -> V_14 . V_1 =
F_53 ( V_3 -> V_14 . V_24 ) ;
V_57 = F_54 ( V_3 -> V_1 , & F_1 , V_112 ,
L_15 , V_3 ) ;
V_57 |= F_54 ( V_3 -> V_14 . V_1 , & F_7 , V_112 ,
L_16 , & V_3 -> V_14 ) ;
V_57 |= F_54 ( V_3 -> V_9 . V_1 , & F_7 , V_112 ,
L_17 , & V_3 -> V_9 ) ;
if ( V_57 ) {
V_91 = - V_93 ;
goto V_113;
}
F_55 ( & V_86 -> V_49 , V_3 ) ;
return F_56 ( & V_86 -> V_49 , & V_114 ) ;
V_113:
F_57 ( V_3 -> V_1 , V_3 ) ;
F_57 ( V_3 -> V_14 . V_1 , & V_3 -> V_14 ) ;
F_57 ( V_3 -> V_9 . V_1 , & V_3 -> V_9 ) ;
V_97:
F_58 ( V_3 ) ;
V_96:
F_59 ( V_5 ) ;
return V_91 ;
}
static int F_60 ( struct V_85 * V_86 )
{
struct V_3 * V_3 = F_61 ( & V_86 -> V_49 ) ;
F_18 ( & V_86 -> V_49 , L_18 ) ;
F_62 ( & V_86 -> V_49 ) ;
F_63 ( V_3 -> V_14 . V_24 ) ;
F_64 ( V_3 -> V_9 . V_24 ) ;
F_57 ( V_3 -> V_1 , V_3 ) ;
F_57 ( V_3 -> V_14 . V_1 , & V_3 -> V_14 ) ;
F_57 ( V_3 -> V_9 . V_1 , & V_3 -> V_9 ) ;
F_59 ( V_3 -> V_6 ) ;
F_58 ( V_3 ) ;
F_55 ( & V_86 -> V_49 , NULL ) ;
return 0 ;
}
