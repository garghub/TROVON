static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static const struct V_5
* F_4 ( enum V_6 V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] . V_7 == V_7 )
return V_9 + V_8 ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_10 , T_2 * V_11 )
{
int V_12 ;
unsigned char V_13 [ 2 ] = { V_10 >> 8 , V_10 & 0xff } ;
V_12 = F_7 ( V_3 , V_13 , 2 ) ;
if ( V_12 < 2 ) {
F_8 ( & V_3 -> V_14 , L_1 ,
V_15 , V_10 ) ;
return V_12 < 0 ? V_12 : - V_16 ;
}
V_12 = F_9 ( V_3 , V_11 , 1 ) ;
if ( V_12 < 1 ) {
F_8 ( & V_3 -> V_14 , L_1 ,
V_15 , V_10 ) ;
return V_12 < 0 ? V_12 : - V_16 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_10 , T_2 V_11 )
{
int V_12 ;
unsigned char V_13 [ 3 ] = { V_10 >> 8 , V_10 & 0xff , V_11 } ;
V_12 = F_7 ( V_3 , V_13 , 3 ) ;
if ( V_12 < 3 ) {
F_8 ( & V_3 -> V_14 , L_2 ,
V_15 , V_10 ) ;
return V_12 < 0 ? V_12 : - V_16 ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_10 , T_1 V_17 )
{
int V_12 ;
V_12 = F_10 ( V_3 , V_10 , V_17 >> 8 ) ;
if ( V_12 )
return V_12 ;
return F_10 ( V_3 , V_10 + 1 , V_17 & 0x00ff ) ;
}
static int F_12 ( struct V_18 * V_19 , struct V_20 * V_10 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
int V_12 ;
T_2 V_11 ;
if ( V_10 -> V_10 & ~ 0xffff )
return - V_21 ;
V_10 -> V_22 = 1 ;
V_12 = F_6 ( V_3 , V_10 -> V_10 , & V_11 ) ;
if ( ! V_12 )
V_10 -> V_11 = ( V_23 ) V_11 ;
return V_12 ;
}
static int F_14 ( struct V_18 * V_19 , const struct V_20 * V_10 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
if ( V_10 -> V_10 & ~ 0xffff || V_10 -> V_11 & ~ 0xff )
return - V_21 ;
return F_10 ( V_3 , V_10 -> V_10 , V_10 -> V_11 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
while ( V_25 -> V_26 != 0xffff || V_25 -> V_27 != 0xff ) {
int V_12 = F_10 ( V_3 , V_25 -> V_26 , V_25 -> V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
V_25 ++ ;
}
F_16 ( & V_3 -> V_14 , L_3 ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
int V_29 = V_28 -> V_30 . V_29 ;
int V_31 = V_28 -> V_30 . V_31 ;
int V_32 = V_28 -> V_32 ;
int V_33 = V_28 -> V_33 ;
int V_34 = ( V_35 - V_29 ) / 2 ;
int V_36 = ( V_37 - V_31 ) / 2 ;
int V_12 ;
V_12 = F_11 ( V_3 , V_38 , V_34 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_39 , V_36 ) ;
if ( ! V_12 ) {
V_28 -> V_30 . V_40 = V_34 ;
V_28 -> V_30 . V_41 = V_36 ;
}
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_42 , V_29 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_43 , V_31 ) ;
if ( V_12 )
return V_12 ;
V_28 -> V_30 . V_29 = V_29 ;
V_28 -> V_30 . V_31 = V_31 ;
V_12 = F_11 ( V_3 , V_44 , V_29 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_45 , V_31 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_46 , V_32 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_47 , V_33 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_48 , V_29 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_3 , V_49 , V_31 ) ;
return V_12 ;
}
static int F_18 ( struct V_18 * V_19 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
const struct V_5 * V_52 = F_4 ( V_51 -> V_7 ) ;
V_51 -> V_29 = V_28 -> V_30 . V_29 ;
V_51 -> V_31 = V_28 -> V_30 . V_31 ;
if ( ! V_52 ) {
V_51 -> V_7 = V_9 [ 0 ] . V_7 ;
V_51 -> V_53 = V_9 [ 0 ] . V_53 ;
}
V_51 -> V_54 = V_55 ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
if ( ! F_4 ( V_51 -> V_7 ) )
return - V_21 ;
F_18 ( V_19 , V_51 ) ;
V_28 -> V_52 = F_4 ( V_51 -> V_7 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
const struct V_5 * V_52 = V_28 -> V_52 ;
V_51 -> V_7 = V_52 -> V_7 ;
V_51 -> V_53 = V_52 -> V_53 ;
V_51 -> V_29 = V_28 -> V_30 . V_29 ;
V_51 -> V_31 = V_28 -> V_30 . V_31 ;
V_51 -> V_54 = V_55 ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 , unsigned int V_56 ,
enum V_6 * V_7 )
{
if ( V_56 >= F_5 ( V_9 ) )
return - V_21 ;
* V_7 = V_9 [ V_56 ] . V_7 ;
return 0 ;
}
static int F_22 ( struct V_18 * V_19 ,
struct V_57 * V_58 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
if ( V_58 -> V_59 . type != V_60 )
return - V_21 ;
if ( V_58 -> V_59 . V_61 != V_3 -> V_61 )
return - V_62 ;
V_58 -> V_63 = V_64 ;
V_58 -> V_65 = 0 ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 , const struct V_66 * V_67 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
struct V_68 V_69 = V_67 -> V_70 ;
int V_12 ;
F_24 ( & V_69 . V_29 , 48 , V_71 , 1 ,
& V_69 . V_31 , 32 , V_72 , 1 , 0 ) ;
V_28 -> V_30 . V_29 = V_69 . V_29 ;
V_28 -> V_30 . V_31 = V_69 . V_31 ;
V_28 -> V_32 = V_69 . V_29 + V_73 ;
V_28 -> V_33 = F_25 ( int , V_69 . V_31 +
V_74 ,
V_75 ) ;
V_28 -> V_30 . V_29 = V_69 . V_29 ;
V_28 -> V_30 . V_31 = V_69 . V_31 ;
V_12 = F_15 ( V_3 , V_76 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_19 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_3 , V_77 ) ;
return V_12 ;
}
static int F_26 ( struct V_18 * V_19 , struct V_66 * V_67 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
struct V_68 * V_69 = & V_67 -> V_70 ;
if ( V_67 -> type != V_78 )
return - V_21 ;
* V_69 = V_28 -> V_30 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , struct V_79 * V_67 )
{
V_67 -> V_80 . V_40 = 0 ;
V_67 -> V_80 . V_41 = 0 ;
V_67 -> V_80 . V_29 = V_71 ;
V_67 -> V_80 . V_31 = V_72 ;
V_67 -> V_81 = V_67 -> V_80 ;
V_67 -> type = V_78 ;
V_67 -> V_82 . V_83 = 1 ;
V_67 -> V_82 . V_84 = 1 ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_85 * V_86 )
{
V_86 -> type = V_87 ;
V_86 -> V_88 = V_89 | V_90 |
V_91 ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 , int V_92 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_93 * V_94 = F_30 ( V_3 ) ;
int V_12 ;
if ( ! V_92 )
return F_31 ( & V_3 -> V_14 , V_94 ) ;
V_12 = F_32 ( & V_3 -> V_14 , V_94 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_15 ( V_3 , V_76 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_19 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_3 , V_77 ) ;
return V_12 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_18 * V_4 = F_3 ( V_3 ) ;
int V_12 ;
T_2 V_95 , V_96 ;
T_1 V_58 ;
V_12 = F_29 ( V_4 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_3 , V_97 , & V_95 ) ;
if ( V_12 < 0 )
goto V_98;
V_58 = V_95 << 8 ;
V_12 = F_6 ( V_3 , V_99 , & V_96 ) ;
if ( V_12 < 0 )
goto V_98;
V_58 |= V_96 ;
F_34 ( & V_3 -> V_14 , L_4 , V_58 ) ;
if ( V_58 != 0x5642 ) {
V_12 = - V_62 ;
goto V_98;
}
V_12 = 0 ;
V_98:
F_29 ( V_4 , 0 ) ;
return V_12 ;
}
static int F_35 ( struct V_2 * V_3 ,
const struct V_100 * V_101 )
{
struct V_1 * V_28 ;
struct V_93 * V_94 = F_30 ( V_3 ) ;
if ( ! V_94 ) {
F_8 ( & V_3 -> V_14 , L_5 ) ;
return - V_21 ;
}
V_28 = F_36 ( & V_3 -> V_14 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_28 )
return - V_103 ;
F_37 ( & V_28 -> V_4 , V_3 , & V_104 ) ;
V_28 -> V_52 = & V_9 [ 0 ] ;
V_28 -> V_30 . V_29 = V_105 ;
V_28 -> V_30 . V_31 = V_106 ;
V_28 -> V_30 . V_40 = ( V_71 - V_105 ) / 2 ;
V_28 -> V_30 . V_41 = ( V_72 - V_106 ) / 2 ;
V_28 -> V_32 = V_105 + V_73 ;
V_28 -> V_33 = V_75 ;
return F_33 ( V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_93 * V_94 = F_30 ( V_3 ) ;
if ( V_94 -> V_107 )
V_94 -> V_107 ( V_94 ) ;
return 0 ;
}
