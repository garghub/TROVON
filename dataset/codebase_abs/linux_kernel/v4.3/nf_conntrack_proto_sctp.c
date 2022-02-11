static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static bool F_3 ( const struct V_4 * V_5 , unsigned int V_6 ,
struct V_7 * V_8 )
{
const struct V_9 * V_10 ;
struct V_9 V_11 ;
V_10 = F_4 ( V_5 , V_6 , 8 , & V_11 ) ;
if ( V_10 == NULL )
return false ;
V_8 -> V_12 . V_13 . V_14 . V_15 = V_10 -> V_16 ;
V_8 -> V_17 . V_13 . V_14 . V_15 = V_10 -> V_18 ;
return true ;
}
static bool F_5 ( struct V_7 * V_8 ,
const struct V_7 * V_19 )
{
V_8 -> V_12 . V_13 . V_14 . V_15 = V_19 -> V_17 . V_13 . V_14 . V_15 ;
V_8 -> V_17 . V_13 . V_14 . V_15 = V_19 -> V_12 . V_13 . V_14 . V_15 ;
return true ;
}
static void F_6 ( struct V_20 * V_21 ,
const struct V_7 * V_8 )
{
F_7 ( V_21 , L_1 ,
F_8 ( V_8 -> V_12 . V_13 . V_14 . V_15 ) ,
F_8 ( V_8 -> V_17 . V_13 . V_14 . V_15 ) ) ;
}
static void F_9 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
enum V_24 V_25 ;
F_10 ( & V_23 -> V_26 ) ;
V_25 = V_23 -> V_27 . V_14 . V_25 ;
F_11 ( & V_23 -> V_26 ) ;
F_7 ( V_21 , L_2 , V_28 [ V_25 ] ) ;
}
static int F_12 ( struct V_22 * V_23 ,
const struct V_4 * V_5 ,
unsigned int V_6 ,
unsigned long * V_29 )
{
T_1 V_30 , V_31 ;
T_2 V_32 , * V_33 ;
int V_34 ;
V_34 = 0 ;
F_13 (skb, sch, _sch, offset, dataoff, count) {
F_14 ( L_3 , V_31 , V_33 -> type ) ;
if ( V_33 -> type == V_35 ||
V_33 -> type == V_36 ||
V_33 -> type == V_37 )
V_34 = 1 ;
if ( ( ( V_33 -> type == V_38 ||
V_33 -> type == V_39 ||
V_34 ) &&
V_31 != 0 ) || ! V_33 -> V_40 ) {
F_14 ( L_4 ) ;
return 1 ;
}
if ( V_29 )
F_15 ( V_33 -> type , V_29 ) ;
}
F_14 ( L_5 ) ;
return V_31 == 0 ;
}
static int F_16 ( enum V_41 V_42 ,
enum V_24 V_43 ,
int V_44 )
{
int V_45 ;
F_14 ( L_6 , V_44 ) ;
switch ( V_44 ) {
case V_35 :
F_14 ( L_7 ) ;
V_45 = 0 ;
break;
case V_36 :
F_14 ( L_8 ) ;
V_45 = 1 ;
break;
case V_46 :
F_14 ( L_9 ) ;
V_45 = 2 ;
break;
case V_47 :
F_14 ( L_10 ) ;
V_45 = 3 ;
break;
case V_48 :
F_14 ( L_11 ) ;
V_45 = 4 ;
break;
case V_49 :
F_14 ( L_12 ) ;
V_45 = 5 ;
break;
case V_39 :
F_14 ( L_13 ) ;
V_45 = 6 ;
break;
case V_38 :
F_14 ( L_14 ) ;
V_45 = 7 ;
break;
case V_37 :
F_14 ( L_15 ) ;
V_45 = 8 ;
break;
case V_50 :
F_14 ( L_16 ) ;
V_45 = 9 ;
break;
case V_51 :
F_14 ( L_17 ) ;
V_45 = 10 ;
break;
default:
F_14 ( L_18 ,
V_28 [ V_43 ] ) ;
return V_43 ;
}
F_14 ( L_19 ,
V_42 , V_28 [ V_43 ] , V_44 ,
V_28 [ V_52 [ V_42 ] [ V_45 ] [ V_43 ] ] ) ;
return V_52 [ V_42 ] [ V_45 ] [ V_43 ] ;
}
static unsigned int * F_17 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_53 ;
}
static int F_18 ( struct V_22 * V_23 ,
const struct V_4 * V_5 ,
unsigned int V_6 ,
enum V_54 V_55 ,
T_3 V_56 ,
unsigned int V_57 ,
unsigned int * V_53 )
{
enum V_24 V_58 , V_59 ;
enum V_41 V_42 = F_19 ( V_55 ) ;
const struct V_9 * V_60 ;
struct V_9 V_61 ;
const struct V_62 * V_33 ;
struct V_62 V_32 ;
T_1 V_30 , V_31 ;
unsigned long V_29 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_60 = F_4 ( V_5 , V_6 , sizeof( V_61 ) , & V_61 ) ;
if ( V_60 == NULL )
goto V_63;
if ( F_12 ( V_23 , V_5 , V_6 , V_29 ) != 0 )
goto V_63;
if ( ! F_20 ( V_35 , V_29 ) &&
! F_20 ( V_37 , V_29 ) &&
! F_20 ( V_39 , V_29 ) &&
! F_20 ( V_46 , V_29 ) &&
! F_20 ( V_48 , V_29 ) &&
! F_20 ( V_50 , V_29 ) &&
! F_20 ( V_51 , V_29 ) &&
V_60 -> V_64 != V_23 -> V_27 . V_14 . V_64 [ V_42 ] ) {
F_14 ( L_20 ) ;
goto V_63;
}
V_59 = V_58 = V_65 ;
F_10 ( & V_23 -> V_26 ) ;
F_13 (skb, sch, _sch, offset, dataoff, count) {
if ( V_33 -> type == V_35 ) {
if ( V_60 -> V_64 != 0 )
goto V_66;
} else if ( V_33 -> type == V_46 ) {
if ( V_60 -> V_64 != V_23 -> V_27 . V_14 . V_64 [ V_42 ] &&
V_60 -> V_64 != V_23 -> V_27 . V_14 . V_64 [ ! V_42 ] )
goto V_66;
} else if ( V_33 -> type == V_37 ) {
if ( V_60 -> V_64 != V_23 -> V_27 . V_14 . V_64 [ V_42 ] &&
V_60 -> V_64 != V_23 -> V_27 . V_14 . V_64 [ ! V_42 ] &&
V_33 -> V_67 & V_68 )
goto V_66;
} else if ( V_33 -> type == V_39 ) {
if ( V_60 -> V_64 != V_23 -> V_27 . V_14 . V_64 [ V_42 ] )
goto V_66;
} else if ( V_33 -> type == V_50 ||
V_33 -> type == V_51 ) {
if ( V_23 -> V_27 . V_14 . V_64 [ V_42 ] == 0 ) {
F_14 ( L_21 ,
V_60 -> V_64 , V_42 ) ;
V_23 -> V_27 . V_14 . V_64 [ V_42 ] = V_60 -> V_64 ;
} else if ( V_60 -> V_64 != V_23 -> V_27 . V_14 . V_64 [ V_42 ] ) {
F_14 ( L_20 ) ;
goto V_66;
}
}
V_59 = V_23 -> V_27 . V_14 . V_25 ;
V_58 = F_16 ( V_42 , V_59 , V_33 -> type ) ;
if ( V_58 == V_69 ) {
F_14 ( L_22
L_23 ,
V_42 , V_33 -> type , V_59 ) ;
goto V_66;
}
if ( V_33 -> type == V_35 ||
V_33 -> type == V_36 ) {
T_4 V_70 , * V_71 ;
V_71 = F_4 ( V_5 , V_30 + sizeof( T_2 ) ,
sizeof( V_70 ) , & V_70 ) ;
if ( V_71 == NULL )
goto V_66;
F_14 ( L_21 ,
V_71 -> V_72 , ! V_42 ) ;
V_23 -> V_27 . V_14 . V_64 [ ! V_42 ] = V_71 -> V_72 ;
}
V_23 -> V_27 . V_14 . V_25 = V_58 ;
if ( V_59 != V_58 )
F_21 ( V_73 , V_23 ) ;
}
F_11 ( & V_23 -> V_26 ) ;
F_22 ( V_23 , V_55 , V_5 , V_53 [ V_58 ] ) ;
if ( V_59 == V_74 &&
V_42 == V_75 &&
V_58 == V_76 ) {
F_14 ( L_24 ) ;
F_15 ( V_77 , & V_23 -> V_78 ) ;
F_21 ( V_79 , V_23 ) ;
}
return V_80 ;
V_66:
F_11 ( & V_23 -> V_26 ) ;
V_63:
return - V_80 ;
}
static bool F_23 ( struct V_22 * V_23 , const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int * V_53 )
{
enum V_24 V_58 ;
const struct V_9 * V_60 ;
struct V_9 V_61 ;
const struct V_62 * V_33 ;
struct V_62 V_32 ;
T_1 V_30 , V_31 ;
unsigned long V_29 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_60 = F_4 ( V_5 , V_6 , sizeof( V_61 ) , & V_61 ) ;
if ( V_60 == NULL )
return false ;
if ( F_12 ( V_23 , V_5 , V_6 , V_29 ) != 0 )
return false ;
if ( F_20 ( V_46 , V_29 ) ||
F_20 ( V_37 , V_29 ) ||
F_20 ( V_38 , V_29 ) )
return false ;
memset ( & V_23 -> V_27 . V_14 , 0 , sizeof( V_23 -> V_27 . V_14 ) ) ;
V_58 = V_69 ;
F_13 (skb, sch, _sch, offset, dataoff, count) {
V_58 = F_16 ( V_81 ,
V_65 , V_33 -> type ) ;
if ( V_58 == V_65 ||
V_58 == V_69 ) {
F_14 ( L_25 ) ;
return false ;
}
if ( V_33 -> type == V_35 ) {
if ( V_60 -> V_64 == 0 ) {
T_4 V_70 , * V_71 ;
V_71 = F_4 ( V_5 , V_30 + sizeof( T_2 ) ,
sizeof( V_70 ) , & V_70 ) ;
if ( V_71 == NULL )
return false ;
F_14 ( L_26 ,
V_71 -> V_72 ) ;
V_23 -> V_27 . V_14 . V_64 [ V_75 ] =
V_71 -> V_72 ;
} else {
return false ;
}
} else if ( V_33 -> type == V_50 ) {
F_14 ( L_27 ,
V_60 -> V_64 ) ;
V_23 -> V_27 . V_14 . V_64 [ V_81 ] = V_60 -> V_64 ;
}
else {
F_14 ( L_28 ,
V_60 -> V_64 ) ;
V_23 -> V_27 . V_14 . V_64 [ V_75 ] = V_60 -> V_64 ;
}
V_23 -> V_27 . V_14 . V_25 = V_58 ;
}
return true ;
}
static int F_24 ( struct V_4 * V_5 , struct V_82 * V_83 ,
struct V_22 * V_23 )
{
struct V_82 * V_84 ;
F_10 ( & V_23 -> V_26 ) ;
V_84 = F_25 ( V_5 , V_85 | V_86 ) ;
if ( ! V_84 )
goto V_87;
if ( F_26 ( V_5 , V_88 , V_23 -> V_27 . V_14 . V_25 ) ||
F_27 ( V_5 , V_89 ,
V_23 -> V_27 . V_14 . V_64 [ V_81 ] ) ||
F_27 ( V_5 , V_90 ,
V_23 -> V_27 . V_14 . V_64 [ V_75 ] ) )
goto V_87;
F_11 ( & V_23 -> V_26 ) ;
F_28 ( V_5 , V_84 ) ;
return 0 ;
V_87:
F_11 ( & V_23 -> V_26 ) ;
return - 1 ;
}
static int F_29 ( struct V_82 * V_91 [] , struct V_22 * V_23 )
{
struct V_82 * V_92 = V_91 [ V_85 ] ;
struct V_82 * V_93 [ V_94 + 1 ] ;
int V_95 ;
if ( ! V_92 )
return 0 ;
V_95 = F_30 ( V_93 ,
V_94 ,
V_92 ,
V_96 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! V_93 [ V_88 ] ||
! V_93 [ V_89 ] ||
! V_93 [ V_90 ] )
return - V_97 ;
F_10 ( & V_23 -> V_26 ) ;
V_23 -> V_27 . V_14 . V_25 = F_31 ( V_93 [ V_88 ] ) ;
V_23 -> V_27 . V_14 . V_64 [ V_81 ] =
F_32 ( V_93 [ V_89 ] ) ;
V_23 -> V_27 . V_14 . V_64 [ V_75 ] =
F_32 ( V_93 [ V_90 ] ) ;
F_11 ( & V_23 -> V_26 ) ;
return 0 ;
}
static int F_33 ( void )
{
return F_34 ( 0 )
+ F_35 ( V_96 , V_94 + 1 ) ;
}
static int F_36 ( struct V_82 * V_93 [] ,
struct V_2 * V_2 , void * V_98 )
{
unsigned int * V_53 = V_98 ;
struct V_1 * V_99 = F_1 ( V_2 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_69 ; V_45 ++ )
V_53 [ V_45 ] = V_99 -> V_53 [ V_45 ] ;
for ( V_45 = V_100 + 1 ; V_45 < V_101 + 1 ; V_45 ++ ) {
if ( V_93 [ V_45 ] ) {
V_53 [ V_45 ] = F_37 ( F_32 ( V_93 [ V_45 ] ) ) * V_102 ;
}
}
return 0 ;
}
static int
F_38 ( struct V_4 * V_5 , const void * V_98 )
{
const unsigned int * V_53 = V_98 ;
int V_45 ;
for ( V_45 = V_100 + 1 ; V_45 < V_101 + 1 ; V_45 ++ ) {
if ( F_27 ( V_5 , V_45 , F_39 ( V_53 [ V_45 ] / V_102 ) ) )
goto V_87;
}
return 0 ;
V_87:
return - V_103 ;
}
static int F_40 ( struct V_104 * V_105 ,
struct V_1 * V_99 )
{
#ifdef F_41
if ( V_105 -> V_106 )
return 0 ;
V_105 -> V_106 = F_42 ( V_107 ,
sizeof( V_107 ) ,
V_108 ) ;
if ( ! V_105 -> V_106 )
return - V_109 ;
V_105 -> V_106 [ 0 ] . V_98 = & V_99 -> V_53 [ V_110 ] ;
V_105 -> V_106 [ 1 ] . V_98 = & V_99 -> V_53 [ V_111 ] ;
V_105 -> V_106 [ 2 ] . V_98 = & V_99 -> V_53 [ V_74 ] ;
V_105 -> V_106 [ 3 ] . V_98 = & V_99 -> V_53 [ V_76 ] ;
V_105 -> V_106 [ 4 ] . V_98 = & V_99 -> V_53 [ V_112 ] ;
V_105 -> V_106 [ 5 ] . V_98 = & V_99 -> V_53 [ V_113 ] ;
V_105 -> V_106 [ 6 ] . V_98 = & V_99 -> V_53 [ V_114 ] ;
V_105 -> V_106 [ 7 ] . V_98 = & V_99 -> V_53 [ V_115 ] ;
V_105 -> V_106 [ 8 ] . V_98 = & V_99 -> V_53 [ V_116 ] ;
#endif
return 0 ;
}
static int F_43 ( struct V_104 * V_105 ,
struct V_1 * V_99 )
{
#ifdef F_41
#ifdef F_44
V_105 -> V_117 = F_42 ( V_118 ,
sizeof( V_118 ) ,
V_108 ) ;
if ( ! V_105 -> V_117 )
return - V_109 ;
V_105 -> V_117 [ 0 ] . V_98 = & V_99 -> V_53 [ V_110 ] ;
V_105 -> V_117 [ 1 ] . V_98 = & V_99 -> V_53 [ V_111 ] ;
V_105 -> V_117 [ 2 ] . V_98 = & V_99 -> V_53 [ V_74 ] ;
V_105 -> V_117 [ 3 ] . V_98 = & V_99 -> V_53 [ V_76 ] ;
V_105 -> V_117 [ 4 ] . V_98 = & V_99 -> V_53 [ V_112 ] ;
V_105 -> V_117 [ 5 ] . V_98 = & V_99 -> V_53 [ V_113 ] ;
V_105 -> V_117 [ 6 ] . V_98 = & V_99 -> V_53 [ V_114 ] ;
#endif
#endif
return 0 ;
}
static int F_45 ( struct V_2 * V_2 , T_5 V_27 )
{
int V_119 ;
struct V_1 * V_99 = F_1 ( V_2 ) ;
struct V_104 * V_105 = & V_99 -> V_105 ;
if ( ! V_105 -> V_120 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_69 ; V_45 ++ )
V_99 -> V_53 [ V_45 ] = V_121 [ V_45 ] ;
}
if ( V_27 == V_122 ) {
V_119 = F_43 ( V_105 , V_99 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_40 ( V_105 , V_99 ) ;
if ( V_119 < 0 )
F_46 ( V_105 ) ;
} else
V_119 = F_40 ( V_105 , V_99 ) ;
return V_119 ;
}
static int F_47 ( struct V_2 * V_2 )
{
int V_119 = 0 ;
V_119 = F_48 ( V_2 , & V_123 ) ;
if ( V_119 < 0 ) {
F_49 ( L_29 ) ;
goto V_63;
}
V_119 = F_48 ( V_2 , & V_124 ) ;
if ( V_119 < 0 ) {
F_49 ( L_30 ) ;
goto V_125;
}
return 0 ;
V_125:
F_50 ( V_2 , & V_123 ) ;
V_63:
return V_119 ;
}
static void F_51 ( struct V_2 * V_2 )
{
F_50 ( V_2 , & V_124 ) ;
F_50 ( V_2 , & V_123 ) ;
}
static int T_6 F_52 ( void )
{
int V_119 ;
V_119 = F_53 ( & V_126 ) ;
if ( V_119 < 0 )
goto V_127;
V_119 = F_54 ( & V_123 ) ;
if ( V_119 < 0 )
goto V_128;
V_119 = F_54 ( & V_124 ) ;
if ( V_119 < 0 )
goto V_129;
return 0 ;
V_129:
F_55 ( & V_123 ) ;
V_128:
F_56 ( & V_126 ) ;
V_127:
return V_119 ;
}
static void T_7 F_57 ( void )
{
F_55 ( & V_124 ) ;
F_55 ( & V_123 ) ;
F_56 ( & V_126 ) ;
}
