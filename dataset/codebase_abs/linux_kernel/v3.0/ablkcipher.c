static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , & V_2 -> V_4 , V_2 -> V_5 , 1 ) ;
}
void F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_8 ;
F_4 (p, tmp, &walk->buffers, entry) {
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_9 ) ;
F_6 ( V_2 ) ;
}
}
static inline void F_7 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
V_2 -> V_4 = V_7 -> V_10 ;
F_8 ( & V_2 -> V_9 , & V_7 -> V_11 ) ;
}
static inline T_1 * F_9 ( T_1 * V_12 , unsigned int V_5 )
{
T_1 * V_13 = ( T_1 * ) ( ( ( unsigned long ) ( V_12 + V_5 - 1 ) ) & V_14 ) ;
return F_10 ( V_12 , V_13 ) ;
}
static inline unsigned int F_11 ( struct V_6 * V_7 ,
unsigned int V_15 )
{
unsigned int V_16 = V_15 ;
for (; ; ) {
unsigned int V_17 = F_12 ( & V_7 -> V_10 ) ;
if ( V_17 > V_16 )
V_17 = V_16 ;
F_13 ( & V_7 -> V_10 , V_16 ) ;
if ( V_16 == V_17 )
break;
V_16 -= V_17 ;
F_14 ( & V_7 -> V_10 , F_15 ( V_7 -> V_10 . V_18 ) ) ;
}
return V_15 ;
}
static inline unsigned int F_16 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
F_13 ( & V_7 -> V_19 , V_16 ) ;
F_13 ( & V_7 -> V_10 , V_16 ) ;
return V_16 ;
}
int F_17 ( struct V_20 * V_21 ,
struct V_6 * V_7 , int V_22 )
{
struct V_23 * V_24 = V_21 -> V_25 . V_24 ;
unsigned int V_26 = 0 ;
if ( F_18 ( V_22 >= 0 ) ) {
unsigned int V_16 = V_7 -> V_26 - V_22 ;
if ( F_18 ( ! ( V_7 -> V_27 & V_28 ) ) )
V_16 = F_16 ( V_7 , V_16 ) ;
else if ( F_19 ( V_22 ) ) {
V_22 = - V_29 ;
goto V_22;
} else
V_16 = F_11 ( V_7 , V_16 ) ;
V_26 = V_7 -> V_30 - V_16 ;
V_22 = 0 ;
}
F_20 ( & V_7 -> V_19 , 0 , V_26 ) ;
F_20 ( & V_7 -> V_10 , 1 , V_26 ) ;
V_22:
V_7 -> V_30 = V_26 ;
V_7 -> V_26 = V_26 ;
if ( V_26 ) {
F_21 ( V_21 -> V_25 . V_27 ) ;
return F_22 ( V_21 , V_7 ) ;
}
if ( V_7 -> V_31 != V_21 -> V_32 )
memcpy ( V_21 -> V_32 , V_7 -> V_31 , V_24 -> V_33 . V_34 ) ;
F_6 ( V_7 -> V_35 ) ;
return V_22 ;
}
static inline int F_23 ( struct V_20 * V_21 ,
struct V_6 * V_7 ,
unsigned int V_15 ,
unsigned int V_36 ,
void * * V_37 , void * * V_38 )
{
unsigned V_39 = F_24 ( V_15 , V_36 + 1 ) ;
struct V_1 * V_2 ;
void * V_40 , * V_4 , * V_25 ;
unsigned int V_16 ;
V_16 = F_24 ( sizeof( struct V_1 ) , V_36 + 1 ) ;
V_16 += ( V_39 * 3 - ( V_36 + 1 ) +
( V_36 & ~ ( F_25 () - 1 ) ) ) ;
V_2 = F_26 ( V_16 , V_41 ) ;
if ( ! V_2 )
return F_17 ( V_21 , V_7 , - V_42 ) ;
V_25 = V_2 + 1 ;
V_4 = ( T_1 * ) F_24 ( ( unsigned long ) V_25 , V_36 + 1 ) ;
V_40 = V_4 = F_9 ( V_4 , V_15 ) ;
V_2 -> V_5 = V_15 ;
V_2 -> V_3 = V_4 ;
F_2 ( V_40 , & V_7 -> V_19 , V_15 , 0 ) ;
F_7 ( V_7 , V_2 ) ;
V_7 -> V_26 = V_15 ;
V_7 -> V_27 |= V_28 ;
* V_37 = V_40 ;
* V_38 = V_4 ;
return 0 ;
}
static inline int F_27 ( struct V_6 * V_7 ,
struct V_23 * V_24 ,
unsigned int V_36 )
{
unsigned V_43 = V_7 -> V_44 ;
unsigned int V_34 = V_24 -> V_33 . V_34 ;
unsigned V_45 = F_24 ( V_43 , V_36 + 1 ) ;
unsigned int V_46 = V_45 * 2 + V_34 + F_10 ( V_45 , V_34 ) -
( V_36 + 1 ) ;
T_1 * V_31 ;
V_46 += V_36 & ~ ( F_25 () - 1 ) ;
V_7 -> V_35 = F_26 ( V_46 , V_41 ) ;
if ( ! V_7 -> V_35 )
return - V_42 ;
V_31 = ( T_1 * ) F_24 ( ( unsigned long ) V_7 -> V_35 , V_36 + 1 ) ;
V_31 = F_9 ( V_31 , V_43 ) + V_45 ;
V_31 = F_9 ( V_31 , V_43 ) + V_45 ;
V_31 = F_9 ( V_31 , V_34 ) ;
V_7 -> V_31 = memcpy ( V_31 , V_7 -> V_31 , V_34 ) ;
return 0 ;
}
static inline int F_28 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_40 . V_47 = F_29 ( & V_7 -> V_19 ) ;
V_7 -> V_40 . V_48 = F_30 ( V_7 -> V_19 . V_48 ) ;
V_7 -> V_4 . V_47 = F_29 ( & V_7 -> V_10 ) ;
V_7 -> V_4 . V_48 = F_30 ( V_7 -> V_10 . V_48 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
struct V_23 * V_24 = V_21 -> V_25 . V_24 ;
unsigned int V_36 , V_15 , V_16 ;
void * V_40 , * V_4 ;
int V_22 ;
V_36 = F_31 ( V_24 ) ;
V_16 = V_7 -> V_30 ;
if ( F_32 ( V_16 < F_33 ( V_24 ) ) ) {
V_21 -> V_25 . V_27 |= V_49 ;
return F_17 ( V_21 , V_7 , - V_29 ) ;
}
V_7 -> V_27 &= ~ V_28 ;
V_40 = V_4 = NULL ;
V_15 = F_34 ( V_7 -> V_44 , V_16 ) ;
V_16 = F_35 ( & V_7 -> V_19 , V_16 ) ;
V_16 = F_35 ( & V_7 -> V_10 , V_16 ) ;
if ( V_16 < V_15 ||
! F_36 ( & V_7 -> V_19 , V_36 ) ||
! F_36 ( & V_7 -> V_10 , V_36 ) ) {
V_22 = F_23 ( V_21 , V_7 , V_15 , V_36 ,
& V_40 , & V_4 ) ;
goto V_50;
}
V_7 -> V_26 = V_16 ;
return F_28 ( V_21 , V_7 ) ;
V_50:
if ( V_22 >= 0 ) {
V_7 -> V_40 . V_47 = F_37 ( V_40 ) ;
V_7 -> V_4 . V_47 = F_37 ( V_4 ) ;
V_7 -> V_40 . V_48 = ( ( unsigned long ) V_40 & ( V_51 - 1 ) ) ;
V_7 -> V_4 . V_48 = ( ( unsigned long ) V_4 & ( V_51 - 1 ) ) ;
}
return V_22 ;
}
static int F_38 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
struct V_23 * V_24 = V_21 -> V_25 . V_24 ;
unsigned int V_36 ;
V_36 = F_31 ( V_24 ) ;
if ( F_39 ( F_40 () ) )
return - V_52 ;
V_7 -> V_26 = V_7 -> V_30 ;
if ( F_32 ( ! V_7 -> V_30 ) )
return 0 ;
V_7 -> V_35 = NULL ;
V_7 -> V_31 = V_21 -> V_32 ;
if ( F_32 ( ( ( unsigned long ) V_7 -> V_31 & V_36 ) ) ) {
int V_22 = F_27 ( V_7 , V_24 , V_36 ) ;
if ( V_22 )
return V_22 ;
}
F_14 ( & V_7 -> V_19 , V_7 -> V_19 . V_18 ) ;
F_14 ( & V_7 -> V_10 , V_7 -> V_10 . V_18 ) ;
return F_22 ( V_21 , V_7 ) ;
}
int F_41 ( struct V_20 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_44 = F_33 ( V_21 -> V_25 . V_24 ) ;
return F_38 ( V_21 , V_7 ) ;
}
static int F_42 ( struct V_53 * V_24 , const T_1 * V_54 ,
unsigned int V_55 )
{
struct V_56 * V_57 = F_43 ( V_24 ) ;
unsigned long V_36 = F_44 ( V_24 ) ;
int V_58 ;
T_1 * V_59 , * V_60 ;
unsigned long V_61 ;
V_61 = V_55 + V_36 ;
V_59 = F_26 ( V_61 , V_41 ) ;
if ( ! V_59 )
return - V_42 ;
V_60 = ( T_1 * ) F_24 ( ( unsigned long ) V_59 , V_36 + 1 ) ;
memcpy ( V_60 , V_54 , V_55 ) ;
V_58 = V_57 -> V_62 ( V_24 , V_60 , V_55 ) ;
memset ( V_60 , 0 , V_55 ) ;
F_6 ( V_59 ) ;
return V_58 ;
}
static int V_62 ( struct V_53 * V_24 , const T_1 * V_54 ,
unsigned int V_55 )
{
struct V_56 * V_57 = F_43 ( V_24 ) ;
unsigned long V_36 = F_44 ( V_24 ) ;
if ( V_55 < V_57 -> V_63 || V_55 > V_57 -> V_64 ) {
F_45 ( V_24 , V_65 ) ;
return - V_29 ;
}
if ( ( unsigned long ) V_54 & V_36 )
return F_42 ( V_24 , V_54 , V_55 ) ;
return V_57 -> V_62 ( V_24 , V_54 , V_55 ) ;
}
static unsigned int F_46 ( struct V_66 * V_67 , T_2 type ,
T_2 V_68 )
{
return V_67 -> V_69 ;
}
int F_47 ( struct V_70 * V_21 )
{
return F_48 ( & V_21 -> V_71 ) ;
}
int F_49 ( struct V_70 * V_21 )
{
return F_50 ( & V_21 -> V_71 ) ;
}
static int F_51 ( struct V_23 * V_24 , T_2 type ,
T_2 V_68 )
{
struct V_56 * V_67 = & V_24 -> V_72 -> V_73 ;
struct V_74 * V_75 = & V_24 -> V_33 ;
if ( V_67 -> V_34 > V_51 / 8 )
return - V_29 ;
V_75 -> V_62 = V_62 ;
V_75 -> V_76 = V_67 -> V_76 ;
V_75 -> V_77 = V_67 -> V_77 ;
if ( ! V_67 -> V_34 ) {
V_75 -> V_78 = F_47 ;
V_75 -> V_79 = F_49 ;
}
V_75 -> V_25 = F_52 ( V_24 ) ;
V_75 -> V_34 = V_67 -> V_34 ;
return 0 ;
}
static void F_53 ( struct V_80 * V_81 , struct V_66 * V_67 )
{
struct V_56 * V_82 = & V_67 -> V_73 ;
F_54 ( V_81 , L_1 ) ;
F_54 ( V_81 , L_2 , V_67 -> V_83 & V_84 ?
L_3 : L_4 ) ;
F_54 ( V_81 , L_5 , V_67 -> V_85 ) ;
F_54 ( V_81 , L_6 , V_82 -> V_63 ) ;
F_54 ( V_81 , L_7 , V_82 -> V_64 ) ;
F_54 ( V_81 , L_8 , V_82 -> V_34 ) ;
F_54 ( V_81 , L_9 , V_82 -> V_86 ? : L_10 ) ;
}
static int F_55 ( struct V_70 * V_21 )
{
return - V_87 ;
}
static int F_56 ( struct V_23 * V_24 , T_2 type ,
T_2 V_68 )
{
struct V_56 * V_67 = & V_24 -> V_72 -> V_73 ;
struct V_74 * V_75 = & V_24 -> V_33 ;
if ( V_67 -> V_34 > V_51 / 8 )
return - V_29 ;
V_75 -> V_62 = V_24 -> V_72 -> V_83 & V_88 ?
V_67 -> V_62 : V_62 ;
V_75 -> V_76 = V_67 -> V_76 ;
V_75 -> V_77 = V_67 -> V_77 ;
V_75 -> V_78 = V_67 -> V_78 ;
V_75 -> V_79 = V_67 -> V_79 ? : F_55 ;
V_75 -> V_25 = F_52 ( V_24 ) ;
V_75 -> V_34 = V_67 -> V_34 ;
return 0 ;
}
static void F_57 ( struct V_80 * V_81 , struct V_66 * V_67 )
{
struct V_56 * V_82 = & V_67 -> V_73 ;
F_54 ( V_81 , L_11 ) ;
F_54 ( V_81 , L_2 , V_67 -> V_83 & V_84 ?
L_3 : L_4 ) ;
F_54 ( V_81 , L_5 , V_67 -> V_85 ) ;
F_54 ( V_81 , L_6 , V_82 -> V_63 ) ;
F_54 ( V_81 , L_7 , V_82 -> V_64 ) ;
F_54 ( V_81 , L_8 , V_82 -> V_34 ) ;
F_54 ( V_81 , L_9 , V_82 -> V_86 ? : L_12 ) ;
}
const char * F_58 ( const struct V_66 * V_67 )
{
if ( ( ( V_67 -> V_83 & V_89 ) ==
V_90 ? V_67 -> V_91 . V_34 :
V_67 -> V_73 . V_34 ) !=
V_67 -> V_85 )
return L_13 ;
return V_67 -> V_83 & V_84 ?
L_14 : V_92 ;
}
static int F_59 ( struct V_66 * V_67 , T_2 type , T_2 V_68 )
{
struct V_93 * V_94 [ 3 ] ;
struct {
struct V_93 V_95 ;
struct V_96 V_3 ;
} V_97 ;
struct {
struct V_93 V_95 ;
struct V_98 V_3 ;
} V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_66 * V_104 ;
const char * V_86 ;
int V_22 ;
V_104 = F_60 ( V_67 -> V_105 ,
( type & ~ V_89 ) |
V_106 ,
V_68 | V_89 ) ;
V_22 = F_61 ( V_104 ) ;
if ( F_62 ( V_104 ) )
goto V_10;
V_22 = - V_107 ;
if ( ! F_63 ( V_104 ) )
goto V_108;
V_97 . V_95 . V_109 = sizeof( V_97 ) ;
V_97 . V_95 . V_110 = V_111 ;
V_97 . V_3 . type = type | V_88 ;
V_97 . V_3 . V_68 = V_68 | V_88 ;
V_94 [ 0 ] = & V_97 . V_95 ;
V_99 . V_95 . V_109 = sizeof( V_99 ) ;
V_99 . V_95 . V_110 = V_112 ;
memcpy ( V_99 . V_3 . V_113 , V_67 -> V_105 , V_114 ) ;
V_94 [ 1 ] = & V_99 . V_95 ;
V_94 [ 2 ] = NULL ;
if ( ( V_67 -> V_83 & V_89 ) ==
V_90 )
V_86 = V_67 -> V_91 . V_86 ;
else
V_86 = V_67 -> V_73 . V_86 ;
if ( ! V_86 )
V_86 = F_58 ( V_67 ) ;
V_101 = F_64 ( V_86 ) ;
V_22 = - V_115 ;
if ( ! V_101 )
goto V_116;
V_103 = V_101 -> V_117 ( V_94 ) ;
V_22 = F_61 ( V_103 ) ;
if ( F_62 ( V_103 ) )
goto V_118;
if ( ( V_22 = F_65 ( V_101 , V_103 ) ) ) {
V_101 -> free ( V_103 ) ;
goto V_118;
}
V_22 = - V_107 ;
V_118:
F_66 ( V_101 ) ;
V_116:
F_67 ( V_104 ) ;
V_108:
F_68 ( V_104 ) ;
V_10:
F_68 ( V_67 ) ;
return V_22 ;
}
static struct V_66 * F_69 ( const char * V_113 , T_2 type ,
T_2 V_68 )
{
struct V_66 * V_67 ;
V_67 = F_70 ( V_113 , type , V_68 ) ;
if ( F_62 ( V_67 ) )
return V_67 ;
if ( ( V_67 -> V_83 & V_89 ) ==
V_106 )
return V_67 ;
if ( ! ( ( V_67 -> V_83 & V_89 ) ==
V_90 ? V_67 -> V_91 . V_34 :
V_67 -> V_73 . V_34 ) )
return V_67 ;
F_68 ( V_67 ) ;
V_67 = F_70 ( V_113 , type | V_119 ,
V_68 & ~ V_119 ) ;
if ( F_62 ( V_67 ) )
return V_67 ;
if ( ( V_67 -> V_83 & V_89 ) ==
V_106 ) {
if ( ( V_67 -> V_83 ^ type ^ ~ V_68 ) & V_119 ) {
F_68 ( V_67 ) ;
V_67 = F_71 ( - V_115 ) ;
}
return V_67 ;
}
F_72 ( ! ( ( V_67 -> V_83 & V_89 ) ==
V_90 ? V_67 -> V_91 . V_34 :
V_67 -> V_73 . V_34 ) ) ;
return F_71 ( F_59 ( V_67 , type , V_68 ) ) ;
}
int F_73 ( struct V_120 * V_121 , const char * V_113 ,
T_2 type , T_2 V_68 )
{
struct V_66 * V_67 ;
int V_22 ;
type = F_74 ( type ) ;
V_68 = F_75 ( V_68 ) ;
V_67 = F_69 ( V_113 , type , V_68 ) ;
if ( F_62 ( V_67 ) )
return F_61 ( V_67 ) ;
V_22 = F_76 ( & V_121 -> V_25 , V_67 , V_121 -> V_25 . V_103 , V_68 ) ;
F_68 ( V_67 ) ;
return V_22 ;
}
struct V_53 * F_77 ( const char * V_122 ,
T_2 type , T_2 V_68 )
{
struct V_23 * V_24 ;
int V_22 ;
type = F_74 ( type ) ;
V_68 = F_75 ( V_68 ) ;
for (; ; ) {
struct V_66 * V_67 ;
V_67 = F_69 ( V_122 , type , V_68 ) ;
if ( F_62 ( V_67 ) ) {
V_22 = F_61 ( V_67 ) ;
goto V_22;
}
V_24 = F_78 ( V_67 , type , V_68 ) ;
if ( ! F_62 ( V_24 ) )
return F_52 ( V_24 ) ;
F_68 ( V_67 ) ;
V_22 = F_61 ( V_24 ) ;
V_22:
if ( V_22 != - V_107 )
break;
if ( F_79 ( V_123 ) ) {
V_22 = - V_124 ;
break;
}
}
return F_71 ( V_22 ) ;
}
static int T_3 F_80 ( void )
{
V_92 = F_81 () > 1 ?
L_14 : L_13 ;
return 0 ;
}
static void F_82 ( void )
{
}
