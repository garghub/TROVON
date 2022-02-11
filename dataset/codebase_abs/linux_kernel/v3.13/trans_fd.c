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
V_14 -> V_20 = V_21 ;
if ( ! V_14 -> V_22 )
V_14 -> V_22 = V_12 ;
F_11 ( & V_14 -> V_23 , & V_16 ) ;
}
F_10 (req, rtmp, &m->unsent_req_list, req_list) {
V_14 -> V_20 = V_21 ;
if ( ! V_14 -> V_22 )
V_14 -> V_22 = V_12 ;
F_11 ( & V_14 -> V_23 , & V_16 ) ;
}
F_6 ( & V_2 -> V_18 -> V_19 , V_3 ) ;
F_10 (req, rtmp, &cancel_list, req_list) {
F_9 ( V_17 , L_2 , V_14 ) ;
F_12 ( & V_14 -> V_23 ) ;
F_13 ( V_2 -> V_18 , V_14 ) ;
}
}
static int
F_14 ( struct V_24 * V_18 , struct V_25 * V_26 )
{
int V_27 , V_28 ;
struct V_29 * V_30 = NULL ;
if ( V_18 && V_18 -> V_20 == V_31 )
V_30 = V_18 -> V_32 ;
if ( ! V_30 )
return - V_33 ;
if ( ! V_30 -> V_34 -> V_35 -> V_36 )
return - V_37 ;
if ( ! V_30 -> V_38 -> V_35 -> V_36 )
return - V_37 ;
V_27 = V_30 -> V_34 -> V_35 -> V_36 ( V_30 -> V_34 , V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_30 -> V_34 != V_30 -> V_38 ) {
V_28 = V_30 -> V_38 -> V_35 -> V_36 ( V_30 -> V_38 , V_26 ) ;
if ( V_28 < 0 )
return V_28 ;
V_27 = ( V_27 & ~ V_39 ) | ( V_28 & ~ V_40 ) ;
}
return V_27 ;
}
static int F_15 ( struct V_24 * V_18 , void * V_41 , int V_42 )
{
int V_27 ;
struct V_29 * V_30 = NULL ;
if ( V_18 && V_18 -> V_20 != V_43 )
V_30 = V_18 -> V_32 ;
if ( ! V_30 )
return - V_33 ;
if ( ! ( V_30 -> V_34 -> V_44 & V_45 ) )
F_9 ( V_17 , L_3 ) ;
V_27 = F_16 ( V_30 -> V_34 , V_30 -> V_34 -> V_46 , V_41 , V_42 ) ;
if ( V_27 <= 0 && V_27 != - V_47 && V_27 != - V_48 )
V_18 -> V_20 = V_43 ;
return V_27 ;
}
static void F_17 ( struct V_49 * V_50 )
{
int V_28 , V_12 ;
struct V_1 * V_2 ;
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
V_28 = F_20 ( * ( V_61 * ) V_2 -> V_54 ) ;
if ( V_28 >= V_2 -> V_18 -> V_62 ) {
F_9 ( V_17 ,
L_8 , V_28 ) ;
V_12 = - V_37 ;
goto error;
}
V_60 = F_21 ( * ( V_63 * ) ( V_2 -> V_54 + 5 ) ) ;
F_9 ( V_52 ,
L_9 , V_2 , V_28 , V_60 ) ;
V_2 -> V_14 = F_22 ( V_2 -> V_18 , V_60 ) ;
if ( ! V_2 -> V_14 || ( V_2 -> V_14 -> V_20 != V_64 &&
V_2 -> V_14 -> V_20 != V_65 ) ) {
F_9 ( V_17 , L_10 ,
V_60 ) ;
V_12 = - V_37 ;
goto error;
}
if ( V_2 -> V_14 -> V_66 == NULL ) {
V_2 -> V_14 -> V_66 = F_23 ( sizeof( struct V_67 ) +
V_2 -> V_18 -> V_62 , V_68 ) ;
if ( ! V_2 -> V_14 -> V_66 ) {
V_2 -> V_14 = NULL ;
V_12 = - V_69 ;
goto error;
}
}
V_2 -> V_54 = ( char * ) V_2 -> V_14 -> V_66 + sizeof( struct V_67 ) ;
memcpy ( V_2 -> V_54 , V_2 -> V_55 , V_2 -> V_56 ) ;
V_2 -> V_56 = V_28 ;
}
if ( ( V_2 -> V_14 ) && ( V_2 -> V_53 == V_2 -> V_56 ) ) {
F_9 ( V_52 , L_11 ) ;
F_24 ( & V_2 -> V_18 -> V_19 ) ;
if ( V_2 -> V_14 -> V_20 != V_21 )
V_2 -> V_14 -> V_20 = V_70 ;
F_12 ( & V_2 -> V_14 -> V_23 ) ;
F_25 ( & V_2 -> V_18 -> V_19 ) ;
F_13 ( V_2 -> V_18 , V_2 -> V_14 ) ;
V_2 -> V_54 = NULL ;
V_2 -> V_53 = 0 ;
V_2 -> V_56 = 0 ;
V_2 -> V_14 = NULL ;
}
V_59:
F_19 ( V_71 , & V_2 -> V_58 ) ;
if ( ! F_26 ( & V_2 -> V_23 ) ) {
if ( F_27 ( V_57 , & V_2 -> V_58 ) )
V_28 = V_40 ;
else
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_28 & V_40 ) && ! F_28 ( V_71 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_12 , V_2 ) ;
F_29 ( & V_2 -> V_51 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_71 , & V_2 -> V_58 ) ;
}
static int F_30 ( struct V_24 * V_18 , void * V_41 , int V_42 )
{
int V_27 ;
T_2 V_72 ;
struct V_29 * V_30 = NULL ;
if ( V_18 && V_18 -> V_20 != V_43 )
V_30 = V_18 -> V_32 ;
if ( ! V_30 )
return - V_33 ;
if ( ! ( V_30 -> V_38 -> V_44 & V_45 ) )
F_9 ( V_17 , L_13 ) ;
V_72 = F_31 () ;
F_32 ( F_33 () ) ;
V_27 = F_34 ( V_30 -> V_38 , ( V_73 void V_74 * ) V_41 , V_42 , & V_30 -> V_38 -> V_46 ) ;
F_32 ( V_72 ) ;
if ( V_27 <= 0 && V_27 != - V_47 && V_27 != - V_48 )
V_18 -> V_20 = V_43 ;
return V_27 ;
}
static void F_35 ( struct V_49 * V_50 )
{
int V_28 , V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_2 = F_18 ( V_50 , struct V_1 , V_75 ) ;
if ( V_2 -> V_12 < 0 ) {
F_19 ( V_76 , & V_2 -> V_58 ) ;
return;
}
if ( ! V_2 -> V_77 ) {
F_24 ( & V_2 -> V_18 -> V_19 ) ;
if ( F_26 ( & V_2 -> V_78 ) ) {
F_19 ( V_76 , & V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_18 -> V_19 ) ;
return;
}
V_14 = F_36 ( V_2 -> V_78 . V_79 , struct V_13 ,
V_23 ) ;
V_14 -> V_20 = V_64 ;
F_9 ( V_52 , L_14 , V_14 ) ;
F_37 ( & V_14 -> V_23 , & V_2 -> V_23 ) ;
V_2 -> V_80 = V_14 -> V_81 -> V_82 ;
V_2 -> V_77 = V_14 -> V_81 -> V_83 ;
V_2 -> V_84 = 0 ;
F_25 ( & V_2 -> V_18 -> V_19 ) ;
}
F_9 ( V_52 , L_15 ,
V_2 , V_2 -> V_84 , V_2 -> V_77 ) ;
F_19 ( V_85 , & V_2 -> V_58 ) ;
V_12 = F_30 ( V_2 -> V_18 , V_2 -> V_80 + V_2 -> V_84 , V_2 -> V_77 - V_2 -> V_84 ) ;
F_9 ( V_52 , L_16 , V_2 , V_12 ) ;
if ( V_12 == - V_48 )
goto V_59;
if ( V_12 < 0 )
goto error;
else if ( V_12 == 0 ) {
V_12 = - V_33 ;
goto error;
}
V_2 -> V_84 += V_12 ;
if ( V_2 -> V_84 == V_2 -> V_77 )
V_2 -> V_84 = V_2 -> V_77 = 0 ;
V_59:
F_19 ( V_76 , & V_2 -> V_58 ) ;
if ( V_2 -> V_77 || ! F_26 ( & V_2 -> V_78 ) ) {
if ( F_27 ( V_85 , & V_2 -> V_58 ) )
V_28 = V_39 ;
else
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_28 & V_39 ) &&
! F_28 ( V_76 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_17 , V_2 ) ;
F_29 ( & V_2 -> V_75 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_76 , & V_2 -> V_58 ) ;
}
static int F_38 ( T_3 * V_9 , unsigned int V_86 , int V_87 , void * V_88 )
{
struct V_6 * V_7 =
F_18 ( V_9 , struct V_6 , V_9 ) ;
struct V_1 * V_2 = V_7 -> V_89 ;
unsigned long V_3 ;
F_4 ( & V_10 , V_3 ) ;
if ( F_26 ( & V_2 -> V_11 ) )
F_39 ( & V_2 -> V_11 , & V_90 ) ;
F_6 ( & V_10 , V_3 ) ;
F_29 ( & V_91 ) ;
return 1 ;
}
static void
F_40 ( struct V_92 * V_93 , T_4 * V_94 , T_5 * V_95 )
{
struct V_1 * V_2 = F_18 ( V_95 , struct V_1 , V_26 ) ;
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
V_7 -> V_89 = V_2 ;
V_7 -> V_8 = V_94 ;
F_41 ( & V_7 -> V_9 , F_38 ) ;
F_42 ( V_94 , & V_7 -> V_9 ) ;
}
static struct V_1 * F_43 ( struct V_24 * V_18 )
{
int V_28 ;
struct V_1 * V_2 ;
F_9 ( V_52 , L_19 , V_18 , V_18 -> V_62 ) ;
V_2 = F_44 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_2 )
return F_45 ( - V_69 ) ;
F_46 ( & V_2 -> V_97 ) ;
V_2 -> V_18 = V_18 ;
F_46 ( & V_2 -> V_23 ) ;
F_46 ( & V_2 -> V_78 ) ;
F_47 ( & V_2 -> V_51 , F_17 ) ;
F_47 ( & V_2 -> V_75 , F_35 ) ;
F_46 ( & V_2 -> V_11 ) ;
F_48 ( & V_2 -> V_26 , F_40 ) ;
V_28 = F_14 ( V_18 , & V_2 -> V_26 ) ;
if ( V_28 & V_40 ) {
F_9 ( V_52 , L_20 , V_2 ) ;
F_49 ( V_57 , & V_2 -> V_58 ) ;
}
if ( V_28 & V_39 ) {
F_9 ( V_52 , L_21 , V_2 ) ;
F_49 ( V_85 , & V_2 -> V_58 ) ;
}
return V_2 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_12 < 0 )
return;
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_28 < 0 || V_28 & ( V_98 | V_99 | V_100 ) ) {
F_9 ( V_52 , L_22 , V_2 , V_28 ) ;
if ( V_28 >= 0 )
V_28 = - V_101 ;
F_7 ( V_2 , V_28 ) ;
}
if ( V_28 & V_40 ) {
F_49 ( V_57 , & V_2 -> V_58 ) ;
F_9 ( V_52 , L_20 , V_2 ) ;
if ( ! F_28 ( V_71 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_12 , V_2 ) ;
F_29 ( & V_2 -> V_51 ) ;
}
}
if ( V_28 & V_39 ) {
F_49 ( V_85 , & V_2 -> V_58 ) ;
F_9 ( V_52 , L_21 , V_2 ) ;
if ( ( V_2 -> V_77 || ! F_26 ( & V_2 -> V_78 ) ) &&
! F_28 ( V_76 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_17 , V_2 ) ;
F_29 ( & V_2 -> V_75 ) ;
}
}
}
static int F_51 ( struct V_24 * V_18 , struct V_13 * V_14 )
{
int V_28 ;
struct V_29 * V_30 = V_18 -> V_32 ;
struct V_1 * V_2 = V_30 -> V_89 ;
F_9 ( V_52 , L_23 ,
V_2 , V_102 , V_14 -> V_81 , V_14 -> V_81 -> V_103 ) ;
if ( V_2 -> V_12 < 0 )
return V_2 -> V_12 ;
F_24 ( & V_18 -> V_19 ) ;
V_14 -> V_20 = V_104 ;
F_39 ( & V_14 -> V_23 , & V_2 -> V_78 ) ;
F_25 ( & V_18 -> V_19 ) ;
if ( F_27 ( V_85 , & V_2 -> V_58 ) )
V_28 = V_39 ;
else
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_28 & V_39 && ! F_28 ( V_76 , & V_2 -> V_58 ) )
F_29 ( & V_2 -> V_75 ) ;
return 0 ;
}
static int F_52 ( struct V_24 * V_18 , struct V_13 * V_14 )
{
int V_27 = 1 ;
F_9 ( V_52 , L_24 , V_18 , V_14 ) ;
F_24 ( & V_18 -> V_19 ) ;
if ( V_14 -> V_20 == V_104 ) {
F_12 ( & V_14 -> V_23 ) ;
V_14 -> V_20 = V_105 ;
V_27 = 0 ;
} else if ( V_14 -> V_20 == V_64 )
V_14 -> V_20 = V_65 ;
F_25 ( & V_18 -> V_19 ) ;
return V_27 ;
}
static int F_53 ( char * V_106 , struct V_107 * V_108 )
{
char * V_95 ;
T_6 args [ V_109 ] ;
int V_110 ;
char * V_111 , * V_112 ;
V_108 -> V_113 = V_114 ;
V_108 -> V_115 = ~ 0 ;
V_108 -> V_116 = ~ 0 ;
if ( ! V_106 )
return 0 ;
V_112 = F_54 ( V_106 , V_96 ) ;
if ( ! V_112 ) {
F_9 ( V_17 ,
L_25 ) ;
return - V_69 ;
}
V_111 = V_112 ;
while ( ( V_95 = F_55 ( & V_111 , L_26 ) ) != NULL ) {
int V_117 ;
int V_118 ;
if ( ! * V_95 )
continue;
V_117 = F_56 ( V_95 , V_119 , args ) ;
if ( ( V_117 != V_120 ) && ( V_117 != V_121 ) ) {
V_118 = F_57 ( & args [ 0 ] , & V_110 ) ;
if ( V_118 < 0 ) {
F_9 ( V_17 ,
L_27 ) ;
continue;
}
}
switch ( V_117 ) {
case V_122 :
V_108 -> V_113 = V_110 ;
break;
case V_123 :
V_108 -> V_115 = V_110 ;
break;
case V_124 :
V_108 -> V_116 = V_110 ;
break;
case V_121 :
V_108 -> V_125 = 1 ;
break;
default:
continue;
}
}
F_58 ( V_112 ) ;
return 0 ;
}
static int F_59 ( struct V_24 * V_18 , int V_115 , int V_116 )
{
struct V_29 * V_30 = F_23 ( sizeof( struct V_29 ) ,
V_96 ) ;
if ( ! V_30 )
return - V_69 ;
V_30 -> V_34 = F_60 ( V_115 ) ;
V_30 -> V_38 = F_60 ( V_116 ) ;
if ( ! V_30 -> V_34 || ! V_30 -> V_38 ) {
if ( V_30 -> V_34 )
F_61 ( V_30 -> V_34 ) ;
if ( V_30 -> V_38 )
F_61 ( V_30 -> V_38 ) ;
F_58 ( V_30 ) ;
return - V_37 ;
}
V_18 -> V_32 = V_30 ;
V_18 -> V_20 = V_31 ;
return 0 ;
}
static int F_62 ( struct V_24 * V_18 , struct V_126 * V_127 )
{
struct V_29 * V_95 ;
struct V_92 * V_92 ;
int V_27 ;
V_95 = F_23 ( sizeof( struct V_29 ) , V_96 ) ;
if ( ! V_95 )
return - V_69 ;
V_127 -> V_128 -> V_129 = V_130 ;
V_92 = F_63 ( V_127 , 0 , NULL ) ;
if ( F_64 ( V_92 ) ) {
F_65 ( L_28 ,
V_131 , F_66 ( V_102 ) ) ;
F_67 ( V_127 ) ;
F_58 ( V_95 ) ;
return F_68 ( V_92 ) ;
}
F_69 ( V_92 ) ;
V_95 -> V_38 = V_95 -> V_34 = V_92 ;
V_18 -> V_32 = V_95 ;
V_18 -> V_20 = V_31 ;
V_95 -> V_34 -> V_44 |= V_45 ;
V_95 -> V_89 = F_43 ( V_18 ) ;
if ( F_64 ( V_95 -> V_89 ) ) {
V_27 = F_68 ( V_95 -> V_89 ) ;
V_95 -> V_89 = NULL ;
F_58 ( V_95 ) ;
F_70 ( V_127 ) ;
F_70 ( V_127 ) ;
return V_27 ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_9 ( V_52 , L_29 ,
V_2 , V_2 -> V_97 . V_132 , V_2 -> V_97 . V_79 ) ;
F_1 ( V_2 ) ;
F_72 ( & V_2 -> V_51 ) ;
F_72 ( & V_2 -> V_75 ) ;
F_7 ( V_2 , - V_101 ) ;
V_2 -> V_18 = NULL ;
F_58 ( V_2 ) ;
}
static void F_73 ( struct V_24 * V_18 )
{
struct V_29 * V_30 ;
if ( ! V_18 )
return;
V_30 = V_18 -> V_32 ;
if ( ! V_30 )
return;
V_18 -> V_20 = V_43 ;
F_71 ( V_30 -> V_89 ) ;
if ( V_30 -> V_34 )
F_61 ( V_30 -> V_34 ) ;
if ( V_30 -> V_38 )
F_61 ( V_30 -> V_38 ) ;
F_58 ( V_30 ) ;
}
static inline int F_74 ( const char * V_133 )
{
int V_66 , V_134 , V_135 [ 4 ] ;
V_66 = sscanf ( V_133 , L_30 , & V_135 [ 0 ] , & V_135 [ 1 ] , & V_135 [ 2 ] , & V_135 [ 3 ] ) ;
if ( V_66 != 4 )
return - V_136 ;
for ( V_134 = 0 ; V_134 < 4 ; V_134 ++ ) {
if ( V_135 [ V_134 ] > 255 )
return - V_136 ;
}
return 0 ;
}
static int F_75 ( struct V_126 * V_137 )
{
struct V_138 V_139 ;
int V_113 , V_12 = - V_136 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_140 = V_141 ;
V_139 . V_142 . V_143 = V_144 ;
for ( V_113 = V_145 ; V_113 >= V_146 ; V_113 -- ) {
V_139 . V_147 = F_76 ( ( V_148 ) V_113 ) ;
V_12 = F_77 ( V_137 , (struct V_149 * ) & V_139 , sizeof( V_139 ) ) ;
if ( V_12 != - V_150 )
break;
}
return V_12 ;
}
static int
F_78 ( struct V_24 * V_18 , const char * V_151 , char * args )
{
int V_12 ;
struct V_126 * V_127 ;
struct V_138 V_152 ;
struct V_107 V_108 ;
V_12 = F_53 ( args , & V_108 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_74 ( V_151 ) < 0 )
return - V_136 ;
V_127 = NULL ;
V_152 . V_140 = V_141 ;
V_152 . V_142 . V_143 = F_79 ( V_151 ) ;
V_152 . V_147 = F_76 ( V_108 . V_113 ) ;
V_12 = F_80 ( F_81 ( & V_102 -> V_153 -> V_154 ) , V_155 ,
V_156 , V_157 , & V_127 , 1 ) ;
if ( V_12 ) {
F_65 ( L_31 ,
V_131 , F_66 ( V_102 ) ) ;
return V_12 ;
}
if ( V_108 . V_125 ) {
V_12 = F_75 ( V_127 ) ;
if ( V_12 < 0 ) {
F_65 ( L_32 ,
V_131 , F_66 ( V_102 ) ) ;
F_67 ( V_127 ) ;
return V_12 ;
}
}
V_12 = V_127 -> V_158 -> V_159 ( V_127 ,
(struct V_149 * ) & V_152 ,
sizeof( struct V_138 ) , 0 ) ;
if ( V_12 < 0 ) {
F_65 ( L_33 ,
V_131 , F_66 ( V_102 ) , V_151 ) ;
F_67 ( V_127 ) ;
return V_12 ;
}
return F_62 ( V_18 , V_127 ) ;
}
static int
F_82 ( struct V_24 * V_18 , const char * V_151 , char * args )
{
int V_12 ;
struct V_126 * V_127 ;
struct V_160 V_161 ;
V_127 = NULL ;
if ( strlen ( V_151 ) >= V_162 ) {
F_65 ( L_34 ,
V_131 , F_66 ( V_102 ) , V_151 ) ;
return - V_163 ;
}
V_161 . V_164 = V_165 ;
strcpy ( V_161 . V_166 , V_151 ) ;
V_12 = F_80 ( F_81 ( & V_102 -> V_153 -> V_154 ) , V_165 ,
V_156 , 0 , & V_127 , 1 ) ;
if ( V_12 < 0 ) {
F_65 ( L_31 ,
V_131 , F_66 ( V_102 ) ) ;
return V_12 ;
}
V_12 = V_127 -> V_158 -> V_159 ( V_127 , (struct V_149 * ) & V_161 ,
sizeof( struct V_160 ) - 1 , 0 ) ;
if ( V_12 < 0 ) {
F_65 ( L_35 ,
V_131 , F_66 ( V_102 ) , V_151 , V_12 ) ;
F_67 ( V_127 ) ;
return V_12 ;
}
return F_62 ( V_18 , V_127 ) ;
}
static int
F_83 ( struct V_24 * V_18 , const char * V_151 , char * args )
{
int V_12 ;
struct V_107 V_108 ;
struct V_29 * V_95 ;
F_53 ( args , & V_108 ) ;
if ( V_108 . V_115 == ~ 0 || V_108 . V_116 == ~ 0 ) {
F_65 ( L_36 ) ;
return - V_167 ;
}
V_12 = F_59 ( V_18 , V_108 . V_115 , V_108 . V_116 ) ;
if ( V_12 < 0 )
return V_12 ;
V_95 = (struct V_29 * ) V_18 -> V_32 ;
V_95 -> V_89 = F_43 ( V_18 ) ;
if ( F_64 ( V_95 -> V_89 ) ) {
V_12 = F_68 ( V_95 -> V_89 ) ;
V_95 -> V_89 = NULL ;
F_61 ( V_95 -> V_34 ) ;
F_61 ( V_95 -> V_38 ) ;
return V_12 ;
}
return 0 ;
}
static void F_84 ( struct V_49 * V_50 )
{
unsigned long V_3 ;
F_9 ( V_52 , L_37 , V_102 ) ;
F_4 ( & V_10 , V_3 ) ;
while ( ! F_26 ( & V_90 ) ) {
struct V_1 * V_89 = F_85 ( & V_90 ,
struct V_1 ,
V_11 ) ;
F_5 ( & V_89 -> V_11 ) ;
F_6 ( & V_10 , V_3 ) ;
F_50 ( V_89 ) ;
F_4 ( & V_10 , V_3 ) ;
}
F_6 ( & V_10 , V_3 ) ;
F_9 ( V_52 , L_38 ) ;
}
int F_86 ( void )
{
F_87 ( & V_168 ) ;
F_87 ( & V_169 ) ;
F_87 ( & V_170 ) ;
return 0 ;
}
void F_88 ( void )
{
F_89 ( & V_91 ) ;
F_90 ( & V_168 ) ;
F_90 ( & V_169 ) ;
F_90 ( & V_170 ) ;
}
