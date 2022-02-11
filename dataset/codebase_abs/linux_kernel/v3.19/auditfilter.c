static void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
F_2 ( V_2 -> V_13 ) ;
F_3 ( V_2 -> V_14 ) ;
}
}
static inline void F_4 ( struct V_15 * V_16 )
{
int V_17 ;
struct V_18 * V_19 = & V_16 -> V_20 ;
if ( V_19 -> V_21 )
F_5 ( V_19 -> V_21 ) ;
if ( V_19 -> V_22 )
for ( V_17 = 0 ; V_17 < V_19 -> V_23 ; V_17 ++ )
F_1 ( & V_19 -> V_22 [ V_17 ] ) ;
F_2 ( V_19 -> V_22 ) ;
F_2 ( V_19 -> V_24 ) ;
F_2 ( V_16 ) ;
}
void F_6 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = F_7 ( V_26 , struct V_15 , V_27 ) ;
F_4 ( V_16 ) ;
}
static inline struct V_15 * F_8 ( T_1 V_23 )
{
struct V_15 * V_28 ;
struct V_1 * V_22 ;
V_28 = F_9 ( sizeof( * V_28 ) , V_29 ) ;
if ( F_10 ( ! V_28 ) )
return NULL ;
V_22 = F_11 ( V_23 , sizeof( * V_22 ) , V_29 ) ;
if ( F_10 ( ! V_22 ) ) {
F_2 ( V_28 ) ;
return NULL ;
}
V_28 -> V_20 . V_22 = V_22 ;
return V_28 ;
}
char * F_12 ( void * * V_30 , T_2 * V_31 , T_2 V_32 )
{
char * V_33 ;
if ( ! * V_30 || ( V_32 == 0 ) || ( V_32 > * V_31 ) )
return F_13 ( - V_34 ) ;
if ( V_32 > V_35 )
return F_13 ( - V_36 ) ;
V_33 = F_14 ( V_32 + 1 , V_29 ) ;
if ( F_10 ( ! V_33 ) )
return F_13 ( - V_37 ) ;
memcpy ( V_33 , * V_30 , V_32 ) ;
V_33 [ V_32 ] = 0 ;
* V_30 += V_32 ;
* V_31 -= V_32 ;
return V_33 ;
}
static inline int F_15 ( struct V_18 * V_38 ,
struct V_1 * V_2 )
{
if ( V_38 -> V_39 != V_40 ||
V_38 -> V_41 || V_38 -> V_21 || V_38 -> V_42 ||
( V_2 -> V_43 != V_44 && V_2 -> V_43 != V_45 ) )
return - V_34 ;
V_38 -> V_41 = V_2 ;
return 0 ;
}
int T_3 F_16 ( int V_46 , unsigned * V_47 )
{
T_4 * V_48 = F_11 ( V_49 , sizeof( T_4 ) , V_29 ) ;
if ( ! V_48 )
return - V_37 ;
while ( * V_47 != ~ 0U ) {
unsigned V_50 = * V_47 ++ ;
if ( V_50 >= V_49 * 32 - V_51 ) {
F_2 ( V_48 ) ;
return - V_34 ;
}
V_48 [ F_17 ( V_50 ) ] |= F_18 ( V_50 ) ;
}
if ( V_46 >= V_51 || V_52 [ V_46 ] ) {
F_2 ( V_48 ) ;
return - V_34 ;
}
V_52 [ V_46 ] = V_48 ;
return 0 ;
}
int F_19 ( int V_46 , unsigned V_53 )
{
if ( F_10 ( V_53 >= V_49 * 32 ) )
return 0 ;
if ( F_10 ( V_46 >= V_51 || ! V_52 [ V_46 ] ) )
return 0 ;
return V_52 [ V_46 ] [ F_17 ( V_53 ) ] & F_18 ( V_53 ) ;
}
static inline int F_20 ( int V_46 , T_1 * V_54 )
{
int V_17 ;
if ( V_52 [ V_46 ] ) {
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
if ( V_54 [ V_17 ] & V_52 [ V_46 ] [ V_17 ] )
return 0 ;
}
return 1 ;
}
static int F_21 ( struct V_15 * V_28 )
{
struct V_1 * V_55 = V_28 -> V_20 . V_56 ;
if ( ! V_55 ) {
return ( F_20 ( V_57 ,
V_28 -> V_20 . V_54 ) &&
F_20 ( V_58 ,
V_28 -> V_20 . V_54 ) ) ;
}
switch( F_22 ( V_55 -> V_59 ) ) {
case 0 :
return ( F_20 ( V_57 ,
V_28 -> V_20 . V_54 ) ) ;
case 1 :
return ( F_20 ( V_58 ,
V_28 -> V_20 . V_54 ) ) ;
default:
return 1 ;
}
}
static inline struct V_15 * F_23 ( struct V_60 * V_20 )
{
unsigned V_39 ;
struct V_15 * V_28 ;
int V_17 , V_61 ;
V_61 = - V_34 ;
V_39 = V_20 -> V_62 & ~ V_63 ;
switch( V_39 ) {
default:
goto V_64;
#ifdef F_24
case V_65 :
if ( V_20 -> V_66 == V_67 )
goto V_64;
case V_40 :
case V_68 :
#endif
case V_69 :
case V_70 :
;
}
if ( F_10 ( V_20 -> V_66 == V_71 ) ) {
F_25 ( L_1 ) ;
goto V_64;
}
if ( V_20 -> V_66 != V_72 && V_20 -> V_66 != V_67 )
goto V_64;
if ( V_20 -> V_23 > V_73 )
goto V_64;
V_61 = - V_37 ;
V_28 = F_8 ( V_20 -> V_23 ) ;
if ( ! V_28 )
goto V_64;
V_28 -> V_20 . V_62 = V_20 -> V_62 & V_63 ;
V_28 -> V_20 . V_39 = V_39 ;
V_28 -> V_20 . V_66 = V_20 -> V_66 ;
V_28 -> V_20 . V_23 = V_20 -> V_23 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_28 -> V_20 . V_54 [ V_17 ] = V_20 -> V_54 [ V_17 ] ;
for ( V_17 = 0 ; V_17 < V_51 ; V_17 ++ ) {
int V_74 = V_49 * 32 - V_17 - 1 ;
T_4 * V_48 = & V_28 -> V_20 . V_54 [ F_17 ( V_74 ) ] ;
T_4 * V_46 ;
if ( ! ( * V_48 & F_18 ( V_74 ) ) )
continue;
* V_48 &= ~ F_18 ( V_74 ) ;
V_46 = V_52 [ V_17 ] ;
if ( V_46 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < V_49 ; V_75 ++ )
V_28 -> V_20 . V_54 [ V_75 ] |= V_46 [ V_75 ] ;
}
}
return V_28 ;
V_64:
return F_13 ( V_61 ) ;
}
static T_1 F_26 ( T_1 V_43 )
{
T_1 V_50 ;
for ( V_50 = V_44 ; V_50 < V_76 && V_77 [ V_50 ] != V_43 ; V_50 ++ )
;
return V_50 ;
}
static int F_27 ( struct V_15 * V_28 , struct V_1 * V_2 )
{
switch( V_2 -> type ) {
case V_78 :
if ( V_28 -> V_20 . V_39 != V_70 &&
V_28 -> V_20 . V_39 != V_69 )
return - V_34 ;
break;
} ;
switch( V_2 -> type ) {
default:
return - V_34 ;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_78 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
if ( V_2 -> V_43 == V_98 || V_2 -> V_43 == V_99 )
return - V_34 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_104 :
case V_105 :
case V_106 :
break;
case V_107 :
if ( ( V_2 -> V_59 != 0 ) && ( V_2 -> V_59 != 1 ) )
return - V_34 ;
case V_108 :
if ( V_2 -> V_43 != V_45 && V_2 -> V_43 != V_44 )
return - V_34 ;
break;
case V_109 :
if ( V_2 -> V_59 & ~ 15 )
return - V_34 ;
break;
case V_110 :
if ( V_2 -> V_59 & ~ V_111 )
return - V_34 ;
break;
case V_112 :
if ( V_2 -> V_59 > V_113 )
return - V_34 ;
break;
} ;
return 0 ;
}
static struct V_15 * F_28 ( struct V_60 * V_114 ,
T_2 V_115 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
void * V_30 ;
T_2 V_31 = V_115 - sizeof( struct V_60 ) ;
int V_17 ;
char * V_33 ;
V_28 = F_23 ( V_114 ) ;
if ( F_29 ( V_28 ) )
goto V_116;
V_30 = V_114 -> V_117 ;
V_28 -> V_20 . V_118 = 2 ;
for ( V_17 = 0 ; V_17 < V_114 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_28 -> V_20 . V_22 [ V_17 ] ;
V_61 = - V_34 ;
V_2 -> V_43 = F_26 ( V_114 -> V_119 [ V_17 ] ) ;
if ( V_2 -> V_43 == V_76 )
goto V_120;
V_2 -> type = V_114 -> V_22 [ V_17 ] ;
V_2 -> V_59 = V_114 -> V_121 [ V_17 ] ;
if ( ( V_2 -> type == V_83 ) && ( V_2 -> V_59 == V_122 ) ) {
V_2 -> type = V_107 ;
V_2 -> V_59 = 0 ;
V_28 -> V_20 . V_123 |= V_124 ;
}
V_61 = F_27 ( V_28 , V_2 ) ;
if ( V_61 )
goto V_120;
V_61 = - V_34 ;
switch ( V_2 -> type ) {
case V_83 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_84 :
V_2 -> V_125 = F_30 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_32 ( V_2 -> V_125 ) )
goto V_120;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_2 -> V_126 = F_33 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_34 ( V_2 -> V_126 ) )
goto V_120;
break;
case V_108 :
V_28 -> V_20 . V_56 = V_2 ;
break;
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_120;
V_28 -> V_20 . V_127 += V_2 -> V_59 ;
V_61 = F_35 ( V_2 -> type , V_2 -> V_43 , V_33 ,
( void * * ) & V_2 -> V_14 ) ;
if ( V_61 == - V_34 ) {
F_36 ( L_2 ,
V_33 ) ;
V_61 = 0 ;
}
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_120;
} else
V_2 -> V_13 = V_33 ;
break;
case V_104 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_120;
V_28 -> V_20 . V_127 += V_2 -> V_59 ;
V_61 = F_37 ( & V_28 -> V_20 , V_33 , V_2 -> V_59 , V_2 -> V_43 ) ;
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_120;
}
break;
case V_105 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_120;
V_28 -> V_20 . V_127 += V_2 -> V_59 ;
V_61 = F_38 ( & V_28 -> V_20 , V_33 , V_2 -> V_43 ) ;
F_2 ( V_33 ) ;
if ( V_61 )
goto V_120;
break;
case V_97 :
V_61 = F_15 ( & V_28 -> V_20 , V_2 ) ;
if ( V_61 )
goto V_120;
break;
case V_106 :
if ( V_28 -> V_20 . V_24 || V_2 -> V_59 > V_128 )
goto V_120;
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_120;
V_28 -> V_20 . V_127 += V_2 -> V_59 ;
V_28 -> V_20 . V_24 = V_33 ;
break;
}
}
if ( V_28 -> V_20 . V_41 && V_28 -> V_20 . V_41 -> V_43 == V_45 )
V_28 -> V_20 . V_41 = NULL ;
V_116:
return V_28 ;
V_120:
if ( V_28 -> V_20 . V_21 )
F_5 ( V_28 -> V_20 . V_21 ) ;
if ( V_28 -> V_20 . V_42 )
F_39 ( V_28 -> V_20 . V_42 ) ;
F_4 ( V_28 ) ;
return F_13 ( V_61 ) ;
}
static inline T_2 F_40 ( void * * V_30 , const char * V_33 )
{
T_2 V_32 = strlen ( V_33 ) ;
memcpy ( * V_30 , V_33 , V_32 ) ;
* V_30 += V_32 ;
return V_32 ;
}
static struct V_60 * F_41 ( struct V_18 * V_38 )
{
struct V_60 * V_114 ;
void * V_30 ;
int V_17 ;
V_114 = F_14 ( sizeof( * V_114 ) + V_38 -> V_127 , V_29 ) ;
if ( F_10 ( ! V_114 ) )
return NULL ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
V_114 -> V_62 = V_38 -> V_62 | V_38 -> V_39 ;
V_114 -> V_66 = V_38 -> V_66 ;
V_114 -> V_23 = V_38 -> V_23 ;
V_30 = V_114 -> V_117 ;
for ( V_17 = 0 ; V_17 < V_114 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_38 -> V_22 [ V_17 ] ;
V_114 -> V_22 [ V_17 ] = V_2 -> type ;
V_114 -> V_119 [ V_17 ] = V_77 [ V_2 -> V_43 ] ;
switch( V_2 -> type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_114 -> V_127 += V_114 -> V_121 [ V_17 ] =
F_40 ( & V_30 , V_2 -> V_13 ) ;
break;
case V_104 :
V_114 -> V_127 += V_114 -> V_121 [ V_17 ] =
F_40 ( & V_30 ,
F_42 ( V_38 -> V_21 ) ) ;
break;
case V_105 :
V_114 -> V_127 += V_114 -> V_121 [ V_17 ] =
F_40 ( & V_30 ,
F_43 ( V_38 -> V_42 ) ) ;
break;
case V_106 :
V_114 -> V_127 += V_114 -> V_121 [ V_17 ] =
F_40 ( & V_30 , V_38 -> V_24 ) ;
break;
case V_107 :
if ( V_38 -> V_123 & V_124 && ! V_2 -> V_59 ) {
V_114 -> V_22 [ V_17 ] = V_83 ;
V_114 -> V_121 [ V_17 ] = V_122 ;
break;
}
default:
V_114 -> V_121 [ V_17 ] = V_2 -> V_59 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ ) V_114 -> V_54 [ V_17 ] = V_38 -> V_54 [ V_17 ] ;
return V_114 ;
}
static int F_44 ( struct V_18 * V_129 , struct V_18 * V_130 )
{
int V_17 ;
if ( V_129 -> V_62 != V_130 -> V_62 ||
V_129 -> V_123 != V_130 -> V_123 ||
V_129 -> V_39 != V_130 -> V_39 ||
V_129 -> V_66 != V_130 -> V_66 ||
V_129 -> V_23 != V_130 -> V_23 )
return 1 ;
for ( V_17 = 0 ; V_17 < V_129 -> V_23 ; V_17 ++ ) {
if ( V_129 -> V_22 [ V_17 ] . type != V_130 -> V_22 [ V_17 ] . type ||
V_129 -> V_22 [ V_17 ] . V_43 != V_130 -> V_22 [ V_17 ] . V_43 )
return 1 ;
switch( V_129 -> V_22 [ V_17 ] . type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
if ( strcmp ( V_129 -> V_22 [ V_17 ] . V_13 , V_130 -> V_22 [ V_17 ] . V_13 ) )
return 1 ;
break;
case V_104 :
if ( strcmp ( F_42 ( V_129 -> V_21 ) ,
F_42 ( V_130 -> V_21 ) ) )
return 1 ;
break;
case V_105 :
if ( strcmp ( F_43 ( V_129 -> V_42 ) ,
F_43 ( V_130 -> V_42 ) ) )
return 1 ;
break;
case V_106 :
if ( strcmp ( V_129 -> V_24 , V_130 -> V_24 ) )
return 1 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
if ( ! F_45 ( V_129 -> V_22 [ V_17 ] . V_125 , V_130 -> V_22 [ V_17 ] . V_125 ) )
return 1 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( ! F_46 ( V_129 -> V_22 [ V_17 ] . V_126 , V_130 -> V_22 [ V_17 ] . V_126 ) )
return 1 ;
break;
default:
if ( V_129 -> V_22 [ V_17 ] . V_59 != V_130 -> V_22 [ V_17 ] . V_59 )
return 1 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
if ( V_129 -> V_54 [ V_17 ] != V_130 -> V_54 [ V_17 ] )
return 1 ;
return 0 ;
}
static inline int F_47 ( struct V_1 * V_131 ,
struct V_1 * V_132 )
{
int V_133 = 0 ;
char * V_13 ;
V_13 = F_48 ( V_132 -> V_13 , V_29 ) ;
if ( F_10 ( ! V_13 ) )
return - V_37 ;
V_131 -> V_13 = V_13 ;
V_133 = F_35 ( V_131 -> type , V_131 -> V_43 , V_131 -> V_13 ,
( void * * ) & V_131 -> V_14 ) ;
if ( V_133 == - V_34 ) {
F_36 ( L_2 ,
V_131 -> V_13 ) ;
V_133 = 0 ;
}
return V_133 ;
}
struct V_15 * F_49 ( struct V_18 * V_134 )
{
T_1 V_135 = V_134 -> V_23 ;
struct V_15 * V_28 ;
struct V_18 * V_136 ;
char * V_137 ;
int V_17 , V_61 = 0 ;
V_28 = F_8 ( V_135 ) ;
if ( F_10 ( ! V_28 ) )
return F_13 ( - V_37 ) ;
V_136 = & V_28 -> V_20 ;
V_136 -> V_118 = V_134 -> V_118 ;
V_136 -> V_62 = V_134 -> V_62 ;
V_136 -> V_123 = V_134 -> V_123 ;
V_136 -> V_39 = V_134 -> V_39 ;
V_136 -> V_66 = V_134 -> V_66 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_136 -> V_54 [ V_17 ] = V_134 -> V_54 [ V_17 ] ;
V_136 -> V_138 = V_134 -> V_138 ;
V_136 -> V_127 = V_134 -> V_127 ;
V_136 -> V_41 = V_134 -> V_41 ;
V_136 -> V_23 = V_134 -> V_23 ;
V_136 -> V_42 = V_134 -> V_42 ;
memcpy ( V_136 -> V_22 , V_134 -> V_22 , sizeof( struct V_1 ) * V_135 ) ;
for ( V_17 = 0 ; V_17 < V_135 ; V_17 ++ ) {
switch ( V_136 -> V_22 [ V_17 ] . type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_61 = F_47 ( & V_136 -> V_22 [ V_17 ] ,
& V_134 -> V_22 [ V_17 ] ) ;
break;
case V_106 :
V_137 = F_48 ( V_134 -> V_24 , V_29 ) ;
if ( F_10 ( ! V_137 ) )
V_61 = - V_37 ;
else
V_136 -> V_24 = V_137 ;
}
if ( V_61 ) {
F_4 ( V_28 ) ;
return F_13 ( V_61 ) ;
}
}
if ( V_134 -> V_21 ) {
F_50 ( V_134 -> V_21 ) ;
V_136 -> V_21 = V_134 -> V_21 ;
}
return V_28 ;
}
static struct V_15 * F_51 ( struct V_15 * V_28 ,
struct V_139 * * V_48 )
{
struct V_15 * V_16 , * V_140 = NULL ;
struct V_139 * V_47 ;
int V_141 ;
if ( V_28 -> V_20 . V_41 ) {
V_141 = F_52 ( V_28 -> V_20 . V_41 -> V_59 ) ;
* V_48 = V_47 = & V_142 [ V_141 ] ;
} else if ( V_28 -> V_20 . V_21 ) {
for ( V_141 = 0 ; V_141 < V_143 ; V_141 ++ ) {
V_47 = & V_142 [ V_141 ] ;
F_53 (e, list, list)
if ( ! F_44 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_140 = V_16 ;
goto V_144;
}
}
goto V_144;
} else {
* V_48 = V_47 = & V_145 [ V_28 -> V_20 . V_39 ] ;
}
F_53 (e, list, list)
if ( ! F_44 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_140 = V_16 ;
goto V_144;
}
V_144:
return V_140 ;
}
static inline int F_54 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_146 * V_21 = V_28 -> V_20 . V_21 ;
struct V_147 * V_42 = V_28 -> V_20 . V_42 ;
struct V_139 * V_47 ;
int V_61 ;
#ifdef F_24
int V_148 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_148 = 1 ;
#endif
F_55 ( & V_149 ) ;
V_16 = F_51 ( V_28 , & V_47 ) ;
if ( V_16 ) {
F_56 ( & V_149 ) ;
V_61 = - V_150 ;
if ( V_42 )
F_39 ( V_42 ) ;
goto error;
}
if ( V_21 ) {
V_61 = F_57 ( & V_28 -> V_20 , & V_47 ) ;
if ( V_61 ) {
F_56 ( & V_149 ) ;
if ( V_42 )
F_39 ( V_42 ) ;
goto error;
}
}
if ( V_42 ) {
V_61 = F_58 ( & V_28 -> V_20 ) ;
if ( V_61 ) {
F_56 ( & V_149 ) ;
goto error;
}
}
V_28 -> V_20 . V_138 = ~ 0ULL ;
if ( V_28 -> V_20 . V_39 == V_40 ) {
if ( V_28 -> V_20 . V_62 & V_63 )
V_28 -> V_20 . V_138 = ++ V_151 ;
else
V_28 -> V_20 . V_138 = -- V_152 ;
}
if ( V_28 -> V_20 . V_62 & V_63 ) {
F_59 ( & V_28 -> V_20 . V_47 ,
& V_153 [ V_28 -> V_20 . V_39 ] ) ;
F_60 ( & V_28 -> V_47 , V_47 ) ;
V_28 -> V_20 . V_62 &= ~ V_63 ;
} else {
F_61 ( & V_28 -> V_20 . V_47 ,
& V_153 [ V_28 -> V_20 . V_39 ] ) ;
F_62 ( & V_28 -> V_47 , V_47 ) ;
}
#ifdef F_24
if ( ! V_148 )
V_154 ++ ;
if ( ! F_21 ( V_28 ) )
V_155 ++ ;
#endif
F_56 ( & V_149 ) ;
return 0 ;
error:
if ( V_21 )
F_5 ( V_21 ) ;
return V_61 ;
}
static inline int F_63 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_146 * V_21 = V_28 -> V_20 . V_21 ;
struct V_147 * V_42 = V_28 -> V_20 . V_42 ;
struct V_139 * V_47 ;
int V_133 = 0 ;
#ifdef F_24
int V_148 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_148 = 1 ;
#endif
F_55 ( & V_149 ) ;
V_16 = F_51 ( V_28 , & V_47 ) ;
if ( ! V_16 ) {
F_56 ( & V_149 ) ;
V_133 = - V_156 ;
goto V_144;
}
if ( V_16 -> V_20 . V_21 )
F_64 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_20 . V_42 )
F_65 ( & V_16 -> V_20 ) ;
F_66 ( & V_16 -> V_47 ) ;
F_67 ( & V_16 -> V_20 . V_47 ) ;
F_68 ( & V_16 -> V_27 , F_6 ) ;
#ifdef F_24
if ( ! V_148 )
V_154 -- ;
if ( ! F_21 ( V_28 ) )
V_155 -- ;
#endif
F_56 ( & V_149 ) ;
V_144:
if ( V_21 )
F_5 ( V_21 ) ;
if ( V_42 )
F_39 ( V_42 ) ;
return V_133 ;
}
static void F_69 ( T_4 V_157 , int V_158 , struct V_159 * V_160 )
{
struct V_161 * V_162 ;
struct V_18 * V_163 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_164 ; V_17 ++ ) {
F_53 (r, &audit_rules_list[i], list) {
struct V_60 * V_114 ;
V_114 = F_41 ( V_163 ) ;
if ( F_10 ( ! V_114 ) )
break;
V_162 = F_70 ( V_157 , V_158 , V_165 ,
0 , 1 , V_114 ,
sizeof( * V_114 ) + V_114 -> V_127 ) ;
if ( V_162 )
F_71 ( V_160 , V_162 ) ;
F_2 ( V_114 ) ;
}
}
V_162 = F_70 ( V_157 , V_158 , V_165 , 1 , 1 , NULL , 0 ) ;
if ( V_162 )
F_71 ( V_160 , V_162 ) ;
}
static void F_72 ( char * V_66 , struct V_18 * V_20 , int V_166 )
{
struct V_167 * V_168 ;
T_5 V_169 = F_73 ( & V_170 , F_74 ( V_171 ) ) ;
unsigned int V_172 = F_75 ( V_171 ) ;
if ( ! V_173 )
return;
V_168 = F_76 ( NULL , V_29 , V_174 ) ;
if ( ! V_168 )
return;
F_77 ( V_168 , L_3 , V_169 , V_172 ) ;
F_78 ( V_168 ) ;
F_77 ( V_168 , L_4 ) ;
F_79 ( V_168 , V_66 ) ;
F_80 ( V_168 , V_20 -> V_24 ) ;
F_77 ( V_168 , L_5 , V_20 -> V_39 , V_166 ) ;
F_81 ( V_168 ) ;
}
int F_82 ( int type , T_4 V_157 , int V_158 , void * V_114 ,
T_2 V_115 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
V_28 = F_28 ( V_114 , V_115 ) ;
if ( F_29 ( V_28 ) )
return F_83 ( V_28 ) ;
switch ( type ) {
case V_175 :
V_61 = F_54 ( V_28 ) ;
F_72 ( L_6 , & V_28 -> V_20 , ! V_61 ) ;
break;
case V_176 :
V_61 = F_63 ( V_28 ) ;
F_72 ( L_7 , & V_28 -> V_20 , ! V_61 ) ;
break;
default:
V_61 = - V_34 ;
F_84 ( 1 ) ;
}
if ( V_61 || type == V_176 )
F_4 ( V_28 ) ;
return V_61 ;
}
int F_85 ( struct V_161 * V_177 , int V_158 )
{
T_1 V_157 = F_86 ( V_177 ) . V_157 ;
struct V_178 * V_178 = F_87 ( F_86 ( V_177 ) . V_179 ) ;
struct V_180 * V_181 ;
struct V_182 * V_183 ;
int V_61 = 0 ;
V_183 = F_14 ( sizeof( struct V_182 ) , V_29 ) ;
if ( ! V_183 )
return - V_37 ;
V_183 -> V_178 = F_88 ( V_178 ) ;
V_183 -> V_157 = V_157 ;
F_89 ( & V_183 -> V_160 ) ;
F_55 ( & V_149 ) ;
F_69 ( V_157 , V_158 , & V_183 -> V_160 ) ;
F_56 ( & V_149 ) ;
V_181 = F_90 ( V_184 , V_183 , L_8 ) ;
if ( F_29 ( V_181 ) ) {
F_91 ( & V_183 -> V_160 ) ;
F_2 ( V_183 ) ;
V_61 = F_83 ( V_181 ) ;
}
return V_61 ;
}
int F_92 ( T_1 V_185 , T_1 V_43 , T_1 V_186 )
{
switch ( V_43 ) {
case V_44 :
return ( V_185 == V_186 ) ;
case V_45 :
return ( V_185 != V_186 ) ;
case V_187 :
return ( V_185 < V_186 ) ;
case V_188 :
return ( V_185 <= V_186 ) ;
case V_189 :
return ( V_185 > V_186 ) ;
case V_190 :
return ( V_185 >= V_186 ) ;
case V_98 :
return ( V_185 & V_186 ) ;
case V_99 :
return ( ( V_185 & V_186 ) == V_186 ) ;
default:
F_93 () ;
return 0 ;
}
}
int F_94 ( T_6 V_185 , T_1 V_43 , T_6 V_186 )
{
switch ( V_43 ) {
case V_44 :
return F_45 ( V_185 , V_186 ) ;
case V_45 :
return ! F_45 ( V_185 , V_186 ) ;
case V_187 :
return F_95 ( V_185 , V_186 ) ;
case V_188 :
return F_96 ( V_185 , V_186 ) ;
case V_189 :
return F_97 ( V_185 , V_186 ) ;
case V_190 :
return F_98 ( V_185 , V_186 ) ;
case V_98 :
case V_99 :
default:
F_93 () ;
return 0 ;
}
}
int F_99 ( T_7 V_185 , T_1 V_43 , T_7 V_186 )
{
switch ( V_43 ) {
case V_44 :
return F_46 ( V_185 , V_186 ) ;
case V_45 :
return ! F_46 ( V_185 , V_186 ) ;
case V_187 :
return F_100 ( V_185 , V_186 ) ;
case V_188 :
return F_101 ( V_185 , V_186 ) ;
case V_189 :
return F_102 ( V_185 , V_186 ) ;
case V_190 :
return F_103 ( V_185 , V_186 ) ;
case V_98 :
case V_99 :
default:
F_93 () ;
return 0 ;
}
}
int F_104 ( const char * V_191 )
{
int V_192 ;
const char * V_48 ;
V_192 = strlen ( V_191 ) ;
if ( V_192 == 0 )
return V_192 ;
V_48 = V_191 + V_192 - 1 ;
while ( ( * V_48 == '/' ) && ( V_48 > V_191 ) )
V_48 -- ;
while ( ( * V_48 != '/' ) && ( V_48 > V_191 ) )
V_48 -- ;
if ( * V_48 == '/' )
V_48 ++ ;
return V_48 - V_191 ;
}
int F_105 ( const char * V_193 , const char * V_191 , int V_194 )
{
int V_195 , V_196 ;
const char * V_48 ;
V_195 = strlen ( V_193 ) ;
V_196 = strlen ( V_191 ) ;
if ( V_196 < V_195 )
return 1 ;
V_194 = V_194 == V_197 ? F_104 ( V_191 ) : V_194 ;
if ( V_196 - V_194 != V_195 )
return 1 ;
V_48 = V_191 + V_194 ;
return strncmp ( V_48 , V_193 , V_195 ) ;
}
static int F_106 ( struct V_18 * V_20 , int type ,
enum V_198 * V_199 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_20 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_20 -> V_22 [ V_17 ] ;
T_8 V_200 ;
int V_201 = 0 ;
T_1 V_202 ;
switch ( V_2 -> type ) {
case V_90 :
V_200 = F_107 ( V_171 ) ;
V_201 = F_92 ( V_200 , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_79 :
V_201 = F_94 ( F_108 () , V_2 -> V_43 , V_2 -> V_125 ) ;
break;
case V_85 :
V_201 = F_99 ( F_109 () , V_2 -> V_43 , V_2 -> V_126 ) ;
break;
case V_83 :
V_201 = F_94 ( F_74 ( V_171 ) ,
V_2 -> V_43 , V_2 -> V_125 ) ;
break;
case V_107 :
V_201 = F_92 ( F_110 ( V_171 ) ,
V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_78 :
V_201 = F_92 ( type , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
if ( V_2 -> V_14 ) {
F_111 ( V_171 , & V_202 ) ;
V_201 = F_112 ( V_202 ,
V_2 -> type ,
V_2 -> V_43 ,
V_2 -> V_14 ,
NULL ) ;
}
break;
}
if ( ! V_201 )
return 0 ;
}
switch ( V_20 -> V_66 ) {
case V_72 : * V_199 = V_203 ; break;
case V_67 : * V_199 = V_204 ; break;
}
return 1 ;
}
int F_113 ( int type )
{
enum V_198 V_199 = V_203 ;
struct V_15 * V_16 ;
int V_205 , V_133 ;
V_133 = 1 ;
F_114 () ;
F_115 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
V_205 = F_106 ( & V_16 -> V_20 , type , & V_199 ) ;
if ( V_205 ) {
if ( V_205 > 0 && V_199 == V_203 )
V_133 = 0 ;
break;
}
}
F_116 () ;
return V_133 ;
}
int F_117 ( int type )
{
struct V_15 * V_16 ;
int V_201 = 0 ;
F_114 () ;
if ( F_118 ( & V_145 [ V_70 ] ) )
goto V_206;
F_115 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_20 . V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_16 -> V_20 . V_22 [ V_17 ] ;
if ( V_2 -> type == V_78 ) {
V_201 = F_92 ( type , V_2 -> V_43 , V_2 -> V_59 ) ;
if ( ! V_201 )
break;
}
}
if ( V_201 )
goto V_206;
}
V_206:
F_116 () ;
return V_201 ;
}
static int F_119 ( struct V_18 * V_163 )
{
struct V_15 * V_28 = F_7 ( V_163 , struct V_15 , V_20 ) ;
struct V_15 * V_207 ;
int V_61 = 0 ;
if ( ! F_120 ( V_163 ) )
return 0 ;
V_207 = F_49 ( V_163 ) ;
if ( F_29 ( V_207 ) ) {
V_61 = F_83 ( V_207 ) ;
F_121 ( L_9 ) ;
if ( V_163 -> V_21 )
F_67 ( & V_163 -> V_208 ) ;
F_66 ( & V_28 -> V_47 ) ;
F_67 ( & V_163 -> V_47 ) ;
} else {
if ( V_163 -> V_21 || V_163 -> V_42 )
F_122 ( & V_163 -> V_208 , & V_207 -> V_20 . V_208 ) ;
F_123 ( & V_28 -> V_47 , & V_207 -> V_47 ) ;
F_124 ( & V_163 -> V_47 , & V_207 -> V_20 . V_47 ) ;
}
F_68 ( & V_28 -> V_27 , F_6 ) ;
return V_61 ;
}
int F_125 ( void )
{
struct V_18 * V_163 , * V_50 ;
int V_17 , V_61 = 0 ;
F_55 ( & V_149 ) ;
for ( V_17 = 0 ; V_17 < V_164 ; V_17 ++ ) {
F_126 (r, n, &audit_rules_list[i], list) {
int V_166 = F_119 ( V_163 ) ;
if ( ! V_61 )
V_61 = V_166 ;
}
}
F_56 ( & V_149 ) ;
return V_61 ;
}
