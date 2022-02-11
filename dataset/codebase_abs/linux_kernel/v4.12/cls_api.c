static const struct V_1 * F_1 ( const char * V_2 )
{
const struct V_1 * V_3 , * V_4 = NULL ;
if ( V_2 ) {
F_2 ( & V_5 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( strcmp ( V_2 , V_3 -> V_2 ) == 0 ) {
if ( F_4 ( V_3 -> V_6 ) )
V_4 = V_3 ;
break;
}
}
F_5 ( & V_5 ) ;
}
return V_4 ;
}
int F_6 ( struct V_1 * V_7 )
{
struct V_1 * V_3 ;
int V_8 = - V_9 ;
F_7 ( & V_5 ) ;
F_3 (t, &tcf_proto_base, head)
if ( ! strcmp ( V_7 -> V_2 , V_3 -> V_2 ) )
goto V_10;
F_8 ( & V_7 -> V_11 , & V_12 ) ;
V_8 = 0 ;
V_10:
F_9 ( & V_5 ) ;
return V_8 ;
}
int F_10 ( struct V_1 * V_7 )
{
struct V_1 * V_3 ;
int V_8 = - V_13 ;
F_11 () ;
F_7 ( & V_5 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( V_3 == V_7 ) {
F_12 ( & V_3 -> V_11 ) ;
V_8 = 0 ;
break;
}
}
F_9 ( & V_5 ) ;
return V_8 ;
}
static void F_13 ( struct V_14 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 T_1 * * V_20 , int V_21 )
{
struct V_19 T_1 * * V_22 ;
struct V_19 * V_23 ;
for ( V_22 = V_20 ; ( V_23 = F_14 ( * V_22 ) ) != NULL ;
V_22 = & V_23 -> V_24 )
F_15 ( V_14 , V_16 , V_18 , V_23 , 0 , V_21 , false ) ;
}
static inline T_2 F_16 ( struct V_19 * V_23 )
{
T_2 V_25 = F_17 ( 0xC0000000U , 0U ) ;
if ( V_23 )
V_25 = V_23 -> V_26 - 1 ;
return V_25 ;
}
static struct V_19 * F_18 ( const char * V_2 , T_2 V_27 ,
T_2 V_26 , T_2 V_28 , struct V_29 * V_30 )
{
struct V_19 * V_23 ;
int V_31 ;
V_23 = F_19 ( sizeof( * V_23 ) , V_32 ) ;
if ( ! V_23 )
return F_20 ( - V_33 ) ;
V_31 = - V_13 ;
V_23 -> V_7 = F_1 ( V_2 ) ;
if ( ! V_23 -> V_7 ) {
#ifdef F_21
F_22 () ;
F_23 ( L_1 , V_2 ) ;
F_24 () ;
V_23 -> V_7 = F_1 ( V_2 ) ;
if ( V_23 -> V_7 ) {
F_25 ( V_23 -> V_7 -> V_6 ) ;
V_31 = - V_34 ;
} else {
V_31 = - V_13 ;
}
goto V_35;
#endif
}
V_23 -> V_36 = V_23 -> V_7 -> V_36 ;
V_23 -> V_27 = V_27 ;
V_23 -> V_26 = V_26 ;
V_23 -> V_37 = V_28 ;
V_23 -> V_30 = V_30 ;
V_31 = V_23 -> V_7 -> V_38 ( V_23 ) ;
if ( V_31 ) {
F_25 ( V_23 -> V_7 -> V_6 ) ;
goto V_35;
}
return V_23 ;
V_35:
F_26 ( V_23 ) ;
return F_20 ( V_31 ) ;
}
static void F_27 ( struct V_19 * V_23 )
{
V_23 -> V_7 -> V_39 ( V_23 ) ;
F_25 ( V_23 -> V_7 -> V_6 ) ;
F_28 ( V_23 , V_40 ) ;
}
void F_29 ( struct V_19 T_1 * * V_41 )
{
struct V_19 * V_23 ;
while ( ( V_23 = F_14 ( * V_41 ) ) != NULL ) {
F_30 ( * V_41 , V_23 -> V_24 ) ;
F_27 ( V_23 ) ;
}
}
static int F_31 ( struct V_15 * V_42 , struct V_17 * V_18 ,
struct V_43 * V_44 )
{
struct V_14 * V_14 = F_32 ( V_42 -> V_45 ) ;
struct V_46 * V_47 [ V_48 + 1 ] ;
struct V_49 * V_3 ;
T_2 V_27 ;
T_2 V_26 ;
T_2 V_50 ;
T_2 V_28 ;
struct V_51 * V_52 ;
struct V_29 * V_30 ;
struct V_19 T_1 * * V_53 ;
struct V_19 T_1 * * V_20 ;
struct V_19 * V_24 ;
struct V_19 * V_23 ;
const struct V_54 * V_55 ;
unsigned long V_56 ;
unsigned long V_57 ;
int V_31 ;
int V_58 ;
if ( ( V_18 -> V_59 != V_60 ) &&
! F_33 ( V_42 , V_14 -> V_61 , V_62 ) )
return - V_63 ;
V_64:
V_58 = 0 ;
V_31 = F_34 ( V_18 , sizeof( * V_3 ) , V_47 , V_48 , NULL , V_44 ) ;
if ( V_31 < 0 )
return V_31 ;
V_3 = F_35 ( V_18 ) ;
V_27 = F_36 ( V_3 -> V_65 ) ;
V_26 = F_37 ( V_3 -> V_65 ) ;
V_50 = V_26 ;
V_28 = V_3 -> V_66 ;
V_56 = 0 ;
if ( V_26 == 0 ) {
switch ( V_18 -> V_59 ) {
case V_67 :
if ( V_27 || V_3 -> V_68 || V_47 [ V_69 ] )
return - V_13 ;
break;
case V_70 :
if ( V_18 -> V_71 & V_72 ) {
V_26 = F_17 ( 0x80000000U , 0U ) ;
break;
}
default:
return - V_13 ;
}
}
V_52 = F_38 ( V_14 , V_3 -> V_73 ) ;
if ( V_52 == NULL )
return - V_74 ;
if ( ! V_28 ) {
V_30 = V_52 -> V_75 ;
V_28 = V_30 -> V_76 ;
} else {
V_30 = F_39 ( V_52 , F_37 ( V_3 -> V_66 ) ) ;
if ( V_30 == NULL )
return - V_77 ;
}
V_55 = V_30 -> V_7 -> V_78 ;
if ( ! V_55 )
return - V_77 ;
if ( V_55 -> V_79 == NULL )
return - V_80 ;
if ( F_36 ( V_28 ) ) {
V_56 = V_55 -> V_81 ( V_30 , V_28 ) ;
if ( V_56 == 0 )
return - V_13 ;
}
V_20 = V_55 -> V_79 ( V_30 , V_56 ) ;
if ( V_20 == NULL ) {
V_31 = - V_77 ;
goto V_35;
}
if ( V_18 -> V_59 == V_67 && V_26 == 0 ) {
F_13 ( V_14 , V_42 , V_18 , V_20 , V_67 ) ;
F_29 ( V_20 ) ;
V_31 = 0 ;
goto V_35;
}
for ( V_53 = V_20 ;
( V_23 = F_14 ( * V_53 ) ) != NULL ;
V_53 = & V_23 -> V_24 ) {
if ( V_23 -> V_26 >= V_26 ) {
if ( V_23 -> V_26 == V_26 ) {
if ( ! V_50 ||
( V_23 -> V_27 != V_27 && V_27 ) ) {
V_31 = - V_77 ;
goto V_35;
}
} else {
V_23 = NULL ;
}
break;
}
}
if ( V_23 == NULL ) {
if ( V_47 [ V_69 ] == NULL || ! V_27 ) {
V_31 = - V_77 ;
goto V_35;
}
if ( V_18 -> V_59 != V_70 ||
! ( V_18 -> V_71 & V_72 ) ) {
V_31 = - V_13 ;
goto V_35;
}
if ( ! V_50 )
V_50 = F_37 ( F_16 ( F_14 ( * V_53 ) ) ) ;
V_23 = F_18 ( F_40 ( V_47 [ V_69 ] ) ,
V_27 , V_50 , V_28 , V_30 ) ;
if ( F_41 ( V_23 ) ) {
V_31 = F_42 ( V_23 ) ;
goto V_35;
}
V_58 = 1 ;
} else if ( V_47 [ V_69 ] && F_43 ( V_47 [ V_69 ] , V_23 -> V_7 -> V_2 ) ) {
V_31 = - V_77 ;
goto V_35;
}
V_57 = V_23 -> V_7 -> V_81 ( V_23 , V_3 -> V_68 ) ;
if ( V_57 == 0 ) {
if ( V_18 -> V_59 == V_67 && V_3 -> V_68 == 0 ) {
V_24 = F_14 ( V_23 -> V_24 ) ;
F_30 ( * V_53 , V_24 ) ;
F_15 ( V_14 , V_42 , V_18 , V_23 , V_57 ,
V_67 , false ) ;
F_27 ( V_23 ) ;
V_31 = 0 ;
goto V_35;
}
if ( V_18 -> V_59 != V_70 ||
! ( V_18 -> V_71 & V_72 ) ) {
V_31 = - V_13 ;
goto V_35;
}
} else {
bool V_82 ;
switch ( V_18 -> V_59 ) {
case V_70 :
if ( V_18 -> V_71 & V_83 ) {
if ( V_58 )
F_27 ( V_23 ) ;
V_31 = - V_9 ;
goto V_35;
}
break;
case V_67 :
V_31 = V_23 -> V_7 -> V_84 ( V_23 , V_57 , & V_82 ) ;
if ( V_31 )
goto V_35;
V_24 = F_14 ( V_23 -> V_24 ) ;
F_15 ( V_14 , V_42 , V_18 , V_23 , V_3 -> V_68 ,
V_67 , false ) ;
if ( V_82 ) {
F_30 ( * V_53 , V_24 ) ;
F_27 ( V_23 ) ;
}
goto V_35;
case V_60 :
V_31 = F_15 ( V_14 , V_42 , V_18 , V_23 , V_57 ,
V_70 , true ) ;
goto V_35;
default:
V_31 = - V_77 ;
goto V_35;
}
}
V_31 = V_23 -> V_7 -> V_85 ( V_14 , V_42 , V_23 , V_56 , V_3 -> V_68 , V_47 , & V_57 ,
V_18 -> V_71 & V_72 ? V_86 : V_87 ) ;
if ( V_31 == 0 ) {
if ( V_58 ) {
F_30 ( V_23 -> V_24 , F_14 ( * V_53 ) ) ;
F_44 ( * V_53 , V_23 ) ;
}
F_15 ( V_14 , V_42 , V_18 , V_23 , V_57 , V_70 , false ) ;
} else {
if ( V_58 )
F_27 ( V_23 ) ;
}
V_35:
if ( V_56 )
V_55 -> V_88 ( V_30 , V_56 ) ;
if ( V_31 == - V_34 )
goto V_64;
return V_31 ;
}
static int F_45 ( struct V_14 * V_14 , struct V_15 * V_42 ,
struct V_19 * V_23 , unsigned long V_57 , T_2 V_89 ,
T_2 V_90 , T_3 V_91 , int V_21 )
{
struct V_49 * V_92 ;
struct V_17 * V_93 ;
unsigned char * V_94 = F_46 ( V_42 ) ;
V_93 = F_47 ( V_42 , V_89 , V_90 , V_21 , sizeof( * V_92 ) , V_91 ) ;
if ( ! V_93 )
goto V_95;
V_92 = F_35 ( V_93 ) ;
V_92 -> V_96 = V_97 ;
V_92 -> V_98 = 0 ;
V_92 -> V_99 = 0 ;
V_92 -> V_73 = F_48 ( V_23 -> V_30 ) -> V_100 ;
V_92 -> V_66 = V_23 -> V_37 ;
V_92 -> V_65 = F_17 ( V_23 -> V_26 , V_23 -> V_27 ) ;
if ( F_49 ( V_42 , V_69 , V_23 -> V_7 -> V_2 ) )
goto V_101;
V_92 -> V_68 = V_57 ;
if ( V_67 != V_21 ) {
V_92 -> V_68 = 0 ;
if ( V_23 -> V_7 -> V_102 && V_23 -> V_7 -> V_102 ( V_14 , V_23 , V_57 , V_42 , V_92 ) < 0 )
goto V_101;
}
V_93 -> V_103 = F_46 ( V_42 ) - V_94 ;
return V_42 -> V_104 ;
V_95:
V_101:
F_50 ( V_42 , V_94 ) ;
return - 1 ;
}
static int F_15 ( struct V_14 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_19 * V_23 ,
unsigned long V_57 , int V_21 , bool V_105 )
{
struct V_15 * V_42 ;
T_2 V_89 = V_16 ? F_51 ( V_16 ) . V_89 : 0 ;
V_42 = F_52 ( V_106 , V_32 ) ;
if ( ! V_42 )
return - V_33 ;
if ( F_45 ( V_14 , V_42 , V_23 , V_57 , V_89 , V_18 -> V_107 ,
V_18 -> V_71 , V_21 ) <= 0 ) {
F_53 ( V_42 ) ;
return - V_77 ;
}
if ( V_105 )
return F_54 ( V_14 -> V_108 , V_42 , V_89 , V_109 ) ;
return F_55 ( V_42 , V_14 , V_89 , V_110 ,
V_18 -> V_71 & V_111 ) ;
}
static int F_56 ( struct V_19 * V_23 , unsigned long V_18 ,
struct V_112 * V_113 )
{
struct V_114 * V_115 = ( void * ) V_113 ;
struct V_14 * V_14 = F_32 ( V_115 -> V_42 -> V_45 ) ;
return F_45 ( V_14 , V_115 -> V_42 , V_23 , V_18 , F_51 ( V_115 -> V_116 -> V_42 ) . V_89 ,
V_115 -> V_116 -> V_93 -> V_107 , V_117 ,
V_70 ) ;
}
static int F_57 ( struct V_15 * V_42 , struct V_118 * V_116 )
{
struct V_14 * V_14 = F_32 ( V_42 -> V_45 ) ;
int V_3 ;
int V_119 ;
struct V_51 * V_52 ;
struct V_29 * V_30 ;
struct V_19 * V_23 , T_1 * * V_20 ;
struct V_49 * V_92 = F_35 ( V_116 -> V_93 ) ;
unsigned long V_56 = 0 ;
const struct V_54 * V_55 ;
struct V_114 V_113 ;
if ( V_103 ( V_116 -> V_93 ) < sizeof( * V_92 ) )
return V_42 -> V_104 ;
V_52 = F_38 ( V_14 , V_92 -> V_73 ) ;
if ( ! V_52 )
return V_42 -> V_104 ;
if ( ! V_92 -> V_66 )
V_30 = V_52 -> V_75 ;
else
V_30 = F_39 ( V_52 , F_37 ( V_92 -> V_66 ) ) ;
if ( ! V_30 )
goto V_10;
V_55 = V_30 -> V_7 -> V_78 ;
if ( ! V_55 )
goto V_35;
if ( V_55 -> V_79 == NULL )
goto V_35;
if ( F_36 ( V_92 -> V_66 ) ) {
V_56 = V_55 -> V_81 ( V_30 , V_92 -> V_66 ) ;
if ( V_56 == 0 )
goto V_35;
}
V_20 = V_55 -> V_79 ( V_30 , V_56 ) ;
if ( V_20 == NULL )
goto V_35;
V_119 = V_116 -> args [ 0 ] ;
for ( V_23 = F_14 ( * V_20 ) , V_3 = 0 ;
V_23 ; V_23 = F_14 ( V_23 -> V_24 ) , V_3 ++ ) {
if ( V_3 < V_119 )
continue;
if ( F_37 ( V_92 -> V_65 ) &&
F_37 ( V_92 -> V_65 ) != V_23 -> V_26 )
continue;
if ( F_36 ( V_92 -> V_65 ) &&
F_36 ( V_92 -> V_65 ) != V_23 -> V_27 )
continue;
if ( V_3 > V_119 )
memset ( & V_116 -> args [ 1 ] , 0 ,
sizeof( V_116 -> args ) - sizeof( V_116 -> args [ 0 ] ) ) ;
if ( V_116 -> args [ 1 ] == 0 ) {
if ( F_45 ( V_14 , V_42 , V_23 , 0 ,
F_51 ( V_116 -> V_42 ) . V_89 ,
V_116 -> V_93 -> V_107 , V_117 ,
V_70 ) <= 0 )
break;
V_116 -> args [ 1 ] = 1 ;
}
if ( V_23 -> V_7 -> V_120 == NULL )
continue;
V_113 . V_121 . V_122 = F_56 ;
V_113 . V_42 = V_42 ;
V_113 . V_116 = V_116 ;
V_113 . V_121 . V_123 = 0 ;
V_113 . V_121 . V_124 = V_116 -> args [ 1 ] - 1 ;
V_113 . V_121 . V_125 = 0 ;
V_23 -> V_7 -> V_120 ( V_23 , & V_113 . V_121 ) ;
V_116 -> args [ 1 ] = V_113 . V_121 . V_125 + 1 ;
if ( V_113 . V_121 . V_123 )
break;
}
V_116 -> args [ 0 ] = V_3 ;
V_35:
if ( V_56 )
V_55 -> V_88 ( V_30 , V_56 ) ;
V_10:
return V_42 -> V_104 ;
}
void F_58 ( struct V_126 * V_127 )
{
#ifdef F_59
F_60 ( V_128 ) ;
F_61 ( V_127 , & V_128 ) ;
F_62 ( & V_128 , V_129 ) ;
F_26 ( V_127 -> V_128 ) ;
V_127 -> V_130 = 0 ;
#endif
}
int F_63 ( struct V_14 * V_14 , struct V_19 * V_23 , struct V_46 * * V_131 ,
struct V_46 * V_132 , struct V_126 * V_127 , bool V_133 )
{
#ifdef F_59
{
struct V_134 * V_135 ;
if ( V_127 -> V_136 && V_131 [ V_127 -> V_136 ] ) {
V_135 = F_64 ( V_14 , V_131 [ V_127 -> V_136 ] , V_132 ,
L_2 , V_133 , V_137 ) ;
if ( F_41 ( V_135 ) )
return F_42 ( V_135 ) ;
V_135 -> type = V_127 -> type = V_138 ;
V_127 -> V_128 [ 0 ] = V_135 ;
V_127 -> V_130 = 1 ;
} else if ( V_127 -> V_139 && V_131 [ V_127 -> V_139 ] ) {
F_60 ( V_128 ) ;
int V_31 , V_140 = 0 ;
V_31 = F_65 ( V_14 , V_131 [ V_127 -> V_139 ] , V_132 ,
NULL , V_133 , V_137 ,
& V_128 ) ;
if ( V_31 )
return V_31 ;
F_3 (act, &actions, list)
V_127 -> V_128 [ V_140 ++ ] = V_135 ;
V_127 -> V_130 = V_140 ;
}
}
#else
if ( ( V_127 -> V_139 && V_131 [ V_127 -> V_139 ] ) ||
( V_127 -> V_136 && V_131 [ V_127 -> V_136 ] ) )
return - V_80 ;
#endif
return 0 ;
}
void F_66 ( struct V_19 * V_23 , struct V_126 * V_141 ,
struct V_126 * V_142 )
{
#ifdef F_59
struct V_126 V_143 = * V_141 ;
F_67 ( V_23 ) ;
V_141 -> V_130 = V_142 -> V_130 ;
V_141 -> V_128 = V_142 -> V_128 ;
V_141 -> type = V_142 -> type ;
F_68 ( V_23 ) ;
F_58 ( & V_143 ) ;
#endif
}
static struct V_134 * F_69 ( struct V_126 * V_127 )
{
if ( V_127 -> V_130 == 0 )
return NULL ;
else
return V_127 -> V_128 [ 0 ] ;
}
int F_70 ( struct V_15 * V_42 , struct V_126 * V_127 )
{
#ifdef F_59
struct V_46 * V_144 ;
if ( V_127 -> V_139 && V_127 -> V_130 ) {
if ( V_127 -> type != V_138 ) {
F_60 ( V_128 ) ;
V_144 = F_71 ( V_42 , V_127 -> V_139 ) ;
if ( V_144 == NULL )
goto V_101;
F_61 ( V_127 , & V_128 ) ;
if ( F_72 ( V_42 , & V_128 , 0 , 0 ) < 0 )
goto V_101;
F_73 ( V_42 , V_144 ) ;
} else if ( V_127 -> V_136 ) {
struct V_134 * V_135 = F_69 ( V_127 ) ;
V_144 = F_71 ( V_42 , V_127 -> V_136 ) ;
if ( V_144 == NULL || ! V_135 )
goto V_101;
if ( F_74 ( V_42 , V_135 , 0 , 0 ) < 0 )
goto V_101;
F_73 ( V_42 , V_144 ) ;
}
}
return 0 ;
V_101:
F_75 ( V_42 , V_144 ) ;
return - 1 ;
#else
return 0 ;
#endif
}
int F_76 ( struct V_15 * V_42 , struct V_126 * V_127 )
{
#ifdef F_59
struct V_134 * V_115 = F_69 ( V_127 ) ;
if ( V_115 != NULL && F_77 ( V_42 , V_115 , 1 ) < 0 )
return - 1 ;
#endif
return 0 ;
}
int F_78 ( struct V_51 * V_52 , struct V_126 * V_127 ,
struct V_51 * * V_145 )
{
#ifdef F_59
const struct V_134 * V_115 ;
F_60 ( V_128 ) ;
if ( F_79 ( V_127 ) )
return - V_77 ;
F_61 ( V_127 , & V_128 ) ;
F_3 (a, &actions, list) {
if ( V_115 -> V_7 -> V_146 ) {
V_115 -> V_7 -> V_146 ( V_115 , F_80 ( V_52 ) , V_145 ) ;
break;
}
}
if ( * V_145 )
return 0 ;
#endif
return - V_80 ;
}
static int T_4 F_81 ( void )
{
F_82 ( V_147 , V_70 , F_31 , NULL , NULL ) ;
F_82 ( V_147 , V_67 , F_31 , NULL , NULL ) ;
F_82 ( V_147 , V_60 , F_31 ,
F_57 , NULL ) ;
return 0 ;
}
