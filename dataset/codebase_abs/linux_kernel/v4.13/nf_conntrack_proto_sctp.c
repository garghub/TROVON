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
static void F_5 ( struct V_21 * V_22 ,
const struct V_9 * V_10 )
{
F_6 ( V_22 , L_1 ,
F_7 ( V_10 -> V_14 . V_15 . V_5 . V_16 ) ,
F_7 ( V_10 -> V_18 . V_15 . V_5 . V_16 ) ) ;
}
static void F_8 ( struct V_21 * V_22 , struct V_23 * V_3 )
{
F_6 ( V_22 , L_2 , V_24 [ V_3 -> V_25 . V_5 . V_26 ] ) ;
}
static int F_9 ( struct V_23 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
unsigned long * V_27 )
{
T_1 V_28 , V_29 ;
struct V_30 V_31 , * V_32 ;
int V_33 ;
V_33 = 0 ;
F_10 (skb, sch, _sch, offset, dataoff, count) {
F_11 ( L_3 , V_29 , V_32 -> type ) ;
if ( V_32 -> type == V_34 ||
V_32 -> type == V_35 ||
V_32 -> type == V_36 )
V_33 = 1 ;
if ( ( ( V_32 -> type == V_37 ||
V_32 -> type == V_38 ||
V_33 ) &&
V_29 != 0 ) || ! V_32 -> V_39 ) {
F_11 ( L_4 ) ;
return 1 ;
}
if ( V_27 )
F_12 ( V_32 -> type , V_27 ) ;
}
F_11 ( L_5 ) ;
return V_29 == 0 ;
}
static int F_13 ( enum V_40 V_41 ,
enum V_42 V_43 ,
int V_44 )
{
int V_45 ;
F_11 ( L_6 , V_44 ) ;
switch ( V_44 ) {
case V_34 :
F_11 ( L_7 ) ;
V_45 = 0 ;
break;
case V_35 :
F_11 ( L_8 ) ;
V_45 = 1 ;
break;
case V_46 :
F_11 ( L_9 ) ;
V_45 = 2 ;
break;
case V_47 :
F_11 ( L_10 ) ;
V_45 = 3 ;
break;
case V_48 :
F_11 ( L_11 ) ;
V_45 = 4 ;
break;
case V_49 :
F_11 ( L_12 ) ;
V_45 = 5 ;
break;
case V_38 :
F_11 ( L_13 ) ;
V_45 = 6 ;
break;
case V_37 :
F_11 ( L_14 ) ;
V_45 = 7 ;
break;
case V_36 :
F_11 ( L_15 ) ;
V_45 = 8 ;
break;
case V_50 :
F_11 ( L_16 ) ;
V_45 = 9 ;
break;
case V_51 :
F_11 ( L_17 ) ;
V_45 = 10 ;
break;
default:
F_11 ( L_18 ,
V_24 [ V_43 ] ) ;
return V_43 ;
}
F_11 ( L_19 ,
V_41 , V_24 [ V_43 ] , V_44 ,
V_24 [ V_52 [ V_41 ] [ V_45 ] [ V_43 ] ] ) ;
return V_52 [ V_41 ] [ V_45 ] [ V_43 ] ;
}
static unsigned int * F_14 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_53 ;
}
static int F_15 ( struct V_23 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_54 V_55 ,
T_2 V_56 ,
unsigned int V_57 ,
unsigned int * V_53 )
{
enum V_42 V_58 , V_59 ;
enum V_40 V_41 = F_16 ( V_55 ) ;
const struct V_11 * V_60 ;
struct V_11 V_61 ;
const struct V_30 * V_32 ;
struct V_30 V_31 ;
T_1 V_28 , V_29 ;
unsigned long V_27 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_60 = F_3 ( V_7 , V_8 , sizeof( V_61 ) , & V_61 ) ;
if ( V_60 == NULL )
goto V_62;
if ( F_9 ( V_3 , V_7 , V_8 , V_27 ) != 0 )
goto V_62;
if ( ! F_17 ( V_34 , V_27 ) &&
! F_17 ( V_36 , V_27 ) &&
! F_17 ( V_38 , V_27 ) &&
! F_17 ( V_46 , V_27 ) &&
! F_17 ( V_48 , V_27 ) &&
! F_17 ( V_50 , V_27 ) &&
! F_17 ( V_51 , V_27 ) &&
V_60 -> V_63 != V_3 -> V_25 . V_5 . V_63 [ V_41 ] ) {
F_11 ( L_20 ) ;
goto V_62;
}
V_59 = V_58 = V_64 ;
F_18 ( & V_3 -> V_65 ) ;
F_10 (skb, sch, _sch, offset, dataoff, count) {
if ( V_32 -> type == V_34 ) {
if ( V_60 -> V_63 != 0 )
goto V_66;
} else if ( V_32 -> type == V_46 ) {
if ( V_60 -> V_63 != V_3 -> V_25 . V_5 . V_63 [ V_41 ] &&
V_60 -> V_63 != V_3 -> V_25 . V_5 . V_63 [ ! V_41 ] )
goto V_66;
} else if ( V_32 -> type == V_36 ) {
if ( V_60 -> V_63 != V_3 -> V_25 . V_5 . V_63 [ V_41 ] &&
V_60 -> V_63 != V_3 -> V_25 . V_5 . V_63 [ ! V_41 ] &&
V_32 -> V_67 & V_68 )
goto V_66;
} else if ( V_32 -> type == V_38 ) {
if ( V_60 -> V_63 != V_3 -> V_25 . V_5 . V_63 [ V_41 ] )
goto V_66;
} else if ( V_32 -> type == V_50 ||
V_32 -> type == V_51 ) {
if ( V_3 -> V_25 . V_5 . V_63 [ V_41 ] == 0 ) {
F_11 ( L_21 ,
V_60 -> V_63 , V_41 ) ;
V_3 -> V_25 . V_5 . V_63 [ V_41 ] = V_60 -> V_63 ;
} else if ( V_60 -> V_63 != V_3 -> V_25 . V_5 . V_63 [ V_41 ] ) {
F_11 ( L_20 ) ;
goto V_66;
}
}
V_59 = V_3 -> V_25 . V_5 . V_26 ;
V_58 = F_13 ( V_41 , V_59 , V_32 -> type ) ;
if ( V_58 == V_69 ) {
F_11 ( L_22
L_23 ,
V_41 , V_32 -> type , V_59 ) ;
goto V_66;
}
if ( V_32 -> type == V_34 ||
V_32 -> type == V_35 ) {
struct V_70 V_71 , * V_72 ;
V_72 = F_3 ( V_7 , V_28 + sizeof( V_31 ) ,
sizeof( V_71 ) , & V_71 ) ;
if ( V_72 == NULL )
goto V_66;
F_11 ( L_21 ,
V_72 -> V_73 , ! V_41 ) ;
V_3 -> V_25 . V_5 . V_63 [ ! V_41 ] = V_72 -> V_73 ;
}
V_3 -> V_25 . V_5 . V_26 = V_58 ;
if ( V_59 != V_58 )
F_19 ( V_74 , V_3 ) ;
}
F_20 ( & V_3 -> V_65 ) ;
F_21 ( V_3 , V_55 , V_7 , V_53 [ V_58 ] ) ;
if ( V_59 == V_75 &&
V_41 == V_76 &&
V_58 == V_77 ) {
F_11 ( L_24 ) ;
F_12 ( V_78 , & V_3 -> V_79 ) ;
F_19 ( V_80 , V_3 ) ;
}
return V_81 ;
V_66:
F_20 ( & V_3 -> V_65 ) ;
V_62:
return - V_81 ;
}
static bool F_22 ( struct V_23 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_53 )
{
enum V_42 V_58 ;
const struct V_11 * V_60 ;
struct V_11 V_61 ;
const struct V_30 * V_32 ;
struct V_30 V_31 ;
T_1 V_28 , V_29 ;
unsigned long V_27 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_60 = F_3 ( V_7 , V_8 , sizeof( V_61 ) , & V_61 ) ;
if ( V_60 == NULL )
return false ;
if ( F_9 ( V_3 , V_7 , V_8 , V_27 ) != 0 )
return false ;
if ( F_17 ( V_46 , V_27 ) ||
F_17 ( V_36 , V_27 ) ||
F_17 ( V_37 , V_27 ) )
return false ;
memset ( & V_3 -> V_25 . V_5 , 0 , sizeof( V_3 -> V_25 . V_5 ) ) ;
V_58 = V_69 ;
F_10 (skb, sch, _sch, offset, dataoff, count) {
V_58 = F_13 ( V_82 ,
V_64 , V_32 -> type ) ;
if ( V_58 == V_64 ||
V_58 == V_69 ) {
F_11 ( L_25 ) ;
return false ;
}
if ( V_32 -> type == V_34 ) {
struct V_70 V_71 , * V_72 ;
if ( V_60 -> V_63 )
return false ;
V_72 = F_3 ( V_7 , V_28 + sizeof( V_31 ) ,
sizeof( V_71 ) , & V_71 ) ;
if ( ! V_72 )
return false ;
F_11 ( L_26 ,
V_72 -> V_73 ) ;
V_3 -> V_25 . V_5 . V_63 [ V_76 ] = V_72 -> V_73 ;
} else if ( V_32 -> type == V_50 ) {
F_11 ( L_27 ,
V_60 -> V_63 ) ;
V_3 -> V_25 . V_5 . V_63 [ V_82 ] = V_60 -> V_63 ;
}
else {
F_11 ( L_28 ,
V_60 -> V_63 ) ;
V_3 -> V_25 . V_5 . V_63 [ V_76 ] = V_60 -> V_63 ;
}
V_3 -> V_25 . V_5 . V_26 = V_58 ;
}
return true ;
}
static int F_23 ( struct V_2 * V_2 , struct V_23 * V_83 , struct V_6 * V_7 ,
unsigned int V_8 ,
T_3 V_56 , unsigned int V_57 )
{
const struct V_11 * V_60 ;
const char * V_84 ;
if ( V_7 -> V_85 < V_8 + sizeof( struct V_11 ) ) {
V_84 = L_29 ;
goto V_86;
}
if ( V_2 -> V_3 . V_87 && V_57 == V_88 &&
V_7 -> V_89 == V_90 ) {
if ( ! F_24 ( V_7 , V_8 + sizeof( struct V_11 ) ) ) {
V_84 = L_30 ;
goto V_86;
}
V_60 = ( const struct V_11 * ) ( V_7 -> V_91 + V_8 ) ;
if ( V_60 -> V_92 != F_25 ( V_7 , V_8 ) ) {
V_84 = L_31 ;
goto V_86;
}
V_7 -> V_89 = V_93 ;
}
return V_81 ;
V_86:
if ( F_26 ( V_2 , V_94 ) )
F_27 ( V_2 , V_56 , 0 , V_7 , NULL , NULL , NULL , L_32 , V_84 ) ;
return - V_81 ;
}
static bool F_28 ( const struct V_23 * V_3 )
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
static int F_29 ( struct V_6 * V_7 , struct V_98 * V_99 ,
struct V_23 * V_3 )
{
struct V_98 * V_100 ;
F_18 ( & V_3 -> V_65 ) ;
V_100 = F_30 ( V_7 , V_101 | V_102 ) ;
if ( ! V_100 )
goto V_103;
if ( F_31 ( V_7 , V_104 , V_3 -> V_25 . V_5 . V_26 ) ||
F_32 ( V_7 , V_105 ,
V_3 -> V_25 . V_5 . V_63 [ V_82 ] ) ||
F_32 ( V_7 , V_106 ,
V_3 -> V_25 . V_5 . V_63 [ V_76 ] ) )
goto V_103;
F_20 ( & V_3 -> V_65 ) ;
F_33 ( V_7 , V_100 ) ;
return 0 ;
V_103:
F_20 ( & V_3 -> V_65 ) ;
return - 1 ;
}
static int F_34 ( struct V_98 * V_107 [] , struct V_23 * V_3 )
{
struct V_98 * V_108 = V_107 [ V_101 ] ;
struct V_98 * V_109 [ V_110 + 1 ] ;
int V_111 ;
if ( ! V_108 )
return 0 ;
V_111 = F_35 ( V_109 , V_110 , V_108 ,
V_112 , NULL ) ;
if ( V_111 < 0 )
return V_111 ;
if ( ! V_109 [ V_104 ] ||
! V_109 [ V_105 ] ||
! V_109 [ V_106 ] )
return - V_113 ;
F_18 ( & V_3 -> V_65 ) ;
V_3 -> V_25 . V_5 . V_26 = F_36 ( V_109 [ V_104 ] ) ;
V_3 -> V_25 . V_5 . V_63 [ V_82 ] =
F_37 ( V_109 [ V_105 ] ) ;
V_3 -> V_25 . V_5 . V_63 [ V_76 ] =
F_37 ( V_109 [ V_106 ] ) ;
F_20 ( & V_3 -> V_65 ) ;
return 0 ;
}
static int F_38 ( void )
{
return F_39 ( 0 )
+ F_40 ( V_112 , V_110 + 1 ) ;
}
static int F_41 ( struct V_98 * V_109 [] ,
struct V_2 * V_2 , void * V_91 )
{
unsigned int * V_53 = V_91 ;
struct V_1 * V_114 = F_1 ( V_2 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_69 ; V_45 ++ )
V_53 [ V_45 ] = V_114 -> V_53 [ V_45 ] ;
for ( V_45 = V_115 + 1 ; V_45 < V_116 + 1 ; V_45 ++ ) {
if ( V_109 [ V_45 ] ) {
V_53 [ V_45 ] = F_42 ( F_37 ( V_109 [ V_45 ] ) ) * V_117 ;
}
}
return 0 ;
}
static int
F_43 ( struct V_6 * V_7 , const void * V_91 )
{
const unsigned int * V_53 = V_91 ;
int V_45 ;
for ( V_45 = V_115 + 1 ; V_45 < V_116 + 1 ; V_45 ++ ) {
if ( F_32 ( V_7 , V_45 , F_44 ( V_53 [ V_45 ] / V_117 ) ) )
goto V_103;
}
return 0 ;
V_103:
return - V_118 ;
}
static int F_45 ( struct V_119 * V_120 ,
struct V_1 * V_114 )
{
#ifdef F_46
if ( V_120 -> V_121 )
return 0 ;
V_120 -> V_121 = F_47 ( V_122 ,
sizeof( V_122 ) ,
V_123 ) ;
if ( ! V_120 -> V_121 )
return - V_124 ;
V_120 -> V_121 [ 0 ] . V_91 = & V_114 -> V_53 [ V_125 ] ;
V_120 -> V_121 [ 1 ] . V_91 = & V_114 -> V_53 [ V_126 ] ;
V_120 -> V_121 [ 2 ] . V_91 = & V_114 -> V_53 [ V_75 ] ;
V_120 -> V_121 [ 3 ] . V_91 = & V_114 -> V_53 [ V_77 ] ;
V_120 -> V_121 [ 4 ] . V_91 = & V_114 -> V_53 [ V_95 ] ;
V_120 -> V_121 [ 5 ] . V_91 = & V_114 -> V_53 [ V_96 ] ;
V_120 -> V_121 [ 6 ] . V_91 = & V_114 -> V_53 [ V_97 ] ;
V_120 -> V_121 [ 7 ] . V_91 = & V_114 -> V_53 [ V_127 ] ;
V_120 -> V_121 [ 8 ] . V_91 = & V_114 -> V_53 [ V_128 ] ;
#endif
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , T_4 V_25 )
{
struct V_1 * V_114 = F_1 ( V_2 ) ;
struct V_119 * V_120 = & V_114 -> V_120 ;
if ( ! V_120 -> V_129 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_69 ; V_45 ++ )
V_114 -> V_53 [ V_45 ] = V_130 [ V_45 ] ;
}
return F_45 ( V_120 , V_114 ) ;
}
static struct V_119 * F_49 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_120 ;
}
