static inline struct V_1 *
F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 ) )
return NULL ;
return V_2 ;
}
static inline void
F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static inline struct V_1 * F_5 ( T_1 V_4 )
{
if ( V_4 < 1 || V_4 - 1 >= V_5 )
return NULL ;
return V_6 [ V_4 - 1 ] ;
}
static inline struct V_7 * F_6 ( T_1 V_8 )
{
F_7 ( & V_9 ) ;
if ( V_8 < 1 || V_8 - 1 >= V_10 )
return NULL ;
return V_11 [ V_8 - 1 ] ;
}
static inline struct V_7 * F_8 ( T_1 V_8 )
{
if ( V_8 < 1 || V_8 - 1 >= V_10 )
return NULL ;
return F_9 ( V_11 [ V_8 - 1 ] ) ;
}
static inline int F_10 ( T_2 V_12 )
{
switch ( V_12 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
return 1 ;
}
return 0 ;
}
static inline int F_11 ( T_2 V_28 )
{
switch ( V_28 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return 1 ;
}
return 0 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_8 , T_3 * V_33 )
{
V_2 = F_1 ( V_2 ) ;
if ( V_2 )
V_2 -> F_12 ( V_2 , V_8 , V_33 ) ;
else
F_13 ( V_34 L_1 ,
V_35 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_8 )
{
F_15 ( L_2 , V_8 ) ;
V_2 -> F_14 ( V_2 , V_8 ) ;
F_3 ( V_2 ) ;
}
static void F_16 ( T_4 V_4 )
{
struct V_7 * V_36 ;
struct V_1 * V_2 ;
T_1 V_8 ;
F_17 ( & V_9 ) ;
if ( V_37 & 1 )
F_13 ( V_38 L_3 , V_4 ) ;
V_2 = F_5 ( V_4 ) ;
if ( V_2 ) {
if ( V_2 -> V_39 == V_40 )
goto V_41;
V_2 -> V_39 = V_40 ;
for ( V_8 = 1 ; V_8 <= V_10 ; V_8 ++ ) {
V_36 = F_6 ( V_8 ) ;
if ( V_36 )
F_12 ( V_2 , V_8 , & V_36 -> V_33 ) ;
}
F_18 ( & V_2 -> V_42 ) ;
} else
F_13 ( V_34 L_4 , V_35 , V_4 ) ;
V_41:
F_19 ( & V_9 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_43 )
{
struct V_7 * V_36 ;
T_1 V_8 ;
if ( V_2 -> V_39 == V_44 || V_2 -> V_39 == V_45 )
return;
V_2 -> V_39 = V_43 ;
memset ( V_2 -> V_46 , 0 , sizeof( V_2 -> V_46 ) ) ;
memset ( & V_2 -> V_47 , 0 , sizeof( V_2 -> V_47 ) ) ;
memset ( & V_2 -> V_48 , 0 , sizeof( V_2 -> V_48 ) ) ;
memset ( V_2 -> V_49 , 0 , sizeof( V_2 -> V_49 ) ) ;
for ( V_8 = 1 ; V_8 <= V_10 ; V_8 ++ ) {
V_36 = F_6 ( V_8 ) ;
if ( V_36 )
F_3 ( V_2 ) ;
}
F_18 ( & V_2 -> V_42 ) ;
}
static void F_21 ( T_4 V_4 )
{
struct V_1 * V_2 ;
F_17 ( & V_9 ) ;
if ( V_37 & 1 )
F_13 ( V_38 L_5 , V_4 ) ;
V_2 = F_5 ( V_4 ) ;
if ( V_2 )
F_20 ( V_2 , V_44 ) ;
else
F_13 ( V_34 L_4 , V_35 , V_4 ) ;
F_19 ( & V_9 ) ;
}
static int
F_22 ( struct V_50 * V_51 , unsigned long V_52 , void * V_53 )
{
T_4 V_4 = ( long ) V_53 ;
switch ( V_52 ) {
case V_54 :
F_16 ( V_4 ) ;
break;
case V_55 :
F_21 ( V_4 ) ;
break;
}
return V_56 ;
}
static void F_23 ( struct V_57 * V_58 )
{
struct V_59 * V_60 =
F_24 ( V_58 , struct V_59 , V_58 ) ;
F_25 ( & V_61 , V_60 -> type ,
( void * ) ( long ) V_60 -> V_62 ) ;
F_26 ( V_60 ) ;
}
static int F_27 ( unsigned int V_63 , T_4 V_62 )
{
struct V_59 * V_60 = F_28 ( sizeof( * V_60 ) , V_64 ) ;
if ( ! V_60 )
return - V_65 ;
F_29 ( & V_60 -> V_58 , F_23 ) ;
V_60 -> type = V_63 ;
V_60 -> V_62 = V_62 ;
F_30 ( V_66 , & V_60 -> V_58 ) ;
return 0 ;
}
int F_31 ( struct V_50 * V_51 )
{
return F_32 ( & V_61 , V_51 ) ;
}
int F_33 ( struct V_50 * V_51 )
{
return F_34 ( & V_61 , V_51 ) ;
}
static void F_35 ( struct V_57 * V_58 )
{
struct V_67 * V_68 ;
struct V_7 * V_36 =
F_24 ( V_58 , struct V_7 , V_69 ) ;
if ( ( ! V_36 ) || ( V_36 -> V_70 ) )
return;
F_17 ( & V_36 -> V_71 ) ;
while ( ( V_68 = F_36 ( & V_36 -> V_72 ) ) ) {
if ( F_37 ( V_68 -> V_73 ) == V_74 )
V_36 -> V_75 ++ ;
else
V_36 -> V_76 ++ ;
V_36 -> V_77 ( V_36 , V_68 ) ;
}
F_19 ( & V_36 -> V_71 ) ;
}
void F_38 ( struct V_1 * V_2 , T_1 V_78 ,
struct V_67 * V_68 )
{
struct V_7 * V_36 ;
int V_79 = 0 ;
T_2 V_12 , V_28 ;
T_5 * V_80 ;
if ( V_2 -> V_39 != V_40 ) {
V_80 = F_39 ( V_68 -> V_73 ) ;
if ( V_80 ) {
F_13 ( V_81 L_6 ,
V_2 -> V_82 , V_80 -> V_83 ) ;
F_40 ( V_80 ) ;
} else
F_13 ( V_81 L_7 ,
V_2 -> V_82 ) ;
goto error;
}
V_12 = F_41 ( V_68 -> V_73 ) ;
V_28 = F_42 ( V_68 -> V_73 ) ;
if ( V_12 == V_19 && V_28 == V_31 ) {
V_2 -> V_75 ++ ;
if ( V_2 -> V_84 > 2 )
V_79 |= 2 ;
} else {
V_2 -> V_76 ++ ;
if ( V_2 -> V_84 )
V_79 |= 2 ;
}
V_79 |= ( V_2 -> V_84 & 1 ) ;
if ( V_79 & 2 ) {
if ( V_79 & 1 ) {
F_13 ( V_38 L_8 ,
V_2 -> V_82 , F_43 ( V_68 -> V_73 ) ,
F_44 ( V_12 , V_28 ) ,
F_45 ( V_68 -> V_73 ) ) ;
} else {
V_80 = F_39 ( V_68 -> V_73 ) ;
if ( V_80 ) {
F_13 ( V_38 L_9 ,
V_2 -> V_82 , V_80 -> V_83 ) ;
F_40 ( V_80 ) ;
} else
F_13 ( V_38 L_10 ,
V_2 -> V_82 , F_43 ( V_68 -> V_73 ) ,
F_44 ( V_12 , V_28 ) ,
F_45 ( V_68 -> V_73 ) ) ;
}
}
F_46 () ;
V_36 = F_8 ( F_43 ( V_68 -> V_73 ) ) ;
if ( ! V_36 ) {
F_47 () ;
V_80 = F_39 ( V_68 -> V_73 ) ;
if ( V_80 ) {
F_13 ( V_85 L_11 ,
F_43 ( V_68 -> V_73 ) , V_80 -> V_83 ) ;
F_40 ( V_80 ) ;
} else
F_13 ( V_85 L_12 ,
F_43 ( V_68 -> V_73 ) ,
F_44 ( V_12 , V_28 ) ) ;
goto error;
}
F_48 ( & V_36 -> V_72 , V_68 ) ;
F_30 ( V_66 , & V_36 -> V_69 ) ;
F_47 () ;
return;
error:
F_49 ( V_68 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_13 ( V_86 L_13 ,
V_2 -> V_82 , V_2 -> V_87 ) ;
F_27 ( V_54 , V_2 -> V_82 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_13 ( V_86 L_14 , V_2 -> V_82 ) ;
F_27 ( V_55 , V_2 -> V_82 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_88 ) {
F_13 ( V_38 L_15 ,
V_2 -> V_82 ) ;
V_2 -> V_88 = 1 ;
}
}
void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_88 ) {
F_13 ( V_38 L_16 ,
V_2 -> V_82 ) ;
V_2 -> V_88 = 0 ;
}
}
int F_54 ( struct V_1 * V_2 )
{
int V_89 ;
F_17 ( & V_9 ) ;
for ( V_89 = 0 ; V_89 < V_5 ; V_89 ++ ) {
if ( ! V_6 [ V_89 ] )
break;
}
if ( V_89 == V_5 ) {
F_19 ( & V_9 ) ;
F_13 ( V_85 L_17 ) ;
return - V_90 ;
}
V_6 [ V_89 ] = V_2 ;
V_2 -> V_76 = 0 ;
V_2 -> V_75 = 0 ;
V_2 -> V_91 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_82 = V_89 + 1 ;
V_2 -> V_39 = V_44 ;
V_2 -> V_88 = 0 ;
V_2 -> V_84 = V_37 ;
F_55 ( & V_2 -> V_42 ) ;
sprintf ( V_2 -> V_93 , L_18 , V_2 -> V_82 ) ;
V_2 -> V_94 = F_56 ( V_2 -> V_93 , 0 , NULL , V_2 -> V_95 , V_2 ) ;
V_96 ++ ;
F_19 ( & V_9 ) ;
F_13 ( V_86 L_19 ,
V_2 -> V_82 , V_2 -> V_87 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_97 = 0 ;
F_17 ( & V_9 ) ;
F_20 ( V_2 , V_45 ) ;
if ( V_6 [ V_2 -> V_82 - 1 ] != V_2 ) {
V_97 = - V_98 ;
goto V_41;
}
V_6 [ V_2 -> V_82 - 1 ] = NULL ;
V_96 -- ;
if ( V_2 -> V_94 )
F_58 ( V_2 -> V_93 , NULL ) ;
F_13 ( V_86 L_20 ,
V_2 -> V_82 , V_2 -> V_87 ) ;
V_41:
F_19 ( & V_9 ) ;
return V_97 ;
}
void F_59 ( struct V_99 * V_100 )
{
F_17 ( & V_101 ) ;
F_60 ( & V_100 -> V_102 , & V_103 ) ;
F_19 ( & V_101 ) ;
}
void F_61 ( struct V_99 * V_100 )
{
F_17 ( & V_101 ) ;
F_62 ( & V_100 -> V_102 ) ;
F_19 ( & V_101 ) ;
}
T_1 F_63 ( void )
{
T_1 V_104 = V_105 ;
int V_89 ;
F_17 ( & V_9 ) ;
for ( V_89 = 0 ; V_89 < V_5 ; V_89 ++ )
if ( V_6 [ V_89 ] &&
V_6 [ V_89 ] -> V_39 == V_40 ) {
V_104 = V_106 ;
break;
}
F_19 ( & V_9 ) ;
return V_104 ;
}
T_1 F_64 ( struct V_7 * V_36 )
{
int V_89 ;
T_1 V_8 ;
F_15 ( L_21 ) ;
if ( V_36 -> V_33 . V_107 < 128 )
return V_108 ;
V_36 -> V_76 = 0 ;
V_36 -> V_75 = 0 ;
V_36 -> V_91 = 0 ;
V_36 -> V_92 = 0 ;
F_65 ( & V_36 -> V_71 ) ;
F_66 ( & V_36 -> V_72 ) ;
F_29 ( & V_36 -> V_69 , F_35 ) ;
V_36 -> V_70 = 0 ;
F_17 ( & V_9 ) ;
for ( V_8 = 1 ; V_8 <= V_10 ; V_8 ++ ) {
if ( V_11 [ V_8 - 1 ] == NULL )
break;
}
if ( V_8 > V_10 ) {
F_19 ( & V_9 ) ;
return V_109 ;
}
V_36 -> V_8 = V_8 ;
V_11 [ V_8 - 1 ] = V_36 ;
for ( V_89 = 0 ; V_89 < V_5 ; V_89 ++ ) {
if ( ! V_6 [ V_89 ] ||
V_6 [ V_89 ] -> V_39 != V_40 )
continue;
F_12 ( V_6 [ V_89 ] , V_8 , & V_36 -> V_33 ) ;
}
F_19 ( & V_9 ) ;
if ( V_37 & 1 ) {
F_13 ( V_38 L_22 , V_8 ) ;
}
return V_106 ;
}
T_1 F_67 ( struct V_7 * V_36 )
{
int V_89 ;
F_15 ( L_2 , V_36 -> V_8 ) ;
F_17 ( & V_9 ) ;
V_36 -> V_70 = 1 ;
V_11 [ V_36 -> V_8 - 1 ] = NULL ;
F_68 () ;
for ( V_89 = 0 ; V_89 < V_5 ; V_89 ++ ) {
if ( ! V_6 [ V_89 ] ||
V_6 [ V_89 ] -> V_39 != V_40 )
continue;
F_14 ( V_6 [ V_89 ] , V_36 -> V_8 ) ;
}
F_19 ( & V_9 ) ;
F_69 ( V_66 ) ;
F_70 ( & V_36 -> V_72 ) ;
if ( V_37 & 1 ) {
F_13 ( V_38 L_23 , V_36 -> V_8 ) ;
}
return V_106 ;
}
T_1 F_71 ( struct V_7 * V_36 , struct V_67 * V_68 )
{
struct V_1 * V_2 ;
int V_79 = 0 ;
T_2 V_12 , V_28 ;
F_15 ( L_2 , V_36 -> V_8 ) ;
if ( V_96 == 0 )
return V_105 ;
if ( ( V_36 -> V_8 == 0 ) || V_36 -> V_70 )
return V_110 ;
if ( V_68 -> V_111 < 12
|| ! F_10 ( F_41 ( V_68 -> V_73 ) )
|| ! F_11 ( F_42 ( V_68 -> V_73 ) ) )
return V_112 ;
V_2 = F_5 ( F_72 ( V_68 -> V_73 ) ) ;
if ( ! V_2 || V_2 -> V_39 != V_40 )
return V_105 ;
if ( V_2 -> V_88 )
return V_113 ;
V_12 = F_41 ( V_68 -> V_73 ) ;
V_28 = F_42 ( V_68 -> V_73 ) ;
if ( V_12 == V_19 && V_28 == V_29 ) {
V_2 -> V_92 ++ ;
V_36 -> V_92 ++ ;
if ( V_2 -> V_84 > 2 )
V_79 |= 2 ;
} else {
V_2 -> V_91 ++ ;
V_36 -> V_91 ++ ;
if ( V_2 -> V_84 )
V_79 |= 2 ;
}
V_79 |= ( V_2 -> V_84 & 1 ) ;
if ( V_79 & 2 ) {
if ( V_79 & 1 ) {
F_13 ( V_38 L_24 ,
F_72 ( V_68 -> V_73 ) ,
F_43 ( V_68 -> V_73 ) ,
F_44 ( V_12 , V_28 ) ,
F_45 ( V_68 -> V_73 ) ) ;
} else {
T_5 * V_80 = F_39 ( V_68 -> V_73 ) ;
if ( V_80 ) {
F_13 ( V_38 L_25 ,
F_72 ( V_68 -> V_73 ) ,
V_80 -> V_83 ) ;
F_40 ( V_80 ) ;
} else
F_13 ( V_38 L_26 ,
F_72 ( V_68 -> V_73 ) ,
F_43 ( V_68 -> V_73 ) ,
F_44 ( V_12 , V_28 ) ,
F_45 ( V_68 -> V_73 ) ) ;
}
}
return V_2 -> V_114 ( V_2 , V_68 ) ;
}
T_1 F_73 ( T_4 V_4 , T_2 * V_83 )
{
struct V_1 * V_2 ;
T_1 V_104 ;
if ( V_4 == 0 ) {
F_74 ( V_83 , V_115 , V_116 ) ;
return V_106 ;
}
F_17 ( & V_9 ) ;
V_2 = F_5 ( V_4 ) ;
if ( V_2 && V_2 -> V_39 == V_40 ) {
F_74 ( V_83 , V_2 -> V_46 , V_116 ) ;
V_104 = V_106 ;
} else
V_104 = V_105 ;
F_19 ( & V_9 ) ;
return V_104 ;
}
T_1 F_75 ( T_4 V_4 , struct V_117 * V_118 )
{
struct V_1 * V_2 ;
T_1 V_104 ;
if ( V_4 == 0 ) {
* V_118 = V_119 ;
return V_106 ;
}
F_17 ( & V_9 ) ;
V_2 = F_5 ( V_4 ) ;
if ( V_2 && V_2 -> V_39 == V_40 ) {
memcpy ( V_118 , & V_2 -> V_47 , sizeof( V_117 ) ) ;
V_104 = V_106 ;
} else
V_104 = V_105 ;
F_19 ( & V_9 ) ;
return V_104 ;
}
T_1 F_76 ( T_4 V_4 , T_2 * V_49 )
{
struct V_1 * V_2 ;
T_1 V_104 ;
if ( V_4 == 0 ) {
F_74 ( V_49 , V_120 , V_121 ) ;
return V_106 ;
}
F_17 ( & V_9 ) ;
V_2 = F_5 ( V_4 ) ;
if ( V_2 && V_2 -> V_39 == V_40 ) {
F_74 ( V_49 , V_2 -> V_49 , V_121 ) ;
V_104 = V_106 ;
} else
V_104 = V_105 ;
F_19 ( & V_9 ) ;
return V_104 ;
}
T_1 F_77 ( T_4 V_4 , struct V_122 * V_123 )
{
struct V_1 * V_2 ;
T_1 V_104 ;
if ( V_4 == 0 ) {
V_123 -> V_124 = V_96 ;
return V_106 ;
}
F_17 ( & V_9 ) ;
V_2 = F_5 ( V_4 ) ;
if ( V_2 && V_2 -> V_39 == V_40 ) {
memcpy ( V_123 , & V_2 -> V_48 , sizeof( struct V_122 ) ) ;
V_104 = V_106 ;
} else
V_104 = V_105 ;
F_19 ( & V_9 ) ;
return V_104 ;
}
static int F_78 ( struct V_1 * V_2 , unsigned int V_39 )
{
F_79 ( V_125 ) ;
int V_126 = 0 ;
V_2 = F_1 ( V_2 ) ;
if ( ! V_2 )
return - V_127 ;
for (; ; ) {
F_80 ( & V_2 -> V_42 , & V_125 ,
V_128 ) ;
if ( V_2 -> V_39 == V_39 )
break;
if ( V_2 -> V_39 == V_45 ) {
V_126 = - V_127 ;
break;
}
if ( F_81 ( V_129 ) ) {
V_126 = - V_130 ;
break;
}
F_19 ( & V_9 ) ;
F_82 () ;
F_17 ( & V_9 ) ;
}
F_83 ( & V_2 -> V_42 , & V_125 ) ;
F_3 ( V_2 ) ;
return V_126 ;
}
static int F_84 ( unsigned int V_12 , void T_6 * V_73 )
{
T_7 V_131 ;
T_8 V_132 ;
T_9 V_133 ;
T_10 V_134 ;
struct V_1 * V_2 ;
struct V_99 * V_100 = NULL ;
T_11 V_135 ;
struct V_136 * V_137 ;
int V_126 ;
switch ( V_12 ) {
case V_138 :
case V_139 :
if ( V_12 == V_138 ) {
if ( ( V_126 = F_85 ( & V_132 , V_73 ,
sizeof( V_140 ) ) ) )
return - V_141 ;
V_132 . V_142 = V_143 ;
} else {
if ( ( V_126 = F_85 ( & V_132 , V_73 ,
sizeof( T_8 ) ) ) )
return - V_141 ;
}
V_134 . V_144 = V_132 . V_144 ;
V_134 . V_145 = V_132 . V_145 ;
V_134 . V_146 = V_132 . V_146 ;
F_17 ( & V_101 ) ;
switch ( V_132 . V_142 ) {
case V_143 :
F_86 (l, &capi_drivers) {
V_100 = F_87 ( V_137 , struct V_99 , V_102 ) ;
if ( strcmp ( V_100 -> V_87 , L_27 ) == 0 )
break;
}
break;
case V_147 :
F_86 (l, &capi_drivers) {
V_100 = F_87 ( V_137 , struct V_99 , V_102 ) ;
if ( strcmp ( V_100 -> V_87 , L_28 ) == 0 )
break;
}
break;
default:
V_100 = NULL ;
break;
}
if ( ! V_100 ) {
F_13 ( V_85 L_29 ) ;
V_126 = - V_148 ;
} else if ( ! V_100 -> V_149 ) {
F_13 ( V_85 L_30 ) ;
V_126 = - V_148 ;
} else
V_126 = V_100 -> V_149 ( V_100 , & V_134 ) ;
F_19 ( & V_101 ) ;
return V_126 ;
case V_150 :
case V_151 :
if ( V_12 == V_150 ) {
if ( F_85 ( & V_131 , V_73 ,
sizeof( V_152 ) ) )
return - V_141 ;
V_131 . V_153 . V_111 = 0 ;
V_131 . V_153 . V_73 = NULL ;
} else {
if ( F_85 ( & V_131 , V_73 ,
sizeof( T_7 ) ) )
return - V_141 ;
}
F_17 ( & V_9 ) ;
V_2 = F_5 ( V_131 . V_4 ) ;
if ( ! V_2 ) {
V_126 = - V_98 ;
goto V_154;
}
if ( V_2 -> V_155 == NULL ) {
F_13 ( V_38 L_31 ) ;
V_126 = - V_127 ;
goto V_154;
}
if ( V_131 . V_156 . V_111 <= 0 ) {
F_13 ( V_38 L_32 , V_131 . V_156 . V_111 ) ;
V_126 = - V_98 ;
goto V_154;
}
if ( V_131 . V_156 . V_73 == NULL ) {
F_13 ( V_38 L_33 ) ;
V_126 = - V_98 ;
goto V_154;
}
V_135 . V_157 . V_158 = 1 ;
V_135 . V_157 . V_73 = V_131 . V_156 . V_73 ;
V_135 . V_157 . V_111 = V_131 . V_156 . V_111 ;
V_135 . V_159 . V_158 = 1 ;
V_135 . V_159 . V_73 = V_131 . V_153 . V_73 ;
V_135 . V_159 . V_111 = V_131 . V_153 . V_111 ;
if ( V_2 -> V_39 != V_44 ) {
F_13 ( V_81 L_34 , V_131 . V_4 ) ;
V_126 = - V_90 ;
goto V_154;
}
V_2 -> V_39 = V_160 ;
V_126 = V_2 -> V_155 ( V_2 , & V_135 ) ;
if ( V_126 ) {
V_2 -> V_39 = V_44 ;
goto V_154;
}
V_126 = F_78 ( V_2 , V_40 ) ;
V_154:
F_19 ( & V_9 ) ;
return V_126 ;
case V_161 :
if ( F_85 ( & V_133 , V_73 , sizeof( T_9 ) ) )
return - V_141 ;
V_126 = 0 ;
F_17 ( & V_9 ) ;
V_2 = F_5 ( V_133 . V_4 ) ;
if ( ! V_2 ) {
V_126 = - V_127 ;
goto V_162;
}
if ( V_2 -> V_39 == V_44 )
goto V_162;
if ( V_2 -> V_163 == NULL ) {
F_13 ( V_38 L_35 ) ;
V_126 = - V_127 ;
goto V_162;
}
V_2 -> V_163 ( V_2 ) ;
V_126 = F_78 ( V_2 , V_44 ) ;
V_162:
F_19 ( & V_9 ) ;
return V_126 ;
}
return - V_98 ;
}
int F_88 ( unsigned long V_12 , void T_6 * V_73 )
{
struct V_1 * V_2 ;
int V_126 ;
switch ( V_12 ) {
#ifdef F_89
case V_150 :
case V_151 :
case V_161 :
case V_164 :
case V_165 :
return F_84 ( V_12 , V_73 ) ;
#endif
case V_166 :
{
T_12 V_167 ;
if ( F_85 ( & V_167 , V_73 , sizeof( T_12 ) ) )
return - V_141 ;
F_17 ( & V_9 ) ;
V_2 = F_5 ( V_167 . V_4 ) ;
if ( V_2 ) {
V_2 -> V_84 = V_167 . V_168 ;
F_13 ( V_81 L_36 ,
V_2 -> V_82 , V_2 -> V_84 ) ;
V_126 = 0 ;
} else
V_126 = - V_127 ;
F_19 ( & V_9 ) ;
return V_126 ;
}
case V_169 :
{
struct V_136 * V_137 ;
struct V_99 * V_100 = NULL ;
T_10 V_134 ;
T_13 V_132 ;
if ( ( V_126 = F_85 ( & V_132 , V_73 , sizeof( V_132 ) ) ) )
return - V_141 ;
V_134 . V_144 = V_132 . V_144 ;
V_134 . V_145 = V_132 . V_145 ;
V_134 . V_170 = V_132 . V_170 ;
V_134 . V_146 = V_132 . V_146 ;
V_134 . V_142 = 0 ;
V_132 . V_100 [ sizeof( V_132 . V_100 ) - 1 ] = 0 ;
F_17 ( & V_101 ) ;
F_86 (l, &capi_drivers) {
V_100 = F_87 ( V_137 , struct V_99 , V_102 ) ;
if ( strcmp ( V_100 -> V_87 , V_132 . V_100 ) == 0 )
break;
}
if ( V_100 == NULL ) {
F_13 ( V_85 L_37 ,
V_132 . V_100 ) ;
V_126 = - V_127 ;
} else if ( ! V_100 -> V_149 ) {
F_13 ( V_85 L_38 , V_132 . V_100 ) ;
V_126 = - V_148 ;
} else
V_126 = V_100 -> V_149 ( V_100 , & V_134 ) ;
F_19 ( & V_101 ) ;
return V_126 ;
}
default:
F_13 ( V_85 L_39 ,
V_12 ) ;
break;
}
return - V_98 ;
}
static int T_14 F_90 ( void )
{
int V_97 ;
V_66 = F_91 ( L_40 , 0 , 0 ) ;
if ( ! V_66 )
return - V_65 ;
F_31 ( & V_171 ) ;
V_97 = F_92 () ;
if ( V_97 ) {
F_33 ( & V_171 ) ;
F_93 ( V_66 ) ;
return V_97 ;
}
F_94 () ;
return 0 ;
}
static void T_15 F_95 ( void )
{
F_96 () ;
F_33 ( & V_171 ) ;
F_97 () ;
F_93 ( V_66 ) ;
}
