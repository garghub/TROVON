static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_2 * V_4 , struct V_5 * * V_6 , int V_7 ,
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
& V_24 , V_8 , false ) ;
if ( V_18 )
return V_18 ;
V_18 = V_25 ;
} else {
if ( V_8 )
return 0 ;
F_7 ( * V_6 , V_8 ) ;
if ( ! V_7 )
return - V_26 ;
}
V_17 = F_8 ( * V_6 ) ;
F_9 ( & V_17 -> V_27 ) ;
V_17 -> V_28 = V_15 -> V_29 ;
V_17 -> V_30 = V_15 -> V_30 ;
F_10 ( & V_17 -> V_27 ) ;
if ( V_18 == V_25 )
F_11 ( V_10 , * V_6 ) ;
return V_18 ;
}
static void * F_12 ( struct V_31 * V_32 ,
unsigned int V_33 , unsigned int V_34 ,
unsigned int V_35 )
{
int V_36 = F_13 ( V_32 ) ;
int V_37 = V_33 + V_35 ;
if ( ! F_14 ( V_32 , V_34 + V_36 ) || ( V_34 < V_37 ) ||
F_15 ( V_32 , V_37 + V_36 ) )
return NULL ;
else
return ( void * ) ( F_16 ( V_32 ) + V_33 ) ;
}
static int F_17 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
struct V_38 * V_39 ;
V_39 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_39 ) ) ;
if ( V_39 == NULL )
return 0 ;
V_39 -> V_40 = 0 ;
V_32 -> V_41 = F_18 ( V_39 , V_34 - V_33 , 0 ) ;
V_39 -> V_40 = F_19 ( V_32 -> V_41 ) ;
V_32 -> V_42 = V_43 ;
return 1 ;
}
static int F_20 ( struct V_31 * V_32 ,
unsigned int V_33 , unsigned int V_34 )
{
struct V_44 * V_45 ;
V_45 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_45 ) ) ;
if ( V_45 == NULL )
return 0 ;
V_45 -> V_41 = 0 ;
V_32 -> V_41 = F_18 ( V_45 , V_34 - V_33 , 0 ) ;
V_45 -> V_41 = F_19 ( V_32 -> V_41 ) ;
V_32 -> V_42 = V_43 ;
return 1 ;
}
static int F_21 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
struct V_46 * V_47 ;
const struct V_48 * V_49 ;
V_47 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_47 ) ) ;
if ( V_47 == NULL )
return 0 ;
V_49 = F_22 ( V_32 ) ;
V_47 -> V_50 = 0 ;
V_32 -> V_41 = F_18 ( V_47 , V_34 - V_33 , 0 ) ;
V_47 -> V_50 = F_23 ( & V_49 -> V_51 , & V_49 -> V_52 ,
V_34 - V_33 , V_53 ,
V_32 -> V_41 ) ;
V_32 -> V_42 = V_43 ;
return 1 ;
}
static int F_24 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
struct V_54 * V_55 ;
const struct V_56 * V_57 ;
V_55 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_55 ) ) ;
if ( V_55 == NULL )
return 0 ;
V_57 = F_25 ( V_32 ) ;
V_55 -> V_58 = 0 ;
V_32 -> V_41 = F_18 ( V_55 , V_34 - V_33 , 0 ) ;
V_55 -> V_58 = F_26 ( V_34 - V_33 ,
V_57 -> V_51 , V_57 -> V_52 , V_32 -> V_41 ) ;
V_32 -> V_42 = V_43 ;
return 1 ;
}
static int F_27 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
struct V_54 * V_55 ;
const struct V_48 * V_49 ;
V_55 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_55 ) ) ;
if ( V_55 == NULL )
return 0 ;
V_49 = F_22 ( V_32 ) ;
V_55 -> V_58 = 0 ;
V_32 -> V_41 = F_18 ( V_55 , V_34 - V_33 , 0 ) ;
V_55 -> V_58 = F_23 ( & V_49 -> V_51 , & V_49 -> V_52 ,
V_34 - V_33 , V_59 ,
V_32 -> V_41 ) ;
V_32 -> V_42 = V_43 ;
return 1 ;
}
static int F_28 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 , int V_60 )
{
struct V_61 * V_62 ;
const struct V_56 * V_57 ;
T_1 V_63 ;
V_62 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_62 ) ) ;
if ( V_62 == NULL )
return 0 ;
V_57 = F_25 ( V_32 ) ;
V_63 = F_29 ( V_62 -> V_64 ) ;
if ( V_60 || V_62 -> V_58 ) {
V_62 -> V_58 = 0 ;
if ( V_60 ) {
if ( V_63 == 0 )
V_32 -> V_41 = F_18 ( V_62 , V_34 - V_33 , 0 ) ;
else if ( ( V_63 >= sizeof( * V_62 ) ) && ( V_63 <= V_34 - V_33 ) )
V_32 -> V_41 = F_18 ( V_62 , V_63 , 0 ) ;
else
goto V_65;
} else {
if ( V_63 != V_34 - V_33 )
goto V_65;
V_32 -> V_41 = F_18 ( V_62 , V_63 , 0 ) ;
}
V_62 -> V_58 = F_30 ( V_57 -> V_51 , V_57 -> V_52 ,
V_63 , V_57 -> V_66 ,
V_32 -> V_41 ) ;
if ( ! V_62 -> V_58 )
V_62 -> V_58 = V_67 ;
}
V_32 -> V_42 = V_43 ;
V_65:
return 1 ;
}
static int F_31 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 , int V_60 )
{
struct V_61 * V_62 ;
const struct V_48 * V_49 ;
T_1 V_63 ;
V_62 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_62 ) ) ;
if ( V_62 == NULL )
return 0 ;
V_49 = F_22 ( V_32 ) ;
V_63 = F_29 ( V_62 -> V_64 ) ;
V_62 -> V_58 = 0 ;
if ( V_60 ) {
if ( V_63 == 0 )
V_32 -> V_41 = F_18 ( V_62 , V_34 - V_33 , 0 ) ;
else if ( ( V_63 >= sizeof( * V_62 ) ) && ( V_63 <= V_34 - V_33 ) )
V_32 -> V_41 = F_18 ( V_62 , V_63 , 0 ) ;
else
goto V_65;
} else {
if ( V_63 != V_34 - V_33 )
goto V_65;
V_32 -> V_41 = F_18 ( V_62 , V_63 , 0 ) ;
}
V_62 -> V_58 = F_23 ( & V_49 -> V_51 , & V_49 -> V_52 , V_63 ,
V_60 ? V_68 : V_69 ,
V_32 -> V_41 ) ;
if ( ! V_62 -> V_58 )
V_62 -> V_58 = V_67 ;
V_32 -> V_42 = V_43 ;
V_65:
return 1 ;
}
static int F_32 ( struct V_31 * V_32 , T_2 V_30 )
{
const struct V_56 * V_57 ;
int V_36 ;
V_36 = F_13 ( V_32 ) ;
if ( ! F_14 ( V_32 , sizeof( * V_57 ) + V_36 ) )
goto V_70;
V_57 = F_25 ( V_32 ) ;
switch ( V_57 -> V_71 & F_33 ( V_72 ) ? 0 : V_57 -> V_66 ) {
case V_73 :
if ( V_30 & V_74 )
if ( ! F_17 ( V_32 , V_57 -> V_33 * 4 ,
F_29 ( V_57 -> V_75 ) ) )
goto V_70;
break;
case V_76 :
if ( V_30 & V_77 )
if ( ! F_20 ( V_32 , V_57 -> V_33 * 4 ,
F_29 ( V_57 -> V_75 ) ) )
goto V_70;
break;
case V_59 :
if ( V_30 & V_78 )
if ( ! F_24 ( V_32 , V_57 -> V_33 * 4 ,
F_29 ( V_57 -> V_75 ) ) )
goto V_70;
break;
case V_69 :
if ( V_30 & V_79 )
if ( ! F_28 ( V_32 , V_57 -> V_33 * 4 ,
F_29 ( V_57 -> V_75 ) , 0 ) )
goto V_70;
break;
case V_68 :
if ( V_30 & V_80 )
if ( ! F_28 ( V_32 , V_57 -> V_33 * 4 ,
F_29 ( V_57 -> V_75 ) , 1 ) )
goto V_70;
break;
}
if ( V_30 & V_81 ) {
if ( F_15 ( V_32 , sizeof( * V_57 ) + V_36 ) )
goto V_70;
F_34 ( F_25 ( V_32 ) ) ;
}
return 1 ;
V_70:
return 0 ;
}
static int F_35 ( struct V_82 * V_83 , unsigned int V_84 ,
unsigned int * V_85 )
{
int V_86 , V_64 , V_87 ;
unsigned char * V_88 = ( void * ) V_83 ;
V_86 = sizeof( * V_83 ) ;
V_64 = V_84 - V_86 ;
while ( V_64 > 1 ) {
switch ( V_88 [ V_86 ] ) {
case V_89 :
V_87 = 1 ;
break;
case V_90 :
V_87 = V_88 [ V_86 + 1 ] + 2 ;
if ( V_87 != 6 || V_64 < 6 || ( V_86 & 3 ) != 2 )
return 0 ;
* V_85 = F_36 ( * ( V_91 * ) ( V_88 + V_86 + 2 ) ) ;
goto V_92;
default:
V_87 = V_88 [ V_86 + 1 ] + 2 ;
if ( V_87 > V_64 )
goto V_92;
break;
}
V_86 += V_87 ;
V_64 -= V_87 ;
}
V_92:
return 1 ;
}
static int F_37 ( struct V_31 * V_32 , T_2 V_30 )
{
struct V_48 * V_49 ;
struct V_82 * V_83 ;
unsigned int V_37 , V_84 ;
unsigned int V_85 ;
int V_36 ;
T_3 V_93 ;
V_36 = F_13 ( V_32 ) ;
V_37 = sizeof( * V_49 ) ;
if ( ! F_14 ( V_32 , V_37 + V_36 ) )
goto V_70;
V_49 = F_22 ( V_32 ) ;
V_85 = F_29 ( V_49 -> V_94 ) ;
V_93 = V_49 -> V_93 ;
do {
switch ( V_93 ) {
case V_95 :
goto V_96;
case V_97 :
case V_98 :
case V_99 :
if ( ! F_14 ( V_32 , V_37 + sizeof( * V_83 ) + V_36 ) )
goto V_70;
V_83 = ( void * ) ( F_16 ( V_32 ) + V_37 ) ;
V_84 = F_38 ( V_83 ) ;
if ( ! F_14 ( V_32 , V_37 + V_84 + V_36 ) )
goto V_70;
V_83 = ( void * ) ( F_16 ( V_32 ) + V_37 ) ;
if ( ( V_93 == V_98 ) &&
! ( F_35 ( V_83 , V_84 , & V_85 ) ) )
goto V_70;
V_93 = V_83 -> V_93 ;
V_37 += V_84 ;
break;
case V_53 :
if ( V_30 & V_74 )
if ( ! F_21 ( V_32 ,
V_37 , V_85 + sizeof( * V_49 ) ) )
goto V_70;
goto V_92;
case V_59 :
if ( V_30 & V_78 )
if ( ! F_27 ( V_32 ,
V_37 , V_85 + sizeof( * V_49 ) ) )
goto V_70;
goto V_92;
case V_69 :
if ( V_30 & V_79 )
if ( ! F_31 ( V_32 , V_37 ,
V_85 + sizeof( * V_49 ) , 0 ) )
goto V_70;
goto V_92;
case V_68 :
if ( V_30 & V_80 )
if ( ! F_31 ( V_32 , V_37 ,
V_85 + sizeof( * V_49 ) , 1 ) )
goto V_70;
goto V_92;
default:
goto V_96;
}
} while ( F_14 ( V_32 , V_37 + 1 + V_36 ) );
V_92:
V_96:
return 1 ;
V_70:
return 0 ;
}
static int V_16 ( struct V_31 * V_32 , const struct V_5 * V_6 ,
struct V_100 * V_101 )
{
struct V_16 * V_17 = F_8 ( V_6 ) ;
int V_29 ;
T_2 V_30 ;
F_39 ( & V_17 -> V_27 ) ;
F_40 ( & V_17 -> V_102 ) ;
F_41 ( & V_17 -> V_103 , V_32 ) ;
V_29 = V_17 -> V_28 ;
V_30 = V_17 -> V_30 ;
F_42 ( & V_17 -> V_27 ) ;
if ( F_43 ( V_29 == V_104 ) )
goto V_105;
switch ( F_44 ( V_32 ) ) {
case F_45 ( V_106 ) :
if ( ! F_32 ( V_32 , V_30 ) )
goto V_105;
break;
case F_45 ( V_107 ) :
if ( ! F_37 ( V_32 , V_30 ) )
goto V_105;
break;
}
return V_29 ;
V_105:
F_39 ( & V_17 -> V_27 ) ;
V_17 -> V_108 . V_109 ++ ;
F_42 ( & V_17 -> V_27 ) ;
return V_104 ;
}
static int F_46 ( struct V_31 * V_32 , struct V_5 * V_6 , int V_8 ,
int V_110 )
{
unsigned char * V_111 = F_47 ( V_32 ) ;
struct V_16 * V_17 = F_8 ( V_6 ) ;
struct V_14 V_112 = {
. V_30 = V_17 -> V_30 ,
. V_23 = V_17 -> V_113 ,
. V_29 = V_17 -> V_28 ,
. V_114 = V_17 -> V_115 - V_110 ,
. V_116 = V_17 -> V_117 - V_8 ,
} ;
struct V_118 V_119 ;
if ( F_48 ( V_32 , V_22 , sizeof( V_112 ) , & V_112 ) )
goto V_120;
F_49 ( & V_119 , & V_17 -> V_102 ) ;
if ( F_50 ( V_32 , V_121 , sizeof( V_119 ) , & V_119 , V_122 ) )
goto V_120;
return V_32 -> V_64 ;
V_120:
F_51 ( V_32 , V_111 ) ;
return - 1 ;
}
static int F_52 ( struct V_1 * V_1 , struct V_31 * V_32 ,
struct V_123 * V_124 , int type ,
const struct V_125 * V_126 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_53 ( V_10 , V_32 , V_124 , type , V_126 ) ;
}
static int F_54 ( struct V_1 * V_1 , struct V_5 * * V_6 , T_2 V_23 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_55 ( V_10 , V_6 , V_23 ) ;
}
static T_4 int F_56 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_57 ( V_10 , & V_24 , V_127 ) ;
}
static void T_5 F_58 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_59 ( V_10 ) ;
}
static int T_6 F_60 ( void )
{
return F_61 ( & V_24 , & V_128 ) ;
}
static void T_7 F_62 ( void )
{
F_63 ( & V_24 , & V_128 ) ;
}
