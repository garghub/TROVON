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
F_13 ( L_12 , V_29 ) ;
V_15 = F_14 ( V_11 -> V_28 , V_11 -> V_16 , V_29 ) ;
if ( V_15 != V_30 ) {
F_10 ( L_13 , V_15 ) ;
if ( V_13 && V_13 -> V_31 )
V_13 -> V_31 ( V_13 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_15 ( struct V_33 * V_34 )
{
T_4 V_35 ;
struct V_36 * V_37 = & V_34 -> V_38 ;
struct V_39 * V_39 ;
unsigned long V_2 ;
struct V_40 V_41 ;
F_16 ( ! V_34 ) ;
F_16 ( ! V_34 -> V_42 ) ;
F_2 ( & V_3 , V_2 ) ;
if ( F_17 ( V_37 ) ) {
F_4 ( & V_3 , V_2 ) ;
return - V_43 ;
}
if ( ! F_18 ( & V_34 -> V_44 , & V_41 ) -> V_45 ) {
F_4 ( & V_3 , V_2 ) ;
return - V_43 ;
}
V_39 = F_19 ( V_37 , struct V_39 , V_46 ) ;
V_35 = V_39 -> V_47 ;
if ( F_20 ( & V_34 -> V_44 ) < V_35 ) {
F_4 ( & V_3 , V_2 ) ;
return - V_43 ;
}
F_16 ( V_39 -> V_48 == 0 ) ;
if ( ! F_21 ( & V_34 -> V_44 , V_39 -> V_48 , V_35 ) ) {
F_22 ( V_37 -> V_49 ) ;
F_4 ( & V_3 , V_2 ) ;
V_39 -> V_50 = 0 ;
V_39 -> V_51 = V_52 ;
V_39 -> V_53 ( V_39 ) ;
return - V_54 ;
}
F_23 ( V_37 -> V_49 , & V_34 -> V_55 ) ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
static int F_24 ( void * V_56 )
{
struct V_10 * V_11 = V_56 ;
while ( ! F_25 () ) {
F_26 ( V_11 -> V_57 ,
V_11 -> V_58 ||
F_25 () ) ;
if ( V_11 -> V_58 ) {
V_11 -> V_58 -- ;
F_27 ( & V_11 -> V_59 , V_11 -> V_60 ,
V_11 -> V_61 ) ;
}
}
return 0 ;
}
static void F_28 ( struct V_10 * V_11 , struct V_39 * V_39 )
{
T_3 * V_56 = V_39 -> V_62 ;
T_3 * V_63 = V_11 -> V_61 ;
F_13 ( L_14 , ( T_4 ) V_56 [ 16 ] << 8 | V_56 [ 17 ] ) ;
V_11 -> V_60 = V_56 [ 18 ] ;
F_13 ( L_15 , V_11 -> V_60 ) ;
memcpy ( V_63 , V_56 + 19 , 6 ) ;
F_13 ( L_16 ,
V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] , V_63 [ 3 ] , V_63 [ 4 ] , V_63 [ 5 ] ) ;
V_11 -> V_58 ++ ;
F_29 ( & V_11 -> V_57 ) ;
}
static void F_30 ( struct V_10 * V_11 , int V_64 )
{
struct V_33 * V_34 = V_11 -> V_65 + V_64 ;
struct V_40 V_41 ;
struct V_36 * V_37 ;
struct V_39 * V_39 ;
int V_66 ;
unsigned long V_2 ;
T_3 * V_56 ;
F_16 ( ! V_34 ) ;
F_16 ( ! V_34 -> V_42 ) ;
F_2 ( & V_3 , V_2 ) ;
V_66 = F_18 ( & V_34 -> V_44 , & V_41 ) -> V_66 ;
if ( ! V_66 ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
if ( ! F_31 ( & V_34 -> V_44 , V_66 ) ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
F_4 ( & V_3 , V_2 ) ;
V_37 = & V_34 -> V_55 ;
while ( V_66 ) {
F_2 ( & V_3 , V_2 ) ;
if ( F_17 ( V_37 ) ) {
F_4 ( & V_3 , V_2 ) ;
F_32 ( L_17 ) ;
break;
}
V_39 = F_19 ( V_37 , struct V_39 , V_46 ) ;
F_22 ( V_37 -> V_49 ) ;
F_4 ( & V_3 , V_2 ) ;
V_56 = V_39 -> V_62 ;
if ( V_34 -> V_67 == V_68 &&
V_34 -> V_69 == V_70 &&
F_33 ( V_56 ) ) {
F_28 ( V_11 , V_39 ) ;
F_2 ( & V_3 , V_2 ) ;
F_34 ( & V_39 -> V_46 , & V_34 -> V_38 ) ;
F_4 ( & V_3 , V_2 ) ;
} else {
if ( V_34 -> V_67 == V_71 ||
V_34 -> V_67 == V_68 ) {
T_1 const V_72 =
( T_1 ) V_56 [ 0 ] * 256 + V_56 [ 1 ] + 2 ;
V_39 -> V_50 =
F_35 ( T_1 , V_72 ,
V_39 -> V_47 ) ;
} else {
V_39 -> V_50 = V_39 -> V_47 ;
}
V_39 -> V_51 = V_73 ;
V_39 -> V_53 ( V_39 ) ;
}
V_66 -- ;
}
}
static struct V_74 * * F_36 ( struct V_10 * V_11 ,
struct V_74 * * V_75 )
{
int V_76 = 0 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_77 ; V_64 ++ ) {
if ( V_11 -> V_65 [ V_64 ] . V_42 )
V_75 [ V_76 ++ ] = & V_11 -> V_65 [ V_64 ] . V_44 ;
}
V_75 [ V_76 ++ ] = NULL ;
return V_75 ;
}
static T_5 F_37 ( int V_78 , void * V_79 )
{
struct V_10 * V_11 = V_79 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_38 () ;
F_4 ( & V_3 , V_2 ) ;
if ( V_11 -> V_80 >= 0 && V_11 -> V_65 [ V_11 -> V_80 ] . V_42 )
while ( ! F_15 ( V_11 -> V_65 + V_11 -> V_80 ) )
continue;
return V_81 ;
}
static void F_39 ( unsigned long V_56 )
{
struct V_10 * V_11 = (struct V_10 * ) V_56 ;
unsigned long V_2 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_77 ; V_64 ++ ) {
if ( ! V_11 -> V_65 [ V_64 ] . V_42 )
continue;
F_2 ( & V_3 , V_2 ) ;
F_40 ( & V_11 -> V_65 [ V_64 ] . V_44 ) ;
F_4 ( & V_3 , V_2 ) ;
F_30 ( V_11 , V_64 ) ;
while ( ! F_15 ( V_11 -> V_65 + V_64 ) )
continue;
}
}
static T_5 F_41 ( int V_78 , void * V_79 )
{
struct V_10 * V_11 = V_79 ;
struct V_74 * V_75 [ V_77 + 1 ] ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_42 ( F_36 ( V_11 , V_75 ) ) ;
F_4 ( & V_3 , V_2 ) ;
V_82 . V_56 = ( unsigned long ) V_11 ;
F_43 ( & V_82 ) ;
return V_81 ;
}
static void F_44 ( struct V_36 * V_37 )
{
unsigned long V_2 ;
struct V_39 * V_39 ;
for (; ; ) {
F_2 ( & V_3 , V_2 ) ;
if ( F_17 ( V_37 ) ) {
F_4 ( & V_3 , V_2 ) ;
break;
}
V_39 = F_19 ( V_37 , struct V_39 , V_46 ) ;
F_22 ( V_37 -> V_49 ) ;
F_4 ( & V_3 , V_2 ) ;
V_39 -> V_50 = 0 ;
V_39 -> V_51 = V_83 ;
V_39 -> V_53 ( V_39 ) ;
}
}
static int F_45 ( struct V_84 * V_59 , int V_64 ,
struct V_85 * V_86 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
bool const V_87 = V_86 -> V_69 == V_88 ;
T_4 const V_89 = V_86 -> V_90 ;
T_4 const V_35 = V_86 -> V_91 ;
T_4 V_92 ;
unsigned long V_2 ;
T_3 V_15 ;
int const V_93 = V_64 * 2 + 2 ;
struct V_33 * const V_34 = V_11 -> V_65 + V_64 ;
F_16 ( V_64 < 0 || V_64 >= V_77 ) ;
if ( V_34 -> V_42 )
return - V_94 ;
switch ( V_86 -> V_67 ) {
case V_71 :
V_92 = F_47 ( V_35 ) ;
if ( V_92 == 0 ) {
F_10 ( L_18 , V_34 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_35 )
F_48 ( L_19 ,
V_34 -> V_95 , V_35 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_49 ( & V_34 -> V_44 , V_87 , V_93 ,
V_87 ? V_92 * 2 : V_92 ) ;
break;
case V_68 :
V_92 = F_47 ( V_35 ) ;
if ( V_92 == 0 ) {
F_10 ( L_18 , V_34 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_35 )
F_48 ( L_19 ,
V_34 -> V_95 , V_35 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_50 ( & V_34 -> V_44 , V_87 , V_93 ,
V_87 ? V_92 * 2 : V_92 ) ;
break;
case V_97 :
V_92 = F_51 ( V_35 , V_89 ) ;
if ( V_92 == 0 ) {
F_10 ( L_20 ,
V_34 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_35 )
F_48 ( L_19 ,
V_34 -> V_95 , V_35 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_52 ( & V_34 -> V_44 , V_87 , V_93 , V_89 ) ;
break;
case V_98 :
V_92 = F_53 ( V_35 , V_89 ) ;
if ( V_92 == 0 ) {
F_10 ( L_20 ,
V_34 -> V_95 ) ;
return - V_96 ;
}
V_86 -> V_91 = V_92 ;
if ( V_92 != V_35 )
F_48 ( L_19 ,
V_34 -> V_95 , V_35 , V_92 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_54 ( & V_34 -> V_44 , V_87 , V_93 , V_89 ) ;
break;
default:
F_10 ( L_21 ,
V_34 -> V_95 , V_86 -> V_67 ) ;
return - V_96 ;
}
if ( V_15 != V_30 ) {
F_4 ( & V_3 , V_2 ) ;
F_10 ( L_22 ,
V_34 -> V_95 , V_15 , V_86 -> V_67 , ( int ) V_87 ) ;
return - V_32 ;
}
V_34 -> V_67 = V_86 -> V_67 ;
V_34 -> V_69 = V_86 -> V_69 ;
V_34 -> V_42 = true ;
if ( V_34 -> V_67 == V_68 &&
V_34 -> V_69 == V_88 &&
V_11 -> V_80 < 0 )
V_11 -> V_80 = V_64 ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_84 * V_59 , int V_64 ,
struct V_39 * V_39 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
struct V_33 * V_34 = V_11 -> V_65 + V_64 ;
unsigned long V_2 ;
F_16 ( V_64 < 0 || V_64 >= V_77 ) ;
if ( ! V_34 -> V_42 )
return - V_94 ;
if ( V_39 -> V_48 == 0 )
return - V_54 ;
F_2 ( & V_3 , V_2 ) ;
F_34 ( & V_39 -> V_46 , & V_34 -> V_38 ) ;
F_4 ( & V_3 , V_2 ) ;
( void ) F_15 ( V_34 ) ;
return 0 ;
}
static void F_56 ( struct V_84 * V_59 , int V_64 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
struct V_39 * V_39 ;
T_3 * V_56 ;
if ( V_11 -> V_80 < 0 ) {
F_10 ( L_23 ) ;
return;
}
V_39 = F_57 ( & V_11 -> V_59 , V_11 -> V_80 , NULL ) ;
if ( ! V_39 )
return;
V_39 -> V_47 = 5 ;
V_56 = V_39 -> V_62 ;
V_56 [ 0 ] = 0x00 ;
V_56 [ 1 ] = 0x03 ;
V_56 [ 2 ] = 0x02 ;
V_56 [ 3 ] = 0x08 ;
V_56 [ 4 ] = 0x40 ;
F_58 ( V_39 ) ;
}
static int F_59 ( struct V_84 * V_59 , int V_64 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
struct V_33 * V_34 = V_11 -> V_65 + V_64 ;
unsigned long V_2 ;
T_3 V_15 ;
int V_27 = 0 ;
F_16 ( V_64 < 0 || V_64 >= V_77 ) ;
if ( ! V_34 -> V_42 )
return - V_94 ;
F_60 ( & V_82 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_61 ( & V_34 -> V_44 ) ;
V_34 -> V_42 = false ;
if ( V_64 == V_11 -> V_80 )
V_11 -> V_80 = - 1 ;
F_4 ( & V_3 , V_2 ) ;
F_62 ( & V_82 ) ;
if ( V_15 != V_30 ) {
F_10 ( L_24 , V_34 -> V_95 ) ;
V_27 = - V_54 ;
}
F_44 ( & V_34 -> V_55 ) ;
F_44 ( & V_34 -> V_38 ) ;
return V_27 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_99 * V_100 ;
int V_27 , V_101 ;
struct V_102 * V_103 ;
int V_78 ;
V_11 = F_64 ( & V_9 -> V_11 , sizeof( * V_11 ) , V_104 ) ;
if ( ! V_11 )
return - V_105 ;
V_11 -> V_80 = - 1 ;
F_65 ( V_9 , V_11 ) ;
V_100 = F_66 ( V_9 , V_106 , 0 ) ;
V_11 -> V_28 = F_67 ( & V_9 -> V_11 , V_100 ) ;
if ( F_68 ( V_11 -> V_28 ) )
return F_69 ( V_11 -> V_28 ) ;
V_78 = F_70 ( V_9 , 0 ) ;
if ( V_78 < 0 ) {
F_71 ( & V_9 -> V_11 , L_25 ) ;
return - V_32 ;
}
V_27 = F_72 ( & V_9 -> V_11 , V_78 , F_41 , 0 ,
L_26 , V_11 ) ;
if ( V_27 ) {
F_71 ( & V_9 -> V_11 , L_27 , V_78 ) ;
return V_27 ;
}
V_78 = F_70 ( V_9 , 1 ) ;
if ( V_78 < 0 ) {
F_71 ( & V_9 -> V_11 , L_28 ) ;
return - V_32 ;
}
V_27 = F_72 ( & V_9 -> V_11 , V_78 , F_37 , 0 ,
L_29 , V_11 ) ;
if ( V_27 ) {
F_71 ( & V_9 -> V_11 , L_30 , V_78 ) ;
return V_27 ;
}
F_73 ( & V_11 -> V_57 ) ;
V_11 -> V_58 = 0 ;
V_11 -> V_107 = F_74 ( & F_24 , ( void * ) V_11 ,
L_31 ) ;
if ( F_68 ( V_11 -> V_107 ) )
return F_69 ( V_11 -> V_107 ) ;
for ( V_101 = 0 ; V_101 < V_77 ; V_101 ++ ) {
struct V_108 * V_109 = V_11 -> V_110 + V_101 ;
struct V_33 * V_34 = V_11 -> V_65 + V_101 ;
F_75 ( & V_34 -> V_38 ) ;
F_75 ( & V_34 -> V_55 ) ;
V_34 -> V_42 = false ;
snprintf ( V_34 -> V_95 , sizeof( V_34 -> V_95 ) , L_32 , V_101 * 2 + 2 ) ;
V_109 -> V_111 = V_34 -> V_95 ;
V_109 -> V_69 = V_70 | V_88 ;
V_109 -> V_67 = V_71 | V_68 |
V_97 | V_98 ;
V_109 -> V_112 = V_113 ;
V_109 -> V_114 = V_115 ;
V_109 -> V_116 = V_117 ;
V_109 -> V_118 = V_119 ;
}
{
const char * V_120 ;
if ( sizeof( V_100 -> V_121 ) == sizeof( long long ) )
V_120 = L_33 ;
else if ( sizeof( V_100 -> V_121 ) == sizeof( long ) )
V_120 = L_34 ;
else
V_120 = L_35 ;
snprintf ( V_11 -> V_95 , sizeof( V_11 -> V_95 ) , V_120 , V_100 -> V_121 ) ;
}
V_11 -> V_59 . V_122 = V_123 ;
V_11 -> V_59 . V_124 = V_11 -> V_95 ;
V_11 -> V_59 . V_125 = V_77 ;
V_11 -> V_59 . V_126 = V_11 -> V_110 ;
V_11 -> V_59 . V_127 = F_45 ;
V_11 -> V_59 . F_55 = F_55 ;
V_11 -> V_59 . F_59 = F_59 ;
V_11 -> V_59 . F_56 = F_56 ;
V_103 = F_76 ( & V_11 -> V_59 ) ;
if ( F_68 ( V_103 ) ) {
V_27 = F_69 ( V_103 ) ;
F_71 ( & V_9 -> V_11 , L_36 ) ;
goto V_128;
}
V_27 = F_77 ( & V_11 -> V_129 , V_103 ) ;
if ( V_27 )
goto V_130;
V_27 = F_11 ( V_9 ) ;
if ( V_27 ) {
F_71 ( & V_9 -> V_11 , L_37 ) ;
goto V_131;
}
return 0 ;
V_131:
F_78 ( & V_11 -> V_129 ) ;
V_130:
F_79 ( & V_11 -> V_59 ) ;
V_128:
F_80 ( V_11 -> V_107 ) ;
return V_27 ;
}
static int F_81 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_12 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_11 . V_14 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_82 () ;
F_4 ( & V_3 , V_2 ) ;
if ( V_13 && V_13 -> V_31 )
V_13 -> V_31 ( V_13 ) ;
F_78 ( & V_11 -> V_129 ) ;
F_79 ( & V_11 -> V_59 ) ;
F_80 ( V_11 -> V_107 ) ;
V_9 -> V_132 = NULL ;
return 0 ;
}
