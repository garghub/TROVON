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
static int F_53 ( struct V_80 * V_81 , struct V_66 * V_67 )
{
struct V_82 V_83 ;
strncpy ( V_83 . type , L_1 , sizeof( V_83 . type ) ) ;
strncpy ( V_83 . V_84 , V_67 -> V_73 . V_84 ? : L_2 ,
sizeof( V_83 . V_84 ) ) ;
V_83 . V_44 = V_67 -> V_85 ;
V_83 . V_63 = V_67 -> V_73 . V_63 ;
V_83 . V_64 = V_67 -> V_73 . V_64 ;
V_83 . V_34 = V_67 -> V_73 . V_34 ;
if ( F_54 ( V_81 , V_86 ,
sizeof( struct V_82 ) , & V_83 ) )
goto V_87;
return 0 ;
V_87:
return - V_88 ;
}
static int F_53 ( struct V_80 * V_81 , struct V_66 * V_67 )
{
return - V_89 ;
}
static void F_55 ( struct V_90 * V_91 , struct V_66 * V_67 )
{
struct V_56 * V_92 = & V_67 -> V_73 ;
F_56 ( V_91 , L_3 ) ;
F_56 ( V_91 , L_4 , V_67 -> V_93 & V_94 ?
L_5 : L_6 ) ;
F_56 ( V_91 , L_7 , V_67 -> V_85 ) ;
F_56 ( V_91 , L_8 , V_92 -> V_63 ) ;
F_56 ( V_91 , L_9 , V_92 -> V_64 ) ;
F_56 ( V_91 , L_10 , V_92 -> V_34 ) ;
F_56 ( V_91 , L_11 , V_92 -> V_84 ? : L_2 ) ;
}
static int F_57 ( struct V_70 * V_21 )
{
return - V_89 ;
}
static int F_58 ( struct V_23 * V_24 , T_2 type ,
T_2 V_68 )
{
struct V_56 * V_67 = & V_24 -> V_72 -> V_73 ;
struct V_74 * V_75 = & V_24 -> V_33 ;
if ( V_67 -> V_34 > V_51 / 8 )
return - V_29 ;
V_75 -> V_62 = V_24 -> V_72 -> V_93 & V_95 ?
V_67 -> V_62 : V_62 ;
V_75 -> V_76 = V_67 -> V_76 ;
V_75 -> V_77 = V_67 -> V_77 ;
V_75 -> V_78 = V_67 -> V_78 ;
V_75 -> V_79 = V_67 -> V_79 ? : F_57 ;
V_75 -> V_25 = F_52 ( V_24 ) ;
V_75 -> V_34 = V_67 -> V_34 ;
return 0 ;
}
static int F_59 ( struct V_80 * V_81 , struct V_66 * V_67 )
{
struct V_82 V_83 ;
strncpy ( V_83 . type , L_12 , sizeof( V_83 . type ) ) ;
strncpy ( V_83 . V_84 , V_67 -> V_73 . V_84 ? : L_13 ,
sizeof( V_83 . V_84 ) ) ;
V_83 . V_44 = V_67 -> V_85 ;
V_83 . V_63 = V_67 -> V_73 . V_63 ;
V_83 . V_64 = V_67 -> V_73 . V_64 ;
V_83 . V_34 = V_67 -> V_73 . V_34 ;
if ( F_54 ( V_81 , V_86 ,
sizeof( struct V_82 ) , & V_83 ) )
goto V_87;
return 0 ;
V_87:
return - V_88 ;
}
static int F_59 ( struct V_80 * V_81 , struct V_66 * V_67 )
{
return - V_89 ;
}
static void F_60 ( struct V_90 * V_91 , struct V_66 * V_67 )
{
struct V_56 * V_92 = & V_67 -> V_73 ;
F_56 ( V_91 , L_14 ) ;
F_56 ( V_91 , L_4 , V_67 -> V_93 & V_94 ?
L_5 : L_6 ) ;
F_56 ( V_91 , L_7 , V_67 -> V_85 ) ;
F_56 ( V_91 , L_8 , V_92 -> V_63 ) ;
F_56 ( V_91 , L_9 , V_92 -> V_64 ) ;
F_56 ( V_91 , L_10 , V_92 -> V_34 ) ;
F_56 ( V_91 , L_11 , V_92 -> V_84 ? : L_13 ) ;
}
const char * F_61 ( const struct V_66 * V_67 )
{
if ( ( ( V_67 -> V_93 & V_96 ) ==
V_97 ? V_67 -> V_98 . V_34 :
V_67 -> V_73 . V_34 ) !=
V_67 -> V_85 )
return L_15 ;
return L_16 ;
}
static int F_62 ( struct V_66 * V_67 , T_2 type , T_2 V_68 )
{
struct V_99 * V_100 [ 3 ] ;
struct {
struct V_99 V_101 ;
struct V_102 V_3 ;
} V_103 ;
struct {
struct V_99 V_101 ;
struct V_104 V_3 ;
} V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_66 * V_110 ;
const char * V_84 ;
int V_22 ;
V_110 = F_63 ( V_67 -> V_111 ,
( type & ~ V_96 ) |
V_112 ,
V_68 | V_96 ) ;
V_22 = F_64 ( V_110 ) ;
if ( F_65 ( V_110 ) )
goto V_10;
V_22 = - V_113 ;
if ( ! F_66 ( V_110 ) )
goto V_114;
V_103 . V_101 . V_115 = sizeof( V_103 ) ;
V_103 . V_101 . V_116 = V_117 ;
V_103 . V_3 . type = type | V_95 ;
V_103 . V_3 . V_68 = V_68 | V_95 ;
V_100 [ 0 ] = & V_103 . V_101 ;
V_105 . V_101 . V_115 = sizeof( V_105 ) ;
V_105 . V_101 . V_116 = V_118 ;
memcpy ( V_105 . V_3 . V_119 , V_67 -> V_111 , V_120 ) ;
V_100 [ 1 ] = & V_105 . V_101 ;
V_100 [ 2 ] = NULL ;
if ( ( V_67 -> V_93 & V_96 ) ==
V_97 )
V_84 = V_67 -> V_98 . V_84 ;
else
V_84 = V_67 -> V_73 . V_84 ;
if ( ! V_84 )
V_84 = F_61 ( V_67 ) ;
V_107 = F_67 ( V_84 ) ;
V_22 = - V_121 ;
if ( ! V_107 )
goto V_122;
V_109 = V_107 -> V_123 ( V_100 ) ;
V_22 = F_64 ( V_109 ) ;
if ( F_65 ( V_109 ) )
goto V_124;
if ( ( V_22 = F_68 ( V_107 , V_109 ) ) ) {
V_107 -> free ( V_109 ) ;
goto V_124;
}
V_22 = - V_113 ;
V_124:
F_69 ( V_107 ) ;
V_122:
F_70 ( V_110 ) ;
V_114:
F_71 ( V_110 ) ;
V_10:
F_71 ( V_67 ) ;
return V_22 ;
}
struct V_66 * F_72 ( const char * V_119 , T_2 type , T_2 V_68 )
{
struct V_66 * V_67 ;
V_67 = F_73 ( V_119 , type , V_68 ) ;
if ( F_65 ( V_67 ) )
return V_67 ;
if ( ( V_67 -> V_93 & V_96 ) ==
V_112 )
return V_67 ;
if ( ! ( ( V_67 -> V_93 & V_96 ) ==
V_97 ? V_67 -> V_98 . V_34 :
V_67 -> V_73 . V_34 ) )
return V_67 ;
F_71 ( V_67 ) ;
V_67 = F_73 ( V_119 , type | V_125 ,
V_68 & ~ V_125 ) ;
if ( F_65 ( V_67 ) )
return V_67 ;
if ( ( V_67 -> V_93 & V_96 ) ==
V_112 ) {
if ( ( V_67 -> V_93 ^ type ^ ~ V_68 ) & V_125 ) {
F_71 ( V_67 ) ;
V_67 = F_74 ( - V_121 ) ;
}
return V_67 ;
}
F_75 ( ! ( ( V_67 -> V_93 & V_96 ) ==
V_97 ? V_67 -> V_98 . V_34 :
V_67 -> V_73 . V_34 ) ) ;
return F_74 ( F_62 ( V_67 , type , V_68 ) ) ;
}
int F_76 ( struct V_126 * V_127 , const char * V_119 ,
T_2 type , T_2 V_68 )
{
struct V_66 * V_67 ;
int V_22 ;
type = F_77 ( type ) ;
V_68 = F_78 ( V_68 ) ;
V_67 = F_72 ( V_119 , type , V_68 ) ;
if ( F_65 ( V_67 ) )
return F_64 ( V_67 ) ;
V_22 = F_79 ( & V_127 -> V_25 , V_67 , V_127 -> V_25 . V_109 , V_68 ) ;
F_71 ( V_67 ) ;
return V_22 ;
}
struct V_53 * F_80 ( const char * V_128 ,
T_2 type , T_2 V_68 )
{
struct V_23 * V_24 ;
int V_22 ;
type = F_77 ( type ) ;
V_68 = F_78 ( V_68 ) ;
for (; ; ) {
struct V_66 * V_67 ;
V_67 = F_72 ( V_128 , type , V_68 ) ;
if ( F_65 ( V_67 ) ) {
V_22 = F_64 ( V_67 ) ;
goto V_22;
}
V_24 = F_81 ( V_67 , type , V_68 ) ;
if ( ! F_65 ( V_24 ) )
return F_52 ( V_24 ) ;
F_71 ( V_67 ) ;
V_22 = F_64 ( V_24 ) ;
V_22:
if ( V_22 != - V_113 )
break;
if ( F_82 ( V_129 ) ) {
V_22 = - V_130 ;
break;
}
}
return F_74 ( V_22 ) ;
}
