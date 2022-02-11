static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 , unsigned int V_8 ,
struct V_2 * V_2 , struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_12 = F_3 ( V_7 , V_8 , 4 , & V_13 ) ;
if ( V_12 == NULL )
return false ;
V_10 -> V_14 . V_15 . V_5 . V_16 = V_12 -> V_17 ;
V_10 -> V_18 . V_15 . V_5 . V_16 = V_12 -> V_19 ;
return true ;
}
static bool F_4 ( struct V_9 * V_10 ,
const struct V_9 * V_20 )
{
V_10 -> V_14 . V_15 . V_5 . V_16 = V_20 -> V_18 . V_15 . V_5 . V_16 ;
V_10 -> V_18 . V_15 . V_5 . V_16 = V_20 -> V_14 . V_15 . V_5 . V_16 ;
return true ;
}
static void F_5 ( struct V_21 * V_22 , struct V_23 * V_3 )
{
F_6 ( V_22 , L_1 , V_24 [ V_3 -> V_25 . V_5 . V_26 ] ) ;
}
static int F_7 ( struct V_23 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
unsigned long * V_27 )
{
T_1 V_28 , V_29 ;
struct V_30 V_31 , * V_32 ;
int V_33 ;
V_33 = 0 ;
F_8 (skb, sch, _sch, offset, dataoff, count) {
F_9 ( L_2 , V_29 , V_32 -> type ) ;
if ( V_32 -> type == V_34 ||
V_32 -> type == V_35 ||
V_32 -> type == V_36 )
V_33 = 1 ;
if ( ( ( V_32 -> type == V_37 ||
V_32 -> type == V_38 ||
V_33 ) &&
V_29 != 0 ) || ! V_32 -> V_39 ) {
F_9 ( L_3 ) ;
return 1 ;
}
if ( V_27 )
F_10 ( V_32 -> type , V_27 ) ;
}
F_9 ( L_4 ) ;
return V_29 == 0 ;
}
static int F_11 ( enum V_40 V_41 ,
enum V_42 V_43 ,
int V_44 )
{
int V_45 ;
F_9 ( L_5 , V_44 ) ;
switch ( V_44 ) {
case V_34 :
F_9 ( L_6 ) ;
V_45 = 0 ;
break;
case V_35 :
F_9 ( L_7 ) ;
V_45 = 1 ;
break;
case V_46 :
F_9 ( L_8 ) ;
V_45 = 2 ;
break;
case V_47 :
F_9 ( L_9 ) ;
V_45 = 3 ;
break;
case V_48 :
F_9 ( L_10 ) ;
V_45 = 4 ;
break;
case V_49 :
F_9 ( L_11 ) ;
V_45 = 5 ;
break;
case V_38 :
F_9 ( L_12 ) ;
V_45 = 6 ;
break;
case V_37 :
F_9 ( L_13 ) ;
V_45 = 7 ;
break;
case V_36 :
F_9 ( L_14 ) ;
V_45 = 8 ;
break;
case V_50 :
F_9 ( L_15 ) ;
V_45 = 9 ;
break;
case V_51 :
F_9 ( L_16 ) ;
V_45 = 10 ;
break;
default:
F_9 ( L_17 ,
V_24 [ V_43 ] ) ;
return V_43 ;
}
F_9 ( L_18 ,
V_41 , V_24 [ V_43 ] , V_44 ,
V_24 [ V_52 [ V_41 ] [ V_45 ] [ V_43 ] ] ) ;
return V_52 [ V_41 ] [ V_45 ] [ V_43 ] ;
}
static unsigned int * F_12 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_53 ;
}
static int F_13 ( struct V_23 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_54 V_55 ,
T_2 V_56 ,
unsigned int * V_53 )
{
enum V_42 V_57 , V_58 ;
enum V_40 V_41 = F_14 ( V_55 ) ;
const struct V_11 * V_59 ;
struct V_11 V_60 ;
const struct V_30 * V_32 ;
struct V_30 V_31 ;
T_1 V_28 , V_29 ;
unsigned long V_27 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_59 = F_3 ( V_7 , V_8 , sizeof( V_60 ) , & V_60 ) ;
if ( V_59 == NULL )
goto V_61;
if ( F_7 ( V_3 , V_7 , V_8 , V_27 ) != 0 )
goto V_61;
if ( ! F_15 ( V_34 , V_27 ) &&
! F_15 ( V_36 , V_27 ) &&
! F_15 ( V_38 , V_27 ) &&
! F_15 ( V_46 , V_27 ) &&
! F_15 ( V_48 , V_27 ) &&
! F_15 ( V_50 , V_27 ) &&
! F_15 ( V_51 , V_27 ) &&
V_59 -> V_62 != V_3 -> V_25 . V_5 . V_62 [ V_41 ] ) {
F_9 ( L_19 ) ;
goto V_61;
}
V_58 = V_57 = V_63 ;
F_16 ( & V_3 -> V_64 ) ;
F_8 (skb, sch, _sch, offset, dataoff, count) {
if ( V_32 -> type == V_34 ) {
if ( V_59 -> V_62 != 0 )
goto V_65;
} else if ( V_32 -> type == V_46 ) {
if ( V_59 -> V_62 != V_3 -> V_25 . V_5 . V_62 [ V_41 ] &&
V_59 -> V_62 != V_3 -> V_25 . V_5 . V_62 [ ! V_41 ] )
goto V_65;
} else if ( V_32 -> type == V_36 ) {
if ( V_59 -> V_62 != V_3 -> V_25 . V_5 . V_62 [ V_41 ] &&
V_59 -> V_62 != V_3 -> V_25 . V_5 . V_62 [ ! V_41 ] &&
V_32 -> V_66 & V_67 )
goto V_65;
} else if ( V_32 -> type == V_38 ) {
if ( V_59 -> V_62 != V_3 -> V_25 . V_5 . V_62 [ V_41 ] )
goto V_65;
} else if ( V_32 -> type == V_50 ||
V_32 -> type == V_51 ) {
if ( V_3 -> V_25 . V_5 . V_62 [ V_41 ] == 0 ) {
F_9 ( L_20 ,
V_59 -> V_62 , V_41 ) ;
V_3 -> V_25 . V_5 . V_62 [ V_41 ] = V_59 -> V_62 ;
} else if ( V_59 -> V_62 != V_3 -> V_25 . V_5 . V_62 [ V_41 ] ) {
F_9 ( L_19 ) ;
goto V_65;
}
}
V_58 = V_3 -> V_25 . V_5 . V_26 ;
V_57 = F_11 ( V_41 , V_58 , V_32 -> type ) ;
if ( V_57 == V_68 ) {
F_9 ( L_21
L_22 ,
V_41 , V_32 -> type , V_58 ) ;
goto V_65;
}
if ( V_32 -> type == V_34 ||
V_32 -> type == V_35 ) {
struct V_69 V_70 , * V_71 ;
V_71 = F_3 ( V_7 , V_28 + sizeof( V_31 ) ,
sizeof( V_70 ) , & V_70 ) ;
if ( V_71 == NULL )
goto V_65;
F_9 ( L_20 ,
V_71 -> V_72 , ! V_41 ) ;
V_3 -> V_25 . V_5 . V_62 [ ! V_41 ] = V_71 -> V_72 ;
}
V_3 -> V_25 . V_5 . V_26 = V_57 ;
if ( V_58 != V_57 )
F_17 ( V_73 , V_3 ) ;
}
F_18 ( & V_3 -> V_64 ) ;
F_19 ( V_3 , V_55 , V_7 , V_53 [ V_57 ] ) ;
if ( V_58 == V_74 &&
V_41 == V_75 &&
V_57 == V_76 ) {
F_9 ( L_23 ) ;
F_10 ( V_77 , & V_3 -> V_78 ) ;
F_17 ( V_79 , V_3 ) ;
}
return V_80 ;
V_65:
F_18 ( & V_3 -> V_64 ) ;
V_61:
return - V_80 ;
}
static bool F_20 ( struct V_23 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_53 )
{
enum V_42 V_57 ;
const struct V_11 * V_59 ;
struct V_11 V_60 ;
const struct V_30 * V_32 ;
struct V_30 V_31 ;
T_1 V_28 , V_29 ;
unsigned long V_27 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_59 = F_3 ( V_7 , V_8 , sizeof( V_60 ) , & V_60 ) ;
if ( V_59 == NULL )
return false ;
if ( F_7 ( V_3 , V_7 , V_8 , V_27 ) != 0 )
return false ;
if ( F_15 ( V_46 , V_27 ) ||
F_15 ( V_36 , V_27 ) ||
F_15 ( V_37 , V_27 ) )
return false ;
memset ( & V_3 -> V_25 . V_5 , 0 , sizeof( V_3 -> V_25 . V_5 ) ) ;
V_57 = V_68 ;
F_8 (skb, sch, _sch, offset, dataoff, count) {
V_57 = F_11 ( V_81 ,
V_63 , V_32 -> type ) ;
if ( V_57 == V_63 ||
V_57 == V_68 ) {
F_9 ( L_24 ) ;
return false ;
}
if ( V_32 -> type == V_34 ) {
struct V_69 V_70 , * V_71 ;
if ( V_59 -> V_62 )
return false ;
V_71 = F_3 ( V_7 , V_28 + sizeof( V_31 ) ,
sizeof( V_70 ) , & V_70 ) ;
if ( ! V_71 )
return false ;
F_9 ( L_25 ,
V_71 -> V_72 ) ;
V_3 -> V_25 . V_5 . V_62 [ V_75 ] = V_71 -> V_72 ;
} else if ( V_32 -> type == V_50 ) {
F_9 ( L_26 ,
V_59 -> V_62 ) ;
V_3 -> V_25 . V_5 . V_62 [ V_81 ] = V_59 -> V_62 ;
}
else {
F_9 ( L_27 ,
V_59 -> V_62 ) ;
V_3 -> V_25 . V_5 . V_62 [ V_75 ] = V_59 -> V_62 ;
}
V_3 -> V_25 . V_5 . V_26 = V_57 ;
}
return true ;
}
static int F_21 ( struct V_2 * V_2 , struct V_23 * V_82 , struct V_6 * V_7 ,
unsigned int V_8 ,
T_3 V_56 , unsigned int V_83 )
{
const struct V_11 * V_59 ;
const char * V_84 ;
if ( V_7 -> V_85 < V_8 + sizeof( struct V_11 ) ) {
V_84 = L_28 ;
goto V_86;
}
if ( V_2 -> V_3 . V_87 && V_83 == V_88 &&
V_7 -> V_89 == V_90 ) {
if ( ! F_22 ( V_7 , V_8 + sizeof( struct V_11 ) ) ) {
V_84 = L_29 ;
goto V_86;
}
V_59 = ( const struct V_11 * ) ( V_7 -> V_91 + V_8 ) ;
if ( V_59 -> V_92 != F_23 ( V_7 , V_8 ) ) {
V_84 = L_30 ;
goto V_86;
}
V_7 -> V_89 = V_93 ;
}
return V_80 ;
V_86:
if ( F_24 ( V_2 , V_94 ) )
F_25 ( V_2 , V_56 , 0 , V_7 , NULL , NULL , NULL , L_31 , V_84 ) ;
return - V_80 ;
}
static bool F_26 ( const struct V_23 * V_3 )
{
switch ( V_3 -> V_25 . V_5 . V_26 ) {
case V_95 :
case V_96 :
case V_97 :
return true ;
default:
break;
}
return false ;
}
static int F_27 ( struct V_6 * V_7 , struct V_98 * V_99 ,
struct V_23 * V_3 )
{
struct V_98 * V_100 ;
F_16 ( & V_3 -> V_64 ) ;
V_100 = F_28 ( V_7 , V_101 | V_102 ) ;
if ( ! V_100 )
goto V_103;
if ( F_29 ( V_7 , V_104 , V_3 -> V_25 . V_5 . V_26 ) ||
F_30 ( V_7 , V_105 ,
V_3 -> V_25 . V_5 . V_62 [ V_81 ] ) ||
F_30 ( V_7 , V_106 ,
V_3 -> V_25 . V_5 . V_62 [ V_75 ] ) )
goto V_103;
F_18 ( & V_3 -> V_64 ) ;
F_31 ( V_7 , V_100 ) ;
return 0 ;
V_103:
F_18 ( & V_3 -> V_64 ) ;
return - 1 ;
}
static int F_32 ( struct V_98 * V_107 [] , struct V_23 * V_3 )
{
struct V_98 * V_108 = V_107 [ V_101 ] ;
struct V_98 * V_109 [ V_110 + 1 ] ;
int V_111 ;
if ( ! V_108 )
return 0 ;
V_111 = F_33 ( V_109 , V_110 , V_108 ,
V_112 , NULL ) ;
if ( V_111 < 0 )
return V_111 ;
if ( ! V_109 [ V_104 ] ||
! V_109 [ V_105 ] ||
! V_109 [ V_106 ] )
return - V_113 ;
F_16 ( & V_3 -> V_64 ) ;
V_3 -> V_25 . V_5 . V_26 = F_34 ( V_109 [ V_104 ] ) ;
V_3 -> V_25 . V_5 . V_62 [ V_81 ] =
F_35 ( V_109 [ V_105 ] ) ;
V_3 -> V_25 . V_5 . V_62 [ V_75 ] =
F_35 ( V_109 [ V_106 ] ) ;
F_18 ( & V_3 -> V_64 ) ;
return 0 ;
}
static int F_36 ( void )
{
return F_37 ( 0 )
+ F_38 ( V_112 , V_110 + 1 ) ;
}
static int F_39 ( struct V_98 * V_109 [] ,
struct V_2 * V_2 , void * V_91 )
{
unsigned int * V_53 = V_91 ;
struct V_1 * V_114 = F_1 ( V_2 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_68 ; V_45 ++ )
V_53 [ V_45 ] = V_114 -> V_53 [ V_45 ] ;
for ( V_45 = V_115 + 1 ; V_45 < V_116 + 1 ; V_45 ++ ) {
if ( V_109 [ V_45 ] ) {
V_53 [ V_45 ] = F_40 ( F_35 ( V_109 [ V_45 ] ) ) * V_117 ;
}
}
return 0 ;
}
static int
F_41 ( struct V_6 * V_7 , const void * V_91 )
{
const unsigned int * V_53 = V_91 ;
int V_45 ;
for ( V_45 = V_115 + 1 ; V_45 < V_116 + 1 ; V_45 ++ ) {
if ( F_30 ( V_7 , V_45 , F_42 ( V_53 [ V_45 ] / V_117 ) ) )
goto V_103;
}
return 0 ;
V_103:
return - V_118 ;
}
static int F_43 ( struct V_119 * V_120 ,
struct V_1 * V_114 )
{
#ifdef F_44
if ( V_120 -> V_121 )
return 0 ;
V_120 -> V_121 = F_45 ( V_122 ,
sizeof( V_122 ) ,
V_123 ) ;
if ( ! V_120 -> V_121 )
return - V_124 ;
V_120 -> V_121 [ 0 ] . V_91 = & V_114 -> V_53 [ V_125 ] ;
V_120 -> V_121 [ 1 ] . V_91 = & V_114 -> V_53 [ V_126 ] ;
V_120 -> V_121 [ 2 ] . V_91 = & V_114 -> V_53 [ V_74 ] ;
V_120 -> V_121 [ 3 ] . V_91 = & V_114 -> V_53 [ V_76 ] ;
V_120 -> V_121 [ 4 ] . V_91 = & V_114 -> V_53 [ V_95 ] ;
V_120 -> V_121 [ 5 ] . V_91 = & V_114 -> V_53 [ V_96 ] ;
V_120 -> V_121 [ 6 ] . V_91 = & V_114 -> V_53 [ V_97 ] ;
V_120 -> V_121 [ 7 ] . V_91 = & V_114 -> V_53 [ V_127 ] ;
V_120 -> V_121 [ 8 ] . V_91 = & V_114 -> V_53 [ V_128 ] ;
#endif
return 0 ;
}
static int F_46 ( struct V_2 * V_2 , T_4 V_25 )
{
struct V_1 * V_114 = F_1 ( V_2 ) ;
struct V_119 * V_120 = & V_114 -> V_120 ;
if ( ! V_120 -> V_129 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_68 ; V_45 ++ )
V_114 -> V_53 [ V_45 ] = V_130 [ V_45 ] ;
}
return F_43 ( V_120 , V_114 ) ;
}
static struct V_119 * F_47 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_120 ;
}
