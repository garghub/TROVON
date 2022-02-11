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
F_13 ( L_14 , ( T_4 ) V_56 [ 16 ] << 8 | V_56 [ 17 ] ) ;
V_11 -> V_60 = V_56 [ 18 ] ;
F_13 ( L_15 , V_11 -> V_60 ) ;
memcpy ( V_11 -> V_61 , V_56 + 19 , 6 ) ;
V_11 -> V_58 ++ ;
F_29 ( & V_11 -> V_57 ) ;
}
static void F_30 ( struct V_10 * V_11 , int V_63 )
{
struct V_33 * V_34 = V_11 -> V_64 + V_63 ;
struct V_40 V_41 ;
struct V_36 * V_37 ;
struct V_39 * V_39 ;
int V_65 ;
unsigned long V_2 ;
T_3 * V_56 ;
F_16 ( ! V_34 ) ;
F_16 ( ! V_34 -> V_42 ) ;
F_2 ( & V_3 , V_2 ) ;
V_65 = F_18 ( & V_34 -> V_44 , & V_41 ) -> V_65 ;
if ( ! V_65 ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
if ( ! F_31 ( & V_34 -> V_44 , V_65 ) ) {
F_4 ( & V_3 , V_2 ) ;
return;
}
F_4 ( & V_3 , V_2 ) ;
V_37 = & V_34 -> V_55 ;
while ( V_65 ) {
F_2 ( & V_3 , V_2 ) ;
if ( F_17 ( V_37 ) ) {
F_4 ( & V_3 , V_2 ) ;
F_32 ( L_16 ) ;
break;
}
V_39 = F_19 ( V_37 , struct V_39 , V_46 ) ;
F_22 ( V_37 -> V_49 ) ;
F_4 ( & V_3 , V_2 ) ;
V_56 = V_39 -> V_62 ;
if ( V_34 -> V_66 == V_67 &&
V_34 -> V_68 == V_69 &&
F_33 ( V_56 ) ) {
F_28 ( V_11 , V_39 ) ;
F_2 ( & V_3 , V_2 ) ;
F_34 ( & V_39 -> V_46 , & V_34 -> V_38 ) ;
F_4 ( & V_3 , V_2 ) ;
} else {
if ( V_34 -> V_66 == V_70 ||
V_34 -> V_66 == V_67 ) {
T_1 const V_71 =
( T_1 ) V_56 [ 0 ] * 256 + V_56 [ 1 ] + 2 ;
V_39 -> V_50 =
F_35 ( T_1 , V_71 ,
V_39 -> V_47 ) ;
} else {
V_39 -> V_50 = V_39 -> V_47 ;
}
V_39 -> V_51 = V_72 ;
V_39 -> V_53 ( V_39 ) ;
}
V_65 -- ;
}
}
static struct V_73 * * F_36 ( struct V_10 * V_11 ,
struct V_73 * * V_74 )
{
int V_75 = 0 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_76 ; V_63 ++ ) {
if ( V_11 -> V_64 [ V_63 ] . V_42 )
V_74 [ V_75 ++ ] = & V_11 -> V_64 [ V_63 ] . V_44 ;
}
V_74 [ V_75 ++ ] = NULL ;
return V_74 ;
}
static T_5 F_37 ( int V_77 , void * V_78 )
{
struct V_10 * V_11 = V_78 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_38 () ;
F_4 ( & V_3 , V_2 ) ;
if ( V_11 -> V_79 >= 0 && V_11 -> V_64 [ V_11 -> V_79 ] . V_42 )
while ( ! F_15 ( V_11 -> V_64 + V_11 -> V_79 ) )
continue;
return V_80 ;
}
static void F_39 ( unsigned long V_56 )
{
struct V_10 * V_11 = (struct V_10 * ) V_56 ;
unsigned long V_2 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_76 ; V_63 ++ ) {
if ( ! V_11 -> V_64 [ V_63 ] . V_42 )
continue;
F_2 ( & V_3 , V_2 ) ;
F_40 ( & V_11 -> V_64 [ V_63 ] . V_44 ) ;
F_4 ( & V_3 , V_2 ) ;
F_30 ( V_11 , V_63 ) ;
while ( ! F_15 ( V_11 -> V_64 + V_63 ) )
continue;
}
}
static T_5 F_41 ( int V_77 , void * V_78 )
{
struct V_10 * V_11 = V_78 ;
struct V_73 * V_74 [ V_76 + 1 ] ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_42 ( F_36 ( V_11 , V_74 ) ) ;
F_4 ( & V_3 , V_2 ) ;
V_81 . V_56 = ( unsigned long ) V_11 ;
F_43 ( & V_81 ) ;
return V_80 ;
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
V_39 -> V_51 = V_82 ;
V_39 -> V_53 ( V_39 ) ;
}
}
static int F_45 ( struct V_83 * V_59 , int V_63 ,
struct V_84 * V_85 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
bool const V_86 = V_85 -> V_68 == V_87 ;
T_4 const V_88 = V_85 -> V_89 ;
T_4 const V_35 = V_85 -> V_90 ;
T_4 V_91 ;
unsigned long V_2 ;
T_3 V_15 ;
int const V_92 = V_63 * 2 + 2 ;
struct V_33 * const V_34 = V_11 -> V_64 + V_63 ;
F_16 ( V_63 < 0 || V_63 >= V_76 ) ;
if ( V_34 -> V_42 )
return - V_93 ;
switch ( V_85 -> V_66 ) {
case V_70 :
V_91 = F_47 ( V_35 ) ;
if ( V_91 == 0 ) {
F_10 ( L_17 , V_34 -> V_94 ) ;
return - V_95 ;
}
V_85 -> V_90 = V_91 ;
if ( V_91 != V_35 )
F_48 ( L_18 ,
V_34 -> V_94 , V_35 , V_91 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_49 ( & V_34 -> V_44 , V_86 , V_92 ,
V_86 ? V_91 * 2 : V_91 ) ;
break;
case V_67 :
V_91 = F_47 ( V_35 ) ;
if ( V_91 == 0 ) {
F_10 ( L_17 , V_34 -> V_94 ) ;
return - V_95 ;
}
V_85 -> V_90 = V_91 ;
if ( V_91 != V_35 )
F_48 ( L_18 ,
V_34 -> V_94 , V_35 , V_91 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_50 ( & V_34 -> V_44 , V_86 , V_92 ,
V_86 ? V_91 * 2 : V_91 ) ;
break;
case V_96 :
V_91 = F_51 ( V_35 , V_88 ) ;
if ( V_91 == 0 ) {
F_10 ( L_19 ,
V_34 -> V_94 ) ;
return - V_95 ;
}
V_85 -> V_90 = V_91 ;
if ( V_91 != V_35 )
F_48 ( L_18 ,
V_34 -> V_94 , V_35 , V_91 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_52 ( & V_34 -> V_44 , V_86 , V_92 , V_88 ) ;
break;
case V_97 :
V_91 = F_53 ( V_35 , V_88 ) ;
if ( V_91 == 0 ) {
F_10 ( L_19 ,
V_34 -> V_94 ) ;
return - V_95 ;
}
V_85 -> V_90 = V_91 ;
if ( V_91 != V_35 )
F_48 ( L_18 ,
V_34 -> V_94 , V_35 , V_91 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_54 ( & V_34 -> V_44 , V_86 , V_92 , V_88 ) ;
break;
default:
F_10 ( L_20 ,
V_34 -> V_94 , V_85 -> V_66 ) ;
return - V_95 ;
}
if ( V_15 != V_30 ) {
F_4 ( & V_3 , V_2 ) ;
F_10 ( L_21 ,
V_34 -> V_94 , V_15 , V_85 -> V_66 , ( int ) V_86 ) ;
return - V_32 ;
}
V_34 -> V_66 = V_85 -> V_66 ;
V_34 -> V_68 = V_85 -> V_68 ;
V_34 -> V_42 = true ;
if ( V_34 -> V_66 == V_67 &&
V_34 -> V_68 == V_87 &&
V_11 -> V_79 < 0 )
V_11 -> V_79 = V_63 ;
F_4 ( & V_3 , V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_83 * V_59 , int V_63 ,
struct V_39 * V_39 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
struct V_33 * V_34 = V_11 -> V_64 + V_63 ;
unsigned long V_2 ;
F_16 ( V_63 < 0 || V_63 >= V_76 ) ;
if ( ! V_34 -> V_42 )
return - V_93 ;
if ( V_39 -> V_48 == 0 )
return - V_54 ;
F_2 ( & V_3 , V_2 ) ;
F_34 ( & V_39 -> V_46 , & V_34 -> V_38 ) ;
F_4 ( & V_3 , V_2 ) ;
( void ) F_15 ( V_34 ) ;
return 0 ;
}
static void F_56 ( struct V_83 * V_59 , int V_63 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
struct V_39 * V_39 ;
T_3 * V_56 ;
if ( V_11 -> V_79 < 0 ) {
F_10 ( L_22 ) ;
return;
}
V_39 = F_57 ( & V_11 -> V_59 , V_11 -> V_79 , NULL ) ;
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
static int F_59 ( struct V_83 * V_59 , int V_63 )
{
struct V_10 * V_11 = F_46 ( V_59 ) ;
struct V_33 * V_34 = V_11 -> V_64 + V_63 ;
unsigned long V_2 ;
T_3 V_15 ;
int V_27 = 0 ;
F_16 ( V_63 < 0 || V_63 >= V_76 ) ;
if ( ! V_34 -> V_42 )
return - V_93 ;
F_60 ( & V_81 ) ;
F_2 ( & V_3 , V_2 ) ;
V_15 = F_61 ( & V_34 -> V_44 ) ;
V_34 -> V_42 = false ;
if ( V_63 == V_11 -> V_79 )
V_11 -> V_79 = - 1 ;
F_4 ( & V_3 , V_2 ) ;
F_62 ( & V_81 ) ;
if ( V_15 != V_30 ) {
F_10 ( L_23 , V_34 -> V_94 ) ;
V_27 = - V_54 ;
}
F_44 ( & V_34 -> V_55 ) ;
F_44 ( & V_34 -> V_38 ) ;
return V_27 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_98 * V_99 ;
int V_27 , V_100 ;
struct V_101 * V_102 ;
int V_77 ;
V_11 = F_64 ( & V_9 -> V_11 , sizeof( * V_11 ) , V_103 ) ;
if ( ! V_11 )
return - V_104 ;
V_11 -> V_79 = - 1 ;
F_65 ( V_9 , V_11 ) ;
V_99 = F_66 ( V_9 , V_105 , 0 ) ;
V_11 -> V_28 = F_67 ( & V_9 -> V_11 , V_99 ) ;
if ( F_68 ( V_11 -> V_28 ) )
return F_69 ( V_11 -> V_28 ) ;
V_77 = F_70 ( V_9 , 0 ) ;
if ( V_77 < 0 ) {
F_71 ( & V_9 -> V_11 , L_24 ) ;
return - V_32 ;
}
V_27 = F_72 ( & V_9 -> V_11 , V_77 , F_41 , 0 ,
L_25 , V_11 ) ;
if ( V_27 ) {
F_71 ( & V_9 -> V_11 , L_26 , V_77 ) ;
return V_27 ;
}
V_77 = F_70 ( V_9 , 1 ) ;
if ( V_77 < 0 ) {
F_71 ( & V_9 -> V_11 , L_27 ) ;
return - V_32 ;
}
V_27 = F_72 ( & V_9 -> V_11 , V_77 , F_37 , 0 ,
L_28 , V_11 ) ;
if ( V_27 ) {
F_71 ( & V_9 -> V_11 , L_29 , V_77 ) ;
return V_27 ;
}
F_73 ( & V_11 -> V_57 ) ;
V_11 -> V_58 = 0 ;
V_11 -> V_106 = F_74 ( & F_24 , ( void * ) V_11 ,
L_30 ) ;
if ( F_68 ( V_11 -> V_106 ) )
return F_69 ( V_11 -> V_106 ) ;
for ( V_100 = 0 ; V_100 < V_76 ; V_100 ++ ) {
struct V_107 * V_108 = V_11 -> V_109 + V_100 ;
struct V_33 * V_34 = V_11 -> V_64 + V_100 ;
F_75 ( & V_34 -> V_38 ) ;
F_75 ( & V_34 -> V_55 ) ;
V_34 -> V_42 = false ;
snprintf ( V_34 -> V_94 , sizeof( V_34 -> V_94 ) , L_31 , V_100 * 2 + 2 ) ;
V_108 -> V_110 = V_34 -> V_94 ;
V_108 -> V_68 = V_69 | V_87 ;
V_108 -> V_66 = V_70 | V_67 |
V_96 | V_97 ;
V_108 -> V_111 = V_112 ;
V_108 -> V_113 = V_114 ;
V_108 -> V_115 = V_116 ;
V_108 -> V_117 = V_118 ;
}
{
const char * V_119 ;
if ( sizeof( V_99 -> V_120 ) == sizeof( long long ) )
V_119 = L_32 ;
else if ( sizeof( V_99 -> V_120 ) == sizeof( long ) )
V_119 = L_33 ;
else
V_119 = L_34 ;
snprintf ( V_11 -> V_94 , sizeof( V_11 -> V_94 ) , V_119 , V_99 -> V_120 ) ;
}
V_11 -> V_59 . V_121 = V_122 ;
V_11 -> V_59 . V_123 = V_11 -> V_94 ;
V_11 -> V_59 . V_124 = V_76 ;
V_11 -> V_59 . V_125 = V_11 -> V_109 ;
V_11 -> V_59 . V_126 = F_45 ;
V_11 -> V_59 . F_55 = F_55 ;
V_11 -> V_59 . F_59 = F_59 ;
V_11 -> V_59 . F_56 = F_56 ;
V_102 = F_76 ( & V_11 -> V_59 ) ;
if ( F_68 ( V_102 ) ) {
V_27 = F_69 ( V_102 ) ;
F_71 ( & V_9 -> V_11 , L_35 ) ;
goto V_127;
}
V_27 = F_77 ( & V_11 -> V_128 , V_102 ) ;
if ( V_27 )
goto V_129;
V_27 = F_11 ( V_9 ) ;
if ( V_27 ) {
F_71 ( & V_9 -> V_11 , L_36 ) ;
goto V_130;
}
return 0 ;
V_130:
F_78 ( & V_11 -> V_128 ) ;
V_129:
F_79 ( & V_11 -> V_59 ) ;
V_127:
F_80 ( V_11 -> V_106 ) ;
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
F_78 ( & V_11 -> V_128 ) ;
F_79 ( & V_11 -> V_59 ) ;
F_80 ( V_11 -> V_106 ) ;
V_9 -> V_131 = NULL ;
return 0 ;
}
