static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_1 , T_1 V_4 , T_1 V_5 , T_1 * V_6 )
{
if ( V_5 == 1 )
return F_4 ( V_1 -> V_7 , V_4 , * V_6 ) ;
else
return F_5 ( V_1 -> V_7 , V_4 , V_5 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
unsigned char V_8 [ 6 ] ;
if ( V_1 -> V_9 )
V_8 [ 0 ] = 0x50 ;
else
V_8 [ 0 ] = 0x51 ;
V_8 [ 1 ] = 0x02 ;
if ( V_1 -> V_10 > 0xef )
V_8 [ 2 ] = 0xef ;
else if ( V_1 -> V_10 < 0 )
V_8 [ 2 ] = 0x00 ;
else
V_8 [ 2 ] = V_1 -> V_10 ;
V_8 [ 3 ] = 0xb0 ;
V_8 [ 4 ] = 0x60 ;
V_8 [ 5 ] = 0xa0 ;
F_3 ( V_1 , V_11 , 6 , V_8 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
T_1 V_12 ;
V_12 = F_8 ( V_1 -> V_13 ) ;
F_3 ( V_1 , V_14 , 1 , & V_12 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
T_1 V_12 ;
V_12 = F_10 ( V_1 -> V_15 ) ;
F_3 ( V_1 , V_16 , 1 , & V_12 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
T_1 V_17 [ 6 ] ;
int V_12 ;
T_1 V_18 , V_19 ;
V_18 = V_1 -> V_20 ;
V_19 = V_1 -> V_21 ;
if ( V_18 > 177 ) V_18 = 177 ;
if ( V_19 > 177 ) V_19 = 177 ;
if ( V_1 -> V_22 ) V_18 = 0 ;
if ( V_1 -> V_23 ) V_19 = 0 ;
V_12 = V_24 [ V_18 ] ;
V_17 [ 0 ] = V_12 >> 20 ;
V_17 [ 1 ] = V_12 >> 12 ;
V_17 [ 2 ] = V_12 >> 4 ;
V_12 = V_24 [ V_19 ] ;
V_17 [ 3 ] = V_12 >> 20 ;
V_17 [ 4 ] = V_12 >> 12 ;
V_17 [ 5 ] = V_12 >> 4 ;
F_3 ( V_1 , V_25 , 6 , V_17 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
T_1 V_17 [ 9 ] ;
int V_12 , V_26 ;
T_1 V_8 ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
V_8 = V_1 -> V_27 [ V_26 ] ;
if ( V_8 > 177 ) V_8 = 177 ;
V_12 = V_24 [ V_8 ] ;
V_17 [ 3 * V_26 + 0 ] = V_12 >> 16 ;
V_17 [ 3 * V_26 + 1 ] = V_12 >> 8 ;
V_17 [ 3 * V_26 + 2 ] = V_12 ;
}
F_3 ( V_1 , V_28 , 9 , V_17 ) ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
V_8 = V_1 -> V_29 [ V_26 ] ;
if ( V_8 > 177 ) V_8 = 177 ;
V_12 = V_24 [ V_8 ] ;
V_17 [ 3 * V_26 + 0 ] = V_12 >> 16 ;
V_17 [ 3 * V_26 + 1 ] = V_12 >> 8 ;
V_17 [ 3 * V_26 + 2 ] = V_12 ;
}
F_3 ( V_1 , V_30 , 9 , V_17 ) ;
}
static int F_13 ( struct V_31 * V_32 )
{
return 0 ;
}
static int F_14 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 2 ;
V_36 -> V_39 . integer . V_40 = 0 ;
V_36 -> V_39 . integer . V_41 = 177 ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_20 ;
V_43 -> V_39 . integer . V_39 [ 1 ] = V_1 -> V_21 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
if ( V_43 -> V_39 . integer . V_39 [ 0 ] < 0 ||
V_43 -> V_39 . integer . V_39 [ 0 ] > 177 )
return - V_45 ;
if ( V_43 -> V_39 . integer . V_39 [ 1 ] < 0 ||
V_43 -> V_39 . integer . V_39 [ 1 ] > 177 )
return - V_45 ;
F_17 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_20 == V_43 -> V_39 . integer . V_39 [ 0 ]
&& V_1 -> V_21 == V_43 -> V_39 . integer . V_39 [ 1 ] ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
V_1 -> V_20 = V_43 -> V_39 . integer . V_39 [ 0 ] ;
V_1 -> V_21 = V_43 -> V_39 . integer . V_39 [ 1 ] ;
if ( V_1 -> V_46 )
F_11 ( V_1 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_20 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = ! V_1 -> V_22 ;
V_43 -> V_39 . integer . V_39 [ 1 ] = ! V_1 -> V_23 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_22 == ! V_43 -> V_39 . integer . V_39 [ 0 ]
&& V_1 -> V_23 == ! V_43 -> V_39 . integer . V_39 [ 1 ] ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
V_1 -> V_22 = ! V_43 -> V_39 . integer . V_39 [ 0 ] ;
V_1 -> V_23 = ! V_43 -> V_39 . integer . V_39 [ 1 ] ;
if ( V_1 -> V_46 )
F_11 ( V_1 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 2 ;
V_36 -> V_39 . integer . V_40 = 0 ;
V_36 -> V_39 . integer . V_41 = 177 ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
int V_47 = V_34 -> V_48 ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_27 [ V_47 ] ;
V_43 -> V_39 . integer . V_39 [ 1 ] = V_1 -> V_29 [ V_47 ] ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_24 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
int V_47 = V_34 -> V_48 ;
F_17 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_27 [ V_47 ] == V_43 -> V_39 . integer . V_39 [ 0 ]
&& V_1 -> V_29 [ V_47 ] == V_43 -> V_39 . integer . V_39 [ 1 ] ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
V_1 -> V_27 [ V_47 ] = V_43 -> V_39 . integer . V_39 [ 0 ] ;
V_1 -> V_29 [ V_47 ] = V_43 -> V_39 . integer . V_39 [ 1 ] ;
if ( V_1 -> V_46 )
F_12 ( V_1 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_25 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 1 ;
V_36 -> V_39 . integer . V_40 = 0 ;
V_36 -> V_39 . integer . V_41 = V_49 ;
return 0 ;
}
static int F_26 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_10 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_27 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
if ( V_43 -> V_39 . integer . V_39 [ 0 ] < 0 ||
V_43 -> V_39 . integer . V_39 [ 0 ] > V_49 )
return - V_45 ;
F_17 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_10 == V_43 -> V_39 . integer . V_39 [ 0 ] ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
V_1 -> V_10 = V_43 -> V_39 . integer . V_39 [ 0 ] ;
if ( V_1 -> V_46 )
F_6 ( V_1 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_28 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_9 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_29 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_9 == V_43 -> V_39 . integer . V_39 [ 0 ] ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
V_1 -> V_9 = ! ! V_43 -> V_39 . integer . V_39 [ 0 ] ;
if ( V_1 -> V_46 )
F_6 ( V_1 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_30 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
static const char * const V_50 [] = { L_1 , L_2 } ;
return F_31 ( V_36 , 1 , 2 , V_50 ) ;
}
static int F_32 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . V_51 . V_52 [ 0 ] = ! ! ( V_1 -> V_53 & V_54 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_33 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
int V_55 ;
if ( V_43 -> V_39 . V_51 . V_52 [ 0 ] > 1 )
return - V_45 ;
F_17 ( & V_1 -> V_44 ) ;
V_55 = V_1 -> V_53 ;
V_1 -> V_53 &= ~ ( V_54 | V_56 ) ;
if ( V_43 -> V_39 . V_51 . V_52 [ 0 ] )
V_1 -> V_53 |= V_54 | V_56 |
V_57 ;
if ( V_55 == V_1 -> V_53 ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
if ( V_1 -> V_46 )
F_3 ( V_1 , V_58 , 1 , & V_1 -> V_53 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_34 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 1 ;
V_36 -> V_39 . integer . V_40 = V_59 ;
V_36 -> V_39 . integer . V_41 = V_60 ;
return 0 ;
}
static int F_35 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_13 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_36 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
if ( V_43 -> V_39 . integer . V_39 [ 0 ] < V_59 ||
V_43 -> V_39 . integer . V_39 [ 0 ] > V_60 )
return - V_45 ;
F_17 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_13 == V_43 -> V_39 . integer . V_39 [ 0 ] ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
V_1 -> V_13 = V_43 -> V_39 . integer . V_39 [ 0 ] ;
if ( V_1 -> V_46 )
F_7 ( V_1 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_37 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 1 ;
V_36 -> V_39 . integer . V_40 = V_61 ;
V_36 -> V_39 . integer . V_41 = V_62 ;
return 0 ;
}
static int F_38 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_15 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_39 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
if ( V_43 -> V_39 . integer . V_39 [ 0 ] < V_61 ||
V_43 -> V_39 . integer . V_39 [ 0 ] > V_62 )
return - V_45 ;
F_17 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_15 == V_43 -> V_39 . integer . V_39 [ 0 ] ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
V_1 -> V_15 = V_43 -> V_39 . integer . V_39 [ 0 ] ;
if ( V_1 -> V_46 )
F_9 ( V_1 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_40 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
struct V_65 * V_67 )
{
return 1 ;
}
static int F_41 ( struct V_1 * V_1 )
{
T_1 V_12 ;
V_1 -> V_3 . V_68 -> V_69 -> V_70 ( V_1 -> V_3 . V_68 ) ;
F_42 ( 5 ) ;
V_1 -> V_3 . V_68 -> V_69 -> V_71 ( V_1 -> V_3 . V_68 , 0 ) ;
F_42 ( 5 ) ;
V_1 -> V_3 . V_68 -> V_69 -> V_71 ( V_1 -> V_3 . V_68 , 1 ) ;
F_42 ( 20 ) ;
V_1 -> V_3 . V_68 -> V_69 -> V_71 ( V_1 -> V_3 . V_68 , 0 ) ;
F_42 ( 10 ) ;
V_1 -> V_3 . V_68 -> V_69 -> V_72 ( V_1 -> V_3 . V_68 ) ;
V_12 = V_73 | V_74 | V_75 ;
if ( F_3 ( V_1 , V_76 , 1 , & V_12 ) )
goto V_77;
V_1 -> V_53 |= V_78 ;
if ( F_3 ( V_1 , V_58 , 1 , & V_1 -> V_53 ) )
goto V_77;
V_12 = 0 ;
if ( F_3 ( V_1 , V_79 , 1 , & V_12 ) )
goto V_77;
F_6 ( V_1 ) ;
V_1 -> V_13 = V_80 ;
V_1 -> V_15 = V_81 ;
F_7 ( V_1 ) ;
F_9 ( V_1 ) ;
V_1 -> V_53 &= ~ V_78 ;
if ( F_3 ( V_1 , V_58 , 1 , & V_1 -> V_53 ) )
goto V_77;
return 0 ;
V_77:
return - V_82 ;
}
static int F_43 ( struct V_63 * V_64 , enum V_83 clock )
{
struct V_1 * V_1 = V_64 -> V_84 ;
switch( clock ) {
case V_85 :
V_1 -> V_3 . V_68 -> V_69 -> V_70 ( V_1 -> V_3 . V_68 ) ;
V_1 -> V_46 = 0 ;
break;
case V_86 :
F_17 ( & V_1 -> V_44 ) ;
F_41 ( V_1 ) ;
F_11 ( V_1 ) ;
F_12 ( V_1 ) ;
V_1 -> V_46 = 1 ;
V_1 -> V_3 . V_68 -> V_69 -> V_72 ( V_1 -> V_3 . V_68 ) ;
F_18 ( & V_1 -> V_44 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_1 )
{
F_17 ( & V_1 -> V_44 ) ;
V_1 -> V_46 = 0 ;
V_1 -> V_53 |= V_78 ;
F_3 ( V_1 , V_58 , 1 , & V_1 -> V_53 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 )
{
F_17 ( & V_1 -> V_44 ) ;
F_41 ( V_1 ) ;
F_11 ( V_1 ) ;
F_12 ( V_1 ) ;
V_1 -> V_46 = 1 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_46 ( struct V_63 * V_64 , T_2 V_87 )
{
return F_44 ( V_64 -> V_84 ) ;
}
static int F_47 ( struct V_63 * V_64 )
{
return F_45 ( V_64 -> V_84 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_88 ;
if ( ! V_1 -> V_3 . V_68 || ! V_1 -> V_3 . V_68 -> V_69 ) {
F_49 (KERN_ERR PFX L_3 ) ;
return - V_45 ;
}
F_17 ( & V_1 -> V_44 ) ;
if ( F_41 ( V_1 ) ) {
F_49 (KERN_ERR PFX L_4 ) ;
F_18 ( & V_1 -> V_44 ) ;
return - V_89 ;
}
V_1 -> V_46 = 1 ;
F_18 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_3 . V_90 -> V_91 ( V_1 -> V_3 . V_90 ,
F_50 () ,
& V_92 , V_1 ) ) {
F_49 (KERN_ERR PFX L_5 ) ;
return - V_82 ;
}
if ( F_51 ( V_93 , V_1 , & V_94 ) ) {
F_49 (KERN_ERR PFX L_6 ) ;
return - V_82 ;
}
V_88 = F_52 ( F_53 ( & V_95 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_96 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_97 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_98 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_99 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_100 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_101 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_102 , V_1 ) ) ;
if ( V_88 )
goto error;
V_88 = F_52 ( F_53 ( & V_103 , V_1 ) ) ;
if ( V_88 )
goto error;
return 0 ;
error:
V_1 -> V_3 . V_90 -> V_104 ( V_1 -> V_3 . V_90 , V_1 ) ;
F_54 ( F_50 () , V_1 ) ;
return V_88 ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_3 . V_90 )
return;
V_1 -> V_3 . V_90 -> V_104 ( V_1 -> V_3 . V_90 , V_1 ) ;
}
static int F_56 ( struct V_105 * V_106 ,
const struct V_107 * V_108 )
{
struct V_109 * V_110 = V_106 -> V_32 . V_111 ;
struct V_1 * V_1 ;
V_1 = F_57 ( sizeof( struct V_1 ) , V_112 ) ;
if ( ! V_1 )
return - V_113 ;
F_58 ( & V_1 -> V_44 ) ;
V_1 -> V_7 = V_106 ;
F_59 ( V_106 , V_1 ) ;
V_1 -> V_10 = V_49 / 2 ;
F_60 ( V_1 -> V_3 . V_114 , L_7 , V_115 ) ;
V_1 -> V_3 . V_116 = V_117 ;
V_1 -> V_3 . V_118 = F_48 ;
V_1 -> V_3 . exit = F_55 ;
V_1 -> V_3 . V_110 = F_61 ( V_110 ) ;
if ( F_62 ( & V_1 -> V_3 ) ) {
goto V_119;
}
F_49 ( V_120
L_8 ,
( unsigned int ) V_106 -> V_121 , V_110 -> V_122 ) ;
return 0 ;
V_119:
F_63 ( & V_1 -> V_44 ) ;
F_64 ( V_1 ) ;
return - V_45 ;
}
static int F_65 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = F_66 ( V_106 ) ;
T_1 V_12 = V_78 ;
F_67 ( & V_1 -> V_3 ) ;
F_68 ( V_1 -> V_3 . V_110 ) ;
F_3 ( V_1 , V_58 , 1 , & V_12 ) ;
F_63 ( & V_1 -> V_44 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
