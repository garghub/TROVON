static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 , struct V_5 * V_6 , int V_7 ,
int V_8 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
struct V_2 * V_12 [ V_13 + 1 ] ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 = 0 , V_19 ;
if ( V_3 == NULL )
return - V_20 ;
V_19 = F_3 ( V_12 , V_13 , V_3 , V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_12 [ V_22 ] == NULL )
return - V_20 ;
V_15 = F_4 ( V_12 [ V_22 ] ) ;
if ( ! F_5 ( V_10 , V_15 -> V_23 , V_6 , V_8 ) ) {
V_18 = F_6 ( V_10 , V_15 -> V_23 , V_4 , V_6 ,
sizeof( * V_17 ) , V_8 , false ) ;
if ( V_18 )
return V_18 ;
V_18 = V_24 ;
} else {
if ( V_8 )
return 0 ;
F_7 ( V_6 , V_8 ) ;
if ( ! V_7 )
return - V_25 ;
}
V_17 = F_8 ( V_6 ) ;
F_9 ( & V_17 -> V_26 ) ;
V_17 -> V_27 = V_15 -> V_28 ;
V_17 -> V_29 = V_15 -> V_29 ;
F_10 ( & V_17 -> V_26 ) ;
if ( V_18 == V_24 )
F_11 ( V_10 , V_6 ) ;
return V_18 ;
}
static void * F_12 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
int V_35 = F_13 ( V_31 ) ;
int V_36 = V_32 + V_34 ;
if ( ! F_14 ( V_31 , V_33 + V_35 ) || ( V_33 < V_36 ) ||
F_15 ( V_31 , V_36 + V_35 ) )
return NULL ;
else
return ( void * ) ( F_16 ( V_31 ) + V_32 ) ;
}
static int F_17 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_37 * V_38 ;
V_38 = F_12 ( V_31 , V_32 , V_33 , sizeof( * V_38 ) ) ;
if ( V_38 == NULL )
return 0 ;
V_38 -> V_39 = 0 ;
V_31 -> V_40 = F_18 ( V_38 , V_33 - V_32 , 0 ) ;
V_38 -> V_39 = F_19 ( V_31 -> V_40 ) ;
V_31 -> V_41 = V_42 ;
return 1 ;
}
static int F_20 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_43 * V_44 ;
V_44 = F_12 ( V_31 , V_32 , V_33 , sizeof( * V_44 ) ) ;
if ( V_44 == NULL )
return 0 ;
V_44 -> V_40 = 0 ;
V_31 -> V_40 = F_18 ( V_44 , V_33 - V_32 , 0 ) ;
V_44 -> V_40 = F_19 ( V_31 -> V_40 ) ;
V_31 -> V_41 = V_42 ;
return 1 ;
}
static int F_21 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_45 * V_46 ;
const struct V_47 * V_48 ;
V_46 = F_12 ( V_31 , V_32 , V_33 , sizeof( * V_46 ) ) ;
if ( V_46 == NULL )
return 0 ;
V_48 = F_22 ( V_31 ) ;
V_46 -> V_49 = 0 ;
V_31 -> V_40 = F_18 ( V_46 , V_33 - V_32 , 0 ) ;
V_46 -> V_49 = F_23 ( & V_48 -> V_50 , & V_48 -> V_51 ,
V_33 - V_32 , V_52 ,
V_31 -> V_40 ) ;
V_31 -> V_41 = V_42 ;
return 1 ;
}
static int F_24 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_53 * V_54 ;
const struct V_55 * V_56 ;
V_54 = F_12 ( V_31 , V_32 , V_33 , sizeof( * V_54 ) ) ;
if ( V_54 == NULL )
return 0 ;
V_56 = F_25 ( V_31 ) ;
V_54 -> V_57 = 0 ;
V_31 -> V_40 = F_18 ( V_54 , V_33 - V_32 , 0 ) ;
V_54 -> V_57 = F_26 ( V_33 - V_32 ,
V_56 -> V_50 , V_56 -> V_51 , V_31 -> V_40 ) ;
V_31 -> V_41 = V_42 ;
return 1 ;
}
static int F_27 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_53 * V_54 ;
const struct V_47 * V_48 ;
V_54 = F_12 ( V_31 , V_32 , V_33 , sizeof( * V_54 ) ) ;
if ( V_54 == NULL )
return 0 ;
V_48 = F_22 ( V_31 ) ;
V_54 -> V_57 = 0 ;
V_31 -> V_40 = F_18 ( V_54 , V_33 - V_32 , 0 ) ;
V_54 -> V_57 = F_23 ( & V_48 -> V_50 , & V_48 -> V_51 ,
V_33 - V_32 , V_58 ,
V_31 -> V_40 ) ;
V_31 -> V_41 = V_42 ;
return 1 ;
}
static int F_28 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 , int V_59 )
{
struct V_60 * V_61 ;
const struct V_55 * V_56 ;
T_1 V_62 ;
V_61 = F_12 ( V_31 , V_32 , V_33 , sizeof( * V_61 ) ) ;
if ( V_61 == NULL )
return 0 ;
V_56 = F_25 ( V_31 ) ;
V_62 = F_29 ( V_61 -> V_63 ) ;
if ( V_59 || V_61 -> V_57 ) {
V_61 -> V_57 = 0 ;
if ( V_59 ) {
if ( V_62 == 0 )
V_31 -> V_40 = F_18 ( V_61 , V_33 - V_32 , 0 ) ;
else if ( ( V_62 >= sizeof( * V_61 ) ) && ( V_62 <= V_33 - V_32 ) )
V_31 -> V_40 = F_18 ( V_61 , V_62 , 0 ) ;
else
goto V_64;
} else {
if ( V_62 != V_33 - V_32 )
goto V_64;
V_31 -> V_40 = F_18 ( V_61 , V_62 , 0 ) ;
}
V_61 -> V_57 = F_30 ( V_56 -> V_50 , V_56 -> V_51 ,
V_62 , V_56 -> V_65 ,
V_31 -> V_40 ) ;
if ( ! V_61 -> V_57 )
V_61 -> V_57 = V_66 ;
}
V_31 -> V_41 = V_42 ;
V_64:
return 1 ;
}
static int F_31 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 , int V_59 )
{
struct V_60 * V_61 ;
const struct V_47 * V_48 ;
T_1 V_62 ;
V_61 = F_12 ( V_31 , V_32 , V_33 , sizeof( * V_61 ) ) ;
if ( V_61 == NULL )
return 0 ;
V_48 = F_22 ( V_31 ) ;
V_62 = F_29 ( V_61 -> V_63 ) ;
V_61 -> V_57 = 0 ;
if ( V_59 ) {
if ( V_62 == 0 )
V_31 -> V_40 = F_18 ( V_61 , V_33 - V_32 , 0 ) ;
else if ( ( V_62 >= sizeof( * V_61 ) ) && ( V_62 <= V_33 - V_32 ) )
V_31 -> V_40 = F_18 ( V_61 , V_62 , 0 ) ;
else
goto V_64;
} else {
if ( V_62 != V_33 - V_32 )
goto V_64;
V_31 -> V_40 = F_18 ( V_61 , V_62 , 0 ) ;
}
V_61 -> V_57 = F_23 ( & V_48 -> V_50 , & V_48 -> V_51 , V_62 ,
V_59 ? V_67 : V_68 ,
V_31 -> V_40 ) ;
if ( ! V_61 -> V_57 )
V_61 -> V_57 = V_66 ;
V_31 -> V_41 = V_42 ;
V_64:
return 1 ;
}
static int F_32 ( struct V_30 * V_31 , T_2 V_29 )
{
const struct V_55 * V_56 ;
int V_35 ;
V_35 = F_13 ( V_31 ) ;
if ( ! F_14 ( V_31 , sizeof( * V_56 ) + V_35 ) )
goto V_69;
V_56 = F_25 ( V_31 ) ;
switch ( V_56 -> V_70 & F_33 ( V_71 ) ? 0 : V_56 -> V_65 ) {
case V_72 :
if ( V_29 & V_73 )
if ( ! F_17 ( V_31 , V_56 -> V_32 * 4 ,
F_29 ( V_56 -> V_74 ) ) )
goto V_69;
break;
case V_75 :
if ( V_29 & V_76 )
if ( ! F_20 ( V_31 , V_56 -> V_32 * 4 ,
F_29 ( V_56 -> V_74 ) ) )
goto V_69;
break;
case V_58 :
if ( V_29 & V_77 )
if ( ! F_24 ( V_31 , V_56 -> V_32 * 4 ,
F_29 ( V_56 -> V_74 ) ) )
goto V_69;
break;
case V_68 :
if ( V_29 & V_78 )
if ( ! F_28 ( V_31 , V_56 -> V_32 * 4 ,
F_29 ( V_56 -> V_74 ) , 0 ) )
goto V_69;
break;
case V_67 :
if ( V_29 & V_79 )
if ( ! F_28 ( V_31 , V_56 -> V_32 * 4 ,
F_29 ( V_56 -> V_74 ) , 1 ) )
goto V_69;
break;
}
if ( V_29 & V_80 ) {
if ( F_15 ( V_31 , sizeof( * V_56 ) + V_35 ) )
goto V_69;
F_34 ( F_25 ( V_31 ) ) ;
}
return 1 ;
V_69:
return 0 ;
}
static int F_35 ( struct V_81 * V_82 ,
unsigned int V_83 , unsigned int * V_84 )
{
int V_85 , V_63 , V_86 ;
unsigned char * V_87 = ( void * ) V_82 ;
V_85 = sizeof( * V_82 ) ;
V_63 = V_83 - V_85 ;
while ( V_63 > 1 ) {
switch ( V_87 [ V_85 ] ) {
case V_88 :
V_86 = 1 ;
break;
case V_89 :
V_86 = V_87 [ V_85 + 1 ] + 2 ;
if ( V_86 != 6 || V_63 < 6 || ( V_85 & 3 ) != 2 )
return 0 ;
* V_84 = F_36 ( * ( V_90 * ) ( V_87 + V_85 + 2 ) ) ;
goto V_91;
default:
V_86 = V_87 [ V_85 + 1 ] + 2 ;
if ( V_86 > V_63 )
goto V_91;
break;
}
V_85 += V_86 ;
V_63 -= V_86 ;
}
V_91:
return 1 ;
}
static int F_37 ( struct V_30 * V_31 , T_2 V_29 )
{
struct V_47 * V_48 ;
struct V_81 * V_82 ;
unsigned int V_36 , V_83 ;
unsigned int V_84 ;
int V_35 ;
T_3 V_92 ;
V_35 = F_13 ( V_31 ) ;
V_36 = sizeof( * V_48 ) ;
if ( ! F_14 ( V_31 , V_36 + V_35 ) )
goto V_69;
V_48 = F_22 ( V_31 ) ;
V_84 = F_29 ( V_48 -> V_93 ) ;
V_92 = V_48 -> V_92 ;
do {
switch ( V_92 ) {
case V_94 :
goto V_95;
case V_96 :
case V_97 :
case V_98 :
if ( ! F_14 ( V_31 , V_36 + sizeof( * V_82 ) + V_35 ) )
goto V_69;
V_82 = ( void * ) ( F_16 ( V_31 ) + V_36 ) ;
V_83 = F_38 ( V_82 ) ;
if ( ! F_14 ( V_31 , V_36 + V_83 + V_35 ) )
goto V_69;
V_82 = ( void * ) ( F_16 ( V_31 ) + V_36 ) ;
if ( ( V_92 == V_97 ) &&
! ( F_35 ( V_82 , V_83 , & V_84 ) ) )
goto V_69;
V_92 = V_82 -> V_92 ;
V_36 += V_83 ;
break;
case V_52 :
if ( V_29 & V_73 )
if ( ! F_21 ( V_31 ,
V_36 , V_84 + sizeof( * V_48 ) ) )
goto V_69;
goto V_91;
case V_58 :
if ( V_29 & V_77 )
if ( ! F_27 ( V_31 ,
V_36 , V_84 + sizeof( * V_48 ) ) )
goto V_69;
goto V_91;
case V_68 :
if ( V_29 & V_78 )
if ( ! F_31 ( V_31 , V_36 ,
V_84 + sizeof( * V_48 ) , 0 ) )
goto V_69;
goto V_91;
case V_67 :
if ( V_29 & V_79 )
if ( ! F_31 ( V_31 , V_36 ,
V_84 + sizeof( * V_48 ) , 1 ) )
goto V_69;
goto V_91;
default:
goto V_95;
}
} while ( F_14 ( V_31 , V_36 + 1 + V_35 ) );
V_91:
V_95:
return 1 ;
V_69:
return 0 ;
}
static int V_16 ( struct V_30 * V_31 ,
const struct V_5 * V_6 , struct V_99 * V_100 )
{
struct V_16 * V_17 = V_6 -> V_101 ;
int V_28 ;
T_2 V_29 ;
F_39 ( & V_17 -> V_26 ) ;
V_17 -> V_102 . V_103 = V_104 ;
F_40 ( & V_17 -> V_105 , V_31 ) ;
V_28 = V_17 -> V_27 ;
V_29 = V_17 -> V_29 ;
F_41 ( & V_17 -> V_26 ) ;
if ( F_42 ( V_28 == V_106 ) )
goto V_107;
switch ( F_43 ( V_31 ) ) {
case F_44 ( V_108 ) :
if ( ! F_32 ( V_31 , V_29 ) )
goto V_107;
break;
case F_44 ( V_109 ) :
if ( ! F_37 ( V_31 , V_29 ) )
goto V_107;
break;
}
return V_28 ;
V_107:
F_39 ( & V_17 -> V_26 ) ;
V_17 -> V_110 . V_111 ++ ;
F_41 ( & V_17 -> V_26 ) ;
return V_106 ;
}
static int F_45 ( struct V_30 * V_31 ,
struct V_5 * V_6 , int V_8 , int V_112 )
{
unsigned char * V_113 = F_46 ( V_31 ) ;
struct V_16 * V_17 = V_6 -> V_101 ;
struct V_14 V_114 = {
. V_29 = V_17 -> V_29 ,
. V_23 = V_17 -> V_115 ,
. V_28 = V_17 -> V_27 ,
. V_116 = V_17 -> V_117 - V_112 ,
. V_118 = V_17 -> V_119 - V_8 ,
} ;
struct V_120 V_121 ;
if ( F_47 ( V_31 , V_22 , sizeof( V_114 ) , & V_114 ) )
goto V_122;
V_121 . V_123 = F_48 ( V_104 - V_17 -> V_102 . V_123 ) ;
V_121 . V_103 = F_48 ( V_104 - V_17 -> V_102 . V_103 ) ;
V_121 . V_124 = F_48 ( V_17 -> V_102 . V_124 ) ;
if ( F_49 ( V_31 , V_125 , sizeof( V_121 ) , & V_121 , V_126 ) )
goto V_122;
return V_31 -> V_63 ;
V_122:
F_50 ( V_31 , V_113 ) ;
return - 1 ;
}
static int F_51 ( struct V_1 * V_1 , struct V_30 * V_31 ,
struct V_127 * V_128 , int type ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_52 ( V_10 , V_31 , V_128 , type , V_6 ) ;
}
static int F_53 ( struct V_1 * V_1 , struct V_5 * V_6 , T_2 V_23 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_54 ( V_10 , V_6 , V_23 ) ;
}
static T_4 int F_55 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_56 ( V_10 , & V_129 , V_130 ) ;
}
static void T_5 F_57 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_58 ( V_10 ) ;
}
static int T_6 F_59 ( void )
{
return F_60 ( & V_129 , & V_131 ) ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_129 , & V_131 ) ;
}
