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
static inline void F_21 ( struct V_6 * V_7 )
{
if ( F_22 ( & V_7 -> V_37 ) ) {
F_23 ( V_7 , L_2 ) ;
F_24 ( & V_7 -> V_8 ) ;
}
}
static inline void F_25 ( struct V_6 * V_7 ,
unsigned int V_38 )
{
if ( V_7 -> V_39 & ( V_40 | V_41 ) )
return;
F_23 ( V_7 , L_3 , V_38 ) ;
F_4 ( V_7 ) ;
if ( ! F_26 ( V_42 , & V_7 -> V_37 ,
F_27 ( V_38 ) ) )
F_18 ( V_7 ) ;
}
static void F_28 ( struct V_6 * V_7 , unsigned int V_38 )
{
F_29 ( & V_7 -> V_43 ) ;
F_25 ( V_7 , V_38 ) ;
F_30 ( & V_7 -> V_43 ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
int V_44 = 1 ;
if ( V_7 -> V_39 & V_41 )
return V_44 ;
V_7 -> V_34 |= V_35 ;
if ( ! ( V_7 -> V_34 & V_45 ) ) {
V_7 -> V_39 |= V_41 ;
F_21 ( V_7 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static inline struct V_6 * F_32 ( struct V_46 * V_47 ,
T_2 V_48 )
{
struct V_6 * * V_49 = (struct V_6 * * ) ( V_47 + 1 ) ;
return V_49 [ V_48 ] ;
}
static inline void F_33 ( struct V_46 * V_47 , T_2 V_48 ,
struct V_6 * V_7 )
{
( (struct V_6 * * ) ( V_47 + 1 ) ) [ V_48 ] = V_7 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_46 * V_47 ;
T_2 V_48 ;
V_47 = V_7 -> V_47 ;
F_29 ( & V_47 -> V_50 ) ;
F_16 ( V_47 -> V_51 <= 0 ) ;
V_47 -> V_51 -- ;
V_48 = ( V_7 -> V_52 - V_7 -> V_31 -> V_53 ) >> V_54 ;
if ( V_47 -> V_55 == V_56 )
V_47 -> V_55 = V_48 ;
else if ( V_47 -> V_57 == V_56 )
V_47 -> V_57 = V_48 ;
else
V_47 -> V_58 = V_48 ;
F_33 ( V_47 , V_48 , NULL ) ;
F_35 ( & V_7 -> V_59 ) ;
F_30 ( & V_47 -> V_50 ) ;
F_18 ( V_7 ) ;
}
static int F_36 ( struct V_60 * V_61 , struct V_62 * V_63 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 = F_7 ( V_10 ) ;
int error = - V_64 ;
T_1 V_11 ;
T_3 V_65 = V_13 -> V_65 ;
V_7 = F_37 ( V_63 ) ;
if ( V_7 -> V_34 & ( V_35 | V_66 ) ) {
F_38 ( V_10 ) ;
goto V_67;
}
F_16 ( ! ( V_7 -> V_34 & V_68 ) ) ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_6 ( V_7 , V_10 , V_11 ) ;
F_40 ( V_10 ) = V_7 -> V_69 ;
if ( F_41 ( V_10 ) )
V_63 -> V_17 += F_42 ( ( F_12 ( V_10 ) - sizeof( * V_13 ) ) ,
F_41 ( V_10 ) ) ;
else
V_63 -> V_17 ++ ;
error = V_61 -> V_70 . V_71 ( V_61 , V_10 ) ;
if ( V_65 == V_72 )
goto V_67;
V_7 -> V_11 = V_11 & ~ V_73 ;
if ( V_11 & V_74 )
V_7 -> V_34 &= ~ V_68 ;
V_67:
return error ;
}
static int F_43 ( struct V_60 * V_61 , struct V_62 * V_63 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_37 ( V_63 ) ;
F_29 ( & V_7 -> V_43 ) ;
error = F_36 ( V_61 , V_63 , V_10 ) ;
F_30 ( & V_7 -> V_43 ) ;
return error ;
}
static struct V_62 * F_44 ( struct V_6 * V_7 , T_3 V_75 )
{
struct V_62 * V_63 ;
V_63 = & V_7 -> V_16 ;
V_63 -> V_76 = 0 ;
V_63 -> V_17 = 0 ;
V_63 -> V_27 = V_75 ;
return V_63 ;
}
static struct V_62 * F_45 ( struct V_62 * V_63 )
{
struct V_6 * V_7 = F_37 ( V_63 ) ;
V_63 = F_44 ( V_7 , V_7 -> V_75 ++ ) ;
F_23 ( V_7 , L_4 ,
V_7 -> V_11 , V_63 -> V_27 ) ;
return V_63 ;
}
static struct V_62 * F_46 ( struct V_62 * V_63 )
{
struct V_6 * V_7 = F_37 ( V_63 ) ;
F_29 ( & V_7 -> V_43 ) ;
V_63 = F_45 ( V_63 ) ;
F_30 ( & V_7 -> V_43 ) ;
return V_63 ;
}
static void F_47 ( struct V_62 * V_63 ,
void (* F_48)( struct V_62 * , struct V_9 * ,
void * ) ,
void * V_33 )
{
struct V_6 * V_7 = F_37 ( V_63 ) ;
F_49 ( V_77 ) ;
F_29 ( & V_7 -> V_43 ) ;
while ( V_7 -> V_78 && V_7 -> V_79 != V_80 ) {
F_50 ( & V_7 -> V_81 , & V_77 , V_82 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_51 () ;
F_29 ( & V_7 -> V_43 ) ;
}
F_52 ( & V_7 -> V_81 , & V_77 ) ;
V_7 -> F_48 = F_48 ;
V_7 -> V_33 = V_33 ;
F_30 ( & V_7 -> V_43 ) ;
}
static int F_53 ( struct V_6 * V_7 ,
unsigned int V_38 )
{
struct V_62 * V_63 ;
struct V_9 * V_10 ;
int error ;
if ( V_7 -> V_34 & ( V_35 | V_66 ) ||
V_7 -> V_39 & ( V_41 | V_40 ) )
return - V_64 ;
V_63 = F_45 ( & V_7 -> V_16 ) ;
if ( ! V_63 )
return - V_83 ;
if ( V_38 )
F_25 ( V_7 , V_38 ) ;
if ( V_7 -> V_84 ) {
V_10 = F_54 ( V_7 -> V_85 , 0 ) ;
if ( V_10 ) {
V_7 -> V_34 |= V_68 ;
F_55 ( V_10 , V_86 , V_7 -> V_87 , V_7 -> V_84 ,
V_72 , V_18 |
V_74 , 0 ) ;
error = F_36 ( V_7 -> V_85 , V_63 , V_10 ) ;
} else {
error = - V_88 ;
}
} else {
error = 0 ;
}
V_7 -> V_34 |= V_66 ;
return error ;
}
static int F_56 ( const struct V_62 * V_89 ,
unsigned int V_38 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_37 ( V_89 ) ;
F_29 ( & V_7 -> V_43 ) ;
error = F_53 ( V_7 , V_38 ) ;
F_30 ( & V_7 -> V_43 ) ;
return error ;
}
static bool F_57 ( struct V_6 * V_7 , struct V_62 * V_63 ,
struct V_9 * V_10 )
{
void (* F_48)( struct V_62 * , struct V_9 * V_10 , void * V_33 );
void * V_33 ;
bool V_90 = false ;
F_29 ( & V_7 -> V_43 ) ;
V_7 -> V_78 ++ ;
if ( V_7 -> V_79 != V_80 )
V_7 -> V_79 = ! V_7 -> V_79 ? V_80 : NULL ;
F_48 = V_7 -> F_48 ;
V_33 = V_7 -> V_33 ;
F_30 ( & V_7 -> V_43 ) ;
if ( F_48 ) {
F_48 ( V_63 , V_10 , V_33 ) ;
V_90 = true ;
} else if ( ! F_58 ( V_10 ) ) {
F_38 ( V_10 ) ;
}
F_29 ( & V_7 -> V_43 ) ;
if ( -- V_7 -> V_78 == 0 )
V_7 -> V_79 = NULL ;
F_30 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_78 == 0 )
F_59 ( & V_7 -> V_81 ) ;
return V_90 ;
}
static void F_60 ( struct V_91 * V_92 )
{
struct V_6 * V_7 = F_61 ( V_92 , struct V_6 ,
V_37 . V_92 ) ;
struct V_62 * V_63 = & V_7 -> V_16 ;
T_1 V_93 ;
int V_44 = 1 ;
F_23 ( V_7 , L_5 ) ;
F_29 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_39 & ( V_40 | V_41 ) )
goto V_94;
V_93 = V_7 -> V_34 ;
if ( V_93 & V_35 ) {
V_7 -> V_34 = V_93 & ~ V_45 ;
F_30 ( & V_7 -> V_43 ) ;
if ( V_93 & V_45 )
F_62 ( V_7 ) ;
goto V_95;
} else {
if ( V_93 & V_66 )
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
F_57 ( V_7 , V_63 , F_63 ( - V_96 ) ) ;
F_47 ( V_63 , NULL , V_7 -> V_33 ) ;
F_56 ( V_63 , 2 * V_7 -> V_97 ) ;
goto V_95;
}
V_94:
F_30 ( & V_7 -> V_43 ) ;
V_95:
F_18 ( V_7 ) ;
}
static struct V_6 * F_64 ( struct V_60 * V_61 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
unsigned int V_98 ;
T_2 V_48 ;
struct V_46 * V_47 ;
V_7 = F_65 ( V_30 -> V_36 , V_99 ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_100 . V_101 ) ;
goto V_67;
}
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_98 = F_66 () ;
V_47 = F_67 ( V_30 -> V_47 , V_98 ) ;
F_29 ( & V_47 -> V_50 ) ;
F_68 () ;
if ( V_47 -> V_55 != V_56 ) {
V_48 = V_47 -> V_55 ;
V_47 -> V_55 = V_56 ;
goto V_102;
}
if ( V_47 -> V_57 != V_56 ) {
V_48 = V_47 -> V_57 ;
V_47 -> V_57 = V_56 ;
goto V_102;
}
V_48 = V_47 -> V_58 ;
while ( F_32 ( V_47 , V_48 ) ) {
V_48 = V_48 == V_30 -> V_103 ? 0 : V_48 + 1 ;
if ( V_48 == V_47 -> V_58 )
goto V_104;
}
V_47 -> V_58 = V_48 == V_30 -> V_103 ? 0 : V_48 + 1 ;
V_102:
F_4 ( V_7 ) ;
F_69 ( & V_7 -> V_43 ) ;
F_29 ( & V_7 -> V_43 ) ;
F_33 ( V_47 , V_48 , V_7 ) ;
F_70 ( & V_7 -> V_59 , & V_47 -> V_59 ) ;
F_44 ( V_7 , V_7 -> V_75 ++ ) ;
V_47 -> V_51 ++ ;
F_30 ( & V_47 -> V_50 ) ;
V_7 -> V_23 = V_7 -> V_52 = ( V_48 << V_54 | V_98 ) + V_30 -> V_53 ;
V_7 -> V_31 = V_30 ;
V_7 -> V_47 = V_47 ;
V_7 -> V_85 = V_61 ;
V_7 -> V_11 = V_73 ;
V_7 -> V_25 = V_56 ;
V_7 -> V_15 = V_30 -> V_15 ;
V_7 -> V_78 = 0 ;
F_71 ( & V_7 -> V_81 ) ;
F_72 ( & V_7 -> V_37 , F_60 ) ;
V_67:
return V_7 ;
V_104:
F_30 ( & V_47 -> V_50 ) ;
F_5 ( & V_30 -> V_100 . V_105 ) ;
F_20 ( V_7 , V_30 -> V_36 ) ;
return NULL ;
}
static inline struct V_6 * F_73 ( struct V_60 * V_61 ,
struct V_9 * V_10 )
{
struct V_106 * V_107 ;
F_74 (ema, &lport->ema_list, ema_list)
if ( ! V_107 -> V_108 || V_107 -> V_108 ( V_10 ) )
return F_64 ( V_61 , V_107 -> V_30 ) ;
return NULL ;
}
static struct V_6 * F_75 ( struct V_29 * V_30 , T_2 V_52 )
{
struct V_46 * V_47 ;
struct V_6 * V_7 = NULL ;
if ( ( V_52 >= V_30 -> V_53 ) && ( V_52 <= V_30 -> V_109 ) ) {
V_47 = F_67 ( V_30 -> V_47 , V_52 & V_110 ) ;
F_29 ( & V_47 -> V_50 ) ;
V_7 = F_32 ( V_47 , ( V_52 - V_30 -> V_53 ) >> V_54 ) ;
if ( V_7 ) {
F_16 ( V_7 -> V_52 != V_52 ) ;
F_4 ( V_7 ) ;
}
F_30 ( & V_47 -> V_50 ) ;
}
return V_7 ;
}
static void F_76 ( struct V_62 * V_63 )
{
struct V_6 * V_7 = F_37 ( V_63 ) ;
int V_44 ;
F_29 ( & V_7 -> V_43 ) ;
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_47 ( V_63 , NULL , V_7 -> V_33 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
}
static struct V_6 * F_77 ( struct V_60 * V_61 ,
struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
V_7 = F_73 ( V_61 , V_10 ) ;
if ( V_7 ) {
V_7 -> V_15 = F_78 ( V_10 ) ;
V_7 -> V_11 |= V_111 ;
V_7 -> V_11 &= ~ V_73 ;
V_13 = F_7 ( V_10 ) ;
V_7 -> V_84 = F_39 ( V_13 -> V_112 ) ;
V_7 -> V_87 = F_39 ( V_13 -> V_113 ) ;
V_7 -> V_114 = V_7 -> V_87 ;
V_7 -> V_25 = V_7 -> V_52 ;
V_7 -> V_23 = F_79 ( V_13 -> V_22 ) ;
V_7 -> V_34 |= V_115 | V_68 ;
if ( ( F_39 ( V_13 -> V_21 ) & V_74 ) == 0 )
V_7 -> V_34 &= ~ V_68 ;
F_4 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
}
return V_7 ;
}
static enum V_116 F_80 ( struct V_60 * V_61 ,
struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_6 * V_7 = NULL ;
struct V_62 * V_63 = NULL ;
enum V_116 V_117 = V_118 ;
T_1 V_11 ;
T_2 V_52 ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_16 ( ( V_11 & V_119 ) != 0 ) ;
if ( V_11 & V_111 ) {
V_52 = F_79 ( V_13 -> V_22 ) ;
V_7 = F_75 ( V_30 , V_52 ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_100 . V_120 ) ;
V_117 = V_121 ;
goto V_67;
}
if ( V_7 -> V_25 == V_56 )
V_7 -> V_25 = F_79 ( V_13 -> V_24 ) ;
else if ( V_7 -> V_25 != F_79 ( V_13 -> V_24 ) ) {
V_117 = V_121 ;
goto V_122;
}
} else {
V_52 = F_79 ( V_13 -> V_24 ) ;
if ( V_52 == 0 && V_13 -> V_123 == V_124 &&
F_81 ( V_10 ) == V_125 ) {
V_13 -> V_24 = F_17 ( V_56 ) ;
V_52 = V_56 ;
}
V_7 = F_75 ( V_30 , V_52 ) ;
if ( ( V_11 & V_73 ) && F_82 ( F_8 ( V_10 ) ) ) {
if ( V_7 ) {
F_5 ( & V_30 -> V_100 . V_126 ) ;
V_117 = V_127 ;
goto V_122;
}
V_7 = F_77 ( V_61 , V_30 , V_10 ) ;
if ( ! V_7 ) {
V_117 = V_128 ;
goto V_67;
}
V_52 = V_7 -> V_52 ;
} else if ( ! V_7 ) {
F_5 ( & V_30 -> V_100 . V_120 ) ;
V_117 = V_127 ;
goto V_67;
}
}
F_29 ( & V_7 -> V_43 ) ;
if ( F_82 ( F_8 ( V_10 ) ) ) {
V_63 = & V_7 -> V_16 ;
V_63 -> V_76 |= V_129 ;
V_63 -> V_27 = V_13 -> V_26 ;
} else {
V_63 = & V_7 -> V_16 ;
if ( V_63 -> V_27 != V_13 -> V_26 ) {
F_5 ( & V_30 -> V_100 . V_130 ) ;
if ( V_11 & V_18 ) {
V_63 -> V_76 |= V_129 ;
V_63 -> V_27 = V_13 -> V_26 ;
} else {
F_30 ( & V_7 -> V_43 ) ;
V_117 = V_131 ;
goto V_122;
}
}
}
F_16 ( V_7 != F_37 ( V_63 ) ) ;
if ( V_11 & V_74 )
V_7 -> V_34 |= V_68 ;
F_30 ( & V_7 -> V_43 ) ;
F_83 ( V_10 ) = V_63 ;
V_67:
return V_117 ;
V_122:
F_76 ( & V_7 -> V_16 ) ;
F_18 ( V_7 ) ;
return V_117 ;
}
static struct V_62 * F_84 ( struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_6 * V_7 ;
struct V_62 * V_63 = NULL ;
T_1 V_11 ;
T_2 V_52 ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_16 ( ( V_11 & V_119 ) != V_119 ) ;
V_52 = F_79 ( ( V_11 & V_111 ) ? V_13 -> V_22 : V_13 -> V_24 ) ;
V_7 = F_75 ( V_30 , V_52 ) ;
if ( ! V_7 )
return NULL ;
if ( V_7 -> V_16 . V_27 == V_13 -> V_26 ) {
V_63 = & V_7 -> V_16 ;
if ( ( V_11 & V_111 ) != 0 &&
V_7 -> V_25 == V_56 ) {
V_7 -> V_25 = F_79 ( V_13 -> V_24 ) ;
}
}
F_18 ( V_7 ) ;
return V_63 ;
}
static void F_85 ( struct V_6 * V_7 ,
T_1 V_132 , T_1 V_133 )
{
V_7 -> V_114 = V_132 ;
if ( V_7 -> V_34 & V_115 ) {
V_7 -> V_84 = V_133 ;
V_7 -> V_87 = V_132 ;
} else {
V_7 -> V_84 = V_132 ;
V_7 -> V_87 = V_133 ;
}
}
static void F_86 ( struct V_9 * V_10 , enum V_134 V_135 ,
struct V_136 * V_137 )
{
switch ( V_135 ) {
case V_138 :
F_87 ( V_10 , V_137 -> V_139 , V_137 -> V_140 ) ;
break;
case V_141 :
F_88 ( V_10 ) ;
break;
case V_142 :
F_89 ( V_10 ) ;
break;
case V_143 :
F_90 ( V_10 ) ;
break;
default:
F_91 ( F_92 ( V_10 ) , L_6 , V_135 ) ;
}
}
static void F_93 ( struct V_62 * V_63 , struct V_9 * V_10 ,
enum V_144 V_145 , enum V_146 V_65 )
{
T_1 V_11 ;
struct V_6 * V_7 = F_37 ( V_63 ) ;
V_11 = V_147 | V_18 | V_74 ;
V_11 |= V_7 -> V_11 ;
F_55 ( V_10 , V_145 , V_7 -> V_87 , V_7 -> V_84 , V_65 , V_11 , 0 ) ;
F_36 ( V_7 -> V_85 , V_63 , V_10 ) ;
}
static void F_94 ( struct V_62 * V_63 , const struct V_9 * V_148 )
{
struct V_9 * V_10 ;
struct V_12 * V_149 ;
struct V_12 * V_13 ;
struct V_6 * V_7 = F_37 ( V_63 ) ;
struct V_60 * V_61 = V_7 -> V_85 ;
unsigned int V_11 ;
if ( F_11 ( F_8 ( V_148 ) ) ) {
V_10 = F_54 ( V_61 , 0 ) ;
if ( ! V_10 )
return;
V_13 = F_7 ( V_10 ) ;
V_13 -> V_123 = V_150 ;
V_13 -> V_65 = V_72 ;
V_149 = F_7 ( V_148 ) ;
V_11 = F_39 ( V_149 -> V_21 ) ;
V_11 &= V_111 | V_119 |
V_73 | V_147 |
V_18 | V_151 | V_74 |
V_152 | V_153 ;
V_11 ^= V_111 | V_119 ;
F_15 ( V_13 -> V_21 , V_11 ) ;
F_6 ( V_7 , V_10 , V_11 ) ;
V_13 -> V_26 = V_149 -> V_26 ;
V_13 -> V_28 = V_149 -> V_28 ;
V_13 -> V_154 = F_95 ( 1 ) ;
F_8 ( V_10 ) = F_8 ( V_148 ) ;
if ( V_11 & V_18 )
F_10 ( V_10 ) = V_19 ;
else
F_10 ( V_10 ) = V_20 ;
V_61 -> V_70 . V_71 ( V_61 , V_10 ) ;
}
}
static void F_96 ( struct V_9 * V_148 ,
enum V_155 V_139 ,
enum V_156 V_140 )
{
struct V_9 * V_10 ;
struct V_12 * V_149 ;
struct V_12 * V_13 ;
struct V_157 * V_158 ;
struct V_60 * V_61 ;
unsigned int V_11 ;
V_61 = F_92 ( V_148 ) ;
V_10 = F_54 ( V_61 , sizeof( * V_158 ) ) ;
if ( ! V_10 )
return;
V_13 = F_7 ( V_10 ) ;
V_149 = F_7 ( V_148 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) + sizeof( * V_158 ) ) ;
V_158 = F_97 ( V_10 , sizeof( * V_158 ) ) ;
V_158 -> V_159 = V_139 ;
V_158 -> V_160 = V_140 ;
memcpy ( V_13 -> V_113 , V_149 -> V_112 , 3 ) ;
memcpy ( V_13 -> V_112 , V_149 -> V_113 , 3 ) ;
V_13 -> V_22 = V_149 -> V_22 ;
V_13 -> V_24 = V_149 -> V_24 ;
V_13 -> V_28 = V_149 -> V_28 ;
V_13 -> V_123 = V_161 ;
V_13 -> V_65 = V_72 ;
V_11 = F_39 ( V_149 -> V_21 ) ;
V_11 &= V_111 | V_119 |
V_151 | V_74 |
V_152 | V_153 ;
V_11 ^= V_111 | V_119 ;
V_11 |= V_147 | V_18 ;
V_11 &= ~ V_73 ;
F_15 ( V_13 -> V_21 , V_11 ) ;
F_8 ( V_10 ) = F_98 ( F_8 ( V_148 ) ) ;
F_10 ( V_10 ) = V_19 ;
if ( F_11 ( F_8 ( V_10 ) ) )
F_10 ( V_10 ) = V_20 ;
V_61 -> V_70 . V_71 ( V_61 , V_10 ) ;
}
static void F_99 ( struct V_6 * V_7 , struct V_9 * V_148 )
{
struct V_9 * V_10 ;
struct V_162 * V_163 ;
struct V_12 * V_13 ;
struct V_62 * V_63 ;
if ( ! V_7 )
goto V_117;
V_10 = F_54 ( V_7 -> V_85 , sizeof( * V_163 ) ) ;
if ( ! V_10 )
goto free;
F_29 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_34 & V_35 ) {
F_30 ( & V_7 -> V_43 ) ;
F_38 ( V_10 ) ;
goto V_117;
}
if ( ! ( V_7 -> V_34 & V_45 ) ) {
V_7 -> V_34 |= V_45 ;
F_4 ( V_7 ) ;
}
F_25 ( V_7 , V_7 -> V_97 ) ;
V_13 = F_7 ( V_10 ) ;
V_163 = F_97 ( V_10 , sizeof( * V_163 ) ) ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
V_63 = & V_7 -> V_16 ;
V_163 -> V_164 = F_17 ( 0xffff ) ;
if ( V_63 -> V_76 & V_129 ) {
V_163 -> V_165 = V_63 -> V_27 ;
V_163 -> V_166 = V_167 ;
V_163 -> V_164 = V_13 -> V_28 ;
V_163 -> V_168 = F_17 ( V_63 -> V_17 ) ;
}
V_63 = F_45 ( V_63 ) ;
F_93 ( V_63 , V_10 , V_169 , V_72 ) ;
V_7 -> V_34 |= V_66 ;
F_30 ( & V_7 -> V_43 ) ;
free:
F_38 ( V_148 ) ;
return;
V_117:
F_96 ( V_148 , V_170 , V_171 ) ;
goto free;
}
static struct V_62 * F_100 ( struct V_60 * V_61 , struct V_9 * V_10 )
{
struct V_106 * V_107 ;
F_16 ( V_61 != F_92 ( V_10 ) ) ;
F_16 ( F_83 ( V_10 ) ) ;
F_83 ( V_10 ) = NULL ;
F_74 (ema, &lport->ema_list, ema_list)
if ( ( ! V_107 -> V_108 || V_107 -> V_108 ( V_10 ) ) &&
F_80 ( V_61 , V_107 -> V_30 , V_10 ) == V_118 )
break;
return F_83 ( V_10 ) ;
}
static void F_101 ( struct V_62 * V_63 )
{
F_18 ( F_37 ( V_63 ) ) ;
}
static void F_102 ( struct V_60 * V_61 , struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_62 * V_63 = NULL ;
struct V_6 * V_7 = NULL ;
enum V_116 V_117 ;
V_61 = F_103 ( V_61 , F_39 ( V_13 -> V_112 ) ) ;
if ( ! V_61 ) {
F_38 ( V_10 ) ;
return;
}
F_92 ( V_10 ) = V_61 ;
F_104 ( F_83 ( V_10 ) ) ;
if ( V_13 -> V_24 == F_17 ( V_56 ) )
return V_61 -> V_70 . V_172 ( V_61 , V_10 ) ;
V_117 = F_80 ( V_61 , V_30 , V_10 ) ;
if ( V_117 == V_118 ) {
V_63 = F_83 ( V_10 ) ;
V_7 = F_37 ( V_63 ) ;
F_94 ( V_63 , V_10 ) ;
V_7 -> V_69 = F_40 ( V_10 ) ;
if ( ! F_57 ( V_7 , V_63 , V_10 ) )
V_61 -> V_70 . V_172 ( V_61 , V_10 ) ;
F_18 ( V_7 ) ;
} else {
F_91 ( V_61 , L_7 ,
V_117 ) ;
F_38 ( V_10 ) ;
}
}
static void F_105 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_62 * V_63 ;
struct V_6 * V_7 ;
enum V_173 V_174 ;
T_1 V_11 ;
int V_44 ;
V_7 = F_75 ( V_30 , F_79 ( V_13 -> V_22 ) ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_100 . V_120 ) ;
goto V_67;
}
if ( V_7 -> V_34 & V_35 ) {
F_5 ( & V_30 -> V_100 . V_120 ) ;
goto V_122;
}
if ( V_7 -> V_25 == V_56 )
V_7 -> V_25 = F_79 ( V_13 -> V_24 ) ;
if ( V_7 -> V_84 != 0 && V_7 -> V_84 != F_39 ( V_13 -> V_112 ) ) {
F_5 ( & V_30 -> V_100 . V_120 ) ;
goto V_122;
}
if ( V_7 -> V_87 != F_39 ( V_13 -> V_113 ) &&
V_7 -> V_87 != V_175 ) {
F_5 ( & V_30 -> V_100 . V_120 ) ;
goto V_122;
}
V_174 = F_8 ( V_10 ) ;
V_63 = & V_7 -> V_16 ;
if ( F_82 ( V_174 ) ) {
V_63 -> V_76 |= V_129 ;
V_63 -> V_27 = V_13 -> V_26 ;
} else if ( V_63 -> V_27 != V_13 -> V_26 ) {
F_5 ( & V_30 -> V_100 . V_130 ) ;
goto V_122;
}
V_11 = F_39 ( V_13 -> V_21 ) ;
F_83 ( V_10 ) = V_63 ;
F_29 ( & V_7 -> V_43 ) ;
if ( V_11 & V_74 )
V_7 -> V_34 |= V_68 ;
F_30 ( & V_7 -> V_43 ) ;
if ( F_11 ( V_174 ) )
F_94 ( V_63 , V_10 ) ;
if ( V_13 -> V_65 != V_176 && F_10 ( V_10 ) == V_19 &&
( V_11 & ( V_147 | V_18 ) ) ==
( V_147 | V_18 ) ) {
F_29 ( & V_7 -> V_43 ) ;
V_44 = F_31 ( V_7 ) ;
F_16 ( F_37 ( V_63 ) != V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
}
F_57 ( V_7 , V_63 , V_10 ) ;
F_18 ( V_7 ) ;
return;
V_122:
F_18 ( V_7 ) ;
V_67:
F_38 ( V_10 ) ;
}
static void F_106 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_62 * V_63 ;
V_63 = F_84 ( V_30 , V_10 ) ;
if ( ! V_63 )
F_5 ( & V_30 -> V_100 . V_120 ) ;
else
F_5 ( & V_30 -> V_100 . V_177 ) ;
F_38 ( V_10 ) ;
}
static void F_107 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_162 * V_163 ;
struct V_62 * V_63 ;
T_2 V_178 ;
T_2 V_179 ;
int V_44 = 1 , V_180 = 0 ;
V_13 = F_7 ( V_10 ) ;
F_23 ( V_7 , L_8 , V_13 -> V_123 ,
F_2 ( V_13 -> V_123 ) ) ;
if ( F_108 ( & V_7 -> V_37 ) ) {
F_23 ( V_7 , L_9 ) ;
F_18 ( V_7 ) ;
}
F_29 ( & V_7 -> V_43 ) ;
switch ( V_13 -> V_123 ) {
case V_169 :
V_163 = F_97 ( V_10 , sizeof( * V_163 ) ) ;
if ( ! V_163 )
break;
V_178 = F_79 ( V_163 -> V_168 ) ;
V_179 = F_79 ( V_163 -> V_164 ) ;
if ( ( V_7 -> V_34 & V_45 ) == 0 &&
( V_163 -> V_166 != V_167 ||
V_163 -> V_165 == V_7 -> V_75 ) && V_178 != V_179 ) {
V_7 -> V_34 |= V_45 ;
F_4 ( V_7 ) ;
V_180 = 1 ;
}
break;
case V_161 :
break;
default:
break;
}
V_63 = & V_7 -> V_16 ;
if ( V_7 -> V_65 != V_176 &&
F_39 ( V_13 -> V_21 ) & V_147 )
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_4 ( V_7 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
F_57 ( V_7 , V_63 , V_10 ) ;
if ( V_180 )
F_28 ( V_7 , V_7 -> V_97 ) ;
F_18 ( V_7 ) ;
}
static void F_109 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_6 * V_7 ;
T_1 V_11 ;
V_13 = F_7 ( V_10 ) ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_83 ( V_10 ) = NULL ;
V_7 = F_75 ( V_30 , ( V_11 & V_111 ) ?
F_79 ( V_13 -> V_22 ) : F_79 ( V_13 -> V_24 ) ) ;
if ( V_7 && ( V_11 & V_74 ) ) {
F_29 ( & V_7 -> V_43 ) ;
V_7 -> V_34 |= V_68 ;
F_30 ( & V_7 -> V_43 ) ;
}
if ( V_11 & V_119 ) {
switch ( V_13 -> V_123 ) {
case V_150 :
case V_181 :
break;
default:
if ( V_7 )
F_23 ( V_7 , L_10 ,
V_13 -> V_123 ,
F_2 ( V_13 -> V_123 ) ) ;
break;
}
F_38 ( V_10 ) ;
} else {
switch ( V_13 -> V_123 ) {
case V_161 :
case V_169 :
if ( V_7 )
F_107 ( V_7 , V_10 ) ;
else
F_38 ( V_10 ) ;
break;
case V_86 :
F_99 ( V_7 , V_10 ) ;
break;
default:
F_38 ( V_10 ) ;
break;
}
}
if ( V_7 )
F_18 ( V_7 ) ;
}
static void F_88 ( struct V_9 * V_148 )
{
struct V_60 * V_61 ;
struct V_182 * V_183 ;
struct V_9 * V_10 ;
V_61 = F_92 ( V_148 ) ;
V_10 = F_54 ( V_61 , sizeof( * V_183 ) ) ;
if ( ! V_10 )
return;
V_183 = F_97 ( V_10 , sizeof( * V_183 ) ) ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_184 = V_141 ;
F_110 ( V_10 , V_148 , V_185 , 0 ) ;
V_61 -> V_70 . V_71 ( V_61 , V_10 ) ;
}
static void F_87 ( struct V_9 * V_148 , enum V_186 V_139 ,
enum V_187 V_140 )
{
struct V_60 * V_61 ;
struct V_188 * V_189 ;
struct V_9 * V_10 ;
V_61 = F_92 ( V_148 ) ;
V_10 = F_54 ( V_61 , sizeof( * V_189 ) ) ;
if ( ! V_10 )
return;
V_189 = F_97 ( V_10 , sizeof( * V_189 ) ) ;
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
V_189 -> V_190 = V_138 ;
V_189 -> V_191 = V_139 ;
V_189 -> V_192 = V_140 ;
F_110 ( V_10 , V_148 , V_185 , 0 ) ;
V_61 -> V_70 . V_71 ( V_61 , V_10 ) ;
}
static void F_111 ( struct V_6 * V_7 )
{
struct V_62 * V_63 ;
int V_44 = 1 ;
F_29 ( & V_7 -> V_43 ) ;
F_53 ( V_7 , 0 ) ;
V_7 -> V_39 |= V_40 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_34 & V_45 )
F_24 ( & V_7 -> V_8 ) ;
V_7 -> V_34 &= ~ V_45 ;
V_63 = & V_7 -> V_16 ;
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_4 ( V_7 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
F_57 ( V_7 , V_63 , F_63 ( - V_193 ) ) ;
F_47 ( V_63 , NULL , V_7 -> V_33 ) ;
F_18 ( V_7 ) ;
}
static void F_112 ( struct V_60 * V_61 ,
struct V_46 * V_47 ,
T_1 V_84 , T_1 V_87 )
{
struct V_6 * V_7 ;
struct V_6 * V_194 ;
F_29 ( & V_47 -> V_50 ) ;
V_195:
F_113 (ep, next, &pool->ex_list, ex_list) {
if ( ( V_61 == V_7 -> V_85 ) &&
( V_84 == 0 || V_84 == V_7 -> V_84 ) &&
( V_87 == 0 || V_87 == V_7 -> V_87 ) ) {
F_4 ( V_7 ) ;
F_30 ( & V_47 -> V_50 ) ;
F_111 ( V_7 ) ;
F_18 ( V_7 ) ;
F_29 ( & V_47 -> V_50 ) ;
goto V_195;
}
}
V_47 -> V_58 = 0 ;
V_47 -> V_55 = V_56 ;
V_47 -> V_57 = V_56 ;
F_30 ( & V_47 -> V_50 ) ;
}
void F_114 ( struct V_60 * V_61 , T_1 V_84 , T_1 V_87 )
{
struct V_106 * V_107 ;
unsigned int V_98 ;
F_74 (ema, &lport->ema_list, ema_list) {
F_115 (cpu)
F_112 ( V_61 ,
F_67 ( V_107 -> V_30 -> V_47 , V_98 ) ,
V_84 , V_87 ) ;
}
}
static struct V_6 * F_116 ( struct V_60 * V_61 , T_1 V_52 )
{
struct V_106 * V_107 ;
F_74 (ema, &lport->ema_list, ema_list)
if ( V_107 -> V_30 -> V_53 <= V_52 && V_52 <= V_107 -> V_30 -> V_109 )
return F_75 ( V_107 -> V_30 , V_52 ) ;
return NULL ;
}
static void F_90 ( struct V_9 * V_196 )
{
struct V_60 * V_61 ;
struct V_9 * V_10 ;
struct V_6 * V_7 ;
struct V_197 * V_158 ;
struct V_198 * V_183 ;
enum V_186 V_139 = V_199 ;
enum V_187 V_140 ;
T_1 V_84 ;
T_2 V_25 ;
T_2 V_23 ;
V_61 = F_92 ( V_196 ) ;
V_158 = F_97 ( V_196 , sizeof( * V_158 ) ) ;
V_140 = V_200 ;
if ( ! V_158 )
goto V_117;
V_84 = F_39 ( V_158 -> V_201 ) ;
V_25 = F_79 ( V_158 -> V_202 ) ;
V_23 = F_79 ( V_158 -> V_203 ) ;
V_7 = F_116 ( V_61 ,
V_84 == F_117 ( V_61 -> V_204 ) ? V_23 : V_25 ) ;
V_140 = V_205 ;
if ( ! V_7 )
goto V_117;
if ( V_7 -> V_114 != V_84 || V_23 != V_7 -> V_23 )
goto V_122;
if ( V_25 != V_56 && V_25 != V_7 -> V_25 )
goto V_122;
V_10 = F_54 ( V_61 , sizeof( * V_183 ) ) ;
if ( ! V_10 )
goto V_67;
V_183 = F_97 ( V_10 , sizeof( * V_183 ) ) ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_206 = V_141 ;
V_183 -> V_207 = V_158 -> V_203 ;
memcpy ( V_183 -> V_208 , V_158 -> V_201 , 3 ) ;
V_183 -> V_209 = F_17 ( V_7 -> V_25 ) ;
if ( V_7 -> V_84 == V_7 -> V_114 )
F_15 ( V_183 -> V_210 , V_7 -> V_87 ) ;
else
F_15 ( V_183 -> V_210 , V_7 -> V_84 ) ;
V_183 -> V_211 = F_95 ( V_7 -> V_16 . V_212 ) ;
V_183 -> V_213 = F_95 ( V_7 -> V_34 & ( V_115 |
V_68 |
V_35 ) ) ;
F_110 ( V_10 , V_196 , V_185 , 0 ) ;
V_61 -> V_70 . V_71 ( V_61 , V_10 ) ;
V_67:
F_18 ( V_7 ) ;
return;
V_122:
F_18 ( V_7 ) ;
V_117:
F_87 ( V_196 , V_139 , V_140 ) ;
}
static void F_118 ( struct V_62 * V_63 , struct V_9 * V_10 , void * V_33 )
{
struct V_6 * V_214 = V_33 ;
unsigned int V_1 ;
if ( F_58 ( V_10 ) ) {
int V_104 = F_119 ( V_10 ) ;
if ( V_104 == - V_193 || V_104 == - V_96 )
goto V_215;
F_23 ( V_214 , L_11
L_12 , V_104 ) ;
return;
}
V_1 = F_81 ( V_10 ) ;
F_38 ( V_10 ) ;
switch ( V_1 ) {
case V_138 :
F_23 ( V_214 , L_13 ) ;
case V_141 :
goto V_215;
default:
F_23 ( V_214 , L_14 ,
V_1 ) ;
return;
}
V_215:
F_76 ( & V_214 -> V_16 ) ;
F_18 ( V_214 ) ;
}
static struct V_62 * F_120 ( struct V_60 * V_61 ,
struct V_9 * V_10 ,
void (* F_48)( struct V_62 * ,
struct V_9 * V_10 ,
void * V_33 ) ,
void (* V_32)( struct V_62 * ,
void * ) ,
void * V_33 , T_1 V_38 )
{
struct V_6 * V_7 ;
struct V_62 * V_63 = NULL ;
struct V_12 * V_13 ;
struct V_216 * V_217 = NULL ;
int V_44 = 1 ;
V_7 = F_73 ( V_61 , V_10 ) ;
if ( ! V_7 ) {
F_38 ( V_10 ) ;
return NULL ;
}
V_7 -> V_34 |= V_68 ;
V_13 = F_7 ( V_10 ) ;
F_85 ( V_7 , F_39 ( V_13 -> V_113 ) , F_39 ( V_13 -> V_112 ) ) ;
V_7 -> F_48 = F_48 ;
V_7 -> V_32 = V_32 ;
V_7 -> V_33 = V_33 ;
V_7 -> V_97 = V_218 ;
V_7 -> V_85 = V_61 ;
V_63 = & V_7 -> V_16 ;
V_7 -> V_65 = V_13 -> V_65 ;
V_7 -> V_11 = F_39 ( V_13 -> V_21 ) ;
F_6 ( V_7 , V_10 , V_7 -> V_11 ) ;
V_63 -> V_17 ++ ;
if ( V_7 -> V_52 <= V_61 -> V_219 && V_13 -> V_123 == V_220 ) {
V_217 = F_121 ( V_10 ) ;
F_122 ( F_121 ( V_10 ) , V_7 -> V_52 ) ;
}
if ( F_123 ( V_61 -> V_70 . V_71 ( V_61 , V_10 ) ) )
goto V_104;
if ( V_38 )
F_25 ( V_7 , V_38 ) ;
V_7 -> V_11 &= ~ V_73 ;
if ( V_7 -> V_11 & V_74 )
V_7 -> V_34 &= ~ V_68 ;
F_30 ( & V_7 -> V_43 ) ;
return V_63 ;
V_104:
if ( V_217 )
F_124 ( V_217 ) ;
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
return NULL ;
}
static void F_62 ( struct V_6 * V_7 )
{
struct V_60 * V_61 ;
struct V_221 * V_222 ;
struct V_9 * V_10 ;
T_1 V_87 ;
V_61 = V_7 -> V_85 ;
V_10 = F_54 ( V_61 , sizeof( * V_222 ) ) ;
if ( ! V_10 )
goto V_223;
V_222 = F_97 ( V_10 , sizeof( * V_222 ) ) ;
memset ( V_222 , 0 , sizeof( * V_222 ) ) ;
V_222 -> V_224 = V_142 ;
F_15 ( V_222 -> V_225 , V_7 -> V_84 ) ;
V_222 -> V_226 = F_17 ( V_7 -> V_23 ) ;
V_222 -> V_227 = F_17 ( V_7 -> V_25 ) ;
V_87 = V_7 -> V_87 ;
if ( V_7 -> V_34 & V_115 )
V_87 = V_7 -> V_84 ;
F_55 ( V_10 , V_124 , V_87 ,
V_61 -> V_228 , V_229 ,
V_73 | V_18 | V_74 , 0 ) ;
if ( F_120 ( V_61 , V_10 , F_118 , NULL , V_7 ,
V_61 -> V_230 ) )
return;
V_223:
F_29 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_39 & ( V_40 | V_41 ) ) {
F_30 ( & V_7 -> V_43 ) ;
F_18 ( V_7 ) ;
return;
}
V_7 -> V_34 |= V_45 ;
F_25 ( V_7 , V_7 -> V_97 ) ;
F_30 ( & V_7 -> V_43 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
struct V_60 * V_61 ;
struct V_6 * V_7 = NULL ;
struct V_221 * V_158 ;
T_1 V_84 ;
T_2 V_52 ;
enum V_187 V_140 ;
V_61 = F_92 ( V_10 ) ;
V_158 = F_97 ( V_10 , sizeof( * V_158 ) ) ;
V_140 = V_200 ;
if ( ! V_158 )
goto V_117;
V_84 = F_39 ( V_158 -> V_225 ) ;
V_52 = F_117 ( V_61 -> V_204 ) == V_84 ?
F_79 ( V_158 -> V_226 ) : F_79 ( V_158 -> V_227 ) ;
V_7 = F_116 ( V_61 , V_52 ) ;
V_140 = V_205 ;
if ( ! V_7 )
goto V_117;
F_29 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_23 != F_79 ( V_158 -> V_226 ) )
goto V_231;
if ( V_7 -> V_25 != F_79 ( V_158 -> V_227 ) &&
V_7 -> V_25 != V_56 )
goto V_231;
V_140 = V_232 ;
if ( V_7 -> V_84 != V_84 )
goto V_231;
if ( V_7 -> V_34 & V_45 ) {
V_7 -> V_34 &= ~ V_45 ;
F_24 ( & V_7 -> V_8 ) ;
}
if ( V_7 -> V_34 & V_35 )
F_21 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_88 ( V_10 ) ;
goto V_67;
V_231:
F_30 ( & V_7 -> V_43 ) ;
V_117:
F_87 ( V_10 , V_199 , V_140 ) ;
V_67:
if ( V_7 )
F_18 ( V_7 ) ;
}
void F_125 ( struct V_60 * V_61 )
{
struct V_233 * V_234 ;
struct V_106 * V_107 ;
struct V_29 * V_30 ;
V_234 = & V_61 -> V_235 ;
F_74 (ema, &lport->ema_list, ema_list) {
V_30 = V_107 -> V_30 ;
V_234 -> V_236 += F_126 ( & V_30 -> V_100 . V_101 ) ;
V_234 -> V_237 +=
F_126 ( & V_30 -> V_100 . V_105 ) ;
V_234 -> V_238 += F_126 ( & V_30 -> V_100 . V_120 ) ;
V_234 -> V_239 += F_126 ( & V_30 -> V_100 . V_126 ) ;
V_234 -> V_240 += F_126 ( & V_30 -> V_100 . V_130 ) ;
V_234 -> V_241 += F_126 ( & V_30 -> V_100 . V_177 ) ;
}
}
struct V_106 * F_127 ( struct V_60 * V_61 ,
struct V_29 * V_30 ,
bool (* V_108)( struct V_9 * ) )
{
struct V_106 * V_107 ;
V_107 = F_128 ( sizeof( * V_107 ) , V_99 ) ;
if ( ! V_107 )
return V_107 ;
V_107 -> V_30 = V_30 ;
V_107 -> V_108 = V_108 ;
F_70 ( & V_107 -> V_242 , & V_61 -> V_242 ) ;
F_129 ( & V_30 -> V_243 ) ;
return V_107 ;
}
static void F_130 ( struct V_243 * V_243 )
{
struct V_29 * V_30 = F_61 ( V_243 , struct V_29 , V_243 ) ;
F_131 ( V_30 -> V_36 ) ;
F_132 ( V_30 -> V_47 ) ;
F_133 ( V_30 ) ;
}
void F_134 ( struct V_106 * V_107 )
{
F_35 ( & V_107 -> V_242 ) ;
F_135 ( & V_107 -> V_30 -> V_243 , F_130 ) ;
F_133 ( V_107 ) ;
}
int F_136 ( struct V_60 * V_244 , struct V_60 * V_245 )
{
struct V_106 * V_107 , * V_246 ;
F_74 (ema, &src->ema_list, ema_list) {
if ( ! F_127 ( V_245 , V_107 -> V_30 , V_107 -> V_108 ) )
goto V_104;
}
return 0 ;
V_104:
F_113 (ema, tmp, &dst->ema_list, ema_list)
F_134 ( V_107 ) ;
return - V_83 ;
}
struct V_29 * F_137 ( struct V_60 * V_61 ,
enum V_247 V_15 ,
T_2 V_53 , T_2 V_109 ,
bool (* V_108)( struct V_9 * ) )
{
struct V_29 * V_30 ;
T_2 V_248 ;
T_4 V_249 ;
unsigned int V_98 ;
struct V_46 * V_47 ;
if ( V_109 <= V_53 || V_109 == V_56 ||
( V_53 & V_110 ) != 0 ) {
F_91 ( V_61 , L_15 ,
V_53 , V_109 ) ;
return NULL ;
}
V_30 = F_138 ( sizeof( struct V_29 ) , V_99 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_15 = V_15 ;
V_30 -> V_53 = V_53 ;
V_248 = ( V_250 - sizeof( * V_47 ) ) /
sizeof( struct V_6 * ) ;
if ( ( V_109 - V_53 + 1 ) / ( V_110 + 1 ) > V_248 ) {
V_30 -> V_109 = V_248 * ( V_110 + 1 ) +
V_53 - 1 ;
} else {
V_30 -> V_109 = V_109 ;
V_248 = ( V_30 -> V_109 - V_30 -> V_53 + 1 ) /
( V_110 + 1 ) ;
}
V_30 -> V_36 = F_139 ( 2 , V_251 ) ;
if ( ! V_30 -> V_36 )
goto V_252;
V_30 -> V_103 = V_248 - 1 ;
V_249 = sizeof( * V_47 ) + V_248 * sizeof( struct V_6 * ) ;
V_30 -> V_47 = F_140 ( V_249 , F_141 ( struct V_46 ) ) ;
if ( ! V_30 -> V_47 )
goto V_253;
F_115 (cpu) {
V_47 = F_67 ( V_30 -> V_47 , V_98 ) ;
V_47 -> V_58 = 0 ;
V_47 -> V_55 = V_56 ;
V_47 -> V_57 = V_56 ;
F_69 ( & V_47 -> V_50 ) ;
F_142 ( & V_47 -> V_59 ) ;
}
F_143 ( & V_30 -> V_243 ) ;
if ( ! F_127 ( V_61 , V_30 , V_108 ) ) {
F_132 ( V_30 -> V_47 ) ;
goto V_253;
}
F_135 ( & V_30 -> V_243 , F_130 ) ;
return V_30 ;
V_253:
F_131 ( V_30 -> V_36 ) ;
V_252:
F_133 ( V_30 ) ;
return NULL ;
}
void F_144 ( struct V_60 * V_61 )
{
struct V_106 * V_107 , * V_194 ;
F_145 ( V_42 ) ;
F_113 (ema, next, &lport->ema_list, ema_list)
F_134 ( V_107 ) ;
}
static struct V_106 * F_146 ( T_1 V_11 ,
struct V_60 * V_61 ,
struct V_12 * V_13 )
{
struct V_106 * V_107 ;
T_2 V_52 ;
if ( V_11 & V_111 )
V_52 = F_79 ( V_13 -> V_22 ) ;
else {
V_52 = F_79 ( V_13 -> V_24 ) ;
if ( V_52 == V_56 )
return F_147 ( V_61 -> V_242 . V_254 ,
F_148 ( * V_107 ) , V_242 ) ;
}
F_74 (ema, &lport->ema_list, ema_list) {
if ( ( V_52 >= V_107 -> V_30 -> V_53 ) &&
( V_52 <= V_107 -> V_30 -> V_109 ) )
return V_107 ;
}
return NULL ;
}
void F_149 ( struct V_60 * V_61 , struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_106 * V_107 ;
T_1 V_11 ;
if ( ! V_61 || V_61 -> V_39 == V_255 ) {
F_91 ( V_61 , L_16
L_17 ) ;
F_38 ( V_10 ) ;
return;
}
V_11 = F_39 ( V_13 -> V_21 ) ;
V_107 = F_146 ( V_11 , V_61 , V_13 ) ;
if ( ! V_107 ) {
F_91 ( V_61 , L_18
L_19 ,
V_11 ,
( V_11 & V_111 ) ?
F_79 ( V_13 -> V_22 ) :
F_79 ( V_13 -> V_24 ) ) ;
F_38 ( V_10 ) ;
return;
}
switch ( F_10 ( V_10 ) ) {
case V_19 :
if ( V_11 & V_18 )
F_150 ( F_14 ( V_10 ) , F_12 ( V_10 ) - F_151 ( V_11 ) ) ;
case V_20 :
if ( V_13 -> V_65 == V_72 )
F_109 ( V_107 -> V_30 , V_10 ) ;
else if ( ( V_11 & ( V_111 | V_119 ) ) ==
V_111 )
F_105 ( V_107 -> V_30 , V_10 ) ;
else if ( V_11 & V_119 )
F_106 ( V_107 -> V_30 , V_10 ) ;
else
F_102 ( V_61 , V_107 -> V_30 , V_10 ) ;
break;
default:
F_91 ( V_61 , L_20 ,
F_10 ( V_10 ) ) ;
F_38 ( V_10 ) ;
}
}
int F_152 ( struct V_60 * V_61 )
{
if ( ! V_61 -> V_70 . V_256 )
V_61 -> V_70 . V_256 = F_46 ;
if ( ! V_61 -> V_70 . V_257 )
V_61 -> V_70 . V_257 = F_47 ;
if ( ! V_61 -> V_70 . V_258 )
V_61 -> V_70 . V_258 = F_120 ;
if ( ! V_61 -> V_70 . V_259 )
V_61 -> V_70 . V_259 = F_43 ;
if ( ! V_61 -> V_70 . V_260 )
V_61 -> V_70 . V_260 = F_86 ;
if ( ! V_61 -> V_70 . V_261 )
V_61 -> V_70 . V_261 = F_76 ;
if ( ! V_61 -> V_70 . V_262 )
V_61 -> V_70 . V_262 = F_114 ;
if ( ! V_61 -> V_70 . V_263 )
V_61 -> V_70 . V_263 = F_56 ;
if ( ! V_61 -> V_70 . V_264 )
V_61 -> V_70 . V_264 = F_100 ;
if ( ! V_61 -> V_70 . V_265 )
V_61 -> V_70 . V_265 = F_101 ;
return 0 ;
}
int F_153 ( void )
{
V_251 = F_154 ( L_21 , sizeof( struct V_6 ) ,
0 , V_266 , NULL ) ;
if ( ! V_251 )
return - V_83 ;
V_54 = F_155 ( F_156 ( V_267 ) ) ;
V_110 = ( 1 << V_54 ) - 1 ;
V_42 = F_157 ( L_22 ) ;
if ( ! V_42 )
goto V_104;
return 0 ;
V_104:
F_158 ( V_251 ) ;
return - V_83 ;
}
void F_159 ( void )
{
F_160 ( V_42 ) ;
F_158 ( V_251 ) ;
}
