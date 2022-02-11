static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline enum V_5
F_3 ( struct V_6 * V_7 )
{
return (enum V_5 )
F_4 ( & V_7 -> V_8 , V_9 , V_10 ) ;
}
static void F_5 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_15 ;
F_6 ( & V_7 -> V_16 ) ;
}
static int F_7 ( struct V_6 * V_7 , char * V_17 , T_1 V_18 )
{
struct V_13 * V_14 = V_7 -> V_19 ;
int V_20 ;
V_14 -> V_21 = V_18 < F_8 ( V_7 -> V_22 . V_23 . V_24 ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_18 ;
if ( V_14 -> V_27 == NULL )
V_14 -> V_27 = ( void * ) 0xDEADBABE ;
F_10 ( & V_7 -> V_16 ) ;
V_20 = F_11 ( V_7 -> V_29 -> V_30 , V_14 , V_31 ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
V_20 = F_13 ( & V_7 -> V_16 ) ;
if ( F_12 ( V_20 ) ) {
F_14 ( V_7 -> V_29 -> V_30 , V_14 ) ;
return - V_32 ;
}
V_7 -> V_8 = V_10 ;
return V_14 -> V_33 ? V_14 -> V_33 : V_14 -> V_34 ;
}
static int F_15 ( struct V_6 * V_7 )
{
if ( V_7 -> V_22 . V_35 ) {
F_16 ( L_1 ) ;
F_17 ( V_7 -> V_29 -> V_30 ) ;
V_7 -> V_8 = V_10 ;
return - V_36 ;
} else {
F_18 ( L_2 ) ;
return - V_37 ;
}
}
static T_2 F_19 ( struct V_38 * V_38 , const char T_3 * V_27 ,
T_1 V_18 , T_4 * V_39 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
T_2 V_20 ;
char * V_17 ;
F_20 () ;
if ( F_3 ( V_7 ) == V_9 )
return - V_41 ;
V_20 = F_21 ( & V_7 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
switch ( V_7 -> V_45 ) {
case V_46 :
case V_47 :
if ( F_12 ( V_18 < 16 ) ) {
V_20 = - V_48 ;
break;
}
V_17 = F_22 ( V_27 , V_18 ) ;
if ( F_23 ( V_17 ) ) {
V_20 = F_24 ( V_17 ) ;
break;
}
if ( V_7 -> V_45 == V_46 ) {
F_25 ( L_3 ) ;
V_20 = F_26 ( V_7 , V_17 , V_18 ) ;
if ( F_12 ( V_20 < 0 ) )
break;
V_7 -> V_45 = V_47 ;
V_20 = V_18 ;
} else {
F_25 ( L_4 ) ;
V_20 = F_27 ( V_7 , V_17 , V_18 ) ;
if ( F_12 ( V_20 < 0 ) )
break;
V_20 = F_28 ( V_7 ) ;
if ( F_12 ( V_20 ) ) {
V_7 -> V_45 = V_49 ;
break;
}
V_7 -> V_45 = V_50 ;
F_29 ( & V_7 -> V_42 ) ;
V_20 = F_30 ( V_7 ) ;
if ( F_12 ( V_20 < 0 ) ) {
V_7 -> V_45 = V_49 ;
return V_20 ;
}
return V_18 ;
}
break;
case V_50 :
V_17 = NULL ;
F_31 ( & V_7 -> V_22 . V_25 . V_26 ) ;
switch ( F_3 ( V_7 ) ) {
case V_9 :
V_20 = - V_41 ;
goto V_51;
case V_10 :
V_20 = - V_37 ;
goto V_51;
case V_52 :
break;
}
if ( ! ( V_7 -> V_22 . V_23 . V_53 & V_54 ) ) {
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_20 = F_15 ( V_7 ) ;
break;
}
V_18 = F_32 ( V_18 , ( T_1 ) F_8 ( V_7 -> V_22 . V_23 . V_24 ) ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_17 = F_22 ( V_27 , V_18 ) ;
if ( F_23 ( V_17 ) ) {
V_20 = F_24 ( V_17 ) ;
break;
}
F_31 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_3 ( V_7 ) ==
V_9 ) {
V_20 = - V_41 ;
V_51:
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
} else {
V_20 = F_7 ( V_7 , V_17 , V_18 ) ;
}
F_33 ( V_17 ) ;
break;
default:
V_20 = - V_55 ;
break;
}
F_29 ( & V_7 -> V_42 ) ;
return V_20 ;
}
static T_2 F_34 ( struct V_6 * V_7 , char T_3 * V_27 ,
T_1 V_56 )
{
struct V_57 V_58 [ F_35 ( V_7 -> V_22 . V_59 ) ] ;
const T_1 V_60 = V_56 * sizeof *V_58 ;
unsigned V_61 = 0 ;
memset ( V_58 , 0 , V_60 ) ;
do {
V_58 [ V_61 ] . type = V_7 -> V_22 . V_59 [ V_61 ] ;
if ( V_58 [ V_61 ] . type == V_62 ) {
V_58 [ V_61 ] . V_63 . V_23 = V_7 -> V_22 . V_23 ;
V_7 -> V_8 = V_52 ;
}
} while ( ++ V_61 < V_56 );
V_7 -> V_22 . V_64 -= V_56 ;
if ( V_7 -> V_22 . V_64 )
memmove ( V_7 -> V_22 . V_59 , V_7 -> V_22 . V_59 + V_56 ,
V_7 -> V_22 . V_64 * sizeof * V_7 -> V_22 . V_59 ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
F_29 ( & V_7 -> V_42 ) ;
return F_12 ( F_36 ( V_27 , V_58 , V_60 ) ) ? - V_65 : V_60 ;
}
static T_2 F_37 ( struct V_38 * V_38 , char T_3 * V_27 ,
T_1 V_18 , T_4 * V_39 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
char * V_17 = NULL ;
T_1 V_56 ;
int V_20 ;
F_20 () ;
if ( F_3 ( V_7 ) == V_9 )
return - V_41 ;
V_20 = F_21 ( & V_7 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_7 -> V_45 != V_50 ) {
V_20 = - V_55 ;
goto V_66;
}
F_31 ( & V_7 -> V_22 . V_25 . V_26 ) ;
switch ( F_3 ( V_7 ) ) {
case V_9 :
V_20 = - V_41 ;
break;
case V_10 :
V_56 = V_18 / sizeof( struct V_57 ) ;
if ( F_12 ( ! V_56 ) ) {
V_20 = - V_48 ;
break;
}
if ( ( V_38 -> V_43 & V_44 ) && ! V_7 -> V_22 . V_64 ) {
V_20 = - V_67 ;
break;
}
if ( F_38 ( V_7 -> V_22 . V_25 ,
V_7 -> V_22 . V_64 ) ) {
V_20 = - V_32 ;
break;
}
return F_34 ( V_7 , V_27 ,
F_32 ( V_56 , ( T_1 ) V_7 -> V_22 . V_64 ) ) ;
case V_52 :
if ( V_7 -> V_22 . V_23 . V_53 & V_54 ) {
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_20 = F_15 ( V_7 ) ;
goto V_66;
}
V_18 = F_32 ( V_18 , ( T_1 ) F_8 ( V_7 -> V_22 . V_23 . V_24 ) ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_39 ( V_18 ) ) {
V_17 = F_40 ( V_18 , V_68 ) ;
if ( F_12 ( ! V_17 ) ) {
V_20 = - V_69 ;
goto V_66;
}
}
F_31 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_3 ( V_7 ) ==
V_9 ) {
V_20 = - V_41 ;
break;
}
V_20 = F_7 ( V_7 , V_17 , V_18 ) ;
if ( F_39 ( V_20 > 0 ) && F_12 ( F_36 ( V_27 , V_17 , V_18 ) ) )
V_20 = - V_65 ;
goto V_66;
default:
V_20 = - V_55 ;
break;
}
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_66:
F_29 ( & V_7 -> V_42 ) ;
F_33 ( V_17 ) ;
return V_20 ;
}
static int F_41 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_6 * V_7 = V_70 -> V_71 ;
F_20 () ;
if ( F_12 ( V_7 -> V_45 == V_49 ) )
return - V_72 ;
V_38 -> V_40 = V_7 ;
F_42 ( V_7 ) ;
return 0 ;
}
static int F_43 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
F_20 () ;
F_44 ( V_7 ) ;
return 0 ;
}
static long F_45 ( struct V_38 * V_38 , unsigned V_73 , unsigned long V_74 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
struct V_75 * V_29 = V_7 -> V_29 ;
long V_20 ;
F_20 () ;
if ( V_73 == V_76 ) {
struct V_1 * V_77 = V_7 -> V_77 ;
V_20 = V_77 ? F_46 ( V_77 , V_74 ) : - V_78 ;
} else if ( V_29 && V_29 -> V_79 -> V_80 ) {
V_20 = V_29 -> V_79 -> V_80 ( V_29 , V_73 , V_74 ) ;
} else {
V_20 = - V_81 ;
}
return V_20 ;
}
static unsigned int F_47 ( struct V_38 * V_38 , T_5 * V_82 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
unsigned int V_83 = V_84 ;
int V_20 ;
F_48 ( V_38 , & V_7 -> V_22 . V_25 , V_82 ) ;
V_20 = F_21 ( & V_7 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 < 0 ) )
return V_83 ;
switch ( V_7 -> V_45 ) {
case V_46 :
case V_47 :
V_83 |= V_85 ;
break;
case V_50 :
switch ( V_7 -> V_8 ) {
case V_10 :
if ( V_7 -> V_22 . V_64 )
V_83 |= V_86 ;
break;
case V_52 :
case V_9 :
V_83 |= ( V_86 | V_85 ) ;
break;
}
case V_49 :
break;
case V_87 :
break;
}
F_29 ( & V_7 -> V_42 ) ;
return V_83 ;
}
static void F_49 ( struct V_11 * V_88 , struct V_13 * V_14 )
{
F_20 () ;
if ( F_39 ( V_14 -> V_15 ) ) {
struct V_89 * V_12 = V_88 -> V_90 ;
V_12 -> V_33 = V_14 -> V_33 ? V_14 -> V_33 : V_14 -> V_34 ;
F_50 ( V_14 -> V_15 ) ;
}
}
static void F_51 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = F_2 ( V_92 , struct V_93 ,
V_92 ) ;
int V_20 = V_94 -> V_14 -> V_33 ? V_94 -> V_14 -> V_33 :
V_94 -> V_14 -> V_34 ;
bool V_95 = V_94 -> V_96 -> V_97 & V_98 ;
if ( V_94 -> V_99 && V_20 > 0 ) {
F_52 ( V_94 -> V_100 ) ;
V_20 = F_53 ( V_94 -> V_27 , V_20 , & V_94 -> V_17 ) ;
if ( V_20 != V_94 -> V_14 -> V_34 && F_54 ( & V_94 -> V_17 ) )
V_20 = - V_65 ;
F_55 ( V_94 -> V_100 ) ;
}
V_94 -> V_96 -> V_101 ( V_94 -> V_96 , V_20 , V_20 ) ;
if ( V_94 -> V_7 -> V_102 && ! V_95 )
F_56 ( V_94 -> V_7 -> V_102 , 1 ) ;
F_57 ( V_94 -> V_12 , V_94 -> V_14 ) ;
if ( V_94 -> V_99 )
F_33 ( V_94 -> V_103 ) ;
F_33 ( V_94 -> V_27 ) ;
F_33 ( V_94 ) ;
}
static void F_58 ( struct V_11 * V_88 ,
struct V_13 * V_14 )
{
struct V_93 * V_94 = V_14 -> V_15 ;
F_20 () ;
F_59 ( & V_94 -> V_92 , F_51 ) ;
F_60 ( & V_94 -> V_92 ) ;
}
static T_2 F_61 ( struct V_38 * V_38 , struct V_93 * V_94 )
{
struct V_104 * V_105 = V_38 -> V_40 ;
struct V_13 * V_14 ;
struct V_89 * V_12 ;
char * V_17 = NULL ;
T_2 V_20 , V_106 = - V_48 ;
int V_107 ;
if ( F_62 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_12 = V_105 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 )
return - V_67 ;
V_20 = F_63 ( V_105 -> V_82 , ( V_12 = V_105 -> V_12 ) ) ;
if ( V_20 )
return - V_32 ;
}
V_107 = ( ! V_94 -> V_99 == ! V_105 -> V_108 ) ;
if ( V_107 && V_105 -> V_109 )
return - V_48 ;
if ( ! V_107 ) {
struct V_75 * V_29 = V_105 -> V_7 -> V_29 ;
T_1 V_110 ;
F_31 ( & V_105 -> V_7 -> V_111 ) ;
if ( V_105 -> V_12 != V_12 ) {
F_9 ( & V_105 -> V_7 -> V_111 ) ;
return - V_112 ;
}
V_106 = F_54 ( & V_94 -> V_17 ) ;
if ( V_94 -> V_99 )
V_106 = F_64 ( V_29 , V_12 -> V_12 , V_106 ) ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_17 = F_40 ( V_106 , V_68 ) ;
if ( F_12 ( ! V_17 ) )
return - V_69 ;
if ( ! V_94 -> V_99 ) {
V_110 = F_65 ( V_17 , V_106 , & V_94 -> V_17 ) ;
if ( V_110 != V_106 ) {
V_20 = - V_65 ;
goto error;
}
}
}
V_20 = F_21 ( & V_105 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 ) )
goto error;
F_31 ( & V_105 -> V_7 -> V_111 ) ;
if ( V_105 -> V_12 != V_12 ) {
V_20 = - V_112 ;
} else if ( V_107 ) {
if ( F_39 ( V_105 -> V_12 == V_12 ) && ! F_62 ( ! V_12 -> V_12 ) )
F_17 ( V_12 -> V_12 ) ;
V_20 = - V_113 ;
} else if ( F_12 ( V_106 == - V_48 ) ) {
F_66 ( 1 , L_5 , V_114 ) ;
V_20 = - V_48 ;
} else if ( ! V_94 -> V_115 ) {
F_67 ( V_116 ) ;
bool V_117 = false ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_106 ;
V_14 -> V_15 = & V_116 ;
V_14 -> F_50 = F_49 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 < 0 ) )
goto V_118;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
if ( F_12 ( F_13 ( & V_116 ) ) ) {
F_14 ( V_12 -> V_12 , V_14 ) ;
V_117 = V_12 -> V_33 < 0 ;
}
V_20 = V_117 ? - V_32 : V_12 -> V_33 ;
if ( V_94 -> V_99 && V_20 > 0 ) {
V_20 = F_53 ( V_17 , V_20 , & V_94 -> V_17 ) ;
if ( ! V_20 )
V_20 = - V_65 ;
}
goto V_119;
} else if ( ! ( V_14 = F_68 ( V_12 -> V_12 , V_68 ) ) ) {
V_20 = - V_69 ;
} else {
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_106 ;
V_94 -> V_27 = V_17 ;
V_94 -> V_12 = V_12 -> V_12 ;
V_94 -> V_14 = V_14 ;
V_94 -> V_7 = V_105 -> V_7 ;
V_14 -> V_15 = V_94 ;
V_14 -> F_50 = F_58 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 ) ) {
F_57 ( V_12 -> V_12 , V_14 ) ;
goto V_118;
}
V_20 = - V_120 ;
V_17 = NULL ;
}
V_118:
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_119:
F_29 ( & V_105 -> V_42 ) ;
error:
F_33 ( V_17 ) ;
return V_20 ;
}
static int
F_69 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_70 -> V_71 ;
F_20 () ;
if ( F_62 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_38 -> V_40 = V_105 ;
F_42 ( V_105 -> V_7 ) ;
return 0 ;
}
static int F_70 ( struct V_96 * V_96 )
{
struct V_93 * V_94 = V_96 -> V_121 ;
struct V_104 * V_105 = V_96 -> V_122 -> V_40 ;
int V_74 ;
F_20 () ;
F_31 ( & V_105 -> V_7 -> V_111 ) ;
if ( F_39 ( V_94 && V_94 -> V_12 && V_94 -> V_14 ) )
V_74 = F_14 ( V_94 -> V_12 , V_94 -> V_14 ) ;
else
V_74 = - V_48 ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
return V_74 ;
}
static T_2 F_71 ( struct V_96 * V_96 , struct V_123 * V_124 )
{
struct V_93 V_94 , * V_125 = & V_94 ;
T_2 V_126 ;
F_20 () ;
if ( ! F_72 ( V_96 ) ) {
V_125 = F_40 ( sizeof( V_94 ) , V_68 ) ;
if ( F_12 ( ! V_125 ) )
return - V_69 ;
V_125 -> V_115 = true ;
} else {
V_125 -> V_115 = false ;
}
V_125 -> V_99 = false ;
V_125 -> V_96 = V_96 ;
V_125 -> V_17 = * V_124 ;
V_125 -> V_100 = V_127 -> V_100 ;
V_96 -> V_121 = V_125 ;
if ( V_125 -> V_115 )
F_73 ( V_96 , F_70 ) ;
V_126 = F_61 ( V_96 -> V_122 , V_125 ) ;
if ( V_126 == - V_120 )
return V_126 ;
if ( V_125 -> V_115 )
F_33 ( V_125 ) ;
else
* V_124 = V_125 -> V_17 ;
return V_126 ;
}
static T_2 F_74 ( struct V_96 * V_96 , struct V_123 * V_128 )
{
struct V_93 V_94 , * V_125 = & V_94 ;
T_2 V_126 ;
F_20 () ;
if ( ! F_72 ( V_96 ) ) {
V_125 = F_40 ( sizeof( V_94 ) , V_68 ) ;
if ( F_12 ( ! V_125 ) )
return - V_69 ;
V_125 -> V_115 = true ;
} else {
V_125 -> V_115 = false ;
}
V_125 -> V_99 = true ;
V_125 -> V_96 = V_96 ;
if ( V_125 -> V_115 ) {
V_125 -> V_103 = F_75 ( & V_125 -> V_17 , V_128 , V_68 ) ;
if ( ! V_125 -> V_103 ) {
F_33 ( V_125 ) ;
return - V_69 ;
}
} else {
V_125 -> V_17 = * V_128 ;
V_125 -> V_103 = NULL ;
}
V_125 -> V_100 = V_127 -> V_100 ;
V_96 -> V_121 = V_125 ;
if ( V_125 -> V_115 )
F_73 ( V_96 , F_70 ) ;
V_126 = F_61 ( V_96 -> V_122 , V_125 ) ;
if ( V_126 == - V_120 )
return V_126 ;
if ( V_125 -> V_115 ) {
F_33 ( V_125 -> V_103 ) ;
F_33 ( V_125 ) ;
} else {
* V_128 = V_125 -> V_17 ;
}
return V_126 ;
}
static int
F_76 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_70 -> V_71 ;
F_20 () ;
F_44 ( V_105 -> V_7 ) ;
return 0 ;
}
static long F_77 ( struct V_38 * V_38 , unsigned V_73 ,
unsigned long V_74 )
{
struct V_104 * V_105 = V_38 -> V_40 ;
int V_20 ;
F_20 () ;
if ( F_62 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
F_31 ( & V_105 -> V_7 -> V_111 ) ;
if ( F_39 ( V_105 -> V_12 ) ) {
switch ( V_73 ) {
case V_129 :
V_20 = F_78 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_130 :
F_79 ( V_105 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_131 :
V_20 = F_80 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_132 :
V_20 = V_105 -> V_12 -> V_133 ;
break;
case V_134 :
{
int V_135 ;
struct V_136 * V_137 ;
switch ( V_105 -> V_7 -> V_29 -> V_138 ) {
case V_139 :
V_135 = 2 ;
break;
case V_140 :
V_135 = 1 ;
break;
default:
V_135 = 0 ;
}
V_137 = V_105 -> V_12 -> V_141 [ V_135 ] ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_20 = F_36 ( ( void * ) V_74 , V_137 , sizeof( * V_137 ) ) ;
if ( V_20 )
V_20 = - V_65 ;
return V_20 ;
}
default:
V_20 = - V_81 ;
}
} else {
V_20 = - V_78 ;
}
F_9 ( & V_105 -> V_7 -> V_111 ) ;
return V_20 ;
}
static struct V_70 * T_6
F_81 ( struct V_142 * V_143 , void * V_17 ,
const struct V_144 * V_145 ,
const struct V_146 * V_147 ,
struct V_148 * V_149 )
{
struct V_70 * V_70 ;
F_20 () ;
V_70 = F_82 ( V_143 ) ;
if ( F_39 ( V_70 ) ) {
struct V_150 V_151 = V_152 ;
V_70 -> V_153 = F_83 () ;
V_70 -> V_154 = V_149 -> V_155 ;
V_70 -> V_156 = V_149 -> V_157 ;
V_70 -> V_158 = V_149 -> V_159 ;
V_70 -> V_160 = V_151 ;
V_70 -> V_161 = V_151 ;
V_70 -> V_162 = V_151 ;
V_70 -> V_71 = V_17 ;
if ( V_145 )
V_70 -> V_163 = V_145 ;
if ( V_147 )
V_70 -> V_164 = V_147 ;
}
return V_70 ;
}
static struct V_165 * F_84 ( struct V_142 * V_143 ,
const char * V_166 , void * V_17 ,
const struct V_144 * V_145 )
{
struct V_6 * V_7 = V_143 -> V_167 ;
struct V_165 * V_165 ;
struct V_70 * V_70 ;
F_20 () ;
V_165 = F_85 ( V_143 -> V_168 , V_166 ) ;
if ( F_12 ( ! V_165 ) )
return NULL ;
V_70 = F_81 ( V_143 , V_17 , V_145 , NULL , & V_7 -> V_169 ) ;
if ( F_12 ( ! V_70 ) ) {
F_86 ( V_165 ) ;
return NULL ;
}
F_87 ( V_165 , V_70 ) ;
return V_165 ;
}
static int F_88 ( struct V_142 * V_143 , void * V_170 , int V_171 )
{
struct V_172 * V_17 = V_170 ;
struct V_70 * V_70 ;
struct V_6 * V_7 = V_17 -> V_6 ;
F_20 () ;
V_7 -> V_143 = V_143 ;
V_17 -> V_6 = NULL ;
V_143 -> V_167 = V_7 ;
V_143 -> V_173 = V_174 ;
V_143 -> V_175 = V_176 ;
V_143 -> V_177 = V_178 ;
V_143 -> V_179 = & V_180 ;
V_143 -> V_181 = 1 ;
V_17 -> V_149 . V_155 = V_17 -> V_182 ;
V_70 = F_81 ( V_143 , NULL ,
& V_183 ,
& V_184 ,
& V_17 -> V_149 ) ;
V_143 -> V_168 = F_89 ( V_70 ) ;
if ( F_12 ( ! V_143 -> V_168 ) )
return - V_69 ;
if ( F_12 ( ! F_84 ( V_143 , L_6 , V_7 ,
& V_185 ) ) )
return - V_69 ;
return 0 ;
}
static int F_90 ( struct V_172 * V_17 , char * V_186 )
{
F_20 () ;
if ( ! V_186 || ! * V_186 )
return 0 ;
for (; ; ) {
unsigned long V_74 ;
char * V_187 , * V_188 ;
V_188 = strchr ( V_186 , ',' ) ;
if ( V_188 )
* V_188 = 0 ;
V_187 = strchr ( V_186 , '=' ) ;
if ( F_12 ( ! V_187 ) ) {
F_91 ( L_7 , V_186 ) ;
return - V_48 ;
}
* V_187 = 0 ;
if ( F_92 ( V_187 + 1 , 0 , & V_74 ) ) {
F_91 ( L_8 , V_186 , V_187 + 1 ) ;
return - V_48 ;
}
switch ( V_187 - V_186 ) {
case 13 :
if ( ! memcmp ( V_186 , L_9 , 13 ) )
V_17 -> V_189 = ! ! V_74 ;
else
goto V_190;
break;
case 5 :
if ( ! memcmp ( V_186 , L_10 , 5 ) )
V_17 -> V_182 = ( V_74 & 0555 ) | V_191 ;
else if ( ! memcmp ( V_186 , L_11 , 5 ) )
V_17 -> V_149 . V_155 = ( V_74 & 0666 ) | V_192 ;
else
goto V_190;
break;
case 4 :
if ( ! memcmp ( V_186 , L_12 , 4 ) ) {
V_17 -> V_182 = ( V_74 & 0555 ) | V_191 ;
V_17 -> V_149 . V_155 = ( V_74 & 0666 ) | V_192 ;
} else {
goto V_190;
}
break;
case 3 :
if ( ! memcmp ( V_186 , L_13 , 3 ) ) {
V_17 -> V_149 . V_157 = F_93 ( F_94 () , V_74 ) ;
if ( ! F_95 ( V_17 -> V_149 . V_157 ) ) {
F_91 ( L_14 , V_186 , V_74 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_186 , L_15 , 3 ) ) {
V_17 -> V_149 . V_159 = F_96 ( F_94 () , V_74 ) ;
if ( ! F_97 ( V_17 -> V_149 . V_159 ) ) {
F_91 ( L_14 , V_186 , V_74 ) ;
return - V_48 ;
}
} else {
goto V_190;
}
break;
default:
V_190:
F_91 ( L_16 , V_186 ) ;
return - V_48 ;
}
if ( ! V_188 )
break;
V_186 = V_188 + 1 ;
}
return 0 ;
}
static struct V_165 *
F_98 ( struct V_193 * V_194 , int V_195 ,
const char * V_196 , void * V_186 )
{
struct V_172 V_17 = {
. V_149 = {
. V_155 = V_192 | 0600 ,
. V_157 = V_197 ,
. V_159 = V_198 ,
} ,
. V_182 = V_191 | 0500 ,
. V_189 = false ,
} ;
struct V_165 * V_199 ;
int V_20 ;
void * V_200 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_90 ( & V_17 , V_186 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_99 ( V_20 ) ;
V_7 = F_100 () ;
if ( F_12 ( ! V_7 ) )
return F_99 ( - V_69 ) ;
V_7 -> V_169 = V_17 . V_149 ;
V_7 -> V_189 = V_17 . V_189 ;
V_7 -> V_196 = F_101 ( V_196 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_196 ) ) {
F_102 ( V_7 ) ;
return F_99 ( - V_69 ) ;
}
V_200 = F_103 ( V_196 ) ;
if ( F_23 ( V_200 ) ) {
F_102 ( V_7 ) ;
return F_104 ( V_200 ) ;
}
V_7 -> V_40 = V_200 ;
V_17 . V_6 = V_7 ;
V_199 = F_105 ( V_194 , V_195 , & V_17 , F_88 ) ;
if ( F_23 ( V_199 ) && V_17 . V_6 ) {
F_106 ( V_17 . V_6 ) ;
F_102 ( V_17 . V_6 ) ;
}
return V_199 ;
}
static void
F_107 ( struct V_142 * V_143 )
{
F_20 () ;
F_108 ( V_143 ) ;
if ( V_143 -> V_167 ) {
F_106 ( V_143 -> V_167 ) ;
F_44 ( V_143 -> V_167 ) ;
F_102 ( V_143 -> V_167 ) ;
}
}
static int F_109 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_110 ( & V_201 ) ;
if ( F_39 ( ! V_20 ) )
F_25 ( L_17 ) ;
else
F_91 ( L_18 , V_20 ) ;
return V_20 ;
}
static void F_111 ( void )
{
F_20 () ;
F_25 ( L_19 ) ;
F_112 ( & V_201 ) ;
}
static void F_113 ( struct V_6 * V_7 )
{
F_20 () ;
F_114 ( & V_7 -> V_202 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_20 () ;
F_114 ( & V_7 -> V_202 ) ;
if ( F_115 ( 1 , & V_7 -> V_203 ) == 1 &&
V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_116 ( V_7 ) ;
}
}
static void F_102 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_117 ( & V_7 -> V_202 ) ) ) {
F_25 ( L_20 , V_114 ) ;
F_118 ( V_7 ) ;
F_119 ( F_120 ( & V_7 -> V_22 . V_25 ) ||
F_120 ( & V_7 -> V_16 . V_82 ) ) ;
F_33 ( V_7 -> V_196 ) ;
F_33 ( V_7 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_117 ( & V_7 -> V_203 ) ) {
if ( V_7 -> V_189 ) {
V_7 -> V_45 = V_87 ;
if ( V_7 -> V_204 ) {
F_121 ( V_7 -> V_204 ,
V_7 -> V_205 ) ;
V_7 -> V_204 = NULL ;
}
if ( V_7 -> V_8 == V_52 )
F_15 ( V_7 ) ;
} else {
V_7 -> V_45 = V_49 ;
F_116 ( V_7 ) ;
}
}
if ( F_122 ( & V_7 -> V_203 ) < 0 ) {
V_7 -> V_45 = V_49 ;
F_116 ( V_7 ) ;
}
F_102 ( V_7 ) ;
}
static struct V_6 * F_100 ( void )
{
struct V_6 * V_7 = F_123 ( sizeof *V_7 , V_68 ) ;
if ( F_12 ( ! V_7 ) )
return NULL ;
F_20 () ;
F_124 ( & V_7 -> V_202 , 1 ) ;
F_124 ( & V_7 -> V_203 , 0 ) ;
V_7 -> V_45 = V_46 ;
F_125 ( & V_7 -> V_42 ) ;
F_126 ( & V_7 -> V_111 ) ;
F_127 ( & V_7 -> V_22 . V_25 ) ;
F_128 ( & V_7 -> V_16 ) ;
V_7 -> V_22 . V_35 = 1 ;
return V_7 ;
}
static void F_118 ( struct V_6 * V_7 )
{
F_20 () ;
F_129 ( V_7 ) ;
F_119 ( V_7 -> V_29 ) ;
if ( V_7 -> V_204 )
F_121 ( V_7 -> V_204 , V_7 -> V_205 ) ;
if ( V_7 -> V_102 )
F_130 ( V_7 -> V_102 ) ;
F_33 ( V_7 -> V_206 ) ;
F_33 ( V_7 -> V_207 ) ;
F_33 ( V_7 -> V_208 ) ;
}
static void F_116 ( struct V_6 * V_7 )
{
F_20 () ;
F_118 ( V_7 ) ;
V_7 -> V_204 = NULL ;
V_7 -> V_206 = NULL ;
V_7 -> V_209 = NULL ;
V_7 -> V_207 = NULL ;
V_7 -> V_208 = NULL ;
V_7 -> V_210 = 0 ;
V_7 -> V_211 = 0 ;
V_7 -> V_212 = 0 ;
V_7 -> V_213 = 0 ;
V_7 -> V_214 = 0 ;
V_7 -> V_215 = 0 ;
V_7 -> V_205 = 0 ;
V_7 -> V_22 . V_64 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_195 = 0 ;
}
static int F_131 ( struct V_6 * V_7 , struct V_216 * V_217 )
{
struct V_218 * * V_219 ;
int V_220 ;
F_20 () ;
if ( F_62 ( V_7 -> V_45 != V_50
|| F_132 ( V_221 , & V_7 -> V_195 ) ) )
return - V_55 ;
V_220 = F_133 ( V_217 , V_7 -> V_214 ) ;
if ( F_12 ( V_220 < 0 ) )
return V_220 ;
V_7 -> V_19 = F_68 ( V_217 -> V_29 -> V_30 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_69 ;
V_7 -> V_19 -> F_50 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_219 = V_7 -> V_208 ;
if ( V_219 ) {
for (; * V_219 ; ++ V_219 ) {
struct V_222 * V_223 = ( * V_219 ) -> V_224 ;
int V_225 = V_220 ;
for (; V_223 -> V_226 ; ++ V_225 , ++ V_223 )
V_223 -> V_225 = V_225 ;
}
}
V_7 -> V_29 = V_217 -> V_29 ;
F_113 ( V_7 ) ;
return 0 ;
}
static void F_134 ( struct V_6 * V_7 )
{
F_20 () ;
if ( ! F_62 ( ! V_7 -> V_29 ) ) {
F_57 ( V_7 -> V_29 -> V_30 , V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_29 = NULL ;
F_135 ( V_221 , & V_7 -> V_195 ) ;
F_102 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_104 * V_105 , * V_204 ;
unsigned V_61 , V_64 ;
F_20 () ;
V_64 = V_7 -> V_205 ;
V_204 = F_136 ( V_64 , sizeof( * V_204 ) , V_68 ) ;
if ( ! V_204 )
return - V_69 ;
V_105 = V_204 ;
for ( V_61 = 1 ; V_61 <= V_64 ; ++ V_61 , ++ V_105 ) {
V_105 -> V_7 = V_7 ;
F_125 ( & V_105 -> V_42 ) ;
F_127 ( & V_105 -> V_82 ) ;
if ( V_7 -> V_227 & V_228 )
sprintf ( V_105 -> V_166 , L_21 , V_7 -> V_229 [ V_61 ] ) ;
else
sprintf ( V_105 -> V_166 , L_22 , V_61 ) ;
V_105 -> V_165 = F_84 ( V_7 -> V_143 , V_105 -> V_166 ,
V_105 ,
& V_230 ) ;
if ( F_12 ( ! V_105 -> V_165 ) ) {
F_121 ( V_204 , V_61 - 1 ) ;
return - V_69 ;
}
}
V_7 -> V_204 = V_204 ;
return 0 ;
}
static void F_121 ( struct V_104 * V_204 , unsigned V_64 )
{
struct V_104 * V_105 = V_204 ;
F_20 () ;
for (; V_64 ; -- V_64 , ++ V_105 ) {
F_119 ( F_137 ( & V_105 -> V_42 ) ||
F_120 ( & V_105 -> V_82 ) ) ;
if ( V_105 -> V_165 ) {
F_138 ( V_105 -> V_165 ) ;
F_86 ( V_105 -> V_165 ) ;
V_105 -> V_165 = NULL ;
}
}
F_33 ( V_204 ) ;
}
static void F_139 ( struct V_1 * V_77 )
{
struct V_89 * V_12 = V_77 -> V_231 ;
struct V_104 * V_105 = V_77 -> V_7 -> V_204 ;
unsigned V_64 = V_77 -> V_7 -> V_205 ;
unsigned long V_195 ;
F_140 ( & V_77 -> V_7 -> V_111 , V_195 ) ;
do {
if ( F_39 ( V_12 -> V_12 ) )
F_141 ( V_12 -> V_12 ) ;
++ V_12 ;
if ( V_105 ) {
V_105 -> V_12 = NULL ;
++ V_105 ;
}
} while ( -- V_64 );
F_142 ( & V_77 -> V_7 -> V_111 , V_195 ) ;
}
static int F_143 ( struct V_1 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_89 * V_12 = V_77 -> V_231 ;
struct V_104 * V_105 = V_7 -> V_204 ;
unsigned V_64 = V_7 -> V_205 ;
unsigned long V_195 ;
int V_20 = 0 ;
F_140 ( & V_77 -> V_7 -> V_111 , V_195 ) ;
do {
struct V_136 * V_232 ;
int V_135 ;
if ( V_7 -> V_29 -> V_138 == V_139 )
V_135 = 2 ;
else if ( V_7 -> V_29 -> V_138 == V_140 )
V_135 = 1 ;
else
V_135 = 0 ;
do {
V_232 = V_12 -> V_141 [ V_135 ] ;
} while ( ! V_232 && -- V_135 >= 0 );
if ( ! V_232 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_90 = V_12 ;
V_12 -> V_12 -> V_137 = V_232 ;
V_20 = F_144 ( V_12 -> V_12 ) ;
if ( F_39 ( ! V_20 ) ) {
V_105 -> V_12 = V_12 ;
V_105 -> V_108 = F_145 ( V_232 ) ;
V_105 -> V_109 = F_146 ( V_232 ) ;
} else {
break;
}
F_147 ( & V_105 -> V_82 ) ;
++ V_12 ;
++ V_105 ;
} while ( -- V_64 );
F_142 ( & V_77 -> V_7 -> V_111 , V_195 ) ;
return V_20 ;
}
static int T_6 F_148 ( char * V_17 , unsigned V_18 ,
T_7 V_233 ,
void * V_234 )
{
struct V_235 * V_236 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_23 ) ;
return - V_48 ;
}
V_28 = V_236 -> V_237 ;
if ( V_18 < V_28 ) {
F_16 ( L_24 ) ;
return - V_48 ;
}
#define F_149 ( T_9 ) 1
#define F_150 ( T_9 ) (val)
#define F_151 ( T_9 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_152 ( type , T_9 ) do { \
pr_vdebug("entity " #type "(%02x)\n", (val)); \
if (unlikely(!__entity_check_ ##type(val))) { \
pr_vdebug("invalid entity's value\n"); \
return -EINVAL; \
} \
ret = entity(FFS_ ##type, &val, _ds, priv); \
if (unlikely(ret < 0)) { \
pr_debug("entity " #type "(%02x); ret = %d\n", \
(val), ret); \
return ret; \
} \
} while (0)
switch ( V_236 -> V_238 ) {
case V_239 :
case V_240 :
case V_241 :
case V_242 :
F_16 ( L_25 ,
V_236 -> V_238 ) ;
return - V_48 ;
case V_243 : {
struct V_244 * V_232 = ( void * ) V_236 ;
F_16 ( L_26 ) ;
if ( V_28 != sizeof *V_232 )
goto V_245;
F_152 ( V_246 , V_232 -> V_247 ) ;
if ( V_232 -> V_248 )
F_152 ( STRING , V_232 -> V_248 ) ;
}
break;
case V_249 : {
struct V_136 * V_232 = ( void * ) V_236 ;
F_16 ( L_27 ) ;
if ( V_28 != V_250 &&
V_28 != V_251 )
goto V_245;
F_152 ( V_252 , V_232 -> V_253 ) ;
}
break;
case V_254 :
F_16 ( L_28 ) ;
if ( V_28 != sizeof( struct V_255 ) )
goto V_245;
break;
case V_256 :
if ( V_28 != sizeof( struct V_257 ) )
goto V_245;
break;
case V_258 : {
struct V_259 * V_232 = ( void * ) V_236 ;
F_16 ( L_29 ) ;
if ( V_28 != sizeof *V_232 )
goto V_245;
if ( V_232 -> V_260 )
F_152 ( STRING , V_232 -> V_260 ) ;
}
break;
case V_261 :
F_16 ( L_30 ) ;
if ( V_28 != sizeof( struct V_262 ) )
goto V_245;
break;
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
F_16 ( L_31 , V_236 -> V_238 ) ;
return - V_48 ;
default:
F_16 ( L_32 , V_236 -> V_238 ) ;
return - V_48 ;
V_245:
F_16 ( L_33 ,
V_236 -> V_237 , V_236 -> V_238 ) ;
return - V_48 ;
}
#undef F_152
#undef V_268
#undef F_149
#undef F_150
#undef F_151
return V_28 ;
}
static int T_6 F_153 ( unsigned V_64 , char * V_17 , unsigned V_18 ,
T_7 V_233 , void * V_234 )
{
const unsigned V_269 = V_18 ;
unsigned long V_133 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_133 == V_64 )
V_17 = NULL ;
V_20 = V_233 ( V_270 , ( T_8 * ) V_133 , ( void * ) V_17 , V_234 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_34 ,
V_133 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_269 - V_18 ;
V_20 = F_148 ( V_17 , V_18 , V_233 , V_234 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_35 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_133 ;
}
}
static int F_154 ( enum V_271 type ,
T_8 * V_272 , struct V_235 * V_137 ,
void * V_234 )
{
struct V_273 * V_274 = V_234 ;
struct V_136 * V_275 ;
F_20 () ;
switch ( type ) {
case V_270 :
break;
case V_276 :
if ( * V_272 >= V_274 -> V_215 )
V_274 -> V_215 = * V_272 + 1 ;
break;
case V_277 :
if ( * V_272 > V_274 -> V_7 -> V_214 )
V_274 -> V_7 -> V_214 = * V_272 ;
break;
case V_278 :
V_275 = ( void * ) V_137 ;
V_274 -> V_205 ++ ;
if ( V_274 -> V_205 >= 15 )
return - V_48 ;
if ( ! V_274 -> V_7 -> V_205 && ! V_274 -> V_7 -> V_215 )
V_274 -> V_7 -> V_229 [ V_274 -> V_205 ] =
V_275 -> V_253 ;
else if ( V_274 -> V_7 -> V_229 [ V_274 -> V_205 ] !=
V_275 -> V_253 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_155 ( enum V_279 * V_280 ,
struct V_281 * V_137 )
{
T_10 V_282 = F_8 ( V_137 -> V_283 ) ;
T_10 V_284 = F_8 ( V_137 -> V_285 ) ;
if ( V_282 != 1 ) {
F_16 ( L_36 ,
V_282 ) ;
return - V_48 ;
}
switch ( V_284 ) {
case 0x4 :
* V_280 = V_286 ;
break;
case 0x5 :
* V_280 = V_287 ;
break;
default:
F_16 ( L_37 , V_284 ) ;
return - V_48 ;
}
return sizeof( * V_137 ) ;
}
static int T_6 F_156 ( char * V_17 , unsigned V_18 ,
enum V_279 type ,
T_10 V_288 ,
T_11 V_233 ,
void * V_234 ,
struct V_281 * V_289 )
{
int V_20 ;
const unsigned V_269 = V_18 ;
F_20 () ;
while ( V_288 -- ) {
V_20 = V_233 ( type , V_289 , V_17 , V_18 , V_234 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 , type ) ;
return V_20 ;
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
return V_269 - V_18 ;
}
static int T_6 F_157 ( unsigned V_64 ,
char * V_17 , unsigned V_18 ,
T_11 V_233 , void * V_234 )
{
const unsigned V_269 = V_18 ;
unsigned long V_133 = 0 ;
F_20 () ;
for ( V_133 = 0 ; V_133 < V_64 ; ++ V_133 ) {
int V_20 ;
enum V_279 type ;
T_10 V_288 ;
struct V_281 * V_137 = ( void * ) V_17 ;
if ( V_18 < sizeof( * V_137 ) )
return - V_48 ;
if ( F_158 ( V_137 -> V_290 ) > V_18 )
return - V_48 ;
V_20 = F_155 ( & type , V_137 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_39 ,
V_133 , V_20 ) ;
return V_20 ;
}
V_288 = F_8 ( V_137 -> V_291 ) ;
if ( type == V_286 &&
( V_288 > 255 || V_137 -> V_292 ) )
return - V_48 ;
V_18 -= V_20 ;
V_17 += V_20 ;
V_20 = F_156 ( V_17 , V_18 , type ,
V_288 , V_233 , V_234 , V_137 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_35 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
return V_269 - V_18 ;
}
static int F_159 ( enum V_279 type ,
struct V_281 * V_289 , void * V_17 ,
unsigned V_18 , void * V_234 )
{
struct V_6 * V_7 = V_234 ;
T_8 V_28 ;
F_20 () ;
switch ( type ) {
case V_286 : {
struct V_293 * V_275 = V_17 ;
int V_61 ;
if ( V_18 < sizeof( * V_275 ) ||
V_275 -> V_294 >= V_7 -> V_215 ||
! V_275 -> V_295 )
return - V_48 ;
for ( V_61 = 0 ; V_61 < F_35 ( V_275 -> V_296 ) ; ++ V_61 )
if ( V_275 -> V_296 [ V_61 ] )
return - V_48 ;
V_28 = sizeof( struct V_293 ) ;
}
break;
case V_287 : {
struct V_297 * V_275 = V_17 ;
T_12 type , V_298 ;
T_10 V_299 ;
if ( V_18 < sizeof( * V_275 ) || V_289 -> V_300 >= V_7 -> V_215 )
return - V_48 ;
V_28 = F_158 ( V_275 -> V_301 ) ;
type = F_158 ( V_275 -> V_302 ) ;
if ( type < V_303 ||
type > V_304 ) {
F_16 ( L_40 ,
type ) ;
return - V_48 ;
}
V_299 = F_8 ( V_275 -> V_305 ) ;
V_298 = F_158 ( * ( T_12 * ) ( ( T_8 * ) V_17 + 10 + V_299 ) ) ;
if ( V_28 != 14 + V_299 + V_298 ) {
F_16 ( L_41 ,
V_28 , V_299 , V_298 , type ) ;
return - V_48 ;
}
++ V_7 -> V_306 ;
V_7 -> V_307 += V_299 * 2 ;
V_7 -> V_308 += V_298 ;
}
break;
default:
F_16 ( L_32 , type ) ;
return - V_48 ;
}
return V_28 ;
}
static int F_26 ( struct V_6 * V_7 ,
char * const V_170 , T_1 V_18 )
{
char * V_17 = V_170 , * V_209 ;
unsigned V_309 = 0 , V_310 [ 3 ] , V_195 ;
int V_20 = - V_48 , V_61 ;
struct V_273 V_274 ;
F_20 () ;
if ( F_160 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_160 ( V_17 ) ) {
case V_311 :
V_195 = V_312 | V_313 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_314 :
V_195 = F_160 ( V_17 + 8 ) ;
V_7 -> V_227 = V_195 ;
if ( V_195 & ~ ( V_312 |
V_313 |
V_315 |
V_316 |
V_228 |
V_317 ) ) {
V_20 = - V_318 ;
goto error;
}
V_17 += 12 ;
V_18 -= 12 ;
break;
default:
goto error;
}
if ( V_195 & V_317 ) {
if ( V_18 < 4 )
goto error;
V_7 -> V_102 =
F_161 ( ( int ) F_160 ( V_17 ) ) ;
if ( F_23 ( V_7 -> V_102 ) ) {
V_20 = F_24 ( V_7 -> V_102 ) ;
V_7 -> V_102 = NULL ;
goto error;
}
V_17 += 4 ;
V_18 -= 4 ;
}
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! ( V_195 & ( 1 << V_61 ) ) ) {
V_310 [ V_61 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_310 [ V_61 ] = F_160 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
if ( V_195 & ( 1 << V_61 ) ) {
V_309 = F_160 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
} ;
V_209 = V_17 ;
V_274 . V_7 = V_7 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! V_310 [ V_61 ] )
continue;
V_274 . V_215 = 0 ;
V_274 . V_205 = 0 ;
V_20 = F_153 ( V_310 [ V_61 ] , V_17 , V_18 ,
F_154 , & V_274 ) ;
if ( V_20 < 0 )
goto error;
if ( ! V_7 -> V_205 && ! V_7 -> V_215 ) {
V_7 -> V_205 = V_274 . V_205 ;
V_7 -> V_215 = V_274 . V_215 ;
} else {
if ( V_7 -> V_205 != V_274 . V_205 ) {
V_20 = - V_48 ;
goto error;
}
if ( V_7 -> V_215 != V_274 . V_215 ) {
V_20 = - V_48 ;
goto error;
}
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_309 ) {
V_20 = F_157 ( V_309 , V_17 , V_18 ,
F_159 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_209 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_206 = V_170 ;
V_7 -> V_209 = V_209 ;
V_7 -> V_210 = V_17 - V_209 ;
V_7 -> V_211 = V_310 [ 0 ] ;
V_7 -> V_212 = V_310 [ 1 ] ;
V_7 -> V_213 = V_310 [ 2 ] ;
V_7 -> V_319 = V_309 ;
return 0 ;
error:
F_33 ( V_170 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_170 , T_1 V_18 )
{
T_12 V_320 , V_321 , V_322 ;
struct V_218 * * V_208 , * V_194 ;
struct V_222 * V_224 , * V_226 ;
const char * V_17 = V_170 ;
F_20 () ;
if ( F_12 ( F_160 ( V_17 ) != V_323 ||
F_160 ( V_17 + 4 ) != V_18 ) )
goto error;
V_320 = F_160 ( V_17 + 8 ) ;
V_322 = F_160 ( V_17 + 12 ) ;
if ( F_12 ( ! V_320 != ! V_322 ) )
goto error;
V_321 = V_7 -> V_214 ;
if ( F_12 ( V_320 < V_321 ) )
goto error;
if ( ! V_321 ) {
F_33 ( V_170 ) ;
return 0 ;
}
{
unsigned V_61 = 0 ;
F_162 ( V_275 ) ;
F_163 ( V_275 , struct V_218 * , V_208 ,
V_322 + 1 ) ;
F_163 ( V_275 , struct V_218 , V_324 , V_322 ) ;
F_163 ( V_275 , struct V_222 , V_224 ,
V_322 * ( V_321 + 1 ) ) ;
char * V_325 = F_40 ( F_164 ( V_275 ) , V_68 ) ;
if ( F_12 ( ! V_325 ) ) {
F_33 ( V_170 ) ;
return - V_69 ;
}
V_208 = F_165 ( V_325 , V_275 , V_208 ) ;
V_194 = F_165 ( V_325 , V_275 , V_324 ) ;
V_61 = V_322 ;
do {
* V_208 ++ = V_194 ++ ;
} while ( -- V_61 );
* V_208 = NULL ;
V_208 = F_165 ( V_325 , V_275 , V_208 ) ;
V_194 = F_165 ( V_325 , V_275 , V_324 ) ;
V_226 = F_165 ( V_325 , V_275 , V_224 ) ;
V_224 = V_226 ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_326 = V_321 ;
if ( F_12 ( V_18 < 3 ) )
goto V_327;
V_194 -> V_328 = F_166 ( V_17 ) ;
V_194 -> V_224 = V_226 ;
++ V_194 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_167 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_327;
if ( F_39 ( V_326 ) ) {
V_226 -> V_226 = V_17 ;
-- V_326 ;
++ V_226 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_320 );
V_226 -> V_225 = 0 ;
V_226 -> V_226 = NULL ;
++ V_226 ;
} while ( -- V_322 );
if ( F_12 ( V_18 ) )
goto V_327;
V_7 -> V_208 = V_208 ;
V_7 -> V_207 = V_170 ;
return 0 ;
V_327:
F_33 ( V_208 ) ;
error:
F_33 ( V_170 ) ;
return - V_48 ;
}
static void F_168 ( struct V_6 * V_7 ,
enum V_329 type )
{
enum V_329 V_330 , V_331 = type ;
int V_332 = 0 ;
if ( V_7 -> V_8 == V_52 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_333 :
V_331 = V_334 ;
case V_334 :
case V_62 :
V_330 = type ;
break;
case V_335 :
case V_336 :
case V_337 :
case V_338 :
V_330 = V_334 ;
V_331 = V_333 ;
V_332 = 1 ;
break;
default:
F_66 ( 1 , L_42 , type ) ;
return;
}
{
T_8 * V_22 = V_7 -> V_22 . V_59 , * V_339 = V_22 ;
unsigned V_56 = V_7 -> V_22 . V_64 ;
for (; V_56 ; -- V_56 , ++ V_22 )
if ( ( * V_22 == V_330 || * V_22 == V_331 ) == V_332 )
* V_339 ++ = * V_22 ;
else
F_16 ( L_43 , * V_22 ) ;
V_7 -> V_22 . V_64 = V_339 - V_7 -> V_22 . V_59 ;
}
F_16 ( L_44 , type ) ;
V_7 -> V_22 . V_59 [ V_7 -> V_22 . V_64 ++ ] = type ;
F_169 ( & V_7 -> V_22 . V_25 ) ;
if ( V_7 -> V_102 )
F_56 ( V_7 -> V_102 , 1 ) ;
}
static void F_170 ( struct V_6 * V_7 ,
enum V_329 type )
{
unsigned long V_195 ;
F_140 ( & V_7 -> V_22 . V_25 . V_26 , V_195 ) ;
F_168 ( V_7 , type ) ;
F_142 ( & V_7 -> V_22 . V_25 . V_26 , V_195 ) ;
}
static int F_171 ( struct V_6 * V_7 , T_8 V_340 )
{
int V_61 ;
for ( V_61 = 1 ; V_61 < F_35 ( V_7 -> V_229 ) ; ++ V_61 )
if ( V_7 -> V_229 [ V_61 ] == V_340 )
return V_61 ;
return - V_341 ;
}
static int F_172 ( enum V_271 type , T_8 * V_272 ,
struct V_235 * V_137 ,
void * V_234 )
{
struct V_136 * V_232 = ( void * ) V_137 ;
struct V_1 * V_77 = V_234 ;
struct V_89 * V_89 ;
unsigned V_342 ;
int V_343 ;
static const char * V_344 [] = { L_45 , L_46 , L_47 } ;
if ( type != V_270 )
return 0 ;
if ( V_77 -> V_4 . V_345 ) {
V_342 = 2 ;
V_77 -> V_4 . V_345 [ ( long ) V_272 ] = V_137 ;
} else if ( V_77 -> V_4 . V_346 ) {
V_342 = 1 ;
V_77 -> V_4 . V_346 [ ( long ) V_272 ] = V_137 ;
} else {
V_342 = 0 ;
V_77 -> V_4 . V_347 [ ( long ) V_272 ] = V_137 ;
}
if ( ! V_137 || V_137 -> V_238 != V_249 )
return 0 ;
V_343 = F_171 ( V_77 -> V_7 , V_232 -> V_253 ) - 1 ;
if ( V_343 < 0 )
return V_343 ;
V_89 = V_77 -> V_231 + V_343 ;
if ( F_12 ( V_89 -> V_141 [ V_342 ] ) ) {
F_91 ( L_48 ,
V_344 [ V_342 ] ,
V_232 -> V_253 & V_348 ) ;
return - V_48 ;
}
V_89 -> V_141 [ V_342 ] = V_232 ;
F_173 ( L_49 , V_232 , V_232 -> V_237 ) ;
if ( V_89 -> V_12 ) {
V_232 -> V_253 = V_89 -> V_141 [ 0 ] -> V_253 ;
if ( ! V_232 -> V_349 )
V_232 -> V_349 = V_89 -> V_141 [ 0 ] -> V_349 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_8 V_253 ;
V_253 = V_232 -> V_253 ;
F_16 ( L_50 ) ;
V_12 = F_174 ( V_77 -> V_29 , V_232 ) ;
if ( F_12 ( ! V_12 ) )
return - V_350 ;
V_12 -> V_90 = V_77 -> V_231 + V_343 ;
V_14 = F_68 ( V_12 , V_68 ) ;
if ( F_12 ( ! V_14 ) )
return - V_69 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_14 = V_14 ;
V_77 -> V_351 [ V_232 -> V_253 &
V_348 ] = V_343 + 1 ;
if ( V_77 -> V_7 -> V_227 & V_228 )
V_232 -> V_253 = V_253 ;
}
F_173 ( L_51 , V_232 , V_232 -> V_237 ) ;
return 0 ;
}
static int F_175 ( enum V_271 type , T_8 * V_272 ,
struct V_235 * V_137 ,
void * V_234 )
{
struct V_1 * V_77 = V_234 ;
unsigned V_343 ;
T_8 V_352 ;
switch ( type ) {
default:
case V_270 :
return 0 ;
case V_276 :
V_343 = * V_272 ;
if ( V_77 -> V_353 [ V_343 ] < 0 ) {
int V_225 = F_176 ( V_77 -> V_354 , & V_77 -> V_4 ) ;
if ( F_12 ( V_225 < 0 ) )
return V_225 ;
V_77 -> V_353 [ V_343 ] = V_225 ;
}
V_352 = V_77 -> V_353 [ V_343 ] ;
break;
case V_277 :
V_352 = V_77 -> V_7 -> V_208 [ 0 ] -> V_224 [ * V_272 - 1 ] . V_225 ;
break;
case V_278 :
if ( V_137 -> V_238 == V_249 )
return 0 ;
V_343 = ( * V_272 & V_348 ) - 1 ;
if ( F_12 ( ! V_77 -> V_231 [ V_343 ] . V_12 ) )
return - V_48 ;
{
struct V_136 * * V_141 ;
V_141 = V_77 -> V_231 [ V_343 ] . V_141 ;
V_352 = V_141 [ V_141 [ 0 ] ? 0 : 1 ] -> V_253 ;
}
break;
}
F_16 ( L_52 , * V_272 , V_352 ) ;
* V_272 = V_352 ;
return 0 ;
}
static int F_177 ( enum V_279 type ,
struct V_281 * V_289 , void * V_17 ,
unsigned V_18 , void * V_234 )
{
struct V_1 * V_77 = V_234 ;
T_8 V_28 = 0 ;
switch ( type ) {
case V_286 : {
struct V_293 * V_137 = V_17 ;
struct V_355 * V_194 ;
V_194 = & V_77 -> V_4 . V_356 [ V_137 -> V_294 ] ;
V_194 -> V_357 = V_77 -> V_353 [ V_137 -> V_294 ] ;
memcpy ( V_194 -> V_358 -> V_359 , & V_137 -> V_360 ,
F_35 ( V_137 -> V_360 ) +
F_35 ( V_137 -> V_361 ) ) ;
V_28 = sizeof( * V_137 ) ;
}
break;
case V_287 : {
struct V_297 * V_137 = V_17 ;
struct V_355 * V_194 ;
struct V_362 * V_363 ;
char * V_364 ;
char * V_365 ;
V_194 = & V_77 -> V_4 . V_356 [ V_289 -> V_300 ] ;
V_194 -> V_357 = V_77 -> V_353 [ V_289 -> V_300 ] ;
V_363 = V_77 -> V_7 -> V_366 ;
V_77 -> V_7 -> V_366 += sizeof( * V_363 ) ;
V_363 -> type = F_158 ( V_137 -> V_302 ) ;
V_363 -> V_367 = F_8 ( V_137 -> V_305 ) ;
V_363 -> V_106 = F_158 ( * ( T_12 * )
F_178 ( V_17 , V_363 -> V_367 ) ) ;
V_28 = V_363 -> V_367 + V_363 -> V_106 + 14 ;
V_364 = V_77 -> V_7 -> V_368 ;
V_77 -> V_7 -> V_368 +=
V_363 -> V_367 ;
V_365 = V_77 -> V_7 -> V_369 ;
V_77 -> V_7 -> V_369 +=
V_363 -> V_106 ;
memcpy ( V_365 ,
F_179 ( V_17 , V_363 -> V_367 ) ,
V_363 -> V_106 ) ;
switch ( V_363 -> type ) {
case V_303 :
case V_370 :
case V_371 :
case V_304 :
V_363 -> V_106 *= 2 ;
break;
}
V_363 -> V_17 = V_365 ;
memcpy ( V_364 , F_180 ( V_17 ) ,
V_363 -> V_367 ) ;
V_363 -> V_367 *= 2 ;
V_363 -> V_166 = V_364 ;
V_194 -> V_358 -> V_372 +=
V_363 -> V_367 + V_363 -> V_106 + 14 ;
++ V_194 -> V_358 -> V_373 ;
F_181 ( & V_363 -> V_374 , & V_194 -> V_358 -> V_363 ) ;
}
break;
default:
F_16 ( L_32 , type ) ;
}
return V_28 ;
}
static inline struct V_375 * F_182 ( struct V_2 * V_3 ,
struct V_376 * V_377 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_375 * V_378 =
F_2 ( V_3 -> V_379 , struct V_375 , V_380 ) ;
int V_20 ;
F_20 () ;
if ( ! V_378 -> V_381 )
F_183 () ;
V_20 = V_378 -> V_382 -> V_383 ? 0 : - V_78 ;
V_77 -> V_7 = V_378 -> V_382 -> V_6 ;
if ( ! V_378 -> V_381 )
F_184 () ;
if ( V_20 )
return F_99 ( V_20 ) ;
V_77 -> V_354 = V_377 ;
V_77 -> V_29 = V_377 -> V_217 -> V_29 ;
if ( ! V_378 -> V_384 ) {
V_20 = F_131 ( V_77 -> V_7 , V_377 -> V_217 ) ;
if ( V_20 )
return F_99 ( V_20 ) ;
}
V_378 -> V_384 ++ ;
V_77 -> V_4 . V_224 = V_77 -> V_7 -> V_208 ;
return V_378 ;
}
static int F_185 ( struct V_376 * V_377 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
const int V_385 = ! ! V_77 -> V_7 -> V_211 ;
const int V_386 = F_186 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_212 ;
const int V_387 = F_187 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_213 ;
int V_388 , V_389 , V_390 , V_20 , V_61 ;
struct V_89 * V_391 ;
F_162 ( V_275 ) ;
F_188 ( V_275 , struct V_89 , V_231 , V_7 -> V_205 ) ;
F_188 ( V_275 , struct V_235 * , V_392 ,
V_385 ? V_7 -> V_211 + 1 : 0 ) ;
F_188 ( V_275 , struct V_235 * , V_393 ,
V_386 ? V_7 -> V_212 + 1 : 0 ) ;
F_188 ( V_275 , struct V_235 * , V_394 ,
V_387 ? V_7 -> V_213 + 1 : 0 ) ;
F_188 ( V_275 , short , V_395 , V_7 -> V_215 ) ;
F_188 ( V_275 , struct V_355 , V_356 ,
V_377 -> V_217 -> V_396 ? V_7 -> V_215 : 0 ) ;
F_188 ( V_275 , char [ 16 ] , V_397 ,
V_377 -> V_217 -> V_396 ? V_7 -> V_215 : 0 ) ;
F_188 ( V_275 , struct V_398 , V_358 ,
V_377 -> V_217 -> V_396 ? V_7 -> V_215 : 0 ) ;
F_188 ( V_275 , struct V_362 , V_363 ,
V_7 -> V_306 ) ;
F_188 ( V_275 , char , V_364 ,
V_7 -> V_307 ) ;
F_188 ( V_275 , char , V_365 ,
V_7 -> V_308 ) ;
F_188 ( V_275 , char , V_209 , V_7 -> V_210 ) ;
char * V_325 ;
F_20 () ;
if ( F_12 ( ! ( V_385 | V_386 | V_387 ) ) )
return - V_350 ;
V_325 = F_123 ( F_164 ( V_275 ) , V_68 ) ;
if ( F_12 ( ! V_325 ) )
return - V_69 ;
V_7 -> V_366 = F_165 ( V_325 , V_275 , V_363 ) ;
V_7 -> V_368 =
F_165 ( V_325 , V_275 , V_364 ) ;
V_7 -> V_369 =
F_165 ( V_325 , V_275 , V_365 ) ;
memcpy ( F_165 ( V_325 , V_275 , V_209 ) , V_7 -> V_209 ,
V_7 -> V_210 ) ;
memset ( F_165 ( V_325 , V_275 , V_395 ) , 0xff , V_399 ) ;
V_391 = F_165 ( V_325 , V_275 , V_231 ) ;
for ( V_61 = 0 ; V_61 < V_7 -> V_205 ; V_61 ++ )
V_391 [ V_61 ] . V_133 = - 1 ;
V_77 -> V_231 = F_165 ( V_325 , V_275 , V_231 ) ;
V_77 -> V_353 = F_165 ( V_325 , V_275 , V_395 ) ;
if ( F_39 ( V_385 ) ) {
V_77 -> V_4 . V_347 = F_165 ( V_325 , V_275 , V_392 ) ;
V_388 = F_153 ( V_7 -> V_211 ,
F_165 ( V_325 , V_275 , V_209 ) ,
V_400 ,
F_172 , V_77 ) ;
if ( F_12 ( V_388 < 0 ) ) {
V_20 = V_388 ;
goto error;
}
} else {
V_388 = 0 ;
}
if ( F_39 ( V_386 ) ) {
V_77 -> V_4 . V_346 = F_165 ( V_325 , V_275 , V_393 ) ;
V_389 = F_153 ( V_7 -> V_212 ,
F_165 ( V_325 , V_275 , V_209 ) + V_388 ,
V_400 - V_388 ,
F_172 , V_77 ) ;
if ( F_12 ( V_389 < 0 ) ) {
V_20 = V_389 ;
goto error;
}
} else {
V_389 = 0 ;
}
if ( F_39 ( V_387 ) ) {
V_77 -> V_4 . V_345 = F_165 ( V_325 , V_275 , V_394 ) ;
V_390 = F_153 ( V_7 -> V_213 ,
F_165 ( V_325 , V_275 , V_209 ) + V_388 + V_389 ,
V_400 - V_388 - V_389 ,
F_172 , V_77 ) ;
if ( F_12 ( V_390 < 0 ) ) {
V_20 = V_390 ;
goto error;
}
} else {
V_390 = 0 ;
}
V_20 = F_153 ( V_7 -> V_211 +
( V_386 ? V_7 -> V_212 : 0 ) +
( V_387 ? V_7 -> V_213 : 0 ) ,
F_165 ( V_325 , V_275 , V_209 ) , V_400 ,
F_175 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_77 -> V_4 . V_356 = F_165 ( V_325 , V_275 , V_356 ) ;
if ( V_377 -> V_217 -> V_396 ) {
for ( V_61 = 0 ; V_61 < V_7 -> V_215 ; ++ V_61 ) {
struct V_398 * V_137 ;
V_137 = V_77 -> V_4 . V_356 [ V_61 ] . V_358 =
F_165 ( V_325 , V_275 , V_358 ) +
V_61 * sizeof( struct V_398 ) ;
V_137 -> V_359 =
F_165 ( V_325 , V_275 , V_397 ) + V_61 * 16 ;
F_189 ( & V_137 -> V_363 ) ;
}
V_20 = F_157 ( V_7 -> V_319 ,
F_165 ( V_325 , V_275 , V_209 ) +
V_388 + V_389 + V_390 ,
V_400 - V_388 - V_389 -
V_390 ,
F_177 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
}
V_77 -> V_4 . V_401 =
V_377 -> V_217 -> V_396 ? V_7 -> V_215 : 0 ;
F_170 ( V_7 , V_335 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_190 ( struct V_376 * V_377 ,
struct V_2 * V_3 )
{
struct V_375 * V_378 = F_182 ( V_3 , V_377 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_20 ;
if ( F_23 ( V_378 ) )
return F_24 ( V_378 ) ;
V_20 = F_185 ( V_377 , V_3 ) ;
if ( V_20 && ! -- V_378 -> V_384 )
F_134 ( V_77 -> V_7 ) ;
return V_20 ;
}
static void F_191 ( struct V_91 * V_92 )
{
struct V_6 * V_7 = F_2 ( V_92 ,
struct V_6 , V_402 ) ;
F_116 ( V_7 ) ;
}
static int F_192 ( struct V_2 * V_3 ,
unsigned V_300 , unsigned V_403 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
int V_20 = 0 , V_404 ;
if ( V_403 != ( unsigned ) - 1 ) {
V_404 = F_46 ( V_77 , V_300 ) ;
if ( F_12 ( V_404 < 0 ) )
return V_404 ;
}
if ( V_7 -> V_77 )
F_139 ( V_7 -> V_77 ) ;
if ( V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_59 ( & V_7 -> V_402 , F_191 ) ;
F_60 ( & V_7 -> V_402 ) ;
return - V_78 ;
}
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
if ( V_403 == ( unsigned ) - 1 ) {
V_7 -> V_77 = NULL ;
F_170 ( V_7 , V_337 ) ;
return 0 ;
}
V_7 -> V_77 = V_77 ;
V_20 = F_143 ( V_77 ) ;
if ( F_39 ( V_20 >= 0 ) )
F_170 ( V_7 , V_338 ) ;
return V_20 ;
}
static void F_193 ( struct V_2 * V_3 )
{
F_192 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_194 ( struct V_2 * V_3 ,
const struct V_405 * V_406 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
unsigned long V_195 ;
int V_20 ;
F_20 () ;
F_16 ( L_53 , V_406 -> V_53 ) ;
F_16 ( L_54 , V_406 -> V_407 ) ;
F_16 ( L_55 , F_8 ( V_406 -> V_408 ) ) ;
F_16 ( L_56 , F_8 ( V_406 -> V_285 ) ) ;
F_16 ( L_57 , F_8 ( V_406 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
switch ( V_406 -> V_53 & V_409 ) {
case V_410 :
V_20 = F_46 ( V_77 , F_8 ( V_406 -> V_285 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_411 :
V_20 = F_195 ( V_77 , F_8 ( V_406 -> V_285 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_77 -> V_7 -> V_227 & V_228 )
V_20 = V_77 -> V_7 -> V_229 [ V_20 ] ;
break;
default:
return - V_412 ;
}
F_140 ( & V_7 -> V_22 . V_25 . V_26 , V_195 ) ;
V_7 -> V_22 . V_23 = * V_406 ;
V_7 -> V_22 . V_23 . V_285 = F_196 ( V_20 ) ;
F_168 ( V_7 , V_62 ) ;
F_142 ( & V_7 -> V_22 . V_25 . V_26 , V_195 ) ;
return 0 ;
}
static void F_197 ( struct V_2 * V_3 )
{
F_20 () ;
F_170 ( F_1 ( V_3 ) -> V_7 , V_334 ) ;
}
static void F_198 ( struct V_2 * V_3 )
{
F_20 () ;
F_170 ( F_1 ( V_3 ) -> V_7 , V_333 ) ;
}
static int F_195 ( struct V_1 * V_77 , T_8 V_133 )
{
V_133 = V_77 -> V_351 [ V_133 & V_348 ] ;
return V_133 ? V_133 : - V_413 ;
}
static int F_46 ( struct V_1 * V_77 , T_8 V_404 )
{
short * V_414 = V_77 -> V_353 ;
unsigned V_64 = V_77 -> V_7 -> V_215 ;
for (; V_64 ; -- V_64 , ++ V_414 ) {
if ( * V_414 >= 0 && * V_414 == V_404 )
return V_414 - V_77 -> V_353 ;
}
return - V_413 ;
}
static struct V_200 * F_199 ( const char * V_166 )
{
struct V_200 * V_382 ;
F_200 (dev, &ffs_devices, entry) {
if ( ! V_382 -> V_166 || ! V_166 )
continue;
if ( strcmp ( V_382 -> V_166 , V_166 ) == 0 )
return V_382 ;
}
return NULL ;
}
static struct V_200 * F_201 ( void )
{
struct V_200 * V_382 ;
if ( F_202 ( & V_415 ) ) {
V_382 = F_203 ( & V_415 , struct V_200 , V_374 ) ;
if ( V_382 -> V_416 )
return V_382 ;
}
return NULL ;
}
static struct V_200 * F_204 ( const char * V_166 )
{
struct V_200 * V_382 ;
V_382 = F_201 () ;
if ( V_382 )
return V_382 ;
return F_199 ( V_166 ) ;
}
static inline struct V_375 * F_205 ( struct V_417 * V_418 )
{
return F_2 ( F_206 ( V_418 ) , struct V_375 ,
V_380 . V_419 ) ;
}
static void F_207 ( struct V_417 * V_418 )
{
struct V_375 * V_186 = F_205 ( V_418 ) ;
F_208 ( & V_186 -> V_380 ) ;
}
static void F_209 ( struct V_420 * V_3 )
{
struct V_375 * V_186 ;
V_186 = F_210 ( V_3 ) ;
F_183 () ;
F_211 ( V_186 -> V_382 ) ;
F_184 () ;
F_33 ( V_186 ) ;
}
static int F_212 ( struct V_420 * V_379 , const char * V_166 )
{
struct V_375 * V_186 ;
char * V_39 ;
const char * V_421 ;
int V_367 , V_20 ;
V_367 = strlen ( V_166 ) + 1 ;
if ( V_367 > V_422 )
return - V_423 ;
V_39 = F_213 ( V_166 , V_367 , V_68 ) ;
if ( ! V_39 )
return - V_69 ;
V_186 = F_210 ( V_379 ) ;
V_421 = NULL ;
F_183 () ;
V_421 = V_186 -> V_382 -> V_424 ? V_186 -> V_382 -> V_166 : NULL ;
V_20 = F_214 ( V_186 -> V_382 , V_39 ) ;
if ( V_20 ) {
F_33 ( V_39 ) ;
F_184 () ;
return V_20 ;
}
V_186 -> V_382 -> V_424 = true ;
F_184 () ;
F_33 ( V_421 ) ;
return 0 ;
}
static struct V_420 * F_215 ( void )
{
struct V_375 * V_186 ;
struct V_200 * V_382 ;
V_186 = F_123 ( sizeof( * V_186 ) , V_68 ) ;
if ( ! V_186 )
return F_99 ( - V_69 ) ;
V_186 -> V_380 . V_425 = F_212 ;
V_186 -> V_380 . V_426 = F_209 ;
F_183 () ;
V_382 = F_216 () ;
F_184 () ;
if ( F_23 ( V_382 ) ) {
F_33 ( V_186 ) ;
return F_104 ( V_382 ) ;
}
V_186 -> V_382 = V_382 ;
V_382 -> V_186 = V_186 ;
F_217 ( & V_186 -> V_380 . V_419 , L_58 ,
& V_427 ) ;
return & V_186 -> V_380 ;
}
static void F_218 ( struct V_2 * V_3 )
{
F_33 ( F_1 ( V_3 ) ) ;
}
static void F_219 ( struct V_376 * V_377 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_375 * V_186 =
F_2 ( V_3 -> V_379 , struct V_375 , V_380 ) ;
struct V_89 * V_12 = V_77 -> V_231 ;
unsigned V_64 = V_7 -> V_205 ;
unsigned long V_195 ;
F_20 () ;
if ( V_7 -> V_77 == V_77 ) {
F_139 ( V_77 ) ;
V_7 -> V_77 = NULL ;
}
if ( ! -- V_186 -> V_384 )
F_134 ( V_7 ) ;
F_140 ( & V_77 -> V_7 -> V_111 , V_195 ) ;
do {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_57 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
} while ( -- V_64 );
F_142 ( & V_77 -> V_7 -> V_111 , V_195 ) ;
F_33 ( V_77 -> V_231 ) ;
V_77 -> V_231 = NULL ;
V_77 -> V_4 . V_347 = NULL ;
V_77 -> V_4 . V_346 = NULL ;
V_77 -> V_4 . V_345 = NULL ;
V_77 -> V_353 = NULL ;
F_170 ( V_7 , V_336 ) ;
}
static struct V_2 * F_220 ( struct V_420 * V_379 )
{
struct V_1 * V_77 ;
F_20 () ;
V_77 = F_123 ( sizeof( * V_77 ) , V_68 ) ;
if ( F_12 ( ! V_77 ) )
return F_99 ( - V_69 ) ;
V_77 -> V_4 . V_166 = L_59 ;
V_77 -> V_4 . V_428 = F_190 ;
V_77 -> V_4 . V_429 = F_219 ;
V_77 -> V_4 . V_430 = F_192 ;
V_77 -> V_4 . V_431 = F_193 ;
V_77 -> V_4 . V_23 = F_194 ;
V_77 -> V_4 . V_432 = F_197 ;
V_77 -> V_4 . V_433 = F_198 ;
V_77 -> V_4 . V_434 = F_218 ;
return & V_77 -> V_4 ;
}
static struct V_200 * F_216 ( void )
{
struct V_200 * V_382 ;
int V_20 ;
if ( F_201 () )
return F_99 ( - V_72 ) ;
V_382 = F_123 ( sizeof( * V_382 ) , V_68 ) ;
if ( ! V_382 )
return F_99 ( - V_69 ) ;
if ( F_221 ( & V_415 ) ) {
V_20 = F_109 () ;
if ( V_20 ) {
F_33 ( V_382 ) ;
return F_99 ( V_20 ) ;
}
}
F_222 ( & V_382 -> V_374 , & V_415 ) ;
return V_382 ;
}
static int F_214 ( struct V_200 * V_382 , const char * V_166 )
{
struct V_200 * V_435 ;
V_435 = F_199 ( V_166 ) ;
if ( V_435 )
return - V_72 ;
V_382 -> V_166 = V_166 ;
return 0 ;
}
int F_223 ( struct V_200 * V_382 , const char * V_166 )
{
int V_20 ;
F_183 () ;
V_20 = F_214 ( V_382 , V_166 ) ;
F_184 () ;
return V_20 ;
}
int F_224 ( struct V_200 * V_382 )
{
int V_20 ;
V_20 = 0 ;
F_183 () ;
if ( ! F_202 ( & V_415 ) )
V_20 = - V_72 ;
else
V_382 -> V_416 = true ;
F_184 () ;
return V_20 ;
}
static void F_211 ( struct V_200 * V_382 )
{
F_225 ( & V_382 -> V_374 ) ;
if ( V_382 -> V_424 )
F_33 ( V_382 -> V_166 ) ;
F_33 ( V_382 ) ;
if ( F_221 ( & V_415 ) )
F_111 () ;
}
static void * F_103 ( const char * V_196 )
{
struct V_200 * V_200 ;
F_20 () ;
F_183 () ;
V_200 = F_204 ( V_196 ) ;
if ( ! V_200 )
V_200 = F_99 ( - V_341 ) ;
else if ( V_200 -> V_436 )
V_200 = F_99 ( - V_72 ) ;
else if ( V_200 -> V_437 &&
V_200 -> V_437 ( V_200 ) )
V_200 = F_99 ( - V_341 ) ;
else
V_200 -> V_436 = true ;
F_184 () ;
return V_200 ;
}
static void F_106 ( struct V_6 * V_6 )
{
struct V_200 * V_200 ;
F_20 () ;
F_183 () ;
V_200 = V_6 -> V_40 ;
if ( V_200 ) {
V_200 -> V_436 = false ;
if ( V_200 -> V_438 )
V_200 -> V_438 ( V_200 ) ;
}
F_184 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_200 * V_439 ;
int V_20 = 0 ;
F_20 () ;
F_183 () ;
V_439 = V_7 -> V_40 ;
if ( ! V_439 ) {
V_20 = - V_48 ;
goto V_116;
}
if ( F_62 ( V_439 -> V_383 ) ) {
V_20 = - V_72 ;
goto V_116;
}
V_439 -> V_383 = true ;
V_439 -> V_6 = V_7 ;
if ( V_439 -> V_440 ) {
V_20 = V_439 -> V_440 ( V_7 ) ;
if ( V_20 )
goto V_116;
}
F_226 ( V_441 , & V_7 -> V_195 ) ;
V_116:
F_184 () ;
return V_20 ;
}
static void F_129 ( struct V_6 * V_7 )
{
struct V_200 * V_439 ;
struct V_375 * V_186 ;
F_20 () ;
F_183 () ;
V_439 = V_7 -> V_40 ;
if ( ! V_439 )
goto V_116;
V_439 -> V_383 = false ;
if ( F_227 ( V_441 , & V_7 -> V_195 ) &&
V_439 -> V_442 )
V_439 -> V_442 ( V_7 ) ;
if ( V_439 -> V_186 )
V_186 = V_439 -> V_186 ;
else
goto V_116;
if ( V_186 -> V_381 || ! V_186 -> V_380 . V_419 . V_443 . V_444
|| ! F_122 ( & V_186 -> V_380 . V_419 . V_443 . V_445 . V_446 ) )
goto V_116;
F_228 ( V_439 -> V_186 ->
V_380 . V_419 . V_443 . V_444 -> V_444 ) ;
V_116:
F_184 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_447 )
{
return V_447
? F_39 ( F_229 ( V_42 ) ) ? 0 : - V_67
: F_230 ( V_42 ) ;
}
static char * F_22 ( const char T_3 * V_27 , T_1 V_18 )
{
char * V_17 ;
if ( F_12 ( ! V_18 ) )
return NULL ;
V_17 = F_40 ( V_18 , V_68 ) ;
if ( F_12 ( ! V_17 ) )
return F_99 ( - V_69 ) ;
if ( F_12 ( F_231 ( V_17 , V_27 , V_18 ) ) ) {
F_33 ( V_17 ) ;
return F_99 ( - V_65 ) ;
}
F_16 ( L_60 ) ;
F_173 ( L_58 , V_17 , V_18 ) ;
return V_17 ;
}
