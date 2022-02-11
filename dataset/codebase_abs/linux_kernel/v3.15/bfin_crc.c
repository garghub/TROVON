static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = V_2 ;
int V_4 = 1 ;
if ( V_2 == NULL )
return 0 ;
while ( ! F_2 ( V_3 ) ) {
V_4 ++ ;
V_3 = F_3 ( V_3 ) ;
}
return V_4 ;
}
static struct V_1 * F_4 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_6 )
{
struct V_1 * V_3 = NULL ;
int V_7 ;
F_5 (sg_list, sg, nents, i)
if ( V_7 == V_6 )
break;
return V_3 ;
}
static int F_6 ( struct V_8 * V_9 , T_1 V_10 )
{
V_9 -> V_11 -> V_12 = 0 ;
V_9 -> V_11 -> V_13 = V_14 << V_15 ;
V_9 -> V_11 -> V_16 = V_10 ;
V_9 -> V_11 -> V_17 = V_18 | V_19 ;
V_9 -> V_11 -> V_20 = V_18 | V_19 ;
return 0 ;
}
static int F_7 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_8 ( V_22 ) ;
struct V_25 * V_26 = F_9 ( V_24 ) ;
struct V_27 * V_28 = F_10 ( V_22 ) ;
struct V_8 * V_9 ;
F_11 ( V_28 -> V_9 -> V_29 , L_1 ) ;
F_12 ( & V_30 . V_31 ) ;
F_13 (crc, &crc_list.dev_list, list) {
V_26 -> V_9 = V_9 ;
break;
}
F_14 ( & V_30 . V_31 ) ;
if ( F_1 ( V_22 -> V_32 ) > V_33 ) {
F_11 ( V_28 -> V_9 -> V_29 , L_2 ,
V_33 ) ;
return - V_34 ;
}
V_28 -> V_9 = V_9 ;
V_28 -> V_35 = 0 ;
V_28 -> V_36 = 0 ;
V_28 -> V_37 = 0 ;
V_28 -> V_38 = 0 ;
V_28 -> V_39 = 0 ;
F_15 ( V_26 -> V_10 , V_22 -> V_40 ) ;
F_11 ( V_28 -> V_9 -> V_29 , L_3 ,
F_16 ( V_24 ) ) ;
return F_6 ( V_9 , V_26 -> V_10 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_3 ;
struct V_27 * V_28 = F_10 ( V_9 -> V_22 ) ;
int V_7 = 0 , V_41 = 0 ;
unsigned long V_42 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 = 0 ;
int V_46 ;
F_18 ( V_9 -> V_29 , V_28 -> V_3 , V_28 -> V_4 , V_47 ) ;
F_5 (ctx->sg, sg, ctx->sg_nents, j) {
V_42 = V_48 | V_49 | V_50 | V_51 | V_52 ;
V_44 = F_19 ( V_3 ) ;
if ( F_2 ( V_3 ) )
V_43 = F_20 ( V_3 ) - V_28 -> V_35 ;
else
V_43 = F_20 ( V_3 ) ;
if ( V_45 ) {
memcpy ( V_9 -> V_53 + ( ( V_7 - 1 ) << 2 ) + V_45 ,
( void * ) V_44 ,
V_54 - V_45 ) ;
V_44 += V_54 - V_45 ;
V_43 -= V_54 - V_45 ;
}
V_45 = V_43 % 4 ;
V_43 &= ~ 0x3 ;
if ( V_44 % 4 == 0 ) {
V_42 |= V_55 ;
V_43 >>= 2 ;
V_46 = 4 ;
} else if ( V_44 % 2 == 0 ) {
V_42 |= V_56 ;
V_43 >>= 1 ;
V_46 = 2 ;
} else {
V_42 |= V_57 ;
V_46 = 1 ;
}
V_9 -> V_58 [ V_7 ] . V_59 = V_44 ;
V_9 -> V_58 [ V_7 ] . V_60 = V_42 ;
V_9 -> V_58 [ V_7 ] . V_61 = V_43 ;
V_9 -> V_58 [ V_7 ] . V_62 = V_46 ;
F_11 ( V_9 -> V_29 , L_4
L_5 ,
V_7 , V_9 -> V_58 [ V_7 ] . V_59 ,
V_9 -> V_58 [ V_7 ] . V_60 , V_9 -> V_58 [ V_7 ] . V_61 ,
V_9 -> V_58 [ V_7 ] . V_62 ) ;
V_7 ++ ;
if ( V_45 ) {
V_42 = V_48 | V_49 | V_50 |
V_51 | V_52 | V_55 ;
memcpy ( V_9 -> V_53 + ( V_7 << 2 ) ,
( void * ) ( V_44 + ( V_43 << 2 ) ) ,
V_45 ) ;
V_9 -> V_58 [ V_7 ] . V_59 = F_21 ( V_9 -> V_29 ,
V_9 -> V_53 + ( V_7 << 2 ) ,
V_54 , V_47 ) ;
V_9 -> V_58 [ V_7 ] . V_60 = V_42 ;
V_9 -> V_58 [ V_7 ] . V_61 = 1 ;
V_9 -> V_58 [ V_7 ] . V_62 = V_54 ;
F_11 ( V_9 -> V_29 , L_4
L_5 ,
V_7 , V_9 -> V_58 [ V_7 ] . V_59 ,
V_9 -> V_58 [ V_7 ] . V_60 , V_9 -> V_58 [ V_7 ] . V_61 ,
V_9 -> V_58 [ V_7 ] . V_62 ) ;
V_7 ++ ;
}
}
V_42 = V_48 | V_49 | V_50 | V_51 | V_52 | V_55 ;
if ( V_28 -> V_35 && ( V_28 -> V_39 == V_63 ||
V_28 -> V_39 == V_64 ) ) {
V_9 -> V_58 [ V_7 ] . V_59 = F_21 ( V_9 -> V_29 , V_28 -> V_65 ,
V_54 , V_47 ) ;
V_9 -> V_58 [ V_7 ] . V_60 = V_42 ;
V_9 -> V_58 [ V_7 ] . V_61 = 1 ;
V_9 -> V_58 [ V_7 ] . V_62 = V_54 ;
F_11 ( V_9 -> V_29 , L_4
L_5 ,
V_7 , V_9 -> V_58 [ V_7 ] . V_59 ,
V_9 -> V_58 [ V_7 ] . V_60 , V_9 -> V_58 [ V_7 ] . V_61 ,
V_9 -> V_58 [ V_7 ] . V_62 ) ;
V_7 ++ ;
}
if ( V_7 == 0 )
return;
V_9 -> V_58 [ V_7 - 1 ] . V_60 &= ~ ( V_66 | V_67 ) ;
V_9 -> V_58 [ V_7 - 1 ] . V_60 |= V_68 ;
F_22 ( V_9 -> V_69 , ( unsigned long * ) V_9 -> V_70 ) ;
F_23 ( V_9 -> V_69 , 0 ) ;
F_24 ( V_9 -> V_69 , 0 ) ;
F_25 ( V_9 -> V_69 , V_42 ) ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_71 * V_72 , * V_73 ;
struct V_27 * V_28 ;
struct V_1 * V_3 ;
int V_74 = 0 ;
int V_75 , V_7 , V_41 ;
unsigned int V_76 ;
unsigned long V_77 ;
F_27 ( & V_9 -> V_31 , V_77 ) ;
if ( V_22 )
V_74 = F_28 ( & V_9 -> V_78 , V_22 ) ;
if ( V_9 -> V_79 ) {
F_29 ( & V_9 -> V_31 , V_77 ) ;
return V_74 ;
}
V_73 = F_30 ( & V_9 -> V_78 ) ;
V_72 = F_31 ( & V_9 -> V_78 ) ;
if ( V_72 )
V_9 -> V_79 = 1 ;
F_29 ( & V_9 -> V_31 , V_77 ) ;
if ( ! V_72 )
return V_74 ;
if ( V_73 )
V_73 -> V_80 ( V_73 , - V_81 ) ;
V_22 = F_32 ( V_72 ) ;
V_9 -> V_22 = V_22 ;
V_28 = F_10 ( V_22 ) ;
V_28 -> V_3 = NULL ;
V_28 -> V_37 = 0 ;
V_28 -> V_4 = 0 ;
F_11 ( V_9 -> V_29 , L_6 ,
V_28 -> V_39 , V_22 -> V_82 ) ;
if ( V_28 -> V_39 == V_64 ) {
if ( V_28 -> V_35 == 0 ) {
V_9 -> V_79 = 0 ;
return 0 ;
}
memset ( V_28 -> V_65 + V_28 -> V_35 , 0 ,
V_54 - V_28 -> V_35 ) ;
} else {
if ( V_28 -> V_35 + V_22 -> V_82 < V_54 ) {
memcpy ( V_28 -> V_65 + V_28 -> V_35 ,
F_33 ( V_22 -> V_32 ) , V_22 -> V_82 ) ;
V_28 -> V_35 += V_22 -> V_82 ;
if ( V_28 -> V_39 == V_63 &&
V_28 -> V_35 ) {
goto V_83;
} else {
V_9 -> V_79 = 0 ;
return 0 ;
}
}
if ( V_28 -> V_35 ) {
V_28 -> V_36 = V_28 -> V_35 ;
memcpy ( V_28 -> V_84 , V_28 -> V_65 , V_28 -> V_36 ) ;
V_75 = V_28 -> V_37 ? 2 : 1 ;
F_34 ( V_28 -> V_85 , V_75 ) ;
F_35 ( V_28 -> V_85 , V_28 -> V_84 , V_28 -> V_36 ) ;
if ( V_75 > 1 )
F_36 ( V_28 -> V_85 , V_75 ,
V_22 -> V_32 ) ;
V_28 -> V_3 = V_28 -> V_85 ;
} else
V_28 -> V_3 = V_22 -> V_32 ;
V_75 = V_28 -> V_4 = F_1 ( V_28 -> V_3 ) ;
V_28 -> V_37 = V_28 -> V_36 + V_22 -> V_82 ;
V_28 -> V_35 = V_28 -> V_37 % 4 ;
V_28 -> V_37 &= ~ 0x3 ;
if ( V_28 -> V_35 ) {
memset ( V_28 -> V_65 , 0 , V_54 ) ;
V_76 = V_28 -> V_35 ;
for ( V_7 = V_75 - 1 ; V_7 >= 0 ; V_7 -- ) {
V_3 = F_4 ( V_28 -> V_3 , V_75 , V_7 ) ;
V_41 = F_37 ( V_76 , F_20 ( V_3 ) ) ;
memcpy ( V_28 -> V_65 + V_76 - V_41 ,
F_33 ( V_3 ) + F_20 ( V_3 ) - V_41 , V_41 ) ;
if ( V_41 == F_20 ( V_3 ) )
V_28 -> V_4 -- ;
V_76 -= V_41 ;
if ( V_76 == 0 )
break;
}
}
}
V_83:
if ( V_28 -> V_35 && ( V_28 -> V_39 == V_63 ||
V_28 -> V_39 == V_64 ) )
V_28 -> V_37 += V_54 ;
V_9 -> V_11 -> V_86 = V_28 -> V_37 >> 2 ;
F_17 ( V_9 ) ;
V_9 -> V_11 -> V_13 |= V_87 ;
return - V_81 ;
}
static int F_38 ( struct V_21 * V_22 )
{
struct V_27 * V_28 = F_10 ( V_22 ) ;
if ( ! V_22 -> V_82 )
return 0 ;
F_11 ( V_28 -> V_9 -> V_29 , L_7 ) ;
V_28 -> V_38 += V_22 -> V_82 ;
V_28 -> V_39 = V_88 ;
return F_26 ( V_28 -> V_9 , V_22 ) ;
}
static int F_39 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_8 ( V_22 ) ;
struct V_25 * V_26 = F_9 ( V_24 ) ;
struct V_27 * V_28 = F_10 ( V_22 ) ;
F_11 ( V_28 -> V_9 -> V_29 , L_8 ) ;
V_28 -> V_39 = V_64 ;
V_26 -> V_10 = 0 ;
return F_26 ( V_28 -> V_9 , V_22 ) ;
}
static int F_40 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_8 ( V_22 ) ;
struct V_25 * V_26 = F_9 ( V_24 ) ;
struct V_27 * V_28 = F_10 ( V_22 ) ;
F_11 ( V_28 -> V_9 -> V_29 , L_9 ) ;
V_28 -> V_38 += V_22 -> V_82 ;
V_28 -> V_39 = V_63 ;
V_26 -> V_10 = 0 ;
return F_26 ( V_28 -> V_9 , V_22 ) ;
}
static int F_41 ( struct V_21 * V_22 )
{
int V_74 ;
V_74 = F_7 ( V_22 ) ;
if ( V_74 )
return V_74 ;
return F_40 ( V_22 ) ;
}
static int F_42 ( struct V_23 * V_24 , const T_2 * V_10 ,
unsigned int V_89 )
{
struct V_25 * V_26 = F_9 ( V_24 ) ;
F_11 ( V_26 -> V_9 -> V_29 , L_10 ) ;
if ( V_89 != V_54 ) {
F_43 ( V_24 , V_90 ) ;
return - V_34 ;
}
V_26 -> V_10 = F_44 ( V_10 ) ;
return 0 ;
}
static int F_45 ( struct V_91 * V_24 )
{
struct V_25 * V_26 = F_46 ( V_24 ) ;
V_26 -> V_10 = 0 ;
F_47 ( F_48 ( V_24 ) ,
sizeof( struct V_27 ) ) ;
return 0 ;
}
static void F_49 ( struct V_91 * V_24 )
{
}
static void F_50 ( unsigned long V_92 )
{
struct V_8 * V_9 = (struct V_8 * ) V_92 ;
F_26 ( V_9 , NULL ) ;
}
static T_3 F_51 ( int V_93 , void * V_94 )
{
struct V_8 * V_9 = V_94 ;
if ( V_9 -> V_11 -> V_17 & V_95 ) {
V_9 -> V_11 -> V_17 = V_95 ;
F_15 ( V_9 -> V_11 -> V_40 , V_9 -> V_22 -> V_40 ) ;
V_9 -> V_11 -> V_13 &= ~ V_87 ;
V_9 -> V_79 = 0 ;
if ( V_9 -> V_22 -> V_96 . V_80 )
V_9 -> V_22 -> V_96 . V_80 ( & V_9 -> V_22 -> V_96 , 0 ) ;
F_52 ( & V_9 -> V_97 ) ;
return V_98 ;
} else
return V_99 ;
}
static int F_53 ( struct V_100 * V_101 , T_4 V_102 )
{
struct V_8 * V_9 = F_54 ( V_101 ) ;
int V_7 = 100000 ;
while ( ( V_9 -> V_11 -> V_13 & V_87 ) && -- V_7 )
F_55 () ;
if ( V_7 == 0 )
return - V_103 ;
return 0 ;
}
static int F_56 ( struct V_100 * V_101 )
{
struct V_104 * V_29 = & V_101 -> V_29 ;
struct V_105 * V_106 ;
struct V_8 * V_9 ;
unsigned int V_107 = 100000 ;
int V_74 ;
V_9 = F_57 ( V_29 , sizeof( * V_9 ) , V_108 ) ;
if ( ! V_9 ) {
F_58 ( & V_101 -> V_29 , L_11 ) ;
return - V_109 ;
}
V_9 -> V_29 = V_29 ;
F_59 ( & V_9 -> V_110 ) ;
F_60 ( & V_9 -> V_31 ) ;
F_61 ( & V_9 -> V_97 , F_50 , ( unsigned long ) V_9 ) ;
F_62 ( & V_9 -> V_78 , V_111 ) ;
V_106 = F_63 ( V_101 , V_112 , 0 ) ;
if ( V_106 == NULL ) {
F_58 ( & V_101 -> V_29 , L_12 ) ;
return - V_113 ;
}
V_9 -> V_11 = F_64 ( V_29 , V_106 ) ;
if ( F_65 ( ( void * ) V_9 -> V_11 ) ) {
F_58 ( & V_101 -> V_29 , L_13 ) ;
return F_66 ( ( void * ) V_9 -> V_11 ) ;
}
V_9 -> V_93 = F_67 ( V_101 , 0 ) ;
if ( V_9 -> V_93 < 0 ) {
F_58 ( & V_101 -> V_29 , L_14 ) ;
return - V_113 ;
}
V_74 = F_68 ( V_29 , V_9 -> V_93 , F_51 ,
V_114 , F_69 ( V_29 ) , V_9 ) ;
if ( V_74 ) {
F_58 ( & V_101 -> V_29 , L_15 ) ;
return V_74 ;
}
V_106 = F_63 ( V_101 , V_115 , 0 ) ;
if ( V_106 == NULL ) {
F_58 ( & V_101 -> V_29 , L_16 ) ;
return - V_113 ;
}
V_9 -> V_69 = V_106 -> V_116 ;
V_74 = F_70 ( V_9 -> V_69 , F_69 ( V_29 ) ) ;
if ( V_74 ) {
F_58 ( & V_101 -> V_29 , L_17 ) ;
return V_74 ;
}
V_9 -> V_58 = F_71 ( & V_101 -> V_29 , V_117 , & V_9 -> V_70 , V_108 ) ;
if ( V_9 -> V_58 == NULL ) {
V_74 = - V_109 ;
goto V_118;
}
V_9 -> V_53 = ( T_2 * ) ( V_9 -> V_58 + ( ( V_33 + 1 ) << 1 ) ) ;
V_9 -> V_11 -> V_13 = 0 ;
V_9 -> V_11 -> V_119 = V_9 -> V_119 = ( T_1 ) V_101 -> V_29 . V_120 ;
while ( ! ( V_9 -> V_11 -> V_17 & V_121 ) && ( -- V_107 ) > 0 )
F_55 () ;
if ( V_107 == 0 )
F_72 ( & V_101 -> V_29 , L_18 ) ;
F_73 ( & V_30 . V_31 ) ;
F_74 ( & V_9 -> V_110 , & V_30 . V_122 ) ;
F_75 ( & V_30 . V_31 ) ;
F_76 ( V_101 , V_9 ) ;
V_74 = F_77 ( & V_123 ) ;
if ( V_74 ) {
F_73 ( & V_30 . V_31 ) ;
F_78 ( & V_9 -> V_110 ) ;
F_75 ( & V_30 . V_31 ) ;
F_58 ( & V_101 -> V_29 , L_19 ) ;
goto V_118;
}
F_72 ( & V_101 -> V_29 , L_20 ) ;
return 0 ;
V_118:
if ( V_9 -> V_58 )
F_79 ( & V_101 -> V_29 , V_117 , V_9 -> V_58 , V_9 -> V_70 ) ;
F_80 ( V_9 -> V_69 ) ;
return V_74 ;
}
static int F_81 ( struct V_100 * V_101 )
{
struct V_8 * V_9 = F_54 ( V_101 ) ;
if ( ! V_9 )
return - V_124 ;
F_73 ( & V_30 . V_31 ) ;
F_78 ( & V_9 -> V_110 ) ;
F_75 ( & V_30 . V_31 ) ;
F_82 ( & V_123 ) ;
F_83 ( & V_9 -> V_97 ) ;
F_80 ( V_9 -> V_69 ) ;
return 0 ;
}
static int T_5 F_84 ( void )
{
int V_74 ;
F_85 ( L_21 ) ;
F_59 ( & V_30 . V_122 ) ;
F_60 ( & V_30 . V_31 ) ;
V_74 = F_86 ( & V_125 ) ;
if ( V_74 ) {
F_85 ( V_126 L_22 ) ;
return V_74 ;
}
return 0 ;
}
static void T_6 F_87 ( void )
{
F_88 ( & V_125 ) ;
}
