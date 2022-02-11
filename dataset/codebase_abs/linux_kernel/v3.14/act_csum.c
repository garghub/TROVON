static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_3 * V_5 ,
struct V_6 * V_7 , int V_8 , int V_9 )
{
struct V_3 * V_10 [ V_11 + 1 ] ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 = 0 , V_19 ;
if ( V_4 == NULL )
return - V_20 ;
V_19 = F_2 ( V_10 , V_11 , V_4 , V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_10 [ V_22 ] == NULL )
return - V_20 ;
V_13 = F_3 ( V_10 [ V_22 ] ) ;
V_15 = F_4 ( V_13 -> V_23 , V_7 , V_9 ) ;
if ( ! V_15 ) {
V_15 = F_5 ( V_13 -> V_23 , V_5 , V_7 , sizeof( * V_17 ) , V_9 ) ;
if ( F_6 ( V_15 ) )
return F_7 ( V_15 ) ;
V_18 = V_24 ;
} else {
if ( V_9 )
return 0 ;
F_8 ( V_15 , V_9 , V_7 -> V_25 -> V_26 ) ;
if ( ! V_8 )
return - V_27 ;
}
V_17 = F_9 ( V_15 ) ;
F_10 ( & V_17 -> V_28 ) ;
V_17 -> V_29 = V_13 -> V_30 ;
V_17 -> V_31 = V_13 -> V_31 ;
F_11 ( & V_17 -> V_28 ) ;
if ( V_18 == V_24 )
F_12 ( V_15 , V_7 -> V_25 -> V_26 ) ;
return V_18 ;
}
static int F_13 ( struct V_6 * V_7 , int V_9 )
{
struct V_16 * V_17 = V_7 -> V_32 ;
return F_8 ( & V_17 -> V_33 , V_9 , & V_34 ) ;
}
static void * F_14 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 ,
unsigned int V_39 )
{
int V_40 = F_15 ( V_36 ) ;
int V_41 = V_37 + V_39 ;
if ( ! F_16 ( V_36 , V_38 + V_40 ) || ( V_38 < V_41 ) ||
( F_17 ( V_36 ) &&
! F_18 ( V_36 , V_41 + V_40 ) &&
F_19 ( V_36 , 0 , 0 , V_42 ) ) )
return NULL ;
else
return ( void * ) ( F_20 ( V_36 ) + V_37 ) ;
}
static int F_21 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
struct V_43 * V_44 ;
V_44 = F_14 ( V_36 , V_37 , V_38 , sizeof( * V_44 ) ) ;
if ( V_44 == NULL )
return 0 ;
V_44 -> V_45 = 0 ;
V_36 -> V_46 = F_22 ( V_44 , V_38 - V_37 , 0 ) ;
V_44 -> V_45 = F_23 ( V_36 -> V_46 ) ;
V_36 -> V_47 = V_48 ;
return 1 ;
}
static int F_24 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
struct V_49 * V_50 ;
V_50 = F_14 ( V_36 , V_37 , V_38 , sizeof( * V_50 ) ) ;
if ( V_50 == NULL )
return 0 ;
V_50 -> V_46 = 0 ;
V_36 -> V_46 = F_22 ( V_50 , V_38 - V_37 , 0 ) ;
V_50 -> V_46 = F_23 ( V_36 -> V_46 ) ;
V_36 -> V_47 = V_48 ;
return 1 ;
}
static int F_25 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
struct V_51 * V_52 ;
const struct V_53 * V_54 ;
V_52 = F_14 ( V_36 , V_37 , V_38 , sizeof( * V_52 ) ) ;
if ( V_52 == NULL )
return 0 ;
V_54 = F_26 ( V_36 ) ;
V_52 -> V_55 = 0 ;
V_36 -> V_46 = F_22 ( V_52 , V_38 - V_37 , 0 ) ;
V_52 -> V_55 = F_27 ( & V_54 -> V_56 , & V_54 -> V_57 ,
V_38 - V_37 , V_58 ,
V_36 -> V_46 ) ;
V_36 -> V_47 = V_48 ;
return 1 ;
}
static int F_28 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
struct V_59 * V_60 ;
const struct V_61 * V_62 ;
V_60 = F_14 ( V_36 , V_37 , V_38 , sizeof( * V_60 ) ) ;
if ( V_60 == NULL )
return 0 ;
V_62 = F_29 ( V_36 ) ;
V_60 -> V_63 = 0 ;
V_36 -> V_46 = F_22 ( V_60 , V_38 - V_37 , 0 ) ;
V_60 -> V_63 = F_30 ( V_38 - V_37 ,
V_62 -> V_56 , V_62 -> V_57 , V_36 -> V_46 ) ;
V_36 -> V_47 = V_48 ;
return 1 ;
}
static int F_31 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
struct V_59 * V_60 ;
const struct V_53 * V_54 ;
V_60 = F_14 ( V_36 , V_37 , V_38 , sizeof( * V_60 ) ) ;
if ( V_60 == NULL )
return 0 ;
V_54 = F_26 ( V_36 ) ;
V_60 -> V_63 = 0 ;
V_36 -> V_46 = F_22 ( V_60 , V_38 - V_37 , 0 ) ;
V_60 -> V_63 = F_27 ( & V_54 -> V_56 , & V_54 -> V_57 ,
V_38 - V_37 , V_64 ,
V_36 -> V_46 ) ;
V_36 -> V_47 = V_48 ;
return 1 ;
}
static int F_32 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 , int V_65 )
{
struct V_66 * V_67 ;
const struct V_61 * V_62 ;
T_1 V_68 ;
V_67 = F_14 ( V_36 , V_37 , V_38 , sizeof( * V_67 ) ) ;
if ( V_67 == NULL )
return 0 ;
V_62 = F_29 ( V_36 ) ;
V_68 = F_33 ( V_67 -> V_69 ) ;
if ( V_65 || V_67 -> V_63 ) {
V_67 -> V_63 = 0 ;
if ( V_65 ) {
if ( V_68 == 0 )
V_36 -> V_46 = F_22 ( V_67 , V_38 - V_37 , 0 ) ;
else if ( ( V_68 >= sizeof( * V_67 ) ) && ( V_68 <= V_38 - V_37 ) )
V_36 -> V_46 = F_22 ( V_67 , V_68 , 0 ) ;
else
goto V_70;
} else {
if ( V_68 != V_38 - V_37 )
goto V_70;
V_36 -> V_46 = F_22 ( V_67 , V_68 , 0 ) ;
}
V_67 -> V_63 = F_34 ( V_62 -> V_56 , V_62 -> V_57 ,
V_68 , V_62 -> V_71 ,
V_36 -> V_46 ) ;
if ( ! V_67 -> V_63 )
V_67 -> V_63 = V_72 ;
}
V_36 -> V_47 = V_48 ;
V_70:
return 1 ;
}
static int F_35 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned int V_38 , int V_65 )
{
struct V_66 * V_67 ;
const struct V_53 * V_54 ;
T_1 V_68 ;
V_67 = F_14 ( V_36 , V_37 , V_38 , sizeof( * V_67 ) ) ;
if ( V_67 == NULL )
return 0 ;
V_54 = F_26 ( V_36 ) ;
V_68 = F_33 ( V_67 -> V_69 ) ;
V_67 -> V_63 = 0 ;
if ( V_65 ) {
if ( V_68 == 0 )
V_36 -> V_46 = F_22 ( V_67 , V_38 - V_37 , 0 ) ;
else if ( ( V_68 >= sizeof( * V_67 ) ) && ( V_68 <= V_38 - V_37 ) )
V_36 -> V_46 = F_22 ( V_67 , V_68 , 0 ) ;
else
goto V_70;
} else {
if ( V_68 != V_38 - V_37 )
goto V_70;
V_36 -> V_46 = F_22 ( V_67 , V_68 , 0 ) ;
}
V_67 -> V_63 = F_27 ( & V_54 -> V_56 , & V_54 -> V_57 , V_68 ,
V_65 ? V_73 : V_74 ,
V_36 -> V_46 ) ;
if ( ! V_67 -> V_63 )
V_67 -> V_63 = V_72 ;
V_36 -> V_47 = V_48 ;
V_70:
return 1 ;
}
static int F_36 ( struct V_35 * V_36 , T_2 V_31 )
{
const struct V_61 * V_62 ;
int V_40 ;
V_40 = F_15 ( V_36 ) ;
if ( ! F_16 ( V_36 , sizeof( * V_62 ) + V_40 ) )
goto V_75;
V_62 = F_29 ( V_36 ) ;
switch ( V_62 -> V_76 & F_37 ( V_77 ) ? 0 : V_62 -> V_71 ) {
case V_78 :
if ( V_31 & V_79 )
if ( ! F_21 ( V_36 , V_62 -> V_37 * 4 ,
F_33 ( V_62 -> V_80 ) ) )
goto V_75;
break;
case V_81 :
if ( V_31 & V_82 )
if ( ! F_24 ( V_36 , V_62 -> V_37 * 4 ,
F_33 ( V_62 -> V_80 ) ) )
goto V_75;
break;
case V_64 :
if ( V_31 & V_83 )
if ( ! F_28 ( V_36 , V_62 -> V_37 * 4 ,
F_33 ( V_62 -> V_80 ) ) )
goto V_75;
break;
case V_74 :
if ( V_31 & V_84 )
if ( ! F_32 ( V_36 , V_62 -> V_37 * 4 ,
F_33 ( V_62 -> V_80 ) , 0 ) )
goto V_75;
break;
case V_73 :
if ( V_31 & V_85 )
if ( ! F_32 ( V_36 , V_62 -> V_37 * 4 ,
F_33 ( V_62 -> V_80 ) , 1 ) )
goto V_75;
break;
}
if ( V_31 & V_86 ) {
if ( F_17 ( V_36 ) &&
! F_18 ( V_36 , sizeof( * V_62 ) + V_40 ) &&
F_19 ( V_36 , 0 , 0 , V_42 ) )
goto V_75;
F_38 ( F_29 ( V_36 ) ) ;
}
return 1 ;
V_75:
return 0 ;
}
static int F_39 ( struct V_87 * V_88 ,
unsigned int V_89 , unsigned int * V_90 )
{
int V_91 , V_69 , V_92 ;
unsigned char * V_93 = ( void * ) V_88 ;
V_91 = sizeof( * V_88 ) ;
V_69 = V_89 - V_91 ;
while ( V_69 > 1 ) {
switch ( V_93 [ V_91 ] ) {
case V_94 :
V_92 = 1 ;
break;
case V_95 :
V_92 = V_93 [ V_91 + 1 ] + 2 ;
if ( V_92 != 6 || V_69 < 6 || ( V_91 & 3 ) != 2 )
return 0 ;
* V_90 = F_40 ( * ( V_96 * ) ( V_93 + V_91 + 2 ) ) ;
goto V_97;
default:
V_92 = V_93 [ V_91 + 1 ] + 2 ;
if ( V_92 > V_69 )
goto V_97;
break;
}
V_91 += V_92 ;
V_69 -= V_92 ;
}
V_97:
return 1 ;
}
static int F_41 ( struct V_35 * V_36 , T_2 V_31 )
{
struct V_53 * V_54 ;
struct V_87 * V_88 ;
unsigned int V_41 , V_89 ;
unsigned int V_90 ;
int V_40 ;
T_3 V_98 ;
V_40 = F_15 ( V_36 ) ;
V_41 = sizeof( * V_54 ) ;
if ( ! F_16 ( V_36 , V_41 + V_40 ) )
goto V_75;
V_54 = F_26 ( V_36 ) ;
V_90 = F_33 ( V_54 -> V_99 ) ;
V_98 = V_54 -> V_98 ;
do {
switch ( V_98 ) {
case V_100 :
goto V_101;
case V_102 :
case V_103 :
case V_104 :
if ( ! F_16 ( V_36 , V_41 + sizeof( * V_88 ) + V_40 ) )
goto V_75;
V_88 = ( void * ) ( F_20 ( V_36 ) + V_41 ) ;
V_89 = F_42 ( V_88 ) ;
if ( ! F_16 ( V_36 , V_41 + V_89 + V_40 ) )
goto V_75;
V_88 = ( void * ) ( F_20 ( V_36 ) + V_41 ) ;
if ( ( V_98 == V_103 ) &&
! ( F_39 ( V_88 , V_89 , & V_90 ) ) )
goto V_75;
V_98 = V_88 -> V_98 ;
V_41 += V_89 ;
break;
case V_58 :
if ( V_31 & V_79 )
if ( ! F_25 ( V_36 ,
V_41 , V_90 + sizeof( * V_54 ) ) )
goto V_75;
goto V_97;
case V_64 :
if ( V_31 & V_83 )
if ( ! F_31 ( V_36 ,
V_41 , V_90 + sizeof( * V_54 ) ) )
goto V_75;
goto V_97;
case V_74 :
if ( V_31 & V_84 )
if ( ! F_35 ( V_36 , V_41 ,
V_90 + sizeof( * V_54 ) , 0 ) )
goto V_75;
goto V_97;
case V_73 :
if ( V_31 & V_85 )
if ( ! F_35 ( V_36 , V_41 ,
V_90 + sizeof( * V_54 ) , 1 ) )
goto V_75;
goto V_97;
default:
goto V_101;
}
} while ( F_16 ( V_36 , V_41 + 1 + V_40 ) );
V_97:
V_101:
return 1 ;
V_75:
return 0 ;
}
static int V_16 ( struct V_35 * V_36 ,
const struct V_6 * V_7 , struct V_105 * V_106 )
{
struct V_16 * V_17 = V_7 -> V_32 ;
int V_30 ;
T_2 V_31 ;
F_43 ( & V_17 -> V_28 ) ;
V_17 -> V_107 . V_108 = V_109 ;
F_44 ( & V_17 -> V_110 , V_36 ) ;
V_30 = V_17 -> V_29 ;
V_31 = V_17 -> V_31 ;
F_45 ( & V_17 -> V_28 ) ;
if ( F_46 ( V_30 == V_111 ) )
goto V_112;
switch ( V_36 -> V_71 ) {
case F_47 ( V_113 ) :
if ( ! F_36 ( V_36 , V_31 ) )
goto V_112;
break;
case F_47 ( V_114 ) :
if ( ! F_41 ( V_36 , V_31 ) )
goto V_112;
break;
}
return V_30 ;
V_112:
F_43 ( & V_17 -> V_28 ) ;
V_17 -> V_115 . V_116 ++ ;
F_45 ( & V_17 -> V_28 ) ;
return V_111 ;
}
static int F_48 ( struct V_35 * V_36 ,
struct V_6 * V_7 , int V_9 , int V_117 )
{
unsigned char * V_118 = F_49 ( V_36 ) ;
struct V_16 * V_17 = V_7 -> V_32 ;
struct V_12 V_119 = {
. V_31 = V_17 -> V_31 ,
. V_23 = V_17 -> V_120 ,
. V_30 = V_17 -> V_29 ,
. V_121 = V_17 -> V_122 - V_117 ,
. V_123 = V_17 -> V_124 - V_9 ,
} ;
struct V_125 V_126 ;
if ( F_50 ( V_36 , V_22 , sizeof( V_119 ) , & V_119 ) )
goto V_127;
V_126 . V_128 = F_51 ( V_109 - V_17 -> V_107 . V_128 ) ;
V_126 . V_108 = F_51 ( V_109 - V_17 -> V_107 . V_108 ) ;
V_126 . V_129 = F_51 ( V_17 -> V_107 . V_129 ) ;
if ( F_50 ( V_36 , V_130 , sizeof( V_126 ) , & V_126 ) )
goto V_127;
return V_36 -> V_69 ;
V_127:
F_52 ( V_36 , V_118 ) ;
return - 1 ;
}
static int T_4 F_53 ( void )
{
int V_19 = F_54 ( & V_34 , V_131 ) ;
if ( V_19 )
return V_19 ;
return F_55 ( & V_132 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_132 ) ;
}
