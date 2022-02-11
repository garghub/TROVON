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
return F_4 ( V_12 , V_13 ) ;
}
static void F_5 ( struct V_11 * V_14 )
{
if ( ! V_14 )
return;
F_6 ( V_12 , V_14 ) ;
}
static struct V_15 * F_7 ( int V_16 , T_2 V_17 )
{
struct V_15 * V_18 ;
V_18 = F_8 ( sizeof( struct V_15 ) + V_16 , V_17 ) ;
if ( ! V_18 )
return NULL ;
F_9 ( & V_18 -> V_19 ) ;
F_9 ( & V_18 -> V_20 ) ;
V_18 -> V_21 = - 1 ;
if ( V_16 ) {
V_18 -> V_16 = V_16 ;
V_18 -> V_22 = ( T_1 * ) ( V_18 + 1 ) ;
}
return V_18 ;
}
static struct V_11 * F_10 ( struct V_1 * V_5 ,
struct V_23 * V_23 )
{
struct V_11 * V_14 ;
F_11 (urbl, &ozhcd->urb_cancel_list, link) {
if ( V_23 == V_14 -> V_23 ) {
F_12 ( & V_14 -> V_20 ) ;
return V_14 ;
}
}
return NULL ;
}
static void F_13 ( struct V_2 * V_3 , struct V_23 * V_23 ,
int V_24 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_25 ;
struct V_11 * V_26 ;
F_14 ( & V_27 , V_25 ) ;
F_15 ( V_3 , V_23 ) ;
V_23 -> V_28 = NULL ;
V_26 = F_10 ( V_5 , V_23 ) ;
F_16 ( & V_27 ) ;
if ( F_17 ( V_23 ) ) {
F_18 ( V_29 , L_1 , V_23 ) ;
} else {
F_19 ( & V_30 ) ;
F_20 ( V_3 , V_23 , V_24 ) ;
}
F_21 ( & V_27 ) ;
F_22 ( & V_27 , V_25 ) ;
F_5 ( V_26 ) ;
}
static void F_23 ( struct V_31 * V_32 , struct V_15 * V_18 )
{
if ( V_32 ) {
F_24 ( V_33 ) ;
struct V_1 * V_5 = V_32 -> V_5 ;
if ( V_18 -> V_34 & V_35 )
F_25 ( V_32 -> V_36 , V_18 -> V_37 ) ;
F_26 ( & V_5 -> V_38 ) ;
F_27 ( & V_18 -> V_19 , & V_33 ) ;
F_28 ( & V_33 , & V_5 -> V_39 ) ;
F_29 ( & V_5 -> V_38 ) ;
}
F_18 ( V_29 , L_2 ) ;
F_30 ( V_18 ) ;
}
static void F_31 ( struct V_31 * V_32 ,
struct V_15 * V_18 ,
struct V_23 * V_23 )
{
int V_40 , V_41 , V_42 ;
V_40 = V_18 -> V_22 [ V_18 -> V_43 ] ;
if ( V_40 <= V_23 -> V_44 )
V_41 = V_40 ;
else
V_41 = V_23 -> V_44 ;
if ( ++ V_18 -> V_43 == V_18 -> V_16 )
V_18 -> V_43 = 0 ;
V_42 = V_18 -> V_16 - V_18 -> V_43 ;
if ( V_42 >= V_41 )
V_42 = V_41 ;
memcpy ( V_23 -> V_45 , & V_18 -> V_22 [ V_18 -> V_43 ] , V_42 ) ;
if ( V_42 < V_41 ) {
memcpy ( ( V_23 -> V_45 + V_42 ) , V_18 -> V_22 ,
( V_41 - V_42 ) ) ;
V_18 -> V_43 = V_41 - V_42 ;
} else {
V_18 -> V_43 += V_42 ;
}
V_23 -> V_46 = V_41 ;
if ( V_18 -> V_43 == V_18 -> V_16 )
V_18 -> V_43 = 0 ;
V_18 -> V_47 -- ;
F_18 ( V_29 , L_3 ,
V_41 ) ;
F_13 ( V_32 -> V_5 -> V_3 , V_23 , 0 ) ;
}
static int F_32 ( struct V_31 * V_32 , T_1 V_48 , int V_49 ,
struct V_23 * V_23 , T_1 V_50 )
{
struct V_11 * V_14 ;
struct V_15 * V_18 = NULL ;
int V_51 = 0 ;
if ( V_48 >= V_52 ) {
F_18 ( V_29 , L_4 , V_53 ) ;
return - V_54 ;
}
V_14 = F_3 () ;
if ( ! V_14 )
return - V_55 ;
V_14 -> V_56 = 0 ;
V_14 -> V_23 = V_23 ;
V_14 -> V_50 = V_50 ;
V_14 -> V_37 = V_48 ;
F_26 ( & V_32 -> V_5 -> V_38 ) ;
if ( V_23 -> V_57 ) {
F_29 ( & V_32 -> V_5 -> V_38 ) ;
F_18 ( V_29 , L_5 , V_23 ) ;
F_13 ( V_32 -> V_5 -> V_3 , V_23 , 0 ) ;
F_5 ( V_14 ) ;
return 0 ;
}
if ( V_49 )
V_18 = V_32 -> V_58 [ V_48 ] ;
else
V_18 = V_32 -> V_59 [ V_48 ] ;
if ( ! V_18 ) {
V_51 = - V_55 ;
goto V_60;
}
if ( ( ( V_18 -> V_61 & V_62 ) == V_63 )
&& V_18 -> V_47 > 0 ) {
F_5 ( V_14 ) ;
F_29 ( & V_32 -> V_5 -> V_38 ) ;
F_31 ( V_32 , V_18 , V_23 ) ;
return 0 ;
}
if ( V_32 -> V_36 ) {
F_33 ( & V_14 -> V_20 , & V_18 -> V_19 ) ;
if ( ! V_49 && V_48 && ( V_18 -> V_21 < 0 ) ) {
F_34 ( & V_18 -> V_64 ) ;
V_18 -> V_21 = 0 ;
}
} else {
V_51 = - V_65 ;
}
V_60:
F_29 ( & V_32 -> V_5 -> V_38 ) ;
if ( V_51 )
F_5 ( V_14 ) ;
return V_51 ;
}
static int F_35 ( struct V_31 * V_32 , T_1 V_48 , int V_49 ,
struct V_23 * V_23 )
{
struct V_11 * V_14 = NULL ;
struct V_15 * V_18 ;
F_26 ( & V_32 -> V_5 -> V_38 ) ;
if ( V_49 )
V_18 = V_32 -> V_58 [ V_48 ] ;
else
V_18 = V_32 -> V_59 [ V_48 ] ;
if ( V_18 ) {
struct V_66 * V_67 ;
F_36 (e, &ep->urb_list) {
V_14 = F_37 ( V_67 , struct V_11 , V_20 ) ;
if ( V_14 -> V_23 == V_23 ) {
F_12 ( V_67 ) ;
break;
}
V_14 = NULL ;
}
}
F_29 ( & V_32 -> V_5 -> V_38 ) ;
F_5 ( V_14 ) ;
return V_14 ? 0 : - V_68 ;
}
static struct V_23 * F_38 ( struct V_31 * V_32 , int V_69 ,
T_1 V_50 )
{
struct V_1 * V_5 = V_32 -> V_5 ;
struct V_23 * V_23 = NULL ;
struct V_11 * V_14 ;
struct V_15 * V_18 ;
F_26 ( & V_5 -> V_38 ) ;
V_18 = V_32 -> V_59 [ V_69 ] ;
if ( V_18 ) {
struct V_66 * V_67 ;
F_36 (e, &ep->urb_list) {
V_14 = F_37 ( V_67 , struct V_11 , V_20 ) ;
if ( V_14 -> V_50 == V_50 ) {
V_23 = V_14 -> V_23 ;
F_12 ( V_67 ) ;
break;
}
}
}
F_29 ( & V_5 -> V_38 ) ;
if ( V_23 )
F_5 ( V_14 ) ;
return V_23 ;
}
static void F_39 ( struct V_31 * V_32 , void * V_36 )
{
F_9 ( & V_32 -> V_70 ) ;
F_9 ( & V_32 -> V_71 ) ;
V_32 -> V_34 |= V_72 | V_73 ;
V_32 -> V_24 |= V_74 |
( V_75 << 16 ) ;
F_40 ( V_36 ) ;
V_32 -> V_36 = V_36 ;
}
static struct V_1 * F_41 ( void )
{
struct V_1 * V_5 ;
F_26 ( & V_76 ) ;
V_5 = V_77 ;
if ( V_5 )
F_42 ( V_5 -> V_3 ) ;
F_29 ( & V_76 ) ;
return V_5 ;
}
static inline void F_43 ( struct V_1 * V_5 )
{
if ( V_5 )
F_44 ( V_5 -> V_3 ) ;
}
struct V_31 * F_45 ( void * V_36 )
{
int V_7 ;
struct V_31 * V_78 ;
struct V_1 * V_5 ;
struct V_15 * V_18 ;
V_5 = F_41 () ;
if ( ! V_5 )
return NULL ;
V_18 = F_7 ( 0 , V_13 ) ;
if ( ! V_18 )
goto V_79;
F_26 ( & V_5 -> V_38 ) ;
if ( V_5 -> V_10 >= 0 )
goto V_80;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_31 * V_32 = & V_5 -> V_9 [ V_7 ] ;
F_21 ( & V_32 -> V_81 ) ;
if ( ! ( V_32 -> V_34 & ( V_72 | V_73 ) ) ) {
F_39 ( V_32 , V_36 ) ;
F_16 ( & V_32 -> V_81 ) ;
break;
}
F_16 ( & V_32 -> V_81 ) ;
}
if ( V_7 == V_8 )
goto V_80;
V_5 -> V_10 = V_7 ;
V_78 = & V_5 -> V_9 [ V_7 ] ;
V_78 -> V_59 [ 0 ] = V_18 ;
F_29 ( & V_5 -> V_38 ) ;
if ( V_5 -> V_34 & V_82 )
F_46 ( V_5 -> V_3 ) ;
F_47 ( V_5 -> V_3 ) ;
F_43 ( V_5 ) ;
return V_78 ;
V_80:
F_29 ( & V_5 -> V_38 ) ;
F_23 ( NULL , V_18 ) ;
V_79:
F_43 ( V_5 ) ;
return NULL ;
}
void F_48 ( struct V_31 * V_32 )
{
struct V_1 * V_5 ;
void * V_36 ;
struct V_15 * V_18 = NULL ;
if ( V_32 == NULL ) {
F_18 ( V_29 , L_6 , V_53 ) ;
return;
}
V_5 = V_32 -> V_5 ;
if ( V_5 == NULL )
return;
F_26 ( & V_5 -> V_38 ) ;
if ( ( V_5 -> V_10 >= 0 ) &&
( V_32 == & V_5 -> V_9 [ V_5 -> V_10 ] ) ) {
F_18 ( V_29 , L_7 ) ;
V_5 -> V_10 = - 1 ;
}
F_21 ( & V_32 -> V_81 ) ;
V_32 -> V_34 |= V_83 ;
F_16 ( & V_32 -> V_81 ) ;
F_29 ( & V_5 -> V_38 ) ;
F_49 ( V_5 -> V_3 , V_32 ) ;
F_26 ( & V_32 -> V_81 ) ;
V_36 = V_32 -> V_36 ;
V_32 -> V_36 = NULL ;
V_32 -> V_6 = 0xff ;
V_32 -> V_84 = 0 ;
V_32 -> V_34 &= ~ ( V_72 | V_83 ) ;
V_32 -> V_34 |= V_73 ;
V_32 -> V_24 &= ~ ( V_74 | V_85 ) ;
V_32 -> V_24 |= ( V_75 << 16 ) ;
if ( V_32 -> V_59 [ 0 ] ) {
V_18 = V_32 -> V_59 [ 0 ] ;
V_32 -> V_59 [ 0 ] = NULL ;
}
F_29 ( & V_32 -> V_81 ) ;
if ( V_18 )
F_23 ( V_32 , V_18 ) ;
F_47 ( V_5 -> V_3 ) ;
F_50 ( V_36 ) ;
}
void F_51 ( void * V_36 , void * V_78 )
{
struct V_31 * V_32 = V_78 ;
struct V_1 * V_5 = V_32 -> V_5 ;
F_18 ( V_29 , L_8 ) ;
F_26 ( & V_32 -> V_81 ) ;
V_32 -> V_34 |= V_73 ;
V_32 -> V_24 |= V_86 ;
V_32 -> V_24 |= ( V_87 << 16 ) ;
F_29 ( & V_32 -> V_81 ) ;
F_49 ( V_5 -> V_3 , V_32 ) ;
F_47 ( V_5 -> V_3 ) ;
}
void F_52 ( void * V_78 , T_1 V_50 , T_1 V_24 , const T_1 * V_88 ,
T_1 V_89 , T_3 V_90 , T_3 V_91 )
{
struct V_31 * V_32 = V_78 ;
struct V_23 * V_23 ;
int V_51 = 0 ;
F_18 ( V_29 , L_9 ,
V_89 , V_90 , V_91 ) ;
V_23 = F_38 ( V_32 , 0 , V_50 ) ;
if ( ! V_23 )
return;
if ( V_24 == 0 ) {
unsigned int V_42 ;
unsigned int V_92 = V_23 -> V_44 ;
if ( V_92 > V_91 )
V_92 = V_91 ;
V_42 = V_92 - V_90 ;
if ( V_89 <= V_42 )
V_42 = V_89 ;
memcpy ( V_23 -> V_45 + V_90 , V_88 , V_42 ) ;
V_90 += V_42 ;
if ( V_90 < V_92 ) {
struct V_93 * V_94 =
(struct V_93 * ) V_23 -> V_95 ;
unsigned V_96 = F_53 ( V_94 -> V_97 ) ;
if ( F_32 ( V_32 , 0 , 0 , V_23 , V_50 ) )
V_51 = - V_55 ;
else if ( F_54 ( V_32 -> V_36 , V_50 ,
V_94 -> V_98 , ( T_1 ) ( V_96 >> 8 ) ,
( T_1 ) V_96 , V_94 -> V_99 , V_90 ,
V_92 - V_90 ) ) {
F_35 ( V_32 , 0 , 0 , V_23 ) ;
V_51 = - V_55 ;
}
if ( V_51 == 0 )
return;
}
}
V_23 -> V_46 = V_91 ;
F_13 ( V_32 -> V_5 -> V_3 , V_23 , 0 ) ;
}
static void F_55 ( T_1 V_100 )
{
switch ( V_100 ) {
case V_101 :
F_18 ( V_29 , L_10 ) ;
break;
case V_102 :
F_18 ( V_29 , L_11 ) ;
break;
case V_103 :
F_18 ( V_29 , L_12 ) ;
break;
case V_104 :
F_18 ( V_29 , L_13 ) ;
break;
case V_105 :
F_18 ( V_29 , L_14 ) ;
break;
case V_106 :
F_18 ( V_29 , L_15 ) ;
break;
case V_107 :
F_18 ( V_29 , L_16 ) ;
break;
case V_108 :
F_18 ( V_29 , L_17 ) ;
break;
case V_109 :
F_18 ( V_29 , L_18 ) ;
break;
case V_110 :
F_18 ( V_29 , L_19 ) ;
break;
case V_111 :
F_18 ( V_29 , L_20 ) ;
break;
}
}
static void F_56 ( struct V_31 * V_32 , struct V_23 * V_23 ,
T_1 V_112 , T_1 V_84 )
{
int V_113 = 0 ;
struct V_2 * V_3 = V_32 -> V_5 -> V_3 ;
if ( V_112 == 0 ) {
V_32 -> V_84 = V_84 ;
F_49 ( V_3 , V_32 ) ;
if ( F_57 ( V_3 , V_32 ,
& V_23 -> V_114 -> V_115 [ V_32 -> V_84 - 1 ] , V_13 ) ) {
V_113 = - V_55 ;
}
} else {
V_113 = - V_55 ;
}
F_13 ( V_3 , V_23 , V_113 ) ;
}
static void F_58 ( struct V_31 * V_32 , struct V_23 * V_23 ,
T_1 V_112 , T_1 V_116 , T_1 V_117 )
{
struct V_2 * V_3 = V_32 -> V_5 -> V_3 ;
int V_113 = 0 ;
if ( ( V_112 == 0 ) && ( V_32 -> V_84 > 0 ) ) {
struct V_118 * V_115 ;
struct V_119 * V_120 ;
F_18 ( V_29 , L_21 , V_116 , V_117 ) ;
F_59 ( V_3 , V_32 , V_116 ) ;
V_115 = & V_23 -> V_114 -> V_115 [ V_32 -> V_84 - 1 ] ;
V_120 = & V_115 -> V_121 [ V_116 ] -> V_122 [ V_117 ] ;
if ( F_60 ( V_3 , V_32 , V_120 ,
V_13 ) )
V_113 = - V_55 ;
else
V_32 -> V_123 [ V_116 ] . V_117 = V_117 ;
} else {
V_113 = - V_55 ;
}
F_13 ( V_3 , V_23 , V_113 ) ;
}
void F_61 ( void * V_78 , T_1 V_50 , T_1 V_112 , const T_1 * V_124 ,
int V_40 )
{
struct V_31 * V_32 = V_78 ;
struct V_23 * V_23 ;
struct V_93 * V_94 ;
struct V_2 * V_3 = V_32 -> V_5 -> V_3 ;
unsigned V_125 ;
unsigned V_96 ;
F_18 ( V_29 , L_22 , V_112 , V_40 ) ;
V_23 = F_38 ( V_32 , 0 , V_50 ) ;
if ( ! V_23 ) {
F_18 ( V_29 , L_23 ) ;
return;
}
V_94 = (struct V_93 * ) V_23 -> V_95 ;
V_125 = F_53 ( V_94 -> V_99 ) ;
V_96 = F_53 ( V_94 -> V_97 ) ;
if ( ( V_94 -> V_98 & V_126 ) == V_127 ) {
F_55 ( V_94 -> V_128 ) ;
switch ( V_94 -> V_128 ) {
case V_108 :
F_56 ( V_32 , V_23 , V_112 ,
( T_1 ) V_96 ) ;
break;
case V_110 :
F_58 ( V_32 , V_23 , V_112 ,
( T_1 ) V_125 , ( T_1 ) V_96 ) ;
break;
default:
F_13 ( V_3 , V_23 , 0 ) ;
}
} else {
int V_42 ;
F_18 ( V_29 , L_24 ) ;
if ( V_40 ) {
if ( V_40 <= V_23 -> V_44 )
V_42 = V_40 ;
else
V_42 = V_23 -> V_44 ;
memcpy ( V_23 -> V_45 , V_124 , V_42 ) ;
V_23 -> V_46 = V_42 ;
}
F_13 ( V_3 , V_23 , 0 ) ;
}
}
static int F_62 ( struct V_15 * V_18 , const T_1 * V_124 ,
int V_40 )
{
int V_129 ;
int V_42 ;
if ( ! V_18 -> V_22 )
return - 1 ;
V_129 = V_18 -> V_43 - V_18 -> V_130 - 1 ;
if ( V_129 < 0 )
V_129 += V_18 -> V_16 ;
if ( V_129 < ( V_40 + 1 ) ) {
F_18 ( V_29 , L_25 ) ;
return - 1 ;
}
V_18 -> V_22 [ V_18 -> V_130 ] = ( T_1 ) V_40 ;
if ( ++ V_18 -> V_130 == V_18 -> V_16 )
V_18 -> V_130 = 0 ;
V_42 = V_18 -> V_16 - V_18 -> V_130 ;
if ( V_42 > V_40 )
V_42 = V_40 ;
memcpy ( & V_18 -> V_22 [ V_18 -> V_130 ] , V_124 , V_42 ) ;
if ( V_42 < V_40 ) {
memcpy ( V_18 -> V_22 , V_124 + V_42 , V_40 - V_42 ) ;
V_18 -> V_130 = V_40 - V_42 ;
} else {
V_18 -> V_130 += V_42 ;
}
if ( V_18 -> V_130 == V_18 -> V_16 )
V_18 -> V_130 = 0 ;
V_18 -> V_47 ++ ;
return 0 ;
}
void F_63 ( void * V_78 , T_1 V_131 , const T_1 * V_124 , int V_40 )
{
struct V_31 * V_32 = (struct V_31 * ) V_78 ;
struct V_15 * V_18 ;
struct V_1 * V_5 = V_32 -> V_5 ;
F_26 ( & V_5 -> V_38 ) ;
V_18 = V_32 -> V_58 [ V_131 & V_132 ] ;
if ( V_18 == NULL )
goto V_133;
switch ( V_18 -> V_61 & V_62 ) {
case V_63 :
case V_134 :
if ( ! F_64 ( & V_18 -> V_19 ) ) {
struct V_11 * V_14 =
F_65 ( & V_18 -> V_19 ,
struct V_11 , V_20 ) ;
struct V_23 * V_23 ;
int V_42 ;
F_12 ( & V_14 -> V_20 ) ;
F_29 ( & V_5 -> V_38 ) ;
V_23 = V_14 -> V_23 ;
F_5 ( V_14 ) ;
if ( V_40 <= V_23 -> V_44 )
V_42 = V_40 ;
else
V_42 = V_23 -> V_44 ;
memcpy ( V_23 -> V_45 , V_124 , V_42 ) ;
V_23 -> V_46 = V_42 ;
F_13 ( V_32 -> V_5 -> V_3 , V_23 , 0 ) ;
return;
}
F_18 ( V_29 , L_26 ) ;
F_62 ( V_18 , V_124 , V_40 ) ;
break;
case V_135 :
F_62 ( V_18 , V_124 , V_40 ) ;
break;
}
V_133:
F_29 ( & V_5 -> V_38 ) ;
}
static inline int F_66 ( void )
{
return F_67 ( & V_136 ) ;
}
int F_68 ( void * V_78 )
{
int V_113 = 0 ;
struct V_31 * V_32 = V_78 ;
struct V_1 * V_5 = V_32 -> V_5 ;
struct V_11 * V_14 , * V_137 ;
F_24 ( V_138 ) ;
struct V_23 * V_23 ;
struct V_15 * V_18 ;
struct V_139 V_140 , V_141 ;
F_34 ( & V_140 ) ;
F_26 ( & V_5 -> V_38 ) ;
F_11 (ep, &port->isoc_out_ep, link) {
if ( V_18 -> V_21 < 0 )
continue;
V_141 = F_69 ( V_140 , V_18 -> V_64 ) ;
V_18 -> V_21 += F_70 ( F_71 ( & V_141 ) , V_142 ) ;
if ( V_18 -> V_21 > V_18 -> V_143 )
V_18 -> V_21 = V_18 -> V_143 ;
V_18 -> V_64 = V_140 ;
while ( V_18 -> V_21 && ! F_64 ( & V_18 -> V_19 ) ) {
V_14 = F_65 ( & V_18 -> V_19 ,
struct V_11 , V_20 ) ;
V_23 = V_14 -> V_23 ;
if ( ( V_18 -> V_21 + 1 ) < V_23 -> V_144 )
break;
V_18 -> V_21 -= V_23 -> V_144 ;
if ( V_18 -> V_21 < 0 )
V_18 -> V_21 = 0 ;
F_72 ( & V_14 -> V_20 , & V_138 ) ;
}
}
F_29 ( & V_5 -> V_38 ) ;
F_73 (urbl, n, &xfr_list, link) {
V_23 = V_14 -> V_23 ;
F_12 ( & V_14 -> V_20 ) ;
V_23 -> V_145 = 0 ;
V_23 -> V_146 = F_66 () ;
F_74 ( V_32 -> V_36 , V_14 -> V_37 , V_23 ) ;
F_5 ( V_14 ) ;
F_13 ( V_32 -> V_5 -> V_3 , V_23 , 0 ) ;
}
F_26 ( & V_5 -> V_38 ) ;
F_11 (ep, &port->isoc_in_ep, link) {
if ( V_18 -> V_34 & V_147 ) {
if ( V_18 -> V_47 >= V_148 ) {
V_18 -> V_34 &= ~ V_147 ;
V_18 -> V_21 = 0 ;
V_18 -> V_64 = V_140 ;
V_18 -> V_146 = 0 ;
}
continue;
}
V_141 = F_69 ( V_140 , V_18 -> V_64 ) ;
V_18 -> V_21 += F_70 ( F_71 ( & V_141 ) , V_142 ) ;
V_18 -> V_64 = V_140 ;
F_73 (urbl, n, &ep->urb_list, link) {
struct V_23 * V_23 = V_14 -> V_23 ;
int V_149 = 0 ;
int V_42 ;
int V_7 ;
if ( V_18 -> V_21 < V_23 -> V_144 )
break;
if ( V_18 -> V_47 < V_23 -> V_144 )
break;
V_23 -> V_46 = 0 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_144 ; V_7 ++ ) {
V_149 = V_18 -> V_22 [ V_18 -> V_43 ] ;
if ( ++ V_18 -> V_43 == V_18 -> V_16 )
V_18 -> V_43 = 0 ;
V_42 = V_18 -> V_16 - V_18 -> V_43 ;
if ( V_42 > V_149 )
V_42 = V_149 ;
memcpy ( V_23 -> V_45 ,
& V_18 -> V_22 [ V_18 -> V_43 ] , V_42 ) ;
if ( V_42 < V_149 ) {
memcpy ( V_23 -> V_45 + V_42 ,
V_18 -> V_22 , V_149 - V_42 ) ;
V_18 -> V_43 = V_149 - V_42 ;
} else
V_18 -> V_43 += V_42 ;
if ( V_18 -> V_43 == V_18 -> V_16 )
V_18 -> V_43 = 0 ;
V_23 -> V_150 [ V_7 ] . V_90 =
V_23 -> V_46 ;
V_23 -> V_46 += V_149 ;
V_23 -> V_150 [ V_7 ] . V_46 = V_149 ;
V_23 -> V_150 [ V_7 ] . V_24 = 0 ;
}
V_18 -> V_47 -= V_23 -> V_144 ;
V_23 -> V_145 = 0 ;
V_23 -> V_146 = V_18 -> V_146 ;
V_18 -> V_146 += V_23 -> V_144 ;
F_72 ( & V_14 -> V_20 , & V_138 ) ;
V_18 -> V_21 -= V_23 -> V_144 ;
}
}
if ( ! F_64 ( & V_32 -> V_70 ) || ! F_64 ( & V_32 -> V_71 ) )
V_113 = 1 ;
F_29 ( & V_5 -> V_38 ) ;
F_73 (urbl, n, &xfr_list, link) {
V_23 = V_14 -> V_23 ;
F_12 ( & V_14 -> V_20 ) ;
F_5 ( V_14 ) ;
F_13 ( V_32 -> V_5 -> V_3 , V_23 , 0 ) ;
}
V_18 = V_32 -> V_59 [ 0 ] ;
if ( V_18 ) {
F_26 ( & V_5 -> V_38 ) ;
F_73 (urbl, n, &ep->urb_list, link) {
if ( V_14 -> V_56 > V_151 ) {
F_18 ( V_29 , L_27 , V_14 -> V_23 ) ;
F_72 ( & V_14 -> V_20 , & V_138 ) ;
V_14 -> V_56 = 0 ;
} else {
V_14 -> V_56 ++ ;
}
}
if ( ! F_64 ( & V_18 -> V_19 ) )
V_113 = 1 ;
F_29 ( & V_5 -> V_38 ) ;
F_73 (urbl, n, &xfr_list, link) {
F_18 ( V_29 , L_28 ) ;
F_75 ( V_5 , V_14 -> V_23 , V_13 ) ;
F_5 ( V_14 ) ;
}
}
return V_113 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_31 * V_32 ,
struct V_119 * V_120 , T_2 V_17 )
{
struct V_1 * V_5 = V_32 -> V_5 ;
int V_7 ;
int V_152 = V_120 -> V_88 . V_153 ;
int V_154 = 0 ;
F_18 ( V_29 , L_29 , V_152 , V_120 ) ;
if ( V_152 >= V_32 -> V_155 || V_32 -> V_123 == NULL )
return - V_55 ;
for ( V_7 = 0 ; V_7 < V_120 -> V_88 . V_156 ; V_7 ++ ) {
struct V_157 * V_158 = & V_120 -> V_131 [ V_7 ] ;
T_1 V_48 = V_158 -> V_88 . V_159 ;
T_1 V_37 = V_48 & V_132 ;
struct V_15 * V_18 ;
int V_16 = 0 ;
F_18 ( V_29 , L_30 , V_7 , V_48 ) ;
if ( V_48 & V_160 ) {
switch ( V_158 -> V_88 . V_161 &
V_62 ) {
case V_135 :
V_16 = V_162 ;
break;
case V_63 :
V_16 = V_163 ;
break;
}
}
V_18 = F_7 ( V_16 , V_17 ) ;
if ( ! V_18 ) {
F_59 ( V_3 , V_32 , V_152 ) ;
return - V_55 ;
}
V_18 -> V_61 = V_158 -> V_88 . V_161 ;
V_18 -> V_37 = V_37 ;
if ( ( V_18 -> V_61 & V_62 )
== V_135 ) {
F_18 ( V_29 , L_31 ,
F_76 ( & V_158 -> V_88 ) ) ;
V_18 -> V_143 = 200 ;
if ( V_48 & V_160 ) {
V_18 -> V_34 |= V_147 ;
} else {
V_18 -> V_34 |= V_35 ;
if ( F_77 ( V_32 -> V_36 , V_37 ) )
V_18 -> V_34 &= ~ V_35 ;
}
}
F_26 ( & V_5 -> V_38 ) ;
if ( V_48 & V_160 ) {
V_32 -> V_58 [ V_37 ] = V_18 ;
V_32 -> V_123 [ V_152 ] . V_164 |=
( 1 << ( V_37 + V_52 ) ) ;
if ( ( V_18 -> V_61 & V_62 )
== V_135 ) {
F_33 ( & V_18 -> V_20 , & V_32 -> V_71 ) ;
V_154 = 1 ;
}
} else {
V_32 -> V_59 [ V_37 ] = V_18 ;
V_32 -> V_123 [ V_152 ] . V_164 |= ( 1 << V_37 ) ;
if ( ( V_18 -> V_61 & V_62 )
== V_135 ) {
F_33 ( & V_18 -> V_20 , & V_32 -> V_70 ) ;
V_154 = 1 ;
}
}
F_29 ( & V_5 -> V_38 ) ;
if ( V_154 && V_32 -> V_36 )
F_78 ( V_32 -> V_36 ) ;
}
return 0 ;
}
static void F_59 ( struct V_2 * V_3 ,
struct V_31 * V_32 , int V_152 )
{
struct V_1 * V_5 = V_32 -> V_5 ;
unsigned V_165 ;
int V_7 ;
F_24 ( V_166 ) ;
struct V_15 * V_18 , * V_137 ;
F_18 ( V_29 , L_32 , V_152 ) ;
if ( V_152 >= V_32 -> V_155 )
return;
F_26 ( & V_5 -> V_38 ) ;
V_165 = V_32 -> V_123 [ V_152 ] . V_164 ;
V_32 -> V_123 [ V_152 ] . V_164 = 0 ;
for ( V_7 = 0 ; V_7 < V_52 ; V_7 ++ ) {
struct V_66 * V_67 ;
if ( ( V_165 & ( 1 << V_7 ) ) && V_32 -> V_59 [ V_7 ] ) {
V_67 = & V_32 -> V_59 [ V_7 ] -> V_20 ;
V_32 -> V_59 [ V_7 ] = NULL ;
F_72 ( V_67 , & V_166 ) ;
}
if ( ( V_165 & ( 1 << ( V_7 + V_52 ) ) ) && V_32 -> V_58 [ V_7 ] ) {
V_67 = & V_32 -> V_58 [ V_7 ] -> V_20 ;
V_32 -> V_58 [ V_7 ] = NULL ;
F_72 ( V_67 , & V_166 ) ;
}
}
F_29 ( & V_5 -> V_38 ) ;
F_73 (ep, n, &ep_list, link) {
F_12 ( & V_18 -> V_20 ) ;
F_23 ( V_32 , V_18 ) ;
}
}
static int F_57 ( struct V_2 * V_3 ,
struct V_31 * V_32 , struct V_118 * V_115 ,
T_2 V_17 )
{
struct V_1 * V_5 = V_32 -> V_5 ;
int V_7 ;
int V_155 = V_115 -> V_88 . V_167 ;
if ( V_155 ) {
struct V_168 * V_123 ;
V_123 = F_79 ( V_155 , sizeof( struct V_168 ) ,
V_17 | V_169 ) ;
if ( ! V_123 )
return - V_55 ;
F_26 ( & V_5 -> V_38 ) ;
V_32 -> V_123 = V_123 ;
V_32 -> V_155 = V_155 ;
F_29 ( & V_5 -> V_38 ) ;
}
for ( V_7 = 0 ; V_7 < V_155 ; V_7 ++ ) {
struct V_119 * V_120 =
& V_115 -> V_121 [ V_7 ] -> V_122 [ 0 ] ;
if ( F_60 ( V_3 , V_32 , V_120 ,
V_17 ) )
goto V_170;
}
return 0 ;
V_170:
F_49 ( V_3 , V_32 ) ;
return - 1 ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_5 = V_32 -> V_5 ;
int V_7 ;
F_18 ( V_29 , L_33 ) ;
for ( V_7 = 0 ; V_7 < V_32 -> V_155 ; V_7 ++ )
F_59 ( V_3 , V_32 , V_7 ) ;
F_26 ( & V_5 -> V_38 ) ;
if ( V_32 -> V_123 ) {
F_18 ( V_29 , L_34 ) ;
F_30 ( V_32 -> V_123 ) ;
V_32 -> V_123 = NULL ;
}
V_32 -> V_155 = 0 ;
F_29 ( & V_5 -> V_38 ) ;
}
static void * F_80 ( struct V_31 * V_32 )
{
void * V_36 ;
struct V_1 * V_5 = V_32 -> V_5 ;
F_26 ( & V_5 -> V_38 ) ;
V_36 = V_32 -> V_36 ;
if ( V_36 )
F_40 ( V_36 ) ;
F_29 ( & V_5 -> V_38 ) ;
return V_36 ;
}
static void F_75 ( struct V_1 * V_5 , struct V_23 * V_23 ,
T_2 V_17 )
{
struct V_93 * V_94 ;
unsigned V_125 ;
unsigned V_96 ;
unsigned V_171 ;
void * V_36 ;
T_1 V_50 ;
int V_113 = 0 ;
unsigned V_172 = 0 ;
int V_173 = - 1 ;
struct V_31 * V_32 = NULL ;
F_18 ( V_174 , L_35 , V_53 , V_23 ) ;
V_173 = F_2 ( V_5 , V_23 -> V_114 -> V_175 ) ;
if ( V_173 < 0 ) {
V_113 = - V_65 ;
goto V_60;
}
V_32 = & V_5 -> V_9 [ V_173 ] ;
if ( ( ( V_32 -> V_34 & V_72 ) == 0 )
|| ( V_32 -> V_34 & V_83 ) ) {
F_18 ( V_29 , L_36 ,
V_173 , V_23 -> V_114 -> V_175 ) ;
V_113 = - V_65 ;
goto V_60;
}
V_23 -> V_28 = V_32 ;
V_94 = (struct V_93 * ) V_23 -> V_95 ;
V_125 = F_53 ( V_94 -> V_99 ) ;
V_96 = F_53 ( V_94 -> V_97 ) ;
V_171 = F_53 ( V_94 -> V_176 ) ;
F_18 ( V_177 , L_37 , V_94 -> V_98 ) ;
F_18 ( V_177 , L_38 , V_94 -> V_128 ) ;
F_18 ( V_177 , L_39 , V_96 ) ;
F_18 ( V_177 , L_40 , V_125 ) ;
F_18 ( V_177 , L_41 , V_171 ) ;
V_50 = V_32 -> V_178 ++ ;
V_36 = F_80 ( V_32 ) ;
if ( V_36 == NULL ) {
F_18 ( V_29 , L_42 ) ;
V_113 = - V_65 ;
goto V_60;
}
if ( ( V_94 -> V_98 & V_126 ) == V_127 ) {
switch ( V_94 -> V_128 ) {
case V_105 :
F_18 ( V_29 , L_43 ) ;
break;
case V_104 :
F_18 ( V_29 , L_44 ) ;
F_18 ( V_29 , L_45 ,
V_5 -> V_10 ,
( T_1 ) F_53 ( V_94 -> V_97 ) ) ;
F_26 ( & V_5 -> V_38 ) ;
if ( V_5 -> V_10 >= 0 ) {
V_5 -> V_9 [ V_5 -> V_10 ] . V_6 =
( T_1 ) F_53 ( V_94 -> V_97 ) ;
F_18 ( V_29 , L_7 ) ;
V_5 -> V_10 = - 1 ;
}
F_29 ( & V_5 -> V_38 ) ;
V_172 = 1 ;
break;
case V_108 :
F_18 ( V_29 , L_46 ) ;
break;
case V_107 :
F_18 ( V_29 , L_47 ) ;
if ( V_23 -> V_44 >= 1 ) {
V_23 -> V_46 = 1 ;
* ( ( T_1 * ) V_23 -> V_45 ) =
V_32 -> V_84 ;
V_172 = 1 ;
} else {
V_113 = - V_65 ;
}
break;
case V_109 :
F_18 ( V_29 , L_48 ) ;
if ( V_23 -> V_44 >= 1 ) {
V_23 -> V_46 = 1 ;
* ( ( T_1 * ) V_23 -> V_45 ) =
V_32 -> V_123 [ ( T_1 ) V_125 ] . V_117 ;
F_18 ( V_29 , L_49 ,
V_125 , V_32 -> V_123 [ ( T_1 ) V_125 ] . V_117 ) ;
V_172 = 1 ;
} else {
V_113 = - V_65 ;
}
break;
case V_110 :
F_18 ( V_29 , L_50 ) ;
break;
}
}
if ( ! V_113 && ! V_172 ) {
int V_40 = 0 ;
if ( ( V_94 -> V_98 & V_179 ) == 0 )
V_40 = V_171 ;
V_23 -> V_46 = V_40 ;
if ( F_81 ( V_32 -> V_36 , V_50 , V_94 ,
V_23 -> V_45 , V_40 ) ) {
V_113 = - V_55 ;
} else {
if ( F_32 ( V_32 , 0 , 0 , V_23 , V_50 ) )
V_113 = - V_55 ;
}
}
F_50 ( V_36 ) ;
V_60:
if ( V_113 || V_172 ) {
F_18 ( V_29 , L_51 ) ;
F_13 ( V_5 -> V_3 , V_23 , V_113 ) ;
} else {
F_78 ( V_32 -> V_36 ) ;
}
}
static int F_82 ( struct V_1 * V_5 , struct V_23 * V_23 )
{
int V_113 = 0 ;
struct V_31 * V_32 = V_23 -> V_28 ;
T_1 V_48 ;
F_83 ( V_23 ) ;
if ( ! V_23 -> V_45 && V_23 -> V_44 )
return - V_54 ;
if ( ( V_32 -> V_34 & V_72 ) == 0 )
return - V_65 ;
V_48 = F_84 ( V_23 -> V_180 ) ;
if ( V_48 ) {
if ( F_32 ( V_32 , V_48 , F_85 ( V_23 -> V_180 ) ,
V_23 , 0 ) )
V_113 = - V_65 ;
} else {
F_75 ( V_5 , V_23 , V_13 ) ;
}
return V_113 ;
}
static void F_86 ( unsigned long V_181 )
{
unsigned long V_25 ;
struct V_23 * V_23 ;
struct V_1 * V_5 = F_41 () ;
struct V_11 * V_14 , * V_137 ;
int V_113 = 0 ;
if ( V_5 == NULL )
return;
F_14 ( & V_27 , V_25 ) ;
F_73 (urbl, n, &ozhcd->urb_pending_list, link) {
F_12 ( & V_14 -> V_20 ) ;
F_22 ( & V_27 , V_25 ) ;
V_23 = V_14 -> V_23 ;
F_5 ( V_14 ) ;
V_113 = F_82 ( V_5 , V_23 ) ;
if ( V_113 )
F_13 ( V_5 -> V_3 , V_23 , V_113 ) ;
F_14 ( & V_27 , V_25 ) ;
}
F_22 ( & V_27 , V_25 ) ;
F_43 ( V_5 ) ;
}
static void F_87 ( struct V_31 * V_32 , T_1 V_37 , struct V_23 * V_23 )
{
struct V_11 * V_14 = NULL ;
struct V_66 * V_67 ;
struct V_1 * V_5 ;
unsigned long V_25 ;
T_1 V_182 ;
if ( V_32 == NULL ) {
F_18 ( V_29 , L_52 , V_53 , V_23 ) ;
return;
}
V_5 = V_32 -> V_5 ;
if ( V_5 == NULL ) {
F_18 ( V_29 , L_53 , V_53 , V_23 ) ;
return;
}
F_14 ( & V_27 , V_25 ) ;
F_36 (e, &ozhcd->urb_cancel_list) {
V_14 = F_37 ( V_67 , struct V_11 , V_20 ) ;
if ( V_23 == V_14 -> V_23 ) {
F_12 ( V_67 ) ;
F_22 ( & V_27 , V_25 ) ;
goto V_183;
}
}
F_22 ( & V_27 , V_25 ) ;
V_14 = NULL ;
F_14 ( & V_5 -> V_38 , V_25 ) ;
F_36 (e, &ozhcd->orphanage) {
V_14 = F_37 ( V_67 , struct V_11 , V_20 ) ;
if ( V_14 -> V_23 == V_23 ) {
F_88 ( V_67 ) ;
F_18 ( V_29 , L_54 ) ;
goto V_60;
}
}
V_182 = ( V_37 & 0xf ) ;
V_14 = NULL ;
if ( ( V_37 & V_179 ) && V_182 )
V_14 = F_89 ( V_32 -> V_58 [ V_182 ] , V_23 ) ;
else
V_14 = F_89 ( V_32 -> V_59 [ V_182 ] , V_23 ) ;
V_60:
F_22 ( & V_5 -> V_38 , V_25 ) ;
V_183:
if ( V_14 ) {
V_23 -> V_46 = 0 ;
F_5 ( V_14 ) ;
F_13 ( V_5 -> V_3 , V_23 , - V_65 ) ;
}
}
static void F_90 ( unsigned long V_181 )
{
unsigned long V_25 ;
struct V_23 * V_23 ;
struct V_11 * V_14 , * V_137 ;
struct V_1 * V_5 = F_41 () ;
if ( V_5 == NULL )
return;
F_14 ( & V_27 , V_25 ) ;
F_73 (urbl, n, &ozhcd->urb_cancel_list, link) {
F_12 ( & V_14 -> V_20 ) ;
F_22 ( & V_27 , V_25 ) ;
V_23 = V_14 -> V_23 ;
if ( V_23 -> V_57 )
F_87 ( V_14 -> V_32 , V_14 -> V_37 , V_23 ) ;
F_5 ( V_14 ) ;
F_14 ( & V_27 , V_25 ) ;
}
F_22 ( & V_27 , V_25 ) ;
F_43 ( V_5 ) ;
}
static void F_91 ( struct V_1 * V_5 , int V_24 )
{
if ( V_5 ) {
struct V_11 * V_14 , * V_137 ;
F_73 (urbl, n, &ozhcd->orphanage, link) {
F_88 ( & V_14 -> V_20 ) ;
F_13 ( V_5 -> V_3 , V_14 -> V_23 , V_24 ) ;
F_5 ( V_14 ) ;
}
}
}
static int F_92 ( struct V_2 * V_3 )
{
V_3 -> V_184 = 200 ;
V_3 -> V_185 = V_186 ;
V_3 -> V_187 = 1 ;
return 0 ;
}
static void F_93 ( struct V_2 * V_3 )
{
}
static void F_94 ( struct V_2 * V_3 )
{
}
static int F_95 ( struct V_2 * V_3 , struct V_23 * V_23 ,
T_2 V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_113 ;
int V_173 ;
struct V_31 * V_32 ;
unsigned long V_25 ;
struct V_11 * V_14 ;
F_18 ( V_174 , L_55 , V_53 , V_23 ) ;
if ( F_96 ( V_5 == NULL ) ) {
F_18 ( V_174 , L_56 , V_23 ) ;
return - V_65 ;
}
if ( F_96 ( V_3 -> V_185 != V_186 ) ) {
F_18 ( V_174 , L_57 , V_23 ) ;
return - V_65 ;
}
V_173 = F_2 ( V_5 , V_23 -> V_114 -> V_175 ) ;
if ( V_173 < 0 )
return - V_65 ;
V_32 = & V_5 -> V_9 [ V_173 ] ;
if ( V_32 == NULL )
return - V_65 ;
if ( ! ( V_32 -> V_34 & V_72 ) ||
( V_32 -> V_34 & V_73 ) ) {
F_18 ( V_29 , L_36 ,
V_173 , V_23 -> V_114 -> V_175 ) ;
return - V_65 ;
}
V_23 -> V_28 = V_32 ;
V_14 = F_3 () ;
if ( F_96 ( V_14 == NULL ) )
return - V_55 ;
V_14 -> V_23 = V_23 ;
F_14 ( & V_27 , V_25 ) ;
V_113 = F_97 ( V_3 , V_23 ) ;
if ( F_96 ( V_113 ) ) {
F_22 ( & V_27 , V_25 ) ;
F_5 ( V_14 ) ;
return V_113 ;
}
F_33 ( & V_14 -> V_20 , & V_5 -> V_188 ) ;
F_22 ( & V_27 , V_25 ) ;
F_98 ( & V_189 ) ;
F_99 ( & V_30 ) ;
return 0 ;
}
static struct V_11 * F_89 ( struct V_15 * V_18 ,
struct V_23 * V_23 )
{
struct V_11 * V_14 ;
if ( F_96 ( V_18 == NULL ) )
return NULL ;
F_11 (urbl, &ep->urb_list, link) {
if ( V_14 -> V_23 == V_23 ) {
F_12 ( & V_14 -> V_20 ) ;
if ( F_100 ( V_23 -> V_180 ) ) {
V_18 -> V_21 -= V_23 -> V_144 ;
if ( V_18 -> V_21 < 0 )
V_18 -> V_21 = 0 ;
}
return V_14 ;
}
}
return NULL ;
}
static int F_101 ( struct V_2 * V_3 , struct V_23 * V_23 , int V_24 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_11 * V_14 ;
int V_113 ;
unsigned long V_25 ;
F_18 ( V_174 , L_55 , V_53 , V_23 ) ;
V_14 = F_3 () ;
if ( F_96 ( V_14 == NULL ) )
return - V_55 ;
F_14 ( & V_27 , V_25 ) ;
V_113 = F_102 ( V_3 , V_23 , V_24 ) ;
if ( ( V_113 == 0 ) && V_23 -> V_28 ) {
V_14 -> V_23 = V_23 ;
V_14 -> V_32 = (struct V_31 * ) V_23 -> V_28 ;
V_14 -> V_37 = F_84 ( V_23 -> V_180 ) ;
if ( F_85 ( V_23 -> V_180 ) )
V_14 -> V_37 |= V_179 ;
F_33 ( & V_14 -> V_20 , & V_5 -> V_190 ) ;
F_22 ( & V_27 , V_25 ) ;
F_98 ( & V_191 ) ;
} else {
F_22 ( & V_27 , V_25 ) ;
F_5 ( V_14 ) ;
}
return V_113 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_157 * V_18 )
{
}
static void F_104 ( struct V_2 * V_3 ,
struct V_157 * V_18 )
{
}
static int F_105 ( struct V_2 * V_3 )
{
F_18 ( V_29 , L_58 ) ;
return F_66 () ;
}
static int F_106 ( struct V_2 * V_3 , char * V_192 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_7 ;
V_192 [ 0 ] = 0 ;
V_192 [ 1 ] = 0 ;
F_26 ( & V_5 -> V_38 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_5 -> V_9 [ V_7 ] . V_34 & V_73 ) {
F_18 ( V_193 , L_59 , V_7 ) ;
V_5 -> V_9 [ V_7 ] . V_34 &= ~ V_73 ;
if ( V_7 < 7 )
V_192 [ 0 ] |= 1 << ( V_7 + 1 ) ;
else
V_192 [ 1 ] |= 1 << ( V_7 - 7 ) ;
}
}
F_29 ( & V_5 -> V_38 ) ;
if ( V_192 [ 0 ] != 0 || V_192 [ 1 ] != 0 )
return 2 ;
return 0 ;
}
static void F_107 ( struct V_2 * V_3 ,
struct V_194 * V_88 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_195 = 0x29 ;
V_88 -> V_196 = 9 ;
V_88 -> V_197 = F_108 ( 0x0001 ) ;
V_88 -> V_198 = V_8 ;
}
static int F_109 ( struct V_2 * V_3 , T_3 V_96 , T_3 V_125 )
{
struct V_31 * V_32 ;
T_1 V_199 = ( T_1 ) V_125 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_200 = 0 ;
unsigned V_201 = 0 ;
if ( ( V_199 < 1 ) || ( V_199 > V_8 ) )
return - V_65 ;
V_32 = & V_5 -> V_9 [ V_199 - 1 ] ;
switch ( V_96 ) {
case V_202 :
F_18 ( V_193 , L_60 ) ;
break;
case V_203 :
F_18 ( V_193 , L_61 ) ;
break;
case V_204 :
F_18 ( V_193 , L_62 ) ;
break;
case V_205 :
F_18 ( V_193 , L_63 ) ;
break;
case V_206 :
F_18 ( V_193 , L_64 ) ;
V_200 = V_85 | ( V_87 << 16 ) ;
V_201 = V_86 ;
V_5 -> V_9 [ V_199 - 1 ] . V_6 = 0 ;
break;
case V_207 :
F_18 ( V_193 , L_65 ) ;
V_200 |= V_208 ;
break;
case V_209 :
F_18 ( V_193 , L_66 ) ;
break;
case V_210 :
F_18 ( V_193 , L_67 ) ;
break;
case V_211 :
F_18 ( V_193 , L_68 ) ;
break;
case V_212 :
F_18 ( V_193 , L_69 ) ;
break;
case V_213 :
F_18 ( V_193 , L_70 ) ;
break;
case V_214 :
F_18 ( V_193 , L_71 ) ;
break;
case V_215 :
F_18 ( V_193 , L_72 ) ;
break;
case V_216 :
F_18 ( V_193 , L_73 ) ;
break;
default:
F_18 ( V_193 , L_74 , V_96 ) ;
break;
}
if ( V_200 || V_201 ) {
F_26 ( & V_32 -> V_81 ) ;
V_32 -> V_24 &= ~ V_201 ;
V_32 -> V_24 |= V_200 ;
F_29 ( & V_32 -> V_81 ) ;
}
F_18 ( V_193 , L_75 , V_199 , V_32 -> V_24 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 , T_3 V_96 , T_3 V_125 )
{
struct V_31 * V_32 ;
T_1 V_199 = ( T_1 ) V_125 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_201 = 0 ;
if ( ( V_199 < 1 ) || ( V_199 > V_8 ) )
return - V_65 ;
V_32 = & V_5 -> V_9 [ V_199 - 1 ] ;
switch ( V_96 ) {
case V_202 :
F_18 ( V_193 , L_60 ) ;
break;
case V_203 :
F_18 ( V_193 , L_61 ) ;
V_201 = V_85 ;
break;
case V_204 :
F_18 ( V_193 , L_62 ) ;
break;
case V_205 :
F_18 ( V_193 , L_63 ) ;
break;
case V_206 :
F_18 ( V_193 , L_64 ) ;
break;
case V_207 :
F_18 ( V_193 , L_65 ) ;
V_201 |= V_208 ;
break;
case V_209 :
F_18 ( V_193 , L_66 ) ;
break;
case V_210 :
F_18 ( V_193 , L_67 ) ;
V_201 = V_75 << 16 ;
break;
case V_211 :
F_18 ( V_193 , L_68 ) ;
V_201 = V_217 << 16 ;
break;
case V_212 :
F_18 ( V_193 , L_69 ) ;
break;
case V_213 :
F_18 ( V_193 , L_70 ) ;
break;
case V_214 :
F_18 ( V_193 , L_71 ) ;
V_201 = V_214 << 16 ;
break;
case V_215 :
F_18 ( V_193 , L_72 ) ;
break;
case V_216 :
F_18 ( V_193 , L_73 ) ;
break;
default:
F_18 ( V_193 , L_74 , V_96 ) ;
break;
}
if ( V_201 ) {
F_26 ( & V_32 -> V_81 ) ;
V_32 -> V_24 &= ~ V_201 ;
F_29 ( & V_32 -> V_81 ) ;
}
F_18 ( V_193 , L_75 ,
V_199 , V_5 -> V_9 [ V_199 - 1 ] . V_24 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 , T_3 V_125 , char * V_192 )
{
struct V_1 * V_5 ;
T_4 V_24 ;
if ( ( V_125 < 1 ) || ( V_125 > V_8 ) )
return - V_65 ;
V_5 = F_1 ( V_3 ) ;
F_18 ( V_193 , L_76 , V_125 ) ;
V_24 = V_5 -> V_9 [ V_125 - 1 ] . V_24 ;
F_112 ( F_113 ( V_24 ) , ( V_218 * ) V_192 ) ;
F_18 ( V_193 , L_77 , V_125 , V_24 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_3 , T_3 V_219 , T_3 V_96 ,
T_3 V_125 , char * V_192 , T_3 V_171 )
{
int V_51 = 0 ;
switch ( V_219 ) {
case V_220 :
F_18 ( V_193 , L_78 , V_219 ) ;
break;
case V_221 :
V_51 = F_110 ( V_3 , V_96 , V_125 ) ;
break;
case V_222 :
F_107 ( V_3 , (struct V_194 * ) V_192 ) ;
break;
case V_223 :
F_18 ( V_193 , L_79 , V_219 ) ;
F_112 ( F_113 ( 0 ) , ( V_218 * ) V_192 ) ;
break;
case V_224 :
V_51 = F_111 ( V_3 , V_125 , V_192 ) ;
break;
case V_225 :
F_18 ( V_193 , L_80 , V_219 ) ;
break;
case V_226 :
V_51 = F_109 ( V_3 , V_96 , V_125 ) ;
break;
default:
F_18 ( V_193 , L_81 , V_219 ) ;
break;
}
return V_51 ;
}
static int F_115 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 ) ;
F_26 ( & V_5 -> V_38 ) ;
V_3 -> V_185 = V_227 ;
V_5 -> V_34 |= V_82 ;
F_29 ( & V_5 -> V_38 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 ) ;
F_26 ( & V_5 -> V_38 ) ;
V_5 -> V_34 &= ~ V_82 ;
V_3 -> V_185 = V_186 ;
F_29 ( & V_5 -> V_38 ) ;
return 0 ;
}
static void F_117 ( struct V_228 * V_114 )
{
}
static int F_118 ( struct V_228 * V_114 )
{
int V_7 ;
int V_51 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
V_3 = F_119 ( & V_229 , & V_114 -> V_114 , F_120 ( & V_114 -> V_114 ) ) ;
if ( V_3 == NULL ) {
F_18 ( V_29 , L_82 ) ;
return - V_55 ;
}
V_5 = F_1 ( V_3 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_9 ( & V_5 -> V_188 ) ;
F_9 ( & V_5 -> V_190 ) ;
F_9 ( & V_5 -> V_39 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_10 = - 1 ;
F_121 ( & V_5 -> V_38 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_31 * V_32 = & V_5 -> V_9 [ V_7 ] ;
V_32 -> V_5 = V_5 ;
V_32 -> V_34 = 0 ;
V_32 -> V_24 = 0 ;
V_32 -> V_6 = 0xff ;
F_121 ( & V_32 -> V_81 ) ;
}
V_51 = F_122 ( V_3 , 0 , 0 ) ;
if ( V_51 ) {
F_18 ( V_29 , L_83 ) ;
F_44 ( V_3 ) ;
return - 1 ;
}
F_123 ( V_3 -> V_230 . V_231 ) ;
F_26 ( & V_76 ) ;
V_77 = V_5 ;
F_29 ( & V_76 ) ;
return 0 ;
}
static int F_124 ( struct V_228 * V_114 )
{
struct V_2 * V_3 = F_125 ( V_114 ) ;
struct V_1 * V_5 ;
if ( V_3 == NULL )
return - 1 ;
V_5 = F_1 ( V_3 ) ;
F_26 ( & V_76 ) ;
if ( V_5 == V_77 )
V_77 = NULL ;
F_29 ( & V_76 ) ;
F_18 ( V_29 , L_84 ) ;
F_91 ( V_5 , - V_65 ) ;
F_18 ( V_29 , L_85 ) ;
F_126 ( V_3 ) ;
F_44 ( V_3 ) ;
return 0 ;
}
static int F_127 ( struct V_228 * V_114 , T_5 V_232 )
{
return 0 ;
}
static int F_128 ( struct V_228 * V_114 )
{
return 0 ;
}
int F_129 ( void )
{
int V_51 ;
if ( F_130 () )
return - V_233 ;
V_12 = F_131 ( V_11 , 0 ) ;
if ( ! V_12 )
return - V_55 ;
F_132 ( & V_189 , F_86 , 0 ) ;
F_132 ( & V_191 , F_90 , 0 ) ;
V_51 = F_133 ( & V_234 ) ;
F_18 ( V_29 , L_86 , V_51 ) ;
if ( V_51 )
goto error;
V_235 = F_134 ( V_236 , - 1 ) ;
if ( V_235 == NULL ) {
V_51 = - V_55 ;
goto V_237;
}
F_18 ( V_29 , L_87 ) ;
V_51 = F_135 ( V_235 ) ;
if ( V_51 )
goto V_238;
F_18 ( V_29 , L_88 ) ;
return 0 ;
V_238:
F_136 ( V_235 ) ;
V_237:
F_137 ( & V_234 ) ;
error:
F_138 ( & V_189 ) ;
F_138 ( & V_191 ) ;
F_18 ( V_29 , L_89 , V_51 ) ;
return V_51 ;
}
void F_139 ( void )
{
F_140 ( V_239 ) ;
F_141 ( & V_189 ) ;
F_141 ( & V_191 ) ;
F_142 ( V_235 ) ;
F_137 ( & V_234 ) ;
F_18 ( V_29 , L_90 , F_143 ( & V_30 ) ) ;
F_144 ( V_12 ) ;
}
