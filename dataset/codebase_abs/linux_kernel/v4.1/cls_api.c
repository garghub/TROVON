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
static inline T_1 F_14 ( struct V_15 * V_16 )
{
T_1 V_17 = F_15 ( 0xC0000000U , 0U ) ;
if ( V_16 )
V_17 = V_16 -> V_18 - 1 ;
return V_17 ;
}
static int F_16 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_23 * V_23 = F_17 ( V_20 -> V_24 ) ;
struct V_2 * V_25 [ V_26 + 1 ] ;
struct V_27 * V_4 ;
T_1 V_28 ;
T_1 V_18 ;
T_1 V_29 ;
T_1 V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_15 T_2 * * V_35 ;
struct V_15 T_2 * * V_36 ;
struct V_15 * V_16 ;
const struct V_1 * V_37 ;
const struct V_38 * V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
int V_42 ;
int V_43 = 0 ;
if ( ( V_22 -> V_44 != V_45 ) &&
! F_18 ( V_20 , V_23 -> V_46 , V_47 ) )
return - V_48 ;
V_49:
V_42 = F_19 ( V_22 , sizeof( * V_4 ) , V_25 , V_26 , NULL ) ;
if ( V_42 < 0 )
return V_42 ;
V_4 = F_20 ( V_22 ) ;
V_28 = F_21 ( V_4 -> V_50 ) ;
V_18 = F_22 ( V_4 -> V_50 ) ;
V_29 = V_18 ;
V_30 = V_4 -> V_51 ;
V_40 = 0 ;
if ( V_18 == 0 ) {
if ( V_22 -> V_44 != V_52 ||
! ( V_22 -> V_53 & V_54 ) )
return - V_14 ;
V_18 = F_15 ( 0x80000000U , 0U ) ;
}
V_32 = F_23 ( V_23 , V_4 -> V_55 ) ;
if ( V_32 == NULL )
return - V_56 ;
if ( ! V_30 ) {
V_34 = V_32 -> V_57 ;
V_30 = V_34 -> V_58 ;
} else {
V_34 = F_24 ( V_32 , F_22 ( V_4 -> V_51 ) ) ;
if ( V_34 == NULL )
return - V_59 ;
}
V_39 = V_34 -> V_8 -> V_60 ;
if ( ! V_39 )
return - V_59 ;
if ( V_39 -> V_61 == NULL )
return - V_62 ;
if ( F_21 ( V_30 ) ) {
V_40 = V_39 -> V_63 ( V_34 , V_30 ) ;
if ( V_40 == 0 )
return - V_14 ;
}
V_36 = V_39 -> V_61 ( V_34 , V_40 ) ;
V_42 = - V_59 ;
if ( V_36 == NULL )
goto V_64;
for ( V_35 = V_36 ;
( V_16 = F_25 ( * V_35 ) ) != NULL ;
V_35 = & V_16 -> V_65 ) {
if ( V_16 -> V_18 >= V_18 ) {
if ( V_16 -> V_18 == V_18 ) {
if ( ! V_29 ||
( V_16 -> V_28 != V_28 && V_28 ) )
goto V_64;
} else
V_16 = NULL ;
break;
}
}
if ( V_16 == NULL ) {
if ( V_25 [ V_66 ] == NULL || ! V_28 )
goto V_64;
V_42 = - V_14 ;
if ( V_22 -> V_44 != V_52 ||
! ( V_22 -> V_53 & V_54 ) )
goto V_64;
V_42 = - V_67 ;
V_16 = F_26 ( sizeof( * V_16 ) , V_68 ) ;
if ( V_16 == NULL )
goto V_64;
V_42 = - V_14 ;
V_37 = F_1 ( V_25 [ V_66 ] ) ;
if ( V_37 == NULL ) {
#ifdef F_27
struct V_2 * V_3 = V_25 [ V_66 ] ;
char V_69 [ V_70 ] ;
if ( V_3 != NULL &&
F_28 ( V_69 , V_3 , V_70 ) < V_70 ) {
F_29 () ;
F_30 ( L_1 , V_69 ) ;
F_31 () ;
V_37 = F_1 ( V_3 ) ;
if ( V_37 != NULL ) {
F_32 ( V_37 -> V_7 ) ;
V_42 = - V_71 ;
}
}
#endif
F_33 ( V_16 ) ;
goto V_64;
}
V_16 -> V_8 = V_37 ;
V_16 -> V_28 = V_28 ;
V_16 -> V_18 = V_29 ? :
F_22 ( F_14 ( F_25 ( * V_35 ) ) ) ;
V_16 -> V_34 = V_34 ;
V_16 -> V_72 = V_37 -> V_72 ;
V_16 -> V_73 = V_30 ;
V_42 = V_37 -> V_74 ( V_16 ) ;
if ( V_42 != 0 ) {
F_32 ( V_37 -> V_7 ) ;
F_33 ( V_16 ) ;
goto V_64;
}
V_43 = 1 ;
} else if ( V_25 [ V_66 ] && F_4 ( V_25 [ V_66 ] , V_16 -> V_8 -> V_3 ) )
goto V_64;
V_41 = V_16 -> V_8 -> V_63 ( V_16 , V_4 -> V_75 ) ;
if ( V_41 == 0 ) {
if ( V_22 -> V_44 == V_76 && V_4 -> V_75 == 0 ) {
struct V_15 * V_65 = F_25 ( V_16 -> V_65 ) ;
F_34 ( * V_35 , V_65 ) ;
F_35 ( V_23 , V_20 , V_22 , V_16 , V_41 , V_76 ) ;
F_36 ( V_16 , true ) ;
V_42 = 0 ;
goto V_64;
}
V_42 = - V_14 ;
if ( V_22 -> V_44 != V_52 ||
! ( V_22 -> V_53 & V_54 ) )
goto V_64;
} else {
switch ( V_22 -> V_44 ) {
case V_52 :
V_42 = - V_10 ;
if ( V_22 -> V_53 & V_77 ) {
if ( V_43 )
F_36 ( V_16 , true ) ;
goto V_64;
}
break;
case V_76 :
V_42 = V_16 -> V_8 -> V_78 ( V_16 , V_41 ) ;
if ( V_42 == 0 ) {
struct V_15 * V_65 = F_25 ( V_16 -> V_65 ) ;
F_35 ( V_23 , V_20 , V_22 , V_16 , V_41 , V_76 ) ;
if ( F_36 ( V_16 , false ) )
F_34 ( * V_35 , V_65 ) ;
}
goto V_64;
case V_45 :
V_42 = F_35 ( V_23 , V_20 , V_22 , V_16 , V_41 , V_52 ) ;
goto V_64;
default:
V_42 = - V_59 ;
goto V_64;
}
}
V_42 = V_16 -> V_8 -> V_79 ( V_23 , V_20 , V_16 , V_40 , V_4 -> V_75 , V_25 , & V_41 ,
V_22 -> V_53 & V_54 ? V_80 : V_81 ) ;
if ( V_42 == 0 ) {
if ( V_43 ) {
F_34 ( V_16 -> V_65 , F_25 ( * V_35 ) ) ;
F_37 ( * V_35 , V_16 ) ;
}
F_35 ( V_23 , V_20 , V_22 , V_16 , V_41 , V_52 ) ;
} else {
if ( V_43 )
F_36 ( V_16 , true ) ;
}
V_64:
if ( V_40 )
V_39 -> V_82 ( V_34 , V_40 ) ;
if ( V_42 == - V_71 )
goto V_49;
return V_42 ;
}
static int F_38 ( struct V_23 * V_23 , struct V_19 * V_20 , struct V_15 * V_16 ,
unsigned long V_41 , T_1 V_83 , T_1 V_84 , T_3 V_85 , int V_86 )
{
struct V_27 * V_87 ;
struct V_21 * V_88 ;
unsigned char * V_89 = F_39 ( V_20 ) ;
V_88 = F_40 ( V_20 , V_83 , V_84 , V_86 , sizeof( * V_87 ) , V_85 ) ;
if ( ! V_88 )
goto V_90;
V_87 = F_20 ( V_88 ) ;
V_87 -> V_91 = V_92 ;
V_87 -> V_93 = 0 ;
V_87 -> V_94 = 0 ;
V_87 -> V_55 = F_41 ( V_16 -> V_34 ) -> V_95 ;
V_87 -> V_51 = V_16 -> V_73 ;
V_87 -> V_50 = F_15 ( V_16 -> V_18 , V_16 -> V_28 ) ;
if ( F_42 ( V_20 , V_66 , V_16 -> V_8 -> V_3 ) )
goto V_96;
V_87 -> V_75 = V_41 ;
if ( V_76 != V_86 ) {
V_87 -> V_75 = 0 ;
if ( V_16 -> V_8 -> V_97 && V_16 -> V_8 -> V_97 ( V_23 , V_16 , V_41 , V_20 , V_87 ) < 0 )
goto V_96;
}
V_88 -> V_98 = F_39 ( V_20 ) - V_89 ;
return V_20 -> V_99 ;
V_90:
V_96:
F_43 ( V_20 , V_89 ) ;
return - 1 ;
}
static int F_35 ( struct V_23 * V_23 , struct V_19 * V_100 ,
struct V_21 * V_22 , struct V_15 * V_16 ,
unsigned long V_41 , int V_86 )
{
struct V_19 * V_20 ;
T_1 V_83 = V_100 ? F_44 ( V_100 ) . V_83 : 0 ;
V_20 = F_45 ( V_101 , V_68 ) ;
if ( ! V_20 )
return - V_67 ;
if ( F_38 ( V_23 , V_20 , V_16 , V_41 , V_83 , V_22 -> V_102 , 0 , V_86 ) <= 0 ) {
F_46 ( V_20 ) ;
return - V_59 ;
}
return F_47 ( V_20 , V_23 , V_83 , V_103 ,
V_22 -> V_53 & V_104 ) ;
}
static int F_48 ( struct V_15 * V_16 , unsigned long V_22 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 = ( void * ) V_106 ;
struct V_23 * V_23 = F_17 ( V_108 -> V_20 -> V_24 ) ;
return F_38 ( V_23 , V_108 -> V_20 , V_16 , V_22 , F_44 ( V_108 -> V_109 -> V_20 ) . V_83 ,
V_108 -> V_109 -> V_88 -> V_102 , V_110 , V_52 ) ;
}
static int F_49 ( struct V_19 * V_20 , struct V_111 * V_109 )
{
struct V_23 * V_23 = F_17 ( V_20 -> V_24 ) ;
int V_4 ;
int V_112 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_15 * V_16 , T_2 * * V_36 ;
struct V_27 * V_87 = F_20 ( V_109 -> V_88 ) ;
unsigned long V_40 = 0 ;
const struct V_38 * V_39 ;
struct V_107 V_106 ;
if ( V_98 ( V_109 -> V_88 ) < sizeof( * V_87 ) )
return V_20 -> V_99 ;
V_32 = F_23 ( V_23 , V_87 -> V_55 ) ;
if ( ! V_32 )
return V_20 -> V_99 ;
if ( ! V_87 -> V_51 )
V_34 = V_32 -> V_57 ;
else
V_34 = F_24 ( V_32 , F_22 ( V_87 -> V_51 ) ) ;
if ( ! V_34 )
goto V_11;
V_39 = V_34 -> V_8 -> V_60 ;
if ( ! V_39 )
goto V_64;
if ( V_39 -> V_61 == NULL )
goto V_64;
if ( F_21 ( V_87 -> V_51 ) ) {
V_40 = V_39 -> V_63 ( V_34 , V_87 -> V_51 ) ;
if ( V_40 == 0 )
goto V_64;
}
V_36 = V_39 -> V_61 ( V_34 , V_40 ) ;
if ( V_36 == NULL )
goto V_64;
V_112 = V_109 -> args [ 0 ] ;
for ( V_16 = F_25 ( * V_36 ) , V_4 = 0 ;
V_16 ; V_16 = F_25 ( V_16 -> V_65 ) , V_4 ++ ) {
if ( V_4 < V_112 )
continue;
if ( F_22 ( V_87 -> V_50 ) &&
F_22 ( V_87 -> V_50 ) != V_16 -> V_18 )
continue;
if ( F_21 ( V_87 -> V_50 ) &&
F_21 ( V_87 -> V_50 ) != V_16 -> V_28 )
continue;
if ( V_4 > V_112 )
memset ( & V_109 -> args [ 1 ] , 0 , sizeof( V_109 -> args ) - sizeof( V_109 -> args [ 0 ] ) ) ;
if ( V_109 -> args [ 1 ] == 0 ) {
if ( F_38 ( V_23 , V_20 , V_16 , 0 , F_44 ( V_109 -> V_20 ) . V_83 ,
V_109 -> V_88 -> V_102 , V_110 ,
V_52 ) <= 0 )
break;
V_109 -> args [ 1 ] = 1 ;
}
if ( V_16 -> V_8 -> V_113 == NULL )
continue;
V_106 . V_114 . V_115 = F_48 ;
V_106 . V_20 = V_20 ;
V_106 . V_109 = V_109 ;
V_106 . V_114 . V_116 = 0 ;
V_106 . V_114 . V_117 = V_109 -> args [ 1 ] - 1 ;
V_106 . V_114 . V_118 = 0 ;
V_16 -> V_8 -> V_113 ( V_16 , & V_106 . V_114 ) ;
V_109 -> args [ 1 ] = V_106 . V_114 . V_118 + 1 ;
if ( V_106 . V_114 . V_116 )
break;
}
V_109 -> args [ 0 ] = V_4 ;
V_64:
if ( V_40 )
V_39 -> V_82 ( V_34 , V_40 ) ;
V_11:
return V_20 -> V_99 ;
}
void F_50 ( struct V_119 * V_120 )
{
#ifdef F_51
F_52 ( & V_120 -> V_121 , V_122 ) ;
F_53 ( & V_120 -> V_121 ) ;
#endif
}
int F_54 ( struct V_23 * V_23 , struct V_15 * V_16 , struct V_2 * * V_123 ,
struct V_2 * V_124 , struct V_119 * V_120 , bool V_125 )
{
#ifdef F_51
{
struct V_126 * V_127 ;
F_53 ( & V_120 -> V_121 ) ;
if ( V_120 -> V_128 && V_123 [ V_120 -> V_128 ] ) {
V_127 = F_55 ( V_23 , V_123 [ V_120 -> V_128 ] , V_124 ,
L_2 , V_125 ,
V_129 ) ;
if ( F_56 ( V_127 ) )
return F_57 ( V_127 ) ;
V_127 -> type = V_120 -> type = V_130 ;
F_58 ( & V_127 -> V_131 , & V_120 -> V_121 ) ;
} else if ( V_120 -> V_132 && V_123 [ V_120 -> V_132 ] ) {
int V_42 ;
V_42 = F_59 ( V_23 , V_123 [ V_120 -> V_132 ] , V_124 ,
NULL , V_125 ,
V_129 , & V_120 -> V_121 ) ;
if ( V_42 )
return V_42 ;
}
}
#else
if ( ( V_120 -> V_132 && V_123 [ V_120 -> V_132 ] ) ||
( V_120 -> V_128 && V_123 [ V_120 -> V_128 ] ) )
return - V_62 ;
#endif
return 0 ;
}
void F_60 ( struct V_15 * V_16 , struct V_119 * V_133 ,
struct V_119 * V_134 )
{
#ifdef F_51
F_61 ( V_135 ) ;
F_62 ( V_16 ) ;
F_63 ( & V_133 -> V_121 , & V_135 ) ;
F_64 ( & V_134 -> V_121 , & V_133 -> V_121 ) ;
V_133 -> type = V_134 -> type ;
F_65 ( V_16 ) ;
F_52 ( & V_135 , V_122 ) ;
#endif
}
int F_66 ( struct V_19 * V_20 , struct V_119 * V_120 )
{
#ifdef F_51
struct V_2 * V_136 ;
if ( V_120 -> V_132 && ! F_67 ( & V_120 -> V_121 ) ) {
if ( V_120 -> type != V_130 ) {
V_136 = F_68 ( V_20 , V_120 -> V_132 ) ;
if ( V_136 == NULL )
goto V_96;
if ( F_69 ( V_20 , & V_120 -> V_121 , 0 , 0 ) < 0 )
goto V_96;
F_70 ( V_20 , V_136 ) ;
} else if ( V_120 -> V_128 ) {
struct V_126 * V_127 = F_71 ( V_120 ) ;
V_136 = F_68 ( V_20 , V_120 -> V_128 ) ;
if ( V_136 == NULL || ! V_127 )
goto V_96;
if ( F_72 ( V_20 , V_127 , 0 , 0 ) < 0 )
goto V_96;
F_70 ( V_20 , V_136 ) ;
}
}
return 0 ;
V_96:
F_73 ( V_20 , V_136 ) ;
return - 1 ;
#else
return 0 ;
#endif
}
int F_74 ( struct V_19 * V_20 , struct V_119 * V_120 )
{
#ifdef F_51
struct V_126 * V_108 = F_71 ( V_120 ) ;
if ( V_108 != NULL && F_75 ( V_20 , V_108 , 1 ) < 0 )
return - 1 ;
#endif
return 0 ;
}
static int T_4 F_76 ( void )
{
F_77 ( V_137 , V_52 , F_16 , NULL , NULL ) ;
F_77 ( V_137 , V_76 , F_16 , NULL , NULL ) ;
F_77 ( V_137 , V_45 , F_16 ,
F_49 , NULL ) ;
return 0 ;
}
