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
static char * V_50 [] = { L_1 , L_2 } ;
V_36 -> type = V_51 ;
V_36 -> V_38 = 1 ;
V_36 -> V_39 . V_52 . V_53 = 2 ;
if ( V_36 -> V_39 . V_52 . V_54 > 1 )
V_36 -> V_39 . V_52 . V_54 = 1 ;
strcpy ( V_36 -> V_39 . V_52 . V_55 , V_50 [ V_36 -> V_39 . V_52 . V_54 ] ) ;
return 0 ;
}
static int F_31 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . V_52 . V_54 [ 0 ] = ! ! ( V_1 -> V_56 & V_57 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
int V_58 ;
if ( V_43 -> V_39 . V_52 . V_54 [ 0 ] > 1 )
return - V_45 ;
F_17 ( & V_1 -> V_44 ) ;
V_58 = V_1 -> V_56 ;
V_1 -> V_56 &= ~ ( V_57 | V_59 ) ;
if ( V_43 -> V_39 . V_52 . V_54 [ 0 ] )
V_1 -> V_56 |= V_57 | V_59 |
V_60 ;
if ( V_58 == V_1 -> V_56 ) {
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
if ( V_1 -> V_46 )
F_3 ( V_1 , V_61 , 1 , & V_1 -> V_56 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 1 ;
}
static int F_33 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 1 ;
V_36 -> V_39 . integer . V_40 = V_62 ;
V_36 -> V_39 . integer . V_41 = V_63 ;
return 0 ;
}
static int F_34 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_13 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_35 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
if ( V_43 -> V_39 . integer . V_39 [ 0 ] < V_62 ||
V_43 -> V_39 . integer . V_39 [ 0 ] > V_63 )
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
static int F_36 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 1 ;
V_36 -> V_39 . integer . V_40 = V_64 ;
V_36 -> V_39 . integer . V_41 = V_65 ;
return 0 ;
}
static int F_37 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
F_17 ( & V_1 -> V_44 ) ;
V_43 -> V_39 . integer . V_39 [ 0 ] = V_1 -> V_15 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_38 ( struct V_33 * V_34 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_16 ( V_34 ) ;
if ( V_43 -> V_39 . integer . V_39 [ 0 ] < V_64 ||
V_43 -> V_39 . integer . V_39 [ 0 ] > V_65 )
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
static int F_39 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_68 * V_70 )
{
return 1 ;
}
static int F_40 ( struct V_1 * V_1 )
{
T_1 V_12 ;
V_1 -> V_3 . V_71 -> V_72 -> V_73 ( V_1 -> V_3 . V_71 ) ;
F_41 ( 5 ) ;
V_1 -> V_3 . V_71 -> V_72 -> V_74 ( V_1 -> V_3 . V_71 , 0 ) ;
F_41 ( 5 ) ;
V_1 -> V_3 . V_71 -> V_72 -> V_74 ( V_1 -> V_3 . V_71 , 1 ) ;
F_41 ( 20 ) ;
V_1 -> V_3 . V_71 -> V_72 -> V_74 ( V_1 -> V_3 . V_71 , 0 ) ;
F_41 ( 10 ) ;
V_1 -> V_3 . V_71 -> V_72 -> V_75 ( V_1 -> V_3 . V_71 ) ;
V_12 = V_76 | V_77 | V_78 ;
if ( F_3 ( V_1 , V_79 , 1 , & V_12 ) )
goto V_80;
V_1 -> V_56 |= V_81 ;
if ( F_3 ( V_1 , V_61 , 1 , & V_1 -> V_56 ) )
goto V_80;
V_12 = 0 ;
if ( F_3 ( V_1 , V_82 , 1 , & V_12 ) )
goto V_80;
F_6 ( V_1 ) ;
V_1 -> V_13 = V_83 ;
V_1 -> V_15 = V_84 ;
F_7 ( V_1 ) ;
F_9 ( V_1 ) ;
V_1 -> V_56 &= ~ V_81 ;
if ( F_3 ( V_1 , V_61 , 1 , & V_1 -> V_56 ) )
goto V_80;
return 0 ;
V_80:
return - V_85 ;
}
static int F_42 ( struct V_66 * V_67 , enum V_86 clock )
{
struct V_1 * V_1 = V_67 -> V_87 ;
switch( clock ) {
case V_88 :
V_1 -> V_3 . V_71 -> V_72 -> V_73 ( V_1 -> V_3 . V_71 ) ;
V_1 -> V_46 = 0 ;
break;
case V_89 :
F_17 ( & V_1 -> V_44 ) ;
F_40 ( V_1 ) ;
F_11 ( V_1 ) ;
F_12 ( V_1 ) ;
V_1 -> V_46 = 1 ;
V_1 -> V_3 . V_71 -> V_72 -> V_75 ( V_1 -> V_3 . V_71 ) ;
F_18 ( & V_1 -> V_44 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_1 )
{
F_17 ( & V_1 -> V_44 ) ;
V_1 -> V_46 = 0 ;
V_1 -> V_56 |= V_81 ;
F_3 ( V_1 , V_61 , 1 , & V_1 -> V_56 ) ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 )
{
F_17 ( & V_1 -> V_44 ) ;
F_40 ( V_1 ) ;
F_11 ( V_1 ) ;
F_12 ( V_1 ) ;
V_1 -> V_46 = 1 ;
F_18 ( & V_1 -> V_44 ) ;
return 0 ;
}
static int F_45 ( struct V_66 * V_67 , T_2 V_90 )
{
return F_43 ( V_67 -> V_87 ) ;
}
static int F_46 ( struct V_66 * V_67 )
{
return F_44 ( V_67 -> V_87 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_91 ;
if ( ! V_1 -> V_3 . V_71 || ! V_1 -> V_3 . V_71 -> V_72 ) {
F_48 (KERN_ERR PFX L_3 ) ;
return - V_45 ;
}
F_17 ( & V_1 -> V_44 ) ;
if ( F_40 ( V_1 ) ) {
F_48 (KERN_ERR PFX L_4 ) ;
F_18 ( & V_1 -> V_44 ) ;
return - V_92 ;
}
V_1 -> V_46 = 1 ;
F_18 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_3 . V_93 -> V_94 ( V_1 -> V_3 . V_93 ,
F_49 () ,
& V_95 , V_1 ) ) {
F_48 (KERN_ERR PFX L_5 ) ;
return - V_85 ;
}
if ( F_50 ( V_96 , V_1 , & V_97 ) ) {
F_48 (KERN_ERR PFX L_6 ) ;
return - V_85 ;
}
V_91 = F_51 ( F_52 ( & V_98 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_99 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_100 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_101 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_102 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_103 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_104 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_105 , V_1 ) ) ;
if ( V_91 )
goto error;
V_91 = F_51 ( F_52 ( & V_106 , V_1 ) ) ;
if ( V_91 )
goto error;
return 0 ;
error:
V_1 -> V_3 . V_93 -> V_107 ( V_1 -> V_3 . V_93 , V_1 ) ;
F_53 ( F_49 () , V_1 ) ;
return V_91 ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_3 . V_93 )
return;
V_1 -> V_3 . V_93 -> V_107 ( V_1 -> V_3 . V_93 , V_1 ) ;
}
static int F_55 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
struct V_112 * V_113 = V_109 -> V_32 . V_114 ;
struct V_1 * V_1 ;
V_1 = F_56 ( sizeof( struct V_1 ) , V_115 ) ;
if ( ! V_1 )
return - V_116 ;
F_57 ( & V_1 -> V_44 ) ;
V_1 -> V_7 = V_109 ;
F_58 ( V_109 , V_1 ) ;
V_1 -> V_10 = V_49 / 2 ;
F_59 ( V_1 -> V_3 . V_55 , L_7 , V_117 ) ;
V_1 -> V_3 . V_118 = V_119 ;
V_1 -> V_3 . V_120 = F_47 ;
V_1 -> V_3 . exit = F_54 ;
V_1 -> V_3 . V_113 = F_60 ( V_113 ) ;
if ( F_61 ( & V_1 -> V_3 ) ) {
goto V_121;
}
F_48 ( V_122
L_8 ,
( unsigned int ) V_109 -> V_123 , V_113 -> V_124 ) ;
return 0 ;
V_121:
F_62 ( & V_1 -> V_44 ) ;
F_63 ( V_1 ) ;
return - V_45 ;
}
static int F_64 ( struct V_108 * V_109 )
{
struct V_1 * V_1 = F_65 ( V_109 ) ;
T_1 V_12 = V_81 ;
F_66 ( & V_1 -> V_3 ) ;
F_67 ( V_1 -> V_3 . V_113 ) ;
F_3 ( V_1 , V_61 , 1 , & V_12 ) ;
F_62 ( & V_1 -> V_44 ) ;
F_63 ( V_1 ) ;
return 0 ;
}
