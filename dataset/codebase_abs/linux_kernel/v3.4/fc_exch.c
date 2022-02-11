static inline const char * F_1 ( unsigned int V_1 , char * * V_2 ,
unsigned int V_3 )
{
const char * V_4 = NULL ;
if ( V_1 < V_3 )
V_4 = V_2 [ V_1 ] ;
if ( ! V_4 )
V_4 = L_1 ;
return V_4 ;
}
static const char * F_2 ( unsigned int V_1 )
{
return F_1 ( V_1 , V_5 ,
F_3 ( V_5 ) ) ;
}
static inline void F_4 ( struct V_6 * V_7 )
{
F_5 ( & V_7 -> V_8 ) ;
}
static void F_6 ( struct V_6 * V_7 , struct V_9 * V_10 ,
T_1 V_11 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
T_2 V_14 ;
F_8 ( V_10 ) = V_7 -> V_15 ;
if ( V_7 -> V_16 . V_17 )
F_8 ( V_10 ) = F_9 ( V_7 -> V_15 ) ;
if ( V_11 & V_18 ) {
F_10 ( V_10 ) = V_19 ;
if ( F_11 ( V_7 -> V_15 ) )
F_10 ( V_10 ) = V_20 ;
V_14 = F_12 ( V_10 ) & 3 ;
if ( V_14 ) {
V_14 = 4 - V_14 ;
F_13 ( F_14 ( V_10 ) , V_14 ) ;
F_15 ( V_13 -> V_21 , V_11 | V_14 ) ;
}
} else {
F_16 ( F_12 ( V_10 ) % 4 != 0 ) ;
F_10 ( V_10 ) = V_20 ;
}
V_13 -> V_22 = F_17 ( V_7 -> V_23 ) ;
V_13 -> V_24 = F_17 ( V_7 -> V_25 ) ;
V_13 -> V_26 = V_7 -> V_16 . V_27 ;
V_13 -> V_28 = F_17 ( V_7 -> V_16 . V_17 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_29 * V_30 ;
if ( F_19 ( & V_7 -> V_8 ) ) {
V_30 = V_7 -> V_31 ;
if ( V_7 -> V_32 )
V_7 -> V_32 ( & V_7 -> V_16 , V_7 -> V_33 ) ;
F_16 ( ! ( V_7 -> V_34 & V_35 ) ) ;
F_20 ( V_7 , V_30 -> V_36 ) ;
}
}
static int F_21 ( struct V_6 * V_7 )
{
int V_37 = 1 ;
V_7 -> V_38 = NULL ;
if ( V_7 -> V_39 & V_40 )
return V_37 ;
V_7 -> V_34 |= V_35 ;
if ( ! ( V_7 -> V_34 & V_41 ) ) {
V_7 -> V_39 |= V_40 ;
if ( F_22 ( & V_7 -> V_42 ) )
F_23 ( & V_7 -> V_8 ) ;
V_37 = 0 ;
}
return V_37 ;
}
static inline struct V_6 * F_24 ( struct V_43 * V_44 ,
T_2 V_45 )
{
struct V_6 * * V_46 = (struct V_6 * * ) ( V_44 + 1 ) ;
return V_46 [ V_45 ] ;
}
static inline void F_25 ( struct V_43 * V_44 , T_2 V_45 ,
struct V_6 * V_7 )
{
( (struct V_6 * * ) ( V_44 + 1 ) ) [ V_45 ] = V_7 ;
}
static void F_26 ( struct V_6 * V_7 )
{
struct V_43 * V_44 ;
T_2 V_45 ;
V_44 = V_7 -> V_44 ;
F_27 ( & V_44 -> V_47 ) ;
F_16 ( V_44 -> V_48 <= 0 ) ;
V_44 -> V_48 -- ;
V_45 = ( V_7 -> V_49 - V_7 -> V_31 -> V_50 ) >> V_51 ;
if ( V_44 -> V_52 == V_53 )
V_44 -> V_52 = V_45 ;
else if ( V_44 -> V_54 == V_53 )
V_44 -> V_54 = V_45 ;
else
V_44 -> V_55 = V_45 ;
F_25 ( V_44 , V_45 , NULL ) ;
F_28 ( & V_7 -> V_56 ) ;
F_29 ( & V_44 -> V_47 ) ;
F_18 ( V_7 ) ;
}
static inline void F_30 ( struct V_6 * V_7 ,
unsigned int V_57 )
{
if ( V_7 -> V_39 & ( V_58 | V_40 ) )
return;
F_31 ( V_7 , L_2 ) ;
if ( F_32 ( V_59 , & V_7 -> V_42 ,
F_33 ( V_57 ) ) )
F_4 ( V_7 ) ;
}
static void F_34 ( struct V_6 * V_7 , unsigned int V_57 )
{
F_27 ( & V_7 -> V_60 ) ;
F_30 ( V_7 , V_57 ) ;
F_29 ( & V_7 -> V_60 ) ;
}
static int F_35 ( struct V_61 * V_62 , struct V_63 * V_64 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 = F_7 ( V_10 ) ;
int error ;
T_1 V_11 ;
T_3 V_65 = V_13 -> V_65 ;
V_7 = F_36 ( V_64 ) ;
F_16 ( ( V_7 -> V_34 & V_66 ) != V_66 ) ;
V_11 = F_37 ( V_13 -> V_21 ) ;
F_6 ( V_7 , V_10 , V_11 ) ;
F_38 ( V_10 ) = V_7 -> V_67 ;
if ( F_39 ( V_10 ) )
V_64 -> V_17 += F_40 ( ( F_12 ( V_10 ) - sizeof( * V_13 ) ) ,
F_39 ( V_10 ) ) ;
else
V_64 -> V_17 ++ ;
error = V_62 -> V_68 . V_69 ( V_62 , V_10 ) ;
if ( V_65 == V_70 )
return error ;
F_27 ( & V_7 -> V_60 ) ;
V_7 -> V_11 = V_11 & ~ V_71 ;
if ( V_11 & V_72 )
V_7 -> V_34 &= ~ V_66 ;
F_29 ( & V_7 -> V_60 ) ;
return error ;
}
static struct V_63 * F_41 ( struct V_6 * V_7 , T_3 V_73 )
{
struct V_63 * V_64 ;
V_64 = & V_7 -> V_16 ;
V_64 -> V_74 = 0 ;
V_64 -> V_17 = 0 ;
V_64 -> V_27 = V_73 ;
return V_64 ;
}
static struct V_63 * F_42 ( struct V_63 * V_64 )
{
struct V_6 * V_7 = F_36 ( V_64 ) ;
V_64 = F_41 ( V_7 , V_7 -> V_73 ++ ) ;
F_31 ( V_7 , L_3 ,
V_7 -> V_11 , V_64 -> V_27 ) ;
return V_64 ;
}
static struct V_63 * F_43 ( struct V_63 * V_64 )
{
struct V_6 * V_7 = F_36 ( V_64 ) ;
F_27 ( & V_7 -> V_60 ) ;
V_64 = F_42 ( V_64 ) ;
F_29 ( & V_7 -> V_60 ) ;
return V_64 ;
}
static void F_44 ( struct V_63 * V_64 ,
void (* V_38)( struct V_63 * , struct V_9 * ,
void * ) ,
void * V_33 )
{
struct V_6 * V_7 = F_36 ( V_64 ) ;
F_27 ( & V_7 -> V_60 ) ;
V_7 -> V_38 = V_38 ;
V_7 -> V_33 = V_33 ;
F_29 ( & V_7 -> V_60 ) ;
}
static int F_45 ( struct V_6 * V_7 ,
unsigned int V_57 )
{
struct V_63 * V_64 ;
struct V_9 * V_10 ;
int error ;
if ( V_7 -> V_34 & ( V_35 | V_75 ) ||
V_7 -> V_39 & ( V_40 | V_58 ) )
return - V_76 ;
V_64 = F_42 ( & V_7 -> V_16 ) ;
if ( ! V_64 )
return - V_77 ;
V_7 -> V_34 |= V_66 | V_75 ;
if ( V_57 )
F_30 ( V_7 , V_57 ) ;
if ( ! V_7 -> V_78 )
return 0 ;
V_10 = F_46 ( V_7 -> V_79 , 0 ) ;
if ( V_10 ) {
F_47 ( V_10 , V_80 , V_7 -> V_81 , V_7 -> V_78 ,
V_70 , V_18 | V_72 , 0 ) ;
error = F_35 ( V_7 -> V_79 , V_64 , V_10 ) ;
} else
error = - V_82 ;
return error ;
}
static int F_48 ( const struct V_63 * V_83 ,
unsigned int V_57 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_36 ( V_83 ) ;
F_27 ( & V_7 -> V_60 ) ;
error = F_45 ( V_7 , V_57 ) ;
F_29 ( & V_7 -> V_60 ) ;
return error ;
}
static void F_49 ( struct V_84 * V_85 )
{
struct V_6 * V_7 = F_50 ( V_85 , struct V_6 ,
V_42 . V_85 ) ;
struct V_63 * V_64 = & V_7 -> V_16 ;
void (* V_38)( struct V_63 * , struct V_9 * V_10 , void * V_33 );
void * V_33 ;
T_1 V_86 ;
int V_37 = 1 ;
F_31 ( V_7 , L_4 ) ;
F_27 ( & V_7 -> V_60 ) ;
if ( V_7 -> V_39 & ( V_58 | V_40 ) )
goto V_87;
V_86 = V_7 -> V_34 ;
if ( V_86 & V_35 ) {
V_7 -> V_34 = V_86 & ~ V_41 ;
F_29 ( & V_7 -> V_60 ) ;
if ( V_86 & V_41 )
F_51 ( V_7 ) ;
goto V_88;
} else {
V_38 = V_7 -> V_38 ;
V_33 = V_7 -> V_33 ;
V_7 -> V_38 = NULL ;
if ( V_86 & V_75 )
V_37 = F_21 ( V_7 ) ;
F_29 ( & V_7 -> V_60 ) ;
if ( ! V_37 )
F_26 ( V_7 ) ;
if ( V_38 )
V_38 ( V_64 , F_52 ( - V_89 ) , V_33 ) ;
F_48 ( V_64 , 2 * V_7 -> V_90 ) ;
goto V_88;
}
V_87:
F_29 ( & V_7 -> V_60 ) ;
V_88:
F_18 ( V_7 ) ;
}
static struct V_6 * F_53 ( struct V_61 * V_62 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
unsigned int V_91 ;
T_2 V_45 ;
struct V_43 * V_44 ;
V_7 = F_54 ( V_30 -> V_36 , V_92 ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_93 . V_94 ) ;
goto V_95;
}
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_91 = F_55 () ;
V_44 = F_56 ( V_30 -> V_44 , V_91 ) ;
F_27 ( & V_44 -> V_47 ) ;
F_57 () ;
if ( V_44 -> V_52 != V_53 ) {
V_45 = V_44 -> V_52 ;
V_44 -> V_52 = V_53 ;
goto V_96;
}
if ( V_44 -> V_54 != V_53 ) {
V_45 = V_44 -> V_54 ;
V_44 -> V_54 = V_53 ;
goto V_96;
}
V_45 = V_44 -> V_55 ;
while ( F_24 ( V_44 , V_45 ) ) {
V_45 = V_45 == V_30 -> V_97 ? 0 : V_45 + 1 ;
if ( V_45 == V_44 -> V_55 )
goto V_98;
}
V_44 -> V_55 = V_45 == V_30 -> V_97 ? 0 : V_45 + 1 ;
V_96:
F_4 ( V_7 ) ;
F_58 ( & V_7 -> V_60 ) ;
F_27 ( & V_7 -> V_60 ) ;
F_25 ( V_44 , V_45 , V_7 ) ;
F_59 ( & V_7 -> V_56 , & V_44 -> V_56 ) ;
F_41 ( V_7 , V_7 -> V_73 ++ ) ;
V_44 -> V_48 ++ ;
F_29 ( & V_44 -> V_47 ) ;
V_7 -> V_23 = V_7 -> V_49 = ( V_45 << V_51 | V_91 ) + V_30 -> V_50 ;
V_7 -> V_31 = V_30 ;
V_7 -> V_44 = V_44 ;
V_7 -> V_79 = V_62 ;
V_7 -> V_11 = V_71 ;
V_7 -> V_25 = V_53 ;
V_7 -> V_15 = V_30 -> V_15 ;
F_60 ( & V_7 -> V_42 , F_49 ) ;
V_95:
return V_7 ;
V_98:
F_29 ( & V_44 -> V_47 ) ;
F_5 ( & V_30 -> V_93 . V_99 ) ;
F_20 ( V_7 , V_30 -> V_36 ) ;
return NULL ;
}
static inline struct V_6 * F_61 ( struct V_61 * V_62 ,
struct V_9 * V_10 )
{
struct V_100 * V_101 ;
F_62 (ema, &lport->ema_list, ema_list)
if ( ! V_101 -> V_102 || V_101 -> V_102 ( V_10 ) )
return F_53 ( V_62 , V_101 -> V_30 ) ;
return NULL ;
}
static struct V_6 * F_63 ( struct V_29 * V_30 , T_2 V_49 )
{
struct V_43 * V_44 ;
struct V_6 * V_7 = NULL ;
if ( ( V_49 >= V_30 -> V_50 ) && ( V_49 <= V_30 -> V_103 ) ) {
V_44 = F_56 ( V_30 -> V_44 , V_49 & V_104 ) ;
F_27 ( & V_44 -> V_47 ) ;
V_7 = F_24 ( V_44 , ( V_49 - V_30 -> V_50 ) >> V_51 ) ;
if ( V_7 && V_7 -> V_49 == V_49 )
F_4 ( V_7 ) ;
F_29 ( & V_44 -> V_47 ) ;
}
return V_7 ;
}
static void F_64 ( struct V_63 * V_64 )
{
struct V_6 * V_7 = F_36 ( V_64 ) ;
int V_37 ;
F_27 ( & V_7 -> V_60 ) ;
V_37 = F_21 ( V_7 ) ;
F_29 ( & V_7 -> V_60 ) ;
if ( ! V_37 )
F_26 ( V_7 ) ;
}
static struct V_6 * F_65 ( struct V_61 * V_62 ,
struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
V_7 = F_61 ( V_62 , V_10 ) ;
if ( V_7 ) {
V_7 -> V_15 = F_66 ( V_10 ) ;
V_7 -> V_11 |= V_105 ;
V_7 -> V_11 &= ~ V_71 ;
V_13 = F_7 ( V_10 ) ;
V_7 -> V_78 = F_37 ( V_13 -> V_106 ) ;
V_7 -> V_81 = F_37 ( V_13 -> V_107 ) ;
V_7 -> V_108 = V_7 -> V_81 ;
V_7 -> V_25 = V_7 -> V_49 ;
V_7 -> V_23 = F_67 ( V_13 -> V_22 ) ;
V_7 -> V_34 |= V_109 | V_66 ;
if ( ( F_37 ( V_13 -> V_21 ) & V_72 ) == 0 )
V_7 -> V_34 &= ~ V_66 ;
F_4 ( V_7 ) ;
F_29 ( & V_7 -> V_60 ) ;
}
return V_7 ;
}
static enum V_110 F_68 ( struct V_61 * V_62 ,
struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_6 * V_7 = NULL ;
struct V_63 * V_64 = NULL ;
enum V_110 V_111 = V_112 ;
T_1 V_11 ;
T_2 V_49 ;
V_11 = F_37 ( V_13 -> V_21 ) ;
F_16 ( ( V_11 & V_113 ) != 0 ) ;
if ( V_11 & V_105 ) {
V_49 = F_67 ( V_13 -> V_22 ) ;
V_7 = F_63 ( V_30 , V_49 ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_93 . V_114 ) ;
V_111 = V_115 ;
goto V_95;
}
if ( V_7 -> V_25 == V_53 )
V_7 -> V_25 = F_67 ( V_13 -> V_24 ) ;
else if ( V_7 -> V_25 != F_67 ( V_13 -> V_24 ) ) {
V_111 = V_115 ;
goto V_116;
}
} else {
V_49 = F_67 ( V_13 -> V_24 ) ;
if ( V_49 == 0 && V_13 -> V_117 == V_118 &&
F_69 ( V_10 ) == V_119 ) {
V_13 -> V_24 = F_17 ( V_53 ) ;
V_49 = V_53 ;
}
V_7 = F_63 ( V_30 , V_49 ) ;
if ( ( V_11 & V_71 ) && F_70 ( F_8 ( V_10 ) ) ) {
if ( V_7 ) {
F_5 ( & V_30 -> V_93 . V_120 ) ;
V_111 = V_121 ;
goto V_116;
}
V_7 = F_65 ( V_62 , V_30 , V_10 ) ;
if ( ! V_7 ) {
V_111 = V_122 ;
goto V_95;
}
V_49 = V_7 -> V_49 ;
} else if ( ! V_7 ) {
F_5 ( & V_30 -> V_93 . V_114 ) ;
V_111 = V_121 ;
goto V_95;
}
}
if ( F_70 ( F_8 ( V_10 ) ) ) {
V_64 = & V_7 -> V_16 ;
V_64 -> V_74 |= V_123 ;
V_64 -> V_27 = V_13 -> V_26 ;
} else {
V_64 = & V_7 -> V_16 ;
if ( V_64 -> V_27 != V_13 -> V_26 ) {
F_5 ( & V_30 -> V_93 . V_124 ) ;
if ( V_11 & V_18 ) {
F_27 ( & V_7 -> V_60 ) ;
V_64 -> V_74 |= V_123 ;
V_64 -> V_27 = V_13 -> V_26 ;
F_29 ( & V_7 -> V_60 ) ;
} else {
V_111 = V_125 ;
goto V_116;
}
}
}
F_16 ( V_7 != F_36 ( V_64 ) ) ;
if ( V_11 & V_72 )
V_7 -> V_34 |= V_66 ;
F_71 ( V_10 ) = V_64 ;
V_95:
return V_111 ;
V_116:
F_64 ( & V_7 -> V_16 ) ;
F_18 ( V_7 ) ;
return V_111 ;
}
static struct V_63 * F_72 ( struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_6 * V_7 ;
struct V_63 * V_64 = NULL ;
T_1 V_11 ;
T_2 V_49 ;
V_11 = F_37 ( V_13 -> V_21 ) ;
F_16 ( ( V_11 & V_113 ) != V_113 ) ;
V_49 = F_67 ( ( V_11 & V_105 ) ? V_13 -> V_22 : V_13 -> V_24 ) ;
V_7 = F_63 ( V_30 , V_49 ) ;
if ( ! V_7 )
return NULL ;
if ( V_7 -> V_16 . V_27 == V_13 -> V_26 ) {
V_64 = & V_7 -> V_16 ;
if ( ( V_11 & V_105 ) != 0 &&
V_7 -> V_25 == V_53 ) {
V_7 -> V_25 = F_67 ( V_13 -> V_24 ) ;
}
}
F_18 ( V_7 ) ;
return V_64 ;
}
static void F_73 ( struct V_6 * V_7 ,
T_1 V_126 , T_1 V_127 )
{
V_7 -> V_108 = V_126 ;
if ( V_7 -> V_34 & V_109 ) {
V_7 -> V_78 = V_127 ;
V_7 -> V_81 = V_126 ;
} else {
V_7 -> V_78 = V_126 ;
V_7 -> V_81 = V_127 ;
}
}
static void F_74 ( struct V_9 * V_10 , enum V_128 V_129 ,
struct V_130 * V_131 )
{
switch ( V_129 ) {
case V_132 :
F_75 ( V_10 , V_131 -> V_133 , V_131 -> V_134 ) ;
break;
case V_135 :
F_76 ( V_10 ) ;
break;
case V_136 :
F_77 ( V_10 ) ;
break;
case V_137 :
F_78 ( V_10 ) ;
break;
default:
F_79 ( F_80 ( V_10 ) , L_5 , V_129 ) ;
}
}
static void F_81 ( struct V_63 * V_64 , struct V_9 * V_10 ,
enum V_138 V_139 , enum V_140 V_65 )
{
T_1 V_11 ;
struct V_6 * V_7 = F_36 ( V_64 ) ;
V_11 = V_141 | V_18 | V_72 ;
V_11 |= V_7 -> V_11 ;
F_47 ( V_10 , V_139 , V_7 -> V_81 , V_7 -> V_78 , V_65 , V_11 , 0 ) ;
F_35 ( V_7 -> V_79 , V_64 , V_10 ) ;
}
static void F_82 ( struct V_63 * V_64 , const struct V_9 * V_142 )
{
struct V_9 * V_10 ;
struct V_12 * V_143 ;
struct V_12 * V_13 ;
struct V_6 * V_7 = F_36 ( V_64 ) ;
struct V_61 * V_62 = V_7 -> V_79 ;
unsigned int V_11 ;
if ( F_11 ( F_8 ( V_142 ) ) ) {
V_10 = F_46 ( V_62 , 0 ) ;
if ( ! V_10 )
return;
V_13 = F_7 ( V_10 ) ;
V_13 -> V_117 = V_144 ;
V_13 -> V_65 = V_70 ;
V_143 = F_7 ( V_142 ) ;
V_11 = F_37 ( V_143 -> V_21 ) ;
V_11 &= V_105 | V_113 |
V_71 | V_141 |
V_18 | V_145 | V_72 |
V_146 | V_147 ;
V_11 ^= V_105 | V_113 ;
F_15 ( V_13 -> V_21 , V_11 ) ;
F_6 ( V_7 , V_10 , V_11 ) ;
V_13 -> V_26 = V_143 -> V_26 ;
V_13 -> V_28 = V_143 -> V_28 ;
V_13 -> V_148 = F_83 ( 1 ) ;
F_8 ( V_10 ) = F_8 ( V_142 ) ;
if ( V_11 & V_18 )
F_10 ( V_10 ) = V_19 ;
else
F_10 ( V_10 ) = V_20 ;
V_62 -> V_68 . V_69 ( V_62 , V_10 ) ;
}
}
static void F_84 ( struct V_9 * V_142 ,
enum V_149 V_133 ,
enum V_150 V_134 )
{
struct V_9 * V_10 ;
struct V_12 * V_143 ;
struct V_12 * V_13 ;
struct V_151 * V_152 ;
struct V_61 * V_62 ;
unsigned int V_11 ;
V_62 = F_80 ( V_142 ) ;
V_10 = F_46 ( V_62 , sizeof( * V_152 ) ) ;
if ( ! V_10 )
return;
V_13 = F_7 ( V_10 ) ;
V_143 = F_7 ( V_142 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) + sizeof( * V_152 ) ) ;
V_152 = F_85 ( V_10 , sizeof( * V_152 ) ) ;
V_152 -> V_153 = V_133 ;
V_152 -> V_154 = V_134 ;
memcpy ( V_13 -> V_107 , V_143 -> V_106 , 3 ) ;
memcpy ( V_13 -> V_106 , V_143 -> V_107 , 3 ) ;
V_13 -> V_22 = V_143 -> V_22 ;
V_13 -> V_24 = V_143 -> V_24 ;
V_13 -> V_28 = V_143 -> V_28 ;
V_13 -> V_117 = V_155 ;
V_13 -> V_65 = V_70 ;
V_11 = F_37 ( V_143 -> V_21 ) ;
V_11 &= V_105 | V_113 |
V_145 | V_72 |
V_146 | V_147 ;
V_11 ^= V_105 | V_113 ;
V_11 |= V_141 | V_18 ;
V_11 &= ~ V_71 ;
F_15 ( V_13 -> V_21 , V_11 ) ;
F_8 ( V_10 ) = F_86 ( F_8 ( V_142 ) ) ;
F_10 ( V_10 ) = V_19 ;
if ( F_11 ( F_8 ( V_10 ) ) )
F_10 ( V_10 ) = V_20 ;
V_62 -> V_68 . V_69 ( V_62 , V_10 ) ;
}
static void F_87 ( struct V_6 * V_7 , struct V_9 * V_142 )
{
struct V_9 * V_10 ;
struct V_156 * V_157 ;
struct V_12 * V_13 ;
struct V_63 * V_64 ;
if ( ! V_7 )
goto V_111;
F_27 ( & V_7 -> V_60 ) ;
if ( V_7 -> V_34 & V_35 ) {
F_29 ( & V_7 -> V_60 ) ;
goto V_111;
}
if ( ! ( V_7 -> V_34 & V_41 ) )
F_4 ( V_7 ) ;
V_7 -> V_34 |= V_75 | V_41 ;
F_30 ( V_7 , V_7 -> V_90 ) ;
V_10 = F_46 ( V_7 -> V_79 , sizeof( * V_157 ) ) ;
if ( ! V_10 ) {
F_29 ( & V_7 -> V_60 ) ;
goto free;
}
V_13 = F_7 ( V_10 ) ;
V_157 = F_85 ( V_10 , sizeof( * V_157 ) ) ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
V_64 = & V_7 -> V_16 ;
V_157 -> V_158 = F_17 ( 0xffff ) ;
if ( V_64 -> V_74 & V_123 ) {
V_157 -> V_159 = V_64 -> V_27 ;
V_157 -> V_160 = V_161 ;
V_157 -> V_158 = V_13 -> V_28 ;
V_157 -> V_162 = F_17 ( V_64 -> V_17 ) ;
}
V_64 = F_42 ( V_64 ) ;
F_29 ( & V_7 -> V_60 ) ;
F_81 ( V_64 , V_10 , V_163 , V_70 ) ;
F_88 ( V_142 ) ;
return;
V_111:
F_84 ( V_142 , V_164 , V_165 ) ;
free:
F_88 ( V_142 ) ;
}
static struct V_63 * F_89 ( struct V_61 * V_62 , struct V_9 * V_10 )
{
struct V_100 * V_101 ;
F_16 ( V_62 != F_80 ( V_10 ) ) ;
F_16 ( F_71 ( V_10 ) ) ;
F_71 ( V_10 ) = NULL ;
F_62 (ema, &lport->ema_list, ema_list)
if ( ( ! V_101 -> V_102 || V_101 -> V_102 ( V_10 ) ) &&
F_68 ( V_62 , V_101 -> V_30 , V_10 ) == V_112 )
break;
return F_71 ( V_10 ) ;
}
static void F_90 ( struct V_63 * V_64 )
{
F_18 ( F_36 ( V_64 ) ) ;
}
static void F_91 ( struct V_61 * V_62 , struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_63 * V_64 = NULL ;
struct V_6 * V_7 = NULL ;
enum V_110 V_111 ;
V_62 = F_92 ( V_62 , F_37 ( V_13 -> V_106 ) ) ;
if ( ! V_62 ) {
F_88 ( V_10 ) ;
return;
}
F_80 ( V_10 ) = V_62 ;
F_93 ( F_71 ( V_10 ) ) ;
if ( V_13 -> V_24 == F_17 ( V_53 ) )
return V_62 -> V_68 . V_166 ( V_62 , V_10 ) ;
V_111 = F_68 ( V_62 , V_30 , V_10 ) ;
if ( V_111 == V_112 ) {
V_64 = F_71 ( V_10 ) ;
V_7 = F_36 ( V_64 ) ;
F_82 ( V_64 , V_10 ) ;
V_7 -> V_67 = F_38 ( V_10 ) ;
if ( V_7 -> V_38 )
V_7 -> V_38 ( V_64 , V_10 , V_7 -> V_33 ) ;
else
V_62 -> V_68 . V_166 ( V_62 , V_10 ) ;
F_18 ( V_7 ) ;
} else {
F_79 ( V_62 , L_6 ,
V_111 ) ;
F_88 ( V_10 ) ;
}
}
static void F_94 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_63 * V_64 ;
struct V_6 * V_7 ;
enum V_167 V_168 ;
T_1 V_11 ;
void (* V_38)( struct V_63 * , struct V_9 * V_10 , void * V_33 );
void * V_169 ;
int V_37 ;
V_7 = F_63 ( V_30 , F_67 ( V_13 -> V_22 ) ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_93 . V_114 ) ;
goto V_95;
}
if ( V_7 -> V_34 & V_35 ) {
F_5 ( & V_30 -> V_93 . V_114 ) ;
goto V_116;
}
if ( V_7 -> V_25 == V_53 )
V_7 -> V_25 = F_67 ( V_13 -> V_24 ) ;
if ( V_7 -> V_78 != 0 && V_7 -> V_78 != F_37 ( V_13 -> V_106 ) ) {
F_5 ( & V_30 -> V_93 . V_114 ) ;
goto V_116;
}
if ( V_7 -> V_81 != F_37 ( V_13 -> V_107 ) &&
V_7 -> V_81 != V_170 ) {
F_5 ( & V_30 -> V_93 . V_114 ) ;
goto V_116;
}
V_168 = F_8 ( V_10 ) ;
V_64 = & V_7 -> V_16 ;
if ( F_70 ( V_168 ) ) {
V_64 -> V_74 |= V_123 ;
V_64 -> V_27 = V_13 -> V_26 ;
} else if ( V_64 -> V_27 != V_13 -> V_26 ) {
F_5 ( & V_30 -> V_93 . V_124 ) ;
goto V_116;
}
V_11 = F_37 ( V_13 -> V_21 ) ;
F_71 ( V_10 ) = V_64 ;
if ( V_11 & V_72 )
V_7 -> V_34 |= V_66 ;
if ( F_11 ( V_168 ) )
F_82 ( V_64 , V_10 ) ;
V_38 = V_7 -> V_38 ;
V_169 = V_7 -> V_33 ;
if ( V_13 -> V_65 != V_171 && F_10 ( V_10 ) == V_19 &&
( V_11 & ( V_141 | V_18 ) ) ==
( V_141 | V_18 ) ) {
F_27 ( & V_7 -> V_60 ) ;
V_38 = V_7 -> V_38 ;
V_37 = F_21 ( V_7 ) ;
F_16 ( F_36 ( V_64 ) != V_7 ) ;
F_29 ( & V_7 -> V_60 ) ;
if ( ! V_37 )
F_26 ( V_7 ) ;
}
if ( V_38 )
V_38 ( V_64 , V_10 , V_169 ) ;
else
F_88 ( V_10 ) ;
F_18 ( V_7 ) ;
return;
V_116:
F_18 ( V_7 ) ;
V_95:
F_88 ( V_10 ) ;
}
static void F_95 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_63 * V_64 ;
V_64 = F_72 ( V_30 , V_10 ) ;
if ( ! V_64 )
F_5 ( & V_30 -> V_93 . V_114 ) ;
else
F_5 ( & V_30 -> V_93 . V_172 ) ;
F_88 ( V_10 ) ;
}
static void F_96 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
void (* V_38)( struct V_63 * , struct V_9 * V_10 , void * V_33 );
void * V_169 ;
struct V_12 * V_13 ;
struct V_156 * V_157 ;
struct V_63 * V_64 ;
T_2 V_173 ;
T_2 V_174 ;
int V_37 = 1 , V_175 = 0 ;
V_13 = F_7 ( V_10 ) ;
F_31 ( V_7 , L_7 , V_13 -> V_117 ,
F_2 ( V_13 -> V_117 ) ) ;
if ( F_97 ( & V_7 -> V_42 ) )
F_18 ( V_7 ) ;
F_27 ( & V_7 -> V_60 ) ;
switch ( V_13 -> V_117 ) {
case V_163 :
V_157 = F_85 ( V_10 , sizeof( * V_157 ) ) ;
if ( ! V_157 )
break;
V_173 = F_67 ( V_157 -> V_162 ) ;
V_174 = F_67 ( V_157 -> V_158 ) ;
if ( ( V_7 -> V_34 & V_41 ) == 0 &&
( V_157 -> V_160 != V_161 ||
V_157 -> V_159 == V_7 -> V_73 ) && V_173 != V_174 ) {
V_7 -> V_34 |= V_41 ;
F_4 ( V_7 ) ;
V_175 = 1 ;
}
break;
case V_155 :
break;
default:
break;
}
V_38 = V_7 -> V_38 ;
V_169 = V_7 -> V_33 ;
V_64 = & V_7 -> V_16 ;
if ( V_7 -> V_65 != V_171 &&
F_37 ( V_13 -> V_21 ) & V_141 )
V_37 = F_21 ( V_7 ) ;
F_29 ( & V_7 -> V_60 ) ;
if ( ! V_37 )
F_26 ( V_7 ) ;
if ( V_38 )
V_38 ( V_64 , V_10 , V_169 ) ;
else
F_88 ( V_10 ) ;
if ( V_175 )
F_34 ( V_7 , V_7 -> V_90 ) ;
}
static void F_98 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_6 * V_7 ;
T_1 V_11 ;
V_13 = F_7 ( V_10 ) ;
V_11 = F_37 ( V_13 -> V_21 ) ;
F_71 ( V_10 ) = NULL ;
V_7 = F_63 ( V_30 , ( V_11 & V_105 ) ?
F_67 ( V_13 -> V_22 ) : F_67 ( V_13 -> V_24 ) ) ;
if ( V_7 && ( V_11 & V_72 ) ) {
F_27 ( & V_7 -> V_60 ) ;
V_7 -> V_34 |= V_66 ;
F_29 ( & V_7 -> V_60 ) ;
}
if ( V_11 & V_113 ) {
switch ( V_13 -> V_117 ) {
case V_144 :
case V_176 :
break;
default:
if ( V_7 )
F_31 ( V_7 , L_8 ,
V_13 -> V_117 ,
F_2 ( V_13 -> V_117 ) ) ;
break;
}
F_88 ( V_10 ) ;
} else {
switch ( V_13 -> V_117 ) {
case V_155 :
case V_163 :
if ( V_7 )
F_96 ( V_7 , V_10 ) ;
else
F_88 ( V_10 ) ;
break;
case V_80 :
F_87 ( V_7 , V_10 ) ;
break;
default:
F_88 ( V_10 ) ;
break;
}
}
if ( V_7 )
F_18 ( V_7 ) ;
}
static void F_76 ( struct V_9 * V_142 )
{
struct V_61 * V_62 ;
struct V_177 * V_178 ;
struct V_9 * V_10 ;
V_62 = F_80 ( V_142 ) ;
V_10 = F_46 ( V_62 , sizeof( * V_178 ) ) ;
if ( ! V_10 )
return;
V_178 = F_85 ( V_10 , sizeof( * V_178 ) ) ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
V_178 -> V_179 = V_135 ;
F_99 ( V_10 , V_142 , V_180 , 0 ) ;
V_62 -> V_68 . V_69 ( V_62 , V_10 ) ;
}
static void F_75 ( struct V_9 * V_142 , enum V_181 V_133 ,
enum V_182 V_134 )
{
struct V_61 * V_62 ;
struct V_183 * V_184 ;
struct V_9 * V_10 ;
V_62 = F_80 ( V_142 ) ;
V_10 = F_46 ( V_62 , sizeof( * V_184 ) ) ;
if ( ! V_10 )
return;
V_184 = F_85 ( V_10 , sizeof( * V_184 ) ) ;
memset ( V_184 , 0 , sizeof( * V_184 ) ) ;
V_184 -> V_185 = V_132 ;
V_184 -> V_186 = V_133 ;
V_184 -> V_187 = V_134 ;
F_99 ( V_10 , V_142 , V_180 , 0 ) ;
V_62 -> V_68 . V_69 ( V_62 , V_10 ) ;
}
static void F_100 ( struct V_6 * V_7 )
{
struct V_63 * V_64 ;
void (* V_38)( struct V_63 * , struct V_9 * , void * );
void * V_33 ;
int V_37 = 1 ;
F_27 ( & V_7 -> V_60 ) ;
F_45 ( V_7 , 0 ) ;
V_7 -> V_39 |= V_58 ;
if ( F_22 ( & V_7 -> V_42 ) )
F_23 ( & V_7 -> V_8 ) ;
V_38 = V_7 -> V_38 ;
V_7 -> V_38 = NULL ;
if ( V_7 -> V_34 & V_41 )
F_23 ( & V_7 -> V_8 ) ;
V_7 -> V_34 &= ~ V_41 ;
V_33 = V_7 -> V_33 ;
V_64 = & V_7 -> V_16 ;
V_37 = F_21 ( V_7 ) ;
F_29 ( & V_7 -> V_60 ) ;
if ( ! V_37 )
F_26 ( V_7 ) ;
if ( V_38 )
V_38 ( V_64 , F_52 ( - V_188 ) , V_33 ) ;
}
static void F_101 ( struct V_61 * V_62 ,
struct V_43 * V_44 ,
T_1 V_78 , T_1 V_81 )
{
struct V_6 * V_7 ;
struct V_6 * V_189 ;
F_27 ( & V_44 -> V_47 ) ;
V_190:
F_102 (ep, next, &pool->ex_list, ex_list) {
if ( ( V_62 == V_7 -> V_79 ) &&
( V_78 == 0 || V_78 == V_7 -> V_78 ) &&
( V_81 == 0 || V_81 == V_7 -> V_81 ) ) {
F_4 ( V_7 ) ;
F_29 ( & V_44 -> V_47 ) ;
F_100 ( V_7 ) ;
F_18 ( V_7 ) ;
F_27 ( & V_44 -> V_47 ) ;
goto V_190;
}
}
V_44 -> V_55 = 0 ;
V_44 -> V_52 = V_53 ;
V_44 -> V_54 = V_53 ;
F_29 ( & V_44 -> V_47 ) ;
}
void F_103 ( struct V_61 * V_62 , T_1 V_78 , T_1 V_81 )
{
struct V_100 * V_101 ;
unsigned int V_91 ;
F_62 (ema, &lport->ema_list, ema_list) {
F_104 (cpu)
F_101 ( V_62 ,
F_56 ( V_101 -> V_30 -> V_44 , V_91 ) ,
V_78 , V_81 ) ;
}
}
static struct V_6 * F_105 ( struct V_61 * V_62 , T_1 V_49 )
{
struct V_100 * V_101 ;
F_62 (ema, &lport->ema_list, ema_list)
if ( V_101 -> V_30 -> V_50 <= V_49 && V_49 <= V_101 -> V_30 -> V_103 )
return F_63 ( V_101 -> V_30 , V_49 ) ;
return NULL ;
}
static void F_78 ( struct V_9 * V_191 )
{
struct V_61 * V_62 ;
struct V_9 * V_10 ;
struct V_6 * V_7 ;
struct V_192 * V_152 ;
struct V_193 * V_178 ;
enum V_181 V_133 = V_194 ;
enum V_182 V_134 ;
T_1 V_78 ;
T_2 V_25 ;
T_2 V_23 ;
V_62 = F_80 ( V_191 ) ;
V_152 = F_85 ( V_191 , sizeof( * V_152 ) ) ;
V_134 = V_195 ;
if ( ! V_152 )
goto V_111;
V_78 = F_37 ( V_152 -> V_196 ) ;
V_25 = F_67 ( V_152 -> V_197 ) ;
V_23 = F_67 ( V_152 -> V_198 ) ;
V_7 = F_105 ( V_62 ,
V_78 == F_106 ( V_62 -> V_199 ) ? V_23 : V_25 ) ;
V_134 = V_200 ;
if ( ! V_7 )
goto V_111;
if ( V_7 -> V_108 != V_78 || V_23 != V_7 -> V_23 )
goto V_116;
if ( V_25 != V_53 && V_25 != V_7 -> V_25 )
goto V_116;
V_10 = F_46 ( V_62 , sizeof( * V_178 ) ) ;
if ( ! V_10 )
goto V_95;
V_178 = F_85 ( V_10 , sizeof( * V_178 ) ) ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
V_178 -> V_201 = V_135 ;
V_178 -> V_202 = V_152 -> V_198 ;
memcpy ( V_178 -> V_203 , V_152 -> V_196 , 3 ) ;
V_178 -> V_204 = F_17 ( V_7 -> V_25 ) ;
if ( V_7 -> V_78 == V_7 -> V_108 )
F_15 ( V_178 -> V_205 , V_7 -> V_81 ) ;
else
F_15 ( V_178 -> V_205 , V_7 -> V_78 ) ;
V_178 -> V_206 = F_83 ( V_7 -> V_16 . V_207 ) ;
V_178 -> V_208 = F_83 ( V_7 -> V_34 & ( V_109 |
V_66 |
V_35 ) ) ;
F_99 ( V_10 , V_191 , V_180 , 0 ) ;
V_62 -> V_68 . V_69 ( V_62 , V_10 ) ;
V_95:
F_18 ( V_7 ) ;
return;
V_116:
F_18 ( V_7 ) ;
V_111:
F_75 ( V_191 , V_133 , V_134 ) ;
}
static void F_107 ( struct V_63 * V_64 , struct V_9 * V_10 , void * V_33 )
{
struct V_6 * V_209 = V_33 ;
unsigned int V_1 ;
if ( F_108 ( V_10 ) ) {
int V_98 = F_109 ( V_10 ) ;
if ( V_98 == - V_188 || V_98 == - V_89 )
goto V_210;
F_31 ( V_209 , L_9
L_10 , V_98 ) ;
return;
}
V_1 = F_69 ( V_10 ) ;
F_88 ( V_10 ) ;
switch ( V_1 ) {
case V_132 :
F_31 ( V_209 , L_11 ) ;
case V_135 :
goto V_210;
default:
F_31 ( V_209 , L_12
L_13 , V_1 ) ;
return;
}
V_210:
F_64 ( & V_209 -> V_16 ) ;
F_18 ( V_209 ) ;
}
static struct V_63 * F_110 ( struct V_61 * V_62 ,
struct V_9 * V_10 ,
void (* V_38)( struct V_63 * ,
struct V_9 * V_10 ,
void * V_33 ) ,
void (* V_32)( struct V_63 * ,
void * ) ,
void * V_33 , T_1 V_57 )
{
struct V_6 * V_7 ;
struct V_63 * V_64 = NULL ;
struct V_12 * V_13 ;
struct V_211 * V_212 = NULL ;
int V_37 = 1 ;
V_7 = F_61 ( V_62 , V_10 ) ;
if ( ! V_7 ) {
F_88 ( V_10 ) ;
return NULL ;
}
V_7 -> V_34 |= V_66 ;
V_13 = F_7 ( V_10 ) ;
F_73 ( V_7 , F_37 ( V_13 -> V_107 ) , F_37 ( V_13 -> V_106 ) ) ;
V_7 -> V_38 = V_38 ;
V_7 -> V_32 = V_32 ;
V_7 -> V_33 = V_33 ;
V_7 -> V_90 = V_213 ;
V_7 -> V_79 = V_62 ;
V_64 = & V_7 -> V_16 ;
V_7 -> V_65 = V_13 -> V_65 ;
V_7 -> V_11 = F_37 ( V_13 -> V_21 ) ;
F_6 ( V_7 , V_10 , V_7 -> V_11 ) ;
V_64 -> V_17 ++ ;
if ( V_7 -> V_49 <= V_62 -> V_214 && V_13 -> V_117 == V_215 ) {
V_212 = F_111 ( V_10 ) ;
F_112 ( F_111 ( V_10 ) , V_7 -> V_49 ) ;
}
if ( F_113 ( V_62 -> V_68 . V_69 ( V_62 , V_10 ) ) )
goto V_98;
if ( V_57 )
F_30 ( V_7 , V_57 ) ;
V_7 -> V_11 &= ~ V_71 ;
if ( V_7 -> V_11 & V_72 )
V_7 -> V_34 &= ~ V_66 ;
F_29 ( & V_7 -> V_60 ) ;
return V_64 ;
V_98:
if ( V_212 )
F_114 ( V_212 ) ;
V_37 = F_21 ( V_7 ) ;
F_29 ( & V_7 -> V_60 ) ;
if ( ! V_37 )
F_26 ( V_7 ) ;
return NULL ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_61 * V_62 ;
struct V_216 * V_217 ;
struct V_9 * V_10 ;
T_1 V_81 ;
V_62 = V_7 -> V_79 ;
V_10 = F_46 ( V_62 , sizeof( * V_217 ) ) ;
if ( ! V_10 )
goto V_218;
V_217 = F_85 ( V_10 , sizeof( * V_217 ) ) ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_217 -> V_219 = V_136 ;
F_15 ( V_217 -> V_220 , V_7 -> V_78 ) ;
V_217 -> V_221 = F_17 ( V_7 -> V_23 ) ;
V_217 -> V_222 = F_17 ( V_7 -> V_25 ) ;
V_81 = V_7 -> V_81 ;
if ( V_7 -> V_34 & V_109 )
V_81 = V_7 -> V_78 ;
F_47 ( V_10 , V_118 , V_81 ,
V_62 -> V_223 , V_224 ,
V_71 | V_18 | V_72 , 0 ) ;
if ( F_110 ( V_62 , V_10 , F_107 , NULL , V_7 ,
V_62 -> V_225 ) )
return;
V_218:
F_27 ( & V_7 -> V_60 ) ;
if ( V_7 -> V_39 & ( V_58 | V_40 ) ) {
F_29 ( & V_7 -> V_60 ) ;
F_18 ( V_7 ) ;
return;
}
V_7 -> V_34 |= V_41 ;
F_30 ( V_7 , V_7 -> V_90 ) ;
F_29 ( & V_7 -> V_60 ) ;
}
static void F_77 ( struct V_9 * V_10 )
{
struct V_61 * V_62 ;
struct V_6 * V_7 = NULL ;
struct V_216 * V_152 ;
T_1 V_78 ;
T_2 V_49 ;
enum V_182 V_134 ;
V_62 = F_80 ( V_10 ) ;
V_152 = F_85 ( V_10 , sizeof( * V_152 ) ) ;
V_134 = V_195 ;
if ( ! V_152 )
goto V_111;
V_78 = F_37 ( V_152 -> V_220 ) ;
V_49 = F_106 ( V_62 -> V_199 ) == V_78 ?
F_67 ( V_152 -> V_221 ) : F_67 ( V_152 -> V_222 ) ;
V_7 = F_105 ( V_62 , V_49 ) ;
V_134 = V_200 ;
if ( ! V_7 )
goto V_111;
F_27 ( & V_7 -> V_60 ) ;
if ( V_7 -> V_23 != F_67 ( V_152 -> V_221 ) )
goto V_226;
if ( V_7 -> V_25 != F_67 ( V_152 -> V_222 ) &&
V_7 -> V_25 != V_53 )
goto V_226;
V_134 = V_227 ;
if ( V_7 -> V_78 != V_78 )
goto V_226;
if ( V_7 -> V_34 & V_41 ) {
V_7 -> V_34 &= ~ V_41 ;
F_23 ( & V_7 -> V_8 ) ;
}
if ( V_7 -> V_34 & V_35 ) {
if ( F_22 ( & V_7 -> V_42 ) )
F_23 ( & V_7 -> V_8 ) ;
}
F_29 ( & V_7 -> V_60 ) ;
F_76 ( V_10 ) ;
goto V_95;
V_226:
F_29 ( & V_7 -> V_60 ) ;
V_111:
F_75 ( V_10 , V_194 , V_134 ) ;
V_95:
if ( V_7 )
F_18 ( V_7 ) ;
}
struct V_100 * F_115 ( struct V_61 * V_62 ,
struct V_29 * V_30 ,
bool (* V_102)( struct V_9 * ) )
{
struct V_100 * V_101 ;
V_101 = F_116 ( sizeof( * V_101 ) , V_92 ) ;
if ( ! V_101 )
return V_101 ;
V_101 -> V_30 = V_30 ;
V_101 -> V_102 = V_102 ;
F_59 ( & V_101 -> V_228 , & V_62 -> V_228 ) ;
F_117 ( & V_30 -> V_229 ) ;
return V_101 ;
}
static void F_118 ( struct V_229 * V_229 )
{
struct V_29 * V_30 = F_50 ( V_229 , struct V_29 , V_229 ) ;
F_119 ( V_30 -> V_36 ) ;
F_120 ( V_30 -> V_44 ) ;
F_121 ( V_30 ) ;
}
void F_122 ( struct V_100 * V_101 )
{
F_28 ( & V_101 -> V_228 ) ;
F_123 ( & V_101 -> V_30 -> V_229 , F_118 ) ;
F_121 ( V_101 ) ;
}
int F_124 ( struct V_61 * V_230 , struct V_61 * V_231 )
{
struct V_100 * V_101 , * V_232 ;
F_62 (ema, &src->ema_list, ema_list) {
if ( ! F_115 ( V_231 , V_101 -> V_30 , V_101 -> V_102 ) )
goto V_98;
}
return 0 ;
V_98:
F_102 (ema, tmp, &dst->ema_list, ema_list)
F_122 ( V_101 ) ;
return - V_77 ;
}
struct V_29 * F_125 ( struct V_61 * V_62 ,
enum V_233 V_15 ,
T_2 V_50 , T_2 V_103 ,
bool (* V_102)( struct V_9 * ) )
{
struct V_29 * V_30 ;
T_2 V_234 ;
T_4 V_235 ;
unsigned int V_91 ;
struct V_43 * V_44 ;
if ( V_103 <= V_50 || V_103 == V_53 ||
( V_50 & V_104 ) != 0 ) {
F_79 ( V_62 , L_14 ,
V_50 , V_103 ) ;
return NULL ;
}
V_30 = F_126 ( sizeof( struct V_29 ) , V_92 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_15 = V_15 ;
V_30 -> V_50 = V_50 ;
V_234 = ( V_236 - sizeof( * V_44 ) ) /
sizeof( struct V_6 * ) ;
if ( ( V_103 - V_50 + 1 ) / ( V_104 + 1 ) > V_234 ) {
V_30 -> V_103 = V_234 * ( V_104 + 1 ) +
V_50 - 1 ;
} else {
V_30 -> V_103 = V_103 ;
V_234 = ( V_30 -> V_103 - V_30 -> V_50 + 1 ) /
( V_104 + 1 ) ;
}
V_30 -> V_36 = F_127 ( 2 , V_237 ) ;
if ( ! V_30 -> V_36 )
goto V_238;
V_30 -> V_97 = V_234 - 1 ;
V_235 = sizeof( * V_44 ) + V_234 * sizeof( struct V_6 * ) ;
V_30 -> V_44 = F_128 ( V_235 , F_129 ( struct V_43 ) ) ;
if ( ! V_30 -> V_44 )
goto V_239;
F_104 (cpu) {
V_44 = F_56 ( V_30 -> V_44 , V_91 ) ;
V_44 -> V_55 = 0 ;
V_44 -> V_52 = V_53 ;
V_44 -> V_54 = V_53 ;
F_58 ( & V_44 -> V_47 ) ;
F_130 ( & V_44 -> V_56 ) ;
}
F_131 ( & V_30 -> V_229 ) ;
if ( ! F_115 ( V_62 , V_30 , V_102 ) ) {
F_120 ( V_30 -> V_44 ) ;
goto V_239;
}
F_123 ( & V_30 -> V_229 , F_118 ) ;
return V_30 ;
V_239:
F_119 ( V_30 -> V_36 ) ;
V_238:
F_121 ( V_30 ) ;
return NULL ;
}
void F_132 ( struct V_61 * V_62 )
{
struct V_100 * V_101 , * V_189 ;
F_133 ( V_59 ) ;
F_102 (ema, next, &lport->ema_list, ema_list)
F_122 ( V_101 ) ;
}
static struct V_100 * F_134 ( T_1 V_11 ,
struct V_61 * V_62 ,
struct V_12 * V_13 )
{
struct V_100 * V_101 ;
T_2 V_49 ;
if ( V_11 & V_105 )
V_49 = F_67 ( V_13 -> V_22 ) ;
else {
V_49 = F_67 ( V_13 -> V_24 ) ;
if ( V_49 == V_53 )
return F_135 ( V_62 -> V_228 . V_240 ,
F_136 ( * V_101 ) , V_228 ) ;
}
F_62 (ema, &lport->ema_list, ema_list) {
if ( ( V_49 >= V_101 -> V_30 -> V_50 ) &&
( V_49 <= V_101 -> V_30 -> V_103 ) )
return V_101 ;
}
return NULL ;
}
void F_137 ( struct V_61 * V_62 , struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_100 * V_101 ;
T_1 V_11 ;
if ( ! V_62 || V_62 -> V_39 == V_241 ) {
F_79 ( V_62 , L_15
L_16 ) ;
F_88 ( V_10 ) ;
return;
}
V_11 = F_37 ( V_13 -> V_21 ) ;
V_101 = F_134 ( V_11 , V_62 , V_13 ) ;
if ( ! V_101 ) {
F_79 ( V_62 , L_17
L_18 ,
V_11 ,
( V_11 & V_105 ) ?
F_67 ( V_13 -> V_22 ) :
F_67 ( V_13 -> V_24 ) ) ;
F_88 ( V_10 ) ;
return;
}
switch ( F_10 ( V_10 ) ) {
case V_19 :
if ( V_11 & V_18 )
F_138 ( F_14 ( V_10 ) , F_12 ( V_10 ) - F_139 ( V_11 ) ) ;
case V_20 :
if ( V_13 -> V_65 == V_70 )
F_98 ( V_101 -> V_30 , V_10 ) ;
else if ( ( V_11 & ( V_105 | V_113 ) ) ==
V_105 )
F_94 ( V_101 -> V_30 , V_10 ) ;
else if ( V_11 & V_113 )
F_95 ( V_101 -> V_30 , V_10 ) ;
else
F_91 ( V_62 , V_101 -> V_30 , V_10 ) ;
break;
default:
F_79 ( V_62 , L_19 ,
F_10 ( V_10 ) ) ;
F_88 ( V_10 ) ;
}
}
int F_140 ( struct V_61 * V_62 )
{
if ( ! V_62 -> V_68 . V_242 )
V_62 -> V_68 . V_242 = F_43 ;
if ( ! V_62 -> V_68 . V_243 )
V_62 -> V_68 . V_243 = F_44 ;
if ( ! V_62 -> V_68 . V_244 )
V_62 -> V_68 . V_244 = F_110 ;
if ( ! V_62 -> V_68 . V_245 )
V_62 -> V_68 . V_245 = F_35 ;
if ( ! V_62 -> V_68 . V_246 )
V_62 -> V_68 . V_246 = F_74 ;
if ( ! V_62 -> V_68 . V_247 )
V_62 -> V_68 . V_247 = F_64 ;
if ( ! V_62 -> V_68 . V_248 )
V_62 -> V_68 . V_248 = F_103 ;
if ( ! V_62 -> V_68 . V_249 )
V_62 -> V_68 . V_249 = F_48 ;
if ( ! V_62 -> V_68 . V_250 )
V_62 -> V_68 . V_250 = F_89 ;
if ( ! V_62 -> V_68 . V_251 )
V_62 -> V_68 . V_251 = F_90 ;
return 0 ;
}
int F_141 ( void )
{
V_237 = F_142 ( L_20 , sizeof( struct V_6 ) ,
0 , V_252 , NULL ) ;
if ( ! V_237 )
return - V_77 ;
V_104 = 1 ;
V_51 = 0 ;
while ( V_104 < V_253 ) {
V_104 <<= 1 ;
V_51 ++ ;
}
V_104 -- ;
V_59 = F_143 ( L_21 ) ;
if ( ! V_59 )
goto V_98;
return 0 ;
V_98:
F_144 ( V_237 ) ;
return - V_77 ;
}
void F_145 ( void )
{
F_146 ( V_59 ) ;
F_144 ( V_237 ) ;
}
