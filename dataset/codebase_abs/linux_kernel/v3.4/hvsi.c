static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 == V_6 )
|| ( V_2 -> V_5 == V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
#ifdef F_4
static const char * V_8 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
} ;
const char * V_9 = ( V_2 -> V_5 < F_5 ( V_8 ) )
? V_8 [ V_2 -> V_5 ] : L_7 ;
F_6 ( L_8 , V_2 -> V_10 , V_9 ) ;
#endif
}
static inline void F_7 ( struct V_1 * V_2 , int V_5 )
{
V_2 -> V_5 = V_5 ;
F_3 ( V_2 ) ;
F_8 ( & V_2 -> V_11 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_5 )
{
unsigned long V_3 ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
F_7 ( V_2 , V_5 ) ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
}
static inline int F_12 ( const T_1 * V_13 )
{
return ( int ) ( (struct V_14 * ) V_13 ) -> V_15 ;
}
static inline int F_13 ( const T_1 * V_13 )
{
struct V_14 * V_16 = (struct V_14 * ) V_13 ;
return V_16 -> type >= V_17 ;
}
static inline int F_14 ( const struct V_1 * V_2 , T_1 * V_13 )
{
if ( V_2 -> V_18 < V_13 + sizeof( struct V_14 ) )
return 0 ;
if ( V_2 -> V_18 < ( V_13 + F_12 ( V_13 ) ) )
return 0 ;
return 1 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 * V_19 )
{
int V_20 = ( int ) ( V_2 -> V_18 - V_19 ) ;
F_6 ( L_9 , V_21 , V_20 ) ;
if ( V_19 != V_2 -> V_22 )
memmove ( V_2 -> V_22 , V_19 , V_20 ) ;
V_2 -> V_18 = V_2 -> V_22 + V_20 ;
}
static void F_16 ( const T_1 * V_23 , int V_15 )
{
int V_24 ;
F_17 ( L_10 ) ;
for ( V_24 = 0 ; V_24 < V_15 ; V_24 ++ )
F_17 ( L_11 , V_23 [ V_24 ] ) ;
F_17 ( L_12 ) ;
for ( V_24 = 0 ; V_24 < V_15 ; V_24 ++ ) {
if ( isprint ( V_23 [ V_24 ] ) )
F_17 ( L_13 , V_23 [ V_24 ] ) ;
else
F_17 ( L_14 ) ;
}
F_17 ( L_15 ) ;
}
static void F_18 ( T_1 * V_13 )
{
struct V_14 * V_16 = (struct V_14 * ) V_13 ;
F_17 ( L_16 , V_16 -> type , V_16 -> V_15 ,
V_16 -> V_25 ) ;
F_16 ( V_13 , V_16 -> V_15 ) ;
}
static int F_19 ( struct V_1 * V_2 , char * V_26 , int V_27 )
{
unsigned long V_28 ;
V_28 = F_20 ( V_2 -> V_29 , V_26 , V_27 ) ;
return V_28 ;
}
static void F_21 ( struct V_1 * V_2 , T_1 * V_13 ,
struct V_30 * * V_31 , struct V_1 * * V_32 )
{
struct V_33 * V_16 = (struct V_33 * ) V_13 ;
switch ( V_16 -> V_34 ) {
case V_35 :
if ( ( V_16 -> V_36 & V_37 ) == 0 ) {
F_6 ( L_17 , V_2 -> V_10 ) ;
V_2 -> V_38 &= V_39 ;
if ( V_2 -> V_40 && ! ( V_2 -> V_40 -> V_3 & V_41 ) )
* V_31 = V_2 -> V_40 ;
}
break;
case V_42 :
F_6 ( L_18 , V_2 -> V_10 ) ;
if ( V_2 -> V_5 != V_43 ) {
* V_32 = V_2 ;
}
break;
default:
F_17 ( V_44 L_19 ,
V_2 -> V_10 ) ;
F_18 ( V_13 ) ;
break;
}
}
static void F_22 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_45 * V_46 = (struct V_45 * ) V_13 ;
switch ( V_2 -> V_5 ) {
case V_47 :
F_7 ( V_2 , V_48 ) ;
break;
case V_7 :
V_2 -> V_38 = 0 ;
if ( V_46 -> V_49 . V_50 & V_51 )
V_2 -> V_38 |= V_52 ;
if ( V_46 -> V_49 . V_50 & V_37 )
V_2 -> V_38 |= V_39 ;
F_7 ( V_2 , V_6 ) ;
break;
default:
F_17 ( V_53 L_20 , V_2 -> V_10 ) ;
F_18 ( V_13 ) ;
break;
}
}
static int F_23 ( struct V_1 * V_2 , T_2 V_54 )
{
struct V_45 V_13 V_55 ;
int V_56 ;
V_13 . V_57 . type = V_17 ;
V_13 . V_57 . V_15 = sizeof( struct V_45 ) ;
V_13 . V_57 . V_25 = F_24 ( & V_2 -> V_25 ) ;
V_13 . V_34 = V_58 ;
V_13 . V_49 . V_59 = V_60 ;
V_13 . V_54 = V_54 + 1 ;
F_6 ( L_21 , V_21 , V_13 . V_57 . V_15 ) ;
F_25 ( ( T_1 * ) & V_13 , V_13 . V_57 . V_15 ) ;
V_56 = F_26 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_57 . V_15 ) ;
if ( V_56 != V_13 . V_57 . V_15 ) {
F_17 ( V_53 L_22 ,
V_2 -> V_10 ) ;
return - V_61 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_62 * V_63 = (struct V_62 * ) V_13 ;
switch ( V_2 -> V_5 ) {
case V_48 :
F_23 ( V_2 , V_63 -> V_57 . V_25 ) ;
F_7 ( V_2 , V_6 ) ;
break;
default:
F_17 ( V_53 L_23 , V_2 -> V_10 ) ;
F_18 ( V_13 ) ;
break;
}
}
static void F_28 ( struct V_1 * V_2 , const char * V_26 , int V_15 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_15 ; V_24 ++ ) {
char V_64 = V_26 [ V_24 ] ;
#ifdef F_29
if ( V_64 == '\0' ) {
V_2 -> V_65 = 1 ;
continue;
} else if ( V_2 -> V_65 ) {
F_30 ( V_64 ) ;
V_2 -> V_65 = 0 ;
continue;
}
#endif
F_31 ( V_2 -> V_40 , V_64 , 0 ) ;
}
}
static struct V_30 * F_32 ( struct V_1 * V_2 ,
const T_1 * V_13 )
{
const struct V_14 * V_16 = ( const struct V_14 * ) V_13 ;
const T_1 * V_23 = V_13 + sizeof( struct V_14 ) ;
int V_66 = V_16 -> V_15 - sizeof( struct V_14 ) ;
int V_67 = V_66 - V_68 ;
F_6 ( L_24 , V_66 , V_66 , V_23 ) ;
if ( V_66 == 0 )
return NULL ;
if ( V_67 > 0 ) {
F_6 ( L_25 , V_21 ) ;
V_66 = V_68 ;
}
F_28 ( V_2 , V_23 , V_66 ) ;
if ( V_67 > 0 ) {
F_6 ( L_26 , V_21 ) ;
memcpy ( V_2 -> V_69 , V_23 + V_68 , V_67 ) ;
V_2 -> V_70 = V_67 ;
}
return V_2 -> V_40 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_30 * * V_71 ,
struct V_30 * * V_72 , struct V_1 * * V_73 )
{
T_1 * V_13 = V_2 -> V_22 ;
int V_74 ;
* V_71 = NULL ;
* V_72 = NULL ;
* V_73 = NULL ;
V_74 = F_19 ( V_2 , V_2 -> V_18 , V_75 ) ;
if ( V_74 == 0 ) {
F_6 ( L_27 , V_21 ) ;
return 0 ;
}
F_6 ( L_28 , V_21 , V_74 ) ;
F_25 ( V_2 -> V_18 , V_74 ) ;
V_2 -> V_18 += V_74 ;
while ( ( V_13 < V_2 -> V_18 ) && F_14 ( V_2 , V_13 ) ) {
struct V_14 * V_16 = (struct V_14 * ) V_13 ;
if ( ! F_13 ( V_13 ) ) {
F_17 ( V_53 L_29 , V_2 -> V_10 ) ;
while ( ( V_13 < V_2 -> V_18 ) && ( ! F_13 ( V_13 ) ) )
V_13 ++ ;
continue;
}
F_6 ( L_30 , V_21 ,
F_12 ( V_13 ) ) ;
F_34 ( V_13 ) ;
switch ( V_16 -> type ) {
case V_76 :
if ( ! F_2 ( V_2 ) )
break;
if ( V_2 -> V_40 == NULL )
break;
* V_71 = F_32 ( V_2 , V_13 ) ;
break;
case V_77 :
F_21 ( V_2 , V_13 , V_72 , V_73 ) ;
break;
case V_17 :
F_22 ( V_2 , V_13 ) ;
break;
case V_78 :
F_27 ( V_2 , V_13 ) ;
break;
default:
F_17 ( V_53 L_31 ,
V_2 -> V_10 , V_16 -> type ) ;
F_18 ( V_13 ) ;
break;
}
V_13 += F_12 ( V_13 ) ;
if ( * V_72 || * V_73 ) {
F_6 ( L_32 , V_21 ) ;
break;
}
}
F_15 ( V_2 , V_13 ) ;
return 1 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_6 ( L_33 , V_21 ,
V_2 -> V_70 ) ;
F_28 ( V_2 , V_2 -> V_69 , V_2 -> V_70 ) ;
V_2 -> V_70 = 0 ;
}
static T_3 F_36 ( int V_79 , void * V_80 )
{
struct V_1 * V_2 = (struct V_1 * ) V_80 ;
struct V_30 * V_71 ;
struct V_30 * V_72 ;
struct V_1 * V_73 ;
unsigned long V_3 ;
int V_81 = 1 ;
F_6 ( L_34 , V_21 ) ;
while ( V_81 ) {
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_81 = F_33 ( V_2 , & V_71 , & V_72 , & V_73 ) ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( V_71 ) {
F_37 ( V_71 ) ;
V_71 = NULL ;
}
if ( V_72 ) {
F_38 ( V_72 ) ;
}
if ( V_73 ) {
F_6 ( L_35 , V_73 -> V_10 ) ;
F_39 ( & V_73 -> V_82 ) ;
}
}
F_10 ( & V_2 -> V_12 , V_3 ) ;
if ( V_2 -> V_40 && V_2 -> V_70
&& ( ! F_40 ( V_83 , & V_2 -> V_40 -> V_3 ) ) ) {
V_71 = V_2 -> V_40 ;
F_35 ( V_2 ) ;
}
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( V_71 ) {
F_37 ( V_71 ) ;
}
return V_84 ;
}
static int T_4 F_41 ( struct V_1 * V_2 , int V_5 )
{
unsigned long V_85 = V_86 + V_87 ;
for (; ; ) {
F_36 ( V_2 -> V_88 , ( void * ) V_2 ) ;
if ( V_2 -> V_5 == V_5 )
return 0 ;
F_42 ( 5 ) ;
if ( F_43 ( V_86 , V_85 ) )
return - V_61 ;
}
}
static int F_44 ( struct V_1 * V_2 , int V_5 )
{
int V_89 = 0 ;
if ( ! F_45 ( V_2 -> V_11 , ( V_2 -> V_5 == V_5 ) , V_87 ) )
V_89 = - V_61 ;
return V_89 ;
}
static int V_62 ( struct V_1 * V_2 , T_2 V_34 )
{
struct V_62 V_13 V_55 ;
int V_56 ;
V_13 . V_57 . type = V_78 ;
V_13 . V_57 . V_15 = sizeof( struct V_62 ) ;
V_13 . V_57 . V_25 = F_24 ( & V_2 -> V_25 ) ;
V_13 . V_34 = V_34 ;
F_6 ( L_21 , V_21 , V_13 . V_57 . V_15 ) ;
F_25 ( ( T_1 * ) & V_13 , V_13 . V_57 . V_15 ) ;
V_56 = F_26 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_57 . V_15 ) ;
if ( V_56 != V_13 . V_57 . V_15 ) {
F_17 ( V_53 L_36 , V_2 -> V_10 ,
V_56 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_89 ;
F_9 ( V_2 , V_7 ) ;
V_62 ( V_2 , V_90 ) ;
V_89 = F_47 ( V_2 , V_6 ) ;
if ( V_89 < 0 ) {
F_17 ( V_53 L_37 , V_2 -> V_10 ) ;
F_9 ( V_2 , V_6 ) ;
return V_89 ;
}
F_6 ( L_38 , V_21 , V_2 -> V_38 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_33 V_13 V_55 ;
int V_56 ;
V_13 . V_57 . type = V_77 ,
V_13 . V_57 . V_25 = F_24 ( & V_2 -> V_25 ) ;
V_13 . V_57 . V_15 = sizeof( struct V_33 ) ;
V_13 . V_34 = V_91 ;
V_13 . V_92 = V_51 ;
if ( V_38 & V_52 )
V_13 . V_36 = V_51 ;
F_6 ( L_21 , V_21 , V_13 . V_57 . V_15 ) ;
F_25 ( ( T_1 * ) & V_13 , V_13 . V_57 . V_15 ) ;
V_56 = F_26 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_57 . V_15 ) ;
if ( V_56 != V_13 . V_57 . V_15 ) {
F_17 ( V_53 L_39 , V_2 -> V_10 ) ;
return - V_61 ;
}
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
T_1 V_26 [ V_75 ] V_55 ;
unsigned long V_85 = V_86 + V_87 ;
while ( F_50 ( V_85 , V_86 ) )
if ( 0 == F_19 ( V_2 , V_26 , V_75 ) )
break;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_89 ;
F_49 ( V_2 ) ;
F_9 ( V_2 , V_47 ) ;
V_89 = V_62 ( V_2 , V_58 ) ;
if ( V_89 < 0 ) {
F_17 ( V_53 L_40 , V_2 -> V_10 ) ;
return V_89 ;
}
V_89 = F_47 ( V_2 , V_6 ) ;
if ( V_89 < 0 )
return V_89 ;
return 0 ;
}
static void F_52 ( struct V_93 * V_94 )
{
struct V_1 * V_2 =
F_53 ( V_94 , struct V_1 , V_82 ) ;
if ( F_51 ( V_2 ) >= 0 )
return;
F_17 ( V_53 L_41 , V_2 -> V_10 ) ;
if ( F_1 ( V_2 ) ) {
F_17 ( V_53 L_42 , V_2 -> V_10 ) ;
}
}
static int F_54 ( struct V_1 * V_2 , const char * V_26 , int V_27 )
{
struct V_95 V_13 V_55 ;
int V_89 ;
F_55 ( V_27 > V_96 ) ;
V_13 . V_57 . type = V_76 ;
V_13 . V_57 . V_25 = F_24 ( & V_2 -> V_25 ) ;
V_13 . V_57 . V_15 = V_27 + sizeof( struct V_14 ) ;
memcpy ( & V_13 . V_23 , V_26 , V_27 ) ;
V_89 = F_26 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_57 . V_15 ) ;
if ( V_89 == V_13 . V_57 . V_15 ) {
return V_27 ;
}
return V_89 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_33 V_13 V_55 ;
V_13 . V_57 . type = V_77 ;
V_13 . V_57 . V_25 = F_24 ( & V_2 -> V_25 ) ;
V_13 . V_57 . V_15 = 6 ;
V_13 . V_34 = V_42 ;
F_6 ( L_21 , V_21 , V_13 . V_57 . V_15 ) ;
F_25 ( ( T_1 * ) & V_13 , V_13 . V_57 . V_15 ) ;
F_26 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_57 . V_15 ) ;
}
static int F_57 ( struct V_30 * V_40 , struct V_97 * V_98 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
int V_89 ;
F_6 ( L_34 , V_21 ) ;
V_2 = & V_99 [ V_40 -> V_10 ] ;
V_40 -> V_100 = V_2 ;
F_58 () ;
if ( V_2 -> V_5 == V_101 )
return - V_61 ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_27 ++ ;
F_59 ( & V_2 -> V_25 , 0 ) ;
F_60 ( V_2 -> V_29 , V_102 ) ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( F_1 ( V_2 ) )
return 0 ;
V_89 = F_51 ( V_2 ) ;
if ( V_89 < 0 ) {
F_17 ( V_53 L_43 , V_40 -> V_9 ) ;
return V_89 ;
}
V_89 = F_46 ( V_2 ) ;
if ( V_89 < 0 ) {
F_17 ( V_53 L_44 , V_40 -> V_9 ) ;
return V_89 ;
}
V_89 = F_48 ( V_2 , V_2 -> V_38 | V_52 ) ;
if ( V_89 < 0 ) {
F_17 ( V_53 L_45 , V_40 -> V_9 ) ;
return V_89 ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_45 ( V_2 -> V_103 , ( V_2 -> V_104 <= 0 ) , V_87 ) ;
F_62 ( & V_2 -> V_105 ) ;
F_63 ( & V_2 -> V_82 ) ;
V_2 -> V_104 = 0 ;
}
static void F_64 ( struct V_30 * V_40 , struct V_97 * V_98 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
unsigned long V_3 ;
F_6 ( L_34 , V_21 ) ;
if ( F_65 ( V_98 ) )
return;
F_10 ( & V_2 -> V_12 , V_3 ) ;
if ( -- V_2 -> V_27 == 0 ) {
V_2 -> V_40 = NULL ;
V_2 -> V_18 = V_2 -> V_22 ;
if ( ! F_1 ( V_2 ) ) {
F_60 ( V_2 -> V_29 , V_106 ) ;
F_7 ( V_2 , V_43 ) ;
V_40 -> V_107 = 1 ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
F_66 ( V_2 -> V_88 ) ;
F_61 ( V_2 ) ;
F_56 ( V_2 ) ;
F_49 ( V_2 ) ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
}
} else if ( V_2 -> V_27 < 0 )
F_17 ( V_53 L_46 ,
V_2 - V_99 , V_2 -> V_27 ) ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
}
static void F_67 ( struct V_30 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
unsigned long V_3 ;
F_6 ( L_34 , V_21 ) ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_104 = 0 ;
V_2 -> V_40 = NULL ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
int V_108 ;
if ( V_2 -> V_104 <= 0 )
return;
V_108 = F_54 ( V_2 , V_2 -> V_109 , V_2 -> V_104 ) ;
if ( V_108 > 0 ) {
F_6 ( L_47 , V_21 , V_108 ) ;
V_2 -> V_104 = 0 ;
} else if ( V_108 == - V_61 ) {
F_7 ( V_2 , V_101 ) ;
F_17 ( V_53 L_48 , V_2 -> V_10 ) ;
}
}
static void F_69 ( struct V_93 * V_94 )
{
struct V_1 * V_2 =
F_53 ( V_94 , struct V_1 , V_105 . V_94 ) ;
unsigned long V_3 ;
#ifdef F_4
static long V_110 = 0 ;
if ( V_110 == 0 )
V_110 = V_86 ;
#endif
F_10 ( & V_2 -> V_12 , V_3 ) ;
F_6 ( L_49 , V_21 , V_2 -> V_104 ) ;
if ( ! F_2 ( V_2 ) ) {
F_70 ( & V_2 -> V_105 , V_111 ) ;
goto V_112;
}
F_68 ( V_2 ) ;
if ( V_2 -> V_104 > 0 )
F_70 ( & V_2 -> V_105 , 10 ) ;
else {
#ifdef F_4
F_6 ( L_50 , V_21 ,
V_86 - V_110 ) ;
V_110 = 0 ;
#endif
F_8 ( & V_2 -> V_103 ) ;
F_71 ( V_2 -> V_40 ) ;
}
V_112:
F_11 ( & V_2 -> V_12 , V_3 ) ;
}
static int F_72 ( struct V_30 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
return V_113 - V_2 -> V_104 ;
}
static int F_73 ( struct V_30 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
return V_2 -> V_104 ;
}
static int F_74 ( struct V_30 * V_40 ,
const unsigned char * V_26 , int V_27 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
const char * V_114 = V_26 ;
unsigned long V_3 ;
int V_115 = 0 ;
int V_116 = V_27 ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
F_6 ( L_49 , V_21 , V_2 -> V_104 ) ;
if ( ! F_2 ( V_2 ) ) {
F_6 ( L_51 , V_21 ) ;
goto V_112;
}
while ( ( V_27 > 0 ) && ( F_72 ( V_2 -> V_40 ) > 0 ) ) {
int V_117 = F_75 ( V_27 , F_72 ( V_2 -> V_40 ) ) ;
F_55 ( V_2 -> V_104 < 0 ) ;
memcpy ( V_2 -> V_109 + V_2 -> V_104 , V_114 , V_117 ) ;
V_2 -> V_104 += V_117 ;
V_115 += V_117 ;
V_114 += V_117 ;
V_27 -= V_117 ;
F_68 ( V_2 ) ;
}
if ( V_2 -> V_104 > 0 ) {
F_70 ( & V_2 -> V_105 , 10 ) ;
}
V_112:
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( V_115 != V_116 )
F_6 ( L_52 , V_21 , V_116 ,
V_115 ) ;
return V_115 ;
}
static void F_76 ( struct V_30 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
F_6 ( L_34 , V_21 ) ;
F_60 ( V_2 -> V_29 , V_106 ) ;
}
static void F_77 ( struct V_30 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
unsigned long V_3 ;
int V_118 = 0 ;
F_6 ( L_34 , V_21 ) ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
if ( V_2 -> V_70 ) {
F_35 ( V_2 ) ;
V_118 = 1 ;
}
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( V_118 )
F_37 ( V_2 -> V_40 ) ;
F_60 ( V_2 -> V_29 , V_102 ) ;
}
static int F_78 ( struct V_30 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
F_46 ( V_2 ) ;
return V_2 -> V_38 ;
}
static int F_79 ( struct V_30 * V_40 ,
unsigned int V_119 , unsigned int V_120 )
{
struct V_1 * V_2 = V_40 -> V_100 ;
unsigned long V_3 ;
T_2 V_121 ;
V_120 &= V_52 ;
V_119 &= V_52 ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_121 = ( V_2 -> V_38 & ~ V_120 ) | V_119 ;
if ( V_2 -> V_38 != V_121 ) {
F_48 ( V_2 , V_121 ) ;
V_2 -> V_38 = V_121 ;
}
F_11 ( & V_2 -> V_12 , V_3 ) ;
return 0 ;
}
static int T_4 F_80 ( void )
{
int V_24 ;
V_122 = F_81 ( V_123 ) ;
if ( ! V_122 )
return - V_124 ;
V_122 -> V_125 = L_53 ;
V_122 -> V_9 = L_53 ;
V_122 -> V_126 = V_127 ;
V_122 -> V_128 = V_129 ;
V_122 -> type = V_130 ;
V_122 -> V_131 = V_132 ;
V_122 -> V_131 . V_133 = V_134 | V_135 | V_136 | V_137 ;
V_122 -> V_131 . V_138 = 9600 ;
V_122 -> V_131 . V_139 = 9600 ;
V_122 -> V_3 = V_140 ;
F_82 ( V_122 , & V_141 ) ;
for ( V_24 = 0 ; V_24 < V_123 ; V_24 ++ ) {
struct V_1 * V_2 = & V_99 [ V_24 ] ;
int V_89 = 1 ;
V_89 = F_83 ( V_2 -> V_88 , F_36 , 0 , L_53 , V_2 ) ;
if ( V_89 )
F_17 ( V_53 L_54 ,
V_2 -> V_88 , V_89 ) ;
}
F_47 = F_44 ;
if ( F_84 ( V_122 ) )
F_85 ( L_55 ) ;
F_17 ( V_142 L_56 , V_123 ) ;
return 0 ;
}
static void F_86 ( struct V_143 * V_143 , const char * V_26 ,
unsigned int V_27 )
{
struct V_1 * V_2 = & V_99 [ V_143 -> V_10 ] ;
char V_64 [ V_96 ] V_55 ;
unsigned int V_24 = 0 , V_108 = 0 ;
int V_89 , V_144 = 0 ;
F_58 () ;
if ( ! F_2 ( V_2 ) )
return;
while ( V_27 > 0 || V_24 > 0 ) {
if ( V_27 > 0 && V_24 < sizeof( V_64 ) ) {
if ( V_26 [ V_108 ] == '\n' && ! V_144 ) {
V_64 [ V_24 ++ ] = '\r' ;
V_144 = 1 ;
} else {
V_64 [ V_24 ++ ] = V_26 [ V_108 ++ ] ;
V_144 = 0 ;
-- V_27 ;
}
} else {
V_89 = F_54 ( V_2 , V_64 , V_24 ) ;
if ( V_89 < 0 )
V_24 = 0 ;
V_24 -= V_89 ;
}
}
}
static struct V_145 * F_87 ( struct V_143 * V_143 ,
int * V_10 )
{
* V_10 = V_143 -> V_10 ;
return V_122 ;
}
static int T_4 F_88 ( struct V_143 * V_143 , char * V_146 )
{
struct V_1 * V_2 ;
int V_89 ;
if ( V_143 -> V_10 < 0 || V_143 -> V_10 >= V_123 )
return - 1 ;
V_2 = & V_99 [ V_143 -> V_10 ] ;
F_56 ( V_2 ) ;
V_89 = F_51 ( V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_46 ( V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_48 ( V_2 , V_2 -> V_38 | V_52 ) ;
if ( V_89 < 0 )
return V_89 ;
V_2 -> V_3 |= V_4 ;
return 0 ;
}
static int T_4 F_89 ( void )
{
struct V_147 * V_148 ;
F_47 = F_41 ;
for ( V_148 = F_90 ( NULL , L_57 , L_58 ) ;
V_148 != NULL ;
V_148 = F_90 ( V_148 , L_57 , L_58 ) ) {
struct V_1 * V_2 ;
const T_5 * V_29 , * V_79 ;
V_29 = F_91 ( V_148 , L_59 , NULL ) ;
V_79 = F_91 ( V_148 , L_60 , NULL ) ;
if ( ! V_29 || ! V_79 )
continue;
if ( V_123 >= V_149 ) {
F_92 ( V_148 ) ;
break;
}
V_2 = & V_99 [ V_123 ] ;
F_93 ( & V_2 -> V_105 , F_69 ) ;
F_94 ( & V_2 -> V_82 , F_52 ) ;
F_95 ( & V_2 -> V_103 ) ;
F_95 ( & V_2 -> V_11 ) ;
F_96 ( & V_2 -> V_12 ) ;
V_2 -> V_10 = V_123 ;
V_2 -> V_18 = V_2 -> V_22 ;
V_2 -> V_5 = V_43 ;
V_2 -> V_29 = * V_29 ;
V_2 -> V_88 = F_97 ( NULL , V_79 [ 0 ] ) ;
if ( V_2 -> V_88 == 0 ) {
F_17 ( V_53 L_61 ,
V_21 , V_79 [ 0 ] ) ;
continue;
}
V_123 ++ ;
}
if ( V_123 )
F_98 ( & V_150 ) ;
return 0 ;
}
