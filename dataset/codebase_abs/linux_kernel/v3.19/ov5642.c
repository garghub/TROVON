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
struct V_49 * V_50 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
const struct V_5 * V_51 = F_4 ( V_50 -> V_6 ) ;
V_50 -> V_28 = V_27 -> V_29 . V_28 ;
V_50 -> V_30 = V_27 -> V_29 . V_30 ;
if ( ! V_51 ) {
V_50 -> V_6 = V_8 [ 0 ] . V_6 ;
V_50 -> V_52 = V_8 [ 0 ] . V_52 ;
}
V_50 -> V_53 = V_54 ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 ,
struct V_49 * V_50 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
if ( ! F_4 ( V_50 -> V_6 ) )
return - V_20 ;
F_18 ( V_18 , V_50 ) ;
V_27 -> V_51 = F_4 ( V_50 -> V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 ,
struct V_49 * V_50 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
const struct V_5 * V_51 = V_27 -> V_51 ;
V_50 -> V_6 = V_51 -> V_6 ;
V_50 -> V_52 = V_51 -> V_52 ;
V_50 -> V_28 = V_27 -> V_29 . V_28 ;
V_50 -> V_30 = V_27 -> V_29 . V_30 ;
V_50 -> V_53 = V_54 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 , unsigned int V_55 ,
T_1 * V_6 )
{
if ( V_55 >= F_5 ( V_8 ) )
return - V_20 ;
* V_6 = V_8 [ V_55 ] . V_6 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 , const struct V_56 * V_57 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
struct V_58 V_59 = V_57 -> V_60 ;
int V_11 ;
F_23 ( & V_59 . V_28 , 48 , V_61 , 1 ,
& V_59 . V_30 , 32 , V_62 , 1 , 0 ) ;
V_27 -> V_29 . V_28 = V_59 . V_28 ;
V_27 -> V_29 . V_30 = V_59 . V_30 ;
V_27 -> V_31 = V_59 . V_28 + V_63 ;
V_27 -> V_32 = F_24 ( int , V_59 . V_30 +
V_64 ,
V_65 ) ;
V_27 -> V_29 . V_28 = V_59 . V_28 ;
V_27 -> V_29 . V_30 = V_59 . V_30 ;
V_11 = F_15 ( V_3 , V_66 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_18 ) ;
if ( ! V_11 )
V_11 = F_15 ( V_3 , V_67 ) ;
return V_11 ;
}
static int F_25 ( struct V_17 * V_18 , struct V_56 * V_57 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
struct V_58 * V_59 = & V_57 -> V_60 ;
if ( V_57 -> type != V_68 )
return - V_20 ;
* V_59 = V_27 -> V_29 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 , struct V_69 * V_57 )
{
V_57 -> V_70 . V_39 = 0 ;
V_57 -> V_70 . V_40 = 0 ;
V_57 -> V_70 . V_28 = V_61 ;
V_57 -> V_70 . V_30 = V_62 ;
V_57 -> V_71 = V_57 -> V_70 ;
V_57 -> type = V_68 ;
V_57 -> V_72 . V_73 = 1 ;
V_57 -> V_72 . V_74 = 1 ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 ,
struct V_75 * V_76 )
{
V_76 -> type = V_77 ;
V_76 -> V_78 = V_79 | V_80 |
V_81 ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 , int V_82 )
{
struct V_2 * V_3 = F_13 ( V_18 ) ;
struct V_83 * V_84 = F_29 ( V_3 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
int V_11 ;
if ( ! V_82 )
return F_30 ( & V_3 -> V_13 , V_84 , V_27 -> V_85 ) ;
V_11 = F_31 ( & V_3 -> V_13 , V_84 , V_27 -> V_85 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_15 ( V_3 , V_66 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_18 ) ;
if ( ! V_11 )
V_11 = F_15 ( V_3 , V_67 ) ;
return V_11 ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_17 * V_4 = F_3 ( V_3 ) ;
int V_11 ;
T_3 V_86 , V_87 ;
T_2 V_88 ;
V_11 = F_28 ( V_4 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_89 , & V_86 ) ;
if ( V_11 < 0 )
goto V_90;
V_88 = V_86 << 8 ;
V_11 = F_6 ( V_3 , V_91 , & V_87 ) ;
if ( V_11 < 0 )
goto V_90;
V_88 |= V_87 ;
F_33 ( & V_3 -> V_13 , L_4 , V_88 ) ;
if ( V_88 != 0x5642 ) {
V_11 = - V_92 ;
goto V_90;
}
V_11 = 0 ;
V_90:
F_28 ( V_4 , 0 ) ;
return V_11 ;
}
static int F_34 ( struct V_2 * V_3 ,
const struct V_93 * V_94 )
{
struct V_1 * V_27 ;
struct V_83 * V_84 = F_29 ( V_3 ) ;
int V_11 ;
if ( ! V_84 ) {
F_8 ( & V_3 -> V_13 , L_5 ) ;
return - V_20 ;
}
V_27 = F_35 ( & V_3 -> V_13 , sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_27 )
return - V_96 ;
F_36 ( & V_27 -> V_4 , V_3 , & V_97 ) ;
V_27 -> V_51 = & V_8 [ 0 ] ;
V_27 -> V_29 . V_28 = V_98 ;
V_27 -> V_29 . V_30 = V_99 ;
V_27 -> V_29 . V_39 = ( V_61 - V_98 ) / 2 ;
V_27 -> V_29 . V_40 = ( V_62 - V_99 ) / 2 ;
V_27 -> V_31 = V_98 + V_63 ;
V_27 -> V_32 = V_65 ;
V_27 -> V_85 = F_37 ( & V_3 -> V_13 , L_6 ) ;
if ( F_38 ( V_27 -> V_85 ) )
return F_39 ( V_27 -> V_85 ) ;
V_11 = F_32 ( V_3 ) ;
if ( V_11 < 0 )
F_40 ( V_27 -> V_85 ) ;
return V_11 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_83 * V_84 = F_29 ( V_3 ) ;
struct V_1 * V_27 = F_1 ( V_3 ) ;
F_40 ( V_27 -> V_85 ) ;
if ( V_84 -> V_100 )
V_84 -> V_100 ( V_84 ) ;
return 0 ;
}
