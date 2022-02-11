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
V_51 = - V_24 ;
if ( V_11 -> V_33 == V_67 )
goto V_74;
switch( V_11 -> type ) {
default:
goto V_74;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
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
if ( V_11 -> V_33 == V_92 || V_11 -> V_33 == V_93 )
goto V_74;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
break;
case V_98 :
if ( V_11 -> V_33 != V_35 && V_11 -> V_33 != V_34 )
goto V_74;
V_18 -> V_6 . V_46 = V_11 ;
break;
case V_99 :
if ( V_11 -> V_49 & ~ 15 )
goto V_74;
break;
case V_100 :
if ( V_11 -> V_49 & ~ V_101 )
goto V_74;
break;
case V_102 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_74;
break;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_69:
return V_18 ;
V_74:
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
static struct V_1 * F_27 ( struct V_103 * V_104 ,
T_2 V_105 )
{
int V_51 = 0 ;
struct V_1 * V_18 ;
void * V_20 ;
T_2 V_21 = V_105 - sizeof( struct V_103 ) ;
int V_3 ;
char * V_23 ;
V_18 = F_21 ( (struct V_50 * ) V_104 ) ;
if ( F_26 ( V_18 ) )
goto V_69;
V_20 = V_104 -> V_106 ;
V_18 -> V_6 . V_72 = 2 ;
for ( V_3 = 0 ; V_3 < V_104 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
V_51 = - V_24 ;
V_11 -> V_33 = F_24 ( V_104 -> V_107 [ V_3 ] ) ;
if ( V_11 -> V_33 == V_67 )
goto V_74;
V_11 -> type = V_104 -> V_8 [ V_3 ] ;
V_11 -> V_49 = V_104 -> V_73 [ V_3 ] ;
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
switch( V_11 -> type ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
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
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_108 :
case V_109 :
break;
case V_98 :
V_18 -> V_6 . V_46 = V_11 ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_120 += V_11 -> V_49 ;
V_51 = F_28 ( V_11 -> type , V_11 -> V_33 , V_23 ,
( void * * ) & V_11 -> V_13 ) ;
if ( V_51 == - V_24 ) {
F_23 ( V_121 L_2
L_3 , V_23 ) ;
V_51 = 0 ;
}
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_74;
} else
V_11 -> V_12 = V_23 ;
break;
case V_122 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_120 += V_11 -> V_49 ;
V_51 = F_29 ( & V_18 -> V_6 , V_23 , V_11 -> V_49 , V_11 -> V_33 ) ;
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_74;
}
break;
case V_123 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_120 += V_11 -> V_49 ;
V_51 = F_30 ( & V_18 -> V_6 , V_23 , V_11 -> V_33 ) ;
F_3 ( V_23 ) ;
if ( V_51 )
goto V_74;
break;
case V_102 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_74;
break;
case V_124 :
if ( V_18 -> V_6 . V_14 || V_11 -> V_49 > V_125 )
goto V_74;
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_120 += V_11 -> V_49 ;
V_18 -> V_6 . V_14 = V_23 ;
break;
case V_99 :
if ( V_11 -> V_49 & ~ 15 )
goto V_74;
break;
case V_100 :
if ( V_11 -> V_49 & ~ V_101 )
goto V_74;
break;
case V_126 :
if ( V_11 -> V_49 > V_127 )
goto V_74;
break;
default:
goto V_74;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_69:
return V_18 ;
V_74:
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
static inline T_2 F_31 ( void * * V_20 , const char * V_23 )
{
T_2 V_22 = strlen ( V_23 ) ;
memcpy ( * V_20 , V_23 , V_22 ) ;
* V_20 += V_22 ;
return V_22 ;
}
static struct V_50 * F_32 ( struct V_4 * V_28 )
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
static struct V_103 * F_33 ( struct V_4 * V_28 )
{
struct V_103 * V_104 ;
void * V_20 ;
int V_3 ;
V_104 = F_12 ( sizeof( * V_104 ) + V_28 -> V_120 , V_19 ) ;
if ( F_9 ( ! V_104 ) )
return NULL ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_104 -> V_56 = V_28 -> V_56 ;
V_104 -> V_9 = V_28 -> V_9 ;
V_20 = V_104 -> V_106 ;
for ( V_3 = 0 ; V_3 < V_104 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_28 -> V_8 [ V_3 ] ;
V_104 -> V_8 [ V_3 ] = V_11 -> type ;
V_104 -> V_107 [ V_3 ] = V_68 [ V_11 -> V_33 ] ;
switch( V_11 -> type ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_104 -> V_120 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 , V_11 -> V_12 ) ;
break;
case V_122 :
V_104 -> V_120 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 ,
F_34 ( V_28 -> V_7 ) ) ;
break;
case V_123 :
V_104 -> V_120 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 ,
F_35 ( V_28 -> V_32 ) ) ;
break;
case V_124 :
V_104 -> V_120 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 , V_28 -> V_14 ) ;
break;
default:
V_104 -> V_73 [ V_3 ] = V_11 -> V_49 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_104 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_104 ;
}
static int F_36 ( struct V_4 * V_128 , struct V_4 * V_129 )
{
int V_3 ;
if ( V_128 -> V_52 != V_129 -> V_52 ||
V_128 -> V_29 != V_129 -> V_29 ||
V_128 -> V_56 != V_129 -> V_56 ||
V_128 -> V_9 != V_129 -> V_9 )
return 1 ;
for ( V_3 = 0 ; V_3 < V_128 -> V_9 ; V_3 ++ ) {
if ( V_128 -> V_8 [ V_3 ] . type != V_129 -> V_8 [ V_3 ] . type ||
V_128 -> V_8 [ V_3 ] . V_33 != V_129 -> V_8 [ V_3 ] . V_33 )
return 1 ;
switch( V_128 -> V_8 [ V_3 ] . type ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
if ( strcmp ( V_128 -> V_8 [ V_3 ] . V_12 , V_129 -> V_8 [ V_3 ] . V_12 ) )
return 1 ;
break;
case V_122 :
if ( strcmp ( F_34 ( V_128 -> V_7 ) ,
F_34 ( V_129 -> V_7 ) ) )
return 1 ;
break;
case V_123 :
if ( strcmp ( F_35 ( V_128 -> V_32 ) ,
F_35 ( V_129 -> V_32 ) ) )
return 1 ;
break;
case V_124 :
if ( strcmp ( V_128 -> V_14 , V_129 -> V_14 ) )
return 1 ;
break;
default:
if ( V_128 -> V_8 [ V_3 ] . V_49 != V_129 -> V_8 [ V_3 ] . V_49 )
return 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
if ( V_128 -> V_44 [ V_3 ] != V_129 -> V_44 [ V_3 ] )
return 1 ;
return 0 ;
}
static inline int F_37 ( struct V_10 * V_130 ,
struct V_10 * V_131 )
{
int V_132 = 0 ;
char * V_12 ;
V_12 = F_38 ( V_131 -> V_12 , V_19 ) ;
if ( F_9 ( ! V_12 ) )
return - V_27 ;
V_130 -> V_12 = V_12 ;
V_132 = F_28 ( V_130 -> type , V_130 -> V_33 , V_130 -> V_12 ,
( void * * ) & V_130 -> V_13 ) ;
if ( V_132 == - V_24 ) {
F_23 ( V_121 L_4
L_5 , V_130 -> V_12 ) ;
V_132 = 0 ;
}
return V_132 ;
}
struct V_1 * F_39 ( struct V_4 * V_133 )
{
T_1 V_134 = V_133 -> V_9 ;
struct V_1 * V_18 ;
struct V_4 * V_135 ;
char * V_136 ;
int V_3 , V_51 = 0 ;
V_18 = F_7 ( V_134 ) ;
if ( F_9 ( ! V_18 ) )
return F_11 ( - V_27 ) ;
V_135 = & V_18 -> V_6 ;
V_135 -> V_72 = V_133 -> V_72 ;
V_135 -> V_52 = V_133 -> V_52 ;
V_135 -> V_29 = V_133 -> V_29 ;
V_135 -> V_56 = V_133 -> V_56 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_135 -> V_44 [ V_3 ] = V_133 -> V_44 [ V_3 ] ;
V_135 -> V_137 = V_133 -> V_137 ;
V_135 -> V_120 = V_133 -> V_120 ;
V_135 -> V_31 = V_133 -> V_31 ;
V_135 -> V_9 = V_133 -> V_9 ;
V_135 -> V_32 = V_133 -> V_32 ;
memcpy ( V_135 -> V_8 , V_133 -> V_8 , sizeof( struct V_10 ) * V_134 ) ;
for ( V_3 = 0 ; V_3 < V_134 ; V_3 ++ ) {
switch ( V_135 -> V_8 [ V_3 ] . type ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_51 = F_37 ( & V_135 -> V_8 [ V_3 ] ,
& V_133 -> V_8 [ V_3 ] ) ;
break;
case V_124 :
V_136 = F_38 ( V_133 -> V_14 , V_19 ) ;
if ( F_9 ( ! V_136 ) )
V_51 = - V_27 ;
else
V_135 -> V_14 = V_136 ;
}
if ( V_51 ) {
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
}
if ( V_133 -> V_7 ) {
F_40 ( V_133 -> V_7 ) ;
V_135 -> V_7 = V_133 -> V_7 ;
}
return V_18 ;
}
static struct V_1 * F_41 ( struct V_1 * V_18 ,
struct V_138 * * V_38 )
{
struct V_1 * V_2 , * V_139 = NULL ;
struct V_138 * V_37 ;
int V_140 ;
if ( V_18 -> V_6 . V_31 ) {
V_140 = F_42 ( V_18 -> V_6 . V_31 -> V_49 ) ;
* V_38 = V_37 = & V_141 [ V_140 ] ;
} else if ( V_18 -> V_6 . V_7 ) {
for ( V_140 = 0 ; V_140 < V_142 ; V_140 ++ ) {
V_37 = & V_141 [ V_140 ] ;
F_43 (e, list, list)
if ( ! F_36 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_139 = V_2 ;
goto V_143;
}
}
goto V_143;
} else {
* V_38 = V_37 = & V_144 [ V_18 -> V_6 . V_29 ] ;
}
F_43 (e, list, list)
if ( ! F_36 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_139 = V_2 ;
goto V_143;
}
V_143:
return V_139 ;
}
static inline int F_44 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_145 * V_7 = V_18 -> V_6 . V_7 ;
struct V_146 * V_32 = V_18 -> V_6 . V_32 ;
struct V_138 * V_37 ;
int V_51 ;
#ifdef F_22
int V_147 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_147 = 1 ;
#endif
F_45 ( & V_148 ) ;
V_2 = F_41 ( V_18 , & V_37 ) ;
if ( V_2 ) {
F_46 ( & V_148 ) ;
V_51 = - V_149 ;
if ( V_32 )
F_47 ( V_32 ) ;
goto error;
}
if ( V_7 ) {
V_51 = F_48 ( & V_18 -> V_6 , & V_37 ) ;
if ( V_51 ) {
F_46 ( & V_148 ) ;
goto error;
}
}
if ( V_32 ) {
V_51 = F_49 ( & V_18 -> V_6 ) ;
if ( V_51 ) {
F_46 ( & V_148 ) ;
goto error;
}
}
V_18 -> V_6 . V_137 = ~ 0ULL ;
if ( V_18 -> V_6 . V_29 == V_30 ) {
if ( V_18 -> V_6 . V_52 & V_53 )
V_18 -> V_6 . V_137 = ++ V_150 ;
else
V_18 -> V_6 . V_137 = -- V_151 ;
}
if ( V_18 -> V_6 . V_52 & V_53 ) {
F_50 ( & V_18 -> V_6 . V_37 ,
& V_152 [ V_18 -> V_6 . V_29 ] ) ;
F_51 ( & V_18 -> V_37 , V_37 ) ;
V_18 -> V_6 . V_52 &= ~ V_53 ;
} else {
F_52 ( & V_18 -> V_6 . V_37 ,
& V_152 [ V_18 -> V_6 . V_29 ] ) ;
F_53 ( & V_18 -> V_37 , V_37 ) ;
}
#ifdef F_22
if ( ! V_147 )
V_153 ++ ;
if ( ! F_19 ( V_18 ) )
V_154 ++ ;
#endif
F_46 ( & V_148 ) ;
return 0 ;
error:
if ( V_7 )
F_2 ( V_7 ) ;
return V_51 ;
}
static inline int F_54 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_145 * V_7 = V_18 -> V_6 . V_7 ;
struct V_146 * V_32 = V_18 -> V_6 . V_32 ;
struct V_138 * V_37 ;
int V_132 = 0 ;
#ifdef F_22
int V_147 = 0 ;
if ( V_18 -> V_6 . V_29 == V_59 ||
V_18 -> V_6 . V_29 == V_60 )
V_147 = 1 ;
#endif
F_45 ( & V_148 ) ;
V_2 = F_41 ( V_18 , & V_37 ) ;
if ( ! V_2 ) {
F_46 ( & V_148 ) ;
V_132 = - V_155 ;
goto V_143;
}
if ( V_2 -> V_6 . V_7 )
F_55 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_6 . V_32 )
F_56 ( & V_2 -> V_6 ) ;
F_57 ( & V_2 -> V_37 ) ;
F_58 ( & V_2 -> V_6 . V_37 ) ;
F_59 ( & V_2 -> V_17 , F_5 ) ;
#ifdef F_22
if ( ! V_147 )
V_153 -- ;
if ( ! F_19 ( V_18 ) )
V_154 -- ;
#endif
F_46 ( & V_148 ) ;
V_143:
if ( V_7 )
F_2 ( V_7 ) ;
if ( V_32 )
F_47 ( V_32 ) ;
return V_132 ;
}
static void F_60 ( int V_156 , int V_157 , struct V_158 * V_159 )
{
struct V_160 * V_161 ;
struct V_4 * V_162 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_163 ; V_3 ++ ) {
F_43 (r, &audit_rules_list[i], list) {
struct V_50 * V_6 ;
V_6 = F_32 ( V_162 ) ;
if ( F_9 ( ! V_6 ) )
break;
V_161 = F_61 ( V_156 , V_157 , V_164 , 0 , 1 ,
V_6 , sizeof( * V_6 ) ) ;
if ( V_161 )
F_62 ( V_159 , V_161 ) ;
F_3 ( V_6 ) ;
}
}
V_161 = F_61 ( V_156 , V_157 , V_164 , 1 , 1 , NULL , 0 ) ;
if ( V_161 )
F_62 ( V_159 , V_161 ) ;
}
static void F_63 ( int V_156 , int V_157 , struct V_158 * V_159 )
{
struct V_160 * V_161 ;
struct V_4 * V_162 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_163 ; V_3 ++ ) {
F_43 (r, &audit_rules_list[i], list) {
struct V_103 * V_104 ;
V_104 = F_33 ( V_162 ) ;
if ( F_9 ( ! V_104 ) )
break;
V_161 = F_61 ( V_156 , V_157 , V_165 , 0 , 1 ,
V_104 , sizeof( * V_104 ) + V_104 -> V_120 ) ;
if ( V_161 )
F_62 ( V_159 , V_161 ) ;
F_3 ( V_104 ) ;
}
}
V_161 = F_61 ( V_156 , V_157 , V_165 , 1 , 1 , NULL , 0 ) ;
if ( V_161 )
F_62 ( V_159 , V_161 ) ;
}
static void F_64 ( T_5 V_166 , T_1 V_167 , T_1 V_168 ,
char * V_56 , struct V_4 * V_6 ,
int V_169 )
{
struct V_170 * V_171 ;
if ( ! V_172 )
return;
V_171 = F_65 ( NULL , V_19 , V_173 ) ;
if ( ! V_171 )
return;
F_66 ( V_171 , L_6 , V_166 , V_167 ) ;
if ( V_168 ) {
char * V_174 = NULL ;
T_1 V_22 ;
if ( F_67 ( V_168 , & V_174 , & V_22 ) )
F_66 ( V_171 , L_7 , V_168 ) ;
else {
F_66 ( V_171 , L_8 , V_174 ) ;
F_68 ( V_174 , V_22 ) ;
}
}
F_66 ( V_171 , L_9 ) ;
F_69 ( V_171 , V_56 ) ;
F_70 ( V_171 , V_6 -> V_14 ) ;
F_66 ( V_171 , L_10 , V_6 -> V_29 , V_169 ) ;
F_71 ( V_171 ) ;
}
int F_72 ( int type , int V_156 , int V_175 , int V_157 , void * V_104 ,
T_2 V_105 , T_5 V_166 , T_1 V_167 , T_1 V_168 )
{
struct V_176 * V_177 ;
struct V_178 * V_179 ;
int V_51 = 0 ;
struct V_1 * V_18 ;
switch ( type ) {
case V_164 :
case V_165 :
V_179 = F_12 ( sizeof( struct V_178 ) , V_19 ) ;
if ( ! V_179 )
return - V_27 ;
V_179 -> V_156 = V_156 ;
F_73 ( & V_179 -> V_159 ) ;
F_45 ( & V_148 ) ;
if ( type == V_164 )
F_60 ( V_156 , V_157 , & V_179 -> V_159 ) ;
else
F_63 ( V_156 , V_157 , & V_179 -> V_159 ) ;
F_46 ( & V_148 ) ;
V_177 = F_74 ( V_180 , V_179 , L_11 ) ;
if ( F_26 ( V_177 ) ) {
F_75 ( & V_179 -> V_159 ) ;
F_3 ( V_179 ) ;
V_51 = F_76 ( V_177 ) ;
}
break;
case V_181 :
case V_182 :
if ( type == V_181 )
V_18 = F_25 ( V_104 ) ;
else
V_18 = F_27 ( V_104 , V_105 ) ;
if ( F_26 ( V_18 ) )
return F_76 ( V_18 ) ;
V_51 = F_44 ( V_18 ) ;
F_64 ( V_166 , V_167 , V_168 , L_12 ,
& V_18 -> V_6 , ! V_51 ) ;
if ( V_51 )
F_1 ( V_18 ) ;
break;
case V_183 :
case V_184 :
if ( type == V_183 )
V_18 = F_25 ( V_104 ) ;
else
V_18 = F_27 ( V_104 , V_105 ) ;
if ( F_26 ( V_18 ) )
return F_76 ( V_18 ) ;
V_51 = F_54 ( V_18 ) ;
F_64 ( V_166 , V_167 , V_168 , L_13 ,
& V_18 -> V_6 , ! V_51 ) ;
F_1 ( V_18 ) ;
break;
default:
return - V_24 ;
}
return V_51 ;
}
int F_77 ( T_1 V_185 , T_1 V_33 , T_1 V_186 )
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
case V_92 :
return ( V_185 & V_186 ) ;
case V_93 :
return ( ( V_185 & V_186 ) == V_186 ) ;
default:
F_78 () ;
return 0 ;
}
}
int F_79 ( const char * V_191 , const char * V_192 ,
int * V_193 )
{
int V_194 , V_195 ;
const char * V_38 ;
if ( ! V_191 || ! V_192 )
return 1 ;
V_194 = strlen ( V_191 ) ;
V_195 = strlen ( V_192 ) ;
if ( V_195 < V_194 )
return 1 ;
V_38 = V_192 + V_195 - 1 ;
while ( ( * V_38 == '/' ) && ( V_38 > V_192 ) )
V_38 -- ;
V_38 = V_38 - V_194 + 1 ;
if ( V_38 < V_192 )
return 1 ;
else if ( V_38 > V_192 ) {
if ( * -- V_38 != '/' )
return 1 ;
else
V_38 ++ ;
}
if ( V_193 )
* V_193 = V_38 - V_192 ;
return strncmp ( V_38 , V_191 , V_194 ) ;
}
static int F_80 ( struct V_196 * V_197 ,
struct V_4 * V_6 ,
enum V_198 * V_199 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_6 -> V_8 [ V_3 ] ;
int V_200 = 0 ;
T_1 V_168 ;
switch ( V_11 -> type ) {
case V_75 :
V_200 = F_77 ( V_197 -> V_201 . V_156 , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_76 :
V_200 = F_77 ( V_197 -> V_201 . V_175 , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_80 :
V_200 = F_77 ( V_197 -> V_201 . V_202 , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_84 :
V_200 = F_77 ( F_81 ( V_203 ) ,
V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
if ( V_11 -> V_13 ) {
F_82 ( V_203 , & V_168 ) ;
V_200 = F_83 ( V_168 ,
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
case V_63 : * V_199 = V_204 ; break;
case V_57 : * V_199 = V_205 ; break;
}
return 1 ;
}
int F_84 ( struct V_196 * V_197 )
{
enum V_198 V_199 = V_204 ;
struct V_1 * V_2 ;
int V_132 = 1 ;
F_85 () ;
F_86 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
if ( F_80 ( V_197 , & V_2 -> V_6 , & V_199 ) ) {
if ( V_199 == V_204 )
V_132 = 0 ;
break;
}
}
F_87 () ;
return V_132 ;
}
int F_88 ( int type )
{
struct V_1 * V_2 ;
int V_200 = 0 ;
F_85 () ;
if ( F_89 ( & V_144 [ V_60 ] ) )
goto V_206;
F_86 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 . V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_2 -> V_6 . V_8 [ V_3 ] ;
if ( V_11 -> type == V_86 ) {
V_200 = F_77 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
if ( ! V_200 )
break;
}
}
if ( V_200 )
goto V_206;
}
V_206:
F_87 () ;
return V_200 ;
}
static int F_90 ( struct V_4 * V_162 )
{
struct V_1 * V_18 = F_6 ( V_162 , struct V_1 , V_6 ) ;
struct V_1 * V_207 ;
int V_51 = 0 ;
if ( ! F_91 ( V_162 ) )
return 0 ;
V_207 = F_39 ( V_162 ) ;
if ( F_26 ( V_207 ) ) {
V_51 = F_76 ( V_207 ) ;
F_92 ( L_14 ) ;
if ( V_162 -> V_7 )
F_58 ( & V_162 -> V_208 ) ;
F_57 ( & V_18 -> V_37 ) ;
F_58 ( & V_162 -> V_37 ) ;
} else {
if ( V_162 -> V_7 || V_162 -> V_32 )
F_93 ( & V_162 -> V_208 , & V_207 -> V_6 . V_208 ) ;
F_94 ( & V_18 -> V_37 , & V_207 -> V_37 ) ;
F_95 ( & V_162 -> V_37 , & V_207 -> V_6 . V_37 ) ;
}
F_59 ( & V_18 -> V_17 , F_5 ) ;
return V_51 ;
}
int F_96 ( void )
{
struct V_4 * V_162 , * V_40 ;
int V_3 , V_51 = 0 ;
F_45 ( & V_148 ) ;
for ( V_3 = 0 ; V_3 < V_163 ; V_3 ++ ) {
F_97 (r, n, &audit_rules_list[i], list) {
int V_169 = F_90 ( V_162 ) ;
if ( ! V_51 )
V_51 = V_169 ;
}
}
F_46 ( & V_148 ) ;
return V_51 ;
}
