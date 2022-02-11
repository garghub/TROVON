static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = V_7 -> V_8 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
T_1 V_12 = V_7 -> V_12 ;
F_2 ( V_13 L_1 , V_8 ) ;
V_5 = F_3 ( V_2 , 0 , V_9 , V_8 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_2 ) ;
return V_5 ;
}
V_5 = F_5 ( V_2 , V_12 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_3 ,
period_size) ;
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
F_2 ( V_13 L_4 ) ;
V_5 = F_7 ( V_2 , V_7 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_5 ) ;
return V_5 ;
}
F_2 ( V_13 L_6 ) ;
V_5 = F_8 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_7 ) ;
return V_5 ;
}
F_2 ( V_13 L_8 ) ;
V_5 = F_9 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_9 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_13 L_10 ) ;
V_5 = F_11 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_11 ) ;
return V_5 ;
}
F_2 ( V_13 L_12 ) ;
V_5 = F_12 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_9 ) ;
return V_5 ;
}
F_2 ( V_13 L_13 ) ;
V_5 = F_13 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 L_14 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_2 ( V_13 L_15 ) ;
V_5 = F_15 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_13 L_16 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_5 = 0 ;
int V_14 ;
F_18 ( L_17 ) ;
F_19 ( & V_2 -> V_15 ) ;
V_7 -> V_16 = V_17 ;
#if 0
err = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0) {
snd_printk(KERN_WARNING LXP "could not constrain periods\n");
goto exit;
}
#endif
V_14 = V_2 -> V_18 ;
V_5 = F_20 ( V_7 , V_19 ,
V_14 , V_14 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_WARNING LXP L_18 ) ;
goto exit;
}
V_5 = F_20 ( V_7 ,
V_20 ,
V_21 ,
V_22 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_WARNING LXP
L_19 ) ;
goto exit;
}
F_21 ( V_7 , 0 ,
V_23 , 32 ) ;
F_22 ( V_4 ) ;
V_5 = 0 ;
exit:
V_7 -> V_24 = V_2 ;
F_23 ( & V_2 -> V_15 ) ;
F_18 ( L_20 , V_5 ) ;
return V_5 ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_5 = 0 ;
F_18 ( L_21 ) ;
return V_5 ;
}
static T_1 F_25 ( struct V_3
* V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
T_1 V_25 ;
unsigned long V_26 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
struct V_27 * V_27 = V_9 ? & V_2 -> V_28 :
& V_2 -> V_29 ;
F_18 ( L_22 ) ;
F_26 ( & V_2 -> V_30 , V_26 ) ;
V_25 = V_27 -> V_31 * V_4 -> V_7 -> V_12 ;
F_27 ( & V_2 -> V_30 , V_26 ) ;
F_18 ( V_13 L_23 , V_25 ) ;
return V_25 ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
const int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_18 ( L_24 ) ;
F_19 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_32 [ V_9 ] ) {
V_5 = F_10 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_25
L_26 , err) ;
goto exit;
}
V_5 = F_14 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_27
L_26 , err) ;
goto exit;
}
}
F_2 ( V_13 L_28 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_29
L_26 , err) ;
goto exit;
}
V_5 = F_6 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_30
L_26 , err) ;
goto exit;
}
V_2 -> V_32 [ V_9 ] = 1 ;
if ( V_2 -> V_18 != V_4 -> V_7 -> V_33 ) {
if ( ! V_5 )
V_2 -> V_18 = V_4 -> V_7 -> V_33 ;
}
exit:
F_23 ( & V_2 -> V_15 ) ;
return V_5 ;
}
static int F_29 ( struct V_3 * V_4 ,
struct V_34 * V_35 , int V_9 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
F_18 ( L_31 ) ;
F_19 ( & V_2 -> V_15 ) ;
V_5 = F_30 ( V_4 ,
F_31 ( V_35 ) ) ;
if ( V_9 )
V_2 -> V_28 . V_10 = V_4 ;
else
V_2 -> V_29 . V_10 = V_4 ;
F_23 ( & V_2 -> V_15 ) ;
return V_5 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_34 * V_35 )
{
return F_29 ( V_4 , V_35 , 0 ) ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_34 * V_35 )
{
return F_29 ( V_4 , V_35 , 1 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
int V_5 = 0 ;
int V_9 = ( V_4 -> V_10 == V_11 ) ;
F_18 ( L_32 ) ;
F_19 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_32 [ V_9 ] ) {
V_5 = F_10 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_25
L_26 , err) ;
goto exit;
}
V_5 = F_14 ( V_2 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_27
L_26 , err) ;
goto exit;
}
V_2 -> V_32 [ V_9 ] = 0 ;
}
V_5 = F_35 ( V_4 ) ;
if ( V_9 )
V_2 -> V_28 . V_10 = 0 ;
else
V_2 -> V_29 . V_10 = 0 ;
exit:
F_23 ( & V_2 -> V_15 ) ;
return V_5 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_27 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_10 ;
const unsigned int V_9 = V_27 -> V_9 ;
int V_5 ;
const T_2 V_8 = V_4 -> V_7 -> V_8 ;
const T_2 V_36 = V_8 * 3 ;
const T_2 V_12 = V_4 -> V_7 -> V_12 ;
const T_2 V_37 = V_4 -> V_7 -> V_37 ;
const T_2 V_38 = V_12 * V_36 ;
T_3 V_39 = V_4 -> V_40 . V_41 ;
int V_42 ;
T_2 V_43 , V_44 ;
T_2 V_45 [ 5 ] ;
for ( V_42 = 0 ; V_42 != V_37 ; ++ V_42 ) {
T_2 V_46 = 0 ;
V_5 = F_37 ( V_2 , 0 , V_9 , & V_43 , & V_44 ,
V_45 ) ;
F_18 ( V_13 L_33 ,
V_43 , V_44 ) ;
V_5 = F_38 ( V_2 , 0 , V_9 , V_38 ,
F_39 ( V_39 ) , F_40 ( V_39 ) ,
& V_46 ) ;
F_18 ( V_13 L_34 ,
V_46 , ( void * ) V_39 , V_38 ) ;
V_39 += V_38 ;
}
V_5 = F_37 ( V_2 , 0 , V_9 , & V_43 , & V_44 , V_45 ) ;
F_18 ( V_13 L_33 , V_43 , V_44 ) ;
F_2 ( V_13 L_35 ) ;
V_5 = F_41 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 )
F_4 (KERN_ERR LXP L_36 ) ;
else
V_27 -> V_47 = V_48 ;
V_27 -> V_31 = 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_27 * V_27 )
{
const unsigned int V_9 = V_27 -> V_9 ;
int V_5 ;
F_2 ( V_13 L_37 ) ;
V_5 = F_43 ( V_2 , 0 , V_9 ) ;
if ( V_5 < 0 )
F_4 (KERN_ERR LXP L_38 ) ;
else
V_27 -> V_47 = V_49 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_27 * V_27 )
{
switch ( V_27 -> V_47 ) {
case V_50 :
F_36 ( V_2 , V_27 ) ;
break;
case V_51 :
F_42 ( V_2 , V_27 ) ;
break;
default:
break;
}
}
static void F_45 ( unsigned long V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
unsigned long V_26 ;
F_18 ( L_39 ) ;
F_26 ( & V_2 -> V_30 , V_26 ) ;
F_44 ( V_2 , & V_2 -> V_28 ) ;
F_44 ( V_2 , & V_2 -> V_29 ) ;
F_27 ( & V_2 -> V_30 , V_26 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_27 * V_27 , int V_53 )
{
int V_5 = 0 ;
switch ( V_53 ) {
case V_54 :
V_27 -> V_47 = V_50 ;
break;
case V_55 :
V_27 -> V_47 = V_51 ;
break;
default:
V_5 = - V_56 ;
goto exit;
}
F_47 ( & V_2 -> V_57 ) ;
exit:
return V_5 ;
}
static int F_48 ( struct V_3 * V_4 , int V_53 )
{
struct V_1 * V_2 = F_17 ( V_4 ) ;
const int V_9 = ( V_4 -> V_10 == V_11 ) ;
struct V_27 * V_10 = V_9 ? & V_2 -> V_28 :
& V_2 -> V_29 ;
F_18 ( L_40 ) ;
return F_46 ( V_2 , V_10 , V_53 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_18 ( L_41 ) ;
F_50 ( V_2 ) ;
if ( V_2 -> V_58 >= 0 )
F_51 ( V_2 -> V_58 , V_2 ) ;
F_52 ( V_2 -> V_59 ) ;
F_53 ( V_2 -> V_60 ) ;
F_54 ( V_2 -> V_61 ) ;
F_55 ( V_2 -> V_61 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_62 * V_63 )
{
return F_49 ( V_63 -> V_64 ) ;
}
static int T_4 F_58 ( struct V_1 * V_2 )
{
int V_42 ;
T_2 V_65 = F_59 ( V_2 , V_66 ) ;
F_18 ( L_42 ) ;
V_65 &= ~ V_67 ;
F_60 ( V_2 , V_66 , V_65 ) ;
F_61 ( 1 ) ;
F_60 ( V_2 , V_68 , 0 ) ;
F_61 ( 1 ) ;
V_65 |= V_67 ;
F_60 ( V_2 , V_66 , V_65 ) ;
for ( V_42 = 0 ; V_42 != 100 ; ++ V_42 ) {
T_2 V_69 ;
F_61 ( 10 ) ;
V_69 = F_59 ( V_2 , V_68 ) ;
if ( V_69 ) {
F_2 ( V_13 L_43 ) ;
F_18 ( V_13 L_44 , V_42 ) ;
break;
}
}
F_62 ( V_2 , V_70 , 0 ) ;
F_61 ( 600 ) ;
return 0 ;
}
static int T_4 F_63 ( struct V_1 * V_2 )
{
T_2 V_71 ;
F_18 ( L_45 ) ;
F_62 ( V_2 , V_70 , 0 ) ;
V_71 = F_64 ( V_2 , V_70 ) ;
if ( V_71 ) {
F_4 (KERN_ERR LXP L_46 , reg) ;
F_60 ( V_2 , V_72 , 1 ) ;
V_71 = F_64 ( V_2 , V_70 ) ;
if ( V_71 ) {
F_4 (KERN_ERR LXP L_47 , reg) ;
return - V_73 ;
}
}
F_2 ( V_13 L_48 ) ;
return 0 ;
}
static int T_4 F_65 ( struct V_1 * V_2 )
{
int V_42 ;
T_2 V_74 = F_64 ( V_2 , V_75 ) ;
T_2 V_76 = ( V_74 & V_77 ) |
( 64 << V_78 ) |
( 64 << V_79 ) |
( V_80 << V_81 ) ;
F_18 ( L_49 ) ;
V_2 -> V_82 = V_80 ;
F_62 ( V_2 , V_75 , V_76 ) ;
for ( V_42 = 0 ; V_42 != 1000 ; ++ V_42 ) {
if ( F_64 ( V_2 , V_83 ) & 4 ) {
F_2 ( V_13 L_50 ,
V_42 ) ;
goto V_84;
}
F_61 ( 1 ) ;
}
F_4 (KERN_WARNING LXP
L_51 , i) ;
return - V_85 ;
V_84:
F_2 ( V_13 L_52 ) ;
return 0 ;
}
static int T_4 F_66 ( struct V_1 * V_2 )
{
T_2 V_86 ;
int V_5 ;
F_18 ( L_53 ) ;
V_5 = F_67 ( V_2 , & V_86 ) ;
if ( V_5 == 0 ) {
T_2 V_87 ;
F_4 ( V_13 L_54 ,
( V_86 >> 16 ) & 0xff , ( V_86 >> 8 ) & 0xff ,
V_86 & 0xff ) ;
V_5 = F_68 ( V_2 , & V_87 ) ;
if ( V_5 == 0 )
V_2 -> V_18 = V_87 ;
F_2 ( V_13 L_55 , V_87 ) ;
} else {
F_4 (KERN_ERR LXP L_56 ) ;
V_5 = - V_73 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_88 )
{
int V_5 = 0 ;
T_2 V_89 = V_21 ;
F_18 ( L_57 ) ;
while ( ( V_89 < V_88 ) &&
( V_89 < V_22 ) ) {
V_89 *= 2 ;
}
if ( V_89 == V_2 -> V_90 )
return 0 ;
V_5 = F_69 ( V_2 , V_89 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_WARNING LXP L_58 ) ;
V_5 = - V_73 ;
}
if ( V_89 != V_88 )
F_4 ( V_13 L_59 , V_89 ) ;
F_2 ( V_13 L_60 , V_89 ) ;
V_2 -> V_90 = V_89 ;
return V_5 ;
}
static int T_4 F_70 ( struct V_1 * V_2 )
{
int V_5 ;
int V_42 ;
F_18 ( L_61 ) ;
F_2 ( V_13 L_62 ) ;
V_5 = F_58 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_2 ( V_13 L_63 ) ;
V_5 = F_63 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_2 ( V_13 L_64 ) ;
V_5 = F_65 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_71 ( V_2 ) ;
for ( V_42 = 0 ; V_42 != 1000 ; ++ V_42 ) {
V_5 = F_72 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_91 [ 0 ] || V_2 -> V_91 [ 1 ] || V_2 -> V_91 [ 2 ] ||
V_2 -> V_91 [ 3 ] || V_2 -> V_91 [ 4 ] || V_2 -> V_91 [ 5 ] )
goto V_92;
F_61 ( 1 ) ;
}
return - V_85 ;
V_92:
F_2 ( V_13 L_65 , V_42 ) ;
F_4 ( V_13 L_66 ,
V_2 -> V_91 [ 0 ] , V_2 -> V_91 [ 1 ] , V_2 -> V_91 [ 2 ] ,
V_2 -> V_91 [ 3 ] , V_2 -> V_91 [ 4 ] , V_2 -> V_91 [ 5 ] ) ;
V_5 = F_66 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_5 ( V_2 , V_93 ) ;
V_2 -> V_94 = 0 ;
return V_5 ;
}
static int T_4 F_73 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_95 * V_96 ;
T_2 V_97 = 64 *
3 *
V_98 *
V_22 *
2 ;
V_97 = F_74 ( V_97 ) ;
V_5 = F_75 ( V_2 -> V_99 , ( char * ) V_100 , 0 ,
1 , 1 , & V_96 ) ;
V_96 -> V_24 = V_2 ;
F_76 ( V_96 , V_101 , & V_102 ) ;
F_76 ( V_96 , V_11 , & V_103 ) ;
V_96 -> V_104 = 0 ;
strcpy ( V_96 -> V_105 , V_100 ) ;
V_5 = F_77 ( V_96 , V_106 ,
F_78 ( V_2 -> V_61 ) ,
V_97 , V_97 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_96 = V_96 ;
V_2 -> V_28 . V_9 = 1 ;
return 0 ;
}
static int F_79 ( struct V_107 * V_108 ,
struct V_109 * V_110 )
{
V_110 -> type = V_111 ;
V_110 -> V_112 = 1 ;
V_110 -> V_113 . integer . V_114 = 0 ;
V_110 -> V_113 . integer . V_115 = 1 ;
return 0 ;
}
static int F_80 ( struct V_107 * V_108 ,
struct V_116 * V_117 )
{
struct V_1 * V_2 = F_81 ( V_108 ) ;
V_117 -> V_113 . integer . V_113 [ 0 ] = V_2 -> V_94 ;
return 0 ;
}
static int F_82 ( struct V_107 * V_108 ,
struct V_116 * V_117 )
{
struct V_1 * V_2 = F_81 ( V_108 ) ;
int V_118 = 0 ;
int V_119 = V_2 -> V_94 ;
if ( V_119 != V_117 -> V_113 . integer . V_113 [ 0 ] ) {
F_83 ( V_2 , 0 , ! V_119 ) ;
V_2 -> V_94 = ! V_119 ;
V_118 = 1 ;
}
return V_118 ;
}
static void F_84 ( struct V_120 * V_121 ,
struct V_122 * V_123 )
{
T_2 V_124 [ 64 ] ;
int V_5 ;
int V_42 , V_125 ;
struct V_1 * V_2 = V_121 -> V_24 ;
F_85 ( V_123 , L_67 ) ;
V_5 = F_86 ( V_2 , 1 , 64 , V_124 ) ;
if ( V_5 < 0 )
return;
for ( V_42 = 0 ; V_42 != 8 ; ++ V_42 ) {
for ( V_125 = 0 ; V_125 != 8 ; ++ V_125 )
F_85 ( V_123 , L_68 , V_124 [ V_42 * 8 + V_125 ] ) ;
F_85 ( V_123 , L_69 ) ;
}
F_85 ( V_123 , L_70 ) ;
V_5 = F_86 ( V_2 , 0 , 64 , V_124 ) ;
if ( V_5 < 0 )
return;
for ( V_42 = 0 ; V_42 != 8 ; ++ V_42 ) {
for ( V_125 = 0 ; V_125 != 8 ; ++ V_125 )
F_85 ( V_123 , L_68 , V_124 [ V_42 * 8 + V_125 ] ) ;
F_85 ( V_123 , L_69 ) ;
}
F_85 ( V_123 , L_69 ) ;
}
static int T_4 F_87 ( struct V_126 * V_99 , struct V_1 * V_2 )
{
struct V_120 * V_121 ;
int V_5 = F_88 ( V_99 , L_71 , & V_121 ) ;
if ( V_5 < 0 )
return V_5 ;
F_89 ( V_121 , V_2 , F_84 ) ;
return 0 ;
}
static int T_4 F_90 ( struct V_126 * V_99 ,
struct V_127 * V_61 ,
struct V_1 * * V_128 )
{
struct V_1 * V_2 ;
int V_5 ;
static struct V_129 V_130 = {
. V_131 = F_57 ,
} ;
F_18 ( L_72 ) ;
* V_128 = NULL ;
V_5 = F_91 ( V_61 ) ;
if ( V_5 < 0 )
return V_5 ;
F_92 ( V_61 ) ;
V_5 = F_93 ( V_61 , F_94 ( 32 ) ) ;
if ( V_5 < 0 ) {
F_4 ( V_132 L_73
L_74 ) ;
F_55 ( V_61 ) ;
return - V_133 ;
}
V_2 = F_95 ( sizeof( * V_2 ) , V_134 ) ;
if ( V_2 == NULL ) {
V_5 = - V_135 ;
goto V_136;
}
V_2 -> V_99 = V_99 ;
V_2 -> V_61 = V_61 ;
V_2 -> V_58 = - 1 ;
F_96 ( & V_2 -> V_30 ) ;
F_96 ( & V_2 -> V_137 ) ;
F_97 ( & V_2 -> V_15 ) ;
F_98 ( & V_2 -> V_57 , F_45 ,
( unsigned long ) V_2 ) ;
F_98 ( & V_2 -> V_138 , V_139 ,
( unsigned long ) V_2 ) ;
F_98 ( & V_2 -> V_140 , V_141 ,
( unsigned long ) V_2 ) ;
V_5 = F_99 ( V_61 , V_100 ) ;
if ( V_5 < 0 )
goto V_142;
V_2 -> V_143 = F_100 ( V_61 , 1 ) ;
V_2 -> V_60 = F_101 ( V_2 -> V_143 ,
F_102 ( V_61 , 1 ) ) ;
V_2 -> V_59 = F_103 ( V_61 , 2 ) ;
V_5 = F_104 ( V_61 -> V_58 , V_144 , V_145 ,
V_146 , V_2 ) ;
if ( V_5 ) {
F_4 (KERN_ERR LXP L_75 , pci->irq) ;
goto V_147;
}
V_2 -> V_58 = V_61 -> V_58 ;
V_5 = F_105 ( V_99 , V_148 , V_2 , & V_130 ) ;
if ( V_5 < 0 )
goto V_149;
V_5 = F_70 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_76 ) ;
return V_5 ;
}
V_5 = F_73 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_87 ( V_99 , V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_106 ( V_99 , F_107 ( & V_150 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
F_108 ( V_99 , & V_61 -> V_151 ) ;
* V_128 = V_2 ;
return 0 ;
V_149:
F_51 ( V_61 -> V_58 , V_2 ) ;
V_147:
F_54 ( V_61 ) ;
V_142:
F_56 ( V_2 ) ;
V_136:
F_55 ( V_61 ) ;
return V_5 ;
}
static int T_4 F_109 ( struct V_127 * V_61 ,
const struct V_152 * V_153 )
{
static int V_151 ;
struct V_126 * V_99 ;
struct V_1 * V_2 ;
int V_5 ;
F_18 ( L_77 ) ;
if ( V_151 >= V_154 )
return - V_155 ;
if ( ! V_156 [ V_151 ] ) {
V_151 ++ ;
return - V_157 ;
}
V_5 = F_110 ( V_158 [ V_151 ] , V_159 [ V_151 ] , V_160 , 0 , & V_99 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_90 ( V_99 , V_61 , & V_2 ) ;
if ( V_5 < 0 ) {
F_4 (KERN_ERR LXP L_78 ) ;
goto V_161;
}
strcpy ( V_99 -> V_162 , L_79 ) ;
sprintf ( V_99 -> V_159 , L_80 ,
V_2 -> V_91 [ 3 ] , V_2 -> V_91 [ 4 ] , V_2 -> V_91 [ 5 ] ) ;
sprintf ( V_99 -> V_163 , L_81 ,
V_2 -> V_91 [ 0 ] , V_2 -> V_91 [ 1 ] , V_2 -> V_91 [ 2 ] ,
V_2 -> V_91 [ 3 ] , V_2 -> V_91 [ 4 ] , V_2 -> V_91 [ 5 ] ) ;
sprintf ( V_99 -> V_164 , L_82 ,
V_99 -> V_163 , V_2 -> V_143 ,
V_2 -> V_59 , V_2 -> V_58 ) ;
V_5 = F_111 ( V_99 ) ;
if ( V_5 < 0 )
goto V_161;
F_18 ( V_13 L_83 ) ;
F_112 ( V_61 , V_99 ) ;
V_151 ++ ;
return 0 ;
V_161:
F_113 ( V_99 ) ;
return V_5 ;
}
static void T_5 F_114 ( struct V_127 * V_61 )
{
F_113 ( F_115 ( V_61 ) ) ;
F_112 ( V_61 , NULL ) ;
}
