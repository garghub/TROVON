static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_2 -> V_3 ) ;
}
int F_5 ( T_1 V_4 , struct V_5 const * V_6 ,
T_1 V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_13 * V_15 = NULL ;
struct V_16 V_17 = { 0 , NULL , } ;
struct V_1 * V_18 = F_6 ( V_4 ) ;
int V_19 ;
int V_20 ;
if ( F_7 ( ! V_18 ) )
return - V_21 ;
V_12 = & V_18 -> V_3 ;
F_8 ( V_12 , V_22 ) ;
F_9 ( V_12 , V_23 ) ;
F_10 ( V_12 , 0 ) ;
F_11 ( V_12 , 0 ) ;
F_12 ( V_12 , V_6 -> type ) ;
F_13 ( V_12 , V_6 -> V_24 ) ;
F_14 ( V_12 , V_6 -> V_25 ) ;
F_15 ( V_12 , V_26 ) ;
V_20 = F_16 ( V_12 , V_9 , V_7 , V_10 , V_27 ,
! V_18 -> V_28 , & V_14 ) ;
if ( F_7 ( ! V_14 ) )
return V_20 ;
V_19 = F_17 ( V_6 -> type , V_6 -> V_24 , V_6 -> V_25 ,
V_29 , & V_17 ) ;
if ( V_19 ) {
if ( V_17 . V_30 != 0 ) {
V_15 = F_18 ( V_14 , V_31 ) ;
if ( V_15 == NULL ) {
F_19 ( & V_17 ) ;
F_20 ( V_14 ) ;
return - V_32 ;
}
}
V_20 = F_21 ( V_14 ) ;
if ( ( V_20 < 0 ) && ( V_17 . V_30 != 0 ) )
F_20 ( V_15 ) ;
} else {
V_15 = V_14 ;
}
if ( V_20 >= 0 ) {
if ( V_15 )
F_22 ( V_15 , & V_17 ) ;
} else {
F_19 ( & V_17 ) ;
}
return V_20 ;
}
void F_22 ( struct V_13 * V_14 , struct V_16 * V_33 )
{
struct V_11 * V_34 ;
struct V_16 V_17 = { 0 , NULL , } ;
struct V_16 * V_35 = V_33 ;
int V_36 = 0 ;
V_34 = F_23 ( V_14 ) ;
if ( V_33 == NULL ) {
F_17 ( F_24 ( V_34 ) ,
F_25 ( V_34 ) ,
F_26 ( V_34 ) ,
V_23 ,
& V_17 ) ;
V_35 = V_33 = & V_17 ;
}
if ( V_33 -> V_30 != 0 ) {
F_11 ( V_34 , V_37 ) ;
if ( V_33 -> V_30 == 1 ) {
F_10 ( V_34 , V_33 -> V_38 [ 0 ] ) ;
F_27 ( V_14 ) ;
F_19 ( V_33 ) ;
return;
}
for (; V_36 < V_33 -> V_30 ; V_36 ++ ) {
int V_39 = V_36 % V_40 ;
struct V_13 * V_41 = F_28 ( V_14 , V_31 ) ;
if ( V_41 == NULL ) {
F_29 ( L_1 ) ;
goto exit;
}
if ( ( V_39 == 0 ) && ( V_36 != 0 ) )
V_35 = V_35 -> V_42 ;
F_10 ( F_23 ( V_41 ) , V_35 -> V_38 [ V_39 ] ) ;
F_27 ( V_41 ) ;
}
}
exit:
F_20 ( V_14 ) ;
F_19 ( V_33 ) ;
}
struct V_1 * F_30 ( void * V_43 ,
T_1 (* F_31)( struct V_1 * , struct V_13 * ) ,
void (* F_32)( struct V_1 * ) ,
const T_1 V_44 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
T_1 V_4 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 ) {
F_29 ( L_2 ) ;
return NULL ;
}
V_4 = F_34 ( V_2 , & V_2 -> V_45 ) ;
if ( ! V_4 ) {
F_29 ( L_3 ) ;
F_35 ( V_2 ) ;
return NULL ;
}
V_2 -> V_43 = V_43 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_4 = V_4 ;
V_34 = & V_2 -> V_3 ;
F_36 ( V_34 , V_44 , V_48 , V_49 , 0 ) ;
F_37 ( V_34 , V_4 ) ;
F_38 ( & V_2 -> V_50 ) ;
F_38 ( & V_2 -> V_51 . V_52 ) ;
V_2 -> F_31 = F_31 ;
V_2 -> F_32 = F_32 ;
V_2 -> V_28 = NULL ;
F_39 ( & V_2 -> V_53 , ( V_54 ) V_55 , V_4 ) ;
F_40 ( & V_56 ) ;
F_38 ( & V_2 -> V_57 ) ;
F_38 ( & V_2 -> V_16 ) ;
F_41 ( & V_2 -> V_16 , & V_38 ) ;
F_42 ( & V_56 ) ;
return V_2 ;
}
int F_43 ( T_1 V_4 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 = NULL ;
F_44 ( V_4 , 0 , NULL ) ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_46 ( V_4 ) ;
F_47 ( V_2 ) ;
F_48 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_58 ) {
V_14 = F_49 ( V_2 , V_59 ) ;
F_50 ( & V_2 -> V_51 ) ;
}
F_35 ( V_2 -> V_28 ) ;
F_40 ( & V_56 ) ;
F_51 ( & V_2 -> V_16 ) ;
F_51 ( & V_2 -> V_50 ) ;
F_42 ( & V_56 ) ;
F_52 ( & V_2 -> V_53 ) ;
F_35 ( V_2 ) ;
F_53 ( V_14 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
return F_55 ( & V_2 -> V_3 ) ;
}
int F_56 ( T_1 V_4 , unsigned int * V_60 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
* V_60 = F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_57 ( T_1 V_4 , unsigned int V_60 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_58 ( & V_2 -> V_3 , ( V_60 != 0 ) ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
return F_60 ( & V_2 -> V_3 ) ;
}
int F_61 ( T_1 V_4 , unsigned int * V_61 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
* V_61 = F_59 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_62 ( T_1 V_4 , unsigned int V_61 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_63 ( & V_2 -> V_3 , ( V_61 != 0 ) ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static struct V_13 * F_64 ( struct V_1 * V_2 ,
T_1 type , T_1 V_62 )
{
struct V_13 * V_14 ;
struct V_11 * V_34 ;
V_14 = F_65 ( V_63 ) ;
if ( V_14 ) {
V_34 = F_23 ( V_14 ) ;
F_36 ( V_34 , V_64 , type , V_63 ,
F_1 ( V_2 ) ) ;
F_10 ( V_34 , F_3 ( V_2 ) ) ;
F_37 ( V_34 , V_2 -> V_4 ) ;
F_66 ( V_34 , V_62 ) ;
}
return V_14 ;
}
int F_67 ( struct V_13 * V_14 , T_1 V_65 )
{
struct V_11 * V_34 = F_23 ( V_14 ) ;
struct V_13 * V_66 ;
struct V_11 * V_67 ;
int V_68 ;
T_1 V_69 ;
T_1 V_70 = F_68 ( V_34 ) ;
T_1 V_71 ;
T_1 V_72 ;
if ( F_69 ( ! F_70 ( V_34 ) ,
L_4 , F_71 ( V_34 ) ) ) {
F_72 () ;
goto exit;
}
if ( F_73 ( V_34 ) || F_60 ( V_34 ) )
goto exit;
V_68 = F_74 ( V_34 ) ;
V_72 = V_68 + F_75 ( T_1 , V_70 , V_73 ) ;
V_66 = F_65 ( V_72 ) ;
if ( V_66 == NULL )
goto exit;
V_67 = F_23 ( V_66 ) ;
F_76 ( V_66 , V_34 , V_72 ) ;
if ( F_77 ( V_67 ) ) {
V_69 = F_78 ( V_67 ) ;
if ( V_69 < V_74 )
F_79 ( V_67 , ++ V_69 ) ;
}
F_80 ( V_67 , 0 ) ;
F_81 ( V_67 , V_72 ) ;
F_82 ( V_67 , V_65 ) ;
F_83 ( V_67 , V_37 ) ;
F_84 ( V_67 , 4 , 5 ) ;
if ( ! F_85 ( V_67 ) )
F_84 ( V_67 , 6 , 7 ) ;
if ( F_77 ( V_34 ) ) {
struct V_13 * V_75 = NULL ;
struct V_1 * V_2 = F_45 ( F_4 ( V_34 ) ) ;
if ( V_2 ) {
if ( V_2 -> V_58 )
V_75 = F_86 ( V_2 , V_65 ) ;
F_47 ( V_2 ) ;
}
F_53 ( V_75 ) ;
}
V_71 = F_87 ( V_34 ) ;
if ( V_71 == V_37 )
F_27 ( V_66 ) ;
else
F_88 ( V_66 , V_71 , F_89 ( V_67 ) ) ;
exit:
F_20 ( V_14 ) ;
return V_70 ;
}
int F_90 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_8 const * V_9 , T_1 V_7 ,
unsigned int V_10 , int V_65 )
{
struct V_13 * V_14 ;
int V_20 ;
V_20 = F_16 ( V_12 , V_9 , V_7 , V_10 , V_27 ,
! V_2 -> V_28 , & V_14 ) ;
if ( ! V_14 )
return V_20 ;
return F_67 ( V_14 , V_65 ) ;
}
static void V_55 ( unsigned long V_4 )
{
struct V_1 * V_2 = F_45 ( V_4 ) ;
struct V_13 * V_14 = NULL ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_58 ) {
F_47 ( V_2 ) ;
return;
}
if ( V_2 -> V_76 == V_77 ) {
V_14 = F_86 ( V_2 , V_59 ) ;
} else {
V_14 = F_64 ( V_2 , V_78 , 0 ) ;
V_2 -> V_76 = V_77 ;
F_91 ( & V_2 -> V_53 , V_2 -> V_79 ) ;
}
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
}
static void F_92 ( unsigned long V_4 )
{
struct V_1 * V_2 = F_45 ( V_4 ) ;
struct V_13 * V_14 = NULL ;
if ( ! V_2 )
return;
V_14 = F_86 ( V_2 , V_80 ) ;
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
}
static struct V_13 * F_86 ( struct V_1 * V_2 , T_1 V_65 )
{
struct V_13 * V_14 = F_49 ( V_2 , V_65 ) ;
if ( V_14 ) {
struct V_11 * V_34 = F_23 ( V_14 ) ;
F_84 ( V_34 , 4 , 5 ) ;
F_84 ( V_34 , 6 , 7 ) ;
}
return V_14 ;
}
static struct V_13 * F_49 ( struct V_1 * V_2 , T_1 V_65 )
{
struct V_13 * V_14 ;
struct V_11 * V_34 ;
T_1 V_69 ;
if ( ! V_2 -> V_58 )
return NULL ;
V_14 = F_65 ( V_81 ) ;
if ( V_14 ) {
V_34 = F_23 ( V_14 ) ;
memcpy ( V_34 , & V_2 -> V_3 , V_81 ) ;
F_15 ( V_34 , V_81 ) ;
F_81 ( V_34 , V_81 ) ;
V_69 = F_78 ( V_34 ) ;
if ( V_69 < V_74 )
F_79 ( V_34 , ++ V_69 ) ;
F_82 ( V_34 , V_65 ) ;
}
return V_14 ;
}
void F_93 ( struct V_13 * V_14 )
{
struct V_11 * V_34 = F_23 ( V_14 ) ;
struct V_1 * V_2 ;
struct V_13 * V_82 = NULL ;
T_1 V_83 = F_94 ( V_34 ) ;
T_1 V_84 = F_95 ( V_34 ) ;
T_1 V_85 = F_4 ( V_34 ) ;
int V_86 ;
V_2 = F_45 ( V_85 ) ;
if ( ! V_2 || ! V_2 -> V_58 ||
( F_1 ( V_2 ) != V_83 ) ||
( F_3 ( V_2 ) != V_84 ) ) {
V_82 = F_65 ( V_81 ) ;
if ( V_82 ) {
V_34 = F_23 ( V_82 ) ;
F_36 ( V_34 , V_87 , V_88 ,
V_81 , V_83 ) ;
F_82 ( V_34 , V_59 ) ;
F_37 ( V_34 , V_85 ) ;
F_10 ( V_34 , V_84 ) ;
}
if ( V_2 )
F_47 ( V_2 ) ;
goto exit;
}
switch ( F_96 ( V_34 ) ) {
case V_89 :
V_86 = F_97 ( V_2 ) && V_2 -> V_90 &&
V_2 -> F_32 ;
V_2 -> V_91 += F_98 ( V_34 ) ;
if ( ! F_97 ( V_2 ) ) {
V_2 -> V_90 = 0 ;
if ( V_86 )
V_2 -> F_32 ( V_2 ) ;
}
break;
case V_78 :
V_82 = F_64 ( V_2 , V_92 , 0 ) ;
break;
default:
break;
}
V_2 -> V_76 = V_93 ;
F_47 ( V_2 ) ;
exit:
F_53 ( V_82 ) ;
F_20 ( V_14 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_94 * V_14 , int V_95 )
{
struct V_96 * V_97 ;
if ( V_95 )
F_100 ( V_14 , L_5 ,
F_101 ( V_37 ) , F_102 ( V_37 ) ,
F_103 ( V_37 ) , V_2 -> V_4 ) ;
else
F_100 ( V_14 , L_6 , V_2 -> V_4 ) ;
if ( V_2 -> V_58 ) {
T_1 V_98 = F_3 ( V_2 ) ;
T_1 V_99 = F_1 ( V_2 ) ;
F_100 ( V_14 , L_7 ,
F_101 ( V_99 ) , F_102 ( V_99 ) ,
F_103 ( V_99 ) , V_98 ) ;
if ( V_2 -> V_100 != 0 )
F_100 ( V_14 , L_8 ,
V_2 -> V_100 ,
V_2 -> V_101 ) ;
} else if ( V_2 -> V_102 ) {
F_100 ( V_14 , L_9 ) ;
F_104 (publ, &p_ptr->publications, pport_list) {
if ( V_97 -> V_24 == V_97 -> V_25 )
F_100 ( V_14 , L_10 , V_97 -> type ,
V_97 -> V_24 ) ;
else
F_100 ( V_14 , L_11 , V_97 -> type ,
V_97 -> V_24 , V_97 -> V_25 ) ;
}
}
F_100 ( V_14 , L_12 ) ;
}
struct V_13 * F_105 ( void )
{
struct V_13 * V_14 ;
struct V_103 * V_104 ;
struct V_94 V_105 ;
struct V_1 * V_2 ;
int V_106 ;
V_14 = F_106 ( F_107 ( V_107 ) ) ;
if ( ! V_14 )
return NULL ;
V_104 = (struct V_103 * ) V_14 -> V_108 ;
F_108 ( & V_105 , F_109 ( V_104 ) , V_107 ) ;
F_40 ( & V_56 ) ;
F_104 (p_ptr, &ports, port_list) {
F_40 ( V_2 -> V_45 ) ;
F_99 ( V_2 , & V_105 , 0 ) ;
F_42 ( V_2 -> V_45 ) ;
}
F_42 ( & V_56 ) ;
V_106 = F_110 ( & V_105 ) ;
F_111 ( V_14 , F_107 ( V_106 ) ) ;
F_112 ( V_104 , V_109 , NULL , V_106 ) ;
return V_14 ;
}
void F_113 ( void )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
F_40 ( & V_56 ) ;
F_104 (p_ptr, &ports, port_list) {
V_34 = & V_2 -> V_3 ;
if ( F_94 ( V_34 ) == V_37 )
break;
F_83 ( V_34 , V_37 ) ;
F_114 ( V_34 , V_37 ) ;
}
F_42 ( & V_56 ) ;
}
static void F_115 ( void * V_110 )
{
struct V_13 * V_14 ;
F_40 ( & V_111 ) ;
V_14 = V_112 ;
V_112 = NULL ;
F_42 ( & V_111 ) ;
while ( V_14 ) {
struct V_1 * V_2 ;
struct V_28 * V_113 ;
struct V_114 V_115 ;
struct V_5 V_116 ;
void * V_43 ;
int V_58 ;
int V_102 ;
T_1 V_117 ;
struct V_13 * V_42 = V_14 -> V_42 ;
struct V_11 * V_34 = F_23 ( V_14 ) ;
T_1 V_118 = F_4 ( V_34 ) ;
V_117 = F_96 ( V_34 ) ;
if ( V_117 > V_119 )
goto V_120;
V_2 = F_45 ( V_118 ) ;
if ( ! V_2 )
goto V_120;
V_115 . V_4 = F_95 ( V_34 ) ;
V_115 . V_121 = F_94 ( V_34 ) ;
V_113 = V_2 -> V_28 ;
V_43 = V_113 -> V_43 ;
V_58 = V_2 -> V_58 ;
V_102 = V_2 -> V_102 ;
if ( F_7 ( F_73 ( V_34 ) ) )
goto V_65;
switch ( V_117 ) {
case V_88 : {
T_2 V_122 = V_113 -> V_123 ;
T_1 V_124 = F_3 ( V_2 ) ;
T_1 V_125 = F_1 ( V_2 ) ;
T_1 V_126 ;
F_47 ( V_2 ) ;
if ( F_7 ( ! V_122 ) )
goto V_120;
if ( F_7 ( ! V_58 ) ) {
if ( F_116 ( V_118 , & V_115 ) )
goto V_120;
} else if ( ( F_95 ( V_34 ) != V_124 ) ||
( F_94 ( V_34 ) != V_125 ) )
goto V_120;
V_126 = F_68 ( V_34 ) ;
if ( F_7 ( V_126 &&
( ++ V_2 -> V_127 >=
V_128 ) ) )
F_117 ( V_118 ,
V_2 -> V_127 ) ;
F_118 ( V_14 , F_74 ( V_34 ) ) ;
V_122 ( V_43 , V_118 , & V_14 , F_119 ( V_34 ) , V_126 ) ;
break;
}
case V_119 : {
T_3 V_122 = V_113 -> V_129 ;
F_47 ( V_2 ) ;
if ( F_7 ( ! V_122 || V_58 ) )
goto V_120;
F_118 ( V_14 , F_74 ( V_34 ) ) ;
V_122 ( V_43 , V_118 , & V_14 , F_119 ( V_34 ) ,
F_68 ( V_34 ) , F_78 ( V_34 ) ,
& V_115 ) ;
break;
}
case V_22 :
case V_48 : {
T_4 V_122 = V_113 -> V_130 ;
F_47 ( V_2 ) ;
if ( F_7 ( ! V_122 || V_58 || ! V_102 ) )
goto V_120;
V_116 . type = F_24 ( V_34 ) ;
V_116 . V_24 = F_120 ( V_34 ) ;
V_116 . V_25 = ( V_117 == V_48 )
? V_116 . V_24 : F_26 ( V_34 ) ;
F_118 ( V_14 , F_74 ( V_34 ) ) ;
V_122 ( V_43 , V_118 , & V_14 , F_119 ( V_34 ) ,
F_68 ( V_34 ) , F_78 ( V_34 ) ,
& V_115 , & V_116 ) ;
break;
}
}
if ( V_14 )
F_20 ( V_14 ) ;
V_14 = V_42 ;
continue;
V_65:
switch ( V_117 ) {
case V_88 : {
T_5 V_122 =
V_113 -> V_131 ;
T_1 V_124 = F_3 ( V_2 ) ;
T_1 V_125 = F_1 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( ! V_122 || ! V_58 )
break;
if ( ( F_95 ( V_34 ) != V_124 ) ||
( F_94 ( V_34 ) != V_125 ) )
break;
F_121 ( V_118 ) ;
F_118 ( V_14 , F_74 ( V_34 ) ) ;
V_122 ( V_43 , V_118 , & V_14 , F_119 ( V_34 ) ,
F_68 ( V_34 ) , F_73 ( V_34 ) ) ;
break;
}
case V_119 : {
T_6 V_122 = V_113 -> V_132 ;
F_47 ( V_2 ) ;
if ( ! V_122 || V_58 )
break;
F_118 ( V_14 , F_74 ( V_34 ) ) ;
V_122 ( V_43 , V_118 , & V_14 , F_119 ( V_34 ) ,
F_68 ( V_34 ) , F_73 ( V_34 ) , & V_115 ) ;
break;
}
case V_22 :
case V_48 : {
T_7 V_122 =
V_113 -> V_133 ;
F_47 ( V_2 ) ;
if ( ! V_122 || V_58 )
break;
V_116 . type = F_24 ( V_34 ) ;
V_116 . V_24 = F_120 ( V_34 ) ;
V_116 . V_25 = ( V_117 == V_48 )
? V_116 . V_24 : F_26 ( V_34 ) ;
F_118 ( V_14 , F_74 ( V_34 ) ) ;
V_122 ( V_43 , V_118 , & V_14 , F_119 ( V_34 ) ,
F_68 ( V_34 ) , F_73 ( V_34 ) , & V_116 ) ;
break;
}
}
if ( V_14 )
F_20 ( V_14 ) ;
V_14 = V_42 ;
continue;
V_120:
F_67 ( V_14 , V_59 ) ;
V_14 = V_42 ;
}
}
static T_1 F_122 ( struct V_1 * V_110 , struct V_13 * V_14 )
{
V_14 -> V_42 = NULL ;
F_40 ( & V_111 ) ;
if ( V_112 ) {
V_134 -> V_42 = V_14 ;
V_134 = V_14 ;
} else {
V_134 = V_112 = V_14 ;
F_123 ( ( V_54 ) F_115 , 0 ) ;
}
F_42 ( & V_111 ) ;
return 0 ;
}
static void F_124 ( unsigned long V_4 )
{
struct V_1 * V_2 ;
struct V_28 * V_113 ;
T_8 V_122 = NULL ;
void * V_135 = NULL ;
V_2 = F_45 ( V_4 ) ;
if ( V_2 ) {
V_113 = V_2 -> V_28 ;
if ( V_113 ) {
V_122 = V_113 -> V_136 ;
V_135 = V_113 -> V_43 ;
}
F_47 ( V_2 ) ;
}
if ( V_122 )
V_122 ( V_135 , V_4 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_123 ( ( V_54 ) F_124 , V_2 -> V_4 ) ;
}
void F_117 ( T_1 V_4 , T_1 V_62 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 = NULL ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return;
if ( V_2 -> V_58 ) {
V_2 -> V_127 -= V_62 ;
V_14 = F_64 ( V_2 , V_89 , V_62 ) ;
}
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
}
int F_126 ( void * V_43 ,
unsigned int V_44 ,
T_6 V_137 ,
T_7 V_138 ,
T_5 V_139 ,
T_3 V_129 ,
T_4 V_130 ,
T_2 V_123 ,
T_8 V_136 ,
T_1 * V_140 )
{
struct V_28 * V_113 ;
struct V_1 * V_2 ;
V_113 = F_127 ( sizeof( * V_113 ) , V_31 ) ;
if ( ! V_113 ) {
F_29 ( L_2 ) ;
return - V_32 ;
}
V_2 = (struct V_1 * ) F_30 ( NULL , F_122 ,
F_125 , V_44 ) ;
if ( ! V_2 ) {
F_35 ( V_113 ) ;
return - V_32 ;
}
V_2 -> V_28 = V_113 ;
V_113 -> V_43 = V_43 ;
V_113 -> V_4 = V_2 -> V_4 ;
V_113 -> V_132 = V_137 ;
V_113 -> V_133 = V_138 ;
V_113 -> V_131 = V_139 ;
V_113 -> V_129 = V_129 ;
V_113 -> V_130 = V_130 ;
V_113 -> V_123 = V_123 ;
V_113 -> V_136 = V_136 ;
* V_140 = V_2 -> V_4 ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_128 ( T_1 V_4 , unsigned int * V_44 )
{
struct V_1 * V_2 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
* V_44 = ( unsigned int ) F_78 ( & V_2 -> V_3 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_129 ( T_1 V_4 , unsigned int V_69 )
{
struct V_1 * V_2 ;
if ( V_69 > V_74 )
return - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
F_79 ( & V_2 -> V_3 , ( T_1 ) V_69 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_130 ( T_1 V_4 , unsigned int V_141 , struct V_5 const * V_6 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 ;
T_1 V_142 ;
int V_20 = - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
if ( V_2 -> V_58 )
goto exit;
if ( V_6 -> V_24 > V_6 -> V_25 )
goto exit;
if ( ( V_141 < V_143 ) || ( V_141 > V_29 ) )
goto exit;
V_142 = V_4 + V_2 -> V_144 + 1 ;
if ( V_142 == V_4 ) {
V_20 = - V_145 ;
goto exit;
}
V_97 = F_131 ( V_6 -> type , V_6 -> V_24 , V_6 -> V_25 ,
V_141 , V_2 -> V_4 , V_142 ) ;
if ( V_97 ) {
F_132 ( & V_97 -> V_146 , & V_2 -> V_57 ) ;
V_2 -> V_144 ++ ;
V_2 -> V_102 = 1 ;
V_20 = 0 ;
}
exit:
F_47 ( V_2 ) ;
return V_20 ;
}
int F_44 ( T_1 V_4 , unsigned int V_141 , struct V_5 const * V_6 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 ;
struct V_96 * V_147 ;
int V_20 = - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
if ( ! V_6 ) {
F_133 (publ, tpubl,
&p_ptr->publications, pport_list) {
F_134 ( V_97 -> type , V_97 -> V_24 ,
V_97 -> V_4 , V_97 -> V_142 ) ;
}
V_20 = 0 ;
} else {
F_133 (publ, tpubl,
&p_ptr->publications, pport_list) {
if ( V_97 -> V_141 != V_141 )
continue;
if ( V_97 -> type != V_6 -> type )
continue;
if ( V_97 -> V_24 != V_6 -> V_24 )
continue;
if ( V_97 -> V_25 != V_6 -> V_25 )
break;
F_134 ( V_97 -> type , V_97 -> V_24 ,
V_97 -> V_4 , V_97 -> V_142 ) ;
V_20 = 0 ;
break;
}
}
if ( F_135 ( & V_2 -> V_57 ) )
V_2 -> V_102 = 0 ;
F_47 ( V_2 ) ;
return V_20 ;
}
int F_116 ( T_1 V_4 , struct V_114 const * V_148 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
int V_20 = - V_21 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
if ( V_2 -> V_102 || V_2 -> V_58 )
goto exit;
if ( ! V_148 -> V_4 )
goto exit;
V_34 = & V_2 -> V_3 ;
F_11 ( V_34 , V_148 -> V_121 ) ;
F_10 ( V_34 , V_148 -> V_4 ) ;
F_114 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_2 -> V_4 ) ;
F_8 ( V_34 , V_88 ) ;
F_9 ( V_34 , 0 ) ;
F_15 ( V_34 , V_149 ) ;
V_2 -> V_79 = V_150 ;
V_2 -> V_76 = V_93 ;
V_2 -> V_58 = 1 ;
F_91 ( & V_2 -> V_53 , V_2 -> V_79 ) ;
F_136 ( & V_2 -> V_51 , V_148 -> V_121 ,
( void * ) ( unsigned long ) V_4 ,
( V_151 ) F_92 ) ;
V_20 = 0 ;
exit:
F_47 ( V_2 ) ;
V_2 -> V_46 = F_137 ( V_148 -> V_121 , V_4 ) ;
return V_20 ;
}
int F_138 ( struct V_1 * V_152 )
{
int V_20 ;
if ( V_152 -> V_58 ) {
V_152 -> V_58 = 0 ;
F_50 (
& ( (struct V_1 * ) V_152 ) -> V_51 ) ;
V_20 = 0 ;
} else {
V_20 = - V_153 ;
}
return V_20 ;
}
int F_121 ( T_1 V_4 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
V_20 = F_138 ( (struct V_1 * ) V_2 ) ;
F_47 ( V_2 ) ;
return V_20 ;
}
int F_139 ( T_1 V_4 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 = NULL ;
V_2 = F_45 ( V_4 ) ;
if ( ! V_2 )
return - V_21 ;
V_14 = F_49 ( V_2 , V_154 ) ;
F_47 ( V_2 ) ;
F_53 ( V_14 ) ;
return F_121 ( V_4 ) ;
}
static int F_140 ( struct V_1 * V_155 , unsigned int V_7 ,
struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_13 * V_14 ;
int V_20 ;
V_20 = F_16 ( & V_155 -> V_3 , V_9 , V_7 , V_10 ,
V_27 , ! V_155 -> V_28 , & V_14 ) ;
if ( F_141 ( V_14 ) )
F_27 ( V_14 ) ;
return V_20 ;
}
int F_142 ( T_1 V_4 , unsigned int V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 ;
T_1 V_99 ;
int V_20 ;
V_2 = F_6 ( V_4 ) ;
if ( ! V_2 || ! V_2 -> V_58 )
return - V_21 ;
V_2 -> V_90 = 1 ;
if ( ! F_97 ( V_2 ) ) {
V_99 = F_1 ( V_2 ) ;
if ( F_141 ( V_99 != V_37 ) )
V_20 = F_143 ( V_2 , V_9 , V_7 ,
V_10 , V_99 ) ;
else
V_20 = F_140 ( V_2 , V_7 , V_9 ,
V_10 ) ;
if ( F_141 ( V_20 != - V_156 ) ) {
V_2 -> V_90 = 0 ;
if ( V_20 > 0 )
V_2 -> V_157 ++ ;
return V_20 ;
}
}
if ( F_54 ( V_2 ) ) {
V_2 -> V_90 = 0 ;
return V_10 ;
}
return - V_156 ;
}
int F_144 ( T_1 V_4 , struct V_158 const * V_159 , unsigned int V_160 ,
unsigned int V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
T_1 V_99 = V_160 ;
T_1 V_85 ;
int V_20 ;
V_2 = F_6 ( V_4 ) ;
if ( ! V_2 || V_2 -> V_58 )
return - V_21 ;
V_34 = & V_2 -> V_3 ;
F_8 ( V_34 , V_48 ) ;
F_114 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_4 ) ;
F_15 ( V_34 , V_49 ) ;
F_12 ( V_34 , V_159 -> type ) ;
F_145 ( V_34 , V_159 -> V_161 ) ;
F_9 ( V_34 , F_146 ( V_160 ) ) ;
V_85 = F_147 ( V_159 -> type , V_159 -> V_161 , & V_99 ) ;
F_11 ( V_34 , V_99 ) ;
F_10 ( V_34 , V_85 ) ;
if ( F_141 ( V_85 ) ) {
if ( F_141 ( V_99 == V_37 ) )
V_20 = F_140 ( V_2 , V_7 ,
V_9 , V_10 ) ;
else
V_20 = F_143 ( V_2 , V_9 ,
V_7 , V_10 ,
V_99 ) ;
if ( F_141 ( V_20 != - V_156 ) ) {
if ( V_20 > 0 )
V_2 -> V_157 ++ ;
return V_20 ;
}
if ( F_54 ( V_2 ) ) {
return V_10 ;
}
return - V_156 ;
}
return F_90 ( V_2 , V_34 , V_9 , V_7 ,
V_10 , V_162 ) ;
}
int F_148 ( T_1 V_4 , struct V_114 const * V_163 ,
unsigned int V_7 , struct V_8 const * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
int V_20 ;
V_2 = F_6 ( V_4 ) ;
if ( ! V_2 || V_2 -> V_58 )
return - V_21 ;
V_34 = & V_2 -> V_3 ;
F_8 ( V_34 , V_119 ) ;
F_9 ( V_34 , 0 ) ;
F_114 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_4 ) ;
F_11 ( V_34 , V_163 -> V_121 ) ;
F_10 ( V_34 , V_163 -> V_4 ) ;
F_15 ( V_34 , V_81 ) ;
if ( V_163 -> V_121 == V_37 )
V_20 = F_140 ( V_2 , V_7 , V_9 ,
V_10 ) ;
else
V_20 = F_143 ( V_2 , V_9 , V_7 ,
V_10 , V_163 -> V_121 ) ;
if ( F_141 ( V_20 != - V_156 ) ) {
if ( V_20 > 0 )
V_2 -> V_157 ++ ;
return V_20 ;
}
if ( F_54 ( V_2 ) ) {
return V_10 ;
}
return - V_156 ;
}
int F_149 ( T_1 V_4 , struct V_114 const * V_163 ,
struct V_13 * V_14 , unsigned int V_126 )
{
struct V_1 * V_2 ;
struct V_11 * V_34 ;
int V_20 ;
V_2 = (struct V_1 * ) F_150 ( V_4 ) ;
if ( ! V_2 || V_2 -> V_58 )
return - V_21 ;
V_34 = & V_2 -> V_3 ;
F_8 ( V_34 , V_119 ) ;
F_114 ( V_34 , V_37 ) ;
F_37 ( V_34 , V_4 ) ;
F_11 ( V_34 , V_163 -> V_121 ) ;
F_10 ( V_34 , V_163 -> V_4 ) ;
F_15 ( V_34 , V_81 ) ;
F_81 ( V_34 , V_81 + V_126 ) ;
if ( F_151 ( V_14 , V_81 ) )
return - V_32 ;
F_152 ( V_14 , V_81 ) ;
F_76 ( V_14 , V_34 , V_81 ) ;
if ( V_163 -> V_121 == V_37 )
V_20 = F_27 ( V_14 ) ;
else
V_20 = F_153 ( V_14 , V_163 -> V_121 ) ;
if ( F_141 ( V_20 != - V_156 ) ) {
if ( V_20 > 0 )
V_2 -> V_157 ++ ;
return V_20 ;
}
if ( F_54 ( V_2 ) )
return V_126 ;
return - V_156 ;
}
