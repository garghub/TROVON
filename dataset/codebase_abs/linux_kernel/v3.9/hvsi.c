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
struct V_30 * V_31 , struct V_1 * * V_32 )
{
struct V_33 * V_16 = (struct V_33 * ) V_13 ;
switch ( V_16 -> V_34 ) {
case V_35 :
if ( ( V_16 -> V_36 & V_37 ) == 0 ) {
F_6 ( L_17 , V_2 -> V_10 ) ;
V_2 -> V_38 &= V_39 ;
if ( V_31 && ! F_22 ( V_31 ) )
F_23 ( V_31 ) ;
}
break;
case V_40 :
F_6 ( L_18 , V_2 -> V_10 ) ;
if ( V_2 -> V_5 != V_41 ) {
* V_32 = V_2 ;
}
break;
default:
F_17 ( V_42 L_19 ,
V_2 -> V_10 ) ;
F_18 ( V_13 ) ;
break;
}
}
static void F_24 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_43 * V_44 = (struct V_43 * ) V_13 ;
switch ( V_2 -> V_5 ) {
case V_45 :
F_7 ( V_2 , V_46 ) ;
break;
case V_7 :
V_2 -> V_38 = 0 ;
if ( V_44 -> V_47 . V_48 & V_49 )
V_2 -> V_38 |= V_50 ;
if ( V_44 -> V_47 . V_48 & V_37 )
V_2 -> V_38 |= V_39 ;
F_7 ( V_2 , V_6 ) ;
break;
default:
F_17 ( V_51 L_20 , V_2 -> V_10 ) ;
F_18 ( V_13 ) ;
break;
}
}
static int F_25 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_43 V_13 V_53 ;
int V_54 ;
V_13 . V_55 . type = V_17 ;
V_13 . V_55 . V_15 = sizeof( struct V_43 ) ;
V_13 . V_55 . V_25 = F_26 ( & V_2 -> V_25 ) ;
V_13 . V_34 = V_56 ;
V_13 . V_47 . V_57 = V_58 ;
V_13 . V_52 = V_52 + 1 ;
F_6 ( L_21 , V_21 , V_13 . V_55 . V_15 ) ;
F_27 ( ( T_1 * ) & V_13 , V_13 . V_55 . V_15 ) ;
V_54 = F_28 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_55 . V_15 ) ;
if ( V_54 != V_13 . V_55 . V_15 ) {
F_17 ( V_51 L_22 ,
V_2 -> V_10 ) ;
return - V_59 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_60 * V_61 = (struct V_60 * ) V_13 ;
switch ( V_2 -> V_5 ) {
case V_46 :
F_25 ( V_2 , V_61 -> V_55 . V_25 ) ;
F_7 ( V_2 , V_6 ) ;
break;
default:
F_17 ( V_51 L_23 , V_2 -> V_10 ) ;
F_18 ( V_13 ) ;
break;
}
}
static void F_30 ( struct V_1 * V_2 , const char * V_26 , int V_15 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_15 ; V_24 ++ ) {
char V_62 = V_26 [ V_24 ] ;
#ifdef F_31
if ( V_62 == '\0' ) {
V_2 -> V_63 = 1 ;
continue;
} else if ( V_2 -> V_63 ) {
F_32 ( V_62 ) ;
V_2 -> V_63 = 0 ;
continue;
}
#endif
F_33 ( & V_2 -> V_64 , V_62 , 0 ) ;
}
}
static bool F_34 ( struct V_1 * V_2 , const T_1 * V_13 )
{
const struct V_14 * V_16 = ( const struct V_14 * ) V_13 ;
const T_1 * V_23 = V_13 + sizeof( struct V_14 ) ;
int V_65 = V_16 -> V_15 - sizeof( struct V_14 ) ;
int V_66 = V_65 - V_67 ;
F_6 ( L_24 , V_65 , V_65 , V_23 ) ;
if ( V_65 == 0 )
return false ;
if ( V_66 > 0 ) {
F_6 ( L_25 , V_21 ) ;
V_65 = V_67 ;
}
F_30 ( V_2 , V_23 , V_65 ) ;
if ( V_66 > 0 ) {
F_6 ( L_26 , V_21 ) ;
memcpy ( V_2 -> V_68 , V_23 + V_67 , V_66 ) ;
V_2 -> V_69 = V_66 ;
}
return true ;
}
static int F_35 ( struct V_1 * V_2 , struct V_30 * V_31 ,
struct V_1 * * V_70 )
{
T_1 * V_13 = V_2 -> V_22 ;
int V_71 ;
bool V_72 = false ;
* V_70 = NULL ;
V_71 = F_19 ( V_2 , V_2 -> V_18 , V_73 ) ;
if ( V_71 == 0 ) {
F_6 ( L_27 , V_21 ) ;
return 0 ;
}
F_6 ( L_28 , V_21 , V_71 ) ;
F_27 ( V_2 -> V_18 , V_71 ) ;
V_2 -> V_18 += V_71 ;
while ( ( V_13 < V_2 -> V_18 ) && F_14 ( V_2 , V_13 ) ) {
struct V_14 * V_16 = (struct V_14 * ) V_13 ;
if ( ! F_13 ( V_13 ) ) {
F_17 ( V_51 L_29 , V_2 -> V_10 ) ;
while ( ( V_13 < V_2 -> V_18 ) && ( ! F_13 ( V_13 ) ) )
V_13 ++ ;
continue;
}
F_6 ( L_30 , V_21 ,
F_12 ( V_13 ) ) ;
F_36 ( V_13 ) ;
switch ( V_16 -> type ) {
case V_74 :
if ( ! F_2 ( V_2 ) )
break;
V_72 = F_34 ( V_2 , V_13 ) ;
break;
case V_75 :
F_21 ( V_2 , V_13 , V_31 , V_70 ) ;
break;
case V_17 :
F_24 ( V_2 , V_13 ) ;
break;
case V_76 :
F_29 ( V_2 , V_13 ) ;
break;
default:
F_17 ( V_51 L_31 ,
V_2 -> V_10 , V_16 -> type ) ;
F_18 ( V_13 ) ;
break;
}
V_13 += F_12 ( V_13 ) ;
if ( * V_70 ) {
F_6 ( L_32 , V_21 ) ;
break;
}
}
F_15 ( V_2 , V_13 ) ;
if ( V_72 )
F_37 ( & V_2 -> V_64 ) ;
return 1 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_6 ( L_33 , V_21 ,
V_2 -> V_69 ) ;
F_30 ( V_2 , V_2 -> V_68 , V_2 -> V_69 ) ;
V_2 -> V_69 = 0 ;
}
static T_3 F_39 ( int V_77 , void * V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_78 ;
struct V_1 * V_70 ;
struct V_30 * V_31 ;
unsigned long V_3 ;
int V_79 = 1 ;
F_6 ( L_34 , V_21 ) ;
V_31 = F_40 ( & V_2 -> V_64 ) ;
while ( V_79 ) {
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_79 = F_35 ( V_2 , V_31 , & V_70 ) ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( V_70 ) {
F_6 ( L_35 , V_70 -> V_10 ) ;
F_41 ( & V_70 -> V_80 ) ;
}
}
F_10 ( & V_2 -> V_12 , V_3 ) ;
if ( V_31 && V_2 -> V_69 && ! F_42 ( V_81 , & V_31 -> V_3 ) ) {
F_38 ( V_2 ) ;
F_37 ( & V_2 -> V_64 ) ;
}
F_11 ( & V_2 -> V_12 , V_3 ) ;
F_43 ( V_31 ) ;
return V_82 ;
}
static int T_4 F_44 ( struct V_1 * V_2 , int V_5 )
{
unsigned long V_83 = V_84 + V_85 ;
for (; ; ) {
F_39 ( V_2 -> V_86 , ( void * ) V_2 ) ;
if ( V_2 -> V_5 == V_5 )
return 0 ;
F_45 ( 5 ) ;
if ( F_46 ( V_84 , V_83 ) )
return - V_59 ;
}
}
static int F_47 ( struct V_1 * V_2 , int V_5 )
{
int V_87 = 0 ;
if ( ! F_48 ( V_2 -> V_11 , ( V_2 -> V_5 == V_5 ) , V_85 ) )
V_87 = - V_59 ;
return V_87 ;
}
static int V_60 ( struct V_1 * V_2 , T_2 V_34 )
{
struct V_60 V_13 V_53 ;
int V_54 ;
V_13 . V_55 . type = V_76 ;
V_13 . V_55 . V_15 = sizeof( struct V_60 ) ;
V_13 . V_55 . V_25 = F_26 ( & V_2 -> V_25 ) ;
V_13 . V_34 = V_34 ;
F_6 ( L_21 , V_21 , V_13 . V_55 . V_15 ) ;
F_27 ( ( T_1 * ) & V_13 , V_13 . V_55 . V_15 ) ;
V_54 = F_28 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_55 . V_15 ) ;
if ( V_54 != V_13 . V_55 . V_15 ) {
F_17 ( V_51 L_36 , V_2 -> V_10 ,
V_54 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_87 ;
F_9 ( V_2 , V_7 ) ;
V_60 ( V_2 , V_88 ) ;
V_87 = F_50 ( V_2 , V_6 ) ;
if ( V_87 < 0 ) {
F_17 ( V_51 L_37 , V_2 -> V_10 ) ;
F_9 ( V_2 , V_6 ) ;
return V_87 ;
}
F_6 ( L_38 , V_21 , V_2 -> V_38 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_33 V_13 V_53 ;
int V_54 ;
V_13 . V_55 . type = V_75 ,
V_13 . V_55 . V_25 = F_26 ( & V_2 -> V_25 ) ;
V_13 . V_55 . V_15 = sizeof( struct V_33 ) ;
V_13 . V_34 = V_89 ;
V_13 . V_90 = V_49 ;
if ( V_38 & V_50 )
V_13 . V_36 = V_49 ;
F_6 ( L_21 , V_21 , V_13 . V_55 . V_15 ) ;
F_27 ( ( T_1 * ) & V_13 , V_13 . V_55 . V_15 ) ;
V_54 = F_28 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_55 . V_15 ) ;
if ( V_54 != V_13 . V_55 . V_15 ) {
F_17 ( V_51 L_39 , V_2 -> V_10 ) ;
return - V_59 ;
}
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_26 [ V_73 ] V_53 ;
unsigned long V_83 = V_84 + V_85 ;
while ( F_53 ( V_83 , V_84 ) )
if ( 0 == F_19 ( V_2 , V_26 , V_73 ) )
break;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_87 ;
F_52 ( V_2 ) ;
F_9 ( V_2 , V_45 ) ;
V_87 = V_60 ( V_2 , V_56 ) ;
if ( V_87 < 0 ) {
F_17 ( V_51 L_40 , V_2 -> V_10 ) ;
return V_87 ;
}
V_87 = F_50 ( V_2 , V_6 ) ;
if ( V_87 < 0 )
return V_87 ;
return 0 ;
}
static void F_55 ( struct V_91 * V_92 )
{
struct V_1 * V_2 =
F_56 ( V_92 , struct V_1 , V_80 ) ;
if ( F_54 ( V_2 ) >= 0 )
return;
F_17 ( V_51 L_41 , V_2 -> V_10 ) ;
if ( F_1 ( V_2 ) ) {
F_17 ( V_51 L_42 , V_2 -> V_10 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , const char * V_26 , int V_27 )
{
struct V_93 V_13 V_53 ;
int V_87 ;
F_58 ( V_27 > V_94 ) ;
V_13 . V_55 . type = V_74 ;
V_13 . V_55 . V_25 = F_26 ( & V_2 -> V_25 ) ;
V_13 . V_55 . V_15 = V_27 + sizeof( struct V_14 ) ;
memcpy ( & V_13 . V_23 , V_26 , V_27 ) ;
V_87 = F_28 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_55 . V_15 ) ;
if ( V_87 == V_13 . V_55 . V_15 ) {
return V_27 ;
}
return V_87 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_33 V_13 V_53 ;
V_13 . V_55 . type = V_75 ;
V_13 . V_55 . V_25 = F_26 ( & V_2 -> V_25 ) ;
V_13 . V_55 . V_15 = 6 ;
V_13 . V_34 = V_40 ;
F_6 ( L_21 , V_21 , V_13 . V_55 . V_15 ) ;
F_27 ( ( T_1 * ) & V_13 , V_13 . V_55 . V_15 ) ;
F_28 ( V_2 -> V_29 , ( char * ) & V_13 , V_13 . V_55 . V_15 ) ;
}
static int F_60 ( struct V_30 * V_31 , struct V_95 * V_96 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
int V_87 ;
F_6 ( L_34 , V_21 ) ;
V_2 = & V_97 [ V_31 -> V_10 ] ;
V_31 -> V_98 = V_2 ;
F_61 () ;
if ( V_2 -> V_5 == V_99 )
return - V_59 ;
F_62 ( & V_2 -> V_64 , V_31 ) ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_2 -> V_64 . V_27 ++ ;
F_63 ( & V_2 -> V_25 , 0 ) ;
F_64 ( V_2 -> V_29 , V_100 ) ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( F_1 ( V_2 ) )
return 0 ;
V_87 = F_54 ( V_2 ) ;
if ( V_87 < 0 ) {
F_17 ( V_51 L_43 , V_31 -> V_9 ) ;
return V_87 ;
}
V_87 = F_49 ( V_2 ) ;
if ( V_87 < 0 ) {
F_17 ( V_51 L_44 , V_31 -> V_9 ) ;
return V_87 ;
}
V_87 = F_51 ( V_2 , V_2 -> V_38 | V_50 ) ;
if ( V_87 < 0 ) {
F_17 ( V_51 L_45 , V_31 -> V_9 ) ;
return V_87 ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_101 , ( V_2 -> V_102 <= 0 ) , V_85 ) ;
F_66 ( & V_2 -> V_103 ) ;
F_67 ( & V_2 -> V_80 ) ;
V_2 -> V_102 = 0 ;
}
static void F_68 ( struct V_30 * V_31 , struct V_95 * V_96 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
unsigned long V_3 ;
F_6 ( L_34 , V_21 ) ;
if ( F_69 ( V_96 ) )
return;
F_10 ( & V_2 -> V_12 , V_3 ) ;
if ( -- V_2 -> V_64 . V_27 == 0 ) {
F_62 ( & V_2 -> V_64 , NULL ) ;
V_2 -> V_18 = V_2 -> V_22 ;
if ( ! F_1 ( V_2 ) ) {
F_64 ( V_2 -> V_29 , V_104 ) ;
F_7 ( V_2 , V_41 ) ;
V_31 -> V_105 = 1 ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
F_70 ( V_2 -> V_86 ) ;
F_65 ( V_2 ) ;
F_59 ( V_2 ) ;
F_52 ( V_2 ) ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
}
} else if ( V_2 -> V_64 . V_27 < 0 )
F_17 ( V_51 L_46 ,
V_2 - V_97 , V_2 -> V_64 . V_27 ) ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
}
static void F_71 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
unsigned long V_3 ;
F_6 ( L_34 , V_21 ) ;
F_62 ( & V_2 -> V_64 , NULL ) ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_2 -> V_64 . V_27 = 0 ;
V_2 -> V_102 = 0 ;
F_11 ( & V_2 -> V_12 , V_3 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
int V_106 ;
if ( V_2 -> V_102 <= 0 )
return;
V_106 = F_57 ( V_2 , V_2 -> V_107 , V_2 -> V_102 ) ;
if ( V_106 > 0 ) {
F_6 ( L_47 , V_21 , V_106 ) ;
V_2 -> V_102 = 0 ;
} else if ( V_106 == - V_59 ) {
F_7 ( V_2 , V_99 ) ;
F_17 ( V_51 L_48 , V_2 -> V_10 ) ;
}
}
static void F_73 ( struct V_91 * V_92 )
{
struct V_1 * V_2 =
F_56 ( V_92 , struct V_1 , V_103 . V_92 ) ;
struct V_30 * V_31 ;
unsigned long V_3 ;
#ifdef F_4
static long V_108 = 0 ;
if ( V_108 == 0 )
V_108 = V_84 ;
#endif
F_10 ( & V_2 -> V_12 , V_3 ) ;
F_6 ( L_49 , V_21 , V_2 -> V_102 ) ;
if ( ! F_2 ( V_2 ) ) {
F_74 ( & V_2 -> V_103 , V_109 ) ;
goto V_110;
}
F_72 ( V_2 ) ;
if ( V_2 -> V_102 > 0 )
F_74 ( & V_2 -> V_103 , 10 ) ;
else {
#ifdef F_4
F_6 ( L_50 , V_21 ,
V_84 - V_108 ) ;
V_108 = 0 ;
#endif
F_8 ( & V_2 -> V_101 ) ;
V_31 = F_40 ( & V_2 -> V_64 ) ;
if ( V_31 ) {
F_75 ( V_31 ) ;
F_43 ( V_31 ) ;
}
}
V_110:
F_11 ( & V_2 -> V_12 , V_3 ) ;
}
static int F_76 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
return V_111 - V_2 -> V_102 ;
}
static int F_77 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
return V_2 -> V_102 ;
}
static int F_78 ( struct V_30 * V_31 ,
const unsigned char * V_26 , int V_27 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
const char * V_112 = V_26 ;
unsigned long V_3 ;
int V_113 = 0 ;
int V_114 = V_27 ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
F_6 ( L_49 , V_21 , V_2 -> V_102 ) ;
if ( ! F_2 ( V_2 ) ) {
F_6 ( L_51 , V_21 ) ;
goto V_110;
}
while ( ( V_27 > 0 ) && ( F_76 ( V_31 ) > 0 ) ) {
int V_115 = F_79 ( V_27 , F_76 ( V_31 ) ) ;
F_58 ( V_2 -> V_102 < 0 ) ;
memcpy ( V_2 -> V_107 + V_2 -> V_102 , V_112 , V_115 ) ;
V_2 -> V_102 += V_115 ;
V_113 += V_115 ;
V_112 += V_115 ;
V_27 -= V_115 ;
F_72 ( V_2 ) ;
}
if ( V_2 -> V_102 > 0 ) {
F_74 ( & V_2 -> V_103 , 10 ) ;
}
V_110:
F_11 ( & V_2 -> V_12 , V_3 ) ;
if ( V_113 != V_114 )
F_6 ( L_52 , V_21 , V_114 ,
V_113 ) ;
return V_113 ;
}
static void F_80 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
F_6 ( L_34 , V_21 ) ;
F_64 ( V_2 -> V_29 , V_104 ) ;
}
static void F_81 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
unsigned long V_3 ;
F_6 ( L_34 , V_21 ) ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
if ( V_2 -> V_69 ) {
F_38 ( V_2 ) ;
F_37 ( & V_2 -> V_64 ) ;
}
F_11 ( & V_2 -> V_12 , V_3 ) ;
F_64 ( V_2 -> V_29 , V_100 ) ;
}
static int F_82 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
F_49 ( V_2 ) ;
return V_2 -> V_38 ;
}
static int F_83 ( struct V_30 * V_31 ,
unsigned int V_116 , unsigned int V_117 )
{
struct V_1 * V_2 = V_31 -> V_98 ;
unsigned long V_3 ;
T_2 V_118 ;
V_117 &= V_50 ;
V_116 &= V_50 ;
F_10 ( & V_2 -> V_12 , V_3 ) ;
V_118 = ( V_2 -> V_38 & ~ V_117 ) | V_116 ;
if ( V_2 -> V_38 != V_118 ) {
F_51 ( V_2 , V_118 ) ;
V_2 -> V_38 = V_118 ;
}
F_11 ( & V_2 -> V_12 , V_3 ) ;
return 0 ;
}
static int T_4 F_84 ( void )
{
int V_24 ;
V_119 = F_85 ( V_120 ) ;
if ( ! V_119 )
return - V_121 ;
V_119 -> V_122 = L_53 ;
V_119 -> V_9 = L_53 ;
V_119 -> V_123 = V_124 ;
V_119 -> V_125 = V_126 ;
V_119 -> type = V_127 ;
V_119 -> V_128 = V_129 ;
V_119 -> V_128 . V_130 = V_131 | V_132 | V_133 | V_134 ;
V_119 -> V_128 . V_135 = 9600 ;
V_119 -> V_128 . V_136 = 9600 ;
V_119 -> V_3 = V_137 ;
F_86 ( V_119 , & V_138 ) ;
for ( V_24 = 0 ; V_24 < V_120 ; V_24 ++ ) {
struct V_1 * V_2 = & V_97 [ V_24 ] ;
int V_87 = 1 ;
F_87 ( & V_2 -> V_64 , V_119 , V_24 ) ;
V_87 = F_88 ( V_2 -> V_86 , F_39 , 0 , L_53 , V_2 ) ;
if ( V_87 )
F_17 ( V_51 L_54 ,
V_2 -> V_86 , V_87 ) ;
}
F_50 = F_47 ;
if ( F_89 ( V_119 ) )
F_90 ( L_55 ) ;
F_17 ( V_139 L_56 , V_120 ) ;
return 0 ;
}
static void F_91 ( struct V_140 * V_140 , const char * V_26 ,
unsigned int V_27 )
{
struct V_1 * V_2 = & V_97 [ V_140 -> V_10 ] ;
char V_62 [ V_94 ] V_53 ;
unsigned int V_24 = 0 , V_106 = 0 ;
int V_87 , V_141 = 0 ;
F_61 () ;
if ( ! F_2 ( V_2 ) )
return;
while ( V_27 > 0 || V_24 > 0 ) {
if ( V_27 > 0 && V_24 < sizeof( V_62 ) ) {
if ( V_26 [ V_106 ] == '\n' && ! V_141 ) {
V_62 [ V_24 ++ ] = '\r' ;
V_141 = 1 ;
} else {
V_62 [ V_24 ++ ] = V_26 [ V_106 ++ ] ;
V_141 = 0 ;
-- V_27 ;
}
} else {
V_87 = F_57 ( V_2 , V_62 , V_24 ) ;
if ( V_87 < 0 )
V_24 = 0 ;
V_24 -= V_87 ;
}
}
}
static struct V_142 * F_92 ( struct V_140 * V_140 ,
int * V_10 )
{
* V_10 = V_140 -> V_10 ;
return V_119 ;
}
static int T_4 F_93 ( struct V_140 * V_140 , char * V_143 )
{
struct V_1 * V_2 ;
int V_87 ;
if ( V_140 -> V_10 < 0 || V_140 -> V_10 >= V_120 )
return - 1 ;
V_2 = & V_97 [ V_140 -> V_10 ] ;
F_59 ( V_2 ) ;
V_87 = F_54 ( V_2 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_49 ( V_2 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_51 ( V_2 , V_2 -> V_38 | V_50 ) ;
if ( V_87 < 0 )
return V_87 ;
V_2 -> V_3 |= V_4 ;
return 0 ;
}
static int T_4 F_94 ( void )
{
struct V_144 * V_145 ;
F_50 = F_44 ;
F_95 (vty, L_57 , L_58 ) {
struct V_1 * V_2 ;
const T_5 * V_29 , * V_77 ;
V_29 = F_96 ( V_145 , L_59 , NULL ) ;
V_77 = F_96 ( V_145 , L_60 , NULL ) ;
if ( ! V_29 || ! V_77 )
continue;
if ( V_120 >= V_146 ) {
F_97 ( V_145 ) ;
break;
}
V_2 = & V_97 [ V_120 ] ;
F_98 ( & V_2 -> V_103 , F_73 ) ;
F_99 ( & V_2 -> V_80 , F_55 ) ;
F_100 ( & V_2 -> V_101 ) ;
F_100 ( & V_2 -> V_11 ) ;
F_101 ( & V_2 -> V_12 ) ;
F_102 ( & V_2 -> V_64 ) ;
V_2 -> V_10 = V_120 ;
V_2 -> V_18 = V_2 -> V_22 ;
V_2 -> V_5 = V_41 ;
V_2 -> V_29 = * V_29 ;
V_2 -> V_86 = F_103 ( NULL , V_77 [ 0 ] ) ;
if ( V_2 -> V_86 == 0 ) {
F_17 ( V_51 L_61 ,
V_21 , V_77 [ 0 ] ) ;
F_104 ( & V_2 -> V_64 ) ;
continue;
}
V_120 ++ ;
}
if ( V_120 )
F_105 ( & V_147 ) ;
return 0 ;
}
