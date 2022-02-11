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
F_9 ( V_52 , L_4 , V_2 , V_2 -> V_53 . V_54 ) ;
if ( ! V_2 -> V_53 . V_55 ) {
V_2 -> V_53 . V_55 = V_2 -> V_56 ;
V_2 -> V_53 . V_54 = 0 ;
V_2 -> V_53 . V_57 = 7 ;
}
F_19 ( V_58 , & V_2 -> V_59 ) ;
F_9 ( V_52 , L_5 ,
V_2 , V_2 -> V_53 . V_54 , V_2 -> V_53 . V_57 ,
V_2 -> V_53 . V_57 - V_2 -> V_53 . V_54 ) ;
V_12 = F_15 ( V_2 -> V_18 , V_2 -> V_53 . V_55 + V_2 -> V_53 . V_54 ,
V_2 -> V_53 . V_57 - V_2 -> V_53 . V_54 ) ;
F_9 ( V_52 , L_6 , V_2 , V_12 ) ;
if ( V_12 == - V_48 )
goto V_60;
if ( V_12 <= 0 )
goto error;
V_2 -> V_53 . V_54 += V_12 ;
if ( ( ! V_2 -> V_14 ) && ( V_2 -> V_53 . V_54 == V_2 -> V_53 . V_57 ) ) {
F_9 ( V_52 , L_7 ) ;
V_12 = F_20 ( & V_2 -> V_53 , NULL , NULL , NULL , 0 ) ;
if ( V_12 ) {
F_9 ( V_17 ,
L_8 , V_12 ) ;
goto error;
}
if ( V_2 -> V_53 . V_61 >= V_2 -> V_18 -> V_62 ) {
F_9 ( V_17 ,
L_9 ,
V_2 -> V_53 . V_61 ) ;
V_12 = - V_37 ;
goto error;
}
F_9 ( V_52 ,
L_10 ,
V_2 , V_2 -> V_53 . V_61 , V_2 -> V_53 . V_63 ) ;
V_2 -> V_14 = F_21 ( V_2 -> V_18 , V_2 -> V_53 . V_63 ) ;
if ( ! V_2 -> V_14 || ( V_2 -> V_14 -> V_30 != V_64 ) ) {
F_9 ( V_17 , L_11 ,
V_2 -> V_53 . V_63 ) ;
V_12 = - V_37 ;
goto error;
}
if ( V_2 -> V_14 -> V_53 == NULL ) {
F_9 ( V_17 ,
L_12 ,
V_2 -> V_53 . V_63 , V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
V_12 = - V_37 ;
goto error;
}
V_2 -> V_53 . V_55 = ( char * ) V_2 -> V_14 -> V_53 + sizeof( struct V_65 ) ;
memcpy ( V_2 -> V_53 . V_55 , V_2 -> V_56 , V_2 -> V_53 . V_57 ) ;
V_2 -> V_53 . V_57 = V_2 -> V_53 . V_61 ;
}
if ( ( V_2 -> V_14 ) && ( V_2 -> V_53 . V_54 == V_2 -> V_53 . V_57 ) ) {
F_9 ( V_52 , L_13 ) ;
F_22 ( & V_2 -> V_18 -> V_19 ) ;
if ( V_2 -> V_14 -> V_30 != V_22 )
V_30 = V_66 ;
F_12 ( & V_2 -> V_14 -> V_20 ) ;
F_23 ( & V_2 -> V_18 -> V_19 ) ;
F_13 ( V_2 -> V_18 , V_2 -> V_14 , V_30 ) ;
V_2 -> V_53 . V_55 = NULL ;
V_2 -> V_53 . V_54 = 0 ;
V_2 -> V_53 . V_57 = 0 ;
V_2 -> V_14 = NULL ;
}
V_60:
F_19 ( V_67 , & V_2 -> V_59 ) ;
if ( ! F_24 ( & V_2 -> V_20 ) ) {
if ( F_25 ( V_58 , & V_2 -> V_59 ) )
V_27 = V_40 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_27 & V_40 ) && ! F_26 ( V_67 , & V_2 -> V_59 ) ) {
F_9 ( V_52 , L_14 , V_2 ) ;
F_27 ( & V_2 -> V_51 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_67 , & V_2 -> V_59 ) ;
}
static int F_28 ( struct V_23 * V_18 , void * V_41 , int V_42 )
{
int V_26 ;
T_1 V_68 ;
struct V_28 * V_29 = NULL ;
if ( V_18 && V_18 -> V_30 != V_43 )
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return - V_33 ;
if ( ! ( V_29 -> V_38 -> V_44 & V_45 ) )
F_9 ( V_17 , L_15 ) ;
V_68 = F_29 () ;
F_30 ( F_31 () ) ;
V_26 = F_32 ( V_29 -> V_38 , ( V_69 void V_70 * ) V_41 , V_42 , & V_29 -> V_38 -> V_46 ) ;
F_30 ( V_68 ) ;
if ( V_26 <= 0 && V_26 != - V_47 && V_26 != - V_48 )
V_18 -> V_30 = V_43 ;
return V_26 ;
}
static void F_33 ( struct V_49 * V_50 )
{
int V_27 , V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_2 = F_18 ( V_50 , struct V_1 , V_71 ) ;
if ( V_2 -> V_12 < 0 ) {
F_19 ( V_72 , & V_2 -> V_59 ) ;
return;
}
if ( ! V_2 -> V_73 ) {
F_22 ( & V_2 -> V_18 -> V_19 ) ;
if ( F_24 ( & V_2 -> V_74 ) ) {
F_19 ( V_72 , & V_2 -> V_59 ) ;
F_23 ( & V_2 -> V_18 -> V_19 ) ;
return;
}
V_14 = F_34 ( V_2 -> V_74 . V_75 , struct V_13 ,
V_20 ) ;
V_14 -> V_30 = V_64 ;
F_9 ( V_52 , L_16 , V_14 ) ;
F_35 ( & V_14 -> V_20 , & V_2 -> V_20 ) ;
V_2 -> V_76 = V_14 -> V_77 -> V_55 ;
V_2 -> V_73 = V_14 -> V_77 -> V_61 ;
V_2 -> V_78 = 0 ;
F_23 ( & V_2 -> V_18 -> V_19 ) ;
}
F_9 ( V_52 , L_17 ,
V_2 , V_2 -> V_78 , V_2 -> V_73 ) ;
F_19 ( V_79 , & V_2 -> V_59 ) ;
V_12 = F_28 ( V_2 -> V_18 , V_2 -> V_76 + V_2 -> V_78 , V_2 -> V_73 - V_2 -> V_78 ) ;
F_9 ( V_52 , L_18 , V_2 , V_12 ) ;
if ( V_12 == - V_48 )
goto V_60;
if ( V_12 < 0 )
goto error;
else if ( V_12 == 0 ) {
V_12 = - V_33 ;
goto error;
}
V_2 -> V_78 += V_12 ;
if ( V_2 -> V_78 == V_2 -> V_73 )
V_2 -> V_78 = V_2 -> V_73 = 0 ;
V_60:
F_19 ( V_72 , & V_2 -> V_59 ) ;
if ( V_2 -> V_73 || ! F_24 ( & V_2 -> V_74 ) ) {
if ( F_25 ( V_79 , & V_2 -> V_59 ) )
V_27 = V_39 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_27 & V_39 ) &&
! F_26 ( V_72 , & V_2 -> V_59 ) ) {
F_9 ( V_52 , L_19 , V_2 ) ;
F_27 ( & V_2 -> V_71 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_72 , & V_2 -> V_59 ) ;
}
static int F_36 ( T_2 * V_9 , unsigned int V_80 , int V_81 , void * V_82 )
{
struct V_6 * V_7 =
F_18 ( V_9 , struct V_6 , V_9 ) ;
struct V_1 * V_2 = V_7 -> V_83 ;
unsigned long V_3 ;
F_4 ( & V_10 , V_3 ) ;
if ( F_24 ( & V_2 -> V_11 ) )
F_37 ( & V_2 -> V_11 , & V_84 ) ;
F_6 ( & V_10 , V_3 ) ;
F_27 ( & V_85 ) ;
return 1 ;
}
static void
F_38 ( struct V_86 * V_87 , T_3 * V_88 , T_4 * V_89 )
{
struct V_1 * V_2 = F_18 ( V_89 , struct V_1 , V_25 ) ;
struct V_6 * V_7 = NULL ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_2 -> V_5 ) ; V_4 ++ ) {
if ( V_2 -> V_5 [ V_4 ] . V_8 == NULL ) {
V_7 = & V_2 -> V_5 [ V_4 ] ;
break;
}
}
if ( ! V_7 ) {
F_9 ( V_17 , L_20 ) ;
return;
}
V_7 -> V_83 = V_2 ;
V_7 -> V_8 = V_88 ;
F_39 ( & V_7 -> V_9 , F_36 ) ;
F_40 ( V_88 , & V_7 -> V_9 ) ;
}
static void F_41 ( struct V_23 * V_18 )
{
int V_27 ;
struct V_28 * V_29 = V_18 -> V_32 ;
struct V_1 * V_2 = & V_29 -> V_83 ;
F_9 ( V_52 , L_21 , V_18 , V_18 -> V_62 ) ;
F_42 ( & V_2 -> V_90 ) ;
V_2 -> V_18 = V_18 ;
F_42 ( & V_2 -> V_20 ) ;
F_42 ( & V_2 -> V_74 ) ;
F_43 ( & V_2 -> V_51 , F_17 ) ;
F_43 ( & V_2 -> V_71 , F_33 ) ;
F_42 ( & V_2 -> V_11 ) ;
F_44 ( & V_2 -> V_25 , F_38 ) ;
V_27 = F_14 ( V_18 , & V_2 -> V_25 ) ;
if ( V_27 & V_40 ) {
F_9 ( V_52 , L_22 , V_2 ) ;
F_45 ( V_58 , & V_2 -> V_59 ) ;
}
if ( V_27 & V_39 ) {
F_9 ( V_52 , L_23 , V_2 ) ;
F_45 ( V_79 , & V_2 -> V_59 ) ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
int V_27 ;
if ( V_2 -> V_12 < 0 )
return;
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_27 < 0 || V_27 & ( V_91 | V_92 | V_93 ) ) {
F_9 ( V_52 , L_24 , V_2 , V_27 ) ;
if ( V_27 >= 0 )
V_27 = - V_94 ;
F_7 ( V_2 , V_27 ) ;
}
if ( V_27 & V_40 ) {
F_45 ( V_58 , & V_2 -> V_59 ) ;
F_9 ( V_52 , L_22 , V_2 ) ;
if ( ! F_26 ( V_67 , & V_2 -> V_59 ) ) {
F_9 ( V_52 , L_14 , V_2 ) ;
F_27 ( & V_2 -> V_51 ) ;
}
}
if ( V_27 & V_39 ) {
F_45 ( V_79 , & V_2 -> V_59 ) ;
F_9 ( V_52 , L_23 , V_2 ) ;
if ( ( V_2 -> V_73 || ! F_24 ( & V_2 -> V_74 ) ) &&
! F_26 ( V_72 , & V_2 -> V_59 ) ) {
F_9 ( V_52 , L_19 , V_2 ) ;
F_27 ( & V_2 -> V_71 ) ;
}
}
}
static int F_47 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
int V_27 ;
struct V_28 * V_29 = V_18 -> V_32 ;
struct V_1 * V_2 = & V_29 -> V_83 ;
F_9 ( V_52 , L_25 ,
V_2 , V_95 , V_14 -> V_77 , V_14 -> V_77 -> V_96 ) ;
if ( V_2 -> V_12 < 0 )
return V_2 -> V_12 ;
F_22 ( & V_18 -> V_19 ) ;
V_14 -> V_30 = V_97 ;
F_37 ( & V_14 -> V_20 , & V_2 -> V_74 ) ;
F_23 ( & V_18 -> V_19 ) ;
if ( F_25 ( V_79 , & V_2 -> V_59 ) )
V_27 = V_39 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_27 & V_39 && ! F_26 ( V_72 , & V_2 -> V_59 ) )
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_48 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
int V_26 = 1 ;
F_9 ( V_52 , L_26 , V_18 , V_14 ) ;
F_22 ( & V_18 -> V_19 ) ;
if ( V_14 -> V_30 == V_97 ) {
F_12 ( & V_14 -> V_20 ) ;
V_14 -> V_30 = V_98 ;
V_26 = 0 ;
}
F_23 ( & V_18 -> V_19 ) ;
return V_26 ;
}
static int F_49 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
F_9 ( V_52 , L_26 , V_18 , V_14 ) ;
F_22 ( & V_18 -> V_19 ) ;
F_12 ( & V_14 -> V_20 ) ;
F_23 ( & V_18 -> V_19 ) ;
return 0 ;
}
static int F_50 ( char * V_99 , struct V_100 * V_101 )
{
char * V_89 ;
T_5 args [ V_102 ] ;
int V_103 ;
char * V_104 , * V_105 ;
V_101 -> V_106 = V_107 ;
V_101 -> V_108 = ~ 0 ;
V_101 -> V_109 = ~ 0 ;
V_101 -> V_110 = 0 ;
if ( ! V_99 )
return 0 ;
V_105 = F_51 ( V_99 , V_111 ) ;
if ( ! V_105 ) {
F_9 ( V_17 ,
L_27 ) ;
return - V_112 ;
}
V_104 = V_105 ;
while ( ( V_89 = F_52 ( & V_104 , L_28 ) ) != NULL ) {
int V_113 ;
int V_114 ;
if ( ! * V_89 )
continue;
V_113 = F_53 ( V_89 , V_115 , args ) ;
if ( ( V_113 != V_116 ) && ( V_113 != V_117 ) ) {
V_114 = F_54 ( & args [ 0 ] , & V_103 ) ;
if ( V_114 < 0 ) {
F_9 ( V_17 ,
L_29 ) ;
continue;
}
}
switch ( V_113 ) {
case V_118 :
V_101 -> V_106 = V_103 ;
break;
case V_119 :
V_101 -> V_108 = V_103 ;
break;
case V_120 :
V_101 -> V_109 = V_103 ;
break;
case V_117 :
V_101 -> V_110 = 1 ;
break;
default:
continue;
}
}
F_55 ( V_105 ) ;
return 0 ;
}
static int F_56 ( struct V_23 * V_18 , int V_108 , int V_109 )
{
struct V_28 * V_29 = F_57 ( sizeof( struct V_28 ) ,
V_111 ) ;
if ( ! V_29 )
return - V_112 ;
V_29 -> V_34 = F_58 ( V_108 ) ;
V_29 -> V_38 = F_58 ( V_109 ) ;
if ( ! V_29 -> V_34 || ! V_29 -> V_38 ) {
if ( V_29 -> V_34 )
F_59 ( V_29 -> V_34 ) ;
if ( V_29 -> V_38 )
F_59 ( V_29 -> V_38 ) ;
F_55 ( V_29 ) ;
return - V_37 ;
}
V_18 -> V_32 = V_29 ;
V_18 -> V_30 = V_31 ;
return 0 ;
}
static int F_60 ( struct V_23 * V_18 , struct V_121 * V_122 )
{
struct V_28 * V_89 ;
struct V_86 * V_86 ;
V_89 = F_57 ( sizeof( struct V_28 ) , V_111 ) ;
if ( ! V_89 )
return - V_112 ;
V_122 -> V_123 -> V_124 = V_125 ;
V_86 = F_61 ( V_122 , 0 , NULL ) ;
if ( F_62 ( V_86 ) ) {
F_63 ( L_30 ,
V_126 , F_64 ( V_95 ) ) ;
F_65 ( V_122 ) ;
F_55 ( V_89 ) ;
return F_66 ( V_86 ) ;
}
F_67 ( V_86 ) ;
V_89 -> V_38 = V_89 -> V_34 = V_86 ;
V_18 -> V_32 = V_89 ;
V_18 -> V_30 = V_31 ;
V_89 -> V_34 -> V_44 |= V_45 ;
F_41 ( V_18 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_9 ( V_52 , L_31 ,
V_2 , V_2 -> V_90 . V_127 , V_2 -> V_90 . V_75 ) ;
F_1 ( V_2 ) ;
F_69 ( & V_2 -> V_51 ) ;
F_69 ( & V_2 -> V_71 ) ;
F_7 ( V_2 , - V_94 ) ;
V_2 -> V_18 = NULL ;
}
static void F_70 ( struct V_23 * V_18 )
{
struct V_28 * V_29 ;
if ( ! V_18 )
return;
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return;
V_18 -> V_30 = V_43 ;
F_68 ( & V_29 -> V_83 ) ;
if ( V_29 -> V_34 )
F_59 ( V_29 -> V_34 ) ;
if ( V_29 -> V_38 )
F_59 ( V_29 -> V_38 ) ;
F_55 ( V_29 ) ;
}
static inline int F_71 ( const char * V_128 )
{
int V_53 , V_129 , V_130 [ 4 ] ;
V_53 = sscanf ( V_128 , L_32 , & V_130 [ 0 ] , & V_130 [ 1 ] , & V_130 [ 2 ] , & V_130 [ 3 ] ) ;
if ( V_53 != 4 )
return - V_131 ;
for ( V_129 = 0 ; V_129 < 4 ; V_129 ++ ) {
if ( V_130 [ V_129 ] > 255 )
return - V_131 ;
}
return 0 ;
}
static int F_72 ( struct V_121 * V_132 )
{
struct V_133 V_134 ;
int V_106 , V_12 = - V_131 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_135 = V_136 ;
V_134 . V_137 . V_138 = V_139 ;
for ( V_106 = V_140 ; V_106 >= V_141 ; V_106 -- ) {
V_134 . V_142 = F_73 ( ( V_143 ) V_106 ) ;
V_12 = F_74 ( V_132 , (struct V_144 * ) & V_134 , sizeof( V_134 ) ) ;
if ( V_12 != - V_145 )
break;
}
return V_12 ;
}
static int
F_75 ( struct V_23 * V_18 , const char * V_146 , char * args )
{
int V_12 ;
struct V_121 * V_122 ;
struct V_133 V_147 ;
struct V_100 V_101 ;
V_12 = F_50 ( args , & V_101 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_71 ( V_146 ) < 0 )
return - V_131 ;
V_122 = NULL ;
V_147 . V_135 = V_136 ;
V_147 . V_137 . V_138 = F_76 ( V_146 ) ;
V_147 . V_142 = F_73 ( V_101 . V_106 ) ;
V_12 = F_77 ( V_95 -> V_148 -> V_149 , V_150 ,
V_151 , V_152 , & V_122 , 1 ) ;
if ( V_12 ) {
F_63 ( L_33 ,
V_126 , F_64 ( V_95 ) ) ;
return V_12 ;
}
if ( V_101 . V_110 ) {
V_12 = F_72 ( V_122 ) ;
if ( V_12 < 0 ) {
F_63 ( L_34 ,
V_126 , F_64 ( V_95 ) ) ;
F_65 ( V_122 ) ;
return V_12 ;
}
}
V_12 = V_122 -> V_153 -> V_154 ( V_122 ,
(struct V_144 * ) & V_147 ,
sizeof( struct V_133 ) , 0 ) ;
if ( V_12 < 0 ) {
F_63 ( L_35 ,
V_126 , F_64 ( V_95 ) , V_146 ) ;
F_65 ( V_122 ) ;
return V_12 ;
}
return F_60 ( V_18 , V_122 ) ;
}
static int
F_78 ( struct V_23 * V_18 , const char * V_146 , char * args )
{
int V_12 ;
struct V_121 * V_122 ;
struct V_155 V_156 ;
V_122 = NULL ;
if ( strlen ( V_146 ) >= V_157 ) {
F_63 ( L_36 ,
V_126 , F_64 ( V_95 ) , V_146 ) ;
return - V_158 ;
}
V_156 . V_159 = V_160 ;
strcpy ( V_156 . V_161 , V_146 ) ;
V_12 = F_77 ( V_95 -> V_148 -> V_149 , V_160 ,
V_151 , 0 , & V_122 , 1 ) ;
if ( V_12 < 0 ) {
F_63 ( L_33 ,
V_126 , F_64 ( V_95 ) ) ;
return V_12 ;
}
V_12 = V_122 -> V_153 -> V_154 ( V_122 , (struct V_144 * ) & V_156 ,
sizeof( struct V_155 ) - 1 , 0 ) ;
if ( V_12 < 0 ) {
F_63 ( L_37 ,
V_126 , F_64 ( V_95 ) , V_146 , V_12 ) ;
F_65 ( V_122 ) ;
return V_12 ;
}
return F_60 ( V_18 , V_122 ) ;
}
static int
F_79 ( struct V_23 * V_18 , const char * V_146 , char * args )
{
int V_12 ;
struct V_100 V_101 ;
F_50 ( args , & V_101 ) ;
if ( V_101 . V_108 == ~ 0 || V_101 . V_109 == ~ 0 ) {
F_63 ( L_38 ) ;
return - V_162 ;
}
V_12 = F_56 ( V_18 , V_101 . V_108 , V_101 . V_109 ) ;
if ( V_12 < 0 )
return V_12 ;
F_41 ( V_18 ) ;
return 0 ;
}
static void F_80 ( struct V_49 * V_50 )
{
unsigned long V_3 ;
F_9 ( V_52 , L_39 , V_95 ) ;
F_4 ( & V_10 , V_3 ) ;
while ( ! F_24 ( & V_84 ) ) {
struct V_1 * V_83 = F_81 ( & V_84 ,
struct V_1 ,
V_11 ) ;
F_5 ( & V_83 -> V_11 ) ;
F_6 ( & V_10 , V_3 ) ;
F_46 ( V_83 ) ;
F_4 ( & V_10 , V_3 ) ;
}
F_6 ( & V_10 , V_3 ) ;
F_9 ( V_52 , L_40 ) ;
}
int F_82 ( void )
{
F_83 ( & V_163 ) ;
F_83 ( & V_164 ) ;
F_83 ( & V_165 ) ;
return 0 ;
}
void F_84 ( void )
{
F_85 ( & V_85 ) ;
F_86 ( & V_163 ) ;
F_86 ( & V_164 ) ;
F_86 ( & V_165 ) ;
}
