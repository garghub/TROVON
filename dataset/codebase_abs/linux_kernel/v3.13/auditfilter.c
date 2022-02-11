static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_5 -> V_7 )
F_2 ( V_5 -> V_7 ) ;
if ( V_5 -> V_8 )
for ( V_3 = 0 ; V_3 < V_5 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_5 -> V_8 [ V_3 ] ;
F_3 ( V_11 -> V_12 ) ;
F_4 ( V_11 -> V_13 ) ;
}
F_3 ( V_5 -> V_8 ) ;
F_3 ( V_5 -> V_14 ) ;
F_3 ( V_2 ) ;
}
void F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 , struct V_1 , V_17 ) ;
F_1 ( V_2 ) ;
}
static inline struct V_1 * F_7 ( T_1 V_9 )
{
struct V_1 * V_18 ;
struct V_10 * V_8 ;
V_18 = F_8 ( sizeof( * V_18 ) , V_19 ) ;
if ( F_9 ( ! V_18 ) )
return NULL ;
V_8 = F_8 ( sizeof( * V_8 ) * V_9 , V_19 ) ;
if ( F_9 ( ! V_8 ) ) {
F_3 ( V_18 ) ;
return NULL ;
}
V_18 -> V_6 . V_8 = V_8 ;
return V_18 ;
}
char * F_10 ( void * * V_20 , T_2 * V_21 , T_2 V_22 )
{
char * V_23 ;
if ( ! * V_20 || ( V_22 == 0 ) || ( V_22 > * V_21 ) )
return F_11 ( - V_24 ) ;
if ( V_22 > V_25 )
return F_11 ( - V_26 ) ;
V_23 = F_12 ( V_22 + 1 , V_19 ) ;
if ( F_9 ( ! V_23 ) )
return F_11 ( - V_27 ) ;
memcpy ( V_23 , * V_20 , V_22 ) ;
V_23 [ V_22 ] = 0 ;
* V_20 += V_22 ;
* V_21 -= V_22 ;
return V_23 ;
}
static inline int F_13 ( struct V_4 * V_28 ,
struct V_10 * V_11 )
{
if ( V_28 -> V_29 != V_30 ||
V_28 -> V_7 || V_28 -> V_31 || V_28 -> V_32 ||
( V_11 -> V_33 != V_34 && V_11 -> V_33 != V_35 ) )
return - V_24 ;
V_28 -> V_31 = V_11 ;
return 0 ;
}
int T_3 F_14 ( int V_36 , unsigned * V_37 )
{
T_4 * V_38 = F_8 ( V_39 * sizeof( T_4 ) , V_19 ) ;
if ( ! V_38 )
return - V_27 ;
while ( * V_37 != ~ 0U ) {
unsigned V_40 = * V_37 ++ ;
if ( V_40 >= V_39 * 32 - V_41 ) {
F_3 ( V_38 ) ;
return - V_24 ;
}
V_38 [ F_15 ( V_40 ) ] |= F_16 ( V_40 ) ;
}
if ( V_36 >= V_41 || V_42 [ V_36 ] ) {
F_3 ( V_38 ) ;
return - V_24 ;
}
V_42 [ V_36 ] = V_38 ;
return 0 ;
}
int F_17 ( int V_36 , unsigned V_43 )
{
if ( F_9 ( V_43 >= V_39 * 32 ) )
return 0 ;
if ( F_9 ( V_36 >= V_41 || ! V_42 [ V_36 ] ) )
return 0 ;
return V_42 [ V_36 ] [ F_15 ( V_43 ) ] & F_16 ( V_43 ) ;
}
static inline int F_18 ( int V_36 , T_1 * V_44 )
{
int V_3 ;
if ( V_42 [ V_36 ] ) {
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
if ( V_44 [ V_3 ] & V_42 [ V_36 ] [ V_3 ] )
return 0 ;
}
return 1 ;
}
static int F_19 ( struct V_1 * V_18 )
{
struct V_10 * V_45 = V_18 -> V_6 . V_46 ;
if ( ! V_45 ) {
return ( F_18 ( V_47 ,
V_18 -> V_6 . V_44 ) &&
F_18 ( V_48 ,
V_18 -> V_6 . V_44 ) ) ;
}
switch( F_20 ( V_45 -> V_49 ) ) {
case 0 :
return ( F_18 ( V_47 ,
V_18 -> V_6 . V_44 ) ) ;
case 1 :
return ( F_18 ( V_48 ,
V_18 -> V_6 . V_44 ) ) ;
default:
return 1 ;
}
}
static inline struct V_1 * F_21 ( struct V_50 * V_6 )
{
unsigned V_29 ;
struct V_1 * V_18 ;
int V_3 , V_51 ;
V_51 = - V_24 ;
V_29 = V_6 -> V_52 & ~ V_53 ;
switch( V_29 ) {
default:
goto V_54;
#ifdef F_22
case V_55 :
if ( V_6 -> V_56 == V_57 )
goto V_54;
case V_30 :
case V_58 :
#endif
case V_59 :
case V_60 :
;
}
if ( F_9 ( V_6 -> V_56 == V_61 ) ) {
F_23 ( V_62 L_1 ) ;
goto V_54;
}
if ( V_6 -> V_56 != V_63 && V_6 -> V_56 != V_57 )
goto V_54;
if ( V_6 -> V_9 > V_64 )
goto V_54;
V_51 = - V_27 ;
V_18 = F_7 ( V_6 -> V_9 ) ;
if ( ! V_18 )
goto V_54;
V_18 -> V_6 . V_52 = V_6 -> V_52 & V_53 ;
V_18 -> V_6 . V_29 = V_29 ;
V_18 -> V_6 . V_56 = V_6 -> V_56 ;
V_18 -> V_6 . V_9 = V_6 -> V_9 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_18 -> V_6 . V_44 [ V_3 ] = V_6 -> V_44 [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ ) {
int V_65 = V_39 * 32 - V_3 - 1 ;
T_4 * V_38 = & V_18 -> V_6 . V_44 [ F_15 ( V_65 ) ] ;
T_4 * V_36 ;
if ( ! ( * V_38 & F_16 ( V_65 ) ) )
continue;
* V_38 &= ~ F_16 ( V_65 ) ;
V_36 = V_42 [ V_3 ] ;
if ( V_36 ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_39 ; V_66 ++ )
V_18 -> V_6 . V_44 [ V_66 ] |= V_36 [ V_66 ] ;
}
}
return V_18 ;
V_54:
return F_11 ( V_51 ) ;
}
static T_1 F_24 ( T_1 V_33 )
{
T_1 V_40 ;
for ( V_40 = V_34 ; V_40 < V_67 && V_68 [ V_40 ] != V_33 ; V_40 ++ )
;
return V_40 ;
}
static int F_25 ( struct V_1 * V_18 , struct V_10 * V_11 )
{
switch( V_11 -> type ) {
case V_69 :
if ( V_18 -> V_6 . V_29 != V_60 &&
V_18 -> V_6 . V_29 != V_59 )
return - V_24 ;
break;
} ;
switch( V_11 -> type ) {
default:
return - V_24 ;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_69 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
if ( V_11 -> V_33 == V_89 || V_11 -> V_33 == V_90 )
return - V_24 ;
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
break;
case V_108 :
if ( ( V_11 -> V_49 != 0 ) && ( V_11 -> V_49 != 1 ) )
return - V_24 ;
case V_109 :
if ( V_11 -> V_33 != V_35 && V_11 -> V_33 != V_34 )
return - V_24 ;
break;
case V_110 :
if ( V_11 -> V_49 & ~ 15 )
return - V_24 ;
break;
case V_111 :
if ( V_11 -> V_49 & ~ V_112 )
return - V_24 ;
break;
case V_113 :
if ( V_11 -> V_49 > V_114 )
return - V_24 ;
break;
} ;
return 0 ;
}
static struct V_1 * F_26 ( struct V_115 * V_116 ,
T_2 V_117 )
{
int V_51 = 0 ;
struct V_1 * V_18 ;
void * V_20 ;
T_2 V_21 = V_117 - sizeof( struct V_115 ) ;
int V_3 ;
char * V_23 ;
V_18 = F_21 ( (struct V_50 * ) V_116 ) ;
if ( F_27 ( V_18 ) )
goto V_118;
V_20 = V_116 -> V_119 ;
V_18 -> V_6 . V_120 = 2 ;
for ( V_3 = 0 ; V_3 < V_116 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
V_51 = - V_24 ;
V_11 -> V_33 = F_24 ( V_116 -> V_121 [ V_3 ] ) ;
if ( V_11 -> V_33 == V_67 )
goto V_122;
V_11 -> type = V_116 -> V_8 [ V_3 ] ;
V_11 -> V_49 = V_116 -> V_123 [ V_3 ] ;
V_11 -> V_124 = V_125 ;
V_11 -> V_126 = V_127 ;
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
if ( ( V_11 -> type == V_74 ) && ( V_11 -> V_49 == V_128 ) ) {
V_11 -> type = V_108 ;
V_11 -> V_49 = 0 ;
}
V_51 = F_25 ( V_18 , V_11 ) ;
if ( V_51 )
goto V_122;
V_51 = - V_24 ;
switch ( V_11 -> type ) {
case V_74 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_75 :
V_11 -> V_124 = F_28 ( F_29 () , V_11 -> V_49 ) ;
if ( ! F_30 ( V_11 -> V_124 ) )
goto V_122;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_11 -> V_126 = F_31 ( F_29 () , V_11 -> V_49 ) ;
if ( ! F_32 ( V_11 -> V_126 ) )
goto V_122;
break;
case V_109 :
V_18 -> V_6 . V_46 = V_11 ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_122;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_51 = F_33 ( V_11 -> type , V_11 -> V_33 , V_23 ,
( void * * ) & V_11 -> V_13 ) ;
if ( V_51 == - V_24 ) {
F_23 ( V_130 L_2
L_3 , V_23 ) ;
V_51 = 0 ;
}
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_122;
} else
V_11 -> V_12 = V_23 ;
break;
case V_105 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_122;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_51 = F_34 ( & V_18 -> V_6 , V_23 , V_11 -> V_49 , V_11 -> V_33 ) ;
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_122;
}
break;
case V_106 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_122;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_51 = F_35 ( & V_18 -> V_6 , V_23 , V_11 -> V_33 ) ;
F_3 ( V_23 ) ;
if ( V_51 )
goto V_122;
break;
case V_88 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_122;
break;
case V_107 :
if ( V_18 -> V_6 . V_14 || V_11 -> V_49 > V_131 )
goto V_122;
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_122;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_18 -> V_6 . V_14 = V_23 ;
break;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_118:
return V_18 ;
V_122:
if ( V_18 -> V_6 . V_7 )
F_2 ( V_18 -> V_6 . V_7 ) ;
if ( V_18 -> V_6 . V_32 )
F_36 ( V_18 -> V_6 . V_32 ) ;
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
static inline T_2 F_37 ( void * * V_20 , const char * V_23 )
{
T_2 V_22 = strlen ( V_23 ) ;
memcpy ( * V_20 , V_23 , V_22 ) ;
* V_20 += V_22 ;
return V_22 ;
}
static struct V_115 * F_38 ( struct V_4 * V_28 )
{
struct V_115 * V_116 ;
void * V_20 ;
int V_3 ;
V_116 = F_12 ( sizeof( * V_116 ) + V_28 -> V_129 , V_19 ) ;
if ( F_9 ( ! V_116 ) )
return NULL ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_116 -> V_56 = V_28 -> V_56 ;
V_116 -> V_9 = V_28 -> V_9 ;
V_20 = V_116 -> V_119 ;
for ( V_3 = 0 ; V_3 < V_116 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_28 -> V_8 [ V_3 ] ;
V_116 -> V_8 [ V_3 ] = V_11 -> type ;
V_116 -> V_121 [ V_3 ] = V_68 [ V_11 -> V_33 ] ;
switch( V_11 -> type ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_116 -> V_129 += V_116 -> V_123 [ V_3 ] =
F_37 ( & V_20 , V_11 -> V_12 ) ;
break;
case V_105 :
V_116 -> V_129 += V_116 -> V_123 [ V_3 ] =
F_37 ( & V_20 ,
F_39 ( V_28 -> V_7 ) ) ;
break;
case V_106 :
V_116 -> V_129 += V_116 -> V_123 [ V_3 ] =
F_37 ( & V_20 ,
F_40 ( V_28 -> V_32 ) ) ;
break;
case V_107 :
V_116 -> V_129 += V_116 -> V_123 [ V_3 ] =
F_37 ( & V_20 , V_28 -> V_14 ) ;
break;
default:
V_116 -> V_123 [ V_3 ] = V_11 -> V_49 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_116 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_116 ;
}
static int F_41 ( struct V_4 * V_132 , struct V_4 * V_133 )
{
int V_3 ;
if ( V_132 -> V_52 != V_133 -> V_52 ||
V_132 -> V_29 != V_133 -> V_29 ||
V_132 -> V_56 != V_133 -> V_56 ||
V_132 -> V_9 != V_133 -> V_9 )
return 1 ;
for ( V_3 = 0 ; V_3 < V_132 -> V_9 ; V_3 ++ ) {
if ( V_132 -> V_8 [ V_3 ] . type != V_133 -> V_8 [ V_3 ] . type ||
V_132 -> V_8 [ V_3 ] . V_33 != V_133 -> V_8 [ V_3 ] . V_33 )
return 1 ;
switch( V_132 -> V_8 [ V_3 ] . type ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
if ( strcmp ( V_132 -> V_8 [ V_3 ] . V_12 , V_133 -> V_8 [ V_3 ] . V_12 ) )
return 1 ;
break;
case V_105 :
if ( strcmp ( F_39 ( V_132 -> V_7 ) ,
F_39 ( V_133 -> V_7 ) ) )
return 1 ;
break;
case V_106 :
if ( strcmp ( F_40 ( V_132 -> V_32 ) ,
F_40 ( V_133 -> V_32 ) ) )
return 1 ;
break;
case V_107 :
if ( strcmp ( V_132 -> V_14 , V_133 -> V_14 ) )
return 1 ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
if ( ! F_42 ( V_132 -> V_8 [ V_3 ] . V_124 , V_133 -> V_8 [ V_3 ] . V_124 ) )
return 1 ;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
if ( ! F_43 ( V_132 -> V_8 [ V_3 ] . V_126 , V_133 -> V_8 [ V_3 ] . V_126 ) )
return 1 ;
break;
default:
if ( V_132 -> V_8 [ V_3 ] . V_49 != V_133 -> V_8 [ V_3 ] . V_49 )
return 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
if ( V_132 -> V_44 [ V_3 ] != V_133 -> V_44 [ V_3 ] )
return 1 ;
return 0 ;
}
static inline int F_44 ( struct V_10 * V_134 ,
struct V_10 * V_135 )
{
int V_136 = 0 ;
char * V_12 ;
V_12 = F_45 ( V_135 -> V_12 , V_19 ) ;
if ( F_9 ( ! V_12 ) )
return - V_27 ;
V_134 -> V_12 = V_12 ;
V_136 = F_33 ( V_134 -> type , V_134 -> V_33 , V_134 -> V_12 ,
( void * * ) & V_134 -> V_13 ) ;
if ( V_136 == - V_24 ) {
F_23 ( V_130 L_4
L_5 , V_134 -> V_12 ) ;
V_136 = 0 ;
}
return V_136 ;
}
struct V_1 * F_46 ( struct V_4 * V_137 )
{
T_1 V_138 = V_137 -> V_9 ;
struct V_1 * V_18 ;
struct V_4 * V_139 ;
char * V_140 ;
int V_3 , V_51 = 0 ;
V_18 = F_7 ( V_138 ) ;
if ( F_9 ( ! V_18 ) )
return F_11 ( - V_27 ) ;
V_139 = & V_18 -> V_6 ;
V_139 -> V_120 = V_137 -> V_120 ;
V_139 -> V_52 = V_137 -> V_52 ;
V_139 -> V_29 = V_137 -> V_29 ;
V_139 -> V_56 = V_137 -> V_56 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_139 -> V_44 [ V_3 ] = V_137 -> V_44 [ V_3 ] ;
V_139 -> V_141 = V_137 -> V_141 ;
V_139 -> V_129 = V_137 -> V_129 ;
V_139 -> V_31 = V_137 -> V_31 ;
V_139 -> V_9 = V_137 -> V_9 ;
V_139 -> V_32 = V_137 -> V_32 ;
memcpy ( V_139 -> V_8 , V_137 -> V_8 , sizeof( struct V_10 ) * V_138 ) ;
for ( V_3 = 0 ; V_3 < V_138 ; V_3 ++ ) {
switch ( V_139 -> V_8 [ V_3 ] . type ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_51 = F_44 ( & V_139 -> V_8 [ V_3 ] ,
& V_137 -> V_8 [ V_3 ] ) ;
break;
case V_107 :
V_140 = F_45 ( V_137 -> V_14 , V_19 ) ;
if ( F_9 ( ! V_140 ) )
V_51 = - V_27 ;
else
V_139 -> V_14 = V_140 ;
}
if ( V_51 ) {
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
}
if ( V_137 -> V_7 ) {
F_47 ( V_137 -> V_7 ) ;
V_139 -> V_7 = V_137 -> V_7 ;
}
return V_18 ;
}
static struct V_1 * F_48 ( struct V_1 * V_18 ,
struct V_142 * * V_38 )
{
struct V_1 * V_2 , * V_143 = NULL ;
struct V_142 * V_37 ;
int V_144 ;
if ( V_18 -> V_6 . V_31 ) {
V_144 = F_49 ( V_18 -> V_6 . V_31 -> V_49 ) ;
* V_38 = V_37 = & V_145 [ V_144 ] ;
} else if ( V_18 -> V_6 . V_7 ) {
for ( V_144 = 0 ; V_144 < V_146 ; V_144 ++ ) {
V_37 = & V_145 [ V_144 ] ;
F_50 (e, list, list)
if ( ! F_41 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_143 = V_2 ;
goto V_147;
}
}
goto V_147;
} else {
* V_38 = V_37 = & V_148 [ V_18 -> V_6 . V_29 ] ;
}
F_50 (e, list, list)
if ( ! F_41 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_143 = V_2 ;
goto V_147;
}
V_147:
return V_143 ;
}
static inline int F_51 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_149 * V_7 = V_18 -> V_6 . V_7 ;
struct V_150 * V_32 = V_18 -> V_6 . V_32 ;
struct V_142 * V_37 ;
int V_51 ;
#ifdef F_22
int V_151 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_151 = 1 ;
#endif
F_52 ( & V_152 ) ;
V_2 = F_48 ( V_18 , & V_37 ) ;
if ( V_2 ) {
F_53 ( & V_152 ) ;
V_51 = - V_153 ;
if ( V_32 )
F_36 ( V_32 ) ;
goto error;
}
if ( V_7 ) {
V_51 = F_54 ( & V_18 -> V_6 , & V_37 ) ;
if ( V_51 ) {
F_53 ( & V_152 ) ;
if ( V_32 )
F_36 ( V_32 ) ;
goto error;
}
}
if ( V_32 ) {
V_51 = F_55 ( & V_18 -> V_6 ) ;
if ( V_51 ) {
F_53 ( & V_152 ) ;
goto error;
}
}
V_18 -> V_6 . V_141 = ~ 0ULL ;
if ( V_18 -> V_6 . V_29 == V_30 ) {
if ( V_18 -> V_6 . V_52 & V_53 )
V_18 -> V_6 . V_141 = ++ V_154 ;
else
V_18 -> V_6 . V_141 = -- V_155 ;
}
if ( V_18 -> V_6 . V_52 & V_53 ) {
F_56 ( & V_18 -> V_6 . V_37 ,
& V_156 [ V_18 -> V_6 . V_29 ] ) ;
F_57 ( & V_18 -> V_37 , V_37 ) ;
V_18 -> V_6 . V_52 &= ~ V_53 ;
} else {
F_58 ( & V_18 -> V_6 . V_37 ,
& V_156 [ V_18 -> V_6 . V_29 ] ) ;
F_59 ( & V_18 -> V_37 , V_37 ) ;
}
#ifdef F_22
if ( ! V_151 )
V_157 ++ ;
if ( ! F_19 ( V_18 ) )
V_158 ++ ;
#endif
F_53 ( & V_152 ) ;
return 0 ;
error:
if ( V_7 )
F_2 ( V_7 ) ;
return V_51 ;
}
static inline int F_60 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_149 * V_7 = V_18 -> V_6 . V_7 ;
struct V_150 * V_32 = V_18 -> V_6 . V_32 ;
struct V_142 * V_37 ;
int V_136 = 0 ;
#ifdef F_22
int V_151 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_151 = 1 ;
#endif
F_52 ( & V_152 ) ;
V_2 = F_48 ( V_18 , & V_37 ) ;
if ( ! V_2 ) {
F_53 ( & V_152 ) ;
V_136 = - V_159 ;
goto V_147;
}
if ( V_2 -> V_6 . V_7 )
F_61 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_6 . V_32 )
F_62 ( & V_2 -> V_6 ) ;
F_63 ( & V_2 -> V_37 ) ;
F_64 ( & V_2 -> V_6 . V_37 ) ;
F_65 ( & V_2 -> V_17 , F_5 ) ;
#ifdef F_22
if ( ! V_151 )
V_157 -- ;
if ( ! F_19 ( V_18 ) )
V_158 -- ;
#endif
F_53 ( & V_152 ) ;
V_147:
if ( V_7 )
F_2 ( V_7 ) ;
if ( V_32 )
F_36 ( V_32 ) ;
return V_136 ;
}
static void F_66 ( int V_160 , int V_161 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
struct V_4 * V_166 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_167 ; V_3 ++ ) {
F_50 (r, &audit_rules_list[i], list) {
struct V_115 * V_116 ;
V_116 = F_38 ( V_166 ) ;
if ( F_9 ( ! V_116 ) )
break;
V_165 = F_67 ( V_160 , V_161 , V_168 , 0 , 1 ,
V_116 , sizeof( * V_116 ) + V_116 -> V_129 ) ;
if ( V_165 )
F_68 ( V_163 , V_165 ) ;
F_3 ( V_116 ) ;
}
}
V_165 = F_67 ( V_160 , V_161 , V_168 , 1 , 1 , NULL , 0 ) ;
if ( V_165 )
F_68 ( V_163 , V_165 ) ;
}
static void F_69 ( char * V_56 , struct V_4 * V_6 , int V_169 )
{
struct V_170 * V_171 ;
T_5 V_172 = F_70 ( & V_173 , F_71 ( V_174 ) ) ;
T_1 V_175 = F_72 ( V_174 ) ;
if ( ! V_176 )
return;
V_171 = F_73 ( NULL , V_19 , V_177 ) ;
if ( ! V_171 )
return;
F_74 ( V_171 , L_6 , V_172 , V_175 ) ;
F_75 ( V_171 ) ;
F_74 ( V_171 , L_7 ) ;
F_76 ( V_171 , V_56 ) ;
F_77 ( V_171 , V_6 -> V_14 ) ;
F_74 ( V_171 , L_8 , V_6 -> V_29 , V_169 ) ;
F_78 ( V_171 ) ;
}
int F_79 ( int type , int V_160 , int V_161 , void * V_116 , T_2 V_117 )
{
struct V_178 * V_179 ;
struct V_180 * V_181 ;
int V_51 = 0 ;
struct V_1 * V_18 ;
switch ( type ) {
case V_168 :
V_181 = F_12 ( sizeof( struct V_180 ) , V_19 ) ;
if ( ! V_181 )
return - V_27 ;
V_181 -> V_160 = V_160 ;
F_80 ( & V_181 -> V_163 ) ;
F_52 ( & V_152 ) ;
F_66 ( V_160 , V_161 , & V_181 -> V_163 ) ;
F_53 ( & V_152 ) ;
V_179 = F_81 ( V_182 , V_181 , L_9 ) ;
if ( F_27 ( V_179 ) ) {
F_82 ( & V_181 -> V_163 ) ;
F_3 ( V_181 ) ;
V_51 = F_83 ( V_179 ) ;
}
break;
case V_183 :
V_18 = F_26 ( V_116 , V_117 ) ;
if ( F_27 ( V_18 ) )
return F_83 ( V_18 ) ;
V_51 = F_51 ( V_18 ) ;
F_69 ( L_10 , & V_18 -> V_6 , ! V_51 ) ;
if ( V_51 )
F_1 ( V_18 ) ;
break;
case V_184 :
V_18 = F_26 ( V_116 , V_117 ) ;
if ( F_27 ( V_18 ) )
return F_83 ( V_18 ) ;
V_51 = F_60 ( V_18 ) ;
F_69 ( L_11 , & V_18 -> V_6 , ! V_51 ) ;
F_1 ( V_18 ) ;
break;
default:
return - V_24 ;
}
return V_51 ;
}
int F_84 ( T_1 V_185 , T_1 V_33 , T_1 V_186 )
{
switch ( V_33 ) {
case V_34 :
return ( V_185 == V_186 ) ;
case V_35 :
return ( V_185 != V_186 ) ;
case V_187 :
return ( V_185 < V_186 ) ;
case V_188 :
return ( V_185 <= V_186 ) ;
case V_189 :
return ( V_185 > V_186 ) ;
case V_190 :
return ( V_185 >= V_186 ) ;
case V_89 :
return ( V_185 & V_186 ) ;
case V_90 :
return ( ( V_185 & V_186 ) == V_186 ) ;
default:
F_85 () ;
return 0 ;
}
}
int F_86 ( T_6 V_185 , T_1 V_33 , T_6 V_186 )
{
switch ( V_33 ) {
case V_34 :
return F_42 ( V_185 , V_186 ) ;
case V_35 :
return ! F_42 ( V_185 , V_186 ) ;
case V_187 :
return F_87 ( V_185 , V_186 ) ;
case V_188 :
return F_88 ( V_185 , V_186 ) ;
case V_189 :
return F_89 ( V_185 , V_186 ) ;
case V_190 :
return F_90 ( V_185 , V_186 ) ;
case V_89 :
case V_90 :
default:
F_85 () ;
return 0 ;
}
}
int F_91 ( T_7 V_185 , T_1 V_33 , T_7 V_186 )
{
switch ( V_33 ) {
case V_34 :
return F_43 ( V_185 , V_186 ) ;
case V_35 :
return ! F_43 ( V_185 , V_186 ) ;
case V_187 :
return F_92 ( V_185 , V_186 ) ;
case V_188 :
return F_93 ( V_185 , V_186 ) ;
case V_189 :
return F_94 ( V_185 , V_186 ) ;
case V_190 :
return F_95 ( V_185 , V_186 ) ;
case V_89 :
case V_90 :
default:
F_85 () ;
return 0 ;
}
}
int F_96 ( const char * V_191 )
{
int V_192 ;
const char * V_38 ;
V_192 = strlen ( V_191 ) ;
if ( V_192 == 0 )
return V_192 ;
V_38 = V_191 + V_192 - 1 ;
while ( ( * V_38 == '/' ) && ( V_38 > V_191 ) )
V_38 -- ;
while ( ( * V_38 != '/' ) && ( V_38 > V_191 ) )
V_38 -- ;
if ( * V_38 == '/' )
V_38 ++ ;
return V_38 - V_191 ;
}
int F_97 ( const char * V_193 , const char * V_191 , int V_194 )
{
int V_195 , V_196 ;
const char * V_38 ;
V_195 = strlen ( V_193 ) ;
V_196 = strlen ( V_191 ) ;
if ( V_196 < V_195 )
return 1 ;
V_194 = V_194 == V_197 ? F_96 ( V_191 ) : V_194 ;
if ( V_196 - V_194 != V_195 )
return 1 ;
V_38 = V_191 + V_194 ;
return strncmp ( V_38 , V_193 , V_195 ) ;
}
static int F_98 ( struct V_4 * V_6 , int type ,
enum V_198 * V_199 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_6 -> V_8 [ V_3 ] ;
int V_200 = 0 ;
T_1 V_201 ;
switch ( V_11 -> type ) {
case V_81 :
V_200 = F_84 ( F_99 ( V_174 ) , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_70 :
V_200 = F_86 ( F_100 () , V_11 -> V_33 , V_11 -> V_124 ) ;
break;
case V_76 :
V_200 = F_91 ( F_101 () , V_11 -> V_33 , V_11 -> V_126 ) ;
break;
case V_74 :
V_200 = F_86 ( F_71 ( V_174 ) ,
V_11 -> V_33 , V_11 -> V_124 ) ;
break;
case V_108 :
V_200 = F_84 ( F_102 ( V_174 ) ,
V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_69 :
V_200 = F_84 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
if ( V_11 -> V_13 ) {
F_103 ( V_174 , & V_201 ) ;
V_200 = F_104 ( V_201 ,
V_11 -> type ,
V_11 -> V_33 ,
V_11 -> V_13 ,
NULL ) ;
}
break;
}
if ( ! V_200 )
return 0 ;
}
switch ( V_6 -> V_56 ) {
case V_63 : * V_199 = V_202 ; break;
case V_57 : * V_199 = V_203 ; break;
}
return 1 ;
}
int F_105 ( int type )
{
enum V_198 V_199 = V_202 ;
struct V_1 * V_2 ;
int V_136 = 1 ;
F_106 () ;
F_107 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
if ( F_98 ( & V_2 -> V_6 , type , & V_199 ) ) {
if ( V_199 == V_202 )
V_136 = 0 ;
break;
}
}
F_108 () ;
return V_136 ;
}
int F_109 ( int type )
{
struct V_1 * V_2 ;
int V_200 = 0 ;
F_106 () ;
if ( F_110 ( & V_148 [ V_60 ] ) )
goto V_204;
F_107 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 . V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_2 -> V_6 . V_8 [ V_3 ] ;
if ( V_11 -> type == V_69 ) {
V_200 = F_84 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
if ( ! V_200 )
break;
}
}
if ( V_200 )
goto V_204;
}
V_204:
F_108 () ;
return V_200 ;
}
static int F_111 ( struct V_4 * V_166 )
{
struct V_1 * V_18 = F_6 ( V_166 , struct V_1 , V_6 ) ;
struct V_1 * V_205 ;
int V_51 = 0 ;
if ( ! F_112 ( V_166 ) )
return 0 ;
V_205 = F_46 ( V_166 ) ;
if ( F_27 ( V_205 ) ) {
V_51 = F_83 ( V_205 ) ;
F_113 ( L_12 ) ;
if ( V_166 -> V_7 )
F_64 ( & V_166 -> V_206 ) ;
F_63 ( & V_18 -> V_37 ) ;
F_64 ( & V_166 -> V_37 ) ;
} else {
if ( V_166 -> V_7 || V_166 -> V_32 )
F_114 ( & V_166 -> V_206 , & V_205 -> V_6 . V_206 ) ;
F_115 ( & V_18 -> V_37 , & V_205 -> V_37 ) ;
F_116 ( & V_166 -> V_37 , & V_205 -> V_6 . V_37 ) ;
}
F_65 ( & V_18 -> V_17 , F_5 ) ;
return V_51 ;
}
int F_117 ( void )
{
struct V_4 * V_166 , * V_40 ;
int V_3 , V_51 = 0 ;
F_52 ( & V_152 ) ;
for ( V_3 = 0 ; V_3 < V_167 ; V_3 ++ ) {
F_118 (r, n, &audit_rules_list[i], list) {
int V_169 = F_111 ( V_166 ) ;
if ( ! V_51 )
V_51 = V_169 ;
}
}
F_53 ( & V_152 ) ;
return V_51 ;
}
