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
static int F_8 ( unsigned long V_14 , int V_15 ,
struct V_10 * V_11 )
{
unsigned long V_16 ;
struct V_13 * V_17 ;
V_11 -> V_12 = 0 ;
V_17 = V_11 -> V_18 ;
while ( V_15 ) {
V_17 -> V_19 = F_9 ( V_14 ) ;
V_16 = F_10 ( V_14 + 1 , V_20 ) ;
if ( V_16 < V_14 + V_15 ) {
if ( F_11 ( V_14 , V_20 ) )
V_17 -> V_15 = V_20 ;
else
V_17 -> V_15 = V_16 - V_14 ;
} else {
V_17 -> V_15 = V_15 ;
}
V_15 -= V_17 -> V_15 ;
V_14 += V_17 -> V_15 ;
V_11 -> V_12 ++ ;
V_17 ++ ;
}
return 0 ;
}
int F_12 ( void )
{
return sizeof( struct V_21 ) + V_20 ;
}
int F_13 ( void )
{
return sizeof( struct V_21 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
if ( ! F_15 ( V_25 -> V_26 ) ) {
F_16 ( V_23 , L_1 ,
V_27 ) ;
F_17 ( V_23 , L_2 ,
V_25 -> V_26 ,
V_25 -> V_28 ,
V_25 -> V_29 ,
V_25 -> V_30 ) ;
F_17 ( V_23 , L_3 ,
V_25 -> V_31 ,
( unsigned long ) V_25 -> V_32 ) ;
return - V_33 ;
}
switch ( V_25 -> V_29 ) {
case 0 :
break;
case 64 :
case 13 :
F_17 ( V_23 , L_4 ,
V_27 ) ;
return - V_34 ;
case 66 :
case 67 :
F_17 ( V_23 , L_5 ,
V_27 , V_25 -> V_29 ) ;
return - V_35 ;
default:
F_17 ( V_23 , L_6 ,
V_27 , V_25 -> V_29 ) ;
return - V_33 ;
}
if ( ! F_18 ( V_25 -> V_30 ) ) {
F_16 ( V_23 , L_7
L_8
L_9
L_10
L_11 , V_27 ) ;
return - V_33 ;
}
return 0 ;
}
int F_19 ( const unsigned char * V_36 , unsigned int V_37 ,
unsigned char * V_38 , unsigned int * V_39 , void * V_40 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
struct V_22 * V_23 = NULL ;
struct V_21 * V_43 ;
struct V_10 V_44 , V_45 ;
struct V_46 * V_47 ;
int V_48 = 0 , V_49 , V_50 , V_51 , V_52 , V_53 ;
unsigned long V_54 , V_55 , V_56 ;
struct V_57 V_58 = {
. V_59 = NULL ,
. V_60 = 0 ,
. V_61 = 0 ,
} ;
unsigned long V_62 = F_20 () ;
V_54 = ( unsigned long ) V_36 ;
if ( ! F_11 ( V_54 , V_63 ) || V_37 != V_63 )
return - V_35 ;
F_21 () ;
V_42 = F_22 ( V_64 ) ;
if ( ! V_42 || ! V_42 -> V_23 ) {
F_23 () ;
return - V_65 ;
}
V_49 = V_42 -> V_49 ;
V_23 = V_42 -> V_23 ;
V_2 = (struct V_1 * ) V_38 ;
V_2 -> V_3 = V_63 / V_49 ;
V_53 = F_1 ( V_2 ) ;
V_55 = ( unsigned long ) V_38 + V_53 ;
V_51 = * V_39 - V_53 ;
V_43 = (struct V_21 * ) F_10 ( ( unsigned long ) V_40 ,
V_20 ) ;
V_44 . V_18 = (struct V_13 * ) V_43 -> V_44 ;
V_45 . V_18 = (struct V_13 * ) V_43 -> V_45 ;
V_58 . V_66 = V_67 ;
V_47 = & V_43 -> V_47 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_58 . V_47 = F_9 ( V_47 ) ;
V_58 . V_38 = F_9 ( V_45 . V_18 ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_3 ; V_50 ++ ) {
V_56 = F_10 ( V_55 , V_68 ) - V_55 ;
V_55 += V_56 ;
V_51 -= V_56 ;
if ( V_50 == 0 )
V_2 -> V_69 = V_56 + V_53 ;
if ( V_51 <= 0 ) {
V_48 = - V_34 ;
goto V_70;
}
if ( F_24 ( V_49 == V_20 ) ) {
V_58 . V_36 = F_9 ( V_54 ) ;
V_58 . V_37 = V_49 ;
} else {
F_8 ( V_54 , V_49 , & V_44 ) ;
V_58 . V_36 = F_9 ( V_44 . V_18 ) ;
V_58 . V_37 = - F_7 ( & V_44 ) ;
}
F_8 ( V_55 ,
F_4 ( V_51 , V_49 ) , & V_45 ) ;
V_58 . V_39 = - F_7 ( & V_45 ) ;
V_48 = F_25 ( V_42 -> V_71 , & V_58 ) ;
if ( V_48 ) {
F_17 ( V_23 , L_12 ,
V_27 , V_48 , V_58 . V_72 ) ;
V_48 = - V_33 ;
goto V_70;
}
V_48 = F_14 ( V_23 , & V_47 -> V_25 ) ;
if ( V_48 && V_48 != - V_34 )
goto V_70;
if ( F_26 ( V_48 == - V_34 ) ) {
if ( V_51 < V_49 ) {
goto V_70;
} else {
memcpy ( ( void * ) V_55 , ( void * ) V_54 ,
V_49 ) ;
V_2 -> V_4 [ V_50 ] = - V_49 ;
V_55 += V_49 ;
V_51 -= V_49 ;
V_48 = 0 ;
}
} else {
V_52 = V_47 -> V_25 . V_31 ;
F_17 ( V_23 , L_13 ,
V_27 , V_52 ) ;
V_2 -> V_4 [ V_50 ] = V_52 ;
V_55 += V_52 ;
V_51 -= V_52 ;
}
V_54 += V_49 ;
}
* V_39 = ( unsigned int ) ( V_55 - ( unsigned long ) V_38 ) ;
V_70:
if ( V_48 )
F_27 ( V_42 ) ;
else {
F_28 ( V_42 ) ;
F_2 ( V_42 -> V_73 -> V_74 ,
( F_20 () - V_62 ) / V_75 ) ;
}
F_23 () ;
return V_48 ;
}
int F_29 ( const unsigned char * V_36 , unsigned int V_37 ,
unsigned char * V_38 , unsigned int * V_39 , void * V_40 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
struct V_22 * V_23 = NULL ;
struct V_21 * V_43 ;
struct V_10 V_44 , V_45 ;
struct V_46 * V_47 ;
int V_48 = 0 , V_50 , V_52 , V_49 ;
unsigned long V_54 , V_55 ;
struct V_57 V_58 = {
. V_59 = NULL ,
. V_60 = 0 ,
. V_61 = 0 ,
} ;
unsigned long V_62 = F_20 () ;
V_55 = ( unsigned long ) V_38 ;
if ( ! F_11 ( V_55 , V_63 ) || * V_39 != V_63 )
return - V_35 ;
F_21 () ;
V_42 = F_22 ( V_64 ) ;
if ( V_42 )
V_23 = V_42 -> V_23 ;
V_2 = (struct V_1 * ) V_36 ;
V_43 = (struct V_21 * ) F_10 ( ( unsigned long ) V_40 ,
V_20 ) ;
V_54 = ( unsigned long ) V_36 + V_2 -> V_69 ;
if ( F_24 ( ! F_11 ( V_54 , V_68 ) ) ) {
memcpy ( V_43 -> V_76 , V_36 + V_2 -> V_69 , V_37 - V_2 -> V_69 ) ;
V_54 = ( unsigned long ) V_43 -> V_76 ;
}
V_44 . V_18 = (struct V_13 * ) V_43 -> V_44 ;
V_45 . V_18 = (struct V_13 * ) V_43 -> V_45 ;
V_58 . V_66 = V_77 ;
V_47 = & V_43 -> V_47 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_58 . V_47 = F_9 ( V_47 ) ;
V_49 = V_63 / V_2 -> V_3 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_3 ; V_50 ++ ) {
V_54 = F_10 ( V_54 , V_68 ) ;
if ( V_2 -> V_4 [ V_50 ] < 0 ) {
V_52 = abs ( V_2 -> V_4 [ V_50 ] ) ;
memcpy ( ( void * ) V_55 , ( void * ) V_54 , V_52 ) ;
V_55 += V_52 ;
V_54 += V_52 ;
continue;
}
if ( ! V_23 )
goto V_78;
if ( F_24 ( ( V_54 & V_79 ) ==
( ( V_54 + V_2 -> V_4 [ V_50 ] - 1 ) & V_79 ) ) ) {
V_58 . V_36 = F_9 ( V_54 ) ;
V_58 . V_37 = V_2 -> V_4 [ V_50 ] ;
} else {
F_8 ( V_54 , V_2 -> V_4 [ V_50 ] , & V_44 ) ;
V_58 . V_36 = F_9 ( V_44 . V_18 ) ;
V_58 . V_37 = - F_7 ( & V_44 ) ;
}
if ( F_24 ( V_49 == V_20 ) ) {
V_58 . V_38 = F_9 ( V_55 ) ;
V_58 . V_39 = V_49 ;
} else {
F_8 ( V_55 , V_49 , & V_45 ) ;
V_58 . V_38 = F_9 ( V_45 . V_18 ) ;
V_58 . V_39 = - F_7 ( & V_45 ) ;
}
V_48 = F_25 ( V_42 -> V_71 , & V_58 ) ;
if ( V_48 ) {
F_17 ( V_23 , L_12 ,
V_27 , V_48 , V_58 . V_72 ) ;
V_23 = NULL ;
goto V_78;
}
V_48 = F_14 ( V_23 , & V_47 -> V_25 ) ;
if ( V_48 ) {
V_23 = NULL ;
goto V_78;
}
V_54 += V_2 -> V_4 [ V_50 ] ;
V_55 += V_47 -> V_25 . V_31 ;
continue;
V_78:
V_52 = V_49 ;
V_48 = F_30 (
( unsigned char * ) V_54 , V_2 -> V_4 [ V_50 ] ,
( unsigned char * ) V_55 , & V_52 , V_40 ) ;
if ( V_48 )
F_31 ( L_14 ,
V_27 , V_48 ) ;
if ( V_48 ) {
if ( V_48 != - V_34 && V_48 != - V_35 &&
V_48 != - V_80 )
V_48 = - V_33 ;
goto V_70;
}
V_54 += V_2 -> V_4 [ V_50 ] ;
V_55 += V_52 ;
}
* V_39 = ( unsigned int ) ( V_55 - ( unsigned long ) V_38 ) ;
V_70:
if ( V_48 )
F_32 ( V_42 ) ;
else {
if ( ! V_23 )
F_33 ( V_42 ) ;
F_34 ( V_42 ) ;
F_2 ( V_42 -> V_73 -> V_81 ,
( F_20 () - V_62 ) / V_75 ) ;
}
F_23 () ;
return V_48 ;
}
static int F_35 ( struct V_41 * V_64 )
{
if ( V_64 ) {
V_64 -> V_49 = 0 ;
V_64 -> V_82 = 0 ;
V_64 -> V_83 = 0 ;
V_64 -> V_84 = V_85 ;
return 0 ;
} else
return - V_86 ;
}
static int F_36 ( struct V_41 * V_64 ,
struct V_87 * V_88 ) {
int V_48 = 0 ;
const char * V_84 = ( const char * ) V_88 -> V_89 ;
if ( ! strncmp ( V_84 , L_15 , ( V_90 ) V_88 -> V_91 ) ) {
V_64 -> V_84 = V_92 ;
} else {
F_37 ( V_64 -> V_23 , L_16 ,
V_27 , V_84 ) ;
V_64 -> V_84 = V_85 ;
}
return V_48 ;
}
static int F_38 ( struct V_41 * V_64 ,
struct V_87 * V_88 ) {
int V_48 = 0 ;
const int * V_93 = V_88 -> V_89 ;
if ( V_88 -> V_91 != sizeof( * V_93 ) ) {
F_16 ( V_64 -> V_23 , L_17 , V_27 ) ;
F_17 ( V_64 -> V_23 , L_18 , V_27 ,
V_88 -> V_91 , sizeof( * V_93 ) ) ;
V_48 = - V_35 ;
} else {
V_64 -> V_83 = ( unsigned int ) F_4 ( * V_93 ,
( int ) V_20 ) ;
}
return V_48 ;
}
static int F_39 ( struct V_41 * V_64 ,
struct V_87 * V_88 ) {
int V_48 = 0 ;
const struct V_94 {
int V_95 ;
int V_96 ;
int V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
} * V_101 ;
if ( V_88 -> V_91 != sizeof( * V_101 ) ) {
F_16 ( V_64 -> V_23 , L_19 , V_27 ) ;
F_17 ( V_64 -> V_23 , L_20 , V_27 , V_88 -> V_91 ,
sizeof( * V_101 ) ) ;
V_48 = - V_35 ;
goto V_38;
}
V_101 = ( const struct V_94 * ) V_88 -> V_89 ;
V_64 -> V_49 =
( unsigned int ) F_4 ( V_101 -> V_96 ,
V_101 -> V_99 ) ;
V_64 -> V_49 = F_40 (unsigned int, devdata->max_sync_size,
SIZE_64K) ;
if ( V_64 -> V_49 < V_102 ) {
F_16 ( V_64 -> V_23 , L_21
L_22
L_23 ,
V_27 , V_64 -> V_49 ) ;
V_48 = - V_35 ;
goto V_38;
}
V_64 -> V_82 = ( unsigned int ) F_4 ( V_101 -> V_97 ,
V_101 -> V_100 ) ;
if ( V_64 -> V_82 < 1 ) {
F_16 ( V_64 -> V_23 , L_24
L_22
L_23 ,
V_27 , V_64 -> V_82 ) ;
V_48 = - V_35 ;
goto V_38;
}
V_38:
return V_48 ;
}
static int F_41 ( struct V_87 * V_103 )
{
struct V_41 * V_104 = NULL ;
struct V_41 * V_105 = NULL ;
struct V_106 * V_107 = NULL ;
struct V_87 * V_84 = NULL ;
struct V_87 * V_93 = NULL ;
struct V_87 * V_108 = NULL ;
int V_48 = 0 ;
unsigned long V_66 ;
F_42 ( & V_109 , V_66 ) ;
V_104 = F_43 ( V_64 ,
F_44 ( & V_109 ) ) ;
if ( V_104 )
V_107 = V_104 -> V_23 -> V_107 ;
if ( ! V_104 || ! V_107 ) {
F_45 ( L_25 , V_27 ) ;
F_46 ( & V_109 , V_66 ) ;
return - V_65 ;
}
V_105 = F_47 ( sizeof( * V_105 ) , V_110 ) ;
if ( ! V_105 ) {
F_16 ( V_104 -> V_23 , L_26 , V_27 ) ;
V_48 = - V_111 ;
goto V_112;
}
memcpy ( V_105 , V_104 , sizeof( * V_104 ) ) ;
V_105 -> V_73 = V_104 -> V_73 ;
V_84 = F_48 ( V_107 , L_27 , NULL ) ;
V_93 = F_48 ( V_107 , L_28 , NULL ) ;
V_108 = F_48 ( V_107 , L_29 , NULL ) ;
if ( ! V_84 || ! V_93 || ! V_108 ) {
F_16 ( V_104 -> V_23 , L_30 , V_27 ) ;
V_48 = - V_35 ;
goto V_112;
}
if ( V_103 ) {
if ( ! strncmp ( V_103 -> V_113 , L_27 , V_103 -> V_91 ) ) {
V_84 = V_103 ;
} else if ( ! strncmp ( V_103 -> V_113 , L_28 ,
V_103 -> V_91 ) ) {
V_93 = V_103 ;
} else if ( ! strncmp ( V_103 -> V_113 , L_29 ,
V_103 -> V_91 ) ) {
V_108 = V_103 ;
} else {
goto V_38;
}
}
V_48 = F_36 ( V_105 , V_84 ) ;
if ( V_48 )
goto V_112;
V_48 = F_38 ( V_105 , V_93 ) ;
if ( V_48 )
goto V_112;
V_48 = F_39 ( V_105 , V_108 ) ;
if ( V_48 )
goto V_112;
V_38:
F_37 ( V_104 -> V_23 , L_31 ,
V_27 , V_105 -> V_49 ,
V_104 -> V_49 ) ;
F_37 ( V_104 -> V_23 , L_32 ,
V_27 , V_105 -> V_82 ,
V_104 -> V_82 ) ;
F_37 ( V_104 -> V_23 , L_33 ,
V_27 , V_105 -> V_83 ,
V_104 -> V_83 ) ;
F_49 ( V_64 , V_105 ) ;
F_46 ( & V_109 , V_66 ) ;
F_50 () ;
F_51 ( V_105 -> V_23 , V_105 ) ;
F_52 ( V_104 ) ;
return 0 ;
V_112:
if ( V_105 ) {
F_37 ( V_104 -> V_23 , L_34 , V_27 ) ;
F_35 ( V_105 ) ;
F_49 ( V_64 , V_105 ) ;
F_46 ( & V_109 , V_66 ) ;
F_50 () ;
F_51 ( V_105 -> V_23 , V_105 ) ;
F_52 ( V_104 ) ;
} else {
F_16 ( V_104 -> V_23 , L_35 , V_27 ) ;
F_46 ( & V_109 , V_66 ) ;
}
if ( ! V_48 )
V_48 = - V_35 ;
return V_48 ;
}
static int F_53 ( struct V_114 * V_115 , unsigned long V_116 ,
void * V_117 )
{
struct V_118 * V_119 = V_117 ;
struct V_41 * V_42 ;
struct V_106 * V_120 = NULL ;
F_21 () ;
V_42 = F_22 ( V_64 ) ;
if ( V_42 )
V_120 = V_42 -> V_23 -> V_107 ;
if ( V_42 &&
V_116 == V_121 &&
! strcmp ( V_119 -> V_122 -> V_113 , V_120 -> V_113 ) ) {
F_23 () ;
F_41 ( V_119 -> V_88 ) ;
} else
F_23 () ;
return V_123 ;
}
static T_2 F_54 ( struct V_22 * V_23 ,
struct V_124 * V_125 , char * V_14 ) {
char * V_126 = V_14 ;
struct V_41 * V_42 ;
T_1 * V_5 ;
int V_127 = V_63 ;
int V_128 ;
int V_50 ;
F_21 () ;
V_42 = F_22 ( V_64 ) ;
if ( ! V_42 ) {
F_23 () ;
return 0 ;
}
if ( V_125 == & V_129 )
V_5 = V_42 -> V_73 -> V_74 ;
else if ( V_125 == & V_130 )
V_5 = V_42 -> V_73 -> V_81 ;
else {
F_23 () ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < ( V_7 - 2 ) ; V_50 ++ ) {
V_128 = snprintf ( V_126 , V_127 , L_36 ,
V_50 ? ( 2 << ( V_50 - 1 ) ) : 0 , ( 2 << V_50 ) - 1 ,
F_55 ( & V_5 [ V_50 ] ) ) ;
V_127 -= V_128 ;
V_126 += V_128 ;
}
V_128 = snprintf ( V_126 , V_127 , L_37 ,
2 << ( V_7 - 2 ) ,
F_55 ( & V_5 [ ( V_7 - 1 ) ] ) ) ;
V_126 += V_128 ;
F_23 () ;
return V_126 - V_14 ;
}
static int T_3 F_56 ( struct V_8 * V_9 ,
const struct V_131 * V_132 )
{
struct V_41 * V_104 , * V_105 = NULL ;
unsigned long V_66 ;
int V_48 = 0 ;
F_42 ( & V_109 , V_66 ) ;
V_104 = F_43 ( V_64 ,
F_44 ( & V_109 ) ) ;
if ( V_104 && V_104 -> V_71 != NULL ) {
F_16 ( & V_9 -> V_23 , L_38 , V_27 ) ;
V_48 = - 1 ;
goto V_133;
}
F_51 ( & V_9 -> V_23 , NULL ) ;
V_105 = F_47 ( sizeof( * V_105 ) , V_110 ) ;
if ( ! V_105 ) {
F_16 ( & V_9 -> V_23 , L_26 , V_27 ) ;
V_48 = - V_111 ;
goto V_133;
}
V_105 -> V_73 = F_47 ( sizeof( * V_105 -> V_73 ) ,
V_110 ) ;
if ( ! V_105 -> V_73 ) {
F_16 ( & V_9 -> V_23 , L_39 , V_27 ) ;
V_48 = - V_111 ;
goto V_133;
}
V_105 -> V_71 = V_9 ;
V_105 -> V_23 = & V_9 -> V_23 ;
F_35 ( V_105 ) ;
F_49 ( V_64 , V_105 ) ;
F_46 ( & V_109 , V_66 ) ;
F_50 () ;
F_52 ( V_104 ) ;
F_57 ( & V_134 ) ;
V_48 = F_41 ( NULL ) ;
if ( V_48 && V_48 != - V_65 ) {
F_16 ( & V_9 -> V_23 , L_40 , V_48 ) ;
V_48 = - 1 ;
goto error;
}
F_21 () ;
if ( F_51 ( & V_9 -> V_23 , F_22 ( V_64 ) ) ) {
F_23 () ;
F_16 ( & V_9 -> V_23 , L_41 ) ;
V_48 = - 1 ;
goto error;
}
F_23 () ;
if ( F_58 ( & V_9 -> V_23 . V_135 , & V_136 ) ) {
F_16 ( & V_9 -> V_23 , L_42 ) ;
V_48 = - 1 ;
goto error;
}
return 0 ;
V_133:
F_46 ( & V_109 , V_66 ) ;
if ( V_105 )
F_52 ( V_105 -> V_73 ) ;
F_52 ( V_105 ) ;
error:
return V_48 ;
}
static int T_4 F_59 ( struct V_8 * V_9 )
{
struct V_41 * V_104 ;
unsigned long V_66 ;
F_60 ( L_43 ) ;
F_61 ( & V_9 -> V_23 . V_135 , & V_136 ) ;
F_42 ( & V_109 , V_66 ) ;
V_104 = F_43 ( V_64 ,
F_44 ( & V_109 ) ) ;
F_62 ( & V_134 ) ;
F_49 ( V_64 , NULL ) ;
F_46 ( & V_109 , V_66 ) ;
F_50 () ;
F_51 ( & V_9 -> V_23 , NULL ) ;
if ( V_104 )
F_52 ( V_104 -> V_73 ) ;
F_52 ( V_104 ) ;
return 0 ;
}
static int T_3 F_63 ( void )
{
struct V_41 * V_105 ;
F_60 ( L_44 ) ;
F_64 ( V_64 , NULL ) ;
V_105 = F_47 ( sizeof( * V_105 ) , V_137 ) ;
if ( ! V_105 ) {
F_45 ( L_45 ) ;
return - V_111 ;
}
V_105 -> V_84 = V_85 ;
F_64 ( V_64 , V_105 ) ;
return F_65 ( & V_138 ) ;
}
static void T_4 F_66 ( void )
{
struct V_41 * V_104 ;
unsigned long V_66 ;
F_60 ( L_46 ) ;
F_42 ( & V_109 , V_66 ) ;
V_104 = F_43 ( V_64 ,
F_44 ( & V_109 ) ) ;
F_49 ( V_64 , NULL ) ;
F_46 ( & V_109 , V_66 ) ;
F_50 () ;
if ( V_104 )
F_51 ( V_104 -> V_23 , NULL ) ;
F_52 ( V_104 ) ;
F_67 ( & V_138 ) ;
}
static T_5 F_68 ( const char * V_14 , int V_139 )
{
T_5 V_140 ;
T_6 V_141 ;
V_141 = F_69 ( * ( T_6 * ) ( V_14 ) ) ;
V_141 = ( T_6 ) ( V_141 << V_139 ) ;
V_141 = F_70 ( V_141 ) ;
memcpy ( & V_140 , & V_141 , 1 ) ;
return V_140 ;
}
static T_5 F_71 ( const char * * V_14 , int * V_139 )
{
T_5 V_142 ;
V_142 = F_68 ( * V_14 , * V_139 ) ;
V_142 = V_142 >> 3 ;
V_142 &= 0x1F ;
* V_14 += ( * V_139 + 5 ) / 8 ;
* V_139 = ( * V_139 + 5 ) % 8 ;
return V_142 ;
}
static T_5 F_72 ( const char * * V_14 , int * V_139 )
{
T_5 V_142 ;
V_142 = F_68 ( * V_14 , * V_139 ) ;
V_142 = V_142 >> 2 ;
V_142 &= 0x3F ;
* V_14 += ( * V_139 + 6 ) / 8 ;
* V_139 = ( * V_139 + 6 ) % 8 ;
return V_142 ;
}
static T_5 F_73 ( const char * * V_14 , int * V_139 )
{
T_5 V_19 ;
V_19 = F_68 ( * V_14 , * V_139 ) ;
( * V_14 ) ++ ;
return V_19 ;
}
static T_6 F_74 ( const char * * V_14 , int * V_139 ,
struct V_143 * V_144 )
{
T_6 V_19 ;
V_19 = F_69 ( * ( T_6 * ) ( * V_14 ) ) ;
V_19 = ( T_6 ) ( V_19 << * V_139 ) ;
V_19 = V_19 >> 7 ;
V_19 &= 0x01FF ;
* V_14 += ( * V_139 + 9 ) / 8 ;
* V_139 = ( * V_139 + 9 ) % 8 ;
return V_19 ;
}
static T_5 F_75 ( const char * * V_14 , int * V_139 ,
struct V_143 * V_144 )
{
return F_73 ( V_14 , V_139 ) ;
}
static int F_76 ( const char * * V_54 , int * V_145 ,
unsigned char * * V_55 , struct V_143 * V_144 )
{
int V_48 ;
V_48 = F_77 ( V_54 , V_145 , V_55 , V_144 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_77 ( V_54 , V_145 , V_55 , V_144 ) ;
return V_48 ;
}
static int F_77 ( const char * * V_54 , int * V_145 ,
unsigned char * * V_55 , struct V_143 * V_144 )
{
int V_48 ;
V_48 = F_78 ( V_54 , V_145 , V_55 , V_144 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_78 ( V_54 , V_145 , V_55 , V_144 ) ;
return V_48 ;
}
static int F_78 ( const char * * V_54 , int * V_145 ,
unsigned char * * V_55 , struct V_143 * V_144 )
{
* * V_55 = F_68 ( * V_54 , * V_145 ) ;
( * V_54 ) ++ ;
( * V_55 ) ++ ;
* * V_55 = F_68 ( * V_54 , * V_145 ) ;
( * V_54 ) ++ ;
( * V_55 ) ++ ;
return 0 ;
}
static int F_79 ( const char * * V_54 , int * V_145 ,
unsigned char * * V_55 , struct V_143 * V_144 )
{
T_5 V_19 ;
V_19 = F_75 ( V_54 , V_145 , V_144 ) ;
if ( ! V_144 -> V_146 && ( V_19 >= V_144 -> V_147 ) )
return 1 ;
memcpy ( * V_55 , V_144 -> V_148 [ V_19 ] , 8 ) ;
* V_55 += 8 ;
return 0 ;
}
static int F_80 ( const char * * V_54 , int * V_145 ,
unsigned char * * V_55 , struct V_143 * V_144 )
{
T_6 V_19 ;
V_19 = F_74 ( V_54 , V_145 , V_144 ) ;
if ( ! V_144 -> V_146 && ( V_19 >= V_144 -> V_149 ) )
return 1 ;
memcpy ( * V_55 , V_144 -> V_150 [ V_19 ] , 4 ) ;
* V_55 += 4 ;
return 0 ;
}
static int F_81 ( const char * * V_54 , int * V_145 ,
unsigned char * * V_55 , struct V_143 * V_144 )
{
T_5 V_19 ;
V_19 = F_73 ( V_54 , V_145 ) ;
if ( ! V_144 -> V_151 && ( V_19 >= V_144 -> V_152 ) )
return 1 ;
memcpy ( * V_55 , V_144 -> V_153 [ V_19 ] , 2 ) ;
* V_55 += 2 ;
return 0 ;
}
static void F_82 ( const char * V_14 , struct V_143 * V_144 )
{
unsigned char V_154 = V_144 -> V_152 ;
memcpy ( V_144 -> V_148 [ V_144 -> V_147 ] , V_14 , 8 ) ;
V_144 -> V_149 += 2 ;
V_144 -> V_147 += 1 ;
if ( ! V_144 -> V_146 && V_144 -> V_149 >= 512 ) {
V_144 -> V_146 = 1 ;
V_144 -> V_149 /= 512 ;
}
memcpy ( V_144 -> V_153 [ V_144 -> V_152 ++ ] , V_14 , 2 ) ;
memcpy ( V_144 -> V_153 [ V_144 -> V_152 ++ ] , V_14 + 2 , 2 ) ;
memcpy ( V_144 -> V_153 [ V_144 -> V_152 ++ ] , V_14 + 4 , 2 ) ;
memcpy ( V_144 -> V_153 [ V_144 -> V_152 ++ ] , V_14 + 6 , 2 ) ;
if ( V_144 -> V_152 < V_154 )
V_144 -> V_151 = 1 ;
}
static int F_30 ( const unsigned char * V_155 , int V_156 ,
unsigned char * V_157 , int * V_158 ,
const void * V_159 )
{
T_5 V_140 ;
const char * V_54 ;
int V_145 = 0 ;
unsigned char * V_55 , * V_160 , * V_161 , * V_162 ;
const char * V_163 ;
T_7 V_58 ;
int V_164 ;
int V_50 , V_165 ;
struct V_143 * V_144 ;
int V_48 = 0 ;
V_144 = & ( (struct V_21 * ) ( V_159 ) ) -> V_166 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_161 = NULL ;
V_54 = V_155 ;
V_163 = V_155 + V_156 ;
V_55 = V_157 ;
V_160 = V_157 + * V_158 ;
while ( ( V_140 = F_71 ( & V_54 , & V_145 ) ) != V_167 ) {
if ( V_54 >= V_163 ) {
V_48 = - V_35 ;
goto V_38;
}
V_164 = 0 ;
V_162 = V_161 ;
V_161 = V_55 ;
switch ( V_140 ) {
case V_168 :
if ( V_162 == NULL ) {
V_48 = - V_35 ;
goto V_38;
}
V_165 = F_72 ( & V_54 ,
& V_145 ) + 1 ;
if ( V_54 > V_163 ) {
V_48 = - V_35 ;
goto V_38;
}
for ( V_50 = 0 ; V_50 < V_165 ; V_50 ++ ) {
if ( ( V_55 + 8 ) > V_160 ) {
V_48 = - V_34 ;
goto V_38;
}
memcpy ( V_55 , V_162 , 8 ) ;
F_82 ( V_55 , V_144 ) ;
V_55 += 8 ;
}
break;
case V_169 :
if ( ( V_55 + 8 ) > V_160 ) {
V_48 = - V_34 ;
goto V_38;
}
memset ( V_55 , 0 , 8 ) ;
F_82 ( V_55 , V_144 ) ;
V_55 += 8 ;
break;
default:
if ( V_140 > 25 ) {
V_48 = - V_35 ;
goto V_38;
}
if ( ( V_54 + 2 ) > V_163 ) {
V_48 = - V_35 ;
goto V_38;
}
if ( ( V_55 + 8 ) > V_160 ) {
V_48 = - V_34 ;
goto V_38;
}
while ( V_164 < 4 &&
( V_58 = V_170 [ V_140 ] [ V_164 ++ ] )
!= NULL ) {
V_48 = (* V_58)( & V_54 , & V_145 , & V_55 , V_144 ) ;
if ( V_48 ) {
V_48 = - V_35 ;
goto V_38;
}
F_82 ( V_161 , V_144 ) ;
}
}
}
V_38:
if ( ! V_48 )
* V_158 = ( unsigned int ) ( V_55 - V_157 ) ;
else
* V_158 = 0 ;
return V_48 ;
}
