static int F_1 ( struct V_1 * V_2 , int V_3 , unsigned long V_4 )
{
F_2 ( V_5 , V_6 ) ;
int V_7 = 0 ;
F_3 ( L_1 , V_2 ) ;
F_4 ( F_5 ( V_2 ) , & V_5 ) ;
F_6 ( V_8 ) ;
while ( V_2 -> V_9 != V_3 ) {
if ( ! V_4 ) {
V_7 = - V_10 ;
break;
}
if ( F_7 ( V_6 ) ) {
V_7 = F_8 ( V_4 ) ;
break;
}
F_9 ( V_2 ) ;
V_4 = F_10 ( V_4 ) ;
F_11 ( V_2 ) ;
F_6 ( V_8 ) ;
V_7 = F_12 ( V_2 ) ;
if ( V_7 )
break;
}
F_13 ( V_11 ) ;
F_14 ( F_5 ( V_2 ) , & V_5 ) ;
return V_7 ;
}
static int F_15 ( struct V_12 * V_1 , struct V_13 * V_14 , int V_15 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 V_23 ;
int V_24 , V_25 = 0 ;
if ( ! V_14 || V_14 -> V_26 != V_27 )
return - V_28 ;
F_3 ( L_2 , V_2 , V_14 , V_14 -> V_26 ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_24 = F_16 (unsigned int, sizeof(llcp_addr), alen) ;
memcpy ( & V_23 , V_14 , V_24 ) ;
if ( V_23 . V_29 != 0 )
return - V_28 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_9 != V_30 ) {
V_25 = - V_31 ;
goto error;
}
V_21 = F_17 ( V_23 . V_32 ) ;
if ( V_21 == NULL ) {
V_25 = - V_33 ;
goto error;
}
V_19 = F_18 ( V_21 ) ;
if ( V_19 == NULL ) {
V_25 = - V_33 ;
goto V_34;
}
V_17 -> V_21 = V_21 ;
V_17 -> V_19 = F_19 ( V_19 ) ;
V_17 -> V_35 = V_23 . V_35 ;
V_17 -> V_36 = F_16 (unsigned int,
llcp_addr.service_name_len,
NFC_LLCP_MAX_SERVICE_NAME) ;
V_17 -> V_37 = F_20 ( V_23 . V_37 ,
V_17 -> V_36 ,
V_38 ) ;
V_17 -> V_39 = F_21 ( V_19 , V_17 ) ;
if ( V_17 -> V_39 == V_40 ) {
V_25 = - V_41 ;
goto V_34;
}
V_17 -> V_42 = V_17 -> V_39 ;
F_22 ( & V_19 -> V_43 , V_2 ) ;
F_3 ( L_3 , V_17 -> V_39 ) ;
V_2 -> V_9 = V_44 ;
V_34:
F_23 ( V_21 ) ;
error:
F_9 ( V_2 ) ;
return V_25 ;
}
static int F_24 ( struct V_12 * V_1 , struct V_13 * V_14 ,
int V_15 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 V_23 ;
int V_24 , V_25 = 0 ;
if ( ! V_14 || V_14 -> V_26 != V_27 )
return - V_28 ;
F_3 ( L_2 , V_2 , V_14 , V_14 -> V_26 ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_24 = F_16 (unsigned int, sizeof(llcp_addr), alen) ;
memcpy ( & V_23 , V_14 , V_24 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_9 != V_30 ) {
V_25 = - V_31 ;
goto error;
}
V_21 = F_17 ( V_23 . V_32 ) ;
if ( V_21 == NULL ) {
V_25 = - V_33 ;
goto error;
}
V_19 = F_18 ( V_21 ) ;
if ( V_19 == NULL ) {
V_25 = - V_33 ;
goto V_34;
}
V_17 -> V_21 = V_21 ;
V_17 -> V_19 = F_19 ( V_19 ) ;
V_17 -> V_35 = V_23 . V_35 ;
F_22 ( & V_19 -> V_45 , V_2 ) ;
V_2 -> V_9 = V_44 ;
V_34:
F_23 ( V_21 ) ;
error:
F_9 ( V_2 ) ;
return V_25 ;
}
static int F_25 ( struct V_12 * V_1 , int V_46 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_25 = 0 ;
F_3 ( L_4 , V_2 , V_46 ) ;
F_11 ( V_2 ) ;
if ( ( V_1 -> type != V_47 && V_1 -> type != V_48 ) ||
V_2 -> V_9 != V_44 ) {
V_25 = - V_31 ;
goto error;
}
V_2 -> V_49 = V_46 ;
V_2 -> V_50 = 0 ;
F_3 ( L_5 ) ;
V_2 -> V_9 = V_51 ;
error:
F_9 ( V_2 ) ;
return V_25 ;
}
static int F_26 ( struct V_12 * V_1 , int V_52 , int V_53 ,
char T_1 * V_54 , unsigned int V_55 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
T_2 V_56 ;
int V_7 = 0 ;
F_3 ( L_6 , V_2 , V_53 ) ;
if ( V_52 != V_57 )
return - V_58 ;
F_11 ( V_2 ) ;
switch ( V_53 ) {
case V_59 :
if ( V_2 -> V_9 == V_60 ||
V_2 -> V_9 == V_44 ||
V_2 -> V_9 == V_51 ) {
V_7 = - V_28 ;
break;
}
if ( F_27 ( V_56 , ( T_2 T_1 * ) V_54 ) ) {
V_7 = - V_61 ;
break;
}
if ( V_56 > V_62 ) {
V_7 = - V_28 ;
break;
}
V_17 -> V_63 = ( V_64 ) V_56 ;
break;
case V_65 :
if ( V_2 -> V_9 == V_60 ||
V_2 -> V_9 == V_44 ||
V_2 -> V_9 == V_51 ) {
V_7 = - V_28 ;
break;
}
if ( F_27 ( V_56 , ( T_2 T_1 * ) V_54 ) ) {
V_7 = - V_61 ;
break;
}
if ( V_56 > V_66 ) {
V_7 = - V_28 ;
break;
}
V_17 -> V_67 = F_28 ( ( V_68 ) V_56 ) ;
break;
default:
V_7 = - V_58 ;
break;
}
F_9 ( V_2 ) ;
F_3 ( L_7 , V_17 ,
V_17 -> V_63 , V_17 -> V_67 ) ;
return V_7 ;
}
static int F_29 ( struct V_12 * V_1 , int V_52 , int V_53 ,
char T_1 * V_54 , int T_1 * V_55 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
int V_24 , V_7 = 0 ;
V_68 V_67 , V_69 ;
V_64 V_63 ;
F_3 ( L_6 , V_2 , V_53 ) ;
if ( V_52 != V_57 )
return - V_58 ;
if ( F_27 ( V_24 , V_55 ) )
return - V_61 ;
V_19 = V_17 -> V_19 ;
if ( ! V_19 )
return - V_33 ;
V_24 = F_16 ( T_2 , V_24 , sizeof( T_2 ) ) ;
F_11 ( V_2 ) ;
switch ( V_53 ) {
case V_59 :
V_63 = V_17 -> V_63 > V_62 ? V_19 -> V_63 : V_17 -> V_63 ;
if ( F_30 ( V_63 , ( T_2 T_1 * ) V_54 ) )
V_7 = - V_61 ;
break;
case V_65 :
V_67 = F_31 ( V_17 -> V_67 ) > V_66 ?
F_31 ( V_19 -> V_67 ) : F_31 ( V_17 -> V_67 ) ;
if ( F_30 ( V_67 , ( T_2 T_1 * ) V_54 ) )
V_7 = - V_61 ;
break;
case V_70 :
V_69 = V_17 -> V_69 > V_71 ?
V_19 -> V_69 : V_17 -> V_69 ;
if ( F_30 ( V_69 , ( T_2 T_1 * ) V_54 ) )
V_7 = - V_61 ;
break;
case V_72 :
if ( F_30 ( V_19 -> V_73 / 10 , ( T_2 T_1 * ) V_54 ) )
V_7 = - V_61 ;
break;
case V_74 :
if ( F_30 ( V_17 -> V_75 , ( T_2 T_1 * ) V_54 ) )
V_7 = - V_61 ;
break;
default:
V_7 = - V_58 ;
break;
}
F_9 ( V_2 ) ;
if ( F_30 ( V_24 , V_55 ) )
return - V_61 ;
return V_7 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
F_3 ( L_8 , V_2 -> V_9 ) ;
F_33 ( & V_17 -> V_76 ) ;
F_34 ( V_17 -> V_77 ) ;
V_17 -> V_77 = NULL ;
F_35 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_77 , struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_16 * V_78 = V_16 ( V_77 ) ;
F_37 ( V_2 ) ;
F_38 ( & V_17 -> V_76 ,
& V_78 -> V_76 ) ;
V_17 -> V_77 = V_77 ;
F_39 ( V_77 ) ;
}
struct V_1 * F_40 ( struct V_1 * V_77 ,
struct V_12 * V_79 )
{
struct V_16 * V_80 , * V_81 , * V_82 ;
struct V_1 * V_2 ;
V_82 = V_16 ( V_77 ) ;
F_41 (lsk, n, &llcp_parent->accept_queue,
accept_queue) {
V_2 = & V_80 -> V_2 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_9 == V_30 ) {
F_9 ( V_2 ) ;
F_32 ( V_2 ) ;
continue;
}
if ( V_2 -> V_9 == V_60 || ! V_79 ) {
F_33 ( & V_80 -> V_76 ) ;
F_35 ( V_2 ) ;
if ( V_79 )
F_42 ( V_2 , V_79 ) ;
F_9 ( V_2 ) ;
F_3 ( L_9 , V_2 -> V_9 ) ;
F_34 ( V_77 ) ;
return V_2 ;
}
F_9 ( V_2 ) ;
}
return NULL ;
}
static int F_43 ( struct V_12 * V_1 , struct V_12 * V_79 ,
int V_83 )
{
F_2 ( V_5 , V_6 ) ;
struct V_1 * V_2 = V_1 -> V_2 , * V_84 ;
long V_4 ;
int V_25 = 0 ;
F_3 ( L_10 , V_2 ) ;
F_44 ( V_2 , V_85 ) ;
if ( V_2 -> V_9 != V_51 ) {
V_25 = - V_31 ;
goto error;
}
V_4 = F_45 ( V_2 , V_83 & V_86 ) ;
F_46 ( F_5 ( V_2 ) , & V_5 ) ;
while ( ! ( V_84 = F_40 ( V_2 , V_79 ) ) ) {
F_6 ( V_8 ) ;
if ( ! V_4 ) {
V_25 = - V_87 ;
break;
}
if ( F_7 ( V_6 ) ) {
V_25 = F_8 ( V_4 ) ;
break;
}
F_9 ( V_2 ) ;
V_4 = F_10 ( V_4 ) ;
F_44 ( V_2 , V_85 ) ;
}
F_13 ( V_11 ) ;
F_14 ( F_5 ( V_2 ) , & V_5 ) ;
if ( V_25 )
goto error;
V_79 -> V_3 = V_88 ;
F_3 ( L_11 , V_84 ) ;
error:
F_9 ( V_2 ) ;
return V_25 ;
}
static int F_47 ( struct V_12 * V_1 , struct V_13 * V_89 ,
int * V_24 , int V_90 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
F_48 ( struct V_22 * , V_23 , V_89 ) ;
if ( V_17 == NULL || V_17 -> V_21 == NULL )
return - V_31 ;
F_3 ( L_12 , V_2 , V_17 -> V_91 ,
V_17 -> V_29 , V_17 -> V_39 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
* V_24 = sizeof( struct V_22 ) ;
V_23 -> V_26 = V_27 ;
V_23 -> V_32 = V_17 -> V_21 -> V_92 ;
V_23 -> V_91 = V_17 -> V_91 ;
V_23 -> V_35 = V_17 -> V_35 ;
V_23 -> V_29 = V_17 -> V_29 ;
V_23 -> V_39 = V_17 -> V_39 ;
V_23 -> V_36 = V_17 -> V_36 ;
memcpy ( V_23 -> V_37 , V_17 -> V_37 ,
V_23 -> V_36 ) ;
return 0 ;
}
static inline unsigned int F_49 ( struct V_1 * V_77 )
{
struct V_16 * V_17 , * V_93 ;
struct V_1 * V_2 ;
V_93 = V_16 ( V_77 ) ;
F_50 (llcp_sock, &parent_sock->accept_queue,
accept_queue) {
V_2 = & V_17 -> V_2 ;
if ( V_2 -> V_9 == V_60 )
return V_94 | V_95 ;
}
return 0 ;
}
static unsigned int F_51 ( struct V_96 * V_96 , struct V_12 * V_1 ,
T_3 * V_5 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_97 = 0 ;
F_3 ( L_13 , V_2 ) ;
F_52 ( V_96 , F_5 ( V_2 ) , V_5 ) ;
if ( V_2 -> V_9 == V_51 )
return F_49 ( V_2 ) ;
if ( V_2 -> V_98 || ! F_53 ( & V_2 -> V_99 ) )
V_97 |= V_100 |
( F_54 ( V_2 , V_101 ) ? V_102 : 0 ) ;
if ( ! F_53 ( & V_2 -> V_103 ) )
V_97 |= V_94 | V_95 ;
if ( V_2 -> V_9 == V_30 )
V_97 |= V_104 ;
if ( V_2 -> V_105 & V_106 )
V_97 |= V_107 | V_94 | V_95 ;
if ( V_2 -> V_105 == V_108 )
V_97 |= V_104 ;
if ( F_55 ( V_2 ) && V_2 -> V_9 == V_60 )
V_97 |= V_109 | V_110 | V_111 ;
else
F_56 ( V_112 , & V_2 -> V_113 -> V_83 ) ;
F_3 ( L_14 , V_97 ) ;
return V_97 ;
}
static int F_57 ( struct V_12 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_18 * V_19 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
int V_7 = 0 ;
if ( ! V_2 )
return 0 ;
F_3 ( L_13 , V_2 ) ;
V_19 = V_17 -> V_19 ;
if ( V_19 == NULL ) {
V_7 = - V_33 ;
goto V_114;
}
F_11 ( V_2 ) ;
if ( V_2 -> V_9 == V_60 )
F_58 ( V_17 ) ;
if ( V_2 -> V_9 == V_51 ) {
struct V_16 * V_80 , * V_81 ;
struct V_1 * V_115 ;
F_41 (lsk, n, &llcp_sock->accept_queue,
accept_queue) {
V_115 = & V_80 -> V_2 ;
F_11 ( V_115 ) ;
F_58 ( V_80 ) ;
F_32 ( V_115 ) ;
F_9 ( V_115 ) ;
}
}
if ( V_17 -> V_42 < V_40 )
F_59 ( V_17 -> V_19 , V_17 -> V_39 ) ;
F_9 ( V_2 ) ;
if ( V_2 -> V_9 == V_116 )
return V_7 ;
if ( V_1 -> type == V_117 )
F_60 ( & V_19 -> V_45 , V_2 ) ;
else
F_60 ( & V_19 -> V_43 , V_2 ) ;
V_114:
F_61 ( V_2 ) ;
F_35 ( V_2 ) ;
return V_7 ;
}
static int F_62 ( struct V_12 * V_1 , struct V_13 * V_118 ,
int V_24 , int V_83 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_22 * V_14 = (struct V_22 * ) V_118 ;
struct V_20 * V_21 ;
struct V_18 * V_19 ;
int V_25 = 0 ;
F_3 ( L_15 , V_1 , V_2 , V_83 ) ;
if ( ! V_14 || V_24 < sizeof( struct V_119 ) ||
V_14 -> V_26 != V_27 )
return - V_28 ;
if ( V_14 -> V_36 == 0 && V_14 -> V_29 == 0 )
return - V_28 ;
F_3 ( L_16 , V_14 -> V_32 ,
V_14 -> V_91 , V_14 -> V_35 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_9 == V_60 ) {
V_25 = - V_120 ;
goto error;
}
V_21 = F_17 ( V_14 -> V_32 ) ;
if ( V_21 == NULL ) {
V_25 = - V_33 ;
goto error;
}
V_19 = F_18 ( V_21 ) ;
if ( V_19 == NULL ) {
V_25 = - V_33 ;
goto V_34;
}
F_63 ( & V_21 -> V_21 ) ;
if ( V_21 -> V_121 == false ) {
V_25 = - V_122 ;
F_64 ( & V_21 -> V_21 ) ;
goto V_34;
}
F_64 ( & V_21 -> V_21 ) ;
if ( V_19 -> V_123 == V_124 &&
V_14 -> V_91 != V_19 -> V_91 ) {
V_25 = - V_122 ;
goto V_34;
}
V_17 -> V_21 = V_21 ;
V_17 -> V_19 = F_19 ( V_19 ) ;
V_17 -> V_39 = F_65 ( V_19 ) ;
if ( V_17 -> V_39 == V_40 ) {
V_25 = - V_125 ;
goto V_34;
}
V_17 -> V_42 = V_17 -> V_39 ;
if ( V_14 -> V_36 == 0 )
V_17 -> V_29 = V_14 -> V_29 ;
else
V_17 -> V_29 = V_126 ;
V_17 -> V_35 = V_14 -> V_35 ;
V_17 -> V_36 = F_16 (unsigned int,
addr->service_name_len,
NFC_LLCP_MAX_SERVICE_NAME) ;
V_17 -> V_37 = F_20 ( V_14 -> V_37 ,
V_17 -> V_36 ,
V_38 ) ;
F_22 ( & V_19 -> V_127 , V_2 ) ;
V_25 = F_66 ( V_17 ) ;
if ( V_25 )
goto V_128;
V_2 -> V_9 = V_129 ;
V_25 = F_1 ( V_2 , V_60 ,
F_67 ( V_2 , V_83 & V_86 ) ) ;
if ( V_25 && V_25 != - V_10 )
goto V_128;
F_9 ( V_2 ) ;
return V_25 ;
V_128:
F_59 ( V_19 , V_17 -> V_39 ) ;
F_60 ( & V_19 -> V_127 , V_2 ) ;
V_34:
F_23 ( V_21 ) ;
error:
F_9 ( V_2 ) ;
return V_25 ;
}
static int F_68 ( struct V_130 * V_131 , struct V_12 * V_1 ,
struct V_132 * V_133 , T_4 V_24 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
int V_25 ;
F_3 ( L_17 , V_1 , V_2 ) ;
V_25 = F_12 ( V_2 ) ;
if ( V_25 )
return V_25 ;
if ( V_133 -> V_134 & V_135 )
return - V_136 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_137 == V_138 ) {
F_48 ( struct V_22 * , V_14 ,
V_133 -> V_139 ) ;
if ( V_133 -> V_140 < sizeof( * V_14 ) ) {
F_9 ( V_2 ) ;
return - V_28 ;
}
F_9 ( V_2 ) ;
return F_69 ( V_17 , V_14 -> V_29 , V_14 -> V_39 ,
V_133 , V_24 ) ;
}
if ( V_2 -> V_9 != V_60 ) {
F_9 ( V_2 ) ;
return - V_141 ;
}
F_9 ( V_2 ) ;
return F_70 ( V_17 , V_133 , V_24 ) ;
}
static int F_71 ( struct V_130 * V_131 , struct V_12 * V_1 ,
struct V_132 * V_133 , T_4 V_24 , int V_83 )
{
int V_142 = V_83 & V_143 ;
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_144 , V_145 ;
struct V_146 * V_147 , * V_148 ;
int V_7 = 0 ;
F_3 ( L_18 , V_2 , V_24 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_9 == V_30 &&
F_53 ( & V_2 -> V_103 ) ) {
F_9 ( V_2 ) ;
return 0 ;
}
F_9 ( V_2 ) ;
if ( V_83 & ( V_135 ) )
return - V_136 ;
V_147 = F_72 ( V_2 , V_83 , V_142 , & V_7 ) ;
if ( ! V_147 ) {
F_73 ( L_19 ,
V_2 -> V_9 , V_7 , F_12 ( V_2 ) ) ;
if ( V_2 -> V_105 & V_106 )
return 0 ;
return V_7 ;
}
V_145 = V_147 -> V_24 ;
V_144 = F_16 (unsigned int, rlen, len) ;
V_148 = V_147 ;
if ( F_74 ( V_148 , 0 , V_133 , V_144 ) ) {
if ( ! ( V_83 & V_149 ) )
F_75 ( & V_2 -> V_103 , V_147 ) ;
return - V_61 ;
}
F_76 ( V_133 , V_2 , V_147 ) ;
if ( V_2 -> V_137 == V_138 && V_133 -> V_139 ) {
struct V_150 * V_151 = F_77 ( V_147 ) ;
F_48 ( struct V_22 * , V_13 ,
V_133 -> V_139 ) ;
V_133 -> V_140 = sizeof( struct V_22 ) ;
F_3 ( L_20 , V_151 -> V_29 , V_151 -> V_39 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_26 = V_27 ;
V_13 -> V_35 = V_152 ;
V_13 -> V_29 = V_151 -> V_29 ;
V_13 -> V_39 = V_151 -> V_39 ;
}
if ( ! ( V_83 & V_149 ) ) {
if ( V_2 -> V_137 == V_48 ||
V_2 -> V_137 == V_138 ||
V_2 -> V_137 == V_117 ) {
F_78 ( V_147 , V_144 ) ;
if ( V_147 -> V_24 ) {
F_75 ( & V_2 -> V_103 , V_147 ) ;
goto V_153;
}
}
F_79 ( V_147 ) ;
}
V_153:
if ( V_2 -> V_137 == V_47 && ( V_83 & V_154 ) )
V_144 = V_145 ;
return V_144 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
F_3 ( L_13 , V_2 ) ;
if ( V_2 -> V_9 == V_60 )
F_23 ( V_17 -> V_21 ) ;
F_81 ( & V_2 -> V_103 ) ;
F_82 ( V_17 ) ;
if ( ! F_54 ( V_2 , V_155 ) ) {
F_73 ( L_21 , V_2 ) ;
return;
}
}
struct V_1 * F_83 ( struct V_12 * V_1 , int type , T_5 V_156 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
V_2 = F_84 ( & V_157 , V_158 , V_156 , & V_159 ) ;
if ( ! V_2 )
return NULL ;
V_17 = V_16 ( V_2 ) ;
F_85 ( V_1 , V_2 ) ;
V_2 -> V_9 = V_30 ;
V_2 -> V_160 = V_161 ;
V_2 -> V_137 = type ;
V_2 -> V_162 = F_80 ;
V_17 -> V_39 = 0 ;
V_17 -> V_29 = V_126 ;
V_17 -> V_63 = V_62 + 1 ;
V_17 -> V_67 = F_28 ( V_66 + 1 ) ;
V_17 -> V_163 = V_17 -> V_164 = 0 ;
V_17 -> V_165 = V_17 -> V_166 = 0 ;
V_17 -> V_167 = 1 ;
V_17 -> V_42 = V_40 ;
F_86 ( V_17 ) ;
F_87 ( & V_17 -> V_168 ) ;
F_87 ( & V_17 -> V_169 ) ;
F_88 ( & V_17 -> V_76 ) ;
if ( V_1 != NULL )
V_1 -> V_3 = V_170 ;
return V_2 ;
}
void F_82 ( struct V_16 * V_1 )
{
F_89 ( V_1 -> V_37 ) ;
F_81 ( & V_1 -> V_168 ) ;
F_81 ( & V_1 -> V_169 ) ;
F_33 ( & V_1 -> V_76 ) ;
V_1 -> V_77 = NULL ;
F_90 ( V_1 -> V_19 ) ;
}
static int F_91 ( struct V_171 * V_171 , struct V_12 * V_1 ,
const struct V_35 * V_172 )
{
struct V_1 * V_2 ;
F_3 ( L_13 , V_1 ) ;
if ( V_1 -> type != V_48 &&
V_1 -> type != V_138 &&
V_1 -> type != V_117 )
return - V_173 ;
if ( V_1 -> type == V_117 )
V_1 -> V_174 = & V_175 ;
else
V_1 -> V_174 = & V_176 ;
V_2 = F_83 ( V_1 , V_1 -> type , V_177 ) ;
if ( V_2 == NULL )
return - V_125 ;
return 0 ;
}
int T_6 F_92 ( void )
{
return F_93 ( & V_178 ) ;
}
void F_94 ( void )
{
F_95 ( & V_178 ) ;
}
