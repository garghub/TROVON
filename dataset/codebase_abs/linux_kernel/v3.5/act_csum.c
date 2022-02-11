static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , int V_6 , int V_7 )
{
struct V_1 * V_8 [ V_9 + 1 ] ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 = 0 , V_17 ;
if ( V_2 == NULL )
return - V_18 ;
V_17 = F_2 ( V_8 , V_9 , V_2 , V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_8 [ V_20 ] == NULL )
return - V_18 ;
V_11 = F_3 ( V_8 [ V_20 ] ) ;
V_13 = F_4 ( V_11 -> V_21 , V_5 , V_7 , & V_22 ) ;
if ( ! V_13 ) {
V_13 = F_5 ( V_11 -> V_21 , V_3 , V_5 , sizeof( * V_15 ) , V_7 ,
& V_23 , & V_22 ) ;
if ( F_6 ( V_13 ) )
return F_7 ( V_13 ) ;
V_15 = F_8 ( V_13 ) ;
V_16 = V_24 ;
} else {
V_15 = F_8 ( V_13 ) ;
if ( ! V_6 ) {
F_9 ( V_13 , V_7 , & V_22 ) ;
return - V_25 ;
}
}
F_10 ( & V_15 -> V_26 ) ;
V_15 -> V_27 = V_11 -> V_28 ;
V_15 -> V_29 = V_11 -> V_29 ;
F_11 ( & V_15 -> V_26 ) ;
if ( V_16 == V_24 )
F_12 ( V_13 , & V_22 ) ;
return V_16 ;
}
static int F_13 ( struct V_4 * V_5 , int V_7 )
{
struct V_14 * V_15 = V_5 -> V_30 ;
return F_9 ( & V_15 -> V_31 , V_7 , & V_22 ) ;
}
static void * F_14 ( struct V_32 * V_33 ,
unsigned int V_34 , unsigned int V_35 ,
unsigned int V_36 )
{
int V_37 = F_15 ( V_33 ) ;
int V_38 = V_34 + V_36 ;
if ( ! F_16 ( V_33 , V_35 + V_37 ) || ( V_35 < V_38 ) ||
( F_17 ( V_33 ) &&
! F_18 ( V_33 , V_38 + V_37 ) &&
F_19 ( V_33 , 0 , 0 , V_39 ) ) )
return NULL ;
else
return ( void * ) ( F_20 ( V_33 ) + V_34 ) ;
}
static int F_21 ( struct V_32 * V_33 ,
unsigned int V_34 , unsigned int V_35 )
{
struct V_40 * V_41 ;
V_41 = F_14 ( V_33 , V_34 , V_35 , sizeof( * V_41 ) ) ;
if ( V_41 == NULL )
return 0 ;
V_41 -> V_42 = 0 ;
V_33 -> V_43 = F_22 ( V_41 , V_35 - V_34 , 0 ) ;
V_41 -> V_42 = F_23 ( V_33 -> V_43 ) ;
V_33 -> V_44 = V_45 ;
return 1 ;
}
static int F_24 ( struct V_32 * V_33 ,
unsigned int V_34 , unsigned int V_35 )
{
struct V_46 * V_47 ;
V_47 = F_14 ( V_33 , V_34 , V_35 , sizeof( * V_47 ) ) ;
if ( V_47 == NULL )
return 0 ;
V_47 -> V_43 = 0 ;
V_33 -> V_43 = F_22 ( V_47 , V_35 - V_34 , 0 ) ;
V_47 -> V_43 = F_23 ( V_33 -> V_43 ) ;
V_33 -> V_44 = V_45 ;
return 1 ;
}
static int F_25 ( struct V_32 * V_33 , struct V_48 * V_49 ,
unsigned int V_34 , unsigned int V_35 )
{
struct V_50 * V_51 ;
V_51 = F_14 ( V_33 , V_34 , V_35 , sizeof( * V_51 ) ) ;
if ( V_51 == NULL )
return 0 ;
V_51 -> V_52 = 0 ;
V_33 -> V_43 = F_22 ( V_51 , V_35 - V_34 , 0 ) ;
V_51 -> V_52 = F_26 ( & V_49 -> V_53 , & V_49 -> V_54 ,
V_35 - V_34 , V_55 ,
V_33 -> V_43 ) ;
V_33 -> V_44 = V_45 ;
return 1 ;
}
static int F_27 ( struct V_32 * V_33 , struct V_56 * V_57 ,
unsigned int V_34 , unsigned int V_35 )
{
struct V_58 * V_59 ;
V_59 = F_14 ( V_33 , V_34 , V_35 , sizeof( * V_59 ) ) ;
if ( V_59 == NULL )
return 0 ;
V_59 -> V_60 = 0 ;
V_33 -> V_43 = F_22 ( V_59 , V_35 - V_34 , 0 ) ;
V_59 -> V_60 = F_28 ( V_35 - V_34 ,
V_57 -> V_53 , V_57 -> V_54 , V_33 -> V_43 ) ;
V_33 -> V_44 = V_45 ;
return 1 ;
}
static int F_29 ( struct V_32 * V_33 , struct V_48 * V_49 ,
unsigned int V_34 , unsigned int V_35 )
{
struct V_58 * V_59 ;
V_59 = F_14 ( V_33 , V_34 , V_35 , sizeof( * V_59 ) ) ;
if ( V_59 == NULL )
return 0 ;
V_59 -> V_60 = 0 ;
V_33 -> V_43 = F_22 ( V_59 , V_35 - V_34 , 0 ) ;
V_59 -> V_60 = F_26 ( & V_49 -> V_53 , & V_49 -> V_54 ,
V_35 - V_34 , V_61 ,
V_33 -> V_43 ) ;
V_33 -> V_44 = V_45 ;
return 1 ;
}
static int F_30 ( struct V_32 * V_33 , struct V_56 * V_57 ,
unsigned int V_34 , unsigned int V_35 , int V_62 )
{
struct V_63 * V_64 ;
T_1 V_65 ;
V_64 = F_14 ( V_33 , V_34 , V_35 , sizeof( * V_64 ) ) ;
if ( V_64 == NULL )
return 0 ;
V_65 = F_31 ( V_64 -> V_66 ) ;
if ( V_62 || V_64 -> V_60 ) {
V_64 -> V_60 = 0 ;
if ( V_62 ) {
if ( V_65 == 0 )
V_33 -> V_43 = F_22 ( V_64 , V_35 - V_34 , 0 ) ;
else if ( ( V_65 >= sizeof( * V_64 ) ) && ( V_65 <= V_35 - V_34 ) )
V_33 -> V_43 = F_22 ( V_64 , V_65 , 0 ) ;
else
goto V_67;
} else {
if ( V_65 != V_35 - V_34 )
goto V_67;
V_33 -> V_43 = F_22 ( V_64 , V_65 , 0 ) ;
}
V_64 -> V_60 = F_32 ( V_57 -> V_53 , V_57 -> V_54 ,
V_65 , V_57 -> V_68 ,
V_33 -> V_43 ) ;
if ( ! V_64 -> V_60 )
V_64 -> V_60 = V_69 ;
}
V_33 -> V_44 = V_45 ;
V_67:
return 1 ;
}
static int F_33 ( struct V_32 * V_33 , struct V_48 * V_49 ,
unsigned int V_34 , unsigned int V_35 , int V_62 )
{
struct V_63 * V_64 ;
T_1 V_65 ;
V_64 = F_14 ( V_33 , V_34 , V_35 , sizeof( * V_64 ) ) ;
if ( V_64 == NULL )
return 0 ;
V_65 = F_31 ( V_64 -> V_66 ) ;
V_64 -> V_60 = 0 ;
if ( V_62 ) {
if ( V_65 == 0 )
V_33 -> V_43 = F_22 ( V_64 , V_35 - V_34 , 0 ) ;
else if ( ( V_65 >= sizeof( * V_64 ) ) && ( V_65 <= V_35 - V_34 ) )
V_33 -> V_43 = F_22 ( V_64 , V_65 , 0 ) ;
else
goto V_67;
} else {
if ( V_65 != V_35 - V_34 )
goto V_67;
V_33 -> V_43 = F_22 ( V_64 , V_65 , 0 ) ;
}
V_64 -> V_60 = F_26 ( & V_49 -> V_53 , & V_49 -> V_54 , V_65 ,
V_62 ? V_70 : V_71 ,
V_33 -> V_43 ) ;
if ( ! V_64 -> V_60 )
V_64 -> V_60 = V_69 ;
V_33 -> V_44 = V_45 ;
V_67:
return 1 ;
}
static int F_34 ( struct V_32 * V_33 , T_2 V_29 )
{
struct V_56 * V_57 ;
int V_37 ;
V_37 = F_15 ( V_33 ) ;
if ( ! F_16 ( V_33 , sizeof( * V_57 ) + V_37 ) )
goto V_72;
V_57 = F_35 ( V_33 ) ;
switch ( V_57 -> V_73 & F_36 ( V_74 ) ? 0 : V_57 -> V_68 ) {
case V_75 :
if ( V_29 & V_76 )
if ( ! F_21 ( V_33 , V_57 -> V_34 * 4 ,
F_31 ( V_57 -> V_77 ) ) )
goto V_72;
break;
case V_78 :
if ( V_29 & V_79 )
if ( ! F_24 ( V_33 , V_57 -> V_34 * 4 ,
F_31 ( V_57 -> V_77 ) ) )
goto V_72;
break;
case V_61 :
if ( V_29 & V_80 )
if ( ! F_27 ( V_33 , V_57 , V_57 -> V_34 * 4 ,
F_31 ( V_57 -> V_77 ) ) )
goto V_72;
break;
case V_71 :
if ( V_29 & V_81 )
if ( ! F_30 ( V_33 , V_57 , V_57 -> V_34 * 4 ,
F_31 ( V_57 -> V_77 ) , 0 ) )
goto V_72;
break;
case V_70 :
if ( V_29 & V_82 )
if ( ! F_30 ( V_33 , V_57 , V_57 -> V_34 * 4 ,
F_31 ( V_57 -> V_77 ) , 1 ) )
goto V_72;
break;
}
if ( V_29 & V_83 ) {
if ( F_17 ( V_33 ) &&
! F_18 ( V_33 , sizeof( * V_57 ) + V_37 ) &&
F_19 ( V_33 , 0 , 0 , V_39 ) )
goto V_72;
F_37 ( V_57 ) ;
}
return 1 ;
V_72:
return 0 ;
}
static int F_38 ( struct V_84 * V_85 ,
unsigned int V_86 , unsigned int * V_87 )
{
int V_88 , V_66 , V_89 ;
unsigned char * V_90 = ( void * ) V_85 ;
V_88 = sizeof( * V_85 ) ;
V_66 = V_86 - V_88 ;
while ( V_66 > 1 ) {
switch ( V_90 [ V_88 ] ) {
case V_91 :
V_89 = 1 ;
break;
case V_92 :
V_89 = V_90 [ V_88 + 1 ] + 2 ;
if ( V_89 != 6 || V_66 < 6 || ( V_88 & 3 ) != 2 )
return 0 ;
* V_87 = F_39 ( * ( V_93 * ) ( V_90 + V_88 + 2 ) ) ;
goto V_94;
default:
V_89 = V_90 [ V_88 + 1 ] + 2 ;
if ( V_89 > V_66 )
goto V_94;
break;
}
V_88 += V_89 ;
V_66 -= V_89 ;
}
V_94:
return 1 ;
}
static int F_40 ( struct V_32 * V_33 , T_2 V_29 )
{
struct V_48 * V_49 ;
struct V_84 * V_85 ;
unsigned int V_38 , V_86 ;
unsigned int V_87 ;
int V_37 ;
T_3 V_95 ;
V_37 = F_15 ( V_33 ) ;
V_38 = sizeof( * V_49 ) ;
if ( ! F_16 ( V_33 , V_38 + V_37 ) )
goto V_72;
V_49 = F_41 ( V_33 ) ;
V_87 = F_31 ( V_49 -> V_96 ) ;
V_95 = V_49 -> V_95 ;
do {
switch ( V_95 ) {
case V_97 :
goto V_98;
case V_99 :
case V_100 :
case V_101 :
if ( ! F_16 ( V_33 , V_38 + sizeof( * V_85 ) + V_37 ) )
goto V_72;
V_85 = ( void * ) ( F_20 ( V_33 ) + V_38 ) ;
V_86 = F_42 ( V_85 ) ;
if ( ! F_16 ( V_33 , V_38 + V_86 + V_37 ) )
goto V_72;
if ( ( V_95 == V_100 ) &&
! ( F_38 ( V_85 , V_86 , & V_87 ) ) )
goto V_72;
V_95 = V_85 -> V_95 ;
V_38 += V_86 ;
break;
case V_55 :
if ( V_29 & V_76 )
if ( ! F_25 ( V_33 , V_49 ,
V_38 , V_87 + sizeof( * V_49 ) ) )
goto V_72;
goto V_94;
case V_61 :
if ( V_29 & V_80 )
if ( ! F_29 ( V_33 , V_49 ,
V_38 , V_87 + sizeof( * V_49 ) ) )
goto V_72;
goto V_94;
case V_71 :
if ( V_29 & V_81 )
if ( ! F_33 ( V_33 , V_49 , V_38 ,
V_87 + sizeof( * V_49 ) , 0 ) )
goto V_72;
goto V_94;
case V_70 :
if ( V_29 & V_82 )
if ( ! F_33 ( V_33 , V_49 , V_38 ,
V_87 + sizeof( * V_49 ) , 1 ) )
goto V_72;
goto V_94;
default:
goto V_98;
}
} while ( F_16 ( V_33 , V_38 + 1 + V_37 ) );
V_94:
V_98:
return 1 ;
V_72:
return 0 ;
}
static int V_14 ( struct V_32 * V_33 ,
const struct V_4 * V_5 , struct V_102 * V_103 )
{
struct V_14 * V_15 = V_5 -> V_30 ;
int V_28 ;
T_2 V_29 ;
F_43 ( & V_15 -> V_26 ) ;
V_15 -> V_104 . V_105 = V_106 ;
F_44 ( & V_15 -> V_107 , V_33 ) ;
V_28 = V_15 -> V_27 ;
V_29 = V_15 -> V_29 ;
F_45 ( & V_15 -> V_26 ) ;
if ( F_46 ( V_28 == V_108 ) )
goto V_109;
switch ( V_33 -> V_68 ) {
case F_47 ( V_110 ) :
if ( ! F_34 ( V_33 , V_29 ) )
goto V_109;
break;
case F_47 ( V_111 ) :
if ( ! F_40 ( V_33 , V_29 ) )
goto V_109;
break;
}
return V_28 ;
V_109:
F_43 ( & V_15 -> V_26 ) ;
V_15 -> V_112 . V_113 ++ ;
F_45 ( & V_15 -> V_26 ) ;
return V_108 ;
}
static int F_48 ( struct V_32 * V_33 ,
struct V_4 * V_5 , int V_7 , int V_114 )
{
unsigned char * V_115 = F_49 ( V_33 ) ;
struct V_14 * V_15 = V_5 -> V_30 ;
struct V_10 V_116 = {
. V_29 = V_15 -> V_29 ,
. V_21 = V_15 -> V_117 ,
. V_28 = V_15 -> V_27 ,
. V_118 = V_15 -> V_119 - V_114 ,
. V_120 = V_15 -> V_121 - V_7 ,
} ;
struct V_122 V_123 ;
if ( F_50 ( V_33 , V_20 , sizeof( V_116 ) , & V_116 ) )
goto V_124;
V_123 . V_125 = F_51 ( V_106 - V_15 -> V_104 . V_125 ) ;
V_123 . V_105 = F_51 ( V_106 - V_15 -> V_104 . V_105 ) ;
V_123 . V_126 = F_51 ( V_15 -> V_104 . V_126 ) ;
if ( F_50 ( V_33 , V_127 , sizeof( V_123 ) , & V_123 ) )
goto V_124;
return V_33 -> V_66 ;
V_124:
F_52 ( V_33 , V_115 ) ;
return - 1 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_128 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_128 ) ;
}
