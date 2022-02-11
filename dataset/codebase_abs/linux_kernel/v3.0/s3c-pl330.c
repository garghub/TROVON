static struct V_1 * F_1 ( const enum V_2 V_3 )
{
struct V_1 * V_4 ;
F_2 (ch, &chan_list, node)
if ( V_4 -> V_3 == V_3 )
return V_4 ;
return NULL ;
}
static void F_3 ( const enum V_2 V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 )
return;
V_4 = F_4 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return;
V_4 -> V_3 = V_3 ;
V_4 -> V_6 = NULL ;
F_5 ( & V_4 -> V_7 , & V_8 ) ;
}
static bool F_6 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return false ;
return V_4 -> V_6 ? false : true ;
}
static unsigned F_7 ( struct V_9 * V_6 , enum V_2 V_10 )
{
enum V_2 * V_3 = V_6 -> V_11 ;
int V_12 ;
if ( V_10 == V_13 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ )
if ( V_3 [ V_12 ] == V_10 )
return V_12 + 1 ;
return 0 ;
}
static inline bool F_8 ( struct V_9 * V_6 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
return ( V_6 -> V_17 < V_16 -> V_18 . V_19 ) ? false : true ;
}
static unsigned F_9 ( struct V_9 * V_6 )
{
enum V_2 * V_3 = V_6 -> V_11 ;
struct V_9 * V_20 ;
struct V_1 * V_4 ;
unsigned V_21 , V_22 = 0 ;
enum V_2 V_23 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
V_23 = V_3 [ V_12 ] ;
V_4 = F_1 ( V_23 ) ;
if ( V_23 == V_13 || ! F_6 ( V_4 ) )
continue;
V_21 = 0 ;
F_2 (d, &dmac_list, node) {
if ( V_20 != V_6 && F_7 ( V_20 , V_4 -> V_3 ) ) {
V_21 = 1 ;
break;
}
}
if ( ! V_21 )
V_22 ++ ;
}
return V_22 ;
}
static unsigned F_10 ( struct V_9 * V_6 ,
struct V_1 * V_4 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
enum V_2 * V_3 = V_6 -> V_11 ;
struct V_9 * V_20 ;
unsigned V_24 ;
int V_12 ;
V_24 = V_25 ;
if ( F_8 ( V_6 ) )
return V_24 ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ )
if ( V_3 [ V_12 ] == V_4 -> V_3 )
break;
if ( V_12 == V_14 )
return V_24 ;
V_24 = V_26 ;
F_2 (d, &dmac_list, node) {
if ( V_20 != V_6 && F_7 ( V_20 , V_4 -> V_3 ) && ! F_8 ( V_20 ) ) {
V_24 = 0 ;
break;
}
}
if ( V_24 )
return V_24 ;
V_24 = 100 ;
V_24 += ( V_16 -> V_18 . V_19 - V_6 -> V_17 ) - F_9 ( V_6 ) ;
return V_24 ;
}
static struct V_9 * F_11 ( struct V_1 * V_4 )
{
struct V_9 * V_20 , * V_6 = NULL ;
unsigned V_27 , V_28 = V_25 ;
F_2 (d, &dmac_list, node) {
V_27 = F_10 ( V_20 , V_4 ) ;
if ( V_27 == V_26 )
return V_20 ;
if ( V_27 > V_28 )
V_6 = V_20 ;
}
return V_6 ;
}
static struct V_1 * F_12 ( const enum V_2 V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_9 * V_6 ;
if ( ! V_4 || ! F_6 ( V_4 ) ) {
V_4 = NULL ;
goto V_29;
}
V_6 = F_11 ( V_4 ) ;
if ( ! V_6 ) {
V_4 = NULL ;
goto V_29;
}
V_6 -> V_17 ++ ;
V_4 -> V_6 = V_6 ;
V_29:
return V_4 ;
}
static inline void F_13 ( struct V_30 * V_31 )
{
struct V_30 * V_32 ;
struct V_1 * V_4 ;
int V_21 ;
if ( ! V_31 )
return;
V_4 = V_31 -> V_33 ;
V_21 = 0 ;
F_2 (t, &ch->xfer_list, node)
if ( V_32 == V_31 ) {
V_21 = 1 ;
break;
}
if ( ! V_21 )
return;
if ( V_31 -> V_7 . V_34 == & V_4 -> V_35 )
V_32 = F_14 ( V_4 -> V_35 . V_34 ,
struct V_30 , V_7 ) ;
else
V_32 = F_14 ( V_31 -> V_7 . V_34 ,
struct V_30 , V_7 ) ;
if ( V_32 == V_31 )
V_4 -> V_36 = NULL ;
else if ( V_4 -> V_36 == V_31 )
V_4 -> V_36 = V_32 ;
F_15 ( & V_31 -> V_7 ) ;
}
static struct V_30 * F_16 ( struct V_1 * V_4 ,
int V_37 )
{
struct V_30 * V_31 = V_4 -> V_36 ;
if ( ! V_31 )
return NULL ;
if ( V_31 -> V_7 . V_34 == & V_4 -> V_35 )
V_4 -> V_36 = F_14 ( V_4 -> V_35 . V_34 ,
struct V_30 , V_7 ) ;
else
V_4 -> V_36 = F_14 ( V_31 -> V_7 . V_34 ,
struct V_30 , V_7 ) ;
if ( V_37 || ! ( V_4 -> V_38 & V_39 ) )
F_13 ( V_31 ) ;
return V_31 ;
}
static inline void F_17 ( struct V_1 * V_4 ,
struct V_30 * V_31 , int V_40 )
{
struct V_41 * V_42 ;
if ( V_4 -> V_36 == NULL )
V_4 -> V_36 = V_31 ;
V_42 = & V_4 -> V_36 -> V_43 ;
if ( V_4 -> V_38 & V_39 &&
( V_42 == V_4 -> V_44 [ 0 ] . V_45 || V_42 == V_4 -> V_44 [ 1 ] . V_45 ) )
V_4 -> V_36 = V_31 ;
if ( V_40 ) {
V_4 -> V_36 = V_31 ;
F_18 ( & V_31 -> V_7 , & V_4 -> V_35 ) ;
} else {
F_5 ( & V_31 -> V_7 , & V_4 -> V_35 ) ;
}
}
static inline void F_19 ( struct V_30 * V_31 ,
enum V_46 V_47 , int V_48 )
{
struct V_1 * V_4 ;
if ( ! V_31 )
return;
V_4 = V_31 -> V_33 ;
if ( V_4 -> V_49 )
V_4 -> V_49 ( NULL , V_31 -> V_50 , V_31 -> V_43 . V_51 , V_47 ) ;
if ( V_48 || ! ( V_4 -> V_38 & V_39 ) )
F_20 ( V_4 -> V_6 -> V_52 , V_31 ) ;
}
static inline int F_21 ( struct V_1 * V_4 ,
struct V_53 * V_54 )
{
struct V_30 * V_31 ;
int V_55 = 0 ;
if ( V_54 -> V_45 )
return 0 ;
V_31 = F_16 ( V_4 , 0 ) ;
if ( V_31 ) {
V_54 -> V_45 = & V_31 -> V_43 ;
if ( V_54 -> V_56 == V_57 ) {
struct V_15 * V_16 = V_31 -> V_33 -> V_6 -> V_16 ;
int V_58 = 1 << V_4 -> V_59 . V_60 ;
T_1 V_51 = V_54 -> V_45 -> V_51 ;
int V_61 ;
V_61 = V_16 -> V_18 . V_62 / 8 ;
V_61 *= V_16 -> V_18 . V_63 ;
V_61 /= V_58 ;
if ( V_61 > 16 )
V_61 = 16 ;
while ( V_61 > 1 ) {
if ( ! ( V_51 % ( V_61 * V_58 ) ) )
break;
V_61 -- ;
}
V_4 -> V_59 . V_64 = V_61 ;
} else {
V_4 -> V_59 . V_64 = 1 ;
}
V_55 = F_22 ( V_4 -> V_65 , V_54 ) ;
if ( ! V_55 ) {
V_4 -> V_66 = V_54 ;
return 0 ;
}
V_54 -> V_45 = NULL ;
if ( V_55 == - V_67 ) {
F_23 ( V_4 -> V_6 -> V_16 -> V_68 , L_1 ,
V_69 , __LINE__ ) ;
F_17 ( V_4 , V_31 , 1 ) ;
V_55 = 0 ;
} else {
F_23 ( V_4 -> V_6 -> V_16 -> V_68 , L_1 ,
V_69 , __LINE__ ) ;
F_19 ( V_31 , V_70 , 0 ) ;
}
}
return V_55 ;
}
static void F_24 ( struct V_1 * V_4 ,
struct V_53 * V_54 , enum V_71 V_72 )
{
unsigned long V_73 ;
struct V_30 * V_31 ;
struct V_41 * V_74 = V_54 -> V_45 ;
enum V_46 V_47 ;
F_25 ( & V_75 , V_73 ) ;
V_54 -> V_45 = NULL ;
F_21 ( V_4 , V_54 ) ;
F_26 ( & V_75 , V_73 ) ;
if ( V_72 == V_76 )
V_47 = V_77 ;
else if ( V_72 == V_78 )
V_47 = V_79 ;
else
V_47 = V_70 ;
if ( V_74 ) {
V_31 = F_27 ( V_74 , struct V_30 , V_43 ) ;
F_19 ( V_31 , V_47 , 0 ) ;
} else {
F_28 ( V_4 -> V_6 -> V_16 -> V_68 , L_2 ,
V_69 , __LINE__ ) ;
}
}
static void F_29 ( void * V_50 , enum V_71 V_72 )
{
struct V_53 * V_54 = V_50 ;
struct V_1 * V_4 = F_27 ( V_54 ,
struct V_1 , V_44 [ 0 ] ) ;
F_24 ( V_4 , V_54 , V_72 ) ;
}
static void F_30 ( void * V_50 , enum V_71 V_72 )
{
struct V_53 * V_54 = V_50 ;
struct V_1 * V_4 = F_27 ( V_54 ,
struct V_1 , V_44 [ 1 ] ) ;
F_24 ( V_4 , V_54 , V_72 ) ;
}
static void F_31 ( struct V_1 * V_4 )
{
struct V_9 * V_6 ;
if ( F_6 ( V_4 ) )
return;
V_6 = V_4 -> V_6 ;
V_4 -> V_6 = NULL ;
V_6 -> V_17 -- ;
}
int F_32 ( enum V_2 V_3 , enum V_80 V_81 )
{
struct V_30 * V_31 ;
enum V_82 V_83 ;
struct V_1 * V_4 ;
unsigned long V_73 ;
int V_84 , V_55 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || F_6 ( V_4 ) ) {
V_55 = - V_85 ;
goto V_86;
}
switch ( V_81 ) {
case V_87 :
V_84 = ( V_4 -> V_66 == & V_4 -> V_44 [ 0 ] ) ? 1 : 0 ;
F_21 ( V_4 , & V_4 -> V_44 [ V_84 ] ) ;
F_21 ( V_4 , & V_4 -> V_44 [ 1 - V_84 ] ) ;
V_83 = V_88 ;
break;
case V_89 :
V_83 = V_90 ;
break;
case V_91 :
V_83 = V_92 ;
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
F_26 ( & V_75 , V_73 ) ;
return 0 ;
default:
F_26 ( & V_75 , V_73 ) ;
return - V_85 ;
}
V_55 = F_33 ( V_4 -> V_65 , V_83 ) ;
if ( V_83 == V_88 ) {
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
V_84 = ( V_4 -> V_66 == & V_4 -> V_44 [ 0 ] ) ? 1 : 0 ;
if ( V_4 -> V_44 [ V_84 ] . V_45 ) {
V_31 = F_27 ( V_4 -> V_44 [ V_84 ] . V_45 ,
struct V_30 , V_43 ) ;
if ( V_83 == V_92 )
F_13 ( V_31 ) ;
V_4 -> V_44 [ V_84 ] . V_45 = NULL ;
F_26 ( & V_75 , V_73 ) ;
F_19 ( V_31 , V_79 ,
V_83 == V_92 ? 1 : 0 ) ;
F_25 ( & V_75 , V_73 ) ;
}
if ( V_83 == V_92 ) {
if ( V_4 -> V_44 [ 1 - V_84 ] . V_45 ) {
V_31 = F_27 ( V_4 -> V_44 [ 1 - V_84 ] . V_45 ,
struct V_30 , V_43 ) ;
F_13 ( V_31 ) ;
V_4 -> V_44 [ 1 - V_84 ] . V_45 = NULL ;
F_26 ( & V_75 , V_73 ) ;
F_19 ( V_31 , V_79 , 1 ) ;
F_25 ( & V_75 , V_73 ) ;
}
V_31 = V_4 -> V_36 ;
while ( V_31 ) {
F_13 ( V_31 ) ;
F_26 ( & V_75 , V_73 ) ;
F_19 ( V_31 , V_79 , 1 ) ;
F_25 ( & V_75 , V_73 ) ;
V_31 = V_4 -> V_36 ;
}
}
V_86:
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
int F_34 ( enum V_2 V_3 , void * V_50 ,
T_2 V_97 , int V_98 )
{
struct V_1 * V_4 ;
struct V_30 * V_31 ;
unsigned long V_73 ;
int V_84 , V_55 = 0 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || F_6 ( V_4 ) ) {
V_55 = - V_85 ;
goto V_99;
}
if ( V_4 -> V_59 . V_60 && V_98 % ( 1 << V_4 -> V_59 . V_60 ) ) {
V_55 = - V_85 ;
goto V_99;
}
V_31 = F_35 ( V_4 -> V_6 -> V_52 , V_100 ) ;
if ( ! V_31 ) {
V_55 = - V_101 ;
goto V_99;
}
V_31 -> V_50 = V_50 ;
V_31 -> V_33 = V_4 ;
V_31 -> V_43 . V_51 = V_98 ;
V_31 -> V_43 . V_34 = NULL ;
if ( V_4 -> V_44 [ 0 ] . V_56 == V_102 ) {
V_31 -> V_43 . V_103 = V_97 ;
V_31 -> V_43 . V_104 = V_4 -> V_105 ;
} else {
V_31 -> V_43 . V_103 = V_4 -> V_105 ;
V_31 -> V_43 . V_104 = V_97 ;
}
F_17 ( V_4 , V_31 , 0 ) ;
V_84 = ( V_4 -> V_66 == & V_4 -> V_44 [ 0 ] ) ? 1 : 0 ;
if ( ! V_4 -> V_44 [ V_84 ] . V_45 )
F_21 ( V_4 , & V_4 -> V_44 [ V_84 ] ) ;
else
F_21 ( V_4 , & V_4 -> V_44 [ 1 - V_84 ] ) ;
F_26 ( & V_75 , V_73 ) ;
if ( V_4 -> V_38 & V_106 )
F_32 ( V_3 , V_87 ) ;
return 0 ;
V_99:
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
int F_36 ( enum V_2 V_3 ,
struct V_107 * V_108 ,
void * V_68 )
{
struct V_9 * V_6 ;
struct V_1 * V_4 ;
unsigned long V_73 ;
int V_55 = 0 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_12 ( V_3 ) ;
if ( ! V_4 ) {
V_55 = - V_109 ;
goto V_110;
}
V_6 = V_4 -> V_6 ;
V_4 -> V_65 = F_37 ( V_6 -> V_16 ) ;
if ( ! V_4 -> V_65 ) {
F_31 ( V_4 ) ;
V_55 = - V_109 ;
goto V_110;
}
V_4 -> V_108 = V_108 ;
V_4 -> V_38 = 0 ;
V_4 -> V_49 = NULL ;
V_4 -> V_66 = NULL ;
V_4 -> V_59 . V_60 = 2 ;
V_4 -> V_59 . V_111 = V_112 ;
V_4 -> V_59 . V_113 = V_114 ;
V_4 -> V_59 . V_115 = V_116 ;
V_4 -> V_59 . V_117 = 0 ;
V_4 -> V_59 . V_118 = 0 ;
V_4 -> V_44 [ 0 ] . V_56 = V_119 ;
V_4 -> V_44 [ 1 ] . V_56 = V_4 -> V_44 [ 0 ] . V_56 ;
V_4 -> V_44 [ 0 ] . V_120 = & V_4 -> V_59 ;
V_4 -> V_44 [ 1 ] . V_120 = V_4 -> V_44 [ 0 ] . V_120 ;
V_4 -> V_44 [ 0 ] . V_11 = F_7 ( V_6 , V_3 ) - 1 ;
V_4 -> V_44 [ 1 ] . V_11 = V_4 -> V_44 [ 0 ] . V_11 ;
V_4 -> V_44 [ 0 ] . V_50 = & V_4 -> V_44 [ 0 ] ;
V_4 -> V_44 [ 0 ] . V_121 = F_29 ;
V_4 -> V_44 [ 1 ] . V_50 = & V_4 -> V_44 [ 1 ] ;
V_4 -> V_44 [ 1 ] . V_121 = F_30 ;
V_4 -> V_44 [ 0 ] . V_45 = NULL ;
V_4 -> V_44 [ 1 ] . V_45 = NULL ;
F_38 ( & V_4 -> V_35 ) ;
V_4 -> V_36 = NULL ;
V_110:
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
int F_39 ( enum V_2 V_3 , struct V_107 * V_108 )
{
struct V_1 * V_4 ;
struct V_30 * V_31 ;
unsigned long V_73 ;
int V_55 = 0 ;
unsigned V_84 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || F_6 ( V_4 ) )
goto V_122;
if ( V_4 -> V_108 != V_108 ) {
V_55 = - V_109 ;
goto V_122;
}
F_33 ( V_4 -> V_65 , V_92 ) ;
V_84 = ( V_4 -> V_66 == & V_4 -> V_44 [ 0 ] ) ? 1 : 0 ;
if ( V_4 -> V_44 [ V_84 ] . V_45 ) {
V_31 = F_27 ( V_4 -> V_44 [ V_84 ] . V_45 ,
struct V_30 , V_43 ) ;
V_4 -> V_44 [ V_84 ] . V_45 = NULL ;
F_13 ( V_31 ) ;
F_26 ( & V_75 , V_73 ) ;
F_19 ( V_31 , V_79 , 1 ) ;
F_25 ( & V_75 , V_73 ) ;
}
if ( V_4 -> V_44 [ 1 - V_84 ] . V_45 ) {
V_31 = F_27 ( V_4 -> V_44 [ 1 - V_84 ] . V_45 ,
struct V_30 , V_43 ) ;
V_4 -> V_44 [ 1 - V_84 ] . V_45 = NULL ;
F_13 ( V_31 ) ;
F_26 ( & V_75 , V_73 ) ;
F_19 ( V_31 , V_79 , 1 ) ;
F_25 ( & V_75 , V_73 ) ;
}
do {
V_31 = F_16 ( V_4 , 1 ) ;
F_26 ( & V_75 , V_73 ) ;
F_19 ( V_31 , V_79 , 1 ) ;
F_25 ( & V_75 , V_73 ) ;
} while ( V_31 );
V_4 -> V_108 = NULL ;
F_40 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
F_31 ( V_4 ) ;
V_122:
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
int F_41 ( enum V_2 V_3 , int V_123 )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
unsigned long V_73 ;
int V_12 , V_124 , V_55 = 0 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || F_6 ( V_4 ) ) {
V_55 = - V_85 ;
goto V_125;
}
V_16 = V_4 -> V_6 -> V_16 ;
V_124 = V_16 -> V_18 . V_62 / 8 ;
if ( V_123 > V_124 ) {
V_55 = - V_85 ;
goto V_125;
}
V_12 = 0 ;
while ( V_123 != ( 1 << V_12 ) )
V_12 ++ ;
if ( V_123 == ( 1 << V_12 ) )
V_4 -> V_59 . V_60 = V_12 ;
else
V_55 = - V_85 ;
V_125:
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
int F_42 ( enum V_2 V_3 , unsigned int V_38 )
{
struct V_1 * V_4 ;
unsigned long V_73 ;
int V_55 = 0 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || F_6 ( V_4 ) || V_38 & ~ ( V_126 ) )
V_55 = - V_85 ;
else
V_4 -> V_38 = V_38 ;
F_26 ( & V_75 , V_73 ) ;
return 0 ;
}
int F_43 ( enum V_2 V_3 , T_3 V_127 )
{
struct V_1 * V_4 ;
unsigned long V_73 ;
int V_55 = 0 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || F_6 ( V_4 ) )
V_55 = - V_85 ;
else
V_4 -> V_49 = V_127 ;
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
int F_44 ( enum V_2 V_3 , enum V_128 V_129 ,
unsigned long V_130 )
{
struct V_1 * V_4 ;
unsigned long V_73 ;
int V_55 = 0 ;
F_25 ( & V_75 , V_73 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 || F_6 ( V_4 ) ) {
V_55 = - V_85 ;
goto V_131;
}
switch ( V_129 ) {
case V_132 :
V_4 -> V_44 [ 0 ] . V_56 = V_133 ;
V_4 -> V_44 [ 1 ] . V_56 = V_133 ;
V_4 -> V_59 . V_134 = 0 ;
V_4 -> V_59 . V_135 = 1 ;
break;
case V_136 :
V_4 -> V_44 [ 0 ] . V_56 = V_102 ;
V_4 -> V_44 [ 1 ] . V_56 = V_102 ;
V_4 -> V_59 . V_134 = 1 ;
V_4 -> V_59 . V_135 = 0 ;
break;
default:
V_55 = - V_85 ;
goto V_131;
}
V_4 -> V_105 = V_130 ;
V_131:
F_26 ( & V_75 , V_73 ) ;
return V_55 ;
}
int F_45 ( enum V_2 V_3 , T_2 * V_137 , T_2 * V_138 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_139 V_140 ;
int V_55 ;
if ( ! V_4 || F_6 ( V_4 ) )
return - V_85 ;
V_55 = F_46 ( V_4 -> V_65 , & V_140 ) ;
if ( V_55 < 0 )
return V_55 ;
* V_137 = V_140 . V_103 ;
* V_138 = V_140 . V_104 ;
return 0 ;
}
static T_4 F_47 ( int V_141 , void * V_142 )
{
if ( F_48 ( V_142 ) )
return V_143 ;
else
return V_144 ;
}
static int F_49 ( struct V_145 * V_146 )
{
struct V_9 * V_9 ;
struct V_147 * V_148 ;
struct V_15 * V_15 ;
struct V_149 * V_47 ;
int V_12 , V_55 , V_141 ;
V_148 = V_146 -> V_68 . V_150 ;
if ( ! V_148 || ! V_148 -> V_11 ) {
F_23 ( & V_146 -> V_68 , L_3 ) ;
return - V_151 ;
}
V_15 = F_50 ( sizeof( * V_15 ) , V_5 ) ;
if ( ! V_15 )
return - V_101 ;
V_15 -> V_152 = NULL ;
V_15 -> V_68 = & V_146 -> V_68 ;
V_47 = F_51 ( V_146 , V_153 , 0 ) ;
if ( ! V_47 ) {
V_55 = - V_151 ;
goto V_154;
}
F_52 ( V_47 -> V_155 , F_53 ( V_47 ) , V_146 -> V_156 ) ;
V_15 -> V_157 = F_54 ( V_47 -> V_155 , F_53 ( V_47 ) ) ;
if ( ! V_15 -> V_157 ) {
V_55 = - V_158 ;
goto V_159;
}
V_141 = F_55 ( V_146 , 0 ) ;
if ( V_141 < 0 ) {
V_55 = V_141 ;
goto V_160;
}
V_55 = F_56 ( V_141 , F_47 , 0 ,
F_57 ( & V_146 -> V_68 ) , V_15 ) ;
if ( V_55 )
goto V_161;
V_9 = F_4 ( sizeof( * V_9 ) , V_5 ) ;
if ( ! V_9 ) {
V_55 = - V_101 ;
goto V_162;
}
V_9 -> V_163 = F_58 ( & V_146 -> V_68 , L_4 ) ;
if ( F_59 ( V_9 -> V_163 ) ) {
F_23 ( & V_146 -> V_68 , L_5 ) ;
V_55 = - V_85 ;
goto V_164;
}
F_60 ( V_9 -> V_163 ) ;
V_55 = F_61 ( V_15 ) ;
if ( V_55 )
goto V_165;
V_9 -> V_16 = V_15 ;
V_9 -> V_17 = 0 ;
V_9 -> V_52 = F_62 ( F_57 ( & V_146 -> V_68 ) ,
sizeof( struct V_30 ) , 0 , 0 , NULL ) ;
if ( ! V_9 -> V_52 ) {
V_55 = - V_101 ;
goto V_166;
}
V_9 -> V_11 = V_148 -> V_11 ;
F_5 ( & V_9 -> V_7 , & V_167 ) ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ )
if ( V_9 -> V_11 [ V_12 ] != V_13 )
F_3 ( V_9 -> V_11 [ V_12 ] ) ;
F_63 ( V_168
L_6 , V_146 -> V_3 , V_146 -> V_156 ) ;
F_63 ( V_168
L_7 ,
V_15 -> V_18 . V_63 ,
V_15 -> V_18 . V_62 / 8 , V_15 -> V_18 . V_19 ,
V_15 -> V_18 . V_169 , V_15 -> V_18 . V_170 ) ;
return 0 ;
V_166:
F_64 ( V_15 ) ;
V_165:
F_65 ( V_9 -> V_163 ) ;
F_66 ( V_9 -> V_163 ) ;
V_164:
F_67 ( V_9 ) ;
V_162:
F_68 ( V_141 , V_15 ) ;
V_161:
V_160:
F_69 ( V_15 -> V_157 ) ;
V_159:
F_70 ( V_47 -> V_155 , F_53 ( V_47 ) ) ;
V_154:
F_67 ( V_15 ) ;
return V_55 ;
}
static int F_71 ( struct V_145 * V_146 )
{
struct V_9 * V_6 , * V_20 ;
struct V_1 * V_4 ;
unsigned long V_73 ;
int V_171 , V_21 ;
if ( ! V_146 -> V_68 . V_150 )
return - V_85 ;
F_25 ( & V_75 , V_73 ) ;
V_21 = 0 ;
F_2 (d, &dmac_list, node)
if ( V_20 -> V_16 -> V_68 == & V_146 -> V_68 ) {
V_21 = 1 ;
break;
}
if ( ! V_21 ) {
F_26 ( & V_75 , V_73 ) ;
return 0 ;
}
V_6 = V_20 ;
F_2 (ch, &chan_list, node) {
if ( F_7 ( V_6 , V_4 -> V_3 ) )
V_171 = 1 ;
else
continue;
F_2 (d, &dmac_list, node)
if ( V_20 != V_6 && F_7 ( V_20 , V_4 -> V_3 ) ) {
V_171 = 0 ;
break;
}
if ( V_171 ) {
F_26 ( & V_75 , V_73 ) ;
F_39 ( V_4 -> V_3 , V_4 -> V_108 ) ;
F_25 ( & V_75 , V_73 ) ;
F_15 ( & V_4 -> V_7 ) ;
F_67 ( V_4 ) ;
}
}
F_65 ( V_6 -> V_163 ) ;
F_66 ( V_6 -> V_163 ) ;
F_15 ( & V_6 -> V_7 ) ;
F_67 ( V_6 ) ;
F_26 ( & V_75 , V_73 ) ;
return 0 ;
}
static int T_5 F_72 ( void )
{
return F_73 ( & V_172 ) ;
}
static void T_6 F_74 ( void )
{
F_75 ( & V_172 ) ;
return;
}
