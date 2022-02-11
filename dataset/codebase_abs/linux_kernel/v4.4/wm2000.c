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
if ( F_11 ( V_6 -> V_15 != V_16 ) )
return - V_22 ;
F_12 ( & V_2 -> V_20 , L_1 ) ;
V_10 = F_13 ( V_23 , V_6 -> V_24 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_2 , V_10 ) ;
return V_10 ;
}
V_21 = F_15 ( V_6 -> V_25 ) ;
if ( V_21 <= 13500000 ) {
F_12 ( & V_2 -> V_20 , L_3 ) ;
F_1 ( V_2 , V_11 ,
V_26 ) ;
} else {
F_12 ( & V_2 -> V_20 , L_4 ) ;
F_1 ( V_2 , V_11 ,
V_27 ) ;
}
F_1 ( V_2 , V_11 , V_12 ) ;
F_1 ( V_2 , V_11 , V_28 ) ;
if ( ! F_7 ( V_2 , V_29 ,
V_30 ) ) {
F_14 ( & V_2 -> V_20 , L_5 ) ;
F_16 ( V_23 , V_6 -> V_24 ) ;
return - V_31 ;
}
if ( ! F_7 ( V_2 , V_32 ,
V_33 ) ) {
F_14 ( & V_2 -> V_20 , L_6 ) ;
F_16 ( V_23 , V_6 -> V_24 ) ;
return - V_31 ;
}
F_1 ( V_2 , V_11 , V_34 ) ;
F_12 ( & V_2 -> V_20 , L_7 ,
V_6 -> V_35 - 2 ) ;
V_10 = F_17 ( V_2 , V_6 -> V_36 ,
V_6 -> V_35 ) ;
if ( V_10 < 0 ) {
F_14 ( & V_2 -> V_20 , L_8 , V_10 ) ;
F_16 ( V_23 , V_6 -> V_24 ) ;
return V_10 ;
}
if ( V_10 != V_6 -> V_35 ) {
F_14 ( & V_2 -> V_20 , L_9 ,
V_10 , V_6 -> V_35 ) ;
F_16 ( V_23 , V_6 -> V_24 ) ;
return - V_37 ;
}
F_12 ( & V_2 -> V_20 , L_10 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_38 , 248 / 4 ) ;
F_1 ( V_2 , V_39 ,
V_40 |
V_41 |
V_42 ) ;
} else {
F_1 ( V_2 , V_39 ,
V_41 |
V_42 ) ;
}
V_10 = F_4 ( V_2 , V_43 ) ;
if ( V_6 -> V_44 )
V_10 |= V_45 ;
else
V_10 &= ~ V_45 ;
F_1 ( V_2 , V_43 , V_10 ) ;
F_1 ( V_2 , V_46 , 0x33 ) ;
F_1 ( V_2 , V_47 , 0x02 ) ;
F_1 ( V_2 , V_11 , V_48 ) ;
if ( ! F_7 ( V_2 , V_32 ,
V_49 ) ) {
F_14 ( & V_2 -> V_20 , L_11 ) ;
F_16 ( V_23 , V_6 -> V_24 ) ;
return - V_31 ;
}
F_12 ( & V_2 -> V_20 , L_12 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_13 ) ;
V_6 -> V_15 = V_50 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_51 , 248 / 4 ) ;
F_1 ( V_2 , V_39 ,
V_40 |
V_52 ) ;
} else {
F_1 ( V_2 , V_39 ,
V_52 ) ;
}
if ( ! F_7 ( V_2 , V_32 ,
V_53 ) ) {
F_14 ( & V_2 -> V_20 , L_14 ) ;
return - V_31 ;
}
if ( ! F_7 ( V_2 , V_29 ,
V_30 ) ) {
F_14 ( & V_2 -> V_20 , L_15 ) ;
return - V_31 ;
}
F_16 ( V_23 , V_6 -> V_24 ) ;
F_12 ( & V_2 -> V_20 , L_16 ) ;
V_6 -> V_15 = V_16 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( F_11 ( V_6 -> V_15 != V_50 ) )
return - V_22 ;
if ( V_19 ) {
F_1 ( V_2 , V_39 ,
V_40 |
V_42 |
V_54 ) ;
} else {
F_1 ( V_2 , V_39 ,
V_42 |
V_54 ) ;
}
if ( ! F_7 ( V_2 , V_32 ,
V_55 ) ) {
F_14 ( & V_2 -> V_20 , L_17 ) ;
return - V_31 ;
}
if ( ! F_7 ( V_2 , V_29 ,
V_30 ) ) {
F_14 ( & V_2 -> V_20 , L_15 ) ;
return - V_31 ;
}
F_1 ( V_2 , V_56 , V_57 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_58 ;
F_12 ( & V_2 -> V_20 , L_18 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( F_11 ( V_6 -> V_15 != V_58 ) )
return - V_22 ;
F_1 ( V_2 , V_56 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_39 ,
V_40 |
V_41 |
V_42 ) ;
} else {
F_1 ( V_2 , V_39 ,
V_41 |
V_42 ) ;
}
F_1 ( V_2 , V_11 , V_34 ) ;
F_1 ( V_2 , V_11 , V_48 ) ;
if ( ! F_7 ( V_2 , V_32 ,
V_49 ) ) {
F_14 ( & V_2 -> V_20 , L_19 ) ;
return - V_31 ;
}
V_6 -> V_15 = V_50 ;
F_12 ( & V_2 -> V_20 , L_20 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( F_11 ( V_6 -> V_15 != V_50 ) )
return - V_22 ;
if ( V_19 ) {
F_1 ( V_2 , V_51 , 248 / 4 ) ;
F_1 ( V_2 , V_39 ,
V_40 |
V_42 |
V_59 ) ;
} else {
F_1 ( V_2 , V_39 ,
V_42 |
V_59 ) ;
}
if ( ! F_7 ( V_2 , V_32 ,
V_55 ) ) {
F_14 ( & V_2 -> V_20 ,
L_21 ) ;
return - V_31 ;
}
if ( ! F_7 ( V_2 , V_29 , V_30 ) ) {
F_14 ( & V_2 -> V_20 ,
L_22 ) ;
return - V_31 ;
}
F_1 ( V_2 , V_56 , V_57 ) ;
F_1 ( V_2 , V_11 , V_13 ) ;
V_6 -> V_15 = V_60 ;
F_12 ( & V_2 -> V_20 , L_23 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_24 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = F_10 ( & V_2 -> V_20 ) ;
if ( F_11 ( V_6 -> V_15 != V_60 ) )
return - V_22 ;
F_1 ( V_2 , V_56 , 0 ) ;
if ( V_19 ) {
F_1 ( V_2 , V_38 , 248 / 4 ) ;
F_1 ( V_2 , V_39 ,
V_40 |
V_42 |
V_41 ) ;
} else {
F_1 ( V_2 , V_39 ,
V_42 |
V_41 ) ;
}
F_1 ( V_2 , V_11 , V_34 ) ;
F_1 ( V_2 , V_11 , V_48 ) ;
if ( ! F_7 ( V_2 , V_32 ,
V_49 ) ) {
F_14 ( & V_2 -> V_20 , L_19 ) ;
return - V_31 ;
}
V_6 -> V_15 = V_50 ;
F_12 ( & V_2 -> V_20 , L_20 ) ;
if ( V_19 )
F_12 ( & V_2 -> V_20 , L_25 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_61 V_62 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_63 , V_64 ;
int V_10 ;
if ( V_6 -> V_15 == V_62 )
return 0 ;
for ( V_63 = 0 ; V_63 < F_24 ( V_65 ) ; V_63 ++ )
if ( V_65 [ V_63 ] . V_66 == V_6 -> V_15 &&
V_65 [ V_63 ] . V_67 == V_62 )
break;
if ( V_63 == F_24 ( V_65 ) ) {
F_14 ( & V_2 -> V_20 , L_26 ,
V_6 -> V_15 , V_62 ) ;
return - V_22 ;
}
if ( V_65 [ V_63 ] . V_66 == V_16 ) {
V_10 = F_25 ( V_6 -> V_25 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_27 , V_10 ) ;
return V_10 ;
}
}
for ( V_64 = 0 ; V_64 < F_24 ( V_65 [ V_64 ] . V_68 ) ; V_64 ++ ) {
if ( ! V_65 [ V_63 ] . V_68 [ V_64 ] )
break;
V_10 = V_65 [ V_63 ] . V_68 [ V_64 ] ( V_2 ,
V_65 [ V_63 ] . V_19 ) ;
if ( V_10 != 0 )
return V_10 ;
}
if ( V_65 [ V_63 ] . V_67 == V_16 )
F_26 ( V_6 -> V_25 ) ;
return V_10 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_61 V_62 ;
if ( V_6 -> V_69 && V_6 -> V_70 )
if ( V_6 -> V_71 )
V_62 = V_50 ;
else
V_62 = V_58 ;
else
V_62 = V_60 ;
F_12 ( & V_2 -> V_20 , L_28 ,
V_62 , V_6 -> V_69 , ! V_6 -> V_70 ,
V_6 -> V_71 ) ;
return F_23 ( V_6 , V_62 ) ;
}
static int F_28 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
V_75 -> V_4 . integer . V_4 [ 0 ] = V_6 -> V_71 ;
return 0 ;
}
static int F_30 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
unsigned int V_71 = V_75 -> V_4 . integer . V_4 [ 0 ] ;
int V_10 ;
if ( V_71 > 1 )
return - V_22 ;
F_31 ( & V_6 -> V_78 ) ;
V_6 -> V_71 = V_71 ;
V_10 = F_27 ( V_6 ) ;
F_32 ( & V_6 -> V_78 ) ;
return V_10 ;
}
static int F_33 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
V_75 -> V_4 . integer . V_4 [ 0 ] = V_6 -> V_70 ;
return 0 ;
}
static int F_34 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = F_29 ( V_73 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
unsigned int V_9 = V_75 -> V_4 . integer . V_4 [ 0 ] ;
int V_10 ;
if ( V_9 > 1 )
return - V_22 ;
F_31 ( & V_6 -> V_78 ) ;
V_6 -> V_70 = V_9 ;
V_10 = F_27 ( V_6 ) ;
F_32 ( & V_6 -> V_78 ) ;
return V_10 ;
}
static int F_35 ( struct V_79 * V_80 ,
struct V_72 * V_73 , int V_81 )
{
struct V_76 * V_77 = F_36 ( V_80 -> V_82 ) ;
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
int V_10 ;
F_31 ( & V_6 -> V_78 ) ;
if ( F_37 ( V_81 ) )
V_6 -> V_69 = 1 ;
if ( F_38 ( V_81 ) )
V_6 -> V_69 = 0 ;
V_10 = F_27 ( V_6 ) ;
F_32 ( & V_6 -> V_78 ) ;
return V_10 ;
}
static int F_39 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
return F_23 ( V_6 , V_16 ) ;
}
static int F_40 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
return F_27 ( V_6 ) ;
}
static bool F_41 ( struct V_83 * V_20 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_43 :
case V_88 :
case V_51 :
case V_38 :
case V_89 :
case V_90 :
case V_32 :
case V_39 :
case V_46 :
case V_47 :
case V_14 :
case V_91 :
case V_92 :
case V_56 :
case V_11 :
case V_29 :
case V_93 :
case V_94 :
case V_95 :
return true ;
default:
return false ;
}
}
static int F_42 ( struct V_76 * V_77 )
{
struct V_5 * V_6 = F_10 ( V_77 -> V_20 ) ;
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
int V_10 , V_63 ;
int V_3 ;
T_2 V_103 ;
V_6 = F_45 ( & V_2 -> V_20 , sizeof( struct V_5 ) ,
V_104 ) ;
if ( ! V_6 )
return - V_105 ;
F_46 ( & V_6 -> V_78 ) ;
F_47 ( & V_2 -> V_20 , V_6 ) ;
V_6 -> V_7 = F_48 ( V_2 , & V_106 ) ;
if ( F_49 ( V_6 -> V_7 ) ) {
V_10 = F_50 ( V_6 -> V_7 ) ;
F_14 ( & V_2 -> V_20 , L_29 ,
V_10 ) ;
goto V_107;
}
for ( V_63 = 0 ; V_63 < V_23 ; V_63 ++ )
V_6 -> V_24 [ V_63 ] . V_108 = V_109 [ V_63 ] ;
V_10 = F_51 ( & V_2 -> V_20 , V_23 ,
V_6 -> V_24 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_30 , V_10 ) ;
return V_10 ;
}
V_10 = F_13 ( V_23 , V_6 -> V_24 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_2 , V_10 ) ;
return V_10 ;
}
V_3 = F_4 ( V_2 , V_14 ) ;
V_103 = V_3 << 8 ;
V_3 = F_4 ( V_2 , V_91 ) ;
V_103 |= V_3 & 0xff ;
if ( V_103 != 0x2000 ) {
F_14 ( & V_2 -> V_20 , L_31 , V_103 ) ;
V_10 = - V_110 ;
goto V_111;
}
V_3 = F_4 ( V_2 , V_92 ) ;
F_52 ( & V_2 -> V_20 , L_32 , V_3 + 'A' ) ;
V_6 -> V_25 = F_53 ( & V_2 -> V_20 , L_33 ) ;
if ( F_49 ( V_6 -> V_25 ) ) {
V_10 = F_50 ( V_6 -> V_25 ) ;
F_14 ( & V_2 -> V_20 , L_34 , V_10 ) ;
goto V_111;
}
V_100 = L_35 ;
V_99 = F_54 ( & V_2 -> V_20 ) ;
if ( V_99 ) {
V_6 -> V_44 = ! V_99 -> V_112 ;
if ( V_99 -> V_113 )
V_100 = V_99 -> V_113 ;
}
V_10 = F_55 ( & V_102 , V_100 , & V_2 -> V_20 ) ;
if ( V_10 != 0 ) {
F_14 ( & V_2 -> V_20 , L_36 , V_10 ) ;
goto V_111;
}
V_6 -> V_35 = V_102 -> V_114 + 2 ;
V_6 -> V_36 = F_45 ( & V_2 -> V_20 ,
V_6 -> V_35 ,
V_104 ) ;
if ( V_6 -> V_36 == NULL ) {
F_14 ( & V_2 -> V_20 , L_37 ) ;
V_10 = - V_105 ;
goto V_111;
}
V_6 -> V_36 [ 0 ] = 0x80 ;
V_6 -> V_36 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_36 + 2 , V_102 -> V_115 , V_102 -> V_114 ) ;
V_6 -> V_69 = 1 ;
V_6 -> V_71 = 1 ;
V_6 -> V_70 = 1 ;
V_6 -> V_2 = V_2 ;
F_6 ( V_6 ) ;
V_10 = F_56 ( & V_2 -> V_20 , & V_116 , NULL , 0 ) ;
V_111:
F_16 ( V_23 , V_6 -> V_24 ) ;
V_107:
F_57 ( V_102 ) ;
return V_10 ;
}
static int F_58 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_20 ) ;
return 0 ;
}
