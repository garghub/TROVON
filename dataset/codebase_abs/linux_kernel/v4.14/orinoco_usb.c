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
struct V_39 * V_40 = & V_22 -> V_40 ;
if ( V_3 -> V_19 != V_34 )
V_40 -> V_41 ++ ;
else
V_40 -> V_42 ++ ;
F_29 ( V_22 ) ;
}
F_23 ( & V_3 -> V_5 ) ;
F_2 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
if ( ! V_12 -> V_15 ) {
F_30 ( L_2 ) ;
F_23 ( & V_3 -> V_5 ) ;
F_2 ( V_3 ) ;
break;
}
F_30 ( L_3 ) ;
break;
}
}
static void F_28 ( struct V_11 * V_12 )
{
unsigned long V_31 ;
struct V_2 * V_3 ;
int V_43 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
if ( ! F_31 ( & V_12 -> V_44 ) )
goto V_45;
if ( F_31 ( & V_12 -> V_46 ) )
goto V_45;
V_3 =
F_32 ( V_12 -> V_46 . V_47 , struct V_2 ,
V_33 ) ;
if ( ! V_3 -> V_12 -> V_15 )
goto V_45;
F_33 ( & V_3 -> V_33 , & V_12 -> V_44 ) ;
if ( V_3 -> V_19 == V_48 ) {
F_14 ( & V_3 -> V_4 ) ;
V_43 = F_34 ( V_3 -> V_6 , V_26 ) ;
if ( V_43 ) {
V_3 -> V_19 = V_35 ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_30 ( L_4
L_5 , V_43 ) ;
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
goto V_5;
}
V_3 -> V_19 = V_49 ;
F_9 ( V_3 -> V_12 , & V_3 -> V_9 ,
V_50 + V_51 ) ;
}
V_45:
F_27 ( & V_12 -> V_32 , V_31 ) ;
V_5:
return;
}
static void F_35 ( struct V_11 * V_12 ,
struct V_2 * V_3 )
{
unsigned long V_31 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
if ( ! V_3 -> V_12 -> V_15 ) {
F_27 ( & V_12 -> V_32 , V_31 ) ;
goto V_5;
}
F_14 ( & V_3 -> V_4 ) ;
F_36 ( & V_3 -> V_33 , & V_12 -> V_46 ) ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
V_3 -> V_19 = V_48 ;
F_28 ( V_12 ) ;
V_5:
return;
}
static void F_37 ( struct V_52 * V_52 )
{
unsigned long V_31 ;
enum V_53 V_19 ;
struct V_2 * V_3 = V_52 -> V_54 ;
struct V_11 * V_12 = V_3 -> V_12 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
F_38 ( & V_3 -> V_9 ) ;
if ( V_3 -> V_23 ) {
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_39 ( L_6 ) ;
goto V_55;
}
V_19 = V_3 -> V_19 ;
if ( V_52 -> V_7 == 0 ) {
switch ( V_19 ) {
case V_49 :
if ( V_3 -> V_25 ) {
V_3 -> V_19 = V_56 ;
F_9 ( V_12 , & V_3 -> V_9 ,
V_50 + V_51 ) ;
F_27 ( & V_12 -> V_32 ,
V_31 ) ;
break;
}
case V_57 :
V_3 -> V_19 = V_34 ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_30 ( L_7 ,
V_19 , V_52 -> V_7 ) ;
break;
}
} else {
switch ( V_19 ) {
case V_49 :
case V_57 :
V_3 -> V_19 = V_36 ;
case V_36 :
case V_20 :
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_30 ( L_7 ,
V_19 , V_52 -> V_7 ) ;
break;
}
}
V_55:
F_2 ( V_3 ) ;
}
static void F_40 ( struct V_11 * V_12 ,
struct V_52 * V_52 )
{
struct V_58 * V_59 = V_52 -> V_60 ;
struct V_2 * V_3 = NULL ;
enum V_53 V_19 ;
unsigned long V_31 ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
if ( V_12 -> V_15 ) {
struct V_61 * V_62 ;
F_41 (item, &upriv->req_active) {
struct V_2 * V_63 ;
int V_64 ;
V_63 = F_32 ( V_62 , struct V_2 , V_33 ) ;
V_64 =
F_1 ( V_63 -> V_10 -> V_65 ) ;
if ( ( V_59 -> V_66 == V_64 )
&& ( F_42 ( V_59 -> V_67 ) == V_63 -> V_25 ) ) {
V_3 = V_63 ;
break;
}
F_43 ( V_12 -> V_22 , L_8 ,
F_42 ( V_59 -> V_67 ) , V_63 -> V_25 ,
V_59 -> V_66 , V_64 ) ;
}
}
if ( V_3 == NULL ) {
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_30 ( L_9 , V_68 ,
F_42 ( V_59 -> V_67 ) ) ;
F_28 ( V_12 ) ;
return;
}
V_52 -> V_60 = V_3 -> V_10 ;
V_3 -> V_10 = ( void * ) V_59 ;
V_3 -> V_69 = V_52 -> V_70 ;
V_19 = V_3 -> V_19 ;
switch ( V_19 ) {
case V_49 :
V_3 -> V_19 = V_57 ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
break;
case V_56 :
V_3 -> V_19 = V_34 ;
F_38 ( & V_3 -> V_9 ) ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_15 ( V_3 ) ;
break;
default:
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_39 ( L_10 ,
V_19 ) ;
F_38 ( & V_3 -> V_9 ) ;
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
case V_48 :
case V_49 :
case V_56 :
case V_57 :
if ( F_45 () ) {
int V_71 = V_51 * ( 1000 / V_72 ) ;
while ( ! V_3 -> V_5 . V_5 && V_71 -- )
F_46 ( 1000 ) ;
} else {
F_47 ( V_3 -> V_5 . V_73 ,
V_3 -> V_5 . V_5 ) ;
}
break;
default:
break;
}
}
static inline T_3 F_48 ( struct V_58 * V_74 )
{
T_3 V_75 = 0 ;
T_1 * V_76 = ( T_1 * ) V_74 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ )
V_75 = ( V_75 << 1 ) + V_76 [ V_77 ] ;
return V_75 ;
}
static int F_49 ( struct V_58 * V_78 , T_3 V_79 , T_3 V_80 ,
const void * V_74 , T_3 V_81 , T_1 V_64 )
{
int V_82 = sizeof( * V_78 ) + V_79 ;
F_5 ( V_82 > V_27 ) ;
V_78 -> V_83 = F_50 ( V_84 ) ;
V_78 -> V_65 = V_64 ;
V_78 -> V_66 = 0 ;
V_78 -> V_81 = F_50 ( V_81 ) ;
V_78 -> V_85 = F_50 ( V_79 + 4 ) ;
V_78 -> V_75 = F_50 ( F_48 ( V_78 ) ) ;
V_78 -> V_86 = F_50 ( F_51 ( V_79 ) ) ;
V_78 -> V_67 = F_50 ( V_80 ) ;
if ( V_74 )
memcpy ( V_78 -> V_74 , V_74 , V_79 ) ;
return V_82 ;
}
static int F_52 ( struct V_11 * V_12 )
{
int V_87 = 0 ;
void * V_88 = V_12 -> V_89 -> V_60 ;
if ( V_12 -> V_89 -> V_7 == - V_8 ) {
F_43 ( V_12 -> V_22 , L_11 ) ;
V_87 = - V_90 ;
goto exit;
}
F_53 ( V_12 -> V_89 , V_12 -> V_15 , V_12 -> V_91 ,
V_88 , V_27 ,
V_92 , V_12 ) ;
V_12 -> V_89 -> V_17 = 0 ;
V_87 = F_34 ( V_12 -> V_89 , V_26 ) ;
if ( V_87 )
F_30 ( L_12 , V_68 , V_87 ) ;
exit:
return V_87 ;
}
static inline int F_54 ( struct V_11 * V_12 , int V_93 )
{
int V_94 ;
T_1 * V_95 = NULL ;
if ( ! V_12 -> V_15 ) {
F_30 ( L_13 , V_68 ) ;
return - V_96 ;
}
V_95 = F_18 ( sizeof( * V_95 ) , V_97 ) ;
if ( ! V_95 )
return - V_98 ;
* V_95 = V_93 ;
V_94 = F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_99 ,
V_100 | V_101 |
V_102 , V_103 , 0 , V_95 ,
sizeof( * V_95 ) , V_51 ) ;
F_8 ( V_95 ) ;
return V_94 ;
}
static int F_57 ( struct V_11 * V_12 ,
struct V_104 * V_105 )
{
T_1 * V_106 ;
int V_87 , V_107 ;
int V_108 ;
V_106 = F_18 ( V_109 , V_97 ) ;
if ( ! V_106 ) {
F_58 (KERN_ERR PFX L_14 ) ;
return - V_98 ;
}
V_108 = F_59 ( ( V_110 * ) & V_105 -> V_111 [ V_112 ] ) ;
if ( V_108 >= V_105 -> V_85 ) {
F_58 (KERN_ERR PFX L_15
L_16 , variant_offset) ;
V_87 = - V_113 ;
goto V_114;
}
V_87 = F_54 ( V_12 , 1 ) ;
if ( V_87 < 0 )
goto V_114;
for ( V_107 = 0 ; V_107 < V_105 -> V_85 ; V_107 += V_109 ) {
if ( ( V_107 >= V_115 ) && ( V_107 < V_116 ) )
continue;
memcpy ( V_106 , & V_105 -> V_111 [ V_107 ] , V_109 ) ;
if ( V_108 >= V_107 &&
V_108 < V_107 + V_109 ) {
F_43 ( V_12 -> V_22 ,
L_17 ,
V_108 ) ;
V_106 [ V_108 - V_107 ] = V_117 ;
}
V_87 = F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_99 ,
V_100 | V_101
| V_102 ,
V_107 , 0x0 ,
V_106 , V_109 ,
V_51 ) ;
if ( V_87 < 0 )
goto V_114;
}
V_87 = F_54 ( V_12 , 0 ) ;
if ( V_87 < 0 )
goto V_114;
goto exit;
V_114:
F_58 (KERN_ERR PFX L_18 ,
retval) ;
exit:
F_8 ( V_106 ) ;
return V_87 ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_2 * V_3 ,
T_3 V_79 , const void * V_74 , T_3 V_81 ,
void * V_118 , unsigned V_119 , T_3 * V_120 )
{
int V_121 ;
int V_87 = 0 ;
enum V_53 V_19 ;
F_5 ( F_61 () ) ;
if ( ! V_12 -> V_15 ) {
V_87 = - V_122 ;
goto exit;
}
if ( V_12 -> V_89 -> V_7 != - V_8 )
F_30 ( L_19 , V_68 ) ;
F_62 ( & V_12 -> V_123 ) ;
V_121 = F_49 ( V_3 -> V_10 , V_79 , V_3 -> V_24 , V_74 ,
V_81 , V_12 -> V_64 ) ;
F_53 ( V_3 -> V_6 , V_12 -> V_15 , V_12 -> V_124 ,
V_3 -> V_10 , V_121 ,
F_37 , V_3 ) ;
if ( V_3 -> V_25 )
V_12 -> V_64 = F_1 ( V_12 -> V_64 ) ;
F_35 ( V_12 , V_3 ) ;
F_63 ( & V_12 -> V_123 ) ;
if ( V_3 -> V_25 )
F_44 ( V_12 , V_3 ) ;
V_19 = V_3 -> V_19 ;
switch ( V_19 ) {
case V_34 :
V_87 = V_3 -> V_6 -> V_7 ;
break;
case V_48 :
case V_49 :
if ( ! V_3 -> V_25 )
break;
default:
F_30 ( L_20 , V_68 ,
V_19 ) ;
case V_20 :
case V_36 :
case V_21 :
case V_35 :
F_58 (KERN_ERR PFX L_21
L_22 , state, upriv->reply_count) ;
V_12 -> V_64 = 0 ;
if ( V_19 == V_20
|| V_19 == V_21 ) {
F_58 (KERN_ERR PFX L_23 ) ;
V_87 = - V_125 ;
} else {
F_58 (KERN_ERR PFX L_24 ) ;
V_87 = - V_96 ;
}
goto exit;
}
if ( V_3 -> V_25 ) {
struct V_58 * V_59 = V_3 -> V_10 ;
unsigned V_126 ;
if ( V_59 -> V_86 != 0 )
V_126 = F_42 ( V_59 -> V_86 ) * 2 + 12 ;
else
V_126 = 14 ;
if ( V_126 != V_3 -> V_69 ) {
F_30 ( L_25
L_26 , V_68 ,
V_3 -> V_25 , V_126 , V_3 -> V_69 ) ;
V_87 = - V_127 ;
goto exit;
}
if ( V_118 )
memcpy ( V_118 , V_59 -> V_74 , F_64 ( V_126 , V_119 ) ) ;
if ( V_120 )
* V_120 = F_42 ( V_59 -> V_86 ) ;
}
exit:
F_2 ( V_3 ) ;
return V_87 ;
}
static int F_65 ( struct V_128 * V_129 , int V_130 , T_3 V_80 ,
T_3 V_79 , const void * V_74 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
T_3 V_81 ;
struct V_2 * V_3 ;
if ( V_79 == 0 )
return - V_113 ;
V_79 = F_66 ( V_79 ) ;
if ( V_79 == 0 )
return 0 ;
V_3 = F_16 ( V_12 , V_80 , V_132 ) ;
if ( ! V_3 )
return - V_98 ;
if ( V_80 == V_37 )
V_81 = V_133 ;
else
V_81 = V_134 ;
return F_60 ( V_12 , V_3 , V_79 , V_74 , V_81 ,
NULL , 0 , NULL ) ;
}
static int F_67 ( struct V_128 * V_129 , int V_130 , T_3 V_80 ,
unsigned V_135 , T_3 * V_79 , void * V_10 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_2 * V_3 ;
if ( V_135 % 2 )
return - V_113 ;
V_3 = F_16 ( V_12 , V_80 , V_80 ) ;
if ( ! V_3 )
return - V_98 ;
return F_60 ( V_12 , V_3 , 0 , NULL , V_134 ,
V_10 , V_135 , V_79 ) ;
}
static int F_68 ( struct V_128 * V_129 , T_3 V_136 , T_3 V_137 , T_3 V_138 ,
T_3 V_139 , struct V_140 * V_141 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_2 * V_3 ;
T_4 V_74 [ 4 ] = {
F_50 ( V_136 ) ,
F_50 ( V_137 ) ,
F_50 ( V_138 ) ,
F_50 ( V_139 ) ,
} ;
F_43 ( V_12 -> V_22 ,
L_27 , V_136 ,
V_137 , V_138 , V_139 ) ;
V_3 = F_16 ( V_12 , V_142 , V_132 ) ;
if ( ! V_3 )
return - V_98 ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_69 ( struct V_128 * V_129 , T_3 V_136 , T_3 V_137 ,
struct V_140 * V_141 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_2 * V_3 ;
T_4 V_74 [ 4 ] = {
F_50 ( V_136 ) ,
F_50 ( V_137 ) ,
0 ,
0 ,
} ;
F_43 ( V_12 -> V_22 , L_28 , V_136 , V_137 ) ;
V_3 = F_16 ( V_12 , V_142 , V_132 ) ;
if ( ! V_3 )
return - V_98 ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_70 ( struct V_128 * V_129 , int V_130 ,
void * V_10 , int V_143 , T_3 V_144 , T_3 V_145 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_58 * V_59 = ( void * ) V_12 -> V_89 -> V_60 ;
int V_70 = V_12 -> V_89 -> V_70 ;
if ( V_144 == V_146 ) {
if ( ( sizeof( * V_59 ) + V_145 + V_143 ) > V_70 ) {
F_58 (KERN_ERR PFX L_29
L_30 ) ;
return - V_113 ;
}
memcpy ( V_10 , V_59 -> V_74 + V_145 , V_143 ) ;
return 0 ;
}
if ( F_71 ( V_144 ) ) {
if ( ( sizeof( * V_59 ) + V_145 + V_143 - 4 ) > V_70 ) {
F_58 (KERN_ERR PFX L_29
L_31 ) ;
return - V_96 ;
}
memcpy ( V_10 , V_59 -> V_74 + V_145 - 4 , V_143 ) ;
} else {
F_58 (KERN_ERR PFX L_32 , id) ;
return - V_113 ;
}
return 0 ;
}
static int F_72 ( struct V_128 * V_129 , T_4 * V_147 ,
T_5 V_148 , T_3 V_149 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_2 * V_3 ;
T_4 V_74 [] = {
F_50 ( V_148 & 0xffff ) ,
F_50 (pda_len - 4 )
} ;
V_3 = F_16 ( V_12 , V_150 , V_150 ) ;
if ( ! V_3 )
return - V_98 ;
V_147 [ 0 ] = F_50 ( V_149 - 2 ) ;
V_147 [ 1 ] = F_50 ( 0x0800 ) ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_134 , & V_147 [ 2 ] , V_149 - 4 ,
NULL ) ;
}
static int F_73 ( struct V_128 * V_129 , T_5 V_151 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_2 * V_3 ;
T_6 V_74 = F_74 ( V_151 ) ;
V_3 = F_16 ( V_12 , V_152 , V_132 ) ;
if ( ! V_3 )
return - V_98 ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_75 ( struct V_128 * V_129 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_2 * V_3 ;
V_3 = F_16 ( V_12 , V_153 , V_132 ) ;
if ( ! V_3 )
return - V_98 ;
return F_60 ( V_12 , V_3 , 0 , NULL ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_76 ( struct V_128 * V_129 , const char * V_10 ,
T_5 V_107 , T_5 V_143 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
struct V_2 * V_3 ;
T_6 V_74 = F_74 ( V_107 ) ;
int F_30 ;
V_3 = F_16 ( V_12 , V_154 , V_132 ) ;
if ( ! V_3 )
return - V_98 ;
F_30 = F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_134 , NULL , 0 , NULL ) ;
if ( F_30 )
return F_30 ;
V_3 = F_16 ( V_12 , V_155 , V_132 ) ;
if ( ! V_3 )
return - V_98 ;
return F_60 ( V_12 , V_3 , V_143 , V_10 ,
V_134 , NULL , 0 , NULL ) ;
}
static int F_77 ( struct V_128 * V_129 , const char * V_10 ,
T_5 V_107 , T_5 V_143 )
{
T_5 V_156 ;
T_5 V_157 ;
int F_30 = 0 ;
V_157 = ( V_143 < V_158 ) ? V_143 : V_158 ;
V_156 = V_107 ;
while ( V_156 < ( V_107 + V_143 ) ) {
F_78 ( L_33
L_34 ,
V_157 , V_156 , & V_10 [ V_156 - V_107 ] ) ;
F_30 = F_76 ( V_129 , & V_10 [ V_156 - V_107 ] ,
V_156 , V_157 ) ;
if ( F_30 )
break;
V_156 += V_157 ;
V_157 = ( ( V_107 + V_143 - V_156 ) < V_158 ) ?
( V_107 + V_143 - V_156 ) : V_158 ;
}
return F_30 ;
}
static T_7 F_79 ( struct V_159 * V_160 , struct V_38 * V_22 )
{
struct V_161 * V_131 = F_80 ( V_22 ) ;
struct V_39 * V_40 = & V_22 -> V_40 ;
struct V_11 * V_12 = V_131 -> V_162 ;
T_1 V_163 [ V_164 + 1 ] ;
int F_30 = 0 ;
int V_165 ;
unsigned long V_31 ;
struct V_2 * V_3 ;
T_1 * V_10 ;
int V_166 ;
if ( ! F_81 ( V_22 ) ) {
F_58 ( V_167 L_35 ,
V_22 -> V_168 ) ;
return V_169 ;
}
if ( F_82 ( V_22 ) ) {
F_58 ( V_170 L_36 ,
V_22 -> V_168 ) ;
return V_169 ;
}
if ( F_83 ( V_131 , & V_31 ) != 0 ) {
F_58 ( V_167
L_37 ,
V_22 -> V_168 ) ;
return V_169 ;
}
if ( ! F_84 ( V_22 ) ||
( V_131 -> V_171 == V_172 ) ) {
goto V_173;
}
if ( V_160 -> V_143 < V_174 )
goto V_173;
V_3 = F_16 ( V_12 , V_37 , 0 ) ;
if ( ! V_3 )
goto V_175;
memset ( V_3 -> V_10 , 0 , V_27 ) ;
V_10 = V_3 -> V_10 -> V_74 ;
V_165 = 0 ;
F_30 = F_85 ( V_160 , V_22 , V_131 , & V_165 ,
& V_163 [ 0 ] ) ;
if ( F_30 )
goto V_173;
{
T_4 * V_176 = ( T_4 * ) V_10 ;
* V_176 = F_50 ( V_165 ) ;
V_10 += sizeof( * V_176 ) ;
}
memcpy ( V_10 , V_160 -> V_74 , V_160 -> V_143 ) ;
V_10 += V_160 -> V_143 ;
if ( V_165 & V_177 ) {
T_1 * V_178 = V_163 ;
if ( V_160 -> V_143 % 2 )
V_178 ++ ;
memcpy ( V_10 , V_178 , V_164 ) ;
V_10 += V_164 ;
}
F_86 ( V_22 ) ;
V_166 = F_87 ( V_10 - V_3 -> V_10 -> V_74 , 2 ) ;
F_30 = F_60 ( V_12 , V_3 , V_166 , NULL ,
V_133 , NULL , 0 , NULL ) ;
if ( F_30 ) {
F_88 ( V_22 ) ;
if ( F_89 () )
F_58 ( V_167 L_38 ,
V_22 -> V_168 , F_30 ) ;
goto V_175;
}
F_90 ( V_22 ) ;
V_40 -> V_179 += V_160 -> V_143 ;
goto V_180;
V_173:
V_40 -> V_41 ++ ;
V_40 -> V_181 ++ ;
V_180:
F_91 ( V_131 , & V_31 ) ;
F_92 ( V_160 ) ;
return V_182 ;
V_175:
F_91 ( V_131 , & V_31 ) ;
return V_169 ;
}
static int F_93 ( struct V_128 * V_129 , T_3 V_85 , T_3 * V_183 )
{
* V_183 = V_37 ;
return 0 ;
}
static int F_94 ( struct V_161 * V_131 )
{
struct V_11 * V_12 = V_131 -> V_162 ;
int V_87 = F_54 ( V_12 , 1 ) ;
if ( V_87 < 0 ) {
F_30 ( L_39 ) ;
return V_87 ;
}
V_87 = F_54 ( V_12 , 0 ) ;
if ( V_87 < 0 ) {
F_30 ( L_40 ) ;
return V_87 ;
}
F_43 ( V_12 -> V_22 , L_41 ) ;
V_87 = F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_184 ,
V_100 | V_101 |
V_102 , 0x0 , 0x0 , NULL , 0 ,
V_51 ) ;
if ( V_87 < 0 ) {
F_30 ( L_42 , V_87 ) ;
return V_87 ;
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
static int F_95 ( struct V_128 * V_129 )
{
struct V_11 * V_12 = V_129 -> V_131 ;
int V_87 ;
F_5 ( F_96 () ) ;
F_5 ( ! V_12 ) ;
V_12 -> V_64 = 0 ;
F_97 ( V_129 , V_185 , V_186 ) ;
F_97 ( V_129 , V_187 , V_146 ) ;
F_98 ( V_12 -> V_89 ) ;
F_52 ( V_12 ) ;
V_87 = F_65 ( V_129 , 0 , V_188 ,
F_51 ( 2 ) , L_43 ) ;
if ( V_87 < 0 ) {
F_58 (KERN_ERR PFX L_44 , retval) ;
return V_87 ;
}
V_87 = F_69 ( V_129 , V_189 , 0 , NULL ) ;
if ( V_87 < 0 ) {
F_58 (KERN_ERR PFX L_45 , retval) ;
return V_87 ;
}
return 0 ;
}
static void V_92 ( struct V_52 * V_52 )
{
struct V_11 * V_12 = (struct V_11 * ) V_52 -> V_54 ;
struct V_58 * V_59 = V_52 -> V_60 ;
T_3 V_75 ;
T_3 V_67 ;
if ( V_12 -> V_15 == NULL )
return;
if ( V_52 -> V_7 == - V_125 ) {
F_39 ( L_46 , V_68 ) ;
return;
}
if ( V_52 -> V_7 == - V_190 ) {
F_39 ( L_47 ,
V_68 ) ;
goto V_191;
}
if ( ( V_52 -> V_7 == - V_192 )
|| ( V_52 -> V_7 == - V_193 )
|| ( V_52 -> V_7 == - V_194 ) ) {
F_43 ( V_12 -> V_22 , L_48 ,
V_52 -> V_7 ) ;
return;
}
if ( V_52 -> V_7 )
F_43 ( V_12 -> V_22 , L_49 ,
V_52 -> V_7 , V_52 -> V_70 ) ;
if ( V_52 -> V_70 < sizeof( * V_59 ) ) {
F_30 ( L_50 , V_68 ) ;
goto V_191;
}
V_75 = F_48 ( V_59 ) ;
if ( F_42 ( V_59 -> V_75 ) != V_75 ) {
F_30 ( L_51 ) ;
goto V_191;
}
V_67 = F_42 ( V_59 -> V_67 ) ;
if ( ( V_67 != V_146 ) && ! F_71 ( V_67 ) ) {
F_40 ( V_12 , V_52 ) ;
} else if ( V_12 -> V_22 ) {
struct V_38 * V_22 = V_12 -> V_22 ;
struct V_161 * V_131 = F_80 ( V_22 ) ;
struct V_128 * V_129 = & V_131 -> V_129 ;
if ( V_67 == V_146 ) {
F_99 ( V_22 , V_129 ) ;
} else {
F_97 ( V_129 , V_195 ,
F_42 ( V_59 -> V_67 ) ) ;
F_100 ( V_22 , V_129 ) ;
}
}
V_191:
if ( V_12 -> V_15 )
F_52 ( V_12 ) ;
}
static inline void F_101 ( struct V_11 * V_12 )
{
struct V_38 * V_22 ;
struct V_61 * V_62 ;
struct V_61 * V_196 ;
unsigned long V_31 ;
F_5 ( F_96 () ) ;
F_5 ( ! V_12 ) ;
V_22 = V_12 -> V_22 ;
F_102 ( & V_12 -> V_197 ) ;
V_12 -> V_15 = NULL ;
F_98 ( V_12 -> V_89 ) ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
F_103 (item, tmp_item, &upriv->req_active) {
struct V_2 * V_3 ;
int F_30 ;
V_3 = F_32 ( V_62 , struct V_2 , V_33 ) ;
F_14 ( & V_3 -> V_4 ) ;
V_3 -> V_6 -> V_17 |= V_18 ;
F_30 = F_12 ( V_3 -> V_6 ) ;
F_27 ( & V_12 -> V_32 , V_31 ) ;
if ( F_30 == - V_8 )
F_104 ( & V_3 -> V_5 ) ;
F_105 ( & V_3 -> V_9 ) ;
if ( ! F_31 ( & V_3 -> V_33 ) )
F_15 ( V_3 ) ;
F_2 ( V_3 ) ;
F_25 ( & V_12 -> V_32 , V_31 ) ;
}
F_27 ( & V_12 -> V_32 , V_31 ) ;
F_103 (item, tmp_item, &upriv->req_pending)
F_15 ( F_32 ( V_62 ,
struct V_2 , V_33 ) ) ;
if ( V_12 -> V_89 && V_12 -> V_89 -> V_7 == - V_8 )
F_58 (KERN_ERR PFX L_52 ) ;
F_106 ( & V_12 -> V_197 ) ;
if ( V_12 -> V_89 ) {
F_8 ( V_12 -> V_89 -> V_60 ) ;
F_7 ( V_12 -> V_89 ) ;
}
F_8 ( V_12 -> V_198 ) ;
if ( V_12 -> V_22 ) {
struct V_161 * V_131 = F_80 ( V_12 -> V_22 ) ;
F_107 ( V_131 ) ;
F_108 ( F_109 ( V_12 ) ) ;
F_110 ( V_131 ) ;
}
}
static void F_111 ( T_8 * V_199 ,
unsigned long * V_31 ) __acquires( V_199 )
{
F_62 ( V_199 ) ;
}
static void F_112 ( T_8 * V_199 ,
unsigned long * V_31 ) __releases( V_199 )
{
F_63 ( V_199 ) ;
}
static void F_113 ( T_8 * V_199 ) __acquires( V_199 )
{
F_62 ( V_199 ) ;
}
static void F_114 ( T_8 * V_199 ) __releases( V_199 )
{
F_63 ( V_199 ) ;
}
static int F_115 ( struct V_200 * V_201 ,
const struct V_202 * V_144 )
{
struct V_203 * V_15 = F_116 ( V_201 ) ;
struct V_161 * V_131 ;
struct V_128 * V_129 ;
struct V_11 * V_12 = NULL ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
const struct V_208 * V_209 = NULL ;
int V_87 = 0 ;
int V_77 ;
V_131 = F_117 ( sizeof( * V_12 ) , & V_15 -> V_22 ,
F_94 , NULL ) ;
if ( ! V_131 ) {
F_30 ( L_53 ) ;
V_87 = - V_98 ;
goto exit;
}
V_129 = & V_131 -> V_129 ;
V_12 = V_131 -> V_162 ;
F_118 ( & V_12 -> V_197 ) ;
F_119 ( & V_12 -> V_123 ) ;
F_119 ( & V_12 -> V_32 ) ;
F_120 ( & V_12 -> V_46 ) ;
F_120 ( & V_12 -> V_44 ) ;
V_12 -> V_15 = V_15 ;
V_129 -> V_210 = ( void V_211 V_212 * ) & V_12 -> V_213 ;
V_129 -> V_214 = V_215 ;
V_129 -> V_131 = V_12 ;
V_129 -> V_216 = & V_217 ;
V_205 = & V_201 -> V_218 [ 0 ] . V_219 ;
for ( V_77 = 0 ; V_77 < V_205 -> V_220 ; ++ V_77 ) {
V_207 = & V_201 -> V_218 [ 0 ] . V_221 [ V_77 ] . V_219 ;
if ( F_121 ( V_207 ) ) {
if ( V_12 -> V_89 != NULL ) {
F_39 ( L_54 ) ;
continue;
}
V_12 -> V_89 = F_19 ( 0 , V_97 ) ;
if ( ! V_12 -> V_89 )
goto error;
if ( F_42 ( V_207 -> V_222 ) != 64 )
F_39 ( L_55 ) ;
if ( V_207 -> V_223 != ( 2 | V_224 ) )
F_39 ( L_56 ,
V_207 -> V_223 ) ;
V_12 -> V_91 = F_122 ( V_15 ,
V_207 ->
V_223 ) ;
V_12 -> V_89 -> V_60 =
F_18 ( V_27 , V_97 ) ;
if ( ! V_12 -> V_89 -> V_60 ) {
F_30 ( L_57 ) ;
goto error;
}
}
if ( F_123 ( V_207 ) ) {
if ( V_12 -> V_198 != NULL ) {
F_39 ( L_58 ) ;
continue;
}
if ( F_42 ( V_207 -> V_222 ) != 64 )
F_39 ( L_59 ) ;
if ( V_207 -> V_223 != 2 )
F_39 ( L_60 ,
V_207 -> V_223 ) ;
V_12 -> V_124 = F_124 ( V_15 ,
V_207 ->
V_223 ) ;
V_12 -> V_198 = F_18 ( V_27 , V_97 ) ;
if ( ! V_12 -> V_198 ) {
F_30 ( L_61 ) ;
goto error;
}
}
}
if ( ! V_12 -> V_198 || ! V_12 -> V_89 ) {
F_30 ( L_62 ) ;
goto error;
}
if ( F_125 ( & V_209 , L_63 ,
& V_201 -> V_22 ) == 0 ) {
V_208 . V_85 = V_209 -> V_85 ;
V_208 . V_111 = V_209 -> V_74 ;
}
if ( V_208 . V_85 && V_208 . V_111 ) {
if ( F_57 ( V_12 , & V_208 ) < 0 )
goto error;
} else {
F_30 ( L_64 ) ;
goto error;
}
if ( F_94 ( V_131 ) < 0 ) {
F_30 ( L_65 ) ;
goto error;
}
if ( F_95 ( V_129 ) < 0 ) {
F_30 ( L_66 ) ;
F_30 ( L_67 ) ;
goto error;
}
if ( F_126 ( V_131 ) != 0 ) {
F_30 ( L_68 ) ;
goto error;
}
if ( F_127 ( V_131 , 0 , 0 , & V_225 ) != 0 ) {
V_12 -> V_22 = NULL ;
F_30 ( L_69 , V_68 ) ;
F_108 ( F_109 ( V_131 ) ) ;
goto error;
}
V_12 -> V_22 = V_131 -> V_226 ;
goto exit;
error:
F_101 ( V_12 ) ;
if ( V_12 -> V_22 ) {
F_110 ( V_131 ) ;
}
V_12 = NULL ;
V_87 = - V_96 ;
exit:
if ( V_209 ) {
V_208 . V_111 = NULL ;
V_208 . V_85 = 0 ;
F_128 ( V_209 ) ;
}
F_129 ( V_201 , V_12 ) ;
return V_87 ;
}
static void F_130 ( struct V_200 * V_227 )
{
struct V_11 * V_12 = F_131 ( V_227 ) ;
F_129 ( V_227 , NULL ) ;
F_101 ( V_12 ) ;
F_58 (KERN_INFO PFX L_70 ) ;
}
