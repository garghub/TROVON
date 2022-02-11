static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 ;
V_4 = F_2 ( sizeof( struct V_4 ) , V_5 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return - V_6 ;
}
V_4 -> V_7 = V_3 ;
V_2 -> V_8 = V_4 ;
F_4 ( L_2
L_3 , V_2 -> V_9 , V_10 ,
V_11 ) ;
F_4 ( L_4
L_5 ,
V_2 -> V_9 , V_4 -> V_7 , V_12 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_8 ;
F_4 ( L_6
L_7 , V_2 -> V_9 , V_4 -> V_7 ) ;
F_6 ( V_4 ) ;
V_2 -> V_8 = NULL ;
}
static void * F_7 ( struct V_1 * V_2 , const char * V_13 )
{
struct V_14 * V_14 ;
struct V_4 * V_4 = V_2 -> V_8 ;
V_14 = F_2 ( sizeof( struct V_14 ) , V_5 ) ;
if ( ! V_14 ) {
F_3 ( L_8 ) ;
return NULL ;
}
V_14 -> V_4 = V_4 ;
F_4 ( L_9 , V_13 ) ;
return V_14 ;
}
static struct V_15 * F_8 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
void * V_18 )
{
char * V_19 = NULL ;
struct V_15 * V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
struct V_14 * V_14 = V_18 ;
struct V_4 * V_4 = V_2 -> V_8 ;
T_2 V_25 ;
struct V_26 * V_26 ;
struct V_27 * V_27 = NULL ;
int V_28 = 0 , V_29 , V_30 = - V_31 ;
memset ( & V_22 , 0 , sizeof( struct V_21 ) ) ;
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_19 = F_12 ( V_14 -> V_32 ) ;
F_10 ( V_25 ) ;
if ( F_13 ( V_19 ) ) {
F_3 ( L_10 ,
V_14 -> V_32 , F_13 ( V_19 ) ) ;
V_30 = F_14 ( V_19 ) ;
goto V_33;
}
V_29 = V_34 | V_35 | V_36 | V_37 ;
V_26 = F_15 ( V_19 , V_29 , 0600 ) ;
if ( F_13 ( V_26 ) ) {
F_3 ( L_11 , V_19 ) ;
V_30 = F_14 ( V_26 ) ;
goto V_33;
}
if ( ! V_26 || ! V_26 -> V_38 ) {
F_3 ( L_11 , V_19 ) ;
goto V_33;
}
V_14 -> V_39 = V_26 ;
V_27 = V_26 -> V_40 -> V_41 ;
if ( F_16 ( V_27 -> V_42 ) ) {
struct V_43 * V_44 ;
unsigned long long V_45 ;
V_44 = F_17 ( V_27 -> V_46 ) ;
V_24 = & V_22 . V_24 ;
V_24 -> V_47 = F_18 ( V_27 -> V_46 ) ;
V_24 -> V_48 = F_19 ( V_44 ) ;
V_24 -> V_49 = F_20 ( V_44 ) ;
V_14 -> V_50 = F_18 ( V_27 -> V_46 ) ;
V_45 = ( F_21 ( V_26 -> V_40 -> V_41 ) -
V_14 -> V_50 ) ;
F_4 ( L_12
L_13 ,
V_45 , F_22 ( V_45 , V_14 -> V_50 ) ,
V_14 -> V_50 ) ;
} else {
if ( ! ( V_14 -> V_51 & V_52 ) ) {
F_3 ( L_14
L_15
L_16 ) ;
goto V_33;
}
V_24 = & V_22 . V_24 ;
V_24 -> V_47 = V_53 ;
V_24 -> V_48 = V_12 ;
V_24 -> V_49 = V_12 ;
V_14 -> V_50 = V_53 ;
}
V_22 . V_54 = V_55 ;
V_22 . V_56 = V_57 ;
V_20 = F_23 ( V_2 , & V_58 ,
V_17 , V_28 , V_14 ,
& V_22 , L_17 , V_10 ) ;
if ( ! V_20 )
goto V_33;
V_14 -> V_59 = V_4 -> V_60 ++ ;
V_14 -> V_61 = V_20 -> V_56 ;
F_4 ( L_18
L_19 , V_4 -> V_7 , V_14 -> V_59 ,
V_14 -> V_32 , V_14 -> V_62 ) ;
F_24 ( V_19 ) ;
return V_20 ;
V_33:
if ( V_14 -> V_39 ) {
F_25 ( V_14 -> V_39 , NULL ) ;
V_14 -> V_39 = NULL ;
}
F_24 ( V_19 ) ;
return F_26 ( V_30 ) ;
}
static void F_27 ( void * V_18 )
{
struct V_14 * V_14 = V_18 ;
if ( V_14 -> V_39 ) {
F_25 ( V_14 -> V_39 , NULL ) ;
V_14 -> V_39 = NULL ;
}
F_6 ( V_14 ) ;
}
static int F_28 ( struct V_63 * V_64 , struct V_65 * V_66 ,
T_1 V_67 )
{
struct V_15 * V_17 = V_64 -> V_17 ;
struct V_14 * V_20 = V_17 -> V_68 ;
struct V_26 * V_69 = V_20 -> V_39 ;
struct V_65 * V_70 ;
struct V_71 * V_72 ;
T_2 V_25 ;
T_3 V_73 = ( V_64 -> V_74 *
V_17 -> V_75 -> V_76 . V_77 ) ;
int V_30 = 0 , V_78 ;
V_72 = F_2 ( sizeof( struct V_71 ) * V_67 , V_5 ) ;
if ( ! V_72 ) {
F_3 ( L_20 ) ;
return - V_6 ;
}
F_29 (sgl, sg, sgl_nents, i) {
V_72 [ V_78 ] . V_79 = V_70 -> V_80 ;
V_72 [ V_78 ] . V_81 = F_30 ( V_70 ) ;
}
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_30 = F_31 ( V_69 , & V_72 [ 0 ] , V_67 , & V_73 ) ;
F_10 ( V_25 ) ;
F_6 ( V_72 ) ;
if ( F_16 ( V_69 -> V_38 -> V_82 -> V_42 ) ) {
if ( V_30 < 0 || V_30 != V_64 -> V_83 ) {
F_3 ( L_21
L_22 , V_30 ,
( int ) V_64 -> V_83 ) ;
return ( V_30 < 0 ? V_30 : - V_31 ) ;
}
} else {
if ( V_30 < 0 ) {
F_3 ( L_23
L_24 , V_30 ) ;
return V_30 ;
}
}
return 1 ;
}
static int F_32 ( struct V_63 * V_64 , struct V_65 * V_66 ,
T_1 V_67 )
{
struct V_15 * V_17 = V_64 -> V_17 ;
struct V_14 * V_20 = V_17 -> V_68 ;
struct V_26 * V_69 = V_20 -> V_39 ;
struct V_65 * V_70 ;
struct V_71 * V_72 ;
T_2 V_25 ;
T_3 V_73 = ( V_64 -> V_74 *
V_17 -> V_75 -> V_76 . V_77 ) ;
int V_30 , V_78 = 0 ;
V_72 = F_2 ( sizeof( struct V_71 ) * V_67 , V_5 ) ;
if ( ! V_72 ) {
F_3 ( L_25 ) ;
return - V_6 ;
}
F_29 (sgl, sg, sgl_nents, i) {
V_72 [ V_78 ] . V_79 = V_70 -> V_80 ;
V_72 [ V_78 ] . V_81 = F_30 ( V_70 ) ;
}
V_25 = F_9 () ;
F_10 ( F_11 () ) ;
V_30 = F_33 ( V_69 , & V_72 [ 0 ] , V_67 , & V_73 ) ;
F_10 ( V_25 ) ;
F_6 ( V_72 ) ;
if ( V_30 < 0 || V_30 != V_64 -> V_83 ) {
F_3 ( L_26 , V_30 ) ;
return ( V_30 < 0 ? V_30 : - V_31 ) ;
}
return 1 ;
}
static void F_34 ( struct V_63 * V_64 )
{
struct V_15 * V_20 = V_64 -> V_17 ;
struct V_14 * V_14 = V_20 -> V_68 ;
int V_84 = ( V_64 -> V_85 [ 1 ] & 0x2 ) ;
T_3 V_86 , V_87 ;
int V_30 ;
if ( V_84 )
F_35 ( V_64 , V_88 ) ;
if ( V_64 -> V_74 == 0 && V_64 -> V_83 == 0 ) {
V_86 = 0 ;
V_87 = V_89 ;
} else {
V_86 = V_64 -> V_74 * V_20 -> V_75 -> V_76 . V_77 ;
if ( V_64 -> V_83 )
V_87 = V_86 + V_64 -> V_83 ;
else
V_87 = V_89 ;
}
V_30 = F_36 ( V_14 -> V_39 , V_86 , V_87 , 1 ) ;
if ( V_30 != 0 )
F_3 ( L_27 , V_30 ) ;
if ( V_84 )
return;
if ( V_30 ) {
V_64 -> V_90 = V_91 ;
F_35 ( V_64 , V_92 ) ;
} else {
F_35 ( V_64 , V_88 ) ;
}
}
static int F_37 ( struct V_63 * V_64 , struct V_65 * V_66 ,
T_1 V_67 , enum V_93 V_94 )
{
struct V_15 * V_20 = V_64 -> V_17 ;
int V_30 = 0 ;
if ( V_94 == V_95 ) {
V_30 = F_28 ( V_64 , V_66 , V_67 ) ;
} else {
V_30 = F_32 ( V_64 , V_66 , V_67 ) ;
if ( V_30 > 0 &&
V_20 -> V_75 -> V_76 . V_96 > 0 &&
( V_64 -> V_97 & V_98 ) ) {
struct V_14 * V_14 = V_20 -> V_68 ;
T_3 V_86 = V_64 -> V_74 *
V_20 -> V_75 -> V_76 . V_77 ;
T_3 V_87 = V_86 + V_64 -> V_83 ;
F_36 ( V_14 -> V_39 , V_86 , V_87 , 1 ) ;
}
}
if ( V_30 < 0 ) {
V_64 -> V_90 = V_91 ;
return V_30 ;
}
if ( V_30 )
F_35 ( V_64 , V_88 ) ;
return 0 ;
}
static T_4 F_38 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_99 , T_4 V_100 )
{
struct V_14 * V_14 = V_17 -> V_101 ;
char * V_102 , * V_103 , * V_104 , * V_105 ;
T_5 args [ V_106 ] ;
int V_30 = 0 , V_107 ;
V_105 = F_39 ( V_99 , V_5 ) ;
if ( ! V_105 )
return - V_6 ;
V_102 = V_105 ;
while ( ( V_103 = F_40 ( & V_105 , L_28 ) ) != NULL ) {
if ( ! * V_103 )
continue;
V_107 = F_41 ( V_103 , V_108 , args ) ;
switch ( V_107 ) {
case V_109 :
V_104 = F_42 ( & args [ 0 ] ) ;
if ( ! V_104 ) {
V_30 = - V_6 ;
break;
}
snprintf ( V_14 -> V_32 , V_110 ,
L_29 , V_104 ) ;
F_6 ( V_104 ) ;
F_4 ( L_30 ,
V_14 -> V_32 ) ;
V_14 -> V_51 |= V_111 ;
break;
case V_112 :
V_104 = F_42 ( & args [ 0 ] ) ;
if ( ! V_104 ) {
V_30 = - V_6 ;
break;
}
V_30 = F_43 ( V_104 , 0 , & V_14 -> V_62 ) ;
F_6 ( V_104 ) ;
if ( V_30 < 0 ) {
F_3 ( L_31
L_32 ) ;
goto V_113;
}
F_4 ( L_33
L_34 , V_14 -> V_62 ) ;
V_14 -> V_51 |= V_52 ;
break;
default:
break;
}
}
V_113:
F_6 ( V_102 ) ;
return ( ! V_30 ) ? V_100 : V_30 ;
}
static T_4 F_44 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_14 * V_14 = V_17 -> V_101 ;
if ( ! ( V_14 -> V_51 & V_111 ) ) {
F_3 ( L_35 ) ;
return - V_31 ;
}
return 0 ;
}
static T_4 F_45 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
char * V_114 )
{
struct V_14 * V_14 = V_17 -> V_101 ;
T_4 V_115 = 0 ;
V_115 = sprintf ( V_114 + V_115 , L_36 , V_14 -> V_59 ) ;
V_115 += sprintf ( V_114 + V_115 , L_37 ,
V_14 -> V_32 , V_14 -> V_62 ) ;
return V_115 ;
}
static T_1 F_46 ( struct V_15 * V_20 )
{
return V_116 ;
}
static T_1 F_47 ( struct V_15 * V_20 )
{
return V_117 ;
}
static T_6 F_48 ( struct V_15 * V_20 )
{
struct V_14 * V_14 = V_20 -> V_68 ;
struct V_26 * V_118 = V_14 -> V_39 ;
struct V_27 * V_78 = V_118 -> V_40 -> V_41 ;
unsigned long long V_45 ;
if ( F_16 ( V_78 -> V_42 ) )
V_45 = ( F_21 ( V_78 ) - V_14 -> V_50 ) ;
else
V_45 = V_14 -> V_62 ;
return F_22 ( V_45 , V_20 -> V_75 -> V_76 . V_77 ) ;
}
static int T_7 F_49 ( void )
{
return F_50 ( & V_58 ) ;
}
static void F_51 ( void )
{
F_52 ( & V_58 ) ;
}
