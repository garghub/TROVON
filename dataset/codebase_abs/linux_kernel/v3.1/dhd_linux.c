void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 1000000 / V_8 ;
}
int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == 0 ) {
V_2 -> V_5 = 1 ;
return 0 ;
}
if ( V_2 -> V_6 >= V_2 -> V_4 )
return 1 ;
V_2 -> V_6 += V_2 -> V_5 ;
if ( V_2 -> V_5 < V_2 -> V_7 ) {
F_3 ( V_2 -> V_5 ) ;
V_2 -> V_5 *= 2 ;
if ( V_2 -> V_5 > V_2 -> V_7 )
V_2 -> V_5 = V_2 -> V_7 ;
} else {
T_2 V_9 ;
F_4 ( V_10 , V_11 ) ;
int V_12 ;
F_5 ( & V_9 ) ;
F_6 ( & V_9 , & V_10 ) ;
F_7 ( V_13 ) ;
F_8 ( 1 ) ;
V_12 = F_9 ( V_11 ) ;
F_10 ( & V_9 , & V_10 ) ;
F_7 ( V_14 ) ;
if ( V_12 )
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_19 = 0 ;
while ( V_19 < V_20 ) {
if ( V_16 -> V_21 [ V_19 ] && ( V_16 -> V_21 [ V_19 ] -> V_18 == V_18 ) )
return V_19 ;
V_19 ++ ;
}
return V_22 ;
}
int F_12 ( struct V_15 * V_16 , char * V_23 )
{
int V_19 = V_20 ;
if ( V_23 == NULL || * V_23 == '\0' )
return 0 ;
while ( -- V_19 > 0 )
if ( V_16 -> V_21 [ V_19 ]
&& ! strncmp ( V_16 -> V_21 [ V_19 ] -> V_23 , V_23 , V_24 ) )
break;
F_13 ( ( L_1 , V_25 , V_19 , V_23 ) ) ;
return V_19 ;
}
char * F_14 ( struct V_26 * V_27 , int V_28 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
if ( V_28 < 0 || V_28 >= V_20 ) {
F_15 ( ( L_2 , V_25 , V_28 ) ) ;
return L_3 ;
}
if ( V_16 -> V_21 [ V_28 ] == NULL ) {
F_15 ( ( L_4 , V_25 , V_28 ) ) ;
return L_5 ;
}
if ( V_16 -> V_21 [ V_28 ] -> V_18 )
return V_16 -> V_21 [ V_28 ] -> V_18 -> V_23 ;
return L_6 ;
}
static void F_16 ( struct V_15 * V_16 , int V_28 )
{
struct V_17 * V_30 ;
struct V_31 * V_32 ;
T_3 V_33 , V_34 ;
struct V_35 V_36 ;
char * V_37 , * V_38 ;
T_1 V_39 ;
int V_40 ;
V_30 = V_16 -> V_21 [ V_28 ] -> V_18 ;
V_34 = F_17 ( V_30 ) ;
V_33 = ( V_30 -> V_41 & V_42 ) ? true : false ;
V_39 = sizeof( L_7 ) + sizeof( V_34 ) + ( V_34 * V_43 ) ;
V_38 = V_37 = F_18 ( V_39 , V_44 ) ;
if ( ! V_38 ) {
F_15 ( ( L_8 ,
F_14 ( & V_16 -> V_45 , V_28 ) , V_34 ) ) ;
return;
}
strcpy ( V_38 , L_7 ) ;
V_38 += strlen ( L_7 ) + 1 ;
V_34 = F_19 ( V_34 ) ;
memcpy ( V_38 , & V_34 , sizeof( V_34 ) ) ;
V_38 += sizeof( V_34 ) ;
F_20 (ha, dev) {
if ( ! V_34 )
break;
memcpy ( V_38 , V_32 -> V_46 , V_43 ) ;
V_38 += V_43 ;
V_34 -- ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_47 = V_48 ;
V_36 . V_37 = V_37 ;
V_36 . V_49 = V_39 ;
V_36 . V_50 = true ;
V_40 = F_21 ( & V_16 -> V_45 , V_28 , & V_36 , V_36 . V_37 , V_36 . V_49 ) ;
if ( V_40 < 0 ) {
F_15 ( ( L_9 ,
F_14 ( & V_16 -> V_45 , V_28 ) , V_34 ) ) ;
V_33 = V_34 ? true : V_33 ;
}
F_22 ( V_37 ) ;
V_39 = sizeof( L_10 ) + sizeof( V_33 ) ;
V_37 = F_18 ( V_39 , V_44 ) ;
if ( ! V_37 ) {
F_15 ( ( L_11 ,
F_14 ( & V_16 -> V_45 , V_28 ) ) ) ;
return;
}
V_33 = F_19 ( V_33 ) ;
if ( ! F_23
( L_10 , ( void * ) & V_33 , sizeof( V_33 ) , V_37 , V_39 ) ) {
F_15 ( ( L_12
L_13 ,
F_14 ( & V_16 -> V_45 , V_28 ) ,
( int ) sizeof( V_33 ) , V_39 ) ) ;
F_22 ( V_37 ) ;
return;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_47 = V_48 ;
V_36 . V_37 = V_37 ;
V_36 . V_49 = V_39 ;
V_36 . V_50 = true ;
V_40 = F_21 ( & V_16 -> V_45 , V_28 , & V_36 , V_36 . V_37 , V_36 . V_49 ) ;
if ( V_40 < 0 ) {
F_15 ( ( L_14 ,
F_14 ( & V_16 -> V_45 , V_28 ) ,
F_24 ( V_33 ) ) ) ;
}
F_22 ( V_37 ) ;
V_33 = ( V_30 -> V_41 & V_51 ) ? true : false ;
V_33 = F_19 ( V_33 ) ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_47 = V_52 ;
V_36 . V_37 = & V_33 ;
V_36 . V_49 = sizeof( V_33 ) ;
V_36 . V_50 = true ;
V_40 = F_21 ( & V_16 -> V_45 , V_28 , & V_36 , V_36 . V_37 , V_36 . V_49 ) ;
if ( V_40 < 0 ) {
F_15 ( ( L_15 ,
F_14 ( & V_16 -> V_45 , V_28 ) ,
F_24 ( V_33 ) ) ) ;
}
}
static int F_25 ( struct V_15 * V_16 , int V_28 , T_4 * V_46 )
{
char V_37 [ 32 ] ;
struct V_35 V_36 ;
int V_40 ;
F_13 ( ( L_16 , V_25 ) ) ;
if ( ! F_23
( L_17 , ( char * ) V_46 , V_43 , V_37 , 32 ) ) {
F_15 ( ( L_18 ,
F_14 ( & V_16 -> V_45 , V_28 ) ) ) ;
return - 1 ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_47 = V_48 ;
V_36 . V_37 = V_37 ;
V_36 . V_49 = 32 ;
V_36 . V_50 = true ;
V_40 = F_21 ( & V_16 -> V_45 , V_28 , & V_36 , V_36 . V_37 , V_36 . V_49 ) ;
if ( V_40 < 0 ) {
F_15 ( ( L_19 ,
F_14 ( & V_16 -> V_45 , V_28 ) ) ) ;
} else {
memcpy ( V_16 -> V_21 [ V_28 ] -> V_18 -> V_53 , V_46 , V_43 ) ;
}
return V_40 ;
}
static void F_26 ( struct V_54 * V_55 )
{
struct V_15 * V_16 ;
int V_40 = 0 , V_56 = 0 ;
V_16 = V_55 -> V_29 ;
F_13 ( ( L_20 , V_25 , V_55 -> V_57 , V_55 -> V_58 ) ) ;
switch ( V_55 -> V_58 ) {
case V_59 :
if ( V_55 -> V_18 != NULL ) {
F_15 ( ( L_21
L_22 ,
V_25 , V_55 -> V_18 -> V_23 ) ) ;
F_27 ( V_55 -> V_18 ) ;
F_28 ( V_55 -> V_18 ) ;
F_29 ( V_55 -> V_18 ) ;
}
V_55 -> V_18 = F_30 ( sizeof( V_16 ) ) ;
if ( ! V_55 -> V_18 ) {
F_15 ( ( L_23 , V_25 ) ) ;
V_40 = - V_60 ;
}
if ( V_40 == 0 ) {
strcpy ( V_55 -> V_18 -> V_23 , V_55 -> V_23 ) ;
memcpy ( F_31 ( V_55 -> V_18 ) , & V_16 , sizeof( V_16 ) ) ;
V_56 = F_32 ( & V_16 -> V_45 , V_55 -> V_57 ) ;
if ( V_56 != 0 ) {
F_15 ( ( L_24
L_25 ,
V_25 , V_56 ) ) ;
V_40 = - V_61 ;
} else {
#ifdef F_33
extern struct V_62 V_63 ;
V_64 = V_55 -> V_18 ;
F_34 ( & V_63 ) ;
#endif
F_13 ( ( L_26
L_27 ,
V_11 -> V_65 , V_55 -> V_18 -> V_23 ) ) ;
V_55 -> V_58 = 0 ;
}
}
break;
case V_66 :
if ( V_55 -> V_18 != NULL ) {
F_13 ( ( L_28 ,
V_25 ) ) ;
F_27 ( V_55 -> V_18 ) ;
F_28 ( V_55 -> V_18 ) ;
V_40 = V_67 ;
}
break;
default:
F_15 ( ( L_29 , V_25 , V_55 -> V_58 ) ) ;
break;
}
if ( V_40 < 0 ) {
if ( V_55 -> V_18 )
F_29 ( V_55 -> V_18 ) ;
V_16 -> V_21 [ V_55 -> V_57 ] = NULL ;
F_22 ( V_55 ) ;
#ifdef F_33
if ( V_55 -> V_18 == V_64 )
V_64 = NULL ;
#endif
}
}
static int F_35 ( void * V_68 )
{
struct V_15 * V_16 = (struct V_15 * ) V_68 ;
int V_19 ;
#ifdef F_33
bool V_69 = false ;
#endif
F_36 ( V_70 ) ;
while ( F_37 ( & V_16 -> V_71 ) == 0 ) {
if ( F_38 () )
break;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
struct V_54 * V_72 = V_16 -> V_21 [ V_19 ] ;
if ( V_72 ) {
#ifdef F_33
V_69 = ( V_64 != NULL ) ;
#endif
if ( V_72 -> V_58 )
F_26 ( V_72 ) ;
#ifdef F_33
if ( V_16 -> V_21 [ V_19 ] == NULL ) {
F_13 ( ( L_30
L_31 , V_25 ,
V_19 ) ) ;
continue;
}
if ( V_69 && V_16 -> V_73 ) {
F_13 ( ( L_32
L_33
L_34 ,
V_72 -> V_18 -> V_23 ) ) ;
V_16 -> V_73 = false ;
continue;
}
if ( V_69 && V_16 -> V_74 ) {
F_13 ( ( L_35
L_36
L_37 ,
V_72 -> V_18 -> V_23 ) ) ;
V_16 -> V_74 = false ;
continue;
}
#endif
if ( V_16 -> V_74 ) {
V_16 -> V_74 = false ;
F_16 ( V_16 , V_19 ) ;
}
if ( V_16 -> V_73 ) {
V_16 -> V_73 = false ;
F_25 ( V_16 , V_19 ,
V_16 -> V_75 ) ;
}
}
}
}
return 0 ;
}
static int F_39 ( struct V_17 * V_30 , void * V_46 )
{
int V_40 = 0 ;
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_30 ) ;
struct V_76 * V_77 = (struct V_76 * ) V_46 ;
int V_28 ;
V_28 = F_11 ( V_16 , V_30 ) ;
if ( V_28 == V_22 )
return - 1 ;
memcpy ( & V_16 -> V_75 , V_77 -> V_78 , V_43 ) ;
V_16 -> V_73 = true ;
F_34 ( & V_16 -> V_71 ) ;
return V_40 ;
}
static void F_40 ( struct V_17 * V_30 )
{
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_30 ) ;
int V_28 ;
V_28 = F_11 ( V_16 , V_30 ) ;
if ( V_28 == V_22 )
return;
V_16 -> V_74 = true ;
F_34 ( & V_16 -> V_71 ) ;
}
int F_41 ( struct V_26 * V_27 , int V_28 , struct V_79 * V_80 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
if ( ! V_27 -> F_34 || ( V_27 -> V_81 == V_82 ) )
return - V_83 ;
if ( V_80 -> V_49 >= V_43 ) {
T_4 * V_84 = ( T_4 * ) ( V_80 -> V_68 ) ;
struct V_85 * V_86 = (struct V_85 * ) V_84 ;
if ( F_42 ( V_86 -> V_87 ) )
V_27 -> V_88 ++ ;
if ( F_43 ( V_86 -> V_89 ) == V_90 )
F_44 ( & V_16 -> V_91 ) ;
}
F_45 ( V_27 , V_28 , V_80 ) ;
return F_46 ( V_27 -> V_92 , V_80 ) ;
}
static int F_47 ( struct V_79 * V_93 , struct V_17 * V_18 )
{
int V_40 ;
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_18 ) ;
int V_28 ;
F_13 ( ( L_38 , V_25 ) ) ;
if ( ! V_16 -> V_45 . F_34 || ( V_16 -> V_45 . V_81 == V_82 ) ) {
F_15 ( ( L_39 ,
V_25 , V_16 -> V_45 . F_34 ,
V_16 -> V_45 . V_81 ) ) ;
F_27 ( V_18 ) ;
return - V_83 ;
}
V_28 = F_11 ( V_16 , V_18 ) ;
if ( V_28 == V_22 ) {
F_15 ( ( L_40 , V_25 , V_28 ) ) ;
F_27 ( V_18 ) ;
return - V_83 ;
}
if ( F_48 ( V_93 ) < V_16 -> V_45 . V_94 ) {
struct V_79 * V_95 ;
F_49 ( ( L_41 ,
F_14 ( & V_16 -> V_45 , V_28 ) ) ) ;
V_16 -> V_45 . V_96 ++ ;
V_95 = F_50 ( V_93 , V_16 -> V_45 . V_94 ) ;
F_51 ( V_93 ) ;
V_93 = V_95 ;
if ( V_93 == NULL ) {
F_15 ( ( L_42 ,
F_14 ( & V_16 -> V_45 , V_28 ) ) ) ;
V_40 = - V_60 ;
goto V_97;
}
}
V_40 = F_41 ( & V_16 -> V_45 , V_28 , V_93 ) ;
V_97:
if ( V_40 )
V_16 -> V_45 . V_98 . V_99 ++ ;
else
V_16 -> V_45 . V_100 ++ ;
return 0 ;
}
void F_52 ( struct V_26 * V_27 , int V_28 , bool V_58 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 = V_27 -> V_29 ;
F_13 ( ( L_38 , V_25 ) ) ;
V_27 -> V_101 = V_58 ;
V_18 = V_16 -> V_21 [ V_28 ] -> V_18 ;
if ( V_58 == V_102 )
F_27 ( V_18 ) ;
else
F_53 ( V_18 ) ;
}
void F_54 ( struct V_26 * V_27 , int V_28 , struct V_79 * V_93 ,
int V_103 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
unsigned char * V_104 ;
T_1 V_49 ;
void * V_68 ;
struct V_79 * V_105 , * V_106 ;
int V_19 ;
struct V_54 * V_55 ;
struct V_107 V_108 ;
F_13 ( ( L_38 , V_25 ) ) ;
V_106 = V_93 ;
for ( V_19 = 0 ; V_93 && V_19 < V_103 ; V_19 ++ , V_93 = V_105 ) {
V_105 = V_93 -> V_109 ;
V_93 -> V_109 = NULL ;
V_104 = V_93 -> V_68 ;
V_49 = V_93 -> V_49 ;
V_55 = V_16 -> V_21 [ V_28 ] ;
if ( V_55 == NULL )
V_55 = V_16 -> V_21 [ 0 ] ;
V_93 -> V_30 = V_55 -> V_18 ;
V_93 -> V_110 = F_55 ( V_93 , V_93 -> V_30 ) ;
if ( V_93 -> V_111 == V_112 )
V_16 -> V_45 . V_113 ++ ;
V_93 -> V_68 = V_104 ;
V_93 -> V_49 = V_49 ;
F_56 ( V_93 , V_114 ) ;
if ( F_43 ( V_93 -> V_110 ) == V_115 )
F_57 ( V_16 , & V_28 ,
F_58 ( V_93 ) ,
& V_108 , & V_68 ) ;
if ( V_16 -> V_21 [ V_28 ] &&
! V_16 -> V_21 [ V_28 ] -> V_58 )
V_55 = V_16 -> V_21 [ V_28 ] ;
if ( V_55 -> V_18 )
V_55 -> V_18 -> V_116 = V_117 ;
V_27 -> V_98 . V_118 += V_93 -> V_49 ;
V_27 -> V_119 ++ ;
if ( F_59 () ) {
F_60 ( V_93 ) ;
} else {
F_61 ( V_93 ) ;
}
}
}
void F_62 ( struct V_26 * V_27 , struct V_79 * V_120 , bool V_121 )
{
T_1 V_28 ;
struct V_15 * V_16 = V_27 -> V_29 ;
struct V_85 * V_86 ;
T_5 type ;
F_63 ( V_27 , & V_28 , V_120 ) ;
V_86 = (struct V_85 * ) ( V_120 -> V_68 ) ;
type = F_43 ( V_86 -> V_89 ) ;
if ( type == V_90 )
F_64 ( & V_16 -> V_91 ) ;
}
static struct V_122 * F_65 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_18 ) ;
struct V_54 * V_55 ;
int V_28 ;
F_13 ( ( L_38 , V_25 ) ) ;
V_28 = F_11 ( V_16 , V_18 ) ;
if ( V_28 == V_22 )
return NULL ;
V_55 = V_16 -> V_21 [ V_28 ] ;
if ( V_16 -> V_45 . F_34 ) {
F_66 ( & V_16 -> V_45 ) ;
}
V_55 -> V_123 . V_119 = V_16 -> V_45 . V_98 . V_119 ;
V_55 -> V_123 . V_100 = V_16 -> V_45 . V_98 . V_100 ;
V_55 -> V_123 . V_118 = V_16 -> V_45 . V_98 . V_118 ;
V_55 -> V_123 . V_124 = V_16 -> V_45 . V_98 . V_124 ;
V_55 -> V_123 . V_125 = V_16 -> V_45 . V_98 . V_125 ;
V_55 -> V_123 . V_126 = V_16 -> V_45 . V_98 . V_126 ;
V_55 -> V_123 . V_127 = V_16 -> V_45 . V_98 . V_127 ;
V_55 -> V_123 . V_99 = V_16 -> V_45 . V_98 . V_99 ;
V_55 -> V_123 . V_128 = V_16 -> V_45 . V_98 . V_128 ;
return & V_55 -> V_123 ;
}
static int F_67 ( struct V_15 * V_16 , int V_28 , T_3 * V_129 )
{
struct V_35 V_36 ;
char V_37 [ 32 ] ;
int V_40 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_47 = V_130 ;
V_36 . V_37 = V_37 ;
V_36 . V_49 = ( T_1 ) sizeof( V_37 ) ;
V_36 . V_50 = false ;
strcpy ( V_37 , L_43 ) ;
V_40 = F_21 ( & V_16 -> V_45 , V_28 , & V_36 , V_36 . V_37 , V_36 . V_49 ) ;
if ( V_40 < 0 ) {
if ( V_40 == - V_131 ) {
F_15 ( ( L_44 ,
F_14 ( & V_16 -> V_45 , V_28 ) ) ) ;
return - V_61 ;
}
F_49 ( ( L_45 ,
F_14 ( & V_16 -> V_45 , V_28 ) , V_40 ) ) ;
return V_40 ;
}
memcpy ( V_129 , V_37 , sizeof( T_3 ) ) ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 , int V_28 , T_3 V_129 )
{
struct V_35 V_36 ;
char V_37 [ 32 ] ;
int V_132 , V_40 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_47 = V_48 ;
V_36 . V_37 = V_37 ;
V_36 . V_49 = ( T_1 ) sizeof( V_37 ) ;
V_36 . V_50 = true ;
strcpy ( V_37 , L_43 ) ;
memcpy ( & V_37 [ sizeof( L_43 ) ] , & V_129 , sizeof( T_3 ) ) ;
V_40 = F_21 ( & V_16 -> V_45 , V_28 , & V_36 , V_36 . V_37 , V_36 . V_49 ) ;
if ( V_40 < 0 ) {
F_15 ( ( L_46 ,
F_14 ( & V_16 -> V_45 , V_28 ) , V_40 ) ) ;
return V_40 ;
}
V_132 = ( V_129 != 0 ) ;
strcpy ( V_37 , L_47 ) ;
memcpy ( & V_37 [ sizeof( L_47 ) ] , & V_132 , sizeof( T_3 ) ) ;
V_40 = F_21 ( & V_16 -> V_45 , V_28 , & V_36 , V_36 . V_37 , V_36 . V_49 ) ;
if ( V_40 < 0 ) {
F_15 ( ( L_48 ,
F_14 ( & V_16 -> V_45 , V_28 ) , V_40 ) ) ;
return V_40 ;
}
return 0 ;
}
static void F_69 ( struct V_17 * V_18 ,
struct V_133 * V_29 )
{
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_18 ) ;
sprintf ( V_29 -> V_134 , V_135 ) ;
sprintf ( V_29 -> V_136 , L_49 , V_16 -> V_45 . V_137 ) ;
sprintf ( V_29 -> V_138 , L_50 , V_139 ) ;
sprintf ( V_29 -> V_140 , L_50 ,
F_70 ( & F_71 () -> V_30 ) ) ;
}
static int F_72 ( struct V_15 * V_16 , void * V_141 )
{
struct V_133 V_29 ;
char V_142 [ sizeof( V_29 . V_134 ) ] ;
T_3 V_47 ;
struct V_143 V_144 ;
T_3 V_145 , V_146 ;
int V_40 ;
F_13 ( ( L_38 , V_25 ) ) ;
if ( F_73 ( & V_47 , V_141 , sizeof( T_3 ) ) )
return - V_147 ;
switch ( V_47 ) {
case V_148 :
if ( F_73 ( & V_29 , V_141 , sizeof( V_29 ) ) )
return - V_147 ;
strncpy ( V_142 , V_29 . V_134 , sizeof( V_29 . V_134 ) ) ;
V_142 [ sizeof( V_29 . V_134 ) - 1 ] = '\0' ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_47 = V_47 ;
if ( strcmp ( V_142 , L_51 ) == 0 ) {
sprintf ( V_29 . V_134 , L_52 ) ;
strcpy ( V_29 . V_136 , V_149 ) ;
}
else if ( ! V_16 -> V_45 . F_34 ) {
F_15 ( ( L_53 , V_25 ) ) ;
return - V_83 ;
}
else if ( V_16 -> V_45 . V_150 )
sprintf ( V_29 . V_134 , L_54 ) ;
else
sprintf ( V_29 . V_134 , L_55 ) ;
sprintf ( V_29 . V_136 , L_49 , V_16 -> V_45 . V_137 ) ;
if ( F_74 ( V_141 , & V_29 , sizeof( V_29 ) ) )
return - V_147 ;
F_75 ( ( L_56 , V_25 ,
( int ) sizeof( V_142 ) , V_142 , V_29 . V_134 ) ) ;
break;
case V_151 :
case V_152 :
V_40 = F_67 ( V_16 , 0 , & V_145 ) ;
if ( V_40 < 0 )
return V_40 ;
V_146 =
( V_47 == V_152 ) ? V_153 : V_154 ;
V_144 . V_47 = V_47 ;
V_144 . V_68 = ( V_145 & V_146 ) ? 1 : 0 ;
if ( F_74 ( V_141 , & V_144 , sizeof( V_144 ) ) )
return - V_147 ;
break;
case V_155 :
case V_156 :
if ( F_73 ( & V_144 , V_141 , sizeof( V_144 ) ) )
return - V_147 ;
V_40 = F_67 ( V_16 , 0 , & V_145 ) ;
if ( V_40 < 0 )
return V_40 ;
V_146 =
( V_47 == V_156 ) ? V_153 : V_154 ;
if ( V_144 . V_68 != 0 )
V_145 |= V_146 ;
else
V_145 &= ~ V_146 ;
V_40 = F_68 ( V_16 , 0 , V_145 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_47 == V_156 ) {
if ( V_144 . V_68 )
V_16 -> V_21 [ 0 ] -> V_18 -> V_157 |=
V_158 ;
else
V_16 -> V_21 [ 0 ] -> V_18 -> V_157 &=
~ V_158 ;
}
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_76 ( struct V_17 * V_18 , struct V_159 * V_160 ,
int V_47 )
{
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_18 ) ;
struct V_161 V_36 ;
int V_162 = 0 ;
int V_39 = 0 ;
void * V_37 = NULL ;
T_1 V_134 = 0 ;
int V_28 ;
bool V_163 ;
V_28 = F_11 ( V_16 , V_18 ) ;
F_13 ( ( L_57 , V_25 , V_28 , V_47 ) ) ;
if ( V_28 == V_22 )
return - 1 ;
if ( V_47 == V_164 )
return F_72 ( V_16 , ( void * ) V_160 -> V_165 ) ;
if ( V_47 != V_166 )
return - V_61 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
if ( F_73 ( & V_36 , V_160 -> V_165 , sizeof( struct V_35 ) ) ) {
V_162 = - V_167 ;
goto V_97;
}
if ( V_36 . V_37 ) {
V_39 = F_77 ( int , V_36 . V_49 , V_168 ) ;
{
V_37 = F_18 ( V_39 , V_44 ) ;
if ( ! V_37 ) {
V_162 = - V_60 ;
goto V_97;
}
if ( F_73 ( V_37 , V_36 . V_37 , V_39 ) ) {
V_162 = - V_167 ;
goto V_97;
}
}
}
if ( ( F_73 ( & V_134 , ( char * ) V_160 -> V_165 +
sizeof( struct V_35 ) , sizeof( T_1 ) ) != 0 ) ) {
V_162 = - V_167 ;
goto V_97;
}
if ( ! F_78 ( V_169 ) ) {
V_162 = - V_170 ;
goto V_97;
}
if ( V_134 == V_171 ) {
V_162 = V_161 ( ( void * ) & V_16 -> V_45 , & V_36 , V_37 , V_39 ) ;
if ( V_162 )
V_16 -> V_45 . V_162 = V_162 ;
goto V_97;
}
if ( ( V_16 -> V_45 . V_81 != V_172 ) ) {
F_15 ( ( L_58 , V_25 ) ) ;
V_162 = - V_131 ;
goto V_97;
}
if ( ! V_16 -> V_45 . V_150 ) {
V_162 = - V_131 ;
goto V_97;
}
V_163 = ( ( V_36 . V_47 == V_173 ) ||
( ( V_36 . V_47 == V_48 ) &&
! ( strncmp ( L_59 , V_36 . V_37 , 9 ) ) ) ||
( ( V_36 . V_47 == V_48 ) &&
! ( strncmp ( L_60 , V_36 . V_37 , 15 ) ) ) ) ;
if ( V_163 )
F_79 ( V_18 ) ;
V_162 =
F_21 ( & V_16 -> V_45 , V_28 , (struct V_35 * ) & V_36 ,
V_37 , V_39 ) ;
V_97:
if ( ! V_162 && V_37 && V_36 . V_37 ) {
if ( F_74 ( V_36 . V_37 , V_37 , V_39 ) )
V_162 = - V_147 ;
}
F_22 ( V_37 ) ;
if ( V_162 > 0 )
V_162 = 0 ;
return V_162 ;
}
static int F_80 ( struct V_17 * V_18 )
{
#if ! F_81 ( V_174 )
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_18 ) ;
F_13 ( ( L_38 , V_25 ) ) ;
F_82 () ;
if ( V_16 -> V_45 . F_34 == 0 )
return 0 ;
V_16 -> V_45 . F_34 = 0 ;
F_27 ( V_18 ) ;
#else
F_15 ( ( L_61 ,
V_25 ) ) ;
#endif
return 0 ;
}
static int F_83 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_18 ) ;
T_3 V_129 ;
int V_28 = F_11 ( V_16 , V_18 ) ;
T_6 V_40 = 0 ;
F_13 ( ( L_62 , V_25 , V_28 ) ) ;
if ( V_28 == 0 ) {
V_40 = F_84 ( & V_16 -> V_45 ) ;
if ( V_40 != 0 ) {
F_15 ( ( L_63 ,
V_25 , V_40 ) ) ;
return - 1 ;
}
F_85 ( & V_16 -> V_91 , 0 ) ;
memcpy ( V_18 -> V_53 , V_16 -> V_45 . V_175 , V_43 ) ;
if ( F_67 ( V_16 , V_28 , & V_129 ) >= 0
&& ( V_129 & V_153 ) != 0 )
V_16 -> V_21 [ V_28 ] -> V_18 -> V_157 |=
V_158 ;
else
V_16 -> V_21 [ V_28 ] -> V_18 -> V_157 &=
~ V_158 ;
}
F_86 ( V_18 ) ;
V_16 -> V_45 . F_34 = 1 ;
if ( F_87 ( F_88 () ) ) {
F_15 ( ( L_64 ,
V_25 ) ) ;
return - 1 ;
}
return V_40 ;
}
int
F_89 ( struct V_15 * V_16 , int V_28 , void * V_176 , char * V_23 ,
T_4 * V_177 , T_3 V_41 , T_4 V_178 )
{
struct V_54 * V_55 ;
F_13 ( ( L_65 , V_25 , V_28 , V_176 ) ) ;
V_55 = V_16 -> V_21 [ V_28 ] ;
if ( ! V_55 ) {
V_55 = F_18 ( sizeof( struct V_54 ) , V_44 ) ;
if ( ! V_55 ) {
F_15 ( ( L_66 , V_25 ) ) ;
return - V_60 ;
}
}
memset ( V_55 , 0 , sizeof( struct V_54 ) ) ;
V_55 -> V_29 = V_16 ;
V_16 -> V_21 [ V_28 ] = V_55 ;
F_90 ( V_55 -> V_23 , V_23 , V_24 ) ;
if ( V_177 != NULL )
memcpy ( & V_55 -> V_177 , V_177 , V_43 ) ;
if ( V_176 == NULL ) {
V_55 -> V_58 = V_59 ;
V_55 -> V_57 = V_28 ;
F_34 ( & V_16 -> V_71 ) ;
} else
V_55 -> V_18 = (struct V_17 * ) V_176 ;
return 0 ;
}
void F_91 ( struct V_15 * V_16 , int V_28 )
{
struct V_54 * V_55 ;
F_13 ( ( L_67 , V_25 , V_28 ) ) ;
V_55 = V_16 -> V_21 [ V_28 ] ;
if ( ! V_55 ) {
F_15 ( ( L_68 , V_25 ) ) ;
return;
}
V_55 -> V_58 = V_66 ;
V_55 -> V_57 = V_28 ;
F_34 ( & V_16 -> V_71 ) ;
}
struct V_26 * F_92 ( struct V_179 * V_92 , T_1 V_180 )
{
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 ;
F_13 ( ( L_38 , V_25 ) ) ;
V_18 = F_30 ( sizeof( V_16 ) ) ;
if ( ! V_18 ) {
F_15 ( ( L_23 , V_25 ) ) ;
goto V_181;
}
V_16 = F_93 ( sizeof( struct V_15 ) , V_44 ) ;
if ( ! V_16 ) {
F_15 ( ( L_69 , V_25 ) ) ;
goto V_181;
}
memcpy ( F_31 ( V_18 ) , & V_16 , sizeof( V_16 ) ) ;
if ( V_182 [ 0 ] ) {
int V_49 ;
char V_183 ;
strncpy ( V_18 -> V_23 , V_182 , V_24 ) ;
V_18 -> V_23 [ V_24 - 1 ] = 0 ;
V_49 = strlen ( V_18 -> V_23 ) ;
V_183 = V_18 -> V_23 [ V_49 - 1 ] ;
if ( ( V_183 > '9' || V_183 < '0' ) && ( V_49 < V_24 - 2 ) )
strcat ( V_18 -> V_23 , L_70 ) ;
}
if ( F_89 ( V_16 , 0 , ( void * ) V_18 , V_18 -> V_23 , NULL , 0 , 0 ) ==
V_22 )
goto V_181;
V_18 -> V_184 = NULL ;
F_94 ( & V_16 -> V_185 , 1 ) ;
F_5 ( & V_16 -> V_186 ) ;
V_16 -> V_45 . V_29 = V_16 ;
V_16 -> V_45 . V_92 = V_92 ;
V_16 -> V_45 . V_94 = V_180 ;
if ( F_95 ( & V_16 -> V_45 ) != 0 ) {
F_15 ( ( L_71 ) ) ;
goto V_181;
}
if ( F_87 ( F_96 ( V_18 , & V_16 -> V_45 ) ) ) {
F_15 ( ( L_72 ) ) ;
goto V_181;
}
if ( V_187 ) {
F_94 ( & V_16 -> V_71 , 0 ) ;
V_16 -> V_188 = F_97 ( F_35 , V_16 ,
L_73 ) ;
if ( F_98 ( V_16 -> V_188 ) ) {
F_99 ( V_189
L_74 ) ;
V_16 -> V_188 = NULL ;
}
} else
V_16 -> V_188 = NULL ;
memcpy ( F_31 ( V_18 ) , & V_16 , sizeof( V_16 ) ) ;
#if F_81 ( V_190 )
F_85 ( & V_191 , false ) ;
#endif
return & V_16 -> V_45 ;
V_181:
if ( V_18 )
F_29 ( V_18 ) ;
if ( V_16 )
F_100 ( & V_16 -> V_45 ) ;
return NULL ;
}
int F_84 ( struct V_26 * V_27 )
{
int V_40 = - 1 ;
struct V_15 * V_16 = V_27 -> V_29 ;
char V_192 [ V_193 + 12 ] ;
F_13 ( ( L_75 , V_25 ) ) ;
V_40 = F_101 ( & V_16 -> V_45 , true ) ;
if ( V_40 != 0 ) {
F_15 ( ( L_76 , V_25 ,
V_40 ) ) ;
return V_40 ;
}
if ( V_16 -> V_45 . V_81 != V_172 ) {
F_15 ( ( L_77 , V_25 ) ) ;
return - V_83 ;
}
F_23 ( L_78 , V_27 -> V_194 , V_193 ,
V_192 , sizeof( V_192 ) ) ;
F_102 ( V_27 , 0 , V_130 , V_192 ,
sizeof( V_192 ) ) ;
memcpy ( V_27 -> V_194 , V_192 , V_193 ) ;
F_103 ( V_27 -> V_194 , V_195 ) ;
F_103 ( V_27 -> V_194 , V_196 ) ;
F_103 ( V_27 -> V_194 , V_197 ) ;
F_103 ( V_27 -> V_194 , V_198 ) ;
F_103 ( V_27 -> V_194 , V_199 ) ;
F_103 ( V_27 -> V_194 , V_200 ) ;
F_103 ( V_27 -> V_194 , V_201 ) ;
F_103 ( V_27 -> V_194 , V_202 ) ;
F_103 ( V_27 -> V_194 , V_203 ) ;
F_103 ( V_27 -> V_194 , V_204 ) ;
F_103 ( V_27 -> V_194 , V_205 ) ;
F_103 ( V_27 -> V_194 , V_206 ) ;
F_103 ( V_27 -> V_194 , V_207 ) ;
F_103 ( V_27 -> V_194 , V_208 ) ;
F_103 ( V_27 -> V_194 , V_209 ) ;
F_103 ( V_27 -> V_194 , V_210 ) ;
F_103 ( V_27 -> V_194 , V_211 ) ;
F_103 ( V_27 -> V_194 , V_212 ) ;
V_27 -> V_213 = 1 ;
V_27 -> V_214 [ 0 ] = L_79 ;
V_40 = F_104 ( & V_16 -> V_45 ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
int F_32 ( struct V_26 * V_27 , int V_28 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
struct V_17 * V_18 ;
T_4 V_215 [ V_43 ] = {
0x00 , 0x90 , 0x4c , 0x11 , 0x22 , 0x33 } ;
F_13 ( ( L_62 , V_25 , V_28 ) ) ;
V_18 = V_16 -> V_21 [ V_28 ] -> V_18 ;
V_18 -> V_184 = & V_216 ;
if ( V_28 != 0 ) {
memcpy ( V_215 , V_16 -> V_45 . V_175 , V_43 ) ;
}
if ( V_28 == 1 ) {
F_13 ( ( L_80 , V_25 ) ) ;
V_215 [ 0 ] |= 0X02 ;
}
V_18 -> V_217 = V_114 + V_16 -> V_45 . V_94 ;
V_18 -> V_218 = & V_219 ;
V_16 -> V_45 . V_220 = V_18 -> V_221 + V_18 -> V_217 +
V_16 -> V_45 . V_94 ;
memcpy ( V_18 -> V_53 , V_215 , V_43 ) ;
if ( F_105 ( V_18 ) != 0 ) {
F_15 ( ( L_81 ,
V_25 ) ) ;
goto V_181;
}
F_49 ( ( L_82 , V_18 -> V_23 ) ) ;
return 0 ;
V_181:
V_18 -> V_184 = NULL ;
return - V_222 ;
}
static void F_106 ( struct V_26 * V_27 )
{
struct V_15 * V_16 ;
F_13 ( ( L_38 , V_25 ) ) ;
if ( V_27 ) {
V_16 = V_27 -> V_29 ;
if ( V_16 ) {
F_107 ( & V_16 -> V_45 ) ;
F_108 ( V_16 -> V_45 . V_92 , true ) ;
}
}
}
void F_100 ( struct V_26 * V_27 )
{
struct V_15 * V_16 ;
F_13 ( ( L_38 , V_25 ) ) ;
if ( V_27 ) {
V_16 = V_27 -> V_29 ;
if ( V_16 ) {
struct V_54 * V_55 ;
int V_19 ;
for ( V_19 = 1 ; V_19 < V_20 ; V_19 ++ )
if ( V_16 -> V_21 [ V_19 ] )
F_91 ( V_16 , V_19 ) ;
V_55 = V_16 -> V_21 [ 0 ] ;
if ( V_55 -> V_18 -> V_184 == & V_216 ) {
F_80 ( V_55 -> V_18 ) ;
F_28 ( V_55 -> V_18 ) ;
}
if ( V_16 -> V_188 ) {
F_109 ( V_70 , V_16 -> V_188 , 1 ) ;
F_110 ( V_16 -> V_188 ) ;
V_16 -> V_188 = NULL ;
}
F_106 ( V_27 ) ;
if ( V_27 -> V_223 )
F_111 ( V_27 ) ;
F_112 () ;
F_29 ( V_55 -> V_18 ) ;
F_22 ( V_55 ) ;
F_22 ( V_16 ) ;
}
}
}
static void T_7 F_113 ( void )
{
F_13 ( ( L_38 , V_25 ) ) ;
F_114 () ;
}
static int T_8 F_115 ( void )
{
int error ;
F_13 ( ( L_38 , V_25 ) ) ;
error = F_116 () ;
if ( error ) {
F_15 ( ( L_83 , V_25 ) ) ;
goto V_224;
}
return 0 ;
V_224:
return - V_167 ;
}
int F_117 ( struct V_26 * V_27 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
if ( V_16 ) {
F_118 ( & V_16 -> V_185 ) ;
return 1 ;
}
return 0 ;
}
int F_119 ( struct V_26 * V_27 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
if ( V_16 ) {
F_34 ( & V_16 -> V_185 ) ;
return 1 ;
}
return 0 ;
}
unsigned int F_120 ( void )
{
return ( unsigned int ) V_225 ;
}
void F_121 ( unsigned int V_226 )
{
V_225 = ( int ) V_226 ;
}
int F_122 ( struct V_26 * V_27 , T_1 * V_227 ,
bool * V_12 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
F_4 ( V_10 , V_11 ) ;
int V_228 = V_225 ;
V_228 = V_228 * V_8 / 1000 ;
F_6 ( & V_16 -> V_186 , & V_10 ) ;
F_7 ( V_13 ) ;
while ( ! ( * V_227 ) && ( ! F_9 ( V_11 ) && V_228 ) )
V_228 = F_8 ( V_228 ) ;
if ( F_9 ( V_11 ) )
* V_12 = true ;
F_7 ( V_14 ) ;
F_10 ( & V_16 -> V_186 , & V_10 ) ;
return V_228 ;
}
int F_123 ( struct V_26 * V_27 )
{
struct V_15 * V_16 = V_27 -> V_29 ;
if ( F_124 ( & V_16 -> V_186 ) )
F_125 ( & V_16 -> V_186 ) ;
return 0 ;
}
static int F_57 ( struct V_15 * V_16 , int * V_28 , void * V_84 ,
struct V_107 * V_108 , void * * V_68 )
{
int V_162 = 0 ;
V_162 = F_126 ( V_16 , V_28 , V_84 , V_108 , V_68 ) ;
if ( V_162 != 0 )
return V_162 ;
if ( V_16 -> V_21 [ * V_28 ] -> V_18 )
F_127 ( V_16 -> V_21 [ * V_28 ] -> V_18 ,
V_108 , * V_68 ) ;
return V_162 ;
}
int F_128 ( struct V_17 * V_30 , T_4 V_229 )
{
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_30 ) ;
F_129 ( & V_16 -> V_45 , V_229 ) ;
return 1 ;
}
static int F_130 ( struct V_15 * V_16 )
{
return F_131 ( & V_16 -> V_91 ) ;
}
int F_79 ( struct V_17 * V_30 )
{
struct V_15 * V_16 = * (struct V_15 * * ) F_31 ( V_30 ) ;
int V_228 = 10 * V_8 / 1000 ;
int V_230 = V_231 ;
int V_232 = F_130 ( V_16 ) ;
while ( V_230 && V_232 ) {
if ( V_232 ) {
F_7 ( V_13 ) ;
F_8 ( V_228 ) ;
F_7 ( V_14 ) ;
V_230 -- ;
}
V_232 = F_130 ( V_16 ) ;
}
return V_232 ;
}
int F_132 ( struct V_26 * V_27 , T_4 * V_37 , int V_233 )
{
int V_40 = 0 ;
struct V_234 * V_235 ;
T_9 V_236 ;
T_10 V_237 = 0 ;
V_236 = F_133 () ;
F_134 ( V_238 ) ;
V_235 = F_135 ( L_84 , V_239 | V_240 , 0640 ) ;
if ( ! V_235 ) {
F_15 ( ( L_85 , V_25 ) ) ;
V_40 = - 1 ;
goto exit;
}
V_235 -> V_241 -> V_242 ( V_235 , V_37 , V_233 , & V_237 ) ;
exit:
F_22 ( V_37 ) ;
if ( V_235 )
F_136 ( V_235 , V_11 -> V_243 ) ;
F_134 ( V_236 ) ;
return V_40 ;
}
