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
static int F_19 ( struct V_42 * V_43 )
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
static T_3 F_24 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
char * V_56 )
{
unsigned long V_5 ;
if ( F_7 ( V_24 , V_33 , & V_5 ) )
return sprintf ( V_56 , L_36 ) ;
return sprintf ( V_56 , L_37 , V_5 ) ;
}
static T_3 F_25 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 , T_4 V_12 )
{
int V_7 , V_57 ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_56 , L_38 , & V_57 ) != 1 )
return - V_58 ;
V_7 = F_11 ( V_24 , V_59 , V_57 ) ;
if ( V_7 < 0 )
return - V_60 ;
return V_12 ;
}
static T_3 F_26 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
char * V_56 )
{
unsigned long V_5 ;
if ( F_7 ( V_24 , V_61 , & V_5 ) )
return sprintf ( V_56 , L_36 ) ;
return sprintf ( V_56 , L_37 , V_5 ) ;
}
static T_3 F_27 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 , T_4 V_12 )
{
int V_7 , V_57 ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_56 , L_38 , & V_57 ) != 1 )
return - V_58 ;
if ( V_57 < 0 || V_57 > 4 || V_57 == 3 )
return - V_58 ;
V_7 = F_11 ( V_24 , V_62 , V_57 ) ;
if ( V_7 < 0 )
return - V_60 ;
return V_12 ;
}
static T_5 F_28 ( struct V_63 * V_64 ,
struct V_65 * V_55 ,
int V_66 )
{
struct V_52 * V_53 = F_29 ( V_64 , struct V_52 , V_64 ) ;
struct V_42 * V_43 = F_30 ( V_53 ) ;
bool V_67 ;
if ( V_55 == & V_68 . V_55 )
V_67 = F_17 ( V_41 , & ( V_43 -> V_37 ) ) ;
else if ( V_55 == & V_69 . V_55 ) {
unsigned long V_15 ;
V_67 = ! F_7 ( V_24 , V_61 , & V_15 ) ;
} else
V_67 = true ;
return V_67 ? V_55 -> V_70 : 0 ;
}
static int F_31 ( void * V_16 , bool V_71 )
{
unsigned long V_72 = ( unsigned long ) V_16 ;
return F_11 ( V_24 , V_72 , ! V_71 ) ;
}
static void F_32 ( struct V_42 * V_43 )
{
unsigned long V_73 ;
int V_74 ;
if ( F_7 ( V_24 , V_28 , & V_73 ) )
return;
V_73 = ! V_73 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ )
if ( V_43 -> V_76 [ V_74 ] )
F_33 ( V_43 -> V_76 [ V_74 ] , V_73 ) ;
}
static int F_34 ( struct V_77 * V_78 , int V_53 )
{
struct V_42 * V_43 = F_30 ( & V_78 -> V_53 ) ;
int V_7 ;
unsigned long V_79 ;
if ( V_80 &&
( V_81 [ V_53 ] . type == V_82 ) ) {
F_11 ( V_24 ,
V_81 [ V_53 ] . V_72 , 1 ) ;
return 0 ;
}
V_43 -> V_76 [ V_53 ] = F_35 ( V_81 [ V_53 ] . V_83 , & V_78 -> V_53 ,
V_81 [ V_53 ] . type , & V_84 ,
( void * ) ( long ) V_53 ) ;
if ( ! V_43 -> V_76 [ V_53 ] )
return - V_51 ;
if ( F_7 ( V_24 , V_81 [ V_53 ] . V_72 - 1 ,
& V_79 ) ) {
F_36 ( V_43 -> V_76 [ V_53 ] , 0 ) ;
} else {
V_79 = ! V_79 ;
F_36 ( V_43 -> V_76 [ V_53 ] , V_79 ) ;
}
V_7 = F_37 ( V_43 -> V_76 [ V_53 ] ) ;
if ( V_7 ) {
F_38 ( V_43 -> V_76 [ V_53 ] ) ;
return V_7 ;
}
return 0 ;
}
static void F_39 ( struct V_77 * V_78 , int V_53 )
{
struct V_42 * V_43 = F_30 ( & V_78 -> V_53 ) ;
if ( ! V_43 -> V_76 [ V_53 ] )
return;
F_40 ( V_43 -> V_76 [ V_53 ] ) ;
F_38 ( V_43 -> V_76 [ V_53 ] ) ;
}
static int F_41 ( struct V_42 * V_43 )
{
int V_5 ;
V_43 -> V_85 = F_42 ( L_30 , - 1 ) ;
if ( ! V_43 -> V_85 )
return - V_51 ;
F_43 ( V_43 -> V_85 , V_43 ) ;
V_5 = F_44 ( V_43 -> V_85 ) ;
if ( V_5 )
goto V_86;
V_5 = F_45 ( & V_43 -> V_85 -> V_53 . V_64 ,
& V_87 ) ;
if ( V_5 )
goto V_88;
return 0 ;
V_88:
F_46 ( V_43 -> V_85 ) ;
V_86:
F_47 ( V_43 -> V_85 ) ;
return V_5 ;
}
static void F_48 ( struct V_42 * V_43 )
{
F_49 ( & V_43 -> V_85 -> V_53 . V_64 ,
& V_87 ) ;
F_50 ( V_43 -> V_85 ) ;
}
static int F_51 ( struct V_42 * V_43 )
{
struct V_89 * V_90 ;
int error ;
V_90 = F_52 () ;
if ( ! V_90 ) {
F_53 ( L_39 ) ;
return - V_51 ;
}
V_90 -> V_83 = L_40 ;
V_90 -> V_91 = L_41 ;
V_90 -> V_92 . V_93 = V_94 ;
V_90 -> V_53 . V_95 = & V_43 -> V_85 -> V_53 ;
error = F_54 ( V_90 , V_96 , NULL ) ;
if ( error ) {
F_10 ( L_42 ) ;
goto V_97;
}
error = F_55 ( V_90 ) ;
if ( error ) {
F_10 ( L_43 ) ;
goto V_98;
}
V_43 -> V_90 = V_90 ;
return 0 ;
V_98:
F_56 ( V_90 ) ;
V_97:
F_57 ( V_90 ) ;
return error ;
}
static void F_58 ( struct V_42 * V_43 )
{
F_56 ( V_43 -> V_90 ) ;
F_59 ( V_43 -> V_90 ) ;
V_43 -> V_90 = NULL ;
}
static void F_60 ( struct V_42 * V_43 ,
unsigned long V_99 )
{
F_61 ( V_43 -> V_90 , V_99 , 1 , true ) ;
}
static void F_62 ( struct V_42 * V_43 )
{
unsigned long V_100 ;
if ( F_7 ( V_24 , V_101 , & V_100 ) )
return;
if ( V_100 )
F_60 ( V_43 , 17 ) ;
else
F_60 ( V_43 , 16 ) ;
}
static void F_63 ( struct V_42 * V_43 )
{
unsigned long V_102 , V_15 ;
F_7 ( V_24 , V_103 , & V_15 ) ;
for ( V_102 = 0 ; V_102 < 16 ; V_102 ++ ) {
if ( F_17 ( V_102 , & V_15 ) ) {
switch ( V_102 ) {
case 6 :
F_60 ( V_43 , 65 ) ;
break;
case 1 :
F_60 ( V_43 , 64 ) ;
break;
}
}
}
}
static int F_64 ( struct V_104 * V_105 )
{
unsigned long V_106 ;
if ( F_7 ( V_24 , V_26 , & V_106 ) )
return - V_60 ;
return V_106 ;
}
static int F_65 ( struct V_104 * V_105 )
{
if ( F_11 ( V_24 , V_107 ,
V_105 -> V_108 . V_109 ) )
return - V_60 ;
if ( F_11 ( V_24 , V_110 ,
V_105 -> V_108 . V_111 == V_112 ? 0 : 1 ) )
return - V_60 ;
return 0 ;
}
static int F_66 ( struct V_42 * V_43 )
{
struct V_104 * V_105 ;
struct V_113 V_108 ;
unsigned long V_114 , V_106 , V_111 ;
if ( F_7 ( V_24 , V_25 , & V_114 ) )
return - V_60 ;
if ( F_7 ( V_24 , V_26 , & V_106 ) )
return - V_60 ;
if ( F_7 ( V_24 , V_27 , & V_111 ) )
return - V_60 ;
memset ( & V_108 , 0 , sizeof( struct V_113 ) ) ;
V_108 . V_115 = V_114 ;
V_108 . type = V_116 ;
V_105 = F_67 ( L_30 ,
& V_43 -> V_85 -> V_53 ,
V_43 ,
& V_117 ,
& V_108 ) ;
if ( F_68 ( V_105 ) ) {
F_10 ( L_44 ) ;
return F_69 ( V_105 ) ;
}
V_43 -> V_105 = V_105 ;
V_105 -> V_108 . V_109 = V_106 ;
V_105 -> V_108 . V_111 = V_111 ? V_118 : V_112 ;
F_70 ( V_105 ) ;
return 0 ;
}
static void F_71 ( struct V_42 * V_43 )
{
if ( V_43 -> V_105 )
F_72 ( V_43 -> V_105 ) ;
V_43 -> V_105 = NULL ;
}
static void F_73 ( struct V_42 * V_43 )
{
unsigned long V_111 ;
struct V_104 * V_105 = V_43 -> V_105 ;
if ( ! V_105 )
return;
if ( F_7 ( V_24 , V_27 , & V_111 ) )
return;
V_105 -> V_108 . V_111 = V_111 ? V_118 : V_112 ;
}
static void F_74 ( struct V_42 * V_43 )
{
unsigned long V_106 ;
if ( V_43 -> V_105 == NULL ) {
F_7 ( V_24 , V_26 , & V_106 ) ;
return;
}
F_75 ( V_43 -> V_105 , V_119 ) ;
}
static void F_76 ( struct V_77 * V_78 )
{
struct V_42 * V_43 = F_30 ( & V_78 -> V_53 ) ;
unsigned long V_15 ;
if ( ! F_7 ( V_78 -> V_1 , V_32 , & V_15 ) ) {
unsigned char V_120 ;
F_77 ( & V_120 , V_15 ? V_121 :
V_122 ) ;
F_60 ( V_43 , V_15 ? 67 : 66 ) ;
}
}
static int F_78 ( struct V_77 * V_78 )
{
int V_7 , V_74 ;
int V_37 ;
struct V_42 * V_43 ;
if ( F_1 ( V_78 -> V_1 , L_45 , & V_37 ) )
return - V_123 ;
V_43 = F_79 ( sizeof( * V_43 ) , V_124 ) ;
if ( ! V_43 )
return - V_51 ;
F_80 ( & V_78 -> V_53 , V_43 ) ;
V_36 = V_43 ;
V_24 = V_78 -> V_1 ;
V_43 -> V_37 = V_37 ;
V_7 = F_41 ( V_43 ) ;
if ( V_7 )
goto V_125;
V_7 = F_19 ( V_43 ) ;
if ( V_7 )
goto V_126;
V_7 = F_51 ( V_43 ) ;
if ( V_7 )
goto V_127;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
if ( F_17 ( V_81 [ V_74 ] . V_128 , & V_43 -> V_37 ) )
F_34 ( V_78 , V_74 ) ;
else
V_43 -> V_76 [ V_74 ] = NULL ;
}
F_32 ( V_43 ) ;
F_76 ( V_78 ) ;
if ( ! F_81 () ) {
V_7 = F_66 ( V_43 ) ;
if ( V_7 && V_7 != - V_123 )
goto V_129;
}
return 0 ;
V_129:
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ )
F_39 ( V_78 , V_74 ) ;
F_58 ( V_43 ) ;
V_127:
F_22 ( V_43 ) ;
V_126:
F_48 ( V_43 ) ;
V_125:
F_82 ( V_43 ) ;
return V_7 ;
}
static int F_83 ( struct V_77 * V_78 )
{
struct V_42 * V_43 = F_30 ( & V_78 -> V_53 ) ;
int V_74 ;
F_71 ( V_43 ) ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ )
F_39 ( V_78 , V_74 ) ;
F_58 ( V_43 ) ;
F_22 ( V_43 ) ;
F_48 ( V_43 ) ;
F_80 ( & V_78 -> V_53 , NULL ) ;
F_82 ( V_43 ) ;
return 0 ;
}
static void F_84 ( struct V_77 * V_78 , T_6 V_130 )
{
struct V_42 * V_43 = F_30 ( & V_78 -> V_53 ) ;
T_1 V_1 = V_78 -> V_1 ;
unsigned long V_131 , V_132 , V_133 ;
if ( F_7 ( V_1 , V_134 , & V_131 ) )
return;
if ( F_7 ( V_1 , V_135 , & V_132 ) )
return;
V_131 = ( V_132 << 8 ) | V_131 ;
for ( V_133 = 0 ; V_133 < 16 ; V_133 ++ ) {
if ( F_17 ( V_133 , & V_131 ) ) {
switch ( V_133 ) {
case 9 :
F_32 ( V_43 ) ;
break;
case 13 :
case 11 :
case 7 :
case 6 :
F_60 ( V_43 , V_133 ) ;
break;
case 5 :
F_76 ( V_78 ) ;
break;
case 4 :
F_74 ( V_43 ) ;
break;
case 3 :
F_62 ( V_43 ) ;
break;
case 2 :
F_73 ( V_43 ) ;
break;
case 0 :
F_63 ( V_43 ) ;
break;
default:
F_53 ( L_46 , V_133 ) ;
}
}
}
}
static int F_85 ( struct V_52 * V_52 )
{
F_32 ( V_36 ) ;
F_76 ( F_86 ( V_52 ) ) ;
return 0 ;
}
