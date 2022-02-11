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
F_52 ( V_94 -> V_97 ) ;
for ( V_61 = 0 ; V_61 < V_94 -> V_98 ; V_61 ++ ) {
if ( F_12 ( F_53 ( V_94 -> V_99 [ V_61 ] . V_100 ,
& V_94 -> V_27 [ V_96 ] ,
V_94 -> V_99 [ V_61 ] . V_101 ) ) ) {
V_20 = - V_66 ;
break;
}
V_96 += V_94 -> V_99 [ V_61 ] . V_101 ;
}
F_54 ( V_94 -> V_97 ) ;
}
F_55 ( V_94 -> V_102 , V_20 , V_20 ) ;
F_56 ( V_94 -> V_12 , V_94 -> V_14 ) ;
V_94 -> V_102 -> V_103 = NULL ;
if ( V_94 -> V_95 )
F_34 ( V_94 -> V_99 ) ;
F_34 ( V_94 -> V_27 ) ;
F_34 ( V_94 ) ;
}
static void F_57 ( struct V_11 * V_88 ,
struct V_13 * V_14 )
{
struct V_93 * V_94 = V_14 -> V_15 ;
F_20 () ;
F_58 ( & V_94 -> V_92 , F_51 ) ;
F_59 ( & V_94 -> V_92 ) ;
}
static T_2 F_60 ( struct V_38 * V_38 , struct V_93 * V_94 )
{
struct V_104 * V_105 = V_38 -> V_40 ;
struct V_89 * V_12 ;
char * V_17 = NULL ;
T_2 V_20 , V_106 ;
int V_107 ;
if ( F_61 ( V_105 -> V_7 -> V_45 != V_50 ) ) {
V_20 = - V_79 ;
goto error;
}
V_12 = V_105 -> V_12 ;
if ( ! V_12 ) {
if ( V_38 -> V_43 & V_44 ) {
V_20 = - V_68 ;
goto error;
}
V_20 = F_62 ( V_105 -> V_83 , ( V_12 = V_105 -> V_12 ) ) ;
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
F_63 ( V_29 , V_12 -> V_12 , V_94 -> V_18 ) :
V_94 -> V_18 ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
V_17 = F_40 ( V_106 , V_69 ) ;
if ( F_12 ( ! V_17 ) )
return - V_70 ;
if ( V_94 -> V_112 && ! V_94 -> V_95 ) {
int V_61 ;
T_1 V_96 = 0 ;
for ( V_61 = 0 ; V_61 < V_94 -> V_98 ; V_61 ++ ) {
if ( F_12 ( F_64 ( & V_17 [ V_96 ] ,
V_94 -> V_99 [ V_61 ] . V_100 ,
V_94 -> V_99 [ V_61 ] . V_101 ) ) ) {
V_20 = - V_66 ;
goto error;
}
V_96 += V_94 -> V_99 [ V_61 ] . V_101 ;
}
} else {
if ( ! V_94 -> V_95 &&
F_12 ( F_65 ( V_17 , V_94 -> V_27 ,
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
if ( F_39 ( V_105 -> V_12 == V_12 ) && ! F_61 ( ! V_12 -> V_12 ) )
F_17 ( V_12 -> V_12 ) ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
V_20 = - V_113 ;
} else {
struct V_13 * V_14 ;
if ( V_94 -> V_112 ) {
V_14 = F_66 ( V_12 -> V_12 , V_69 ) ;
if ( F_12 ( ! V_14 ) )
goto V_114;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_94 -> V_18 ;
V_94 -> V_27 = V_17 ;
V_94 -> V_12 = V_12 -> V_12 ;
V_94 -> V_14 = V_14 ;
V_14 -> V_15 = V_94 ;
V_14 -> F_50 = F_57 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
if ( F_12 ( V_20 ) ) {
F_56 ( V_12 -> V_12 , V_14 ) ;
goto V_114;
}
V_20 = - V_115 ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
} else {
F_67 ( V_116 ) ;
V_14 = V_12 -> V_14 ;
V_14 -> V_27 = V_17 ;
V_14 -> V_28 = V_94 -> V_18 ;
V_14 -> V_15 = & V_116 ;
V_14 -> F_50 = F_49 ;
V_20 = F_11 ( V_12 -> V_12 , V_14 , V_31 ) ;
F_9 ( & V_105 -> V_7 -> V_110 ) ;
if ( F_12 ( V_20 < 0 ) ) {
} else if ( F_12 (
F_13 ( & V_116 ) ) ) {
V_20 = - V_32 ;
F_14 ( V_12 -> V_12 , V_14 ) ;
} else {
V_20 = V_12 -> V_33 ;
if ( V_94 -> V_95 && V_20 > 0 ) {
V_20 = F_68 ( T_1 , V_20 , V_94 -> V_18 ) ;
if ( F_12 ( F_53 ( V_94 -> V_27 ,
V_17 , V_20 ) ) )
V_20 = - V_66 ;
}
}
F_34 ( V_17 ) ;
}
}
F_29 ( & V_105 -> V_42 ) ;
return V_20 ;
V_114:
F_9 ( & V_105 -> V_7 -> V_110 ) ;
F_29 ( & V_105 -> V_42 ) ;
error:
F_34 ( V_17 ) ;
return V_20 ;
}
static T_2
F_69 ( struct V_38 * V_38 , const char T_3 * V_27 , T_1 V_18 ,
T_4 * V_39 )
{
struct V_93 V_94 ;
F_20 () ;
V_94 . V_112 = false ;
V_94 . V_95 = false ;
V_94 . V_27 = ( char * T_3 ) V_27 ;
V_94 . V_18 = V_18 ;
return F_60 ( V_38 , & V_94 ) ;
}
static T_2
F_70 ( struct V_38 * V_38 , char T_3 * V_27 , T_1 V_18 , T_4 * V_39 )
{
struct V_93 V_94 ;
F_20 () ;
V_94 . V_112 = false ;
V_94 . V_95 = true ;
V_94 . V_27 = V_27 ;
V_94 . V_18 = V_18 ;
return F_60 ( V_38 , & V_94 ) ;
}
static int
F_71 ( struct V_71 * V_71 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_71 -> V_72 ;
F_20 () ;
if ( F_61 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_79 ;
V_38 -> V_40 = V_105 ;
F_42 ( V_105 -> V_7 ) ;
return 0 ;
}
static int F_72 ( struct V_102 * V_102 )
{
struct V_93 * V_94 = V_102 -> V_103 ;
struct V_104 * V_105 = V_102 -> V_117 -> V_40 ;
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
static T_2 F_73 ( struct V_102 * V_102 ,
const struct V_99 * V_99 ,
unsigned long V_98 , T_4 V_118 )
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
V_94 -> V_18 = V_102 -> V_119 ;
V_94 -> V_97 = V_120 -> V_97 ;
V_102 -> V_103 = V_94 ;
F_74 ( V_102 , F_72 ) ;
return F_60 ( V_102 -> V_117 , V_94 ) ;
}
static T_2 F_75 ( struct V_102 * V_102 ,
const struct V_99 * V_99 ,
unsigned long V_98 , T_4 V_118 )
{
struct V_93 * V_94 ;
struct V_99 * V_121 ;
F_20 () ;
V_121 = F_76 ( V_98 , sizeof( * V_121 ) , V_69 ) ;
if ( F_12 ( ! V_121 ) )
return - V_70 ;
memcpy ( V_121 , V_99 , sizeof( struct V_99 ) * V_98 ) ;
V_94 = F_40 ( sizeof( * V_94 ) , V_69 ) ;
if ( F_12 ( ! V_94 ) ) {
F_34 ( V_121 ) ;
return - V_70 ;
}
V_94 -> V_112 = true ;
V_94 -> V_95 = true ;
V_94 -> V_102 = V_102 ;
V_94 -> V_99 = V_121 ;
V_94 -> V_98 = V_98 ;
V_94 -> V_18 = V_102 -> V_119 ;
V_94 -> V_97 = V_120 -> V_97 ;
V_102 -> V_103 = V_94 ;
F_74 ( V_102 , F_72 ) ;
return F_60 ( V_102 -> V_117 , V_94 ) ;
}
static int
F_77 ( struct V_71 * V_71 , struct V_38 * V_38 )
{
struct V_104 * V_105 = V_71 -> V_72 ;
F_20 () ;
F_44 ( V_105 -> V_7 ) ;
return 0 ;
}
static long F_78 ( struct V_38 * V_38 , unsigned V_74 ,
unsigned long V_75 )
{
struct V_104 * V_105 = V_38 -> V_40 ;
int V_20 ;
F_20 () ;
if ( F_61 ( V_105 -> V_7 -> V_45 != V_50 ) )
return - V_79 ;
F_32 ( & V_105 -> V_7 -> V_110 ) ;
if ( F_39 ( V_105 -> V_12 ) ) {
switch ( V_74 ) {
case V_122 :
V_20 = F_79 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_123 :
F_80 ( V_105 -> V_12 -> V_12 ) ;
V_20 = 0 ;
break;
case V_124 :
V_20 = F_81 ( V_105 -> V_12 -> V_12 ) ;
break;
case V_125 :
V_20 = V_105 -> V_12 -> V_126 ;
break;
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
F_82 ( struct V_127 * V_128 , void * V_17 ,
const struct V_129 * V_130 ,
const struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_71 * V_71 ;
F_20 () ;
V_71 = F_83 ( V_128 ) ;
if ( F_39 ( V_71 ) ) {
struct V_135 V_136 = V_137 ;
V_71 -> V_138 = F_84 () ;
V_71 -> V_139 = V_134 -> V_140 ;
V_71 -> V_141 = V_134 -> V_142 ;
V_71 -> V_143 = V_134 -> V_144 ;
V_71 -> V_145 = V_136 ;
V_71 -> V_146 = V_136 ;
V_71 -> V_147 = V_136 ;
V_71 -> V_72 = V_17 ;
if ( V_130 )
V_71 -> V_148 = V_130 ;
if ( V_132 )
V_71 -> V_149 = V_132 ;
}
return V_71 ;
}
static struct V_71 * F_85 ( struct V_127 * V_128 ,
const char * V_150 , void * V_17 ,
const struct V_129 * V_130 ,
struct V_151 * * V_152 )
{
struct V_6 * V_7 = V_128 -> V_153 ;
struct V_151 * V_151 ;
struct V_71 * V_71 ;
F_20 () ;
V_151 = F_86 ( V_128 -> V_154 , V_150 ) ;
if ( F_12 ( ! V_151 ) )
return NULL ;
V_71 = F_82 ( V_128 , V_17 , V_130 , NULL , & V_7 -> V_155 ) ;
if ( F_12 ( ! V_71 ) ) {
F_87 ( V_151 ) ;
return NULL ;
}
F_88 ( V_151 , V_71 ) ;
if ( V_152 )
* V_152 = V_151 ;
return V_71 ;
}
static int F_89 ( struct V_127 * V_128 , void * V_156 , int V_157 )
{
struct V_158 * V_17 = V_156 ;
struct V_71 * V_71 ;
struct V_6 * V_7 = V_17 -> V_6 ;
F_20 () ;
V_7 -> V_128 = V_128 ;
V_17 -> V_6 = NULL ;
V_128 -> V_153 = V_7 ;
V_128 -> V_159 = V_160 ;
V_128 -> V_161 = V_162 ;
V_128 -> V_163 = V_164 ;
V_128 -> V_165 = & V_166 ;
V_128 -> V_167 = 1 ;
V_17 -> V_134 . V_140 = V_17 -> V_168 ;
V_71 = F_82 ( V_128 , NULL ,
& V_169 ,
& V_170 ,
& V_17 -> V_134 ) ;
V_128 -> V_154 = F_90 ( V_71 ) ;
if ( F_12 ( ! V_128 -> V_154 ) )
return - V_70 ;
if ( F_12 ( ! F_85 ( V_128 , L_5 , V_7 ,
& V_171 , NULL ) ) )
return - V_70 ;
return 0 ;
}
static int F_91 ( struct V_158 * V_17 , char * V_172 )
{
F_20 () ;
if ( ! V_172 || ! * V_172 )
return 0 ;
for (; ; ) {
unsigned long V_75 ;
char * V_173 , * V_174 ;
V_174 = strchr ( V_172 , ',' ) ;
if ( V_174 )
* V_174 = 0 ;
V_173 = strchr ( V_172 , '=' ) ;
if ( F_12 ( ! V_173 ) ) {
F_92 ( L_6 , V_172 ) ;
return - V_48 ;
}
* V_173 = 0 ;
if ( F_93 ( V_173 + 1 , 0 , & V_75 ) ) {
F_92 ( L_7 , V_172 , V_173 + 1 ) ;
return - V_48 ;
}
switch ( V_173 - V_172 ) {
case 5 :
if ( ! memcmp ( V_172 , L_8 , 5 ) )
V_17 -> V_168 = ( V_75 & 0555 ) | V_175 ;
else if ( ! memcmp ( V_172 , L_9 , 5 ) )
V_17 -> V_134 . V_140 = ( V_75 & 0666 ) | V_176 ;
else
goto V_177;
break;
case 4 :
if ( ! memcmp ( V_172 , L_10 , 4 ) ) {
V_17 -> V_168 = ( V_75 & 0555 ) | V_175 ;
V_17 -> V_134 . V_140 = ( V_75 & 0666 ) | V_176 ;
} else {
goto V_177;
}
break;
case 3 :
if ( ! memcmp ( V_172 , L_11 , 3 ) ) {
V_17 -> V_134 . V_142 = F_94 ( F_95 () , V_75 ) ;
if ( ! F_96 ( V_17 -> V_134 . V_142 ) ) {
F_92 ( L_12 , V_172 , V_75 ) ;
return - V_48 ;
}
} else if ( ! memcmp ( V_172 , L_13 , 3 ) ) {
V_17 -> V_134 . V_144 = F_97 ( F_95 () , V_75 ) ;
if ( ! F_98 ( V_17 -> V_134 . V_144 ) ) {
F_92 ( L_12 , V_172 , V_75 ) ;
return - V_48 ;
}
} else {
goto V_177;
}
break;
default:
V_177:
F_92 ( L_14 , V_172 ) ;
return - V_48 ;
}
if ( ! V_174 )
break;
V_172 = V_174 + 1 ;
}
return 0 ;
}
static struct V_151 *
F_99 ( struct V_178 * V_179 , int V_52 ,
const char * V_180 , void * V_172 )
{
struct V_158 V_17 = {
. V_134 = {
. V_140 = V_176 | 0600 ,
. V_142 = V_181 ,
. V_144 = V_182 ,
} ,
. V_168 = V_175 | 0500 ,
} ;
struct V_151 * V_183 ;
int V_20 ;
void * V_184 ;
struct V_6 * V_7 ;
F_20 () ;
V_20 = F_91 ( & V_17 , V_172 ) ;
if ( F_12 ( V_20 < 0 ) )
return F_100 ( V_20 ) ;
V_7 = F_101 () ;
if ( F_12 ( ! V_7 ) )
return F_100 ( - V_70 ) ;
V_7 -> V_155 = V_17 . V_134 ;
V_7 -> V_180 = F_102 ( V_180 , V_69 ) ;
if ( F_12 ( ! V_7 -> V_180 ) ) {
F_103 ( V_7 ) ;
return F_100 ( - V_70 ) ;
}
V_184 = F_104 ( V_180 ) ;
if ( F_23 ( V_184 ) ) {
F_103 ( V_7 ) ;
return F_105 ( V_184 ) ;
}
V_7 -> V_40 = V_184 ;
V_17 . V_6 = V_7 ;
V_183 = F_106 ( V_179 , V_52 , & V_17 , F_89 ) ;
if ( F_23 ( V_183 ) && V_17 . V_6 ) {
F_107 ( V_17 . V_6 ) ;
F_103 ( V_17 . V_6 ) ;
}
return V_183 ;
}
static void
F_108 ( struct V_127 * V_128 )
{
F_20 () ;
F_109 ( V_128 ) ;
if ( V_128 -> V_153 ) {
F_107 ( V_128 -> V_153 ) ;
F_103 ( V_128 -> V_153 ) ;
}
}
static int F_110 ( void )
{
int V_20 ;
F_20 () ;
V_20 = F_111 ( & V_185 ) ;
if ( F_39 ( ! V_20 ) )
F_25 ( L_15 ) ;
else
F_92 ( L_16 , V_20 ) ;
return V_20 ;
}
static void F_112 ( void )
{
F_20 () ;
F_25 ( L_17 ) ;
F_113 ( & V_185 ) ;
}
static void F_114 ( struct V_6 * V_7 )
{
F_20 () ;
F_115 ( & V_7 -> V_186 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_20 () ;
F_115 ( & V_7 -> V_186 ) ;
F_115 ( & V_7 -> V_187 ) ;
}
static void F_103 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_12 ( F_116 ( & V_7 -> V_186 ) ) ) {
F_25 ( L_18 , V_188 ) ;
F_117 ( V_7 ) ;
F_118 ( F_119 ( & V_7 -> V_22 . V_25 ) ||
F_119 ( & V_7 -> V_16 . V_83 ) ) ;
F_34 ( V_7 -> V_180 ) ;
F_34 ( V_7 ) ;
}
}
static void F_44 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_116 ( & V_7 -> V_187 ) ) {
V_7 -> V_45 = V_49 ;
F_120 ( V_7 ) ;
}
F_103 ( V_7 ) ;
}
static struct V_6 * F_101 ( void )
{
struct V_6 * V_7 = F_121 ( sizeof *V_7 , V_69 ) ;
if ( F_12 ( ! V_7 ) )
return NULL ;
F_20 () ;
F_122 ( & V_7 -> V_186 , 1 ) ;
F_122 ( & V_7 -> V_187 , 0 ) ;
V_7 -> V_45 = V_46 ;
F_123 ( & V_7 -> V_42 ) ;
F_124 ( & V_7 -> V_110 ) ;
F_125 ( & V_7 -> V_22 . V_25 ) ;
F_126 ( & V_7 -> V_16 ) ;
V_7 -> V_22 . V_35 = 1 ;
return V_7 ;
}
static void F_117 ( struct V_6 * V_7 )
{
F_20 () ;
if ( F_127 ( V_51 , & V_7 -> V_52 ) )
F_128 ( V_7 ) ;
F_118 ( V_7 -> V_29 ) ;
if ( V_7 -> V_189 )
F_129 ( V_7 -> V_189 , V_7 -> V_190 ) ;
F_34 ( V_7 -> V_191 ) ;
F_34 ( V_7 -> V_192 ) ;
F_34 ( V_7 -> V_193 ) ;
}
static void F_120 ( struct V_6 * V_7 )
{
F_20 () ;
F_117 ( V_7 ) ;
V_7 -> V_189 = NULL ;
V_7 -> V_191 = NULL ;
V_7 -> V_194 = NULL ;
V_7 -> V_192 = NULL ;
V_7 -> V_193 = NULL ;
V_7 -> V_195 = 0 ;
V_7 -> V_196 = 0 ;
V_7 -> V_197 = 0 ;
V_7 -> V_198 = 0 ;
V_7 -> V_199 = 0 ;
V_7 -> V_200 = 0 ;
V_7 -> V_190 = 0 ;
V_7 -> V_22 . V_65 = 0 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_8 = V_10 ;
V_7 -> V_52 = 0 ;
}
static int F_130 ( struct V_6 * V_7 , struct V_201 * V_202 )
{
struct V_203 * * V_204 ;
int V_205 ;
F_20 () ;
if ( F_61 ( V_7 -> V_45 != V_50
|| F_131 ( V_206 , & V_7 -> V_52 ) ) )
return - V_57 ;
V_205 = F_132 ( V_202 , V_7 -> V_199 ) ;
if ( F_12 ( V_205 < 0 ) )
return V_205 ;
V_7 -> V_19 = F_66 ( V_202 -> V_29 -> V_30 , V_69 ) ;
if ( F_12 ( ! V_7 -> V_19 ) )
return - V_70 ;
V_7 -> V_19 -> F_50 = F_5 ;
V_7 -> V_19 -> V_15 = V_7 ;
V_204 = V_7 -> V_193 ;
if ( V_204 ) {
for (; * V_204 ; ++ V_204 ) {
struct V_207 * V_208 = ( * V_204 ) -> V_209 ;
int V_210 = V_205 ;
for (; V_208 -> V_211 ; ++ V_210 , ++ V_208 )
V_208 -> V_210 = V_210 ;
}
}
V_7 -> V_29 = V_202 -> V_29 ;
F_114 ( V_7 ) ;
return 0 ;
}
static void F_133 ( struct V_6 * V_7 )
{
F_20 () ;
if ( ! F_61 ( ! V_7 -> V_29 ) ) {
F_56 ( V_7 -> V_29 -> V_30 , V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_29 = NULL ;
F_134 ( V_206 , & V_7 -> V_52 ) ;
F_103 ( V_7 ) ;
}
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_104 * V_105 , * V_189 ;
unsigned V_61 , V_65 ;
F_20 () ;
V_65 = V_7 -> V_190 ;
V_189 = F_135 ( V_65 , sizeof( * V_189 ) , V_69 ) ;
if ( ! V_189 )
return - V_70 ;
V_105 = V_189 ;
for ( V_61 = 1 ; V_61 <= V_65 ; ++ V_61 , ++ V_105 ) {
V_105 -> V_7 = V_7 ;
F_123 ( & V_105 -> V_42 ) ;
F_125 ( & V_105 -> V_83 ) ;
sprintf ( V_189 -> V_150 , L_19 , V_61 ) ;
if ( ! F_12 ( F_85 ( V_7 -> V_128 , V_189 -> V_150 , V_105 ,
& V_212 ,
& V_105 -> V_151 ) ) ) {
F_129 ( V_189 , V_61 - 1 ) ;
return - V_70 ;
}
}
V_7 -> V_189 = V_189 ;
return 0 ;
}
static void F_129 ( struct V_104 * V_189 , unsigned V_65 )
{
struct V_104 * V_105 = V_189 ;
F_20 () ;
for (; V_65 ; -- V_65 , ++ V_105 ) {
F_118 ( F_136 ( & V_105 -> V_42 ) ||
F_119 ( & V_105 -> V_83 ) ) ;
if ( V_105 -> V_151 ) {
F_137 ( V_105 -> V_151 ) ;
F_87 ( V_105 -> V_151 ) ;
V_105 -> V_151 = NULL ;
}
}
F_34 ( V_189 ) ;
}
static void F_138 ( struct V_1 * V_78 )
{
struct V_89 * V_12 = V_78 -> V_213 ;
struct V_104 * V_105 = V_78 -> V_7 -> V_189 ;
unsigned V_65 = V_78 -> V_7 -> V_190 ;
unsigned long V_52 ;
F_139 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
do {
if ( F_39 ( V_12 -> V_12 ) )
F_140 ( V_12 -> V_12 ) ;
V_105 -> V_12 = NULL ;
++ V_12 ;
++ V_105 ;
} while ( -- V_65 );
F_141 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
}
static int F_142 ( struct V_1 * V_78 )
{
struct V_6 * V_7 = V_78 -> V_7 ;
struct V_89 * V_12 = V_78 -> V_213 ;
struct V_104 * V_105 = V_7 -> V_189 ;
unsigned V_65 = V_7 -> V_190 ;
unsigned long V_52 ;
int V_20 = 0 ;
F_139 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
do {
struct V_214 * V_215 ;
int V_216 ;
if ( V_7 -> V_29 -> V_217 == V_218 )
V_216 = 2 ;
else if ( V_7 -> V_29 -> V_217 == V_219 )
V_216 = 1 ;
else
V_216 = 0 ;
do {
V_215 = V_12 -> V_220 [ V_216 ] ;
} while ( ! V_215 && -- V_216 >= 0 );
if ( ! V_215 ) {
V_20 = - V_48 ;
break;
}
V_12 -> V_12 -> V_90 = V_12 ;
V_12 -> V_12 -> V_221 = V_215 ;
V_20 = F_143 ( V_12 -> V_12 ) ;
if ( F_39 ( ! V_20 ) ) {
V_105 -> V_12 = V_12 ;
V_105 -> V_108 = F_144 ( V_215 ) ;
V_105 -> V_109 = F_145 ( V_215 ) ;
} else {
break;
}
F_146 ( & V_105 -> V_83 ) ;
++ V_12 ;
++ V_105 ;
} while ( -- V_65 );
F_141 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
return V_20 ;
}
static int T_6 F_147 ( char * V_17 , unsigned V_18 ,
T_7 V_222 , void * V_223 )
{
struct V_224 * V_225 = ( void * ) V_17 ;
T_8 V_28 ;
int V_20 ;
F_20 () ;
if ( V_18 < 2 ) {
F_16 ( L_20 ) ;
return - V_48 ;
}
V_28 = V_225 -> V_226 ;
if ( V_18 < V_28 ) {
F_16 ( L_21 ) ;
return - V_48 ;
}
#define F_148 ( T_9 ) 1
#define F_149 ( T_9 ) (val)
#define F_150 ( T_9 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_151 ( type , T_9 ) do { \
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
switch ( V_225 -> V_227 ) {
case V_228 :
case V_229 :
case V_230 :
case V_231 :
F_16 ( L_22 ,
V_225 -> V_227 ) ;
return - V_48 ;
case V_232 : {
struct V_233 * V_215 = ( void * ) V_225 ;
F_16 ( L_23 ) ;
if ( V_28 != sizeof *V_215 )
goto V_234;
F_151 ( V_235 , V_215 -> V_236 ) ;
if ( V_215 -> V_237 )
F_151 ( STRING , V_215 -> V_237 ) ;
}
break;
case V_238 : {
struct V_214 * V_215 = ( void * ) V_225 ;
F_16 ( L_24 ) ;
if ( V_28 != V_239 &&
V_28 != V_240 )
goto V_234;
F_151 ( V_241 , V_215 -> V_242 ) ;
}
break;
case V_243 :
F_16 ( L_25 ) ;
if ( V_28 != sizeof( struct V_244 ) )
goto V_234;
break;
case V_245 :
if ( V_28 != sizeof( struct V_246 ) )
goto V_234;
break;
case V_247 : {
struct V_248 * V_215 = ( void * ) V_225 ;
F_16 ( L_26 ) ;
if ( V_28 != sizeof *V_215 )
goto V_234;
if ( V_215 -> V_249 )
F_151 ( STRING , V_215 -> V_249 ) ;
}
break;
case V_250 :
F_16 ( L_27 ) ;
if ( V_28 != sizeof( struct V_251 ) )
goto V_234;
break;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
F_16 ( L_28 , V_225 -> V_227 ) ;
return - V_48 ;
default:
F_16 ( L_29 , V_225 -> V_227 ) ;
return - V_48 ;
V_234:
F_16 ( L_30 ,
V_225 -> V_226 , V_225 -> V_227 ) ;
return - V_48 ;
}
#undef F_151
#undef V_257
#undef F_148
#undef F_149
#undef F_150
return V_28 ;
}
static int T_6 F_152 ( unsigned V_65 , char * V_17 , unsigned V_18 ,
T_7 V_222 , void * V_223 )
{
const unsigned V_258 = V_18 ;
unsigned long V_126 = 0 ;
F_20 () ;
for (; ; ) {
int V_20 ;
if ( V_126 == V_65 )
V_17 = NULL ;
V_20 = V_222 ( V_259 , ( T_8 * ) V_126 , ( void * ) V_17 , V_223 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_31 ,
V_126 , V_20 ) ;
return V_20 ;
}
if ( ! V_17 )
return V_258 - V_18 ;
V_20 = F_147 ( V_17 , V_18 , V_222 , V_223 ) ;
if ( F_12 ( V_20 < 0 ) ) {
F_18 ( L_32 , V_188 , V_20 ) ;
return V_20 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
++ V_126 ;
}
}
static int F_153 ( enum V_260 type ,
T_8 * V_261 , struct V_224 * V_221 ,
void * V_223 )
{
struct V_6 * V_7 = V_223 ;
F_20 () ;
switch ( type ) {
case V_259 :
break;
case V_262 :
if ( * V_261 >= V_7 -> V_200 )
V_7 -> V_200 = * V_261 + 1 ;
break;
case V_263 :
if ( * V_261 > V_7 -> V_199 )
V_7 -> V_199 = * V_261 ;
break;
case V_264 :
if ( ( * V_261 & V_265 ) > V_7 -> V_190 )
V_7 -> V_190 = ( * V_261 & V_265 ) ;
break;
}
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
char * const V_156 , T_1 V_18 )
{
char * V_17 = V_156 , * V_194 ;
unsigned V_266 [ 3 ] , V_52 ;
int V_20 = - V_48 , V_61 ;
F_20 () ;
if ( F_154 ( V_17 + 4 ) != V_18 )
goto error;
switch ( F_154 ( V_17 ) ) {
case V_267 :
V_52 = V_268 | V_269 ;
V_17 += 8 ;
V_18 -= 8 ;
break;
case V_270 :
V_52 = F_154 ( V_17 + 8 ) ;
if ( V_52 & ~ ( V_268 |
V_269 |
V_271 ) ) {
V_20 = - V_272 ;
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
V_266 [ V_61 ] = 0 ;
} else if ( V_18 < 4 ) {
goto error;
} else {
V_266 [ V_61 ] = F_154 ( V_17 ) ;
V_17 += 4 ;
V_18 -= 4 ;
}
}
V_194 = V_17 ;
for ( V_61 = 0 ; V_61 < 3 ; ++ V_61 ) {
if ( ! V_266 [ V_61 ] )
continue;
V_20 = F_152 ( V_266 [ V_61 ] , V_17 , V_18 ,
F_153 , V_7 ) ;
if ( V_20 < 0 )
goto error;
V_17 += V_20 ;
V_18 -= V_20 ;
}
if ( V_194 == V_17 || V_18 ) {
V_20 = - V_48 ;
goto error;
}
V_7 -> V_191 = V_156 ;
V_7 -> V_194 = V_194 ;
V_7 -> V_195 = V_17 - V_194 ;
V_7 -> V_196 = V_266 [ 0 ] ;
V_7 -> V_197 = V_266 [ 1 ] ;
V_7 -> V_198 = V_266 [ 2 ] ;
return 0 ;
error:
F_34 ( V_156 ) ;
return V_20 ;
}
static int F_27 ( struct V_6 * V_7 ,
char * const V_156 , T_1 V_18 )
{
T_10 V_273 , V_274 , V_275 ;
struct V_203 * * V_193 , * V_179 ;
struct V_207 * V_209 , * V_211 ;
const char * V_17 = V_156 ;
F_20 () ;
if ( F_12 ( F_154 ( V_17 ) != V_276 ||
F_154 ( V_17 + 4 ) != V_18 ) )
goto error;
V_273 = F_154 ( V_17 + 8 ) ;
V_275 = F_154 ( V_17 + 12 ) ;
if ( F_12 ( ! V_273 != ! V_275 ) )
goto error;
V_274 = V_7 -> V_199 ;
if ( F_12 ( V_273 < V_274 ) )
goto error;
if ( ! V_274 ) {
F_34 ( V_156 ) ;
return 0 ;
}
{
unsigned V_61 = 0 ;
F_155 ( V_277 ) ;
F_156 ( V_277 , struct V_203 * , V_193 ,
V_275 + 1 ) ;
F_156 ( V_277 , struct V_203 , V_278 , V_275 ) ;
F_156 ( V_277 , struct V_207 , V_209 ,
V_275 * ( V_274 + 1 ) ) ;
char * V_279 = F_40 ( F_157 ( V_277 ) , V_69 ) ;
if ( F_12 ( ! V_279 ) ) {
F_34 ( V_156 ) ;
return - V_70 ;
}
V_193 = F_158 ( V_279 , V_277 , V_193 ) ;
V_179 = F_158 ( V_279 , V_277 , V_278 ) ;
V_61 = V_275 ;
do {
* V_193 ++ = V_179 ++ ;
} while ( -- V_61 );
* V_193 = NULL ;
V_193 = F_158 ( V_279 , V_277 , V_193 ) ;
V_179 = F_158 ( V_279 , V_277 , V_278 ) ;
V_211 = F_158 ( V_279 , V_277 , V_209 ) ;
V_209 = V_211 ;
}
V_17 += 16 ;
V_18 -= 16 ;
do {
unsigned V_280 = V_274 ;
if ( F_12 ( V_18 < 3 ) )
goto V_281;
V_179 -> V_282 = F_159 ( V_17 ) ;
V_179 -> V_209 = V_211 ;
++ V_179 ;
V_17 += 2 ;
V_18 -= 2 ;
do {
T_1 V_28 = F_160 ( V_17 , V_18 ) ;
if ( F_12 ( V_28 == V_18 ) )
goto V_281;
if ( F_39 ( V_280 ) ) {
V_211 -> V_211 = V_17 ;
-- V_280 ;
++ V_211 ;
}
V_17 += V_28 + 1 ;
V_18 -= V_28 + 1 ;
} while ( -- V_273 );
V_211 -> V_210 = 0 ;
V_211 -> V_211 = NULL ;
++ V_211 ;
} while ( -- V_275 );
if ( F_12 ( V_18 ) )
goto V_281;
V_7 -> V_193 = V_193 ;
V_7 -> V_192 = V_156 ;
return 0 ;
V_281:
F_34 ( V_193 ) ;
error:
F_34 ( V_156 ) ;
return - V_48 ;
}
static void F_161 ( struct V_6 * V_7 ,
enum V_283 type )
{
enum V_283 V_284 , V_285 = type ;
int V_286 = 0 ;
if ( V_7 -> V_8 == V_54 )
V_7 -> V_8 = V_9 ;
switch ( type ) {
case V_287 :
V_285 = V_288 ;
case V_288 :
case V_63 :
V_284 = type ;
break;
case V_289 :
case V_290 :
case V_291 :
case V_292 :
V_284 = V_288 ;
V_285 = V_287 ;
V_286 = 1 ;
break;
default:
F_162 () ;
}
{
T_8 * V_22 = V_7 -> V_22 . V_62 , * V_293 = V_22 ;
unsigned V_58 = V_7 -> V_22 . V_65 ;
for (; V_58 ; -- V_58 , ++ V_22 )
if ( ( * V_22 == V_284 || * V_22 == V_285 ) == V_286 )
* V_293 ++ = * V_22 ;
else
F_16 ( L_33 , * V_22 ) ;
V_7 -> V_22 . V_65 = V_293 - V_7 -> V_22 . V_62 ;
}
F_16 ( L_34 , type ) ;
V_7 -> V_22 . V_62 [ V_7 -> V_22 . V_65 ++ ] = type ;
F_163 ( & V_7 -> V_22 . V_25 ) ;
}
static void F_164 ( struct V_6 * V_7 ,
enum V_283 type )
{
unsigned long V_52 ;
F_139 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
F_161 ( V_7 , type ) ;
F_141 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
}
static int F_165 ( enum V_260 type , T_8 * V_261 ,
struct V_224 * V_221 ,
void * V_223 )
{
struct V_214 * V_215 = ( void * ) V_221 ;
struct V_1 * V_78 = V_223 ;
struct V_89 * V_89 ;
unsigned V_294 , V_295 ;
static const char * V_296 [] = { L_35 , L_36 , L_37 } ;
if ( type != V_259 )
return 0 ;
if ( V_78 -> V_4 . V_297 ) {
V_294 = 2 ;
V_78 -> V_4 . V_297 [ ( long ) V_261 ] = V_221 ;
} else if ( V_78 -> V_4 . V_298 ) {
V_294 = 1 ;
V_78 -> V_4 . V_298 [ ( long ) V_261 ] = V_221 ;
} else {
V_294 = 0 ;
V_78 -> V_4 . V_299 [ ( long ) V_261 ] = V_221 ;
}
if ( ! V_221 || V_221 -> V_227 != V_238 )
return 0 ;
V_295 = ( V_215 -> V_242 & V_265 ) - 1 ;
V_89 = V_78 -> V_213 + V_295 ;
if ( F_12 ( V_89 -> V_220 [ V_294 ] ) ) {
F_92 ( L_38 ,
V_296 [ V_294 ] ,
V_215 -> V_242 & V_265 ) ;
return - V_48 ;
}
V_89 -> V_220 [ V_294 ] = V_215 ;
F_166 ( L_39 , V_215 , V_215 -> V_226 ) ;
if ( V_89 -> V_12 ) {
V_215 -> V_242 = V_89 -> V_220 [ 0 ] -> V_242 ;
if ( ! V_215 -> V_300 )
V_215 -> V_300 = V_89 -> V_220 [ 0 ] -> V_300 ;
} else {
struct V_13 * V_14 ;
struct V_11 * V_12 ;
F_16 ( L_40 ) ;
V_12 = F_167 ( V_78 -> V_29 , V_215 ) ;
if ( F_12 ( ! V_12 ) )
return - V_301 ;
V_12 -> V_90 = V_78 -> V_213 + V_295 ;
V_14 = F_66 ( V_12 , V_69 ) ;
if ( F_12 ( ! V_14 ) )
return - V_70 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_14 = V_14 ;
V_78 -> V_302 [ V_215 -> V_242 &
V_265 ] = V_295 + 1 ;
}
F_166 ( L_41 , V_215 , V_215 -> V_226 ) ;
return 0 ;
}
static int F_168 ( enum V_260 type , T_8 * V_261 ,
struct V_224 * V_221 ,
void * V_223 )
{
struct V_1 * V_78 = V_223 ;
unsigned V_295 ;
T_8 V_303 ;
switch ( type ) {
default:
case V_259 :
return 0 ;
case V_262 :
V_295 = * V_261 ;
if ( V_78 -> V_304 [ V_295 ] < 0 ) {
int V_210 = F_169 ( V_78 -> V_305 , & V_78 -> V_4 ) ;
if ( F_12 ( V_210 < 0 ) )
return V_210 ;
V_78 -> V_304 [ V_295 ] = V_210 ;
}
V_303 = V_78 -> V_304 [ V_295 ] ;
break;
case V_263 :
V_303 = V_78 -> V_7 -> V_193 [ 0 ] -> V_209 [ * V_261 - 1 ] . V_210 ;
break;
case V_264 :
if ( V_221 -> V_227 == V_238 )
return 0 ;
V_295 = ( * V_261 & V_265 ) - 1 ;
if ( F_12 ( ! V_78 -> V_213 [ V_295 ] . V_12 ) )
return - V_48 ;
{
struct V_214 * * V_220 ;
V_220 = V_78 -> V_213 [ V_295 ] . V_220 ;
V_303 = V_220 [ V_220 [ 0 ] ? 0 : 1 ] -> V_242 ;
}
break;
}
F_16 ( L_42 , * V_261 , V_303 ) ;
* V_261 = V_303 ;
return 0 ;
}
static inline struct V_306 * F_170 ( struct V_2 * V_3 ,
struct V_307 * V_308 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_306 * V_309 =
F_2 ( V_3 -> V_310 , struct V_306 , V_311 ) ;
int V_20 ;
F_20 () ;
if ( ! V_309 -> V_312 )
F_171 () ;
V_20 = V_309 -> V_313 -> V_314 ? 0 : - V_79 ;
V_78 -> V_7 = V_309 -> V_313 -> V_6 ;
if ( ! V_309 -> V_312 )
F_172 () ;
if ( V_20 )
return F_100 ( V_20 ) ;
V_78 -> V_305 = V_308 ;
V_78 -> V_29 = V_308 -> V_202 -> V_29 ;
F_114 ( V_78 -> V_7 ) ;
if ( ! V_309 -> V_315 ) {
V_20 = F_130 ( V_78 -> V_7 , V_308 -> V_202 ) ;
if ( V_20 )
return F_100 ( V_20 ) ;
}
V_309 -> V_315 ++ ;
V_78 -> V_4 . V_209 = V_78 -> V_7 -> V_193 ;
return V_309 ;
}
static int F_173 ( struct V_307 * V_308 ,
struct V_2 * V_3 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
const int V_316 = ! ! V_78 -> V_7 -> V_196 ;
const int V_317 = F_174 ( V_78 -> V_29 ) &&
V_78 -> V_7 -> V_197 ;
const int V_318 = F_175 ( V_78 -> V_29 ) &&
V_78 -> V_7 -> V_198 ;
int V_319 , V_320 , V_20 ;
F_155 ( V_277 ) ;
F_176 ( V_277 , struct V_89 , V_213 , V_7 -> V_190 ) ;
F_176 ( V_277 , struct V_224 * , V_321 ,
V_316 ? V_7 -> V_196 + 1 : 0 ) ;
F_176 ( V_277 , struct V_224 * , V_322 ,
V_317 ? V_7 -> V_197 + 1 : 0 ) ;
F_176 ( V_277 , struct V_224 * , V_323 ,
V_318 ? V_7 -> V_198 + 1 : 0 ) ;
F_176 ( V_277 , short , V_324 , V_7 -> V_200 ) ;
F_176 ( V_277 , char , V_194 , V_7 -> V_195 ) ;
char * V_279 ;
F_20 () ;
if ( F_12 ( ! ( V_316 | V_317 | V_318 ) ) )
return - V_301 ;
V_279 = F_40 ( F_157 ( V_277 ) , V_69 ) ;
if ( F_12 ( ! V_279 ) )
return - V_70 ;
memset ( F_158 ( V_279 , V_277 , V_213 ) , 0 , V_325 ) ;
memcpy ( F_158 ( V_279 , V_277 , V_194 ) , V_7 -> V_194 ,
V_7 -> V_195 ) ;
memset ( F_158 ( V_279 , V_277 , V_324 ) , 0xff , V_326 ) ;
for ( V_20 = V_7 -> V_190 ; V_20 ; -- V_20 ) {
struct V_89 * V_39 ;
V_39 = F_158 ( V_279 , V_277 , V_213 ) ;
V_39 [ V_20 ] . V_126 = - 1 ;
}
V_78 -> V_213 = F_158 ( V_279 , V_277 , V_213 ) ;
V_78 -> V_304 = F_158 ( V_279 , V_277 , V_324 ) ;
if ( F_39 ( V_316 ) ) {
V_78 -> V_4 . V_299 = F_158 ( V_279 , V_277 , V_321 ) ;
V_319 = F_152 ( V_7 -> V_196 ,
F_158 ( V_279 , V_277 , V_194 ) ,
V_327 ,
F_165 , V_78 ) ;
if ( F_12 ( V_319 < 0 ) ) {
V_20 = V_319 ;
goto error;
}
} else {
V_319 = 0 ;
}
if ( F_39 ( V_317 ) ) {
V_78 -> V_4 . V_298 = F_158 ( V_279 , V_277 , V_322 ) ;
V_320 = F_152 ( V_7 -> V_197 ,
F_158 ( V_279 , V_277 , V_194 ) + V_319 ,
V_327 - V_319 ,
F_165 , V_78 ) ;
if ( F_12 ( V_320 < 0 ) ) {
V_20 = V_320 ;
goto error;
}
} else {
V_320 = 0 ;
}
if ( F_39 ( V_318 ) ) {
V_78 -> V_4 . V_297 = F_158 ( V_279 , V_277 , V_323 ) ;
V_20 = F_152 ( V_7 -> V_198 ,
F_158 ( V_279 , V_277 , V_194 ) + V_319 + V_320 ,
V_327 - V_319 - V_320 ,
F_165 , V_78 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
}
V_20 = F_152 ( V_7 -> V_196 +
( V_317 ? V_7 -> V_197 : 0 ) +
( V_318 ? V_7 -> V_198 : 0 ) ,
F_158 ( V_279 , V_277 , V_194 ) , V_327 ,
F_168 , V_78 ) ;
if ( F_12 ( V_20 < 0 ) )
goto error;
F_164 ( V_7 , V_289 ) ;
return 0 ;
error:
return V_20 ;
}
static int F_177 ( struct V_307 * V_308 ,
struct V_2 * V_3 )
{
struct V_306 * V_309 = F_170 ( V_3 , V_308 ) ;
if ( F_23 ( V_309 ) )
return F_24 ( V_309 ) ;
return F_173 ( V_308 , V_3 ) ;
}
static int F_178 ( struct V_2 * V_3 ,
unsigned V_328 , unsigned V_329 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
int V_20 = 0 , V_330 ;
if ( V_329 != ( unsigned ) - 1 ) {
V_330 = F_46 ( V_78 , V_328 ) ;
if ( F_12 ( V_330 < 0 ) )
return V_330 ;
}
if ( V_7 -> V_78 )
F_138 ( V_7 -> V_78 ) ;
if ( V_7 -> V_45 != V_50 )
return - V_79 ;
if ( V_329 == ( unsigned ) - 1 ) {
V_7 -> V_78 = NULL ;
F_164 ( V_7 , V_291 ) ;
return 0 ;
}
V_7 -> V_78 = V_78 ;
V_20 = F_142 ( V_78 ) ;
if ( F_39 ( V_20 >= 0 ) )
F_164 ( V_7 , V_292 ) ;
return V_20 ;
}
static void F_179 ( struct V_2 * V_3 )
{
F_178 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_180 ( struct V_2 * V_3 ,
const struct V_331 * V_332 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
unsigned long V_52 ;
int V_20 ;
F_20 () ;
F_16 ( L_43 , V_332 -> V_55 ) ;
F_16 ( L_44 , V_332 -> V_333 ) ;
F_16 ( L_45 , F_8 ( V_332 -> V_334 ) ) ;
F_16 ( L_46 , F_8 ( V_332 -> V_335 ) ) ;
F_16 ( L_47 , F_8 ( V_332 -> V_24 ) ) ;
if ( V_7 -> V_45 != V_50 )
return - V_79 ;
switch ( V_332 -> V_55 & V_336 ) {
case V_337 :
V_20 = F_46 ( V_78 , F_8 ( V_332 -> V_335 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
case V_338 :
V_20 = F_181 ( V_78 , F_8 ( V_332 -> V_335 ) ) ;
if ( F_12 ( V_20 < 0 ) )
return V_20 ;
break;
default:
return - V_339 ;
}
F_139 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
V_7 -> V_22 . V_23 = * V_332 ;
V_7 -> V_22 . V_23 . V_335 = F_182 ( V_20 ) ;
F_161 ( V_7 , V_63 ) ;
F_141 ( & V_7 -> V_22 . V_25 . V_26 , V_52 ) ;
return 0 ;
}
static void F_183 ( struct V_2 * V_3 )
{
F_20 () ;
F_164 ( F_1 ( V_3 ) -> V_7 , V_288 ) ;
}
static void F_184 ( struct V_2 * V_3 )
{
F_20 () ;
F_164 ( F_1 ( V_3 ) -> V_7 , V_287 ) ;
}
static int F_181 ( struct V_1 * V_78 , T_8 V_126 )
{
V_126 = V_78 -> V_302 [ V_126 & V_265 ] ;
return V_126 ? V_126 : - V_340 ;
}
static int F_46 ( struct V_1 * V_78 , T_8 V_330 )
{
short * V_341 = V_78 -> V_304 ;
unsigned V_65 = V_78 -> V_7 -> V_200 ;
for (; V_65 ; -- V_65 , ++ V_341 ) {
if ( * V_341 >= 0 && * V_341 == V_330 )
return V_341 - V_78 -> V_304 ;
}
return - V_340 ;
}
static struct V_184 * F_185 ( const char * V_150 )
{
struct V_184 * V_313 ;
F_186 (dev, &ffs_devices, entry) {
if ( ! V_313 -> V_150 || ! V_150 )
continue;
if ( strcmp ( V_313 -> V_150 , V_150 ) == 0 )
return V_313 ;
}
return NULL ;
}
static struct V_184 * F_187 ( void )
{
struct V_184 * V_313 ;
if ( F_188 ( & V_342 ) ) {
V_313 = F_189 ( & V_342 , struct V_184 , V_343 ) ;
if ( V_313 -> V_344 )
return V_313 ;
}
return NULL ;
}
static struct V_184 * F_190 ( const char * V_150 )
{
struct V_184 * V_313 ;
V_313 = F_187 () ;
if ( V_313 )
return V_313 ;
return F_185 ( V_150 ) ;
}
static inline struct V_306 * F_191 ( struct V_345 * V_346 )
{
return F_2 ( F_192 ( V_346 ) , struct V_306 ,
V_311 . V_347 ) ;
}
static void F_193 ( struct V_345 * V_346 )
{
struct V_306 * V_172 = F_191 ( V_346 ) ;
F_194 ( & V_172 -> V_311 ) ;
}
static void F_195 ( struct V_348 * V_3 )
{
struct V_306 * V_172 ;
V_172 = F_196 ( V_3 ) ;
F_171 () ;
F_197 ( V_172 -> V_313 ) ;
F_172 () ;
F_34 ( V_172 ) ;
}
static int F_198 ( struct V_348 * V_310 , const char * V_150 )
{
struct V_306 * V_172 ;
char * V_39 ;
const char * V_349 ;
int V_350 , V_20 ;
V_350 = strlen ( V_150 ) + 1 ;
if ( V_350 > V_351 )
return - V_352 ;
V_39 = F_199 ( V_150 , V_350 , V_69 ) ;
if ( ! V_39 )
return - V_70 ;
V_172 = F_196 ( V_310 ) ;
V_349 = NULL ;
F_171 () ;
V_349 = V_172 -> V_313 -> V_353 ? V_172 -> V_313 -> V_150 : NULL ;
V_20 = F_200 ( V_172 -> V_313 , V_39 ) ;
if ( V_20 ) {
F_34 ( V_39 ) ;
F_172 () ;
return V_20 ;
}
V_172 -> V_313 -> V_353 = true ;
F_172 () ;
F_34 ( V_349 ) ;
return 0 ;
}
static struct V_348 * F_201 ( void )
{
struct V_306 * V_172 ;
struct V_184 * V_313 ;
V_172 = F_121 ( sizeof( * V_172 ) , V_69 ) ;
if ( ! V_172 )
return F_100 ( - V_70 ) ;
V_172 -> V_311 . V_354 = F_198 ;
V_172 -> V_311 . V_355 = F_195 ;
F_171 () ;
V_313 = F_202 () ;
F_172 () ;
if ( F_23 ( V_313 ) ) {
F_34 ( V_172 ) ;
return F_105 ( V_313 ) ;
}
V_172 -> V_313 = V_313 ;
V_313 -> V_172 = V_172 ;
F_203 ( & V_172 -> V_311 . V_347 , L_48 ,
& V_356 ) ;
return & V_172 -> V_311 ;
}
static void F_204 ( struct V_2 * V_3 )
{
F_34 ( F_1 ( V_3 ) ) ;
}
static void F_205 ( struct V_307 * V_308 ,
struct V_2 * V_3 )
{
struct V_1 * V_78 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_78 -> V_7 ;
struct V_306 * V_172 =
F_2 ( V_3 -> V_310 , struct V_306 , V_311 ) ;
struct V_89 * V_12 = V_78 -> V_213 ;
unsigned V_65 = V_7 -> V_190 ;
unsigned long V_52 ;
F_20 () ;
if ( V_7 -> V_78 == V_78 ) {
F_138 ( V_78 ) ;
V_7 -> V_78 = NULL ;
}
if ( ! -- V_172 -> V_315 )
F_133 ( V_7 ) ;
F_139 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
do {
if ( V_12 -> V_12 && V_12 -> V_14 )
F_56 ( V_12 -> V_12 , V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
++ V_12 ;
} while ( -- V_65 );
F_141 ( & V_78 -> V_7 -> V_110 , V_52 ) ;
F_34 ( V_78 -> V_213 ) ;
V_78 -> V_213 = NULL ;
V_78 -> V_4 . V_299 = NULL ;
V_78 -> V_4 . V_298 = NULL ;
V_78 -> V_4 . V_297 = NULL ;
V_78 -> V_304 = NULL ;
F_164 ( V_7 , V_290 ) ;
}
static struct V_2 * F_206 ( struct V_348 * V_310 )
{
struct V_1 * V_78 ;
F_20 () ;
V_78 = F_121 ( sizeof( * V_78 ) , V_69 ) ;
if ( F_12 ( ! V_78 ) )
return F_100 ( - V_70 ) ;
V_78 -> V_4 . V_150 = L_49 ;
V_78 -> V_4 . V_357 = F_177 ;
V_78 -> V_4 . V_358 = F_205 ;
V_78 -> V_4 . V_359 = F_178 ;
V_78 -> V_4 . V_360 = F_179 ;
V_78 -> V_4 . V_23 = F_180 ;
V_78 -> V_4 . V_361 = F_183 ;
V_78 -> V_4 . V_362 = F_184 ;
V_78 -> V_4 . V_363 = F_204 ;
return & V_78 -> V_4 ;
}
static struct V_184 * F_202 ( void )
{
struct V_184 * V_313 ;
int V_20 ;
if ( F_187 () )
return F_100 ( - V_73 ) ;
V_313 = F_121 ( sizeof( * V_313 ) , V_69 ) ;
if ( ! V_313 )
return F_100 ( - V_70 ) ;
if ( F_207 ( & V_342 ) ) {
V_20 = F_110 () ;
if ( V_20 ) {
F_34 ( V_313 ) ;
return F_100 ( V_20 ) ;
}
}
F_208 ( & V_313 -> V_343 , & V_342 ) ;
return V_313 ;
}
static int F_200 ( struct V_184 * V_313 , const char * V_150 )
{
struct V_184 * V_364 ;
V_364 = F_185 ( V_150 ) ;
if ( V_364 )
return - V_73 ;
V_313 -> V_150 = V_150 ;
return 0 ;
}
int F_209 ( struct V_184 * V_313 , const char * V_150 )
{
int V_20 ;
F_171 () ;
V_20 = F_200 ( V_313 , V_150 ) ;
F_172 () ;
return V_20 ;
}
int F_210 ( struct V_184 * V_313 )
{
int V_20 ;
V_20 = 0 ;
F_171 () ;
if ( ! F_188 ( & V_342 ) )
V_20 = - V_73 ;
else
V_313 -> V_344 = true ;
F_172 () ;
return V_20 ;
}
static void F_197 ( struct V_184 * V_313 )
{
F_211 ( & V_313 -> V_343 ) ;
if ( V_313 -> V_353 )
F_34 ( V_313 -> V_150 ) ;
F_34 ( V_313 ) ;
if ( F_207 ( & V_342 ) )
F_112 () ;
}
static void * F_104 ( const char * V_180 )
{
struct V_184 * V_184 ;
F_20 () ;
F_171 () ;
V_184 = F_190 ( V_180 ) ;
if ( ! V_184 )
V_184 = F_100 ( - V_79 ) ;
else if ( V_184 -> V_365 )
V_184 = F_100 ( - V_73 ) ;
else if ( V_184 -> V_366 &&
V_184 -> V_366 ( V_184 ) )
V_184 = F_100 ( - V_79 ) ;
else
V_184 -> V_365 = true ;
F_172 () ;
return V_184 ;
}
static void F_107 ( struct V_6 * V_6 )
{
struct V_184 * V_184 ;
F_20 () ;
F_171 () ;
V_184 = V_6 -> V_40 ;
if ( V_184 ) {
V_184 -> V_365 = false ;
if ( V_184 -> V_367 )
V_184 -> V_367 ( V_184 ) ;
}
F_172 () ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_184 * V_368 ;
int V_20 = 0 ;
F_20 () ;
F_171 () ;
V_368 = V_7 -> V_40 ;
if ( ! V_368 ) {
V_20 = - V_48 ;
goto V_116;
}
if ( F_61 ( V_368 -> V_314 ) ) {
V_20 = - V_73 ;
goto V_116;
}
V_368 -> V_314 = true ;
V_368 -> V_6 = V_7 ;
if ( V_368 -> V_369 )
V_20 = V_368 -> V_369 ( V_7 ) ;
V_116:
F_172 () ;
return V_20 ;
}
static void F_128 ( struct V_6 * V_7 )
{
struct V_184 * V_368 ;
F_20 () ;
F_171 () ;
V_368 = V_7 -> V_40 ;
if ( ! V_368 )
goto V_116;
V_368 -> V_314 = false ;
if ( V_368 -> V_370 )
V_368 -> V_370 ( V_7 ) ;
if ( ! V_368 -> V_172 || V_368 -> V_172 -> V_312
|| ! V_368 -> V_172 -> V_311 . V_347 . V_371 . V_372 )
goto V_116;
F_212 ( V_368 -> V_172 ->
V_311 . V_347 . V_371 . V_372 -> V_372 ) ;
V_116:
F_172 () ;
}
static int F_21 ( struct V_42 * V_42 , unsigned V_373 )
{
return V_373
? F_39 ( F_213 ( V_42 ) ) ? 0 : - V_68
: F_214 ( V_42 ) ;
}
static char * F_22 ( const char T_3 * V_27 , T_1 V_18 )
{
char * V_17 ;
if ( F_12 ( ! V_18 ) )
return NULL ;
V_17 = F_40 ( V_18 , V_69 ) ;
if ( F_12 ( ! V_17 ) )
return F_100 ( - V_70 ) ;
if ( F_12 ( F_65 ( V_17 , V_27 , V_18 ) ) ) {
F_34 ( V_17 ) ;
return F_100 ( - V_66 ) ;
}
F_16 ( L_50 ) ;
F_166 ( L_48 , V_17 , V_18 ) ;
return V_17 ;
}
