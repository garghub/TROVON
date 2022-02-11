static struct V_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 = NULL ;
int V_6 ;
F_2 (sg_list, sg, nents, i)
if ( V_6 == V_4 )
break;
return V_5 ;
}
static int F_3 ( struct V_7 * V_8 , T_1 V_9 )
{
F_4 ( 0 , & V_8 -> V_10 -> V_11 ) ;
F_4 ( V_12 << V_13 , & V_8 -> V_10 -> V_14 ) ;
F_4 ( V_9 , & V_8 -> V_10 -> V_15 ) ;
F_4 ( V_16 | V_17 , & V_8 -> V_10 -> V_18 ) ;
F_4 ( V_16 | V_17 , & V_8 -> V_10 -> V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_6 ( V_21 ) ;
struct V_24 * V_25 = F_7 ( V_23 ) ;
struct V_26 * V_27 = F_8 ( V_21 ) ;
struct V_7 * V_8 ;
F_9 ( V_27 -> V_8 -> V_28 , L_1 ) ;
F_10 ( & V_29 . V_30 ) ;
F_11 (crc, &crc_list.dev_list, list) {
V_25 -> V_8 = V_8 ;
break;
}
F_12 ( & V_29 . V_30 ) ;
if ( F_13 ( V_21 -> V_31 ) > V_32 ) {
F_9 ( V_27 -> V_8 -> V_28 , L_2 ,
V_32 ) ;
return - V_33 ;
}
V_27 -> V_8 = V_8 ;
V_27 -> V_34 = 0 ;
V_27 -> V_35 = 0 ;
V_27 -> V_36 = 0 ;
V_27 -> V_37 = 0 ;
V_27 -> V_38 = 0 ;
F_14 ( V_25 -> V_9 , V_21 -> V_39 ) ;
F_9 ( V_27 -> V_8 -> V_28 , L_3 ,
F_15 ( V_23 ) ) ;
return F_3 ( V_8 , V_25 -> V_9 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_5 ;
struct V_26 * V_27 = F_8 ( V_8 -> V_21 ) ;
int V_6 = 0 , V_40 = 0 ;
unsigned long V_41 ;
unsigned int V_42 ;
unsigned int V_43 ;
unsigned int V_44 = 0 ;
int V_45 ;
F_17 ( V_8 -> V_28 , V_27 -> V_5 , V_27 -> F_13 , V_46 ) ;
F_2 (ctx->sg, sg, ctx->sg_nents, j) {
V_43 = F_18 ( V_5 ) ;
if ( F_19 ( V_5 ) )
V_42 = F_20 ( V_5 ) - V_27 -> V_34 ;
else
V_42 = F_20 ( V_5 ) ;
if ( V_44 ) {
memcpy ( V_8 -> V_47 + ( V_6 << 2 ) + V_44 ,
F_21 ( V_5 ) ,
V_48 - V_44 ) ;
V_43 += V_48 - V_44 ;
V_42 -= V_48 - V_44 ;
V_41 = V_49 | V_50 | V_51 |
V_52 | V_53 | V_54 ;
V_8 -> V_55 [ V_6 ] . V_56 = V_8 -> V_57 + ( V_6 << 2 ) ;
V_8 -> V_55 [ V_6 ] . V_58 = V_41 ;
V_8 -> V_55 [ V_6 ] . V_59 = 1 ;
V_8 -> V_55 [ V_6 ] . V_60 = V_48 ;
F_9 ( V_8 -> V_28 , L_4
L_5 ,
V_6 , V_8 -> V_55 [ V_6 ] . V_56 ,
V_8 -> V_55 [ V_6 ] . V_58 , V_8 -> V_55 [ V_6 ] . V_59 ,
V_8 -> V_55 [ V_6 ] . V_60 ) ;
V_6 ++ ;
}
V_41 = V_49 | V_50 | V_51 | V_52 | V_53 ;
V_44 = V_42 % 4 ;
V_42 &= ~ 0x3 ;
if ( V_43 % 4 == 0 ) {
V_41 |= V_54 ;
V_42 >>= 2 ;
V_45 = 4 ;
} else if ( V_43 % 2 == 0 ) {
V_41 |= V_61 ;
V_42 >>= 1 ;
V_45 = 2 ;
} else {
V_41 |= V_62 ;
V_45 = 1 ;
}
V_8 -> V_55 [ V_6 ] . V_56 = V_43 ;
V_8 -> V_55 [ V_6 ] . V_58 = V_41 ;
V_8 -> V_55 [ V_6 ] . V_59 = V_42 ;
V_8 -> V_55 [ V_6 ] . V_60 = V_45 ;
F_9 ( V_8 -> V_28 , L_4
L_5 ,
V_6 , V_8 -> V_55 [ V_6 ] . V_56 ,
V_8 -> V_55 [ V_6 ] . V_58 , V_8 -> V_55 [ V_6 ] . V_59 ,
V_8 -> V_55 [ V_6 ] . V_60 ) ;
V_6 ++ ;
if ( V_44 ) {
memcpy ( V_8 -> V_47 + ( V_6 << 2 ) ,
( V_63 * ) F_21 ( V_5 ) + ( V_42 << 2 ) ,
V_44 ) ;
}
}
V_41 = V_49 | V_50 | V_51 | V_52 | V_53 | V_54 ;
if ( V_27 -> V_34 && ( V_27 -> V_38 == V_64 ||
V_27 -> V_38 == V_65 ) ) {
V_8 -> V_55 [ V_6 ] . V_56 = F_22 ( V_8 -> V_28 , V_27 -> V_66 ,
V_48 , V_46 ) ;
V_8 -> V_55 [ V_6 ] . V_58 = V_41 ;
V_8 -> V_55 [ V_6 ] . V_59 = 1 ;
V_8 -> V_55 [ V_6 ] . V_60 = V_48 ;
F_9 ( V_8 -> V_28 , L_4
L_5 ,
V_6 , V_8 -> V_55 [ V_6 ] . V_56 ,
V_8 -> V_55 [ V_6 ] . V_58 , V_8 -> V_55 [ V_6 ] . V_59 ,
V_8 -> V_55 [ V_6 ] . V_60 ) ;
V_6 ++ ;
}
if ( V_6 == 0 )
return;
V_8 -> V_55 [ V_6 - 1 ] . V_58 &= ~ ( V_67 | V_68 ) ;
V_8 -> V_55 [ V_6 - 1 ] . V_58 |= V_69 ;
F_23 ( V_8 -> V_70 , ( unsigned long * ) V_8 -> V_71 ) ;
F_24 ( V_8 -> V_70 , 0 ) ;
F_25 ( V_8 -> V_70 , 0 ) ;
F_26 ( V_8 -> V_70 , V_41 ) ;
}
static int F_27 ( struct V_7 * V_8 ,
struct V_20 * V_21 )
{
struct V_72 * V_73 , * V_74 ;
struct V_26 * V_27 ;
struct V_1 * V_5 ;
int V_75 = 0 ;
int V_76 , V_6 , V_40 ;
unsigned int V_77 ;
unsigned long V_78 ;
T_1 V_79 ;
F_28 ( & V_8 -> V_30 , V_78 ) ;
if ( V_21 )
V_75 = F_29 ( & V_8 -> V_80 , V_21 ) ;
if ( V_8 -> V_81 ) {
F_30 ( & V_8 -> V_30 , V_78 ) ;
return V_75 ;
}
V_74 = F_31 ( & V_8 -> V_80 ) ;
V_73 = F_32 ( & V_8 -> V_80 ) ;
if ( V_73 )
V_8 -> V_81 = 1 ;
F_30 ( & V_8 -> V_30 , V_78 ) ;
if ( ! V_73 )
return V_75 ;
if ( V_74 )
V_74 -> V_82 ( V_74 , - V_83 ) ;
V_21 = F_33 ( V_73 ) ;
V_8 -> V_21 = V_21 ;
V_27 = F_8 ( V_21 ) ;
V_27 -> V_5 = NULL ;
V_27 -> V_36 = 0 ;
V_27 -> F_13 = 0 ;
F_9 ( V_8 -> V_28 , L_6 ,
V_27 -> V_38 , V_21 -> V_84 ) ;
if ( V_27 -> V_38 == V_65 ) {
if ( V_27 -> V_34 == 0 ) {
V_8 -> V_81 = 0 ;
return 0 ;
}
memset ( V_27 -> V_66 + V_27 -> V_34 , 0 ,
V_48 - V_27 -> V_34 ) ;
} else {
if ( V_27 -> V_34 + V_21 -> V_84 < V_48 ) {
memcpy ( V_27 -> V_66 + V_27 -> V_34 ,
F_21 ( V_21 -> V_31 ) , V_21 -> V_84 ) ;
V_27 -> V_34 += V_21 -> V_84 ;
if ( V_27 -> V_38 == V_64 &&
V_27 -> V_34 ) {
goto V_85;
} else {
V_8 -> V_81 = 0 ;
return 0 ;
}
}
if ( V_27 -> V_34 ) {
V_27 -> V_35 = V_27 -> V_34 ;
memcpy ( V_27 -> V_86 , V_27 -> V_66 , V_27 -> V_35 ) ;
V_76 = V_27 -> V_36 ? 2 : 1 ;
F_34 ( V_27 -> V_87 , V_76 ) ;
F_35 ( V_27 -> V_87 , V_27 -> V_86 , V_27 -> V_35 ) ;
if ( V_76 > 1 )
F_36 ( V_27 -> V_87 , V_76 , V_21 -> V_31 ) ;
V_27 -> V_5 = V_27 -> V_87 ;
} else
V_27 -> V_5 = V_21 -> V_31 ;
V_76 = F_13 ( V_27 -> V_5 ) ;
V_27 -> F_13 = V_76 ;
V_27 -> V_36 = V_27 -> V_35 + V_21 -> V_84 ;
V_27 -> V_34 = V_27 -> V_36 % 4 ;
V_27 -> V_36 &= ~ 0x3 ;
if ( V_27 -> V_34 ) {
memset ( V_27 -> V_66 , 0 , V_48 ) ;
V_77 = V_27 -> V_34 ;
for ( V_6 = V_76 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_5 = F_1 ( V_27 -> V_5 , V_76 , V_6 ) ;
V_40 = F_37 ( V_77 , F_20 ( V_5 ) ) ;
memcpy ( V_27 -> V_66 + V_77 - V_40 ,
F_21 ( V_5 ) + F_20 ( V_5 ) - V_40 , V_40 ) ;
if ( V_40 == F_20 ( V_5 ) )
V_27 -> F_13 -- ;
V_77 -= V_40 ;
if ( V_77 == 0 )
break;
}
}
}
V_85:
if ( V_27 -> V_34 && ( V_27 -> V_38 == V_64 ||
V_27 -> V_38 == V_65 ) )
V_27 -> V_36 += V_48 ;
F_4 ( V_27 -> V_36 >> 2 , & V_8 -> V_10 -> V_88 ) ;
F_16 ( V_8 ) ;
V_79 = F_38 ( & V_8 -> V_10 -> V_14 ) ;
F_4 ( V_79 | V_89 , & V_8 -> V_10 -> V_14 ) ;
return - V_83 ;
}
static int F_39 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = F_8 ( V_21 ) ;
if ( ! V_21 -> V_84 )
return 0 ;
F_9 ( V_27 -> V_8 -> V_28 , L_7 ) ;
V_27 -> V_37 += V_21 -> V_84 ;
V_27 -> V_38 = V_90 ;
return F_27 ( V_27 -> V_8 , V_21 ) ;
}
static int F_40 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_6 ( V_21 ) ;
struct V_24 * V_25 = F_7 ( V_23 ) ;
struct V_26 * V_27 = F_8 ( V_21 ) ;
F_9 ( V_27 -> V_8 -> V_28 , L_8 ) ;
V_27 -> V_38 = V_65 ;
V_25 -> V_9 = 0 ;
return F_27 ( V_27 -> V_8 , V_21 ) ;
}
static int F_41 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_6 ( V_21 ) ;
struct V_24 * V_25 = F_7 ( V_23 ) ;
struct V_26 * V_27 = F_8 ( V_21 ) ;
F_9 ( V_27 -> V_8 -> V_28 , L_9 ) ;
V_27 -> V_37 += V_21 -> V_84 ;
V_27 -> V_38 = V_64 ;
V_25 -> V_9 = 0 ;
return F_27 ( V_27 -> V_8 , V_21 ) ;
}
static int F_42 ( struct V_20 * V_21 )
{
int V_75 ;
V_75 = F_5 ( V_21 ) ;
if ( V_75 )
return V_75 ;
return F_41 ( V_21 ) ;
}
static int F_43 ( struct V_22 * V_23 , const V_63 * V_9 ,
unsigned int V_91 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
F_9 ( V_25 -> V_8 -> V_28 , L_10 ) ;
if ( V_91 != V_48 ) {
F_44 ( V_23 , V_92 ) ;
return - V_33 ;
}
V_25 -> V_9 = F_45 ( V_9 ) ;
return 0 ;
}
static int F_46 ( struct V_93 * V_23 )
{
struct V_24 * V_25 = F_47 ( V_23 ) ;
V_25 -> V_9 = 0 ;
F_48 ( F_49 ( V_23 ) ,
sizeof( struct V_26 ) ) ;
return 0 ;
}
static void F_50 ( struct V_93 * V_23 )
{
}
static void F_51 ( unsigned long V_94 )
{
struct V_7 * V_8 = (struct V_7 * ) V_94 ;
F_27 ( V_8 , NULL ) ;
}
static T_2 F_52 ( int V_95 , void * V_96 )
{
struct V_7 * V_8 = V_96 ;
T_1 V_79 ;
if ( F_38 ( & V_8 -> V_10 -> V_18 ) & V_97 ) {
F_4 ( V_97 , & V_8 -> V_10 -> V_18 ) ;
F_14 ( F_38 ( & V_8 -> V_10 -> V_39 ) ,
V_8 -> V_21 -> V_39 ) ;
V_79 = F_38 ( & V_8 -> V_10 -> V_14 ) ;
F_4 ( V_79 & ~ V_89 , & V_8 -> V_10 -> V_14 ) ;
V_8 -> V_81 = 0 ;
if ( V_8 -> V_21 -> V_98 . V_82 )
V_8 -> V_21 -> V_98 . V_82 ( & V_8 -> V_21 -> V_98 , 0 ) ;
F_53 ( & V_8 -> V_99 ) ;
return V_100 ;
} else
return V_101 ;
}
static int F_54 ( struct V_102 * V_103 , T_3 V_104 )
{
struct V_7 * V_8 = F_55 ( V_103 ) ;
int V_6 = 100000 ;
while ( ( F_38 ( & V_8 -> V_10 -> V_14 ) & V_89 ) && -- V_6 )
F_56 () ;
if ( V_6 == 0 )
return - V_105 ;
return 0 ;
}
static int F_57 ( struct V_102 * V_103 )
{
struct V_106 * V_28 = & V_103 -> V_28 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
unsigned int V_109 = 100000 ;
int V_75 ;
V_8 = F_58 ( V_28 , sizeof( * V_8 ) , V_110 ) ;
if ( ! V_8 ) {
F_59 ( & V_103 -> V_28 , L_11 ) ;
return - V_111 ;
}
V_8 -> V_28 = V_28 ;
F_60 ( & V_8 -> V_112 ) ;
F_61 ( & V_8 -> V_30 ) ;
F_62 ( & V_8 -> V_99 , F_51 , ( unsigned long ) V_8 ) ;
F_63 ( & V_8 -> V_80 , V_113 ) ;
V_108 = F_64 ( V_103 , V_114 , 0 ) ;
if ( V_108 == NULL ) {
F_59 ( & V_103 -> V_28 , L_12 ) ;
return - V_115 ;
}
V_8 -> V_10 = F_65 ( V_28 , V_108 ) ;
if ( F_66 ( ( void * ) V_8 -> V_10 ) ) {
F_59 ( & V_103 -> V_28 , L_13 ) ;
return F_67 ( ( void * ) V_8 -> V_10 ) ;
}
V_8 -> V_95 = F_68 ( V_103 , 0 ) ;
if ( V_8 -> V_95 < 0 ) {
F_59 ( & V_103 -> V_28 , L_14 ) ;
return - V_115 ;
}
V_75 = F_69 ( V_28 , V_8 -> V_95 , F_52 ,
V_116 , F_70 ( V_28 ) , V_8 ) ;
if ( V_75 ) {
F_59 ( & V_103 -> V_28 , L_15 ) ;
return V_75 ;
}
V_108 = F_64 ( V_103 , V_117 , 0 ) ;
if ( V_108 == NULL ) {
F_59 ( & V_103 -> V_28 , L_16 ) ;
return - V_115 ;
}
V_8 -> V_70 = V_108 -> V_118 ;
V_75 = F_71 ( V_8 -> V_70 , F_70 ( V_28 ) ) ;
if ( V_75 ) {
F_59 ( & V_103 -> V_28 , L_17 ) ;
return V_75 ;
}
V_8 -> V_55 = F_72 ( & V_103 -> V_28 , V_119 , & V_8 -> V_71 , V_110 ) ;
if ( V_8 -> V_55 == NULL ) {
V_75 = - V_111 ;
goto V_120;
}
V_8 -> V_47 = ( V_63 * ) ( V_8 -> V_55 + ( ( V_32 + 1 ) << 1 ) ) ;
V_8 -> V_57 = V_8 -> V_71 + sizeof( struct V_121 )
* ( ( V_32 + 1 ) << 1 ) ;
F_4 ( 0 , & V_8 -> V_10 -> V_14 ) ;
V_8 -> V_122 = ( T_1 ) V_103 -> V_28 . V_123 ;
F_4 ( V_8 -> V_122 , & V_8 -> V_10 -> V_122 ) ;
while ( ! ( F_38 ( & V_8 -> V_10 -> V_18 ) & V_124 ) && ( -- V_109 ) > 0 )
F_56 () ;
if ( V_109 == 0 )
F_73 ( & V_103 -> V_28 , L_18 ) ;
F_74 ( V_103 , V_8 ) ;
F_75 ( & V_29 . V_30 ) ;
F_76 ( & V_8 -> V_112 , & V_29 . V_125 ) ;
F_77 ( & V_29 . V_30 ) ;
if ( F_78 ( & V_29 . V_125 ) ) {
V_75 = F_79 ( & V_126 ) ;
if ( V_75 ) {
F_59 ( & V_103 -> V_28 ,
L_19 ) ;
goto V_120;
}
}
F_73 ( & V_103 -> V_28 , L_20 ) ;
return 0 ;
V_120:
if ( V_8 -> V_55 )
F_80 ( & V_103 -> V_28 , V_119 , V_8 -> V_55 , V_8 -> V_71 ) ;
F_81 ( V_8 -> V_70 ) ;
return V_75 ;
}
static int F_82 ( struct V_102 * V_103 )
{
struct V_7 * V_8 = F_55 ( V_103 ) ;
if ( ! V_8 )
return - V_127 ;
F_75 ( & V_29 . V_30 ) ;
F_83 ( & V_8 -> V_112 ) ;
F_77 ( & V_29 . V_30 ) ;
F_84 ( & V_126 ) ;
F_85 ( & V_8 -> V_99 ) ;
F_81 ( V_8 -> V_70 ) ;
return 0 ;
}
static int T_4 F_86 ( void )
{
int V_75 ;
F_87 ( L_21 ) ;
F_60 ( & V_29 . V_125 ) ;
F_61 ( & V_29 . V_30 ) ;
V_75 = F_88 ( & V_128 ) ;
if ( V_75 ) {
F_89 ( L_22 ) ;
return V_75 ;
}
return 0 ;
}
static void T_5 F_90 ( void )
{
F_91 ( & V_128 ) ;
}
