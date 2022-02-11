static inline T_1 F_1 ( T_1 V_1 )
{
if ( V_1 < 0x7F )
return V_1 + 1 ;
else
return 1 ;
}
static void F_2 ( struct V_2 * V_3 )
{
if ( ! F_3 ( & V_3 -> V_4 ) )
return;
F_4 ( ! V_3 -> V_5 . V_5 ) ;
F_5 ( V_3 -> V_6 -> V_7 == - V_8 ) ;
F_5 ( F_6 ( & V_3 -> V_9 ) ) ;
F_7 ( V_3 -> V_6 ) ;
F_8 ( V_3 -> V_10 ) ;
F_8 ( V_3 ) ;
}
static inline void F_9 ( struct V_11 * V_12 ,
struct V_13 * V_9 ,
unsigned long V_14 )
{
if ( ! V_12 -> V_15 )
return;
F_10 ( V_9 , V_14 ) ;
}
static void F_11 ( T_2 V_16 )
{
struct V_2 * V_3 = ( void * ) V_16 ;
V_3 -> V_6 -> V_17 |= V_18 ;
if ( F_12 ( V_3 -> V_6 ) == - V_8 ) {
V_3 -> V_19 = V_20 ;
} else {
V_3 -> V_19 = V_21 ;
F_13 ( & V_3 -> V_6 -> V_22 -> V_22 , L_1 ) ;
F_14 ( & V_3 -> V_4 ) ;
V_3 -> V_23 = 1 ;
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
}
}
static struct V_2 * F_16 ( struct V_11 * V_12 ,
T_3 V_24 , T_3 V_25 )
{
struct V_2 * V_3 ;
V_3 = F_17 ( sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_10 = F_18 ( V_27 , V_26 ) ;
if ( ! V_3 -> V_10 ) {
F_8 ( V_3 ) ;
return NULL ;
}
V_3 -> V_6 = F_19 ( 0 , V_26 ) ;
if ( ! V_3 -> V_6 ) {
F_8 ( V_3 -> V_10 ) ;
F_8 ( V_3 ) ;
return NULL ;
}
V_3 -> V_12 = V_12 ;
V_3 -> V_19 = V_28 ;
V_3 -> V_24 = V_24 ;
V_3 -> V_25 = V_25 ;
F_20 ( & V_3 -> V_4 , 1 ) ;
F_21 ( & V_3 -> V_5 ) ;
F_22 ( & V_3 -> V_9 ) ;
V_3 -> V_9 . V_29 = F_11 ;
V_3 -> V_9 . V_30 = ( T_2 ) V_3 ;
return V_3 ;
}
static inline void F_23 ( struct V_31 * V_32 )
{
F_24 ( V_32 ) ;
F_24 ( V_32 ) ;
F_24 ( V_32 ) ;
F_24 ( V_32 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_12 ;
unsigned long V_33 ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
F_26 ( & V_3 -> V_35 ) ;
if ( V_12 -> V_15 ) {
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_28 ( V_12 ) ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
}
switch ( V_3 -> V_19 ) {
case V_36 :
case V_37 :
case V_38 :
case V_20 :
case V_21 :
F_27 ( & V_12 -> V_34 , V_33 ) ;
if ( ( V_3 -> V_24 == V_39 ) && V_12 -> V_22 ) {
struct V_40 * V_22 = V_12 -> V_22 ;
struct V_41 * V_42 = F_29 ( V_22 ) ;
struct V_43 * V_44 = & V_42 -> V_44 ;
if ( V_3 -> V_19 != V_36 )
V_44 -> V_45 ++ ;
else
V_44 -> V_46 ++ ;
F_30 ( V_22 ) ;
}
F_23 ( & V_3 -> V_5 ) ;
F_2 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_34 , V_33 ) ;
if ( ! V_12 -> V_15 ) {
F_31 ( L_2 ) ;
F_23 ( & V_3 -> V_5 ) ;
F_2 ( V_3 ) ;
break;
}
F_31 ( L_3 ) ;
break;
}
}
static void F_28 ( struct V_11 * V_12 )
{
unsigned long V_33 ;
struct V_2 * V_3 ;
int V_47 ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
if ( ! F_32 ( & V_12 -> V_48 ) )
goto V_49;
if ( F_32 ( & V_12 -> V_50 ) )
goto V_49;
V_3 =
F_33 ( V_12 -> V_50 . V_51 , struct V_2 ,
V_35 ) ;
if ( ! V_3 -> V_12 -> V_15 )
goto V_49;
F_34 ( & V_3 -> V_35 , & V_12 -> V_48 ) ;
if ( V_3 -> V_19 == V_52 ) {
F_14 ( & V_3 -> V_4 ) ;
V_47 = F_35 ( V_3 -> V_6 , V_26 ) ;
if ( V_47 ) {
V_3 -> V_19 = V_37 ;
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_31 ( L_4
L_5 , V_47 ) ;
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
goto V_5;
}
V_3 -> V_19 = V_53 ;
F_9 ( V_3 -> V_12 , & V_3 -> V_9 ,
V_54 + V_55 ) ;
}
V_49:
F_27 ( & V_12 -> V_34 , V_33 ) ;
V_5:
return;
}
static void F_36 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
unsigned long V_33 ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
if ( ! V_3 -> V_12 -> V_15 ) {
F_27 ( & V_12 -> V_34 , V_33 ) ;
goto V_5;
}
F_14 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_35 , & V_12 -> V_50 ) ;
F_27 ( & V_12 -> V_34 , V_33 ) ;
V_3 -> V_19 = V_52 ;
F_28 ( V_12 ) ;
V_5:
return;
}
static void F_38 ( struct V_56 * V_56 )
{
unsigned long V_33 ;
enum V_57 V_19 ;
struct V_2 * V_3 = V_56 -> V_58 ;
struct V_11 * V_12 = V_3 -> V_12 ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
F_39 ( & V_3 -> V_9 ) ;
if ( V_3 -> V_23 ) {
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_40 ( L_6 ) ;
goto V_59;
}
V_19 = V_3 -> V_19 ;
if ( V_56 -> V_7 == 0 ) {
switch ( V_19 ) {
case V_53 :
if ( V_3 -> V_25 ) {
V_3 -> V_19 = V_60 ;
F_9 ( V_12 , & V_3 -> V_9 ,
V_54 + V_55 ) ;
F_27 ( & V_12 -> V_34 ,
V_33 ) ;
break;
}
case V_61 :
V_3 -> V_19 = V_36 ;
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_31 ( L_7 ,
V_19 , V_56 -> V_7 ) ;
break;
}
} else {
switch ( V_19 ) {
case V_53 :
case V_61 :
V_3 -> V_19 = V_38 ;
case V_38 :
case V_20 :
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_31 ( L_7 ,
V_19 , V_56 -> V_7 ) ;
break;
}
}
V_59:
F_2 ( V_3 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
struct V_56 * V_56 )
{
struct V_62 * V_63 = V_56 -> V_64 ;
struct V_2 * V_3 = NULL ;
enum V_57 V_19 ;
unsigned long V_33 ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
if ( V_12 -> V_15 ) {
struct V_65 * V_66 ;
F_42 (item, &upriv->req_active) {
struct V_2 * V_67 ;
int V_68 ;
V_67 = F_33 ( V_66 , struct V_2 , V_35 ) ;
V_68 =
F_1 ( V_67 -> V_10 -> V_69 ) ;
if ( ( V_63 -> V_70 == V_68 )
&& ( F_43 ( V_63 -> V_71 ) == V_67 -> V_25 ) ) {
V_3 = V_67 ;
break;
}
F_44 ( V_12 -> V_22 , L_8 ,
F_43 ( V_63 -> V_71 ) , V_67 -> V_25 ,
V_63 -> V_70 , V_68 ) ;
}
}
if ( V_3 == NULL ) {
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_31 ( L_9 , V_72 ,
F_43 ( V_63 -> V_71 ) ) ;
F_28 ( V_12 ) ;
return;
}
V_56 -> V_64 = V_3 -> V_10 ;
V_3 -> V_10 = ( void * ) V_63 ;
V_3 -> V_73 = V_56 -> V_74 ;
V_19 = V_3 -> V_19 ;
switch ( V_19 ) {
case V_53 :
V_3 -> V_19 = V_61 ;
F_27 ( & V_12 -> V_34 , V_33 ) ;
break;
case V_60 :
V_3 -> V_19 = V_36 ;
F_39 ( & V_3 -> V_9 ) ;
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_40 ( L_10 ,
V_19 ) ;
F_39 ( & V_3 -> V_9 ) ;
V_3 -> V_6 -> V_17 |= V_18 ;
F_12 ( V_3 -> V_6 ) ;
F_28 ( V_12 ) ;
break;
}
}
static void F_45 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
switch ( V_3 -> V_19 ) {
case V_52 :
case V_53 :
case V_60 :
case V_61 :
if ( F_46 () ) {
int V_75 = V_55 * ( 1000 / V_76 ) ;
while ( ! V_3 -> V_5 . V_5 && V_75 -- )
F_47 ( 1000 ) ;
} else {
F_48 ( V_3 -> V_5 . V_77 ,
V_3 -> V_5 . V_5 ) ;
}
break;
default:
break;
}
}
static inline T_3 F_49 ( struct V_62 * V_30 )
{
T_3 V_78 = 0 ;
T_1 * V_79 = ( T_1 * ) V_30 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < 8 ; V_80 ++ )
V_78 = ( V_78 << 1 ) + V_79 [ V_80 ] ;
return V_78 ;
}
static int F_50 ( struct V_62 * V_81 , T_3 V_82 , T_3 V_83 ,
const void * V_30 , T_3 V_84 , T_1 V_68 )
{
int V_85 = sizeof( * V_81 ) + V_82 ;
F_5 ( V_85 > V_27 ) ;
V_81 -> V_86 = F_51 ( V_87 ) ;
V_81 -> V_69 = V_68 ;
V_81 -> V_70 = 0 ;
V_81 -> V_84 = F_51 ( V_84 ) ;
V_81 -> V_88 = F_51 ( V_82 + 4 ) ;
V_81 -> V_78 = F_51 ( F_49 ( V_81 ) ) ;
V_81 -> V_89 = F_51 ( F_52 ( V_82 ) ) ;
V_81 -> V_71 = F_51 ( V_83 ) ;
if ( V_30 )
memcpy ( V_81 -> V_30 , V_30 , V_82 ) ;
return V_85 ;
}
static int F_53 ( struct V_11 * V_12 )
{
int V_90 = 0 ;
void * V_91 = V_12 -> V_92 -> V_64 ;
if ( V_12 -> V_92 -> V_7 == - V_8 ) {
F_44 ( V_12 -> V_22 , L_11 ) ;
V_90 = - V_93 ;
goto exit;
}
F_54 ( V_12 -> V_92 , V_12 -> V_15 , V_12 -> V_94 ,
V_91 , V_27 ,
V_95 , V_12 ) ;
V_12 -> V_92 -> V_17 = 0 ;
V_90 = F_35 ( V_12 -> V_92 , V_26 ) ;
if ( V_90 )
F_31 ( L_12 , V_72 , V_90 ) ;
exit:
return V_90 ;
}
static inline int F_55 ( struct V_11 * V_12 , int V_96 )
{
T_1 V_97 = V_96 ;
if ( ! V_12 -> V_15 ) {
F_31 ( L_13 , V_72 ) ;
return - V_98 ;
}
return F_56 ( V_12 -> V_15 ,
F_57 ( V_12 -> V_15 , 0 ) ,
V_99 ,
V_100 | V_101 |
V_102 , V_103 , 0 , & V_97 ,
sizeof( V_97 ) , V_55 ) ;
}
static int F_58 ( struct V_11 * V_12 ,
struct V_104 * V_105 )
{
T_1 * V_106 ;
int V_90 , V_107 ;
int V_108 ;
V_106 = F_18 ( V_109 , V_110 ) ;
if ( ! V_106 ) {
F_59 (KERN_ERR PFX L_14 ) ;
return - V_111 ;
}
V_108 = F_60 ( ( V_112 * ) & V_105 -> V_113 [ V_114 ] ) ;
if ( V_108 >= V_105 -> V_88 ) {
F_59 (KERN_ERR PFX L_15
L_16 , variant_offset) ;
V_90 = - V_115 ;
goto V_116;
}
V_90 = F_55 ( V_12 , 1 ) ;
if ( V_90 < 0 )
goto V_116;
for ( V_107 = 0 ; V_107 < V_105 -> V_88 ; V_107 += V_109 ) {
if ( ( V_107 >= V_117 ) && ( V_107 < V_118 ) )
continue;
memcpy ( V_106 , & V_105 -> V_113 [ V_107 ] , V_109 ) ;
if ( V_108 >= V_107 &&
V_108 < V_107 + V_109 ) {
F_44 ( V_12 -> V_22 ,
L_17 ,
V_108 ) ;
V_106 [ V_108 - V_107 ] = V_119 ;
}
V_90 = F_56 ( V_12 -> V_15 ,
F_57 ( V_12 -> V_15 , 0 ) ,
V_99 ,
V_100 | V_101
| V_102 ,
V_107 , 0x0 ,
V_106 , V_109 ,
V_55 ) ;
if ( V_90 < 0 )
goto V_116;
}
V_90 = F_55 ( V_12 , 0 ) ;
if ( V_90 < 0 )
goto V_116;
goto exit;
V_116:
F_59 (KERN_ERR PFX L_18 ,
retval) ;
exit:
F_8 ( V_106 ) ;
return V_90 ;
}
static int F_61 ( struct V_11 * V_12 ,
struct V_2 * V_3 ,
T_3 V_82 , const void * V_30 , T_3 V_84 ,
void * V_120 , unsigned V_121 , T_3 * V_122 )
{
int V_123 ;
int V_90 = 0 ;
enum V_57 V_19 ;
F_5 ( F_62 () ) ;
if ( ! V_12 -> V_15 ) {
V_90 = - V_124 ;
goto exit;
}
if ( V_12 -> V_92 -> V_7 != - V_8 )
F_31 ( L_19 , V_72 ) ;
F_63 ( & V_12 -> V_125 ) ;
V_123 = F_50 ( V_3 -> V_10 , V_82 , V_3 -> V_24 , V_30 ,
V_84 , V_12 -> V_68 ) ;
F_54 ( V_3 -> V_6 , V_12 -> V_15 , V_12 -> V_126 ,
V_3 -> V_10 , V_123 ,
F_38 , V_3 ) ;
if ( V_3 -> V_25 )
V_12 -> V_68 = F_1 ( V_12 -> V_68 ) ;
F_36 ( V_12 , V_3 ) ;
F_64 ( & V_12 -> V_125 ) ;
if ( V_3 -> V_25 )
F_45 ( V_12 , V_3 ) ;
V_19 = V_3 -> V_19 ;
switch ( V_19 ) {
case V_36 :
V_90 = V_3 -> V_6 -> V_7 ;
break;
case V_52 :
case V_53 :
if ( ! V_3 -> V_25 )
break;
default:
F_31 ( L_20 , V_72 ,
V_19 ) ;
case V_20 :
case V_38 :
case V_21 :
case V_37 :
F_59 (KERN_ERR PFX L_21
L_22 , state, upriv->reply_count) ;
V_12 -> V_68 = 0 ;
if ( V_19 == V_20
|| V_19 == V_21 ) {
F_59 (KERN_ERR PFX L_23 ) ;
V_90 = - V_127 ;
} else {
F_59 (KERN_ERR PFX L_24 ) ;
V_90 = - V_98 ;
}
goto exit;
}
if ( V_3 -> V_25 ) {
struct V_62 * V_63 = V_3 -> V_10 ;
unsigned V_128 ;
if ( V_63 -> V_89 != 0 )
V_128 = F_43 ( V_63 -> V_89 ) * 2 + 12 ;
else
V_128 = 14 ;
if ( V_128 != V_3 -> V_73 ) {
F_31 ( L_25
L_26 , V_72 ,
V_3 -> V_25 , V_128 , V_3 -> V_73 ) ;
V_90 = - V_129 ;
goto exit;
}
if ( V_120 )
memcpy ( V_120 , V_63 -> V_30 , F_65 ( V_128 , V_121 ) ) ;
if ( V_122 )
* V_122 = F_43 ( V_63 -> V_89 ) ;
}
exit:
F_2 ( V_3 ) ;
return V_90 ;
}
static int F_66 ( struct V_130 * V_131 , int V_132 , T_3 V_83 ,
T_3 V_82 , const void * V_30 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
T_3 V_84 ;
struct V_2 * V_3 ;
if ( V_82 == 0 )
return - V_115 ;
V_82 = F_67 ( V_82 ) ;
if ( V_82 == 0 )
return 0 ;
V_3 = F_16 ( V_12 , V_83 , V_133 ) ;
if ( ! V_3 )
return - V_111 ;
if ( V_83 == V_39 )
V_84 = V_134 ;
else
V_84 = V_135 ;
return F_61 ( V_12 , V_3 , V_82 , V_30 , V_84 ,
NULL , 0 , NULL ) ;
}
static int F_68 ( struct V_130 * V_131 , int V_132 , T_3 V_83 ,
unsigned V_136 , T_3 * V_82 , void * V_10 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_2 * V_3 ;
if ( V_136 % 2 )
return - V_115 ;
V_3 = F_16 ( V_12 , V_83 , V_83 ) ;
if ( ! V_3 )
return - V_111 ;
return F_61 ( V_12 , V_3 , 0 , NULL , V_135 ,
V_10 , V_136 , V_82 ) ;
}
static int F_69 ( struct V_130 * V_131 , T_3 V_137 , T_3 V_138 , T_3 V_139 ,
T_3 V_140 , struct V_141 * V_142 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_2 * V_3 ;
T_4 V_30 [ 4 ] = {
F_51 ( V_137 ) ,
F_51 ( V_138 ) ,
F_51 ( V_139 ) ,
F_51 ( V_140 ) ,
} ;
F_44 ( V_12 -> V_22 ,
L_27 , V_137 ,
V_138 , V_139 , V_140 ) ;
V_3 = F_16 ( V_12 , V_143 , V_133 ) ;
if ( ! V_3 )
return - V_111 ;
return F_61 ( V_12 , V_3 , sizeof( V_30 ) , & V_30 ,
V_135 , NULL , 0 , NULL ) ;
}
static int F_70 ( struct V_130 * V_131 , T_3 V_137 , T_3 V_138 ,
struct V_141 * V_142 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_2 * V_3 ;
T_4 V_30 [ 4 ] = {
F_51 ( V_137 ) ,
F_51 ( V_138 ) ,
0 ,
0 ,
} ;
F_44 ( V_12 -> V_22 , L_28 , V_137 , V_138 ) ;
V_3 = F_16 ( V_12 , V_143 , V_133 ) ;
if ( ! V_3 )
return - V_111 ;
return F_61 ( V_12 , V_3 , sizeof( V_30 ) , & V_30 ,
V_135 , NULL , 0 , NULL ) ;
}
static int F_71 ( struct V_130 * V_131 , int V_132 ,
void * V_10 , int V_144 , T_3 V_145 , T_3 V_146 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_62 * V_63 = ( void * ) V_12 -> V_92 -> V_64 ;
int V_74 = V_12 -> V_92 -> V_74 ;
if ( V_145 == V_147 ) {
if ( ( sizeof( * V_63 ) + V_146 + V_144 ) > V_74 ) {
F_59 (KERN_ERR PFX L_29
L_30 ) ;
return - V_115 ;
}
memcpy ( V_10 , V_63 -> V_30 + V_146 , V_144 ) ;
return 0 ;
}
if ( F_72 ( V_145 ) ) {
if ( ( sizeof( * V_63 ) + V_146 + V_144 - 4 ) > V_74 ) {
F_59 (KERN_ERR PFX L_29
L_31 ) ;
return - V_98 ;
}
memcpy ( V_10 , V_63 -> V_30 + V_146 - 4 , V_144 ) ;
} else {
F_59 (KERN_ERR PFX L_32 , id) ;
return - V_115 ;
}
return 0 ;
}
static int F_73 ( struct V_130 * V_131 , T_4 * V_148 ,
T_5 V_149 , T_3 V_150 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_2 * V_3 ;
T_4 V_30 [] = {
F_51 ( V_149 & 0xffff ) ,
F_51 (pda_len - 4 )
} ;
V_3 = F_16 ( V_12 , V_151 , V_151 ) ;
if ( ! V_3 )
return - V_111 ;
V_148 [ 0 ] = F_51 ( V_150 - 2 ) ;
V_148 [ 1 ] = F_51 ( 0x0800 ) ;
return F_61 ( V_12 , V_3 , sizeof( V_30 ) , & V_30 ,
V_135 , & V_148 [ 2 ] , V_150 - 4 ,
NULL ) ;
}
static int F_74 ( struct V_130 * V_131 , T_5 V_152 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_2 * V_3 ;
T_6 V_30 = F_75 ( V_152 ) ;
V_3 = F_16 ( V_12 , V_153 , V_133 ) ;
if ( ! V_3 )
return - V_111 ;
return F_61 ( V_12 , V_3 , sizeof( V_30 ) , & V_30 ,
V_135 , NULL , 0 , NULL ) ;
}
static int F_76 ( struct V_130 * V_131 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_2 * V_3 ;
V_3 = F_16 ( V_12 , V_154 , V_133 ) ;
if ( ! V_3 )
return - V_111 ;
return F_61 ( V_12 , V_3 , 0 , NULL ,
V_135 , NULL , 0 , NULL ) ;
}
static int F_77 ( struct V_130 * V_131 , const char * V_10 ,
T_5 V_107 , T_5 V_144 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
struct V_2 * V_3 ;
T_6 V_30 = F_75 ( V_107 ) ;
int F_31 ;
V_3 = F_16 ( V_12 , V_155 , V_133 ) ;
if ( ! V_3 )
return - V_111 ;
F_31 = F_61 ( V_12 , V_3 , sizeof( V_30 ) , & V_30 ,
V_135 , NULL , 0 , NULL ) ;
if ( F_31 )
return F_31 ;
V_3 = F_16 ( V_12 , V_156 , V_133 ) ;
if ( ! V_3 )
return - V_111 ;
return F_61 ( V_12 , V_3 , V_144 , V_10 ,
V_135 , NULL , 0 , NULL ) ;
}
static int F_78 ( struct V_130 * V_131 , const char * V_10 ,
T_5 V_107 , T_5 V_144 )
{
T_5 V_157 ;
T_5 V_158 ;
int F_31 = 0 ;
V_158 = ( V_144 < V_159 ) ? V_144 : V_159 ;
V_157 = V_107 ;
while ( V_157 < ( V_107 + V_144 ) ) {
F_79 ( L_33
L_34 ,
V_158 , V_157 , & V_10 [ V_157 - V_107 ] ) ;
F_31 = F_77 ( V_131 , & V_10 [ V_157 - V_107 ] ,
V_157 , V_158 ) ;
if ( F_31 )
break;
V_157 += V_158 ;
V_158 = ( ( V_107 + V_144 - V_157 ) < V_159 ) ?
( V_107 + V_144 - V_157 ) : V_159 ;
}
return F_31 ;
}
static T_7 F_80 ( struct V_160 * V_161 , struct V_40 * V_22 )
{
struct V_41 * V_42 = F_29 ( V_22 ) ;
struct V_43 * V_44 = & V_42 -> V_44 ;
struct V_11 * V_12 = V_42 -> V_162 ;
T_1 V_163 [ V_164 + 1 ] ;
int F_31 = 0 ;
int V_165 ;
unsigned long V_33 ;
struct V_2 * V_3 ;
T_1 * V_10 ;
int V_166 ;
if ( ! F_81 ( V_22 ) ) {
F_59 ( V_167 L_35 ,
V_22 -> V_168 ) ;
return V_169 ;
}
if ( F_82 ( V_22 ) ) {
F_59 ( V_170 L_36 ,
V_22 -> V_168 ) ;
return V_169 ;
}
if ( F_83 ( V_42 , & V_33 ) != 0 ) {
F_59 ( V_167
L_37 ,
V_22 -> V_168 ) ;
return V_169 ;
}
if ( ! F_84 ( V_22 ) ||
( V_42 -> V_171 == V_172 ) ) {
goto V_173;
}
if ( V_161 -> V_144 < V_174 )
goto V_173;
V_3 = F_16 ( V_12 , V_39 , 0 ) ;
if ( ! V_3 )
goto V_175;
memset ( V_3 -> V_10 , 0 , V_27 ) ;
V_10 = V_3 -> V_10 -> V_30 ;
V_165 = 0 ;
F_31 = F_85 ( V_161 , V_22 , V_42 , & V_165 ,
& V_163 [ 0 ] ) ;
if ( F_31 )
goto V_173;
{
T_4 * V_176 = ( T_4 * ) V_10 ;
* V_176 = F_51 ( V_165 ) ;
V_10 += sizeof( * V_176 ) ;
}
memcpy ( V_10 , V_161 -> V_30 , V_161 -> V_144 ) ;
V_10 += V_161 -> V_144 ;
if ( V_165 & V_177 ) {
T_1 * V_178 = V_163 ;
if ( V_161 -> V_144 % 2 )
V_178 ++ ;
memcpy ( V_10 , V_178 , V_164 ) ;
V_10 += V_164 ;
}
F_86 ( V_22 ) ;
V_166 = F_87 ( V_10 - V_3 -> V_10 -> V_30 , 2 ) ;
F_31 = F_61 ( V_12 , V_3 , V_166 , NULL ,
V_134 , NULL , 0 , NULL ) ;
if ( F_31 ) {
F_88 ( V_22 ) ;
if ( F_89 () )
F_59 ( V_167 L_38 ,
V_22 -> V_168 , F_31 ) ;
goto V_175;
}
V_22 -> V_179 = V_54 ;
V_44 -> V_180 += V_161 -> V_144 ;
goto V_181;
V_173:
V_44 -> V_45 ++ ;
V_44 -> V_182 ++ ;
V_181:
F_90 ( V_42 , & V_33 ) ;
F_91 ( V_161 ) ;
return V_183 ;
V_175:
F_90 ( V_42 , & V_33 ) ;
return V_169 ;
}
static int F_92 ( struct V_130 * V_131 , T_3 V_88 , T_3 * V_184 )
{
* V_184 = V_39 ;
return 0 ;
}
static int F_93 ( struct V_41 * V_42 )
{
struct V_11 * V_12 = V_42 -> V_162 ;
int V_90 = F_55 ( V_12 , 1 ) ;
if ( V_90 < 0 ) {
F_31 ( L_39 ) ;
return V_90 ;
}
V_90 = F_55 ( V_12 , 0 ) ;
if ( V_90 < 0 ) {
F_31 ( L_40 ) ;
return V_90 ;
}
F_44 ( V_12 -> V_22 , L_41 ) ;
V_90 = F_56 ( V_12 -> V_15 ,
F_57 ( V_12 -> V_15 , 0 ) ,
V_185 ,
V_100 | V_101 |
V_102 , 0x0 , 0x0 , NULL , 0 ,
V_55 ) ;
if ( V_90 < 0 ) {
F_31 ( L_42 , V_90 ) ;
return V_90 ;
}
#if 0
dbg("Sending EZUSB_REQUEST_TRIG_AC");
retval = usb_control_msg(upriv->udev,
usb_sndctrlpipe(upriv->udev, 0),
EZUSB_REQUEST_TRIG_AC,
USB_TYPE_VENDOR | USB_RECIP_DEVICE |
USB_DIR_OUT, 0x00FA, 0x0, NULL, 0,
DEF_TIMEOUT);
if (retval < 0) {
err("EZUSB_REQUEST_TRIG_AC failed retval %d", retval);
return retval;
}
#endif
return 0 ;
}
static int F_94 ( struct V_130 * V_131 )
{
struct V_11 * V_12 = V_131 -> V_42 ;
int V_90 ;
F_5 ( F_95 () ) ;
F_5 ( ! V_12 ) ;
V_12 -> V_68 = 0 ;
F_96 ( V_131 , V_186 , V_187 ) ;
F_96 ( V_131 , V_188 , V_147 ) ;
F_97 ( V_12 -> V_92 ) ;
F_53 ( V_12 ) ;
V_90 = F_66 ( V_131 , 0 , V_189 ,
F_52 ( 2 ) , L_43 ) ;
if ( V_90 < 0 ) {
F_59 (KERN_ERR PFX L_44 , retval) ;
return V_90 ;
}
V_90 = F_70 ( V_131 , V_190 , 0 , NULL ) ;
if ( V_90 < 0 ) {
F_59 (KERN_ERR PFX L_45 , retval) ;
return V_90 ;
}
return 0 ;
}
static void V_95 ( struct V_56 * V_56 )
{
struct V_11 * V_12 = (struct V_11 * ) V_56 -> V_58 ;
struct V_62 * V_63 = V_56 -> V_64 ;
T_3 V_78 ;
T_3 V_71 ;
if ( V_12 -> V_15 == NULL )
return;
if ( V_56 -> V_7 == - V_127 ) {
F_40 ( L_46 , V_72 ) ;
return;
}
if ( V_56 -> V_7 == - V_191 ) {
F_40 ( L_47 ,
V_72 ) ;
goto V_192;
}
if ( ( V_56 -> V_7 == - V_193 )
|| ( V_56 -> V_7 == - V_194 )
|| ( V_56 -> V_7 == - V_195 ) ) {
F_44 ( V_12 -> V_22 , L_48 ,
V_56 -> V_7 ) ;
return;
}
if ( V_56 -> V_7 )
F_44 ( V_12 -> V_22 , L_49 ,
V_56 -> V_7 , V_56 -> V_74 ) ;
if ( V_56 -> V_74 < sizeof( * V_63 ) ) {
F_31 ( L_50 , V_72 ) ;
goto V_192;
}
V_78 = F_49 ( V_63 ) ;
if ( F_43 ( V_63 -> V_78 ) != V_78 ) {
F_31 ( L_51 ) ;
goto V_192;
}
V_71 = F_43 ( V_63 -> V_71 ) ;
if ( ( V_71 != V_147 ) && ! F_72 ( V_71 ) ) {
F_41 ( V_12 , V_56 ) ;
} else if ( V_12 -> V_22 ) {
struct V_40 * V_22 = V_12 -> V_22 ;
struct V_41 * V_42 = F_29 ( V_22 ) ;
struct V_130 * V_131 = & V_42 -> V_131 ;
if ( V_71 == V_147 ) {
F_98 ( V_22 , V_131 ) ;
} else {
F_96 ( V_131 , V_196 ,
F_43 ( V_63 -> V_71 ) ) ;
F_99 ( V_22 , V_131 ) ;
}
}
V_192:
if ( V_12 -> V_15 )
F_53 ( V_12 ) ;
}
static inline void F_100 ( struct V_11 * V_12 )
{
struct V_40 * V_22 ;
struct V_65 * V_66 ;
struct V_65 * V_197 ;
unsigned long V_33 ;
F_5 ( F_95 () ) ;
F_5 ( ! V_12 ) ;
V_22 = V_12 -> V_22 ;
F_101 ( & V_12 -> V_198 ) ;
V_12 -> V_15 = NULL ;
F_97 ( V_12 -> V_92 ) ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
F_102 (item, tmp_item, &upriv->req_active) {
struct V_2 * V_3 ;
int F_31 ;
V_3 = F_33 ( V_66 , struct V_2 , V_35 ) ;
F_14 ( & V_3 -> V_4 ) ;
V_3 -> V_6 -> V_17 |= V_18 ;
F_31 = F_12 ( V_3 -> V_6 ) ;
F_27 ( & V_12 -> V_34 , V_33 ) ;
if ( F_31 == - V_8 )
F_103 ( & V_3 -> V_5 ) ;
F_104 ( & V_3 -> V_9 ) ;
if ( ! F_32 ( & V_3 -> V_35 ) )
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
F_25 ( & V_12 -> V_34 , V_33 ) ;
}
F_27 ( & V_12 -> V_34 , V_33 ) ;
F_102 (item, tmp_item, &upriv->req_pending)
F_15 ( F_33 ( V_66 ,
struct V_2 , V_35 ) ) ;
if ( V_12 -> V_92 && V_12 -> V_92 -> V_7 == - V_8 )
F_59 (KERN_ERR PFX L_52 ) ;
F_105 ( & V_12 -> V_198 ) ;
if ( V_12 -> V_92 ) {
F_8 ( V_12 -> V_92 -> V_64 ) ;
F_7 ( V_12 -> V_92 ) ;
}
F_8 ( V_12 -> V_199 ) ;
if ( V_12 -> V_22 ) {
struct V_41 * V_42 = F_29 ( V_12 -> V_22 ) ;
F_106 ( V_42 ) ;
F_107 ( V_42 ) ;
}
}
static void F_108 ( T_8 * V_200 ,
unsigned long * V_33 ) __acquires( V_200 )
{
F_63 ( V_200 ) ;
}
static void F_109 ( T_8 * V_200 ,
unsigned long * V_33 ) __releases( V_200 )
{
F_64 ( V_200 ) ;
}
static void F_110 ( T_8 * V_200 ) __acquires( V_200 )
{
F_63 ( V_200 ) ;
}
static void F_111 ( T_8 * V_200 ) __releases( V_200 )
{
F_64 ( V_200 ) ;
}
static int F_112 ( struct V_201 * V_202 ,
const struct V_203 * V_145 )
{
struct V_204 * V_15 = F_113 ( V_202 ) ;
struct V_41 * V_42 ;
struct V_130 * V_131 ;
struct V_11 * V_12 = NULL ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
const struct V_209 * V_210 = NULL ;
int V_90 = 0 ;
int V_80 ;
V_42 = F_114 ( sizeof( * V_12 ) , & V_15 -> V_22 ,
F_93 , NULL ) ;
if ( ! V_42 ) {
F_31 ( L_53 ) ;
goto exit;
}
V_131 = & V_42 -> V_131 ;
V_12 = V_42 -> V_162 ;
F_115 ( & V_12 -> V_198 ) ;
F_116 ( & V_12 -> V_125 ) ;
F_116 ( & V_12 -> V_34 ) ;
F_117 ( & V_12 -> V_50 ) ;
F_117 ( & V_12 -> V_48 ) ;
V_12 -> V_15 = V_15 ;
V_131 -> V_211 = ( void V_212 V_213 * ) & V_12 -> V_214 ;
V_131 -> V_215 = V_216 ;
V_131 -> V_42 = V_12 ;
V_131 -> V_217 = & V_218 ;
V_206 = & V_202 -> V_219 [ 0 ] . V_220 ;
for ( V_80 = 0 ; V_80 < V_206 -> V_221 ; ++ V_80 ) {
V_208 = & V_202 -> V_219 [ 0 ] . V_222 [ V_80 ] . V_220 ;
if ( ( ( V_208 -> V_223 & V_224 )
== V_225 ) &&
( ( V_208 -> V_226 & V_227 )
== V_228 ) ) {
if ( V_12 -> V_92 != NULL ) {
F_40 ( L_54 ) ;
continue;
}
V_12 -> V_92 = F_19 ( 0 , V_110 ) ;
if ( ! V_12 -> V_92 ) {
F_31 ( L_55 ) ;
goto error;
}
if ( F_43 ( V_208 -> V_229 ) != 64 )
F_40 ( L_56 ) ;
if ( V_208 -> V_223 != ( 2 | V_225 ) )
F_40 ( L_57 ,
V_208 -> V_223 ) ;
V_12 -> V_94 = F_118 ( V_15 ,
V_208 ->
V_223 ) ;
V_12 -> V_92 -> V_64 =
F_18 ( V_27 , V_110 ) ;
if ( ! V_12 -> V_92 -> V_64 ) {
F_31 ( L_58 ) ;
goto error;
}
}
if ( ( ( V_208 -> V_223 & V_224 )
== V_102 ) &&
( ( V_208 -> V_226 & V_227 )
== V_228 ) ) {
if ( V_12 -> V_199 != NULL ) {
F_40 ( L_59 ) ;
continue;
}
if ( F_43 ( V_208 -> V_229 ) != 64 )
F_40 ( L_60 ) ;
if ( V_208 -> V_223 != 2 )
F_40 ( L_61 ,
V_208 -> V_223 ) ;
V_12 -> V_126 = F_119 ( V_15 ,
V_208 ->
V_223 ) ;
V_12 -> V_199 = F_18 ( V_27 , V_110 ) ;
if ( ! V_12 -> V_199 ) {
F_31 ( L_62 ) ;
goto error;
}
}
}
if ( ! V_12 -> V_199 || ! V_12 -> V_92 ) {
F_31 ( L_63 ) ;
goto error;
}
if ( F_120 ( & V_210 , L_64 ,
& V_202 -> V_22 ) == 0 ) {
V_209 . V_88 = V_210 -> V_88 ;
V_209 . V_113 = V_210 -> V_30 ;
}
if ( V_209 . V_88 && V_209 . V_113 ) {
if ( F_58 ( V_12 , & V_209 ) < 0 )
goto error;
} else {
F_31 ( L_65 ) ;
goto error;
}
if ( F_93 ( V_42 ) < 0 ) {
F_31 ( L_66 ) ;
goto error;
}
if ( F_94 ( V_131 ) < 0 ) {
F_31 ( L_67 ) ;
F_31 ( L_68 ) ;
goto error;
}
if ( F_121 ( V_42 ) != 0 ) {
F_31 ( L_69 ) ;
goto error;
}
if ( F_122 ( V_42 , 0 , 0 , & V_230 ) != 0 ) {
V_12 -> V_22 = NULL ;
F_31 ( L_70 , V_72 ) ;
goto error;
}
V_12 -> V_22 = V_42 -> V_231 ;
goto exit;
error:
F_100 ( V_12 ) ;
if ( V_12 -> V_22 ) {
F_107 ( V_42 ) ;
}
V_12 = NULL ;
V_90 = - V_98 ;
exit:
if ( V_210 ) {
V_209 . V_113 = NULL ;
V_209 . V_88 = 0 ;
F_123 ( V_210 ) ;
}
F_124 ( V_202 , V_12 ) ;
return V_90 ;
}
static void F_125 ( struct V_201 * V_232 )
{
struct V_11 * V_12 = F_126 ( V_232 ) ;
F_124 ( V_232 , NULL ) ;
F_100 ( V_12 ) ;
F_59 (KERN_INFO PFX L_71 ) ;
}
