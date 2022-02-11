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
F_25 ( V_3 , V_30 , V_31 ) ;
}
F_26 ( & V_34 ) ;
F_6 ( & V_34 , V_13 ) ;
if ( V_33 )
F_8 ( V_33 ) ;
}
static void F_27 ( struct V_40 * V_41 , struct V_23 * V_26 )
{
F_21 ( L_3 ) ;
if ( V_41 ) {
struct V_21 V_42 ;
struct V_1 * V_5 = V_41 -> V_5 ;
F_13 ( & V_42 ) ;
if ( V_26 -> V_43 & V_44 )
F_28 ( V_41 -> V_45 , V_26 -> V_46 ) ;
F_29 ( & V_5 -> V_47 ) ;
F_30 ( & V_26 -> V_27 , & V_42 ) ;
F_31 ( & V_42 , & V_5 -> V_48 ) ;
F_32 ( & V_5 -> V_47 ) ;
}
F_21 ( L_4 ) ;
F_9 ( V_26 ) ;
}
static void F_33 ( struct V_40 * V_41 ,
struct V_23 * V_26 ,
struct V_30 * V_30 )
{
T_1 V_49 , V_50 , V_51 ;
memcpy ( & V_49 , & V_26 -> V_29 [ V_26 -> V_52 ] , sizeof( T_1 ) ) ;
if ( V_49 <= V_30 -> V_53 )
V_50 = V_49 ;
else
V_50 = V_30 -> V_53 ;
if ( ++ V_26 -> V_52 == V_26 -> V_25 )
V_26 -> V_52 = 0 ;
V_51 = V_26 -> V_25 - V_26 -> V_52 ;
if ( V_51 >= V_50 )
V_51 = V_50 ;
memcpy ( V_30 -> V_54 , & V_26 -> V_29 [ V_26 -> V_52 ] , V_51 ) ;
if ( V_51 < V_50 ) {
memcpy ( ( V_30 -> V_54 + V_51 ) , V_26 -> V_29 ,
( V_50 - V_51 ) ) ;
V_26 -> V_52 = V_50 - V_51 ;
} else {
V_26 -> V_52 += V_51 ;
}
V_30 -> V_55 = V_50 ;
if ( V_26 -> V_52 == V_26 -> V_25 )
V_26 -> V_52 = 0 ;
V_26 -> V_56 -- ;
F_21 ( L_5 ,
V_50 ) ;
F_17 ( V_41 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
static int F_34 ( struct V_40 * V_41 , T_1 V_57 , int V_58 ,
struct V_30 * V_30 , T_1 V_59 )
{
struct V_11 * V_12 ;
struct V_23 * V_26 ;
int V_60 = 0 ;
if ( V_57 >= V_61 ) {
F_21 ( L_6 ) ;
return - V_62 ;
}
V_12 = F_3 () ;
if ( ! V_12 )
return - V_63 ;
V_12 -> V_32 = V_39 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_59 = V_59 ;
V_12 -> V_46 = V_57 ;
F_29 ( & V_41 -> V_5 -> V_47 ) ;
if ( V_30 -> V_64 ) {
F_32 ( & V_41 -> V_5 -> V_47 ) ;
F_21 ( L_7 , V_30 ) ;
F_17 ( V_41 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
F_8 ( V_12 ) ;
return 0 ;
}
if ( V_58 )
V_26 = V_41 -> V_65 [ V_57 ] ;
else
V_26 = V_41 -> V_66 [ V_57 ] ;
if ( ( ( V_26 -> V_67 & V_68 ) == V_69 )
&& V_26 -> V_56 > 0 ) {
F_8 ( V_12 ) ;
F_32 ( & V_41 -> V_5 -> V_47 ) ;
F_33 ( V_41 , V_26 , V_30 ) ;
return 0 ;
}
if ( V_26 && V_41 -> V_45 ) {
F_35 ( & V_12 -> V_16 , & V_26 -> V_27 ) ;
if ( ! V_58 && V_57 && ( V_26 -> V_28 < 0 ) ) {
V_26 -> V_70 = V_39 ;
V_26 -> V_28 = 0 ;
}
} else {
V_60 = - V_71 ;
}
F_32 ( & V_41 -> V_5 -> V_47 ) ;
if ( V_60 )
F_8 ( V_12 ) ;
return V_60 ;
}
static int F_36 ( struct V_40 * V_41 , T_1 V_57 , int V_58 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_23 * V_26 ;
F_29 ( & V_41 -> V_5 -> V_47 ) ;
if ( V_58 )
V_26 = V_41 -> V_65 [ V_57 ] ;
else
V_26 = V_41 -> V_66 [ V_57 ] ;
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
F_32 ( & V_41 -> V_5 -> V_47 ) ;
if ( V_12 )
F_8 ( V_12 ) ;
return V_12 ? 0 : - V_72 ;
}
static struct V_30 * F_37 ( struct V_40 * V_41 , int V_73 ,
T_1 V_59 )
{
struct V_1 * V_5 = V_41 -> V_5 ;
struct V_30 * V_30 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_23 * V_26 ;
F_29 ( & V_5 -> V_47 ) ;
V_26 = V_41 -> V_66 [ V_73 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_59 == V_59 ) {
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
break;
}
}
}
F_32 ( & V_5 -> V_47 ) ;
if ( V_30 )
F_8 ( V_12 ) ;
return V_30 ;
}
static void F_38 ( struct V_40 * V_41 , void * V_45 )
{
F_13 ( & V_41 -> V_74 ) ;
F_13 ( & V_41 -> V_75 ) ;
V_41 -> V_43 |= V_76 | V_77 ;
V_41 -> V_31 |= V_78 |
( V_79 << 16 ) ;
F_39 ( V_45 ) ;
V_41 -> V_45 = V_45 ;
}
static struct V_1 * F_40 ( void )
{
struct V_1 * V_5 ;
F_29 ( & V_80 ) ;
V_5 = V_81 ;
if ( V_5 )
F_41 ( V_5 -> V_3 ) ;
F_32 ( & V_80 ) ;
return V_5 ;
}
static inline void F_42 ( struct V_1 * V_5 )
{
if ( V_5 )
F_43 ( V_5 -> V_3 ) ;
}
void * F_44 ( void * V_45 )
{
int V_7 ;
void * V_82 = NULL ;
struct V_1 * V_5 = NULL ;
struct V_23 * V_26 ;
F_21 ( L_8 ) ;
V_5 = F_40 () ;
if ( V_5 == NULL )
return NULL ;
V_26 = F_11 ( V_19 , 0 ) ;
F_29 ( & V_5 -> V_47 ) ;
if ( V_5 -> V_10 >= 0 ) {
F_32 ( & V_5 -> V_47 ) ;
F_21 ( L_9 ) ;
goto V_83;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_40 * V_41 = & V_5 -> V_9 [ V_7 ] ;
F_26 ( & V_41 -> V_84 ) ;
if ( ( V_41 -> V_43 & V_76 ) == 0 ) {
F_38 ( V_41 , V_45 ) ;
F_19 ( & V_41 -> V_84 ) ;
break;
}
F_19 ( & V_41 -> V_84 ) ;
}
if ( V_7 < V_8 ) {
F_21 ( L_10 , V_7 ) ;
V_5 -> V_10 = V_7 ;
V_5 -> V_9 [ V_7 ] . V_66 [ 0 ] = V_26 ;
V_26 = NULL ;
V_82 = & V_5 -> V_9 [ V_7 ] ;
F_32 ( & V_5 -> V_47 ) ;
if ( V_5 -> V_43 & V_85 ) {
F_21 ( L_11 ) ;
F_45 ( V_5 -> V_3 ) ;
}
F_46 ( V_5 -> V_3 ) ;
} else {
F_32 ( & V_5 -> V_47 ) ;
}
V_83:
if ( V_26 )
F_27 ( NULL , V_26 ) ;
F_42 ( V_5 ) ;
return V_82 ;
}
void F_47 ( void * V_82 )
{
struct V_40 * V_41 = (struct V_40 * ) V_82 ;
struct V_1 * V_5 ;
void * V_45 ;
struct V_23 * V_26 = NULL ;
F_21 ( L_12 ) ;
if ( V_41 == NULL ) {
F_21 ( L_13 ) ;
return;
}
V_5 = V_41 -> V_5 ;
if ( V_5 == NULL )
return;
F_29 ( & V_5 -> V_47 ) ;
if ( ( V_5 -> V_10 >= 0 ) &&
( V_41 == & V_5 -> V_9 [ V_5 -> V_10 ] ) ) {
F_21 ( L_14 ) ;
V_5 -> V_10 = - 1 ;
}
F_26 ( & V_41 -> V_84 ) ;
V_41 -> V_43 |= V_86 ;
F_19 ( & V_41 -> V_84 ) ;
F_32 ( & V_5 -> V_47 ) ;
F_48 ( V_5 -> V_3 , V_41 ) ;
F_29 ( & V_41 -> V_84 ) ;
V_45 = V_41 -> V_45 ;
V_41 -> V_45 = NULL ;
V_41 -> V_6 = 0xff ;
V_41 -> V_43 &= ~ ( V_76 | V_86 ) ;
V_41 -> V_43 |= V_77 ;
V_41 -> V_31 &= ~ V_78 ;
V_41 -> V_31 |= ( V_79 << 16 ) ;
if ( V_41 -> V_66 [ 0 ] ) {
V_26 = V_41 -> V_66 [ 0 ] ;
V_41 -> V_66 [ 0 ] = NULL ;
}
F_32 ( & V_41 -> V_84 ) ;
if ( V_26 )
F_27 ( V_41 , V_26 ) ;
F_46 ( V_5 -> V_3 ) ;
F_49 ( V_45 ) ;
}
void F_50 ( void * V_45 , void * V_82 )
{
struct V_40 * V_41 = (struct V_40 * ) V_82 ;
struct V_1 * V_5 = V_41 -> V_5 ;
F_21 ( L_15 ) ;
F_29 ( & V_41 -> V_84 ) ;
V_41 -> V_43 |= V_77 ;
V_41 -> V_31 |= V_87 ;
V_41 -> V_31 |= ( V_88 << 16 ) ;
F_32 ( & V_41 -> V_84 ) ;
F_48 ( V_5 -> V_3 , V_41 ) ;
F_46 ( V_5 -> V_3 ) ;
}
void F_51 ( void * V_82 , T_1 V_59 , int V_31 , const T_1 * V_89 ,
int V_90 , int V_91 , int V_92 )
{
struct V_40 * V_41 = (struct V_40 * ) V_82 ;
struct V_30 * V_30 ;
int V_60 = 0 ;
F_21 ( L_16 ,
V_90 , V_91 , V_92 ) ;
V_30 = F_37 ( V_41 , 0 , V_59 ) ;
if ( ! V_30 )
return;
if ( V_31 == 0 ) {
int V_51 ;
int V_93 = V_30 -> V_53 ;
if ( V_93 > V_92 )
V_93 = V_92 ;
V_51 = V_93 - V_91 ;
if ( V_90 <= V_51 )
V_51 = V_90 ;
memcpy ( V_30 -> V_54 + V_91 , V_89 , V_51 ) ;
V_91 += V_51 ;
if ( V_91 < V_93 ) {
struct V_94 * V_95 =
(struct V_94 * ) V_30 -> V_96 ;
unsigned V_97 = F_52 ( V_95 -> V_98 ) ;
if ( F_34 ( V_41 , 0 , 0 , V_30 , V_59 ) )
V_60 = - V_63 ;
else if ( F_53 ( V_41 -> V_45 , V_59 ,
V_95 -> V_99 , ( T_1 ) ( V_97 >> 8 ) ,
( T_1 ) V_97 , V_95 -> V_100 , V_91 ,
V_93 - V_91 ) ) {
F_36 ( V_41 , 0 , 0 , V_30 ) ;
V_60 = - V_63 ;
}
if ( V_60 == 0 )
return;
}
}
V_30 -> V_55 = V_92 ;
F_17 ( V_41 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
static void F_54 ( T_1 V_101 )
{
switch ( V_101 ) {
case V_102 :
F_21 ( L_17 ) ;
break;
case V_103 :
F_21 ( L_18 ) ;
break;
case V_104 :
F_21 ( L_19 ) ;
break;
case V_105 :
F_21 ( L_20 ) ;
break;
case V_106 :
F_21 ( L_21 ) ;
break;
case V_107 :
F_21 ( L_22 ) ;
break;
case V_108 :
F_21 ( L_23 ) ;
break;
case V_109 :
F_21 ( L_24 ) ;
break;
case V_110 :
F_21 ( L_25 ) ;
break;
case V_111 :
F_21 ( L_26 ) ;
break;
case V_112 :
F_21 ( L_27 ) ;
break;
}
}
static void F_55 ( struct V_40 * V_41 , struct V_30 * V_30 ,
T_1 V_113 , T_1 V_114 )
{
int V_115 = 0 ;
struct V_2 * V_3 = V_41 -> V_5 -> V_3 ;
if ( V_113 == 0 ) {
V_41 -> V_114 = V_114 ;
F_48 ( V_3 , V_41 ) ;
if ( F_56 ( V_3 , V_41 ,
& V_30 -> V_116 -> V_117 [ V_41 -> V_114 - 1 ] , V_19 ) ) {
V_115 = - V_63 ;
}
} else {
V_115 = - V_63 ;
}
F_17 ( V_3 , V_30 , V_115 , 0 ) ;
}
static void F_57 ( struct V_40 * V_41 , struct V_30 * V_30 ,
T_1 V_113 , T_1 V_118 , T_1 V_119 )
{
struct V_2 * V_3 = V_41 -> V_5 -> V_3 ;
int V_115 = 0 ;
if ( V_113 == 0 ) {
struct V_120 * V_117 ;
struct V_121 * V_122 ;
F_21 ( L_28 , V_118 , V_119 ) ;
F_58 ( V_3 , V_41 , V_118 ) ;
V_117 = & V_30 -> V_116 -> V_117 [ V_41 -> V_114 - 1 ] ;
V_122 = & V_117 -> V_123 [ V_118 ] -> V_124 [ V_119 ] ;
if ( F_59 ( V_3 , V_41 , V_122 ,
V_19 ) )
V_115 = - V_63 ;
else
V_41 -> V_125 [ V_118 ] . V_119 = V_119 ;
} else {
V_115 = - V_63 ;
}
F_17 ( V_3 , V_30 , V_115 , 0 ) ;
}
void F_60 ( void * V_82 , T_1 V_59 , T_1 V_113 , const T_1 * V_126 ,
int V_49 )
{
struct V_40 * V_41 = (struct V_40 * ) V_82 ;
struct V_30 * V_30 ;
struct V_94 * V_95 ;
struct V_2 * V_3 = V_41 -> V_5 -> V_3 ;
unsigned V_127 ;
unsigned V_97 ;
F_21 ( L_29 , V_113 , V_49 ) ;
V_30 = F_37 ( V_41 , 0 , V_59 ) ;
if ( ! V_30 ) {
F_21 ( L_30 ) ;
return;
}
V_95 = (struct V_94 * ) V_30 -> V_96 ;
V_127 = F_52 ( V_95 -> V_100 ) ;
V_97 = F_52 ( V_95 -> V_98 ) ;
if ( ( V_95 -> V_99 & V_128 ) == V_129 ) {
F_54 ( V_95 -> V_130 ) ;
switch ( V_95 -> V_130 ) {
case V_109 :
F_55 ( V_41 , V_30 , V_113 ,
( T_1 ) V_97 ) ;
break;
case V_111 :
F_57 ( V_41 , V_30 , V_113 ,
( T_1 ) V_127 , ( T_1 ) V_97 ) ;
break;
default:
F_17 ( V_3 , V_30 , 0 , 0 ) ;
}
} else {
int V_51 ;
F_21 ( L_31 ) ;
if ( V_49 ) {
if ( V_49 <= V_30 -> V_53 )
V_51 = V_49 ;
else
V_51 = V_30 -> V_53 ;
memcpy ( V_30 -> V_54 , V_126 , V_51 ) ;
V_30 -> V_55 = V_51 ;
}
F_17 ( V_3 , V_30 , 0 , 0 ) ;
}
}
static int F_61 ( struct V_23 * V_26 , const T_1 * V_126 ,
int V_49 )
{
int V_131 ;
int V_51 ;
if ( ! V_26 -> V_29 )
return - 1 ;
V_131 = V_26 -> V_52 - V_26 -> V_132 - 1 ;
if ( V_131 < 0 )
V_131 += V_26 -> V_25 ;
if ( V_131 < ( V_49 + 1 ) ) {
F_21 ( L_32 ) ;
return - 1 ;
}
V_26 -> V_29 [ V_26 -> V_132 ] = ( T_1 ) V_49 ;
if ( ++ V_26 -> V_132 == V_26 -> V_25 )
V_26 -> V_132 = 0 ;
V_51 = V_26 -> V_25 - V_26 -> V_132 ;
if ( V_51 > V_49 )
V_51 = V_49 ;
memcpy ( & V_26 -> V_29 [ V_26 -> V_132 ] , V_126 , V_51 ) ;
if ( V_51 < V_49 ) {
memcpy ( V_26 -> V_29 , V_126 + V_51 , V_49 - V_51 ) ;
V_26 -> V_132 = V_49 - V_51 ;
} else {
V_26 -> V_132 += V_51 ;
}
if ( V_26 -> V_132 == V_26 -> V_25 )
V_26 -> V_132 = 0 ;
V_26 -> V_56 ++ ;
return 0 ;
}
void F_62 ( void * V_82 , T_1 V_133 , const T_1 * V_126 , int V_49 )
{
struct V_40 * V_41 = (struct V_40 * ) V_82 ;
struct V_23 * V_26 ;
struct V_1 * V_5 = V_41 -> V_5 ;
F_29 ( & V_5 -> V_47 ) ;
V_26 = V_41 -> V_65 [ V_133 & V_134 ] ;
if ( V_26 == NULL )
goto V_135;
switch ( V_26 -> V_67 & V_68 ) {
case V_69 :
case V_136 :
if ( ! F_63 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_64 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 ;
int V_51 ;
F_16 ( & V_12 -> V_16 ) ;
F_32 ( & V_5 -> V_47 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
if ( V_49 <= V_30 -> V_53 )
V_51 = V_49 ;
else
V_51 = V_30 -> V_53 ;
memcpy ( V_30 -> V_54 , V_126 , V_51 ) ;
V_30 -> V_55 = V_51 ;
F_17 ( V_41 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
return;
} else {
F_21 ( L_33 ) ;
F_61 ( V_26 , V_126 , V_49 ) ;
}
break;
case V_137 :
F_61 ( V_26 , V_126 , V_49 ) ;
break;
}
V_135:
F_32 ( & V_5 -> V_47 ) ;
}
static inline int F_65 ( void )
{
return F_66 ( F_67 () ) ;
}
int F_68 ( void * V_82 )
{
int V_115 = 0 ;
struct V_40 * V_41 = (struct V_40 * ) V_82 ;
struct V_1 * V_5 = V_41 -> V_5 ;
struct V_11 * V_12 ;
struct V_21 V_138 ;
struct V_21 * V_22 ;
struct V_21 * V_139 ;
struct V_30 * V_30 ;
struct V_23 * V_26 ;
unsigned long V_140 = V_39 ;
F_13 ( & V_138 ) ;
F_29 ( & V_5 -> V_47 ) ;
F_15 (e, &port->isoc_out_ep) {
V_26 = F_69 ( V_22 ) ;
if ( V_26 -> V_28 < 0 )
continue;
V_26 -> V_28 += F_66 ( V_140 - V_26 -> V_70 ) ;
if ( V_26 -> V_28 > V_26 -> V_141 )
V_26 -> V_28 = V_26 -> V_141 ;
V_26 -> V_70 = V_140 ;
while ( V_26 -> V_28 && ! F_63 ( & V_26 -> V_27 ) ) {
V_12 = F_64 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
if ( ( V_26 -> V_28 + 1 ) < V_30 -> V_142 )
break;
V_26 -> V_28 -= V_30 -> V_142 ;
F_70 ( & V_12 -> V_16 , & V_138 ) ;
}
}
F_32 ( & V_5 -> V_47 ) ;
F_71 (e, n, &xfr_list) {
unsigned long V_101 ;
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
V_101 = V_12 -> V_32 ;
F_16 ( V_22 ) ;
V_30 -> V_143 = 0 ;
V_30 -> V_144 = F_65 () ;
F_72 ( V_41 -> V_45 , V_12 -> V_46 , V_30 ) ;
F_8 ( V_12 ) ;
F_17 ( V_41 -> V_5 -> V_3 , V_30 , 0 , V_101 ) ;
}
F_29 ( & V_5 -> V_47 ) ;
F_15 (e, &port->isoc_in_ep) {
struct V_23 * V_26 = F_69 ( V_22 ) ;
if ( V_26 -> V_43 & V_145 ) {
if ( V_26 -> V_56 >= V_146 ) {
V_26 -> V_43 &= ~ V_145 ;
V_26 -> V_28 = 0 ;
V_26 -> V_70 = V_140 ;
V_26 -> V_144 = 0 ;
}
continue;
}
V_26 -> V_28 += F_66 ( V_140 - V_26 -> V_70 ) ;
V_26 -> V_70 = V_140 ;
while ( ! F_63 ( & V_26 -> V_27 ) ) {
struct V_11 * V_12 =
F_64 ( & V_26 -> V_27 ,
struct V_11 , V_16 ) ;
struct V_30 * V_30 = V_12 -> V_30 ;
int V_147 = 0 ;
int V_51 ;
int V_7 ;
if ( ( V_26 -> V_28 + 1 ) < V_30 -> V_142 )
break;
if ( V_26 -> V_56 < V_30 -> V_142 )
break;
V_30 -> V_55 = 0 ;
for ( V_7 = 0 ; V_7 < V_30 -> V_142 ; V_7 ++ ) {
V_147 = V_26 -> V_29 [ V_26 -> V_52 ] ;
if ( ++ V_26 -> V_52 == V_26 -> V_25 )
V_26 -> V_52 = 0 ;
V_51 = V_26 -> V_25 - V_26 -> V_52 ;
if ( V_51 > V_147 )
V_51 = V_147 ;
memcpy ( V_30 -> V_54 ,
& V_26 -> V_29 [ V_26 -> V_52 ] , V_51 ) ;
if ( V_51 < V_147 ) {
memcpy ( V_30 -> V_54 + V_51 ,
V_26 -> V_29 , V_147 - V_51 ) ;
V_26 -> V_52 = V_147 - V_51 ;
} else
V_26 -> V_52 += V_51 ;
if ( V_26 -> V_52 == V_26 -> V_25 )
V_26 -> V_52 = 0 ;
V_30 -> V_148 [ V_7 ] . V_91 =
V_30 -> V_55 ;
V_30 -> V_55 += V_147 ;
V_30 -> V_148 [ V_7 ] . V_55 = V_147 ;
V_30 -> V_148 [ V_7 ] . V_31 = 0 ;
}
V_26 -> V_56 -= V_30 -> V_142 ;
V_30 -> V_143 = 0 ;
V_30 -> V_144 = V_26 -> V_144 ;
V_26 -> V_144 += V_30 -> V_142 ;
F_70 ( & V_12 -> V_16 , & V_138 ) ;
V_26 -> V_28 -= V_30 -> V_142 ;
}
}
if ( ! F_63 ( & V_41 -> V_74 ) || ! F_63 ( & V_41 -> V_75 ) )
V_115 = 1 ;
F_32 ( & V_5 -> V_47 ) ;
F_71 (e, n, &xfr_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_30 = V_12 -> V_30 ;
F_16 ( V_22 ) ;
F_8 ( V_12 ) ;
F_17 ( V_41 -> V_5 -> V_3 , V_30 , 0 , 0 ) ;
}
V_26 = V_41 -> V_66 [ 0 ] ;
if ( V_26 ) {
struct V_21 * V_22 ;
struct V_21 * V_139 ;
F_29 ( & V_5 -> V_47 ) ;
F_71 (e, n, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( F_73 ( V_140 , V_12 -> V_32 + V_149 / 2 ) ) {
F_21 ( L_34 ,
V_140 , V_12 -> V_30 ) ;
V_12 -> V_32 = V_140 ;
F_70 ( V_22 , & V_138 ) ;
}
}
if ( ! F_63 ( & V_26 -> V_27 ) )
V_115 = 1 ;
F_32 ( & V_5 -> V_47 ) ;
V_22 = V_138 . V_17 ;
while ( V_22 != & V_138 ) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
V_22 = V_22 -> V_17 ;
F_21 ( L_35 ) ;
F_74 ( V_5 , V_12 -> V_30 , V_19 ) ;
F_8 ( V_12 ) ;
}
}
return V_115 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
struct V_121 * V_122 , T_2 V_24 )
{
struct V_1 * V_5 = V_41 -> V_5 ;
int V_7 ;
int V_150 = V_122 -> V_89 . V_151 ;
int V_152 = 0 ;
F_21 ( L_36 , V_150 , V_122 ) ;
for ( V_7 = 0 ; V_7 < V_122 -> V_89 . V_153 ; V_7 ++ ) {
struct V_154 * V_155 = & V_122 -> V_133 [ V_7 ] ;
T_1 V_57 = V_155 -> V_89 . V_156 ;
T_1 V_46 = V_57 & V_134 ;
struct V_23 * V_26 ;
int V_25 = 0 ;
F_21 ( L_37 , V_7 , V_57 ) ;
if ( V_57 & V_157 ) {
switch ( V_155 -> V_89 . V_158 &
V_68 ) {
case V_137 :
V_25 = 24 * 1024 ;
break;
case V_69 :
V_25 = 128 ;
break;
}
}
V_26 = F_11 ( V_24 , V_25 ) ;
if ( ! V_26 ) {
F_58 ( V_3 , V_41 , V_150 ) ;
return - V_63 ;
}
V_26 -> V_67 = V_155 -> V_89 . V_158 ;
V_26 -> V_46 = V_46 ;
if ( ( V_26 -> V_67 & V_68 )
== V_137 ) {
F_21 ( L_38 ,
F_75 ( & V_155 -> V_89 ) ) ;
V_26 -> V_141 = 200 ;
if ( V_57 & V_157 ) {
V_26 -> V_43 |= V_145 ;
} else {
V_26 -> V_43 |= V_44 ;
if ( F_76 ( V_41 -> V_45 , V_46 ) )
V_26 -> V_43 &= ~ V_44 ;
}
}
F_29 ( & V_5 -> V_47 ) ;
if ( V_57 & V_157 ) {
V_41 -> V_65 [ V_46 ] = V_26 ;
V_41 -> V_125 [ V_150 ] . V_159 |=
( 1 << ( V_46 + V_61 ) ) ;
if ( ( V_26 -> V_67 & V_68 )
== V_137 ) {
F_35 ( & V_26 -> V_16 , & V_41 -> V_75 ) ;
V_152 = 1 ;
}
} else {
V_41 -> V_66 [ V_46 ] = V_26 ;
V_41 -> V_125 [ V_150 ] . V_159 |= ( 1 << V_46 ) ;
if ( ( V_26 -> V_67 & V_68 )
== V_137 ) {
F_35 ( & V_26 -> V_16 , & V_41 -> V_74 ) ;
V_152 = 1 ;
}
}
F_32 ( & V_5 -> V_47 ) ;
if ( V_152 && V_41 -> V_45 )
F_77 ( V_41 -> V_45 ) ;
}
return 0 ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_40 * V_41 , int V_150 )
{
struct V_1 * V_5 = V_41 -> V_5 ;
unsigned V_160 ;
int V_7 ;
struct V_21 V_161 ;
F_21 ( L_39 , V_150 ) ;
if ( V_150 >= V_41 -> V_162 )
return;
F_13 ( & V_161 ) ;
F_29 ( & V_5 -> V_47 ) ;
V_160 = V_41 -> V_125 [ V_150 ] . V_159 ;
V_41 -> V_125 [ V_150 ] . V_159 = 0 ;
for ( V_7 = 0 ; V_7 < V_61 ; V_7 ++ ) {
struct V_21 * V_22 ;
if ( ( V_160 & ( 1 << V_7 ) ) && V_41 -> V_66 [ V_7 ] ) {
V_22 = & V_41 -> V_66 [ V_7 ] -> V_16 ;
V_41 -> V_66 [ V_7 ] = NULL ;
F_70 ( V_22 , & V_161 ) ;
}
if ( ( V_160 & ( 1 << ( V_7 + V_61 ) ) ) && V_41 -> V_65 [ V_7 ] ) {
V_22 = & V_41 -> V_65 [ V_7 ] -> V_16 ;
V_41 -> V_65 [ V_7 ] = NULL ;
F_70 ( V_22 , & V_161 ) ;
}
}
F_32 ( & V_5 -> V_47 ) ;
while ( ! F_63 ( & V_161 ) ) {
struct V_23 * V_26 =
F_64 ( & V_161 , struct V_23 , V_16 ) ;
F_16 ( & V_26 -> V_16 ) ;
F_27 ( V_41 , V_26 ) ;
}
}
static int F_56 ( struct V_2 * V_3 ,
struct V_40 * V_41 , struct V_120 * V_117 ,
T_2 V_24 )
{
struct V_1 * V_5 = V_41 -> V_5 ;
int V_7 ;
int V_162 = V_117 -> V_89 . V_163 ;
if ( V_162 ) {
struct V_164 * V_125 ;
V_125 = F_7 ( V_162 * sizeof( struct V_164 ) ,
V_24 | V_165 ) ;
if ( ! V_125 )
return - V_63 ;
F_29 ( & V_5 -> V_47 ) ;
V_41 -> V_125 = V_125 ;
V_41 -> V_162 = V_162 ;
F_32 ( & V_5 -> V_47 ) ;
}
for ( V_7 = 0 ; V_7 < V_162 ; V_7 ++ ) {
struct V_121 * V_122 =
& V_117 -> V_123 [ V_7 ] -> V_124 [ 0 ] ;
if ( F_59 ( V_3 , V_41 , V_122 ,
V_24 ) )
goto V_166;
}
return 0 ;
V_166:
F_48 ( V_3 , V_41 ) ;
return - 1 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_1 * V_5 = V_41 -> V_5 ;
int V_7 ;
F_21 ( L_40 ) ;
for ( V_7 = 0 ; V_7 < V_41 -> V_162 ; V_7 ++ )
F_58 ( V_3 , V_41 , V_7 ) ;
F_29 ( & V_5 -> V_47 ) ;
if ( V_41 -> V_125 ) {
F_21 ( L_41 ) ;
F_9 ( V_41 -> V_125 ) ;
V_41 -> V_125 = NULL ;
}
V_41 -> V_162 = 0 ;
F_32 ( & V_5 -> V_47 ) ;
}
static void * F_78 ( struct V_40 * V_41 )
{
void * V_45 = NULL ;
struct V_1 * V_5 = V_41 -> V_5 ;
F_29 ( & V_5 -> V_47 ) ;
V_45 = V_41 -> V_45 ;
if ( V_45 )
F_39 ( V_45 ) ;
F_32 ( & V_5 -> V_47 ) ;
return V_45 ;
}
static void F_74 ( struct V_1 * V_5 , struct V_30 * V_30 ,
T_2 V_24 )
{
struct V_94 * V_95 ;
unsigned V_127 ;
unsigned V_97 ;
unsigned V_167 ;
void * V_45 = NULL ;
T_1 V_59 ;
int V_115 = 0 ;
unsigned V_168 = 0 ;
int V_169 = - 1 ;
struct V_40 * V_41 = NULL ;
F_23 ( V_38 , L_42 , V_39 , V_30 ) ;
V_169 = F_2 ( V_5 , V_30 -> V_116 -> V_170 ) ;
if ( V_169 < 0 ) {
V_115 = - V_71 ;
goto V_83;
}
V_41 = & V_5 -> V_9 [ V_169 ] ;
if ( ( ( V_41 -> V_43 & V_76 ) == 0 )
|| ( V_41 -> V_43 & V_86 ) ) {
F_21 ( L_43 ,
V_169 , V_30 -> V_116 -> V_170 ) ;
V_115 = - V_71 ;
goto V_83;
}
V_30 -> V_35 = V_41 ;
V_95 = (struct V_94 * ) V_30 -> V_96 ;
V_127 = F_52 ( V_95 -> V_100 ) ;
V_97 = F_52 ( V_95 -> V_98 ) ;
V_167 = F_52 ( V_95 -> V_171 ) ;
F_23 ( V_172 , L_44 ,
V_95 -> V_99 ) ;
F_23 ( V_172 , L_45 , V_95 -> V_130 ) ;
F_23 ( V_172 , L_46 , V_97 ) ;
F_23 ( V_172 , L_47 , V_127 ) ;
F_23 ( V_172 , L_48 , V_167 ) ;
V_59 = V_41 -> V_173 ++ ;
V_45 = F_78 ( V_41 ) ;
if ( V_45 == NULL ) {
F_21 ( L_49 ) ;
V_115 = - V_71 ;
goto V_83;
}
if ( ( V_95 -> V_99 & V_128 ) == V_129 ) {
switch ( V_95 -> V_130 ) {
case V_106 :
F_21 ( L_50 ) ;
break;
case V_105 :
F_21 ( L_51 ) ;
F_21 ( L_52 , V_5 -> V_10 ,
( T_1 ) F_52 ( V_95 -> V_98 ) ) ;
F_29 ( & V_5 -> V_47 ) ;
if ( V_5 -> V_10 >= 0 ) {
V_5 -> V_9 [ V_5 -> V_10 ] . V_6 =
( T_1 ) F_52 ( V_95 -> V_98 ) ;
F_21 ( L_14 ) ;
V_5 -> V_10 = - 1 ;
}
F_32 ( & V_5 -> V_47 ) ;
V_168 = 1 ;
break;
case V_109 :
F_21 ( L_53 ) ;
break;
case V_108 :
F_21 ( L_54 ) ;
if ( V_30 -> V_53 >= 1 ) {
V_30 -> V_55 = 1 ;
* ( ( T_1 * ) V_30 -> V_54 ) =
V_41 -> V_114 ;
V_168 = 1 ;
} else {
V_115 = - V_71 ;
}
break;
case V_110 :
F_21 ( L_55 ) ;
if ( V_30 -> V_53 >= 1 ) {
V_30 -> V_55 = 1 ;
* ( ( T_1 * ) V_30 -> V_54 ) =
V_41 -> V_125 [ ( T_1 ) V_127 ] . V_119 ;
F_21 ( L_56 ,
V_127 , V_41 -> V_125 [ ( T_1 ) V_127 ] . V_119 ) ;
V_168 = 1 ;
} else {
V_115 = - V_71 ;
}
break;
case V_111 :
F_21 ( L_57 ) ;
break;
}
}
if ( ! V_115 && ! V_168 ) {
int V_49 = 0 ;
if ( ( V_95 -> V_99 & V_174 ) == 0 )
V_49 = V_167 ;
V_30 -> V_55 = V_49 ;
if ( F_79 ( V_41 -> V_45 , V_59 , V_95 ,
V_30 -> V_54 , V_49 ) ) {
V_115 = - V_63 ;
} else {
if ( F_34 ( V_41 , 0 , 0 , V_30 , V_59 ) )
V_115 = - V_63 ;
}
}
F_49 ( V_45 ) ;
V_83:
if ( V_115 || V_168 ) {
F_21 ( L_58 ) ;
F_17 ( V_5 -> V_3 , V_30 , V_115 , 0 ) ;
} else {
F_77 ( V_41 -> V_45 ) ;
}
}
static int F_80 ( struct V_1 * V_5 , struct V_30 * V_30 )
{
int V_115 = 0 ;
struct V_40 * V_41 = V_30 -> V_35 ;
T_1 V_57 ;
F_81 ( V_30 ) ;
if ( ! V_30 -> V_54 && V_30 -> V_53 )
return - V_62 ;
if ( ( V_41 -> V_43 & V_76 ) == 0 )
return - V_71 ;
V_57 = F_82 ( V_30 -> V_175 ) ;
if ( V_57 ) {
if ( F_34 ( V_41 , V_57 , F_83 ( V_30 -> V_175 ) ,
V_30 , 0 ) )
V_115 = - V_71 ;
} else {
F_74 ( V_5 , V_30 , V_19 ) ;
}
return V_115 ;
}
static void F_84 ( unsigned long V_176 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_40 () ;
int V_115 = 0 ;
if ( V_5 == NULL )
return;
F_4 ( & V_34 , V_13 ) ;
while ( ! F_63 ( & V_5 -> V_177 ) ) {
struct V_11 * V_12 =
F_64 ( & V_5 -> V_177 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_34 , V_13 ) ;
V_30 = V_12 -> V_30 ;
F_8 ( V_12 ) ;
V_115 = F_80 ( V_5 , V_30 ) ;
if ( V_115 )
F_17 ( V_5 -> V_3 , V_30 , V_115 , 0 ) ;
F_4 ( & V_34 , V_13 ) ;
}
F_6 ( & V_34 , V_13 ) ;
F_42 ( V_5 ) ;
}
static void F_85 ( struct V_40 * V_41 , T_1 V_46 , struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_21 * V_22 ;
struct V_1 * V_5 ;
unsigned long V_13 ;
T_1 V_178 ;
if ( V_41 == NULL ) {
F_21 ( L_59 , V_30 ) ;
return;
}
V_5 = V_41 -> V_5 ;
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
goto V_179;
}
}
F_6 ( & V_34 , V_13 ) ;
V_12 = NULL ;
F_4 ( & V_5 -> V_47 , V_13 ) ;
F_15 (e, &ozhcd->orphanage) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_86 ( V_22 ) ;
F_21 ( L_61 ) ;
goto V_83;
}
}
V_178 = ( V_46 & 0xf ) ;
V_12 = NULL ;
if ( ( V_46 & V_174 ) && V_178 )
V_12 = F_87 ( V_41 -> V_65 [ V_178 ] , V_30 ) ;
else
V_12 = F_87 ( V_41 -> V_66 [ V_178 ] , V_30 ) ;
V_83:
F_6 ( & V_5 -> V_47 , V_13 ) ;
V_179:
if ( V_12 ) {
V_30 -> V_55 = 0 ;
F_8 ( V_12 ) ;
F_17 ( V_5 -> V_3 , V_30 , - V_71 , 0 ) ;
}
}
static void F_88 ( unsigned long V_176 )
{
unsigned long V_13 ;
struct V_30 * V_30 ;
struct V_1 * V_5 = F_40 () ;
if ( V_5 == NULL )
return;
F_4 ( & V_34 , V_13 ) ;
while ( ! F_63 ( & V_5 -> V_180 ) ) {
struct V_11 * V_12 =
F_64 ( & V_5 -> V_180 ,
struct V_11 , V_16 ) ;
F_16 ( & V_12 -> V_16 ) ;
F_6 ( & V_34 , V_13 ) ;
V_30 = V_12 -> V_30 ;
if ( V_30 -> V_64 )
F_85 ( V_12 -> V_41 , V_12 -> V_46 , V_30 ) ;
F_8 ( V_12 ) ;
F_4 ( & V_34 , V_13 ) ;
}
F_6 ( & V_34 , V_13 ) ;
F_42 ( V_5 ) ;
}
static void F_89 ( struct V_1 * V_5 , int V_31 )
{
if ( V_5 ) {
struct V_11 * V_12 ;
while ( ! F_63 ( & V_5 -> V_48 ) ) {
V_12 = F_64 ( & V_5 -> V_48 ,
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
V_3 -> V_181 = 200 ;
V_3 -> V_182 = V_183 ;
V_3 -> V_184 = 1 ;
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
static int F_93 ( struct V_2 * V_3 , struct V_30 * V_30 ,
T_2 V_24 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_115 = 0 ;
int V_169 ;
struct V_40 * V_41 ;
unsigned long V_13 ;
struct V_11 * V_12 ;
F_23 ( V_38 , L_65 ,
V_39 , V_30 ) ;
if ( F_94 ( V_5 == NULL ) ) {
F_23 ( V_38 , L_66 ,
V_39 , V_30 ) ;
return - V_71 ;
}
if ( F_94 ( V_3 -> V_182 != V_183 ) ) {
F_23 ( V_38 , L_67 ,
V_39 , V_30 ) ;
return - V_71 ;
}
V_169 = F_2 ( V_5 , V_30 -> V_116 -> V_170 ) ;
if ( V_169 < 0 )
return - V_71 ;
V_41 = & V_5 -> V_9 [ V_169 ] ;
if ( V_41 == NULL )
return - V_71 ;
if ( ( V_41 -> V_43 & V_76 ) == 0 ) {
F_21 ( L_43 ,
V_169 , V_30 -> V_116 -> V_170 ) ;
return - V_71 ;
}
V_30 -> V_35 = V_41 ;
V_12 = F_3 () ;
if ( F_94 ( V_12 == NULL ) )
return - V_63 ;
V_12 -> V_30 = V_30 ;
F_4 ( & V_34 , V_13 ) ;
V_115 = F_95 ( V_3 , V_30 ) ;
if ( F_94 ( V_115 ) ) {
F_6 ( & V_34 , V_13 ) ;
F_8 ( V_12 ) ;
return V_115 ;
}
F_35 ( & V_12 -> V_16 , & V_5 -> V_177 ) ;
F_6 ( & V_34 , V_13 ) ;
F_96 ( & V_185 ) ;
F_97 ( & V_37 ) ;
return 0 ;
}
static struct V_11 * F_87 ( struct V_23 * V_26 ,
struct V_30 * V_30 )
{
struct V_11 * V_12 = NULL ;
struct V_21 * V_22 ;
if ( F_94 ( V_26 == NULL ) )
return NULL ;
F_15 (e, &ep->urb_list) {
V_12 = F_5 ( V_22 , struct V_11 , V_16 ) ;
if ( V_12 -> V_30 == V_30 ) {
F_16 ( V_22 ) ;
if ( F_98 ( V_30 -> V_175 ) ) {
V_26 -> V_28 -= V_30 -> V_142 ;
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
struct V_11 * V_12 = NULL ;
int V_115 ;
unsigned long V_13 ;
F_23 ( V_38 , L_68 , V_39 , V_30 ) ;
V_12 = F_3 () ;
if ( F_94 ( V_12 == NULL ) )
return - V_63 ;
F_4 ( & V_34 , V_13 ) ;
V_115 = F_100 ( V_3 , V_30 , V_31 ) ;
if ( ( V_115 == 0 ) && V_30 -> V_35 ) {
V_12 -> V_30 = V_30 ;
V_12 -> V_41 = (struct V_40 * ) V_30 -> V_35 ;
V_12 -> V_46 = F_82 ( V_30 -> V_175 ) ;
if ( F_83 ( V_30 -> V_175 ) )
V_12 -> V_46 |= V_174 ;
F_35 ( & V_12 -> V_16 , & V_5 -> V_180 ) ;
F_6 ( & V_34 , V_13 ) ;
F_96 ( & V_186 ) ;
} else {
F_6 ( & V_34 , V_13 ) ;
F_8 ( V_12 ) ;
}
return V_115 ;
}
static void F_101 ( struct V_2 * V_3 ,
struct V_154 * V_26 )
{
F_21 ( L_69 ) ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_154 * V_26 )
{
F_21 ( L_70 ) ;
}
static int F_103 ( struct V_2 * V_3 )
{
F_21 ( L_71 ) ;
return F_65 () ;
}
static int F_104 ( struct V_2 * V_3 , char * V_187 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_7 ;
F_23 ( V_188 , L_72 ) ;
V_187 [ 0 ] = 0 ;
F_29 ( & V_5 -> V_47 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_5 -> V_9 [ V_7 ] . V_43 & V_77 ) {
F_23 ( V_188 , L_73 , V_7 ) ;
V_5 -> V_9 [ V_7 ] . V_43 &= ~ V_77 ;
V_187 [ 0 ] |= 1 << ( V_7 + 1 ) ;
}
}
F_32 ( & V_5 -> V_47 ) ;
return V_187 [ 0 ] ? 1 : 0 ;
}
static void F_105 ( struct V_2 * V_3 ,
struct V_189 * V_89 )
{
F_23 ( V_188 , L_74 ) ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_190 = 0x29 ;
V_89 -> V_191 = 9 ;
V_89 -> V_192 = ( V_193 V_194 )
F_106 ( 0x0001 ) ;
V_89 -> V_195 = V_8 ;
}
static int F_107 ( struct V_2 * V_3 , T_3 V_97 , T_3 V_127 )
{
struct V_40 * V_41 ;
int V_60 = 0 ;
T_1 V_196 = ( T_1 ) V_127 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_197 = 0 ;
unsigned V_198 = 0 ;
F_23 ( V_188 , L_75 ) ;
if ( ( V_196 < 1 ) || ( V_196 > V_8 ) )
return - V_71 ;
V_41 = & V_5 -> V_9 [ V_196 - 1 ] ;
switch ( V_97 ) {
case V_199 :
F_23 ( V_188 , L_76 ) ;
break;
case V_200 :
F_23 ( V_188 , L_77 ) ;
break;
case V_201 :
F_23 ( V_188 , L_78 ) ;
break;
case V_202 :
F_23 ( V_188 , L_79 ) ;
break;
case V_203 :
F_23 ( V_188 , L_80 ) ;
V_197 = V_204 | ( V_88 << 16 ) ;
V_198 = V_87 ;
V_5 -> V_9 [ V_196 - 1 ] . V_6 = 0 ;
break;
case V_205 :
F_23 ( V_188 , L_81 ) ;
V_197 |= V_206 ;
break;
case V_207 :
F_23 ( V_188 , L_82 ) ;
break;
case V_208 :
F_23 ( V_188 , L_83 ) ;
break;
case V_209 :
F_23 ( V_188 , L_84 ) ;
break;
case V_210 :
F_23 ( V_188 , L_85 ) ;
break;
case V_211 :
F_23 ( V_188 , L_86 ) ;
break;
case V_212 :
F_23 ( V_188 , L_87 ) ;
break;
case V_213 :
F_23 ( V_188 , L_88 ) ;
break;
case V_214 :
F_23 ( V_188 , L_89 ) ;
break;
default:
F_23 ( V_188 , L_90 , V_97 ) ;
break;
}
if ( V_197 || V_198 ) {
F_29 ( & V_41 -> V_84 ) ;
V_41 -> V_31 &= ~ V_198 ;
V_41 -> V_31 |= V_197 ;
F_32 ( & V_41 -> V_84 ) ;
}
F_23 ( V_188 , L_91 , V_196 ,
V_41 -> V_31 ) ;
return V_60 ;
}
static int F_108 ( struct V_2 * V_3 , T_3 V_97 , T_3 V_127 )
{
struct V_40 * V_41 ;
int V_60 = 0 ;
T_1 V_196 = ( T_1 ) V_127 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_198 = 0 ;
F_23 ( V_188 , L_92 ) ;
if ( ( V_196 < 1 ) || ( V_196 > V_8 ) )
return - V_71 ;
V_41 = & V_5 -> V_9 [ V_196 - 1 ] ;
switch ( V_97 ) {
case V_199 :
F_23 ( V_188 , L_76 ) ;
break;
case V_200 :
F_23 ( V_188 , L_77 ) ;
V_198 = V_204 ;
break;
case V_201 :
F_23 ( V_188 , L_78 ) ;
break;
case V_202 :
F_23 ( V_188 , L_79 ) ;
break;
case V_203 :
F_23 ( V_188 , L_80 ) ;
break;
case V_205 :
F_23 ( V_188 , L_81 ) ;
V_198 |= V_206 ;
break;
case V_207 :
F_23 ( V_188 , L_82 ) ;
break;
case V_208 :
F_23 ( V_188 , L_83 ) ;
V_198 = ( V_79 << 16 ) ;
break;
case V_209 :
F_23 ( V_188 , L_84 ) ;
V_198 = ( V_215 << 16 ) ;
break;
case V_210 :
F_23 ( V_188 , L_85 ) ;
break;
case V_211 :
F_23 ( V_188 , L_86 ) ;
break;
case V_212 :
F_23 ( V_188 , L_87 ) ;
V_198 = ( V_212 << 16 ) ;
break;
case V_213 :
F_23 ( V_188 , L_88 ) ;
break;
case V_214 :
F_23 ( V_188 , L_89 ) ;
break;
default:
F_23 ( V_188 , L_90 , V_97 ) ;
break;
}
if ( V_198 ) {
F_29 ( & V_41 -> V_84 ) ;
V_41 -> V_31 &= ~ V_198 ;
F_32 ( & V_41 -> V_84 ) ;
}
F_23 ( V_188 , L_91 , V_196 ,
V_5 -> V_9 [ V_196 - 1 ] . V_31 ) ;
return V_60 ;
}
static int F_109 ( struct V_2 * V_3 , T_3 V_127 , char * V_187 )
{
struct V_1 * V_5 ;
T_4 V_31 = 0 ;
if ( ( V_127 < 1 ) || ( V_127 > V_8 ) )
return - V_71 ;
V_5 = F_1 ( V_3 ) ;
F_23 ( V_188 , L_93 , V_127 ) ;
V_31 = V_5 -> V_9 [ V_127 - 1 ] . V_31 ;
F_110 ( F_111 ( V_31 ) , ( V_216 * ) V_187 ) ;
F_23 ( V_188 , L_94 , V_127 , V_31 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , T_3 V_217 , T_3 V_97 ,
T_3 V_127 , char * V_187 , T_3 V_167 )
{
int V_60 = 0 ;
F_23 ( V_188 , L_95 ) ;
switch ( V_217 ) {
case V_218 :
F_23 ( V_188 , L_96 , V_217 ) ;
break;
case V_219 :
V_60 = F_108 ( V_3 , V_97 , V_127 ) ;
break;
case V_220 :
F_105 ( V_3 , (struct V_189 * ) V_187 ) ;
break;
case V_221 :
F_23 ( V_188 , L_97 ,
V_217 ) ;
F_110 ( F_113 ( 0 ) , ( V_216 * ) V_187 ) ;
break;
case V_222 :
V_60 = F_109 ( V_3 , V_127 , V_187 ) ;
break;
case V_223 :
F_23 ( V_188 , L_98 , V_217 ) ;
break;
case V_224 :
V_60 = F_107 ( V_3 , V_97 , V_127 ) ;
break;
default:
F_23 ( V_188 , L_99 , V_217 ) ;
break;
}
return V_60 ;
}
static int F_114 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_23 ( V_188 , L_100 ) ;
V_5 = F_1 ( V_3 ) ;
F_29 ( & V_5 -> V_47 ) ;
V_3 -> V_182 = V_225 ;
V_5 -> V_43 |= V_85 ;
F_32 ( & V_5 -> V_47 ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_23 ( V_188 , L_101 ) ;
V_5 = F_1 ( V_3 ) ;
F_29 ( & V_5 -> V_47 ) ;
V_5 -> V_43 &= ~ V_85 ;
V_3 -> V_182 = V_183 ;
F_32 ( & V_5 -> V_47 ) ;
return 0 ;
}
static void F_116 ( struct V_226 * V_116 )
{
F_21 ( L_102 ) ;
}
static int F_117 ( struct V_226 * V_116 )
{
int V_7 ;
int V_60 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
F_21 ( L_103 ) ;
V_3 = F_118 ( & V_227 , & V_116 -> V_116 , F_119 ( & V_116 -> V_116 ) ) ;
if ( V_3 == NULL ) {
F_21 ( L_104 ) ;
return - V_63 ;
}
V_5 = F_1 ( V_3 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_13 ( & V_5 -> V_177 ) ;
F_13 ( & V_5 -> V_180 ) ;
F_13 ( & V_5 -> V_48 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_10 = - 1 ;
F_120 ( & V_5 -> V_47 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_40 * V_41 = & V_5 -> V_9 [ V_7 ] ;
V_41 -> V_5 = V_5 ;
V_41 -> V_43 = 0 ;
V_41 -> V_31 = 0 ;
V_41 -> V_6 = 0xff ;
F_120 ( & V_41 -> V_84 ) ;
}
V_60 = F_121 ( V_3 , 0 , 0 ) ;
if ( V_60 ) {
F_21 ( L_105 ) ;
F_43 ( V_3 ) ;
return - 1 ;
}
F_29 ( & V_80 ) ;
V_81 = V_5 ;
F_32 ( & V_80 ) ;
return 0 ;
}
static int F_122 ( struct V_226 * V_116 )
{
struct V_2 * V_3 = F_123 ( V_116 ) ;
struct V_1 * V_5 ;
F_21 ( L_106 ) ;
if ( V_3 == NULL )
return - 1 ;
V_5 = F_1 ( V_3 ) ;
F_29 ( & V_80 ) ;
if ( V_5 == V_81 )
V_81 = NULL ;
F_32 ( & V_80 ) ;
F_21 ( L_107 ) ;
F_89 ( V_5 , - V_71 ) ;
F_21 ( L_108 ) ;
F_124 ( V_3 ) ;
F_43 ( V_3 ) ;
F_10 () ;
return 0 ;
}
static int F_125 ( struct V_226 * V_116 , T_5 V_228 )
{
F_21 ( L_109 ) ;
return 0 ;
}
static int F_126 ( struct V_226 * V_116 )
{
F_21 ( L_110 ) ;
return 0 ;
}
int F_127 ( void )
{
int V_60 ;
if ( F_128 () )
return - V_229 ;
F_129 ( & V_185 , F_84 , 0 ) ;
F_129 ( & V_186 , F_88 , 0 ) ;
V_60 = F_130 ( & V_230 ) ;
F_21 ( L_111 , V_60 ) ;
if ( V_60 )
goto error;
V_231 = F_131 ( V_232 , - 1 ) ;
if ( V_231 == NULL ) {
V_60 = - V_63 ;
goto V_233;
}
F_21 ( L_112 ) ;
V_60 = F_132 ( V_231 ) ;
if ( V_60 )
goto V_234;
F_21 ( L_113 ) ;
return 0 ;
V_234:
F_133 ( V_231 ) ;
V_233:
F_134 ( & V_230 ) ;
error:
F_135 ( & V_185 ) ;
F_135 ( & V_186 ) ;
F_21 ( L_114 , V_60 ) ;
return V_60 ;
}
void F_136 ( void )
{
F_137 ( & V_185 ) ;
F_137 ( & V_186 ) ;
F_138 ( V_231 ) ;
F_134 ( & V_230 ) ;
F_21 ( L_115 , F_24 ( & V_37 ) ) ;
}
