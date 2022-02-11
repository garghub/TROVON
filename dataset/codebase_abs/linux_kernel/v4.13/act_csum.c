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
V_19 = F_3 ( V_12 , V_13 , V_3 , V_21 , NULL ) ;
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
if ( F_25 ( V_32 ) && F_26 ( V_32 ) -> V_58 & V_59 )
return 1 ;
V_55 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_55 ) ) ;
if ( V_55 == NULL )
return 0 ;
V_57 = F_27 ( V_32 ) ;
V_55 -> V_60 = 0 ;
V_32 -> V_41 = F_18 ( V_55 , V_34 - V_33 , 0 ) ;
V_55 -> V_60 = F_28 ( V_34 - V_33 ,
V_57 -> V_51 , V_57 -> V_52 , V_32 -> V_41 ) ;
V_32 -> V_42 = V_43 ;
return 1 ;
}
static int F_29 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
struct V_54 * V_55 ;
const struct V_48 * V_49 ;
if ( F_25 ( V_32 ) && F_26 ( V_32 ) -> V_58 & V_61 )
return 1 ;
V_55 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_55 ) ) ;
if ( V_55 == NULL )
return 0 ;
V_49 = F_22 ( V_32 ) ;
V_55 -> V_60 = 0 ;
V_32 -> V_41 = F_18 ( V_55 , V_34 - V_33 , 0 ) ;
V_55 -> V_60 = F_23 ( & V_49 -> V_51 , & V_49 -> V_52 ,
V_34 - V_33 , V_62 ,
V_32 -> V_41 ) ;
V_32 -> V_42 = V_43 ;
return 1 ;
}
static int F_30 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 , int V_63 )
{
struct V_64 * V_65 ;
const struct V_56 * V_57 ;
T_1 V_66 ;
if ( F_25 ( V_32 ) && F_26 ( V_32 ) -> V_58 & V_67 )
return 1 ;
V_65 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_65 ) ) ;
if ( V_65 == NULL )
return 0 ;
V_57 = F_27 ( V_32 ) ;
V_66 = F_31 ( V_65 -> V_68 ) ;
if ( V_63 || V_65 -> V_60 ) {
V_65 -> V_60 = 0 ;
if ( V_63 ) {
if ( V_66 == 0 )
V_32 -> V_41 = F_18 ( V_65 , V_34 - V_33 , 0 ) ;
else if ( ( V_66 >= sizeof( * V_65 ) ) && ( V_66 <= V_34 - V_33 ) )
V_32 -> V_41 = F_18 ( V_65 , V_66 , 0 ) ;
else
goto V_69;
} else {
if ( V_66 != V_34 - V_33 )
goto V_69;
V_32 -> V_41 = F_18 ( V_65 , V_66 , 0 ) ;
}
V_65 -> V_60 = F_32 ( V_57 -> V_51 , V_57 -> V_52 ,
V_66 , V_57 -> V_70 ,
V_32 -> V_41 ) ;
if ( ! V_65 -> V_60 )
V_65 -> V_60 = V_71 ;
}
V_32 -> V_42 = V_43 ;
V_69:
return 1 ;
}
static int F_33 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 , int V_63 )
{
struct V_64 * V_65 ;
const struct V_48 * V_49 ;
T_1 V_66 ;
if ( F_25 ( V_32 ) && F_26 ( V_32 ) -> V_58 & V_67 )
return 1 ;
V_65 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_65 ) ) ;
if ( V_65 == NULL )
return 0 ;
V_49 = F_22 ( V_32 ) ;
V_66 = F_31 ( V_65 -> V_68 ) ;
V_65 -> V_60 = 0 ;
if ( V_63 ) {
if ( V_66 == 0 )
V_32 -> V_41 = F_18 ( V_65 , V_34 - V_33 , 0 ) ;
else if ( ( V_66 >= sizeof( * V_65 ) ) && ( V_66 <= V_34 - V_33 ) )
V_32 -> V_41 = F_18 ( V_65 , V_66 , 0 ) ;
else
goto V_69;
} else {
if ( V_66 != V_34 - V_33 )
goto V_69;
V_32 -> V_41 = F_18 ( V_65 , V_66 , 0 ) ;
}
V_65 -> V_60 = F_23 ( & V_49 -> V_51 , & V_49 -> V_52 , V_66 ,
V_63 ? V_72 : V_73 ,
V_32 -> V_41 ) ;
if ( ! V_65 -> V_60 )
V_65 -> V_60 = V_71 ;
V_32 -> V_42 = V_43 ;
V_69:
return 1 ;
}
static int F_34 ( struct V_31 * V_32 , unsigned int V_33 ,
unsigned int V_34 )
{
struct V_74 * V_75 ;
if ( F_25 ( V_32 ) && F_26 ( V_32 ) -> V_58 & V_76 )
return 1 ;
V_75 = F_12 ( V_32 , V_33 , V_34 , sizeof( * V_75 ) ) ;
if ( ! V_75 )
return 0 ;
V_75 -> V_40 = F_35 ( V_32 ,
F_13 ( V_32 ) + V_33 ) ;
V_32 -> V_42 = V_43 ;
V_32 -> V_77 = 0 ;
return 1 ;
}
static int F_36 ( struct V_31 * V_32 , T_2 V_30 )
{
const struct V_56 * V_57 ;
int V_36 ;
V_36 = F_13 ( V_32 ) ;
if ( ! F_14 ( V_32 , sizeof( * V_57 ) + V_36 ) )
goto V_78;
V_57 = F_27 ( V_32 ) ;
switch ( V_57 -> V_79 & F_37 ( V_80 ) ? 0 : V_57 -> V_70 ) {
case V_81 :
if ( V_30 & V_82 )
if ( ! F_17 ( V_32 , V_57 -> V_33 * 4 ,
F_31 ( V_57 -> V_83 ) ) )
goto V_78;
break;
case V_84 :
if ( V_30 & V_85 )
if ( ! F_20 ( V_32 , V_57 -> V_33 * 4 ,
F_31 ( V_57 -> V_83 ) ) )
goto V_78;
break;
case V_62 :
if ( V_30 & V_86 )
if ( ! F_24 ( V_32 , V_57 -> V_33 * 4 ,
F_31 ( V_57 -> V_83 ) ) )
goto V_78;
break;
case V_73 :
if ( V_30 & V_87 )
if ( ! F_30 ( V_32 , V_57 -> V_33 * 4 ,
F_31 ( V_57 -> V_83 ) , 0 ) )
goto V_78;
break;
case V_72 :
if ( V_30 & V_88 )
if ( ! F_30 ( V_32 , V_57 -> V_33 * 4 ,
F_31 ( V_57 -> V_83 ) , 1 ) )
goto V_78;
break;
case V_89 :
if ( ( V_30 & V_90 ) &&
! F_34 ( V_32 , V_57 -> V_33 * 4 , F_31 ( V_57 -> V_83 ) ) )
goto V_78;
break;
}
if ( V_30 & V_91 ) {
if ( F_15 ( V_32 , sizeof( * V_57 ) + V_36 ) )
goto V_78;
F_38 ( F_27 ( V_32 ) ) ;
}
return 1 ;
V_78:
return 0 ;
}
static int F_39 ( struct V_92 * V_93 , unsigned int V_94 ,
unsigned int * V_95 )
{
int V_96 , V_68 , V_97 ;
unsigned char * V_98 = ( void * ) V_93 ;
V_96 = sizeof( * V_93 ) ;
V_68 = V_94 - V_96 ;
while ( V_68 > 1 ) {
switch ( V_98 [ V_96 ] ) {
case V_99 :
V_97 = 1 ;
break;
case V_100 :
V_97 = V_98 [ V_96 + 1 ] + 2 ;
if ( V_97 != 6 || V_68 < 6 || ( V_96 & 3 ) != 2 )
return 0 ;
* V_95 = F_40 ( * ( V_101 * ) ( V_98 + V_96 + 2 ) ) ;
goto V_102;
default:
V_97 = V_98 [ V_96 + 1 ] + 2 ;
if ( V_97 > V_68 )
goto V_102;
break;
}
V_96 += V_97 ;
V_68 -= V_97 ;
}
V_102:
return 1 ;
}
static int F_41 ( struct V_31 * V_32 , T_2 V_30 )
{
struct V_48 * V_49 ;
struct V_92 * V_93 ;
unsigned int V_37 , V_94 ;
unsigned int V_95 ;
int V_36 ;
T_3 V_103 ;
V_36 = F_13 ( V_32 ) ;
V_37 = sizeof( * V_49 ) ;
if ( ! F_14 ( V_32 , V_37 + V_36 ) )
goto V_78;
V_49 = F_22 ( V_32 ) ;
V_95 = F_31 ( V_49 -> V_104 ) ;
V_103 = V_49 -> V_103 ;
do {
switch ( V_103 ) {
case V_105 :
goto V_106;
case V_107 :
case V_108 :
case V_109 :
if ( ! F_14 ( V_32 , V_37 + sizeof( * V_93 ) + V_36 ) )
goto V_78;
V_93 = ( void * ) ( F_16 ( V_32 ) + V_37 ) ;
V_94 = F_42 ( V_93 ) ;
if ( ! F_14 ( V_32 , V_37 + V_94 + V_36 ) )
goto V_78;
V_93 = ( void * ) ( F_16 ( V_32 ) + V_37 ) ;
if ( ( V_103 == V_108 ) &&
! ( F_39 ( V_93 , V_94 , & V_95 ) ) )
goto V_78;
V_103 = V_93 -> V_103 ;
V_37 += V_94 ;
break;
case V_53 :
if ( V_30 & V_82 )
if ( ! F_21 ( V_32 ,
V_37 , V_95 + sizeof( * V_49 ) ) )
goto V_78;
goto V_102;
case V_62 :
if ( V_30 & V_86 )
if ( ! F_29 ( V_32 ,
V_37 , V_95 + sizeof( * V_49 ) ) )
goto V_78;
goto V_102;
case V_73 :
if ( V_30 & V_87 )
if ( ! F_33 ( V_32 , V_37 ,
V_95 + sizeof( * V_49 ) , 0 ) )
goto V_78;
goto V_102;
case V_72 :
if ( V_30 & V_88 )
if ( ! F_33 ( V_32 , V_37 ,
V_95 + sizeof( * V_49 ) , 1 ) )
goto V_78;
goto V_102;
case V_89 :
if ( ( V_30 & V_90 ) &&
! F_34 ( V_32 , V_37 , V_95 + sizeof( * V_49 ) ) )
goto V_78;
goto V_102;
default:
goto V_106;
}
} while ( F_14 ( V_32 , V_37 + 1 + V_36 ) );
V_102:
V_106:
return 1 ;
V_78:
return 0 ;
}
static int V_16 ( struct V_31 * V_32 , const struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_16 * V_17 = F_8 ( V_6 ) ;
int V_29 ;
T_2 V_30 ;
F_43 ( & V_17 -> V_27 ) ;
F_44 ( & V_17 -> V_112 ) ;
F_45 ( & V_17 -> V_113 , V_32 ) ;
V_29 = V_17 -> V_28 ;
V_30 = V_17 -> V_30 ;
F_46 ( & V_17 -> V_27 ) ;
if ( F_47 ( V_29 == V_114 ) )
goto V_115;
switch ( F_48 ( V_32 ) ) {
case F_49 ( V_116 ) :
if ( ! F_36 ( V_32 , V_30 ) )
goto V_115;
break;
case F_49 ( V_117 ) :
if ( ! F_41 ( V_32 , V_30 ) )
goto V_115;
break;
}
return V_29 ;
V_115:
F_43 ( & V_17 -> V_27 ) ;
V_17 -> V_118 . V_119 ++ ;
F_46 ( & V_17 -> V_27 ) ;
return V_114 ;
}
static int F_50 ( struct V_31 * V_32 , struct V_5 * V_6 , int V_8 ,
int V_120 )
{
unsigned char * V_121 = F_51 ( V_32 ) ;
struct V_16 * V_17 = F_8 ( V_6 ) ;
struct V_14 V_122 = {
. V_30 = V_17 -> V_30 ,
. V_23 = V_17 -> V_123 ,
. V_29 = V_17 -> V_28 ,
. V_124 = V_17 -> V_125 - V_120 ,
. V_126 = V_17 -> V_127 - V_8 ,
} ;
struct V_128 V_129 ;
if ( F_52 ( V_32 , V_22 , sizeof( V_122 ) , & V_122 ) )
goto V_130;
F_53 ( & V_129 , & V_17 -> V_112 ) ;
if ( F_54 ( V_32 , V_131 , sizeof( V_129 ) , & V_129 , V_132 ) )
goto V_130;
return V_32 -> V_68 ;
V_130:
F_55 ( V_32 , V_121 ) ;
return - 1 ;
}
static int F_56 ( struct V_1 * V_1 , struct V_31 * V_32 ,
struct V_133 * V_134 , int type ,
const struct V_135 * V_136 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_57 ( V_10 , V_32 , V_134 , type , V_136 ) ;
}
static int F_58 ( struct V_1 * V_1 , struct V_5 * * V_6 , T_2 V_23 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_59 ( V_10 , V_6 , V_23 ) ;
}
static T_4 int F_60 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
return F_61 ( V_10 , & V_24 , V_137 ) ;
}
static void T_5 F_62 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_1 , V_11 ) ;
F_63 ( V_10 ) ;
}
static int T_6 F_64 ( void )
{
return F_65 ( & V_24 , & V_138 ) ;
}
static void T_7 F_66 ( void )
{
F_67 ( & V_24 , & V_138 ) ;
}
