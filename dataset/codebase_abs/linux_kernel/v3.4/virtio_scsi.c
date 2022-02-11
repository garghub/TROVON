static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
if ( ! V_7 )
return;
if ( ! F_3 ( V_6 ) ) {
F_4 ( V_6 , V_7 ) ;
return;
}
F_5 ( V_6 ) -> V_7 = F_6 ( V_7 , F_5 ( V_6 ) -> V_8 ) ;
F_7 ( V_6 ) -> V_7 = V_7 - F_5 ( V_6 ) -> V_7 ;
}
static void F_8 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_12 * V_13 = & V_11 -> V_13 . V_11 ;
F_9 ( & V_6 -> V_14 -> V_15 ,
L_1 ,
V_6 , V_13 -> V_16 , V_13 -> V_17 , V_13 -> V_18 ) ;
V_6 -> V_19 = V_13 -> V_17 ;
F_2 ( V_6 , V_13 -> V_7 ) ;
switch ( V_13 -> V_16 ) {
case V_20 :
F_10 ( V_6 , V_21 ) ;
break;
case V_22 :
F_10 ( V_6 , V_23 ) ;
break;
case V_24 :
F_10 ( V_6 , V_25 ) ;
break;
case V_26 :
F_10 ( V_6 , V_27 ) ;
break;
case V_28 :
F_10 ( V_6 , V_29 ) ;
break;
case V_30 :
F_10 ( V_6 , V_31 ) ;
break;
case V_32 :
F_10 ( V_6 , V_33 ) ;
break;
case V_34 :
F_10 ( V_6 , V_35 ) ;
break;
case V_36 :
F_10 ( V_6 , V_37 ) ;
break;
default:
F_11 ( V_38 , V_6 , L_2 ,
V_13 -> V_16 ) ;
case V_39 :
F_10 ( V_6 , V_23 ) ;
break;
}
F_12 ( V_13 -> V_18 > V_40 ) ;
if ( V_6 -> V_41 ) {
memcpy ( V_6 -> V_41 , V_13 -> V_42 ,
F_13 ( T_1 , V_13 -> V_18 , V_40 ) ) ;
if ( V_13 -> V_18 )
F_14 ( V_6 , V_43 ) ;
}
F_15 ( V_11 , V_44 ) ;
V_6 -> V_45 ( V_6 ) ;
}
static void F_16 ( struct V_46 * V_47 , void (* F_17)( void * V_9 ) )
{
struct V_1 * V_48 = F_1 ( V_47 -> V_3 ) ;
struct V_49 * V_50 = F_18 ( V_48 ) ;
void * V_9 ;
unsigned long V_51 ;
unsigned int V_52 ;
F_19 ( & V_50 -> V_53 , V_51 ) ;
do {
F_20 ( V_47 ) ;
while ( ( V_9 = F_21 ( V_47 , & V_52 ) ) != NULL )
F_17 ( V_9 ) ;
} while ( ! F_22 ( V_47 ) );
F_23 ( & V_50 -> V_53 , V_51 ) ;
}
static void F_24 ( struct V_46 * V_47 )
{
F_16 ( V_47 , F_8 ) ;
}
static void F_25 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
if ( V_11 -> V_54 )
F_26 ( V_11 -> V_54 ) ;
else
F_15 ( V_11 , V_44 ) ;
}
static void F_27 ( struct V_46 * V_47 )
{
F_16 ( V_47 , F_25 ) ;
}
static void F_28 ( struct V_46 * V_47 )
{
F_16 ( V_47 , F_25 ) ;
}
static void F_29 ( struct V_55 * V_56 , unsigned int * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_59 -> V_61 ;
struct V_55 * V_62 ;
unsigned int V_63 = * V_57 ;
int V_64 ;
F_30 (table->sgl, sg_elem, table->nents, i)
F_31 ( & V_56 [ V_63 ++ ] , F_32 ( V_62 ) , V_62 -> V_8 ) ;
* V_57 = V_63 ;
}
static void F_33 ( struct V_49 * V_50 ,
struct V_10 * V_11 ,
unsigned * V_65 , unsigned * V_66 ,
T_2 V_67 , T_2 V_68 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_55 * V_56 = V_50 -> V_56 ;
unsigned int V_63 = 0 ;
if ( V_6 ) {
struct V_1 * V_69 = F_1 ( V_50 -> V_3 ) ;
F_34 ( F_35 ( V_6 ) > V_69 -> V_70 ) ;
F_34 ( V_6 -> V_71 == V_72 ) ;
}
F_31 ( & V_56 [ V_63 ++ ] , & V_11 -> V_73 , V_67 ) ;
if ( V_6 && V_6 -> V_71 != V_74 )
F_29 ( V_56 , & V_63 , F_7 ( V_6 ) ) ;
* V_65 = V_63 ;
F_31 ( & V_56 [ V_63 ++ ] , & V_11 -> V_13 , V_68 ) ;
if ( V_6 && V_6 -> V_71 != V_75 )
F_29 ( V_56 , & V_63 , F_5 ( V_6 ) ) ;
* V_66 = V_63 - * V_65 ;
}
static int F_36 ( struct V_49 * V_50 , struct V_46 * V_47 ,
struct V_10 * V_11 ,
T_2 V_67 , T_2 V_68 , T_3 V_76 )
{
unsigned int V_65 , V_66 ;
unsigned long V_51 ;
int V_77 ;
F_19 ( & V_50 -> V_53 , V_51 ) ;
F_33 ( V_50 , V_11 , & V_65 , & V_66 , V_67 , V_68 ) ;
V_77 = F_37 ( V_47 , V_50 -> V_56 , V_65 , V_66 , V_11 , V_76 ) ;
if ( V_77 >= 0 )
F_38 ( V_47 ) ;
F_23 ( & V_50 -> V_53 , V_51 ) ;
return V_77 ;
}
static int F_39 ( struct V_1 * V_48 , struct V_5 * V_6 )
{
struct V_49 * V_50 = F_18 ( V_48 ) ;
struct V_10 * V_11 ;
int V_77 ;
F_9 ( & V_6 -> V_14 -> V_15 ,
L_3 , V_6 , V_6 -> V_78 [ 0 ] ) ;
V_77 = V_79 ;
V_11 = F_40 ( V_44 , V_80 ) ;
if ( ! V_11 )
goto V_81;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_73 . V_11 = (struct V_82 ) {
. V_83 [ 0 ] = 1 ,
. V_83 [ 1 ] = V_6 -> V_14 -> V_84 ,
. V_83 [ 2 ] = ( V_6 -> V_14 -> V_83 >> 8 ) | 0x40 ,
. V_83 [ 3 ] = V_6 -> V_14 -> V_83 & 0xff ,
. V_85 = ( unsigned long ) V_6 ,
. V_86 = V_87 ,
. V_88 = 0 ,
. V_89 = 0 ,
} ;
F_34 ( V_6 -> V_90 > V_91 ) ;
memcpy ( V_11 -> V_73 . V_11 . V_92 , V_6 -> V_78 , V_6 -> V_90 ) ;
if ( F_36 ( V_50 , V_50 -> V_93 , V_11 ,
sizeof V_11 -> V_73 . V_11 , sizeof V_11 -> V_13 . V_11 ,
V_80 ) >= 0 )
V_77 = 0 ;
V_81:
return V_77 ;
}
static int F_41 ( struct V_49 * V_50 , struct V_10 * V_11 )
{
F_42 ( V_54 ) ;
int V_77 = V_94 ;
V_11 -> V_54 = & V_54 ;
if ( F_36 ( V_50 , V_50 -> V_95 , V_11 ,
sizeof V_11 -> V_73 . V_96 , sizeof V_11 -> V_13 . V_96 ,
V_97 ) < 0 )
goto V_81;
F_43 ( & V_54 ) ;
if ( V_11 -> V_13 . V_96 . V_16 == V_20 ||
V_11 -> V_13 . V_96 . V_16 == V_98 )
V_77 = V_99 ;
V_81:
F_15 ( V_11 , V_44 ) ;
return V_77 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_49 * V_50 = F_18 ( V_6 -> V_14 -> V_100 ) ;
struct V_10 * V_11 ;
F_45 ( V_101 , V_6 -> V_14 , L_4 ) ;
V_11 = F_40 ( V_44 , V_97 ) ;
if ( ! V_11 )
return V_94 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_73 . V_96 = (struct V_102 ) {
. type = V_103 ,
. V_104 = V_105 ,
. V_83 [ 0 ] = 1 ,
. V_83 [ 1 ] = V_6 -> V_14 -> V_84 ,
. V_83 [ 2 ] = ( V_6 -> V_14 -> V_83 >> 8 ) | 0x40 ,
. V_83 [ 3 ] = V_6 -> V_14 -> V_83 & 0xff ,
} ;
return F_41 ( V_50 , V_11 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_49 * V_50 = F_18 ( V_6 -> V_14 -> V_100 ) ;
struct V_10 * V_11 ;
F_11 ( V_101 , V_6 , L_5 ) ;
V_11 = F_40 ( V_44 , V_97 ) ;
if ( ! V_11 )
return V_94 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_73 . V_96 = (struct V_102 ) {
. type = V_103 ,
. V_104 = V_106 ,
. V_83 [ 0 ] = 1 ,
. V_83 [ 1 ] = V_6 -> V_14 -> V_84 ,
. V_83 [ 2 ] = ( V_6 -> V_14 -> V_83 >> 8 ) | 0x40 ,
. V_83 [ 3 ] = V_6 -> V_14 -> V_83 & 0xff ,
. V_85 = ( unsigned long ) V_6 ,
} ;
return F_41 ( V_50 , V_11 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_49 * V_50 )
{
int V_107 ;
struct V_46 * V_108 [ 3 ] ;
T_4 * V_109 [] = {
F_27 ,
F_28 ,
F_24
} ;
const char * V_110 [] = {
L_6 ,
L_7 ,
L_8
} ;
V_107 = V_3 -> V_111 -> V_112 ( V_3 , 3 , V_108 , V_109 , V_110 ) ;
if ( V_107 )
return V_107 ;
V_50 -> V_95 = V_108 [ 0 ] ;
V_50 -> V_113 = V_108 [ 1 ] ;
V_50 -> V_93 = V_108 [ 2 ] ;
F_48 ( V_3 , V_114 , V_91 ) ;
F_48 ( V_3 , V_115 , V_40 ) ;
return 0 ;
}
static int T_5 F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_69 ;
struct V_49 * V_50 ;
int V_107 ;
T_1 V_116 ;
T_1 V_117 ;
V_116 = F_50 ( V_3 , V_118 ) ? : 1 ;
V_69 = F_51 ( & V_119 ,
sizeof( * V_50 ) + sizeof( V_50 -> V_56 [ 0 ] ) * ( V_116 + 2 ) ) ;
if ( ! V_69 )
return - V_120 ;
V_69 -> V_70 = V_116 ;
V_50 = F_18 ( V_69 ) ;
V_50 -> V_3 = V_3 ;
V_3 -> V_4 = V_69 ;
F_52 ( & V_50 -> V_53 ) ;
F_53 ( V_50 -> V_56 , V_116 + 2 ) ;
V_107 = F_47 ( V_3 , V_50 ) ;
if ( V_107 )
goto V_121;
V_117 = F_50 ( V_3 , V_117 ) ? : 1 ;
V_69 -> V_117 = F_13 ( T_1 , V_117 , V_69 -> V_122 ) ;
V_69 -> V_123 = F_50 ( V_3 , V_123 ) ? : 0xFFFF ;
V_69 -> V_124 = F_50 ( V_3 , V_124 ) + 1 ;
V_69 -> V_125 = F_50 ( V_3 , V_126 ) + 1 ;
V_69 -> V_127 = 0 ;
V_69 -> V_128 = V_91 ;
V_107 = F_54 ( V_69 , & V_3 -> V_129 ) ;
if ( V_107 )
goto V_130;
F_55 ( V_69 ) ;
return 0 ;
V_130:
V_3 -> V_111 -> V_131 ( V_3 ) ;
V_121:
F_56 ( V_69 ) ;
return V_107 ;
}
static void F_57 ( struct V_2 * V_3 )
{
V_3 -> V_111 -> V_132 ( V_3 ) ;
V_3 -> V_111 -> V_131 ( V_3 ) ;
}
static void T_6 F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_69 = F_1 ( V_3 ) ;
F_59 ( V_69 ) ;
F_57 ( V_3 ) ;
F_56 ( V_69 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
F_57 ( V_3 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_49 * V_50 = F_18 ( V_48 ) ;
return F_47 ( V_3 , V_50 ) ;
}
static int T_7 F_62 ( void )
{
int V_77 = - V_120 ;
V_133 = F_63 ( V_10 , 0 ) ;
if ( ! V_133 ) {
F_64 ( V_134 L_9
L_10 ) ;
goto error;
}
V_44 =
F_65 ( V_135 ,
V_133 ) ;
if ( ! V_44 ) {
F_64 ( V_134 L_11
L_12 ) ;
goto error;
}
V_77 = F_66 ( & V_136 ) ;
if ( V_77 < 0 )
goto error;
return 0 ;
error:
if ( V_44 ) {
F_67 ( V_44 ) ;
V_44 = NULL ;
}
if ( V_133 ) {
F_68 ( V_133 ) ;
V_133 = NULL ;
}
return V_77 ;
}
static void T_8 F_69 ( void )
{
F_70 ( & V_136 ) ;
F_67 ( V_44 ) ;
F_68 ( V_133 ) ;
}
