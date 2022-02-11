static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static const struct V_5
* F_4 ( T_1 V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_8 ) ; V_7 ++ )
if ( V_8 [ V_7 ] . V_6 == V_6 )
return V_8 + V_7 ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 , T_2 V_9 , T_3 * V_10 )
{
int V_11 ;
unsigned char V_12 [ 2 ] = { V_9 >> 8 , V_9 & 0xff } ;
V_11 = F_7 ( V_3 , V_12 , 2 ) ;
if ( V_11 < 2 ) {
F_8 ( & V_3 -> V_13 , L_1 ,
V_14 , V_9 ) ;
return V_11 < 0 ? V_11 : - V_15 ;
}
V_11 = F_9 ( V_3 , V_10 , 1 ) ;
if ( V_11 < 1 ) {
F_8 ( & V_3 -> V_13 , L_1 ,
V_14 , V_9 ) ;
return V_11 < 0 ? V_11 : - V_15 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , T_2 V_9 , T_3 V_10 )
{
int V_11 ;
unsigned char V_12 [ 3 ] = { V_9 >> 8 , V_9 & 0xff , V_10 } ;
V_11 = F_7 ( V_3 , V_12 , 3 ) ;
if ( V_11 < 3 ) {
F_8 ( & V_3 -> V_13 , L_2 ,
V_14 , V_9 ) ;
return V_11 < 0 ? V_11 : - V_15 ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , T_2 V_9 , T_2 V_16 )
{
int V_11 ;
V_11 = F_10 ( V_3 , V_9 , V_16 >> 8 ) ;
if ( V_11 )
return V_11 ;
return F_10 ( V_3 , V_9 + 1 , V_16 & 0x00ff ) ;
}
static int F_12 ( struct V_17 * V_18 , struct V_19 * V_9 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
int V_11 ;
T_3 V_10 ;
if ( V_9 -> V_9 & ~ 0xffff )
return - V_20 ;
V_9 -> V_21 = 1 ;
V_11 = F_6 ( V_3 , V_9 -> V_9 , & V_10 ) ;
if ( ! V_11 )
V_9 -> V_10 = ( V_22 ) V_10 ;
return V_11 ;
}
static int F_14 ( struct V_17 * V_18 , const struct V_19 * V_9 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
if ( V_9 -> V_9 & ~ 0xffff || V_9 -> V_10 & ~ 0xff )
return - V_20 ;
return F_10 ( V_3 , V_9 -> V_9 , V_9 -> V_10 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
while ( V_24 -> V_25 != 0xffff || V_24 -> V_26 != 0xff ) {
int V_11 = F_10 ( V_3 , V_24 -> V_25 , V_24 -> V_26 ) ;
if ( V_11 < 0 )
return V_11 ;
V_24 ++ ;
}
F_16 ( & V_3 -> V_13 , L_3 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
int V_28 = V_27 -> V_29 . V_28 ;
int V_30 = V_27 -> V_29 . V_30 ;
int V_31 = V_27 -> V_31 ;
int V_32 = V_27 -> V_32 ;
int V_33 = ( V_34 - V_28 ) / 2 ;
int V_35 = ( V_36 - V_30 ) / 2 ;
int V_11 ;
V_11 = F_11 ( V_3 , V_37 , V_33 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_38 , V_35 ) ;
if ( ! V_11 ) {
V_27 -> V_29 . V_39 = V_33 ;
V_27 -> V_29 . V_40 = V_35 ;
}
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_41 , V_28 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_42 , V_30 ) ;
if ( V_11 )
return V_11 ;
V_27 -> V_29 . V_28 = V_28 ;
V_27 -> V_29 . V_30 = V_30 ;
V_11 = F_11 ( V_3 , V_43 , V_28 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_44 , V_30 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_45 , V_31 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_46 , V_32 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_47 , V_28 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_3 , V_48 , V_30 ) ;
return V_11 ;
}
static int F_18 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = & V_52 -> V_52 ;
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
const struct V_5 * V_55 = F_4 ( V_54 -> V_6 ) ;
if ( V_52 -> V_56 )
return - V_20 ;
V_54 -> V_28 = V_27 -> V_29 . V_28 ;
V_54 -> V_30 = V_27 -> V_29 . V_30 ;
if ( ! V_55 ) {
if ( V_52 -> V_57 == V_58 )
return - V_20 ;
V_54 -> V_6 = V_8 [ 0 ] . V_6 ;
V_54 -> V_59 = V_8 [ 0 ] . V_59 ;
}
V_54 -> V_60 = V_61 ;
if ( V_52 -> V_57 == V_58 )
V_27 -> V_55 = V_55 ;
else
V_50 -> V_62 = * V_54 ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = & V_52 -> V_52 ;
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
const struct V_5 * V_55 = V_27 -> V_55 ;
if ( V_52 -> V_56 )
return - V_20 ;
V_54 -> V_6 = V_55 -> V_6 ;
V_54 -> V_59 = V_55 -> V_59 ;
V_54 -> V_28 = V_27 -> V_29 . V_28 ;
V_54 -> V_30 = V_27 -> V_29 . V_30 ;
V_54 -> V_60 = V_61 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
struct V_63 * V_6 )
{
if ( V_6 -> V_56 || V_6 -> V_64 >= F_5 ( V_8 ) )
return - V_20 ;
V_6 -> V_6 = V_8 [ V_6 -> V_64 ] . V_6 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
struct V_65 * V_66 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
struct V_67 V_68 = V_66 -> V_69 ;
int V_11 ;
if ( V_66 -> V_57 != V_58 ||
V_66 -> V_70 != V_71 )
return - V_20 ;
F_22 ( & V_68 . V_28 , 48 , V_72 , 1 ,
& V_68 . V_30 , 32 , V_73 , 1 , 0 ) ;
V_27 -> V_29 . V_28 = V_68 . V_28 ;
V_27 -> V_29 . V_30 = V_68 . V_30 ;
V_27 -> V_31 = V_68 . V_28 + V_74 ;
V_27 -> V_32 = F_23 ( int , V_68 . V_30 +
V_75 ,
V_76 ) ;
V_27 -> V_29 . V_28 = V_68 . V_28 ;
V_27 -> V_29 . V_30 = V_68 . V_30 ;
V_11 = F_15 ( V_3 , V_77 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_18 ) ;
if ( ! V_11 )
V_11 = F_15 ( V_3 , V_78 ) ;
return V_11 ;
}
static int F_24 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
struct V_65 * V_66 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
if ( V_66 -> V_57 != V_58 )
return - V_20 ;
switch ( V_66 -> V_70 ) {
case V_79 :
case V_80 :
V_66 -> V_69 . V_39 = 0 ;
V_66 -> V_69 . V_40 = 0 ;
V_66 -> V_69 . V_28 = V_72 ;
V_66 -> V_69 . V_30 = V_73 ;
return 0 ;
case V_71 :
V_66 -> V_69 = V_27 -> V_29 ;
return 0 ;
default:
return - V_20 ;
}
}
static int F_25 ( struct V_17 * V_18 ,
struct V_81 * V_50 )
{
V_50 -> type = V_82 ;
V_50 -> V_83 = V_84 | V_85 |
V_86 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 , int V_87 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_88 * V_89 = F_27 ( V_3 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
int V_11 ;
if ( ! V_87 )
return F_28 ( & V_3 -> V_13 , V_89 , V_27 -> V_90 ) ;
V_11 = F_29 ( & V_3 -> V_13 , V_89 , V_27 -> V_90 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_15 ( V_3 , V_77 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_18 ) ;
if ( ! V_11 )
V_11 = F_15 ( V_3 , V_78 ) ;
return V_11 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_17 * V_4 = F_3 ( V_3 ) ;
int V_11 ;
T_3 V_91 , V_92 ;
T_2 V_93 ;
V_11 = F_26 ( V_4 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_94 , & V_91 ) ;
if ( V_11 < 0 )
goto V_95;
V_93 = V_91 << 8 ;
V_11 = F_6 ( V_3 , V_96 , & V_92 ) ;
if ( V_11 < 0 )
goto V_95;
V_93 |= V_92 ;
F_31 ( & V_3 -> V_13 , L_4 , V_93 ) ;
if ( V_93 != 0x5642 ) {
V_11 = - V_97 ;
goto V_95;
}
V_11 = 0 ;
V_95:
F_26 ( V_4 , 0 ) ;
return V_11 ;
}
static int F_32 ( struct V_2 * V_3 ,
const struct V_98 * V_99 )
{
struct V_1 * V_27 ;
struct V_88 * V_89 = F_27 ( V_3 ) ;
int V_11 ;
if ( ! V_89 ) {
F_8 ( & V_3 -> V_13 , L_5 ) ;
return - V_20 ;
}
V_27 = F_33 ( & V_3 -> V_13 , sizeof( struct V_1 ) , V_100 ) ;
if ( ! V_27 )
return - V_101 ;
F_34 ( & V_27 -> V_4 , V_3 , & V_102 ) ;
V_27 -> V_55 = & V_8 [ 0 ] ;
V_27 -> V_29 . V_28 = V_103 ;
V_27 -> V_29 . V_30 = V_104 ;
V_27 -> V_29 . V_39 = ( V_72 - V_103 ) / 2 ;
V_27 -> V_29 . V_40 = ( V_73 - V_104 ) / 2 ;
V_27 -> V_31 = V_103 + V_74 ;
V_27 -> V_32 = V_76 ;
V_27 -> V_90 = F_35 ( & V_3 -> V_13 , L_6 ) ;
if ( F_36 ( V_27 -> V_90 ) )
return F_37 ( V_27 -> V_90 ) ;
V_11 = F_30 ( V_3 ) ;
if ( V_11 < 0 )
F_38 ( V_27 -> V_90 ) ;
return V_11 ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_88 * V_89 = F_27 ( V_3 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
F_38 ( V_27 -> V_90 ) ;
if ( V_89 -> V_105 )
V_89 -> V_105 ( V_89 ) ;
return 0 ;
}
