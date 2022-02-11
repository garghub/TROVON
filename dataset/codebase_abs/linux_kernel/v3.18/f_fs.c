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
struct V_59 V_60 [ V_58 ] ;
unsigned V_61 = 0 ;
memset ( V_60 , 0 , sizeof V_60 ) ;
do {
V_60 [ V_61 ] . type = V_7 -> V_22 . V_62 [ V_61 ] ;
if ( V_60 [ V_61 ] . type == V_63 ) {
V_60 [ V_61 ] . V_64 . V_23 = V_7 -> V_22 . V_23 ;
V_7 -> V_8 = V_54 ;
}
} while ( ++ V_61 < V_58 );
if ( V_58 < V_7 -> V_22 . V_65 ) {
V_7 -> V_22 . V_65 -= V_58 ;
memmove ( V_7 -> V_22 . V_62 , V_7 -> V_22 . V_62 + V_58 ,
V_7 -> V_22 . V_65 * sizeof * V_7 -> V_22 . V_62 ) ;
} else {
V_7 -> V_22 . V_65 = 0 ;
}
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
F_29 ( & V_7 -> V_42 ) ;
return F_12 ( F_36 ( V_27 , V_60 , sizeof V_60 ) )
? - V_66 : sizeof V_60 ;
}
static T_2 F_37 ( struct V_38 * V_38 , char T_3 * V_27 ,
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
goto V_67;
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
if ( ( V_38 -> V_43 & V_44 ) && ! V_7 -> V_22 . V_65 ) {
V_20 = - V_68 ;
break;
}
if ( F_38 ( V_7 -> V_22 . V_25 ,
V_7 -> V_22 . V_65 ) ) {
V_20 = - V_32 ;
break;
}
return F_35 ( V_7 , V_27 ,
F_33 ( V_58 , ( T_1 ) V_7 -> V_22 . V_65 ) ) ;
case V_54 :
if ( V_7 -> V_22 . V_23 . V_55 & V_56 ) {
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_20 = F_15 ( V_7 ) ;
goto V_67;
}
V_18 = F_33 ( V_18 , ( T_1 ) F_8 ( V_7 -> V_22 . V_23 . V_24 ) ) ;
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_39 ( V_18 ) ) {
V_17 = F_40 ( V_18 , V_69 ) ;
if ( F_12 ( ! V_17 ) ) {
V_20 = - V_70 ;
goto V_67;
}
}
F_32 ( & V_7 -> V_22 . V_25 . V_26 ) ;
if ( F_3 ( V_7 ) ==
V_9 ) {
V_20 = - V_41 ;
break;
}
V_20 = F_7 ( V_7 , V_17 , V_18 ) ;
if ( F_39 ( V_20 > 0 ) && F_12 ( F_36 ( V_27 , V_17 , V_18 ) ) )
V_20 = - V_66 ;
goto V_67;
default:
V_20 = - V_57 ;
break;
}
F_9 ( & V_7 -> V_22 . V_25 . V_26 ) ;
V_67:
F_29 ( & V_7 -> V_42 ) ;
F_34 ( V_17 ) ;
return V_20 ;
}
static int F_41 ( struct V_71 * V_71 , struct V_38 * V_38 )
{
struct V_6 * V_7 = V_71 -> V_72 ;
F_20 () ;
if ( F_12 ( V_7 -> V_45 == V_49 ) )
return - V_73 ;
V_38 -> V_40 = V_7 ;
F_42 ( V_7 ) ;
return 0 ;
}
static int F_43 ( struct V_71 * V_71 , struct V_38 * V_38 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
F_20 () ;
F_44 ( V_7 ) ;
return 0 ;
}
static long F_45 ( struct V_38 * V_38 , unsigned V_74 , unsigned long V_75 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
struct V_76 * V_29 = V_7 -> V_29 ;
long V_20 ;
F_20 () ;
if ( V_74 == V_77 ) {
struct V_1 * V_78 = V_7 -> V_78 ;
V_20 = V_78 ? F_46 ( V_78 , V_75 ) : - V_79 ;
} else if ( V_29 && V_29 -> V_80 -> V_81 ) {
V_20 = V_29 -> V_80 -> V_81 ( V_29 , V_74 , V_75 ) ;
} else {
V_20 = - V_82 ;
}
return V_20 ;
}
static unsigned int F_47 ( struct V_38 * V_38 , T_5 * V_83 )
{
struct V_6 * V_7 = V_38 -> V_40 ;
unsigned int V_84 = V_85 ;
int V_20 ;
F_48 ( V_38 , & V_7 -> V_22 . V_25 , V_83 ) ;
V_20 = F_21 ( & V_7 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 < 0 ) )
return V_84 ;
switch ( V_7 -> V_45 ) {
case V_46 :
case V_47 :
V_84 |= V_86 ;
break;
case V_50 :
switch ( V_7 -> V_8 ) {
case V_10 :
if ( V_7 -> V_22 . V_65 )
V_84 |= V_87 ;
break;
case V_54 :
case V_9 :
V_84 |= ( V_87 | V_86 ) ;
break;
}
case V_49 :
break;
}
F_29 ( & V_7 -> V_42 ) ;
return V_84 ;
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
int V_61 ;
T_1 V_96 = 0 ;
V_20 = F_52 ( int , V_20 , V_94 -> V_18 ) ;
F_53 ( V_94 -> V_97 ) ;
for ( V_61 = 0 ; V_61 < V_94 -> V_98 ; V_61 ++ ) {
T_1 V_18 = F_52 ( T_1 , V_20 - V_96 ,
V_94 -> V_99 [ V_61 ] . V_100 ) ;
if ( ! V_18 )
break;
if ( F_12 ( F_54 ( V_94 -> V_99 [ V_61 ] . V_101 ,
& V_94 -> V_27 [ V_96 ] , V_18 ) ) ) {
V_20 = - V_66 ;
break;
}
V_96 += V_18 ;
}
F_55 ( V_94 -> V_97 ) ;
}
F_56 ( V_94 -> V_102 , V_20 , V_20 ) ;
F_57 ( V_94 -> V_12 , V_94 -> V_14 ) ;
V_94 -> V_102 -> V_103 = NULL ;
if ( V_94 -> V_95 )
F_34 ( V_94 -> V_99 ) ;
F_34 ( V_94 -> V_27 ) ;
F_34 ( V_94 ) ;
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
V_20 = - V_79 ;
goto error;
}
V_12 = V_105 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 ) {
V_20 = - V_68 ;
goto error;
}
V_20 = F_63 ( V_105 -> V_83 , ( V_12 = V_105 -> V_12 ) ) ;
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
struct V_76 * V_29 = V_105 -> V_7 -> V_29 ;
F_32 ( & V_105 -> V_7 -> V_110 ) ;
if ( V_105 -> V_12 != V_12 ) {
F_9 ( & V_105 -> V_7 -> V_110 ) ;
return - V_111 ;
}
V_106 = V_94 -> V_95 ?
F_64 ( V_29 , V_12 -> V_12 , V_94 -> V_18 ) :
V_94 -> V_18 ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
V_17 = F_40 ( V_106 , V_69 ) ;
if ( F_12 ( ! V_17 ) )
return - V_70 ;
if ( V_94 -> V_112 && ! V_94 -> V_95 ) {
int V_61 ;
T_1 V_96 = 0 ;
for ( V_61 = 0 ; V_61 < V_94 -> V_98 ; V_61 ++ ) {
if ( F_12 ( F_65 ( & V_17 [ V_96 ] ,
V_94 -> V_99 [ V_61 ] . V_101 ,
V_94 -> V_99 [ V_61 ] . V_100 ) ) ) {
V_20 = - V_66 ;
goto error;
}
V_96 += V_94 -> V_99 [ V_61 ] . V_100 ;
}
} else {
if ( ! V_94 -> V_95 &&
F_12 ( F_66 ( V_17 , V_94 -> V_27 ,
V_94 -> V_18 ) ) ) {
V_20 = - V_66 ;
goto error;
}
}
}
V_20 = F_21 ( & V_105 -> V_42 , V_38 -> V_43 & V_44 ) ;
if ( F_12 ( V_20 ) )
goto error;
F_32 ( & V_105 -> V_7 -> V_110 ) ;
if ( V_105 -> V_12 != V_12 ) {
V_20 = - V_111 ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
} else if ( V_107 ) {
if ( F_39 ( V_105 -> V_12 == V_12 ) && ! F_62 ( ! V_12 -> V_12 ) )
F_17 ( V_12 -> V_12 ) ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
V_20 = - V_113 ;
} else {
struct V_13 * V_14 ;
if ( F_12 ( V_106 == - V_48 ) ) {
F_67 ( 1 , L_5 , V_114 ) ;
V_20 = - V_48 ;
goto V_115;
}
if ( V_94 -> V_112 ) {
V_14 = F_68 ( V_12 -> V_12 , V_69 ) ;
if ( F_12 ( ! V_14 ) )
goto V_115;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_106 ;
V_94 -> V_27 = V_17 ;
V_94 -> V_12 = V_12 -> V_12 ;
V_94 -> V_14 = V_14 ;
V_14 -> V_15 = V_94 ;
V_14 -> F_50 = F_58 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 ) ) {
F_57 ( V_12 -> V_12 , V_14 ) ;
goto V_115;
}
V_20 = - V_116 ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
} else {
F_69 ( V_117 ) ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_106 ;
V_14 -> V_15 = & V_117 ;
V_14 -> F_50 = F_49 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
if ( F_12 ( V_20 < 0 ) ) {
} else if ( F_12 (
F_13 ( & V_117 ) ) ) {
V_20 = - V_32 ;
F_14 ( V_12 -> V_12 , V_14 ) ;
} else {
V_20 = V_12 -> V_33 ;
if ( V_94 -> V_95 && V_20 > 0 ) {
V_20 = F_52 ( T_1 , V_20 , V_94 -> V_18 ) ;
if ( F_12 ( F_54 ( V_94 -> V_27 ,
V_17 , V_20 ) ) )
V_20 = - V_66 ;
}
}
F_34 ( V_17 ) ;
}
}
F_29 ( & V_105 -> V_42 ) ;
return V_20 ;
V_115:
F_9 ( & V_105 -> V_7 -> V_110 ) ;
F_29 ( & V_105 -> V_42 ) ;
error:
F_34 ( V_17 ) ;
return V_20 ;
}
static T_2
F_70 ( struct V_38 * V_38 , const char T_3 * V_27 , T_1 V_18 ,
T_4 * V_39 )
{
struct V_93 V_94 ;
F_20 () ;
V_94 . V_112 = false ;
V_94 . V_95 = false ;
V_94 . V_27 = ( char * T_3 ) V_27 ;
V_94 . V_18 = V_18 ;
return F_61 ( V_38 , & V_94 ) ;
}
static T_2
F_71 ( struct V_38 * V_38 , char T_3 * V_27 , T_1 V_18 , T_4 * V_39 )
{
struct V_93 V_94 ;
F_20 () ;
V_94 . V_112 = false ;
V_94 . V_95 = true ;
V_94 . V_27 = V_27 ;
V_94 . V_18 = V_18 ;
return F_61 ( V_38 , & V_94 ) ;
}
static int
F_72 ( struct V_71 * V_71 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_71 -> V_72 ;
F_20 () ;
if ( F_62 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_79 ;
V_38 -> V_40 = V_105 ;
F_42 ( V_105 -> V_7 ) ;
return 0 ;
}
static int F_73 ( struct V_102 * V_102 )
{
struct V_93 * V_94 = V_102 -> V_103 ;
struct V_104 * V_105 = V_102 -> V_118 -> V_40 ;
int V_75 ;
F_20 () ;
F_32 ( & V_105 -> V_7 -> V_110 ) ;
if ( F_39 ( V_94 && V_94 -> V_12 && V_94 -> V_14 ) )
V_75 = F_14 ( V_94 -> V_12 , V_94 -> V_14 ) ;
else
V_75 = - V_48 ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
return V_75 ;
}
static T_2 F_74 ( struct V_102 * V_102 ,
const struct V_99 * V_99 ,
unsigned long V_98 , T_4 V_119 )
{
struct V_93 * V_94 ;
F_20 () ;
V_94 = F_40 ( sizeof( * V_94 ) , V_69 ) ;
if ( F_12 ( ! V_94 ) )
return - V_70 ;
V_94 -> V_112 = true ;
V_94 -> V_95 = false ;
V_94 -> V_102 = V_102 ;
V_94 -> V_99 = V_99 ;
V_94 -> V_98 = V_98 ;
V_94 -> V_18 = V_102 -> V_120 ;
V_94 -> V_97 = V_121 -> V_97 ;
V_102 -> V_103 = V_94 ;
F_75 ( V_102 , F_73 ) ;
return F_61 ( V_102 -> V_118 , V_94 ) ;
}
static T_2 F_76 ( struct V_102 * V_102 ,
const struct V_99 * V_99 ,
unsigned long V_98 , T_4 V_119 )
{
struct V_93 * V_94 ;
struct V_99 * V_122 ;
F_20 () ;
V_122 = F_77 ( V_98 , sizeof( * V_122 ) , V_69 ) ;
if ( F_12 ( ! V_122 ) )
return - V_70 ;
memcpy ( V_122 , V_99 , sizeof( struct V_99 ) * V_98 ) ;
V_94 = F_40 ( sizeof( * V_94 ) , V_69 ) ;
if ( F_12 ( ! V_94 ) ) {
F_34 ( V_122 ) ;
return - V_70 ;
}
V_94 -> V_112 = true ;
V_94 -> V_95 = true ;
V_94 -> V_102 = V_102 ;
V_94 -> V_99 = V_122 ;
V_94 -> V_98 = V_98 ;
V_94 -> V_18 = V_102 -> V_120 ;
V_94 -> V_97 = V_121 -> V_97 ;
V_102 -> V_103 = V_94 ;
F_75 ( V_102 , F_73 ) ;
return F_61 ( V_102 -> V_118 , V_94 ) ;
}
static int
F_78 ( struct V_71 * V_71 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_71 -> V_72 ;
F_20 () ;
F_44 ( V_105 -> V_7 ) ;
return 0 ;
}
static long F_79 ( struct V_38 * V_38 , unsigned V_74 ,
unsigned long V_75 )
{
struct V_104 * V_105 = V_38 -> V_40 ;
int V_20 ;
F_20 () ;
if ( F_62 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_79 ;
F_32 ( & V_105 -> V_7 -> V_110 ) ;
if ( F_39 ( V_105 -> V_12 ) ) {
switch ( V_74 ) {
case V_123 :
V_20 = F_80 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_124 :
F_81 ( V_105 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_125 :
V_20 = F_82 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_126 :
V_20 = V_105 -> V_12 -> V_127 ;
break;
case V_128 :
{
int V_129 ;
struct V_130 * V_131 ;
switch ( V_105 -> V_7 -> V_29 -> V_132 ) {
case V_133 :
V_129 = 2 ;
break;
case V_134 :
V_129 = 1 ;
break;
default:
V_129 = 0 ;
}
V_131 = V_105 -> V_12 -> V_135 [ V_129 ] ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
V_20 = F_54 ( ( void * ) V_75 , V_131 , sizeof( * V_131 ) ) ;
if ( V_20 )
V_20 = - V_66 ;
return V_20 ;
}
default:
V_20 = - V_82 ;
}
} else {
V_20 = - V_79 ;
}
F_9 ( & V_105 -> V_7 -> V_110 ) ;
return V_20 ;
}
static struct V_71 * T_6
F_83 ( struct V_136 * V_137 , void * V_17 ,
const struct V_138 * V_139 ,
const struct V_140 * V_141 ,
struct V_142 * V_143 )
{
struct V_71 * V_71 ;
F_20 () ;
V_71 = F_84 ( V_137 ) ;
if ( F_39 ( V_71 ) ) {
struct V_144 V_145 = V_146 ;
V_71 -> V_147 = F_85 () ;
V_71 -> V_148 = V_143 -> V_149 ;
V_71 -> V_150 = V_143 -> V_151 ;
V_71 -> V_152 = V_143 -> V_153 ;
V_71 -> V_154 = V_145 ;
V_71 -> V_155 = V_145 ;
V_71 -> V_156 = V_145 ;
V_71 -> V_72 = V_17 ;
if ( V_139 )
V_71 -> V_157 = V_139 ;
if ( V_141 )
V_71 -> V_158 = V_141 ;
}
return V_71 ;
}
static struct V_159 * F_86 ( struct V_136 * V_137 ,
const char * V_160 , void * V_17 ,
const struct V_138 * V_139 )
{
struct V_6 * V_7 = V_137 -> V_161 ;
struct V_159 * V_159 ;
struct V_71 * V_71 ;
F_20 () ;
V_159 = F_87 ( V_137 -> V_162 , V_160 ) ;
if ( F_12 ( ! V_159 ) )
return NULL ;
V_71 = F_83 ( V_137 , V_17 , V_139 , NULL , & V_7 -> V_163 ) ;
if ( F_12 ( ! V_71 ) ) {
F_88 ( V_159 ) ;
return NULL ;
}
F_89 ( V_159 , V_71 ) ;
return V_159 ;
}
static int F_90 ( struct V_136 * V_137 , void * V_164 , int V_165 )
{
struct V_166 * V_17 = V_164 ;
struct V_71 * V_71 ;
struct V_6 * V_7 = V_17 -> V_6 ;
F_20 () ;
V_7 -> V_137 = V_137 ;
V_17 -> V_6 = NULL ;
V_137 -> V_161 = V_7 ;
V_137 -> V_167 = V_168 ;
V_137 -> V_169 = V_170 ;
V_137 -> V_171 = V_172 ;
V_137 -> V_173 = & V_174 ;
V_137 -> V_175 = 1 ;
V_17 -> V_143 . V_149 = V_17 -> V_176 ;
V_71 = F_83 ( V_137 , NULL ,
& V_177 ,
& V_178 ,
& V_17 -> V_143 ) ;
V_137 -> V_162 = F_91 ( V_71 ) ;
if ( F_12 ( ! V_137 -> V_162 ) )
return - V_70 ;
if ( F_12 ( ! F_86 ( V_137 , L_6 , V_7 ,
& V_179 ) ) )
return - V_70 ;
return 0 ;
}
static int F_92 ( struct V_166 * V_17 , char * V_180 )
{
F_20 () ;
if ( ! V_180 || ! * V_180 )
return 0 ;
for (; ; ) {
unsigned long V_75 ;
char * V_181 , * V_182 ;
V_182 = strchr ( V_180 , ',' ) ;
if ( V_182 )
* V_182 = 0 ;
V_181 = strchr ( V_180 , '=' ) ;
if ( F_12 ( ! V_181 ) ) {
F_93 ( L_7 , V_180 ) ;
return - V_48 ;
}
* V_181 = 0 ;
if ( F_94 ( V_181 + 1 , 0 , & V_75 ) ) {
F_93 ( L_8 , V_180 , V_181 + 1 ) ;
return - V_48 ;
}
switch ( V_181 - V_180 ) {
case 5 :
if ( ! memcmp ( V_180 , L_9 , 5 ) )
V_17 -> V_176 = ( V_75 & 0555 ) | V_183 ;
else if ( ! memcmp ( V_180 , L_10 , 5 ) )
V_17 -> V_143 . V_149 = ( V_75 & 0666 ) | V_184 ;
else
goto V_185;
break;
case 4 :
if ( ! memcmp ( V_180 , L_11 , 4 ) ) {
V_17 -> V_176 = ( V_75 & 0555 ) | V_183 ;
V_17 -> V_143 . V_149 = ( V_75 & 0666 ) | V_184 ;
} else {
goto V_185;
}
break;
case 3 :
if ( ! memcmp ( V_180 , L_12 , 3 ) ) {
V_17 -> V_143 . V_151 = F_95 ( F_96 () , V_75 ) ;
if ( ! F_97 ( V_17 -> V_143 . V_151 ) ) {
F_93 ( L_13 , V_180 , V_75 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_180 , L_14 , 3 ) ) {
V_17 -> V_143 . V_153 = F_98 ( F_96 () , V_75 ) ;
if ( ! F_99 ( V_17 -> V_143 . V_153 ) ) {
F_93 ( L_13 , V_180 , V_75 ) ;
return - V_48 ;
}
} else {
goto V_185;
}
break;
default:
V_185:
F_93 ( L_15 , V_180 ) ;
return - V_48 ;
}
if ( ! V_182 )
break;
V_180 = V_182 + 1 ;
}
return 0 ;
}
static struct V_159 *
F_100 ( struct V_186 * V_187 , int V_52 ,
const char * V_188 , void * V_180 )
{
struct V_166 V_17 = {
. V_143 = {
. V_149 = V_184 | 0600 ,
. V_151 = V_189 ,
. V_153 = V_190 ,
} ,
. V_176 = V_183 | 0500 ,
} ;
struct V_159 * V_191 ;
int V_20 ;
void * V_192 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_92 ( & V_17 , V_180 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_101 ( V_20 ) ;
V_7 = F_102 () ;
if ( F_12 ( ! V_7 ) )
return F_101 ( - V_70 ) ;
V_7 -> V_163 = V_17 . V_143 ;
V_7 -> V_188 = F_103 ( V_188 , V_69 ) ;
if ( F_12 ( ! V_7 -> V_188 ) ) {
F_104 ( V_7 ) ;
return F_101 ( - V_70 ) ;
}
V_192 = F_105 ( V_188 ) ;
if ( F_23 ( V_192 ) ) {
F_104 ( V_7 ) ;
return F_106 ( V_192 ) ;
}
V_7 -> V_40 = V_192 ;
V_17 . V_6 = V_7 ;
V_191 = F_107 ( V_187 , V_52 , & V_17 , F_90 ) ;
if ( F_23 ( V_191 ) && V_17 . V_6 ) {
F_108 ( V_17 . V_6 ) ;
F_104 ( V_17 . V_6 ) ;
}
return V_191 ;
}
static void
F_109 ( struct V_136 * V_137 )
{
F_20 () ;
F_110 ( V_137 ) ;
if ( V_137 -> V_161 ) {
F_108 ( V_137 -> V_161 ) ;
F_104 ( V_137 -> V_161 ) ;
}
}
static int F_111 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_112 ( & V_193 ) ;
if ( F_39 ( ! V_20 ) )
F_25 ( L_16 ) ;
else
F_93 ( L_17 , V_20 ) ;
return V_20 ;
}
static void F_113 ( void )
{
F_20 () ;
F_25 ( L_18 ) ;
F_114 ( & V_193 ) ;
}
static void F_115 ( struct V_6 * V_7 )
{
F_20 () ;
F_116 ( & V_7 -> V_194 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_20 () ;
F_116 ( & V_7 -> V_194 ) ;
F_116 ( & V_7 -> V_195 ) ;
}
static void F_104 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_117 ( & V_7 -> V_194 ) ) ) {
F_25 ( L_19 , V_114 ) ;
F_118 ( V_7 ) ;
F_119 ( F_120 ( & V_7 -> V_22 . V_25 ) ||
F_120 ( & V_7 -> V_16 . V_83 ) ) ;
F_34 ( V_7 -> V_188 ) ;
F_34 ( V_7 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_117 ( & V_7 -> V_195 ) ) {
V_7 -> V_45 = V_49 ;
F_121 ( V_7 ) ;
}
F_104 ( V_7 ) ;
}
static struct V_6 * F_102 ( void )
{
struct V_6 * V_7 = F_122 ( sizeof *V_7 , V_69 ) ;
if ( F_12 ( ! V_7 ) )
return NULL ;
F_20 () ;
F_123 ( & V_7 -> V_194 , 1 ) ;
F_123 ( & V_7 -> V_195 , 0 ) ;
V_7 -> V_45 = V_46 ;
F_124 ( & V_7 -> V_42 ) ;
F_125 ( & V_7 -> V_110 ) ;
F_126 ( & V_7 -> V_22 . V_25 ) ;
F_127 ( & V_7 -> V_16 ) ;
V_7 -> V_22 . V_35 = 1 ;
return V_7 ;
}
static void F_118 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_128 ( V_51 , & V_7 -> V_52 ) )
F_129 ( V_7 ) ;
F_119 ( V_7 -> V_29 ) ;
if ( V_7 -> V_196 )
F_130 ( V_7 -> V_196 , V_7 -> V_197 ) ;
F_34 ( V_7 -> V_198 ) ;
F_34 ( V_7 -> V_199 ) ;
F_34 ( V_7 -> V_200 ) ;
}
static void F_121 ( struct V_6 * V_7 )
{
F_20 () ;
F_118 ( V_7 ) ;
V_7 -> V_196 = NULL ;
V_7 -> V_198 = NULL ;
V_7 -> V_201 = NULL ;
V_7 -> V_199 = NULL ;
V_7 -> V_200 = NULL ;
V_7 -> V_202 = 0 ;
V_7 -> V_203 = 0 ;
V_7 -> V_204 = 0 ;
V_7 -> V_205 = 0 ;
V_7 -> V_206 = 0 ;
V_7 -> V_207 = 0 ;
V_7 -> V_197 = 0 ;
V_7 -> V_22 . V_65 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_52 = 0 ;
}
static int F_131 ( struct V_6 * V_7 , struct V_208 * V_209 )
{
struct V_210 * * V_211 ;
int V_212 ;
F_20 () ;
if ( F_62 ( V_7 -> V_45 != V_50
|| F_132 ( V_213 , & V_7 -> V_52 ) ) )
return - V_57 ;
V_212 = F_133 ( V_209 , V_7 -> V_206 ) ;
if ( F_12 ( V_212 < 0 ) )
return V_212 ;
V_7 -> V_19 = F_68 ( V_209 -> V_29 -> V_30 , V_69 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_70 ;
V_7 -> V_19 -> F_50 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_211 = V_7 -> V_200 ;
if ( V_211 ) {
for (; * V_211 ; ++ V_211 ) {
struct V_214 * V_215 = ( * V_211 ) -> V_216 ;
int V_217 = V_212 ;
for (; V_215 -> V_218 ; ++ V_217 , ++ V_215 )
V_215 -> V_217 = V_217 ;
}
}
V_7 -> V_29 = V_209 -> V_29 ;
F_115 ( V_7 ) ;
return 0 ;
}
static void F_134 ( struct V_6 * V_7 )
{
F_20 () ;
if ( ! F_62 ( ! V_7 -> V_29 ) ) {
F_57 ( V_7 -> V_29 -> V_30 , V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_29 = NULL ;
F_135 ( V_213 , & V_7 -> V_52 ) ;
F_104 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_104 * V_105 , * V_196 ;
unsigned V_61 , V_65 ;
F_20 () ;
V_65 = V_7 -> V_197 ;
V_196 = F_136 ( V_65 , sizeof( * V_196 ) , V_69 ) ;
if ( ! V_196 )
return - V_70 ;
V_105 = V_196 ;
for ( V_61 = 1 ; V_61 <= V_65 ; ++ V_61 , ++ V_105 ) {
V_105 -> V_7 = V_7 ;
F_124 ( & V_105 -> V_42 ) ;
F_126 ( & V_105 -> V_83 ) ;
if ( V_7 -> V_219 & V_220 )
sprintf ( V_196 -> V_160 , L_20 , V_7 -> V_221 [ V_61 ] ) ;
else
sprintf ( V_196 -> V_160 , L_21 , V_61 ) ;
V_105 -> V_159 = F_86 ( V_7 -> V_137 , V_196 -> V_160 ,
V_105 ,
& V_222 ) ;
if ( F_12 ( ! V_105 -> V_159 ) ) {
F_130 ( V_196 , V_61 - 1 ) ;
return - V_70 ;
}
}
V_7 -> V_196 = V_196 ;
return 0 ;
}
static void F_130 ( struct V_104 * V_196 , unsigned V_65 )
{
struct V_104 * V_105 = V_196 ;
F_20 () ;
for (; V_65 ; -- V_65 , ++ V_105 ) {
F_119 ( F_137 ( & V_105 -> V_42 ) ||
F_120 ( & V_105 -> V_83 ) ) ;
if ( V_105 -> V_159 ) {
F_138 ( V_105 -> V_159 ) ;
F_88 ( V_105 -> V_159 ) ;
V_105 -> V_159 = NULL ;
}
}
F_34 ( V_196 ) ;
}
static void F_139 ( struct V_1 * V_78 )
{
struct V_89 * V_12 = V_78 -> V_223 ;
struct V_104 * V_105 = V_78 -> V_7 -> V_196 ;
unsigned V_65 = V_78 -> V_7 -> V_197 ;
unsigned long V_52 ;
F_140 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
do {
if ( F_39 ( V_12 -> V_12 ) )
F_141 ( V_12 -> V_12 ) ;
V_105 -> V_12 = NULL ;
++ V_12 ;
++ V_105 ;
} while ( -- V_65 );
F_142 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
}
static int F_143 ( struct V_1 * V_78 )
{
struct V_6 * V_7 = V_78 -> V_7 ;
struct V_89 * V_12 = V_78 -> V_223 ;
struct V_104 * V_105 = V_7 -> V_196 ;
unsigned V_65 = V_7 -> V_197 ;
unsigned long V_52 ;
int V_20 = 0 ;
F_140 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
do {
struct V_130 * V_224 ;
int V_129 ;
if ( V_7 -> V_29 -> V_132 == V_133 )
V_129 = 2 ;
else if ( V_7 -> V_29 -> V_132 == V_134 )
V_129 = 1 ;
else
V_129 = 0 ;
do {
V_224 = V_12 -> V_135 [ V_129 ] ;
} while ( ! V_224 && -- V_129 >= 0 );
if ( ! V_224 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_90 = V_12 ;
V_12 -> V_12 -> V_131 = V_224 ;
V_20 = F_144 ( V_12 -> V_12 ) ;
if ( F_39 ( ! V_20 ) ) {
V_105 -> V_12 = V_12 ;
V_105 -> V_108 = F_145 ( V_224 ) ;
V_105 -> V_109 = F_146 ( V_224 ) ;
} else {
break;
}
F_147 ( & V_105 -> V_83 ) ;
++ V_12 ;
++ V_105 ;
} while ( -- V_65 );
F_142 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
return V_20 ;
}
static int T_6 F_148 ( char * V_17 , unsigned V_18 ,
T_7 V_225 ,
void * V_226 )
{
struct V_227 * V_228 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_22 ) ;
return - V_48 ;
}
V_28 = V_228 -> V_229 ;
if ( V_18 < V_28 ) {
F_16 ( L_23 ) ;
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
switch ( V_228 -> V_230 ) {
case V_231 :
case V_232 :
case V_233 :
case V_234 :
F_16 ( L_24 ,
V_228 -> V_230 ) ;
return - V_48 ;
case V_235 : {
struct V_236 * V_224 = ( void * ) V_228 ;
F_16 ( L_25 ) ;
if ( V_28 != sizeof *V_224 )
goto V_237;
F_152 ( V_238 , V_224 -> V_239 ) ;
if ( V_224 -> V_240 )
F_152 ( STRING , V_224 -> V_240 ) ;
}
break;
case V_241 : {
struct V_130 * V_224 = ( void * ) V_228 ;
F_16 ( L_26 ) ;
if ( V_28 != V_242 &&
V_28 != V_243 )
goto V_237;
F_152 ( V_244 , V_224 -> V_245 ) ;
}
break;
case V_246 :
F_16 ( L_27 ) ;
if ( V_28 != sizeof( struct V_247 ) )
goto V_237;
break;
case V_248 :
if ( V_28 != sizeof( struct V_249 ) )
goto V_237;
break;
case V_250 : {
struct V_251 * V_224 = ( void * ) V_228 ;
F_16 ( L_28 ) ;
if ( V_28 != sizeof *V_224 )
goto V_237;
if ( V_224 -> V_252 )
F_152 ( STRING , V_224 -> V_252 ) ;
}
break;
case V_253 :
F_16 ( L_29 ) ;
if ( V_28 != sizeof( struct V_254 ) )
goto V_237;
break;
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
F_16 ( L_30 , V_228 -> V_230 ) ;
return - V_48 ;
default:
F_16 ( L_31 , V_228 -> V_230 ) ;
return - V_48 ;
V_237:
F_16 ( L_32 ,
V_228 -> V_229 , V_228 -> V_230 ) ;
return - V_48 ;
}
#undef F_152
#undef V_260
#undef F_149
#undef F_150
#undef F_151
return V_28 ;
}
static int T_6 F_153 ( unsigned V_65 , char * V_17 , unsigned V_18 ,
T_7 V_225 , void * V_226 )
{
const unsigned V_261 = V_18 ;
unsigned long V_127 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_127 == V_65 )
V_17 = NULL ;
V_20 = V_225 ( V_262 , ( T_8 * ) V_127 , ( void * ) V_17 , V_226 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_33 ,
V_127 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_261 - V_18 ;
V_20 = F_148 ( V_17 , V_18 , V_225 , V_226 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_34 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_127 ;
}
}
static int F_154 ( enum V_263 type ,
T_8 * V_264 , struct V_227 * V_131 ,
void * V_226 )
{
struct V_265 * V_266 = V_226 ;
struct V_130 * V_267 ;
F_20 () ;
switch ( type ) {
case V_262 :
break;
case V_268 :
if ( * V_264 >= V_266 -> V_207 )
V_266 -> V_207 = * V_264 + 1 ;
break;
case V_269 :
if ( * V_264 > V_266 -> V_7 -> V_206 )
V_266 -> V_7 -> V_206 = * V_264 ;
break;
case V_270 :
V_267 = ( void * ) V_131 ;
V_266 -> V_197 ++ ;
if ( V_266 -> V_197 >= 15 )
return - V_48 ;
if ( ! V_266 -> V_7 -> V_197 && ! V_266 -> V_7 -> V_207 )
V_266 -> V_7 -> V_221 [ V_266 -> V_197 ] =
V_267 -> V_245 ;
else if ( V_266 -> V_7 -> V_221 [ V_266 -> V_197 ] !=
V_267 -> V_245 )
return - V_48 ;
break;
}
return 0 ;
}
static int F_155 ( enum V_271 * V_272 ,
struct V_273 * V_131 )
{
T_10 V_274 = F_8 ( V_131 -> V_275 ) ;
T_10 V_276 = F_8 ( V_131 -> V_277 ) ;
if ( V_274 != 1 ) {
F_16 ( L_35 ,
V_274 ) ;
return - V_48 ;
}
switch ( V_276 ) {
case 0x4 :
* V_272 = V_278 ;
break;
case 0x5 :
* V_272 = V_279 ;
break;
default:
F_16 ( L_36 , V_276 ) ;
return - V_48 ;
}
return sizeof( * V_131 ) ;
}
static int T_6 F_156 ( char * V_17 , unsigned V_18 ,
enum V_271 type ,
T_10 V_280 ,
T_11 V_225 ,
void * V_226 ,
struct V_273 * V_281 )
{
int V_20 ;
const unsigned V_261 = V_18 ;
F_20 () ;
while ( V_280 -- ) {
V_20 = V_225 ( type , V_281 , V_17 , V_18 , V_226 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_37 , type ) ;
return V_20 ;
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
return V_261 - V_18 ;
}
static int T_6 F_157 ( unsigned V_65 ,
char * V_17 , unsigned V_18 ,
T_11 V_225 , void * V_226 )
{
const unsigned V_261 = V_18 ;
unsigned long V_127 = 0 ;
F_20 () ;
for ( V_127 = 0 ; V_127 < V_65 ; ++ V_127 ) {
int V_20 ;
enum V_271 type ;
T_10 V_280 ;
struct V_273 * V_131 = ( void * ) V_17 ;
if ( V_18 < sizeof( * V_131 ) )
return - V_48 ;
if ( F_158 ( V_131 -> V_282 ) > V_18 )
return - V_48 ;
V_20 = F_155 ( & type , V_131 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_38 ,
V_127 , V_20 ) ;
return V_20 ;
}
V_280 = F_8 ( V_131 -> V_283 ) ;
if ( type == V_278 &&
( V_280 > 255 || V_131 -> V_284 ) )
return - V_48 ;
V_18 -= V_20 ;
V_17 += V_20 ;
V_20 = F_156 ( V_17 , V_18 , type ,
V_280 , V_225 , V_226 , V_131 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_34 , V_114 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
return V_261 - V_18 ;
}
static int F_159 ( enum V_271 type ,
struct V_273 * V_281 , void * V_17 ,
unsigned V_18 , void * V_226 )
{
struct V_6 * V_7 = V_226 ;
T_8 V_28 ;
F_20 () ;
switch ( type ) {
case V_278 : {
struct V_285 * V_267 = V_17 ;
int V_61 ;
if ( V_18 < sizeof( * V_267 ) ||
V_267 -> V_286 >= V_7 -> V_207 ||
V_267 -> V_287 )
return - V_48 ;
for ( V_61 = 0 ; V_61 < F_160 ( V_267 -> V_288 ) ; ++ V_61 )
if ( V_267 -> V_288 [ V_61 ] )
return - V_48 ;
V_28 = sizeof( struct V_285 ) ;
}
break;
case V_279 : {
struct V_289 * V_267 = V_17 ;
T_12 type , V_290 ;
T_10 V_291 ;
if ( V_18 < sizeof( * V_267 ) || V_281 -> V_292 >= V_7 -> V_207 )
return - V_48 ;
V_28 = F_158 ( V_267 -> V_293 ) ;
type = F_158 ( V_267 -> V_294 ) ;
if ( type < V_295 ||
type > V_296 ) {
F_16 ( L_39 ,
type ) ;
return - V_48 ;
}
V_291 = F_8 ( V_267 -> V_297 ) ;
V_290 = F_158 ( * ( T_12 * ) ( ( T_8 * ) V_17 + 10 + V_291 ) ) ;
if ( V_28 != 14 + V_291 + V_290 ) {
F_16 ( L_40 ,
V_28 , V_291 , V_290 , type ) ;
return - V_48 ;
}
++ V_7 -> V_298 ;
V_7 -> V_299 += V_291 * 2 ;
V_7 -> V_300 += V_290 ;
}
break;
default:
F_16 ( L_31 , type ) ;
return - V_48 ;
}
return V_28 ;
}
static int F_26 ( struct V_6 * V_7 ,
char * const V_164 , T_1 V_18 )
{
char * V_17 = V_164 , * V_201 ;
unsigned V_301 = 0 , V_302 [ 3 ] , V_52 ;
int V_20 = - V_48 , V_61 ;
struct V_265 V_266 ;
F_20 () ;
if ( F_161 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_161 ( V_17 ) ) {
case V_303 :
V_52 = V_304 | V_305 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_306 :
V_52 = F_161 ( V_17 + 8 ) ;
V_7 -> V_219 = V_52 ;
if ( V_52 & ~ ( V_304 |
V_305 |
V_307 |
V_308 |
V_220 ) ) {
V_20 = - V_309 ;
goto error;
}
V_17 += 12 ;
V_18 -= 12 ;
break;
default:
goto error;
}
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! ( V_52 & ( 1 << V_61 ) ) ) {
V_302 [ V_61 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_302 [ V_61 ] = F_161 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
if ( V_52 & ( 1 << V_61 ) ) {
V_301 = F_161 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
} ;
V_201 = V_17 ;
V_266 . V_7 = V_7 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! V_302 [ V_61 ] )
continue;
V_266 . V_207 = 0 ;
V_266 . V_197 = 0 ;
V_20 = F_153 ( V_302 [ V_61 ] , V_17 , V_18 ,
F_154 , & V_266 ) ;
if ( V_20 < 0 )
goto error;
if ( ! V_7 -> V_197 && ! V_7 -> V_207 ) {
V_7 -> V_197 = V_266 . V_197 ;
V_7 -> V_207 = V_266 . V_207 ;
} else {
if ( V_7 -> V_197 != V_266 . V_197 ) {
V_20 = - V_48 ;
goto error;
}
if ( V_7 -> V_207 != V_266 . V_207 ) {
V_20 = - V_48 ;
goto error;
}
}
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_301 ) {
V_20 = F_157 ( V_301 , V_17 , V_18 ,
F_159 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_201 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_198 = V_164 ;
V_7 -> V_201 = V_201 ;
V_7 -> V_202 = V_17 - V_201 ;
V_7 -> V_203 = V_302 [ 0 ] ;
V_7 -> V_204 = V_302 [ 1 ] ;
V_7 -> V_205 = V_302 [ 2 ] ;
V_7 -> V_310 = V_301 ;
return 0 ;
error:
F_34 ( V_164 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_164 , T_1 V_18 )
{
T_12 V_311 , V_312 , V_313 ;
struct V_210 * * V_200 , * V_187 ;
struct V_214 * V_216 , * V_218 ;
const char * V_17 = V_164 ;
F_20 () ;
if ( F_12 ( F_161 ( V_17 ) != V_314 ||
F_161 ( V_17 + 4 ) != V_18 ) )
goto error;
V_311 = F_161 ( V_17 + 8 ) ;
V_313 = F_161 ( V_17 + 12 ) ;
if ( F_12 ( ! V_311 != ! V_313 ) )
goto error;
V_312 = V_7 -> V_206 ;
if ( F_12 ( V_311 < V_312 ) )
goto error;
if ( ! V_312 ) {
F_34 ( V_164 ) ;
return 0 ;
}
{
unsigned V_61 = 0 ;
F_162 ( V_267 ) ;
F_163 ( V_267 , struct V_210 * , V_200 ,
V_313 + 1 ) ;
F_163 ( V_267 , struct V_210 , V_315 , V_313 ) ;
F_163 ( V_267 , struct V_214 , V_216 ,
V_313 * ( V_312 + 1 ) ) ;
char * V_316 = F_40 ( F_164 ( V_267 ) , V_69 ) ;
if ( F_12 ( ! V_316 ) ) {
F_34 ( V_164 ) ;
return - V_70 ;
}
V_200 = F_165 ( V_316 , V_267 , V_200 ) ;
V_187 = F_165 ( V_316 , V_267 , V_315 ) ;
V_61 = V_313 ;
do {
* V_200 ++ = V_187 ++ ;
} while ( -- V_61 );
* V_200 = NULL ;
V_200 = F_165 ( V_316 , V_267 , V_200 ) ;
V_187 = F_165 ( V_316 , V_267 , V_315 ) ;
V_218 = F_165 ( V_316 , V_267 , V_216 ) ;
V_216 = V_218 ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_317 = V_312 ;
if ( F_12 ( V_18 < 3 ) )
goto V_318;
V_187 -> V_319 = F_166 ( V_17 ) ;
V_187 -> V_216 = V_218 ;
++ V_187 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_167 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_318;
if ( F_39 ( V_317 ) ) {
V_218 -> V_218 = V_17 ;
-- V_317 ;
++ V_218 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_311 );
V_218 -> V_217 = 0 ;
V_218 -> V_218 = NULL ;
++ V_218 ;
} while ( -- V_313 );
if ( F_12 ( V_18 ) )
goto V_318;
V_7 -> V_200 = V_200 ;
V_7 -> V_199 = V_164 ;
return 0 ;
V_318:
F_34 ( V_200 ) ;
error:
F_34 ( V_164 ) ;
return - V_48 ;
}
static void F_168 ( struct V_6 * V_7 ,
enum V_320 type )
{
enum V_320 V_321 , V_322 = type ;
int V_323 = 0 ;
if ( V_7 -> V_8 == V_54 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_324 :
V_322 = V_325 ;
case V_325 :
case V_63 :
V_321 = type ;
break;
case V_326 :
case V_327 :
case V_328 :
case V_329 :
V_321 = V_325 ;
V_322 = V_324 ;
V_323 = 1 ;
break;
default:
F_67 ( 1 , L_41 , type ) ;
return;
}
{
T_8 * V_22 = V_7 -> V_22 . V_62 , * V_330 = V_22 ;
unsigned V_58 = V_7 -> V_22 . V_65 ;
for (; V_58 ; -- V_58 , ++ V_22 )
if ( ( * V_22 == V_321 || * V_22 == V_322 ) == V_323 )
* V_330 ++ = * V_22 ;
else
F_16 ( L_42 , * V_22 ) ;
V_7 -> V_22 . V_65 = V_330 - V_7 -> V_22 . V_62 ;
}
F_16 ( L_43 , type ) ;
V_7 -> V_22 . V_62 [ V_7 -> V_22 . V_65 ++ ] = type ;
F_169 ( & V_7 -> V_22 . V_25 ) ;
}
static void F_170 ( struct V_6 * V_7 ,
enum V_320 type )
{
unsigned long V_52 ;
F_140 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
F_168 ( V_7 , type ) ;
F_142 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
}
static int F_171 ( struct V_6 * V_7 , T_8 V_331 )
{
int V_61 ;
for ( V_61 = 1 ; V_61 < F_160 ( V_7 -> V_221 ) ; ++ V_61 )
if ( V_7 -> V_221 [ V_61 ] == V_331 )
return V_61 ;
return - V_332 ;
}
static int F_172 ( enum V_263 type , T_8 * V_264 ,
struct V_227 * V_131 ,
void * V_226 )
{
struct V_130 * V_224 = ( void * ) V_131 ;
struct V_1 * V_78 = V_226 ;
struct V_89 * V_89 ;
unsigned V_333 ;
int V_334 ;
static const char * V_335 [] = { L_44 , L_45 , L_46 } ;
if ( type != V_262 )
return 0 ;
if ( V_78 -> V_4 . V_336 ) {
V_333 = 2 ;
V_78 -> V_4 . V_336 [ ( long ) V_264 ] = V_131 ;
} else if ( V_78 -> V_4 . V_337 ) {
V_333 = 1 ;
V_78 -> V_4 . V_337 [ ( long ) V_264 ] = V_131 ;
} else {
V_333 = 0 ;
V_78 -> V_4 . V_338 [ ( long ) V_264 ] = V_131 ;
}
if ( ! V_131 || V_131 -> V_230 != V_241 )
return 0 ;
V_334 = F_171 ( V_78 -> V_7 , V_224 -> V_245 ) - 1 ;
if ( V_334 < 0 )
return V_334 ;
V_89 = V_78 -> V_223 + V_334 ;
if ( F_12 ( V_89 -> V_135 [ V_333 ] ) ) {
F_93 ( L_47 ,
V_335 [ V_333 ] ,
V_224 -> V_245 & V_339 ) ;
return - V_48 ;
}
V_89 -> V_135 [ V_333 ] = V_224 ;
F_173 ( L_48 , V_224 , V_224 -> V_229 ) ;
if ( V_89 -> V_12 ) {
V_224 -> V_245 = V_89 -> V_135 [ 0 ] -> V_245 ;
if ( ! V_224 -> V_340 )
V_224 -> V_340 = V_89 -> V_135 [ 0 ] -> V_340 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_8 V_245 ;
V_245 = V_224 -> V_245 ;
F_16 ( L_49 ) ;
V_12 = F_174 ( V_78 -> V_29 , V_224 ) ;
if ( F_12 ( ! V_12 ) )
return - V_341 ;
V_12 -> V_90 = V_78 -> V_223 + V_334 ;
V_14 = F_68 ( V_12 , V_69 ) ;
if ( F_12 ( ! V_14 ) )
return - V_70 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_14 = V_14 ;
V_78 -> V_342 [ V_224 -> V_245 &
V_339 ] = V_334 + 1 ;
if ( V_78 -> V_7 -> V_219 & V_220 )
V_224 -> V_245 = V_245 ;
}
F_173 ( L_50 , V_224 , V_224 -> V_229 ) ;
return 0 ;
}
static int F_175 ( enum V_263 type , T_8 * V_264 ,
struct V_227 * V_131 ,
void * V_226 )
{
struct V_1 * V_78 = V_226 ;
unsigned V_334 ;
T_8 V_343 ;
switch ( type ) {
default:
case V_262 :
return 0 ;
case V_268 :
V_334 = * V_264 ;
if ( V_78 -> V_344 [ V_334 ] < 0 ) {
int V_217 = F_176 ( V_78 -> V_345 , & V_78 -> V_4 ) ;
if ( F_12 ( V_217 < 0 ) )
return V_217 ;
V_78 -> V_344 [ V_334 ] = V_217 ;
}
V_343 = V_78 -> V_344 [ V_334 ] ;
break;
case V_269 :
V_343 = V_78 -> V_7 -> V_200 [ 0 ] -> V_216 [ * V_264 - 1 ] . V_217 ;
break;
case V_270 :
if ( V_131 -> V_230 == V_241 )
return 0 ;
V_334 = ( * V_264 & V_339 ) - 1 ;
if ( F_12 ( ! V_78 -> V_223 [ V_334 ] . V_12 ) )
return - V_48 ;
{
struct V_130 * * V_135 ;
V_135 = V_78 -> V_223 [ V_334 ] . V_135 ;
V_343 = V_135 [ V_135 [ 0 ] ? 0 : 1 ] -> V_245 ;
}
break;
}
F_16 ( L_51 , * V_264 , V_343 ) ;
* V_264 = V_343 ;
return 0 ;
}
static int F_177 ( enum V_271 type ,
struct V_273 * V_281 , void * V_17 ,
unsigned V_18 , void * V_226 )
{
struct V_1 * V_78 = V_226 ;
T_8 V_28 = 0 ;
switch ( type ) {
case V_278 : {
struct V_285 * V_131 = V_17 ;
struct V_346 * V_187 ;
V_187 = & V_78 -> V_4 . V_347 [ V_131 -> V_286 ] ;
V_187 -> V_348 = V_78 -> V_344 [ V_131 -> V_286 ] ;
memcpy ( V_187 -> V_349 -> V_350 , & V_131 -> V_351 ,
F_160 ( V_131 -> V_351 ) +
F_160 ( V_131 -> V_352 ) ) ;
V_28 = sizeof( * V_131 ) ;
}
break;
case V_279 : {
struct V_289 * V_131 = V_17 ;
struct V_346 * V_187 ;
struct V_353 * V_354 ;
char * V_355 ;
char * V_356 ;
V_187 = & V_78 -> V_4 . V_347 [ V_281 -> V_292 ] ;
V_187 -> V_348 = V_78 -> V_344 [ V_281 -> V_292 ] ;
V_354 = V_78 -> V_7 -> V_357 ;
V_78 -> V_7 -> V_357 += sizeof( * V_354 ) ;
V_354 -> type = F_158 ( V_131 -> V_294 ) ;
V_354 -> V_358 = F_8 ( V_131 -> V_297 ) ;
V_354 -> V_106 = F_158 ( * ( T_12 * )
F_178 ( V_17 , V_354 -> V_358 ) ) ;
V_28 = V_354 -> V_358 + V_354 -> V_106 + 14 ;
V_355 = V_78 -> V_7 -> V_359 ;
V_78 -> V_7 -> V_359 +=
V_354 -> V_358 ;
V_356 = V_78 -> V_7 -> V_360 ;
V_78 -> V_7 -> V_360 +=
V_354 -> V_106 ;
memcpy ( V_356 ,
F_179 ( V_17 , V_354 -> V_358 ) ,
V_354 -> V_106 ) ;
switch ( V_354 -> type ) {
case V_295 :
case V_361 :
case V_362 :
case V_296 :
V_354 -> V_106 *= 2 ;
break;
}
V_354 -> V_17 = V_356 ;
memcpy ( V_355 , F_180 ( V_17 ) ,
V_354 -> V_358 ) ;
V_354 -> V_358 *= 2 ;
V_354 -> V_160 = V_355 ;
V_187 -> V_349 -> V_363 +=
V_354 -> V_358 + V_354 -> V_106 + 14 ;
++ V_187 -> V_349 -> V_364 ;
F_181 ( & V_354 -> V_365 , & V_187 -> V_349 -> V_354 ) ;
}
break;
default:
F_16 ( L_31 , type ) ;
}
return V_28 ;
}
static inline struct V_366 * F_182 ( struct V_2 * V_3 ,
struct V_367 * V_368 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_366 * V_369 =
F_2 ( V_3 -> V_370 , struct V_366 , V_371 ) ;
int V_20 ;
F_20 () ;
if ( ! V_369 -> V_372 )
F_183 () ;
V_20 = V_369 -> V_373 -> V_374 ? 0 : - V_79 ;
V_78 -> V_7 = V_369 -> V_373 -> V_6 ;
if ( ! V_369 -> V_372 )
F_184 () ;
if ( V_20 )
return F_101 ( V_20 ) ;
V_78 -> V_345 = V_368 ;
V_78 -> V_29 = V_368 -> V_209 -> V_29 ;
if ( ! V_369 -> V_375 ) {
V_20 = F_131 ( V_78 -> V_7 , V_368 -> V_209 ) ;
if ( V_20 )
return F_101 ( V_20 ) ;
}
V_369 -> V_375 ++ ;
V_78 -> V_4 . V_216 = V_78 -> V_7 -> V_200 ;
return V_369 ;
}
static int F_185 ( struct V_367 * V_368 ,
struct V_2 * V_3 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
const int V_376 = ! ! V_78 -> V_7 -> V_203 ;
const int V_377 = F_186 ( V_78 -> V_29 ) &&
V_78 -> V_7 -> V_204 ;
const int V_378 = F_187 ( V_78 -> V_29 ) &&
V_78 -> V_7 -> V_205 ;
int V_379 , V_380 , V_381 , V_20 , V_61 ;
F_162 ( V_267 ) ;
F_188 ( V_267 , struct V_89 , V_223 , V_7 -> V_197 ) ;
F_188 ( V_267 , struct V_227 * , V_382 ,
V_376 ? V_7 -> V_203 + 1 : 0 ) ;
F_188 ( V_267 , struct V_227 * , V_383 ,
V_377 ? V_7 -> V_204 + 1 : 0 ) ;
F_188 ( V_267 , struct V_227 * , V_384 ,
V_378 ? V_7 -> V_205 + 1 : 0 ) ;
F_188 ( V_267 , short , V_385 , V_7 -> V_207 ) ;
F_188 ( V_267 , struct V_346 , V_347 ,
V_368 -> V_209 -> V_386 ? V_7 -> V_207 : 0 ) ;
F_188 ( V_267 , char [ 16 ] , V_387 ,
V_368 -> V_209 -> V_386 ? V_7 -> V_207 : 0 ) ;
F_188 ( V_267 , struct V_388 , V_349 ,
V_368 -> V_209 -> V_386 ? V_7 -> V_207 : 0 ) ;
F_188 ( V_267 , struct V_353 , V_354 ,
V_7 -> V_298 ) ;
F_188 ( V_267 , char , V_355 ,
V_7 -> V_299 ) ;
F_188 ( V_267 , char , V_356 ,
V_7 -> V_300 ) ;
F_188 ( V_267 , char , V_201 , V_7 -> V_202 ) ;
char * V_316 ;
F_20 () ;
if ( F_12 ( ! ( V_376 | V_377 | V_378 ) ) )
return - V_341 ;
V_316 = F_122 ( F_164 ( V_267 ) , V_69 ) ;
if ( F_12 ( ! V_316 ) )
return - V_70 ;
V_7 -> V_357 = F_165 ( V_316 , V_267 , V_354 ) ;
V_7 -> V_359 =
F_165 ( V_316 , V_267 , V_355 ) ;
V_7 -> V_360 =
F_165 ( V_316 , V_267 , V_356 ) ;
memcpy ( F_165 ( V_316 , V_267 , V_201 ) , V_7 -> V_201 ,
V_7 -> V_202 ) ;
memset ( F_165 ( V_316 , V_267 , V_385 ) , 0xff , V_389 ) ;
for ( V_20 = V_7 -> V_197 ; V_20 ; -- V_20 ) {
struct V_89 * V_39 ;
V_39 = F_165 ( V_316 , V_267 , V_223 ) ;
V_39 [ V_20 ] . V_127 = - 1 ;
}
V_78 -> V_223 = F_165 ( V_316 , V_267 , V_223 ) ;
V_78 -> V_344 = F_165 ( V_316 , V_267 , V_385 ) ;
if ( F_39 ( V_376 ) ) {
V_78 -> V_4 . V_338 = F_165 ( V_316 , V_267 , V_382 ) ;
V_379 = F_153 ( V_7 -> V_203 ,
F_165 ( V_316 , V_267 , V_201 ) ,
V_390 ,
F_172 , V_78 ) ;
if ( F_12 ( V_379 < 0 ) ) {
V_20 = V_379 ;
goto error;
}
} else {
V_379 = 0 ;
}
if ( F_39 ( V_377 ) ) {
V_78 -> V_4 . V_337 = F_165 ( V_316 , V_267 , V_383 ) ;
V_380 = F_153 ( V_7 -> V_204 ,
F_165 ( V_316 , V_267 , V_201 ) + V_379 ,
V_390 - V_379 ,
F_172 , V_78 ) ;
if ( F_12 ( V_380 < 0 ) ) {
V_20 = V_380 ;
goto error;
}
} else {
V_380 = 0 ;
}
if ( F_39 ( V_378 ) ) {
V_78 -> V_4 . V_336 = F_165 ( V_316 , V_267 , V_384 ) ;
V_381 = F_153 ( V_7 -> V_205 ,
F_165 ( V_316 , V_267 , V_201 ) + V_379 + V_380 ,
V_390 - V_379 - V_380 ,
F_172 , V_78 ) ;
if ( F_12 ( V_381 < 0 ) ) {
V_20 = V_381 ;
goto error;
}
} else {
V_381 = 0 ;
}
V_20 = F_153 ( V_7 -> V_203 +
( V_377 ? V_7 -> V_204 : 0 ) +
( V_378 ? V_7 -> V_205 : 0 ) ,
F_165 ( V_316 , V_267 , V_201 ) , V_390 ,
F_175 , V_78 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_78 -> V_4 . V_347 = F_165 ( V_316 , V_267 , V_347 ) ;
if ( V_368 -> V_209 -> V_386 )
for ( V_61 = 0 ; V_61 < V_7 -> V_207 ; ++ V_61 ) {
struct V_388 * V_131 ;
V_131 = V_78 -> V_4 . V_347 [ V_61 ] . V_349 =
F_165 ( V_316 , V_267 , V_349 ) +
V_61 * sizeof( struct V_388 ) ;
V_131 -> V_350 =
F_165 ( V_316 , V_267 , V_387 ) + V_61 * 16 ;
F_189 ( & V_131 -> V_354 ) ;
}
V_20 = F_157 ( V_7 -> V_310 ,
F_165 ( V_316 , V_267 , V_201 ) +
V_379 + V_380 + V_381 ,
V_390 - V_379 - V_380 - V_381 ,
F_177 , V_78 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
V_78 -> V_4 . V_391 =
V_368 -> V_209 -> V_386 ? V_7 -> V_207 : 0 ;
F_170 ( V_7 , V_326 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_190 ( struct V_367 * V_368 ,
struct V_2 * V_3 )
{
struct V_366 * V_369 = F_182 ( V_3 , V_368 ) ;
if ( F_23 ( V_369 ) )
return F_24 ( V_369 ) ;
return F_185 ( V_368 , V_3 ) ;
}
static int F_191 ( struct V_2 * V_3 ,
unsigned V_292 , unsigned V_392 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
int V_20 = 0 , V_393 ;
if ( V_392 != ( unsigned ) - 1 ) {
V_393 = F_46 ( V_78 , V_292 ) ;
if ( F_12 ( V_393 < 0 ) )
return V_393 ;
}
if ( V_7 -> V_78 )
F_139 ( V_7 -> V_78 ) ;
if ( V_7 -> V_45 != V_50 )
return - V_79 ;
if ( V_392 == ( unsigned ) - 1 ) {
V_7 -> V_78 = NULL ;
F_170 ( V_7 , V_328 ) ;
return 0 ;
}
V_7 -> V_78 = V_78 ;
V_20 = F_143 ( V_78 ) ;
if ( F_39 ( V_20 >= 0 ) )
F_170 ( V_7 , V_329 ) ;
return V_20 ;
}
static void F_192 ( struct V_2 * V_3 )
{
F_191 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_193 ( struct V_2 * V_3 ,
const struct V_394 * V_395 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
unsigned long V_52 ;
int V_20 ;
F_20 () ;
F_16 ( L_52 , V_395 -> V_55 ) ;
F_16 ( L_53 , V_395 -> V_396 ) ;
F_16 ( L_54 , F_8 ( V_395 -> V_397 ) ) ;
F_16 ( L_55 , F_8 ( V_395 -> V_277 ) ) ;
F_16 ( L_56 , F_8 ( V_395 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_79 ;
switch ( V_395 -> V_55 & V_398 ) {
case V_399 :
V_20 = F_46 ( V_78 , F_8 ( V_395 -> V_277 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_400 :
V_20 = F_194 ( V_78 , F_8 ( V_395 -> V_277 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
if ( V_78 -> V_7 -> V_219 & V_220 )
V_20 = V_78 -> V_7 -> V_221 [ V_20 ] ;
break;
default:
return - V_401 ;
}
F_140 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
V_7 -> V_22 . V_23 = * V_395 ;
V_7 -> V_22 . V_23 . V_277 = F_195 ( V_20 ) ;
F_168 ( V_7 , V_63 ) ;
F_142 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
return 0 ;
}
static void F_196 ( struct V_2 * V_3 )
{
F_20 () ;
F_170 ( F_1 ( V_3 ) -> V_7 , V_325 ) ;
}
static void F_197 ( struct V_2 * V_3 )
{
F_20 () ;
F_170 ( F_1 ( V_3 ) -> V_7 , V_324 ) ;
}
static int F_194 ( struct V_1 * V_78 , T_8 V_127 )
{
V_127 = V_78 -> V_342 [ V_127 & V_339 ] ;
return V_127 ? V_127 : - V_402 ;
}
static int F_46 ( struct V_1 * V_78 , T_8 V_393 )
{
short * V_403 = V_78 -> V_344 ;
unsigned V_65 = V_78 -> V_7 -> V_207 ;
for (; V_65 ; -- V_65 , ++ V_403 ) {
if ( * V_403 >= 0 && * V_403 == V_393 )
return V_403 - V_78 -> V_344 ;
}
return - V_402 ;
}
static struct V_192 * F_198 ( const char * V_160 )
{
struct V_192 * V_373 ;
F_199 (dev, &ffs_devices, entry) {
if ( ! V_373 -> V_160 || ! V_160 )
continue;
if ( strcmp ( V_373 -> V_160 , V_160 ) == 0 )
return V_373 ;
}
return NULL ;
}
static struct V_192 * F_200 ( void )
{
struct V_192 * V_373 ;
if ( F_201 ( & V_404 ) ) {
V_373 = F_202 ( & V_404 , struct V_192 , V_365 ) ;
if ( V_373 -> V_405 )
return V_373 ;
}
return NULL ;
}
static struct V_192 * F_203 ( const char * V_160 )
{
struct V_192 * V_373 ;
V_373 = F_200 () ;
if ( V_373 )
return V_373 ;
return F_198 ( V_160 ) ;
}
static inline struct V_366 * F_204 ( struct V_406 * V_407 )
{
return F_2 ( F_205 ( V_407 ) , struct V_366 ,
V_371 . V_408 ) ;
}
static void F_206 ( struct V_406 * V_407 )
{
struct V_366 * V_180 = F_204 ( V_407 ) ;
F_207 ( & V_180 -> V_371 ) ;
}
static void F_208 ( struct V_409 * V_3 )
{
struct V_366 * V_180 ;
V_180 = F_209 ( V_3 ) ;
F_183 () ;
F_210 ( V_180 -> V_373 ) ;
F_184 () ;
F_34 ( V_180 ) ;
}
static int F_211 ( struct V_409 * V_370 , const char * V_160 )
{
struct V_366 * V_180 ;
char * V_39 ;
const char * V_410 ;
int V_358 , V_20 ;
V_358 = strlen ( V_160 ) + 1 ;
if ( V_358 > V_411 )
return - V_412 ;
V_39 = F_212 ( V_160 , V_358 , V_69 ) ;
if ( ! V_39 )
return - V_70 ;
V_180 = F_209 ( V_370 ) ;
V_410 = NULL ;
F_183 () ;
V_410 = V_180 -> V_373 -> V_413 ? V_180 -> V_373 -> V_160 : NULL ;
V_20 = F_213 ( V_180 -> V_373 , V_39 ) ;
if ( V_20 ) {
F_34 ( V_39 ) ;
F_184 () ;
return V_20 ;
}
V_180 -> V_373 -> V_413 = true ;
F_184 () ;
F_34 ( V_410 ) ;
return 0 ;
}
static struct V_409 * F_214 ( void )
{
struct V_366 * V_180 ;
struct V_192 * V_373 ;
V_180 = F_122 ( sizeof( * V_180 ) , V_69 ) ;
if ( ! V_180 )
return F_101 ( - V_70 ) ;
V_180 -> V_371 . V_414 = F_211 ;
V_180 -> V_371 . V_415 = F_208 ;
F_183 () ;
V_373 = F_215 () ;
F_184 () ;
if ( F_23 ( V_373 ) ) {
F_34 ( V_180 ) ;
return F_106 ( V_373 ) ;
}
V_180 -> V_373 = V_373 ;
V_373 -> V_180 = V_180 ;
F_216 ( & V_180 -> V_371 . V_408 , L_57 ,
& V_416 ) ;
return & V_180 -> V_371 ;
}
static void F_217 ( struct V_2 * V_3 )
{
F_34 ( F_1 ( V_3 ) ) ;
}
static void F_218 ( struct V_367 * V_368 ,
struct V_2 * V_3 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
struct V_366 * V_180 =
F_2 ( V_3 -> V_370 , struct V_366 , V_371 ) ;
struct V_89 * V_12 = V_78 -> V_223 ;
unsigned V_65 = V_7 -> V_197 ;
unsigned long V_52 ;
F_20 () ;
if ( V_7 -> V_78 == V_78 ) {
F_139 ( V_78 ) ;
V_7 -> V_78 = NULL ;
}
if ( ! -- V_180 -> V_375 )
F_134 ( V_7 ) ;
F_140 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
do {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_57 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
} while ( -- V_65 );
F_142 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
F_34 ( V_78 -> V_223 ) ;
V_78 -> V_223 = NULL ;
V_78 -> V_4 . V_338 = NULL ;
V_78 -> V_4 . V_337 = NULL ;
V_78 -> V_4 . V_336 = NULL ;
V_78 -> V_344 = NULL ;
F_170 ( V_7 , V_327 ) ;
}
static struct V_2 * F_219 ( struct V_409 * V_370 )
{
struct V_1 * V_78 ;
F_20 () ;
V_78 = F_122 ( sizeof( * V_78 ) , V_69 ) ;
if ( F_12 ( ! V_78 ) )
return F_101 ( - V_70 ) ;
V_78 -> V_4 . V_160 = L_58 ;
V_78 -> V_4 . V_417 = F_190 ;
V_78 -> V_4 . V_418 = F_218 ;
V_78 -> V_4 . V_419 = F_191 ;
V_78 -> V_4 . V_420 = F_192 ;
V_78 -> V_4 . V_23 = F_193 ;
V_78 -> V_4 . V_421 = F_196 ;
V_78 -> V_4 . V_422 = F_197 ;
V_78 -> V_4 . V_423 = F_217 ;
return & V_78 -> V_4 ;
}
static struct V_192 * F_215 ( void )
{
struct V_192 * V_373 ;
int V_20 ;
if ( F_200 () )
return F_101 ( - V_73 ) ;
V_373 = F_122 ( sizeof( * V_373 ) , V_69 ) ;
if ( ! V_373 )
return F_101 ( - V_70 ) ;
if ( F_220 ( & V_404 ) ) {
V_20 = F_111 () ;
if ( V_20 ) {
F_34 ( V_373 ) ;
return F_101 ( V_20 ) ;
}
}
F_221 ( & V_373 -> V_365 , & V_404 ) ;
return V_373 ;
}
static int F_213 ( struct V_192 * V_373 , const char * V_160 )
{
struct V_192 * V_424 ;
V_424 = F_198 ( V_160 ) ;
if ( V_424 )
return - V_73 ;
V_373 -> V_160 = V_160 ;
return 0 ;
}
int F_222 ( struct V_192 * V_373 , const char * V_160 )
{
int V_20 ;
F_183 () ;
V_20 = F_213 ( V_373 , V_160 ) ;
F_184 () ;
return V_20 ;
}
int F_223 ( struct V_192 * V_373 )
{
int V_20 ;
V_20 = 0 ;
F_183 () ;
if ( ! F_201 ( & V_404 ) )
V_20 = - V_73 ;
else
V_373 -> V_405 = true ;
F_184 () ;
return V_20 ;
}
static void F_210 ( struct V_192 * V_373 )
{
F_224 ( & V_373 -> V_365 ) ;
if ( V_373 -> V_413 )
F_34 ( V_373 -> V_160 ) ;
F_34 ( V_373 ) ;
if ( F_220 ( & V_404 ) )
F_113 () ;
}
static void * F_105 ( const char * V_188 )
{
struct V_192 * V_192 ;
F_20 () ;
F_183 () ;
V_192 = F_203 ( V_188 ) ;
if ( ! V_192 )
V_192 = F_101 ( - V_332 ) ;
else if ( V_192 -> V_425 )
V_192 = F_101 ( - V_73 ) ;
else if ( V_192 -> V_426 &&
V_192 -> V_426 ( V_192 ) )
V_192 = F_101 ( - V_332 ) ;
else
V_192 -> V_425 = true ;
F_184 () ;
return V_192 ;
}
static void F_108 ( struct V_6 * V_6 )
{
struct V_192 * V_192 ;
F_20 () ;
F_183 () ;
V_192 = V_6 -> V_40 ;
if ( V_192 ) {
V_192 -> V_425 = false ;
if ( V_192 -> V_427 )
V_192 -> V_427 ( V_192 ) ;
}
F_184 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_192 * V_428 ;
int V_20 = 0 ;
F_20 () ;
F_183 () ;
V_428 = V_7 -> V_40 ;
if ( ! V_428 ) {
V_20 = - V_48 ;
goto V_117;
}
if ( F_62 ( V_428 -> V_374 ) ) {
V_20 = - V_73 ;
goto V_117;
}
V_428 -> V_374 = true ;
V_428 -> V_6 = V_7 ;
if ( V_428 -> V_429 )
V_20 = V_428 -> V_429 ( V_7 ) ;
V_117:
F_184 () ;
return V_20 ;
}
static void F_129 ( struct V_6 * V_7 )
{
struct V_192 * V_428 ;
F_20 () ;
F_183 () ;
V_428 = V_7 -> V_40 ;
if ( ! V_428 )
goto V_117;
V_428 -> V_374 = false ;
if ( V_428 -> V_430 )
V_428 -> V_430 ( V_7 ) ;
if ( ! V_428 -> V_180 || V_428 -> V_180 -> V_372
|| ! V_428 -> V_180 -> V_371 . V_408 . V_431 . V_432 )
goto V_117;
F_225 ( V_428 -> V_180 ->
V_371 . V_408 . V_431 . V_432 -> V_432 ) ;
V_117:
F_184 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_433 )
{
return V_433
? F_39 ( F_226 ( V_42 ) ) ? 0 : - V_68
: F_227 ( V_42 ) ;
}
static char * F_22 ( const char T_3 * V_27 , T_1 V_18 )
{
char * V_17 ;
if ( F_12 ( ! V_18 ) )
return NULL ;
V_17 = F_40 ( V_18 , V_69 ) ;
if ( F_12 ( ! V_17 ) )
return F_101 ( - V_70 ) ;
if ( F_12 ( F_66 ( V_17 , V_27 , V_18 ) ) ) {
F_34 ( V_17 ) ;
return F_101 ( - V_66 ) ;
}
F_16 ( L_59 ) ;
F_173 ( L_57 , V_17 , V_18 ) ;
return V_17 ;
}
