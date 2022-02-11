static int F_1 ( T_1 V_1 , const char * V_2 , int * V_3 )
{
T_2 V_4 ;
unsigned long long V_5 ;
V_4 = F_2 ( V_1 , ( char * ) V_2 , NULL , & V_5 ) ;
if ( F_3 ( V_4 ) ) {
* V_3 = - 1 ;
return - 1 ;
} else {
* V_3 = V_5 ;
return 0 ;
}
}
static int F_4 ( T_1 V_1 , int V_6 , int * V_7 )
{
T_2 V_4 ;
unsigned long long V_5 ;
struct V_8 V_9 ;
union V_10 V_11 ;
V_9 . V_12 = 1 ;
V_9 . V_13 = & V_11 ;
V_11 . type = V_14 ;
V_11 . integer . V_15 = V_6 ;
V_4 = F_2 ( V_1 , L_1 , & V_9 , & V_5 ) ;
if ( F_3 ( V_4 ) ) {
* V_7 = - 1 ;
return - 1 ;
} else {
* V_7 = V_5 ;
return 0 ;
}
}
static int F_5 ( T_1 V_1 , int V_6 , int V_16 )
{
struct V_8 V_9 ;
union V_10 V_11 [ 2 ] ;
T_2 V_4 ;
V_9 . V_12 = 2 ;
V_9 . V_13 = V_11 ;
V_11 [ 0 ] . type = V_14 ;
V_11 [ 0 ] . integer . V_15 = V_6 ;
V_11 [ 1 ] . type = V_14 ;
V_11 [ 1 ] . integer . V_15 = V_16 ;
V_4 = F_6 ( V_1 , L_2 , & V_9 , NULL ) ;
if ( V_4 != V_17 )
return - 1 ;
return 0 ;
}
static int F_7 ( T_1 V_1 , int V_6 , unsigned long * V_16 )
{
int V_3 ;
unsigned long int V_18 ;
if ( F_5 ( V_1 , 1 , V_6 ) )
return - 1 ;
for ( V_18 = V_19 + ( V_20 ) * V_21 / 1000 + 1 ;
F_8 ( V_19 , V_18 ) ; ) {
F_9 () ;
if ( F_4 ( V_1 , 1 , & V_3 ) )
return - 1 ;
if ( V_3 == 0 ) {
if ( F_4 ( V_1 , 0 , & V_3 ) )
return - 1 ;
* V_16 = V_3 ;
return 0 ;
}
}
F_10 ( L_3 ) ;
return - 1 ;
}
static int F_11 ( T_1 V_1 , int V_6 , unsigned long V_16 )
{
int V_3 ;
unsigned long int V_18 ;
if ( F_5 ( V_1 , 0 , V_16 ) )
return - 1 ;
if ( F_5 ( V_1 , 1 , V_6 ) )
return - 1 ;
for ( V_18 = V_19 + ( V_20 ) * V_21 / 1000 + 1 ;
F_8 ( V_19 , V_18 ) ; ) {
F_9 () ;
if ( F_4 ( V_1 , 1 , & V_3 ) )
return - 1 ;
if ( V_3 == 0 )
return 0 ;
}
F_10 ( L_4 ) ;
return - 1 ;
}
static int F_12 ( struct V_22 * V_23 , void * V_16 )
{
unsigned long V_15 ;
if ( ! F_7 ( V_24 , V_25 , & V_15 ) )
F_13 ( V_23 , L_5 , V_15 ) ;
if ( ! F_7 ( V_24 , V_26 , & V_15 ) )
F_13 ( V_23 , L_6 , V_15 ) ;
if ( ! F_7 ( V_24 , V_27 , & V_15 ) )
F_13 ( V_23 , L_7 , V_15 ? L_8 : L_9 ) ;
F_13 ( V_23 , L_10 ) ;
if ( ! F_7 ( V_24 , V_28 , & V_15 ) )
F_13 ( V_23 , L_11 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_24 , V_29 , & V_15 ) )
F_13 ( V_23 , L_12 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_24 , V_30 , & V_15 ) )
F_13 ( V_23 , L_13 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_24 , V_31 , & V_15 ) )
F_13 ( V_23 , L_14 ,
V_15 ? L_8 : L_9 , V_15 ) ;
F_13 ( V_23 , L_10 ) ;
if ( ! F_7 ( V_24 , V_32 , & V_15 ) )
F_13 ( V_23 , L_15 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_24 , V_33 , & V_15 ) )
F_13 ( V_23 , L_16 ,
V_15 ? L_8 : L_9 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_15 ( V_35 , F_12 , NULL ) ;
}
static int F_16 ( struct V_22 * V_23 , void * V_16 )
{
if ( ! V_36 ) {
F_13 ( V_23 , L_17 ) ;
} else {
F_13 ( V_23 , L_18 ,
V_36 -> V_37 ) ;
if ( F_17 ( V_38 , & V_36 -> V_37 ) )
F_13 ( V_23 , L_19 ) ;
if ( F_17 ( V_39 , & V_36 -> V_37 ) )
F_13 ( V_23 , L_20 ) ;
if ( F_17 ( V_40 , & V_36 -> V_37 ) )
F_13 ( V_23 , L_21 ) ;
if ( F_17 ( V_41 , & V_36 -> V_37 ) )
F_13 ( V_23 , L_22 ) ;
F_13 ( V_23 , L_23 ) ;
switch ( ( V_36 -> V_37 ) & 0x700 ) {
case 0x100 :
F_13 ( V_23 , L_24 ) ;
break;
case 0x200 :
F_13 ( V_23 , L_25 ) ;
break;
case 0x300 :
F_13 ( V_23 , L_26 ) ;
break;
case 0x400 :
F_13 ( V_23 , L_27 ) ;
break;
case 0x500 :
F_13 ( V_23 , L_28 ) ;
break;
}
F_13 ( V_23 , L_29 ) ;
}
return 0 ;
}
static int F_18 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_15 ( V_35 , F_16 , NULL ) ;
}
static int T_3 F_19 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
V_43 -> V_46 = F_20 ( L_30 , NULL ) ;
if ( V_43 -> V_46 == NULL ) {
F_10 ( L_31 ) ;
goto V_47;
}
V_45 = F_21 ( L_32 , V_48 , V_43 -> V_46 , NULL ,
& V_49 ) ;
if ( ! V_45 ) {
F_10 ( L_33 ) ;
goto V_47;
}
V_45 = F_21 ( L_34 , V_48 , V_43 -> V_46 , NULL ,
& V_50 ) ;
if ( ! V_45 ) {
F_10 ( L_35 ) ;
goto V_47;
}
return 0 ;
V_47:
return - V_51 ;
}
static void F_22 ( struct V_42 * V_43 )
{
F_23 ( V_43 -> V_46 ) ;
V_43 -> V_46 = NULL ;
}
static T_4 F_24 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
char * V_56 )
{
unsigned long V_5 ;
if ( F_7 ( V_24 , V_33 , & V_5 ) )
return sprintf ( V_56 , L_36 ) ;
return sprintf ( V_56 , L_37 , V_5 ) ;
}
static T_4 F_25 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 , T_5 V_12 )
{
int V_7 , V_57 ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_56 , L_38 , & V_57 ) != 1 )
return - V_58 ;
V_7 = F_11 ( V_24 , V_59 , V_57 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_12 ;
}
static T_6 F_26 ( struct V_60 * V_61 ,
struct V_62 * V_55 ,
int V_63 )
{
struct V_52 * V_53 = F_27 ( V_61 , struct V_52 , V_61 ) ;
struct V_42 * V_43 = F_28 ( V_53 ) ;
bool V_64 ;
if ( V_55 == & V_65 . V_55 )
V_64 = F_17 ( V_41 , & ( V_43 -> V_37 ) ) ;
else
V_64 = true ;
return V_64 ? V_55 -> V_66 : 0 ;
}
static int F_29 ( void * V_16 , bool V_67 )
{
unsigned long V_68 = ( unsigned long ) V_16 ;
return F_11 ( V_24 , V_68 , ! V_67 ) ;
}
static void F_30 ( struct V_42 * V_43 )
{
unsigned long V_69 ;
int V_70 ;
if ( F_7 ( V_24 , V_28 , & V_69 ) )
return;
V_69 = ! V_69 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
if ( V_43 -> V_72 [ V_70 ] )
F_31 ( V_43 -> V_72 [ V_70 ] , V_69 ) ;
}
static int T_3 F_32 ( struct V_73 * V_74 ,
int V_53 )
{
struct V_42 * V_43 = F_28 ( & V_74 -> V_53 ) ;
int V_7 ;
unsigned long V_75 ;
if ( V_76 &&
( V_77 [ V_53 ] . type == V_78 ) ) {
F_11 ( V_24 ,
V_77 [ V_53 ] . V_68 , 1 ) ;
return 0 ;
}
V_43 -> V_72 [ V_53 ] = F_33 ( V_77 [ V_53 ] . V_79 , & V_74 -> V_53 ,
V_77 [ V_53 ] . type , & V_80 ,
( void * ) ( long ) V_53 ) ;
if ( ! V_43 -> V_72 [ V_53 ] )
return - V_51 ;
if ( F_7 ( V_24 , V_77 [ V_53 ] . V_68 - 1 ,
& V_75 ) ) {
F_34 ( V_43 -> V_72 [ V_53 ] , 0 ) ;
} else {
V_75 = ! V_75 ;
F_34 ( V_43 -> V_72 [ V_53 ] , V_75 ) ;
}
V_7 = F_35 ( V_43 -> V_72 [ V_53 ] ) ;
if ( V_7 ) {
F_36 ( V_43 -> V_72 [ V_53 ] ) ;
return V_7 ;
}
return 0 ;
}
static void F_37 ( struct V_73 * V_74 , int V_53 )
{
struct V_42 * V_43 = F_28 ( & V_74 -> V_53 ) ;
if ( ! V_43 -> V_72 [ V_53 ] )
return;
F_38 ( V_43 -> V_72 [ V_53 ] ) ;
F_36 ( V_43 -> V_72 [ V_53 ] ) ;
}
static int T_3 F_39 ( struct V_42 * V_43 )
{
int V_5 ;
V_43 -> V_81 = F_40 ( L_30 , - 1 ) ;
if ( ! V_43 -> V_81 )
return - V_51 ;
F_41 ( V_43 -> V_81 , V_43 ) ;
V_5 = F_42 ( V_43 -> V_81 ) ;
if ( V_5 )
goto V_82;
V_5 = F_43 ( & V_43 -> V_81 -> V_53 . V_61 ,
& V_83 ) ;
if ( V_5 )
goto V_84;
return 0 ;
V_84:
F_44 ( V_43 -> V_81 ) ;
V_82:
F_45 ( V_43 -> V_81 ) ;
return V_5 ;
}
static void F_46 ( struct V_42 * V_43 )
{
F_47 ( & V_43 -> V_81 -> V_53 . V_61 ,
& V_83 ) ;
F_48 ( V_43 -> V_81 ) ;
}
static int T_3 F_49 ( struct V_42 * V_43 )
{
struct V_85 * V_86 ;
int error ;
V_86 = F_50 () ;
if ( ! V_86 ) {
F_51 ( L_39 ) ;
return - V_51 ;
}
V_86 -> V_79 = L_40 ;
V_86 -> V_87 = L_41 ;
V_86 -> V_88 . V_89 = V_90 ;
V_86 -> V_53 . V_91 = & V_43 -> V_81 -> V_53 ;
error = F_52 ( V_86 , V_92 , NULL ) ;
if ( error ) {
F_10 ( L_42 ) ;
goto V_93;
}
error = F_53 ( V_86 ) ;
if ( error ) {
F_10 ( L_43 ) ;
goto V_94;
}
V_43 -> V_86 = V_86 ;
return 0 ;
V_94:
F_54 ( V_86 ) ;
V_93:
F_55 ( V_86 ) ;
return error ;
}
static void F_56 ( struct V_42 * V_43 )
{
F_54 ( V_43 -> V_86 ) ;
F_57 ( V_43 -> V_86 ) ;
V_43 -> V_86 = NULL ;
}
static void F_58 ( struct V_42 * V_43 ,
unsigned long V_95 )
{
F_59 ( V_43 -> V_86 , V_95 , 1 , true ) ;
}
static void F_60 ( struct V_42 * V_43 )
{
unsigned long V_96 ;
if ( F_7 ( V_24 , V_97 , & V_96 ) )
return;
if ( V_96 )
F_58 ( V_43 , 17 ) ;
else
F_58 ( V_43 , 16 ) ;
}
static int F_61 ( struct V_98 * V_99 )
{
unsigned long V_100 ;
if ( F_7 ( V_24 , V_26 , & V_100 ) )
return - V_101 ;
return V_100 ;
}
static int F_62 ( struct V_98 * V_99 )
{
if ( F_11 ( V_24 , V_102 ,
V_99 -> V_103 . V_104 ) )
return - V_101 ;
if ( F_11 ( V_24 , V_105 ,
V_99 -> V_103 . V_106 == V_107 ? 0 : 1 ) )
return - V_101 ;
return 0 ;
}
static int F_63 ( struct V_42 * V_43 )
{
struct V_98 * V_99 ;
struct V_108 V_103 ;
unsigned long V_109 , V_100 , V_106 ;
if ( F_7 ( V_24 , V_25 , & V_109 ) )
return - V_101 ;
if ( F_7 ( V_24 , V_26 , & V_100 ) )
return - V_101 ;
if ( F_7 ( V_24 , V_27 , & V_106 ) )
return - V_101 ;
memset ( & V_103 , 0 , sizeof( struct V_108 ) ) ;
V_103 . V_110 = V_109 ;
V_103 . type = V_111 ;
V_99 = F_64 ( L_30 ,
& V_43 -> V_81 -> V_53 ,
V_43 ,
& V_112 ,
& V_103 ) ;
if ( F_65 ( V_99 ) ) {
F_10 ( L_44 ) ;
return F_66 ( V_99 ) ;
}
V_43 -> V_99 = V_99 ;
V_99 -> V_103 . V_104 = V_100 ;
V_99 -> V_103 . V_106 = V_106 ? V_113 : V_107 ;
F_67 ( V_99 ) ;
return 0 ;
}
static void F_68 ( struct V_42 * V_43 )
{
if ( V_43 -> V_99 )
F_69 ( V_43 -> V_99 ) ;
V_43 -> V_99 = NULL ;
}
static void F_70 ( struct V_42 * V_43 )
{
unsigned long V_106 ;
struct V_98 * V_99 = V_43 -> V_99 ;
if ( ! V_99 )
return;
if ( F_7 ( V_24 , V_27 , & V_106 ) )
return;
V_99 -> V_103 . V_106 = V_106 ? V_113 : V_107 ;
}
static void F_71 ( struct V_42 * V_43 )
{
unsigned long V_100 ;
if ( V_43 -> V_99 == NULL ) {
F_7 ( V_24 , V_26 , & V_100 ) ;
return;
}
F_72 ( V_43 -> V_99 , V_114 ) ;
}
static int T_3 F_73 ( struct V_73 * V_74 )
{
int V_7 , V_70 ;
int V_37 ;
struct V_42 * V_43 ;
if ( F_1 ( V_74 -> V_1 , L_45 , & V_37 ) )
return - V_115 ;
V_43 = F_74 ( sizeof( * V_43 ) , V_116 ) ;
if ( ! V_43 )
return - V_51 ;
F_75 ( & V_74 -> V_53 , V_43 ) ;
V_36 = V_43 ;
V_24 = V_74 -> V_1 ;
V_43 -> V_37 = V_37 ;
V_7 = F_39 ( V_43 ) ;
if ( V_7 )
goto V_117;
V_7 = F_19 ( V_43 ) ;
if ( V_7 )
goto V_118;
V_7 = F_49 ( V_43 ) ;
if ( V_7 )
goto V_119;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
if ( F_17 ( V_77 [ V_70 ] . V_120 , & V_43 -> V_37 ) )
F_32 ( V_74 , V_70 ) ;
else
V_43 -> V_72 [ V_70 ] = NULL ;
}
F_30 ( V_43 ) ;
if ( ! F_76 () ) {
V_7 = F_63 ( V_43 ) ;
if ( V_7 && V_7 != - V_115 )
goto V_121;
}
return 0 ;
V_121:
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_37 ( V_74 , V_70 ) ;
F_56 ( V_43 ) ;
V_119:
F_22 ( V_43 ) ;
V_118:
F_46 ( V_43 ) ;
V_117:
F_77 ( V_43 ) ;
return V_7 ;
}
static int T_7 F_78 ( struct V_73 * V_74 , int type )
{
struct V_42 * V_43 = F_28 ( & V_74 -> V_53 ) ;
int V_70 ;
F_68 ( V_43 ) ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_37 ( V_74 , V_70 ) ;
F_56 ( V_43 ) ;
F_22 ( V_43 ) ;
F_46 ( V_43 ) ;
F_75 ( & V_74 -> V_53 , NULL ) ;
F_77 ( V_43 ) ;
return 0 ;
}
static void F_79 ( struct V_73 * V_74 , T_8 V_122 )
{
struct V_42 * V_43 = F_28 ( & V_74 -> V_53 ) ;
T_1 V_1 = V_74 -> V_1 ;
unsigned long V_123 , V_124 , V_125 ;
if ( F_7 ( V_1 , V_126 , & V_123 ) )
return;
if ( F_7 ( V_1 , V_127 , & V_124 ) )
return;
V_123 = ( V_124 << 8 ) | V_123 ;
for ( V_125 = 0 ; V_125 < 16 ; V_125 ++ ) {
if ( F_17 ( V_125 , & V_123 ) ) {
switch ( V_125 ) {
case 9 :
F_30 ( V_43 ) ;
break;
case 13 :
case 6 :
F_58 ( V_43 , V_125 ) ;
break;
case 4 :
F_71 ( V_43 ) ;
break;
case 3 :
F_60 ( V_43 ) ;
break;
case 2 :
F_70 ( V_43 ) ;
break;
default:
F_51 ( L_46 , V_125 ) ;
}
}
}
}
static int T_9 F_80 ( void )
{
return F_81 ( & V_128 ) ;
}
static void T_10 F_82 ( void )
{
F_83 ( & V_128 ) ;
}
