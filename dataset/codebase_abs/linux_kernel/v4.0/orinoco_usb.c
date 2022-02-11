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
F_22 ( & V_3 -> V_9 , F_11 , ( T_2 ) V_3 ) ;
return V_3 ;
}
static inline void F_23 ( struct V_29 * V_30 )
{
F_24 ( V_30 ) ;
F_24 ( V_30 ) ;
F_24 ( V_30 ) ;
F_24 ( V_30 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_12 ;
unsigned long V_31 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
F_26 ( & V_3 -> V_33 ) ;
if ( V_12 -> V_15 ) {
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_28 ( V_12 ) ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
}
switch ( V_3 -> V_19 ) {
case V_34 :
case V_35 :
case V_36 :
case V_20 :
case V_21 :
F_27 ( & V_12 -> V_32 , V_31 ) ;
if ( ( V_3 -> V_24 == V_37 ) && V_12 -> V_22 ) {
struct V_38 * V_22 = V_12 -> V_22 ;
struct V_39 * V_40 = F_29 ( V_22 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
if ( V_3 -> V_19 != V_34 )
V_42 -> V_43 ++ ;
else
V_42 -> V_44 ++ ;
F_30 ( V_22 ) ;
}
F_23 ( & V_3 -> V_5 ) ;
F_2 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
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
unsigned long V_31 ;
struct V_2 * V_3 ;
int V_45 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
if ( ! F_32 ( & V_12 -> V_46 ) )
goto V_47;
if ( F_32 ( & V_12 -> V_48 ) )
goto V_47;
V_3 =
F_33 ( V_12 -> V_48 . V_49 , struct V_2 ,
V_33 ) ;
if ( ! V_3 -> V_12 -> V_15 )
goto V_47;
F_34 ( & V_3 -> V_33 , & V_12 -> V_46 ) ;
if ( V_3 -> V_19 == V_50 ) {
F_14 ( & V_3 -> V_4 ) ;
V_45 = F_35 ( V_3 -> V_6 , V_26 ) ;
if ( V_45 ) {
V_3 -> V_19 = V_35 ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_31 ( L_4
L_5 , V_45 ) ;
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
goto V_5;
}
V_3 -> V_19 = V_51 ;
F_9 ( V_3 -> V_12 , & V_3 -> V_9 ,
V_52 + V_53 ) ;
}
V_47:
F_27 ( & V_12 -> V_32 , V_31 ) ;
V_5:
return;
}
static void F_36 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
unsigned long V_31 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
if ( ! V_3 -> V_12 -> V_15 ) {
F_27 ( & V_12 -> V_32 , V_31 ) ;
goto V_5;
}
F_14 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_33 , & V_12 -> V_48 ) ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
V_3 -> V_19 = V_50 ;
F_28 ( V_12 ) ;
V_5:
return;
}
static void F_38 ( struct V_54 * V_54 )
{
unsigned long V_31 ;
enum V_55 V_19 ;
struct V_2 * V_3 = V_54 -> V_56 ;
struct V_11 * V_12 = V_3 -> V_12 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
F_39 ( & V_3 -> V_9 ) ;
if ( V_3 -> V_23 ) {
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_40 ( L_6 ) ;
goto V_57;
}
V_19 = V_3 -> V_19 ;
if ( V_54 -> V_7 == 0 ) {
switch ( V_19 ) {
case V_51 :
if ( V_3 -> V_25 ) {
V_3 -> V_19 = V_58 ;
F_9 ( V_12 , & V_3 -> V_9 ,
V_52 + V_53 ) ;
F_27 ( & V_12 -> V_32 ,
V_31 ) ;
break;
}
case V_59 :
V_3 -> V_19 = V_34 ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_31 ( L_7 ,
V_19 , V_54 -> V_7 ) ;
break;
}
} else {
switch ( V_19 ) {
case V_51 :
case V_59 :
V_3 -> V_19 = V_36 ;
case V_36 :
case V_20 :
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_31 ( L_7 ,
V_19 , V_54 -> V_7 ) ;
break;
}
}
V_57:
F_2 ( V_3 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
struct V_54 * V_54 )
{
struct V_60 * V_61 = V_54 -> V_62 ;
struct V_2 * V_3 = NULL ;
enum V_55 V_19 ;
unsigned long V_31 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
if ( V_12 -> V_15 ) {
struct V_63 * V_64 ;
F_42 (item, &upriv->req_active) {
struct V_2 * V_65 ;
int V_66 ;
V_65 = F_33 ( V_64 , struct V_2 , V_33 ) ;
V_66 =
F_1 ( V_65 -> V_10 -> V_67 ) ;
if ( ( V_61 -> V_68 == V_66 )
&& ( F_43 ( V_61 -> V_69 ) == V_65 -> V_25 ) ) {
V_3 = V_65 ;
break;
}
F_44 ( V_12 -> V_22 , L_8 ,
F_43 ( V_61 -> V_69 ) , V_65 -> V_25 ,
V_61 -> V_68 , V_66 ) ;
}
}
if ( V_3 == NULL ) {
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_31 ( L_9 , V_70 ,
F_43 ( V_61 -> V_69 ) ) ;
F_28 ( V_12 ) ;
return;
}
V_54 -> V_62 = V_3 -> V_10 ;
V_3 -> V_10 = ( void * ) V_61 ;
V_3 -> V_71 = V_54 -> V_72 ;
V_19 = V_3 -> V_19 ;
switch ( V_19 ) {
case V_51 :
V_3 -> V_19 = V_59 ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
break;
case V_58 :
V_3 -> V_19 = V_34 ;
F_39 ( & V_3 -> V_9 ) ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
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
case V_50 :
case V_51 :
case V_58 :
case V_59 :
if ( F_46 () ) {
int V_73 = V_53 * ( 1000 / V_74 ) ;
while ( ! V_3 -> V_5 . V_5 && V_73 -- )
F_47 ( 1000 ) ;
} else {
F_48 ( V_3 -> V_5 . V_75 ,
V_3 -> V_5 . V_5 ) ;
}
break;
default:
break;
}
}
static inline T_3 F_49 ( struct V_60 * V_76 )
{
T_3 V_77 = 0 ;
T_1 * V_78 = ( T_1 * ) V_76 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ )
V_77 = ( V_77 << 1 ) + V_78 [ V_79 ] ;
return V_77 ;
}
static int F_50 ( struct V_60 * V_80 , T_3 V_81 , T_3 V_82 ,
const void * V_76 , T_3 V_83 , T_1 V_66 )
{
int V_84 = sizeof( * V_80 ) + V_81 ;
F_5 ( V_84 > V_27 ) ;
V_80 -> V_85 = F_51 ( V_86 ) ;
V_80 -> V_67 = V_66 ;
V_80 -> V_68 = 0 ;
V_80 -> V_83 = F_51 ( V_83 ) ;
V_80 -> V_87 = F_51 ( V_81 + 4 ) ;
V_80 -> V_77 = F_51 ( F_49 ( V_80 ) ) ;
V_80 -> V_88 = F_51 ( F_52 ( V_81 ) ) ;
V_80 -> V_69 = F_51 ( V_82 ) ;
if ( V_76 )
memcpy ( V_80 -> V_76 , V_76 , V_81 ) ;
return V_84 ;
}
static int F_53 ( struct V_11 * V_12 )
{
int V_89 = 0 ;
void * V_90 = V_12 -> V_91 -> V_62 ;
if ( V_12 -> V_91 -> V_7 == - V_8 ) {
F_44 ( V_12 -> V_22 , L_11 ) ;
V_89 = - V_92 ;
goto exit;
}
F_54 ( V_12 -> V_91 , V_12 -> V_15 , V_12 -> V_93 ,
V_90 , V_27 ,
V_94 , V_12 ) ;
V_12 -> V_91 -> V_17 = 0 ;
V_89 = F_35 ( V_12 -> V_91 , V_26 ) ;
if ( V_89 )
F_31 ( L_12 , V_70 , V_89 ) ;
exit:
return V_89 ;
}
static inline int F_55 ( struct V_11 * V_12 , int V_95 )
{
T_1 V_96 = V_95 ;
if ( ! V_12 -> V_15 ) {
F_31 ( L_13 , V_70 ) ;
return - V_97 ;
}
return F_56 ( V_12 -> V_15 ,
F_57 ( V_12 -> V_15 , 0 ) ,
V_98 ,
V_99 | V_100 |
V_101 , V_102 , 0 , & V_96 ,
sizeof( V_96 ) , V_53 ) ;
}
static int F_58 ( struct V_11 * V_12 ,
struct V_103 * V_104 )
{
T_1 * V_105 ;
int V_89 , V_106 ;
int V_107 ;
V_105 = F_18 ( V_108 , V_109 ) ;
if ( ! V_105 ) {
F_59 (KERN_ERR PFX L_14 ) ;
return - V_110 ;
}
V_107 = F_60 ( ( V_111 * ) & V_104 -> V_112 [ V_113 ] ) ;
if ( V_107 >= V_104 -> V_87 ) {
F_59 (KERN_ERR PFX L_15
L_16 , variant_offset) ;
V_89 = - V_114 ;
goto V_115;
}
V_89 = F_55 ( V_12 , 1 ) ;
if ( V_89 < 0 )
goto V_115;
for ( V_106 = 0 ; V_106 < V_104 -> V_87 ; V_106 += V_108 ) {
if ( ( V_106 >= V_116 ) && ( V_106 < V_117 ) )
continue;
memcpy ( V_105 , & V_104 -> V_112 [ V_106 ] , V_108 ) ;
if ( V_107 >= V_106 &&
V_107 < V_106 + V_108 ) {
F_44 ( V_12 -> V_22 ,
L_17 ,
V_107 ) ;
V_105 [ V_107 - V_106 ] = V_118 ;
}
V_89 = F_56 ( V_12 -> V_15 ,
F_57 ( V_12 -> V_15 , 0 ) ,
V_98 ,
V_99 | V_100
| V_101 ,
V_106 , 0x0 ,
V_105 , V_108 ,
V_53 ) ;
if ( V_89 < 0 )
goto V_115;
}
V_89 = F_55 ( V_12 , 0 ) ;
if ( V_89 < 0 )
goto V_115;
goto exit;
V_115:
F_59 (KERN_ERR PFX L_18 ,
retval) ;
exit:
F_8 ( V_105 ) ;
return V_89 ;
}
static int F_61 ( struct V_11 * V_12 ,
struct V_2 * V_3 ,
T_3 V_81 , const void * V_76 , T_3 V_83 ,
void * V_119 , unsigned V_120 , T_3 * V_121 )
{
int V_122 ;
int V_89 = 0 ;
enum V_55 V_19 ;
F_5 ( F_62 () ) ;
if ( ! V_12 -> V_15 ) {
V_89 = - V_123 ;
goto exit;
}
if ( V_12 -> V_91 -> V_7 != - V_8 )
F_31 ( L_19 , V_70 ) ;
F_63 ( & V_12 -> V_124 ) ;
V_122 = F_50 ( V_3 -> V_10 , V_81 , V_3 -> V_24 , V_76 ,
V_83 , V_12 -> V_66 ) ;
F_54 ( V_3 -> V_6 , V_12 -> V_15 , V_12 -> V_125 ,
V_3 -> V_10 , V_122 ,
F_38 , V_3 ) ;
if ( V_3 -> V_25 )
V_12 -> V_66 = F_1 ( V_12 -> V_66 ) ;
F_36 ( V_12 , V_3 ) ;
F_64 ( & V_12 -> V_124 ) ;
if ( V_3 -> V_25 )
F_45 ( V_12 , V_3 ) ;
V_19 = V_3 -> V_19 ;
switch ( V_19 ) {
case V_34 :
V_89 = V_3 -> V_6 -> V_7 ;
break;
case V_50 :
case V_51 :
if ( ! V_3 -> V_25 )
break;
default:
F_31 ( L_20 , V_70 ,
V_19 ) ;
case V_20 :
case V_36 :
case V_21 :
case V_35 :
F_59 (KERN_ERR PFX L_21
L_22 , state, upriv->reply_count) ;
V_12 -> V_66 = 0 ;
if ( V_19 == V_20
|| V_19 == V_21 ) {
F_59 (KERN_ERR PFX L_23 ) ;
V_89 = - V_126 ;
} else {
F_59 (KERN_ERR PFX L_24 ) ;
V_89 = - V_97 ;
}
goto exit;
}
if ( V_3 -> V_25 ) {
struct V_60 * V_61 = V_3 -> V_10 ;
unsigned V_127 ;
if ( V_61 -> V_88 != 0 )
V_127 = F_43 ( V_61 -> V_88 ) * 2 + 12 ;
else
V_127 = 14 ;
if ( V_127 != V_3 -> V_71 ) {
F_31 ( L_25
L_26 , V_70 ,
V_3 -> V_25 , V_127 , V_3 -> V_71 ) ;
V_89 = - V_128 ;
goto exit;
}
if ( V_119 )
memcpy ( V_119 , V_61 -> V_76 , F_65 ( V_127 , V_120 ) ) ;
if ( V_121 )
* V_121 = F_43 ( V_61 -> V_88 ) ;
}
exit:
F_2 ( V_3 ) ;
return V_89 ;
}
static int F_66 ( struct V_129 * V_130 , int V_131 , T_3 V_82 ,
T_3 V_81 , const void * V_76 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
T_3 V_83 ;
struct V_2 * V_3 ;
if ( V_81 == 0 )
return - V_114 ;
V_81 = F_67 ( V_81 ) ;
if ( V_81 == 0 )
return 0 ;
V_3 = F_16 ( V_12 , V_82 , V_132 ) ;
if ( ! V_3 )
return - V_110 ;
if ( V_82 == V_37 )
V_83 = V_133 ;
else
V_83 = V_134 ;
return F_61 ( V_12 , V_3 , V_81 , V_76 , V_83 ,
NULL , 0 , NULL ) ;
}
static int F_68 ( struct V_129 * V_130 , int V_131 , T_3 V_82 ,
unsigned V_135 , T_3 * V_81 , void * V_10 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_2 * V_3 ;
if ( V_135 % 2 )
return - V_114 ;
V_3 = F_16 ( V_12 , V_82 , V_82 ) ;
if ( ! V_3 )
return - V_110 ;
return F_61 ( V_12 , V_3 , 0 , NULL , V_134 ,
V_10 , V_135 , V_81 ) ;
}
static int F_69 ( struct V_129 * V_130 , T_3 V_136 , T_3 V_137 , T_3 V_138 ,
T_3 V_139 , struct V_140 * V_141 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_2 * V_3 ;
T_4 V_76 [ 4 ] = {
F_51 ( V_136 ) ,
F_51 ( V_137 ) ,
F_51 ( V_138 ) ,
F_51 ( V_139 ) ,
} ;
F_44 ( V_12 -> V_22 ,
L_27 , V_136 ,
V_137 , V_138 , V_139 ) ;
V_3 = F_16 ( V_12 , V_142 , V_132 ) ;
if ( ! V_3 )
return - V_110 ;
return F_61 ( V_12 , V_3 , sizeof( V_76 ) , & V_76 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_70 ( struct V_129 * V_130 , T_3 V_136 , T_3 V_137 ,
struct V_140 * V_141 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_2 * V_3 ;
T_4 V_76 [ 4 ] = {
F_51 ( V_136 ) ,
F_51 ( V_137 ) ,
0 ,
0 ,
} ;
F_44 ( V_12 -> V_22 , L_28 , V_136 , V_137 ) ;
V_3 = F_16 ( V_12 , V_142 , V_132 ) ;
if ( ! V_3 )
return - V_110 ;
return F_61 ( V_12 , V_3 , sizeof( V_76 ) , & V_76 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_71 ( struct V_129 * V_130 , int V_131 ,
void * V_10 , int V_143 , T_3 V_144 , T_3 V_145 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_60 * V_61 = ( void * ) V_12 -> V_91 -> V_62 ;
int V_72 = V_12 -> V_91 -> V_72 ;
if ( V_144 == V_146 ) {
if ( ( sizeof( * V_61 ) + V_145 + V_143 ) > V_72 ) {
F_59 (KERN_ERR PFX L_29
L_30 ) ;
return - V_114 ;
}
memcpy ( V_10 , V_61 -> V_76 + V_145 , V_143 ) ;
return 0 ;
}
if ( F_72 ( V_144 ) ) {
if ( ( sizeof( * V_61 ) + V_145 + V_143 - 4 ) > V_72 ) {
F_59 (KERN_ERR PFX L_29
L_31 ) ;
return - V_97 ;
}
memcpy ( V_10 , V_61 -> V_76 + V_145 - 4 , V_143 ) ;
} else {
F_59 (KERN_ERR PFX L_32 , id) ;
return - V_114 ;
}
return 0 ;
}
static int F_73 ( struct V_129 * V_130 , T_4 * V_147 ,
T_5 V_148 , T_3 V_149 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_2 * V_3 ;
T_4 V_76 [] = {
F_51 ( V_148 & 0xffff ) ,
F_51 (pda_len - 4 )
} ;
V_3 = F_16 ( V_12 , V_150 , V_150 ) ;
if ( ! V_3 )
return - V_110 ;
V_147 [ 0 ] = F_51 ( V_149 - 2 ) ;
V_147 [ 1 ] = F_51 ( 0x0800 ) ;
return F_61 ( V_12 , V_3 , sizeof( V_76 ) , & V_76 ,
V_134 , & V_147 [ 2 ] , V_149 - 4 ,
NULL ) ;
}
static int F_74 ( struct V_129 * V_130 , T_5 V_151 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_2 * V_3 ;
T_6 V_76 = F_75 ( V_151 ) ;
V_3 = F_16 ( V_12 , V_152 , V_132 ) ;
if ( ! V_3 )
return - V_110 ;
return F_61 ( V_12 , V_3 , sizeof( V_76 ) , & V_76 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_76 ( struct V_129 * V_130 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_2 * V_3 ;
V_3 = F_16 ( V_12 , V_153 , V_132 ) ;
if ( ! V_3 )
return - V_110 ;
return F_61 ( V_12 , V_3 , 0 , NULL ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_77 ( struct V_129 * V_130 , const char * V_10 ,
T_5 V_106 , T_5 V_143 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
struct V_2 * V_3 ;
T_6 V_76 = F_75 ( V_106 ) ;
int F_31 ;
V_3 = F_16 ( V_12 , V_154 , V_132 ) ;
if ( ! V_3 )
return - V_110 ;
F_31 = F_61 ( V_12 , V_3 , sizeof( V_76 ) , & V_76 ,
V_134 , NULL , 0 , NULL ) ;
if ( F_31 )
return F_31 ;
V_3 = F_16 ( V_12 , V_155 , V_132 ) ;
if ( ! V_3 )
return - V_110 ;
return F_61 ( V_12 , V_3 , V_143 , V_10 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_78 ( struct V_129 * V_130 , const char * V_10 ,
T_5 V_106 , T_5 V_143 )
{
T_5 V_156 ;
T_5 V_157 ;
int F_31 = 0 ;
V_157 = ( V_143 < V_158 ) ? V_143 : V_158 ;
V_156 = V_106 ;
while ( V_156 < ( V_106 + V_143 ) ) {
F_79 ( L_33
L_34 ,
V_157 , V_156 , & V_10 [ V_156 - V_106 ] ) ;
F_31 = F_77 ( V_130 , & V_10 [ V_156 - V_106 ] ,
V_156 , V_157 ) ;
if ( F_31 )
break;
V_156 += V_157 ;
V_157 = ( ( V_106 + V_143 - V_156 ) < V_158 ) ?
( V_106 + V_143 - V_156 ) : V_158 ;
}
return F_31 ;
}
static T_7 F_80 ( struct V_159 * V_160 , struct V_38 * V_22 )
{
struct V_39 * V_40 = F_29 ( V_22 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
struct V_11 * V_12 = V_40 -> V_161 ;
T_1 V_162 [ V_163 + 1 ] ;
int F_31 = 0 ;
int V_164 ;
unsigned long V_31 ;
struct V_2 * V_3 ;
T_1 * V_10 ;
int V_165 ;
if ( ! F_81 ( V_22 ) ) {
F_59 ( V_166 L_35 ,
V_22 -> V_167 ) ;
return V_168 ;
}
if ( F_82 ( V_22 ) ) {
F_59 ( V_169 L_36 ,
V_22 -> V_167 ) ;
return V_168 ;
}
if ( F_83 ( V_40 , & V_31 ) != 0 ) {
F_59 ( V_166
L_37 ,
V_22 -> V_167 ) ;
return V_168 ;
}
if ( ! F_84 ( V_22 ) ||
( V_40 -> V_170 == V_171 ) ) {
goto V_172;
}
if ( V_160 -> V_143 < V_173 )
goto V_172;
V_3 = F_16 ( V_12 , V_37 , 0 ) ;
if ( ! V_3 )
goto V_174;
memset ( V_3 -> V_10 , 0 , V_27 ) ;
V_10 = V_3 -> V_10 -> V_76 ;
V_164 = 0 ;
F_31 = F_85 ( V_160 , V_22 , V_40 , & V_164 ,
& V_162 [ 0 ] ) ;
if ( F_31 )
goto V_172;
{
T_4 * V_175 = ( T_4 * ) V_10 ;
* V_175 = F_51 ( V_164 ) ;
V_10 += sizeof( * V_175 ) ;
}
memcpy ( V_10 , V_160 -> V_76 , V_160 -> V_143 ) ;
V_10 += V_160 -> V_143 ;
if ( V_164 & V_176 ) {
T_1 * V_177 = V_162 ;
if ( V_160 -> V_143 % 2 )
V_177 ++ ;
memcpy ( V_10 , V_177 , V_163 ) ;
V_10 += V_163 ;
}
F_86 ( V_22 ) ;
V_165 = F_87 ( V_10 - V_3 -> V_10 -> V_76 , 2 ) ;
F_31 = F_61 ( V_12 , V_3 , V_165 , NULL ,
V_133 , NULL , 0 , NULL ) ;
if ( F_31 ) {
F_88 ( V_22 ) ;
if ( F_89 () )
F_59 ( V_166 L_38 ,
V_22 -> V_167 , F_31 ) ;
goto V_174;
}
V_22 -> V_178 = V_52 ;
V_42 -> V_179 += V_160 -> V_143 ;
goto V_180;
V_172:
V_42 -> V_43 ++ ;
V_42 -> V_181 ++ ;
V_180:
F_90 ( V_40 , & V_31 ) ;
F_91 ( V_160 ) ;
return V_182 ;
V_174:
F_90 ( V_40 , & V_31 ) ;
return V_168 ;
}
static int F_92 ( struct V_129 * V_130 , T_3 V_87 , T_3 * V_183 )
{
* V_183 = V_37 ;
return 0 ;
}
static int F_93 ( struct V_39 * V_40 )
{
struct V_11 * V_12 = V_40 -> V_161 ;
int V_89 = F_55 ( V_12 , 1 ) ;
if ( V_89 < 0 ) {
F_31 ( L_39 ) ;
return V_89 ;
}
V_89 = F_55 ( V_12 , 0 ) ;
if ( V_89 < 0 ) {
F_31 ( L_40 ) ;
return V_89 ;
}
F_44 ( V_12 -> V_22 , L_41 ) ;
V_89 = F_56 ( V_12 -> V_15 ,
F_57 ( V_12 -> V_15 , 0 ) ,
V_184 ,
V_99 | V_100 |
V_101 , 0x0 , 0x0 , NULL , 0 ,
V_53 ) ;
if ( V_89 < 0 ) {
F_31 ( L_42 , V_89 ) ;
return V_89 ;
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
static int F_94 ( struct V_129 * V_130 )
{
struct V_11 * V_12 = V_130 -> V_40 ;
int V_89 ;
F_5 ( F_95 () ) ;
F_5 ( ! V_12 ) ;
V_12 -> V_66 = 0 ;
F_96 ( V_130 , V_185 , V_186 ) ;
F_96 ( V_130 , V_187 , V_146 ) ;
F_97 ( V_12 -> V_91 ) ;
F_53 ( V_12 ) ;
V_89 = F_66 ( V_130 , 0 , V_188 ,
F_52 ( 2 ) , L_43 ) ;
if ( V_89 < 0 ) {
F_59 (KERN_ERR PFX L_44 , retval) ;
return V_89 ;
}
V_89 = F_70 ( V_130 , V_189 , 0 , NULL ) ;
if ( V_89 < 0 ) {
F_59 (KERN_ERR PFX L_45 , retval) ;
return V_89 ;
}
return 0 ;
}
static void V_94 ( struct V_54 * V_54 )
{
struct V_11 * V_12 = (struct V_11 * ) V_54 -> V_56 ;
struct V_60 * V_61 = V_54 -> V_62 ;
T_3 V_77 ;
T_3 V_69 ;
if ( V_12 -> V_15 == NULL )
return;
if ( V_54 -> V_7 == - V_126 ) {
F_40 ( L_46 , V_70 ) ;
return;
}
if ( V_54 -> V_7 == - V_190 ) {
F_40 ( L_47 ,
V_70 ) ;
goto V_191;
}
if ( ( V_54 -> V_7 == - V_192 )
|| ( V_54 -> V_7 == - V_193 )
|| ( V_54 -> V_7 == - V_194 ) ) {
F_44 ( V_12 -> V_22 , L_48 ,
V_54 -> V_7 ) ;
return;
}
if ( V_54 -> V_7 )
F_44 ( V_12 -> V_22 , L_49 ,
V_54 -> V_7 , V_54 -> V_72 ) ;
if ( V_54 -> V_72 < sizeof( * V_61 ) ) {
F_31 ( L_50 , V_70 ) ;
goto V_191;
}
V_77 = F_49 ( V_61 ) ;
if ( F_43 ( V_61 -> V_77 ) != V_77 ) {
F_31 ( L_51 ) ;
goto V_191;
}
V_69 = F_43 ( V_61 -> V_69 ) ;
if ( ( V_69 != V_146 ) && ! F_72 ( V_69 ) ) {
F_41 ( V_12 , V_54 ) ;
} else if ( V_12 -> V_22 ) {
struct V_38 * V_22 = V_12 -> V_22 ;
struct V_39 * V_40 = F_29 ( V_22 ) ;
struct V_129 * V_130 = & V_40 -> V_130 ;
if ( V_69 == V_146 ) {
F_98 ( V_22 , V_130 ) ;
} else {
F_96 ( V_130 , V_195 ,
F_43 ( V_61 -> V_69 ) ) ;
F_99 ( V_22 , V_130 ) ;
}
}
V_191:
if ( V_12 -> V_15 )
F_53 ( V_12 ) ;
}
static inline void F_100 ( struct V_11 * V_12 )
{
struct V_38 * V_22 ;
struct V_63 * V_64 ;
struct V_63 * V_196 ;
unsigned long V_31 ;
F_5 ( F_95 () ) ;
F_5 ( ! V_12 ) ;
V_22 = V_12 -> V_22 ;
F_101 ( & V_12 -> V_197 ) ;
V_12 -> V_15 = NULL ;
F_97 ( V_12 -> V_91 ) ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
F_102 (item, tmp_item, &upriv->req_active) {
struct V_2 * V_3 ;
int F_31 ;
V_3 = F_33 ( V_64 , struct V_2 , V_33 ) ;
F_14 ( & V_3 -> V_4 ) ;
V_3 -> V_6 -> V_17 |= V_18 ;
F_31 = F_12 ( V_3 -> V_6 ) ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
if ( F_31 == - V_8 )
F_103 ( & V_3 -> V_5 ) ;
F_104 ( & V_3 -> V_9 ) ;
if ( ! F_32 ( & V_3 -> V_33 ) )
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
}
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_102 (item, tmp_item, &upriv->req_pending)
F_15 ( F_33 ( V_64 ,
struct V_2 , V_33 ) ) ;
if ( V_12 -> V_91 && V_12 -> V_91 -> V_7 == - V_8 )
F_59 (KERN_ERR PFX L_52 ) ;
F_105 ( & V_12 -> V_197 ) ;
if ( V_12 -> V_91 ) {
F_8 ( V_12 -> V_91 -> V_62 ) ;
F_7 ( V_12 -> V_91 ) ;
}
F_8 ( V_12 -> V_198 ) ;
if ( V_12 -> V_22 ) {
struct V_39 * V_40 = F_29 ( V_12 -> V_22 ) ;
F_106 ( V_40 ) ;
F_107 ( V_40 ) ;
}
}
static void F_108 ( T_8 * V_199 ,
unsigned long * V_31 ) __acquires( V_199 )
{
F_63 ( V_199 ) ;
}
static void F_109 ( T_8 * V_199 ,
unsigned long * V_31 ) __releases( V_199 )
{
F_64 ( V_199 ) ;
}
static void F_110 ( T_8 * V_199 ) __acquires( V_199 )
{
F_63 ( V_199 ) ;
}
static void F_111 ( T_8 * V_199 ) __releases( V_199 )
{
F_64 ( V_199 ) ;
}
static int F_112 ( struct V_200 * V_201 ,
const struct V_202 * V_144 )
{
struct V_203 * V_15 = F_113 ( V_201 ) ;
struct V_39 * V_40 ;
struct V_129 * V_130 ;
struct V_11 * V_12 = NULL ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
const struct V_208 * V_209 = NULL ;
int V_89 = 0 ;
int V_79 ;
V_40 = F_114 ( sizeof( * V_12 ) , & V_15 -> V_22 ,
F_93 , NULL ) ;
if ( ! V_40 ) {
F_31 ( L_53 ) ;
goto exit;
}
V_130 = & V_40 -> V_130 ;
V_12 = V_40 -> V_161 ;
F_115 ( & V_12 -> V_197 ) ;
F_116 ( & V_12 -> V_124 ) ;
F_116 ( & V_12 -> V_32 ) ;
F_117 ( & V_12 -> V_48 ) ;
F_117 ( & V_12 -> V_46 ) ;
V_12 -> V_15 = V_15 ;
V_130 -> V_210 = ( void V_211 V_212 * ) & V_12 -> V_213 ;
V_130 -> V_214 = V_215 ;
V_130 -> V_40 = V_12 ;
V_130 -> V_216 = & V_217 ;
V_205 = & V_201 -> V_218 [ 0 ] . V_219 ;
for ( V_79 = 0 ; V_79 < V_205 -> V_220 ; ++ V_79 ) {
V_207 = & V_201 -> V_218 [ 0 ] . V_221 [ V_79 ] . V_219 ;
if ( F_118 ( V_207 ) ) {
if ( V_12 -> V_91 != NULL ) {
F_40 ( L_54 ) ;
continue;
}
V_12 -> V_91 = F_19 ( 0 , V_109 ) ;
if ( ! V_12 -> V_91 ) {
F_31 ( L_55 ) ;
goto error;
}
if ( F_43 ( V_207 -> V_222 ) != 64 )
F_40 ( L_56 ) ;
if ( V_207 -> V_223 != ( 2 | V_224 ) )
F_40 ( L_57 ,
V_207 -> V_223 ) ;
V_12 -> V_93 = F_119 ( V_15 ,
V_207 ->
V_223 ) ;
V_12 -> V_91 -> V_62 =
F_18 ( V_27 , V_109 ) ;
if ( ! V_12 -> V_91 -> V_62 ) {
F_31 ( L_58 ) ;
goto error;
}
}
if ( F_120 ( V_207 ) ) {
if ( V_12 -> V_198 != NULL ) {
F_40 ( L_59 ) ;
continue;
}
if ( F_43 ( V_207 -> V_222 ) != 64 )
F_40 ( L_60 ) ;
if ( V_207 -> V_223 != 2 )
F_40 ( L_61 ,
V_207 -> V_223 ) ;
V_12 -> V_125 = F_121 ( V_15 ,
V_207 ->
V_223 ) ;
V_12 -> V_198 = F_18 ( V_27 , V_109 ) ;
if ( ! V_12 -> V_198 ) {
F_31 ( L_62 ) ;
goto error;
}
}
}
if ( ! V_12 -> V_198 || ! V_12 -> V_91 ) {
F_31 ( L_63 ) ;
goto error;
}
if ( F_122 ( & V_209 , L_64 ,
& V_201 -> V_22 ) == 0 ) {
V_208 . V_87 = V_209 -> V_87 ;
V_208 . V_112 = V_209 -> V_76 ;
}
if ( V_208 . V_87 && V_208 . V_112 ) {
if ( F_58 ( V_12 , & V_208 ) < 0 )
goto error;
} else {
F_31 ( L_65 ) ;
goto error;
}
if ( F_93 ( V_40 ) < 0 ) {
F_31 ( L_66 ) ;
goto error;
}
if ( F_94 ( V_130 ) < 0 ) {
F_31 ( L_67 ) ;
F_31 ( L_68 ) ;
goto error;
}
if ( F_123 ( V_40 ) != 0 ) {
F_31 ( L_69 ) ;
goto error;
}
if ( F_124 ( V_40 , 0 , 0 , & V_225 ) != 0 ) {
V_12 -> V_22 = NULL ;
F_31 ( L_70 , V_70 ) ;
goto error;
}
V_12 -> V_22 = V_40 -> V_226 ;
goto exit;
error:
F_100 ( V_12 ) ;
if ( V_12 -> V_22 ) {
F_107 ( V_40 ) ;
}
V_12 = NULL ;
V_89 = - V_97 ;
exit:
if ( V_209 ) {
V_208 . V_112 = NULL ;
V_208 . V_87 = 0 ;
F_125 ( V_209 ) ;
}
F_126 ( V_201 , V_12 ) ;
return V_89 ;
}
static void F_127 ( struct V_200 * V_227 )
{
struct V_11 * V_12 = F_128 ( V_227 ) ;
F_126 ( V_227 , NULL ) ;
F_100 ( V_12 ) ;
F_59 (KERN_INFO PFX L_71 ) ;
}
