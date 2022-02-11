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
T_1 V_94 = V_93 ;
if ( ! V_12 -> V_15 ) {
F_30 ( L_13 , V_68 ) ;
return - V_95 ;
}
return F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_96 ,
V_97 | V_98 |
V_99 , V_100 , 0 , & V_94 ,
sizeof( V_94 ) , V_51 ) ;
}
static int F_57 ( struct V_11 * V_12 ,
struct V_101 * V_102 )
{
T_1 * V_103 ;
int V_87 , V_104 ;
int V_105 ;
V_103 = F_18 ( V_106 , V_107 ) ;
if ( ! V_103 ) {
F_58 (KERN_ERR PFX L_14 ) ;
return - V_108 ;
}
V_105 = F_59 ( ( V_109 * ) & V_102 -> V_110 [ V_111 ] ) ;
if ( V_105 >= V_102 -> V_85 ) {
F_58 (KERN_ERR PFX L_15
L_16 , variant_offset) ;
V_87 = - V_112 ;
goto V_113;
}
V_87 = F_54 ( V_12 , 1 ) ;
if ( V_87 < 0 )
goto V_113;
for ( V_104 = 0 ; V_104 < V_102 -> V_85 ; V_104 += V_106 ) {
if ( ( V_104 >= V_114 ) && ( V_104 < V_115 ) )
continue;
memcpy ( V_103 , & V_102 -> V_110 [ V_104 ] , V_106 ) ;
if ( V_105 >= V_104 &&
V_105 < V_104 + V_106 ) {
F_43 ( V_12 -> V_22 ,
L_17 ,
V_105 ) ;
V_103 [ V_105 - V_104 ] = V_116 ;
}
V_87 = F_55 ( V_12 -> V_15 ,
F_56 ( V_12 -> V_15 , 0 ) ,
V_96 ,
V_97 | V_98
| V_99 ,
V_104 , 0x0 ,
V_103 , V_106 ,
V_51 ) ;
if ( V_87 < 0 )
goto V_113;
}
V_87 = F_54 ( V_12 , 0 ) ;
if ( V_87 < 0 )
goto V_113;
goto exit;
V_113:
F_58 (KERN_ERR PFX L_18 ,
retval) ;
exit:
F_8 ( V_103 ) ;
return V_87 ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_2 * V_3 ,
T_3 V_79 , const void * V_74 , T_3 V_81 ,
void * V_117 , unsigned V_118 , T_3 * V_119 )
{
int V_120 ;
int V_87 = 0 ;
enum V_53 V_19 ;
F_5 ( F_61 () ) ;
if ( ! V_12 -> V_15 ) {
V_87 = - V_121 ;
goto exit;
}
if ( V_12 -> V_89 -> V_7 != - V_8 )
F_30 ( L_19 , V_68 ) ;
F_62 ( & V_12 -> V_122 ) ;
V_120 = F_49 ( V_3 -> V_10 , V_79 , V_3 -> V_24 , V_74 ,
V_81 , V_12 -> V_64 ) ;
F_53 ( V_3 -> V_6 , V_12 -> V_15 , V_12 -> V_123 ,
V_3 -> V_10 , V_120 ,
F_37 , V_3 ) ;
if ( V_3 -> V_25 )
V_12 -> V_64 = F_1 ( V_12 -> V_64 ) ;
F_35 ( V_12 , V_3 ) ;
F_63 ( & V_12 -> V_122 ) ;
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
V_87 = - V_124 ;
} else {
F_58 (KERN_ERR PFX L_24 ) ;
V_87 = - V_95 ;
}
goto exit;
}
if ( V_3 -> V_25 ) {
struct V_58 * V_59 = V_3 -> V_10 ;
unsigned V_125 ;
if ( V_59 -> V_86 != 0 )
V_125 = F_42 ( V_59 -> V_86 ) * 2 + 12 ;
else
V_125 = 14 ;
if ( V_125 != V_3 -> V_69 ) {
F_30 ( L_25
L_26 , V_68 ,
V_3 -> V_25 , V_125 , V_3 -> V_69 ) ;
V_87 = - V_126 ;
goto exit;
}
if ( V_117 )
memcpy ( V_117 , V_59 -> V_74 , F_64 ( V_125 , V_118 ) ) ;
if ( V_119 )
* V_119 = F_42 ( V_59 -> V_86 ) ;
}
exit:
F_2 ( V_3 ) ;
return V_87 ;
}
static int F_65 ( struct V_127 * V_128 , int V_129 , T_3 V_80 ,
T_3 V_79 , const void * V_74 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
T_3 V_81 ;
struct V_2 * V_3 ;
if ( V_79 == 0 )
return - V_112 ;
V_79 = F_66 ( V_79 ) ;
if ( V_79 == 0 )
return 0 ;
V_3 = F_16 ( V_12 , V_80 , V_131 ) ;
if ( ! V_3 )
return - V_108 ;
if ( V_80 == V_37 )
V_81 = V_132 ;
else
V_81 = V_133 ;
return F_60 ( V_12 , V_3 , V_79 , V_74 , V_81 ,
NULL , 0 , NULL ) ;
}
static int F_67 ( struct V_127 * V_128 , int V_129 , T_3 V_80 ,
unsigned V_134 , T_3 * V_79 , void * V_10 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_2 * V_3 ;
if ( V_134 % 2 )
return - V_112 ;
V_3 = F_16 ( V_12 , V_80 , V_80 ) ;
if ( ! V_3 )
return - V_108 ;
return F_60 ( V_12 , V_3 , 0 , NULL , V_133 ,
V_10 , V_134 , V_79 ) ;
}
static int F_68 ( struct V_127 * V_128 , T_3 V_135 , T_3 V_136 , T_3 V_137 ,
T_3 V_138 , struct V_139 * V_140 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_2 * V_3 ;
T_4 V_74 [ 4 ] = {
F_50 ( V_135 ) ,
F_50 ( V_136 ) ,
F_50 ( V_137 ) ,
F_50 ( V_138 ) ,
} ;
F_43 ( V_12 -> V_22 ,
L_27 , V_135 ,
V_136 , V_137 , V_138 ) ;
V_3 = F_16 ( V_12 , V_141 , V_131 ) ;
if ( ! V_3 )
return - V_108 ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_133 , NULL , 0 , NULL ) ;
}
static int F_69 ( struct V_127 * V_128 , T_3 V_135 , T_3 V_136 ,
struct V_139 * V_140 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_2 * V_3 ;
T_4 V_74 [ 4 ] = {
F_50 ( V_135 ) ,
F_50 ( V_136 ) ,
0 ,
0 ,
} ;
F_43 ( V_12 -> V_22 , L_28 , V_135 , V_136 ) ;
V_3 = F_16 ( V_12 , V_141 , V_131 ) ;
if ( ! V_3 )
return - V_108 ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_133 , NULL , 0 , NULL ) ;
}
static int F_70 ( struct V_127 * V_128 , int V_129 ,
void * V_10 , int V_142 , T_3 V_143 , T_3 V_144 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_58 * V_59 = ( void * ) V_12 -> V_89 -> V_60 ;
int V_70 = V_12 -> V_89 -> V_70 ;
if ( V_143 == V_145 ) {
if ( ( sizeof( * V_59 ) + V_144 + V_142 ) > V_70 ) {
F_58 (KERN_ERR PFX L_29
L_30 ) ;
return - V_112 ;
}
memcpy ( V_10 , V_59 -> V_74 + V_144 , V_142 ) ;
return 0 ;
}
if ( F_71 ( V_143 ) ) {
if ( ( sizeof( * V_59 ) + V_144 + V_142 - 4 ) > V_70 ) {
F_58 (KERN_ERR PFX L_29
L_31 ) ;
return - V_95 ;
}
memcpy ( V_10 , V_59 -> V_74 + V_144 - 4 , V_142 ) ;
} else {
F_58 (KERN_ERR PFX L_32 , id) ;
return - V_112 ;
}
return 0 ;
}
static int F_72 ( struct V_127 * V_128 , T_4 * V_146 ,
T_5 V_147 , T_3 V_148 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_2 * V_3 ;
T_4 V_74 [] = {
F_50 ( V_147 & 0xffff ) ,
F_50 (pda_len - 4 )
} ;
V_3 = F_16 ( V_12 , V_149 , V_149 ) ;
if ( ! V_3 )
return - V_108 ;
V_146 [ 0 ] = F_50 ( V_148 - 2 ) ;
V_146 [ 1 ] = F_50 ( 0x0800 ) ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_133 , & V_146 [ 2 ] , V_148 - 4 ,
NULL ) ;
}
static int F_73 ( struct V_127 * V_128 , T_5 V_150 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_2 * V_3 ;
T_6 V_74 = F_74 ( V_150 ) ;
V_3 = F_16 ( V_12 , V_151 , V_131 ) ;
if ( ! V_3 )
return - V_108 ;
return F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_133 , NULL , 0 , NULL ) ;
}
static int F_75 ( struct V_127 * V_128 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_2 * V_3 ;
V_3 = F_16 ( V_12 , V_152 , V_131 ) ;
if ( ! V_3 )
return - V_108 ;
return F_60 ( V_12 , V_3 , 0 , NULL ,
V_133 , NULL , 0 , NULL ) ;
}
static int F_76 ( struct V_127 * V_128 , const char * V_10 ,
T_5 V_104 , T_5 V_142 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
struct V_2 * V_3 ;
T_6 V_74 = F_74 ( V_104 ) ;
int F_30 ;
V_3 = F_16 ( V_12 , V_153 , V_131 ) ;
if ( ! V_3 )
return - V_108 ;
F_30 = F_60 ( V_12 , V_3 , sizeof( V_74 ) , & V_74 ,
V_133 , NULL , 0 , NULL ) ;
if ( F_30 )
return F_30 ;
V_3 = F_16 ( V_12 , V_154 , V_131 ) ;
if ( ! V_3 )
return - V_108 ;
return F_60 ( V_12 , V_3 , V_142 , V_10 ,
V_133 , NULL , 0 , NULL ) ;
}
static int F_77 ( struct V_127 * V_128 , const char * V_10 ,
T_5 V_104 , T_5 V_142 )
{
T_5 V_155 ;
T_5 V_156 ;
int F_30 = 0 ;
V_156 = ( V_142 < V_157 ) ? V_142 : V_157 ;
V_155 = V_104 ;
while ( V_155 < ( V_104 + V_142 ) ) {
F_78 ( L_33
L_34 ,
V_156 , V_155 , & V_10 [ V_155 - V_104 ] ) ;
F_30 = F_76 ( V_128 , & V_10 [ V_155 - V_104 ] ,
V_155 , V_156 ) ;
if ( F_30 )
break;
V_155 += V_156 ;
V_156 = ( ( V_104 + V_142 - V_155 ) < V_157 ) ?
( V_104 + V_142 - V_155 ) : V_157 ;
}
return F_30 ;
}
static T_7 F_79 ( struct V_158 * V_159 , struct V_38 * V_22 )
{
struct V_160 * V_130 = F_80 ( V_22 ) ;
struct V_39 * V_40 = & V_22 -> V_40 ;
struct V_11 * V_12 = V_130 -> V_161 ;
T_1 V_162 [ V_163 + 1 ] ;
int F_30 = 0 ;
int V_164 ;
unsigned long V_31 ;
struct V_2 * V_3 ;
T_1 * V_10 ;
int V_165 ;
if ( ! F_81 ( V_22 ) ) {
F_58 ( V_166 L_35 ,
V_22 -> V_167 ) ;
return V_168 ;
}
if ( F_82 ( V_22 ) ) {
F_58 ( V_169 L_36 ,
V_22 -> V_167 ) ;
return V_168 ;
}
if ( F_83 ( V_130 , & V_31 ) != 0 ) {
F_58 ( V_166
L_37 ,
V_22 -> V_167 ) ;
return V_168 ;
}
if ( ! F_84 ( V_22 ) ||
( V_130 -> V_170 == V_171 ) ) {
goto V_172;
}
if ( V_159 -> V_142 < V_173 )
goto V_172;
V_3 = F_16 ( V_12 , V_37 , 0 ) ;
if ( ! V_3 )
goto V_174;
memset ( V_3 -> V_10 , 0 , V_27 ) ;
V_10 = V_3 -> V_10 -> V_74 ;
V_164 = 0 ;
F_30 = F_85 ( V_159 , V_22 , V_130 , & V_164 ,
& V_162 [ 0 ] ) ;
if ( F_30 )
goto V_172;
{
T_4 * V_175 = ( T_4 * ) V_10 ;
* V_175 = F_50 ( V_164 ) ;
V_10 += sizeof( * V_175 ) ;
}
memcpy ( V_10 , V_159 -> V_74 , V_159 -> V_142 ) ;
V_10 += V_159 -> V_142 ;
if ( V_164 & V_176 ) {
T_1 * V_177 = V_162 ;
if ( V_159 -> V_142 % 2 )
V_177 ++ ;
memcpy ( V_10 , V_177 , V_163 ) ;
V_10 += V_163 ;
}
F_86 ( V_22 ) ;
V_165 = F_87 ( V_10 - V_3 -> V_10 -> V_74 , 2 ) ;
F_30 = F_60 ( V_12 , V_3 , V_165 , NULL ,
V_132 , NULL , 0 , NULL ) ;
if ( F_30 ) {
F_88 ( V_22 ) ;
if ( F_89 () )
F_58 ( V_166 L_38 ,
V_22 -> V_167 , F_30 ) ;
goto V_174;
}
F_90 ( V_22 ) ;
V_40 -> V_178 += V_159 -> V_142 ;
goto V_179;
V_172:
V_40 -> V_41 ++ ;
V_40 -> V_180 ++ ;
V_179:
F_91 ( V_130 , & V_31 ) ;
F_92 ( V_159 ) ;
return V_181 ;
V_174:
F_91 ( V_130 , & V_31 ) ;
return V_168 ;
}
static int F_93 ( struct V_127 * V_128 , T_3 V_85 , T_3 * V_182 )
{
* V_182 = V_37 ;
return 0 ;
}
static int F_94 ( struct V_160 * V_130 )
{
struct V_11 * V_12 = V_130 -> V_161 ;
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
V_183 ,
V_97 | V_98 |
V_99 , 0x0 , 0x0 , NULL , 0 ,
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
static int F_95 ( struct V_127 * V_128 )
{
struct V_11 * V_12 = V_128 -> V_130 ;
int V_87 ;
F_5 ( F_96 () ) ;
F_5 ( ! V_12 ) ;
V_12 -> V_64 = 0 ;
F_97 ( V_128 , V_184 , V_185 ) ;
F_97 ( V_128 , V_186 , V_145 ) ;
F_98 ( V_12 -> V_89 ) ;
F_52 ( V_12 ) ;
V_87 = F_65 ( V_128 , 0 , V_187 ,
F_51 ( 2 ) , L_43 ) ;
if ( V_87 < 0 ) {
F_58 (KERN_ERR PFX L_44 , retval) ;
return V_87 ;
}
V_87 = F_69 ( V_128 , V_188 , 0 , NULL ) ;
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
if ( V_52 -> V_7 == - V_124 ) {
F_39 ( L_46 , V_68 ) ;
return;
}
if ( V_52 -> V_7 == - V_189 ) {
F_39 ( L_47 ,
V_68 ) ;
goto V_190;
}
if ( ( V_52 -> V_7 == - V_191 )
|| ( V_52 -> V_7 == - V_192 )
|| ( V_52 -> V_7 == - V_193 ) ) {
F_43 ( V_12 -> V_22 , L_48 ,
V_52 -> V_7 ) ;
return;
}
if ( V_52 -> V_7 )
F_43 ( V_12 -> V_22 , L_49 ,
V_52 -> V_7 , V_52 -> V_70 ) ;
if ( V_52 -> V_70 < sizeof( * V_59 ) ) {
F_30 ( L_50 , V_68 ) ;
goto V_190;
}
V_75 = F_48 ( V_59 ) ;
if ( F_42 ( V_59 -> V_75 ) != V_75 ) {
F_30 ( L_51 ) ;
goto V_190;
}
V_67 = F_42 ( V_59 -> V_67 ) ;
if ( ( V_67 != V_145 ) && ! F_71 ( V_67 ) ) {
F_40 ( V_12 , V_52 ) ;
} else if ( V_12 -> V_22 ) {
struct V_38 * V_22 = V_12 -> V_22 ;
struct V_160 * V_130 = F_80 ( V_22 ) ;
struct V_127 * V_128 = & V_130 -> V_128 ;
if ( V_67 == V_145 ) {
F_99 ( V_22 , V_128 ) ;
} else {
F_97 ( V_128 , V_194 ,
F_42 ( V_59 -> V_67 ) ) ;
F_100 ( V_22 , V_128 ) ;
}
}
V_190:
if ( V_12 -> V_15 )
F_52 ( V_12 ) ;
}
static inline void F_101 ( struct V_11 * V_12 )
{
struct V_38 * V_22 ;
struct V_61 * V_62 ;
struct V_61 * V_195 ;
unsigned long V_31 ;
F_5 ( F_96 () ) ;
F_5 ( ! V_12 ) ;
V_22 = V_12 -> V_22 ;
F_102 ( & V_12 -> V_196 ) ;
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
F_106 ( & V_12 -> V_196 ) ;
if ( V_12 -> V_89 ) {
F_8 ( V_12 -> V_89 -> V_60 ) ;
F_7 ( V_12 -> V_89 ) ;
}
F_8 ( V_12 -> V_197 ) ;
if ( V_12 -> V_22 ) {
struct V_160 * V_130 = F_80 ( V_12 -> V_22 ) ;
F_107 ( V_130 ) ;
F_108 ( F_109 ( V_12 ) ) ;
F_110 ( V_130 ) ;
}
}
static void F_111 ( T_8 * V_198 ,
unsigned long * V_31 ) __acquires( V_198 )
{
F_62 ( V_198 ) ;
}
static void F_112 ( T_8 * V_198 ,
unsigned long * V_31 ) __releases( V_198 )
{
F_63 ( V_198 ) ;
}
static void F_113 ( T_8 * V_198 ) __acquires( V_198 )
{
F_62 ( V_198 ) ;
}
static void F_114 ( T_8 * V_198 ) __releases( V_198 )
{
F_63 ( V_198 ) ;
}
static int F_115 ( struct V_199 * V_200 ,
const struct V_201 * V_143 )
{
struct V_202 * V_15 = F_116 ( V_200 ) ;
struct V_160 * V_130 ;
struct V_127 * V_128 ;
struct V_11 * V_12 = NULL ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
const struct V_207 * V_208 = NULL ;
int V_87 = 0 ;
int V_77 ;
V_130 = F_117 ( sizeof( * V_12 ) , & V_15 -> V_22 ,
F_94 , NULL ) ;
if ( ! V_130 ) {
F_30 ( L_53 ) ;
V_87 = - V_108 ;
goto exit;
}
V_128 = & V_130 -> V_128 ;
V_12 = V_130 -> V_161 ;
F_118 ( & V_12 -> V_196 ) ;
F_119 ( & V_12 -> V_122 ) ;
F_119 ( & V_12 -> V_32 ) ;
F_120 ( & V_12 -> V_46 ) ;
F_120 ( & V_12 -> V_44 ) ;
V_12 -> V_15 = V_15 ;
V_128 -> V_209 = ( void V_210 V_211 * ) & V_12 -> V_212 ;
V_128 -> V_213 = V_214 ;
V_128 -> V_130 = V_12 ;
V_128 -> V_215 = & V_216 ;
V_204 = & V_200 -> V_217 [ 0 ] . V_218 ;
for ( V_77 = 0 ; V_77 < V_204 -> V_219 ; ++ V_77 ) {
V_206 = & V_200 -> V_217 [ 0 ] . V_220 [ V_77 ] . V_218 ;
if ( F_121 ( V_206 ) ) {
if ( V_12 -> V_89 != NULL ) {
F_39 ( L_54 ) ;
continue;
}
V_12 -> V_89 = F_19 ( 0 , V_107 ) ;
if ( ! V_12 -> V_89 )
goto error;
if ( F_42 ( V_206 -> V_221 ) != 64 )
F_39 ( L_55 ) ;
if ( V_206 -> V_222 != ( 2 | V_223 ) )
F_39 ( L_56 ,
V_206 -> V_222 ) ;
V_12 -> V_91 = F_122 ( V_15 ,
V_206 ->
V_222 ) ;
V_12 -> V_89 -> V_60 =
F_18 ( V_27 , V_107 ) ;
if ( ! V_12 -> V_89 -> V_60 ) {
F_30 ( L_57 ) ;
goto error;
}
}
if ( F_123 ( V_206 ) ) {
if ( V_12 -> V_197 != NULL ) {
F_39 ( L_58 ) ;
continue;
}
if ( F_42 ( V_206 -> V_221 ) != 64 )
F_39 ( L_59 ) ;
if ( V_206 -> V_222 != 2 )
F_39 ( L_60 ,
V_206 -> V_222 ) ;
V_12 -> V_123 = F_124 ( V_15 ,
V_206 ->
V_222 ) ;
V_12 -> V_197 = F_18 ( V_27 , V_107 ) ;
if ( ! V_12 -> V_197 ) {
F_30 ( L_61 ) ;
goto error;
}
}
}
if ( ! V_12 -> V_197 || ! V_12 -> V_89 ) {
F_30 ( L_62 ) ;
goto error;
}
if ( F_125 ( & V_208 , L_63 ,
& V_200 -> V_22 ) == 0 ) {
V_207 . V_85 = V_208 -> V_85 ;
V_207 . V_110 = V_208 -> V_74 ;
}
if ( V_207 . V_85 && V_207 . V_110 ) {
if ( F_57 ( V_12 , & V_207 ) < 0 )
goto error;
} else {
F_30 ( L_64 ) ;
goto error;
}
if ( F_94 ( V_130 ) < 0 ) {
F_30 ( L_65 ) ;
goto error;
}
if ( F_95 ( V_128 ) < 0 ) {
F_30 ( L_66 ) ;
F_30 ( L_67 ) ;
goto error;
}
if ( F_126 ( V_130 ) != 0 ) {
F_30 ( L_68 ) ;
goto error;
}
if ( F_127 ( V_130 , 0 , 0 , & V_224 ) != 0 ) {
V_12 -> V_22 = NULL ;
F_30 ( L_69 , V_68 ) ;
F_108 ( F_109 ( V_130 ) ) ;
goto error;
}
V_12 -> V_22 = V_130 -> V_225 ;
goto exit;
error:
F_101 ( V_12 ) ;
if ( V_12 -> V_22 ) {
F_110 ( V_130 ) ;
}
V_12 = NULL ;
V_87 = - V_95 ;
exit:
if ( V_208 ) {
V_207 . V_110 = NULL ;
V_207 . V_85 = 0 ;
F_128 ( V_208 ) ;
}
F_129 ( V_200 , V_12 ) ;
return V_87 ;
}
static void F_130 ( struct V_199 * V_226 )
{
struct V_11 * V_12 = F_131 ( V_226 ) ;
F_129 ( V_226 , NULL ) ;
F_101 ( V_12 ) ;
F_58 (KERN_INFO PFX L_70 ) ;
}
