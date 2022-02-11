static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( sizeof( struct V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
return - V_9 ;
}
V_7 -> V_10 = V_6 ;
V_5 -> V_11 = V_7 ;
F_6 ( L_2
L_3 , V_5 -> V_12 , V_13 ,
V_14 ) ;
F_6 ( L_4
L_5 ,
V_5 -> V_12 , V_7 -> V_10 , V_15 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = V_5 -> V_11 ;
F_6 ( L_6
L_7 , V_5 -> V_12 , V_7 -> V_10 ) ;
F_8 ( V_7 ) ;
V_5 -> V_11 = NULL ;
}
static struct V_2 * F_9 ( struct V_4 * V_5 , const char * V_16 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = V_5 -> V_11 ;
V_1 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_1 ) {
F_5 ( L_8 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
F_6 ( L_9 , V_16 ) ;
return & V_1 -> V_3 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
struct V_17 * V_17 ;
struct V_18 * V_18 = NULL ;
int V_19 , V_20 = - V_21 ;
if ( ! ( V_1 -> V_22 & V_23 ) ) {
F_5 ( L_10 ) ;
return - V_21 ;
}
V_19 = V_24 | V_25 | V_26 | V_27 ;
if ( V_1 -> V_22 & V_28 ) {
F_6 ( L_11 ) ;
V_19 &= ~ V_27 ;
}
V_17 = F_11 ( V_1 -> V_29 , V_19 , 0600 ) ;
if ( F_12 ( V_17 ) ) {
F_5 ( L_12 , V_1 -> V_29 ) ;
V_20 = F_13 ( V_17 ) ;
goto V_30;
}
V_1 -> V_31 = V_17 ;
V_18 = V_17 -> V_32 -> V_33 ;
if ( F_14 ( V_18 -> V_34 ) ) {
struct V_35 * V_36 = F_15 ( V_18 -> V_37 ) ;
unsigned long long V_38 ;
V_3 -> V_39 . V_40 =
F_16 ( V_18 -> V_37 ) ;
V_3 -> V_39 . V_41 = F_17 ( V_36 ) ;
V_38 = ( F_18 ( V_17 -> V_32 -> V_33 ) -
V_1 -> V_42 ) ;
F_6 ( L_13
L_14 ,
V_38 , F_19 ( V_38 , V_1 -> V_42 ) ,
V_1 -> V_42 ) ;
} else {
if ( ! ( V_1 -> V_22 & V_43 ) ) {
F_5 ( L_15
L_16
L_17 ) ;
goto V_30;
}
V_3 -> V_39 . V_40 = V_44 ;
V_3 -> V_39 . V_41 = V_15 ;
}
V_1 -> V_42 = V_3 -> V_39 . V_40 ;
V_3 -> V_39 . V_45 = V_46 ;
if ( V_1 -> V_22 & V_28 ) {
F_6 ( L_18
L_19 ) ;
V_3 -> V_39 . V_47 = 1 ;
}
V_1 -> V_48 = V_7 -> V_49 ++ ;
V_1 -> V_50 = V_3 -> V_51 ;
F_6 ( L_20
L_21 , V_7 -> V_10 , V_1 -> V_48 ,
V_1 -> V_29 , V_1 -> V_52 ) ;
return 0 ;
V_30:
if ( V_1 -> V_31 ) {
F_20 ( V_1 -> V_31 , NULL ) ;
V_1 -> V_31 = NULL ;
}
return V_20 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_31 ) {
F_20 ( V_1 -> V_31 , NULL ) ;
V_1 -> V_31 = NULL ;
}
F_8 ( V_1 ) ;
}
static int F_22 ( struct V_53 * V_54 , struct V_55 * V_56 ,
T_1 V_57 , int V_58 )
{
struct V_2 * V_59 = V_54 -> V_59 ;
struct V_1 * V_3 = F_1 ( V_59 ) ;
struct V_17 * V_60 = V_3 -> V_31 ;
struct V_55 * V_61 ;
struct V_62 * V_63 ;
T_2 V_64 ;
T_3 V_65 = ( V_54 -> V_66 * V_59 -> V_39 . V_67 ) ;
int V_20 = 0 , V_68 ;
V_63 = F_4 ( sizeof( struct V_62 ) * V_57 , V_8 ) ;
if ( ! V_63 ) {
F_5 ( L_22 ) ;
return - V_9 ;
}
F_23 (sgl, sg, sgl_nents, i) {
V_63 [ V_68 ] . V_69 = V_61 -> V_70 ;
V_63 [ V_68 ] . V_71 = F_24 ( F_25 ( V_61 ) ) + V_61 -> V_72 ;
}
V_64 = F_26 () ;
F_27 ( F_28 () ) ;
if ( V_58 )
V_20 = F_29 ( V_60 , & V_63 [ 0 ] , V_57 , & V_65 ) ;
else
V_20 = F_30 ( V_60 , & V_63 [ 0 ] , V_57 , & V_65 ) ;
F_27 ( V_64 ) ;
F_23 (sgl, sg, sgl_nents, i)
F_31 ( F_25 ( V_61 ) ) ;
F_8 ( V_63 ) ;
if ( V_58 ) {
if ( V_20 < 0 || V_20 != V_54 -> V_73 ) {
F_5 ( L_23 , V_74 , V_20 ) ;
return ( V_20 < 0 ? V_20 : - V_21 ) ;
}
} else {
if ( F_14 ( V_60 -> V_75 -> V_76 -> V_34 ) ) {
if ( V_20 < 0 || V_20 != V_54 -> V_73 ) {
F_5 ( L_24
L_25 , V_74 , V_20 ,
V_54 -> V_73 ) ;
return ( V_20 < 0 ? V_20 : - V_21 ) ;
}
} else {
if ( V_20 < 0 ) {
F_5 ( L_26 ,
V_74 , V_20 ) ;
return V_20 ;
}
}
}
return 1 ;
}
static T_4
F_32 ( struct V_53 * V_54 )
{
struct V_2 * V_3 = V_54 -> V_59 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_77 = ( V_54 -> V_78 [ 1 ] & 0x2 ) ;
T_3 V_79 , V_80 ;
int V_20 ;
if ( V_77 )
F_33 ( V_54 , V_81 ) ;
if ( V_54 -> V_66 == 0 && V_54 -> V_73 == 0 ) {
V_79 = 0 ;
V_80 = V_82 ;
} else {
V_79 = V_54 -> V_66 * V_3 -> V_39 . V_67 ;
if ( V_54 -> V_73 )
V_80 = V_79 + V_54 -> V_73 ;
else
V_80 = V_82 ;
}
V_20 = F_34 ( V_1 -> V_31 , V_79 , V_80 , 1 ) ;
if ( V_20 != 0 )
F_5 ( L_27 , V_20 ) ;
if ( V_77 )
return 0 ;
if ( V_20 )
F_33 ( V_54 , V_83 ) ;
else
F_33 ( V_54 , V_81 ) ;
return 0 ;
}
static T_4
F_35 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_84 ;
T_1 V_57 = V_54 -> V_85 ;
enum V_86 V_87 = V_54 -> V_87 ;
struct V_2 * V_3 = V_54 -> V_59 ;
int V_20 = 0 ;
if ( V_87 == V_88 ) {
V_20 = F_22 ( V_54 , V_56 , V_57 , 0 ) ;
} else {
V_20 = F_22 ( V_54 , V_56 , V_57 , 1 ) ;
if ( V_20 > 0 &&
V_3 -> V_39 . V_89 > 0 &&
( V_54 -> V_90 & V_91 ) ) {
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_79 = V_54 -> V_66 *
V_3 -> V_39 . V_67 ;
T_3 V_80 = V_79 + V_54 -> V_73 ;
F_34 ( V_1 -> V_31 , V_79 , V_80 , 1 ) ;
}
}
if ( V_20 < 0 )
return V_92 ;
if ( V_20 )
F_33 ( V_54 , V_81 ) ;
return 0 ;
}
static T_5 F_36 ( struct V_2 * V_3 ,
const char * V_93 , T_5 V_94 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_95 , * V_96 , * V_97 , * V_98 ;
T_6 args [ V_99 ] ;
int V_20 = 0 , V_100 , V_101 ;
V_98 = F_37 ( V_93 , V_8 ) ;
if ( ! V_98 )
return - V_9 ;
V_95 = V_98 ;
while ( ( V_96 = F_38 ( & V_98 , L_28 ) ) != NULL ) {
if ( ! * V_96 )
continue;
V_101 = F_39 ( V_96 , V_102 , args ) ;
switch ( V_101 ) {
case V_103 :
if ( F_40 ( V_1 -> V_29 , & args [ 0 ] ,
V_104 ) == 0 ) {
V_20 = - V_21 ;
break;
}
F_6 ( L_29 ,
V_1 -> V_29 ) ;
V_1 -> V_22 |= V_23 ;
break;
case V_105 :
V_97 = F_41 ( & args [ 0 ] ) ;
if ( ! V_97 ) {
V_20 = - V_9 ;
break;
}
V_20 = F_42 ( V_97 , 0 , & V_1 -> V_52 ) ;
F_8 ( V_97 ) ;
if ( V_20 < 0 ) {
F_5 ( L_30
L_31 ) ;
goto V_106;
}
F_6 ( L_32
L_33 , V_1 -> V_52 ) ;
V_1 -> V_22 |= V_43 ;
break;
case V_107 :
F_43 ( args , & V_100 ) ;
if ( V_100 != 1 ) {
F_5 ( L_34 , V_100 ) ;
V_20 = - V_21 ;
goto V_106;
}
F_6 ( L_35
L_36 ) ;
V_1 -> V_22 |= V_28 ;
break;
default:
break;
}
}
V_106:
F_8 ( V_95 ) ;
return ( ! V_20 ) ? V_94 : V_20 ;
}
static T_5 F_44 ( struct V_2 * V_3 , char * V_108 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_5 V_109 = 0 ;
V_109 = sprintf ( V_108 + V_109 , L_37 , V_1 -> V_48 ) ;
V_109 += sprintf ( V_108 + V_109 , L_38 ,
V_1 -> V_29 , V_1 -> V_52 ,
( V_1 -> V_22 & V_28 ) ?
L_39 : L_40 ) ;
return V_109 ;
}
static T_7 F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_110 = V_1 -> V_31 ;
struct V_18 * V_68 = V_110 -> V_32 -> V_33 ;
unsigned long long V_38 ;
if ( F_14 ( V_68 -> V_34 ) )
V_38 = ( F_18 ( V_68 ) - V_1 -> V_42 ) ;
else
V_38 = V_1 -> V_52 ;
return F_19 ( V_38 , V_3 -> V_39 . V_67 ) ;
}
static T_4
F_46 ( struct V_53 * V_54 )
{
return F_47 ( V_54 , & V_111 ) ;
}
static int T_8 F_48 ( void )
{
return F_49 ( & V_112 ) ;
}
static void F_50 ( void )
{
F_51 ( & V_112 ) ;
}
