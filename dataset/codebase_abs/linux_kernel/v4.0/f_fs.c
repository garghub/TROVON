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
F_31 ( V_51 , & V_7 -> V_52 ) ;
return V_18 ;
}
break;
case V_50 :
V_17 = NULL ;
F_32 ( & V_7 -> V_22 . V_25 . V_26 ) ;
switch ( F_3 ( V_7 ) ) {
case V_9 :
V_20 = - V_41 ;
goto V_53;
case V_10 :
V_20 = - V_37 ;
goto V_53;
case V_54 :
break;
}
if ( ! ( V_7 -> V_22 . V_23 . V_55 & V_56 ) ) {
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_20 = F_15 ( V_7 ) ;
break;
}
V_18 = F_33 ( V_18 , ( T_1 ) F_8 ( V_7 -> V_22 . V_23 . V_24 ) ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_17 = F_22 ( V_27 , V_18 ) ;
if ( F_23 ( V_17 ) ) {
V_20 = F_24 ( V_17 ) ;
break;
}
F_32 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_3 ( V_7 ) ==
V_9 ) {
V_20 = - V_41 ;
V_53:
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
} else {
V_20 = F_7 ( V_7 , V_17 , V_18 ) ;
}
F_34 ( V_17 ) ;
break;
default:
V_20 = - V_57 ;
break;
}
F_29 ( & V_7 -> V_42 ) ;
return V_20 ;
}
static T_2 F_35 ( struct V_6 * V_7 , char T_3 * V_27 ,
T_1 V_58 )
{
struct V_59 V_60 [ F_36 ( V_7 -> V_22 . V_61 ) ] ;
const T_1 V_62 = V_58 * sizeof *V_60 ;
unsigned V_63 = 0 ;
memset ( V_60 , 0 , V_62 ) ;
do {
V_60 [ V_63 ] . type = V_7 -> V_22 . V_61 [ V_63 ] ;
if ( V_60 [ V_63 ] . type == V_64 ) {
V_60 [ V_63 ] . V_65 . V_23 = V_7 -> V_22 . V_23 ;
V_7 -> V_8 = V_54 ;
}
} while ( ++ V_63 < V_58 );
V_7 -> V_22 . V_66 -= V_58 ;
if ( V_7 -> V_22 . V_66 )
memmove ( V_7 -> V_22 . V_61 , V_7 -> V_22 . V_61 + V_58 ,
V_7 -> V_22 . V_66 * sizeof * V_7 -> V_22 . V_61 ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
F_29 ( & V_7 -> V_42 ) ;
return F_12 ( F_37 ( V_27 , V_60 , V_62 ) ) ? - V_67 : V_62 ;
}
static T_2 F_38 ( struct V_38 * V_38 , char T_3 * V_27 ,
T_1 V_18 , T_4 * V_39 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
char * V_17 = NULL ;
T_1 V_58 ;
int V_20 ;
F_20 () ;
if ( F_3 ( V_7 ) == V_9 )
return - V_41 ;
V_20 = F_21 ( & V_7 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_7 -> V_45 != V_50 ) {
V_20 = - V_57 ;
goto V_68;
}
F_32 ( & V_7 -> V_22 . V_25 . V_26 ) ;
switch ( F_3 ( V_7 ) ) {
case V_9 :
V_20 = - V_41 ;
break;
case V_10 :
V_58 = V_18 / sizeof( struct V_59 ) ;
if ( F_12 ( ! V_58 ) ) {
V_20 = - V_48 ;
break;
}
if ( ( V_38 -> V_43 & V_44 ) && ! V_7 -> V_22 . V_66 ) {
V_20 = - V_69 ;
break;
}
if ( F_39 ( V_7 -> V_22 . V_25 ,
V_7 -> V_22 . V_66 ) ) {
V_20 = - V_32 ;
break;
}
return F_35 ( V_7 , V_27 ,
F_33 ( V_58 , ( T_1 ) V_7 -> V_22 . V_66 ) ) ;
case V_54 :
if ( V_7 -> V_22 . V_23 . V_55 & V_56 ) {
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_20 = F_15 ( V_7 ) ;
goto V_68;
}
V_18 = F_33 ( V_18 , ( T_1 ) F_8 ( V_7 -> V_22 . V_23 . V_24 ) ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_40 ( V_18 ) ) {
V_17 = F_41 ( V_18 , V_70 ) ;
if ( F_12 ( ! V_17 ) ) {
V_20 = - V_71 ;
goto V_68;
}
}
F_32 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_3 ( V_7 ) ==
V_9 ) {
V_20 = - V_41 ;
break;
}
V_20 = F_7 ( V_7 , V_17 , V_18 ) ;
if ( F_40 ( V_20 > 0 ) && F_12 ( F_37 ( V_27 , V_17 , V_18 ) ) )
V_20 = - V_67 ;
goto V_68;
default:
V_20 = - V_57 ;
break;
}
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_68:
F_29 ( & V_7 -> V_42 ) ;
F_34 ( V_17 ) ;
return V_20 ;
}
static int F_42 ( struct V_72 * V_72 , struct V_38 * V_38 )
{
struct V_6 * V_7 = V_72 -> V_73 ;
F_20 () ;
if ( F_12 ( V_7 -> V_45 == V_49 ) )
return - V_74 ;
V_38 -> V_40 = V_7 ;
F_43 ( V_7 ) ;
return 0 ;
}
static int F_44 ( struct V_72 * V_72 , struct V_38 * V_38 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
F_20 () ;
F_45 ( V_7 ) ;
return 0 ;
}
static long F_46 ( struct V_38 * V_38 , unsigned V_75 , unsigned long V_76 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
struct V_77 * V_29 = V_7 -> V_29 ;
long V_20 ;
F_20 () ;
if ( V_75 == V_78 ) {
struct V_1 * V_79 = V_7 -> V_79 ;
V_20 = V_79 ? F_47 ( V_79 , V_76 ) : - V_80 ;
} else if ( V_29 && V_29 -> V_81 -> V_82 ) {
V_20 = V_29 -> V_81 -> V_82 ( V_29 , V_75 , V_76 ) ;
} else {
V_20 = - V_83 ;
}
return V_20 ;
}
static unsigned int F_48 ( struct V_38 * V_38 , T_5 * V_84 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
unsigned int V_85 = V_86 ;
int V_20 ;
F_49 ( V_38 , & V_7 -> V_22 . V_25 , V_84 ) ;
V_20 = F_21 ( & V_7 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 < 0 ) )
return V_85 ;
switch ( V_7 -> V_45 ) {
case V_46 :
case V_47 :
V_85 |= V_87 ;
break;
case V_50 :
switch ( V_7 -> V_8 ) {
case V_10 :
if ( V_7 -> V_22 . V_66 )
V_85 |= V_88 ;
break;
case V_54 :
case V_9 :
V_85 |= ( V_88 | V_87 ) ;
break;
}
case V_49 :
break;
case V_89 :
break;
}
F_29 ( & V_7 -> V_42 ) ;
return V_85 ;
}
static void F_50 ( struct V_11 * V_90 , struct V_13 * V_14 )
{
F_20 () ;
if ( F_40 ( V_14 -> V_15 ) ) {
struct V_91 * V_12 = V_90 -> V_92 ;
V_12 -> V_33 = V_14 -> V_33 ? V_14 -> V_33 : V_14 -> V_34 ;
F_51 ( V_14 -> V_15 ) ;
}
}
static void F_52 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = F_2 ( V_94 , struct V_95 ,
V_94 ) ;
int V_20 = V_96 -> V_14 -> V_33 ? V_96 -> V_14 -> V_33 :
V_96 -> V_14 -> V_34 ;
if ( V_96 -> V_97 && V_20 > 0 ) {
F_53 ( V_96 -> V_98 ) ;
V_20 = F_54 ( V_96 -> V_27 , V_20 , & V_96 -> V_17 ) ;
if ( F_55 ( & V_96 -> V_17 ) )
V_20 = - V_67 ;
F_56 ( V_96 -> V_98 ) ;
}
F_57 ( V_96 -> V_99 , V_20 , V_20 ) ;
if ( V_96 -> V_7 -> V_100 && ! V_96 -> V_99 -> V_101 )
F_58 ( V_96 -> V_7 -> V_100 , 1 ) ;
F_59 ( V_96 -> V_12 , V_96 -> V_14 ) ;
V_96 -> V_99 -> V_102 = NULL ;
if ( V_96 -> V_97 )
F_34 ( V_96 -> V_103 ) ;
F_34 ( V_96 -> V_27 ) ;
F_34 ( V_96 ) ;
}
static void F_60 ( struct V_11 * V_90 ,
struct V_13 * V_14 )
{
struct V_95 * V_96 = V_14 -> V_15 ;
F_20 () ;
F_61 ( & V_96 -> V_94 , F_52 ) ;
F_62 ( & V_96 -> V_94 ) ;
}
static T_2 F_63 ( struct V_38 * V_38 , struct V_95 * V_96 )
{
struct V_104 * V_105 = V_38 -> V_40 ;
struct V_91 * V_12 ;
char * V_17 = NULL ;
T_2 V_20 , V_106 = - V_48 ;
int V_107 ;
if ( F_64 ( V_105 -> V_7 -> V_45 != V_50 ) ) {
V_20 = - V_80 ;
goto error;
}
V_12 = V_105 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 ) {
V_20 = - V_69 ;
goto error;
}
V_20 = F_65 ( V_105 -> V_84 , ( V_12 = V_105 -> V_12 ) ) ;
if ( V_20 ) {
V_20 = - V_32 ;
goto error;
}
}
V_107 = ( ! V_96 -> V_97 == ! V_105 -> V_108 ) ;
if ( V_107 && V_105 -> V_109 ) {
V_20 = - V_48 ;
goto error;
}
if ( ! V_107 ) {
struct V_77 * V_29 = V_105 -> V_7 -> V_29 ;
T_1 V_110 ;
F_32 ( & V_105 -> V_7 -> V_111 ) ;
if ( V_105 -> V_12 != V_12 ) {
F_9 ( & V_105 -> V_7 -> V_111 ) ;
return - V_112 ;
}
V_106 = F_55 ( & V_96 -> V_17 ) ;
if ( V_96 -> V_97 )
V_106 = F_66 ( V_29 , V_12 -> V_12 , V_106 ) ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_17 = F_41 ( V_106 , V_70 ) ;
if ( F_12 ( ! V_17 ) )
return - V_71 ;
if ( ! V_96 -> V_97 ) {
V_110 = F_67 ( V_17 , V_106 , & V_96 -> V_17 ) ;
if ( V_110 != V_106 ) {
V_20 = - V_67 ;
goto error;
}
}
}
V_20 = F_21 ( & V_105 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 ) )
goto error;
F_32 ( & V_105 -> V_7 -> V_111 ) ;
if ( V_105 -> V_12 != V_12 ) {
V_20 = - V_112 ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
} else if ( V_107 ) {
if ( F_40 ( V_105 -> V_12 == V_12 ) && ! F_64 ( ! V_12 -> V_12 ) )
F_17 ( V_12 -> V_12 ) ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
V_20 = - V_113 ;
} else {
struct V_13 * V_14 ;
if ( F_12 ( V_106 == - V_48 ) ) {
F_68 ( 1 , L_5 , V_114 ) ;
V_20 = - V_48 ;
goto V_115;
}
if ( V_96 -> V_116 ) {
V_14 = F_69 ( V_12 -> V_12 , V_70 ) ;
if ( F_12 ( ! V_14 ) )
goto V_115;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_106 ;
V_96 -> V_27 = V_17 ;
V_96 -> V_12 = V_12 -> V_12 ;
V_96 -> V_14 = V_14 ;
V_96 -> V_7 = V_105 -> V_7 ;
V_14 -> V_15 = V_96 ;
V_14 -> F_51 = F_60 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 ) ) {
F_59 ( V_12 -> V_12 , V_14 ) ;
goto V_115;
}
V_20 = - V_117 ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
} else {
F_70 ( V_118 ) ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_106 ;
V_14 -> V_15 = & V_118 ;
V_14 -> F_51 = F_50 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
if ( F_12 ( V_20 < 0 ) ) {
} else if ( F_12 (
F_13 ( & V_118 ) ) ) {
V_20 = - V_32 ;
F_14 ( V_12 -> V_12 , V_14 ) ;
} else {
V_20 = V_12 -> V_33 ;
if ( V_96 -> V_97 && V_20 > 0 ) {
V_20 = F_54 ( V_17 , V_20 , & V_96 -> V_17 ) ;
if ( F_12 ( F_55 ( & V_96 -> V_17 ) ) )
V_20 = - V_67 ;
}
}
F_34 ( V_17 ) ;
}
}
F_29 ( & V_105 -> V_42 ) ;
return V_20 ;
V_115:
F_9 ( & V_105 -> V_7 -> V_111 ) ;
F_29 ( & V_105 -> V_42 ) ;
error:
F_34 ( V_17 ) ;
return V_20 ;
}
static int
F_71 ( struct V_72 * V_72 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_72 -> V_73 ;
F_20 () ;
if ( F_64 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_80 ;
V_38 -> V_40 = V_105 ;
F_43 ( V_105 -> V_7 ) ;
return 0 ;
}
static int F_72 ( struct V_99 * V_99 )
{
struct V_95 * V_96 = V_99 -> V_102 ;
struct V_104 * V_105 = V_99 -> V_119 -> V_40 ;
int V_76 ;
F_20 () ;
F_32 ( & V_105 -> V_7 -> V_111 ) ;
if ( F_40 ( V_96 && V_96 -> V_12 && V_96 -> V_14 ) )
V_76 = F_14 ( V_96 -> V_12 , V_96 -> V_14 ) ;
else
V_76 = - V_48 ;
F_9 ( & V_105 -> V_7 -> V_111 ) ;
return V_76 ;
}
static T_2 F_73 ( struct V_99 * V_99 , struct V_120 * V_121 )
{
struct V_95 V_96 , * V_122 = & V_96 ;
T_2 V_123 ;
F_20 () ;
if ( ! F_74 ( V_99 ) ) {
V_122 = F_41 ( sizeof( V_96 ) , V_70 ) ;
if ( F_12 ( ! V_122 ) )
return - V_71 ;
V_122 -> V_116 = true ;
} else {
V_122 -> V_116 = false ;
}
V_122 -> V_97 = false ;
V_122 -> V_99 = V_99 ;
V_122 -> V_17 = * V_121 ;
V_122 -> V_98 = V_124 -> V_98 ;
V_99 -> V_102 = V_122 ;
F_75 ( V_99 , F_72 ) ;
V_123 = F_63 ( V_99 -> V_119 , V_122 ) ;
if ( V_123 == - V_117 )
return V_123 ;
if ( V_122 -> V_116 )
F_34 ( V_122 ) ;
else
* V_121 = V_122 -> V_17 ;
return V_123 ;
}
static T_2 F_76 ( struct V_99 * V_99 , struct V_120 * V_125 )
{
struct V_95 V_96 , * V_122 = & V_96 ;
T_2 V_123 ;
F_20 () ;
if ( ! F_74 ( V_99 ) ) {
V_122 = F_41 ( sizeof( V_96 ) , V_70 ) ;
if ( F_12 ( ! V_122 ) )
return - V_71 ;
V_122 -> V_116 = true ;
} else {
V_122 -> V_116 = false ;
}
V_122 -> V_97 = true ;
V_122 -> V_99 = V_99 ;
if ( V_122 -> V_116 ) {
V_122 -> V_103 = F_77 ( & V_122 -> V_17 , V_125 , V_70 ) ;
if ( ! V_122 -> V_103 ) {
F_34 ( V_122 ) ;
return - V_71 ;
}
} else {
V_122 -> V_17 = * V_125 ;
V_122 -> V_103 = NULL ;
}
V_122 -> V_98 = V_124 -> V_98 ;
V_99 -> V_102 = V_122 ;
F_75 ( V_99 , F_72 ) ;
V_123 = F_63 ( V_99 -> V_119 , V_122 ) ;
if ( V_123 == - V_117 )
return V_123 ;
if ( V_122 -> V_116 ) {
F_34 ( V_122 -> V_103 ) ;
F_34 ( V_122 ) ;
} else {
* V_125 = V_122 -> V_17 ;
}
return V_123 ;
}
static int
F_78 ( struct V_72 * V_72 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_72 -> V_73 ;
F_20 () ;
F_45 ( V_105 -> V_7 ) ;
return 0 ;
}
static long F_79 ( struct V_38 * V_38 , unsigned V_75 ,
unsigned long V_76 )
{
struct V_104 * V_105 = V_38 -> V_40 ;
int V_20 ;
F_20 () ;
if ( F_64 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_80 ;
F_32 ( & V_105 -> V_7 -> V_111 ) ;
if ( F_40 ( V_105 -> V_12 ) ) {
switch ( V_75 ) {
case V_126 :
V_20 = F_80 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_127 :
F_81 ( V_105 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_128 :
V_20 = F_82 ( V_105 -> V_12 -> V_12 ) ;
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
V_20 = F_83 ( ( void * ) V_76 , V_134 , sizeof( * V_134 ) ) ;
if ( V_20 )
V_20 = - V_67 ;
return V_20 ;
}
default:
V_20 = - V_83 ;
}
} else {
V_20 = - V_80 ;
}
F_9 ( & V_105 -> V_7 -> V_111 ) ;
return V_20 ;
}
static struct V_72 * T_6
F_84 ( struct V_139 * V_140 , void * V_17 ,
const struct V_141 * V_142 ,
const struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_72 * V_72 ;
F_20 () ;
V_72 = F_85 ( V_140 ) ;
if ( F_40 ( V_72 ) ) {
struct V_147 V_148 = V_149 ;
V_72 -> V_150 = F_86 () ;
V_72 -> V_151 = V_146 -> V_152 ;
V_72 -> V_153 = V_146 -> V_154 ;
V_72 -> V_155 = V_146 -> V_156 ;
V_72 -> V_157 = V_148 ;
V_72 -> V_158 = V_148 ;
V_72 -> V_159 = V_148 ;
V_72 -> V_73 = V_17 ;
if ( V_142 )
V_72 -> V_160 = V_142 ;
if ( V_144 )
V_72 -> V_161 = V_144 ;
}
return V_72 ;
}
static struct V_162 * F_87 ( struct V_139 * V_140 ,
const char * V_163 , void * V_17 ,
const struct V_141 * V_142 )
{
struct V_6 * V_7 = V_140 -> V_164 ;
struct V_162 * V_162 ;
struct V_72 * V_72 ;
F_20 () ;
V_162 = F_88 ( V_140 -> V_165 , V_163 ) ;
if ( F_12 ( ! V_162 ) )
return NULL ;
V_72 = F_84 ( V_140 , V_17 , V_142 , NULL , & V_7 -> V_166 ) ;
if ( F_12 ( ! V_72 ) ) {
F_89 ( V_162 ) ;
return NULL ;
}
F_90 ( V_162 , V_72 ) ;
return V_162 ;
}
static int F_91 ( struct V_139 * V_140 , void * V_167 , int V_168 )
{
struct V_169 * V_17 = V_167 ;
struct V_72 * V_72 ;
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
V_72 = F_84 ( V_140 , NULL ,
& V_180 ,
& V_181 ,
& V_17 -> V_146 ) ;
V_140 -> V_165 = F_92 ( V_72 ) ;
if ( F_12 ( ! V_140 -> V_165 ) )
return - V_71 ;
if ( F_12 ( ! F_87 ( V_140 , L_6 , V_7 ,
& V_182 ) ) )
return - V_71 ;
return 0 ;
}
static int F_93 ( struct V_169 * V_17 , char * V_183 )
{
F_20 () ;
if ( ! V_183 || ! * V_183 )
return 0 ;
for (; ; ) {
unsigned long V_76 ;
char * V_184 , * V_185 ;
V_185 = strchr ( V_183 , ',' ) ;
if ( V_185 )
* V_185 = 0 ;
V_184 = strchr ( V_183 , '=' ) ;
if ( F_12 ( ! V_184 ) ) {
F_94 ( L_7 , V_183 ) ;
return - V_48 ;
}
* V_184 = 0 ;
if ( F_95 ( V_184 + 1 , 0 , & V_76 ) ) {
F_94 ( L_8 , V_183 , V_184 + 1 ) ;
return - V_48 ;
}
switch ( V_184 - V_183 ) {
case 13 :
if ( ! memcmp ( V_183 , L_9 , 13 ) )
V_17 -> V_186 = ! ! V_76 ;
else
goto V_187;
break;
case 5 :
if ( ! memcmp ( V_183 , L_10 , 5 ) )
V_17 -> V_179 = ( V_76 & 0555 ) | V_188 ;
else if ( ! memcmp ( V_183 , L_11 , 5 ) )
V_17 -> V_146 . V_152 = ( V_76 & 0666 ) | V_189 ;
else
goto V_187;
break;
case 4 :
if ( ! memcmp ( V_183 , L_12 , 4 ) ) {
V_17 -> V_179 = ( V_76 & 0555 ) | V_188 ;
V_17 -> V_146 . V_152 = ( V_76 & 0666 ) | V_189 ;
} else {
goto V_187;
}
break;
case 3 :
if ( ! memcmp ( V_183 , L_13 , 3 ) ) {
V_17 -> V_146 . V_154 = F_96 ( F_97 () , V_76 ) ;
if ( ! F_98 ( V_17 -> V_146 . V_154 ) ) {
F_94 ( L_14 , V_183 , V_76 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_183 , L_15 , 3 ) ) {
V_17 -> V_146 . V_156 = F_99 ( F_97 () , V_76 ) ;
if ( ! F_100 ( V_17 -> V_146 . V_156 ) ) {
F_94 ( L_14 , V_183 , V_76 ) ;
return - V_48 ;
}
} else {
goto V_187;
}
break;
default:
V_187:
F_94 ( L_16 , V_183 ) ;
return - V_48 ;
}
if ( ! V_185 )
break;
V_183 = V_185 + 1 ;
}
return 0 ;
}
static struct V_162 *
F_101 ( struct V_190 * V_191 , int V_52 ,
const char * V_192 , void * V_183 )
{
struct V_169 V_17 = {
. V_146 = {
. V_152 = V_189 | 0600 ,
. V_154 = V_193 ,
. V_156 = V_194 ,
} ,
. V_179 = V_188 | 0500 ,
. V_186 = false ,
} ;
struct V_162 * V_195 ;
int V_20 ;
void * V_196 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_93 ( & V_17 , V_183 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_102 ( V_20 ) ;
V_7 = F_103 () ;
if ( F_12 ( ! V_7 ) )
return F_102 ( - V_71 ) ;
V_7 -> V_166 = V_17 . V_146 ;
V_7 -> V_186 = V_17 . V_186 ;
V_7 -> V_192 = F_104 ( V_192 , V_70 ) ;
if ( F_12 ( ! V_7 -> V_192 ) ) {
F_105 ( V_7 ) ;
return F_102 ( - V_71 ) ;
}
V_196 = F_106 ( V_192 ) ;
if ( F_23 ( V_196 ) ) {
F_105 ( V_7 ) ;
return F_107 ( V_196 ) ;
}
V_7 -> V_40 = V_196 ;
V_17 . V_6 = V_7 ;
V_195 = F_108 ( V_191 , V_52 , & V_17 , F_91 ) ;
if ( F_23 ( V_195 ) && V_17 . V_6 ) {
F_109 ( V_17 . V_6 ) ;
F_105 ( V_17 . V_6 ) ;
}
return V_195 ;
}
static void
F_110 ( struct V_139 * V_140 )
{
F_20 () ;
F_111 ( V_140 ) ;
if ( V_140 -> V_164 ) {
F_109 ( V_140 -> V_164 ) ;
F_45 ( V_140 -> V_164 ) ;
F_105 ( V_140 -> V_164 ) ;
}
}
static int F_112 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_113 ( & V_197 ) ;
if ( F_40 ( ! V_20 ) )
F_25 ( L_17 ) ;
else
F_94 ( L_18 , V_20 ) ;
return V_20 ;
}
static void F_114 ( void )
{
F_20 () ;
F_25 ( L_19 ) ;
F_115 ( & V_197 ) ;
}
static void F_116 ( struct V_6 * V_7 )
{
F_20 () ;
F_117 ( & V_7 -> V_198 ) ;
}
static void F_43 ( struct V_6 * V_7 )
{
F_20 () ;
F_117 ( & V_7 -> V_198 ) ;
if ( F_118 ( 1 , & V_7 -> V_199 ) == 1 &&
V_7 -> V_45 == V_89 ) {
V_7 -> V_45 = V_49 ;
F_119 ( V_7 ) ;
}
}
static void F_105 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_120 ( & V_7 -> V_198 ) ) ) {
F_25 ( L_20 , V_114 ) ;
F_121 ( V_7 ) ;
F_122 ( F_123 ( & V_7 -> V_22 . V_25 ) ||
F_123 ( & V_7 -> V_16 . V_84 ) ) ;
F_34 ( V_7 -> V_192 ) ;
F_34 ( V_7 ) ;
}
}
static void F_45 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_120 ( & V_7 -> V_199 ) ) {
if ( V_7 -> V_186 ) {
V_7 -> V_45 = V_89 ;
if ( V_7 -> V_200 ) {
F_124 ( V_7 -> V_200 ,
V_7 -> V_201 ) ;
V_7 -> V_200 = NULL ;
}
if ( V_7 -> V_8 == V_54 )
F_15 ( V_7 ) ;
} else {
V_7 -> V_45 = V_49 ;
F_119 ( V_7 ) ;
}
}
if ( F_125 ( & V_7 -> V_199 ) < 0 ) {
V_7 -> V_45 = V_49 ;
F_119 ( V_7 ) ;
}
F_105 ( V_7 ) ;
}
static struct V_6 * F_103 ( void )
{
struct V_6 * V_7 = F_126 ( sizeof *V_7 , V_70 ) ;
if ( F_12 ( ! V_7 ) )
return NULL ;
F_20 () ;
F_127 ( & V_7 -> V_198 , 1 ) ;
F_127 ( & V_7 -> V_199 , 0 ) ;
V_7 -> V_45 = V_46 ;
F_128 ( & V_7 -> V_42 ) ;
F_129 ( & V_7 -> V_111 ) ;
F_130 ( & V_7 -> V_22 . V_25 ) ;
F_131 ( & V_7 -> V_16 ) ;
V_7 -> V_22 . V_35 = 1 ;
return V_7 ;
}
static void F_121 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_132 ( V_51 , & V_7 -> V_52 ) )
F_133 ( V_7 ) ;
F_122 ( V_7 -> V_29 ) ;
if ( V_7 -> V_200 )
F_124 ( V_7 -> V_200 , V_7 -> V_201 ) ;
if ( V_7 -> V_100 )
F_134 ( V_7 -> V_100 ) ;
F_34 ( V_7 -> V_202 ) ;
F_34 ( V_7 -> V_203 ) ;
F_34 ( V_7 -> V_204 ) ;
}
static void F_119 ( struct V_6 * V_7 )
{
F_20 () ;
F_121 ( V_7 ) ;
V_7 -> V_200 = NULL ;
V_7 -> V_202 = NULL ;
V_7 -> V_205 = NULL ;
V_7 -> V_203 = NULL ;
V_7 -> V_204 = NULL ;
V_7 -> V_206 = 0 ;
V_7 -> V_207 = 0 ;
V_7 -> V_208 = 0 ;
V_7 -> V_209 = 0 ;
V_7 -> V_210 = 0 ;
V_7 -> V_211 = 0 ;
V_7 -> V_201 = 0 ;
V_7 -> V_22 . V_66 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_52 = 0 ;
}
static int F_135 ( struct V_6 * V_7 , struct V_212 * V_213 )
{
struct V_214 * * V_215 ;
int V_216 ;
F_20 () ;
if ( F_64 ( V_7 -> V_45 != V_50
|| F_136 ( V_217 , & V_7 -> V_52 ) ) )
return - V_57 ;
V_216 = F_137 ( V_213 , V_7 -> V_210 ) ;
if ( F_12 ( V_216 < 0 ) )
return V_216 ;
V_7 -> V_19 = F_69 ( V_213 -> V_29 -> V_30 , V_70 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_71 ;
V_7 -> V_19 -> F_51 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_215 = V_7 -> V_204 ;
if ( V_215 ) {
for (; * V_215 ; ++ V_215 ) {
struct V_218 * V_219 = ( * V_215 ) -> V_220 ;
int V_221 = V_216 ;
for (; V_219 -> V_222 ; ++ V_221 , ++ V_219 )
V_219 -> V_221 = V_221 ;
}
}
V_7 -> V_29 = V_213 -> V_29 ;
F_116 ( V_7 ) ;
return 0 ;
}
static void F_138 ( struct V_6 * V_7 )
{
F_20 () ;
if ( ! F_64 ( ! V_7 -> V_29 ) ) {
F_59 ( V_7 -> V_29 -> V_30 , V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_29 = NULL ;
F_139 ( V_217 , & V_7 -> V_52 ) ;
F_105 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_104 * V_105 , * V_200 ;
unsigned V_63 , V_66 ;
F_20 () ;
V_66 = V_7 -> V_201 ;
V_200 = F_140 ( V_66 , sizeof( * V_200 ) , V_70 ) ;
if ( ! V_200 )
return - V_71 ;
V_105 = V_200 ;
for ( V_63 = 1 ; V_63 <= V_66 ; ++ V_63 , ++ V_105 ) {
V_105 -> V_7 = V_7 ;
F_128 ( & V_105 -> V_42 ) ;
F_130 ( & V_105 -> V_84 ) ;
if ( V_7 -> V_223 & V_224 )
sprintf ( V_105 -> V_163 , L_21 , V_7 -> V_225 [ V_63 ] ) ;
else
sprintf ( V_105 -> V_163 , L_22 , V_63 ) ;
V_105 -> V_162 = F_87 ( V_7 -> V_140 , V_105 -> V_163 ,
V_105 ,
& V_226 ) ;
if ( F_12 ( ! V_105 -> V_162 ) ) {
F_124 ( V_200 , V_63 - 1 ) ;
return - V_71 ;
}
}
V_7 -> V_200 = V_200 ;
return 0 ;
}
static void F_124 ( struct V_104 * V_200 , unsigned V_66 )
{
struct V_104 * V_105 = V_200 ;
F_20 () ;
for (; V_66 ; -- V_66 , ++ V_105 ) {
F_122 ( F_141 ( & V_105 -> V_42 ) ||
F_123 ( & V_105 -> V_84 ) ) ;
if ( V_105 -> V_162 ) {
F_142 ( V_105 -> V_162 ) ;
F_89 ( V_105 -> V_162 ) ;
V_105 -> V_162 = NULL ;
}
}
F_34 ( V_200 ) ;
}
static void F_143 ( struct V_1 * V_79 )
{
struct V_91 * V_12 = V_79 -> V_227 ;
struct V_104 * V_105 = V_79 -> V_7 -> V_200 ;
unsigned V_66 = V_79 -> V_7 -> V_201 ;
unsigned long V_52 ;
F_144 ( & V_79 -> V_7 -> V_111 , V_52 ) ;
do {
if ( F_40 ( V_12 -> V_12 ) )
F_145 ( V_12 -> V_12 ) ;
++ V_12 ;
if ( V_105 ) {
V_105 -> V_12 = NULL ;
++ V_105 ;
}
} while ( -- V_66 );
F_146 ( & V_79 -> V_7 -> V_111 , V_52 ) ;
}
static int F_147 ( struct V_1 * V_79 )
{
struct V_6 * V_7 = V_79 -> V_7 ;
struct V_91 * V_12 = V_79 -> V_227 ;
struct V_104 * V_105 = V_7 -> V_200 ;
unsigned V_66 = V_7 -> V_201 ;
unsigned long V_52 ;
int V_20 = 0 ;
F_144 ( & V_79 -> V_7 -> V_111 , V_52 ) ;
do {
struct V_133 * V_228 ;
int V_132 ;
if ( V_7 -> V_29 -> V_135 == V_136 )
V_132 = 2 ;
else if ( V_7 -> V_29 -> V_135 == V_137 )
V_132 = 1 ;
else
V_132 = 0 ;
do {
V_228 = V_12 -> V_138 [ V_132 ] ;
} while ( ! V_228 && -- V_132 >= 0 );
if ( ! V_228 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_92 = V_12 ;
V_12 -> V_12 -> V_134 = V_228 ;
V_20 = F_148 ( V_12 -> V_12 ) ;
if ( F_40 ( ! V_20 ) ) {
V_105 -> V_12 = V_12 ;
V_105 -> V_108 = F_149 ( V_228 ) ;
V_105 -> V_109 = F_150 ( V_228 ) ;
} else {
break;
}
F_151 ( & V_105 -> V_84 ) ;
++ V_12 ;
++ V_105 ;
} while ( -- V_66 );
F_146 ( & V_79 -> V_7 -> V_111 , V_52 ) ;
return V_20 ;
}
static int T_6 F_152 ( char * V_17 , unsigned V_18 ,
T_7 V_229 ,
void * V_230 )
{
struct V_231 * V_232 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_23 ) ;
return - V_48 ;
}
V_28 = V_232 -> V_233 ;
if ( V_18 < V_28 ) {
F_16 ( L_24 ) ;
return - V_48 ;
}
#define F_153 ( T_9 ) 1
#define F_154 ( T_9 ) (val)
#define F_155 ( T_9 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_156 ( type , T_9 ) do { \
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
switch ( V_232 -> V_234 ) {
case V_235 :
case V_236 :
case V_237 :
case V_238 :
F_16 ( L_25 ,
V_232 -> V_234 ) ;
return - V_48 ;
case V_239 : {
struct V_240 * V_228 = ( void * ) V_232 ;
F_16 ( L_26 ) ;
if ( V_28 != sizeof *V_228 )
goto V_241;
F_156 ( V_242 , V_228 -> V_243 ) ;
if ( V_228 -> V_244 )
F_156 ( STRING , V_228 -> V_244 ) ;
}
break;
case V_245 : {
struct V_133 * V_228 = ( void * ) V_232 ;
F_16 ( L_27 ) ;
if ( V_28 != V_246 &&
V_28 != V_247 )
goto V_241;
F_156 ( V_248 , V_228 -> V_249 ) ;
}
break;
case V_250 :
F_16 ( L_28 ) ;
if ( V_28 != sizeof( struct V_251 ) )
goto V_241;
break;
case V_252 :
if ( V_28 != sizeof( struct V_253 ) )
goto V_241;
break;
case V_254 : {
struct V_255 * V_228 = ( void * ) V_232 ;
F_16 ( L_29 ) ;
if ( V_28 != sizeof *V_228 )
goto V_241;
if ( V_228 -> V_256 )
F_156 ( STRING , V_228 -> V_256 ) ;
}
break;
case V_257 :
F_16 ( L_30 ) ;
if ( V_28 != sizeof( struct V_258 ) )
goto V_241;
break;
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
F_16 ( L_31 , V_232 -> V_234 ) ;
return - V_48 ;
default:
F_16 ( L_32 , V_232 -> V_234 ) ;
return - V_48 ;
V_241:
F_16 ( L_33 ,
V_232 -> V_233 , V_232 -> V_234 ) ;
return - V_48 ;
}
#undef F_156
#undef V_264
#undef F_153
#undef F_154
#undef F_155
return V_28 ;
}
static int T_6 F_157 ( unsigned V_66 , char * V_17 , unsigned V_18 ,
T_7 V_229 , void * V_230 )
{
const unsigned V_265 = V_18 ;
unsigned long V_130 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_130 == V_66 )
V_17 = NULL ;
V_20 = V_229 ( V_266 , ( T_8 * ) V_130 , ( void * ) V_17 , V_230 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_34 ,
V_130 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_265 - V_18 ;
V_20 = F_152 ( V_17 , V_18 , V_229 , V_230 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_35 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_130 ;
}
}
static int F_158 ( enum V_267 type ,
T_8 * V_268 , struct V_231 * V_134 ,
void * V_230 )
{
struct V_269 * V_270 = V_230 ;
struct V_133 * V_271 ;
F_20 () ;
switch ( type ) {
case V_266 :
break;
case V_272 :
if ( * V_268 >= V_270 -> V_211 )
V_270 -> V_211 = * V_268 + 1 ;
break;
case V_273 :
if ( * V_268 > V_270 -> V_7 -> V_210 )
V_270 -> V_7 -> V_210 = * V_268 ;
break;
case V_274 :
V_271 = ( void * ) V_134 ;
V_270 -> V_201 ++ ;
if ( V_270 -> V_201 >= 15 )
return - V_48 ;
if ( ! V_270 -> V_7 -> V_201 && ! V_270 -> V_7 -> V_211 )
V_270 -> V_7 -> V_225 [ V_270 -> V_201 ] =
V_271 -> V_249 ;
else if ( V_270 -> V_7 -> V_225 [ V_270 -> V_201 ] !=
V_271 -> V_249 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_159 ( enum V_275 * V_276 ,
struct V_277 * V_134 )
{
T_10 V_278 = F_8 ( V_134 -> V_279 ) ;
T_10 V_280 = F_8 ( V_134 -> V_281 ) ;
if ( V_278 != 1 ) {
F_16 ( L_36 ,
V_278 ) ;
return - V_48 ;
}
switch ( V_280 ) {
case 0x4 :
* V_276 = V_282 ;
break;
case 0x5 :
* V_276 = V_283 ;
break;
default:
F_16 ( L_37 , V_280 ) ;
return - V_48 ;
}
return sizeof( * V_134 ) ;
}
static int T_6 F_160 ( char * V_17 , unsigned V_18 ,
enum V_275 type ,
T_10 V_284 ,
T_11 V_229 ,
void * V_230 ,
struct V_277 * V_285 )
{
int V_20 ;
const unsigned V_265 = V_18 ;
F_20 () ;
while ( V_284 -- ) {
V_20 = V_229 ( type , V_285 , V_17 , V_18 , V_230 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 , type ) ;
return V_20 ;
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
return V_265 - V_18 ;
}
static int T_6 F_161 ( unsigned V_66 ,
char * V_17 , unsigned V_18 ,
T_11 V_229 , void * V_230 )
{
const unsigned V_265 = V_18 ;
unsigned long V_130 = 0 ;
F_20 () ;
for ( V_130 = 0 ; V_130 < V_66 ; ++ V_130 ) {
int V_20 ;
enum V_275 type ;
T_10 V_284 ;
struct V_277 * V_134 = ( void * ) V_17 ;
if ( V_18 < sizeof( * V_134 ) )
return - V_48 ;
if ( F_162 ( V_134 -> V_286 ) > V_18 )
return - V_48 ;
V_20 = F_159 ( & type , V_134 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_39 ,
V_130 , V_20 ) ;
return V_20 ;
}
V_284 = F_8 ( V_134 -> V_287 ) ;
if ( type == V_282 &&
( V_284 > 255 || V_134 -> V_288 ) )
return - V_48 ;
V_18 -= V_20 ;
V_17 += V_20 ;
V_20 = F_160 ( V_17 , V_18 , type ,
V_284 , V_229 , V_230 , V_134 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_35 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
return V_265 - V_18 ;
}
static int F_163 ( enum V_275 type ,
struct V_277 * V_285 , void * V_17 ,
unsigned V_18 , void * V_230 )
{
struct V_6 * V_7 = V_230 ;
T_8 V_28 ;
F_20 () ;
switch ( type ) {
case V_282 : {
struct V_289 * V_271 = V_17 ;
int V_63 ;
if ( V_18 < sizeof( * V_271 ) ||
V_271 -> V_290 >= V_7 -> V_211 ||
V_271 -> V_291 )
return - V_48 ;
for ( V_63 = 0 ; V_63 < F_36 ( V_271 -> V_292 ) ; ++ V_63 )
if ( V_271 -> V_292 [ V_63 ] )
return - V_48 ;
V_28 = sizeof( struct V_289 ) ;
}
break;
case V_283 : {
struct V_293 * V_271 = V_17 ;
T_12 type , V_294 ;
T_10 V_295 ;
if ( V_18 < sizeof( * V_271 ) || V_285 -> V_296 >= V_7 -> V_211 )
return - V_48 ;
V_28 = F_162 ( V_271 -> V_297 ) ;
type = F_162 ( V_271 -> V_298 ) ;
if ( type < V_299 ||
type > V_300 ) {
F_16 ( L_40 ,
type ) ;
return - V_48 ;
}
V_295 = F_8 ( V_271 -> V_301 ) ;
V_294 = F_162 ( * ( T_12 * ) ( ( T_8 * ) V_17 + 10 + V_295 ) ) ;
if ( V_28 != 14 + V_295 + V_294 ) {
F_16 ( L_41 ,
V_28 , V_295 , V_294 , type ) ;
return - V_48 ;
}
++ V_7 -> V_302 ;
V_7 -> V_303 += V_295 * 2 ;
V_7 -> V_304 += V_294 ;
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
char * V_17 = V_167 , * V_205 ;
unsigned V_305 = 0 , V_306 [ 3 ] , V_52 ;
int V_20 = - V_48 , V_63 ;
struct V_269 V_270 ;
F_20 () ;
if ( F_164 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_164 ( V_17 ) ) {
case V_307 :
V_52 = V_308 | V_309 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_310 :
V_52 = F_164 ( V_17 + 8 ) ;
V_7 -> V_223 = V_52 ;
if ( V_52 & ~ ( V_308 |
V_309 |
V_311 |
V_312 |
V_224 |
V_313 ) ) {
V_20 = - V_314 ;
goto error;
}
V_17 += 12 ;
V_18 -= 12 ;
break;
default:
goto error;
}
if ( V_52 & V_313 ) {
if ( V_18 < 4 )
goto error;
V_7 -> V_100 =
F_165 ( ( int ) F_164 ( V_17 ) ) ;
if ( F_23 ( V_7 -> V_100 ) ) {
V_20 = F_24 ( V_7 -> V_100 ) ;
V_7 -> V_100 = NULL ;
goto error;
}
V_17 += 4 ;
V_18 -= 4 ;
}
for ( V_63 = 0 ; V_63 < 3 ; ++ V_63 ) {
if ( ! ( V_52 & ( 1 << V_63 ) ) ) {
V_306 [ V_63 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_306 [ V_63 ] = F_164 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
if ( V_52 & ( 1 << V_63 ) ) {
V_305 = F_164 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
} ;
V_205 = V_17 ;
V_270 . V_7 = V_7 ;
for ( V_63 = 0 ; V_63 < 3 ; ++ V_63 ) {
if ( ! V_306 [ V_63 ] )
continue;
V_270 . V_211 = 0 ;
V_270 . V_201 = 0 ;
V_20 = F_157 ( V_306 [ V_63 ] , V_17 , V_18 ,
F_158 , & V_270 ) ;
if ( V_20 < 0 )
goto error;
if ( ! V_7 -> V_201 && ! V_7 -> V_211 ) {
V_7 -> V_201 = V_270 . V_201 ;
V_7 -> V_211 = V_270 . V_211 ;
} else {
if ( V_7 -> V_201 != V_270 . V_201 ) {
V_20 = - V_48 ;
goto error;
}
if ( V_7 -> V_211 != V_270 . V_211 ) {
V_20 = - V_48 ;
goto error;
}
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_305 ) {
V_20 = F_161 ( V_305 , V_17 , V_18 ,
F_163 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_205 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_202 = V_167 ;
V_7 -> V_205 = V_205 ;
V_7 -> V_206 = V_17 - V_205 ;
V_7 -> V_207 = V_306 [ 0 ] ;
V_7 -> V_208 = V_306 [ 1 ] ;
V_7 -> V_209 = V_306 [ 2 ] ;
V_7 -> V_315 = V_305 ;
return 0 ;
error:
F_34 ( V_167 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_167 , T_1 V_18 )
{
T_12 V_316 , V_317 , V_318 ;
struct V_214 * * V_204 , * V_191 ;
struct V_218 * V_220 , * V_222 ;
const char * V_17 = V_167 ;
F_20 () ;
if ( F_12 ( F_164 ( V_17 ) != V_319 ||
F_164 ( V_17 + 4 ) != V_18 ) )
goto error;
V_316 = F_164 ( V_17 + 8 ) ;
V_318 = F_164 ( V_17 + 12 ) ;
if ( F_12 ( ! V_316 != ! V_318 ) )
goto error;
V_317 = V_7 -> V_210 ;
if ( F_12 ( V_316 < V_317 ) )
goto error;
if ( ! V_317 ) {
F_34 ( V_167 ) ;
return 0 ;
}
{
unsigned V_63 = 0 ;
F_166 ( V_271 ) ;
F_167 ( V_271 , struct V_214 * , V_204 ,
V_318 + 1 ) ;
F_167 ( V_271 , struct V_214 , V_320 , V_318 ) ;
F_167 ( V_271 , struct V_218 , V_220 ,
V_318 * ( V_317 + 1 ) ) ;
char * V_321 = F_41 ( F_168 ( V_271 ) , V_70 ) ;
if ( F_12 ( ! V_321 ) ) {
F_34 ( V_167 ) ;
return - V_71 ;
}
V_204 = F_169 ( V_321 , V_271 , V_204 ) ;
V_191 = F_169 ( V_321 , V_271 , V_320 ) ;
V_63 = V_318 ;
do {
* V_204 ++ = V_191 ++ ;
} while ( -- V_63 );
* V_204 = NULL ;
V_204 = F_169 ( V_321 , V_271 , V_204 ) ;
V_191 = F_169 ( V_321 , V_271 , V_320 ) ;
V_222 = F_169 ( V_321 , V_271 , V_220 ) ;
V_220 = V_222 ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_322 = V_317 ;
if ( F_12 ( V_18 < 3 ) )
goto V_323;
V_191 -> V_324 = F_170 ( V_17 ) ;
V_191 -> V_220 = V_222 ;
++ V_191 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_171 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_323;
if ( F_40 ( V_322 ) ) {
V_222 -> V_222 = V_17 ;
-- V_322 ;
++ V_222 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_316 );
V_222 -> V_221 = 0 ;
V_222 -> V_222 = NULL ;
++ V_222 ;
} while ( -- V_318 );
if ( F_12 ( V_18 ) )
goto V_323;
V_7 -> V_204 = V_204 ;
V_7 -> V_203 = V_167 ;
return 0 ;
V_323:
F_34 ( V_204 ) ;
error:
F_34 ( V_167 ) ;
return - V_48 ;
}
static void F_172 ( struct V_6 * V_7 ,
enum V_325 type )
{
enum V_325 V_326 , V_327 = type ;
int V_328 = 0 ;
if ( V_7 -> V_8 == V_54 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_329 :
V_327 = V_330 ;
case V_330 :
case V_64 :
V_326 = type ;
break;
case V_331 :
case V_332 :
case V_333 :
case V_334 :
V_326 = V_330 ;
V_327 = V_329 ;
V_328 = 1 ;
break;
default:
F_68 ( 1 , L_42 , type ) ;
return;
}
{
T_8 * V_22 = V_7 -> V_22 . V_61 , * V_335 = V_22 ;
unsigned V_58 = V_7 -> V_22 . V_66 ;
for (; V_58 ; -- V_58 , ++ V_22 )
if ( ( * V_22 == V_326 || * V_22 == V_327 ) == V_328 )
* V_335 ++ = * V_22 ;
else
F_16 ( L_43 , * V_22 ) ;
V_7 -> V_22 . V_66 = V_335 - V_7 -> V_22 . V_61 ;
}
F_16 ( L_44 , type ) ;
V_7 -> V_22 . V_61 [ V_7 -> V_22 . V_66 ++ ] = type ;
F_173 ( & V_7 -> V_22 . V_25 ) ;
if ( V_7 -> V_100 )
F_58 ( V_7 -> V_100 , 1 ) ;
}
static void F_174 ( struct V_6 * V_7 ,
enum V_325 type )
{
unsigned long V_52 ;
F_144 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
F_172 ( V_7 , type ) ;
F_146 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
}
static int F_175 ( struct V_6 * V_7 , T_8 V_336 )
{
int V_63 ;
for ( V_63 = 1 ; V_63 < F_36 ( V_7 -> V_225 ) ; ++ V_63 )
if ( V_7 -> V_225 [ V_63 ] == V_336 )
return V_63 ;
return - V_337 ;
}
static int F_176 ( enum V_267 type , T_8 * V_268 ,
struct V_231 * V_134 ,
void * V_230 )
{
struct V_133 * V_228 = ( void * ) V_134 ;
struct V_1 * V_79 = V_230 ;
struct V_91 * V_91 ;
unsigned V_338 ;
int V_339 ;
static const char * V_340 [] = { L_45 , L_46 , L_47 } ;
if ( type != V_266 )
return 0 ;
if ( V_79 -> V_4 . V_341 ) {
V_338 = 2 ;
V_79 -> V_4 . V_341 [ ( long ) V_268 ] = V_134 ;
} else if ( V_79 -> V_4 . V_342 ) {
V_338 = 1 ;
V_79 -> V_4 . V_342 [ ( long ) V_268 ] = V_134 ;
} else {
V_338 = 0 ;
V_79 -> V_4 . V_343 [ ( long ) V_268 ] = V_134 ;
}
if ( ! V_134 || V_134 -> V_234 != V_245 )
return 0 ;
V_339 = F_175 ( V_79 -> V_7 , V_228 -> V_249 ) - 1 ;
if ( V_339 < 0 )
return V_339 ;
V_91 = V_79 -> V_227 + V_339 ;
if ( F_12 ( V_91 -> V_138 [ V_338 ] ) ) {
F_94 ( L_48 ,
V_340 [ V_338 ] ,
V_228 -> V_249 & V_344 ) ;
return - V_48 ;
}
V_91 -> V_138 [ V_338 ] = V_228 ;
F_177 ( L_49 , V_228 , V_228 -> V_233 ) ;
if ( V_91 -> V_12 ) {
V_228 -> V_249 = V_91 -> V_138 [ 0 ] -> V_249 ;
if ( ! V_228 -> V_345 )
V_228 -> V_345 = V_91 -> V_138 [ 0 ] -> V_345 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_8 V_249 ;
V_249 = V_228 -> V_249 ;
F_16 ( L_50 ) ;
V_12 = F_178 ( V_79 -> V_29 , V_228 ) ;
if ( F_12 ( ! V_12 ) )
return - V_346 ;
V_12 -> V_92 = V_79 -> V_227 + V_339 ;
V_14 = F_69 ( V_12 , V_70 ) ;
if ( F_12 ( ! V_14 ) )
return - V_71 ;
V_91 -> V_12 = V_12 ;
V_91 -> V_14 = V_14 ;
V_79 -> V_347 [ V_228 -> V_249 &
V_344 ] = V_339 + 1 ;
if ( V_79 -> V_7 -> V_223 & V_224 )
V_228 -> V_249 = V_249 ;
}
F_177 ( L_51 , V_228 , V_228 -> V_233 ) ;
return 0 ;
}
static int F_179 ( enum V_267 type , T_8 * V_268 ,
struct V_231 * V_134 ,
void * V_230 )
{
struct V_1 * V_79 = V_230 ;
unsigned V_339 ;
T_8 V_348 ;
switch ( type ) {
default:
case V_266 :
return 0 ;
case V_272 :
V_339 = * V_268 ;
if ( V_79 -> V_349 [ V_339 ] < 0 ) {
int V_221 = F_180 ( V_79 -> V_350 , & V_79 -> V_4 ) ;
if ( F_12 ( V_221 < 0 ) )
return V_221 ;
V_79 -> V_349 [ V_339 ] = V_221 ;
}
V_348 = V_79 -> V_349 [ V_339 ] ;
break;
case V_273 :
V_348 = V_79 -> V_7 -> V_204 [ 0 ] -> V_220 [ * V_268 - 1 ] . V_221 ;
break;
case V_274 :
if ( V_134 -> V_234 == V_245 )
return 0 ;
V_339 = ( * V_268 & V_344 ) - 1 ;
if ( F_12 ( ! V_79 -> V_227 [ V_339 ] . V_12 ) )
return - V_48 ;
{
struct V_133 * * V_138 ;
V_138 = V_79 -> V_227 [ V_339 ] . V_138 ;
V_348 = V_138 [ V_138 [ 0 ] ? 0 : 1 ] -> V_249 ;
}
break;
}
F_16 ( L_52 , * V_268 , V_348 ) ;
* V_268 = V_348 ;
return 0 ;
}
static int F_181 ( enum V_275 type ,
struct V_277 * V_285 , void * V_17 ,
unsigned V_18 , void * V_230 )
{
struct V_1 * V_79 = V_230 ;
T_8 V_28 = 0 ;
switch ( type ) {
case V_282 : {
struct V_289 * V_134 = V_17 ;
struct V_351 * V_191 ;
V_191 = & V_79 -> V_4 . V_352 [ V_134 -> V_290 ] ;
V_191 -> V_353 = V_79 -> V_349 [ V_134 -> V_290 ] ;
memcpy ( V_191 -> V_354 -> V_355 , & V_134 -> V_356 ,
F_36 ( V_134 -> V_356 ) +
F_36 ( V_134 -> V_357 ) ) ;
V_28 = sizeof( * V_134 ) ;
}
break;
case V_283 : {
struct V_293 * V_134 = V_17 ;
struct V_351 * V_191 ;
struct V_358 * V_359 ;
char * V_360 ;
char * V_361 ;
V_191 = & V_79 -> V_4 . V_352 [ V_285 -> V_296 ] ;
V_191 -> V_353 = V_79 -> V_349 [ V_285 -> V_296 ] ;
V_359 = V_79 -> V_7 -> V_362 ;
V_79 -> V_7 -> V_362 += sizeof( * V_359 ) ;
V_359 -> type = F_162 ( V_134 -> V_298 ) ;
V_359 -> V_363 = F_8 ( V_134 -> V_301 ) ;
V_359 -> V_106 = F_162 ( * ( T_12 * )
F_182 ( V_17 , V_359 -> V_363 ) ) ;
V_28 = V_359 -> V_363 + V_359 -> V_106 + 14 ;
V_360 = V_79 -> V_7 -> V_364 ;
V_79 -> V_7 -> V_364 +=
V_359 -> V_363 ;
V_361 = V_79 -> V_7 -> V_365 ;
V_79 -> V_7 -> V_365 +=
V_359 -> V_106 ;
memcpy ( V_361 ,
F_183 ( V_17 , V_359 -> V_363 ) ,
V_359 -> V_106 ) ;
switch ( V_359 -> type ) {
case V_299 :
case V_366 :
case V_367 :
case V_300 :
V_359 -> V_106 *= 2 ;
break;
}
V_359 -> V_17 = V_361 ;
memcpy ( V_360 , F_184 ( V_17 ) ,
V_359 -> V_363 ) ;
V_359 -> V_363 *= 2 ;
V_359 -> V_163 = V_360 ;
V_191 -> V_354 -> V_368 +=
V_359 -> V_363 + V_359 -> V_106 + 14 ;
++ V_191 -> V_354 -> V_369 ;
F_185 ( & V_359 -> V_370 , & V_191 -> V_354 -> V_359 ) ;
}
break;
default:
F_16 ( L_32 , type ) ;
}
return V_28 ;
}
static inline struct V_371 * F_186 ( struct V_2 * V_3 ,
struct V_372 * V_373 )
{
struct V_1 * V_79 = F_1 ( V_3 ) ;
struct V_371 * V_374 =
F_2 ( V_3 -> V_375 , struct V_371 , V_376 ) ;
int V_20 ;
F_20 () ;
if ( ! V_374 -> V_377 )
F_187 () ;
V_20 = V_374 -> V_378 -> V_379 ? 0 : - V_80 ;
V_79 -> V_7 = V_374 -> V_378 -> V_6 ;
if ( ! V_374 -> V_377 )
F_188 () ;
if ( V_20 )
return F_102 ( V_20 ) ;
V_79 -> V_350 = V_373 ;
V_79 -> V_29 = V_373 -> V_213 -> V_29 ;
if ( ! V_374 -> V_380 ) {
V_20 = F_135 ( V_79 -> V_7 , V_373 -> V_213 ) ;
if ( V_20 )
return F_102 ( V_20 ) ;
}
V_374 -> V_380 ++ ;
V_79 -> V_4 . V_220 = V_79 -> V_7 -> V_204 ;
return V_374 ;
}
static int F_189 ( struct V_372 * V_373 ,
struct V_2 * V_3 )
{
struct V_1 * V_79 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_79 -> V_7 ;
const int V_381 = ! ! V_79 -> V_7 -> V_207 ;
const int V_382 = F_190 ( V_79 -> V_29 ) &&
V_79 -> V_7 -> V_208 ;
const int V_383 = F_191 ( V_79 -> V_29 ) &&
V_79 -> V_7 -> V_209 ;
int V_384 , V_385 , V_386 , V_20 , V_63 ;
F_166 ( V_271 ) ;
F_192 ( V_271 , struct V_91 , V_227 , V_7 -> V_201 ) ;
F_192 ( V_271 , struct V_231 * , V_387 ,
V_381 ? V_7 -> V_207 + 1 : 0 ) ;
F_192 ( V_271 , struct V_231 * , V_388 ,
V_382 ? V_7 -> V_208 + 1 : 0 ) ;
F_192 ( V_271 , struct V_231 * , V_389 ,
V_383 ? V_7 -> V_209 + 1 : 0 ) ;
F_192 ( V_271 , short , V_390 , V_7 -> V_211 ) ;
F_192 ( V_271 , struct V_351 , V_352 ,
V_373 -> V_213 -> V_391 ? V_7 -> V_211 : 0 ) ;
F_192 ( V_271 , char [ 16 ] , V_392 ,
V_373 -> V_213 -> V_391 ? V_7 -> V_211 : 0 ) ;
F_192 ( V_271 , struct V_393 , V_354 ,
V_373 -> V_213 -> V_391 ? V_7 -> V_211 : 0 ) ;
F_192 ( V_271 , struct V_358 , V_359 ,
V_7 -> V_302 ) ;
F_192 ( V_271 , char , V_360 ,
V_7 -> V_303 ) ;
F_192 ( V_271 , char , V_361 ,
V_7 -> V_304 ) ;
F_192 ( V_271 , char , V_205 , V_7 -> V_206 ) ;
char * V_321 ;
F_20 () ;
if ( F_12 ( ! ( V_381 | V_382 | V_383 ) ) )
return - V_346 ;
V_321 = F_126 ( F_168 ( V_271 ) , V_70 ) ;
if ( F_12 ( ! V_321 ) )
return - V_71 ;
V_7 -> V_362 = F_169 ( V_321 , V_271 , V_359 ) ;
V_7 -> V_364 =
F_169 ( V_321 , V_271 , V_360 ) ;
V_7 -> V_365 =
F_169 ( V_321 , V_271 , V_361 ) ;
memcpy ( F_169 ( V_321 , V_271 , V_205 ) , V_7 -> V_205 ,
V_7 -> V_206 ) ;
memset ( F_169 ( V_321 , V_271 , V_390 ) , 0xff , V_394 ) ;
for ( V_20 = V_7 -> V_201 ; V_20 ; -- V_20 ) {
struct V_91 * V_39 ;
V_39 = F_169 ( V_321 , V_271 , V_227 ) ;
V_39 [ V_20 ] . V_130 = - 1 ;
}
V_79 -> V_227 = F_169 ( V_321 , V_271 , V_227 ) ;
V_79 -> V_349 = F_169 ( V_321 , V_271 , V_390 ) ;
if ( F_40 ( V_381 ) ) {
V_79 -> V_4 . V_343 = F_169 ( V_321 , V_271 , V_387 ) ;
V_384 = F_157 ( V_7 -> V_207 ,
F_169 ( V_321 , V_271 , V_205 ) ,
V_395 ,
F_176 , V_79 ) ;
if ( F_12 ( V_384 < 0 ) ) {
V_20 = V_384 ;
goto error;
}
} else {
V_384 = 0 ;
}
if ( F_40 ( V_382 ) ) {
V_79 -> V_4 . V_342 = F_169 ( V_321 , V_271 , V_388 ) ;
V_385 = F_157 ( V_7 -> V_208 ,
F_169 ( V_321 , V_271 , V_205 ) + V_384 ,
V_395 - V_384 ,
F_176 , V_79 ) ;
if ( F_12 ( V_385 < 0 ) ) {
V_20 = V_385 ;
goto error;
}
} else {
V_385 = 0 ;
}
if ( F_40 ( V_383 ) ) {
V_79 -> V_4 . V_341 = F_169 ( V_321 , V_271 , V_389 ) ;
V_386 = F_157 ( V_7 -> V_209 ,
F_169 ( V_321 , V_271 , V_205 ) + V_384 + V_385 ,
V_395 - V_384 - V_385 ,
F_176 , V_79 ) ;
if ( F_12 ( V_386 < 0 ) ) {
V_20 = V_386 ;
goto error;
}
} else {
V_386 = 0 ;
}
V_20 = F_157 ( V_7 -> V_207 +
( V_382 ? V_7 -> V_208 : 0 ) +
( V_383 ? V_7 -> V_209 : 0 ) ,
F_169 ( V_321 , V_271 , V_205 ) , V_395 ,
F_179 , V_79 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_79 -> V_4 . V_352 = F_169 ( V_321 , V_271 , V_352 ) ;
if ( V_373 -> V_213 -> V_391 )
for ( V_63 = 0 ; V_63 < V_7 -> V_211 ; ++ V_63 ) {
struct V_393 * V_134 ;
V_134 = V_79 -> V_4 . V_352 [ V_63 ] . V_354 =
F_169 ( V_321 , V_271 , V_354 ) +
V_63 * sizeof( struct V_393 ) ;
V_134 -> V_355 =
F_169 ( V_321 , V_271 , V_392 ) + V_63 * 16 ;
F_193 ( & V_134 -> V_359 ) ;
}
V_20 = F_161 ( V_7 -> V_315 ,
F_169 ( V_321 , V_271 , V_205 ) +
V_384 + V_385 + V_386 ,
V_395 - V_384 - V_385 - V_386 ,
F_181 , V_79 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_79 -> V_4 . V_396 =
V_373 -> V_213 -> V_391 ? V_7 -> V_211 : 0 ;
F_174 ( V_7 , V_331 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_194 ( struct V_372 * V_373 ,
struct V_2 * V_3 )
{
struct V_371 * V_374 = F_186 ( V_3 , V_373 ) ;
if ( F_23 ( V_374 ) )
return F_24 ( V_374 ) ;
return F_189 ( V_373 , V_3 ) ;
}
static void F_195 ( struct V_93 * V_94 )
{
struct V_6 * V_7 = F_2 ( V_94 ,
struct V_6 , V_397 ) ;
F_119 ( V_7 ) ;
}
static int F_196 ( struct V_2 * V_3 ,
unsigned V_296 , unsigned V_398 )
{
struct V_1 * V_79 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_79 -> V_7 ;
int V_20 = 0 , V_399 ;
if ( V_398 != ( unsigned ) - 1 ) {
V_399 = F_47 ( V_79 , V_296 ) ;
if ( F_12 ( V_399 < 0 ) )
return V_399 ;
}
if ( V_7 -> V_79 )
F_143 ( V_7 -> V_79 ) ;
if ( V_7 -> V_45 == V_89 ) {
V_7 -> V_45 = V_49 ;
F_61 ( & V_7 -> V_397 , F_195 ) ;
F_62 ( & V_7 -> V_397 ) ;
return - V_80 ;
}
if ( V_7 -> V_45 != V_50 )
return - V_80 ;
if ( V_398 == ( unsigned ) - 1 ) {
V_7 -> V_79 = NULL ;
F_174 ( V_7 , V_333 ) ;
return 0 ;
}
V_7 -> V_79 = V_79 ;
V_20 = F_147 ( V_79 ) ;
if ( F_40 ( V_20 >= 0 ) )
F_174 ( V_7 , V_334 ) ;
return V_20 ;
}
static void F_197 ( struct V_2 * V_3 )
{
F_196 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_198 ( struct V_2 * V_3 ,
const struct V_400 * V_401 )
{
struct V_1 * V_79 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_79 -> V_7 ;
unsigned long V_52 ;
int V_20 ;
F_20 () ;
F_16 ( L_53 , V_401 -> V_55 ) ;
F_16 ( L_54 , V_401 -> V_402 ) ;
F_16 ( L_55 , F_8 ( V_401 -> V_403 ) ) ;
F_16 ( L_56 , F_8 ( V_401 -> V_281 ) ) ;
F_16 ( L_57 , F_8 ( V_401 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_80 ;
switch ( V_401 -> V_55 & V_404 ) {
case V_405 :
V_20 = F_47 ( V_79 , F_8 ( V_401 -> V_281 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_406 :
V_20 = F_199 ( V_79 , F_8 ( V_401 -> V_281 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_79 -> V_7 -> V_223 & V_224 )
V_20 = V_79 -> V_7 -> V_225 [ V_20 ] ;
break;
default:
return - V_407 ;
}
F_144 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
V_7 -> V_22 . V_23 = * V_401 ;
V_7 -> V_22 . V_23 . V_281 = F_200 ( V_20 ) ;
F_172 ( V_7 , V_64 ) ;
F_146 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
return 0 ;
}
static void F_201 ( struct V_2 * V_3 )
{
F_20 () ;
F_174 ( F_1 ( V_3 ) -> V_7 , V_330 ) ;
}
static void F_202 ( struct V_2 * V_3 )
{
F_20 () ;
F_174 ( F_1 ( V_3 ) -> V_7 , V_329 ) ;
}
static int F_199 ( struct V_1 * V_79 , T_8 V_130 )
{
V_130 = V_79 -> V_347 [ V_130 & V_344 ] ;
return V_130 ? V_130 : - V_408 ;
}
static int F_47 ( struct V_1 * V_79 , T_8 V_399 )
{
short * V_409 = V_79 -> V_349 ;
unsigned V_66 = V_79 -> V_7 -> V_211 ;
for (; V_66 ; -- V_66 , ++ V_409 ) {
if ( * V_409 >= 0 && * V_409 == V_399 )
return V_409 - V_79 -> V_349 ;
}
return - V_408 ;
}
static struct V_196 * F_203 ( const char * V_163 )
{
struct V_196 * V_378 ;
F_204 (dev, &ffs_devices, entry) {
if ( ! V_378 -> V_163 || ! V_163 )
continue;
if ( strcmp ( V_378 -> V_163 , V_163 ) == 0 )
return V_378 ;
}
return NULL ;
}
static struct V_196 * F_205 ( void )
{
struct V_196 * V_378 ;
if ( F_206 ( & V_410 ) ) {
V_378 = F_207 ( & V_410 , struct V_196 , V_370 ) ;
if ( V_378 -> V_411 )
return V_378 ;
}
return NULL ;
}
static struct V_196 * F_208 ( const char * V_163 )
{
struct V_196 * V_378 ;
V_378 = F_205 () ;
if ( V_378 )
return V_378 ;
return F_203 ( V_163 ) ;
}
static inline struct V_371 * F_209 ( struct V_412 * V_413 )
{
return F_2 ( F_210 ( V_413 ) , struct V_371 ,
V_376 . V_414 ) ;
}
static void F_211 ( struct V_412 * V_413 )
{
struct V_371 * V_183 = F_209 ( V_413 ) ;
F_212 ( & V_183 -> V_376 ) ;
}
static void F_213 ( struct V_415 * V_3 )
{
struct V_371 * V_183 ;
V_183 = F_214 ( V_3 ) ;
F_187 () ;
F_215 ( V_183 -> V_378 ) ;
F_188 () ;
F_34 ( V_183 ) ;
}
static int F_216 ( struct V_415 * V_375 , const char * V_163 )
{
struct V_371 * V_183 ;
char * V_39 ;
const char * V_416 ;
int V_363 , V_20 ;
V_363 = strlen ( V_163 ) + 1 ;
if ( V_363 > V_417 )
return - V_418 ;
V_39 = F_217 ( V_163 , V_363 , V_70 ) ;
if ( ! V_39 )
return - V_71 ;
V_183 = F_214 ( V_375 ) ;
V_416 = NULL ;
F_187 () ;
V_416 = V_183 -> V_378 -> V_419 ? V_183 -> V_378 -> V_163 : NULL ;
V_20 = F_218 ( V_183 -> V_378 , V_39 ) ;
if ( V_20 ) {
F_34 ( V_39 ) ;
F_188 () ;
return V_20 ;
}
V_183 -> V_378 -> V_419 = true ;
F_188 () ;
F_34 ( V_416 ) ;
return 0 ;
}
static struct V_415 * F_219 ( void )
{
struct V_371 * V_183 ;
struct V_196 * V_378 ;
V_183 = F_126 ( sizeof( * V_183 ) , V_70 ) ;
if ( ! V_183 )
return F_102 ( - V_71 ) ;
V_183 -> V_376 . V_420 = F_216 ;
V_183 -> V_376 . V_421 = F_213 ;
F_187 () ;
V_378 = F_220 () ;
F_188 () ;
if ( F_23 ( V_378 ) ) {
F_34 ( V_183 ) ;
return F_107 ( V_378 ) ;
}
V_183 -> V_378 = V_378 ;
V_378 -> V_183 = V_183 ;
F_221 ( & V_183 -> V_376 . V_414 , L_58 ,
& V_422 ) ;
return & V_183 -> V_376 ;
}
static void F_222 ( struct V_2 * V_3 )
{
F_34 ( F_1 ( V_3 ) ) ;
}
static void F_223 ( struct V_372 * V_373 ,
struct V_2 * V_3 )
{
struct V_1 * V_79 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_79 -> V_7 ;
struct V_371 * V_183 =
F_2 ( V_3 -> V_375 , struct V_371 , V_376 ) ;
struct V_91 * V_12 = V_79 -> V_227 ;
unsigned V_66 = V_7 -> V_201 ;
unsigned long V_52 ;
F_20 () ;
if ( V_7 -> V_79 == V_79 ) {
F_143 ( V_79 ) ;
V_7 -> V_79 = NULL ;
}
if ( ! -- V_183 -> V_380 )
F_138 ( V_7 ) ;
F_144 ( & V_79 -> V_7 -> V_111 , V_52 ) ;
do {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_59 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
} while ( -- V_66 );
F_146 ( & V_79 -> V_7 -> V_111 , V_52 ) ;
F_34 ( V_79 -> V_227 ) ;
V_79 -> V_227 = NULL ;
V_79 -> V_4 . V_343 = NULL ;
V_79 -> V_4 . V_342 = NULL ;
V_79 -> V_4 . V_341 = NULL ;
V_79 -> V_349 = NULL ;
F_174 ( V_7 , V_332 ) ;
}
static struct V_2 * F_224 ( struct V_415 * V_375 )
{
struct V_1 * V_79 ;
F_20 () ;
V_79 = F_126 ( sizeof( * V_79 ) , V_70 ) ;
if ( F_12 ( ! V_79 ) )
return F_102 ( - V_71 ) ;
V_79 -> V_4 . V_163 = L_59 ;
V_79 -> V_4 . V_423 = F_194 ;
V_79 -> V_4 . V_424 = F_223 ;
V_79 -> V_4 . V_425 = F_196 ;
V_79 -> V_4 . V_426 = F_197 ;
V_79 -> V_4 . V_23 = F_198 ;
V_79 -> V_4 . V_427 = F_201 ;
V_79 -> V_4 . V_428 = F_202 ;
V_79 -> V_4 . V_429 = F_222 ;
return & V_79 -> V_4 ;
}
static struct V_196 * F_220 ( void )
{
struct V_196 * V_378 ;
int V_20 ;
if ( F_205 () )
return F_102 ( - V_74 ) ;
V_378 = F_126 ( sizeof( * V_378 ) , V_70 ) ;
if ( ! V_378 )
return F_102 ( - V_71 ) ;
if ( F_225 ( & V_410 ) ) {
V_20 = F_112 () ;
if ( V_20 ) {
F_34 ( V_378 ) ;
return F_102 ( V_20 ) ;
}
}
F_226 ( & V_378 -> V_370 , & V_410 ) ;
return V_378 ;
}
static int F_218 ( struct V_196 * V_378 , const char * V_163 )
{
struct V_196 * V_430 ;
V_430 = F_203 ( V_163 ) ;
if ( V_430 )
return - V_74 ;
V_378 -> V_163 = V_163 ;
return 0 ;
}
int F_227 ( struct V_196 * V_378 , const char * V_163 )
{
int V_20 ;
F_187 () ;
V_20 = F_218 ( V_378 , V_163 ) ;
F_188 () ;
return V_20 ;
}
int F_228 ( struct V_196 * V_378 )
{
int V_20 ;
V_20 = 0 ;
F_187 () ;
if ( ! F_206 ( & V_410 ) )
V_20 = - V_74 ;
else
V_378 -> V_411 = true ;
F_188 () ;
return V_20 ;
}
static void F_215 ( struct V_196 * V_378 )
{
F_229 ( & V_378 -> V_370 ) ;
if ( V_378 -> V_419 )
F_34 ( V_378 -> V_163 ) ;
F_34 ( V_378 ) ;
if ( F_225 ( & V_410 ) )
F_114 () ;
}
static void * F_106 ( const char * V_192 )
{
struct V_196 * V_196 ;
F_20 () ;
F_187 () ;
V_196 = F_208 ( V_192 ) ;
if ( ! V_196 )
V_196 = F_102 ( - V_337 ) ;
else if ( V_196 -> V_431 )
V_196 = F_102 ( - V_74 ) ;
else if ( V_196 -> V_432 &&
V_196 -> V_432 ( V_196 ) )
V_196 = F_102 ( - V_337 ) ;
else
V_196 -> V_431 = true ;
F_188 () ;
return V_196 ;
}
static void F_109 ( struct V_6 * V_6 )
{
struct V_196 * V_196 ;
F_20 () ;
F_187 () ;
V_196 = V_6 -> V_40 ;
if ( V_196 ) {
V_196 -> V_431 = false ;
if ( V_196 -> V_433 )
V_196 -> V_433 ( V_196 ) ;
}
F_188 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_196 * V_434 ;
int V_20 = 0 ;
F_20 () ;
F_187 () ;
V_434 = V_7 -> V_40 ;
if ( ! V_434 ) {
V_20 = - V_48 ;
goto V_118;
}
if ( F_64 ( V_434 -> V_379 ) ) {
V_20 = - V_74 ;
goto V_118;
}
V_434 -> V_379 = true ;
V_434 -> V_6 = V_7 ;
if ( V_434 -> V_435 )
V_20 = V_434 -> V_435 ( V_7 ) ;
V_118:
F_188 () ;
return V_20 ;
}
static void F_133 ( struct V_6 * V_7 )
{
struct V_196 * V_434 ;
F_20 () ;
F_187 () ;
V_434 = V_7 -> V_40 ;
if ( ! V_434 )
goto V_118;
V_434 -> V_379 = false ;
if ( V_434 -> V_436 )
V_434 -> V_436 ( V_7 ) ;
if ( ! V_434 -> V_183 || V_434 -> V_183 -> V_377
|| ! V_434 -> V_183 -> V_376 . V_414 . V_437 . V_438 )
goto V_118;
F_230 ( V_434 -> V_183 ->
V_376 . V_414 . V_437 . V_438 -> V_438 ) ;
V_118:
F_188 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_439 )
{
return V_439
? F_40 ( F_231 ( V_42 ) ) ? 0 : - V_69
: F_232 ( V_42 ) ;
}
static char * F_22 ( const char T_3 * V_27 , T_1 V_18 )
{
char * V_17 ;
if ( F_12 ( ! V_18 ) )
return NULL ;
V_17 = F_41 ( V_18 , V_70 ) ;
if ( F_12 ( ! V_17 ) )
return F_102 ( - V_71 ) ;
if ( F_12 ( F_233 ( V_17 , V_27 , V_18 ) ) ) {
F_34 ( V_17 ) ;
return F_102 ( - V_67 ) ;
}
F_16 ( L_60 ) ;
F_177 ( L_58 , V_17 , V_18 ) ;
return V_17 ;
}
