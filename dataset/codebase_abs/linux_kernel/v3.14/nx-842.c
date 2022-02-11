static inline int F_1 ( const struct V_1 * V_2 )
{
return sizeof( struct V_1 ) +
V_2 -> V_3 * sizeof( V_2 -> V_4 [ 0 ] ) ;
}
static void F_2 ( T_1 * V_5 , unsigned int time )
{
int V_6 = F_3 ( time ) ;
if ( V_6 )
V_6 = F_4 ( ( V_7 - 1 ) , V_6 - 1 ) ;
F_5 ( & V_5 [ V_6 ] ) ;
}
static unsigned long F_6 ( struct V_8 * V_9 )
{
return 0 ;
}
static inline unsigned long F_7 (
struct V_10 * V_11 )
{
return V_11 -> V_12 * sizeof( struct V_13 ) ;
}
static inline unsigned long F_8 ( void * V_14 )
{
if ( F_9 ( V_14 ) )
return F_10 ( F_11 ( V_14 ) )
+ F_12 ( V_14 ) ;
else
return F_13 ( V_14 ) ;
}
static int F_14 ( unsigned long V_15 , int V_16 ,
struct V_10 * V_11 )
{
unsigned long V_17 ;
struct V_13 * V_18 ;
V_11 -> V_12 = 0 ;
V_18 = V_11 -> V_19 ;
while ( V_16 ) {
V_18 -> V_20 = F_8 ( ( void * ) V_15 ) ;
V_17 = F_15 ( V_15 + 1 , V_21 ) ;
if ( V_17 < V_15 + V_16 ) {
if ( F_16 ( V_15 , V_21 ) )
V_18 -> V_16 = V_21 ;
else
V_18 -> V_16 = V_17 - V_15 ;
} else {
V_18 -> V_16 = V_16 ;
}
V_16 -= V_18 -> V_16 ;
V_15 += V_18 -> V_16 ;
V_11 -> V_12 ++ ;
V_18 ++ ;
}
return 0 ;
}
int F_17 ( void )
{
return sizeof( struct V_22 ) + V_21 ;
}
int F_18 ( void )
{
return sizeof( struct V_22 ) ;
}
static int F_19 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
if ( ! F_20 ( V_26 -> V_27 ) ) {
F_21 ( V_24 , L_1 ,
V_28 ) ;
F_22 ( V_24 , L_2 ,
V_26 -> V_27 ,
V_26 -> V_29 ,
V_26 -> V_30 ,
V_26 -> V_31 ) ;
F_22 ( V_24 , L_3 ,
V_26 -> V_32 ,
( unsigned long ) V_26 -> V_33 ) ;
return - V_34 ;
}
switch ( V_26 -> V_30 ) {
case 0 :
break;
case 64 :
case 13 :
F_22 ( V_24 , L_4 ,
V_28 ) ;
return - V_35 ;
case 66 :
case 67 :
F_22 ( V_24 , L_5 ,
V_28 , V_26 -> V_30 ) ;
return - V_36 ;
default:
F_22 ( V_24 , L_6 ,
V_28 , V_26 -> V_30 ) ;
return - V_34 ;
}
if ( ! F_23 ( V_26 -> V_31 ) ) {
F_21 ( V_24 , L_7
L_8
L_9
L_10
L_11 , V_28 ) ;
return - V_34 ;
}
return 0 ;
}
int F_24 ( const unsigned char * V_37 , unsigned int V_38 ,
unsigned char * V_39 , unsigned int * V_40 , void * V_41 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_23 * V_24 = NULL ;
struct V_22 * V_44 ;
struct V_10 V_45 , V_46 ;
struct V_47 * V_48 ;
int V_49 = 0 , V_50 , V_51 , V_52 , V_53 , V_54 ;
unsigned long V_55 , V_56 , V_57 ;
struct V_58 V_59 = {
. V_60 = NULL ,
. V_61 = 0 ,
. V_62 = 0 ,
} ;
unsigned long V_63 = F_25 () ;
V_55 = ( unsigned long ) V_37 ;
if ( ! F_16 ( V_55 , V_64 ) || V_38 != V_64 )
return - V_36 ;
F_26 () ;
V_43 = F_27 ( V_65 ) ;
if ( ! V_43 || ! V_43 -> V_24 ) {
F_28 () ;
return - V_66 ;
}
V_50 = V_43 -> V_50 ;
V_24 = V_43 -> V_24 ;
V_2 = (struct V_1 * ) V_39 ;
V_2 -> V_3 = V_64 / V_50 ;
V_54 = F_1 ( V_2 ) ;
V_56 = ( unsigned long ) V_39 + V_54 ;
V_52 = * V_40 - V_54 ;
V_44 = (struct V_22 * ) F_15 ( ( unsigned long ) V_41 ,
V_21 ) ;
V_45 . V_19 = (struct V_13 * ) V_44 -> V_45 ;
V_46 . V_19 = (struct V_13 * ) V_44 -> V_46 ;
V_59 . V_67 = V_68 ;
V_48 = & V_44 -> V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_59 . V_48 = F_8 ( V_48 ) ;
V_59 . V_39 = F_8 ( V_46 . V_19 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_3 ; V_51 ++ ) {
V_57 = F_15 ( V_56 , V_69 ) - V_56 ;
V_56 += V_57 ;
V_52 -= V_57 ;
if ( V_51 == 0 )
V_2 -> V_70 = V_57 + V_54 ;
if ( V_52 <= 0 ) {
V_49 = - V_35 ;
goto V_71;
}
if ( F_29 ( V_50 == V_21 ) ) {
V_59 . V_37 = F_8 ( ( void * ) V_55 ) ;
V_59 . V_38 = V_50 ;
} else {
F_14 ( V_55 , V_50 , & V_45 ) ;
V_59 . V_37 = F_8 ( V_45 . V_19 ) ;
V_59 . V_38 = - F_7 ( & V_45 ) ;
}
F_14 ( V_56 ,
F_4 ( V_52 , V_50 ) , & V_46 ) ;
V_59 . V_40 = - F_7 ( & V_46 ) ;
V_49 = F_30 ( V_43 -> V_72 , & V_59 ) ;
if ( V_49 ) {
F_22 ( V_24 , L_12 ,
V_28 , V_49 , V_59 . V_73 ) ;
V_49 = - V_34 ;
goto V_71;
}
V_49 = F_19 ( V_24 , & V_48 -> V_26 ) ;
if ( V_49 && V_49 != - V_35 )
goto V_71;
if ( F_31 ( V_49 == - V_35 ) ) {
if ( V_52 < V_50 ) {
goto V_71;
} else {
memcpy ( ( void * ) V_56 , ( void * ) V_55 ,
V_50 ) ;
V_2 -> V_4 [ V_51 ] = - V_50 ;
V_56 += V_50 ;
V_52 -= V_50 ;
V_49 = 0 ;
}
} else {
V_53 = V_48 -> V_26 . V_32 ;
F_22 ( V_24 , L_13 ,
V_28 , V_53 ) ;
V_2 -> V_4 [ V_51 ] = V_53 ;
V_56 += V_53 ;
V_52 -= V_53 ;
}
V_55 += V_50 ;
}
* V_40 = ( unsigned int ) ( V_56 - ( unsigned long ) V_39 ) ;
V_71:
if ( V_49 )
F_32 ( V_43 ) ;
else {
F_33 ( V_43 ) ;
F_2 ( V_43 -> V_74 -> V_75 ,
( F_25 () - V_63 ) / V_76 ) ;
}
F_28 () ;
return V_49 ;
}
int F_34 ( const unsigned char * V_37 , unsigned int V_38 ,
unsigned char * V_39 , unsigned int * V_40 , void * V_41 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_23 * V_24 = NULL ;
struct V_22 * V_44 ;
struct V_10 V_45 , V_46 ;
struct V_47 * V_48 ;
int V_49 = 0 , V_51 , V_53 , V_50 ;
unsigned long V_55 , V_56 ;
struct V_58 V_59 = {
. V_60 = NULL ,
. V_61 = 0 ,
. V_62 = 0 ,
} ;
unsigned long V_63 = F_25 () ;
V_56 = ( unsigned long ) V_39 ;
if ( ! F_16 ( V_56 , V_64 ) || * V_40 != V_64 )
return - V_36 ;
F_26 () ;
V_43 = F_27 ( V_65 ) ;
if ( V_43 )
V_24 = V_43 -> V_24 ;
V_2 = (struct V_1 * ) V_37 ;
V_44 = (struct V_22 * ) F_15 ( ( unsigned long ) V_41 ,
V_21 ) ;
V_55 = ( unsigned long ) V_37 + V_2 -> V_70 ;
if ( F_29 ( ! F_16 ( V_55 , V_69 ) ) ) {
memcpy ( V_44 -> V_77 , V_37 + V_2 -> V_70 , V_38 - V_2 -> V_70 ) ;
V_55 = ( unsigned long ) V_44 -> V_77 ;
}
V_45 . V_19 = (struct V_13 * ) V_44 -> V_45 ;
V_46 . V_19 = (struct V_13 * ) V_44 -> V_46 ;
V_59 . V_67 = V_78 ;
V_48 = & V_44 -> V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_59 . V_48 = F_8 ( V_48 ) ;
V_50 = V_64 / V_2 -> V_3 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_3 ; V_51 ++ ) {
V_55 = F_15 ( V_55 , V_69 ) ;
if ( V_2 -> V_4 [ V_51 ] < 0 ) {
V_53 = abs ( V_2 -> V_4 [ V_51 ] ) ;
memcpy ( ( void * ) V_56 , ( void * ) V_55 , V_53 ) ;
V_56 += V_53 ;
V_55 += V_53 ;
continue;
}
if ( ! V_24 )
goto V_79;
if ( F_29 ( ( V_55 & V_80 ) ==
( ( V_55 + V_2 -> V_4 [ V_51 ] - 1 ) & V_80 ) ) ) {
V_59 . V_37 = F_8 ( ( void * ) V_55 ) ;
V_59 . V_38 = V_2 -> V_4 [ V_51 ] ;
} else {
F_14 ( V_55 , V_2 -> V_4 [ V_51 ] , & V_45 ) ;
V_59 . V_37 = F_8 ( V_45 . V_19 ) ;
V_59 . V_38 = - F_7 ( & V_45 ) ;
}
if ( F_29 ( V_50 == V_21 ) ) {
V_59 . V_39 = F_8 ( ( void * ) V_56 ) ;
V_59 . V_40 = V_50 ;
} else {
F_14 ( V_56 , V_50 , & V_46 ) ;
V_59 . V_39 = F_8 ( V_46 . V_19 ) ;
V_59 . V_40 = - F_7 ( & V_46 ) ;
}
V_49 = F_30 ( V_43 -> V_72 , & V_59 ) ;
if ( V_49 ) {
F_22 ( V_24 , L_12 ,
V_28 , V_49 , V_59 . V_73 ) ;
V_24 = NULL ;
goto V_79;
}
V_49 = F_19 ( V_24 , & V_48 -> V_26 ) ;
if ( V_49 ) {
V_24 = NULL ;
goto V_79;
}
V_55 += V_2 -> V_4 [ V_51 ] ;
V_56 += V_48 -> V_26 . V_32 ;
continue;
V_79:
V_53 = V_50 ;
V_49 = F_35 (
( unsigned char * ) V_55 , V_2 -> V_4 [ V_51 ] ,
( unsigned char * ) V_56 , & V_53 , V_41 ) ;
if ( V_49 )
F_36 ( L_14 ,
V_28 , V_49 ) ;
if ( V_49 ) {
if ( V_49 != - V_35 && V_49 != - V_36 &&
V_49 != - V_81 )
V_49 = - V_34 ;
goto V_71;
}
V_55 += V_2 -> V_4 [ V_51 ] ;
V_56 += V_53 ;
}
* V_40 = ( unsigned int ) ( V_56 - ( unsigned long ) V_39 ) ;
V_71:
if ( V_49 )
F_37 ( V_43 ) ;
else {
if ( ! V_24 )
F_38 ( V_43 ) ;
F_39 ( V_43 ) ;
F_2 ( V_43 -> V_74 -> V_82 ,
( F_25 () - V_63 ) / V_76 ) ;
}
F_28 () ;
return V_49 ;
}
static int F_40 ( struct V_42 * V_65 )
{
if ( V_65 ) {
V_65 -> V_50 = 0 ;
V_65 -> V_83 = 0 ;
V_65 -> V_84 = 0 ;
V_65 -> V_85 = V_86 ;
return 0 ;
} else
return - V_87 ;
}
static int F_41 ( struct V_42 * V_65 ,
struct V_88 * V_89 ) {
int V_49 = 0 ;
const char * V_85 = ( const char * ) V_89 -> V_90 ;
if ( ! strncmp ( V_85 , L_15 , ( V_91 ) V_89 -> V_92 ) ) {
V_65 -> V_85 = V_93 ;
} else {
F_42 ( V_65 -> V_24 , L_16 ,
V_28 , V_85 ) ;
V_65 -> V_85 = V_86 ;
}
return V_49 ;
}
static int F_43 ( struct V_42 * V_65 ,
struct V_88 * V_89 ) {
int V_49 = 0 ;
const int * V_94 = V_89 -> V_90 ;
if ( V_89 -> V_92 != sizeof( * V_94 ) ) {
F_21 ( V_65 -> V_24 , L_17 , V_28 ) ;
F_22 ( V_65 -> V_24 , L_18 , V_28 ,
V_89 -> V_92 , sizeof( * V_94 ) ) ;
V_49 = - V_36 ;
} else {
V_65 -> V_84 = ( unsigned int ) F_4 ( * V_94 ,
( int ) V_21 ) ;
}
return V_49 ;
}
static int F_44 ( struct V_42 * V_65 ,
struct V_88 * V_89 ) {
int V_49 = 0 ;
const struct V_95 {
int V_96 ;
int V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
int V_101 ;
} * V_102 ;
if ( V_89 -> V_92 != sizeof( * V_102 ) ) {
F_21 ( V_65 -> V_24 , L_19 , V_28 ) ;
F_22 ( V_65 -> V_24 , L_20 , V_28 , V_89 -> V_92 ,
sizeof( * V_102 ) ) ;
V_49 = - V_36 ;
goto V_39;
}
V_102 = ( const struct V_95 * ) V_89 -> V_90 ;
V_65 -> V_50 =
( unsigned int ) F_4 ( V_102 -> V_97 ,
V_102 -> V_100 ) ;
V_65 -> V_50 = F_45 (unsigned int, devdata->max_sync_size,
SIZE_64K) ;
if ( V_65 -> V_50 < V_103 ) {
F_21 ( V_65 -> V_24 , L_21
L_22
L_23 ,
V_28 , V_65 -> V_50 ) ;
V_49 = - V_36 ;
goto V_39;
}
V_65 -> V_83 = ( unsigned int ) F_4 ( V_102 -> V_98 ,
V_102 -> V_101 ) ;
if ( V_65 -> V_83 < 1 ) {
F_21 ( V_65 -> V_24 , L_24
L_22
L_23 ,
V_28 , V_65 -> V_83 ) ;
V_49 = - V_36 ;
goto V_39;
}
V_39:
return V_49 ;
}
static int F_46 ( struct V_88 * V_104 )
{
struct V_42 * V_105 = NULL ;
struct V_42 * V_106 = NULL ;
struct V_107 * V_108 = NULL ;
struct V_88 * V_85 = NULL ;
struct V_88 * V_94 = NULL ;
struct V_88 * V_109 = NULL ;
int V_49 = 0 ;
unsigned long V_67 ;
F_47 ( & V_110 , V_67 ) ;
V_105 = F_48 ( V_65 ,
F_49 ( & V_110 ) ) ;
if ( V_105 )
V_108 = V_105 -> V_24 -> V_108 ;
if ( ! V_105 || ! V_108 ) {
F_50 ( L_25 , V_28 ) ;
F_51 ( & V_110 , V_67 ) ;
return - V_66 ;
}
V_106 = F_52 ( sizeof( * V_106 ) , V_111 ) ;
if ( ! V_106 ) {
F_21 ( V_105 -> V_24 , L_26 , V_28 ) ;
V_49 = - V_112 ;
goto V_113;
}
memcpy ( V_106 , V_105 , sizeof( * V_105 ) ) ;
V_106 -> V_74 = V_105 -> V_74 ;
V_85 = F_53 ( V_108 , L_27 , NULL ) ;
V_94 = F_53 ( V_108 , L_28 , NULL ) ;
V_109 = F_53 ( V_108 , L_29 , NULL ) ;
if ( ! V_85 || ! V_94 || ! V_109 ) {
F_21 ( V_105 -> V_24 , L_30 , V_28 ) ;
V_49 = - V_36 ;
goto V_113;
}
if ( V_104 ) {
if ( ! strncmp ( V_104 -> V_114 , L_27 , V_104 -> V_92 ) ) {
V_85 = V_104 ;
} else if ( ! strncmp ( V_104 -> V_114 , L_28 ,
V_104 -> V_92 ) ) {
V_94 = V_104 ;
} else if ( ! strncmp ( V_104 -> V_114 , L_29 ,
V_104 -> V_92 ) ) {
V_109 = V_104 ;
} else {
goto V_39;
}
}
V_49 = F_41 ( V_106 , V_85 ) ;
if ( V_49 )
goto V_113;
V_49 = F_43 ( V_106 , V_94 ) ;
if ( V_49 )
goto V_113;
V_49 = F_44 ( V_106 , V_109 ) ;
if ( V_49 )
goto V_113;
V_39:
F_42 ( V_105 -> V_24 , L_31 ,
V_28 , V_106 -> V_50 ,
V_105 -> V_50 ) ;
F_42 ( V_105 -> V_24 , L_32 ,
V_28 , V_106 -> V_83 ,
V_105 -> V_83 ) ;
F_42 ( V_105 -> V_24 , L_33 ,
V_28 , V_106 -> V_84 ,
V_105 -> V_84 ) ;
F_54 ( V_65 , V_106 ) ;
F_51 ( & V_110 , V_67 ) ;
F_55 () ;
F_56 ( V_106 -> V_24 , V_106 ) ;
F_57 ( V_105 ) ;
return 0 ;
V_113:
if ( V_106 ) {
F_42 ( V_105 -> V_24 , L_34 , V_28 ) ;
F_40 ( V_106 ) ;
F_54 ( V_65 , V_106 ) ;
F_51 ( & V_110 , V_67 ) ;
F_55 () ;
F_56 ( V_106 -> V_24 , V_106 ) ;
F_57 ( V_105 ) ;
} else {
F_21 ( V_105 -> V_24 , L_35 , V_28 ) ;
F_51 ( & V_110 , V_67 ) ;
}
if ( ! V_49 )
V_49 = - V_36 ;
return V_49 ;
}
static int F_58 ( struct V_115 * V_116 , unsigned long V_117 ,
void * V_118 )
{
struct V_119 * V_120 = V_118 ;
struct V_42 * V_43 ;
struct V_107 * V_121 = NULL ;
F_26 () ;
V_43 = F_27 ( V_65 ) ;
if ( V_43 )
V_121 = V_43 -> V_24 -> V_108 ;
if ( V_43 &&
V_117 == V_122 &&
! strcmp ( V_120 -> V_123 -> V_114 , V_121 -> V_114 ) ) {
F_28 () ;
F_46 ( V_120 -> V_89 ) ;
} else
F_28 () ;
return V_124 ;
}
static T_2 F_59 ( struct V_23 * V_24 ,
struct V_125 * V_126 , char * V_15 ) {
char * V_127 = V_15 ;
struct V_42 * V_43 ;
T_1 * V_5 ;
int V_128 = V_64 ;
int V_129 ;
int V_51 ;
F_26 () ;
V_43 = F_27 ( V_65 ) ;
if ( ! V_43 ) {
F_28 () ;
return 0 ;
}
if ( V_126 == & V_130 )
V_5 = V_43 -> V_74 -> V_75 ;
else if ( V_126 == & V_131 )
V_5 = V_43 -> V_74 -> V_82 ;
else {
F_28 () ;
return 0 ;
}
for ( V_51 = 0 ; V_51 < ( V_7 - 2 ) ; V_51 ++ ) {
V_129 = snprintf ( V_127 , V_128 , L_36 ,
V_51 ? ( 2 << ( V_51 - 1 ) ) : 0 , ( 2 << V_51 ) - 1 ,
F_60 ( & V_5 [ V_51 ] ) ) ;
V_128 -= V_129 ;
V_127 += V_129 ;
}
V_129 = snprintf ( V_127 , V_128 , L_37 ,
2 << ( V_7 - 2 ) ,
F_60 ( & V_5 [ ( V_7 - 1 ) ] ) ) ;
V_127 += V_129 ;
F_28 () ;
return V_127 - V_15 ;
}
static int T_3 F_61 ( struct V_8 * V_9 ,
const struct V_132 * V_133 )
{
struct V_42 * V_105 , * V_106 = NULL ;
unsigned long V_67 ;
int V_49 = 0 ;
F_47 ( & V_110 , V_67 ) ;
V_105 = F_48 ( V_65 ,
F_49 ( & V_110 ) ) ;
if ( V_105 && V_105 -> V_72 != NULL ) {
F_21 ( & V_9 -> V_24 , L_38 , V_28 ) ;
V_49 = - 1 ;
goto V_134;
}
F_56 ( & V_9 -> V_24 , NULL ) ;
V_106 = F_52 ( sizeof( * V_106 ) , V_111 ) ;
if ( ! V_106 ) {
F_21 ( & V_9 -> V_24 , L_26 , V_28 ) ;
V_49 = - V_112 ;
goto V_134;
}
V_106 -> V_74 = F_52 ( sizeof( * V_106 -> V_74 ) ,
V_111 ) ;
if ( ! V_106 -> V_74 ) {
F_21 ( & V_9 -> V_24 , L_39 , V_28 ) ;
V_49 = - V_112 ;
goto V_134;
}
V_106 -> V_72 = V_9 ;
V_106 -> V_24 = & V_9 -> V_24 ;
F_40 ( V_106 ) ;
F_54 ( V_65 , V_106 ) ;
F_51 ( & V_110 , V_67 ) ;
F_55 () ;
F_57 ( V_105 ) ;
F_62 ( & V_135 ) ;
V_49 = F_46 ( NULL ) ;
if ( V_49 && V_49 != - V_66 ) {
F_21 ( & V_9 -> V_24 , L_40 , V_49 ) ;
V_49 = - 1 ;
goto error;
}
F_26 () ;
if ( F_56 ( & V_9 -> V_24 , F_27 ( V_65 ) ) ) {
F_28 () ;
F_21 ( & V_9 -> V_24 , L_41 ) ;
V_49 = - 1 ;
goto error;
}
F_28 () ;
if ( F_63 ( & V_9 -> V_24 . V_136 , & V_137 ) ) {
F_21 ( & V_9 -> V_24 , L_42 ) ;
V_49 = - 1 ;
goto error;
}
return 0 ;
V_134:
F_51 ( & V_110 , V_67 ) ;
if ( V_106 )
F_57 ( V_106 -> V_74 ) ;
F_57 ( V_106 ) ;
error:
return V_49 ;
}
static int T_4 F_64 ( struct V_8 * V_9 )
{
struct V_42 * V_105 ;
unsigned long V_67 ;
F_65 ( L_43 ) ;
F_66 ( & V_9 -> V_24 . V_136 , & V_137 ) ;
F_47 ( & V_110 , V_67 ) ;
V_105 = F_48 ( V_65 ,
F_49 ( & V_110 ) ) ;
F_67 ( & V_135 ) ;
F_54 ( V_65 , NULL ) ;
F_51 ( & V_110 , V_67 ) ;
F_55 () ;
F_56 ( & V_9 -> V_24 , NULL ) ;
if ( V_105 )
F_57 ( V_105 -> V_74 ) ;
F_57 ( V_105 ) ;
return 0 ;
}
static int T_3 F_68 ( void )
{
struct V_42 * V_106 ;
F_65 ( L_44 ) ;
F_69 ( V_65 , NULL ) ;
V_106 = F_52 ( sizeof( * V_106 ) , V_138 ) ;
if ( ! V_106 ) {
F_50 ( L_45 ) ;
return - V_112 ;
}
V_106 -> V_85 = V_86 ;
F_69 ( V_65 , V_106 ) ;
return F_70 ( & V_139 ) ;
}
static void T_4 F_71 ( void )
{
struct V_42 * V_105 ;
unsigned long V_67 ;
F_65 ( L_46 ) ;
F_47 ( & V_110 , V_67 ) ;
V_105 = F_48 ( V_65 ,
F_49 ( & V_110 ) ) ;
F_54 ( V_65 , NULL ) ;
F_51 ( & V_110 , V_67 ) ;
F_55 () ;
if ( V_105 )
F_56 ( V_105 -> V_24 , NULL ) ;
F_57 ( V_105 ) ;
F_72 ( & V_139 ) ;
}
static T_5 F_73 ( const char * V_15 , int V_140 )
{
T_5 V_141 ;
T_6 V_142 ;
V_142 = F_74 ( * ( T_6 * ) ( V_15 ) ) ;
V_142 = ( T_6 ) ( V_142 << V_140 ) ;
V_142 = F_75 ( V_142 ) ;
memcpy ( & V_141 , & V_142 , 1 ) ;
return V_141 ;
}
static T_5 F_76 ( const char * * V_15 , int * V_140 )
{
T_5 V_143 ;
V_143 = F_73 ( * V_15 , * V_140 ) ;
V_143 = V_143 >> 3 ;
V_143 &= 0x1F ;
* V_15 += ( * V_140 + 5 ) / 8 ;
* V_140 = ( * V_140 + 5 ) % 8 ;
return V_143 ;
}
static T_5 F_77 ( const char * * V_15 , int * V_140 )
{
T_5 V_143 ;
V_143 = F_73 ( * V_15 , * V_140 ) ;
V_143 = V_143 >> 2 ;
V_143 &= 0x3F ;
* V_15 += ( * V_140 + 6 ) / 8 ;
* V_140 = ( * V_140 + 6 ) % 8 ;
return V_143 ;
}
static T_5 F_78 ( const char * * V_15 , int * V_140 )
{
T_5 V_20 ;
V_20 = F_73 ( * V_15 , * V_140 ) ;
( * V_15 ) ++ ;
return V_20 ;
}
static T_6 F_79 ( const char * * V_15 , int * V_140 ,
struct V_144 * V_145 )
{
T_6 V_20 ;
V_20 = F_74 ( * ( T_6 * ) ( * V_15 ) ) ;
V_20 = ( T_6 ) ( V_20 << * V_140 ) ;
V_20 = V_20 >> 7 ;
V_20 &= 0x01FF ;
* V_15 += ( * V_140 + 9 ) / 8 ;
* V_140 = ( * V_140 + 9 ) % 8 ;
return V_20 ;
}
static T_5 F_80 ( const char * * V_15 , int * V_140 ,
struct V_144 * V_145 )
{
return F_78 ( V_15 , V_140 ) ;
}
static int F_81 ( const char * * V_55 , int * V_146 ,
unsigned char * * V_56 , struct V_144 * V_145 )
{
int V_49 ;
V_49 = F_82 ( V_55 , V_146 , V_56 , V_145 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_82 ( V_55 , V_146 , V_56 , V_145 ) ;
return V_49 ;
}
static int F_82 ( const char * * V_55 , int * V_146 ,
unsigned char * * V_56 , struct V_144 * V_145 )
{
int V_49 ;
V_49 = F_83 ( V_55 , V_146 , V_56 , V_145 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_83 ( V_55 , V_146 , V_56 , V_145 ) ;
return V_49 ;
}
static int F_83 ( const char * * V_55 , int * V_146 ,
unsigned char * * V_56 , struct V_144 * V_145 )
{
* * V_56 = F_73 ( * V_55 , * V_146 ) ;
( * V_55 ) ++ ;
( * V_56 ) ++ ;
* * V_56 = F_73 ( * V_55 , * V_146 ) ;
( * V_55 ) ++ ;
( * V_56 ) ++ ;
return 0 ;
}
static int F_84 ( const char * * V_55 , int * V_146 ,
unsigned char * * V_56 , struct V_144 * V_145 )
{
T_5 V_20 ;
V_20 = F_80 ( V_55 , V_146 , V_145 ) ;
if ( ! V_145 -> V_147 && ( V_20 >= V_145 -> V_148 ) )
return 1 ;
memcpy ( * V_56 , V_145 -> V_149 [ V_20 ] , 8 ) ;
* V_56 += 8 ;
return 0 ;
}
static int F_85 ( const char * * V_55 , int * V_146 ,
unsigned char * * V_56 , struct V_144 * V_145 )
{
T_6 V_20 ;
V_20 = F_79 ( V_55 , V_146 , V_145 ) ;
if ( ! V_145 -> V_147 && ( V_20 >= V_145 -> V_150 ) )
return 1 ;
memcpy ( * V_56 , V_145 -> V_151 [ V_20 ] , 4 ) ;
* V_56 += 4 ;
return 0 ;
}
static int F_86 ( const char * * V_55 , int * V_146 ,
unsigned char * * V_56 , struct V_144 * V_145 )
{
T_5 V_20 ;
V_20 = F_78 ( V_55 , V_146 ) ;
if ( ! V_145 -> V_152 && ( V_20 >= V_145 -> V_153 ) )
return 1 ;
memcpy ( * V_56 , V_145 -> V_154 [ V_20 ] , 2 ) ;
* V_56 += 2 ;
return 0 ;
}
static void F_87 ( const char * V_15 , struct V_144 * V_145 )
{
unsigned char V_155 = V_145 -> V_153 ;
memcpy ( V_145 -> V_149 [ V_145 -> V_148 ] , V_15 , 8 ) ;
V_145 -> V_150 += 2 ;
V_145 -> V_148 += 1 ;
if ( ! V_145 -> V_147 && V_145 -> V_150 >= 512 ) {
V_145 -> V_147 = 1 ;
V_145 -> V_150 /= 512 ;
}
memcpy ( V_145 -> V_154 [ V_145 -> V_153 ++ ] , V_15 , 2 ) ;
memcpy ( V_145 -> V_154 [ V_145 -> V_153 ++ ] , V_15 + 2 , 2 ) ;
memcpy ( V_145 -> V_154 [ V_145 -> V_153 ++ ] , V_15 + 4 , 2 ) ;
memcpy ( V_145 -> V_154 [ V_145 -> V_153 ++ ] , V_15 + 6 , 2 ) ;
if ( V_145 -> V_153 < V_155 )
V_145 -> V_152 = 1 ;
}
static int F_35 ( const unsigned char * V_156 , int V_157 ,
unsigned char * V_158 , int * V_159 ,
const void * V_160 )
{
T_5 V_141 ;
const char * V_55 ;
int V_146 = 0 ;
unsigned char * V_56 , * V_161 , * V_162 , * V_163 ;
const char * V_164 ;
T_7 V_59 ;
int V_165 ;
int V_51 , V_166 ;
struct V_144 * V_145 ;
int V_49 = 0 ;
V_145 = & ( (struct V_22 * ) ( V_160 ) ) -> V_167 ;
memset ( V_145 , 0 , sizeof( * V_145 ) ) ;
V_162 = NULL ;
V_55 = V_156 ;
V_164 = V_156 + V_157 ;
V_56 = V_158 ;
V_161 = V_158 + * V_159 ;
while ( ( V_141 = F_76 ( & V_55 , & V_146 ) ) != V_168 ) {
if ( V_55 >= V_164 ) {
V_49 = - V_36 ;
goto V_39;
}
V_165 = 0 ;
V_163 = V_162 ;
V_162 = V_56 ;
switch ( V_141 ) {
case V_169 :
if ( V_163 == NULL ) {
V_49 = - V_36 ;
goto V_39;
}
V_166 = F_77 ( & V_55 ,
& V_146 ) + 1 ;
if ( V_55 > V_164 ) {
V_49 = - V_36 ;
goto V_39;
}
for ( V_51 = 0 ; V_51 < V_166 ; V_51 ++ ) {
if ( ( V_56 + 8 ) > V_161 ) {
V_49 = - V_35 ;
goto V_39;
}
memcpy ( V_56 , V_163 , 8 ) ;
F_87 ( V_56 , V_145 ) ;
V_56 += 8 ;
}
break;
case V_170 :
if ( ( V_56 + 8 ) > V_161 ) {
V_49 = - V_35 ;
goto V_39;
}
memset ( V_56 , 0 , 8 ) ;
F_87 ( V_56 , V_145 ) ;
V_56 += 8 ;
break;
default:
if ( V_141 > 25 ) {
V_49 = - V_36 ;
goto V_39;
}
if ( ( V_55 + 2 ) > V_164 ) {
V_49 = - V_36 ;
goto V_39;
}
if ( ( V_56 + 8 ) > V_161 ) {
V_49 = - V_35 ;
goto V_39;
}
while ( V_165 < 4 &&
( V_59 = V_171 [ V_141 ] [ V_165 ++ ] )
!= NULL ) {
V_49 = (* V_59)( & V_55 , & V_146 , & V_56 , V_145 ) ;
if ( V_49 ) {
V_49 = - V_36 ;
goto V_39;
}
F_87 ( V_162 , V_145 ) ;
}
}
}
V_39:
if ( ! V_49 )
* V_159 = ( unsigned int ) ( V_56 - V_158 ) ;
else
* V_159 = 0 ;
return V_49 ;
}
