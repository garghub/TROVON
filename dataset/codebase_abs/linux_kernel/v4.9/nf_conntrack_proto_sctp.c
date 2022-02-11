static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static bool F_3 ( const struct V_4 * V_5 , unsigned int V_6 ,
struct V_2 * V_2 , struct V_7 * V_8 )
{
const struct V_9 * V_10 ;
struct V_9 V_11 ;
V_10 = F_4 ( V_5 , V_6 , 4 , & V_11 ) ;
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
F_7 ( V_21 , L_2 , V_24 [ V_23 -> V_25 . V_14 . V_26 ] ) ;
}
static int F_10 ( struct V_22 * V_23 ,
const struct V_4 * V_5 ,
unsigned int V_6 ,
unsigned long * V_27 )
{
T_1 V_28 , V_29 ;
T_2 V_30 , * V_31 ;
int V_32 ;
V_32 = 0 ;
F_11 (skb, sch, _sch, offset, dataoff, count) {
F_12 ( L_3 , V_29 , V_31 -> type ) ;
if ( V_31 -> type == V_33 ||
V_31 -> type == V_34 ||
V_31 -> type == V_35 )
V_32 = 1 ;
if ( ( ( V_31 -> type == V_36 ||
V_31 -> type == V_37 ||
V_32 ) &&
V_29 != 0 ) || ! V_31 -> V_38 ) {
F_12 ( L_4 ) ;
return 1 ;
}
if ( V_27 )
F_13 ( V_31 -> type , V_27 ) ;
}
F_12 ( L_5 ) ;
return V_29 == 0 ;
}
static int F_14 ( enum V_39 V_40 ,
enum V_41 V_42 ,
int V_43 )
{
int V_44 ;
F_12 ( L_6 , V_43 ) ;
switch ( V_43 ) {
case V_33 :
F_12 ( L_7 ) ;
V_44 = 0 ;
break;
case V_34 :
F_12 ( L_8 ) ;
V_44 = 1 ;
break;
case V_45 :
F_12 ( L_9 ) ;
V_44 = 2 ;
break;
case V_46 :
F_12 ( L_10 ) ;
V_44 = 3 ;
break;
case V_47 :
F_12 ( L_11 ) ;
V_44 = 4 ;
break;
case V_48 :
F_12 ( L_12 ) ;
V_44 = 5 ;
break;
case V_37 :
F_12 ( L_13 ) ;
V_44 = 6 ;
break;
case V_36 :
F_12 ( L_14 ) ;
V_44 = 7 ;
break;
case V_35 :
F_12 ( L_15 ) ;
V_44 = 8 ;
break;
case V_49 :
F_12 ( L_16 ) ;
V_44 = 9 ;
break;
case V_50 :
F_12 ( L_17 ) ;
V_44 = 10 ;
break;
default:
F_12 ( L_18 ,
V_24 [ V_42 ] ) ;
return V_42 ;
}
F_12 ( L_19 ,
V_40 , V_24 [ V_42 ] , V_43 ,
V_24 [ V_51 [ V_40 ] [ V_44 ] [ V_42 ] ] ) ;
return V_51 [ V_40 ] [ V_44 ] [ V_42 ] ;
}
static unsigned int * F_15 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_52 ;
}
static int F_16 ( struct V_22 * V_23 ,
const struct V_4 * V_5 ,
unsigned int V_6 ,
enum V_53 V_54 ,
T_3 V_55 ,
unsigned int V_56 ,
unsigned int * V_52 )
{
enum V_41 V_57 , V_58 ;
enum V_39 V_40 = F_17 ( V_54 ) ;
const struct V_9 * V_59 ;
struct V_9 V_60 ;
const struct V_61 * V_31 ;
struct V_61 V_30 ;
T_1 V_28 , V_29 ;
unsigned long V_27 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_59 = F_4 ( V_5 , V_6 , sizeof( V_60 ) , & V_60 ) ;
if ( V_59 == NULL )
goto V_62;
if ( F_10 ( V_23 , V_5 , V_6 , V_27 ) != 0 )
goto V_62;
if ( ! F_18 ( V_33 , V_27 ) &&
! F_18 ( V_35 , V_27 ) &&
! F_18 ( V_37 , V_27 ) &&
! F_18 ( V_45 , V_27 ) &&
! F_18 ( V_47 , V_27 ) &&
! F_18 ( V_49 , V_27 ) &&
! F_18 ( V_50 , V_27 ) &&
V_59 -> V_63 != V_23 -> V_25 . V_14 . V_63 [ V_40 ] ) {
F_12 ( L_20 ) ;
goto V_62;
}
V_58 = V_57 = V_64 ;
F_19 ( & V_23 -> V_65 ) ;
F_11 (skb, sch, _sch, offset, dataoff, count) {
if ( V_31 -> type == V_33 ) {
if ( V_59 -> V_63 != 0 )
goto V_66;
} else if ( V_31 -> type == V_45 ) {
if ( V_59 -> V_63 != V_23 -> V_25 . V_14 . V_63 [ V_40 ] &&
V_59 -> V_63 != V_23 -> V_25 . V_14 . V_63 [ ! V_40 ] )
goto V_66;
} else if ( V_31 -> type == V_35 ) {
if ( V_59 -> V_63 != V_23 -> V_25 . V_14 . V_63 [ V_40 ] &&
V_59 -> V_63 != V_23 -> V_25 . V_14 . V_63 [ ! V_40 ] &&
V_31 -> V_67 & V_68 )
goto V_66;
} else if ( V_31 -> type == V_37 ) {
if ( V_59 -> V_63 != V_23 -> V_25 . V_14 . V_63 [ V_40 ] )
goto V_66;
} else if ( V_31 -> type == V_49 ||
V_31 -> type == V_50 ) {
if ( V_23 -> V_25 . V_14 . V_63 [ V_40 ] == 0 ) {
F_12 ( L_21 ,
V_59 -> V_63 , V_40 ) ;
V_23 -> V_25 . V_14 . V_63 [ V_40 ] = V_59 -> V_63 ;
} else if ( V_59 -> V_63 != V_23 -> V_25 . V_14 . V_63 [ V_40 ] ) {
F_12 ( L_20 ) ;
goto V_66;
}
}
V_58 = V_23 -> V_25 . V_14 . V_26 ;
V_57 = F_14 ( V_40 , V_58 , V_31 -> type ) ;
if ( V_57 == V_69 ) {
F_12 ( L_22
L_23 ,
V_40 , V_31 -> type , V_58 ) ;
goto V_66;
}
if ( V_31 -> type == V_33 ||
V_31 -> type == V_34 ) {
T_4 V_70 , * V_71 ;
V_71 = F_4 ( V_5 , V_28 + sizeof( T_2 ) ,
sizeof( V_70 ) , & V_70 ) ;
if ( V_71 == NULL )
goto V_66;
F_12 ( L_21 ,
V_71 -> V_72 , ! V_40 ) ;
V_23 -> V_25 . V_14 . V_63 [ ! V_40 ] = V_71 -> V_72 ;
}
V_23 -> V_25 . V_14 . V_26 = V_57 ;
if ( V_58 != V_57 )
F_20 ( V_73 , V_23 ) ;
}
F_21 ( & V_23 -> V_65 ) ;
F_22 ( V_23 , V_54 , V_5 , V_52 [ V_57 ] ) ;
if ( V_58 == V_74 &&
V_40 == V_75 &&
V_57 == V_76 ) {
F_12 ( L_24 ) ;
F_13 ( V_77 , & V_23 -> V_78 ) ;
F_20 ( V_79 , V_23 ) ;
}
return V_80 ;
V_66:
F_21 ( & V_23 -> V_65 ) ;
V_62:
return - V_80 ;
}
static bool F_23 ( struct V_22 * V_23 , const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int * V_52 )
{
enum V_41 V_57 ;
const struct V_9 * V_59 ;
struct V_9 V_60 ;
const struct V_61 * V_31 ;
struct V_61 V_30 ;
T_1 V_28 , V_29 ;
unsigned long V_27 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_59 = F_4 ( V_5 , V_6 , sizeof( V_60 ) , & V_60 ) ;
if ( V_59 == NULL )
return false ;
if ( F_10 ( V_23 , V_5 , V_6 , V_27 ) != 0 )
return false ;
if ( F_18 ( V_45 , V_27 ) ||
F_18 ( V_35 , V_27 ) ||
F_18 ( V_36 , V_27 ) )
return false ;
memset ( & V_23 -> V_25 . V_14 , 0 , sizeof( V_23 -> V_25 . V_14 ) ) ;
V_57 = V_69 ;
F_11 (skb, sch, _sch, offset, dataoff, count) {
V_57 = F_14 ( V_81 ,
V_64 , V_31 -> type ) ;
if ( V_57 == V_64 ||
V_57 == V_69 ) {
F_12 ( L_25 ) ;
return false ;
}
if ( V_31 -> type == V_33 ) {
if ( V_59 -> V_63 == 0 ) {
T_4 V_70 , * V_71 ;
V_71 = F_4 ( V_5 , V_28 + sizeof( T_2 ) ,
sizeof( V_70 ) , & V_70 ) ;
if ( V_71 == NULL )
return false ;
F_12 ( L_26 ,
V_71 -> V_72 ) ;
V_23 -> V_25 . V_14 . V_63 [ V_75 ] =
V_71 -> V_72 ;
} else {
return false ;
}
} else if ( V_31 -> type == V_49 ) {
F_12 ( L_27 ,
V_59 -> V_63 ) ;
V_23 -> V_25 . V_14 . V_63 [ V_81 ] = V_59 -> V_63 ;
}
else {
F_12 ( L_28 ,
V_59 -> V_63 ) ;
V_23 -> V_25 . V_14 . V_63 [ V_75 ] = V_59 -> V_63 ;
}
V_23 -> V_25 . V_14 . V_26 = V_57 ;
}
return true ;
}
static int F_24 ( struct V_4 * V_5 , struct V_82 * V_83 ,
struct V_22 * V_23 )
{
struct V_82 * V_84 ;
F_19 ( & V_23 -> V_65 ) ;
V_84 = F_25 ( V_5 , V_85 | V_86 ) ;
if ( ! V_84 )
goto V_87;
if ( F_26 ( V_5 , V_88 , V_23 -> V_25 . V_14 . V_26 ) ||
F_27 ( V_5 , V_89 ,
V_23 -> V_25 . V_14 . V_63 [ V_81 ] ) ||
F_27 ( V_5 , V_90 ,
V_23 -> V_25 . V_14 . V_63 [ V_75 ] ) )
goto V_87;
F_21 ( & V_23 -> V_65 ) ;
F_28 ( V_5 , V_84 ) ;
return 0 ;
V_87:
F_21 ( & V_23 -> V_65 ) ;
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
F_19 ( & V_23 -> V_65 ) ;
V_23 -> V_25 . V_14 . V_26 = F_31 ( V_93 [ V_88 ] ) ;
V_23 -> V_25 . V_14 . V_63 [ V_81 ] =
F_32 ( V_93 [ V_89 ] ) ;
V_23 -> V_25 . V_14 . V_63 [ V_75 ] =
F_32 ( V_93 [ V_90 ] ) ;
F_21 ( & V_23 -> V_65 ) ;
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
unsigned int * V_52 = V_98 ;
struct V_1 * V_99 = F_1 ( V_2 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_69 ; V_44 ++ )
V_52 [ V_44 ] = V_99 -> V_52 [ V_44 ] ;
for ( V_44 = V_100 + 1 ; V_44 < V_101 + 1 ; V_44 ++ ) {
if ( V_93 [ V_44 ] ) {
V_52 [ V_44 ] = F_37 ( F_32 ( V_93 [ V_44 ] ) ) * V_102 ;
}
}
return 0 ;
}
static int
F_38 ( struct V_4 * V_5 , const void * V_98 )
{
const unsigned int * V_52 = V_98 ;
int V_44 ;
for ( V_44 = V_100 + 1 ; V_44 < V_101 + 1 ; V_44 ++ ) {
if ( F_27 ( V_5 , V_44 , F_39 ( V_52 [ V_44 ] / V_102 ) ) )
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
V_105 -> V_106 [ 0 ] . V_98 = & V_99 -> V_52 [ V_110 ] ;
V_105 -> V_106 [ 1 ] . V_98 = & V_99 -> V_52 [ V_111 ] ;
V_105 -> V_106 [ 2 ] . V_98 = & V_99 -> V_52 [ V_74 ] ;
V_105 -> V_106 [ 3 ] . V_98 = & V_99 -> V_52 [ V_76 ] ;
V_105 -> V_106 [ 4 ] . V_98 = & V_99 -> V_52 [ V_112 ] ;
V_105 -> V_106 [ 5 ] . V_98 = & V_99 -> V_52 [ V_113 ] ;
V_105 -> V_106 [ 6 ] . V_98 = & V_99 -> V_52 [ V_114 ] ;
V_105 -> V_106 [ 7 ] . V_98 = & V_99 -> V_52 [ V_115 ] ;
V_105 -> V_106 [ 8 ] . V_98 = & V_99 -> V_52 [ V_116 ] ;
#endif
return 0 ;
}
static int F_43 ( struct V_2 * V_2 , T_5 V_25 )
{
struct V_1 * V_99 = F_1 ( V_2 ) ;
struct V_104 * V_105 = & V_99 -> V_105 ;
if ( ! V_105 -> V_117 ) {
int V_44 ;
for ( V_44 = 0 ; V_44 < V_69 ; V_44 ++ )
V_99 -> V_52 [ V_44 ] = V_118 [ V_44 ] ;
}
return F_40 ( V_105 , V_99 ) ;
}
static int F_44 ( struct V_2 * V_2 )
{
int V_119 = 0 ;
V_119 = F_45 ( V_2 , & V_120 ) ;
if ( V_119 < 0 ) {
F_46 ( L_29 ) ;
goto V_62;
}
V_119 = F_45 ( V_2 , & V_121 ) ;
if ( V_119 < 0 ) {
F_46 ( L_30 ) ;
goto V_122;
}
return 0 ;
V_122:
F_47 ( V_2 , & V_120 ) ;
V_62:
return V_119 ;
}
static void F_48 ( struct V_2 * V_2 )
{
F_47 ( V_2 , & V_121 ) ;
F_47 ( V_2 , & V_120 ) ;
}
static int T_6 F_49 ( void )
{
int V_119 ;
V_119 = F_50 ( & V_123 ) ;
if ( V_119 < 0 )
goto V_124;
V_119 = F_51 ( & V_120 ) ;
if ( V_119 < 0 )
goto V_125;
V_119 = F_51 ( & V_121 ) ;
if ( V_119 < 0 )
goto V_126;
return 0 ;
V_126:
F_52 ( & V_120 ) ;
V_125:
F_53 ( & V_123 ) ;
V_124:
return V_119 ;
}
static void T_7 F_54 ( void )
{
F_52 ( & V_121 ) ;
F_52 ( & V_120 ) ;
F_53 ( & V_123 ) ;
}
