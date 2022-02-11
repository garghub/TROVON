static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_3 * V_5 ,
struct V_6 * V_7 , int V_8 , int V_9 )
{
struct V_3 * V_10 [ V_11 + 1 ] ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 = 0 , V_17 ;
if ( V_4 == NULL )
return - V_18 ;
V_17 = F_2 ( V_10 , V_11 , V_4 , V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_10 [ V_20 ] == NULL )
return - V_18 ;
V_13 = F_3 ( V_10 [ V_20 ] ) ;
if ( ! F_4 ( V_13 -> V_21 , V_7 , V_9 ) ) {
V_16 = F_5 ( V_13 -> V_21 , V_5 , V_7 , sizeof( * V_15 ) ,
V_9 , false ) ;
if ( V_16 )
return V_16 ;
V_16 = V_22 ;
} else {
if ( V_9 )
return 0 ;
F_6 ( V_7 , V_9 ) ;
if ( ! V_8 )
return - V_23 ;
}
V_15 = F_7 ( V_7 ) ;
F_8 ( & V_15 -> V_24 ) ;
V_15 -> V_25 = V_13 -> V_26 ;
V_15 -> V_27 = V_13 -> V_27 ;
F_9 ( & V_15 -> V_24 ) ;
if ( V_16 == V_22 )
F_10 ( V_7 ) ;
return V_16 ;
}
static void * F_11 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 ,
unsigned int V_32 )
{
int V_33 = F_12 ( V_29 ) ;
int V_34 = V_30 + V_32 ;
if ( ! F_13 ( V_29 , V_31 + V_33 ) || ( V_31 < V_34 ) ||
( F_14 ( V_29 ) &&
! F_15 ( V_29 , V_34 + V_33 ) &&
F_16 ( V_29 , 0 , 0 , V_35 ) ) )
return NULL ;
else
return ( void * ) ( F_17 ( V_29 ) + V_30 ) ;
}
static int F_18 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_36 * V_37 ;
V_37 = F_11 ( V_29 , V_30 , V_31 , sizeof( * V_37 ) ) ;
if ( V_37 == NULL )
return 0 ;
V_37 -> V_38 = 0 ;
V_29 -> V_39 = F_19 ( V_37 , V_31 - V_30 , 0 ) ;
V_37 -> V_38 = F_20 ( V_29 -> V_39 ) ;
V_29 -> V_40 = V_41 ;
return 1 ;
}
static int F_21 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_42 * V_43 ;
V_43 = F_11 ( V_29 , V_30 , V_31 , sizeof( * V_43 ) ) ;
if ( V_43 == NULL )
return 0 ;
V_43 -> V_39 = 0 ;
V_29 -> V_39 = F_19 ( V_43 , V_31 - V_30 , 0 ) ;
V_43 -> V_39 = F_20 ( V_29 -> V_39 ) ;
V_29 -> V_40 = V_41 ;
return 1 ;
}
static int F_22 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_44 * V_45 ;
const struct V_46 * V_47 ;
V_45 = F_11 ( V_29 , V_30 , V_31 , sizeof( * V_45 ) ) ;
if ( V_45 == NULL )
return 0 ;
V_47 = F_23 ( V_29 ) ;
V_45 -> V_48 = 0 ;
V_29 -> V_39 = F_19 ( V_45 , V_31 - V_30 , 0 ) ;
V_45 -> V_48 = F_24 ( & V_47 -> V_49 , & V_47 -> V_50 ,
V_31 - V_30 , V_51 ,
V_29 -> V_39 ) ;
V_29 -> V_40 = V_41 ;
return 1 ;
}
static int F_25 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_52 * V_53 ;
const struct V_54 * V_55 ;
V_53 = F_11 ( V_29 , V_30 , V_31 , sizeof( * V_53 ) ) ;
if ( V_53 == NULL )
return 0 ;
V_55 = F_26 ( V_29 ) ;
V_53 -> V_56 = 0 ;
V_29 -> V_39 = F_19 ( V_53 , V_31 - V_30 , 0 ) ;
V_53 -> V_56 = F_27 ( V_31 - V_30 ,
V_55 -> V_49 , V_55 -> V_50 , V_29 -> V_39 ) ;
V_29 -> V_40 = V_41 ;
return 1 ;
}
static int F_28 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_52 * V_53 ;
const struct V_46 * V_47 ;
V_53 = F_11 ( V_29 , V_30 , V_31 , sizeof( * V_53 ) ) ;
if ( V_53 == NULL )
return 0 ;
V_47 = F_23 ( V_29 ) ;
V_53 -> V_56 = 0 ;
V_29 -> V_39 = F_19 ( V_53 , V_31 - V_30 , 0 ) ;
V_53 -> V_56 = F_24 ( & V_47 -> V_49 , & V_47 -> V_50 ,
V_31 - V_30 , V_57 ,
V_29 -> V_39 ) ;
V_29 -> V_40 = V_41 ;
return 1 ;
}
static int F_29 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 , int V_58 )
{
struct V_59 * V_60 ;
const struct V_54 * V_55 ;
T_1 V_61 ;
V_60 = F_11 ( V_29 , V_30 , V_31 , sizeof( * V_60 ) ) ;
if ( V_60 == NULL )
return 0 ;
V_55 = F_26 ( V_29 ) ;
V_61 = F_30 ( V_60 -> V_62 ) ;
if ( V_58 || V_60 -> V_56 ) {
V_60 -> V_56 = 0 ;
if ( V_58 ) {
if ( V_61 == 0 )
V_29 -> V_39 = F_19 ( V_60 , V_31 - V_30 , 0 ) ;
else if ( ( V_61 >= sizeof( * V_60 ) ) && ( V_61 <= V_31 - V_30 ) )
V_29 -> V_39 = F_19 ( V_60 , V_61 , 0 ) ;
else
goto V_63;
} else {
if ( V_61 != V_31 - V_30 )
goto V_63;
V_29 -> V_39 = F_19 ( V_60 , V_61 , 0 ) ;
}
V_60 -> V_56 = F_31 ( V_55 -> V_49 , V_55 -> V_50 ,
V_61 , V_55 -> V_64 ,
V_29 -> V_39 ) ;
if ( ! V_60 -> V_56 )
V_60 -> V_56 = V_65 ;
}
V_29 -> V_40 = V_41 ;
V_63:
return 1 ;
}
static int F_32 ( struct V_28 * V_29 ,
unsigned int V_30 , unsigned int V_31 , int V_58 )
{
struct V_59 * V_60 ;
const struct V_46 * V_47 ;
T_1 V_61 ;
V_60 = F_11 ( V_29 , V_30 , V_31 , sizeof( * V_60 ) ) ;
if ( V_60 == NULL )
return 0 ;
V_47 = F_23 ( V_29 ) ;
V_61 = F_30 ( V_60 -> V_62 ) ;
V_60 -> V_56 = 0 ;
if ( V_58 ) {
if ( V_61 == 0 )
V_29 -> V_39 = F_19 ( V_60 , V_31 - V_30 , 0 ) ;
else if ( ( V_61 >= sizeof( * V_60 ) ) && ( V_61 <= V_31 - V_30 ) )
V_29 -> V_39 = F_19 ( V_60 , V_61 , 0 ) ;
else
goto V_63;
} else {
if ( V_61 != V_31 - V_30 )
goto V_63;
V_29 -> V_39 = F_19 ( V_60 , V_61 , 0 ) ;
}
V_60 -> V_56 = F_24 ( & V_47 -> V_49 , & V_47 -> V_50 , V_61 ,
V_58 ? V_66 : V_67 ,
V_29 -> V_39 ) ;
if ( ! V_60 -> V_56 )
V_60 -> V_56 = V_65 ;
V_29 -> V_40 = V_41 ;
V_63:
return 1 ;
}
static int F_33 ( struct V_28 * V_29 , T_2 V_27 )
{
const struct V_54 * V_55 ;
int V_33 ;
V_33 = F_12 ( V_29 ) ;
if ( ! F_13 ( V_29 , sizeof( * V_55 ) + V_33 ) )
goto V_68;
V_55 = F_26 ( V_29 ) ;
switch ( V_55 -> V_69 & F_34 ( V_70 ) ? 0 : V_55 -> V_64 ) {
case V_71 :
if ( V_27 & V_72 )
if ( ! F_18 ( V_29 , V_55 -> V_30 * 4 ,
F_30 ( V_55 -> V_73 ) ) )
goto V_68;
break;
case V_74 :
if ( V_27 & V_75 )
if ( ! F_21 ( V_29 , V_55 -> V_30 * 4 ,
F_30 ( V_55 -> V_73 ) ) )
goto V_68;
break;
case V_57 :
if ( V_27 & V_76 )
if ( ! F_25 ( V_29 , V_55 -> V_30 * 4 ,
F_30 ( V_55 -> V_73 ) ) )
goto V_68;
break;
case V_67 :
if ( V_27 & V_77 )
if ( ! F_29 ( V_29 , V_55 -> V_30 * 4 ,
F_30 ( V_55 -> V_73 ) , 0 ) )
goto V_68;
break;
case V_66 :
if ( V_27 & V_78 )
if ( ! F_29 ( V_29 , V_55 -> V_30 * 4 ,
F_30 ( V_55 -> V_73 ) , 1 ) )
goto V_68;
break;
}
if ( V_27 & V_79 ) {
if ( F_14 ( V_29 ) &&
! F_15 ( V_29 , sizeof( * V_55 ) + V_33 ) &&
F_16 ( V_29 , 0 , 0 , V_35 ) )
goto V_68;
F_35 ( F_26 ( V_29 ) ) ;
}
return 1 ;
V_68:
return 0 ;
}
static int F_36 ( struct V_80 * V_81 ,
unsigned int V_82 , unsigned int * V_83 )
{
int V_84 , V_62 , V_85 ;
unsigned char * V_86 = ( void * ) V_81 ;
V_84 = sizeof( * V_81 ) ;
V_62 = V_82 - V_84 ;
while ( V_62 > 1 ) {
switch ( V_86 [ V_84 ] ) {
case V_87 :
V_85 = 1 ;
break;
case V_88 :
V_85 = V_86 [ V_84 + 1 ] + 2 ;
if ( V_85 != 6 || V_62 < 6 || ( V_84 & 3 ) != 2 )
return 0 ;
* V_83 = F_37 ( * ( V_89 * ) ( V_86 + V_84 + 2 ) ) ;
goto V_90;
default:
V_85 = V_86 [ V_84 + 1 ] + 2 ;
if ( V_85 > V_62 )
goto V_90;
break;
}
V_84 += V_85 ;
V_62 -= V_85 ;
}
V_90:
return 1 ;
}
static int F_38 ( struct V_28 * V_29 , T_2 V_27 )
{
struct V_46 * V_47 ;
struct V_80 * V_81 ;
unsigned int V_34 , V_82 ;
unsigned int V_83 ;
int V_33 ;
T_3 V_91 ;
V_33 = F_12 ( V_29 ) ;
V_34 = sizeof( * V_47 ) ;
if ( ! F_13 ( V_29 , V_34 + V_33 ) )
goto V_68;
V_47 = F_23 ( V_29 ) ;
V_83 = F_30 ( V_47 -> V_92 ) ;
V_91 = V_47 -> V_91 ;
do {
switch ( V_91 ) {
case V_93 :
goto V_94;
case V_95 :
case V_96 :
case V_97 :
if ( ! F_13 ( V_29 , V_34 + sizeof( * V_81 ) + V_33 ) )
goto V_68;
V_81 = ( void * ) ( F_17 ( V_29 ) + V_34 ) ;
V_82 = F_39 ( V_81 ) ;
if ( ! F_13 ( V_29 , V_34 + V_82 + V_33 ) )
goto V_68;
V_81 = ( void * ) ( F_17 ( V_29 ) + V_34 ) ;
if ( ( V_91 == V_96 ) &&
! ( F_36 ( V_81 , V_82 , & V_83 ) ) )
goto V_68;
V_91 = V_81 -> V_91 ;
V_34 += V_82 ;
break;
case V_51 :
if ( V_27 & V_72 )
if ( ! F_22 ( V_29 ,
V_34 , V_83 + sizeof( * V_47 ) ) )
goto V_68;
goto V_90;
case V_57 :
if ( V_27 & V_76 )
if ( ! F_28 ( V_29 ,
V_34 , V_83 + sizeof( * V_47 ) ) )
goto V_68;
goto V_90;
case V_67 :
if ( V_27 & V_77 )
if ( ! F_32 ( V_29 , V_34 ,
V_83 + sizeof( * V_47 ) , 0 ) )
goto V_68;
goto V_90;
case V_66 :
if ( V_27 & V_78 )
if ( ! F_32 ( V_29 , V_34 ,
V_83 + sizeof( * V_47 ) , 1 ) )
goto V_68;
goto V_90;
default:
goto V_94;
}
} while ( F_13 ( V_29 , V_34 + 1 + V_33 ) );
V_90:
V_94:
return 1 ;
V_68:
return 0 ;
}
static int V_14 ( struct V_28 * V_29 ,
const struct V_6 * V_7 , struct V_98 * V_99 )
{
struct V_14 * V_15 = V_7 -> V_100 ;
int V_26 ;
T_2 V_27 ;
F_40 ( & V_15 -> V_24 ) ;
V_15 -> V_101 . V_102 = V_103 ;
F_41 ( & V_15 -> V_104 , V_29 ) ;
V_26 = V_15 -> V_25 ;
V_27 = V_15 -> V_27 ;
F_42 ( & V_15 -> V_24 ) ;
if ( F_43 ( V_26 == V_105 ) )
goto V_106;
switch ( F_44 ( V_29 ) ) {
case F_45 ( V_107 ) :
if ( ! F_33 ( V_29 , V_27 ) )
goto V_106;
break;
case F_45 ( V_108 ) :
if ( ! F_38 ( V_29 , V_27 ) )
goto V_106;
break;
}
return V_26 ;
V_106:
F_40 ( & V_15 -> V_24 ) ;
V_15 -> V_109 . V_110 ++ ;
F_42 ( & V_15 -> V_24 ) ;
return V_105 ;
}
static int F_46 ( struct V_28 * V_29 ,
struct V_6 * V_7 , int V_9 , int V_111 )
{
unsigned char * V_112 = F_47 ( V_29 ) ;
struct V_14 * V_15 = V_7 -> V_100 ;
struct V_12 V_113 = {
. V_27 = V_15 -> V_27 ,
. V_21 = V_15 -> V_114 ,
. V_26 = V_15 -> V_25 ,
. V_115 = V_15 -> V_116 - V_111 ,
. V_117 = V_15 -> V_118 - V_9 ,
} ;
struct V_119 V_120 ;
if ( F_48 ( V_29 , V_20 , sizeof( V_113 ) , & V_113 ) )
goto V_121;
V_120 . V_122 = F_49 ( V_103 - V_15 -> V_101 . V_122 ) ;
V_120 . V_102 = F_49 ( V_103 - V_15 -> V_101 . V_102 ) ;
V_120 . V_123 = F_49 ( V_15 -> V_101 . V_123 ) ;
if ( F_48 ( V_29 , V_124 , sizeof( V_120 ) , & V_120 ) )
goto V_121;
return V_29 -> V_62 ;
V_121:
F_50 ( V_29 , V_112 ) ;
return - 1 ;
}
static int T_4 F_51 ( void )
{
return F_52 ( & V_125 , V_126 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_125 ) ;
}
