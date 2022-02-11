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
if ( V_94 -> V_95 && V_20 > 0 ) {
F_52 ( V_94 -> V_96 ) ;
V_20 = F_53 ( V_94 -> V_27 , V_20 , & V_94 -> V_17 ) ;
if ( F_54 ( & V_94 -> V_17 ) )
V_20 = - V_65 ;
F_55 ( V_94 -> V_96 ) ;
}
V_94 -> V_97 -> V_98 ( V_94 -> V_97 , V_20 , V_20 ) ;
if ( V_94 -> V_7 -> V_99 &&
! ( V_94 -> V_97 -> V_100 & V_101 ) )
F_56 ( V_94 -> V_7 -> V_99 , 1 ) ;
F_57 ( V_94 -> V_12 , V_94 -> V_14 ) ;
V_94 -> V_97 -> V_102 = NULL ;
if ( V_94 -> V_95 )
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
struct V_89 * V_12 ;
char * V_17 = NULL ;
T_2 V_20 , V_106 = - V_48 ;
int V_107 ;
if ( F_62 ( V_105 -> V_7 -> V_45 != V_50 ) ) {
V_20 = - V_78 ;
goto error;
}
V_12 = V_105 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 ) {
V_20 = - V_67 ;
goto error;
}
V_20 = F_63 ( V_105 -> V_82 , ( V_12 = V_105 -> V_12 ) ) ;
if ( V_20 ) {
V_20 = - V_32 ;
goto error;
}
}
V_107 = ( ! V_94 -> V_95 == ! V_105 -> V_108 ) ;
if ( V_107 && V_105 -> V_109 ) {
V_20 = - V_48 ;
goto error;
}
if ( ! V_107 ) {
struct V_75 * V_29 = V_105 -> V_7 -> V_29 ;
T_1 V_110 ;
F_31 ( & V_105 -> V_7 -> V_111 ) ;
if ( V_105 -> V_12 != V_12 ) {
F_9 ( & V_105 -> V_7 -> V_111 ) ;
return - V_112 ;
}
V_106 = F_54 ( & V_94 -> V_17 ) ;
if ( V_94 -> V_95 )
V_106 = F_64 ( V_29 , V_12 -> V_12 , V_106 ) ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_17 = F_40 ( V_106 , V_68 ) ;
if ( F_12 ( ! V_17 ) )
return - V_69 ;
if ( ! V_94 -> V_95 ) {
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
F_9 ( & V_105 -> V_7 -> V_111 ) ;
} else if ( V_107 ) {
if ( F_39 ( V_105 -> V_12 == V_12 ) && ! F_62 ( ! V_12 -> V_12 ) )
F_17 ( V_12 -> V_12 ) ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_20 = - V_113 ;
} else {
struct V_13 * V_14 ;
if ( F_12 ( V_106 == - V_48 ) ) {
F_66 ( 1 , L_5 , V_114 ) ;
V_20 = - V_48 ;
goto V_115;
}
if ( V_94 -> V_116 ) {
V_14 = F_67 ( V_12 -> V_12 , V_68 ) ;
if ( F_12 ( ! V_14 ) )
goto V_115;
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
goto V_115;
}
V_20 = - V_117 ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
} else {
F_68 ( V_118 ) ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_106 ;
V_14 -> V_15 = & V_118 ;
V_14 -> F_50 = F_49 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
if ( F_12 ( V_20 < 0 ) ) {
} else if ( F_12 (
F_13 ( & V_118 ) ) ) {
V_20 = - V_32 ;
F_14 ( V_12 -> V_12 , V_14 ) ;
} else {
V_20 = V_12 -> V_33 ;
if ( V_94 -> V_95 && V_20 > 0 ) {
V_20 = F_53 ( V_17 , V_20 , & V_94 -> V_17 ) ;
if ( ! V_20 )
V_20 = - V_65 ;
}
}
F_33 ( V_17 ) ;
}
}
F_29 ( & V_105 -> V_42 ) ;
return V_20 ;
V_115:
F_9 ( & V_105 -> V_7 -> V_111 ) ;
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
static int F_70 ( struct V_97 * V_97 )
{
struct V_93 * V_94 = V_97 -> V_102 ;
struct V_104 * V_105 = V_97 -> V_119 -> V_40 ;
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
static T_2 F_71 ( struct V_97 * V_97 , struct V_120 * V_121 )
{
struct V_93 V_94 , * V_122 = & V_94 ;
T_2 V_123 ;
F_20 () ;
if ( ! F_72 ( V_97 ) ) {
V_122 = F_40 ( sizeof( V_94 ) , V_68 ) ;
if ( F_12 ( ! V_122 ) )
return - V_69 ;
V_122 -> V_116 = true ;
} else {
V_122 -> V_116 = false ;
}
V_122 -> V_95 = false ;
V_122 -> V_97 = V_97 ;
V_122 -> V_17 = * V_121 ;
V_122 -> V_96 = V_124 -> V_96 ;
V_97 -> V_102 = V_122 ;
if ( V_122 -> V_116 )
F_73 ( V_97 , F_70 ) ;
V_123 = F_61 ( V_97 -> V_119 , V_122 ) ;
if ( V_123 == - V_117 )
return V_123 ;
if ( V_122 -> V_116 )
F_33 ( V_122 ) ;
else
* V_121 = V_122 -> V_17 ;
return V_123 ;
}
static T_2 F_74 ( struct V_97 * V_97 , struct V_120 * V_125 )
{
struct V_93 V_94 , * V_122 = & V_94 ;
T_2 V_123 ;
F_20 () ;
if ( ! F_72 ( V_97 ) ) {
V_122 = F_40 ( sizeof( V_94 ) , V_68 ) ;
if ( F_12 ( ! V_122 ) )
return - V_69 ;
V_122 -> V_116 = true ;
} else {
V_122 -> V_116 = false ;
}
V_122 -> V_95 = true ;
V_122 -> V_97 = V_97 ;
if ( V_122 -> V_116 ) {
V_122 -> V_103 = F_75 ( & V_122 -> V_17 , V_125 , V_68 ) ;
if ( ! V_122 -> V_103 ) {
F_33 ( V_122 ) ;
return - V_69 ;
}
} else {
V_122 -> V_17 = * V_125 ;
V_122 -> V_103 = NULL ;
}
V_122 -> V_96 = V_124 -> V_96 ;
V_97 -> V_102 = V_122 ;
if ( V_122 -> V_116 )
F_73 ( V_97 , F_70 ) ;
V_123 = F_61 ( V_97 -> V_119 , V_122 ) ;
if ( V_123 == - V_117 )
return V_123 ;
if ( V_122 -> V_116 ) {
F_33 ( V_122 -> V_103 ) ;
F_33 ( V_122 ) ;
} else {
* V_125 = V_122 -> V_17 ;
}
return V_123 ;
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
case V_126 :
V_20 = F_78 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_127 :
F_79 ( V_105 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_128 :
V_20 = F_80 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_129 :
V_20 = V_105 -> V_12 -> V_130 ;
break;
case V_131 :
{
int V_132 ;
struct V_133 * V_134 ;
switch ( V_105 -> V_7 -> V_29 -> V_135 ) {
case V_136 :
V_132 = 2 ;
break;
case V_137 :
V_132 = 1 ;
break;
default:
V_132 = 0 ;
}
V_134 = V_105 -> V_12 -> V_138 [ V_132 ] ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_20 = F_36 ( ( void * ) V_74 , V_134 , sizeof( * V_134 ) ) ;
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
F_81 ( struct V_139 * V_140 , void * V_17 ,
const struct V_141 * V_142 ,
const struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_70 * V_70 ;
F_20 () ;
V_70 = F_82 ( V_140 ) ;
if ( F_39 ( V_70 ) ) {
struct V_147 V_148 = V_149 ;
V_70 -> V_150 = F_83 () ;
V_70 -> V_151 = V_146 -> V_152 ;
V_70 -> V_153 = V_146 -> V_154 ;
V_70 -> V_155 = V_146 -> V_156 ;
V_70 -> V_157 = V_148 ;
V_70 -> V_158 = V_148 ;
V_70 -> V_159 = V_148 ;
V_70 -> V_71 = V_17 ;
if ( V_142 )
V_70 -> V_160 = V_142 ;
if ( V_144 )
V_70 -> V_161 = V_144 ;
}
return V_70 ;
}
static struct V_162 * F_84 ( struct V_139 * V_140 ,
const char * V_163 , void * V_17 ,
const struct V_141 * V_142 )
{
struct V_6 * V_7 = V_140 -> V_164 ;
struct V_162 * V_162 ;
struct V_70 * V_70 ;
F_20 () ;
V_162 = F_85 ( V_140 -> V_165 , V_163 ) ;
if ( F_12 ( ! V_162 ) )
return NULL ;
V_70 = F_81 ( V_140 , V_17 , V_142 , NULL , & V_7 -> V_166 ) ;
if ( F_12 ( ! V_70 ) ) {
F_86 ( V_162 ) ;
return NULL ;
}
F_87 ( V_162 , V_70 ) ;
return V_162 ;
}
static int F_88 ( struct V_139 * V_140 , void * V_167 , int V_168 )
{
struct V_169 * V_17 = V_167 ;
struct V_70 * V_70 ;
struct V_6 * V_7 = V_17 -> V_6 ;
F_20 () ;
V_7 -> V_140 = V_140 ;
V_17 -> V_6 = NULL ;
V_140 -> V_164 = V_7 ;
V_140 -> V_170 = V_171 ;
V_140 -> V_172 = V_173 ;
V_140 -> V_174 = V_175 ;
V_140 -> V_176 = & V_177 ;
V_140 -> V_178 = 1 ;
V_17 -> V_146 . V_152 = V_17 -> V_179 ;
V_70 = F_81 ( V_140 , NULL ,
& V_180 ,
& V_181 ,
& V_17 -> V_146 ) ;
V_140 -> V_165 = F_89 ( V_70 ) ;
if ( F_12 ( ! V_140 -> V_165 ) )
return - V_69 ;
if ( F_12 ( ! F_84 ( V_140 , L_6 , V_7 ,
& V_182 ) ) )
return - V_69 ;
return 0 ;
}
static int F_90 ( struct V_169 * V_17 , char * V_183 )
{
F_20 () ;
if ( ! V_183 || ! * V_183 )
return 0 ;
for (; ; ) {
unsigned long V_74 ;
char * V_184 , * V_185 ;
V_185 = strchr ( V_183 , ',' ) ;
if ( V_185 )
* V_185 = 0 ;
V_184 = strchr ( V_183 , '=' ) ;
if ( F_12 ( ! V_184 ) ) {
F_91 ( L_7 , V_183 ) ;
return - V_48 ;
}
* V_184 = 0 ;
if ( F_92 ( V_184 + 1 , 0 , & V_74 ) ) {
F_91 ( L_8 , V_183 , V_184 + 1 ) ;
return - V_48 ;
}
switch ( V_184 - V_183 ) {
case 13 :
if ( ! memcmp ( V_183 , L_9 , 13 ) )
V_17 -> V_186 = ! ! V_74 ;
else
goto V_187;
break;
case 5 :
if ( ! memcmp ( V_183 , L_10 , 5 ) )
V_17 -> V_179 = ( V_74 & 0555 ) | V_188 ;
else if ( ! memcmp ( V_183 , L_11 , 5 ) )
V_17 -> V_146 . V_152 = ( V_74 & 0666 ) | V_189 ;
else
goto V_187;
break;
case 4 :
if ( ! memcmp ( V_183 , L_12 , 4 ) ) {
V_17 -> V_179 = ( V_74 & 0555 ) | V_188 ;
V_17 -> V_146 . V_152 = ( V_74 & 0666 ) | V_189 ;
} else {
goto V_187;
}
break;
case 3 :
if ( ! memcmp ( V_183 , L_13 , 3 ) ) {
V_17 -> V_146 . V_154 = F_93 ( F_94 () , V_74 ) ;
if ( ! F_95 ( V_17 -> V_146 . V_154 ) ) {
F_91 ( L_14 , V_183 , V_74 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_183 , L_15 , 3 ) ) {
V_17 -> V_146 . V_156 = F_96 ( F_94 () , V_74 ) ;
if ( ! F_97 ( V_17 -> V_146 . V_156 ) ) {
F_91 ( L_14 , V_183 , V_74 ) ;
return - V_48 ;
}
} else {
goto V_187;
}
break;
default:
V_187:
F_91 ( L_16 , V_183 ) ;
return - V_48 ;
}
if ( ! V_185 )
break;
V_183 = V_185 + 1 ;
}
return 0 ;
}
static struct V_162 *
F_98 ( struct V_190 * V_191 , int V_192 ,
const char * V_193 , void * V_183 )
{
struct V_169 V_17 = {
. V_146 = {
. V_152 = V_189 | 0600 ,
. V_154 = V_194 ,
. V_156 = V_195 ,
} ,
. V_179 = V_188 | 0500 ,
. V_186 = false ,
} ;
struct V_162 * V_196 ;
int V_20 ;
void * V_197 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_90 ( & V_17 , V_183 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_99 ( V_20 ) ;
V_7 = F_100 () ;
if ( F_12 ( ! V_7 ) )
return F_99 ( - V_69 ) ;
V_7 -> V_166 = V_17 . V_146 ;
V_7 -> V_186 = V_17 . V_186 ;
V_7 -> V_193 = F_101 ( V_193 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_193 ) ) {
F_102 ( V_7 ) ;
return F_99 ( - V_69 ) ;
}
V_197 = F_103 ( V_193 ) ;
if ( F_23 ( V_197 ) ) {
F_102 ( V_7 ) ;
return F_104 ( V_197 ) ;
}
V_7 -> V_40 = V_197 ;
V_17 . V_6 = V_7 ;
V_196 = F_105 ( V_191 , V_192 , & V_17 , F_88 ) ;
if ( F_23 ( V_196 ) && V_17 . V_6 ) {
F_106 ( V_17 . V_6 ) ;
F_102 ( V_17 . V_6 ) ;
}
return V_196 ;
}
static void
F_107 ( struct V_139 * V_140 )
{
F_20 () ;
F_108 ( V_140 ) ;
if ( V_140 -> V_164 ) {
F_106 ( V_140 -> V_164 ) ;
F_44 ( V_140 -> V_164 ) ;
F_102 ( V_140 -> V_164 ) ;
}
}
static int F_109 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_110 ( & V_198 ) ;
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
F_112 ( & V_198 ) ;
}
static void F_113 ( struct V_6 * V_7 )
{
F_20 () ;
F_114 ( & V_7 -> V_199 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_20 () ;
F_114 ( & V_7 -> V_199 ) ;
if ( F_115 ( 1 , & V_7 -> V_200 ) == 1 &&
V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_116 ( V_7 ) ;
}
}
static void F_102 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_117 ( & V_7 -> V_199 ) ) ) {
F_25 ( L_20 , V_114 ) ;
F_118 ( V_7 ) ;
F_119 ( F_120 ( & V_7 -> V_22 . V_25 ) ||
F_120 ( & V_7 -> V_16 . V_82 ) ) ;
F_33 ( V_7 -> V_193 ) ;
F_33 ( V_7 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_117 ( & V_7 -> V_200 ) ) {
if ( V_7 -> V_186 ) {
V_7 -> V_45 = V_87 ;
if ( V_7 -> V_201 ) {
F_121 ( V_7 -> V_201 ,
V_7 -> V_202 ) ;
V_7 -> V_201 = NULL ;
}
if ( V_7 -> V_8 == V_52 )
F_15 ( V_7 ) ;
} else {
V_7 -> V_45 = V_49 ;
F_116 ( V_7 ) ;
}
}
if ( F_122 ( & V_7 -> V_200 ) < 0 ) {
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
F_124 ( & V_7 -> V_199 , 1 ) ;
F_124 ( & V_7 -> V_200 , 0 ) ;
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
if ( V_7 -> V_201 )
F_121 ( V_7 -> V_201 , V_7 -> V_202 ) ;
if ( V_7 -> V_99 )
F_130 ( V_7 -> V_99 ) ;
F_33 ( V_7 -> V_203 ) ;
F_33 ( V_7 -> V_204 ) ;
F_33 ( V_7 -> V_205 ) ;
}
static void F_116 ( struct V_6 * V_7 )
{
F_20 () ;
F_118 ( V_7 ) ;
V_7 -> V_201 = NULL ;
V_7 -> V_203 = NULL ;
V_7 -> V_206 = NULL ;
V_7 -> V_204 = NULL ;
V_7 -> V_205 = NULL ;
V_7 -> V_207 = 0 ;
V_7 -> V_208 = 0 ;
V_7 -> V_209 = 0 ;
V_7 -> V_210 = 0 ;
V_7 -> V_211 = 0 ;
V_7 -> V_212 = 0 ;
V_7 -> V_202 = 0 ;
V_7 -> V_22 . V_64 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_192 = 0 ;
}
static int F_131 ( struct V_6 * V_7 , struct V_213 * V_214 )
{
struct V_215 * * V_216 ;
int V_217 ;
F_20 () ;
if ( F_62 ( V_7 -> V_45 != V_50
|| F_132 ( V_218 , & V_7 -> V_192 ) ) )
return - V_55 ;
V_217 = F_133 ( V_214 , V_7 -> V_211 ) ;
if ( F_12 ( V_217 < 0 ) )
return V_217 ;
V_7 -> V_19 = F_67 ( V_214 -> V_29 -> V_30 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_69 ;
V_7 -> V_19 -> F_50 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_216 = V_7 -> V_205 ;
if ( V_216 ) {
for (; * V_216 ; ++ V_216 ) {
struct V_219 * V_220 = ( * V_216 ) -> V_221 ;
int V_222 = V_217 ;
for (; V_220 -> V_223 ; ++ V_222 , ++ V_220 )
V_220 -> V_222 = V_222 ;
}
}
V_7 -> V_29 = V_214 -> V_29 ;
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
F_135 ( V_218 , & V_7 -> V_192 ) ;
F_102 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_104 * V_105 , * V_201 ;
unsigned V_61 , V_64 ;
F_20 () ;
V_64 = V_7 -> V_202 ;
V_201 = F_136 ( V_64 , sizeof( * V_201 ) , V_68 ) ;
if ( ! V_201 )
return - V_69 ;
V_105 = V_201 ;
for ( V_61 = 1 ; V_61 <= V_64 ; ++ V_61 , ++ V_105 ) {
V_105 -> V_7 = V_7 ;
F_125 ( & V_105 -> V_42 ) ;
F_127 ( & V_105 -> V_82 ) ;
if ( V_7 -> V_224 & V_225 )
sprintf ( V_105 -> V_163 , L_21 , V_7 -> V_226 [ V_61 ] ) ;
else
sprintf ( V_105 -> V_163 , L_22 , V_61 ) ;
V_105 -> V_162 = F_84 ( V_7 -> V_140 , V_105 -> V_163 ,
V_105 ,
& V_227 ) ;
if ( F_12 ( ! V_105 -> V_162 ) ) {
F_121 ( V_201 , V_61 - 1 ) ;
return - V_69 ;
}
}
V_7 -> V_201 = V_201 ;
return 0 ;
}
static void F_121 ( struct V_104 * V_201 , unsigned V_64 )
{
struct V_104 * V_105 = V_201 ;
F_20 () ;
for (; V_64 ; -- V_64 , ++ V_105 ) {
F_119 ( F_137 ( & V_105 -> V_42 ) ||
F_120 ( & V_105 -> V_82 ) ) ;
if ( V_105 -> V_162 ) {
F_138 ( V_105 -> V_162 ) ;
F_86 ( V_105 -> V_162 ) ;
V_105 -> V_162 = NULL ;
}
}
F_33 ( V_201 ) ;
}
static void F_139 ( struct V_1 * V_77 )
{
struct V_89 * V_12 = V_77 -> V_228 ;
struct V_104 * V_105 = V_77 -> V_7 -> V_201 ;
unsigned V_64 = V_77 -> V_7 -> V_202 ;
unsigned long V_192 ;
F_140 ( & V_77 -> V_7 -> V_111 , V_192 ) ;
do {
if ( F_39 ( V_12 -> V_12 ) )
F_141 ( V_12 -> V_12 ) ;
++ V_12 ;
if ( V_105 ) {
V_105 -> V_12 = NULL ;
++ V_105 ;
}
} while ( -- V_64 );
F_142 ( & V_77 -> V_7 -> V_111 , V_192 ) ;
}
static int F_143 ( struct V_1 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_89 * V_12 = V_77 -> V_228 ;
struct V_104 * V_105 = V_7 -> V_201 ;
unsigned V_64 = V_7 -> V_202 ;
unsigned long V_192 ;
int V_20 = 0 ;
F_140 ( & V_77 -> V_7 -> V_111 , V_192 ) ;
do {
struct V_133 * V_229 ;
int V_132 ;
if ( V_7 -> V_29 -> V_135 == V_136 )
V_132 = 2 ;
else if ( V_7 -> V_29 -> V_135 == V_137 )
V_132 = 1 ;
else
V_132 = 0 ;
do {
V_229 = V_12 -> V_138 [ V_132 ] ;
} while ( ! V_229 && -- V_132 >= 0 );
if ( ! V_229 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_90 = V_12 ;
V_12 -> V_12 -> V_134 = V_229 ;
V_20 = F_144 ( V_12 -> V_12 ) ;
if ( F_39 ( ! V_20 ) ) {
V_105 -> V_12 = V_12 ;
V_105 -> V_108 = F_145 ( V_229 ) ;
V_105 -> V_109 = F_146 ( V_229 ) ;
} else {
break;
}
F_147 ( & V_105 -> V_82 ) ;
++ V_12 ;
++ V_105 ;
} while ( -- V_64 );
F_142 ( & V_77 -> V_7 -> V_111 , V_192 ) ;
return V_20 ;
}
static int T_6 F_148 ( char * V_17 , unsigned V_18 ,
T_7 V_230 ,
void * V_231 )
{
struct V_232 * V_233 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_23 ) ;
return - V_48 ;
}
V_28 = V_233 -> V_234 ;
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
switch ( V_233 -> V_235 ) {
case V_236 :
case V_237 :
case V_238 :
case V_239 :
F_16 ( L_25 ,
V_233 -> V_235 ) ;
return - V_48 ;
case V_240 : {
struct V_241 * V_229 = ( void * ) V_233 ;
F_16 ( L_26 ) ;
if ( V_28 != sizeof *V_229 )
goto V_242;
F_152 ( V_243 , V_229 -> V_244 ) ;
if ( V_229 -> V_245 )
F_152 ( STRING , V_229 -> V_245 ) ;
}
break;
case V_246 : {
struct V_133 * V_229 = ( void * ) V_233 ;
F_16 ( L_27 ) ;
if ( V_28 != V_247 &&
V_28 != V_248 )
goto V_242;
F_152 ( V_249 , V_229 -> V_250 ) ;
}
break;
case V_251 :
F_16 ( L_28 ) ;
if ( V_28 != sizeof( struct V_252 ) )
goto V_242;
break;
case V_253 :
if ( V_28 != sizeof( struct V_254 ) )
goto V_242;
break;
case V_255 : {
struct V_256 * V_229 = ( void * ) V_233 ;
F_16 ( L_29 ) ;
if ( V_28 != sizeof *V_229 )
goto V_242;
if ( V_229 -> V_257 )
F_152 ( STRING , V_229 -> V_257 ) ;
}
break;
case V_258 :
F_16 ( L_30 ) ;
if ( V_28 != sizeof( struct V_259 ) )
goto V_242;
break;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
F_16 ( L_31 , V_233 -> V_235 ) ;
return - V_48 ;
default:
F_16 ( L_32 , V_233 -> V_235 ) ;
return - V_48 ;
V_242:
F_16 ( L_33 ,
V_233 -> V_234 , V_233 -> V_235 ) ;
return - V_48 ;
}
#undef F_152
#undef V_265
#undef F_149
#undef F_150
#undef F_151
return V_28 ;
}
static int T_6 F_153 ( unsigned V_64 , char * V_17 , unsigned V_18 ,
T_7 V_230 , void * V_231 )
{
const unsigned V_266 = V_18 ;
unsigned long V_130 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_130 == V_64 )
V_17 = NULL ;
V_20 = V_230 ( V_267 , ( T_8 * ) V_130 , ( void * ) V_17 , V_231 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_34 ,
V_130 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_266 - V_18 ;
V_20 = F_148 ( V_17 , V_18 , V_230 , V_231 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_35 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_130 ;
}
}
static int F_154 ( enum V_268 type ,
T_8 * V_269 , struct V_232 * V_134 ,
void * V_231 )
{
struct V_270 * V_271 = V_231 ;
struct V_133 * V_272 ;
F_20 () ;
switch ( type ) {
case V_267 :
break;
case V_273 :
if ( * V_269 >= V_271 -> V_212 )
V_271 -> V_212 = * V_269 + 1 ;
break;
case V_274 :
if ( * V_269 > V_271 -> V_7 -> V_211 )
V_271 -> V_7 -> V_211 = * V_269 ;
break;
case V_275 :
V_272 = ( void * ) V_134 ;
V_271 -> V_202 ++ ;
if ( V_271 -> V_202 >= 15 )
return - V_48 ;
if ( ! V_271 -> V_7 -> V_202 && ! V_271 -> V_7 -> V_212 )
V_271 -> V_7 -> V_226 [ V_271 -> V_202 ] =
V_272 -> V_250 ;
else if ( V_271 -> V_7 -> V_226 [ V_271 -> V_202 ] !=
V_272 -> V_250 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_155 ( enum V_276 * V_277 ,
struct V_278 * V_134 )
{
T_10 V_279 = F_8 ( V_134 -> V_280 ) ;
T_10 V_281 = F_8 ( V_134 -> V_282 ) ;
if ( V_279 != 1 ) {
F_16 ( L_36 ,
V_279 ) ;
return - V_48 ;
}
switch ( V_281 ) {
case 0x4 :
* V_277 = V_283 ;
break;
case 0x5 :
* V_277 = V_284 ;
break;
default:
F_16 ( L_37 , V_281 ) ;
return - V_48 ;
}
return sizeof( * V_134 ) ;
}
static int T_6 F_156 ( char * V_17 , unsigned V_18 ,
enum V_276 type ,
T_10 V_285 ,
T_11 V_230 ,
void * V_231 ,
struct V_278 * V_286 )
{
int V_20 ;
const unsigned V_266 = V_18 ;
F_20 () ;
while ( V_285 -- ) {
V_20 = V_230 ( type , V_286 , V_17 , V_18 , V_231 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 , type ) ;
return V_20 ;
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
return V_266 - V_18 ;
}
static int T_6 F_157 ( unsigned V_64 ,
char * V_17 , unsigned V_18 ,
T_11 V_230 , void * V_231 )
{
const unsigned V_266 = V_18 ;
unsigned long V_130 = 0 ;
F_20 () ;
for ( V_130 = 0 ; V_130 < V_64 ; ++ V_130 ) {
int V_20 ;
enum V_276 type ;
T_10 V_285 ;
struct V_278 * V_134 = ( void * ) V_17 ;
if ( V_18 < sizeof( * V_134 ) )
return - V_48 ;
if ( F_158 ( V_134 -> V_287 ) > V_18 )
return - V_48 ;
V_20 = F_155 ( & type , V_134 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_39 ,
V_130 , V_20 ) ;
return V_20 ;
}
V_285 = F_8 ( V_134 -> V_288 ) ;
if ( type == V_283 &&
( V_285 > 255 || V_134 -> V_289 ) )
return - V_48 ;
V_18 -= V_20 ;
V_17 += V_20 ;
V_20 = F_156 ( V_17 , V_18 , type ,
V_285 , V_230 , V_231 , V_134 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_35 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
return V_266 - V_18 ;
}
static int F_159 ( enum V_276 type ,
struct V_278 * V_286 , void * V_17 ,
unsigned V_18 , void * V_231 )
{
struct V_6 * V_7 = V_231 ;
T_8 V_28 ;
F_20 () ;
switch ( type ) {
case V_283 : {
struct V_290 * V_272 = V_17 ;
int V_61 ;
if ( V_18 < sizeof( * V_272 ) ||
V_272 -> V_291 >= V_7 -> V_212 ||
V_272 -> V_292 )
return - V_48 ;
for ( V_61 = 0 ; V_61 < F_35 ( V_272 -> V_293 ) ; ++ V_61 )
if ( V_272 -> V_293 [ V_61 ] )
return - V_48 ;
V_28 = sizeof( struct V_290 ) ;
}
break;
case V_284 : {
struct V_294 * V_272 = V_17 ;
T_12 type , V_295 ;
T_10 V_296 ;
if ( V_18 < sizeof( * V_272 ) || V_286 -> V_297 >= V_7 -> V_212 )
return - V_48 ;
V_28 = F_158 ( V_272 -> V_298 ) ;
type = F_158 ( V_272 -> V_299 ) ;
if ( type < V_300 ||
type > V_301 ) {
F_16 ( L_40 ,
type ) ;
return - V_48 ;
}
V_296 = F_8 ( V_272 -> V_302 ) ;
V_295 = F_158 ( * ( T_12 * ) ( ( T_8 * ) V_17 + 10 + V_296 ) ) ;
if ( V_28 != 14 + V_296 + V_295 ) {
F_16 ( L_41 ,
V_28 , V_296 , V_295 , type ) ;
return - V_48 ;
}
++ V_7 -> V_303 ;
V_7 -> V_304 += V_296 * 2 ;
V_7 -> V_305 += V_295 ;
}
break;
default:
F_16 ( L_32 , type ) ;
return - V_48 ;
}
return V_28 ;
}
static int F_26 ( struct V_6 * V_7 ,
char * const V_167 , T_1 V_18 )
{
char * V_17 = V_167 , * V_206 ;
unsigned V_306 = 0 , V_307 [ 3 ] , V_192 ;
int V_20 = - V_48 , V_61 ;
struct V_270 V_271 ;
F_20 () ;
if ( F_160 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_160 ( V_17 ) ) {
case V_308 :
V_192 = V_309 | V_310 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_311 :
V_192 = F_160 ( V_17 + 8 ) ;
V_7 -> V_224 = V_192 ;
if ( V_192 & ~ ( V_309 |
V_310 |
V_312 |
V_313 |
V_225 |
V_314 ) ) {
V_20 = - V_315 ;
goto error;
}
V_17 += 12 ;
V_18 -= 12 ;
break;
default:
goto error;
}
if ( V_192 & V_314 ) {
if ( V_18 < 4 )
goto error;
V_7 -> V_99 =
F_161 ( ( int ) F_160 ( V_17 ) ) ;
if ( F_23 ( V_7 -> V_99 ) ) {
V_20 = F_24 ( V_7 -> V_99 ) ;
V_7 -> V_99 = NULL ;
goto error;
}
V_17 += 4 ;
V_18 -= 4 ;
}
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! ( V_192 & ( 1 << V_61 ) ) ) {
V_307 [ V_61 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_307 [ V_61 ] = F_160 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
if ( V_192 & ( 1 << V_61 ) ) {
V_306 = F_160 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
} ;
V_206 = V_17 ;
V_271 . V_7 = V_7 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! V_307 [ V_61 ] )
continue;
V_271 . V_212 = 0 ;
V_271 . V_202 = 0 ;
V_20 = F_153 ( V_307 [ V_61 ] , V_17 , V_18 ,
F_154 , & V_271 ) ;
if ( V_20 < 0 )
goto error;
if ( ! V_7 -> V_202 && ! V_7 -> V_212 ) {
V_7 -> V_202 = V_271 . V_202 ;
V_7 -> V_212 = V_271 . V_212 ;
} else {
if ( V_7 -> V_202 != V_271 . V_202 ) {
V_20 = - V_48 ;
goto error;
}
if ( V_7 -> V_212 != V_271 . V_212 ) {
V_20 = - V_48 ;
goto error;
}
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_306 ) {
V_20 = F_157 ( V_306 , V_17 , V_18 ,
F_159 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_206 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_203 = V_167 ;
V_7 -> V_206 = V_206 ;
V_7 -> V_207 = V_17 - V_206 ;
V_7 -> V_208 = V_307 [ 0 ] ;
V_7 -> V_209 = V_307 [ 1 ] ;
V_7 -> V_210 = V_307 [ 2 ] ;
V_7 -> V_316 = V_306 ;
return 0 ;
error:
F_33 ( V_167 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_167 , T_1 V_18 )
{
T_12 V_317 , V_318 , V_319 ;
struct V_215 * * V_205 , * V_191 ;
struct V_219 * V_221 , * V_223 ;
const char * V_17 = V_167 ;
F_20 () ;
if ( F_12 ( F_160 ( V_17 ) != V_320 ||
F_160 ( V_17 + 4 ) != V_18 ) )
goto error;
V_317 = F_160 ( V_17 + 8 ) ;
V_319 = F_160 ( V_17 + 12 ) ;
if ( F_12 ( ! V_317 != ! V_319 ) )
goto error;
V_318 = V_7 -> V_211 ;
if ( F_12 ( V_317 < V_318 ) )
goto error;
if ( ! V_318 ) {
F_33 ( V_167 ) ;
return 0 ;
}
{
unsigned V_61 = 0 ;
F_162 ( V_272 ) ;
F_163 ( V_272 , struct V_215 * , V_205 ,
V_319 + 1 ) ;
F_163 ( V_272 , struct V_215 , V_321 , V_319 ) ;
F_163 ( V_272 , struct V_219 , V_221 ,
V_319 * ( V_318 + 1 ) ) ;
char * V_322 = F_40 ( F_164 ( V_272 ) , V_68 ) ;
if ( F_12 ( ! V_322 ) ) {
F_33 ( V_167 ) ;
return - V_69 ;
}
V_205 = F_165 ( V_322 , V_272 , V_205 ) ;
V_191 = F_165 ( V_322 , V_272 , V_321 ) ;
V_61 = V_319 ;
do {
* V_205 ++ = V_191 ++ ;
} while ( -- V_61 );
* V_205 = NULL ;
V_205 = F_165 ( V_322 , V_272 , V_205 ) ;
V_191 = F_165 ( V_322 , V_272 , V_321 ) ;
V_223 = F_165 ( V_322 , V_272 , V_221 ) ;
V_221 = V_223 ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_323 = V_318 ;
if ( F_12 ( V_18 < 3 ) )
goto V_324;
V_191 -> V_325 = F_166 ( V_17 ) ;
V_191 -> V_221 = V_223 ;
++ V_191 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_167 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_324;
if ( F_39 ( V_323 ) ) {
V_223 -> V_223 = V_17 ;
-- V_323 ;
++ V_223 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_317 );
V_223 -> V_222 = 0 ;
V_223 -> V_223 = NULL ;
++ V_223 ;
} while ( -- V_319 );
if ( F_12 ( V_18 ) )
goto V_324;
V_7 -> V_205 = V_205 ;
V_7 -> V_204 = V_167 ;
return 0 ;
V_324:
F_33 ( V_205 ) ;
error:
F_33 ( V_167 ) ;
return - V_48 ;
}
static void F_168 ( struct V_6 * V_7 ,
enum V_326 type )
{
enum V_326 V_327 , V_328 = type ;
int V_329 = 0 ;
if ( V_7 -> V_8 == V_52 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_330 :
V_328 = V_331 ;
case V_331 :
case V_62 :
V_327 = type ;
break;
case V_332 :
case V_333 :
case V_334 :
case V_335 :
V_327 = V_331 ;
V_328 = V_330 ;
V_329 = 1 ;
break;
default:
F_66 ( 1 , L_42 , type ) ;
return;
}
{
T_8 * V_22 = V_7 -> V_22 . V_59 , * V_336 = V_22 ;
unsigned V_56 = V_7 -> V_22 . V_64 ;
for (; V_56 ; -- V_56 , ++ V_22 )
if ( ( * V_22 == V_327 || * V_22 == V_328 ) == V_329 )
* V_336 ++ = * V_22 ;
else
F_16 ( L_43 , * V_22 ) ;
V_7 -> V_22 . V_64 = V_336 - V_7 -> V_22 . V_59 ;
}
F_16 ( L_44 , type ) ;
V_7 -> V_22 . V_59 [ V_7 -> V_22 . V_64 ++ ] = type ;
F_169 ( & V_7 -> V_22 . V_25 ) ;
if ( V_7 -> V_99 )
F_56 ( V_7 -> V_99 , 1 ) ;
}
static void F_170 ( struct V_6 * V_7 ,
enum V_326 type )
{
unsigned long V_192 ;
F_140 ( & V_7 -> V_22 . V_25 . V_26 , V_192 ) ;
F_168 ( V_7 , type ) ;
F_142 ( & V_7 -> V_22 . V_25 . V_26 , V_192 ) ;
}
static int F_171 ( struct V_6 * V_7 , T_8 V_337 )
{
int V_61 ;
for ( V_61 = 1 ; V_61 < F_35 ( V_7 -> V_226 ) ; ++ V_61 )
if ( V_7 -> V_226 [ V_61 ] == V_337 )
return V_61 ;
return - V_338 ;
}
static int F_172 ( enum V_268 type , T_8 * V_269 ,
struct V_232 * V_134 ,
void * V_231 )
{
struct V_133 * V_229 = ( void * ) V_134 ;
struct V_1 * V_77 = V_231 ;
struct V_89 * V_89 ;
unsigned V_339 ;
int V_340 ;
static const char * V_341 [] = { L_45 , L_46 , L_47 } ;
if ( type != V_267 )
return 0 ;
if ( V_77 -> V_4 . V_342 ) {
V_339 = 2 ;
V_77 -> V_4 . V_342 [ ( long ) V_269 ] = V_134 ;
} else if ( V_77 -> V_4 . V_343 ) {
V_339 = 1 ;
V_77 -> V_4 . V_343 [ ( long ) V_269 ] = V_134 ;
} else {
V_339 = 0 ;
V_77 -> V_4 . V_344 [ ( long ) V_269 ] = V_134 ;
}
if ( ! V_134 || V_134 -> V_235 != V_246 )
return 0 ;
V_340 = F_171 ( V_77 -> V_7 , V_229 -> V_250 ) - 1 ;
if ( V_340 < 0 )
return V_340 ;
V_89 = V_77 -> V_228 + V_340 ;
if ( F_12 ( V_89 -> V_138 [ V_339 ] ) ) {
F_91 ( L_48 ,
V_341 [ V_339 ] ,
V_229 -> V_250 & V_345 ) ;
return - V_48 ;
}
V_89 -> V_138 [ V_339 ] = V_229 ;
F_173 ( L_49 , V_229 , V_229 -> V_234 ) ;
if ( V_89 -> V_12 ) {
V_229 -> V_250 = V_89 -> V_138 [ 0 ] -> V_250 ;
if ( ! V_229 -> V_346 )
V_229 -> V_346 = V_89 -> V_138 [ 0 ] -> V_346 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_8 V_250 ;
V_250 = V_229 -> V_250 ;
F_16 ( L_50 ) ;
V_12 = F_174 ( V_77 -> V_29 , V_229 ) ;
if ( F_12 ( ! V_12 ) )
return - V_347 ;
V_12 -> V_90 = V_77 -> V_228 + V_340 ;
V_14 = F_67 ( V_12 , V_68 ) ;
if ( F_12 ( ! V_14 ) )
return - V_69 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_14 = V_14 ;
V_77 -> V_348 [ V_229 -> V_250 &
V_345 ] = V_340 + 1 ;
if ( V_77 -> V_7 -> V_224 & V_225 )
V_229 -> V_250 = V_250 ;
}
F_173 ( L_51 , V_229 , V_229 -> V_234 ) ;
return 0 ;
}
static int F_175 ( enum V_268 type , T_8 * V_269 ,
struct V_232 * V_134 ,
void * V_231 )
{
struct V_1 * V_77 = V_231 ;
unsigned V_340 ;
T_8 V_349 ;
switch ( type ) {
default:
case V_267 :
return 0 ;
case V_273 :
V_340 = * V_269 ;
if ( V_77 -> V_350 [ V_340 ] < 0 ) {
int V_222 = F_176 ( V_77 -> V_351 , & V_77 -> V_4 ) ;
if ( F_12 ( V_222 < 0 ) )
return V_222 ;
V_77 -> V_350 [ V_340 ] = V_222 ;
}
V_349 = V_77 -> V_350 [ V_340 ] ;
break;
case V_274 :
V_349 = V_77 -> V_7 -> V_205 [ 0 ] -> V_221 [ * V_269 - 1 ] . V_222 ;
break;
case V_275 :
if ( V_134 -> V_235 == V_246 )
return 0 ;
V_340 = ( * V_269 & V_345 ) - 1 ;
if ( F_12 ( ! V_77 -> V_228 [ V_340 ] . V_12 ) )
return - V_48 ;
{
struct V_133 * * V_138 ;
V_138 = V_77 -> V_228 [ V_340 ] . V_138 ;
V_349 = V_138 [ V_138 [ 0 ] ? 0 : 1 ] -> V_250 ;
}
break;
}
F_16 ( L_52 , * V_269 , V_349 ) ;
* V_269 = V_349 ;
return 0 ;
}
static int F_177 ( enum V_276 type ,
struct V_278 * V_286 , void * V_17 ,
unsigned V_18 , void * V_231 )
{
struct V_1 * V_77 = V_231 ;
T_8 V_28 = 0 ;
switch ( type ) {
case V_283 : {
struct V_290 * V_134 = V_17 ;
struct V_352 * V_191 ;
V_191 = & V_77 -> V_4 . V_353 [ V_134 -> V_291 ] ;
V_191 -> V_354 = V_77 -> V_350 [ V_134 -> V_291 ] ;
memcpy ( V_191 -> V_355 -> V_356 , & V_134 -> V_357 ,
F_35 ( V_134 -> V_357 ) +
F_35 ( V_134 -> V_358 ) ) ;
V_28 = sizeof( * V_134 ) ;
}
break;
case V_284 : {
struct V_294 * V_134 = V_17 ;
struct V_352 * V_191 ;
struct V_359 * V_360 ;
char * V_361 ;
char * V_362 ;
V_191 = & V_77 -> V_4 . V_353 [ V_286 -> V_297 ] ;
V_191 -> V_354 = V_77 -> V_350 [ V_286 -> V_297 ] ;
V_360 = V_77 -> V_7 -> V_363 ;
V_77 -> V_7 -> V_363 += sizeof( * V_360 ) ;
V_360 -> type = F_158 ( V_134 -> V_299 ) ;
V_360 -> V_364 = F_8 ( V_134 -> V_302 ) ;
V_360 -> V_106 = F_158 ( * ( T_12 * )
F_178 ( V_17 , V_360 -> V_364 ) ) ;
V_28 = V_360 -> V_364 + V_360 -> V_106 + 14 ;
V_361 = V_77 -> V_7 -> V_365 ;
V_77 -> V_7 -> V_365 +=
V_360 -> V_364 ;
V_362 = V_77 -> V_7 -> V_366 ;
V_77 -> V_7 -> V_366 +=
V_360 -> V_106 ;
memcpy ( V_362 ,
F_179 ( V_17 , V_360 -> V_364 ) ,
V_360 -> V_106 ) ;
switch ( V_360 -> type ) {
case V_300 :
case V_367 :
case V_368 :
case V_301 :
V_360 -> V_106 *= 2 ;
break;
}
V_360 -> V_17 = V_362 ;
memcpy ( V_361 , F_180 ( V_17 ) ,
V_360 -> V_364 ) ;
V_360 -> V_364 *= 2 ;
V_360 -> V_163 = V_361 ;
V_191 -> V_355 -> V_369 +=
V_360 -> V_364 + V_360 -> V_106 + 14 ;
++ V_191 -> V_355 -> V_370 ;
F_181 ( & V_360 -> V_371 , & V_191 -> V_355 -> V_360 ) ;
}
break;
default:
F_16 ( L_32 , type ) ;
}
return V_28 ;
}
static inline struct V_372 * F_182 ( struct V_2 * V_3 ,
struct V_373 * V_374 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_372 * V_375 =
F_2 ( V_3 -> V_376 , struct V_372 , V_377 ) ;
int V_20 ;
F_20 () ;
if ( ! V_375 -> V_378 )
F_183 () ;
V_20 = V_375 -> V_379 -> V_380 ? 0 : - V_78 ;
V_77 -> V_7 = V_375 -> V_379 -> V_6 ;
if ( ! V_375 -> V_378 )
F_184 () ;
if ( V_20 )
return F_99 ( V_20 ) ;
V_77 -> V_351 = V_374 ;
V_77 -> V_29 = V_374 -> V_214 -> V_29 ;
if ( ! V_375 -> V_381 ) {
V_20 = F_131 ( V_77 -> V_7 , V_374 -> V_214 ) ;
if ( V_20 )
return F_99 ( V_20 ) ;
}
V_375 -> V_381 ++ ;
V_77 -> V_4 . V_221 = V_77 -> V_7 -> V_205 ;
return V_375 ;
}
static int F_185 ( struct V_373 * V_374 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
const int V_382 = ! ! V_77 -> V_7 -> V_208 ;
const int V_383 = F_186 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_209 ;
const int V_384 = F_187 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_210 ;
int V_385 , V_386 , V_387 , V_20 , V_61 ;
F_162 ( V_272 ) ;
F_188 ( V_272 , struct V_89 , V_228 , V_7 -> V_202 ) ;
F_188 ( V_272 , struct V_232 * , V_388 ,
V_382 ? V_7 -> V_208 + 1 : 0 ) ;
F_188 ( V_272 , struct V_232 * , V_389 ,
V_383 ? V_7 -> V_209 + 1 : 0 ) ;
F_188 ( V_272 , struct V_232 * , V_390 ,
V_384 ? V_7 -> V_210 + 1 : 0 ) ;
F_188 ( V_272 , short , V_391 , V_7 -> V_212 ) ;
F_188 ( V_272 , struct V_352 , V_353 ,
V_374 -> V_214 -> V_392 ? V_7 -> V_212 : 0 ) ;
F_188 ( V_272 , char [ 16 ] , V_393 ,
V_374 -> V_214 -> V_392 ? V_7 -> V_212 : 0 ) ;
F_188 ( V_272 , struct V_394 , V_355 ,
V_374 -> V_214 -> V_392 ? V_7 -> V_212 : 0 ) ;
F_188 ( V_272 , struct V_359 , V_360 ,
V_7 -> V_303 ) ;
F_188 ( V_272 , char , V_361 ,
V_7 -> V_304 ) ;
F_188 ( V_272 , char , V_362 ,
V_7 -> V_305 ) ;
F_188 ( V_272 , char , V_206 , V_7 -> V_207 ) ;
char * V_322 ;
F_20 () ;
if ( F_12 ( ! ( V_382 | V_383 | V_384 ) ) )
return - V_347 ;
V_322 = F_123 ( F_164 ( V_272 ) , V_68 ) ;
if ( F_12 ( ! V_322 ) )
return - V_69 ;
V_7 -> V_363 = F_165 ( V_322 , V_272 , V_360 ) ;
V_7 -> V_365 =
F_165 ( V_322 , V_272 , V_361 ) ;
V_7 -> V_366 =
F_165 ( V_322 , V_272 , V_362 ) ;
memcpy ( F_165 ( V_322 , V_272 , V_206 ) , V_7 -> V_206 ,
V_7 -> V_207 ) ;
memset ( F_165 ( V_322 , V_272 , V_391 ) , 0xff , V_395 ) ;
for ( V_20 = V_7 -> V_202 ; V_20 ; -- V_20 ) {
struct V_89 * V_39 ;
V_39 = F_165 ( V_322 , V_272 , V_228 ) ;
V_39 [ V_20 ] . V_130 = - 1 ;
}
V_77 -> V_228 = F_165 ( V_322 , V_272 , V_228 ) ;
V_77 -> V_350 = F_165 ( V_322 , V_272 , V_391 ) ;
if ( F_39 ( V_382 ) ) {
V_77 -> V_4 . V_344 = F_165 ( V_322 , V_272 , V_388 ) ;
V_385 = F_153 ( V_7 -> V_208 ,
F_165 ( V_322 , V_272 , V_206 ) ,
V_396 ,
F_172 , V_77 ) ;
if ( F_12 ( V_385 < 0 ) ) {
V_20 = V_385 ;
goto error;
}
} else {
V_385 = 0 ;
}
if ( F_39 ( V_383 ) ) {
V_77 -> V_4 . V_343 = F_165 ( V_322 , V_272 , V_389 ) ;
V_386 = F_153 ( V_7 -> V_209 ,
F_165 ( V_322 , V_272 , V_206 ) + V_385 ,
V_396 - V_385 ,
F_172 , V_77 ) ;
if ( F_12 ( V_386 < 0 ) ) {
V_20 = V_386 ;
goto error;
}
} else {
V_386 = 0 ;
}
if ( F_39 ( V_384 ) ) {
V_77 -> V_4 . V_342 = F_165 ( V_322 , V_272 , V_390 ) ;
V_387 = F_153 ( V_7 -> V_210 ,
F_165 ( V_322 , V_272 , V_206 ) + V_385 + V_386 ,
V_396 - V_385 - V_386 ,
F_172 , V_77 ) ;
if ( F_12 ( V_387 < 0 ) ) {
V_20 = V_387 ;
goto error;
}
} else {
V_387 = 0 ;
}
V_20 = F_153 ( V_7 -> V_208 +
( V_383 ? V_7 -> V_209 : 0 ) +
( V_384 ? V_7 -> V_210 : 0 ) ,
F_165 ( V_322 , V_272 , V_206 ) , V_396 ,
F_175 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_77 -> V_4 . V_353 = F_165 ( V_322 , V_272 , V_353 ) ;
if ( V_374 -> V_214 -> V_392 )
for ( V_61 = 0 ; V_61 < V_7 -> V_212 ; ++ V_61 ) {
struct V_394 * V_134 ;
V_134 = V_77 -> V_4 . V_353 [ V_61 ] . V_355 =
F_165 ( V_322 , V_272 , V_355 ) +
V_61 * sizeof( struct V_394 ) ;
V_134 -> V_356 =
F_165 ( V_322 , V_272 , V_393 ) + V_61 * 16 ;
F_189 ( & V_134 -> V_360 ) ;
}
V_20 = F_157 ( V_7 -> V_316 ,
F_165 ( V_322 , V_272 , V_206 ) +
V_385 + V_386 + V_387 ,
V_396 - V_385 - V_386 - V_387 ,
F_177 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_77 -> V_4 . V_397 =
V_374 -> V_214 -> V_392 ? V_7 -> V_212 : 0 ;
F_170 ( V_7 , V_332 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_190 ( struct V_373 * V_374 ,
struct V_2 * V_3 )
{
struct V_372 * V_375 = F_182 ( V_3 , V_374 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_20 ;
if ( F_23 ( V_375 ) )
return F_24 ( V_375 ) ;
V_20 = F_185 ( V_374 , V_3 ) ;
if ( V_20 && ! -- V_375 -> V_381 )
F_134 ( V_77 -> V_7 ) ;
return V_20 ;
}
static void F_191 ( struct V_91 * V_92 )
{
struct V_6 * V_7 = F_2 ( V_92 ,
struct V_6 , V_398 ) ;
F_116 ( V_7 ) ;
}
static int F_192 ( struct V_2 * V_3 ,
unsigned V_297 , unsigned V_399 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
int V_20 = 0 , V_400 ;
if ( V_399 != ( unsigned ) - 1 ) {
V_400 = F_46 ( V_77 , V_297 ) ;
if ( F_12 ( V_400 < 0 ) )
return V_400 ;
}
if ( V_7 -> V_77 )
F_139 ( V_7 -> V_77 ) ;
if ( V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_59 ( & V_7 -> V_398 , F_191 ) ;
F_60 ( & V_7 -> V_398 ) ;
return - V_78 ;
}
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
if ( V_399 == ( unsigned ) - 1 ) {
V_7 -> V_77 = NULL ;
F_170 ( V_7 , V_334 ) ;
return 0 ;
}
V_7 -> V_77 = V_77 ;
V_20 = F_143 ( V_77 ) ;
if ( F_39 ( V_20 >= 0 ) )
F_170 ( V_7 , V_335 ) ;
return V_20 ;
}
static void F_193 ( struct V_2 * V_3 )
{
F_192 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_194 ( struct V_2 * V_3 ,
const struct V_401 * V_402 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
unsigned long V_192 ;
int V_20 ;
F_20 () ;
F_16 ( L_53 , V_402 -> V_53 ) ;
F_16 ( L_54 , V_402 -> V_403 ) ;
F_16 ( L_55 , F_8 ( V_402 -> V_404 ) ) ;
F_16 ( L_56 , F_8 ( V_402 -> V_282 ) ) ;
F_16 ( L_57 , F_8 ( V_402 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
switch ( V_402 -> V_53 & V_405 ) {
case V_406 :
V_20 = F_46 ( V_77 , F_8 ( V_402 -> V_282 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_407 :
V_20 = F_195 ( V_77 , F_8 ( V_402 -> V_282 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_77 -> V_7 -> V_224 & V_225 )
V_20 = V_77 -> V_7 -> V_226 [ V_20 ] ;
break;
default:
return - V_408 ;
}
F_140 ( & V_7 -> V_22 . V_25 . V_26 , V_192 ) ;
V_7 -> V_22 . V_23 = * V_402 ;
V_7 -> V_22 . V_23 . V_282 = F_196 ( V_20 ) ;
F_168 ( V_7 , V_62 ) ;
F_142 ( & V_7 -> V_22 . V_25 . V_26 , V_192 ) ;
return 0 ;
}
static void F_197 ( struct V_2 * V_3 )
{
F_20 () ;
F_170 ( F_1 ( V_3 ) -> V_7 , V_331 ) ;
}
static void F_198 ( struct V_2 * V_3 )
{
F_20 () ;
F_170 ( F_1 ( V_3 ) -> V_7 , V_330 ) ;
}
static int F_195 ( struct V_1 * V_77 , T_8 V_130 )
{
V_130 = V_77 -> V_348 [ V_130 & V_345 ] ;
return V_130 ? V_130 : - V_409 ;
}
static int F_46 ( struct V_1 * V_77 , T_8 V_400 )
{
short * V_410 = V_77 -> V_350 ;
unsigned V_64 = V_77 -> V_7 -> V_212 ;
for (; V_64 ; -- V_64 , ++ V_410 ) {
if ( * V_410 >= 0 && * V_410 == V_400 )
return V_410 - V_77 -> V_350 ;
}
return - V_409 ;
}
static struct V_197 * F_199 ( const char * V_163 )
{
struct V_197 * V_379 ;
F_200 (dev, &ffs_devices, entry) {
if ( ! V_379 -> V_163 || ! V_163 )
continue;
if ( strcmp ( V_379 -> V_163 , V_163 ) == 0 )
return V_379 ;
}
return NULL ;
}
static struct V_197 * F_201 ( void )
{
struct V_197 * V_379 ;
if ( F_202 ( & V_411 ) ) {
V_379 = F_203 ( & V_411 , struct V_197 , V_371 ) ;
if ( V_379 -> V_412 )
return V_379 ;
}
return NULL ;
}
static struct V_197 * F_204 ( const char * V_163 )
{
struct V_197 * V_379 ;
V_379 = F_201 () ;
if ( V_379 )
return V_379 ;
return F_199 ( V_163 ) ;
}
static inline struct V_372 * F_205 ( struct V_413 * V_414 )
{
return F_2 ( F_206 ( V_414 ) , struct V_372 ,
V_377 . V_415 ) ;
}
static void F_207 ( struct V_413 * V_414 )
{
struct V_372 * V_183 = F_205 ( V_414 ) ;
F_208 ( & V_183 -> V_377 ) ;
}
static void F_209 ( struct V_416 * V_3 )
{
struct V_372 * V_183 ;
V_183 = F_210 ( V_3 ) ;
F_183 () ;
F_211 ( V_183 -> V_379 ) ;
F_184 () ;
F_33 ( V_183 ) ;
}
static int F_212 ( struct V_416 * V_376 , const char * V_163 )
{
struct V_372 * V_183 ;
char * V_39 ;
const char * V_417 ;
int V_364 , V_20 ;
V_364 = strlen ( V_163 ) + 1 ;
if ( V_364 > V_418 )
return - V_419 ;
V_39 = F_213 ( V_163 , V_364 , V_68 ) ;
if ( ! V_39 )
return - V_69 ;
V_183 = F_210 ( V_376 ) ;
V_417 = NULL ;
F_183 () ;
V_417 = V_183 -> V_379 -> V_420 ? V_183 -> V_379 -> V_163 : NULL ;
V_20 = F_214 ( V_183 -> V_379 , V_39 ) ;
if ( V_20 ) {
F_33 ( V_39 ) ;
F_184 () ;
return V_20 ;
}
V_183 -> V_379 -> V_420 = true ;
F_184 () ;
F_33 ( V_417 ) ;
return 0 ;
}
static struct V_416 * F_215 ( void )
{
struct V_372 * V_183 ;
struct V_197 * V_379 ;
V_183 = F_123 ( sizeof( * V_183 ) , V_68 ) ;
if ( ! V_183 )
return F_99 ( - V_69 ) ;
V_183 -> V_377 . V_421 = F_212 ;
V_183 -> V_377 . V_422 = F_209 ;
F_183 () ;
V_379 = F_216 () ;
F_184 () ;
if ( F_23 ( V_379 ) ) {
F_33 ( V_183 ) ;
return F_104 ( V_379 ) ;
}
V_183 -> V_379 = V_379 ;
V_379 -> V_183 = V_183 ;
F_217 ( & V_183 -> V_377 . V_415 , L_58 ,
& V_423 ) ;
return & V_183 -> V_377 ;
}
static void F_218 ( struct V_2 * V_3 )
{
F_33 ( F_1 ( V_3 ) ) ;
}
static void F_219 ( struct V_373 * V_374 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_372 * V_183 =
F_2 ( V_3 -> V_376 , struct V_372 , V_377 ) ;
struct V_89 * V_12 = V_77 -> V_228 ;
unsigned V_64 = V_7 -> V_202 ;
unsigned long V_192 ;
F_20 () ;
if ( V_7 -> V_77 == V_77 ) {
F_139 ( V_77 ) ;
V_7 -> V_77 = NULL ;
}
if ( ! -- V_183 -> V_381 )
F_134 ( V_7 ) ;
F_140 ( & V_77 -> V_7 -> V_111 , V_192 ) ;
do {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_57 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
} while ( -- V_64 );
F_142 ( & V_77 -> V_7 -> V_111 , V_192 ) ;
F_33 ( V_77 -> V_228 ) ;
V_77 -> V_228 = NULL ;
V_77 -> V_4 . V_344 = NULL ;
V_77 -> V_4 . V_343 = NULL ;
V_77 -> V_4 . V_342 = NULL ;
V_77 -> V_350 = NULL ;
F_170 ( V_7 , V_333 ) ;
}
static struct V_2 * F_220 ( struct V_416 * V_376 )
{
struct V_1 * V_77 ;
F_20 () ;
V_77 = F_123 ( sizeof( * V_77 ) , V_68 ) ;
if ( F_12 ( ! V_77 ) )
return F_99 ( - V_69 ) ;
V_77 -> V_4 . V_163 = L_59 ;
V_77 -> V_4 . V_424 = F_190 ;
V_77 -> V_4 . V_425 = F_219 ;
V_77 -> V_4 . V_426 = F_192 ;
V_77 -> V_4 . V_427 = F_193 ;
V_77 -> V_4 . V_23 = F_194 ;
V_77 -> V_4 . V_428 = F_197 ;
V_77 -> V_4 . V_429 = F_198 ;
V_77 -> V_4 . V_430 = F_218 ;
return & V_77 -> V_4 ;
}
static struct V_197 * F_216 ( void )
{
struct V_197 * V_379 ;
int V_20 ;
if ( F_201 () )
return F_99 ( - V_72 ) ;
V_379 = F_123 ( sizeof( * V_379 ) , V_68 ) ;
if ( ! V_379 )
return F_99 ( - V_69 ) ;
if ( F_221 ( & V_411 ) ) {
V_20 = F_109 () ;
if ( V_20 ) {
F_33 ( V_379 ) ;
return F_99 ( V_20 ) ;
}
}
F_222 ( & V_379 -> V_371 , & V_411 ) ;
return V_379 ;
}
static int F_214 ( struct V_197 * V_379 , const char * V_163 )
{
struct V_197 * V_431 ;
V_431 = F_199 ( V_163 ) ;
if ( V_431 )
return - V_72 ;
V_379 -> V_163 = V_163 ;
return 0 ;
}
int F_223 ( struct V_197 * V_379 , const char * V_163 )
{
int V_20 ;
F_183 () ;
V_20 = F_214 ( V_379 , V_163 ) ;
F_184 () ;
return V_20 ;
}
int F_224 ( struct V_197 * V_379 )
{
int V_20 ;
V_20 = 0 ;
F_183 () ;
if ( ! F_202 ( & V_411 ) )
V_20 = - V_72 ;
else
V_379 -> V_412 = true ;
F_184 () ;
return V_20 ;
}
static void F_211 ( struct V_197 * V_379 )
{
F_225 ( & V_379 -> V_371 ) ;
if ( V_379 -> V_420 )
F_33 ( V_379 -> V_163 ) ;
F_33 ( V_379 ) ;
if ( F_221 ( & V_411 ) )
F_111 () ;
}
static void * F_103 ( const char * V_193 )
{
struct V_197 * V_197 ;
F_20 () ;
F_183 () ;
V_197 = F_204 ( V_193 ) ;
if ( ! V_197 )
V_197 = F_99 ( - V_338 ) ;
else if ( V_197 -> V_432 )
V_197 = F_99 ( - V_72 ) ;
else if ( V_197 -> V_433 &&
V_197 -> V_433 ( V_197 ) )
V_197 = F_99 ( - V_338 ) ;
else
V_197 -> V_432 = true ;
F_184 () ;
return V_197 ;
}
static void F_106 ( struct V_6 * V_6 )
{
struct V_197 * V_197 ;
F_20 () ;
F_183 () ;
V_197 = V_6 -> V_40 ;
if ( V_197 ) {
V_197 -> V_432 = false ;
if ( V_197 -> V_434 )
V_197 -> V_434 ( V_197 ) ;
}
F_184 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_197 * V_435 ;
int V_20 = 0 ;
F_20 () ;
F_183 () ;
V_435 = V_7 -> V_40 ;
if ( ! V_435 ) {
V_20 = - V_48 ;
goto V_118;
}
if ( F_62 ( V_435 -> V_380 ) ) {
V_20 = - V_72 ;
goto V_118;
}
V_435 -> V_380 = true ;
V_435 -> V_6 = V_7 ;
if ( V_435 -> V_436 ) {
V_20 = V_435 -> V_436 ( V_7 ) ;
if ( V_20 )
goto V_118;
}
F_226 ( V_437 , & V_7 -> V_192 ) ;
V_118:
F_184 () ;
return V_20 ;
}
static void F_129 ( struct V_6 * V_7 )
{
struct V_197 * V_435 ;
struct V_372 * V_183 ;
F_20 () ;
F_183 () ;
V_435 = V_7 -> V_40 ;
if ( ! V_435 )
goto V_118;
V_435 -> V_380 = false ;
if ( F_227 ( V_437 , & V_7 -> V_192 ) &&
V_435 -> V_438 )
V_435 -> V_438 ( V_7 ) ;
if ( V_435 -> V_183 )
V_183 = V_435 -> V_183 ;
else
goto V_118;
if ( V_183 -> V_378 || ! V_183 -> V_377 . V_415 . V_439 . V_440
|| ! F_122 ( & V_183 -> V_377 . V_415 . V_439 . V_441 . V_442 ) )
goto V_118;
F_228 ( V_435 -> V_183 ->
V_377 . V_415 . V_439 . V_440 -> V_440 ) ;
V_118:
F_184 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_443 )
{
return V_443
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
