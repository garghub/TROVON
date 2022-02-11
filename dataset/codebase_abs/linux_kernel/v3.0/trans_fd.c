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
if ( ! V_30 -> V_34 -> V_35 || ! V_30 -> V_34 -> V_35 -> V_36 )
return - V_37 ;
if ( ! V_30 -> V_38 -> V_35 || ! V_30 -> V_38 -> V_35 -> V_36 )
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
F_9 ( V_52 , L_5 , V_2 ,
V_2 -> V_53 , V_2 -> V_56 , V_2 -> V_56 - V_2 -> V_53 ) ;
V_12 = F_15 ( V_2 -> V_18 , V_2 -> V_54 + V_2 -> V_53 ,
V_2 -> V_56 - V_2 -> V_53 ) ;
F_9 ( V_52 , L_6 , V_2 , V_12 ) ;
if ( V_12 == - V_48 ) {
F_19 ( V_59 , & V_2 -> V_58 ) ;
return;
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
if ( ! F_26 ( & V_2 -> V_23 ) ) {
if ( F_27 ( V_57 , & V_2 -> V_58 ) )
V_28 = V_40 ;
else
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_28 & V_40 ) {
F_9 ( V_52 , L_12 , V_2 ) ;
F_28 ( & V_2 -> V_51 ) ;
} else
F_19 ( V_59 , & V_2 -> V_58 ) ;
} else
F_19 ( V_59 , & V_2 -> V_58 ) ;
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_59 , & V_2 -> V_58 ) ;
}
static int F_29 ( struct V_24 * V_18 , void * V_41 , int V_42 )
{
int V_27 ;
T_2 V_71 ;
struct V_29 * V_30 = NULL ;
if ( V_18 && V_18 -> V_20 != V_43 )
V_30 = V_18 -> V_32 ;
if ( ! V_30 )
return - V_33 ;
if ( ! ( V_30 -> V_38 -> V_44 & V_45 ) )
F_9 ( V_17 , L_13 ) ;
V_71 = F_30 () ;
F_31 ( F_32 () ) ;
V_27 = F_33 ( V_30 -> V_38 , ( V_72 void V_73 * ) V_41 , V_42 , & V_30 -> V_38 -> V_46 ) ;
F_31 ( V_71 ) ;
if ( V_27 <= 0 && V_27 != - V_47 && V_27 != - V_48 )
V_18 -> V_20 = V_43 ;
return V_27 ;
}
static void F_34 ( struct V_49 * V_50 )
{
int V_28 , V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_2 = F_18 ( V_50 , struct V_1 , V_74 ) ;
if ( V_2 -> V_12 < 0 ) {
F_19 ( V_75 , & V_2 -> V_58 ) ;
return;
}
if ( ! V_2 -> V_76 ) {
if ( F_26 ( & V_2 -> V_77 ) ) {
F_19 ( V_75 , & V_2 -> V_58 ) ;
return;
}
F_24 ( & V_2 -> V_18 -> V_19 ) ;
V_14 = F_35 ( V_2 -> V_77 . V_78 , struct V_13 ,
V_23 ) ;
V_14 -> V_20 = V_64 ;
F_9 ( V_52 , L_14 , V_14 ) ;
F_36 ( & V_14 -> V_23 , & V_2 -> V_23 ) ;
V_2 -> V_79 = V_14 -> V_80 -> V_81 ;
V_2 -> V_76 = V_14 -> V_80 -> V_82 ;
V_2 -> V_83 = 0 ;
F_25 ( & V_2 -> V_18 -> V_19 ) ;
}
F_9 ( V_52 , L_15 , V_2 , V_2 -> V_83 ,
V_2 -> V_76 ) ;
F_19 ( V_84 , & V_2 -> V_58 ) ;
V_12 = F_29 ( V_2 -> V_18 , V_2 -> V_79 + V_2 -> V_83 , V_2 -> V_76 - V_2 -> V_83 ) ;
F_9 ( V_52 , L_16 , V_2 , V_12 ) ;
if ( V_12 == - V_48 ) {
F_19 ( V_75 , & V_2 -> V_58 ) ;
return;
}
if ( V_12 < 0 )
goto error;
else if ( V_12 == 0 ) {
V_12 = - V_33 ;
goto error;
}
V_2 -> V_83 += V_12 ;
if ( V_2 -> V_83 == V_2 -> V_76 )
V_2 -> V_83 = V_2 -> V_76 = 0 ;
if ( V_2 -> V_76 == 0 && ! F_26 ( & V_2 -> V_77 ) ) {
if ( F_27 ( V_84 , & V_2 -> V_58 ) )
V_28 = V_39 ;
else
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_28 & V_39 ) {
F_9 ( V_52 , L_17 , V_2 ) ;
F_28 ( & V_2 -> V_74 ) ;
} else
F_19 ( V_75 , & V_2 -> V_58 ) ;
} else
F_19 ( V_75 , & V_2 -> V_58 ) ;
return;
error:
F_7 ( V_2 , V_12 ) ;
F_19 ( V_75 , & V_2 -> V_58 ) ;
}
static int F_37 ( T_3 * V_9 , unsigned V_85 , int V_86 , void * V_87 )
{
struct V_6 * V_7 =
F_18 ( V_9 , struct V_6 , V_9 ) ;
struct V_1 * V_2 = V_7 -> V_88 ;
unsigned long V_3 ;
F_4 ( & V_10 , V_3 ) ;
if ( F_26 ( & V_2 -> V_11 ) )
F_38 ( & V_2 -> V_11 , & V_89 ) ;
F_6 ( & V_10 , V_3 ) ;
F_28 ( & V_90 ) ;
return 1 ;
}
static void
F_39 ( struct V_91 * V_92 , T_4 * V_93 , T_5 * V_94 )
{
struct V_1 * V_2 = F_18 ( V_94 , struct V_1 , V_26 ) ;
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
F_40 ( & V_7 -> V_9 , F_37 ) ;
F_41 ( V_93 , & V_7 -> V_9 ) ;
}
static struct V_1 * F_42 ( struct V_24 * V_18 )
{
int V_28 ;
struct V_1 * V_2 ;
F_9 ( V_52 , L_19 , V_18 ,
V_18 -> V_62 ) ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return F_44 ( - V_69 ) ;
F_45 ( & V_2 -> V_96 ) ;
V_2 -> V_18 = V_18 ;
F_45 ( & V_2 -> V_23 ) ;
F_45 ( & V_2 -> V_77 ) ;
F_46 ( & V_2 -> V_51 , F_17 ) ;
F_46 ( & V_2 -> V_74 , F_34 ) ;
F_45 ( & V_2 -> V_11 ) ;
F_47 ( & V_2 -> V_26 , F_39 ) ;
V_28 = F_14 ( V_18 , & V_2 -> V_26 ) ;
if ( V_28 & V_40 ) {
F_9 ( V_52 , L_20 , V_2 ) ;
F_48 ( V_57 , & V_2 -> V_58 ) ;
}
if ( V_28 & V_39 ) {
F_9 ( V_52 , L_21 , V_2 ) ;
F_48 ( V_84 , & V_2 -> V_58 ) ;
}
return V_2 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_12 < 0 )
return;
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_28 < 0 || V_28 & ( V_97 | V_98 | V_99 ) ) {
F_9 ( V_52 , L_22 , V_2 , V_28 ) ;
if ( V_28 >= 0 )
V_28 = - V_100 ;
F_7 ( V_2 , V_28 ) ;
}
if ( V_28 & V_40 ) {
F_48 ( V_57 , & V_2 -> V_58 ) ;
F_9 ( V_52 , L_20 , V_2 ) ;
if ( ! F_50 ( V_59 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_12 , V_2 ) ;
F_28 ( & V_2 -> V_51 ) ;
}
}
if ( V_28 & V_39 ) {
F_48 ( V_84 , & V_2 -> V_58 ) ;
F_9 ( V_52 , L_21 , V_2 ) ;
if ( ( V_2 -> V_76 || ! F_26 ( & V_2 -> V_77 ) ) &&
! F_50 ( V_75 , & V_2 -> V_58 ) ) {
F_9 ( V_52 , L_17 , V_2 ) ;
F_28 ( & V_2 -> V_74 ) ;
}
}
}
static int F_51 ( struct V_24 * V_18 , struct V_13 * V_14 )
{
int V_28 ;
struct V_29 * V_30 = V_18 -> V_32 ;
struct V_1 * V_2 = V_30 -> V_88 ;
F_9 ( V_52 , L_23 , V_2 ,
V_101 , V_14 -> V_80 , V_14 -> V_80 -> V_102 ) ;
if ( V_2 -> V_12 < 0 )
return V_2 -> V_12 ;
F_24 ( & V_18 -> V_19 ) ;
V_14 -> V_20 = V_103 ;
F_38 ( & V_14 -> V_23 , & V_2 -> V_77 ) ;
F_25 ( & V_18 -> V_19 ) ;
if ( F_27 ( V_84 , & V_2 -> V_58 ) )
V_28 = V_39 ;
else
V_28 = F_14 ( V_2 -> V_18 , NULL ) ;
if ( V_28 & V_39 && ! F_50 ( V_75 , & V_2 -> V_58 ) )
F_28 ( & V_2 -> V_74 ) ;
return 0 ;
}
static int F_52 ( struct V_24 * V_18 , struct V_13 * V_14 )
{
int V_27 = 1 ;
F_9 ( V_52 , L_24 , V_18 , V_14 ) ;
F_24 ( & V_18 -> V_19 ) ;
if ( V_14 -> V_20 == V_103 ) {
F_12 ( & V_14 -> V_23 ) ;
V_14 -> V_20 = V_104 ;
V_27 = 0 ;
} else if ( V_14 -> V_20 == V_64 )
V_14 -> V_20 = V_65 ;
F_25 ( & V_18 -> V_19 ) ;
return V_27 ;
}
static int F_53 ( char * V_105 , struct V_106 * V_107 )
{
char * V_94 ;
T_6 args [ V_108 ] ;
int V_109 ;
char * V_110 , * V_111 ;
V_107 -> V_112 = V_113 ;
V_107 -> V_114 = ~ 0 ;
V_107 -> V_115 = ~ 0 ;
if ( ! V_105 )
return 0 ;
V_111 = F_54 ( V_105 , V_95 ) ;
if ( ! V_111 ) {
F_9 ( V_17 ,
L_25 ) ;
return - V_69 ;
}
V_110 = V_111 ;
while ( ( V_94 = F_55 ( & V_110 , L_26 ) ) != NULL ) {
int V_116 ;
int V_117 ;
if ( ! * V_94 )
continue;
V_116 = F_56 ( V_94 , V_118 , args ) ;
if ( V_116 != V_119 ) {
V_117 = F_57 ( & args [ 0 ] , & V_109 ) ;
if ( V_117 < 0 ) {
F_9 ( V_17 ,
L_27 ) ;
continue;
}
}
switch ( V_116 ) {
case V_120 :
V_107 -> V_112 = V_109 ;
break;
case V_121 :
V_107 -> V_114 = V_109 ;
break;
case V_122 :
V_107 -> V_115 = V_109 ;
break;
default:
continue;
}
}
F_58 ( V_111 ) ;
return 0 ;
}
static int F_59 ( struct V_24 * V_18 , int V_114 , int V_115 )
{
struct V_29 * V_30 = F_23 ( sizeof( struct V_29 ) ,
V_95 ) ;
if ( ! V_30 )
return - V_69 ;
V_30 -> V_34 = F_60 ( V_114 ) ;
V_30 -> V_38 = F_60 ( V_115 ) ;
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
static int F_62 ( struct V_24 * V_18 , struct V_123 * V_124 )
{
struct V_29 * V_94 ;
int V_27 , V_125 ;
V_94 = F_23 ( sizeof( struct V_29 ) , V_95 ) ;
if ( ! V_94 )
return - V_69 ;
V_124 -> V_126 -> V_127 = V_128 ;
V_125 = F_63 ( V_124 , 0 ) ;
if ( V_125 < 0 ) {
F_64 ( V_129 , L_28 ) ;
F_65 ( V_124 ) ;
F_58 ( V_94 ) ;
return V_125 ;
}
F_66 ( V_124 -> V_91 ) ;
F_66 ( V_124 -> V_91 ) ;
V_94 -> V_38 = V_94 -> V_34 = V_124 -> V_91 ;
V_18 -> V_32 = V_94 ;
V_18 -> V_20 = V_31 ;
F_67 ( V_125 ) ;
V_94 -> V_34 -> V_44 |= V_45 ;
V_94 -> V_88 = F_42 ( V_18 ) ;
if ( F_68 ( V_94 -> V_88 ) ) {
V_27 = F_69 ( V_94 -> V_88 ) ;
V_94 -> V_88 = NULL ;
F_58 ( V_94 ) ;
F_70 ( V_124 ) ;
F_70 ( V_124 ) ;
return V_27 ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_9 ( V_52 , L_29 , V_2 ,
V_2 -> V_96 . V_130 , V_2 -> V_96 . V_78 ) ;
F_1 ( V_2 ) ;
F_72 ( & V_2 -> V_51 ) ;
F_72 ( & V_2 -> V_74 ) ;
F_7 ( V_2 , - V_100 ) ;
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
F_71 ( V_30 -> V_88 ) ;
if ( V_30 -> V_34 )
F_61 ( V_30 -> V_34 ) ;
if ( V_30 -> V_38 )
F_61 ( V_30 -> V_38 ) ;
F_58 ( V_30 ) ;
}
static inline int F_74 ( const char * V_131 )
{
int V_66 , V_132 , V_133 [ 4 ] ;
V_66 = sscanf ( V_131 , L_30 , & V_133 [ 0 ] , & V_133 [ 1 ] , & V_133 [ 2 ] , & V_133 [ 3 ] ) ;
if ( V_66 != 4 )
return - V_134 ;
for ( V_132 = 0 ; V_132 < 4 ; V_132 ++ ) {
if ( V_133 [ V_132 ] > 255 )
return - V_134 ;
}
return 0 ;
}
static int
F_75 ( struct V_24 * V_18 , const char * V_135 , char * args )
{
int V_12 ;
struct V_123 * V_124 ;
struct V_136 V_137 ;
struct V_106 V_107 ;
V_12 = F_53 ( args , & V_107 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_74 ( V_135 ) < 0 )
return - V_134 ;
V_124 = NULL ;
V_137 . V_138 = V_139 ;
V_137 . V_140 . V_141 = F_76 ( V_135 ) ;
V_137 . V_142 = F_77 ( V_107 . V_112 ) ;
V_12 = F_78 ( F_79 ( & V_101 -> V_143 -> V_144 ) , V_145 ,
V_146 , V_147 , & V_124 , 1 ) ;
if ( V_12 ) {
F_64 ( V_129 , L_31 ) ;
return V_12 ;
}
V_12 = V_124 -> V_148 -> V_149 ( V_124 ,
(struct V_150 * ) & V_137 ,
sizeof( struct V_136 ) , 0 ) ;
if ( V_12 < 0 ) {
F_64 ( V_129 ,
L_32 ,
V_135 ) ;
F_65 ( V_124 ) ;
return V_12 ;
}
return F_62 ( V_18 , V_124 ) ;
}
static int
F_80 ( struct V_24 * V_18 , const char * V_135 , char * args )
{
int V_12 ;
struct V_123 * V_124 ;
struct V_151 V_152 ;
V_124 = NULL ;
if ( strlen ( V_135 ) >= V_153 ) {
F_64 ( V_129 , L_33 ,
V_135 ) ;
return - V_154 ;
}
V_152 . V_155 = V_156 ;
strcpy ( V_152 . V_157 , V_135 ) ;
V_12 = F_78 ( F_79 ( & V_101 -> V_143 -> V_144 ) , V_156 ,
V_146 , 0 , & V_124 , 1 ) ;
if ( V_12 < 0 ) {
F_64 ( V_129 , L_34 ) ;
return V_12 ;
}
V_12 = V_124 -> V_148 -> V_149 ( V_124 , (struct V_150 * ) & V_152 ,
sizeof( struct V_151 ) - 1 , 0 ) ;
if ( V_12 < 0 ) {
F_64 ( V_129 ,
L_35 ,
V_135 , V_12 ) ;
F_65 ( V_124 ) ;
return V_12 ;
}
return F_62 ( V_18 , V_124 ) ;
}
static int
F_81 ( struct V_24 * V_18 , const char * V_135 , char * args )
{
int V_12 ;
struct V_106 V_107 ;
struct V_29 * V_94 ;
F_53 ( args , & V_107 ) ;
if ( V_107 . V_114 == ~ 0 || V_107 . V_115 == ~ 0 ) {
F_82 ( V_129 L_36 ) ;
return - V_158 ;
}
V_12 = F_59 ( V_18 , V_107 . V_114 , V_107 . V_115 ) ;
if ( V_12 < 0 )
return V_12 ;
V_94 = (struct V_29 * ) V_18 -> V_32 ;
V_94 -> V_88 = F_42 ( V_18 ) ;
if ( F_68 ( V_94 -> V_88 ) ) {
V_12 = F_69 ( V_94 -> V_88 ) ;
V_94 -> V_88 = NULL ;
F_61 ( V_94 -> V_34 ) ;
F_61 ( V_94 -> V_38 ) ;
return V_12 ;
}
return 0 ;
}
static void F_83 ( struct V_49 * V_50 )
{
unsigned long V_3 ;
F_9 ( V_52 , L_37 , V_101 ) ;
F_4 ( & V_10 , V_3 ) ;
while ( ! F_26 ( & V_89 ) ) {
struct V_1 * V_88 = F_84 ( & V_89 ,
struct V_1 ,
V_11 ) ;
F_5 ( & V_88 -> V_11 ) ;
F_6 ( & V_10 , V_3 ) ;
F_49 ( V_88 ) ;
F_4 ( & V_10 , V_3 ) ;
}
F_6 ( & V_10 , V_3 ) ;
F_9 ( V_52 , L_38 ) ;
}
int F_85 ( void )
{
F_86 ( & V_159 ) ;
F_86 ( & V_160 ) ;
F_86 ( & V_161 ) ;
return 0 ;
}
void F_87 ( void )
{
F_88 ( & V_90 ) ;
F_89 ( & V_159 ) ;
F_89 ( & V_160 ) ;
F_89 ( & V_161 ) ;
}
