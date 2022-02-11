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
struct V_6 * V_7 = V_97 -> V_7 ;
F_20 () ;
F_60 ( & V_97 -> V_95 , F_54 ) ;
F_61 ( V_7 -> V_107 , & V_97 -> V_95 ) ;
}
static void F_62 ( struct V_108 * V_109 )
{
struct V_110 * V_27 = F_63 ( & V_109 -> V_111 , V_112 ) ;
if ( V_27 && V_27 != V_112 )
F_33 ( V_27 ) ;
}
static T_2 F_64 ( struct V_108 * V_109 ,
struct V_92 * V_93 )
{
struct V_110 * V_27 = F_63 ( & V_109 -> V_111 , NULL ) ;
T_2 V_20 ;
if ( ! V_27 || V_27 == V_112 )
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
if ( F_4 ( & V_109 -> V_111 , NULL , V_27 ) )
F_33 ( V_27 ) ;
return V_20 ;
}
static T_2 F_65 ( struct V_108 * V_109 ,
void * V_17 , int V_91 ,
struct V_92 * V_93 )
{
struct V_110 * V_27 ;
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
V_27 -> V_17 = V_27 -> V_113 ;
memcpy ( V_27 -> V_113 , V_17 + V_20 , V_91 ) ;
if ( F_12 ( F_4 ( & V_109 -> V_111 , NULL , V_27 ) ) )
F_33 ( V_27 ) ;
return V_20 ;
}
static T_2 F_67 ( struct V_38 * V_38 , struct V_96 * V_97 )
{
struct V_108 * V_109 = V_38 -> V_40 ;
struct V_13 * V_14 ;
struct V_89 * V_12 ;
char * V_17 = NULL ;
T_2 V_20 , V_91 = - V_48 ;
int V_114 ;
if ( F_68 ( V_109 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_12 = V_109 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 )
return - V_67 ;
V_20 = F_69 (
V_109 -> V_7 -> V_82 , ( V_12 = V_109 -> V_12 ) ) ;
if ( V_20 )
return - V_32 ;
}
V_114 = ( ! V_97 -> V_102 == ! V_109 -> V_115 ) ;
if ( V_114 && V_109 -> V_116 )
return - V_48 ;
V_20 = F_21 ( & V_109 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 ) )
goto error;
if ( ! V_114 ) {
struct V_75 * V_29 ;
if ( ! V_97 -> V_117 && V_97 -> V_102 ) {
V_20 = F_64 ( V_109 , & V_97 -> V_17 ) ;
if ( V_20 )
goto V_118;
}
V_29 = V_109 -> V_7 -> V_29 ;
F_31 ( & V_109 -> V_7 -> V_119 ) ;
if ( V_109 -> V_12 != V_12 ) {
V_20 = - V_120 ;
goto V_121;
}
V_91 = F_52 ( & V_97 -> V_17 ) ;
if ( V_97 -> V_102 )
V_91 = F_70 ( V_29 , V_12 -> V_12 , V_91 ) ;
F_9 ( & V_109 -> V_7 -> V_119 ) ;
V_17 = F_40 ( V_91 , V_68 ) ;
if ( F_12 ( ! V_17 ) ) {
V_20 = - V_69 ;
goto V_118;
}
if ( ! V_97 -> V_102 &&
! F_71 ( V_17 , V_91 , & V_97 -> V_17 ) ) {
V_20 = - V_65 ;
goto V_118;
}
}
F_31 ( & V_109 -> V_7 -> V_119 ) ;
if ( V_109 -> V_12 != V_12 ) {
V_20 = - V_120 ;
} else if ( V_114 ) {
V_20 = F_17 ( V_12 -> V_12 ) ;
if ( ! V_20 )
V_20 = - V_122 ;
} else if ( F_12 ( V_91 == - V_48 ) ) {
F_72 ( 1 , L_8 , V_123 ) ;
V_20 = - V_48 ;
} else if ( ! V_97 -> V_117 ) {
F_73 ( V_124 ) ;
bool V_125 = false ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_91 ;
V_14 -> V_15 = & V_124 ;
V_14 -> F_6 = F_49 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 < 0 ) )
goto V_121;
F_9 ( & V_109 -> V_7 -> V_119 ) ;
if ( F_12 ( F_13 ( & V_124 ) ) ) {
F_14 ( V_12 -> V_12 , V_14 ) ;
V_125 = V_12 -> V_33 < 0 ;
}
if ( V_125 )
V_20 = - V_32 ;
else if ( V_97 -> V_102 && V_12 -> V_33 > 0 )
V_20 = F_65 ( V_109 , V_17 , V_12 -> V_33 ,
& V_97 -> V_17 ) ;
else
V_20 = V_12 -> V_33 ;
goto V_118;
} else if ( ! ( V_14 = F_74 ( V_12 -> V_12 , V_68 ) ) ) {
V_20 = - V_69 ;
} else {
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_91 ;
V_97 -> V_27 = V_17 ;
V_97 -> V_12 = V_12 -> V_12 ;
V_97 -> V_14 = V_14 ;
V_97 -> V_7 = V_109 -> V_7 ;
V_14 -> V_15 = V_97 ;
V_14 -> F_6 = F_59 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 ) ) {
F_58 ( V_12 -> V_12 , V_14 ) ;
goto V_121;
}
V_20 = - V_126 ;
V_17 = NULL ;
}
V_121:
F_9 ( & V_109 -> V_7 -> V_119 ) ;
V_118:
F_29 ( & V_109 -> V_42 ) ;
error:
F_33 ( V_17 ) ;
return V_20 ;
}
static int
F_75 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_108 * V_109 = V_70 -> V_71 ;
F_20 () ;
if ( F_68 ( V_109 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_38 -> V_40 = V_109 ;
F_42 ( V_109 -> V_7 ) ;
return 0 ;
}
static int F_76 ( struct V_99 * V_99 )
{
struct V_96 * V_97 = V_99 -> V_127 ;
struct V_108 * V_109 = V_99 -> V_128 -> V_40 ;
int V_74 ;
F_20 () ;
F_31 ( & V_109 -> V_7 -> V_119 ) ;
if ( F_39 ( V_97 && V_97 -> V_12 && V_97 -> V_14 ) )
V_74 = F_14 ( V_97 -> V_12 , V_97 -> V_14 ) ;
else
V_74 = - V_48 ;
F_9 ( & V_109 -> V_7 -> V_119 ) ;
return V_74 ;
}
static T_2 F_77 ( struct V_99 * V_99 , struct V_92 * V_129 )
{
struct V_96 V_97 , * V_130 = & V_97 ;
T_2 V_131 ;
F_20 () ;
if ( ! F_78 ( V_99 ) ) {
V_130 = F_40 ( sizeof( V_97 ) , V_68 ) ;
if ( F_12 ( ! V_130 ) )
return - V_69 ;
V_130 -> V_117 = true ;
} else {
V_130 -> V_117 = false ;
}
V_130 -> V_102 = false ;
V_130 -> V_99 = V_99 ;
V_130 -> V_17 = * V_129 ;
V_130 -> V_103 = V_132 -> V_103 ;
V_99 -> V_127 = V_130 ;
if ( V_130 -> V_117 )
F_79 ( V_99 , F_76 ) ;
V_131 = F_67 ( V_99 -> V_128 , V_130 ) ;
if ( V_131 == - V_126 )
return V_131 ;
if ( V_130 -> V_117 )
F_33 ( V_130 ) ;
else
* V_129 = V_130 -> V_17 ;
return V_131 ;
}
static T_2 F_80 ( struct V_99 * V_99 , struct V_92 * V_133 )
{
struct V_96 V_97 , * V_130 = & V_97 ;
T_2 V_131 ;
F_20 () ;
if ( ! F_78 ( V_99 ) ) {
V_130 = F_40 ( sizeof( V_97 ) , V_68 ) ;
if ( F_12 ( ! V_130 ) )
return - V_69 ;
V_130 -> V_117 = true ;
} else {
V_130 -> V_117 = false ;
}
V_130 -> V_102 = true ;
V_130 -> V_99 = V_99 ;
if ( V_130 -> V_117 ) {
V_130 -> V_106 = F_81 ( & V_130 -> V_17 , V_133 , V_68 ) ;
if ( ! V_130 -> V_106 ) {
F_33 ( V_130 ) ;
return - V_69 ;
}
} else {
V_130 -> V_17 = * V_133 ;
V_130 -> V_106 = NULL ;
}
V_130 -> V_103 = V_132 -> V_103 ;
V_99 -> V_127 = V_130 ;
if ( V_130 -> V_117 )
F_79 ( V_99 , F_76 ) ;
V_131 = F_67 ( V_99 -> V_128 , V_130 ) ;
if ( V_131 == - V_126 )
return V_131 ;
if ( V_130 -> V_117 ) {
F_33 ( V_130 -> V_106 ) ;
F_33 ( V_130 ) ;
} else {
* V_133 = V_130 -> V_17 ;
}
return V_131 ;
}
static int
F_82 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_108 * V_109 = V_70 -> V_71 ;
F_20 () ;
F_62 ( V_109 ) ;
F_44 ( V_109 -> V_7 ) ;
return 0 ;
}
static long F_83 ( struct V_38 * V_38 , unsigned V_73 ,
unsigned long V_74 )
{
struct V_108 * V_109 = V_38 -> V_40 ;
struct V_89 * V_12 ;
int V_20 ;
F_20 () ;
if ( F_68 ( V_109 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_12 = V_109 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 )
return - V_67 ;
V_20 = F_69 (
V_109 -> V_7 -> V_82 , ( V_12 = V_109 -> V_12 ) ) ;
if ( V_20 )
return - V_32 ;
}
F_31 ( & V_109 -> V_7 -> V_119 ) ;
if ( V_109 -> V_12 != V_12 ) {
F_9 ( & V_109 -> V_7 -> V_119 ) ;
return - V_120 ;
}
switch ( V_73 ) {
case V_134 :
V_20 = F_84 ( V_109 -> V_12 -> V_12 ) ;
break;
case V_135 :
F_85 ( V_109 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_136 :
V_20 = F_86 ( V_109 -> V_12 -> V_12 ) ;
break;
case V_137 :
V_20 = V_109 -> V_12 -> V_138 ;
break;
case V_139 :
{
int V_140 ;
struct V_141 * V_142 ;
switch ( V_109 -> V_7 -> V_29 -> V_143 ) {
case V_144 :
V_140 = 2 ;
break;
case V_145 :
V_140 = 1 ;
break;
default:
V_140 = 0 ;
}
V_142 = V_109 -> V_12 -> V_146 [ V_140 ] ;
F_9 ( & V_109 -> V_7 -> V_119 ) ;
V_20 = F_36 ( ( void * ) V_74 , V_142 , V_142 -> V_147 ) ;
if ( V_20 )
V_20 = - V_65 ;
return V_20 ;
}
default:
V_20 = - V_81 ;
}
F_9 ( & V_109 -> V_7 -> V_119 ) ;
return V_20 ;
}
static struct V_70 * T_6
F_87 ( struct V_148 * V_149 , void * V_17 ,
const struct V_150 * V_151 ,
const struct V_152 * V_153 ,
struct V_154 * V_155 )
{
struct V_70 * V_70 ;
F_20 () ;
V_70 = F_88 ( V_149 ) ;
if ( F_39 ( V_70 ) ) {
struct V_156 V_157 = F_89 ( V_70 ) ;
V_70 -> V_158 = F_90 () ;
V_70 -> V_159 = V_155 -> V_160 ;
V_70 -> V_161 = V_155 -> V_162 ;
V_70 -> V_163 = V_155 -> V_164 ;
V_70 -> V_165 = V_157 ;
V_70 -> V_166 = V_157 ;
V_70 -> V_167 = V_157 ;
V_70 -> V_71 = V_17 ;
if ( V_151 )
V_70 -> V_168 = V_151 ;
if ( V_153 )
V_70 -> V_169 = V_153 ;
}
return V_70 ;
}
static struct V_170 * F_91 ( struct V_148 * V_149 ,
const char * V_171 , void * V_17 ,
const struct V_150 * V_151 )
{
struct V_6 * V_7 = V_149 -> V_172 ;
struct V_170 * V_170 ;
struct V_70 * V_70 ;
F_20 () ;
V_170 = F_92 ( V_149 -> V_173 , V_171 ) ;
if ( F_12 ( ! V_170 ) )
return NULL ;
V_70 = F_87 ( V_149 , V_17 , V_151 , NULL , & V_7 -> V_174 ) ;
if ( F_12 ( ! V_70 ) ) {
F_93 ( V_170 ) ;
return NULL ;
}
F_94 ( V_170 , V_70 ) ;
return V_170 ;
}
static int F_95 ( struct V_148 * V_149 , void * V_175 , int V_176 )
{
struct V_177 * V_17 = V_175 ;
struct V_70 * V_70 ;
struct V_6 * V_7 = V_17 -> V_6 ;
F_20 () ;
V_7 -> V_149 = V_149 ;
V_17 -> V_6 = NULL ;
V_149 -> V_172 = V_7 ;
V_149 -> V_178 = V_179 ;
V_149 -> V_180 = V_181 ;
V_149 -> V_182 = V_183 ;
V_149 -> V_184 = & V_185 ;
V_149 -> V_186 = 1 ;
V_17 -> V_155 . V_160 = V_17 -> V_187 ;
V_70 = F_87 ( V_149 , NULL ,
& V_188 ,
& V_189 ,
& V_17 -> V_155 ) ;
V_149 -> V_173 = F_96 ( V_70 ) ;
if ( F_12 ( ! V_149 -> V_173 ) )
return - V_69 ;
if ( F_12 ( ! F_91 ( V_149 , L_9 , V_7 ,
& V_190 ) ) )
return - V_69 ;
return 0 ;
}
static int F_97 ( struct V_177 * V_17 , char * V_191 )
{
F_20 () ;
if ( ! V_191 || ! * V_191 )
return 0 ;
for (; ; ) {
unsigned long V_74 ;
char * V_192 , * V_193 ;
V_193 = strchr ( V_191 , ',' ) ;
if ( V_193 )
* V_193 = 0 ;
V_192 = strchr ( V_191 , '=' ) ;
if ( F_12 ( ! V_192 ) ) {
F_53 ( L_10 , V_191 ) ;
return - V_48 ;
}
* V_192 = 0 ;
if ( F_98 ( V_192 + 1 , 0 , & V_74 ) ) {
F_53 ( L_11 , V_191 , V_192 + 1 ) ;
return - V_48 ;
}
switch ( V_192 - V_191 ) {
case 13 :
if ( ! memcmp ( V_191 , L_12 , 13 ) )
V_17 -> V_194 = ! ! V_74 ;
else
goto V_195;
break;
case 5 :
if ( ! memcmp ( V_191 , L_13 , 5 ) )
V_17 -> V_187 = ( V_74 & 0555 ) | V_196 ;
else if ( ! memcmp ( V_191 , L_14 , 5 ) )
V_17 -> V_155 . V_160 = ( V_74 & 0666 ) | V_197 ;
else
goto V_195;
break;
case 4 :
if ( ! memcmp ( V_191 , L_15 , 4 ) ) {
V_17 -> V_187 = ( V_74 & 0555 ) | V_196 ;
V_17 -> V_155 . V_160 = ( V_74 & 0666 ) | V_197 ;
} else {
goto V_195;
}
break;
case 3 :
if ( ! memcmp ( V_191 , L_16 , 3 ) ) {
V_17 -> V_155 . V_162 = F_99 ( F_100 () , V_74 ) ;
if ( ! F_101 ( V_17 -> V_155 . V_162 ) ) {
F_53 ( L_17 , V_191 , V_74 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_191 , L_18 , 3 ) ) {
V_17 -> V_155 . V_164 = F_102 ( F_100 () , V_74 ) ;
if ( ! F_103 ( V_17 -> V_155 . V_164 ) ) {
F_53 ( L_17 , V_191 , V_74 ) ;
return - V_48 ;
}
} else {
goto V_195;
}
break;
default:
V_195:
F_53 ( L_19 , V_191 ) ;
return - V_48 ;
}
if ( ! V_193 )
break;
V_191 = V_193 + 1 ;
}
return 0 ;
}
static struct V_170 *
F_104 ( struct V_198 * V_199 , int V_200 ,
const char * V_201 , void * V_191 )
{
struct V_177 V_17 = {
. V_155 = {
. V_160 = V_197 | 0600 ,
. V_162 = V_202 ,
. V_164 = V_203 ,
} ,
. V_187 = V_196 | 0500 ,
. V_194 = false ,
} ;
struct V_170 * V_204 ;
int V_20 ;
void * V_205 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_97 ( & V_17 , V_191 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_105 ( V_20 ) ;
V_7 = F_106 ( V_201 ) ;
if ( F_12 ( ! V_7 ) )
return F_105 ( - V_69 ) ;
V_7 -> V_174 = V_17 . V_155 ;
V_7 -> V_194 = V_17 . V_194 ;
V_7 -> V_201 = F_107 ( V_201 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_201 ) ) {
F_108 ( V_7 ) ;
return F_105 ( - V_69 ) ;
}
V_205 = F_109 ( V_201 ) ;
if ( F_23 ( V_205 ) ) {
F_108 ( V_7 ) ;
return F_110 ( V_205 ) ;
}
V_7 -> V_40 = V_205 ;
V_17 . V_6 = V_7 ;
V_204 = F_111 ( V_199 , V_200 , & V_17 , F_95 ) ;
if ( F_23 ( V_204 ) && V_17 . V_6 ) {
F_112 ( V_17 . V_6 ) ;
F_108 ( V_17 . V_6 ) ;
}
return V_204 ;
}
static void
F_113 ( struct V_148 * V_149 )
{
F_20 () ;
F_114 ( V_149 ) ;
if ( V_149 -> V_172 ) {
F_112 ( V_149 -> V_172 ) ;
F_44 ( V_149 -> V_172 ) ;
F_108 ( V_149 -> V_172 ) ;
}
}
static int F_115 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_116 ( & V_206 ) ;
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
F_118 ( & V_206 ) ;
}
static void F_119 ( struct V_6 * V_7 )
{
F_20 () ;
F_120 ( & V_7 -> V_207 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_20 () ;
F_120 ( & V_7 -> V_207 ) ;
if ( F_121 ( 1 , & V_7 -> V_208 ) == 1 &&
V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_122 ( V_7 ) ;
}
}
static void F_108 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_123 ( & V_7 -> V_207 ) ) ) {
F_25 ( L_23 , V_123 ) ;
F_124 ( V_7 ) ;
F_125 ( F_126 ( & V_7 -> V_22 . V_25 ) ||
F_126 ( & V_7 -> V_16 . V_82 ) ||
F_126 ( & V_7 -> V_82 ) ) ;
F_127 ( V_7 -> V_107 ) ;
F_33 ( V_7 -> V_201 ) ;
F_33 ( V_7 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_128 ( & V_7 -> V_208 ) ) {
if ( V_7 -> V_194 ) {
V_7 -> V_45 = V_87 ;
if ( V_7 -> V_209 ) {
F_129 ( V_7 -> V_209 ,
V_7 -> V_210 ) ;
V_7 -> V_209 = NULL ;
}
if ( V_7 -> V_8 == V_52 )
F_15 ( V_7 ) ;
} else {
V_7 -> V_45 = V_49 ;
F_122 ( V_7 ) ;
}
}
if ( F_130 ( & V_7 -> V_208 ) < 0 ) {
V_7 -> V_45 = V_49 ;
F_122 ( V_7 ) ;
}
F_108 ( V_7 ) ;
}
static struct V_6 * F_106 ( const char * V_201 )
{
struct V_6 * V_7 = F_131 ( sizeof *V_7 , V_68 ) ;
if ( F_12 ( ! V_7 ) )
return NULL ;
F_20 () ;
V_7 -> V_107 = F_132 ( L_24 , 0 , V_201 ) ;
if ( ! V_7 -> V_107 ) {
F_33 ( V_7 ) ;
return NULL ;
}
F_133 ( & V_7 -> V_207 , 1 ) ;
F_134 ( & V_7 -> V_208 , 0 ) ;
V_7 -> V_45 = V_46 ;
F_135 ( & V_7 -> V_42 ) ;
F_136 ( & V_7 -> V_119 ) ;
F_137 ( & V_7 -> V_22 . V_25 ) ;
F_137 ( & V_7 -> V_82 ) ;
F_138 ( & V_7 -> V_16 ) ;
V_7 -> V_22 . V_35 = 1 ;
return V_7 ;
}
static void F_124 ( struct V_6 * V_7 )
{
F_20 () ;
F_139 ( V_7 ) ;
F_125 ( V_7 -> V_29 ) ;
if ( V_7 -> V_209 )
F_129 ( V_7 -> V_209 , V_7 -> V_210 ) ;
if ( V_7 -> V_105 )
F_140 ( V_7 -> V_105 ) ;
F_33 ( V_7 -> V_211 ) ;
F_33 ( V_7 -> V_212 ) ;
F_33 ( V_7 -> V_213 ) ;
}
static void F_122 ( struct V_6 * V_7 )
{
F_20 () ;
F_124 ( V_7 ) ;
V_7 -> V_209 = NULL ;
V_7 -> V_211 = NULL ;
V_7 -> V_214 = NULL ;
V_7 -> V_212 = NULL ;
V_7 -> V_213 = NULL ;
V_7 -> V_215 = 0 ;
V_7 -> V_216 = 0 ;
V_7 -> V_217 = 0 ;
V_7 -> V_218 = 0 ;
V_7 -> V_219 = 0 ;
V_7 -> V_220 = 0 ;
V_7 -> V_210 = 0 ;
V_7 -> V_22 . V_64 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_200 = 0 ;
}
static int F_141 ( struct V_6 * V_7 , struct V_221 * V_222 )
{
struct V_223 * * V_224 ;
int V_225 ;
F_20 () ;
if ( F_68 ( V_7 -> V_45 != V_50
|| F_142 ( V_226 , & V_7 -> V_200 ) ) )
return - V_55 ;
V_225 = F_143 ( V_222 , V_7 -> V_219 ) ;
if ( F_12 ( V_225 < 0 ) )
return V_225 ;
V_7 -> V_19 = F_74 ( V_222 -> V_29 -> V_30 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_69 ;
V_7 -> V_19 -> F_6 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_224 = V_7 -> V_213 ;
if ( V_224 ) {
for (; * V_224 ; ++ V_224 ) {
struct V_227 * V_228 = ( * V_224 ) -> V_229 ;
int V_230 = V_225 ;
for (; V_228 -> V_231 ; ++ V_230 , ++ V_228 )
V_228 -> V_230 = V_230 ;
}
}
V_7 -> V_29 = V_222 -> V_29 ;
F_119 ( V_7 ) ;
return 0 ;
}
static void F_144 ( struct V_6 * V_7 )
{
F_20 () ;
if ( ! F_68 ( ! V_7 -> V_29 ) ) {
F_58 ( V_7 -> V_29 -> V_30 , V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_29 = NULL ;
F_145 ( V_226 , & V_7 -> V_200 ) ;
F_108 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_108 * V_109 , * V_209 ;
unsigned V_61 , V_64 ;
F_20 () ;
V_64 = V_7 -> V_210 ;
V_209 = F_146 ( V_64 , sizeof( * V_209 ) , V_68 ) ;
if ( ! V_209 )
return - V_69 ;
V_109 = V_209 ;
for ( V_61 = 1 ; V_61 <= V_64 ; ++ V_61 , ++ V_109 ) {
V_109 -> V_7 = V_7 ;
F_135 ( & V_109 -> V_42 ) ;
if ( V_7 -> V_232 & V_233 )
sprintf ( V_109 -> V_171 , L_25 , V_7 -> V_234 [ V_61 ] ) ;
else
sprintf ( V_109 -> V_171 , L_26 , V_61 ) ;
V_109 -> V_170 = F_91 ( V_7 -> V_149 , V_109 -> V_171 ,
V_109 ,
& V_235 ) ;
if ( F_12 ( ! V_109 -> V_170 ) ) {
F_129 ( V_209 , V_61 - 1 ) ;
return - V_69 ;
}
}
V_7 -> V_209 = V_209 ;
return 0 ;
}
static void F_129 ( struct V_108 * V_209 , unsigned V_64 )
{
struct V_108 * V_109 = V_209 ;
F_20 () ;
for (; V_64 ; -- V_64 , ++ V_109 ) {
F_125 ( F_147 ( & V_109 -> V_42 ) ) ;
if ( V_109 -> V_170 ) {
F_148 ( V_109 -> V_170 ) ;
F_93 ( V_109 -> V_170 ) ;
V_109 -> V_170 = NULL ;
}
}
F_33 ( V_209 ) ;
}
static void F_149 ( struct V_1 * V_77 )
{
struct V_89 * V_12 = V_77 -> V_236 ;
struct V_108 * V_109 = V_77 -> V_7 -> V_209 ;
unsigned V_64 = V_77 -> V_7 -> V_210 ;
unsigned long V_200 ;
F_150 ( & V_77 -> V_7 -> V_119 , V_200 ) ;
while ( V_64 -- ) {
if ( F_39 ( V_12 -> V_12 ) )
F_151 ( V_12 -> V_12 ) ;
++ V_12 ;
if ( V_109 ) {
V_109 -> V_12 = NULL ;
F_62 ( V_109 ) ;
++ V_109 ;
}
}
F_152 ( & V_77 -> V_7 -> V_119 , V_200 ) ;
}
static int F_153 ( struct V_1 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_89 * V_12 = V_77 -> V_236 ;
struct V_108 * V_109 = V_7 -> V_209 ;
unsigned V_64 = V_7 -> V_210 ;
unsigned long V_200 ;
int V_20 = 0 ;
F_150 ( & V_77 -> V_7 -> V_119 , V_200 ) ;
while( V_64 -- ) {
struct V_141 * V_237 ;
struct V_238 * V_239 = NULL ;
int V_240 = false ;
int V_140 ;
if ( V_7 -> V_29 -> V_143 == V_144 ) {
V_140 = 2 ;
V_240 = true ;
} else if ( V_7 -> V_29 -> V_143 == V_145 )
V_140 = 1 ;
else
V_140 = 0 ;
do {
V_237 = V_12 -> V_146 [ V_140 ] ;
} while ( ! V_237 && -- V_140 >= 0 );
if ( ! V_237 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_90 = V_12 ;
V_12 -> V_12 -> V_142 = V_237 ;
if ( V_240 ) {
V_239 = (struct V_238 * ) ( V_237 +
V_241 ) ;
V_12 -> V_12 -> V_242 = V_239 -> V_243 + 1 ;
V_12 -> V_12 -> V_239 = V_239 ;
}
V_20 = F_154 ( V_12 -> V_12 ) ;
if ( F_39 ( ! V_20 ) ) {
V_109 -> V_12 = V_12 ;
V_109 -> V_115 = F_155 ( V_237 ) ;
V_109 -> V_116 = F_156 ( V_237 ) ;
} else {
break;
}
++ V_12 ;
++ V_109 ;
}
F_157 ( & V_7 -> V_82 ) ;
F_152 ( & V_77 -> V_7 -> V_119 , V_200 ) ;
return V_20 ;
}
static int T_6 F_158 ( char * V_17 , unsigned V_18 ,
T_7 V_244 ,
void * V_245 )
{
struct V_246 * V_247 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_27 ) ;
return - V_48 ;
}
V_28 = V_247 -> V_147 ;
if ( V_18 < V_28 ) {
F_16 ( L_28 ) ;
return - V_48 ;
}
#define F_159 ( T_9 ) 1
#define F_160 ( T_9 ) (val)
#define F_161 ( T_9 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_162 ( type , T_9 ) do { \
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
switch ( V_247 -> V_248 ) {
case V_249 :
case V_250 :
case V_251 :
case V_252 :
F_16 ( L_29 ,
V_247 -> V_248 ) ;
return - V_48 ;
case V_253 : {
struct V_254 * V_237 = ( void * ) V_247 ;
F_16 ( L_30 ) ;
if ( V_28 != sizeof *V_237 )
goto V_255;
F_162 ( V_256 , V_237 -> V_257 ) ;
if ( V_237 -> V_258 )
F_162 ( STRING , V_237 -> V_258 ) ;
}
break;
case V_259 : {
struct V_141 * V_237 = ( void * ) V_247 ;
F_16 ( L_31 ) ;
if ( V_28 != V_241 &&
V_28 != V_260 )
goto V_255;
F_162 ( V_261 , V_237 -> V_262 ) ;
}
break;
case V_263 :
F_16 ( L_32 ) ;
if ( V_28 != sizeof( struct V_264 ) )
goto V_255;
break;
case V_265 :
if ( V_28 != sizeof( struct V_266 ) )
goto V_255;
break;
case V_267 : {
struct V_268 * V_237 = ( void * ) V_247 ;
F_16 ( L_33 ) ;
if ( V_28 != sizeof *V_237 )
goto V_255;
if ( V_237 -> V_269 )
F_162 ( STRING , V_237 -> V_269 ) ;
}
break;
case V_270 :
F_16 ( L_34 ) ;
if ( V_28 != sizeof( struct V_238 ) )
goto V_255;
break;
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
F_16 ( L_35 , V_247 -> V_248 ) ;
return - V_48 ;
default:
F_16 ( L_36 , V_247 -> V_248 ) ;
return - V_48 ;
V_255:
F_16 ( L_37 ,
V_247 -> V_147 , V_247 -> V_248 ) ;
return - V_48 ;
}
#undef F_162
#undef V_276
#undef F_159
#undef F_160
#undef F_161
return V_28 ;
}
static int T_6 F_163 ( unsigned V_64 , char * V_17 , unsigned V_18 ,
T_7 V_244 , void * V_245 )
{
const unsigned V_277 = V_18 ;
unsigned long V_138 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_138 == V_64 )
V_17 = NULL ;
V_20 = V_244 ( V_278 , ( T_8 * ) V_138 , ( void * ) V_17 , V_245 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 ,
V_138 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_277 - V_18 ;
V_20 = F_158 ( V_17 , V_18 , V_244 , V_245 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_39 , V_123 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_138 ;
}
}
static int F_164 ( enum V_279 type ,
T_8 * V_280 , struct V_246 * V_142 ,
void * V_245 )
{
struct V_281 * V_282 = V_245 ;
struct V_141 * V_283 ;
F_20 () ;
switch ( type ) {
case V_278 :
break;
case V_284 :
if ( * V_280 >= V_282 -> V_220 )
V_282 -> V_220 = * V_280 + 1 ;
break;
case V_285 :
if ( * V_280 > V_282 -> V_7 -> V_219 )
V_282 -> V_7 -> V_219 = * V_280 ;
break;
case V_286 :
V_283 = ( void * ) V_142 ;
V_282 -> V_210 ++ ;
if ( V_282 -> V_210 >= V_287 )
return - V_48 ;
if ( ! V_282 -> V_7 -> V_210 && ! V_282 -> V_7 -> V_220 )
V_282 -> V_7 -> V_234 [ V_282 -> V_210 ] =
V_283 -> V_262 ;
else if ( V_282 -> V_7 -> V_234 [ V_282 -> V_210 ] !=
V_283 -> V_262 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_165 ( enum V_288 * V_289 ,
struct V_290 * V_142 )
{
T_10 V_291 = F_8 ( V_142 -> V_292 ) ;
T_10 V_293 = F_8 ( V_142 -> V_294 ) ;
if ( V_291 != 1 ) {
F_16 ( L_40 ,
V_291 ) ;
return - V_48 ;
}
switch ( V_293 ) {
case 0x4 :
* V_289 = V_295 ;
break;
case 0x5 :
* V_289 = V_296 ;
break;
default:
F_16 ( L_41 , V_293 ) ;
return - V_48 ;
}
return sizeof( * V_142 ) ;
}
static int T_6 F_166 ( char * V_17 , unsigned V_18 ,
enum V_288 type ,
T_10 V_297 ,
T_11 V_244 ,
void * V_245 ,
struct V_290 * V_298 )
{
int V_20 ;
const unsigned V_277 = V_18 ;
F_20 () ;
while ( V_297 -- ) {
V_20 = V_244 ( type , V_298 , V_17 , V_18 , V_245 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_42 , type ) ;
return V_20 ;
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
return V_277 - V_18 ;
}
static int T_6 F_167 ( unsigned V_64 ,
char * V_17 , unsigned V_18 ,
T_11 V_244 , void * V_245 )
{
const unsigned V_277 = V_18 ;
unsigned long V_138 = 0 ;
F_20 () ;
for ( V_138 = 0 ; V_138 < V_64 ; ++ V_138 ) {
int V_20 ;
enum V_288 type ;
T_10 V_297 ;
struct V_290 * V_142 = ( void * ) V_17 ;
if ( V_18 < sizeof( * V_142 ) )
return - V_48 ;
if ( F_168 ( V_142 -> V_299 ) > V_18 )
return - V_48 ;
V_20 = F_165 ( & type , V_142 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_43 ,
V_138 , V_20 ) ;
return V_20 ;
}
V_297 = F_8 ( V_142 -> V_300 ) ;
if ( type == V_295 &&
( V_297 > 255 || V_142 -> V_301 ) )
return - V_48 ;
V_18 -= V_20 ;
V_17 += V_20 ;
V_20 = F_166 ( V_17 , V_18 , type ,
V_297 , V_244 , V_245 , V_142 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_39 , V_123 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
return V_277 - V_18 ;
}
static int F_169 ( enum V_288 type ,
struct V_290 * V_298 , void * V_17 ,
unsigned V_18 , void * V_245 )
{
struct V_6 * V_7 = V_245 ;
T_8 V_28 ;
F_20 () ;
switch ( type ) {
case V_295 : {
struct V_302 * V_283 = V_17 ;
int V_61 ;
if ( V_18 < sizeof( * V_283 ) ||
V_283 -> V_303 >= V_7 -> V_220 ||
! V_283 -> V_304 )
return - V_48 ;
for ( V_61 = 0 ; V_61 < F_35 ( V_283 -> V_305 ) ; ++ V_61 )
if ( V_283 -> V_305 [ V_61 ] )
return - V_48 ;
V_28 = sizeof( struct V_302 ) ;
}
break;
case V_296 : {
struct V_306 * V_283 = V_17 ;
T_12 type , V_307 ;
T_10 V_308 ;
if ( V_18 < sizeof( * V_283 ) || V_298 -> V_309 >= V_7 -> V_220 )
return - V_48 ;
V_28 = F_168 ( V_283 -> V_310 ) ;
if ( V_18 < V_28 )
return - V_48 ;
type = F_168 ( V_283 -> V_311 ) ;
if ( type < V_312 ||
type > V_313 ) {
F_16 ( L_44 ,
type ) ;
return - V_48 ;
}
V_308 = F_8 ( V_283 -> V_314 ) ;
if ( V_28 < 14 + V_308 ) {
F_16 ( L_45 ,
V_28 , V_308 , type ) ;
return - V_48 ;
}
V_307 = F_168 ( * ( T_12 * ) ( ( T_8 * ) V_17 + 10 + V_308 ) ) ;
if ( V_28 != 14 + V_308 + V_307 ) {
F_16 ( L_46 ,
V_28 , V_308 , V_307 , type ) ;
return - V_48 ;
}
++ V_7 -> V_315 ;
V_7 -> V_316 += V_308 * 2 ;
V_7 -> V_317 += V_307 ;
}
break;
default:
F_16 ( L_36 , type ) ;
return - V_48 ;
}
return V_28 ;
}
static int F_26 ( struct V_6 * V_7 ,
char * const V_175 , T_1 V_18 )
{
char * V_17 = V_175 , * V_214 ;
unsigned V_318 = 0 , V_319 [ 3 ] , V_200 ;
int V_20 = - V_48 , V_61 ;
struct V_281 V_282 ;
F_20 () ;
if ( F_170 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_170 ( V_17 ) ) {
case V_320 :
V_200 = V_321 | V_322 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_323 :
V_200 = F_170 ( V_17 + 8 ) ;
V_7 -> V_232 = V_200 ;
if ( V_200 & ~ ( V_321 |
V_322 |
V_324 |
V_325 |
V_233 |
V_326 |
V_327 |
V_328 ) ) {
V_20 = - V_329 ;
goto error;
}
V_17 += 12 ;
V_18 -= 12 ;
break;
default:
goto error;
}
if ( V_200 & V_326 ) {
if ( V_18 < 4 )
goto error;
V_7 -> V_105 =
F_171 ( ( int ) F_170 ( V_17 ) ) ;
if ( F_23 ( V_7 -> V_105 ) ) {
V_20 = F_24 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
goto error;
}
V_17 += 4 ;
V_18 -= 4 ;
}
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! ( V_200 & ( 1 << V_61 ) ) ) {
V_319 [ V_61 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_319 [ V_61 ] = F_170 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
if ( V_200 & ( 1 << V_61 ) ) {
if ( V_18 < 4 ) {
goto error;
}
V_318 = F_170 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
} ;
V_214 = V_17 ;
V_282 . V_7 = V_7 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! V_319 [ V_61 ] )
continue;
V_282 . V_220 = 0 ;
V_282 . V_210 = 0 ;
V_20 = F_163 ( V_319 [ V_61 ] , V_17 , V_18 ,
F_164 , & V_282 ) ;
if ( V_20 < 0 )
goto error;
if ( ! V_7 -> V_210 && ! V_7 -> V_220 ) {
V_7 -> V_210 = V_282 . V_210 ;
V_7 -> V_220 = V_282 . V_220 ;
} else {
if ( V_7 -> V_210 != V_282 . V_210 ) {
V_20 = - V_48 ;
goto error;
}
if ( V_7 -> V_220 != V_282 . V_220 ) {
V_20 = - V_48 ;
goto error;
}
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_318 ) {
V_20 = F_167 ( V_318 , V_17 , V_18 ,
F_169 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_214 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_211 = V_175 ;
V_7 -> V_214 = V_214 ;
V_7 -> V_215 = V_17 - V_214 ;
V_7 -> V_216 = V_319 [ 0 ] ;
V_7 -> V_217 = V_319 [ 1 ] ;
V_7 -> V_218 = V_319 [ 2 ] ;
V_7 -> V_330 = V_318 ;
return 0 ;
error:
F_33 ( V_175 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_175 , T_1 V_18 )
{
T_12 V_331 , V_332 , V_333 ;
struct V_223 * * V_213 , * V_199 ;
const char * V_17 = V_175 ;
struct V_227 * V_231 ;
F_20 () ;
if ( F_12 ( V_18 < 16 ||
F_170 ( V_17 ) != V_334 ||
F_170 ( V_17 + 4 ) != V_18 ) )
goto error;
V_331 = F_170 ( V_17 + 8 ) ;
V_333 = F_170 ( V_17 + 12 ) ;
if ( F_12 ( ! V_331 != ! V_333 ) )
goto error;
V_332 = V_7 -> V_219 ;
if ( F_12 ( V_331 < V_332 ) )
goto error;
if ( ! V_332 ) {
F_33 ( V_175 ) ;
return 0 ;
}
{
unsigned V_61 = 0 ;
F_172 ( V_283 ) ;
F_173 ( V_283 , struct V_223 * , V_213 ,
V_333 + 1 ) ;
F_173 ( V_283 , struct V_223 , V_335 , V_333 ) ;
F_173 ( V_283 , struct V_227 , V_229 ,
V_333 * ( V_332 + 1 ) ) ;
char * V_336 = F_40 ( F_174 ( V_283 ) , V_68 ) ;
if ( F_12 ( ! V_336 ) ) {
F_33 ( V_175 ) ;
return - V_69 ;
}
V_213 = F_175 ( V_336 , V_283 , V_213 ) ;
V_199 = F_175 ( V_336 , V_283 , V_335 ) ;
V_61 = V_333 ;
do {
* V_213 ++ = V_199 ++ ;
} while ( -- V_61 );
* V_213 = NULL ;
V_213 = F_175 ( V_336 , V_283 , V_213 ) ;
V_199 = F_175 ( V_336 , V_283 , V_335 ) ;
V_231 = F_175 ( V_336 , V_283 , V_229 ) ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_337 = V_332 ;
if ( F_12 ( V_18 < 3 ) )
goto V_338;
V_199 -> V_339 = F_176 ( V_17 ) ;
V_199 -> V_229 = V_231 ;
++ V_199 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_177 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_338;
if ( F_39 ( V_337 ) ) {
V_231 -> V_231 = V_17 ;
-- V_337 ;
++ V_231 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_331 );
V_231 -> V_230 = 0 ;
V_231 -> V_231 = NULL ;
++ V_231 ;
} while ( -- V_333 );
if ( F_12 ( V_18 ) )
goto V_338;
V_7 -> V_213 = V_213 ;
V_7 -> V_212 = V_175 ;
return 0 ;
V_338:
F_33 ( V_213 ) ;
error:
F_33 ( V_175 ) ;
return - V_48 ;
}
static void F_178 ( struct V_6 * V_7 ,
enum V_340 type )
{
enum V_340 V_341 , V_342 = type ;
int V_343 = 0 ;
if ( V_7 -> V_8 == V_52 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_344 :
V_342 = V_345 ;
case V_345 :
case V_62 :
V_341 = type ;
break;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
V_341 = V_345 ;
V_342 = V_344 ;
V_343 = 1 ;
break;
default:
F_72 ( 1 , L_47 , type ) ;
return;
}
{
T_8 * V_22 = V_7 -> V_22 . V_59 , * V_350 = V_22 ;
unsigned V_56 = V_7 -> V_22 . V_64 ;
for (; V_56 ; -- V_56 , ++ V_22 )
if ( ( * V_22 == V_341 || * V_22 == V_342 ) == V_343 )
* V_350 ++ = * V_22 ;
else
F_16 ( L_48 , * V_22 ) ;
V_7 -> V_22 . V_64 = V_350 - V_7 -> V_22 . V_59 ;
}
F_16 ( L_49 , type ) ;
V_7 -> V_22 . V_59 [ V_7 -> V_22 . V_64 ++ ] = type ;
F_179 ( & V_7 -> V_22 . V_25 ) ;
if ( V_7 -> V_105 )
F_57 ( V_7 -> V_105 , 1 ) ;
}
static void F_180 ( struct V_6 * V_7 ,
enum V_340 type )
{
unsigned long V_200 ;
F_150 ( & V_7 -> V_22 . V_25 . V_26 , V_200 ) ;
F_178 ( V_7 , type ) ;
F_152 ( & V_7 -> V_22 . V_25 . V_26 , V_200 ) ;
}
static int F_181 ( struct V_6 * V_7 , T_8 V_351 )
{
int V_61 ;
for ( V_61 = 1 ; V_61 < F_35 ( V_7 -> V_234 ) ; ++ V_61 )
if ( V_7 -> V_234 [ V_61 ] == V_351 )
return V_61 ;
return - V_352 ;
}
static int F_182 ( enum V_279 type , T_8 * V_280 ,
struct V_246 * V_142 ,
void * V_245 )
{
struct V_141 * V_237 = ( void * ) V_142 ;
struct V_1 * V_77 = V_245 ;
struct V_89 * V_89 ;
unsigned V_353 ;
int V_354 ;
static const char * V_355 [] = { L_50 , L_51 , L_52 } ;
if ( type != V_278 )
return 0 ;
if ( V_77 -> V_4 . V_356 ) {
V_353 = 2 ;
V_77 -> V_4 . V_356 [ ( long ) V_280 ] = V_142 ;
} else if ( V_77 -> V_4 . V_357 ) {
V_353 = 1 ;
V_77 -> V_4 . V_357 [ ( long ) V_280 ] = V_142 ;
} else {
V_353 = 0 ;
V_77 -> V_4 . V_358 [ ( long ) V_280 ] = V_142 ;
}
if ( ! V_142 || V_142 -> V_248 != V_259 )
return 0 ;
V_354 = F_181 ( V_77 -> V_7 , V_237 -> V_262 ) - 1 ;
if ( V_354 < 0 )
return V_354 ;
V_89 = V_77 -> V_236 + V_354 ;
if ( F_12 ( V_89 -> V_146 [ V_353 ] ) ) {
F_53 ( L_53 ,
V_355 [ V_353 ] ,
V_237 -> V_262 & V_359 ) ;
return - V_48 ;
}
V_89 -> V_146 [ V_353 ] = V_237 ;
F_183 ( L_54 , V_237 , V_237 -> V_147 ) ;
if ( V_89 -> V_12 ) {
V_237 -> V_262 = V_89 -> V_146 [ 0 ] -> V_262 ;
if ( ! V_237 -> V_360 )
V_237 -> V_360 = V_89 -> V_146 [ 0 ] -> V_360 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_8 V_262 ;
V_262 = V_237 -> V_262 ;
F_16 ( L_55 ) ;
V_12 = F_184 ( V_77 -> V_29 , V_237 ) ;
if ( F_12 ( ! V_12 ) )
return - V_361 ;
V_12 -> V_90 = V_77 -> V_236 + V_354 ;
V_14 = F_74 ( V_12 , V_68 ) ;
if ( F_12 ( ! V_14 ) )
return - V_69 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_14 = V_14 ;
V_77 -> V_362 [ V_237 -> V_262 &
V_359 ] = V_354 + 1 ;
if ( V_77 -> V_7 -> V_232 & V_233 )
V_237 -> V_262 = V_262 ;
}
F_183 ( L_56 , V_237 , V_237 -> V_147 ) ;
return 0 ;
}
static int F_185 ( enum V_279 type , T_8 * V_280 ,
struct V_246 * V_142 ,
void * V_245 )
{
struct V_1 * V_77 = V_245 ;
unsigned V_354 ;
T_8 V_363 ;
switch ( type ) {
default:
case V_278 :
return 0 ;
case V_284 :
V_354 = * V_280 ;
if ( V_77 -> V_364 [ V_354 ] < 0 ) {
int V_230 = F_186 ( V_77 -> V_365 , & V_77 -> V_4 ) ;
if ( F_12 ( V_230 < 0 ) )
return V_230 ;
V_77 -> V_364 [ V_354 ] = V_230 ;
}
V_363 = V_77 -> V_364 [ V_354 ] ;
break;
case V_285 :
V_363 = V_77 -> V_7 -> V_213 [ 0 ] -> V_229 [ * V_280 - 1 ] . V_230 ;
break;
case V_286 :
if ( V_142 -> V_248 == V_259 )
return 0 ;
V_354 = ( * V_280 & V_359 ) - 1 ;
if ( F_12 ( ! V_77 -> V_236 [ V_354 ] . V_12 ) )
return - V_48 ;
{
struct V_141 * * V_146 ;
V_146 = V_77 -> V_236 [ V_354 ] . V_146 ;
V_363 = V_146 [ V_146 [ 0 ] ? 0 : 1 ] -> V_262 ;
}
break;
}
F_16 ( L_57 , * V_280 , V_363 ) ;
* V_280 = V_363 ;
return 0 ;
}
static int F_187 ( enum V_288 type ,
struct V_290 * V_298 , void * V_17 ,
unsigned V_18 , void * V_245 )
{
struct V_1 * V_77 = V_245 ;
T_8 V_28 = 0 ;
switch ( type ) {
case V_295 : {
struct V_302 * V_142 = V_17 ;
struct V_366 * V_199 ;
V_199 = & V_77 -> V_4 . V_367 [ V_142 -> V_303 ] ;
V_199 -> V_368 = V_77 -> V_364 [ V_142 -> V_303 ] ;
memcpy ( V_199 -> V_369 -> V_370 , & V_142 -> V_371 ,
F_35 ( V_142 -> V_371 ) +
F_35 ( V_142 -> V_372 ) ) ;
V_28 = sizeof( * V_142 ) ;
}
break;
case V_296 : {
struct V_306 * V_142 = V_17 ;
struct V_366 * V_199 ;
struct V_373 * V_374 ;
char * V_375 ;
char * V_376 ;
V_199 = & V_77 -> V_4 . V_367 [ V_298 -> V_309 ] ;
V_199 -> V_368 = V_77 -> V_364 [ V_298 -> V_309 ] ;
V_374 = V_77 -> V_7 -> V_377 ;
V_77 -> V_7 -> V_377 += sizeof( * V_374 ) ;
V_374 -> type = F_168 ( V_142 -> V_311 ) ;
V_374 -> V_378 = F_8 ( V_142 -> V_314 ) ;
V_374 -> V_91 = F_168 ( * ( T_12 * )
F_188 ( V_17 , V_374 -> V_378 ) ) ;
V_28 = V_374 -> V_378 + V_374 -> V_91 + 14 ;
V_375 = V_77 -> V_7 -> V_379 ;
V_77 -> V_7 -> V_379 +=
V_374 -> V_378 ;
V_376 = V_77 -> V_7 -> V_380 ;
V_77 -> V_7 -> V_380 +=
V_374 -> V_91 ;
memcpy ( V_376 ,
F_189 ( V_17 , V_374 -> V_378 ) ,
V_374 -> V_91 ) ;
switch ( V_374 -> type ) {
case V_312 :
case V_381 :
case V_382 :
case V_313 :
V_374 -> V_91 *= 2 ;
break;
}
V_374 -> V_17 = V_376 ;
memcpy ( V_375 , F_190 ( V_17 ) ,
V_374 -> V_378 ) ;
V_374 -> V_378 *= 2 ;
V_374 -> V_171 = V_375 ;
V_199 -> V_369 -> V_383 +=
V_374 -> V_378 + V_374 -> V_91 + 14 ;
++ V_199 -> V_369 -> V_384 ;
F_191 ( & V_374 -> V_385 , & V_199 -> V_369 -> V_374 ) ;
}
break;
default:
F_16 ( L_36 , type ) ;
}
return V_28 ;
}
static inline struct V_386 * F_192 ( struct V_2 * V_3 ,
struct V_387 * V_388 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_386 * V_389 =
F_2 ( V_3 -> V_390 , struct V_386 , V_391 ) ;
int V_20 ;
F_20 () ;
if ( ! V_389 -> V_392 )
F_193 () ;
V_20 = V_389 -> V_393 -> V_394 ? 0 : - V_78 ;
V_77 -> V_7 = V_389 -> V_393 -> V_6 ;
if ( ! V_389 -> V_392 )
F_194 () ;
if ( V_20 )
return F_105 ( V_20 ) ;
V_77 -> V_365 = V_388 ;
V_77 -> V_29 = V_388 -> V_222 -> V_29 ;
if ( ! V_389 -> V_395 ) {
V_20 = F_141 ( V_77 -> V_7 , V_388 -> V_222 ) ;
if ( V_20 )
return F_105 ( V_20 ) ;
}
V_389 -> V_395 ++ ;
V_77 -> V_4 . V_229 = V_77 -> V_7 -> V_213 ;
return V_389 ;
}
static int F_195 ( struct V_387 * V_388 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
const int V_396 = ! ! V_77 -> V_7 -> V_216 ;
const int V_397 = F_196 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_217 ;
const int V_398 = F_197 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_218 ;
int V_399 , V_400 , V_401 , V_20 , V_61 ;
struct V_89 * V_402 ;
F_172 ( V_283 ) ;
F_198 ( V_283 , struct V_89 , V_236 , V_7 -> V_210 ) ;
F_198 ( V_283 , struct V_246 * , V_403 ,
V_396 ? V_7 -> V_216 + 1 : 0 ) ;
F_198 ( V_283 , struct V_246 * , V_404 ,
V_397 ? V_7 -> V_217 + 1 : 0 ) ;
F_198 ( V_283 , struct V_246 * , V_405 ,
V_398 ? V_7 -> V_218 + 1 : 0 ) ;
F_198 ( V_283 , short , V_406 , V_7 -> V_220 ) ;
F_198 ( V_283 , struct V_366 , V_367 ,
V_388 -> V_222 -> V_407 ? V_7 -> V_220 : 0 ) ;
F_198 ( V_283 , char [ 16 ] , V_408 ,
V_388 -> V_222 -> V_407 ? V_7 -> V_220 : 0 ) ;
F_198 ( V_283 , struct V_409 , V_369 ,
V_388 -> V_222 -> V_407 ? V_7 -> V_220 : 0 ) ;
F_198 ( V_283 , struct V_373 , V_374 ,
V_7 -> V_315 ) ;
F_198 ( V_283 , char , V_375 ,
V_7 -> V_316 ) ;
F_198 ( V_283 , char , V_376 ,
V_7 -> V_317 ) ;
F_198 ( V_283 , char , V_214 , V_7 -> V_215 ) ;
char * V_336 ;
F_20 () ;
if ( F_12 ( ! ( V_396 | V_397 | V_398 ) ) )
return - V_361 ;
V_336 = F_131 ( F_174 ( V_283 ) , V_68 ) ;
if ( F_12 ( ! V_336 ) )
return - V_69 ;
V_7 -> V_377 = F_175 ( V_336 , V_283 , V_374 ) ;
V_7 -> V_379 =
F_175 ( V_336 , V_283 , V_375 ) ;
V_7 -> V_380 =
F_175 ( V_336 , V_283 , V_376 ) ;
memcpy ( F_175 ( V_336 , V_283 , V_214 ) , V_7 -> V_214 ,
V_7 -> V_215 ) ;
memset ( F_175 ( V_336 , V_283 , V_406 ) , 0xff , V_410 ) ;
V_402 = F_175 ( V_336 , V_283 , V_236 ) ;
for ( V_61 = 0 ; V_61 < V_7 -> V_210 ; V_61 ++ )
V_402 [ V_61 ] . V_138 = - 1 ;
V_77 -> V_236 = F_175 ( V_336 , V_283 , V_236 ) ;
V_77 -> V_364 = F_175 ( V_336 , V_283 , V_406 ) ;
if ( F_39 ( V_396 ) ) {
V_77 -> V_4 . V_358 = F_175 ( V_336 , V_283 , V_403 ) ;
V_399 = F_163 ( V_7 -> V_216 ,
F_175 ( V_336 , V_283 , V_214 ) ,
V_411 ,
F_182 , V_77 ) ;
if ( F_12 ( V_399 < 0 ) ) {
V_20 = V_399 ;
goto error;
}
} else {
V_399 = 0 ;
}
if ( F_39 ( V_397 ) ) {
V_77 -> V_4 . V_357 = F_175 ( V_336 , V_283 , V_404 ) ;
V_400 = F_163 ( V_7 -> V_217 ,
F_175 ( V_336 , V_283 , V_214 ) + V_399 ,
V_411 - V_399 ,
F_182 , V_77 ) ;
if ( F_12 ( V_400 < 0 ) ) {
V_20 = V_400 ;
goto error;
}
} else {
V_400 = 0 ;
}
if ( F_39 ( V_398 ) ) {
V_77 -> V_4 . V_356 = F_175 ( V_336 , V_283 , V_405 ) ;
V_401 = F_163 ( V_7 -> V_218 ,
F_175 ( V_336 , V_283 , V_214 ) + V_399 + V_400 ,
V_411 - V_399 - V_400 ,
F_182 , V_77 ) ;
if ( F_12 ( V_401 < 0 ) ) {
V_20 = V_401 ;
goto error;
}
} else {
V_401 = 0 ;
}
V_20 = F_163 ( V_7 -> V_216 +
( V_397 ? V_7 -> V_217 : 0 ) +
( V_398 ? V_7 -> V_218 : 0 ) ,
F_175 ( V_336 , V_283 , V_214 ) , V_411 ,
F_185 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_77 -> V_4 . V_367 = F_175 ( V_336 , V_283 , V_367 ) ;
if ( V_388 -> V_222 -> V_407 ) {
for ( V_61 = 0 ; V_61 < V_7 -> V_220 ; ++ V_61 ) {
struct V_409 * V_142 ;
V_142 = V_77 -> V_4 . V_367 [ V_61 ] . V_369 =
F_175 ( V_336 , V_283 , V_369 ) +
V_61 * sizeof( struct V_409 ) ;
V_142 -> V_370 =
F_175 ( V_336 , V_283 , V_408 ) + V_61 * 16 ;
F_199 ( & V_142 -> V_374 ) ;
}
V_20 = F_167 ( V_7 -> V_330 ,
F_175 ( V_336 , V_283 , V_214 ) +
V_399 + V_400 + V_401 ,
V_411 - V_399 - V_400 -
V_401 ,
F_187 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
}
V_77 -> V_4 . V_412 =
V_388 -> V_222 -> V_407 ? V_7 -> V_220 : 0 ;
F_180 ( V_7 , V_346 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_200 ( struct V_387 * V_388 ,
struct V_2 * V_3 )
{
struct V_386 * V_389 = F_192 ( V_3 , V_388 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_20 ;
if ( F_23 ( V_389 ) )
return F_24 ( V_389 ) ;
V_20 = F_195 ( V_388 , V_3 ) ;
if ( V_20 && ! -- V_389 -> V_395 )
F_144 ( V_77 -> V_7 ) ;
return V_20 ;
}
static void F_201 ( struct V_94 * V_95 )
{
struct V_6 * V_7 = F_2 ( V_95 ,
struct V_6 , V_413 ) ;
F_122 ( V_7 ) ;
}
static int F_202 ( struct V_2 * V_3 ,
unsigned V_309 , unsigned V_414 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
int V_20 = 0 , V_415 ;
if ( V_414 != ( unsigned ) - 1 ) {
V_415 = F_46 ( V_77 , V_309 ) ;
if ( F_12 ( V_415 < 0 ) )
return V_415 ;
}
if ( V_7 -> V_77 )
F_149 ( V_7 -> V_77 ) ;
if ( V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_60 ( & V_7 -> V_413 , F_201 ) ;
F_203 ( & V_7 -> V_413 ) ;
return - V_78 ;
}
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
if ( V_414 == ( unsigned ) - 1 ) {
V_7 -> V_77 = NULL ;
F_180 ( V_7 , V_348 ) ;
return 0 ;
}
V_7 -> V_77 = V_77 ;
V_20 = F_153 ( V_77 ) ;
if ( F_39 ( V_20 >= 0 ) )
F_180 ( V_7 , V_349 ) ;
return V_20 ;
}
static void F_204 ( struct V_2 * V_3 )
{
F_202 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_205 ( struct V_2 * V_3 ,
const struct V_416 * V_417 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
unsigned long V_200 ;
int V_20 ;
F_20 () ;
F_16 ( L_58 , V_417 -> V_53 ) ;
F_16 ( L_59 , V_417 -> V_418 ) ;
F_16 ( L_60 , F_8 ( V_417 -> V_419 ) ) ;
F_16 ( L_61 , F_8 ( V_417 -> V_294 ) ) ;
F_16 ( L_62 , F_8 ( V_417 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
switch ( V_417 -> V_53 & V_420 ) {
case V_421 :
V_20 = F_46 ( V_77 , F_8 ( V_417 -> V_294 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_422 :
V_20 = F_206 ( V_77 , F_8 ( V_417 -> V_294 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_77 -> V_7 -> V_232 & V_233 )
V_20 = V_77 -> V_7 -> V_234 [ V_20 ] ;
break;
default:
if ( V_77 -> V_7 -> V_232 & V_327 )
V_20 = F_8 ( V_417 -> V_294 ) ;
else
return - V_423 ;
}
F_150 ( & V_7 -> V_22 . V_25 . V_26 , V_200 ) ;
V_7 -> V_22 . V_23 = * V_417 ;
V_7 -> V_22 . V_23 . V_294 = F_207 ( V_20 ) ;
F_178 ( V_7 , V_62 ) ;
F_152 ( & V_7 -> V_22 . V_25 . V_26 , V_200 ) ;
return 0 ;
}
static bool F_208 ( struct V_2 * V_3 ,
const struct V_416 * V_417 ,
bool V_424 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
if ( V_424 && ! ( V_77 -> V_7 -> V_232 & V_328 ) )
return false ;
switch ( V_417 -> V_53 & V_420 ) {
case V_421 :
return ( F_46 ( V_77 ,
F_8 ( V_417 -> V_294 ) ) >= 0 ) ;
case V_422 :
return ( F_206 ( V_77 ,
F_8 ( V_417 -> V_294 ) ) >= 0 ) ;
default:
return ( bool ) ( V_77 -> V_7 -> V_232 &
V_327 ) ;
}
}
static void F_209 ( struct V_2 * V_3 )
{
F_20 () ;
F_180 ( F_1 ( V_3 ) -> V_7 , V_345 ) ;
}
static void F_210 ( struct V_2 * V_3 )
{
F_20 () ;
F_180 ( F_1 ( V_3 ) -> V_7 , V_344 ) ;
}
static int F_206 ( struct V_1 * V_77 , T_8 V_138 )
{
V_138 = V_77 -> V_362 [ V_138 & V_359 ] ;
return V_138 ? V_138 : - V_425 ;
}
static int F_46 ( struct V_1 * V_77 , T_8 V_415 )
{
short * V_426 = V_77 -> V_364 ;
unsigned V_64 = V_77 -> V_7 -> V_220 ;
for (; V_64 ; -- V_64 , ++ V_426 ) {
if ( * V_426 >= 0 && * V_426 == V_415 )
return V_426 - V_77 -> V_364 ;
}
return - V_425 ;
}
static struct V_205 * F_211 ( const char * V_171 )
{
struct V_205 * V_393 ;
if ( ! V_171 )
return NULL ;
F_212 (dev, &ffs_devices, entry) {
if ( strcmp ( V_393 -> V_171 , V_171 ) == 0 )
return V_393 ;
}
return NULL ;
}
static struct V_205 * F_213 ( void )
{
struct V_205 * V_393 ;
if ( F_214 ( & V_427 ) ) {
V_393 = F_215 ( & V_427 , struct V_205 , V_385 ) ;
if ( V_393 -> V_428 )
return V_393 ;
}
return NULL ;
}
static struct V_205 * F_216 ( const char * V_171 )
{
struct V_205 * V_393 ;
V_393 = F_213 () ;
if ( V_393 )
return V_393 ;
return F_211 ( V_171 ) ;
}
static inline struct V_386 * F_217 ( struct V_429 * V_430 )
{
return F_2 ( F_218 ( V_430 ) , struct V_386 ,
V_391 . V_431 ) ;
}
static void F_219 ( struct V_429 * V_430 )
{
struct V_386 * V_191 = F_217 ( V_430 ) ;
F_220 ( & V_191 -> V_391 ) ;
}
static void F_221 ( struct V_432 * V_3 )
{
struct V_386 * V_191 ;
V_191 = F_222 ( V_3 ) ;
F_193 () ;
F_223 ( V_191 -> V_393 ) ;
F_194 () ;
F_33 ( V_191 ) ;
}
static int F_224 ( struct V_432 * V_390 , const char * V_171 )
{
if ( strlen ( V_171 ) >= F_225 ( struct V_205 , V_171 ) )
return - V_433 ;
return F_226 ( F_222 ( V_390 ) -> V_393 , V_171 ) ;
}
static struct V_432 * F_227 ( void )
{
struct V_386 * V_191 ;
struct V_205 * V_393 ;
V_191 = F_131 ( sizeof( * V_191 ) , V_68 ) ;
if ( ! V_191 )
return F_105 ( - V_69 ) ;
V_191 -> V_391 . V_434 = F_224 ;
V_191 -> V_391 . V_435 = F_221 ;
F_193 () ;
V_393 = F_228 () ;
F_194 () ;
if ( F_23 ( V_393 ) ) {
F_33 ( V_191 ) ;
return F_110 ( V_393 ) ;
}
V_191 -> V_393 = V_393 ;
V_393 -> V_191 = V_191 ;
F_229 ( & V_191 -> V_391 . V_431 , L_63 ,
& V_436 ) ;
return & V_191 -> V_391 ;
}
static void F_230 ( struct V_2 * V_3 )
{
F_33 ( F_1 ( V_3 ) ) ;
}
static void F_231 ( struct V_387 * V_388 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_386 * V_191 =
F_2 ( V_3 -> V_390 , struct V_386 , V_391 ) ;
struct V_89 * V_12 = V_77 -> V_236 ;
unsigned V_64 = V_7 -> V_210 ;
unsigned long V_200 ;
F_20 () ;
if ( V_7 -> V_77 == V_77 ) {
F_149 ( V_77 ) ;
V_7 -> V_77 = NULL ;
}
if ( ! -- V_191 -> V_395 )
F_144 ( V_7 ) ;
F_150 ( & V_77 -> V_7 -> V_119 , V_200 ) ;
while ( V_64 -- ) {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_58 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
}
F_152 ( & V_77 -> V_7 -> V_119 , V_200 ) ;
F_33 ( V_77 -> V_236 ) ;
V_77 -> V_236 = NULL ;
V_77 -> V_4 . V_358 = NULL ;
V_77 -> V_4 . V_357 = NULL ;
V_77 -> V_4 . V_356 = NULL ;
V_77 -> V_364 = NULL ;
F_180 ( V_7 , V_347 ) ;
}
static struct V_2 * F_232 ( struct V_432 * V_390 )
{
struct V_1 * V_77 ;
F_20 () ;
V_77 = F_131 ( sizeof( * V_77 ) , V_68 ) ;
if ( F_12 ( ! V_77 ) )
return F_105 ( - V_69 ) ;
V_77 -> V_4 . V_171 = L_64 ;
V_77 -> V_4 . V_437 = F_200 ;
V_77 -> V_4 . V_438 = F_231 ;
V_77 -> V_4 . V_439 = F_202 ;
V_77 -> V_4 . V_440 = F_204 ;
V_77 -> V_4 . V_23 = F_205 ;
V_77 -> V_4 . V_441 = F_208 ;
V_77 -> V_4 . V_442 = F_209 ;
V_77 -> V_4 . V_443 = F_210 ;
V_77 -> V_4 . V_444 = F_230 ;
return & V_77 -> V_4 ;
}
static struct V_205 * F_228 ( void )
{
struct V_205 * V_393 ;
int V_20 ;
if ( F_213 () )
return F_105 ( - V_72 ) ;
V_393 = F_131 ( sizeof( * V_393 ) , V_68 ) ;
if ( ! V_393 )
return F_105 ( - V_69 ) ;
if ( F_233 ( & V_427 ) ) {
V_20 = F_115 () ;
if ( V_20 ) {
F_33 ( V_393 ) ;
return F_105 ( V_20 ) ;
}
}
F_234 ( & V_393 -> V_385 , & V_427 ) ;
return V_393 ;
}
int F_226 ( struct V_205 * V_393 , const char * V_171 )
{
struct V_205 * V_445 ;
int V_20 = 0 ;
F_193 () ;
V_445 = F_211 ( V_171 ) ;
if ( ! V_445 )
F_235 ( V_393 -> V_171 , V_171 , F_35 ( V_393 -> V_171 ) ) ;
else if ( V_445 != V_393 )
V_20 = - V_72 ;
F_194 () ;
return V_20 ;
}
int F_236 ( struct V_205 * V_393 )
{
int V_20 ;
V_20 = 0 ;
F_193 () ;
if ( ! F_214 ( & V_427 ) )
V_20 = - V_72 ;
else
V_393 -> V_428 = true ;
F_194 () ;
return V_20 ;
}
static void F_223 ( struct V_205 * V_393 )
{
F_237 ( & V_393 -> V_385 ) ;
if ( V_393 -> V_6 )
V_393 -> V_6 -> V_40 = NULL ;
F_33 ( V_393 ) ;
if ( F_233 ( & V_427 ) )
F_117 () ;
}
static void * F_109 ( const char * V_201 )
{
struct V_205 * V_205 ;
F_20 () ;
F_193 () ;
V_205 = F_216 ( V_201 ) ;
if ( ! V_205 )
V_205 = F_105 ( - V_352 ) ;
else if ( V_205 -> V_446 )
V_205 = F_105 ( - V_72 ) ;
else if ( V_205 -> V_447 &&
V_205 -> V_447 ( V_205 ) )
V_205 = F_105 ( - V_352 ) ;
else
V_205 -> V_446 = true ;
F_194 () ;
return V_205 ;
}
static void F_112 ( struct V_6 * V_6 )
{
struct V_205 * V_205 ;
F_20 () ;
F_193 () ;
V_205 = V_6 -> V_40 ;
if ( V_205 ) {
V_205 -> V_446 = false ;
if ( V_205 -> V_448 )
V_205 -> V_448 ( V_205 ) ;
}
F_194 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_205 * V_449 ;
int V_20 = 0 ;
F_20 () ;
F_193 () ;
V_449 = V_7 -> V_40 ;
if ( ! V_449 ) {
V_20 = - V_48 ;
goto V_124;
}
if ( F_68 ( V_449 -> V_394 ) ) {
V_20 = - V_72 ;
goto V_124;
}
V_449 -> V_394 = true ;
V_449 -> V_6 = V_7 ;
if ( V_449 -> V_450 ) {
V_20 = V_449 -> V_450 ( V_7 ) ;
if ( V_20 )
goto V_124;
}
F_238 ( V_451 , & V_7 -> V_200 ) ;
V_124:
F_194 () ;
return V_20 ;
}
static void F_139 ( struct V_6 * V_7 )
{
struct V_205 * V_449 ;
struct V_386 * V_191 ;
struct V_429 * V_452 ;
F_20 () ;
F_193 () ;
V_449 = V_7 -> V_40 ;
if ( ! V_449 )
goto V_124;
V_449 -> V_394 = false ;
if ( F_239 ( V_451 , & V_7 -> V_200 ) &&
V_449 -> V_453 )
V_449 -> V_453 ( V_7 ) ;
if ( V_449 -> V_191 )
V_191 = V_449 -> V_191 ;
else
goto V_124;
if ( V_191 -> V_392 || ! V_191 -> V_391 . V_431 . V_454 . V_455
|| ! F_240 ( & V_191 -> V_391 . V_431 . V_454 . V_456 ) )
goto V_124;
V_452 = V_191 -> V_391 . V_431 . V_454 . V_455 -> V_455 ;
F_194 () ;
F_241 ( V_452 ) ;
return;
V_124:
F_194 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_457 )
{
return V_457
? F_39 ( F_242 ( V_42 ) ) ? 0 : - V_67
: F_243 ( V_42 ) ;
}
static char * F_22 ( const char T_3 * V_27 , T_1 V_18 )
{
char * V_17 ;
if ( F_12 ( ! V_18 ) )
return NULL ;
V_17 = F_40 ( V_18 , V_68 ) ;
if ( F_12 ( ! V_17 ) )
return F_105 ( - V_69 ) ;
if ( F_12 ( F_244 ( V_17 , V_27 , V_18 ) ) ) {
F_33 ( V_17 ) ;
return F_105 ( - V_65 ) ;
}
F_16 ( L_65 ) ;
F_183 ( L_63 , V_17 , V_18 ) ;
return V_17 ;
}
