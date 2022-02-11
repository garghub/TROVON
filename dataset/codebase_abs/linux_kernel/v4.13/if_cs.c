static inline unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_4 = F_2 ( V_2 -> V_5 + V_3 ) ;
if ( V_6 )
F_3 ( V_7 L_1 , V_3 , V_4 ) ;
return V_4 ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_4 = F_5 ( V_2 -> V_5 + V_3 ) ;
if ( V_6 )
F_3 ( V_7 L_2 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_6 (
struct V_1 * V_2 ,
T_1 V_3 ,
void * V_8 ,
unsigned long V_9 )
{
if ( V_6 )
F_3 ( V_7 L_3 ,
V_3 , V_9 ) ;
F_7 ( V_2 -> V_5 + V_3 , V_8 , V_9 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( V_6 )
F_3 ( V_7 L_4 , V_3 , V_4 ) ;
F_9 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 )
{
if ( V_6 )
F_3 ( V_7 L_5 , V_3 , V_4 ) ;
F_11 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline void F_12 (
struct V_1 * V_2 ,
T_1 V_3 ,
const void * V_8 ,
unsigned long V_9 )
{
if ( V_6 )
F_3 ( V_7 L_6 ,
V_3 , V_9 ) ;
F_13 ( V_2 -> V_5 + V_3 , V_8 , V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_10 , T_2 V_3 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < 100000 ; V_11 ++ ) {
T_2 V_4 = F_1 ( V_2 , V_10 ) ;
if ( V_4 == V_3 )
return 0 ;
F_15 ( 5 ) ;
}
return - V_12 ;
}
static inline T_4 F_16 ( T_3 V_13 , T_3 V_14 )
{
if ( V_13 == V_15 && V_14 == V_16 )
return V_17 ;
else if ( V_13 == V_18 && V_14 == V_19 )
return V_20 ;
else if ( V_13 == V_21 && V_14 == V_22 )
return V_23 ;
return V_24 ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_25 , 0 ) ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_25 , V_26 ) ;
}
static int F_19 ( struct V_27 * V_28 , T_2 * V_8 , T_3 V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 -> V_2 ;
int V_30 = - 1 ;
int V_31 = 0 ;
F_18 ( V_2 ) ;
while ( 1 ) {
T_3 V_32 = F_4 ( V_2 , V_33 ) ;
if ( V_32 & V_34 )
break;
if ( ++ V_31 > 100 ) {
F_20 ( V_28 -> V_35 , L_7 ) ;
goto V_36;
}
F_21 ( 1 ) ;
}
F_10 ( V_2 , V_37 , V_29 ) ;
F_12 ( V_2 , V_38 , V_8 , V_29 / 2 ) ;
if ( V_29 & 1 )
F_8 ( V_2 , V_38 , V_8 [ V_29 - 1 ] ) ;
F_10 ( V_2 , V_39 , V_34 ) ;
F_10 ( V_2 , V_40 , V_34 ) ;
V_30 = 0 ;
V_36:
F_17 ( V_2 ) ;
return V_30 ;
}
static void F_22 ( struct V_27 * V_28 , T_2 * V_8 , T_3 V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 -> V_2 ;
T_3 V_32 ;
F_18 ( V_2 ) ;
V_32 = F_4 ( V_2 , V_33 ) ;
F_23 ( ( V_32 & V_41 ) == 0 ) ;
F_10 ( V_2 , V_42 , V_29 ) ;
F_12 ( V_2 , V_43 , V_8 , V_29 / 2 ) ;
if ( V_29 & 1 )
F_8 ( V_2 , V_43 , V_8 [ V_29 - 1 ] ) ;
F_10 ( V_2 , V_39 , V_41 ) ;
F_10 ( V_2 , V_40 , V_41 ) ;
F_17 ( V_2 ) ;
}
static int F_24 ( struct V_27 * V_28 , T_2 * V_44 , T_4 * V_45 )
{
unsigned long V_46 ;
int V_30 = - 1 ;
T_3 V_32 ;
V_32 = F_4 ( V_28 -> V_2 , V_33 ) ;
if ( ( V_32 & V_47 ) == 0 ) {
F_20 ( V_28 -> V_35 , L_8 ) ;
* V_45 = 0 ;
goto V_48;
}
* V_45 = F_4 ( V_28 -> V_2 , V_49 ) ;
if ( ( * V_45 == 0 ) || ( * V_45 > V_50 ) ) {
F_20 ( V_28 -> V_35 ,
L_9 ,
* V_45 ) ;
goto V_48;
}
F_6 ( V_28 -> V_2 , V_51 , V_44 , * V_45 / sizeof( T_3 ) ) ;
if ( * V_45 & 1 )
V_44 [ * V_45 - 1 ] = F_1 ( V_28 -> V_2 , V_51 ) ;
* V_45 -= 8 ;
V_30 = 0 ;
F_25 ( & V_28 -> V_52 , V_46 ) ;
V_28 -> V_53 = V_54 ;
F_26 ( & V_28 -> V_52 , V_46 ) ;
V_48:
return V_30 ;
}
static struct V_55 * F_27 ( struct V_27 * V_28 )
{
struct V_55 * V_56 = NULL ;
T_3 V_45 ;
T_2 * V_44 ;
V_45 = F_4 ( V_28 -> V_2 , V_57 ) ;
if ( V_45 == 0 || V_45 > V_58 ) {
F_20 ( V_28 -> V_35 ,
L_10 ,
V_45 ) ;
V_28 -> V_35 -> V_59 . V_60 ++ ;
goto V_61;
}
V_56 = F_28 ( V_58 + 2 ) ;
if ( ! V_56 )
goto V_48;
F_29 ( V_56 , V_45 ) ;
F_30 ( V_56 , 2 ) ;
V_44 = V_56 -> V_44 ;
F_6 ( V_28 -> V_2 , V_62 , V_44 , V_45 / sizeof( T_3 ) ) ;
if ( V_45 & 1 )
V_44 [ V_45 - 1 ] = F_1 ( V_28 -> V_2 , V_62 ) ;
V_61:
F_10 ( V_28 -> V_2 , V_39 , V_63 ) ;
F_10 ( V_28 -> V_2 , V_40 , V_63 ) ;
V_48:
return V_56 ;
}
static T_5 F_31 ( int V_64 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_27 * V_28 = V_2 -> V_28 ;
T_3 V_65 ;
V_65 = F_4 ( V_2 , V_66 ) ;
F_32 ( L_11 , V_65 ) ;
if ( V_65 == 0 ) {
return V_67 ;
}
if ( V_65 == 0xffff ) {
V_2 -> V_28 -> V_68 = 1 ;
return V_69 ;
}
if ( V_65 & V_63 ) {
struct V_55 * V_56 ;
F_32 ( L_12 ) ;
V_56 = F_27 ( V_28 ) ;
if ( V_56 )
F_33 ( V_28 , V_56 ) ;
}
if ( V_65 & V_41 ) {
F_32 ( L_13 ) ;
F_34 ( V_28 ) ;
}
if ( V_65 & V_47 ) {
unsigned long V_46 ;
T_2 V_11 ;
F_32 ( L_14 ) ;
F_25 ( & V_28 -> V_52 , V_46 ) ;
V_11 = ( V_28 -> V_70 == 0 ) ? 1 : 0 ;
F_26 ( & V_28 -> V_52 , V_46 ) ;
F_23 ( V_28 -> V_71 [ V_11 ] ) ;
F_24 ( V_28 , V_28 -> V_72 [ V_11 ] ,
& V_28 -> V_71 [ V_11 ] ) ;
F_25 ( & V_28 -> V_52 , V_46 ) ;
F_35 ( V_28 , V_11 ) ;
F_26 ( & V_28 -> V_52 , V_46 ) ;
}
if ( V_65 & V_73 ) {
T_3 V_32 = F_4 ( V_28 -> V_2 , V_33 ) ;
F_10 ( V_28 -> V_2 , V_40 ,
V_73 ) ;
F_36 ( V_28 , ( V_32 & V_74 ) >> 8 ) ;
}
F_10 ( V_2 , V_66 , V_65 & V_26 ) ;
return V_69 ;
}
static int F_37 ( struct V_1 * V_2 , const struct V_75 * V_76 )
{
int V_30 = 0 ;
int V_77 = 0 ;
T_2 V_78 ;
if ( V_2 -> V_79 )
V_78 = F_4 ( V_2 , V_80 ) >> 8 ;
else
V_78 = F_1 ( V_2 , V_80 ) ;
if ( V_78 == V_81 )
goto V_36;
if ( V_78 != V_82 ) {
V_30 = - V_83 ;
goto V_36;
}
F_32 ( L_15 , V_76 -> V_84 ) ;
for (; ; ) {
int V_9 = 256 ;
int V_85 = V_76 -> V_84 - V_77 ;
if ( V_85 < V_9 )
V_9 = V_85 ;
F_10 ( V_2 , V_37 , V_9 ) ;
if ( V_9 )
F_12 ( V_2 , V_38 ,
& V_76 -> V_44 [ V_77 ] ,
V_9 >> 1 ) ;
F_8 ( V_2 , V_39 , V_34 ) ;
F_10 ( V_2 , V_40 , V_34 ) ;
V_30 = F_14 ( V_2 , V_33 ,
V_34 ) ;
if ( V_30 < 0 ) {
F_38 ( L_16 ,
V_77 , V_30 ) ;
goto V_36;
}
if ( V_9 == 0 )
break;
V_77 += V_9 ;
}
V_36:
return V_30 ;
}
static int F_39 ( struct V_1 * V_2 , const struct V_75 * V_76 )
{
int V_30 = 0 ;
int V_86 = 0 ;
int V_45 = 0 ;
int V_77 ;
F_32 ( L_17 , V_76 -> V_84 ) ;
V_30 = F_14 ( V_2 , V_87 ,
V_88 ) ;
if ( V_30 < 0 ) {
F_38 ( L_18 ) ;
goto V_36;
}
for ( V_77 = 0 ; V_77 < V_76 -> V_84 ; V_77 += V_45 ) {
V_45 = F_4 ( V_2 , V_87 ) ;
if ( V_45 & 1 ) {
V_86 ++ ;
F_40 ( L_19 ) ;
} else {
V_86 = 0 ;
}
if ( V_86 > 20 ) {
F_38 ( L_20 ) ;
V_30 = - V_83 ;
goto V_36;
}
if ( V_86 ) {
V_77 -= V_45 ;
}
F_10 ( V_2 , V_37 , V_45 ) ;
F_12 ( V_2 , V_38 ,
& V_76 -> V_44 [ V_77 ] ,
( V_45 + 1 ) >> 1 ) ;
F_8 ( V_2 , V_39 , V_34 ) ;
F_10 ( V_2 , V_40 , V_34 ) ;
V_30 = F_14 ( V_2 , V_33 ,
V_34 ) ;
if ( V_30 < 0 ) {
F_38 ( L_21 , V_77 ) ;
goto V_36;
}
}
V_30 = F_14 ( V_2 , V_80 , 0x5a ) ;
if ( V_30 < 0 )
F_38 ( L_22 ) ;
V_36:
return V_30 ;
}
static void F_41 ( struct V_27 * V_28 , int V_30 ,
const struct V_75 * V_89 ,
const struct V_75 * V_90 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
if ( V_30 ) {
F_38 ( L_23 , V_30 ) ;
return;
}
V_30 = F_37 ( V_2 , V_89 ) ;
if ( V_30 == 0 && ( V_2 -> V_91 != V_17 ) )
V_30 = F_39 ( V_2 , V_90 ) ;
if ( V_30 )
return;
V_30 = F_42 ( V_2 -> V_92 -> V_64 , F_31 ,
V_93 , V_94 , V_2 ) ;
if ( V_30 ) {
F_38 ( L_24 ) ;
return;
}
F_10 ( V_2 , V_66 , V_26 ) ;
F_17 ( V_2 ) ;
V_28 -> V_95 = 1 ;
if ( F_43 ( V_28 ) != 0 ) {
F_38 ( L_25 ) ;
F_44 ( V_2 -> V_92 -> V_64 , V_2 ) ;
}
}
static int F_45 ( struct V_27 * V_28 ,
T_2 type ,
T_2 * V_8 ,
T_3 V_29 )
{
int V_30 = - 1 ;
switch ( type ) {
case V_96 :
V_28 -> V_53 = V_97 ;
F_22 ( V_28 , V_8 , V_29 ) ;
V_30 = 0 ;
break;
case V_98 :
V_28 -> V_53 = V_99 ;
V_30 = F_19 ( V_28 , V_8 , V_29 ) ;
break;
default:
F_20 ( V_28 -> V_35 , L_26 ,
V_100 , type ) ;
}
return V_30 ;
}
static void F_46 ( struct V_101 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_28 ;
F_44 ( V_92 -> V_64 , V_2 ) ;
F_47 ( V_92 ) ;
if ( V_2 -> V_5 )
F_48 ( V_2 -> V_5 ) ;
}
static int F_49 ( struct V_101 * V_92 , void * V_102 )
{
V_92 -> V_103 [ 0 ] -> V_46 &= ~ V_104 ;
V_92 -> V_103 [ 0 ] -> V_46 |= V_105 ;
if ( V_92 -> V_103 [ 1 ] -> V_106 ) {
F_38 ( L_27 ) ;
return - V_83 ;
}
return F_50 ( V_92 ) ;
}
static int F_51 ( struct V_101 * V_92 )
{
int V_30 = - V_107 ;
unsigned int V_108 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
V_2 = F_52 ( sizeof( struct V_1 ) , V_109 ) ;
if ( ! V_2 )
goto V_48;
V_2 -> V_92 = V_92 ;
V_92 -> V_28 = V_2 ;
V_92 -> V_110 |= V_111 | V_112 ;
if ( F_53 ( V_92 , F_49 , NULL ) ) {
F_38 ( L_28 ) ;
goto V_113;
}
if ( ! V_92 -> V_64 )
goto V_113;
V_2 -> V_5 = F_54 ( V_92 -> V_103 [ 0 ] -> V_114 ,
F_55 ( V_92 -> V_103 [ 0 ] ) ) ;
if ( ! V_2 -> V_5 ) {
F_38 ( L_29 ) ;
V_30 = - V_115 ;
goto V_113;
}
V_30 = F_56 ( V_92 ) ;
if ( V_30 ) {
F_38 ( L_30 ) ;
goto V_116;
}
F_32 ( L_31 , V_92 -> V_64 , V_92 -> V_103 [ 0 ] ) ;
V_2 -> V_79 = false ;
V_2 -> V_91 = F_16 ( V_92 -> V_13 , V_92 -> V_14 ) ;
if ( V_2 -> V_91 == V_24 ) {
F_38 ( L_32 ,
V_92 -> V_13 , V_92 -> V_14 ) ;
V_30 = - V_83 ;
goto V_116;
}
V_108 = F_1 ( V_2 , V_117 ) ;
if ( V_2 -> V_91 == V_17 ) {
V_2 -> V_79 = true ;
if ( V_108 < V_118 ) {
F_38 ( L_33 ) ;
V_30 = - V_83 ;
goto V_116;
}
}
if ( ( V_2 -> V_91 == V_20 ) && V_108 < V_119 ) {
F_38 ( L_34 ) ;
V_30 = - V_83 ;
goto V_116;
}
if ( ( V_2 -> V_91 == V_23 ) && V_108 < V_120 ) {
F_38 ( L_35 ) ;
V_30 = - V_83 ;
goto V_116;
}
V_28 = F_57 ( V_2 , & V_92 -> V_35 ) ;
if ( ! V_28 ) {
V_30 = - V_107 ;
goto V_116;
}
V_2 -> V_28 = V_28 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_121 = F_45 ;
V_28 -> V_122 = NULL ;
V_28 -> V_123 = NULL ;
V_28 -> V_124 = NULL ;
V_30 = F_58 ( V_28 , & V_92 -> V_35 , V_2 -> V_91 , V_125 ,
F_41 ) ;
if ( V_30 ) {
F_38 ( L_23 , V_30 ) ;
goto V_126;
}
goto V_48;
V_126:
F_59 ( V_28 ) ;
V_116:
F_48 ( V_2 -> V_5 ) ;
V_113:
F_47 ( V_92 ) ;
V_48:
return V_30 ;
}
static void F_60 ( struct V_101 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_28 ;
F_61 ( V_2 -> V_28 ) ;
F_59 ( V_2 -> V_28 ) ;
F_18 ( V_2 ) ;
F_46 ( V_92 ) ;
F_62 ( V_2 ) ;
}
