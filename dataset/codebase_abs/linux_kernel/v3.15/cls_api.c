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
if ( ( V_22 -> V_45 != V_46 ) && ! F_17 ( V_20 , V_47 ) )
return - V_48 ;
V_49:
V_43 = F_18 ( V_22 , sizeof( * V_4 ) , V_25 , V_26 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
V_4 = F_19 ( V_22 ) ;
V_29 = F_20 ( V_4 -> V_50 ) ;
V_18 = F_21 ( V_4 -> V_50 ) ;
V_30 = V_18 ;
V_31 = V_4 -> V_51 ;
V_41 = 0 ;
if ( V_18 == 0 ) {
if ( V_22 -> V_45 != V_52 ||
! ( V_22 -> V_53 & V_54 ) )
return - V_14 ;
V_18 = F_14 ( 0x80000000U , 0U ) ;
}
V_33 = F_22 ( V_23 , V_4 -> V_55 ) ;
if ( V_33 == NULL )
return - V_56 ;
if ( ! V_31 ) {
V_35 = V_33 -> V_57 ;
V_31 = V_35 -> V_58 ;
} else {
V_35 = F_23 ( V_33 , F_21 ( V_4 -> V_51 ) ) ;
if ( V_35 == NULL )
return - V_59 ;
}
V_40 = V_35 -> V_8 -> V_60 ;
if ( ! V_40 )
return - V_59 ;
if ( V_40 -> V_61 == NULL )
return - V_62 ;
if ( F_20 ( V_31 ) ) {
V_41 = V_40 -> V_63 ( V_35 , V_31 ) ;
if ( V_41 == 0 )
return - V_14 ;
}
V_37 = V_40 -> V_61 ( V_35 , V_41 ) ;
V_43 = - V_59 ;
if ( V_37 == NULL )
goto V_64;
for ( V_36 = V_37 ; ( V_16 = * V_36 ) != NULL ; V_36 = & V_16 -> V_65 ) {
if ( V_16 -> V_18 >= V_18 ) {
if ( V_16 -> V_18 == V_18 ) {
if ( ! V_30 ||
( V_16 -> V_29 != V_29 && V_29 ) )
goto V_64;
} else
V_16 = NULL ;
break;
}
}
V_27 = F_24 ( V_35 ) ;
if ( V_16 == NULL ) {
if ( V_25 [ V_66 ] == NULL || ! V_29 )
goto V_64;
V_43 = - V_14 ;
if ( V_22 -> V_45 != V_52 ||
! ( V_22 -> V_53 & V_54 ) )
goto V_64;
V_43 = - V_67 ;
V_16 = F_25 ( sizeof( * V_16 ) , V_68 ) ;
if ( V_16 == NULL )
goto V_64;
V_43 = - V_14 ;
V_38 = F_1 ( V_25 [ V_66 ] ) ;
if ( V_38 == NULL ) {
#ifdef F_26
struct V_2 * V_3 = V_25 [ V_66 ] ;
char V_69 [ V_70 ] ;
if ( V_3 != NULL &&
F_27 ( V_69 , V_3 , V_70 ) < V_70 ) {
F_28 () ;
F_29 ( L_1 , V_69 ) ;
F_30 () ;
V_38 = F_1 ( V_3 ) ;
if ( V_38 != NULL ) {
F_31 ( V_38 -> V_7 ) ;
V_43 = - V_71 ;
}
}
#endif
F_32 ( V_16 ) ;
goto V_64;
}
V_16 -> V_8 = V_38 ;
V_16 -> V_29 = V_29 ;
V_16 -> V_18 = V_30 ? : F_21 ( F_13 ( * V_36 ) ) ;
V_16 -> V_35 = V_35 ;
V_16 -> V_72 = V_38 -> V_72 ;
V_16 -> V_73 = V_31 ;
V_43 = V_38 -> V_74 ( V_16 ) ;
if ( V_43 != 0 ) {
F_31 ( V_38 -> V_7 ) ;
F_32 ( V_16 ) ;
goto V_64;
}
V_44 = 1 ;
} else if ( V_25 [ V_66 ] && F_4 ( V_25 [ V_66 ] , V_16 -> V_8 -> V_3 ) )
goto V_64;
V_42 = V_16 -> V_8 -> V_63 ( V_16 , V_4 -> V_75 ) ;
if ( V_42 == 0 ) {
if ( V_22 -> V_45 == V_76 && V_4 -> V_75 == 0 ) {
F_33 ( V_27 ) ;
* V_36 = V_16 -> V_65 ;
F_34 ( V_27 ) ;
F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_76 ) ;
F_36 ( V_16 ) ;
V_43 = 0 ;
goto V_64;
}
V_43 = - V_14 ;
if ( V_22 -> V_45 != V_52 ||
! ( V_22 -> V_53 & V_54 ) )
goto V_64;
} else {
switch ( V_22 -> V_45 ) {
case V_52 :
V_43 = - V_10 ;
if ( V_22 -> V_53 & V_77 ) {
if ( V_44 )
F_36 ( V_16 ) ;
goto V_64;
}
break;
case V_76 :
V_43 = V_16 -> V_8 -> V_78 ( V_16 , V_42 ) ;
if ( V_43 == 0 )
F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_76 ) ;
goto V_64;
case V_46 :
V_43 = F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_52 ) ;
goto V_64;
default:
V_43 = - V_59 ;
goto V_64;
}
}
V_43 = V_16 -> V_8 -> V_79 ( V_23 , V_20 , V_16 , V_41 , V_4 -> V_75 , V_25 , & V_42 ) ;
if ( V_43 == 0 ) {
if ( V_44 ) {
F_33 ( V_27 ) ;
V_16 -> V_65 = * V_36 ;
* V_36 = V_16 ;
F_34 ( V_27 ) ;
}
F_35 ( V_23 , V_20 , V_22 , V_16 , V_42 , V_52 ) ;
} else {
if ( V_44 )
F_36 ( V_16 ) ;
}
V_64:
if ( V_41 )
V_40 -> V_80 ( V_35 , V_41 ) ;
if ( V_43 == - V_71 )
goto V_49;
return V_43 ;
}
static int F_37 ( struct V_23 * V_23 , struct V_19 * V_20 , struct V_15 * V_16 ,
unsigned long V_42 , T_1 V_81 , T_1 V_82 , T_3 V_83 , int V_84 )
{
struct V_28 * V_85 ;
struct V_21 * V_86 ;
unsigned char * V_87 = F_38 ( V_20 ) ;
V_86 = F_39 ( V_20 , V_81 , V_82 , V_84 , sizeof( * V_85 ) , V_83 ) ;
if ( ! V_86 )
goto V_88;
V_85 = F_19 ( V_86 ) ;
V_85 -> V_89 = V_90 ;
V_85 -> V_91 = 0 ;
V_85 -> V_92 = 0 ;
V_85 -> V_55 = F_40 ( V_16 -> V_35 ) -> V_93 ;
V_85 -> V_51 = V_16 -> V_73 ;
V_85 -> V_50 = F_14 ( V_16 -> V_18 , V_16 -> V_29 ) ;
if ( F_41 ( V_20 , V_66 , V_16 -> V_8 -> V_3 ) )
goto V_94;
V_85 -> V_75 = V_42 ;
if ( V_76 != V_84 ) {
V_85 -> V_75 = 0 ;
if ( V_16 -> V_8 -> V_95 && V_16 -> V_8 -> V_95 ( V_23 , V_16 , V_42 , V_20 , V_85 ) < 0 )
goto V_94;
}
V_86 -> V_96 = F_38 ( V_20 ) - V_87 ;
return V_20 -> V_97 ;
V_88:
V_94:
F_42 ( V_20 , V_87 ) ;
return - 1 ;
}
static int F_35 ( struct V_23 * V_23 , struct V_19 * V_98 ,
struct V_21 * V_22 , struct V_15 * V_16 ,
unsigned long V_42 , int V_84 )
{
struct V_19 * V_20 ;
T_1 V_81 = V_98 ? F_43 ( V_98 ) . V_81 : 0 ;
V_20 = F_44 ( V_99 , V_68 ) ;
if ( ! V_20 )
return - V_67 ;
if ( F_37 ( V_23 , V_20 , V_16 , V_42 , V_81 , V_22 -> V_100 , 0 , V_84 ) <= 0 ) {
F_45 ( V_20 ) ;
return - V_59 ;
}
return F_46 ( V_20 , V_23 , V_81 , V_101 ,
V_22 -> V_53 & V_102 ) ;
}
static int F_47 ( struct V_15 * V_16 , unsigned long V_22 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 = ( void * ) V_104 ;
struct V_23 * V_23 = F_16 ( V_106 -> V_20 -> V_24 ) ;
return F_37 ( V_23 , V_106 -> V_20 , V_16 , V_22 , F_43 ( V_106 -> V_107 -> V_20 ) . V_81 ,
V_106 -> V_107 -> V_86 -> V_100 , V_108 , V_52 ) ;
}
static int F_48 ( struct V_19 * V_20 , struct V_109 * V_107 )
{
struct V_23 * V_23 = F_16 ( V_20 -> V_24 ) ;
int V_4 ;
int V_110 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_15 * V_16 , * * V_37 ;
struct V_28 * V_85 = F_19 ( V_107 -> V_86 ) ;
unsigned long V_41 = 0 ;
const struct V_39 * V_40 ;
struct V_105 V_104 ;
if ( V_96 ( V_107 -> V_86 ) < sizeof( * V_85 ) )
return V_20 -> V_97 ;
V_33 = F_22 ( V_23 , V_85 -> V_55 ) ;
if ( ! V_33 )
return V_20 -> V_97 ;
if ( ! V_85 -> V_51 )
V_35 = V_33 -> V_57 ;
else
V_35 = F_23 ( V_33 , F_21 ( V_85 -> V_51 ) ) ;
if ( ! V_35 )
goto V_11;
V_40 = V_35 -> V_8 -> V_60 ;
if ( ! V_40 )
goto V_64;
if ( V_40 -> V_61 == NULL )
goto V_64;
if ( F_20 ( V_85 -> V_51 ) ) {
V_41 = V_40 -> V_63 ( V_35 , V_85 -> V_51 ) ;
if ( V_41 == 0 )
goto V_64;
}
V_37 = V_40 -> V_61 ( V_35 , V_41 ) ;
if ( V_37 == NULL )
goto V_64;
V_110 = V_107 -> args [ 0 ] ;
for ( V_16 = * V_37 , V_4 = 0 ; V_16 ; V_16 = V_16 -> V_65 , V_4 ++ ) {
if ( V_4 < V_110 )
continue;
if ( F_21 ( V_85 -> V_50 ) &&
F_21 ( V_85 -> V_50 ) != V_16 -> V_18 )
continue;
if ( F_20 ( V_85 -> V_50 ) &&
F_20 ( V_85 -> V_50 ) != V_16 -> V_29 )
continue;
if ( V_4 > V_110 )
memset ( & V_107 -> args [ 1 ] , 0 , sizeof( V_107 -> args ) - sizeof( V_107 -> args [ 0 ] ) ) ;
if ( V_107 -> args [ 1 ] == 0 ) {
if ( F_37 ( V_23 , V_20 , V_16 , 0 , F_43 ( V_107 -> V_20 ) . V_81 ,
V_107 -> V_86 -> V_100 , V_108 ,
V_52 ) <= 0 )
break;
V_107 -> args [ 1 ] = 1 ;
}
if ( V_16 -> V_8 -> V_111 == NULL )
continue;
V_104 . V_112 . V_113 = F_47 ;
V_104 . V_20 = V_20 ;
V_104 . V_107 = V_107 ;
V_104 . V_112 . V_114 = 0 ;
V_104 . V_112 . V_115 = V_107 -> args [ 1 ] - 1 ;
V_104 . V_112 . V_116 = 0 ;
V_16 -> V_8 -> V_111 ( V_16 , & V_104 . V_112 ) ;
V_107 -> args [ 1 ] = V_104 . V_112 . V_116 + 1 ;
if ( V_104 . V_112 . V_114 )
break;
}
V_107 -> args [ 0 ] = V_4 ;
V_64:
if ( V_41 )
V_40 -> V_80 ( V_35 , V_41 ) ;
V_11:
return V_20 -> V_97 ;
}
void F_49 ( struct V_15 * V_16 , struct V_117 * V_118 )
{
#ifdef F_50
F_51 ( & V_118 -> V_119 , V_120 ) ;
F_52 ( & V_118 -> V_119 ) ;
#endif
}
int F_53 ( struct V_23 * V_23 , struct V_15 * V_16 , struct V_2 * * V_121 ,
struct V_2 * V_122 , struct V_117 * V_118 )
{
#ifdef F_50
{
struct V_123 * V_124 ;
F_52 ( & V_118 -> V_119 ) ;
if ( V_118 -> V_125 && V_121 [ V_118 -> V_125 ] ) {
V_124 = F_54 ( V_23 , V_121 [ V_118 -> V_125 ] , V_122 ,
L_2 , V_126 ,
V_127 ) ;
if ( F_55 ( V_124 ) )
return F_56 ( V_124 ) ;
V_124 -> type = V_118 -> type = V_128 ;
F_57 ( & V_124 -> V_129 , & V_118 -> V_119 ) ;
} else if ( V_118 -> V_130 && V_121 [ V_118 -> V_130 ] ) {
int V_43 ;
V_43 = F_58 ( V_23 , V_121 [ V_118 -> V_130 ] , V_122 ,
NULL , V_126 ,
V_127 , & V_118 -> V_119 ) ;
if ( V_43 )
return V_43 ;
}
}
#else
if ( ( V_118 -> V_130 && V_121 [ V_118 -> V_130 ] ) ||
( V_118 -> V_125 && V_121 [ V_118 -> V_125 ] ) )
return - V_62 ;
#endif
return 0 ;
}
void F_59 ( struct V_15 * V_16 , struct V_117 * V_131 ,
struct V_117 * V_132 )
{
#ifdef F_50
if ( ! F_60 ( & V_132 -> V_119 ) ) {
F_61 ( V_133 ) ;
F_62 ( V_16 ) ;
F_63 ( & V_131 -> V_119 , & V_133 ) ;
F_64 ( & V_132 -> V_119 , & V_131 -> V_119 ) ;
F_65 ( V_16 ) ;
F_51 ( & V_133 , V_120 ) ;
}
#endif
}
int F_66 ( struct V_19 * V_20 , struct V_117 * V_118 )
{
#ifdef F_50
if ( V_118 -> V_130 && ! F_60 ( & V_118 -> V_119 ) ) {
struct V_2 * V_134 ;
if ( V_118 -> type != V_128 ) {
V_134 = F_67 ( V_20 , V_118 -> V_130 ) ;
if ( V_134 == NULL )
goto V_94;
if ( F_68 ( V_20 , & V_118 -> V_119 , 0 , 0 ) < 0 )
goto V_94;
F_69 ( V_20 , V_134 ) ;
} else if ( V_118 -> V_125 ) {
struct V_123 * V_124 = F_70 ( V_118 ) ;
V_134 = F_67 ( V_20 , V_118 -> V_125 ) ;
if ( V_134 == NULL || ! V_124 )
goto V_94;
if ( F_71 ( V_20 , V_124 , 0 , 0 ) < 0 )
goto V_94;
F_69 ( V_20 , V_134 ) ;
}
}
#endif
return 0 ;
V_94: F_72 ((unused))
return - 1 ;
}
int F_73 ( struct V_19 * V_20 , struct V_117 * V_118 )
{
#ifdef F_50
struct V_123 * V_106 = F_70 ( V_118 ) ;
if ( F_74 ( V_20 , V_106 , 1 ) < 0 )
return - 1 ;
#endif
return 0 ;
}
static int T_4 F_75 ( void )
{
F_76 ( V_135 , V_52 , F_15 , NULL , NULL ) ;
F_76 ( V_135 , V_76 , F_15 , NULL , NULL ) ;
F_76 ( V_135 , V_46 , F_15 ,
F_48 , NULL ) ;
return 0 ;
}
