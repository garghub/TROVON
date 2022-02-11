static int T_1 F_1 ( const char * V_1 ,
const struct V_2 * V_3 )
{
int V_4 , V_5 ;
T_2 V_6 ;
struct V_7 * V_8 ;
char V_9 [ V_10 ] ;
char * V_11 = & V_9 [ 0 ] ;
char * V_12 [ V_13 ] ;
if ( ! V_1 )
return - V_14 ;
V_6 = F_2 ( V_1 , V_10 ) ;
if ( V_6 == 0 ) {
F_3 ( L_1 ) ;
return 0 ;
}
if ( V_6 == V_10 ) {
F_4 ( L_2 ,
V_1 , V_10 ) ;
return - V_14 ;
}
strcpy ( V_9 , V_1 ) ;
if ( V_9 [ V_6 - 1 ] == '\n' )
V_9 [ V_6 - 1 ] = '\0' ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ )
V_12 [ V_4 ] = F_5 ( & V_11 , L_3 ) ;
V_8 = & V_7 [ V_15 ] ;
if ( V_12 [ 1 ] ) {
V_5 = F_6 ( V_12 [ 0 ] , 10 , & V_8 -> V_16 ) ;
if ( V_5 < 0 )
return - V_14 ;
V_5 = F_6 ( V_12 [ 1 ] , 10 , & V_8 -> V_17 ) ;
if ( V_5 < 0 ) {
V_8 -> V_17 = - 1 ;
strcpy ( V_8 -> V_18 , V_12 [ 1 ] ) ;
}
} else {
strcpy ( V_8 -> V_18 , V_12 [ 0 ] ) ;
V_8 -> V_16 = - 1 ;
V_8 -> V_17 = - 1 ;
}
V_15 ++ ;
return 0 ;
}
static struct V_19 * F_7 ( int V_16 , int V_17 )
{
struct V_19 * V_20 ;
F_8 (dev, &ubiblock_devices, list)
if ( V_20 -> V_16 == V_16 && V_20 -> V_17 == V_17 )
return V_20 ;
return NULL ;
}
static int F_9 ( struct V_21 * V_22 )
{
int V_5 , V_23 , V_24 , V_25 , V_26 ;
T_3 V_27 ;
struct V_28 * V_29 = F_10 ( V_22 ) ;
struct V_19 * V_20 = V_29 -> V_30 -> V_31 ;
V_26 = F_11 ( V_29 ) ;
V_27 = F_12 ( V_29 ) << 9 ;
V_24 = F_13 ( V_27 , V_20 -> V_32 ) ;
V_23 = V_27 ;
V_25 = V_26 ;
while ( V_25 ) {
if ( V_24 + V_26 > V_20 -> V_32 )
V_26 = V_20 -> V_32 - V_24 ;
V_5 = F_14 ( V_20 -> V_33 , V_23 , & V_22 -> V_34 , V_24 , V_26 ) ;
if ( V_5 < 0 )
return V_5 ;
V_25 -= V_26 ;
V_26 = V_25 ;
V_23 += 1 ;
V_24 = 0 ;
}
return 0 ;
}
static int F_15 ( struct V_35 * V_36 , T_4 V_37 )
{
struct V_19 * V_20 = V_36 -> V_38 -> V_39 ;
int V_5 ;
F_16 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_41 > 0 ) {
goto V_42;
}
if ( V_37 & V_43 ) {
V_5 = - V_44 ;
goto V_45;
}
V_20 -> V_33 = F_17 ( V_20 -> V_16 , V_20 -> V_17 , V_46 ) ;
if ( F_18 ( V_20 -> V_33 ) ) {
F_19 ( F_20 ( V_20 -> V_47 ) , L_4 ,
V_20 -> V_16 , V_20 -> V_17 ) ;
V_5 = F_21 ( V_20 -> V_33 ) ;
V_20 -> V_33 = NULL ;
goto V_45;
}
V_42:
V_20 -> V_41 ++ ;
F_22 ( & V_20 -> V_40 ) ;
return 0 ;
V_45:
F_22 ( & V_20 -> V_40 ) ;
return V_5 ;
}
static void F_23 ( struct V_48 * V_47 , T_4 V_37 )
{
struct V_19 * V_20 = V_47 -> V_39 ;
F_16 ( & V_20 -> V_40 ) ;
V_20 -> V_41 -- ;
if ( V_20 -> V_41 == 0 ) {
F_24 ( V_20 -> V_33 ) ;
V_20 -> V_33 = NULL ;
}
F_22 ( & V_20 -> V_40 ) ;
}
static int F_25 ( struct V_35 * V_36 , struct V_49 * V_50 )
{
V_50 -> V_51 = 1 ;
V_50 -> V_52 = 1 ;
V_50 -> V_53 = F_26 ( V_36 -> V_38 ) ;
V_50 -> V_54 = 0 ;
return 0 ;
}
static void F_27 ( struct V_55 * V_56 )
{
int V_5 ;
struct V_21 * V_22 = F_28 ( V_56 , struct V_21 , V_56 ) ;
struct V_28 * V_29 = F_10 ( V_22 ) ;
F_29 ( V_29 ) ;
F_30 ( V_29 -> V_30 , V_29 , V_22 -> V_34 . V_57 ) ;
V_5 = F_9 ( V_22 ) ;
F_31 ( V_29 ) ;
F_32 ( V_29 , V_5 ) ;
}
static int F_33 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
struct V_28 * V_29 = V_61 -> V_62 ;
struct V_19 * V_20 = V_59 -> V_63 -> V_31 ;
struct V_21 * V_22 = F_34 ( V_29 ) ;
if ( V_29 -> V_64 != V_65 )
return V_66 ;
if ( F_35 ( V_29 ) != V_67 )
return V_66 ;
F_36 ( & V_22 -> V_34 ) ;
F_37 ( V_20 -> V_68 , & V_22 -> V_56 ) ;
return V_69 ;
}
static int F_38 ( void * V_70 , struct V_28 * V_29 ,
unsigned int V_71 ,
unsigned int V_72 ,
unsigned int V_73 )
{
struct V_21 * V_22 = F_34 ( V_29 ) ;
F_39 ( V_22 -> V_34 . V_57 , V_74 ) ;
F_40 ( & V_22 -> V_56 , F_27 ) ;
return 0 ;
}
int F_41 ( struct V_75 * V_76 )
{
struct V_19 * V_20 ;
struct V_48 * V_47 ;
T_3 V_77 = V_76 -> V_78 >> 9 ;
int V_5 ;
if ( ( V_79 ) V_77 != V_77 )
return - V_80 ;
F_16 ( & V_81 ) ;
if ( F_7 ( V_76 -> V_16 , V_76 -> V_17 ) ) {
F_22 ( & V_81 ) ;
return - V_82 ;
}
F_22 ( & V_81 ) ;
V_20 = F_42 ( sizeof( struct V_19 ) , V_83 ) ;
if ( ! V_20 )
return - V_84 ;
F_43 ( & V_20 -> V_40 ) ;
V_20 -> V_16 = V_76 -> V_16 ;
V_20 -> V_17 = V_76 -> V_17 ;
V_20 -> V_32 = V_76 -> V_85 ;
V_47 = F_44 ( 1 ) ;
if ( ! V_47 ) {
F_4 ( L_5 ) ;
V_5 = - V_86 ;
goto V_87;
}
V_47 -> V_88 = & V_89 ;
V_47 -> V_90 = V_91 ;
V_47 -> V_92 = F_45 ( & V_93 , V_20 , 0 , 0 , V_83 ) ;
if ( V_47 -> V_92 < 0 ) {
F_19 ( F_20 ( V_47 ) ,
L_6 ) ;
V_5 = - V_86 ;
goto V_94;
}
V_47 -> V_39 = V_20 ;
sprintf ( V_47 -> V_95 , L_7 , V_20 -> V_16 , V_20 -> V_17 ) ;
F_46 ( V_47 , V_77 ) ;
V_20 -> V_47 = V_47 ;
V_20 -> V_96 . V_97 = & V_98 ;
V_20 -> V_96 . V_99 = 64 ;
V_20 -> V_96 . V_73 = V_100 ;
V_20 -> V_96 . V_101 = V_102 ;
V_20 -> V_96 . V_103 = sizeof( struct V_21 ) ;
V_20 -> V_96 . V_104 = V_20 ;
V_20 -> V_96 . V_105 = 1 ;
V_5 = F_47 ( & V_20 -> V_96 ) ;
if ( V_5 ) {
F_19 ( F_20 ( V_20 -> V_47 ) , L_8 ) ;
goto V_106;
}
V_20 -> V_62 = F_48 ( & V_20 -> V_96 ) ;
if ( F_18 ( V_20 -> V_62 ) ) {
F_19 ( F_20 ( V_47 ) , L_9 ) ;
V_5 = F_21 ( V_20 -> V_62 ) ;
goto V_107;
}
F_49 ( V_20 -> V_62 , V_74 ) ;
V_20 -> V_62 -> V_31 = V_20 ;
V_20 -> V_47 -> V_63 = V_20 -> V_62 ;
V_20 -> V_68 = F_50 ( L_10 , 0 , 0 , V_47 -> V_95 ) ;
if ( ! V_20 -> V_68 ) {
V_5 = - V_84 ;
goto V_108;
}
F_16 ( & V_81 ) ;
F_51 ( & V_20 -> V_109 , & V_110 ) ;
F_22 ( & V_81 ) ;
F_52 ( V_20 -> V_47 ) ;
F_53 ( F_20 ( V_20 -> V_47 ) , L_11 ,
V_20 -> V_16 , V_20 -> V_17 , V_76 -> V_18 ) ;
return 0 ;
V_108:
F_54 ( V_20 -> V_62 ) ;
V_107:
F_55 ( & V_20 -> V_96 ) ;
V_106:
F_56 ( & V_93 , V_47 -> V_92 ) ;
V_94:
F_57 ( V_20 -> V_47 ) ;
V_87:
F_58 ( V_20 ) ;
return V_5 ;
}
static void F_59 ( struct V_19 * V_20 )
{
F_60 ( V_20 -> V_47 ) ;
F_61 ( V_20 -> V_68 ) ;
F_54 ( V_20 -> V_62 ) ;
F_55 ( & V_20 -> V_96 ) ;
F_53 ( F_20 ( V_20 -> V_47 ) , L_12 ) ;
F_56 ( & V_93 , V_20 -> V_47 -> V_92 ) ;
F_57 ( V_20 -> V_47 ) ;
}
int F_62 ( struct V_75 * V_76 )
{
struct V_19 * V_20 ;
F_16 ( & V_81 ) ;
V_20 = F_7 ( V_76 -> V_16 , V_76 -> V_17 ) ;
if ( ! V_20 ) {
F_22 ( & V_81 ) ;
return - V_86 ;
}
F_16 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_41 > 0 ) {
F_22 ( & V_20 -> V_40 ) ;
F_22 ( & V_81 ) ;
return - V_111 ;
}
F_63 ( & V_20 -> V_109 ) ;
F_22 ( & V_81 ) ;
F_59 ( V_20 ) ;
F_22 ( & V_20 -> V_40 ) ;
F_58 ( V_20 ) ;
return 0 ;
}
static int F_64 ( struct V_75 * V_76 )
{
struct V_19 * V_20 ;
T_3 V_77 = V_76 -> V_78 >> 9 ;
F_16 ( & V_81 ) ;
V_20 = F_7 ( V_76 -> V_16 , V_76 -> V_17 ) ;
if ( ! V_20 ) {
F_22 ( & V_81 ) ;
return - V_86 ;
}
if ( ( V_79 ) V_77 != V_77 ) {
F_22 ( & V_81 ) ;
F_65 ( F_20 ( V_20 -> V_47 ) , L_13 ,
V_76 -> V_112 ) ;
return - V_80 ;
}
F_16 ( & V_20 -> V_40 ) ;
if ( F_26 ( V_20 -> V_47 ) != V_77 ) {
F_46 ( V_20 -> V_47 , V_77 ) ;
F_53 ( F_20 ( V_20 -> V_47 ) , L_14 ,
V_76 -> V_78 ) ;
}
F_22 ( & V_20 -> V_40 ) ;
F_22 ( & V_81 ) ;
return 0 ;
}
static int F_66 ( struct V_113 * V_114 ,
unsigned long V_115 , void * V_116 )
{
struct V_117 * V_118 = V_116 ;
switch ( V_115 ) {
case V_119 :
break;
case V_120 :
F_62 ( & V_118 -> V_76 ) ;
break;
case V_121 :
F_64 ( & V_118 -> V_76 ) ;
break;
case V_122 :
if ( V_118 -> V_76 . V_123 == V_124 )
F_64 ( & V_118 -> V_76 ) ;
break;
default:
break;
}
return V_125 ;
}
static struct V_126 * T_1
F_67 ( const char * V_18 , int V_16 , int V_17 )
{
if ( V_16 == - 1 )
return F_68 ( V_18 , V_46 ) ;
else if ( V_17 == - 1 )
return F_69 ( V_16 , V_18 , V_46 ) ;
else
return F_17 ( V_16 , V_17 , V_46 ) ;
}
static void T_1 F_70 ( void )
{
int V_4 , V_5 = 0 ;
struct V_7 * V_127 ;
struct V_126 * V_33 ;
struct V_75 V_76 ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
V_127 = & V_7 [ V_4 ] ;
V_33 = F_67 ( V_127 -> V_18 , V_127 -> V_16 , V_127 -> V_17 ) ;
if ( F_18 ( V_33 ) ) {
F_4 (
L_15 ,
V_127 -> V_16 , V_127 -> V_17 , F_21 ( V_33 ) ) ;
continue;
}
F_71 ( V_33 , & V_76 ) ;
F_24 ( V_33 ) ;
V_5 = F_41 ( & V_76 ) ;
if ( V_5 ) {
F_4 (
L_16 ,
V_76 . V_18 , V_127 -> V_16 , V_127 -> V_17 , V_5 ) ;
continue;
}
}
}
static void F_72 ( void )
{
struct V_19 * V_128 ;
struct V_19 * V_20 ;
F_73 (dev, next, &ubiblock_devices, list) {
F_74 ( V_20 -> V_33 ) ;
F_63 ( & V_20 -> V_109 ) ;
F_59 ( V_20 ) ;
F_58 ( V_20 ) ;
}
}
int T_1 F_75 ( void )
{
int V_5 ;
V_91 = F_76 ( 0 , L_17 ) ;
if ( V_91 < 0 )
return V_91 ;
F_70 () ;
V_5 = F_77 ( & V_129 , 1 ) ;
if ( V_5 )
goto V_130;
return 0 ;
V_130:
F_78 ( V_91 , L_17 ) ;
F_72 () ;
return V_5 ;
}
void T_5 F_79 ( void )
{
F_80 ( & V_129 ) ;
F_72 () ;
F_78 ( V_91 , L_17 ) ;
}
