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
F_7 () ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_22 ) ;
struct V_25 * V_26 = F_10 ( V_24 ) ;
struct V_27 * V_28 = F_11 ( V_22 ) ;
struct V_8 * V_9 ;
F_12 ( V_9 -> V_29 , L_1 ) ;
F_13 ( & V_30 . V_31 ) ;
F_14 (crc, &crc_list.dev_list, list) {
V_26 -> V_9 = V_9 ;
break;
}
F_15 ( & V_30 . V_31 ) ;
if ( F_1 ( V_22 -> V_32 ) > V_33 ) {
F_12 ( V_9 -> V_29 , L_2 ,
V_33 ) ;
return - V_34 ;
}
V_28 -> V_9 = V_9 ;
V_28 -> V_35 = 0 ;
V_28 -> V_36 = 0 ;
V_28 -> V_37 = 0 ;
V_28 -> V_38 = 0 ;
V_28 -> V_39 = 0 ;
F_16 ( V_26 -> V_10 , V_22 -> V_40 ) ;
F_12 ( V_9 -> V_29 , L_3 ,
F_17 ( V_24 ) ) ;
return F_6 ( V_9 , V_26 -> V_10 ) ;
}
static void F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_3 ;
struct V_27 * V_28 = F_11 ( V_9 -> V_22 ) ;
int V_7 = 0 , V_41 = 0 ;
unsigned long V_42 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 = 0 ;
int V_46 ;
F_19 ( V_9 -> V_29 , V_28 -> V_3 , V_28 -> V_4 , V_47 ) ;
F_5 (ctx->sg, sg, ctx->sg_nents, j) {
V_42 = V_48 | V_49 | V_50 | V_51 | V_52 ;
V_44 = F_20 ( V_3 ) ;
if ( F_2 ( V_3 ) )
V_43 = F_21 ( V_3 ) - V_28 -> V_35 ;
else
V_43 = F_21 ( V_3 ) ;
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
F_12 ( V_9 -> V_29 , L_4
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
V_9 -> V_58 [ V_7 ] . V_59 = F_22 ( V_9 -> V_29 ,
V_9 -> V_53 + ( V_7 << 2 ) ,
V_54 , V_47 ) ;
V_9 -> V_58 [ V_7 ] . V_60 = V_42 ;
V_9 -> V_58 [ V_7 ] . V_61 = 1 ;
V_9 -> V_58 [ V_7 ] . V_62 = V_54 ;
F_12 ( V_9 -> V_29 , L_4
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
V_9 -> V_58 [ V_7 ] . V_59 = F_22 ( V_9 -> V_29 , V_28 -> V_65 ,
V_54 , V_47 ) ;
V_9 -> V_58 [ V_7 ] . V_60 = V_42 ;
V_9 -> V_58 [ V_7 ] . V_61 = 1 ;
V_9 -> V_58 [ V_7 ] . V_62 = V_54 ;
F_12 ( V_9 -> V_29 , L_4
L_5 ,
V_7 , V_9 -> V_58 [ V_7 ] . V_59 ,
V_9 -> V_58 [ V_7 ] . V_60 , V_9 -> V_58 [ V_7 ] . V_61 ,
V_9 -> V_58 [ V_7 ] . V_62 ) ;
V_7 ++ ;
}
if ( V_7 == 0 )
return;
F_23 ( ( unsigned int ) V_9 -> V_58 ,
( unsigned int ) V_9 -> V_58 +
V_7 * sizeof( struct V_66 ) ) ;
V_9 -> V_58 [ V_7 - 1 ] . V_60 &= ~ ( V_67 | V_68 ) ;
V_9 -> V_58 [ V_7 - 1 ] . V_60 |= V_69 ;
F_24 ( V_9 -> V_70 , ( unsigned long * ) V_9 -> V_71 ) ;
F_25 ( V_9 -> V_70 , 0 ) ;
F_26 ( V_9 -> V_70 , 0 ) ;
F_7 () ;
F_27 ( V_9 -> V_70 , V_42 ) ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_72 * V_73 , * V_74 ;
struct V_27 * V_28 ;
struct V_1 * V_3 ;
int V_75 = 0 ;
int V_76 , V_7 , V_41 ;
unsigned int V_77 ;
unsigned long V_78 ;
F_29 ( & V_9 -> V_31 , V_78 ) ;
if ( V_22 )
V_75 = F_30 ( & V_9 -> V_79 , V_22 ) ;
if ( V_9 -> V_80 ) {
F_31 ( & V_9 -> V_31 , V_78 ) ;
return V_75 ;
}
V_74 = F_32 ( & V_9 -> V_79 ) ;
V_73 = F_33 ( & V_9 -> V_79 ) ;
if ( V_73 )
V_9 -> V_80 = 1 ;
F_31 ( & V_9 -> V_31 , V_78 ) ;
if ( ! V_73 )
return V_75 ;
if ( V_74 )
V_74 -> V_81 ( V_74 , - V_82 ) ;
V_22 = F_34 ( V_73 ) ;
V_9 -> V_22 = V_22 ;
V_28 = F_11 ( V_22 ) ;
V_28 -> V_3 = NULL ;
V_28 -> V_37 = 0 ;
V_28 -> V_4 = 0 ;
F_12 ( V_9 -> V_29 , L_6 ,
V_28 -> V_39 , V_22 -> V_83 ) ;
if ( V_28 -> V_39 == V_64 ) {
if ( V_28 -> V_35 == 0 ) {
V_9 -> V_80 = 0 ;
return 0 ;
}
memset ( V_28 -> V_65 + V_28 -> V_35 , 0 ,
V_54 - V_28 -> V_35 ) ;
} else {
if ( V_28 -> V_35 + V_22 -> V_83 < V_54 ) {
memcpy ( V_28 -> V_65 + V_28 -> V_35 ,
F_35 ( V_22 -> V_32 ) , V_22 -> V_83 ) ;
V_28 -> V_35 += V_22 -> V_83 ;
if ( V_28 -> V_39 == V_63 &&
V_28 -> V_35 ) {
goto V_84;
} else {
V_9 -> V_80 = 0 ;
return 0 ;
}
}
if ( V_28 -> V_35 ) {
V_28 -> V_36 = V_28 -> V_35 ;
memcpy ( V_28 -> V_85 , V_28 -> V_65 , V_28 -> V_36 ) ;
V_76 = V_28 -> V_37 ? 2 : 1 ;
F_36 ( V_28 -> V_86 , V_76 ) ;
F_37 ( V_28 -> V_86 , V_28 -> V_85 , V_28 -> V_36 ) ;
if ( V_76 > 1 )
F_38 ( V_28 -> V_86 , V_76 ,
V_22 -> V_32 ) ;
V_28 -> V_3 = V_28 -> V_86 ;
} else
V_28 -> V_3 = V_22 -> V_32 ;
V_76 = V_28 -> V_4 = F_1 ( V_28 -> V_3 ) ;
V_28 -> V_37 = V_28 -> V_36 + V_22 -> V_83 ;
V_28 -> V_35 = V_28 -> V_37 % 4 ;
V_28 -> V_37 &= ~ 0x3 ;
if ( V_28 -> V_35 ) {
memset ( V_28 -> V_65 , 0 , V_54 ) ;
V_77 = V_28 -> V_35 ;
for ( V_7 = V_76 - 1 ; V_7 >= 0 ; V_7 -- ) {
V_3 = F_4 ( V_28 -> V_3 , V_76 , V_7 ) ;
V_41 = F_39 ( V_77 , F_21 ( V_3 ) ) ;
memcpy ( V_28 -> V_65 + V_77 - V_41 ,
F_35 ( V_3 ) + F_21 ( V_3 ) - V_41 , V_41 ) ;
if ( V_41 == F_21 ( V_3 ) )
V_28 -> V_4 -- ;
V_77 -= V_41 ;
if ( V_77 == 0 )
break;
}
}
}
V_84:
if ( V_28 -> V_35 && ( V_28 -> V_39 == V_63 ||
V_28 -> V_39 == V_64 ) )
V_28 -> V_37 += V_54 ;
V_9 -> V_11 -> V_87 = V_28 -> V_37 >> 2 ;
F_18 ( V_9 ) ;
V_9 -> V_11 -> V_13 |= V_88 ;
F_7 () ;
return - V_82 ;
}
static int F_40 ( struct V_21 * V_22 )
{
struct V_27 * V_28 = F_11 ( V_22 ) ;
if ( ! V_22 -> V_83 )
return 0 ;
F_12 ( V_28 -> V_9 -> V_29 , L_7 ) ;
V_28 -> V_38 += V_22 -> V_83 ;
V_28 -> V_39 = V_89 ;
return F_28 ( V_28 -> V_9 , V_22 ) ;
}
static int F_41 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_22 ) ;
struct V_25 * V_26 = F_10 ( V_24 ) ;
struct V_27 * V_28 = F_11 ( V_22 ) ;
F_12 ( V_28 -> V_9 -> V_29 , L_8 ) ;
V_28 -> V_39 = V_64 ;
V_26 -> V_10 = 0 ;
return F_28 ( V_28 -> V_9 , V_22 ) ;
}
static int F_42 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_22 ) ;
struct V_25 * V_26 = F_10 ( V_24 ) ;
struct V_27 * V_28 = F_11 ( V_22 ) ;
F_12 ( V_28 -> V_9 -> V_29 , L_9 ) ;
V_28 -> V_38 += V_22 -> V_83 ;
V_28 -> V_39 = V_63 ;
V_26 -> V_10 = 0 ;
return F_28 ( V_28 -> V_9 , V_22 ) ;
}
static int F_43 ( struct V_21 * V_22 )
{
int V_75 ;
V_75 = F_8 ( V_22 ) ;
if ( V_75 )
return V_75 ;
return F_42 ( V_22 ) ;
}
static int F_44 ( struct V_23 * V_24 , const T_2 * V_10 ,
unsigned int V_90 )
{
struct V_25 * V_26 = F_10 ( V_24 ) ;
F_12 ( V_26 -> V_9 -> V_29 , L_10 ) ;
if ( V_90 != V_54 ) {
F_45 ( V_24 , V_91 ) ;
return - V_34 ;
}
V_26 -> V_10 = F_46 ( V_10 ) ;
return 0 ;
}
static int F_47 ( struct V_92 * V_24 )
{
struct V_25 * V_26 = F_48 ( V_24 ) ;
V_26 -> V_10 = 0 ;
F_49 ( F_50 ( V_24 ) ,
sizeof( struct V_27 ) ) ;
return 0 ;
}
static void F_51 ( struct V_92 * V_24 )
{
}
static void F_52 ( unsigned long V_93 )
{
struct V_8 * V_9 = (struct V_8 * ) V_93 ;
F_28 ( V_9 , NULL ) ;
}
static T_3 F_53 ( int V_94 , void * V_95 )
{
struct V_8 * V_9 = V_95 ;
if ( V_9 -> V_11 -> V_17 & V_96 ) {
V_9 -> V_11 -> V_17 = V_96 ;
F_7 () ;
F_16 ( V_9 -> V_11 -> V_40 , V_9 -> V_22 -> V_40 ) ;
V_9 -> V_11 -> V_13 &= ~ V_88 ;
V_9 -> V_80 = 0 ;
if ( V_9 -> V_22 -> V_97 . V_81 )
V_9 -> V_22 -> V_97 . V_81 ( & V_9 -> V_22 -> V_97 , 0 ) ;
F_54 ( & V_9 -> V_98 ) ;
return V_99 ;
} else
return V_100 ;
}
static int F_55 ( struct V_101 * V_102 , T_4 V_103 )
{
struct V_8 * V_9 = F_56 ( V_102 ) ;
int V_7 = 100000 ;
while ( ( V_9 -> V_11 -> V_13 & V_88 ) && -- V_7 )
F_57 () ;
if ( V_7 == 0 )
return - V_104 ;
return 0 ;
}
static int F_58 ( struct V_101 * V_102 )
{
struct V_105 * V_29 = & V_102 -> V_29 ;
struct V_106 * V_107 ;
struct V_8 * V_9 ;
unsigned int V_108 = 100000 ;
int V_75 ;
V_9 = F_59 ( sizeof( * V_9 ) , V_109 ) ;
if ( ! V_9 ) {
F_60 ( & V_102 -> V_29 , L_11 ) ;
return - V_110 ;
}
V_9 -> V_29 = V_29 ;
F_61 ( & V_9 -> V_111 ) ;
F_62 ( & V_9 -> V_31 ) ;
F_63 ( & V_9 -> V_98 , F_52 , ( unsigned long ) V_9 ) ;
F_64 ( & V_9 -> V_79 , V_112 ) ;
V_107 = F_65 ( V_102 , V_113 , 0 ) ;
if ( V_107 == NULL ) {
F_60 ( & V_102 -> V_29 , L_12 ) ;
V_75 = - V_114 ;
goto V_115;
}
V_9 -> V_11 = F_66 ( V_107 -> V_116 , F_67 ( V_107 ) ) ;
if ( ! V_9 -> V_11 ) {
F_60 ( & V_102 -> V_29 , L_13 ) ;
V_75 = - V_117 ;
goto V_115;
}
V_9 -> V_94 = F_68 ( V_102 , 0 ) ;
if ( V_9 -> V_94 < 0 ) {
F_60 ( & V_102 -> V_29 , L_14 ) ;
V_75 = - V_114 ;
goto V_118;
}
V_75 = F_69 ( V_9 -> V_94 , F_53 , V_119 , F_70 ( V_29 ) , V_9 ) ;
if ( V_75 ) {
F_60 ( & V_102 -> V_29 , L_15 ) ;
goto V_118;
}
V_107 = F_65 ( V_102 , V_120 , 0 ) ;
if ( V_107 == NULL ) {
F_60 ( & V_102 -> V_29 , L_16 ) ;
V_75 = - V_114 ;
goto V_121;
}
V_9 -> V_70 = V_107 -> V_116 ;
V_75 = F_71 ( V_9 -> V_70 , F_70 ( V_29 ) ) ;
if ( V_75 ) {
F_60 ( & V_102 -> V_29 , L_17 ) ;
goto V_121;
}
V_9 -> V_58 = F_72 ( & V_102 -> V_29 , V_122 , & V_9 -> V_71 , V_109 ) ;
if ( V_9 -> V_58 == NULL ) {
V_75 = - V_110 ;
goto V_123;
}
V_9 -> V_53 = ( T_2 * ) ( V_9 -> V_58 + ( ( V_33 + 1 ) << 1 ) ) ;
V_9 -> V_11 -> V_13 = 0 ;
F_7 () ;
V_9 -> V_11 -> V_124 = V_9 -> V_124 = ( T_1 ) V_102 -> V_29 . V_125 ;
F_7 () ;
while ( ! ( V_9 -> V_11 -> V_17 & V_126 ) && ( -- V_108 ) > 0 )
F_57 () ;
if ( V_108 == 0 )
F_73 ( & V_102 -> V_29 , L_18 ) ;
F_74 ( & V_30 . V_31 ) ;
F_75 ( & V_9 -> V_111 , & V_30 . V_127 ) ;
F_76 ( & V_30 . V_31 ) ;
F_77 ( V_102 , V_9 ) ;
V_75 = F_78 ( & V_128 ) ;
if ( V_75 ) {
F_74 ( & V_30 . V_31 ) ;
F_79 ( & V_9 -> V_111 ) ;
F_76 ( & V_30 . V_31 ) ;
F_60 ( & V_102 -> V_29 , L_19 ) ;
goto V_123;
}
F_73 ( & V_102 -> V_29 , L_20 ) ;
return 0 ;
V_123:
if ( V_9 -> V_58 )
F_80 ( & V_102 -> V_29 , V_122 , V_9 -> V_58 , V_9 -> V_71 ) ;
F_81 ( V_9 -> V_70 ) ;
V_121:
F_82 ( V_9 -> V_94 , V_9 ) ;
V_118:
F_83 ( ( void * ) V_9 -> V_11 ) ;
V_115:
F_84 ( V_9 ) ;
return V_75 ;
}
static int F_85 ( struct V_101 * V_102 )
{
struct V_8 * V_9 = F_56 ( V_102 ) ;
if ( ! V_9 )
return - V_129 ;
F_74 ( & V_30 . V_31 ) ;
F_79 ( & V_9 -> V_111 ) ;
F_76 ( & V_30 . V_31 ) ;
F_86 ( & V_128 ) ;
F_87 ( & V_9 -> V_98 ) ;
F_81 ( V_9 -> V_70 ) ;
if ( V_9 -> V_94 > 0 )
F_82 ( V_9 -> V_94 , V_9 ) ;
F_83 ( ( void * ) V_9 -> V_11 ) ;
F_84 ( V_9 ) ;
return 0 ;
}
static int T_5 F_88 ( void )
{
int V_75 ;
F_89 ( L_21 ) ;
F_61 ( & V_30 . V_127 ) ;
F_62 ( & V_30 . V_31 ) ;
V_75 = F_90 ( & V_130 ) ;
if ( V_75 ) {
F_89 ( V_131 L_22 ) ;
return V_75 ;
}
return 0 ;
}
static void T_6 F_91 ( void )
{
F_92 ( & V_130 ) ;
}
