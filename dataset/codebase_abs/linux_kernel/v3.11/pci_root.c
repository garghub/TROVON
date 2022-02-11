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
static T_2 F_9 ( T_1 V_1 ,
const T_3 * V_22 , T_3 * V_23 )
{
struct V_24 V_25 = {
. V_26 = V_27 ,
. V_28 = 1 ,
. V_29 . V_30 = 12 ,
. V_29 . V_31 = ( void * ) V_22 ,
} ;
T_2 V_12 ;
V_12 = F_10 ( V_1 , & V_25 ) ;
if ( F_11 ( V_12 ) ) {
* V_23 = * ( ( T_3 * ) ( V_25 . V_2 . V_31 + 8 ) ) ;
F_12 ( V_25 . V_2 . V_31 ) ;
}
return V_12 ;
}
static T_2 F_13 ( struct V_32 * V_33 ,
T_3 V_34 ,
T_3 * V_35 )
{
T_2 V_12 ;
T_3 V_36 , V_22 [ 3 ] ;
V_34 &= V_37 ;
V_34 |= V_33 -> V_38 ;
V_22 [ V_39 ] = V_40 ;
V_22 [ V_41 ] = V_34 ;
if ( V_35 ) {
* V_35 &= V_42 ;
V_22 [ V_43 ] = * V_35 | V_33 -> V_44 ;
} else {
V_22 [ V_43 ] = V_33 -> V_44 ;
}
V_12 = F_9 ( V_33 -> V_4 -> V_1 , V_22 , & V_36 ) ;
if ( F_11 ( V_12 ) ) {
V_33 -> V_38 = V_34 ;
if ( V_35 )
* V_35 = V_36 ;
}
return V_12 ;
}
static T_2 F_14 ( struct V_32 * V_33 , T_3 V_45 )
{
T_2 V_12 ;
T_1 V_46 ;
V_12 = F_15 ( V_33 -> V_4 -> V_1 , L_1 , & V_46 ) ;
if ( F_6 ( V_12 ) )
return V_12 ;
F_16 ( & V_47 ) ;
V_12 = F_13 ( V_33 , V_45 , NULL ) ;
F_17 ( & V_47 ) ;
return V_12 ;
}
struct V_32 * F_18 ( T_1 V_1 )
{
struct V_32 * V_33 ;
struct V_3 * V_4 ;
if ( F_2 ( V_1 , & V_4 ) ||
F_3 ( V_4 , V_5 ) )
return NULL ;
V_33 = F_19 ( V_4 ) ;
return V_33 ;
}
struct V_48 * F_20 ( T_1 V_1 )
{
int V_49 , V_50 ;
unsigned long long V_51 ;
T_2 V_12 ;
T_1 V_52 ;
struct V_53 * V_54 ;
struct V_48 * V_55 = NULL ;
struct V_56 * V_57 , * V_46 ;
struct V_32 * V_33 ;
F_21 ( V_58 ) ;
V_52 = V_1 ;
while ( ! F_1 ( V_52 ) ) {
V_57 = F_22 ( sizeof( struct V_56 ) , V_59 ) ;
if ( ! V_57 )
goto V_60;
F_23 ( & V_57 -> V_57 ) ;
V_57 -> V_1 = V_52 ;
F_24 ( & V_57 -> V_57 , & V_58 ) ;
V_12 = F_25 ( V_52 , & V_52 ) ;
if ( F_6 ( V_12 ) )
goto V_60;
}
V_33 = F_18 ( V_52 ) ;
if ( ! V_33 )
goto V_60;
V_54 = V_33 -> V_61 ;
F_26 (node, &device_list, node) {
T_1 V_62 = V_57 -> V_1 ;
V_12 = F_27 ( V_62 , L_2 , NULL , & V_51 ) ;
if ( F_6 ( V_12 ) )
goto V_60;
V_49 = ( V_51 >> 16 ) & 0xffff ;
V_50 = V_51 & 0xffff ;
V_55 = F_28 ( V_54 , F_29 ( V_49 , V_50 ) ) ;
if ( ! V_55 || V_62 == V_1 )
break;
V_54 = V_55 -> V_63 ;
F_30 ( V_55 ) ;
if ( ! V_54 ) {
F_31 ( & V_55 -> V_49 , L_3 ) ;
V_55 = NULL ;
break;
}
}
V_60:
F_32 (node, tmp, &device_list, node)
F_12 ( V_57 ) ;
return V_55 ;
}
T_2 F_33 ( T_1 V_1 , T_3 * V_64 , T_3 V_65 )
{
struct V_32 * V_33 ;
T_2 V_12 ;
T_3 V_66 , V_22 [ 3 ] ;
T_1 V_46 ;
if ( ! V_64 )
return V_67 ;
V_66 = * V_64 & V_42 ;
if ( ( V_66 & V_65 ) != V_65 )
return V_68 ;
V_33 = F_18 ( V_1 ) ;
if ( ! V_33 )
return V_69 ;
V_12 = F_15 ( V_1 , L_1 , & V_46 ) ;
if ( F_6 ( V_12 ) )
return V_12 ;
F_16 ( & V_47 ) ;
* V_64 = V_66 | V_33 -> V_44 ;
if ( ( V_33 -> V_44 & V_66 ) == V_66 )
goto V_60;
while ( * V_64 ) {
V_12 = F_13 ( V_33 , V_33 -> V_38 , V_64 ) ;
if ( F_6 ( V_12 ) )
goto V_60;
if ( V_66 == * V_64 )
break;
V_66 = * V_64 ;
}
if ( ( V_66 & V_65 ) != V_65 ) {
V_12 = V_70 ;
goto V_60;
}
V_22 [ V_39 ] = 0 ;
V_22 [ V_41 ] = V_33 -> V_38 ;
V_22 [ V_43 ] = V_66 ;
V_12 = F_9 ( V_1 , V_22 , V_64 ) ;
if ( F_11 ( V_12 ) )
V_33 -> V_44 = * V_64 ;
V_60:
F_17 ( & V_47 ) ;
return V_12 ;
}
static int F_34 ( struct V_3 * V_4 ,
const struct V_71 * V_72 )
{
unsigned long long V_73 , V_61 ;
T_2 V_12 ;
int V_36 ;
struct V_32 * V_33 ;
T_3 V_45 , V_74 ;
T_1 V_1 = V_4 -> V_1 ;
V_33 = F_22 ( sizeof( struct V_32 ) , V_59 ) ;
if ( ! V_33 )
return - V_75 ;
V_73 = 0 ;
V_12 = F_27 ( V_1 , V_76 , NULL ,
& V_73 ) ;
if ( F_6 ( V_12 ) && V_12 != V_77 ) {
F_35 ( & V_4 -> V_49 , L_4 ) ;
V_36 = - V_78 ;
goto V_19;
}
V_33 -> V_79 . V_45 = V_80 ;
V_12 = F_7 ( V_1 , & V_33 -> V_79 ) ;
if ( F_6 ( V_12 ) ) {
V_33 -> V_79 . V_19 = 0xFF ;
F_36 ( & V_4 -> V_49 ,
V_81 L_5 ) ;
V_12 = F_27 ( V_1 , V_82 ,
NULL , & V_61 ) ;
if ( F_11 ( V_12 ) )
V_33 -> V_79 . V_17 = V_61 ;
else if ( V_12 == V_77 )
V_33 -> V_79 . V_17 = 0 ;
else {
F_35 ( & V_4 -> V_49 , L_6 ) ;
V_36 = - V_78 ;
goto V_19;
}
}
V_33 -> V_4 = V_4 ;
V_33 -> V_73 = V_73 & 0xFFFF ;
strcpy ( F_37 ( V_4 ) , V_83 ) ;
strcpy ( F_38 ( V_4 ) , V_84 ) ;
V_4 -> V_85 = V_33 ;
F_39 ( V_86 L_7 ,
F_37 ( V_4 ) , F_40 ( V_4 ) ,
V_33 -> V_73 , & V_33 -> V_79 ) ;
V_33 -> V_87 = F_41 ( V_1 ) ;
V_45 = V_74 = V_88 ;
F_14 ( V_33 , V_45 ) ;
V_33 -> V_61 = F_42 ( V_33 ) ;
if ( ! V_33 -> V_61 ) {
F_35 ( & V_4 -> V_49 ,
L_8 ,
V_33 -> V_73 , ( unsigned int ) V_33 -> V_79 . V_17 ) ;
V_36 = - V_78 ;
goto V_19;
}
if ( F_43 () )
V_45 |= V_89 ;
if ( F_44 () ) {
V_45 |= V_90 |
V_91 ;
}
if ( F_45 () )
V_45 |= V_92 ;
if ( V_45 != V_74 ) {
V_12 = F_14 ( V_33 , V_45 ) ;
if ( F_6 ( V_12 ) ) {
F_46 ( & V_4 -> V_49 , L_9
L_10 ) ;
F_47 () ;
V_45 = V_74 ;
}
}
if ( ! V_93
&& ( V_45 & V_94 ) == V_94 ) {
V_45 = V_95
| V_96
| V_97 ;
if ( F_48 () ) {
if ( F_49 () )
F_31 ( & V_4 -> V_49 ,
L_11 ) ;
else
V_45 |= V_98 ;
}
F_46 ( & V_4 -> V_49 ,
L_12 , V_45 ) ;
V_12 = F_33 ( V_1 , & V_45 ,
V_95 ) ;
if ( F_11 ( V_12 ) ) {
F_46 ( & V_4 -> V_49 ,
L_13 , V_45 ) ;
if ( V_99 . V_100 & V_101 ) {
F_50 ( V_33 -> V_61 ) ;
}
} else {
F_46 ( & V_4 -> V_49 ,
L_14
L_15 ,
F_51 ( V_12 ) , V_45 ) ;
F_46 ( & V_4 -> V_49 ,
L_16 ) ;
F_47 () ;
}
} else {
F_46 ( & V_4 -> V_49 ,
L_17
L_18 , V_45 ) ;
}
F_52 ( V_4 , V_33 -> V_61 ) ;
if ( V_4 -> V_102 . V_45 . V_103 )
F_53 ( V_33 -> V_61 -> V_104 , true ) ;
if ( V_105 != V_106 ) {
F_54 ( V_33 -> V_61 ) ;
F_55 ( V_33 -> V_61 ) ;
F_56 ( V_33 -> V_61 ) ;
}
F_57 ( V_33 -> V_61 ) ;
return 1 ;
V_19:
F_12 ( V_33 ) ;
return V_36 ;
}
static void F_58 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = F_19 ( V_4 ) ;
F_59 ( V_33 -> V_61 ) ;
F_53 ( V_33 -> V_61 -> V_104 , false ) ;
F_60 ( V_4 ) ;
F_61 ( V_33 -> V_61 ) ;
F_12 ( V_33 ) ;
}
void T_4 F_62 ( void )
{
F_63 () ;
if ( ! V_107 ) {
F_64 () ;
F_65 ( & V_108 ) ;
}
}
static void F_66 ( T_1 V_1 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_1 , & V_4 ) ) {
F_67 ( V_109 , & V_4 -> V_49 ,
L_19 ) ;
return;
}
if ( F_68 ( V_1 ) )
F_69 ( V_1 , L_20 ) ;
}
static void F_70 ( struct V_3 * V_4 )
{
T_2 V_12 ;
struct V_110 * V_111 ;
V_111 = F_71 ( sizeof( * V_111 ) , V_59 ) ;
if ( ! V_111 ) {
( void ) F_72 ( V_4 -> V_1 ,
V_112 ,
V_113 ,
NULL ) ;
return;
}
V_111 -> V_4 = V_4 ;
V_111 -> V_114 = V_112 ;
V_12 = F_73 ( V_115 , V_111 ) ;
if ( F_6 ( V_12 ) )
F_12 ( V_111 ) ;
}
static void F_74 ( struct V_116 * V_117 )
{
struct V_32 * V_33 ;
struct V_118 * V_119 ;
T_1 V_1 ;
T_3 type ;
V_119 = F_75 ( V_117 , struct V_118 , V_117 ) ;
V_1 = V_119 -> V_1 ;
type = V_119 -> type ;
F_76 () ;
V_33 = F_18 ( V_1 ) ;
switch ( type ) {
case V_120 :
F_77 ( V_109 , V_1 ,
L_21 , V_121 ) ;
if ( V_33 )
F_78 ( V_1 ) ;
else
F_66 ( V_1 ) ;
break;
case V_122 :
F_77 ( V_109 , V_1 ,
L_22 , V_121 ) ;
if ( ! V_33 )
F_66 ( V_1 ) ;
break;
case V_112 :
F_77 ( V_109 , V_1 ,
L_23 , V_121 ) ;
if ( V_33 )
F_70 ( V_33 -> V_4 ) ;
break;
default:
F_79 ( V_1 ,
L_24 ,
type ) ;
break;
}
F_80 () ;
F_12 ( V_119 ) ;
}
static void F_81 ( T_1 V_1 , T_3 type ,
void * V_25 )
{
F_82 ( V_1 , type , V_25 ,
F_74 ) ;
}
static T_2 T_4
F_83 ( T_1 V_1 , T_3 V_123 , void * V_25 , void * * V_124 )
{
T_2 V_12 ;
int * V_125 = ( int * ) V_25 ;
if ( ! F_1 ( V_1 ) )
return V_13 ;
( * V_125 ) ++ ;
V_12 = F_84 ( V_1 , V_126 ,
F_81 , NULL ) ;
if ( F_6 ( V_12 ) )
F_77 ( V_109 , V_1 ,
L_25 ,
( unsigned int ) V_12 ) ;
else
F_77 ( V_109 , V_1 ,
L_26 ) ;
return V_13 ;
}
void T_4 F_85 ( void )
{
int V_127 = 0 ;
F_86 ( V_128 , V_129 ,
V_130 , F_83 , NULL , & V_127 , NULL ) ;
F_87 ( V_109 L_27 , V_127 ) ;
}
