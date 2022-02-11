static unsigned char * F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
void * V_5 )
{
void * V_6 = NULL ;
struct {
T_1 V_7 ;
T_1 V_8 ;
} * V_9 , V_10 ;
int V_11 = * V_4 ;
V_9 = F_2 ( V_2 , 0 , 2 , & V_10 ) ;
if ( V_9 == NULL || V_9 -> V_8 < 2 || ! F_3 ( V_2 , V_9 -> V_8 ) )
return NULL ;
V_9 -> V_8 -= 2 ;
* V_3 = V_9 -> V_7 ;
* V_4 = V_9 -> V_8 ;
if ( V_11 > V_9 -> V_8 )
V_11 = V_9 -> V_8 ;
V_6 = F_2 ( V_2 , 2 , V_11 , V_5 ) ;
F_4 ( V_2 , 2 + V_9 -> V_8 ) ;
return V_6 ;
}
static struct V_1 * F_5 ( struct V_12 * V_13 , const void * V_14 ,
int V_15 , T_2 V_16 )
{
struct V_1 * V_2 = F_6 ( V_17 + V_15 , V_16 ) ;
if ( ! V_2 )
return NULL ;
F_7 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_17 ) ;
F_9 ( V_2 , V_15 ) ;
F_10 ( V_2 , V_14 , V_15 ) ;
F_11 ( V_2 , sizeof( struct V_18 ) ) ;
F_12 ( V_2 ) ;
return V_2 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_1 * V_19 , T_1 V_20 ,
const void * V_6 , int V_15 , T_2 V_16 )
{
const struct V_18 * V_21 = F_14 ( V_19 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
struct V_22 V_23 ;
V_2 = F_5 ( V_13 , V_6 , V_15 , V_16 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = V_21 -> V_25 ;
V_9 -> V_26 = V_21 -> V_26 + 1 ;
V_9 -> V_27 = V_21 -> V_27 ;
V_9 -> V_28 = V_20 ;
F_15 ( V_19 , & V_23 ) ;
return F_16 ( V_13 , V_2 , & V_23 ) ;
}
static int F_17 ( struct V_12 * V_13 , T_1 V_29 , T_1 V_20 ,
const void * V_6 , int V_15 , T_2 V_16 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , V_6 , V_15 , V_16 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = V_29 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_20 ;
return F_16 ( V_13 , V_2 , NULL ) ;
}
static int F_19 ( struct V_12 * V_13 , T_1 V_29 , T_1 V_20 ,
const void * V_6 , int V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , V_6 , V_15 , V_32 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = V_29 ;
V_9 -> V_26 = V_29 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_20 ;
return F_16 ( V_13 , V_2 , NULL ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
T_1 V_6 [ 4 ] = {
V_33 , F_21 ( 2 ) ,
V_31 -> V_34 , V_31 -> V_35 ,
} ;
return F_17 ( V_13 , V_36 , 1 ,
V_6 , 4 , V_37 ) ;
}
static int F_22 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
static const T_1 V_6 [ 20 ] = {
V_38 , V_38 , V_38 , 2 ,
V_39 , F_21 ( 5 ) , 3 , V_38 ,
V_40 ,
V_41 ,
V_42 ,
V_38 ,
V_43 , F_21 ( 5 ) , 3 , V_38 ,
V_40 ,
V_41 ,
V_42 ,
V_38 ,
} ;
F_23 () ;
return F_13 ( V_13 , V_2 , V_44 , V_6 , sizeof( V_6 ) ,
V_32 ) ;
}
static int F_24 ( struct V_12 * V_13 , struct V_1 * V_2 , T_1 V_20 ,
T_2 V_16 )
{
static const T_1 V_6 [ 4 ] = { V_38 , V_38 , V_38 , 0 } ;
F_25 ( V_20 == V_44 ) ;
return F_13 ( V_13 , V_2 , V_20 , V_6 , sizeof( V_6 ) , V_16 ) ;
}
static int F_26 ( struct V_12 * V_13 , struct V_1 * V_19 , T_1 V_20 ,
T_2 V_16 )
{
const struct V_18 * V_21 = F_14 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_18 * V_9 ;
struct V_22 V_45 ;
T_1 V_6 [ 4 ] = {
V_21 -> V_6 [ 0 ] ,
V_20 ,
V_38 , V_38 ,
} ;
V_2 = F_5 ( V_13 , V_6 , 4 , V_16 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = V_21 -> V_25 ;
V_9 -> V_26 = V_46 ;
V_9 -> V_27 = V_21 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_21 -> V_6 [ 1 ] ;
F_15 ( V_19 , & V_45 ) ;
return F_16 ( V_13 , V_2 , & V_45 ) ;
}
static int F_27 ( struct V_12 * V_13 , T_1 type , T_1 V_47 , T_2 V_16 )
{
T_1 V_6 [ 4 ] = { type , V_38 , V_38 , V_47 } ;
return F_17 ( V_13 , V_48 , V_49 ,
V_6 , 4 , V_16 ) ;
}
static void F_28 ( struct V_12 * V_13 , T_2 V_16 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
F_29 ( V_13 -> V_50 != V_51 ) ;
switch ( V_31 -> V_35 ) {
case V_42 :
break;
case V_41 :
if ( F_27 ( V_13 , V_52 ,
V_53 , V_16 ) == 0 )
V_31 -> V_54 = 1 ;
break;
case V_40 :
if ( ( V_31 -> V_54 + V_55 ) > V_56 )
break;
if ( F_27 ( V_13 , V_57 ,
V_56 - V_31 -> V_54 ,
V_16 ) == 0 )
V_31 -> V_54 = V_56 ;
break;
}
}
static int F_30 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 ;
int V_59 = 0 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) + 4 ) )
return - V_60 ;
V_58 = F_14 ( V_2 ) ;
if ( V_58 -> V_6 [ 0 ] != V_49 ) {
F_31 ( V_61 L_1 ,
( unsigned ) V_58 -> V_6 [ 0 ] ) ;
return - V_62 ;
}
switch ( V_58 -> V_6 [ 1 ] ) {
case V_52 :
switch ( V_31 -> V_34 ) {
case V_42 :
switch ( V_58 -> V_6 [ 4 ] ) {
case V_63 :
F_32 ( & V_31 -> V_64 , 0 ) ;
break;
case V_53 :
F_32 ( & V_31 -> V_64 , V_59 = 1 ) ;
break;
}
break;
case V_41 :
if ( V_58 -> V_6 [ 4 ] == V_53 )
F_32 ( & V_31 -> V_64 , V_59 = 1 ) ;
break;
}
break;
case V_57 :
if ( V_31 -> V_34 != V_40 )
break;
F_33 ( V_59 = V_58 -> V_6 [ 4 ] , & V_31 -> V_64 ) ;
break;
default:
F_31 ( V_61 L_2 ,
( unsigned ) V_58 -> V_6 [ 1 ] ) ;
return - V_62 ;
}
if ( V_59 )
V_13 -> V_65 ( V_13 ) ;
return 0 ;
}
static int F_34 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
T_1 V_66 = V_58 -> V_6 [ 0 ] ;
V_31 -> V_35 = V_31 -> V_34 = V_42 ;
F_4 ( V_2 , sizeof( * V_58 ) ) ;
while ( V_66 > 0 ) {
T_1 type , V_5 [ 2 ] , V_15 = sizeof( V_5 ) ;
T_1 * V_6 = F_1 ( V_2 , & type , & V_15 , V_5 ) ;
if ( V_6 == NULL )
return - V_60 ;
switch ( type ) {
case V_33 :
if ( V_15 < 2 || ( V_6 [ 0 ] | V_6 [ 1 ] ) > 3 )
break;
V_31 -> V_34 = V_6 [ 0 ] & 3 ;
V_31 -> V_35 = V_6 [ 1 ] & 3 ;
break;
}
V_66 -- ;
}
return 0 ;
}
static int F_35 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
struct V_67 * V_68 ;
int V_69 = 0 ;
F_29 ( V_13 -> V_50 == V_70 ) ;
switch ( V_58 -> V_26 ) {
case V_71 :
F_24 ( V_13 , V_2 , V_72 , V_37 ) ;
break;
case V_73 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
V_13 -> V_50 = V_70 ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_75 ( V_13 ) ;
break;
case V_76 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_77 :
switch ( V_58 -> V_78 ) {
case V_79 :
V_31 -> V_80 = 0 ;
break;
case V_81 :
V_31 -> V_80 = 1 ;
break;
default:
V_69 = - V_60 ;
goto V_82;
}
case V_83 :
F_32 ( & V_31 -> V_64 , 0 ) ;
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_84 :
if ( F_37 ( & V_31 -> V_85 ) >= V_86 ) {
F_38 ( & V_13 -> V_87 ) ;
break;
}
F_4 ( V_2 , 4 ) ;
V_68 = & V_31 -> V_85 ;
goto V_68;
case V_88 :
F_4 ( V_2 , 1 ) ;
case V_89 :
F_4 ( V_2 , 3 ) ;
if ( ! F_39 ( V_31 -> V_35 ) ) {
V_69 = F_40 ( V_13 , V_2 ) ;
if ( ! V_69 )
return V_90 ;
V_69 = - V_91 ;
break;
}
if ( V_31 -> V_54 == 0 ) {
F_38 ( & V_13 -> V_87 ) ;
V_69 = - V_91 ;
break;
}
V_31 -> V_54 -- ;
V_68 = & V_13 -> V_92 ;
goto V_68;
case V_48 :
F_30 ( V_13 , V_2 ) ;
break;
case V_93 :
V_69 = F_34 ( V_13 , V_2 ) ;
break;
case V_36 :
V_69 = F_34 ( V_13 , V_2 ) ;
if ( V_69 )
break;
case V_94 :
if ( ! V_31 -> V_80 )
break;
case V_95 :
if ( ! F_39 ( V_31 -> V_34 ) ) {
F_32 ( & V_31 -> V_64 , 1 ) ;
V_13 -> V_65 ( V_13 ) ;
}
if ( V_13 -> V_50 == V_51 )
break;
V_13 -> V_50 = V_51 ;
F_28 ( V_13 , V_37 ) ;
break;
case V_96 :
V_13 -> V_50 = V_97 ;
V_31 -> V_54 = 0 ;
break;
default:
F_31 ( V_61 L_3 ,
V_58 -> V_26 ) ;
V_69 = - V_60 ;
}
V_82:
F_41 ( V_2 ) ;
return ( V_69 == - V_91 ) ? V_98 : V_90 ;
V_68:
V_2 -> V_99 = NULL ;
F_42 ( V_2 , V_13 ) ;
V_69 = V_2 -> V_15 ;
F_43 ( V_68 , V_2 ) ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_100 ( V_13 , V_69 ) ;
return V_90 ;
}
static void F_44 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
F_45 ( & V_13 -> V_92 ) ;
F_45 ( & V_31 -> V_85 ) ;
}
static T_1 F_46 ( const T_1 * V_101 , unsigned V_102 )
{
unsigned V_103 ;
T_1 V_104 = V_105 ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
T_1 V_106 = V_101 [ V_103 ] ;
if ( V_106 > V_104 && V_106 < V_107 )
V_104 = V_106 ;
}
return V_104 ;
}
static int F_47 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 ;
T_1 V_66 ;
if ( ! F_48 ( V_2 , sizeof( * V_58 ) + 4 ) )
return - V_60 ;
V_58 = F_14 ( V_2 ) ;
if ( V_58 -> V_28 != V_44 )
return - V_108 ;
V_66 = V_58 -> V_6 [ 4 ] ;
while ( V_66 > 0 ) {
T_1 type , V_5 [ 6 ] , V_15 = sizeof( V_5 ) ;
const T_1 * V_6 = F_1 ( V_2 , & type , & V_15 , V_5 ) ;
if ( V_6 == NULL )
return - V_60 ;
switch ( type ) {
case V_39 :
if ( V_15 < 2 || V_15 < V_6 [ 0 ] )
break;
V_31 -> V_34 = F_46 ( V_6 + 2 , V_15 - 2 ) ;
break;
case V_43 :
if ( V_15 < 2 || V_15 < V_6 [ 0 ] )
break;
V_31 -> V_35 = F_46 ( V_6 + 2 , V_15 - 2 ) ;
break;
}
V_66 -- ;
}
return F_20 ( V_13 ) ;
}
static int F_49 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_18 * V_58 = F_14 ( V_2 ) ;
if ( V_58 -> V_28 != V_44 )
return - V_108 ;
return F_17 ( V_13 , V_95 , 0 ,
NULL , 0 , V_37 ) ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
if ( ! F_39 ( V_31 -> V_34 ) ) {
F_32 ( & V_31 -> V_64 , 1 ) ;
V_13 -> V_65 ( V_13 ) ;
}
F_28 ( V_13 , V_37 ) ;
}
static int F_51 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
int V_69 = V_90 ;
switch ( V_58 -> V_26 ) {
case V_88 :
F_4 ( V_2 , 1 ) ;
case V_89 :
F_4 ( V_2 , 3 ) ;
if ( ! F_39 ( V_31 -> V_35 ) ) {
V_69 = F_40 ( V_13 , V_2 ) ;
if ( ! V_69 )
return V_90 ;
V_69 = V_98 ;
break;
}
if ( V_31 -> V_54 == 0 ) {
F_38 ( & V_13 -> V_87 ) ;
V_69 = V_98 ;
break;
}
V_31 -> V_54 -- ;
V_2 -> V_99 = NULL ;
F_42 ( V_2 , V_13 ) ;
V_69 = V_2 -> V_15 ;
F_43 ( & V_13 -> V_92 , V_2 ) ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_100 ( V_13 , V_69 ) ;
return V_90 ;
case V_109 :
if ( V_13 -> V_50 != V_110 )
break;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_75 ( V_13 ) ;
if ( F_47 ( V_13 , V_2 ) ) {
V_13 -> V_50 = V_70 ;
break;
}
if ( V_31 -> V_80 == V_79 )
V_13 -> V_50 = V_97 ;
else {
V_13 -> V_50 = V_51 ;
F_50 ( V_13 ) ;
}
break;
case V_111 :
if ( V_13 -> V_50 != V_110 )
break;
if ( F_49 ( V_13 , V_2 ) ) {
V_13 -> V_50 = V_70 ;
break;
}
V_13 -> V_50 = V_51 ;
F_50 ( V_13 ) ;
break;
case V_112 :
break;
case V_48 :
F_30 ( V_13 , V_2 ) ;
break;
}
F_41 ( V_2 ) ;
return V_69 ;
}
static struct V_12 * F_52 ( const struct V_113 * V_114 ,
const struct V_22 * V_45 ,
T_1 V_27 )
{
struct V_115 * V_116 ;
struct V_12 * V_117 ;
T_3 V_118 = F_53 ( V_45 ) ;
F_54 (sknode, node, hlist) {
struct V_30 * V_119 = F_18 ( V_117 ) ;
if ( V_119 -> V_120 . V_121 != V_118 )
continue;
if ( V_119 -> V_27 != V_27 )
continue;
if ( V_117 -> V_50 == V_70 )
continue;
F_55 ( V_117 ) ;
return V_117 ;
}
return NULL ;
}
static int F_56 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_12 * V_117 ;
struct V_18 * V_58 ;
struct V_22 V_45 ;
T_1 V_27 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) ) )
goto V_122;
V_58 = F_14 ( V_2 ) ;
V_27 = V_58 -> V_27 ;
if ( V_27 == V_123 )
goto V_122;
F_57 ( V_2 , & V_45 ) ;
V_117 = F_52 ( & V_31 -> V_114 , & V_45 , V_27 ) ;
if ( V_117 )
return F_58 ( V_117 , V_2 , 1 ) ;
switch ( V_58 -> V_26 ) {
case V_71 :
if ( V_13 -> V_50 != V_124 || F_59 ( V_13 ) ) {
F_24 ( V_13 , V_2 , V_72 ,
V_37 ) ;
break;
}
F_60 ( & V_13 -> V_92 , V_2 ) ;
F_61 ( V_13 ) ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_100 ( V_13 , 0 ) ;
return V_90 ;
case V_73 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_84 :
F_26 ( V_13 , V_2 , V_123 , V_37 ) ;
break;
case V_77 :
case V_76 :
case V_83 :
break;
default:
if ( ( 1 << V_13 -> V_50 )
& ~ ( V_125 | V_126 | V_127 ) )
return F_51 ( V_13 , V_2 ) ;
}
V_122:
F_41 ( V_2 ) ;
return V_90 ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , NULL , 0 , V_32 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = V_128 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_38 ;
return F_16 ( V_13 , V_2 , NULL ) ;
}
static void F_63 ( struct V_12 * V_13 , long V_129 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_130 = 0 ;
F_55 ( V_13 ) ;
F_64 ( V_13 ) ;
F_65 ( V_13 ) ;
if ( ( 1 << V_13 -> V_50 ) & ( V_131 | V_132 ) ) {
if ( V_13 -> V_133 == F_35 )
F_62 ( V_13 ) ;
else
F_19 ( V_13 , V_73 , V_38 ,
NULL , 0 ) ;
}
V_13 -> V_50 = V_134 ;
V_130 = V_31 -> V_130 ;
V_31 -> V_130 = 0 ;
F_66 ( V_13 ) ;
if ( V_130 )
F_67 ( V_13 ) ;
F_68 ( V_13 ) ;
}
static struct V_12 * F_69 ( struct V_12 * V_13 , int V_135 , int * V_136 )
{
struct V_30 * V_31 = F_18 ( V_13 ) , * V_137 ;
struct V_12 * V_138 = NULL ;
struct V_1 * V_2 ;
struct V_18 * V_58 ;
struct V_22 V_45 , V_139 ;
int V_69 ;
T_3 V_140 ;
T_1 V_27 , V_141 , V_66 ;
T_1 V_142 = 0 ;
V_2 = F_70 ( V_13 , 0 , V_135 & V_143 , V_136 ) ;
if ( ! V_2 )
return NULL ;
F_65 ( V_13 ) ;
if ( V_13 -> V_50 != V_124 ) {
V_69 = - V_60 ;
goto V_122;
}
F_71 ( V_13 ) ;
V_69 = - V_144 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) + 4 ) )
goto V_122;
V_58 = F_14 ( V_2 ) ;
V_27 = V_58 -> V_27 ;
switch ( V_58 -> V_145 ) {
case V_79 :
V_141 = 0 ;
break;
case V_81 :
V_141 = 1 ;
break;
default:
F_24 ( V_13 , V_2 , V_146 ,
V_32 ) ;
goto V_122;
}
V_140 = V_58 -> V_147 << 8 ;
V_66 = V_58 -> V_6 [ 4 ] ;
while ( V_66 > 0 ) {
T_1 type , V_5 [ 1 ] , V_15 = sizeof( V_5 ) ;
const T_1 * V_6 = F_1 ( V_2 , & type , & V_15 , V_5 ) ;
if ( V_6 == NULL )
goto V_122;
switch ( type ) {
case V_148 :
if ( V_15 < 1 )
goto V_122;
V_140 = ( V_140 & 0xff00 ) | V_6 [ 0 ] ;
break;
case V_149 :
V_142 = V_6 [ 0 ] != 0 ;
break;
}
V_66 -- ;
}
V_138 = F_52 ( & V_31 -> V_114 , & V_45 , V_27 ) ;
if ( F_72 ( V_138 ) ) {
F_73 ( V_138 ) ;
V_138 = NULL ;
F_24 ( V_13 , V_2 , V_72 , V_32 ) ;
goto V_122;
}
V_138 = F_74 ( F_75 ( V_13 ) , V_150 , V_32 , V_13 -> V_151 ) ;
if ( ! V_138 ) {
F_24 ( V_13 , V_2 , V_152 , V_32 ) ;
V_69 = - V_91 ;
goto V_122;
}
F_76 ( NULL , V_138 ) ;
V_138 -> V_50 = V_97 ;
V_138 -> V_133 = F_35 ;
V_138 -> V_153 = V_13 -> V_153 ;
V_138 -> V_154 = F_44 ;
V_137 = F_18 ( V_138 ) ;
F_57 ( V_2 , & V_45 ) ;
F_15 ( V_2 , & V_139 ) ;
V_137 -> V_120 . V_121 = F_53 ( & V_45 ) ;
V_137 -> V_120 . V_155 = F_53 ( & V_139 ) ;
V_137 -> V_120 . V_156 = F_77 ( & V_45 ) ;
F_55 ( V_13 ) ;
V_137 -> V_157 = V_13 ;
F_78 ( & V_137 -> V_85 ) ;
V_137 -> V_27 = V_27 ;
F_32 ( & V_137 -> V_64 , 0 ) ;
V_137 -> V_130 = 0 ;
V_137 -> V_140 = V_140 ;
V_137 -> V_54 = 0 ;
V_137 -> V_35 = V_137 -> V_34 = V_42 ;
V_137 -> V_80 = V_141 ;
V_137 -> V_142 = V_142 ;
V_69 = F_22 ( V_138 , V_2 ) ;
if ( V_69 ) {
F_68 ( V_138 ) ;
V_138 = NULL ;
goto V_122;
}
F_79 ( V_138 , & V_31 -> V_114 ) ;
V_122:
F_66 ( V_13 ) ;
F_41 ( V_2 ) ;
* V_136 = V_69 ;
return V_138 ;
}
static int F_80 ( struct V_12 * V_13 , struct V_158 * V_159 , int V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_69 ;
T_1 V_6 [ 4 ] = { 0 , V_38 , V_38 , V_38 } ;
if ( V_31 -> V_27 == V_123 )
V_31 -> V_27 = 1 ;
V_69 = F_19 ( V_13 , V_71 ,
V_31 -> V_80 , V_6 , 4 ) ;
if ( V_69 ) {
V_31 -> V_27 = V_123 ;
return V_69 ;
}
V_13 -> V_50 = V_110 ;
return 0 ;
}
static int F_81 ( struct V_12 * V_13 , struct V_158 * V_159 , int V_15 )
{
int V_69 ;
V_69 = F_19 ( V_13 , V_76 , V_38 ,
NULL , 0 ) ;
if ( V_69 )
return V_69 ;
V_13 -> V_50 = V_110 ;
return 0 ;
}
static int F_82 ( struct V_12 * V_13 , int V_160 , unsigned long V_161 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_162 ;
int V_163 = - V_164 ;
switch ( V_160 ) {
case V_165 :
if ( V_13 -> V_50 == V_124 ) {
V_163 = - V_60 ;
break;
}
F_65 ( V_13 ) ;
if ( F_36 ( V_13 , V_166 ) &&
! F_83 ( & V_31 -> V_85 ) )
V_162 = F_84 ( & V_31 -> V_85 ) -> V_15 ;
else if ( ! F_83 ( & V_13 -> V_92 ) )
V_162 = F_84 ( & V_13 -> V_92 ) -> V_15 ;
else
V_162 = 0 ;
F_66 ( V_13 ) ;
V_163 = F_85 ( V_162 , ( int V_167 * ) V_161 ) ;
break;
case V_168 :
F_65 ( V_13 ) ;
if ( V_13 -> V_50 == V_110 )
V_163 = - V_169 ;
else if ( V_13 -> V_50 == V_51 )
V_163 = - V_170 ;
else
V_163 = F_81 ( V_13 , NULL , 0 ) ;
F_66 ( V_13 ) ;
break;
}
return V_163 ;
}
static int F_86 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
V_13 -> V_154 = F_44 ;
F_87 ( & V_31 -> V_114 ) ;
V_31 -> V_157 = NULL ;
F_78 ( & V_31 -> V_85 ) ;
F_32 ( & V_31 -> V_64 , 0 ) ;
V_31 -> V_130 = 0 ;
V_31 -> V_140 = 0 ;
V_31 -> V_27 = V_123 ;
V_31 -> V_54 = 0 ;
V_31 -> V_35 = V_31 -> V_34 = V_42 ;
V_31 -> V_80 = 1 ;
V_31 -> V_142 = 0 ;
return 0 ;
}
static int F_88 ( struct V_12 * V_13 , int V_171 , int V_172 ,
char V_167 * V_173 , unsigned int V_174 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_175 = 0 , V_69 = 0 ;
if ( V_171 != V_176 )
return - V_177 ;
if ( V_174 >= sizeof( int ) ) {
if ( F_89 ( V_175 , ( int V_167 * ) V_173 ) )
return - V_178 ;
}
F_65 ( V_13 ) ;
switch ( V_172 ) {
case V_179 :
if ( V_175 && V_175 != V_180 ) {
V_69 = - V_60 ;
break;
}
if ( ! V_31 -> V_130 == ! V_175 )
break;
if ( ! F_90 ( V_181 ) ) {
V_69 = - V_182 ;
break;
}
if ( V_175 ) {
F_66 ( V_13 ) ;
V_69 = F_91 ( V_13 ) ;
if ( V_69 > 0 ) {
V_31 -> V_130 = V_69 ;
V_69 = 0 ;
}
} else {
V_31 -> V_130 = 0 ;
F_66 ( V_13 ) ;
F_67 ( V_13 ) ;
V_69 = 0 ;
}
goto V_183;
case V_184 :
if ( ( V_13 -> V_50 == V_134 ) &&
( V_175 >= 0 ) && ( V_175 < V_123 ) )
V_31 -> V_27 = V_175 ;
else
V_69 = - V_60 ;
break;
case V_185 :
V_31 -> V_80 = ! ! V_175 ;
break;
default:
V_69 = - V_177 ;
}
F_66 ( V_13 ) ;
V_183:
return V_69 ;
}
static int F_92 ( struct V_12 * V_13 , int V_171 , int V_172 ,
char V_167 * V_173 , int V_167 * V_174 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_15 , V_175 ;
if ( V_171 != V_176 )
return - V_177 ;
if ( F_89 ( V_15 , V_174 ) )
return - V_178 ;
switch ( V_172 ) {
case V_179 :
V_175 = V_31 -> V_130 ? V_180 : V_186 ;
break;
case V_187 :
V_175 = V_31 -> V_130 ;
break;
case V_184 :
V_175 = V_31 -> V_27 ;
if ( V_175 == V_123 )
return - V_60 ;
break;
case V_185 :
V_175 = V_31 -> V_80 ;
break;
default:
return - V_177 ;
}
V_15 = F_93 (unsigned int, sizeof(int), len) ;
if ( F_85 ( V_15 , V_174 ) )
return - V_178 ;
if ( F_85 ( V_175 , ( int V_167 * ) V_173 ) )
return - V_178 ;
return 0 ;
}
static int F_94 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
int V_69 ;
if ( F_39 ( V_31 -> V_34 ) &&
! F_95 ( & V_31 -> V_64 , - 1 , 0 ) ) {
F_41 ( V_2 ) ;
return - V_91 ;
}
F_96 ( V_2 , 3 + V_31 -> V_142 ) ;
F_12 ( V_2 ) ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
if ( V_31 -> V_142 ) {
V_9 -> V_26 = V_88 ;
V_9 -> V_6 [ 0 ] = 0 ;
} else
V_9 -> V_26 = V_89 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_69 = F_16 ( V_13 , V_2 , NULL ) ;
if ( V_69 && F_39 ( V_31 -> V_34 ) )
F_38 ( & V_31 -> V_64 ) ;
return V_69 ;
}
static int F_97 ( struct V_188 * V_189 , struct V_12 * V_13 ,
struct V_190 * V_191 , T_4 V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_1 * V_2 ;
long V_192 ;
int V_135 = V_191 -> V_193 ;
int V_69 , V_194 ;
if ( V_15 > V_195 )
return - V_196 ;
if ( ( V_191 -> V_193 & ~ ( V_197 | V_198 | V_199 |
V_200 ) ) ||
! ( V_191 -> V_193 & V_198 ) )
return - V_62 ;
V_2 = F_98 ( V_13 , V_17 + V_15 ,
V_135 & V_197 , & V_69 ) ;
if ( ! V_2 )
return V_69 ;
F_8 ( V_2 , V_201 + 3 + V_31 -> V_142 ) ;
V_69 = F_99 ( F_100 ( V_2 , V_15 ) , V_191 -> V_202 , V_15 ) ;
if ( V_69 < 0 )
goto V_203;
F_65 ( V_13 ) ;
V_192 = F_101 ( V_13 , V_135 & V_197 ) ;
if ( ( 1 << V_13 -> V_50 ) & ( V_126 | V_125 ) ) {
V_69 = - V_204 ;
goto V_82;
}
if ( V_13 -> V_50 != V_51 ) {
V_205:
V_69 = F_102 ( V_13 , & V_192 ) ;
if ( V_69 )
goto V_82;
if ( V_13 -> V_50 == V_70 ) {
V_69 = - V_206 ;
goto V_82;
}
}
F_29 ( V_13 -> V_50 != V_51 ) ;
V_194 = F_103 ( & V_31 -> V_64 ) ;
while ( ! V_194 ) {
F_104 ( V_207 ) ;
if ( ! V_192 ) {
V_69 = - V_208 ;
goto V_82;
}
if ( F_105 ( V_209 ) ) {
V_69 = F_106 ( V_192 ) ;
goto V_82;
}
F_107 ( F_108 ( V_13 ) , & V_207 ,
V_210 ) ;
V_194 = F_109 ( V_13 , & V_192 , F_103 ( & V_31 -> V_64 ) ) ;
F_110 ( F_108 ( V_13 ) , & V_207 ) ;
if ( V_13 -> V_50 != V_51 )
goto V_205;
}
V_69 = F_94 ( V_13 , V_2 ) ;
if ( V_69 >= 0 )
V_69 = V_15 ;
V_2 = NULL ;
V_82:
F_66 ( V_13 ) ;
V_203:
F_41 ( V_2 ) ;
return V_69 ;
}
int F_111 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
return F_103 ( & V_31 -> V_64 ) ;
}
int F_112 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_1 * V_211 , * V_212 ;
int V_213 = 0 ;
if ( F_18 ( V_13 ) -> V_142 )
return F_94 ( V_13 , V_2 ) ;
V_211 = F_6 ( V_17 , V_37 ) ;
if ( ! V_211 ) {
F_41 ( V_2 ) ;
return - V_24 ;
}
F_113 ( V_211 ) -> V_214 = V_2 ;
V_211 -> V_15 += V_2 -> V_15 ;
V_211 -> V_215 += V_211 -> V_15 ;
V_211 -> V_216 += V_211 -> V_15 ;
F_114 (skb, fs)
V_213 += V_212 -> V_15 ;
V_2 -> V_217 = F_113 ( V_2 ) -> V_214 ;
F_115 ( V_2 ) ;
V_2 -> V_15 -= V_213 ;
V_2 -> V_215 -= V_213 ;
V_2 -> V_216 -= V_213 ;
F_8 ( V_211 , V_201 + 3 ) ;
return F_94 ( V_13 , V_211 ) ;
}
struct V_1 * F_116 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_117 ( & V_13 -> V_92 ) ;
if ( V_13 -> V_50 == V_51 )
F_28 ( V_13 , V_37 ) ;
return V_2 ;
}
static int F_118 ( struct V_188 * V_189 , struct V_12 * V_13 ,
struct V_190 * V_191 , T_4 V_15 , int V_218 ,
int V_135 , int * V_219 )
{
struct V_1 * V_2 ;
int V_69 ;
if ( V_135 & ~ ( V_220 | V_221 | V_222 | V_197 | V_223 |
V_199 | V_200 ) )
return - V_62 ;
if ( F_72 ( 1 << V_13 -> V_50 & ( V_126 | V_125 ) ) )
return - V_204 ;
if ( ( V_135 & V_220 ) || F_36 ( V_13 , V_166 ) ) {
struct V_30 * V_31 = F_18 ( V_13 ) ;
if ( V_135 & V_221 )
return - V_62 ;
V_2 = F_117 ( & V_31 -> V_85 ) ;
if ( V_2 ) {
F_26 ( V_13 , V_2 , V_44 ,
V_32 ) ;
V_191 -> V_193 |= V_220 ;
goto V_224;
}
if ( V_135 & V_220 )
return - V_60 ;
}
V_2 = F_70 ( V_13 , V_135 , V_218 , & V_69 ) ;
F_65 ( V_13 ) ;
if ( V_2 == NULL ) {
if ( V_69 == - V_204 && V_13 -> V_50 == V_70 )
V_69 = - V_206 ;
F_66 ( V_13 ) ;
return V_69 ;
}
if ( V_13 -> V_50 == V_51 )
F_28 ( V_13 , V_32 ) ;
F_66 ( V_13 ) ;
V_224:
V_191 -> V_193 |= V_198 ;
if ( V_2 -> V_15 > V_15 )
V_191 -> V_193 |= V_222 ;
else
V_15 = V_2 -> V_15 ;
V_69 = F_119 ( V_2 , 0 , V_191 -> V_202 , V_15 ) ;
if ( ! V_69 )
V_69 = ( V_135 & V_222 ) ? V_2 -> V_15 : V_15 ;
F_120 ( V_13 , V_2 ) ;
return V_69 ;
}
static void F_121 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_12 * V_225 = NULL ;
F_65 ( V_13 ) ;
if ( V_31 -> V_157 != NULL ) {
V_225 = V_31 -> V_157 ;
V_31 -> V_157 = NULL ;
F_66 ( V_13 ) ;
V_31 = F_18 ( V_225 ) ;
F_65 ( V_225 ) ;
F_122 ( V_13 ) ;
V_13 = V_225 ;
}
if ( F_123 ( & V_31 -> V_114 ) )
F_124 ( & V_31 -> V_120 . V_13 ) ;
F_66 ( V_13 ) ;
if ( V_225 )
F_68 ( V_225 ) ;
}
static int T_5 F_125 ( void )
{
return F_126 ( V_226 , & V_227 ) ;
}
static void T_6 F_127 ( void )
{
F_128 ( V_226 , & V_227 ) ;
}
