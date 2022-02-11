static int F_1 ( unsigned long V_1 , unsigned int * V_2 , bool V_3 )
{
if ( ! F_2 ( V_1 , V_4 . V_5 ) ) {
F_3 ( L_1 ,
V_3 ? L_2 : L_3 , V_1 ,
V_4 . V_5 ) ;
return - V_6 ;
}
if ( * V_2 % V_4 . V_7 ) {
F_3 ( L_4 ,
V_3 ? L_2 : L_3 , * V_2 ,
V_4 . V_7 ) ;
if ( V_3 )
return - V_6 ;
* V_2 = F_4 ( * V_2 , V_4 . V_7 ) ;
}
if ( * V_2 < V_4 . V_8 ) {
F_3 ( L_5 ,
V_3 ? L_2 : L_3 , * V_2 ,
V_4 . V_8 ) ;
return - V_6 ;
}
if ( * V_2 > V_4 . V_9 ) {
F_3 ( L_6 ,
V_3 ? L_2 : L_3 , * V_2 ,
V_4 . V_9 ) ;
if ( V_3 )
return - V_6 ;
* V_2 = V_4 . V_9 ;
}
return 0 ;
}
static void F_5 ( T_1 * V_10 , unsigned int time )
{
int V_11 = F_6 ( time ) ;
if ( V_11 )
V_11 = F_7 ( ( V_12 - 1 ) , V_11 - 1 ) ;
F_8 ( & V_10 [ V_11 ] ) ;
}
static unsigned long F_9 ( struct V_13 * V_14 )
{
return 0 ;
}
static inline unsigned long F_10 (
struct V_15 * V_16 )
{
return V_16 -> V_17 * sizeof( struct V_18 ) ;
}
static int F_11 ( unsigned long V_1 , int V_2 ,
struct V_15 * V_16 )
{
unsigned long V_19 ;
struct V_18 * V_20 ;
V_16 -> V_17 = 0 ;
V_20 = V_16 -> V_21 ;
while ( V_2 ) {
V_20 -> V_22 = F_12 ( F_13 ( ( void * ) V_1 ) ) ;
V_19 = F_14 ( int , V_2 ,
F_15 ( V_1 , V_23 ) ) ;
V_20 -> V_2 = F_12 ( V_19 ) ;
V_2 -= V_19 ;
V_1 += V_19 ;
V_16 -> V_17 ++ ;
V_20 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
if ( ! F_17 ( V_27 -> V_28 ) ) {
F_18 ( V_25 , L_7 ,
V_29 ) ;
F_19 ( V_25 , L_8 ,
V_27 -> V_28 ,
V_27 -> V_30 ,
V_27 -> V_31 ,
V_27 -> V_32 ) ;
F_19 ( V_25 , L_9 ,
F_20 ( V_27 -> V_33 ) ,
( unsigned long ) F_21 ( V_27 -> V_34 ) ) ;
return - V_35 ;
}
switch ( V_27 -> V_31 ) {
case 0 :
break;
case 64 :
F_19 ( V_25 , L_10 ,
V_29 ) ;
break;
case 13 :
F_19 ( V_25 , L_11 ,
V_29 ) ;
return - V_36 ;
case 65 :
F_19 ( V_25 , L_12 ,
V_29 ) ;
return - V_6 ;
case 66 :
case 67 :
F_19 ( V_25 , L_13 ,
V_29 , V_27 -> V_31 ) ;
return - V_6 ;
default:
F_19 ( V_25 , L_14 ,
V_29 , V_27 -> V_31 ) ;
return - V_35 ;
}
if ( ! F_22 ( V_27 -> V_32 ) ) {
F_18 ( V_25 , L_15
L_16
L_17
L_18
L_19 , V_29 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_23 ( const unsigned char * V_3 , unsigned int V_37 ,
unsigned char * V_38 , unsigned int * V_39 ,
void * V_40 )
{
struct V_41 * V_42 ;
struct V_24 * V_25 = NULL ;
struct V_43 * V_44 ;
struct V_15 V_45 , V_46 ;
struct V_47 * V_48 ;
int V_49 = 0 , V_50 ;
unsigned long V_51 , V_52 ;
struct V_53 V_54 = {
. V_55 = NULL ,
. V_56 = 0 ,
. V_57 = 0 ,
} ;
unsigned long V_58 = F_24 () ;
V_51 = ( unsigned long ) V_3 ;
if ( F_1 ( V_51 , & V_37 , true ) )
return - V_6 ;
V_52 = ( unsigned long ) V_38 ;
if ( F_1 ( V_52 , V_39 , false ) )
return - V_6 ;
F_25 () ;
V_42 = F_26 ( V_59 ) ;
if ( ! V_42 || ! V_42 -> V_25 ) {
F_27 () ;
return - V_60 ;
}
V_50 = V_42 -> V_50 ;
V_25 = V_42 -> V_25 ;
V_44 = F_28 ( V_40 , V_61 ) ;
V_45 . V_21 = (struct V_18 * ) V_44 -> V_45 ;
V_46 . V_21 = (struct V_18 * ) V_44 -> V_46 ;
V_54 . V_62 = V_63 ;
V_48 = & V_44 -> V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_54 . V_48 = F_13 ( V_48 ) ;
if ( ( V_51 & V_64 ) ==
( ( V_51 + V_37 - 1 ) & V_64 ) ) {
V_54 . V_3 = F_13 ( ( void * ) V_51 ) ;
V_54 . V_37 = V_37 ;
} else {
F_11 ( V_51 , V_37 , & V_45 ) ;
V_54 . V_3 = F_13 ( V_45 . V_21 ) ;
V_54 . V_37 = - F_10 ( & V_45 ) ;
}
if ( ( V_52 & V_64 ) ==
( ( V_52 + * V_39 - 1 ) & V_64 ) ) {
V_54 . V_38 = F_13 ( ( void * ) V_52 ) ;
V_54 . V_39 = * V_39 ;
} else {
F_11 ( V_52 , * V_39 , & V_46 ) ;
V_54 . V_38 = F_13 ( V_46 . V_21 ) ;
V_54 . V_39 = - F_10 ( & V_46 ) ;
}
F_19 ( V_25 , L_20 ,
V_29 , ( unsigned long ) V_54 . V_3 , ( long ) V_54 . V_37 ,
( unsigned long ) V_54 . V_38 , ( long ) V_54 . V_39 ) ;
V_49 = F_29 ( V_42 -> V_65 , & V_54 ) ;
if ( V_49 ) {
F_19 ( V_25 , L_21 ,
V_29 , V_49 , V_54 . V_66 ) ;
V_49 = - V_35 ;
goto V_67;
}
V_49 = F_16 ( V_25 , & V_48 -> V_27 ) ;
if ( V_49 )
goto V_67;
* V_39 = F_20 ( V_48 -> V_27 . V_33 ) ;
F_19 ( V_25 , L_22 , V_29 , * V_39 ) ;
V_67:
if ( V_49 )
F_30 ( V_42 ) ;
else {
F_31 ( V_42 ) ;
F_5 ( V_42 -> V_68 -> V_69 ,
( F_24 () - V_58 ) / V_70 ) ;
}
F_27 () ;
return V_49 ;
}
static int F_32 ( const unsigned char * V_3 , unsigned int V_37 ,
unsigned char * V_38 , unsigned int * V_39 ,
void * V_40 )
{
struct V_41 * V_42 ;
struct V_24 * V_25 = NULL ;
struct V_43 * V_44 ;
struct V_15 V_45 , V_46 ;
struct V_47 * V_48 ;
int V_49 = 0 , V_50 ;
unsigned long V_51 , V_52 ;
struct V_53 V_54 = {
. V_55 = NULL ,
. V_56 = 0 ,
. V_57 = 0 ,
} ;
unsigned long V_58 = F_24 () ;
V_51 = ( unsigned long ) V_3 ;
if ( F_1 ( V_51 , & V_37 , true ) )
return - V_6 ;
V_52 = ( unsigned long ) V_38 ;
if ( F_1 ( V_52 , V_39 , false ) )
return - V_6 ;
F_25 () ;
V_42 = F_26 ( V_59 ) ;
if ( ! V_42 || ! V_42 -> V_25 ) {
F_27 () ;
return - V_60 ;
}
V_50 = V_42 -> V_50 ;
V_25 = V_42 -> V_25 ;
V_44 = F_28 ( V_40 , V_61 ) ;
V_45 . V_21 = (struct V_18 * ) V_44 -> V_45 ;
V_46 . V_21 = (struct V_18 * ) V_44 -> V_46 ;
V_54 . V_62 = V_71 ;
V_48 = & V_44 -> V_48 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_54 . V_48 = F_13 ( V_48 ) ;
if ( ( V_51 & V_64 ) ==
( ( V_51 + V_37 - 1 ) & V_64 ) ) {
V_54 . V_3 = F_13 ( ( void * ) V_51 ) ;
V_54 . V_37 = V_37 ;
} else {
F_11 ( V_51 , V_37 , & V_45 ) ;
V_54 . V_3 = F_13 ( V_45 . V_21 ) ;
V_54 . V_37 = - F_10 ( & V_45 ) ;
}
if ( ( V_52 & V_64 ) ==
( ( V_52 + * V_39 - 1 ) & V_64 ) ) {
V_54 . V_38 = F_13 ( ( void * ) V_52 ) ;
V_54 . V_39 = * V_39 ;
} else {
F_11 ( V_52 , * V_39 , & V_46 ) ;
V_54 . V_38 = F_13 ( V_46 . V_21 ) ;
V_54 . V_39 = - F_10 ( & V_46 ) ;
}
F_19 ( V_25 , L_20 ,
V_29 , ( unsigned long ) V_54 . V_3 , ( long ) V_54 . V_37 ,
( unsigned long ) V_54 . V_38 , ( long ) V_54 . V_39 ) ;
V_49 = F_29 ( V_42 -> V_65 , & V_54 ) ;
if ( V_49 ) {
F_19 ( V_25 , L_21 ,
V_29 , V_49 , V_54 . V_66 ) ;
goto V_67;
}
V_49 = F_16 ( V_25 , & V_48 -> V_27 ) ;
if ( V_49 )
goto V_67;
* V_39 = F_20 ( V_48 -> V_27 . V_33 ) ;
V_67:
if ( V_49 )
F_33 ( V_42 ) ;
else {
F_34 ( V_42 ) ;
F_5 ( V_42 -> V_68 -> V_72 ,
( F_24 () - V_58 ) / V_70 ) ;
}
F_27 () ;
return V_49 ;
}
static int F_35 ( struct V_41 * V_59 )
{
if ( V_59 ) {
V_59 -> V_50 = 0 ;
V_59 -> V_73 = 0 ;
V_59 -> V_74 = 0 ;
return 0 ;
} else
return - V_75 ;
}
static int F_36 ( struct V_76 * V_77 )
{
const char * V_78 = ( const char * ) V_77 -> V_79 ;
if ( ! strncmp ( V_78 , L_23 , ( V_80 ) V_77 -> V_81 ) )
return 0 ;
if ( ! strncmp ( V_78 , L_24 , ( V_80 ) V_77 -> V_81 ) )
return - V_60 ;
F_37 ( V_59 -> V_25 , L_25 , V_29 , V_78 ) ;
return - V_6 ;
}
static int F_38 ( struct V_41 * V_59 ,
struct V_76 * V_77 ) {
int V_49 = 0 ;
const unsigned int V_82 = F_39 ( V_77 -> V_79 , 1 ) ;
if ( V_77 -> V_81 != sizeof( V_82 ) ) {
F_18 ( V_59 -> V_25 , L_26 , V_29 ) ;
F_19 ( V_59 -> V_25 , L_27 , V_29 ,
V_77 -> V_81 , sizeof( V_82 ) ) ;
V_49 = - V_6 ;
} else {
V_59 -> V_74 = F_14 (unsigned int,
maxsglen, NX842_HW_PAGE_SIZE) ;
}
return V_49 ;
}
static int F_40 ( struct V_41 * V_59 ,
struct V_76 * V_77 ) {
int V_49 = 0 ;
unsigned int V_83 , V_84 ;
unsigned int V_85 , V_86 ;
const struct V_87 {
T_2 V_88 ;
T_2 V_83 ;
T_2 V_85 ;
T_2 V_89 ;
T_2 V_84 ;
T_2 V_86 ;
} * V_90 ;
if ( V_77 -> V_81 != sizeof( * V_90 ) ) {
F_18 ( V_59 -> V_25 , L_28 , V_29 ) ;
F_19 ( V_59 -> V_25 , L_29 , V_29 , V_77 -> V_81 ,
sizeof( * V_90 ) ) ;
V_49 = - V_6 ;
goto V_38;
}
V_90 = ( const struct V_87 * ) V_77 -> V_79 ;
V_83 = F_20 ( V_90 -> V_83 ) ;
V_85 = F_20 ( V_90 -> V_85 ) ;
V_84 = F_20 ( V_90 -> V_84 ) ;
V_86 = F_20 ( V_90 -> V_86 ) ;
V_59 -> V_50 = F_7 ( V_83 , V_84 ) ;
V_59 -> V_50 = F_14 (unsigned int, devdata->max_sync_size,
65536 ) ;
if ( V_59 -> V_50 < 4096 ) {
F_18 ( V_59 -> V_25 , L_30
L_31
L_32 ,
V_29 , V_59 -> V_50 ) ;
V_49 = - V_6 ;
goto V_38;
}
V_4 . V_9 = V_59 -> V_50 ;
V_59 -> V_73 = F_7 ( V_85 , V_86 ) ;
if ( V_59 -> V_73 < 1 ) {
F_18 ( V_59 -> V_25 , L_33
L_31
L_32 ,
V_29 , V_59 -> V_73 ) ;
V_49 = - V_6 ;
goto V_38;
}
V_38:
return V_49 ;
}
static int F_41 ( struct V_76 * V_91 )
{
struct V_41 * V_92 = NULL ;
struct V_41 * V_93 = NULL ;
struct V_94 * V_95 = NULL ;
struct V_76 * V_78 = NULL ;
struct V_76 * V_82 = NULL ;
struct V_76 * V_96 = NULL ;
int V_49 = 0 ;
unsigned long V_62 ;
V_93 = F_42 ( sizeof( * V_93 ) , V_97 ) ;
if ( ! V_93 )
return - V_98 ;
F_43 ( & V_99 , V_62 ) ;
V_92 = F_44 ( V_59 ,
F_45 ( & V_99 ) ) ;
if ( V_92 )
V_95 = V_92 -> V_25 -> V_95 ;
if ( ! V_92 || ! V_95 ) {
F_46 ( L_34 , V_29 ) ;
F_47 ( & V_99 , V_62 ) ;
F_48 ( V_93 ) ;
return - V_60 ;
}
memcpy ( V_93 , V_92 , sizeof( * V_92 ) ) ;
V_93 -> V_68 = V_92 -> V_68 ;
V_78 = F_49 ( V_95 , L_35 , NULL ) ;
V_82 = F_49 ( V_95 , L_36 , NULL ) ;
V_96 = F_49 ( V_95 , L_37 , NULL ) ;
if ( ! V_78 || ! V_82 || ! V_96 ) {
F_18 ( V_92 -> V_25 , L_38 , V_29 ) ;
V_49 = - V_6 ;
goto V_100;
}
if ( V_91 && ( strncmp ( V_91 -> V_101 , L_35 , V_91 -> V_81 ) ||
strncmp ( V_91 -> V_101 , L_36 , V_91 -> V_81 ) ||
strncmp ( V_91 -> V_101 , L_37 , V_91 -> V_81 ) ) )
goto V_38;
V_49 = F_36 ( V_78 ) ;
if ( V_49 )
goto V_100;
V_49 = F_38 ( V_93 , V_82 ) ;
if ( V_49 )
goto V_100;
V_49 = F_40 ( V_93 , V_96 ) ;
if ( V_49 )
goto V_100;
V_38:
F_37 ( V_92 -> V_25 , L_39 ,
V_29 , V_93 -> V_50 ,
V_92 -> V_50 ) ;
F_37 ( V_92 -> V_25 , L_40 ,
V_29 , V_93 -> V_73 ,
V_92 -> V_73 ) ;
F_37 ( V_92 -> V_25 , L_41 ,
V_29 , V_93 -> V_74 ,
V_92 -> V_74 ) ;
F_50 ( V_59 , V_93 ) ;
F_47 ( & V_99 , V_62 ) ;
F_51 () ;
F_52 ( V_93 -> V_25 , V_93 ) ;
F_48 ( V_92 ) ;
return 0 ;
V_100:
if ( V_93 ) {
F_37 ( V_92 -> V_25 , L_42 , V_29 ) ;
F_35 ( V_93 ) ;
F_50 ( V_59 , V_93 ) ;
F_47 ( & V_99 , V_62 ) ;
F_51 () ;
F_52 ( V_93 -> V_25 , V_93 ) ;
F_48 ( V_92 ) ;
} else {
F_18 ( V_92 -> V_25 , L_43 , V_29 ) ;
F_47 ( & V_99 , V_62 ) ;
}
if ( ! V_49 )
V_49 = - V_6 ;
return V_49 ;
}
static int F_53 ( struct V_102 * V_103 , unsigned long V_104 ,
void * V_105 )
{
struct V_106 * V_107 = V_105 ;
struct V_41 * V_42 ;
struct V_94 * V_108 = NULL ;
F_25 () ;
V_42 = F_26 ( V_59 ) ;
if ( V_42 )
V_108 = V_42 -> V_25 -> V_95 ;
if ( V_42 &&
V_104 == V_109 &&
! strcmp ( V_107 -> V_110 -> V_101 , V_108 -> V_101 ) ) {
F_27 () ;
F_41 ( V_107 -> V_77 ) ;
} else
F_27 () ;
return V_111 ;
}
static T_3 F_54 ( struct V_24 * V_25 ,
struct V_112 * V_113 , char * V_1 ) {
char * V_114 = V_1 ;
struct V_41 * V_42 ;
T_1 * V_10 ;
int V_115 = V_116 ;
int V_117 ;
int V_118 ;
F_25 () ;
V_42 = F_26 ( V_59 ) ;
if ( ! V_42 ) {
F_27 () ;
return 0 ;
}
if ( V_113 == & V_119 )
V_10 = V_42 -> V_68 -> V_69 ;
else if ( V_113 == & V_120 )
V_10 = V_42 -> V_68 -> V_72 ;
else {
F_27 () ;
return 0 ;
}
for ( V_118 = 0 ; V_118 < ( V_12 - 2 ) ; V_118 ++ ) {
V_117 = snprintf ( V_114 , V_115 , L_44 ,
V_118 ? ( 2 << ( V_118 - 1 ) ) : 0 , ( 2 << V_118 ) - 1 ,
F_55 ( & V_10 [ V_118 ] ) ) ;
V_115 -= V_117 ;
V_114 += V_117 ;
}
V_117 = snprintf ( V_114 , V_115 , L_45 ,
2 << ( V_12 - 2 ) ,
F_55 ( & V_10 [ ( V_12 - 1 ) ] ) ) ;
V_114 += V_117 ;
F_27 () ;
return V_114 - V_1 ;
}
static int F_56 ( struct V_121 * V_122 )
{
return F_57 ( V_122 , & V_123 ) ;
}
static int F_58 ( struct V_13 * V_14 ,
const struct V_124 * V_125 )
{
struct V_41 * V_92 , * V_93 = NULL ;
unsigned long V_62 ;
int V_49 = 0 ;
V_93 = F_42 ( sizeof( * V_93 ) , V_97 ) ;
if ( ! V_93 )
return - V_98 ;
V_93 -> V_68 = F_42 ( sizeof( * V_93 -> V_68 ) ,
V_97 ) ;
if ( ! V_93 -> V_68 ) {
F_48 ( V_93 ) ;
return - V_98 ;
}
F_43 ( & V_99 , V_62 ) ;
V_92 = F_44 ( V_59 ,
F_45 ( & V_99 ) ) ;
if ( V_92 && V_92 -> V_65 != NULL ) {
F_18 ( & V_14 -> V_25 , L_46 , V_29 ) ;
V_49 = - 1 ;
goto V_126;
}
F_52 ( & V_14 -> V_25 , NULL ) ;
V_93 -> V_65 = V_14 ;
V_93 -> V_25 = & V_14 -> V_25 ;
F_35 ( V_93 ) ;
F_50 ( V_59 , V_93 ) ;
F_47 ( & V_99 , V_62 ) ;
F_51 () ;
F_48 ( V_92 ) ;
F_59 ( & V_127 ) ;
V_49 = F_41 ( NULL ) ;
if ( V_49 )
goto error;
V_49 = F_60 ( & V_128 ) ;
if ( V_49 ) {
F_18 ( & V_14 -> V_25 , L_47 , V_49 ) ;
goto error;
}
F_25 () ;
F_52 ( & V_14 -> V_25 , F_26 ( V_59 ) ) ;
F_27 () ;
if ( F_61 ( & V_14 -> V_25 . V_129 , & V_130 ) ) {
F_18 ( & V_14 -> V_25 , L_48 ) ;
V_49 = - 1 ;
goto error;
}
return 0 ;
V_126:
F_47 ( & V_99 , V_62 ) ;
if ( V_93 )
F_48 ( V_93 -> V_68 ) ;
F_48 ( V_93 ) ;
error:
return V_49 ;
}
static int F_62 ( struct V_13 * V_14 )
{
struct V_41 * V_92 ;
unsigned long V_62 ;
F_63 ( L_49 ) ;
F_64 ( & V_14 -> V_25 . V_129 , & V_130 ) ;
F_65 ( & V_128 ) ;
F_43 ( & V_99 , V_62 ) ;
V_92 = F_44 ( V_59 ,
F_45 ( & V_99 ) ) ;
F_66 ( & V_127 ) ;
F_67 ( V_59 , NULL ) ;
F_47 ( & V_99 , V_62 ) ;
F_51 () ;
F_52 ( & V_14 -> V_25 , NULL ) ;
if ( V_92 )
F_48 ( V_92 -> V_68 ) ;
F_48 ( V_92 ) ;
return 0 ;
}
static int T_4 F_68 ( void )
{
struct V_41 * V_93 ;
int V_49 ;
if ( ! F_69 ( NULL , NULL , L_50 ) )
return - V_60 ;
F_67 ( V_59 , NULL ) ;
V_93 = F_42 ( sizeof( * V_93 ) , V_131 ) ;
if ( ! V_93 ) {
F_46 ( L_51 ) ;
return - V_98 ;
}
F_67 ( V_59 , V_93 ) ;
V_49 = F_70 ( & V_132 ) ;
if ( V_49 ) {
F_46 ( L_52 , V_49 ) ;
F_48 ( V_93 ) ;
return V_49 ;
}
return 0 ;
}
static void T_5 F_71 ( void )
{
struct V_41 * V_92 ;
unsigned long V_62 ;
F_65 ( & V_128 ) ;
F_43 ( & V_99 , V_62 ) ;
V_92 = F_44 ( V_59 ,
F_45 ( & V_99 ) ) ;
F_67 ( V_59 , NULL ) ;
F_47 ( & V_99 , V_62 ) ;
F_51 () ;
if ( V_92 && V_92 -> V_25 )
F_52 ( V_92 -> V_25 , NULL ) ;
F_48 ( V_92 ) ;
F_72 ( & V_132 ) ;
}
