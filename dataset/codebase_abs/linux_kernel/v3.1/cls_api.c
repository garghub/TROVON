static const struct V_1 * F_1 ( struct V_2 * V_3 )
{
const struct V_1 * V_4 = NULL ;
if ( V_3 ) {
F_2 ( & V_5 ) ;
for ( V_4 = V_6 ; V_4 ; V_4 = V_4 -> V_7 ) {
if ( F_3 ( V_3 , V_4 -> V_3 ) == 0 ) {
if ( ! F_4 ( V_4 -> V_8 ) )
V_4 = NULL ;
break;
}
}
F_5 ( & V_5 ) ;
}
return V_4 ;
}
int F_6 ( struct V_1 * V_9 )
{
struct V_1 * V_4 , * * V_10 ;
int V_11 = - V_12 ;
F_7 ( & V_5 ) ;
for ( V_10 = & V_6 ; ( V_4 = * V_10 ) != NULL ; V_10 = & V_4 -> V_7 )
if ( ! strcmp ( V_9 -> V_3 , V_4 -> V_3 ) )
goto V_13;
V_9 -> V_7 = NULL ;
* V_10 = V_9 ;
V_11 = 0 ;
V_13:
F_8 ( & V_5 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_9 )
{
struct V_1 * V_4 , * * V_10 ;
int V_11 = - V_14 ;
F_7 ( & V_5 ) ;
for ( V_10 = & V_6 ; ( V_4 = * V_10 ) != NULL ; V_10 = & V_4 -> V_7 )
if ( V_4 == V_9 )
break;
if ( ! V_4 )
goto V_13;
* V_10 = V_4 -> V_7 ;
V_11 = 0 ;
V_13:
F_8 ( & V_5 ) ;
return V_11 ;
}
static inline T_1 F_10 ( struct V_15 * V_10 )
{
T_1 V_16 = F_11 ( 0xC0000000U , 0U ) ;
if ( V_10 )
V_16 = V_10 -> V_17 - 1 ;
return V_16 ;
}
static int F_12 ( struct V_18 * V_19 , struct V_20 * V_21 , void * V_22 )
{
struct V_23 * V_23 = F_13 ( V_19 -> V_24 ) ;
struct V_2 * V_25 [ V_26 + 1 ] ;
T_2 * V_27 ;
struct V_28 * V_4 ;
T_1 V_29 ;
T_1 V_17 ;
T_1 V_30 ;
T_1 V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_15 * * V_36 , * * V_37 ;
struct V_15 * V_10 ;
const struct V_1 * V_38 ;
const struct V_39 * V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
int V_43 ;
int V_44 = 0 ;
V_45:
V_4 = F_14 ( V_21 ) ;
V_29 = F_15 ( V_4 -> V_46 ) ;
V_17 = F_16 ( V_4 -> V_46 ) ;
V_30 = V_17 ;
V_31 = V_4 -> V_47 ;
V_41 = 0 ;
if ( V_17 == 0 ) {
if ( V_21 -> V_48 != V_49 ||
! ( V_21 -> V_50 & V_51 ) )
return - V_14 ;
V_17 = F_11 ( 0x80000000U , 0U ) ;
}
V_33 = F_17 ( V_23 , V_4 -> V_52 ) ;
if ( V_33 == NULL )
return - V_53 ;
V_43 = F_18 ( V_21 , sizeof( * V_4 ) , V_25 , V_26 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_31 ) {
V_35 = V_33 -> V_54 ;
V_31 = V_35 -> V_55 ;
} else {
V_35 = F_19 ( V_33 , F_16 ( V_4 -> V_47 ) ) ;
if ( V_35 == NULL )
return - V_56 ;
}
V_40 = V_35 -> V_9 -> V_57 ;
if ( ! V_40 )
return - V_56 ;
if ( V_40 -> V_58 == NULL )
return - V_59 ;
if ( F_15 ( V_31 ) ) {
V_41 = V_40 -> V_60 ( V_35 , V_31 ) ;
if ( V_41 == 0 )
return - V_14 ;
}
V_37 = V_40 -> V_58 ( V_35 , V_41 ) ;
V_43 = - V_56 ;
if ( V_37 == NULL )
goto V_61;
for ( V_36 = V_37 ; ( V_10 = * V_36 ) != NULL ; V_36 = & V_10 -> V_7 ) {
if ( V_10 -> V_17 >= V_17 ) {
if ( V_10 -> V_17 == V_17 ) {
if ( ! V_30 ||
( V_10 -> V_29 != V_29 && V_29 ) )
goto V_61;
} else
V_10 = NULL ;
break;
}
}
V_27 = F_20 ( V_35 ) ;
if ( V_10 == NULL ) {
if ( V_25 [ V_62 ] == NULL || ! V_29 )
goto V_61;
V_43 = - V_14 ;
if ( V_21 -> V_48 != V_49 ||
! ( V_21 -> V_50 & V_51 ) )
goto V_61;
V_43 = - V_63 ;
V_10 = F_21 ( sizeof( * V_10 ) , V_64 ) ;
if ( V_10 == NULL )
goto V_61;
V_43 = - V_14 ;
V_38 = F_1 ( V_25 [ V_62 ] ) ;
if ( V_38 == NULL ) {
#ifdef F_22
struct V_2 * V_3 = V_25 [ V_62 ] ;
char V_65 [ V_66 ] ;
if ( V_3 != NULL &&
F_23 ( V_65 , V_3 , V_66 ) < V_66 ) {
F_24 () ;
F_25 ( L_1 , V_65 ) ;
F_26 () ;
V_38 = F_1 ( V_3 ) ;
if ( V_38 != NULL ) {
F_27 ( V_38 -> V_8 ) ;
V_43 = - V_67 ;
}
}
#endif
F_28 ( V_10 ) ;
goto V_61;
}
V_10 -> V_9 = V_38 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_17 = V_30 ? : F_16 ( F_10 ( * V_36 ) ) ;
V_10 -> V_35 = V_35 ;
V_10 -> V_68 = V_38 -> V_68 ;
V_10 -> V_69 = V_31 ;
V_43 = V_38 -> V_70 ( V_10 ) ;
if ( V_43 != 0 ) {
F_27 ( V_38 -> V_8 ) ;
F_28 ( V_10 ) ;
goto V_61;
}
V_44 = 1 ;
} else if ( V_25 [ V_62 ] && F_3 ( V_25 [ V_62 ] , V_10 -> V_9 -> V_3 ) )
goto V_61;
V_42 = V_10 -> V_9 -> V_60 ( V_10 , V_4 -> V_71 ) ;
if ( V_42 == 0 ) {
if ( V_21 -> V_48 == V_72 && V_4 -> V_71 == 0 ) {
F_29 ( V_27 ) ;
* V_36 = V_10 -> V_7 ;
F_30 ( V_27 ) ;
F_31 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_72 ) ;
F_32 ( V_10 ) ;
V_43 = 0 ;
goto V_61;
}
V_43 = - V_14 ;
if ( V_21 -> V_48 != V_49 ||
! ( V_21 -> V_50 & V_51 ) )
goto V_61;
} else {
switch ( V_21 -> V_48 ) {
case V_49 :
V_43 = - V_12 ;
if ( V_21 -> V_50 & V_73 ) {
if ( V_44 )
F_32 ( V_10 ) ;
goto V_61;
}
break;
case V_72 :
V_43 = V_10 -> V_9 -> V_74 ( V_10 , V_42 ) ;
if ( V_43 == 0 )
F_31 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_72 ) ;
goto V_61;
case V_75 :
V_43 = F_31 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_49 ) ;
goto V_61;
default:
V_43 = - V_56 ;
goto V_61;
}
}
V_43 = V_10 -> V_9 -> V_76 ( V_10 , V_41 , V_4 -> V_71 , V_25 , & V_42 ) ;
if ( V_43 == 0 ) {
if ( V_44 ) {
F_29 ( V_27 ) ;
V_10 -> V_7 = * V_36 ;
* V_36 = V_10 ;
F_30 ( V_27 ) ;
}
F_31 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_49 ) ;
} else {
if ( V_44 )
F_32 ( V_10 ) ;
}
V_61:
if ( V_41 )
V_40 -> V_77 ( V_35 , V_41 ) ;
if ( V_43 == - V_67 )
goto V_45;
return V_43 ;
}
static int F_33 ( struct V_18 * V_19 , struct V_15 * V_10 ,
unsigned long V_42 , T_1 V_78 , T_1 V_79 , T_3 V_80 , int V_81 )
{
struct V_28 * V_82 ;
struct V_20 * V_83 ;
unsigned char * V_84 = F_34 ( V_19 ) ;
V_83 = F_35 ( V_19 , V_78 , V_79 , V_81 , sizeof( * V_82 ) , V_80 ) ;
V_82 = F_14 ( V_83 ) ;
V_82 -> V_85 = V_86 ;
V_82 -> V_87 = 0 ;
V_82 -> V_88 = 0 ;
V_82 -> V_52 = F_36 ( V_10 -> V_35 ) -> V_89 ;
V_82 -> V_47 = V_10 -> V_69 ;
V_82 -> V_46 = F_11 ( V_10 -> V_17 , V_10 -> V_29 ) ;
F_37 ( V_19 , V_62 , V_10 -> V_9 -> V_3 ) ;
V_82 -> V_71 = V_42 ;
if ( V_72 != V_81 ) {
V_82 -> V_71 = 0 ;
if ( V_10 -> V_9 -> V_90 && V_10 -> V_9 -> V_90 ( V_10 , V_42 , V_19 , V_82 ) < 0 )
goto V_91;
}
V_83 -> V_92 = F_34 ( V_19 ) - V_84 ;
return V_19 -> V_93 ;
V_94:
V_91:
F_38 ( V_19 , V_84 ) ;
return - 1 ;
}
static int F_31 ( struct V_23 * V_23 , struct V_18 * V_95 ,
struct V_20 * V_21 , struct V_15 * V_10 ,
unsigned long V_42 , int V_81 )
{
struct V_18 * V_19 ;
T_1 V_78 = V_95 ? F_39 ( V_95 ) . V_78 : 0 ;
V_19 = F_40 ( V_96 , V_64 ) ;
if ( ! V_19 )
return - V_63 ;
if ( F_33 ( V_19 , V_10 , V_42 , V_78 , V_21 -> V_97 , 0 , V_81 ) <= 0 ) {
F_41 ( V_19 ) ;
return - V_56 ;
}
return F_42 ( V_19 , V_23 , V_78 , V_98 ,
V_21 -> V_50 & V_99 ) ;
}
static int F_43 ( struct V_15 * V_10 , unsigned long V_21 ,
struct V_100 * V_22 )
{
struct V_101 * V_102 = ( void * ) V_22 ;
return F_33 ( V_102 -> V_19 , V_10 , V_21 , F_39 ( V_102 -> V_103 -> V_19 ) . V_78 ,
V_102 -> V_103 -> V_83 -> V_97 , V_104 , V_49 ) ;
}
static int F_44 ( struct V_18 * V_19 , struct V_105 * V_103 )
{
struct V_23 * V_23 = F_13 ( V_19 -> V_24 ) ;
int V_4 ;
int V_106 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_15 * V_10 , * * V_37 ;
struct V_28 * V_82 = (struct V_28 * ) F_14 ( V_103 -> V_83 ) ;
unsigned long V_41 = 0 ;
const struct V_39 * V_40 ;
struct V_101 V_22 ;
if ( V_103 -> V_83 -> V_92 < F_45 ( sizeof( * V_82 ) ) )
return V_19 -> V_93 ;
V_33 = F_17 ( V_23 , V_82 -> V_52 ) ;
if ( ! V_33 )
return V_19 -> V_93 ;
if ( ! V_82 -> V_47 )
V_35 = V_33 -> V_54 ;
else
V_35 = F_19 ( V_33 , F_16 ( V_82 -> V_47 ) ) ;
if ( ! V_35 )
goto V_13;
V_40 = V_35 -> V_9 -> V_57 ;
if ( ! V_40 )
goto V_61;
if ( V_40 -> V_58 == NULL )
goto V_61;
if ( F_15 ( V_82 -> V_47 ) ) {
V_41 = V_40 -> V_60 ( V_35 , V_82 -> V_47 ) ;
if ( V_41 == 0 )
goto V_61;
}
V_37 = V_40 -> V_58 ( V_35 , V_41 ) ;
if ( V_37 == NULL )
goto V_61;
V_106 = V_103 -> args [ 0 ] ;
for ( V_10 = * V_37 , V_4 = 0 ; V_10 ; V_10 = V_10 -> V_7 , V_4 ++ ) {
if ( V_4 < V_106 )
continue;
if ( F_16 ( V_82 -> V_46 ) &&
F_16 ( V_82 -> V_46 ) != V_10 -> V_17 )
continue;
if ( F_15 ( V_82 -> V_46 ) &&
F_15 ( V_82 -> V_46 ) != V_10 -> V_29 )
continue;
if ( V_4 > V_106 )
memset ( & V_103 -> args [ 1 ] , 0 , sizeof( V_103 -> args ) - sizeof( V_103 -> args [ 0 ] ) ) ;
if ( V_103 -> args [ 1 ] == 0 ) {
if ( F_33 ( V_19 , V_10 , 0 , F_39 ( V_103 -> V_19 ) . V_78 ,
V_103 -> V_83 -> V_97 , V_104 ,
V_49 ) <= 0 )
break;
V_103 -> args [ 1 ] = 1 ;
}
if ( V_10 -> V_9 -> V_107 == NULL )
continue;
V_22 . V_108 . V_109 = F_43 ;
V_22 . V_19 = V_19 ;
V_22 . V_103 = V_103 ;
V_22 . V_108 . V_110 = 0 ;
V_22 . V_108 . V_111 = V_103 -> args [ 1 ] - 1 ;
V_22 . V_108 . V_112 = 0 ;
V_10 -> V_9 -> V_107 ( V_10 , & V_22 . V_108 ) ;
V_103 -> args [ 1 ] = V_22 . V_108 . V_112 + 1 ;
if ( V_22 . V_108 . V_110 )
break;
}
V_103 -> args [ 0 ] = V_4 ;
V_61:
if ( V_41 )
V_40 -> V_77 ( V_35 , V_41 ) ;
V_13:
return V_19 -> V_93 ;
}
void F_46 ( struct V_15 * V_10 , struct V_113 * V_114 )
{
#ifdef F_47
if ( V_114 -> V_115 ) {
F_48 ( V_114 -> V_115 , V_116 ) ;
V_114 -> V_115 = NULL ;
}
#endif
}
int F_49 ( struct V_15 * V_10 , struct V_2 * * V_117 ,
struct V_2 * V_118 , struct V_113 * V_114 ,
const struct V_119 * V_120 )
{
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
#ifdef F_47
{
struct V_121 * V_122 ;
if ( V_120 -> V_123 && V_117 [ V_120 -> V_123 ] ) {
V_122 = F_50 ( V_117 [ V_120 -> V_123 ] , V_118 ,
L_2 , V_124 ,
V_125 ) ;
if ( F_51 ( V_122 ) )
return F_52 ( V_122 ) ;
V_122 -> type = V_126 ;
V_114 -> V_115 = V_122 ;
} else if ( V_120 -> V_115 && V_117 [ V_120 -> V_115 ] ) {
V_122 = F_53 ( V_117 [ V_120 -> V_115 ] , V_118 , NULL ,
V_124 , V_125 ) ;
if ( F_51 ( V_122 ) )
return F_52 ( V_122 ) ;
V_114 -> V_115 = V_122 ;
}
}
#else
if ( ( V_120 -> V_115 && V_117 [ V_120 -> V_115 ] ) ||
( V_120 -> V_123 && V_117 [ V_120 -> V_123 ] ) )
return - V_59 ;
#endif
return 0 ;
}
void F_54 ( struct V_15 * V_10 , struct V_113 * V_127 ,
struct V_113 * V_128 )
{
#ifdef F_47
if ( V_128 -> V_115 ) {
struct V_121 * V_122 ;
F_55 ( V_10 ) ;
V_122 = V_127 -> V_115 ;
V_127 -> V_115 = V_128 -> V_115 ;
F_56 ( V_10 ) ;
if ( V_122 )
F_48 ( V_122 , V_116 ) ;
}
#endif
}
int F_57 ( struct V_18 * V_19 , struct V_113 * V_114 ,
const struct V_119 * V_120 )
{
#ifdef F_47
if ( V_120 -> V_115 && V_114 -> V_115 ) {
struct V_2 * V_129 ;
if ( V_114 -> V_115 -> type != V_126 ) {
V_129 = F_58 ( V_19 , V_120 -> V_115 ) ;
if ( V_129 == NULL )
goto V_91;
if ( F_59 ( V_19 , V_114 -> V_115 , 0 , 0 ) < 0 )
goto V_91;
F_60 ( V_19 , V_129 ) ;
} else if ( V_120 -> V_123 ) {
V_129 = F_58 ( V_19 , V_120 -> V_123 ) ;
if ( V_129 == NULL )
goto V_91;
if ( F_61 ( V_19 , V_114 -> V_115 , 0 , 0 ) < 0 )
goto V_91;
F_60 ( V_19 , V_129 ) ;
}
}
#endif
return 0 ;
V_91: F_62 ((unused))
return - 1 ;
}
int F_63 ( struct V_18 * V_19 , struct V_113 * V_114 ,
const struct V_119 * V_120 )
{
#ifdef F_47
if ( V_114 -> V_115 )
if ( F_64 ( V_19 , V_114 -> V_115 , 1 ) < 0 )
goto V_91;
#endif
return 0 ;
V_91: F_62 ((unused))
return - 1 ;
}
static int T_4 F_65 ( void )
{
F_66 ( V_130 , V_49 , F_12 , NULL , NULL ) ;
F_66 ( V_130 , V_72 , F_12 , NULL , NULL ) ;
F_66 ( V_130 , V_75 , F_12 ,
F_44 , NULL ) ;
return 0 ;
}
