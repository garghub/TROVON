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
static inline unsigned int F_9 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
unsigned int V_15 )
{
T_1 * V_5 ;
unsigned int V_16 = F_10 ( V_14 ) ;
V_5 = ( T_1 * ) F_11 ( ( unsigned long ) V_2 -> V_17 , V_16 + 1 ) ;
V_5 = F_7 ( V_5 , V_15 ) ;
F_12 ( V_5 , & V_2 -> V_8 , V_15 , 1 ) ;
return V_15 ;
}
static inline unsigned int F_13 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
if ( V_2 -> V_19 & V_20 ) {
F_3 ( V_2 ) ;
memcpy ( V_2 -> V_7 . V_4 . V_5 , V_2 -> V_21 , V_18 ) ;
F_6 ( V_2 ) ;
} else if ( ! ( V_2 -> V_19 & V_22 ) ) {
if ( V_2 -> V_19 & V_23 )
F_6 ( V_2 ) ;
F_4 ( V_2 ) ;
}
F_14 ( & V_2 -> V_6 , V_18 ) ;
F_14 ( & V_2 -> V_8 , V_18 ) ;
return V_18 ;
}
int F_15 ( struct V_24 * V_25 ,
struct V_1 * V_2 , int V_26 )
{
struct V_13 * V_14 = V_25 -> V_14 ;
unsigned int V_27 = 0 ;
if ( F_16 ( V_26 >= 0 ) ) {
unsigned int V_18 = V_2 -> V_27 - V_26 ;
if ( F_16 ( ! ( V_2 -> V_19 & V_28 ) ) )
V_18 = F_13 ( V_2 , V_18 ) ;
else if ( F_17 ( V_26 ) ) {
V_26 = - V_29 ;
goto V_26;
} else
V_18 = F_9 ( V_14 , V_2 , V_18 ) ;
V_27 = V_2 -> V_30 - V_18 ;
V_26 = 0 ;
}
F_18 ( & V_2 -> V_6 , 0 , V_27 ) ;
F_18 ( & V_2 -> V_8 , 1 , V_27 ) ;
V_26:
V_2 -> V_30 = V_27 ;
V_2 -> V_27 = V_27 ;
if ( V_27 ) {
F_19 ( V_25 -> V_19 ) ;
return F_20 ( V_25 , V_2 ) ;
}
if ( V_2 -> V_31 != V_25 -> V_32 )
memcpy ( V_25 -> V_32 , V_2 -> V_31 , F_21 ( V_14 ) ) ;
if ( V_2 -> V_17 != V_2 -> V_21 )
F_22 ( V_2 -> V_17 ) ;
if ( V_2 -> V_21 )
F_23 ( ( unsigned long ) V_2 -> V_21 ) ;
return V_26 ;
}
static inline int F_24 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
unsigned int V_15 ,
unsigned int V_16 )
{
unsigned int V_18 ;
unsigned V_33 = F_11 ( V_15 , V_16 + 1 ) ;
if ( V_2 -> V_17 )
goto V_34;
V_2 -> V_17 = V_2 -> V_21 ;
if ( V_2 -> V_17 )
goto V_34;
V_18 = V_33 * 3 - ( V_16 + 1 ) +
( V_16 & ~ ( F_25 () - 1 ) ) ;
V_2 -> V_17 = F_26 ( V_18 , V_35 ) ;
if ( ! V_2 -> V_17 )
return F_15 ( V_25 , V_2 , - V_36 ) ;
V_34:
V_2 -> V_7 . V_4 . V_5 = ( T_1 * ) F_11 ( ( unsigned long ) V_2 -> V_17 ,
V_16 + 1 ) ;
V_2 -> V_7 . V_4 . V_5 = F_7 ( V_2 -> V_7 . V_4 . V_5 , V_15 ) ;
V_2 -> V_3 . V_4 . V_5 = F_7 ( V_2 -> V_7 . V_4 . V_5 +
V_33 , V_15 ) ;
F_12 ( V_2 -> V_3 . V_4 . V_5 , & V_2 -> V_6 , V_15 , 0 ) ;
V_2 -> V_27 = V_15 ;
V_2 -> V_19 |= V_28 ;
return 0 ;
}
static inline int F_27 ( struct V_1 * V_2 )
{
T_1 * V_37 = V_2 -> V_21 ;
F_1 ( V_2 ) ;
memcpy ( V_37 , V_2 -> V_3 . V_4 . V_5 , V_2 -> V_27 ) ;
F_4 ( V_2 ) ;
V_2 -> V_3 . V_4 . V_5 = V_37 ;
V_2 -> V_7 . V_4 . V_5 = V_37 ;
return 0 ;
}
static inline int F_28 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
unsigned long V_38 ;
V_2 -> V_3 . V_39 . V_21 = F_29 ( & V_2 -> V_6 ) ;
V_2 -> V_3 . V_39 . V_40 = F_30 ( V_2 -> V_6 . V_40 ) ;
V_2 -> V_7 . V_39 . V_21 = F_29 ( & V_2 -> V_8 ) ;
V_2 -> V_7 . V_39 . V_40 = F_30 ( V_2 -> V_8 . V_40 ) ;
if ( V_2 -> V_19 & V_22 )
return 0 ;
V_38 = V_2 -> V_3 . V_39 . V_40 - V_2 -> V_7 . V_39 . V_40 ;
V_38 |= V_2 -> V_3 . V_4 . V_21 - V_2 -> V_7 . V_4 . V_21 ;
F_1 ( V_2 ) ;
V_2 -> V_7 . V_4 . V_5 = V_2 -> V_3 . V_4 . V_5 ;
if ( V_38 ) {
V_2 -> V_19 |= V_23 ;
F_3 ( V_2 ) ;
}
return 0 ;
}
static int F_20 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_25 -> V_14 ;
unsigned int V_16 = F_10 ( V_14 ) ;
unsigned int V_15 ;
unsigned int V_18 ;
int V_26 ;
V_18 = V_2 -> V_30 ;
if ( F_31 ( V_18 < F_32 ( V_14 ) ) ) {
V_25 -> V_19 |= V_41 ;
return F_15 ( V_25 , V_2 , - V_29 ) ;
}
V_2 -> V_19 &= ~ ( V_28 | V_20 |
V_23 ) ;
if ( ! F_33 ( & V_2 -> V_6 , V_16 ) ||
! F_33 ( & V_2 -> V_8 , V_16 ) ) {
V_2 -> V_19 |= V_20 ;
if ( ! V_2 -> V_21 ) {
V_2 -> V_21 = ( void * ) F_34 ( V_35 ) ;
if ( ! V_2 -> V_21 )
V_18 = 0 ;
}
}
V_15 = F_35 ( V_2 -> V_42 , V_18 ) ;
V_18 = F_36 ( & V_2 -> V_6 , V_18 ) ;
V_18 = F_36 ( & V_2 -> V_8 , V_18 ) ;
if ( F_31 ( V_18 < V_15 ) ) {
V_26 = F_24 ( V_25 , V_2 , V_15 , V_16 ) ;
goto V_43;
}
V_2 -> V_27 = V_18 ;
if ( V_2 -> V_19 & V_20 ) {
V_26 = F_27 ( V_2 ) ;
goto V_43;
}
return F_28 ( V_25 , V_2 ) ;
V_43:
if ( V_2 -> V_19 & V_22 ) {
V_2 -> V_3 . V_39 . V_21 = F_37 ( V_2 -> V_3 . V_4 . V_5 ) ;
V_2 -> V_7 . V_39 . V_21 = F_37 ( V_2 -> V_7 . V_4 . V_5 ) ;
V_2 -> V_3 . V_39 . V_40 &= V_44 - 1 ;
V_2 -> V_7 . V_39 . V_40 &= V_44 - 1 ;
}
return V_26 ;
}
static inline int F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_16 )
{
unsigned V_45 = V_2 -> V_42 ;
unsigned int V_46 = F_21 ( V_14 ) ;
unsigned V_47 = F_11 ( V_45 , V_16 + 1 ) ;
unsigned int V_48 = V_47 * 2 + V_46 + F_8 ( V_47 , V_46 ) -
( V_16 + 1 ) ;
T_1 * V_31 ;
V_48 += V_16 & ~ ( F_25 () - 1 ) ;
V_2 -> V_17 = F_26 ( V_48 , V_35 ) ;
if ( ! V_2 -> V_17 )
return - V_36 ;
V_31 = ( T_1 * ) F_11 ( ( unsigned long ) V_2 -> V_17 , V_16 + 1 ) ;
V_31 = F_7 ( V_31 , V_45 ) + V_47 ;
V_31 = F_7 ( V_31 , V_45 ) + V_47 ;
V_31 = F_7 ( V_31 , V_46 ) ;
V_2 -> V_31 = memcpy ( V_31 , V_2 -> V_31 , V_46 ) ;
return 0 ;
}
int F_39 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
V_2 -> V_19 &= ~ V_22 ;
V_2 -> V_42 = F_32 ( V_25 -> V_14 ) ;
return F_40 ( V_25 , V_2 ) ;
}
int F_41 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
V_2 -> V_19 |= V_22 ;
V_2 -> V_42 = F_32 ( V_25 -> V_14 ) ;
return F_40 ( V_25 , V_2 ) ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 = V_25 -> V_14 ;
unsigned int V_16 = F_10 ( V_14 ) ;
if ( F_42 ( F_43 () ) )
return - V_49 ;
V_2 -> V_27 = V_2 -> V_30 ;
if ( F_31 ( ! V_2 -> V_30 ) )
return 0 ;
V_2 -> V_17 = NULL ;
V_2 -> V_31 = V_25 -> V_32 ;
if ( F_31 ( ( ( unsigned long ) V_2 -> V_31 & V_16 ) ) ) {
int V_26 = F_38 ( V_2 , V_14 , V_16 ) ;
if ( V_26 )
return V_26 ;
}
F_44 ( & V_2 -> V_6 , V_2 -> V_6 . V_50 ) ;
F_44 ( & V_2 -> V_8 , V_2 -> V_8 . V_50 ) ;
V_2 -> V_21 = NULL ;
return F_20 ( V_25 , V_2 ) ;
}
int F_45 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
unsigned int V_42 )
{
V_2 -> V_19 &= ~ V_22 ;
V_2 -> V_42 = V_42 ;
return F_40 ( V_25 , V_2 ) ;
}
static int F_46 ( struct V_51 * V_14 , const T_1 * V_52 ,
unsigned int V_53 )
{
struct V_54 * V_55 = & V_14 -> V_56 -> V_57 ;
unsigned long V_16 = F_47 ( V_14 ) ;
int V_58 ;
T_1 * V_17 , * V_59 ;
unsigned long V_60 ;
V_60 = V_53 + V_16 ;
V_17 = F_26 ( V_60 , V_35 ) ;
if ( ! V_17 )
return - V_36 ;
V_59 = ( T_1 * ) F_11 ( ( unsigned long ) V_17 , V_16 + 1 ) ;
memcpy ( V_59 , V_52 , V_53 ) ;
V_58 = V_55 -> V_61 ( V_14 , V_59 , V_53 ) ;
memset ( V_59 , 0 , V_53 ) ;
F_22 ( V_17 ) ;
return V_58 ;
}
static int V_61 ( struct V_51 * V_14 , const T_1 * V_52 , unsigned int V_53 )
{
struct V_54 * V_55 = & V_14 -> V_56 -> V_57 ;
unsigned long V_16 = F_47 ( V_14 ) ;
if ( V_53 < V_55 -> V_62 || V_53 > V_55 -> V_63 ) {
V_14 -> V_64 |= V_65 ;
return - V_29 ;
}
if ( ( unsigned long ) V_52 & V_16 )
return F_46 ( V_14 , V_52 , V_53 ) ;
return V_55 -> V_61 ( V_14 , V_52 , V_53 ) ;
}
static int F_48 ( struct V_66 * V_14 , const T_1 * V_52 ,
unsigned int V_53 )
{
return V_61 ( F_49 ( V_14 ) , V_52 , V_53 ) ;
}
static int F_50 ( struct V_67 * V_68 )
{
struct V_51 * V_14 = V_68 -> V_69 . V_14 ;
struct V_54 * V_70 = & V_14 -> V_56 -> V_57 ;
struct V_24 V_25 = {
. V_14 = F_51 ( V_14 ) ,
. V_32 = V_68 -> V_32 ,
. V_19 = V_68 -> V_69 . V_19 ,
} ;
return V_70 -> V_71 ( & V_25 , V_68 -> V_7 , V_68 -> V_3 , V_68 -> V_27 ) ;
}
static int F_52 ( struct V_67 * V_68 )
{
struct V_51 * V_14 = V_68 -> V_69 . V_14 ;
struct V_54 * V_70 = & V_14 -> V_56 -> V_57 ;
struct V_24 V_25 = {
. V_14 = F_51 ( V_14 ) ,
. V_32 = V_68 -> V_32 ,
. V_19 = V_68 -> V_69 . V_19 ,
} ;
return V_70 -> V_72 ( & V_25 , V_68 -> V_7 , V_68 -> V_3 , V_68 -> V_27 ) ;
}
static unsigned int F_53 ( struct V_73 * V_70 , T_2 type ,
T_2 V_74 )
{
struct V_54 * V_55 = & V_70 -> V_57 ;
unsigned int V_10 = V_70 -> V_75 ;
if ( ( V_74 & V_76 ) == V_76 &&
V_55 -> V_46 ) {
V_10 = F_11 ( V_10 , ( unsigned long ) V_70 -> V_77 + 1 ) ;
V_10 += V_55 -> V_46 ;
}
return V_10 ;
}
static int F_54 ( struct V_51 * V_14 )
{
struct V_78 * V_79 = & V_14 -> V_80 ;
struct V_54 * V_70 = & V_14 -> V_56 -> V_57 ;
V_79 -> V_61 = F_48 ;
V_79 -> V_71 = F_50 ;
V_79 -> V_72 = F_52 ;
if ( ! V_70 -> V_46 ) {
V_79 -> V_81 = V_82 ;
V_79 -> V_83 = V_84 ;
}
V_79 -> V_69 = F_55 ( V_14 ) ;
V_79 -> V_46 = V_70 -> V_46 ;
return 0 ;
}
static int F_56 ( struct V_51 * V_14 )
{
struct V_85 * V_79 = & V_14 -> V_86 ;
struct V_54 * V_70 = & V_14 -> V_56 -> V_57 ;
unsigned long V_87 = F_47 ( V_14 ) + 1 ;
unsigned long V_5 ;
V_79 -> V_61 = V_61 ;
V_79 -> V_71 = V_70 -> V_71 ;
V_79 -> V_72 = V_70 -> V_72 ;
V_5 = ( unsigned long ) F_57 ( V_14 ) ;
V_5 = F_11 ( V_5 , V_87 ) ;
V_5 += F_11 ( V_14 -> V_56 -> V_75 , V_87 ) ;
V_79 -> V_31 = ( void * ) V_5 ;
return 0 ;
}
static int F_58 ( struct V_51 * V_14 , T_2 type , T_2 V_74 )
{
struct V_54 * V_70 = & V_14 -> V_56 -> V_57 ;
if ( V_70 -> V_46 > V_44 / 8 )
return - V_29 ;
if ( ( V_74 & V_76 ) == V_76 )
return F_56 ( V_14 ) ;
else
return F_54 ( V_14 ) ;
}
static int F_59 ( struct V_88 * V_89 , struct V_73 * V_70 )
{
struct V_90 V_91 ;
snprintf ( V_91 . type , V_92 , L_1 , L_2 ) ;
snprintf ( V_91 . V_93 , V_92 , L_1 ,
V_70 -> V_57 . V_93 ? : L_3 ) ;
V_91 . V_42 = V_70 -> V_94 ;
V_91 . V_62 = V_70 -> V_57 . V_62 ;
V_91 . V_63 = V_70 -> V_57 . V_63 ;
V_91 . V_46 = V_70 -> V_57 . V_46 ;
if ( F_60 ( V_89 , V_95 ,
sizeof( struct V_90 ) , & V_91 ) )
goto V_96;
return 0 ;
V_96:
return - V_97 ;
}
static int F_59 ( struct V_88 * V_89 , struct V_73 * V_70 )
{
return - V_98 ;
}
static void F_61 ( struct V_99 * V_100 , struct V_73 * V_70 )
{
F_62 ( V_100 , L_4 ) ;
F_62 ( V_100 , L_5 , V_70 -> V_94 ) ;
F_62 ( V_100 , L_6 , V_70 -> V_57 . V_62 ) ;
F_62 ( V_100 , L_7 , V_70 -> V_57 . V_63 ) ;
F_62 ( V_100 , L_8 , V_70 -> V_57 . V_46 ) ;
F_62 ( V_100 , L_9 , V_70 -> V_57 . V_93 ? :
L_3 ) ;
}
static int F_63 ( struct V_101 * V_102 ,
const char * V_103 , T_2 type , T_2 V_74 )
{
struct V_73 * V_70 ;
int V_26 ;
type = F_64 ( type ) ;
V_74 = F_65 ( V_74 ) | V_104 ;
V_70 = F_66 ( V_103 , type , V_74 ) ;
if ( F_67 ( V_70 ) )
return F_68 ( V_70 ) ;
V_26 = F_69 ( & V_102 -> V_69 , V_70 , V_102 -> V_69 . V_105 , V_74 ) ;
F_70 ( V_70 ) ;
return V_26 ;
}
struct V_106 * F_71 ( struct V_107 * V_108 ,
struct V_109 * * V_110 , T_2 type ,
T_2 V_74 )
{
struct {
int (* V_61)( struct V_66 * V_14 , const T_1 * V_52 ,
unsigned int V_53 );
int (* V_71)( struct V_67 * V_68 );
int (* V_72)( struct V_67 * V_68 );
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_46 ;
const char * V_93 ;
} V_111 ;
const char * V_103 ;
struct V_101 * V_102 ;
struct V_112 * V_113 ;
struct V_106 * V_105 ;
struct V_73 * V_70 ;
int V_26 ;
V_113 = F_72 ( V_110 ) ;
V_26 = F_68 ( V_113 ) ;
if ( F_67 ( V_113 ) )
return F_73 ( V_26 ) ;
if ( ( V_113 -> type ^ ( V_114 | V_104 ) ) &
V_113 -> V_74 )
return F_73 ( - V_29 ) ;
V_103 = F_74 ( V_110 [ 1 ] ) ;
V_26 = F_68 ( V_103 ) ;
if ( F_67 ( V_103 ) )
return F_73 ( V_26 ) ;
V_105 = F_75 ( sizeof( * V_105 ) + sizeof( * V_102 ) , V_115 ) ;
if ( ! V_105 )
return F_73 ( - V_36 ) ;
V_102 = F_76 ( V_105 ) ;
V_74 |= F_77 ( V_113 -> type , V_113 -> V_74 ) ;
F_78 ( V_102 , V_105 ) ;
V_26 = F_63 ( V_102 , V_103 , type , V_74 ) ;
if ( V_26 )
goto V_116;
V_70 = F_79 ( V_102 ) ;
if ( ( V_70 -> V_117 & V_76 ) ==
V_118 ) {
V_111 . V_46 = V_70 -> V_57 . V_46 ;
V_111 . V_62 = V_70 -> V_57 . V_62 ;
V_111 . V_63 = V_70 -> V_57 . V_63 ;
V_111 . V_61 = F_48 ;
V_111 . V_71 = F_50 ;
V_111 . V_72 = F_52 ;
V_111 . V_93 = V_70 -> V_57 . V_93 ;
} else {
V_111 . V_46 = V_70 -> V_119 . V_46 ;
V_111 . V_62 = V_70 -> V_119 . V_62 ;
V_111 . V_63 = V_70 -> V_119 . V_63 ;
V_111 . V_61 = V_70 -> V_119 . V_61 ;
V_111 . V_71 = V_70 -> V_119 . V_71 ;
V_111 . V_72 = V_70 -> V_119 . V_72 ;
V_111 . V_93 = V_70 -> V_119 . V_93 ;
}
V_26 = - V_29 ;
if ( ! V_111 . V_46 )
goto V_120;
if ( V_113 -> V_74 & V_104 ) {
if ( ! V_111 . V_93 )
V_111 . V_93 = F_80 ( V_70 ) ;
V_26 = - V_121 ;
if ( strcmp ( V_108 -> V_103 , V_111 . V_93 ) )
goto V_120;
memcpy ( V_105 -> V_70 . V_122 , V_70 -> V_122 , V_92 ) ;
memcpy ( V_105 -> V_70 . V_123 , V_70 -> V_123 ,
V_92 ) ;
} else {
V_26 = - V_124 ;
if ( snprintf ( V_105 -> V_70 . V_122 , V_92 ,
L_10 , V_108 -> V_103 , V_70 -> V_122 ) >=
V_92 )
goto V_120;
if ( snprintf ( V_105 -> V_70 . V_123 , V_92 ,
L_10 , V_108 -> V_103 , V_70 -> V_123 ) >=
V_92 )
goto V_120;
}
V_105 -> V_70 . V_117 = V_114 | V_104 ;
V_105 -> V_70 . V_117 |= V_70 -> V_117 & V_125 ;
V_105 -> V_70 . V_126 = V_70 -> V_126 ;
V_105 -> V_70 . V_94 = V_70 -> V_94 ;
V_105 -> V_70 . V_77 = V_70 -> V_77 ;
V_105 -> V_70 . V_127 = & V_128 ;
V_105 -> V_70 . V_119 . V_46 = V_111 . V_46 ;
V_105 -> V_70 . V_119 . V_62 = V_111 . V_62 ;
V_105 -> V_70 . V_119 . V_63 = V_111 . V_63 ;
V_105 -> V_70 . V_119 . V_93 = V_111 . V_93 ;
V_105 -> V_70 . V_119 . V_61 = V_111 . V_61 ;
V_105 -> V_70 . V_119 . V_71 = V_111 . V_71 ;
V_105 -> V_70 . V_119 . V_72 = V_111 . V_72 ;
V_8:
return V_105 ;
V_120:
F_81 ( V_102 ) ;
V_116:
F_22 ( V_105 ) ;
V_105 = F_73 ( V_26 ) ;
goto V_8;
}
void F_82 ( struct V_106 * V_105 )
{
F_81 ( F_76 ( V_105 ) ) ;
F_22 ( V_105 ) ;
}
int F_83 ( struct V_51 * V_14 )
{
struct V_106 * V_105 = ( void * ) V_14 -> V_56 ;
struct V_66 * V_55 ;
V_55 = F_84 ( F_76 ( V_105 ) ) ;
if ( F_67 ( V_55 ) )
return F_68 ( V_55 ) ;
V_14 -> V_80 . V_69 = V_55 ;
V_14 -> V_80 . V_129 += F_85 ( V_55 ) ;
return 0 ;
}
void F_86 ( struct V_51 * V_14 )
{
F_87 ( V_14 -> V_80 . V_69 ) ;
}
