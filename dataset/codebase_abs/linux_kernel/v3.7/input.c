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
for ( V_26 = V_21 ; V_26 != V_21 + V_22 ; V_26 ++ ) {
if ( V_24 -> V_27 &&
V_24 -> V_27 ( V_19 , V_26 -> type , V_26 -> V_1 , V_26 -> V_4 ) )
continue;
if ( V_25 != V_26 )
* V_25 = * V_26 ;
V_25 ++ ;
}
V_22 = V_25 - V_21 ;
if ( ! V_22 )
return 0 ;
if ( V_24 -> V_28 )
V_24 -> V_28 ( V_19 , V_21 , V_22 ) ;
else if ( V_24 -> V_29 )
for ( V_26 = V_21 ; V_26 != V_25 ; V_26 ++ )
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
if ( V_19 -> V_31 )
V_22 = F_9 ( V_19 , V_21 , V_22 ) ;
}
F_14 () ;
F_15 ( V_21 -> type , V_21 -> V_1 , V_21 -> V_4 ) ;
for ( V_26 = V_21 ; V_26 != V_21 + V_22 ; V_26 ++ ) {
if ( V_26 -> type == V_32 && V_26 -> V_4 != 2 ) {
if ( V_26 -> V_4 )
F_4 ( V_8 , V_26 -> V_1 ) ;
else
F_7 ( V_8 ) ;
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
unsigned int type , unsigned int V_1 , int V_4 )
{
int V_53 = V_47 ;
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
return V_53 ;
}
static void F_27 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_1 , int V_4 )
{
int V_53 ;
V_53 = F_25 ( V_8 , type , V_1 , V_4 ) ;
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
V_8 -> V_65 [ F_34 ( V_92 ) ] |= F_35 ( V_92 ) ;
}
int F_36 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
int V_97 ;
V_97 = F_37 ( & V_8 -> V_98 ) ;
if ( V_97 )
return V_97 ;
if ( V_8 -> V_30 ) {
V_97 = - V_99 ;
goto V_100;
}
F_38 ( V_8 -> V_30 , V_19 ) ;
V_100:
F_39 ( & V_8 -> V_98 ) ;
return V_97 ;
}
static void F_40 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
if ( V_8 -> V_30 == V_19 ) {
F_38 ( V_8 -> V_30 , NULL ) ;
F_41 () ;
F_42 (handle, &dev->h_list, d_node)
if ( V_19 -> V_31 && V_19 -> V_24 -> V_101 )
V_19 -> V_24 -> V_101 ( V_19 ) ;
}
}
void F_43 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_44 ( & V_8 -> V_98 ) ;
F_40 ( V_19 ) ;
F_39 ( & V_8 -> V_98 ) ;
}
int F_45 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
int V_97 ;
V_97 = F_37 ( & V_8 -> V_98 ) ;
if ( V_97 )
return V_97 ;
if ( V_8 -> V_102 ) {
V_97 = - V_103 ;
goto V_100;
}
V_19 -> V_31 ++ ;
if ( ! V_8 -> V_104 ++ && V_8 -> V_31 )
V_97 = V_8 -> V_31 ( V_8 ) ;
if ( V_97 ) {
V_8 -> V_104 -- ;
if ( ! -- V_19 -> V_31 ) {
F_41 () ;
}
}
V_100:
F_39 ( & V_8 -> V_98 ) ;
return V_97 ;
}
int F_46 ( struct V_18 * V_19 , struct V_105 * V_105 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
int V_97 ;
V_97 = F_37 ( & V_8 -> V_98 ) ;
if ( V_97 )
return V_97 ;
if ( V_8 -> V_106 )
V_97 = V_8 -> V_106 ( V_8 , V_105 ) ;
F_39 ( & V_8 -> V_98 ) ;
return V_97 ;
}
void F_47 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_44 ( & V_8 -> V_98 ) ;
F_40 ( V_19 ) ;
if ( ! -- V_8 -> V_104 && V_8 -> V_107 )
V_8 -> V_107 ( V_8 ) ;
if ( ! -- V_19 -> V_31 ) {
F_41 () ;
}
F_39 ( & V_8 -> V_98 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
int V_1 ;
if ( F_1 ( V_32 , V_8 -> V_10 , V_87 ) ) {
for ( V_1 = 0 ; V_1 <= V_37 ; V_1 ++ ) {
if ( F_1 ( V_1 , V_8 -> V_36 , V_37 ) &&
F_49 ( V_1 , V_8 -> V_35 ) ) {
F_16 ( V_8 , V_32 , V_1 , 0 ) ;
}
}
F_16 ( V_8 , V_54 , V_57 , 1 ) ;
}
}
static void F_50 ( struct V_7 * V_8 )
{
struct V_18 * V_19 ;
F_44 ( & V_8 -> V_98 ) ;
V_8 -> V_102 = true ;
F_39 ( & V_8 -> V_98 ) ;
F_51 ( & V_8 -> V_34 ) ;
F_48 ( V_8 ) ;
F_42 (handle, &dev->h_list, d_node)
V_19 -> V_31 = 0 ;
F_52 ( & V_8 -> V_34 ) ;
}
int F_53 ( const struct V_108 * V_109 ,
unsigned int * V_110 )
{
switch ( V_109 -> V_111 ) {
case 1 :
* V_110 = * ( ( V_112 * ) V_109 -> V_110 ) ;
break;
case 2 :
* V_110 = * ( ( V_113 * ) V_109 -> V_110 ) ;
break;
case 4 :
* V_110 = * ( ( V_114 * ) V_109 -> V_110 ) ;
break;
default:
return - V_115 ;
}
return 0 ;
}
static unsigned int F_54 ( struct V_7 * V_8 ,
unsigned int V_116 )
{
switch ( V_8 -> V_117 ) {
case 1 :
return ( ( V_112 * ) V_8 -> V_118 ) [ V_116 ] ;
case 2 :
return ( ( V_113 * ) V_8 -> V_118 ) [ V_116 ] ;
default:
return ( ( V_114 * ) V_8 -> V_118 ) [ V_116 ] ;
}
}
static int F_55 ( struct V_7 * V_8 ,
struct V_108 * V_109 )
{
unsigned int V_116 ;
int error ;
if ( ! V_8 -> V_117 )
return - V_115 ;
if ( V_109 -> V_33 & V_119 )
V_116 = V_109 -> V_116 ;
else {
error = F_53 ( V_109 , & V_116 ) ;
if ( error )
return error ;
}
if ( V_116 >= V_8 -> V_120 )
return - V_115 ;
V_109 -> V_118 = F_54 ( V_8 , V_116 ) ;
V_109 -> V_116 = V_116 ;
V_109 -> V_111 = sizeof( V_116 ) ;
memcpy ( V_109 -> V_110 , & V_116 , sizeof( V_116 ) ) ;
return 0 ;
}
static int F_56 ( struct V_7 * V_8 ,
const struct V_108 * V_109 ,
unsigned int * V_121 )
{
unsigned int V_116 ;
int error ;
int V_122 ;
if ( ! V_8 -> V_117 )
return - V_115 ;
if ( V_109 -> V_33 & V_119 ) {
V_116 = V_109 -> V_116 ;
} else {
error = F_53 ( V_109 , & V_116 ) ;
if ( error )
return error ;
}
if ( V_116 >= V_8 -> V_120 )
return - V_115 ;
if ( V_8 -> V_117 < sizeof( V_109 -> V_118 ) &&
( V_109 -> V_118 >> ( V_8 -> V_117 * 8 ) ) )
return - V_115 ;
switch ( V_8 -> V_117 ) {
case 1 : {
V_112 * V_123 = ( V_112 * ) V_8 -> V_118 ;
* V_121 = V_123 [ V_116 ] ;
V_123 [ V_116 ] = V_109 -> V_118 ;
break;
}
case 2 : {
V_113 * V_123 = ( V_113 * ) V_8 -> V_118 ;
* V_121 = V_123 [ V_116 ] ;
V_123 [ V_116 ] = V_109 -> V_118 ;
break;
}
default: {
V_114 * V_123 = ( V_114 * ) V_8 -> V_118 ;
* V_121 = V_123 [ V_116 ] ;
V_123 [ V_116 ] = V_109 -> V_118 ;
break;
}
}
F_57 ( * V_121 , V_8 -> V_36 ) ;
F_58 ( V_109 -> V_118 , V_8 -> V_36 ) ;
for ( V_122 = 0 ; V_122 < V_8 -> V_120 ; V_122 ++ ) {
if ( F_54 ( V_8 , V_122 ) == * V_121 ) {
F_58 ( * V_121 , V_8 -> V_36 ) ;
break;
}
}
return 0 ;
}
int F_59 ( struct V_7 * V_8 , struct V_108 * V_109 )
{
unsigned long V_33 ;
int V_97 ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
V_97 = V_8 -> V_124 ( V_8 , V_109 ) ;
F_20 ( & V_8 -> V_34 , V_33 ) ;
return V_97 ;
}
int F_60 ( struct V_7 * V_8 ,
const struct V_108 * V_109 )
{
unsigned long V_33 ;
unsigned int V_121 ;
int V_97 ;
if ( V_109 -> V_118 > V_37 )
return - V_115 ;
F_19 ( & V_8 -> V_34 , V_33 ) ;
V_97 = V_8 -> V_125 ( V_8 , V_109 , & V_121 ) ;
if ( V_97 )
goto V_100;
F_57 ( V_126 , V_8 -> V_36 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) &&
! F_1 ( V_121 , V_8 -> V_36 , V_37 ) &&
F_49 ( V_121 , V_8 -> V_35 ) ) {
struct V_20 V_21 [] = {
{ V_32 , V_121 , 0 } ,
V_38
} ;
F_10 ( V_8 , V_21 , F_17 ( V_21 ) ) ;
}
V_100:
F_20 ( & V_8 -> V_34 , V_33 ) ;
return V_97 ;
}
static const struct V_127 * F_61 ( struct V_23 * V_24 ,
struct V_7 * V_8 )
{
const struct V_127 * V_128 ;
for ( V_128 = V_24 -> V_129 ; V_128 -> V_33 || V_128 -> V_130 ; V_128 ++ ) {
if ( V_128 -> V_33 & V_131 )
if ( V_128 -> V_132 != V_8 -> V_128 . V_132 )
continue;
if ( V_128 -> V_33 & V_133 )
if ( V_128 -> V_134 != V_8 -> V_128 . V_134 )
continue;
if ( V_128 -> V_33 & V_135 )
if ( V_128 -> V_136 != V_8 -> V_128 . V_136 )
continue;
if ( V_128 -> V_33 & V_137 )
if ( V_128 -> V_138 != V_8 -> V_128 . V_138 )
continue;
if ( ! F_62 ( V_128 -> V_10 , V_8 -> V_10 , V_87 ) )
continue;
if ( ! F_62 ( V_128 -> V_36 , V_8 -> V_36 , V_37 ) )
continue;
if ( ! F_62 ( V_128 -> V_68 , V_8 -> V_68 , V_69 ) )
continue;
if ( ! F_62 ( V_128 -> V_65 , V_8 -> V_65 , V_66 ) )
continue;
if ( ! F_62 ( V_128 -> V_71 , V_8 -> V_71 , V_72 ) )
continue;
if ( ! F_62 ( V_128 -> V_74 , V_8 -> V_74 , V_75 ) )
continue;
if ( ! F_62 ( V_128 -> V_78 , V_8 -> V_78 , V_79 ) )
continue;
if ( ! F_62 ( V_128 -> V_139 , V_8 -> V_139 , V_140 ) )
continue;
if ( ! F_62 ( V_128 -> V_61 , V_8 -> V_61 , V_62 ) )
continue;
if ( ! V_24 -> V_141 || V_24 -> V_141 ( V_24 , V_8 ) )
return V_128 ;
}
return NULL ;
}
static int F_63 ( struct V_7 * V_8 , struct V_23 * V_24 )
{
const struct V_127 * V_128 ;
int error ;
V_128 = F_61 ( V_24 , V_8 ) ;
if ( ! V_128 )
return - V_103 ;
error = V_24 -> V_142 ( V_24 , V_8 , V_128 ) ;
if ( error && error != - V_103 )
F_64 ( L_2 ,
V_24 -> V_143 , F_65 ( & V_8 -> V_8 . V_144 ) , error ) ;
return error ;
}
static int F_66 ( char * V_145 , int V_146 ,
unsigned long V_147 , bool V_148 )
{
int V_111 = 0 ;
if ( V_149 ) {
V_114 V_150 = V_147 >> 32 ;
if ( V_150 || ! V_148 )
V_111 += snprintf ( V_145 , V_146 , L_3 , V_150 ) ;
V_150 = V_147 & 0xffffffffUL ;
if ( V_150 || ! V_148 || V_111 )
V_111 += snprintf ( V_145 + V_111 , V_3 ( V_146 - V_111 , 0 ) ,
L_4 , V_150 ) ;
} else {
if ( V_147 || ! V_148 )
V_111 += snprintf ( V_145 , V_146 , L_5 , V_147 ) ;
}
return V_111 ;
}
static int F_66 ( char * V_145 , int V_146 ,
unsigned long V_147 , bool V_148 )
{
return V_147 || ! V_148 ?
snprintf ( V_145 , V_146 , L_5 , V_147 ) : 0 ;
}
static inline void F_67 ( void )
{
V_151 ++ ;
F_68 ( & V_152 ) ;
}
static unsigned int F_69 ( struct V_105 * V_105 , T_1 * V_153 )
{
F_70 ( V_105 , & V_152 , V_153 ) ;
if ( V_105 -> V_154 != V_151 ) {
V_105 -> V_154 = V_151 ;
return V_155 | V_156 ;
}
return 0 ;
}
static void * F_71 ( struct V_157 * V_158 , T_2 * V_159 )
{
union V_160 * V_161 = (union V_160 * ) & V_158 -> V_162 ;
int error ;
F_72 ( sizeof( union V_160 ) != sizeof( V_158 -> V_162 ) ) ;
error = F_37 ( & V_163 ) ;
if ( error ) {
V_161 -> V_164 = false ;
return F_73 ( error ) ;
}
V_161 -> V_164 = true ;
return F_74 ( & V_165 , * V_159 ) ;
}
static void * F_75 ( struct V_157 * V_158 , void * V_26 , T_2 * V_159 )
{
return F_76 ( V_26 , & V_165 , V_159 ) ;
}
static void F_77 ( struct V_157 * V_158 , void * V_26 )
{
union V_160 * V_161 = (union V_160 * ) & V_158 -> V_162 ;
if ( V_161 -> V_164 )
F_39 ( & V_163 ) ;
}
static void F_78 ( struct V_157 * V_158 , const char * V_143 ,
unsigned long * V_166 , int V_3 )
{
int V_122 ;
bool V_148 = true ;
char V_145 [ 18 ] ;
F_79 ( V_158 , L_6 , V_143 ) ;
for ( V_122 = F_80 ( V_3 ) - 1 ; V_122 >= 0 ; V_122 -- ) {
if ( F_66 ( V_145 , sizeof( V_145 ) ,
V_166 [ V_122 ] , V_148 ) ) {
V_148 = false ;
F_79 ( V_158 , L_7 , V_145 , V_122 > 0 ? L_8 : L_9 ) ;
}
}
if ( V_148 )
F_81 ( V_158 , L_10 ) ;
F_82 ( V_158 , '\n' ) ;
}
static int F_83 ( struct V_157 * V_158 , void * V_26 )
{
struct V_7 * V_8 = F_84 ( V_26 , struct V_7 , V_167 ) ;
const char * V_168 = F_85 ( & V_8 -> V_8 . V_144 , V_90 ) ;
struct V_18 * V_19 ;
F_79 ( V_158 , L_11 ,
V_8 -> V_128 . V_132 , V_8 -> V_128 . V_134 , V_8 -> V_128 . V_136 , V_8 -> V_128 . V_138 ) ;
F_79 ( V_158 , L_12 , V_8 -> V_143 ? V_8 -> V_143 : L_9 ) ;
F_79 ( V_158 , L_13 , V_8 -> V_169 ? V_8 -> V_169 : L_9 ) ;
F_79 ( V_158 , L_14 , V_168 ? V_168 : L_9 ) ;
F_79 ( V_158 , L_15 , V_8 -> V_170 ? V_8 -> V_170 : L_9 ) ;
F_79 ( V_158 , L_16 ) ;
F_42 (handle, &dev->h_list, d_node)
F_79 ( V_158 , L_17 , V_19 -> V_143 ) ;
F_82 ( V_158 , '\n' ) ;
F_78 ( V_158 , L_18 , V_8 -> V_171 , V_172 ) ;
F_78 ( V_158 , L_19 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_78 ( V_158 , L_20 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_78 ( V_158 , L_21 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_78 ( V_158 , L_22 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_78 ( V_158 , L_23 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_78 ( V_158 , L_24 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_78 ( V_158 , L_25 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_78 ( V_158 , L_26 , V_8 -> V_139 , V_140 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_78 ( V_158 , L_27 , V_8 -> V_61 , V_62 ) ;
F_82 ( V_158 , '\n' ) ;
F_86 ( V_168 ) ;
return 0 ;
}
static int F_87 ( struct V_173 * V_173 , struct V_105 * V_105 )
{
return F_88 ( V_105 , & V_174 ) ;
}
static void * F_89 ( struct V_157 * V_158 , T_2 * V_159 )
{
union V_160 * V_161 = (union V_160 * ) & V_158 -> V_162 ;
int error ;
F_72 ( sizeof( union V_160 ) != sizeof( V_158 -> V_162 ) ) ;
error = F_37 ( & V_163 ) ;
if ( error ) {
V_161 -> V_164 = false ;
return F_73 ( error ) ;
}
V_161 -> V_164 = true ;
V_161 -> V_159 = * V_159 ;
return F_74 ( & V_175 , * V_159 ) ;
}
static void * F_90 ( struct V_157 * V_158 , void * V_26 , T_2 * V_159 )
{
union V_160 * V_161 = (union V_160 * ) & V_158 -> V_162 ;
V_161 -> V_159 = * V_159 + 1 ;
return F_76 ( V_26 , & V_175 , V_159 ) ;
}
static int F_91 ( struct V_157 * V_158 , void * V_26 )
{
struct V_23 * V_24 = F_84 ( V_26 , struct V_23 , V_167 ) ;
union V_160 * V_161 = (union V_160 * ) & V_158 -> V_162 ;
F_79 ( V_158 , L_28 , V_161 -> V_159 , V_24 -> V_143 ) ;
if ( V_24 -> V_27 )
F_81 ( V_158 , L_29 ) ;
if ( V_24 -> V_176 )
F_79 ( V_158 , L_30 , V_24 -> V_177 ) ;
F_82 ( V_158 , '\n' ) ;
return 0 ;
}
static int F_92 ( struct V_173 * V_173 , struct V_105 * V_105 )
{
return F_88 ( V_105 , & V_178 ) ;
}
static int T_3 F_93 ( void )
{
struct V_179 * V_180 ;
V_181 = F_94 ( L_31 , NULL ) ;
if ( ! V_181 )
return - V_182 ;
V_180 = F_95 ( L_32 , 0 , V_181 ,
& V_183 ) ;
if ( ! V_180 )
goto V_184;
V_180 = F_95 ( L_33 , 0 , V_181 ,
& V_185 ) ;
if ( ! V_180 )
goto V_186;
return 0 ;
V_186: F_96 ( L_32 , V_181 ) ;
V_184: F_96 ( L_31 , NULL ) ;
return - V_182 ;
}
static void F_97 ( void )
{
F_96 ( L_32 , V_181 ) ;
F_96 ( L_33 , V_181 ) ;
F_96 ( L_31 , NULL ) ;
}
static inline void F_67 ( void ) { }
static inline int F_93 ( void ) { return 0 ; }
static inline void F_97 ( void ) { }
static int F_98 ( char * V_145 , int V_187 ,
char V_143 , unsigned long * V_2 ,
unsigned int V_188 , unsigned int V_189 )
{
int V_111 = 0 , V_122 ;
V_111 += snprintf ( V_145 , V_3 ( V_187 , 0 ) , L_34 , V_143 ) ;
for ( V_122 = V_188 ; V_122 < V_189 ; V_122 ++ )
if ( V_2 [ F_34 ( V_122 ) ] & F_35 ( V_122 ) )
V_111 += snprintf ( V_145 + V_111 , V_3 ( V_187 - V_111 , 0 ) , L_35 , V_122 ) ;
return V_111 ;
}
static int F_99 ( char * V_145 , int V_187 , struct V_7 * V_128 ,
int V_190 )
{
int V_111 ;
V_111 = snprintf ( V_145 , V_3 ( V_187 , 0 ) ,
L_36 ,
V_128 -> V_128 . V_132 , V_128 -> V_128 . V_134 ,
V_128 -> V_128 . V_136 , V_128 -> V_128 . V_138 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'e' , V_128 -> V_10 , 0 , V_87 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'k' , V_128 -> V_36 , V_191 , V_37 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'r' , V_128 -> V_68 , 0 , V_69 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'a' , V_128 -> V_65 , 0 , V_66 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'm' , V_128 -> V_71 , 0 , V_72 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'l' , V_128 -> V_74 , 0 , V_75 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
's' , V_128 -> V_78 , 0 , V_79 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'f' , V_128 -> V_139 , 0 , V_140 ) ;
V_111 += F_98 ( V_145 + V_111 , V_187 - V_111 ,
'w' , V_128 -> V_61 , 0 , V_62 ) ;
if ( V_190 )
V_111 += snprintf ( V_145 + V_111 , V_3 ( V_187 - V_111 , 0 ) , L_37 ) ;
return V_111 ;
}
static T_4 F_100 ( struct V_192 * V_8 ,
struct V_193 * V_194 ,
char * V_145 )
{
struct V_7 * V_128 = F_101 ( V_8 ) ;
T_4 V_111 ;
V_111 = F_99 ( V_145 , V_195 , V_128 , 1 ) ;
return F_102 ( int , V_111 , V_195 ) ;
}
static T_4 F_103 ( struct V_192 * V_8 ,
struct V_193 * V_194 ,
char * V_145 )
{
struct V_7 * V_7 = F_101 ( V_8 ) ;
int V_111 = F_104 ( V_145 , V_195 , V_7 -> V_171 ,
V_172 , true ) ;
return F_102 ( int , V_111 , V_195 ) ;
}
static int F_104 ( char * V_145 , int V_146 , unsigned long * V_166 ,
int V_3 , int V_190 )
{
int V_122 ;
int V_111 = 0 ;
bool V_148 = true ;
for ( V_122 = F_80 ( V_3 ) - 1 ; V_122 >= 0 ; V_122 -- ) {
V_111 += F_66 ( V_145 + V_111 , V_3 ( V_146 - V_111 , 0 ) ,
V_166 [ V_122 ] , V_148 ) ;
if ( V_111 ) {
V_148 = false ;
if ( V_122 > 0 )
V_111 += snprintf ( V_145 + V_111 , V_3 ( V_146 - V_111 , 0 ) , L_8 ) ;
}
}
if ( V_111 == 0 )
V_111 = snprintf ( V_145 , V_146 , L_38 , 0 ) ;
if ( V_190 )
V_111 += snprintf ( V_145 + V_111 , V_3 ( V_146 - V_111 , 0 ) , L_37 ) ;
return V_111 ;
}
static void F_105 ( struct V_192 * V_192 )
{
struct V_7 * V_8 = F_101 ( V_192 ) ;
F_106 ( V_8 ) ;
F_107 ( V_8 ) ;
F_86 ( V_8 -> V_48 ) ;
F_86 ( V_8 -> V_21 ) ;
F_86 ( V_8 ) ;
F_108 ( V_196 ) ;
}
static int F_109 ( struct V_197 * V_198 ,
const char * V_143 , unsigned long * V_166 , int V_3 )
{
int V_111 ;
if ( F_110 ( V_198 , L_39 , V_143 ) )
return - V_182 ;
V_111 = F_104 ( & V_198 -> V_145 [ V_198 -> V_199 - 1 ] ,
sizeof( V_198 -> V_145 ) - V_198 -> V_199 ,
V_166 , V_3 , false ) ;
if ( V_111 >= ( sizeof( V_198 -> V_145 ) - V_198 -> V_199 ) )
return - V_182 ;
V_198 -> V_199 += V_111 ;
return 0 ;
}
static int F_111 ( struct V_197 * V_198 ,
struct V_7 * V_8 )
{
int V_111 ;
if ( F_110 ( V_198 , L_40 ) )
return - V_182 ;
V_111 = F_99 ( & V_198 -> V_145 [ V_198 -> V_199 - 1 ] ,
sizeof( V_198 -> V_145 ) - V_198 -> V_199 ,
V_8 , 0 ) ;
if ( V_111 >= ( sizeof( V_198 -> V_145 ) - V_198 -> V_199 ) )
return - V_182 ;
V_198 -> V_199 += V_111 ;
return 0 ;
}
static int F_112 ( struct V_192 * V_192 , struct V_197 * V_198 )
{
struct V_7 * V_8 = F_101 ( V_192 ) ;
F_113 ( L_41 ,
V_8 -> V_128 . V_132 , V_8 -> V_128 . V_134 ,
V_8 -> V_128 . V_136 , V_8 -> V_128 . V_138 ) ;
if ( V_8 -> V_143 )
F_113 ( L_42 , V_8 -> V_143 ) ;
if ( V_8 -> V_169 )
F_113 ( L_43 , V_8 -> V_169 ) ;
if ( V_8 -> V_170 )
F_113 ( L_44 , V_8 -> V_170 ) ;
F_114 ( L_45 , V_8 -> V_171 , V_172 ) ;
F_114 ( L_46 , V_8 -> V_10 , V_87 ) ;
if ( F_2 ( V_32 , V_8 -> V_10 ) )
F_114 ( L_47 , V_8 -> V_36 , V_37 ) ;
if ( F_2 ( V_67 , V_8 -> V_10 ) )
F_114 ( L_48 , V_8 -> V_68 , V_69 ) ;
if ( F_2 ( V_64 , V_8 -> V_10 ) )
F_114 ( L_49 , V_8 -> V_65 , V_66 ) ;
if ( F_2 ( V_70 , V_8 -> V_10 ) )
F_114 ( L_50 , V_8 -> V_71 , V_72 ) ;
if ( F_2 ( V_73 , V_8 -> V_10 ) )
F_114 ( L_51 , V_8 -> V_74 , V_75 ) ;
if ( F_2 ( V_77 , V_8 -> V_10 ) )
F_114 ( L_52 , V_8 -> V_78 , V_79 ) ;
if ( F_2 ( V_82 , V_8 -> V_10 ) )
F_114 ( L_53 , V_8 -> V_139 , V_140 ) ;
if ( F_2 ( V_60 , V_8 -> V_10 ) )
F_114 ( L_54 , V_8 -> V_61 , V_62 ) ;
F_115 ( V_8 ) ;
return 0 ;
}
static void F_116 ( struct V_7 * V_8 , bool V_200 )
{
if ( ! V_8 -> V_29 )
return;
F_117 ( V_8 , V_201 , V_76 , V_200 ) ;
F_117 ( V_8 , V_202 , V_80 , V_200 ) ;
if ( V_200 && F_2 ( V_9 , V_8 -> V_10 ) ) {
V_8 -> V_29 ( V_8 , V_9 , V_12 , V_8 -> V_11 [ V_12 ] ) ;
V_8 -> V_29 ( V_8 , V_9 , V_13 , V_8 -> V_11 [ V_13 ] ) ;
}
}
void F_118 ( struct V_7 * V_8 )
{
F_44 ( & V_8 -> V_98 ) ;
if ( V_8 -> V_104 ) {
F_116 ( V_8 , true ) ;
F_51 ( & V_8 -> V_34 ) ;
F_48 ( V_8 ) ;
F_52 ( & V_8 -> V_34 ) ;
}
F_39 ( & V_8 -> V_98 ) ;
}
static int F_119 ( struct V_192 * V_8 )
{
struct V_7 * V_7 = F_101 ( V_8 ) ;
F_44 ( & V_7 -> V_98 ) ;
if ( V_7 -> V_104 )
F_116 ( V_7 , false ) ;
F_39 ( & V_7 -> V_98 ) ;
return 0 ;
}
static int F_120 ( struct V_192 * V_8 )
{
struct V_7 * V_7 = F_101 ( V_8 ) ;
F_118 ( V_7 ) ;
return 0 ;
}
static char * F_121 ( struct V_192 * V_8 , T_5 * V_203 )
{
return F_122 ( V_90 , L_55 , F_123 ( V_8 ) ) ;
}
struct V_7 * F_124 ( void )
{
struct V_7 * V_8 ;
V_8 = F_125 ( sizeof( struct V_7 ) , V_90 ) ;
if ( V_8 ) {
V_8 -> V_8 . type = & V_204 ;
V_8 -> V_8 . V_205 = & V_206 ;
F_126 ( & V_8 -> V_8 ) ;
F_127 ( & V_8 -> V_98 ) ;
F_128 ( & V_8 -> V_34 ) ;
F_129 ( & V_8 -> V_207 ) ;
F_129 ( & V_8 -> V_167 ) ;
F_130 ( V_196 ) ;
}
return V_8 ;
}
void F_131 ( struct V_7 * V_8 )
{
if ( V_8 )
F_132 ( V_8 ) ;
}
void F_133 ( struct V_7 * V_8 , unsigned int type , unsigned int V_1 )
{
switch ( type ) {
case V_32 :
F_58 ( V_1 , V_8 -> V_36 ) ;
break;
case V_67 :
F_58 ( V_1 , V_8 -> V_68 ) ;
break;
case V_64 :
F_58 ( V_1 , V_8 -> V_65 ) ;
break;
case V_70 :
F_58 ( V_1 , V_8 -> V_71 ) ;
break;
case V_60 :
F_58 ( V_1 , V_8 -> V_61 ) ;
break;
case V_73 :
F_58 ( V_1 , V_8 -> V_74 ) ;
break;
case V_77 :
F_58 ( V_1 , V_8 -> V_78 ) ;
break;
case V_82 :
F_58 ( V_1 , V_8 -> V_139 ) ;
break;
case V_83 :
break;
default:
F_64 ( L_56 ,
type , V_1 ) ;
F_134 () ;
return;
}
F_58 ( type , V_8 -> V_10 ) ;
}
static unsigned int F_135 ( struct V_7 * V_8 )
{
int V_208 ;
int V_122 ;
unsigned int V_28 ;
if ( V_8 -> V_41 ) {
V_208 = V_8 -> V_41 -> V_45 ;
} else if ( F_2 ( V_209 , V_8 -> V_65 ) ) {
V_208 = V_8 -> V_48 [ V_209 ] . V_96 -
V_8 -> V_48 [ V_209 ] . V_95 + 1 ,
V_208 = F_136 ( V_208 , 2 , 32 ) ;
} else if ( F_2 ( V_210 , V_8 -> V_65 ) ) {
V_208 = 2 ;
} else {
V_208 = 0 ;
}
V_28 = V_208 + 1 ;
for ( V_122 = 0 ; V_122 < V_88 ; V_122 ++ ) {
if ( F_2 ( V_122 , V_8 -> V_65 ) ) {
if ( F_137 ( V_122 ) )
V_28 += V_208 ;
else
V_28 ++ ;
}
}
for ( V_122 = 0 ; V_122 < V_211 ; V_122 ++ )
if ( F_2 ( V_122 , V_8 -> V_68 ) )
V_28 ++ ;
V_28 += 7 ;
return V_28 ;
}
static void F_138 ( struct V_7 * V_8 )
{
F_139 ( V_8 , V_212 , V_35 ) ;
F_139 ( V_8 , V_213 , V_214 ) ;
F_139 ( V_8 , ABS , abs ) ;
F_139 ( V_8 , V_215 , V_216 ) ;
F_139 ( V_8 , V_201 , V_76 ) ;
F_139 ( V_8 , V_202 , V_80 ) ;
F_139 ( V_8 , V_217 , V_218 ) ;
F_139 ( V_8 , V_219 , V_63 ) ;
}
int F_140 ( struct V_7 * V_8 )
{
static T_6 V_220 = F_141 ( 0 ) ;
struct V_23 * V_24 ;
unsigned int V_221 ;
const char * V_168 ;
int error ;
F_58 ( V_54 , V_8 -> V_10 ) ;
F_57 ( V_126 , V_8 -> V_36 ) ;
F_138 ( V_8 ) ;
V_221 = F_135 ( V_8 ) ;
if ( V_8 -> V_222 < V_221 )
V_8 -> V_222 = V_221 ;
V_8 -> V_86 = V_3 ( V_8 -> V_222 , V_221 ) + 2 ;
V_8 -> V_21 = F_31 ( V_8 -> V_86 , sizeof( * V_8 -> V_21 ) , V_90 ) ;
if ( ! V_8 -> V_21 )
return - V_182 ;
F_142 ( & V_8 -> V_14 ) ;
if ( ! V_8 -> V_11 [ V_13 ] && ! V_8 -> V_11 [ V_12 ] ) {
V_8 -> V_14 . V_15 = ( long ) V_8 ;
V_8 -> V_14 . V_223 = F_18 ;
V_8 -> V_11 [ V_13 ] = 250 ;
V_8 -> V_11 [ V_12 ] = 33 ;
}
if ( ! V_8 -> V_124 )
V_8 -> V_124 = F_55 ;
if ( ! V_8 -> V_125 )
V_8 -> V_125 = F_56 ;
F_143 ( & V_8 -> V_8 , L_57 ,
( unsigned long ) F_144 ( & V_220 ) - 1 ) ;
error = F_145 ( & V_8 -> V_8 ) ;
if ( error )
return error ;
V_168 = F_85 ( & V_8 -> V_8 . V_144 , V_90 ) ;
F_146 ( L_58 ,
V_8 -> V_143 ? V_8 -> V_143 : L_59 ,
V_168 ? V_168 : L_60 ) ;
F_86 ( V_168 ) ;
error = F_37 ( & V_163 ) ;
if ( error ) {
F_147 ( & V_8 -> V_8 ) ;
return error ;
}
F_148 ( & V_8 -> V_167 , & V_165 ) ;
F_42 (handler, &input_handler_list, node)
F_63 ( V_8 , V_24 ) ;
F_67 () ;
F_39 ( & V_163 ) ;
return 0 ;
}
void F_149 ( struct V_7 * V_8 )
{
struct V_18 * V_19 , * V_224 ;
F_50 ( V_8 ) ;
F_44 ( & V_163 ) ;
F_150 (handle, next, &dev->h_list, d_node)
V_19 -> V_24 -> V_225 ( V_19 ) ;
F_151 ( ! F_152 ( & V_8 -> V_207 ) ) ;
F_153 ( & V_8 -> V_14 ) ;
F_154 ( & V_8 -> V_167 ) ;
F_67 () ;
F_39 ( & V_163 ) ;
F_155 ( & V_8 -> V_8 ) ;
}
int F_156 ( struct V_23 * V_24 )
{
struct V_7 * V_8 ;
int error ;
error = F_37 ( & V_163 ) ;
if ( error )
return error ;
F_129 ( & V_24 -> V_207 ) ;
F_148 ( & V_24 -> V_167 , & V_175 ) ;
F_42 (dev, &input_dev_list, node)
F_63 ( V_8 , V_24 ) ;
F_67 () ;
F_39 ( & V_163 ) ;
return 0 ;
}
void F_157 ( struct V_23 * V_24 )
{
struct V_18 * V_19 , * V_224 ;
F_44 ( & V_163 ) ;
F_150 (handle, next, &handler->h_list, h_node)
V_24 -> V_225 ( V_19 ) ;
F_151 ( ! F_152 ( & V_24 -> V_207 ) ) ;
F_154 ( & V_24 -> V_167 ) ;
F_67 () ;
F_39 ( & V_163 ) ;
}
int F_158 ( struct V_23 * V_24 , void * V_15 ,
int (* F_159)( struct V_18 * , void * ) )
{
struct V_18 * V_19 ;
int V_97 = 0 ;
F_11 () ;
F_13 (handle, &handler->h_list, h_node) {
V_97 = F_159 ( V_19 , V_15 ) ;
if ( V_97 )
break;
}
F_14 () ;
return V_97 ;
}
int F_160 ( struct V_18 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_7 * V_8 = V_19 -> V_8 ;
int error ;
error = F_37 ( & V_8 -> V_98 ) ;
if ( error )
return error ;
if ( V_24 -> V_27 )
F_161 ( & V_19 -> V_226 , & V_8 -> V_207 ) ;
else
F_162 ( & V_19 -> V_226 , & V_8 -> V_207 ) ;
F_39 ( & V_8 -> V_98 ) ;
F_162 ( & V_19 -> V_227 , & V_24 -> V_207 ) ;
if ( V_24 -> V_101 )
V_24 -> V_101 ( V_19 ) ;
return 0 ;
}
void F_163 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_8 ;
F_164 ( & V_19 -> V_227 ) ;
F_44 ( & V_8 -> V_98 ) ;
F_164 ( & V_19 -> V_226 ) ;
F_39 ( & V_8 -> V_98 ) ;
F_41 () ;
}
int F_165 ( int V_228 , unsigned int V_229 ,
bool V_230 )
{
if ( V_228 >= 0 ) {
int V_177 = F_166 ( & V_231 ,
V_228 ,
V_228 + V_229 ,
V_90 ) ;
if ( V_177 >= 0 || ! V_230 )
return V_177 ;
}
return F_166 ( & V_231 ,
V_232 , V_233 ,
V_90 ) ;
}
void F_167 ( unsigned int V_177 )
{
F_168 ( & V_231 , V_177 ) ;
}
static int T_3 F_169 ( void )
{
int V_234 ;
V_234 = F_170 ( & V_206 ) ;
if ( V_234 ) {
F_64 ( L_61 ) ;
return V_234 ;
}
V_234 = F_93 () ;
if ( V_234 )
goto V_184;
V_234 = F_171 ( F_172 ( V_235 , 0 ) ,
V_233 , L_62 ) ;
if ( V_234 ) {
F_64 ( L_63 , V_235 ) ;
goto V_186;
}
return 0 ;
V_186: F_97 () ;
V_184: F_173 ( & V_206 ) ;
return V_234 ;
}
static void T_7 F_174 ( void )
{
F_97 () ;
F_175 ( F_172 ( V_235 , 0 ) ,
V_233 ) ;
F_173 ( & V_206 ) ;
}
