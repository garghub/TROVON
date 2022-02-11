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
unsigned long V_21 ;
int V_10 ;
F_11 ( V_6 -> V_15 != V_16 ) ;
F_12 ( & V_2 -> V_20 , L_1 ) ;
V_10 = F_13 ( V_22 , V_6 -> V_23 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_2 , V_10 ) ;
return V_10 ;
}
V_21 = F_15 ( V_6 -> V_24 ) ;
if ( V_21 <= 13500000 ) {
F_12 ( & V_2 -> V_20 , L_3 ) ;
F_1 ( V_2 , V_11 ,
V_25 ) ;
} else {
F_12 ( & V_2 -> V_20 , L_4 ) ;
F_1 ( V_2 , V_11 ,
V_26 ) ;
}
F_1 ( V_2 , V_11 , V_12 ) ;
F_1 ( V_2 , V_11 , V_27 ) ;
if ( ! F_7 ( V_2 , V_28 ,
V_29 ) ) {
F_14 ( & V_2 -> V_20 , L_5 ) ;
F_16 ( V_22 , V_6 -> V_23 ) ;
return - V_30 ;
}
if ( ! F_7 ( V_2 , V_31 ,
V_32 ) ) {
F_14 ( & V_2 -> V_20 , L_6 ) ;
F_16 ( V_22 , V_6 -> V_23 ) ;
return - V_30 ;
}
F_1 ( V_2 , V_11 , V_33 ) ;
F_12 ( & V_2 -> V_20 , L_7 ,
V_6 -> V_34 - 2 ) ;
V_10 = F_17 ( V_2 , V_6 -> V_35 ,
V_6 -> V_34 ) ;
if ( V_10 < 0 ) {
F_14 ( & V_2 -> V_20 , L_8 , V_10 ) ;
F_16 ( V_22 , V_6 -> V_23 ) ;
return V_10 ;
}
if ( V_10 != V_6 -> V_34 ) {
F_14 ( & V_2 -> V_20 , L_9 ,
V_10 , V_6 -> V_34 ) ;
F_16 ( V_22 , V_6 -> V_23 ) ;
return - V_36 ;
}
F_12 ( & V_2 -> V_20 , L_10 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_37 , 248 / 4 ) ;
F_1 ( V_2 , V_38 ,
V_39 |
V_40 |
V_41 ) ;
} else {
F_1 ( V_2 , V_38 ,
V_40 |
V_41 ) ;
}
V_10 = F_4 ( V_2 , V_42 ) ;
if ( V_6 -> V_43 )
V_10 |= V_44 ;
else
V_10 &= ~ V_44 ;
F_1 ( V_2 , V_42 , V_10 ) ;
F_1 ( V_2 , V_45 , 0x33 ) ;
F_1 ( V_2 , V_46 , 0x02 ) ;
F_1 ( V_2 , V_11 , V_47 ) ;
if ( ! F_7 ( V_2 , V_31 ,
V_48 ) ) {
F_14 ( & V_2 -> V_20 , L_11 ) ;
F_16 ( V_22 , V_6 -> V_23 ) ;
return - V_30 ;
}
F_12 ( & V_2 -> V_20 , L_12 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_13 ) ;
V_6 -> V_15 = V_49 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_50 , 248 / 4 ) ;
F_1 ( V_2 , V_38 ,
V_39 |
V_51 ) ;
} else {
F_1 ( V_2 , V_38 ,
V_51 ) ;
}
if ( ! F_7 ( V_2 , V_31 ,
V_52 ) ) {
F_14 ( & V_2 -> V_20 , L_14 ) ;
return - V_30 ;
}
if ( ! F_7 ( V_2 , V_28 ,
V_29 ) ) {
F_14 ( & V_2 -> V_20 , L_15 ) ;
return - V_30 ;
}
F_16 ( V_22 , V_6 -> V_23 ) ;
F_12 ( & V_2 -> V_20 , L_16 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_49 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_38 ,
V_39 |
V_41 |
V_53 ) ;
} else {
F_1 ( V_2 , V_38 ,
V_41 |
V_53 ) ;
}
if ( ! F_7 ( V_2 , V_31 ,
V_54 ) ) {
F_14 ( & V_2 -> V_20 , L_17 ) ;
return - V_30 ;
}
if ( ! F_7 ( V_2 , V_28 ,
V_29 ) ) {
F_14 ( & V_2 -> V_20 , L_15 ) ;
return - V_30 ;
}
F_1 ( V_2 , V_55 , V_56 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_57 ;
F_12 ( & V_2 -> V_20 , L_18 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_57 ) ;
F_1 ( V_2 , V_55 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_38 ,
V_39 |
V_40 |
V_41 ) ;
} else {
F_1 ( V_2 , V_38 ,
V_40 |
V_41 ) ;
}
F_1 ( V_2 , V_11 , V_33 ) ;
F_1 ( V_2 , V_11 , V_47 ) ;
if ( ! F_7 ( V_2 , V_31 ,
V_48 ) ) {
F_14 ( & V_2 -> V_20 , L_19 ) ;
return - V_30 ;
}
V_6 -> V_15 = V_49 ;
F_12 ( & V_2 -> V_20 , L_20 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_49 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_50 , 248 / 4 ) ;
F_1 ( V_2 , V_38 ,
V_39 |
V_41 |
V_58 ) ;
} else {
F_1 ( V_2 , V_38 ,
V_41 |
V_58 ) ;
}
if ( ! F_7 ( V_2 , V_31 ,
V_54 ) ) {
F_14 ( & V_2 -> V_20 ,
L_21 ) ;
return - V_30 ;
}
if ( ! F_7 ( V_2 , V_28 , V_29 ) ) {
F_14 ( & V_2 -> V_20 ,
L_22 ) ;
return - V_30 ;
}
F_1 ( V_2 , V_55 , V_56 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_59 ;
F_12 ( & V_2 -> V_20 , L_23 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_24 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
F_11 ( V_6 -> V_15 != V_59 ) ;
F_1 ( V_2 , V_55 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_37 , 248 / 4 ) ;
F_1 ( V_2 , V_38 ,
V_39 |
V_41 |
V_40 ) ;
} else {
F_1 ( V_2 , V_38 ,
V_41 |
V_40 ) ;
}
F_1 ( V_2 , V_11 , V_33 ) ;
F_1 ( V_2 , V_11 , V_47 ) ;
if ( ! F_7 ( V_2 , V_31 ,
V_48 ) ) {
F_14 ( & V_2 -> V_20 , L_19 ) ;
return - V_30 ;
}
V_6 -> V_15 = V_49 ;
F_12 ( & V_2 -> V_20 , L_20 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_25 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_60 V_61 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_62 , V_63 ;
int V_10 ;
if ( V_6 -> V_15 == V_61 )
return 0 ;
for ( V_62 = 0 ; V_62 < F_24 ( V_64 ) ; V_62 ++ )
if ( V_64 [ V_62 ] . V_65 == V_6 -> V_15 &&
V_64 [ V_62 ] . V_66 == V_61 )
break;
if ( V_62 == F_24 ( V_64 ) ) {
F_14 ( & V_2 -> V_20 , L_26 ,
V_6 -> V_15 , V_61 ) ;
return - V_67 ;
}
if ( V_64 [ V_62 ] . V_65 == V_16 ) {
V_10 = F_25 ( V_6 -> V_24 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_27 , V_10 ) ;
return V_10 ;
}
}
for ( V_63 = 0 ; V_63 < F_24 ( V_64 [ V_63 ] . V_68 ) ; V_63 ++ ) {
if ( ! V_64 [ V_62 ] . V_68 [ V_63 ] )
break;
V_10 = V_64 [ V_62 ] . V_68 [ V_63 ] ( V_2 ,
V_64 [ V_62 ] . V_19 ) ;
if ( V_10 != 0 )
return V_10 ;
}
if ( V_64 [ V_62 ] . V_66 == V_16 )
F_26 ( V_6 -> V_24 ) ;
return V_10 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_60 V_61 ;
if ( V_6 -> V_69 && V_6 -> V_70 )
if ( V_6 -> V_71 )
V_61 = V_49 ;
else
V_61 = V_57 ;
else
V_61 = V_59 ;
F_12 ( & V_2 -> V_20 , L_28 ,
V_61 , V_6 -> V_69 , ! V_6 -> V_70 ,
V_6 -> V_71 ) ;
return F_23 ( V_6 , V_61 ) ;
}
static int F_28 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
V_75 -> V_4 . V_78 . V_79 [ 0 ] = V_6 -> V_71 ;
return 0 ;
}
static int F_30 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
int V_71 = V_75 -> V_4 . V_78 . V_79 [ 0 ] ;
int V_10 ;
if ( V_71 > 1 )
return - V_67 ;
F_31 ( & V_6 -> V_80 ) ;
V_6 -> V_71 = V_71 ;
V_10 = F_27 ( V_6 ) ;
F_32 ( & V_6 -> V_80 ) ;
return V_10 ;
}
static int F_33 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
V_75 -> V_4 . V_78 . V_79 [ 0 ] = V_6 -> V_70 ;
return 0 ;
}
static int F_34 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
int V_9 = V_75 -> V_4 . V_78 . V_79 [ 0 ] ;
int V_10 ;
if ( V_9 > 1 )
return - V_67 ;
F_31 ( & V_6 -> V_80 ) ;
V_6 -> V_70 = V_9 ;
V_10 = F_27 ( V_6 ) ;
F_32 ( & V_6 -> V_80 ) ;
return V_10 ;
}
static int F_35 ( struct V_81 * V_82 ,
struct V_72 * V_73 , int V_83 )
{
struct V_76 * V_77 = V_82 -> V_77 ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
int V_10 ;
F_31 ( & V_6 -> V_80 ) ;
if ( F_36 ( V_83 ) )
V_6 -> V_69 = 1 ;
if ( F_37 ( V_83 ) )
V_6 -> V_69 = 0 ;
V_10 = F_27 ( V_6 ) ;
F_32 ( & V_6 -> V_80 ) ;
return V_10 ;
}
static int F_38 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
return F_23 ( V_6 , V_16 ) ;
}
static int F_39 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
return F_27 ( V_6 ) ;
}
static bool F_40 ( struct V_84 * V_20 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_42 :
case V_89 :
case V_50 :
case V_37 :
case V_90 :
case V_91 :
case V_31 :
case V_38 :
case V_45 :
case V_46 :
case V_14 :
case V_92 :
case V_93 :
case V_55 :
case V_11 :
case V_28 :
case V_94 :
return true ;
default:
return false ;
}
}
static int F_41 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
F_42 ( V_77 , 16 , 8 , V_95 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
static int F_43 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
return F_23 ( V_6 , V_16 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_96 * V_97 )
{
struct V_5 * V_6 ;
struct V_98 * V_99 ;
const char * V_100 ;
const struct V_101 * V_102 = NULL ;
int V_10 , V_62 ;
int V_3 ;
T_2 V_103 ;
V_6 = F_45 ( & V_2 -> V_20 , sizeof( struct V_5 ) ,
V_104 ) ;
if ( V_6 == NULL ) {
F_14 ( & V_2 -> V_20 , L_29 ) ;
return - V_105 ;
}
F_46 ( & V_6 -> V_80 ) ;
F_47 ( & V_2 -> V_20 , V_6 ) ;
V_6 -> V_7 = F_48 ( V_2 , & V_106 ) ;
if ( F_49 ( V_6 -> V_7 ) ) {
V_10 = F_50 ( V_6 -> V_7 ) ;
F_14 ( & V_2 -> V_20 , L_30 ,
V_10 ) ;
goto V_107;
}
for ( V_62 = 0 ; V_62 < V_22 ; V_62 ++ )
V_6 -> V_23 [ V_62 ] . V_108 = V_109 [ V_62 ] ;
V_10 = F_51 ( & V_2 -> V_20 , V_22 ,
V_6 -> V_23 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_31 , V_10 ) ;
return V_10 ;
}
V_10 = F_13 ( V_22 , V_6 -> V_23 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_2 , V_10 ) ;
return V_10 ;
}
V_3 = F_4 ( V_2 , V_14 ) ;
V_103 = V_3 << 8 ;
V_3 = F_4 ( V_2 , V_92 ) ;
V_103 |= V_3 & 0xff ;
if ( V_103 != 0x2000 ) {
F_14 ( & V_2 -> V_20 , L_32 , V_103 ) ;
V_10 = - V_110 ;
goto V_111;
}
V_3 = F_4 ( V_2 , V_93 ) ;
F_52 ( & V_2 -> V_20 , L_33 , V_3 + 'A' ) ;
V_6 -> V_24 = F_53 ( & V_2 -> V_20 , L_34 ) ;
if ( F_49 ( V_6 -> V_24 ) ) {
V_10 = F_50 ( V_6 -> V_24 ) ;
F_14 ( & V_2 -> V_20 , L_35 , V_10 ) ;
goto V_111;
}
V_100 = L_36 ;
V_99 = F_54 ( & V_2 -> V_20 ) ;
if ( V_99 ) {
V_6 -> V_43 = ! V_99 -> V_112 ;
if ( V_99 -> V_113 )
V_100 = V_99 -> V_113 ;
}
V_10 = F_55 ( & V_102 , V_100 , & V_2 -> V_20 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_37 , V_10 ) ;
goto V_111;
}
V_6 -> V_34 = V_102 -> V_114 + 2 ;
V_6 -> V_35 = F_45 ( & V_2 -> V_20 ,
V_6 -> V_34 ,
V_104 ) ;
if ( V_6 -> V_35 == NULL ) {
F_14 ( & V_2 -> V_20 , L_38 ) ;
V_10 = - V_105 ;
goto V_111;
}
V_6 -> V_35 [ 0 ] = 0x80 ;
V_6 -> V_35 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_35 + 2 , V_102 -> V_115 , V_102 -> V_114 ) ;
V_6 -> V_69 = 1 ;
V_6 -> V_71 = 1 ;
V_6 -> V_70 = 1 ;
V_6 -> V_2 = V_2 ;
F_6 ( V_6 ) ;
V_10 = F_56 ( & V_2 -> V_20 , & V_116 , NULL , 0 ) ;
V_111:
F_16 ( V_22 , V_6 -> V_23 ) ;
V_107:
F_57 ( V_102 ) ;
return V_10 ;
}
static int F_58 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_20 ) ;
return 0 ;
}
