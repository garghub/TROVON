static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 )
{
struct V_6 V_7 [ 2 ] ;
struct V_8 V_9 ;
T_3 V_10 ;
V_10 = F_2 ( V_3 << 8 | V_11 ) ;
F_3 ( & V_9 ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_7 [ 0 ] . V_12 = & V_10 ;
V_7 [ 0 ] . V_5 = sizeof( V_10 ) ;
F_4 ( & V_7 [ 0 ] , & V_9 ) ;
V_7 [ 1 ] . V_13 = V_4 ;
V_7 [ 1 ] . V_5 = V_5 ;
F_4 ( & V_7 [ 1 ] , & V_9 ) ;
F_5 ( V_2 -> V_14 , & V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
const void * V_4 , T_2 V_5 )
{
struct V_6 V_7 [ 3 ] ;
struct V_8 V_9 ;
T_3 V_10 ;
V_10 = F_2 ( V_3 << 8 ) ;
F_3 ( & V_9 ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_7 [ 0 ] . V_12 = & V_10 ;
V_7 [ 0 ] . V_5 = sizeof( V_10 ) ;
F_4 ( & V_7 [ 0 ] , & V_9 ) ;
V_7 [ 1 ] . V_12 = V_4 ;
V_7 [ 1 ] . V_5 = V_5 & ~ 1 ;
F_4 ( & V_7 [ 1 ] , & V_9 ) ;
if ( V_5 % 2 ) {
T_3 V_15 ;
V_15 = F_2 ( ( ( T_1 * ) V_4 ) [ V_5 - 1 ] ) ;
V_7 [ 2 ] . V_12 = & V_15 ;
V_7 [ 2 ] . V_5 = sizeof( V_15 ) ;
F_4 ( & V_7 [ 2 ] , & V_9 ) ;
}
F_5 ( V_2 -> V_14 , & V_9 ) ;
}
static T_4 F_7 ( struct V_1 * V_2 , T_1 V_10 )
{
T_5 V_16 ;
F_1 ( V_2 , V_10 , & V_16 , sizeof( V_16 ) ) ;
return F_8 ( V_16 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_10 , T_3 V_16 )
{
F_6 ( V_2 , V_10 , & V_16 , sizeof( V_16 ) ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_10 , T_5 V_16 )
{
F_6 ( V_2 , V_10 , & V_16 , sizeof( V_16 ) ) ;
}
static int F_11 ( struct V_1 * V_2 , T_6 V_17 , T_4 V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < 2000 ; V_19 ++ ) {
T_4 V_20 = F_7 ( V_2 , V_17 ) ;
if ( ( V_20 & V_18 ) == V_18 )
return 1 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_5 V_21 ,
const void * V_4 , T_2 V_5 )
{
if ( ! F_11 ( V_2 , V_22 , V_23 ) ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_1
L_2 ) ;
return - V_25 ;
}
F_9 ( V_2 , V_22 ,
F_2 ( V_26 ) ) ;
F_9 ( V_2 , V_27 , F_2 ( V_5 ) ) ;
F_10 ( V_2 , V_28 , V_21 ) ;
F_6 ( V_2 , V_29 , V_4 , V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_30 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_31 ;
V_31 = F_15 ( & V_2 -> V_32 , L_3 , & V_2 -> V_14 -> V_24 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_4 , V_31 ) ;
return V_31 ;
}
V_31 = F_16 ( V_24 , V_2 -> V_32 ) ;
if ( V_31 ) {
F_17 ( V_2 -> V_32 ) ;
return V_31 ;
}
return 0 ;
}
static int F_18 ( struct V_30 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
const struct V_32 * V_33 ;
int V_31 ;
V_31 = F_15 ( & V_33 , L_5 , & V_2 -> V_14 -> V_24 ) ;
if ( V_31 < 0 ) {
#ifdef F_19
F_20 ( & V_2 -> V_14 -> V_24 , L_6 ) ;
V_31 = F_21 ( V_24 , ( void * ) V_34 ,
sizeof( V_34 ) ) ;
#else
F_13 ( & V_2 -> V_14 -> V_24 , L_7 ) ;
#endif
} else {
F_20 ( & V_2 -> V_14 -> V_24 , L_8 ) ;
V_31 = F_21 ( V_24 , ( void * ) V_33 -> V_35 ,
( int ) V_33 -> V_36 ) ;
F_17 ( V_33 ) ;
}
return V_31 ;
}
static int F_22 ( struct V_30 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned long V_37 , V_38 ;
unsigned int V_39 = 0 ;
int V_40 = 0 ;
T_1 * V_41 ;
V_37 = V_2 -> V_32 -> V_36 ;
V_41 = F_23 ( V_2 -> V_32 -> V_35 , V_37 , V_42 ) ;
if ( ! V_41 )
return - V_43 ;
F_9 ( V_2 , V_44 , F_2 (
V_45 | V_46 |
V_47 ) ) ;
F_24 ( V_48 ) ;
F_9 ( V_2 , V_44 , F_2 (
V_45 |
V_47 ) ) ;
F_24 ( V_48 ) ;
while ( V_37 > 0 ) {
V_38 = F_25 ( long , V_37 , V_49 ) ;
V_40 = F_12 ( V_2 , F_26 (
V_50 + V_39 ) ,
( V_41 + V_39 ) , V_38 ) ;
if ( V_40 < 0 )
goto V_51;
V_37 -= V_38 ;
V_39 += V_38 ;
}
F_27 ( V_37 != 0 ) ;
F_10 ( V_2 , V_52 ,
F_26 ( V_53 ) ) ;
F_9 ( V_2 , V_44 , F_2 (
V_45 | V_46 |
V_54 ) ) ;
F_24 ( V_48 ) ;
F_9 ( V_2 , V_44 , F_2 (
V_45 | V_54 ) ) ;
F_24 ( V_48 ) ;
V_51:
F_28 ( V_41 ) ;
return V_40 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( F_31 ( V_55 ) ) ;
F_32 ( V_56 , 0 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_32 ( V_56 , 1 ) ;
F_34 ( F_31 ( V_55 ) ) ;
F_24 ( 10 ) ;
}
static inline void F_35 ( struct V_1 * V_2 , T_4 V_16 )
{
F_10 ( V_2 , V_57 , F_26 ( V_16 ) ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_58 ,
F_26 ( V_59 ) ) ;
if ( ! F_11 ( V_2 , V_60 ,
V_61 ) ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_9 ) ;
return - V_62 ;
}
F_35 ( V_2 , V_61 ) ;
return 0 ;
}
static inline void F_37 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_58 ,
F_26 ( V_63 ) ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_52 , F_26 (
V_64 | V_65 ) ) ;
switch ( V_2 -> V_66 ) {
case V_67 :
V_2 -> V_66 = V_68 ;
F_39 ( & V_2 -> V_69 ) ;
break;
case V_70 :
V_2 -> V_66 = V_68 ;
break;
default:
break;
}
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
T_6 V_5 ;
T_6 V_73 [ 2 ] ;
#define F_41 (sizeof(rx_head)-sizeof(u16))
if ( F_36 ( V_2 ) < 0 )
return - V_62 ;
F_1 ( V_2 , V_29 , V_73 , sizeof( V_73 ) ) ;
V_5 = V_73 [ 0 ] ;
if ( V_5 == 0 ) {
F_37 ( V_2 ) ;
F_13 ( & V_2 -> V_14 -> V_24 , L_10 ) ;
return 0 ;
}
V_72 = F_42 ( V_5 + 4 ) ;
if ( ! V_72 ) {
F_37 ( V_2 ) ;
F_13 ( & V_2 -> V_14 -> V_24 , L_11 ) ;
return - V_43 ;
}
if ( V_5 <= F_41 ) {
memcpy ( F_43 ( V_72 , V_5 ) , V_73 + 1 , V_5 ) ;
} else {
memcpy ( F_43 ( V_72 , F_41 ) , V_73 + 1 , F_41 ) ;
F_1 ( V_2 , V_29 ,
F_43 ( V_72 , V_5 - F_41 ) ,
V_5 - F_41 ) ;
}
F_37 ( V_2 ) ;
F_43 ( V_72 , 4 ) ;
if ( F_44 ( V_2 -> V_74 , V_72 ) == 0 )
F_45 ( V_72 ) ;
return 0 ;
}
static T_7 F_46 ( int V_75 , void * V_76 )
{
struct V_77 * V_14 = V_76 ;
struct V_1 * V_2 = F_47 ( & V_14 -> V_24 ) ;
F_48 ( V_2 -> V_74 , & V_2 -> V_78 ) ;
return V_79 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_80 * V_81 = (struct V_80 * ) V_72 -> V_35 ;
int V_31 = 0 ;
if ( F_36 ( V_2 ) < 0 )
return - V_62 ;
V_31 = F_12 ( V_2 , V_81 -> V_82 , V_72 -> V_35 , V_72 -> V_5 ) ;
if ( V_31 < 0 )
goto V_51;
if ( ! F_11 ( V_2 , V_60 ,
V_83 ) ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_12 ) ;
V_31 = - V_25 ;
goto V_51;
}
F_35 ( V_2 , V_83 ) ;
if ( F_50 ( V_72 ) )
F_51 ( V_2 -> V_74 , V_72 ) ;
V_51:
F_37 ( V_2 ) ;
return V_31 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
struct V_71 * V_72 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_84 * V_90 ;
unsigned long V_91 ;
int V_31 = 0 ;
F_53 ( & V_2 -> V_92 , V_91 ) ;
while ( ! F_54 ( & V_2 -> V_93 ) ) {
V_85 = F_55 ( V_2 -> V_93 . V_94 ,
struct V_84 , V_95 ) ;
F_56 ( & V_85 -> V_95 ) ;
F_57 ( & V_2 -> V_92 , V_91 ) ;
V_90 = F_58 ( ( void * ) V_85 , struct V_84 ,
V_95 ) ;
V_89 = F_58 ( ( void * ) V_90 , struct V_88 ,
V_35 ) ;
V_87 = F_58 ( ( void * ) V_89 , struct V_86 ,
V_96 ) ;
V_72 = F_58 ( ( void * ) V_87 , struct V_71 , V_97 ) ;
V_31 = F_49 ( V_2 , V_72 ) ;
if ( V_31 < 0 ) {
F_51 ( V_2 -> V_74 , V_72 ) ;
return V_31 ;
}
F_53 ( & V_2 -> V_92 , V_91 ) ;
}
F_57 ( & V_2 -> V_92 , V_91 ) ;
return V_31 ;
}
static void F_59 ( struct V_30 * V_24 , struct V_71 * V_72 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_86 * V_87 = F_60 ( V_72 ) ;
struct V_88 * V_98 = (struct V_88 * ) V_87 -> V_96 ;
struct V_84 * V_99 = (struct V_84 * ) V_98 -> V_35 ;
unsigned long V_91 ;
F_61 ( sizeof( * V_99 ) > sizeof( ( V_98 -> V_35 ) ) ) ;
F_53 ( & V_2 -> V_92 , V_91 ) ;
F_62 ( & V_99 -> V_95 , & V_2 -> V_93 ) ;
F_57 ( & V_2 -> V_92 , V_91 ) ;
F_48 ( V_2 -> V_74 , & V_2 -> V_78 ) ;
}
static void F_63 ( struct V_100 * V_78 )
{
struct V_1 * V_2 = F_58 ( V_78 , struct V_1 , V_78 ) ;
T_4 V_101 ;
int V_31 ;
F_64 ( & V_2 -> V_102 ) ;
if ( V_2 -> V_66 == V_103 )
goto V_51;
V_101 = F_7 ( V_2 , V_60 ) ;
if ( V_101 & V_61 ) {
F_38 ( V_2 ) ;
F_35 ( V_2 , V_61 ) ;
}
if ( V_2 -> V_66 != V_68 )
goto V_51;
if ( V_101 & V_64 ) {
F_35 ( V_2 , V_64 ) ;
V_31 = F_40 ( V_2 ) ;
if ( V_31 < 0 )
goto V_51;
}
if ( V_101 & V_65 ) {
F_35 ( V_2 , V_65 ) ;
V_31 = F_40 ( V_2 ) ;
if ( V_31 < 0 )
goto V_51;
}
V_31 = F_52 ( V_2 ) ;
V_51:
F_65 ( & V_2 -> V_102 ) ;
}
static int F_66 ( struct V_30 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned long V_104 ;
int V_31 = 0 ;
if ( F_67 ( & V_2 -> V_102 ) ) {
V_31 = - V_105 ;
goto V_51;
}
V_2 -> V_66 = V_67 ;
F_33 ( V_2 ) ;
V_31 = F_22 ( V_24 ) ;
if ( V_31 < 0 ) {
F_29 ( V_2 ) ;
goto V_106;
}
F_65 ( & V_2 -> V_102 ) ;
V_104 = F_68 ( 2000 ) ;
V_104 = F_69 ( & V_2 -> V_69 ,
V_104 ) ;
if ( ! V_104 ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_13 ) ;
F_29 ( V_2 ) ;
V_31 = - 1 ;
goto V_51;
}
if ( F_67 ( & V_2 -> V_102 ) ) {
V_31 = - V_105 ;
F_29 ( V_2 ) ;
goto V_51;
}
F_70 ( V_2 -> V_66 != V_68 ) ;
V_106:
F_65 ( & V_2 -> V_102 ) ;
V_51:
return V_31 ;
}
static void F_71 ( struct V_30 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned long V_91 ;
F_64 ( & V_2 -> V_102 ) ;
F_70 ( V_2 -> V_66 != V_68 ) ;
F_29 ( V_2 ) ;
F_53 ( & V_2 -> V_92 , V_91 ) ;
F_72 ( & V_2 -> V_93 ) ;
F_57 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_66 = V_103 ;
F_65 ( & V_2 -> V_102 ) ;
F_73 ( & V_2 -> V_78 ) ;
}
static int T_8 F_74 ( struct V_77 * V_14 )
{
struct V_1 * V_2 = NULL ;
struct V_30 * V_74 ;
int V_31 = - V_107 ;
V_74 = F_75 ( sizeof( * V_2 ) ) ;
if ( ! V_74 ) {
F_13 ( & V_14 -> V_24 , L_14 ) ;
return - V_43 ;
}
V_2 = V_74 -> V_2 ;
V_2 -> V_74 = V_74 ;
F_76 ( & V_14 -> V_24 , V_2 ) ;
V_2 -> V_14 = V_14 ;
V_14 -> V_108 = 16 ;
V_14 -> V_109 = 24000000 ;
V_31 = F_77 ( V_14 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_15 ) ;
goto V_110;
}
V_31 = F_78 ( V_56 , L_16 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_17 , V_31 ) ;
goto V_110;
}
V_31 = F_78 ( V_55 , L_18 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_19 , V_31 ) ;
goto V_111;
}
F_79 ( V_56 , 0 ) ;
F_80 ( V_55 ) ;
V_31 = F_81 ( F_31 ( V_55 ) ,
F_46 , V_112 , L_20 ,
V_2 -> V_14 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_14 -> V_24 , L_21 ) ;
goto V_113;
}
F_82 ( F_31 ( V_55 ) , V_114 ) ;
F_30 ( F_31 ( V_55 ) ) ;
F_83 ( & V_2 -> V_78 , F_63 ) ;
F_84 ( & V_2 -> V_69 ) ;
F_72 ( & V_2 -> V_93 ) ;
F_85 ( & V_2 -> V_102 ) ;
F_86 ( & V_2 -> V_92 ) ;
F_87 ( V_74 , & V_14 -> V_24 ) ;
V_2 -> V_115 . V_116 = F_66 ;
V_2 -> V_115 . V_117 = F_71 ;
V_2 -> V_115 . V_118 = F_59 ;
V_31 = F_14 ( V_74 ) ;
if ( V_31 < 0 )
goto V_119;
V_31 = F_18 ( V_74 ) ;
if ( V_31 )
goto V_119;
V_31 = F_88 ( V_74 , & V_2 -> V_14 -> V_24 ) ;
if ( V_31 )
goto V_119;
return 0 ;
V_119:
F_89 ( F_31 ( V_55 ) , V_14 ) ;
V_113:
F_90 ( V_55 ) ;
V_111:
F_90 ( V_56 ) ;
V_110:
F_91 ( V_2 -> V_74 ) ;
return V_31 ;
}
static int T_9 F_92 ( struct V_77 * V_14 )
{
struct V_1 * V_2 = F_47 ( & V_14 -> V_24 ) ;
F_93 ( V_2 -> V_74 ) ;
F_89 ( F_31 ( V_55 ) , V_14 ) ;
F_90 ( V_56 ) ;
F_90 ( V_55 ) ;
F_17 ( V_2 -> V_32 ) ;
F_94 ( & V_2 -> V_102 ) ;
F_91 ( V_2 -> V_74 ) ;
return 0 ;
}
static int T_10 F_95 ( void )
{
int V_31 ;
V_31 = F_96 ( & V_120 ) ;
if ( V_31 < 0 ) {
F_97 ( V_121 L_22 , V_31 ) ;
goto V_51;
}
V_51:
return V_31 ;
}
static void T_11 F_98 ( void )
{
F_99 ( & V_120 ) ;
}
