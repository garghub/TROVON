static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = V_7 -> V_8 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
T_1 V_12 = V_7 -> V_12 ;
F_2 ( V_2 -> V_13 -> V_14 , L_1 , V_8 ) ;
V_5 = F_3 ( V_2 , 0 , V_9 , V_8 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , V_15 L_2 ) ;
return V_5 ;
}
V_5 = F_5 ( V_2 , V_12 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_3 ,
V_12 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_4 ) ;
V_5 = F_7 ( V_2 , V_7 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_5 ) ;
return V_5 ;
}
F_2 ( V_2 -> V_13 -> V_14 , L_6 ) ;
V_5 = F_8 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_7 ) ;
return V_5 ;
}
F_2 ( V_2 -> V_13 -> V_14 , L_8 ) ;
V_5 = F_9 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_9 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_10 ) ;
V_5 = F_11 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_11 ) ;
return V_5 ;
}
F_2 ( V_2 -> V_13 -> V_14 , L_12 ) ;
V_5 = F_12 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_9 ) ;
return V_5 ;
}
F_2 ( V_2 -> V_13 -> V_14 , L_13 ) ;
V_5 = F_13 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_14 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_15 ) ;
V_5 = F_15 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_16 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_5 = 0 ;
int V_16 ;
F_2 ( V_2 -> V_13 -> V_14 , L_17 ) ;
F_18 ( & V_2 -> V_17 ) ;
V_7 -> V_18 = V_19 ;
#if 0
err = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0) {
dev_warn(chip->card->dev, "could not constrain periods\n");
goto exit;
}
#endif
V_16 = V_2 -> V_20 ;
V_5 = F_19 ( V_7 , V_21 ,
V_16 ) ;
if ( V_5 < 0 ) {
F_20 ( V_2 -> V_13 -> V_14 , L_18 ) ;
goto exit;
}
V_5 = F_21 ( V_7 ,
V_22 ,
V_23 ,
V_24 ) ;
if ( V_5 < 0 ) {
F_20 ( V_2 -> V_13 -> V_14 ,
L_19 ) ;
goto exit;
}
F_22 ( V_7 , 0 ,
V_25 , 32 ) ;
F_23 ( V_4 ) ;
V_5 = 0 ;
exit:
V_7 -> V_26 = V_2 ;
F_24 ( & V_2 -> V_17 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_20 , V_5 ) ;
return V_5 ;
}
static int F_25 ( struct V_3 * V_4 )
{
int V_5 = 0 ;
F_2 ( V_4 -> V_27 -> V_13 -> V_14 , L_21 ) ;
return V_5 ;
}
static T_1 F_26 ( struct V_3
* V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
T_1 V_28 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
struct V_29 * V_29 = V_9 ? & V_2 -> V_30 :
& V_2 -> V_31 ;
F_2 ( V_2 -> V_13 -> V_14 , L_22 ) ;
F_18 ( & V_2 -> V_32 ) ;
V_28 = V_29 -> V_33 * V_4 -> V_7 -> V_12 ;
F_24 ( & V_2 -> V_32 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_23 , V_28 ) ;
return V_28 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
const int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_24 ) ;
F_18 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_34 [ V_9 ] ) {
V_5 = F_10 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_25
L_26 , V_5 ) ;
goto exit;
}
V_5 = F_14 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_27
L_26 , V_5 ) ;
goto exit;
}
}
F_2 ( V_2 -> V_13 -> V_14 , L_28 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_29
L_26 , V_5 ) ;
goto exit;
}
V_5 = F_6 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_30
L_26 , V_5 ) ;
goto exit;
}
V_2 -> V_34 [ V_9 ] = 1 ;
if ( V_2 -> V_20 != V_4 -> V_7 -> V_35 ) {
if ( ! V_5 )
V_2 -> V_20 = V_4 -> V_7 -> V_35 ;
}
exit:
F_24 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_36 * V_37 , int V_9 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
F_2 ( V_2 -> V_13 -> V_14 , L_31 ) ;
F_18 ( & V_2 -> V_17 ) ;
V_5 = F_29 ( V_4 ,
F_30 ( V_37 ) ) ;
if ( V_9 )
V_2 -> V_30 . V_10 = V_4 ;
else
V_2 -> V_31 . V_10 = V_4 ;
F_24 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_31 ( struct V_3 * V_4 ,
struct V_36 * V_37 )
{
return F_28 ( V_4 , V_37 , 0 ) ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_36 * V_37 )
{
return F_28 ( V_4 , V_37 , 1 ) ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_32 ) ;
F_18 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_34 [ V_9 ] ) {
V_5 = F_10 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_25
L_26 , V_5 ) ;
goto exit;
}
V_5 = F_14 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_27
L_26 , V_5 ) ;
goto exit;
}
V_2 -> V_34 [ V_9 ] = 0 ;
}
V_5 = F_34 ( V_4 ) ;
if ( V_9 )
V_2 -> V_30 . V_10 = NULL ;
else
V_2 -> V_31 . V_10 = NULL ;
exit:
F_24 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
struct V_3 * V_4 = V_29 -> V_10 ;
const unsigned int V_9 = V_29 -> V_9 ;
int V_5 ;
const T_2 V_8 = V_4 -> V_7 -> V_8 ;
const T_2 V_38 = V_8 * 3 ;
const T_2 V_12 = V_4 -> V_7 -> V_12 ;
const T_2 V_39 = V_4 -> V_7 -> V_39 ;
const T_2 V_40 = V_12 * V_38 ;
T_3 V_41 = V_4 -> V_42 . V_43 ;
int V_44 ;
T_2 V_45 , V_46 ;
T_2 V_47 [ 5 ] ;
for ( V_44 = 0 ; V_44 != V_39 ; ++ V_44 ) {
T_2 V_48 = 0 ;
V_5 = F_36 ( V_2 , 0 , V_9 , & V_45 , & V_46 ,
V_47 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_33 ,
V_45 , V_46 ) ;
V_5 = F_37 ( V_2 , 0 , V_9 , V_40 ,
F_38 ( V_41 ) , F_39 ( V_41 ) ,
& V_48 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_34 ,
V_48 , ( unsigned long ) V_41 , V_40 ) ;
V_41 += V_40 ;
}
V_5 = F_36 ( V_2 , 0 , V_9 , & V_45 , & V_46 , V_47 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_33 , V_45 , V_46 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_35 ) ;
V_5 = F_40 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_13 -> V_14 , L_36 ) ;
else
V_29 -> V_49 = V_50 ;
V_29 -> V_33 = 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
const unsigned int V_9 = V_29 -> V_9 ;
int V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_37 ) ;
V_5 = F_42 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_13 -> V_14 , L_38 ) ;
else
V_29 -> V_49 = V_51 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_29 * V_29 )
{
switch ( V_29 -> V_49 ) {
case V_52 :
F_35 ( V_2 , V_29 ) ;
break;
case V_53 :
F_41 ( V_2 , V_29 ) ;
break;
default:
break;
}
}
static int F_44 ( struct V_1 * V_2 ,
struct V_29 * V_29 , int V_54 )
{
int V_5 = 0 ;
F_18 ( & V_2 -> V_32 ) ;
switch ( V_54 ) {
case V_55 :
V_29 -> V_49 = V_52 ;
break;
case V_56 :
V_29 -> V_49 = V_53 ;
break;
default:
V_5 = - V_57 ;
goto exit;
}
F_43 ( V_2 , & V_2 -> V_30 ) ;
F_43 ( V_2 , & V_2 -> V_31 ) ;
exit:
F_24 ( & V_2 -> V_32 ) ;
return V_5 ;
}
static int F_45 ( struct V_3 * V_4 , int V_54 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
const int V_9 = ( V_4 -> V_10 == V_11 ) ;
struct V_29 * V_10 = V_9 ? & V_2 -> V_30 :
& V_2 -> V_31 ;
F_2 ( V_2 -> V_13 -> V_14 , L_39 ) ;
return F_44 ( V_2 , V_10 , V_54 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_13 -> V_14 , L_40 ) ;
F_47 ( V_2 ) ;
if ( V_2 -> V_58 >= 0 )
F_48 ( V_2 -> V_58 , V_2 ) ;
F_49 ( V_2 -> V_59 ) ;
F_50 ( V_2 -> V_60 ) ;
F_51 ( V_2 -> V_61 ) ;
F_52 ( V_2 -> V_61 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_62 * V_63 )
{
return F_46 ( V_63 -> V_64 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_44 ;
T_2 V_65 = F_56 ( V_2 , V_66 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_41 ) ;
V_65 &= ~ V_67 ;
F_57 ( V_2 , V_66 , V_65 ) ;
F_58 ( 1 ) ;
F_57 ( V_2 , V_68 , 0 ) ;
F_58 ( 1 ) ;
V_65 |= V_67 ;
F_57 ( V_2 , V_66 , V_65 ) ;
for ( V_44 = 0 ; V_44 != 100 ; ++ V_44 ) {
T_2 V_69 ;
F_58 ( 10 ) ;
V_69 = F_56 ( V_2 , V_68 ) ;
if ( V_69 ) {
F_2 ( V_2 -> V_13 -> V_14 , L_42 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_43 , V_44 ) ;
break;
}
}
F_59 ( V_2 , V_70 , 0 ) ;
F_58 ( 600 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_2 V_71 ;
F_2 ( V_2 -> V_13 -> V_14 , L_44 ) ;
F_59 ( V_2 , V_70 , 0 ) ;
V_71 = F_61 ( V_2 , V_70 ) ;
if ( V_71 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_45 , V_71 ) ;
F_57 ( V_2 , V_72 , 1 ) ;
V_71 = F_61 ( V_2 , V_70 ) ;
if ( V_71 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_46 , V_71 ) ;
return - V_73 ;
}
}
F_2 ( V_2 -> V_13 -> V_14 , L_47 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_44 ;
T_2 V_74 = F_61 ( V_2 , V_75 ) ;
T_2 V_76 = ( V_74 & V_77 ) |
( 64 << V_78 ) |
( 64 << V_79 ) |
( V_80 << V_81 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_48 ) ;
V_2 -> V_82 = V_80 ;
F_59 ( V_2 , V_75 , V_76 ) ;
for ( V_44 = 0 ; V_44 != 1000 ; ++ V_44 ) {
if ( F_61 ( V_2 , V_83 ) & 4 ) {
F_2 ( V_2 -> V_13 -> V_14 , L_49 ,
V_44 ) ;
goto V_84;
}
F_58 ( 1 ) ;
}
F_20 ( V_2 -> V_13 -> V_14 ,
L_50 , V_44 ) ;
return - V_85 ;
V_84:
F_2 ( V_2 -> V_13 -> V_14 , L_51 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_2 V_86 ;
int V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_52 ) ;
V_5 = F_64 ( V_2 , & V_86 ) ;
if ( V_5 == 0 ) {
T_2 V_87 ;
F_65 ( V_2 -> V_13 -> V_14 , L_53 ,
( V_86 >> 16 ) & 0xff , ( V_86 >> 8 ) & 0xff ,
V_86 & 0xff ) ;
V_5 = F_66 ( V_2 , & V_87 ) ;
if ( V_5 == 0 )
V_2 -> V_20 = V_87 ;
F_2 ( V_2 -> V_13 -> V_14 , L_54 , V_87 ) ;
} else {
F_4 ( V_2 -> V_13 -> V_14 , L_55 ) ;
V_5 = - V_73 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_88 )
{
int V_5 = 0 ;
T_2 V_89 = V_23 ;
F_2 ( V_2 -> V_13 -> V_14 , L_56 ) ;
while ( ( V_89 < V_88 ) &&
( V_89 < V_24 ) ) {
V_89 *= 2 ;
}
if ( V_89 == V_2 -> V_90 )
return 0 ;
V_5 = F_67 ( V_2 , V_89 ) ;
if ( V_5 < 0 ) {
F_20 ( V_2 -> V_13 -> V_14 , L_57 ) ;
V_5 = - V_73 ;
}
if ( V_89 != V_88 )
F_4 ( V_2 -> V_13 -> V_14 , L_58 , V_89 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_59 , V_89 ) ;
V_2 -> V_90 = V_89 ;
return V_5 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_5 ;
int V_44 ;
F_2 ( V_2 -> V_13 -> V_14 , L_60 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_61 ) ;
V_5 = F_55 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_62 ) ;
V_5 = F_60 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_63 ) ;
V_5 = F_62 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_69 ( V_2 ) ;
for ( V_44 = 0 ; V_44 != 1000 ; ++ V_44 ) {
V_5 = F_70 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_91 [ 0 ] || V_2 -> V_91 [ 1 ] || V_2 -> V_91 [ 2 ] ||
V_2 -> V_91 [ 3 ] || V_2 -> V_91 [ 4 ] || V_2 -> V_91 [ 5 ] )
goto V_92;
F_58 ( 1 ) ;
}
return - V_85 ;
V_92:
F_2 ( V_2 -> V_13 -> V_14 , L_64 , V_44 ) ;
F_65 ( V_2 -> V_13 -> V_14 ,
L_65 ,
V_2 -> V_91 [ 0 ] , V_2 -> V_91 [ 1 ] , V_2 -> V_91 [ 2 ] ,
V_2 -> V_91 [ 3 ] , V_2 -> V_91 [ 4 ] , V_2 -> V_91 [ 5 ] ) ;
V_5 = F_63 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_5 ( V_2 , V_93 ) ;
V_2 -> V_94 = 0 ;
return V_5 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_95 * V_27 ;
T_2 V_96 = 64 *
3 *
V_97 *
V_24 *
2 ;
V_96 = F_72 ( V_96 ) ;
V_5 = F_73 ( V_2 -> V_13 , ( char * ) V_98 , 0 ,
1 , 1 , & V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
V_27 -> V_26 = V_2 ;
F_74 ( V_27 , V_99 , & V_100 ) ;
F_74 ( V_27 , V_11 , & V_101 ) ;
V_27 -> V_102 = 0 ;
V_27 -> V_103 = true ;
strcpy ( V_27 -> V_104 , V_98 ) ;
V_5 = F_75 ( V_27 , V_105 ,
F_76 ( V_2 -> V_61 ) ,
V_96 , V_96 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_30 . V_9 = 1 ;
return 0 ;
}
static int F_77 ( struct V_106 * V_107 ,
struct V_108 * V_109 )
{
V_109 -> type = V_110 ;
V_109 -> V_111 = 1 ;
V_109 -> V_112 . integer . V_113 = 0 ;
V_109 -> V_112 . integer . V_114 = 1 ;
return 0 ;
}
static int F_78 ( struct V_106 * V_107 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_79 ( V_107 ) ;
V_116 -> V_112 . integer . V_112 [ 0 ] = V_2 -> V_94 ;
return 0 ;
}
static int F_80 ( struct V_106 * V_107 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_79 ( V_107 ) ;
int V_117 = 0 ;
int V_118 = V_2 -> V_94 ;
if ( V_118 != V_116 -> V_112 . integer . V_112 [ 0 ] ) {
F_81 ( V_2 , 0 , ! V_118 ) ;
V_2 -> V_94 = ! V_118 ;
V_117 = 1 ;
}
return V_117 ;
}
static void F_82 ( struct V_119 * V_120 ,
struct V_121 * V_122 )
{
T_2 V_123 [ 64 ] ;
int V_5 ;
int V_44 , V_124 ;
struct V_1 * V_2 = V_120 -> V_26 ;
F_83 ( V_122 , L_66 ) ;
V_5 = F_84 ( V_2 , 1 , 64 , V_123 ) ;
if ( V_5 < 0 )
return;
for ( V_44 = 0 ; V_44 != 8 ; ++ V_44 ) {
for ( V_124 = 0 ; V_124 != 8 ; ++ V_124 )
F_83 ( V_122 , L_67 , V_123 [ V_44 * 8 + V_124 ] ) ;
F_83 ( V_122 , L_68 ) ;
}
F_83 ( V_122 , L_69 ) ;
V_5 = F_84 ( V_2 , 0 , 64 , V_123 ) ;
if ( V_5 < 0 )
return;
for ( V_44 = 0 ; V_44 != 8 ; ++ V_44 ) {
for ( V_124 = 0 ; V_124 != 8 ; ++ V_124 )
F_83 ( V_122 , L_67 , V_123 [ V_44 * 8 + V_124 ] ) ;
F_83 ( V_122 , L_68 ) ;
}
F_83 ( V_122 , L_68 ) ;
}
static int F_85 ( struct V_125 * V_13 , struct V_1 * V_2 )
{
struct V_119 * V_120 ;
int V_5 = F_86 ( V_13 , L_70 , & V_120 ) ;
if ( V_5 < 0 )
return V_5 ;
F_87 ( V_120 , V_2 , F_82 ) ;
return 0 ;
}
static int F_88 ( struct V_125 * V_13 ,
struct V_126 * V_61 ,
struct V_1 * * V_127 )
{
struct V_1 * V_2 ;
int V_5 ;
static struct V_128 V_129 = {
. V_130 = F_54 ,
} ;
F_2 ( V_13 -> V_14 , L_71 ) ;
* V_127 = NULL ;
V_5 = F_89 ( V_61 ) ;
if ( V_5 < 0 )
return V_5 ;
F_90 ( V_61 ) ;
V_5 = F_91 ( & V_61 -> V_14 , F_92 ( 32 ) ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 -> V_14 ,
L_72 ) ;
F_52 ( V_61 ) ;
return - V_131 ;
}
V_2 = F_93 ( sizeof( * V_2 ) , V_132 ) ;
if ( V_2 == NULL ) {
V_5 = - V_133 ;
goto V_134;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_61 = V_61 ;
V_2 -> V_58 = - 1 ;
F_94 ( & V_2 -> V_32 ) ;
F_94 ( & V_2 -> V_135 ) ;
F_94 ( & V_2 -> V_17 ) ;
V_5 = F_95 ( V_61 , V_98 ) ;
if ( V_5 < 0 )
goto V_136;
V_2 -> V_137 = F_96 ( V_61 , 1 ) ;
V_2 -> V_60 = F_97 ( V_2 -> V_137 ,
F_98 ( V_61 , 1 ) ) ;
V_2 -> V_59 = F_99 ( V_61 , 2 ) ;
V_5 = F_100 ( V_61 -> V_58 , V_138 , V_139 ,
V_140 , V_141 , V_2 ) ;
if ( V_5 ) {
F_4 ( V_13 -> V_14 , L_73 , V_61 -> V_58 ) ;
goto V_142;
}
V_2 -> V_58 = V_61 -> V_58 ;
V_5 = F_101 ( V_13 , V_143 , V_2 , & V_129 ) ;
if ( V_5 < 0 )
goto V_144;
V_5 = F_68 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 -> V_14 , L_74 ) ;
return V_5 ;
}
V_5 = F_71 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_85 ( V_13 , V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_102 ( V_13 , F_103 ( & V_145 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
* V_127 = V_2 ;
return 0 ;
V_144:
F_48 ( V_61 -> V_58 , V_2 ) ;
V_142:
F_51 ( V_61 ) ;
V_136:
F_53 ( V_2 ) ;
V_134:
F_52 ( V_61 ) ;
return V_5 ;
}
static int F_104 ( struct V_126 * V_61 ,
const struct V_146 * V_147 )
{
static int V_14 ;
struct V_125 * V_13 ;
struct V_1 * V_2 ;
int V_5 ;
F_2 ( & V_61 -> V_14 , L_75 ) ;
if ( V_14 >= V_148 )
return - V_149 ;
if ( ! V_150 [ V_14 ] ) {
V_14 ++ ;
return - V_151 ;
}
V_5 = F_105 ( & V_61 -> V_14 , V_152 [ V_14 ] , V_153 [ V_14 ] , V_154 ,
0 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_88 ( V_13 , V_61 , & V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 -> V_14 , L_76 ) ;
goto V_155;
}
strcpy ( V_13 -> V_156 , L_77 ) ;
sprintf ( V_13 -> V_153 , L_78 ,
V_2 -> V_91 [ 3 ] , V_2 -> V_91 [ 4 ] , V_2 -> V_91 [ 5 ] ) ;
sprintf ( V_13 -> V_157 , L_79 ,
V_2 -> V_91 [ 0 ] , V_2 -> V_91 [ 1 ] , V_2 -> V_91 [ 2 ] ,
V_2 -> V_91 [ 3 ] , V_2 -> V_91 [ 4 ] , V_2 -> V_91 [ 5 ] ) ;
sprintf ( V_13 -> V_158 , L_80 ,
V_13 -> V_157 , V_2 -> V_137 ,
V_2 -> V_59 , V_2 -> V_58 ) ;
V_5 = F_106 ( V_13 ) ;
if ( V_5 < 0 )
goto V_155;
F_2 ( V_2 -> V_13 -> V_14 , L_81 ) ;
F_107 ( V_61 , V_13 ) ;
V_14 ++ ;
return 0 ;
V_155:
F_108 ( V_13 ) ;
return V_5 ;
}
static void F_109 ( struct V_126 * V_61 )
{
F_108 ( F_110 ( V_61 ) ) ;
}
