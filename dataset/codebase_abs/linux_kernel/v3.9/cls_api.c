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
if ( ( V_21 -> V_45 != V_46 ) && ! F_14 ( V_47 ) )
return - V_48 ;
V_49:
V_4 = F_15 ( V_21 ) ;
V_29 = F_16 ( V_4 -> V_50 ) ;
V_17 = F_17 ( V_4 -> V_50 ) ;
V_30 = V_17 ;
V_31 = V_4 -> V_51 ;
V_41 = 0 ;
if ( V_17 == 0 ) {
if ( V_21 -> V_45 != V_52 ||
! ( V_21 -> V_53 & V_54 ) )
return - V_14 ;
V_17 = F_11 ( 0x80000000U , 0U ) ;
}
V_33 = F_18 ( V_23 , V_4 -> V_55 ) ;
if ( V_33 == NULL )
return - V_56 ;
V_43 = F_19 ( V_21 , sizeof( * V_4 ) , V_25 , V_26 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_31 ) {
V_35 = V_33 -> V_57 ;
V_31 = V_35 -> V_58 ;
} else {
V_35 = F_20 ( V_33 , F_17 ( V_4 -> V_51 ) ) ;
if ( V_35 == NULL )
return - V_59 ;
}
V_40 = V_35 -> V_9 -> V_60 ;
if ( ! V_40 )
return - V_59 ;
if ( V_40 -> V_61 == NULL )
return - V_62 ;
if ( F_16 ( V_31 ) ) {
V_41 = V_40 -> V_63 ( V_35 , V_31 ) ;
if ( V_41 == 0 )
return - V_14 ;
}
V_37 = V_40 -> V_61 ( V_35 , V_41 ) ;
V_43 = - V_59 ;
if ( V_37 == NULL )
goto V_64;
for ( V_36 = V_37 ; ( V_10 = * V_36 ) != NULL ; V_36 = & V_10 -> V_7 ) {
if ( V_10 -> V_17 >= V_17 ) {
if ( V_10 -> V_17 == V_17 ) {
if ( ! V_30 ||
( V_10 -> V_29 != V_29 && V_29 ) )
goto V_64;
} else
V_10 = NULL ;
break;
}
}
V_27 = F_21 ( V_35 ) ;
if ( V_10 == NULL ) {
if ( V_25 [ V_65 ] == NULL || ! V_29 )
goto V_64;
V_43 = - V_14 ;
if ( V_21 -> V_45 != V_52 ||
! ( V_21 -> V_53 & V_54 ) )
goto V_64;
V_43 = - V_66 ;
V_10 = F_22 ( sizeof( * V_10 ) , V_67 ) ;
if ( V_10 == NULL )
goto V_64;
V_43 = - V_14 ;
V_38 = F_1 ( V_25 [ V_65 ] ) ;
if ( V_38 == NULL ) {
#ifdef F_23
struct V_2 * V_3 = V_25 [ V_65 ] ;
char V_68 [ V_69 ] ;
if ( V_3 != NULL &&
F_24 ( V_68 , V_3 , V_69 ) < V_69 ) {
F_25 () ;
F_26 ( L_1 , V_68 ) ;
F_27 () ;
V_38 = F_1 ( V_3 ) ;
if ( V_38 != NULL ) {
F_28 ( V_38 -> V_8 ) ;
V_43 = - V_70 ;
}
}
#endif
F_29 ( V_10 ) ;
goto V_64;
}
V_10 -> V_9 = V_38 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_17 = V_30 ? : F_17 ( F_10 ( * V_36 ) ) ;
V_10 -> V_35 = V_35 ;
V_10 -> V_71 = V_38 -> V_71 ;
V_10 -> V_72 = V_31 ;
V_43 = V_38 -> V_73 ( V_10 ) ;
if ( V_43 != 0 ) {
F_28 ( V_38 -> V_8 ) ;
F_29 ( V_10 ) ;
goto V_64;
}
V_44 = 1 ;
} else if ( V_25 [ V_65 ] && F_3 ( V_25 [ V_65 ] , V_10 -> V_9 -> V_3 ) )
goto V_64;
V_42 = V_10 -> V_9 -> V_63 ( V_10 , V_4 -> V_74 ) ;
if ( V_42 == 0 ) {
if ( V_21 -> V_45 == V_75 && V_4 -> V_74 == 0 ) {
F_30 ( V_27 ) ;
* V_36 = V_10 -> V_7 ;
F_31 ( V_27 ) ;
F_32 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_75 ) ;
F_33 ( V_10 ) ;
V_43 = 0 ;
goto V_64;
}
V_43 = - V_14 ;
if ( V_21 -> V_45 != V_52 ||
! ( V_21 -> V_53 & V_54 ) )
goto V_64;
} else {
switch ( V_21 -> V_45 ) {
case V_52 :
V_43 = - V_12 ;
if ( V_21 -> V_53 & V_76 ) {
if ( V_44 )
F_33 ( V_10 ) ;
goto V_64;
}
break;
case V_75 :
V_43 = V_10 -> V_9 -> V_77 ( V_10 , V_42 ) ;
if ( V_43 == 0 )
F_32 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_75 ) ;
goto V_64;
case V_46 :
V_43 = F_32 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_52 ) ;
goto V_64;
default:
V_43 = - V_59 ;
goto V_64;
}
}
V_43 = V_10 -> V_9 -> V_78 ( V_23 , V_19 , V_10 , V_41 , V_4 -> V_74 , V_25 , & V_42 ) ;
if ( V_43 == 0 ) {
if ( V_44 ) {
F_30 ( V_27 ) ;
V_10 -> V_7 = * V_36 ;
* V_36 = V_10 ;
F_31 ( V_27 ) ;
}
F_32 ( V_23 , V_19 , V_21 , V_10 , V_42 , V_52 ) ;
} else {
if ( V_44 )
F_33 ( V_10 ) ;
}
V_64:
if ( V_41 )
V_40 -> V_79 ( V_35 , V_41 ) ;
if ( V_43 == - V_70 )
goto V_49;
return V_43 ;
}
static int F_34 ( struct V_18 * V_19 , struct V_15 * V_10 ,
unsigned long V_42 , T_1 V_80 , T_1 V_81 , T_3 V_82 , int V_83 )
{
struct V_28 * V_84 ;
struct V_20 * V_85 ;
unsigned char * V_86 = F_35 ( V_19 ) ;
V_85 = F_36 ( V_19 , V_80 , V_81 , V_83 , sizeof( * V_84 ) , V_82 ) ;
if ( ! V_85 )
goto V_87;
V_84 = F_15 ( V_85 ) ;
V_84 -> V_88 = V_89 ;
V_84 -> V_90 = 0 ;
V_84 -> V_91 = 0 ;
V_84 -> V_55 = F_37 ( V_10 -> V_35 ) -> V_92 ;
V_84 -> V_51 = V_10 -> V_72 ;
V_84 -> V_50 = F_11 ( V_10 -> V_17 , V_10 -> V_29 ) ;
if ( F_38 ( V_19 , V_65 , V_10 -> V_9 -> V_3 ) )
goto V_93;
V_84 -> V_74 = V_42 ;
if ( V_75 != V_83 ) {
V_84 -> V_74 = 0 ;
if ( V_10 -> V_9 -> V_94 && V_10 -> V_9 -> V_94 ( V_10 , V_42 , V_19 , V_84 ) < 0 )
goto V_93;
}
V_85 -> V_95 = F_35 ( V_19 ) - V_86 ;
return V_19 -> V_96 ;
V_87:
V_93:
F_39 ( V_19 , V_86 ) ;
return - 1 ;
}
static int F_32 ( struct V_23 * V_23 , struct V_18 * V_97 ,
struct V_20 * V_21 , struct V_15 * V_10 ,
unsigned long V_42 , int V_83 )
{
struct V_18 * V_19 ;
T_1 V_80 = V_97 ? F_40 ( V_97 ) . V_80 : 0 ;
V_19 = F_41 ( V_98 , V_67 ) ;
if ( ! V_19 )
return - V_66 ;
if ( F_34 ( V_19 , V_10 , V_42 , V_80 , V_21 -> V_99 , 0 , V_83 ) <= 0 ) {
F_42 ( V_19 ) ;
return - V_59 ;
}
return F_43 ( V_19 , V_23 , V_80 , V_100 ,
V_21 -> V_53 & V_101 ) ;
}
static int F_44 ( struct V_15 * V_10 , unsigned long V_21 ,
struct V_102 * V_22 )
{
struct V_103 * V_104 = ( void * ) V_22 ;
return F_34 ( V_104 -> V_19 , V_10 , V_21 , F_40 ( V_104 -> V_105 -> V_19 ) . V_80 ,
V_104 -> V_105 -> V_85 -> V_99 , V_106 , V_52 ) ;
}
static int F_45 ( struct V_18 * V_19 , struct V_107 * V_105 )
{
struct V_23 * V_23 = F_13 ( V_19 -> V_24 ) ;
int V_4 ;
int V_108 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_15 * V_10 , * * V_37 ;
struct V_28 * V_84 = F_15 ( V_105 -> V_85 ) ;
unsigned long V_41 = 0 ;
const struct V_39 * V_40 ;
struct V_103 V_22 ;
if ( V_105 -> V_85 -> V_95 < F_46 ( sizeof( * V_84 ) ) )
return V_19 -> V_96 ;
V_33 = F_18 ( V_23 , V_84 -> V_55 ) ;
if ( ! V_33 )
return V_19 -> V_96 ;
if ( ! V_84 -> V_51 )
V_35 = V_33 -> V_57 ;
else
V_35 = F_20 ( V_33 , F_17 ( V_84 -> V_51 ) ) ;
if ( ! V_35 )
goto V_13;
V_40 = V_35 -> V_9 -> V_60 ;
if ( ! V_40 )
goto V_64;
if ( V_40 -> V_61 == NULL )
goto V_64;
if ( F_16 ( V_84 -> V_51 ) ) {
V_41 = V_40 -> V_63 ( V_35 , V_84 -> V_51 ) ;
if ( V_41 == 0 )
goto V_64;
}
V_37 = V_40 -> V_61 ( V_35 , V_41 ) ;
if ( V_37 == NULL )
goto V_64;
V_108 = V_105 -> args [ 0 ] ;
for ( V_10 = * V_37 , V_4 = 0 ; V_10 ; V_10 = V_10 -> V_7 , V_4 ++ ) {
if ( V_4 < V_108 )
continue;
if ( F_17 ( V_84 -> V_50 ) &&
F_17 ( V_84 -> V_50 ) != V_10 -> V_17 )
continue;
if ( F_16 ( V_84 -> V_50 ) &&
F_16 ( V_84 -> V_50 ) != V_10 -> V_29 )
continue;
if ( V_4 > V_108 )
memset ( & V_105 -> args [ 1 ] , 0 , sizeof( V_105 -> args ) - sizeof( V_105 -> args [ 0 ] ) ) ;
if ( V_105 -> args [ 1 ] == 0 ) {
if ( F_34 ( V_19 , V_10 , 0 , F_40 ( V_105 -> V_19 ) . V_80 ,
V_105 -> V_85 -> V_99 , V_106 ,
V_52 ) <= 0 )
break;
V_105 -> args [ 1 ] = 1 ;
}
if ( V_10 -> V_9 -> V_109 == NULL )
continue;
V_22 . V_110 . V_111 = F_44 ;
V_22 . V_19 = V_19 ;
V_22 . V_105 = V_105 ;
V_22 . V_110 . V_112 = 0 ;
V_22 . V_110 . V_113 = V_105 -> args [ 1 ] - 1 ;
V_22 . V_110 . V_114 = 0 ;
V_10 -> V_9 -> V_109 ( V_10 , & V_22 . V_110 ) ;
V_105 -> args [ 1 ] = V_22 . V_110 . V_114 + 1 ;
if ( V_22 . V_110 . V_112 )
break;
}
V_105 -> args [ 0 ] = V_4 ;
V_64:
if ( V_41 )
V_40 -> V_79 ( V_35 , V_41 ) ;
V_13:
return V_19 -> V_96 ;
}
void F_47 ( struct V_15 * V_10 , struct V_115 * V_116 )
{
#ifdef F_48
if ( V_116 -> V_117 ) {
F_49 ( V_116 -> V_117 , V_118 ) ;
V_116 -> V_117 = NULL ;
}
#endif
}
int F_50 ( struct V_23 * V_23 , struct V_15 * V_10 , struct V_2 * * V_119 ,
struct V_2 * V_120 , struct V_115 * V_116 ,
const struct V_121 * V_122 )
{
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
#ifdef F_48
{
struct V_123 * V_124 ;
if ( V_122 -> V_125 && V_119 [ V_122 -> V_125 ] ) {
V_124 = F_51 ( V_23 , V_119 [ V_122 -> V_125 ] , V_120 ,
L_2 , V_126 ,
V_127 ) ;
if ( F_52 ( V_124 ) )
return F_53 ( V_124 ) ;
V_124 -> type = V_128 ;
V_116 -> V_117 = V_124 ;
} else if ( V_122 -> V_117 && V_119 [ V_122 -> V_117 ] ) {
V_124 = F_54 ( V_23 , V_119 [ V_122 -> V_117 ] , V_120 ,
NULL , V_126 ,
V_127 ) ;
if ( F_52 ( V_124 ) )
return F_53 ( V_124 ) ;
V_116 -> V_117 = V_124 ;
}
}
#else
if ( ( V_122 -> V_117 && V_119 [ V_122 -> V_117 ] ) ||
( V_122 -> V_125 && V_119 [ V_122 -> V_125 ] ) )
return - V_62 ;
#endif
return 0 ;
}
void F_55 ( struct V_15 * V_10 , struct V_115 * V_129 ,
struct V_115 * V_130 )
{
#ifdef F_48
if ( V_130 -> V_117 ) {
struct V_123 * V_124 ;
F_56 ( V_10 ) ;
V_124 = V_129 -> V_117 ;
V_129 -> V_117 = V_130 -> V_117 ;
F_57 ( V_10 ) ;
if ( V_124 )
F_49 ( V_124 , V_118 ) ;
}
#endif
}
int F_58 ( struct V_18 * V_19 , struct V_115 * V_116 ,
const struct V_121 * V_122 )
{
#ifdef F_48
if ( V_122 -> V_117 && V_116 -> V_117 ) {
struct V_2 * V_131 ;
if ( V_116 -> V_117 -> type != V_128 ) {
V_131 = F_59 ( V_19 , V_122 -> V_117 ) ;
if ( V_131 == NULL )
goto V_93;
if ( F_60 ( V_19 , V_116 -> V_117 , 0 , 0 ) < 0 )
goto V_93;
F_61 ( V_19 , V_131 ) ;
} else if ( V_122 -> V_125 ) {
V_131 = F_59 ( V_19 , V_122 -> V_125 ) ;
if ( V_131 == NULL )
goto V_93;
if ( F_62 ( V_19 , V_116 -> V_117 , 0 , 0 ) < 0 )
goto V_93;
F_61 ( V_19 , V_131 ) ;
}
}
#endif
return 0 ;
V_93: F_63 ((unused))
return - 1 ;
}
int F_64 ( struct V_18 * V_19 , struct V_115 * V_116 ,
const struct V_121 * V_122 )
{
#ifdef F_48
if ( V_116 -> V_117 )
if ( F_65 ( V_19 , V_116 -> V_117 , 1 ) < 0 )
goto V_93;
#endif
return 0 ;
V_93: F_63 ((unused))
return - 1 ;
}
static int T_4 F_66 ( void )
{
F_67 ( V_132 , V_52 , F_12 , NULL , NULL ) ;
F_67 ( V_132 , V_75 , F_12 , NULL , NULL ) ;
F_67 ( V_132 , V_46 , F_12 ,
F_45 , NULL ) ;
return 0 ;
}
