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
F_18 ( V_25 ) ;
F_10 ( V_2 , V_26 , 0 ) ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
F_18 ( V_25 ) ;
F_10 ( V_2 , V_26 , V_27 ) ;
}
static int F_20 ( struct V_28 * V_29 , T_2 * V_8 , T_3 V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_2 ;
int V_31 = - 1 ;
int V_32 = 0 ;
F_18 ( V_25 ) ;
F_19 ( V_2 ) ;
while ( 1 ) {
T_3 V_33 = F_4 ( V_2 , V_34 ) ;
if ( V_33 & V_35 )
break;
if ( ++ V_32 > 100 ) {
F_21 ( V_29 -> V_36 , L_7 ) ;
goto V_37;
}
F_22 ( 1 ) ;
}
F_10 ( V_2 , V_38 , V_30 ) ;
F_12 ( V_2 , V_39 , V_8 , V_30 / 2 ) ;
if ( V_30 & 1 )
F_8 ( V_2 , V_39 , V_8 [ V_30 - 1 ] ) ;
F_10 ( V_2 , V_40 , V_35 ) ;
F_10 ( V_2 , V_41 , V_35 ) ;
V_31 = 0 ;
V_37:
F_17 ( V_2 ) ;
F_23 ( V_25 , L_8 , V_31 ) ;
return V_31 ;
}
static void F_24 ( struct V_28 * V_29 , T_2 * V_8 , T_3 V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_2 ;
T_3 V_33 ;
F_18 ( V_25 ) ;
F_19 ( V_2 ) ;
V_33 = F_4 ( V_2 , V_34 ) ;
F_25 ( ( V_33 & V_42 ) == 0 ) ;
F_10 ( V_2 , V_43 , V_30 ) ;
F_12 ( V_2 , V_44 , V_8 , V_30 / 2 ) ;
if ( V_30 & 1 )
F_8 ( V_2 , V_44 , V_8 [ V_30 - 1 ] ) ;
F_10 ( V_2 , V_40 , V_42 ) ;
F_10 ( V_2 , V_41 , V_42 ) ;
F_17 ( V_2 ) ;
F_26 ( V_25 ) ;
}
static int F_27 ( struct V_28 * V_29 , T_2 * V_45 , T_4 * V_46 )
{
unsigned long V_47 ;
int V_31 = - 1 ;
T_3 V_33 ;
F_18 ( V_25 ) ;
V_33 = F_4 ( V_29 -> V_2 , V_34 ) ;
if ( ( V_33 & V_48 ) == 0 ) {
F_21 ( V_29 -> V_36 , L_9 ) ;
* V_46 = 0 ;
goto V_49;
}
* V_46 = F_4 ( V_29 -> V_2 , V_50 ) ;
if ( ( * V_46 == 0 ) || ( * V_46 > V_51 ) ) {
F_21 ( V_29 -> V_36 ,
L_10 ,
* V_46 ) ;
goto V_49;
}
F_6 ( V_29 -> V_2 , V_52 , V_45 , * V_46 / sizeof( T_3 ) ) ;
if ( * V_46 & 1 )
V_45 [ * V_46 - 1 ] = F_1 ( V_29 -> V_2 , V_52 ) ;
* V_46 -= 8 ;
V_31 = 0 ;
F_28 ( & V_29 -> V_53 , V_47 ) ;
V_29 -> V_54 = V_55 ;
F_29 ( & V_29 -> V_53 , V_47 ) ;
V_49:
F_23 ( V_25 , L_11 , V_31 , * V_46 ) ;
return V_31 ;
}
static struct V_56 * F_30 ( struct V_28 * V_29 )
{
struct V_56 * V_57 = NULL ;
T_3 V_46 ;
T_2 * V_45 ;
F_18 ( V_25 ) ;
V_46 = F_4 ( V_29 -> V_2 , V_58 ) ;
if ( V_46 == 0 || V_46 > V_59 ) {
F_21 ( V_29 -> V_36 ,
L_12 ,
V_46 ) ;
V_29 -> V_36 -> V_60 . V_61 ++ ;
goto V_62;
}
V_57 = F_31 ( V_59 + 2 ) ;
if ( ! V_57 )
goto V_49;
F_32 ( V_57 , V_46 ) ;
F_33 ( V_57 , 2 ) ;
V_45 = V_57 -> V_45 ;
F_6 ( V_29 -> V_2 , V_63 , V_45 , V_46 / sizeof( T_3 ) ) ;
if ( V_46 & 1 )
V_45 [ V_46 - 1 ] = F_1 ( V_29 -> V_2 , V_63 ) ;
V_62:
F_10 ( V_29 -> V_2 , V_40 , V_64 ) ;
F_10 ( V_29 -> V_2 , V_41 , V_64 ) ;
V_49:
F_23 ( V_25 , L_13 , V_57 ) ;
return V_57 ;
}
static T_5 F_34 ( int V_65 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
struct V_28 * V_29 = V_2 -> V_29 ;
T_3 V_66 ;
F_18 ( V_25 ) ;
V_66 = F_4 ( V_2 , V_67 ) ;
F_35 ( L_14 , V_66 ) ;
if ( V_66 == 0 ) {
return V_68 ;
}
if ( V_66 == 0xffff ) {
V_2 -> V_29 -> V_69 = 1 ;
return V_70 ;
}
if ( V_66 & V_64 ) {
struct V_56 * V_57 ;
F_35 ( L_15 ) ;
V_57 = F_30 ( V_29 ) ;
if ( V_57 )
F_36 ( V_29 , V_57 ) ;
}
if ( V_66 & V_42 ) {
F_35 ( L_16 ) ;
F_37 ( V_29 ) ;
}
if ( V_66 & V_48 ) {
unsigned long V_47 ;
T_2 V_11 ;
F_35 ( L_17 ) ;
F_28 ( & V_29 -> V_53 , V_47 ) ;
V_11 = ( V_29 -> V_71 == 0 ) ? 1 : 0 ;
F_29 ( & V_29 -> V_53 , V_47 ) ;
F_25 ( V_29 -> V_72 [ V_11 ] ) ;
F_27 ( V_29 , V_29 -> V_73 [ V_11 ] ,
& V_29 -> V_72 [ V_11 ] ) ;
F_28 ( & V_29 -> V_53 , V_47 ) ;
F_38 ( V_29 , V_11 ) ;
F_29 ( & V_29 -> V_53 , V_47 ) ;
}
if ( V_66 & V_74 ) {
T_3 V_33 = F_4 ( V_29 -> V_2 , V_34 ) ;
F_10 ( V_29 -> V_2 , V_41 ,
V_74 ) ;
F_39 ( V_29 , ( V_33 & V_75 ) >> 8 ) ;
}
F_10 ( V_2 , V_67 , V_66 & V_27 ) ;
F_26 ( V_25 ) ;
return V_70 ;
}
static int F_40 ( struct V_1 * V_2 , const struct V_76 * V_77 )
{
int V_31 = 0 ;
int V_78 = 0 ;
T_2 V_79 ;
F_18 ( V_25 ) ;
if ( V_2 -> V_80 )
V_79 = F_4 ( V_2 , V_81 ) >> 8 ;
else
V_79 = F_1 ( V_2 , V_81 ) ;
if ( V_79 == V_82 )
goto V_37;
if ( V_79 != V_83 ) {
V_31 = - V_84 ;
goto V_37;
}
F_35 ( L_18 , V_77 -> V_85 ) ;
for (; ; ) {
int V_9 = 256 ;
int V_86 = V_77 -> V_85 - V_78 ;
if ( V_86 < V_9 )
V_9 = V_86 ;
F_10 ( V_2 , V_38 , V_9 ) ;
if ( V_9 )
F_12 ( V_2 , V_39 ,
& V_77 -> V_45 [ V_78 ] ,
V_9 >> 1 ) ;
F_8 ( V_2 , V_40 , V_35 ) ;
F_10 ( V_2 , V_41 , V_35 ) ;
V_31 = F_14 ( V_2 , V_34 ,
V_35 ) ;
if ( V_31 < 0 ) {
F_41 ( L_19 ,
V_78 , V_31 ) ;
goto V_37;
}
if ( V_9 == 0 )
break;
V_78 += V_9 ;
}
V_37:
F_23 ( V_25 , L_8 , V_31 ) ;
return V_31 ;
}
static int F_42 ( struct V_1 * V_2 , const struct V_76 * V_77 )
{
int V_31 = 0 ;
int V_87 = 0 ;
int V_46 = 0 ;
int V_78 ;
F_18 ( V_25 ) ;
F_35 ( L_20 , V_77 -> V_85 ) ;
V_31 = F_14 ( V_2 , V_88 ,
V_89 ) ;
if ( V_31 < 0 ) {
F_41 ( L_21 ) ;
goto V_37;
}
for ( V_78 = 0 ; V_78 < V_77 -> V_85 ; V_78 += V_46 ) {
V_46 = F_4 ( V_2 , V_88 ) ;
if ( V_46 & 1 ) {
V_87 ++ ;
F_43 ( L_22 ) ;
} else {
V_87 = 0 ;
}
if ( V_87 > 20 ) {
F_41 ( L_23 ) ;
V_31 = - V_84 ;
goto V_37;
}
if ( V_87 ) {
V_78 -= V_46 ;
}
F_10 ( V_2 , V_38 , V_46 ) ;
F_12 ( V_2 , V_39 ,
& V_77 -> V_45 [ V_78 ] ,
( V_46 + 1 ) >> 1 ) ;
F_8 ( V_2 , V_40 , V_35 ) ;
F_10 ( V_2 , V_41 , V_35 ) ;
V_31 = F_14 ( V_2 , V_34 ,
V_35 ) ;
if ( V_31 < 0 ) {
F_41 ( L_24 , V_78 ) ;
goto V_37;
}
}
V_31 = F_14 ( V_2 , V_81 , 0x5a ) ;
if ( V_31 < 0 )
F_41 ( L_25 ) ;
V_37:
F_23 ( V_25 , L_8 , V_31 ) ;
return V_31 ;
}
static int F_44 ( struct V_28 * V_29 ,
T_2 type ,
T_2 * V_8 ,
T_3 V_30 )
{
int V_31 = - 1 ;
F_45 ( V_25 , L_26 , type , V_30 ) ;
switch ( type ) {
case V_90 :
V_29 -> V_54 = V_91 ;
F_24 ( V_29 , V_8 , V_30 ) ;
V_31 = 0 ;
break;
case V_92 :
V_29 -> V_54 = V_93 ;
V_31 = F_20 ( V_29 , V_8 , V_30 ) ;
break;
default:
F_21 ( V_29 -> V_36 , L_27 ,
V_94 , type ) ;
}
F_23 ( V_25 , L_8 , V_31 ) ;
return V_31 ;
}
static void F_46 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_29 ;
F_18 ( V_25 ) ;
F_47 ( V_96 -> V_65 , V_2 ) ;
F_48 ( V_96 ) ;
if ( V_2 -> V_5 )
F_49 ( V_2 -> V_5 ) ;
F_26 ( V_25 ) ;
}
static int F_50 ( struct V_95 * V_96 , void * V_97 )
{
V_96 -> V_98 [ 0 ] -> V_47 &= ~ V_99 ;
V_96 -> V_98 [ 0 ] -> V_47 |= V_100 ;
if ( V_96 -> V_98 [ 1 ] -> V_101 ) {
F_41 ( L_28 ) ;
return - V_84 ;
}
return F_51 ( V_96 ) ;
}
static int F_52 ( struct V_95 * V_96 )
{
int V_31 = - V_102 ;
unsigned int V_103 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
const struct V_76 * V_104 = NULL ;
const struct V_76 * V_105 = NULL ;
F_18 ( V_25 ) ;
V_2 = F_53 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_2 )
goto V_49;
V_2 -> V_96 = V_96 ;
V_96 -> V_29 = V_2 ;
V_96 -> V_107 |= V_108 | V_109 ;
if ( F_54 ( V_96 , F_50 , NULL ) ) {
F_41 ( L_29 ) ;
goto V_110;
}
if ( ! V_96 -> V_65 )
goto V_110;
V_2 -> V_5 = F_55 ( V_96 -> V_98 [ 0 ] -> V_111 ,
F_56 ( V_96 -> V_98 [ 0 ] ) ) ;
if ( ! V_2 -> V_5 ) {
F_41 ( L_30 ) ;
V_31 = - V_112 ;
goto V_110;
}
V_31 = F_57 ( V_96 ) ;
if ( V_31 ) {
F_41 ( L_31 ) ;
goto V_113;
}
F_35 ( L_32 , V_96 -> V_65 , V_96 -> V_98 [ 0 ] ) ;
V_2 -> V_80 = false ;
V_2 -> V_114 = F_16 ( V_96 -> V_13 , V_96 -> V_14 ) ;
if ( V_2 -> V_114 == V_24 ) {
F_41 ( L_33 ,
V_96 -> V_13 , V_96 -> V_14 ) ;
goto V_113;
}
V_103 = F_1 ( V_2 , V_115 ) ;
if ( V_2 -> V_114 == V_17 ) {
V_2 -> V_80 = true ;
if ( V_103 < V_116 ) {
F_41 ( L_34 ) ;
V_31 = - V_84 ;
goto V_113;
}
}
if ( ( V_2 -> V_114 == V_20 ) && V_103 < V_117 ) {
F_41 ( L_35 ) ;
V_31 = - V_84 ;
goto V_113;
}
if ( ( V_2 -> V_114 == V_23 ) && V_103 < V_118 ) {
F_41 ( L_36 ) ;
V_31 = - V_84 ;
goto V_113;
}
V_31 = F_58 ( & V_96 -> V_36 , NULL , NULL , V_2 -> V_114 ,
& V_119 [ 0 ] , & V_104 , & V_105 ) ;
if ( V_31 ) {
F_41 ( L_37 , V_31 ) ;
goto V_113;
}
V_31 = F_40 ( V_2 , V_104 ) ;
if ( V_31 == 0 && ( V_2 -> V_114 != V_17 ) )
V_31 = F_42 ( V_2 , V_105 ) ;
if ( V_31 )
goto V_113;
V_29 = F_59 ( V_2 , & V_96 -> V_36 ) ;
if ( ! V_29 ) {
V_31 = - V_102 ;
goto V_113;
}
V_2 -> V_29 = V_29 ;
V_29 -> V_2 = V_2 ;
V_29 -> V_120 = F_44 ;
V_29 -> V_121 = NULL ;
V_29 -> V_122 = NULL ;
V_29 -> V_123 = NULL ;
V_29 -> V_124 = 1 ;
V_31 = F_60 ( V_96 -> V_65 , F_34 ,
V_125 , V_126 , V_2 ) ;
if ( V_31 ) {
F_41 ( L_38 ) ;
goto V_127;
}
F_10 ( V_2 , V_67 , V_27 ) ;
F_17 ( V_2 ) ;
if ( F_61 ( V_29 ) != 0 ) {
F_41 ( L_39 ) ;
goto V_127;
}
V_31 = 0 ;
goto V_49;
V_127:
F_62 ( V_29 ) ;
V_113:
F_49 ( V_2 -> V_5 ) ;
V_110:
F_48 ( V_96 ) ;
V_49:
if ( V_104 )
F_63 ( V_104 ) ;
if ( V_105 )
F_63 ( V_105 ) ;
F_23 ( V_25 , L_8 , V_31 ) ;
return V_31 ;
}
static void F_64 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_29 ;
F_18 ( V_25 ) ;
F_65 ( V_2 -> V_29 ) ;
F_62 ( V_2 -> V_29 ) ;
F_19 ( V_2 ) ;
F_46 ( V_96 ) ;
F_66 ( V_2 ) ;
F_26 ( V_25 ) ;
}
static int T_6 F_67 ( void )
{
int V_31 ;
F_18 ( V_25 ) ;
V_31 = F_68 ( & V_128 ) ;
F_26 ( V_25 ) ;
return V_31 ;
}
static void T_7 F_69 ( void )
{
F_18 ( V_25 ) ;
F_70 ( & V_128 ) ;
F_26 ( V_25 ) ;
}
