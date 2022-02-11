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
static struct V_1 * F_26 ( struct V_114 * V_115 ,
T_2 V_116 )
{
int V_51 = 0 ;
struct V_1 * V_18 ;
void * V_20 ;
T_2 V_21 = V_116 - sizeof( struct V_114 ) ;
int V_3 ;
char * V_23 ;
V_18 = F_21 ( (struct V_50 * ) V_115 ) ;
if ( F_27 ( V_18 ) )
goto V_117;
V_20 = V_115 -> V_118 ;
V_18 -> V_6 . V_119 = 2 ;
for ( V_3 = 0 ; V_3 < V_115 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
V_51 = - V_24 ;
V_11 -> V_33 = F_24 ( V_115 -> V_120 [ V_3 ] ) ;
if ( V_11 -> V_33 == V_67 )
goto V_121;
V_11 -> type = V_115 -> V_8 [ V_3 ] ;
V_11 -> V_49 = V_115 -> V_122 [ V_3 ] ;
V_11 -> V_123 = V_124 ;
V_11 -> V_125 = V_126 ;
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
if ( ( V_11 -> type == V_74 ) && ( V_11 -> V_49 == 4294967295 ) ) {
V_11 -> type = V_107 ;
V_11 -> V_49 = 0 ;
}
V_51 = F_25 ( V_18 , V_11 ) ;
if ( V_51 )
goto V_121;
V_51 = - V_24 ;
switch ( V_11 -> type ) {
case V_74 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_75 :
V_11 -> V_123 = F_28 ( F_29 () , V_11 -> V_49 ) ;
if ( ! F_30 ( V_11 -> V_123 ) )
goto V_121;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_11 -> V_125 = F_31 ( F_29 () , V_11 -> V_49 ) ;
if ( ! F_32 ( V_11 -> V_125 ) )
goto V_121;
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
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_121;
V_18 -> V_6 . V_127 += V_11 -> V_49 ;
V_51 = F_33 ( V_11 -> type , V_11 -> V_33 , V_23 ,
( void * * ) & V_11 -> V_13 ) ;
if ( V_51 == - V_24 ) {
F_23 ( V_128 L_2
L_3 , V_23 ) ;
V_51 = 0 ;
}
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_121;
} else
V_11 -> V_12 = V_23 ;
break;
case V_104 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_121;
V_18 -> V_6 . V_127 += V_11 -> V_49 ;
V_51 = F_34 ( & V_18 -> V_6 , V_23 , V_11 -> V_49 , V_11 -> V_33 ) ;
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_121;
}
break;
case V_105 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_121;
V_18 -> V_6 . V_127 += V_11 -> V_49 ;
V_51 = F_35 ( & V_18 -> V_6 , V_23 , V_11 -> V_33 ) ;
F_3 ( V_23 ) ;
if ( V_51 )
goto V_121;
break;
case V_129 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_121;
break;
case V_106 :
if ( V_18 -> V_6 . V_14 || V_11 -> V_49 > V_130 )
goto V_121;
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_27 ( V_23 ) )
goto V_121;
V_18 -> V_6 . V_127 += V_11 -> V_49 ;
V_18 -> V_6 . V_14 = V_23 ;
break;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_117:
return V_18 ;
V_121:
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
static struct V_114 * F_38 ( struct V_4 * V_28 )
{
struct V_114 * V_115 ;
void * V_20 ;
int V_3 ;
V_115 = F_12 ( sizeof( * V_115 ) + V_28 -> V_127 , V_19 ) ;
if ( F_9 ( ! V_115 ) )
return NULL ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_115 -> V_56 = V_28 -> V_56 ;
V_115 -> V_9 = V_28 -> V_9 ;
V_20 = V_115 -> V_118 ;
for ( V_3 = 0 ; V_3 < V_115 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_28 -> V_8 [ V_3 ] ;
V_115 -> V_8 [ V_3 ] = V_11 -> type ;
V_115 -> V_120 [ V_3 ] = V_68 [ V_11 -> V_33 ] ;
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
V_115 -> V_127 += V_115 -> V_122 [ V_3 ] =
F_37 ( & V_20 , V_11 -> V_12 ) ;
break;
case V_104 :
V_115 -> V_127 += V_115 -> V_122 [ V_3 ] =
F_37 ( & V_20 ,
F_39 ( V_28 -> V_7 ) ) ;
break;
case V_105 :
V_115 -> V_127 += V_115 -> V_122 [ V_3 ] =
F_37 ( & V_20 ,
F_40 ( V_28 -> V_32 ) ) ;
break;
case V_106 :
V_115 -> V_127 += V_115 -> V_122 [ V_3 ] =
F_37 ( & V_20 , V_28 -> V_14 ) ;
break;
default:
V_115 -> V_122 [ V_3 ] = V_11 -> V_49 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_115 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_115 ;
}
static int F_41 ( struct V_4 * V_131 , struct V_4 * V_132 )
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
if ( strcmp ( F_39 ( V_131 -> V_7 ) ,
F_39 ( V_132 -> V_7 ) ) )
return 1 ;
break;
case V_105 :
if ( strcmp ( F_40 ( V_131 -> V_32 ) ,
F_40 ( V_132 -> V_32 ) ) )
return 1 ;
break;
case V_106 :
if ( strcmp ( V_131 -> V_14 , V_132 -> V_14 ) )
return 1 ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
if ( ! F_42 ( V_131 -> V_8 [ V_3 ] . V_123 , V_132 -> V_8 [ V_3 ] . V_123 ) )
return 1 ;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
if ( ! F_43 ( V_131 -> V_8 [ V_3 ] . V_125 , V_132 -> V_8 [ V_3 ] . V_125 ) )
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
static inline int F_44 ( struct V_10 * V_133 ,
struct V_10 * V_134 )
{
int V_135 = 0 ;
char * V_12 ;
V_12 = F_45 ( V_134 -> V_12 , V_19 ) ;
if ( F_9 ( ! V_12 ) )
return - V_27 ;
V_133 -> V_12 = V_12 ;
V_135 = F_33 ( V_133 -> type , V_133 -> V_33 , V_133 -> V_12 ,
( void * * ) & V_133 -> V_13 ) ;
if ( V_135 == - V_24 ) {
F_23 ( V_128 L_4
L_5 , V_133 -> V_12 ) ;
V_135 = 0 ;
}
return V_135 ;
}
struct V_1 * F_46 ( struct V_4 * V_136 )
{
T_1 V_137 = V_136 -> V_9 ;
struct V_1 * V_18 ;
struct V_4 * V_138 ;
char * V_139 ;
int V_3 , V_51 = 0 ;
V_18 = F_7 ( V_137 ) ;
if ( F_9 ( ! V_18 ) )
return F_11 ( - V_27 ) ;
V_138 = & V_18 -> V_6 ;
V_138 -> V_119 = V_136 -> V_119 ;
V_138 -> V_52 = V_136 -> V_52 ;
V_138 -> V_29 = V_136 -> V_29 ;
V_138 -> V_56 = V_136 -> V_56 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_138 -> V_44 [ V_3 ] = V_136 -> V_44 [ V_3 ] ;
V_138 -> V_140 = V_136 -> V_140 ;
V_138 -> V_127 = V_136 -> V_127 ;
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
V_51 = F_44 ( & V_138 -> V_8 [ V_3 ] ,
& V_136 -> V_8 [ V_3 ] ) ;
break;
case V_106 :
V_139 = F_45 ( V_136 -> V_14 , V_19 ) ;
if ( F_9 ( ! V_139 ) )
V_51 = - V_27 ;
else
V_138 -> V_14 = V_139 ;
}
if ( V_51 ) {
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
}
if ( V_136 -> V_7 ) {
F_47 ( V_136 -> V_7 ) ;
V_138 -> V_7 = V_136 -> V_7 ;
}
return V_18 ;
}
static struct V_1 * F_48 ( struct V_1 * V_18 ,
struct V_141 * * V_38 )
{
struct V_1 * V_2 , * V_142 = NULL ;
struct V_141 * V_37 ;
int V_143 ;
if ( V_18 -> V_6 . V_31 ) {
V_143 = F_49 ( V_18 -> V_6 . V_31 -> V_49 ) ;
* V_38 = V_37 = & V_144 [ V_143 ] ;
} else if ( V_18 -> V_6 . V_7 ) {
for ( V_143 = 0 ; V_143 < V_145 ; V_143 ++ ) {
V_37 = & V_144 [ V_143 ] ;
F_50 (e, list, list)
if ( ! F_41 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_142 = V_2 ;
goto V_146;
}
}
goto V_146;
} else {
* V_38 = V_37 = & V_147 [ V_18 -> V_6 . V_29 ] ;
}
F_50 (e, list, list)
if ( ! F_41 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_142 = V_2 ;
goto V_146;
}
V_146:
return V_142 ;
}
static inline int F_51 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_148 * V_7 = V_18 -> V_6 . V_7 ;
struct V_149 * V_32 = V_18 -> V_6 . V_32 ;
struct V_141 * V_37 ;
int V_51 ;
#ifdef F_22
int V_150 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_150 = 1 ;
#endif
F_52 ( & V_151 ) ;
V_2 = F_48 ( V_18 , & V_37 ) ;
if ( V_2 ) {
F_53 ( & V_151 ) ;
V_51 = - V_152 ;
if ( V_32 )
F_36 ( V_32 ) ;
goto error;
}
if ( V_7 ) {
V_51 = F_54 ( & V_18 -> V_6 , & V_37 ) ;
if ( V_51 ) {
F_53 ( & V_151 ) ;
goto error;
}
}
if ( V_32 ) {
V_51 = F_55 ( & V_18 -> V_6 ) ;
if ( V_51 ) {
F_53 ( & V_151 ) ;
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
F_56 ( & V_18 -> V_6 . V_37 ,
& V_155 [ V_18 -> V_6 . V_29 ] ) ;
F_57 ( & V_18 -> V_37 , V_37 ) ;
V_18 -> V_6 . V_52 &= ~ V_53 ;
} else {
F_58 ( & V_18 -> V_6 . V_37 ,
& V_155 [ V_18 -> V_6 . V_29 ] ) ;
F_59 ( & V_18 -> V_37 , V_37 ) ;
}
#ifdef F_22
if ( ! V_150 )
V_156 ++ ;
if ( ! F_19 ( V_18 ) )
V_157 ++ ;
#endif
F_53 ( & V_151 ) ;
return 0 ;
error:
if ( V_7 )
F_2 ( V_7 ) ;
return V_51 ;
}
static inline int F_60 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_148 * V_7 = V_18 -> V_6 . V_7 ;
struct V_149 * V_32 = V_18 -> V_6 . V_32 ;
struct V_141 * V_37 ;
int V_135 = 0 ;
#ifdef F_22
int V_150 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_150 = 1 ;
#endif
F_52 ( & V_151 ) ;
V_2 = F_48 ( V_18 , & V_37 ) ;
if ( ! V_2 ) {
F_53 ( & V_151 ) ;
V_135 = - V_158 ;
goto V_146;
}
if ( V_2 -> V_6 . V_7 )
F_61 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_6 . V_32 )
F_62 ( & V_2 -> V_6 ) ;
F_63 ( & V_2 -> V_37 ) ;
F_64 ( & V_2 -> V_6 . V_37 ) ;
F_65 ( & V_2 -> V_17 , F_5 ) ;
#ifdef F_22
if ( ! V_150 )
V_156 -- ;
if ( ! F_19 ( V_18 ) )
V_157 -- ;
#endif
F_53 ( & V_151 ) ;
V_146:
if ( V_7 )
F_2 ( V_7 ) ;
if ( V_32 )
F_36 ( V_32 ) ;
return V_135 ;
}
static void F_66 ( int V_159 , int V_160 , struct V_161 * V_162 )
{
struct V_163 * V_164 ;
struct V_4 * V_165 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_166 ; V_3 ++ ) {
F_50 (r, &audit_rules_list[i], list) {
struct V_114 * V_115 ;
V_115 = F_38 ( V_165 ) ;
if ( F_9 ( ! V_115 ) )
break;
V_164 = F_67 ( V_159 , V_160 , V_167 , 0 , 1 ,
V_115 , sizeof( * V_115 ) + V_115 -> V_127 ) ;
if ( V_164 )
F_68 ( V_162 , V_164 ) ;
F_3 ( V_115 ) ;
}
}
V_164 = F_67 ( V_159 , V_160 , V_167 , 1 , 1 , NULL , 0 ) ;
if ( V_164 )
F_68 ( V_162 , V_164 ) ;
}
static void F_69 ( char * V_56 , struct V_4 * V_6 , int V_168 )
{
struct V_169 * V_170 ;
T_5 V_171 = F_70 ( & V_172 , F_71 ( V_173 ) ) ;
T_1 V_174 = F_72 ( V_173 ) ;
if ( ! V_175 )
return;
V_170 = F_73 ( NULL , V_19 , V_176 ) ;
if ( ! V_170 )
return;
F_74 ( V_170 , L_6 , V_171 , V_174 ) ;
F_75 ( V_170 ) ;
F_74 ( V_170 , L_7 ) ;
F_76 ( V_170 , V_56 ) ;
F_77 ( V_170 , V_6 -> V_14 ) ;
F_74 ( V_170 , L_8 , V_6 -> V_29 , V_168 ) ;
F_78 ( V_170 ) ;
}
int F_79 ( int type , int V_159 , int V_160 , void * V_115 , T_2 V_116 )
{
struct V_177 * V_178 ;
struct V_179 * V_180 ;
int V_51 = 0 ;
struct V_1 * V_18 ;
switch ( type ) {
case V_167 :
V_180 = F_12 ( sizeof( struct V_179 ) , V_19 ) ;
if ( ! V_180 )
return - V_27 ;
V_180 -> V_159 = V_159 ;
F_80 ( & V_180 -> V_162 ) ;
F_52 ( & V_151 ) ;
F_66 ( V_159 , V_160 , & V_180 -> V_162 ) ;
F_53 ( & V_151 ) ;
V_178 = F_81 ( V_181 , V_180 , L_9 ) ;
if ( F_27 ( V_178 ) ) {
F_82 ( & V_180 -> V_162 ) ;
F_3 ( V_180 ) ;
V_51 = F_83 ( V_178 ) ;
}
break;
case V_182 :
V_18 = F_26 ( V_115 , V_116 ) ;
if ( F_27 ( V_18 ) )
return F_83 ( V_18 ) ;
V_51 = F_51 ( V_18 ) ;
F_69 ( L_10 , & V_18 -> V_6 , ! V_51 ) ;
if ( V_51 )
F_1 ( V_18 ) ;
break;
case V_183 :
V_18 = F_26 ( V_115 , V_116 ) ;
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
int F_84 ( T_1 V_184 , T_1 V_33 , T_1 V_185 )
{
switch ( V_33 ) {
case V_34 :
return ( V_184 == V_185 ) ;
case V_35 :
return ( V_184 != V_185 ) ;
case V_186 :
return ( V_184 < V_185 ) ;
case V_187 :
return ( V_184 <= V_185 ) ;
case V_188 :
return ( V_184 > V_185 ) ;
case V_189 :
return ( V_184 >= V_185 ) ;
case V_88 :
return ( V_184 & V_185 ) ;
case V_89 :
return ( ( V_184 & V_185 ) == V_185 ) ;
default:
F_85 () ;
return 0 ;
}
}
int F_86 ( T_6 V_184 , T_1 V_33 , T_6 V_185 )
{
switch ( V_33 ) {
case V_34 :
return F_42 ( V_184 , V_185 ) ;
case V_35 :
return ! F_42 ( V_184 , V_185 ) ;
case V_186 :
return F_87 ( V_184 , V_185 ) ;
case V_187 :
return F_88 ( V_184 , V_185 ) ;
case V_188 :
return F_89 ( V_184 , V_185 ) ;
case V_189 :
return F_90 ( V_184 , V_185 ) ;
case V_88 :
case V_89 :
default:
F_85 () ;
return 0 ;
}
}
int F_91 ( T_7 V_184 , T_1 V_33 , T_7 V_185 )
{
switch ( V_33 ) {
case V_34 :
return F_43 ( V_184 , V_185 ) ;
case V_35 :
return ! F_43 ( V_184 , V_185 ) ;
case V_186 :
return F_92 ( V_184 , V_185 ) ;
case V_187 :
return F_93 ( V_184 , V_185 ) ;
case V_188 :
return F_94 ( V_184 , V_185 ) ;
case V_189 :
return F_95 ( V_184 , V_185 ) ;
case V_88 :
case V_89 :
default:
F_85 () ;
return 0 ;
}
}
int F_96 ( const char * V_190 )
{
int V_191 ;
const char * V_38 ;
V_191 = strlen ( V_190 ) ;
if ( V_191 == 0 )
return V_191 ;
V_38 = V_190 + V_191 - 1 ;
while ( ( * V_38 == '/' ) && ( V_38 > V_190 ) )
V_38 -- ;
while ( ( * V_38 != '/' ) && ( V_38 > V_190 ) )
V_38 -- ;
if ( * V_38 == '/' )
V_38 ++ ;
return V_38 - V_190 ;
}
int F_97 ( const char * V_192 , const char * V_190 , int V_193 )
{
int V_194 , V_195 ;
const char * V_38 ;
V_194 = strlen ( V_192 ) ;
V_195 = strlen ( V_190 ) ;
if ( V_195 < V_194 )
return 1 ;
V_193 = V_193 == V_196 ? F_96 ( V_190 ) : V_193 ;
if ( V_195 - V_193 != V_194 )
return 1 ;
V_38 = V_190 + V_193 ;
return strncmp ( V_38 , V_192 , V_194 ) ;
}
static int F_98 ( struct V_4 * V_6 , int type ,
enum V_197 * V_198 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_6 -> V_8 [ V_3 ] ;
int V_199 = 0 ;
T_1 V_200 ;
switch ( V_11 -> type ) {
case V_81 :
V_199 = F_84 ( F_99 ( V_173 ) , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_70 :
V_199 = F_86 ( F_100 () , V_11 -> V_33 , V_11 -> V_123 ) ;
break;
case V_76 :
V_199 = F_91 ( F_101 () , V_11 -> V_33 , V_11 -> V_125 ) ;
break;
case V_74 :
V_199 = F_86 ( F_71 ( V_173 ) ,
V_11 -> V_33 , V_11 -> V_123 ) ;
break;
case V_107 :
V_199 = F_84 ( F_102 ( V_173 ) ,
V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_69 :
V_199 = F_84 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
if ( V_11 -> V_13 ) {
F_103 ( V_173 , & V_200 ) ;
V_199 = F_104 ( V_200 ,
V_11 -> type ,
V_11 -> V_33 ,
V_11 -> V_13 ,
NULL ) ;
}
break;
}
if ( ! V_199 )
return 0 ;
}
switch ( V_6 -> V_56 ) {
case V_63 : * V_198 = V_201 ; break;
case V_57 : * V_198 = V_202 ; break;
}
return 1 ;
}
int F_105 ( int type )
{
enum V_197 V_198 = V_201 ;
struct V_1 * V_2 ;
int V_135 = 1 ;
F_106 () ;
F_107 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
if ( F_98 ( & V_2 -> V_6 , type , & V_198 ) ) {
if ( V_198 == V_201 )
V_135 = 0 ;
break;
}
}
F_108 () ;
return V_135 ;
}
int F_109 ( int type )
{
struct V_1 * V_2 ;
int V_199 = 0 ;
F_106 () ;
if ( F_110 ( & V_147 [ V_60 ] ) )
goto V_203;
F_107 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 . V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_2 -> V_6 . V_8 [ V_3 ] ;
if ( V_11 -> type == V_69 ) {
V_199 = F_84 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
if ( ! V_199 )
break;
}
}
if ( V_199 )
goto V_203;
}
V_203:
F_108 () ;
return V_199 ;
}
static int F_111 ( struct V_4 * V_165 )
{
struct V_1 * V_18 = F_6 ( V_165 , struct V_1 , V_6 ) ;
struct V_1 * V_204 ;
int V_51 = 0 ;
if ( ! F_112 ( V_165 ) )
return 0 ;
V_204 = F_46 ( V_165 ) ;
if ( F_27 ( V_204 ) ) {
V_51 = F_83 ( V_204 ) ;
F_113 ( L_12 ) ;
if ( V_165 -> V_7 )
F_64 ( & V_165 -> V_205 ) ;
F_63 ( & V_18 -> V_37 ) ;
F_64 ( & V_165 -> V_37 ) ;
} else {
if ( V_165 -> V_7 || V_165 -> V_32 )
F_114 ( & V_165 -> V_205 , & V_204 -> V_6 . V_205 ) ;
F_115 ( & V_18 -> V_37 , & V_204 -> V_37 ) ;
F_116 ( & V_165 -> V_37 , & V_204 -> V_6 . V_37 ) ;
}
F_65 ( & V_18 -> V_17 , F_5 ) ;
return V_51 ;
}
int F_117 ( void )
{
struct V_4 * V_165 , * V_40 ;
int V_3 , V_51 = 0 ;
F_52 ( & V_151 ) ;
for ( V_3 = 0 ; V_3 < V_166 ; V_3 ++ ) {
F_118 (r, n, &audit_rules_list[i], list) {
int V_168 = F_111 ( V_165 ) ;
if ( ! V_51 )
V_51 = V_168 ;
}
}
F_53 ( & V_151 ) ;
return V_51 ;
}
