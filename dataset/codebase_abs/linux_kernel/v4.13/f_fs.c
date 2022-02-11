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
F_6 ( V_14 -> V_15 ) ;
}
}
static T_2 F_50 ( void * V_17 , int V_91 , struct V_92 * V_93 )
{
T_2 V_20 = F_51 ( V_17 , V_91 , V_93 ) ;
if ( F_39 ( V_20 == V_91 ) )
return V_20 ;
if ( F_12 ( F_52 ( V_93 ) ) )
return - V_65 ;
F_53 ( L_5
L_6 ,
V_91 , V_20 ) ;
return V_20 ;
}
static void F_54 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = F_2 ( V_95 , struct V_96 ,
V_95 ) ;
int V_20 = V_97 -> V_14 -> V_33 ? V_97 -> V_14 -> V_33 :
V_97 -> V_14 -> V_34 ;
bool V_98 = V_97 -> V_99 -> V_100 & V_101 ;
if ( V_97 -> V_102 && V_20 > 0 ) {
F_55 ( V_97 -> V_103 ) ;
V_20 = F_50 ( V_97 -> V_27 , V_20 , & V_97 -> V_17 ) ;
F_56 ( V_97 -> V_103 ) ;
}
V_97 -> V_99 -> V_104 ( V_97 -> V_99 , V_20 , V_20 ) ;
if ( V_97 -> V_7 -> V_105 && ! V_98 )
F_57 ( V_97 -> V_7 -> V_105 , 1 ) ;
F_58 ( V_97 -> V_12 , V_97 -> V_14 ) ;
if ( V_97 -> V_102 )
F_33 ( V_97 -> V_106 ) ;
F_33 ( V_97 -> V_27 ) ;
F_33 ( V_97 ) ;
}
static void F_59 ( struct V_11 * V_88 ,
struct V_13 * V_14 )
{
struct V_96 * V_97 = V_14 -> V_15 ;
F_20 () ;
F_60 ( & V_97 -> V_95 , F_54 ) ;
F_61 ( & V_97 -> V_95 ) ;
}
static void F_62 ( struct V_107 * V_108 )
{
struct V_109 * V_27 = F_63 ( & V_108 -> V_110 , V_111 ) ;
if ( V_27 && V_27 != V_111 )
F_33 ( V_27 ) ;
}
static T_2 F_64 ( struct V_107 * V_108 ,
struct V_92 * V_93 )
{
struct V_109 * V_27 = F_63 ( & V_108 -> V_110 , NULL ) ;
T_2 V_20 ;
if ( ! V_27 || V_27 == V_111 )
return 0 ;
V_20 = F_51 ( V_27 -> V_17 , V_27 -> V_28 , V_93 ) ;
if ( V_27 -> V_28 == V_20 ) {
F_33 ( V_27 ) ;
return V_20 ;
}
if ( F_12 ( F_52 ( V_93 ) ) ) {
V_20 = - V_65 ;
} else {
V_27 -> V_28 -= V_20 ;
V_27 -> V_17 += V_20 ;
}
if ( F_4 ( & V_108 -> V_110 , NULL , V_27 ) )
F_33 ( V_27 ) ;
return V_20 ;
}
static T_2 F_65 ( struct V_107 * V_108 ,
void * V_17 , int V_91 ,
struct V_92 * V_93 )
{
struct V_109 * V_27 ;
T_2 V_20 = F_51 ( V_17 , V_91 , V_93 ) ;
if ( F_39 ( V_91 == V_20 ) )
return V_20 ;
if ( F_12 ( F_52 ( V_93 ) ) )
return - V_65 ;
F_66 ( L_7 ,
V_91 , V_20 ) ;
V_91 -= V_20 ;
V_27 = F_40 ( sizeof( * V_27 ) + V_91 , V_68 ) ;
if ( ! V_27 )
return - V_69 ;
V_27 -> V_28 = V_91 ;
V_27 -> V_17 = V_27 -> V_112 ;
memcpy ( V_27 -> V_112 , V_17 + V_20 , V_91 ) ;
if ( F_12 ( F_4 ( & V_108 -> V_110 , NULL , V_27 ) ) )
F_33 ( V_27 ) ;
return V_20 ;
}
static T_2 F_67 ( struct V_38 * V_38 , struct V_96 * V_97 )
{
struct V_107 * V_108 = V_38 -> V_40 ;
struct V_13 * V_14 ;
struct V_89 * V_12 ;
char * V_17 = NULL ;
T_2 V_20 , V_91 = - V_48 ;
int V_113 ;
if ( F_68 ( V_108 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_12 = V_108 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 )
return - V_67 ;
V_20 = F_69 (
V_108 -> V_7 -> V_82 , ( V_12 = V_108 -> V_12 ) ) ;
if ( V_20 )
return - V_32 ;
}
V_113 = ( ! V_97 -> V_102 == ! V_108 -> V_114 ) ;
if ( V_113 && V_108 -> V_115 )
return - V_48 ;
V_20 = F_21 ( & V_108 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 ) )
goto error;
if ( ! V_113 ) {
struct V_75 * V_29 ;
if ( ! V_97 -> V_116 && V_97 -> V_102 ) {
V_20 = F_64 ( V_108 , & V_97 -> V_17 ) ;
if ( V_20 )
goto V_117;
}
V_29 = V_108 -> V_7 -> V_29 ;
F_31 ( & V_108 -> V_7 -> V_118 ) ;
if ( V_108 -> V_12 != V_12 ) {
V_20 = - V_119 ;
goto V_120;
}
V_91 = F_52 ( & V_97 -> V_17 ) ;
if ( V_97 -> V_102 )
V_91 = F_70 ( V_29 , V_12 -> V_12 , V_91 ) ;
F_9 ( & V_108 -> V_7 -> V_118 ) ;
V_17 = F_40 ( V_91 , V_68 ) ;
if ( F_12 ( ! V_17 ) ) {
V_20 = - V_69 ;
goto V_117;
}
if ( ! V_97 -> V_102 &&
! F_71 ( V_17 , V_91 , & V_97 -> V_17 ) ) {
V_20 = - V_65 ;
goto V_117;
}
}
F_31 ( & V_108 -> V_7 -> V_118 ) ;
if ( V_108 -> V_12 != V_12 ) {
V_20 = - V_119 ;
} else if ( V_113 ) {
if ( F_39 ( V_108 -> V_12 == V_12 ) && ! F_68 ( ! V_12 -> V_12 ) )
F_17 ( V_12 -> V_12 ) ;
V_20 = - V_121 ;
} else if ( F_12 ( V_91 == - V_48 ) ) {
F_72 ( 1 , L_8 , V_122 ) ;
V_20 = - V_48 ;
} else if ( ! V_97 -> V_116 ) {
F_73 ( V_123 ) ;
bool V_124 = false ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_91 ;
V_14 -> V_15 = & V_123 ;
V_14 -> F_6 = F_49 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 < 0 ) )
goto V_120;
F_9 ( & V_108 -> V_7 -> V_118 ) ;
if ( F_12 ( F_13 ( & V_123 ) ) ) {
F_14 ( V_12 -> V_12 , V_14 ) ;
V_124 = V_12 -> V_33 < 0 ;
}
if ( V_124 )
V_20 = - V_32 ;
else if ( V_97 -> V_102 && V_12 -> V_33 > 0 )
V_20 = F_65 ( V_108 , V_17 , V_12 -> V_33 ,
& V_97 -> V_17 ) ;
else
V_20 = V_12 -> V_33 ;
goto V_117;
} else if ( ! ( V_14 = F_74 ( V_12 -> V_12 , V_68 ) ) ) {
V_20 = - V_69 ;
} else {
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_91 ;
V_97 -> V_27 = V_17 ;
V_97 -> V_12 = V_12 -> V_12 ;
V_97 -> V_14 = V_14 ;
V_97 -> V_7 = V_108 -> V_7 ;
V_14 -> V_15 = V_97 ;
V_14 -> F_6 = F_59 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 ) ) {
F_58 ( V_12 -> V_12 , V_14 ) ;
goto V_120;
}
V_20 = - V_125 ;
V_17 = NULL ;
}
V_120:
F_9 ( & V_108 -> V_7 -> V_118 ) ;
V_117:
F_29 ( & V_108 -> V_42 ) ;
error:
F_33 ( V_17 ) ;
return V_20 ;
}
static int
F_75 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_107 * V_108 = V_70 -> V_71 ;
F_20 () ;
if ( F_68 ( V_108 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_38 -> V_40 = V_108 ;
F_42 ( V_108 -> V_7 ) ;
return 0 ;
}
static int F_76 ( struct V_99 * V_99 )
{
struct V_96 * V_97 = V_99 -> V_126 ;
struct V_107 * V_108 = V_99 -> V_127 -> V_40 ;
int V_74 ;
F_20 () ;
F_31 ( & V_108 -> V_7 -> V_118 ) ;
if ( F_39 ( V_97 && V_97 -> V_12 && V_97 -> V_14 ) )
V_74 = F_14 ( V_97 -> V_12 , V_97 -> V_14 ) ;
else
V_74 = - V_48 ;
F_9 ( & V_108 -> V_7 -> V_118 ) ;
return V_74 ;
}
static T_2 F_77 ( struct V_99 * V_99 , struct V_92 * V_128 )
{
struct V_96 V_97 , * V_129 = & V_97 ;
T_2 V_130 ;
F_20 () ;
if ( ! F_78 ( V_99 ) ) {
V_129 = F_40 ( sizeof( V_97 ) , V_68 ) ;
if ( F_12 ( ! V_129 ) )
return - V_69 ;
V_129 -> V_116 = true ;
} else {
V_129 -> V_116 = false ;
}
V_129 -> V_102 = false ;
V_129 -> V_99 = V_99 ;
V_129 -> V_17 = * V_128 ;
V_129 -> V_103 = V_131 -> V_103 ;
V_99 -> V_126 = V_129 ;
if ( V_129 -> V_116 )
F_79 ( V_99 , F_76 ) ;
V_130 = F_67 ( V_99 -> V_127 , V_129 ) ;
if ( V_130 == - V_125 )
return V_130 ;
if ( V_129 -> V_116 )
F_33 ( V_129 ) ;
else
* V_128 = V_129 -> V_17 ;
return V_130 ;
}
static T_2 F_80 ( struct V_99 * V_99 , struct V_92 * V_132 )
{
struct V_96 V_97 , * V_129 = & V_97 ;
T_2 V_130 ;
F_20 () ;
if ( ! F_78 ( V_99 ) ) {
V_129 = F_40 ( sizeof( V_97 ) , V_68 ) ;
if ( F_12 ( ! V_129 ) )
return - V_69 ;
V_129 -> V_116 = true ;
} else {
V_129 -> V_116 = false ;
}
V_129 -> V_102 = true ;
V_129 -> V_99 = V_99 ;
if ( V_129 -> V_116 ) {
V_129 -> V_106 = F_81 ( & V_129 -> V_17 , V_132 , V_68 ) ;
if ( ! V_129 -> V_106 ) {
F_33 ( V_129 ) ;
return - V_69 ;
}
} else {
V_129 -> V_17 = * V_132 ;
V_129 -> V_106 = NULL ;
}
V_129 -> V_103 = V_131 -> V_103 ;
V_99 -> V_126 = V_129 ;
if ( V_129 -> V_116 )
F_79 ( V_99 , F_76 ) ;
V_130 = F_67 ( V_99 -> V_127 , V_129 ) ;
if ( V_130 == - V_125 )
return V_130 ;
if ( V_129 -> V_116 ) {
F_33 ( V_129 -> V_106 ) ;
F_33 ( V_129 ) ;
} else {
* V_132 = V_129 -> V_17 ;
}
return V_130 ;
}
static int
F_82 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_107 * V_108 = V_70 -> V_71 ;
F_20 () ;
F_62 ( V_108 ) ;
F_44 ( V_108 -> V_7 ) ;
return 0 ;
}
static long F_83 ( struct V_38 * V_38 , unsigned V_73 ,
unsigned long V_74 )
{
struct V_107 * V_108 = V_38 -> V_40 ;
struct V_89 * V_12 ;
int V_20 ;
F_20 () ;
if ( F_68 ( V_108 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_12 = V_108 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 )
return - V_67 ;
V_20 = F_69 (
V_108 -> V_7 -> V_82 , ( V_12 = V_108 -> V_12 ) ) ;
if ( V_20 )
return - V_32 ;
}
F_31 ( & V_108 -> V_7 -> V_118 ) ;
if ( V_108 -> V_12 != V_12 ) {
F_9 ( & V_108 -> V_7 -> V_118 ) ;
return - V_119 ;
}
switch ( V_73 ) {
case V_133 :
V_20 = F_84 ( V_108 -> V_12 -> V_12 ) ;
break;
case V_134 :
F_85 ( V_108 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_135 :
V_20 = F_86 ( V_108 -> V_12 -> V_12 ) ;
break;
case V_136 :
V_20 = V_108 -> V_12 -> V_137 ;
break;
case V_138 :
{
int V_139 ;
struct V_140 * V_141 ;
switch ( V_108 -> V_7 -> V_29 -> V_142 ) {
case V_143 :
V_139 = 2 ;
break;
case V_144 :
V_139 = 1 ;
break;
default:
V_139 = 0 ;
}
V_141 = V_108 -> V_12 -> V_145 [ V_139 ] ;
F_9 ( & V_108 -> V_7 -> V_118 ) ;
V_20 = F_36 ( ( void * ) V_74 , V_141 , V_141 -> V_146 ) ;
if ( V_20 )
V_20 = - V_65 ;
return V_20 ;
}
default:
V_20 = - V_81 ;
}
F_9 ( & V_108 -> V_7 -> V_118 ) ;
return V_20 ;
}
static struct V_70 * T_6
F_87 ( struct V_147 * V_148 , void * V_17 ,
const struct V_149 * V_150 ,
const struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_70 * V_70 ;
F_20 () ;
V_70 = F_88 ( V_148 ) ;
if ( F_39 ( V_70 ) ) {
struct V_155 V_156 = F_89 ( V_70 ) ;
V_70 -> V_157 = F_90 () ;
V_70 -> V_158 = V_154 -> V_159 ;
V_70 -> V_160 = V_154 -> V_161 ;
V_70 -> V_162 = V_154 -> V_163 ;
V_70 -> V_164 = V_156 ;
V_70 -> V_165 = V_156 ;
V_70 -> V_166 = V_156 ;
V_70 -> V_71 = V_17 ;
if ( V_150 )
V_70 -> V_167 = V_150 ;
if ( V_152 )
V_70 -> V_168 = V_152 ;
}
return V_70 ;
}
static struct V_169 * F_91 ( struct V_147 * V_148 ,
const char * V_170 , void * V_17 ,
const struct V_149 * V_150 )
{
struct V_6 * V_7 = V_148 -> V_171 ;
struct V_169 * V_169 ;
struct V_70 * V_70 ;
F_20 () ;
V_169 = F_92 ( V_148 -> V_172 , V_170 ) ;
if ( F_12 ( ! V_169 ) )
return NULL ;
V_70 = F_87 ( V_148 , V_17 , V_150 , NULL , & V_7 -> V_173 ) ;
if ( F_12 ( ! V_70 ) ) {
F_93 ( V_169 ) ;
return NULL ;
}
F_94 ( V_169 , V_70 ) ;
return V_169 ;
}
static int F_95 ( struct V_147 * V_148 , void * V_174 , int V_175 )
{
struct V_176 * V_17 = V_174 ;
struct V_70 * V_70 ;
struct V_6 * V_7 = V_17 -> V_6 ;
F_20 () ;
V_7 -> V_148 = V_148 ;
V_17 -> V_6 = NULL ;
V_148 -> V_171 = V_7 ;
V_148 -> V_177 = V_178 ;
V_148 -> V_179 = V_180 ;
V_148 -> V_181 = V_182 ;
V_148 -> V_183 = & V_184 ;
V_148 -> V_185 = 1 ;
V_17 -> V_154 . V_159 = V_17 -> V_186 ;
V_70 = F_87 ( V_148 , NULL ,
& V_187 ,
& V_188 ,
& V_17 -> V_154 ) ;
V_148 -> V_172 = F_96 ( V_70 ) ;
if ( F_12 ( ! V_148 -> V_172 ) )
return - V_69 ;
if ( F_12 ( ! F_91 ( V_148 , L_9 , V_7 ,
& V_189 ) ) )
return - V_69 ;
return 0 ;
}
static int F_97 ( struct V_176 * V_17 , char * V_190 )
{
F_20 () ;
if ( ! V_190 || ! * V_190 )
return 0 ;
for (; ; ) {
unsigned long V_74 ;
char * V_191 , * V_192 ;
V_192 = strchr ( V_190 , ',' ) ;
if ( V_192 )
* V_192 = 0 ;
V_191 = strchr ( V_190 , '=' ) ;
if ( F_12 ( ! V_191 ) ) {
F_53 ( L_10 , V_190 ) ;
return - V_48 ;
}
* V_191 = 0 ;
if ( F_98 ( V_191 + 1 , 0 , & V_74 ) ) {
F_53 ( L_11 , V_190 , V_191 + 1 ) ;
return - V_48 ;
}
switch ( V_191 - V_190 ) {
case 13 :
if ( ! memcmp ( V_190 , L_12 , 13 ) )
V_17 -> V_193 = ! ! V_74 ;
else
goto V_194;
break;
case 5 :
if ( ! memcmp ( V_190 , L_13 , 5 ) )
V_17 -> V_186 = ( V_74 & 0555 ) | V_195 ;
else if ( ! memcmp ( V_190 , L_14 , 5 ) )
V_17 -> V_154 . V_159 = ( V_74 & 0666 ) | V_196 ;
else
goto V_194;
break;
case 4 :
if ( ! memcmp ( V_190 , L_15 , 4 ) ) {
V_17 -> V_186 = ( V_74 & 0555 ) | V_195 ;
V_17 -> V_154 . V_159 = ( V_74 & 0666 ) | V_196 ;
} else {
goto V_194;
}
break;
case 3 :
if ( ! memcmp ( V_190 , L_16 , 3 ) ) {
V_17 -> V_154 . V_161 = F_99 ( F_100 () , V_74 ) ;
if ( ! F_101 ( V_17 -> V_154 . V_161 ) ) {
F_53 ( L_17 , V_190 , V_74 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_190 , L_18 , 3 ) ) {
V_17 -> V_154 . V_163 = F_102 ( F_100 () , V_74 ) ;
if ( ! F_103 ( V_17 -> V_154 . V_163 ) ) {
F_53 ( L_17 , V_190 , V_74 ) ;
return - V_48 ;
}
} else {
goto V_194;
}
break;
default:
V_194:
F_53 ( L_19 , V_190 ) ;
return - V_48 ;
}
if ( ! V_192 )
break;
V_190 = V_192 + 1 ;
}
return 0 ;
}
static struct V_169 *
F_104 ( struct V_197 * V_198 , int V_199 ,
const char * V_200 , void * V_190 )
{
struct V_176 V_17 = {
. V_154 = {
. V_159 = V_196 | 0600 ,
. V_161 = V_201 ,
. V_163 = V_202 ,
} ,
. V_186 = V_195 | 0500 ,
. V_193 = false ,
} ;
struct V_169 * V_203 ;
int V_20 ;
void * V_204 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_97 ( & V_17 , V_190 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_105 ( V_20 ) ;
V_7 = F_106 () ;
if ( F_12 ( ! V_7 ) )
return F_105 ( - V_69 ) ;
V_7 -> V_173 = V_17 . V_154 ;
V_7 -> V_193 = V_17 . V_193 ;
V_7 -> V_200 = F_107 ( V_200 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_200 ) ) {
F_108 ( V_7 ) ;
return F_105 ( - V_69 ) ;
}
V_204 = F_109 ( V_200 ) ;
if ( F_23 ( V_204 ) ) {
F_108 ( V_7 ) ;
return F_110 ( V_204 ) ;
}
V_7 -> V_40 = V_204 ;
V_17 . V_6 = V_7 ;
V_203 = F_111 ( V_198 , V_199 , & V_17 , F_95 ) ;
if ( F_23 ( V_203 ) && V_17 . V_6 ) {
F_112 ( V_17 . V_6 ) ;
F_108 ( V_17 . V_6 ) ;
}
return V_203 ;
}
static void
F_113 ( struct V_147 * V_148 )
{
F_20 () ;
F_114 ( V_148 ) ;
if ( V_148 -> V_171 ) {
F_112 ( V_148 -> V_171 ) ;
F_44 ( V_148 -> V_171 ) ;
F_108 ( V_148 -> V_171 ) ;
}
}
static int F_115 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_116 ( & V_205 ) ;
if ( F_39 ( ! V_20 ) )
F_25 ( L_20 ) ;
else
F_53 ( L_21 , V_20 ) ;
return V_20 ;
}
static void F_117 ( void )
{
F_20 () ;
F_25 ( L_22 ) ;
F_118 ( & V_205 ) ;
}
static void F_119 ( struct V_6 * V_7 )
{
F_20 () ;
F_120 ( & V_7 -> V_206 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_20 () ;
F_120 ( & V_7 -> V_206 ) ;
if ( F_121 ( 1 , & V_7 -> V_207 ) == 1 &&
V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_122 ( V_7 ) ;
}
}
static void F_108 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_123 ( & V_7 -> V_206 ) ) ) {
F_25 ( L_23 , V_122 ) ;
F_124 ( V_7 ) ;
F_125 ( F_126 ( & V_7 -> V_22 . V_25 ) ||
F_126 ( & V_7 -> V_16 . V_82 ) ||
F_126 ( & V_7 -> V_82 ) ) ;
F_33 ( V_7 -> V_200 ) ;
F_33 ( V_7 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_127 ( & V_7 -> V_207 ) ) {
if ( V_7 -> V_193 ) {
V_7 -> V_45 = V_87 ;
if ( V_7 -> V_208 ) {
F_128 ( V_7 -> V_208 ,
V_7 -> V_209 ) ;
V_7 -> V_208 = NULL ;
}
if ( V_7 -> V_8 == V_52 )
F_15 ( V_7 ) ;
} else {
V_7 -> V_45 = V_49 ;
F_122 ( V_7 ) ;
}
}
if ( F_129 ( & V_7 -> V_207 ) < 0 ) {
V_7 -> V_45 = V_49 ;
F_122 ( V_7 ) ;
}
F_108 ( V_7 ) ;
}
static struct V_6 * F_106 ( void )
{
struct V_6 * V_7 = F_130 ( sizeof *V_7 , V_68 ) ;
if ( F_12 ( ! V_7 ) )
return NULL ;
F_20 () ;
F_131 ( & V_7 -> V_206 , 1 ) ;
F_132 ( & V_7 -> V_207 , 0 ) ;
V_7 -> V_45 = V_46 ;
F_133 ( & V_7 -> V_42 ) ;
F_134 ( & V_7 -> V_118 ) ;
F_135 ( & V_7 -> V_22 . V_25 ) ;
F_135 ( & V_7 -> V_82 ) ;
F_136 ( & V_7 -> V_16 ) ;
V_7 -> V_22 . V_35 = 1 ;
return V_7 ;
}
static void F_124 ( struct V_6 * V_7 )
{
F_20 () ;
F_137 ( V_7 ) ;
F_125 ( V_7 -> V_29 ) ;
if ( V_7 -> V_208 )
F_128 ( V_7 -> V_208 , V_7 -> V_209 ) ;
if ( V_7 -> V_105 )
F_138 ( V_7 -> V_105 ) ;
F_33 ( V_7 -> V_210 ) ;
F_33 ( V_7 -> V_211 ) ;
F_33 ( V_7 -> V_212 ) ;
}
static void F_122 ( struct V_6 * V_7 )
{
F_20 () ;
F_124 ( V_7 ) ;
V_7 -> V_208 = NULL ;
V_7 -> V_210 = NULL ;
V_7 -> V_213 = NULL ;
V_7 -> V_211 = NULL ;
V_7 -> V_212 = NULL ;
V_7 -> V_214 = 0 ;
V_7 -> V_215 = 0 ;
V_7 -> V_216 = 0 ;
V_7 -> V_217 = 0 ;
V_7 -> V_218 = 0 ;
V_7 -> V_219 = 0 ;
V_7 -> V_209 = 0 ;
V_7 -> V_22 . V_64 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_199 = 0 ;
}
static int F_139 ( struct V_6 * V_7 , struct V_220 * V_221 )
{
struct V_222 * * V_223 ;
int V_224 ;
F_20 () ;
if ( F_68 ( V_7 -> V_45 != V_50
|| F_140 ( V_225 , & V_7 -> V_199 ) ) )
return - V_55 ;
V_224 = F_141 ( V_221 , V_7 -> V_218 ) ;
if ( F_12 ( V_224 < 0 ) )
return V_224 ;
V_7 -> V_19 = F_74 ( V_221 -> V_29 -> V_30 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_69 ;
V_7 -> V_19 -> F_6 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_223 = V_7 -> V_212 ;
if ( V_223 ) {
for (; * V_223 ; ++ V_223 ) {
struct V_226 * V_227 = ( * V_223 ) -> V_228 ;
int V_229 = V_224 ;
for (; V_227 -> V_230 ; ++ V_229 , ++ V_227 )
V_227 -> V_229 = V_229 ;
}
}
V_7 -> V_29 = V_221 -> V_29 ;
F_119 ( V_7 ) ;
return 0 ;
}
static void F_142 ( struct V_6 * V_7 )
{
F_20 () ;
if ( ! F_68 ( ! V_7 -> V_29 ) ) {
F_58 ( V_7 -> V_29 -> V_30 , V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_29 = NULL ;
F_143 ( V_225 , & V_7 -> V_199 ) ;
F_108 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_107 * V_108 , * V_208 ;
unsigned V_61 , V_64 ;
F_20 () ;
V_64 = V_7 -> V_209 ;
V_208 = F_144 ( V_64 , sizeof( * V_208 ) , V_68 ) ;
if ( ! V_208 )
return - V_69 ;
V_108 = V_208 ;
for ( V_61 = 1 ; V_61 <= V_64 ; ++ V_61 , ++ V_108 ) {
V_108 -> V_7 = V_7 ;
F_133 ( & V_108 -> V_42 ) ;
if ( V_7 -> V_231 & V_232 )
sprintf ( V_108 -> V_170 , L_24 , V_7 -> V_233 [ V_61 ] ) ;
else
sprintf ( V_108 -> V_170 , L_25 , V_61 ) ;
V_108 -> V_169 = F_91 ( V_7 -> V_148 , V_108 -> V_170 ,
V_108 ,
& V_234 ) ;
if ( F_12 ( ! V_108 -> V_169 ) ) {
F_128 ( V_208 , V_61 - 1 ) ;
return - V_69 ;
}
}
V_7 -> V_208 = V_208 ;
return 0 ;
}
static void F_128 ( struct V_107 * V_208 , unsigned V_64 )
{
struct V_107 * V_108 = V_208 ;
F_20 () ;
for (; V_64 ; -- V_64 , ++ V_108 ) {
F_125 ( F_145 ( & V_108 -> V_42 ) ) ;
if ( V_108 -> V_169 ) {
F_146 ( V_108 -> V_169 ) ;
F_93 ( V_108 -> V_169 ) ;
V_108 -> V_169 = NULL ;
}
}
F_33 ( V_208 ) ;
}
static void F_147 ( struct V_1 * V_77 )
{
struct V_89 * V_12 = V_77 -> V_235 ;
struct V_107 * V_108 = V_77 -> V_7 -> V_208 ;
unsigned V_64 = V_77 -> V_7 -> V_209 ;
unsigned long V_199 ;
F_148 ( & V_77 -> V_7 -> V_118 , V_199 ) ;
while ( V_64 -- ) {
if ( F_39 ( V_12 -> V_12 ) )
F_149 ( V_12 -> V_12 ) ;
++ V_12 ;
if ( V_108 ) {
V_108 -> V_12 = NULL ;
F_62 ( V_108 ) ;
++ V_108 ;
}
}
F_150 ( & V_77 -> V_7 -> V_118 , V_199 ) ;
}
static int F_151 ( struct V_1 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_89 * V_12 = V_77 -> V_235 ;
struct V_107 * V_108 = V_7 -> V_208 ;
unsigned V_64 = V_7 -> V_209 ;
unsigned long V_199 ;
int V_20 = 0 ;
F_148 ( & V_77 -> V_7 -> V_118 , V_199 ) ;
while( V_64 -- ) {
struct V_140 * V_236 ;
struct V_237 * V_238 = NULL ;
int V_239 = false ;
int V_139 ;
if ( V_7 -> V_29 -> V_142 == V_143 ) {
V_139 = 2 ;
V_239 = true ;
} else if ( V_7 -> V_29 -> V_142 == V_144 )
V_139 = 1 ;
else
V_139 = 0 ;
do {
V_236 = V_12 -> V_145 [ V_139 ] ;
} while ( ! V_236 && -- V_139 >= 0 );
if ( ! V_236 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_90 = V_12 ;
V_12 -> V_12 -> V_141 = V_236 ;
if ( V_239 ) {
V_238 = (struct V_237 * ) ( V_236 +
V_240 ) ;
V_12 -> V_12 -> V_241 = V_238 -> V_242 + 1 ;
V_12 -> V_12 -> V_238 = V_238 ;
}
V_20 = F_152 ( V_12 -> V_12 ) ;
if ( F_39 ( ! V_20 ) ) {
V_108 -> V_12 = V_12 ;
V_108 -> V_114 = F_153 ( V_236 ) ;
V_108 -> V_115 = F_154 ( V_236 ) ;
} else {
break;
}
++ V_12 ;
++ V_108 ;
}
F_155 ( & V_7 -> V_82 ) ;
F_150 ( & V_77 -> V_7 -> V_118 , V_199 ) ;
return V_20 ;
}
static int T_6 F_156 ( char * V_17 , unsigned V_18 ,
T_7 V_243 ,
void * V_244 )
{
struct V_245 * V_246 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_26 ) ;
return - V_48 ;
}
V_28 = V_246 -> V_146 ;
if ( V_18 < V_28 ) {
F_16 ( L_27 ) ;
return - V_48 ;
}
#define F_157 ( T_9 ) 1
#define F_158 ( T_9 ) (val)
#define F_159 ( T_9 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_160 ( type , T_9 ) do { \
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
switch ( V_246 -> V_247 ) {
case V_248 :
case V_249 :
case V_250 :
case V_251 :
F_16 ( L_28 ,
V_246 -> V_247 ) ;
return - V_48 ;
case V_252 : {
struct V_253 * V_236 = ( void * ) V_246 ;
F_16 ( L_29 ) ;
if ( V_28 != sizeof *V_236 )
goto V_254;
F_160 ( V_255 , V_236 -> V_256 ) ;
if ( V_236 -> V_257 )
F_160 ( STRING , V_236 -> V_257 ) ;
}
break;
case V_258 : {
struct V_140 * V_236 = ( void * ) V_246 ;
F_16 ( L_30 ) ;
if ( V_28 != V_240 &&
V_28 != V_259 )
goto V_254;
F_160 ( V_260 , V_236 -> V_261 ) ;
}
break;
case V_262 :
F_16 ( L_31 ) ;
if ( V_28 != sizeof( struct V_263 ) )
goto V_254;
break;
case V_264 :
if ( V_28 != sizeof( struct V_265 ) )
goto V_254;
break;
case V_266 : {
struct V_267 * V_236 = ( void * ) V_246 ;
F_16 ( L_32 ) ;
if ( V_28 != sizeof *V_236 )
goto V_254;
if ( V_236 -> V_268 )
F_160 ( STRING , V_236 -> V_268 ) ;
}
break;
case V_269 :
F_16 ( L_33 ) ;
if ( V_28 != sizeof( struct V_237 ) )
goto V_254;
break;
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
F_16 ( L_34 , V_246 -> V_247 ) ;
return - V_48 ;
default:
F_16 ( L_35 , V_246 -> V_247 ) ;
return - V_48 ;
V_254:
F_16 ( L_36 ,
V_246 -> V_146 , V_246 -> V_247 ) ;
return - V_48 ;
}
#undef F_160
#undef V_275
#undef F_157
#undef F_158
#undef F_159
return V_28 ;
}
static int T_6 F_161 ( unsigned V_64 , char * V_17 , unsigned V_18 ,
T_7 V_243 , void * V_244 )
{
const unsigned V_276 = V_18 ;
unsigned long V_137 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_137 == V_64 )
V_17 = NULL ;
V_20 = V_243 ( V_277 , ( T_8 * ) V_137 , ( void * ) V_17 , V_244 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_37 ,
V_137 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_276 - V_18 ;
V_20 = F_156 ( V_17 , V_18 , V_243 , V_244 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 , V_122 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_137 ;
}
}
static int F_162 ( enum V_278 type ,
T_8 * V_279 , struct V_245 * V_141 ,
void * V_244 )
{
struct V_280 * V_281 = V_244 ;
struct V_140 * V_282 ;
F_20 () ;
switch ( type ) {
case V_277 :
break;
case V_283 :
if ( * V_279 >= V_281 -> V_219 )
V_281 -> V_219 = * V_279 + 1 ;
break;
case V_284 :
if ( * V_279 > V_281 -> V_7 -> V_218 )
V_281 -> V_7 -> V_218 = * V_279 ;
break;
case V_285 :
V_282 = ( void * ) V_141 ;
V_281 -> V_209 ++ ;
if ( V_281 -> V_209 >= V_286 )
return - V_48 ;
if ( ! V_281 -> V_7 -> V_209 && ! V_281 -> V_7 -> V_219 )
V_281 -> V_7 -> V_233 [ V_281 -> V_209 ] =
V_282 -> V_261 ;
else if ( V_281 -> V_7 -> V_233 [ V_281 -> V_209 ] !=
V_282 -> V_261 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_163 ( enum V_287 * V_288 ,
struct V_289 * V_141 )
{
T_10 V_290 = F_8 ( V_141 -> V_291 ) ;
T_10 V_292 = F_8 ( V_141 -> V_293 ) ;
if ( V_290 != 1 ) {
F_16 ( L_39 ,
V_290 ) ;
return - V_48 ;
}
switch ( V_292 ) {
case 0x4 :
* V_288 = V_294 ;
break;
case 0x5 :
* V_288 = V_295 ;
break;
default:
F_16 ( L_40 , V_292 ) ;
return - V_48 ;
}
return sizeof( * V_141 ) ;
}
static int T_6 F_164 ( char * V_17 , unsigned V_18 ,
enum V_287 type ,
T_10 V_296 ,
T_11 V_243 ,
void * V_244 ,
struct V_289 * V_297 )
{
int V_20 ;
const unsigned V_276 = V_18 ;
F_20 () ;
while ( V_296 -- ) {
V_20 = V_243 ( type , V_297 , V_17 , V_18 , V_244 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_41 , type ) ;
return V_20 ;
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
return V_276 - V_18 ;
}
static int T_6 F_165 ( unsigned V_64 ,
char * V_17 , unsigned V_18 ,
T_11 V_243 , void * V_244 )
{
const unsigned V_276 = V_18 ;
unsigned long V_137 = 0 ;
F_20 () ;
for ( V_137 = 0 ; V_137 < V_64 ; ++ V_137 ) {
int V_20 ;
enum V_287 type ;
T_10 V_296 ;
struct V_289 * V_141 = ( void * ) V_17 ;
if ( V_18 < sizeof( * V_141 ) )
return - V_48 ;
if ( F_166 ( V_141 -> V_298 ) > V_18 )
return - V_48 ;
V_20 = F_163 ( & type , V_141 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_42 ,
V_137 , V_20 ) ;
return V_20 ;
}
V_296 = F_8 ( V_141 -> V_299 ) ;
if ( type == V_294 &&
( V_296 > 255 || V_141 -> V_300 ) )
return - V_48 ;
V_18 -= V_20 ;
V_17 += V_20 ;
V_20 = F_164 ( V_17 , V_18 , type ,
V_296 , V_243 , V_244 , V_141 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 , V_122 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
return V_276 - V_18 ;
}
static int F_167 ( enum V_287 type ,
struct V_289 * V_297 , void * V_17 ,
unsigned V_18 , void * V_244 )
{
struct V_6 * V_7 = V_244 ;
T_8 V_28 ;
F_20 () ;
switch ( type ) {
case V_294 : {
struct V_301 * V_282 = V_17 ;
int V_61 ;
if ( V_18 < sizeof( * V_282 ) ||
V_282 -> V_302 >= V_7 -> V_219 ||
! V_282 -> V_303 )
return - V_48 ;
for ( V_61 = 0 ; V_61 < F_35 ( V_282 -> V_304 ) ; ++ V_61 )
if ( V_282 -> V_304 [ V_61 ] )
return - V_48 ;
V_28 = sizeof( struct V_301 ) ;
}
break;
case V_295 : {
struct V_305 * V_282 = V_17 ;
T_12 type , V_306 ;
T_10 V_307 ;
if ( V_18 < sizeof( * V_282 ) || V_297 -> V_308 >= V_7 -> V_219 )
return - V_48 ;
V_28 = F_166 ( V_282 -> V_309 ) ;
if ( V_18 < V_28 )
return - V_48 ;
type = F_166 ( V_282 -> V_310 ) ;
if ( type < V_311 ||
type > V_312 ) {
F_16 ( L_43 ,
type ) ;
return - V_48 ;
}
V_307 = F_8 ( V_282 -> V_313 ) ;
if ( V_28 < 14 + V_307 ) {
F_16 ( L_44 ,
V_28 , V_307 , type ) ;
return - V_48 ;
}
V_306 = F_166 ( * ( T_12 * ) ( ( T_8 * ) V_17 + 10 + V_307 ) ) ;
if ( V_28 != 14 + V_307 + V_306 ) {
F_16 ( L_45 ,
V_28 , V_307 , V_306 , type ) ;
return - V_48 ;
}
++ V_7 -> V_314 ;
V_7 -> V_315 += V_307 * 2 ;
V_7 -> V_316 += V_306 ;
}
break;
default:
F_16 ( L_35 , type ) ;
return - V_48 ;
}
return V_28 ;
}
static int F_26 ( struct V_6 * V_7 ,
char * const V_174 , T_1 V_18 )
{
char * V_17 = V_174 , * V_213 ;
unsigned V_317 = 0 , V_318 [ 3 ] , V_199 ;
int V_20 = - V_48 , V_61 ;
struct V_280 V_281 ;
F_20 () ;
if ( F_168 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_168 ( V_17 ) ) {
case V_319 :
V_199 = V_320 | V_321 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_322 :
V_199 = F_168 ( V_17 + 8 ) ;
V_7 -> V_231 = V_199 ;
if ( V_199 & ~ ( V_320 |
V_321 |
V_323 |
V_324 |
V_232 |
V_325 |
V_326 |
V_327 ) ) {
V_20 = - V_328 ;
goto error;
}
V_17 += 12 ;
V_18 -= 12 ;
break;
default:
goto error;
}
if ( V_199 & V_325 ) {
if ( V_18 < 4 )
goto error;
V_7 -> V_105 =
F_169 ( ( int ) F_168 ( V_17 ) ) ;
if ( F_23 ( V_7 -> V_105 ) ) {
V_20 = F_24 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
goto error;
}
V_17 += 4 ;
V_18 -= 4 ;
}
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! ( V_199 & ( 1 << V_61 ) ) ) {
V_318 [ V_61 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_318 [ V_61 ] = F_168 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
if ( V_199 & ( 1 << V_61 ) ) {
if ( V_18 < 4 ) {
goto error;
}
V_317 = F_168 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
} ;
V_213 = V_17 ;
V_281 . V_7 = V_7 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! V_318 [ V_61 ] )
continue;
V_281 . V_219 = 0 ;
V_281 . V_209 = 0 ;
V_20 = F_161 ( V_318 [ V_61 ] , V_17 , V_18 ,
F_162 , & V_281 ) ;
if ( V_20 < 0 )
goto error;
if ( ! V_7 -> V_209 && ! V_7 -> V_219 ) {
V_7 -> V_209 = V_281 . V_209 ;
V_7 -> V_219 = V_281 . V_219 ;
} else {
if ( V_7 -> V_209 != V_281 . V_209 ) {
V_20 = - V_48 ;
goto error;
}
if ( V_7 -> V_219 != V_281 . V_219 ) {
V_20 = - V_48 ;
goto error;
}
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_317 ) {
V_20 = F_165 ( V_317 , V_17 , V_18 ,
F_167 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_213 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_210 = V_174 ;
V_7 -> V_213 = V_213 ;
V_7 -> V_214 = V_17 - V_213 ;
V_7 -> V_215 = V_318 [ 0 ] ;
V_7 -> V_216 = V_318 [ 1 ] ;
V_7 -> V_217 = V_318 [ 2 ] ;
V_7 -> V_329 = V_317 ;
return 0 ;
error:
F_33 ( V_174 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_174 , T_1 V_18 )
{
T_12 V_330 , V_331 , V_332 ;
struct V_222 * * V_212 , * V_198 ;
const char * V_17 = V_174 ;
struct V_226 * V_230 ;
F_20 () ;
if ( F_12 ( V_18 < 16 ||
F_168 ( V_17 ) != V_333 ||
F_168 ( V_17 + 4 ) != V_18 ) )
goto error;
V_330 = F_168 ( V_17 + 8 ) ;
V_332 = F_168 ( V_17 + 12 ) ;
if ( F_12 ( ! V_330 != ! V_332 ) )
goto error;
V_331 = V_7 -> V_218 ;
if ( F_12 ( V_330 < V_331 ) )
goto error;
if ( ! V_331 ) {
F_33 ( V_174 ) ;
return 0 ;
}
{
unsigned V_61 = 0 ;
F_170 ( V_282 ) ;
F_171 ( V_282 , struct V_222 * , V_212 ,
V_332 + 1 ) ;
F_171 ( V_282 , struct V_222 , V_334 , V_332 ) ;
F_171 ( V_282 , struct V_226 , V_228 ,
V_332 * ( V_331 + 1 ) ) ;
char * V_335 = F_40 ( F_172 ( V_282 ) , V_68 ) ;
if ( F_12 ( ! V_335 ) ) {
F_33 ( V_174 ) ;
return - V_69 ;
}
V_212 = F_173 ( V_335 , V_282 , V_212 ) ;
V_198 = F_173 ( V_335 , V_282 , V_334 ) ;
V_61 = V_332 ;
do {
* V_212 ++ = V_198 ++ ;
} while ( -- V_61 );
* V_212 = NULL ;
V_212 = F_173 ( V_335 , V_282 , V_212 ) ;
V_198 = F_173 ( V_335 , V_282 , V_334 ) ;
V_230 = F_173 ( V_335 , V_282 , V_228 ) ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_336 = V_331 ;
if ( F_12 ( V_18 < 3 ) )
goto V_337;
V_198 -> V_338 = F_174 ( V_17 ) ;
V_198 -> V_228 = V_230 ;
++ V_198 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_175 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_337;
if ( F_39 ( V_336 ) ) {
V_230 -> V_230 = V_17 ;
-- V_336 ;
++ V_230 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_330 );
V_230 -> V_229 = 0 ;
V_230 -> V_230 = NULL ;
++ V_230 ;
} while ( -- V_332 );
if ( F_12 ( V_18 ) )
goto V_337;
V_7 -> V_212 = V_212 ;
V_7 -> V_211 = V_174 ;
return 0 ;
V_337:
F_33 ( V_212 ) ;
error:
F_33 ( V_174 ) ;
return - V_48 ;
}
static void F_176 ( struct V_6 * V_7 ,
enum V_339 type )
{
enum V_339 V_340 , V_341 = type ;
int V_342 = 0 ;
if ( V_7 -> V_8 == V_52 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_343 :
V_341 = V_344 ;
case V_344 :
case V_62 :
V_340 = type ;
break;
case V_345 :
case V_346 :
case V_347 :
case V_348 :
V_340 = V_344 ;
V_341 = V_343 ;
V_342 = 1 ;
break;
default:
F_72 ( 1 , L_46 , type ) ;
return;
}
{
T_8 * V_22 = V_7 -> V_22 . V_59 , * V_349 = V_22 ;
unsigned V_56 = V_7 -> V_22 . V_64 ;
for (; V_56 ; -- V_56 , ++ V_22 )
if ( ( * V_22 == V_340 || * V_22 == V_341 ) == V_342 )
* V_349 ++ = * V_22 ;
else
F_16 ( L_47 , * V_22 ) ;
V_7 -> V_22 . V_64 = V_349 - V_7 -> V_22 . V_59 ;
}
F_16 ( L_48 , type ) ;
V_7 -> V_22 . V_59 [ V_7 -> V_22 . V_64 ++ ] = type ;
F_177 ( & V_7 -> V_22 . V_25 ) ;
if ( V_7 -> V_105 )
F_57 ( V_7 -> V_105 , 1 ) ;
}
static void F_178 ( struct V_6 * V_7 ,
enum V_339 type )
{
unsigned long V_199 ;
F_148 ( & V_7 -> V_22 . V_25 . V_26 , V_199 ) ;
F_176 ( V_7 , type ) ;
F_150 ( & V_7 -> V_22 . V_25 . V_26 , V_199 ) ;
}
static int F_179 ( struct V_6 * V_7 , T_8 V_350 )
{
int V_61 ;
for ( V_61 = 1 ; V_61 < F_35 ( V_7 -> V_233 ) ; ++ V_61 )
if ( V_7 -> V_233 [ V_61 ] == V_350 )
return V_61 ;
return - V_351 ;
}
static int F_180 ( enum V_278 type , T_8 * V_279 ,
struct V_245 * V_141 ,
void * V_244 )
{
struct V_140 * V_236 = ( void * ) V_141 ;
struct V_1 * V_77 = V_244 ;
struct V_89 * V_89 ;
unsigned V_352 ;
int V_353 ;
static const char * V_354 [] = { L_49 , L_50 , L_51 } ;
if ( type != V_277 )
return 0 ;
if ( V_77 -> V_4 . V_355 ) {
V_352 = 2 ;
V_77 -> V_4 . V_355 [ ( long ) V_279 ] = V_141 ;
} else if ( V_77 -> V_4 . V_356 ) {
V_352 = 1 ;
V_77 -> V_4 . V_356 [ ( long ) V_279 ] = V_141 ;
} else {
V_352 = 0 ;
V_77 -> V_4 . V_357 [ ( long ) V_279 ] = V_141 ;
}
if ( ! V_141 || V_141 -> V_247 != V_258 )
return 0 ;
V_353 = F_179 ( V_77 -> V_7 , V_236 -> V_261 ) - 1 ;
if ( V_353 < 0 )
return V_353 ;
V_89 = V_77 -> V_235 + V_353 ;
if ( F_12 ( V_89 -> V_145 [ V_352 ] ) ) {
F_53 ( L_52 ,
V_354 [ V_352 ] ,
V_236 -> V_261 & V_358 ) ;
return - V_48 ;
}
V_89 -> V_145 [ V_352 ] = V_236 ;
F_181 ( L_53 , V_236 , V_236 -> V_146 ) ;
if ( V_89 -> V_12 ) {
V_236 -> V_261 = V_89 -> V_145 [ 0 ] -> V_261 ;
if ( ! V_236 -> V_359 )
V_236 -> V_359 = V_89 -> V_145 [ 0 ] -> V_359 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_8 V_261 ;
V_261 = V_236 -> V_261 ;
F_16 ( L_54 ) ;
V_12 = F_182 ( V_77 -> V_29 , V_236 ) ;
if ( F_12 ( ! V_12 ) )
return - V_360 ;
V_12 -> V_90 = V_77 -> V_235 + V_353 ;
V_14 = F_74 ( V_12 , V_68 ) ;
if ( F_12 ( ! V_14 ) )
return - V_69 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_14 = V_14 ;
V_77 -> V_361 [ V_236 -> V_261 &
V_358 ] = V_353 + 1 ;
if ( V_77 -> V_7 -> V_231 & V_232 )
V_236 -> V_261 = V_261 ;
}
F_181 ( L_55 , V_236 , V_236 -> V_146 ) ;
return 0 ;
}
static int F_183 ( enum V_278 type , T_8 * V_279 ,
struct V_245 * V_141 ,
void * V_244 )
{
struct V_1 * V_77 = V_244 ;
unsigned V_353 ;
T_8 V_362 ;
switch ( type ) {
default:
case V_277 :
return 0 ;
case V_283 :
V_353 = * V_279 ;
if ( V_77 -> V_363 [ V_353 ] < 0 ) {
int V_229 = F_184 ( V_77 -> V_364 , & V_77 -> V_4 ) ;
if ( F_12 ( V_229 < 0 ) )
return V_229 ;
V_77 -> V_363 [ V_353 ] = V_229 ;
}
V_362 = V_77 -> V_363 [ V_353 ] ;
break;
case V_284 :
V_362 = V_77 -> V_7 -> V_212 [ 0 ] -> V_228 [ * V_279 - 1 ] . V_229 ;
break;
case V_285 :
if ( V_141 -> V_247 == V_258 )
return 0 ;
V_353 = ( * V_279 & V_358 ) - 1 ;
if ( F_12 ( ! V_77 -> V_235 [ V_353 ] . V_12 ) )
return - V_48 ;
{
struct V_140 * * V_145 ;
V_145 = V_77 -> V_235 [ V_353 ] . V_145 ;
V_362 = V_145 [ V_145 [ 0 ] ? 0 : 1 ] -> V_261 ;
}
break;
}
F_16 ( L_56 , * V_279 , V_362 ) ;
* V_279 = V_362 ;
return 0 ;
}
static int F_185 ( enum V_287 type ,
struct V_289 * V_297 , void * V_17 ,
unsigned V_18 , void * V_244 )
{
struct V_1 * V_77 = V_244 ;
T_8 V_28 = 0 ;
switch ( type ) {
case V_294 : {
struct V_301 * V_141 = V_17 ;
struct V_365 * V_198 ;
V_198 = & V_77 -> V_4 . V_366 [ V_141 -> V_302 ] ;
V_198 -> V_367 = V_77 -> V_363 [ V_141 -> V_302 ] ;
memcpy ( V_198 -> V_368 -> V_369 , & V_141 -> V_370 ,
F_35 ( V_141 -> V_370 ) +
F_35 ( V_141 -> V_371 ) ) ;
V_28 = sizeof( * V_141 ) ;
}
break;
case V_295 : {
struct V_305 * V_141 = V_17 ;
struct V_365 * V_198 ;
struct V_372 * V_373 ;
char * V_374 ;
char * V_375 ;
V_198 = & V_77 -> V_4 . V_366 [ V_297 -> V_308 ] ;
V_198 -> V_367 = V_77 -> V_363 [ V_297 -> V_308 ] ;
V_373 = V_77 -> V_7 -> V_376 ;
V_77 -> V_7 -> V_376 += sizeof( * V_373 ) ;
V_373 -> type = F_166 ( V_141 -> V_310 ) ;
V_373 -> V_377 = F_8 ( V_141 -> V_313 ) ;
V_373 -> V_91 = F_166 ( * ( T_12 * )
F_186 ( V_17 , V_373 -> V_377 ) ) ;
V_28 = V_373 -> V_377 + V_373 -> V_91 + 14 ;
V_374 = V_77 -> V_7 -> V_378 ;
V_77 -> V_7 -> V_378 +=
V_373 -> V_377 ;
V_375 = V_77 -> V_7 -> V_379 ;
V_77 -> V_7 -> V_379 +=
V_373 -> V_91 ;
memcpy ( V_375 ,
F_187 ( V_17 , V_373 -> V_377 ) ,
V_373 -> V_91 ) ;
switch ( V_373 -> type ) {
case V_311 :
case V_380 :
case V_381 :
case V_312 :
V_373 -> V_91 *= 2 ;
break;
}
V_373 -> V_17 = V_375 ;
memcpy ( V_374 , F_188 ( V_17 ) ,
V_373 -> V_377 ) ;
V_373 -> V_377 *= 2 ;
V_373 -> V_170 = V_374 ;
V_198 -> V_368 -> V_382 +=
V_373 -> V_377 + V_373 -> V_91 + 14 ;
++ V_198 -> V_368 -> V_383 ;
F_189 ( & V_373 -> V_384 , & V_198 -> V_368 -> V_373 ) ;
}
break;
default:
F_16 ( L_35 , type ) ;
}
return V_28 ;
}
static inline struct V_385 * F_190 ( struct V_2 * V_3 ,
struct V_386 * V_387 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_385 * V_388 =
F_2 ( V_3 -> V_389 , struct V_385 , V_390 ) ;
int V_20 ;
F_20 () ;
if ( ! V_388 -> V_391 )
F_191 () ;
V_20 = V_388 -> V_392 -> V_393 ? 0 : - V_78 ;
V_77 -> V_7 = V_388 -> V_392 -> V_6 ;
if ( ! V_388 -> V_391 )
F_192 () ;
if ( V_20 )
return F_105 ( V_20 ) ;
V_77 -> V_364 = V_387 ;
V_77 -> V_29 = V_387 -> V_221 -> V_29 ;
if ( ! V_388 -> V_394 ) {
V_20 = F_139 ( V_77 -> V_7 , V_387 -> V_221 ) ;
if ( V_20 )
return F_105 ( V_20 ) ;
}
V_388 -> V_394 ++ ;
V_77 -> V_4 . V_228 = V_77 -> V_7 -> V_212 ;
return V_388 ;
}
static int F_193 ( struct V_386 * V_387 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
const int V_395 = ! ! V_77 -> V_7 -> V_215 ;
const int V_396 = F_194 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_216 ;
const int V_397 = F_195 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_217 ;
int V_398 , V_399 , V_400 , V_20 , V_61 ;
struct V_89 * V_401 ;
F_170 ( V_282 ) ;
F_196 ( V_282 , struct V_89 , V_235 , V_7 -> V_209 ) ;
F_196 ( V_282 , struct V_245 * , V_402 ,
V_395 ? V_7 -> V_215 + 1 : 0 ) ;
F_196 ( V_282 , struct V_245 * , V_403 ,
V_396 ? V_7 -> V_216 + 1 : 0 ) ;
F_196 ( V_282 , struct V_245 * , V_404 ,
V_397 ? V_7 -> V_217 + 1 : 0 ) ;
F_196 ( V_282 , short , V_405 , V_7 -> V_219 ) ;
F_196 ( V_282 , struct V_365 , V_366 ,
V_387 -> V_221 -> V_406 ? V_7 -> V_219 : 0 ) ;
F_196 ( V_282 , char [ 16 ] , V_407 ,
V_387 -> V_221 -> V_406 ? V_7 -> V_219 : 0 ) ;
F_196 ( V_282 , struct V_408 , V_368 ,
V_387 -> V_221 -> V_406 ? V_7 -> V_219 : 0 ) ;
F_196 ( V_282 , struct V_372 , V_373 ,
V_7 -> V_314 ) ;
F_196 ( V_282 , char , V_374 ,
V_7 -> V_315 ) ;
F_196 ( V_282 , char , V_375 ,
V_7 -> V_316 ) ;
F_196 ( V_282 , char , V_213 , V_7 -> V_214 ) ;
char * V_335 ;
F_20 () ;
if ( F_12 ( ! ( V_395 | V_396 | V_397 ) ) )
return - V_360 ;
V_335 = F_130 ( F_172 ( V_282 ) , V_68 ) ;
if ( F_12 ( ! V_335 ) )
return - V_69 ;
V_7 -> V_376 = F_173 ( V_335 , V_282 , V_373 ) ;
V_7 -> V_378 =
F_173 ( V_335 , V_282 , V_374 ) ;
V_7 -> V_379 =
F_173 ( V_335 , V_282 , V_375 ) ;
memcpy ( F_173 ( V_335 , V_282 , V_213 ) , V_7 -> V_213 ,
V_7 -> V_214 ) ;
memset ( F_173 ( V_335 , V_282 , V_405 ) , 0xff , V_409 ) ;
V_401 = F_173 ( V_335 , V_282 , V_235 ) ;
for ( V_61 = 0 ; V_61 < V_7 -> V_209 ; V_61 ++ )
V_401 [ V_61 ] . V_137 = - 1 ;
V_77 -> V_235 = F_173 ( V_335 , V_282 , V_235 ) ;
V_77 -> V_363 = F_173 ( V_335 , V_282 , V_405 ) ;
if ( F_39 ( V_395 ) ) {
V_77 -> V_4 . V_357 = F_173 ( V_335 , V_282 , V_402 ) ;
V_398 = F_161 ( V_7 -> V_215 ,
F_173 ( V_335 , V_282 , V_213 ) ,
V_410 ,
F_180 , V_77 ) ;
if ( F_12 ( V_398 < 0 ) ) {
V_20 = V_398 ;
goto error;
}
} else {
V_398 = 0 ;
}
if ( F_39 ( V_396 ) ) {
V_77 -> V_4 . V_356 = F_173 ( V_335 , V_282 , V_403 ) ;
V_399 = F_161 ( V_7 -> V_216 ,
F_173 ( V_335 , V_282 , V_213 ) + V_398 ,
V_410 - V_398 ,
F_180 , V_77 ) ;
if ( F_12 ( V_399 < 0 ) ) {
V_20 = V_399 ;
goto error;
}
} else {
V_399 = 0 ;
}
if ( F_39 ( V_397 ) ) {
V_77 -> V_4 . V_355 = F_173 ( V_335 , V_282 , V_404 ) ;
V_400 = F_161 ( V_7 -> V_217 ,
F_173 ( V_335 , V_282 , V_213 ) + V_398 + V_399 ,
V_410 - V_398 - V_399 ,
F_180 , V_77 ) ;
if ( F_12 ( V_400 < 0 ) ) {
V_20 = V_400 ;
goto error;
}
} else {
V_400 = 0 ;
}
V_20 = F_161 ( V_7 -> V_215 +
( V_396 ? V_7 -> V_216 : 0 ) +
( V_397 ? V_7 -> V_217 : 0 ) ,
F_173 ( V_335 , V_282 , V_213 ) , V_410 ,
F_183 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_77 -> V_4 . V_366 = F_173 ( V_335 , V_282 , V_366 ) ;
if ( V_387 -> V_221 -> V_406 ) {
for ( V_61 = 0 ; V_61 < V_7 -> V_219 ; ++ V_61 ) {
struct V_408 * V_141 ;
V_141 = V_77 -> V_4 . V_366 [ V_61 ] . V_368 =
F_173 ( V_335 , V_282 , V_368 ) +
V_61 * sizeof( struct V_408 ) ;
V_141 -> V_369 =
F_173 ( V_335 , V_282 , V_407 ) + V_61 * 16 ;
F_197 ( & V_141 -> V_373 ) ;
}
V_20 = F_165 ( V_7 -> V_329 ,
F_173 ( V_335 , V_282 , V_213 ) +
V_398 + V_399 + V_400 ,
V_410 - V_398 - V_399 -
V_400 ,
F_185 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
}
V_77 -> V_4 . V_411 =
V_387 -> V_221 -> V_406 ? V_7 -> V_219 : 0 ;
F_178 ( V_7 , V_345 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_198 ( struct V_386 * V_387 ,
struct V_2 * V_3 )
{
struct V_385 * V_388 = F_190 ( V_3 , V_387 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_20 ;
if ( F_23 ( V_388 ) )
return F_24 ( V_388 ) ;
V_20 = F_193 ( V_387 , V_3 ) ;
if ( V_20 && ! -- V_388 -> V_394 )
F_142 ( V_77 -> V_7 ) ;
return V_20 ;
}
static void F_199 ( struct V_94 * V_95 )
{
struct V_6 * V_7 = F_2 ( V_95 ,
struct V_6 , V_412 ) ;
F_122 ( V_7 ) ;
}
static int F_200 ( struct V_2 * V_3 ,
unsigned V_308 , unsigned V_413 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
int V_20 = 0 , V_414 ;
if ( V_413 != ( unsigned ) - 1 ) {
V_414 = F_46 ( V_77 , V_308 ) ;
if ( F_12 ( V_414 < 0 ) )
return V_414 ;
}
if ( V_7 -> V_77 )
F_147 ( V_7 -> V_77 ) ;
if ( V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_60 ( & V_7 -> V_412 , F_199 ) ;
F_61 ( & V_7 -> V_412 ) ;
return - V_78 ;
}
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
if ( V_413 == ( unsigned ) - 1 ) {
V_7 -> V_77 = NULL ;
F_178 ( V_7 , V_347 ) ;
return 0 ;
}
V_7 -> V_77 = V_77 ;
V_20 = F_151 ( V_77 ) ;
if ( F_39 ( V_20 >= 0 ) )
F_178 ( V_7 , V_348 ) ;
return V_20 ;
}
static void F_201 ( struct V_2 * V_3 )
{
F_200 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_202 ( struct V_2 * V_3 ,
const struct V_415 * V_416 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
unsigned long V_199 ;
int V_20 ;
F_20 () ;
F_16 ( L_57 , V_416 -> V_53 ) ;
F_16 ( L_58 , V_416 -> V_417 ) ;
F_16 ( L_59 , F_8 ( V_416 -> V_418 ) ) ;
F_16 ( L_60 , F_8 ( V_416 -> V_293 ) ) ;
F_16 ( L_61 , F_8 ( V_416 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
switch ( V_416 -> V_53 & V_419 ) {
case V_420 :
V_20 = F_46 ( V_77 , F_8 ( V_416 -> V_293 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_421 :
V_20 = F_203 ( V_77 , F_8 ( V_416 -> V_293 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_77 -> V_7 -> V_231 & V_232 )
V_20 = V_77 -> V_7 -> V_233 [ V_20 ] ;
break;
default:
if ( V_77 -> V_7 -> V_231 & V_326 )
V_20 = F_8 ( V_416 -> V_293 ) ;
else
return - V_422 ;
}
F_148 ( & V_7 -> V_22 . V_25 . V_26 , V_199 ) ;
V_7 -> V_22 . V_23 = * V_416 ;
V_7 -> V_22 . V_23 . V_293 = F_204 ( V_20 ) ;
F_176 ( V_7 , V_62 ) ;
F_150 ( & V_7 -> V_22 . V_25 . V_26 , V_199 ) ;
return 0 ;
}
static bool F_205 ( struct V_2 * V_3 ,
const struct V_415 * V_416 ,
bool V_423 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
if ( V_423 && ! ( V_77 -> V_7 -> V_231 & V_327 ) )
return false ;
switch ( V_416 -> V_53 & V_419 ) {
case V_420 :
return ( F_46 ( V_77 ,
F_8 ( V_416 -> V_293 ) ) >= 0 ) ;
case V_421 :
return ( F_203 ( V_77 ,
F_8 ( V_416 -> V_293 ) ) >= 0 ) ;
default:
return ( bool ) ( V_77 -> V_7 -> V_231 &
V_326 ) ;
}
}
static void F_206 ( struct V_2 * V_3 )
{
F_20 () ;
F_178 ( F_1 ( V_3 ) -> V_7 , V_344 ) ;
}
static void F_207 ( struct V_2 * V_3 )
{
F_20 () ;
F_178 ( F_1 ( V_3 ) -> V_7 , V_343 ) ;
}
static int F_203 ( struct V_1 * V_77 , T_8 V_137 )
{
V_137 = V_77 -> V_361 [ V_137 & V_358 ] ;
return V_137 ? V_137 : - V_424 ;
}
static int F_46 ( struct V_1 * V_77 , T_8 V_414 )
{
short * V_425 = V_77 -> V_363 ;
unsigned V_64 = V_77 -> V_7 -> V_219 ;
for (; V_64 ; -- V_64 , ++ V_425 ) {
if ( * V_425 >= 0 && * V_425 == V_414 )
return V_425 - V_77 -> V_363 ;
}
return - V_424 ;
}
static struct V_204 * F_208 ( const char * V_170 )
{
struct V_204 * V_392 ;
if ( ! V_170 )
return NULL ;
F_209 (dev, &ffs_devices, entry) {
if ( strcmp ( V_392 -> V_170 , V_170 ) == 0 )
return V_392 ;
}
return NULL ;
}
static struct V_204 * F_210 ( void )
{
struct V_204 * V_392 ;
if ( F_211 ( & V_426 ) ) {
V_392 = F_212 ( & V_426 , struct V_204 , V_384 ) ;
if ( V_392 -> V_427 )
return V_392 ;
}
return NULL ;
}
static struct V_204 * F_213 ( const char * V_170 )
{
struct V_204 * V_392 ;
V_392 = F_210 () ;
if ( V_392 )
return V_392 ;
return F_208 ( V_170 ) ;
}
static inline struct V_385 * F_214 ( struct V_428 * V_429 )
{
return F_2 ( F_215 ( V_429 ) , struct V_385 ,
V_390 . V_430 ) ;
}
static void F_216 ( struct V_428 * V_429 )
{
struct V_385 * V_190 = F_214 ( V_429 ) ;
F_217 ( & V_190 -> V_390 ) ;
}
static void F_218 ( struct V_431 * V_3 )
{
struct V_385 * V_190 ;
V_190 = F_219 ( V_3 ) ;
F_191 () ;
F_220 ( V_190 -> V_392 ) ;
F_192 () ;
F_33 ( V_190 ) ;
}
static int F_221 ( struct V_431 * V_389 , const char * V_170 )
{
if ( strlen ( V_170 ) >= F_222 ( struct V_204 , V_170 ) )
return - V_432 ;
return F_223 ( F_219 ( V_389 ) -> V_392 , V_170 ) ;
}
static struct V_431 * F_224 ( void )
{
struct V_385 * V_190 ;
struct V_204 * V_392 ;
V_190 = F_130 ( sizeof( * V_190 ) , V_68 ) ;
if ( ! V_190 )
return F_105 ( - V_69 ) ;
V_190 -> V_390 . V_433 = F_221 ;
V_190 -> V_390 . V_434 = F_218 ;
F_191 () ;
V_392 = F_225 () ;
F_192 () ;
if ( F_23 ( V_392 ) ) {
F_33 ( V_190 ) ;
return F_110 ( V_392 ) ;
}
V_190 -> V_392 = V_392 ;
V_392 -> V_190 = V_190 ;
F_226 ( & V_190 -> V_390 . V_430 , L_62 ,
& V_435 ) ;
return & V_190 -> V_390 ;
}
static void F_227 ( struct V_2 * V_3 )
{
F_33 ( F_1 ( V_3 ) ) ;
}
static void F_228 ( struct V_386 * V_387 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_385 * V_190 =
F_2 ( V_3 -> V_389 , struct V_385 , V_390 ) ;
struct V_89 * V_12 = V_77 -> V_235 ;
unsigned V_64 = V_7 -> V_209 ;
unsigned long V_199 ;
F_20 () ;
if ( V_7 -> V_77 == V_77 ) {
F_147 ( V_77 ) ;
V_7 -> V_77 = NULL ;
}
if ( ! -- V_190 -> V_394 )
F_142 ( V_7 ) ;
F_148 ( & V_77 -> V_7 -> V_118 , V_199 ) ;
while ( V_64 -- ) {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_58 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
}
F_150 ( & V_77 -> V_7 -> V_118 , V_199 ) ;
F_33 ( V_77 -> V_235 ) ;
V_77 -> V_235 = NULL ;
V_77 -> V_4 . V_357 = NULL ;
V_77 -> V_4 . V_356 = NULL ;
V_77 -> V_4 . V_355 = NULL ;
V_77 -> V_363 = NULL ;
F_178 ( V_7 , V_346 ) ;
}
static struct V_2 * F_229 ( struct V_431 * V_389 )
{
struct V_1 * V_77 ;
F_20 () ;
V_77 = F_130 ( sizeof( * V_77 ) , V_68 ) ;
if ( F_12 ( ! V_77 ) )
return F_105 ( - V_69 ) ;
V_77 -> V_4 . V_170 = L_63 ;
V_77 -> V_4 . V_436 = F_198 ;
V_77 -> V_4 . V_437 = F_228 ;
V_77 -> V_4 . V_438 = F_200 ;
V_77 -> V_4 . V_439 = F_201 ;
V_77 -> V_4 . V_23 = F_202 ;
V_77 -> V_4 . V_440 = F_205 ;
V_77 -> V_4 . V_441 = F_206 ;
V_77 -> V_4 . V_442 = F_207 ;
V_77 -> V_4 . V_443 = F_227 ;
return & V_77 -> V_4 ;
}
static struct V_204 * F_225 ( void )
{
struct V_204 * V_392 ;
int V_20 ;
if ( F_210 () )
return F_105 ( - V_72 ) ;
V_392 = F_130 ( sizeof( * V_392 ) , V_68 ) ;
if ( ! V_392 )
return F_105 ( - V_69 ) ;
if ( F_230 ( & V_426 ) ) {
V_20 = F_115 () ;
if ( V_20 ) {
F_33 ( V_392 ) ;
return F_105 ( V_20 ) ;
}
}
F_231 ( & V_392 -> V_384 , & V_426 ) ;
return V_392 ;
}
int F_223 ( struct V_204 * V_392 , const char * V_170 )
{
struct V_204 * V_444 ;
int V_20 = 0 ;
F_191 () ;
V_444 = F_208 ( V_170 ) ;
if ( ! V_444 )
F_232 ( V_392 -> V_170 , V_170 , F_35 ( V_392 -> V_170 ) ) ;
else if ( V_444 != V_392 )
V_20 = - V_72 ;
F_192 () ;
return V_20 ;
}
int F_233 ( struct V_204 * V_392 )
{
int V_20 ;
V_20 = 0 ;
F_191 () ;
if ( ! F_211 ( & V_426 ) )
V_20 = - V_72 ;
else
V_392 -> V_427 = true ;
F_192 () ;
return V_20 ;
}
static void F_220 ( struct V_204 * V_392 )
{
F_234 ( & V_392 -> V_384 ) ;
if ( V_392 -> V_6 )
V_392 -> V_6 -> V_40 = NULL ;
F_33 ( V_392 ) ;
if ( F_230 ( & V_426 ) )
F_117 () ;
}
static void * F_109 ( const char * V_200 )
{
struct V_204 * V_204 ;
F_20 () ;
F_191 () ;
V_204 = F_213 ( V_200 ) ;
if ( ! V_204 )
V_204 = F_105 ( - V_351 ) ;
else if ( V_204 -> V_445 )
V_204 = F_105 ( - V_72 ) ;
else if ( V_204 -> V_446 &&
V_204 -> V_446 ( V_204 ) )
V_204 = F_105 ( - V_351 ) ;
else
V_204 -> V_445 = true ;
F_192 () ;
return V_204 ;
}
static void F_112 ( struct V_6 * V_6 )
{
struct V_204 * V_204 ;
F_20 () ;
F_191 () ;
V_204 = V_6 -> V_40 ;
if ( V_204 ) {
V_204 -> V_445 = false ;
if ( V_204 -> V_447 )
V_204 -> V_447 ( V_204 ) ;
}
F_192 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_204 * V_448 ;
int V_20 = 0 ;
F_20 () ;
F_191 () ;
V_448 = V_7 -> V_40 ;
if ( ! V_448 ) {
V_20 = - V_48 ;
goto V_123;
}
if ( F_68 ( V_448 -> V_393 ) ) {
V_20 = - V_72 ;
goto V_123;
}
V_448 -> V_393 = true ;
V_448 -> V_6 = V_7 ;
if ( V_448 -> V_449 ) {
V_20 = V_448 -> V_449 ( V_7 ) ;
if ( V_20 )
goto V_123;
}
F_235 ( V_450 , & V_7 -> V_199 ) ;
V_123:
F_192 () ;
return V_20 ;
}
static void F_137 ( struct V_6 * V_7 )
{
struct V_204 * V_448 ;
struct V_385 * V_190 ;
struct V_428 * V_451 ;
F_20 () ;
F_191 () ;
V_448 = V_7 -> V_40 ;
if ( ! V_448 )
goto V_123;
V_448 -> V_393 = false ;
if ( F_236 ( V_450 , & V_7 -> V_199 ) &&
V_448 -> V_452 )
V_448 -> V_452 ( V_7 ) ;
if ( V_448 -> V_190 )
V_190 = V_448 -> V_190 ;
else
goto V_123;
if ( V_190 -> V_391 || ! V_190 -> V_390 . V_430 . V_453 . V_454
|| ! F_237 ( & V_190 -> V_390 . V_430 . V_453 . V_455 ) )
goto V_123;
V_451 = V_190 -> V_390 . V_430 . V_453 . V_454 -> V_454 ;
F_192 () ;
F_238 ( V_451 ) ;
return;
V_123:
F_192 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_456 )
{
return V_456
? F_39 ( F_239 ( V_42 ) ) ? 0 : - V_67
: F_240 ( V_42 ) ;
}
static char * F_22 ( const char T_3 * V_27 , T_1 V_18 )
{
char * V_17 ;
if ( F_12 ( ! V_18 ) )
return NULL ;
V_17 = F_40 ( V_18 , V_68 ) ;
if ( F_12 ( ! V_17 ) )
return F_105 ( - V_69 ) ;
if ( F_12 ( F_241 ( V_17 , V_27 , V_18 ) ) ) {
F_33 ( V_17 ) ;
return F_105 ( - V_65 ) ;
}
F_16 ( L_64 ) ;
F_181 ( L_62 , V_17 , V_18 ) ;
return V_17 ;
}
