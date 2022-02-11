static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_2 -> V_5 ) ; V_4 ++ ) {
struct V_6 * V_7 = & V_2 -> V_5 [ V_4 ] ;
if ( V_7 -> V_8 ) {
F_3 ( V_7 -> V_8 , & V_7 -> V_9 ) ;
V_7 -> V_8 = NULL ;
}
}
F_4 ( & V_10 , V_3 ) ;
F_5 ( & V_2 -> V_11 ) ;
F_6 ( & V_10 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 , * V_15 ;
unsigned long V_3 ;
F_8 ( V_16 ) ;
F_9 ( V_17 , L_1 , V_2 , V_12 ) ;
F_4 ( & V_2 -> V_18 -> V_19 , V_3 ) ;
if ( V_2 -> V_12 ) {
F_6 ( & V_2 -> V_18 -> V_19 , V_3 ) ;
return;
}
V_2 -> V_12 = V_12 ;
F_10 (req, rtmp, &m->req_list, req_list) {
F_11 ( & V_14 -> V_20 , & V_16 ) ;
}
F_10 (req, rtmp, &m->unsent_req_list, req_list) {
F_11 ( & V_14 -> V_20 , & V_16 ) ;
}
F_6 ( & V_2 -> V_18 -> V_19 , V_3 ) ;
F_10 (req, rtmp, &cancel_list, req_list) {
F_9 ( V_17 , L_2 , V_14 ) ;
F_12 ( & V_14 -> V_20 ) ;
if ( ! V_14 -> V_21 )
V_14 -> V_21 = V_12 ;
F_13 ( V_2 -> V_18 , V_14 , V_22 ) ;
}
}
static int
F_14 ( struct V_23 * V_18 , struct V_24 * V_25 )
{
int V_26 , V_27 ;
struct V_28 * V_29 = NULL ;
if ( V_18 && V_18 -> V_30 == V_31 )
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return - V_33 ;
if ( ! V_29 -> V_34 -> V_35 -> V_36 )
return - V_37 ;
if ( ! V_29 -> V_38 -> V_35 -> V_36 )
return - V_37 ;
V_26 = V_29 -> V_34 -> V_35 -> V_36 ( V_29 -> V_34 , V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_29 -> V_34 != V_29 -> V_38 ) {
V_27 = V_29 -> V_38 -> V_35 -> V_36 ( V_29 -> V_38 , V_25 ) ;
if ( V_27 < 0 )
return V_27 ;
V_26 = ( V_26 & ~ V_39 ) | ( V_27 & ~ V_40 ) ;
}
return V_26 ;
}
static int F_15 ( struct V_23 * V_18 , void * V_41 , int V_42 )
{
int V_26 ;
struct V_28 * V_29 = NULL ;
if ( V_18 && V_18 -> V_30 != V_43 )
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return - V_33 ;
if ( ! ( V_29 -> V_34 -> V_44 & V_45 ) )
F_9 ( V_17 , L_3 ) ;
V_26 = F_16 ( V_29 -> V_34 , V_29 -> V_34 -> V_46 , V_41 , V_42 ) ;
if ( V_26 <= 0 && V_26 != - V_47 && V_26 != - V_48 )
V_18 -> V_30 = V_43 ;
return V_26 ;
}
static void F_17 ( struct V_49 * V_50 )
{
int V_27 , V_12 ;
struct V_1 * V_2 ;
int V_30 = V_22 ;
V_2 = F_18 ( V_50 , struct V_1 , V_51 ) ;
if ( V_2 -> V_12 < 0 )
return;
F_9 ( V_52 , L_4 , V_2 , V_2 -> V_53 ) ;
if ( ! V_2 -> V_54 ) {
V_2 -> V_54 = V_2 -> V_55 ;
V_2 -> V_53 = 0 ;
V_2 -> V_56 = 7 ;
}
F_19 ( V_57 , & V_2 -> V_58 ) ;
F_9 ( V_52 , L_5 ,
V_2 , V_2 -> V_53 , V_2 -> V_56 , V_2 -> V_56 - V_2 -> V_53 ) ;
V_12 = F_15 ( V_2 -> V_18 , V_2 -> V_54 + V_2 -> V_53 ,
V_2 -> V_56 - V_2 -> V_53 ) ;
F_9 ( V_52 , L_6 , V_2 , V_12 ) ;
if ( V_12 == - V_48 ) {
goto V_59;
}
if ( V_12 <= 0 )
goto error;
V_2 -> V_53 += V_12 ;
if ( ( ! V_2 -> V_14 ) && ( V_2 -> V_53 == V_2 -> V_56 ) ) {
T_1 V_60 ;
F_9 ( V_52 , L_7 ) ;
V_27 = F_20 ( * ( V_61 * ) V_2 -> V_54 ) ;
if ( V_27 >= V_2 -> V_18 -> V_62 ) {
F_9 ( V_17 ,
L_8 , V_27 ) ;
V_12 = - V_37 ;
goto error;
}
V_60 = F_21 ( * ( V_63 * ) ( V_2 -> V_54 + 5 ) ) ;
F_9 ( V_52 ,
L_9 , V_2 , V_27 , V_60 ) ;
V_2 -> V_14 = F_22 ( V_2 -> V_18 , V_60 ) ;
if ( ! V_2 -> V_14 || ( V_2 -> V_14 -> V_30 != V_64 ) ) {
F_9 ( V_17 , L_10 ,
V_60 ) ;
V_12 = - V_37 ;
goto error;
}
if ( V_2 -> V_14 -> V_65 == NULL ) {
V_2 -> V_14 -> V_65 = F_23 ( sizeof( struct V_66 ) +
V_2 -> V_18 -> V_62 , V_67 ) ;
if ( ! V_2 -> V_14 -> V_65 ) {
V_2 -> V_14 = NULL ;
V_12 = - V_68 ;
goto error;
}
}
V_2 -> V_54 = ( char * ) V_2 -> V_14 -> V_65 + sizeof( struct V_66 ) ;
memcpy ( V_2 -> V_54 , V_2 -> V_55 , V_2 -> V_56 ) ;
V_2 -> V_56 = V_27 ;
}
if ( ( V_2 -> V_14 ) && ( V_2 -> V_53 == V_2 -> V_56 ) ) {
F_9 ( V_52 , L_11 ) ;
F_24 ( & V_2 -> V_18 -> V_19 ) ;
if ( V_2 -> V_14 -> V_30 != V_22 )
V_30 = V_69 ;
F_12 ( & V_2 -> V_14 -> V_20 ) ;
F_25 ( & V_2 -> V_18 -> V_19 ) ;
F_13 ( V_2 -> V_18 , V_2 -> V_14 , V_30 ) ;
V_2 -> V_54 = NULL ;
V_2 -> V_53 = 0 ;
V_2 -> V_56 = 0 ;
V_2 -> V_14 = NULL ;
}
V_59:
F_19 ( V_70 , & V_2 -> V_58 ) ;
if ( ! F_26 ( & V_2 -> V_20 ) ) {
if ( F_27 ( V_57 , & V_2 -> V_58 ) )
V_27 = V_40 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_27 & V_40 ) && ! F_28 ( V_70 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_12 , V_2 ) ;
F_29 ( & V_2 -> V_51 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_70 , & V_2 -> V_58 ) ;
}
static int F_30 ( struct V_23 * V_18 , void * V_41 , int V_42 )
{
int V_26 ;
T_2 V_71 ;
struct V_28 * V_29 = NULL ;
if ( V_18 && V_18 -> V_30 != V_43 )
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return - V_33 ;
if ( ! ( V_29 -> V_38 -> V_44 & V_45 ) )
F_9 ( V_17 , L_13 ) ;
V_71 = F_31 () ;
F_32 ( F_33 () ) ;
V_26 = F_34 ( V_29 -> V_38 , ( V_72 void V_73 * ) V_41 , V_42 , & V_29 -> V_38 -> V_46 ) ;
F_32 ( V_71 ) ;
if ( V_26 <= 0 && V_26 != - V_47 && V_26 != - V_48 )
V_18 -> V_30 = V_43 ;
return V_26 ;
}
static void F_35 ( struct V_49 * V_50 )
{
int V_27 , V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_2 = F_18 ( V_50 , struct V_1 , V_74 ) ;
if ( V_2 -> V_12 < 0 ) {
F_19 ( V_75 , & V_2 -> V_58 ) ;
return;
}
if ( ! V_2 -> V_76 ) {
F_24 ( & V_2 -> V_18 -> V_19 ) ;
if ( F_26 ( & V_2 -> V_77 ) ) {
F_19 ( V_75 , & V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_18 -> V_19 ) ;
return;
}
V_14 = F_36 ( V_2 -> V_77 . V_78 , struct V_13 ,
V_20 ) ;
V_14 -> V_30 = V_64 ;
F_9 ( V_52 , L_14 , V_14 ) ;
F_37 ( & V_14 -> V_20 , & V_2 -> V_20 ) ;
V_2 -> V_79 = V_14 -> V_80 -> V_81 ;
V_2 -> V_76 = V_14 -> V_80 -> V_82 ;
V_2 -> V_83 = 0 ;
F_25 ( & V_2 -> V_18 -> V_19 ) ;
}
F_9 ( V_52 , L_15 ,
V_2 , V_2 -> V_83 , V_2 -> V_76 ) ;
F_19 ( V_84 , & V_2 -> V_58 ) ;
V_12 = F_30 ( V_2 -> V_18 , V_2 -> V_79 + V_2 -> V_83 , V_2 -> V_76 - V_2 -> V_83 ) ;
F_9 ( V_52 , L_16 , V_2 , V_12 ) ;
if ( V_12 == - V_48 )
goto V_59;
if ( V_12 < 0 )
goto error;
else if ( V_12 == 0 ) {
V_12 = - V_33 ;
goto error;
}
V_2 -> V_83 += V_12 ;
if ( V_2 -> V_83 == V_2 -> V_76 )
V_2 -> V_83 = V_2 -> V_76 = 0 ;
V_59:
F_19 ( V_75 , & V_2 -> V_58 ) ;
if ( V_2 -> V_76 || ! F_26 ( & V_2 -> V_77 ) ) {
if ( F_27 ( V_84 , & V_2 -> V_58 ) )
V_27 = V_39 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_27 & V_39 ) &&
! F_28 ( V_75 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_17 , V_2 ) ;
F_29 ( & V_2 -> V_74 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_75 , & V_2 -> V_58 ) ;
}
static int F_38 ( T_3 * V_9 , unsigned int V_85 , int V_86 , void * V_87 )
{
struct V_6 * V_7 =
F_18 ( V_9 , struct V_6 , V_9 ) ;
struct V_1 * V_2 = V_7 -> V_88 ;
unsigned long V_3 ;
F_4 ( & V_10 , V_3 ) ;
if ( F_26 ( & V_2 -> V_11 ) )
F_39 ( & V_2 -> V_11 , & V_89 ) ;
F_6 ( & V_10 , V_3 ) ;
F_29 ( & V_90 ) ;
return 1 ;
}
static void
F_40 ( struct V_91 * V_92 , T_4 * V_93 , T_5 * V_94 )
{
struct V_1 * V_2 = F_18 ( V_94 , struct V_1 , V_25 ) ;
struct V_6 * V_7 = NULL ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_2 -> V_5 ) ; V_4 ++ ) {
if ( V_2 -> V_5 [ V_4 ] . V_8 == NULL ) {
V_7 = & V_2 -> V_5 [ V_4 ] ;
break;
}
}
if ( ! V_7 ) {
F_9 ( V_17 , L_18 ) ;
return;
}
V_7 -> V_88 = V_2 ;
V_7 -> V_8 = V_93 ;
F_41 ( & V_7 -> V_9 , F_38 ) ;
F_42 ( V_93 , & V_7 -> V_9 ) ;
}
static void F_43 ( struct V_23 * V_18 )
{
int V_27 ;
struct V_28 * V_29 = V_18 -> V_32 ;
struct V_1 * V_2 = & V_29 -> V_88 ;
F_9 ( V_52 , L_19 , V_18 , V_18 -> V_62 ) ;
F_44 ( & V_2 -> V_95 ) ;
V_2 -> V_18 = V_18 ;
F_44 ( & V_2 -> V_20 ) ;
F_44 ( & V_2 -> V_77 ) ;
F_45 ( & V_2 -> V_51 , F_17 ) ;
F_45 ( & V_2 -> V_74 , F_35 ) ;
F_44 ( & V_2 -> V_11 ) ;
F_46 ( & V_2 -> V_25 , F_40 ) ;
V_27 = F_14 ( V_18 , & V_2 -> V_25 ) ;
if ( V_27 & V_40 ) {
F_9 ( V_52 , L_20 , V_2 ) ;
F_47 ( V_57 , & V_2 -> V_58 ) ;
}
if ( V_27 & V_39 ) {
F_9 ( V_52 , L_21 , V_2 ) ;
F_47 ( V_84 , & V_2 -> V_58 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
int V_27 ;
if ( V_2 -> V_12 < 0 )
return;
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_27 < 0 || V_27 & ( V_96 | V_97 | V_98 ) ) {
F_9 ( V_52 , L_22 , V_2 , V_27 ) ;
if ( V_27 >= 0 )
V_27 = - V_99 ;
F_7 ( V_2 , V_27 ) ;
}
if ( V_27 & V_40 ) {
F_47 ( V_57 , & V_2 -> V_58 ) ;
F_9 ( V_52 , L_20 , V_2 ) ;
if ( ! F_28 ( V_70 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_12 , V_2 ) ;
F_29 ( & V_2 -> V_51 ) ;
}
}
if ( V_27 & V_39 ) {
F_47 ( V_84 , & V_2 -> V_58 ) ;
F_9 ( V_52 , L_21 , V_2 ) ;
if ( ( V_2 -> V_76 || ! F_26 ( & V_2 -> V_77 ) ) &&
! F_28 ( V_75 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_17 , V_2 ) ;
F_29 ( & V_2 -> V_74 ) ;
}
}
}
static int F_49 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
int V_27 ;
struct V_28 * V_29 = V_18 -> V_32 ;
struct V_1 * V_2 = & V_29 -> V_88 ;
F_9 ( V_52 , L_23 ,
V_2 , V_100 , V_14 -> V_80 , V_14 -> V_80 -> V_101 ) ;
if ( V_2 -> V_12 < 0 )
return V_2 -> V_12 ;
F_24 ( & V_18 -> V_19 ) ;
V_14 -> V_30 = V_102 ;
F_39 ( & V_14 -> V_20 , & V_2 -> V_77 ) ;
F_25 ( & V_18 -> V_19 ) ;
if ( F_27 ( V_84 , & V_2 -> V_58 ) )
V_27 = V_39 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_27 & V_39 && ! F_28 ( V_75 , & V_2 -> V_58 ) )
F_29 ( & V_2 -> V_74 ) ;
return 0 ;
}
static int F_50 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
int V_26 = 1 ;
F_9 ( V_52 , L_24 , V_18 , V_14 ) ;
F_24 ( & V_18 -> V_19 ) ;
if ( V_14 -> V_30 == V_102 ) {
F_12 ( & V_14 -> V_20 ) ;
V_14 -> V_30 = V_103 ;
V_26 = 0 ;
}
F_25 ( & V_18 -> V_19 ) ;
return V_26 ;
}
static int F_51 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
F_9 ( V_52 , L_24 , V_18 , V_14 ) ;
F_24 ( & V_18 -> V_19 ) ;
F_12 ( & V_14 -> V_20 ) ;
F_25 ( & V_18 -> V_19 ) ;
return 0 ;
}
static int F_52 ( char * V_104 , struct V_105 * V_106 )
{
char * V_94 ;
T_6 args [ V_107 ] ;
int V_108 ;
char * V_109 , * V_110 ;
V_106 -> V_111 = V_112 ;
V_106 -> V_113 = ~ 0 ;
V_106 -> V_114 = ~ 0 ;
if ( ! V_104 )
return 0 ;
V_110 = F_53 ( V_104 , V_115 ) ;
if ( ! V_110 ) {
F_9 ( V_17 ,
L_25 ) ;
return - V_68 ;
}
V_109 = V_110 ;
while ( ( V_94 = F_54 ( & V_109 , L_26 ) ) != NULL ) {
int V_116 ;
int V_117 ;
if ( ! * V_94 )
continue;
V_116 = F_55 ( V_94 , V_118 , args ) ;
if ( ( V_116 != V_119 ) && ( V_116 != V_120 ) ) {
V_117 = F_56 ( & args [ 0 ] , & V_108 ) ;
if ( V_117 < 0 ) {
F_9 ( V_17 ,
L_27 ) ;
continue;
}
}
switch ( V_116 ) {
case V_121 :
V_106 -> V_111 = V_108 ;
break;
case V_122 :
V_106 -> V_113 = V_108 ;
break;
case V_123 :
V_106 -> V_114 = V_108 ;
break;
case V_120 :
V_106 -> V_124 = 1 ;
break;
default:
continue;
}
}
F_57 ( V_110 ) ;
return 0 ;
}
static int F_58 ( struct V_23 * V_18 , int V_113 , int V_114 )
{
struct V_28 * V_29 = F_59 ( sizeof( struct V_28 ) ,
V_115 ) ;
if ( ! V_29 )
return - V_68 ;
V_29 -> V_34 = F_60 ( V_113 ) ;
V_29 -> V_38 = F_60 ( V_114 ) ;
if ( ! V_29 -> V_34 || ! V_29 -> V_38 ) {
if ( V_29 -> V_34 )
F_61 ( V_29 -> V_34 ) ;
if ( V_29 -> V_38 )
F_61 ( V_29 -> V_38 ) ;
F_57 ( V_29 ) ;
return - V_37 ;
}
V_18 -> V_32 = V_29 ;
V_18 -> V_30 = V_31 ;
return 0 ;
}
static int F_62 ( struct V_23 * V_18 , struct V_125 * V_126 )
{
struct V_28 * V_94 ;
struct V_91 * V_91 ;
V_94 = F_59 ( sizeof( struct V_28 ) , V_115 ) ;
if ( ! V_94 )
return - V_68 ;
V_126 -> V_127 -> V_128 = V_129 ;
V_91 = F_63 ( V_126 , 0 , NULL ) ;
if ( F_64 ( V_91 ) ) {
F_65 ( L_28 ,
V_130 , F_66 ( V_100 ) ) ;
F_67 ( V_126 ) ;
F_57 ( V_94 ) ;
return F_68 ( V_91 ) ;
}
F_69 ( V_91 ) ;
V_94 -> V_38 = V_94 -> V_34 = V_91 ;
V_18 -> V_32 = V_94 ;
V_18 -> V_30 = V_31 ;
V_94 -> V_34 -> V_44 |= V_45 ;
F_43 ( V_18 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_9 ( V_52 , L_29 ,
V_2 , V_2 -> V_95 . V_131 , V_2 -> V_95 . V_78 ) ;
F_1 ( V_2 ) ;
F_71 ( & V_2 -> V_51 ) ;
F_71 ( & V_2 -> V_74 ) ;
F_7 ( V_2 , - V_99 ) ;
V_2 -> V_18 = NULL ;
}
static void F_72 ( struct V_23 * V_18 )
{
struct V_28 * V_29 ;
if ( ! V_18 )
return;
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return;
V_18 -> V_30 = V_43 ;
F_70 ( & V_29 -> V_88 ) ;
if ( V_29 -> V_34 )
F_61 ( V_29 -> V_34 ) ;
if ( V_29 -> V_38 )
F_61 ( V_29 -> V_38 ) ;
F_57 ( V_29 ) ;
}
static inline int F_73 ( const char * V_132 )
{
int V_65 , V_133 , V_134 [ 4 ] ;
V_65 = sscanf ( V_132 , L_30 , & V_134 [ 0 ] , & V_134 [ 1 ] , & V_134 [ 2 ] , & V_134 [ 3 ] ) ;
if ( V_65 != 4 )
return - V_135 ;
for ( V_133 = 0 ; V_133 < 4 ; V_133 ++ ) {
if ( V_134 [ V_133 ] > 255 )
return - V_135 ;
}
return 0 ;
}
static int F_74 ( struct V_125 * V_136 )
{
struct V_137 V_138 ;
int V_111 , V_12 = - V_135 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_139 = V_140 ;
V_138 . V_141 . V_142 = V_143 ;
for ( V_111 = V_144 ; V_111 >= V_145 ; V_111 -- ) {
V_138 . V_146 = F_75 ( ( V_147 ) V_111 ) ;
V_12 = F_76 ( V_136 , (struct V_148 * ) & V_138 , sizeof( V_138 ) ) ;
if ( V_12 != - V_149 )
break;
}
return V_12 ;
}
static int
F_77 ( struct V_23 * V_18 , const char * V_150 , char * args )
{
int V_12 ;
struct V_125 * V_126 ;
struct V_137 V_151 ;
struct V_105 V_106 ;
V_12 = F_52 ( args , & V_106 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_73 ( V_150 ) < 0 )
return - V_135 ;
V_126 = NULL ;
V_151 . V_139 = V_140 ;
V_151 . V_141 . V_142 = F_78 ( V_150 ) ;
V_151 . V_146 = F_75 ( V_106 . V_111 ) ;
V_12 = F_79 ( F_80 ( & V_100 -> V_152 -> V_153 ) , V_154 ,
V_155 , V_156 , & V_126 , 1 ) ;
if ( V_12 ) {
F_65 ( L_31 ,
V_130 , F_66 ( V_100 ) ) ;
return V_12 ;
}
if ( V_106 . V_124 ) {
V_12 = F_74 ( V_126 ) ;
if ( V_12 < 0 ) {
F_65 ( L_32 ,
V_130 , F_66 ( V_100 ) ) ;
F_67 ( V_126 ) ;
return V_12 ;
}
}
V_12 = V_126 -> V_157 -> V_158 ( V_126 ,
(struct V_148 * ) & V_151 ,
sizeof( struct V_137 ) , 0 ) ;
if ( V_12 < 0 ) {
F_65 ( L_33 ,
V_130 , F_66 ( V_100 ) , V_150 ) ;
F_67 ( V_126 ) ;
return V_12 ;
}
return F_62 ( V_18 , V_126 ) ;
}
static int
F_81 ( struct V_23 * V_18 , const char * V_150 , char * args )
{
int V_12 ;
struct V_125 * V_126 ;
struct V_159 V_160 ;
V_126 = NULL ;
if ( strlen ( V_150 ) >= V_161 ) {
F_65 ( L_34 ,
V_130 , F_66 ( V_100 ) , V_150 ) ;
return - V_162 ;
}
V_160 . V_163 = V_164 ;
strcpy ( V_160 . V_165 , V_150 ) ;
V_12 = F_79 ( F_80 ( & V_100 -> V_152 -> V_153 ) , V_164 ,
V_155 , 0 , & V_126 , 1 ) ;
if ( V_12 < 0 ) {
F_65 ( L_31 ,
V_130 , F_66 ( V_100 ) ) ;
return V_12 ;
}
V_12 = V_126 -> V_157 -> V_158 ( V_126 , (struct V_148 * ) & V_160 ,
sizeof( struct V_159 ) - 1 , 0 ) ;
if ( V_12 < 0 ) {
F_65 ( L_35 ,
V_130 , F_66 ( V_100 ) , V_150 , V_12 ) ;
F_67 ( V_126 ) ;
return V_12 ;
}
return F_62 ( V_18 , V_126 ) ;
}
static int
F_82 ( struct V_23 * V_18 , const char * V_150 , char * args )
{
int V_12 ;
struct V_105 V_106 ;
struct V_28 * V_94 ;
F_52 ( args , & V_106 ) ;
if ( V_106 . V_113 == ~ 0 || V_106 . V_114 == ~ 0 ) {
F_65 ( L_36 ) ;
return - V_166 ;
}
V_12 = F_58 ( V_18 , V_106 . V_113 , V_106 . V_114 ) ;
if ( V_12 < 0 )
return V_12 ;
V_94 = (struct V_28 * ) V_18 -> V_32 ;
F_43 ( V_18 ) ;
return 0 ;
}
static void F_83 ( struct V_49 * V_50 )
{
unsigned long V_3 ;
F_9 ( V_52 , L_37 , V_100 ) ;
F_4 ( & V_10 , V_3 ) ;
while ( ! F_26 ( & V_89 ) ) {
struct V_1 * V_88 = F_84 ( & V_89 ,
struct V_1 ,
V_11 ) ;
F_5 ( & V_88 -> V_11 ) ;
F_6 ( & V_10 , V_3 ) ;
F_48 ( V_88 ) ;
F_4 ( & V_10 , V_3 ) ;
}
F_6 ( & V_10 , V_3 ) ;
F_9 ( V_52 , L_38 ) ;
}
int F_85 ( void )
{
F_86 ( & V_167 ) ;
F_86 ( & V_168 ) ;
F_86 ( & V_169 ) ;
return 0 ;
}
void F_87 ( void )
{
F_88 ( & V_90 ) ;
F_89 ( & V_167 ) ;
F_89 ( & V_168 ) ;
F_89 ( & V_169 ) ;
}
