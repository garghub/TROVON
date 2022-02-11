static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 . V_5 = F_2 ( & V_2 -> V_6 , 0 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_7 . V_4 . V_5 = F_2 ( & V_2 -> V_8 , 1 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_3 . V_4 . V_5 , 0 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_7 . V_4 . V_5 , 1 ) ;
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
static void F_59 ( struct V_88 * V_89 , struct V_73 * V_70 )
{
F_60 ( V_89 , L_1 ) ;
F_60 ( V_89 , L_2 , V_70 -> V_90 ) ;
F_60 ( V_89 , L_3 , V_70 -> V_57 . V_62 ) ;
F_60 ( V_89 , L_4 , V_70 -> V_57 . V_63 ) ;
F_60 ( V_89 , L_5 , V_70 -> V_57 . V_46 ) ;
F_60 ( V_89 , L_6 , V_70 -> V_57 . V_91 ? :
L_7 ) ;
}
static int F_61 ( struct V_92 * V_93 ,
const char * V_94 , T_2 type , T_2 V_74 )
{
struct V_73 * V_70 ;
int V_26 ;
type = F_62 ( type ) ;
V_74 = F_63 ( V_74 ) | V_95 ;
V_70 = F_64 ( V_94 , type , V_74 ) ;
if ( F_65 ( V_70 ) )
return F_66 ( V_70 ) ;
V_26 = F_67 ( & V_93 -> V_69 , V_70 , V_93 -> V_69 . V_96 , V_74 ) ;
F_68 ( V_70 ) ;
return V_26 ;
}
struct V_97 * F_69 ( struct V_98 * V_99 ,
struct V_100 * * V_101 , T_2 type ,
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
const char * V_91 ;
} V_102 ;
const char * V_94 ;
struct V_92 * V_93 ;
struct V_103 * V_104 ;
struct V_97 * V_96 ;
struct V_73 * V_70 ;
int V_26 ;
V_104 = F_70 ( V_101 ) ;
V_26 = F_66 ( V_104 ) ;
if ( F_65 ( V_104 ) )
return F_71 ( V_26 ) ;
if ( ( V_104 -> type ^ ( V_105 | V_95 ) ) &
V_104 -> V_74 )
return F_71 ( - V_29 ) ;
V_94 = F_72 ( V_101 [ 1 ] ) ;
V_26 = F_66 ( V_94 ) ;
if ( F_65 ( V_94 ) )
return F_71 ( V_26 ) ;
V_96 = F_73 ( sizeof( * V_96 ) + sizeof( * V_93 ) , V_106 ) ;
if ( ! V_96 )
return F_71 ( - V_36 ) ;
V_93 = F_74 ( V_96 ) ;
V_74 |= F_75 ( V_104 -> type , V_104 -> V_74 ) ;
F_76 ( V_93 , V_96 ) ;
V_26 = F_61 ( V_93 , V_94 , type , V_74 ) ;
if ( V_26 )
goto V_107;
V_70 = F_77 ( V_93 ) ;
if ( ( V_70 -> V_108 & V_76 ) ==
V_109 ) {
V_102 . V_46 = V_70 -> V_57 . V_46 ;
V_102 . V_62 = V_70 -> V_57 . V_62 ;
V_102 . V_63 = V_70 -> V_57 . V_63 ;
V_102 . V_61 = F_48 ;
V_102 . V_71 = F_50 ;
V_102 . V_72 = F_52 ;
V_102 . V_91 = V_70 -> V_57 . V_91 ;
} else {
V_102 . V_46 = V_70 -> V_110 . V_46 ;
V_102 . V_62 = V_70 -> V_110 . V_62 ;
V_102 . V_63 = V_70 -> V_110 . V_63 ;
V_102 . V_61 = V_70 -> V_110 . V_61 ;
V_102 . V_71 = V_70 -> V_110 . V_71 ;
V_102 . V_72 = V_70 -> V_110 . V_72 ;
V_102 . V_91 = V_70 -> V_110 . V_91 ;
}
V_26 = - V_29 ;
if ( ! V_102 . V_46 )
goto V_111;
if ( V_104 -> V_74 & V_95 ) {
if ( ! V_102 . V_91 )
V_102 . V_91 = F_78 ( V_70 ) ;
V_26 = - V_112 ;
if ( strcmp ( V_99 -> V_94 , V_102 . V_91 ) )
goto V_111;
memcpy ( V_96 -> V_70 . V_113 , V_70 -> V_113 , V_114 ) ;
memcpy ( V_96 -> V_70 . V_115 , V_70 -> V_115 ,
V_114 ) ;
} else {
V_26 = - V_116 ;
if ( snprintf ( V_96 -> V_70 . V_113 , V_114 ,
L_8 , V_99 -> V_94 , V_70 -> V_113 ) >=
V_114 )
goto V_111;
if ( snprintf ( V_96 -> V_70 . V_115 , V_114 ,
L_8 , V_99 -> V_94 , V_70 -> V_115 ) >=
V_114 )
goto V_111;
}
V_96 -> V_70 . V_108 = V_105 | V_95 ;
V_96 -> V_70 . V_108 |= V_70 -> V_108 & V_117 ;
V_96 -> V_70 . V_118 = V_70 -> V_118 ;
V_96 -> V_70 . V_90 = V_70 -> V_90 ;
V_96 -> V_70 . V_77 = V_70 -> V_77 ;
V_96 -> V_70 . V_119 = & V_120 ;
V_96 -> V_70 . V_110 . V_46 = V_102 . V_46 ;
V_96 -> V_70 . V_110 . V_62 = V_102 . V_62 ;
V_96 -> V_70 . V_110 . V_63 = V_102 . V_63 ;
V_96 -> V_70 . V_110 . V_91 = V_102 . V_91 ;
V_96 -> V_70 . V_110 . V_61 = V_102 . V_61 ;
V_96 -> V_70 . V_110 . V_71 = V_102 . V_71 ;
V_96 -> V_70 . V_110 . V_72 = V_102 . V_72 ;
V_8:
return V_96 ;
V_111:
F_79 ( V_93 ) ;
V_107:
F_22 ( V_96 ) ;
V_96 = F_71 ( V_26 ) ;
goto V_8;
}
void F_80 ( struct V_97 * V_96 )
{
F_79 ( F_74 ( V_96 ) ) ;
F_22 ( V_96 ) ;
}
int F_81 ( struct V_51 * V_14 )
{
struct V_97 * V_96 = ( void * ) V_14 -> V_56 ;
struct V_66 * V_55 ;
V_55 = F_82 ( F_74 ( V_96 ) ) ;
if ( F_65 ( V_55 ) )
return F_66 ( V_55 ) ;
V_14 -> V_80 . V_69 = V_55 ;
V_14 -> V_80 . V_121 += F_83 ( V_55 ) ;
return 0 ;
}
void F_84 ( struct V_51 * V_14 )
{
F_85 ( V_14 -> V_80 . V_69 ) ;
}
