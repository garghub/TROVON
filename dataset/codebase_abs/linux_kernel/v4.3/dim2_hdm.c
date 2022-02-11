bool F_1 ( void )
{
bool V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 () ;
F_4 ( & V_3 , V_2 ) ;
return V_1 ;
}
T_1 F_5 ( T_1 * V_4 )
{
return F_6 ( V_4 ) ;
}
void F_7 ( T_1 * V_4 , T_1 V_5 )
{
F_8 ( V_5 , V_4 ) ;
}
void F_9 ( T_2 V_6 , const char * V_7 )
{
F_10 ( L_1 , V_6 ,
V_7 ) ;
}
void F_11 ( const char * V_8 , int V_9 )
{
F_10 ( L_2 , V_8 , V_9 ) ;
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_13 ( V_11 ) ;
struct V_14 * V_15 = V_11 -> V_13 . V_16 ;
T_2 V_17 ;
V_13 -> V_18 = - 1 ;
if ( V_19 ) {
if ( ! strcmp ( V_19 , L_3 ) )
V_13 -> V_18 = V_20 ;
else if ( ! strcmp ( V_19 , L_4 ) )
V_13 -> V_18 = V_21 ;
else if ( ! strcmp ( V_19 , L_5 ) )
V_13 -> V_18 = V_22 ;
else if ( ! strcmp ( V_19 , L_6 ) )
V_13 -> V_18 = V_23 ;
else if ( ! strcmp ( V_19 , L_7 ) )
V_13 -> V_18 = V_24 ;
else if ( ! strcmp ( V_19 , L_8 ) )
V_13 -> V_18 = V_25 ;
else if ( ! strcmp ( V_19 , L_9 ) )
V_13 -> V_18 = V_26 ;
else if ( ! strcmp ( V_19 , L_10 ) )
V_13 -> V_18 = V_27 ;
}
if ( V_13 -> V_18 == - 1 ) {
F_14 ( L_11
L_12 ) ;
V_13 -> V_18 = V_24 ;
} else
F_14 ( L_13 , V_19 ) ;
if ( V_15 && V_15 -> V_28 ) {
int V_29 = V_15 -> V_28 ( V_15 , V_13 -> V_30 , V_13 -> V_18 ) ;
if ( V_29 )
return V_29 ;
}
V_17 = F_15 ( V_13 -> V_30 , V_13 -> V_18 ) ;
if ( V_17 != V_31 ) {
F_10 ( L_14 , V_17 ) ;
if ( V_15 && V_15 -> V_32 )
V_15 -> V_32 ( V_15 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_16 ( struct V_34 * V_35 )
{
T_3 V_36 ;
struct V_37 * V_38 = & V_35 -> V_39 ;
struct V_40 * V_40 ;
unsigned long V_2 ;
struct V_41 V_42 ;
F_17 ( V_35 == 0 ) ;
F_17 ( ! V_35 -> V_43 ) ;
F_2 ( & V_3 , V_2 ) ;
if ( F_18 ( V_38 ) ) {
F_4 ( & V_3 , V_2 ) ;
return - V_44 ;
}
if ( ! F_19 ( & V_35 -> V_45 , & V_42 ) -> V_46 ) {
F_4 ( & V_3 , V_2 ) ;
return - V_44 ;
}
V_40 = F_20 ( V_38 -> V_47 , struct V_40 , V_48 ) ;
V_36 = V_40 -> V_49 ;
F_17 ( V_40 -> V_50 == 0 ) ;
if ( ! F_21 ( & V_35 -> V_45 , V_40 -> V_50 , V_36 ) ) {
F_22 ( V_38 -> V_47 ) ;
F_4 ( & V_3 , V_2 ) ;
V_40 -> V_51 = 0 ;
V_40 -> V_52 = V_53 ;
V_40 -> V_54 ( V_40 ) ;
return - V_55 ;
}
F_23 ( V_38 -> V_47 , & V_35 -> V_56 ) ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
static int F_24 ( void * V_57 )
{
struct V_12 * V_13 = (struct V_12 * ) V_57 ;
while ( ! F_25 () ) {
F_26 ( V_13 -> V_58 ,
V_13 -> V_59 ||
F_25 () ) ;
if ( V_13 -> V_59 ) {
V_13 -> V_59 -- ;
F_27 ( & V_13 -> V_60 , V_13 -> V_61 ,
V_13 -> V_62 ) ;
}
}
return 0 ;
}
static void F_28 ( struct V_12 * V_13 , struct V_40 * V_40 )
{
T_2 * V_57 = V_40 -> V_63 ;
T_2 * V_64 = V_13 -> V_62 ;
F_14 ( L_15 , ( T_3 ) V_57 [ 16 ] << 8 | V_57 [ 17 ] ) ;
V_13 -> V_61 = V_57 [ 18 ] ;
F_14 ( L_16 , V_13 -> V_61 ) ;
memcpy ( V_64 , V_57 + 19 , 6 ) ;
F_14 ( L_17 ,
V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] , V_64 [ 3 ] , V_64 [ 4 ] , V_64 [ 5 ] ) ;
V_13 -> V_59 ++ ;
F_29 ( & V_13 -> V_58 ) ;
}
static void F_30 ( struct V_12 * V_13 , int V_65 )
{
struct V_34 * V_35 = V_13 -> V_66 + V_65 ;
struct V_41 V_42 ;
struct V_37 * V_38 ;
struct V_40 * V_40 ;
int V_67 ;
unsigned long V_2 ;
T_2 * V_57 ;
F_17 ( V_35 == 0 ) ;
F_17 ( ! V_35 -> V_43 ) ;
F_2 ( & V_3 , V_2 ) ;
V_67 = F_19 ( & V_35 -> V_45 , & V_42 ) -> V_67 ;
if ( ! V_67 ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
if ( ! F_31 ( & V_35 -> V_45 , V_67 ) ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
F_4 ( & V_3 , V_2 ) ;
V_38 = & V_35 -> V_56 ;
while ( V_67 ) {
F_2 ( & V_3 , V_2 ) ;
if ( F_18 ( V_38 ) ) {
F_4 ( & V_3 , V_2 ) ;
F_32 ( L_18
L_19 ) ;
break;
}
V_40 = F_20 ( V_38 -> V_47 , struct V_40 , V_48 ) ;
F_22 ( V_38 -> V_47 ) ;
F_4 ( & V_3 , V_2 ) ;
V_57 = V_40 -> V_63 ;
if ( V_35 -> V_68 == V_69 &&
V_35 -> V_70 == V_71 &&
F_33 ( V_57 ) ) {
F_28 ( V_13 , V_40 ) ;
F_2 ( & V_3 , V_2 ) ;
F_34 ( & V_40 -> V_48 , & V_35 -> V_39 ) ;
F_4 ( & V_3 , V_2 ) ;
} else {
if ( V_35 -> V_68 == V_72 ||
V_35 -> V_68 == V_69 ) {
T_1 const V_73 =
( T_1 ) V_57 [ 0 ] * 256 + V_57 [ 1 ] + 2 ;
V_40 -> V_51 =
F_35 ( V_73 , ( T_1 ) V_40 -> V_49 ) ;
} else {
V_40 -> V_51 = V_40 -> V_49 ;
}
V_40 -> V_52 = V_74 ;
V_40 -> V_54 ( V_40 ) ;
}
V_67 -- ;
}
}
static struct V_75 * * F_36 ( struct V_12 * V_13 ,
struct V_75 * * V_76 )
{
int V_77 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ ) {
if ( V_13 -> V_66 [ V_65 ] . V_43 )
V_76 [ V_77 ++ ] = & V_13 -> V_66 [ V_65 ] . V_45 ;
}
V_76 [ V_77 ++ ] = 0 ;
return V_76 ;
}
static void F_37 ( unsigned long V_57 )
{
struct V_12 * V_13 = (struct V_12 * ) V_57 ;
unsigned long V_2 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ ) {
if ( ! V_13 -> V_66 [ V_65 ] . V_43 )
continue;
F_2 ( & V_3 , V_2 ) ;
F_38 ( & ( V_13 -> V_66 [ V_65 ] . V_45 ) ) ;
F_4 ( & V_3 , V_2 ) ;
F_30 ( V_13 , V_65 ) ;
while ( ! F_16 ( V_13 -> V_66 + V_65 ) )
continue;
}
}
static T_4 F_39 ( int V_79 , void * V_80 )
{
struct V_12 * V_13 = (struct V_12 * ) V_80 ;
struct V_75 * V_76 [ V_78 + 1 ] ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_40 ( F_36 ( V_13 , V_76 ) ) ;
F_4 ( & V_3 , V_2 ) ;
#if ! F_41 ( V_81 )
V_82 . V_57 = ( unsigned long ) V_13 ;
F_42 ( & V_82 ) ;
#else
F_37 ( ( unsigned long ) V_13 ) ;
#endif
return V_83 ;
}
void F_43 ( void )
{
( void ) F_39 ( 0 , V_84 ) ;
}
static void F_44 ( struct V_37 * V_38 )
{
unsigned long V_2 ;
struct V_40 * V_40 ;
for (; ; ) {
F_2 ( & V_3 , V_2 ) ;
if ( F_18 ( V_38 ) ) {
F_4 ( & V_3 , V_2 ) ;
break;
}
V_40 = F_20 ( V_38 -> V_47 , struct V_40 , V_48 ) ;
F_22 ( V_38 -> V_47 ) ;
F_4 ( & V_3 , V_2 ) ;
V_40 -> V_51 = 0 ;
V_40 -> V_52 = V_85 ;
V_40 -> V_54 ( V_40 ) ;
}
}
static int F_45 ( struct V_86 * V_60 , int V_65 ,
struct V_87 * V_88 )
{
struct V_12 * V_13 = F_46 ( V_60 ) ;
bool const V_89 = V_88 -> V_70 == V_90 ;
T_3 const V_91 = V_88 -> V_92 ;
T_3 const V_36 = V_88 -> V_93 ;
T_3 V_94 ;
unsigned long V_2 ;
T_2 V_17 ;
int const V_95 = V_65 * 2 + 2 ;
struct V_34 * const V_35 = V_13 -> V_66 + V_65 ;
F_17 ( V_65 < 0 || V_65 >= V_78 ) ;
if ( V_35 -> V_43 )
return - V_96 ;
switch ( V_88 -> V_68 ) {
case V_72 :
V_94 = F_47 ( V_36 ) ;
if ( V_94 == 0 ) {
F_10 ( L_20 , V_35 -> V_97 ) ;
return - V_98 ;
}
V_88 -> V_93 = V_94 ;
if ( V_94 != V_36 )
F_48 ( L_21 ,
V_35 -> V_97 , V_36 , V_94 ) ;
F_2 ( & V_3 , V_2 ) ;
V_17 = F_49 ( & V_35 -> V_45 , V_89 , V_95 , V_36 ) ;
break;
case V_69 :
V_94 = F_47 ( V_36 ) ;
if ( V_94 == 0 ) {
F_10 ( L_20 , V_35 -> V_97 ) ;
return - V_98 ;
}
V_88 -> V_93 = V_94 ;
if ( V_94 != V_36 )
F_48 ( L_21 ,
V_35 -> V_97 , V_36 , V_94 ) ;
F_2 ( & V_3 , V_2 ) ;
V_17 = F_50 ( & V_35 -> V_45 , V_89 , V_95 , V_36 ) ;
break;
case V_99 :
V_94 = F_51 ( V_36 , V_91 ) ;
if ( V_94 == 0 ) {
F_10 ( L_22
L_23 , V_35 -> V_97 ) ;
return - V_98 ;
}
V_88 -> V_93 = V_94 ;
if ( V_94 != V_36 )
F_48 ( L_21 ,
V_35 -> V_97 , V_36 , V_94 ) ;
F_2 ( & V_3 , V_2 ) ;
V_17 = F_52 ( & V_35 -> V_45 , V_89 , V_95 , V_91 ) ;
break;
case V_100 :
V_94 = F_53 ( V_36 , V_91 ) ;
if ( V_94 == 0 ) {
F_10 ( L_22
L_23 , V_35 -> V_97 ) ;
return - V_98 ;
}
V_88 -> V_93 = V_94 ;
if ( V_94 != V_36 )
F_48 ( L_21 ,
V_35 -> V_97 , V_36 , V_94 ) ;
F_2 ( & V_3 , V_2 ) ;
V_17 = F_54 ( & V_35 -> V_45 , V_89 , V_95 , V_91 ) ;
break;
default:
F_10 ( L_24 ,
V_35 -> V_97 , V_88 -> V_68 ) ;
return - V_98 ;
}
if ( V_17 != V_31 ) {
F_4 ( & V_3 , V_2 ) ;
F_10 ( L_25 ,
V_35 -> V_97 , V_17 , V_88 -> V_68 , ( int ) V_89 ) ;
return - V_33 ;
}
V_35 -> V_68 = V_88 -> V_68 ;
V_35 -> V_70 = V_88 -> V_70 ;
V_35 -> V_43 = true ;
if ( V_35 -> V_68 == V_69 &&
V_35 -> V_70 == V_90 &&
V_13 -> V_101 < 0 )
V_13 -> V_101 = V_65 ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_86 * V_60 , int V_65 ,
struct V_40 * V_40 )
{
struct V_12 * V_13 = F_46 ( V_60 ) ;
struct V_34 * V_35 = V_13 -> V_66 + V_65 ;
unsigned long V_2 ;
F_17 ( V_65 < 0 || V_65 >= V_78 ) ;
if ( ! V_35 -> V_43 )
return - V_96 ;
if ( V_40 -> V_50 == 0 )
return - V_55 ;
F_2 ( & V_3 , V_2 ) ;
F_34 ( & V_40 -> V_48 , & V_35 -> V_39 ) ;
F_4 ( & V_3 , V_2 ) ;
( void ) F_16 ( V_35 ) ;
return 0 ;
}
static void F_56 ( struct V_86 * V_60 , int V_65 )
{
struct V_12 * V_13 = F_46 ( V_60 ) ;
struct V_40 * V_40 ;
T_2 * V_57 ;
if ( V_13 -> V_101 < 0 ) {
F_10 ( L_26 ) ;
return;
}
V_40 = F_57 ( & V_13 -> V_60 , V_13 -> V_101 ) ;
if ( ! V_40 )
return;
V_40 -> V_49 = 5 ;
V_57 = V_40 -> V_63 ;
V_57 [ 0 ] = 0x00 ;
V_57 [ 1 ] = 0x03 ;
V_57 [ 2 ] = 0x02 ;
V_57 [ 3 ] = 0x08 ;
V_57 [ 4 ] = 0x40 ;
F_58 ( V_40 ) ;
}
static int F_59 ( struct V_86 * V_60 , int V_65 )
{
struct V_12 * V_13 = F_46 ( V_60 ) ;
struct V_34 * V_35 = V_13 -> V_66 + V_65 ;
unsigned long V_2 ;
T_2 V_17 ;
int V_29 = 0 ;
F_17 ( V_65 < 0 || V_65 >= V_78 ) ;
if ( ! V_35 -> V_43 )
return - V_96 ;
F_2 ( & V_3 , V_2 ) ;
V_17 = F_60 ( & V_35 -> V_45 ) ;
V_35 -> V_43 = false ;
if ( V_65 == V_13 -> V_101 )
V_13 -> V_101 = - 1 ;
F_4 ( & V_3 , V_2 ) ;
if ( V_17 != V_31 ) {
F_10 ( L_27 , V_35 -> V_97 ) ;
V_29 = - V_55 ;
}
F_44 ( & V_35 -> V_56 ) ;
F_44 ( & V_35 -> V_39 ) ;
return V_29 ;
}
static int F_61 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_102 * V_103 ;
int V_29 , V_104 ;
struct V_105 * V_106 ;
V_13 = F_62 ( sizeof( * V_13 ) , V_107 ) ;
if ( ! V_13 )
return - V_108 ;
V_13 -> V_101 = - 1 ;
F_63 ( V_11 , V_13 ) ;
#if F_41 ( V_81 )
V_84 = V_13 ;
#else
V_103 = F_64 ( V_11 , V_109 , 0 ) ;
if ( ! V_103 ) {
F_10 ( L_28 ) ;
V_29 = - V_110 ;
goto V_111;
}
if ( ! F_65 ( V_103 -> V_112 , F_66 ( V_103 ) , V_11 -> V_97 ) ) {
F_10 ( L_29 ) ;
V_29 = - V_113 ;
goto V_111;
}
V_13 -> V_30 = F_67 ( V_103 -> V_112 , F_66 ( V_103 ) ) ;
if ( ! V_13 -> V_30 ) {
F_10 ( L_30 ) ;
V_29 = - V_108 ;
goto V_114;
}
V_29 = F_68 ( V_11 , 0 ) ;
if ( V_29 < 0 ) {
F_10 ( L_31 ) ;
goto V_115;
}
V_13 -> V_116 = V_29 ;
V_29 = F_69 ( V_13 -> V_116 , F_39 , 0 , L_32 , V_13 ) ;
if ( V_29 ) {
F_10 ( L_33 , V_13 -> V_116 , V_29 ) ;
goto V_115;
}
#endif
F_70 ( & V_13 -> V_58 ) ;
V_13 -> V_59 = 0 ;
V_13 -> V_117 = F_71 ( & F_24 , ( void * ) V_13 ,
L_34 ) ;
if ( F_72 ( V_13 -> V_117 ) ) {
V_29 = F_73 ( V_13 -> V_117 ) ;
goto V_118;
}
for ( V_104 = 0 ; V_104 < V_78 ; V_104 ++ ) {
struct V_119 * V_120 = V_13 -> V_121 + V_104 ;
struct V_34 * V_35 = V_13 -> V_66 + V_104 ;
F_74 ( & V_35 -> V_39 ) ;
F_74 ( & V_35 -> V_56 ) ;
V_35 -> V_43 = false ;
snprintf ( V_35 -> V_97 , sizeof( V_35 -> V_97 ) , L_35 , V_104 * 2 + 2 ) ;
V_120 -> V_122 = V_35 -> V_97 ;
V_120 -> V_70 = V_71 | V_90 ;
V_120 -> V_68 = V_72 | V_69 |
V_99 | V_100 ;
V_120 -> V_123 = V_124 ;
V_120 -> V_125 = V_126 ;
V_120 -> V_127 = V_128 ;
V_120 -> V_129 = V_130 ;
}
{
const char * V_131 ;
if ( sizeof( V_103 -> V_112 ) == sizeof( long long ) )
V_131 = L_36 ;
else if ( sizeof( V_103 -> V_112 ) == sizeof( long ) )
V_131 = L_37 ;
else
V_131 = L_38 ;
snprintf ( V_13 -> V_97 , sizeof( V_13 -> V_97 ) , V_131 , V_103 -> V_112 ) ;
}
V_13 -> V_60 . V_132 = V_133 ;
V_13 -> V_60 . V_134 = V_13 -> V_97 ;
V_13 -> V_60 . V_135 = V_78 ;
V_13 -> V_60 . V_136 = V_13 -> V_121 ;
V_13 -> V_60 . V_137 = F_45 ;
V_13 -> V_60 . F_55 = F_55 ;
V_13 -> V_60 . F_59 = F_59 ;
V_13 -> V_60 . F_56 = F_56 ;
V_106 = F_75 ( & V_13 -> V_60 ) ;
if ( F_72 ( V_106 ) ) {
V_29 = F_73 ( V_106 ) ;
F_10 ( L_39 ) ;
goto V_138;
}
V_29 = F_76 ( & V_13 -> V_139 , V_106 ) ;
if ( V_29 )
goto V_140;
V_29 = F_12 ( V_11 ) ;
if ( V_29 ) {
F_10 ( L_40 ) ;
goto V_141;
}
return 0 ;
V_141:
F_77 ( & V_13 -> V_139 ) ;
V_140:
F_78 ( & V_13 -> V_60 ) ;
V_138:
F_79 ( V_13 -> V_117 ) ;
V_118:
#if ! F_41 ( V_81 )
F_80 ( V_13 -> V_116 , V_13 ) ;
V_115:
F_81 ( V_13 -> V_30 ) ;
V_114:
F_82 ( V_103 -> V_112 , F_66 ( V_103 ) ) ;
V_111:
#endif
F_83 ( V_13 ) ;
return V_29 ;
}
static int F_84 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_13 ( V_11 ) ;
struct V_102 * V_103 = F_64 ( V_11 , V_109 , 0 ) ;
struct V_14 * V_15 = V_11 -> V_13 . V_16 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_85 () ;
F_4 ( & V_3 , V_2 ) ;
if ( V_15 && V_15 -> V_32 )
V_15 -> V_32 ( V_15 ) ;
F_77 ( & V_13 -> V_139 ) ;
F_78 ( & V_13 -> V_60 ) ;
F_79 ( V_13 -> V_117 ) ;
#if ! F_41 ( V_81 )
F_80 ( V_13 -> V_116 , V_13 ) ;
F_81 ( V_13 -> V_30 ) ;
F_82 ( V_103 -> V_112 , F_66 ( V_103 ) ) ;
#endif
F_83 ( V_13 ) ;
F_63 ( V_11 , NULL ) ;
V_11 -> V_142 = 0 ;
return 0 ;
}
static int T_5 F_86 ( void )
{
F_14 ( L_41 ) ;
return F_87 ( & V_143 ) ;
}
static void T_6 F_88 ( void )
{
F_14 ( L_42 ) ;
F_89 ( & V_143 ) ;
}
