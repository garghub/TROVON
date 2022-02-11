static inline void
F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_2
F_3 ( const struct V_1 * V_6 , T_1 V_3 )
{
return F_4 ( V_6 -> V_5 + V_3 ) ;
}
static inline void
F_5 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1
F_7 ( const struct V_1 * V_6 , T_1 V_3 )
{
return F_8 ( V_6 -> V_5 + V_3 ) ;
}
static int F_9 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
int V_8 ;
V_8 = F_10 ( V_2 -> V_9 ) ;
if ( V_8 )
return V_8 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 |= V_11 ;
F_1 ( V_2 , V_10 , V_7 ) ;
return 0 ;
}
static void F_11 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 &= ~ V_11 ;
F_1 ( V_2 , V_10 , V_7 ) ;
F_12 ( V_2 -> V_9 ) ;
}
static void F_13 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 |= ( V_12 | V_13 | V_14 ) ;
F_1 ( V_2 , V_10 , V_7 ) ;
}
static void F_14 ( const struct V_1 * V_2 )
{
T_2 V_7 ;
V_7 = F_3 ( V_2 , V_10 ) ;
V_7 &= ~ ( V_12 | V_13 | V_14 ) ;
F_1 ( V_2 , V_10 , V_7 ) ;
}
static int F_15 ( const struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned long V_17 )
{
unsigned long V_18 = F_16 ( V_2 -> V_9 ) ;
int V_19 , V_20 ;
V_17 = F_17 ( V_17 , V_2 -> V_21 , V_2 -> V_22 ) ;
for ( V_19 = 2 ; V_19 <= 254 ; V_19 += 2 ) {
for ( V_20 = 0 ; V_20 <= 255 ; V_20 ++ ) {
if ( ( V_18 / ( V_19 * ( V_20 + 1 ) ) ) <= V_17 ) {
V_16 -> V_23 = ( T_2 ) V_20 ;
V_16 -> V_24 = ( T_2 ) V_19 ;
return 0 ;
}
}
}
return - V_25 ;
}
static void F_18 ( struct V_26 * V_6 , bool V_27 )
{
struct V_15 * V_16 = F_19 ( V_6 ) ;
int V_4 = ( V_6 -> V_28 & V_29 ) ? V_27 : ! V_27 ;
if ( V_16 -> V_30 && V_16 -> V_30 -> V_31 )
V_16 -> V_30 -> V_31 ( V_6 , V_4 ) ;
}
static int F_20 ( struct V_26 * V_6 )
{
struct V_1 * V_2 = F_21 ( V_6 -> V_32 ) ;
struct V_15 * V_16 ;
if ( V_6 -> V_33 < 4 || V_6 -> V_33 > 16 ) {
F_22 ( & V_2 -> V_34 -> V_35 , L_1 ,
V_6 -> V_33 ) ;
return - V_25 ;
}
V_16 = F_19 ( V_6 ) ;
if ( ! V_16 ) {
F_23 ( & V_2 -> V_34 -> V_35 , L_2 ,
V_6 -> V_36 ) ;
V_16 = F_24 ( sizeof( * V_16 ) , V_37 ) ;
if ( ! V_16 )
return - V_38 ;
V_16 -> V_6 = V_6 ;
V_16 -> V_30 = V_6 -> V_39 ;
if ( V_16 -> V_30 && V_16 -> V_30 -> V_40 ) {
int V_41 = V_16 -> V_30 -> V_40 ( V_6 ) ;
if ( V_41 ) {
F_25 ( V_16 ) ;
return V_41 ;
}
}
F_26 ( V_6 , V_16 ) ;
}
if ( V_6 -> V_42 != V_16 -> V_17 ) {
int V_8 ;
V_8 = F_15 ( V_2 , V_16 , V_6 -> V_42 ) ;
if ( V_8 != 0 ) {
F_26 ( V_6 , NULL ) ;
F_25 ( V_16 ) ;
return V_8 ;
}
V_16 -> V_17 = V_6 -> V_42 ;
}
V_16 -> V_43 = F_27 ( V_6 -> V_33 ) ;
F_18 ( V_6 , false ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_6 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_6 -> V_32 ) ;
struct V_46 * V_47 ;
unsigned long V_48 ;
if ( ! V_45 || ! V_45 -> V_49 )
return - V_25 ;
F_29 (t, &msg->transfers, transfer_list) {
if ( V_47 -> V_33 ) {
if ( V_47 -> V_33 < 4 || V_47 -> V_33 > 16 )
return - V_25 ;
}
if ( V_47 -> V_50 && V_47 -> V_50 < V_2 -> V_21 )
return - V_25 ;
}
V_45 -> V_51 = NULL ;
V_45 -> V_52 = 0 ;
V_45 -> V_53 = 0 ;
F_30 ( & V_2 -> V_54 , V_48 ) ;
if ( ! V_2 -> V_55 ) {
F_31 ( & V_2 -> V_54 , V_48 ) ;
return - V_56 ;
}
F_32 ( & V_45 -> V_57 , & V_2 -> V_58 ) ;
F_33 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_31 ( & V_2 -> V_54 , V_48 ) ;
return 0 ;
}
static void F_34 ( struct V_26 * V_6 )
{
struct V_15 * V_16 ;
V_16 = F_19 ( V_6 ) ;
if ( V_16 ) {
if ( V_16 -> V_30 && V_16 -> V_30 -> V_61 )
V_16 -> V_30 -> V_61 ( V_6 ) ;
F_26 ( V_6 , NULL ) ;
F_25 ( V_16 ) ;
}
}
static void F_35 ( const struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
T_1 V_62 ;
V_62 = V_16 -> V_23 << V_63 ;
V_62 |= ( V_16 -> V_6 -> V_28 & ( V_64 | V_65 ) ) << V_66 ;
V_62 |= V_16 -> V_43 ;
F_23 ( & V_2 -> V_34 -> V_35 , L_3 ,
V_16 -> V_6 -> V_28 , V_16 -> V_24 , V_16 -> V_23 , V_16 -> V_43 ) ;
F_23 ( & V_2 -> V_34 -> V_35 , L_4 , V_62 ) ;
F_1 ( V_2 , V_67 , V_16 -> V_24 ) ;
F_5 ( V_2 , V_68 , V_62 ) ;
}
static inline int V_33 ( const struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_46 * V_47 = V_45 -> V_51 ;
return V_47 -> V_33 ? V_47 -> V_33 : V_45 -> V_6 -> V_33 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( V_33 ( V_2 ) > 8 ) {
T_1 V_70 = 0 ;
if ( V_47 -> V_71 )
V_70 = ( ( T_1 * ) V_47 -> V_71 ) [ V_2 -> V_72 ] ;
F_5 ( V_2 , V_73 , V_70 ) ;
V_2 -> V_72 += sizeof( V_70 ) ;
} else {
T_2 V_70 = 0 ;
if ( V_47 -> V_71 )
V_70 = ( ( T_2 * ) V_47 -> V_71 ) [ V_2 -> V_72 ] ;
F_1 ( V_2 , V_73 , V_70 ) ;
V_2 -> V_72 += sizeof( V_70 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
if ( V_33 ( V_2 ) > 8 ) {
T_1 V_74 ;
V_74 = F_7 ( V_2 , V_73 ) ;
if ( V_47 -> V_75 )
( ( T_1 * ) V_47 -> V_75 ) [ V_2 -> V_76 ] = V_74 ;
V_2 -> V_76 += sizeof( V_74 ) ;
} else {
T_2 V_74 ;
V_74 = F_3 ( V_2 , V_73 ) ;
if ( V_47 -> V_75 )
( ( T_2 * ) V_47 -> V_75 ) [ V_2 -> V_76 ] = V_74 ;
V_2 -> V_76 += sizeof( V_74 ) ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_69 ;
struct V_46 * V_47 = V_45 -> V_51 ;
while ( ( F_3 ( V_2 , V_77 ) & V_78 ) ) {
F_37 ( V_2 , V_47 ) ;
V_2 -> V_79 -- ;
}
while ( V_2 -> V_79 < V_80 && V_2 -> V_72 < V_47 -> V_81 ) {
F_36 ( V_2 , V_47 ) ;
V_2 -> V_79 ++ ;
}
if ( V_2 -> V_76 == V_47 -> V_81 ) {
V_45 -> V_53 += V_47 -> V_81 ;
return 0 ;
}
return - V_82 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_15 * V_16 = F_19 ( V_45 -> V_6 ) ;
V_45 -> V_51 = V_47 ;
if ( V_47 -> V_50 || V_47 -> V_33 ) {
struct V_15 V_83 = * V_16 ;
if ( V_47 -> V_50 ) {
int V_8 ;
V_8 = F_15 ( V_2 , & V_83 ,
V_47 -> V_50 ) ;
if ( V_8 ) {
F_22 ( & V_2 -> V_34 -> V_35 ,
L_5 ) ;
V_45 -> V_52 = V_8 ;
return;
}
}
if ( V_47 -> V_33 )
V_83 . V_43 = F_27 ( V_47 -> V_33 ) ;
F_35 ( V_2 , & V_83 ) ;
}
V_2 -> V_76 = 0 ;
V_2 -> V_72 = 0 ;
if ( F_38 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_40 ( & V_2 -> V_84 ) ;
}
if ( V_45 -> V_52 )
return;
if ( V_47 -> V_85 ) {
F_41 ( V_86 ) ;
F_42 ( F_43 ( V_47 -> V_85 ) ) ;
}
if ( V_47 -> V_87 ) {
if ( ! F_44 ( & V_47 -> V_88 , & V_45 -> V_89 ) ) {
F_18 ( V_45 -> V_6 , false ) ;
F_45 () ;
F_18 ( V_45 -> V_6 , true ) ;
}
}
if ( V_47 -> V_50 || V_47 -> V_33 )
F_35 ( V_2 , V_16 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
unsigned long V_90 ;
struct V_46 * V_47 ;
int V_8 ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 ) {
F_22 ( & V_2 -> V_34 -> V_35 , L_6 ) ;
V_45 -> V_52 = V_8 ;
return;
}
V_90 = V_91 + F_47 ( V_92 ) ;
while ( F_7 ( V_2 , V_77 ) & V_78 ) {
if ( F_48 ( V_91 , V_90 ) ) {
F_49 ( & V_2 -> V_34 -> V_35 ,
L_7 ) ;
V_45 -> V_52 = - V_93 ;
return;
}
F_7 ( V_2 , V_73 ) ;
}
V_2 -> V_79 = 0 ;
F_35 ( V_2 , F_19 ( V_45 -> V_6 ) ) ;
F_18 ( V_45 -> V_6 , true ) ;
F_29 (t, &msg->transfers, transfer_list) {
F_39 ( V_2 , V_45 , V_47 ) ;
if ( V_45 -> V_52 )
break;
}
F_18 ( V_45 -> V_6 , false ) ;
F_11 ( V_2 ) ;
}
static void F_50 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_51 ( V_95 ) ;
struct V_44 * V_45 ;
F_52 ( & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 || V_2 -> V_69 ||
F_53 ( & V_2 -> V_58 ) ) {
F_54 ( & V_2 -> V_54 ) ;
return;
}
V_45 = F_55 ( & V_2 -> V_58 , struct V_44 , V_57 ) ;
F_56 ( & V_45 -> V_57 ) ;
V_2 -> V_69 = V_45 ;
F_54 ( & V_2 -> V_54 ) ;
F_46 ( V_2 , V_45 ) ;
F_52 ( & V_2 -> V_54 ) ;
V_2 -> V_69 = NULL ;
if ( V_2 -> V_55 && ! F_53 ( & V_2 -> V_58 ) )
F_33 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_54 ( & V_2 -> V_54 ) ;
V_45 -> V_49 ( V_45 -> V_96 ) ;
}
static T_3 F_57 ( int V_97 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
T_2 V_99 = F_3 ( V_2 , V_100 ) ;
if ( F_58 ( V_99 & V_101 ) ) {
F_1 ( V_2 , V_102 , 0 ) ;
F_49 ( & V_2 -> V_34 -> V_35 ,
L_8 ) ;
V_2 -> V_69 -> V_52 = - V_103 ;
} else {
if ( F_38 ( V_2 ) ) {
return V_104 ;
}
}
F_14 ( V_2 ) ;
V_49 ( & V_2 -> V_84 ) ;
return V_104 ;
}
static int T_4 F_59 ( struct V_105 * V_34 )
{
struct V_106 * V_32 ;
struct V_107 * V_108 ;
struct V_1 * V_2 ;
struct V_109 * V_110 ;
int error ;
V_108 = V_34 -> V_35 . V_111 ;
V_32 = F_60 ( & V_34 -> V_35 , sizeof( * V_2 ) ) ;
if ( ! V_32 ) {
F_22 ( & V_34 -> V_35 , L_9 ) ;
return - V_38 ;
}
V_32 -> V_40 = F_20 ;
V_32 -> V_112 = F_28 ;
V_32 -> V_61 = F_34 ;
V_32 -> V_113 = V_34 -> V_114 ;
V_32 -> V_115 = V_108 -> V_115 ;
V_32 -> V_116 = V_65 | V_64 | V_29 ;
F_61 ( V_34 , V_32 ) ;
V_2 = F_21 ( V_32 ) ;
V_2 -> V_9 = F_62 ( & V_34 -> V_35 , NULL ) ;
if ( F_63 ( V_2 -> V_9 ) ) {
F_22 ( & V_34 -> V_35 , L_10 ) ;
error = F_64 ( V_2 -> V_9 ) ;
goto V_117;
}
F_65 ( & V_2 -> V_54 ) ;
F_66 ( & V_2 -> V_84 ) ;
V_2 -> V_22 = F_16 ( V_2 -> V_9 ) / 2 ;
V_2 -> V_21 = F_16 ( V_2 -> V_9 ) / ( 254 * 256 ) ;
V_2 -> V_34 = V_34 ;
V_2 -> V_97 = F_67 ( V_34 , 0 ) ;
if ( V_2 -> V_97 < 0 ) {
error = - V_118 ;
F_22 ( & V_34 -> V_35 , L_11 ) ;
goto V_119;
}
V_110 = F_68 ( V_34 , V_120 , 0 ) ;
if ( ! V_110 ) {
F_22 ( & V_34 -> V_35 , L_12 ) ;
error = - V_121 ;
goto V_119;
}
V_110 = F_69 ( V_110 -> V_122 , F_70 ( V_110 ) , V_34 -> V_123 ) ;
if ( ! V_110 ) {
F_22 ( & V_34 -> V_35 , L_13 ) ;
error = - V_118 ;
goto V_119;
}
V_2 -> V_5 = F_71 ( V_110 -> V_122 , F_70 ( V_110 ) ) ;
if ( ! V_2 -> V_5 ) {
F_22 ( & V_34 -> V_35 , L_14 ) ;
error = - V_121 ;
goto V_124;
}
error = F_72 ( V_2 -> V_97 , F_57 , 0 ,
L_15 , V_2 ) ;
if ( error ) {
F_22 ( & V_34 -> V_35 , L_16 ) ;
goto V_125;
}
V_2 -> V_59 = F_73 ( L_17 ) ;
if ( ! V_2 -> V_59 ) {
F_22 ( & V_34 -> V_35 , L_18 ) ;
goto V_126;
}
F_74 ( & V_2 -> V_60 , F_50 ) ;
F_75 ( & V_2 -> V_58 ) ;
V_2 -> V_55 = true ;
F_1 ( V_2 , V_10 , 0 ) ;
error = F_76 ( V_32 ) ;
if ( error ) {
F_22 ( & V_34 -> V_35 , L_19 ) ;
goto V_127;
}
F_77 ( & V_34 -> V_35 , L_20 ,
( unsigned long ) V_110 -> V_122 , V_2 -> V_97 ) ;
return 0 ;
V_127:
F_78 ( V_2 -> V_59 ) ;
V_126:
F_79 ( V_2 -> V_97 , V_2 ) ;
V_125:
F_80 ( V_2 -> V_5 ) ;
V_124:
F_81 ( V_110 -> V_122 , F_70 ( V_110 ) ) ;
V_119:
F_82 ( V_2 -> V_9 ) ;
V_117:
F_83 ( V_32 ) ;
F_61 ( V_34 , NULL ) ;
return error ;
}
static int T_5 F_84 ( struct V_105 * V_34 )
{
struct V_106 * V_32 = F_85 ( V_34 ) ;
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_109 * V_110 ;
F_52 ( & V_2 -> V_54 ) ;
V_2 -> V_55 = false ;
F_54 ( & V_2 -> V_54 ) ;
F_78 ( V_2 -> V_59 ) ;
F_52 ( & V_2 -> V_54 ) ;
while ( ! F_53 ( & V_2 -> V_58 ) ) {
struct V_44 * V_45 ;
V_45 = F_55 ( & V_2 -> V_58 ,
struct V_44 , V_57 ) ;
F_56 ( & V_45 -> V_57 ) ;
V_45 -> V_52 = - V_56 ;
F_54 ( & V_2 -> V_54 ) ;
V_45 -> V_49 ( V_45 -> V_96 ) ;
F_52 ( & V_2 -> V_54 ) ;
}
F_54 ( & V_2 -> V_54 ) ;
F_79 ( V_2 -> V_97 , V_2 ) ;
F_80 ( V_2 -> V_5 ) ;
V_110 = F_68 ( V_34 , V_120 , 0 ) ;
F_81 ( V_110 -> V_122 , F_70 ( V_110 ) ) ;
F_82 ( V_2 -> V_9 ) ;
F_61 ( V_34 , NULL ) ;
F_86 ( V_32 ) ;
return 0 ;
}
static int T_4 F_87 ( void )
{
return F_88 ( & V_128 , F_59 ) ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_128 ) ;
}
