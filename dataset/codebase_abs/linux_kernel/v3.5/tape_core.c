static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + ( V_2 -> V_4 << 16 ) ;
}
static T_1
F_2 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_3 ( V_6 ) ;
return F_4 ( V_9 , V_12 , L_1 , V_11 -> V_13 ) ;
}
static T_1
F_5 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_3 ( V_6 ) ;
return F_4 ( V_9 , V_12 , L_1 , V_11 -> V_14 ) ;
}
static T_1
F_6 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_3 ( V_6 ) ;
return F_4 ( V_9 , V_12 , L_2 , ( V_11 -> V_14 < 0 ) ?
L_3 : V_15 [ V_11 -> V_16 ] ) ;
}
static T_1
F_7 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 ;
T_1 V_17 ;
V_11 = F_3 ( V_6 ) ;
if ( V_11 -> V_14 < 0 )
return F_4 ( V_9 , V_12 , L_4 ) ;
F_8 ( F_9 ( V_11 -> V_18 ) ) ;
if ( F_10 ( & V_11 -> V_19 ) )
V_17 = F_4 ( V_9 , V_12 , L_5 ) ;
else {
struct V_20 * V_21 ;
V_21 = F_11 ( V_11 -> V_19 . V_22 , struct V_20 ,
V_23 ) ;
V_17 = F_4 ( V_9 , V_12 , L_2 , V_24 [ V_21 -> V_25 ] ) ;
}
F_12 ( F_9 ( V_11 -> V_18 ) ) ;
return V_17 ;
}
static T_1
F_13 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_3 ( V_6 ) ;
return F_4 ( V_9 , V_12 , L_1 , V_11 -> V_26 . V_27 ) ;
}
void
F_14 ( struct V_10 * V_5 , enum V_16 V_28 )
{
const char * V_29 ;
if ( V_5 -> V_16 == V_30 ) {
F_15 ( 3 , L_6 ) ;
return;
}
F_15 ( 4 , L_7 , V_5 -> V_14 ) ;
F_15 ( 4 , L_8 ) ;
if ( V_5 -> V_16 < V_31 && V_5 -> V_16 >= 0 )
V_29 = V_15 [ V_5 -> V_16 ] ;
else
V_29 = L_9 ;
F_15 ( 4 , L_2 , V_29 ) ;
F_15 ( 4 , L_10 ) ;
if ( V_28 < V_31 && V_28 >= 0 )
V_29 = V_15 [ V_28 ] ;
else
V_29 = L_9 ;
F_15 ( 4 , L_2 , V_29 ) ;
V_5 -> V_16 = V_28 ;
F_16 ( & V_5 -> V_32 ) ;
}
static void
F_17 ( struct V_33 * V_34 )
{
static char V_35 [] = L_11 ;
static char V_36 [] = L_12 ;
struct V_37 * V_38 =
F_18 ( V_34 , struct V_37 , V_34 ) ;
struct V_10 * V_5 = V_38 -> V_5 ;
char * V_39 [] = { NULL , NULL } ;
switch ( V_38 -> V_40 ) {
case V_41 :
F_19 ( L_13
L_14 , F_20 ( & V_5 -> V_18 -> V_6 ) ) ;
V_39 [ 0 ] = V_36 ;
F_21 ( & V_5 -> V_18 -> V_6 . V_42 , V_43 , V_39 ) ;
break;
case V_44 :
F_19 ( L_15 ,
F_20 ( & V_5 -> V_18 -> V_6 ) ) ;
V_39 [ 0 ] = V_35 ;
F_21 ( & V_5 -> V_18 -> V_6 . V_42 , V_43 , V_39 ) ;
break;
default:
break;
}
F_22 ( V_5 ) ;
F_23 ( V_38 ) ;
}
static void
F_24 ( struct V_10 * V_5 , enum V_45 V_40 )
{
struct V_37 * V_38 ;
V_38 = F_25 ( sizeof( * V_38 ) , V_46 ) ;
if ( V_38 ) {
F_26 ( & V_38 -> V_34 , F_17 ) ;
V_38 -> V_5 = F_27 ( V_5 ) ;
V_38 -> V_40 = V_40 ;
F_28 ( & V_38 -> V_34 ) ;
}
}
void
F_29 ( struct V_10 * V_5 , enum V_45 V_28 )
{
enum V_45 V_47 ;
V_47 = V_5 -> V_13 ;
if ( V_47 == V_28 )
return;
V_5 -> V_13 = V_28 ;
switch( V_28 ) {
case V_41 :
V_5 -> V_48 |= F_30 ( ~ 0 ) ;
if ( V_47 == V_44 )
F_24 ( V_5 , V_41 ) ;
break;
case V_44 :
V_5 -> V_48 &= ~ F_30 ( ~ 0 ) ;
if ( V_47 == V_41 )
F_24 ( V_5 , V_44 ) ;
break;
default:
break;
}
F_16 ( & V_5 -> V_32 ) ;
}
static int
F_31 ( struct V_10 * V_5 , struct V_20 * V_49 )
{
int V_50 ;
int V_17 ;
if ( V_49 -> V_51 == NULL )
return 0 ;
V_17 = 0 ;
for ( V_50 = 0 ; V_50 < 5 ; V_50 ++ ) {
V_17 = F_32 ( V_5 -> V_18 , ( long ) V_49 ) ;
switch ( V_17 ) {
case 0 :
V_49 -> V_52 = V_53 ;
return 0 ;
case - V_54 :
V_49 -> V_52 = V_55 ;
F_33 ( & V_5 -> V_56 , 0 ) ;
return 0 ;
case - V_57 :
F_34 ( 2 , L_16 ) ;
break;
case - V_58 :
F_34 ( 2 , L_17 ) ;
break;
default:
F_35 () ;
}
}
return V_17 ;
}
static int
F_36 ( struct V_10 * V_5 )
{
struct V_10 * V_59 ;
int V_60 ;
V_60 = 0 ;
F_37 ( & V_61 ) ;
F_38 (tmp, &tape_device_list, node) {
if ( V_60 < V_59 -> V_14 )
break;
V_60 += V_62 ;
}
if ( V_60 >= 256 ) {
F_39 ( & V_61 ) ;
return - V_57 ;
}
V_5 -> V_14 = V_60 ;
F_40 ( & V_5 -> V_63 , & V_59 -> V_63 ) ;
F_39 ( & V_61 ) ;
return 0 ;
}
static void
F_41 ( struct V_10 * V_5 )
{
F_37 ( & V_61 ) ;
F_42 ( & V_5 -> V_63 ) ;
V_5 -> V_14 = - 1 ;
F_39 ( & V_61 ) ;
}
int
F_43 ( struct V_10 * V_5 ,
struct V_64 * V_65 )
{
int V_17 ;
F_44 ( 6 , L_18 , V_5 , V_65 ) ;
if ( V_5 -> V_16 != V_66 ) {
F_44 ( 3 , L_19 , V_5 -> V_16 ) ;
return - V_67 ;
}
F_45 ( & V_5 -> V_68 ) ;
V_5 -> V_68 . V_69 = V_70 ;
V_5 -> V_65 = V_65 ;
if ( ! F_46 ( V_65 -> V_71 ) ) {
return - V_67 ;
}
V_17 = V_65 -> V_72 ( V_5 ) ;
if ( V_17 )
goto V_73;
V_17 = F_36 ( V_5 ) ;
if ( V_17 )
goto V_74;
V_17 = F_47 ( V_5 ) ;
if ( V_17 )
goto V_75;
F_14 ( V_5 , V_76 ) ;
F_44 ( 3 , L_20 , V_5 -> V_77 ) ;
return 0 ;
V_75:
F_41 ( V_5 ) ;
V_74:
V_5 -> V_65 -> V_78 ( V_5 ) ;
V_5 -> V_65 = NULL ;
V_73:
F_48 ( V_65 -> V_71 ) ;
return V_17 ;
}
static void
F_49 ( struct V_10 * V_5 )
{
F_50 ( V_5 ) ;
V_5 -> V_65 -> V_78 ( V_5 ) ;
F_48 ( V_5 -> V_65 -> V_71 ) ;
F_41 ( V_5 ) ;
F_29 ( V_5 , V_79 ) ;
}
int F_51 ( struct V_80 * V_18 )
{
struct V_10 * V_5 ;
V_5 = F_3 ( & V_18 -> V_6 ) ;
if ( ! V_5 ) {
return - V_57 ;
}
F_44 ( 3 , L_21 ,
V_5 -> V_77 , V_5 ) ;
if ( V_5 -> V_13 != V_41 ) {
F_52 ( L_22
L_23 , F_20 ( & V_18 -> V_6 ) ) ;
return - V_54 ;
}
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
switch ( V_5 -> V_16 ) {
case V_66 :
case V_30 :
case V_76 :
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
break;
default:
F_52 ( L_24
L_25 , F_20 ( & V_18 -> V_6 ) ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
return - V_54 ;
}
F_44 ( 3 , L_26 , V_5 -> V_77 ) ;
return 0 ;
}
int
F_53 ( struct V_80 * V_18 )
{
struct V_10 * V_5 ;
V_5 = F_3 ( & V_18 -> V_6 ) ;
if ( ! V_5 ) {
return - V_57 ;
}
F_44 ( 3 , L_27 ,
V_5 -> V_77 , V_5 ) ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
switch ( V_5 -> V_16 ) {
case V_66 :
case V_30 :
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
break;
case V_76 :
F_14 ( V_5 , V_66 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
F_49 ( V_5 ) ;
break;
default:
F_15 ( 3 , L_28
L_29 ,
V_5 -> V_77 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
return - V_54 ;
}
F_44 ( 3 , L_30 , V_5 -> V_77 ) ;
return 0 ;
}
static struct V_10 *
F_54 ( void )
{
struct V_10 * V_5 ;
V_5 = F_25 ( sizeof( struct V_10 ) , V_81 ) ;
if ( V_5 == NULL ) {
F_34 ( 2 , L_31 ) ;
return F_55 ( - V_82 ) ;
}
V_5 -> V_83 = F_56 ( 1 , V_81 | V_84 ) ;
if ( V_5 -> V_83 == NULL ) {
F_34 ( 2 , L_31 ) ;
F_23 ( V_5 ) ;
return F_55 ( - V_82 ) ;
}
F_57 ( & V_5 -> V_85 ) ;
F_58 ( & V_5 -> V_19 ) ;
F_58 ( & V_5 -> V_63 ) ;
F_59 ( & V_5 -> V_32 ) ;
F_59 ( & V_5 -> V_86 ) ;
V_5 -> V_16 = V_66 ;
V_5 -> V_13 = V_79 ;
* V_5 -> V_83 = 0 ;
V_5 -> V_14 = - 1 ;
F_60 ( & V_5 -> V_87 , 1 ) ;
F_61 ( & V_5 -> V_56 , V_88 ) ;
return V_5 ;
}
struct V_10 *
F_27 ( struct V_10 * V_5 )
{
int V_89 ;
V_89 = F_62 ( & V_5 -> V_87 ) ;
F_15 ( 4 , L_32 , V_5 , V_89 ) ;
return V_5 ;
}
void
F_22 ( struct V_10 * V_5 )
{
int V_89 ;
V_89 = F_63 ( & V_5 -> V_87 ) ;
F_15 ( 4 , L_33 , V_5 , V_89 ) ;
F_64 ( V_89 < 0 ) ;
if ( V_89 == 0 ) {
F_23 ( V_5 -> V_83 ) ;
F_23 ( V_5 ) ;
}
}
struct V_10 *
F_65 ( int V_90 )
{
struct V_10 * V_5 , * V_59 ;
V_5 = F_55 ( - V_57 ) ;
F_66 ( & V_61 ) ;
F_38 (tmp, &tape_device_list, node) {
if ( V_59 -> V_14 / V_62 == V_90 ) {
V_5 = F_27 ( V_59 ) ;
break;
}
}
F_67 ( & V_61 ) ;
return V_5 ;
}
int
F_68 ( struct V_80 * V_18 )
{
struct V_10 * V_5 ;
int V_91 ;
struct V_1 V_2 ;
V_5 = F_54 () ;
if ( F_69 ( V_5 ) )
return - V_57 ;
F_70 ( V_18 , V_92 |
V_93 ) ;
V_91 = F_71 ( & V_18 -> V_6 . V_42 , & V_94 ) ;
if ( V_91 ) {
F_22 ( V_5 ) ;
return V_91 ;
}
F_72 ( & V_18 -> V_6 , V_5 ) ;
V_18 -> V_95 = V_96 ;
V_5 -> V_18 = V_18 ;
F_73 ( V_18 , & V_2 ) ;
V_5 -> V_77 = F_1 ( & V_2 ) ;
return V_91 ;
}
static void
F_74 ( struct V_10 * V_5 )
{
struct V_20 * V_49 ;
struct V_97 * V_98 , * V_99 ;
F_75 (l, n, &device->req_queue) {
V_49 = F_11 ( V_98 , struct V_20 , V_23 ) ;
if ( V_49 -> V_52 == V_100 )
V_49 -> V_52 = V_53 ;
F_76 ( & V_49 -> V_23 ) ;
V_49 -> V_5 = NULL ;
F_22 ( V_5 ) ;
V_49 -> V_17 = - V_58 ;
if ( V_49 -> V_51 != NULL )
V_49 -> V_51 ( V_49 , V_49 -> V_101 ) ;
}
}
void
F_77 ( struct V_80 * V_18 )
{
struct V_10 * V_5 ;
V_5 = F_3 ( & V_18 -> V_6 ) ;
if ( ! V_5 ) {
return;
}
F_44 ( 3 , L_34 , V_5 -> V_77 , V_18 ) ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
switch ( V_5 -> V_16 ) {
case V_66 :
F_14 ( V_5 , V_30 ) ;
case V_30 :
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
break;
case V_76 :
F_14 ( V_5 , V_30 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
F_49 ( V_5 ) ;
break;
default:
F_15 ( 3 , L_35 ,
V_5 -> V_77 ) ;
F_78 ( L_36
L_37 , F_20 ( & V_5 -> V_18 -> V_6 ) ) ;
F_14 ( V_5 , V_30 ) ;
F_74 ( V_5 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
F_49 ( V_5 ) ;
}
V_5 = F_3 ( & V_18 -> V_6 ) ;
if ( V_5 ) {
F_79 ( & V_18 -> V_6 . V_42 , & V_94 ) ;
F_72 ( & V_18 -> V_6 , NULL ) ;
F_22 ( V_5 ) ;
}
}
struct V_20 *
F_80 ( int V_102 , int V_103 )
{
struct V_20 * V_49 ;
F_64 ( V_103 > V_12 || ( V_102 * sizeof( struct V_104 ) ) > V_12 ) ;
F_44 ( 6 , L_38 , V_102 , V_103 ) ;
V_49 = F_25 ( sizeof( struct V_20 ) , V_81 ) ;
if ( V_49 == NULL ) {
F_34 ( 1 , L_39 ) ;
return F_55 ( - V_82 ) ;
}
if ( V_102 > 0 ) {
V_49 -> V_105 = F_81 ( V_102 , sizeof( struct V_104 ) ,
V_46 | V_84 ) ;
if ( V_49 -> V_105 == NULL ) {
F_34 ( 1 , L_39 ) ;
F_23 ( V_49 ) ;
return F_55 ( - V_82 ) ;
}
}
if ( V_103 > 0 ) {
V_49 -> V_106 = F_25 ( V_103 , V_81 | V_84 ) ;
if ( V_49 -> V_106 == NULL ) {
F_34 ( 1 , L_39 ) ;
F_23 ( V_49 -> V_105 ) ;
F_23 ( V_49 ) ;
return F_55 ( - V_82 ) ;
}
}
F_44 ( 6 , L_40 , V_49 , V_49 -> V_105 ,
V_49 -> V_106 ) ;
return V_49 ;
}
void
F_82 ( struct V_20 * V_49 )
{
F_44 ( 6 , L_41 , V_49 ) ;
if ( V_49 -> V_5 )
F_22 ( V_49 -> V_5 ) ;
F_23 ( V_49 -> V_106 ) ;
F_23 ( V_49 -> V_105 ) ;
F_23 ( V_49 ) ;
}
static int
F_83 ( struct V_10 * V_5 , struct V_20 * V_49 )
{
int V_17 ;
V_17 = F_84 (
V_5 -> V_18 ,
V_49 -> V_105 ,
( unsigned long ) V_49 ,
0x00 ,
V_49 -> V_107
) ;
if ( V_17 == 0 ) {
V_49 -> V_52 = V_100 ;
} else if ( V_17 == - V_54 ) {
V_49 -> V_52 = V_108 ;
F_33 ( & V_5 -> V_56 , 0 ) ;
V_17 = 0 ;
} else {
F_15 ( 1 , L_42 , V_17 ) ;
}
return V_17 ;
}
static void
F_85 ( struct V_10 * V_5 )
{
struct V_97 * V_98 , * V_99 ;
struct V_20 * V_49 ;
int V_17 ;
F_44 ( 6 , L_43 , V_5 ) ;
F_75 (l, n, &device->req_queue) {
V_49 = F_11 ( V_98 , struct V_20 , V_23 ) ;
if ( V_49 -> V_52 == V_100 )
return;
if ( V_49 -> V_52 == V_53 )
return;
if ( V_49 -> V_52 == V_55 ) {
V_17 = F_31 ( V_5 , V_49 ) ;
} else {
V_17 = F_83 ( V_5 , V_49 ) ;
}
if ( V_17 == 0 )
return;
V_49 -> V_17 = V_17 ;
V_49 -> V_52 = V_53 ;
F_76 ( & V_49 -> V_23 ) ;
if ( V_49 -> V_51 != NULL )
V_49 -> V_51 ( V_49 , V_49 -> V_101 ) ;
}
}
static void
V_88 ( struct V_33 * V_34 )
{
struct V_10 * V_5 =
F_18 ( V_34 , struct V_10 , V_56 . V_34 ) ;
F_44 ( 6 , L_44 , V_5 ) ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
F_85 ( V_5 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
}
static void V_70 ( unsigned long V_109 )
{
struct V_20 * V_49 ;
struct V_10 * V_5 ;
V_5 = (struct V_10 * ) V_109 ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
V_49 = F_11 ( V_5 -> V_19 . V_22 , struct V_20 , V_23 ) ;
F_64 ( V_49 -> V_52 != V_110 ) ;
F_44 ( 6 , L_45 , V_5 -> V_77 ) ;
F_85 ( V_5 ) ;
V_5 -> V_68 . V_109 = 0UL ;
F_22 ( V_5 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
}
static void
F_86 (
struct V_10 * V_5 ,
struct V_20 * V_49 ,
int V_17 )
{
F_44 ( 6 , L_46 , V_5 , V_49 , V_17 ) ;
if ( V_49 ) {
V_49 -> V_17 = V_17 ;
V_49 -> V_52 = V_53 ;
F_76 ( & V_49 -> V_23 ) ;
if ( V_49 -> V_51 != NULL )
V_49 -> V_51 ( V_49 , V_49 -> V_101 ) ;
}
if ( ! F_10 ( & V_5 -> V_19 ) )
F_85 ( V_5 ) ;
}
void
F_87 ( struct V_10 * V_5 , struct V_20 * V_49 ,
struct V_111 * V_111 )
{
unsigned int * V_112 ;
const char * V_25 ;
if ( V_49 != NULL )
V_25 = V_24 [ V_49 -> V_25 ] ;
else
V_25 = L_47 ;
F_15 ( 3 , L_48 ,
V_111 -> V_113 . V_114 . V_115 , V_111 -> V_113 . V_114 . V_116 ) ;
F_15 ( 3 , L_49 , V_5 -> V_77 , V_25 ) ;
V_112 = ( unsigned int * ) V_111 -> V_117 ;
F_15 ( 3 , L_50 , V_112 [ 0 ] , V_112 [ 1 ] ) ;
F_15 ( 3 , L_50 , V_112 [ 2 ] , V_112 [ 3 ] ) ;
F_15 ( 3 , L_50 , V_112 [ 4 ] , V_112 [ 5 ] ) ;
F_15 ( 3 , L_50 , V_112 [ 6 ] , V_112 [ 7 ] ) ;
}
static int
F_88 ( struct V_10 * V_5 , struct V_20 * V_49 )
{
int V_17 ;
switch ( V_49 -> V_25 ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
if ( V_5 -> V_16 == V_66 )
break;
if ( V_5 -> V_16 == V_76 )
break;
default:
if ( V_5 -> V_16 == V_123 )
break;
if ( V_5 -> V_16 != V_124 )
return - V_57 ;
}
V_49 -> V_5 = F_27 ( V_5 ) ;
if ( F_10 ( & V_5 -> V_19 ) ) {
V_17 = F_83 ( V_5 , V_49 ) ;
if ( V_17 )
return V_17 ;
F_44 ( 5 , L_51 , V_49 ) ;
F_89 ( & V_49 -> V_23 , & V_5 -> V_19 ) ;
} else {
F_44 ( 5 , L_52 , V_49 ) ;
V_49 -> V_52 = V_108 ;
F_40 ( & V_49 -> V_23 , & V_5 -> V_19 ) ;
}
return 0 ;
}
int
F_90 ( struct V_10 * V_5 , struct V_20 * V_49 )
{
int V_17 ;
F_44 ( 6 , L_53 , V_5 , V_49 ) ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
V_17 = F_88 ( V_5 , V_49 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
return V_17 ;
}
static void
F_91 ( struct V_20 * V_49 , void * V_109 )
{
V_49 -> V_51 = NULL ;
F_16 ( ( V_125 * ) V_109 ) ;
}
int
F_92 ( struct V_10 * V_5 , struct V_20 * V_49 )
{
int V_17 ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
V_49 -> V_51 = F_91 ;
V_49 -> V_101 = & V_5 -> V_86 ;
V_17 = F_88 ( V_5 , V_49 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
if ( V_17 )
return V_17 ;
F_93 ( V_5 -> V_86 , ( V_49 -> V_51 == NULL ) ) ;
return V_49 -> V_17 ;
}
static void
F_94 ( struct V_20 * V_49 , void * V_109 )
{
V_49 -> V_51 = NULL ;
F_95 ( ( V_125 * ) V_109 ) ;
}
int
F_96 ( struct V_10 * V_5 ,
struct V_20 * V_49 )
{
int V_17 ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
V_49 -> V_51 = F_94 ;
V_49 -> V_101 = & V_5 -> V_86 ;
V_17 = F_88 ( V_5 , V_49 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
if ( V_17 )
return V_17 ;
V_17 = F_97 ( V_5 -> V_86 ,
( V_49 -> V_51 == NULL ) ) ;
if ( V_17 != - V_126 )
return V_49 -> V_17 ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
V_17 = F_31 ( V_5 , V_49 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
if ( V_17 == 0 ) {
do {
V_17 = F_97 (
V_5 -> V_86 ,
( V_49 -> V_51 == NULL )
) ;
} while ( V_17 == - V_126 );
F_15 ( 3 , L_54 , V_5 -> V_77 ) ;
V_17 = - V_126 ;
}
return V_17 ;
}
int
F_98 ( struct V_10 * V_5 , struct V_20 * V_49 )
{
int V_17 ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
V_17 = F_31 ( V_5 , V_49 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
return V_17 ;
}
static void
V_96 ( struct V_80 * V_18 , unsigned long V_127 , struct V_111 * V_111 )
{
struct V_10 * V_5 ;
struct V_20 * V_49 ;
int V_17 ;
V_5 = F_3 ( & V_18 -> V_6 ) ;
if ( V_5 == NULL ) {
return;
}
V_49 = (struct V_20 * ) V_127 ;
F_44 ( 6 , L_55 , V_5 , V_49 ) ;
if ( F_69 ( V_111 ) ) {
switch ( F_99 ( V_111 ) ) {
case - V_128 :
F_44 ( 1 , L_56 ,
V_5 -> V_77 ) ;
case - V_58 :
F_86 ( V_5 , V_49 , - V_58 ) ;
break;
default:
F_44 ( 1 , L_57 ,
V_5 -> V_77 , F_99 ( V_111 ) ) ;
}
return;
}
if ( V_111 -> V_113 . V_114 . V_129 != 0 &&
( V_111 -> V_113 . V_114 . V_130 & V_131 ) &&
( V_49 -> V_52 == V_100 ) ) {
F_15 ( 3 , L_58 ,
V_5 -> V_77 , V_111 -> V_113 . V_114 . V_129 , V_111 -> V_113 . V_114 . V_130 ) ;
V_49 -> V_52 = V_108 ;
F_33 ( & V_5 -> V_56 , V_132 ) ;
return;
}
if( V_49 != NULL )
V_49 -> V_133 = V_111 -> V_113 . V_114 . V_89 ;
else if ( ( V_111 -> V_113 . V_114 . V_115 == 0x85 || V_111 -> V_113 . V_114 . V_115 == 0x80 ) &&
! F_10 ( & V_5 -> V_19 ) ) {
struct V_20 * V_21 ;
V_21 = F_11 ( V_5 -> V_19 . V_22 ,
struct V_20 , V_23 ) ;
if ( V_21 -> V_52 == V_110 ) {
F_15 ( 3 , L_59 , V_5 -> V_77 ) ;
if ( F_100 ( & V_5 -> V_68 ) ) {
V_5 -> V_68 . V_109 = 0UL ;
F_22 ( V_5 ) ;
F_85 ( V_5 ) ;
}
return;
}
}
if ( V_111 -> V_113 . V_114 . V_115 != 0x0c ) {
if( * ( ( ( V_134 * ) V_111 -> V_117 ) + 1 ) & V_135 )
V_5 -> V_48 |= F_101 ( ~ 0 ) ;
else
V_5 -> V_48 &= ~ F_101 ( ~ 0 ) ;
F_15 ( 3 , L_60 ) ;
F_87 ( V_5 , V_49 , V_111 ) ;
} else {
V_5 -> V_48 |= F_101 ( ~ 0 ) ;
}
if ( V_5 -> V_16 == V_30 ) {
F_15 ( 6 , L_61 ) ;
return;
}
if( V_49 != NULL && V_49 -> V_52 == V_53 ) {
F_86 ( V_5 , V_49 , - V_58 ) ;
return;
}
V_17 = V_5 -> V_65 -> V_136 ( V_5 , V_49 , V_111 ) ;
switch ( V_17 ) {
case V_137 :
V_5 -> V_48 |= F_101 ( ~ 0 ) ;
F_86 ( V_5 , V_49 , V_17 ) ;
break;
case V_138 :
break;
case V_139 :
V_5 -> V_68 . V_109 =
( unsigned long ) F_27 ( V_5 ) ;
V_5 -> V_68 . V_140 = V_141 +
V_142 * V_132 ;
F_15 ( 3 , L_62 , V_5 -> V_77 ) ;
F_102 ( & V_5 -> V_68 ) ;
V_49 -> V_52 = V_110 ;
break;
case V_143 :
V_17 = F_83 ( V_5 , V_49 ) ;
if ( V_17 )
F_86 ( V_5 , V_49 , V_17 ) ;
break;
case V_144 :
V_17 = F_31 ( V_5 , V_49 ) ;
if ( V_17 )
F_86 ( V_5 , V_49 , V_17 ) ;
break;
default:
if ( V_17 > 0 ) {
F_15 ( 6 , L_63 ) ;
F_86 ( V_5 , V_49 , - V_58 ) ;
} else {
F_86 ( V_5 , V_49 , V_17 ) ;
}
break;
}
}
int
F_103 ( struct V_10 * V_5 )
{
int V_17 ;
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
if ( V_5 -> V_16 == V_30 ) {
F_15 ( 6 , L_64 ) ;
V_17 = - V_57 ;
} else if ( V_5 -> V_16 == V_124 ) {
F_15 ( 6 , L_65 ) ;
V_17 = - V_54 ;
} else if ( V_5 -> V_16 == V_123 ) {
F_15 ( 6 , L_65 ) ;
V_17 = - V_54 ;
} else if ( V_5 -> V_65 != NULL &&
! F_46 ( V_5 -> V_65 -> V_71 ) ) {
F_15 ( 6 , L_66 ) ;
V_17 = - V_57 ;
} else {
F_14 ( V_5 , V_124 ) ;
V_17 = 0 ;
}
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
return V_17 ;
}
int
F_104 ( struct V_10 * V_5 )
{
F_8 ( F_9 ( V_5 -> V_18 ) ) ;
if ( V_5 -> V_16 == V_124 )
F_14 ( V_5 , V_76 ) ;
F_48 ( V_5 -> V_65 -> V_71 ) ;
F_12 ( F_9 ( V_5 -> V_18 ) ) ;
return 0 ;
}
int
F_105 ( struct V_10 * V_5 , int V_145 , int V_146 )
{
T_2 V_147 ;
int V_17 ;
F_15 ( 6 , L_67 ) ;
F_15 ( 6 , L_68 , V_145 ) ;
F_15 ( 6 , L_69 , V_146 ) ;
if ( V_145 < 0 || V_145 >= V_148 )
return - V_67 ;
V_147 = V_5 -> V_65 -> V_149 [ V_145 ] ;
if ( V_147 == NULL )
return - V_67 ;
if ( V_145 == V_150 || V_145 == V_151 || V_145 == V_152 ||
V_145 == V_153 || V_145 == V_154 || V_145 == V_155 ) {
V_17 = 0 ;
for (; V_146 > 500 ; V_146 -= 500 )
if ( ( V_17 = V_147 ( V_5 , 500 ) ) != 0 )
break;
if ( V_17 == 0 )
V_17 = V_147 ( V_5 , V_146 ) ;
} else
V_17 = V_147 ( V_5 , V_146 ) ;
return V_17 ;
}
static int
F_106 ( void )
{
V_156 = F_107 ( L_70 , 2 , 2 , 4 * sizeof( long ) ) ;
F_108 ( V_156 , & V_157 ) ;
#ifdef F_109
F_110 ( V_156 , 6 ) ;
#endif
F_15 ( 3 , L_71 ) ;
F_111 () ;
F_112 () ;
return 0 ;
}
static void
F_113 ( void )
{
F_15 ( 6 , L_72 ) ;
F_114 () ;
F_115 () ;
F_116 ( V_156 ) ;
}
