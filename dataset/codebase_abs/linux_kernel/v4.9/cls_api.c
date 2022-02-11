static const struct V_1 * F_1 ( struct V_2 * V_3 )
{
const struct V_1 * V_4 , * V_5 = NULL ;
if ( V_3 ) {
F_2 ( & V_6 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( F_4 ( V_3 , V_4 -> V_3 ) == 0 ) {
if ( F_5 ( V_4 -> V_7 ) )
V_5 = V_4 ;
break;
}
}
F_6 ( & V_6 ) ;
}
return V_5 ;
}
int F_7 ( struct V_1 * V_8 )
{
struct V_1 * V_4 ;
int V_9 = - V_10 ;
F_8 ( & V_6 ) ;
F_3 (t, &tcf_proto_base, head)
if ( ! strcmp ( V_8 -> V_3 , V_4 -> V_3 ) )
goto V_11;
F_9 ( & V_8 -> V_12 , & V_13 ) ;
V_9 = 0 ;
V_11:
F_10 ( & V_6 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_8 )
{
struct V_1 * V_4 ;
int V_9 = - V_14 ;
F_12 () ;
F_8 ( & V_6 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( V_4 == V_8 ) {
F_13 ( & V_4 -> V_12 ) ;
V_9 = 0 ;
break;
}
}
F_10 ( & V_6 ) ;
return V_9 ;
}
static void F_14 ( struct V_15 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 T_1 * * V_21 , int V_22 )
{
struct V_20 T_1 * * V_23 ;
struct V_20 * V_24 ;
for ( V_23 = V_21 ; ( V_24 = F_15 ( * V_23 ) ) != NULL ;
V_23 = & V_24 -> V_25 )
F_16 ( V_15 , V_17 , V_19 , V_24 , 0 , V_22 , false ) ;
}
static inline T_2 F_17 ( struct V_20 * V_24 )
{
T_2 V_26 = F_18 ( 0xC0000000U , 0U ) ;
if ( V_24 )
V_26 = V_24 -> V_27 - 1 ;
return V_26 ;
}
static int F_19 ( struct V_16 * V_28 , struct V_18 * V_19 )
{
struct V_15 * V_15 = F_20 ( V_28 -> V_29 ) ;
struct V_2 * V_30 [ V_31 + 1 ] ;
struct V_32 * V_4 ;
T_2 V_33 ;
T_2 V_27 ;
T_2 V_34 ;
T_2 V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_20 T_1 * * V_40 ;
struct V_20 T_1 * * V_21 ;
struct V_20 * V_24 ;
const struct V_1 * V_41 ;
const struct V_42 * V_43 ;
unsigned long V_44 ;
unsigned long V_45 ;
int V_46 ;
int V_47 = 0 ;
if ( ( V_19 -> V_48 != V_49 ) &&
! F_21 ( V_28 , V_15 -> V_50 , V_51 ) )
return - V_52 ;
V_53:
V_46 = F_22 ( V_19 , sizeof( * V_4 ) , V_30 , V_31 , NULL ) ;
if ( V_46 < 0 )
return V_46 ;
V_4 = F_23 ( V_19 ) ;
V_33 = F_24 ( V_4 -> V_54 ) ;
V_27 = F_25 ( V_4 -> V_54 ) ;
V_34 = V_27 ;
V_35 = V_4 -> V_55 ;
V_44 = 0 ;
if ( V_27 == 0 ) {
switch ( V_19 -> V_48 ) {
case V_56 :
if ( V_33 || V_4 -> V_57 || V_30 [ V_58 ] )
return - V_14 ;
break;
case V_59 :
if ( V_19 -> V_60 & V_61 ) {
V_27 = F_18 ( 0x80000000U , 0U ) ;
break;
}
default:
return - V_14 ;
}
}
V_37 = F_26 ( V_15 , V_4 -> V_62 ) ;
if ( V_37 == NULL )
return - V_63 ;
if ( ! V_35 ) {
V_39 = V_37 -> V_64 ;
V_35 = V_39 -> V_65 ;
} else {
V_39 = F_27 ( V_37 , F_25 ( V_4 -> V_55 ) ) ;
if ( V_39 == NULL )
return - V_66 ;
}
V_43 = V_39 -> V_8 -> V_67 ;
if ( ! V_43 )
return - V_66 ;
if ( V_43 -> V_68 == NULL )
return - V_69 ;
if ( F_24 ( V_35 ) ) {
V_44 = V_43 -> V_70 ( V_39 , V_35 ) ;
if ( V_44 == 0 )
return - V_14 ;
}
V_21 = V_43 -> V_68 ( V_39 , V_44 ) ;
V_46 = - V_66 ;
if ( V_21 == NULL )
goto V_71;
if ( V_19 -> V_48 == V_56 && V_27 == 0 ) {
F_14 ( V_15 , V_28 , V_19 , V_21 , V_56 ) ;
F_28 ( V_21 ) ;
V_46 = 0 ;
goto V_71;
}
for ( V_40 = V_21 ;
( V_24 = F_15 ( * V_40 ) ) != NULL ;
V_40 = & V_24 -> V_25 ) {
if ( V_24 -> V_27 >= V_27 ) {
if ( V_24 -> V_27 == V_27 ) {
if ( ! V_34 ||
( V_24 -> V_33 != V_33 && V_33 ) )
goto V_71;
} else
V_24 = NULL ;
break;
}
}
if ( V_24 == NULL ) {
if ( V_30 [ V_58 ] == NULL || ! V_33 )
goto V_71;
V_46 = - V_14 ;
if ( V_19 -> V_48 != V_59 ||
! ( V_19 -> V_60 & V_61 ) )
goto V_71;
V_46 = - V_72 ;
V_24 = F_29 ( sizeof( * V_24 ) , V_73 ) ;
if ( V_24 == NULL )
goto V_71;
V_46 = - V_14 ;
V_41 = F_1 ( V_30 [ V_58 ] ) ;
if ( V_41 == NULL ) {
#ifdef F_30
struct V_2 * V_3 = V_30 [ V_58 ] ;
char V_74 [ V_75 ] ;
if ( V_3 != NULL &&
F_31 ( V_74 , V_3 , V_75 ) < V_75 ) {
F_32 () ;
F_33 ( L_1 , V_74 ) ;
F_34 () ;
V_41 = F_1 ( V_3 ) ;
if ( V_41 != NULL ) {
F_35 ( V_41 -> V_7 ) ;
V_46 = - V_76 ;
}
}
#endif
F_36 ( V_24 ) ;
goto V_71;
}
V_24 -> V_8 = V_41 ;
V_24 -> V_33 = V_33 ;
V_24 -> V_27 = V_34 ? :
F_25 ( F_17 ( F_15 ( * V_40 ) ) ) ;
V_24 -> V_39 = V_39 ;
V_24 -> V_77 = V_41 -> V_77 ;
V_24 -> V_78 = V_35 ;
V_46 = V_41 -> V_79 ( V_24 ) ;
if ( V_46 != 0 ) {
F_35 ( V_41 -> V_7 ) ;
F_36 ( V_24 ) ;
goto V_71;
}
V_47 = 1 ;
} else if ( V_30 [ V_58 ] && F_4 ( V_30 [ V_58 ] , V_24 -> V_8 -> V_3 ) )
goto V_71;
V_45 = V_24 -> V_8 -> V_70 ( V_24 , V_4 -> V_57 ) ;
if ( V_45 == 0 ) {
if ( V_19 -> V_48 == V_56 && V_4 -> V_57 == 0 ) {
struct V_20 * V_25 = F_15 ( V_24 -> V_25 ) ;
F_37 ( * V_40 , V_25 ) ;
F_16 ( V_15 , V_28 , V_19 , V_24 , V_45 ,
V_56 , false ) ;
F_38 ( V_24 , true ) ;
V_46 = 0 ;
goto V_71;
}
V_46 = - V_14 ;
if ( V_19 -> V_48 != V_59 ||
! ( V_19 -> V_60 & V_61 ) )
goto V_71;
} else {
switch ( V_19 -> V_48 ) {
case V_59 :
V_46 = - V_10 ;
if ( V_19 -> V_60 & V_80 ) {
if ( V_47 )
F_38 ( V_24 , true ) ;
goto V_71;
}
break;
case V_56 :
V_46 = V_24 -> V_8 -> V_81 ( V_24 , V_45 ) ;
if ( V_46 == 0 ) {
struct V_20 * V_25 = F_15 ( V_24 -> V_25 ) ;
F_16 ( V_15 , V_28 , V_19 , V_24 ,
V_4 -> V_57 ,
V_56 , false ) ;
if ( F_38 ( V_24 , false ) )
F_37 ( * V_40 , V_25 ) ;
}
goto V_71;
case V_49 :
V_46 = F_16 ( V_15 , V_28 , V_19 , V_24 , V_45 ,
V_59 , true ) ;
goto V_71;
default:
V_46 = - V_66 ;
goto V_71;
}
}
V_46 = V_24 -> V_8 -> V_82 ( V_15 , V_28 , V_24 , V_44 , V_4 -> V_57 , V_30 , & V_45 ,
V_19 -> V_60 & V_61 ? V_83 : V_84 ) ;
if ( V_46 == 0 ) {
if ( V_47 ) {
F_37 ( V_24 -> V_25 , F_15 ( * V_40 ) ) ;
F_39 ( * V_40 , V_24 ) ;
}
F_16 ( V_15 , V_28 , V_19 , V_24 , V_45 , V_59 , false ) ;
} else {
if ( V_47 )
F_38 ( V_24 , true ) ;
}
V_71:
if ( V_44 )
V_43 -> V_85 ( V_39 , V_44 ) ;
if ( V_46 == - V_76 )
goto V_53;
return V_46 ;
}
static int F_40 ( struct V_15 * V_15 , struct V_16 * V_28 ,
struct V_20 * V_24 , unsigned long V_45 , T_2 V_86 ,
T_2 V_87 , T_3 V_88 , int V_22 )
{
struct V_32 * V_89 ;
struct V_18 * V_90 ;
unsigned char * V_91 = F_41 ( V_28 ) ;
V_90 = F_42 ( V_28 , V_86 , V_87 , V_22 , sizeof( * V_89 ) , V_88 ) ;
if ( ! V_90 )
goto V_92;
V_89 = F_23 ( V_90 ) ;
V_89 -> V_93 = V_94 ;
V_89 -> V_95 = 0 ;
V_89 -> V_96 = 0 ;
V_89 -> V_62 = F_43 ( V_24 -> V_39 ) -> V_97 ;
V_89 -> V_55 = V_24 -> V_78 ;
V_89 -> V_54 = F_18 ( V_24 -> V_27 , V_24 -> V_33 ) ;
if ( F_44 ( V_28 , V_58 , V_24 -> V_8 -> V_3 ) )
goto V_98;
V_89 -> V_57 = V_45 ;
if ( V_56 != V_22 ) {
V_89 -> V_57 = 0 ;
if ( V_24 -> V_8 -> V_99 && V_24 -> V_8 -> V_99 ( V_15 , V_24 , V_45 , V_28 , V_89 ) < 0 )
goto V_98;
}
V_90 -> V_100 = F_41 ( V_28 ) - V_91 ;
return V_28 -> V_101 ;
V_92:
V_98:
F_45 ( V_28 , V_91 ) ;
return - 1 ;
}
static int F_16 ( struct V_15 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 , struct V_20 * V_24 ,
unsigned long V_45 , int V_22 , bool V_102 )
{
struct V_16 * V_28 ;
T_2 V_86 = V_17 ? F_46 ( V_17 ) . V_86 : 0 ;
V_28 = F_47 ( V_103 , V_73 ) ;
if ( ! V_28 )
return - V_72 ;
if ( F_40 ( V_15 , V_28 , V_24 , V_45 , V_86 , V_19 -> V_104 ,
V_19 -> V_60 , V_22 ) <= 0 ) {
F_48 ( V_28 ) ;
return - V_66 ;
}
if ( V_102 )
return F_49 ( V_15 -> V_105 , V_28 , V_86 , V_106 ) ;
return F_50 ( V_28 , V_15 , V_86 , V_107 ,
V_19 -> V_60 & V_108 ) ;
}
static int F_51 ( struct V_20 * V_24 , unsigned long V_19 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 = ( void * ) V_110 ;
struct V_15 * V_15 = F_20 ( V_112 -> V_28 -> V_29 ) ;
return F_40 ( V_15 , V_112 -> V_28 , V_24 , V_19 , F_46 ( V_112 -> V_113 -> V_28 ) . V_86 ,
V_112 -> V_113 -> V_90 -> V_104 , V_114 ,
V_59 ) ;
}
static int F_52 ( struct V_16 * V_28 , struct V_115 * V_113 )
{
struct V_15 * V_15 = F_20 ( V_28 -> V_29 ) ;
int V_4 ;
int V_116 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_20 * V_24 , T_1 * * V_21 ;
struct V_32 * V_89 = F_23 ( V_113 -> V_90 ) ;
unsigned long V_44 = 0 ;
const struct V_42 * V_43 ;
struct V_111 V_110 ;
if ( V_100 ( V_113 -> V_90 ) < sizeof( * V_89 ) )
return V_28 -> V_101 ;
V_37 = F_26 ( V_15 , V_89 -> V_62 ) ;
if ( ! V_37 )
return V_28 -> V_101 ;
if ( ! V_89 -> V_55 )
V_39 = V_37 -> V_64 ;
else
V_39 = F_27 ( V_37 , F_25 ( V_89 -> V_55 ) ) ;
if ( ! V_39 )
goto V_11;
V_43 = V_39 -> V_8 -> V_67 ;
if ( ! V_43 )
goto V_71;
if ( V_43 -> V_68 == NULL )
goto V_71;
if ( F_24 ( V_89 -> V_55 ) ) {
V_44 = V_43 -> V_70 ( V_39 , V_89 -> V_55 ) ;
if ( V_44 == 0 )
goto V_71;
}
V_21 = V_43 -> V_68 ( V_39 , V_44 ) ;
if ( V_21 == NULL )
goto V_71;
V_116 = V_113 -> args [ 0 ] ;
for ( V_24 = F_15 ( * V_21 ) , V_4 = 0 ;
V_24 ; V_24 = F_15 ( V_24 -> V_25 ) , V_4 ++ ) {
if ( V_4 < V_116 )
continue;
if ( F_25 ( V_89 -> V_54 ) &&
F_25 ( V_89 -> V_54 ) != V_24 -> V_27 )
continue;
if ( F_24 ( V_89 -> V_54 ) &&
F_24 ( V_89 -> V_54 ) != V_24 -> V_33 )
continue;
if ( V_4 > V_116 )
memset ( & V_113 -> args [ 1 ] , 0 ,
sizeof( V_113 -> args ) - sizeof( V_113 -> args [ 0 ] ) ) ;
if ( V_113 -> args [ 1 ] == 0 ) {
if ( F_40 ( V_15 , V_28 , V_24 , 0 ,
F_46 ( V_113 -> V_28 ) . V_86 ,
V_113 -> V_90 -> V_104 , V_114 ,
V_59 ) <= 0 )
break;
V_113 -> args [ 1 ] = 1 ;
}
if ( V_24 -> V_8 -> V_117 == NULL )
continue;
V_110 . V_118 . V_119 = F_51 ;
V_110 . V_28 = V_28 ;
V_110 . V_113 = V_113 ;
V_110 . V_118 . V_120 = 0 ;
V_110 . V_118 . V_121 = V_113 -> args [ 1 ] - 1 ;
V_110 . V_118 . V_122 = 0 ;
V_24 -> V_8 -> V_117 ( V_24 , & V_110 . V_118 ) ;
V_113 -> args [ 1 ] = V_110 . V_118 . V_122 + 1 ;
if ( V_110 . V_118 . V_120 )
break;
}
V_113 -> args [ 0 ] = V_4 ;
V_71:
if ( V_44 )
V_43 -> V_85 ( V_39 , V_44 ) ;
V_11:
return V_28 -> V_101 ;
}
void F_53 ( struct V_123 * V_124 )
{
#ifdef F_54
F_55 ( V_125 ) ;
F_56 ( V_124 , & V_125 ) ;
F_57 ( & V_125 , V_126 ) ;
F_36 ( V_124 -> V_125 ) ;
V_124 -> V_127 = 0 ;
#endif
}
int F_58 ( struct V_15 * V_15 , struct V_20 * V_24 , struct V_2 * * V_128 ,
struct V_2 * V_129 , struct V_123 * V_124 , bool V_130 )
{
#ifdef F_54
{
struct V_131 * V_132 ;
if ( V_124 -> V_133 && V_128 [ V_124 -> V_133 ] ) {
V_132 = F_59 ( V_15 , V_128 [ V_124 -> V_133 ] , V_129 ,
L_2 , V_130 , V_134 ) ;
if ( F_60 ( V_132 ) )
return F_61 ( V_132 ) ;
V_132 -> type = V_124 -> type = V_135 ;
V_124 -> V_125 [ 0 ] = V_132 ;
V_124 -> V_127 = 1 ;
} else if ( V_124 -> V_136 && V_128 [ V_124 -> V_136 ] ) {
F_55 ( V_125 ) ;
int V_46 , V_137 = 0 ;
V_46 = F_62 ( V_15 , V_128 [ V_124 -> V_136 ] , V_129 ,
NULL , V_130 , V_134 ,
& V_125 ) ;
if ( V_46 )
return V_46 ;
F_3 (act, &actions, list)
V_124 -> V_125 [ V_137 ++ ] = V_132 ;
V_124 -> V_127 = V_137 ;
}
}
#else
if ( ( V_124 -> V_136 && V_128 [ V_124 -> V_136 ] ) ||
( V_124 -> V_133 && V_128 [ V_124 -> V_133 ] ) )
return - V_69 ;
#endif
return 0 ;
}
void F_63 ( struct V_20 * V_24 , struct V_123 * V_138 ,
struct V_123 * V_139 )
{
#ifdef F_54
struct V_123 V_140 = * V_138 ;
F_64 ( V_24 ) ;
V_138 -> V_127 = V_139 -> V_127 ;
V_138 -> V_125 = V_139 -> V_125 ;
V_138 -> type = V_139 -> type ;
F_65 ( V_24 ) ;
F_53 ( & V_140 ) ;
#endif
}
static struct V_131 * F_66 ( struct V_123 * V_124 )
{
if ( V_124 -> V_127 == 0 )
return NULL ;
else
return V_124 -> V_125 [ 0 ] ;
}
int F_67 ( struct V_16 * V_28 , struct V_123 * V_124 )
{
#ifdef F_54
struct V_2 * V_141 ;
if ( V_124 -> V_136 && V_124 -> V_127 ) {
if ( V_124 -> type != V_135 ) {
F_55 ( V_125 ) ;
V_141 = F_68 ( V_28 , V_124 -> V_136 ) ;
if ( V_141 == NULL )
goto V_98;
F_56 ( V_124 , & V_125 ) ;
if ( F_69 ( V_28 , & V_125 , 0 , 0 ) < 0 )
goto V_98;
F_70 ( V_28 , V_141 ) ;
} else if ( V_124 -> V_133 ) {
struct V_131 * V_132 = F_66 ( V_124 ) ;
V_141 = F_68 ( V_28 , V_124 -> V_133 ) ;
if ( V_141 == NULL || ! V_132 )
goto V_98;
if ( F_71 ( V_28 , V_132 , 0 , 0 ) < 0 )
goto V_98;
F_70 ( V_28 , V_141 ) ;
}
}
return 0 ;
V_98:
F_72 ( V_28 , V_141 ) ;
return - 1 ;
#else
return 0 ;
#endif
}
int F_73 ( struct V_16 * V_28 , struct V_123 * V_124 )
{
#ifdef F_54
struct V_131 * V_112 = F_66 ( V_124 ) ;
if ( V_112 != NULL && F_74 ( V_28 , V_112 , 1 ) < 0 )
return - 1 ;
#endif
return 0 ;
}
static int T_4 F_75 ( void )
{
F_76 ( V_142 , V_59 , F_19 , NULL , NULL ) ;
F_76 ( V_142 , V_56 , F_19 , NULL , NULL ) ;
F_76 ( V_142 , V_49 , F_19 ,
F_52 , NULL ) ;
return 0 ;
}
