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
static struct V_1 * F_25 ( struct V_50 * V_6 )
{
struct V_1 * V_18 ;
int V_51 = 0 ;
int V_3 ;
V_18 = F_21 ( V_6 ) ;
if ( F_26 ( V_18 ) )
goto V_69;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
T_1 V_40 ;
V_40 = V_6 -> V_8 [ V_3 ] & ( V_70 | V_71 ) ;
if ( V_40 & V_70 )
V_11 -> V_33 = V_35 ;
else if ( ! V_40 )
V_11 -> V_33 = V_34 ;
else
V_11 -> V_33 = F_24 ( V_40 ) ;
V_18 -> V_6 . V_72 = ( V_40 & V_71 ) ? 2 : 1 ;
V_11 -> type = V_6 -> V_8 [ V_3 ] & ~ ( V_70 | V_71 ) ;
V_11 -> V_49 = V_6 -> V_73 [ V_3 ] ;
V_11 -> V_74 = V_75 ;
V_11 -> V_76 = V_77 ;
V_51 = - V_24 ;
if ( V_11 -> V_33 == V_67 )
goto V_78;
switch( V_11 -> type ) {
default:
goto V_78;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
if ( V_11 -> V_33 == V_84 || V_11 -> V_33 == V_85 )
goto V_78;
V_11 -> V_74 = F_27 ( F_28 () , V_11 -> V_49 ) ;
if ( ! F_29 ( V_11 -> V_74 ) )
goto V_78;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( V_11 -> V_33 == V_84 || V_11 -> V_33 == V_85 )
goto V_78;
V_11 -> V_76 = F_30 ( F_28 () , V_11 -> V_49 ) ;
if ( ! F_31 ( V_11 -> V_76 ) )
goto V_78;
break;
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
if ( V_11 -> V_33 == V_84 || V_11 -> V_33 == V_85 )
goto V_78;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
break;
case V_102 :
if ( V_11 -> V_33 != V_35 && V_11 -> V_33 != V_34 )
goto V_78;
V_18 -> V_6 . V_46 = V_11 ;
break;
case V_103 :
if ( V_11 -> V_49 & ~ 15 )
goto V_78;
break;
case V_104 :
if ( V_11 -> V_49 & ~ V_105 )
goto V_78;
break;
case V_106 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_78;
break;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_69:
return V_18 ;
V_78:
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
static struct V_1 * F_32 ( struct V_107 * V_108 ,
T_2 V_109 )
{
int V_51 = 0 ;
struct V_1 * V_18 ;
void * V_20 ;
T_2 V_21 = V_109 - sizeof( struct V_107 ) ;
int V_3 ;
char * V_23 ;
V_18 = F_21 ( (struct V_50 * ) V_108 ) ;
if ( F_26 ( V_18 ) )
goto V_69;
V_20 = V_108 -> V_110 ;
V_18 -> V_6 . V_72 = 2 ;
for ( V_3 = 0 ; V_3 < V_108 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
V_51 = - V_24 ;
V_11 -> V_33 = F_24 ( V_108 -> V_111 [ V_3 ] ) ;
if ( V_11 -> V_33 == V_67 )
goto V_78;
V_11 -> type = V_108 -> V_8 [ V_3 ] ;
V_11 -> V_49 = V_108 -> V_73 [ V_3 ] ;
V_11 -> V_74 = V_75 ;
V_11 -> V_76 = V_77 ;
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
switch( V_11 -> type ) {
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_112 :
if ( V_11 -> V_33 == V_84 || V_11 -> V_33 == V_85 )
goto V_78;
V_11 -> V_74 = F_27 ( F_28 () , V_11 -> V_49 ) ;
if ( ! F_29 ( V_11 -> V_74 ) )
goto V_78;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_113 :
if ( V_11 -> V_33 == V_84 || V_11 -> V_33 == V_85 )
goto V_78;
V_11 -> V_76 = F_30 ( F_28 () , V_11 -> V_49 ) ;
if ( ! F_31 ( V_11 -> V_76 ) )
goto V_78;
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
break;
case V_102 :
V_18 -> V_6 . V_46 = V_11 ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_78;
V_18 -> V_6 . V_124 += V_11 -> V_49 ;
V_51 = F_33 ( V_11 -> type , V_11 -> V_33 , V_23 ,
( void * * ) & V_11 -> V_13 ) ;
if ( V_51 == - V_24 ) {
F_23 ( V_125 L_2
L_3 , V_23 ) ;
V_51 = 0 ;
}
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_78;
} else
V_11 -> V_12 = V_23 ;
break;
case V_126 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_78;
V_18 -> V_6 . V_124 += V_11 -> V_49 ;
V_51 = F_34 ( & V_18 -> V_6 , V_23 , V_11 -> V_49 , V_11 -> V_33 ) ;
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_78;
}
break;
case V_127 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_78;
V_18 -> V_6 . V_124 += V_11 -> V_49 ;
V_51 = F_35 ( & V_18 -> V_6 , V_23 , V_11 -> V_33 ) ;
F_3 ( V_23 ) ;
if ( V_51 )
goto V_78;
break;
case V_106 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_78;
break;
case V_128 :
if ( V_18 -> V_6 . V_14 || V_11 -> V_49 > V_129 )
goto V_78;
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_78;
V_18 -> V_6 . V_124 += V_11 -> V_49 ;
V_18 -> V_6 . V_14 = V_23 ;
break;
case V_103 :
if ( V_11 -> V_49 & ~ 15 )
goto V_78;
break;
case V_104 :
if ( V_11 -> V_49 & ~ V_105 )
goto V_78;
break;
case V_130 :
if ( V_11 -> V_49 > V_131 )
goto V_78;
break;
default:
goto V_78;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_69:
return V_18 ;
V_78:
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
static inline T_2 F_36 ( void * * V_20 , const char * V_23 )
{
T_2 V_22 = strlen ( V_23 ) ;
memcpy ( * V_20 , V_23 , V_22 ) ;
* V_20 += V_22 ;
return V_22 ;
}
static struct V_50 * F_37 ( struct V_4 * V_28 )
{
struct V_50 * V_6 ;
int V_3 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_19 ) ;
if ( F_9 ( ! V_6 ) )
return NULL ;
V_6 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_6 -> V_56 = V_28 -> V_56 ;
V_6 -> V_9 = V_28 -> V_9 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
V_6 -> V_73 [ V_3 ] = V_28 -> V_8 [ V_3 ] . V_49 ;
V_6 -> V_8 [ V_3 ] = V_28 -> V_8 [ V_3 ] . type ;
if ( V_28 -> V_72 == 1 ) {
if ( V_28 -> V_8 [ V_3 ] . V_33 == V_35 )
V_6 -> V_8 [ V_3 ] |= V_70 ;
} else {
V_6 -> V_8 [ V_3 ] |= V_68 [ V_28 -> V_8 [ V_3 ] . V_33 ] ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_6 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_6 ;
}
static struct V_107 * F_38 ( struct V_4 * V_28 )
{
struct V_107 * V_108 ;
void * V_20 ;
int V_3 ;
V_108 = F_12 ( sizeof( * V_108 ) + V_28 -> V_124 , V_19 ) ;
if ( F_9 ( ! V_108 ) )
return NULL ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_108 -> V_56 = V_28 -> V_56 ;
V_108 -> V_9 = V_28 -> V_9 ;
V_20 = V_108 -> V_110 ;
for ( V_3 = 0 ; V_3 < V_108 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_28 -> V_8 [ V_3 ] ;
V_108 -> V_8 [ V_3 ] = V_11 -> type ;
V_108 -> V_111 [ V_3 ] = V_68 [ V_11 -> V_33 ] ;
switch( V_11 -> type ) {
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_108 -> V_124 += V_108 -> V_73 [ V_3 ] =
F_36 ( & V_20 , V_11 -> V_12 ) ;
break;
case V_126 :
V_108 -> V_124 += V_108 -> V_73 [ V_3 ] =
F_36 ( & V_20 ,
F_39 ( V_28 -> V_7 ) ) ;
break;
case V_127 :
V_108 -> V_124 += V_108 -> V_73 [ V_3 ] =
F_36 ( & V_20 ,
F_40 ( V_28 -> V_32 ) ) ;
break;
case V_128 :
V_108 -> V_124 += V_108 -> V_73 [ V_3 ] =
F_36 ( & V_20 , V_28 -> V_14 ) ;
break;
default:
V_108 -> V_73 [ V_3 ] = V_11 -> V_49 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_108 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_108 ;
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
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
if ( strcmp ( V_132 -> V_8 [ V_3 ] . V_12 , V_133 -> V_8 [ V_3 ] . V_12 ) )
return 1 ;
break;
case V_126 :
if ( strcmp ( F_39 ( V_132 -> V_7 ) ,
F_39 ( V_133 -> V_7 ) ) )
return 1 ;
break;
case V_127 :
if ( strcmp ( F_40 ( V_132 -> V_32 ) ,
F_40 ( V_133 -> V_32 ) ) )
return 1 ;
break;
case V_128 :
if ( strcmp ( V_132 -> V_14 , V_133 -> V_14 ) )
return 1 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_112 :
if ( ! F_42 ( V_132 -> V_8 [ V_3 ] . V_74 , V_133 -> V_8 [ V_3 ] . V_74 ) )
return 1 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_113 :
if ( ! F_43 ( V_132 -> V_8 [ V_3 ] . V_76 , V_133 -> V_8 [ V_3 ] . V_76 ) )
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
F_23 ( V_125 L_4
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
V_139 -> V_72 = V_137 -> V_72 ;
V_139 -> V_52 = V_137 -> V_52 ;
V_139 -> V_29 = V_137 -> V_29 ;
V_139 -> V_56 = V_137 -> V_56 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_139 -> V_44 [ V_3 ] = V_137 -> V_44 [ V_3 ] ;
V_139 -> V_141 = V_137 -> V_141 ;
V_139 -> V_124 = V_137 -> V_124 ;
V_139 -> V_31 = V_137 -> V_31 ;
V_139 -> V_9 = V_137 -> V_9 ;
V_139 -> V_32 = V_137 -> V_32 ;
memcpy ( V_139 -> V_8 , V_137 -> V_8 , sizeof( struct V_10 ) * V_138 ) ;
for ( V_3 = 0 ; V_3 < V_138 ; V_3 ++ ) {
switch ( V_139 -> V_8 [ V_3 ] . type ) {
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_51 = F_44 ( & V_139 -> V_8 [ V_3 ] ,
& V_137 -> V_8 [ V_3 ] ) ;
break;
case V_128 :
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
F_54 ( V_32 ) ;
goto error;
}
if ( V_7 ) {
V_51 = F_55 ( & V_18 -> V_6 , & V_37 ) ;
if ( V_51 ) {
F_53 ( & V_152 ) ;
goto error;
}
}
if ( V_32 ) {
V_51 = F_56 ( & V_18 -> V_6 ) ;
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
F_57 ( & V_18 -> V_6 . V_37 ,
& V_156 [ V_18 -> V_6 . V_29 ] ) ;
F_58 ( & V_18 -> V_37 , V_37 ) ;
V_18 -> V_6 . V_52 &= ~ V_53 ;
} else {
F_59 ( & V_18 -> V_6 . V_37 ,
& V_156 [ V_18 -> V_6 . V_29 ] ) ;
F_60 ( & V_18 -> V_37 , V_37 ) ;
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
static inline int F_61 ( struct V_1 * V_18 )
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
F_62 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_6 . V_32 )
F_63 ( & V_2 -> V_6 ) ;
F_64 ( & V_2 -> V_37 ) ;
F_65 ( & V_2 -> V_6 . V_37 ) ;
F_66 ( & V_2 -> V_17 , F_5 ) ;
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
F_54 ( V_32 ) ;
return V_136 ;
}
static void F_67 ( int V_160 , int V_161 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
struct V_4 * V_166 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_167 ; V_3 ++ ) {
F_50 (r, &audit_rules_list[i], list) {
struct V_50 * V_6 ;
V_6 = F_37 ( V_166 ) ;
if ( F_9 ( ! V_6 ) )
break;
V_165 = F_68 ( V_160 , V_161 , V_168 , 0 , 1 ,
V_6 , sizeof( * V_6 ) ) ;
if ( V_165 )
F_69 ( V_163 , V_165 ) ;
F_3 ( V_6 ) ;
}
}
V_165 = F_68 ( V_160 , V_161 , V_168 , 1 , 1 , NULL , 0 ) ;
if ( V_165 )
F_69 ( V_163 , V_165 ) ;
}
static void F_70 ( int V_160 , int V_161 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
struct V_4 * V_166 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_167 ; V_3 ++ ) {
F_50 (r, &audit_rules_list[i], list) {
struct V_107 * V_108 ;
V_108 = F_38 ( V_166 ) ;
if ( F_9 ( ! V_108 ) )
break;
V_165 = F_68 ( V_160 , V_161 , V_169 , 0 , 1 ,
V_108 , sizeof( * V_108 ) + V_108 -> V_124 ) ;
if ( V_165 )
F_69 ( V_163 , V_165 ) ;
F_3 ( V_108 ) ;
}
}
V_165 = F_68 ( V_160 , V_161 , V_169 , 1 , 1 , NULL , 0 ) ;
if ( V_165 )
F_69 ( V_163 , V_165 ) ;
}
static void F_71 ( T_5 V_170 , T_1 V_171 , T_1 V_172 ,
char * V_56 , struct V_4 * V_6 ,
int V_173 )
{
struct V_174 * V_175 ;
if ( ! V_176 )
return;
V_175 = F_72 ( NULL , V_19 , V_177 ) ;
if ( ! V_175 )
return;
F_73 ( V_175 , L_6 ,
F_74 ( & V_178 , V_170 ) , V_171 ) ;
if ( V_172 ) {
char * V_179 = NULL ;
T_1 V_22 ;
if ( F_75 ( V_172 , & V_179 , & V_22 ) )
F_73 ( V_175 , L_7 , V_172 ) ;
else {
F_73 ( V_175 , L_8 , V_179 ) ;
F_76 ( V_179 , V_22 ) ;
}
}
F_73 ( V_175 , L_9 ) ;
F_77 ( V_175 , V_56 ) ;
F_78 ( V_175 , V_6 -> V_14 ) ;
F_73 ( V_175 , L_10 , V_6 -> V_29 , V_173 ) ;
F_79 ( V_175 ) ;
}
int F_80 ( int type , int V_160 , int V_161 , void * V_108 ,
T_2 V_109 , T_5 V_170 , T_1 V_171 , T_1 V_172 )
{
struct V_180 * V_181 ;
struct V_182 * V_183 ;
int V_51 = 0 ;
struct V_1 * V_18 ;
switch ( type ) {
case V_168 :
case V_169 :
V_183 = F_12 ( sizeof( struct V_182 ) , V_19 ) ;
if ( ! V_183 )
return - V_27 ;
V_183 -> V_160 = V_160 ;
F_81 ( & V_183 -> V_163 ) ;
F_52 ( & V_152 ) ;
if ( type == V_168 )
F_67 ( V_160 , V_161 , & V_183 -> V_163 ) ;
else
F_70 ( V_160 , V_161 , & V_183 -> V_163 ) ;
F_53 ( & V_152 ) ;
V_181 = F_82 ( V_184 , V_183 , L_11 ) ;
if ( F_26 ( V_181 ) ) {
F_83 ( & V_183 -> V_163 ) ;
F_3 ( V_183 ) ;
V_51 = F_84 ( V_181 ) ;
}
break;
case V_185 :
case V_186 :
if ( type == V_185 )
V_18 = F_25 ( V_108 ) ;
else
V_18 = F_32 ( V_108 , V_109 ) ;
if ( F_26 ( V_18 ) )
return F_84 ( V_18 ) ;
V_51 = F_51 ( V_18 ) ;
F_71 ( V_170 , V_171 , V_172 , L_12 ,
& V_18 -> V_6 , ! V_51 ) ;
if ( V_51 )
F_1 ( V_18 ) ;
break;
case V_187 :
case V_188 :
if ( type == V_187 )
V_18 = F_25 ( V_108 ) ;
else
V_18 = F_32 ( V_108 , V_109 ) ;
if ( F_26 ( V_18 ) )
return F_84 ( V_18 ) ;
V_51 = F_61 ( V_18 ) ;
F_71 ( V_170 , V_171 , V_172 , L_13 ,
& V_18 -> V_6 , ! V_51 ) ;
F_1 ( V_18 ) ;
break;
default:
return - V_24 ;
}
return V_51 ;
}
int F_85 ( T_1 V_189 , T_1 V_33 , T_1 V_190 )
{
switch ( V_33 ) {
case V_34 :
return ( V_189 == V_190 ) ;
case V_35 :
return ( V_189 != V_190 ) ;
case V_191 :
return ( V_189 < V_190 ) ;
case V_192 :
return ( V_189 <= V_190 ) ;
case V_193 :
return ( V_189 > V_190 ) ;
case V_194 :
return ( V_189 >= V_190 ) ;
case V_84 :
return ( V_189 & V_190 ) ;
case V_85 :
return ( ( V_189 & V_190 ) == V_190 ) ;
default:
F_86 () ;
return 0 ;
}
}
int F_87 ( T_5 V_189 , T_1 V_33 , T_5 V_190 )
{
switch ( V_33 ) {
case V_34 :
return F_42 ( V_189 , V_190 ) ;
case V_35 :
return ! F_42 ( V_189 , V_190 ) ;
case V_191 :
return F_88 ( V_189 , V_190 ) ;
case V_192 :
return F_89 ( V_189 , V_190 ) ;
case V_193 :
return F_90 ( V_189 , V_190 ) ;
case V_194 :
return F_91 ( V_189 , V_190 ) ;
case V_84 :
case V_85 :
default:
F_86 () ;
return 0 ;
}
}
int F_92 ( T_6 V_189 , T_1 V_33 , T_6 V_190 )
{
switch ( V_33 ) {
case V_34 :
return F_43 ( V_189 , V_190 ) ;
case V_35 :
return ! F_43 ( V_189 , V_190 ) ;
case V_191 :
return F_93 ( V_189 , V_190 ) ;
case V_192 :
return F_94 ( V_189 , V_190 ) ;
case V_193 :
return F_95 ( V_189 , V_190 ) ;
case V_194 :
return F_96 ( V_189 , V_190 ) ;
case V_84 :
case V_85 :
default:
F_86 () ;
return 0 ;
}
}
int F_97 ( const char * V_195 )
{
int V_196 ;
const char * V_38 ;
V_196 = strlen ( V_195 ) ;
if ( V_196 == 0 )
return V_196 ;
V_38 = V_195 + V_196 - 1 ;
while ( ( * V_38 == '/' ) && ( V_38 > V_195 ) )
V_38 -- ;
while ( ( * V_38 != '/' ) && ( V_38 > V_195 ) )
V_38 -- ;
if ( * V_38 == '/' )
V_38 ++ ;
return V_38 - V_195 ;
}
int F_98 ( const char * V_197 , const char * V_195 , int V_198 )
{
int V_199 , V_200 ;
const char * V_38 ;
V_199 = strlen ( V_197 ) ;
V_200 = strlen ( V_195 ) ;
if ( V_200 < V_199 )
return 1 ;
V_198 = V_198 == V_201 ? F_97 ( V_195 ) : V_198 ;
if ( V_200 - V_198 != V_199 )
return 1 ;
V_38 = V_195 + V_198 ;
return strncmp ( V_38 , V_197 , V_199 ) ;
}
static int F_99 ( struct V_4 * V_6 ,
enum V_202 * V_203 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_6 -> V_8 [ V_3 ] ;
int V_204 = 0 ;
T_1 V_172 ;
switch ( V_11 -> type ) {
case V_90 :
V_204 = F_85 ( F_100 ( V_205 ) , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_79 :
V_204 = F_87 ( F_101 () , V_11 -> V_33 , V_11 -> V_74 ) ;
break;
case V_86 :
V_204 = F_92 ( F_102 () , V_11 -> V_33 , V_11 -> V_76 ) ;
break;
case V_83 :
V_204 = F_87 ( F_103 ( V_205 ) ,
V_11 -> V_33 , V_11 -> V_74 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
if ( V_11 -> V_13 ) {
F_104 ( V_205 , & V_172 ) ;
V_204 = F_105 ( V_172 ,
V_11 -> type ,
V_11 -> V_33 ,
V_11 -> V_13 ,
NULL ) ;
}
break;
}
if ( ! V_204 )
return 0 ;
}
switch ( V_6 -> V_56 ) {
case V_63 : * V_203 = V_206 ; break;
case V_57 : * V_203 = V_207 ; break;
}
return 1 ;
}
int F_106 ( void )
{
enum V_202 V_203 = V_206 ;
struct V_1 * V_2 ;
int V_136 = 1 ;
F_107 () ;
F_108 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
if ( F_99 ( & V_2 -> V_6 , & V_203 ) ) {
if ( V_203 == V_206 )
V_136 = 0 ;
break;
}
}
F_109 () ;
return V_136 ;
}
int F_110 ( int type )
{
struct V_1 * V_2 ;
int V_204 = 0 ;
F_107 () ;
if ( F_111 ( & V_148 [ V_60 ] ) )
goto V_208;
F_108 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 . V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_2 -> V_6 . V_8 [ V_3 ] ;
if ( V_11 -> type == V_92 ) {
V_204 = F_85 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
if ( ! V_204 )
break;
}
}
if ( V_204 )
goto V_208;
}
V_208:
F_109 () ;
return V_204 ;
}
static int F_112 ( struct V_4 * V_166 )
{
struct V_1 * V_18 = F_6 ( V_166 , struct V_1 , V_6 ) ;
struct V_1 * V_209 ;
int V_51 = 0 ;
if ( ! F_113 ( V_166 ) )
return 0 ;
V_209 = F_46 ( V_166 ) ;
if ( F_26 ( V_209 ) ) {
V_51 = F_84 ( V_209 ) ;
F_114 ( L_14 ) ;
if ( V_166 -> V_7 )
F_65 ( & V_166 -> V_210 ) ;
F_64 ( & V_18 -> V_37 ) ;
F_65 ( & V_166 -> V_37 ) ;
} else {
if ( V_166 -> V_7 || V_166 -> V_32 )
F_115 ( & V_166 -> V_210 , & V_209 -> V_6 . V_210 ) ;
F_116 ( & V_18 -> V_37 , & V_209 -> V_37 ) ;
F_117 ( & V_166 -> V_37 , & V_209 -> V_6 . V_37 ) ;
}
F_66 ( & V_18 -> V_17 , F_5 ) ;
return V_51 ;
}
int F_118 ( void )
{
struct V_4 * V_166 , * V_40 ;
int V_3 , V_51 = 0 ;
F_52 ( & V_152 ) ;
for ( V_3 = 0 ; V_3 < V_167 ; V_3 ++ ) {
F_119 (r, n, &audit_rules_list[i], list) {
int V_173 = F_112 ( V_166 ) ;
if ( ! V_51 )
V_51 = V_173 ;
}
}
F_53 ( & V_152 ) ;
return V_51 ;
}
