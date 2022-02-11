static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_7 , V_3 , V_4 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 , unsigned int V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_9 ;
int V_10 ;
V_10 = F_5 ( V_6 -> V_7 , V_8 , & V_9 ) ;
if ( V_10 < 0 )
return - 1 ;
return V_9 ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_1 ( V_2 , V_11 , V_12 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
F_1 ( V_2 , V_14 , 0 ) ;
V_6 -> V_15 = V_16 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_17 )
{
int V_18 = 4000 ;
int V_9 ;
V_9 = F_4 ( V_2 , V_3 ) ;
while ( ! ( V_9 & V_17 ) && -- V_18 ) {
F_8 ( 1 ) ;
V_9 = F_4 ( V_2 , V_3 ) ;
}
if ( V_18 == 0 )
return 0 ;
else
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
int V_10 ;
F_11 ( V_6 -> V_15 != V_16 ) ;
F_12 ( & V_2 -> V_20 , L_1 ) ;
if ( ! V_6 -> V_21 ) {
F_12 ( & V_2 -> V_20 , L_2 ) ;
F_1 ( V_2 , V_11 ,
V_22 ) ;
} else {
F_12 ( & V_2 -> V_20 , L_3 ) ;
F_1 ( V_2 , V_11 ,
V_23 ) ;
}
F_1 ( V_2 , V_11 , V_12 ) ;
F_1 ( V_2 , V_11 , V_24 ) ;
if ( ! F_7 ( V_2 , V_25 ,
V_26 ) ) {
F_13 ( & V_2 -> V_20 , L_4 ) ;
return - V_27 ;
}
if ( ! F_7 ( V_2 , V_28 ,
V_29 ) ) {
F_13 ( & V_2 -> V_20 , L_5 ) ;
return - V_27 ;
}
F_1 ( V_2 , V_11 , V_30 ) ;
F_12 ( & V_2 -> V_20 , L_6 ,
V_6 -> V_31 - 2 ) ;
V_10 = F_14 ( V_2 , V_6 -> V_32 ,
V_6 -> V_31 ) ;
if ( V_10 < 0 ) {
F_13 ( & V_2 -> V_20 , L_7 , V_10 ) ;
return V_10 ;
}
if ( V_10 != V_6 -> V_31 ) {
F_13 ( & V_2 -> V_20 , L_8 ,
V_10 , V_6 -> V_31 ) ;
return - V_33 ;
}
F_12 ( & V_2 -> V_20 , L_9 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_34 , 248 / 4 ) ;
F_1 ( V_2 , V_35 ,
V_36 |
V_37 |
V_38 ) ;
} else {
F_1 ( V_2 , V_35 ,
V_37 |
V_38 ) ;
}
V_10 = F_4 ( V_2 , V_39 ) ;
if ( V_6 -> V_40 )
V_10 &= ~ V_41 ;
else
V_10 |= V_41 ;
F_1 ( V_2 , V_39 , V_10 ) ;
F_1 ( V_2 , V_42 , 0x33 ) ;
F_1 ( V_2 , V_43 , 0x02 ) ;
F_1 ( V_2 , V_11 , V_44 ) ;
if ( ! F_7 ( V_2 , V_28 ,
V_45 ) ) {
F_13 ( & V_2 -> V_20 , L_10 ) ;
return - V_27 ;
}
F_12 ( & V_2 -> V_20 , L_11 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_12 ) ;
V_6 -> V_15 = V_46 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_47 , 248 / 4 ) ;
F_1 ( V_2 , V_35 ,
V_36 |
V_48 ) ;
} else {
F_1 ( V_2 , V_35 ,
V_48 ) ;
}
if ( ! F_7 ( V_2 , V_28 ,
V_49 ) ) {
F_13 ( & V_2 -> V_20 , L_13 ) ;
return - V_27 ;
}
if ( ! F_7 ( V_2 , V_25 ,
V_26 ) ) {
F_13 ( & V_2 -> V_20 , L_14 ) ;
return - V_27 ;
}
F_12 ( & V_2 -> V_20 , L_15 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_46 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_35 ,
V_36 |
V_38 |
V_50 ) ;
} else {
F_1 ( V_2 , V_35 ,
V_38 |
V_50 ) ;
}
if ( ! F_7 ( V_2 , V_28 ,
V_51 ) ) {
F_13 ( & V_2 -> V_20 , L_16 ) ;
return - V_27 ;
}
if ( ! F_7 ( V_2 , V_25 ,
V_26 ) ) {
F_13 ( & V_2 -> V_20 , L_14 ) ;
return - V_27 ;
}
F_1 ( V_2 , V_52 , V_53 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_54 ;
F_12 ( & V_2 -> V_20 , L_17 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_54 ) ;
F_1 ( V_2 , V_52 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_35 ,
V_36 |
V_37 |
V_38 ) ;
} else {
F_1 ( V_2 , V_35 ,
V_37 |
V_38 ) ;
}
F_1 ( V_2 , V_11 , V_30 ) ;
F_1 ( V_2 , V_11 , V_44 ) ;
if ( ! F_7 ( V_2 , V_28 ,
V_45 ) ) {
F_13 ( & V_2 -> V_20 , L_18 ) ;
return - V_27 ;
}
V_6 -> V_15 = V_46 ;
F_12 ( & V_2 -> V_20 , L_19 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_46 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_47 , 248 / 4 ) ;
F_1 ( V_2 , V_35 ,
V_36 |
V_38 |
V_55 ) ;
} else {
F_1 ( V_2 , V_35 ,
V_38 |
V_55 ) ;
}
if ( ! F_7 ( V_2 , V_28 ,
V_51 ) ) {
F_13 ( & V_2 -> V_20 ,
L_20 ) ;
return - V_27 ;
}
if ( ! F_7 ( V_2 , V_25 , V_26 ) ) {
F_13 ( & V_2 -> V_20 ,
L_21 ) ;
return - V_27 ;
}
F_1 ( V_2 , V_52 , V_53 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_56 ;
F_12 ( & V_2 -> V_20 , L_22 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_23 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_56 ) ;
F_1 ( V_2 , V_52 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_34 , 248 / 4 ) ;
F_1 ( V_2 , V_35 ,
V_36 |
V_38 |
V_37 ) ;
} else {
F_1 ( V_2 , V_35 ,
V_38 |
V_37 ) ;
}
F_1 ( V_2 , V_11 , V_30 ) ;
F_1 ( V_2 , V_11 , V_44 ) ;
if ( ! F_7 ( V_2 , V_28 ,
V_45 ) ) {
F_13 ( & V_2 -> V_20 , L_18 ) ;
return - V_27 ;
}
V_6 -> V_15 = V_46 ;
F_12 ( & V_2 -> V_20 , L_19 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_24 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
enum V_57 V_58 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_59 , V_60 ;
int V_10 ;
if ( V_6 -> V_15 == V_58 )
return 0 ;
for ( V_59 = 0 ; V_59 < F_21 ( V_61 ) ; V_59 ++ )
if ( V_61 [ V_59 ] . V_62 == V_6 -> V_15 &&
V_61 [ V_59 ] . V_63 == V_58 )
break;
if ( V_59 == F_21 ( V_61 ) ) {
F_13 ( & V_2 -> V_20 , L_25 ,
V_6 -> V_15 , V_58 ) ;
return - V_64 ;
}
for ( V_60 = 0 ; V_60 < F_21 ( V_61 [ V_60 ] . V_65 ) ; V_60 ++ ) {
if ( ! V_61 [ V_59 ] . V_65 [ V_60 ] )
break;
V_10 = V_61 [ V_59 ] . V_65 [ V_60 ] ( V_2 ,
V_61 [ V_59 ] . V_19 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_57 V_58 ;
if ( V_6 -> V_66 && V_6 -> V_67 )
if ( V_6 -> V_68 )
V_58 = V_46 ;
else
V_58 = V_54 ;
else
V_58 = V_56 ;
F_12 ( & V_2 -> V_20 , L_26 ,
V_58 , V_6 -> V_66 , ! V_6 -> V_67 ,
V_6 -> V_68 ) ;
return F_20 ( V_6 , V_58 ) ;
}
static int F_23 ( struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = F_24 ( V_70 ) ;
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
V_72 -> V_4 . V_75 . V_76 [ 0 ] = V_6 -> V_68 ;
return 0 ;
}
static int F_25 ( struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = F_24 ( V_70 ) ;
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
int V_68 = V_72 -> V_4 . V_75 . V_76 [ 0 ] ;
if ( V_68 > 1 )
return - V_64 ;
V_6 -> V_68 = V_68 ;
return F_22 ( V_6 ) ;
}
static int F_26 ( struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = F_24 ( V_70 ) ;
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
V_72 -> V_4 . V_75 . V_76 [ 0 ] = V_6 -> V_67 ;
return 0 ;
}
static int F_27 ( struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = F_24 ( V_70 ) ;
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
int V_9 = V_72 -> V_4 . V_75 . V_76 [ 0 ] ;
if ( V_9 > 1 )
return - V_64 ;
V_6 -> V_67 = V_9 ;
return F_22 ( V_6 ) ;
}
static int F_28 ( struct V_77 * V_78 ,
struct V_69 * V_70 , int V_79 )
{
struct V_73 * V_74 = F_24 ( V_70 ) ;
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
if ( F_29 ( V_79 ) )
V_6 -> V_66 = 1 ;
if ( F_30 ( V_79 ) )
V_6 -> V_66 = 0 ;
return F_22 ( V_6 ) ;
}
static int F_31 ( struct V_73 * V_74 )
{
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
return F_20 ( V_6 , V_16 ) ;
}
static int F_32 ( struct V_73 * V_74 )
{
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
return F_22 ( V_6 ) ;
}
static bool F_33 ( struct V_80 * V_20 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_81 :
case V_39 :
case V_82 :
case V_47 :
case V_34 :
case V_83 :
case V_84 :
case V_28 :
case V_35 :
case V_42 :
case V_43 :
case V_14 :
case V_85 :
case V_86 :
case V_52 :
case V_11 :
case V_25 :
case V_87 :
return true ;
default:
return false ;
}
}
static int F_34 ( struct V_73 * V_74 )
{
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
F_22 ( V_6 ) ;
return 0 ;
}
static int F_35 ( struct V_73 * V_74 )
{
struct V_5 * V_6 = F_10 ( V_74 -> V_20 ) ;
return F_20 ( V_6 , V_16 ) ;
}
static int T_2 F_36 ( struct V_1 * V_2 ,
const struct V_88 * V_89 )
{
struct V_5 * V_6 ;
struct V_90 * V_91 ;
const char * V_92 ;
const struct V_93 * V_94 = NULL ;
int V_10 ;
int V_3 ;
T_3 V_95 ;
V_6 = F_37 ( & V_2 -> V_20 , sizeof( struct V_5 ) ,
V_96 ) ;
if ( V_6 == NULL ) {
F_13 ( & V_2 -> V_20 , L_27 ) ;
return - V_97 ;
}
F_38 ( & V_2 -> V_20 , V_6 ) ;
V_6 -> V_7 = F_39 ( V_2 , & V_98 ) ;
if ( F_40 ( V_6 -> V_7 ) ) {
V_10 = F_41 ( V_6 -> V_7 ) ;
F_13 ( & V_2 -> V_20 , L_28 ,
V_10 ) ;
goto V_99;
}
V_3 = F_4 ( V_2 , V_14 ) ;
V_95 = V_3 << 8 ;
V_3 = F_4 ( V_2 , V_85 ) ;
V_95 |= V_3 & 0xff ;
if ( V_95 != 0x2000 ) {
F_13 ( & V_2 -> V_20 , L_29 , V_95 ) ;
V_10 = - V_100 ;
goto V_101;
}
V_3 = F_4 ( V_2 , V_86 ) ;
F_42 ( & V_2 -> V_20 , L_30 , V_3 + 'A' ) ;
V_92 = L_31 ;
V_91 = F_43 ( & V_2 -> V_20 ) ;
if ( V_91 ) {
V_6 -> V_21 = V_91 -> V_102 ;
V_6 -> V_40 = ! V_91 -> V_103 ;
if ( V_91 -> V_104 )
V_92 = V_91 -> V_104 ;
}
V_10 = F_44 ( & V_94 , V_92 , & V_2 -> V_20 ) ;
if ( V_10 != 0 ) {
F_13 ( & V_2 -> V_20 , L_32 , V_10 ) ;
goto V_101;
}
V_6 -> V_31 = V_94 -> V_105 + 2 ;
V_6 -> V_32 = F_37 ( & V_2 -> V_20 ,
V_6 -> V_31 ,
V_96 ) ;
if ( V_6 -> V_32 == NULL ) {
F_13 ( & V_2 -> V_20 , L_33 ) ;
V_10 = - V_97 ;
goto V_101;
}
V_6 -> V_32 [ 0 ] = 0x80 ;
V_6 -> V_32 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_32 + 2 , V_94 -> V_106 , V_94 -> V_105 ) ;
V_6 -> V_66 = 1 ;
V_6 -> V_68 = 1 ;
V_6 -> V_67 = 1 ;
V_6 -> V_2 = V_2 ;
F_6 ( V_6 ) ;
V_10 = F_45 ( & V_2 -> V_20 , & V_107 , NULL , 0 ) ;
if ( ! V_10 )
goto V_99;
V_101:
F_46 ( V_6 -> V_7 ) ;
V_99:
F_47 ( V_94 ) ;
return V_10 ;
}
static T_4 int F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_49 ( & V_2 -> V_20 ) ;
F_46 ( V_6 -> V_7 ) ;
return 0 ;
}
static int T_5 F_50 ( void )
{
return F_51 ( & V_108 ) ;
}
static void T_6 F_52 ( void )
{
F_53 ( & V_108 ) ;
}
