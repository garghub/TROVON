static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 , * V_7 ;
if ( ! V_4 )
return;
F_2 (node, n, &spec->nid_list, list) {
if ( V_6 -> V_8 != V_6 -> V_9 )
F_3 ( V_6 -> V_8 ) ;
F_3 ( V_6 ) ;
}
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_10 )
{
struct V_5 * V_6 ;
int V_11 ;
T_1 V_8 [ V_12 ] ;
V_6 = F_5 ( sizeof( * V_6 ) , V_13 ) ;
if ( V_6 == NULL )
return - V_14 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_15 = F_6 ( V_2 , V_10 ) ;
V_6 -> type = F_7 ( V_6 -> V_15 ) ;
if ( V_6 -> V_15 & V_16 ) {
V_11 = F_8 ( V_2 , V_10 , V_8 ,
V_12 ) ;
if ( V_11 < 0 ) {
F_3 ( V_6 ) ;
return V_11 ;
}
} else {
V_11 = 0 ;
}
if ( V_11 <= F_9 ( V_6 -> V_9 ) )
V_6 -> V_8 = V_6 -> V_9 ;
else {
V_6 -> V_8 = F_10 ( sizeof( T_1 ) * V_11 ,
V_13 ) ;
if ( ! V_6 -> V_8 ) {
F_11 ( V_17 L_1 ) ;
F_3 ( V_6 ) ;
return - V_14 ;
}
}
memcpy ( V_6 -> V_8 , V_8 , V_11 * sizeof( T_1 ) ) ;
V_6 -> V_11 = V_11 ;
if ( V_6 -> type == V_18 ) {
V_6 -> V_19 = F_12 ( V_2 , V_6 -> V_10 ) ;
V_6 -> V_20 = F_13 ( V_2 , V_6 -> V_10 , 0 , V_21 , 0 ) ;
V_6 -> V_22 = F_14 ( V_2 , V_6 -> V_10 ) ;
}
if ( V_6 -> V_15 & V_23 ) {
if ( V_6 -> V_15 & V_24 )
V_6 -> V_25 = F_15 ( V_2 , V_6 -> V_10 , V_26 ) ;
if ( ! V_6 -> V_25 )
V_6 -> V_25 = V_4 -> V_27 ;
}
if ( V_6 -> V_15 & V_28 ) {
if ( V_6 -> V_15 & V_24 )
V_6 -> V_29 = F_15 ( V_2 , V_6 -> V_10 , V_30 ) ;
if ( ! V_6 -> V_29 )
V_6 -> V_29 = V_4 -> V_31 ;
}
F_16 ( & V_6 -> V_32 , & V_4 -> V_33 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_34 , V_35 , V_36 ;
T_1 V_10 ;
if ( F_18 ( ! V_4 ) )
return - V_37 ;
V_4 -> V_27 = F_15 ( V_2 , V_2 -> V_38 , V_26 ) ;
V_4 -> V_31 = F_15 ( V_2 , V_2 -> V_38 , V_30 ) ;
V_35 = F_19 ( V_2 , V_2 -> V_38 , & V_10 ) ;
if ( ! V_10 || V_35 < 0 ) {
F_20 ( V_17 L_2 ) ;
return - V_37 ;
}
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ , V_10 ++ ) {
if ( ( V_36 = F_4 ( V_2 , V_4 , V_10 ) ) < 0 )
return V_36 ;
}
return 0 ;
}
static struct V_5 * F_21 ( struct V_3 * V_4 , T_1 V_10 )
{
struct V_5 * V_6 ;
F_22 (node, &spec->nid_list, list) {
if ( V_6 -> V_10 == V_10 )
return V_6 ;
}
return NULL ;
}
static int F_23 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned int V_39 , V_40 ;
F_24 ( L_3 , V_6 -> V_10 ) ;
V_39 = ( V_6 -> V_25 & V_41 ) >> V_42 ;
V_40 = ( V_6 -> V_25 & V_43 ) >> V_44 ;
if ( V_39 >= V_40 )
V_39 -= V_40 ;
F_25 ( V_2 , V_6 -> V_10 , V_45 , 0 , 0xff , V_39 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_5 * V_6 , unsigned int V_46 )
{
unsigned int V_39 , V_40 ;
F_24 ( L_4 , V_6 -> V_10 , V_46 ) ;
V_39 = ( V_6 -> V_29 & V_41 ) >> V_42 ;
V_40 = ( V_6 -> V_29 & V_43 ) >> V_44 ;
if ( V_39 >= V_40 )
V_39 -= V_40 ;
F_25 ( V_2 , V_6 -> V_10 , V_47 , V_46 , 0xff , V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned int V_46 )
{
F_24 ( L_5 , V_6 -> V_10 , V_46 ) ;
return F_28 ( V_2 , V_6 -> V_10 , 0 ,
V_48 , V_46 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_22 (node, &spec->nid_list, list) {
V_6 -> V_49 = 0 ;
}
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_50 )
{
int V_34 , V_36 ;
struct V_5 * V_51 ;
if ( V_6 -> V_49 )
return 0 ;
V_6 -> V_49 = 1 ;
if ( V_6 -> type == V_52 ) {
if ( V_6 -> V_15 & V_53 ) {
F_24 ( L_6 , V_6 -> V_10 ) ;
return 0 ;
}
F_24 ( L_7 , V_6 -> V_10 ) ;
if ( V_4 -> V_54 [ V_50 ] ) {
return V_6 == V_4 -> V_54 [ V_50 ] ;
}
V_4 -> V_54 [ V_50 ] = V_6 ;
if ( ( V_6 -> V_15 & V_23 ) &&
V_4 -> V_55 < V_56 ) {
V_4 -> V_57 [ V_4 -> V_55 ] . V_6 = V_6 ;
V_4 -> V_57 [ V_4 -> V_55 ] . V_46 = 0 ;
V_4 -> V_55 ++ ;
}
return 1 ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_11 ; V_34 ++ ) {
V_51 = F_21 ( V_4 , V_6 -> V_8 [ V_34 ] ) ;
if ( ! V_51 )
continue;
V_36 = F_30 ( V_2 , V_4 , V_51 , V_50 ) ;
if ( V_36 < 0 )
return V_36 ;
else if ( V_36 > 0 ) {
if ( V_6 -> V_11 > 1 )
F_27 ( V_2 , V_6 , V_34 ) ;
F_26 ( V_2 , V_6 , V_34 ) ;
F_23 ( V_2 , V_6 ) ;
if ( V_4 -> V_54 [ V_50 ] &&
V_4 -> V_55 < V_56 &&
! ( V_4 -> V_54 [ V_50 ] -> V_15 &
V_23 ) ) {
if ( ( V_6 -> V_15 & V_28 ) ||
( V_6 -> V_15 & V_23 ) ) {
int V_7 = V_4 -> V_55 ;
V_4 -> V_57 [ V_7 ] . V_6 = V_6 ;
V_4 -> V_57 [ V_7 ] . V_46 = V_34 ;
V_4 -> V_55 ++ ;
}
}
return 1 ;
}
}
return 0 ;
}
static struct V_5 * F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_58 )
{
struct V_5 * V_6 ;
int V_36 ;
F_22 (node, &spec->nid_list, list) {
if ( V_6 -> type != V_18 )
continue;
if ( ! ( V_6 -> V_19 & V_59 ) )
continue;
if ( F_32 ( V_6 ) == V_60 )
continue;
if ( V_58 >= 0 ) {
if ( V_58 != F_33 ( V_6 ) )
continue;
if ( V_6 -> V_15 & V_53 )
continue;
} else {
if ( ! ( V_6 -> V_20 & V_61 ) )
continue;
}
F_29 ( V_4 ) ;
V_36 = F_30 ( V_2 , V_4 , V_6 , 0 ) ;
if ( V_36 < 0 )
return NULL ;
if ( ! V_36 && V_4 -> V_62 [ 0 ] ) {
V_36 = F_30 ( V_2 , V_4 , V_6 , 1 ) ;
if ( V_36 < 0 )
return NULL ;
}
if ( V_36 > 0 ) {
F_23 ( V_2 , V_6 ) ;
F_28 ( V_2 , V_6 -> V_10 , 0 ,
V_63 ,
V_61 |
( ( V_6 -> V_19 & V_64 ) ?
V_65 : 0 ) ) ;
return V_6 ;
}
}
return NULL ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
V_6 = F_31 ( V_2 , V_4 , V_66 ) ;
if ( V_6 )
V_4 -> V_62 [ 0 ] = V_6 ;
else {
V_6 = F_31 ( V_2 , V_4 , V_67 ) ;
if ( V_6 )
V_4 -> V_62 [ 0 ] = V_6 ;
}
V_6 = F_31 ( V_2 , V_4 , V_68 ) ;
if ( V_6 ) {
if ( ! V_4 -> V_62 [ 0 ] )
V_4 -> V_62 [ 0 ] = V_6 ;
else
V_4 -> V_62 [ 1 ] = V_6 ;
}
if ( ! V_4 -> V_62 [ 0 ] ) {
V_4 -> V_62 [ 0 ] = F_31 ( V_2 , V_4 , - 1 ) ;
if ( ! V_4 -> V_62 [ 0 ] )
F_35 ( L_8 ) ;
}
return 0 ;
}
static int F_36 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_1 * V_2 = F_37 ( V_70 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_38 ( & V_4 -> V_73 , V_72 ) ;
}
static int F_39 ( struct V_69 * V_70 , struct V_74 * V_75 )
{
struct V_1 * V_2 = F_37 ( V_70 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_75 -> V_76 . V_77 . V_78 [ 0 ] = V_4 -> V_79 ;
return 0 ;
}
static int F_40 ( struct V_69 * V_70 , struct V_74 * V_75 )
{
struct V_1 * V_2 = F_37 ( V_70 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_41 ( V_2 , & V_4 -> V_73 , V_75 ,
V_4 -> V_80 -> V_10 , & V_4 -> V_79 ) ;
}
static const char * F_42 ( struct V_5 * V_6 , unsigned int * V_81 )
{
unsigned int V_82 = F_43 ( V_6 ) ;
switch ( F_33 ( V_6 ) ) {
case V_83 :
if ( ( V_82 & 0x0f ) == V_84 )
return L_9 ;
return L_10 ;
case V_85 :
#if 0
if (pinctl)
*pinctl |= AC_PINCTL_VREF_GRD;
#endif
return L_11 ;
case V_86 :
if ( ( V_82 & 0x0f ) == V_84 )
return L_12 ;
return L_13 ;
case V_87 :
if ( V_81 &&
( V_6 -> V_19 &
( V_88 << V_89 ) ) )
* V_81 |= V_90 ;
if ( ( V_82 & 0x0f ) == V_84 )
return L_14 ;
return L_15 ;
case V_91 :
return L_16 ;
case V_92 :
return L_17 ;
}
return NULL ;
}
static int F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_93 )
{
int V_34 , V_36 ;
unsigned int V_81 ;
const char * type ;
if ( V_6 -> V_49 )
return 0 ;
V_6 -> V_49 = 1 ;
if ( V_6 -> type != V_18 ) {
for ( V_34 = 0 ; V_34 < V_6 -> V_11 ; V_34 ++ ) {
struct V_5 * V_51 ;
V_51 = F_21 ( V_4 , V_6 -> V_8 [ V_34 ] ) ;
if ( ! V_51 )
continue;
V_36 = F_44 ( V_2 , V_4 , V_51 , V_93 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_36 > 0 ) {
if ( V_6 -> V_11 > 1 )
F_27 ( V_2 , V_6 , V_34 ) ;
F_26 ( V_2 , V_6 , V_34 ) ;
F_23 ( V_2 , V_6 ) ;
return V_36 ;
}
}
return 0 ;
}
if ( ! ( V_6 -> V_19 & V_94 ) )
return 0 ;
if ( F_32 ( V_6 ) == V_60 )
return 0 ;
if ( V_6 -> V_15 & V_53 )
return 0 ;
if ( V_4 -> V_73 . V_95 >= V_96 ) {
F_11 ( V_17 L_18 ) ;
return - V_37 ;
}
V_81 = V_97 ;
type = F_42 ( V_6 , & V_81 ) ;
if ( ! type ) {
if ( ! ( V_6 -> V_20 & V_97 ) )
return 0 ;
type = L_19 ;
}
F_45 ( & V_4 -> V_73 , type , V_93 , NULL ) ;
F_26 ( V_2 , V_6 , 0 ) ;
F_28 ( V_2 , V_6 -> V_10 , 0 ,
V_63 , V_81 ) ;
return 1 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_5 * V_80 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_34 , V_36 ;
F_24 ( L_20 , V_80 -> V_10 ) ;
F_29 ( V_4 ) ;
F_26 ( V_2 , V_80 , 0 ) ;
for ( V_34 = 0 ; V_34 < V_80 -> V_11 ; V_34 ++ ) {
V_6 = F_21 ( V_4 , V_80 -> V_8 [ V_34 ] ) ;
if ( V_6 && V_6 -> type == V_18 ) {
V_36 = F_44 ( V_2 , V_4 , V_6 , V_34 ) ;
if ( V_36 < 0 )
return V_36 ;
}
}
for ( V_34 = 0 ; V_34 < V_80 -> V_11 ; V_34 ++ ) {
V_6 = F_21 ( V_4 , V_80 -> V_8 [ V_34 ] ) ;
if ( V_6 && V_6 -> type != V_18 ) {
V_36 = F_44 ( V_2 , V_4 , V_6 , V_34 ) ;
if ( V_36 < 0 )
return V_36 ;
}
}
if ( ! V_4 -> V_73 . V_95 )
return 0 ;
F_24 ( L_21 , V_80 -> V_10 , V_4 -> V_73 . V_95 ) ;
for ( V_34 = 0 ; V_34 < V_4 -> V_73 . V_95 ; V_34 ++ )
F_24 ( L_22 , V_4 -> V_73 . V_98 [ V_34 ] . V_99 ,
V_4 -> V_73 . V_98 [ V_34 ] . V_46 ) ;
V_4 -> V_80 = V_80 ;
return 1 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_36 ;
F_22 (node, &spec->nid_list, list) {
if ( V_6 -> V_15 & V_53 )
continue;
if ( V_6 -> type == V_100 ) {
V_36 = F_46 ( V_2 , V_6 ) ;
if ( V_36 < 0 )
return V_36 ;
else if ( V_36 > 0 )
return 0 ;
}
}
F_35 ( L_23 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 , T_1 V_10 ,
int V_101 , int V_93 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_102 * V_103 ;
if ( V_4 -> V_104 >= V_105 ) {
F_11 ( V_17 L_24 ) ;
return;
}
V_103 = & V_4 -> V_106 [ V_4 -> V_104 ++ ] ;
V_103 -> V_10 = V_10 ;
V_103 -> V_101 = V_101 ;
V_103 -> V_93 = V_93 ;
V_4 -> V_107 . V_108 = V_4 -> V_106 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned int V_46 , const char * type ,
const char * V_109 , int V_110 )
{
char V_111 [ 32 ] ;
int V_36 ;
int V_112 = 0 ;
struct V_113 V_114 ;
if ( type )
sprintf ( V_111 , L_25 , type , V_109 ) ;
else
sprintf ( V_111 , L_26 , V_109 ) ;
if ( ( V_6 -> V_15 & V_28 ) &&
( V_6 -> V_29 & V_115 ) ) {
V_114 = (struct V_113 ) F_50 ( V_111 , V_6 -> V_10 , V_46 , V_47 ) ;
if ( V_110 )
F_48 ( V_2 , V_6 -> V_10 , V_47 , V_46 ) ;
F_24 ( L_27 , V_111 , V_6 -> V_10 , V_46 ) ;
V_36 = F_51 ( V_2 , V_6 -> V_10 ,
F_52 ( & V_114 , V_2 ) ) ;
if ( V_36 < 0 )
return V_36 ;
V_112 = 1 ;
} else if ( ( V_6 -> V_15 & V_23 ) &&
( V_6 -> V_25 & V_115 ) ) {
V_114 = (struct V_113 ) F_50 ( V_111 , V_6 -> V_10 , 0 , V_45 ) ;
if ( V_110 )
F_48 ( V_2 , V_6 -> V_10 , V_45 , 0 ) ;
F_24 ( L_28 , V_111 , V_6 -> V_10 ) ;
V_36 = F_51 ( V_2 , V_6 -> V_10 ,
F_52 ( & V_114 , V_2 ) ) ;
if ( V_36 < 0 )
return V_36 ;
V_112 = 1 ;
}
if ( type )
sprintf ( V_111 , L_29 , type , V_109 ) ;
else
sprintf ( V_111 , L_30 , V_109 ) ;
if ( ( V_6 -> V_15 & V_28 ) &&
( V_6 -> V_29 & V_41 ) ) {
V_114 = (struct V_113 ) F_53 ( V_111 , V_6 -> V_10 , V_46 , V_47 ) ;
F_24 ( L_27 , V_111 , V_6 -> V_10 , V_46 ) ;
V_36 = F_51 ( V_2 , V_6 -> V_10 ,
F_52 ( & V_114 , V_2 ) ) ;
if ( V_36 < 0 )
return V_36 ;
V_112 = 1 ;
} else if ( ( V_6 -> V_15 & V_23 ) &&
( V_6 -> V_25 & V_41 ) ) {
V_114 = (struct V_113 ) F_53 ( V_111 , V_6 -> V_10 , 0 , V_45 ) ;
F_24 ( L_28 , V_111 , V_6 -> V_10 ) ;
V_36 = F_51 ( V_2 , V_6 -> V_10 ,
F_52 ( & V_114 , V_2 ) ) ;
if ( V_36 < 0 )
return V_36 ;
V_112 = 1 ;
}
return V_112 ;
}
static int F_54 ( struct V_1 * V_2 , const char * type , const char * V_101 )
{
struct V_116 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
sprintf ( V_117 . V_111 , L_29 , type , V_101 ) ;
V_117 . V_118 = V_119 ;
if ( F_55 ( V_2 -> V_120 -> V_121 , & V_117 ) )
return 1 ;
sprintf ( V_117 . V_111 , L_25 , type , V_101 ) ;
V_117 . V_118 = V_119 ;
if ( F_55 ( V_2 -> V_120 -> V_121 , & V_117 ) )
return 1 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
const char * const * V_122 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_34 , V_36 ;
for ( V_34 = 0 ; V_34 < V_4 -> V_55 ; V_34 ++ ) {
V_36 = F_49 ( V_2 , V_4 -> V_57 [ V_34 ] . V_6 ,
V_4 -> V_57 [ V_34 ] . V_46 ,
V_122 [ V_34 ] , L_31 , 0 ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
static const char * const V_123 [] = { L_32 , L_33 } ;
static const char * const V_124 [] = { L_34 , L_33 } ;
switch ( V_4 -> V_55 ) {
case 1 :
return F_49 ( V_2 , V_4 -> V_57 [ 0 ] . V_6 ,
V_4 -> V_57 [ 0 ] . V_46 ,
L_35 , L_31 , 0 ) ;
case 2 :
if ( F_33 ( V_4 -> V_62 [ 0 ] ) == V_67 )
return F_56 ( V_2 , V_123 ) ;
else
return F_56 ( V_2 , V_124 ) ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_80 = V_4 -> V_80 ;
int V_34 , V_36 ;
static struct V_113 V_125 = {
. V_118 = V_119 ,
. V_111 = L_36 ,
. V_126 = F_36 ,
. V_127 = F_39 ,
. V_128 = F_40 ,
} ;
if ( ! V_80 || ! V_4 -> V_73 . V_95 )
return 0 ;
V_4 -> V_79 = 0 ;
F_27 ( V_2 , V_80 ,
V_4 -> V_73 . V_98 [ 0 ] . V_46 ) ;
if ( V_4 -> V_73 . V_95 == 1 ) {
V_36 = F_49 ( V_2 , V_80 ,
V_4 -> V_73 . V_98 [ 0 ] . V_46 ,
NULL , L_37 , 0 ) ;
if ( V_36 < 0 )
return V_36 ;
return 0 ;
}
V_36 = F_51 ( V_2 , V_4 -> V_80 -> V_10 ,
F_52 ( & V_125 , V_2 ) ) ;
if ( V_36 < 0 )
return V_36 ;
if ( ! ( V_80 -> V_15 & V_28 ) ||
! ( V_80 -> V_29 & V_41 ) )
return 0 ;
for ( V_34 = 0 ; V_34 < V_4 -> V_73 . V_95 ; V_34 ++ ) {
struct V_113 V_114 ;
char V_111 [ 32 ] ;
sprintf ( V_111 , L_38 ,
V_4 -> V_73 . V_98 [ V_34 ] . V_99 ) ;
V_114 = (struct V_113 )
F_53 ( V_111 , V_80 -> V_10 ,
V_4 -> V_73 . V_98 [ V_34 ] . V_46 ,
V_47 ) ;
V_36 = F_51 ( V_2 , V_80 -> V_10 ,
F_52 ( & V_114 , V_2 ) ) ;
if ( V_36 < 0 )
return V_36 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_5 * V_129 ,
const char * type )
{
int V_34 , V_36 ;
if ( V_6 -> V_49 )
return 0 ;
V_6 -> V_49 = 1 ;
if ( V_6 == V_129 ) {
return 1 ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_11 ; V_34 ++ ) {
struct V_5 * V_51 = F_21 ( V_4 , V_6 -> V_8 [ V_34 ] ) ;
if ( ! V_51 )
continue;
V_36 = F_59 ( V_2 , V_4 , V_51 , V_129 , type ) ;
if ( V_36 < 0 )
return V_36 ;
else if ( V_36 >= 1 ) {
if ( V_36 == 1 ) {
V_36 = F_49 ( V_2 , V_6 , V_34 , type ,
L_31 , 1 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_36 > 0 )
return 2 ;
V_36 = 1 ;
}
if ( V_6 -> V_11 > 1 )
F_27 ( V_2 , V_6 , V_34 ) ;
F_26 ( V_2 , V_6 , V_34 ) ;
F_23 ( V_2 , V_6 ) ;
return V_36 ;
}
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_36 ;
const char * type ;
if ( ! V_4 -> V_62 [ 0 ] )
return 0 ;
F_22 (node, &spec->nid_list, list) {
if ( V_6 -> type != V_18 )
continue;
if ( ! ( V_6 -> V_19 & V_94 ) )
return 0 ;
type = F_42 ( V_6 , NULL ) ;
if ( type ) {
if ( F_54 ( V_2 , type , L_31 ) )
continue;
F_29 ( V_4 ) ;
V_36 = F_59 ( V_2 , V_4 ,
V_4 -> V_62 [ 0 ] ,
V_6 , type ) ;
if ( V_36 < 0 )
return V_36 ;
if ( ! V_36 )
continue;
}
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_36 ;
if ( ( V_36 = F_58 ( V_2 ) ) < 0 ||
( V_36 = F_57 ( V_2 ) ) < 0 ||
( V_36 = F_60 ( V_2 ) ) < 0 )
return V_36 ;
return 0 ;
}
static int F_62 ( struct V_130 * V_131 ,
struct V_1 * V_2 ,
unsigned int V_132 ,
unsigned int V_133 ,
struct V_134 * V_135 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_63 ( V_2 , V_131 -> V_10 , V_132 , 0 , V_133 ) ;
F_63 ( V_2 , V_4 -> V_54 [ 1 ] -> V_10 ,
V_132 , 0 , V_133 ) ;
return 0 ;
}
static int F_64 ( struct V_130 * V_131 ,
struct V_1 * V_2 ,
struct V_134 * V_135 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_65 ( V_2 , V_131 -> V_10 ) ;
F_65 ( V_2 , V_4 -> V_54 [ 1 ] -> V_10 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_136 * V_126 = & V_4 -> V_137 ;
if ( ! V_4 -> V_54 [ 0 ] && ! V_4 -> V_80 ) {
F_35 ( L_39 ) ;
return 0 ;
}
V_2 -> V_138 = 1 ;
V_2 -> V_139 = V_126 ;
V_126 -> V_111 = L_40 ;
if ( V_4 -> V_54 [ 0 ] ) {
V_126 -> V_140 [ 0 ] = V_141 ;
V_126 -> V_140 [ 0 ] . V_10 = V_4 -> V_54 [ 0 ] -> V_10 ;
if ( V_4 -> V_54 [ 1 ] ) {
V_126 -> V_140 [ 0 ] . V_142 . V_143 = F_62 ;
V_126 -> V_140 [ 0 ] . V_142 . V_144 = F_64 ;
}
}
if ( V_4 -> V_80 ) {
V_126 -> V_140 [ 1 ] = V_141 ;
V_126 -> V_140 [ 1 ] . V_10 = V_4 -> V_80 -> V_10 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_68 ( V_2 , & V_4 -> V_107 , V_10 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_36 ;
if( ! V_2 -> V_38 )
return 0 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_13 ) ;
if ( V_4 == NULL ) {
F_20 ( V_17 L_41 ) ;
return - V_14 ;
}
V_2 -> V_4 = V_4 ;
F_70 ( & V_4 -> V_33 ) ;
if ( ( V_36 = F_17 ( V_2 ) ) < 0 )
goto error;
if ( ( V_36 = F_47 ( V_2 ) ) < 0 ||
( V_36 = F_34 ( V_2 ) ) < 0 )
goto error;
V_2 -> V_145 = V_146 ;
return 0 ;
error:
F_1 ( V_2 ) ;
return V_36 ;
}
