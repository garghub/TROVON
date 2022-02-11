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
static int F_12 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_22 * V_22 = F_13 ( V_19 -> V_23 ) ;
struct V_2 * V_24 [ V_25 + 1 ] ;
T_2 * V_26 ;
struct V_27 * V_4 ;
T_1 V_28 ;
T_1 V_17 ;
T_1 V_29 ;
T_1 V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_15 * * V_35 , * * V_36 ;
struct V_15 * V_10 ;
const struct V_1 * V_37 ;
const struct V_38 * V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
int V_42 ;
int V_43 = 0 ;
if ( ( V_21 -> V_44 != V_45 ) && ! F_14 ( V_46 ) )
return - V_47 ;
V_48:
V_42 = F_15 ( V_21 , sizeof( * V_4 ) , V_24 , V_25 , NULL ) ;
if ( V_42 < 0 )
return V_42 ;
V_4 = F_16 ( V_21 ) ;
V_28 = F_17 ( V_4 -> V_49 ) ;
V_17 = F_18 ( V_4 -> V_49 ) ;
V_29 = V_17 ;
V_30 = V_4 -> V_50 ;
V_40 = 0 ;
if ( V_17 == 0 ) {
if ( V_21 -> V_44 != V_51 ||
! ( V_21 -> V_52 & V_53 ) )
return - V_14 ;
V_17 = F_11 ( 0x80000000U , 0U ) ;
}
V_32 = F_19 ( V_22 , V_4 -> V_54 ) ;
if ( V_32 == NULL )
return - V_55 ;
if ( ! V_30 ) {
V_34 = V_32 -> V_56 ;
V_30 = V_34 -> V_57 ;
} else {
V_34 = F_20 ( V_32 , F_18 ( V_4 -> V_50 ) ) ;
if ( V_34 == NULL )
return - V_58 ;
}
V_39 = V_34 -> V_9 -> V_59 ;
if ( ! V_39 )
return - V_58 ;
if ( V_39 -> V_60 == NULL )
return - V_61 ;
if ( F_17 ( V_30 ) ) {
V_40 = V_39 -> V_62 ( V_34 , V_30 ) ;
if ( V_40 == 0 )
return - V_14 ;
}
V_36 = V_39 -> V_60 ( V_34 , V_40 ) ;
V_42 = - V_58 ;
if ( V_36 == NULL )
goto V_63;
for ( V_35 = V_36 ; ( V_10 = * V_35 ) != NULL ; V_35 = & V_10 -> V_7 ) {
if ( V_10 -> V_17 >= V_17 ) {
if ( V_10 -> V_17 == V_17 ) {
if ( ! V_29 ||
( V_10 -> V_28 != V_28 && V_28 ) )
goto V_63;
} else
V_10 = NULL ;
break;
}
}
V_26 = F_21 ( V_34 ) ;
if ( V_10 == NULL ) {
if ( V_24 [ V_64 ] == NULL || ! V_28 )
goto V_63;
V_42 = - V_14 ;
if ( V_21 -> V_44 != V_51 ||
! ( V_21 -> V_52 & V_53 ) )
goto V_63;
V_42 = - V_65 ;
V_10 = F_22 ( sizeof( * V_10 ) , V_66 ) ;
if ( V_10 == NULL )
goto V_63;
V_42 = - V_14 ;
V_37 = F_1 ( V_24 [ V_64 ] ) ;
if ( V_37 == NULL ) {
#ifdef F_23
struct V_2 * V_3 = V_24 [ V_64 ] ;
char V_67 [ V_68 ] ;
if ( V_3 != NULL &&
F_24 ( V_67 , V_3 , V_68 ) < V_68 ) {
F_25 () ;
F_26 ( L_1 , V_67 ) ;
F_27 () ;
V_37 = F_1 ( V_3 ) ;
if ( V_37 != NULL ) {
F_28 ( V_37 -> V_8 ) ;
V_42 = - V_69 ;
}
}
#endif
F_29 ( V_10 ) ;
goto V_63;
}
V_10 -> V_9 = V_37 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_17 = V_29 ? : F_18 ( F_10 ( * V_35 ) ) ;
V_10 -> V_34 = V_34 ;
V_10 -> V_70 = V_37 -> V_70 ;
V_10 -> V_71 = V_30 ;
V_42 = V_37 -> V_72 ( V_10 ) ;
if ( V_42 != 0 ) {
F_28 ( V_37 -> V_8 ) ;
F_29 ( V_10 ) ;
goto V_63;
}
V_43 = 1 ;
} else if ( V_24 [ V_64 ] && F_3 ( V_24 [ V_64 ] , V_10 -> V_9 -> V_3 ) )
goto V_63;
V_41 = V_10 -> V_9 -> V_62 ( V_10 , V_4 -> V_73 ) ;
if ( V_41 == 0 ) {
if ( V_21 -> V_44 == V_74 && V_4 -> V_73 == 0 ) {
F_30 ( V_26 ) ;
* V_35 = V_10 -> V_7 ;
F_31 ( V_26 ) ;
F_32 ( V_22 , V_19 , V_21 , V_10 , V_41 , V_74 ) ;
F_33 ( V_10 ) ;
V_42 = 0 ;
goto V_63;
}
V_42 = - V_14 ;
if ( V_21 -> V_44 != V_51 ||
! ( V_21 -> V_52 & V_53 ) )
goto V_63;
} else {
switch ( V_21 -> V_44 ) {
case V_51 :
V_42 = - V_12 ;
if ( V_21 -> V_52 & V_75 ) {
if ( V_43 )
F_33 ( V_10 ) ;
goto V_63;
}
break;
case V_74 :
V_42 = V_10 -> V_9 -> V_76 ( V_10 , V_41 ) ;
if ( V_42 == 0 )
F_32 ( V_22 , V_19 , V_21 , V_10 , V_41 , V_74 ) ;
goto V_63;
case V_45 :
V_42 = F_32 ( V_22 , V_19 , V_21 , V_10 , V_41 , V_51 ) ;
goto V_63;
default:
V_42 = - V_58 ;
goto V_63;
}
}
V_42 = V_10 -> V_9 -> V_77 ( V_22 , V_19 , V_10 , V_40 , V_4 -> V_73 , V_24 , & V_41 ) ;
if ( V_42 == 0 ) {
if ( V_43 ) {
F_30 ( V_26 ) ;
V_10 -> V_7 = * V_35 ;
* V_35 = V_10 ;
F_31 ( V_26 ) ;
}
F_32 ( V_22 , V_19 , V_21 , V_10 , V_41 , V_51 ) ;
} else {
if ( V_43 )
F_33 ( V_10 ) ;
}
V_63:
if ( V_40 )
V_39 -> V_78 ( V_34 , V_40 ) ;
if ( V_42 == - V_69 )
goto V_48;
return V_42 ;
}
static int F_34 ( struct V_18 * V_19 , struct V_15 * V_10 ,
unsigned long V_41 , T_1 V_79 , T_1 V_80 , T_3 V_81 , int V_82 )
{
struct V_27 * V_83 ;
struct V_20 * V_84 ;
unsigned char * V_85 = F_35 ( V_19 ) ;
V_84 = F_36 ( V_19 , V_79 , V_80 , V_82 , sizeof( * V_83 ) , V_81 ) ;
if ( ! V_84 )
goto V_86;
V_83 = F_16 ( V_84 ) ;
V_83 -> V_87 = V_88 ;
V_83 -> V_89 = 0 ;
V_83 -> V_90 = 0 ;
V_83 -> V_54 = F_37 ( V_10 -> V_34 ) -> V_91 ;
V_83 -> V_50 = V_10 -> V_71 ;
V_83 -> V_49 = F_11 ( V_10 -> V_17 , V_10 -> V_28 ) ;
if ( F_38 ( V_19 , V_64 , V_10 -> V_9 -> V_3 ) )
goto V_92;
V_83 -> V_73 = V_41 ;
if ( V_74 != V_82 ) {
V_83 -> V_73 = 0 ;
if ( V_10 -> V_9 -> V_93 && V_10 -> V_9 -> V_93 ( V_10 , V_41 , V_19 , V_83 ) < 0 )
goto V_92;
}
V_84 -> V_94 = F_35 ( V_19 ) - V_85 ;
return V_19 -> V_95 ;
V_86:
V_92:
F_39 ( V_19 , V_85 ) ;
return - 1 ;
}
static int F_32 ( struct V_22 * V_22 , struct V_18 * V_96 ,
struct V_20 * V_21 , struct V_15 * V_10 ,
unsigned long V_41 , int V_82 )
{
struct V_18 * V_19 ;
T_1 V_79 = V_96 ? F_40 ( V_96 ) . V_79 : 0 ;
V_19 = F_41 ( V_97 , V_66 ) ;
if ( ! V_19 )
return - V_65 ;
if ( F_34 ( V_19 , V_10 , V_41 , V_79 , V_21 -> V_98 , 0 , V_82 ) <= 0 ) {
F_42 ( V_19 ) ;
return - V_58 ;
}
return F_43 ( V_19 , V_22 , V_79 , V_99 ,
V_21 -> V_52 & V_100 ) ;
}
static int F_44 ( struct V_15 * V_10 , unsigned long V_21 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = ( void * ) V_102 ;
return F_34 ( V_104 -> V_19 , V_10 , V_21 , F_40 ( V_104 -> V_105 -> V_19 ) . V_79 ,
V_104 -> V_105 -> V_84 -> V_98 , V_106 , V_51 ) ;
}
static int F_45 ( struct V_18 * V_19 , struct V_107 * V_105 )
{
struct V_22 * V_22 = F_13 ( V_19 -> V_23 ) ;
int V_4 ;
int V_108 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_15 * V_10 , * * V_36 ;
struct V_27 * V_83 = F_16 ( V_105 -> V_84 ) ;
unsigned long V_40 = 0 ;
const struct V_38 * V_39 ;
struct V_103 V_102 ;
if ( V_94 ( V_105 -> V_84 ) < sizeof( * V_83 ) )
return V_19 -> V_95 ;
V_32 = F_19 ( V_22 , V_83 -> V_54 ) ;
if ( ! V_32 )
return V_19 -> V_95 ;
if ( ! V_83 -> V_50 )
V_34 = V_32 -> V_56 ;
else
V_34 = F_20 ( V_32 , F_18 ( V_83 -> V_50 ) ) ;
if ( ! V_34 )
goto V_13;
V_39 = V_34 -> V_9 -> V_59 ;
if ( ! V_39 )
goto V_63;
if ( V_39 -> V_60 == NULL )
goto V_63;
if ( F_17 ( V_83 -> V_50 ) ) {
V_40 = V_39 -> V_62 ( V_34 , V_83 -> V_50 ) ;
if ( V_40 == 0 )
goto V_63;
}
V_36 = V_39 -> V_60 ( V_34 , V_40 ) ;
if ( V_36 == NULL )
goto V_63;
V_108 = V_105 -> args [ 0 ] ;
for ( V_10 = * V_36 , V_4 = 0 ; V_10 ; V_10 = V_10 -> V_7 , V_4 ++ ) {
if ( V_4 < V_108 )
continue;
if ( F_18 ( V_83 -> V_49 ) &&
F_18 ( V_83 -> V_49 ) != V_10 -> V_17 )
continue;
if ( F_17 ( V_83 -> V_49 ) &&
F_17 ( V_83 -> V_49 ) != V_10 -> V_28 )
continue;
if ( V_4 > V_108 )
memset ( & V_105 -> args [ 1 ] , 0 , sizeof( V_105 -> args ) - sizeof( V_105 -> args [ 0 ] ) ) ;
if ( V_105 -> args [ 1 ] == 0 ) {
if ( F_34 ( V_19 , V_10 , 0 , F_40 ( V_105 -> V_19 ) . V_79 ,
V_105 -> V_84 -> V_98 , V_106 ,
V_51 ) <= 0 )
break;
V_105 -> args [ 1 ] = 1 ;
}
if ( V_10 -> V_9 -> V_109 == NULL )
continue;
V_102 . V_110 . V_111 = F_44 ;
V_102 . V_19 = V_19 ;
V_102 . V_105 = V_105 ;
V_102 . V_110 . V_112 = 0 ;
V_102 . V_110 . V_113 = V_105 -> args [ 1 ] - 1 ;
V_102 . V_110 . V_114 = 0 ;
V_10 -> V_9 -> V_109 ( V_10 , & V_102 . V_110 ) ;
V_105 -> args [ 1 ] = V_102 . V_110 . V_114 + 1 ;
if ( V_102 . V_110 . V_112 )
break;
}
V_105 -> args [ 0 ] = V_4 ;
V_63:
if ( V_40 )
V_39 -> V_78 ( V_34 , V_40 ) ;
V_13:
return V_19 -> V_95 ;
}
void F_46 ( struct V_15 * V_10 , struct V_115 * V_116 )
{
#ifdef F_47
if ( V_116 -> V_117 ) {
F_48 ( V_116 -> V_117 , V_118 ) ;
V_116 -> V_117 = NULL ;
}
#endif
}
int F_49 ( struct V_22 * V_22 , struct V_15 * V_10 , struct V_2 * * V_119 ,
struct V_2 * V_120 , struct V_115 * V_116 ,
const struct V_121 * V_122 )
{
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
#ifdef F_47
{
struct V_123 * V_124 ;
if ( V_122 -> V_125 && V_119 [ V_122 -> V_125 ] ) {
V_124 = F_50 ( V_22 , V_119 [ V_122 -> V_125 ] , V_120 ,
L_2 , V_126 ,
V_127 ) ;
if ( F_51 ( V_124 ) )
return F_52 ( V_124 ) ;
V_124 -> type = V_128 ;
V_116 -> V_117 = V_124 ;
} else if ( V_122 -> V_117 && V_119 [ V_122 -> V_117 ] ) {
V_124 = F_53 ( V_22 , V_119 [ V_122 -> V_117 ] , V_120 ,
NULL , V_126 ,
V_127 ) ;
if ( F_51 ( V_124 ) )
return F_52 ( V_124 ) ;
V_116 -> V_117 = V_124 ;
}
}
#else
if ( ( V_122 -> V_117 && V_119 [ V_122 -> V_117 ] ) ||
( V_122 -> V_125 && V_119 [ V_122 -> V_125 ] ) )
return - V_61 ;
#endif
return 0 ;
}
void F_54 ( struct V_15 * V_10 , struct V_115 * V_129 ,
struct V_115 * V_130 )
{
#ifdef F_47
if ( V_130 -> V_117 ) {
struct V_123 * V_124 ;
F_55 ( V_10 ) ;
V_124 = V_129 -> V_117 ;
V_129 -> V_117 = V_130 -> V_117 ;
F_56 ( V_10 ) ;
if ( V_124 )
F_48 ( V_124 , V_118 ) ;
}
#endif
}
int F_57 ( struct V_18 * V_19 , struct V_115 * V_116 ,
const struct V_121 * V_122 )
{
#ifdef F_47
if ( V_122 -> V_117 && V_116 -> V_117 ) {
struct V_2 * V_131 ;
if ( V_116 -> V_117 -> type != V_128 ) {
V_131 = F_58 ( V_19 , V_122 -> V_117 ) ;
if ( V_131 == NULL )
goto V_92;
if ( F_59 ( V_19 , V_116 -> V_117 , 0 , 0 ) < 0 )
goto V_92;
F_60 ( V_19 , V_131 ) ;
} else if ( V_122 -> V_125 ) {
V_131 = F_58 ( V_19 , V_122 -> V_125 ) ;
if ( V_131 == NULL )
goto V_92;
if ( F_61 ( V_19 , V_116 -> V_117 , 0 , 0 ) < 0 )
goto V_92;
F_60 ( V_19 , V_131 ) ;
}
}
#endif
return 0 ;
V_92: F_62 ((unused))
return - 1 ;
}
int F_63 ( struct V_18 * V_19 , struct V_115 * V_116 ,
const struct V_121 * V_122 )
{
#ifdef F_47
if ( V_116 -> V_117 )
if ( F_64 ( V_19 , V_116 -> V_117 , 1 ) < 0 )
goto V_92;
#endif
return 0 ;
V_92: F_62 ((unused))
return - 1 ;
}
static int T_4 F_65 ( void )
{
F_66 ( V_132 , V_51 , F_12 , NULL , NULL ) ;
F_66 ( V_132 , V_74 , F_12 , NULL , NULL ) ;
F_66 ( V_132 , V_45 , F_12 ,
F_45 , NULL ) ;
return 0 ;
}
