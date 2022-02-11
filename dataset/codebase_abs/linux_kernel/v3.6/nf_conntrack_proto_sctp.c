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
static int F_6 ( struct V_20 * V_21 ,
const struct V_7 * V_8 )
{
return F_7 ( V_21 , L_1 ,
F_8 ( V_8 -> V_12 . V_13 . V_14 . V_15 ) ,
F_8 ( V_8 -> V_17 . V_13 . V_14 . V_15 ) ) ;
}
static int F_9 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
enum V_24 V_25 ;
F_10 ( & V_23 -> V_26 ) ;
V_25 = V_23 -> V_27 . V_14 . V_25 ;
F_11 ( & V_23 -> V_26 ) ;
return F_7 ( V_21 , L_2 , V_28 [ V_25 ] ) ;
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
default:
F_14 ( L_16 ,
V_28 [ V_43 ] ) ;
return V_43 ;
}
F_14 ( L_17 ,
V_42 , V_28 [ V_43 ] , V_44 ,
V_28 [ V_50 [ V_42 ] [ V_45 ] [ V_43 ] ] ) ;
return V_50 [ V_42 ] [ V_45 ] [ V_43 ] ;
}
static unsigned int * F_17 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_51 ;
}
static int F_18 ( struct V_22 * V_23 ,
const struct V_4 * V_5 ,
unsigned int V_6 ,
enum V_52 V_53 ,
T_3 V_54 ,
unsigned int V_55 ,
unsigned int * V_51 )
{
enum V_24 V_56 , V_57 ;
enum V_41 V_42 = F_19 ( V_53 ) ;
const struct V_9 * V_58 ;
struct V_9 V_59 ;
const struct V_60 * V_33 ;
struct V_60 V_32 ;
T_1 V_30 , V_31 ;
unsigned long V_29 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_58 = F_4 ( V_5 , V_6 , sizeof( V_59 ) , & V_59 ) ;
if ( V_58 == NULL )
goto V_61;
if ( F_12 ( V_23 , V_5 , V_6 , V_29 ) != 0 )
goto V_61;
if ( ! F_20 ( V_35 , V_29 ) &&
! F_20 ( V_37 , V_29 ) &&
! F_20 ( V_39 , V_29 ) &&
! F_20 ( V_46 , V_29 ) &&
! F_20 ( V_48 , V_29 ) &&
V_58 -> V_62 != V_23 -> V_27 . V_14 . V_62 [ V_42 ] ) {
F_14 ( L_18 ) ;
goto V_61;
}
V_57 = V_56 = V_63 ;
F_10 ( & V_23 -> V_26 ) ;
F_13 (skb, sch, _sch, offset, dataoff, count) {
if ( V_33 -> type == V_35 ) {
if ( V_58 -> V_62 != 0 )
goto V_64;
} else if ( V_33 -> type == V_46 ) {
if ( V_58 -> V_62 != V_23 -> V_27 . V_14 . V_62 [ V_42 ] &&
V_58 -> V_62 != V_23 -> V_27 . V_14 . V_62 [ ! V_42 ] )
goto V_64;
} else if ( V_33 -> type == V_37 ) {
if ( V_58 -> V_62 != V_23 -> V_27 . V_14 . V_62 [ V_42 ] &&
V_58 -> V_62 != V_23 -> V_27 . V_14 . V_62 [ ! V_42 ] &&
V_33 -> V_65 & V_66 )
goto V_64;
} else if ( V_33 -> type == V_39 ) {
if ( V_58 -> V_62 != V_23 -> V_27 . V_14 . V_62 [ V_42 ] )
goto V_64;
}
V_57 = V_23 -> V_27 . V_14 . V_25 ;
V_56 = F_16 ( V_42 , V_57 , V_33 -> type ) ;
if ( V_56 == V_67 ) {
F_14 ( L_19
L_20 ,
V_42 , V_33 -> type , V_57 ) ;
goto V_64;
}
if ( V_33 -> type == V_35 ||
V_33 -> type == V_36 ) {
T_4 V_68 , * V_69 ;
V_69 = F_4 ( V_5 , V_30 + sizeof( T_2 ) ,
sizeof( V_68 ) , & V_68 ) ;
if ( V_69 == NULL )
goto V_64;
F_14 ( L_21 ,
V_69 -> V_70 , ! V_42 ) ;
V_23 -> V_27 . V_14 . V_62 [ ! V_42 ] = V_69 -> V_70 ;
}
V_23 -> V_27 . V_14 . V_25 = V_56 ;
if ( V_57 != V_56 )
F_21 ( V_71 , V_23 ) ;
}
F_11 ( & V_23 -> V_26 ) ;
F_22 ( V_23 , V_53 , V_5 , V_51 [ V_56 ] ) ;
if ( V_57 == V_72 &&
V_42 == V_73 &&
V_56 == V_74 ) {
F_14 ( L_22 ) ;
F_15 ( V_75 , & V_23 -> V_76 ) ;
F_21 ( V_77 , V_23 ) ;
}
return V_78 ;
V_64:
F_11 ( & V_23 -> V_26 ) ;
V_61:
return - V_78 ;
}
static bool F_23 ( struct V_22 * V_23 , const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int * V_51 )
{
enum V_24 V_56 ;
const struct V_9 * V_58 ;
struct V_9 V_59 ;
const struct V_60 * V_33 ;
struct V_60 V_32 ;
T_1 V_30 , V_31 ;
unsigned long V_29 [ 256 / sizeof( unsigned long )] = { 0 } ;
V_58 = F_4 ( V_5 , V_6 , sizeof( V_59 ) , & V_59 ) ;
if ( V_58 == NULL )
return false ;
if ( F_12 ( V_23 , V_5 , V_6 , V_29 ) != 0 )
return false ;
if ( F_20 ( V_46 , V_29 ) ||
F_20 ( V_37 , V_29 ) ||
F_20 ( V_38 , V_29 ) )
return false ;
memset ( & V_23 -> V_27 . V_14 , 0 , sizeof( V_23 -> V_27 . V_14 ) ) ;
V_56 = V_67 ;
F_13 (skb, sch, _sch, offset, dataoff, count) {
V_56 = F_16 ( V_79 ,
V_63 , V_33 -> type ) ;
if ( V_56 == V_63 ||
V_56 == V_67 ) {
F_14 ( L_23 ) ;
return false ;
}
if ( V_33 -> type == V_35 ) {
if ( V_58 -> V_62 == 0 ) {
T_4 V_68 , * V_69 ;
V_69 = F_4 ( V_5 , V_30 + sizeof( T_2 ) ,
sizeof( V_68 ) , & V_68 ) ;
if ( V_69 == NULL )
return false ;
F_14 ( L_24 ,
V_69 -> V_70 ) ;
V_23 -> V_27 . V_14 . V_62 [ V_73 ] =
V_69 -> V_70 ;
} else {
return false ;
}
}
else {
F_14 ( L_25 ,
V_58 -> V_62 ) ;
V_23 -> V_27 . V_14 . V_62 [ V_73 ] = V_58 -> V_62 ;
}
V_23 -> V_27 . V_14 . V_25 = V_56 ;
}
return true ;
}
static int F_24 ( struct V_4 * V_5 , struct V_80 * V_81 ,
struct V_22 * V_23 )
{
struct V_80 * V_82 ;
F_10 ( & V_23 -> V_26 ) ;
V_82 = F_25 ( V_5 , V_83 | V_84 ) ;
if ( ! V_82 )
goto V_85;
if ( F_26 ( V_5 , V_86 , V_23 -> V_27 . V_14 . V_25 ) ||
F_27 ( V_5 , V_87 ,
V_23 -> V_27 . V_14 . V_62 [ V_79 ] ) ||
F_27 ( V_5 , V_88 ,
V_23 -> V_27 . V_14 . V_62 [ V_73 ] ) )
goto V_85;
F_11 ( & V_23 -> V_26 ) ;
F_28 ( V_5 , V_82 ) ;
return 0 ;
V_85:
F_11 ( & V_23 -> V_26 ) ;
return - 1 ;
}
static int F_29 ( struct V_80 * V_89 [] , struct V_22 * V_23 )
{
struct V_80 * V_90 = V_89 [ V_83 ] ;
struct V_80 * V_91 [ V_92 + 1 ] ;
int V_93 ;
if ( ! V_90 )
return 0 ;
V_93 = F_30 ( V_91 ,
V_92 ,
V_90 ,
V_94 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( ! V_91 [ V_86 ] ||
! V_91 [ V_87 ] ||
! V_91 [ V_88 ] )
return - V_95 ;
F_10 ( & V_23 -> V_26 ) ;
V_23 -> V_27 . V_14 . V_25 = F_31 ( V_91 [ V_86 ] ) ;
V_23 -> V_27 . V_14 . V_62 [ V_79 ] =
F_32 ( V_91 [ V_87 ] ) ;
V_23 -> V_27 . V_14 . V_62 [ V_73 ] =
F_32 ( V_91 [ V_88 ] ) ;
F_11 ( & V_23 -> V_26 ) ;
return 0 ;
}
static int F_33 ( void )
{
return F_34 ( 0 )
+ F_35 ( V_94 , V_92 + 1 ) ;
}
static int F_36 ( struct V_80 * V_91 [] ,
struct V_2 * V_2 , void * V_96 )
{
unsigned int * V_51 = V_96 ;
struct V_1 * V_97 = F_1 ( V_2 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_67 ; V_45 ++ )
V_51 [ V_45 ] = V_97 -> V_51 [ V_45 ] ;
for ( V_45 = V_98 + 1 ; V_45 < V_99 + 1 ; V_45 ++ ) {
if ( V_91 [ V_45 ] ) {
V_51 [ V_45 ] = F_37 ( F_32 ( V_91 [ V_45 ] ) ) * V_100 ;
}
}
return 0 ;
}
static int
F_38 ( struct V_4 * V_5 , const void * V_96 )
{
const unsigned int * V_51 = V_96 ;
int V_45 ;
for ( V_45 = V_98 + 1 ; V_45 < V_99 + 1 ; V_45 ++ ) {
if ( F_27 ( V_5 , V_45 , F_39 ( V_51 [ V_45 ] / V_100 ) ) )
goto V_85;
}
return 0 ;
V_85:
return - V_101 ;
}
static int F_40 ( struct V_102 * V_103 ,
struct V_1 * V_97 )
{
#ifdef F_41
if ( V_103 -> V_104 )
return 0 ;
V_103 -> V_104 = F_42 ( V_105 ,
sizeof( V_105 ) ,
V_106 ) ;
if ( ! V_103 -> V_104 )
return - V_107 ;
V_103 -> V_104 [ 0 ] . V_96 = & V_97 -> V_51 [ V_108 ] ;
V_103 -> V_104 [ 1 ] . V_96 = & V_97 -> V_51 [ V_109 ] ;
V_103 -> V_104 [ 2 ] . V_96 = & V_97 -> V_51 [ V_72 ] ;
V_103 -> V_104 [ 3 ] . V_96 = & V_97 -> V_51 [ V_74 ] ;
V_103 -> V_104 [ 4 ] . V_96 = & V_97 -> V_51 [ V_110 ] ;
V_103 -> V_104 [ 5 ] . V_96 = & V_97 -> V_51 [ V_111 ] ;
V_103 -> V_104 [ 6 ] . V_96 = & V_97 -> V_51 [ V_112 ] ;
#endif
return 0 ;
}
static int F_43 ( struct V_102 * V_103 ,
struct V_1 * V_97 )
{
#ifdef F_41
#ifdef F_44
V_103 -> V_113 = F_42 ( V_114 ,
sizeof( V_114 ) ,
V_106 ) ;
if ( ! V_103 -> V_113 )
return - V_107 ;
V_103 -> V_113 [ 0 ] . V_96 = & V_97 -> V_51 [ V_108 ] ;
V_103 -> V_113 [ 1 ] . V_96 = & V_97 -> V_51 [ V_109 ] ;
V_103 -> V_113 [ 2 ] . V_96 = & V_97 -> V_51 [ V_72 ] ;
V_103 -> V_113 [ 3 ] . V_96 = & V_97 -> V_51 [ V_74 ] ;
V_103 -> V_113 [ 4 ] . V_96 = & V_97 -> V_51 [ V_110 ] ;
V_103 -> V_113 [ 5 ] . V_96 = & V_97 -> V_51 [ V_111 ] ;
V_103 -> V_113 [ 6 ] . V_96 = & V_97 -> V_51 [ V_112 ] ;
#endif
#endif
return 0 ;
}
static int F_45 ( struct V_2 * V_2 , T_5 V_27 )
{
int V_115 ;
struct V_1 * V_97 = F_1 ( V_2 ) ;
struct V_102 * V_103 = & V_97 -> V_103 ;
if ( ! V_103 -> V_116 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_67 ; V_45 ++ )
V_97 -> V_51 [ V_45 ] = V_117 [ V_45 ] ;
}
if ( V_27 == V_118 ) {
V_115 = F_43 ( V_103 , V_97 ) ;
if ( V_115 < 0 )
return V_115 ;
V_115 = F_40 ( V_103 , V_97 ) ;
if ( V_115 < 0 )
F_46 ( V_103 ) ;
} else
V_115 = F_40 ( V_103 , V_97 ) ;
return V_115 ;
}
static int F_47 ( struct V_2 * V_2 )
{
int V_115 = 0 ;
V_115 = F_48 ( V_2 ,
& V_119 ) ;
if ( V_115 < 0 ) {
F_49 ( L_26 ) ;
goto V_61;
}
V_115 = F_48 ( V_2 ,
& V_120 ) ;
if ( V_115 < 0 ) {
F_49 ( L_27 ) ;
goto V_121;
}
return 0 ;
V_121:
F_50 ( V_2 ,
& V_119 ) ;
V_61:
return V_115 ;
}
static void F_51 ( struct V_2 * V_2 )
{
F_50 ( V_2 ,
& V_120 ) ;
F_50 ( V_2 ,
& V_119 ) ;
}
static int T_6 F_52 ( void )
{
return F_53 ( & V_122 ) ;
}
static void T_7 F_54 ( void )
{
F_55 ( & V_122 ) ;
}
