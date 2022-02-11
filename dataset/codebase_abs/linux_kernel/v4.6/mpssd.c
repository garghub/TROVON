static int
F_1 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 ;
char * V_5 [ 7 ] ;
char V_6 [ V_7 ] ;
int V_8 = 0 ;
V_4 = F_2 () ;
if ( V_4 == 0 ) {
V_5 [ 0 ] = L_1 ;
V_5 [ 1 ] = L_2 ;
V_5 [ 2 ] = L_3 ;
V_5 [ 3 ] = V_3 ;
V_5 [ 4 ] = L_4 ;
V_5 [ 5 ] = NULL ;
F_3 ( L_5 , V_3 ) ;
V_8 = F_4 ( L_1 , V_5 ) ;
if ( V_8 < 0 ) {
F_3 ( L_6 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return V_8 ;
}
}
if ( V_4 < 0 ) {
F_3 ( L_7 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return V_8 ;
}
V_8 = F_5 ( V_4 , NULL , 0 ) ;
if ( V_8 < 0 ) {
F_3 ( L_8 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return V_8 ;
}
snprintf ( V_6 , V_7 , L_9 , V_2 -> V_11 + 1 ) ;
V_4 = F_2 () ;
if ( V_4 == 0 ) {
V_5 [ 0 ] = L_1 ;
V_5 [ 1 ] = L_10 ;
V_5 [ 2 ] = L_11 ;
V_5 [ 3 ] = V_6 ;
V_5 [ 4 ] = L_12 ;
V_5 [ 5 ] = V_3 ;
V_5 [ 6 ] = NULL ;
F_3 ( L_13 , V_3 , V_6 ) ;
V_8 = F_4 ( L_1 , V_5 ) ;
if ( V_8 < 0 ) {
F_3 ( L_6 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return V_8 ;
}
}
if ( V_4 < 0 ) {
F_3 ( L_7 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return V_8 ;
}
V_8 = F_5 ( V_4 , NULL , 0 ) ;
if ( V_8 < 0 ) {
F_3 ( L_8 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return V_8 ;
}
F_3 ( L_14 ,
V_2 -> V_9 , V_12 , __LINE__ ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , char * V_3 )
{
struct V_13 V_14 ;
int V_15 , V_16 ;
#if V_17
unsigned V_18 ;
#endif
V_15 = F_7 ( L_15 , V_19 ) ;
if ( V_15 < 0 ) {
F_3 ( L_16 , strerror ( V_10 ) ) ;
goto V_20;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_21 = V_22 | V_23 | V_24 ;
if ( * V_3 )
strncpy ( V_14 . V_25 , V_3 , V_7 ) ;
V_16 = F_8 ( V_15 , V_26 , ( void * ) & V_14 ) ;
if ( V_16 < 0 ) {
F_3 ( L_17 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
F_9 ( V_15 ) ;
return V_16 ;
}
#if V_17
V_18 = V_27 | V_28 | V_29 | V_30 ;
V_16 = F_8 ( V_15 , V_31 , V_18 ) ;
if ( V_16 < 0 ) {
F_3 ( L_18 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
F_9 ( V_15 ) ;
return V_16 ;
}
#endif
strcpy ( V_3 , V_14 . V_25 ) ;
F_3 ( L_19 , V_3 ) ;
V_20:
return V_15 ;
}
static void F_10 ( struct V_1 * V_2 , int type , void * V_32 )
{
switch ( type ) {
case V_33 :
V_2 -> V_34 . V_35 = V_32 ;
return;
case V_36 :
V_2 -> V_37 . V_38 = V_32 ;
return;
case V_39 :
V_2 -> V_40 . V_41 = V_32 ;
return;
}
F_3 ( L_20 , V_2 -> V_9 , V_12 , type ) ;
assert ( 0 ) ;
}
static void * F_11 ( struct V_1 * V_2 , int type )
{
switch ( type ) {
case V_33 :
return V_2 -> V_34 . V_35 ;
case V_36 :
return V_2 -> V_37 . V_38 ;
case V_39 :
return V_2 -> V_40 . V_41 ;
}
F_3 ( L_20 , V_2 -> V_9 , V_12 , type ) ;
assert ( 0 ) ;
return NULL ;
}
static struct V_42 * F_12 ( struct V_1 * V_2 , int type )
{
struct V_42 * V_43 ;
int V_44 ;
void * V_32 = F_11 ( V_2 , type ) ;
for ( V_44 = sizeof( struct V_45 ) ; V_44 < V_46 ;
V_44 += F_13 ( V_43 ) ) {
V_43 = V_32 + V_44 ;
if ( V_43 -> type == 0 )
break;
if ( V_43 -> type == - 1 )
continue;
F_3 ( L_21 ,
V_2 -> V_9 , V_12 , V_43 -> type , V_43 ) ;
if ( V_43 -> type == ( V_47 ) type )
return V_43 ;
}
F_3 ( L_20 , V_2 -> V_9 , V_12 , type ) ;
return NULL ;
}
static unsigned F_14 ( struct V_48 * V_49 )
{
unsigned int V_50 ;
if ( ! ( F_15 ( V_49 -> V_51 ) & V_52 ) )
return - 1U ;
V_50 = F_15 ( V_49 -> V_50 ) ;
return V_50 ;
}
static T_2
F_16 ( struct V_53 * V_54 )
{
T_2 V_55 = 0 ;
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < V_54 -> V_56 ; V_44 ++ )
V_55 += V_54 -> V_57 [ V_44 ] . V_58 ;
return V_55 ;
}
static inline void F_17 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
if ( V_54 -> V_59 != F_16 ( V_54 ) ) {
F_3 ( L_22 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_54 -> V_59 , F_16 ( V_54 ) ) ;
assert ( V_54 -> V_59 == F_16 ( V_54 ) ) ;
}
}
static void
F_18 ( struct V_1 * V_2 , struct V_53 * V_54 ,
const char * V_60 , int line )
{
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < V_54 -> V_56 ; V_44 ++ )
F_3 ( L_23 ,
V_2 -> V_9 , V_60 , line , V_44 ,
V_54 -> V_57 [ V_44 ] . V_61 , V_54 -> V_57 [ V_44 ] . V_58 ) ;
}
static inline T_3 F_19 ( struct V_62 * V_63 )
{
return F_20 ( V_63 -> V_64 -> V_65 ) ;
}
static inline void F_21 ( int type , bool V_66 , struct V_62 * V_63 ,
struct V_53 * V_54 , T_2 V_67 )
{
V_54 -> V_68 = V_66 ? 0 : 1 ;
V_54 -> V_69 = true ;
if ( type == V_36 )
V_54 -> V_57 [ 1 ] . V_58 = V_67 - sizeof( struct V_70 ) ;
else
V_54 -> V_57 [ 0 ] . V_58 = V_67 ;
}
static int
F_22 ( struct V_1 * V_2 , int V_15 ,
struct V_62 * V_63 , struct V_53 * V_54 )
{
int V_8 ;
V_8 = F_8 ( V_15 , V_71 , V_54 ) ;
if ( V_8 ) {
F_3 ( L_24 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) , V_8 ) ;
}
return V_8 ;
}
static inline unsigned F_23 ( unsigned int V_72 , unsigned long V_73 )
{
return ( ( sizeof( struct V_48 ) * V_72 + sizeof( T_3 ) * ( 3 + V_72 )
+ V_73 - 1 ) & ~ ( V_73 - 1 ) )
+ sizeof( T_3 ) * 3 + sizeof( struct V_74 ) * V_72 ;
}
static void *
F_24 ( struct V_1 * V_2 , int V_15 , int type ,
struct V_62 * V_75 , struct V_62 * V_76 , int V_77 )
{
int V_78 ;
char * V_79 ;
V_78 = F_25 ( F_23 ( V_80 ,
V_81 ) +
sizeof( struct V_82 ) ) ;
V_79 = F_26 ( NULL , V_83 + V_78 * V_77 ,
V_84 , V_85 , V_15 , 0 ) ;
if ( V_86 == V_79 ) {
F_3 ( L_25 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
goto V_20;
}
F_10 ( V_2 , type , V_79 ) ;
V_75 -> V_79 = (struct V_62 * ) & V_79 [ V_83 ] ;
V_75 -> V_64 = V_75 -> V_79 +
F_23 ( V_80 , V_81 ) ;
F_27 ( & V_75 -> V_63 ,
V_80 , V_75 -> V_79 , V_81 ) ;
F_3 ( L_26 ,
V_12 , V_2 -> V_9 , V_75 -> V_79 , V_75 -> V_64 , V_78 ,
F_23 ( V_80 , V_81 ) ) ;
F_3 ( L_27 ,
F_28 ( V_75 -> V_64 -> V_87 ) , V_88 + type ) ;
assert ( F_28 ( V_75 -> V_64 -> V_87 ) == V_88 + type ) ;
if ( V_76 ) {
V_76 -> V_79 = (struct V_62 * )
& V_79 [ V_83 + V_78 ] ;
V_76 -> V_64 = V_76 -> V_79 + F_23 ( V_80 ,
V_81 ) ;
F_27 ( & V_76 -> V_63 ,
V_80 , V_76 -> V_79 , V_81 ) ;
F_3 ( L_28 ,
V_12 , V_2 -> V_9 , V_76 -> V_79 , V_76 -> V_64 , V_78 ,
F_23 ( V_80 , V_81 ) ) ;
F_3 ( L_27 ,
F_28 ( V_76 -> V_64 -> V_87 ) , V_88 + type + 1 ) ;
assert ( F_28 ( V_76 -> V_64 -> V_87 ) == V_88 + type + 1 ) ;
}
V_20:
return V_79 ;
}
static int
F_29 ( struct V_1 * V_2 , int V_15 , int type )
{
struct V_89 V_89 ;
int V_16 ;
struct V_42 * V_49 = F_12 ( V_2 , type ) ;
V_47 V_90 ;
if ( ! V_49 )
return - V_91 ;
V_90 = V_49 -> V_92 ;
V_89 . V_15 = V_15 ;
F_3 ( L_29 ,
V_2 -> V_9 , V_12 , type , V_49 -> V_92 ) ;
while ( 1 ) {
V_89 . V_93 = V_94 ;
V_89 . V_95 = 0 ;
V_16 = F_30 ( & V_89 , 1 , - 1 ) ;
if ( V_16 < 0 ) {
F_3 ( L_30 ,
V_2 -> V_9 , V_12 , strerror ( V_10 ) ) ;
continue;
}
if ( V_89 . V_95 ) {
if ( V_49 -> V_92 != V_90 ) {
F_3 ( L_31
L_32 ,
V_2 -> V_9 , V_12 , type ,
V_49 -> V_92 ) ;
V_90 = V_49 -> V_92 ;
}
if ( V_49 -> V_92 & V_96 ) {
F_3 ( L_33 ,
V_2 -> V_9 , V_12 , V_89 . V_95 ) ;
F_3 ( L_34 ,
V_2 -> V_9 , V_12 , type ,
V_49 -> V_92 ) ;
break;
}
}
}
return 0 ;
}
static void
F_31 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
T_3 V_65 = F_19 ( V_63 ) ;
while ( V_65 == F_15 ( F_20 ( V_63 -> V_63 . V_97 -> V_98 ) ) ) {
#ifdef F_32
F_3 ( L_35 ,
V_2 -> V_9 , V_12 ,
F_15 ( V_63 -> V_63 . V_97 -> V_98 ) , V_63 -> V_64 -> V_65 ) ;
#endif
F_33 () ;
}
}
static void *
F_34 ( void * V_99 )
{
static V_47 V_100 [ 2 ] [ sizeof( struct V_70 ) ] ;
static V_47 V_101 [ 2 ] [ V_102 ] V_103 ( ( F_35 ( 64 ) ) ) ;
struct V_104 V_105 [ 2 ] [ 2 ] = {
{ { . V_61 = V_100 [ 0 ] , . V_58 = sizeof( V_100 [ 0 ] ) } ,
{ . V_61 = V_101 [ 0 ] , . V_58 = sizeof( V_101 [ 0 ] ) } } ,
{ { . V_61 = V_100 [ 1 ] , . V_58 = sizeof( V_100 [ 1 ] ) } ,
{ . V_61 = V_101 [ 1 ] , . V_58 = sizeof( V_101 [ 1 ] ) } } ,
} ;
struct V_104 * V_106 = V_105 [ 0 ] , * V_107 = V_105 [ 1 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
char V_108 [ V_7 ] ;
struct V_89 V_109 [ V_110 ] ;
struct V_62 V_111 , V_112 ;
struct V_53 V_54 ;
struct V_42 * V_49 ;
int V_16 ;
snprintf ( V_108 , V_7 , L_36 , V_2 -> V_11 ) ;
V_2 -> V_37 . V_113 = F_6 ( V_2 , V_108 ) ;
if ( V_2 -> V_37 . V_113 < 0 )
goto V_20;
if ( F_1 ( V_2 , V_108 ) )
goto V_20;
F_3 ( L_37 , V_2 -> V_9 , V_2 -> V_11 ) ;
V_109 [ V_114 ] . V_15 = V_2 -> V_37 . V_115 ;
V_109 [ V_114 ] . V_93 = V_94 ;
V_109 [ V_116 ] . V_15 = V_2 -> V_37 . V_113 ;
V_109 [ V_116 ] . V_93 = V_94 ;
if ( V_86 == F_24 ( V_2 , V_2 -> V_37 . V_115 ,
V_36 , & V_111 , & V_112 ,
V_117 . V_118 . V_77 ) ) {
F_3 ( L_38 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
goto V_20;
}
V_54 . V_56 = 2 ;
V_49 = F_12 ( V_2 , V_36 ) ;
while ( 1 ) {
T_2 V_67 ;
V_109 [ V_114 ] . V_95 = 0 ;
V_109 [ V_116 ] . V_95 = 0 ;
V_16 = F_30 ( V_109 , 2 , - 1 ) ;
if ( V_16 < 0 ) {
F_3 ( L_39 ,
V_12 , strerror ( V_10 ) ) ;
continue;
}
if ( ! ( V_49 -> V_92 & V_96 ) ) {
V_16 = F_29 ( V_2 ,
V_2 -> V_37 . V_115 ,
V_36 ) ;
if ( V_16 ) {
F_3 ( L_40 ,
V_2 -> V_9 , V_12 , __LINE__ ) ;
break;
}
}
if ( V_109 [ V_116 ] . V_95 & V_94 ) {
V_54 . V_57 = V_106 ;
V_67 = F_36 ( V_109 [ V_116 ] . V_15 ,
V_54 . V_57 , V_54 . V_56 ) ;
if ( V_67 > 0 ) {
struct V_70 * V_119
= (struct V_70 * ) V_100 [ 0 ] ;
V_119 -> V_51 |= V_120 ;
#ifdef F_32
F_3 ( L_41 , V_2 -> V_9 ,
V_12 , __LINE__ , V_119 -> V_51 ) ;
F_3 ( L_42 ,
V_54 . V_59 , V_119 -> V_121 ) ;
#endif
#ifdef F_32
F_18 ( V_2 , V_54 , V_12 , __LINE__ ) ;
F_3 ( L_43 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_67 ) ;
#endif
F_31 ( V_2 , & V_111 ) ;
F_21 ( V_36 , 1 , & V_111 , & V_54 ,
V_67 ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_37 . V_115 , & V_111 ,
& V_54 ) ;
if ( V_16 < 0 ) {
F_3 ( L_44 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
}
if ( ! V_16 )
F_17 ( V_2 , & V_54 ) ;
#ifdef F_32
F_18 ( V_2 , V_54 , V_12 , __LINE__ ) ;
F_3 ( L_45 ,
V_2 -> V_9 , V_12 , __LINE__ ,
F_16 ( & V_54 ) ) ;
#endif
V_106 [ 1 ] . V_58 = V_102 ;
} else if ( V_67 < 0 ) {
F_18 ( V_2 , & V_54 , V_12 , __LINE__ ) ;
F_3 ( L_46 , V_2 -> V_9 ,
V_12 , __LINE__ , strerror ( V_10 ) ) ;
F_3 ( L_47 ,
V_54 . V_56 , F_16 ( & V_54 ) ) ;
}
}
if ( V_109 [ V_114 ] . V_95 & V_94 ) {
while ( V_112 . V_64 -> V_65 !=
F_15 ( V_112 . V_63 . V_97 -> V_98 ) ) {
V_54 . V_57 = V_107 ;
F_21 ( V_36 , 0 , & V_112 , & V_54 ,
V_102
+ sizeof( struct V_70 ) ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_37 . V_115 , & V_112 ,
& V_54 ) ;
if ( ! V_16 ) {
#ifdef F_32
struct V_70 * V_119
= (struct V_70 * )
V_100 [ 1 ] ;
F_3 ( L_48 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_119 -> V_51 ) ;
F_3 ( L_49 ,
V_54 . V_59 ,
V_119 -> V_121 ) ;
#endif
V_107 [ 1 ] . V_58 = V_54 . V_59 -
sizeof( struct V_70 ) ;
F_17 ( V_2 , & V_54 ) ;
#ifdef F_32
F_18 ( V_2 , V_54 , V_12 ,
__LINE__ ) ;
F_3 ( L_50 ,
V_2 -> V_9 , V_12 , __LINE__ ) ;
F_3 ( L_51 ,
F_16 ( V_54 ) ) ;
#endif
V_67 = F_37 ( V_109 [ V_116 ] . V_15 ,
V_54 . V_57 , V_54 . V_56 ) ;
if ( V_67 != F_16 ( & V_54 ) ) {
F_3 ( L_52 ,
strerror ( V_10 ) ) ;
F_3 ( L_53 , V_67 ) ;
F_3 ( L_54 ,
F_16 ( & V_54 ) ) ;
} else {
#ifdef F_32
F_18 ( V_2 , & V_54 , V_12 ,
__LINE__ ) ;
F_3 ( L_50 ,
V_2 -> V_9 , V_12 ,
__LINE__ ) ;
F_3 ( L_55 ,
V_67 ) ;
#endif
}
} else {
F_3 ( L_44 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
break;
}
}
}
if ( V_109 [ V_114 ] . V_95 & V_122 )
F_3 ( L_56 , V_12 , V_2 -> V_9 ) ;
}
V_20:
F_38 ( NULL ) ;
}
static void *
F_39 ( void * V_99 )
{
static V_47 V_123 [ 2 ] [ V_46 ] ;
struct V_104 V_124 [ 2 ] = {
{ . V_61 = V_123 [ 0 ] , . V_58 = sizeof( V_123 [ 0 ] ) } ,
{ . V_61 = V_123 [ 1 ] , . V_58 = sizeof( V_123 [ 1 ] ) } ,
} ;
struct V_104 * V_106 = & V_124 [ 0 ] , * V_107 = & V_124 [ 1 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
int V_16 ;
struct V_89 V_125 [ V_126 ] ;
int V_127 ;
char * V_128 ;
T_2 V_67 ;
struct V_62 V_111 , V_112 ;
struct V_53 V_54 ;
struct V_42 * V_49 ;
V_127 = F_40 ( V_19 ) ;
if ( V_127 < 0 ) {
F_3 ( L_57 ,
strerror ( V_10 ) ) ;
goto V_129;
}
V_128 = F_41 ( V_127 ) ;
if ( V_128 == NULL ) {
F_3 ( L_58 ) ;
goto V_130;
}
printf ( L_59 , V_2 -> V_9 , V_128 ) ;
F_3 ( L_59 , V_2 -> V_9 , V_128 ) ;
V_16 = F_42 ( V_127 ) ;
if ( V_16 < 0 ) {
F_3 ( L_60 ,
V_128 , strerror ( V_10 ) ) ;
goto V_130;
}
V_16 = F_43 ( V_127 ) ;
if ( V_16 < 0 ) {
F_3 ( L_61 ,
V_128 , strerror ( V_10 ) ) ;
goto V_130;
}
V_125 [ V_131 ] . V_15 = V_127 ;
V_125 [ V_131 ] . V_93 = V_94 ;
V_125 [ V_132 ] . V_15 = V_2 -> V_34 . V_133 ;
V_125 [ V_132 ] . V_93 = V_94 ;
if ( V_86 == F_24 ( V_2 , V_2 -> V_34 . V_133 ,
V_33 , & V_111 , & V_112 ,
V_134 . V_118 . V_77 ) ) {
F_3 ( L_38 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
goto V_130;
}
V_54 . V_56 = 1 ;
V_49 = F_12 ( V_2 , V_33 ) ;
for (; ; ) {
V_125 [ V_131 ] . V_95 = 0 ;
V_125 [ V_132 ] . V_95 = 0 ;
V_16 = F_30 ( V_125 , V_126 , - 1 ) ;
if ( V_16 < 0 ) {
F_3 ( L_62 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
continue;
}
if ( ! ( V_49 -> V_92 & V_96 ) ) {
V_16 = F_29 ( V_2 ,
V_2 -> V_34 . V_133 ,
V_33 ) ;
if ( V_16 ) {
F_3 ( L_40 ,
V_2 -> V_9 , V_12 , __LINE__ ) ;
break;
}
}
if ( V_125 [ V_131 ] . V_95 & V_94 ) {
V_54 . V_57 = V_106 ;
V_67 = F_36 ( V_127 , V_54 . V_57 , V_54 . V_56 ) ;
if ( V_67 > 0 ) {
#ifdef F_32
F_18 ( V_2 , V_54 , V_12 , __LINE__ ) ;
F_3 ( L_43 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_67 ) ;
#endif
F_31 ( V_2 , & V_111 ) ;
F_21 ( V_33 , 1 , & V_111 ,
& V_54 , V_67 ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_34 . V_133 ,
& V_111 , & V_54 ) ;
if ( V_16 < 0 ) {
F_3 ( L_44 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
}
if ( ! V_16 )
F_17 ( V_2 , & V_54 ) ;
#ifdef F_32
F_18 ( V_2 , V_54 , V_12 , __LINE__ ) ;
F_3 ( L_45 ,
V_2 -> V_9 , V_12 , __LINE__ ,
F_16 ( V_54 ) ) ;
#endif
V_106 -> V_58 = V_46 ;
} else if ( V_67 < 0 ) {
F_18 ( V_2 , & V_54 , V_12 , __LINE__ ) ;
F_3 ( L_46 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
F_3 ( L_47 ,
V_54 . V_56 , F_16 ( & V_54 ) ) ;
}
}
if ( V_125 [ V_132 ] . V_95 & V_94 ) {
while ( V_112 . V_64 -> V_65 !=
F_15 ( V_112 . V_63 . V_97 -> V_98 ) ) {
V_54 . V_57 = V_107 ;
F_21 ( V_33 , 0 , & V_112 ,
& V_54 , V_46 ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_34 . V_133 ,
& V_112 , & V_54 ) ;
if ( ! V_16 ) {
V_107 -> V_58 = V_54 . V_59 ;
F_17 ( V_2 , & V_54 ) ;
#ifdef F_32
F_18 ( V_2 , V_54 , V_12 ,
__LINE__ ) ;
F_3 ( L_50 ,
V_2 -> V_9 , V_12 , __LINE__ ) ;
F_3 ( L_51 ,
F_16 ( V_54 ) ) ;
#endif
V_67 = F_37 ( V_127 ,
V_54 . V_57 , V_54 . V_56 ) ;
if ( V_67 != F_16 ( & V_54 ) ) {
F_3 ( L_52 ,
strerror ( V_10 ) ) ;
F_3 ( L_53 , V_67 ) ;
F_3 ( L_54 ,
F_16 ( & V_54 ) ) ;
} else {
#ifdef F_32
F_18 ( V_2 , V_54 , V_12 ,
__LINE__ ) ;
F_3 ( L_50 ,
V_2 -> V_9 , V_12 ,
__LINE__ ) ;
F_3 ( L_55 ,
V_67 ) ;
#endif
}
} else {
F_3 ( L_44 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
break;
}
}
}
if ( V_125 [ V_114 ] . V_95 & V_122 )
F_3 ( L_56 , V_12 , V_2 -> V_9 ) ;
}
V_130:
F_9 ( V_127 ) ;
V_129:
F_38 ( NULL ) ;
}
static void
F_44 ( struct V_1 * V_2 , struct V_42 * V_118 )
{
char V_135 [ V_136 ] ;
int V_15 , V_16 ;
snprintf ( V_135 , V_136 , L_63 , V_2 -> V_11 ) ;
V_15 = F_7 ( V_135 , V_19 ) ;
if ( V_15 < 0 ) {
F_3 ( L_64 , V_135 , strerror ( V_10 ) ) ;
return;
}
V_16 = F_8 ( V_15 , V_137 , V_118 ) ;
if ( V_16 < 0 ) {
F_3 ( L_65 , V_118 -> type , strerror ( V_10 ) ) ;
F_9 ( V_15 ) ;
return;
}
switch ( V_118 -> type ) {
case V_36 :
V_2 -> V_37 . V_115 = V_15 ;
F_3 ( L_66 , V_2 -> V_9 ) ;
break;
case V_33 :
V_2 -> V_34 . V_133 = V_15 ;
F_3 ( L_67 , V_2 -> V_9 ) ;
break;
case V_39 :
V_2 -> V_40 . V_138 = V_15 ;
F_3 ( L_68 , V_2 -> V_9 ) ;
break;
}
}
static bool
F_45 ( struct V_1 * V_2 )
{
T_4 * V_139 ;
char V_140 [ V_136 ] , * line , * V_141 , * V_142 ;
snprintf ( V_140 , V_136 , L_69 , V_143 , V_2 -> V_11 ) ;
V_139 = fopen ( V_140 , L_70 ) ;
if ( V_139 == NULL )
return false ;
do {
line = fgets ( V_140 , V_136 , V_139 ) ;
if ( line == NULL )
break;
if ( * line == '#' )
continue;
V_142 = strchr ( line , '\n' ) ;
if ( V_142 )
* V_142 = '\0' ;
} while ( strncmp ( line , V_144 , strlen ( V_144 ) ) != 0 );
fclose ( V_139 ) ;
if ( line == NULL )
return false ;
V_141 = strchr ( line , '=' ) ;
if ( V_141 == NULL )
return false ;
V_2 -> V_40 . V_145 = malloc ( strlen ( V_141 ) + 1 ) ;
if ( V_2 -> V_40 . V_145 == NULL ) {
F_3 ( L_71 , V_2 -> V_9 , V_2 -> V_11 ) ;
return false ;
}
strcpy ( V_2 -> V_40 . V_145 , V_141 + 1 ) ;
return true ;
}
static bool
F_46 ( struct V_1 * V_2 )
{
V_2 -> V_40 . V_146 = F_47 ( V_2 -> V_40 . V_147 , 0 ,
V_148 ) ;
if ( V_2 -> V_40 . V_146 < 0 ) {
F_3 ( L_72 ,
V_2 -> V_9 , V_2 -> V_40 . V_145 ) ;
return false ;
}
V_149 . V_150 . V_151 =
V_2 -> V_40 . V_146 / V_152 ;
if ( ( V_2 -> V_40 . V_146 % V_152 ) != 0 )
V_149 . V_150 . V_151 ++ ;
V_149 . V_150 . V_151 =
F_48 ( V_149 . V_150 . V_151 ) ;
return true ;
}
static bool
F_49 ( struct V_1 * V_2 )
{
if ( ! F_45 ( V_2 ) )
goto V_153;
V_2 -> V_40 . V_147 = F_7 ( V_2 -> V_40 . V_145 , V_19 ) ;
if ( V_2 -> V_40 . V_147 < 0 ) {
F_3 ( L_73 , V_2 -> V_9 ,
V_2 -> V_40 . V_145 ) ;
goto V_154;
}
if ( ! F_46 ( V_2 ) )
goto V_155;
V_2 -> V_40 . V_156 = F_26 ( NULL ,
V_2 -> V_40 . V_146 ,
V_84 | V_157 , V_85 ,
V_2 -> V_40 . V_147 , 0L ) ;
if ( V_2 -> V_40 . V_156 == V_86 ) {
F_3 ( L_74 ,
V_2 -> V_9 , V_2 -> V_40 . V_145 ,
strerror ( V_10 ) ) ;
goto V_155;
}
return true ;
V_155:
F_9 ( V_2 -> V_40 . V_147 ) ;
V_154:
free ( V_2 -> V_40 . V_145 ) ;
V_153:
return false ;
}
static void
F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_40 . V_156 , V_2 -> V_40 . V_146 ) ;
F_9 ( V_2 -> V_40 . V_147 ) ;
free ( V_2 -> V_40 . V_145 ) ;
}
static bool
F_52 ( struct V_1 * V_2 , struct V_62 * V_158 )
{
if ( ( ( unsigned long ) & V_149 . V_150 % 8 ) != 0 ) {
F_3 ( L_75 ,
V_2 -> V_9 ) ;
return false ;
}
F_44 ( V_2 , & V_149 . V_118 ) ;
if ( V_86 == F_24 ( V_2 , V_2 -> V_40 . V_138 ,
V_39 , V_158 , NULL ,
V_149 . V_118 . V_77 ) ) {
F_3 ( L_38 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return false ;
}
return true ;
}
static void
F_53 ( struct V_1 * V_2 )
{
int V_78 , V_8 ;
V_78 = F_25 ( F_23 ( V_80 ,
V_81 ) +
sizeof( struct V_82 ) ) ;
V_8 = F_51 ( V_2 -> V_40 . V_41 ,
V_83 + V_78 * V_149 . V_118 . V_77 ) ;
if ( V_8 < 0 )
F_3 ( L_76 , V_2 -> V_9 , V_10 ) ;
F_9 ( V_2 -> V_40 . V_138 ) ;
}
static V_47
F_54 ( struct V_48 * V_49 )
{
if ( F_28 ( V_49 -> V_67 ) != sizeof( struct V_159 ) ) {
F_3 ( L_77 ,
V_12 , __LINE__ ) ;
return - V_160 ;
}
if ( ! ( F_15 ( V_49 -> V_51 ) & V_52 ) ) {
F_3 ( L_78 ,
V_12 , __LINE__ ) ;
return - V_160 ;
}
if ( F_15 ( V_49 -> V_51 ) & V_161 ) {
F_3 ( L_79 ,
V_12 , __LINE__ ) ;
return - V_160 ;
}
return 0 ;
}
static int
F_55 ( int V_15 , struct V_159 * V_119 , T_5 V_162 )
{
struct V_104 V_104 ;
struct V_53 V_54 ;
V_104 . V_58 = sizeof( * V_119 ) ;
V_104 . V_61 = V_119 ;
V_54 . V_57 = & V_104 ;
V_54 . V_56 = 1 ;
V_54 . V_68 = 0 ;
V_54 . V_69 = false ;
return F_8 ( V_15 , V_71 , & V_54 ) ;
}
static int
F_56 ( int V_15 , struct V_104 * V_104 , T_5 V_56 )
{
struct V_53 V_54 ;
V_54 . V_57 = V_104 ;
V_54 . V_56 = V_56 ;
V_54 . V_68 = 0 ;
V_54 . V_69 = false ;
return F_8 ( V_15 , V_71 , & V_54 ) ;
}
static V_47
F_57 ( struct V_48 * V_49 )
{
if ( F_28 ( V_49 -> V_67 ) != sizeof( V_47 ) ) {
F_3 ( L_80 ,
V_12 , __LINE__ ) ;
return - V_160 ;
}
return 0 ;
}
static int
F_58 ( int V_15 , V_47 * V_92 )
{
struct V_104 V_104 ;
struct V_53 V_54 ;
V_104 . V_61 = V_92 ;
V_104 . V_58 = sizeof( * V_92 ) ;
V_54 . V_57 = & V_104 ;
V_54 . V_56 = 1 ;
V_54 . V_68 = 0 ;
V_54 . V_69 = true ;
return F_8 ( V_15 , V_71 , & V_54 ) ;
}
static void *
F_59 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
int V_8 ;
struct V_89 V_163 ;
struct V_62 V_158 ;
T_3 V_65 ;
T_5 V_162 ;
struct V_48 * V_49 ;
struct V_104 * V_104 , * V_164 ;
V_47 V_92 ;
T_5 V_165 ;
struct V_159 V_119 ;
void * V_166 ;
for (; ; ) {
if ( ! F_49 ( V_2 ) ) {
for ( V_2 -> V_40 . V_167 = 0 ;
! V_2 -> V_40 . V_167 ; )
F_60 ( 1 ) ;
continue;
}
if ( ! F_52 ( V_2 , & V_158 ) )
goto V_168;
V_104 = malloc ( sizeof( * V_104 ) *
F_28 ( V_149 . V_150 . V_169 ) ) ;
if ( ! V_104 ) {
F_3 ( L_81 ,
V_2 -> V_9 , strerror ( V_170 ) ) ;
goto V_171;
}
V_163 . V_15 = V_2 -> V_40 . V_138 ;
V_163 . V_93 = V_94 ;
for ( V_2 -> V_40 . V_167 = 0 ;
! V_2 -> V_40 . V_167 ; ) {
V_163 . V_95 = 0 ;
V_8 = F_30 ( & V_163 , 1 , 1000 ) ;
if ( V_8 < 0 ) {
F_3 ( L_62 ,
V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
continue;
}
if ( ! ( V_163 . V_95 & V_94 ) ) {
#ifdef F_32
F_3 ( L_82 ,
V_12 , __LINE__ , V_163 . V_95 ) ;
#endif
continue;
}
while ( V_158 . V_64 -> V_65 !=
F_15 ( V_158 . V_63 . V_97 -> V_98 ) ) {
V_65 =
V_158 . V_64 -> V_65 &
( V_158 . V_63 . V_72 - 1 ) ;
V_162 = F_15 (
V_158 . V_63 . V_97 -> V_172 [ V_65 ] ) ;
V_49 = & V_158 . V_63 . V_49 [ V_162 ] ;
#ifdef F_32
F_3 ( L_83 ,
V_12 , __LINE__ ,
V_158 . V_64 -> V_65 ) ;
F_3 ( L_84 ,
V_158 . V_63 . V_72 , V_49 ) ;
#endif
V_92 = F_54 ( V_49 ) ;
V_8 = F_55 (
V_2 -> V_40 . V_138 ,
& V_119 , V_162 ) ;
if ( V_8 < 0 ) {
F_3 ( L_85 ,
V_12 , __LINE__ ,
V_2 -> V_9 , V_8 ,
strerror ( V_10 ) ) ;
break;
}
V_164 = V_104 ;
V_92 = 0 ;
V_166 = V_2 -> V_40 . V_156 +
( V_119 . V_173 * V_152 ) ;
V_165 = F_14 ( V_49 ) ;
V_162 = V_165 ;
for ( V_49 = & V_158 . V_63 . V_49 [ V_165 ] ;
V_49 -> V_51 & V_52 ;
V_162 = F_14 ( V_49 ) ,
V_49 = & V_158 . V_63 . V_49 [ V_162 ] ) {
V_164 -> V_58 = V_49 -> V_67 ;
V_164 -> V_61 = V_166 ;
V_164 ++ ;
V_166 += V_49 -> V_67 ;
}
if ( V_119 . type & ~ ( V_174 |
V_175 ) ) {
F_3 ( L_86 ,
V_12 , __LINE__ ,
V_119 . type ) ;
F_3 ( L_87 ) ;
V_92 = - V_176 ;
} else {
V_8 = F_56 (
V_2 -> V_40 . V_138 ,
V_104 ,
V_164 - V_104 ) ;
if ( V_8 < 0 &&
V_92 != 0 )
V_92 = V_8 ;
}
if ( V_92 != 0 )
V_92 = F_57 ( V_49 ) ;
V_8 = F_58 (
V_2 -> V_40 . V_138 ,
& V_92 ) ;
#ifdef F_32
F_3 ( L_88 ,
V_12 , __LINE__ ,
V_92 , V_49 ) ;
#endif
}
}
free ( V_104 ) ;
V_171:
F_53 ( V_2 ) ;
V_168:
F_50 ( V_2 ) ;
}
F_38 ( NULL ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
#define F_62 120
int V_44 = F_62 ;
F_63 ( V_2 -> V_9 , L_89 , L_90 ) ;
while ( V_44 ) {
char * V_177 ;
V_177 = F_64 ( V_2 -> V_9 , L_89 ) ;
if ( ! V_177 )
goto V_178;
F_3 ( L_91 ,
V_2 -> V_9 , V_12 , __LINE__ , V_177 ) ;
if ( ! strcmp ( V_177 , L_92 ) ) {
free ( V_177 ) ;
break;
}
free ( V_177 ) ;
V_178:
F_60 ( 1 ) ;
V_44 -- ;
}
}
static int
F_65 ( struct V_1 * V_2 , char * V_179 )
{
if ( ! strcmp ( V_179 , L_93 ) )
return V_180 ;
if ( ! strcmp ( V_179 , L_94 ) )
return V_181 ;
if ( ! strcmp ( V_179 , L_95 ) )
return V_182 ;
if ( ! strcmp ( V_179 , L_96 ) )
return V_183 ;
if ( ! strcmp ( V_179 , L_97 ) )
return V_184 ;
F_3 ( L_98 , V_2 -> V_9 , V_179 ) ;
assert ( 0 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
char * V_177 = NULL ;
enum V_185 V_186 ;
while ( ! V_177 ) {
V_177 = F_64 ( V_2 -> V_9 , L_89 ) ;
F_60 ( 1 ) ;
}
F_3 ( L_91 ,
V_2 -> V_9 , V_12 , __LINE__ , V_177 ) ;
if ( ! strcmp ( V_177 , L_92 ) ) {
V_186 = V_187 ;
} else if ( ! strcmp ( V_177 , L_99 ) ) {
V_186 = V_188 ;
} else if ( ! strcmp ( V_177 , L_100 ) ) {
V_186 = V_189 ;
} else if ( ! strcmp ( V_177 , L_101 ) ) {
V_186 = V_190 ;
} else if ( ! strcmp ( V_177 , L_102 ) ) {
V_186 = V_191 ;
} else if ( ! strcmp ( V_177 , L_103 ) ) {
V_186 = V_192 ;
} else {
F_3 ( L_104 , V_2 -> V_9 , V_177 ) ;
assert ( 0 ) ;
}
free ( V_177 ) ;
return V_186 ;
}
static void F_67 ( struct V_1 * V_2 )
{
#define F_68 60
int V_44 = F_68 ;
char * V_179 ;
while ( V_44 ) {
V_179 = F_64 ( V_2 -> V_9 , L_105 ) ;
if ( ! V_179 ) {
F_60 ( 1 ) ;
continue;
}
F_3 ( L_106 ,
V_2 -> V_9 , V_12 , __LINE__ , V_179 ) ;
switch ( F_65 ( V_2 , V_179 ) ) {
case V_184 :
V_2 -> V_193 = 1 ;
case V_182 :
case V_183 :
case V_181 :
free ( V_179 ) ;
goto F_61;
default:
break;
}
free ( V_179 ) ;
F_60 ( 1 ) ;
V_44 -- ;
}
F_61:
if ( ! V_44 )
F_3 ( L_107 ,
V_2 -> V_9 , V_12 , __LINE__ , V_179 ) ;
F_61 ( V_2 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
char V_194 [ V_136 ] ;
int V_15 ;
snprintf ( V_194 , V_136 - 1 , L_108 ,
V_195 , V_2 -> V_9 , L_89 ) ;
V_15 = F_7 ( V_194 , V_196 ) ;
if ( V_15 < 0 )
F_3 ( L_109 ,
V_2 -> V_9 , V_194 , strerror ( V_10 ) ) ;
return V_15 ;
}
static int F_70 ( int V_15 , struct V_1 * V_2 )
{
struct V_89 V_197 [ 1 ] ;
char V_198 [ V_46 ] ;
int V_8 ;
V_197 [ 0 ] . V_15 = V_15 ;
V_197 [ 0 ] . V_93 = V_122 | V_199 ;
V_8 = F_30 ( V_197 , 1 , - 1 ) ;
if ( V_8 < 0 ) {
F_3 ( L_110 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
return V_8 ;
}
V_8 = F_47 ( V_15 , 0 , V_200 ) ;
if ( V_8 < 0 ) {
F_3 ( L_111 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
return V_8 ;
}
V_8 = F_71 ( V_15 , V_198 , sizeof( V_198 ) ) ;
if ( V_8 < 0 ) {
F_3 ( L_112 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
return V_8 ;
}
return 0 ;
}
static void *
F_72 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
int V_15 , V_8 , V_201 = 0 ;
V_15 = F_69 ( V_2 ) ;
if ( V_15 < 0 ) {
F_3 ( L_113 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
goto exit;
}
do {
V_8 = F_70 ( V_15 , V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_114 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
goto V_202;
}
switch ( F_66 ( V_2 ) ) {
case V_190 :
F_67 ( V_2 ) ;
break;
case V_187 :
case V_191 :
V_8 = F_73 ( V_2 -> V_4 , V_203 ) ;
F_3 ( L_115 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_2 -> V_4 , V_8 ) ;
if ( ! V_8 ) {
V_8 = F_5 ( V_2 -> V_4 , & V_201 ,
F_74 ( V_201 ) ) ;
F_3 ( L_116 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_8 , V_2 -> V_4 ) ;
}
if ( V_2 -> V_204 ) {
F_63 ( V_2 -> V_9 , L_89 , L_117 ) ;
V_2 -> V_204 = 0 ;
}
goto V_202;
default:
break;
}
} while ( 1 );
V_202:
F_9 ( V_15 ) ;
exit:
F_75 ( V_2 ) ;
F_38 ( NULL ) ;
}
static void
F_76 ( struct V_1 * V_2 )
{
char V_205 [ V_136 ] ;
int V_67 ;
V_67 = snprintf ( V_205 , V_136 ,
L_118 ) ;
V_67 += snprintf ( V_205 + V_67 , V_136 ,
L_119 ) ;
V_67 += snprintf ( V_205 + V_67 , V_136 ,
L_120 ,
V_2 -> V_11 + 1 ) ;
F_63 ( V_2 -> V_9 , L_121 , V_205 ) ;
F_3 ( L_122 , V_2 -> V_9 , V_205 ) ;
snprintf ( V_205 , V_136 , L_123 , V_2 -> V_11 + 1 ) ;
F_3 ( L_124 , V_2 -> V_9 , V_205 ) ;
}
static void
F_77 ( struct V_1 * V_2 )
{
int V_15 ;
T_6 V_67 ;
char V_206 [] = L_125 ;
char * V_207 , * V_208 , V_209 [ 17 ] = { '\0' } ;
V_15 = F_7 ( V_206 , V_196 ) ;
if ( V_15 < 0 ) {
F_3 ( L_126 ,
V_2 -> V_9 , V_10 ) ;
return;
}
V_67 = F_47 ( V_15 , 0 , V_148 ) ;
if ( V_67 < 0 ) {
F_3 ( L_127 ,
V_2 -> V_9 , V_10 ) ;
F_9 ( V_15 ) ;
return;
}
V_207 = F_26 ( NULL , V_67 , V_84 , V_210 , V_15 , 0 ) ;
if ( V_207 == V_86 ) {
F_3 ( L_128 ,
V_2 -> V_9 , V_10 ) ;
F_9 ( V_15 ) ;
return;
}
V_208 = strstr ( V_207 , L_129 ) ;
if ( ! V_208 ) {
F_3 ( L_130 , V_2 -> V_9 , V_10 ) ;
F_51 ( V_207 , V_67 ) ;
F_9 ( V_15 ) ;
return;
}
strncpy ( V_209 , V_208 - 19 , 16 ) ;
F_63 ( V_2 -> V_9 , L_131 , V_209 ) ;
F_3 ( L_132 , V_2 -> V_9 , V_209 ) ;
V_208 = strstr ( V_207 , L_133 ) ;
if ( ! V_208 ) {
F_3 ( L_134 , V_2 -> V_9 , V_10 ) ;
F_51 ( V_207 , V_67 ) ;
F_9 ( V_15 ) ;
return;
}
strncpy ( V_209 , V_208 - 19 , 16 ) ;
F_63 ( V_2 -> V_9 , L_133 , V_209 ) ;
F_3 ( L_135 , V_2 -> V_9 , V_209 ) ;
F_51 ( V_207 , V_67 ) ;
F_9 ( V_15 ) ;
}
static void
F_78 ( int V_211 , T_7 * V_212 , void * V_142 )
{
struct V_1 * V_2 ;
for ( V_2 = V_213 . V_50 ; V_2 != NULL ; V_2 = V_2 -> V_50 )
V_2 -> V_40 . V_167 = 1 ;
}
static void
F_79 ( struct V_1 * V_2 )
{
F_77 ( V_2 ) ;
F_76 ( V_2 ) ;
}
static void *
F_75 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
struct V_214 V_215 = {
. V_216 = 0 ,
. V_217 = V_218
} ;
struct V_214 V_219 = {
. V_216 = V_220 ,
. V_221 = F_78 ,
} ;
char V_205 [ V_136 ] ;
int V_16 , V_15 ;
V_214 ( V_222 , & V_215 , NULL ) ;
V_178:
V_15 = F_69 ( V_2 ) ;
if ( V_15 < 0 ) {
F_3 ( L_113 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
F_60 ( 2 ) ;
goto V_178;
}
if ( V_2 -> V_193 ) {
snprintf ( V_205 , V_136 , L_117 ) ;
F_63 ( V_2 -> V_9 , L_89 , V_205 ) ;
F_3 ( L_136 ,
V_2 -> V_9 , V_2 -> V_193 ) ;
V_2 -> V_193 = 0 ;
}
while ( 1 ) {
while ( F_70 ( V_15 , V_2 ) ) {
F_3 ( L_114 ,
V_2 -> V_9 , V_12 , __LINE__ , strerror ( V_10 ) ) ;
F_60 ( 2 ) ;
continue;
}
if ( F_66 ( V_2 ) == V_188 )
break;
}
V_2 -> V_4 = F_2 () ;
switch ( V_2 -> V_4 ) {
case 0 :
F_44 ( V_2 , & V_134 . V_118 ) ;
F_44 ( V_2 , & V_117 . V_118 ) ;
V_16 = F_80 ( & V_2 -> V_34 . V_223 , NULL ,
F_39 , V_2 ) ;
if ( V_16 )
F_3 ( L_137 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
V_16 = F_80 ( & V_2 -> V_37 . V_224 , NULL ,
F_34 , V_2 ) ;
if ( V_16 )
F_3 ( L_138 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
V_16 = F_80 ( & V_2 -> V_40 . V_225 , NULL ,
F_59 , V_2 ) ;
if ( V_16 )
F_3 ( L_139 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
F_81 ( & V_219 . V_226 ) ;
V_16 = V_214 ( V_222 , & V_219 , NULL ) ;
if ( V_16 )
F_3 ( L_140 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
while ( 1 )
F_60 ( 60 ) ;
case - 1 :
F_3 ( L_141 ,
V_2 -> V_9 , V_2 -> V_11 , V_10 ) ;
break;
default:
V_16 = F_80 ( & V_2 -> V_227 , NULL ,
F_72 , V_2 ) ;
if ( V_16 )
F_3 ( L_142 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
}
return NULL ;
}
static void
F_82 ( void )
{
struct V_1 * V_2 ;
int V_16 ;
for ( V_2 = V_213 . V_50 ; V_2 ; V_2 = V_2 -> V_50 ) {
F_79 ( V_2 ) ;
V_16 = F_80 ( & V_2 -> V_228 , NULL , F_75 , V_2 ) ;
if ( V_16 )
F_3 ( L_143 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
}
while ( 1 )
F_60 ( 60 ) ;
}
static int
F_83 ( void )
{
struct V_1 * V_2 = & V_213 ;
struct V_229 * V_230 ;
T_8 * V_32 ;
int V_231 = 0 ;
V_32 = F_84 ( V_195 ) ;
if ( ! V_32 )
return 0 ;
while ( ( V_230 = F_85 ( V_32 ) ) != NULL ) {
if ( ! strncmp ( V_230 -> V_232 , L_144 , 3 ) ) {
V_2 -> V_50 = calloc ( 1 , sizeof( struct V_1 ) ) ;
if ( V_2 -> V_50 ) {
V_2 = V_2 -> V_50 ;
V_2 -> V_11 = atoi ( & V_230 -> V_232 [ 3 ] ) ;
V_2 -> V_9 = malloc ( strlen ( V_230 -> V_232 ) + 16 ) ;
if ( V_2 -> V_9 )
strcpy ( V_2 -> V_9 , V_230 -> V_232 ) ;
F_3 ( L_37 , V_2 -> V_9 ,
V_2 -> V_11 ) ;
V_231 ++ ;
}
}
}
F_86 ( V_32 ) ;
return V_231 ;
}
void
F_3 ( char * V_233 , ... )
{
T_9 args ;
char V_205 [ 4096 ] ;
char V_234 [ 52 ] , * V_235 ;
T_10 V_236 ;
if ( V_237 == NULL )
return;
va_start ( args , V_233 ) ;
vsprintf ( V_205 , V_233 , args ) ;
va_end ( args ) ;
time ( & V_236 ) ;
V_235 = ctime_r ( & V_236 , V_234 ) ;
V_235 [ strlen ( V_235 ) - 1 ] = '\0' ;
fprintf ( V_237 , L_145 , V_235 , V_205 ) ;
fflush ( V_237 ) ;
}
int
main ( int V_238 , char * V_239 [] )
{
int V_231 ;
T_1 V_4 ;
V_240 = V_239 [ 0 ] ;
V_237 = fopen ( V_241 , L_146 ) ;
if ( ! V_237 ) {
fprintf ( V_242 , L_147 , V_241 ) ;
exit ( 1 ) ;
}
V_4 = F_2 () ;
switch ( V_4 ) {
case 0 :
break;
case - 1 :
exit ( 2 ) ;
default:
exit ( 0 ) ;
}
F_3 ( L_148 ) ;
V_231 = F_83 () ;
if ( V_231 == 0 ) {
F_3 ( L_149 ) ;
exit ( 3 ) ;
}
F_3 ( L_150 , V_231 ) ;
F_82 () ;
exit ( 0 ) ;
}
