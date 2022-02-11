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
int V_1 ;
if ( F_1 ( V_32 , V_8 -> V_10 , V_87 ) ) {
for ( V_1 = 0 ; V_1 <= V_37 ; V_1 ++ ) {
if ( F_1 ( V_1 , V_8 -> V_36 , V_37 ) &&
F_50 ( V_1 , V_8 -> V_35 ) ) {
F_16 ( V_8 , V_32 , V_1 , 0 ) ;
}
}
F_16 ( V_8 , V_54 , V_57 , 1 ) ;
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
int F_54 ( const struct V_109 * V_110 ,
unsigned int * V_111 )
{
switch ( V_110 -> V_112 ) {
case 1 :
* V_111 = * ( ( V_113 * ) V_110 -> V_111 ) ;
break;
case 2 :
* V_111 = * ( ( V_114 * ) V_110 -> V_111 ) ;
break;
case 4 :
* V_111 = * ( ( V_115 * ) V_110 -> V_111 ) ;
break;
default:
return - V_116 ;
}
return 0 ;
}
static unsigned int F_55 ( struct V_7 * V_8 ,
unsigned int V_117 )
{
switch ( V_8 -> V_118 ) {
case 1 :
return ( ( V_113 * ) V_8 -> V_119 ) [ V_117 ] ;
case 2 :
return ( ( V_114 * ) V_8 -> V_119 ) [ V_117 ] ;
default:
return ( ( V_115 * ) V_8 -> V_119 ) [ V_117 ] ;
}
}
static int F_56 ( struct V_7 * V_8 ,
struct V_109 * V_110 )
{
unsigned int V_117 ;
int error ;
if ( ! V_8 -> V_118 )
return - V_116 ;
if ( V_110 -> V_33 & V_120 )
V_117 = V_110 -> V_117 ;
else {
error = F_54 ( V_110 , & V_117 ) ;
if ( error )
return error ;
}
if ( V_117 >= V_8 -> V_121 )
return - V_116 ;
V_110 -> V_119 = F_55 ( V_8 , V_117 ) ;
V_110 -> V_117 = V_117 ;
V_110 -> V_112 = sizeof( V_117 ) ;
memcpy ( V_110 -> V_111 , & V_117 , sizeof( V_117 ) ) ;
return 0 ;
}
static int F_57 ( struct V_7 * V_8 ,
const struct V_109 * V_110 ,
unsigned int * V_122 )
{
unsigned int V_117 ;
int error ;
int V_123 ;
if ( ! V_8 -> V_118 )
return - V_116 ;
if ( V_110 -> V_33 & V_120 ) {
V_117 = V_110 -> V_117 ;
} else {
error = F_54 ( V_110 , & V_117 ) ;
if ( error )
return error ;
}
if ( V_117 >= V_8 -> V_121 )
return - V_116 ;
if ( V_8 -> V_118 < sizeof( V_110 -> V_119 ) &&
( V_110 -> V_119 >> ( V_8 -> V_118 * 8 ) ) )
return - V_116 ;
switch ( V_8 -> V_118 ) {
case 1 : {
V_113 * V_124 = ( V_113 * ) V_8 -> V_119 ;
* V_122 = V_124 [ V_117 ] ;
V_124 [ V_117 ] = V_110 -> V_119 ;
break;
}
case 2 : {
V_114 * V_124 = ( V_114 * ) V_8 -> V_119 ;
* V_122 = V_124 [ V_117 ] ;
V_124 [ V_117 ] = V_110 -> V_119 ;
break;
}
default: {
V_115 * V_124 = ( V_115 * ) V_8 -> V_119 ;
* V_122 = V_124 [ V_117 ] ;
V_124 [ V_117 ] = V_110 -> V_119 ;
break;
}
}
F_58 ( * V_122 , V_8 -> V_36 ) ;
F_34 ( V_110 -> V_119 , V_8 -> V_36 ) ;
for ( V_123 = 0 ; V_123 < V_8 -> V_121 ; V_123 ++ ) {
if ( F_55 ( V_8 , V_123 ) == * V_122 ) {
F_34 ( * V_122 , V_8 -> V_36 ) ;
break;
}
}
return 0 ;
}
int F_59 ( struct V_7 * V_8 , struct V_109 * V_110 )
{
unsigned long V_33 ;
int V_97 ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
V_97 = V_8 -> V_125 ( V_8 , V_110 ) ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
return V_97 ;
}
int F_60 ( struct V_7 * V_8 ,
const struct V_109 * V_110 )
{
unsigned long V_33 ;
unsigned int V_122 ;
int V_97 ;
if ( V_110 -> V_119 > V_37 )
return - V_116 ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
V_97 = V_8 -> V_126 ( V_8 , V_110 , & V_122 ) ;
if ( V_97 )
goto V_100;
F_58 ( V_127 , V_8 -> V_36 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) &&
! F_1 ( V_122 , V_8 -> V_36 , V_37 ) &&
F_50 ( V_122 , V_8 -> V_35 ) ) {
struct V_20 V_21 [] = {
{ V_32 , V_122 , 0 } ,
V_38
} ;
F_10 ( V_8 , V_21 , F_17 ( V_21 ) ) ;
}
V_100:
F_20 ( & V_8 -> V_34 , V_33 ) ;
return V_97 ;
}
static const struct V_128 * F_61 ( struct V_23 * V_24 ,
struct V_7 * V_8 )
{
const struct V_128 * V_129 ;
for ( V_129 = V_24 -> V_130 ; V_129 -> V_33 || V_129 -> V_131 ; V_129 ++ ) {
if ( V_129 -> V_33 & V_132 )
if ( V_129 -> V_133 != V_8 -> V_129 . V_133 )
continue;
if ( V_129 -> V_33 & V_134 )
if ( V_129 -> V_135 != V_8 -> V_129 . V_135 )
continue;
if ( V_129 -> V_33 & V_136 )
if ( V_129 -> V_137 != V_8 -> V_129 . V_137 )
continue;
if ( V_129 -> V_33 & V_138 )
if ( V_129 -> V_139 != V_8 -> V_129 . V_139 )
continue;
if ( ! F_62 ( V_129 -> V_10 , V_8 -> V_10 , V_87 ) )
continue;
if ( ! F_62 ( V_129 -> V_36 , V_8 -> V_36 , V_37 ) )
continue;
if ( ! F_62 ( V_129 -> V_68 , V_8 -> V_68 , V_69 ) )
continue;
if ( ! F_62 ( V_129 -> V_65 , V_8 -> V_65 , V_66 ) )
continue;
if ( ! F_62 ( V_129 -> V_71 , V_8 -> V_71 , V_72 ) )
continue;
if ( ! F_62 ( V_129 -> V_74 , V_8 -> V_74 , V_75 ) )
continue;
if ( ! F_62 ( V_129 -> V_78 , V_8 -> V_78 , V_79 ) )
continue;
if ( ! F_62 ( V_129 -> V_140 , V_8 -> V_140 , V_141 ) )
continue;
if ( ! F_62 ( V_129 -> V_61 , V_8 -> V_61 , V_62 ) )
continue;
if ( ! V_24 -> V_142 || V_24 -> V_142 ( V_24 , V_8 ) )
return V_129 ;
}
return NULL ;
}
static int F_63 ( struct V_7 * V_8 , struct V_23 * V_24 )
{
const struct V_128 * V_129 ;
int error ;
V_129 = F_61 ( V_24 , V_8 ) ;
if ( ! V_129 )
return - V_104 ;
error = V_24 -> V_143 ( V_24 , V_8 , V_129 ) ;
if ( error && error != - V_104 )
F_64 ( L_2 ,
V_24 -> V_144 , F_65 ( & V_8 -> V_8 . V_145 ) , error ) ;
return error ;
}
static int F_66 ( char * V_146 , int V_147 ,
unsigned long V_148 , bool V_149 )
{
int V_112 = 0 ;
if ( V_150 ) {
V_115 V_151 = V_148 >> 32 ;
if ( V_151 || ! V_149 )
V_112 += snprintf ( V_146 , V_147 , L_3 , V_151 ) ;
V_151 = V_148 & 0xffffffffUL ;
if ( V_151 || ! V_149 || V_112 )
V_112 += snprintf ( V_146 + V_112 , V_3 ( V_147 - V_112 , 0 ) ,
L_4 , V_151 ) ;
} else {
if ( V_148 || ! V_149 )
V_112 += snprintf ( V_146 , V_147 , L_5 , V_148 ) ;
}
return V_112 ;
}
static int F_66 ( char * V_146 , int V_147 ,
unsigned long V_148 , bool V_149 )
{
return V_148 || ! V_149 ?
snprintf ( V_146 , V_147 , L_5 , V_148 ) : 0 ;
}
static inline void F_67 ( void )
{
V_152 ++ ;
F_68 ( & V_153 ) ;
}
static unsigned int F_69 ( struct V_106 * V_106 , T_1 * V_154 )
{
F_70 ( V_106 , & V_153 , V_154 ) ;
if ( V_106 -> V_155 != V_152 ) {
V_106 -> V_155 = V_152 ;
return V_156 | V_157 ;
}
return 0 ;
}
static void * F_71 ( struct V_158 * V_159 , T_2 * V_160 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
int error ;
F_72 ( sizeof( union V_161 ) != sizeof( V_159 -> V_163 ) ) ;
error = F_36 ( & V_164 ) ;
if ( error ) {
V_162 -> V_165 = false ;
return F_73 ( error ) ;
}
V_162 -> V_165 = true ;
return F_74 ( & V_166 , * V_160 ) ;
}
static void * F_75 ( struct V_158 * V_159 , void * V_26 , T_2 * V_160 )
{
return F_76 ( V_26 , & V_166 , V_160 ) ;
}
static void F_77 ( struct V_158 * V_159 , void * V_26 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
if ( V_162 -> V_165 )
F_38 ( & V_164 ) ;
}
static void F_78 ( struct V_158 * V_159 , const char * V_144 ,
unsigned long * V_167 , int V_3 )
{
int V_123 ;
bool V_149 = true ;
char V_146 [ 18 ] ;
F_79 ( V_159 , L_6 , V_144 ) ;
for ( V_123 = F_80 ( V_3 ) - 1 ; V_123 >= 0 ; V_123 -- ) {
if ( F_66 ( V_146 , sizeof( V_146 ) ,
V_167 [ V_123 ] , V_149 ) ) {
V_149 = false ;
F_79 ( V_159 , L_7 , V_146 , V_123 > 0 ? L_8 : L_9 ) ;
}
}
if ( V_149 )
F_81 ( V_159 , L_10 ) ;
F_82 ( V_159 , '\n' ) ;
}
static int F_83 ( struct V_158 * V_159 , void * V_26 )
{
struct V_7 * V_8 = F_84 ( V_26 , struct V_7 , V_168 ) ;
const char * V_169 = F_85 ( & V_8 -> V_8 . V_145 , V_90 ) ;
struct V_18 * V_19 ;
F_79 ( V_159 , L_11 ,
V_8 -> V_129 . V_133 , V_8 -> V_129 . V_135 , V_8 -> V_129 . V_137 , V_8 -> V_129 . V_139 ) ;
F_79 ( V_159 , L_12 , V_8 -> V_144 ? V_8 -> V_144 : L_9 ) ;
F_79 ( V_159 , L_13 , V_8 -> V_170 ? V_8 -> V_170 : L_9 ) ;
F_79 ( V_159 , L_14 , V_169 ? V_169 : L_9 ) ;
F_79 ( V_159 , L_15 , V_8 -> V_171 ? V_8 -> V_171 : L_9 ) ;
F_79 ( V_159 , L_16 ) ;
F_43 (handle, &dev->h_list, d_node)
F_79 ( V_159 , L_17 , V_19 -> V_144 ) ;
F_82 ( V_159 , '\n' ) ;
F_78 ( V_159 , L_18 , V_8 -> V_172 , V_173 ) ;
F_78 ( V_159 , L_19 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_78 ( V_159 , L_20 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_78 ( V_159 , L_21 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_78 ( V_159 , L_22 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_78 ( V_159 , L_23 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_78 ( V_159 , L_24 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_78 ( V_159 , L_25 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_78 ( V_159 , L_26 , V_8 -> V_140 , V_141 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_78 ( V_159 , L_27 , V_8 -> V_61 , V_62 ) ;
F_82 ( V_159 , '\n' ) ;
F_86 ( V_169 ) ;
return 0 ;
}
static int F_87 ( struct V_174 * V_174 , struct V_106 * V_106 )
{
return F_88 ( V_106 , & V_175 ) ;
}
static void * F_89 ( struct V_158 * V_159 , T_2 * V_160 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
int error ;
F_72 ( sizeof( union V_161 ) != sizeof( V_159 -> V_163 ) ) ;
error = F_36 ( & V_164 ) ;
if ( error ) {
V_162 -> V_165 = false ;
return F_73 ( error ) ;
}
V_162 -> V_165 = true ;
V_162 -> V_160 = * V_160 ;
return F_74 ( & V_176 , * V_160 ) ;
}
static void * F_90 ( struct V_158 * V_159 , void * V_26 , T_2 * V_160 )
{
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
V_162 -> V_160 = * V_160 + 1 ;
return F_76 ( V_26 , & V_176 , V_160 ) ;
}
static int F_91 ( struct V_158 * V_159 , void * V_26 )
{
struct V_23 * V_24 = F_84 ( V_26 , struct V_23 , V_168 ) ;
union V_161 * V_162 = (union V_161 * ) & V_159 -> V_163 ;
F_79 ( V_159 , L_28 , V_162 -> V_160 , V_24 -> V_144 ) ;
if ( V_24 -> V_27 )
F_81 ( V_159 , L_29 ) ;
if ( V_24 -> V_177 )
F_79 ( V_159 , L_30 , V_24 -> V_178 ) ;
F_82 ( V_159 , '\n' ) ;
return 0 ;
}
static int F_92 ( struct V_174 * V_174 , struct V_106 * V_106 )
{
return F_88 ( V_106 , & V_179 ) ;
}
static int T_3 F_93 ( void )
{
struct V_180 * V_181 ;
V_182 = F_94 ( L_31 , NULL ) ;
if ( ! V_182 )
return - V_183 ;
V_181 = F_95 ( L_32 , 0 , V_182 ,
& V_184 ) ;
if ( ! V_181 )
goto V_185;
V_181 = F_95 ( L_33 , 0 , V_182 ,
& V_186 ) ;
if ( ! V_181 )
goto V_187;
return 0 ;
V_187: F_96 ( L_32 , V_182 ) ;
V_185: F_96 ( L_31 , NULL ) ;
return - V_183 ;
}
static void F_97 ( void )
{
F_96 ( L_32 , V_182 ) ;
F_96 ( L_33 , V_182 ) ;
F_96 ( L_31 , NULL ) ;
}
static inline void F_67 ( void ) { }
static inline int F_93 ( void ) { return 0 ; }
static inline void F_97 ( void ) { }
static int F_98 ( char * V_146 , int V_188 ,
char V_144 , unsigned long * V_2 ,
unsigned int V_189 , unsigned int V_190 )
{
int V_112 = 0 , V_123 ;
V_112 += snprintf ( V_146 , V_3 ( V_188 , 0 ) , L_34 , V_144 ) ;
for ( V_123 = V_189 ; V_123 < V_190 ; V_123 ++ )
if ( V_2 [ F_99 ( V_123 ) ] & F_100 ( V_123 ) )
V_112 += snprintf ( V_146 + V_112 , V_3 ( V_188 - V_112 , 0 ) , L_35 , V_123 ) ;
return V_112 ;
}
static int F_101 ( char * V_146 , int V_188 , struct V_7 * V_129 ,
int V_191 )
{
int V_112 ;
V_112 = snprintf ( V_146 , V_3 ( V_188 , 0 ) ,
L_36 ,
V_129 -> V_129 . V_133 , V_129 -> V_129 . V_135 ,
V_129 -> V_129 . V_137 , V_129 -> V_129 . V_139 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'e' , V_129 -> V_10 , 0 , V_87 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'k' , V_129 -> V_36 , V_192 , V_37 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'r' , V_129 -> V_68 , 0 , V_69 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'a' , V_129 -> V_65 , 0 , V_66 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'm' , V_129 -> V_71 , 0 , V_72 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'l' , V_129 -> V_74 , 0 , V_75 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
's' , V_129 -> V_78 , 0 , V_79 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'f' , V_129 -> V_140 , 0 , V_141 ) ;
V_112 += F_98 ( V_146 + V_112 , V_188 - V_112 ,
'w' , V_129 -> V_61 , 0 , V_62 ) ;
if ( V_191 )
V_112 += snprintf ( V_146 + V_112 , V_3 ( V_188 - V_112 , 0 ) , L_37 ) ;
return V_112 ;
}
static T_4 F_102 ( struct V_193 * V_8 ,
struct V_194 * V_195 ,
char * V_146 )
{
struct V_7 * V_129 = F_103 ( V_8 ) ;
T_4 V_112 ;
V_112 = F_101 ( V_146 , V_196 , V_129 , 1 ) ;
return F_104 ( int , V_112 , V_196 ) ;
}
static T_4 F_105 ( struct V_193 * V_8 ,
struct V_194 * V_195 ,
char * V_146 )
{
struct V_7 * V_7 = F_103 ( V_8 ) ;
int V_112 = F_106 ( V_146 , V_196 , V_7 -> V_172 ,
V_173 , true ) ;
return F_104 ( int , V_112 , V_196 ) ;
}
static int F_106 ( char * V_146 , int V_147 , unsigned long * V_167 ,
int V_3 , int V_191 )
{
int V_123 ;
int V_112 = 0 ;
bool V_149 = true ;
for ( V_123 = F_80 ( V_3 ) - 1 ; V_123 >= 0 ; V_123 -- ) {
V_112 += F_66 ( V_146 + V_112 , V_3 ( V_147 - V_112 , 0 ) ,
V_167 [ V_123 ] , V_149 ) ;
if ( V_112 ) {
V_149 = false ;
if ( V_123 > 0 )
V_112 += snprintf ( V_146 + V_112 , V_3 ( V_147 - V_112 , 0 ) , L_8 ) ;
}
}
if ( V_112 == 0 )
V_112 = snprintf ( V_146 , V_147 , L_38 , 0 ) ;
if ( V_191 )
V_112 += snprintf ( V_146 + V_112 , V_3 ( V_147 - V_112 , 0 ) , L_37 ) ;
return V_112 ;
}
static void F_107 ( struct V_193 * V_193 )
{
struct V_7 * V_8 = F_103 ( V_193 ) ;
F_108 ( V_8 ) ;
F_109 ( V_8 ) ;
F_86 ( V_8 -> V_48 ) ;
F_86 ( V_8 -> V_21 ) ;
F_86 ( V_8 ) ;
F_110 ( V_197 ) ;
}
static int F_111 ( struct V_198 * V_199 ,
const char * V_144 , unsigned long * V_167 , int V_3 )
{
int V_112 ;
if ( F_112 ( V_199 , L_39 , V_144 ) )
return - V_183 ;
V_112 = F_106 ( & V_199 -> V_146 [ V_199 -> V_200 - 1 ] ,
sizeof( V_199 -> V_146 ) - V_199 -> V_200 ,
V_167 , V_3 , false ) ;
if ( V_112 >= ( sizeof( V_199 -> V_146 ) - V_199 -> V_200 ) )
return - V_183 ;
V_199 -> V_200 += V_112 ;
return 0 ;
}
static int F_113 ( struct V_198 * V_199 ,
struct V_7 * V_8 )
{
int V_112 ;
if ( F_112 ( V_199 , L_40 ) )
return - V_183 ;
V_112 = F_101 ( & V_199 -> V_146 [ V_199 -> V_200 - 1 ] ,
sizeof( V_199 -> V_146 ) - V_199 -> V_200 ,
V_8 , 0 ) ;
if ( V_112 >= ( sizeof( V_199 -> V_146 ) - V_199 -> V_200 ) )
return - V_183 ;
V_199 -> V_200 += V_112 ;
return 0 ;
}
static int F_114 ( struct V_193 * V_193 , struct V_198 * V_199 )
{
struct V_7 * V_8 = F_103 ( V_193 ) ;
F_115 ( L_41 ,
V_8 -> V_129 . V_133 , V_8 -> V_129 . V_135 ,
V_8 -> V_129 . V_137 , V_8 -> V_129 . V_139 ) ;
if ( V_8 -> V_144 )
F_115 ( L_42 , V_8 -> V_144 ) ;
if ( V_8 -> V_170 )
F_115 ( L_43 , V_8 -> V_170 ) ;
if ( V_8 -> V_171 )
F_115 ( L_44 , V_8 -> V_171 ) ;
F_116 ( L_45 , V_8 -> V_172 , V_173 ) ;
F_116 ( L_46 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_116 ( L_47 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_116 ( L_48 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_116 ( L_49 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_116 ( L_50 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_116 ( L_51 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_116 ( L_52 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_116 ( L_53 , V_8 -> V_140 , V_141 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_116 ( L_54 , V_8 -> V_61 , V_62 ) ;
F_117 ( V_8 ) ;
return 0 ;
}
static void F_118 ( struct V_7 * V_8 , bool V_201 )
{
if ( ! V_8 -> V_29 )
return;
F_119 ( V_8 , V_202 , V_76 , V_201 ) ;
F_119 ( V_8 , V_203 , V_80 , V_201 ) ;
if ( V_201 && F_2 ( V_9 , V_8 -> V_10 ) ) {
V_8 -> V_29 ( V_8 , V_9 , V_12 , V_8 -> V_11 [ V_12 ] ) ;
V_8 -> V_29 ( V_8 , V_9 , V_13 , V_8 -> V_11 [ V_13 ] ) ;
}
}
void F_120 ( struct V_7 * V_8 )
{
unsigned long V_33 ;
F_45 ( & V_8 -> V_98 ) ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
F_118 ( V_8 , true ) ;
F_49 ( V_8 ) ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
F_38 ( & V_8 -> V_98 ) ;
}
static int F_121 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_103 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_49 ( V_7 ) ;
F_118 ( V_7 , false ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_122 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_103 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_118 ( V_7 , true ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_123 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_103 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_49 ( V_7 ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static int F_124 ( struct V_193 * V_8 )
{
struct V_7 * V_7 = F_103 ( V_8 ) ;
F_52 ( & V_7 -> V_34 ) ;
F_118 ( V_7 , false ) ;
F_53 ( & V_7 -> V_34 ) ;
return 0 ;
}
static char * F_125 ( struct V_193 * V_8 , T_5 * V_204 )
{
return F_126 ( V_90 , L_55 , F_127 ( V_8 ) ) ;
}
struct V_7 * F_128 ( void )
{
static T_6 V_205 = F_129 ( - 1 ) ;
struct V_7 * V_8 ;
V_8 = F_130 ( sizeof( struct V_7 ) , V_90 ) ;
if ( V_8 ) {
V_8 -> V_8 . type = & V_206 ;
V_8 -> V_8 . V_207 = & V_208 ;
F_131 ( & V_8 -> V_8 ) ;
F_132 ( & V_8 -> V_98 ) ;
F_133 ( & V_8 -> V_34 ) ;
F_134 ( & V_8 -> V_14 ) ;
F_135 ( & V_8 -> V_209 ) ;
F_135 ( & V_8 -> V_168 ) ;
F_136 ( & V_8 -> V_8 , L_56 ,
( unsigned long ) F_137 ( & V_205 ) ) ;
F_138 ( V_197 ) ;
}
return V_8 ;
}
static int F_139 ( struct V_193 * V_8 , void * V_210 , void * V_15 )
{
struct V_211 * V_212 = V_210 ;
return V_212 -> V_213 == V_15 ;
}
static void F_140 ( struct V_193 * V_8 , void * V_210 )
{
struct V_211 * V_212 = V_210 ;
struct V_7 * V_213 = V_212 -> V_213 ;
F_141 ( V_8 , L_57 ,
V_91 , F_127 ( & V_213 -> V_8 ) ) ;
F_142 ( V_213 ) ;
}
struct V_7 * F_143 ( struct V_193 * V_8 )
{
struct V_7 * V_213 ;
struct V_211 * V_212 ;
V_212 = F_144 ( F_140 ,
sizeof( struct V_211 ) , V_90 ) ;
if ( ! V_212 )
return NULL ;
V_213 = F_128 () ;
if ( ! V_213 ) {
F_145 ( V_212 ) ;
return NULL ;
}
V_213 -> V_8 . V_214 = V_8 ;
V_213 -> V_215 = true ;
V_212 -> V_213 = V_213 ;
F_146 ( V_8 , V_212 ) ;
return V_213 ;
}
void F_147 ( struct V_7 * V_8 )
{
if ( V_8 ) {
if ( V_8 -> V_215 )
F_148 ( F_149 ( V_8 -> V_8 . V_214 ,
F_140 ,
F_139 ,
V_8 ) ) ;
F_142 ( V_8 ) ;
}
}
void F_150 ( struct V_7 * V_8 , unsigned int type , unsigned int V_1 )
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
F_34 ( V_1 , V_8 -> V_140 ) ;
break;
case V_83 :
break;
default:
F_64 ( L_58 ,
type , V_1 ) ;
F_151 () ;
return;
}
F_34 ( type , V_8 -> V_10 ) ;
}
static unsigned int F_152 ( struct V_7 * V_8 )
{
int V_216 ;
int V_123 ;
unsigned int V_28 ;
if ( V_8 -> V_41 ) {
V_216 = V_8 -> V_41 -> V_45 ;
} else if ( F_2 ( V_217 , V_8 -> V_65 ) ) {
V_216 = V_8 -> V_48 [ V_217 ] . V_96 -
V_8 -> V_48 [ V_217 ] . V_95 + 1 ,
V_216 = F_153 ( V_216 , 2 , 32 ) ;
} else if ( F_2 ( V_218 , V_8 -> V_65 ) ) {
V_216 = 2 ;
} else {
V_216 = 0 ;
}
V_28 = V_216 + 1 ;
if ( F_2 ( V_64 , V_8 -> V_10 ) ) {
for ( V_123 = 0 ; V_123 < V_88 ; V_123 ++ ) {
if ( F_2 ( V_123 , V_8 -> V_65 ) ) {
if ( F_154 ( V_123 ) )
V_28 += V_216 ;
else
V_28 ++ ;
}
}
}
if ( F_2 ( V_67 , V_8 -> V_10 ) ) {
for ( V_123 = 0 ; V_123 < V_219 ; V_123 ++ )
if ( F_2 ( V_123 , V_8 -> V_68 ) )
V_28 ++ ;
}
V_28 += 7 ;
return V_28 ;
}
static void F_155 ( struct V_7 * V_8 )
{
F_156 ( V_8 , V_220 , V_35 ) ;
F_156 ( V_8 , V_221 , V_222 ) ;
F_156 ( V_8 , ABS , abs ) ;
F_156 ( V_8 , V_223 , V_224 ) ;
F_156 ( V_8 , V_202 , V_76 ) ;
F_156 ( V_8 , V_203 , V_80 ) ;
F_156 ( V_8 , V_225 , V_226 ) ;
F_156 ( V_8 , V_227 , V_63 ) ;
}
static void F_157 ( struct V_7 * V_8 )
{
struct V_18 * V_19 , * V_228 ;
F_51 ( V_8 ) ;
F_45 ( & V_164 ) ;
F_158 (handle, next, &dev->h_list, d_node)
V_19 -> V_24 -> V_229 ( V_19 ) ;
F_148 ( ! F_159 ( & V_8 -> V_209 ) ) ;
F_160 ( & V_8 -> V_14 ) ;
F_161 ( & V_8 -> V_168 ) ;
F_67 () ;
F_38 ( & V_164 ) ;
F_162 ( & V_8 -> V_8 ) ;
}
static void F_163 ( struct V_193 * V_8 , void * V_210 )
{
struct V_211 * V_212 = V_210 ;
struct V_7 * V_213 = V_212 -> V_213 ;
F_141 ( V_8 , L_59 ,
V_91 , F_127 ( & V_213 -> V_8 ) ) ;
F_157 ( V_213 ) ;
}
int F_164 ( struct V_7 * V_8 )
{
struct V_211 * V_212 = NULL ;
struct V_23 * V_24 ;
unsigned int V_230 ;
const char * V_169 ;
int error ;
if ( V_8 -> V_215 ) {
V_212 = F_144 ( F_163 ,
sizeof( struct V_211 ) , V_90 ) ;
if ( ! V_212 )
return - V_183 ;
V_212 -> V_213 = V_8 ;
}
F_34 ( V_54 , V_8 -> V_10 ) ;
F_58 ( V_127 , V_8 -> V_36 ) ;
F_155 ( V_8 ) ;
V_230 = F_152 ( V_8 ) ;
if ( V_8 -> V_231 < V_230 )
V_8 -> V_231 = V_230 ;
V_8 -> V_86 = V_8 -> V_231 + 2 ;
V_8 -> V_21 = F_31 ( V_8 -> V_86 , sizeof( * V_8 -> V_21 ) , V_90 ) ;
if ( ! V_8 -> V_21 ) {
error = - V_183 ;
goto V_232;
}
if ( ! V_8 -> V_11 [ V_13 ] && ! V_8 -> V_11 [ V_12 ] ) {
V_8 -> V_14 . V_15 = ( long ) V_8 ;
V_8 -> V_14 . V_233 = F_18 ;
V_8 -> V_11 [ V_13 ] = 250 ;
V_8 -> V_11 [ V_12 ] = 33 ;
}
if ( ! V_8 -> V_125 )
V_8 -> V_125 = F_56 ;
if ( ! V_8 -> V_126 )
V_8 -> V_126 = F_57 ;
error = F_165 ( & V_8 -> V_8 ) ;
if ( error )
goto V_234;
V_169 = F_85 ( & V_8 -> V_8 . V_145 , V_90 ) ;
F_166 ( L_60 ,
V_8 -> V_144 ? V_8 -> V_144 : L_61 ,
V_169 ? V_169 : L_62 ) ;
F_86 ( V_169 ) ;
error = F_36 ( & V_164 ) ;
if ( error )
goto V_235;
F_167 ( & V_8 -> V_168 , & V_166 ) ;
F_43 (handler, &input_handler_list, node)
F_63 ( V_8 , V_24 ) ;
F_67 () ;
F_38 ( & V_164 ) ;
if ( V_8 -> V_215 ) {
F_141 ( V_8 -> V_8 . V_214 , L_63 ,
V_91 , F_127 ( & V_8 -> V_8 ) ) ;
F_146 ( V_8 -> V_8 . V_214 , V_212 ) ;
}
return 0 ;
V_235:
F_162 ( & V_8 -> V_8 ) ;
V_234:
F_86 ( V_8 -> V_21 ) ;
V_8 -> V_21 = NULL ;
V_232:
F_145 ( V_212 ) ;
return error ;
}
void F_168 ( struct V_7 * V_8 )
{
if ( V_8 -> V_215 ) {
F_148 ( F_149 ( V_8 -> V_8 . V_214 ,
F_163 ,
F_139 ,
V_8 ) ) ;
F_157 ( V_8 ) ;
} else {
F_157 ( V_8 ) ;
F_142 ( V_8 ) ;
}
}
int F_169 ( struct V_23 * V_24 )
{
struct V_7 * V_8 ;
int error ;
error = F_36 ( & V_164 ) ;
if ( error )
return error ;
F_135 ( & V_24 -> V_209 ) ;
F_167 ( & V_24 -> V_168 , & V_176 ) ;
F_43 (dev, &input_dev_list, node)
F_63 ( V_8 , V_24 ) ;
F_67 () ;
F_38 ( & V_164 ) ;
return 0 ;
}
void F_170 ( struct V_23 * V_24 )
{
struct V_18 * V_19 , * V_228 ;
F_45 ( & V_164 ) ;
F_158 (handle, next, &handler->h_list, h_node)
V_24 -> V_229 ( V_19 ) ;
F_148 ( ! F_159 ( & V_24 -> V_209 ) ) ;
F_161 ( & V_24 -> V_168 ) ;
F_67 () ;
F_38 ( & V_164 ) ;
}
int F_171 ( struct V_23 * V_24 , void * V_15 ,
int (* F_172)( struct V_18 * , void * ) )
{
struct V_18 * V_19 ;
int V_97 = 0 ;
F_11 () ;
F_13 (handle, &handler->h_list, h_node) {
V_97 = F_172 ( V_19 , V_15 ) ;
if ( V_97 )
break;
}
F_14 () ;
return V_97 ;
}
int F_173 ( struct V_18 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_7 * V_8 = V_19 -> V_8 ;
int error ;
error = F_36 ( & V_8 -> V_98 ) ;
if ( error )
return error ;
if ( V_24 -> V_27 )
F_174 ( & V_19 -> V_236 , & V_8 -> V_209 ) ;
else
F_175 ( & V_19 -> V_236 , & V_8 -> V_209 ) ;
F_38 ( & V_8 -> V_98 ) ;
F_175 ( & V_19 -> V_237 , & V_24 -> V_209 ) ;
if ( V_24 -> V_102 )
V_24 -> V_102 ( V_19 ) ;
return 0 ;
}
void F_176 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_177 ( & V_19 -> V_237 ) ;
F_45 ( & V_8 -> V_98 ) ;
F_177 ( & V_19 -> V_236 ) ;
F_38 ( & V_8 -> V_98 ) ;
F_42 () ;
}
int F_178 ( int V_238 , unsigned int V_239 ,
bool V_240 )
{
if ( V_238 >= 0 ) {
int V_178 = F_179 ( & V_241 ,
V_238 ,
V_238 + V_239 ,
V_90 ) ;
if ( V_178 >= 0 || ! V_240 )
return V_178 ;
}
return F_179 ( & V_241 ,
V_242 , V_243 ,
V_90 ) ;
}
void F_180 ( unsigned int V_178 )
{
F_181 ( & V_241 , V_178 ) ;
}
static int T_3 F_182 ( void )
{
int V_244 ;
V_244 = F_183 ( & V_208 ) ;
if ( V_244 ) {
F_64 ( L_64 ) ;
return V_244 ;
}
V_244 = F_93 () ;
if ( V_244 )
goto V_185;
V_244 = F_184 ( F_185 ( V_245 , 0 ) ,
V_243 , L_65 ) ;
if ( V_244 ) {
F_64 ( L_66 , V_245 ) ;
goto V_187;
}
return 0 ;
V_187: F_97 () ;
V_185: F_186 ( & V_208 ) ;
return V_244 ;
}
static void T_7 F_187 ( void )
{
F_97 () ;
F_188 ( F_185 ( V_245 , 0 ) ,
V_243 ) ;
F_186 ( & V_208 ) ;
}
