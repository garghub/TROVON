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
if ( F_22 ( & V_43 ) )
return - V_44 ;
V_45:
F_6 ( & V_46 ) ;
F_7 (op, temp, &orangefs_request_list, list) {
T_2 V_16 ;
F_6 ( & V_4 -> V_47 ) ;
if ( F_23 ( F_8 ( V_4 ) || F_9 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_47 ) ;
continue;
}
V_16 = F_24 ( V_4 ) ;
if ( V_16 != V_48 ) {
int V_20 ;
V_20 = F_14 ( V_16 ) ;
if ( V_20 == 1 ) {
F_17 ( V_30 ,
L_7
L_8 ,
V_25 ,
F_25 ( V_4 -> V_1 ) ,
F_26 ( V_4 ) ) ;
F_11 ( & V_4 -> V_47 ) ;
continue;
} else if ( V_20 == - 1 &&
! ( V_4 -> V_49 . type ==
V_50 ||
V_4 -> V_49 . type ==
V_51 ||
V_4 -> V_49 . type ==
V_52 ) ) {
F_17 ( V_30 ,
L_9 ,
F_25 ( V_4 -> V_1 ) , F_26 ( V_4 ) ) ;
F_16 (
L_10 ,
V_16 ) ;
F_11 ( & V_4 -> V_47 ) ;
continue;
}
}
V_41 = V_4 ;
break;
}
if ( ! V_41 ) {
F_11 ( & V_46 ) ;
return - V_44 ;
}
F_17 ( V_30 , L_11 ,
V_25 ,
F_25 ( V_41 -> V_1 ) ,
F_26 ( V_41 ) ) ;
if ( F_27 ( V_41 ) || F_28 ( V_41 ) ) {
F_16 ( L_12 ) ;
F_10 ( & V_41 -> V_7 ) ;
F_11 ( & V_41 -> V_47 ) ;
F_11 ( & V_46 ) ;
return - V_44 ;
}
F_10 ( & V_41 -> V_7 ) ;
F_11 ( & V_46 ) ;
F_11 ( & V_41 -> V_47 ) ;
V_20 = F_29 ( V_33 , & V_37 , sizeof( T_2 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_29 ( V_33 + sizeof( T_2 ) , & V_39 , sizeof( T_2 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_29 ( V_33 + 2 * sizeof( T_2 ) , & V_41 -> V_1 , sizeof( T_1 ) ) ;
if ( V_20 != 0 )
goto error;
V_20 = F_29 ( V_33 + 2 * sizeof( T_2 ) + sizeof( T_1 ) , & V_41 -> V_49 ,
sizeof( struct V_53 ) ) ;
if ( V_20 != 0 )
goto error;
F_6 ( & V_10 ) ;
F_6 ( & V_41 -> V_47 ) ;
if ( F_23 ( F_9 ( V_41 ) ) ) {
F_11 ( & V_41 -> V_47 ) ;
F_11 ( & V_10 ) ;
F_30 ( & V_41 -> V_54 ) ;
goto V_45;
}
F_31 ( V_41 ) ;
F_17 ( V_30 ,
L_13 ,
V_25 ,
F_26 ( V_41 ) ,
V_41 -> V_55 ,
V_56 -> V_57 ) ;
F_3 ( V_41 ) ;
F_11 ( & V_41 -> V_47 ) ;
F_11 ( & V_10 ) ;
return V_42 ;
error:
F_16 ( L_14 ) ;
F_6 ( & V_46 ) ;
F_6 ( & V_41 -> V_47 ) ;
if ( F_32 ( ! F_9 ( V_41 ) ) ) {
F_33 ( V_41 ) ;
F_17 ( V_30 ,
L_15 ,
V_25 ,
F_26 ( V_41 ) ,
V_41 -> V_55 ,
V_56 -> V_57 ) ;
F_34 ( & V_41 -> V_7 , & V_43 ) ;
F_11 ( & V_41 -> V_47 ) ;
} else {
F_11 ( & V_41 -> V_47 ) ;
F_30 ( & V_41 -> V_54 ) ;
}
F_11 ( & V_46 ) ;
return - V_58 ;
}
static T_3 F_35 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
T_3 V_20 ;
struct V_3 * V_4 = NULL ;
struct {
T_7 V_63 ;
T_7 V_39 ;
T_1 V_1 ;
} V_64 ;
int V_65 = V_20 = F_36 ( V_62 ) ;
int V_66 = sizeof( struct V_67 ) ;
int V_68 = sizeof( V_64 ) ;
F_17 ( V_30 , L_16 ,
V_25 ,
V_65 ,
V_20 ) ;
if ( V_65 < V_69 ) {
F_16 ( L_17 ,
V_25 ,
V_65 ,
( unsigned int ) V_69 ) ;
return - V_58 ;
}
if ( ! F_37 ( & V_64 , V_68 , V_62 ) ) {
F_16 ( L_18 , V_25 ) ;
return - V_58 ;
}
if ( V_64 . V_63 < V_70 ) {
F_16 ( L_19
L_20 ,
V_25 ,
V_64 . V_63 ,
V_70 ) ;
return - V_71 ;
}
if ( V_64 . V_39 != V_40 ) {
F_16 ( L_21 ) ;
return - V_71 ;
}
if ( ! V_72 ) {
V_72 = V_64 . V_63 ;
} else if ( V_72 != V_64 . V_63 ) {
F_16 ( L_22 ) ;
return - V_71 ;
}
V_4 = F_5 ( V_64 . V_1 ) ;
if ( ! V_4 ) {
F_17 ( V_30 ,
L_23 ,
V_25 , F_25 ( V_64 . V_1 ) ) ;
return V_20 ;
}
if ( ! F_37 ( & V_4 -> V_73 , V_66 , V_62 ) ) {
F_16 ( L_24 , V_25 ) ;
goto V_74;
}
if ( V_4 -> V_73 . V_75 )
goto V_76;
if ( ( V_68 + V_66 + V_4 -> V_73 . V_77 ) != V_65 ) {
F_16 ( L_25
L_26
L_27 ,
V_25 ,
V_68 ,
V_66 ,
V_4 -> V_73 . V_77 ,
V_65 ) ;
goto V_74;
}
if ( ( V_4 -> V_73 . type != V_78 ) &&
( V_4 -> V_73 . V_77 != 0 ) ) {
F_16 ( L_28 ,
V_25 ,
V_4 -> V_73 . type ) ;
goto V_74;
}
if ( ( V_4 -> V_73 . type == V_78 ) &&
( V_4 -> V_73 . V_77 == 0 ) ) {
F_16 ( L_29 ,
V_25 ,
V_4 -> V_73 . type ) ;
goto V_74;
}
if ( V_4 -> V_73 . type != V_78 )
goto V_76;
V_4 -> V_73 . V_79 = F_38 ( V_4 -> V_73 . V_77 ) ;
if ( ! V_4 -> V_73 . V_79 )
goto V_80;
memset ( V_4 -> V_73 . V_79 , 0 , V_4 -> V_73 . V_77 ) ;
if ( ! F_37 ( V_4 -> V_73 . V_79 ,
V_4 -> V_73 . V_77 , V_62 ) ) {
F_16 ( L_30 , V_25 ) ;
F_39 ( V_4 -> V_73 . V_79 ) ;
goto V_74;
}
V_76:
F_6 ( & V_4 -> V_47 ) ;
if ( F_23 ( F_40 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_47 ) ;
F_41 ( V_4 ) ;
} else if ( F_23 ( F_9 ( V_4 ) ) ) {
F_11 ( & V_4 -> V_47 ) ;
F_30 ( & V_4 -> V_54 ) ;
} else {
F_42 ( V_4 ) ;
F_17 ( V_30 ,
L_31 ,
V_25 ,
F_26 ( V_4 ) ,
V_4 -> V_55 ,
V_56 -> V_57 ) ;
F_11 ( & V_4 -> V_47 ) ;
}
return V_20 ;
V_74:
V_4 -> V_73 . V_75 = - ( V_81 | 9 ) ;
V_20 = - V_58 ;
goto V_76;
V_80:
V_4 -> V_73 . V_75 = - ( V_81 | 8 ) ;
V_20 = - V_82 ;
goto V_76;
}
static int F_43 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
int V_11 = 0 ;
F_17 ( V_30 ,
L_32 ,
V_25 ) ;
F_18 ( & V_31 ) ;
F_44 () ;
V_32 = - 1 ;
V_11 = F_12 () ;
F_17 ( V_30 , L_33 ,
( V_11 ? L_34 : L_35 ) ) ;
F_45 () ;
F_46 () ;
F_47 () ;
F_17 ( V_30 ,
L_36 ) ;
V_32 = 0 ;
V_72 = 0 ;
F_20 ( & V_31 ) ;
return 0 ;
}
int F_48 ( void )
{
int V_83 ;
F_18 ( & V_31 ) ;
V_83 = V_32 == 1 ? 0 : - V_84 ;
F_20 ( & V_31 ) ;
return V_83 ;
}
bool F_49 ( void )
{
return V_32 == 1 ;
}
static inline long F_50 ( unsigned int V_85 )
{
if ( F_51 ( V_85 ) != V_86 ) {
F_16 ( L_37 ,
V_85 ,
F_51 ( V_85 ) ,
V_86 ) ;
return - V_21 ;
}
if ( F_52 ( V_85 ) >= V_87 || F_52 ( V_85 ) <= 0 ) {
F_16 ( L_38 ,
F_52 ( V_85 ) , V_87 ) ;
return - V_88 ;
}
return 0 ;
}
static long F_53 ( unsigned int V_85 , unsigned long V_89 )
{
static T_2 V_39 = V_40 ;
static T_2 V_90 = V_42 ;
static T_2 V_91 = V_69 ;
struct V_92 V_93 ;
int V_20 = 0 ;
int V_94 = 1 ;
struct V_12 * V_13 ;
switch ( V_85 ) {
case V_95 :
return ( ( F_54 ( V_39 , ( T_2 T_4 * ) V_89 ) == - V_58 ) ?
- V_84 :
0 ) ;
case V_96 :
return ( ( F_54 ( V_90 ,
( T_2 T_4 * ) V_89 ) == - V_58 ) ?
- V_84 :
0 ) ;
case V_97 :
return ( ( F_54 ( V_91 ,
( T_2 T_4 * ) V_89 ) == - V_58 ) ?
- V_84 :
0 ) ;
case V_98 :
V_20 = F_55 ( & V_93 ,
(struct V_92 T_4 * )
V_89 ,
sizeof( struct V_92 ) ) ;
return V_20 ? - V_84 : F_56 ( & V_93 ) ;
case V_99 :
F_17 ( V_30 ,
L_39 ,
V_25 ) ;
V_20 = F_57 ( & V_100 ) ;
if ( V_20 < 0 )
return V_20 ;
F_17 ( V_30 ,
L_40 ,
V_25 ) ;
F_6 ( & V_14 ) ;
F_13 (orangefs_sb, &orangefs_superblocks, list) {
if ( ! V_13 -> V_7 . V_101 )
continue;
F_17 ( V_30 ,
L_41 ,
V_25 ,
V_13 ) ;
F_11 ( & V_14 ) ;
V_20 = F_58 ( V_13 ) ;
F_6 ( & V_14 ) ;
if ( V_20 ) {
F_17 ( V_30 ,
L_42 ,
V_13 ) ;
break;
}
}
F_11 ( & V_14 ) ;
F_17 ( V_30 ,
L_43 ,
V_25 ) ;
F_20 ( & V_100 ) ;
return V_20 ;
case V_102 :
V_20 = F_29 ( ( void T_4 * ) V_89 ,
& V_94 ,
sizeof( V_94 ) ) ;
if ( V_20 != 0 )
return - V_84 ;
else
return V_20 ;
case V_103 :
return F_59 ( ( void T_4 * ) V_89 ) ;
case V_104 :
return F_60 ( ( void T_4 * ) V_89 ) ;
case V_105 :
return F_61 ( ( void T_4 * ) V_89 ) ;
default:
return - V_88 ;
}
return - V_88 ;
}
static long F_62 ( struct V_19 * V_19 ,
unsigned int V_85 , unsigned long V_89 )
{
long V_20 ;
V_20 = F_50 ( V_85 ) ;
if ( V_20 < 0 )
return ( int ) V_20 ;
return ( int ) F_53 ( V_85 , V_89 ) ;
}
static unsigned long F_63 ( unsigned long args , long * error )
{
struct V_106 T_4 * V_107 = ( void T_4 * ) args ;
struct V_92 T_4 * V_108 =
F_64 ( sizeof( * V_108 ) ) ;
T_8 V_109 ;
* error = 0 ;
if ( F_65 ( V_109 , & V_107 -> V_110 ) )
goto V_111;
if ( F_54 ( F_66 ( V_109 ) , & V_108 -> V_110 ) )
goto V_111;
if ( F_67 ( & V_108 -> V_112 , & V_107 -> V_112 , sizeof( T_2 ) ) )
goto V_111;
if ( F_67 ( & V_108 -> V_113 , & V_107 -> V_113 , sizeof( T_2 ) ) )
goto V_111;
if ( F_67 ( & V_108 -> V_34 , & V_107 -> V_34 , sizeof( T_2 ) ) )
goto V_111;
return ( unsigned long ) V_108 ;
V_111:
* error = - V_58 ;
return 0 ;
}
static long F_68 ( struct V_19 * V_114 , unsigned int V_115 ,
unsigned long args )
{
long V_20 ;
unsigned long V_89 = args ;
V_20 = F_50 ( V_115 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_115 == V_98 ) {
V_89 = F_63 ( args , & V_20 ) ;
if ( V_20 < 0 ) {
F_16 ( L_44 ) ;
return V_20 ;
}
}
return F_53 ( V_115 , V_89 ) ;
}
int F_69 ( void )
{
V_116 = F_70 ( 0 ,
V_117 ,
& V_118 ) ;
if ( V_116 < 0 ) {
F_17 ( V_30 ,
L_45 ,
V_117 , V_116 ) ;
return V_116 ;
}
F_17 ( V_30 ,
L_46 ,
V_117 ) ;
F_17 ( V_30 , L_47 ,
V_117 , V_116 ) ;
return 0 ;
}
void F_71 ( void )
{
F_72 ( V_116 , V_117 ) ;
F_17 ( V_30 ,
L_48 ,
V_117 ) ;
}
static unsigned int F_73 ( struct V_19 * V_19 ,
struct V_119 * V_120 )
{
int V_121 = 0 ;
F_74 ( V_19 , & V_122 , V_120 ) ;
if ( ! F_22 ( & V_43 ) )
V_121 |= V_123 ;
return V_121 ;
}
