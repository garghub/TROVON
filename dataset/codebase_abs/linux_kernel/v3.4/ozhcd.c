static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_1 * V_5 , T_1 V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_5 -> V_9 [ V_7 ] . V_6 == V_6 )
return V_7 ;
}
return V_5 -> V_10 ;
}
static struct V_11 * F_3 ( void )
{
struct V_11 * V_12 = 0 ;
unsigned long V_13 ;
F_4 ( & V_14 , V_13 ) ;
if ( V_15 ) {
V_12 = F_5 ( V_15 , struct V_11 , V_16 ) ;
V_15 = V_12 -> V_16 . V_17 ;
-- V_18 ;
}
F_6 ( & V_14 , V_13 ) ;
if ( V_12 == 0 )
V_12 = F_7 ( sizeof( struct V_11 ) , V_19 ) ;
return V_12 ;
}
static void F_8 ( struct V_11 * V_12 )
{
if ( V_12 ) {
unsigned long V_13 ;
F_4 ( & V_14 , V_13 ) ;
if ( V_18 < V_20 ) {
V_12 -> V_16 . V_17 = V_15 ;
V_15 = & V_12 -> V_16 ;
V_12 = 0 ;
V_18 ++ ;
}
F_6 ( & V_14 , V_13 ) ;
if ( V_12 )
F_9 ( V_12 ) ;
}
}
static void F_10 ( void )
{
struct V_21 * V_22 ;
unsigned long V_13 ;
F_4 ( & V_14 , V_13 ) ;
V_22 = V_15 ;
V_15 = 0 ;
V_18 = 0 ;
F_6 ( & V_14 , V_13 ) ;
while ( V_22 ) {
struct V_11 * V_12 =
F_5 ( V_22 , struct V_11 , V_16 ) ;
V_22 = V_22 -> V_17 ;
F_9 ( V_12 ) ;
}
}
static struct V_23 * F_11 ( T_2 V_24 , int V_25 )
{
struct V_23 * V_26 =
F_12 ( sizeof( struct V_23 ) + V_25 , V_24 ) ;
if ( V_26 ) {
F_13 ( & V_26 -> V_27 ) ;
F_13 ( & V_26 -> V_16 ) ;
V_26 -> V_28 = - 1 ;
if ( V_25 ) {
V_26 -> V_25 = V_25 ;
V_26 -> V_29 = ( T_1 * ) ( V_26 + 1 ) ;
}
}
return V_26 ;
}
struct V_11 * F_14 ( struct V_1 * V_5 , struct V_30 * V_30 )
{
struct V_11 * V_12 ;
struct V_21 * V_22 ;
F_15 (e, &ozhcd->urb_cancel_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_30 == V_12 -> V_30 ) {
F_16 ( V_22 ) ;
return V_12 ;
}
}
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , struct V_30 * V_30 ,
int V_31 , unsigned long V_32 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_13 ;
struct V_11 * V_33 = 0 ;
F_4 ( & V_34 , V_13 ) ;
F_18 ( V_3 , V_30 ) ;
V_30 -> V_35 = 0 ;
V_33 = F_14 ( V_5 , V_30 ) ;
F_19 ( & V_34 ) ;
if ( F_20 ( V_30 ) ) {
F_21 ( L_1 , V_30 ) ;
} else {
static unsigned long V_36 ;
F_22 ( & V_37 ) ;
F_23 ( V_38 ,
L_2 ,
V_39 , V_30 , V_31 , V_39 - V_32 ,
V_39 - V_36 , F_24 ( & V_37 ) ) ;
V_36 = V_39 ;
F_25 ( V_40 , 0 , 0 , V_30 , V_31 ) ;
F_26 ( V_3 , V_30 , V_31 ) ;
}
F_27 ( & V_34 ) ;
F_6 ( & V_34 , V_13 ) ;
if ( V_33 )
F_8 ( V_33 ) ;
}
static void F_28 ( struct V_41 * V_42 , struct V_23 * V_26 )
{
F_21 ( L_3 ) ;
if ( V_42 ) {
struct V_21 V_43 ;
struct V_1 * V_5 = V_42 -> V_5 ;
F_13 ( & V_43 ) ;
if ( V_26 -> V_44 & V_45 )
F_29 ( V_42 -> V_46 , V_26 -> V_47 ) ;
F_30 ( & V_5 -> V_48 ) ;
F_31 ( & V_26 -> V_27 , & V_43 ) ;
F_32 ( & V_43 , & V_5 -> V_49 ) ;
F_33 ( & V_5 -> V_48 ) ;
}
F_21 ( L_4 ) ;
F_9 ( V_26 ) ;
}
static int F_34 ( struct V_41 * V_42 , T_1 V_50 , int V_51 ,
struct V_30 * V_30 , T_1 V_52 )
{
struct V_11 * V_12 ;
struct V_23 * V_26 ;
int V_53 = 0 ;
if ( V_50 >= V_54 ) {
F_21 ( L_5 ) ;
return - V_55 ;
}
V_12 = F_3 () ;
if ( ! V_12 )
return - V_56 ;
V_12 -> V_32 = V_39 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_52 = V_52 ;
V_12 -> V_47 = V_50 ;
F_30 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_30 -> V_57 ) {
F_33 ( & V_42 -> V_5 -> V_48 ) ;
F_21 ( L_6 , V_30 ) ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
F_8 ( V_12 ) ;
return 0 ;
}
if ( V_51 )
V_26 = V_42 -> V_58 [ V_50 ] ;
else
V_26 = V_42 -> V_59 [ V_50 ] ;
if ( V_26 && V_42 -> V_46 ) {
F_35 ( & V_12 -> V_16 , & V_26 -> V_27 ) ;
if ( ! V_51 && V_50 && ( V_26 -> V_28 < 0 ) ) {
V_26 -> V_60 = V_39 ;
V_26 -> V_28 = 0 ;
F_25 ( V_61 , V_26 -> V_47 ,
0 , 0 , V_26 -> V_28 ) ;
}
} else {
V_53 = - V_62 ;
}
F_33 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_53 )
F_8 ( V_12 ) ;
return V_53 ;
}
static int F_36 ( struct V_41 * V_42 , T_1 V_50 , int V_51 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 = 0 ;
struct V_23 * V_26 ;
F_30 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_51 )
V_26 = V_42 -> V_58 [ V_50 ] ;
else
V_26 = V_42 -> V_59 [ V_50 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_16 ( V_22 ) ;
break;
}
V_12 = 0 ;
}
}
F_33 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_12 )
F_8 ( V_12 ) ;
return V_12 ? 0 : - V_63 ;
}
static struct V_30 * F_37 ( struct V_41 * V_42 , int V_64 ,
T_1 V_52 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
struct V_30 * V_30 = 0 ;
struct V_11 * V_12 = 0 ;
struct V_23 * V_26 ;
F_30 ( & V_5 -> V_48 ) ;
V_26 = V_42 -> V_59 [ V_64 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_52 == V_52 ) {
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
break;
}
}
}
F_33 ( & V_5 -> V_48 ) ;
if ( V_30 )
F_8 ( V_12 ) ;
return V_30 ;
}
static void F_38 ( struct V_41 * V_42 , void * V_46 )
{
F_13 ( & V_42 -> V_65 ) ;
F_13 ( & V_42 -> V_66 ) ;
V_42 -> V_44 |= V_67 | V_68 ;
V_42 -> V_31 |= V_69 |
( V_70 << 16 ) ;
F_39 ( V_46 ) ;
V_42 -> V_46 = V_46 ;
}
static struct V_1 * F_40 ( void )
{
struct V_1 * V_5 ;
F_30 ( & V_71 ) ;
V_5 = V_72 ;
if ( V_5 )
F_41 ( V_5 -> V_3 ) ;
F_33 ( & V_71 ) ;
return V_5 ;
}
static inline void F_42 ( struct V_1 * V_5 )
{
if ( V_5 )
F_43 ( V_5 -> V_3 ) ;
}
void * F_44 ( void * V_46 )
{
int V_7 ;
void * V_73 = 0 ;
struct V_1 * V_5 = 0 ;
struct V_23 * V_26 ;
F_21 ( L_7 ) ;
V_5 = F_40 () ;
if ( V_5 == 0 )
return 0 ;
V_26 = F_11 ( V_19 , 0 ) ;
F_30 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_10 >= 0 ) {
F_33 ( & V_5 -> V_48 ) ;
F_21 ( L_8 ) ;
goto V_74;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_41 * V_42 = & V_5 -> V_9 [ V_7 ] ;
F_27 ( & V_42 -> V_75 ) ;
if ( ( V_42 -> V_44 & V_67 ) == 0 ) {
F_38 ( V_42 , V_46 ) ;
F_19 ( & V_42 -> V_75 ) ;
break;
}
F_19 ( & V_42 -> V_75 ) ;
}
if ( V_7 < V_8 ) {
F_21 ( L_9 , V_7 ) ;
V_5 -> V_10 = V_7 ;
V_5 -> V_9 [ V_7 ] . V_59 [ 0 ] = V_26 ;
V_26 = 0 ;
V_73 = & V_5 -> V_9 [ V_7 ] ;
F_33 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_44 & V_76 ) {
F_21 ( L_10 ) ;
F_45 ( V_5 -> V_3 ) ;
}
F_46 ( V_5 -> V_3 ) ;
} else {
F_33 ( & V_5 -> V_48 ) ;
}
V_74:
if ( V_26 )
F_28 ( 0 , V_26 ) ;
F_42 ( V_5 ) ;
return V_73 ;
}
void F_47 ( void * V_73 )
{
struct V_41 * V_42 = (struct V_41 * ) V_73 ;
struct V_1 * V_5 ;
void * V_46 ;
struct V_23 * V_26 = 0 ;
F_21 ( L_11 ) ;
if ( V_42 == 0 ) {
F_21 ( L_12 ) ;
return;
}
V_5 = V_42 -> V_5 ;
if ( V_5 == 0 )
return;
F_30 ( & V_5 -> V_48 ) ;
if ( ( V_5 -> V_10 >= 0 ) &&
( V_42 == & V_5 -> V_9 [ V_5 -> V_10 ] ) ) {
F_21 ( L_13 ) ;
V_5 -> V_10 = - 1 ;
}
F_27 ( & V_42 -> V_75 ) ;
V_42 -> V_44 |= V_77 ;
F_19 ( & V_42 -> V_75 ) ;
F_33 ( & V_5 -> V_48 ) ;
F_48 ( V_5 -> V_3 , V_42 ) ;
F_30 ( & V_42 -> V_75 ) ;
V_46 = V_42 -> V_46 ;
V_42 -> V_46 = 0 ;
V_42 -> V_6 = 0xff ;
V_42 -> V_44 &= ~ ( V_67 | V_77 ) ;
V_42 -> V_44 |= V_68 ;
V_42 -> V_31 &= ~ V_69 ;
V_42 -> V_31 |= ( V_70 << 16 ) ;
if ( V_42 -> V_59 [ 0 ] ) {
V_26 = V_42 -> V_59 [ 0 ] ;
V_42 -> V_59 [ 0 ] = 0 ;
}
F_33 ( & V_42 -> V_75 ) ;
if ( V_26 )
F_28 ( V_42 , V_26 ) ;
F_46 ( V_5 -> V_3 ) ;
F_49 ( V_46 ) ;
}
void F_50 ( void * V_46 , void * V_73 )
{
struct V_41 * V_42 = (struct V_41 * ) V_73 ;
struct V_1 * V_5 = V_42 -> V_5 ;
F_21 ( L_14 ) ;
F_30 ( & V_42 -> V_75 ) ;
V_42 -> V_44 |= V_68 ;
V_42 -> V_31 |= V_78 ;
V_42 -> V_31 |= ( V_79 << 16 ) ;
F_33 ( & V_42 -> V_75 ) ;
F_48 ( V_5 -> V_3 , V_42 ) ;
F_46 ( V_5 -> V_3 ) ;
}
void F_51 ( void * V_73 , T_1 V_52 , int V_31 , T_1 * V_80 ,
int V_81 , int V_82 , int V_83 )
{
struct V_41 * V_42 = (struct V_41 * ) V_73 ;
struct V_30 * V_30 ;
int V_53 = 0 ;
F_25 ( V_84 , 0 , V_52 , 0 , V_31 ) ;
F_21 ( L_15 ,
V_81 , V_82 , V_83 ) ;
V_30 = F_37 ( V_42 , 0 , V_52 ) ;
if ( ! V_30 )
return;
if ( V_31 == 0 ) {
int V_85 ;
int V_86 = V_30 -> V_87 ;
if ( V_86 > V_83 )
V_86 = V_83 ;
V_85 = V_86 - V_82 ;
if ( V_81 <= V_85 )
V_85 = V_81 ;
memcpy ( V_30 -> V_88 + V_82 , V_80 , V_85 ) ;
V_82 += V_85 ;
if ( V_82 < V_86 ) {
struct V_89 * V_90 =
(struct V_89 * ) V_30 -> V_91 ;
unsigned V_92 = F_52 ( V_90 -> V_93 ) ;
if ( F_34 ( V_42 , 0 , 0 , V_30 , V_52 ) )
V_53 = - V_56 ;
else if ( F_53 ( V_42 -> V_46 , V_52 ,
V_90 -> V_94 , ( T_1 ) ( V_92 >> 8 ) ,
( T_1 ) V_92 , V_90 -> V_95 , V_82 ,
V_86 - V_82 ) ) {
F_36 ( V_42 , 0 , 0 , V_30 ) ;
V_53 = - V_56 ;
}
if ( V_53 == 0 )
return;
}
}
V_30 -> V_96 = V_83 ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
static void F_54 ( T_1 V_97 )
{
switch ( V_97 ) {
case V_98 :
F_21 ( L_16 ) ;
break;
case V_99 :
F_21 ( L_17 ) ;
break;
case V_100 :
F_21 ( L_18 ) ;
break;
case V_101 :
F_21 ( L_19 ) ;
break;
case V_102 :
F_21 ( L_20 ) ;
break;
case V_103 :
F_21 ( L_21 ) ;
break;
case V_104 :
F_21 ( L_22 ) ;
break;
case V_105 :
F_21 ( L_23 ) ;
break;
case V_106 :
F_21 ( L_24 ) ;
break;
case V_107 :
F_21 ( L_25 ) ;
break;
case V_108 :
F_21 ( L_26 ) ;
break;
}
}
static void F_55 ( struct V_41 * V_42 , struct V_30 * V_30 ,
T_1 V_109 , T_1 V_110 )
{
int V_111 = 0 ;
struct V_2 * V_3 = V_42 -> V_5 -> V_3 ;
if ( V_109 == 0 ) {
V_42 -> V_110 = V_110 ;
F_48 ( V_3 , V_42 ) ;
if ( F_56 ( V_3 , V_42 ,
& V_30 -> V_112 -> V_113 [ V_42 -> V_110 - 1 ] , V_19 ) ) {
V_111 = - V_56 ;
}
} else {
V_111 = - V_56 ;
}
F_17 ( V_3 , V_30 , V_111 , 0 ) ;
}
static void F_57 ( struct V_41 * V_42 , struct V_30 * V_30 ,
T_1 V_109 , T_1 V_114 , T_1 V_115 )
{
struct V_2 * V_3 = V_42 -> V_5 -> V_3 ;
int V_111 = 0 ;
if ( V_109 == 0 ) {
struct V_116 * V_113 ;
struct V_117 * V_118 ;
F_21 ( L_27 , V_114 , V_115 ) ;
F_58 ( V_3 , V_42 , V_114 ) ;
V_113 = & V_30 -> V_112 -> V_113 [ V_42 -> V_110 - 1 ] ;
V_118 = & V_113 -> V_119 [ V_114 ] -> V_120 [ V_115 ] ;
if ( F_59 ( V_3 , V_42 , V_118 ,
V_19 ) )
V_111 = - V_56 ;
else
V_42 -> V_121 [ V_114 ] . V_115 = V_115 ;
} else {
V_111 = - V_56 ;
}
F_17 ( V_3 , V_30 , V_111 , 0 ) ;
}
void F_60 ( void * V_73 , T_1 V_52 , T_1 V_109 , T_1 * V_122 ,
int V_123 )
{
struct V_41 * V_42 = (struct V_41 * ) V_73 ;
struct V_30 * V_30 ;
struct V_89 * V_90 ;
struct V_2 * V_3 = V_42 -> V_5 -> V_3 ;
unsigned V_124 ;
unsigned V_92 ;
F_25 ( V_84 , 0 , V_52 , 0 , V_109 ) ;
F_21 ( L_28 , V_109 , V_123 ) ;
V_30 = F_37 ( V_42 , 0 , V_52 ) ;
if ( ! V_30 ) {
F_21 ( L_29 ) ;
return;
}
V_90 = (struct V_89 * ) V_30 -> V_91 ;
V_124 = F_52 ( V_90 -> V_95 ) ;
V_92 = F_52 ( V_90 -> V_93 ) ;
if ( ( V_90 -> V_94 & V_125 ) == V_126 ) {
F_54 ( V_90 -> V_127 ) ;
switch ( V_90 -> V_127 ) {
case V_105 :
F_55 ( V_42 , V_30 , V_109 ,
( T_1 ) V_92 ) ;
break;
case V_107 :
F_57 ( V_42 , V_30 , V_109 ,
( T_1 ) V_124 , ( T_1 ) V_92 ) ;
break;
default:
F_17 ( V_3 , V_30 , 0 , 0 ) ;
}
} else {
int V_85 ;
F_21 ( L_30 ) ;
if ( V_123 <= V_30 -> V_87 )
V_85 = V_123 ;
else
V_85 = V_30 -> V_87 ;
if ( V_85 )
memcpy ( V_30 -> V_88 , V_122 , V_85 ) ;
V_30 -> V_96 = V_85 ;
F_17 ( V_3 , V_30 , 0 , 0 ) ;
}
}
static int F_61 ( struct V_23 * V_26 , T_1 * V_122 , int V_123 )
{
int V_128 ;
int V_85 ;
if ( ! V_26 -> V_29 )
return - 1 ;
V_128 = V_26 -> V_129 - V_26 -> V_130 - 1 ;
if ( V_128 < 0 )
V_128 += V_26 -> V_25 ;
if ( V_128 < ( V_123 + 1 ) ) {
F_21 ( L_31 ) ;
return - 1 ;
}
V_26 -> V_29 [ V_26 -> V_130 ] = ( T_1 ) V_123 ;
if ( ++ V_26 -> V_130 == V_26 -> V_25 )
V_26 -> V_130 = 0 ;
V_85 = V_26 -> V_25 - V_26 -> V_130 ;
if ( V_85 > V_123 )
V_85 = V_123 ;
memcpy ( & V_26 -> V_29 [ V_26 -> V_130 ] , V_122 , V_85 ) ;
if ( V_85 < V_123 ) {
memcpy ( V_26 -> V_29 , V_122 + V_85 , V_123 - V_85 ) ;
V_26 -> V_130 = V_123 - V_85 ;
} else {
V_26 -> V_130 += V_85 ;
}
if ( V_26 -> V_130 == V_26 -> V_25 )
V_26 -> V_130 = 0 ;
V_26 -> V_131 ++ ;
return 0 ;
}
void F_62 ( void * V_73 , T_1 V_132 , T_1 * V_122 , int V_123 )
{
struct V_41 * V_42 = (struct V_41 * ) V_73 ;
struct V_23 * V_26 ;
struct V_1 * V_5 = V_42 -> V_5 ;
F_30 ( & V_5 -> V_48 ) ;
V_26 = V_42 -> V_58 [ V_132 & V_133 ] ;
if ( V_26 == 0 )
goto V_134;
switch ( V_26 -> V_135 & V_136 ) {
case V_137 :
case V_138 :
if ( ! F_63 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_64 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 ;
int V_85 ;
F_16 ( & V_12 -> V_16 ) ;
F_33 ( & V_5 -> V_48 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
if ( V_123 <= V_30 -> V_87 )
V_85 = V_123 ;
else
V_85 = V_30 -> V_87 ;
memcpy ( V_30 -> V_88 , V_122 , V_85 ) ;
V_30 -> V_96 = V_85 ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
return;
}
break;
case V_139 :
F_61 ( V_26 , V_122 , V_123 ) ;
break;
}
V_134:
F_33 ( & V_5 -> V_48 ) ;
}
static inline int F_65 ( void )
{
return F_66 ( F_67 () ) ;
}
int F_68 ( void * V_73 )
{
int V_111 = 0 ;
struct V_41 * V_42 = (struct V_41 * ) V_73 ;
struct V_1 * V_5 = V_42 -> V_5 ;
struct V_11 * V_12 ;
struct V_21 V_140 ;
struct V_21 * V_22 ;
struct V_21 * V_141 ;
struct V_30 * V_30 ;
struct V_23 * V_26 ;
unsigned long V_142 = V_39 ;
F_13 ( & V_140 ) ;
F_30 ( & V_5 -> V_48 ) ;
F_15 (e, &port->isoc_out_ep) {
V_26 = F_69 ( V_22 ) ;
if ( V_26 -> V_28 < 0 )
continue;
V_26 -> V_28 += ( V_142 - V_26 -> V_60 ) ;
if ( V_26 -> V_28 > V_26 -> V_143 )
V_26 -> V_28 = V_26 -> V_143 ;
F_25 ( V_61 , V_26 -> V_47 , 0 , 0 , V_26 -> V_28 ) ;
V_26 -> V_60 = V_142 ;
while ( V_26 -> V_28 && ! F_63 ( & V_26 -> V_27 ) ) {
V_12 = F_64 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
if ( V_26 -> V_28 < V_30 -> V_144 )
break;
V_26 -> V_28 -= V_30 -> V_144 ;
F_25 ( V_61 , V_26 -> V_47 , 0 , 0 ,
V_26 -> V_28 ) ;
F_70 ( & V_12 -> V_16 ) ;
F_35 ( & V_12 -> V_16 , & V_140 ) ;
}
}
F_33 ( & V_5 -> V_48 ) ;
F_71 (e, n, &xfr_list) {
unsigned long V_97 ;
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
V_97 = V_12 -> V_32 ;
F_16 ( V_22 ) ;
V_30 -> V_145 = 0 ;
V_30 -> V_146 = F_65 () ;
F_72 ( V_42 -> V_46 , V_12 -> V_47 , V_30 ) ;
F_8 ( V_12 ) ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , V_97 ) ;
}
F_30 ( & V_5 -> V_48 ) ;
F_15 (e, &port->isoc_in_ep) {
struct V_23 * V_26 = F_69 ( V_22 ) ;
if ( V_26 -> V_44 & V_147 ) {
if ( V_26 -> V_131 * V_148 ) {
V_26 -> V_44 &= ~ V_147 ;
V_26 -> V_28 = 0 ;
F_25 ( V_61 ,
V_26 -> V_47 | V_149 ,
0 , 0 , V_26 -> V_28 ) ;
V_26 -> V_60 = V_142 ;
V_26 -> V_146 = 0 ;
F_25 ( V_150 ,
V_26 -> V_47 | V_149 , 0 , 0 , 0 ) ;
}
continue;
}
V_26 -> V_28 += ( V_142 - V_26 -> V_60 ) ;
F_25 ( V_61 , V_26 -> V_47 | V_149 ,
0 , 0 , V_26 -> V_28 ) ;
V_26 -> V_60 = V_142 ;
while ( ! F_63 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_64 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 = V_12 -> V_30 ;
int V_151 = 0 ;
int V_85 ;
int V_7 ;
if ( V_26 -> V_28 < V_30 -> V_144 )
break;
if ( V_26 -> V_131 < V_30 -> V_144 )
break;
V_30 -> V_96 = 0 ;
for ( V_7 = 0 ; V_7 < V_30 -> V_144 ; V_7 ++ ) {
V_151 = V_26 -> V_29 [ V_26 -> V_129 ] ;
if ( ++ V_26 -> V_129 == V_26 -> V_25 )
V_26 -> V_129 = 0 ;
V_85 = V_26 -> V_25 - V_26 -> V_129 ;
if ( V_85 > V_151 )
V_85 = V_151 ;
memcpy ( V_30 -> V_88 ,
& V_26 -> V_29 [ V_26 -> V_129 ] , V_85 ) ;
if ( V_85 < V_151 ) {
memcpy ( V_30 -> V_88 + V_85 ,
V_26 -> V_29 , V_151 - V_85 ) ;
V_26 -> V_129 = V_151 - V_85 ;
} else
V_26 -> V_129 += V_85 ;
if ( V_26 -> V_129 == V_26 -> V_25 )
V_26 -> V_129 = 0 ;
V_30 -> V_152 [ V_7 ] . V_82 =
V_30 -> V_96 ;
V_30 -> V_96 += V_151 ;
V_30 -> V_152 [ V_7 ] . V_96 = V_151 ;
V_30 -> V_152 [ V_7 ] . V_31 = 0 ;
}
V_26 -> V_131 -= V_30 -> V_144 ;
V_30 -> V_145 = 0 ;
V_30 -> V_146 = V_26 -> V_146 ;
V_26 -> V_146 += V_30 -> V_144 ;
F_70 ( & V_12 -> V_16 ) ;
F_35 ( & V_12 -> V_16 , & V_140 ) ;
V_26 -> V_28 -= V_30 -> V_144 ;
F_25 ( V_61 , V_26 -> V_47 | V_149 ,
0 , 0 , V_26 -> V_28 ) ;
}
}
if ( ! F_63 ( & V_42 -> V_65 ) || ! F_63 ( & V_42 -> V_66 ) )
V_111 = 1 ;
F_33 ( & V_5 -> V_48 ) ;
F_71 (e, n, &xfr_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
F_8 ( V_12 ) ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
V_26 = V_42 -> V_59 [ 0 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
struct V_21 * V_141 ;
F_30 ( & V_5 -> V_48 ) ;
F_71 (e, n, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( F_73 ( V_142 , V_12 -> V_32 + V_153 / 2 ) ) {
F_21 ( L_32 ,
V_142 , V_12 -> V_30 ) ;
V_12 -> V_32 = V_142 ;
F_70 ( V_22 ) ;
F_35 ( V_22 , & V_140 ) ;
}
}
if ( ! F_63 ( & V_26 -> V_27 ) )
V_111 = 1 ;
F_33 ( & V_5 -> V_48 ) ;
V_22 = V_140 . V_17 ;
while ( V_22 != & V_140 ) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_22 = V_22 -> V_17 ;
F_21 ( L_33 ) ;
F_74 ( V_5 , V_12 -> V_30 , V_19 ) ;
F_8 ( V_12 ) ;
}
}
return V_111 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
struct V_117 * V_118 , T_2 V_24 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
int V_7 ;
int V_154 = V_118 -> V_80 . V_155 ;
int V_156 = 0 ;
F_21 ( L_34 , V_154 , V_118 ) ;
for ( V_7 = 0 ; V_7 < V_118 -> V_80 . V_157 ; V_7 ++ ) {
struct V_158 * V_159 = & V_118 -> V_132 [ V_7 ] ;
T_1 V_50 = V_159 -> V_80 . V_160 ;
T_1 V_47 = V_50 & V_133 ;
struct V_23 * V_26 ;
int V_25 = 0 ;
F_21 ( L_35 , V_7 , V_50 ) ;
if ( ( V_50 & V_161 ) &&
( ( V_159 -> V_80 . V_162 & V_136 )
== V_139 ) ) {
V_25 = 24 * 1024 ;
}
V_26 = F_11 ( V_24 , V_25 ) ;
if ( ! V_26 ) {
F_58 ( V_3 , V_42 , V_154 ) ;
return - V_56 ;
}
V_26 -> V_135 = V_159 -> V_80 . V_162 ;
V_26 -> V_47 = V_47 ;
if ( ( V_26 -> V_135 & V_136 )
== V_139 ) {
F_21 ( L_36 ,
V_159 -> V_80 . V_163 ) ;
V_26 -> V_143 = 200 ;
if ( V_50 & V_161 ) {
V_26 -> V_44 |= V_147 ;
F_25 ( V_150 ,
V_26 -> V_47 | V_149 , 1 , 0 , 0 ) ;
} else {
V_26 -> V_44 |= V_45 ;
if ( F_75 ( V_42 -> V_46 , V_47 ) )
V_26 -> V_44 &= ~ V_45 ;
}
}
F_30 ( & V_5 -> V_48 ) ;
if ( V_50 & V_161 ) {
V_42 -> V_58 [ V_47 ] = V_26 ;
V_42 -> V_121 [ V_154 ] . V_164 |=
( 1 << ( V_47 + V_54 ) ) ;
if ( ( V_26 -> V_135 & V_136 )
== V_139 ) {
F_35 ( & V_26 -> V_16 , & V_42 -> V_66 ) ;
V_156 = 1 ;
}
} else {
V_42 -> V_59 [ V_47 ] = V_26 ;
V_42 -> V_121 [ V_154 ] . V_164 |= ( 1 << V_47 ) ;
if ( ( V_26 -> V_135 & V_136 )
== V_139 ) {
F_35 ( & V_26 -> V_16 , & V_42 -> V_65 ) ;
V_156 = 1 ;
}
}
F_33 ( & V_5 -> V_48 ) ;
if ( V_156 && V_42 -> V_46 )
F_76 ( V_42 -> V_46 ) ;
}
return 0 ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_41 * V_42 , int V_154 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
unsigned V_165 ;
int V_7 ;
struct V_21 V_166 ;
F_21 ( L_37 , V_154 ) ;
if ( V_154 >= V_42 -> V_167 )
return;
F_13 ( & V_166 ) ;
F_30 ( & V_5 -> V_48 ) ;
V_165 = V_42 -> V_121 [ V_154 ] . V_164 ;
V_42 -> V_121 [ V_154 ] . V_164 = 0 ;
for ( V_7 = 0 ; V_7 < V_54 ; V_7 ++ ) {
struct V_21 * V_22 ;
if ( ( V_165 & ( 1 << V_7 ) ) && V_42 -> V_59 [ V_7 ] ) {
V_22 = & V_42 -> V_59 [ V_7 ] -> V_16 ;
V_42 -> V_59 [ V_7 ] = 0 ;
F_70 ( V_22 ) ;
F_35 ( V_22 , & V_166 ) ;
}
if ( ( V_165 & ( 1 << ( V_7 + V_54 ) ) ) && V_42 -> V_58 [ V_7 ] ) {
V_22 = & V_42 -> V_58 [ V_7 ] -> V_16 ;
V_42 -> V_58 [ V_7 ] = 0 ;
F_70 ( V_22 ) ;
F_35 ( V_22 , & V_166 ) ;
}
}
F_33 ( & V_5 -> V_48 ) ;
while ( ! F_63 ( & V_166 ) ) {
struct V_23 * V_26 =
F_64 ( & V_166 , struct V_23 , V_16 ) ;
F_16 ( & V_26 -> V_16 ) ;
F_28 ( V_42 , V_26 ) ;
}
}
static int F_56 ( struct V_2 * V_3 ,
struct V_41 * V_42 , struct V_116 * V_113 ,
T_2 V_24 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
int V_7 ;
int V_167 = V_113 -> V_80 . V_168 ;
if ( V_167 ) {
struct V_169 * V_121 ;
V_121 = F_7 ( V_167 * sizeof( struct V_169 ) ,
V_24 | V_170 ) ;
if ( ! V_121 )
return - V_56 ;
F_30 ( & V_5 -> V_48 ) ;
V_42 -> V_121 = V_121 ;
V_42 -> V_167 = V_167 ;
F_33 ( & V_5 -> V_48 ) ;
}
for ( V_7 = 0 ; V_7 < V_167 ; V_7 ++ ) {
struct V_117 * V_118 =
& V_113 -> V_119 [ V_7 ] -> V_120 [ 0 ] ;
if ( F_59 ( V_3 , V_42 , V_118 ,
V_24 ) )
goto V_171;
}
return 0 ;
V_171:
F_48 ( V_3 , V_42 ) ;
return - 1 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
int V_7 ;
F_21 ( L_38 ) ;
for ( V_7 = 0 ; V_7 < V_42 -> V_167 ; V_7 ++ )
F_58 ( V_3 , V_42 , V_7 ) ;
F_30 ( & V_5 -> V_48 ) ;
if ( V_42 -> V_121 ) {
F_21 ( L_39 ) ;
F_9 ( V_42 -> V_121 ) ;
V_42 -> V_121 = 0 ;
}
V_42 -> V_167 = 0 ;
F_33 ( & V_5 -> V_48 ) ;
}
static void * F_77 ( struct V_41 * V_42 )
{
void * V_46 = 0 ;
struct V_1 * V_5 = V_42 -> V_5 ;
F_30 ( & V_5 -> V_48 ) ;
V_46 = V_42 -> V_46 ;
if ( V_46 )
F_39 ( V_46 ) ;
F_33 ( & V_5 -> V_48 ) ;
return V_46 ;
}
static void F_74 ( struct V_1 * V_5 , struct V_30 * V_30 ,
T_2 V_24 )
{
struct V_89 * V_90 ;
unsigned V_124 ;
unsigned V_92 ;
unsigned V_172 ;
void * V_46 = 0 ;
T_1 V_52 ;
int V_111 = 0 ;
unsigned V_173 = 0 ;
int V_174 = - 1 ;
struct V_41 * V_42 = 0 ;
F_23 ( V_38 , L_40 , V_39 , V_30 ) ;
V_174 = F_2 ( V_5 , V_30 -> V_112 -> V_175 ) ;
if ( V_174 < 0 ) {
V_111 = - V_62 ;
goto V_74;
}
V_42 = & V_5 -> V_9 [ V_174 ] ;
if ( ( ( V_42 -> V_44 & V_67 ) == 0 )
|| ( V_42 -> V_44 & V_77 ) ) {
F_21 ( L_41 ,
V_174 , V_30 -> V_112 -> V_175 ) ;
V_111 = - V_62 ;
goto V_74;
}
V_30 -> V_35 = V_42 ;
V_90 = (struct V_89 * ) V_30 -> V_91 ;
V_124 = F_52 ( V_90 -> V_95 ) ;
V_92 = F_52 ( V_90 -> V_93 ) ;
V_172 = F_52 ( V_90 -> V_176 ) ;
F_23 ( V_177 , L_42 ,
V_90 -> V_94 ) ;
F_23 ( V_177 , L_43 , V_90 -> V_127 ) ;
F_23 ( V_177 , L_44 , V_92 ) ;
F_23 ( V_177 , L_45 , V_124 ) ;
F_23 ( V_177 , L_46 , V_172 ) ;
V_52 = V_42 -> V_178 ++ ;
V_46 = F_77 ( V_42 ) ;
if ( V_46 == 0 ) {
F_21 ( L_47 ) ;
V_111 = - V_62 ;
goto V_74;
}
if ( ( V_90 -> V_94 & V_125 ) == V_126 ) {
switch ( V_90 -> V_127 ) {
case V_102 :
F_21 ( L_48 ) ;
break;
case V_101 :
F_25 ( V_179 , V_90 -> V_127 ,
0 , 0 , V_90 -> V_94 ) ;
F_21 ( L_49 ) ;
F_21 ( L_50 , V_5 -> V_10 ,
( T_1 ) F_52 ( V_90 -> V_93 ) ) ;
F_30 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_10 >= 0 ) {
V_5 -> V_9 [ V_5 -> V_10 ] . V_6 =
( T_1 ) F_52 ( V_90 -> V_93 ) ;
F_21 ( L_13 ) ;
V_5 -> V_10 = - 1 ;
}
F_33 ( & V_5 -> V_48 ) ;
V_173 = 1 ;
break;
case V_105 :
F_21 ( L_51 ) ;
break;
case V_104 :
F_25 ( V_179 , V_90 -> V_127 , 0 , 0 ,
V_90 -> V_94 ) ;
F_21 ( L_52 ) ;
if ( V_30 -> V_87 >= 1 ) {
V_30 -> V_96 = 1 ;
* ( ( T_1 * ) V_30 -> V_88 ) =
V_42 -> V_110 ;
V_173 = 1 ;
} else {
V_111 = - V_62 ;
}
break;
case V_106 :
F_25 ( V_179 , V_90 -> V_127 , 0 , 0 ,
V_90 -> V_94 ) ;
F_21 ( L_53 ) ;
if ( V_30 -> V_87 >= 1 ) {
V_30 -> V_96 = 1 ;
* ( ( T_1 * ) V_30 -> V_88 ) =
V_42 -> V_121 [ ( T_1 ) V_124 ] . V_115 ;
F_21 ( L_54 ,
V_124 , V_42 -> V_121 [ ( T_1 ) V_124 ] . V_115 ) ;
V_173 = 1 ;
} else {
V_111 = - V_62 ;
}
break;
case V_107 :
F_21 ( L_55 ) ;
break;
}
}
if ( ! V_111 && ! V_173 ) {
int V_123 = 0 ;
if ( ( V_90 -> V_94 & V_149 ) == 0 )
V_123 = V_172 ;
if ( F_78 ( V_42 -> V_46 , V_52 , V_90 ,
V_30 -> V_88 , V_123 ) ) {
V_111 = - V_56 ;
} else {
if ( F_34 ( V_42 , 0 , 0 , V_30 , V_52 ) )
V_111 = - V_56 ;
}
}
F_49 ( V_46 ) ;
V_74:
if ( V_111 || V_173 ) {
F_21 ( L_56 ) ;
F_17 ( V_5 -> V_3 , V_30 , V_111 , 0 ) ;
} else {
F_76 ( V_42 -> V_46 ) ;
}
}
static int F_79 ( struct V_1 * V_5 , struct V_30 * V_30 )
{
int V_111 = 0 ;
struct V_41 * V_42 = V_30 -> V_35 ;
T_1 V_50 ;
F_80 ( V_30 ) ;
if ( ! V_30 -> V_88 && V_30 -> V_87 )
return - V_55 ;
if ( ( V_42 -> V_44 & V_67 ) == 0 )
return - V_62 ;
V_50 = F_81 ( V_30 -> V_180 ) ;
if ( V_50 ) {
if ( F_34 ( V_42 , V_50 , F_82 ( V_30 -> V_180 ) ,
V_30 , 0 ) )
V_111 = - V_62 ;
} else {
F_74 ( V_5 , V_30 , V_19 ) ;
}
return V_111 ;
}
static void F_83 ( unsigned long V_181 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_40 () ;
int V_111 = 0 ;
if ( V_5 == 0 )
return;
F_4 ( & V_34 , V_13 ) ;
while ( ! F_63 ( & V_5 -> V_182 ) ) {
struct V_11 * V_12 =
F_64 ( & V_5 -> V_182 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_34 , V_13 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
V_111 = F_79 ( V_5 , V_30 ) ;
if ( V_111 )
F_17 ( V_5 -> V_3 , V_30 , V_111 , 0 ) ;
F_4 ( & V_34 , V_13 ) ;
}
F_6 ( & V_34 , V_13 ) ;
F_42 ( V_5 ) ;
}
static void F_84 ( struct V_41 * V_42 , T_1 V_47 , struct V_30 * V_30 )
{
struct V_11 * V_12 = 0 ;
struct V_21 * V_22 ;
struct V_1 * V_5 ;
unsigned long V_13 ;
T_1 V_183 ;
if ( V_42 == 0 ) {
F_21 ( L_57 , V_30 ) ;
return;
}
V_5 = V_42 -> V_5 ;
if ( V_5 == 0 ) {
F_21 ( L_58 , V_30 ) ;
return;
}
F_4 ( & V_34 , V_13 ) ;
F_15 (e, &ozhcd->urb_cancel_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_30 == V_12 -> V_30 ) {
F_16 ( V_22 ) ;
F_6 ( & V_34 , V_13 ) ;
goto V_184;
}
}
F_6 ( & V_34 , V_13 ) ;
V_12 = 0 ;
F_4 ( & V_5 -> V_48 , V_13 ) ;
F_15 (e, &ozhcd->orphanage) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_70 ( V_22 ) ;
F_21 ( L_59 ) ;
goto V_74;
}
}
V_183 = ( V_47 & 0xf ) ;
V_12 = 0 ;
if ( ( V_47 & V_149 ) && V_183 )
V_12 = F_85 ( V_42 -> V_58 [ V_183 ] , V_30 ) ;
else
V_12 = F_85 ( V_42 -> V_59 [ V_183 ] , V_30 ) ;
V_74:
F_6 ( & V_5 -> V_48 , V_13 ) ;
V_184:
if ( V_12 ) {
V_30 -> V_96 = 0 ;
F_8 ( V_12 ) ;
F_17 ( V_5 -> V_3 , V_30 , - V_62 , 0 ) ;
}
}
static void F_86 ( unsigned long V_181 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_40 () ;
if ( V_5 == 0 )
return;
F_4 ( & V_34 , V_13 ) ;
while ( ! F_63 ( & V_5 -> V_185 ) ) {
struct V_11 * V_12 =
F_64 ( & V_5 -> V_185 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_34 , V_13 ) ;
V_30 = V_12 -> V_30 ;
if ( V_30 -> V_57 )
F_84 ( V_12 -> V_42 , V_12 -> V_47 , V_30 ) ;
F_8 ( V_12 ) ;
F_4 ( & V_34 , V_13 ) ;
}
F_6 ( & V_34 , V_13 ) ;
F_42 ( V_5 ) ;
}
static void F_87 ( struct V_1 * V_5 , int V_31 )
{
if ( V_5 ) {
struct V_11 * V_12 ;
while ( ! F_63 ( & V_5 -> V_49 ) ) {
V_12 = F_64 ( & V_5 -> V_49 ,
struct V_11 , V_16 ) ;
F_70 ( & V_12 -> V_16 ) ;
F_17 ( V_5 -> V_3 , V_12 -> V_30 , V_31 , 0 ) ;
F_8 ( V_12 ) ;
}
}
}
static int F_88 ( struct V_2 * V_3 )
{
F_21 ( L_60 ) ;
V_3 -> V_186 = 200 ;
V_3 -> V_187 = V_188 ;
V_3 -> V_189 = 1 ;
return 0 ;
}
static void F_89 ( struct V_2 * V_3 )
{
F_21 ( L_61 ) ;
}
static void F_90 ( struct V_2 * V_3 )
{
F_21 ( L_62 ) ;
}
static T_1 F_91 ( void )
{
T_1 V_190 = 0 ;
if ( F_92 () )
V_190 |= 1 ;
if ( F_93 () )
V_190 |= 2 ;
return V_190 ;
}
static int F_94 ( struct V_2 * V_3 , struct V_30 * V_30 ,
T_2 V_24 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_111 = 0 ;
int V_174 ;
struct V_41 * V_42 ;
unsigned long V_13 ;
struct V_11 * V_12 ;
F_23 ( V_38 , L_63 ,
V_39 , V_30 ) ;
F_25 ( V_191 , F_91 () ,
( V_192 ) V_30 -> V_144 , V_30 , V_30 -> V_180 ) ;
if ( F_95 ( V_5 == 0 ) ) {
F_23 ( V_38 , L_64 ,
V_39 , V_30 ) ;
return - V_62 ;
}
if ( F_95 ( V_3 -> V_187 != V_188 ) ) {
F_23 ( V_38 , L_65 ,
V_39 , V_30 ) ;
return - V_62 ;
}
V_174 = F_2 ( V_5 , V_30 -> V_112 -> V_175 ) ;
if ( V_174 < 0 )
return - V_62 ;
V_42 = & V_5 -> V_9 [ V_174 ] ;
if ( V_42 == 0 )
return - V_62 ;
if ( ( V_42 -> V_44 & V_67 ) == 0 ) {
F_21 ( L_41 ,
V_174 , V_30 -> V_112 -> V_175 ) ;
return - V_62 ;
}
V_30 -> V_35 = V_42 ;
V_12 = F_3 () ;
if ( F_95 ( V_12 == 0 ) )
return - V_56 ;
V_12 -> V_30 = V_30 ;
F_4 ( & V_34 , V_13 ) ;
V_111 = F_96 ( V_3 , V_30 ) ;
if ( F_95 ( V_111 ) ) {
F_6 ( & V_34 , V_13 ) ;
F_8 ( V_12 ) ;
return V_111 ;
}
F_35 ( & V_12 -> V_16 , & V_5 -> V_182 ) ;
F_6 ( & V_34 , V_13 ) ;
F_97 ( & V_193 ) ;
F_98 ( & V_37 ) ;
return 0 ;
}
static struct V_11 * F_85 ( struct V_23 * V_26 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 = 0 ;
struct V_21 * V_22 ;
if ( F_95 ( V_26 == 0 ) )
return 0 ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_16 ( V_22 ) ;
if ( F_99 ( V_30 -> V_180 ) ) {
V_26 -> V_28 -= V_30 -> V_144 ;
if ( V_26 -> V_28 < 0 )
V_26 -> V_28 = 0 ;
F_25 ( V_61 ,
F_82 ( V_30 -> V_180 ) ?
( V_26 -> V_47 | V_149 ) : V_26 -> V_47 ,
0 , 0 , V_26 -> V_28 ) ;
}
return V_12 ;
}
}
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , struct V_30 * V_30 , int V_31 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_11 * V_12 = 0 ;
int V_111 ;
unsigned long V_13 ;
F_23 ( V_38 , L_66 , V_39 , V_30 ) ;
V_12 = F_3 () ;
if ( F_95 ( V_12 == 0 ) )
return - V_56 ;
F_4 ( & V_34 , V_13 ) ;
V_111 = F_101 ( V_3 , V_30 , V_31 ) ;
if ( ( V_111 == 0 ) && V_30 -> V_35 ) {
V_12 -> V_30 = V_30 ;
V_12 -> V_42 = (struct V_41 * ) V_30 -> V_35 ;
V_12 -> V_47 = F_81 ( V_30 -> V_180 ) ;
if ( F_82 ( V_30 -> V_180 ) )
V_12 -> V_47 |= V_149 ;
F_35 ( & V_12 -> V_16 , & V_5 -> V_185 ) ;
F_6 ( & V_34 , V_13 ) ;
F_97 ( & V_194 ) ;
} else {
F_6 ( & V_34 , V_13 ) ;
F_8 ( V_12 ) ;
}
return V_111 ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_158 * V_26 )
{
F_21 ( L_67 ) ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_158 * V_26 )
{
F_21 ( L_68 ) ;
}
static int F_104 ( struct V_2 * V_3 )
{
F_21 ( L_69 ) ;
return F_65 () ;
}
static int F_105 ( struct V_2 * V_3 , char * V_195 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_7 ;
F_23 ( V_196 , L_70 ) ;
V_195 [ 0 ] = 0 ;
F_30 ( & V_5 -> V_48 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_5 -> V_9 [ V_7 ] . V_44 & V_68 ) {
F_23 ( V_196 , L_71 , V_7 ) ;
V_5 -> V_9 [ V_7 ] . V_44 &= ~ V_68 ;
V_195 [ 0 ] |= 1 << ( V_7 + 1 ) ;
}
}
F_33 ( & V_5 -> V_48 ) ;
return V_195 [ 0 ] ? 1 : 0 ;
}
static void F_106 ( struct V_2 * V_3 ,
struct V_197 * V_80 )
{
F_23 ( V_196 , L_72 ) ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
V_80 -> V_198 = 0x29 ;
V_80 -> V_199 = 9 ;
V_80 -> V_200 = ( V_201 V_202 )
F_107 ( 0x0001 ) ;
V_80 -> V_203 = V_8 ;
}
static int F_108 ( struct V_2 * V_3 , V_192 V_92 , V_192 V_124 )
{
struct V_41 * V_42 ;
int V_53 = 0 ;
T_1 V_204 = ( T_1 ) V_124 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_205 = 0 ;
unsigned V_206 = 0 ;
F_23 ( V_196 , L_73 ) ;
if ( ( V_204 < 1 ) || ( V_204 > V_8 ) )
return - V_62 ;
V_42 = & V_5 -> V_9 [ V_204 - 1 ] ;
switch ( V_92 ) {
case V_207 :
F_23 ( V_196 , L_74 ) ;
break;
case V_208 :
F_23 ( V_196 , L_75 ) ;
break;
case V_209 :
F_23 ( V_196 , L_76 ) ;
break;
case V_210 :
F_23 ( V_196 , L_77 ) ;
break;
case V_211 :
F_23 ( V_196 , L_78 ) ;
V_205 = V_212 | ( V_79 << 16 ) ;
V_206 = V_78 ;
V_5 -> V_9 [ V_204 - 1 ] . V_6 = 0 ;
break;
case V_213 :
F_23 ( V_196 , L_79 ) ;
V_205 |= V_214 ;
break;
case V_215 :
F_23 ( V_196 , L_80 ) ;
break;
case V_216 :
F_23 ( V_196 , L_81 ) ;
break;
case V_217 :
F_23 ( V_196 , L_82 ) ;
break;
case V_218 :
F_23 ( V_196 , L_83 ) ;
break;
case V_219 :
F_23 ( V_196 , L_84 ) ;
break;
case V_220 :
F_23 ( V_196 , L_85 ) ;
break;
case V_221 :
F_23 ( V_196 , L_86 ) ;
break;
case V_222 :
F_23 ( V_196 , L_87 ) ;
break;
default:
F_23 ( V_196 , L_88 , V_92 ) ;
break;
}
if ( V_205 || V_206 ) {
F_30 ( & V_42 -> V_75 ) ;
V_42 -> V_31 &= ~ V_206 ;
V_42 -> V_31 |= V_205 ;
F_33 ( & V_42 -> V_75 ) ;
}
F_23 ( V_196 , L_89 , V_204 ,
V_42 -> V_31 ) ;
return V_53 ;
}
static int F_109 ( struct V_2 * V_3 , V_192 V_92 , V_192 V_124 )
{
struct V_41 * V_42 ;
int V_53 = 0 ;
T_1 V_204 = ( T_1 ) V_124 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_206 = 0 ;
F_23 ( V_196 , L_90 ) ;
if ( ( V_204 < 1 ) || ( V_204 > V_8 ) )
return - V_62 ;
V_42 = & V_5 -> V_9 [ V_204 - 1 ] ;
switch ( V_92 ) {
case V_207 :
F_23 ( V_196 , L_74 ) ;
break;
case V_208 :
F_23 ( V_196 , L_75 ) ;
V_206 = V_212 ;
break;
case V_209 :
F_23 ( V_196 , L_76 ) ;
break;
case V_210 :
F_23 ( V_196 , L_77 ) ;
break;
case V_211 :
F_23 ( V_196 , L_78 ) ;
break;
case V_213 :
F_23 ( V_196 , L_79 ) ;
V_206 |= V_214 ;
break;
case V_215 :
F_23 ( V_196 , L_80 ) ;
break;
case V_216 :
F_23 ( V_196 , L_81 ) ;
V_206 = ( V_70 << 16 ) ;
break;
case V_217 :
F_23 ( V_196 , L_82 ) ;
V_206 = ( V_223 << 16 ) ;
break;
case V_218 :
F_23 ( V_196 , L_83 ) ;
break;
case V_219 :
F_23 ( V_196 , L_84 ) ;
break;
case V_220 :
F_23 ( V_196 , L_85 ) ;
V_206 = ( V_220 << 16 ) ;
break;
case V_221 :
F_23 ( V_196 , L_86 ) ;
break;
case V_222 :
F_23 ( V_196 , L_87 ) ;
break;
default:
F_23 ( V_196 , L_88 , V_92 ) ;
break;
}
if ( V_206 ) {
F_30 ( & V_42 -> V_75 ) ;
V_42 -> V_31 &= ~ V_206 ;
F_33 ( & V_42 -> V_75 ) ;
}
F_23 ( V_196 , L_89 , V_204 ,
V_5 -> V_9 [ V_204 - 1 ] . V_31 ) ;
return V_53 ;
}
static int F_110 ( struct V_2 * V_3 , V_192 V_124 , char * V_195 )
{
struct V_1 * V_5 ;
T_3 V_31 = 0 ;
if ( ( V_124 < 1 ) || ( V_124 > V_8 ) )
return - V_62 ;
V_5 = F_1 ( V_3 ) ;
F_23 ( V_196 , L_91 , V_124 ) ;
V_31 = V_5 -> V_9 [ V_124 - 1 ] . V_31 ;
F_111 ( F_112 ( V_31 ) , ( V_224 * ) V_195 ) ;
F_23 ( V_196 , L_92 , V_124 , V_31 ) ;
return 0 ;
}
static int F_113 ( struct V_2 * V_3 , V_192 V_225 , V_192 V_92 ,
V_192 V_124 , char * V_195 , V_192 V_172 )
{
int V_53 = 0 ;
F_23 ( V_196 , L_93 ) ;
switch ( V_225 ) {
case V_226 :
F_23 ( V_196 , L_94 , V_225 ) ;
break;
case V_227 :
V_53 = F_109 ( V_3 , V_92 , V_124 ) ;
break;
case V_228 :
F_106 ( V_3 , (struct V_197 * ) V_195 ) ;
break;
case V_229 :
F_23 ( V_196 , L_95 ,
V_225 ) ;
F_111 ( F_114 ( 0 ) , ( V_224 * ) V_195 ) ;
break;
case V_230 :
V_53 = F_110 ( V_3 , V_124 , V_195 ) ;
break;
case V_231 :
F_23 ( V_196 , L_96 , V_225 ) ;
break;
case V_232 :
V_53 = F_108 ( V_3 , V_92 , V_124 ) ;
break;
default:
F_23 ( V_196 , L_97 , V_225 ) ;
break;
}
return V_53 ;
}
static int F_115 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_23 ( V_196 , L_98 ) ;
V_5 = F_1 ( V_3 ) ;
F_30 ( & V_5 -> V_48 ) ;
V_3 -> V_187 = V_233 ;
V_5 -> V_44 |= V_76 ;
F_33 ( & V_5 -> V_48 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_23 ( V_196 , L_99 ) ;
V_5 = F_1 ( V_3 ) ;
F_30 ( & V_5 -> V_48 ) ;
V_5 -> V_44 &= ~ V_76 ;
V_3 -> V_187 = V_188 ;
F_33 ( & V_5 -> V_48 ) ;
return 0 ;
}
static void F_117 ( struct V_234 * V_112 )
{
F_21 ( L_100 ) ;
}
static int F_118 ( struct V_234 * V_112 )
{
int V_7 ;
int V_53 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
F_21 ( L_101 ) ;
V_3 = F_119 ( & V_235 , & V_112 -> V_112 , F_120 ( & V_112 -> V_112 ) ) ;
if ( V_3 == 0 ) {
F_21 ( L_102 ) ;
return - V_56 ;
}
V_5 = F_1 ( V_3 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_13 ( & V_5 -> V_182 ) ;
F_13 ( & V_5 -> V_185 ) ;
F_13 ( & V_5 -> V_49 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_10 = - 1 ;
F_121 ( & V_5 -> V_48 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_41 * V_42 = & V_5 -> V_9 [ V_7 ] ;
V_42 -> V_5 = V_5 ;
V_42 -> V_44 = 0 ;
V_42 -> V_31 = 0 ;
V_42 -> V_6 = 0xff ;
F_121 ( & V_42 -> V_75 ) ;
}
V_53 = F_122 ( V_3 , 0 , 0 ) ;
if ( V_53 ) {
F_21 ( L_103 ) ;
F_43 ( V_3 ) ;
return - 1 ;
}
F_30 ( & V_71 ) ;
V_72 = V_5 ;
F_33 ( & V_71 ) ;
return 0 ;
}
static int F_123 ( struct V_234 * V_112 )
{
struct V_2 * V_3 = F_124 ( V_112 ) ;
struct V_1 * V_5 ;
F_21 ( L_104 ) ;
if ( V_3 == 0 )
return - 1 ;
V_5 = F_1 ( V_3 ) ;
F_30 ( & V_71 ) ;
if ( V_5 == V_72 )
V_72 = 0 ;
F_33 ( & V_71 ) ;
F_21 ( L_105 ) ;
F_87 ( V_5 , - V_62 ) ;
F_21 ( L_106 ) ;
F_125 ( V_3 ) ;
F_43 ( V_3 ) ;
F_10 () ;
return 0 ;
}
static int F_126 ( struct V_234 * V_112 , T_4 V_236 )
{
F_21 ( L_107 ) ;
return 0 ;
}
static int F_127 ( struct V_234 * V_112 )
{
F_21 ( L_108 ) ;
return 0 ;
}
int F_128 ( void )
{
int V_53 ;
if ( F_129 () )
return - V_237 ;
F_130 ( & V_193 , F_83 , 0 ) ;
F_130 ( & V_194 , F_86 , 0 ) ;
V_53 = F_131 ( & V_238 ) ;
F_21 ( L_109 , V_53 ) ;
if ( V_53 )
goto error;
V_239 = F_132 ( V_240 , - 1 ) ;
if ( V_239 == 0 ) {
V_53 = - V_56 ;
goto V_241;
}
F_21 ( L_110 ) ;
V_53 = F_133 ( V_239 ) ;
if ( V_53 )
goto V_242;
F_21 ( L_111 ) ;
return 0 ;
V_242:
F_134 ( V_239 ) ;
V_241:
F_135 ( & V_238 ) ;
error:
F_136 ( & V_193 ) ;
F_136 ( & V_194 ) ;
F_21 ( L_112 , V_53 ) ;
return V_53 ;
}
void F_137 ( void )
{
F_136 ( & V_193 ) ;
F_136 ( & V_194 ) ;
F_138 ( V_239 ) ;
F_135 ( & V_238 ) ;
F_21 ( L_113 , F_24 ( & V_37 ) ) ;
}
