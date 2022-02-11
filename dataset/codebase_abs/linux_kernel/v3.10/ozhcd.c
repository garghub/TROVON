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
static struct V_11 * F_14 ( struct V_1 * V_5 , struct V_30 * V_30 )
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
int V_31 , unsigned long V_32 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_13 ;
struct V_11 * V_33 = NULL ;
F_4 ( & V_34 , V_13 ) ;
F_18 ( V_3 , V_30 ) ;
V_30 -> V_35 = NULL ;
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
static void F_34 ( struct V_41 * V_42 ,
struct V_23 * V_26 ,
struct V_30 * V_30 )
{
T_1 V_50 , V_51 , V_52 ;
memcpy ( & V_50 , & V_26 -> V_29 [ V_26 -> V_53 ] , sizeof( T_1 ) ) ;
if ( V_50 <= V_30 -> V_54 )
V_51 = V_50 ;
else
V_51 = V_30 -> V_54 ;
if ( ++ V_26 -> V_53 == V_26 -> V_25 )
V_26 -> V_53 = 0 ;
V_52 = V_26 -> V_25 - V_26 -> V_53 ;
if ( V_52 >= V_51 )
V_52 = V_51 ;
memcpy ( V_30 -> V_55 , & V_26 -> V_29 [ V_26 -> V_53 ] , V_52 ) ;
if ( V_52 < V_51 ) {
memcpy ( ( V_30 -> V_55 + V_52 ) , V_26 -> V_29 ,
( V_51 - V_52 ) ) ;
V_26 -> V_53 = V_51 - V_52 ;
} else {
V_26 -> V_53 += V_52 ;
}
V_30 -> V_56 = V_51 ;
if ( V_26 -> V_53 == V_26 -> V_25 )
V_26 -> V_53 = 0 ;
V_26 -> V_57 -- ;
F_21 ( L_5 ,
V_51 ) ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
static int F_35 ( struct V_41 * V_42 , T_1 V_58 , int V_59 ,
struct V_30 * V_30 , T_1 V_60 )
{
struct V_11 * V_12 ;
struct V_23 * V_26 ;
int V_61 = 0 ;
if ( V_58 >= V_62 ) {
F_21 ( L_6 ) ;
return - V_63 ;
}
V_12 = F_3 () ;
if ( ! V_12 )
return - V_64 ;
V_12 -> V_32 = V_39 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_60 = V_60 ;
V_12 -> V_47 = V_58 ;
F_30 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_30 -> V_65 ) {
F_33 ( & V_42 -> V_5 -> V_48 ) ;
F_21 ( L_7 , V_30 ) ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
F_8 ( V_12 ) ;
return 0 ;
}
if ( V_59 )
V_26 = V_42 -> V_66 [ V_58 ] ;
else
V_26 = V_42 -> V_67 [ V_58 ] ;
if ( ( ( V_26 -> V_68 & V_69 ) == V_70 )
&& V_26 -> V_57 > 0 ) {
F_8 ( V_12 ) ;
F_33 ( & V_42 -> V_5 -> V_48 ) ;
F_34 ( V_42 , V_26 , V_30 ) ;
return 0 ;
}
if ( V_26 && V_42 -> V_46 ) {
F_36 ( & V_12 -> V_16 , & V_26 -> V_27 ) ;
if ( ! V_59 && V_58 && ( V_26 -> V_28 < 0 ) ) {
V_26 -> V_71 = V_39 ;
V_26 -> V_28 = 0 ;
F_25 ( V_72 , V_26 -> V_47 ,
0 , NULL , V_26 -> V_28 ) ;
}
} else {
V_61 = - V_73 ;
}
F_33 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_61 )
F_8 ( V_12 ) ;
return V_61 ;
}
static int F_37 ( struct V_41 * V_42 , T_1 V_58 , int V_59 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_23 * V_26 ;
F_30 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_59 )
V_26 = V_42 -> V_66 [ V_58 ] ;
else
V_26 = V_42 -> V_67 [ V_58 ] ;
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
F_33 ( & V_42 -> V_5 -> V_48 ) ;
if ( V_12 )
F_8 ( V_12 ) ;
return V_12 ? 0 : - V_74 ;
}
static struct V_30 * F_38 ( struct V_41 * V_42 , int V_75 ,
T_1 V_60 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
struct V_30 * V_30 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_23 * V_26 ;
F_30 ( & V_5 -> V_48 ) ;
V_26 = V_42 -> V_67 [ V_75 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_60 == V_60 ) {
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
static void F_39 ( struct V_41 * V_42 , void * V_46 )
{
F_13 ( & V_42 -> V_76 ) ;
F_13 ( & V_42 -> V_77 ) ;
V_42 -> V_44 |= V_78 | V_79 ;
V_42 -> V_31 |= V_80 |
( V_81 << 16 ) ;
F_40 ( V_46 ) ;
V_42 -> V_46 = V_46 ;
}
static struct V_1 * F_41 ( void )
{
struct V_1 * V_5 ;
F_30 ( & V_82 ) ;
V_5 = V_83 ;
if ( V_5 )
F_42 ( V_5 -> V_3 ) ;
F_33 ( & V_82 ) ;
return V_5 ;
}
static inline void F_43 ( struct V_1 * V_5 )
{
if ( V_5 )
F_44 ( V_5 -> V_3 ) ;
}
void * F_45 ( void * V_46 )
{
int V_7 ;
void * V_84 = NULL ;
struct V_1 * V_5 = NULL ;
struct V_23 * V_26 ;
F_21 ( L_8 ) ;
V_5 = F_41 () ;
if ( V_5 == NULL )
return NULL ;
V_26 = F_11 ( V_19 , 0 ) ;
F_30 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_10 >= 0 ) {
F_33 ( & V_5 -> V_48 ) ;
F_21 ( L_9 ) ;
goto V_85;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_41 * V_42 = & V_5 -> V_9 [ V_7 ] ;
F_27 ( & V_42 -> V_86 ) ;
if ( ( V_42 -> V_44 & V_78 ) == 0 ) {
F_39 ( V_42 , V_46 ) ;
F_19 ( & V_42 -> V_86 ) ;
break;
}
F_19 ( & V_42 -> V_86 ) ;
}
if ( V_7 < V_8 ) {
F_21 ( L_10 , V_7 ) ;
V_5 -> V_10 = V_7 ;
V_5 -> V_9 [ V_7 ] . V_67 [ 0 ] = V_26 ;
V_26 = NULL ;
V_84 = & V_5 -> V_9 [ V_7 ] ;
F_33 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_44 & V_87 ) {
F_21 ( L_11 ) ;
F_46 ( V_5 -> V_3 ) ;
}
F_47 ( V_5 -> V_3 ) ;
} else {
F_33 ( & V_5 -> V_48 ) ;
}
V_85:
if ( V_26 )
F_28 ( NULL , V_26 ) ;
F_43 ( V_5 ) ;
return V_84 ;
}
void F_48 ( void * V_84 )
{
struct V_41 * V_42 = (struct V_41 * ) V_84 ;
struct V_1 * V_5 ;
void * V_46 ;
struct V_23 * V_26 = NULL ;
F_21 ( L_12 ) ;
if ( V_42 == NULL ) {
F_21 ( L_13 ) ;
return;
}
V_5 = V_42 -> V_5 ;
if ( V_5 == NULL )
return;
F_30 ( & V_5 -> V_48 ) ;
if ( ( V_5 -> V_10 >= 0 ) &&
( V_42 == & V_5 -> V_9 [ V_5 -> V_10 ] ) ) {
F_21 ( L_14 ) ;
V_5 -> V_10 = - 1 ;
}
F_27 ( & V_42 -> V_86 ) ;
V_42 -> V_44 |= V_88 ;
F_19 ( & V_42 -> V_86 ) ;
F_33 ( & V_5 -> V_48 ) ;
F_49 ( V_5 -> V_3 , V_42 ) ;
F_30 ( & V_42 -> V_86 ) ;
V_46 = V_42 -> V_46 ;
V_42 -> V_46 = NULL ;
V_42 -> V_6 = 0xff ;
V_42 -> V_44 &= ~ ( V_78 | V_88 ) ;
V_42 -> V_44 |= V_79 ;
V_42 -> V_31 &= ~ V_80 ;
V_42 -> V_31 |= ( V_81 << 16 ) ;
if ( V_42 -> V_67 [ 0 ] ) {
V_26 = V_42 -> V_67 [ 0 ] ;
V_42 -> V_67 [ 0 ] = NULL ;
}
F_33 ( & V_42 -> V_86 ) ;
if ( V_26 )
F_28 ( V_42 , V_26 ) ;
F_47 ( V_5 -> V_3 ) ;
F_50 ( V_46 ) ;
}
void F_51 ( void * V_46 , void * V_84 )
{
struct V_41 * V_42 = (struct V_41 * ) V_84 ;
struct V_1 * V_5 = V_42 -> V_5 ;
F_21 ( L_15 ) ;
F_30 ( & V_42 -> V_86 ) ;
V_42 -> V_44 |= V_79 ;
V_42 -> V_31 |= V_89 ;
V_42 -> V_31 |= ( V_90 << 16 ) ;
F_33 ( & V_42 -> V_86 ) ;
F_49 ( V_5 -> V_3 , V_42 ) ;
F_47 ( V_5 -> V_3 ) ;
}
void F_52 ( void * V_84 , T_1 V_60 , int V_31 , const T_1 * V_91 ,
int V_92 , int V_93 , int V_94 )
{
struct V_41 * V_42 = (struct V_41 * ) V_84 ;
struct V_30 * V_30 ;
int V_61 = 0 ;
F_25 ( V_95 , 0 , V_60 , NULL , V_31 ) ;
F_21 ( L_16 ,
V_92 , V_93 , V_94 ) ;
V_30 = F_38 ( V_42 , 0 , V_60 ) ;
if ( ! V_30 )
return;
if ( V_31 == 0 ) {
int V_52 ;
int V_96 = V_30 -> V_54 ;
if ( V_96 > V_94 )
V_96 = V_94 ;
V_52 = V_96 - V_93 ;
if ( V_92 <= V_52 )
V_52 = V_92 ;
memcpy ( V_30 -> V_55 + V_93 , V_91 , V_52 ) ;
V_93 += V_52 ;
if ( V_93 < V_96 ) {
struct V_97 * V_98 =
(struct V_97 * ) V_30 -> V_99 ;
unsigned V_100 = F_53 ( V_98 -> V_101 ) ;
if ( F_35 ( V_42 , 0 , 0 , V_30 , V_60 ) )
V_61 = - V_64 ;
else if ( F_54 ( V_42 -> V_46 , V_60 ,
V_98 -> V_102 , ( T_1 ) ( V_100 >> 8 ) ,
( T_1 ) V_100 , V_98 -> V_103 , V_93 ,
V_96 - V_93 ) ) {
F_37 ( V_42 , 0 , 0 , V_30 ) ;
V_61 = - V_64 ;
}
if ( V_61 == 0 )
return;
}
}
V_30 -> V_56 = V_94 ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
static void F_55 ( T_1 V_104 )
{
switch ( V_104 ) {
case V_105 :
F_21 ( L_17 ) ;
break;
case V_106 :
F_21 ( L_18 ) ;
break;
case V_107 :
F_21 ( L_19 ) ;
break;
case V_108 :
F_21 ( L_20 ) ;
break;
case V_109 :
F_21 ( L_21 ) ;
break;
case V_110 :
F_21 ( L_22 ) ;
break;
case V_111 :
F_21 ( L_23 ) ;
break;
case V_112 :
F_21 ( L_24 ) ;
break;
case V_113 :
F_21 ( L_25 ) ;
break;
case V_114 :
F_21 ( L_26 ) ;
break;
case V_115 :
F_21 ( L_27 ) ;
break;
}
}
static void F_56 ( struct V_41 * V_42 , struct V_30 * V_30 ,
T_1 V_116 , T_1 V_117 )
{
int V_118 = 0 ;
struct V_2 * V_3 = V_42 -> V_5 -> V_3 ;
if ( V_116 == 0 ) {
V_42 -> V_117 = V_117 ;
F_49 ( V_3 , V_42 ) ;
if ( F_57 ( V_3 , V_42 ,
& V_30 -> V_119 -> V_120 [ V_42 -> V_117 - 1 ] , V_19 ) ) {
V_118 = - V_64 ;
}
} else {
V_118 = - V_64 ;
}
F_17 ( V_3 , V_30 , V_118 , 0 ) ;
}
static void F_58 ( struct V_41 * V_42 , struct V_30 * V_30 ,
T_1 V_116 , T_1 V_121 , T_1 V_122 )
{
struct V_2 * V_3 = V_42 -> V_5 -> V_3 ;
int V_118 = 0 ;
if ( V_116 == 0 ) {
struct V_123 * V_120 ;
struct V_124 * V_125 ;
F_21 ( L_28 , V_121 , V_122 ) ;
F_59 ( V_3 , V_42 , V_121 ) ;
V_120 = & V_30 -> V_119 -> V_120 [ V_42 -> V_117 - 1 ] ;
V_125 = & V_120 -> V_126 [ V_121 ] -> V_127 [ V_122 ] ;
if ( F_60 ( V_3 , V_42 , V_125 ,
V_19 ) )
V_118 = - V_64 ;
else
V_42 -> V_128 [ V_121 ] . V_122 = V_122 ;
} else {
V_118 = - V_64 ;
}
F_17 ( V_3 , V_30 , V_118 , 0 ) ;
}
void F_61 ( void * V_84 , T_1 V_60 , T_1 V_116 , const T_1 * V_129 ,
int V_50 )
{
struct V_41 * V_42 = (struct V_41 * ) V_84 ;
struct V_30 * V_30 ;
struct V_97 * V_98 ;
struct V_2 * V_3 = V_42 -> V_5 -> V_3 ;
unsigned V_130 ;
unsigned V_100 ;
F_25 ( V_95 , 0 , V_60 , NULL , V_116 ) ;
F_21 ( L_29 , V_116 , V_50 ) ;
V_30 = F_38 ( V_42 , 0 , V_60 ) ;
if ( ! V_30 ) {
F_21 ( L_30 ) ;
return;
}
V_98 = (struct V_97 * ) V_30 -> V_99 ;
V_130 = F_53 ( V_98 -> V_103 ) ;
V_100 = F_53 ( V_98 -> V_101 ) ;
if ( ( V_98 -> V_102 & V_131 ) == V_132 ) {
F_55 ( V_98 -> V_133 ) ;
switch ( V_98 -> V_133 ) {
case V_112 :
F_56 ( V_42 , V_30 , V_116 ,
( T_1 ) V_100 ) ;
break;
case V_114 :
F_58 ( V_42 , V_30 , V_116 ,
( T_1 ) V_130 , ( T_1 ) V_100 ) ;
break;
default:
F_17 ( V_3 , V_30 , 0 , 0 ) ;
}
} else {
int V_52 ;
F_21 ( L_31 ) ;
if ( V_50 ) {
if ( V_50 <= V_30 -> V_54 )
V_52 = V_50 ;
else
V_52 = V_30 -> V_54 ;
memcpy ( V_30 -> V_55 , V_129 , V_52 ) ;
V_30 -> V_56 = V_52 ;
}
F_17 ( V_3 , V_30 , 0 , 0 ) ;
}
}
static int F_62 ( struct V_23 * V_26 , const T_1 * V_129 ,
int V_50 )
{
int V_134 ;
int V_52 ;
if ( ! V_26 -> V_29 )
return - 1 ;
V_134 = V_26 -> V_53 - V_26 -> V_135 - 1 ;
if ( V_134 < 0 )
V_134 += V_26 -> V_25 ;
if ( V_134 < ( V_50 + 1 ) ) {
F_21 ( L_32 ) ;
return - 1 ;
}
V_26 -> V_29 [ V_26 -> V_135 ] = ( T_1 ) V_50 ;
if ( ++ V_26 -> V_135 == V_26 -> V_25 )
V_26 -> V_135 = 0 ;
V_52 = V_26 -> V_25 - V_26 -> V_135 ;
if ( V_52 > V_50 )
V_52 = V_50 ;
memcpy ( & V_26 -> V_29 [ V_26 -> V_135 ] , V_129 , V_52 ) ;
if ( V_52 < V_50 ) {
memcpy ( V_26 -> V_29 , V_129 + V_52 , V_50 - V_52 ) ;
V_26 -> V_135 = V_50 - V_52 ;
} else {
V_26 -> V_135 += V_52 ;
}
if ( V_26 -> V_135 == V_26 -> V_25 )
V_26 -> V_135 = 0 ;
V_26 -> V_57 ++ ;
return 0 ;
}
void F_63 ( void * V_84 , T_1 V_136 , const T_1 * V_129 , int V_50 )
{
struct V_41 * V_42 = (struct V_41 * ) V_84 ;
struct V_23 * V_26 ;
struct V_1 * V_5 = V_42 -> V_5 ;
F_30 ( & V_5 -> V_48 ) ;
V_26 = V_42 -> V_66 [ V_136 & V_137 ] ;
if ( V_26 == NULL )
goto V_138;
switch ( V_26 -> V_68 & V_69 ) {
case V_70 :
case V_139 :
if ( ! F_64 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_65 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 ;
int V_52 ;
F_16 ( & V_12 -> V_16 ) ;
F_33 ( & V_5 -> V_48 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
if ( V_50 <= V_30 -> V_54 )
V_52 = V_50 ;
else
V_52 = V_30 -> V_54 ;
memcpy ( V_30 -> V_55 , V_129 , V_52 ) ;
V_30 -> V_56 = V_52 ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
return;
} else {
F_21 ( L_33 ) ;
F_62 ( V_26 , V_129 , V_50 ) ;
}
break;
case V_140 :
F_62 ( V_26 , V_129 , V_50 ) ;
break;
}
V_138:
F_33 ( & V_5 -> V_48 ) ;
}
static inline int F_66 ( void )
{
return F_67 ( F_68 () ) ;
}
int F_69 ( void * V_84 )
{
int V_118 = 0 ;
struct V_41 * V_42 = (struct V_41 * ) V_84 ;
struct V_1 * V_5 = V_42 -> V_5 ;
struct V_11 * V_12 ;
struct V_21 V_141 ;
struct V_21 * V_22 ;
struct V_21 * V_142 ;
struct V_30 * V_30 ;
struct V_23 * V_26 ;
unsigned long V_143 = V_39 ;
F_13 ( & V_141 ) ;
F_30 ( & V_5 -> V_48 ) ;
F_15 (e, &port->isoc_out_ep) {
V_26 = F_70 ( V_22 ) ;
if ( V_26 -> V_28 < 0 )
continue;
V_26 -> V_28 += F_67 ( V_143 - V_26 -> V_71 ) ;
if ( V_26 -> V_28 > V_26 -> V_144 )
V_26 -> V_28 = V_26 -> V_144 ;
F_25 ( V_72 , V_26 -> V_47 , 0 , NULL ,
V_26 -> V_28 ) ;
V_26 -> V_71 = V_143 ;
while ( V_26 -> V_28 && ! F_64 ( & V_26 -> V_27 ) ) {
V_12 = F_65 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
if ( ( V_26 -> V_28 + 1 ) < V_30 -> V_145 )
break;
V_26 -> V_28 -= V_30 -> V_145 ;
F_25 ( V_72 , V_26 -> V_47 , 0 , NULL ,
V_26 -> V_28 ) ;
F_71 ( & V_12 -> V_16 , & V_141 ) ;
}
}
F_33 ( & V_5 -> V_48 ) ;
F_72 (e, n, &xfr_list) {
unsigned long V_104 ;
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
V_104 = V_12 -> V_32 ;
F_16 ( V_22 ) ;
V_30 -> V_146 = 0 ;
V_30 -> V_147 = F_66 () ;
F_73 ( V_42 -> V_46 , V_12 -> V_47 , V_30 ) ;
F_8 ( V_12 ) ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , V_104 ) ;
}
F_30 ( & V_5 -> V_48 ) ;
F_15 (e, &port->isoc_in_ep) {
struct V_23 * V_26 = F_70 ( V_22 ) ;
if ( V_26 -> V_44 & V_148 ) {
if ( V_26 -> V_57 >= V_149 ) {
V_26 -> V_44 &= ~ V_148 ;
V_26 -> V_28 = 0 ;
F_25 ( V_72 ,
V_26 -> V_47 | V_150 ,
0 , NULL , V_26 -> V_28 ) ;
V_26 -> V_71 = V_143 ;
V_26 -> V_147 = 0 ;
F_25 ( V_151 ,
V_26 -> V_47 | V_150 , 0 , NULL , 0 ) ;
}
continue;
}
V_26 -> V_28 += F_67 ( V_143 - V_26 -> V_71 ) ;
F_25 ( V_72 , V_26 -> V_47 | V_150 ,
0 , NULL , V_26 -> V_28 ) ;
V_26 -> V_71 = V_143 ;
while ( ! F_64 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_65 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 = V_12 -> V_30 ;
int V_152 = 0 ;
int V_52 ;
int V_7 ;
if ( ( V_26 -> V_28 + 1 ) < V_30 -> V_145 )
break;
if ( V_26 -> V_57 < V_30 -> V_145 )
break;
V_30 -> V_56 = 0 ;
for ( V_7 = 0 ; V_7 < V_30 -> V_145 ; V_7 ++ ) {
V_152 = V_26 -> V_29 [ V_26 -> V_53 ] ;
if ( ++ V_26 -> V_53 == V_26 -> V_25 )
V_26 -> V_53 = 0 ;
V_52 = V_26 -> V_25 - V_26 -> V_53 ;
if ( V_52 > V_152 )
V_52 = V_152 ;
memcpy ( V_30 -> V_55 ,
& V_26 -> V_29 [ V_26 -> V_53 ] , V_52 ) ;
if ( V_52 < V_152 ) {
memcpy ( V_30 -> V_55 + V_52 ,
V_26 -> V_29 , V_152 - V_52 ) ;
V_26 -> V_53 = V_152 - V_52 ;
} else
V_26 -> V_53 += V_52 ;
if ( V_26 -> V_53 == V_26 -> V_25 )
V_26 -> V_53 = 0 ;
V_30 -> V_153 [ V_7 ] . V_93 =
V_30 -> V_56 ;
V_30 -> V_56 += V_152 ;
V_30 -> V_153 [ V_7 ] . V_56 = V_152 ;
V_30 -> V_153 [ V_7 ] . V_31 = 0 ;
}
V_26 -> V_57 -= V_30 -> V_145 ;
V_30 -> V_146 = 0 ;
V_30 -> V_147 = V_26 -> V_147 ;
V_26 -> V_147 += V_30 -> V_145 ;
F_71 ( & V_12 -> V_16 , & V_141 ) ;
V_26 -> V_28 -= V_30 -> V_145 ;
F_25 ( V_72 , V_26 -> V_47 | V_150 ,
0 , NULL , V_26 -> V_28 ) ;
}
}
if ( ! F_64 ( & V_42 -> V_76 ) || ! F_64 ( & V_42 -> V_77 ) )
V_118 = 1 ;
F_33 ( & V_5 -> V_48 ) ;
F_72 (e, n, &xfr_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
F_8 ( V_12 ) ;
F_17 ( V_42 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
V_26 = V_42 -> V_67 [ 0 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
struct V_21 * V_142 ;
F_30 ( & V_5 -> V_48 ) ;
F_72 (e, n, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( F_74 ( V_143 , V_12 -> V_32 + V_154 / 2 ) ) {
F_21 ( L_34 ,
V_143 , V_12 -> V_30 ) ;
V_12 -> V_32 = V_143 ;
F_71 ( V_22 , & V_141 ) ;
}
}
if ( ! F_64 ( & V_26 -> V_27 ) )
V_118 = 1 ;
F_33 ( & V_5 -> V_48 ) ;
V_22 = V_141 . V_17 ;
while ( V_22 != & V_141 ) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_22 = V_22 -> V_17 ;
F_21 ( L_35 ) ;
F_75 ( V_5 , V_12 -> V_30 , V_19 ) ;
F_8 ( V_12 ) ;
}
}
return V_118 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
struct V_124 * V_125 , T_2 V_24 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
int V_7 ;
int V_155 = V_125 -> V_91 . V_156 ;
int V_157 = 0 ;
F_21 ( L_36 , V_155 , V_125 ) ;
for ( V_7 = 0 ; V_7 < V_125 -> V_91 . V_158 ; V_7 ++ ) {
struct V_159 * V_160 = & V_125 -> V_136 [ V_7 ] ;
T_1 V_58 = V_160 -> V_91 . V_161 ;
T_1 V_47 = V_58 & V_137 ;
struct V_23 * V_26 ;
int V_25 = 0 ;
F_21 ( L_37 , V_7 , V_58 ) ;
if ( V_58 & V_162 ) {
switch ( V_160 -> V_91 . V_163 &
V_69 ) {
case V_140 :
V_25 = 24 * 1024 ;
break;
case V_70 :
V_25 = 128 ;
break;
}
}
V_26 = F_11 ( V_24 , V_25 ) ;
if ( ! V_26 ) {
F_59 ( V_3 , V_42 , V_155 ) ;
return - V_64 ;
}
V_26 -> V_68 = V_160 -> V_91 . V_163 ;
V_26 -> V_47 = V_47 ;
if ( ( V_26 -> V_68 & V_69 )
== V_140 ) {
F_21 ( L_38 ,
V_160 -> V_91 . V_164 ) ;
V_26 -> V_144 = 200 ;
if ( V_58 & V_162 ) {
V_26 -> V_44 |= V_148 ;
F_25 ( V_151 ,
V_26 -> V_47 | V_150 , 1 , NULL , 0 ) ;
} else {
V_26 -> V_44 |= V_45 ;
if ( F_76 ( V_42 -> V_46 , V_47 ) )
V_26 -> V_44 &= ~ V_45 ;
}
}
F_30 ( & V_5 -> V_48 ) ;
if ( V_58 & V_162 ) {
V_42 -> V_66 [ V_47 ] = V_26 ;
V_42 -> V_128 [ V_155 ] . V_165 |=
( 1 << ( V_47 + V_62 ) ) ;
if ( ( V_26 -> V_68 & V_69 )
== V_140 ) {
F_36 ( & V_26 -> V_16 , & V_42 -> V_77 ) ;
V_157 = 1 ;
}
} else {
V_42 -> V_67 [ V_47 ] = V_26 ;
V_42 -> V_128 [ V_155 ] . V_165 |= ( 1 << V_47 ) ;
if ( ( V_26 -> V_68 & V_69 )
== V_140 ) {
F_36 ( & V_26 -> V_16 , & V_42 -> V_76 ) ;
V_157 = 1 ;
}
}
F_33 ( & V_5 -> V_48 ) ;
if ( V_157 && V_42 -> V_46 )
F_77 ( V_42 -> V_46 ) ;
}
return 0 ;
}
static void F_59 ( struct V_2 * V_3 ,
struct V_41 * V_42 , int V_155 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
unsigned V_166 ;
int V_7 ;
struct V_21 V_167 ;
F_21 ( L_39 , V_155 ) ;
if ( V_155 >= V_42 -> V_168 )
return;
F_13 ( & V_167 ) ;
F_30 ( & V_5 -> V_48 ) ;
V_166 = V_42 -> V_128 [ V_155 ] . V_165 ;
V_42 -> V_128 [ V_155 ] . V_165 = 0 ;
for ( V_7 = 0 ; V_7 < V_62 ; V_7 ++ ) {
struct V_21 * V_22 ;
if ( ( V_166 & ( 1 << V_7 ) ) && V_42 -> V_67 [ V_7 ] ) {
V_22 = & V_42 -> V_67 [ V_7 ] -> V_16 ;
V_42 -> V_67 [ V_7 ] = NULL ;
F_71 ( V_22 , & V_167 ) ;
}
if ( ( V_166 & ( 1 << ( V_7 + V_62 ) ) ) && V_42 -> V_66 [ V_7 ] ) {
V_22 = & V_42 -> V_66 [ V_7 ] -> V_16 ;
V_42 -> V_66 [ V_7 ] = NULL ;
F_71 ( V_22 , & V_167 ) ;
}
}
F_33 ( & V_5 -> V_48 ) ;
while ( ! F_64 ( & V_167 ) ) {
struct V_23 * V_26 =
F_65 ( & V_167 , struct V_23 , V_16 ) ;
F_16 ( & V_26 -> V_16 ) ;
F_28 ( V_42 , V_26 ) ;
}
}
static int F_57 ( struct V_2 * V_3 ,
struct V_41 * V_42 , struct V_123 * V_120 ,
T_2 V_24 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
int V_7 ;
int V_168 = V_120 -> V_91 . V_169 ;
if ( V_168 ) {
struct V_170 * V_128 ;
V_128 = F_7 ( V_168 * sizeof( struct V_170 ) ,
V_24 | V_171 ) ;
if ( ! V_128 )
return - V_64 ;
F_30 ( & V_5 -> V_48 ) ;
V_42 -> V_128 = V_128 ;
V_42 -> V_168 = V_168 ;
F_33 ( & V_5 -> V_48 ) ;
}
for ( V_7 = 0 ; V_7 < V_168 ; V_7 ++ ) {
struct V_124 * V_125 =
& V_120 -> V_126 [ V_7 ] -> V_127 [ 0 ] ;
if ( F_60 ( V_3 , V_42 , V_125 ,
V_24 ) )
goto V_172;
}
return 0 ;
V_172:
F_49 ( V_3 , V_42 ) ;
return - 1 ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_1 * V_5 = V_42 -> V_5 ;
int V_7 ;
F_21 ( L_40 ) ;
for ( V_7 = 0 ; V_7 < V_42 -> V_168 ; V_7 ++ )
F_59 ( V_3 , V_42 , V_7 ) ;
F_30 ( & V_5 -> V_48 ) ;
if ( V_42 -> V_128 ) {
F_21 ( L_41 ) ;
F_9 ( V_42 -> V_128 ) ;
V_42 -> V_128 = NULL ;
}
V_42 -> V_168 = 0 ;
F_33 ( & V_5 -> V_48 ) ;
}
static void * F_78 ( struct V_41 * V_42 )
{
void * V_46 = NULL ;
struct V_1 * V_5 = V_42 -> V_5 ;
F_30 ( & V_5 -> V_48 ) ;
V_46 = V_42 -> V_46 ;
if ( V_46 )
F_40 ( V_46 ) ;
F_33 ( & V_5 -> V_48 ) ;
return V_46 ;
}
static void F_75 ( struct V_1 * V_5 , struct V_30 * V_30 ,
T_2 V_24 )
{
struct V_97 * V_98 ;
unsigned V_130 ;
unsigned V_100 ;
unsigned V_173 ;
void * V_46 = NULL ;
T_1 V_60 ;
int V_118 = 0 ;
unsigned V_174 = 0 ;
int V_175 = - 1 ;
struct V_41 * V_42 = NULL ;
F_23 ( V_38 , L_42 , V_39 , V_30 ) ;
V_175 = F_2 ( V_5 , V_30 -> V_119 -> V_176 ) ;
if ( V_175 < 0 ) {
V_118 = - V_73 ;
goto V_85;
}
V_42 = & V_5 -> V_9 [ V_175 ] ;
if ( ( ( V_42 -> V_44 & V_78 ) == 0 )
|| ( V_42 -> V_44 & V_88 ) ) {
F_21 ( L_43 ,
V_175 , V_30 -> V_119 -> V_176 ) ;
V_118 = - V_73 ;
goto V_85;
}
V_30 -> V_35 = V_42 ;
V_98 = (struct V_97 * ) V_30 -> V_99 ;
V_130 = F_53 ( V_98 -> V_103 ) ;
V_100 = F_53 ( V_98 -> V_101 ) ;
V_173 = F_53 ( V_98 -> V_177 ) ;
F_23 ( V_178 , L_44 ,
V_98 -> V_102 ) ;
F_23 ( V_178 , L_45 , V_98 -> V_133 ) ;
F_23 ( V_178 , L_46 , V_100 ) ;
F_23 ( V_178 , L_47 , V_130 ) ;
F_23 ( V_178 , L_48 , V_173 ) ;
V_60 = V_42 -> V_179 ++ ;
V_46 = F_78 ( V_42 ) ;
if ( V_46 == NULL ) {
F_21 ( L_49 ) ;
V_118 = - V_73 ;
goto V_85;
}
if ( ( V_98 -> V_102 & V_131 ) == V_132 ) {
switch ( V_98 -> V_133 ) {
case V_109 :
F_21 ( L_50 ) ;
break;
case V_108 :
F_25 ( V_180 , V_98 -> V_133 ,
0 , NULL , V_98 -> V_102 ) ;
F_21 ( L_51 ) ;
F_21 ( L_52 , V_5 -> V_10 ,
( T_1 ) F_53 ( V_98 -> V_101 ) ) ;
F_30 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_10 >= 0 ) {
V_5 -> V_9 [ V_5 -> V_10 ] . V_6 =
( T_1 ) F_53 ( V_98 -> V_101 ) ;
F_21 ( L_14 ) ;
V_5 -> V_10 = - 1 ;
}
F_33 ( & V_5 -> V_48 ) ;
V_174 = 1 ;
break;
case V_112 :
F_21 ( L_53 ) ;
break;
case V_111 :
F_25 ( V_180 , V_98 -> V_133 , 0 ,
NULL , V_98 -> V_102 ) ;
F_21 ( L_54 ) ;
if ( V_30 -> V_54 >= 1 ) {
V_30 -> V_56 = 1 ;
* ( ( T_1 * ) V_30 -> V_55 ) =
V_42 -> V_117 ;
V_174 = 1 ;
} else {
V_118 = - V_73 ;
}
break;
case V_113 :
F_25 ( V_180 , V_98 -> V_133 , 0 ,
NULL , V_98 -> V_102 ) ;
F_21 ( L_55 ) ;
if ( V_30 -> V_54 >= 1 ) {
V_30 -> V_56 = 1 ;
* ( ( T_1 * ) V_30 -> V_55 ) =
V_42 -> V_128 [ ( T_1 ) V_130 ] . V_122 ;
F_21 ( L_56 ,
V_130 , V_42 -> V_128 [ ( T_1 ) V_130 ] . V_122 ) ;
V_174 = 1 ;
} else {
V_118 = - V_73 ;
}
break;
case V_114 :
F_21 ( L_57 ) ;
break;
}
}
if ( ! V_118 && ! V_174 ) {
int V_50 = 0 ;
if ( ( V_98 -> V_102 & V_150 ) == 0 )
V_50 = V_173 ;
V_30 -> V_56 = V_50 ;
if ( F_79 ( V_42 -> V_46 , V_60 , V_98 ,
V_30 -> V_55 , V_50 ) ) {
V_118 = - V_64 ;
} else {
if ( F_35 ( V_42 , 0 , 0 , V_30 , V_60 ) )
V_118 = - V_64 ;
}
}
F_50 ( V_46 ) ;
V_85:
if ( V_118 || V_174 ) {
F_21 ( L_58 ) ;
F_17 ( V_5 -> V_3 , V_30 , V_118 , 0 ) ;
} else {
F_77 ( V_42 -> V_46 ) ;
}
}
static int F_80 ( struct V_1 * V_5 , struct V_30 * V_30 )
{
int V_118 = 0 ;
struct V_41 * V_42 = V_30 -> V_35 ;
T_1 V_58 ;
F_81 ( V_30 ) ;
if ( ! V_30 -> V_55 && V_30 -> V_54 )
return - V_63 ;
if ( ( V_42 -> V_44 & V_78 ) == 0 )
return - V_73 ;
V_58 = F_82 ( V_30 -> V_181 ) ;
if ( V_58 ) {
if ( F_35 ( V_42 , V_58 , F_83 ( V_30 -> V_181 ) ,
V_30 , 0 ) )
V_118 = - V_73 ;
} else {
F_75 ( V_5 , V_30 , V_19 ) ;
}
return V_118 ;
}
static void F_84 ( unsigned long V_182 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_41 () ;
int V_118 = 0 ;
if ( V_5 == NULL )
return;
F_4 ( & V_34 , V_13 ) ;
while ( ! F_64 ( & V_5 -> V_183 ) ) {
struct V_11 * V_12 =
F_65 ( & V_5 -> V_183 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_34 , V_13 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
V_118 = F_80 ( V_5 , V_30 ) ;
if ( V_118 )
F_17 ( V_5 -> V_3 , V_30 , V_118 , 0 ) ;
F_4 ( & V_34 , V_13 ) ;
}
F_6 ( & V_34 , V_13 ) ;
F_43 ( V_5 ) ;
}
static void F_85 ( struct V_41 * V_42 , T_1 V_47 , struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_21 * V_22 ;
struct V_1 * V_5 ;
unsigned long V_13 ;
T_1 V_184 ;
if ( V_42 == NULL ) {
F_21 ( L_59 , V_30 ) ;
return;
}
V_5 = V_42 -> V_5 ;
if ( V_5 == NULL ) {
F_21 ( L_60 , V_30 ) ;
return;
}
F_4 ( & V_34 , V_13 ) ;
F_15 (e, &ozhcd->urb_cancel_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_30 == V_12 -> V_30 ) {
F_16 ( V_22 ) ;
F_6 ( & V_34 , V_13 ) ;
goto V_185;
}
}
F_6 ( & V_34 , V_13 ) ;
V_12 = NULL ;
F_4 ( & V_5 -> V_48 , V_13 ) ;
F_15 (e, &ozhcd->orphanage) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_86 ( V_22 ) ;
F_21 ( L_61 ) ;
goto V_85;
}
}
V_184 = ( V_47 & 0xf ) ;
V_12 = NULL ;
if ( ( V_47 & V_150 ) && V_184 )
V_12 = F_87 ( V_42 -> V_66 [ V_184 ] , V_30 ) ;
else
V_12 = F_87 ( V_42 -> V_67 [ V_184 ] , V_30 ) ;
V_85:
F_6 ( & V_5 -> V_48 , V_13 ) ;
V_185:
if ( V_12 ) {
V_30 -> V_56 = 0 ;
F_8 ( V_12 ) ;
F_17 ( V_5 -> V_3 , V_30 , - V_73 , 0 ) ;
}
}
static void F_88 ( unsigned long V_182 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_41 () ;
if ( V_5 == NULL )
return;
F_4 ( & V_34 , V_13 ) ;
while ( ! F_64 ( & V_5 -> V_186 ) ) {
struct V_11 * V_12 =
F_65 ( & V_5 -> V_186 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_34 , V_13 ) ;
V_30 = V_12 -> V_30 ;
if ( V_30 -> V_65 )
F_85 ( V_12 -> V_42 , V_12 -> V_47 , V_30 ) ;
F_8 ( V_12 ) ;
F_4 ( & V_34 , V_13 ) ;
}
F_6 ( & V_34 , V_13 ) ;
F_43 ( V_5 ) ;
}
static void F_89 ( struct V_1 * V_5 , int V_31 )
{
if ( V_5 ) {
struct V_11 * V_12 ;
while ( ! F_64 ( & V_5 -> V_49 ) ) {
V_12 = F_65 ( & V_5 -> V_49 ,
struct V_11 , V_16 ) ;
F_86 ( & V_12 -> V_16 ) ;
F_17 ( V_5 -> V_3 , V_12 -> V_30 , V_31 , 0 ) ;
F_8 ( V_12 ) ;
}
}
}
static int F_90 ( struct V_2 * V_3 )
{
F_21 ( L_62 ) ;
V_3 -> V_187 = 200 ;
V_3 -> V_188 = V_189 ;
V_3 -> V_190 = 1 ;
return 0 ;
}
static void F_91 ( struct V_2 * V_3 )
{
F_21 ( L_63 ) ;
}
static void F_92 ( struct V_2 * V_3 )
{
F_21 ( L_64 ) ;
}
static T_1 F_93 ( void )
{
T_1 V_191 = 0 ;
if ( F_94 () )
V_191 |= 1 ;
if ( F_95 () )
V_191 |= 2 ;
return V_191 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_30 * V_30 ,
T_2 V_24 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_118 = 0 ;
int V_175 ;
struct V_41 * V_42 ;
unsigned long V_13 ;
struct V_11 * V_12 ;
F_23 ( V_38 , L_65 ,
V_39 , V_30 ) ;
F_25 ( V_192 , F_93 () ,
( V_193 ) V_30 -> V_145 , V_30 , V_30 -> V_181 ) ;
if ( F_97 ( V_5 == NULL ) ) {
F_23 ( V_38 , L_66 ,
V_39 , V_30 ) ;
return - V_73 ;
}
if ( F_97 ( V_3 -> V_188 != V_189 ) ) {
F_23 ( V_38 , L_67 ,
V_39 , V_30 ) ;
return - V_73 ;
}
V_175 = F_2 ( V_5 , V_30 -> V_119 -> V_176 ) ;
if ( V_175 < 0 )
return - V_73 ;
V_42 = & V_5 -> V_9 [ V_175 ] ;
if ( V_42 == NULL )
return - V_73 ;
if ( ( V_42 -> V_44 & V_78 ) == 0 ) {
F_21 ( L_43 ,
V_175 , V_30 -> V_119 -> V_176 ) ;
return - V_73 ;
}
V_30 -> V_35 = V_42 ;
V_12 = F_3 () ;
if ( F_97 ( V_12 == NULL ) )
return - V_64 ;
V_12 -> V_30 = V_30 ;
F_4 ( & V_34 , V_13 ) ;
V_118 = F_98 ( V_3 , V_30 ) ;
if ( F_97 ( V_118 ) ) {
F_6 ( & V_34 , V_13 ) ;
F_8 ( V_12 ) ;
return V_118 ;
}
F_36 ( & V_12 -> V_16 , & V_5 -> V_183 ) ;
F_6 ( & V_34 , V_13 ) ;
F_99 ( & V_194 ) ;
F_100 ( & V_37 ) ;
return 0 ;
}
static struct V_11 * F_87 ( struct V_23 * V_26 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_21 * V_22 ;
if ( F_97 ( V_26 == NULL ) )
return NULL ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_16 ( V_22 ) ;
if ( F_101 ( V_30 -> V_181 ) ) {
V_26 -> V_28 -= V_30 -> V_145 ;
if ( V_26 -> V_28 < 0 )
V_26 -> V_28 = 0 ;
F_25 ( V_72 ,
F_83 ( V_30 -> V_181 ) ?
( V_26 -> V_47 | V_150 ) : V_26 -> V_47 ,
0 , NULL , V_26 -> V_28 ) ;
}
return V_12 ;
}
}
return NULL ;
}
static int F_102 ( struct V_2 * V_3 , struct V_30 * V_30 , int V_31 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_11 * V_12 = NULL ;
int V_118 ;
unsigned long V_13 ;
F_23 ( V_38 , L_68 , V_39 , V_30 ) ;
V_12 = F_3 () ;
if ( F_97 ( V_12 == NULL ) )
return - V_64 ;
F_4 ( & V_34 , V_13 ) ;
V_118 = F_103 ( V_3 , V_30 , V_31 ) ;
if ( ( V_118 == 0 ) && V_30 -> V_35 ) {
V_12 -> V_30 = V_30 ;
V_12 -> V_42 = (struct V_41 * ) V_30 -> V_35 ;
V_12 -> V_47 = F_82 ( V_30 -> V_181 ) ;
if ( F_83 ( V_30 -> V_181 ) )
V_12 -> V_47 |= V_150 ;
F_36 ( & V_12 -> V_16 , & V_5 -> V_186 ) ;
F_6 ( & V_34 , V_13 ) ;
F_99 ( & V_195 ) ;
} else {
F_6 ( & V_34 , V_13 ) ;
F_8 ( V_12 ) ;
}
return V_118 ;
}
static void F_104 ( struct V_2 * V_3 ,
struct V_159 * V_26 )
{
F_21 ( L_69 ) ;
}
static void F_105 ( struct V_2 * V_3 ,
struct V_159 * V_26 )
{
F_21 ( L_70 ) ;
}
static int F_106 ( struct V_2 * V_3 )
{
F_21 ( L_71 ) ;
return F_66 () ;
}
static int F_107 ( struct V_2 * V_3 , char * V_196 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_7 ;
F_23 ( V_197 , L_72 ) ;
V_196 [ 0 ] = 0 ;
F_30 ( & V_5 -> V_48 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_5 -> V_9 [ V_7 ] . V_44 & V_79 ) {
F_23 ( V_197 , L_73 , V_7 ) ;
V_5 -> V_9 [ V_7 ] . V_44 &= ~ V_79 ;
V_196 [ 0 ] |= 1 << ( V_7 + 1 ) ;
}
}
F_33 ( & V_5 -> V_48 ) ;
return V_196 [ 0 ] ? 1 : 0 ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_198 * V_91 )
{
F_23 ( V_197 , L_74 ) ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
V_91 -> V_199 = 0x29 ;
V_91 -> V_200 = 9 ;
V_91 -> V_201 = ( V_202 V_203 )
F_109 ( 0x0001 ) ;
V_91 -> V_204 = V_8 ;
}
static int F_110 ( struct V_2 * V_3 , V_193 V_100 , V_193 V_130 )
{
struct V_41 * V_42 ;
int V_61 = 0 ;
T_1 V_205 = ( T_1 ) V_130 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_206 = 0 ;
unsigned V_207 = 0 ;
F_23 ( V_197 , L_75 ) ;
if ( ( V_205 < 1 ) || ( V_205 > V_8 ) )
return - V_73 ;
V_42 = & V_5 -> V_9 [ V_205 - 1 ] ;
switch ( V_100 ) {
case V_208 :
F_23 ( V_197 , L_76 ) ;
break;
case V_209 :
F_23 ( V_197 , L_77 ) ;
break;
case V_210 :
F_23 ( V_197 , L_78 ) ;
break;
case V_211 :
F_23 ( V_197 , L_79 ) ;
break;
case V_212 :
F_23 ( V_197 , L_80 ) ;
V_206 = V_213 | ( V_90 << 16 ) ;
V_207 = V_89 ;
V_5 -> V_9 [ V_205 - 1 ] . V_6 = 0 ;
break;
case V_214 :
F_23 ( V_197 , L_81 ) ;
V_206 |= V_215 ;
break;
case V_216 :
F_23 ( V_197 , L_82 ) ;
break;
case V_217 :
F_23 ( V_197 , L_83 ) ;
break;
case V_218 :
F_23 ( V_197 , L_84 ) ;
break;
case V_219 :
F_23 ( V_197 , L_85 ) ;
break;
case V_220 :
F_23 ( V_197 , L_86 ) ;
break;
case V_221 :
F_23 ( V_197 , L_87 ) ;
break;
case V_222 :
F_23 ( V_197 , L_88 ) ;
break;
case V_223 :
F_23 ( V_197 , L_89 ) ;
break;
default:
F_23 ( V_197 , L_90 , V_100 ) ;
break;
}
if ( V_206 || V_207 ) {
F_30 ( & V_42 -> V_86 ) ;
V_42 -> V_31 &= ~ V_207 ;
V_42 -> V_31 |= V_206 ;
F_33 ( & V_42 -> V_86 ) ;
}
F_23 ( V_197 , L_91 , V_205 ,
V_42 -> V_31 ) ;
return V_61 ;
}
static int F_111 ( struct V_2 * V_3 , V_193 V_100 , V_193 V_130 )
{
struct V_41 * V_42 ;
int V_61 = 0 ;
T_1 V_205 = ( T_1 ) V_130 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_207 = 0 ;
F_23 ( V_197 , L_92 ) ;
if ( ( V_205 < 1 ) || ( V_205 > V_8 ) )
return - V_73 ;
V_42 = & V_5 -> V_9 [ V_205 - 1 ] ;
switch ( V_100 ) {
case V_208 :
F_23 ( V_197 , L_76 ) ;
break;
case V_209 :
F_23 ( V_197 , L_77 ) ;
V_207 = V_213 ;
break;
case V_210 :
F_23 ( V_197 , L_78 ) ;
break;
case V_211 :
F_23 ( V_197 , L_79 ) ;
break;
case V_212 :
F_23 ( V_197 , L_80 ) ;
break;
case V_214 :
F_23 ( V_197 , L_81 ) ;
V_207 |= V_215 ;
break;
case V_216 :
F_23 ( V_197 , L_82 ) ;
break;
case V_217 :
F_23 ( V_197 , L_83 ) ;
V_207 = ( V_81 << 16 ) ;
break;
case V_218 :
F_23 ( V_197 , L_84 ) ;
V_207 = ( V_224 << 16 ) ;
break;
case V_219 :
F_23 ( V_197 , L_85 ) ;
break;
case V_220 :
F_23 ( V_197 , L_86 ) ;
break;
case V_221 :
F_23 ( V_197 , L_87 ) ;
V_207 = ( V_221 << 16 ) ;
break;
case V_222 :
F_23 ( V_197 , L_88 ) ;
break;
case V_223 :
F_23 ( V_197 , L_89 ) ;
break;
default:
F_23 ( V_197 , L_90 , V_100 ) ;
break;
}
if ( V_207 ) {
F_30 ( & V_42 -> V_86 ) ;
V_42 -> V_31 &= ~ V_207 ;
F_33 ( & V_42 -> V_86 ) ;
}
F_23 ( V_197 , L_91 , V_205 ,
V_5 -> V_9 [ V_205 - 1 ] . V_31 ) ;
return V_61 ;
}
static int F_112 ( struct V_2 * V_3 , V_193 V_130 , char * V_196 )
{
struct V_1 * V_5 ;
T_3 V_31 = 0 ;
if ( ( V_130 < 1 ) || ( V_130 > V_8 ) )
return - V_73 ;
V_5 = F_1 ( V_3 ) ;
F_23 ( V_197 , L_93 , V_130 ) ;
V_31 = V_5 -> V_9 [ V_130 - 1 ] . V_31 ;
F_113 ( F_114 ( V_31 ) , ( V_225 * ) V_196 ) ;
F_23 ( V_197 , L_94 , V_130 , V_31 ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 , V_193 V_226 , V_193 V_100 ,
V_193 V_130 , char * V_196 , V_193 V_173 )
{
int V_61 = 0 ;
F_23 ( V_197 , L_95 ) ;
switch ( V_226 ) {
case V_227 :
F_23 ( V_197 , L_96 , V_226 ) ;
break;
case V_228 :
V_61 = F_111 ( V_3 , V_100 , V_130 ) ;
break;
case V_229 :
F_108 ( V_3 , (struct V_198 * ) V_196 ) ;
break;
case V_230 :
F_23 ( V_197 , L_97 ,
V_226 ) ;
F_113 ( F_116 ( 0 ) , ( V_225 * ) V_196 ) ;
break;
case V_231 :
V_61 = F_112 ( V_3 , V_130 , V_196 ) ;
break;
case V_232 :
F_23 ( V_197 , L_98 , V_226 ) ;
break;
case V_233 :
V_61 = F_110 ( V_3 , V_100 , V_130 ) ;
break;
default:
F_23 ( V_197 , L_99 , V_226 ) ;
break;
}
return V_61 ;
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_23 ( V_197 , L_100 ) ;
V_5 = F_1 ( V_3 ) ;
F_30 ( & V_5 -> V_48 ) ;
V_3 -> V_188 = V_234 ;
V_5 -> V_44 |= V_87 ;
F_33 ( & V_5 -> V_48 ) ;
return 0 ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_23 ( V_197 , L_101 ) ;
V_5 = F_1 ( V_3 ) ;
F_30 ( & V_5 -> V_48 ) ;
V_5 -> V_44 &= ~ V_87 ;
V_3 -> V_188 = V_189 ;
F_33 ( & V_5 -> V_48 ) ;
return 0 ;
}
static void F_119 ( struct V_235 * V_119 )
{
F_21 ( L_102 ) ;
}
static int F_120 ( struct V_235 * V_119 )
{
int V_7 ;
int V_61 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
F_21 ( L_103 ) ;
V_3 = F_121 ( & V_236 , & V_119 -> V_119 , F_122 ( & V_119 -> V_119 ) ) ;
if ( V_3 == NULL ) {
F_21 ( L_104 ) ;
return - V_64 ;
}
V_5 = F_1 ( V_3 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_13 ( & V_5 -> V_183 ) ;
F_13 ( & V_5 -> V_186 ) ;
F_13 ( & V_5 -> V_49 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_10 = - 1 ;
F_123 ( & V_5 -> V_48 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_41 * V_42 = & V_5 -> V_9 [ V_7 ] ;
V_42 -> V_5 = V_5 ;
V_42 -> V_44 = 0 ;
V_42 -> V_31 = 0 ;
V_42 -> V_6 = 0xff ;
F_123 ( & V_42 -> V_86 ) ;
}
V_61 = F_124 ( V_3 , 0 , 0 ) ;
if ( V_61 ) {
F_21 ( L_105 ) ;
F_44 ( V_3 ) ;
return - 1 ;
}
F_30 ( & V_82 ) ;
V_83 = V_5 ;
F_33 ( & V_82 ) ;
return 0 ;
}
static int F_125 ( struct V_235 * V_119 )
{
struct V_2 * V_3 = F_126 ( V_119 ) ;
struct V_1 * V_5 ;
F_21 ( L_106 ) ;
if ( V_3 == NULL )
return - 1 ;
V_5 = F_1 ( V_3 ) ;
F_30 ( & V_82 ) ;
if ( V_5 == V_83 )
V_83 = NULL ;
F_33 ( & V_82 ) ;
F_21 ( L_107 ) ;
F_89 ( V_5 , - V_73 ) ;
F_21 ( L_108 ) ;
F_127 ( V_3 ) ;
F_44 ( V_3 ) ;
F_10 () ;
return 0 ;
}
static int F_128 ( struct V_235 * V_119 , T_4 V_237 )
{
F_21 ( L_109 ) ;
return 0 ;
}
static int F_129 ( struct V_235 * V_119 )
{
F_21 ( L_110 ) ;
return 0 ;
}
int F_130 ( void )
{
int V_61 ;
if ( F_131 () )
return - V_238 ;
F_132 ( & V_194 , F_84 , 0 ) ;
F_132 ( & V_195 , F_88 , 0 ) ;
V_61 = F_133 ( & V_239 ) ;
F_21 ( L_111 , V_61 ) ;
if ( V_61 )
goto error;
V_240 = F_134 ( V_241 , - 1 ) ;
if ( V_240 == NULL ) {
V_61 = - V_64 ;
goto V_242;
}
F_21 ( L_112 ) ;
V_61 = F_135 ( V_240 ) ;
if ( V_61 )
goto V_243;
F_21 ( L_113 ) ;
return 0 ;
V_243:
F_136 ( V_240 ) ;
V_242:
F_137 ( & V_239 ) ;
error:
F_138 ( & V_194 ) ;
F_138 ( & V_195 ) ;
F_21 ( L_114 , V_61 ) ;
return V_61 ;
}
void F_139 ( void )
{
F_140 ( & V_194 ) ;
F_140 ( & V_195 ) ;
F_141 ( V_240 ) ;
F_137 ( & V_239 ) ;
F_21 ( L_115 , F_24 ( & V_37 ) ) ;
}
