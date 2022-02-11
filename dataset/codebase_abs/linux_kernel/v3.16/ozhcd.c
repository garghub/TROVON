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
struct V_11 * V_12 = NULL ;
unsigned long V_13 ;
F_4 ( & V_14 , V_13 ) ;
if ( V_15 ) {
V_12 = F_5 ( V_15 , struct V_11 , V_16 ) ;
V_15 = V_12 -> V_16 . V_17 ;
-- V_18 ;
}
F_6 ( & V_14 , V_13 ) ;
if ( V_12 == NULL )
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
V_12 = NULL ;
V_18 ++ ;
}
F_6 ( & V_14 , V_13 ) ;
F_9 ( V_12 ) ;
}
}
static void F_10 ( void )
{
struct V_21 * V_22 ;
unsigned long V_13 ;
F_4 ( & V_14 , V_13 ) ;
V_22 = V_15 ;
V_15 = NULL ;
V_18 = 0 ;
F_6 ( & V_14 , V_13 ) ;
while ( V_22 ) {
struct V_11 * V_12 =
F_5 ( V_22 , struct V_11 , V_16 ) ;
V_22 = V_22 -> V_17 ;
F_9 ( V_12 ) ;
}
}
static struct V_23 * F_11 ( int V_24 , T_2 V_25 )
{
struct V_23 * V_26 =
F_12 ( sizeof( struct V_23 ) + V_24 , V_25 ) ;
if ( V_26 ) {
F_13 ( & V_26 -> V_27 ) ;
F_13 ( & V_26 -> V_16 ) ;
V_26 -> V_28 = - 1 ;
if ( V_24 ) {
V_26 -> V_24 = V_24 ;
V_26 -> V_29 = ( T_1 * ) ( V_26 + 1 ) ;
}
}
return V_26 ;
}
static struct V_11 * F_14 ( struct V_1 * V_5 ,
struct V_30 * V_30 )
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
return NULL ;
}
static void F_17 ( struct V_2 * V_3 , struct V_30 * V_30 ,
int V_31 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_13 ;
struct V_11 * V_32 ;
F_4 ( & V_33 , V_13 ) ;
F_18 ( V_3 , V_30 ) ;
V_30 -> V_34 = NULL ;
V_32 = F_14 ( V_5 , V_30 ) ;
F_19 ( & V_33 ) ;
if ( F_20 ( V_30 ) ) {
F_21 ( V_35 , L_1 , V_30 ) ;
} else {
F_22 ( & V_36 ) ;
F_23 ( V_3 , V_30 , V_31 ) ;
}
F_24 ( & V_33 ) ;
F_6 ( & V_33 , V_13 ) ;
if ( V_32 )
F_8 ( V_32 ) ;
}
static void F_25 ( struct V_37 * V_38 , struct V_23 * V_26 )
{
if ( V_38 ) {
struct V_21 V_39 ;
struct V_1 * V_5 = V_38 -> V_5 ;
F_13 ( & V_39 ) ;
if ( V_26 -> V_40 & V_41 )
F_26 ( V_38 -> V_42 , V_26 -> V_43 ) ;
F_27 ( & V_5 -> V_44 ) ;
F_28 ( & V_26 -> V_27 , & V_39 ) ;
F_29 ( & V_39 , & V_5 -> V_45 ) ;
F_30 ( & V_5 -> V_44 ) ;
}
F_21 ( V_35 , L_2 ) ;
F_9 ( V_26 ) ;
}
static void F_31 ( struct V_37 * V_38 ,
struct V_23 * V_26 ,
struct V_30 * V_30 )
{
int V_46 , V_47 , V_48 ;
V_46 = V_26 -> V_29 [ V_26 -> V_49 ] ;
if ( V_46 <= V_30 -> V_50 )
V_47 = V_46 ;
else
V_47 = V_30 -> V_50 ;
if ( ++ V_26 -> V_49 == V_26 -> V_24 )
V_26 -> V_49 = 0 ;
V_48 = V_26 -> V_24 - V_26 -> V_49 ;
if ( V_48 >= V_47 )
V_48 = V_47 ;
memcpy ( V_30 -> V_51 , & V_26 -> V_29 [ V_26 -> V_49 ] , V_48 ) ;
if ( V_48 < V_47 ) {
memcpy ( ( V_30 -> V_51 + V_48 ) , V_26 -> V_29 ,
( V_47 - V_48 ) ) ;
V_26 -> V_49 = V_47 - V_48 ;
} else {
V_26 -> V_49 += V_48 ;
}
V_30 -> V_52 = V_47 ;
if ( V_26 -> V_49 == V_26 -> V_24 )
V_26 -> V_49 = 0 ;
V_26 -> V_53 -- ;
F_21 ( V_35 , L_3 ,
V_47 ) ;
F_17 ( V_38 -> V_5 -> V_3 , V_30 , 0 ) ;
}
static int F_32 ( struct V_37 * V_38 , T_1 V_54 , int V_55 ,
struct V_30 * V_30 , T_1 V_56 )
{
struct V_11 * V_12 ;
struct V_23 * V_26 = NULL ;
int V_57 = 0 ;
if ( V_54 >= V_58 ) {
F_21 ( V_35 , L_4 , V_59 ) ;
return - V_60 ;
}
V_12 = F_3 () ;
if ( ! V_12 )
return - V_61 ;
V_12 -> V_62 = 0 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_56 = V_56 ;
V_12 -> V_43 = V_54 ;
F_27 ( & V_38 -> V_5 -> V_44 ) ;
if ( V_30 -> V_63 ) {
F_30 ( & V_38 -> V_5 -> V_44 ) ;
F_21 ( V_35 , L_5 , V_30 ) ;
F_17 ( V_38 -> V_5 -> V_3 , V_30 , 0 ) ;
F_8 ( V_12 ) ;
return 0 ;
}
if ( V_55 )
V_26 = V_38 -> V_64 [ V_54 ] ;
else
V_26 = V_38 -> V_65 [ V_54 ] ;
if ( ! V_26 ) {
V_57 = - V_61 ;
goto V_66;
}
if ( ( ( V_26 -> V_67 & V_68 ) == V_69 )
&& V_26 -> V_53 > 0 ) {
F_8 ( V_12 ) ;
F_30 ( & V_38 -> V_5 -> V_44 ) ;
F_31 ( V_38 , V_26 , V_30 ) ;
return 0 ;
}
if ( V_38 -> V_42 ) {
F_33 ( & V_12 -> V_16 , & V_26 -> V_27 ) ;
if ( ! V_55 && V_54 && ( V_26 -> V_28 < 0 ) ) {
F_34 ( & V_26 -> V_70 ) ;
V_26 -> V_28 = 0 ;
}
} else {
V_57 = - V_71 ;
}
V_66:
F_30 ( & V_38 -> V_5 -> V_44 ) ;
if ( V_57 )
F_8 ( V_12 ) ;
return V_57 ;
}
static int F_35 ( struct V_37 * V_38 , T_1 V_54 , int V_55 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_23 * V_26 ;
F_27 ( & V_38 -> V_5 -> V_44 ) ;
if ( V_55 )
V_26 = V_38 -> V_64 [ V_54 ] ;
else
V_26 = V_38 -> V_65 [ V_54 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_16 ( V_22 ) ;
break;
}
V_12 = NULL ;
}
}
F_30 ( & V_38 -> V_5 -> V_44 ) ;
if ( V_12 )
F_8 ( V_12 ) ;
return V_12 ? 0 : - V_72 ;
}
static struct V_30 * F_36 ( struct V_37 * V_38 , int V_73 ,
T_1 V_56 )
{
struct V_1 * V_5 = V_38 -> V_5 ;
struct V_30 * V_30 = NULL ;
struct V_11 * V_12 ;
struct V_23 * V_26 ;
F_27 ( & V_5 -> V_44 ) ;
V_26 = V_38 -> V_65 [ V_73 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_56 == V_56 ) {
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
break;
}
}
}
F_30 ( & V_5 -> V_44 ) ;
if ( V_30 )
F_8 ( V_12 ) ;
return V_30 ;
}
static void F_37 ( struct V_37 * V_38 , void * V_42 )
{
F_13 ( & V_38 -> V_74 ) ;
F_13 ( & V_38 -> V_75 ) ;
V_38 -> V_40 |= V_76 | V_77 ;
V_38 -> V_31 |= V_78 |
( V_79 << 16 ) ;
F_38 ( V_42 ) ;
V_38 -> V_42 = V_42 ;
}
static struct V_1 * F_39 ( void )
{
struct V_1 * V_5 ;
F_27 ( & V_80 ) ;
V_5 = V_81 ;
if ( V_5 )
F_40 ( V_5 -> V_3 ) ;
F_30 ( & V_80 ) ;
return V_5 ;
}
static inline void F_41 ( struct V_1 * V_5 )
{
if ( V_5 )
F_42 ( V_5 -> V_3 ) ;
}
struct V_37 * F_43 ( void * V_42 )
{
int V_7 ;
struct V_37 * V_82 ;
struct V_1 * V_5 ;
struct V_23 * V_26 ;
V_5 = F_39 () ;
if ( ! V_5 )
return NULL ;
V_26 = F_11 ( 0 , V_19 ) ;
if ( ! V_26 )
goto V_83;
F_27 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_10 >= 0 )
goto V_84;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_37 * V_38 = & V_5 -> V_9 [ V_7 ] ;
F_24 ( & V_38 -> V_85 ) ;
if ( ! ( V_38 -> V_40 & ( V_76 | V_77 ) ) ) {
F_37 ( V_38 , V_42 ) ;
F_19 ( & V_38 -> V_85 ) ;
break;
}
F_19 ( & V_38 -> V_85 ) ;
}
if ( V_7 == V_8 )
goto V_84;
V_5 -> V_10 = V_7 ;
V_82 = & V_5 -> V_9 [ V_7 ] ;
V_82 -> V_65 [ 0 ] = V_26 ;
F_30 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_40 & V_86 )
F_44 ( V_5 -> V_3 ) ;
F_45 ( V_5 -> V_3 ) ;
F_41 ( V_5 ) ;
return V_82 ;
V_84:
F_30 ( & V_5 -> V_44 ) ;
F_25 ( NULL , V_26 ) ;
V_83:
F_41 ( V_5 ) ;
return NULL ;
}
void F_46 ( struct V_37 * V_38 )
{
struct V_1 * V_5 ;
void * V_42 ;
struct V_23 * V_26 = NULL ;
if ( V_38 == NULL ) {
F_21 ( V_35 , L_6 , V_59 ) ;
return;
}
V_5 = V_38 -> V_5 ;
if ( V_5 == NULL )
return;
F_27 ( & V_5 -> V_44 ) ;
if ( ( V_5 -> V_10 >= 0 ) &&
( V_38 == & V_5 -> V_9 [ V_5 -> V_10 ] ) ) {
F_21 ( V_35 , L_7 ) ;
V_5 -> V_10 = - 1 ;
}
F_24 ( & V_38 -> V_85 ) ;
V_38 -> V_40 |= V_87 ;
F_19 ( & V_38 -> V_85 ) ;
F_30 ( & V_5 -> V_44 ) ;
F_47 ( V_5 -> V_3 , V_38 ) ;
F_27 ( & V_38 -> V_85 ) ;
V_42 = V_38 -> V_42 ;
V_38 -> V_42 = NULL ;
V_38 -> V_6 = 0xff ;
V_38 -> V_88 = 0 ;
V_38 -> V_40 &= ~ ( V_76 | V_87 ) ;
V_38 -> V_40 |= V_77 ;
V_38 -> V_31 &= ~ ( V_78 | V_89 ) ;
V_38 -> V_31 |= ( V_79 << 16 ) ;
if ( V_38 -> V_65 [ 0 ] ) {
V_26 = V_38 -> V_65 [ 0 ] ;
V_38 -> V_65 [ 0 ] = NULL ;
}
F_30 ( & V_38 -> V_85 ) ;
if ( V_26 )
F_25 ( V_38 , V_26 ) ;
F_45 ( V_5 -> V_3 ) ;
F_48 ( V_42 ) ;
}
void F_49 ( void * V_42 , void * V_82 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
struct V_1 * V_5 = V_38 -> V_5 ;
F_21 ( V_35 , L_8 ) ;
F_27 ( & V_38 -> V_85 ) ;
V_38 -> V_40 |= V_77 ;
V_38 -> V_31 |= V_90 ;
V_38 -> V_31 |= ( V_91 << 16 ) ;
F_30 ( & V_38 -> V_85 ) ;
F_47 ( V_5 -> V_3 , V_38 ) ;
F_45 ( V_5 -> V_3 ) ;
}
void F_50 ( void * V_82 , T_1 V_56 , int V_31 , const T_1 * V_92 ,
int V_93 , int V_94 , int V_95 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
struct V_30 * V_30 ;
int V_57 = 0 ;
F_21 ( V_35 , L_9 ,
V_93 , V_94 , V_95 ) ;
V_30 = F_36 ( V_38 , 0 , V_56 ) ;
if ( ! V_30 )
return;
if ( V_31 == 0 ) {
int V_48 ;
int V_96 = V_30 -> V_50 ;
if ( V_96 > V_95 )
V_96 = V_95 ;
V_48 = V_96 - V_94 ;
if ( V_93 <= V_48 )
V_48 = V_93 ;
memcpy ( V_30 -> V_51 + V_94 , V_92 , V_48 ) ;
V_94 += V_48 ;
if ( V_94 < V_96 ) {
struct V_97 * V_98 =
(struct V_97 * ) V_30 -> V_99 ;
unsigned V_100 = F_51 ( V_98 -> V_101 ) ;
if ( F_32 ( V_38 , 0 , 0 , V_30 , V_56 ) )
V_57 = - V_61 ;
else if ( F_52 ( V_38 -> V_42 , V_56 ,
V_98 -> V_102 , ( T_1 ) ( V_100 >> 8 ) ,
( T_1 ) V_100 , V_98 -> V_103 , V_94 ,
V_96 - V_94 ) ) {
F_35 ( V_38 , 0 , 0 , V_30 ) ;
V_57 = - V_61 ;
}
if ( V_57 == 0 )
return;
}
}
V_30 -> V_52 = V_95 ;
F_17 ( V_38 -> V_5 -> V_3 , V_30 , 0 ) ;
}
static void F_53 ( T_1 V_104 )
{
switch ( V_104 ) {
case V_105 :
F_21 ( V_35 , L_10 ) ;
break;
case V_106 :
F_21 ( V_35 , L_11 ) ;
break;
case V_107 :
F_21 ( V_35 , L_12 ) ;
break;
case V_108 :
F_21 ( V_35 , L_13 ) ;
break;
case V_109 :
F_21 ( V_35 , L_14 ) ;
break;
case V_110 :
F_21 ( V_35 , L_15 ) ;
break;
case V_111 :
F_21 ( V_35 , L_16 ) ;
break;
case V_112 :
F_21 ( V_35 , L_17 ) ;
break;
case V_113 :
F_21 ( V_35 , L_18 ) ;
break;
case V_114 :
F_21 ( V_35 , L_19 ) ;
break;
case V_115 :
F_21 ( V_35 , L_20 ) ;
break;
}
}
static void F_54 ( struct V_37 * V_38 , struct V_30 * V_30 ,
T_1 V_116 , T_1 V_88 )
{
int V_117 = 0 ;
struct V_2 * V_3 = V_38 -> V_5 -> V_3 ;
if ( V_116 == 0 ) {
V_38 -> V_88 = V_88 ;
F_47 ( V_3 , V_38 ) ;
if ( F_55 ( V_3 , V_38 ,
& V_30 -> V_118 -> V_119 [ V_38 -> V_88 - 1 ] , V_19 ) ) {
V_117 = - V_61 ;
}
} else {
V_117 = - V_61 ;
}
F_17 ( V_3 , V_30 , V_117 ) ;
}
static void F_56 ( struct V_37 * V_38 , struct V_30 * V_30 ,
T_1 V_116 , T_1 V_120 , T_1 V_121 )
{
struct V_2 * V_3 = V_38 -> V_5 -> V_3 ;
int V_117 = 0 ;
if ( ( V_116 == 0 ) && ( V_38 -> V_88 > 0 ) ) {
struct V_122 * V_119 ;
struct V_123 * V_124 ;
F_21 ( V_35 , L_21 , V_120 , V_121 ) ;
F_57 ( V_3 , V_38 , V_120 ) ;
V_119 = & V_30 -> V_118 -> V_119 [ V_38 -> V_88 - 1 ] ;
V_124 = & V_119 -> V_125 [ V_120 ] -> V_126 [ V_121 ] ;
if ( F_58 ( V_3 , V_38 , V_124 ,
V_19 ) )
V_117 = - V_61 ;
else
V_38 -> V_127 [ V_120 ] . V_121 = V_121 ;
} else {
V_117 = - V_61 ;
}
F_17 ( V_3 , V_30 , V_117 ) ;
}
void F_59 ( void * V_82 , T_1 V_56 , T_1 V_116 , const T_1 * V_128 ,
int V_46 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
struct V_30 * V_30 ;
struct V_97 * V_98 ;
struct V_2 * V_3 = V_38 -> V_5 -> V_3 ;
unsigned V_129 ;
unsigned V_100 ;
F_21 ( V_35 , L_22 , V_116 , V_46 ) ;
V_30 = F_36 ( V_38 , 0 , V_56 ) ;
if ( ! V_30 ) {
F_21 ( V_35 , L_23 ) ;
return;
}
V_98 = (struct V_97 * ) V_30 -> V_99 ;
V_129 = F_51 ( V_98 -> V_103 ) ;
V_100 = F_51 ( V_98 -> V_101 ) ;
if ( ( V_98 -> V_102 & V_130 ) == V_131 ) {
F_53 ( V_98 -> V_132 ) ;
switch ( V_98 -> V_132 ) {
case V_112 :
F_54 ( V_38 , V_30 , V_116 ,
( T_1 ) V_100 ) ;
break;
case V_114 :
F_56 ( V_38 , V_30 , V_116 ,
( T_1 ) V_129 , ( T_1 ) V_100 ) ;
break;
default:
F_17 ( V_3 , V_30 , 0 ) ;
}
} else {
int V_48 ;
F_21 ( V_35 , L_24 ) ;
if ( V_46 ) {
if ( V_46 <= V_30 -> V_50 )
V_48 = V_46 ;
else
V_48 = V_30 -> V_50 ;
memcpy ( V_30 -> V_51 , V_128 , V_48 ) ;
V_30 -> V_52 = V_48 ;
}
F_17 ( V_3 , V_30 , 0 ) ;
}
}
static int F_60 ( struct V_23 * V_26 , const T_1 * V_128 ,
int V_46 )
{
int V_133 ;
int V_48 ;
if ( ! V_26 -> V_29 )
return - 1 ;
V_133 = V_26 -> V_49 - V_26 -> V_134 - 1 ;
if ( V_133 < 0 )
V_133 += V_26 -> V_24 ;
if ( V_133 < ( V_46 + 1 ) ) {
F_21 ( V_35 , L_25 ) ;
return - 1 ;
}
V_26 -> V_29 [ V_26 -> V_134 ] = ( T_1 ) V_46 ;
if ( ++ V_26 -> V_134 == V_26 -> V_24 )
V_26 -> V_134 = 0 ;
V_48 = V_26 -> V_24 - V_26 -> V_134 ;
if ( V_48 > V_46 )
V_48 = V_46 ;
memcpy ( & V_26 -> V_29 [ V_26 -> V_134 ] , V_128 , V_48 ) ;
if ( V_48 < V_46 ) {
memcpy ( V_26 -> V_29 , V_128 + V_48 , V_46 - V_48 ) ;
V_26 -> V_134 = V_46 - V_48 ;
} else {
V_26 -> V_134 += V_48 ;
}
if ( V_26 -> V_134 == V_26 -> V_24 )
V_26 -> V_134 = 0 ;
V_26 -> V_53 ++ ;
return 0 ;
}
void F_61 ( void * V_82 , T_1 V_135 , const T_1 * V_128 , int V_46 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
struct V_23 * V_26 ;
struct V_1 * V_5 = V_38 -> V_5 ;
F_27 ( & V_5 -> V_44 ) ;
V_26 = V_38 -> V_64 [ V_135 & V_136 ] ;
if ( V_26 == NULL )
goto V_137;
switch ( V_26 -> V_67 & V_68 ) {
case V_69 :
case V_138 :
if ( ! F_62 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_63 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 ;
int V_48 ;
F_16 ( & V_12 -> V_16 ) ;
F_30 ( & V_5 -> V_44 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
if ( V_46 <= V_30 -> V_50 )
V_48 = V_46 ;
else
V_48 = V_30 -> V_50 ;
memcpy ( V_30 -> V_51 , V_128 , V_48 ) ;
V_30 -> V_52 = V_48 ;
F_17 ( V_38 -> V_5 -> V_3 , V_30 , 0 ) ;
return;
} else {
F_21 ( V_35 , L_26 ) ;
F_60 ( V_26 , V_128 , V_46 ) ;
}
break;
case V_139 :
F_60 ( V_26 , V_128 , V_46 ) ;
break;
}
V_137:
F_30 ( & V_5 -> V_44 ) ;
}
static inline int F_64 ( void )
{
return F_65 ( & V_140 ) ;
}
int F_66 ( void * V_82 )
{
int V_117 = 0 ;
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
struct V_1 * V_5 = V_38 -> V_5 ;
struct V_11 * V_12 ;
struct V_21 V_141 ;
struct V_21 * V_22 ;
struct V_21 * V_142 ;
struct V_30 * V_30 ;
struct V_23 * V_26 ;
struct V_143 V_144 , V_145 ;
F_34 ( & V_144 ) ;
F_13 ( & V_141 ) ;
F_27 ( & V_5 -> V_44 ) ;
F_15 (e, &port->isoc_out_ep) {
V_26 = F_67 ( V_22 ) ;
if ( V_26 -> V_28 < 0 )
continue;
V_145 = F_68 ( V_144 , V_26 -> V_70 ) ;
V_26 -> V_28 += F_69 ( F_70 ( & V_145 ) , V_146 ) ;
if ( V_26 -> V_28 > V_26 -> V_147 )
V_26 -> V_28 = V_26 -> V_147 ;
V_26 -> V_70 = V_144 ;
while ( V_26 -> V_28 && ! F_62 ( & V_26 -> V_27 ) ) {
V_12 = F_63 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
if ( ( V_26 -> V_28 + 1 ) < V_30 -> V_148 )
break;
V_26 -> V_28 -= V_30 -> V_148 ;
if ( V_26 -> V_28 < 0 )
V_26 -> V_28 = 0 ;
F_71 ( & V_12 -> V_16 , & V_141 ) ;
}
}
F_30 ( & V_5 -> V_44 ) ;
F_72 (e, n, &xfr_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
V_30 -> V_149 = 0 ;
V_30 -> V_150 = F_64 () ;
F_73 ( V_38 -> V_42 , V_12 -> V_43 , V_30 ) ;
F_8 ( V_12 ) ;
F_17 ( V_38 -> V_5 -> V_3 , V_30 , 0 ) ;
}
F_27 ( & V_5 -> V_44 ) ;
F_15 (e, &port->isoc_in_ep) {
struct V_23 * V_26 = F_67 ( V_22 ) ;
if ( V_26 -> V_40 & V_151 ) {
if ( V_26 -> V_53 >= V_152 ) {
V_26 -> V_40 &= ~ V_151 ;
V_26 -> V_28 = 0 ;
V_26 -> V_70 = V_144 ;
V_26 -> V_150 = 0 ;
}
continue;
}
V_145 = F_68 ( V_144 , V_26 -> V_70 ) ;
V_26 -> V_28 += F_69 ( F_70 ( & V_145 ) , V_146 ) ;
V_26 -> V_70 = V_144 ;
while ( ! F_62 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_63 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 = V_12 -> V_30 ;
int V_153 = 0 ;
int V_48 ;
int V_7 ;
if ( V_26 -> V_28 < V_30 -> V_148 )
break;
if ( V_26 -> V_53 < V_30 -> V_148 )
break;
V_30 -> V_52 = 0 ;
for ( V_7 = 0 ; V_7 < V_30 -> V_148 ; V_7 ++ ) {
V_153 = V_26 -> V_29 [ V_26 -> V_49 ] ;
if ( ++ V_26 -> V_49 == V_26 -> V_24 )
V_26 -> V_49 = 0 ;
V_48 = V_26 -> V_24 - V_26 -> V_49 ;
if ( V_48 > V_153 )
V_48 = V_153 ;
memcpy ( V_30 -> V_51 ,
& V_26 -> V_29 [ V_26 -> V_49 ] , V_48 ) ;
if ( V_48 < V_153 ) {
memcpy ( V_30 -> V_51 + V_48 ,
V_26 -> V_29 , V_153 - V_48 ) ;
V_26 -> V_49 = V_153 - V_48 ;
} else
V_26 -> V_49 += V_48 ;
if ( V_26 -> V_49 == V_26 -> V_24 )
V_26 -> V_49 = 0 ;
V_30 -> V_154 [ V_7 ] . V_94 =
V_30 -> V_52 ;
V_30 -> V_52 += V_153 ;
V_30 -> V_154 [ V_7 ] . V_52 = V_153 ;
V_30 -> V_154 [ V_7 ] . V_31 = 0 ;
}
V_26 -> V_53 -= V_30 -> V_148 ;
V_30 -> V_149 = 0 ;
V_30 -> V_150 = V_26 -> V_150 ;
V_26 -> V_150 += V_30 -> V_148 ;
F_71 ( & V_12 -> V_16 , & V_141 ) ;
V_26 -> V_28 -= V_30 -> V_148 ;
}
}
if ( ! F_62 ( & V_38 -> V_74 ) || ! F_62 ( & V_38 -> V_75 ) )
V_117 = 1 ;
F_30 ( & V_5 -> V_44 ) ;
F_72 (e, n, &xfr_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
F_8 ( V_12 ) ;
F_17 ( V_38 -> V_5 -> V_3 , V_30 , 0 ) ;
}
V_26 = V_38 -> V_65 [ 0 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
struct V_21 * V_142 ;
F_27 ( & V_5 -> V_44 ) ;
F_72 (e, n, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_62 > V_155 ) {
F_21 ( V_35 , L_27 , V_12 -> V_30 ) ;
F_71 ( V_22 , & V_141 ) ;
V_12 -> V_62 = 0 ;
} else {
V_12 -> V_62 ++ ;
}
}
if ( ! F_62 ( & V_26 -> V_27 ) )
V_117 = 1 ;
F_30 ( & V_5 -> V_44 ) ;
V_22 = V_141 . V_17 ;
while ( V_22 != & V_141 ) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_22 = V_22 -> V_17 ;
F_21 ( V_35 , L_28 ) ;
F_74 ( V_5 , V_12 -> V_30 , V_19 ) ;
F_8 ( V_12 ) ;
}
}
return V_117 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_123 * V_124 , T_2 V_25 )
{
struct V_1 * V_5 = V_38 -> V_5 ;
int V_7 ;
int V_156 = V_124 -> V_92 . V_157 ;
int V_158 = 0 ;
F_21 ( V_35 , L_29 , V_156 , V_124 ) ;
if ( V_156 >= V_38 -> V_159 || V_38 -> V_127 == NULL )
return - V_61 ;
for ( V_7 = 0 ; V_7 < V_124 -> V_92 . V_160 ; V_7 ++ ) {
struct V_161 * V_162 = & V_124 -> V_135 [ V_7 ] ;
T_1 V_54 = V_162 -> V_92 . V_163 ;
T_1 V_43 = V_54 & V_136 ;
struct V_23 * V_26 ;
int V_24 = 0 ;
F_21 ( V_35 , L_30 , V_7 , V_54 ) ;
if ( V_54 & V_164 ) {
switch ( V_162 -> V_92 . V_165 &
V_68 ) {
case V_139 :
V_24 = V_166 ;
break;
case V_69 :
V_24 = V_167 ;
break;
}
}
V_26 = F_11 ( V_24 , V_25 ) ;
if ( ! V_26 ) {
F_57 ( V_3 , V_38 , V_156 ) ;
return - V_61 ;
}
V_26 -> V_67 = V_162 -> V_92 . V_165 ;
V_26 -> V_43 = V_43 ;
if ( ( V_26 -> V_67 & V_68 )
== V_139 ) {
F_21 ( V_35 , L_31 ,
F_75 ( & V_162 -> V_92 ) ) ;
V_26 -> V_147 = 200 ;
if ( V_54 & V_164 ) {
V_26 -> V_40 |= V_151 ;
} else {
V_26 -> V_40 |= V_41 ;
if ( F_76 ( V_38 -> V_42 , V_43 ) )
V_26 -> V_40 &= ~ V_41 ;
}
}
F_27 ( & V_5 -> V_44 ) ;
if ( V_54 & V_164 ) {
V_38 -> V_64 [ V_43 ] = V_26 ;
V_38 -> V_127 [ V_156 ] . V_168 |=
( 1 << ( V_43 + V_58 ) ) ;
if ( ( V_26 -> V_67 & V_68 )
== V_139 ) {
F_33 ( & V_26 -> V_16 , & V_38 -> V_75 ) ;
V_158 = 1 ;
}
} else {
V_38 -> V_65 [ V_43 ] = V_26 ;
V_38 -> V_127 [ V_156 ] . V_168 |= ( 1 << V_43 ) ;
if ( ( V_26 -> V_67 & V_68 )
== V_139 ) {
F_33 ( & V_26 -> V_16 , & V_38 -> V_74 ) ;
V_158 = 1 ;
}
}
F_30 ( & V_5 -> V_44 ) ;
if ( V_158 && V_38 -> V_42 )
F_77 ( V_38 -> V_42 ) ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 ,
struct V_37 * V_38 , int V_156 )
{
struct V_1 * V_5 = V_38 -> V_5 ;
unsigned V_169 ;
int V_7 ;
struct V_21 V_170 ;
F_21 ( V_35 , L_32 , V_156 ) ;
if ( V_156 >= V_38 -> V_159 )
return;
F_13 ( & V_170 ) ;
F_27 ( & V_5 -> V_44 ) ;
V_169 = V_38 -> V_127 [ V_156 ] . V_168 ;
V_38 -> V_127 [ V_156 ] . V_168 = 0 ;
for ( V_7 = 0 ; V_7 < V_58 ; V_7 ++ ) {
struct V_21 * V_22 ;
if ( ( V_169 & ( 1 << V_7 ) ) && V_38 -> V_65 [ V_7 ] ) {
V_22 = & V_38 -> V_65 [ V_7 ] -> V_16 ;
V_38 -> V_65 [ V_7 ] = NULL ;
F_71 ( V_22 , & V_170 ) ;
}
if ( ( V_169 & ( 1 << ( V_7 + V_58 ) ) ) && V_38 -> V_64 [ V_7 ] ) {
V_22 = & V_38 -> V_64 [ V_7 ] -> V_16 ;
V_38 -> V_64 [ V_7 ] = NULL ;
F_71 ( V_22 , & V_170 ) ;
}
}
F_30 ( & V_5 -> V_44 ) ;
while ( ! F_62 ( & V_170 ) ) {
struct V_23 * V_26 =
F_63 ( & V_170 , struct V_23 , V_16 ) ;
F_16 ( & V_26 -> V_16 ) ;
F_25 ( V_38 , V_26 ) ;
}
}
static int F_55 ( struct V_2 * V_3 ,
struct V_37 * V_38 , struct V_122 * V_119 ,
T_2 V_25 )
{
struct V_1 * V_5 = V_38 -> V_5 ;
int V_7 ;
int V_159 = V_119 -> V_92 . V_171 ;
if ( V_159 ) {
struct V_172 * V_127 ;
V_127 = F_7 ( V_159 * sizeof( struct V_172 ) ,
V_25 | V_173 ) ;
if ( ! V_127 )
return - V_61 ;
F_27 ( & V_5 -> V_44 ) ;
V_38 -> V_127 = V_127 ;
V_38 -> V_159 = V_159 ;
F_30 ( & V_5 -> V_44 ) ;
}
for ( V_7 = 0 ; V_7 < V_159 ; V_7 ++ ) {
struct V_123 * V_124 =
& V_119 -> V_125 [ V_7 ] -> V_126 [ 0 ] ;
if ( F_58 ( V_3 , V_38 , V_124 ,
V_25 ) )
goto V_174;
}
return 0 ;
V_174:
F_47 ( V_3 , V_38 ) ;
return - 1 ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_1 * V_5 = V_38 -> V_5 ;
int V_7 ;
F_21 ( V_35 , L_33 ) ;
for ( V_7 = 0 ; V_7 < V_38 -> V_159 ; V_7 ++ )
F_57 ( V_3 , V_38 , V_7 ) ;
F_27 ( & V_5 -> V_44 ) ;
if ( V_38 -> V_127 ) {
F_21 ( V_35 , L_34 ) ;
F_9 ( V_38 -> V_127 ) ;
V_38 -> V_127 = NULL ;
}
V_38 -> V_159 = 0 ;
F_30 ( & V_5 -> V_44 ) ;
}
static void * F_78 ( struct V_37 * V_38 )
{
void * V_42 ;
struct V_1 * V_5 = V_38 -> V_5 ;
F_27 ( & V_5 -> V_44 ) ;
V_42 = V_38 -> V_42 ;
if ( V_42 )
F_38 ( V_42 ) ;
F_30 ( & V_5 -> V_44 ) ;
return V_42 ;
}
static void F_74 ( struct V_1 * V_5 , struct V_30 * V_30 ,
T_2 V_25 )
{
struct V_97 * V_98 ;
unsigned V_129 ;
unsigned V_100 ;
unsigned V_175 ;
void * V_42 ;
T_1 V_56 ;
int V_117 = 0 ;
unsigned V_176 = 0 ;
int V_177 = - 1 ;
struct V_37 * V_38 = NULL ;
F_21 ( V_178 , L_35 , V_59 , V_30 ) ;
V_177 = F_2 ( V_5 , V_30 -> V_118 -> V_179 ) ;
if ( V_177 < 0 ) {
V_117 = - V_71 ;
goto V_66;
}
V_38 = & V_5 -> V_9 [ V_177 ] ;
if ( ( ( V_38 -> V_40 & V_76 ) == 0 )
|| ( V_38 -> V_40 & V_87 ) ) {
F_21 ( V_35 , L_36 ,
V_177 , V_30 -> V_118 -> V_179 ) ;
V_117 = - V_71 ;
goto V_66;
}
V_30 -> V_34 = V_38 ;
V_98 = (struct V_97 * ) V_30 -> V_99 ;
V_129 = F_51 ( V_98 -> V_103 ) ;
V_100 = F_51 ( V_98 -> V_101 ) ;
V_175 = F_51 ( V_98 -> V_180 ) ;
F_21 ( V_181 , L_37 , V_98 -> V_102 ) ;
F_21 ( V_181 , L_38 , V_98 -> V_132 ) ;
F_21 ( V_181 , L_39 , V_100 ) ;
F_21 ( V_181 , L_40 , V_129 ) ;
F_21 ( V_181 , L_41 , V_175 ) ;
V_56 = V_38 -> V_182 ++ ;
V_42 = F_78 ( V_38 ) ;
if ( V_42 == NULL ) {
F_21 ( V_35 , L_42 ) ;
V_117 = - V_71 ;
goto V_66;
}
if ( ( V_98 -> V_102 & V_130 ) == V_131 ) {
switch ( V_98 -> V_132 ) {
case V_109 :
F_21 ( V_35 , L_43 ) ;
break;
case V_108 :
F_21 ( V_35 , L_44 ) ;
F_21 ( V_35 , L_45 ,
V_5 -> V_10 ,
( T_1 ) F_51 ( V_98 -> V_101 ) ) ;
F_27 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_10 >= 0 ) {
V_5 -> V_9 [ V_5 -> V_10 ] . V_6 =
( T_1 ) F_51 ( V_98 -> V_101 ) ;
F_21 ( V_35 , L_7 ) ;
V_5 -> V_10 = - 1 ;
}
F_30 ( & V_5 -> V_44 ) ;
V_176 = 1 ;
break;
case V_112 :
F_21 ( V_35 , L_46 ) ;
break;
case V_111 :
F_21 ( V_35 , L_47 ) ;
if ( V_30 -> V_50 >= 1 ) {
V_30 -> V_52 = 1 ;
* ( ( T_1 * ) V_30 -> V_51 ) =
V_38 -> V_88 ;
V_176 = 1 ;
} else {
V_117 = - V_71 ;
}
break;
case V_113 :
F_21 ( V_35 , L_48 ) ;
if ( V_30 -> V_50 >= 1 ) {
V_30 -> V_52 = 1 ;
* ( ( T_1 * ) V_30 -> V_51 ) =
V_38 -> V_127 [ ( T_1 ) V_129 ] . V_121 ;
F_21 ( V_35 , L_49 ,
V_129 , V_38 -> V_127 [ ( T_1 ) V_129 ] . V_121 ) ;
V_176 = 1 ;
} else {
V_117 = - V_71 ;
}
break;
case V_114 :
F_21 ( V_35 , L_50 ) ;
break;
}
}
if ( ! V_117 && ! V_176 ) {
int V_46 = 0 ;
if ( ( V_98 -> V_102 & V_183 ) == 0 )
V_46 = V_175 ;
V_30 -> V_52 = V_46 ;
if ( F_79 ( V_38 -> V_42 , V_56 , V_98 ,
V_30 -> V_51 , V_46 ) ) {
V_117 = - V_61 ;
} else {
if ( F_32 ( V_38 , 0 , 0 , V_30 , V_56 ) )
V_117 = - V_61 ;
}
}
F_48 ( V_42 ) ;
V_66:
if ( V_117 || V_176 ) {
F_21 ( V_35 , L_51 ) ;
F_17 ( V_5 -> V_3 , V_30 , V_117 ) ;
} else {
F_77 ( V_38 -> V_42 ) ;
}
}
static int F_80 ( struct V_1 * V_5 , struct V_30 * V_30 )
{
int V_117 = 0 ;
struct V_37 * V_38 = V_30 -> V_34 ;
T_1 V_54 ;
F_81 ( V_30 ) ;
if ( ! V_30 -> V_51 && V_30 -> V_50 )
return - V_60 ;
if ( ( V_38 -> V_40 & V_76 ) == 0 )
return - V_71 ;
V_54 = F_82 ( V_30 -> V_184 ) ;
if ( V_54 ) {
if ( F_32 ( V_38 , V_54 , F_83 ( V_30 -> V_184 ) ,
V_30 , 0 ) )
V_117 = - V_71 ;
} else {
F_74 ( V_5 , V_30 , V_19 ) ;
}
return V_117 ;
}
static void F_84 ( unsigned long V_185 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_39 () ;
int V_117 = 0 ;
if ( V_5 == NULL )
return;
F_4 ( & V_33 , V_13 ) ;
while ( ! F_62 ( & V_5 -> V_186 ) ) {
struct V_11 * V_12 =
F_63 ( & V_5 -> V_186 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_33 , V_13 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
V_117 = F_80 ( V_5 , V_30 ) ;
if ( V_117 )
F_17 ( V_5 -> V_3 , V_30 , V_117 ) ;
F_4 ( & V_33 , V_13 ) ;
}
F_6 ( & V_33 , V_13 ) ;
F_41 ( V_5 ) ;
}
static void F_85 ( struct V_37 * V_38 , T_1 V_43 , struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_21 * V_22 ;
struct V_1 * V_5 ;
unsigned long V_13 ;
T_1 V_187 ;
if ( V_38 == NULL ) {
F_21 ( V_35 , L_52 , V_59 , V_30 ) ;
return;
}
V_5 = V_38 -> V_5 ;
if ( V_5 == NULL ) {
F_21 ( V_35 , L_53 , V_59 , V_30 ) ;
return;
}
F_4 ( & V_33 , V_13 ) ;
F_15 (e, &ozhcd->urb_cancel_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_30 == V_12 -> V_30 ) {
F_16 ( V_22 ) ;
F_6 ( & V_33 , V_13 ) ;
goto V_188;
}
}
F_6 ( & V_33 , V_13 ) ;
V_12 = NULL ;
F_4 ( & V_5 -> V_44 , V_13 ) ;
F_15 (e, &ozhcd->orphanage) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_86 ( V_22 ) ;
F_21 ( V_35 , L_54 ) ;
goto V_66;
}
}
V_187 = ( V_43 & 0xf ) ;
V_12 = NULL ;
if ( ( V_43 & V_183 ) && V_187 )
V_12 = F_87 ( V_38 -> V_64 [ V_187 ] , V_30 ) ;
else
V_12 = F_87 ( V_38 -> V_65 [ V_187 ] , V_30 ) ;
V_66:
F_6 ( & V_5 -> V_44 , V_13 ) ;
V_188:
if ( V_12 ) {
V_30 -> V_52 = 0 ;
F_8 ( V_12 ) ;
F_17 ( V_5 -> V_3 , V_30 , - V_71 ) ;
}
}
static void F_88 ( unsigned long V_185 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_39 () ;
if ( V_5 == NULL )
return;
F_4 ( & V_33 , V_13 ) ;
while ( ! F_62 ( & V_5 -> V_189 ) ) {
struct V_11 * V_12 =
F_63 ( & V_5 -> V_189 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_33 , V_13 ) ;
V_30 = V_12 -> V_30 ;
if ( V_30 -> V_63 )
F_85 ( V_12 -> V_38 , V_12 -> V_43 , V_30 ) ;
F_8 ( V_12 ) ;
F_4 ( & V_33 , V_13 ) ;
}
F_6 ( & V_33 , V_13 ) ;
F_41 ( V_5 ) ;
}
static void F_89 ( struct V_1 * V_5 , int V_31 )
{
if ( V_5 ) {
struct V_11 * V_12 ;
while ( ! F_62 ( & V_5 -> V_45 ) ) {
V_12 = F_63 ( & V_5 -> V_45 ,
struct V_11 , V_16 ) ;
F_86 ( & V_12 -> V_16 ) ;
F_17 ( V_5 -> V_3 , V_12 -> V_30 , V_31 ) ;
F_8 ( V_12 ) ;
}
}
}
static int F_90 ( struct V_2 * V_3 )
{
V_3 -> V_190 = 200 ;
V_3 -> V_191 = V_192 ;
V_3 -> V_193 = 1 ;
return 0 ;
}
static void F_91 ( struct V_2 * V_3 )
{
}
static void F_92 ( struct V_2 * V_3 )
{
}
static int F_93 ( struct V_2 * V_3 , struct V_30 * V_30 ,
T_2 V_25 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_117 ;
int V_177 ;
struct V_37 * V_38 ;
unsigned long V_13 ;
struct V_11 * V_12 ;
F_21 ( V_178 , L_55 , V_59 , V_30 ) ;
if ( F_94 ( V_5 == NULL ) ) {
F_21 ( V_178 , L_56 , V_30 ) ;
return - V_71 ;
}
if ( F_94 ( V_3 -> V_191 != V_192 ) ) {
F_21 ( V_178 , L_57 , V_30 ) ;
return - V_71 ;
}
V_177 = F_2 ( V_5 , V_30 -> V_118 -> V_179 ) ;
if ( V_177 < 0 )
return - V_71 ;
V_38 = & V_5 -> V_9 [ V_177 ] ;
if ( V_38 == NULL )
return - V_71 ;
if ( ! ( V_38 -> V_40 & V_76 ) ||
( V_38 -> V_40 & V_77 ) ) {
F_21 ( V_35 , L_36 ,
V_177 , V_30 -> V_118 -> V_179 ) ;
return - V_71 ;
}
V_30 -> V_34 = V_38 ;
V_12 = F_3 () ;
if ( F_94 ( V_12 == NULL ) )
return - V_61 ;
V_12 -> V_30 = V_30 ;
F_4 ( & V_33 , V_13 ) ;
V_117 = F_95 ( V_3 , V_30 ) ;
if ( F_94 ( V_117 ) ) {
F_6 ( & V_33 , V_13 ) ;
F_8 ( V_12 ) ;
return V_117 ;
}
F_33 ( & V_12 -> V_16 , & V_5 -> V_186 ) ;
F_6 ( & V_33 , V_13 ) ;
F_96 ( & V_194 ) ;
F_97 ( & V_36 ) ;
return 0 ;
}
static struct V_11 * F_87 ( struct V_23 * V_26 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 ;
struct V_21 * V_22 ;
if ( F_94 ( V_26 == NULL ) )
return NULL ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_16 ( V_22 ) ;
if ( F_98 ( V_30 -> V_184 ) ) {
V_26 -> V_28 -= V_30 -> V_148 ;
if ( V_26 -> V_28 < 0 )
V_26 -> V_28 = 0 ;
}
return V_12 ;
}
}
return NULL ;
}
static int F_99 ( struct V_2 * V_3 , struct V_30 * V_30 , int V_31 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_11 * V_12 ;
int V_117 ;
unsigned long V_13 ;
F_21 ( V_178 , L_55 , V_59 , V_30 ) ;
V_12 = F_3 () ;
if ( F_94 ( V_12 == NULL ) )
return - V_61 ;
F_4 ( & V_33 , V_13 ) ;
V_117 = F_100 ( V_3 , V_30 , V_31 ) ;
if ( ( V_117 == 0 ) && V_30 -> V_34 ) {
V_12 -> V_30 = V_30 ;
V_12 -> V_38 = (struct V_37 * ) V_30 -> V_34 ;
V_12 -> V_43 = F_82 ( V_30 -> V_184 ) ;
if ( F_83 ( V_30 -> V_184 ) )
V_12 -> V_43 |= V_183 ;
F_33 ( & V_12 -> V_16 , & V_5 -> V_189 ) ;
F_6 ( & V_33 , V_13 ) ;
F_96 ( & V_195 ) ;
} else {
F_6 ( & V_33 , V_13 ) ;
F_8 ( V_12 ) ;
}
return V_117 ;
}
static void F_101 ( struct V_2 * V_3 ,
struct V_161 * V_26 )
{
}
static void F_102 ( struct V_2 * V_3 ,
struct V_161 * V_26 )
{
}
static int F_103 ( struct V_2 * V_3 )
{
F_21 ( V_35 , L_58 ) ;
return F_64 () ;
}
static int F_104 ( struct V_2 * V_3 , char * V_196 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_7 ;
V_196 [ 0 ] = 0 ;
V_196 [ 1 ] = 0 ;
F_27 ( & V_5 -> V_44 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_5 -> V_9 [ V_7 ] . V_40 & V_77 ) {
F_21 ( V_197 , L_59 , V_7 ) ;
V_5 -> V_9 [ V_7 ] . V_40 &= ~ V_77 ;
if ( V_7 < 7 )
V_196 [ 0 ] |= 1 << ( V_7 + 1 ) ;
else
V_196 [ 1 ] |= 1 << ( V_7 - 7 ) ;
}
}
F_30 ( & V_5 -> V_44 ) ;
if ( V_196 [ 0 ] != 0 || V_196 [ 1 ] != 0 )
return 2 ;
else
return 0 ;
}
static void F_105 ( struct V_2 * V_3 ,
struct V_198 * V_92 )
{
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_199 = 0x29 ;
V_92 -> V_200 = 9 ;
V_92 -> V_201 = ( V_202 V_203 ) F_106 ( 0x0001 ) ;
V_92 -> V_204 = V_8 ;
}
static int F_107 ( struct V_2 * V_3 , T_3 V_100 , T_3 V_129 )
{
struct V_37 * V_38 ;
T_1 V_205 = ( T_1 ) V_129 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_206 = 0 ;
unsigned V_207 = 0 ;
if ( ( V_205 < 1 ) || ( V_205 > V_8 ) )
return - V_71 ;
V_38 = & V_5 -> V_9 [ V_205 - 1 ] ;
switch ( V_100 ) {
case V_208 :
F_21 ( V_197 , L_60 ) ;
break;
case V_209 :
F_21 ( V_197 , L_61 ) ;
break;
case V_210 :
F_21 ( V_197 , L_62 ) ;
break;
case V_211 :
F_21 ( V_197 , L_63 ) ;
break;
case V_212 :
F_21 ( V_197 , L_64 ) ;
V_206 = V_89 | ( V_91 << 16 ) ;
V_207 = V_90 ;
V_5 -> V_9 [ V_205 - 1 ] . V_6 = 0 ;
break;
case V_213 :
F_21 ( V_197 , L_65 ) ;
V_206 |= V_214 ;
break;
case V_215 :
F_21 ( V_197 , L_66 ) ;
break;
case V_216 :
F_21 ( V_197 , L_67 ) ;
break;
case V_217 :
F_21 ( V_197 , L_68 ) ;
break;
case V_218 :
F_21 ( V_197 , L_69 ) ;
break;
case V_219 :
F_21 ( V_197 , L_70 ) ;
break;
case V_220 :
F_21 ( V_197 , L_71 ) ;
break;
case V_221 :
F_21 ( V_197 , L_72 ) ;
break;
case V_222 :
F_21 ( V_197 , L_73 ) ;
break;
default:
F_21 ( V_197 , L_74 , V_100 ) ;
break;
}
if ( V_206 || V_207 ) {
F_27 ( & V_38 -> V_85 ) ;
V_38 -> V_31 &= ~ V_207 ;
V_38 -> V_31 |= V_206 ;
F_30 ( & V_38 -> V_85 ) ;
}
F_21 ( V_197 , L_75 , V_205 , V_38 -> V_31 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 , T_3 V_100 , T_3 V_129 )
{
struct V_37 * V_38 ;
T_1 V_205 = ( T_1 ) V_129 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_207 = 0 ;
if ( ( V_205 < 1 ) || ( V_205 > V_8 ) )
return - V_71 ;
V_38 = & V_5 -> V_9 [ V_205 - 1 ] ;
switch ( V_100 ) {
case V_208 :
F_21 ( V_197 , L_60 ) ;
break;
case V_209 :
F_21 ( V_197 , L_61 ) ;
V_207 = V_89 ;
break;
case V_210 :
F_21 ( V_197 , L_62 ) ;
break;
case V_211 :
F_21 ( V_197 , L_63 ) ;
break;
case V_212 :
F_21 ( V_197 , L_64 ) ;
break;
case V_213 :
F_21 ( V_197 , L_65 ) ;
V_207 |= V_214 ;
break;
case V_215 :
F_21 ( V_197 , L_66 ) ;
break;
case V_216 :
F_21 ( V_197 , L_67 ) ;
V_207 = ( V_79 << 16 ) ;
break;
case V_217 :
F_21 ( V_197 , L_68 ) ;
V_207 = ( V_223 << 16 ) ;
break;
case V_218 :
F_21 ( V_197 , L_69 ) ;
break;
case V_219 :
F_21 ( V_197 , L_70 ) ;
break;
case V_220 :
F_21 ( V_197 , L_71 ) ;
V_207 = ( V_220 << 16 ) ;
break;
case V_221 :
F_21 ( V_197 , L_72 ) ;
break;
case V_222 :
F_21 ( V_197 , L_73 ) ;
break;
default:
F_21 ( V_197 , L_74 , V_100 ) ;
break;
}
if ( V_207 ) {
F_27 ( & V_38 -> V_85 ) ;
V_38 -> V_31 &= ~ V_207 ;
F_30 ( & V_38 -> V_85 ) ;
}
F_21 ( V_197 , L_75 ,
V_205 , V_5 -> V_9 [ V_205 - 1 ] . V_31 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , T_3 V_129 , char * V_196 )
{
struct V_1 * V_5 ;
T_4 V_31 ;
if ( ( V_129 < 1 ) || ( V_129 > V_8 ) )
return - V_71 ;
V_5 = F_1 ( V_3 ) ;
F_21 ( V_197 , L_76 , V_129 ) ;
V_31 = V_5 -> V_9 [ V_129 - 1 ] . V_31 ;
F_110 ( F_111 ( V_31 ) , ( V_224 * ) V_196 ) ;
F_21 ( V_197 , L_77 , V_129 , V_31 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , T_3 V_225 , T_3 V_100 ,
T_3 V_129 , char * V_196 , T_3 V_175 )
{
int V_57 = 0 ;
switch ( V_225 ) {
case V_226 :
F_21 ( V_197 , L_78 , V_225 ) ;
break;
case V_227 :
V_57 = F_108 ( V_3 , V_100 , V_129 ) ;
break;
case V_228 :
F_105 ( V_3 , (struct V_198 * ) V_196 ) ;
break;
case V_229 :
F_21 ( V_197 , L_79 , V_225 ) ;
F_110 ( F_111 ( 0 ) , ( V_224 * ) V_196 ) ;
break;
case V_230 :
V_57 = F_109 ( V_3 , V_129 , V_196 ) ;
break;
case V_231 :
F_21 ( V_197 , L_80 , V_225 ) ;
break;
case V_232 :
V_57 = F_107 ( V_3 , V_100 , V_129 ) ;
break;
default:
F_21 ( V_197 , L_81 , V_225 ) ;
break;
}
return V_57 ;
}
static int F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 ) ;
F_27 ( & V_5 -> V_44 ) ;
V_3 -> V_191 = V_233 ;
V_5 -> V_40 |= V_86 ;
F_30 ( & V_5 -> V_44 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 ) ;
F_27 ( & V_5 -> V_44 ) ;
V_5 -> V_40 &= ~ V_86 ;
V_3 -> V_191 = V_192 ;
F_30 ( & V_5 -> V_44 ) ;
return 0 ;
}
static void F_115 ( struct V_234 * V_118 )
{
}
static int F_116 ( struct V_234 * V_118 )
{
int V_7 ;
int V_57 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
V_3 = F_117 ( & V_235 , & V_118 -> V_118 , F_118 ( & V_118 -> V_118 ) ) ;
if ( V_3 == NULL ) {
F_21 ( V_35 , L_82 ) ;
return - V_61 ;
}
V_5 = F_1 ( V_3 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_13 ( & V_5 -> V_186 ) ;
F_13 ( & V_5 -> V_189 ) ;
F_13 ( & V_5 -> V_45 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_10 = - 1 ;
F_119 ( & V_5 -> V_44 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_37 * V_38 = & V_5 -> V_9 [ V_7 ] ;
V_38 -> V_5 = V_5 ;
V_38 -> V_40 = 0 ;
V_38 -> V_31 = 0 ;
V_38 -> V_6 = 0xff ;
F_119 ( & V_38 -> V_85 ) ;
}
V_57 = F_120 ( V_3 , 0 , 0 ) ;
if ( V_57 ) {
F_21 ( V_35 , L_83 ) ;
F_42 ( V_3 ) ;
return - 1 ;
}
F_121 ( V_3 -> V_236 . V_237 ) ;
F_27 ( & V_80 ) ;
V_81 = V_5 ;
F_30 ( & V_80 ) ;
return 0 ;
}
static int F_122 ( struct V_234 * V_118 )
{
struct V_2 * V_3 = F_123 ( V_118 ) ;
struct V_1 * V_5 ;
if ( V_3 == NULL )
return - 1 ;
V_5 = F_1 ( V_3 ) ;
F_27 ( & V_80 ) ;
if ( V_5 == V_81 )
V_81 = NULL ;
F_30 ( & V_80 ) ;
F_21 ( V_35 , L_84 ) ;
F_89 ( V_5 , - V_71 ) ;
F_21 ( V_35 , L_85 ) ;
F_124 ( V_3 ) ;
F_42 ( V_3 ) ;
F_10 () ;
return 0 ;
}
static int F_125 ( struct V_234 * V_118 , T_5 V_238 )
{
return 0 ;
}
static int F_126 ( struct V_234 * V_118 )
{
return 0 ;
}
int F_127 ( void )
{
int V_57 ;
if ( F_128 () )
return - V_239 ;
F_129 ( & V_194 , F_84 , 0 ) ;
F_129 ( & V_195 , F_88 , 0 ) ;
V_57 = F_130 ( & V_240 ) ;
F_21 ( V_35 , L_86 , V_57 ) ;
if ( V_57 )
goto error;
V_241 = F_131 ( V_242 , - 1 ) ;
if ( V_241 == NULL ) {
V_57 = - V_61 ;
goto V_243;
}
F_21 ( V_35 , L_87 ) ;
V_57 = F_132 ( V_241 ) ;
if ( V_57 )
goto V_244;
F_21 ( V_35 , L_88 ) ;
return 0 ;
V_244:
F_133 ( V_241 ) ;
V_243:
F_134 ( & V_240 ) ;
error:
F_135 ( & V_194 ) ;
F_135 ( & V_195 ) ;
F_21 ( V_35 , L_89 , V_57 ) ;
return V_57 ;
}
void F_136 ( void )
{
F_137 ( V_245 ) ;
F_138 ( & V_194 ) ;
F_138 ( & V_195 ) ;
F_139 ( V_241 ) ;
F_134 ( & V_240 ) ;
F_21 ( V_35 , L_90 , F_140 ( & V_36 ) ) ;
}
