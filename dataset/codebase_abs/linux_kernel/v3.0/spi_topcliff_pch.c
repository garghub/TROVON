static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 , ( V_6 -> V_7 + V_3 ) ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 -> V_7 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_3 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_10 = F_4 ( V_2 , V_3 ) ;
V_10 = ( V_10 & ~ V_9 ) | V_8 ;
F_1 ( V_2 , V_3 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_11 , V_12 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_11 , V_13 , 0 ) ;
F_6 ( V_2 , V_11 , 0 , V_13 ) ;
}
static void F_9 ( struct V_5 * V_6 , T_1 V_14 ,
void T_2 * V_7 )
{
T_1 V_15 , V_16 , V_17 , V_18 ;
T_3 * V_19 , * V_20 ;
int V_21 ;
T_1 V_22 ;
void T_2 * V_23 ;
void T_2 * V_24 ;
void T_2 * V_25 ;
V_23 = V_7 + V_26 ;
F_3 ( V_14 , V_23 ) ;
if ( V_6 -> V_27 ) {
V_17 = V_6 -> V_17 ;
V_16 = V_6 -> V_16 ;
V_18 = V_6 -> V_18 ;
V_19 = V_6 -> V_28 ;
V_20 = V_6 -> V_20 ;
V_24 = V_7 + V_29 ;
V_25 = V_7 + V_30 ;
V_15 = F_10 ( V_14 ) ;
for ( V_21 = 0 ; ( V_21 < V_15 ) ; V_21 ++ ) {
V_19 [ V_17 ++ ] = F_5 ( V_24 ) ;
if ( V_16 < V_18 )
F_3 ( V_20 [ V_16 ++ ] , V_25 ) ;
}
if ( ( V_18 - V_17 ) <= V_31 ) {
V_22 = F_5 ( V_7 + V_11 ) ;
V_22 &= ~ V_32 ;
V_22 &= V_33 ;
V_22 |= ( V_34 << V_35 ) ;
F_3 ( ( ( V_22 ) &= ( ~ ( V_32 ) ) ) ,
( V_7 + V_11 ) ) ;
}
V_6 -> V_16 = V_16 ;
V_6 -> V_17 = V_17 ;
}
if ( V_14 & V_36 ) {
F_6 ( V_6 -> V_2 , V_11 , 0 ,
V_37 | V_32 ) ;
V_6 -> V_38 = true ;
F_11 ( & V_6 -> V_39 ) ;
}
}
static T_4 F_12 ( int V_40 , void * V_41 )
{
T_1 V_14 ;
struct V_5 * V_6 ;
void T_2 * V_23 ;
void T_2 * V_7 ;
T_4 V_42 = V_43 ;
struct V_44 * V_45 = V_41 ;
if ( V_45 -> V_46 ) {
F_13 ( & V_45 -> V_47 -> V_48 ,
L_1 , V_49 ) ;
return V_43 ;
}
V_6 = V_45 -> V_6 ;
V_7 = V_6 -> V_7 ;
V_23 = V_7 + V_26 ;
V_14 = F_5 ( V_23 ) ;
if ( V_14 & ( V_36 | V_50 ) ) {
F_9 ( V_6 , V_14 , V_7 ) ;
V_42 = V_51 ;
}
F_13 ( & V_45 -> V_47 -> V_48 , L_2 ,
V_49 , V_42 ) ;
return V_42 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_52 )
{
T_1 V_53 = V_54 / ( V_52 * 2 ) ;
if ( V_53 > V_55 )
V_53 = V_55 ;
F_6 ( V_2 , V_56 , V_53 , ~ V_57 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_5 V_58 )
{
if ( V_58 == 8 )
F_6 ( V_2 , V_56 , 0 , V_59 ) ;
else
F_6 ( V_2 , V_56 , V_59 , 0 ) ;
}
static void F_16 ( struct V_60 * V_61 )
{
T_1 V_62 = 0 ;
F_13 ( & V_61 -> V_48 , L_3 ,
V_49 , F_4 ( V_61 -> V_2 , V_56 ) ,
V_61 -> V_63 ) ;
F_14 ( V_61 -> V_2 , V_61 -> V_63 ) ;
F_15 ( V_61 -> V_2 , V_61 -> V_58 ) ;
if ( ! ( V_61 -> V_64 & V_65 ) )
V_62 |= V_66 ;
if ( V_61 -> V_64 & V_67 )
V_62 |= V_68 ;
if ( V_61 -> V_64 & V_69 )
V_62 |= V_70 ;
F_6 ( V_61 -> V_2 , V_11 , V_62 ,
( V_66 | V_68 | V_70 ) ) ;
F_8 ( V_61 -> V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_71 , 0x1 ) ;
F_1 ( V_2 , V_71 , 0x0 ) ;
}
static int F_18 ( struct V_60 * V_72 )
{
if ( V_72 -> V_58 == 0 ) {
V_72 -> V_58 = 8 ;
F_13 ( & V_72 -> V_48 , L_4 , V_49 ) ;
}
if ( ( V_72 -> V_58 != 8 ) && ( V_72 -> V_58 != 16 ) ) {
F_19 ( & V_72 -> V_48 , L_5 , V_49 ) ;
return - V_73 ;
}
if ( ( V_72 -> V_63 ) > V_74 )
V_72 -> V_63 = V_74 ;
F_13 ( & V_72 -> V_48 , L_6 , V_49 ,
( V_72 -> V_64 ) & ( V_67 | V_69 ) ) ;
return 0 ;
}
static int F_20 ( struct V_60 * V_72 , struct V_75 * V_76 )
{
struct V_77 * V_78 ;
struct V_5 * V_6 = F_2 ( V_72 -> V_2 ) ;
int V_79 ;
unsigned long V_62 ;
if ( F_21 ( F_22 ( & V_76 -> V_80 ) == 1 ) ) {
F_19 ( & V_72 -> V_48 , L_7 , V_49 ) ;
V_79 = - V_73 ;
goto V_81;
}
if ( F_21 ( V_72 -> V_63 == 0 ) ) {
F_19 ( & V_72 -> V_48 , L_8 ,
V_49 , V_72 -> V_63 ) ;
V_79 = - V_73 ;
goto V_81;
}
F_13 ( & V_72 -> V_48 , L_9
L_10 , V_49 ) ;
F_23 (transfer, &pmsg->transfers, transfer_list) {
if ( ! V_78 -> V_82 && ! V_78 -> V_83 ) {
F_19 ( & V_72 -> V_48 ,
L_11 , V_49 ) ;
V_79 = - V_73 ;
goto V_81;
}
if ( ! V_78 -> V_84 ) {
F_19 ( & V_72 -> V_48 , L_12 ,
V_49 ) ;
V_79 = - V_73 ;
goto V_81;
}
F_13 ( & V_72 -> V_48 , L_13
L_14 , V_49 ) ;
if ( V_78 -> V_52 > V_74 )
V_78 -> V_52 = V_74 ;
if ( V_78 -> V_58 ) {
if ( ( V_78 -> V_58 != 8 )
&& ( V_78 -> V_58 != 16 ) ) {
V_79 = - V_73 ;
F_19 ( & V_72 -> V_48 ,
L_5 , V_49 ) ;
goto V_81;
}
}
}
F_24 ( & V_6 -> V_85 , V_62 ) ;
if ( V_6 -> V_86 == V_87 ) {
F_19 ( & V_72 -> V_48 , L_15 , V_49 ) ;
V_79 = - V_88 ;
goto V_89;
}
if ( V_6 -> V_45 -> V_46 ) {
F_19 ( & V_72 -> V_48 , L_16 , V_49 ) ;
V_79 = - V_73 ;
goto V_89;
}
V_76 -> V_90 = 0 ;
F_13 ( & V_72 -> V_48 , L_17 , V_49 , V_76 -> V_86 ) ;
V_76 -> V_86 = - V_91 ;
F_25 ( & V_76 -> V_92 , & V_6 -> V_92 ) ;
F_13 ( & V_72 -> V_48 , L_18 , V_49 ) ;
F_26 ( V_6 -> V_93 , & V_6 -> V_94 ) ;
F_13 ( & V_72 -> V_48 , L_19 , V_49 ) ;
V_79 = 0 ;
V_89:
F_27 ( & V_6 -> V_85 , V_62 ) ;
V_81:
F_13 ( & V_72 -> V_48 , L_20 , V_49 , V_79 ) ;
return V_79 ;
}
static inline void F_28 ( struct V_5 * V_6 ,
struct V_60 * V_72 )
{
if ( V_6 -> V_95 != NULL ) {
if ( V_72 -> V_96 != V_6 -> V_97 ) {
F_13 ( & V_72 -> V_48 , L_21 , V_49 ) ;
V_6 -> V_95 = NULL ;
}
}
V_6 -> V_95 = V_72 ;
V_6 -> V_97 = V_6 -> V_95 -> V_96 ;
F_13 ( & V_72 -> V_48 , L_22 , V_49 ) ;
F_16 ( V_72 ) ;
}
static void F_29 ( struct V_5 * V_6 , int * V_98 ,
struct V_75 * * V_99 )
{
int V_100 ;
T_1 V_101 ;
int V_102 ;
struct V_75 * V_76 ;
const T_5 * V_82 ;
const T_3 * V_103 ;
V_76 = * V_99 ;
if ( V_6 -> V_104 -> V_52 ) {
F_13 ( & V_6 -> V_2 -> V_48 , L_23 , V_49 ) ;
F_14 ( V_6 -> V_2 , V_6 -> V_104 -> V_52 ) ;
}
if ( V_6 -> V_104 -> V_58 &&
( V_6 -> V_105 -> V_61 -> V_58 != V_6 -> V_104 -> V_58 ) ) {
F_13 ( & V_6 -> V_2 -> V_48 , L_24 , V_49 ) ;
F_15 ( V_6 -> V_2 ,
V_6 -> V_104 -> V_58 ) ;
* V_98 = V_6 -> V_104 -> V_58 ;
} else {
* V_98 = V_6 -> V_105 -> V_61 -> V_58 ;
}
V_6 -> V_16 = 0 ;
V_6 -> V_17 = 0 ;
V_6 -> V_18 = V_6 -> V_104 -> V_84 / ( * V_98 / 8 ) ;
V_100 = V_6 -> V_104 -> V_84 * sizeof( * V_6 -> V_20 ) ;
V_6 -> V_20 = F_30 ( V_100 , V_106 ) ;
if ( V_6 -> V_20 != NULL ) {
V_6 -> V_28 = F_30 ( V_100 , V_106 ) ;
if ( ! V_6 -> V_28 )
F_31 ( V_6 -> V_20 ) ;
}
if ( ! V_6 -> V_28 ) {
F_19 ( & V_6 -> V_2 -> V_48 , L_25 , V_49 ) ;
F_23 (pmsg, data->queue.next, queue) {
V_76 -> V_86 = - V_107 ;
if ( V_76 -> V_108 != 0 )
V_76 -> V_108 ( V_76 -> V_109 ) ;
F_32 ( & V_76 -> V_92 ) ;
}
return;
}
if ( V_6 -> V_104 -> V_82 != NULL ) {
if ( * V_98 == 8 ) {
V_82 = V_6 -> V_104 -> V_82 ;
for ( V_102 = 0 ; V_102 < V_6 -> V_18 ; V_102 ++ )
V_6 -> V_20 [ V_102 ] = * V_82 ++ ;
} else {
V_103 = V_6 -> V_104 -> V_82 ;
for ( V_102 = 0 ; V_102 < V_6 -> V_18 ; V_102 ++ )
V_6 -> V_20 [ V_102 ] = * V_103 ++ ;
}
}
V_101 = V_6 -> V_18 ;
if ( V_101 > V_31 )
V_101 = V_31 ;
F_13 ( & V_6 -> V_2 -> V_48 , L_26
L_27 , V_49 ) ;
F_1 ( V_6 -> V_2 , V_110 , V_111 ) ;
for ( V_102 = 0 ; V_102 < V_101 ; V_102 ++ )
F_1 ( V_6 -> V_2 , V_30 , V_6 -> V_20 [ V_102 ] ) ;
V_6 -> V_16 = V_102 ;
V_6 -> V_38 = false ;
V_6 -> V_27 = true ;
}
static void F_33 ( struct V_5 * V_6 ,
struct V_75 * V_76 )
{
F_13 ( & V_6 -> V_2 -> V_48 , L_28 , V_49 ) ;
V_6 -> V_105 -> V_86 = 0 ;
if ( V_6 -> V_105 -> V_108 != 0 ) {
F_13 ( & V_6 -> V_2 -> V_48 ,
L_29 , V_49 ) ;
V_6 -> V_105 -> V_108 ( V_6 -> V_105 -> V_109 ) ;
}
V_6 -> V_112 = false ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_30 , V_49 ) ;
V_6 -> V_105 = NULL ;
V_6 -> V_104 = NULL ;
if ( ( F_22 ( & V_6 -> V_92 ) == 0 ) &&
( ! V_6 -> V_45 -> V_46 ) &&
( V_6 -> V_86 != V_87 ) ) {
F_13 ( & V_6 -> V_2 -> V_48 , L_31 , V_49 ) ;
F_26 ( V_6 -> V_93 , & V_6 -> V_94 ) ;
} else if ( V_6 -> V_45 -> V_46 ||
V_6 -> V_86 == V_87 ) {
F_13 ( & V_6 -> V_2 -> V_48 ,
L_32 ,
V_49 ) ;
F_23 (pmsg, data->queue.next, queue) {
V_76 -> V_86 = - V_113 ;
if ( V_76 -> V_108 )
V_76 -> V_108 ( V_76 -> V_109 ) ;
F_32 ( & V_76 -> V_92 ) ;
}
}
}
static void F_34 ( struct V_5 * V_6 )
{
if ( ( V_6 -> V_18 ) > V_31 ) {
F_6 ( V_6 -> V_2 , V_11 ,
V_114 << V_35 ,
~ V_33 ) ;
F_6 ( V_6 -> V_2 , V_11 ,
V_32 | V_37 , 0 ) ;
} else {
F_6 ( V_6 -> V_2 , V_11 ,
V_34 << V_115 ,
~ V_116 ) ;
F_6 ( V_6 -> V_2 , V_11 , V_37 , 0 ) ;
}
F_13 ( & V_6 -> V_2 -> V_48 ,
L_33 , V_49 ) ;
F_6 ( V_6 -> V_95 -> V_2 , V_11 , V_117 , 0 ) ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_34 , V_49 ) ;
F_35 ( V_6 -> V_39 , V_6 -> V_38 ) ;
F_1 ( V_6 -> V_2 , V_110 , V_118 ) ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_35 , V_49 ) ;
V_6 -> V_27 = false ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_36 , V_49 ) ;
F_1 ( V_6 -> V_2 , V_26 ,
F_4 ( V_6 -> V_2 , V_26 ) ) ;
F_6 ( V_6 -> V_2 , V_11 , 0 , V_119 ) ;
}
static void F_36 ( struct V_5 * V_6 , int V_98 )
{
int V_102 ;
T_5 * V_83 ;
T_3 * V_120 ;
if ( ! V_6 -> V_104 -> V_83 )
return;
if ( V_98 == 8 ) {
V_83 = V_6 -> V_104 -> V_83 ;
for ( V_102 = 0 ; V_102 < V_6 -> V_18 ; V_102 ++ )
* V_83 ++ = V_6 -> V_28 [ V_102 ] & 0xFF ;
} else {
V_120 = V_6 -> V_104 -> V_83 ;
for ( V_102 = 0 ; V_102 < V_6 -> V_18 ; V_102 ++ )
* V_120 ++ = V_6 -> V_28 [ V_102 ] ;
}
}
static void F_37 ( struct V_121 * V_122 )
{
struct V_75 * V_76 ;
struct V_5 * V_6 ;
int V_98 ;
V_6 = F_38 ( V_122 , struct V_5 , V_94 ) ;
F_13 ( & V_6 -> V_2 -> V_48 , L_37 , V_49 ) ;
F_39 ( & V_6 -> V_85 ) ;
if ( V_6 -> V_45 -> V_46 || ( V_6 -> V_86 == V_87 ) ) {
F_13 ( & V_6 -> V_2 -> V_48 ,
L_38 ,
V_49 ) ;
F_23 (pmsg, data->queue.next, queue) {
V_76 -> V_86 = - V_113 ;
if ( V_76 -> V_108 != 0 ) {
F_40 ( & V_6 -> V_85 ) ;
V_76 -> V_108 ( V_76 -> V_109 ) ;
F_39 ( & V_6 -> V_85 ) ;
}
F_32 ( & V_76 -> V_92 ) ;
}
F_40 ( & V_6 -> V_85 ) ;
return;
}
V_6 -> V_112 = true ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_39 , V_49 ) ;
V_6 -> V_105 = F_41 ( V_6 -> V_92 . V_123 , struct V_75 ,
V_92 ) ;
F_32 ( & V_6 -> V_105 -> V_92 ) ;
V_6 -> V_105 -> V_86 = 0 ;
F_28 ( V_6 , V_6 -> V_105 -> V_61 ) ;
F_40 ( & V_6 -> V_85 ) ;
do {
F_39 ( & V_6 -> V_85 ) ;
if ( V_6 -> V_104 == NULL ) {
V_6 -> V_104 =
F_41 ( V_6 -> V_105 -> V_80 .
V_123 , struct V_77 ,
V_124 ) ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_40 , V_49 ) ;
} else {
V_6 -> V_104 =
F_41 ( V_6 -> V_104 -> V_124 . V_123 ,
struct V_77 ,
V_124 ) ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_41 ,
V_49 ) ;
}
F_40 ( & V_6 -> V_85 ) ;
F_29 ( V_6 , & V_98 , & V_76 ) ;
F_34 ( V_6 ) ;
F_6 ( V_6 -> V_95 -> V_2 , V_11 , 0 ,
V_117 ) ;
F_8 ( V_6 -> V_2 ) ;
F_36 ( V_6 , V_98 ) ;
F_31 ( V_6 -> V_28 ) ;
V_6 -> V_28 = NULL ;
F_31 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
V_6 -> V_105 -> V_90 += V_6 -> V_104 -> V_84 ;
F_13 ( & V_6 -> V_2 -> V_48 ,
L_42 ,
V_49 , V_6 -> V_105 -> V_90 ) ;
if ( V_6 -> V_104 -> V_125 ) {
F_13 ( & V_6 -> V_2 -> V_48 , L_43
L_44 , V_49 ,
V_6 -> V_104 -> V_125 ) ;
F_42 ( V_6 -> V_104 -> V_125 ) ;
}
F_39 ( & V_6 -> V_85 ) ;
if ( ( V_6 -> V_104 -> V_124 . V_123 ) ==
& ( V_6 -> V_105 -> V_80 ) ) {
F_33 ( V_6 , V_76 ) ;
}
F_40 ( & V_6 -> V_85 ) ;
} while ( V_6 -> V_104 != NULL );
}
static void F_43 ( struct V_44 * V_45 )
{
F_13 ( & V_45 -> V_47 -> V_48 , L_45 , V_49 ) ;
if ( V_45 -> V_6 -> V_93 != NULL ) {
F_44 ( V_45 -> V_6 -> V_93 ) ;
V_45 -> V_6 -> V_93 = NULL ;
F_13 ( & V_45 -> V_47 -> V_48 ,
L_46 ,
V_49 ) ;
}
if ( V_45 -> V_126 ) {
F_6 ( V_45 -> V_6 -> V_2 , V_11 , 0 ,
V_119 ) ;
F_45 ( V_45 -> V_47 -> V_40 , V_45 ) ;
F_13 ( & V_45 -> V_47 -> V_48 ,
L_47 , V_49 ) ;
V_45 -> V_126 = false ;
}
if ( V_45 -> V_6 -> V_7 != 0 ) {
F_46 ( V_45 -> V_47 , V_45 -> V_6 -> V_7 ) ;
V_45 -> V_6 -> V_7 = 0 ;
F_13 ( & V_45 -> V_47 -> V_48 ,
L_48 , V_49 ) ;
}
if ( V_45 -> V_127 ) {
F_47 ( V_45 -> V_47 ) ;
F_13 ( & V_45 -> V_47 -> V_48 ,
L_49 ,
V_49 ) ;
V_45 -> V_127 = false ;
}
}
static int F_48 ( struct V_44 * V_45 )
{
void T_2 * V_7 ;
int V_79 ;
F_13 ( & V_45 -> V_47 -> V_48 , L_45 , V_49 ) ;
V_45 -> V_6 -> V_93 = F_49 ( V_128 ) ;
if ( ! V_45 -> V_6 -> V_93 ) {
F_19 ( & V_45 -> V_47 -> V_48 ,
L_50 , V_49 ) ;
V_79 = - V_129 ;
goto V_130;
}
F_13 ( & V_45 -> V_47 -> V_48 ,
L_51 , V_49 ) ;
V_79 = F_50 ( V_45 -> V_47 , V_128 ) ;
if ( V_79 != 0 ) {
F_19 ( & V_45 -> V_47 -> V_48 ,
L_52 , V_49 ) ;
goto V_130;
}
V_45 -> V_127 = true ;
V_7 = F_51 ( V_45 -> V_47 , 1 , 0 ) ;
if ( V_7 == 0 ) {
F_19 ( & V_45 -> V_47 -> V_48 ,
L_53 , V_49 ) ;
V_79 = - V_107 ;
goto V_130;
}
V_45 -> V_6 -> V_7 = V_7 ;
F_17 ( V_45 -> V_6 -> V_2 ) ;
F_13 ( & V_45 -> V_47 -> V_48 ,
L_54 , V_49 ) ;
V_79 = F_52 ( V_45 -> V_47 -> V_40 , F_12 ,
V_131 , V_128 , V_45 ) ;
if ( V_79 != 0 ) {
F_19 ( & V_45 -> V_47 -> V_48 ,
L_55 , V_49 ) ;
goto V_130;
}
F_13 ( & V_45 -> V_47 -> V_48 , L_56 ,
V_49 , V_79 ) ;
V_45 -> V_126 = true ;
F_13 ( & V_45 -> V_47 -> V_48 , L_57 , V_49 ) ;
V_130:
if ( V_79 != 0 ) {
F_19 ( & V_45 -> V_47 -> V_48 ,
L_58 , V_49 ) ;
F_43 ( V_45 ) ;
}
F_13 ( & V_45 -> V_47 -> V_48 , L_59 , V_49 , V_79 ) ;
return V_79 ;
}
static int F_53 ( struct V_132 * V_47 , const struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_79 ;
F_13 ( & V_47 -> V_48 , L_45 , V_49 ) ;
V_45 = F_30 ( sizeof( struct V_44 ) , V_106 ) ;
if ( V_45 == NULL ) {
F_19 ( & V_47 -> V_48 ,
L_60 ,
V_49 ) ;
V_79 = - V_107 ;
goto V_135;
}
F_13 ( & V_47 -> V_48 ,
L_61 , V_49 ) ;
V_79 = F_54 ( V_47 ) ;
if ( V_79 != 0 ) {
F_19 ( & V_47 -> V_48 , L_62 , V_49 ) ;
goto V_136;
}
F_13 ( & V_47 -> V_48 , L_63 ,
V_49 , V_79 ) ;
V_45 -> V_47 = V_47 ;
V_2 = F_55 ( & V_47 -> V_48 , sizeof( struct V_5 ) ) ;
if ( V_2 == NULL ) {
V_79 = - V_107 ;
F_19 ( & V_47 -> V_48 , L_64 , V_49 ) ;
goto V_137;
}
F_13 ( & V_47 -> V_48 ,
L_65 , V_49 ) ;
V_2 -> V_138 = - 1 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_141 = F_18 ;
V_2 -> V_78 = F_20 ;
F_13 ( & V_47 -> V_48 ,
L_66 , V_49 ) ;
V_45 -> V_6 = F_2 ( V_2 ) ;
V_45 -> V_6 -> V_2 = V_2 ;
V_45 -> V_6 -> V_97 = 255 ;
V_45 -> V_6 -> V_45 = V_45 ;
V_45 -> V_6 -> V_86 = V_142 ;
F_56 ( & V_45 -> V_6 -> V_92 ) ;
F_57 ( & V_45 -> V_6 -> V_85 ) ;
F_58 ( & V_45 -> V_6 -> V_94 , F_37 ) ;
F_59 ( & V_45 -> V_6 -> V_39 ) ;
V_79 = F_48 ( V_45 ) ;
if ( V_79 ) {
F_19 ( & V_47 -> V_48 , L_67 , V_49 , V_79 ) ;
goto V_143;
}
F_13 ( & V_47 -> V_48 , L_68 ,
V_49 , V_79 ) ;
F_60 ( V_47 , V_45 ) ;
F_13 ( & V_47 -> V_48 , L_69 , V_49 ) ;
F_7 ( V_2 ) ;
F_13 ( & V_47 -> V_48 ,
L_70 , V_49 ) ;
V_79 = F_61 ( V_2 ) ;
if ( V_79 != 0 ) {
F_19 ( & V_47 -> V_48 ,
L_71 , V_49 ) ;
goto V_144;
}
F_13 ( & V_47 -> V_48 , L_72 ,
V_49 , V_79 ) ;
return 0 ;
V_144:
F_62 ( V_2 ) ;
V_143:
V_137:
F_63 ( V_2 ) ;
F_64 ( V_47 ) ;
V_136:
F_31 ( V_45 ) ;
V_135:
return V_79 ;
}
static void F_65 ( struct V_132 * V_47 )
{
struct V_44 * V_45 = F_66 ( V_47 ) ;
int V_145 ;
F_13 ( & V_47 -> V_48 , L_45 , V_49 ) ;
if ( ! V_45 ) {
F_19 ( & V_47 -> V_48 ,
L_73 , V_49 ) ;
return;
}
V_145 = 500 ;
F_39 ( & V_45 -> V_6 -> V_85 ) ;
V_45 -> V_6 -> V_86 = V_87 ;
while ( ( F_22 ( & V_45 -> V_6 -> V_92 ) == 0 ) && -- V_145 ) {
F_13 ( & V_45 -> V_47 -> V_48 , L_74 ,
V_49 ) ;
F_40 ( & V_45 -> V_6 -> V_85 ) ;
F_67 ( V_146 ) ;
F_39 ( & V_45 -> V_6 -> V_85 ) ;
}
F_40 ( & V_45 -> V_6 -> V_85 ) ;
F_43 ( V_45 ) ;
F_62 ( V_45 -> V_6 -> V_2 ) ;
F_31 ( V_45 ) ;
F_60 ( V_47 , NULL ) ;
F_64 ( V_47 ) ;
F_13 ( & V_47 -> V_48 , L_75 , V_49 ) ;
}
static int F_68 ( struct V_132 * V_47 , T_6 V_147 )
{
T_5 V_145 ;
int V_79 ;
struct V_44 * V_45 = F_66 ( V_47 ) ;
F_13 ( & V_47 -> V_48 , L_45 , V_49 ) ;
if ( ! V_45 ) {
F_19 ( & V_47 -> V_48 ,
L_73 , V_49 ) ;
return - V_148 ;
}
V_79 = 0 ;
V_45 -> V_46 = true ;
V_145 = 255 ;
while ( ( -- V_145 ) > 0 ) {
if ( ! ( V_45 -> V_6 -> V_112 ) ) {
F_13 ( & V_47 -> V_48 , L_76
L_77 , V_49 ) ;
break;
} else {
F_13 ( & V_47 -> V_48 , L_78
L_79 , V_49 ) ;
}
F_67 ( V_146 ) ;
}
if ( V_45 -> V_126 ) {
F_6 ( V_45 -> V_6 -> V_2 , V_11 , 0 ,
V_119 ) ;
F_17 ( V_45 -> V_6 -> V_2 ) ;
F_45 ( V_45 -> V_47 -> V_40 , V_45 ) ;
V_45 -> V_126 = false ;
F_13 ( & V_47 -> V_48 ,
L_80 , V_49 ) ;
}
V_79 = F_69 ( V_47 ) ;
if ( V_79 == 0 ) {
F_13 ( & V_47 -> V_48 , L_81 ,
V_49 , V_79 ) ;
F_70 ( V_47 , V_149 , 0 ) ;
F_13 ( & V_47 -> V_48 ,
L_82 , V_49 ) ;
F_64 ( V_47 ) ;
F_13 ( & V_47 -> V_48 ,
L_83 ,
V_49 ) ;
F_71 ( V_47 , V_149 ) ;
F_13 ( & V_47 -> V_48 ,
L_84 ,
V_49 ) ;
} else {
F_19 ( & V_47 -> V_48 , L_85 , V_49 ) ;
}
F_13 ( & V_47 -> V_48 , L_86 , V_49 , V_79 ) ;
return V_79 ;
}
static int F_72 ( struct V_132 * V_47 )
{
int V_79 ;
struct V_44 * V_150 = F_66 ( V_47 ) ;
F_13 ( & V_47 -> V_48 , L_45 , V_49 ) ;
if ( ! V_150 ) {
F_19 ( & V_47 -> V_48 ,
L_73 , V_49 ) ;
return - V_148 ;
}
F_71 ( V_47 , V_151 ) ;
F_73 ( V_47 ) ;
V_79 = F_54 ( V_47 ) ;
if ( V_79 < 0 ) {
F_19 ( & V_47 -> V_48 ,
L_87 , V_49 ) ;
} else {
F_70 ( V_47 , V_149 , 0 ) ;
if ( ! V_150 -> V_126 ) {
V_79 = F_52 ( V_150 -> V_47 -> V_40 , F_12 ,
V_131 , V_128 ,
V_150 ) ;
if ( V_79 < 0 ) {
F_19 ( & V_47 -> V_48 ,
L_55 , V_49 ) ;
return V_79 ;
}
V_150 -> V_126 = true ;
F_17 ( V_150 -> V_6 -> V_2 ) ;
F_7 ( V_150 -> V_6 -> V_2 ) ;
V_150 -> V_46 = false ;
}
}
F_13 ( & V_47 -> V_48 , L_88 , V_49 , V_79 ) ;
return V_79 ;
}
static int T_7 F_74 ( void )
{
return F_75 ( & V_152 ) ;
}
static void T_8 F_76 ( void )
{
F_77 ( & V_152 ) ;
}
