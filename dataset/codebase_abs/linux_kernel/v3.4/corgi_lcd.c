static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( 10 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
F_1 ( V_2 , V_3 ) ;
F_1 ( V_2 , V_3 | V_5 ) ;
F_1 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_1 ( V_2 , V_6 | V_5 | V_7 ) ;
F_1 ( V_2 , V_6 | V_5 ) ;
F_1 ( V_2 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_6 )
{
F_1 ( V_2 , V_6 ) ;
F_1 ( V_2 , V_6 | V_5 ) ;
F_1 ( V_2 , V_6 | V_5 | V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_6 , T_1 V_3 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
if ( V_3 & 0x80 )
F_4 ( V_2 , V_6 | V_7 ) ;
else
F_4 ( V_2 , V_6 ) ;
V_3 <<= 1 ;
}
}
static void F_8 ( struct V_1 * V_2 , T_1 V_6 )
{
F_4 ( V_2 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
T_1 V_9 , T_1 V_3 )
{
F_5 ( V_2 , V_9 ) ;
F_7 ( V_2 , V_9 , 0x9c ) ;
F_8 ( V_2 , V_9 ) ;
F_7 ( V_2 , V_9 , 0x00 ) ;
F_8 ( V_2 , V_9 ) ;
F_7 ( V_2 , V_9 , V_3 ) ;
F_8 ( V_2 , V_9 ) ;
F_6 ( V_2 , V_9 ) ;
}
static int F_2 ( struct V_1 * V_2 , int V_10 , T_1 V_3 )
{
struct V_11 V_12 ;
struct V_13 V_14 = {
. V_15 = 1 ,
. V_16 = 1 ,
. V_17 = V_2 -> V_18 ,
} ;
V_2 -> V_18 [ 0 ] = ( ( V_10 & 0x07 ) << 5 ) | ( V_3 & 0x1f ) ;
F_10 ( & V_12 ) ;
F_11 ( & V_14 , & V_12 ) ;
return F_12 ( V_2 -> V_19 , & V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_20 )
{
int V_21 ;
switch( V_20 ) {
case V_22 :
V_21 = V_23 . V_24 ;
V_21 = ( V_21 < 0 ) ? V_25 :
V_25 | ( ( V_21 & 0xf ) << 1 ) ;
break;
case V_26 :
default:
V_21 = ( V_27 << 1 ) | V_25 ;
break;
}
F_2 ( V_2 , V_28 , V_21 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_29 ;
F_2 ( V_2 , V_30 ,
V_31 | V_32 |
V_33 | V_34 |
V_35 ) ;
F_2 ( V_2 , V_4 ,
V_5 | V_7 | V_36 |
V_37 | V_38 ) ;
F_2 ( V_2 , V_39 ,
V_40 | V_41 | V_42 ) ;
F_2 ( V_2 , V_39 ,
V_40 | V_41 | V_43 ) ;
F_15 ( 3 ) ;
F_2 ( V_2 , V_4 ,
V_5 | V_7 | V_44 |
V_37 | V_38 ) ;
F_2 ( V_2 , V_30 ,
V_33 | V_34 ) ;
V_29 = V_23 . V_29 ;
if ( V_29 < 0 )
V_29 = V_45 ;
F_9 ( V_2 , V_44 | V_37 |
V_38 , V_29 ) ;
F_2 ( V_2 , V_4 ,
V_5 | V_7 | V_44 |
V_37 | V_46 ) ;
F_2 ( V_2 , V_39 ,
V_40 | V_47 | V_43 ) ;
F_15 ( 2 ) ;
F_2 ( V_2 , V_30 , V_33 ) ;
F_2 ( V_2 , V_4 ,
V_5 | V_7 | V_44 |
V_48 | V_46 ) ;
F_2 ( V_2 , V_39 ,
V_49 | V_47 | V_43 ) ;
F_2 ( V_2 , V_30 , 0 ) ;
F_13 ( V_2 , V_2 -> V_20 ) ;
F_2 ( V_2 , V_50 ,
V_51 | V_52 |
V_53 | V_54 |
V_55 ) ;
F_3 ( 1000 ) ;
switch ( V_2 -> V_20 ) {
case V_22 :
F_2 ( V_2 , V_56 , V_57 ) ;
break;
case V_26 :
default:
F_2 ( V_2 , V_56 , V_58 ) ;
break;
}
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( 34 ) ;
F_2 ( V_2 , V_39 ,
V_40 | V_47 | V_43 ) ;
F_2 ( V_2 , V_30 , V_34 ) ;
F_2 ( V_2 , V_4 ,
V_44 | V_37 | V_46 ) ;
F_9 ( V_2 , V_44 | V_37 |
V_46 , 0 ) ;
F_2 ( V_2 , V_39 ,
V_40 | V_41 | V_43 ) ;
F_2 ( V_2 , V_4 ,
V_44 | V_37 | V_38 ) ;
F_2 ( V_2 , V_30 ,
V_32 | V_35 |
V_31 | V_34 ) ;
F_2 ( V_2 , V_4 ,
V_36 | V_37 | V_38 ) ;
F_2 ( V_2 , V_39 ,
V_40 | V_41 | V_42 ) ;
}
static int F_18 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_19 ( & V_60 -> V_63 ) ;
int V_20 = V_26 ;
if ( V_62 -> V_64 == 640 || V_62 -> V_64 == 480 )
V_20 = V_22 ;
if ( V_2 -> V_20 == V_20 )
return 0 ;
F_13 ( V_2 , V_20 ) ;
switch ( V_20 ) {
case V_22 :
F_2 ( V_2 , V_56 , V_57 ) ;
break;
case V_26 :
default:
F_2 ( V_2 , V_56 , V_58 ) ;
break;
}
V_2 -> V_20 = V_20 ;
return 0 ;
}
static int F_20 ( struct V_59 * V_60 , int V_65 )
{
struct V_1 * V_2 = F_19 ( & V_60 -> V_63 ) ;
if ( F_21 ( V_65 ) && ! F_21 ( V_2 -> V_65 ) )
F_14 ( V_2 ) ;
if ( ! F_21 ( V_65 ) && F_21 ( V_2 -> V_65 ) )
F_16 ( V_2 ) ;
V_2 -> V_65 = V_65 ;
return 0 ;
}
static int F_22 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_19 ( & V_60 -> V_63 ) ;
return V_2 -> V_65 ;
}
static int F_23 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_19 ( & V_67 -> V_63 ) ;
return V_2 -> V_68 ;
}
static int F_24 ( struct V_1 * V_2 , int V_68 )
{
int V_69 ;
if ( V_68 > 0x10 )
V_68 += 0x10 ;
F_2 ( V_2 , V_70 , V_68 ) ;
V_69 = ! ! ( V_68 & 0x20 ) ^ V_2 -> V_71 ;
if ( F_25 ( V_2 -> V_72 ) )
F_26 ( V_2 -> V_72 , V_69 ) ;
if ( F_25 ( V_2 -> V_73 ) )
F_26 ( V_2 -> V_73 , V_68 ) ;
if ( V_2 -> V_74 )
V_2 -> V_74 () ;
V_2 -> V_68 = V_68 ;
return 0 ;
}
static int F_27 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_19 ( & V_67 -> V_63 ) ;
int V_68 = V_67 -> V_75 . V_76 ;
if ( V_67 -> V_75 . V_65 != V_77 )
V_68 = 0 ;
if ( V_67 -> V_75 . V_78 != V_77 )
V_68 = 0 ;
if ( V_79 & V_80 )
V_68 = 0 ;
if ( ( V_79 & V_81 ) && V_68 > V_2 -> V_82 )
V_68 = V_2 -> V_82 ;
return F_24 ( V_2 , V_68 ) ;
}
void F_28 ( int V_83 )
{
if ( V_83 )
V_79 |= V_81 ;
else
V_79 &= ~ V_81 ;
F_29 ( V_84 -> V_85 ) ;
}
static int F_30 ( struct V_86 * V_87 , T_2 V_88 )
{
struct V_1 * V_2 = F_19 ( & V_87 -> V_63 ) ;
V_79 |= V_80 ;
F_24 ( V_2 , 0 ) ;
F_20 ( V_2 -> V_89 , V_90 ) ;
return 0 ;
}
static int F_31 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_19 ( & V_87 -> V_63 ) ;
V_79 &= ~ V_80 ;
F_20 ( V_2 -> V_89 , V_77 ) ;
F_29 ( V_2 -> V_85 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_86 * V_87 = V_2 -> V_19 ;
int V_93 ;
V_2 -> V_73 = - 1 ;
V_2 -> V_72 = - 1 ;
if ( F_25 ( V_92 -> V_73 ) ) {
V_93 = F_33 ( V_92 -> V_73 , L_1 ) ;
if ( V_93 ) {
F_34 ( & V_87 -> V_63 , L_2
L_3 , V_92 -> V_73 ) ;
return V_93 ;
}
V_2 -> V_73 = V_92 -> V_73 ;
F_35 ( V_2 -> V_73 , 0 ) ;
}
if ( F_25 ( V_92 -> V_72 ) ) {
V_93 = F_33 ( V_92 -> V_72 , L_4 ) ;
if ( V_93 ) {
F_34 ( & V_87 -> V_63 , L_2
L_5 , V_92 -> V_72 ) ;
goto V_94;
}
V_2 -> V_72 = V_92 -> V_72 ;
if ( F_25 ( V_2 -> V_73 ) ) {
V_2 -> V_71 = 1 ;
F_35 ( V_2 -> V_72 , 1 ) ;
} else {
V_2 -> V_71 = 0 ;
F_35 ( V_2 -> V_72 , 0 ) ;
}
}
return 0 ;
V_94:
if ( F_25 ( V_2 -> V_73 ) )
F_36 ( V_2 -> V_73 ) ;
return V_93 ;
}
static int T_3 F_37 ( struct V_86 * V_87 )
{
struct V_95 V_75 ;
struct V_91 * V_92 = V_87 -> V_63 . V_96 ;
struct V_1 * V_2 ;
int V_97 = 0 ;
if ( V_92 == NULL ) {
F_34 ( & V_87 -> V_63 , L_6 ) ;
return - V_98 ;
}
V_2 = F_38 ( sizeof( struct V_1 ) , V_99 ) ;
if ( ! V_2 ) {
F_34 ( & V_87 -> V_63 , L_7 ) ;
return - V_100 ;
}
V_2 -> V_19 = V_87 ;
V_2 -> V_89 = F_39 ( L_8 , & V_87 -> V_63 ,
V_2 , & V_101 ) ;
if ( F_40 ( V_2 -> V_89 ) ) {
V_97 = F_41 ( V_2 -> V_89 ) ;
goto V_102;
}
V_2 -> V_65 = V_90 ;
V_2 -> V_20 = ( V_92 ) ? V_92 -> V_103 : V_22 ;
memset ( & V_75 , 0 , sizeof( struct V_95 ) ) ;
V_75 . type = V_104 ;
V_75 . V_105 = V_92 -> V_106 ;
V_2 -> V_85 = F_42 ( L_9 , & V_87 -> V_63 , V_2 ,
& V_107 , & V_75 ) ;
if ( F_40 ( V_2 -> V_85 ) ) {
V_97 = F_41 ( V_2 -> V_85 ) ;
goto V_108;
}
V_2 -> V_85 -> V_75 . V_76 = V_92 -> V_109 ;
V_2 -> V_85 -> V_75 . V_65 = V_77 ;
V_97 = F_32 ( V_2 , V_92 ) ;
if ( V_97 )
goto V_110;
V_2 -> V_74 = V_92 -> V_74 ;
F_43 ( & V_87 -> V_63 , V_2 ) ;
F_20 ( V_2 -> V_89 , V_77 ) ;
F_29 ( V_2 -> V_85 ) ;
V_2 -> V_82 = V_92 -> V_82 ;
V_84 = V_2 ;
return 0 ;
V_110:
F_44 ( V_2 -> V_85 ) ;
V_108:
F_45 ( V_2 -> V_89 ) ;
V_102:
F_46 ( V_2 ) ;
return V_97 ;
}
static int T_4 F_47 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_19 ( & V_87 -> V_63 ) ;
V_2 -> V_85 -> V_75 . V_65 = V_77 ;
V_2 -> V_85 -> V_75 . V_76 = 0 ;
F_29 ( V_2 -> V_85 ) ;
F_44 ( V_2 -> V_85 ) ;
if ( F_25 ( V_2 -> V_73 ) )
F_36 ( V_2 -> V_73 ) ;
if ( F_25 ( V_2 -> V_72 ) )
F_36 ( V_2 -> V_72 ) ;
F_20 ( V_2 -> V_89 , V_90 ) ;
F_45 ( V_2 -> V_89 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
