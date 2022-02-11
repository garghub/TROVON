static inline bool F_1 ( const struct V_1 * V_2 )
{
return memcmp ( V_2 -> V_3 , V_4 , V_5 ) == 0 ;
}
static T_1 F_2 ( const struct V_1 * V_2 , T_1 V_6 )
{
if ( V_2 -> V_3 [ V_7 ] == V_8 )
V_6 = F_3 ( V_6 ) ;
else if ( V_2 -> V_3 [ V_7 ] == V_9 )
V_6 = F_4 ( V_6 ) ;
return V_6 ;
}
static T_2 F_5 ( const struct V_1 * V_2 , T_2 V_6 )
{
if ( V_2 -> V_3 [ V_7 ] == V_8 )
V_6 = F_6 ( V_6 ) ;
else if ( V_2 -> V_3 [ V_7 ] == V_9 )
V_6 = F_7 ( V_6 ) ;
return V_6 ;
}
static T_3 F_8 ( const struct V_1 * V_2 , T_3 V_6 )
{
if ( V_2 -> V_3 [ V_7 ] == V_8 )
V_6 = F_9 ( V_6 ) ;
else if ( V_2 -> V_3 [ V_7 ] == V_9 )
V_6 = F_10 ( V_6 ) ;
return V_6 ;
}
static bool F_11 ( const struct V_1 * V_2 , T_4 V_10 )
{
if ( V_2 -> V_11 > 0 && V_2 -> V_12 != sizeof( struct V_13 ) ) {
F_12 ( L_1 ) ;
return false ;
} else if ( V_2 -> V_14 > 0 &&
V_2 -> V_15 != sizeof( struct V_16 ) ) {
F_12 ( L_2 ) ;
return false ;
} else if ( V_2 -> V_3 [ V_17 ] != V_18 ||
V_2 -> V_19 != V_18 ) {
F_12 ( L_3 ) ;
return false ;
}
if ( V_2 -> V_20 > 0 && V_2 -> V_11 > 0 ) {
T_4 V_21 ;
V_21 = sizeof( struct V_13 ) * V_2 -> V_11 ;
if ( V_2 -> V_20 + V_21 < V_2 -> V_20 ) {
F_12 ( L_4 ) ;
return false ;
} else if ( V_2 -> V_20 + V_21 > V_10 ) {
F_12 ( L_5 ) ;
return false ;
}
}
if ( V_2 -> V_22 > 0 && V_2 -> V_14 > 0 ) {
T_4 V_23 ;
V_23 = sizeof( struct V_16 ) * V_2 -> V_14 ;
if ( V_2 -> V_22 + V_23 < V_2 -> V_22 ) {
F_12 ( L_6 ) ;
return false ;
} else if ( V_2 -> V_22 + V_23 > V_10 ) {
F_12 ( L_7 ) ;
return false ;
}
}
return true ;
}
static int F_13 ( const char * V_24 , T_4 V_25 , struct V_1 * V_2 )
{
struct V_1 * V_26 ;
if ( V_25 < sizeof( * V_26 ) ) {
F_12 ( L_8 ) ;
return - V_27 ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
memcpy ( V_2 -> V_3 , V_24 , sizeof( V_2 -> V_3 ) ) ;
if ( ! F_1 ( V_2 ) ) {
F_12 ( L_9 ) ;
return - V_27 ;
}
if ( V_2 -> V_3 [ V_28 ] != V_29 ) {
F_12 ( L_10 ) ;
return - V_27 ;
} else if ( V_2 -> V_3 [ V_7 ] != V_8 &&
V_2 -> V_3 [ V_7 ] != V_9 ) {
F_12 ( L_11 ) ;
return - V_27 ;
}
V_26 = (struct V_1 * ) V_24 ;
if ( F_5 ( V_2 , V_26 -> V_30 ) != sizeof( * V_26 ) ) {
F_12 ( L_12 ) ;
return - V_27 ;
}
V_2 -> V_31 = F_5 ( V_2 , V_26 -> V_31 ) ;
V_2 -> V_32 = F_5 ( V_2 , V_26 -> V_32 ) ;
V_2 -> V_19 = F_8 ( V_2 , V_26 -> V_19 ) ;
V_2 -> V_33 = F_14 ( V_2 , V_26 -> V_33 ) ;
V_2 -> V_20 = F_14 ( V_2 , V_26 -> V_20 ) ;
V_2 -> V_22 = F_14 ( V_2 , V_26 -> V_22 ) ;
V_2 -> V_34 = F_8 ( V_2 , V_26 -> V_34 ) ;
V_2 -> V_12 = F_5 ( V_2 , V_26 -> V_12 ) ;
V_2 -> V_11 = F_5 ( V_2 , V_26 -> V_11 ) ;
V_2 -> V_15 = F_5 ( V_2 , V_26 -> V_15 ) ;
V_2 -> V_14 = F_5 ( V_2 , V_26 -> V_14 ) ;
V_2 -> V_35 = F_5 ( V_2 , V_26 -> V_35 ) ;
return F_11 ( V_2 , V_25 ) ? 0 : - V_27 ;
}
static bool F_15 ( const struct V_13 * V_36 , T_4 V_10 )
{
if ( V_36 -> V_37 + V_36 -> V_38 < V_36 -> V_37 ) {
F_12 ( L_13 ) ;
return false ;
} else if ( V_36 -> V_37 + V_36 -> V_38 > V_10 ) {
F_12 ( L_14 ) ;
return false ;
} else if ( V_36 -> V_39 + V_36 -> V_40 < V_36 -> V_39 ) {
F_12 ( L_15 ) ;
return false ;
}
return true ;
}
static int F_16 ( const char * V_24 , T_4 V_25 , struct V_41 * V_41 ,
int V_42 )
{
struct V_13 * V_36 = (struct V_13 * ) & V_41 -> V_43 [ V_42 ] ;
const char * V_44 ;
struct V_13 * V_45 ;
V_44 = V_24 + V_41 -> V_2 -> V_20 + ( V_42 * sizeof( * V_45 ) ) ;
V_45 = (struct V_13 * ) V_44 ;
V_36 -> V_46 = F_8 ( V_41 -> V_2 , V_45 -> V_46 ) ;
V_36 -> V_37 = F_14 ( V_41 -> V_2 , V_45 -> V_37 ) ;
V_36 -> V_39 = F_14 ( V_41 -> V_2 , V_45 -> V_39 ) ;
V_36 -> V_47 = F_14 ( V_41 -> V_2 , V_45 -> V_47 ) ;
V_36 -> V_48 = F_8 ( V_41 -> V_2 , V_45 -> V_48 ) ;
V_36 -> V_38 = F_14 ( V_41 -> V_2 , V_45 -> V_38 ) ;
V_36 -> V_40 = F_14 ( V_41 -> V_2 , V_45 -> V_40 ) ;
V_36 -> V_49 = F_14 ( V_41 -> V_2 , V_45 -> V_49 ) ;
return F_15 ( V_36 , V_25 ) ? 0 : - V_27 ;
}
static int F_17 ( const char * V_24 , T_4 V_25 ,
struct V_41 * V_41 )
{
T_4 V_21 , V_50 ;
const struct V_1 * V_2 = V_41 -> V_2 ;
V_21 = sizeof( struct V_13 ) * V_2 -> V_11 ;
V_41 -> V_43 = F_18 ( V_21 , V_51 ) ;
if ( ! V_41 -> V_43 )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_11 ; V_50 ++ ) {
int V_53 ;
V_53 = F_16 ( V_24 , V_25 , V_41 , V_50 ) ;
if ( V_53 ) {
F_19 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_53 ;
}
}
return 0 ;
}
static bool F_20 ( const struct V_16 * V_54 , T_4 V_10 )
{
bool V_55 ;
if ( V_54 -> V_56 == V_57 )
return true ;
switch ( V_54 -> V_56 ) {
case V_58 :
V_55 = V_54 -> V_59 == sizeof( V_60 ) ;
break;
case V_61 :
V_55 = V_54 -> V_59 == sizeof( V_62 ) ;
break;
case V_63 :
V_55 = V_54 -> V_59 == sizeof( V_64 ) ;
break;
case V_65 :
V_55 = V_54 -> V_59 == sizeof( V_66 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
default:
V_55 = true ;
break;
}
if ( ! V_55 ) {
F_12 ( L_16 ) ;
return false ;
} else if ( V_54 -> V_71 + V_54 -> V_72 < V_54 -> V_71 ) {
F_12 ( L_17 ) ;
return false ;
}
if ( V_54 -> V_56 != V_70 ) {
if ( V_54 -> V_73 + V_54 -> V_72 < V_54 -> V_73 ) {
F_12 ( L_18 ) ;
return false ;
} else if ( V_54 -> V_73 + V_54 -> V_72 > V_10 ) {
F_12 ( L_19 ) ;
return false ;
}
}
return true ;
}
static int F_21 ( const char * V_24 , T_4 V_25 , struct V_41 * V_41 ,
int V_42 )
{
struct V_16 * V_54 = & V_41 -> V_74 [ V_42 ] ;
const struct V_1 * V_2 = V_41 -> V_2 ;
const char * V_75 ;
struct V_16 * V_76 ;
V_75 = V_24 + V_2 -> V_22 + V_42 * sizeof( * V_76 ) ;
V_76 = (struct V_16 * ) V_75 ;
V_54 -> V_77 = F_8 ( V_2 , V_76 -> V_77 ) ;
V_54 -> V_56 = F_8 ( V_2 , V_76 -> V_56 ) ;
V_54 -> V_71 = F_14 ( V_2 , V_76 -> V_71 ) ;
V_54 -> V_73 = F_14 ( V_2 , V_76 -> V_73 ) ;
V_54 -> V_78 = F_8 ( V_2 , V_76 -> V_78 ) ;
V_54 -> V_79 = F_8 ( V_2 , V_76 -> V_79 ) ;
V_54 -> V_80 = F_14 ( V_2 , V_76 -> V_80 ) ;
V_54 -> V_72 = F_14 ( V_2 , V_76 -> V_72 ) ;
V_54 -> V_81 = F_14 ( V_2 , V_76 -> V_81 ) ;
V_54 -> V_59 = F_14 ( V_2 , V_76 -> V_59 ) ;
return F_20 ( V_54 , V_25 ) ? 0 : - V_27 ;
}
static int F_22 ( const char * V_24 , T_4 V_25 ,
struct V_41 * V_41 )
{
T_4 V_23 , V_50 ;
V_23 = sizeof( struct V_16 ) * V_41 -> V_2 -> V_14 ;
V_41 -> V_74 = F_18 ( V_23 , V_51 ) ;
if ( ! V_41 -> V_74 )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_41 -> V_2 -> V_14 ; V_50 ++ ) {
int V_53 ;
V_53 = F_21 ( V_24 , V_25 , V_41 , V_50 ) ;
if ( V_53 ) {
F_19 ( V_41 -> V_74 ) ;
V_41 -> V_74 = NULL ;
return V_53 ;
}
}
return 0 ;
}
int F_23 ( const char * V_24 , T_4 V_25 , struct V_1 * V_2 ,
struct V_41 * V_41 )
{
int V_53 ;
V_53 = F_13 ( V_24 , V_25 , V_2 ) ;
if ( V_53 )
return V_53 ;
V_41 -> V_82 = V_24 ;
V_41 -> V_2 = V_2 ;
if ( V_2 -> V_20 > 0 && V_2 -> V_11 > 0 ) {
V_53 = F_17 ( V_24 , V_25 , V_41 ) ;
if ( V_53 )
return V_53 ;
}
if ( V_2 -> V_22 > 0 && V_2 -> V_14 > 0 ) {
V_53 = F_22 ( V_24 , V_25 , V_41 ) ;
if ( V_53 ) {
F_19 ( V_41 -> V_43 ) ;
return V_53 ;
}
}
return 0 ;
}
void F_24 ( struct V_41 * V_41 )
{
F_19 ( V_41 -> V_43 ) ;
F_19 ( V_41 -> V_74 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
}
static int F_25 ( const char * V_24 , T_4 V_25 , struct V_1 * V_2 ,
struct V_41 * V_41 )
{
int V_50 ;
int V_53 ;
V_53 = F_23 ( V_24 , V_25 , V_2 , V_41 ) ;
if ( V_53 )
return V_53 ;
if ( V_2 -> V_31 != V_83 && V_2 -> V_31 != V_84 ) {
F_26 ( L_20 ) ;
goto error;
} else if ( ! V_41 -> V_43 ) {
F_26 ( L_21 ) ;
goto error;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_11 ; V_50 ++ ) {
if ( V_41 -> V_43 [ V_50 ] . V_46 == V_85 ) {
F_26 ( L_22 ) ;
goto error;
}
}
return 0 ;
error:
F_24 ( V_41 ) ;
return - V_27 ;
}
static int F_27 ( const char * V_24 , unsigned long V_25 )
{
struct V_1 V_2 ;
struct V_41 V_41 ;
int V_53 ;
V_53 = F_25 ( V_24 , V_25 , & V_2 , & V_41 ) ;
if ( V_53 )
return V_53 ;
F_24 ( & V_41 ) ;
return F_28 ( & V_2 ) ? 0 : - V_27 ;
}
static int F_29 ( struct V_86 * V_87 , struct V_1 * V_2 ,
struct V_41 * V_41 ,
unsigned long * V_88 )
{
unsigned long V_89 = 0 , V_90 = V_91 ;
int V_53 ;
T_4 V_50 ;
struct V_92 V_93 = { . V_87 = V_87 , . V_94 = V_95 ,
. V_96 = false } ;
for ( V_50 = 0 ; V_50 < V_2 -> V_11 ; V_50 ++ ) {
unsigned long V_97 ;
T_4 V_98 ;
const struct V_13 * V_36 ;
V_36 = & V_41 -> V_43 [ V_50 ] ;
if ( V_36 -> V_46 != V_99 )
continue;
V_98 = V_36 -> V_38 ;
if ( V_98 > V_36 -> V_40 )
V_98 = V_36 -> V_40 ;
V_93 . V_82 = ( void * ) V_41 -> V_82 + V_36 -> V_37 ;
V_93 . V_100 = V_98 ;
V_93 . V_101 = V_36 -> V_40 ;
V_93 . V_102 = V_36 -> V_49 ;
V_93 . V_103 = V_36 -> V_39 + V_89 ;
V_53 = F_30 ( & V_93 ) ;
if ( V_53 )
goto V_104;
V_97 = V_93 . V_105 ;
if ( V_97 < V_90 )
V_90 = V_97 ;
}
V_2 -> V_33 += V_89 ;
* V_88 = V_90 ;
V_53 = 0 ;
V_104:
return V_53 ;
}
static void * F_31 ( struct V_86 * V_87 , char * V_106 ,
unsigned long V_107 , char * V_108 ,
unsigned long V_109 , char * V_110 ,
unsigned long V_111 )
{
int V_53 ;
unsigned int V_112 ;
unsigned long V_113 , V_114 ;
unsigned long V_115 = 0 , V_116 ;
void * V_117 ;
const void * V_118 ;
struct V_1 V_2 ;
struct V_41 V_41 ;
struct V_92 V_93 = { . V_87 = V_87 , . V_103 = 0 ,
. V_94 = V_95 } ;
V_53 = F_25 ( V_106 , V_107 , & V_2 , & V_41 ) ;
if ( V_53 )
goto V_104;
V_53 = F_29 ( V_87 , & V_2 , & V_41 , & V_113 ) ;
if ( V_53 )
goto V_104;
F_12 ( L_23 , V_113 ) ;
V_53 = F_32 ( V_87 , 0 , V_95 , true ,
& V_114 ) ;
if ( V_53 ) {
F_26 ( L_24 ) ;
goto V_104;
}
F_12 ( L_25 , V_114 ) ;
if ( V_108 != NULL ) {
V_93 . V_82 = V_108 ;
V_93 . V_100 = V_93 . V_101 = V_109 ;
V_93 . V_102 = V_119 ;
V_93 . V_96 = false ;
V_53 = F_30 ( & V_93 ) ;
if ( V_53 )
goto V_104;
V_115 = V_93 . V_105 ;
F_12 ( L_26 , V_115 ) ;
}
V_112 = F_33 ( V_120 ) * 2 ;
V_117 = F_34 ( V_112 , V_51 ) ;
if ( ! V_117 ) {
F_26 ( L_27 ) ;
V_53 = - V_52 ;
goto V_104;
}
V_53 = F_35 ( V_120 , V_117 , V_112 ) ;
if ( V_53 < 0 ) {
F_26 ( L_28 ) ;
V_53 = - V_121 ;
goto V_104;
}
V_53 = F_36 ( V_87 , V_117 , V_115 , V_109 , V_110 ) ;
if ( V_53 )
goto V_104;
F_37 ( V_117 ) ;
V_93 . V_82 = V_117 ;
V_93 . V_100 = V_93 . V_101 = V_112 ;
V_93 . V_102 = V_119 ;
V_93 . V_96 = true ;
V_53 = F_30 ( & V_93 ) ;
if ( V_53 )
goto V_104;
V_116 = V_93 . V_105 ;
F_12 ( L_29 , V_116 ) ;
V_118 = V_41 . V_82 + V_41 . V_43 [ 0 ] . V_37 ;
V_53 = F_38 ( V_87 , V_118 , V_117 , V_113 ,
V_116 ) ;
if ( V_53 )
F_26 ( L_30 ) ;
V_104:
F_24 ( & V_41 ) ;
return V_53 ? F_39 ( V_53 ) : V_117 ;
}
