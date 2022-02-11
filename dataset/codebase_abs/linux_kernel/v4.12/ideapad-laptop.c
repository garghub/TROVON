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
struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long V_15 ;
if ( ! V_25 )
return - V_27 ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_29 , & V_15 ) )
F_13 ( V_23 , L_5 , V_15 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_30 , & V_15 ) )
F_13 ( V_23 , L_6 , V_15 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_31 , & V_15 ) )
F_13 ( V_23 , L_7 , V_15 ? L_8 : L_9 ) ;
F_13 ( V_23 , L_10 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_32 , & V_15 ) )
F_13 ( V_23 , L_11 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_33 , & V_15 ) )
F_13 ( V_23 , L_12 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_34 , & V_15 ) )
F_13 ( V_23 , L_13 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_35 , & V_15 ) )
F_13 ( V_23 , L_14 ,
V_15 ? L_8 : L_9 , V_15 ) ;
F_13 ( V_23 , L_10 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_36 , & V_15 ) )
F_13 ( V_23 , L_15 ,
V_15 ? L_8 : L_9 , V_15 ) ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_37 , & V_15 ) )
F_13 ( V_23 , L_16 ,
V_15 ? L_8 : L_9 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_15 ( V_39 , F_12 , V_38 -> V_40 ) ;
}
static int F_16 ( struct V_22 * V_23 , void * V_16 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
if ( ! V_25 ) {
F_13 ( V_23 , L_17 ) ;
} else {
F_13 ( V_23 , L_18 ,
V_25 -> V_41 ) ;
if ( F_17 ( V_42 , & V_25 -> V_41 ) )
F_13 ( V_23 , L_19 ) ;
if ( F_17 ( V_43 , & V_25 -> V_41 ) )
F_13 ( V_23 , L_20 ) ;
if ( F_17 ( V_44 , & V_25 -> V_41 ) )
F_13 ( V_23 , L_21 ) ;
if ( F_17 ( V_45 , & V_25 -> V_41 ) )
F_13 ( V_23 , L_22 ) ;
F_13 ( V_23 , L_23 ) ;
switch ( ( V_25 -> V_41 ) & 0x700 ) {
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
static int F_18 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_15 ( V_39 , F_16 , V_38 -> V_40 ) ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_46 * V_47 ;
V_25 -> V_48 = F_20 ( L_30 , NULL ) ;
if ( V_25 -> V_48 == NULL ) {
F_10 ( L_31 ) ;
goto V_49;
}
V_47 = F_21 ( L_32 , V_50 , V_25 -> V_48 , V_25 ,
& V_51 ) ;
if ( ! V_47 ) {
F_10 ( L_33 ) ;
goto V_49;
}
V_47 = F_21 ( L_34 , V_50 , V_25 -> V_48 , V_25 ,
& V_52 ) ;
if ( ! V_47 ) {
F_10 ( L_35 ) ;
goto V_49;
}
return 0 ;
V_49:
return - V_53 ;
}
static void F_22 ( struct V_24 * V_25 )
{
F_23 ( V_25 -> V_48 ) ;
V_25 -> V_48 = NULL ;
}
static T_3 F_24 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_58 )
{
unsigned long V_5 ;
struct V_24 * V_25 = F_25 ( V_55 ) ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_37 , & V_5 ) )
return sprintf ( V_58 , L_36 ) ;
return sprintf ( V_58 , L_37 , V_5 ) ;
}
static T_3 F_26 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_58 , T_4 V_12 )
{
int V_7 , V_59 ;
struct V_24 * V_25 = F_25 ( V_55 ) ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_58 , L_38 , & V_59 ) != 1 )
return - V_27 ;
V_7 = F_11 ( V_25 -> V_28 -> V_1 , V_60 , V_59 ) ;
if ( V_7 < 0 )
return - V_61 ;
return V_12 ;
}
static T_3 F_27 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
char * V_58 )
{
unsigned long V_5 ;
struct V_24 * V_25 = F_25 ( V_55 ) ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_62 , & V_5 ) )
return sprintf ( V_58 , L_36 ) ;
return sprintf ( V_58 , L_37 , V_5 ) ;
}
static T_3 F_28 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
const char * V_58 , T_4 V_12 )
{
int V_7 , V_59 ;
struct V_24 * V_25 = F_25 ( V_55 ) ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_58 , L_38 , & V_59 ) != 1 )
return - V_27 ;
if ( V_59 < 0 || V_59 > 4 || V_59 == 3 )
return - V_27 ;
V_7 = F_11 ( V_25 -> V_28 -> V_1 , V_63 , V_59 ) ;
if ( V_7 < 0 )
return - V_61 ;
return V_12 ;
}
static T_5 F_29 ( struct V_64 * V_65 ,
struct V_66 * V_57 ,
int V_67 )
{
struct V_54 * V_55 = F_30 ( V_65 , struct V_54 , V_65 ) ;
struct V_24 * V_25 = F_25 ( V_55 ) ;
bool V_68 ;
if ( V_57 == & V_69 . V_57 )
V_68 = F_17 ( V_45 , & ( V_25 -> V_41 ) ) ;
else if ( V_57 == & V_70 . V_57 ) {
unsigned long V_15 ;
V_68 = ! F_7 ( V_25 -> V_28 -> V_1 , V_62 ,
& V_15 ) ;
} else
V_68 = true ;
return V_68 ? V_57 -> V_71 : 0 ;
}
static int F_31 ( void * V_16 , bool V_72 )
{
struct V_73 * V_25 = V_16 ;
int V_74 = V_75 [ V_25 -> V_55 ] . V_74 ;
return F_11 ( V_25 -> V_25 -> V_28 -> V_1 , V_74 , ! V_72 ) ;
}
static void F_32 ( struct V_24 * V_25 )
{
unsigned long V_76 = 0 ;
int V_77 ;
if ( V_25 -> V_78 ) {
if ( F_7 ( V_25 -> V_28 -> V_1 , V_32 , & V_76 ) )
return;
V_76 = ! V_76 ;
}
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ )
if ( V_25 -> V_80 [ V_77 ] )
F_33 ( V_25 -> V_80 [ V_77 ] , V_76 ) ;
}
static int F_34 ( struct V_24 * V_25 , int V_55 )
{
int V_7 ;
unsigned long V_81 ;
if ( V_82 &&
( V_75 [ V_55 ] . type == V_83 ) ) {
F_11 ( V_25 -> V_28 -> V_1 ,
V_75 [ V_55 ] . V_74 , 1 ) ;
return 0 ;
}
V_25 -> V_84 [ V_55 ] . V_55 = V_55 ;
V_25 -> V_84 [ V_55 ] . V_25 = V_25 ;
V_25 -> V_80 [ V_55 ] = F_35 ( V_75 [ V_55 ] . V_85 ,
& V_25 -> V_86 -> V_55 ,
V_75 [ V_55 ] . type ,
& V_87 ,
& V_25 -> V_84 [ V_55 ] ) ;
if ( ! V_25 -> V_80 [ V_55 ] )
return - V_53 ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_75 [ V_55 ] . V_74 - 1 ,
& V_81 ) ) {
F_36 ( V_25 -> V_80 [ V_55 ] , 0 ) ;
} else {
V_81 = ! V_81 ;
F_36 ( V_25 -> V_80 [ V_55 ] , V_81 ) ;
}
V_7 = F_37 ( V_25 -> V_80 [ V_55 ] ) ;
if ( V_7 ) {
F_38 ( V_25 -> V_80 [ V_55 ] ) ;
return V_7 ;
}
return 0 ;
}
static void F_39 ( struct V_24 * V_25 , int V_55 )
{
if ( ! V_25 -> V_80 [ V_55 ] )
return;
F_40 ( V_25 -> V_80 [ V_55 ] ) ;
F_38 ( V_25 -> V_80 [ V_55 ] ) ;
}
static int F_41 ( struct V_24 * V_25 )
{
return F_42 ( & V_25 -> V_86 -> V_55 . V_65 ,
& V_88 ) ;
}
static void F_43 ( struct V_24 * V_25 )
{
F_44 ( & V_25 -> V_86 -> V_55 . V_65 ,
& V_88 ) ;
}
static int F_45 ( struct V_24 * V_25 )
{
struct V_89 * V_90 ;
int error ;
V_90 = F_46 () ;
if ( ! V_90 )
return - V_53 ;
V_90 -> V_85 = L_39 ;
V_90 -> V_91 = L_40 ;
V_90 -> V_92 . V_93 = V_94 ;
V_90 -> V_55 . V_95 = & V_25 -> V_86 -> V_55 ;
error = F_47 ( V_90 , V_96 , NULL ) ;
if ( error ) {
F_10 ( L_41 ) ;
goto V_97;
}
error = F_48 ( V_90 ) ;
if ( error ) {
F_10 ( L_42 ) ;
goto V_97;
}
V_25 -> V_90 = V_90 ;
return 0 ;
V_97:
F_49 ( V_90 ) ;
return error ;
}
static void F_50 ( struct V_24 * V_25 )
{
F_51 ( V_25 -> V_90 ) ;
V_25 -> V_90 = NULL ;
}
static void F_52 ( struct V_24 * V_25 ,
unsigned long V_98 )
{
F_53 ( V_25 -> V_90 , V_98 , 1 , true ) ;
}
static void F_54 ( struct V_24 * V_25 )
{
unsigned long V_99 ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_100 , & V_99 ) )
return;
if ( V_99 )
F_52 ( V_25 , 17 ) ;
else
F_52 ( V_25 , 16 ) ;
}
static void F_55 ( struct V_24 * V_25 )
{
unsigned long V_101 , V_15 ;
F_7 ( V_25 -> V_28 -> V_1 , V_102 , & V_15 ) ;
for ( V_101 = 0 ; V_101 < 16 ; V_101 ++ ) {
if ( F_17 ( V_101 , & V_15 ) ) {
switch ( V_101 ) {
case 0 :
case 6 :
F_52 ( V_25 , 65 ) ;
break;
case 1 :
F_52 ( V_25 , 64 ) ;
break;
default:
F_56 ( L_43 , V_101 ) ;
break;
}
}
}
}
static int F_57 ( struct V_103 * V_104 )
{
struct V_24 * V_25 = F_58 ( V_104 ) ;
unsigned long V_105 ;
if ( ! V_25 )
return - V_27 ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_30 , & V_105 ) )
return - V_61 ;
return V_105 ;
}
static int F_59 ( struct V_103 * V_104 )
{
struct V_24 * V_25 = F_58 ( V_104 ) ;
if ( ! V_25 )
return - V_27 ;
if ( F_11 ( V_25 -> V_28 -> V_1 , V_106 ,
V_104 -> V_107 . V_108 ) )
return - V_61 ;
if ( F_11 ( V_25 -> V_28 -> V_1 , V_109 ,
V_104 -> V_107 . V_110 == V_111 ? 0 : 1 ) )
return - V_61 ;
return 0 ;
}
static int F_60 ( struct V_24 * V_25 )
{
struct V_103 * V_104 ;
struct V_112 V_107 ;
unsigned long V_113 , V_105 , V_110 ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_29 , & V_113 ) )
return - V_61 ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_30 , & V_105 ) )
return - V_61 ;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_31 , & V_110 ) )
return - V_61 ;
memset ( & V_107 , 0 , sizeof( struct V_112 ) ) ;
V_107 . V_114 = V_113 ;
V_107 . type = V_115 ;
V_104 = F_61 ( L_30 ,
& V_25 -> V_86 -> V_55 ,
V_25 ,
& V_116 ,
& V_107 ) ;
if ( F_62 ( V_104 ) ) {
F_10 ( L_44 ) ;
return F_63 ( V_104 ) ;
}
V_25 -> V_104 = V_104 ;
V_104 -> V_107 . V_108 = V_105 ;
V_104 -> V_107 . V_110 = V_110 ? V_117 : V_111 ;
F_64 ( V_104 ) ;
return 0 ;
}
static void F_65 ( struct V_24 * V_25 )
{
F_66 ( V_25 -> V_104 ) ;
V_25 -> V_104 = NULL ;
}
static void F_67 ( struct V_24 * V_25 )
{
unsigned long V_110 ;
struct V_103 * V_104 = V_25 -> V_104 ;
if ( ! V_104 )
return;
if ( F_7 ( V_25 -> V_28 -> V_1 , V_31 , & V_110 ) )
return;
V_104 -> V_107 . V_110 = V_110 ? V_117 : V_111 ;
}
static void F_68 ( struct V_24 * V_25 )
{
unsigned long V_105 ;
if ( V_25 -> V_104 == NULL ) {
F_7 ( V_25 -> V_28 -> V_1 , V_30 , & V_105 ) ;
return;
}
F_69 ( V_25 -> V_104 , V_118 ) ;
}
static void F_70 ( struct V_24 * V_25 )
{
unsigned long V_15 ;
if ( ! F_7 ( V_25 -> V_28 -> V_1 , V_36 , & V_15 ) ) {
unsigned char V_119 ;
F_71 ( & V_119 , V_15 ? V_120 :
V_121 ) ;
F_52 ( V_25 , V_15 ? 67 : 66 ) ;
}
}
static void F_72 ( T_1 V_1 , T_6 V_122 , void * V_16 )
{
struct V_24 * V_25 = V_16 ;
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
F_32 ( V_25 ) ;
break;
case 13 :
case 11 :
case 8 :
case 7 :
case 6 :
case 1 :
F_52 ( V_25 , V_125 ) ;
break;
case 5 :
F_70 ( V_25 ) ;
break;
case 4 :
F_68 ( V_25 ) ;
break;
case 3 :
F_54 ( V_25 ) ;
break;
case 2 :
F_67 ( V_25 ) ;
break;
case 0 :
F_55 ( V_25 ) ;
break;
default:
F_56 ( L_45 , V_125 ) ;
}
}
}
}
static void F_73 ( T_6 V_15 , void * V_128 )
{
switch ( V_15 ) {
case 128 :
F_52 ( V_128 , V_15 ) ;
break;
default:
F_56 ( L_46 , V_15 ) ;
}
}
static int F_74 ( struct V_86 * V_129 )
{
int V_7 , V_77 ;
int V_41 ;
struct V_24 * V_25 ;
struct V_130 * V_28 ;
V_7 = F_75 ( F_76 ( & V_129 -> V_55 ) , & V_28 ) ;
if ( V_7 )
return - V_131 ;
if ( F_1 ( V_28 -> V_1 , L_47 , & V_41 ) )
return - V_131 ;
V_25 = F_77 ( & V_129 -> V_55 , sizeof( * V_25 ) , V_132 ) ;
if ( ! V_25 )
return - V_53 ;
F_78 ( & V_129 -> V_55 , V_25 ) ;
V_25 -> V_41 = V_41 ;
V_25 -> V_28 = V_28 ;
V_25 -> V_86 = V_129 ;
V_25 -> V_78 = ! F_79 ( V_133 ) ;
V_7 = F_41 ( V_25 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_19 ( V_25 ) ;
if ( V_7 )
goto V_134;
V_7 = F_45 ( V_25 ) ;
if ( V_7 )
goto V_135;
if ( ! V_25 -> V_78 )
F_11 ( V_25 -> V_28 -> V_1 , V_136 , 1 ) ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ )
if ( F_17 ( V_75 [ V_77 ] . V_137 , & V_25 -> V_41 ) )
F_34 ( V_25 , V_77 ) ;
F_32 ( V_25 ) ;
F_70 ( V_25 ) ;
if ( F_80 () == V_138 ) {
V_7 = F_60 ( V_25 ) ;
if ( V_7 && V_7 != - V_131 )
goto V_139;
}
V_7 = F_81 ( V_28 -> V_1 ,
V_140 , F_72 , V_25 ) ;
if ( V_7 )
goto V_141;
#if F_82 ( V_142 )
for ( V_77 = 0 ; V_77 < F_83 ( V_143 ) ; V_77 ++ ) {
V_7 = F_84 ( V_143 [ V_77 ] ,
F_73 , V_25 ) ;
if ( V_7 == V_17 ) {
V_25 -> V_144 = V_143 [ V_77 ] ;
break;
}
}
if ( V_7 != V_17 && V_7 != V_145 )
goto V_146;
#endif
return 0 ;
#if F_82 ( V_142 )
V_146:
F_85 ( V_25 -> V_28 -> V_1 ,
V_140 , F_72 ) ;
#endif
V_141:
F_65 ( V_25 ) ;
V_139:
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ )
F_39 ( V_25 , V_77 ) ;
F_50 ( V_25 ) ;
V_135:
F_22 ( V_25 ) ;
V_134:
F_43 ( V_25 ) ;
return V_7 ;
}
static int F_86 ( struct V_86 * V_129 )
{
struct V_24 * V_25 = F_25 ( & V_129 -> V_55 ) ;
int V_77 ;
#if F_82 ( V_142 )
if ( V_25 -> V_144 )
F_87 ( V_25 -> V_144 ) ;
#endif
F_85 ( V_25 -> V_28 -> V_1 ,
V_140 , F_72 ) ;
F_65 ( V_25 ) ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ )
F_39 ( V_25 , V_77 ) ;
F_50 ( V_25 ) ;
F_22 ( V_25 ) ;
F_43 ( V_25 ) ;
F_78 ( & V_129 -> V_55 , NULL ) ;
return 0 ;
}
static int F_88 ( struct V_54 * V_54 )
{
struct V_24 * V_25 ;
if ( ! V_54 )
return - V_27 ;
V_25 = F_25 ( V_54 ) ;
F_32 ( V_25 ) ;
F_70 ( V_25 ) ;
return 0 ;
}
