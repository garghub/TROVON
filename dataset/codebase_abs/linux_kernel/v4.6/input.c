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
if ( F_68 () ) {
V_116 V_151 = V_149 >> 32 ;
if ( V_151 || ! V_150 )
V_113 += snprintf ( V_147 , V_148 , L_3 , V_151 ) ;
V_151 = V_149 & 0xffffffffUL ;
if ( V_151 || ! V_150 || V_113 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) ,
L_4 , V_151 ) ;
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
static inline void F_69 ( void )
{
V_152 ++ ;
F_70 ( & V_153 ) ;
}
static unsigned int F_71 ( struct V_106 * V_106 , T_1 * V_154 )
{
F_72 ( V_106 , & V_153 , V_154 ) ;
if ( V_106 -> V_155 != V_152 ) {
V_106 -> V_155 = V_152 ;
return V_156 | V_157 ;
}
return 0 ;
}
static void * F_73 ( struct V_158 * V_159 , T_2 * V_160 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
int error ;
F_74 ( sizeof( union V_161 ) != sizeof( V_159 -> V_163 ) ) ;
error = F_36 ( & V_164 ) ;
if ( error ) {
V_162 -> V_165 = false ;
return F_75 ( error ) ;
}
V_162 -> V_165 = true ;
return F_76 ( & V_166 , * V_160 ) ;
}
static void * F_77 ( struct V_158 * V_159 , void * V_26 , T_2 * V_160 )
{
return F_78 ( V_26 , & V_166 , V_160 ) ;
}
static void F_79 ( struct V_158 * V_159 , void * V_26 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
if ( V_162 -> V_165 )
F_38 ( & V_164 ) ;
}
static void F_80 ( struct V_158 * V_159 , const char * V_145 ,
unsigned long * V_167 , int V_3 )
{
int V_124 ;
bool V_150 = true ;
char V_147 [ 18 ] ;
F_81 ( V_159 , L_6 , V_145 ) ;
for ( V_124 = F_82 ( V_3 ) - 1 ; V_124 >= 0 ; V_124 -- ) {
if ( F_67 ( V_147 , sizeof( V_147 ) ,
V_167 [ V_124 ] , V_150 ) ) {
V_150 = false ;
F_81 ( V_159 , L_7 , V_147 , V_124 > 0 ? L_8 : L_9 ) ;
}
}
if ( V_150 )
F_83 ( V_159 , L_10 ) ;
F_84 ( V_159 , '\n' ) ;
}
static int F_85 ( struct V_158 * V_159 , void * V_26 )
{
struct V_7 * V_8 = F_86 ( V_26 , struct V_7 , V_168 ) ;
const char * V_169 = F_87 ( & V_8 -> V_8 . V_146 , V_90 ) ;
struct V_18 * V_19 ;
F_81 ( V_159 , L_11 ,
V_8 -> V_130 . V_134 , V_8 -> V_130 . V_136 , V_8 -> V_130 . V_138 , V_8 -> V_130 . V_140 ) ;
F_81 ( V_159 , L_12 , V_8 -> V_145 ? V_8 -> V_145 : L_9 ) ;
F_81 ( V_159 , L_13 , V_8 -> V_170 ? V_8 -> V_170 : L_9 ) ;
F_81 ( V_159 , L_14 , V_169 ? V_169 : L_9 ) ;
F_81 ( V_159 , L_15 , V_8 -> V_171 ? V_8 -> V_171 : L_9 ) ;
F_81 ( V_159 , L_16 ) ;
F_43 (handle, &dev->h_list, d_node)
F_81 ( V_159 , L_17 , V_19 -> V_145 ) ;
F_84 ( V_159 , '\n' ) ;
F_80 ( V_159 , L_18 , V_8 -> V_172 , V_173 ) ;
F_80 ( V_159 , L_19 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_80 ( V_159 , L_20 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_80 ( V_159 , L_21 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_80 ( V_159 , L_22 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_80 ( V_159 , L_23 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_80 ( V_159 , L_24 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_80 ( V_159 , L_25 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_80 ( V_159 , L_26 , V_8 -> V_141 , V_142 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_80 ( V_159 , L_27 , V_8 -> V_61 , V_62 ) ;
F_84 ( V_159 , '\n' ) ;
F_88 ( V_169 ) ;
return 0 ;
}
static int F_89 ( struct V_174 * V_174 , struct V_106 * V_106 )
{
return F_90 ( V_106 , & V_175 ) ;
}
static void * F_91 ( struct V_158 * V_159 , T_2 * V_160 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
int error ;
F_74 ( sizeof( union V_161 ) != sizeof( V_159 -> V_163 ) ) ;
error = F_36 ( & V_164 ) ;
if ( error ) {
V_162 -> V_165 = false ;
return F_75 ( error ) ;
}
V_162 -> V_165 = true ;
V_162 -> V_160 = * V_160 ;
return F_76 ( & V_176 , * V_160 ) ;
}
static void * F_92 ( struct V_158 * V_159 , void * V_26 , T_2 * V_160 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
V_162 -> V_160 = * V_160 + 1 ;
return F_78 ( V_26 , & V_176 , V_160 ) ;
}
static int F_93 ( struct V_158 * V_159 , void * V_26 )
{
struct V_23 * V_24 = F_86 ( V_26 , struct V_23 , V_168 ) ;
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
F_81 ( V_159 , L_28 , V_162 -> V_160 , V_24 -> V_145 ) ;
if ( V_24 -> V_27 )
F_83 ( V_159 , L_29 ) ;
if ( V_24 -> V_177 )
F_81 ( V_159 , L_30 , V_24 -> V_178 ) ;
F_84 ( V_159 , '\n' ) ;
return 0 ;
}
static int F_94 ( struct V_174 * V_174 , struct V_106 * V_106 )
{
return F_90 ( V_106 , & V_179 ) ;
}
static int T_3 F_95 ( void )
{
struct V_180 * V_181 ;
V_182 = F_96 ( L_31 , NULL ) ;
if ( ! V_182 )
return - V_183 ;
V_181 = F_97 ( L_32 , 0 , V_182 ,
& V_184 ) ;
if ( ! V_181 )
goto V_185;
V_181 = F_97 ( L_33 , 0 , V_182 ,
& V_186 ) ;
if ( ! V_181 )
goto V_187;
return 0 ;
V_187: F_98 ( L_32 , V_182 ) ;
V_185: F_98 ( L_31 , NULL ) ;
return - V_183 ;
}
static void F_99 ( void )
{
F_98 ( L_32 , V_182 ) ;
F_98 ( L_33 , V_182 ) ;
F_98 ( L_31 , NULL ) ;
}
static inline void F_69 ( void ) { }
static inline int F_95 ( void ) { return 0 ; }
static inline void F_99 ( void ) { }
static int F_100 ( char * V_147 , int V_188 ,
char V_145 , unsigned long * V_2 ,
unsigned int V_189 , unsigned int V_190 )
{
int V_113 = 0 , V_124 ;
V_113 += snprintf ( V_147 , V_3 ( V_188 , 0 ) , L_34 , V_145 ) ;
for ( V_124 = V_189 ; V_124 < V_190 ; V_124 ++ )
if ( V_2 [ F_101 ( V_124 ) ] & F_102 ( V_124 ) )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_188 - V_113 , 0 ) , L_35 , V_124 ) ;
return V_113 ;
}
static int F_103 ( char * V_147 , int V_188 , struct V_7 * V_130 ,
int V_191 )
{
int V_113 ;
V_113 = snprintf ( V_147 , V_3 ( V_188 , 0 ) ,
L_36 ,
V_130 -> V_130 . V_134 , V_130 -> V_130 . V_136 ,
V_130 -> V_130 . V_138 , V_130 -> V_130 . V_140 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'e' , V_130 -> V_10 , 0 , V_87 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'k' , V_130 -> V_36 , V_192 , V_37 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'r' , V_130 -> V_68 , 0 , V_69 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'a' , V_130 -> V_65 , 0 , V_66 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'm' , V_130 -> V_71 , 0 , V_72 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'l' , V_130 -> V_74 , 0 , V_75 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
's' , V_130 -> V_78 , 0 , V_79 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'f' , V_130 -> V_141 , 0 , V_142 ) ;
V_113 += F_100 ( V_147 + V_113 , V_188 - V_113 ,
'w' , V_130 -> V_61 , 0 , V_62 ) ;
if ( V_191 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_188 - V_113 , 0 ) , L_37 ) ;
return V_113 ;
}
static T_4 F_104 ( struct V_193 * V_8 ,
struct V_194 * V_195 ,
char * V_147 )
{
struct V_7 * V_130 = F_105 ( V_8 ) ;
T_4 V_113 ;
V_113 = F_103 ( V_147 , V_196 , V_130 , 1 ) ;
return F_106 ( int , V_113 , V_196 ) ;
}
static T_4 F_107 ( struct V_193 * V_8 ,
struct V_194 * V_195 ,
char * V_147 )
{
struct V_7 * V_7 = F_105 ( V_8 ) ;
int V_113 = F_108 ( V_147 , V_196 , V_7 -> V_172 ,
V_173 , true ) ;
return F_106 ( int , V_113 , V_196 ) ;
}
static int F_108 ( char * V_147 , int V_148 , unsigned long * V_167 ,
int V_3 , int V_191 )
{
int V_124 ;
int V_113 = 0 ;
bool V_150 = true ;
for ( V_124 = F_82 ( V_3 ) - 1 ; V_124 >= 0 ; V_124 -- ) {
V_113 += F_67 ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) ,
V_167 [ V_124 ] , V_150 ) ;
if ( V_113 ) {
V_150 = false ;
if ( V_124 > 0 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) , L_8 ) ;
}
}
if ( V_113 == 0 )
V_113 = snprintf ( V_147 , V_148 , L_38 , 0 ) ;
if ( V_191 )
V_113 += snprintf ( V_147 + V_113 , V_3 ( V_148 - V_113 , 0 ) , L_37 ) ;
return V_113 ;
}
static void F_109 ( struct V_193 * V_193 )
{
struct V_7 * V_8 = F_105 ( V_193 ) ;
F_110 ( V_8 ) ;
F_111 ( V_8 ) ;
F_88 ( V_8 -> V_48 ) ;
F_88 ( V_8 -> V_21 ) ;
F_88 ( V_8 ) ;
F_112 ( V_197 ) ;
}
static int F_113 ( struct V_198 * V_199 ,
const char * V_145 , unsigned long * V_167 , int V_3 )
{
int V_113 ;
if ( F_114 ( V_199 , L_39 , V_145 ) )
return - V_183 ;
V_113 = F_108 ( & V_199 -> V_147 [ V_199 -> V_200 - 1 ] ,
sizeof( V_199 -> V_147 ) - V_199 -> V_200 ,
V_167 , V_3 , false ) ;
if ( V_113 >= ( sizeof( V_199 -> V_147 ) - V_199 -> V_200 ) )
return - V_183 ;
V_199 -> V_200 += V_113 ;
return 0 ;
}
static int F_115 ( struct V_198 * V_199 ,
struct V_7 * V_8 )
{
int V_113 ;
if ( F_114 ( V_199 , L_40 ) )
return - V_183 ;
V_113 = F_103 ( & V_199 -> V_147 [ V_199 -> V_200 - 1 ] ,
sizeof( V_199 -> V_147 ) - V_199 -> V_200 ,
V_8 , 0 ) ;
if ( V_113 >= ( sizeof( V_199 -> V_147 ) - V_199 -> V_200 ) )
return - V_183 ;
V_199 -> V_200 += V_113 ;
return 0 ;
}
static int F_116 ( struct V_193 * V_193 , struct V_198 * V_199 )
{
struct V_7 * V_8 = F_105 ( V_193 ) ;
F_117 ( L_41 ,
V_8 -> V_130 . V_134 , V_8 -> V_130 . V_136 ,
V_8 -> V_130 . V_138 , V_8 -> V_130 . V_140 ) ;
if ( V_8 -> V_145 )
F_117 ( L_42 , V_8 -> V_145 ) ;
if ( V_8 -> V_170 )
F_117 ( L_43 , V_8 -> V_170 ) ;
if ( V_8 -> V_171 )
F_117 ( L_44 , V_8 -> V_171 ) ;
F_118 ( L_45 , V_8 -> V_172 , V_173 ) ;
F_118 ( L_46 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_118 ( L_47 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_118 ( L_48 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_118 ( L_49 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_118 ( L_50 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_118 ( L_51 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_118 ( L_52 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_118 ( L_53 , V_8 -> V_141 , V_142 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_118 ( L_54 , V_8 -> V_61 , V_62 ) ;
F_119 ( V_8 ) ;
return 0 ;
}
static void F_120 ( struct V_7 * V_8 , bool V_201 )
{
if ( ! V_8 -> V_29 )
return;
F_121 ( V_8 , V_202 , V_76 , V_201 ) ;
F_121 ( V_8 , V_203 , V_80 , V_201 ) ;
if ( V_201 && F_2 ( V_9 , V_8 -> V_10 ) ) {
V_8 -> V_29 ( V_8 , V_9 , V_12 , V_8 -> V_11 [ V_12 ] ) ;
V_8 -> V_29 ( V_8 , V_9 , V_13 , V_8 -> V_11 [ V_13 ] ) ;
}
}
void F_122 ( struct V_7 * V_8 )
{
unsigned long V_33 ;
F_45 ( & V_8 -> V_98 ) ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
F_120 ( V_8 , true ) ;
F_49 ( V_8 ) ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
F_38 ( & V_8 -> V_98 ) ;
}
static int F_123 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_105 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_49 ( V_7 ) ;
F_120 ( V_7 , false ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_124 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_105 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_120 ( V_7 , true ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_125 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_105 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_49 ( V_7 ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_126 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_105 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_120 ( V_7 , false ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static char * F_127 ( struct V_193 * V_8 , T_5 * V_204 )
{
return F_128 ( V_90 , L_55 , F_129 ( V_8 ) ) ;
}
struct V_7 * F_130 ( void )
{
static T_6 V_205 = F_131 ( - 1 ) ;
struct V_7 * V_8 ;
V_8 = F_132 ( sizeof( struct V_7 ) , V_90 ) ;
if ( V_8 ) {
V_8 -> V_8 . type = & V_206 ;
V_8 -> V_8 . V_207 = & V_208 ;
F_133 ( & V_8 -> V_8 ) ;
F_134 ( & V_8 -> V_98 ) ;
F_135 ( & V_8 -> V_34 ) ;
F_136 ( & V_8 -> V_14 ) ;
F_137 ( & V_8 -> V_209 ) ;
F_137 ( & V_8 -> V_168 ) ;
F_138 ( & V_8 -> V_8 , L_56 ,
( unsigned long ) F_139 ( & V_205 ) ) ;
F_140 ( V_197 ) ;
}
return V_8 ;
}
static int F_141 ( struct V_193 * V_8 , void * V_210 , void * V_15 )
{
struct V_211 * V_212 = V_210 ;
return V_212 -> V_213 == V_15 ;
}
static void F_142 ( struct V_193 * V_8 , void * V_210 )
{
struct V_211 * V_212 = V_210 ;
struct V_7 * V_213 = V_212 -> V_213 ;
F_143 ( V_8 , L_57 ,
V_91 , F_129 ( & V_213 -> V_8 ) ) ;
F_144 ( V_213 ) ;
}
struct V_7 * F_145 ( struct V_193 * V_8 )
{
struct V_7 * V_213 ;
struct V_211 * V_212 ;
V_212 = F_146 ( F_142 ,
sizeof( struct V_211 ) , V_90 ) ;
if ( ! V_212 )
return NULL ;
V_213 = F_130 () ;
if ( ! V_213 ) {
F_147 ( V_212 ) ;
return NULL ;
}
V_213 -> V_8 . V_214 = V_8 ;
V_213 -> V_215 = true ;
V_212 -> V_213 = V_213 ;
F_148 ( V_8 , V_212 ) ;
return V_213 ;
}
void F_149 ( struct V_7 * V_8 )
{
if ( V_8 ) {
if ( V_8 -> V_215 )
F_150 ( F_151 ( V_8 -> V_8 . V_214 ,
F_142 ,
F_141 ,
V_8 ) ) ;
F_144 ( V_8 ) ;
}
}
void F_152 ( struct V_7 * V_8 , unsigned int type , unsigned int V_1 )
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
F_153 () ;
return;
}
F_34 ( type , V_8 -> V_10 ) ;
}
static unsigned int F_154 ( struct V_7 * V_8 )
{
int V_216 ;
int V_124 ;
unsigned int V_28 ;
if ( V_8 -> V_41 ) {
V_216 = V_8 -> V_41 -> V_45 ;
} else if ( F_2 ( V_217 , V_8 -> V_65 ) ) {
V_216 = V_8 -> V_48 [ V_217 ] . V_96 -
V_8 -> V_48 [ V_217 ] . V_95 + 1 ,
V_216 = F_155 ( V_216 , 2 , 32 ) ;
} else if ( F_2 ( V_218 , V_8 -> V_65 ) ) {
V_216 = 2 ;
} else {
V_216 = 0 ;
}
V_28 = V_216 + 1 ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_50 (i, dev->absbit, ABS_CNT)
V_28 += F_156 ( V_124 ) ? V_216 : 1 ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
V_28 += F_157 ( V_8 -> V_68 , V_219 ) ;
V_28 += 7 ;
return V_28 ;
}
static void F_158 ( struct V_7 * V_8 )
{
F_159 ( V_8 , V_220 , V_35 ) ;
F_159 ( V_8 , V_221 , V_222 ) ;
F_159 ( V_8 , ABS , abs ) ;
F_159 ( V_8 , V_223 , V_224 ) ;
F_159 ( V_8 , V_202 , V_76 ) ;
F_159 ( V_8 , V_203 , V_80 ) ;
F_159 ( V_8 , V_225 , V_226 ) ;
F_159 ( V_8 , V_227 , V_63 ) ;
}
static void F_160 ( struct V_7 * V_8 )
{
struct V_18 * V_19 , * V_228 ;
F_51 ( V_8 ) ;
F_45 ( & V_164 ) ;
F_161 (handle, next, &dev->h_list, d_node)
V_19 -> V_24 -> V_229 ( V_19 ) ;
F_150 ( ! F_162 ( & V_8 -> V_209 ) ) ;
F_163 ( & V_8 -> V_14 ) ;
F_164 ( & V_8 -> V_168 ) ;
F_69 () ;
F_38 ( & V_164 ) ;
F_165 ( & V_8 -> V_8 ) ;
}
static void F_166 ( struct V_193 * V_8 , void * V_210 )
{
struct V_211 * V_212 = V_210 ;
struct V_7 * V_213 = V_212 -> V_213 ;
F_143 ( V_8 , L_59 ,
V_91 , F_129 ( & V_213 -> V_8 ) ) ;
F_160 ( V_213 ) ;
}
void F_167 ( struct V_7 * V_8 , int V_230 , int V_231 )
{
V_8 -> V_14 . V_15 = ( unsigned long ) V_8 ;
V_8 -> V_14 . V_232 = F_18 ;
V_8 -> V_11 [ V_13 ] = V_230 ;
V_8 -> V_11 [ V_12 ] = V_231 ;
}
int F_168 ( struct V_7 * V_8 )
{
struct V_211 * V_212 = NULL ;
struct V_23 * V_24 ;
unsigned int V_233 ;
const char * V_169 ;
int error ;
if ( V_8 -> V_215 ) {
V_212 = F_146 ( F_166 ,
sizeof( struct V_211 ) , V_90 ) ;
if ( ! V_212 )
return - V_183 ;
V_212 -> V_213 = V_8 ;
}
F_34 ( V_54 , V_8 -> V_10 ) ;
F_58 ( V_128 , V_8 -> V_36 ) ;
F_158 ( V_8 ) ;
V_233 = F_154 ( V_8 ) ;
if ( V_8 -> V_234 < V_233 )
V_8 -> V_234 = V_233 ;
V_8 -> V_86 = V_8 -> V_234 + 2 ;
V_8 -> V_21 = F_31 ( V_8 -> V_86 , sizeof( * V_8 -> V_21 ) , V_90 ) ;
if ( ! V_8 -> V_21 ) {
error = - V_183 ;
goto V_235;
}
if ( ! V_8 -> V_11 [ V_13 ] && ! V_8 -> V_11 [ V_12 ] )
F_167 ( V_8 , 250 , 33 ) ;
if ( ! V_8 -> V_126 )
V_8 -> V_126 = F_56 ;
if ( ! V_8 -> V_127 )
V_8 -> V_127 = F_57 ;
error = F_169 ( & V_8 -> V_8 ) ;
if ( error )
goto V_236;
V_169 = F_87 ( & V_8 -> V_8 . V_146 , V_90 ) ;
F_170 ( L_60 ,
V_8 -> V_145 ? V_8 -> V_145 : L_61 ,
V_169 ? V_169 : L_62 ) ;
F_88 ( V_169 ) ;
error = F_36 ( & V_164 ) ;
if ( error )
goto V_237;
F_171 ( & V_8 -> V_168 , & V_166 ) ;
F_43 (handler, &input_handler_list, node)
F_64 ( V_8 , V_24 ) ;
F_69 () ;
F_38 ( & V_164 ) ;
if ( V_8 -> V_215 ) {
F_143 ( V_8 -> V_8 . V_214 , L_63 ,
V_91 , F_129 ( & V_8 -> V_8 ) ) ;
F_148 ( V_8 -> V_8 . V_214 , V_212 ) ;
}
return 0 ;
V_237:
F_165 ( & V_8 -> V_8 ) ;
V_236:
F_88 ( V_8 -> V_21 ) ;
V_8 -> V_21 = NULL ;
V_235:
F_147 ( V_212 ) ;
return error ;
}
void F_172 ( struct V_7 * V_8 )
{
if ( V_8 -> V_215 ) {
F_150 ( F_151 ( V_8 -> V_8 . V_214 ,
F_166 ,
F_141 ,
V_8 ) ) ;
F_160 ( V_8 ) ;
} else {
F_160 ( V_8 ) ;
F_144 ( V_8 ) ;
}
}
int F_173 ( struct V_23 * V_24 )
{
struct V_7 * V_8 ;
int error ;
error = F_36 ( & V_164 ) ;
if ( error )
return error ;
F_137 ( & V_24 -> V_209 ) ;
F_171 ( & V_24 -> V_168 , & V_176 ) ;
F_43 (dev, &input_dev_list, node)
F_64 ( V_8 , V_24 ) ;
F_69 () ;
F_38 ( & V_164 ) ;
return 0 ;
}
void F_174 ( struct V_23 * V_24 )
{
struct V_18 * V_19 , * V_228 ;
F_45 ( & V_164 ) ;
F_161 (handle, next, &handler->h_list, h_node)
V_24 -> V_229 ( V_19 ) ;
F_150 ( ! F_162 ( & V_24 -> V_209 ) ) ;
F_164 ( & V_24 -> V_168 ) ;
F_69 () ;
F_38 ( & V_164 ) ;
}
int F_175 ( struct V_23 * V_24 , void * V_15 ,
int (* F_176)( struct V_18 * , void * ) )
{
struct V_18 * V_19 ;
int V_97 = 0 ;
F_11 () ;
F_13 (handle, &handler->h_list, h_node) {
V_97 = F_176 ( V_19 , V_15 ) ;
if ( V_97 )
break;
}
F_14 () ;
return V_97 ;
}
int F_177 ( struct V_18 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_7 * V_8 = V_19 -> V_8 ;
int error ;
error = F_36 ( & V_8 -> V_98 ) ;
if ( error )
return error ;
if ( V_24 -> V_27 )
F_178 ( & V_19 -> V_238 , & V_8 -> V_209 ) ;
else
F_179 ( & V_19 -> V_238 , & V_8 -> V_209 ) ;
F_38 ( & V_8 -> V_98 ) ;
F_179 ( & V_19 -> V_239 , & V_24 -> V_209 ) ;
if ( V_24 -> V_102 )
V_24 -> V_102 ( V_19 ) ;
return 0 ;
}
void F_180 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_181 ( & V_19 -> V_239 ) ;
F_45 ( & V_8 -> V_98 ) ;
F_181 ( & V_19 -> V_238 ) ;
F_38 ( & V_8 -> V_98 ) ;
F_42 () ;
}
int F_182 ( int V_240 , unsigned int V_241 ,
bool V_242 )
{
if ( V_240 >= 0 ) {
int V_178 = F_183 ( & V_243 ,
V_240 ,
V_240 + V_241 ,
V_90 ) ;
if ( V_178 >= 0 || ! V_242 )
return V_178 ;
}
return F_183 ( & V_243 ,
V_244 , V_245 ,
V_90 ) ;
}
void F_184 ( unsigned int V_178 )
{
F_185 ( & V_243 , V_178 ) ;
}
static int T_3 F_186 ( void )
{
int V_246 ;
V_246 = F_187 ( & V_208 ) ;
if ( V_246 ) {
F_65 ( L_64 ) ;
return V_246 ;
}
V_246 = F_95 () ;
if ( V_246 )
goto V_185;
V_246 = F_188 ( F_189 ( V_247 , 0 ) ,
V_245 , L_65 ) ;
if ( V_246 ) {
F_65 ( L_66 , V_247 ) ;
goto V_187;
}
return 0 ;
V_187: F_99 () ;
V_185: F_190 ( & V_208 ) ;
return V_246 ;
}
static void T_7 F_191 ( void )
{
F_99 () ;
F_192 ( F_189 ( V_247 , 0 ) ,
V_245 ) ;
F_190 ( & V_208 ) ;
}
