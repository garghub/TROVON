static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 . V_5 = F_2 ( & V_2 -> V_6 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_7 . V_4 . V_5 = F_2 ( & V_2 -> V_8 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_3 . V_4 . V_5 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_7 . V_4 . V_5 ) ;
}
static inline T_1 * F_7 ( T_1 * V_9 , unsigned int V_10 )
{
T_1 * V_11 = ( T_1 * ) ( ( ( unsigned long ) ( V_9 + V_10 - 1 ) ) & V_12 ) ;
return F_8 ( V_9 , V_11 ) ;
}
static inline unsigned int F_9 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
T_1 * V_5 ;
V_5 = ( T_1 * ) F_10 ( ( unsigned long ) V_2 -> V_14 , V_2 -> V_15 + 1 ) ;
V_5 = F_7 ( V_5 , V_13 ) ;
F_11 ( V_5 , & V_2 -> V_8 , V_13 , 1 ) ;
return V_13 ;
}
static inline unsigned int F_12 ( struct V_1 * V_2 ,
unsigned int V_16 )
{
if ( V_2 -> V_17 & V_18 ) {
F_3 ( V_2 ) ;
memcpy ( V_2 -> V_7 . V_4 . V_5 , V_2 -> V_19 , V_16 ) ;
F_6 ( V_2 ) ;
} else if ( ! ( V_2 -> V_17 & V_20 ) ) {
if ( V_2 -> V_17 & V_21 )
F_6 ( V_2 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_2 -> V_6 , V_16 ) ;
F_13 ( & V_2 -> V_8 , V_16 ) ;
return V_16 ;
}
int F_14 ( struct V_22 * V_23 ,
struct V_1 * V_2 , int V_24 )
{
unsigned int V_25 = 0 ;
if ( F_15 ( V_24 >= 0 ) ) {
unsigned int V_16 = V_2 -> V_25 - V_24 ;
if ( F_15 ( ! ( V_2 -> V_17 & V_26 ) ) )
V_16 = F_12 ( V_2 , V_16 ) ;
else if ( F_16 ( V_24 ) ) {
V_24 = - V_27 ;
goto V_24;
} else
V_16 = F_9 ( V_2 , V_16 ) ;
V_25 = V_2 -> V_28 - V_16 ;
V_24 = 0 ;
}
F_17 ( & V_2 -> V_6 , 0 , V_25 ) ;
F_17 ( & V_2 -> V_8 , 1 , V_25 ) ;
V_24:
V_2 -> V_28 = V_25 ;
V_2 -> V_25 = V_25 ;
if ( V_25 ) {
F_18 ( V_23 -> V_17 ) ;
return F_19 ( V_23 , V_2 ) ;
}
if ( V_2 -> V_29 != V_23 -> V_30 )
memcpy ( V_23 -> V_30 , V_2 -> V_29 , V_2 -> V_31 ) ;
if ( V_2 -> V_14 != V_2 -> V_19 )
F_20 ( V_2 -> V_14 ) ;
if ( V_2 -> V_19 )
F_21 ( ( unsigned long ) V_2 -> V_19 ) ;
return V_24 ;
}
static inline int F_22 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
unsigned int V_13 ,
unsigned int V_15 )
{
unsigned int V_16 ;
unsigned V_32 = F_10 ( V_13 , V_15 + 1 ) ;
if ( V_2 -> V_14 )
goto V_33;
V_2 -> V_14 = V_2 -> V_19 ;
if ( V_2 -> V_14 )
goto V_33;
V_16 = V_32 * 3 - ( V_15 + 1 ) +
( V_15 & ~ ( F_23 () - 1 ) ) ;
V_2 -> V_14 = F_24 ( V_16 , V_34 ) ;
if ( ! V_2 -> V_14 )
return F_14 ( V_23 , V_2 , - V_35 ) ;
V_33:
V_2 -> V_7 . V_4 . V_5 = ( T_1 * ) F_10 ( ( unsigned long ) V_2 -> V_14 ,
V_15 + 1 ) ;
V_2 -> V_7 . V_4 . V_5 = F_7 ( V_2 -> V_7 . V_4 . V_5 , V_13 ) ;
V_2 -> V_3 . V_4 . V_5 = F_7 ( V_2 -> V_7 . V_4 . V_5 +
V_32 , V_13 ) ;
F_11 ( V_2 -> V_3 . V_4 . V_5 , & V_2 -> V_6 , V_13 , 0 ) ;
V_2 -> V_25 = V_13 ;
V_2 -> V_17 |= V_26 ;
return 0 ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
T_1 * V_36 = V_2 -> V_19 ;
F_1 ( V_2 ) ;
memcpy ( V_36 , V_2 -> V_3 . V_4 . V_5 , V_2 -> V_25 ) ;
F_4 ( V_2 ) ;
V_2 -> V_3 . V_4 . V_5 = V_36 ;
V_2 -> V_7 . V_4 . V_5 = V_36 ;
return 0 ;
}
static inline int F_26 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
unsigned long V_37 ;
V_2 -> V_3 . V_38 . V_19 = F_27 ( & V_2 -> V_6 ) ;
V_2 -> V_3 . V_38 . V_39 = F_28 ( V_2 -> V_6 . V_39 ) ;
V_2 -> V_7 . V_38 . V_19 = F_27 ( & V_2 -> V_8 ) ;
V_2 -> V_7 . V_38 . V_39 = F_28 ( V_2 -> V_8 . V_39 ) ;
if ( V_2 -> V_17 & V_20 )
return 0 ;
V_37 = V_2 -> V_3 . V_38 . V_39 - V_2 -> V_7 . V_38 . V_39 ;
V_37 |= V_2 -> V_3 . V_4 . V_19 - V_2 -> V_7 . V_4 . V_19 ;
F_1 ( V_2 ) ;
V_2 -> V_7 . V_4 . V_5 = V_2 -> V_3 . V_4 . V_5 ;
if ( V_37 ) {
V_2 -> V_17 |= V_21 ;
F_3 ( V_2 ) ;
}
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
unsigned int V_13 ;
unsigned int V_16 ;
int V_24 ;
V_16 = V_2 -> V_28 ;
if ( F_29 ( V_16 < V_2 -> V_40 ) ) {
V_23 -> V_17 |= V_41 ;
return F_14 ( V_23 , V_2 , - V_27 ) ;
}
V_2 -> V_17 &= ~ ( V_26 | V_18 |
V_21 ) ;
if ( ! F_30 ( & V_2 -> V_6 , V_2 -> V_15 ) ||
! F_30 ( & V_2 -> V_8 , V_2 -> V_15 ) ) {
V_2 -> V_17 |= V_18 ;
if ( ! V_2 -> V_19 ) {
V_2 -> V_19 = ( void * ) F_31 ( V_34 ) ;
if ( ! V_2 -> V_19 )
V_16 = 0 ;
}
}
V_13 = F_32 ( V_2 -> V_42 , V_16 ) ;
V_16 = F_33 ( & V_2 -> V_6 , V_16 ) ;
V_16 = F_33 ( & V_2 -> V_8 , V_16 ) ;
if ( F_29 ( V_16 < V_13 ) ) {
V_24 = F_22 ( V_23 , V_2 , V_13 , V_2 -> V_15 ) ;
goto V_43;
}
V_2 -> V_25 = V_16 ;
if ( V_2 -> V_17 & V_18 ) {
V_24 = F_25 ( V_2 ) ;
goto V_43;
}
return F_26 ( V_23 , V_2 ) ;
V_43:
if ( V_2 -> V_17 & V_20 ) {
V_2 -> V_3 . V_38 . V_19 = F_34 ( V_2 -> V_3 . V_4 . V_5 ) ;
V_2 -> V_7 . V_38 . V_19 = F_34 ( V_2 -> V_7 . V_4 . V_5 ) ;
V_2 -> V_3 . V_38 . V_39 &= V_44 - 1 ;
V_2 -> V_7 . V_38 . V_39 &= V_44 - 1 ;
}
return V_24 ;
}
static inline int F_35 ( struct V_1 * V_2 )
{
unsigned V_45 = V_2 -> V_42 ;
unsigned V_46 = F_10 ( V_45 , V_2 -> V_15 + 1 ) ;
unsigned int V_47 = V_46 * 2 +
V_2 -> V_31 + F_8 ( V_46 , V_2 -> V_31 ) -
( V_2 -> V_15 + 1 ) ;
T_1 * V_29 ;
V_47 += V_2 -> V_15 & ~ ( F_23 () - 1 ) ;
V_2 -> V_14 = F_24 ( V_47 , V_34 ) ;
if ( ! V_2 -> V_14 )
return - V_35 ;
V_29 = ( T_1 * ) F_10 ( ( unsigned long ) V_2 -> V_14 , V_2 -> V_15 + 1 ) ;
V_29 = F_7 ( V_29 , V_45 ) + V_46 ;
V_29 = F_7 ( V_29 , V_45 ) + V_46 ;
V_29 = F_7 ( V_29 , V_2 -> V_31 ) ;
V_2 -> V_29 = memcpy ( V_29 , V_2 -> V_29 , V_2 -> V_31 ) ;
return 0 ;
}
int F_36 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
V_2 -> V_17 &= ~ V_20 ;
V_2 -> V_42 = F_37 ( V_23 -> V_48 ) ;
V_2 -> V_40 = V_2 -> V_42 ;
V_2 -> V_31 = F_38 ( V_23 -> V_48 ) ;
V_2 -> V_15 = F_39 ( V_23 -> V_48 ) ;
return F_40 ( V_23 , V_2 ) ;
}
int F_41 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
V_2 -> V_17 |= V_20 ;
V_2 -> V_42 = F_37 ( V_23 -> V_48 ) ;
V_2 -> V_40 = V_2 -> V_42 ;
V_2 -> V_31 = F_38 ( V_23 -> V_48 ) ;
V_2 -> V_15 = F_39 ( V_23 -> V_48 ) ;
return F_40 ( V_23 , V_2 ) ;
}
static int F_40 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
if ( F_42 ( F_43 () ) )
return - V_49 ;
V_2 -> V_25 = V_2 -> V_28 ;
if ( F_29 ( ! V_2 -> V_28 ) )
return 0 ;
V_2 -> V_14 = NULL ;
V_2 -> V_29 = V_23 -> V_30 ;
if ( F_29 ( ( ( unsigned long ) V_2 -> V_29 & V_2 -> V_15 ) ) ) {
int V_24 = F_35 ( V_2 ) ;
if ( V_24 )
return V_24 ;
}
F_44 ( & V_2 -> V_6 , V_2 -> V_6 . V_50 ) ;
F_44 ( & V_2 -> V_8 , V_2 -> V_8 . V_50 ) ;
V_2 -> V_19 = NULL ;
return F_19 ( V_23 , V_2 ) ;
}
int F_45 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
unsigned int V_51 )
{
V_2 -> V_17 &= ~ V_20 ;
V_2 -> V_42 = V_51 ;
V_2 -> V_40 = F_37 ( V_23 -> V_48 ) ;
V_2 -> V_31 = F_38 ( V_23 -> V_48 ) ;
V_2 -> V_15 = F_39 ( V_23 -> V_48 ) ;
return F_40 ( V_23 , V_2 ) ;
}
int F_46 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_52 * V_48 ,
unsigned int V_51 )
{
V_2 -> V_17 &= ~ V_20 ;
V_2 -> V_42 = V_51 ;
V_2 -> V_40 = F_47 ( V_48 ) ;
V_2 -> V_31 = F_48 ( V_48 ) ;
V_2 -> V_15 = F_49 ( V_48 ) ;
return F_40 ( V_23 , V_2 ) ;
}
static int F_50 ( struct V_53 * V_48 , const T_1 * V_54 ,
unsigned int V_55 )
{
struct V_56 * V_57 = & V_48 -> V_58 -> V_59 ;
unsigned long V_15 = F_51 ( V_48 ) ;
int V_60 ;
T_1 * V_14 , * V_61 ;
unsigned long V_62 ;
V_62 = V_55 + V_15 ;
V_14 = F_24 ( V_62 , V_34 ) ;
if ( ! V_14 )
return - V_35 ;
V_61 = ( T_1 * ) F_10 ( ( unsigned long ) V_14 , V_15 + 1 ) ;
memcpy ( V_61 , V_54 , V_55 ) ;
V_60 = V_57 -> V_63 ( V_48 , V_61 , V_55 ) ;
memset ( V_61 , 0 , V_55 ) ;
F_20 ( V_14 ) ;
return V_60 ;
}
static int V_63 ( struct V_53 * V_48 , const T_1 * V_54 , unsigned int V_55 )
{
struct V_56 * V_57 = & V_48 -> V_58 -> V_59 ;
unsigned long V_15 = F_51 ( V_48 ) ;
if ( V_55 < V_57 -> V_64 || V_55 > V_57 -> V_65 ) {
V_48 -> V_66 |= V_67 ;
return - V_27 ;
}
if ( ( unsigned long ) V_54 & V_15 )
return F_50 ( V_48 , V_54 , V_55 ) ;
return V_57 -> V_63 ( V_48 , V_54 , V_55 ) ;
}
static int F_52 ( struct V_68 * V_48 , const T_1 * V_54 ,
unsigned int V_55 )
{
return V_63 ( F_53 ( V_48 ) , V_54 , V_55 ) ;
}
static int F_54 ( struct V_69 * V_70 )
{
struct V_53 * V_48 = V_70 -> V_71 . V_48 ;
struct V_56 * V_72 = & V_48 -> V_58 -> V_59 ;
struct V_22 V_23 = {
. V_48 = F_55 ( V_48 ) ,
. V_30 = V_70 -> V_30 ,
. V_17 = V_70 -> V_71 . V_17 ,
} ;
return V_72 -> V_73 ( & V_23 , V_70 -> V_7 , V_70 -> V_3 , V_70 -> V_25 ) ;
}
static int F_56 ( struct V_69 * V_70 )
{
struct V_53 * V_48 = V_70 -> V_71 . V_48 ;
struct V_56 * V_72 = & V_48 -> V_58 -> V_59 ;
struct V_22 V_23 = {
. V_48 = F_55 ( V_48 ) ,
. V_30 = V_70 -> V_30 ,
. V_17 = V_70 -> V_71 . V_17 ,
} ;
return V_72 -> V_74 ( & V_23 , V_70 -> V_7 , V_70 -> V_3 , V_70 -> V_25 ) ;
}
static unsigned int F_57 ( struct V_75 * V_72 , T_2 type ,
T_2 V_76 )
{
struct V_56 * V_57 = & V_72 -> V_59 ;
unsigned int V_10 = V_72 -> V_77 ;
if ( ( V_76 & V_78 ) == V_78 &&
V_57 -> V_31 ) {
V_10 = F_10 ( V_10 , ( unsigned long ) V_72 -> V_79 + 1 ) ;
V_10 += V_57 -> V_31 ;
}
return V_10 ;
}
static int F_58 ( struct V_53 * V_48 )
{
struct V_80 * V_81 = & V_48 -> V_82 ;
struct V_56 * V_72 = & V_48 -> V_58 -> V_59 ;
V_81 -> V_63 = F_52 ;
V_81 -> V_73 = F_54 ;
V_81 -> V_74 = F_56 ;
if ( ! V_72 -> V_31 ) {
V_81 -> V_83 = V_84 ;
V_81 -> V_85 = V_86 ;
}
V_81 -> V_71 = F_59 ( V_48 ) ;
V_81 -> V_31 = V_72 -> V_31 ;
return 0 ;
}
static int F_60 ( struct V_53 * V_48 )
{
struct V_87 * V_81 = & V_48 -> V_88 ;
struct V_56 * V_72 = & V_48 -> V_58 -> V_59 ;
unsigned long V_89 = F_51 ( V_48 ) + 1 ;
unsigned long V_5 ;
V_81 -> V_63 = V_63 ;
V_81 -> V_73 = V_72 -> V_73 ;
V_81 -> V_74 = V_72 -> V_74 ;
V_5 = ( unsigned long ) F_61 ( V_48 ) ;
V_5 = F_10 ( V_5 , V_89 ) ;
V_5 += F_10 ( V_48 -> V_58 -> V_77 , V_89 ) ;
V_81 -> V_29 = ( void * ) V_5 ;
return 0 ;
}
static int F_62 ( struct V_53 * V_48 , T_2 type , T_2 V_76 )
{
struct V_56 * V_72 = & V_48 -> V_58 -> V_59 ;
if ( V_72 -> V_31 > V_44 / 8 )
return - V_27 ;
if ( ( V_76 & V_78 ) == V_78 )
return F_60 ( V_48 ) ;
else
return F_58 ( V_48 ) ;
}
static int F_63 ( struct V_90 * V_91 , struct V_75 * V_72 )
{
struct V_92 V_93 ;
strncpy ( V_93 . type , L_1 , sizeof( V_93 . type ) ) ;
strncpy ( V_93 . V_94 , V_72 -> V_59 . V_94 ? : L_2 ,
sizeof( V_93 . V_94 ) ) ;
V_93 . V_51 = V_72 -> V_95 ;
V_93 . V_64 = V_72 -> V_59 . V_64 ;
V_93 . V_65 = V_72 -> V_59 . V_65 ;
V_93 . V_31 = V_72 -> V_59 . V_31 ;
if ( F_64 ( V_91 , V_96 ,
sizeof( struct V_92 ) , & V_93 ) )
goto V_97;
return 0 ;
V_97:
return - V_98 ;
}
static int F_63 ( struct V_90 * V_91 , struct V_75 * V_72 )
{
return - V_99 ;
}
static void F_65 ( struct V_100 * V_101 , struct V_75 * V_72 )
{
F_66 ( V_101 , L_3 ) ;
F_66 ( V_101 , L_4 , V_72 -> V_95 ) ;
F_66 ( V_101 , L_5 , V_72 -> V_59 . V_64 ) ;
F_66 ( V_101 , L_6 , V_72 -> V_59 . V_65 ) ;
F_66 ( V_101 , L_7 , V_72 -> V_59 . V_31 ) ;
F_66 ( V_101 , L_8 , V_72 -> V_59 . V_94 ? :
L_2 ) ;
}
static int F_67 ( struct V_102 * V_103 ,
const char * V_104 , T_2 type , T_2 V_76 )
{
struct V_75 * V_72 ;
int V_24 ;
type = F_68 ( type ) ;
V_76 = F_69 ( V_76 ) | V_105 ;
V_72 = F_70 ( V_104 , type , V_76 ) ;
if ( F_71 ( V_72 ) )
return F_72 ( V_72 ) ;
V_24 = F_73 ( & V_103 -> V_71 , V_72 , V_103 -> V_71 . V_106 , V_76 ) ;
F_74 ( V_72 ) ;
return V_24 ;
}
struct V_107 * F_75 ( struct V_108 * V_109 ,
struct V_110 * * V_111 , T_2 type ,
T_2 V_76 )
{
struct {
int (* V_63)( struct V_68 * V_48 , const T_1 * V_54 ,
unsigned int V_55 );
int (* V_73)( struct V_69 * V_70 );
int (* V_74)( struct V_69 * V_70 );
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_31 ;
const char * V_94 ;
} V_112 ;
const char * V_104 ;
struct V_102 * V_103 ;
struct V_113 * V_114 ;
struct V_107 * V_106 ;
struct V_75 * V_72 ;
int V_24 ;
V_114 = F_76 ( V_111 ) ;
if ( F_71 ( V_114 ) )
return F_77 ( V_114 ) ;
if ( ( V_114 -> type ^ ( V_115 | V_105 ) ) &
V_114 -> V_76 )
return F_78 ( - V_27 ) ;
V_104 = F_79 ( V_111 [ 1 ] ) ;
if ( F_71 ( V_104 ) )
return F_77 ( V_104 ) ;
V_106 = F_80 ( sizeof( * V_106 ) + sizeof( * V_103 ) , V_116 ) ;
if ( ! V_106 )
return F_78 ( - V_35 ) ;
V_103 = F_81 ( V_106 ) ;
V_76 |= F_82 ( V_114 -> type , V_114 -> V_76 ) ;
F_83 ( V_103 , V_106 ) ;
V_24 = F_67 ( V_103 , V_104 , type , V_76 ) ;
if ( V_24 )
goto V_117;
V_72 = F_84 ( V_103 ) ;
if ( ( V_72 -> V_118 & V_78 ) ==
V_119 ) {
V_112 . V_31 = V_72 -> V_59 . V_31 ;
V_112 . V_64 = V_72 -> V_59 . V_64 ;
V_112 . V_65 = V_72 -> V_59 . V_65 ;
V_112 . V_63 = F_52 ;
V_112 . V_73 = F_54 ;
V_112 . V_74 = F_56 ;
V_112 . V_94 = V_72 -> V_59 . V_94 ;
} else {
V_112 . V_31 = V_72 -> V_120 . V_31 ;
V_112 . V_64 = V_72 -> V_120 . V_64 ;
V_112 . V_65 = V_72 -> V_120 . V_65 ;
V_112 . V_63 = V_72 -> V_120 . V_63 ;
V_112 . V_73 = V_72 -> V_120 . V_73 ;
V_112 . V_74 = V_72 -> V_120 . V_74 ;
V_112 . V_94 = V_72 -> V_120 . V_94 ;
}
V_24 = - V_27 ;
if ( ! V_112 . V_31 )
goto V_121;
if ( V_114 -> V_76 & V_105 ) {
if ( ! V_112 . V_94 )
V_112 . V_94 = F_85 ( V_72 ) ;
V_24 = - V_122 ;
if ( strcmp ( V_109 -> V_104 , V_112 . V_94 ) )
goto V_121;
memcpy ( V_106 -> V_72 . V_123 , V_72 -> V_123 , V_124 ) ;
memcpy ( V_106 -> V_72 . V_125 , V_72 -> V_125 ,
V_124 ) ;
} else {
V_24 = - V_126 ;
if ( snprintf ( V_106 -> V_72 . V_123 , V_124 ,
L_9 , V_109 -> V_104 , V_72 -> V_123 ) >=
V_124 )
goto V_121;
if ( snprintf ( V_106 -> V_72 . V_125 , V_124 ,
L_9 , V_109 -> V_104 , V_72 -> V_125 ) >=
V_124 )
goto V_121;
}
V_106 -> V_72 . V_118 = V_115 | V_105 ;
V_106 -> V_72 . V_118 |= V_72 -> V_118 & V_127 ;
V_106 -> V_72 . V_128 = V_72 -> V_128 ;
V_106 -> V_72 . V_95 = V_72 -> V_95 ;
V_106 -> V_72 . V_79 = V_72 -> V_79 ;
V_106 -> V_72 . V_129 = & V_130 ;
V_106 -> V_72 . V_120 . V_31 = V_112 . V_31 ;
V_106 -> V_72 . V_120 . V_64 = V_112 . V_64 ;
V_106 -> V_72 . V_120 . V_65 = V_112 . V_65 ;
V_106 -> V_72 . V_120 . V_94 = V_112 . V_94 ;
V_106 -> V_72 . V_120 . V_63 = V_112 . V_63 ;
V_106 -> V_72 . V_120 . V_73 = V_112 . V_73 ;
V_106 -> V_72 . V_120 . V_74 = V_112 . V_74 ;
V_8:
return V_106 ;
V_121:
F_86 ( V_103 ) ;
V_117:
F_20 ( V_106 ) ;
V_106 = F_78 ( V_24 ) ;
goto V_8;
}
void F_87 ( struct V_107 * V_106 )
{
F_86 ( F_81 ( V_106 ) ) ;
F_20 ( V_106 ) ;
}
int F_88 ( struct V_53 * V_48 )
{
struct V_107 * V_106 = ( void * ) V_48 -> V_58 ;
struct V_68 * V_57 ;
V_57 = F_89 ( F_81 ( V_106 ) ) ;
if ( F_71 ( V_57 ) )
return F_72 ( V_57 ) ;
V_48 -> V_82 . V_71 = V_57 ;
V_48 -> V_82 . V_131 += F_90 ( V_57 ) ;
return 0 ;
}
void F_91 ( struct V_53 * V_48 )
{
F_92 ( V_48 -> V_82 . V_71 ) ;
}
