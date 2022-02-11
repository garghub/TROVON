static int F_1 ( T_1 V_1 , int V_2 )
{
return F_2 ( V_1 , ( unsigned int ) V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
int V_5 = F_1 ( V_4 -> V_1 , V_6 ) ;
F_4 ( & V_4 -> V_7 , & V_8 [ V_5 ] ) ;
}
static struct V_3 * F_5 ( T_1 V_1 )
{
struct V_3 * V_4 , * V_9 ;
int V_5 ;
V_5 = F_1 ( V_1 , V_6 ) ;
F_6 ( & V_10 ) ;
F_7 (op,
next,
&orangefs_htable_ops_in_progress[index],
list) {
if ( V_4 -> V_1 == V_1 && ! F_8 ( V_4 ) &&
! F_9 ( V_4 ) ) {
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_10 ) ;
return V_4 ;
}
}
F_11 ( & V_10 ) ;
return NULL ;
}
static int F_12 ( void )
{
int V_11 = 1 ;
struct V_12 * V_13 = NULL ;
F_6 ( & V_14 ) ;
F_13 (orangefs_sb, &orangefs_superblocks, list) {
V_13 -> V_15 = 1 ;
V_11 = 0 ;
}
F_11 ( & V_14 ) ;
return V_11 ;
}
static int F_14 ( T_2 V_16 )
{
int V_15 = - 1 ;
struct V_12 * V_13 = NULL ;
F_6 ( & V_14 ) ;
F_13 (orangefs_sb, &orangefs_superblocks, list) {
if ( V_13 -> V_17 == V_16 ) {
V_15 = V_13 -> V_15 ;
break;
}
}
F_11 ( & V_14 ) ;
return V_15 ;
}
static int F_15 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
int V_20 = - V_21 ;
if ( V_19 -> V_22 -> V_23 != & V_24 ) {
F_16 ( L_1 ,
V_25 ) ;
goto V_26;
}
if ( ! ( V_19 -> V_27 & V_28 ) ) {
F_16 ( L_2 ,
V_25 ) ;
goto V_26;
}
V_20 = - V_29 ;
F_17 ( V_30 , L_3 ) ;
F_18 ( & V_31 ) ;
if ( V_32 == 0 ) {
V_32 = 1 ;
V_20 = 0 ;
} else {
F_19 () ;
}
F_20 ( & V_31 ) ;
V_26:
F_17 ( V_30 ,
L_4 ,
V_20 ) ;
return V_20 ;
}
static T_3 F_21 ( struct V_19 * V_19 ,
char T_4 * V_33 ,
T_5 V_34 , T_6 * V_35 )
{
struct V_3 * V_4 , * V_36 ;
T_2 V_37 = V_38 ;
static T_2 V_39 = V_40 ;
struct V_3 * V_41 = NULL ;
unsigned long V_20 ;
if ( ! ( V_19 -> V_27 & V_28 ) ) {
F_16 ( L_5 ,
V_25 ) ;
return - V_21 ;
}
if ( V_34 != V_42 ) {
F_16 ( L_6 ) ;
return - V_21 ;
}
V_43:
F_6 ( & V_44 ) ;
F_7 (op, temp, &orangefs_request_list, list) {
T_2 V_16 ;
F_6 ( & V_4 -> V_45 ) ;
if ( F_22 ( F_8 ( V_4 ) || F_9 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_45 ) ;
continue;
}
V_16 = F_23 ( V_4 ) ;
if ( V_16 != V_46 ) {
int V_20 ;
V_20 = F_14 ( V_16 ) ;
if ( V_20 == 1 ) {
F_17 ( V_30 ,
L_7
L_8 ,
V_25 ,
F_24 ( V_4 -> V_1 ) ,
F_25 ( V_4 ) ) ;
F_11 ( & V_4 -> V_45 ) ;
continue;
} else if ( V_20 == - 1 &&
! ( V_4 -> V_47 . type ==
V_48 ||
V_4 -> V_47 . type ==
V_49 ) ) {
F_17 ( V_30 ,
L_9 ,
F_24 ( V_4 -> V_1 ) , F_25 ( V_4 ) ) ;
F_16 (
L_10 ,
V_16 ) ;
F_11 ( & V_4 -> V_45 ) ;
continue;
}
}
V_41 = V_4 ;
break;
}
if ( ! V_41 ) {
F_11 ( & V_44 ) ;
return - V_50 ;
}
F_17 ( V_30 , L_11 ,
V_25 ,
F_24 ( V_41 -> V_1 ) ,
F_25 ( V_41 ) ) ;
if ( F_26 ( V_41 ) || F_27 ( V_41 ) ) {
F_16 ( L_12 ) ;
F_10 ( & V_41 -> V_7 ) ;
F_11 ( & V_41 -> V_45 ) ;
F_11 ( & V_44 ) ;
return - V_50 ;
}
F_10 ( & V_41 -> V_7 ) ;
F_11 ( & V_44 ) ;
F_11 ( & V_41 -> V_45 ) ;
V_20 = F_28 ( V_33 , & V_37 , sizeof( T_2 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_28 ( V_33 + sizeof( T_2 ) , & V_39 , sizeof( T_2 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_28 ( V_33 + 2 * sizeof( T_2 ) , & V_41 -> V_1 , sizeof( T_1 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_28 ( V_33 + 2 * sizeof( T_2 ) + sizeof( T_1 ) , & V_41 -> V_47 ,
sizeof( struct V_51 ) ) ;
if ( V_20 != 0 )
goto error;
F_6 ( & V_10 ) ;
F_6 ( & V_41 -> V_45 ) ;
if ( F_22 ( F_9 ( V_41 ) ) ) {
F_11 ( & V_41 -> V_45 ) ;
F_11 ( & V_10 ) ;
F_29 ( & V_41 -> V_52 ) ;
goto V_43;
}
F_30 ( V_41 ) ;
F_17 ( V_30 ,
L_13 ,
V_25 ,
F_25 ( V_41 ) ,
V_41 -> V_53 ,
V_54 -> V_55 ) ;
F_3 ( V_41 ) ;
F_11 ( & V_41 -> V_45 ) ;
F_11 ( & V_10 ) ;
return V_42 ;
error:
F_16 ( L_14 ) ;
F_6 ( & V_44 ) ;
F_6 ( & V_41 -> V_45 ) ;
if ( F_31 ( ! F_9 ( V_41 ) ) ) {
F_32 ( V_41 ) ;
F_17 ( V_30 ,
L_15 ,
V_25 ,
F_25 ( V_41 ) ,
V_41 -> V_53 ,
V_54 -> V_55 ) ;
F_33 ( & V_41 -> V_7 , & V_56 ) ;
F_11 ( & V_41 -> V_45 ) ;
} else {
F_11 ( & V_41 -> V_45 ) ;
F_29 ( & V_41 -> V_52 ) ;
}
F_11 ( & V_44 ) ;
return - V_57 ;
}
static T_3 F_34 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
T_3 V_20 ;
struct V_3 * V_4 = NULL ;
struct {
T_7 V_62 ;
T_7 V_39 ;
T_1 V_1 ;
} V_63 ;
int V_64 = V_20 = F_35 ( V_61 ) ;
int V_65 = sizeof( struct V_66 ) ;
int V_67 = sizeof( V_63 ) ;
F_17 ( V_30 , L_16 ,
V_25 ,
V_64 ,
V_20 ) ;
if ( V_64 < V_68 ) {
F_16 ( L_17 ,
V_25 ,
V_64 ,
( unsigned int ) V_68 ) ;
return - V_57 ;
}
if ( ! F_36 ( & V_63 , V_67 , V_61 ) ) {
F_16 ( L_18 , V_25 ) ;
return - V_57 ;
}
if ( V_63 . V_62 < V_69 ) {
F_16 ( L_19
L_20 ,
V_25 ,
V_63 . V_62 ,
V_69 ) ;
return - V_70 ;
}
if ( V_63 . V_39 != V_40 ) {
F_16 ( L_21 ) ;
return - V_70 ;
}
if ( ! V_71 ) {
V_71 = V_63 . V_62 ;
} else if ( V_71 != V_63 . V_62 ) {
F_16 ( L_22 ) ;
return - V_70 ;
}
V_4 = F_5 ( V_63 . V_1 ) ;
if ( ! V_4 ) {
F_16 ( L_23 ,
F_24 ( V_63 . V_1 ) ) ;
return V_20 ;
}
if ( ! F_36 ( & V_4 -> V_72 , V_65 , V_61 ) ) {
F_16 ( L_24 , V_25 ) ;
goto V_73;
}
if ( V_4 -> V_72 . V_74 )
goto V_75;
if ( ( V_67 + V_65 + V_4 -> V_72 . V_76 ) != V_64 ) {
F_16 ( L_25
L_26
L_27 ,
V_25 ,
V_67 ,
V_65 ,
V_4 -> V_72 . V_76 ,
V_64 ) ;
goto V_73;
}
if ( ( V_4 -> V_72 . type != V_77 ) &&
( V_4 -> V_72 . V_76 != 0 ) ) {
F_16 ( L_28 ,
V_25 ,
V_4 -> V_72 . type ) ;
goto V_73;
}
if ( ( V_4 -> V_72 . type == V_77 ) &&
( V_4 -> V_72 . V_76 == 0 ) ) {
F_16 ( L_29 ,
V_25 ,
V_4 -> V_72 . type ) ;
goto V_73;
}
if ( V_4 -> V_72 . type != V_77 )
goto V_75;
V_4 -> V_72 . V_78 =
F_37 ( V_4 -> V_72 . V_76 ) ;
if ( V_4 -> V_72 . V_78 == NULL ) {
F_16 ( L_30 ,
V_25 ) ;
goto V_79;
}
memset ( V_4 -> V_72 . V_78 , 0 , V_4 -> V_72 . V_76 ) ;
if ( ! F_36 ( V_4 -> V_72 . V_78 ,
V_4 -> V_72 . V_76 , V_61 ) ) {
F_16 ( L_31 , V_25 ) ;
F_38 ( V_4 -> V_72 . V_78 ) ;
goto V_73;
}
V_75:
F_6 ( & V_4 -> V_45 ) ;
if ( F_22 ( F_39 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_45 ) ;
F_40 ( V_4 ) ;
} else if ( F_22 ( F_9 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_45 ) ;
F_29 ( & V_4 -> V_52 ) ;
} else {
F_41 ( V_4 ) ;
F_17 ( V_30 ,
L_32 ,
V_25 ,
F_25 ( V_4 ) ,
V_4 -> V_53 ,
V_54 -> V_55 ) ;
F_11 ( & V_4 -> V_45 ) ;
}
return V_20 ;
V_73:
V_4 -> V_72 . V_74 = - ( V_80 | 9 ) ;
V_20 = - V_57 ;
goto V_75;
V_79:
V_4 -> V_72 . V_74 = - ( V_80 | 8 ) ;
V_20 = - V_81 ;
goto V_75;
}
static int F_42 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
int V_11 = 0 ;
F_17 ( V_30 ,
L_33 ,
V_25 ) ;
F_18 ( & V_31 ) ;
F_43 () ;
V_32 = - 1 ;
V_11 = F_12 () ;
F_17 ( V_30 , L_34 ,
( V_11 ? L_35 : L_36 ) ) ;
F_44 () ;
F_45 () ;
F_46 () ;
F_17 ( V_30 ,
L_37 ) ;
V_32 = 0 ;
V_71 = 0 ;
F_20 ( & V_31 ) ;
return 0 ;
}
int F_47 ( void )
{
int V_82 ;
F_18 ( & V_31 ) ;
V_82 = V_32 == 1 ? 0 : - V_83 ;
F_20 ( & V_31 ) ;
return V_82 ;
}
bool F_48 ( void )
{
return V_32 == 1 ;
}
static inline long F_49 ( unsigned int V_84 )
{
if ( F_50 ( V_84 ) != V_85 ) {
F_16 ( L_38 ,
V_84 ,
F_50 ( V_84 ) ,
V_85 ) ;
return - V_21 ;
}
if ( F_51 ( V_84 ) >= V_86 || F_51 ( V_84 ) <= 0 ) {
F_16 ( L_39 ,
F_51 ( V_84 ) , V_86 ) ;
return - V_87 ;
}
return 0 ;
}
static long F_52 ( unsigned int V_84 , unsigned long V_88 )
{
static T_2 V_39 = V_40 ;
static T_2 V_89 = V_42 ;
static T_2 V_90 = V_68 ;
struct V_91 V_92 ;
int V_20 = 0 ;
int V_93 = 1 ;
struct V_12 * V_13 ;
switch ( V_84 ) {
case V_94 :
return ( ( F_53 ( V_39 , ( T_2 T_4 * ) V_88 ) == - V_57 ) ?
- V_83 :
0 ) ;
case V_95 :
return ( ( F_53 ( V_89 ,
( T_2 T_4 * ) V_88 ) == - V_57 ) ?
- V_83 :
0 ) ;
case V_96 :
return ( ( F_53 ( V_90 ,
( T_2 T_4 * ) V_88 ) == - V_57 ) ?
- V_83 :
0 ) ;
case V_97 :
V_20 = F_54 ( & V_92 ,
(struct V_91 T_4 * )
V_88 ,
sizeof( struct V_91 ) ) ;
return V_20 ? - V_83 : F_55 ( & V_92 ) ;
case V_98 :
F_17 ( V_30 ,
L_40 ,
V_25 ) ;
V_20 = F_56 ( & V_99 ) ;
if ( V_20 < 0 )
return V_20 ;
F_17 ( V_30 ,
L_41 ,
V_25 ) ;
F_6 ( & V_14 ) ;
F_13 (orangefs_sb, &orangefs_superblocks, list) {
if ( ! V_13 -> V_7 . V_100 )
continue;
F_17 ( V_30 ,
L_42 ,
V_25 ,
V_13 ) ;
F_11 ( & V_14 ) ;
V_20 = F_57 ( V_13 ) ;
F_6 ( & V_14 ) ;
if ( V_20 ) {
F_17 ( V_30 ,
L_43 ,
V_13 ) ;
break;
}
}
F_11 ( & V_14 ) ;
F_17 ( V_30 ,
L_44 ,
V_25 ) ;
F_20 ( & V_99 ) ;
return V_20 ;
case V_101 :
V_20 = F_28 ( ( void T_4 * ) V_88 ,
& V_93 ,
sizeof( V_93 ) ) ;
if ( V_20 != 0 )
return - V_83 ;
else
return V_20 ;
case V_102 :
return F_58 ( ( void T_4 * ) V_88 ) ;
case V_103 :
return F_59 ( ( void T_4 * ) V_88 ) ;
case V_104 :
return F_60 ( ( void T_4 * ) V_88 ) ;
default:
return - V_87 ;
}
return - V_87 ;
}
static long F_61 ( struct V_19 * V_19 ,
unsigned int V_84 , unsigned long V_88 )
{
long V_20 ;
V_20 = F_49 ( V_84 ) ;
if ( V_20 < 0 )
return ( int ) V_20 ;
return ( int ) F_52 ( V_84 , V_88 ) ;
}
static unsigned long F_62 ( unsigned long args , long * error )
{
struct V_105 T_4 * V_106 = ( void T_4 * ) args ;
struct V_91 T_4 * V_107 =
F_63 ( sizeof( * V_107 ) ) ;
T_8 V_108 ;
* error = 0 ;
if ( F_64 ( V_108 , & V_106 -> V_109 ) )
goto V_110;
if ( F_53 ( F_65 ( V_108 ) , & V_107 -> V_109 ) )
goto V_110;
if ( F_66 ( & V_107 -> V_111 , & V_106 -> V_111 , sizeof( T_2 ) ) )
goto V_110;
if ( F_66 ( & V_107 -> V_112 , & V_106 -> V_112 , sizeof( T_2 ) ) )
goto V_110;
if ( F_66 ( & V_107 -> V_34 , & V_106 -> V_34 , sizeof( T_2 ) ) )
goto V_110;
return ( unsigned long ) V_107 ;
V_110:
* error = - V_57 ;
return 0 ;
}
static long F_67 ( struct V_19 * V_113 , unsigned int V_114 ,
unsigned long args )
{
long V_20 ;
unsigned long V_88 = args ;
V_20 = F_49 ( V_114 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_114 == V_97 ) {
V_88 = F_62 ( args , & V_20 ) ;
if ( V_20 < 0 ) {
F_16 ( L_45 ) ;
return V_20 ;
}
}
return F_52 ( V_114 , V_88 ) ;
}
int F_68 ( void )
{
V_115 = F_69 ( 0 ,
V_116 ,
& V_117 ) ;
if ( V_115 < 0 ) {
F_17 ( V_30 ,
L_46 ,
V_116 , V_115 ) ;
return V_115 ;
}
F_17 ( V_30 ,
L_47 ,
V_116 ) ;
F_17 ( V_30 , L_48 ,
V_116 , V_115 ) ;
return 0 ;
}
void F_70 ( void )
{
F_71 ( V_115 , V_116 ) ;
F_17 ( V_30 ,
L_49 ,
V_116 ) ;
}
static unsigned int F_72 ( struct V_19 * V_19 ,
struct V_118 * V_119 )
{
int V_120 = 0 ;
F_73 ( V_19 , & V_121 , V_119 ) ;
if ( ! F_74 ( & V_56 ) )
V_120 |= V_122 ;
return V_120 ;
}
