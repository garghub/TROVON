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
V_10 = F_13 ( V_21 , V_6 -> V_22 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_2 , V_10 ) ;
return V_10 ;
}
if ( ! V_6 -> V_23 ) {
F_12 ( & V_2 -> V_20 , L_3 ) ;
F_1 ( V_2 , V_11 ,
V_24 ) ;
} else {
F_12 ( & V_2 -> V_20 , L_4 ) ;
F_1 ( V_2 , V_11 ,
V_25 ) ;
}
F_1 ( V_2 , V_11 , V_12 ) ;
F_1 ( V_2 , V_11 , V_26 ) ;
if ( ! F_7 ( V_2 , V_27 ,
V_28 ) ) {
F_14 ( & V_2 -> V_20 , L_5 ) ;
F_15 ( V_21 , V_6 -> V_22 ) ;
return - V_29 ;
}
if ( ! F_7 ( V_2 , V_30 ,
V_31 ) ) {
F_14 ( & V_2 -> V_20 , L_6 ) ;
F_15 ( V_21 , V_6 -> V_22 ) ;
return - V_29 ;
}
F_1 ( V_2 , V_11 , V_32 ) ;
F_12 ( & V_2 -> V_20 , L_7 ,
V_6 -> V_33 - 2 ) ;
V_10 = F_16 ( V_2 , V_6 -> V_34 ,
V_6 -> V_33 ) ;
if ( V_10 < 0 ) {
F_14 ( & V_2 -> V_20 , L_8 , V_10 ) ;
F_15 ( V_21 , V_6 -> V_22 ) ;
return V_10 ;
}
if ( V_10 != V_6 -> V_33 ) {
F_14 ( & V_2 -> V_20 , L_9 ,
V_10 , V_6 -> V_33 ) ;
F_15 ( V_21 , V_6 -> V_22 ) ;
return - V_35 ;
}
F_12 ( & V_2 -> V_20 , L_10 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_36 , 248 / 4 ) ;
F_1 ( V_2 , V_37 ,
V_38 |
V_39 |
V_40 ) ;
} else {
F_1 ( V_2 , V_37 ,
V_39 |
V_40 ) ;
}
V_10 = F_4 ( V_2 , V_41 ) ;
if ( V_6 -> V_42 )
V_10 &= ~ V_43 ;
else
V_10 |= V_43 ;
F_1 ( V_2 , V_41 , V_10 ) ;
F_1 ( V_2 , V_44 , 0x33 ) ;
F_1 ( V_2 , V_45 , 0x02 ) ;
F_1 ( V_2 , V_11 , V_46 ) ;
if ( ! F_7 ( V_2 , V_30 ,
V_47 ) ) {
F_14 ( & V_2 -> V_20 , L_11 ) ;
F_15 ( V_21 , V_6 -> V_22 ) ;
return - V_29 ;
}
F_12 ( & V_2 -> V_20 , L_12 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_13 ) ;
V_6 -> V_15 = V_48 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_49 , 248 / 4 ) ;
F_1 ( V_2 , V_37 ,
V_38 |
V_50 ) ;
} else {
F_1 ( V_2 , V_37 ,
V_50 ) ;
}
if ( ! F_7 ( V_2 , V_30 ,
V_51 ) ) {
F_14 ( & V_2 -> V_20 , L_14 ) ;
return - V_29 ;
}
if ( ! F_7 ( V_2 , V_27 ,
V_28 ) ) {
F_14 ( & V_2 -> V_20 , L_15 ) ;
return - V_29 ;
}
F_15 ( V_21 , V_6 -> V_22 ) ;
F_12 ( & V_2 -> V_20 , L_16 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_48 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_37 ,
V_38 |
V_40 |
V_52 ) ;
} else {
F_1 ( V_2 , V_37 ,
V_40 |
V_52 ) ;
}
if ( ! F_7 ( V_2 , V_30 ,
V_53 ) ) {
F_14 ( & V_2 -> V_20 , L_17 ) ;
return - V_29 ;
}
if ( ! F_7 ( V_2 , V_27 ,
V_28 ) ) {
F_14 ( & V_2 -> V_20 , L_15 ) ;
return - V_29 ;
}
F_1 ( V_2 , V_54 , V_55 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_56 ;
F_12 ( & V_2 -> V_20 , L_18 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_56 ) ;
F_1 ( V_2 , V_54 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_37 ,
V_38 |
V_39 |
V_40 ) ;
} else {
F_1 ( V_2 , V_37 ,
V_39 |
V_40 ) ;
}
F_1 ( V_2 , V_11 , V_32 ) ;
F_1 ( V_2 , V_11 , V_46 ) ;
if ( ! F_7 ( V_2 , V_30 ,
V_47 ) ) {
F_14 ( & V_2 -> V_20 , L_19 ) ;
return - V_29 ;
}
V_6 -> V_15 = V_48 ;
F_12 ( & V_2 -> V_20 , L_20 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_48 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_49 , 248 / 4 ) ;
F_1 ( V_2 , V_37 ,
V_38 |
V_40 |
V_57 ) ;
} else {
F_1 ( V_2 , V_37 ,
V_40 |
V_57 ) ;
}
if ( ! F_7 ( V_2 , V_30 ,
V_53 ) ) {
F_14 ( & V_2 -> V_20 ,
L_21 ) ;
return - V_29 ;
}
if ( ! F_7 ( V_2 , V_27 , V_28 ) ) {
F_14 ( & V_2 -> V_20 ,
L_22 ) ;
return - V_29 ;
}
F_1 ( V_2 , V_54 , V_55 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_58 ;
F_12 ( & V_2 -> V_20 , L_23 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_24 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_58 ) ;
F_1 ( V_2 , V_54 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_36 , 248 / 4 ) ;
F_1 ( V_2 , V_37 ,
V_38 |
V_40 |
V_39 ) ;
} else {
F_1 ( V_2 , V_37 ,
V_40 |
V_39 ) ;
}
F_1 ( V_2 , V_11 , V_32 ) ;
F_1 ( V_2 , V_11 , V_46 ) ;
if ( ! F_7 ( V_2 , V_30 ,
V_47 ) ) {
F_14 ( & V_2 -> V_20 , L_19 ) ;
return - V_29 ;
}
V_6 -> V_15 = V_48 ;
F_12 ( & V_2 -> V_20 , L_20 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_25 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
enum V_59 V_60 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_61 , V_62 ;
int V_10 ;
if ( V_6 -> V_15 == V_60 )
return 0 ;
for ( V_61 = 0 ; V_61 < F_23 ( V_63 ) ; V_61 ++ )
if ( V_63 [ V_61 ] . V_64 == V_6 -> V_15 &&
V_63 [ V_61 ] . V_65 == V_60 )
break;
if ( V_61 == F_23 ( V_63 ) ) {
F_14 ( & V_2 -> V_20 , L_26 ,
V_6 -> V_15 , V_60 ) ;
return - V_66 ;
}
for ( V_62 = 0 ; V_62 < F_23 ( V_63 [ V_62 ] . V_67 ) ; V_62 ++ ) {
if ( ! V_63 [ V_61 ] . V_67 [ V_62 ] )
break;
V_10 = V_63 [ V_61 ] . V_67 [ V_62 ] ( V_2 ,
V_63 [ V_61 ] . V_19 ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_59 V_60 ;
if ( V_6 -> V_68 && V_6 -> V_69 )
if ( V_6 -> V_70 )
V_60 = V_48 ;
else
V_60 = V_56 ;
else
V_60 = V_58 ;
F_12 ( & V_2 -> V_20 , L_27 ,
V_60 , V_6 -> V_68 , ! V_6 -> V_69 ,
V_6 -> V_70 ) ;
return F_22 ( V_6 , V_60 ) ;
}
static int F_25 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_75 * V_76 = F_26 ( V_72 ) ;
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
V_74 -> V_4 . V_77 . V_78 [ 0 ] = V_6 -> V_70 ;
return 0 ;
}
static int F_27 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_75 * V_76 = F_26 ( V_72 ) ;
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
int V_70 = V_74 -> V_4 . V_77 . V_78 [ 0 ] ;
if ( V_70 > 1 )
return - V_66 ;
V_6 -> V_70 = V_70 ;
return F_24 ( V_6 ) ;
}
static int F_28 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_75 * V_76 = F_26 ( V_72 ) ;
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
V_74 -> V_4 . V_77 . V_78 [ 0 ] = V_6 -> V_69 ;
return 0 ;
}
static int F_29 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_75 * V_76 = F_26 ( V_72 ) ;
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
int V_9 = V_74 -> V_4 . V_77 . V_78 [ 0 ] ;
if ( V_9 > 1 )
return - V_66 ;
V_6 -> V_69 = V_9 ;
return F_24 ( V_6 ) ;
}
static int F_30 ( struct V_79 * V_80 ,
struct V_71 * V_72 , int V_81 )
{
struct V_75 * V_76 = F_26 ( V_72 ) ;
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
if ( F_31 ( V_81 ) )
V_6 -> V_68 = 1 ;
if ( F_32 ( V_81 ) )
V_6 -> V_68 = 0 ;
return F_24 ( V_6 ) ;
}
static int F_33 ( struct V_75 * V_76 )
{
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
return F_22 ( V_6 , V_16 ) ;
}
static int F_34 ( struct V_75 * V_76 )
{
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
return F_24 ( V_6 ) ;
}
static bool F_35 ( struct V_82 * V_20 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_83 :
case V_41 :
case V_84 :
case V_49 :
case V_36 :
case V_85 :
case V_86 :
case V_30 :
case V_37 :
case V_44 :
case V_45 :
case V_14 :
case V_87 :
case V_88 :
case V_54 :
case V_11 :
case V_27 :
case V_89 :
return true ;
default:
return false ;
}
}
static int F_36 ( struct V_75 * V_76 )
{
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
static int F_37 ( struct V_75 * V_76 )
{
struct V_5 * V_6 = F_10 ( V_76 -> V_20 ) ;
return F_22 ( V_6 , V_16 ) ;
}
static int T_2 F_38 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
struct V_5 * V_6 ;
struct V_92 * V_93 ;
const char * V_94 ;
const struct V_95 * V_96 = NULL ;
int V_10 , V_61 ;
int V_3 ;
T_3 V_97 ;
V_6 = F_39 ( & V_2 -> V_20 , sizeof( struct V_5 ) ,
V_98 ) ;
if ( V_6 == NULL ) {
F_14 ( & V_2 -> V_20 , L_28 ) ;
return - V_99 ;
}
F_40 ( & V_2 -> V_20 , V_6 ) ;
V_6 -> V_7 = F_41 ( V_2 , & V_100 ) ;
if ( F_42 ( V_6 -> V_7 ) ) {
V_10 = F_43 ( V_6 -> V_7 ) ;
F_14 ( & V_2 -> V_20 , L_29 ,
V_10 ) ;
goto V_101;
}
for ( V_61 = 0 ; V_61 < V_21 ; V_61 ++ )
V_6 -> V_22 [ V_61 ] . V_102 = V_103 [ V_61 ] ;
V_10 = F_44 ( & V_2 -> V_20 , V_21 ,
V_6 -> V_22 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_30 , V_10 ) ;
return V_10 ;
}
V_10 = F_13 ( V_21 , V_6 -> V_22 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_2 , V_10 ) ;
return V_10 ;
}
V_3 = F_4 ( V_2 , V_14 ) ;
V_97 = V_3 << 8 ;
V_3 = F_4 ( V_2 , V_87 ) ;
V_97 |= V_3 & 0xff ;
if ( V_97 != 0x2000 ) {
F_14 ( & V_2 -> V_20 , L_31 , V_97 ) ;
V_10 = - V_104 ;
goto V_105;
}
V_3 = F_4 ( V_2 , V_88 ) ;
F_45 ( & V_2 -> V_20 , L_32 , V_3 + 'A' ) ;
V_94 = L_33 ;
V_93 = F_46 ( & V_2 -> V_20 ) ;
if ( V_93 ) {
V_6 -> V_23 = V_93 -> V_106 ;
V_6 -> V_42 = ! V_93 -> V_107 ;
if ( V_93 -> V_108 )
V_94 = V_93 -> V_108 ;
}
V_10 = F_47 ( & V_96 , V_94 , & V_2 -> V_20 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_34 , V_10 ) ;
goto V_105;
}
V_6 -> V_33 = V_96 -> V_109 + 2 ;
V_6 -> V_34 = F_39 ( & V_2 -> V_20 ,
V_6 -> V_33 ,
V_98 ) ;
if ( V_6 -> V_34 == NULL ) {
F_14 ( & V_2 -> V_20 , L_35 ) ;
V_10 = - V_99 ;
goto V_105;
}
V_6 -> V_34 [ 0 ] = 0x80 ;
V_6 -> V_34 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_34 + 2 , V_96 -> V_110 , V_96 -> V_109 ) ;
V_6 -> V_68 = 1 ;
V_6 -> V_70 = 1 ;
V_6 -> V_69 = 1 ;
V_6 -> V_2 = V_2 ;
F_6 ( V_6 ) ;
V_10 = F_48 ( & V_2 -> V_20 , & V_111 , NULL , 0 ) ;
V_105:
F_15 ( V_21 , V_6 -> V_22 ) ;
V_101:
F_49 ( V_96 ) ;
return V_10 ;
}
static T_4 int F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_20 ) ;
return 0 ;
}
