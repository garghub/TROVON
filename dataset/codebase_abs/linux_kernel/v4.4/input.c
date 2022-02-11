static inline int F_1 ( unsigned int V_1 ,
unsigned long * V_2 , unsigned int V_3 )
{
return V_1 <= V_3 && F_2 ( V_1 , V_2 ) ;
}
static int F_3 ( int V_4 , int V_5 , int V_6 )
{
if ( V_6 ) {
if ( V_4 > V_5 - V_6 / 2 && V_4 < V_5 + V_6 / 2 )
return V_5 ;
if ( V_4 > V_5 - V_6 && V_4 < V_5 + V_6 )
return ( V_5 * 3 + V_4 ) / 4 ;
if ( V_4 > V_5 - V_6 * 2 && V_4 < V_5 + V_6 * 2 )
return ( V_5 + V_4 ) / 2 ;
}
return V_4 ;
}
static void F_4 ( struct V_7 * V_8 , int V_1 )
{
if ( F_2 ( V_9 , V_8 -> V_10 ) &&
V_8 -> V_11 [ V_12 ] && V_8 -> V_11 [ V_13 ] &&
V_8 -> V_14 . V_15 ) {
V_8 -> V_16 = V_1 ;
F_5 ( & V_8 -> V_14 ,
V_17 + F_6 ( V_8 -> V_11 [ V_13 ] ) ) ;
}
}
static void F_7 ( struct V_7 * V_8 )
{
F_8 ( & V_8 -> V_14 ) ;
}
static unsigned int F_9 ( struct V_18 * V_19 ,
struct V_20 * V_21 , unsigned int V_22 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_20 * V_25 = V_21 ;
struct V_20 * V_26 ;
if ( V_24 -> V_27 ) {
for ( V_26 = V_21 ; V_26 != V_21 + V_22 ; V_26 ++ ) {
if ( V_24 -> V_27 ( V_19 , V_26 -> type , V_26 -> V_1 , V_26 -> V_4 ) )
continue;
if ( V_25 != V_26 )
* V_25 = * V_26 ;
V_25 ++ ;
}
V_22 = V_25 - V_21 ;
}
if ( ! V_22 )
return 0 ;
if ( V_24 -> V_28 )
V_24 -> V_28 ( V_19 , V_21 , V_22 ) ;
else if ( V_24 -> V_29 )
for ( V_26 = V_21 ; V_26 != V_21 + V_22 ; V_26 ++ )
V_24 -> V_29 ( V_19 , V_26 -> type , V_26 -> V_1 , V_26 -> V_4 ) ;
return V_22 ;
}
static void F_10 ( struct V_7 * V_8 ,
struct V_20 * V_21 , unsigned int V_22 )
{
struct V_18 * V_19 ;
struct V_20 * V_26 ;
if ( ! V_22 )
return;
F_11 () ;
V_19 = F_12 ( V_8 -> V_30 ) ;
if ( V_19 ) {
V_22 = F_9 ( V_19 , V_21 , V_22 ) ;
} else {
F_13 (handle, &dev->h_list, d_node)
if ( V_19 -> V_31 ) {
V_22 = F_9 ( V_19 , V_21 , V_22 ) ;
if ( ! V_22 )
break;
}
}
F_14 () ;
F_15 ( V_21 -> type , V_21 -> V_1 , V_21 -> V_4 ) ;
if ( F_2 ( V_9 , V_8 -> V_10 ) && F_2 ( V_32 , V_8 -> V_10 ) ) {
for ( V_26 = V_21 ; V_26 != V_21 + V_22 ; V_26 ++ ) {
if ( V_26 -> type == V_32 && V_26 -> V_4 != 2 ) {
if ( V_26 -> V_4 )
F_4 ( V_8 , V_26 -> V_1 ) ;
else
F_7 ( V_8 ) ;
}
}
}
}
static void F_16 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
struct V_20 V_21 [] = { { type , V_1 , V_4 } } ;
F_10 ( V_8 , V_21 , F_17 ( V_21 ) ) ;
}
static void F_18 ( unsigned long V_15 )
{
struct V_7 * V_8 = ( void * ) V_15 ;
unsigned long V_33 ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
if ( F_2 ( V_8 -> V_16 , V_8 -> V_35 ) &&
F_1 ( V_8 -> V_16 , V_8 -> V_36 , V_37 ) ) {
struct V_20 V_21 [] = {
{ V_32 , V_8 -> V_16 , 2 } ,
V_38
} ;
F_10 ( V_8 , V_21 , F_17 ( V_21 ) ) ;
if ( V_8 -> V_11 [ V_12 ] )
F_5 ( & V_8 -> V_14 , V_17 +
F_6 ( V_8 -> V_11 [ V_12 ] ) ) ;
}
F_20 ( & V_8 -> V_34 , V_33 ) ;
}
static int F_21 ( struct V_7 * V_8 ,
unsigned int V_1 , int * V_39 )
{
struct V_40 * V_41 = V_8 -> V_41 ;
bool V_42 ;
int * V_43 ;
if ( V_1 == V_44 ) {
if ( V_41 && * V_39 >= 0 && * V_39 < V_41 -> V_45 )
V_41 -> V_46 = * V_39 ;
return V_47 ;
}
V_42 = F_22 ( V_1 ) ;
if ( ! V_42 ) {
V_43 = & V_8 -> V_48 [ V_1 ] . V_4 ;
} else if ( V_41 ) {
V_43 = & V_41 -> V_49 [ V_41 -> V_46 ] . abs [ V_1 - V_50 ] ;
} else {
V_43 = NULL ;
}
if ( V_43 ) {
* V_39 = F_3 ( * V_39 , * V_43 ,
V_8 -> V_48 [ V_1 ] . V_6 ) ;
if ( * V_43 == * V_39 )
return V_47 ;
* V_43 = * V_39 ;
}
if ( V_42 && V_41 && V_41 -> V_46 != F_23 ( V_8 , V_44 ) ) {
F_24 ( V_8 , V_44 , V_41 -> V_46 ) ;
return V_51 | V_52 ;
}
return V_51 ;
}
static int F_25 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int * V_39 )
{
int V_53 = V_47 ;
int V_4 = * V_39 ;
switch ( type ) {
case V_54 :
switch ( V_1 ) {
case V_55 :
V_53 = V_56 ;
break;
case V_57 :
V_53 = V_51 | V_58 ;
break;
case V_59 :
V_53 = V_51 ;
break;
}
break;
case V_32 :
if ( F_1 ( V_1 , V_8 -> V_36 , V_37 ) ) {
if ( V_4 == 2 ) {
V_53 = V_51 ;
break;
}
if ( ! ! F_2 ( V_1 , V_8 -> V_35 ) != ! ! V_4 ) {
F_26 ( V_1 , V_8 -> V_35 ) ;
V_53 = V_51 ;
}
}
break;
case V_60 :
if ( F_1 ( V_1 , V_8 -> V_61 , V_62 ) &&
! ! F_2 ( V_1 , V_8 -> V_63 ) != ! ! V_4 ) {
F_26 ( V_1 , V_8 -> V_63 ) ;
V_53 = V_51 ;
}
break;
case V_64 :
if ( F_1 ( V_1 , V_8 -> V_65 , V_66 ) )
V_53 = F_21 ( V_8 , V_1 , & V_4 ) ;
break;
case V_67 :
if ( F_1 ( V_1 , V_8 -> V_68 , V_69 ) && V_4 )
V_53 = V_51 ;
break;
case V_70 :
if ( F_1 ( V_1 , V_8 -> V_71 , V_72 ) )
V_53 = V_56 ;
break;
case V_73 :
if ( F_1 ( V_1 , V_8 -> V_74 , V_75 ) &&
! ! F_2 ( V_1 , V_8 -> V_76 ) != ! ! V_4 ) {
F_26 ( V_1 , V_8 -> V_76 ) ;
V_53 = V_56 ;
}
break;
case V_77 :
if ( F_1 ( V_1 , V_8 -> V_78 , V_79 ) ) {
if ( ! ! F_2 ( V_1 , V_8 -> V_80 ) != ! ! V_4 )
F_26 ( V_1 , V_8 -> V_80 ) ;
V_53 = V_56 ;
}
break;
case V_9 :
if ( V_1 <= V_81 && V_4 >= 0 && V_8 -> V_11 [ V_1 ] != V_4 ) {
V_8 -> V_11 [ V_1 ] = V_4 ;
V_53 = V_56 ;
}
break;
case V_82 :
if ( V_4 >= 0 )
V_53 = V_56 ;
break;
case V_83 :
V_53 = V_56 ;
break;
}
* V_39 = V_4 ;
return V_53 ;
}
static void F_27 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
int V_53 ;
V_53 = F_25 ( V_8 , type , V_1 , & V_4 ) ;
if ( ( V_53 & V_84 ) && V_8 -> V_29 )
V_8 -> V_29 ( V_8 , type , V_1 , V_4 ) ;
if ( ! V_8 -> V_21 )
return;
if ( V_53 & V_51 ) {
struct V_20 * V_26 ;
if ( V_53 & V_52 ) {
V_26 = & V_8 -> V_21 [ V_8 -> V_85 ++ ] ;
V_26 -> type = V_64 ;
V_26 -> V_1 = V_44 ;
V_26 -> V_4 = V_8 -> V_41 -> V_46 ;
}
V_26 = & V_8 -> V_21 [ V_8 -> V_85 ++ ] ;
V_26 -> type = type ;
V_26 -> V_1 = V_1 ;
V_26 -> V_4 = V_4 ;
}
if ( V_53 & V_58 ) {
if ( V_8 -> V_85 >= 2 )
F_10 ( V_8 , V_8 -> V_21 , V_8 -> V_85 ) ;
V_8 -> V_85 = 0 ;
} else if ( V_8 -> V_85 >= V_8 -> V_86 - 2 ) {
V_8 -> V_21 [ V_8 -> V_85 ++ ] = V_38 ;
F_10 ( V_8 , V_8 -> V_21 , V_8 -> V_85 ) ;
V_8 -> V_85 = 0 ;
}
}
void F_28 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
unsigned long V_33 ;
if ( F_1 ( type , V_8 -> V_10 , V_87 ) ) {
F_19 ( & V_8 -> V_34 , V_33 ) ;
F_27 ( V_8 , type , V_1 , V_4 ) ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
}
}
void F_29 ( struct V_18 * V_19 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
struct V_18 * V_30 ;
unsigned long V_33 ;
if ( F_1 ( type , V_8 -> V_10 , V_87 ) ) {
F_19 ( & V_8 -> V_34 , V_33 ) ;
F_11 () ;
V_30 = F_12 ( V_8 -> V_30 ) ;
if ( ! V_30 || V_30 == V_19 )
F_27 ( V_8 , type , V_1 , V_4 ) ;
F_14 () ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
}
}
void F_30 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_48 )
V_8 -> V_48 = F_31 ( V_88 , sizeof( struct V_89 ) ,
V_90 ) ;
F_32 ( ! V_8 -> V_48 , L_1 , V_91 ) ;
}
void F_33 ( struct V_7 * V_8 , unsigned int V_92 ,
int V_93 , int V_3 , int V_6 , int V_94 )
{
struct V_89 * V_48 ;
F_30 ( V_8 ) ;
if ( ! V_8 -> V_48 )
return;
V_48 = & V_8 -> V_48 [ V_92 ] ;
V_48 -> V_95 = V_93 ;
V_48 -> V_96 = V_3 ;
V_48 -> V_6 = V_6 ;
V_48 -> V_94 = V_94 ;
F_34 ( V_64 , V_8 -> V_10 ) ;
F_34 ( V_92 , V_8 -> V_65 ) ;
}
int F_35 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
int V_97 ;
V_97 = F_36 ( & V_8 -> V_98 ) ;
if ( V_97 )
return V_97 ;
if ( V_8 -> V_30 ) {
V_97 = - V_99 ;
goto V_100;
}
F_37 ( V_8 -> V_30 , V_19 ) ;
V_100:
F_38 ( & V_8 -> V_98 ) ;
return V_97 ;
}
static void F_39 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
struct V_18 * V_101 ;
V_101 = F_40 ( V_8 -> V_30 ,
F_41 ( & V_8 -> V_98 ) ) ;
if ( V_101 == V_19 ) {
F_37 ( V_8 -> V_30 , NULL ) ;
F_42 () ;
F_43 (handle, &dev->h_list, d_node)
if ( V_19 -> V_31 && V_19 -> V_24 -> V_102 )
V_19 -> V_24 -> V_102 ( V_19 ) ;
}
}
void F_44 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_45 ( & V_8 -> V_98 ) ;
F_39 ( V_19 ) ;
F_38 ( & V_8 -> V_98 ) ;
}
int F_46 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
int V_97 ;
V_97 = F_36 ( & V_8 -> V_98 ) ;
if ( V_97 )
return V_97 ;
if ( V_8 -> V_103 ) {
V_97 = - V_104 ;
goto V_100;
}
V_19 -> V_31 ++ ;
if ( ! V_8 -> V_105 ++ && V_8 -> V_31 )
V_97 = V_8 -> V_31 ( V_8 ) ;
if ( V_97 ) {
V_8 -> V_105 -- ;
if ( ! -- V_19 -> V_31 ) {
F_42 () ;
}
}
V_100:
F_38 ( & V_8 -> V_98 ) ;
return V_97 ;
}
int F_47 ( struct V_18 * V_19 , struct V_106 * V_106 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
int V_97 ;
V_97 = F_36 ( & V_8 -> V_98 ) ;
if ( V_97 )
return V_97 ;
if ( V_8 -> V_107 )
V_97 = V_8 -> V_107 ( V_8 , V_106 ) ;
F_38 ( & V_8 -> V_98 ) ;
return V_97 ;
}
void F_48 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_45 ( & V_8 -> V_98 ) ;
F_39 ( V_19 ) ;
if ( ! -- V_8 -> V_105 && V_8 -> V_108 )
V_8 -> V_108 ( V_8 ) ;
if ( ! -- V_19 -> V_31 ) {
F_42 () ;
}
F_38 ( & V_8 -> V_98 ) ;
}
static void F_49 ( struct V_7 * V_8 )
{
bool V_109 = false ;
int V_1 ;
if ( F_1 ( V_32 , V_8 -> V_10 , V_87 ) ) {
F_50 (code, dev->key, KEY_CNT) {
F_16 ( V_8 , V_32 , V_1 , 0 ) ;
V_109 = true ;
}
if ( V_109 )
F_16 ( V_8 , V_54 , V_57 , 1 ) ;
memset ( V_8 -> V_35 , 0 , sizeof( V_8 -> V_35 ) ) ;
}
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_18 * V_19 ;
F_45 ( & V_8 -> V_98 ) ;
V_8 -> V_103 = true ;
F_38 ( & V_8 -> V_98 ) ;
F_52 ( & V_8 -> V_34 ) ;
F_49 ( V_8 ) ;
F_43 (handle, &dev->h_list, d_node)
V_19 -> V_31 = 0 ;
F_53 ( & V_8 -> V_34 ) ;
}
int F_54 ( const struct V_110 * V_111 ,
unsigned int * V_112 )
{
switch ( V_111 -> V_113 ) {
case 1 :
* V_112 = * ( ( V_114 * ) V_111 -> V_112 ) ;
break;
case 2 :
* V_112 = * ( ( V_115 * ) V_111 -> V_112 ) ;
break;
case 4 :
* V_112 = * ( ( V_116 * ) V_111 -> V_112 ) ;
break;
default:
return - V_117 ;
}
return 0 ;
}
static unsigned int F_55 ( struct V_7 * V_8 ,
unsigned int V_118 )
{
switch ( V_8 -> V_119 ) {
case 1 :
return ( ( V_114 * ) V_8 -> V_120 ) [ V_118 ] ;
case 2 :
return ( ( V_115 * ) V_8 -> V_120 ) [ V_118 ] ;
default:
return ( ( V_116 * ) V_8 -> V_120 ) [ V_118 ] ;
}
}
static int F_56 ( struct V_7 * V_8 ,
struct V_110 * V_111 )
{
unsigned int V_118 ;
int error ;
if ( ! V_8 -> V_119 )
return - V_117 ;
if ( V_111 -> V_33 & V_121 )
V_118 = V_111 -> V_118 ;
else {
error = F_54 ( V_111 , & V_118 ) ;
if ( error )
return error ;
}
if ( V_118 >= V_8 -> V_122 )
return - V_117 ;
V_111 -> V_120 = F_55 ( V_8 , V_118 ) ;
V_111 -> V_118 = V_118 ;
V_111 -> V_113 = sizeof( V_118 ) ;
memcpy ( V_111 -> V_112 , & V_118 , sizeof( V_118 ) ) ;
return 0 ;
}
static int F_57 ( struct V_7 * V_8 ,
const struct V_110 * V_111 ,
unsigned int * V_123 )
{
unsigned int V_118 ;
int error ;
int V_124 ;
if ( ! V_8 -> V_119 )
return - V_117 ;
if ( V_111 -> V_33 & V_121 ) {
V_118 = V_111 -> V_118 ;
} else {
error = F_54 ( V_111 , & V_118 ) ;
if ( error )
return error ;
}
if ( V_118 >= V_8 -> V_122 )
return - V_117 ;
if ( V_8 -> V_119 < sizeof( V_111 -> V_120 ) &&
( V_111 -> V_120 >> ( V_8 -> V_119 * 8 ) ) )
return - V_117 ;
switch ( V_8 -> V_119 ) {
case 1 : {
V_114 * V_125 = ( V_114 * ) V_8 -> V_120 ;
* V_123 = V_125 [ V_118 ] ;
V_125 [ V_118 ] = V_111 -> V_120 ;
break;
}
case 2 : {
V_115 * V_125 = ( V_115 * ) V_8 -> V_120 ;
* V_123 = V_125 [ V_118 ] ;
V_125 [ V_118 ] = V_111 -> V_120 ;
break;
}
default: {
V_116 * V_125 = ( V_116 * ) V_8 -> V_120 ;
* V_123 = V_125 [ V_118 ] ;
V_125 [ V_118 ] = V_111 -> V_120 ;
break;
}
}
F_58 ( * V_123 , V_8 -> V_36 ) ;
F_34 ( V_111 -> V_120 , V_8 -> V_36 ) ;
for ( V_124 = 0 ; V_124 < V_8 -> V_122 ; V_124 ++ ) {
if ( F_55 ( V_8 , V_124 ) == * V_123 ) {
F_34 ( * V_123 , V_8 -> V_36 ) ;
break;
}
}
return 0 ;
}
int F_59 ( struct V_7 * V_8 , struct V_110 * V_111 )
{
unsigned long V_33 ;
int V_97 ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
V_97 = V_8 -> V_126 ( V_8 , V_111 ) ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
return V_97 ;
}
int F_60 ( struct V_7 * V_8 ,
const struct V_110 * V_111 )
{
unsigned long V_33 ;
unsigned int V_123 ;
int V_97 ;
if ( V_111 -> V_120 > V_37 )
return - V_117 ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
V_97 = V_8 -> V_127 ( V_8 , V_111 , & V_123 ) ;
if ( V_97 )
goto V_100;
F_58 ( V_128 , V_8 -> V_36 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) &&
! F_1 ( V_123 , V_8 -> V_36 , V_37 ) &&
F_61 ( V_123 , V_8 -> V_35 ) ) {
struct V_20 V_21 [] = {
{ V_32 , V_123 , 0 } ,
V_38
} ;
F_10 ( V_8 , V_21 , F_17 ( V_21 ) ) ;
}
V_100:
F_20 ( & V_8 -> V_34 , V_33 ) ;
return V_97 ;
}
static const struct V_129 * F_62 ( struct V_23 * V_24 ,
struct V_7 * V_8 )
{
const struct V_129 * V_130 ;
for ( V_130 = V_24 -> V_131 ; V_130 -> V_33 || V_130 -> V_132 ; V_130 ++ ) {
if ( V_130 -> V_33 & V_133 )
if ( V_130 -> V_134 != V_8 -> V_130 . V_134 )
continue;
if ( V_130 -> V_33 & V_135 )
if ( V_130 -> V_136 != V_8 -> V_130 . V_136 )
continue;
if ( V_130 -> V_33 & V_137 )
if ( V_130 -> V_138 != V_8 -> V_130 . V_138 )
continue;
if ( V_130 -> V_33 & V_139 )
if ( V_130 -> V_140 != V_8 -> V_130 . V_140 )
continue;
if ( ! F_63 ( V_130 -> V_10 , V_8 -> V_10 , V_87 ) )
continue;
if ( ! F_63 ( V_130 -> V_36 , V_8 -> V_36 , V_37 ) )
continue;
if ( ! F_63 ( V_130 -> V_68 , V_8 -> V_68 , V_69 ) )
continue;
if ( ! F_63 ( V_130 -> V_65 , V_8 -> V_65 , V_66 ) )
continue;
if ( ! F_63 ( V_130 -> V_71 , V_8 -> V_71 , V_72 ) )
continue;
if ( ! F_63 ( V_130 -> V_74 , V_8 -> V_74 , V_75 ) )
continue;
if ( ! F_63 ( V_130 -> V_78 , V_8 -> V_78 , V_79 ) )
continue;
if ( ! F_63 ( V_130 -> V_141 , V_8 -> V_141 , V_142 ) )
continue;
if ( ! F_63 ( V_130 -> V_61 , V_8 -> V_61 , V_62 ) )
continue;
if ( ! V_24 -> V_143 || V_24 -> V_143 ( V_24 , V_8 ) )
return V_130 ;
}
return NULL ;
}
static int F_64 ( struct V_7 * V_8 , struct V_23 * V_24 )
{
const struct V_129 * V_130 ;
int error ;
V_130 = F_62 ( V_24 , V_8 ) ;
if ( ! V_130 )
return - V_104 ;
error = V_24 -> V_144 ( V_24 , V_8 , V_130 ) ;
if ( error && error != - V_104 )
F_65 ( L_2 ,
V_24 -> V_145 , F_66 ( & V_8 -> V_8 . V_146 ) , error ) ;
return error ;
}
static int F_67 ( char * V_147 , int V_148 ,
unsigned long V_149 , bool V_150 )
{
int V_113 = 0 ;
if ( V_151 ) {
V_116 V_152 = V_149 >> 32 ;
if ( V_152 || ! V_150 )
V_113 += snprintf ( V_147 , V_148 , L_3 , V_152 ) ;
V_152 = V_149 & 0xffffffffUL ;
if ( V_152 || ! V_150 || V_113 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) ,
L_4 , V_152 ) ;
} else {
if ( V_149 || ! V_150 )
V_113 += snprintf ( V_147 , V_148 , L_5 , V_149 ) ;
}
return V_113 ;
}
static int F_67 ( char * V_147 , int V_148 ,
unsigned long V_149 , bool V_150 )
{
return V_149 || ! V_150 ?
snprintf ( V_147 , V_148 , L_5 , V_149 ) : 0 ;
}
static inline void F_68 ( void )
{
V_153 ++ ;
F_69 ( & V_154 ) ;
}
static unsigned int F_70 ( struct V_106 * V_106 , T_1 * V_155 )
{
F_71 ( V_106 , & V_154 , V_155 ) ;
if ( V_106 -> V_156 != V_153 ) {
V_106 -> V_156 = V_153 ;
return V_157 | V_158 ;
}
return 0 ;
}
static void * F_72 ( struct V_159 * V_160 , T_2 * V_161 )
{
union V_162 * V_163 = (union V_162 * ) & V_160 -> V_164 ;
int error ;
F_73 ( sizeof( union V_162 ) != sizeof( V_160 -> V_164 ) ) ;
error = F_36 ( & V_165 ) ;
if ( error ) {
V_163 -> V_166 = false ;
return F_74 ( error ) ;
}
V_163 -> V_166 = true ;
return F_75 ( & V_167 , * V_161 ) ;
}
static void * F_76 ( struct V_159 * V_160 , void * V_26 , T_2 * V_161 )
{
return F_77 ( V_26 , & V_167 , V_161 ) ;
}
static void F_78 ( struct V_159 * V_160 , void * V_26 )
{
union V_162 * V_163 = (union V_162 * ) & V_160 -> V_164 ;
if ( V_163 -> V_166 )
F_38 ( & V_165 ) ;
}
static void F_79 ( struct V_159 * V_160 , const char * V_145 ,
unsigned long * V_168 , int V_3 )
{
int V_124 ;
bool V_150 = true ;
char V_147 [ 18 ] ;
F_80 ( V_160 , L_6 , V_145 ) ;
for ( V_124 = F_81 ( V_3 ) - 1 ; V_124 >= 0 ; V_124 -- ) {
if ( F_67 ( V_147 , sizeof( V_147 ) ,
V_168 [ V_124 ] , V_150 ) ) {
V_150 = false ;
F_80 ( V_160 , L_7 , V_147 , V_124 > 0 ? L_8 : L_9 ) ;
}
}
if ( V_150 )
F_82 ( V_160 , L_10 ) ;
F_83 ( V_160 , '\n' ) ;
}
static int F_84 ( struct V_159 * V_160 , void * V_26 )
{
struct V_7 * V_8 = F_85 ( V_26 , struct V_7 , V_169 ) ;
const char * V_170 = F_86 ( & V_8 -> V_8 . V_146 , V_90 ) ;
struct V_18 * V_19 ;
F_80 ( V_160 , L_11 ,
V_8 -> V_130 . V_134 , V_8 -> V_130 . V_136 , V_8 -> V_130 . V_138 , V_8 -> V_130 . V_140 ) ;
F_80 ( V_160 , L_12 , V_8 -> V_145 ? V_8 -> V_145 : L_9 ) ;
F_80 ( V_160 , L_13 , V_8 -> V_171 ? V_8 -> V_171 : L_9 ) ;
F_80 ( V_160 , L_14 , V_170 ? V_170 : L_9 ) ;
F_80 ( V_160 , L_15 , V_8 -> V_172 ? V_8 -> V_172 : L_9 ) ;
F_80 ( V_160 , L_16 ) ;
F_43 (handle, &dev->h_list, d_node)
F_80 ( V_160 , L_17 , V_19 -> V_145 ) ;
F_83 ( V_160 , '\n' ) ;
F_79 ( V_160 , L_18 , V_8 -> V_173 , V_174 ) ;
F_79 ( V_160 , L_19 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_79 ( V_160 , L_20 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_79 ( V_160 , L_21 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_79 ( V_160 , L_22 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_79 ( V_160 , L_23 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_79 ( V_160 , L_24 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_79 ( V_160 , L_25 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_79 ( V_160 , L_26 , V_8 -> V_141 , V_142 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_79 ( V_160 , L_27 , V_8 -> V_61 , V_62 ) ;
F_83 ( V_160 , '\n' ) ;
F_87 ( V_170 ) ;
return 0 ;
}
static int F_88 ( struct V_175 * V_175 , struct V_106 * V_106 )
{
return F_89 ( V_106 , & V_176 ) ;
}
static void * F_90 ( struct V_159 * V_160 , T_2 * V_161 )
{
union V_162 * V_163 = (union V_162 * ) & V_160 -> V_164 ;
int error ;
F_73 ( sizeof( union V_162 ) != sizeof( V_160 -> V_164 ) ) ;
error = F_36 ( & V_165 ) ;
if ( error ) {
V_163 -> V_166 = false ;
return F_74 ( error ) ;
}
V_163 -> V_166 = true ;
V_163 -> V_161 = * V_161 ;
return F_75 ( & V_177 , * V_161 ) ;
}
static void * F_91 ( struct V_159 * V_160 , void * V_26 , T_2 * V_161 )
{
union V_162 * V_163 = (union V_162 * ) & V_160 -> V_164 ;
V_163 -> V_161 = * V_161 + 1 ;
return F_77 ( V_26 , & V_177 , V_161 ) ;
}
static int F_92 ( struct V_159 * V_160 , void * V_26 )
{
struct V_23 * V_24 = F_85 ( V_26 , struct V_23 , V_169 ) ;
union V_162 * V_163 = (union V_162 * ) & V_160 -> V_164 ;
F_80 ( V_160 , L_28 , V_163 -> V_161 , V_24 -> V_145 ) ;
if ( V_24 -> V_27 )
F_82 ( V_160 , L_29 ) ;
if ( V_24 -> V_178 )
F_80 ( V_160 , L_30 , V_24 -> V_179 ) ;
F_83 ( V_160 , '\n' ) ;
return 0 ;
}
static int F_93 ( struct V_175 * V_175 , struct V_106 * V_106 )
{
return F_89 ( V_106 , & V_180 ) ;
}
static int T_3 F_94 ( void )
{
struct V_181 * V_182 ;
V_183 = F_95 ( L_31 , NULL ) ;
if ( ! V_183 )
return - V_184 ;
V_182 = F_96 ( L_32 , 0 , V_183 ,
& V_185 ) ;
if ( ! V_182 )
goto V_186;
V_182 = F_96 ( L_33 , 0 , V_183 ,
& V_187 ) ;
if ( ! V_182 )
goto V_188;
return 0 ;
V_188: F_97 ( L_32 , V_183 ) ;
V_186: F_97 ( L_31 , NULL ) ;
return - V_184 ;
}
static void F_98 ( void )
{
F_97 ( L_32 , V_183 ) ;
F_97 ( L_33 , V_183 ) ;
F_97 ( L_31 , NULL ) ;
}
static inline void F_68 ( void ) { }
static inline int F_94 ( void ) { return 0 ; }
static inline void F_98 ( void ) { }
static int F_99 ( char * V_147 , int V_189 ,
char V_145 , unsigned long * V_2 ,
unsigned int V_190 , unsigned int V_191 )
{
int V_113 = 0 , V_124 ;
V_113 += snprintf ( V_147 , V_3 ( V_189 , 0 ) , L_34 , V_145 ) ;
for ( V_124 = V_190 ; V_124 < V_191 ; V_124 ++ )
if ( V_2 [ F_100 ( V_124 ) ] & F_101 ( V_124 ) )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_189 - V_113 , 0 ) , L_35 , V_124 ) ;
return V_113 ;
}
static int F_102 ( char * V_147 , int V_189 , struct V_7 * V_130 ,
int V_192 )
{
int V_113 ;
V_113 = snprintf ( V_147 , V_3 ( V_189 , 0 ) ,
L_36 ,
V_130 -> V_130 . V_134 , V_130 -> V_130 . V_136 ,
V_130 -> V_130 . V_138 , V_130 -> V_130 . V_140 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'e' , V_130 -> V_10 , 0 , V_87 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'k' , V_130 -> V_36 , V_193 , V_37 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'r' , V_130 -> V_68 , 0 , V_69 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'a' , V_130 -> V_65 , 0 , V_66 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'm' , V_130 -> V_71 , 0 , V_72 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'l' , V_130 -> V_74 , 0 , V_75 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
's' , V_130 -> V_78 , 0 , V_79 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'f' , V_130 -> V_141 , 0 , V_142 ) ;
V_113 += F_99 ( V_147 + V_113 , V_189 - V_113 ,
'w' , V_130 -> V_61 , 0 , V_62 ) ;
if ( V_192 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_189 - V_113 , 0 ) , L_37 ) ;
return V_113 ;
}
static T_4 F_103 ( struct V_194 * V_8 ,
struct V_195 * V_196 ,
char * V_147 )
{
struct V_7 * V_130 = F_104 ( V_8 ) ;
T_4 V_113 ;
V_113 = F_102 ( V_147 , V_197 , V_130 , 1 ) ;
return F_105 ( int , V_113 , V_197 ) ;
}
static T_4 F_106 ( struct V_194 * V_8 ,
struct V_195 * V_196 ,
char * V_147 )
{
struct V_7 * V_7 = F_104 ( V_8 ) ;
int V_113 = F_107 ( V_147 , V_197 , V_7 -> V_173 ,
V_174 , true ) ;
return F_105 ( int , V_113 , V_197 ) ;
}
static int F_107 ( char * V_147 , int V_148 , unsigned long * V_168 ,
int V_3 , int V_192 )
{
int V_124 ;
int V_113 = 0 ;
bool V_150 = true ;
for ( V_124 = F_81 ( V_3 ) - 1 ; V_124 >= 0 ; V_124 -- ) {
V_113 += F_67 ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) ,
V_168 [ V_124 ] , V_150 ) ;
if ( V_113 ) {
V_150 = false ;
if ( V_124 > 0 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) , L_8 ) ;
}
}
if ( V_113 == 0 )
V_113 = snprintf ( V_147 , V_148 , L_38 , 0 ) ;
if ( V_192 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) , L_37 ) ;
return V_113 ;
}
static void F_108 ( struct V_194 * V_194 )
{
struct V_7 * V_8 = F_104 ( V_194 ) ;
F_109 ( V_8 ) ;
F_110 ( V_8 ) ;
F_87 ( V_8 -> V_48 ) ;
F_87 ( V_8 -> V_21 ) ;
F_87 ( V_8 ) ;
F_111 ( V_198 ) ;
}
static int F_112 ( struct V_199 * V_200 ,
const char * V_145 , unsigned long * V_168 , int V_3 )
{
int V_113 ;
if ( F_113 ( V_200 , L_39 , V_145 ) )
return - V_184 ;
V_113 = F_107 ( & V_200 -> V_147 [ V_200 -> V_201 - 1 ] ,
sizeof( V_200 -> V_147 ) - V_200 -> V_201 ,
V_168 , V_3 , false ) ;
if ( V_113 >= ( sizeof( V_200 -> V_147 ) - V_200 -> V_201 ) )
return - V_184 ;
V_200 -> V_201 += V_113 ;
return 0 ;
}
static int F_114 ( struct V_199 * V_200 ,
struct V_7 * V_8 )
{
int V_113 ;
if ( F_113 ( V_200 , L_40 ) )
return - V_184 ;
V_113 = F_102 ( & V_200 -> V_147 [ V_200 -> V_201 - 1 ] ,
sizeof( V_200 -> V_147 ) - V_200 -> V_201 ,
V_8 , 0 ) ;
if ( V_113 >= ( sizeof( V_200 -> V_147 ) - V_200 -> V_201 ) )
return - V_184 ;
V_200 -> V_201 += V_113 ;
return 0 ;
}
static int F_115 ( struct V_194 * V_194 , struct V_199 * V_200 )
{
struct V_7 * V_8 = F_104 ( V_194 ) ;
F_116 ( L_41 ,
V_8 -> V_130 . V_134 , V_8 -> V_130 . V_136 ,
V_8 -> V_130 . V_138 , V_8 -> V_130 . V_140 ) ;
if ( V_8 -> V_145 )
F_116 ( L_42 , V_8 -> V_145 ) ;
if ( V_8 -> V_171 )
F_116 ( L_43 , V_8 -> V_171 ) ;
if ( V_8 -> V_172 )
F_116 ( L_44 , V_8 -> V_172 ) ;
F_117 ( L_45 , V_8 -> V_173 , V_174 ) ;
F_117 ( L_46 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_117 ( L_47 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_117 ( L_48 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_117 ( L_49 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_117 ( L_50 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_117 ( L_51 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_117 ( L_52 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_117 ( L_53 , V_8 -> V_141 , V_142 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_117 ( L_54 , V_8 -> V_61 , V_62 ) ;
F_118 ( V_8 ) ;
return 0 ;
}
static void F_119 ( struct V_7 * V_8 , bool V_202 )
{
if ( ! V_8 -> V_29 )
return;
F_120 ( V_8 , V_203 , V_76 , V_202 ) ;
F_120 ( V_8 , V_204 , V_80 , V_202 ) ;
if ( V_202 && F_2 ( V_9 , V_8 -> V_10 ) ) {
V_8 -> V_29 ( V_8 , V_9 , V_12 , V_8 -> V_11 [ V_12 ] ) ;
V_8 -> V_29 ( V_8 , V_9 , V_13 , V_8 -> V_11 [ V_13 ] ) ;
}
}
void F_121 ( struct V_7 * V_8 )
{
unsigned long V_33 ;
F_45 ( & V_8 -> V_98 ) ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
F_119 ( V_8 , true ) ;
F_49 ( V_8 ) ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
F_38 ( & V_8 -> V_98 ) ;
}
static int F_122 ( struct V_194 * V_8 )
{
struct V_7 * V_7 = F_104 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_49 ( V_7 ) ;
F_119 ( V_7 , false ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_123 ( struct V_194 * V_8 )
{
struct V_7 * V_7 = F_104 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_119 ( V_7 , true ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_124 ( struct V_194 * V_8 )
{
struct V_7 * V_7 = F_104 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_49 ( V_7 ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_125 ( struct V_194 * V_8 )
{
struct V_7 * V_7 = F_104 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_119 ( V_7 , false ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static char * F_126 ( struct V_194 * V_8 , T_5 * V_205 )
{
return F_127 ( V_90 , L_55 , F_128 ( V_8 ) ) ;
}
struct V_7 * F_129 ( void )
{
static T_6 V_206 = F_130 ( - 1 ) ;
struct V_7 * V_8 ;
V_8 = F_131 ( sizeof( struct V_7 ) , V_90 ) ;
if ( V_8 ) {
V_8 -> V_8 . type = & V_207 ;
V_8 -> V_8 . V_208 = & V_209 ;
F_132 ( & V_8 -> V_8 ) ;
F_133 ( & V_8 -> V_98 ) ;
F_134 ( & V_8 -> V_34 ) ;
F_135 ( & V_8 -> V_14 ) ;
F_136 ( & V_8 -> V_210 ) ;
F_136 ( & V_8 -> V_169 ) ;
F_137 ( & V_8 -> V_8 , L_56 ,
( unsigned long ) F_138 ( & V_206 ) ) ;
F_139 ( V_198 ) ;
}
return V_8 ;
}
static int F_140 ( struct V_194 * V_8 , void * V_211 , void * V_15 )
{
struct V_212 * V_213 = V_211 ;
return V_213 -> V_214 == V_15 ;
}
static void F_141 ( struct V_194 * V_8 , void * V_211 )
{
struct V_212 * V_213 = V_211 ;
struct V_7 * V_214 = V_213 -> V_214 ;
F_142 ( V_8 , L_57 ,
V_91 , F_128 ( & V_214 -> V_8 ) ) ;
F_143 ( V_214 ) ;
}
struct V_7 * F_144 ( struct V_194 * V_8 )
{
struct V_7 * V_214 ;
struct V_212 * V_213 ;
V_213 = F_145 ( F_141 ,
sizeof( struct V_212 ) , V_90 ) ;
if ( ! V_213 )
return NULL ;
V_214 = F_129 () ;
if ( ! V_214 ) {
F_146 ( V_213 ) ;
return NULL ;
}
V_214 -> V_8 . V_215 = V_8 ;
V_214 -> V_216 = true ;
V_213 -> V_214 = V_214 ;
F_147 ( V_8 , V_213 ) ;
return V_214 ;
}
void F_148 ( struct V_7 * V_8 )
{
if ( V_8 ) {
if ( V_8 -> V_216 )
F_149 ( F_150 ( V_8 -> V_8 . V_215 ,
F_141 ,
F_140 ,
V_8 ) ) ;
F_143 ( V_8 ) ;
}
}
void F_151 ( struct V_7 * V_8 , unsigned int type , unsigned int V_1 )
{
switch ( type ) {
case V_32 :
F_34 ( V_1 , V_8 -> V_36 ) ;
break;
case V_67 :
F_34 ( V_1 , V_8 -> V_68 ) ;
break;
case V_64 :
F_30 ( V_8 ) ;
if ( ! V_8 -> V_48 )
return;
F_34 ( V_1 , V_8 -> V_65 ) ;
break;
case V_70 :
F_34 ( V_1 , V_8 -> V_71 ) ;
break;
case V_60 :
F_34 ( V_1 , V_8 -> V_61 ) ;
break;
case V_73 :
F_34 ( V_1 , V_8 -> V_74 ) ;
break;
case V_77 :
F_34 ( V_1 , V_8 -> V_78 ) ;
break;
case V_82 :
F_34 ( V_1 , V_8 -> V_141 ) ;
break;
case V_83 :
break;
default:
F_65 ( L_58 ,
type , V_1 ) ;
F_152 () ;
return;
}
F_34 ( type , V_8 -> V_10 ) ;
}
static unsigned int F_153 ( struct V_7 * V_8 )
{
int V_217 ;
int V_124 ;
unsigned int V_28 ;
if ( V_8 -> V_41 ) {
V_217 = V_8 -> V_41 -> V_45 ;
} else if ( F_2 ( V_218 , V_8 -> V_65 ) ) {
V_217 = V_8 -> V_48 [ V_218 ] . V_96 -
V_8 -> V_48 [ V_218 ] . V_95 + 1 ,
V_217 = F_154 ( V_217 , 2 , 32 ) ;
} else if ( F_2 ( V_219 , V_8 -> V_65 ) ) {
V_217 = 2 ;
} else {
V_217 = 0 ;
}
V_28 = V_217 + 1 ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_50 (i, dev->absbit, ABS_CNT)
V_28 += F_155 ( V_124 ) ? V_217 : 1 ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
V_28 += F_156 ( V_8 -> V_68 , V_220 ) ;
V_28 += 7 ;
return V_28 ;
}
static void F_157 ( struct V_7 * V_8 )
{
F_158 ( V_8 , V_221 , V_35 ) ;
F_158 ( V_8 , V_222 , V_223 ) ;
F_158 ( V_8 , ABS , abs ) ;
F_158 ( V_8 , V_224 , V_225 ) ;
F_158 ( V_8 , V_203 , V_76 ) ;
F_158 ( V_8 , V_204 , V_80 ) ;
F_158 ( V_8 , V_226 , V_227 ) ;
F_158 ( V_8 , V_228 , V_63 ) ;
}
static void F_159 ( struct V_7 * V_8 )
{
struct V_18 * V_19 , * V_229 ;
F_51 ( V_8 ) ;
F_45 ( & V_165 ) ;
F_160 (handle, next, &dev->h_list, d_node)
V_19 -> V_24 -> V_230 ( V_19 ) ;
F_149 ( ! F_161 ( & V_8 -> V_210 ) ) ;
F_162 ( & V_8 -> V_14 ) ;
F_163 ( & V_8 -> V_169 ) ;
F_68 () ;
F_38 ( & V_165 ) ;
F_164 ( & V_8 -> V_8 ) ;
}
static void F_165 ( struct V_194 * V_8 , void * V_211 )
{
struct V_212 * V_213 = V_211 ;
struct V_7 * V_214 = V_213 -> V_214 ;
F_142 ( V_8 , L_59 ,
V_91 , F_128 ( & V_214 -> V_8 ) ) ;
F_159 ( V_214 ) ;
}
void F_166 ( struct V_7 * V_8 , int V_231 , int V_232 )
{
V_8 -> V_14 . V_15 = ( unsigned long ) V_8 ;
V_8 -> V_14 . V_233 = F_18 ;
V_8 -> V_11 [ V_13 ] = V_231 ;
V_8 -> V_11 [ V_12 ] = V_232 ;
}
int F_167 ( struct V_7 * V_8 )
{
struct V_212 * V_213 = NULL ;
struct V_23 * V_24 ;
unsigned int V_234 ;
const char * V_170 ;
int error ;
if ( V_8 -> V_216 ) {
V_213 = F_145 ( F_165 ,
sizeof( struct V_212 ) , V_90 ) ;
if ( ! V_213 )
return - V_184 ;
V_213 -> V_214 = V_8 ;
}
F_34 ( V_54 , V_8 -> V_10 ) ;
F_58 ( V_128 , V_8 -> V_36 ) ;
F_157 ( V_8 ) ;
V_234 = F_153 ( V_8 ) ;
if ( V_8 -> V_235 < V_234 )
V_8 -> V_235 = V_234 ;
V_8 -> V_86 = V_8 -> V_235 + 2 ;
V_8 -> V_21 = F_31 ( V_8 -> V_86 , sizeof( * V_8 -> V_21 ) , V_90 ) ;
if ( ! V_8 -> V_21 ) {
error = - V_184 ;
goto V_236;
}
if ( ! V_8 -> V_11 [ V_13 ] && ! V_8 -> V_11 [ V_12 ] )
F_166 ( V_8 , 250 , 33 ) ;
if ( ! V_8 -> V_126 )
V_8 -> V_126 = F_56 ;
if ( ! V_8 -> V_127 )
V_8 -> V_127 = F_57 ;
error = F_168 ( & V_8 -> V_8 ) ;
if ( error )
goto V_237;
V_170 = F_86 ( & V_8 -> V_8 . V_146 , V_90 ) ;
F_169 ( L_60 ,
V_8 -> V_145 ? V_8 -> V_145 : L_61 ,
V_170 ? V_170 : L_62 ) ;
F_87 ( V_170 ) ;
error = F_36 ( & V_165 ) ;
if ( error )
goto V_238;
F_170 ( & V_8 -> V_169 , & V_167 ) ;
F_43 (handler, &input_handler_list, node)
F_64 ( V_8 , V_24 ) ;
F_68 () ;
F_38 ( & V_165 ) ;
if ( V_8 -> V_216 ) {
F_142 ( V_8 -> V_8 . V_215 , L_63 ,
V_91 , F_128 ( & V_8 -> V_8 ) ) ;
F_147 ( V_8 -> V_8 . V_215 , V_213 ) ;
}
return 0 ;
V_238:
F_164 ( & V_8 -> V_8 ) ;
V_237:
F_87 ( V_8 -> V_21 ) ;
V_8 -> V_21 = NULL ;
V_236:
F_146 ( V_213 ) ;
return error ;
}
void F_171 ( struct V_7 * V_8 )
{
if ( V_8 -> V_216 ) {
F_149 ( F_150 ( V_8 -> V_8 . V_215 ,
F_165 ,
F_140 ,
V_8 ) ) ;
F_159 ( V_8 ) ;
} else {
F_159 ( V_8 ) ;
F_143 ( V_8 ) ;
}
}
int F_172 ( struct V_23 * V_24 )
{
struct V_7 * V_8 ;
int error ;
error = F_36 ( & V_165 ) ;
if ( error )
return error ;
F_136 ( & V_24 -> V_210 ) ;
F_170 ( & V_24 -> V_169 , & V_177 ) ;
F_43 (dev, &input_dev_list, node)
F_64 ( V_8 , V_24 ) ;
F_68 () ;
F_38 ( & V_165 ) ;
return 0 ;
}
void F_173 ( struct V_23 * V_24 )
{
struct V_18 * V_19 , * V_229 ;
F_45 ( & V_165 ) ;
F_160 (handle, next, &handler->h_list, h_node)
V_24 -> V_230 ( V_19 ) ;
F_149 ( ! F_161 ( & V_24 -> V_210 ) ) ;
F_163 ( & V_24 -> V_169 ) ;
F_68 () ;
F_38 ( & V_165 ) ;
}
int F_174 ( struct V_23 * V_24 , void * V_15 ,
int (* F_175)( struct V_18 * , void * ) )
{
struct V_18 * V_19 ;
int V_97 = 0 ;
F_11 () ;
F_13 (handle, &handler->h_list, h_node) {
V_97 = F_175 ( V_19 , V_15 ) ;
if ( V_97 )
break;
}
F_14 () ;
return V_97 ;
}
int F_176 ( struct V_18 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_7 * V_8 = V_19 -> V_8 ;
int error ;
error = F_36 ( & V_8 -> V_98 ) ;
if ( error )
return error ;
if ( V_24 -> V_27 )
F_177 ( & V_19 -> V_239 , & V_8 -> V_210 ) ;
else
F_178 ( & V_19 -> V_239 , & V_8 -> V_210 ) ;
F_38 ( & V_8 -> V_98 ) ;
F_178 ( & V_19 -> V_240 , & V_24 -> V_210 ) ;
if ( V_24 -> V_102 )
V_24 -> V_102 ( V_19 ) ;
return 0 ;
}
void F_179 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_180 ( & V_19 -> V_240 ) ;
F_45 ( & V_8 -> V_98 ) ;
F_180 ( & V_19 -> V_239 ) ;
F_38 ( & V_8 -> V_98 ) ;
F_42 () ;
}
int F_181 ( int V_241 , unsigned int V_242 ,
bool V_243 )
{
if ( V_241 >= 0 ) {
int V_179 = F_182 ( & V_244 ,
V_241 ,
V_241 + V_242 ,
V_90 ) ;
if ( V_179 >= 0 || ! V_243 )
return V_179 ;
}
return F_182 ( & V_244 ,
V_245 , V_246 ,
V_90 ) ;
}
void F_183 ( unsigned int V_179 )
{
F_184 ( & V_244 , V_179 ) ;
}
static int T_3 F_185 ( void )
{
int V_247 ;
V_247 = F_186 ( & V_209 ) ;
if ( V_247 ) {
F_65 ( L_64 ) ;
return V_247 ;
}
V_247 = F_94 () ;
if ( V_247 )
goto V_186;
V_247 = F_187 ( F_188 ( V_248 , 0 ) ,
V_246 , L_65 ) ;
if ( V_247 ) {
F_65 ( L_66 , V_248 ) ;
goto V_188;
}
return 0 ;
V_188: F_98 () ;
V_186: F_189 ( & V_209 ) ;
return V_247 ;
}
static void T_7 F_190 ( void )
{
F_98 () ;
F_191 ( F_188 ( V_248 , 0 ) ,
V_246 ) ;
F_189 ( & V_209 ) ;
}
