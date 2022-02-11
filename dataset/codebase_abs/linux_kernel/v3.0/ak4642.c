static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return - 1 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_7 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_7 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
T_2 V_8 [ 2 ] ;
V_8 [ 0 ] = V_3 & 0xff ;
V_8 [ 1 ] = V_7 & 0xff ;
if ( V_2 -> V_9 ( V_2 -> V_10 , V_8 , 2 ) == 2 ) {
F_2 ( V_2 , V_3 , V_7 ) ;
return 0 ;
} else
return - V_11 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_12 , V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
V_13 |= F_3 ( V_2 , V_12 , V_4 [ V_12 ] ) ;
return V_13 ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_18 = V_15 -> V_19 == V_20 ;
struct V_1 * V_2 = V_17 -> V_2 ;
if ( V_18 ) {
F_6 ( V_2 , V_21 , V_22 , V_22 ) ;
F_6 ( V_2 , V_23 , V_24 , V_24 ) ;
F_3 ( V_2 , V_25 , 0x91 ) ;
F_3 ( V_2 , V_26 , 0x91 ) ;
F_6 ( V_2 , V_27 , V_28 | V_29 | V_30 ,
V_28 | V_29 | V_30 ) ;
F_6 ( V_2 , V_31 , V_32 , V_33 ) ;
F_6 ( V_2 , V_31 , V_34 , V_34 ) ;
} else {
F_3 ( V_2 , V_35 , V_36 | V_37 ) ;
F_3 ( V_2 , V_38 , F_7 ( 0x3 ) | F_8 ( 0x3 ) ) ;
F_3 ( V_2 , V_39 , V_40 | V_41 ) ;
F_6 ( V_2 , V_27 , V_28 | V_42 ,
V_28 | V_42 ) ;
F_6 ( V_2 , V_43 , V_44 , V_44 ) ;
}
return 0 ;
}
static void F_9 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_18 = V_15 -> V_19 == V_20 ;
struct V_1 * V_2 = V_17 -> V_2 ;
if ( V_18 ) {
F_6 ( V_2 , V_31 , V_34 , 0 ) ;
F_6 ( V_2 , V_31 , V_32 , 0 ) ;
F_6 ( V_2 , V_27 , V_29 | V_30 , 0 ) ;
F_6 ( V_2 , V_23 , V_24 , 0 ) ;
F_6 ( V_2 , V_21 , V_22 , 0 ) ;
} else {
F_6 ( V_2 , V_27 , V_42 , 0 ) ;
F_6 ( V_2 , V_43 , V_44 , 0 ) ;
F_6 ( V_2 , V_39 , V_40 , 0 ) ;
}
}
static int F_10 ( struct V_16 * V_45 ,
int V_46 , unsigned int V_47 , int V_48 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
T_2 V_49 ;
switch ( V_47 ) {
case 11289600 :
V_49 = V_50 ;
break;
case 12288000 :
V_49 = V_50 | V_51 ;
break;
case 12000000 :
V_49 = V_50 | V_52 ;
break;
case 24000000 :
V_49 = V_50 | V_52 | V_51 ;
break;
case 13500000 :
V_49 = V_53 | V_50 ;
break;
case 27000000 :
V_49 = V_53 | V_50 | V_51 ;
break;
default:
return - V_54 ;
}
F_6 ( V_2 , V_55 , V_56 , V_49 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 , unsigned int V_57 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
T_2 V_8 ;
T_2 V_58 ;
V_8 = V_59 | V_60 ;
V_58 = 0 ;
switch ( V_57 & V_61 ) {
case V_62 :
V_8 |= V_63 ;
V_58 = V_64 ;
break;
case V_65 :
break;
default:
return - V_54 ;
}
F_6 ( V_2 , V_31 , V_63 | V_59 | V_60 , V_8 ) ;
F_6 ( V_2 , V_55 , V_66 , V_58 ) ;
V_8 = 0 ;
switch ( V_57 & V_67 ) {
case V_68 :
V_8 = V_69 ;
break;
case V_70 :
V_8 = V_71 ;
break;
default:
return - V_54 ;
break;
}
F_6 ( V_2 , V_55 , V_72 , V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_73 * V_74 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
T_2 V_75 ;
switch ( F_13 ( V_74 ) ) {
case 7350 :
V_75 = V_76 ;
break;
case 8000 :
V_75 = 0 ;
break;
case 11025 :
V_75 = V_76 | V_77 ;
break;
case 12000 :
V_75 = V_77 ;
break;
case 14700 :
V_75 = V_76 | V_78 ;
break;
case 16000 :
V_75 = V_78 ;
break;
case 22050 :
V_75 = V_76 | V_78 | V_77 ;
break;
case 24000 :
V_75 = V_78 | V_77 ;
break;
case 29400 :
V_75 = V_79 | V_76 | V_78 ;
break;
case 32000 :
V_75 = V_79 | V_78 ;
break;
case 44100 :
V_75 = V_79 | V_76 | V_78 | V_77 ;
break;
case 48000 :
V_75 = V_79 | V_78 | V_77 ;
break;
default:
return - V_54 ;
break;
}
F_6 ( V_2 , V_80 , V_81 , V_75 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_16 ( V_2 ) ;
F_17 ( V_2 -> V_84 , L_1 , V_85 ) ;
V_2 -> V_9 = ( V_86 ) V_87 ;
V_2 -> V_10 = V_83 -> V_10 ;
F_18 ( V_2 , V_88 ,
F_19 ( V_88 ) ) ;
return 0 ;
}
static T_3 int F_20 ( struct V_89 * V_90 ,
const struct V_91 * V_92 )
{
struct V_82 * V_83 ;
int V_93 ;
V_83 = F_21 ( sizeof( struct V_82 ) , V_94 ) ;
if ( ! V_83 )
return - V_95 ;
F_22 ( V_90 , V_83 ) ;
V_83 -> V_10 = V_90 ;
V_83 -> V_96 = V_97 ;
V_93 = F_23 ( & V_90 -> V_84 ,
& V_98 , & V_99 , 1 ) ;
if ( V_93 < 0 )
F_24 ( V_83 ) ;
return V_93 ;
}
static T_4 int F_25 ( struct V_89 * V_100 )
{
F_26 ( & V_100 -> V_84 ) ;
F_24 ( F_27 ( V_100 ) ) ;
return 0 ;
}
static int T_5 F_28 ( void )
{
int V_93 = 0 ;
#if F_29 ( V_101 ) || F_29 ( V_102 )
V_93 = F_30 ( & V_103 ) ;
#endif
return V_93 ;
}
static void T_6 F_31 ( void )
{
#if F_29 ( V_101 ) || F_29 ( V_102 )
F_32 ( & V_103 ) ;
#endif
}
