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
V_15 = F_4 ( V_13 -> V_23 , V_7 , V_9 , & V_24 ) ;
if ( ! V_15 ) {
V_15 = F_5 ( V_13 -> V_23 , V_5 , V_7 , sizeof( * V_17 ) , V_9 ,
& V_25 , & V_24 ) ;
if ( F_6 ( V_15 ) )
return F_7 ( V_15 ) ;
V_17 = F_8 ( V_15 ) ;
V_18 = V_26 ;
} else {
V_17 = F_8 ( V_15 ) ;
if ( ! V_8 ) {
F_9 ( V_15 , V_9 , & V_24 ) ;
return - V_27 ;
}
}
F_10 ( & V_17 -> V_28 ) ;
V_17 -> V_29 = V_13 -> V_30 ;
V_17 -> V_31 = V_13 -> V_31 ;
F_11 ( & V_17 -> V_28 ) ;
if ( V_18 == V_26 )
F_12 ( V_15 , & V_24 ) ;
return V_18 ;
}
static int F_13 ( struct V_6 * V_7 , int V_9 )
{
struct V_16 * V_17 = V_7 -> V_32 ;
return F_9 ( & V_17 -> V_33 , V_9 , & V_24 ) ;
}
static void * F_14 ( struct V_34 * V_35 ,
unsigned int V_36 , unsigned int V_37 ,
unsigned int V_38 )
{
int V_39 = F_15 ( V_35 ) ;
int V_40 = V_36 + V_38 ;
if ( ! F_16 ( V_35 , V_37 + V_39 ) || ( V_37 < V_40 ) ||
( F_17 ( V_35 ) &&
! F_18 ( V_35 , V_40 + V_39 ) &&
F_19 ( V_35 , 0 , 0 , V_41 ) ) )
return NULL ;
else
return ( void * ) ( F_20 ( V_35 ) + V_36 ) ;
}
static int F_21 ( struct V_34 * V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
struct V_42 * V_43 ;
V_43 = F_14 ( V_35 , V_36 , V_37 , sizeof( * V_43 ) ) ;
if ( V_43 == NULL )
return 0 ;
V_43 -> V_44 = 0 ;
V_35 -> V_45 = F_22 ( V_43 , V_37 - V_36 , 0 ) ;
V_43 -> V_44 = F_23 ( V_35 -> V_45 ) ;
V_35 -> V_46 = V_47 ;
return 1 ;
}
static int F_24 ( struct V_34 * V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
struct V_48 * V_49 ;
V_49 = F_14 ( V_35 , V_36 , V_37 , sizeof( * V_49 ) ) ;
if ( V_49 == NULL )
return 0 ;
V_49 -> V_45 = 0 ;
V_35 -> V_45 = F_22 ( V_49 , V_37 - V_36 , 0 ) ;
V_49 -> V_45 = F_23 ( V_35 -> V_45 ) ;
V_35 -> V_46 = V_47 ;
return 1 ;
}
static int F_25 ( struct V_34 * V_35 , struct V_50 * V_51 ,
unsigned int V_36 , unsigned int V_37 )
{
struct V_52 * V_53 ;
V_53 = F_14 ( V_35 , V_36 , V_37 , sizeof( * V_53 ) ) ;
if ( V_53 == NULL )
return 0 ;
V_53 -> V_54 = 0 ;
V_35 -> V_45 = F_22 ( V_53 , V_37 - V_36 , 0 ) ;
V_53 -> V_54 = F_26 ( & V_51 -> V_55 , & V_51 -> V_56 ,
V_37 - V_36 , V_57 ,
V_35 -> V_45 ) ;
V_35 -> V_46 = V_47 ;
return 1 ;
}
static int F_27 ( struct V_34 * V_35 , struct V_58 * V_59 ,
unsigned int V_36 , unsigned int V_37 )
{
struct V_60 * V_61 ;
V_61 = F_14 ( V_35 , V_36 , V_37 , sizeof( * V_61 ) ) ;
if ( V_61 == NULL )
return 0 ;
V_61 -> V_62 = 0 ;
V_35 -> V_45 = F_22 ( V_61 , V_37 - V_36 , 0 ) ;
V_61 -> V_62 = F_28 ( V_37 - V_36 ,
V_59 -> V_55 , V_59 -> V_56 , V_35 -> V_45 ) ;
V_35 -> V_46 = V_47 ;
return 1 ;
}
static int F_29 ( struct V_34 * V_35 , struct V_50 * V_51 ,
unsigned int V_36 , unsigned int V_37 )
{
struct V_60 * V_61 ;
V_61 = F_14 ( V_35 , V_36 , V_37 , sizeof( * V_61 ) ) ;
if ( V_61 == NULL )
return 0 ;
V_61 -> V_62 = 0 ;
V_35 -> V_45 = F_22 ( V_61 , V_37 - V_36 , 0 ) ;
V_61 -> V_62 = F_26 ( & V_51 -> V_55 , & V_51 -> V_56 ,
V_37 - V_36 , V_63 ,
V_35 -> V_45 ) ;
V_35 -> V_46 = V_47 ;
return 1 ;
}
static int F_30 ( struct V_34 * V_35 , struct V_58 * V_59 ,
unsigned int V_36 , unsigned int V_37 , int V_64 )
{
struct V_65 * V_66 ;
T_1 V_67 ;
V_66 = F_14 ( V_35 , V_36 , V_37 , sizeof( * V_66 ) ) ;
if ( V_66 == NULL )
return 0 ;
V_67 = F_31 ( V_66 -> V_68 ) ;
if ( V_64 || V_66 -> V_62 ) {
V_66 -> V_62 = 0 ;
if ( V_64 ) {
if ( V_67 == 0 )
V_35 -> V_45 = F_22 ( V_66 , V_37 - V_36 , 0 ) ;
else if ( ( V_67 >= sizeof( * V_66 ) ) && ( V_67 <= V_37 - V_36 ) )
V_35 -> V_45 = F_22 ( V_66 , V_67 , 0 ) ;
else
goto V_69;
} else {
if ( V_67 != V_37 - V_36 )
goto V_69;
V_35 -> V_45 = F_22 ( V_66 , V_67 , 0 ) ;
}
V_66 -> V_62 = F_32 ( V_59 -> V_55 , V_59 -> V_56 ,
V_67 , V_59 -> V_70 ,
V_35 -> V_45 ) ;
if ( ! V_66 -> V_62 )
V_66 -> V_62 = V_71 ;
}
V_35 -> V_46 = V_47 ;
V_69:
return 1 ;
}
static int F_33 ( struct V_34 * V_35 , struct V_50 * V_51 ,
unsigned int V_36 , unsigned int V_37 , int V_64 )
{
struct V_65 * V_66 ;
T_1 V_67 ;
V_66 = F_14 ( V_35 , V_36 , V_37 , sizeof( * V_66 ) ) ;
if ( V_66 == NULL )
return 0 ;
V_67 = F_31 ( V_66 -> V_68 ) ;
V_66 -> V_62 = 0 ;
if ( V_64 ) {
if ( V_67 == 0 )
V_35 -> V_45 = F_22 ( V_66 , V_37 - V_36 , 0 ) ;
else if ( ( V_67 >= sizeof( * V_66 ) ) && ( V_67 <= V_37 - V_36 ) )
V_35 -> V_45 = F_22 ( V_66 , V_67 , 0 ) ;
else
goto V_69;
} else {
if ( V_67 != V_37 - V_36 )
goto V_69;
V_35 -> V_45 = F_22 ( V_66 , V_67 , 0 ) ;
}
V_66 -> V_62 = F_26 ( & V_51 -> V_55 , & V_51 -> V_56 , V_67 ,
V_64 ? V_72 : V_73 ,
V_35 -> V_45 ) ;
if ( ! V_66 -> V_62 )
V_66 -> V_62 = V_71 ;
V_35 -> V_46 = V_47 ;
V_69:
return 1 ;
}
static int F_34 ( struct V_34 * V_35 , T_2 V_31 )
{
struct V_58 * V_59 ;
int V_39 ;
V_39 = F_15 ( V_35 ) ;
if ( ! F_16 ( V_35 , sizeof( * V_59 ) + V_39 ) )
goto V_74;
V_59 = F_35 ( V_35 ) ;
switch ( V_59 -> V_75 & F_36 ( V_76 ) ? 0 : V_59 -> V_70 ) {
case V_77 :
if ( V_31 & V_78 )
if ( ! F_21 ( V_35 , V_59 -> V_36 * 4 ,
F_31 ( V_59 -> V_79 ) ) )
goto V_74;
break;
case V_80 :
if ( V_31 & V_81 )
if ( ! F_24 ( V_35 , V_59 -> V_36 * 4 ,
F_31 ( V_59 -> V_79 ) ) )
goto V_74;
break;
case V_63 :
if ( V_31 & V_82 )
if ( ! F_27 ( V_35 , V_59 , V_59 -> V_36 * 4 ,
F_31 ( V_59 -> V_79 ) ) )
goto V_74;
break;
case V_73 :
if ( V_31 & V_83 )
if ( ! F_30 ( V_35 , V_59 , V_59 -> V_36 * 4 ,
F_31 ( V_59 -> V_79 ) , 0 ) )
goto V_74;
break;
case V_72 :
if ( V_31 & V_84 )
if ( ! F_30 ( V_35 , V_59 , V_59 -> V_36 * 4 ,
F_31 ( V_59 -> V_79 ) , 1 ) )
goto V_74;
break;
}
if ( V_31 & V_85 ) {
if ( F_17 ( V_35 ) &&
! F_18 ( V_35 , sizeof( * V_59 ) + V_39 ) &&
F_19 ( V_35 , 0 , 0 , V_41 ) )
goto V_74;
F_37 ( V_59 ) ;
}
return 1 ;
V_74:
return 0 ;
}
static int F_38 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned int * V_89 )
{
int V_90 , V_68 , V_91 ;
unsigned char * V_92 = ( void * ) V_87 ;
V_90 = sizeof( * V_87 ) ;
V_68 = V_88 - V_90 ;
while ( V_68 > 1 ) {
switch ( V_92 [ V_90 ] ) {
case V_93 :
V_91 = 1 ;
break;
case V_94 :
V_91 = V_92 [ V_90 + 1 ] + 2 ;
if ( V_91 != 6 || V_68 < 6 || ( V_90 & 3 ) != 2 )
return 0 ;
* V_89 = F_39 ( * ( V_95 * ) ( V_92 + V_90 + 2 ) ) ;
goto V_96;
default:
V_91 = V_92 [ V_90 + 1 ] + 2 ;
if ( V_91 > V_68 )
goto V_96;
break;
}
V_90 += V_91 ;
V_68 -= V_91 ;
}
V_96:
return 1 ;
}
static int F_40 ( struct V_34 * V_35 , T_2 V_31 )
{
struct V_50 * V_51 ;
struct V_86 * V_87 ;
unsigned int V_40 , V_88 ;
unsigned int V_89 ;
int V_39 ;
T_3 V_97 ;
V_39 = F_15 ( V_35 ) ;
V_40 = sizeof( * V_51 ) ;
if ( ! F_16 ( V_35 , V_40 + V_39 ) )
goto V_74;
V_51 = F_41 ( V_35 ) ;
V_89 = F_31 ( V_51 -> V_98 ) ;
V_97 = V_51 -> V_97 ;
do {
switch ( V_97 ) {
case V_99 :
goto V_100;
case V_101 :
case V_102 :
case V_103 :
if ( ! F_16 ( V_35 , V_40 + sizeof( * V_87 ) + V_39 ) )
goto V_74;
V_87 = ( void * ) ( F_20 ( V_35 ) + V_40 ) ;
V_88 = F_42 ( V_87 ) ;
if ( ! F_16 ( V_35 , V_40 + V_88 + V_39 ) )
goto V_74;
if ( ( V_97 == V_102 ) &&
! ( F_38 ( V_87 , V_88 , & V_89 ) ) )
goto V_74;
V_97 = V_87 -> V_97 ;
V_40 += V_88 ;
break;
case V_57 :
if ( V_31 & V_78 )
if ( ! F_25 ( V_35 , V_51 ,
V_40 , V_89 + sizeof( * V_51 ) ) )
goto V_74;
goto V_96;
case V_63 :
if ( V_31 & V_82 )
if ( ! F_29 ( V_35 , V_51 ,
V_40 , V_89 + sizeof( * V_51 ) ) )
goto V_74;
goto V_96;
case V_73 :
if ( V_31 & V_83 )
if ( ! F_33 ( V_35 , V_51 , V_40 ,
V_89 + sizeof( * V_51 ) , 0 ) )
goto V_74;
goto V_96;
case V_72 :
if ( V_31 & V_84 )
if ( ! F_33 ( V_35 , V_51 , V_40 ,
V_89 + sizeof( * V_51 ) , 1 ) )
goto V_74;
goto V_96;
default:
goto V_100;
}
} while ( F_16 ( V_35 , V_40 + 1 + V_39 ) );
V_96:
V_100:
return 1 ;
V_74:
return 0 ;
}
static int V_16 ( struct V_34 * V_35 ,
const struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_16 * V_17 = V_7 -> V_32 ;
int V_30 ;
T_2 V_31 ;
F_43 ( & V_17 -> V_28 ) ;
V_17 -> V_106 . V_107 = V_108 ;
F_44 ( & V_17 -> V_109 , V_35 ) ;
V_30 = V_17 -> V_29 ;
V_31 = V_17 -> V_31 ;
F_45 ( & V_17 -> V_28 ) ;
if ( F_46 ( V_30 == V_110 ) )
goto V_111;
switch ( V_35 -> V_70 ) {
case F_47 ( V_112 ) :
if ( ! F_34 ( V_35 , V_31 ) )
goto V_111;
break;
case F_47 ( V_113 ) :
if ( ! F_40 ( V_35 , V_31 ) )
goto V_111;
break;
}
return V_30 ;
V_111:
F_43 ( & V_17 -> V_28 ) ;
V_17 -> V_114 . V_115 ++ ;
F_45 ( & V_17 -> V_28 ) ;
return V_110 ;
}
static int F_48 ( struct V_34 * V_35 ,
struct V_6 * V_7 , int V_9 , int V_116 )
{
unsigned char * V_117 = F_49 ( V_35 ) ;
struct V_16 * V_17 = V_7 -> V_32 ;
struct V_12 V_118 = {
. V_31 = V_17 -> V_31 ,
. V_23 = V_17 -> V_119 ,
. V_30 = V_17 -> V_29 ,
. V_120 = V_17 -> V_121 - V_116 ,
. V_122 = V_17 -> V_123 - V_9 ,
} ;
struct V_124 V_125 ;
if ( F_50 ( V_35 , V_22 , sizeof( V_118 ) , & V_118 ) )
goto V_126;
V_125 . V_127 = F_51 ( V_108 - V_17 -> V_106 . V_127 ) ;
V_125 . V_107 = F_51 ( V_108 - V_17 -> V_106 . V_107 ) ;
V_125 . V_128 = F_51 ( V_17 -> V_106 . V_128 ) ;
if ( F_50 ( V_35 , V_129 , sizeof( V_125 ) , & V_125 ) )
goto V_126;
return V_35 -> V_68 ;
V_126:
F_52 ( V_35 , V_117 ) ;
return - 1 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_130 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_130 ) ;
}
