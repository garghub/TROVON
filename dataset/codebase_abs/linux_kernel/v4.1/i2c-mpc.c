static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static T_2 F_3 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
if ( F_4 ( V_2 -> V_4 + V_8 ) & V_9 ) {
V_2 -> V_10 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
F_5 ( & V_2 -> V_11 ) ;
return V_12 ;
}
return V_13 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_14 ;
T_1 V_15 = 1000000 / V_2 -> V_16 + 1 ;
if ( V_15 < 2 )
V_15 = 2 ;
for ( V_14 = 9 ; V_14 ; V_14 -- ) {
F_1 ( V_2 , 0 ) ;
F_1 ( V_2 , V_17 | V_18 | V_19 ) ;
F_4 ( V_2 -> V_4 + V_20 ) ;
F_1 ( V_2 , V_19 ) ;
F_7 ( V_15 << 1 ) ;
}
}
static int F_8 ( struct V_1 * V_2 , unsigned V_21 , int V_22 )
{
unsigned long V_23 = V_24 ;
T_1 V_25 ;
int V_26 = 0 ;
if ( ! V_2 -> V_6 ) {
while ( ! ( F_4 ( V_2 -> V_4 + V_8 ) & V_9 ) ) {
F_9 () ;
if ( F_10 ( V_24 , V_23 + V_21 ) ) {
F_11 ( V_2 -> V_27 , L_1 ) ;
F_1 ( V_2 , 0 ) ;
V_26 = - V_28 ;
break;
}
}
V_25 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
} else {
V_26 = F_12 ( V_2 -> V_11 ,
( V_2 -> V_10 & V_9 ) , V_21 ) ;
if ( F_13 ( ! ( V_2 -> V_10 & V_9 ) ) ) {
F_11 ( V_2 -> V_27 , L_2 ) ;
F_1 ( V_2 , 0 ) ;
V_26 = - V_28 ;
}
V_25 = V_2 -> V_10 ;
V_2 -> V_10 = 0 ;
}
if ( V_26 < 0 )
return V_26 ;
if ( ! ( V_25 & V_29 ) ) {
F_11 ( V_2 -> V_27 , L_3 ) ;
return - V_30 ;
}
if ( V_25 & V_31 ) {
F_11 ( V_2 -> V_27 , L_4 ) ;
return - V_32 ;
}
if ( V_22 && ( V_25 & V_33 ) ) {
F_11 ( V_2 -> V_27 , L_5 ) ;
F_1 ( V_2 , V_19 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_14 ( struct V_35 * V_36 , T_1 clock ,
int V_37 , T_1 * V_16 )
{
const struct V_38 * div = NULL ;
unsigned int V_39 = F_15 ( V_40 ) ;
T_1 V_41 ;
int V_42 ;
if ( clock == V_43 ) {
* V_16 = F_16 ( V_36 ) / 2048 ;
return - V_44 ;
}
V_41 = F_16 ( V_36 ) / clock ;
for ( V_42 = 0 ; V_42 < F_17 ( V_45 ) ; V_42 ++ ) {
div = & V_45 [ V_42 ] ;
if ( div -> V_46 & 0xc0 && V_39 == 0x80822011 )
continue;
if ( div -> V_41 >= V_41 )
break;
}
* V_16 = F_16 ( V_36 ) / div -> V_41 ;
return ( int ) div -> V_46 ;
}
static void F_18 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_37 )
{
int V_47 , V_46 ;
if ( clock == V_48 ) {
F_11 ( V_2 -> V_27 , L_6 ,
F_4 ( V_2 -> V_4 + V_49 ) ) ;
return;
}
V_47 = F_14 ( V_36 , clock , V_37 , & V_2 -> V_16 ) ;
V_46 = ( V_47 >= 0 ) ? V_47 : 0x3f ;
F_2 ( V_46 & 0xff , V_2 -> V_4 + V_49 ) ;
if ( V_47 >= 0 )
F_19 ( V_2 -> V_27 , L_7 , V_2 -> V_16 ,
V_46 ) ;
}
static void F_18 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_37 )
{
}
static void F_20 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_37 )
{
struct V_35 * V_50 ;
void T_3 * V_51 ;
const T_1 * V_52 ;
T_1 V_53 ;
V_50 = F_21 ( NULL , NULL ,
L_8 ) ;
if ( V_50 ) {
V_51 = F_22 ( V_50 , 0 ) ;
if ( V_51 ) {
V_52 = F_23 ( V_36 , L_9 , NULL ) ;
V_53 = ( * V_52 & 0xff ) / 0x20 ;
F_24 ( V_51 , 1 << ( 24 + V_53 * 2 ) ) ;
F_25 ( V_51 ) ;
}
F_26 ( V_50 ) ;
}
F_18 ( V_36 , V_2 , clock , V_37 ) ;
}
static void F_20 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_37 )
{
}
static T_1 F_27 ( void )
{
struct V_35 * V_36 = NULL ;
T_1 T_3 * V_54 ;
T_1 V_55 = 0 ;
V_36 = F_28 ( NULL , L_10 ) ;
if ( V_36 ) {
const T_1 * V_56 = F_23 ( V_36 , L_9 , NULL ) ;
if ( V_56 ) {
V_54 = F_29 ( F_30 () + * V_56 + 0x14 , 0x4 ) ;
if ( ! V_54 )
F_31 ( V_57
L_11 ) ;
else
V_55 = F_32 ( V_54 ) & 0x00000080 ;
F_25 ( V_54 ) ;
}
}
F_26 ( V_36 ) ;
return V_55 ;
}
static T_1 F_33 ( void )
{
T_1 V_37 = 1 ;
if ( F_34 ( V_58 ) || F_34 ( V_59 )
|| F_34 ( V_60 )
|| F_34 ( V_61 )
|| F_34 ( V_62 ) ) {
unsigned int V_63 = F_15 ( V_64 ) ;
if ( ( F_35 ( V_63 ) == V_65 )
|| ( F_35 ( V_63 ) == V_66 )
|| ( F_35 ( V_63 ) == V_67 )
|| ( F_35 ( V_63 ) == V_68 )
|| ( F_35 ( V_63 ) == V_69 ) )
V_37 = 1 ;
else
V_37 = 2 ;
}
return V_37 ;
}
static int F_36 ( struct V_35 * V_36 , T_1 clock ,
T_1 V_37 , T_1 * V_16 )
{
const struct V_38 * div = NULL ;
T_1 V_41 ;
int V_42 ;
if ( clock == V_43 ) {
* V_16 = F_37 () / V_37 / ( 16 * 3072 ) ;
return - V_44 ;
}
if ( F_38 ( V_36 , L_12 ) )
V_37 = F_27 () ? 3 : 2 ;
if ( ! V_37 )
V_37 = F_33 () ;
V_41 = F_37 () / clock / V_37 ;
F_39 ( L_13 ,
F_37 () , clock , V_41 ) ;
for ( V_42 = 0 ; V_42 < F_17 ( V_70 ) ; V_42 ++ ) {
div = & V_70 [ V_42 ] ;
if ( div -> V_41 >= V_41 )
break;
}
* V_16 = F_37 () / V_37 / div -> V_41 ;
return div ? ( int ) div -> V_46 : - V_44 ;
}
static void F_40 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_37 )
{
int V_47 , V_46 ;
if ( clock == V_48 ) {
F_11 ( V_2 -> V_27 , L_14 ,
F_4 ( V_2 -> V_4 + V_71 ) ,
F_4 ( V_2 -> V_4 + V_49 ) ) ;
return;
}
V_47 = F_36 ( V_36 , clock , V_37 , & V_2 -> V_16 ) ;
V_46 = ( V_47 >= 0 ) ? V_47 : 0x1031 ;
F_2 ( V_46 & 0xff , V_2 -> V_4 + V_49 ) ;
F_2 ( ( V_46 >> 8 ) & 0xff , V_2 -> V_4 + V_71 ) ;
if ( V_47 >= 0 )
F_19 ( V_2 -> V_27 , L_15 ,
V_2 -> V_16 , V_46 >> 8 , V_46 & 0xff ) ;
}
static void F_40 ( struct V_35 * V_36 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_37 )
{
}
static void F_41 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
F_1 ( V_2 , V_19 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_19 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_72 ,
const T_4 * V_73 , int V_74 , int V_75 )
{
int V_42 , V_26 ;
unsigned V_21 = V_2 -> V_76 . V_21 ;
T_1 V_77 = V_75 ? V_78 : 0 ;
F_1 ( V_2 , V_79 | V_19 | V_17 | V_18 | V_77 ) ;
F_2 ( ( V_72 << 1 ) , V_2 -> V_4 + V_20 ) ;
V_26 = F_8 ( V_2 , V_21 , 1 ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_42 = 0 ; V_42 < V_74 ; V_42 ++ ) {
F_2 ( V_73 [ V_42 ] , V_2 -> V_4 + V_20 ) ;
V_26 = F_8 ( V_2 , V_21 , 1 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_72 ,
T_4 * V_73 , int V_74 , int V_75 , bool V_80 )
{
unsigned V_21 = V_2 -> V_76 . V_21 ;
int V_42 , V_26 ;
T_1 V_77 = V_75 ? V_78 : 0 ;
F_1 ( V_2 , V_79 | V_19 | V_17 | V_18 | V_77 ) ;
F_2 ( ( V_72 << 1 ) | 1 , V_2 -> V_4 + V_20 ) ;
V_26 = F_8 ( V_2 , V_21 , 1 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_74 ) {
if ( V_74 == 1 && ! V_80 )
F_1 ( V_2 , V_79 | V_19 | V_17 | V_81 ) ;
else
F_1 ( V_2 , V_79 | V_19 | V_17 ) ;
F_4 ( V_2 -> V_4 + V_20 ) ;
}
for ( V_42 = 0 ; V_42 < V_74 ; V_42 ++ ) {
T_4 V_82 ;
V_26 = F_8 ( V_2 , V_21 , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_42 || ! V_80 ) {
if ( V_42 == V_74 - 2 )
F_1 ( V_2 , V_79 | V_19 | V_17
| V_81 ) ;
if ( V_42 == V_74 - 1 )
F_1 ( V_2 , V_79 | V_19 | V_17
| V_18 ) ;
}
V_82 = F_4 ( V_2 -> V_4 + V_20 ) ;
if ( V_42 == 0 && V_80 ) {
if ( V_82 == 0 || V_82 > V_83 )
return - V_84 ;
V_74 += V_82 ;
if ( V_74 == 2 )
F_1 ( V_2 , V_79 | V_19 | V_17
| V_81 ) ;
}
V_73 [ V_42 ] = V_82 ;
}
return V_74 ;
}
static int F_45 ( struct V_85 * V_76 , struct V_86 * V_87 , int V_88 )
{
struct V_86 * V_89 ;
int V_42 ;
int V_47 = 0 ;
unsigned long V_23 = V_24 ;
struct V_1 * V_2 = F_46 ( V_76 ) ;
F_41 ( V_2 ) ;
while ( F_4 ( V_2 -> V_4 + V_8 ) & V_90 ) {
if ( F_47 ( V_91 ) ) {
F_11 ( V_2 -> V_27 , L_16 ) ;
F_1 ( V_2 , 0 ) ;
return - V_92 ;
}
if ( F_10 ( V_24 , V_23 + V_93 ) ) {
T_4 V_94 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_11 ( V_2 -> V_27 , L_1 ) ;
if ( ( V_94 & ( V_29 | V_90 | V_33 ) ) != 0 ) {
F_2 ( V_94 & ~ V_31 ,
V_2 -> V_4 + V_8 ) ;
F_6 ( V_2 ) ;
}
return - V_30 ;
}
F_9 () ;
}
for ( V_42 = 0 ; V_47 >= 0 && V_42 < V_88 ; V_42 ++ ) {
V_89 = & V_87 [ V_42 ] ;
F_11 ( V_2 -> V_27 ,
L_17 ,
V_89 -> V_77 & V_95 ? L_18 : L_19 ,
V_89 -> V_96 , V_89 -> V_97 , V_42 + 1 , V_88 ) ;
if ( V_89 -> V_77 & V_95 ) {
bool V_80 = V_89 -> V_77 & V_98 ;
V_47 = F_44 ( V_2 , V_89 -> V_97 , V_89 -> V_99 , V_89 -> V_96 , V_42 ,
V_80 ) ;
if ( V_80 && V_47 > 0 )
V_89 -> V_96 = V_47 ;
} else {
V_47 =
F_43 ( V_2 , V_89 -> V_97 , V_89 -> V_99 , V_89 -> V_96 , V_42 ) ;
}
}
F_42 ( V_2 ) ;
V_23 = V_24 ;
while ( F_4 ( V_2 -> V_4 + V_8 ) & V_90 ) {
if ( F_10 ( V_24 , V_23 + V_93 ) ) {
T_4 V_94 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_11 ( V_2 -> V_27 , L_1 ) ;
if ( ( V_94 & ( V_29 | V_90 | V_33 ) ) != 0 ) {
F_2 ( V_94 & ~ V_31 ,
V_2 -> V_4 + V_8 ) ;
F_6 ( V_2 ) ;
}
return - V_30 ;
}
F_48 () ;
}
return ( V_47 < 0 ) ? V_47 : V_88 ;
}
static T_1 F_49 ( struct V_85 * V_76 )
{
return V_100 | V_101
| V_102 | V_103 ;
}
static int F_50 ( struct V_104 * V_105 )
{
const struct V_106 * V_107 ;
struct V_1 * V_2 ;
const T_1 * V_56 ;
T_1 clock = V_43 ;
int V_26 = 0 ;
int V_108 ;
struct V_109 V_110 ;
struct V_111 * V_111 ;
int V_112 ;
V_107 = F_51 ( V_113 , & V_105 -> V_27 ) ;
if ( ! V_107 )
return - V_44 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_114 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_27 = & V_105 -> V_27 ;
F_53 ( & V_2 -> V_11 ) ;
V_2 -> V_4 = F_22 ( V_105 -> V_27 . V_116 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_54 ( V_2 -> V_27 , L_20 ) ;
V_26 = - V_115 ;
goto V_117;
}
V_2 -> V_6 = F_55 ( V_105 -> V_27 . V_116 , 0 ) ;
if ( V_2 -> V_6 ) {
V_26 = F_56 ( V_2 -> V_6 , F_3 ,
V_118 , L_21 , V_2 ) ;
if ( V_26 < 0 ) {
F_54 ( V_2 -> V_27 , L_22 ) ;
goto V_119;
}
}
V_111 = F_57 ( & V_105 -> V_27 , NULL ) ;
if ( ! F_58 ( V_111 ) ) {
V_112 = F_59 ( V_111 ) ;
if ( V_112 ) {
F_54 ( & V_105 -> V_27 , L_23 ) ;
goto V_119;
} else {
V_2 -> V_120 = V_111 ;
}
}
if ( F_23 ( V_105 -> V_27 . V_116 , L_24 , NULL ) ) {
clock = V_48 ;
} else {
V_56 = F_23 ( V_105 -> V_27 . V_116 , L_25 ,
& V_108 ) ;
if ( V_56 && V_108 == sizeof( T_1 ) )
clock = * V_56 ;
}
if ( V_107 -> V_73 ) {
const struct V_121 * V_73 = V_107 -> V_73 ;
V_73 -> V_122 ( V_105 -> V_27 . V_116 , V_2 , clock , V_73 -> V_37 ) ;
} else {
if ( F_23 ( V_105 -> V_27 . V_116 , L_26 , NULL ) )
F_40 ( V_105 -> V_27 . V_116 , V_2 , clock , 0 ) ;
}
V_56 = F_23 ( V_105 -> V_27 . V_116 , L_27 , & V_108 ) ;
if ( V_56 && V_108 == sizeof( T_1 ) ) {
V_123 . V_21 = * V_56 * V_93 / 1000000 ;
if ( V_123 . V_21 < 5 )
V_123 . V_21 = 5 ;
}
F_19 ( V_2 -> V_27 , L_28 , V_123 . V_21 * 1000000 / V_93 ) ;
F_60 ( V_105 , V_2 ) ;
V_2 -> V_76 = V_123 ;
F_61 ( V_105 -> V_27 . V_116 , 0 , & V_110 ) ;
F_62 ( V_2 -> V_76 . V_124 , sizeof( V_2 -> V_76 . V_124 ) ,
L_29 , ( unsigned long long ) V_110 . V_125 ) ;
F_63 ( & V_2 -> V_76 , V_2 ) ;
V_2 -> V_76 . V_27 . V_126 = & V_105 -> V_27 ;
V_2 -> V_76 . V_27 . V_116 = F_64 ( V_105 -> V_27 . V_116 ) ;
V_26 = F_65 ( & V_2 -> V_76 ) ;
if ( V_26 < 0 ) {
F_54 ( V_2 -> V_27 , L_30 ) ;
goto V_127;
}
return V_26 ;
V_127:
if ( V_2 -> V_120 )
F_66 ( V_2 -> V_120 ) ;
F_67 ( V_2 -> V_6 , V_2 ) ;
V_119:
F_68 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_4 ) ;
V_117:
F_69 ( V_2 ) ;
return V_26 ;
}
static int F_70 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_71 ( V_105 ) ;
F_72 ( & V_2 -> V_76 ) ;
if ( V_2 -> V_120 )
F_66 ( V_2 -> V_120 ) ;
if ( V_2 -> V_6 )
F_67 ( V_2 -> V_6 , V_2 ) ;
F_68 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_4 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_128 * V_27 )
{
struct V_1 * V_2 = F_74 ( V_27 ) ;
V_2 -> V_46 = F_4 ( V_2 -> V_4 + V_49 ) ;
V_2 -> V_129 = F_4 ( V_2 -> V_4 + V_71 ) ;
return 0 ;
}
static int F_75 ( struct V_128 * V_27 )
{
struct V_1 * V_2 = F_74 ( V_27 ) ;
F_2 ( V_2 -> V_46 , V_2 -> V_4 + V_49 ) ;
F_2 ( V_2 -> V_129 , V_2 -> V_4 + V_71 ) ;
return 0 ;
}
