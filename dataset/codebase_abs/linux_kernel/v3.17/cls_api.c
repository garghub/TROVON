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
F_8 ( & V_6 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( V_4 == V_8 ) {
F_12 ( & V_4 -> V_12 ) ;
V_9 = 0 ;
break;
}
}
F_10 ( & V_6 ) ;
return V_9 ;
}
static inline T_1 F_13 ( struct V_15 * V_16 )
{
T_1 V_17 = F_14 ( 0xC0000000U , 0U ) ;
if ( V_16 )
V_17 = V_16 -> V_18 - 1 ;
return V_17 ;
}
static int F_15 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_23 * V_23 = F_16 ( V_20 -> V_24 ) ;
struct V_2 * V_25 [ V_26 + 1 ] ;
T_2 * V_27 ;
struct V_28 * V_4 ;
T_1 V_29 ;
T_1 V_18 ;
T_1 V_30 ;
T_1 V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_15 * * V_36 , * * V_37 ;
struct V_15 * V_16 ;
const struct V_1 * V_38 ;
const struct V_39 * V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
int V_43 ;
int V_44 = 0 ;
if ( ( V_22 -> V_45 != V_46 ) &&
! F_17 ( V_20 , V_23 -> V_47 , V_48 ) )
return - V_49 ;
V_50:
V_43 = F_18 ( V_22 , sizeof( * V_4 ) , V_25 , V_26 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
V_4 = F_19 ( V_22 ) ;
V_29 = F_20 ( V_4 -> V_51 ) ;
V_18 = F_21 ( V_4 -> V_51 ) ;
V_30 = V_18 ;
V_31 = V_4 -> V_52 ;
V_41 = 0 ;
if ( V_18 == 0 ) {
if ( V_22 -> V_45 != V_53 ||
! ( V_22 -> V_54 & V_55 ) )
return - V_14 ;
V_18 = F_14 ( 0x80000000U , 0U ) ;
}
V_33 = F_22 ( V_23 , V_4 -> V_56 ) ;
if ( V_33 == NULL )
return - V_57 ;
if ( ! V_31 ) {
V_35 = V_33 -> V_58 ;
V_31 = V_35 -> V_59 ;
} else {
V_35 = F_23 ( V_33 , F_21 ( V_4 -> V_52 ) ) ;
if ( V_35 == NULL )
return - V_60 ;
}
V_40 = V_35 -> V_8 -> V_61 ;
if ( ! V_40 )
return - V_60 ;
if ( V_40 -> V_62 == NULL )
return - V_63 ;
if ( F_20 ( V_31 ) ) {
V_41 = V_40 -> V_64 ( V_35 , V_31 ) ;
if ( V_41 == 0 )
return - V_14 ;
}
V_37 = V_40 -> V_62 ( V_35 , V_41 ) ;
V_43 = - V_60 ;
if ( V_37 == NULL )
goto V_65;
for ( V_36 = V_37 ; ( V_16 = * V_36 ) != NULL ; V_36 = & V_16 -> V_66 ) {
if ( V_16 -> V_18 >= V_18 ) {
if ( V_16 -> V_18 == V_18 ) {
if ( ! V_30 ||
( V_16 -> V_29 != V_29 && V_29 ) )
goto V_65;
} else
V_16 = NULL ;
break;
}
}
V_27 = F_24 ( V_35 ) ;
if ( V_16 == NULL ) {
if ( V_25 [ V_67 ] == NULL || ! V_29 )
goto V_65;
V_43 = - V_14 ;
if ( V_22 -> V_45 != V_53 ||
! ( V_22 -> V_54 & V_55 ) )
goto V_65;
V_43 = - V_68 ;
V_16 = F_25 ( sizeof( * V_16 ) , V_69 ) ;
if ( V_16 == NULL )
goto V_65;
V_43 = - V_14 ;
V_38 = F_1 ( V_25 [ V_67 ] ) ;
if ( V_38 == NULL ) {
#ifdef F_26
struct V_2 * V_3 = V_25 [ V_67 ] ;
char V_70 [ V_71 ] ;
if ( V_3 != NULL &&
F_27 ( V_70 , V_3 , V_71 ) < V_71 ) {
F_28 () ;
F_29 ( L_1 , V_70 ) ;
F_30 () ;
V_38 = F_1 ( V_3 ) ;
if ( V_38 != NULL ) {
F_31 ( V_38 -> V_7 ) ;
V_43 = - V_72 ;
}
}
#endif
F_32 ( V_16 ) ;
goto V_65;
}
V_16 -> V_8 = V_38 ;
V_16 -> V_29 = V_29 ;
V_16 -> V_18 = V_30 ? : F_21 ( F_13 ( * V_36 ) ) ;
V_16 -> V_35 = V_35 ;
V_16 -> V_73 = V_38 -> V_73 ;
V_16 -> V_74 = V_31 ;
V_43 = V_38 -> V_75 ( V_16 ) ;
if ( V_43 != 0 ) {
F_31 ( V_38 -> V_7 ) ;
F_32 ( V_16 ) ;
goto V_65;
}
V_44 = 1 ;
} else if ( V_25 [ V_67 ] && F_4 ( V_25 [ V_67 ] , V_16 -> V_8 -> V_3 ) )
goto V_65;
V_42 = V_16 -> V_8 -> V_64 ( V_16 , V_4 -> V_76 ) ;
if ( V_42 == 0 ) {
if ( V_22 -> V_45 == V_77 && V_4 -> V_76 == 0 ) {
F_33 ( V_27 ) ;
* V_36 = V_16 -> V_66 ;
F_34 ( V_27 ) ;
F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_77 ) ;
F_36 ( V_16 ) ;
V_43 = 0 ;
goto V_65;
}
V_43 = - V_14 ;
if ( V_22 -> V_45 != V_53 ||
! ( V_22 -> V_54 & V_55 ) )
goto V_65;
} else {
switch ( V_22 -> V_45 ) {
case V_53 :
V_43 = - V_10 ;
if ( V_22 -> V_54 & V_78 ) {
if ( V_44 )
F_36 ( V_16 ) ;
goto V_65;
}
break;
case V_77 :
V_43 = V_16 -> V_8 -> V_79 ( V_16 , V_42 ) ;
if ( V_43 == 0 )
F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_77 ) ;
goto V_65;
case V_46 :
V_43 = F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_53 ) ;
goto V_65;
default:
V_43 = - V_60 ;
goto V_65;
}
}
V_43 = V_16 -> V_8 -> V_80 ( V_23 , V_20 , V_16 , V_41 , V_4 -> V_76 , V_25 , & V_42 ,
V_22 -> V_54 & V_55 ? V_81 : V_82 ) ;
if ( V_43 == 0 ) {
if ( V_44 ) {
F_33 ( V_27 ) ;
V_16 -> V_66 = * V_36 ;
* V_36 = V_16 ;
F_34 ( V_27 ) ;
}
F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_53 ) ;
} else {
if ( V_44 )
F_36 ( V_16 ) ;
}
V_65:
if ( V_41 )
V_40 -> V_83 ( V_35 , V_41 ) ;
if ( V_43 == - V_72 )
goto V_50;
return V_43 ;
}
static int F_37 ( struct V_23 * V_23 , struct V_19 * V_20 , struct V_15 * V_16 ,
unsigned long V_42 , T_1 V_84 , T_1 V_85 , T_3 V_86 , int V_87 )
{
struct V_28 * V_88 ;
struct V_21 * V_89 ;
unsigned char * V_90 = F_38 ( V_20 ) ;
V_89 = F_39 ( V_20 , V_84 , V_85 , V_87 , sizeof( * V_88 ) , V_86 ) ;
if ( ! V_89 )
goto V_91;
V_88 = F_19 ( V_89 ) ;
V_88 -> V_92 = V_93 ;
V_88 -> V_94 = 0 ;
V_88 -> V_95 = 0 ;
V_88 -> V_56 = F_40 ( V_16 -> V_35 ) -> V_96 ;
V_88 -> V_52 = V_16 -> V_74 ;
V_88 -> V_51 = F_14 ( V_16 -> V_18 , V_16 -> V_29 ) ;
if ( F_41 ( V_20 , V_67 , V_16 -> V_8 -> V_3 ) )
goto V_97;
V_88 -> V_76 = V_42 ;
if ( V_77 != V_87 ) {
V_88 -> V_76 = 0 ;
if ( V_16 -> V_8 -> V_98 && V_16 -> V_8 -> V_98 ( V_23 , V_16 , V_42 , V_20 , V_88 ) < 0 )
goto V_97;
}
V_89 -> V_99 = F_38 ( V_20 ) - V_90 ;
return V_20 -> V_100 ;
V_91:
V_97:
F_42 ( V_20 , V_90 ) ;
return - 1 ;
}
static int F_35 ( struct V_23 * V_23 , struct V_19 * V_101 ,
struct V_21 * V_22 , struct V_15 * V_16 ,
unsigned long V_42 , int V_87 )
{
struct V_19 * V_20 ;
T_1 V_84 = V_101 ? F_43 ( V_101 ) . V_84 : 0 ;
V_20 = F_44 ( V_102 , V_69 ) ;
if ( ! V_20 )
return - V_68 ;
if ( F_37 ( V_23 , V_20 , V_16 , V_42 , V_84 , V_22 -> V_103 , 0 , V_87 ) <= 0 ) {
F_45 ( V_20 ) ;
return - V_60 ;
}
return F_46 ( V_20 , V_23 , V_84 , V_104 ,
V_22 -> V_54 & V_105 ) ;
}
static int F_47 ( struct V_15 * V_16 , unsigned long V_22 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 = ( void * ) V_107 ;
struct V_23 * V_23 = F_16 ( V_109 -> V_20 -> V_24 ) ;
return F_37 ( V_23 , V_109 -> V_20 , V_16 , V_22 , F_43 ( V_109 -> V_110 -> V_20 ) . V_84 ,
V_109 -> V_110 -> V_89 -> V_103 , V_111 , V_53 ) ;
}
static int F_48 ( struct V_19 * V_20 , struct V_112 * V_110 )
{
struct V_23 * V_23 = F_16 ( V_20 -> V_24 ) ;
int V_4 ;
int V_113 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_15 * V_16 , * * V_37 ;
struct V_28 * V_88 = F_19 ( V_110 -> V_89 ) ;
unsigned long V_41 = 0 ;
const struct V_39 * V_40 ;
struct V_108 V_107 ;
if ( V_99 ( V_110 -> V_89 ) < sizeof( * V_88 ) )
return V_20 -> V_100 ;
V_33 = F_22 ( V_23 , V_88 -> V_56 ) ;
if ( ! V_33 )
return V_20 -> V_100 ;
if ( ! V_88 -> V_52 )
V_35 = V_33 -> V_58 ;
else
V_35 = F_23 ( V_33 , F_21 ( V_88 -> V_52 ) ) ;
if ( ! V_35 )
goto V_11;
V_40 = V_35 -> V_8 -> V_61 ;
if ( ! V_40 )
goto V_65;
if ( V_40 -> V_62 == NULL )
goto V_65;
if ( F_20 ( V_88 -> V_52 ) ) {
V_41 = V_40 -> V_64 ( V_35 , V_88 -> V_52 ) ;
if ( V_41 == 0 )
goto V_65;
}
V_37 = V_40 -> V_62 ( V_35 , V_41 ) ;
if ( V_37 == NULL )
goto V_65;
V_113 = V_110 -> args [ 0 ] ;
for ( V_16 = * V_37 , V_4 = 0 ; V_16 ; V_16 = V_16 -> V_66 , V_4 ++ ) {
if ( V_4 < V_113 )
continue;
if ( F_21 ( V_88 -> V_51 ) &&
F_21 ( V_88 -> V_51 ) != V_16 -> V_18 )
continue;
if ( F_20 ( V_88 -> V_51 ) &&
F_20 ( V_88 -> V_51 ) != V_16 -> V_29 )
continue;
if ( V_4 > V_113 )
memset ( & V_110 -> args [ 1 ] , 0 , sizeof( V_110 -> args ) - sizeof( V_110 -> args [ 0 ] ) ) ;
if ( V_110 -> args [ 1 ] == 0 ) {
if ( F_37 ( V_23 , V_20 , V_16 , 0 , F_43 ( V_110 -> V_20 ) . V_84 ,
V_110 -> V_89 -> V_103 , V_111 ,
V_53 ) <= 0 )
break;
V_110 -> args [ 1 ] = 1 ;
}
if ( V_16 -> V_8 -> V_114 == NULL )
continue;
V_107 . V_115 . V_116 = F_47 ;
V_107 . V_20 = V_20 ;
V_107 . V_110 = V_110 ;
V_107 . V_115 . V_117 = 0 ;
V_107 . V_115 . V_118 = V_110 -> args [ 1 ] - 1 ;
V_107 . V_115 . V_119 = 0 ;
V_16 -> V_8 -> V_114 ( V_16 , & V_107 . V_115 ) ;
V_110 -> args [ 1 ] = V_107 . V_115 . V_119 + 1 ;
if ( V_107 . V_115 . V_117 )
break;
}
V_110 -> args [ 0 ] = V_4 ;
V_65:
if ( V_41 )
V_40 -> V_83 ( V_35 , V_41 ) ;
V_11:
return V_20 -> V_100 ;
}
void F_49 ( struct V_15 * V_16 , struct V_120 * V_121 )
{
#ifdef F_50
F_51 ( & V_121 -> V_122 , V_123 ) ;
F_52 ( & V_121 -> V_122 ) ;
#endif
}
int F_53 ( struct V_23 * V_23 , struct V_15 * V_16 , struct V_2 * * V_124 ,
struct V_2 * V_125 , struct V_120 * V_121 , bool V_126 )
{
#ifdef F_50
{
struct V_127 * V_128 ;
F_52 ( & V_121 -> V_122 ) ;
if ( V_121 -> V_129 && V_124 [ V_121 -> V_129 ] ) {
V_128 = F_54 ( V_23 , V_124 [ V_121 -> V_129 ] , V_125 ,
L_2 , V_126 ,
V_130 ) ;
if ( F_55 ( V_128 ) )
return F_56 ( V_128 ) ;
V_128 -> type = V_121 -> type = V_131 ;
F_57 ( & V_128 -> V_132 , & V_121 -> V_122 ) ;
} else if ( V_121 -> V_133 && V_124 [ V_121 -> V_133 ] ) {
int V_43 ;
V_43 = F_58 ( V_23 , V_124 [ V_121 -> V_133 ] , V_125 ,
NULL , V_126 ,
V_130 , & V_121 -> V_122 ) ;
if ( V_43 )
return V_43 ;
}
}
#else
if ( ( V_121 -> V_133 && V_124 [ V_121 -> V_133 ] ) ||
( V_121 -> V_129 && V_124 [ V_121 -> V_129 ] ) )
return - V_63 ;
#endif
return 0 ;
}
void F_59 ( struct V_15 * V_16 , struct V_120 * V_134 ,
struct V_120 * V_135 )
{
#ifdef F_50
F_60 ( V_136 ) ;
F_61 ( V_16 ) ;
F_62 ( & V_134 -> V_122 , & V_136 ) ;
F_63 ( & V_135 -> V_122 , & V_134 -> V_122 ) ;
F_64 ( V_16 ) ;
F_51 ( & V_136 , V_123 ) ;
#endif
}
int F_65 ( struct V_19 * V_20 , struct V_120 * V_121 )
{
#ifdef F_50
struct V_2 * V_137 ;
if ( V_121 -> V_133 && ! F_66 ( & V_121 -> V_122 ) ) {
if ( V_121 -> type != V_131 ) {
V_137 = F_67 ( V_20 , V_121 -> V_133 ) ;
if ( V_137 == NULL )
goto V_97;
if ( F_68 ( V_20 , & V_121 -> V_122 , 0 , 0 ) < 0 )
goto V_97;
F_69 ( V_20 , V_137 ) ;
} else if ( V_121 -> V_129 ) {
struct V_127 * V_128 = F_70 ( V_121 ) ;
V_137 = F_67 ( V_20 , V_121 -> V_129 ) ;
if ( V_137 == NULL || ! V_128 )
goto V_97;
if ( F_71 ( V_20 , V_128 , 0 , 0 ) < 0 )
goto V_97;
F_69 ( V_20 , V_137 ) ;
}
}
return 0 ;
V_97:
F_72 ( V_20 , V_137 ) ;
return - 1 ;
#else
return 0 ;
#endif
}
int F_73 ( struct V_19 * V_20 , struct V_120 * V_121 )
{
#ifdef F_50
struct V_127 * V_109 = F_70 ( V_121 ) ;
if ( F_74 ( V_20 , V_109 , 1 ) < 0 )
return - 1 ;
#endif
return 0 ;
}
static int T_4 F_75 ( void )
{
F_76 ( V_138 , V_53 , F_15 , NULL , NULL ) ;
F_76 ( V_138 , V_77 , F_15 , NULL , NULL ) ;
F_76 ( V_138 , V_46 , F_15 ,
F_48 , NULL ) ;
return 0 ;
}
