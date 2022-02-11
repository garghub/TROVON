static inline void F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( F_2 ( F_3 ( V_2 ) ) )
F_4 ( V_3 ) ;
}
static inline void * F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_3 ( V_2 ) ;
return ( F_2 ( V_4 ) ? F_6 ( V_4 ) : F_7 ( V_4 ) ) +
F_8 ( V_2 -> V_5 ) ;
}
static inline void F_9 ( struct V_6 * V_2 )
{
V_2 -> V_7 . V_8 . V_9 = F_5 ( & V_2 -> V_10 ) ;
}
static inline void F_10 ( struct V_6 * V_2 )
{
V_2 -> V_11 . V_8 . V_9 = F_5 ( & V_2 -> V_12 ) ;
}
static inline void F_11 ( struct V_6 * V_2 )
{
F_1 ( & V_2 -> V_10 , V_2 -> V_7 . V_8 . V_9 ) ;
}
static inline void F_12 ( struct V_6 * V_2 )
{
F_1 ( & V_2 -> V_12 , V_2 -> V_11 . V_8 . V_9 ) ;
}
static inline T_1 F_13 ( struct V_6 * V_2 )
{
return V_2 -> V_13 & V_14 ? V_15 : V_16 ;
}
static inline T_2 * F_14 ( T_2 * V_17 , unsigned int V_18 )
{
T_2 * V_19 = ( T_2 * ) ( ( ( unsigned long ) ( V_17 + V_18 - 1 ) ) & V_20 ) ;
return F_15 ( V_17 , V_19 ) ;
}
static int F_16 ( struct V_6 * V_2 , unsigned int V_21 )
{
T_2 * V_9 ;
V_9 = ( T_2 * ) F_17 ( ( unsigned long ) V_2 -> V_22 , V_2 -> V_23 + 1 ) ;
V_9 = F_14 ( V_9 , V_21 ) ;
F_18 ( V_9 , & V_2 -> V_12 , V_21 ,
( V_2 -> V_13 & V_24 ) ? 2 : 1 ) ;
return 0 ;
}
int F_19 ( struct V_6 * V_2 , int V_25 )
{
unsigned int V_26 = V_2 -> V_27 - V_25 ;
unsigned int V_27 ;
V_27 = V_2 -> V_28 - V_26 ;
if ( F_20 ( V_25 < 0 ) ) {
V_27 = 0 ;
V_26 = 0 ;
} else if ( F_21 ( ! ( V_2 -> V_13 & ( V_24 |
V_29 |
V_30 |
V_31 ) ) ) ) {
V_32:
F_11 ( V_2 ) ;
} else if ( V_2 -> V_13 & V_31 ) {
F_12 ( V_2 ) ;
goto V_32;
} else if ( V_2 -> V_13 & V_30 ) {
F_10 ( V_2 ) ;
memcpy ( V_2 -> V_11 . V_8 . V_9 , V_2 -> V_4 , V_26 ) ;
F_12 ( V_2 ) ;
} else if ( F_20 ( V_2 -> V_13 & V_29 ) ) {
if ( F_22 ( V_25 ) ) {
V_25 = - V_33 ;
V_27 = 0 ;
} else
V_26 = F_16 ( V_2 , V_26 ) ;
}
if ( V_25 > 0 )
V_25 = 0 ;
V_2 -> V_28 = V_27 ;
V_2 -> V_27 = V_27 ;
F_23 ( & V_2 -> V_10 , V_26 ) ;
F_23 ( & V_2 -> V_12 , V_26 ) ;
F_24 ( & V_2 -> V_10 , 0 , V_27 ) ;
F_24 ( & V_2 -> V_12 , 1 , V_27 ) ;
if ( V_27 ) {
F_25 ( V_2 -> V_13 & V_14 ?
V_34 : 0 ) ;
return F_26 ( V_2 ) ;
}
if ( ! ( ( unsigned long ) V_2 -> V_22 | ( unsigned long ) V_2 -> V_4 ) )
goto V_12;
if ( V_2 -> V_13 & V_24 )
goto V_12;
if ( V_2 -> V_35 != V_2 -> V_36 )
memcpy ( V_2 -> V_36 , V_2 -> V_35 , V_2 -> V_37 ) ;
if ( V_2 -> V_22 != V_2 -> V_4 )
F_27 ( V_2 -> V_22 ) ;
if ( V_2 -> V_4 )
F_28 ( ( unsigned long ) V_2 -> V_4 ) ;
V_12:
return V_25 ;
}
void F_29 ( struct V_6 * V_2 , int V_25 )
{
struct V_38 * V_39 , * V_40 ;
F_30 (p, tmp, &walk->buffers, entry) {
T_2 * V_41 ;
if ( V_25 )
goto V_42;
V_41 = V_39 -> V_41 ;
if ( ! V_41 ) {
V_41 = F_31 ( & V_39 -> V_22 [ 0 ] , V_2 -> V_23 + 1 ) ;
V_41 = F_14 ( V_41 , V_2 -> V_43 ) ;
}
F_18 ( V_41 , & V_39 -> V_11 , V_39 -> V_18 , 1 ) ;
if ( F_8 ( V_39 -> V_41 ) + V_39 -> V_18 + V_2 -> V_43 >
V_44 )
F_28 ( ( unsigned long ) V_39 -> V_41 ) ;
V_42:
F_32 ( & V_39 -> V_45 ) ;
F_27 ( V_39 ) ;
}
if ( ! V_25 && V_2 -> V_35 != V_2 -> V_36 )
memcpy ( V_2 -> V_36 , V_2 -> V_35 , V_2 -> V_37 ) ;
if ( V_2 -> V_22 != V_2 -> V_4 )
F_27 ( V_2 -> V_22 ) ;
if ( V_2 -> V_4 )
F_28 ( ( unsigned long ) V_2 -> V_4 ) ;
}
static void F_33 ( struct V_6 * V_2 ,
struct V_38 * V_39 )
{
V_39 -> V_11 = V_2 -> V_12 ;
F_34 ( & V_39 -> V_45 , & V_2 -> V_46 ) ;
}
static int F_35 ( struct V_6 * V_2 , unsigned int V_21 )
{
bool V_47 = V_2 -> V_13 & V_24 ;
unsigned V_23 = V_2 -> V_23 ;
struct V_38 * V_39 ;
unsigned V_48 ;
unsigned V_26 ;
T_2 * V_22 ;
void * V_49 ;
if ( ! V_47 ) {
if ( ! V_2 -> V_22 )
V_2 -> V_22 = V_2 -> V_4 ;
V_22 = V_2 -> V_22 ;
if ( V_22 )
goto V_50;
}
V_48 = F_36 () - 1 ;
V_26 = V_21 ;
if ( V_47 ) {
V_48 &= ( sizeof( * V_39 ) ^ ( sizeof( * V_39 ) - 1 ) ) >> 1 ;
V_26 += sizeof( * V_39 ) ;
}
V_26 += V_23 & ~ V_48 ;
V_26 += ( V_21 - 1 ) & ~ ( V_23 | V_48 ) ;
V_49 = F_37 ( V_26 , F_13 ( V_2 ) ) ;
if ( ! V_49 )
return F_19 ( V_2 , - V_51 ) ;
if ( V_47 ) {
V_39 = V_49 ;
V_39 -> V_18 = V_21 ;
F_33 ( V_2 , V_39 ) ;
V_22 = V_39 -> V_22 ;
} else {
V_2 -> V_22 = V_49 ;
V_22 = V_49 ;
}
V_50:
V_2 -> V_11 . V_8 . V_9 = F_31 ( V_22 , V_23 + 1 ) ;
V_2 -> V_11 . V_8 . V_9 = F_14 ( V_2 -> V_11 . V_8 . V_9 , V_21 ) ;
V_2 -> V_7 . V_8 . V_9 = V_2 -> V_11 . V_8 . V_9 ;
F_18 ( V_2 -> V_7 . V_8 . V_9 , & V_2 -> V_10 , V_21 , 0 ) ;
V_2 -> V_27 = V_21 ;
V_2 -> V_13 |= V_29 ;
return 0 ;
}
static int F_38 ( struct V_6 * V_2 )
{
struct V_38 * V_39 ;
T_2 * V_40 = V_2 -> V_4 ;
F_9 ( V_2 ) ;
memcpy ( V_40 , V_2 -> V_7 . V_8 . V_9 , V_2 -> V_27 ) ;
F_11 ( V_2 ) ;
V_2 -> V_7 . V_8 . V_9 = V_40 ;
V_2 -> V_11 . V_8 . V_9 = V_40 ;
if ( ! ( V_2 -> V_13 & V_24 ) )
return 0 ;
V_39 = F_39 ( sizeof( * V_39 ) , F_13 ( V_2 ) ) ;
if ( ! V_39 )
return - V_51 ;
V_39 -> V_41 = V_2 -> V_4 ;
V_39 -> V_18 = V_2 -> V_27 ;
F_33 ( V_2 , V_39 ) ;
if ( F_8 ( V_2 -> V_4 ) + V_2 -> V_27 + V_2 -> V_43 >
V_44 )
V_2 -> V_4 = NULL ;
else
V_2 -> V_4 += V_2 -> V_27 ;
return 0 ;
}
static int F_40 ( struct V_6 * V_2 )
{
unsigned long V_52 ;
V_2 -> V_7 . V_47 . V_4 = F_3 ( & V_2 -> V_10 ) ;
V_2 -> V_7 . V_47 . V_5 = F_8 ( V_2 -> V_10 . V_5 ) ;
V_2 -> V_11 . V_47 . V_4 = F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_11 . V_47 . V_5 = F_8 ( V_2 -> V_12 . V_5 ) ;
if ( V_2 -> V_13 & V_24 )
return 0 ;
V_52 = V_2 -> V_7 . V_47 . V_5 - V_2 -> V_11 . V_47 . V_5 ;
V_52 |= V_2 -> V_7 . V_8 . V_4 - V_2 -> V_11 . V_8 . V_4 ;
F_9 ( V_2 ) ;
V_2 -> V_11 . V_8 . V_9 = V_2 -> V_7 . V_8 . V_9 ;
if ( V_52 ) {
V_2 -> V_13 |= V_31 ;
F_10 ( V_2 ) ;
}
return 0 ;
}
static int F_26 ( struct V_6 * V_2 )
{
unsigned int V_21 ;
unsigned int V_26 ;
int V_25 ;
V_2 -> V_13 &= ~ ( V_29 | V_30 |
V_31 ) ;
V_26 = V_2 -> V_28 ;
V_21 = F_41 ( V_2 -> V_43 , F_15 ( V_26 , V_2 -> V_53 ) ) ;
V_26 = F_42 ( & V_2 -> V_10 , V_26 ) ;
V_26 = F_42 ( & V_2 -> V_12 , V_26 ) ;
if ( F_20 ( V_26 < V_21 ) ) {
if ( F_20 ( V_2 -> V_28 < V_2 -> V_53 ) )
return F_19 ( V_2 , - V_33 ) ;
V_54:
V_25 = F_35 ( V_2 , V_21 ) ;
goto V_55;
}
if ( F_20 ( ( V_2 -> V_10 . V_5 | V_2 -> V_12 . V_5 ) & V_2 -> V_23 ) ) {
if ( ! V_2 -> V_4 ) {
T_1 V_56 = F_13 ( V_2 ) ;
V_2 -> V_4 = ( void * ) F_43 ( V_56 ) ;
if ( ! V_2 -> V_4 )
goto V_54;
}
V_2 -> V_27 = F_44 ( unsigned , V_26 ,
V_44 - F_8 ( V_2 -> V_4 ) ) ;
V_2 -> V_13 |= V_30 ;
V_25 = F_38 ( V_2 ) ;
goto V_55;
}
V_2 -> V_27 = V_26 ;
return F_40 ( V_2 ) ;
V_55:
if ( ! V_25 && ( V_2 -> V_13 & V_24 ) ) {
V_2 -> V_7 . V_47 . V_4 = F_45 ( V_2 -> V_7 . V_8 . V_9 ) ;
V_2 -> V_11 . V_47 . V_4 = F_45 ( V_2 -> V_11 . V_8 . V_9 ) ;
V_2 -> V_7 . V_47 . V_5 &= V_44 - 1 ;
V_2 -> V_11 . V_47 . V_5 &= V_44 - 1 ;
}
return V_25 ;
}
static int F_46 ( struct V_6 * V_2 )
{
unsigned V_48 = F_36 () - 1 ;
unsigned V_23 = V_2 -> V_23 ;
unsigned V_37 = V_2 -> V_37 ;
unsigned V_57 = V_2 -> V_43 ;
unsigned V_58 ;
unsigned V_59 ;
T_2 * V_35 ;
V_58 = F_17 ( V_57 , V_23 ) ;
V_59 = V_23 & ~ V_48 ;
if ( V_2 -> V_13 & V_24 )
V_59 += V_37 ;
else {
V_59 += V_58 + V_37 ;
V_59 += ( V_57 - 1 ) & ~ ( V_23 | V_48 ) ;
}
V_2 -> V_22 = F_39 ( V_59 , F_13 ( V_2 ) ) ;
if ( ! V_2 -> V_22 )
return - V_51 ;
V_35 = F_31 ( V_2 -> V_22 , V_23 + 1 ) ;
V_35 = F_14 ( V_35 , V_57 ) + V_58 ;
V_2 -> V_35 = memcpy ( V_35 , V_2 -> V_35 , V_2 -> V_37 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_2 )
{
V_2 -> V_27 = 0 ;
if ( F_48 ( F_49 () ) )
return - V_60 ;
if ( F_20 ( ! V_2 -> V_28 ) )
return 0 ;
V_2 -> V_22 = NULL ;
if ( F_20 ( ( ( unsigned long ) V_2 -> V_35 & V_2 -> V_23 ) ) ) {
int V_25 = F_46 ( V_2 ) ;
if ( V_25 )
return V_25 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_27 = V_2 -> V_28 ;
return F_26 ( V_2 ) ;
}
static int F_50 ( struct V_6 * V_2 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_51 ( V_62 ) ;
F_52 ( & V_2 -> V_10 , V_62 -> V_7 ) ;
F_52 ( & V_2 -> V_12 , V_62 -> V_11 ) ;
V_2 -> V_28 = V_62 -> V_65 ;
V_2 -> V_35 = V_62 -> V_35 ;
V_2 -> V_36 = V_62 -> V_35 ;
V_2 -> V_13 &= ~ V_14 ;
V_2 -> V_13 |= V_62 -> V_66 . V_13 & V_34 ?
V_14 : 0 ;
V_2 -> V_53 = F_53 ( V_64 ) ;
V_2 -> V_43 = F_54 ( V_64 ) ;
V_2 -> V_37 = F_55 ( V_64 ) ;
V_2 -> V_23 = F_56 ( V_64 ) ;
return F_47 ( V_2 ) ;
}
int F_57 ( struct V_6 * V_2 ,
struct V_61 * V_62 , bool V_67 )
{
int V_25 ;
V_2 -> V_13 &= ~ V_24 ;
V_25 = F_50 ( V_2 , V_62 ) ;
V_2 -> V_13 &= V_67 ? ~ V_14 : ~ 0 ;
return V_25 ;
}
void F_58 ( struct V_6 * V_2 )
{
V_2 -> V_13 &= ~ V_14 ;
}
int F_59 ( struct V_6 * V_2 ,
struct V_61 * V_62 )
{
V_2 -> V_13 |= V_24 ;
F_60 ( & V_2 -> V_46 ) ;
return F_50 ( V_2 , V_62 ) ;
}
static int F_61 ( struct V_6 * V_2 ,
struct V_68 * V_62 , bool V_67 )
{
struct V_69 * V_64 = F_62 ( V_62 ) ;
int V_25 ;
V_2 -> V_13 &= ~ V_24 ;
F_52 ( & V_2 -> V_10 , V_62 -> V_7 ) ;
F_52 ( & V_2 -> V_12 , V_62 -> V_11 ) ;
F_18 ( NULL , & V_2 -> V_10 , V_62 -> V_70 , 2 ) ;
F_18 ( NULL , & V_2 -> V_12 , V_62 -> V_70 , 2 ) ;
V_2 -> V_35 = V_62 -> V_35 ;
V_2 -> V_36 = V_62 -> V_35 ;
if ( V_62 -> V_66 . V_13 & V_34 )
V_2 -> V_13 |= V_14 ;
else
V_2 -> V_13 &= ~ V_14 ;
V_2 -> V_53 = F_63 ( V_64 ) ;
V_2 -> V_43 = F_64 ( V_64 ) ;
V_2 -> V_37 = F_65 ( V_64 ) ;
V_2 -> V_23 = F_66 ( V_64 ) ;
V_25 = F_47 ( V_2 ) ;
if ( V_67 )
V_2 -> V_13 &= ~ V_14 ;
return V_25 ;
}
int F_67 ( struct V_6 * V_2 , struct V_68 * V_62 ,
bool V_67 )
{
V_2 -> V_28 = V_62 -> V_65 ;
return F_61 ( V_2 , V_62 , V_67 ) ;
}
int F_68 ( struct V_6 * V_2 ,
struct V_68 * V_62 , bool V_67 )
{
V_2 -> V_28 = V_62 -> V_65 ;
return F_61 ( V_2 , V_62 , V_67 ) ;
}
int F_69 ( struct V_6 * V_2 ,
struct V_68 * V_62 , bool V_67 )
{
struct V_69 * V_64 = F_62 ( V_62 ) ;
V_2 -> V_28 = V_62 -> V_65 - F_70 ( V_64 ) ;
return F_61 ( V_2 , V_62 , V_67 ) ;
}
static unsigned int F_71 ( struct V_71 * V_72 )
{
if ( V_72 -> V_73 == & V_74 )
return sizeof( struct V_75 * ) ;
if ( V_72 -> V_73 == & V_76 ||
V_72 -> V_73 == & V_77 )
return sizeof( struct V_78 * ) ;
return F_72 ( V_72 ) ;
}
static int F_73 ( struct V_63 * V_64 ,
const T_2 * V_79 , unsigned int V_80 )
{
struct V_75 * * V_81 = F_74 ( V_64 ) ;
struct V_75 * V_82 = * V_81 ;
int V_25 ;
F_75 ( V_82 , ~ 0 ) ;
F_76 ( V_82 , F_77 ( V_64 ) &
V_83 ) ;
V_25 = F_78 ( V_82 , V_79 , V_80 ) ;
F_79 ( V_64 , F_80 ( V_82 ) &
V_84 ) ;
return V_25 ;
}
static int F_81 ( struct V_61 * V_62 ,
int (* F_82)( struct V_85 * ,
struct V_86 * ,
struct V_86 * ,
unsigned int ) )
{
struct V_63 * V_64 = F_51 ( V_62 ) ;
struct V_75 * * V_81 = F_74 ( V_64 ) ;
struct V_85 V_87 = {
. V_64 = * V_81 ,
. V_88 = V_62 -> V_35 ,
. V_13 = V_62 -> V_66 . V_13 ,
} ;
return F_82 ( & V_87 , V_62 -> V_11 , V_62 -> V_7 , V_62 -> V_65 ) ;
}
static int F_83 ( struct V_61 * V_62 )
{
struct V_63 * V_89 = F_51 ( V_62 ) ;
struct V_90 * V_64 = F_84 ( V_89 ) ;
struct V_91 * V_72 = & V_64 -> V_92 -> V_93 ;
return F_81 ( V_62 , V_72 -> V_94 ) ;
}
static int F_85 ( struct V_61 * V_62 )
{
struct V_63 * V_89 = F_51 ( V_62 ) ;
struct V_90 * V_64 = F_84 ( V_89 ) ;
struct V_91 * V_72 = & V_64 -> V_92 -> V_93 ;
return F_81 ( V_62 , V_72 -> V_95 ) ;
}
static void F_86 ( struct V_90 * V_64 )
{
struct V_75 * * V_81 = F_87 ( V_64 ) ;
F_88 ( * V_81 ) ;
}
static int F_89 ( struct V_90 * V_64 )
{
struct V_71 * V_96 = V_64 -> V_92 ;
struct V_63 * V_89 = F_90 ( V_64 ) ;
struct V_75 * * V_81 = F_87 ( V_64 ) ;
struct V_75 * V_82 ;
struct V_90 * V_97 ;
if ( ! F_91 ( V_96 ) )
return - V_98 ;
V_97 = F_92 ( V_96 , V_99 ,
V_100 ) ;
if ( F_93 ( V_97 ) ) {
F_94 ( V_96 ) ;
return F_95 ( V_97 ) ;
}
V_82 = F_96 ( V_97 ) ;
* V_81 = V_82 ;
V_64 -> exit = F_86 ;
V_89 -> V_101 = F_73 ;
V_89 -> V_94 = F_83 ;
V_89 -> V_95 = F_85 ;
V_89 -> V_37 = F_97 ( V_82 ) ;
V_89 -> V_102 = V_96 -> V_93 . V_103 ;
return 0 ;
}
static int F_98 ( struct V_63 * V_64 ,
const T_2 * V_79 , unsigned int V_80 )
{
struct V_78 * * V_81 = F_74 ( V_64 ) ;
struct V_78 * V_104 = * V_81 ;
int V_25 ;
F_99 ( V_104 , ~ 0 ) ;
F_100 ( V_104 ,
F_77 ( V_64 ) &
V_83 ) ;
V_25 = F_101 ( V_104 , V_79 , V_80 ) ;
F_79 ( V_64 ,
F_102 ( V_104 ) &
V_84 ) ;
return V_25 ;
}
static int F_103 ( struct V_61 * V_62 ,
int (* F_82)( struct V_105 * ) )
{
struct V_63 * V_64 = F_51 ( V_62 ) ;
struct V_78 * * V_81 = F_74 ( V_64 ) ;
struct V_105 * V_106 = F_104 ( V_62 ) ;
F_105 ( V_106 , * V_81 ) ;
F_106 ( V_106 , F_107 ( V_62 ) ,
V_62 -> V_66 . V_107 , V_62 -> V_66 . V_41 ) ;
F_108 ( V_106 , V_62 -> V_7 , V_62 -> V_11 , V_62 -> V_65 ,
V_62 -> V_35 ) ;
return F_82 ( V_106 ) ;
}
static int F_109 ( struct V_61 * V_62 )
{
struct V_63 * V_89 = F_51 ( V_62 ) ;
struct V_90 * V_64 = F_84 ( V_89 ) ;
struct V_108 * V_72 = & V_64 -> V_92 -> V_109 ;
return F_103 ( V_62 , V_72 -> V_94 ) ;
}
static int F_110 ( struct V_61 * V_62 )
{
struct V_63 * V_89 = F_51 ( V_62 ) ;
struct V_90 * V_64 = F_84 ( V_89 ) ;
struct V_108 * V_72 = & V_64 -> V_92 -> V_109 ;
return F_103 ( V_62 , V_72 -> V_95 ) ;
}
static void F_111 ( struct V_90 * V_64 )
{
struct V_78 * * V_81 = F_87 ( V_64 ) ;
F_112 ( * V_81 ) ;
}
static int F_113 ( struct V_90 * V_64 )
{
struct V_71 * V_96 = V_64 -> V_92 ;
struct V_63 * V_89 = F_90 ( V_64 ) ;
struct V_78 * * V_81 = F_87 ( V_64 ) ;
struct V_78 * V_104 ;
struct V_90 * V_110 ;
if ( ! F_91 ( V_96 ) )
return - V_98 ;
V_110 = F_92 ( V_96 , 0 , 0 ) ;
if ( F_93 ( V_110 ) ) {
F_94 ( V_96 ) ;
return F_95 ( V_110 ) ;
}
V_104 = F_114 ( V_110 ) ;
* V_81 = V_104 ;
V_64 -> exit = F_111 ;
V_89 -> V_101 = F_98 ;
V_89 -> V_94 = F_109 ;
V_89 -> V_95 = F_110 ;
V_89 -> V_37 = F_115 ( V_104 ) ;
V_89 -> V_111 = F_116 ( V_104 ) +
sizeof( struct V_105 ) ;
V_89 -> V_102 = V_96 -> V_109 . V_103 ;
return 0 ;
}
static void F_117 ( struct V_90 * V_64 )
{
struct V_63 * V_89 = F_90 ( V_64 ) ;
struct V_112 * V_72 = F_118 ( V_89 ) ;
V_72 -> exit ( V_89 ) ;
}
static int F_119 ( struct V_90 * V_64 )
{
struct V_63 * V_89 = F_90 ( V_64 ) ;
struct V_112 * V_72 = F_118 ( V_89 ) ;
if ( V_64 -> V_92 -> V_73 == & V_74 )
return F_89 ( V_64 ) ;
if ( V_64 -> V_92 -> V_73 == & V_76 ||
V_64 -> V_92 -> V_73 == & V_77 )
return F_113 ( V_64 ) ;
V_89 -> V_101 = V_72 -> V_101 ;
V_89 -> V_94 = V_72 -> V_94 ;
V_89 -> V_95 = V_72 -> V_95 ;
V_89 -> V_37 = V_72 -> V_37 ;
V_89 -> V_102 = V_72 -> V_103 ;
if ( V_72 -> exit )
V_89 -> V_66 . exit = F_117 ;
if ( V_72 -> V_113 )
return V_72 -> V_113 ( V_89 ) ;
return 0 ;
}
static void F_120 ( struct V_114 * V_115 )
{
struct V_116 * V_89 =
F_121 ( V_115 , struct V_116 , V_117 . V_66 ) ;
V_89 -> free ( V_89 ) ;
}
static void F_122 ( struct V_118 * V_119 , struct V_71 * V_72 )
{
struct V_112 * V_89 = F_121 ( V_72 , struct V_112 ,
V_66 ) ;
F_123 ( V_119 , L_1 ) ;
F_123 ( V_119 , L_2 ,
V_72 -> V_120 & V_121 ? L_3 : L_4 ) ;
F_123 ( V_119 , L_5 , V_72 -> V_122 ) ;
F_123 ( V_119 , L_6 , V_89 -> V_123 ) ;
F_123 ( V_119 , L_7 , V_89 -> V_103 ) ;
F_123 ( V_119 , L_8 , V_89 -> V_37 ) ;
F_123 ( V_119 , L_9 , V_89 -> V_124 ) ;
F_123 ( V_119 , L_10 , V_89 -> V_125 ) ;
}
static int F_124 ( struct V_126 * V_127 , struct V_71 * V_72 )
{
struct V_128 V_129 ;
struct V_112 * V_89 = F_121 ( V_72 , struct V_112 ,
V_66 ) ;
strncpy ( V_129 . type , L_11 , sizeof( V_129 . type ) ) ;
strncpy ( V_129 . V_130 , L_12 , sizeof( V_129 . V_130 ) ) ;
V_129 . V_53 = V_72 -> V_122 ;
V_129 . V_123 = V_89 -> V_123 ;
V_129 . V_103 = V_89 -> V_103 ;
V_129 . V_37 = V_89 -> V_37 ;
if ( F_125 ( V_127 , V_131 ,
sizeof( struct V_128 ) , & V_129 ) )
goto V_132;
return 0 ;
V_132:
return - V_133 ;
}
static int F_124 ( struct V_126 * V_127 , struct V_71 * V_72 )
{
return - V_134 ;
}
int F_126 ( struct V_135 * V_136 ,
const char * V_137 , T_3 type , T_3 V_138 )
{
V_136 -> V_66 . V_139 = & V_140 ;
return F_127 ( & V_136 -> V_66 , V_137 , type , V_138 ) ;
}
struct V_63 * F_128 ( const char * V_141 ,
T_3 type , T_3 V_138 )
{
return F_129 ( V_141 , & V_140 , type , V_138 ) ;
}
int F_130 ( const char * V_141 , T_3 type , T_3 V_138 )
{
return F_131 ( V_141 , & V_140 ,
type , V_138 ) ;
}
static int F_132 ( struct V_112 * V_72 )
{
struct V_71 * V_66 = & V_72 -> V_66 ;
if ( V_72 -> V_37 > V_44 / 8 || V_72 -> V_124 > V_44 / 8 ||
V_72 -> V_125 > V_44 / 8 )
return - V_33 ;
if ( ! V_72 -> V_124 )
V_72 -> V_124 = V_66 -> V_122 ;
if ( ! V_72 -> V_125 )
V_72 -> V_125 = V_72 -> V_124 ;
V_66 -> V_73 = & V_140 ;
V_66 -> V_120 &= ~ V_100 ;
V_66 -> V_120 |= V_142 ;
return 0 ;
}
int F_133 ( struct V_112 * V_72 )
{
struct V_71 * V_66 = & V_72 -> V_66 ;
int V_25 ;
V_25 = F_132 ( V_72 ) ;
if ( V_25 )
return V_25 ;
return F_134 ( V_66 ) ;
}
void F_135 ( struct V_112 * V_72 )
{
F_136 ( & V_72 -> V_66 ) ;
}
int F_137 ( struct V_112 * V_143 , int V_144 )
{
int V_145 , V_146 ;
for ( V_145 = 0 ; V_145 < V_144 ; V_145 ++ ) {
V_146 = F_133 ( & V_143 [ V_145 ] ) ;
if ( V_146 )
goto V_25;
}
return 0 ;
V_25:
for ( -- V_145 ; V_145 >= 0 ; -- V_145 )
F_135 ( & V_143 [ V_145 ] ) ;
return V_146 ;
}
void F_138 ( struct V_112 * V_143 , int V_144 )
{
int V_145 ;
for ( V_145 = V_144 - 1 ; V_145 >= 0 ; -- V_145 )
F_135 ( & V_143 [ V_145 ] ) ;
}
int F_139 ( struct V_147 * V_148 ,
struct V_116 * V_115 )
{
int V_25 ;
V_25 = F_132 ( & V_115 -> V_72 ) ;
if ( V_25 )
return V_25 ;
return F_140 ( V_148 , F_141 ( V_115 ) ) ;
}
