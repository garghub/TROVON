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
V_8 = F_10 ( V_9 , sizeof( * V_8 ) , V_19 ) ;
if ( F_9 ( ! V_8 ) ) {
F_3 ( V_18 ) ;
return NULL ;
}
V_18 -> V_6 . V_8 = V_8 ;
return V_18 ;
}
char * F_11 ( void * * V_20 , T_2 * V_21 , T_2 V_22 )
{
char * V_23 ;
if ( ! * V_20 || ( V_22 == 0 ) || ( V_22 > * V_21 ) )
return F_12 ( - V_24 ) ;
if ( V_22 > V_25 )
return F_12 ( - V_26 ) ;
V_23 = F_13 ( V_22 + 1 , V_19 ) ;
if ( F_9 ( ! V_23 ) )
return F_12 ( - V_27 ) ;
memcpy ( V_23 , * V_20 , V_22 ) ;
V_23 [ V_22 ] = 0 ;
* V_20 += V_22 ;
* V_21 -= V_22 ;
return V_23 ;
}
static inline int F_14 ( struct V_4 * V_28 ,
struct V_10 * V_11 )
{
if ( V_28 -> V_29 != V_30 ||
V_28 -> V_7 || V_28 -> V_31 || V_28 -> V_32 ||
( V_11 -> V_33 != V_34 && V_11 -> V_33 != V_35 ) )
return - V_24 ;
V_28 -> V_31 = V_11 ;
return 0 ;
}
int T_3 F_15 ( int V_36 , unsigned * V_37 )
{
T_4 * V_38 = F_10 ( V_39 , sizeof( T_4 ) , V_19 ) ;
if ( ! V_38 )
return - V_27 ;
while ( * V_37 != ~ 0U ) {
unsigned V_40 = * V_37 ++ ;
if ( V_40 >= V_39 * 32 - V_41 ) {
F_3 ( V_38 ) ;
return - V_24 ;
}
V_38 [ F_16 ( V_40 ) ] |= F_17 ( V_40 ) ;
}
if ( V_36 >= V_41 || V_42 [ V_36 ] ) {
F_3 ( V_38 ) ;
return - V_24 ;
}
V_42 [ V_36 ] = V_38 ;
return 0 ;
}
int F_18 ( int V_36 , unsigned V_43 )
{
if ( F_9 ( V_43 >= V_39 * 32 ) )
return 0 ;
if ( F_9 ( V_36 >= V_41 || ! V_42 [ V_36 ] ) )
return 0 ;
return V_42 [ V_36 ] [ F_16 ( V_43 ) ] & F_17 ( V_43 ) ;
}
static inline int F_19 ( int V_36 , T_1 * V_44 )
{
int V_3 ;
if ( V_42 [ V_36 ] ) {
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
if ( V_44 [ V_3 ] & V_42 [ V_36 ] [ V_3 ] )
return 0 ;
}
return 1 ;
}
static int F_20 ( struct V_1 * V_18 )
{
struct V_10 * V_45 = V_18 -> V_6 . V_46 ;
if ( ! V_45 ) {
return ( F_19 ( V_47 ,
V_18 -> V_6 . V_44 ) &&
F_19 ( V_48 ,
V_18 -> V_6 . V_44 ) ) ;
}
switch( F_21 ( V_45 -> V_49 ) ) {
case 0 :
return ( F_19 ( V_47 ,
V_18 -> V_6 . V_44 ) ) ;
case 1 :
return ( F_19 ( V_48 ,
V_18 -> V_6 . V_44 ) ) ;
default:
return 1 ;
}
}
static inline struct V_1 * F_22 ( struct V_50 * V_6 )
{
unsigned V_29 ;
struct V_1 * V_18 ;
int V_3 , V_51 ;
V_51 = - V_24 ;
V_29 = V_6 -> V_52 & ~ V_53 ;
switch( V_29 ) {
default:
goto V_54;
#ifdef F_23
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
F_24 ( L_1 ) ;
goto V_54;
}
if ( V_6 -> V_56 != V_62 && V_6 -> V_56 != V_57 )
goto V_54;
if ( V_6 -> V_9 > V_63 )
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
int V_64 = V_39 * 32 - V_3 - 1 ;
T_4 * V_38 = & V_18 -> V_6 . V_44 [ F_16 ( V_64 ) ] ;
T_4 * V_36 ;
if ( ! ( * V_38 & F_17 ( V_64 ) ) )
continue;
* V_38 &= ~ F_17 ( V_64 ) ;
V_36 = V_42 [ V_3 ] ;
if ( V_36 ) {
int V_65 ;
for ( V_65 = 0 ; V_65 < V_39 ; V_65 ++ )
V_18 -> V_6 . V_44 [ V_65 ] |= V_36 [ V_65 ] ;
}
}
return V_18 ;
V_54:
return F_12 ( V_51 ) ;
}
static T_1 F_25 ( T_1 V_33 )
{
T_1 V_40 ;
for ( V_40 = V_34 ; V_40 < V_66 && V_67 [ V_40 ] != V_33 ; V_40 ++ )
;
return V_40 ;
}
static int F_26 ( struct V_1 * V_18 , struct V_10 * V_11 )
{
switch( V_11 -> type ) {
case V_68 :
if ( V_18 -> V_6 . V_29 != V_60 &&
V_18 -> V_6 . V_29 != V_59 )
return - V_24 ;
break;
} ;
switch( V_11 -> type ) {
default:
return - V_24 ;
case V_69 :
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
case V_68 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
if ( V_11 -> V_33 == V_88 || V_11 -> V_33 == V_89 )
return - V_24 ;
break;
case V_90 :
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
break;
case V_107 :
if ( ( V_11 -> V_49 != 0 ) && ( V_11 -> V_49 != 1 ) )
return - V_24 ;
case V_108 :
if ( V_11 -> V_33 != V_35 && V_11 -> V_33 != V_34 )
return - V_24 ;
break;
case V_109 :
if ( V_11 -> V_49 & ~ 15 )
return - V_24 ;
break;
case V_110 :
if ( V_11 -> V_49 & ~ V_111 )
return - V_24 ;
break;
case V_112 :
if ( V_11 -> V_49 > V_113 )
return - V_24 ;
break;
} ;
return 0 ;
}
static struct V_1 * F_27 ( struct V_50 * V_114 ,
T_2 V_115 )
{
int V_51 = 0 ;
struct V_1 * V_18 ;
void * V_20 ;
T_2 V_21 = V_115 - sizeof( struct V_50 ) ;
int V_3 ;
char * V_23 ;
V_18 = F_22 ( V_114 ) ;
if ( F_28 ( V_18 ) )
goto V_116;
V_20 = V_114 -> V_117 ;
V_18 -> V_6 . V_118 = 2 ;
for ( V_3 = 0 ; V_3 < V_114 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
V_51 = - V_24 ;
V_11 -> V_33 = F_25 ( V_114 -> V_119 [ V_3 ] ) ;
if ( V_11 -> V_33 == V_66 )
goto V_120;
V_11 -> type = V_114 -> V_8 [ V_3 ] ;
V_11 -> V_49 = V_114 -> V_121 [ V_3 ] ;
V_11 -> V_122 = V_123 ;
V_11 -> V_124 = V_125 ;
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
if ( ( V_11 -> type == V_73 ) && ( V_11 -> V_49 == V_126 ) ) {
V_11 -> type = V_107 ;
V_11 -> V_49 = 0 ;
}
if ( ( V_11 -> type == V_80 ) || ( V_11 -> type == V_82 ) ) {
struct V_127 * V_127 ;
F_29 () ;
V_127 = F_30 ( V_11 -> V_49 ) ;
if ( ! V_127 ) {
F_31 () ;
V_51 = - V_128 ;
goto V_120;
}
V_11 -> V_49 = F_32 ( V_127 ) ;
F_31 () ;
}
V_51 = F_26 ( V_18 , V_11 ) ;
if ( V_51 )
goto V_120;
V_51 = - V_24 ;
switch ( V_11 -> type ) {
case V_73 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_74 :
V_11 -> V_122 = F_33 ( F_34 () , V_11 -> V_49 ) ;
if ( ! F_35 ( V_11 -> V_122 ) )
goto V_120;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_11 -> V_124 = F_36 ( F_34 () , V_11 -> V_49 ) ;
if ( ! F_37 ( V_11 -> V_124 ) )
goto V_120;
break;
case V_108 :
V_18 -> V_6 . V_46 = V_11 ;
break;
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
V_23 = F_11 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_28 ( V_23 ) )
goto V_120;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_51 = F_38 ( V_11 -> type , V_11 -> V_33 , V_23 ,
( void * * ) & V_11 -> V_13 ) ;
if ( V_51 == - V_24 ) {
F_39 ( L_2 ,
V_23 ) ;
V_51 = 0 ;
}
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_120;
} else
V_11 -> V_12 = V_23 ;
break;
case V_104 :
V_23 = F_11 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_28 ( V_23 ) )
goto V_120;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_51 = F_40 ( & V_18 -> V_6 , V_23 , V_11 -> V_49 , V_11 -> V_33 ) ;
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_120;
}
break;
case V_105 :
V_23 = F_11 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_28 ( V_23 ) )
goto V_120;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_51 = F_41 ( & V_18 -> V_6 , V_23 , V_11 -> V_33 ) ;
F_3 ( V_23 ) ;
if ( V_51 )
goto V_120;
break;
case V_87 :
V_51 = F_14 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_120;
break;
case V_106 :
if ( V_18 -> V_6 . V_14 || V_11 -> V_49 > V_130 )
goto V_120;
V_23 = F_11 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_28 ( V_23 ) )
goto V_120;
V_18 -> V_6 . V_129 += V_11 -> V_49 ;
V_18 -> V_6 . V_14 = V_23 ;
break;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_116:
return V_18 ;
V_120:
if ( V_18 -> V_6 . V_7 )
F_2 ( V_18 -> V_6 . V_7 ) ;
if ( V_18 -> V_6 . V_32 )
F_42 ( V_18 -> V_6 . V_32 ) ;
F_1 ( V_18 ) ;
return F_12 ( V_51 ) ;
}
static inline T_2 F_43 ( void * * V_20 , const char * V_23 )
{
T_2 V_22 = strlen ( V_23 ) ;
memcpy ( * V_20 , V_23 , V_22 ) ;
* V_20 += V_22 ;
return V_22 ;
}
static struct V_50 * F_44 ( struct V_4 * V_28 )
{
struct V_50 * V_114 ;
void * V_20 ;
int V_3 ;
V_114 = F_13 ( sizeof( * V_114 ) + V_28 -> V_129 , V_19 ) ;
if ( F_9 ( ! V_114 ) )
return NULL ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
V_114 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_114 -> V_56 = V_28 -> V_56 ;
V_114 -> V_9 = V_28 -> V_9 ;
V_20 = V_114 -> V_117 ;
for ( V_3 = 0 ; V_3 < V_114 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_28 -> V_8 [ V_3 ] ;
V_114 -> V_8 [ V_3 ] = V_11 -> type ;
V_114 -> V_119 [ V_3 ] = V_67 [ V_11 -> V_33 ] ;
switch( V_11 -> type ) {
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
V_114 -> V_129 += V_114 -> V_121 [ V_3 ] =
F_43 ( & V_20 , V_11 -> V_12 ) ;
break;
case V_104 :
V_114 -> V_129 += V_114 -> V_121 [ V_3 ] =
F_43 ( & V_20 ,
F_45 ( V_28 -> V_7 ) ) ;
break;
case V_105 :
V_114 -> V_129 += V_114 -> V_121 [ V_3 ] =
F_43 ( & V_20 ,
F_46 ( V_28 -> V_32 ) ) ;
break;
case V_106 :
V_114 -> V_129 += V_114 -> V_121 [ V_3 ] =
F_43 ( & V_20 , V_28 -> V_14 ) ;
break;
default:
V_114 -> V_121 [ V_3 ] = V_11 -> V_49 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_114 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_114 ;
}
static int F_47 ( struct V_4 * V_131 , struct V_4 * V_132 )
{
int V_3 ;
if ( V_131 -> V_52 != V_132 -> V_52 ||
V_131 -> V_29 != V_132 -> V_29 ||
V_131 -> V_56 != V_132 -> V_56 ||
V_131 -> V_9 != V_132 -> V_9 )
return 1 ;
for ( V_3 = 0 ; V_3 < V_131 -> V_9 ; V_3 ++ ) {
if ( V_131 -> V_8 [ V_3 ] . type != V_132 -> V_8 [ V_3 ] . type ||
V_131 -> V_8 [ V_3 ] . V_33 != V_132 -> V_8 [ V_3 ] . V_33 )
return 1 ;
switch( V_131 -> V_8 [ V_3 ] . type ) {
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
if ( strcmp ( V_131 -> V_8 [ V_3 ] . V_12 , V_132 -> V_8 [ V_3 ] . V_12 ) )
return 1 ;
break;
case V_104 :
if ( strcmp ( F_45 ( V_131 -> V_7 ) ,
F_45 ( V_132 -> V_7 ) ) )
return 1 ;
break;
case V_105 :
if ( strcmp ( F_46 ( V_131 -> V_32 ) ,
F_46 ( V_132 -> V_32 ) ) )
return 1 ;
break;
case V_106 :
if ( strcmp ( V_131 -> V_14 , V_132 -> V_14 ) )
return 1 ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
if ( ! F_48 ( V_131 -> V_8 [ V_3 ] . V_122 , V_132 -> V_8 [ V_3 ] . V_122 ) )
return 1 ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
if ( ! F_49 ( V_131 -> V_8 [ V_3 ] . V_124 , V_132 -> V_8 [ V_3 ] . V_124 ) )
return 1 ;
break;
default:
if ( V_131 -> V_8 [ V_3 ] . V_49 != V_132 -> V_8 [ V_3 ] . V_49 )
return 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
if ( V_131 -> V_44 [ V_3 ] != V_132 -> V_44 [ V_3 ] )
return 1 ;
return 0 ;
}
static inline int F_50 ( struct V_10 * V_133 ,
struct V_10 * V_134 )
{
int V_135 = 0 ;
char * V_12 ;
V_12 = F_51 ( V_134 -> V_12 , V_19 ) ;
if ( F_9 ( ! V_12 ) )
return - V_27 ;
V_133 -> V_12 = V_12 ;
V_135 = F_38 ( V_133 -> type , V_133 -> V_33 , V_133 -> V_12 ,
( void * * ) & V_133 -> V_13 ) ;
if ( V_135 == - V_24 ) {
F_39 ( L_2 ,
V_133 -> V_12 ) ;
V_135 = 0 ;
}
return V_135 ;
}
struct V_1 * F_52 ( struct V_4 * V_136 )
{
T_1 V_137 = V_136 -> V_9 ;
struct V_1 * V_18 ;
struct V_4 * V_138 ;
char * V_139 ;
int V_3 , V_51 = 0 ;
V_18 = F_7 ( V_137 ) ;
if ( F_9 ( ! V_18 ) )
return F_12 ( - V_27 ) ;
V_138 = & V_18 -> V_6 ;
V_138 -> V_118 = V_136 -> V_118 ;
V_138 -> V_52 = V_136 -> V_52 ;
V_138 -> V_29 = V_136 -> V_29 ;
V_138 -> V_56 = V_136 -> V_56 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_138 -> V_44 [ V_3 ] = V_136 -> V_44 [ V_3 ] ;
V_138 -> V_140 = V_136 -> V_140 ;
V_138 -> V_129 = V_136 -> V_129 ;
V_138 -> V_31 = V_136 -> V_31 ;
V_138 -> V_9 = V_136 -> V_9 ;
V_138 -> V_32 = V_136 -> V_32 ;
memcpy ( V_138 -> V_8 , V_136 -> V_8 , sizeof( struct V_10 ) * V_137 ) ;
for ( V_3 = 0 ; V_3 < V_137 ; V_3 ++ ) {
switch ( V_138 -> V_8 [ V_3 ] . type ) {
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
V_51 = F_50 ( & V_138 -> V_8 [ V_3 ] ,
& V_136 -> V_8 [ V_3 ] ) ;
break;
case V_106 :
V_139 = F_51 ( V_136 -> V_14 , V_19 ) ;
if ( F_9 ( ! V_139 ) )
V_51 = - V_27 ;
else
V_138 -> V_14 = V_139 ;
}
if ( V_51 ) {
F_1 ( V_18 ) ;
return F_12 ( V_51 ) ;
}
}
if ( V_136 -> V_7 ) {
F_53 ( V_136 -> V_7 ) ;
V_138 -> V_7 = V_136 -> V_7 ;
}
return V_18 ;
}
static struct V_1 * F_54 ( struct V_1 * V_18 ,
struct V_141 * * V_38 )
{
struct V_1 * V_2 , * V_142 = NULL ;
struct V_141 * V_37 ;
int V_143 ;
if ( V_18 -> V_6 . V_31 ) {
V_143 = F_55 ( V_18 -> V_6 . V_31 -> V_49 ) ;
* V_38 = V_37 = & V_144 [ V_143 ] ;
} else if ( V_18 -> V_6 . V_7 ) {
for ( V_143 = 0 ; V_143 < V_145 ; V_143 ++ ) {
V_37 = & V_144 [ V_143 ] ;
F_56 (e, list, list)
if ( ! F_47 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_142 = V_2 ;
goto V_146;
}
}
goto V_146;
} else {
* V_38 = V_37 = & V_147 [ V_18 -> V_6 . V_29 ] ;
}
F_56 (e, list, list)
if ( ! F_47 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_142 = V_2 ;
goto V_146;
}
V_146:
return V_142 ;
}
static inline int F_57 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_148 * V_7 = V_18 -> V_6 . V_7 ;
struct V_149 * V_32 = V_18 -> V_6 . V_32 ;
struct V_141 * V_37 ;
int V_51 ;
#ifdef F_23
int V_150 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_150 = 1 ;
#endif
F_58 ( & V_151 ) ;
V_2 = F_54 ( V_18 , & V_37 ) ;
if ( V_2 ) {
F_59 ( & V_151 ) ;
V_51 = - V_152 ;
if ( V_32 )
F_42 ( V_32 ) ;
goto error;
}
if ( V_7 ) {
V_51 = F_60 ( & V_18 -> V_6 , & V_37 ) ;
if ( V_51 ) {
F_59 ( & V_151 ) ;
if ( V_32 )
F_42 ( V_32 ) ;
goto error;
}
}
if ( V_32 ) {
V_51 = F_61 ( & V_18 -> V_6 ) ;
if ( V_51 ) {
F_59 ( & V_151 ) ;
goto error;
}
}
V_18 -> V_6 . V_140 = ~ 0ULL ;
if ( V_18 -> V_6 . V_29 == V_30 ) {
if ( V_18 -> V_6 . V_52 & V_53 )
V_18 -> V_6 . V_140 = ++ V_153 ;
else
V_18 -> V_6 . V_140 = -- V_154 ;
}
if ( V_18 -> V_6 . V_52 & V_53 ) {
F_62 ( & V_18 -> V_6 . V_37 ,
& V_155 [ V_18 -> V_6 . V_29 ] ) ;
F_63 ( & V_18 -> V_37 , V_37 ) ;
V_18 -> V_6 . V_52 &= ~ V_53 ;
} else {
F_64 ( & V_18 -> V_6 . V_37 ,
& V_155 [ V_18 -> V_6 . V_29 ] ) ;
F_65 ( & V_18 -> V_37 , V_37 ) ;
}
#ifdef F_23
if ( ! V_150 )
V_156 ++ ;
if ( ! F_20 ( V_18 ) )
V_157 ++ ;
#endif
F_59 ( & V_151 ) ;
return 0 ;
error:
if ( V_7 )
F_2 ( V_7 ) ;
return V_51 ;
}
static inline int F_66 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_148 * V_7 = V_18 -> V_6 . V_7 ;
struct V_149 * V_32 = V_18 -> V_6 . V_32 ;
struct V_141 * V_37 ;
int V_135 = 0 ;
#ifdef F_23
int V_150 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_150 = 1 ;
#endif
F_58 ( & V_151 ) ;
V_2 = F_54 ( V_18 , & V_37 ) ;
if ( ! V_2 ) {
F_59 ( & V_151 ) ;
V_135 = - V_158 ;
goto V_146;
}
if ( V_2 -> V_6 . V_7 )
F_67 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_6 . V_32 )
F_68 ( & V_2 -> V_6 ) ;
F_69 ( & V_2 -> V_37 ) ;
F_70 ( & V_2 -> V_6 . V_37 ) ;
F_71 ( & V_2 -> V_17 , F_5 ) ;
#ifdef F_23
if ( ! V_150 )
V_156 -- ;
if ( ! F_20 ( V_18 ) )
V_157 -- ;
#endif
F_59 ( & V_151 ) ;
V_146:
if ( V_7 )
F_2 ( V_7 ) ;
if ( V_32 )
F_42 ( V_32 ) ;
return V_135 ;
}
static void F_72 ( T_4 V_159 , int V_160 , struct V_161 * V_162 )
{
struct V_163 * V_164 ;
struct V_4 * V_165 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_166 ; V_3 ++ ) {
F_56 (r, &audit_rules_list[i], list) {
struct V_50 * V_114 ;
V_114 = F_44 ( V_165 ) ;
if ( F_9 ( ! V_114 ) )
break;
V_164 = F_73 ( V_159 , V_160 , V_167 ,
0 , 1 , V_114 ,
sizeof( * V_114 ) + V_114 -> V_129 ) ;
if ( V_164 )
F_74 ( V_162 , V_164 ) ;
F_3 ( V_114 ) ;
}
}
V_164 = F_73 ( V_159 , V_160 , V_167 , 1 , 1 , NULL , 0 ) ;
if ( V_164 )
F_74 ( V_162 , V_164 ) ;
}
static void F_75 ( char * V_56 , struct V_4 * V_6 , int V_168 )
{
struct V_169 * V_170 ;
T_5 V_171 = F_76 ( & V_172 , F_77 ( V_173 ) ) ;
unsigned int V_174 = F_78 ( V_173 ) ;
if ( ! V_175 )
return;
V_170 = F_79 ( NULL , V_19 , V_176 ) ;
if ( ! V_170 )
return;
F_80 ( V_170 , L_3 , V_171 , V_174 ) ;
F_81 ( V_170 ) ;
F_80 ( V_170 , L_4 ) ;
F_82 ( V_170 , V_56 ) ;
F_83 ( V_170 , V_6 -> V_14 ) ;
F_80 ( V_170 , L_5 , V_6 -> V_29 , V_168 ) ;
F_84 ( V_170 ) ;
}
int F_85 ( int type , T_4 V_159 , int V_160 , void * V_114 ,
T_2 V_115 )
{
int V_51 = 0 ;
struct V_1 * V_18 ;
switch ( type ) {
case V_177 :
V_18 = F_27 ( V_114 , V_115 ) ;
if ( F_28 ( V_18 ) )
return F_86 ( V_18 ) ;
V_51 = F_57 ( V_18 ) ;
F_75 ( L_6 , & V_18 -> V_6 , ! V_51 ) ;
if ( V_51 )
F_1 ( V_18 ) ;
break;
case V_178 :
V_18 = F_27 ( V_114 , V_115 ) ;
if ( F_28 ( V_18 ) )
return F_86 ( V_18 ) ;
V_51 = F_66 ( V_18 ) ;
F_75 ( L_7 , & V_18 -> V_6 , ! V_51 ) ;
F_1 ( V_18 ) ;
break;
default:
return - V_24 ;
}
return V_51 ;
}
int F_87 ( struct V_163 * V_179 , int V_160 )
{
T_1 V_159 = F_88 ( V_179 ) . V_159 ;
struct V_180 * V_180 = F_89 ( F_88 ( V_179 ) . V_181 ) ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
int V_51 = 0 ;
V_185 = F_13 ( sizeof( struct V_184 ) , V_19 ) ;
if ( ! V_185 )
return - V_27 ;
V_185 -> V_180 = F_90 ( V_180 ) ;
V_185 -> V_159 = V_159 ;
F_91 ( & V_185 -> V_162 ) ;
F_58 ( & V_151 ) ;
F_72 ( V_159 , V_160 , & V_185 -> V_162 ) ;
F_59 ( & V_151 ) ;
V_183 = F_92 ( V_186 , V_185 , L_8 ) ;
if ( F_28 ( V_183 ) ) {
F_93 ( & V_185 -> V_162 ) ;
F_3 ( V_185 ) ;
V_51 = F_86 ( V_183 ) ;
}
return V_51 ;
}
int F_94 ( T_1 V_187 , T_1 V_33 , T_1 V_188 )
{
switch ( V_33 ) {
case V_34 :
return ( V_187 == V_188 ) ;
case V_35 :
return ( V_187 != V_188 ) ;
case V_189 :
return ( V_187 < V_188 ) ;
case V_190 :
return ( V_187 <= V_188 ) ;
case V_191 :
return ( V_187 > V_188 ) ;
case V_192 :
return ( V_187 >= V_188 ) ;
case V_88 :
return ( V_187 & V_188 ) ;
case V_89 :
return ( ( V_187 & V_188 ) == V_188 ) ;
default:
F_95 () ;
return 0 ;
}
}
int F_96 ( T_6 V_187 , T_1 V_33 , T_6 V_188 )
{
switch ( V_33 ) {
case V_34 :
return F_48 ( V_187 , V_188 ) ;
case V_35 :
return ! F_48 ( V_187 , V_188 ) ;
case V_189 :
return F_97 ( V_187 , V_188 ) ;
case V_190 :
return F_98 ( V_187 , V_188 ) ;
case V_191 :
return F_99 ( V_187 , V_188 ) ;
case V_192 :
return F_100 ( V_187 , V_188 ) ;
case V_88 :
case V_89 :
default:
F_95 () ;
return 0 ;
}
}
int F_101 ( T_7 V_187 , T_1 V_33 , T_7 V_188 )
{
switch ( V_33 ) {
case V_34 :
return F_49 ( V_187 , V_188 ) ;
case V_35 :
return ! F_49 ( V_187 , V_188 ) ;
case V_189 :
return F_102 ( V_187 , V_188 ) ;
case V_190 :
return F_103 ( V_187 , V_188 ) ;
case V_191 :
return F_104 ( V_187 , V_188 ) ;
case V_192 :
return F_105 ( V_187 , V_188 ) ;
case V_88 :
case V_89 :
default:
F_95 () ;
return 0 ;
}
}
int F_106 ( const char * V_193 )
{
int V_194 ;
const char * V_38 ;
V_194 = strlen ( V_193 ) ;
if ( V_194 == 0 )
return V_194 ;
V_38 = V_193 + V_194 - 1 ;
while ( ( * V_38 == '/' ) && ( V_38 > V_193 ) )
V_38 -- ;
while ( ( * V_38 != '/' ) && ( V_38 > V_193 ) )
V_38 -- ;
if ( * V_38 == '/' )
V_38 ++ ;
return V_38 - V_193 ;
}
int F_107 ( const char * V_195 , const char * V_193 , int V_196 )
{
int V_197 , V_198 ;
const char * V_38 ;
V_197 = strlen ( V_195 ) ;
V_198 = strlen ( V_193 ) ;
if ( V_198 < V_197 )
return 1 ;
V_196 = V_196 == V_199 ? F_106 ( V_193 ) : V_196 ;
if ( V_198 - V_196 != V_197 )
return 1 ;
V_38 = V_193 + V_196 ;
return strncmp ( V_38 , V_195 , V_197 ) ;
}
static int F_108 ( struct V_4 * V_6 , int type ,
enum V_200 * V_201 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_6 -> V_8 [ V_3 ] ;
T_8 V_127 ;
int V_202 = 0 ;
T_1 V_203 ;
switch ( V_11 -> type ) {
case V_80 :
V_127 = F_109 ( V_173 ) ;
V_202 = F_94 ( V_127 , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_69 :
V_202 = F_96 ( F_110 () , V_11 -> V_33 , V_11 -> V_122 ) ;
break;
case V_75 :
V_202 = F_101 ( F_111 () , V_11 -> V_33 , V_11 -> V_124 ) ;
break;
case V_73 :
V_202 = F_96 ( F_77 ( V_173 ) ,
V_11 -> V_33 , V_11 -> V_122 ) ;
break;
case V_107 :
V_202 = F_94 ( F_112 ( V_173 ) ,
V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_68 :
V_202 = F_94 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
if ( V_11 -> V_13 ) {
F_113 ( V_173 , & V_203 ) ;
V_202 = F_114 ( V_203 ,
V_11 -> type ,
V_11 -> V_33 ,
V_11 -> V_13 ,
NULL ) ;
}
break;
}
if ( ! V_202 )
return 0 ;
}
switch ( V_6 -> V_56 ) {
case V_62 : * V_201 = V_204 ; break;
case V_57 : * V_201 = V_205 ; break;
}
return 1 ;
}
int F_115 ( int type )
{
enum V_200 V_201 = V_204 ;
struct V_1 * V_2 ;
int V_206 , V_135 ;
V_135 = 1 ;
F_29 () ;
F_116 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
V_206 = F_108 ( & V_2 -> V_6 , type , & V_201 ) ;
if ( V_206 ) {
if ( V_206 > 0 && V_201 == V_204 )
V_135 = 0 ;
break;
}
}
F_31 () ;
return V_135 ;
}
int F_117 ( int type )
{
struct V_1 * V_2 ;
int V_202 = 0 ;
F_29 () ;
if ( F_118 ( & V_147 [ V_60 ] ) )
goto V_207;
F_116 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 . V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_2 -> V_6 . V_8 [ V_3 ] ;
if ( V_11 -> type == V_68 ) {
V_202 = F_94 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
if ( ! V_202 )
break;
}
}
if ( V_202 )
goto V_207;
}
V_207:
F_31 () ;
return V_202 ;
}
static int F_119 ( struct V_4 * V_165 )
{
struct V_1 * V_18 = F_6 ( V_165 , struct V_1 , V_6 ) ;
struct V_1 * V_208 ;
int V_51 = 0 ;
if ( ! F_120 ( V_165 ) )
return 0 ;
V_208 = F_52 ( V_165 ) ;
if ( F_28 ( V_208 ) ) {
V_51 = F_86 ( V_208 ) ;
F_121 ( L_9 ) ;
if ( V_165 -> V_7 )
F_70 ( & V_165 -> V_209 ) ;
F_69 ( & V_18 -> V_37 ) ;
F_70 ( & V_165 -> V_37 ) ;
} else {
if ( V_165 -> V_7 || V_165 -> V_32 )
F_122 ( & V_165 -> V_209 , & V_208 -> V_6 . V_209 ) ;
F_123 ( & V_18 -> V_37 , & V_208 -> V_37 ) ;
F_124 ( & V_165 -> V_37 , & V_208 -> V_6 . V_37 ) ;
}
F_71 ( & V_18 -> V_17 , F_5 ) ;
return V_51 ;
}
int F_125 ( void )
{
struct V_4 * V_165 , * V_40 ;
int V_3 , V_51 = 0 ;
F_58 ( & V_151 ) ;
for ( V_3 = 0 ; V_3 < V_166 ; V_3 ++ ) {
F_126 (r, n, &audit_rules_list[i], list) {
int V_168 = F_119 ( V_165 ) ;
if ( ! V_51 )
V_51 = V_168 ;
}
}
F_59 ( & V_151 ) ;
return V_51 ;
}
