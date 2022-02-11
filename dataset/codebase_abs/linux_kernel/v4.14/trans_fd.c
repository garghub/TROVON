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
T_1 V_43 ;
if ( V_18 && V_18 -> V_30 != V_44 )
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return - V_33 ;
if ( ! ( V_29 -> V_34 -> V_45 & V_46 ) )
F_9 ( V_17 , L_3 ) ;
V_43 = V_29 -> V_34 -> V_47 ;
V_26 = F_16 ( V_29 -> V_34 , V_41 , V_42 , & V_43 ) ;
if ( V_26 <= 0 && V_26 != - V_48 && V_26 != - V_49 )
V_18 -> V_30 = V_44 ;
return V_26 ;
}
static void F_17 ( struct V_50 * V_51 )
{
int V_27 , V_12 ;
struct V_1 * V_2 ;
int V_30 = V_22 ;
V_2 = F_18 ( V_51 , struct V_1 , V_52 ) ;
if ( V_2 -> V_12 < 0 )
return;
F_9 ( V_53 , L_4 , V_2 , V_2 -> V_54 . V_55 ) ;
if ( ! V_2 -> V_54 . V_56 ) {
V_2 -> V_54 . V_56 = V_2 -> V_57 ;
V_2 -> V_54 . V_55 = 0 ;
V_2 -> V_54 . V_58 = 7 ;
}
F_19 ( V_59 , & V_2 -> V_60 ) ;
F_9 ( V_53 , L_5 ,
V_2 , V_2 -> V_54 . V_55 , V_2 -> V_54 . V_58 ,
V_2 -> V_54 . V_58 - V_2 -> V_54 . V_55 ) ;
V_12 = F_15 ( V_2 -> V_18 , V_2 -> V_54 . V_56 + V_2 -> V_54 . V_55 ,
V_2 -> V_54 . V_58 - V_2 -> V_54 . V_55 ) ;
F_9 ( V_53 , L_6 , V_2 , V_12 ) ;
if ( V_12 == - V_49 )
goto V_61;
if ( V_12 <= 0 )
goto error;
V_2 -> V_54 . V_55 += V_12 ;
if ( ( ! V_2 -> V_14 ) && ( V_2 -> V_54 . V_55 == V_2 -> V_54 . V_58 ) ) {
F_9 ( V_53 , L_7 ) ;
V_12 = F_20 ( & V_2 -> V_54 , NULL , NULL , NULL , 0 ) ;
if ( V_12 ) {
F_9 ( V_17 ,
L_8 , V_12 ) ;
goto error;
}
if ( V_2 -> V_54 . V_62 >= V_2 -> V_18 -> V_63 ) {
F_9 ( V_17 ,
L_9 ,
V_2 -> V_54 . V_62 ) ;
V_12 = - V_37 ;
goto error;
}
F_9 ( V_53 ,
L_10 ,
V_2 , V_2 -> V_54 . V_62 , V_2 -> V_54 . V_64 ) ;
V_2 -> V_14 = F_21 ( V_2 -> V_18 , V_2 -> V_54 . V_64 ) ;
if ( ! V_2 -> V_14 || ( V_2 -> V_14 -> V_30 != V_65 ) ) {
F_9 ( V_17 , L_11 ,
V_2 -> V_54 . V_64 ) ;
V_12 = - V_37 ;
goto error;
}
if ( V_2 -> V_14 -> V_54 == NULL ) {
F_9 ( V_17 ,
L_12 ,
V_2 -> V_54 . V_64 , V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
V_12 = - V_37 ;
goto error;
}
V_2 -> V_54 . V_56 = ( char * ) V_2 -> V_14 -> V_54 + sizeof( struct V_66 ) ;
memcpy ( V_2 -> V_54 . V_56 , V_2 -> V_57 , V_2 -> V_54 . V_58 ) ;
V_2 -> V_54 . V_58 = V_2 -> V_54 . V_62 ;
}
if ( ( V_2 -> V_14 ) && ( V_2 -> V_54 . V_55 == V_2 -> V_54 . V_58 ) ) {
F_9 ( V_53 , L_13 ) ;
F_22 ( & V_2 -> V_18 -> V_19 ) ;
if ( V_2 -> V_14 -> V_30 != V_22 )
V_30 = V_67 ;
F_12 ( & V_2 -> V_14 -> V_20 ) ;
F_23 ( & V_2 -> V_18 -> V_19 ) ;
F_13 ( V_2 -> V_18 , V_2 -> V_14 , V_30 ) ;
V_2 -> V_54 . V_56 = NULL ;
V_2 -> V_54 . V_55 = 0 ;
V_2 -> V_54 . V_58 = 0 ;
V_2 -> V_14 = NULL ;
}
V_61:
F_19 ( V_68 , & V_2 -> V_60 ) ;
if ( ! F_24 ( & V_2 -> V_20 ) ) {
if ( F_25 ( V_59 , & V_2 -> V_60 ) )
V_27 = V_40 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_27 & V_40 ) && ! F_26 ( V_68 , & V_2 -> V_60 ) ) {
F_9 ( V_53 , L_14 , V_2 ) ;
F_27 ( & V_2 -> V_52 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_68 , & V_2 -> V_60 ) ;
}
static int F_28 ( struct V_23 * V_18 , void * V_41 , int V_42 )
{
T_2 V_26 ;
struct V_28 * V_29 = NULL ;
if ( V_18 && V_18 -> V_30 != V_44 )
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return - V_33 ;
if ( ! ( V_29 -> V_38 -> V_45 & V_46 ) )
F_9 ( V_17 , L_15 ) ;
V_26 = F_29 ( V_29 -> V_38 , V_41 , V_42 , & V_29 -> V_38 -> V_47 ) ;
if ( V_26 <= 0 && V_26 != - V_48 && V_26 != - V_49 )
V_18 -> V_30 = V_44 ;
return V_26 ;
}
static void F_30 ( struct V_50 * V_51 )
{
int V_27 , V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_2 = F_18 ( V_51 , struct V_1 , V_69 ) ;
if ( V_2 -> V_12 < 0 ) {
F_19 ( V_70 , & V_2 -> V_60 ) ;
return;
}
if ( ! V_2 -> V_71 ) {
F_22 ( & V_2 -> V_18 -> V_19 ) ;
if ( F_24 ( & V_2 -> V_72 ) ) {
F_19 ( V_70 , & V_2 -> V_60 ) ;
F_23 ( & V_2 -> V_18 -> V_19 ) ;
return;
}
V_14 = F_31 ( V_2 -> V_72 . V_73 , struct V_13 ,
V_20 ) ;
V_14 -> V_30 = V_65 ;
F_9 ( V_53 , L_16 , V_14 ) ;
F_32 ( & V_14 -> V_20 , & V_2 -> V_20 ) ;
V_2 -> V_74 = V_14 -> V_75 -> V_56 ;
V_2 -> V_71 = V_14 -> V_75 -> V_62 ;
V_2 -> V_76 = 0 ;
F_23 ( & V_2 -> V_18 -> V_19 ) ;
}
F_9 ( V_53 , L_17 ,
V_2 , V_2 -> V_76 , V_2 -> V_71 ) ;
F_19 ( V_77 , & V_2 -> V_60 ) ;
V_12 = F_28 ( V_2 -> V_18 , V_2 -> V_74 + V_2 -> V_76 , V_2 -> V_71 - V_2 -> V_76 ) ;
F_9 ( V_53 , L_18 , V_2 , V_12 ) ;
if ( V_12 == - V_49 )
goto V_61;
if ( V_12 < 0 )
goto error;
else if ( V_12 == 0 ) {
V_12 = - V_33 ;
goto error;
}
V_2 -> V_76 += V_12 ;
if ( V_2 -> V_76 == V_2 -> V_71 )
V_2 -> V_76 = V_2 -> V_71 = 0 ;
V_61:
F_19 ( V_70 , & V_2 -> V_60 ) ;
if ( V_2 -> V_71 || ! F_24 ( & V_2 -> V_72 ) ) {
if ( F_25 ( V_77 , & V_2 -> V_60 ) )
V_27 = V_39 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( ( V_27 & V_39 ) &&
! F_26 ( V_70 , & V_2 -> V_60 ) ) {
F_9 ( V_53 , L_19 , V_2 ) ;
F_27 ( & V_2 -> V_69 ) ;
}
}
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_70 , & V_2 -> V_60 ) ;
}
static int F_33 ( T_3 * V_9 , unsigned int V_78 , int V_79 , void * V_80 )
{
struct V_6 * V_7 =
F_18 ( V_9 , struct V_6 , V_9 ) ;
struct V_1 * V_2 = V_7 -> V_81 ;
unsigned long V_3 ;
F_4 ( & V_10 , V_3 ) ;
if ( F_24 ( & V_2 -> V_11 ) )
F_34 ( & V_2 -> V_11 , & V_82 ) ;
F_6 ( & V_10 , V_3 ) ;
F_27 ( & V_83 ) ;
return 1 ;
}
static void
F_35 ( struct V_84 * V_85 , T_4 * V_86 , T_5 * V_87 )
{
struct V_1 * V_2 = F_18 ( V_87 , struct V_1 , V_25 ) ;
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
V_7 -> V_81 = V_2 ;
V_7 -> V_8 = V_86 ;
F_36 ( & V_7 -> V_9 , F_33 ) ;
F_37 ( V_86 , & V_7 -> V_9 ) ;
}
static void F_38 ( struct V_23 * V_18 )
{
int V_27 ;
struct V_28 * V_29 = V_18 -> V_32 ;
struct V_1 * V_2 = & V_29 -> V_81 ;
F_9 ( V_53 , L_21 , V_18 , V_18 -> V_63 ) ;
F_39 ( & V_2 -> V_88 ) ;
V_2 -> V_18 = V_18 ;
F_39 ( & V_2 -> V_20 ) ;
F_39 ( & V_2 -> V_72 ) ;
F_40 ( & V_2 -> V_52 , F_17 ) ;
F_40 ( & V_2 -> V_69 , F_30 ) ;
F_39 ( & V_2 -> V_11 ) ;
F_41 ( & V_2 -> V_25 , F_35 ) ;
V_27 = F_14 ( V_18 , & V_2 -> V_25 ) ;
if ( V_27 & V_40 ) {
F_9 ( V_53 , L_22 , V_2 ) ;
F_42 ( V_59 , & V_2 -> V_60 ) ;
}
if ( V_27 & V_39 ) {
F_9 ( V_53 , L_23 , V_2 ) ;
F_42 ( V_77 , & V_2 -> V_60 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
int V_27 ;
if ( V_2 -> V_12 < 0 )
return;
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_27 < 0 || V_27 & ( V_89 | V_90 | V_91 ) ) {
F_9 ( V_53 , L_24 , V_2 , V_27 ) ;
if ( V_27 >= 0 )
V_27 = - V_92 ;
F_7 ( V_2 , V_27 ) ;
}
if ( V_27 & V_40 ) {
F_42 ( V_59 , & V_2 -> V_60 ) ;
F_9 ( V_53 , L_22 , V_2 ) ;
if ( ! F_26 ( V_68 , & V_2 -> V_60 ) ) {
F_9 ( V_53 , L_14 , V_2 ) ;
F_27 ( & V_2 -> V_52 ) ;
}
}
if ( V_27 & V_39 ) {
F_42 ( V_77 , & V_2 -> V_60 ) ;
F_9 ( V_53 , L_23 , V_2 ) ;
if ( ( V_2 -> V_71 || ! F_24 ( & V_2 -> V_72 ) ) &&
! F_26 ( V_70 , & V_2 -> V_60 ) ) {
F_9 ( V_53 , L_19 , V_2 ) ;
F_27 ( & V_2 -> V_69 ) ;
}
}
}
static int F_44 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
int V_27 ;
struct V_28 * V_29 = V_18 -> V_32 ;
struct V_1 * V_2 = & V_29 -> V_81 ;
F_9 ( V_53 , L_25 ,
V_2 , V_93 , V_14 -> V_75 , V_14 -> V_75 -> V_94 ) ;
if ( V_2 -> V_12 < 0 )
return V_2 -> V_12 ;
F_22 ( & V_18 -> V_19 ) ;
V_14 -> V_30 = V_95 ;
F_34 ( & V_14 -> V_20 , & V_2 -> V_72 ) ;
F_23 ( & V_18 -> V_19 ) ;
if ( F_25 ( V_77 , & V_2 -> V_60 ) )
V_27 = V_39 ;
else
V_27 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_27 & V_39 && ! F_26 ( V_70 , & V_2 -> V_60 ) )
F_27 ( & V_2 -> V_69 ) ;
return 0 ;
}
static int F_45 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
int V_26 = 1 ;
F_9 ( V_53 , L_26 , V_18 , V_14 ) ;
F_22 ( & V_18 -> V_19 ) ;
if ( V_14 -> V_30 == V_95 ) {
F_12 ( & V_14 -> V_20 ) ;
V_14 -> V_30 = V_96 ;
V_26 = 0 ;
}
F_23 ( & V_18 -> V_19 ) ;
return V_26 ;
}
static int F_46 ( struct V_23 * V_18 , struct V_13 * V_14 )
{
F_9 ( V_53 , L_26 , V_18 , V_14 ) ;
F_22 ( & V_18 -> V_19 ) ;
F_12 ( & V_14 -> V_20 ) ;
F_23 ( & V_18 -> V_19 ) ;
return 0 ;
}
static int F_47 ( struct V_97 * V_2 , struct V_23 * V_98 )
{
if ( V_98 -> V_99 == & V_100 ) {
if ( V_98 -> V_101 . V_102 . V_103 != V_104 )
F_48 ( V_2 , L_27 , V_98 -> V_101 . V_102 . V_103 ) ;
} else if ( V_98 -> V_99 == & V_105 ) {
if ( V_98 -> V_101 . V_106 . V_107 != ~ 0 )
F_48 ( V_2 , L_28 , V_98 -> V_101 . V_106 . V_107 ) ;
if ( V_98 -> V_101 . V_106 . V_108 != ~ 0 )
F_48 ( V_2 , L_29 , V_98 -> V_101 . V_106 . V_108 ) ;
}
return 0 ;
}
static int F_49 ( char * V_109 , struct V_110 * V_111 )
{
char * V_87 ;
T_6 args [ V_112 ] ;
int V_113 ;
char * V_114 , * V_115 ;
V_111 -> V_103 = V_104 ;
V_111 -> V_107 = ~ 0 ;
V_111 -> V_108 = ~ 0 ;
V_111 -> V_116 = false ;
if ( ! V_109 )
return 0 ;
V_115 = F_50 ( V_109 , V_117 ) ;
if ( ! V_115 ) {
F_9 ( V_17 ,
L_30 ) ;
return - V_118 ;
}
V_114 = V_115 ;
while ( ( V_87 = F_51 ( & V_114 , L_31 ) ) != NULL ) {
int V_119 ;
int V_120 ;
if ( ! * V_87 )
continue;
V_119 = F_52 ( V_87 , V_121 , args ) ;
if ( ( V_119 != V_122 ) && ( V_119 != V_123 ) ) {
V_120 = F_53 ( & args [ 0 ] , & V_113 ) ;
if ( V_120 < 0 ) {
F_9 ( V_17 ,
L_32 ) ;
continue;
}
}
switch ( V_119 ) {
case V_124 :
V_111 -> V_103 = V_113 ;
break;
case V_125 :
V_111 -> V_107 = V_113 ;
break;
case V_126 :
V_111 -> V_108 = V_113 ;
break;
case V_123 :
V_111 -> V_116 = true ;
break;
default:
continue;
}
}
F_54 ( V_115 ) ;
return 0 ;
}
static int F_55 ( struct V_23 * V_18 , int V_107 , int V_108 )
{
struct V_28 * V_29 = F_56 ( sizeof( struct V_28 ) ,
V_117 ) ;
if ( ! V_29 )
return - V_118 ;
V_29 -> V_34 = F_57 ( V_107 ) ;
V_29 -> V_38 = F_57 ( V_108 ) ;
if ( ! V_29 -> V_34 || ! V_29 -> V_38 ) {
if ( V_29 -> V_34 )
F_58 ( V_29 -> V_34 ) ;
if ( V_29 -> V_38 )
F_58 ( V_29 -> V_38 ) ;
F_54 ( V_29 ) ;
return - V_37 ;
}
V_18 -> V_32 = V_29 ;
V_18 -> V_30 = V_31 ;
return 0 ;
}
static int F_59 ( struct V_23 * V_18 , struct V_127 * V_128 )
{
struct V_28 * V_87 ;
struct V_84 * V_84 ;
V_87 = F_56 ( sizeof( struct V_28 ) , V_117 ) ;
if ( ! V_87 )
return - V_118 ;
V_128 -> V_129 -> V_130 = V_131 ;
V_84 = F_60 ( V_128 , 0 , NULL ) ;
if ( F_61 ( V_84 ) ) {
F_62 ( L_33 ,
V_132 , F_63 ( V_93 ) ) ;
F_64 ( V_128 ) ;
F_54 ( V_87 ) ;
return F_65 ( V_84 ) ;
}
F_66 ( V_84 ) ;
V_87 -> V_38 = V_87 -> V_34 = V_84 ;
V_18 -> V_32 = V_87 ;
V_18 -> V_30 = V_31 ;
V_87 -> V_34 -> V_45 |= V_46 ;
F_38 ( V_18 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_9 ( V_53 , L_34 ,
V_2 , V_2 -> V_88 . V_133 , V_2 -> V_88 . V_73 ) ;
F_1 ( V_2 ) ;
F_68 ( & V_2 -> V_52 ) ;
F_68 ( & V_2 -> V_69 ) ;
F_7 ( V_2 , - V_92 ) ;
V_2 -> V_18 = NULL ;
}
static void F_69 ( struct V_23 * V_18 )
{
struct V_28 * V_29 ;
if ( ! V_18 )
return;
V_29 = V_18 -> V_32 ;
if ( ! V_29 )
return;
V_18 -> V_30 = V_44 ;
F_67 ( & V_29 -> V_81 ) ;
if ( V_29 -> V_34 )
F_58 ( V_29 -> V_34 ) ;
if ( V_29 -> V_38 )
F_58 ( V_29 -> V_38 ) ;
F_54 ( V_29 ) ;
}
static inline int F_70 ( const char * V_134 )
{
int V_54 , V_135 , V_136 [ 4 ] ;
V_54 = sscanf ( V_134 , L_35 , & V_136 [ 0 ] , & V_136 [ 1 ] , & V_136 [ 2 ] , & V_136 [ 3 ] ) ;
if ( V_54 != 4 )
return - V_137 ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
if ( V_136 [ V_135 ] > 255 )
return - V_137 ;
}
return 0 ;
}
static int F_71 ( struct V_127 * V_138 )
{
struct V_139 V_140 ;
int V_103 , V_12 = - V_137 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_141 = V_142 ;
V_140 . V_143 . V_144 = V_145 ;
for ( V_103 = V_146 ; V_103 >= V_147 ; V_103 -- ) {
V_140 . V_148 = F_72 ( ( V_149 ) V_103 ) ;
V_12 = F_73 ( V_138 , (struct V_150 * ) & V_140 , sizeof( V_140 ) ) ;
if ( V_12 != - V_151 )
break;
}
return V_12 ;
}
static int
F_74 ( struct V_23 * V_18 , const char * V_152 , char * args )
{
int V_12 ;
struct V_127 * V_128 ;
struct V_139 V_153 ;
struct V_110 V_111 ;
V_12 = F_49 ( args , & V_111 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_70 ( V_152 ) < 0 )
return - V_137 ;
V_128 = NULL ;
V_18 -> V_101 . V_102 . V_103 = V_111 . V_103 ;
V_18 -> V_101 . V_102 . V_116 = V_111 . V_116 ;
V_153 . V_141 = V_142 ;
V_153 . V_143 . V_144 = F_75 ( V_152 ) ;
V_153 . V_148 = F_72 ( V_111 . V_103 ) ;
V_12 = F_76 ( V_93 -> V_154 -> V_155 , V_156 ,
V_157 , V_158 , & V_128 , 1 ) ;
if ( V_12 ) {
F_62 ( L_36 ,
V_132 , F_63 ( V_93 ) ) ;
return V_12 ;
}
if ( V_111 . V_116 ) {
V_12 = F_71 ( V_128 ) ;
if ( V_12 < 0 ) {
F_62 ( L_37 ,
V_132 , F_63 ( V_93 ) ) ;
F_64 ( V_128 ) ;
return V_12 ;
}
}
V_12 = V_128 -> V_159 -> V_160 ( V_128 ,
(struct V_150 * ) & V_153 ,
sizeof( struct V_139 ) , 0 ) ;
if ( V_12 < 0 ) {
F_62 ( L_38 ,
V_132 , F_63 ( V_93 ) , V_152 ) ;
F_64 ( V_128 ) ;
return V_12 ;
}
return F_59 ( V_18 , V_128 ) ;
}
static int
F_77 ( struct V_23 * V_18 , const char * V_152 , char * args )
{
int V_12 ;
struct V_127 * V_128 ;
struct V_161 V_162 ;
V_128 = NULL ;
if ( strlen ( V_152 ) >= V_163 ) {
F_62 ( L_39 ,
V_132 , F_63 ( V_93 ) , V_152 ) ;
return - V_164 ;
}
V_162 . V_165 = V_166 ;
strcpy ( V_162 . V_167 , V_152 ) ;
V_12 = F_76 ( V_93 -> V_154 -> V_155 , V_166 ,
V_157 , 0 , & V_128 , 1 ) ;
if ( V_12 < 0 ) {
F_62 ( L_36 ,
V_132 , F_63 ( V_93 ) ) ;
return V_12 ;
}
V_12 = V_128 -> V_159 -> V_160 ( V_128 , (struct V_150 * ) & V_162 ,
sizeof( struct V_161 ) - 1 , 0 ) ;
if ( V_12 < 0 ) {
F_62 ( L_40 ,
V_132 , F_63 ( V_93 ) , V_152 , V_12 ) ;
F_64 ( V_128 ) ;
return V_12 ;
}
return F_59 ( V_18 , V_128 ) ;
}
static int
F_78 ( struct V_23 * V_18 , const char * V_152 , char * args )
{
int V_12 ;
struct V_110 V_111 ;
F_49 ( args , & V_111 ) ;
V_18 -> V_101 . V_106 . V_107 = V_111 . V_107 ;
V_18 -> V_101 . V_106 . V_108 = V_111 . V_108 ;
if ( V_111 . V_107 == ~ 0 || V_111 . V_108 == ~ 0 ) {
F_62 ( L_41 ) ;
return - V_168 ;
}
V_12 = F_55 ( V_18 , V_111 . V_107 , V_111 . V_108 ) ;
if ( V_12 < 0 )
return V_12 ;
F_38 ( V_18 ) ;
return 0 ;
}
static void F_79 ( struct V_50 * V_51 )
{
unsigned long V_3 ;
F_9 ( V_53 , L_42 , V_93 ) ;
F_4 ( & V_10 , V_3 ) ;
while ( ! F_24 ( & V_82 ) ) {
struct V_1 * V_81 = F_80 ( & V_82 ,
struct V_1 ,
V_11 ) ;
F_5 ( & V_81 -> V_11 ) ;
F_6 ( & V_10 , V_3 ) ;
F_43 ( V_81 ) ;
F_4 ( & V_10 , V_3 ) ;
}
F_6 ( & V_10 , V_3 ) ;
F_9 ( V_53 , L_43 ) ;
}
int F_81 ( void )
{
F_82 ( & V_100 ) ;
F_82 ( & V_169 ) ;
F_82 ( & V_105 ) ;
return 0 ;
}
void F_83 ( void )
{
F_84 ( & V_83 ) ;
F_85 ( & V_100 ) ;
F_85 ( & V_169 ) ;
F_85 ( & V_105 ) ;
}
