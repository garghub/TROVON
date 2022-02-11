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
F_13 ( L_1 ) ;
F_14 ( & V_3 -> V_4 ) ;
V_3 -> V_22 = 1 ;
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
}
}
static struct V_2 * F_16 ( struct V_11 * V_12 ,
T_3 V_23 , T_3 V_24 )
{
struct V_2 * V_3 ;
V_3 = F_17 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_10 = F_18 ( V_26 , V_25 ) ;
if ( ! V_3 -> V_10 ) {
F_8 ( V_3 ) ;
return NULL ;
}
V_3 -> V_6 = F_19 ( 0 , V_25 ) ;
if ( ! V_3 -> V_6 ) {
F_8 ( V_3 -> V_10 ) ;
F_8 ( V_3 ) ;
return NULL ;
}
V_3 -> V_12 = V_12 ;
V_3 -> V_19 = V_27 ;
V_3 -> V_23 = V_23 ;
V_3 -> V_24 = V_24 ;
F_20 ( & V_3 -> V_4 , 1 ) ;
F_21 ( & V_3 -> V_5 ) ;
F_22 ( & V_3 -> V_9 ) ;
V_3 -> V_9 . V_28 = F_11 ;
V_3 -> V_9 . V_29 = ( T_2 ) V_3 ;
return V_3 ;
}
static inline void F_23 ( struct V_30 * V_31 )
{
F_24 ( V_31 ) ;
F_24 ( V_31 ) ;
F_24 ( V_31 ) ;
F_24 ( V_31 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_12 ;
unsigned long V_32 ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
F_26 ( & V_3 -> V_34 ) ;
if ( V_12 -> V_15 ) {
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_28 ( V_12 ) ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
}
switch ( V_3 -> V_19 ) {
case V_35 :
case V_36 :
case V_37 :
case V_20 :
case V_21 :
F_27 ( & V_12 -> V_33 , V_32 ) ;
if ( ( V_3 -> V_23 == V_38 ) && V_12 -> V_39 ) {
struct V_40 * V_39 = V_12 -> V_39 ;
struct V_41 * V_42 = F_29 ( V_39 ) ;
struct V_43 * V_44 = & V_42 -> V_44 ;
if ( V_3 -> V_19 != V_35 )
V_44 -> V_45 ++ ;
else
V_44 -> V_46 ++ ;
F_30 ( V_39 ) ;
}
F_23 ( & V_3 -> V_5 ) ;
F_2 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_33 , V_32 ) ;
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
unsigned long V_32 ;
struct V_2 * V_3 ;
int V_47 ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
if ( ! F_32 ( & V_12 -> V_48 ) )
goto V_49;
if ( F_32 ( & V_12 -> V_50 ) )
goto V_49;
V_3 =
F_33 ( V_12 -> V_50 . V_51 , struct V_2 ,
V_34 ) ;
if ( ! V_3 -> V_12 -> V_15 )
goto V_49;
F_34 ( & V_3 -> V_34 , & V_12 -> V_48 ) ;
if ( V_3 -> V_19 == V_52 ) {
F_14 ( & V_3 -> V_4 ) ;
V_47 = F_35 ( V_3 -> V_6 , V_25 ) ;
if ( V_47 ) {
V_3 -> V_19 = V_36 ;
F_27 ( & V_12 -> V_33 , V_32 ) ;
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
F_27 ( & V_12 -> V_33 , V_32 ) ;
V_5:
return;
}
static void F_36 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
unsigned long V_32 ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
if ( ! V_3 -> V_12 -> V_15 ) {
F_27 ( & V_12 -> V_33 , V_32 ) ;
goto V_5;
}
F_14 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_34 , & V_12 -> V_50 ) ;
F_27 ( & V_12 -> V_33 , V_32 ) ;
V_3 -> V_19 = V_52 ;
F_28 ( V_12 ) ;
V_5:
return;
}
static void F_38 ( struct V_56 * V_56 )
{
unsigned long V_32 ;
enum V_57 V_19 ;
struct V_2 * V_3 = V_56 -> V_58 ;
struct V_11 * V_12 = V_3 -> V_12 ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
F_39 ( & V_3 -> V_9 ) ;
if ( V_3 -> V_22 ) {
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_40 ( L_6 ) ;
goto V_59;
}
V_19 = V_3 -> V_19 ;
if ( V_56 -> V_7 == 0 ) {
switch ( V_19 ) {
case V_53 :
if ( V_3 -> V_24 ) {
V_3 -> V_19 = V_60 ;
F_9 ( V_12 , & V_3 -> V_9 ,
V_54 + V_55 ) ;
F_27 ( & V_12 -> V_33 ,
V_32 ) ;
break;
}
case V_61 :
V_3 -> V_19 = V_35 ;
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_31 ( L_7 ,
V_19 , V_56 -> V_7 ) ;
break;
}
} else {
switch ( V_19 ) {
case V_53 :
case V_61 :
V_3 -> V_19 = V_37 ;
case V_37 :
case V_20 :
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_33 , V_32 ) ;
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
unsigned long V_32 ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
if ( V_12 -> V_15 ) {
struct V_65 * V_66 ;
F_42 (item, &upriv->req_active) {
struct V_2 * V_67 ;
int V_68 ;
V_67 = F_33 ( V_66 , struct V_2 , V_34 ) ;
V_68 =
F_1 ( V_67 -> V_10 -> V_69 ) ;
if ( ( V_63 -> V_70 == V_68 )
&& ( F_43 ( V_63 -> V_71 ) == V_67 -> V_24 ) ) {
V_3 = V_67 ;
break;
}
F_13 ( L_8 ,
F_43 ( V_63 -> V_71 ) ,
V_67 -> V_24 , V_63 -> V_70 , V_68 ) ;
}
}
if ( V_3 == NULL ) {
F_27 ( & V_12 -> V_33 , V_32 ) ;
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
F_27 ( & V_12 -> V_33 , V_32 ) ;
break;
case V_60 :
V_3 -> V_19 = V_35 ;
F_39 ( & V_3 -> V_9 ) ;
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_40 ( L_10 ,
V_19 ) ;
F_39 ( & V_3 -> V_9 ) ;
V_3 -> V_6 -> V_17 |= V_18 ;
F_12 ( V_3 -> V_6 ) ;
F_28 ( V_12 ) ;
break;
}
}
static void F_44 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
switch ( V_3 -> V_19 ) {
case V_52 :
case V_53 :
case V_60 :
case V_61 :
if ( F_45 () ) {
int V_75 = V_55 * ( 1000 / V_76 ) ;
while ( ! V_3 -> V_5 . V_5 && V_75 -- )
F_46 ( 1000 ) ;
} else {
F_47 ( V_3 -> V_5 . V_77 ,
V_3 -> V_5 . V_5 ) ;
}
break;
default:
break;
}
}
static inline T_3 F_48 ( struct V_62 * V_29 )
{
T_3 V_78 = 0 ;
T_1 * V_79 = ( T_1 * ) V_29 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < 8 ; V_80 ++ )
V_78 = ( V_78 << 1 ) + V_79 [ V_80 ] ;
return V_78 ;
}
static int F_49 ( struct V_62 * V_81 , T_3 V_82 , T_3 V_83 ,
const void * V_29 , T_3 V_84 , T_1 V_68 )
{
int V_85 = sizeof( * V_81 ) + V_82 ;
F_5 ( V_85 > V_26 ) ;
V_81 -> V_86 = F_50 ( V_87 ) ;
V_81 -> V_69 = V_68 ;
V_81 -> V_70 = 0 ;
V_81 -> V_84 = F_50 ( V_84 ) ;
V_81 -> V_88 = F_50 ( V_82 + 4 ) ;
V_81 -> V_78 = F_50 ( F_48 ( V_81 ) ) ;
V_81 -> V_89 = F_50 ( F_51 ( V_82 ) ) ;
V_81 -> V_71 = F_50 ( V_83 ) ;
if ( V_29 )
memcpy ( V_81 -> V_29 , V_29 , V_82 ) ;
return V_85 ;
}
static int F_52 ( struct V_11 * V_12 )
{
int V_90 = 0 ;
void * V_91 = V_12 -> V_92 -> V_64 ;
if ( V_12 -> V_92 -> V_7 == - V_8 ) {
F_13 ( L_11 ) ;
V_90 = - V_93 ;
goto exit;
}
F_53 ( V_12 -> V_92 , V_12 -> V_15 , V_12 -> V_94 ,
V_91 , V_26 ,
V_95 , V_12 ) ;
V_12 -> V_92 -> V_17 = 0 ;
V_90 = F_35 ( V_12 -> V_92 , V_25 ) ;
if ( V_90 )
F_31 ( L_12 , V_72 , V_90 ) ;
exit:
return V_90 ;
}
static inline int F_54 ( struct V_11 * V_12 , int V_96 )
{
T_1 V_97 = V_96 ;
if ( ! V_12 -> V_15 ) {
F_31 ( L_13 , V_72 ) ;
return - V_98 ;
}
return F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_99 ,
V_100 | V_101 |
V_102 , V_103 , 0 , & V_97 ,
sizeof( V_97 ) , V_55 ) ;
}
static int F_57 ( struct V_11 * V_12 ,
struct V_104 * V_105 )
{
T_1 V_106 [ V_107 ] ;
int V_90 , V_108 ;
int V_109 ;
V_109 = F_58 ( ( V_110 * ) & V_105 -> V_111 [ V_112 ] ) ;
if ( V_109 >= V_105 -> V_88 ) {
F_59 (KERN_ERR PFX L_14
L_15 , variant_offset) ;
V_90 = - V_113 ;
goto V_114;
}
V_90 = F_54 ( V_12 , 1 ) ;
if ( V_90 < 0 )
goto V_114;
for ( V_108 = 0 ; V_108 < V_105 -> V_88 ; V_108 += V_107 ) {
if ( ( V_108 >= V_115 ) && ( V_108 < V_116 ) )
continue;
memcpy ( V_106 , & V_105 -> V_111 [ V_108 ] , V_107 ) ;
if ( V_109 >= V_108 &&
V_109 < V_108 + V_107 ) {
F_13 ( L_16 ,
V_109 ) ;
V_106 [ V_109 - V_108 ] = V_117 ;
}
V_90 = F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_99 ,
V_100 | V_101
| V_102 ,
V_108 , 0x0 ,
V_106 , V_107 ,
V_55 ) ;
if ( V_90 < 0 )
goto V_114;
}
V_90 = F_54 ( V_12 , 0 ) ;
if ( V_90 < 0 )
goto V_114;
goto exit;
V_114:
F_59 (KERN_ERR PFX L_17 ,
retval) ;
exit:
return V_90 ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_2 * V_3 ,
T_3 V_82 , const void * V_29 , T_3 V_84 ,
void * V_118 , int V_119 , T_3 * V_120 )
{
int V_121 ;
int V_90 = 0 ;
enum V_57 V_19 ;
F_5 ( F_61 () ) ;
if ( ! V_12 -> V_15 ) {
F_13 ( L_18 ) ;
return - V_122 ;
}
if ( V_12 -> V_92 -> V_7 != - V_8 )
F_31 ( L_19 , V_72 ) ;
F_62 ( & V_12 -> V_123 ) ;
V_121 = F_49 ( V_3 -> V_10 , V_82 , V_3 -> V_23 , V_29 ,
V_84 , V_12 -> V_68 ) ;
F_53 ( V_3 -> V_6 , V_12 -> V_15 , V_12 -> V_124 ,
V_3 -> V_10 , V_121 ,
F_38 , V_3 ) ;
if ( V_3 -> V_24 )
V_12 -> V_68 = F_1 ( V_12 -> V_68 ) ;
F_36 ( V_12 , V_3 ) ;
F_63 ( & V_12 -> V_123 ) ;
if ( V_3 -> V_24 )
F_44 ( V_12 , V_3 ) ;
V_19 = V_3 -> V_19 ;
switch ( V_19 ) {
case V_35 :
V_90 = V_3 -> V_6 -> V_7 ;
break;
case V_52 :
case V_53 :
if ( ! V_3 -> V_24 )
break;
default:
F_31 ( L_20 , V_72 ,
V_19 ) ;
case V_20 :
case V_37 :
case V_21 :
case V_36 :
F_59 (KERN_ERR PFX L_21
L_22 , state, upriv->reply_count) ;
V_12 -> V_68 = 0 ;
if ( V_19 == V_20
|| V_19 == V_21 ) {
F_59 (KERN_ERR PFX L_23 ) ;
V_90 = - V_125 ;
} else {
F_59 (KERN_ERR PFX L_24 ) ;
V_90 = - V_98 ;
}
goto exit;
break;
}
if ( V_3 -> V_24 ) {
struct V_62 * V_63 = V_3 -> V_10 ;
int V_126 ;
if ( V_63 -> V_89 != 0 )
V_126 = F_43 ( V_63 -> V_89 ) * 2 + 12 ;
else
V_126 = 14 ;
if ( V_126 != V_3 -> V_73 ) {
F_31 ( L_25
L_26 , V_72 ,
V_3 -> V_24 , V_126 , V_3 -> V_73 ) ;
V_90 = - V_127 ;
goto exit;
}
if ( V_118 )
memcpy ( V_118 , V_63 -> V_29 ,
F_64 ( int , V_126 , V_119 ) ) ;
if ( V_120 )
* V_120 = F_43 ( V_63 -> V_89 ) ;
}
exit:
F_2 ( V_3 ) ;
return V_90 ;
}
static int F_65 ( struct V_128 * V_129 , int V_130 , T_3 V_83 ,
T_3 V_82 , const void * V_29 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
T_3 V_84 ;
struct V_2 * V_3 ;
if ( V_82 == 0 )
return - V_113 ;
V_82 = F_66 ( V_82 ) ;
if ( V_82 == 0 )
return 0 ;
V_3 = F_16 ( V_12 , V_83 , V_131 ) ;
if ( ! V_3 )
return - V_132 ;
if ( V_83 == V_38 )
V_84 = V_133 ;
else
V_84 = V_134 ;
return F_60 ( V_12 , V_3 , V_82 , V_29 , V_84 ,
NULL , 0 , NULL ) ;
}
static int F_67 ( struct V_128 * V_129 , int V_130 , T_3 V_83 ,
unsigned V_135 , T_3 * V_82 , void * V_10 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_2 * V_3 ;
if ( ( V_135 < 0 ) || ( V_135 % 2 ) )
return - V_113 ;
V_3 = F_16 ( V_12 , V_83 , V_83 ) ;
if ( ! V_3 )
return - V_132 ;
return F_60 ( V_12 , V_3 , 0 , NULL , V_134 ,
V_10 , V_135 , V_82 ) ;
}
static int F_68 ( struct V_128 * V_129 , T_3 V_136 , T_3 V_137 , T_3 V_138 ,
T_3 V_139 , struct V_140 * V_141 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_2 * V_3 ;
T_4 V_29 [ 4 ] = {
F_50 ( V_136 ) ,
F_50 ( V_137 ) ,
F_50 ( V_138 ) ,
F_50 ( V_139 ) ,
} ;
F_13 ( L_27 ,
V_136 , V_137 , V_138 , V_139 ) ;
V_3 = F_16 ( V_12 , V_142 , V_131 ) ;
if ( ! V_3 )
return - V_132 ;
return F_60 ( V_12 , V_3 , sizeof( V_29 ) , & V_29 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_69 ( struct V_128 * V_129 , T_3 V_136 , T_3 V_137 ,
struct V_140 * V_141 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_2 * V_3 ;
T_4 V_29 [ 4 ] = {
F_50 ( V_136 ) ,
F_50 ( V_137 ) ,
0 ,
0 ,
} ;
F_13 ( L_28 , V_136 , V_137 ) ;
V_3 = F_16 ( V_12 , V_142 , V_131 ) ;
if ( ! V_3 )
return - V_132 ;
return F_60 ( V_12 , V_3 , sizeof( V_29 ) , & V_29 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_70 ( struct V_128 * V_129 , int V_130 ,
void * V_10 , int V_143 , T_3 V_144 , T_3 V_145 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_62 * V_63 = ( void * ) V_12 -> V_92 -> V_64 ;
int V_74 = V_12 -> V_92 -> V_74 ;
if ( V_144 == V_146 ) {
if ( ( sizeof( * V_63 ) + V_145 + V_143 ) > V_74 ) {
F_59 (KERN_ERR PFX L_29
L_30 ) ;
return - V_113 ;
}
memcpy ( V_10 , V_63 -> V_29 + V_145 , V_143 ) ;
return 0 ;
}
if ( F_71 ( V_144 ) ) {
if ( ( sizeof( * V_63 ) + V_145 + V_143 - 4 ) > V_74 ) {
F_59 (KERN_ERR PFX L_29
L_31 ) ;
return - V_98 ;
}
memcpy ( V_10 , V_63 -> V_29 + V_145 - 4 , V_143 ) ;
} else {
F_59 (KERN_ERR PFX L_32 , id) ;
return - V_113 ;
}
return 0 ;
}
static int F_72 ( struct V_128 * V_129 , T_4 * V_147 ,
T_5 V_148 , T_3 V_149 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_2 * V_3 ;
T_4 V_29 [] = {
F_50 ( V_148 & 0xffff ) ,
F_50 (pda_len - 4 )
} ;
V_3 = F_16 ( V_12 , V_150 , V_150 ) ;
if ( ! V_3 )
return - V_132 ;
V_147 [ 0 ] = F_50 ( V_149 - 2 ) ;
V_147 [ 1 ] = F_50 ( 0x0800 ) ;
return F_60 ( V_12 , V_3 , sizeof( V_29 ) , & V_29 ,
V_134 , & V_147 [ 2 ] , V_149 - 4 ,
NULL ) ;
}
static int F_73 ( struct V_128 * V_129 , T_5 V_151 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_2 * V_3 ;
T_6 V_29 = F_74 ( V_151 ) ;
V_3 = F_16 ( V_12 , V_152 , V_131 ) ;
if ( ! V_3 )
return - V_132 ;
return F_60 ( V_12 , V_3 , sizeof( V_29 ) , & V_29 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_75 ( struct V_128 * V_129 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_2 * V_3 ;
V_3 = F_16 ( V_12 , V_153 , V_131 ) ;
if ( ! V_3 )
return - V_132 ;
return F_60 ( V_12 , V_3 , 0 , NULL ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_76 ( struct V_128 * V_129 , const char * V_10 ,
T_5 V_108 , T_5 V_143 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
struct V_2 * V_3 ;
T_6 V_29 = F_74 ( V_108 ) ;
int F_31 ;
V_3 = F_16 ( V_12 , V_154 , V_131 ) ;
if ( ! V_3 )
return - V_132 ;
F_31 = F_60 ( V_12 , V_3 , sizeof( V_29 ) , & V_29 ,
V_134 , NULL , 0 , NULL ) ;
if ( F_31 )
return F_31 ;
V_3 = F_16 ( V_12 , V_155 , V_131 ) ;
if ( ! V_3 )
return - V_132 ;
return F_60 ( V_12 , V_3 , V_143 , V_10 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_77 ( struct V_128 * V_129 , const char * V_10 ,
T_5 V_108 , T_5 V_143 )
{
T_5 V_156 ;
T_5 V_157 ;
int F_31 = 0 ;
V_157 = ( V_143 < V_158 ) ? V_143 : V_158 ;
V_156 = V_108 ;
while ( V_156 < ( V_108 + V_143 ) ) {
F_78 ( L_33
L_34 ,
V_157 , V_156 , & V_10 [ V_156 - V_108 ] ) ;
F_31 = F_76 ( V_129 , & V_10 [ V_156 - V_108 ] ,
V_156 , V_157 ) ;
if ( F_31 )
break;
V_156 += V_157 ;
V_157 = ( ( V_108 + V_143 - V_156 ) < V_158 ) ?
( V_108 + V_143 - V_156 ) : V_158 ;
}
return F_31 ;
}
static T_7 F_79 ( struct V_159 * V_160 , struct V_40 * V_39 )
{
struct V_41 * V_42 = F_29 ( V_39 ) ;
struct V_43 * V_44 = & V_42 -> V_44 ;
struct V_11 * V_12 = V_42 -> V_161 ;
T_1 V_162 [ V_163 + 1 ] ;
int F_31 = 0 ;
int V_164 ;
unsigned long V_32 ;
struct V_2 * V_3 ;
T_1 * V_10 ;
int V_165 ;
if ( ! F_80 ( V_39 ) ) {
F_59 ( V_166 L_35 ,
V_39 -> V_167 ) ;
return V_168 ;
}
if ( F_81 ( V_39 ) ) {
F_59 ( V_169 L_36 ,
V_39 -> V_167 ) ;
return V_168 ;
}
if ( F_82 ( V_42 , & V_32 ) != 0 ) {
F_59 ( V_166
L_37 ,
V_39 -> V_167 ) ;
return V_168 ;
}
if ( ! F_83 ( V_39 ) ||
( V_42 -> V_170 == V_171 ) ) {
goto V_172;
}
if ( V_160 -> V_143 < V_173 )
goto V_172;
V_3 = F_16 ( V_12 , V_38 , 0 ) ;
if ( ! V_3 )
goto V_174;
memset ( V_3 -> V_10 , 0 , V_26 ) ;
V_10 = V_3 -> V_10 -> V_29 ;
V_164 = 0 ;
F_31 = F_84 ( V_160 , V_39 , V_42 , & V_164 ,
& V_162 [ 0 ] ) ;
if ( F_31 )
goto V_172;
{
T_4 * V_175 = ( T_4 * ) V_10 ;
* V_175 = F_50 ( V_164 ) ;
V_10 += sizeof( * V_175 ) ;
}
memcpy ( V_10 , V_160 -> V_29 , V_160 -> V_143 ) ;
V_10 += V_160 -> V_143 ;
if ( V_164 & V_176 ) {
T_1 * V_177 = V_162 ;
if ( V_160 -> V_143 % 2 )
V_177 ++ ;
memcpy ( V_10 , V_177 , V_163 ) ;
V_10 += V_163 ;
}
F_85 ( V_39 ) ;
V_165 = F_86 ( V_10 - V_3 -> V_10 -> V_29 , 2 ) ;
F_31 = F_60 ( V_12 , V_3 , V_165 , NULL ,
V_133 , NULL , 0 , NULL ) ;
if ( F_31 ) {
F_87 ( V_39 ) ;
if ( F_88 () )
F_59 ( V_166 L_38 ,
V_39 -> V_167 , F_31 ) ;
goto V_174;
}
V_39 -> V_178 = V_54 ;
V_44 -> V_179 += V_160 -> V_143 ;
goto V_180;
V_172:
V_44 -> V_45 ++ ;
V_44 -> V_181 ++ ;
V_180:
F_89 ( V_42 , & V_32 ) ;
F_90 ( V_160 ) ;
return V_182 ;
V_174:
F_89 ( V_42 , & V_32 ) ;
return V_168 ;
}
static int F_91 ( struct V_128 * V_129 , T_3 V_88 , T_3 * V_183 )
{
* V_183 = V_38 ;
return 0 ;
}
static int F_92 ( struct V_41 * V_42 )
{
struct V_11 * V_12 = V_42 -> V_161 ;
int V_90 = F_54 ( V_12 , 1 ) ;
if ( V_90 < 0 ) {
F_31 ( L_39 ) ;
return V_90 ;
}
V_90 = F_54 ( V_12 , 0 ) ;
if ( V_90 < 0 ) {
F_31 ( L_40 ) ;
return V_90 ;
}
F_13 ( L_41 ) ;
V_90 = F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_184 ,
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
static int F_93 ( struct V_128 * V_129 )
{
struct V_11 * V_12 = V_129 -> V_42 ;
int V_90 ;
F_5 ( F_94 () ) ;
F_5 ( ! V_12 ) ;
V_12 -> V_68 = 0 ;
F_95 ( V_129 , V_185 , V_186 ) ;
F_95 ( V_129 , V_187 , V_146 ) ;
F_96 ( V_12 -> V_92 ) ;
F_52 ( V_12 ) ;
V_90 = F_65 ( V_129 , 0 , V_188 ,
F_51 ( 2 ) , L_43 ) ;
if ( V_90 < 0 ) {
F_59 (KERN_ERR PFX L_44 , retval) ;
return V_90 ;
}
V_90 = F_69 ( V_129 , V_189 , 0 , NULL ) ;
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
if ( V_12 -> V_15 == NULL ) {
F_13 ( L_46 ) ;
return;
}
if ( V_56 -> V_7 == - V_125 ) {
F_40 ( L_47 , V_72 ) ;
return;
}
if ( V_56 -> V_7 == - V_190 ) {
F_40 ( L_48 ,
V_72 ) ;
goto V_191;
}
if ( ( V_56 -> V_7 == - V_192 )
|| ( V_56 -> V_7 == - V_193 )
|| ( V_56 -> V_7 == - V_194 ) ) {
F_13 ( L_49 , V_56 -> V_7 ) ;
return;
}
if ( V_56 -> V_7 )
F_13 ( L_50 ,
V_56 -> V_7 , V_56 -> V_74 ) ;
if ( V_56 -> V_74 < sizeof( * V_63 ) ) {
F_31 ( L_51 , V_72 ) ;
goto V_191;
}
V_78 = F_48 ( V_63 ) ;
if ( F_43 ( V_63 -> V_78 ) != V_78 ) {
F_31 ( L_52 ) ;
goto V_191;
}
V_71 = F_43 ( V_63 -> V_71 ) ;
if ( ( V_71 != V_146 ) && ! F_71 ( V_71 ) ) {
F_41 ( V_12 , V_56 ) ;
} else if ( V_12 -> V_39 ) {
struct V_40 * V_39 = V_12 -> V_39 ;
struct V_41 * V_42 = F_29 ( V_39 ) ;
struct V_128 * V_129 = & V_42 -> V_129 ;
if ( V_71 == V_146 ) {
F_97 ( V_39 , V_129 ) ;
} else {
F_95 ( V_129 , V_195 ,
F_43 ( V_63 -> V_71 ) ) ;
F_98 ( V_39 , V_129 ) ;
}
}
V_191:
if ( V_12 -> V_15 )
F_52 ( V_12 ) ;
}
static inline void F_99 ( struct V_11 * V_12 )
{
struct V_40 * V_39 ;
struct V_65 * V_66 ;
struct V_65 * V_196 ;
unsigned long V_32 ;
F_5 ( F_94 () ) ;
F_5 ( ! V_12 ) ;
V_39 = V_12 -> V_39 ;
F_100 ( & V_12 -> V_197 ) ;
V_12 -> V_15 = NULL ;
F_96 ( V_12 -> V_92 ) ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
F_101 (item, tmp_item, &upriv->req_active) {
struct V_2 * V_3 ;
int F_31 ;
V_3 = F_33 ( V_66 , struct V_2 , V_34 ) ;
F_14 ( & V_3 -> V_4 ) ;
V_3 -> V_6 -> V_17 |= V_18 ;
F_31 = F_12 ( V_3 -> V_6 ) ;
F_27 ( & V_12 -> V_33 , V_32 ) ;
if ( F_31 == - V_8 )
F_102 ( & V_3 -> V_5 ) ;
F_103 ( & V_3 -> V_9 ) ;
if ( ! F_32 ( & V_3 -> V_34 ) )
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
F_25 ( & V_12 -> V_33 , V_32 ) ;
}
F_27 ( & V_12 -> V_33 , V_32 ) ;
F_101 (item, tmp_item, &upriv->req_pending)
F_15 ( F_33 ( V_66 ,
struct V_2 , V_34 ) ) ;
if ( V_12 -> V_92 && V_12 -> V_92 -> V_7 == - V_8 )
F_59 (KERN_ERR PFX L_53 ) ;
F_104 ( & V_12 -> V_197 ) ;
if ( V_12 -> V_92 ) {
F_8 ( V_12 -> V_92 -> V_64 ) ;
F_7 ( V_12 -> V_92 ) ;
}
F_8 ( V_12 -> V_198 ) ;
if ( V_12 -> V_39 ) {
struct V_41 * V_42 = F_29 ( V_12 -> V_39 ) ;
F_105 ( V_42 ) ;
F_106 ( V_42 ) ;
}
}
static void F_107 ( T_8 * V_199 ,
unsigned long * V_32 ) __acquires( V_199 )
{
F_62 ( V_199 ) ;
}
static void F_108 ( T_8 * V_199 ,
unsigned long * V_32 ) __releases( V_199 )
{
F_63 ( V_199 ) ;
}
static void F_109 ( T_8 * V_199 ) __acquires( V_199 )
{
F_62 ( V_199 ) ;
}
static void F_110 ( T_8 * V_199 ) __releases( V_199 )
{
F_63 ( V_199 ) ;
}
static int F_111 ( struct V_200 * V_201 ,
const struct V_202 * V_144 )
{
struct V_203 * V_15 = F_112 ( V_201 ) ;
struct V_41 * V_42 ;
struct V_128 * V_129 ;
struct V_11 * V_12 = NULL ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
const struct V_208 * V_209 ;
int V_90 = 0 ;
int V_80 ;
V_42 = F_113 ( sizeof( * V_12 ) , & V_15 -> V_39 ,
F_92 , NULL ) ;
if ( ! V_42 ) {
F_31 ( L_54 ) ;
goto exit;
}
V_129 = & V_42 -> V_129 ;
V_12 = V_42 -> V_161 ;
F_114 ( & V_12 -> V_197 ) ;
F_115 ( & V_12 -> V_123 ) ;
F_115 ( & V_12 -> V_33 ) ;
F_116 ( & V_12 -> V_50 ) ;
F_116 ( & V_12 -> V_48 ) ;
V_12 -> V_15 = V_15 ;
V_129 -> V_210 = ( void V_211 V_212 * ) & V_12 -> V_213 ;
V_129 -> V_214 = V_215 ;
V_129 -> V_42 = V_12 ;
V_129 -> V_216 = & V_217 ;
V_205 = & V_201 -> V_218 [ 0 ] . V_219 ;
for ( V_80 = 0 ; V_80 < V_205 -> V_220 ; ++ V_80 ) {
V_207 = & V_201 -> V_218 [ 0 ] . V_221 [ V_80 ] . V_219 ;
if ( ( ( V_207 -> V_222 & V_223 )
== V_224 ) &&
( ( V_207 -> V_225 & V_226 )
== V_227 ) ) {
if ( V_12 -> V_92 != NULL ) {
F_40 ( L_55 ) ;
continue;
}
V_12 -> V_92 = F_19 ( 0 , V_228 ) ;
if ( ! V_12 -> V_92 ) {
F_31 ( L_56 ) ;
goto error;
}
if ( F_43 ( V_207 -> V_229 ) != 64 )
F_40 ( L_57 ) ;
if ( V_207 -> V_222 != ( 2 | V_224 ) )
F_40 ( L_58 ,
V_207 -> V_222 ) ;
V_12 -> V_94 = F_117 ( V_15 ,
V_207 ->
V_222 ) ;
V_12 -> V_92 -> V_64 =
F_18 ( V_26 , V_228 ) ;
if ( ! V_12 -> V_92 -> V_64 ) {
F_31 ( L_59 ) ;
goto error;
}
}
if ( ( ( V_207 -> V_222 & V_223 )
== V_102 ) &&
( ( V_207 -> V_225 & V_226 )
== V_227 ) ) {
if ( V_12 -> V_198 != NULL ) {
F_40 ( L_60 ) ;
continue;
}
if ( F_43 ( V_207 -> V_229 ) != 64 )
F_40 ( L_61 ) ;
if ( V_207 -> V_222 != 2 )
F_40 ( L_62 ,
V_207 -> V_222 ) ;
V_12 -> V_124 = F_118 ( V_15 ,
V_207 ->
V_222 ) ;
V_12 -> V_198 = F_18 ( V_26 , V_228 ) ;
if ( ! V_12 -> V_198 ) {
F_31 ( L_63 ) ;
goto error;
}
}
}
if ( ! V_12 -> V_198 || ! V_12 -> V_92 ) {
F_31 ( L_64 ) ;
goto error;
}
if ( F_119 ( & V_209 , L_65 ,
& V_201 -> V_39 ) == 0 ) {
V_208 . V_88 = V_209 -> V_88 ;
V_208 . V_111 = V_209 -> V_29 ;
}
if ( V_208 . V_88 && V_208 . V_111 ) {
F_57 ( V_12 , & V_208 ) ;
} else {
F_31 ( L_66 ) ;
goto error;
}
if ( F_92 ( V_42 ) < 0 ) {
F_31 ( L_67 ) ;
goto error;
}
if ( F_93 ( V_129 ) < 0 ) {
F_31 ( L_68 ) ;
F_31 ( L_69 ) ;
goto error;
}
if ( F_120 ( V_42 ) != 0 ) {
F_31 ( L_70 ) ;
goto error;
}
if ( F_121 ( V_42 , 0 , 0 , & V_230 ) != 0 ) {
V_12 -> V_39 = NULL ;
F_31 ( L_71 , V_72 ) ;
goto error;
}
V_12 -> V_39 = V_42 -> V_231 ;
goto exit;
error:
F_99 ( V_12 ) ;
if ( V_12 -> V_39 ) {
F_106 ( V_42 ) ;
}
V_12 = NULL ;
V_90 = - V_98 ;
exit:
if ( V_209 ) {
V_208 . V_111 = NULL ;
V_208 . V_88 = 0 ;
F_122 ( V_209 ) ;
}
F_123 ( V_201 , V_12 ) ;
return V_90 ;
}
static void F_124 ( struct V_200 * V_232 )
{
struct V_11 * V_12 = F_125 ( V_232 ) ;
F_123 ( V_232 , NULL ) ;
F_99 ( V_12 ) ;
F_59 (KERN_INFO PFX L_72 ) ;
}
static int T_9 F_126 ( void )
{
int F_31 ;
F_59 ( V_169 L_73 , V_233 ) ;
F_31 = F_127 ( & V_234 ) ;
if ( F_31 < 0 ) {
F_59 (KERN_ERR PFX L_74 ,
err) ;
return F_31 ;
}
return 0 ;
}
static void T_10 F_128 ( void )
{
F_129 ( & V_234 ) ;
}
