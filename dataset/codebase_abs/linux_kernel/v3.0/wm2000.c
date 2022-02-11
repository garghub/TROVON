static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
T_1 V_5 [ 3 ] ;
int V_6 ;
V_5 [ 0 ] = ( V_3 >> 8 ) & 0xff ;
V_5 [ 1 ] = V_3 & 0xff ;
V_5 [ 2 ] = V_4 & 0xff ;
F_2 ( & V_2 -> V_7 , L_1 , V_3 , V_4 ) ;
V_6 = F_3 ( V_2 , V_5 , 3 ) ;
if ( V_6 == 3 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_8 ;
}
static unsigned int F_4 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_10 V_11 [ 2 ] ;
T_1 V_3 [ 2 ] ;
T_1 V_5 ;
int V_6 ;
V_3 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_9 & 0xff ;
V_11 [ 0 ] . V_12 = V_2 -> V_12 ;
V_11 [ 0 ] . V_13 = 0 ;
V_11 [ 0 ] . V_14 = sizeof( V_3 ) ;
V_11 [ 0 ] . V_15 = & V_3 [ 0 ] ;
V_11 [ 1 ] . V_12 = V_2 -> V_12 ;
V_11 [ 1 ] . V_13 = V_16 ;
V_11 [ 1 ] . V_14 = 1 ;
V_11 [ 1 ] . V_15 = & V_5 ;
V_6 = F_5 ( V_2 -> V_17 , V_11 , 2 ) ;
if ( V_6 != 2 ) {
F_6 ( & V_2 -> V_7 , L_2 , V_6 ) ;
return 0 ;
}
F_2 ( & V_2 -> V_7 , L_3 , V_5 , V_9 ) ;
return V_5 ;
}
static void F_7 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_1 ( V_2 , V_20 , V_21 ) ;
F_1 ( V_2 , V_20 , V_22 ) ;
F_1 ( V_2 , V_23 , 0 ) ;
V_19 -> V_24 = V_25 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_26 , int V_27 )
{
int V_28 ;
V_28 = F_4 ( V_2 , V_3 ) ;
while ( ! ( V_28 & V_26 ) && -- V_27 ) {
F_9 ( 1 ) ;
V_28 = F_4 ( V_2 , V_3 ) ;
}
if ( V_27 == 0 )
return 0 ;
else
return 1 ;
}
static int F_10 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
int V_6 , V_27 ;
F_12 ( V_19 -> V_24 != V_25 ) ;
F_13 ( & V_2 -> V_7 , L_4 ) ;
if ( ! V_19 -> V_30 ) {
F_13 ( & V_2 -> V_7 , L_5 ) ;
F_1 ( V_2 , V_20 ,
V_31 ) ;
} else {
F_13 ( & V_2 -> V_7 , L_6 ) ;
F_1 ( V_2 , V_20 ,
V_32 ) ;
}
F_1 ( V_2 , V_20 , V_21 ) ;
F_1 ( V_2 , V_20 , V_33 ) ;
if ( ! F_8 ( V_2 , V_34 ,
V_35 , 1 ) ) {
F_6 ( & V_2 -> V_7 , L_7 ) ;
return - V_36 ;
}
if ( ! F_8 ( V_2 , V_37 ,
V_38 , 1 ) ) {
F_6 ( & V_2 -> V_7 , L_8 ) ;
return - V_36 ;
}
F_1 ( V_2 , V_20 , V_39 ) ;
F_13 ( & V_2 -> V_7 , L_9 ,
V_19 -> V_40 - 2 ) ;
V_6 = F_3 ( V_2 , V_19 -> V_41 ,
V_19 -> V_40 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_7 , L_10 , V_6 ) ;
return V_6 ;
}
if ( V_6 != V_19 -> V_40 ) {
F_6 ( & V_2 -> V_7 , L_11 ,
V_6 , V_19 -> V_40 ) ;
return - V_8 ;
}
F_13 ( & V_2 -> V_7 , L_12 ) ;
if ( V_29 ) {
V_27 = 248 ;
F_1 ( V_2 , V_42 , V_27 / 4 ) ;
F_1 ( V_2 , V_43 ,
V_44 |
V_45 |
V_46 ) ;
} else {
V_27 = 10 ;
F_1 ( V_2 , V_43 ,
V_45 |
V_46 ) ;
}
V_6 = F_4 ( V_2 , V_47 ) ;
if ( V_19 -> V_48 )
V_6 &= ~ V_49 ;
else
V_6 |= V_49 ;
F_1 ( V_2 , V_47 , V_6 ) ;
F_1 ( V_2 , V_50 , 0x33 ) ;
F_1 ( V_2 , V_51 , 0x02 ) ;
F_1 ( V_2 , V_20 , V_52 ) ;
if ( ! F_8 ( V_2 , V_37 ,
V_53 , V_27 ) ) {
F_6 ( & V_2 -> V_7 , L_13 ,
V_27 * 10 ) ;
return - V_36 ;
}
F_13 ( & V_2 -> V_7 , L_14 ) ;
if ( V_29 )
F_13 ( & V_2 -> V_7 , L_15 ) ;
V_19 -> V_24 = V_54 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
int V_27 ;
if ( V_29 ) {
V_27 = 248 ;
F_1 ( V_2 , V_55 , V_27 / 4 ) ;
F_1 ( V_2 , V_43 ,
V_44 |
V_56 ) ;
} else {
V_27 = 10 ;
F_1 ( V_2 , V_43 ,
V_56 ) ;
}
if ( ! F_8 ( V_2 , V_37 ,
V_57 , V_27 ) ) {
F_6 ( & V_2 -> V_7 , L_16 ) ;
return - V_36 ;
}
if ( ! F_8 ( V_2 , V_34 ,
V_35 , 1 ) ) {
F_6 ( & V_2 -> V_7 , L_17 ) ;
return - V_36 ;
}
F_13 ( & V_2 -> V_7 , L_18 ) ;
V_19 -> V_24 = V_25 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
F_12 ( V_19 -> V_24 != V_54 ) ;
if ( V_29 ) {
F_1 ( V_2 , V_43 ,
V_44 |
V_46 |
V_58 ) ;
} else {
F_1 ( V_2 , V_43 ,
V_46 |
V_58 ) ;
}
if ( ! F_8 ( V_2 , V_37 ,
V_59 , 10 ) ) {
F_6 ( & V_2 -> V_7 , L_19 ) ;
return - V_36 ;
}
if ( ! F_8 ( V_2 , V_34 ,
V_35 , 1 ) ) {
F_6 ( & V_2 -> V_7 , L_17 ) ;
return - V_36 ;
}
F_1 ( V_2 , V_60 , V_61 ) ;
F_1 ( V_2 , V_20 , V_22 ) ;
V_19 -> V_24 = V_62 ;
F_13 ( & V_2 -> V_7 , L_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
F_12 ( V_19 -> V_24 != V_62 ) ;
F_1 ( V_2 , V_60 , 0 ) ;
if ( V_29 ) {
F_1 ( V_2 , V_43 ,
V_44 |
V_45 |
V_46 ) ;
} else {
F_1 ( V_2 , V_43 ,
V_45 |
V_46 ) ;
}
F_1 ( V_2 , V_20 , V_39 ) ;
F_1 ( V_2 , V_20 , V_52 ) ;
if ( ! F_8 ( V_2 , V_37 ,
V_53 , 10 ) ) {
F_6 ( & V_2 -> V_7 , L_21 ) ;
return - V_36 ;
}
V_19 -> V_24 = V_54 ;
F_13 ( & V_2 -> V_7 , L_22 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
int V_27 ;
F_12 ( V_19 -> V_24 != V_54 ) ;
if ( V_29 ) {
V_27 = 248 ;
F_1 ( V_2 , V_55 , V_27 / 4 ) ;
F_1 ( V_2 , V_43 ,
V_44 |
V_46 |
V_63 ) ;
} else {
V_27 = 10 ;
F_1 ( V_2 , V_43 ,
V_46 |
V_63 ) ;
}
if ( ! F_8 ( V_2 , V_37 ,
V_59 , V_27 ) ) {
F_6 ( & V_2 -> V_7 ,
L_23 ) ;
return - V_36 ;
}
if ( ! F_8 ( V_2 , V_34 , V_35 ,
1 ) ) {
F_6 ( & V_2 -> V_7 ,
L_24 ,
V_27 * 10 ) ;
return - V_36 ;
}
F_1 ( V_2 , V_60 , V_61 ) ;
F_1 ( V_2 , V_20 , V_22 ) ;
V_19 -> V_24 = V_64 ;
F_13 ( & V_2 -> V_7 , L_25 ) ;
if ( V_29 )
F_13 ( & V_2 -> V_7 , L_26 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
int V_27 ;
F_12 ( V_19 -> V_24 != V_64 ) ;
F_1 ( V_2 , V_60 , 0 ) ;
if ( V_29 ) {
V_27 = 248 ;
F_1 ( V_2 , V_42 , V_27 / 4 ) ;
F_1 ( V_2 , V_43 ,
V_44 |
V_46 |
V_45 ) ;
} else {
V_27 = 10 ;
F_1 ( V_2 , V_43 ,
V_46 |
V_45 ) ;
}
F_1 ( V_2 , V_20 , V_39 ) ;
F_1 ( V_2 , V_20 , V_52 ) ;
if ( ! F_8 ( V_2 , V_37 ,
V_53 , V_27 ) ) {
F_6 ( & V_2 -> V_7 , L_27 ,
V_27 * 10 ) ;
return - V_36 ;
}
V_19 -> V_24 = V_54 ;
F_13 ( & V_2 -> V_7 , L_22 ) ;
if ( V_29 )
F_13 ( & V_2 -> V_7 , L_28 ) ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 ,
enum V_65 V_66 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_67 , V_68 ;
int V_6 ;
if ( V_19 -> V_24 == V_66 )
return 0 ;
for ( V_67 = 0 ; V_67 < F_20 ( V_69 ) ; V_67 ++ )
if ( V_69 [ V_67 ] . V_70 == V_19 -> V_24 &&
V_69 [ V_67 ] . V_71 == V_66 )
break;
if ( V_67 == F_20 ( V_69 ) ) {
F_6 ( & V_2 -> V_7 , L_29 ,
V_19 -> V_24 , V_66 ) ;
return - V_72 ;
}
for ( V_68 = 0 ; V_68 < F_20 ( V_69 [ V_68 ] . V_73 ) ; V_68 ++ ) {
if ( ! V_69 [ V_67 ] . V_73 [ V_68 ] )
break;
V_6 = V_69 [ V_67 ] . V_73 [ V_68 ] ( V_2 ,
V_69 [ V_67 ] . V_29 ) ;
if ( V_6 != 0 )
return V_6 ;
}
return 0 ;
}
static int F_21 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
enum V_65 V_66 ;
if ( V_19 -> V_74 && V_19 -> V_75 )
if ( V_19 -> V_76 )
V_66 = V_54 ;
else
V_66 = V_62 ;
else
V_66 = V_64 ;
F_13 ( & V_2 -> V_7 , L_30 ,
V_66 , V_19 -> V_74 , ! V_19 -> V_75 ,
V_19 -> V_76 ) ;
return F_19 ( V_19 , V_66 ) ;
}
static int F_22 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_18 * V_19 = F_11 ( & V_81 -> V_7 ) ;
V_80 -> V_4 . V_82 . V_83 [ 0 ] = V_19 -> V_76 ;
return 0 ;
}
static int F_23 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_18 * V_19 = F_11 ( & V_81 -> V_7 ) ;
int V_76 = V_80 -> V_4 . V_82 . V_83 [ 0 ] ;
if ( V_76 > 1 )
return - V_72 ;
V_19 -> V_76 = V_76 ;
return F_21 ( V_19 ) ;
}
static int F_24 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_18 * V_19 = F_11 ( & V_81 -> V_7 ) ;
V_80 -> V_4 . V_82 . V_83 [ 0 ] = V_19 -> V_75 ;
return 0 ;
}
static int F_25 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_18 * V_19 = F_11 ( & V_81 -> V_7 ) ;
int V_28 = V_80 -> V_4 . V_82 . V_83 [ 0 ] ;
if ( V_28 > 1 )
return - V_72 ;
V_19 -> V_75 = V_28 ;
return F_21 ( V_19 ) ;
}
static int F_26 ( struct V_84 * V_85 ,
struct V_77 * V_78 , int V_86 )
{
struct V_18 * V_19 = F_11 ( & V_81 -> V_7 ) ;
if ( F_27 ( V_86 ) )
V_19 -> V_74 = 1 ;
if ( F_28 ( V_86 ) )
V_19 -> V_74 = 0 ;
return F_21 ( V_19 ) ;
}
int F_29 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = & V_88 -> V_90 ;
int V_6 ;
if ( ! V_81 ) {
F_30 ( L_31 ) ;
return - V_91 ;
}
V_6 = F_31 ( V_90 , V_92 ,
F_20 ( V_92 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_32 ( V_90 , V_93 , F_20 ( V_93 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return F_33 ( V_88 , V_94 ,
F_20 ( V_94 ) ) ;
}
static int T_2 F_34 ( struct V_1 * V_2 ,
const struct V_95 * V_96 )
{
struct V_18 * V_19 ;
struct V_97 * V_98 ;
const char * V_99 ;
const struct V_100 * V_101 ;
int V_3 , V_6 ;
T_3 V_102 ;
if ( V_81 ) {
F_6 ( & V_2 -> V_7 , L_32 ) ;
return - V_72 ;
}
V_19 = F_35 ( sizeof( struct V_18 ) , V_103 ) ;
if ( V_19 == NULL ) {
F_6 ( & V_2 -> V_7 , L_33 ) ;
return - V_104 ;
}
V_3 = F_4 ( V_2 , V_23 ) ;
V_102 = V_3 << 8 ;
V_3 = F_4 ( V_2 , V_105 ) ;
V_102 |= V_3 & 0xff ;
if ( V_102 != 0x2000 ) {
F_6 ( & V_2 -> V_7 , L_34 , V_102 ) ;
V_6 = - V_91 ;
goto V_106;
}
V_3 = F_4 ( V_2 , V_107 ) ;
F_36 ( & V_2 -> V_7 , L_35 , V_3 + 'A' ) ;
V_99 = L_36 ;
V_98 = F_37 ( & V_2 -> V_7 ) ;
if ( V_98 ) {
V_19 -> V_30 = V_98 -> V_108 ;
V_19 -> V_48 = ! V_98 -> V_109 ;
if ( V_98 -> V_110 )
V_99 = V_98 -> V_110 ;
}
V_6 = F_38 ( & V_101 , V_99 , & V_2 -> V_7 ) ;
if ( V_6 != 0 ) {
F_6 ( & V_2 -> V_7 , L_37 , V_6 ) ;
goto V_106;
}
V_19 -> V_40 = V_101 -> V_111 + 2 ;
V_19 -> V_41 = F_39 ( V_19 -> V_40 , V_103 ) ;
if ( V_19 -> V_41 == NULL ) {
F_6 ( & V_2 -> V_7 , L_38 ) ;
V_6 = - V_104 ;
goto V_112;
}
V_19 -> V_41 [ 0 ] = 0x80 ;
V_19 -> V_41 [ 1 ] = 0x00 ;
memcpy ( V_19 -> V_41 + 2 , V_101 -> V_5 , V_101 -> V_111 ) ;
F_40 ( V_101 ) ;
F_41 ( & V_2 -> V_7 , V_19 ) ;
V_19 -> V_74 = 1 ;
V_19 -> V_76 = 1 ;
V_19 -> V_75 = 1 ;
V_19 -> V_2 = V_2 ;
F_7 ( V_19 ) ;
F_21 ( V_19 ) ;
V_81 = V_2 ;
return 0 ;
V_112:
F_40 ( V_101 ) ;
V_106:
F_42 ( V_19 ) ;
return V_6 ;
}
static T_4 int F_43 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
F_19 ( V_19 , V_25 ) ;
V_81 = NULL ;
F_42 ( V_19 -> V_41 ) ;
F_42 ( V_19 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
F_19 ( V_19 , V_25 ) ;
}
static int F_45 ( struct V_113 * V_7 )
{
struct V_1 * V_2 = F_46 ( V_7 ) ;
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
return F_19 ( V_19 , V_25 ) ;
}
static int F_47 ( struct V_113 * V_7 )
{
struct V_1 * V_2 = F_46 ( V_7 ) ;
struct V_18 * V_19 = F_11 ( & V_2 -> V_7 ) ;
return F_21 ( V_19 ) ;
}
static int T_5 F_48 ( void )
{
return F_49 ( & V_114 ) ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_114 ) ;
}
