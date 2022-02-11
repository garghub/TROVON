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
static T_2 F_51 ( void * V_17 , int V_91 , struct V_92 * V_93 )
{
T_2 V_20 = F_52 ( V_17 , V_91 , V_93 ) ;
if ( F_39 ( V_20 == V_91 ) )
return V_20 ;
if ( F_12 ( F_53 ( V_93 ) ) )
return - V_65 ;
F_54 ( L_5
L_6 ,
V_91 , V_20 ) ;
return V_20 ;
}
static void F_55 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = F_2 ( V_95 , struct V_96 ,
V_95 ) ;
int V_20 = V_97 -> V_14 -> V_33 ? V_97 -> V_14 -> V_33 :
V_97 -> V_14 -> V_34 ;
bool V_98 = V_97 -> V_99 -> V_100 & V_101 ;
if ( V_97 -> V_102 && V_20 > 0 ) {
F_56 ( V_97 -> V_103 ) ;
V_20 = F_51 ( V_97 -> V_27 , V_20 , & V_97 -> V_17 ) ;
F_57 ( V_97 -> V_103 ) ;
}
V_97 -> V_99 -> V_104 ( V_97 -> V_99 , V_20 , V_20 ) ;
if ( V_97 -> V_7 -> V_105 && ! V_98 )
F_58 ( V_97 -> V_7 -> V_105 , 1 ) ;
F_59 ( V_97 -> V_12 , V_97 -> V_14 ) ;
if ( V_97 -> V_102 )
F_33 ( V_97 -> V_106 ) ;
F_33 ( V_97 -> V_27 ) ;
F_33 ( V_97 ) ;
}
static void F_60 ( struct V_11 * V_88 ,
struct V_13 * V_14 )
{
struct V_96 * V_97 = V_14 -> V_15 ;
F_20 () ;
F_61 ( & V_97 -> V_95 , F_55 ) ;
F_62 ( & V_97 -> V_95 ) ;
}
static T_2 F_63 ( struct V_107 * V_108 ,
struct V_92 * V_93 )
{
struct V_109 * V_27 = V_108 -> V_110 ;
T_2 V_20 ;
if ( ! V_27 )
return 0 ;
V_20 = F_52 ( V_27 -> V_17 , V_27 -> V_28 , V_93 ) ;
if ( V_27 -> V_28 == V_20 ) {
F_33 ( V_27 ) ;
V_108 -> V_110 = NULL ;
} else if ( F_12 ( F_53 ( V_93 ) ) ) {
V_20 = - V_65 ;
} else {
V_27 -> V_28 -= V_20 ;
V_27 -> V_17 += V_20 ;
}
return V_20 ;
}
static T_2 F_64 ( struct V_107 * V_108 ,
void * V_17 , int V_91 ,
struct V_92 * V_93 )
{
struct V_109 * V_27 ;
T_2 V_20 = F_52 ( V_17 , V_91 , V_93 ) ;
if ( F_39 ( V_91 == V_20 ) )
return V_20 ;
if ( F_12 ( F_53 ( V_93 ) ) )
return - V_65 ;
F_65 ( L_7 ,
V_91 , V_20 ) ;
V_91 -= V_20 ;
V_27 = F_40 ( sizeof( * V_27 ) + V_91 , V_68 ) ;
if ( ! V_27 )
return - V_69 ;
V_27 -> V_28 = V_91 ;
V_27 -> V_17 = V_27 -> V_111 ;
memcpy ( V_27 -> V_111 , V_17 + V_20 , V_91 ) ;
V_108 -> V_110 = V_27 ;
return V_20 ;
}
static T_2 F_66 ( struct V_38 * V_38 , struct V_96 * V_97 )
{
struct V_107 * V_108 = V_38 -> V_40 ;
struct V_13 * V_14 ;
struct V_89 * V_12 ;
char * V_17 = NULL ;
T_2 V_20 , V_91 = - V_48 ;
int V_112 ;
if ( F_67 ( V_108 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_12 = V_108 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 )
return - V_67 ;
V_20 = F_68 ( V_108 -> V_82 , ( V_12 = V_108 -> V_12 ) ) ;
if ( V_20 )
return - V_32 ;
}
V_112 = ( ! V_97 -> V_102 == ! V_108 -> V_113 ) ;
if ( V_112 && V_108 -> V_114 )
return - V_48 ;
V_20 = F_21 ( & V_108 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 ) )
goto error;
if ( ! V_112 ) {
struct V_75 * V_29 ;
if ( ! V_97 -> V_115 && V_97 -> V_102 ) {
V_20 = F_63 ( V_108 , & V_97 -> V_17 ) ;
if ( V_20 )
goto V_116;
}
V_29 = V_108 -> V_7 -> V_29 ;
F_31 ( & V_108 -> V_7 -> V_117 ) ;
if ( V_108 -> V_12 != V_12 ) {
V_20 = - V_118 ;
goto V_119;
}
V_91 = F_53 ( & V_97 -> V_17 ) ;
if ( V_97 -> V_102 )
V_91 = F_69 ( V_29 , V_12 -> V_12 , V_91 ) ;
F_9 ( & V_108 -> V_7 -> V_117 ) ;
V_17 = F_40 ( V_91 , V_68 ) ;
if ( F_12 ( ! V_17 ) ) {
V_20 = - V_69 ;
goto V_116;
}
if ( ! V_97 -> V_102 &&
F_70 ( V_17 , V_91 , & V_97 -> V_17 ) != V_91 ) {
V_20 = - V_65 ;
goto V_116;
}
}
F_31 ( & V_108 -> V_7 -> V_117 ) ;
if ( V_108 -> V_12 != V_12 ) {
V_20 = - V_118 ;
} else if ( V_112 ) {
if ( F_39 ( V_108 -> V_12 == V_12 ) && ! F_67 ( ! V_12 -> V_12 ) )
F_17 ( V_12 -> V_12 ) ;
V_20 = - V_120 ;
} else if ( F_12 ( V_91 == - V_48 ) ) {
F_71 ( 1 , L_8 , V_121 ) ;
V_20 = - V_48 ;
} else if ( ! V_97 -> V_115 ) {
F_72 ( V_122 ) ;
bool V_123 = false ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_91 ;
V_14 -> V_15 = & V_122 ;
V_14 -> F_50 = F_49 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 < 0 ) )
goto V_119;
F_9 ( & V_108 -> V_7 -> V_117 ) ;
if ( F_12 ( F_13 ( & V_122 ) ) ) {
F_14 ( V_12 -> V_12 , V_14 ) ;
V_123 = V_12 -> V_33 < 0 ;
}
if ( V_123 )
V_20 = - V_32 ;
else if ( V_97 -> V_102 && V_12 -> V_33 > 0 )
V_20 = F_64 ( V_108 , V_17 , V_12 -> V_33 ,
& V_97 -> V_17 ) ;
else
V_20 = V_12 -> V_33 ;
goto V_116;
} else if ( ! ( V_14 = F_73 ( V_12 -> V_12 , V_68 ) ) ) {
V_20 = - V_69 ;
} else {
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_91 ;
V_97 -> V_27 = V_17 ;
V_97 -> V_12 = V_12 -> V_12 ;
V_97 -> V_14 = V_14 ;
V_97 -> V_7 = V_108 -> V_7 ;
V_14 -> V_15 = V_97 ;
V_14 -> F_50 = F_60 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 ) ) {
F_59 ( V_12 -> V_12 , V_14 ) ;
goto V_119;
}
V_20 = - V_124 ;
V_17 = NULL ;
}
V_119:
F_9 ( & V_108 -> V_7 -> V_117 ) ;
V_116:
F_29 ( & V_108 -> V_42 ) ;
error:
F_33 ( V_17 ) ;
return V_20 ;
}
static int
F_74 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_107 * V_108 = V_70 -> V_71 ;
F_20 () ;
if ( F_67 ( V_108 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
V_38 -> V_40 = V_108 ;
F_42 ( V_108 -> V_7 ) ;
return 0 ;
}
static int F_75 ( struct V_99 * V_99 )
{
struct V_96 * V_97 = V_99 -> V_125 ;
struct V_107 * V_108 = V_99 -> V_126 -> V_40 ;
int V_74 ;
F_20 () ;
F_31 ( & V_108 -> V_7 -> V_117 ) ;
if ( F_39 ( V_97 && V_97 -> V_12 && V_97 -> V_14 ) )
V_74 = F_14 ( V_97 -> V_12 , V_97 -> V_14 ) ;
else
V_74 = - V_48 ;
F_9 ( & V_108 -> V_7 -> V_117 ) ;
return V_74 ;
}
static T_2 F_76 ( struct V_99 * V_99 , struct V_92 * V_127 )
{
struct V_96 V_97 , * V_128 = & V_97 ;
T_2 V_129 ;
F_20 () ;
if ( ! F_77 ( V_99 ) ) {
V_128 = F_40 ( sizeof( V_97 ) , V_68 ) ;
if ( F_12 ( ! V_128 ) )
return - V_69 ;
V_128 -> V_115 = true ;
} else {
V_128 -> V_115 = false ;
}
V_128 -> V_102 = false ;
V_128 -> V_99 = V_99 ;
V_128 -> V_17 = * V_127 ;
V_128 -> V_103 = V_130 -> V_103 ;
V_99 -> V_125 = V_128 ;
if ( V_128 -> V_115 )
F_78 ( V_99 , F_75 ) ;
V_129 = F_66 ( V_99 -> V_126 , V_128 ) ;
if ( V_129 == - V_124 )
return V_129 ;
if ( V_128 -> V_115 )
F_33 ( V_128 ) ;
else
* V_127 = V_128 -> V_17 ;
return V_129 ;
}
static T_2 F_79 ( struct V_99 * V_99 , struct V_92 * V_131 )
{
struct V_96 V_97 , * V_128 = & V_97 ;
T_2 V_129 ;
F_20 () ;
if ( ! F_77 ( V_99 ) ) {
V_128 = F_40 ( sizeof( V_97 ) , V_68 ) ;
if ( F_12 ( ! V_128 ) )
return - V_69 ;
V_128 -> V_115 = true ;
} else {
V_128 -> V_115 = false ;
}
V_128 -> V_102 = true ;
V_128 -> V_99 = V_99 ;
if ( V_128 -> V_115 ) {
V_128 -> V_106 = F_80 ( & V_128 -> V_17 , V_131 , V_68 ) ;
if ( ! V_128 -> V_106 ) {
F_33 ( V_128 ) ;
return - V_69 ;
}
} else {
V_128 -> V_17 = * V_131 ;
V_128 -> V_106 = NULL ;
}
V_128 -> V_103 = V_130 -> V_103 ;
V_99 -> V_125 = V_128 ;
if ( V_128 -> V_115 )
F_78 ( V_99 , F_75 ) ;
V_129 = F_66 ( V_99 -> V_126 , V_128 ) ;
if ( V_129 == - V_124 )
return V_129 ;
if ( V_128 -> V_115 ) {
F_33 ( V_128 -> V_106 ) ;
F_33 ( V_128 ) ;
} else {
* V_131 = V_128 -> V_17 ;
}
return V_129 ;
}
static int
F_81 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
struct V_107 * V_108 = V_70 -> V_71 ;
F_20 () ;
F_33 ( V_108 -> V_110 ) ;
V_108 -> V_110 = NULL ;
F_44 ( V_108 -> V_7 ) ;
return 0 ;
}
static long F_82 ( struct V_38 * V_38 , unsigned V_73 ,
unsigned long V_74 )
{
struct V_107 * V_108 = V_38 -> V_40 ;
int V_20 ;
F_20 () ;
if ( F_67 ( V_108 -> V_7 -> V_45 != V_50 ) )
return - V_78 ;
F_31 ( & V_108 -> V_7 -> V_117 ) ;
if ( F_39 ( V_108 -> V_12 ) ) {
switch ( V_73 ) {
case V_132 :
V_20 = F_83 ( V_108 -> V_12 -> V_12 ) ;
break;
case V_133 :
F_84 ( V_108 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_134 :
V_20 = F_85 ( V_108 -> V_12 -> V_12 ) ;
break;
case V_135 :
V_20 = V_108 -> V_12 -> V_136 ;
break;
case V_137 :
{
int V_138 ;
struct V_139 * V_140 ;
switch ( V_108 -> V_7 -> V_29 -> V_141 ) {
case V_142 :
V_138 = 2 ;
break;
case V_143 :
V_138 = 1 ;
break;
default:
V_138 = 0 ;
}
V_140 = V_108 -> V_12 -> V_144 [ V_138 ] ;
F_9 ( & V_108 -> V_7 -> V_117 ) ;
V_20 = F_36 ( ( void * ) V_74 , V_140 , sizeof( * V_140 ) ) ;
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
F_9 ( & V_108 -> V_7 -> V_117 ) ;
return V_20 ;
}
static struct V_70 * T_6
F_86 ( struct V_145 * V_146 , void * V_17 ,
const struct V_147 * V_148 ,
const struct V_149 * V_150 ,
struct V_151 * V_152 )
{
struct V_70 * V_70 ;
F_20 () ;
V_70 = F_87 ( V_146 ) ;
if ( F_39 ( V_70 ) ) {
struct V_153 V_154 = V_155 ;
V_70 -> V_156 = F_88 () ;
V_70 -> V_157 = V_152 -> V_158 ;
V_70 -> V_159 = V_152 -> V_160 ;
V_70 -> V_161 = V_152 -> V_162 ;
V_70 -> V_163 = V_154 ;
V_70 -> V_164 = V_154 ;
V_70 -> V_165 = V_154 ;
V_70 -> V_71 = V_17 ;
if ( V_148 )
V_70 -> V_166 = V_148 ;
if ( V_150 )
V_70 -> V_167 = V_150 ;
}
return V_70 ;
}
static struct V_168 * F_89 ( struct V_145 * V_146 ,
const char * V_169 , void * V_17 ,
const struct V_147 * V_148 )
{
struct V_6 * V_7 = V_146 -> V_170 ;
struct V_168 * V_168 ;
struct V_70 * V_70 ;
F_20 () ;
V_168 = F_90 ( V_146 -> V_171 , V_169 ) ;
if ( F_12 ( ! V_168 ) )
return NULL ;
V_70 = F_86 ( V_146 , V_17 , V_148 , NULL , & V_7 -> V_172 ) ;
if ( F_12 ( ! V_70 ) ) {
F_91 ( V_168 ) ;
return NULL ;
}
F_92 ( V_168 , V_70 ) ;
return V_168 ;
}
static int F_93 ( struct V_145 * V_146 , void * V_173 , int V_174 )
{
struct V_175 * V_17 = V_173 ;
struct V_70 * V_70 ;
struct V_6 * V_7 = V_17 -> V_6 ;
F_20 () ;
V_7 -> V_146 = V_146 ;
V_17 -> V_6 = NULL ;
V_146 -> V_170 = V_7 ;
V_146 -> V_176 = V_177 ;
V_146 -> V_178 = V_179 ;
V_146 -> V_180 = V_181 ;
V_146 -> V_182 = & V_183 ;
V_146 -> V_184 = 1 ;
V_17 -> V_152 . V_158 = V_17 -> V_185 ;
V_70 = F_86 ( V_146 , NULL ,
& V_186 ,
& V_187 ,
& V_17 -> V_152 ) ;
V_146 -> V_171 = F_94 ( V_70 ) ;
if ( F_12 ( ! V_146 -> V_171 ) )
return - V_69 ;
if ( F_12 ( ! F_89 ( V_146 , L_9 , V_7 ,
& V_188 ) ) )
return - V_69 ;
return 0 ;
}
static int F_95 ( struct V_175 * V_17 , char * V_189 )
{
F_20 () ;
if ( ! V_189 || ! * V_189 )
return 0 ;
for (; ; ) {
unsigned long V_74 ;
char * V_190 , * V_191 ;
V_191 = strchr ( V_189 , ',' ) ;
if ( V_191 )
* V_191 = 0 ;
V_190 = strchr ( V_189 , '=' ) ;
if ( F_12 ( ! V_190 ) ) {
F_54 ( L_10 , V_189 ) ;
return - V_48 ;
}
* V_190 = 0 ;
if ( F_96 ( V_190 + 1 , 0 , & V_74 ) ) {
F_54 ( L_11 , V_189 , V_190 + 1 ) ;
return - V_48 ;
}
switch ( V_190 - V_189 ) {
case 13 :
if ( ! memcmp ( V_189 , L_12 , 13 ) )
V_17 -> V_192 = ! ! V_74 ;
else
goto V_193;
break;
case 5 :
if ( ! memcmp ( V_189 , L_13 , 5 ) )
V_17 -> V_185 = ( V_74 & 0555 ) | V_194 ;
else if ( ! memcmp ( V_189 , L_14 , 5 ) )
V_17 -> V_152 . V_158 = ( V_74 & 0666 ) | V_195 ;
else
goto V_193;
break;
case 4 :
if ( ! memcmp ( V_189 , L_15 , 4 ) ) {
V_17 -> V_185 = ( V_74 & 0555 ) | V_194 ;
V_17 -> V_152 . V_158 = ( V_74 & 0666 ) | V_195 ;
} else {
goto V_193;
}
break;
case 3 :
if ( ! memcmp ( V_189 , L_16 , 3 ) ) {
V_17 -> V_152 . V_160 = F_97 ( F_98 () , V_74 ) ;
if ( ! F_99 ( V_17 -> V_152 . V_160 ) ) {
F_54 ( L_17 , V_189 , V_74 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_189 , L_18 , 3 ) ) {
V_17 -> V_152 . V_162 = F_100 ( F_98 () , V_74 ) ;
if ( ! F_101 ( V_17 -> V_152 . V_162 ) ) {
F_54 ( L_17 , V_189 , V_74 ) ;
return - V_48 ;
}
} else {
goto V_193;
}
break;
default:
V_193:
F_54 ( L_19 , V_189 ) ;
return - V_48 ;
}
if ( ! V_191 )
break;
V_189 = V_191 + 1 ;
}
return 0 ;
}
static struct V_168 *
F_102 ( struct V_196 * V_197 , int V_198 ,
const char * V_199 , void * V_189 )
{
struct V_175 V_17 = {
. V_152 = {
. V_158 = V_195 | 0600 ,
. V_160 = V_200 ,
. V_162 = V_201 ,
} ,
. V_185 = V_194 | 0500 ,
. V_192 = false ,
} ;
struct V_168 * V_202 ;
int V_20 ;
void * V_203 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_95 ( & V_17 , V_189 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_103 ( V_20 ) ;
V_7 = F_104 () ;
if ( F_12 ( ! V_7 ) )
return F_103 ( - V_69 ) ;
V_7 -> V_172 = V_17 . V_152 ;
V_7 -> V_192 = V_17 . V_192 ;
V_7 -> V_199 = F_105 ( V_199 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_199 ) ) {
F_106 ( V_7 ) ;
return F_103 ( - V_69 ) ;
}
V_203 = F_107 ( V_199 ) ;
if ( F_23 ( V_203 ) ) {
F_106 ( V_7 ) ;
return F_108 ( V_203 ) ;
}
V_7 -> V_40 = V_203 ;
V_17 . V_6 = V_7 ;
V_202 = F_109 ( V_197 , V_198 , & V_17 , F_93 ) ;
if ( F_23 ( V_202 ) && V_17 . V_6 ) {
F_110 ( V_17 . V_6 ) ;
F_106 ( V_17 . V_6 ) ;
}
return V_202 ;
}
static void
F_111 ( struct V_145 * V_146 )
{
F_20 () ;
F_112 ( V_146 ) ;
if ( V_146 -> V_170 ) {
F_110 ( V_146 -> V_170 ) ;
F_44 ( V_146 -> V_170 ) ;
F_106 ( V_146 -> V_170 ) ;
}
}
static int F_113 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_114 ( & V_204 ) ;
if ( F_39 ( ! V_20 ) )
F_25 ( L_20 ) ;
else
F_54 ( L_21 , V_20 ) ;
return V_20 ;
}
static void F_115 ( void )
{
F_20 () ;
F_25 ( L_22 ) ;
F_116 ( & V_204 ) ;
}
static void F_117 ( struct V_6 * V_7 )
{
F_20 () ;
F_118 ( & V_7 -> V_205 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_20 () ;
F_118 ( & V_7 -> V_205 ) ;
if ( F_119 ( 1 , & V_7 -> V_206 ) == 1 &&
V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_120 ( V_7 ) ;
}
}
static void F_106 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_121 ( & V_7 -> V_205 ) ) ) {
F_25 ( L_23 , V_121 ) ;
F_122 ( V_7 ) ;
F_123 ( F_124 ( & V_7 -> V_22 . V_25 ) ||
F_124 ( & V_7 -> V_16 . V_82 ) ) ;
F_33 ( V_7 -> V_199 ) ;
F_33 ( V_7 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_121 ( & V_7 -> V_206 ) ) {
if ( V_7 -> V_192 ) {
V_7 -> V_45 = V_87 ;
if ( V_7 -> V_207 ) {
F_125 ( V_7 -> V_207 ,
V_7 -> V_208 ) ;
V_7 -> V_207 = NULL ;
}
if ( V_7 -> V_8 == V_52 )
F_15 ( V_7 ) ;
} else {
V_7 -> V_45 = V_49 ;
F_120 ( V_7 ) ;
}
}
if ( F_126 ( & V_7 -> V_206 ) < 0 ) {
V_7 -> V_45 = V_49 ;
F_120 ( V_7 ) ;
}
F_106 ( V_7 ) ;
}
static struct V_6 * F_104 ( void )
{
struct V_6 * V_7 = F_127 ( sizeof *V_7 , V_68 ) ;
if ( F_12 ( ! V_7 ) )
return NULL ;
F_20 () ;
F_128 ( & V_7 -> V_205 , 1 ) ;
F_128 ( & V_7 -> V_206 , 0 ) ;
V_7 -> V_45 = V_46 ;
F_129 ( & V_7 -> V_42 ) ;
F_130 ( & V_7 -> V_117 ) ;
F_131 ( & V_7 -> V_22 . V_25 ) ;
F_132 ( & V_7 -> V_16 ) ;
V_7 -> V_22 . V_35 = 1 ;
return V_7 ;
}
static void F_122 ( struct V_6 * V_7 )
{
F_20 () ;
F_133 ( V_7 ) ;
F_123 ( V_7 -> V_29 ) ;
if ( V_7 -> V_207 )
F_125 ( V_7 -> V_207 , V_7 -> V_208 ) ;
if ( V_7 -> V_105 )
F_134 ( V_7 -> V_105 ) ;
F_33 ( V_7 -> V_209 ) ;
F_33 ( V_7 -> V_210 ) ;
F_33 ( V_7 -> V_211 ) ;
}
static void F_120 ( struct V_6 * V_7 )
{
F_20 () ;
F_122 ( V_7 ) ;
V_7 -> V_207 = NULL ;
V_7 -> V_209 = NULL ;
V_7 -> V_212 = NULL ;
V_7 -> V_210 = NULL ;
V_7 -> V_211 = NULL ;
V_7 -> V_213 = 0 ;
V_7 -> V_214 = 0 ;
V_7 -> V_215 = 0 ;
V_7 -> V_216 = 0 ;
V_7 -> V_217 = 0 ;
V_7 -> V_218 = 0 ;
V_7 -> V_208 = 0 ;
V_7 -> V_22 . V_64 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_198 = 0 ;
}
static int F_135 ( struct V_6 * V_7 , struct V_219 * V_220 )
{
struct V_221 * * V_222 ;
int V_223 ;
F_20 () ;
if ( F_67 ( V_7 -> V_45 != V_50
|| F_136 ( V_224 , & V_7 -> V_198 ) ) )
return - V_55 ;
V_223 = F_137 ( V_220 , V_7 -> V_217 ) ;
if ( F_12 ( V_223 < 0 ) )
return V_223 ;
V_7 -> V_19 = F_73 ( V_220 -> V_29 -> V_30 , V_68 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_69 ;
V_7 -> V_19 -> F_50 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_222 = V_7 -> V_211 ;
if ( V_222 ) {
for (; * V_222 ; ++ V_222 ) {
struct V_225 * V_226 = ( * V_222 ) -> V_227 ;
int V_228 = V_223 ;
for (; V_226 -> V_229 ; ++ V_228 , ++ V_226 )
V_226 -> V_228 = V_228 ;
}
}
V_7 -> V_29 = V_220 -> V_29 ;
F_117 ( V_7 ) ;
return 0 ;
}
static void F_138 ( struct V_6 * V_7 )
{
F_20 () ;
if ( ! F_67 ( ! V_7 -> V_29 ) ) {
F_59 ( V_7 -> V_29 -> V_30 , V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_29 = NULL ;
F_139 ( V_224 , & V_7 -> V_198 ) ;
F_106 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_107 * V_108 , * V_207 ;
unsigned V_61 , V_64 ;
F_20 () ;
V_64 = V_7 -> V_208 ;
V_207 = F_140 ( V_64 , sizeof( * V_207 ) , V_68 ) ;
if ( ! V_207 )
return - V_69 ;
V_108 = V_207 ;
for ( V_61 = 1 ; V_61 <= V_64 ; ++ V_61 , ++ V_108 ) {
V_108 -> V_7 = V_7 ;
F_129 ( & V_108 -> V_42 ) ;
F_131 ( & V_108 -> V_82 ) ;
if ( V_7 -> V_230 & V_231 )
sprintf ( V_108 -> V_169 , L_24 , V_7 -> V_232 [ V_61 ] ) ;
else
sprintf ( V_108 -> V_169 , L_25 , V_61 ) ;
V_108 -> V_168 = F_89 ( V_7 -> V_146 , V_108 -> V_169 ,
V_108 ,
& V_233 ) ;
if ( F_12 ( ! V_108 -> V_168 ) ) {
F_125 ( V_207 , V_61 - 1 ) ;
return - V_69 ;
}
}
V_7 -> V_207 = V_207 ;
return 0 ;
}
static void F_125 ( struct V_107 * V_207 , unsigned V_64 )
{
struct V_107 * V_108 = V_207 ;
F_20 () ;
for (; V_64 ; -- V_64 , ++ V_108 ) {
F_123 ( F_141 ( & V_108 -> V_42 ) ||
F_124 ( & V_108 -> V_82 ) ) ;
if ( V_108 -> V_168 ) {
F_142 ( V_108 -> V_168 ) ;
F_91 ( V_108 -> V_168 ) ;
V_108 -> V_168 = NULL ;
}
}
F_33 ( V_207 ) ;
}
static void F_143 ( struct V_1 * V_77 )
{
struct V_89 * V_12 = V_77 -> V_234 ;
struct V_107 * V_108 = V_77 -> V_7 -> V_207 ;
unsigned V_64 = V_77 -> V_7 -> V_208 ;
unsigned long V_198 ;
do {
if ( V_108 )
F_144 ( & V_108 -> V_42 ) ;
F_145 ( & V_77 -> V_7 -> V_117 , V_198 ) ;
if ( F_39 ( V_12 -> V_12 ) )
F_146 ( V_12 -> V_12 ) ;
++ V_12 ;
F_147 ( & V_77 -> V_7 -> V_117 , V_198 ) ;
if ( V_108 ) {
V_108 -> V_12 = NULL ;
F_33 ( V_108 -> V_110 ) ;
V_108 -> V_110 = NULL ;
F_29 ( & V_108 -> V_42 ) ;
++ V_108 ;
}
} while ( -- V_64 );
}
static int F_148 ( struct V_1 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_89 * V_12 = V_77 -> V_234 ;
struct V_107 * V_108 = V_7 -> V_207 ;
unsigned V_64 = V_7 -> V_208 ;
unsigned long V_198 ;
int V_20 = 0 ;
F_145 ( & V_77 -> V_7 -> V_117 , V_198 ) ;
do {
struct V_139 * V_235 ;
int V_138 ;
if ( V_7 -> V_29 -> V_141 == V_142 )
V_138 = 2 ;
else if ( V_7 -> V_29 -> V_141 == V_143 )
V_138 = 1 ;
else
V_138 = 0 ;
do {
V_235 = V_12 -> V_144 [ V_138 ] ;
} while ( ! V_235 && -- V_138 >= 0 );
if ( ! V_235 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_90 = V_12 ;
V_12 -> V_12 -> V_140 = V_235 ;
V_20 = F_149 ( V_12 -> V_12 ) ;
if ( F_39 ( ! V_20 ) ) {
V_108 -> V_12 = V_12 ;
V_108 -> V_113 = F_150 ( V_235 ) ;
V_108 -> V_114 = F_151 ( V_235 ) ;
} else {
break;
}
F_152 ( & V_108 -> V_82 ) ;
++ V_12 ;
++ V_108 ;
} while ( -- V_64 );
F_147 ( & V_77 -> V_7 -> V_117 , V_198 ) ;
return V_20 ;
}
static int T_6 F_153 ( char * V_17 , unsigned V_18 ,
T_7 V_236 ,
void * V_237 )
{
struct V_238 * V_239 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_26 ) ;
return - V_48 ;
}
V_28 = V_239 -> V_240 ;
if ( V_18 < V_28 ) {
F_16 ( L_27 ) ;
return - V_48 ;
}
#define F_154 ( T_9 ) 1
#define F_155 ( T_9 ) (val)
#define F_156 ( T_9 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_157 ( type , T_9 ) do { \
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
switch ( V_239 -> V_241 ) {
case V_242 :
case V_243 :
case V_244 :
case V_245 :
F_16 ( L_28 ,
V_239 -> V_241 ) ;
return - V_48 ;
case V_246 : {
struct V_247 * V_235 = ( void * ) V_239 ;
F_16 ( L_29 ) ;
if ( V_28 != sizeof *V_235 )
goto V_248;
F_157 ( V_249 , V_235 -> V_250 ) ;
if ( V_235 -> V_251 )
F_157 ( STRING , V_235 -> V_251 ) ;
}
break;
case V_252 : {
struct V_139 * V_235 = ( void * ) V_239 ;
F_16 ( L_30 ) ;
if ( V_28 != V_253 &&
V_28 != V_254 )
goto V_248;
F_157 ( V_255 , V_235 -> V_256 ) ;
}
break;
case V_257 :
F_16 ( L_31 ) ;
if ( V_28 != sizeof( struct V_258 ) )
goto V_248;
break;
case V_259 :
if ( V_28 != sizeof( struct V_260 ) )
goto V_248;
break;
case V_261 : {
struct V_262 * V_235 = ( void * ) V_239 ;
F_16 ( L_32 ) ;
if ( V_28 != sizeof *V_235 )
goto V_248;
if ( V_235 -> V_263 )
F_157 ( STRING , V_235 -> V_263 ) ;
}
break;
case V_264 :
F_16 ( L_33 ) ;
if ( V_28 != sizeof( struct V_265 ) )
goto V_248;
break;
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
F_16 ( L_34 , V_239 -> V_241 ) ;
return - V_48 ;
default:
F_16 ( L_35 , V_239 -> V_241 ) ;
return - V_48 ;
V_248:
F_16 ( L_36 ,
V_239 -> V_240 , V_239 -> V_241 ) ;
return - V_48 ;
}
#undef F_157
#undef V_271
#undef F_154
#undef F_155
#undef F_156
return V_28 ;
}
static int T_6 F_158 ( unsigned V_64 , char * V_17 , unsigned V_18 ,
T_7 V_236 , void * V_237 )
{
const unsigned V_272 = V_18 ;
unsigned long V_136 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_136 == V_64 )
V_17 = NULL ;
V_20 = V_236 ( V_273 , ( T_8 * ) V_136 , ( void * ) V_17 , V_237 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_37 ,
V_136 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_272 - V_18 ;
V_20 = F_153 ( V_17 , V_18 , V_236 , V_237 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 , V_121 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_136 ;
}
}
static int F_159 ( enum V_274 type ,
T_8 * V_275 , struct V_238 * V_140 ,
void * V_237 )
{
struct V_276 * V_277 = V_237 ;
struct V_139 * V_278 ;
F_20 () ;
switch ( type ) {
case V_273 :
break;
case V_279 :
if ( * V_275 >= V_277 -> V_218 )
V_277 -> V_218 = * V_275 + 1 ;
break;
case V_280 :
if ( * V_275 > V_277 -> V_7 -> V_217 )
V_277 -> V_7 -> V_217 = * V_275 ;
break;
case V_281 :
V_278 = ( void * ) V_140 ;
V_277 -> V_208 ++ ;
if ( V_277 -> V_208 >= 15 )
return - V_48 ;
if ( ! V_277 -> V_7 -> V_208 && ! V_277 -> V_7 -> V_218 )
V_277 -> V_7 -> V_232 [ V_277 -> V_208 ] =
V_278 -> V_256 ;
else if ( V_277 -> V_7 -> V_232 [ V_277 -> V_208 ] !=
V_278 -> V_256 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_160 ( enum V_282 * V_283 ,
struct V_284 * V_140 )
{
T_10 V_285 = F_8 ( V_140 -> V_286 ) ;
T_10 V_287 = F_8 ( V_140 -> V_288 ) ;
if ( V_285 != 1 ) {
F_16 ( L_39 ,
V_285 ) ;
return - V_48 ;
}
switch ( V_287 ) {
case 0x4 :
* V_283 = V_289 ;
break;
case 0x5 :
* V_283 = V_290 ;
break;
default:
F_16 ( L_40 , V_287 ) ;
return - V_48 ;
}
return sizeof( * V_140 ) ;
}
static int T_6 F_161 ( char * V_17 , unsigned V_18 ,
enum V_282 type ,
T_10 V_291 ,
T_11 V_236 ,
void * V_237 ,
struct V_284 * V_292 )
{
int V_20 ;
const unsigned V_272 = V_18 ;
F_20 () ;
while ( V_291 -- ) {
V_20 = V_236 ( type , V_292 , V_17 , V_18 , V_237 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_41 , type ) ;
return V_20 ;
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
return V_272 - V_18 ;
}
static int T_6 F_162 ( unsigned V_64 ,
char * V_17 , unsigned V_18 ,
T_11 V_236 , void * V_237 )
{
const unsigned V_272 = V_18 ;
unsigned long V_136 = 0 ;
F_20 () ;
for ( V_136 = 0 ; V_136 < V_64 ; ++ V_136 ) {
int V_20 ;
enum V_282 type ;
T_10 V_291 ;
struct V_284 * V_140 = ( void * ) V_17 ;
if ( V_18 < sizeof( * V_140 ) )
return - V_48 ;
if ( F_163 ( V_140 -> V_293 ) > V_18 )
return - V_48 ;
V_20 = F_160 ( & type , V_140 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_42 ,
V_136 , V_20 ) ;
return V_20 ;
}
V_291 = F_8 ( V_140 -> V_294 ) ;
if ( type == V_289 &&
( V_291 > 255 || V_140 -> V_295 ) )
return - V_48 ;
V_18 -= V_20 ;
V_17 += V_20 ;
V_20 = F_161 ( V_17 , V_18 , type ,
V_291 , V_236 , V_237 , V_140 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 , V_121 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
return V_272 - V_18 ;
}
static int F_164 ( enum V_282 type ,
struct V_284 * V_292 , void * V_17 ,
unsigned V_18 , void * V_237 )
{
struct V_6 * V_7 = V_237 ;
T_8 V_28 ;
F_20 () ;
switch ( type ) {
case V_289 : {
struct V_296 * V_278 = V_17 ;
int V_61 ;
if ( V_18 < sizeof( * V_278 ) ||
V_278 -> V_297 >= V_7 -> V_218 ||
! V_278 -> V_298 )
return - V_48 ;
for ( V_61 = 0 ; V_61 < F_35 ( V_278 -> V_299 ) ; ++ V_61 )
if ( V_278 -> V_299 [ V_61 ] )
return - V_48 ;
V_28 = sizeof( struct V_296 ) ;
}
break;
case V_290 : {
struct V_300 * V_278 = V_17 ;
T_12 type , V_301 ;
T_10 V_302 ;
if ( V_18 < sizeof( * V_278 ) || V_292 -> V_303 >= V_7 -> V_218 )
return - V_48 ;
V_28 = F_163 ( V_278 -> V_304 ) ;
type = F_163 ( V_278 -> V_305 ) ;
if ( type < V_306 ||
type > V_307 ) {
F_16 ( L_43 ,
type ) ;
return - V_48 ;
}
V_302 = F_8 ( V_278 -> V_308 ) ;
V_301 = F_163 ( * ( T_12 * ) ( ( T_8 * ) V_17 + 10 + V_302 ) ) ;
if ( V_28 != 14 + V_302 + V_301 ) {
F_16 ( L_44 ,
V_28 , V_302 , V_301 , type ) ;
return - V_48 ;
}
++ V_7 -> V_309 ;
V_7 -> V_310 += V_302 * 2 ;
V_7 -> V_311 += V_301 ;
}
break;
default:
F_16 ( L_35 , type ) ;
return - V_48 ;
}
return V_28 ;
}
static int F_26 ( struct V_6 * V_7 ,
char * const V_173 , T_1 V_18 )
{
char * V_17 = V_173 , * V_212 ;
unsigned V_312 = 0 , V_313 [ 3 ] , V_198 ;
int V_20 = - V_48 , V_61 ;
struct V_276 V_277 ;
F_20 () ;
if ( F_165 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_165 ( V_17 ) ) {
case V_314 :
V_198 = V_315 | V_316 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_317 :
V_198 = F_165 ( V_17 + 8 ) ;
V_7 -> V_230 = V_198 ;
if ( V_198 & ~ ( V_315 |
V_316 |
V_318 |
V_319 |
V_231 |
V_320 ) ) {
V_20 = - V_321 ;
goto error;
}
V_17 += 12 ;
V_18 -= 12 ;
break;
default:
goto error;
}
if ( V_198 & V_320 ) {
if ( V_18 < 4 )
goto error;
V_7 -> V_105 =
F_166 ( ( int ) F_165 ( V_17 ) ) ;
if ( F_23 ( V_7 -> V_105 ) ) {
V_20 = F_24 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
goto error;
}
V_17 += 4 ;
V_18 -= 4 ;
}
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! ( V_198 & ( 1 << V_61 ) ) ) {
V_313 [ V_61 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_313 [ V_61 ] = F_165 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
if ( V_198 & ( 1 << V_61 ) ) {
V_312 = F_165 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
} ;
V_212 = V_17 ;
V_277 . V_7 = V_7 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! V_313 [ V_61 ] )
continue;
V_277 . V_218 = 0 ;
V_277 . V_208 = 0 ;
V_20 = F_158 ( V_313 [ V_61 ] , V_17 , V_18 ,
F_159 , & V_277 ) ;
if ( V_20 < 0 )
goto error;
if ( ! V_7 -> V_208 && ! V_7 -> V_218 ) {
V_7 -> V_208 = V_277 . V_208 ;
V_7 -> V_218 = V_277 . V_218 ;
} else {
if ( V_7 -> V_208 != V_277 . V_208 ) {
V_20 = - V_48 ;
goto error;
}
if ( V_7 -> V_218 != V_277 . V_218 ) {
V_20 = - V_48 ;
goto error;
}
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_312 ) {
V_20 = F_162 ( V_312 , V_17 , V_18 ,
F_164 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_212 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_209 = V_173 ;
V_7 -> V_212 = V_212 ;
V_7 -> V_213 = V_17 - V_212 ;
V_7 -> V_214 = V_313 [ 0 ] ;
V_7 -> V_215 = V_313 [ 1 ] ;
V_7 -> V_216 = V_313 [ 2 ] ;
V_7 -> V_322 = V_312 ;
return 0 ;
error:
F_33 ( V_173 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_173 , T_1 V_18 )
{
T_12 V_323 , V_324 , V_325 ;
struct V_221 * * V_211 , * V_197 ;
const char * V_17 = V_173 ;
struct V_225 * V_229 ;
F_20 () ;
if ( F_12 ( F_165 ( V_17 ) != V_326 ||
F_165 ( V_17 + 4 ) != V_18 ) )
goto error;
V_323 = F_165 ( V_17 + 8 ) ;
V_325 = F_165 ( V_17 + 12 ) ;
if ( F_12 ( ! V_323 != ! V_325 ) )
goto error;
V_324 = V_7 -> V_217 ;
if ( F_12 ( V_323 < V_324 ) )
goto error;
if ( ! V_324 ) {
F_33 ( V_173 ) ;
return 0 ;
}
{
unsigned V_61 = 0 ;
F_167 ( V_278 ) ;
F_168 ( V_278 , struct V_221 * , V_211 ,
V_325 + 1 ) ;
F_168 ( V_278 , struct V_221 , V_327 , V_325 ) ;
F_168 ( V_278 , struct V_225 , V_227 ,
V_325 * ( V_324 + 1 ) ) ;
char * V_328 = F_40 ( F_169 ( V_278 ) , V_68 ) ;
if ( F_12 ( ! V_328 ) ) {
F_33 ( V_173 ) ;
return - V_69 ;
}
V_211 = F_170 ( V_328 , V_278 , V_211 ) ;
V_197 = F_170 ( V_328 , V_278 , V_327 ) ;
V_61 = V_325 ;
do {
* V_211 ++ = V_197 ++ ;
} while ( -- V_61 );
* V_211 = NULL ;
V_211 = F_170 ( V_328 , V_278 , V_211 ) ;
V_197 = F_170 ( V_328 , V_278 , V_327 ) ;
V_229 = F_170 ( V_328 , V_278 , V_227 ) ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_329 = V_324 ;
if ( F_12 ( V_18 < 3 ) )
goto V_330;
V_197 -> V_331 = F_171 ( V_17 ) ;
V_197 -> V_227 = V_229 ;
++ V_197 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_172 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_330;
if ( F_39 ( V_329 ) ) {
V_229 -> V_229 = V_17 ;
-- V_329 ;
++ V_229 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_323 );
V_229 -> V_228 = 0 ;
V_229 -> V_229 = NULL ;
++ V_229 ;
} while ( -- V_325 );
if ( F_12 ( V_18 ) )
goto V_330;
V_7 -> V_211 = V_211 ;
V_7 -> V_210 = V_173 ;
return 0 ;
V_330:
F_33 ( V_211 ) ;
error:
F_33 ( V_173 ) ;
return - V_48 ;
}
static void F_173 ( struct V_6 * V_7 ,
enum V_332 type )
{
enum V_332 V_333 , V_334 = type ;
int V_335 = 0 ;
if ( V_7 -> V_8 == V_52 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_336 :
V_334 = V_337 ;
case V_337 :
case V_62 :
V_333 = type ;
break;
case V_338 :
case V_339 :
case V_340 :
case V_341 :
V_333 = V_337 ;
V_334 = V_336 ;
V_335 = 1 ;
break;
default:
F_71 ( 1 , L_45 , type ) ;
return;
}
{
T_8 * V_22 = V_7 -> V_22 . V_59 , * V_342 = V_22 ;
unsigned V_56 = V_7 -> V_22 . V_64 ;
for (; V_56 ; -- V_56 , ++ V_22 )
if ( ( * V_22 == V_333 || * V_22 == V_334 ) == V_335 )
* V_342 ++ = * V_22 ;
else
F_16 ( L_46 , * V_22 ) ;
V_7 -> V_22 . V_64 = V_342 - V_7 -> V_22 . V_59 ;
}
F_16 ( L_47 , type ) ;
V_7 -> V_22 . V_59 [ V_7 -> V_22 . V_64 ++ ] = type ;
F_174 ( & V_7 -> V_22 . V_25 ) ;
if ( V_7 -> V_105 )
F_58 ( V_7 -> V_105 , 1 ) ;
}
static void F_175 ( struct V_6 * V_7 ,
enum V_332 type )
{
unsigned long V_198 ;
F_145 ( & V_7 -> V_22 . V_25 . V_26 , V_198 ) ;
F_173 ( V_7 , type ) ;
F_147 ( & V_7 -> V_22 . V_25 . V_26 , V_198 ) ;
}
static int F_176 ( struct V_6 * V_7 , T_8 V_343 )
{
int V_61 ;
for ( V_61 = 1 ; V_61 < F_35 ( V_7 -> V_232 ) ; ++ V_61 )
if ( V_7 -> V_232 [ V_61 ] == V_343 )
return V_61 ;
return - V_344 ;
}
static int F_177 ( enum V_274 type , T_8 * V_275 ,
struct V_238 * V_140 ,
void * V_237 )
{
struct V_139 * V_235 = ( void * ) V_140 ;
struct V_1 * V_77 = V_237 ;
struct V_89 * V_89 ;
unsigned V_345 ;
int V_346 ;
static const char * V_347 [] = { L_48 , L_49 , L_50 } ;
if ( type != V_273 )
return 0 ;
if ( V_77 -> V_4 . V_348 ) {
V_345 = 2 ;
V_77 -> V_4 . V_348 [ ( long ) V_275 ] = V_140 ;
} else if ( V_77 -> V_4 . V_349 ) {
V_345 = 1 ;
V_77 -> V_4 . V_349 [ ( long ) V_275 ] = V_140 ;
} else {
V_345 = 0 ;
V_77 -> V_4 . V_350 [ ( long ) V_275 ] = V_140 ;
}
if ( ! V_140 || V_140 -> V_241 != V_252 )
return 0 ;
V_346 = F_176 ( V_77 -> V_7 , V_235 -> V_256 ) - 1 ;
if ( V_346 < 0 )
return V_346 ;
V_89 = V_77 -> V_234 + V_346 ;
if ( F_12 ( V_89 -> V_144 [ V_345 ] ) ) {
F_54 ( L_51 ,
V_347 [ V_345 ] ,
V_235 -> V_256 & V_351 ) ;
return - V_48 ;
}
V_89 -> V_144 [ V_345 ] = V_235 ;
F_178 ( L_52 , V_235 , V_235 -> V_240 ) ;
if ( V_89 -> V_12 ) {
V_235 -> V_256 = V_89 -> V_144 [ 0 ] -> V_256 ;
if ( ! V_235 -> V_352 )
V_235 -> V_352 = V_89 -> V_144 [ 0 ] -> V_352 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_8 V_256 ;
V_256 = V_235 -> V_256 ;
F_16 ( L_53 ) ;
V_12 = F_179 ( V_77 -> V_29 , V_235 ) ;
if ( F_12 ( ! V_12 ) )
return - V_353 ;
V_12 -> V_90 = V_77 -> V_234 + V_346 ;
V_14 = F_73 ( V_12 , V_68 ) ;
if ( F_12 ( ! V_14 ) )
return - V_69 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_14 = V_14 ;
V_77 -> V_354 [ V_235 -> V_256 &
V_351 ] = V_346 + 1 ;
if ( V_77 -> V_7 -> V_230 & V_231 )
V_235 -> V_256 = V_256 ;
}
F_178 ( L_54 , V_235 , V_235 -> V_240 ) ;
return 0 ;
}
static int F_180 ( enum V_274 type , T_8 * V_275 ,
struct V_238 * V_140 ,
void * V_237 )
{
struct V_1 * V_77 = V_237 ;
unsigned V_346 ;
T_8 V_355 ;
switch ( type ) {
default:
case V_273 :
return 0 ;
case V_279 :
V_346 = * V_275 ;
if ( V_77 -> V_356 [ V_346 ] < 0 ) {
int V_228 = F_181 ( V_77 -> V_357 , & V_77 -> V_4 ) ;
if ( F_12 ( V_228 < 0 ) )
return V_228 ;
V_77 -> V_356 [ V_346 ] = V_228 ;
}
V_355 = V_77 -> V_356 [ V_346 ] ;
break;
case V_280 :
V_355 = V_77 -> V_7 -> V_211 [ 0 ] -> V_227 [ * V_275 - 1 ] . V_228 ;
break;
case V_281 :
if ( V_140 -> V_241 == V_252 )
return 0 ;
V_346 = ( * V_275 & V_351 ) - 1 ;
if ( F_12 ( ! V_77 -> V_234 [ V_346 ] . V_12 ) )
return - V_48 ;
{
struct V_139 * * V_144 ;
V_144 = V_77 -> V_234 [ V_346 ] . V_144 ;
V_355 = V_144 [ V_144 [ 0 ] ? 0 : 1 ] -> V_256 ;
}
break;
}
F_16 ( L_55 , * V_275 , V_355 ) ;
* V_275 = V_355 ;
return 0 ;
}
static int F_182 ( enum V_282 type ,
struct V_284 * V_292 , void * V_17 ,
unsigned V_18 , void * V_237 )
{
struct V_1 * V_77 = V_237 ;
T_8 V_28 = 0 ;
switch ( type ) {
case V_289 : {
struct V_296 * V_140 = V_17 ;
struct V_358 * V_197 ;
V_197 = & V_77 -> V_4 . V_359 [ V_140 -> V_297 ] ;
V_197 -> V_360 = V_77 -> V_356 [ V_140 -> V_297 ] ;
memcpy ( V_197 -> V_361 -> V_362 , & V_140 -> V_363 ,
F_35 ( V_140 -> V_363 ) +
F_35 ( V_140 -> V_364 ) ) ;
V_28 = sizeof( * V_140 ) ;
}
break;
case V_290 : {
struct V_300 * V_140 = V_17 ;
struct V_358 * V_197 ;
struct V_365 * V_366 ;
char * V_367 ;
char * V_368 ;
V_197 = & V_77 -> V_4 . V_359 [ V_292 -> V_303 ] ;
V_197 -> V_360 = V_77 -> V_356 [ V_292 -> V_303 ] ;
V_366 = V_77 -> V_7 -> V_369 ;
V_77 -> V_7 -> V_369 += sizeof( * V_366 ) ;
V_366 -> type = F_163 ( V_140 -> V_305 ) ;
V_366 -> V_370 = F_8 ( V_140 -> V_308 ) ;
V_366 -> V_91 = F_163 ( * ( T_12 * )
F_183 ( V_17 , V_366 -> V_370 ) ) ;
V_28 = V_366 -> V_370 + V_366 -> V_91 + 14 ;
V_367 = V_77 -> V_7 -> V_371 ;
V_77 -> V_7 -> V_371 +=
V_366 -> V_370 ;
V_368 = V_77 -> V_7 -> V_372 ;
V_77 -> V_7 -> V_372 +=
V_366 -> V_91 ;
memcpy ( V_368 ,
F_184 ( V_17 , V_366 -> V_370 ) ,
V_366 -> V_91 ) ;
switch ( V_366 -> type ) {
case V_306 :
case V_373 :
case V_374 :
case V_307 :
V_366 -> V_91 *= 2 ;
break;
}
V_366 -> V_17 = V_368 ;
memcpy ( V_367 , F_185 ( V_17 ) ,
V_366 -> V_370 ) ;
V_366 -> V_370 *= 2 ;
V_366 -> V_169 = V_367 ;
V_197 -> V_361 -> V_375 +=
V_366 -> V_370 + V_366 -> V_91 + 14 ;
++ V_197 -> V_361 -> V_376 ;
F_186 ( & V_366 -> V_377 , & V_197 -> V_361 -> V_366 ) ;
}
break;
default:
F_16 ( L_35 , type ) ;
}
return V_28 ;
}
static inline struct V_378 * F_187 ( struct V_2 * V_3 ,
struct V_379 * V_380 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_378 * V_381 =
F_2 ( V_3 -> V_382 , struct V_378 , V_383 ) ;
int V_20 ;
F_20 () ;
if ( ! V_381 -> V_384 )
F_188 () ;
V_20 = V_381 -> V_385 -> V_386 ? 0 : - V_78 ;
V_77 -> V_7 = V_381 -> V_385 -> V_6 ;
if ( ! V_381 -> V_384 )
F_189 () ;
if ( V_20 )
return F_103 ( V_20 ) ;
V_77 -> V_357 = V_380 ;
V_77 -> V_29 = V_380 -> V_220 -> V_29 ;
if ( ! V_381 -> V_387 ) {
V_20 = F_135 ( V_77 -> V_7 , V_380 -> V_220 ) ;
if ( V_20 )
return F_103 ( V_20 ) ;
}
V_381 -> V_387 ++ ;
V_77 -> V_4 . V_227 = V_77 -> V_7 -> V_211 ;
return V_381 ;
}
static int F_190 ( struct V_379 * V_380 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
const int V_388 = ! ! V_77 -> V_7 -> V_214 ;
const int V_389 = F_191 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_215 ;
const int V_390 = F_192 ( V_77 -> V_29 ) &&
V_77 -> V_7 -> V_216 ;
int V_391 , V_392 , V_393 , V_20 , V_61 ;
struct V_89 * V_394 ;
F_167 ( V_278 ) ;
F_193 ( V_278 , struct V_89 , V_234 , V_7 -> V_208 ) ;
F_193 ( V_278 , struct V_238 * , V_395 ,
V_388 ? V_7 -> V_214 + 1 : 0 ) ;
F_193 ( V_278 , struct V_238 * , V_396 ,
V_389 ? V_7 -> V_215 + 1 : 0 ) ;
F_193 ( V_278 , struct V_238 * , V_397 ,
V_390 ? V_7 -> V_216 + 1 : 0 ) ;
F_193 ( V_278 , short , V_398 , V_7 -> V_218 ) ;
F_193 ( V_278 , struct V_358 , V_359 ,
V_380 -> V_220 -> V_399 ? V_7 -> V_218 : 0 ) ;
F_193 ( V_278 , char [ 16 ] , V_400 ,
V_380 -> V_220 -> V_399 ? V_7 -> V_218 : 0 ) ;
F_193 ( V_278 , struct V_401 , V_361 ,
V_380 -> V_220 -> V_399 ? V_7 -> V_218 : 0 ) ;
F_193 ( V_278 , struct V_365 , V_366 ,
V_7 -> V_309 ) ;
F_193 ( V_278 , char , V_367 ,
V_7 -> V_310 ) ;
F_193 ( V_278 , char , V_368 ,
V_7 -> V_311 ) ;
F_193 ( V_278 , char , V_212 , V_7 -> V_213 ) ;
char * V_328 ;
F_20 () ;
if ( F_12 ( ! ( V_388 | V_389 | V_390 ) ) )
return - V_353 ;
V_328 = F_127 ( F_169 ( V_278 ) , V_68 ) ;
if ( F_12 ( ! V_328 ) )
return - V_69 ;
V_7 -> V_369 = F_170 ( V_328 , V_278 , V_366 ) ;
V_7 -> V_371 =
F_170 ( V_328 , V_278 , V_367 ) ;
V_7 -> V_372 =
F_170 ( V_328 , V_278 , V_368 ) ;
memcpy ( F_170 ( V_328 , V_278 , V_212 ) , V_7 -> V_212 ,
V_7 -> V_213 ) ;
memset ( F_170 ( V_328 , V_278 , V_398 ) , 0xff , V_402 ) ;
V_394 = F_170 ( V_328 , V_278 , V_234 ) ;
for ( V_61 = 0 ; V_61 < V_7 -> V_208 ; V_61 ++ )
V_394 [ V_61 ] . V_136 = - 1 ;
V_77 -> V_234 = F_170 ( V_328 , V_278 , V_234 ) ;
V_77 -> V_356 = F_170 ( V_328 , V_278 , V_398 ) ;
if ( F_39 ( V_388 ) ) {
V_77 -> V_4 . V_350 = F_170 ( V_328 , V_278 , V_395 ) ;
V_391 = F_158 ( V_7 -> V_214 ,
F_170 ( V_328 , V_278 , V_212 ) ,
V_403 ,
F_177 , V_77 ) ;
if ( F_12 ( V_391 < 0 ) ) {
V_20 = V_391 ;
goto error;
}
} else {
V_391 = 0 ;
}
if ( F_39 ( V_389 ) ) {
V_77 -> V_4 . V_349 = F_170 ( V_328 , V_278 , V_396 ) ;
V_392 = F_158 ( V_7 -> V_215 ,
F_170 ( V_328 , V_278 , V_212 ) + V_391 ,
V_403 - V_391 ,
F_177 , V_77 ) ;
if ( F_12 ( V_392 < 0 ) ) {
V_20 = V_392 ;
goto error;
}
} else {
V_392 = 0 ;
}
if ( F_39 ( V_390 ) ) {
V_77 -> V_4 . V_348 = F_170 ( V_328 , V_278 , V_397 ) ;
V_393 = F_158 ( V_7 -> V_216 ,
F_170 ( V_328 , V_278 , V_212 ) + V_391 + V_392 ,
V_403 - V_391 - V_392 ,
F_177 , V_77 ) ;
if ( F_12 ( V_393 < 0 ) ) {
V_20 = V_393 ;
goto error;
}
} else {
V_393 = 0 ;
}
V_20 = F_158 ( V_7 -> V_214 +
( V_389 ? V_7 -> V_215 : 0 ) +
( V_390 ? V_7 -> V_216 : 0 ) ,
F_170 ( V_328 , V_278 , V_212 ) , V_403 ,
F_180 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_77 -> V_4 . V_359 = F_170 ( V_328 , V_278 , V_359 ) ;
if ( V_380 -> V_220 -> V_399 ) {
for ( V_61 = 0 ; V_61 < V_7 -> V_218 ; ++ V_61 ) {
struct V_401 * V_140 ;
V_140 = V_77 -> V_4 . V_359 [ V_61 ] . V_361 =
F_170 ( V_328 , V_278 , V_361 ) +
V_61 * sizeof( struct V_401 ) ;
V_140 -> V_362 =
F_170 ( V_328 , V_278 , V_400 ) + V_61 * 16 ;
F_194 ( & V_140 -> V_366 ) ;
}
V_20 = F_162 ( V_7 -> V_322 ,
F_170 ( V_328 , V_278 , V_212 ) +
V_391 + V_392 + V_393 ,
V_403 - V_391 - V_392 -
V_393 ,
F_182 , V_77 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
}
V_77 -> V_4 . V_404 =
V_380 -> V_220 -> V_399 ? V_7 -> V_218 : 0 ;
F_175 ( V_7 , V_338 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_195 ( struct V_379 * V_380 ,
struct V_2 * V_3 )
{
struct V_378 * V_381 = F_187 ( V_3 , V_380 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_20 ;
if ( F_23 ( V_381 ) )
return F_24 ( V_381 ) ;
V_20 = F_190 ( V_380 , V_3 ) ;
if ( V_20 && ! -- V_381 -> V_387 )
F_138 ( V_77 -> V_7 ) ;
return V_20 ;
}
static void F_196 ( struct V_94 * V_95 )
{
struct V_6 * V_7 = F_2 ( V_95 ,
struct V_6 , V_405 ) ;
F_120 ( V_7 ) ;
}
static int F_197 ( struct V_2 * V_3 ,
unsigned V_303 , unsigned V_406 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
int V_20 = 0 , V_407 ;
if ( V_406 != ( unsigned ) - 1 ) {
V_407 = F_46 ( V_77 , V_303 ) ;
if ( F_12 ( V_407 < 0 ) )
return V_407 ;
}
if ( V_7 -> V_77 )
F_143 ( V_7 -> V_77 ) ;
if ( V_7 -> V_45 == V_87 ) {
V_7 -> V_45 = V_49 ;
F_61 ( & V_7 -> V_405 , F_196 ) ;
F_62 ( & V_7 -> V_405 ) ;
return - V_78 ;
}
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
if ( V_406 == ( unsigned ) - 1 ) {
V_7 -> V_77 = NULL ;
F_175 ( V_7 , V_340 ) ;
return 0 ;
}
V_7 -> V_77 = V_77 ;
V_20 = F_148 ( V_77 ) ;
if ( F_39 ( V_20 >= 0 ) )
F_175 ( V_7 , V_341 ) ;
return V_20 ;
}
static void F_198 ( struct V_2 * V_3 )
{
F_197 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_199 ( struct V_2 * V_3 ,
const struct V_408 * V_409 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
unsigned long V_198 ;
int V_20 ;
F_20 () ;
F_16 ( L_56 , V_409 -> V_53 ) ;
F_16 ( L_57 , V_409 -> V_410 ) ;
F_16 ( L_58 , F_8 ( V_409 -> V_411 ) ) ;
F_16 ( L_59 , F_8 ( V_409 -> V_288 ) ) ;
F_16 ( L_60 , F_8 ( V_409 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_78 ;
switch ( V_409 -> V_53 & V_412 ) {
case V_413 :
V_20 = F_46 ( V_77 , F_8 ( V_409 -> V_288 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_414 :
V_20 = F_200 ( V_77 , F_8 ( V_409 -> V_288 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_77 -> V_7 -> V_230 & V_231 )
V_20 = V_77 -> V_7 -> V_232 [ V_20 ] ;
break;
default:
return - V_415 ;
}
F_145 ( & V_7 -> V_22 . V_25 . V_26 , V_198 ) ;
V_7 -> V_22 . V_23 = * V_409 ;
V_7 -> V_22 . V_23 . V_288 = F_201 ( V_20 ) ;
F_173 ( V_7 , V_62 ) ;
F_147 ( & V_7 -> V_22 . V_25 . V_26 , V_198 ) ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 )
{
F_20 () ;
F_175 ( F_1 ( V_3 ) -> V_7 , V_337 ) ;
}
static void F_203 ( struct V_2 * V_3 )
{
F_20 () ;
F_175 ( F_1 ( V_3 ) -> V_7 , V_336 ) ;
}
static int F_200 ( struct V_1 * V_77 , T_8 V_136 )
{
V_136 = V_77 -> V_354 [ V_136 & V_351 ] ;
return V_136 ? V_136 : - V_416 ;
}
static int F_46 ( struct V_1 * V_77 , T_8 V_407 )
{
short * V_417 = V_77 -> V_356 ;
unsigned V_64 = V_77 -> V_7 -> V_218 ;
for (; V_64 ; -- V_64 , ++ V_417 ) {
if ( * V_417 >= 0 && * V_417 == V_407 )
return V_417 - V_77 -> V_356 ;
}
return - V_416 ;
}
static struct V_203 * F_204 ( const char * V_169 )
{
struct V_203 * V_385 ;
F_205 (dev, &ffs_devices, entry) {
if ( ! V_385 -> V_169 || ! V_169 )
continue;
if ( strcmp ( V_385 -> V_169 , V_169 ) == 0 )
return V_385 ;
}
return NULL ;
}
static struct V_203 * F_206 ( void )
{
struct V_203 * V_385 ;
if ( F_207 ( & V_418 ) ) {
V_385 = F_208 ( & V_418 , struct V_203 , V_377 ) ;
if ( V_385 -> V_419 )
return V_385 ;
}
return NULL ;
}
static struct V_203 * F_209 ( const char * V_169 )
{
struct V_203 * V_385 ;
V_385 = F_206 () ;
if ( V_385 )
return V_385 ;
return F_204 ( V_169 ) ;
}
static inline struct V_378 * F_210 ( struct V_420 * V_421 )
{
return F_2 ( F_211 ( V_421 ) , struct V_378 ,
V_383 . V_422 ) ;
}
static void F_212 ( struct V_420 * V_421 )
{
struct V_378 * V_189 = F_210 ( V_421 ) ;
F_213 ( & V_189 -> V_383 ) ;
}
static void F_214 ( struct V_423 * V_3 )
{
struct V_378 * V_189 ;
V_189 = F_215 ( V_3 ) ;
F_188 () ;
F_216 ( V_189 -> V_385 ) ;
F_189 () ;
F_33 ( V_189 ) ;
}
static int F_217 ( struct V_423 * V_382 , const char * V_169 )
{
struct V_378 * V_189 ;
char * V_39 ;
const char * V_424 ;
int V_370 , V_20 ;
V_370 = strlen ( V_169 ) + 1 ;
if ( V_370 > V_425 )
return - V_426 ;
V_39 = F_218 ( V_169 , V_370 , V_68 ) ;
if ( ! V_39 )
return - V_69 ;
V_189 = F_215 ( V_382 ) ;
V_424 = NULL ;
F_188 () ;
V_424 = V_189 -> V_385 -> V_427 ? V_189 -> V_385 -> V_169 : NULL ;
V_20 = F_219 ( V_189 -> V_385 , V_39 ) ;
if ( V_20 ) {
F_33 ( V_39 ) ;
F_189 () ;
return V_20 ;
}
V_189 -> V_385 -> V_427 = true ;
F_189 () ;
F_33 ( V_424 ) ;
return 0 ;
}
static struct V_423 * F_220 ( void )
{
struct V_378 * V_189 ;
struct V_203 * V_385 ;
V_189 = F_127 ( sizeof( * V_189 ) , V_68 ) ;
if ( ! V_189 )
return F_103 ( - V_69 ) ;
V_189 -> V_383 . V_428 = F_217 ;
V_189 -> V_383 . V_429 = F_214 ;
F_188 () ;
V_385 = F_221 () ;
F_189 () ;
if ( F_23 ( V_385 ) ) {
F_33 ( V_189 ) ;
return F_108 ( V_385 ) ;
}
V_189 -> V_385 = V_385 ;
V_385 -> V_189 = V_189 ;
F_222 ( & V_189 -> V_383 . V_422 , L_61 ,
& V_430 ) ;
return & V_189 -> V_383 ;
}
static void F_223 ( struct V_2 * V_3 )
{
F_33 ( F_1 ( V_3 ) ) ;
}
static void F_224 ( struct V_379 * V_380 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_378 * V_189 =
F_2 ( V_3 -> V_382 , struct V_378 , V_383 ) ;
struct V_89 * V_12 = V_77 -> V_234 ;
unsigned V_64 = V_7 -> V_208 ;
unsigned long V_198 ;
F_20 () ;
if ( V_7 -> V_77 == V_77 ) {
F_143 ( V_77 ) ;
V_7 -> V_77 = NULL ;
}
if ( ! -- V_189 -> V_387 )
F_138 ( V_7 ) ;
F_145 ( & V_77 -> V_7 -> V_117 , V_198 ) ;
do {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_59 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
} while ( -- V_64 );
F_147 ( & V_77 -> V_7 -> V_117 , V_198 ) ;
F_33 ( V_77 -> V_234 ) ;
V_77 -> V_234 = NULL ;
V_77 -> V_4 . V_350 = NULL ;
V_77 -> V_4 . V_349 = NULL ;
V_77 -> V_4 . V_348 = NULL ;
V_77 -> V_356 = NULL ;
F_175 ( V_7 , V_339 ) ;
}
static struct V_2 * F_225 ( struct V_423 * V_382 )
{
struct V_1 * V_77 ;
F_20 () ;
V_77 = F_127 ( sizeof( * V_77 ) , V_68 ) ;
if ( F_12 ( ! V_77 ) )
return F_103 ( - V_69 ) ;
V_77 -> V_4 . V_169 = L_62 ;
V_77 -> V_4 . V_431 = F_195 ;
V_77 -> V_4 . V_432 = F_224 ;
V_77 -> V_4 . V_433 = F_197 ;
V_77 -> V_4 . V_434 = F_198 ;
V_77 -> V_4 . V_23 = F_199 ;
V_77 -> V_4 . V_435 = F_202 ;
V_77 -> V_4 . V_436 = F_203 ;
V_77 -> V_4 . V_437 = F_223 ;
return & V_77 -> V_4 ;
}
static struct V_203 * F_221 ( void )
{
struct V_203 * V_385 ;
int V_20 ;
if ( F_206 () )
return F_103 ( - V_72 ) ;
V_385 = F_127 ( sizeof( * V_385 ) , V_68 ) ;
if ( ! V_385 )
return F_103 ( - V_69 ) ;
if ( F_226 ( & V_418 ) ) {
V_20 = F_113 () ;
if ( V_20 ) {
F_33 ( V_385 ) ;
return F_103 ( V_20 ) ;
}
}
F_227 ( & V_385 -> V_377 , & V_418 ) ;
return V_385 ;
}
static int F_219 ( struct V_203 * V_385 , const char * V_169 )
{
struct V_203 * V_438 ;
V_438 = F_204 ( V_169 ) ;
if ( V_438 )
return - V_72 ;
V_385 -> V_169 = V_169 ;
return 0 ;
}
int F_228 ( struct V_203 * V_385 , const char * V_169 )
{
int V_20 ;
F_188 () ;
V_20 = F_219 ( V_385 , V_169 ) ;
F_189 () ;
return V_20 ;
}
int F_229 ( struct V_203 * V_385 )
{
int V_20 ;
V_20 = 0 ;
F_188 () ;
if ( ! F_207 ( & V_418 ) )
V_20 = - V_72 ;
else
V_385 -> V_419 = true ;
F_189 () ;
return V_20 ;
}
static void F_216 ( struct V_203 * V_385 )
{
F_230 ( & V_385 -> V_377 ) ;
if ( V_385 -> V_427 )
F_33 ( V_385 -> V_169 ) ;
F_33 ( V_385 ) ;
if ( F_226 ( & V_418 ) )
F_115 () ;
}
static void * F_107 ( const char * V_199 )
{
struct V_203 * V_203 ;
F_20 () ;
F_188 () ;
V_203 = F_209 ( V_199 ) ;
if ( ! V_203 )
V_203 = F_103 ( - V_344 ) ;
else if ( V_203 -> V_439 )
V_203 = F_103 ( - V_72 ) ;
else if ( V_203 -> V_440 &&
V_203 -> V_440 ( V_203 ) )
V_203 = F_103 ( - V_344 ) ;
else
V_203 -> V_439 = true ;
F_189 () ;
return V_203 ;
}
static void F_110 ( struct V_6 * V_6 )
{
struct V_203 * V_203 ;
F_20 () ;
F_188 () ;
V_203 = V_6 -> V_40 ;
if ( V_203 ) {
V_203 -> V_439 = false ;
if ( V_203 -> V_441 )
V_203 -> V_441 ( V_203 ) ;
}
F_189 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_203 * V_442 ;
int V_20 = 0 ;
F_20 () ;
F_188 () ;
V_442 = V_7 -> V_40 ;
if ( ! V_442 ) {
V_20 = - V_48 ;
goto V_122;
}
if ( F_67 ( V_442 -> V_386 ) ) {
V_20 = - V_72 ;
goto V_122;
}
V_442 -> V_386 = true ;
V_442 -> V_6 = V_7 ;
if ( V_442 -> V_443 ) {
V_20 = V_442 -> V_443 ( V_7 ) ;
if ( V_20 )
goto V_122;
}
F_231 ( V_444 , & V_7 -> V_198 ) ;
V_122:
F_189 () ;
return V_20 ;
}
static void F_133 ( struct V_6 * V_7 )
{
struct V_203 * V_442 ;
struct V_378 * V_189 ;
F_20 () ;
F_188 () ;
V_442 = V_7 -> V_40 ;
if ( ! V_442 )
goto V_122;
V_442 -> V_386 = false ;
if ( F_232 ( V_444 , & V_7 -> V_198 ) &&
V_442 -> V_445 )
V_442 -> V_445 ( V_7 ) ;
if ( V_442 -> V_189 )
V_189 = V_442 -> V_189 ;
else
goto V_122;
if ( V_189 -> V_384 || ! V_189 -> V_383 . V_422 . V_446 . V_447
|| ! F_126 ( & V_189 -> V_383 . V_422 . V_446 . V_448 . V_449 ) )
goto V_122;
F_233 ( V_442 -> V_189 ->
V_383 . V_422 . V_446 . V_447 -> V_447 ) ;
V_122:
F_189 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_450 )
{
return V_450
? F_39 ( F_234 ( V_42 ) ) ? 0 : - V_67
: F_235 ( V_42 ) ;
}
static char * F_22 ( const char T_3 * V_27 , T_1 V_18 )
{
char * V_17 ;
if ( F_12 ( ! V_18 ) )
return NULL ;
V_17 = F_40 ( V_18 , V_68 ) ;
if ( F_12 ( ! V_17 ) )
return F_103 ( - V_69 ) ;
if ( F_12 ( F_236 ( V_17 , V_27 , V_18 ) ) ) {
F_33 ( V_17 ) ;
return F_103 ( - V_65 ) ;
}
F_16 ( L_63 ) ;
F_178 ( L_61 , V_17 , V_18 ) ;
return V_17 ;
}
