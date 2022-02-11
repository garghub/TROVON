static int F_1 ( struct V_1 * V_2 , int type , T_1 V_3 ,
struct V_4 * V_5 )
{
return F_2 ( type , V_2 -> V_6 -> V_7 , V_3 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_4 ( V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_1 V_3 )
{
struct V_10 * V_10 = F_6 ( V_9 ) ;
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
V_10 -> V_13 = 0 ;
return F_7 ( V_9 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
return F_9 ( V_9 ) ;
}
static void F_10 ( T_2 V_14 , T_2 * V_15 )
{
F_11 ( V_14 , V_15 ) ;
}
static T_2 F_12 ( T_2 * V_15 )
{
return F_13 ( V_15 ) ;
}
static void F_14 ( T_3 V_14 , T_3 * V_15 )
{
unsigned int V_16 = ( ( unsigned long ) ( V_15 ) & 0x3 ) << 3 ;
void * V_17 = ( void * ) ( ( unsigned long ) ( V_15 ) & ~ 0x3 ) ;
T_2 V_18 ;
V_18 = F_13 ( V_17 ) ;
V_18 &= ~ ( 0xffff << V_16 ) ;
V_18 |= V_14 << V_16 ;
F_11 ( V_18 , V_17 ) ;
}
static T_3 F_15 ( T_3 * V_15 )
{
unsigned int V_16 = ( ( unsigned long ) ( V_15 ) & 0x3 ) << 3 ;
void * V_17 = ( void * ) ( ( unsigned long ) ( V_15 ) & ~ 0x3 ) ;
T_2 V_18 ;
V_18 = F_13 ( V_17 ) ;
return ( V_18 >> V_16 ) & 0xffff ;
}
static void F_16 ( T_4 V_14 , T_4 * V_15 )
{
unsigned int V_16 = ( ( unsigned long ) ( V_15 ) & 0x3 ) << 3 ;
void * V_17 = ( void * ) ( ( unsigned long ) ( V_15 ) & ~ 0x3 ) ;
T_2 V_18 ;
V_18 = F_13 ( V_17 ) ;
V_18 &= ~ ( 0xff << V_16 ) ;
V_18 |= V_14 << V_16 ;
F_11 ( V_18 , V_17 ) ;
}
static T_4 F_17 ( T_4 * V_15 )
{
unsigned int V_16 = ( ( unsigned long ) ( V_15 ) & 0x3 ) << 3 ;
void * V_17 = ( void * ) ( ( unsigned long ) ( V_15 ) & ~ 0x3 ) ;
T_2 V_18 ;
V_18 = F_13 ( V_17 ) ;
return ( V_18 >> V_16 ) & 0xff ;
}
static void F_18 ( struct V_19 * V_20 )
{
T_2 V_18 ;
V_18 = F_13 ( V_20 -> V_21 + V_22 ) ;
V_18 |= V_23 ;
F_11 ( V_18 , V_20 -> V_21 + V_22 ) ;
V_18 = F_13 ( V_20 -> V_21 + V_24 ) ;
V_18 &= ~ V_25 ;
V_18 |= V_26 | V_27 |
V_28 | V_29 ;
F_11 ( V_18 , V_20 -> V_21 + V_24 ) ;
F_11 ( V_30 , V_20 -> V_21 + V_31 ) ;
F_11 ( V_32 , V_20 -> V_21 + V_31 ) ;
F_11 ( V_33 , V_20 -> V_21 + V_34 ) ;
V_18 = F_13 ( V_20 -> V_21 + V_35 ) ;
V_18 |= V_36 ;
F_11 ( V_18 , V_20 -> V_21 + V_35 ) ;
}
static int F_19 ( struct V_19 * V_37 )
{
int V_38 ;
V_38 = F_20 ( V_37 -> V_39 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_20 ( V_37 -> V_40 ) ;
if ( V_38 )
goto V_41;
V_38 = F_20 ( V_37 -> V_42 ) ;
if ( V_38 )
goto V_43;
return 0 ;
V_43:
F_21 ( V_37 -> V_40 ) ;
V_41:
F_21 ( V_37 -> V_39 ) ;
return V_38 ;
}
static void F_22 ( struct V_19 * V_37 )
{
F_21 ( V_37 -> V_42 ) ;
F_21 ( V_37 -> V_40 ) ;
F_21 ( V_37 -> V_39 ) ;
}
static int F_23 ( struct V_44 * V_7 )
{
struct V_45 * V_6 = F_24 ( V_7 ) ;
struct V_1 * V_2 = V_6 -> V_46 ;
struct V_47 * V_48 ;
struct V_19 * V_20 = F_25 ( V_2 , struct V_19 , V_2 ) ;
F_26 ( V_6 , V_49 ) ;
F_27 (p, &chip->pcm_list, list)
F_28 ( V_48 -> V_50 ) ;
if ( V_2 -> V_51 )
F_29 ( V_2 -> V_52 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_22 ( V_20 ) ;
return 0 ;
}
static int F_32 ( struct V_44 * V_7 )
{
struct V_45 * V_6 = F_24 ( V_7 ) ;
struct V_1 * V_2 = V_6 -> V_46 ;
struct V_19 * V_20 = F_25 ( V_2 , struct V_19 , V_2 ) ;
int V_53 ;
F_19 ( V_20 ) ;
V_53 = F_33 ( V_2 , V_54 ) ;
F_18 ( V_20 ) ;
F_34 ( V_2 , 1 ) ;
F_35 ( V_2 -> V_52 ) ;
F_26 ( V_6 , V_55 ) ;
return 0 ;
}
static int F_36 ( struct V_56 * V_57 , unsigned long V_58 ,
void * V_5 )
{
struct V_1 * V_2 = F_25 ( V_57 , struct V_1 , V_59 ) ;
F_37 ( V_2 -> V_52 ) ;
F_30 ( V_2 ) ;
return V_60 ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_59 . V_61 = F_36 ;
F_39 ( & V_2 -> V_59 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 . V_61 )
F_41 ( & V_2 -> V_59 ) ;
}
static int F_42 ( struct V_62 * V_44 )
{
int V_63 ;
struct V_1 * V_2 = V_44 -> V_64 ;
F_40 ( V_2 ) ;
if ( V_2 -> V_51 ) {
for ( V_63 = 0 ; V_63 < V_2 -> V_65 ; V_63 ++ )
F_43 ( V_2 , & V_2 -> V_10 [ V_63 ] ) ;
F_30 ( V_2 ) ;
}
F_44 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_19 * V_20 = F_25 ( V_2 , struct V_19 , V_2 ) ;
struct V_44 * V_7 = V_20 -> V_7 ;
struct V_68 * V_69 ;
int V_70 ;
V_20 -> V_39 = F_46 ( V_7 , L_1 ) ;
if ( F_47 ( V_20 -> V_39 ) )
return F_48 ( V_20 -> V_39 ) ;
V_20 -> V_40 = F_46 ( V_7 , L_2 ) ;
if ( F_47 ( V_20 -> V_40 ) )
return F_48 ( V_20 -> V_40 ) ;
V_20 -> V_42 = F_46 ( V_7 , L_3 ) ;
if ( F_47 ( V_20 -> V_42 ) )
return F_48 ( V_20 -> V_42 ) ;
V_69 = F_49 ( V_67 , V_71 , 0 ) ;
V_20 -> V_21 = F_50 ( V_7 , V_69 ) ;
if ( F_47 ( V_2 -> V_72 ) )
return F_48 ( V_2 -> V_72 ) ;
V_2 -> V_72 = V_20 -> V_21 + V_73 ;
V_2 -> V_15 = V_69 -> V_74 + V_73 ;
V_70 = F_19 ( V_20 ) ;
if ( V_70 )
return V_70 ;
F_18 ( V_20 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
F_27 (codec, &chip->bus->codec_list, list)
F_52 ( V_76 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_45 * V_6 = V_2 -> V_6 ;
int V_70 ;
unsigned short V_77 ;
int V_78 = F_54 ( V_67 , 0 ) ;
V_70 = F_45 ( V_2 , V_67 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_55 ( V_2 -> V_6 -> V_7 , V_78 , V_79 ,
V_80 , V_81 , V_2 ) ;
if ( V_70 ) {
F_56 ( V_2 -> V_6 -> V_7 ,
L_4 ,
V_78 ) ;
return V_70 ;
}
V_2 -> V_82 = V_78 ;
F_57 ( V_2 -> V_82 ) ;
V_77 = F_33 ( V_2 , V_83 ) ;
F_58 ( V_6 -> V_7 , L_5 , V_77 ) ;
V_2 -> V_84 = ( V_77 >> 8 ) & 0x0f ;
V_2 -> V_85 = ( V_77 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_85 && ! V_2 -> V_84 ) {
V_2 -> V_85 = V_86 ;
V_2 -> V_84 = V_87 ;
}
V_2 -> V_88 = 0 ;
V_2 -> V_89 = V_2 -> V_84 ;
V_2 -> V_65 = V_2 -> V_85 + V_2 -> V_84 ;
V_2 -> V_10 = F_59 ( V_6 -> V_7 , V_2 -> V_65 ,
sizeof( * V_2 -> V_10 ) , V_90 ) ;
if ( ! V_2 -> V_10 )
return - V_91 ;
V_70 = F_60 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
F_61 ( V_2 ) ;
F_34 ( V_2 , 1 ) ;
if ( ! V_2 -> V_92 ) {
F_56 ( V_6 -> V_7 , L_6 ) ;
return - V_93 ;
}
strcpy ( V_6 -> V_94 , L_7 ) ;
strcpy ( V_6 -> V_95 , L_7 ) ;
snprintf ( V_6 -> V_96 , sizeof( V_6 -> V_96 ) ,
L_8 ,
V_6 -> V_95 , V_2 -> V_15 , V_2 -> V_82 ) ;
return 0 ;
}
static int F_62 ( struct V_45 * V_6 ,
unsigned int V_97 ,
const struct V_98 * V_99 ,
struct V_19 * V_20 )
{
static struct V_100 V_101 = {
. V_102 = F_42 ,
} ;
struct V_1 * V_2 ;
int V_70 ;
V_2 = & V_20 -> V_2 ;
F_63 ( & V_2 -> V_103 ) ;
F_64 ( & V_2 -> V_104 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_101 = V_99 ;
V_2 -> V_82 = - 1 ;
V_2 -> V_97 = V_97 ;
V_2 -> V_105 = V_97 & 0xff ;
V_2 -> V_106 = 0 ;
F_65 ( & V_2 -> V_107 ) ;
F_65 ( & V_2 -> V_108 ) ;
V_2 -> V_109 [ 0 ] = V_110 ;
V_2 -> V_109 [ 1 ] = V_110 ;
V_2 -> V_111 = - 1 ;
V_2 -> V_112 = false ;
V_2 -> V_113 = true ;
V_70 = F_66 ( V_6 , V_114 , V_2 , & V_101 ) ;
if ( V_70 < 0 ) {
F_56 ( V_6 -> V_7 , L_9 ) ;
return V_70 ;
}
return 0 ;
}
static int F_67 ( struct V_66 * V_67 )
{
struct V_45 * V_6 ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_70 ;
const unsigned int V_115 = V_116 ;
V_20 = F_68 ( & V_67 -> V_7 , sizeof( * V_20 ) , V_90 ) ;
if ( ! V_20 )
return - V_91 ;
V_20 -> V_7 = & V_67 -> V_7 ;
V_2 = & V_20 -> V_2 ;
V_70 = F_69 ( & V_67 -> V_7 , V_117 , V_118 ,
V_119 , 0 , & V_6 ) ;
if ( V_70 < 0 ) {
F_56 ( & V_67 -> V_7 , L_10 ) ;
return V_70 ;
}
V_70 = F_62 ( V_6 , V_115 , & V_120 , V_20 ) ;
if ( V_70 < 0 )
goto V_121;
V_6 -> V_46 = V_2 ;
F_70 ( & V_67 -> V_7 , V_6 ) ;
V_70 = F_53 ( V_2 , V_67 ) ;
if ( V_70 < 0 )
goto V_121;
V_70 = F_71 ( V_2 , NULL , 0 , & V_122 ) ;
if ( V_70 < 0 )
goto V_121;
V_70 = F_72 ( V_2 ) ;
if ( V_70 < 0 )
goto V_121;
V_70 = F_73 ( V_2 -> V_52 ) ;
if ( V_70 < 0 )
goto V_121;
V_70 = F_74 ( V_2 ) ;
if ( V_70 < 0 )
goto V_121;
V_70 = F_75 ( V_2 -> V_6 ) ;
if ( V_70 < 0 )
goto V_121;
V_2 -> V_123 = 1 ;
F_51 ( V_2 ) ;
F_38 ( V_2 ) ;
return 0 ;
V_121:
F_76 ( V_6 ) ;
return V_70 ;
}
static int F_77 ( struct V_66 * V_67 )
{
return F_76 ( F_24 ( & V_67 -> V_7 ) ) ;
}
