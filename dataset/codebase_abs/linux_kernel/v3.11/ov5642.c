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
static int F_22 ( struct V_18 * V_19 , const struct V_57 * V_58 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
struct V_59 V_60 = V_58 -> V_61 ;
int V_12 ;
F_23 ( & V_60 . V_29 , 48 , V_62 , 1 ,
& V_60 . V_31 , 32 , V_63 , 1 , 0 ) ;
V_28 -> V_30 . V_29 = V_60 . V_29 ;
V_28 -> V_30 . V_31 = V_60 . V_31 ;
V_28 -> V_32 = V_60 . V_29 + V_64 ;
V_28 -> V_33 = F_24 ( int , V_60 . V_31 +
V_65 ,
V_66 ) ;
V_28 -> V_30 . V_29 = V_60 . V_29 ;
V_28 -> V_30 . V_31 = V_60 . V_31 ;
V_12 = F_15 ( V_3 , V_67 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_19 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_3 , V_68 ) ;
return V_12 ;
}
static int F_25 ( struct V_18 * V_19 , struct V_57 * V_58 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
struct V_59 * V_60 = & V_58 -> V_61 ;
if ( V_58 -> type != V_69 )
return - V_21 ;
* V_60 = V_28 -> V_30 ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , struct V_70 * V_58 )
{
V_58 -> V_71 . V_40 = 0 ;
V_58 -> V_71 . V_41 = 0 ;
V_58 -> V_71 . V_29 = V_62 ;
V_58 -> V_71 . V_31 = V_63 ;
V_58 -> V_72 = V_58 -> V_71 ;
V_58 -> type = V_69 ;
V_58 -> V_73 . V_74 = 1 ;
V_58 -> V_73 . V_75 = 1 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 ,
struct V_76 * V_77 )
{
V_77 -> type = V_78 ;
V_77 -> V_79 = V_80 | V_81 |
V_82 ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 , int V_83 )
{
struct V_2 * V_3 = F_13 ( V_19 ) ;
struct V_84 * V_85 = F_29 ( V_3 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
int V_12 ;
if ( ! V_83 )
return F_30 ( & V_3 -> V_14 , V_85 , V_28 -> V_86 ) ;
V_12 = F_31 ( & V_3 -> V_14 , V_85 , V_28 -> V_86 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_15 ( V_3 , V_67 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_19 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_3 , V_68 ) ;
return V_12 ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_18 * V_4 = F_3 ( V_3 ) ;
int V_12 ;
T_2 V_87 , V_88 ;
T_1 V_89 ;
V_12 = F_28 ( V_4 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_3 , V_90 , & V_87 ) ;
if ( V_12 < 0 )
goto V_91;
V_89 = V_87 << 8 ;
V_12 = F_6 ( V_3 , V_92 , & V_88 ) ;
if ( V_12 < 0 )
goto V_91;
V_89 |= V_88 ;
F_33 ( & V_3 -> V_14 , L_4 , V_89 ) ;
if ( V_89 != 0x5642 ) {
V_12 = - V_93 ;
goto V_91;
}
V_12 = 0 ;
V_91:
F_28 ( V_4 , 0 ) ;
return V_12 ;
}
static int F_34 ( struct V_2 * V_3 ,
const struct V_94 * V_95 )
{
struct V_1 * V_28 ;
struct V_84 * V_85 = F_29 ( V_3 ) ;
int V_12 ;
if ( ! V_85 ) {
F_8 ( & V_3 -> V_14 , L_5 ) ;
return - V_21 ;
}
V_28 = F_35 ( & V_3 -> V_14 , sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_28 )
return - V_97 ;
F_36 ( & V_28 -> V_4 , V_3 , & V_98 ) ;
V_28 -> V_52 = & V_9 [ 0 ] ;
V_28 -> V_30 . V_29 = V_99 ;
V_28 -> V_30 . V_31 = V_100 ;
V_28 -> V_30 . V_40 = ( V_62 - V_99 ) / 2 ;
V_28 -> V_30 . V_41 = ( V_63 - V_100 ) / 2 ;
V_28 -> V_32 = V_99 + V_64 ;
V_28 -> V_33 = V_66 ;
V_28 -> V_86 = F_37 ( & V_3 -> V_14 , L_6 ) ;
if ( F_38 ( V_28 -> V_86 ) )
return F_39 ( V_28 -> V_86 ) ;
V_12 = F_32 ( V_3 ) ;
if ( V_12 < 0 )
F_40 ( V_28 -> V_86 ) ;
return V_12 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_84 * V_85 = F_29 ( V_3 ) ;
struct V_1 * V_28 = F_1 ( V_3 ) ;
F_40 ( V_28 -> V_86 ) ;
if ( V_85 -> V_101 )
V_85 -> V_101 ( V_85 ) ;
return 0 ;
}
