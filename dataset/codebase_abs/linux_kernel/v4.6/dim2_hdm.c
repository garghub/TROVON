bool F_1 ( void )
{
bool V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 () ;
F_4 ( & V_3 , V_2 ) ;
return V_1 ;
}
T_1 F_5 ( T_1 T_2 * V_4 )
{
return F_6 ( V_4 ) ;
}
void F_7 ( T_1 T_2 * V_4 , T_1 V_5 )
{
F_8 ( V_5 , V_4 ) ;
}
void F_9 ( T_3 V_6 , const char * V_7 )
{
F_10 ( L_1 , V_6 ,
V_7 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_12 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_11 . V_14 ;
T_3 V_15 ;
V_11 -> V_16 = - 1 ;
if ( V_17 ) {
if ( ! strcmp ( V_17 , L_2 ) )
V_11 -> V_16 = V_18 ;
else if ( ! strcmp ( V_17 , L_3 ) )
V_11 -> V_16 = V_19 ;
else if ( ! strcmp ( V_17 , L_4 ) )
V_11 -> V_16 = V_20 ;
else if ( ! strcmp ( V_17 , L_5 ) )
V_11 -> V_16 = V_21 ;
else if ( ! strcmp ( V_17 , L_6 ) )
V_11 -> V_16 = V_22 ;
else if ( ! strcmp ( V_17 , L_7 ) )
V_11 -> V_16 = V_23 ;
else if ( ! strcmp ( V_17 , L_8 ) )
V_11 -> V_16 = V_24 ;
else if ( ! strcmp ( V_17 , L_9 ) )
V_11 -> V_16 = V_25 ;
}
if ( V_11 -> V_16 == - 1 ) {
F_13 ( L_10 ) ;
V_11 -> V_16 = V_22 ;
} else {
F_13 ( L_11 , V_17 ) ;
}
if ( V_13 && V_13 -> V_26 ) {
int V_27 = V_13 -> V_26 ( V_13 , V_11 -> V_28 , V_11 -> V_16 ) ;
if ( V_27 )
return V_27 ;
}
V_15 = F_14 ( V_11 -> V_28 , V_11 -> V_16 ) ;
if ( V_15 != V_29 ) {
F_10 ( L_12 , V_15 ) ;
if ( V_13 && V_13 -> V_30 )
V_13 -> V_30 ( V_13 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_15 ( struct V_32 * V_33 )
{
T_4 V_34 ;
struct V_35 * V_36 = & V_33 -> V_37 ;
struct V_38 * V_38 ;
unsigned long V_2 ;
struct V_39 V_40 ;
F_16 ( ! V_33 ) ;
F_16 ( ! V_33 -> V_41 ) ;
F_2 ( & V_3 , V_2 ) ;
if ( F_17 ( V_36 ) ) {
F_4 ( & V_3 , V_2 ) ;
return - V_42 ;
}
if ( ! F_18 ( & V_33 -> V_43 , & V_40 ) -> V_44 ) {
F_4 ( & V_3 , V_2 ) ;
return - V_42 ;
}
V_38 = F_19 ( V_36 , struct V_38 , V_45 ) ;
V_34 = V_38 -> V_46 ;
F_16 ( V_38 -> V_47 == 0 ) ;
if ( ! F_20 ( & V_33 -> V_43 , V_38 -> V_47 , V_34 ) ) {
F_21 ( V_36 -> V_48 ) ;
F_4 ( & V_3 , V_2 ) ;
V_38 -> V_49 = 0 ;
V_38 -> V_50 = V_51 ;
V_38 -> V_52 ( V_38 ) ;
return - V_53 ;
}
F_22 ( V_36 -> V_48 , & V_33 -> V_54 ) ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
static int F_23 ( void * V_55 )
{
struct V_10 * V_11 = V_55 ;
while ( ! F_24 () ) {
F_25 ( V_11 -> V_56 ,
V_11 -> V_57 ||
F_24 () ) ;
if ( V_11 -> V_57 ) {
V_11 -> V_57 -- ;
F_26 ( & V_11 -> V_58 , V_11 -> V_59 ,
V_11 -> V_60 ) ;
}
}
return 0 ;
}
static void F_27 ( struct V_10 * V_11 , struct V_38 * V_38 )
{
T_3 * V_55 = V_38 -> V_61 ;
T_3 * V_62 = V_11 -> V_60 ;
F_13 ( L_13 , ( T_4 ) V_55 [ 16 ] << 8 | V_55 [ 17 ] ) ;
V_11 -> V_59 = V_55 [ 18 ] ;
F_13 ( L_14 , V_11 -> V_59 ) ;
memcpy ( V_62 , V_55 + 19 , 6 ) ;
F_13 ( L_15 ,
V_62 [ 0 ] , V_62 [ 1 ] , V_62 [ 2 ] , V_62 [ 3 ] , V_62 [ 4 ] , V_62 [ 5 ] ) ;
V_11 -> V_57 ++ ;
F_28 ( & V_11 -> V_56 ) ;
}
static void F_29 ( struct V_10 * V_11 , int V_63 )
{
struct V_32 * V_33 = V_11 -> V_64 + V_63 ;
struct V_39 V_40 ;
struct V_35 * V_36 ;
struct V_38 * V_38 ;
int V_65 ;
unsigned long V_2 ;
T_3 * V_55 ;
F_16 ( ! V_33 ) ;
F_16 ( ! V_33 -> V_41 ) ;
F_2 ( & V_3 , V_2 ) ;
V_65 = F_18 ( & V_33 -> V_43 , & V_40 ) -> V_65 ;
if ( ! V_65 ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
if ( ! F_30 ( & V_33 -> V_43 , V_65 ) ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
F_4 ( & V_3 , V_2 ) ;
V_36 = & V_33 -> V_54 ;
while ( V_65 ) {
F_2 ( & V_3 , V_2 ) ;
if ( F_17 ( V_36 ) ) {
F_4 ( & V_3 , V_2 ) ;
F_31 ( L_16 ) ;
break;
}
V_38 = F_19 ( V_36 , struct V_38 , V_45 ) ;
F_21 ( V_36 -> V_48 ) ;
F_4 ( & V_3 , V_2 ) ;
V_55 = V_38 -> V_61 ;
if ( V_33 -> V_66 == V_67 &&
V_33 -> V_68 == V_69 &&
F_32 ( V_55 ) ) {
F_27 ( V_11 , V_38 ) ;
F_2 ( & V_3 , V_2 ) ;
F_33 ( & V_38 -> V_45 , & V_33 -> V_37 ) ;
F_4 ( & V_3 , V_2 ) ;
} else {
if ( V_33 -> V_66 == V_70 ||
V_33 -> V_66 == V_67 ) {
T_1 const V_71 =
( T_1 ) V_55 [ 0 ] * 256 + V_55 [ 1 ] + 2 ;
V_38 -> V_49 =
F_34 ( T_1 , V_71 ,
V_38 -> V_46 ) ;
} else {
V_38 -> V_49 = V_38 -> V_46 ;
}
V_38 -> V_50 = V_72 ;
V_38 -> V_52 ( V_38 ) ;
}
V_65 -- ;
}
}
static struct V_73 * * F_35 ( struct V_10 * V_11 ,
struct V_73 * * V_74 )
{
int V_75 = 0 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_76 ; V_63 ++ ) {
if ( V_11 -> V_64 [ V_63 ] . V_41 )
V_74 [ V_75 ++ ] = & V_11 -> V_64 [ V_63 ] . V_43 ;
}
V_74 [ V_75 ++ ] = NULL ;
return V_74 ;
}
static void F_36 ( unsigned long V_55 )
{
struct V_10 * V_11 = (struct V_10 * ) V_55 ;
unsigned long V_2 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_76 ; V_63 ++ ) {
if ( ! V_11 -> V_64 [ V_63 ] . V_41 )
continue;
F_2 ( & V_3 , V_2 ) ;
F_37 ( & V_11 -> V_64 [ V_63 ] . V_43 ) ;
F_4 ( & V_3 , V_2 ) ;
F_29 ( V_11 , V_63 ) ;
while ( ! F_15 ( V_11 -> V_64 + V_63 ) )
continue;
}
}
static T_5 F_38 ( int V_77 , void * V_78 )
{
struct V_10 * V_11 = V_78 ;
struct V_73 * V_74 [ V_76 + 1 ] ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_39 ( F_35 ( V_11 , V_74 ) ) ;
F_4 ( & V_3 , V_2 ) ;
#if ! F_40 ( V_79 )
V_80 . V_55 = ( unsigned long ) V_11 ;
F_41 ( & V_80 ) ;
#else
F_36 ( ( unsigned long ) V_11 ) ;
#endif
return V_81 ;
}
void F_42 ( void )
{
( void ) F_38 ( 0 , V_82 ) ;
}
static void F_43 ( struct V_35 * V_36 )
{
unsigned long V_2 ;
struct V_38 * V_38 ;
for (; ; ) {
F_2 ( & V_3 , V_2 ) ;
if ( F_17 ( V_36 ) ) {
F_4 ( & V_3 , V_2 ) ;
break;
}
V_38 = F_19 ( V_36 , struct V_38 , V_45 ) ;
F_21 ( V_36 -> V_48 ) ;
F_4 ( & V_3 , V_2 ) ;
V_38 -> V_49 = 0 ;
V_38 -> V_50 = V_83 ;
V_38 -> V_52 ( V_38 ) ;
}
}
static int F_44 ( struct V_84 * V_58 , int V_63 ,
struct V_85 * V_86 )
{
struct V_10 * V_11 = F_45 ( V_58 ) ;
bool const V_87 = V_86 -> V_68 == V_88 ;
T_4 const V_89 = V_86 -> V_90 ;
T_4 const V_34 = V_86 -> V_91 ;
T_4 V_92 ;
unsigned long V_2 ;
T_3 V_15 ;
int const V_93 = V_63 * 2 + 2 ;
struct V_32 * const V_33 = V_11 -> V_64 + V_63 ;
F_16 ( V_63 < 0 || V_63 >= V_76 ) ;
if ( V_33 -> V_41 )
return - V_94 ;
switch ( V_86 -> V_66 ) {
case V_70 :
V_92 = F_46 ( V_34 ) ;
if ( V_92 == 0 ) {
F_10 ( L_17 , V_33 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_34 )
F_47 ( L_18 ,
V_33 -> V_95 , V_34 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_48 ( & V_33 -> V_43 , V_87 , V_93 ,
V_34 ) ;
break;
case V_67 :
V_92 = F_46 ( V_34 ) ;
if ( V_92 == 0 ) {
F_10 ( L_17 , V_33 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_34 )
F_47 ( L_18 ,
V_33 -> V_95 , V_34 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_49 ( & V_33 -> V_43 , V_87 , V_93 , V_34 ) ;
break;
case V_97 :
V_92 = F_50 ( V_34 , V_89 ) ;
if ( V_92 == 0 ) {
F_10 ( L_19 ,
V_33 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_34 )
F_47 ( L_18 ,
V_33 -> V_95 , V_34 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_51 ( & V_33 -> V_43 , V_87 , V_93 , V_89 ) ;
break;
case V_98 :
V_92 = F_52 ( V_34 , V_89 ) ;
if ( V_92 == 0 ) {
F_10 ( L_19 ,
V_33 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_34 )
F_47 ( L_18 ,
V_33 -> V_95 , V_34 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_53 ( & V_33 -> V_43 , V_87 , V_93 , V_89 ) ;
break;
default:
F_10 ( L_20 ,
V_33 -> V_95 , V_86 -> V_66 ) ;
return - V_96 ;
}
if ( V_15 != V_29 ) {
F_4 ( & V_3 , V_2 ) ;
F_10 ( L_21 ,
V_33 -> V_95 , V_15 , V_86 -> V_66 , ( int ) V_87 ) ;
return - V_31 ;
}
V_33 -> V_66 = V_86 -> V_66 ;
V_33 -> V_68 = V_86 -> V_68 ;
V_33 -> V_41 = true ;
if ( V_33 -> V_66 == V_67 &&
V_33 -> V_68 == V_88 &&
V_11 -> V_99 < 0 )
V_11 -> V_99 = V_63 ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_84 * V_58 , int V_63 ,
struct V_38 * V_38 )
{
struct V_10 * V_11 = F_45 ( V_58 ) ;
struct V_32 * V_33 = V_11 -> V_64 + V_63 ;
unsigned long V_2 ;
F_16 ( V_63 < 0 || V_63 >= V_76 ) ;
if ( ! V_33 -> V_41 )
return - V_94 ;
if ( V_38 -> V_47 == 0 )
return - V_53 ;
F_2 ( & V_3 , V_2 ) ;
F_33 ( & V_38 -> V_45 , & V_33 -> V_37 ) ;
F_4 ( & V_3 , V_2 ) ;
( void ) F_15 ( V_33 ) ;
return 0 ;
}
static void F_55 ( struct V_84 * V_58 , int V_63 )
{
struct V_10 * V_11 = F_45 ( V_58 ) ;
struct V_38 * V_38 ;
T_3 * V_55 ;
if ( V_11 -> V_99 < 0 ) {
F_10 ( L_22 ) ;
return;
}
V_38 = F_56 ( & V_11 -> V_58 , V_11 -> V_99 , NULL ) ;
if ( ! V_38 )
return;
V_38 -> V_46 = 5 ;
V_55 = V_38 -> V_61 ;
V_55 [ 0 ] = 0x00 ;
V_55 [ 1 ] = 0x03 ;
V_55 [ 2 ] = 0x02 ;
V_55 [ 3 ] = 0x08 ;
V_55 [ 4 ] = 0x40 ;
F_57 ( V_38 ) ;
}
static int F_58 ( struct V_84 * V_58 , int V_63 )
{
struct V_10 * V_11 = F_45 ( V_58 ) ;
struct V_32 * V_33 = V_11 -> V_64 + V_63 ;
unsigned long V_2 ;
T_3 V_15 ;
int V_27 = 0 ;
F_16 ( V_63 < 0 || V_63 >= V_76 ) ;
if ( ! V_33 -> V_41 )
return - V_94 ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_59 ( & V_33 -> V_43 ) ;
V_33 -> V_41 = false ;
if ( V_63 == V_11 -> V_99 )
V_11 -> V_99 = - 1 ;
F_4 ( & V_3 , V_2 ) ;
if ( V_15 != V_29 ) {
F_10 ( L_23 , V_33 -> V_95 ) ;
V_27 = - V_53 ;
}
F_43 ( & V_33 -> V_54 ) ;
F_43 ( & V_33 -> V_37 ) ;
return V_27 ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_100 * V_101 ;
int V_27 , V_102 ;
struct V_103 * V_104 ;
V_11 = F_61 ( & V_9 -> V_11 , sizeof( * V_11 ) , V_105 ) ;
if ( ! V_11 )
return - V_106 ;
V_11 -> V_99 = - 1 ;
F_62 ( V_9 , V_11 ) ;
#if F_40 ( V_79 )
V_82 = V_11 ;
#else
V_101 = F_63 ( V_9 , V_107 , 0 ) ;
V_11 -> V_28 = F_64 ( & V_9 -> V_11 , V_101 ) ;
if ( F_65 ( V_11 -> V_28 ) )
return F_66 ( V_11 -> V_28 ) ;
V_27 = F_67 ( V_9 , 0 ) ;
if ( V_27 < 0 ) {
F_68 ( & V_9 -> V_11 , L_24 ) ;
return - V_31 ;
}
V_11 -> V_108 = V_27 ;
V_27 = F_69 ( & V_9 -> V_11 , V_11 -> V_108 , F_38 , 0 ,
L_25 , V_11 ) ;
if ( V_27 ) {
F_68 ( & V_9 -> V_11 , L_26 ,
V_11 -> V_108 , V_27 ) ;
return V_27 ;
}
#endif
F_70 ( & V_11 -> V_56 ) ;
V_11 -> V_57 = 0 ;
V_11 -> V_109 = F_71 ( & F_23 , ( void * ) V_11 ,
L_27 ) ;
if ( F_65 ( V_11 -> V_109 ) )
return F_66 ( V_11 -> V_109 ) ;
for ( V_102 = 0 ; V_102 < V_76 ; V_102 ++ ) {
struct V_110 * V_111 = V_11 -> V_112 + V_102 ;
struct V_32 * V_33 = V_11 -> V_64 + V_102 ;
F_72 ( & V_33 -> V_37 ) ;
F_72 ( & V_33 -> V_54 ) ;
V_33 -> V_41 = false ;
snprintf ( V_33 -> V_95 , sizeof( V_33 -> V_95 ) , L_28 , V_102 * 2 + 2 ) ;
V_111 -> V_113 = V_33 -> V_95 ;
V_111 -> V_68 = V_69 | V_88 ;
V_111 -> V_66 = V_70 | V_67 |
V_97 | V_98 ;
V_111 -> V_114 = V_115 ;
V_111 -> V_116 = V_117 ;
V_111 -> V_118 = V_119 ;
V_111 -> V_120 = V_121 ;
}
{
const char * V_122 ;
if ( sizeof( V_101 -> V_123 ) == sizeof( long long ) )
V_122 = L_29 ;
else if ( sizeof( V_101 -> V_123 ) == sizeof( long ) )
V_122 = L_30 ;
else
V_122 = L_31 ;
snprintf ( V_11 -> V_95 , sizeof( V_11 -> V_95 ) , V_122 , V_101 -> V_123 ) ;
}
V_11 -> V_58 . V_124 = V_125 ;
V_11 -> V_58 . V_126 = V_11 -> V_95 ;
V_11 -> V_58 . V_127 = V_76 ;
V_11 -> V_58 . V_128 = V_11 -> V_112 ;
V_11 -> V_58 . V_129 = F_44 ;
V_11 -> V_58 . F_54 = F_54 ;
V_11 -> V_58 . F_58 = F_58 ;
V_11 -> V_58 . F_55 = F_55 ;
V_104 = F_73 ( & V_11 -> V_58 ) ;
if ( F_65 ( V_104 ) ) {
V_27 = F_66 ( V_104 ) ;
F_68 ( & V_9 -> V_11 , L_32 ) ;
goto V_130;
}
V_27 = F_74 ( & V_11 -> V_131 , V_104 ) ;
if ( V_27 )
goto V_132;
V_27 = F_11 ( V_9 ) ;
if ( V_27 ) {
F_68 ( & V_9 -> V_11 , L_33 ) ;
goto V_133;
}
return 0 ;
V_133:
F_75 ( & V_11 -> V_131 ) ;
V_132:
F_76 ( & V_11 -> V_58 ) ;
V_130:
F_77 ( V_11 -> V_109 ) ;
return V_27 ;
}
static int F_78 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_12 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_11 . V_14 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_79 () ;
F_4 ( & V_3 , V_2 ) ;
if ( V_13 && V_13 -> V_30 )
V_13 -> V_30 ( V_13 ) ;
F_75 ( & V_11 -> V_131 ) ;
F_76 ( & V_11 -> V_58 ) ;
F_77 ( V_11 -> V_109 ) ;
V_9 -> V_134 = NULL ;
return 0 ;
}
