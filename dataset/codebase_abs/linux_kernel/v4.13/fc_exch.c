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
F_27 ( V_38 ) ) ) {
F_23 ( V_7 , L_4 ) ;
F_18 ( V_7 ) ;
}
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
if ( ! ( V_7 -> V_39 & V_55 ) ) {
if ( V_47 -> V_56 == V_57 )
V_47 -> V_56 = V_48 ;
else if ( V_47 -> V_58 == V_57 )
V_47 -> V_58 = V_48 ;
else
V_47 -> V_59 = V_48 ;
F_33 ( V_47 , V_48 , NULL ) ;
} else {
F_33 ( V_47 , V_48 , & V_60 ) ;
}
F_35 ( & V_7 -> V_61 ) ;
F_30 ( & V_47 -> V_50 ) ;
F_18 ( V_7 ) ;
}
static int F_36 ( struct V_62 * V_63 , struct V_64 * V_65 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 = F_7 ( V_10 ) ;
int error = - V_66 ;
T_1 V_11 ;
T_3 V_67 = V_13 -> V_67 ;
V_7 = F_37 ( V_65 ) ;
if ( V_7 -> V_34 & ( V_35 | V_68 ) ) {
F_38 ( V_10 ) ;
goto V_69;
}
F_16 ( ! ( V_7 -> V_34 & V_70 ) ) ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_6 ( V_7 , V_10 , V_11 ) ;
F_40 ( V_10 ) = V_7 -> V_71 ;
if ( F_41 ( V_10 ) )
V_65 -> V_17 += F_42 ( ( F_12 ( V_10 ) - sizeof( * V_13 ) ) ,
F_41 ( V_10 ) ) ;
else
V_65 -> V_17 ++ ;
error = V_63 -> V_72 . V_73 ( V_63 , V_10 ) ;
if ( V_67 == V_74 )
goto V_69;
V_7 -> V_11 = V_11 & ~ V_75 ;
if ( V_11 & V_76 )
V_7 -> V_34 &= ~ V_70 ;
V_69:
return error ;
}
int F_43 ( struct V_62 * V_63 , struct V_64 * V_65 , struct V_9 * V_10 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_37 ( V_65 ) ;
F_29 ( & V_7 -> V_43 ) ;
error = F_36 ( V_63 , V_65 , V_10 ) ;
F_30 ( & V_7 -> V_43 ) ;
return error ;
}
static struct V_64 * F_44 ( struct V_6 * V_7 , T_3 V_77 )
{
struct V_64 * V_65 ;
V_65 = & V_7 -> V_16 ;
V_65 -> V_78 = 0 ;
V_65 -> V_17 = 0 ;
V_65 -> V_27 = V_77 ;
return V_65 ;
}
static struct V_64 * F_45 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = F_37 ( V_65 ) ;
V_65 = F_44 ( V_7 , V_7 -> V_77 ++ ) ;
F_23 ( V_7 , L_5 ,
V_7 -> V_11 , V_65 -> V_27 ) ;
return V_65 ;
}
struct V_64 * F_46 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = F_37 ( V_65 ) ;
F_29 ( & V_7 -> V_43 ) ;
V_65 = F_45 ( V_65 ) ;
F_30 ( & V_7 -> V_43 ) ;
return V_65 ;
}
void F_47 ( struct V_64 * V_65 ,
void (* F_48)( struct V_64 * , struct V_9 * , void * ) ,
void * V_33 )
{
struct V_6 * V_7 = F_37 ( V_65 ) ;
F_49 ( V_79 ) ;
F_29 ( & V_7 -> V_43 ) ;
while ( V_7 -> V_80 && V_7 -> V_81 != V_82 ) {
F_50 ( & V_7 -> V_83 , & V_79 , V_84 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_51 () ;
F_29 ( & V_7 -> V_43 ) ;
}
F_52 ( & V_7 -> V_83 , & V_79 ) ;
V_7 -> F_48 = F_48 ;
V_7 -> V_33 = V_33 ;
F_30 ( & V_7 -> V_43 ) ;
}
static int F_53 ( struct V_6 * V_7 ,
unsigned int V_38 )
{
struct V_64 * V_65 ;
struct V_9 * V_10 ;
int error ;
F_23 ( V_7 , L_6 , V_38 ) ;
if ( V_7 -> V_34 & ( V_35 | V_68 ) ||
V_7 -> V_39 & ( V_41 | V_40 ) ) {
F_23 ( V_7 , L_7 ,
V_7 -> V_34 , V_7 -> V_39 ) ;
return - V_66 ;
}
V_65 = F_45 ( & V_7 -> V_16 ) ;
if ( ! V_65 )
return - V_85 ;
if ( V_38 )
F_25 ( V_7 , V_38 ) ;
if ( V_7 -> V_86 ) {
V_10 = F_54 ( V_7 -> V_87 , 0 ) ;
if ( V_10 ) {
V_7 -> V_34 |= V_70 ;
F_55 ( V_10 , V_88 , V_7 -> V_89 , V_7 -> V_86 ,
V_74 , V_18 |
V_76 , 0 ) ;
error = F_36 ( V_7 -> V_87 , V_65 , V_10 ) ;
} else {
error = - V_90 ;
}
} else {
error = 0 ;
}
V_7 -> V_34 |= V_68 ;
return error ;
}
int F_56 ( const struct V_64 * V_91 , unsigned int V_38 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_37 ( V_91 ) ;
F_29 ( & V_7 -> V_43 ) ;
error = F_53 ( V_7 , V_38 ) ;
F_30 ( & V_7 -> V_43 ) ;
return error ;
}
static bool F_57 ( struct V_6 * V_7 , struct V_64 * V_65 ,
struct V_9 * V_10 )
{
void (* F_48)( struct V_64 * , struct V_9 * V_10 , void * V_33 );
void * V_33 ;
bool V_92 = false ;
F_29 ( & V_7 -> V_43 ) ;
V_7 -> V_80 ++ ;
if ( V_7 -> V_81 != V_82 )
V_7 -> V_81 = ! V_7 -> V_81 ? V_82 : NULL ;
F_48 = V_7 -> F_48 ;
V_33 = V_7 -> V_33 ;
F_30 ( & V_7 -> V_43 ) ;
if ( F_48 ) {
F_48 ( V_65 , V_10 , V_33 ) ;
V_92 = true ;
}
F_29 ( & V_7 -> V_43 ) ;
if ( -- V_7 -> V_80 == 0 )
V_7 -> V_81 = NULL ;
F_30 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_80 == 0 )
F_58 ( & V_7 -> V_83 ) ;
return V_92 ;
}
static void F_59 ( struct V_93 * V_94 )
{
struct V_6 * V_7 = F_60 ( V_94 , struct V_6 ,
V_37 . V_94 ) ;
struct V_64 * V_65 = & V_7 -> V_16 ;
T_1 V_95 ;
int V_44 = 1 ;
F_23 ( V_7 , L_8 , V_7 -> V_39 ) ;
F_29 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_39 & ( V_40 | V_41 ) )
goto V_96;
V_95 = V_7 -> V_34 ;
if ( V_95 & V_35 ) {
V_7 -> V_34 = V_95 & ~ V_45 ;
F_30 ( & V_7 -> V_43 ) ;
if ( V_95 & V_45 )
F_61 ( V_7 ) ;
goto V_97;
} else {
if ( V_95 & V_68 )
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
F_57 ( V_7 , V_65 , F_62 ( - V_98 ) ) ;
F_47 ( V_65 , NULL , V_7 -> V_33 ) ;
F_56 ( V_65 , 2 * V_7 -> V_99 ) ;
goto V_97;
}
V_96:
F_30 ( & V_7 -> V_43 ) ;
V_97:
F_18 ( V_7 ) ;
}
static struct V_6 * F_63 ( struct V_62 * V_63 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
unsigned int V_100 ;
T_2 V_48 ;
struct V_46 * V_47 ;
V_7 = F_64 ( V_30 -> V_36 , V_101 ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_102 . V_103 ) ;
goto V_69;
}
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_100 = F_65 () ;
V_47 = F_66 ( V_30 -> V_47 , V_100 ) ;
F_29 ( & V_47 -> V_50 ) ;
F_67 () ;
if ( V_47 -> V_56 != V_57 ) {
if ( ! F_16 ( F_32 ( V_47 , V_47 -> V_56 ) ) ) {
V_48 = V_47 -> V_56 ;
V_47 -> V_56 = V_57 ;
goto V_104;
}
}
if ( V_47 -> V_58 != V_57 ) {
if ( ! F_16 ( F_32 ( V_47 , V_47 -> V_58 ) ) ) {
V_48 = V_47 -> V_58 ;
V_47 -> V_58 = V_57 ;
goto V_104;
}
}
V_48 = V_47 -> V_59 ;
while ( F_32 ( V_47 , V_48 ) ) {
V_48 = V_48 == V_30 -> V_105 ? 0 : V_48 + 1 ;
if ( V_48 == V_47 -> V_59 )
goto V_106;
}
V_47 -> V_59 = V_48 == V_30 -> V_105 ? 0 : V_48 + 1 ;
V_104:
F_4 ( V_7 ) ;
F_68 ( & V_7 -> V_43 ) ;
F_29 ( & V_7 -> V_43 ) ;
F_33 ( V_47 , V_48 , V_7 ) ;
F_69 ( & V_7 -> V_61 , & V_47 -> V_61 ) ;
F_44 ( V_7 , V_7 -> V_77 ++ ) ;
V_47 -> V_51 ++ ;
F_30 ( & V_47 -> V_50 ) ;
V_7 -> V_23 = V_7 -> V_52 = ( V_48 << V_54 | V_100 ) + V_30 -> V_53 ;
V_7 -> V_31 = V_30 ;
V_7 -> V_47 = V_47 ;
V_7 -> V_87 = V_63 ;
V_7 -> V_11 = V_75 ;
V_7 -> V_25 = V_57 ;
V_7 -> V_15 = V_30 -> V_15 ;
V_7 -> V_80 = 0 ;
F_70 ( & V_7 -> V_83 ) ;
F_71 ( & V_7 -> V_37 , F_59 ) ;
V_69:
return V_7 ;
V_106:
F_30 ( & V_47 -> V_50 ) ;
F_5 ( & V_30 -> V_102 . V_107 ) ;
F_20 ( V_7 , V_30 -> V_36 ) ;
return NULL ;
}
static struct V_6 * F_72 ( struct V_62 * V_63 ,
struct V_9 * V_10 )
{
struct V_108 * V_109 ;
struct V_6 * V_7 ;
F_73 (ema, &lport->ema_list, ema_list) {
if ( ! V_109 -> V_110 || V_109 -> V_110 ( V_10 ) ) {
V_7 = F_63 ( V_63 , V_109 -> V_30 ) ;
if ( V_7 )
return V_7 ;
}
}
return NULL ;
}
static struct V_6 * F_74 ( struct V_29 * V_30 , T_2 V_52 )
{
struct V_62 * V_63 = V_30 -> V_63 ;
struct V_46 * V_47 ;
struct V_6 * V_7 = NULL ;
T_2 V_100 = V_52 & V_111 ;
if ( V_52 == V_57 )
return NULL ;
if ( V_100 >= V_112 || ! F_75 ( V_100 ) ) {
F_76 ( L_9 ,
V_63 -> V_113 -> V_114 , V_63 -> V_115 , V_52 , V_100 ) ;
return NULL ;
}
if ( ( V_52 >= V_30 -> V_53 ) && ( V_52 <= V_30 -> V_116 ) ) {
V_47 = F_66 ( V_30 -> V_47 , V_100 ) ;
F_29 ( & V_47 -> V_50 ) ;
V_7 = F_32 ( V_47 , ( V_52 - V_30 -> V_53 ) >> V_54 ) ;
if ( V_7 == & V_60 ) {
F_77 ( V_63 , L_10 , V_52 ) ;
V_7 = NULL ;
}
if ( V_7 ) {
F_16 ( V_7 -> V_52 != V_52 ) ;
F_4 ( V_7 ) ;
}
F_30 ( & V_47 -> V_50 ) ;
}
return V_7 ;
}
void F_78 ( struct V_64 * V_65 )
{
struct V_6 * V_7 = F_37 ( V_65 ) ;
int V_44 ;
F_29 ( & V_7 -> V_43 ) ;
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_47 ( V_65 , NULL , V_7 -> V_33 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
}
static struct V_6 * F_79 ( struct V_62 * V_63 ,
struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
V_7 = F_72 ( V_63 , V_10 ) ;
if ( V_7 ) {
V_7 -> V_15 = F_80 ( V_10 ) ;
V_7 -> V_11 |= V_117 ;
V_7 -> V_11 &= ~ V_75 ;
V_13 = F_7 ( V_10 ) ;
V_7 -> V_86 = F_39 ( V_13 -> V_118 ) ;
V_7 -> V_89 = F_39 ( V_13 -> V_119 ) ;
V_7 -> V_120 = V_7 -> V_89 ;
V_7 -> V_25 = V_7 -> V_52 ;
V_7 -> V_23 = F_81 ( V_13 -> V_22 ) ;
V_7 -> V_34 |= V_121 | V_70 ;
if ( ( F_39 ( V_13 -> V_21 ) & V_76 ) == 0 )
V_7 -> V_34 &= ~ V_70 ;
F_4 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
}
return V_7 ;
}
static enum V_122 F_82 ( struct V_62 * V_63 ,
struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_6 * V_7 = NULL ;
struct V_64 * V_65 = NULL ;
enum V_122 V_123 = V_124 ;
T_1 V_11 ;
T_2 V_52 ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_16 ( ( V_11 & V_125 ) != 0 ) ;
if ( V_11 & V_117 ) {
V_52 = F_81 ( V_13 -> V_22 ) ;
V_7 = F_74 ( V_30 , V_52 ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_102 . V_126 ) ;
V_123 = V_127 ;
goto V_69;
}
if ( V_7 -> V_25 == V_57 )
V_7 -> V_25 = F_81 ( V_13 -> V_24 ) ;
else if ( V_7 -> V_25 != F_81 ( V_13 -> V_24 ) ) {
V_123 = V_127 ;
goto V_128;
}
} else {
V_52 = F_81 ( V_13 -> V_24 ) ;
if ( V_52 == 0 && V_13 -> V_129 == V_130 &&
F_83 ( V_10 ) == V_131 ) {
V_13 -> V_24 = F_17 ( V_57 ) ;
V_52 = V_57 ;
}
V_7 = F_74 ( V_30 , V_52 ) ;
if ( ( V_11 & V_75 ) && F_84 ( F_8 ( V_10 ) ) ) {
if ( V_7 ) {
F_5 ( & V_30 -> V_102 . V_132 ) ;
V_123 = V_133 ;
goto V_128;
}
V_7 = F_79 ( V_63 , V_30 , V_10 ) ;
if ( ! V_7 ) {
V_123 = V_134 ;
goto V_69;
}
V_52 = V_7 -> V_52 ;
} else if ( ! V_7 ) {
F_5 ( & V_30 -> V_102 . V_126 ) ;
V_123 = V_133 ;
goto V_69;
}
}
F_29 ( & V_7 -> V_43 ) ;
if ( F_84 ( F_8 ( V_10 ) ) ) {
V_65 = & V_7 -> V_16 ;
V_65 -> V_78 |= V_135 ;
V_65 -> V_27 = V_13 -> V_26 ;
} else {
V_65 = & V_7 -> V_16 ;
if ( V_65 -> V_27 != V_13 -> V_26 ) {
F_5 ( & V_30 -> V_102 . V_136 ) ;
if ( V_11 & V_18 ) {
V_65 -> V_78 |= V_135 ;
V_65 -> V_27 = V_13 -> V_26 ;
} else {
F_30 ( & V_7 -> V_43 ) ;
V_123 = V_137 ;
goto V_128;
}
}
}
F_16 ( V_7 != F_37 ( V_65 ) ) ;
if ( V_11 & V_76 )
V_7 -> V_34 |= V_70 ;
F_30 ( & V_7 -> V_43 ) ;
F_85 ( V_10 ) = V_65 ;
V_69:
return V_123 ;
V_128:
F_78 ( & V_7 -> V_16 ) ;
F_18 ( V_7 ) ;
return V_123 ;
}
static struct V_64 * F_86 ( struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_6 * V_7 ;
struct V_64 * V_65 = NULL ;
T_1 V_11 ;
T_2 V_52 ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_16 ( ( V_11 & V_125 ) != V_125 ) ;
V_52 = F_81 ( ( V_11 & V_117 ) ? V_13 -> V_22 : V_13 -> V_24 ) ;
V_7 = F_74 ( V_30 , V_52 ) ;
if ( ! V_7 )
return NULL ;
if ( V_7 -> V_16 . V_27 == V_13 -> V_26 ) {
V_65 = & V_7 -> V_16 ;
if ( ( V_11 & V_117 ) != 0 &&
V_7 -> V_25 == V_57 ) {
V_7 -> V_25 = F_81 ( V_13 -> V_24 ) ;
}
}
F_18 ( V_7 ) ;
return V_65 ;
}
static void F_87 ( struct V_6 * V_7 ,
T_1 V_138 , T_1 V_139 )
{
V_7 -> V_120 = V_138 ;
if ( V_7 -> V_34 & V_121 ) {
V_7 -> V_86 = V_139 ;
V_7 -> V_89 = V_138 ;
} else {
V_7 -> V_86 = V_138 ;
V_7 -> V_89 = V_139 ;
}
}
void F_88 ( struct V_9 * V_10 , enum V_140 V_141 ,
struct V_142 * V_143 )
{
switch ( V_141 ) {
case V_144 :
F_89 ( V_10 , V_143 -> V_145 , V_143 -> V_146 ) ;
break;
case V_147 :
F_90 ( V_10 ) ;
break;
case V_148 :
F_91 ( V_10 ) ;
break;
case V_149 :
F_92 ( V_10 ) ;
break;
default:
F_77 ( F_93 ( V_10 ) , L_11 , V_141 ) ;
}
}
static void F_94 ( struct V_64 * V_65 , struct V_9 * V_10 ,
enum V_150 V_151 , enum V_152 V_67 )
{
T_1 V_11 ;
struct V_6 * V_7 = F_37 ( V_65 ) ;
V_11 = V_153 | V_18 | V_76 ;
V_11 |= V_7 -> V_11 ;
F_55 ( V_10 , V_151 , V_7 -> V_89 , V_7 -> V_86 , V_67 , V_11 , 0 ) ;
F_36 ( V_7 -> V_87 , V_65 , V_10 ) ;
}
static void F_95 ( struct V_64 * V_65 , const struct V_9 * V_154 )
{
struct V_9 * V_10 ;
struct V_12 * V_155 ;
struct V_12 * V_13 ;
struct V_6 * V_7 = F_37 ( V_65 ) ;
struct V_62 * V_63 = V_7 -> V_87 ;
unsigned int V_11 ;
if ( F_11 ( F_8 ( V_154 ) ) ) {
V_10 = F_54 ( V_63 , 0 ) ;
if ( ! V_10 ) {
F_23 ( V_7 , L_12 ) ;
return;
}
V_13 = F_7 ( V_10 ) ;
V_13 -> V_129 = V_156 ;
V_13 -> V_67 = V_74 ;
V_155 = F_7 ( V_154 ) ;
V_11 = F_39 ( V_155 -> V_21 ) ;
V_11 &= V_117 | V_125 |
V_75 | V_153 |
V_18 | V_157 | V_76 |
V_158 | V_159 ;
V_11 ^= V_117 | V_125 ;
F_15 ( V_13 -> V_21 , V_11 ) ;
F_6 ( V_7 , V_10 , V_11 ) ;
V_13 -> V_26 = V_155 -> V_26 ;
V_13 -> V_28 = V_155 -> V_28 ;
V_13 -> V_160 = F_96 ( 1 ) ;
F_8 ( V_10 ) = F_8 ( V_154 ) ;
if ( V_11 & V_18 )
F_10 ( V_10 ) = V_19 ;
else
F_10 ( V_10 ) = V_20 ;
V_63 -> V_72 . V_73 ( V_63 , V_10 ) ;
}
}
static void F_97 ( struct V_9 * V_154 ,
enum V_161 V_145 ,
enum V_162 V_146 )
{
struct V_9 * V_10 ;
struct V_12 * V_155 ;
struct V_12 * V_13 ;
struct V_163 * V_164 ;
struct V_64 * V_65 ;
struct V_62 * V_63 ;
unsigned int V_11 ;
V_63 = F_93 ( V_154 ) ;
V_65 = F_85 ( V_154 ) ;
V_10 = F_54 ( V_63 , sizeof( * V_164 ) ) ;
if ( ! V_10 ) {
F_23 ( F_37 ( V_65 ) ,
L_13 ) ;
return;
}
V_13 = F_7 ( V_10 ) ;
V_155 = F_7 ( V_154 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) + sizeof( * V_164 ) ) ;
V_164 = F_98 ( V_10 , sizeof( * V_164 ) ) ;
V_164 -> V_165 = V_145 ;
V_164 -> V_166 = V_146 ;
memcpy ( V_13 -> V_119 , V_155 -> V_118 , 3 ) ;
memcpy ( V_13 -> V_118 , V_155 -> V_119 , 3 ) ;
V_13 -> V_22 = V_155 -> V_22 ;
V_13 -> V_24 = V_155 -> V_24 ;
V_13 -> V_28 = V_155 -> V_28 ;
V_13 -> V_129 = V_167 ;
V_13 -> V_67 = V_74 ;
V_11 = F_39 ( V_155 -> V_21 ) ;
V_11 &= V_117 | V_125 |
V_157 | V_76 |
V_158 | V_159 ;
V_11 ^= V_117 | V_125 ;
V_11 |= V_153 | V_18 ;
V_11 &= ~ V_75 ;
F_15 ( V_13 -> V_21 , V_11 ) ;
F_8 ( V_10 ) = F_99 ( F_8 ( V_154 ) ) ;
F_10 ( V_10 ) = V_19 ;
if ( F_11 ( F_8 ( V_10 ) ) )
F_10 ( V_10 ) = V_20 ;
V_63 -> V_72 . V_73 ( V_63 , V_10 ) ;
}
static void F_100 ( struct V_6 * V_7 , struct V_9 * V_154 )
{
struct V_9 * V_10 ;
struct V_168 * V_169 ;
struct V_12 * V_13 ;
struct V_64 * V_65 ;
if ( ! V_7 )
goto V_123;
F_23 ( V_7 , L_14 ) ;
V_10 = F_54 ( V_7 -> V_87 , sizeof( * V_169 ) ) ;
if ( ! V_10 ) {
F_23 ( V_7 , L_15 ) ;
goto free;
}
F_29 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_34 & V_35 ) {
F_30 ( & V_7 -> V_43 ) ;
F_23 ( V_7 , L_16 ) ;
F_38 ( V_10 ) ;
goto V_123;
}
if ( ! ( V_7 -> V_34 & V_45 ) ) {
V_7 -> V_34 |= V_45 ;
F_4 ( V_7 ) ;
}
F_25 ( V_7 , V_7 -> V_99 ) ;
V_13 = F_7 ( V_10 ) ;
V_169 = F_98 ( V_10 , sizeof( * V_169 ) ) ;
memset ( V_169 , 0 , sizeof( * V_169 ) ) ;
V_65 = & V_7 -> V_16 ;
V_169 -> V_170 = F_17 ( 0xffff ) ;
if ( V_65 -> V_78 & V_135 ) {
V_169 -> V_171 = V_65 -> V_27 ;
V_169 -> V_172 = V_173 ;
V_169 -> V_170 = V_13 -> V_28 ;
V_169 -> V_174 = F_17 ( V_65 -> V_17 ) ;
}
V_65 = F_45 ( V_65 ) ;
F_94 ( V_65 , V_10 , V_175 , V_74 ) ;
V_7 -> V_34 |= V_68 ;
F_30 ( & V_7 -> V_43 ) ;
free:
F_38 ( V_154 ) ;
return;
V_123:
F_97 ( V_154 , V_176 , V_177 ) ;
goto free;
}
struct V_64 * F_101 ( struct V_62 * V_63 , struct V_9 * V_10 )
{
struct V_108 * V_109 ;
F_16 ( V_63 != F_93 ( V_10 ) ) ;
F_16 ( F_85 ( V_10 ) ) ;
F_85 ( V_10 ) = NULL ;
F_73 (ema, &lport->ema_list, ema_list)
if ( ( ! V_109 -> V_110 || V_109 -> V_110 ( V_10 ) ) &&
F_82 ( V_63 , V_109 -> V_30 , V_10 ) == V_124 )
break;
return F_85 ( V_10 ) ;
}
void F_102 ( struct V_64 * V_65 )
{
F_18 ( F_37 ( V_65 ) ) ;
}
static void F_103 ( struct V_62 * V_63 , struct V_29 * V_30 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_64 * V_65 = NULL ;
struct V_6 * V_7 = NULL ;
enum V_122 V_123 ;
V_63 = F_104 ( V_63 , F_39 ( V_13 -> V_118 ) ) ;
if ( ! V_63 ) {
F_38 ( V_10 ) ;
return;
}
F_93 ( V_10 ) = V_63 ;
F_105 ( F_85 ( V_10 ) ) ;
if ( V_13 -> V_24 == F_17 ( V_57 ) )
return F_106 ( V_63 , V_10 ) ;
V_123 = F_82 ( V_63 , V_30 , V_10 ) ;
if ( V_123 == V_124 ) {
V_65 = F_85 ( V_10 ) ;
V_7 = F_37 ( V_65 ) ;
F_95 ( V_65 , V_10 ) ;
V_7 -> V_71 = F_40 ( V_10 ) ;
if ( ! F_57 ( V_7 , V_65 , V_10 ) )
F_106 ( V_63 , V_10 ) ;
F_18 ( V_7 ) ;
} else {
F_77 ( V_63 , L_17 ,
V_123 ) ;
F_38 ( V_10 ) ;
}
}
static void F_107 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_64 * V_65 ;
struct V_6 * V_7 ;
enum V_178 V_179 ;
T_1 V_11 ;
int V_44 ;
V_7 = F_74 ( V_30 , F_81 ( V_13 -> V_22 ) ) ;
if ( ! V_7 ) {
F_5 ( & V_30 -> V_102 . V_126 ) ;
goto V_69;
}
if ( V_7 -> V_34 & V_35 ) {
F_5 ( & V_30 -> V_102 . V_126 ) ;
goto V_128;
}
if ( V_7 -> V_25 == V_57 )
V_7 -> V_25 = F_81 ( V_13 -> V_24 ) ;
if ( V_7 -> V_86 != 0 && V_7 -> V_86 != F_39 ( V_13 -> V_118 ) ) {
F_5 ( & V_30 -> V_102 . V_126 ) ;
goto V_128;
}
if ( V_7 -> V_89 != F_39 ( V_13 -> V_119 ) &&
V_7 -> V_89 != V_180 ) {
F_5 ( & V_30 -> V_102 . V_126 ) ;
goto V_128;
}
V_179 = F_8 ( V_10 ) ;
V_65 = & V_7 -> V_16 ;
if ( F_84 ( V_179 ) ) {
V_65 -> V_78 |= V_135 ;
V_65 -> V_27 = V_13 -> V_26 ;
}
V_11 = F_39 ( V_13 -> V_21 ) ;
F_85 ( V_10 ) = V_65 ;
F_29 ( & V_7 -> V_43 ) ;
if ( V_11 & V_76 )
V_7 -> V_34 |= V_70 ;
F_30 ( & V_7 -> V_43 ) ;
if ( F_11 ( V_179 ) )
F_95 ( V_65 , V_10 ) ;
if ( V_13 -> V_67 != V_181 && F_10 ( V_10 ) == V_19 &&
( V_11 & ( V_153 | V_18 ) ) ==
( V_153 | V_18 ) ) {
F_29 ( & V_7 -> V_43 ) ;
V_44 = F_31 ( V_7 ) ;
F_16 ( F_37 ( V_65 ) != V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
}
if ( ! F_57 ( V_7 , V_65 , V_10 ) )
F_38 ( V_10 ) ;
F_18 ( V_7 ) ;
return;
V_128:
F_18 ( V_7 ) ;
V_69:
F_38 ( V_10 ) ;
}
static void F_108 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_64 * V_65 ;
V_65 = F_86 ( V_30 , V_10 ) ;
if ( ! V_65 )
F_5 ( & V_30 -> V_102 . V_126 ) ;
else
F_5 ( & V_30 -> V_102 . V_182 ) ;
F_38 ( V_10 ) ;
}
static void F_109 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_168 * V_169 ;
struct V_64 * V_65 ;
T_2 V_183 ;
T_2 V_184 ;
int V_44 = 1 , V_185 = 0 ;
V_13 = F_7 ( V_10 ) ;
F_23 ( V_7 , L_18 , V_13 -> V_129 ,
F_2 ( V_13 -> V_129 ) ) ;
if ( F_110 ( & V_7 -> V_37 ) ) {
F_23 ( V_7 , L_19 ) ;
F_18 ( V_7 ) ;
}
F_29 ( & V_7 -> V_43 ) ;
switch ( V_13 -> V_129 ) {
case V_175 :
V_169 = F_98 ( V_10 , sizeof( * V_169 ) ) ;
if ( ! V_169 )
break;
V_183 = F_81 ( V_169 -> V_174 ) ;
V_184 = F_81 ( V_169 -> V_170 ) ;
if ( ( V_7 -> V_34 & V_45 ) == 0 &&
( V_169 -> V_172 != V_173 ||
V_169 -> V_171 == V_7 -> V_77 ) && V_183 != V_184 ) {
V_7 -> V_34 |= V_45 ;
F_4 ( V_7 ) ;
V_185 = 1 ;
}
break;
case V_167 :
break;
default:
break;
}
V_65 = & V_7 -> V_16 ;
if ( V_7 -> V_67 != V_181 &&
F_39 ( V_13 -> V_21 ) & V_153 )
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_4 ( V_7 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
if ( ! F_57 ( V_7 , V_65 , V_10 ) )
F_38 ( V_10 ) ;
if ( V_185 )
F_28 ( V_7 , V_7 -> V_99 ) ;
F_18 ( V_7 ) ;
}
static void F_111 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_6 * V_7 ;
T_1 V_11 ;
V_13 = F_7 ( V_10 ) ;
V_11 = F_39 ( V_13 -> V_21 ) ;
F_85 ( V_10 ) = NULL ;
V_7 = F_74 ( V_30 , ( V_11 & V_117 ) ?
F_81 ( V_13 -> V_22 ) : F_81 ( V_13 -> V_24 ) ) ;
if ( V_7 && ( V_11 & V_76 ) ) {
F_29 ( & V_7 -> V_43 ) ;
V_7 -> V_34 |= V_70 ;
F_30 ( & V_7 -> V_43 ) ;
}
if ( V_11 & V_125 ) {
switch ( V_13 -> V_129 ) {
case V_156 :
case V_186 :
break;
default:
if ( V_7 )
F_23 ( V_7 , L_20 ,
V_13 -> V_129 ,
F_2 ( V_13 -> V_129 ) ) ;
break;
}
F_38 ( V_10 ) ;
} else {
switch ( V_13 -> V_129 ) {
case V_167 :
case V_175 :
if ( V_7 )
F_109 ( V_7 , V_10 ) ;
else
F_38 ( V_10 ) ;
break;
case V_88 :
if ( V_7 )
F_100 ( V_7 , V_10 ) ;
else
F_38 ( V_10 ) ;
break;
default:
F_38 ( V_10 ) ;
break;
}
}
if ( V_7 )
F_18 ( V_7 ) ;
}
static void F_90 ( struct V_9 * V_154 )
{
struct V_62 * V_63 ;
struct V_187 * V_188 ;
struct V_9 * V_10 ;
struct V_64 * V_65 ;
V_63 = F_93 ( V_154 ) ;
V_65 = F_85 ( V_154 ) ;
V_10 = F_54 ( V_63 , sizeof( * V_188 ) ) ;
if ( ! V_10 ) {
F_23 ( F_37 ( V_65 ) ,
L_21 ) ;
return;
}
V_188 = F_98 ( V_10 , sizeof( * V_188 ) ) ;
memset ( V_188 , 0 , sizeof( * V_188 ) ) ;
V_188 -> V_189 = V_147 ;
F_112 ( V_10 , V_154 , V_190 , 0 ) ;
V_63 -> V_72 . V_73 ( V_63 , V_10 ) ;
}
static void F_89 ( struct V_9 * V_154 , enum V_191 V_145 ,
enum V_192 V_146 )
{
struct V_62 * V_63 ;
struct V_193 * V_194 ;
struct V_9 * V_10 ;
struct V_64 * V_65 ;
V_63 = F_93 ( V_154 ) ;
V_65 = F_85 ( V_154 ) ;
V_10 = F_54 ( V_63 , sizeof( * V_194 ) ) ;
if ( ! V_10 ) {
F_23 ( F_37 ( V_65 ) ,
L_21 ) ;
return;
}
V_194 = F_98 ( V_10 , sizeof( * V_194 ) ) ;
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
V_194 -> V_195 = V_144 ;
V_194 -> V_196 = V_145 ;
V_194 -> V_197 = V_146 ;
F_112 ( V_10 , V_154 , V_190 , 0 ) ;
V_63 -> V_72 . V_73 ( V_63 , V_10 ) ;
}
static void F_113 ( struct V_6 * V_7 )
{
struct V_64 * V_65 ;
int V_44 = 1 ;
F_29 ( & V_7 -> V_43 ) ;
V_7 -> V_39 |= V_40 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_34 & V_45 )
F_24 ( & V_7 -> V_8 ) ;
V_7 -> V_34 &= ~ V_45 ;
V_65 = & V_7 -> V_16 ;
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_4 ( V_7 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
F_57 ( V_7 , V_65 , F_62 ( - V_198 ) ) ;
F_47 ( V_65 , NULL , V_7 -> V_33 ) ;
F_18 ( V_7 ) ;
}
static void F_114 ( struct V_62 * V_63 ,
struct V_46 * V_47 ,
T_1 V_86 , T_1 V_89 )
{
struct V_6 * V_7 ;
struct V_6 * V_199 ;
F_29 ( & V_47 -> V_50 ) ;
V_200:
F_115 (ep, next, &pool->ex_list, ex_list) {
if ( ( V_63 == V_7 -> V_87 ) &&
( V_86 == 0 || V_86 == V_7 -> V_86 ) &&
( V_89 == 0 || V_89 == V_7 -> V_89 ) ) {
F_4 ( V_7 ) ;
F_30 ( & V_47 -> V_50 ) ;
F_113 ( V_7 ) ;
F_18 ( V_7 ) ;
F_29 ( & V_47 -> V_50 ) ;
goto V_200;
}
}
V_47 -> V_59 = 0 ;
V_47 -> V_56 = V_57 ;
V_47 -> V_58 = V_57 ;
F_30 ( & V_47 -> V_50 ) ;
}
void F_116 ( struct V_62 * V_63 , T_1 V_86 , T_1 V_89 )
{
struct V_108 * V_109 ;
unsigned int V_100 ;
F_73 (ema, &lport->ema_list, ema_list) {
F_117 (cpu)
F_114 ( V_63 ,
F_66 ( V_109 -> V_30 -> V_47 , V_100 ) ,
V_86 , V_89 ) ;
}
}
static struct V_6 * F_118 ( struct V_62 * V_63 , T_1 V_52 )
{
struct V_108 * V_109 ;
F_73 (ema, &lport->ema_list, ema_list)
if ( V_109 -> V_30 -> V_53 <= V_52 && V_52 <= V_109 -> V_30 -> V_116 )
return F_74 ( V_109 -> V_30 , V_52 ) ;
return NULL ;
}
static void F_92 ( struct V_9 * V_201 )
{
struct V_62 * V_63 ;
struct V_9 * V_10 ;
struct V_6 * V_7 ;
struct V_202 * V_164 ;
struct V_203 * V_188 ;
enum V_191 V_145 = V_204 ;
enum V_192 V_146 ;
T_1 V_86 ;
T_2 V_52 , V_25 , V_23 ;
V_63 = F_93 ( V_201 ) ;
V_164 = F_98 ( V_201 , sizeof( * V_164 ) ) ;
V_146 = V_205 ;
if ( ! V_164 )
goto V_123;
V_86 = F_39 ( V_164 -> V_206 ) ;
V_25 = F_81 ( V_164 -> V_207 ) ;
V_23 = F_81 ( V_164 -> V_208 ) ;
V_146 = V_209 ;
if ( V_86 == F_119 ( V_63 -> V_113 ) )
V_52 = V_23 ;
else
V_52 = V_25 ;
if ( V_52 == V_57 ) {
F_77 ( V_63 ,
L_22 ,
V_86 , V_25 , V_23 ) ;
goto V_123;
}
V_7 = F_118 ( V_63 , V_52 ) ;
if ( ! V_7 ) {
F_77 ( V_63 ,
L_23 ,
V_86 , V_25 , V_23 ) ;
goto V_123;
}
F_23 ( V_7 , L_24 ,
V_86 , V_25 , V_23 ) ;
if ( V_7 -> V_120 != V_86 || V_23 != V_7 -> V_23 )
goto V_128;
if ( V_25 != V_57 && V_25 != V_7 -> V_25 )
goto V_128;
V_10 = F_54 ( V_63 , sizeof( * V_188 ) ) ;
if ( ! V_10 ) {
F_23 ( V_7 , L_25 ) ;
goto V_69;
}
V_188 = F_98 ( V_10 , sizeof( * V_188 ) ) ;
memset ( V_188 , 0 , sizeof( * V_188 ) ) ;
V_188 -> V_210 = V_147 ;
V_188 -> V_211 = V_164 -> V_208 ;
memcpy ( V_188 -> V_212 , V_164 -> V_206 , 3 ) ;
V_188 -> V_213 = F_17 ( V_7 -> V_25 ) ;
if ( V_7 -> V_86 == V_7 -> V_120 )
F_15 ( V_188 -> V_214 , V_7 -> V_89 ) ;
else
F_15 ( V_188 -> V_214 , V_7 -> V_86 ) ;
V_188 -> V_215 = F_96 ( V_7 -> V_16 . V_216 ) ;
V_188 -> V_217 = F_96 ( V_7 -> V_34 & ( V_121 |
V_70 |
V_35 ) ) ;
F_112 ( V_10 , V_201 , V_190 , 0 ) ;
V_63 -> V_72 . V_73 ( V_63 , V_10 ) ;
V_69:
F_18 ( V_7 ) ;
return;
V_128:
F_18 ( V_7 ) ;
V_123:
F_89 ( V_201 , V_145 , V_146 ) ;
}
static void F_120 ( struct V_64 * V_65 , struct V_9 * V_10 , void * V_33 )
{
struct V_6 * V_218 = V_33 ;
unsigned int V_1 ;
if ( F_121 ( V_10 ) ) {
int V_106 = F_122 ( V_10 ) ;
if ( V_106 == - V_198 || V_106 == - V_98 )
goto V_219;
F_23 ( V_218 , L_26
L_27 , V_106 ) ;
return;
}
V_1 = F_83 ( V_10 ) ;
F_38 ( V_10 ) ;
switch ( V_1 ) {
case V_144 :
F_23 ( V_218 , L_28 ) ;
case V_147 :
goto V_219;
default:
F_23 ( V_218 , L_29 ,
V_1 ) ;
return;
}
V_219:
F_78 ( & V_218 -> V_16 ) ;
F_18 ( V_218 ) ;
}
struct V_64 * F_123 ( struct V_62 * V_63 ,
struct V_9 * V_10 ,
void (* F_48)( struct V_64 * ,
struct V_9 * V_10 ,
void * V_33 ) ,
void (* V_32)( struct V_64 * , void * ) ,
void * V_33 , T_1 V_38 )
{
struct V_6 * V_7 ;
struct V_64 * V_65 = NULL ;
struct V_12 * V_13 ;
struct V_220 * V_221 = NULL ;
int V_44 = 1 ;
V_7 = F_72 ( V_63 , V_10 ) ;
if ( ! V_7 ) {
F_38 ( V_10 ) ;
return NULL ;
}
V_7 -> V_34 |= V_70 ;
V_13 = F_7 ( V_10 ) ;
F_87 ( V_7 , F_39 ( V_13 -> V_119 ) , F_39 ( V_13 -> V_118 ) ) ;
V_7 -> F_48 = F_48 ;
V_7 -> V_32 = V_32 ;
V_7 -> V_33 = V_33 ;
V_7 -> V_99 = V_63 -> V_99 ;
V_7 -> V_87 = V_63 ;
V_65 = & V_7 -> V_16 ;
V_7 -> V_67 = V_13 -> V_67 ;
V_7 -> V_11 = F_39 ( V_13 -> V_21 ) ;
F_6 ( V_7 , V_10 , V_7 -> V_11 ) ;
V_65 -> V_17 ++ ;
if ( V_7 -> V_52 <= V_63 -> V_222 && V_13 -> V_129 == V_223 ) {
V_221 = F_124 ( V_10 ) ;
F_125 ( F_124 ( V_10 ) , V_7 -> V_52 ) ;
}
if ( F_126 ( V_63 -> V_72 . V_73 ( V_63 , V_10 ) ) )
goto V_106;
if ( V_38 )
F_25 ( V_7 , V_38 ) ;
V_7 -> V_11 &= ~ V_75 ;
if ( V_7 -> V_11 & V_76 )
V_7 -> V_34 &= ~ V_70 ;
F_30 ( & V_7 -> V_43 ) ;
return V_65 ;
V_106:
if ( V_221 )
F_127 ( V_221 ) ;
V_44 = F_31 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
if ( ! V_44 )
F_34 ( V_7 ) ;
return NULL ;
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_62 * V_63 ;
struct V_224 * V_225 ;
struct V_9 * V_10 ;
T_1 V_89 ;
V_63 = V_7 -> V_87 ;
V_10 = F_54 ( V_63 , sizeof( * V_225 ) ) ;
if ( ! V_10 )
goto V_226;
V_225 = F_98 ( V_10 , sizeof( * V_225 ) ) ;
memset ( V_225 , 0 , sizeof( * V_225 ) ) ;
V_225 -> V_227 = V_148 ;
F_15 ( V_225 -> V_228 , V_7 -> V_86 ) ;
V_225 -> V_229 = F_17 ( V_7 -> V_23 ) ;
V_225 -> V_230 = F_17 ( V_7 -> V_25 ) ;
V_89 = V_7 -> V_89 ;
if ( V_7 -> V_34 & V_121 )
V_89 = V_7 -> V_86 ;
F_55 ( V_10 , V_130 , V_89 ,
V_63 -> V_115 , V_231 ,
V_75 | V_18 | V_76 , 0 ) ;
if ( F_123 ( V_63 , V_10 , F_120 , NULL , V_7 ,
V_63 -> V_232 ) )
return;
V_226:
F_23 ( V_7 , L_30 ) ;
F_29 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_39 & ( V_40 | V_41 ) ) {
F_30 ( & V_7 -> V_43 ) ;
F_18 ( V_7 ) ;
return;
}
V_7 -> V_34 |= V_45 ;
F_25 ( V_7 , V_7 -> V_99 ) ;
F_30 ( & V_7 -> V_43 ) ;
}
static void F_91 ( struct V_9 * V_10 )
{
struct V_62 * V_63 ;
struct V_6 * V_7 = NULL ;
struct V_224 * V_164 ;
T_1 V_86 ;
T_2 V_52 ;
enum V_192 V_146 ;
V_63 = F_93 ( V_10 ) ;
V_164 = F_98 ( V_10 , sizeof( * V_164 ) ) ;
V_146 = V_205 ;
if ( ! V_164 )
goto V_123;
V_86 = F_39 ( V_164 -> V_228 ) ;
V_52 = F_119 ( V_63 -> V_113 ) == V_86 ?
F_81 ( V_164 -> V_229 ) : F_81 ( V_164 -> V_230 ) ;
V_7 = F_118 ( V_63 , V_52 ) ;
V_146 = V_209 ;
if ( ! V_7 )
goto V_123;
F_29 ( & V_7 -> V_43 ) ;
F_23 ( V_7 , L_31 ,
V_86 , V_52 , F_81 ( V_164 -> V_230 ) , F_81 ( V_164 -> V_229 ) ) ;
if ( V_7 -> V_23 != F_81 ( V_164 -> V_229 ) )
goto V_233;
if ( V_7 -> V_25 != F_81 ( V_164 -> V_230 ) &&
V_7 -> V_25 != V_57 )
goto V_233;
V_146 = V_234 ;
if ( V_7 -> V_86 != V_86 )
goto V_233;
if ( V_7 -> V_34 & V_45 ) {
V_7 -> V_34 &= ~ V_45 ;
F_24 ( & V_7 -> V_8 ) ;
}
if ( V_7 -> V_34 & V_35 )
F_21 ( V_7 ) ;
F_30 ( & V_7 -> V_43 ) ;
F_90 ( V_10 ) ;
goto V_69;
V_233:
F_30 ( & V_7 -> V_43 ) ;
V_123:
F_89 ( V_10 , V_204 , V_146 ) ;
V_69:
if ( V_7 )
F_18 ( V_7 ) ;
}
void F_128 ( struct V_62 * V_63 )
{
struct V_235 * V_236 ;
struct V_108 * V_109 ;
struct V_29 * V_30 ;
V_236 = & V_63 -> V_237 ;
F_73 (ema, &lport->ema_list, ema_list) {
V_30 = V_109 -> V_30 ;
V_236 -> V_238 += F_129 ( & V_30 -> V_102 . V_103 ) ;
V_236 -> V_239 +=
F_129 ( & V_30 -> V_102 . V_107 ) ;
V_236 -> V_240 += F_129 ( & V_30 -> V_102 . V_126 ) ;
V_236 -> V_241 += F_129 ( & V_30 -> V_102 . V_132 ) ;
V_236 -> V_242 += F_129 ( & V_30 -> V_102 . V_136 ) ;
V_236 -> V_243 += F_129 ( & V_30 -> V_102 . V_182 ) ;
}
}
struct V_108 * F_130 ( struct V_62 * V_63 ,
struct V_29 * V_30 ,
bool (* V_110)( struct V_9 * ) )
{
struct V_108 * V_109 ;
V_109 = F_131 ( sizeof( * V_109 ) , V_101 ) ;
if ( ! V_109 )
return V_109 ;
V_109 -> V_30 = V_30 ;
V_109 -> V_110 = V_110 ;
F_69 ( & V_109 -> V_244 , & V_63 -> V_244 ) ;
F_132 ( & V_30 -> V_245 ) ;
return V_109 ;
}
static void F_133 ( struct V_245 * V_245 )
{
struct V_29 * V_30 = F_60 ( V_245 , struct V_29 , V_245 ) ;
F_134 ( V_30 -> V_36 ) ;
F_135 ( V_30 -> V_47 ) ;
F_136 ( V_30 ) ;
}
void F_137 ( struct V_108 * V_109 )
{
F_35 ( & V_109 -> V_244 ) ;
F_138 ( & V_109 -> V_30 -> V_245 , F_133 ) ;
F_136 ( V_109 ) ;
}
int F_139 ( struct V_62 * V_246 , struct V_62 * V_247 )
{
struct V_108 * V_109 , * V_248 ;
F_73 (ema, &src->ema_list, ema_list) {
if ( ! F_130 ( V_247 , V_109 -> V_30 , V_109 -> V_110 ) )
goto V_106;
}
return 0 ;
V_106:
F_115 (ema, tmp, &dst->ema_list, ema_list)
F_137 ( V_109 ) ;
return - V_85 ;
}
struct V_29 * F_140 ( struct V_62 * V_63 ,
enum V_249 V_15 ,
T_2 V_53 , T_2 V_116 ,
bool (* V_110)( struct V_9 * ) )
{
struct V_29 * V_30 ;
T_2 V_250 ;
T_4 V_251 ;
unsigned int V_100 ;
struct V_46 * V_47 ;
if ( V_116 <= V_53 || V_116 == V_57 ||
( V_53 & V_111 ) != 0 ) {
F_77 ( V_63 , L_32 ,
V_53 , V_116 ) ;
return NULL ;
}
V_30 = F_141 ( sizeof( struct V_29 ) , V_101 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_15 = V_15 ;
V_30 -> V_63 = V_63 ;
V_30 -> V_53 = V_53 ;
V_250 = ( V_252 - sizeof( * V_47 ) ) /
sizeof( struct V_6 * ) ;
if ( ( V_116 - V_53 + 1 ) / ( V_111 + 1 ) > V_250 ) {
V_30 -> V_116 = V_250 * ( V_111 + 1 ) +
V_53 - 1 ;
} else {
V_30 -> V_116 = V_116 ;
V_250 = ( V_30 -> V_116 - V_30 -> V_53 + 1 ) /
( V_111 + 1 ) ;
}
V_30 -> V_36 = F_142 ( 2 , V_253 ) ;
if ( ! V_30 -> V_36 )
goto V_254;
V_30 -> V_105 = V_250 - 1 ;
V_251 = sizeof( * V_47 ) + V_250 * sizeof( struct V_6 * ) ;
V_30 -> V_47 = F_143 ( V_251 , F_144 ( struct V_46 ) ) ;
if ( ! V_30 -> V_47 )
goto V_255;
F_117 (cpu) {
V_47 = F_66 ( V_30 -> V_47 , V_100 ) ;
V_47 -> V_59 = 0 ;
V_47 -> V_56 = V_57 ;
V_47 -> V_58 = V_57 ;
F_68 ( & V_47 -> V_50 ) ;
F_145 ( & V_47 -> V_61 ) ;
}
F_146 ( & V_30 -> V_245 ) ;
if ( ! F_130 ( V_63 , V_30 , V_110 ) ) {
F_135 ( V_30 -> V_47 ) ;
goto V_255;
}
F_138 ( & V_30 -> V_245 , F_133 ) ;
return V_30 ;
V_255:
F_134 ( V_30 -> V_36 ) ;
V_254:
F_136 ( V_30 ) ;
return NULL ;
}
void F_147 ( struct V_62 * V_63 )
{
struct V_108 * V_109 , * V_199 ;
F_148 ( V_42 ) ;
F_115 (ema, next, &lport->ema_list, ema_list)
F_137 ( V_109 ) ;
}
static struct V_108 * F_149 ( T_1 V_11 ,
struct V_62 * V_63 ,
struct V_12 * V_13 )
{
struct V_108 * V_109 ;
T_2 V_52 ;
if ( V_11 & V_117 )
V_52 = F_81 ( V_13 -> V_22 ) ;
else {
V_52 = F_81 ( V_13 -> V_24 ) ;
if ( V_52 == V_57 )
return F_150 ( V_63 -> V_244 . V_256 ,
F_151 ( * V_109 ) , V_244 ) ;
}
F_73 (ema, &lport->ema_list, ema_list) {
if ( ( V_52 >= V_109 -> V_30 -> V_53 ) &&
( V_52 <= V_109 -> V_30 -> V_116 ) )
return V_109 ;
}
return NULL ;
}
void F_152 ( struct V_62 * V_63 , struct V_9 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 ) ;
struct V_108 * V_109 ;
T_1 V_11 ;
if ( ! V_63 || V_63 -> V_39 == V_257 ) {
F_77 ( V_63 , L_33
L_34 ) ;
F_38 ( V_10 ) ;
return;
}
V_11 = F_39 ( V_13 -> V_21 ) ;
V_109 = F_149 ( V_11 , V_63 , V_13 ) ;
if ( ! V_109 ) {
F_77 ( V_63 , L_35
L_36 ,
V_11 ,
( V_11 & V_117 ) ?
F_81 ( V_13 -> V_22 ) :
F_81 ( V_13 -> V_24 ) ) ;
F_38 ( V_10 ) ;
return;
}
switch ( F_10 ( V_10 ) ) {
case V_19 :
if ( V_11 & V_18 )
F_153 ( F_14 ( V_10 ) , F_12 ( V_10 ) - F_154 ( V_11 ) ) ;
case V_20 :
if ( V_13 -> V_67 == V_74 )
F_111 ( V_109 -> V_30 , V_10 ) ;
else if ( ( V_11 & ( V_117 | V_125 ) ) ==
V_117 )
F_107 ( V_109 -> V_30 , V_10 ) ;
else if ( V_11 & V_125 )
F_108 ( V_109 -> V_30 , V_10 ) ;
else
F_103 ( V_63 , V_109 -> V_30 , V_10 ) ;
break;
default:
F_77 ( V_63 , L_37 ,
F_10 ( V_10 ) ) ;
F_38 ( V_10 ) ;
}
}
int F_155 ( struct V_62 * V_63 )
{
if ( ! V_63 -> V_72 . V_258 )
V_63 -> V_72 . V_258 = F_116 ;
return 0 ;
}
int F_156 ( void )
{
V_253 = F_157 ( L_38 , sizeof( struct V_6 ) ,
0 , V_259 , NULL ) ;
if ( ! V_253 )
return - V_85 ;
V_54 = F_158 ( F_159 ( V_112 ) ) ;
V_111 = ( 1 << V_54 ) - 1 ;
V_42 = F_160 ( L_39 ) ;
if ( ! V_42 )
goto V_106;
return 0 ;
V_106:
F_161 ( V_253 ) ;
return - V_85 ;
}
void F_162 ( void )
{
F_163 ( V_42 ) ;
F_161 ( V_253 ) ;
}
