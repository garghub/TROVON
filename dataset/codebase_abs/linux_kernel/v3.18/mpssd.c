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
snprintf ( V_6 , V_7 , L_9 , V_2 -> V_11 ) ;
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
V_18 = V_27 | V_28 | V_29 |
V_30 | V_31 ;
V_16 = F_8 ( V_15 , V_32 , V_18 ) ;
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
static void F_10 ( struct V_1 * V_2 , int type , void * V_33 )
{
switch ( type ) {
case V_34 :
V_2 -> V_35 . V_36 = V_33 ;
return;
case V_37 :
V_2 -> V_38 . V_39 = V_33 ;
return;
case V_40 :
V_2 -> V_41 . V_42 = V_33 ;
return;
}
F_3 ( L_20 , V_2 -> V_9 , V_12 , type ) ;
assert ( 0 ) ;
}
static void * F_11 ( struct V_1 * V_2 , int type )
{
switch ( type ) {
case V_34 :
return V_2 -> V_35 . V_36 ;
case V_37 :
return V_2 -> V_38 . V_39 ;
case V_40 :
return V_2 -> V_41 . V_42 ;
}
F_3 ( L_20 , V_2 -> V_9 , V_12 , type ) ;
assert ( 0 ) ;
return NULL ;
}
static struct V_43 * F_12 ( struct V_1 * V_2 , int type )
{
struct V_43 * V_44 ;
int V_45 ;
void * V_33 = F_11 ( V_2 , type ) ;
for ( V_45 = sizeof( struct V_46 ) ; V_45 < V_47 ;
V_45 += F_13 ( V_44 ) ) {
V_44 = V_33 + V_45 ;
if ( V_44 -> type == 0 )
break;
if ( V_44 -> type == - 1 )
continue;
F_3 ( L_21 ,
V_2 -> V_9 , V_12 , V_44 -> type , V_44 ) ;
if ( V_44 -> type == ( V_48 ) type )
return V_44 ;
}
F_3 ( L_20 , V_2 -> V_9 , V_12 , type ) ;
assert ( 0 ) ;
return NULL ;
}
static unsigned F_14 ( struct V_49 * V_50 )
{
unsigned int V_51 ;
if ( ! ( F_15 ( V_50 -> V_52 ) & V_53 ) )
return - 1U ;
V_51 = F_15 ( V_50 -> V_51 ) ;
return V_51 ;
}
static T_2
F_16 ( struct V_54 * V_55 )
{
T_2 V_56 = 0 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_55 -> V_57 ; V_45 ++ )
V_56 += V_55 -> V_58 [ V_45 ] . V_59 ;
return V_56 ;
}
static inline void F_17 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
if ( V_55 -> V_60 != F_16 ( V_55 ) ) {
F_3 ( L_22 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_55 -> V_60 , F_16 ( V_55 ) ) ;
assert ( V_55 -> V_60 == F_16 ( V_55 ) ) ;
}
}
static void
F_18 ( struct V_1 * V_2 , struct V_54 * V_55 ,
const char * V_61 , int line )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_55 -> V_57 ; V_45 ++ )
F_3 ( L_23 ,
V_2 -> V_9 , V_61 , line , V_45 ,
V_55 -> V_58 [ V_45 ] . V_62 , V_55 -> V_58 [ V_45 ] . V_59 ) ;
}
static inline T_3 F_19 ( struct V_63 * V_64 )
{
return F_20 ( V_64 -> V_65 -> V_66 ) ;
}
static inline void F_21 ( int type , bool V_67 , struct V_63 * V_64 ,
struct V_54 * V_55 , T_2 V_68 )
{
V_55 -> V_69 = V_67 ? 0 : 1 ;
V_55 -> V_70 = true ;
if ( type == V_37 )
V_55 -> V_58 [ 1 ] . V_59 = V_68 - sizeof( struct V_71 ) ;
else
V_55 -> V_58 [ 0 ] . V_59 = V_68 ;
}
static int
F_22 ( struct V_1 * V_2 , int V_15 ,
struct V_63 * V_64 , struct V_54 * V_55 )
{
int V_8 ;
V_8 = F_8 ( V_15 , V_72 , V_55 ) ;
if ( V_8 ) {
F_3 ( L_24 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) , V_8 ) ;
}
return V_8 ;
}
static void *
F_23 ( struct V_1 * V_2 , int V_15 , int type ,
struct V_63 * V_73 , struct V_63 * V_74 , int V_75 )
{
int V_76 ;
char * V_77 ;
V_76 = F_24 ( F_25 ( V_78 ,
V_79 ) + sizeof( struct V_80 ) ) ;
V_77 = F_26 ( NULL , V_81 + V_76 * V_75 ,
V_82 , V_83 , V_15 , 0 ) ;
if ( V_84 == V_77 ) {
F_3 ( L_25 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
goto V_20;
}
F_10 ( V_2 , type , V_77 ) ;
V_73 -> V_77 = (struct V_63 * ) & V_77 [ V_81 ] ;
V_73 -> V_65 = V_73 -> V_77 +
F_25 ( V_78 , V_79 ) ;
F_27 ( & V_73 -> V_64 ,
V_78 , V_73 -> V_77 , V_79 ) ;
F_3 ( L_26 ,
V_12 , V_2 -> V_9 , V_73 -> V_77 , V_73 -> V_65 , V_76 ,
F_25 ( V_78 , V_79 ) ) ;
F_3 ( L_27 ,
F_28 ( V_73 -> V_65 -> V_85 ) , V_86 + type ) ;
assert ( F_28 ( V_73 -> V_65 -> V_85 ) == V_86 + type ) ;
if ( V_74 ) {
V_74 -> V_77 = (struct V_63 * )
& V_77 [ V_81 + V_76 ] ;
V_74 -> V_65 = V_74 -> V_77 + F_25 ( V_78 ,
V_79 ) ;
F_27 ( & V_74 -> V_64 ,
V_78 , V_74 -> V_77 , V_79 ) ;
F_3 ( L_28 ,
V_12 , V_2 -> V_9 , V_74 -> V_77 , V_74 -> V_65 , V_76 ,
F_25 ( V_78 , V_79 ) ) ;
F_3 ( L_27 ,
F_28 ( V_74 -> V_65 -> V_85 ) , V_86 + type + 1 ) ;
assert ( F_28 ( V_74 -> V_65 -> V_85 ) == V_86 + type + 1 ) ;
}
V_20:
return V_77 ;
}
static void
F_29 ( struct V_1 * V_2 , int V_15 , int type )
{
struct V_87 V_87 ;
int V_16 ;
struct V_43 * V_50 = F_12 ( V_2 , type ) ;
V_87 . V_15 = V_15 ;
F_3 ( L_29 ,
V_2 -> V_9 , V_12 , type , V_50 -> V_88 ) ;
while ( 1 ) {
V_87 . V_89 = V_90 ;
V_87 . V_91 = 0 ;
V_16 = F_30 ( & V_87 , 1 , - 1 ) ;
if ( V_16 < 0 ) {
F_3 ( L_30 ,
V_2 -> V_9 , V_12 , strerror ( V_10 ) ) ;
continue;
}
if ( V_87 . V_91 ) {
F_3 ( L_31 ,
V_2 -> V_9 , V_12 , type , V_50 -> V_88 ) ;
if ( V_50 -> V_88 & V_92 ) {
F_3 ( L_32 ,
V_2 -> V_9 , V_12 , V_87 . V_91 ) ;
F_3 ( L_33 ,
V_2 -> V_9 , V_12 , type ,
V_50 -> V_88 ) ;
break;
}
}
}
}
static void
F_31 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
T_3 V_66 = F_19 ( V_64 ) ;
while ( V_66 == F_15 ( F_20 ( V_64 -> V_64 . V_93 -> V_94 ) ) ) {
#ifdef F_32
F_3 ( L_34 ,
V_2 -> V_9 , V_12 ,
F_15 ( V_64 -> V_64 . V_93 -> V_94 ) , V_64 -> V_65 -> V_66 ) ;
#endif
F_33 () ;
}
}
static void *
F_34 ( void * V_95 )
{
static V_48 V_96 [ 2 ] [ sizeof( struct V_71 ) ] ;
static V_48 V_97 [ 2 ] [ V_98 ] V_99 ( ( F_35 ( 64 ) ) ) ;
struct V_100 V_101 [ 2 ] [ 2 ] = {
{ { . V_62 = V_96 [ 0 ] , . V_59 = sizeof( V_96 [ 0 ] ) } ,
{ . V_62 = V_97 [ 0 ] , . V_59 = sizeof( V_97 [ 0 ] ) } } ,
{ { . V_62 = V_96 [ 1 ] , . V_59 = sizeof( V_96 [ 1 ] ) } ,
{ . V_62 = V_97 [ 1 ] , . V_59 = sizeof( V_97 [ 1 ] ) } } ,
} ;
struct V_100 * V_102 = V_101 [ 0 ] , * V_103 = V_101 [ 1 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
char V_104 [ V_7 ] ;
struct V_87 V_105 [ V_106 ] ;
struct V_63 V_107 , V_108 ;
struct V_54 V_55 ;
struct V_43 * V_50 ;
int V_16 ;
snprintf ( V_104 , V_7 , L_35 , V_2 -> V_11 ) ;
V_2 -> V_38 . V_109 = F_6 ( V_2 , V_104 ) ;
if ( V_2 -> V_38 . V_109 < 0 )
goto V_20;
if ( F_1 ( V_2 , V_104 ) )
goto V_20;
F_3 ( L_36 , V_2 -> V_9 , V_2 -> V_11 ) ;
V_105 [ V_110 ] . V_15 = V_2 -> V_38 . V_111 ;
V_105 [ V_110 ] . V_89 = V_90 ;
V_105 [ V_112 ] . V_15 = V_2 -> V_38 . V_109 ;
V_105 [ V_112 ] . V_89 = V_90 ;
if ( V_84 == F_23 ( V_2 , V_2 -> V_38 . V_111 ,
V_37 , & V_107 , & V_108 ,
V_113 . V_114 . V_75 ) ) {
F_3 ( L_37 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
goto V_20;
}
V_55 . V_57 = 2 ;
V_50 = F_12 ( V_2 , V_37 ) ;
while ( 1 ) {
T_2 V_68 ;
V_105 [ V_110 ] . V_91 = 0 ;
V_105 [ V_112 ] . V_91 = 0 ;
V_16 = F_30 ( V_105 , 2 , - 1 ) ;
if ( V_16 < 0 ) {
F_3 ( L_38 ,
V_12 , strerror ( V_10 ) ) ;
continue;
}
if ( ! ( V_50 -> V_88 & V_92 ) )
F_29 ( V_2 , V_2 -> V_38 . V_111 ,
V_37 ) ;
if ( V_105 [ V_112 ] . V_91 & V_90 ) {
V_55 . V_58 = V_102 ;
V_68 = F_36 ( V_105 [ V_112 ] . V_15 ,
V_55 . V_58 , V_55 . V_57 ) ;
if ( V_68 > 0 ) {
struct V_71 * V_115
= (struct V_71 * ) V_96 [ 0 ] ;
V_115 -> V_52 |= V_116 ;
#ifdef F_32
F_3 ( L_39 , V_2 -> V_9 ,
V_12 , __LINE__ , V_115 -> V_52 ) ;
F_3 ( L_40 ,
V_55 . V_60 , V_115 -> V_117 ) ;
#endif
#ifdef F_32
F_18 ( V_2 , V_55 , V_12 , __LINE__ ) ;
F_3 ( L_41 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_68 ) ;
#endif
F_31 ( V_2 , & V_107 ) ;
F_21 ( V_37 , 1 , & V_107 , & V_55 ,
V_68 ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_38 . V_111 , & V_107 ,
& V_55 ) ;
if ( V_16 < 0 ) {
F_3 ( L_42 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
}
if ( ! V_16 )
F_17 ( V_2 , & V_55 ) ;
#ifdef F_32
F_18 ( V_2 , V_55 , V_12 , __LINE__ ) ;
F_3 ( L_43 ,
V_2 -> V_9 , V_12 , __LINE__ ,
F_16 ( & V_55 ) ) ;
#endif
V_102 [ 1 ] . V_59 = V_98 ;
} else if ( V_68 < 0 ) {
F_18 ( V_2 , & V_55 , V_12 , __LINE__ ) ;
F_3 ( L_44 , V_2 -> V_9 ,
V_12 , __LINE__ , strerror ( V_10 ) ) ;
F_3 ( L_45 ,
V_55 . V_57 , F_16 ( & V_55 ) ) ;
}
}
if ( V_105 [ V_110 ] . V_91 & V_90 ) {
while ( V_108 . V_65 -> V_66 !=
F_15 ( V_108 . V_64 . V_93 -> V_94 ) ) {
V_55 . V_58 = V_103 ;
F_21 ( V_37 , 0 , & V_108 , & V_55 ,
V_98
+ sizeof( struct V_71 ) ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_38 . V_111 , & V_108 ,
& V_55 ) ;
if ( ! V_16 ) {
#ifdef F_32
struct V_71 * V_115
= (struct V_71 * )
V_96 [ 1 ] ;
F_3 ( L_46 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_115 -> V_52 ) ;
F_3 ( L_47 ,
V_55 . V_60 ,
V_115 -> V_117 ) ;
#endif
V_103 [ 1 ] . V_59 = V_55 . V_60 -
sizeof( struct V_71 ) ;
F_17 ( V_2 , & V_55 ) ;
#ifdef F_32
F_18 ( V_2 , V_55 , V_12 ,
__LINE__ ) ;
F_3 ( L_48 ,
V_2 -> V_9 , V_12 , __LINE__ ) ;
F_3 ( L_49 ,
F_16 ( V_55 ) ) ;
#endif
V_68 = F_37 ( V_105 [ V_112 ] . V_15 ,
V_55 . V_58 , V_55 . V_57 ) ;
if ( V_68 != F_16 ( & V_55 ) ) {
F_3 ( L_50 ,
strerror ( V_10 ) ) ;
F_3 ( L_51 , V_68 ) ;
F_3 ( L_52 ,
F_16 ( & V_55 ) ) ;
} else {
#ifdef F_32
F_18 ( V_2 , & V_55 , V_12 ,
__LINE__ ) ;
F_3 ( L_48 ,
V_2 -> V_9 , V_12 ,
__LINE__ ) ;
F_3 ( L_53 ,
V_68 ) ;
#endif
}
} else {
F_3 ( L_42 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
break;
}
}
}
if ( V_105 [ V_110 ] . V_91 & V_118 )
F_3 ( L_54 , V_12 , V_2 -> V_9 ) ;
}
V_20:
F_38 ( NULL ) ;
}
static void *
F_39 ( void * V_95 )
{
static V_48 V_119 [ 2 ] [ V_47 ] ;
struct V_100 V_120 [ 2 ] = {
{ . V_62 = V_119 [ 0 ] , . V_59 = sizeof( V_119 [ 0 ] ) } ,
{ . V_62 = V_119 [ 1 ] , . V_59 = sizeof( V_119 [ 1 ] ) } ,
} ;
struct V_100 * V_102 = & V_120 [ 0 ] , * V_103 = & V_120 [ 1 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
int V_16 ;
struct V_87 V_121 [ V_122 ] ;
int V_123 ;
char * V_124 ;
T_2 V_68 ;
struct V_63 V_107 , V_108 ;
struct V_54 V_55 ;
struct V_43 * V_50 ;
V_123 = F_40 ( V_19 ) ;
if ( V_123 < 0 ) {
F_3 ( L_55 ,
strerror ( V_10 ) ) ;
goto V_125;
}
V_124 = F_41 ( V_123 ) ;
if ( V_124 == NULL ) {
F_3 ( L_56 ) ;
goto V_126;
}
printf ( L_57 , V_2 -> V_9 , V_124 ) ;
F_3 ( L_57 , V_2 -> V_9 , V_124 ) ;
V_16 = F_42 ( V_123 ) ;
if ( V_16 < 0 ) {
F_3 ( L_58 ,
V_124 , strerror ( V_10 ) ) ;
goto V_126;
}
V_16 = F_43 ( V_123 ) ;
if ( V_16 < 0 ) {
F_3 ( L_59 ,
V_124 , strerror ( V_10 ) ) ;
goto V_126;
}
V_121 [ V_127 ] . V_15 = V_123 ;
V_121 [ V_127 ] . V_89 = V_90 ;
V_121 [ V_128 ] . V_15 = V_2 -> V_35 . V_129 ;
V_121 [ V_128 ] . V_89 = V_90 ;
if ( V_84 == F_23 ( V_2 , V_2 -> V_35 . V_129 ,
V_34 , & V_107 , & V_108 ,
V_130 . V_114 . V_75 ) ) {
F_3 ( L_37 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
goto V_126;
}
V_55 . V_57 = 1 ;
V_50 = F_12 ( V_2 , V_34 ) ;
for (; ; ) {
V_121 [ V_127 ] . V_91 = 0 ;
V_121 [ V_128 ] . V_91 = 0 ;
V_16 = F_30 ( V_121 , V_122 , - 1 ) ;
if ( V_16 < 0 ) {
F_3 ( L_60 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
continue;
}
if ( ! ( V_50 -> V_88 & V_92 ) )
F_29 ( V_2 ,
V_2 -> V_35 . V_129 ,
V_34 ) ;
if ( V_121 [ V_127 ] . V_91 & V_90 ) {
V_55 . V_58 = V_102 ;
V_68 = F_36 ( V_123 , V_55 . V_58 , V_55 . V_57 ) ;
if ( V_68 > 0 ) {
#ifdef F_32
F_18 ( V_2 , V_55 , V_12 , __LINE__ ) ;
F_3 ( L_41 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_68 ) ;
#endif
F_31 ( V_2 , & V_107 ) ;
F_21 ( V_34 , 1 , & V_107 ,
& V_55 , V_68 ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_35 . V_129 ,
& V_107 , & V_55 ) ;
if ( V_16 < 0 ) {
F_3 ( L_42 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
}
if ( ! V_16 )
F_17 ( V_2 , & V_55 ) ;
#ifdef F_32
F_18 ( V_2 , V_55 , V_12 , __LINE__ ) ;
F_3 ( L_43 ,
V_2 -> V_9 , V_12 , __LINE__ ,
F_16 ( V_55 ) ) ;
#endif
V_102 -> V_59 = V_47 ;
} else if ( V_68 < 0 ) {
F_18 ( V_2 , & V_55 , V_12 , __LINE__ ) ;
F_3 ( L_44 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
F_3 ( L_45 ,
V_55 . V_57 , F_16 ( & V_55 ) ) ;
}
}
if ( V_121 [ V_128 ] . V_91 & V_90 ) {
while ( V_108 . V_65 -> V_66 !=
F_15 ( V_108 . V_64 . V_93 -> V_94 ) ) {
V_55 . V_58 = V_103 ;
F_21 ( V_34 , 0 , & V_108 ,
& V_55 , V_47 ) ;
V_16 = F_22 ( V_2 ,
V_2 -> V_35 . V_129 ,
& V_108 , & V_55 ) ;
if ( ! V_16 ) {
V_103 -> V_59 = V_55 . V_60 ;
F_17 ( V_2 , & V_55 ) ;
#ifdef F_32
F_18 ( V_2 , V_55 , V_12 ,
__LINE__ ) ;
F_3 ( L_48 ,
V_2 -> V_9 , V_12 , __LINE__ ) ;
F_3 ( L_49 ,
F_16 ( V_55 ) ) ;
#endif
V_68 = F_37 ( V_123 ,
V_55 . V_58 , V_55 . V_57 ) ;
if ( V_68 != F_16 ( & V_55 ) ) {
F_3 ( L_50 ,
strerror ( V_10 ) ) ;
F_3 ( L_51 , V_68 ) ;
F_3 ( L_52 ,
F_16 ( & V_55 ) ) ;
} else {
#ifdef F_32
F_18 ( V_2 , V_55 , V_12 ,
__LINE__ ) ;
F_3 ( L_48 ,
V_2 -> V_9 , V_12 ,
__LINE__ ) ;
F_3 ( L_53 ,
V_68 ) ;
#endif
}
} else {
F_3 ( L_42 ,
V_2 -> V_9 , V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
break;
}
}
}
if ( V_121 [ V_110 ] . V_91 & V_118 )
F_3 ( L_54 , V_12 , V_2 -> V_9 ) ;
}
V_126:
F_9 ( V_123 ) ;
V_125:
F_38 ( NULL ) ;
}
static void
F_44 ( struct V_1 * V_2 , struct V_43 * V_114 )
{
char V_131 [ V_132 ] ;
int V_15 , V_16 ;
snprintf ( V_131 , V_132 , L_61 , V_2 -> V_11 ) ;
V_15 = F_7 ( V_131 , V_19 ) ;
if ( V_15 < 0 ) {
F_3 ( L_62 , V_131 , strerror ( V_10 ) ) ;
return;
}
V_16 = F_8 ( V_15 , V_133 , V_114 ) ;
if ( V_16 < 0 ) {
F_3 ( L_63 , V_114 -> type , strerror ( V_10 ) ) ;
F_9 ( V_15 ) ;
return;
}
switch ( V_114 -> type ) {
case V_37 :
V_2 -> V_38 . V_111 = V_15 ;
F_3 ( L_64 , V_2 -> V_9 ) ;
break;
case V_34 :
V_2 -> V_35 . V_129 = V_15 ;
F_3 ( L_65 , V_2 -> V_9 ) ;
break;
case V_40 :
V_2 -> V_41 . V_134 = V_15 ;
F_3 ( L_66 , V_2 -> V_9 ) ;
break;
}
}
static bool
F_45 ( struct V_1 * V_2 )
{
T_4 * V_135 ;
char V_136 [ V_132 ] , * line , * V_137 , * V_138 ;
snprintf ( V_136 , V_132 , L_67 , V_139 , V_2 -> V_11 ) ;
V_135 = fopen ( V_136 , L_68 ) ;
if ( V_135 == NULL )
return false ;
do {
line = fgets ( V_136 , V_132 , V_135 ) ;
if ( line == NULL )
break;
if ( * line == '#' )
continue;
V_138 = strchr ( line , '\n' ) ;
if ( V_138 )
* V_138 = '\0' ;
} while ( strncmp ( line , V_140 , strlen ( V_140 ) ) != 0 );
fclose ( V_135 ) ;
if ( line == NULL )
return false ;
V_137 = strchr ( line , '=' ) ;
if ( V_137 == NULL )
return false ;
V_2 -> V_41 . V_141 = malloc ( strlen ( V_137 ) + 1 ) ;
if ( V_2 -> V_41 . V_141 == NULL ) {
F_3 ( L_69 , V_2 -> V_9 , V_2 -> V_11 ) ;
return false ;
}
strcpy ( V_2 -> V_41 . V_141 , V_137 + 1 ) ;
return true ;
}
static bool
F_46 ( struct V_1 * V_2 )
{
V_2 -> V_41 . V_142 = F_47 ( V_2 -> V_41 . V_143 , 0 ,
V_144 ) ;
if ( V_2 -> V_41 . V_142 < 0 ) {
F_3 ( L_70 ,
V_2 -> V_9 , V_2 -> V_41 . V_141 ) ;
return false ;
}
V_145 . V_146 . V_147 =
V_2 -> V_41 . V_142 / V_148 ;
if ( ( V_2 -> V_41 . V_142 % V_148 ) != 0 )
V_145 . V_146 . V_147 ++ ;
V_145 . V_146 . V_147 =
F_48 ( V_145 . V_146 . V_147 ) ;
return true ;
}
static bool
F_49 ( struct V_1 * V_2 )
{
if ( ! F_45 ( V_2 ) )
goto V_149;
V_2 -> V_41 . V_143 = F_7 ( V_2 -> V_41 . V_141 , V_19 ) ;
if ( V_2 -> V_41 . V_143 < 0 ) {
F_3 ( L_71 , V_2 -> V_9 ,
V_2 -> V_41 . V_141 ) ;
goto V_150;
}
if ( ! F_46 ( V_2 ) )
goto V_151;
V_2 -> V_41 . V_152 = F_26 ( NULL ,
V_2 -> V_41 . V_142 ,
V_82 | V_153 , V_83 ,
V_2 -> V_41 . V_143 , 0L ) ;
if ( V_2 -> V_41 . V_152 == V_84 ) {
F_3 ( L_72 ,
V_2 -> V_9 , V_2 -> V_41 . V_141 ,
strerror ( V_10 ) ) ;
goto V_151;
}
return true ;
V_151:
F_9 ( V_2 -> V_41 . V_143 ) ;
V_150:
free ( V_2 -> V_41 . V_141 ) ;
V_149:
return false ;
}
static void
F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_41 . V_152 , V_2 -> V_41 . V_142 ) ;
F_9 ( V_2 -> V_41 . V_143 ) ;
free ( V_2 -> V_41 . V_141 ) ;
}
static bool
F_52 ( struct V_1 * V_2 , struct V_63 * V_154 )
{
if ( ( ( unsigned long ) & V_145 . V_146 % 8 ) != 0 ) {
F_3 ( L_73 ,
V_2 -> V_9 ) ;
return false ;
}
F_44 ( V_2 , & V_145 . V_114 ) ;
if ( V_84 == F_23 ( V_2 , V_2 -> V_41 . V_134 ,
V_40 , V_154 , NULL ,
V_145 . V_114 . V_75 ) ) {
F_3 ( L_37 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
return false ;
}
return true ;
}
static void
F_53 ( struct V_1 * V_2 )
{
int V_76 , V_8 ;
V_76 = F_24 ( F_25 ( V_78 ,
V_79 ) + sizeof( struct V_80 ) ) ;
V_8 = F_51 ( V_2 -> V_41 . V_42 ,
V_81 + V_76 * V_145 . V_114 . V_75 ) ;
if ( V_8 < 0 )
F_3 ( L_74 , V_2 -> V_9 , V_10 ) ;
F_9 ( V_2 -> V_41 . V_134 ) ;
}
static V_48
F_54 ( struct V_49 * V_50 )
{
if ( F_28 ( V_50 -> V_68 ) != sizeof( struct V_155 ) ) {
F_3 ( L_75 ,
V_12 , __LINE__ ) ;
return - V_156 ;
}
if ( ! ( F_15 ( V_50 -> V_52 ) & V_53 ) ) {
F_3 ( L_76 ,
V_12 , __LINE__ ) ;
return - V_156 ;
}
if ( F_15 ( V_50 -> V_52 ) & V_157 ) {
F_3 ( L_77 ,
V_12 , __LINE__ ) ;
return - V_156 ;
}
return 0 ;
}
static int
F_55 ( int V_15 , struct V_155 * V_115 , T_5 V_158 )
{
struct V_100 V_100 ;
struct V_54 V_55 ;
V_100 . V_59 = sizeof( * V_115 ) ;
V_100 . V_62 = V_115 ;
V_55 . V_58 = & V_100 ;
V_55 . V_57 = 1 ;
V_55 . V_69 = 0 ;
V_55 . V_70 = false ;
return F_8 ( V_15 , V_72 , & V_55 ) ;
}
static int
F_56 ( int V_15 , struct V_100 * V_100 , T_5 V_57 )
{
struct V_54 V_55 ;
V_55 . V_58 = V_100 ;
V_55 . V_57 = V_57 ;
V_55 . V_69 = 0 ;
V_55 . V_70 = false ;
return F_8 ( V_15 , V_72 , & V_55 ) ;
}
static V_48
F_57 ( struct V_49 * V_50 )
{
if ( F_28 ( V_50 -> V_68 ) != sizeof( V_48 ) ) {
F_3 ( L_78 ,
V_12 , __LINE__ ) ;
return - V_156 ;
}
return 0 ;
}
static int
F_58 ( int V_15 , V_48 * V_88 )
{
struct V_100 V_100 ;
struct V_54 V_55 ;
V_100 . V_62 = V_88 ;
V_100 . V_59 = sizeof( * V_88 ) ;
V_55 . V_58 = & V_100 ;
V_55 . V_57 = 1 ;
V_55 . V_69 = 0 ;
V_55 . V_70 = true ;
return F_8 ( V_15 , V_72 , & V_55 ) ;
}
static void *
F_59 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
int V_8 ;
struct V_87 V_159 ;
struct V_63 V_154 ;
T_3 V_66 ;
T_5 V_158 ;
struct V_49 * V_50 ;
struct V_100 * V_100 , * V_160 ;
V_48 V_88 ;
T_5 V_161 ;
struct V_155 V_115 ;
void * V_162 ;
for (; ; ) {
if ( ! F_49 ( V_2 ) ) {
for ( V_2 -> V_41 . V_163 = 0 ;
! V_2 -> V_41 . V_163 ; )
F_60 ( 1 ) ;
continue;
}
if ( ! F_52 ( V_2 , & V_154 ) )
goto V_164;
V_100 = malloc ( sizeof( * V_100 ) *
F_28 ( V_145 . V_146 . V_165 ) ) ;
if ( ! V_100 ) {
F_3 ( L_79 ,
V_2 -> V_9 , strerror ( V_166 ) ) ;
goto V_167;
}
V_159 . V_15 = V_2 -> V_41 . V_134 ;
V_159 . V_89 = V_90 ;
for ( V_2 -> V_41 . V_163 = 0 ;
! V_2 -> V_41 . V_163 ; ) {
V_159 . V_91 = 0 ;
V_8 = F_30 ( & V_159 , 1 , 1000 ) ;
if ( V_8 < 0 ) {
F_3 ( L_60 ,
V_12 , __LINE__ ,
strerror ( V_10 ) ) ;
continue;
}
if ( ! ( V_159 . V_91 & V_90 ) ) {
#ifdef F_32
F_3 ( L_80 ,
V_12 , __LINE__ , V_159 . V_91 ) ;
#endif
continue;
}
while ( V_154 . V_65 -> V_66 !=
F_15 ( V_154 . V_64 . V_93 -> V_94 ) ) {
V_66 =
V_154 . V_65 -> V_66 &
( V_154 . V_64 . V_168 - 1 ) ;
V_158 = F_15 (
V_154 . V_64 . V_93 -> V_169 [ V_66 ] ) ;
V_50 = & V_154 . V_64 . V_50 [ V_158 ] ;
#ifdef F_32
F_3 ( L_81 ,
V_12 , __LINE__ ,
V_154 . V_65 -> V_66 ) ;
F_3 ( L_82 ,
V_154 . V_64 . V_168 , V_50 ) ;
#endif
V_88 = F_54 ( V_50 ) ;
V_8 = F_55 (
V_2 -> V_41 . V_134 ,
& V_115 , V_158 ) ;
if ( V_8 < 0 ) {
F_3 ( L_83 ,
V_12 , __LINE__ ,
V_2 -> V_9 , V_8 ,
strerror ( V_10 ) ) ;
break;
}
V_160 = V_100 ;
V_88 = 0 ;
V_162 = V_2 -> V_41 . V_152 +
( V_115 . V_170 * V_148 ) ;
V_161 = F_14 ( V_50 ) ;
V_158 = V_161 ;
for ( V_50 = & V_154 . V_64 . V_50 [ V_161 ] ;
V_50 -> V_52 & V_53 ;
V_158 = F_14 ( V_50 ) ,
V_50 = & V_154 . V_64 . V_50 [ V_158 ] ) {
V_160 -> V_59 = V_50 -> V_68 ;
V_160 -> V_62 = V_162 ;
V_160 ++ ;
V_162 += V_50 -> V_68 ;
}
if ( V_115 . type & ~ ( V_171 |
V_172 ) ) {
F_3 ( L_84 ,
V_12 , __LINE__ ,
V_115 . type ) ;
F_3 ( L_85 ) ;
V_88 = - V_173 ;
} else {
V_8 = F_56 (
V_2 -> V_41 . V_134 ,
V_100 ,
V_160 - V_100 ) ;
if ( V_8 < 0 &&
V_88 != 0 )
V_88 = V_8 ;
}
if ( V_88 != 0 )
V_88 = F_57 ( V_50 ) ;
V_8 = F_58 (
V_2 -> V_41 . V_134 ,
& V_88 ) ;
#ifdef F_32
F_3 ( L_86 ,
V_12 , __LINE__ ,
V_88 , V_50 ) ;
#endif
}
}
free ( V_100 ) ;
V_167:
F_53 ( V_2 ) ;
V_164:
F_50 ( V_2 ) ;
}
F_38 ( NULL ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
#define F_62 120
int V_45 = F_62 ;
F_63 ( V_2 -> V_9 , L_87 , L_88 ) ;
while ( V_45 ) {
char * V_174 ;
V_174 = F_64 ( V_2 -> V_9 , L_87 ) ;
if ( ! V_174 )
goto V_175;
F_3 ( L_89 ,
V_2 -> V_9 , V_12 , __LINE__ , V_174 ) ;
if ( ( ! strcmp ( V_174 , L_90 ) ) ||
( ! strcmp ( V_174 , L_91 ) ) ) {
free ( V_174 ) ;
break;
}
free ( V_174 ) ;
V_175:
F_60 ( 1 ) ;
V_45 -- ;
}
}
static int
F_65 ( struct V_1 * V_2 , char * V_176 )
{
if ( ! strcmp ( V_176 , L_92 ) )
return V_177 ;
if ( ! strcmp ( V_176 , L_93 ) )
return V_178 ;
if ( ! strcmp ( V_176 , L_94 ) )
return V_179 ;
if ( ! strcmp ( V_176 , L_95 ) )
return V_180 ;
if ( ! strcmp ( V_176 , L_96 ) )
return V_181 ;
F_3 ( L_97 , V_2 -> V_9 , V_176 ) ;
assert ( 0 ) ;
}
static int F_66 ( struct V_1 * V_2 , char * V_174 )
{
if ( ! strcmp ( V_174 , L_90 ) )
return V_182 ;
if ( ! strcmp ( V_174 , L_98 ) )
return V_183 ;
if ( ! strcmp ( V_174 , L_99 ) )
return V_184 ;
if ( ! strcmp ( V_174 , L_100 ) )
return V_185 ;
if ( ! strcmp ( V_174 , L_101 ) )
return V_186 ;
if ( ! strcmp ( V_174 , L_91 ) )
return V_187 ;
F_3 ( L_102 , V_2 -> V_9 , V_174 ) ;
assert ( 0 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
#define F_68 60
int V_45 = F_68 , V_8 , V_188 = 0 ;
char * V_176 ;
while ( V_45 ) {
V_176 = F_64 ( V_2 -> V_9 , L_103 ) ;
if ( ! V_176 )
continue;
F_3 ( L_104 ,
V_2 -> V_9 , V_12 , __LINE__ , V_176 ) ;
switch ( F_65 ( V_2 , V_176 ) ) {
case V_181 :
V_2 -> V_189 = 1 ;
case V_179 :
case V_180 :
case V_178 :
free ( V_176 ) ;
goto F_61;
default:
break;
}
free ( V_176 ) ;
F_60 ( 1 ) ;
V_45 -- ;
}
F_61:
V_8 = F_69 ( V_2 -> V_4 , V_190 ) ;
F_3 ( L_105 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_2 -> V_4 , V_8 ) ;
if ( ! V_8 ) {
V_8 = F_5 ( V_2 -> V_4 , & V_188 ,
F_70 ( V_188 ) ) ;
F_3 ( L_106 ,
V_2 -> V_9 , V_12 , __LINE__ ,
V_8 , V_2 -> V_4 ) ;
}
if ( V_8 == V_2 -> V_4 )
F_61 ( V_2 ) ;
}
static void *
F_71 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
char * V_174 = NULL ;
char V_191 [ V_132 ] ;
int V_15 , V_8 ;
struct V_87 V_192 [ 1 ] ;
char V_193 [ 4096 ] ;
snprintf ( V_191 , V_132 - 1 , L_107 ,
V_194 , V_2 -> V_9 , L_87 ) ;
V_15 = F_7 ( V_191 , V_195 ) ;
if ( V_15 < 0 ) {
F_3 ( L_108 ,
V_2 -> V_9 , V_191 , strerror ( V_10 ) ) ;
goto error;
}
do {
V_8 = F_47 ( V_15 , 0 , V_196 ) ;
if ( V_8 < 0 ) {
F_3 ( L_109 ,
V_2 -> V_9 , V_191 , strerror ( V_10 ) ) ;
goto V_197;
}
V_8 = F_72 ( V_15 , V_193 , sizeof( V_193 ) ) ;
if ( V_8 < 0 ) {
F_3 ( L_110 ,
V_2 -> V_9 , V_191 , strerror ( V_10 ) ) ;
goto V_197;
}
V_175:
V_174 = F_64 ( V_2 -> V_9 , L_87 ) ;
if ( ! V_174 )
goto V_175;
F_3 ( L_89 ,
V_2 -> V_9 , V_12 , __LINE__ , V_174 ) ;
switch ( F_66 ( V_2 , V_174 ) ) {
case V_184 :
F_67 ( V_2 ) ;
goto V_198;
case V_186 :
V_2 -> V_199 = 1 ;
F_63 ( V_2 -> V_9 , L_87 , L_111 ) ;
F_67 ( V_2 ) ;
goto V_198;
case V_182 :
if ( V_2 -> V_199 ) {
F_63 ( V_2 -> V_9 , L_87 , L_112 ) ;
V_2 -> V_199 = 0 ;
}
break;
default:
break;
}
free ( V_174 ) ;
V_192 [ 0 ] . V_15 = V_15 ;
V_192 [ 0 ] . V_89 = V_118 | V_200 ;
V_8 = F_30 ( V_192 , 1 , - 1 ) ;
if ( V_8 < 0 ) {
F_3 ( L_113 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
goto V_197;
}
} while ( 1 );
V_198:
free ( V_174 ) ;
V_197:
F_9 ( V_15 ) ;
error:
F_73 ( V_2 ) ;
F_38 ( NULL ) ;
}
static void
F_74 ( struct V_1 * V_2 )
{
char V_201 [ V_132 ] ;
int V_68 ;
V_68 = snprintf ( V_201 , V_132 ,
L_114 ) ;
V_68 += snprintf ( V_201 + V_68 , V_132 - V_68 ,
L_115 ) ;
V_68 += snprintf ( V_201 + V_68 , V_132 - V_68 ,
L_116 ,
V_2 -> V_11 ) ;
F_63 ( V_2 -> V_9 , L_117 , V_201 ) ;
F_3 ( L_118 , V_2 -> V_9 , V_201 ) ;
snprintf ( V_201 , V_132 , L_119 , V_2 -> V_11 ) ;
F_3 ( L_120 , V_2 -> V_9 , V_201 ) ;
}
static void
F_75 ( struct V_1 * V_2 )
{
int V_15 ;
T_6 V_68 ;
char V_202 [] = L_121 ;
char * V_203 , * V_204 , V_205 [ 17 ] = { '\0' } ;
V_15 = F_7 ( V_202 , V_195 ) ;
if ( V_15 < 0 ) {
F_3 ( L_122 ,
V_2 -> V_9 , V_10 ) ;
return;
}
V_68 = F_47 ( V_15 , 0 , V_144 ) ;
if ( V_68 < 0 ) {
F_3 ( L_123 ,
V_2 -> V_9 , V_10 ) ;
F_9 ( V_15 ) ;
return;
}
V_203 = F_26 ( NULL , V_68 , V_82 , V_206 , V_15 , 0 ) ;
if ( V_203 == V_84 ) {
F_3 ( L_124 ,
V_2 -> V_9 , V_10 ) ;
F_9 ( V_15 ) ;
return;
}
V_204 = strstr ( V_203 , L_125 ) ;
if ( ! V_204 ) {
F_3 ( L_126 , V_2 -> V_9 , V_10 ) ;
F_51 ( V_203 , V_68 ) ;
F_9 ( V_15 ) ;
return;
}
strncpy ( V_205 , V_204 - 19 , 16 ) ;
F_63 ( V_2 -> V_9 , L_127 , V_205 ) ;
F_3 ( L_128 , V_2 -> V_9 , V_205 ) ;
V_204 = strstr ( V_203 , L_129 ) ;
if ( ! V_204 ) {
F_3 ( L_130 , V_2 -> V_9 , V_10 ) ;
F_51 ( V_203 , V_68 ) ;
F_9 ( V_15 ) ;
return;
}
strncpy ( V_205 , V_204 - 19 , 16 ) ;
F_63 ( V_2 -> V_9 , L_129 , V_205 ) ;
F_3 ( L_131 , V_2 -> V_9 , V_205 ) ;
F_51 ( V_203 , V_68 ) ;
F_9 ( V_15 ) ;
}
static void
F_76 ( int V_207 , T_7 * V_208 , void * V_138 )
{
struct V_1 * V_2 ;
for ( V_2 = V_209 . V_51 ; V_2 != NULL ; V_2 = V_2 -> V_51 )
V_2 -> V_41 . V_163 = 1 ;
}
static void
F_73 ( struct V_1 * V_2 )
{
struct V_210 V_211 = {
. V_212 = 0 ,
. V_213 = V_214
} ;
struct V_210 V_215 = {
. V_212 = V_216 ,
. V_217 = F_76 ,
} ;
char V_201 [ V_132 ] ;
int V_16 ;
V_210 ( V_218 , & V_211 , NULL ) ;
V_2 -> V_4 = F_2 () ;
switch ( V_2 -> V_4 ) {
case 0 :
F_75 ( V_2 ) ;
F_74 ( V_2 ) ;
F_44 ( V_2 , & V_130 . V_114 ) ;
F_44 ( V_2 , & V_113 . V_114 ) ;
V_16 = F_77 ( & V_2 -> V_35 . V_219 , NULL ,
F_39 , V_2 ) ;
if ( V_16 )
F_3 ( L_132 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
V_16 = F_77 ( & V_2 -> V_38 . V_220 , NULL ,
F_34 , V_2 ) ;
if ( V_16 )
F_3 ( L_133 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
V_16 = F_77 ( & V_2 -> V_41 . V_221 , NULL ,
F_59 , V_2 ) ;
if ( V_16 )
F_3 ( L_134 ,
V_2 -> V_9 , strerror ( V_16 ) ) ;
F_78 ( & V_215 . V_222 ) ;
V_16 = V_210 ( V_218 , & V_215 , NULL ) ;
if ( V_16 )
F_3 ( L_135 ,
V_2 -> V_9 , strerror ( V_10 ) ) ;
while ( 1 )
F_60 ( 60 ) ;
case - 1 :
F_3 ( L_136 ,
V_2 -> V_9 , V_2 -> V_11 , V_10 ) ;
break;
default:
if ( V_2 -> V_189 ) {
snprintf ( V_201 , V_132 , L_112 ) ;
F_63 ( V_2 -> V_9 , L_87 , V_201 ) ;
F_3 ( L_137 ,
V_2 -> V_9 , V_2 -> V_189 ) ;
V_2 -> V_189 = 0 ;
}
F_77 ( & V_2 -> V_223 , NULL , F_71 , V_2 ) ;
}
}
static void
F_79 ( void )
{
struct V_1 * V_2 ;
for ( V_2 = V_209 . V_51 ; V_2 != NULL ; V_2 = V_2 -> V_51 )
F_73 ( V_2 ) ;
while ( 1 )
F_60 ( 60 ) ;
}
static int
F_80 ( void )
{
struct V_1 * V_2 = & V_209 ;
struct V_224 * V_225 ;
T_8 * V_33 ;
int V_226 = 0 ;
V_33 = F_81 ( V_194 ) ;
if ( ! V_33 )
return 0 ;
while ( ( V_225 = F_82 ( V_33 ) ) != NULL ) {
if ( ! strncmp ( V_225 -> V_227 , L_138 , 3 ) ) {
V_2 -> V_51 = calloc ( 1 , sizeof( struct V_1 ) ) ;
if ( V_2 -> V_51 ) {
V_2 = V_2 -> V_51 ;
V_2 -> V_11 = atoi ( & V_225 -> V_227 [ 3 ] ) ;
V_2 -> V_9 = malloc ( strlen ( V_225 -> V_227 ) + 16 ) ;
if ( V_2 -> V_9 )
strcpy ( V_2 -> V_9 , V_225 -> V_227 ) ;
F_3 ( L_36 , V_2 -> V_9 ,
V_2 -> V_11 ) ;
V_226 ++ ;
}
}
}
F_83 ( V_33 ) ;
return V_226 ;
}
void
F_3 ( char * V_228 , ... )
{
T_9 args ;
char V_201 [ 4096 ] ;
char V_229 [ 52 ] , * V_230 ;
T_10 V_231 ;
if ( V_232 == NULL )
return;
va_start ( args , V_228 ) ;
vsprintf ( V_201 , V_228 , args ) ;
va_end ( args ) ;
time ( & V_231 ) ;
V_230 = ctime_r ( & V_231 , V_229 ) ;
V_230 [ strlen ( V_230 ) - 1 ] = '\0' ;
fprintf ( V_232 , L_139 , V_230 , V_201 ) ;
fflush ( V_232 ) ;
}
int
main ( int V_233 , char * V_234 [] )
{
int V_226 ;
T_1 V_4 ;
V_235 = V_234 [ 0 ] ;
V_232 = fopen ( V_236 , L_140 ) ;
if ( ! V_232 ) {
fprintf ( V_237 , L_141 , V_236 ) ;
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
F_3 ( L_142 ) ;
V_226 = F_80 () ;
if ( V_226 == 0 ) {
F_3 ( L_143 ) ;
exit ( 3 ) ;
}
F_3 ( L_144 , V_226 ) ;
F_79 () ;
exit ( 0 ) ;
}
