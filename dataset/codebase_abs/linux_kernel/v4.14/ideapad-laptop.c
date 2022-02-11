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
static int F_4 ( T_1 V_1 , unsigned long * V_6 )
{
int V_5 , V_3 ;
V_5 = F_1 ( V_1 , L_1 , & V_3 ) ;
* V_6 = V_3 ;
return V_5 ;
}
static int F_5 ( T_1 V_1 , int V_7 )
{
T_2 V_4 ;
V_4 = F_6 ( V_1 , L_2 , V_7 ) ;
return F_3 ( V_4 ) ? - 1 : 0 ;
}
static int F_7 ( T_1 V_1 , int V_7 , int * V_6 )
{
T_2 V_4 ;
unsigned long long V_5 ;
struct V_8 V_9 ;
union V_10 V_11 ;
V_9 . V_12 = 1 ;
V_9 . V_13 = & V_11 ;
V_11 . type = V_14 ;
V_11 . integer . V_15 = V_7 ;
V_4 = F_2 ( V_1 , L_3 , & V_9 , & V_5 ) ;
if ( F_3 ( V_4 ) ) {
* V_6 = - 1 ;
return - 1 ;
} else {
* V_6 = V_5 ;
return 0 ;
}
}
static int F_8 ( T_1 V_1 , int V_7 , int V_16 )
{
struct V_8 V_9 ;
union V_10 V_11 [ 2 ] ;
T_2 V_4 ;
V_9 . V_12 = 2 ;
V_9 . V_13 = V_11 ;
V_11 [ 0 ] . type = V_14 ;
V_11 [ 0 ] . integer . V_15 = V_7 ;
V_11 [ 1 ] . type = V_14 ;
V_11 [ 1 ] . integer . V_15 = V_16 ;
V_4 = F_9 ( V_1 , L_4 , & V_9 , NULL ) ;
if ( V_4 != V_17 )
return - 1 ;
return 0 ;
}
static int F_10 ( T_1 V_1 , int V_7 , unsigned long * V_16 )
{
int V_3 ;
unsigned long int V_18 ;
if ( F_8 ( V_1 , 1 , V_7 ) )
return - 1 ;
for ( V_18 = V_19 + ( V_20 ) * V_21 / 1000 + 1 ;
F_11 ( V_19 , V_18 ) ; ) {
F_12 () ;
if ( F_7 ( V_1 , 1 , & V_3 ) )
return - 1 ;
if ( V_3 == 0 ) {
if ( F_7 ( V_1 , 0 , & V_3 ) )
return - 1 ;
* V_16 = V_3 ;
return 0 ;
}
}
F_13 ( L_5 ) ;
return - 1 ;
}
static int F_14 ( T_1 V_1 , int V_7 , unsigned long V_16 )
{
int V_3 ;
unsigned long int V_18 ;
if ( F_8 ( V_1 , 0 , V_16 ) )
return - 1 ;
if ( F_8 ( V_1 , 1 , V_7 ) )
return - 1 ;
for ( V_18 = V_19 + ( V_20 ) * V_21 / 1000 + 1 ;
F_11 ( V_19 , V_18 ) ; ) {
F_12 () ;
if ( F_7 ( V_1 , 1 , & V_3 ) )
return - 1 ;
if ( V_3 == 0 )
return 0 ;
}
F_13 ( L_6 ) ;
return - 1 ;
}
static int F_15 ( struct V_22 * V_23 , void * V_16 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
unsigned long V_15 ;
if ( ! V_25 )
return - V_27 ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_29 , & V_15 ) )
F_16 ( V_23 , L_7 , V_15 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_30 , & V_15 ) )
F_16 ( V_23 , L_8 , V_15 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_31 , & V_15 ) )
F_16 ( V_23 , L_9 , V_15 ? L_10 : L_11 ) ;
F_16 ( V_23 , L_12 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_32 , & V_15 ) )
F_16 ( V_23 , L_13 ,
V_15 ? L_10 : L_11 , V_15 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_33 , & V_15 ) )
F_16 ( V_23 , L_14 ,
V_15 ? L_10 : L_11 , V_15 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_34 , & V_15 ) )
F_16 ( V_23 , L_15 ,
V_15 ? L_10 : L_11 , V_15 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_35 , & V_15 ) )
F_16 ( V_23 , L_16 ,
V_15 ? L_10 : L_11 , V_15 ) ;
F_16 ( V_23 , L_12 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_36 , & V_15 ) )
F_16 ( V_23 , L_17 ,
V_15 ? L_10 : L_11 , V_15 ) ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_37 , & V_15 ) )
F_16 ( V_23 , L_18 ,
V_15 ? L_10 : L_11 , V_15 ) ;
F_17 ( V_23 , L_12 ) ;
if ( ! F_4 ( V_25 -> V_28 -> V_1 , & V_15 ) ) {
F_16 ( V_23 , L_19 ,
F_18 ( V_38 , & V_15 ) ? L_10 : L_11 ,
V_15 ) ;
}
return 0 ;
}
static int F_19 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_20 ( V_40 , F_15 , V_39 -> V_41 ) ;
}
static int F_21 ( struct V_22 * V_23 , void * V_16 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
if ( ! V_25 ) {
F_16 ( V_23 , L_20 ) ;
} else {
F_16 ( V_23 , L_21 ,
V_25 -> V_42 ) ;
if ( F_18 ( V_43 , & V_25 -> V_42 ) )
F_16 ( V_23 , L_22 ) ;
if ( F_18 ( V_44 , & V_25 -> V_42 ) )
F_16 ( V_23 , L_23 ) ;
if ( F_18 ( V_45 , & V_25 -> V_42 ) )
F_16 ( V_23 , L_24 ) ;
if ( F_18 ( V_46 , & V_25 -> V_42 ) )
F_16 ( V_23 , L_25 ) ;
F_16 ( V_23 , L_26 ) ;
switch ( ( V_25 -> V_42 ) & 0x700 ) {
case 0x100 :
F_16 ( V_23 , L_27 ) ;
break;
case 0x200 :
F_16 ( V_23 , L_28 ) ;
break;
case 0x300 :
F_16 ( V_23 , L_29 ) ;
break;
case 0x400 :
F_16 ( V_23 , L_30 ) ;
break;
case 0x500 :
F_16 ( V_23 , L_31 ) ;
break;
}
F_16 ( V_23 , L_32 ) ;
}
return 0 ;
}
static int F_22 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_20 ( V_40 , F_21 , V_39 -> V_41 ) ;
}
static int F_23 ( struct V_24 * V_25 )
{
struct V_47 * V_48 ;
V_25 -> V_49 = F_24 ( L_33 , NULL ) ;
if ( V_25 -> V_49 == NULL ) {
F_13 ( L_34 ) ;
goto V_50;
}
V_48 = F_25 ( L_35 , V_51 , V_25 -> V_49 , V_25 ,
& V_52 ) ;
if ( ! V_48 ) {
F_13 ( L_36 ) ;
goto V_50;
}
V_48 = F_25 ( L_37 , V_51 , V_25 -> V_49 , V_25 ,
& V_53 ) ;
if ( ! V_48 ) {
F_13 ( L_38 ) ;
goto V_50;
}
return 0 ;
V_50:
return - V_54 ;
}
static void F_26 ( struct V_24 * V_25 )
{
F_27 ( V_25 -> V_49 ) ;
V_25 -> V_49 = NULL ;
}
static T_3 F_28 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_59 )
{
unsigned long V_5 ;
struct V_24 * V_25 = F_29 ( V_56 ) ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_37 , & V_5 ) )
return sprintf ( V_59 , L_39 ) ;
return sprintf ( V_59 , L_40 , V_5 ) ;
}
static T_3 F_30 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
const char * V_59 , T_4 V_12 )
{
int V_6 , V_60 ;
struct V_24 * V_25 = F_29 ( V_56 ) ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_59 , L_41 , & V_60 ) != 1 )
return - V_27 ;
V_6 = F_14 ( V_25 -> V_28 -> V_1 , V_61 , V_60 ) ;
if ( V_6 < 0 )
return - V_62 ;
return V_12 ;
}
static T_3 F_31 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_59 )
{
unsigned long V_5 ;
struct V_24 * V_25 = F_29 ( V_56 ) ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_63 , & V_5 ) )
return sprintf ( V_59 , L_39 ) ;
return sprintf ( V_59 , L_40 , V_5 ) ;
}
static T_3 F_32 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
const char * V_59 , T_4 V_12 )
{
int V_6 , V_60 ;
struct V_24 * V_25 = F_29 ( V_56 ) ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_59 , L_41 , & V_60 ) != 1 )
return - V_27 ;
if ( V_60 < 0 || V_60 > 4 || V_60 == 3 )
return - V_27 ;
V_6 = F_14 ( V_25 -> V_28 -> V_1 , V_64 , V_60 ) ;
if ( V_6 < 0 )
return - V_62 ;
return V_12 ;
}
static T_3 F_33 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_24 * V_25 = F_29 ( V_56 ) ;
unsigned long V_5 ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_36 , & V_5 ) )
return sprintf ( V_59 , L_39 ) ;
return sprintf ( V_59 , L_40 , V_5 ) ;
}
static T_3 T_5 F_34 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
const char * V_59 , T_4 V_12 )
{
struct V_24 * V_25 = F_29 ( V_56 ) ;
bool V_60 ;
int V_6 ;
V_6 = F_35 ( V_59 , & V_60 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_14 ( V_25 -> V_28 -> V_1 , V_65 , V_60 ) ;
if ( V_6 < 0 )
return - V_62 ;
return V_12 ;
}
static T_3 F_36 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_24 * V_25 = F_29 ( V_56 ) ;
unsigned long V_5 ;
if ( F_4 ( V_25 -> V_28 -> V_1 , & V_5 ) )
return sprintf ( V_59 , L_39 ) ;
return sprintf ( V_59 , L_42 , F_18 ( V_38 , & V_5 ) ) ;
}
static T_3 F_37 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
const char * V_59 , T_4 V_12 )
{
struct V_24 * V_25 = F_29 ( V_56 ) ;
bool V_60 ;
int V_6 ;
V_6 = F_35 ( V_59 , & V_60 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_5 ( V_25 -> V_28 -> V_1 , V_60 ?
V_66 :
V_67 ) ;
if ( V_6 < 0 )
return - V_62 ;
return V_12 ;
}
static T_6 F_38 ( struct V_68 * V_69 ,
struct V_70 * V_58 ,
int V_71 )
{
struct V_55 * V_56 = F_39 ( V_69 , struct V_55 , V_69 ) ;
struct V_24 * V_25 = F_29 ( V_56 ) ;
bool V_72 ;
if ( V_58 == & V_73 . V_58 )
V_72 = F_18 ( V_46 , & ( V_25 -> V_42 ) ) ;
else if ( V_58 == & V_74 . V_58 ) {
unsigned long V_15 ;
V_72 = ! F_10 ( V_25 -> V_28 -> V_1 , V_63 ,
& V_15 ) ;
} else if ( V_58 == & V_75 . V_58 ) {
V_72 = F_40 ( V_25 -> V_28 -> V_1 , L_1 ) &&
F_40 ( V_25 -> V_28 -> V_1 , L_2 ) ;
} else
V_72 = true ;
return V_72 ? V_58 -> V_76 : 0 ;
}
static int F_41 ( void * V_16 , bool V_77 )
{
struct V_78 * V_25 = V_16 ;
int V_79 = V_80 [ V_25 -> V_56 ] . V_79 ;
return F_14 ( V_25 -> V_25 -> V_28 -> V_1 , V_79 , ! V_77 ) ;
}
static void F_42 ( struct V_24 * V_25 )
{
unsigned long V_81 = 0 ;
int V_82 ;
if ( V_25 -> V_83 ) {
if ( F_10 ( V_25 -> V_28 -> V_1 , V_32 , & V_81 ) )
return;
V_81 = ! V_81 ;
}
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
if ( V_25 -> V_85 [ V_82 ] )
F_43 ( V_25 -> V_85 [ V_82 ] , V_81 ) ;
}
static int F_44 ( struct V_24 * V_25 , int V_56 )
{
int V_6 ;
unsigned long V_86 ;
if ( V_87 &&
( V_80 [ V_56 ] . type == V_88 ) ) {
F_14 ( V_25 -> V_28 -> V_1 ,
V_80 [ V_56 ] . V_79 , 1 ) ;
return 0 ;
}
V_25 -> V_89 [ V_56 ] . V_56 = V_56 ;
V_25 -> V_89 [ V_56 ] . V_25 = V_25 ;
V_25 -> V_85 [ V_56 ] = F_45 ( V_80 [ V_56 ] . V_90 ,
& V_25 -> V_91 -> V_56 ,
V_80 [ V_56 ] . type ,
& V_92 ,
& V_25 -> V_89 [ V_56 ] ) ;
if ( ! V_25 -> V_85 [ V_56 ] )
return - V_54 ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_80 [ V_56 ] . V_79 - 1 ,
& V_86 ) ) {
F_46 ( V_25 -> V_85 [ V_56 ] , 0 ) ;
} else {
V_86 = ! V_86 ;
F_46 ( V_25 -> V_85 [ V_56 ] , V_86 ) ;
}
V_6 = F_47 ( V_25 -> V_85 [ V_56 ] ) ;
if ( V_6 ) {
F_48 ( V_25 -> V_85 [ V_56 ] ) ;
return V_6 ;
}
return 0 ;
}
static void F_49 ( struct V_24 * V_25 , int V_56 )
{
if ( ! V_25 -> V_85 [ V_56 ] )
return;
F_50 ( V_25 -> V_85 [ V_56 ] ) ;
F_48 ( V_25 -> V_85 [ V_56 ] ) ;
}
static int F_51 ( struct V_24 * V_25 )
{
return F_52 ( & V_25 -> V_91 -> V_56 . V_69 ,
& V_93 ) ;
}
static void F_53 ( struct V_24 * V_25 )
{
F_54 ( & V_25 -> V_91 -> V_56 . V_69 ,
& V_93 ) ;
}
static int F_55 ( struct V_24 * V_25 )
{
struct V_94 * V_95 ;
int error ;
V_95 = F_56 () ;
if ( ! V_95 )
return - V_54 ;
V_95 -> V_90 = L_43 ;
V_95 -> V_96 = L_44 ;
V_95 -> V_97 . V_98 = V_99 ;
V_95 -> V_56 . V_100 = & V_25 -> V_91 -> V_56 ;
error = F_57 ( V_95 , V_101 , NULL ) ;
if ( error ) {
F_13 ( L_45 ) ;
goto V_102;
}
error = F_58 ( V_95 ) ;
if ( error ) {
F_13 ( L_46 ) ;
goto V_102;
}
V_25 -> V_95 = V_95 ;
return 0 ;
V_102:
F_59 ( V_95 ) ;
return error ;
}
static void F_60 ( struct V_24 * V_25 )
{
F_61 ( V_25 -> V_95 ) ;
V_25 -> V_95 = NULL ;
}
static void F_62 ( struct V_24 * V_25 ,
unsigned long V_103 )
{
F_63 ( V_25 -> V_95 , V_103 , 1 , true ) ;
}
static void F_64 ( struct V_24 * V_25 )
{
unsigned long V_104 ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_105 , & V_104 ) )
return;
if ( V_104 )
F_62 ( V_25 , 17 ) ;
else
F_62 ( V_25 , 16 ) ;
}
static void F_65 ( struct V_24 * V_25 )
{
unsigned long V_106 , V_15 ;
F_10 ( V_25 -> V_28 -> V_1 , V_107 , & V_15 ) ;
for ( V_106 = 0 ; V_106 < 16 ; V_106 ++ ) {
if ( F_18 ( V_106 , & V_15 ) ) {
switch ( V_106 ) {
case 0 :
case 6 :
F_62 ( V_25 , 65 ) ;
break;
case 1 :
F_62 ( V_25 , 64 ) ;
break;
default:
F_66 ( L_47 , V_106 ) ;
break;
}
}
}
}
static int F_67 ( struct V_108 * V_109 )
{
struct V_24 * V_25 = F_68 ( V_109 ) ;
unsigned long V_110 ;
if ( ! V_25 )
return - V_27 ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_30 , & V_110 ) )
return - V_62 ;
return V_110 ;
}
static int F_69 ( struct V_108 * V_109 )
{
struct V_24 * V_25 = F_68 ( V_109 ) ;
if ( ! V_25 )
return - V_27 ;
if ( F_14 ( V_25 -> V_28 -> V_1 , V_111 ,
V_109 -> V_112 . V_113 ) )
return - V_62 ;
if ( F_14 ( V_25 -> V_28 -> V_1 , V_114 ,
V_109 -> V_112 . V_115 == V_116 ? 0 : 1 ) )
return - V_62 ;
return 0 ;
}
static int F_70 ( struct V_24 * V_25 )
{
struct V_108 * V_109 ;
struct V_117 V_112 ;
unsigned long V_118 , V_110 , V_115 ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_29 , & V_118 ) )
return - V_62 ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_30 , & V_110 ) )
return - V_62 ;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_31 , & V_115 ) )
return - V_62 ;
memset ( & V_112 , 0 , sizeof( struct V_117 ) ) ;
V_112 . V_119 = V_118 ;
V_112 . type = V_120 ;
V_109 = F_71 ( L_33 ,
& V_25 -> V_91 -> V_56 ,
V_25 ,
& V_121 ,
& V_112 ) ;
if ( F_72 ( V_109 ) ) {
F_13 ( L_48 ) ;
return F_73 ( V_109 ) ;
}
V_25 -> V_109 = V_109 ;
V_109 -> V_112 . V_113 = V_110 ;
V_109 -> V_112 . V_115 = V_115 ? V_122 : V_116 ;
F_74 ( V_109 ) ;
return 0 ;
}
static void F_75 ( struct V_24 * V_25 )
{
F_76 ( V_25 -> V_109 ) ;
V_25 -> V_109 = NULL ;
}
static void F_77 ( struct V_24 * V_25 )
{
unsigned long V_115 ;
struct V_108 * V_109 = V_25 -> V_109 ;
if ( ! V_109 )
return;
if ( F_10 ( V_25 -> V_28 -> V_1 , V_31 , & V_115 ) )
return;
V_109 -> V_112 . V_115 = V_115 ? V_122 : V_116 ;
}
static void F_78 ( struct V_24 * V_25 )
{
unsigned long V_110 ;
if ( V_25 -> V_109 == NULL ) {
F_10 ( V_25 -> V_28 -> V_1 , V_30 , & V_110 ) ;
return;
}
F_79 ( V_25 -> V_109 , V_123 ) ;
}
static void F_80 ( struct V_24 * V_25 )
{
unsigned long V_15 ;
if ( ! F_10 ( V_25 -> V_28 -> V_1 , V_36 , & V_15 ) ) {
unsigned char V_124 ;
F_81 ( & V_124 , V_15 ? V_125 :
V_126 ) ;
F_62 ( V_25 , V_15 ? 67 : 66 ) ;
}
}
static void F_82 ( T_1 V_1 , T_7 V_127 , void * V_16 )
{
struct V_24 * V_25 = V_16 ;
unsigned long V_128 , V_129 , V_130 ;
if ( F_10 ( V_1 , V_131 , & V_128 ) )
return;
if ( F_10 ( V_1 , V_132 , & V_129 ) )
return;
V_128 = ( V_129 << 8 ) | V_128 ;
for ( V_130 = 0 ; V_130 < 16 ; V_130 ++ ) {
if ( F_18 ( V_130 , & V_128 ) ) {
switch ( V_130 ) {
case 9 :
F_42 ( V_25 ) ;
break;
case 13 :
case 11 :
case 8 :
case 7 :
case 6 :
F_62 ( V_25 , V_130 ) ;
break;
case 5 :
F_80 ( V_25 ) ;
break;
case 4 :
F_78 ( V_25 ) ;
break;
case 3 :
F_64 ( V_25 ) ;
break;
case 2 :
F_77 ( V_25 ) ;
break;
case 0 :
F_65 ( V_25 ) ;
break;
case 1 :
break;
default:
F_66 ( L_49 , V_130 ) ;
}
}
}
}
static void F_83 ( T_7 V_15 , void * V_133 )
{
switch ( V_15 ) {
case 128 :
F_62 ( V_133 , V_15 ) ;
break;
default:
F_66 ( L_50 , V_15 ) ;
}
}
static int F_84 ( struct V_91 * V_134 )
{
int V_6 , V_82 ;
int V_42 ;
struct V_24 * V_25 ;
struct V_135 * V_28 ;
V_6 = F_85 ( F_86 ( & V_134 -> V_56 ) , & V_28 ) ;
if ( V_6 )
return - V_136 ;
if ( F_1 ( V_28 -> V_1 , L_51 , & V_42 ) )
return - V_136 ;
V_25 = F_87 ( & V_134 -> V_56 , sizeof( * V_25 ) , V_137 ) ;
if ( ! V_25 )
return - V_54 ;
F_88 ( & V_134 -> V_56 , V_25 ) ;
V_25 -> V_42 = V_42 ;
V_25 -> V_28 = V_28 ;
V_25 -> V_91 = V_134 ;
V_25 -> V_83 = ! F_89 ( V_138 ) ;
V_6 = F_51 ( V_25 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_23 ( V_25 ) ;
if ( V_6 )
goto V_139;
V_6 = F_55 ( V_25 ) ;
if ( V_6 )
goto V_140;
if ( ! V_25 -> V_83 )
F_14 ( V_25 -> V_28 -> V_1 , V_141 , 1 ) ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
if ( F_18 ( V_80 [ V_82 ] . V_142 , & V_25 -> V_42 ) )
F_44 ( V_25 , V_82 ) ;
F_42 ( V_25 ) ;
F_80 ( V_25 ) ;
if ( F_90 () == V_143 ) {
V_6 = F_70 ( V_25 ) ;
if ( V_6 && V_6 != - V_136 )
goto V_144;
}
V_6 = F_91 ( V_28 -> V_1 ,
V_145 , F_82 , V_25 ) ;
if ( V_6 )
goto V_146;
#if F_92 ( V_147 )
for ( V_82 = 0 ; V_82 < F_93 ( V_148 ) ; V_82 ++ ) {
V_6 = F_94 ( V_148 [ V_82 ] ,
F_83 , V_25 ) ;
if ( V_6 == V_17 ) {
V_25 -> V_149 = V_148 [ V_82 ] ;
break;
}
}
if ( V_6 != V_17 && V_6 != V_150 )
goto V_151;
#endif
return 0 ;
#if F_92 ( V_147 )
V_151:
F_95 ( V_25 -> V_28 -> V_1 ,
V_145 , F_82 ) ;
#endif
V_146:
F_75 ( V_25 ) ;
V_144:
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
F_49 ( V_25 , V_82 ) ;
F_60 ( V_25 ) ;
V_140:
F_26 ( V_25 ) ;
V_139:
F_53 ( V_25 ) ;
return V_6 ;
}
static int F_96 ( struct V_91 * V_134 )
{
struct V_24 * V_25 = F_29 ( & V_134 -> V_56 ) ;
int V_82 ;
#if F_92 ( V_147 )
if ( V_25 -> V_149 )
F_97 ( V_25 -> V_149 ) ;
#endif
F_95 ( V_25 -> V_28 -> V_1 ,
V_145 , F_82 ) ;
F_75 ( V_25 ) ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ )
F_49 ( V_25 , V_82 ) ;
F_60 ( V_25 ) ;
F_26 ( V_25 ) ;
F_53 ( V_25 ) ;
F_88 ( & V_134 -> V_56 , NULL ) ;
return 0 ;
}
static int F_98 ( struct V_55 * V_55 )
{
struct V_24 * V_25 ;
if ( ! V_55 )
return - V_27 ;
V_25 = F_29 ( V_55 ) ;
F_42 ( V_25 ) ;
F_80 ( V_25 ) ;
return 0 ;
}
