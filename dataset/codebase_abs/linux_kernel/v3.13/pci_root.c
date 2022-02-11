int F_1 ( T_1 V_1 )
{
int V_2 ;
struct V_3 * V_4 ;
V_2 = F_2 ( V_1 , & V_4 ) ;
if ( V_2 )
return 0 ;
V_2 = F_3 ( V_4 , V_5 ) ;
if ( V_2 )
return 0 ;
else
return 1 ;
}
static T_2
F_4 ( struct V_6 * V_7 , void * V_8 )
{
struct V_7 * V_9 = V_8 ;
struct V_10 V_11 ;
T_2 V_12 ;
V_12 = F_5 ( V_7 , & V_11 ) ;
if ( F_6 ( V_12 ) )
return V_13 ;
if ( ( V_11 . V_14 > 0 ) &&
( V_11 . V_15 == V_16 ) ) {
V_9 -> V_17 = V_11 . V_18 ;
V_9 -> V_19 = V_11 . V_18 + V_11 . V_14 - 1 ;
}
return V_13 ;
}
static T_2 F_7 ( T_1 V_1 ,
struct V_7 * V_9 )
{
T_2 V_12 ;
V_9 -> V_17 = - 1 ;
V_12 =
F_8 ( V_1 , V_20 ,
F_4 , V_9 ) ;
if ( F_6 ( V_12 ) )
return V_12 ;
if ( V_9 -> V_17 == - 1 )
return V_21 ;
return V_13 ;
}
static void F_9 ( struct V_22 * V_23 , char * V_24 , T_3 V_25 ,
struct V_26 * V_27 , int V_28 )
{
char V_29 [ 80 ] ;
int V_30 , V_31 = 0 ;
struct V_26 * V_32 ;
V_29 [ 0 ] = '\0' ;
for ( V_30 = 0 , V_32 = V_27 ; V_30 < V_28 ; V_30 ++ , V_32 ++ )
if ( V_25 & V_32 -> V_33 )
V_31 += snprintf ( V_29 + V_31 , sizeof( V_29 ) - V_31 , L_1 ,
V_31 ? L_2 : L_3 , V_32 -> V_34 ) ;
F_10 ( & V_23 -> V_4 -> V_35 , L_4 , V_24 , V_29 ) ;
}
static void F_11 ( struct V_22 * V_23 , char * V_24 , T_3 V_25 )
{
F_9 ( V_23 , V_24 , V_25 , V_36 ,
F_12 ( V_36 ) ) ;
}
static void F_13 ( struct V_22 * V_23 , char * V_24 , T_3 V_25 )
{
F_9 ( V_23 , V_24 , V_25 , V_37 ,
F_12 ( V_37 ) ) ;
}
static T_2 F_14 ( T_1 V_1 ,
const T_3 * V_38 , T_3 * V_39 )
{
struct V_40 V_41 = {
. V_42 = V_43 ,
. V_44 = 1 ,
. V_45 . V_46 = 12 ,
. V_45 . V_47 = ( void * ) V_38 ,
} ;
T_2 V_12 ;
V_12 = F_15 ( V_1 , & V_41 ) ;
if ( F_16 ( V_12 ) ) {
* V_39 = * ( ( T_3 * ) ( V_41 . V_2 . V_47 + 8 ) ) ;
F_17 ( V_41 . V_2 . V_47 ) ;
}
return V_12 ;
}
static T_2 F_18 ( struct V_22 * V_23 ,
T_3 V_48 ,
T_3 * V_49 )
{
T_2 V_12 ;
T_3 V_50 , V_38 [ 3 ] ;
V_48 &= V_51 ;
V_48 |= V_23 -> V_52 ;
V_38 [ V_53 ] = V_54 ;
V_38 [ V_55 ] = V_48 ;
if ( V_49 ) {
* V_49 &= V_56 ;
V_38 [ V_57 ] = * V_49 | V_23 -> V_58 ;
} else {
V_38 [ V_57 ] = V_23 -> V_58 ;
}
V_12 = F_14 ( V_23 -> V_4 -> V_1 , V_38 , & V_50 ) ;
if ( F_16 ( V_12 ) ) {
V_23 -> V_52 = V_48 ;
if ( V_49 )
* V_49 = V_50 ;
}
return V_12 ;
}
static T_2 F_19 ( struct V_22 * V_23 , T_3 V_59 )
{
T_2 V_12 ;
F_20 ( & V_60 ) ;
V_12 = F_18 ( V_23 , V_59 , NULL ) ;
F_21 ( & V_60 ) ;
return V_12 ;
}
struct V_22 * F_22 ( T_1 V_1 )
{
struct V_22 * V_23 ;
struct V_3 * V_4 ;
if ( F_2 ( V_1 , & V_4 ) ||
F_3 ( V_4 , V_5 ) )
return NULL ;
V_23 = F_23 ( V_4 ) ;
return V_23 ;
}
struct V_61 * F_24 ( T_1 V_1 )
{
int V_35 , V_62 ;
unsigned long long V_63 ;
T_2 V_12 ;
T_1 V_64 ;
struct V_65 * V_66 ;
struct V_61 * V_67 = NULL ;
struct V_68 * V_69 , * V_70 ;
struct V_22 * V_23 ;
F_25 ( V_71 ) ;
V_64 = V_1 ;
while ( ! F_1 ( V_64 ) ) {
V_69 = F_26 ( sizeof( struct V_68 ) , V_72 ) ;
if ( ! V_69 )
goto V_73;
F_27 ( & V_69 -> V_69 ) ;
V_69 -> V_1 = V_64 ;
F_28 ( & V_69 -> V_69 , & V_71 ) ;
V_12 = F_29 ( V_64 , & V_64 ) ;
if ( F_6 ( V_12 ) )
goto V_73;
}
V_23 = F_22 ( V_64 ) ;
if ( ! V_23 )
goto V_73;
V_66 = V_23 -> V_74 ;
F_30 (node, &device_list, node) {
T_1 V_75 = V_69 -> V_1 ;
V_12 = F_31 ( V_75 , L_5 , NULL , & V_63 ) ;
if ( F_6 ( V_12 ) )
goto V_73;
V_35 = ( V_63 >> 16 ) & 0xffff ;
V_62 = V_63 & 0xffff ;
V_67 = F_32 ( V_66 , F_33 ( V_35 , V_62 ) ) ;
if ( ! V_67 || V_75 == V_1 )
break;
V_66 = V_67 -> V_76 ;
F_34 ( V_67 ) ;
if ( ! V_66 ) {
F_35 ( & V_67 -> V_35 , L_6 ) ;
V_67 = NULL ;
break;
}
}
V_73:
F_36 (node, tmp, &device_list, node)
F_17 ( V_69 ) ;
return V_67 ;
}
T_2 F_37 ( T_1 V_1 , T_3 * V_77 , T_3 V_78 )
{
struct V_22 * V_23 ;
T_2 V_12 = V_13 ;
T_3 V_79 , V_38 [ 3 ] ;
if ( ! V_77 )
return V_80 ;
V_79 = * V_77 & V_56 ;
if ( ( V_79 & V_78 ) != V_78 )
return V_81 ;
V_23 = F_22 ( V_1 ) ;
if ( ! V_23 )
return V_82 ;
F_20 ( & V_60 ) ;
* V_77 = V_79 | V_23 -> V_58 ;
if ( ( V_23 -> V_58 & V_79 ) == V_79 )
goto V_73;
while ( * V_77 ) {
V_12 = F_18 ( V_23 , V_23 -> V_52 , V_77 ) ;
if ( F_6 ( V_12 ) )
goto V_73;
if ( V_79 == * V_77 )
break;
F_13 ( V_23 , L_7 ,
V_79 & ~ ( * V_77 ) ) ;
V_79 = * V_77 ;
}
if ( ( V_79 & V_78 ) != V_78 ) {
F_13 ( V_23 , L_8 ,
V_78 & ~ ( V_79 ) ) ;
V_12 = V_83 ;
goto V_73;
}
V_38 [ V_53 ] = 0 ;
V_38 [ V_55 ] = V_23 -> V_52 ;
V_38 [ V_57 ] = V_79 ;
V_12 = F_14 ( V_1 , V_38 , V_77 ) ;
if ( F_16 ( V_12 ) )
V_23 -> V_58 = * V_77 ;
V_73:
F_21 ( & V_60 ) ;
return V_12 ;
}
static void F_38 ( struct V_22 * V_23 , int * V_84 ,
int * V_85 )
{
T_3 V_48 , V_49 , V_86 ;
T_2 V_12 ;
struct V_3 * V_4 = V_23 -> V_4 ;
T_1 V_1 = V_4 -> V_1 ;
V_48 = V_87 ;
if ( F_39 () )
V_48 |= V_88 ;
if ( F_40 () )
V_48 |= V_89 | V_90 ;
if ( F_41 () )
V_48 |= V_91 ;
F_11 ( V_23 , L_9 , V_48 ) ;
V_12 = F_19 ( V_23 , V_48 ) ;
if ( F_6 ( V_12 ) ) {
F_10 ( & V_4 -> V_35 , L_10 ,
F_42 ( V_12 ) ) ;
* V_84 = 1 ;
return;
}
if ( V_92 ) {
F_10 ( & V_4 -> V_35 , L_11 ) ;
return;
}
if ( ( V_48 & V_93 ) != V_93 ) {
F_11 ( V_23 , L_12 ,
V_93 ) ;
return;
}
V_49 = V_94
| V_95
| V_96 ;
if ( F_43 () ) {
if ( F_44 () )
F_10 ( & V_4 -> V_35 ,
L_13 ) ;
else
V_49 |= V_97 ;
}
V_86 = V_49 ;
V_12 = F_37 ( V_1 , & V_49 ,
V_94 ) ;
if ( F_16 ( V_12 ) ) {
F_13 ( V_23 , L_14 , V_49 ) ;
if ( V_98 . V_99 & V_100 ) {
* V_85 = 1 ;
}
} else {
F_13 ( V_23 , L_15 , V_86 ) ;
F_13 ( V_23 , L_16 , V_49 ) ;
F_10 ( & V_4 -> V_35 , L_10 ,
F_42 ( V_12 ) ) ;
* V_84 = 1 ;
}
}
static int F_45 ( struct V_3 * V_4 ,
const struct V_101 * V_102 )
{
unsigned long long V_103 , V_74 ;
T_2 V_12 ;
int V_50 ;
struct V_22 * V_23 ;
T_1 V_1 = V_4 -> V_1 ;
int V_84 = 0 , V_85 = 0 ;
V_23 = F_26 ( sizeof( struct V_22 ) , V_72 ) ;
if ( ! V_23 )
return - V_104 ;
V_103 = 0 ;
V_12 = F_31 ( V_1 , V_105 , NULL ,
& V_103 ) ;
if ( F_6 ( V_12 ) && V_12 != V_106 ) {
F_46 ( & V_4 -> V_35 , L_17 ) ;
V_50 = - V_107 ;
goto V_19;
}
V_23 -> V_108 . V_59 = V_109 ;
V_12 = F_7 ( V_1 , & V_23 -> V_108 ) ;
if ( F_6 ( V_12 ) ) {
V_23 -> V_108 . V_19 = 0xFF ;
F_47 ( & V_4 -> V_35 ,
V_110 L_18 ) ;
V_12 = F_31 ( V_1 , V_111 ,
NULL , & V_74 ) ;
if ( F_16 ( V_12 ) )
V_23 -> V_108 . V_17 = V_74 ;
else if ( V_12 == V_106 )
V_23 -> V_108 . V_17 = 0 ;
else {
F_46 ( & V_4 -> V_35 , L_19 ) ;
V_50 = - V_107 ;
goto V_19;
}
}
V_23 -> V_4 = V_4 ;
V_23 -> V_103 = V_103 & 0xFFFF ;
strcpy ( F_48 ( V_4 ) , V_112 ) ;
strcpy ( F_49 ( V_4 ) , V_113 ) ;
V_4 -> V_114 = V_23 ;
F_50 ( V_115 L_20 ,
F_48 ( V_4 ) , F_51 ( V_4 ) ,
V_23 -> V_103 , & V_23 -> V_108 ) ;
V_23 -> V_116 = F_52 ( V_1 ) ;
F_38 ( V_23 , & V_84 , & V_85 ) ;
V_23 -> V_74 = F_53 ( V_23 ) ;
if ( ! V_23 -> V_74 ) {
F_46 ( & V_4 -> V_35 ,
L_21 ,
V_23 -> V_103 , ( unsigned int ) V_23 -> V_108 . V_17 ) ;
V_4 -> V_114 = NULL ;
V_50 = - V_107 ;
goto V_19;
}
if ( V_85 ) {
F_10 ( & V_4 -> V_35 , L_22 ) ;
F_54 ( V_23 -> V_74 ) ;
}
if ( V_84 )
F_55 () ;
F_56 ( V_4 , V_23 -> V_74 ) ;
if ( V_4 -> V_117 . V_59 . V_118 )
F_57 ( V_23 -> V_74 -> V_119 , true ) ;
if ( V_120 != V_121 ) {
F_58 ( V_23 -> V_74 ) ;
F_59 ( V_23 -> V_74 ) ;
}
F_60 ( V_23 -> V_74 ) ;
return 1 ;
V_19:
F_17 ( V_23 ) ;
return V_50 ;
}
static void F_61 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = F_23 ( V_4 ) ;
F_62 ( V_23 -> V_74 ) ;
F_57 ( V_23 -> V_74 -> V_119 , false ) ;
F_63 ( V_4 ) ;
F_64 ( V_23 -> V_74 ) ;
F_17 ( V_23 ) ;
}
void T_4 F_65 ( void )
{
F_66 () ;
if ( ! V_122 ) {
F_67 () ;
F_68 ( & V_123 ) ;
}
}
static void F_69 ( T_1 V_1 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_1 , & V_4 ) ) {
F_70 ( V_124 , & V_4 -> V_35 ,
L_23 ) ;
return;
}
if ( F_71 ( V_1 ) )
F_72 ( V_1 , L_24 ) ;
}
static void F_73 ( void * V_8 , T_3 type )
{
T_1 V_1 = V_8 ;
struct V_22 * V_23 ;
F_74 () ;
V_23 = F_22 ( V_1 ) ;
switch ( type ) {
case V_125 :
F_75 ( V_124 , V_1 ,
L_25 , V_126 ) ;
if ( V_23 )
F_76 ( V_1 ) ;
else
F_69 ( V_1 ) ;
break;
case V_127 :
F_75 ( V_124 , V_1 ,
L_26 , V_126 ) ;
if ( ! V_23 )
F_69 ( V_1 ) ;
break;
case V_128 :
F_75 ( V_124 , V_1 ,
L_27 , V_126 ) ;
if ( ! V_23 )
break;
F_77 ( & V_23 -> V_4 -> V_35 ) ;
F_78 () ;
F_79 ( V_23 -> V_4 , V_128 ) ;
return;
default:
F_80 ( V_1 ,
L_28 ,
type ) ;
break;
}
F_78 () ;
}
static void F_81 ( T_1 V_1 , T_3 type ,
void * V_41 )
{
F_82 ( F_73 , V_1 , type ) ;
}
static T_2 T_4
F_83 ( T_1 V_1 , T_3 V_129 , void * V_41 , void * * V_130 )
{
T_2 V_12 ;
int * V_131 = ( int * ) V_41 ;
if ( ! F_1 ( V_1 ) )
return V_13 ;
( * V_131 ) ++ ;
V_12 = F_84 ( V_1 , V_132 ,
F_81 , NULL ) ;
if ( F_6 ( V_12 ) )
F_75 ( V_124 , V_1 ,
L_29 ,
( unsigned int ) V_12 ) ;
else
F_75 ( V_124 , V_1 ,
L_30 ) ;
return V_13 ;
}
void T_4 F_85 ( void )
{
int V_133 = 0 ;
F_86 ( V_134 , V_135 ,
V_136 , F_83 , NULL , & V_133 , NULL ) ;
F_87 ( V_124 L_31 , V_133 ) ;
}
