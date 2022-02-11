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
V_16 , V_16 ) ;
if ( V_5 < 0 ) {
F_20 ( V_2 -> V_13 -> V_14 , L_18 ) ;
goto exit;
}
V_5 = F_19 ( V_7 ,
V_22 ,
V_23 ,
V_24 ) ;
if ( V_5 < 0 ) {
F_20 ( V_2 -> V_13 -> V_14 ,
L_19 ) ;
goto exit;
}
F_21 ( V_7 , 0 ,
V_25 , 32 ) ;
F_22 ( V_4 ) ;
V_5 = 0 ;
exit:
V_7 -> V_26 = V_2 ;
F_23 ( & V_2 -> V_17 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_20 , V_5 ) ;
return V_5 ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_5 = 0 ;
F_2 ( V_4 -> V_27 -> V_13 -> V_14 , L_21 ) ;
return V_5 ;
}
static T_1 F_25 ( struct V_3
* V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
T_1 V_28 ;
unsigned long V_29 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
struct V_30 * V_30 = V_9 ? & V_2 -> V_31 :
& V_2 -> V_32 ;
F_2 ( V_2 -> V_13 -> V_14 , L_22 ) ;
F_26 ( & V_2 -> V_33 , V_29 ) ;
V_28 = V_30 -> V_34 * V_4 -> V_7 -> V_12 ;
F_27 ( & V_2 -> V_33 , V_29 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_23 , V_28 ) ;
return V_28 ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
const int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_24 ) ;
F_18 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_35 [ V_9 ] ) {
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
V_2 -> V_35 [ V_9 ] = 1 ;
if ( V_2 -> V_20 != V_4 -> V_7 -> V_36 ) {
if ( ! V_5 )
V_2 -> V_20 = V_4 -> V_7 -> V_36 ;
}
exit:
F_23 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_29 ( struct V_3 * V_4 ,
struct V_37 * V_38 , int V_9 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
F_2 ( V_2 -> V_13 -> V_14 , L_31 ) ;
F_18 ( & V_2 -> V_17 ) ;
V_5 = F_30 ( V_4 ,
F_31 ( V_38 ) ) ;
if ( V_9 )
V_2 -> V_31 . V_10 = V_4 ;
else
V_2 -> V_32 . V_10 = V_4 ;
F_23 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_37 * V_38 )
{
return F_29 ( V_4 , V_38 , 0 ) ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_37 * V_38 )
{
return F_29 ( V_4 , V_38 , 1 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_32 ) ;
F_18 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_35 [ V_9 ] ) {
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
V_2 -> V_35 [ V_9 ] = 0 ;
}
V_5 = F_35 ( V_4 ) ;
if ( V_9 )
V_2 -> V_31 . V_10 = 0 ;
else
V_2 -> V_32 . V_10 = 0 ;
exit:
F_23 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_30 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_10 ;
const unsigned int V_9 = V_30 -> V_9 ;
int V_5 ;
const T_2 V_8 = V_4 -> V_7 -> V_8 ;
const T_2 V_39 = V_8 * 3 ;
const T_2 V_12 = V_4 -> V_7 -> V_12 ;
const T_2 V_40 = V_4 -> V_7 -> V_40 ;
const T_2 V_41 = V_12 * V_39 ;
T_3 V_42 = V_4 -> V_43 . V_44 ;
int V_45 ;
T_2 V_46 , V_47 ;
T_2 V_48 [ 5 ] ;
for ( V_45 = 0 ; V_45 != V_40 ; ++ V_45 ) {
T_2 V_49 = 0 ;
V_5 = F_37 ( V_2 , 0 , V_9 , & V_46 , & V_47 ,
V_48 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_33 ,
V_46 , V_47 ) ;
V_5 = F_38 ( V_2 , 0 , V_9 , V_41 ,
F_39 ( V_42 ) , F_40 ( V_42 ) ,
& V_49 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_34 ,
V_49 , ( unsigned long ) V_42 , V_41 ) ;
V_42 += V_41 ;
}
V_5 = F_37 ( V_2 , 0 , V_9 , & V_46 , & V_47 , V_48 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_33 , V_46 , V_47 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_35 ) ;
V_5 = F_41 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_13 -> V_14 , L_36 ) ;
else
V_30 -> V_50 = V_51 ;
V_30 -> V_34 = 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_30 * V_30 )
{
const unsigned int V_9 = V_30 -> V_9 ;
int V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_37 ) ;
V_5 = F_43 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_13 -> V_14 , L_38 ) ;
else
V_30 -> V_50 = V_52 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_30 * V_30 )
{
switch ( V_30 -> V_50 ) {
case V_53 :
F_36 ( V_2 , V_30 ) ;
break;
case V_54 :
F_42 ( V_2 , V_30 ) ;
break;
default:
break;
}
}
static void F_45 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
unsigned long V_29 ;
F_2 ( V_2 -> V_13 -> V_14 , L_39 ) ;
F_26 ( & V_2 -> V_33 , V_29 ) ;
F_44 ( V_2 , & V_2 -> V_31 ) ;
F_44 ( V_2 , & V_2 -> V_32 ) ;
F_27 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_30 * V_30 , int V_56 )
{
int V_5 = 0 ;
switch ( V_56 ) {
case V_57 :
V_30 -> V_50 = V_53 ;
break;
case V_58 :
V_30 -> V_50 = V_54 ;
break;
default:
V_5 = - V_59 ;
goto exit;
}
F_47 ( & V_2 -> V_60 ) ;
exit:
return V_5 ;
}
static int F_48 ( struct V_3 * V_4 , int V_56 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
const int V_9 = ( V_4 -> V_10 == V_11 ) ;
struct V_30 * V_10 = V_9 ? & V_2 -> V_31 :
& V_2 -> V_32 ;
F_2 ( V_2 -> V_13 -> V_14 , L_40 ) ;
return F_46 ( V_2 , V_10 , V_56 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_13 -> V_14 , L_41 ) ;
F_50 ( V_2 ) ;
if ( V_2 -> V_61 >= 0 )
F_51 ( V_2 -> V_61 , V_2 ) ;
F_52 ( V_2 -> V_62 ) ;
F_53 ( V_2 -> V_63 ) ;
F_54 ( V_2 -> V_64 ) ;
F_55 ( V_2 -> V_64 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_65 * V_66 )
{
return F_49 ( V_66 -> V_67 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_45 ;
T_2 V_68 = F_59 ( V_2 , V_69 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_42 ) ;
V_68 &= ~ V_70 ;
F_60 ( V_2 , V_69 , V_68 ) ;
F_61 ( 1 ) ;
F_60 ( V_2 , V_71 , 0 ) ;
F_61 ( 1 ) ;
V_68 |= V_70 ;
F_60 ( V_2 , V_69 , V_68 ) ;
for ( V_45 = 0 ; V_45 != 100 ; ++ V_45 ) {
T_2 V_72 ;
F_61 ( 10 ) ;
V_72 = F_59 ( V_2 , V_71 ) ;
if ( V_72 ) {
F_2 ( V_2 -> V_13 -> V_14 , L_43 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_44 , V_45 ) ;
break;
}
}
F_62 ( V_2 , V_73 , 0 ) ;
F_61 ( 600 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_2 V_74 ;
F_2 ( V_2 -> V_13 -> V_14 , L_45 ) ;
F_62 ( V_2 , V_73 , 0 ) ;
V_74 = F_64 ( V_2 , V_73 ) ;
if ( V_74 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_46 , V_74 ) ;
F_60 ( V_2 , V_75 , 1 ) ;
V_74 = F_64 ( V_2 , V_73 ) ;
if ( V_74 ) {
F_4 ( V_2 -> V_13 -> V_14 , L_47 , V_74 ) ;
return - V_76 ;
}
}
F_2 ( V_2 -> V_13 -> V_14 , L_48 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_45 ;
T_2 V_77 = F_64 ( V_2 , V_78 ) ;
T_2 V_79 = ( V_77 & V_80 ) |
( 64 << V_81 ) |
( 64 << V_82 ) |
( V_83 << V_84 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_49 ) ;
V_2 -> V_85 = V_83 ;
F_62 ( V_2 , V_78 , V_79 ) ;
for ( V_45 = 0 ; V_45 != 1000 ; ++ V_45 ) {
if ( F_64 ( V_2 , V_86 ) & 4 ) {
F_2 ( V_2 -> V_13 -> V_14 , L_50 ,
V_45 ) ;
goto V_87;
}
F_61 ( 1 ) ;
}
F_20 ( V_2 -> V_13 -> V_14 ,
L_51 , V_45 ) ;
return - V_88 ;
V_87:
F_2 ( V_2 -> V_13 -> V_14 , L_52 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
T_2 V_89 ;
int V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_53 ) ;
V_5 = F_67 ( V_2 , & V_89 ) ;
if ( V_5 == 0 ) {
T_2 V_90 ;
F_68 ( V_2 -> V_13 -> V_14 , L_54 ,
( V_89 >> 16 ) & 0xff , ( V_89 >> 8 ) & 0xff ,
V_89 & 0xff ) ;
V_5 = F_69 ( V_2 , & V_90 ) ;
if ( V_5 == 0 )
V_2 -> V_20 = V_90 ;
F_2 ( V_2 -> V_13 -> V_14 , L_55 , V_90 ) ;
} else {
F_4 ( V_2 -> V_13 -> V_14 , L_56 ) ;
V_5 = - V_76 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_91 )
{
int V_5 = 0 ;
T_2 V_92 = V_23 ;
F_2 ( V_2 -> V_13 -> V_14 , L_57 ) ;
while ( ( V_92 < V_91 ) &&
( V_92 < V_24 ) ) {
V_92 *= 2 ;
}
if ( V_92 == V_2 -> V_93 )
return 0 ;
V_5 = F_70 ( V_2 , V_92 ) ;
if ( V_5 < 0 ) {
F_20 ( V_2 -> V_13 -> V_14 , L_58 ) ;
V_5 = - V_76 ;
}
if ( V_92 != V_91 )
F_4 ( V_2 -> V_13 -> V_14 , L_59 , V_92 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_60 , V_92 ) ;
V_2 -> V_93 = V_92 ;
return V_5 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_5 ;
int V_45 ;
F_2 ( V_2 -> V_13 -> V_14 , L_61 ) ;
F_2 ( V_2 -> V_13 -> V_14 , L_62 ) ;
V_5 = F_58 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_63 ) ;
V_5 = F_63 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_2 ( V_2 -> V_13 -> V_14 , L_64 ) ;
V_5 = F_65 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_72 ( V_2 ) ;
for ( V_45 = 0 ; V_45 != 1000 ; ++ V_45 ) {
V_5 = F_73 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_94 [ 0 ] || V_2 -> V_94 [ 1 ] || V_2 -> V_94 [ 2 ] ||
V_2 -> V_94 [ 3 ] || V_2 -> V_94 [ 4 ] || V_2 -> V_94 [ 5 ] )
goto V_95;
F_61 ( 1 ) ;
}
return - V_88 ;
V_95:
F_2 ( V_2 -> V_13 -> V_14 , L_65 , V_45 ) ;
F_68 ( V_2 -> V_13 -> V_14 ,
L_66 ,
V_2 -> V_94 [ 0 ] , V_2 -> V_94 [ 1 ] , V_2 -> V_94 [ 2 ] ,
V_2 -> V_94 [ 3 ] , V_2 -> V_94 [ 4 ] , V_2 -> V_94 [ 5 ] ) ;
V_5 = F_66 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_5 ( V_2 , V_96 ) ;
V_2 -> V_97 = 0 ;
return V_5 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_98 * V_27 ;
T_2 V_99 = 64 *
3 *
V_100 *
V_24 *
2 ;
V_99 = F_75 ( V_99 ) ;
V_5 = F_76 ( V_2 -> V_13 , ( char * ) V_101 , 0 ,
1 , 1 , & V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
V_27 -> V_26 = V_2 ;
F_77 ( V_27 , V_102 , & V_103 ) ;
F_77 ( V_27 , V_11 , & V_104 ) ;
V_27 -> V_105 = 0 ;
strcpy ( V_27 -> V_106 , V_101 ) ;
V_5 = F_78 ( V_27 , V_107 ,
F_79 ( V_2 -> V_64 ) ,
V_99 , V_99 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_31 . V_9 = 1 ;
return 0 ;
}
static int F_80 ( struct V_108 * V_109 ,
struct V_110 * V_111 )
{
V_111 -> type = V_112 ;
V_111 -> V_113 = 1 ;
V_111 -> V_114 . integer . V_115 = 0 ;
V_111 -> V_114 . integer . V_116 = 1 ;
return 0 ;
}
static int F_81 ( struct V_108 * V_109 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_82 ( V_109 ) ;
V_118 -> V_114 . integer . V_114 [ 0 ] = V_2 -> V_97 ;
return 0 ;
}
static int F_83 ( struct V_108 * V_109 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_82 ( V_109 ) ;
int V_119 = 0 ;
int V_120 = V_2 -> V_97 ;
if ( V_120 != V_118 -> V_114 . integer . V_114 [ 0 ] ) {
F_84 ( V_2 , 0 , ! V_120 ) ;
V_2 -> V_97 = ! V_120 ;
V_119 = 1 ;
}
return V_119 ;
}
static void F_85 ( struct V_121 * V_122 ,
struct V_123 * V_124 )
{
T_2 V_125 [ 64 ] ;
int V_5 ;
int V_45 , V_126 ;
struct V_1 * V_2 = V_122 -> V_26 ;
F_86 ( V_124 , L_67 ) ;
V_5 = F_87 ( V_2 , 1 , 64 , V_125 ) ;
if ( V_5 < 0 )
return;
for ( V_45 = 0 ; V_45 != 8 ; ++ V_45 ) {
for ( V_126 = 0 ; V_126 != 8 ; ++ V_126 )
F_86 ( V_124 , L_68 , V_125 [ V_45 * 8 + V_126 ] ) ;
F_86 ( V_124 , L_69 ) ;
}
F_86 ( V_124 , L_70 ) ;
V_5 = F_87 ( V_2 , 0 , 64 , V_125 ) ;
if ( V_5 < 0 )
return;
for ( V_45 = 0 ; V_45 != 8 ; ++ V_45 ) {
for ( V_126 = 0 ; V_126 != 8 ; ++ V_126 )
F_86 ( V_124 , L_68 , V_125 [ V_45 * 8 + V_126 ] ) ;
F_86 ( V_124 , L_69 ) ;
}
F_86 ( V_124 , L_69 ) ;
}
static int F_88 ( struct V_127 * V_13 , struct V_1 * V_2 )
{
struct V_121 * V_122 ;
int V_5 = F_89 ( V_13 , L_71 , & V_122 ) ;
if ( V_5 < 0 )
return V_5 ;
F_90 ( V_122 , V_2 , F_85 ) ;
return 0 ;
}
static int F_91 ( struct V_127 * V_13 ,
struct V_128 * V_64 ,
struct V_1 * * V_129 )
{
struct V_1 * V_2 ;
int V_5 ;
static struct V_130 V_131 = {
. V_132 = F_57 ,
} ;
F_2 ( V_13 -> V_14 , L_72 ) ;
* V_129 = NULL ;
V_5 = F_92 ( V_64 ) ;
if ( V_5 < 0 )
return V_5 ;
F_93 ( V_64 ) ;
V_5 = F_94 ( V_64 , F_95 ( 32 ) ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 -> V_14 ,
L_73 ) ;
F_55 ( V_64 ) ;
return - V_133 ;
}
V_2 = F_96 ( sizeof( * V_2 ) , V_134 ) ;
if ( V_2 == NULL ) {
V_5 = - V_135 ;
goto V_136;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_61 = - 1 ;
F_97 ( & V_2 -> V_33 ) ;
F_97 ( & V_2 -> V_137 ) ;
F_98 ( & V_2 -> V_17 ) ;
F_99 ( & V_2 -> V_60 , F_45 ,
( unsigned long ) V_2 ) ;
F_99 ( & V_2 -> V_138 , V_139 ,
( unsigned long ) V_2 ) ;
F_99 ( & V_2 -> V_140 , V_141 ,
( unsigned long ) V_2 ) ;
V_5 = F_100 ( V_64 , V_101 ) ;
if ( V_5 < 0 )
goto V_142;
V_2 -> V_143 = F_101 ( V_64 , 1 ) ;
V_2 -> V_63 = F_102 ( V_2 -> V_143 ,
F_103 ( V_64 , 1 ) ) ;
V_2 -> V_62 = F_104 ( V_64 , 2 ) ;
V_5 = F_105 ( V_64 -> V_61 , V_144 , V_145 ,
V_146 , V_2 ) ;
if ( V_5 ) {
F_4 ( V_13 -> V_14 , L_74 , V_64 -> V_61 ) ;
goto V_147;
}
V_2 -> V_61 = V_64 -> V_61 ;
V_5 = F_106 ( V_13 , V_148 , V_2 , & V_131 ) ;
if ( V_5 < 0 )
goto V_149;
V_5 = F_71 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 -> V_14 , L_75 ) ;
return V_5 ;
}
V_5 = F_74 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_88 ( V_13 , V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_107 ( V_13 , F_108 ( & V_150 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
* V_129 = V_2 ;
return 0 ;
V_149:
F_51 ( V_64 -> V_61 , V_2 ) ;
V_147:
F_54 ( V_64 ) ;
V_142:
F_56 ( V_2 ) ;
V_136:
F_55 ( V_64 ) ;
return V_5 ;
}
static int F_109 ( struct V_128 * V_64 ,
const struct V_151 * V_152 )
{
static int V_14 ;
struct V_127 * V_13 ;
struct V_1 * V_2 ;
int V_5 ;
F_2 ( & V_64 -> V_14 , L_76 ) ;
if ( V_14 >= V_153 )
return - V_154 ;
if ( ! V_155 [ V_14 ] ) {
V_14 ++ ;
return - V_156 ;
}
V_5 = F_110 ( & V_64 -> V_14 , V_157 [ V_14 ] , V_158 [ V_14 ] , V_159 ,
0 , & V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_91 ( V_13 , V_64 , & V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 -> V_14 , L_77 ) ;
goto V_160;
}
strcpy ( V_13 -> V_161 , L_78 ) ;
sprintf ( V_13 -> V_158 , L_79 ,
V_2 -> V_94 [ 3 ] , V_2 -> V_94 [ 4 ] , V_2 -> V_94 [ 5 ] ) ;
sprintf ( V_13 -> V_162 , L_80 ,
V_2 -> V_94 [ 0 ] , V_2 -> V_94 [ 1 ] , V_2 -> V_94 [ 2 ] ,
V_2 -> V_94 [ 3 ] , V_2 -> V_94 [ 4 ] , V_2 -> V_94 [ 5 ] ) ;
sprintf ( V_13 -> V_163 , L_81 ,
V_13 -> V_162 , V_2 -> V_143 ,
V_2 -> V_62 , V_2 -> V_61 ) ;
V_5 = F_111 ( V_13 ) ;
if ( V_5 < 0 )
goto V_160;
F_2 ( V_2 -> V_13 -> V_14 , L_82 ) ;
F_112 ( V_64 , V_13 ) ;
V_14 ++ ;
return 0 ;
V_160:
F_113 ( V_13 ) ;
return V_5 ;
}
static void F_114 ( struct V_128 * V_64 )
{
F_113 ( F_115 ( V_64 ) ) ;
}
