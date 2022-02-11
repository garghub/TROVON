static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memset ( V_4 -> V_5 , 0 ,
V_6 * sizeof( struct V_7 * ) ) ;
}
static int F_3 ( struct V_8 * V_9 )
{
if ( V_9 ) {
F_4 ( V_9 ) ;
F_5 ( V_9 ) ;
}
return 0 ;
}
static struct V_10 * F_6 ( struct V_1
* V_2 )
{
struct V_10 * V_11 ;
static int V_12 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_13 ) ;
if ( ! V_11 ) {
return NULL ;
}
V_11 -> V_14 = F_8 ( V_2 -> V_15 , V_13 ) ;
if ( ! V_11 -> V_14 ) {
F_9 ( V_11 ) ;
return NULL ;
}
V_11 -> V_12 = V_12 ++ ;
F_10 ( & V_11 -> V_16 ) ;
return V_11 ;
}
static struct V_10 * F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 = NULL ;
struct V_17 * V_18 = V_4 -> V_19 . V_20 ;
V_4 -> V_21 ++ ;
V_22:
if ( V_18 != & V_4 -> V_19 ) {
V_11 = F_12 ( V_18 , struct V_10 , V_16 ) ;
F_13 ( V_18 ) ;
memset ( V_11 -> V_14 , 0 , V_2 -> V_15 ) ;
V_4 -> V_23 -- ;
return V_11 ;
}
V_11 = F_6 ( V_2 ) ;
if ( ! V_11 ) {
F_14 () ;
goto V_22;
}
return V_11 ;
}
static inline void F_15 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_21 -- ;
if ( V_4 -> V_23 > V_24 ) {
F_9 ( V_11 -> V_14 ) ;
F_9 ( V_11 ) ;
} else {
F_16 ( & V_11 -> V_16 , & V_4 -> V_19 ) ;
V_4 -> V_23 ++ ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
int V_25 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 = NULL ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
F_16 ( & V_11 -> V_16 , & V_4 -> V_19 ) ;
V_4 -> V_23 ++ ;
} else {
break;
}
}
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_27 ,
struct V_28 * V_29 )
{
unsigned int V_30 = V_27 / ( V_2 -> V_15 << 3 ) ;
unsigned int V_31 = V_27 % ( V_2 -> V_15 << 3 ) ;
if ( ! V_29 -> V_32 [ V_30 ] ) {
V_29 -> V_32 [ V_30 ] = F_11 ( V_2 ) ;
}
F_19 ( V_31 , ( unsigned long * ) V_29 -> V_32 [ V_30 ] -> V_14 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_25 ;
if ( V_29 -> V_32 == NULL )
return;
for ( V_25 = 0 ; V_25 < F_21 ( V_2 ) ; V_25 ++ ) {
if ( V_29 -> V_32 [ V_25 ] ) {
F_15 ( V_2 , V_29 -> V_32 [ V_25 ] ) ;
V_29 -> V_32 [ V_25 ] = NULL ;
}
}
}
static int F_22 ( struct V_1 * V_2 ,
struct V_28 * V_33 )
{
int V_25 ;
struct V_28 * V_29 ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ ) {
V_29 = V_33 + V_25 ;
V_29 -> V_35 = NULL ;
F_20 ( V_2 , V_29 ) ;
F_23 ( V_29 -> V_32 ) ;
V_29 -> V_32 = NULL ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_20 = V_4 -> V_19 . V_20 ;
struct V_10 * V_11 ;
while ( V_20 != & V_4 -> V_19 ) {
V_11 = F_12 ( V_20 , struct V_10 , V_16 ) ;
F_13 ( V_20 ) ;
F_9 ( V_11 -> V_14 ) ;
F_9 ( V_11 ) ;
V_20 = V_4 -> V_19 . V_20 ;
V_4 -> V_23 -- ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_28 * V_33 ,
unsigned int V_30 )
{
int V_25 ;
int V_36 = 0 ;
struct V_28 * V_29 ;
int V_37 = V_30 * sizeof( struct V_10 * ) ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ ) {
V_29 = V_33 + V_25 ;
V_29 -> V_35 = NULL ;
V_29 -> V_32 = F_26 ( V_37 ) ;
if ( ! V_29 -> V_32 ) {
F_27 ( V_2 , L_1 , L_2
L_3 ) ;
V_36 = 1 ;
break;
}
}
if ( V_36 ) {
F_22 ( V_2 , V_33 ) ;
return - 1 ;
}
return 0 ;
}
static struct V_28 * F_28 ( struct V_1 * V_2 ,
struct V_38
* V_39 )
{
int V_25 , V_40 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_29 = NULL ;
for ( V_40 = 0 ; V_40 < ( V_34 * 3 ) ; V_40 ++ ) {
V_25 = V_4 -> V_41 ;
V_4 -> V_41 = ( V_25 + 1 ) % V_34 ;
V_29 = V_4 -> V_42 + V_25 ;
if ( V_4 -> V_42 [ V_25 ] . V_35 ) {
F_29 ( V_2 ,
V_4 -> V_42 [ V_25 ] .
V_35 , 1 ) ;
if ( ! V_4 -> V_42 [ V_25 ] . V_35 ) {
break;
}
} else {
break;
}
}
if ( V_29 -> V_35 ) {
return NULL ;
}
V_29 -> V_35 = V_39 ;
return V_29 ;
}
static struct V_7 * F_30 ( int V_43 )
{
struct V_7 * V_44 ;
int V_25 ;
if ( V_43 <= 0 ) {
return NULL ;
}
V_44 = F_26 ( V_43 * sizeof( struct V_7 ) ) ;
if ( ! V_44 ) {
return NULL ;
}
V_44 [ 0 ] . V_45 = NULL ;
V_44 [ 0 ] . V_20 = V_44 + 1 ;
for ( V_25 = 1 ; V_25 < V_43 ; V_25 ++ ) {
V_44 [ V_25 ] . V_45 = V_44 + ( V_25 - 1 ) ;
V_44 [ V_25 ] . V_20 = V_44 + ( V_25 + 1 ) ;
}
V_44 [ V_43 - 1 ] . V_20 = NULL ;
return V_44 ;
}
static struct V_7 * F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_46 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_32 ( V_2 , L_4 ) ;
if ( V_4 -> V_47 <= 0 ) {
return NULL ;
}
V_4 -> V_48 ++ ;
V_4 -> V_47 -- ;
V_46 = V_4 -> V_49 ;
if ( ! V_46 ) {
return V_46 ;
}
if ( V_46 -> V_20 ) {
V_46 -> V_20 -> V_45 = NULL ;
}
V_4 -> V_49 = V_46 -> V_20 ;
memset ( V_46 , 0 , sizeof( struct V_7 ) ) ;
return V_46 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_7 * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_32 ( V_2 , L_5 ) ;
V_4 -> V_48 -- ;
V_4 -> V_47 ++ ;
V_46 -> V_20 = V_4 -> V_49 ;
if ( V_4 -> V_49 ) {
V_4 -> V_49 -> V_45 = V_46 ;
}
V_46 -> V_45 = NULL ;
V_4 -> V_49 = V_46 ;
}
static void F_34 ( struct V_8 * V_9 )
{
F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
}
static inline struct V_7 * F_37 ( struct
V_1
* V_2 ,
struct
V_7
* * V_50 ,
long V_51 )
{
struct V_7 * V_46 ;
V_46 = F_38 ( V_50 , V_2 , V_51 ) ;
while ( V_46 ) {
if ( V_46 -> V_52 == V_51 && V_46 -> V_2 == V_2 )
return V_46 ;
V_46 = V_46 -> V_53 ;
}
return (struct V_7 * ) 0 ;
}
int F_39 ( struct V_1 * V_2 ,
unsigned int V_30 , int V_31 , int V_54 ,
T_1 * V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 ;
struct V_28 * V_29 ;
int V_25 ;
unsigned long V_51 ;
* V_55 = 0 ;
F_40 ( V_2 , V_4 . V_56 ) ;
if ( V_54 ) {
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ ) {
F_40 ( V_2 , V_4 . V_57 ) ;
V_29 = V_4 -> V_42 + V_25 ;
if ( V_29 -> V_35 && V_29 -> V_32 [ V_30 ] &&
F_41 ( V_31 ,
( unsigned long * ) V_29 -> V_32 [ V_30 ] ->
V_14 ) ) {
* V_55 =
F_42 ( ( unsigned long * )
( V_29 -> V_32 [ V_30 ] ->
V_14 ) ,
V_2 -> V_15 << 3 ,
V_31 + 1 ) ;
return 1 ;
}
}
}
V_51 = V_30 * ( V_2 -> V_15 << 3 ) + V_31 ;
if ( V_54
&& ( V_46 =
F_37 ( V_2 , V_4 -> V_58 , V_51 ) ) ) {
return 1 ;
}
if ( ( V_46 = F_37 ( V_2 , V_4 -> V_5 , V_51 ) ) ) {
F_43 () ;
return 1 ;
}
F_40 ( V_2 , V_4 . V_59 ) ;
return 0 ;
}
static inline void F_44 ( struct V_7 * * V_50 ,
struct V_7 * V_46 )
{
struct V_7 * V_60 ;
V_60 = F_38 ( V_50 , V_46 -> V_2 , V_46 -> V_52 ) ;
V_46 -> V_53 = V_60 ;
V_46 -> V_61 = NULL ;
if ( V_60 ) {
V_60 -> V_61 = V_46 ;
}
F_38 ( V_50 , V_46 -> V_2 , V_46 -> V_52 ) = V_46 ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
F_40 ( V_2 , V_4 . F_45 ) ;
F_46 ( & F_2 ( V_2 ) -> V_62 , V_2 ) ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
F_48 ( & F_2 ( V_2 ) -> V_62 ) ;
}
static inline void F_49 ( struct V_38 * V_39 )
{
V_39 -> V_63 ++ ;
}
static inline void F_50 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
if ( V_39 -> V_63 < 1 ) {
F_51 ( V_64 , L_6 , L_7 ,
V_39 -> V_65 , V_39 -> V_63 ) ;
}
if ( -- V_39 -> V_63 == 0 )
F_9 ( V_39 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_28 * V_29 = V_39 -> V_42 ;
if ( V_29 ) {
F_20 ( V_2 , V_29 ) ;
}
V_39 -> V_42 -> V_35 = NULL ;
V_39 -> V_42 = NULL ;
}
static int F_53 ( struct V_1 * V_64 ,
unsigned int V_66 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
struct V_17 * V_18 = & V_4 -> V_67 ;
struct V_38 * V_39 ;
if ( ! F_54 ( V_18 ) ) {
V_39 = F_55 ( V_18 -> V_20 ) ;
if ( V_39 -> V_65 <= V_66 ) {
return 1 ;
}
}
return 0 ;
}
static void F_56 ( struct V_8 * V_9 )
{
struct V_68 * V_68 = V_9 -> V_69 ;
if ( ! V_68 -> V_70 && F_57 ( V_68 ) ) {
F_58 ( V_68 ) ;
F_59 ( V_9 ) ;
if ( ! V_68 -> V_70 )
F_60 ( V_68 ) ;
F_61 ( V_68 ) ;
F_62 ( V_68 ) ;
} else {
F_59 ( V_9 ) ;
}
}
static void F_63 ( struct V_8 * V_9 , int V_71 )
{
char V_72 [ V_73 ] ;
if ( F_64 ( V_9 ) ) {
F_27 ( NULL , L_8 ,
L_9 ,
V_9 -> V_74 , F_65 ( V_9 -> V_75 , V_72 ) ) ;
}
if ( V_71 )
F_66 ( V_9 ) ;
else
F_67 ( V_9 ) ;
F_68 ( V_9 ) ;
F_56 ( V_9 ) ;
}
static void F_69 ( struct V_8 * V_9 , int V_71 )
{
if ( V_71 )
F_66 ( V_9 ) ;
else
F_67 ( V_9 ) ;
F_68 ( V_9 ) ;
F_59 ( V_9 ) ;
}
static void F_70 ( struct V_8 * V_9 )
{
F_71 ( V_9 ) ;
V_9 -> V_76 = F_63 ;
F_72 ( V_9 ) ;
F_4 ( V_9 ) ;
if ( ! F_73 ( V_9 ) )
F_43 () ;
if ( ! F_74 ( V_9 ) )
F_43 () ;
F_75 ( V_77 , V_9 ) ;
}
static void F_76 ( struct V_8 * V_9 )
{
F_71 ( V_9 ) ;
V_9 -> V_76 = F_69 ;
F_4 ( V_9 ) ;
if ( ! F_74 ( V_9 ) )
F_43 () ;
F_75 ( V_77 , V_9 ) ;
}
static void F_77 ( struct V_78 * V_79 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_79 -> V_80 ; V_25 ++ ) {
F_70 ( V_79 -> V_9 [ V_25 ] ) ;
}
V_79 -> V_80 = 0 ;
}
static void F_78 ( struct V_78 * V_79 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_79 -> V_80 ; V_25 ++ ) {
F_76 ( V_79 -> V_9 [ V_25 ] ) ;
}
V_79 -> V_80 = 0 ;
}
static int F_79 ( struct V_78 * V_79 , struct V_8 * V_9 ,
T_2 * V_81 , void (F_80) ( struct V_78 * ) )
{
int V_82 = 0 ;
F_81 ( V_79 -> V_80 >= V_83 ) ;
V_79 -> V_9 [ V_79 -> V_80 ++ ] = V_9 ;
if ( V_79 -> V_80 >= V_83 ) {
V_82 = 1 ;
if ( V_81 )
F_82 ( V_81 ) ;
F_80 ( V_79 ) ;
if ( V_81 )
F_83 ( V_81 ) ;
}
return V_82 ;
}
static struct V_84 * F_84 ( void )
{
struct V_84 * V_85 ;
while ( 1 ) {
V_85 = F_7 ( sizeof( * V_85 ) , V_13 ) ;
if ( V_85 ) {
F_85 ( & V_86 ) ;
return V_85 ;
}
F_14 () ;
}
}
void F_86 ( struct V_8 * V_9 )
{
struct V_84 * V_85 ;
V_85 = V_9 -> V_87 ;
if ( V_85 ) {
V_9 -> V_87 = NULL ;
V_85 -> V_9 = NULL ;
F_87 ( & V_85 -> V_16 ) ;
F_9 ( V_85 ) ;
if ( F_88 ( & V_86 ) <= 0 )
F_43 () ;
F_89 ( & V_86 ) ;
F_59 ( V_9 ) ;
}
}
static inline int F_90 ( struct V_3 * V_40 , struct V_8 * V_9 ,
int V_88 )
{
struct V_84 * V_85 ;
if ( V_9 -> V_87 ) {
F_83 ( & V_40 -> V_89 ) ;
if ( ! V_9 -> V_87 ) {
F_82 ( & V_40 -> V_89 ) ;
goto V_90;
}
V_85 = V_9 -> V_87 ;
F_87 ( & V_85 -> V_16 ) ;
} else {
V_90:
F_71 ( V_9 ) ;
V_85 = F_84 () ;
F_83 ( & V_40 -> V_89 ) ;
F_81 ( V_9 -> V_87 ) ;
V_85 -> V_9 = V_9 ;
V_9 -> V_87 = V_85 ;
}
V_85 -> V_39 = V_40 -> V_91 ;
if ( V_88 )
F_91 ( & V_85 -> V_16 , & V_85 -> V_39 -> V_92 ) ;
else {
F_91 ( & V_85 -> V_16 , & V_85 -> V_39 -> V_93 ) ;
}
F_82 ( & V_40 -> V_89 ) ;
return 0 ;
}
int F_92 ( struct V_94 * V_94 , struct V_8 * V_9 )
{
return F_90 ( F_2 ( V_94 -> V_95 ) , V_9 , 1 ) ;
}
int F_93 ( struct V_94 * V_94 , struct V_8 * V_9 )
{
return F_90 ( F_2 ( V_94 -> V_95 ) , V_9 , 0 ) ;
}
static int F_94 ( T_2 * V_81 ,
struct V_3 * V_40 ,
struct V_38 * V_39 ,
struct V_17 * V_16 )
{
struct V_8 * V_9 ;
struct V_84 * V_85 ;
int V_82 = V_40 -> V_96 ;
struct V_78 V_79 ;
struct V_17 V_97 ;
F_10 ( & V_97 ) ;
V_79 . V_80 = 0 ;
F_83 ( V_81 ) ;
while ( ! F_54 ( V_16 ) ) {
V_85 = F_95 ( V_16 -> V_20 ) ;
V_9 = V_85 -> V_9 ;
F_71 ( V_9 ) ;
if ( ! F_96 ( V_9 ) ) {
if ( ! F_97 ( V_9 ) ) {
F_98 ( & V_85 -> V_16 , & V_97 ) ;
goto V_98;
}
F_82 ( V_81 ) ;
if ( V_79 . V_80 )
F_78 ( & V_79 ) ;
F_99 ( V_9 ) ;
F_100 () ;
F_83 ( V_81 ) ;
goto V_98;
}
if ( ! F_74 ( V_9 ) && F_97 ( V_9 ) ) {
F_4 ( V_9 ) ;
V_82 = - V_99 ;
}
if ( F_97 ( V_9 ) ) {
F_98 ( & V_85 -> V_16 , & V_97 ) ;
F_79 ( & V_79 , V_9 , V_81 , F_78 ) ;
} else {
F_86 ( V_9 ) ;
F_68 ( V_9 ) ;
}
V_98:
F_59 ( V_9 ) ;
F_101 ( V_81 ) ;
}
if ( V_79 . V_80 ) {
F_82 ( V_81 ) ;
F_78 ( & V_79 ) ;
F_83 ( V_81 ) ;
}
while ( ! F_54 ( & V_97 ) ) {
V_85 = F_95 ( V_97 . V_45 ) ;
V_9 = V_85 -> V_9 ;
F_71 ( V_9 ) ;
F_86 ( V_9 ) ;
if ( F_102 ( V_9 ) ) {
F_82 ( V_81 ) ;
F_99 ( V_9 ) ;
F_83 ( V_81 ) ;
}
if ( ! F_74 ( V_9 ) ) {
V_82 = - V_99 ;
}
if ( F_97 ( V_9 ) && F_103 ( V_9 -> V_69 -> V_70 == NULL ) ) {
F_82 ( V_81 ) ;
F_104 ( V_77 , 1 , & V_9 ) ;
F_83 ( V_81 ) ;
}
F_59 ( V_9 ) ;
F_101 ( V_81 ) ;
}
F_82 ( V_81 ) ;
return V_82 ;
}
static int F_105 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
struct V_38 * V_100 ;
struct V_38 * V_101 ;
struct V_17 * V_18 ;
unsigned int V_66 = V_39 -> V_65 ;
unsigned int V_102 ;
unsigned int V_103 ;
V_104:
V_101 = V_39 ;
V_18 = V_39 -> V_105 . V_45 ;
while ( 1 ) {
V_100 = F_55 ( V_18 ) ;
if ( V_18 == & V_4 -> V_67 ||
F_88 ( & V_100 -> V_106 ) )
break;
V_101 = V_100 ;
V_18 = V_100 -> V_105 . V_45 ;
}
if ( V_101 == V_39 ) {
return 0 ;
}
V_103 = V_101 -> V_65 ;
V_18 = & V_101 -> V_105 ;
while ( 1 ) {
V_100 = F_55 ( V_18 ) ;
V_102 = V_100 -> V_65 ;
if ( V_102 < V_66 ) {
if ( F_88 ( & V_100 -> V_107 ) != 0 ) {
F_29 ( V_64 , V_100 , 0 ) ;
if ( ! F_53 ( V_64 , V_66 ) )
return 1 ;
if ( ! F_53
( V_64 , V_102 ) ) {
goto V_104;
}
}
V_18 = V_18 -> V_20 ;
if ( V_18 == & V_4 -> V_67 )
return 0 ;
} else {
return 0 ;
}
}
return 0 ;
}
static int F_106 ( struct V_1 * V_64 )
{
struct V_3 * V_40 = F_2 ( V_64 ) ;
if ( F_88 ( & V_40 -> V_108 ) ) {
int V_109 ;
V_109 = F_107 ( V_64 ) ;
F_108 ( V_110 , V_111 / 10 ) ;
F_109 ( V_64 , V_109 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_64 ,
struct V_38 * V_39 , int V_112 )
{
int V_25 ;
T_1 V_11 ;
struct V_8 * V_113 = NULL ;
unsigned int V_66 = V_39 -> V_65 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
int V_114 = 0 ;
int V_115 ;
int V_109 ;
F_32 ( V_64 , L_10 ) ;
if ( F_88 ( & V_39 -> V_106 ) ) {
return 0 ;
}
F_81 ( V_39 -> V_116 <= 0 ) ;
F_81 ( V_66 == V_4 -> V_65 ) ;
F_49 ( V_39 ) ;
if ( V_112 ) {
if ( F_105 ( V_64 , V_39 ) == 1 ) {
goto V_117;
}
}
F_46 ( & V_39 -> V_118 , V_64 ) ;
if ( ! F_53 ( V_64 , V_66 ) ) {
F_48 ( & V_39 -> V_118 ) ;
goto V_117;
}
F_81 ( V_39 -> V_65 == 0 ) ;
if ( F_88 ( & ( V_39 -> V_107 ) ) <= 0 ) {
if ( V_112 ) {
F_110 ( & ( V_39 -> V_106 ) , 1 ) ;
}
F_48 ( & V_39 -> V_118 ) ;
goto V_117;
}
if ( ! F_54 ( & V_39 -> V_93 ) ) {
int V_82 ;
V_109 = F_107 ( V_64 ) ;
V_82 = F_94 ( & V_4 -> V_89 ,
V_4 , V_39 , & V_39 -> V_93 ) ;
if ( V_82 < 0 && V_114 == 0 )
V_114 = V_82 ;
F_109 ( V_64 , V_109 ) ;
}
F_81 ( ! F_54 ( & V_39 -> V_93 ) ) ;
F_85 ( & V_4 -> V_108 ) ;
V_115 = V_39 -> V_116 + 1 ;
if ( V_115 < 256 )
V_115 = 256 ;
for ( V_25 = 0 ; V_25 < V_115 ; V_25 ++ ) {
V_11 = F_111 ( V_64 ) + ( V_39 -> V_119 + V_25 ) %
F_112 ( V_64 ) ;
V_113 = F_113 ( V_64 , V_11 ) ;
if ( V_113 ) {
if ( F_97 ( V_113 ) ) {
V_109 = F_107 ( V_64 ) ;
F_104 ( V_77 , 1 , & V_113 ) ;
F_109 ( V_64 , V_109 ) ;
}
F_59 ( V_113 ) ;
}
}
F_89 ( & V_4 -> V_108 ) ;
for ( V_25 = 0 ; V_25 < ( V_39 -> V_116 + 1 ) ; V_25 ++ ) {
V_11 = F_111 ( V_64 ) +
( V_39 -> V_119 + V_25 ) % F_112 ( V_64 ) ;
V_113 = F_113 ( V_64 , V_11 ) ;
V_109 = F_107 ( V_64 ) ;
F_114 ( V_113 ) ;
F_109 ( V_64 , V_109 ) ;
if ( F_97 ( V_113 ) ) {
V_109 = F_107 ( V_64 ) ;
F_115 ( V_113 ) ;
F_109 ( V_64 , V_109 ) ;
}
if ( F_103 ( ! F_74 ( V_113 ) ) ) {
#ifdef F_116
F_27 ( V_64 , L_11 ,
L_12 ) ;
#endif
V_114 = - V_99 ;
}
F_59 ( V_113 ) ;
F_59 ( V_113 ) ;
F_89 ( & ( V_39 -> V_107 ) ) ;
}
F_81 ( F_88 ( & ( V_39 -> V_107 ) ) != 1 ) ;
if ( F_117 ( ! V_114 && ! F_118 ( V_4 ) ) ) {
if ( F_97 ( V_39 -> V_120 ) )
F_43 () ;
F_119 ( V_39 -> V_120 ) ;
V_109 = F_107 ( V_64 ) ;
if ( F_120 ( V_64 ) )
F_121 ( V_39 -> V_120 , V_121 ) ;
else
F_115 ( V_39 -> V_120 ) ;
F_109 ( V_64 , V_109 ) ;
}
if ( F_103 ( ! F_74 ( V_39 -> V_120 ) ) ) {
#ifdef F_116
F_27 ( V_64 , L_13 , L_12 ) ;
#endif
V_114 = - V_99 ;
}
F_122 ( V_39 -> V_120 ) ;
if ( V_4 -> V_122 != 0 &&
( V_39 -> V_65 - V_4 -> V_122 ) != 1 ) {
F_27 ( V_64 , L_14 , L_15 ,
V_4 -> V_122 , V_39 -> V_65 ) ;
}
V_4 -> V_122 = V_39 -> V_65 ;
F_52 ( V_64 , V_39 ) ;
V_114 = V_114 ? V_114 : V_4 -> V_96 ;
if ( ! V_114 )
F_123 ( V_64 , V_39 ) ;
F_89 ( & ( V_39 -> V_107 ) ) ;
if ( V_112 ) {
F_110 ( & ( V_39 -> V_106 ) , 1 ) ;
}
F_48 ( & V_39 -> V_118 ) ;
V_117:
F_50 ( V_64 , V_39 ) ;
if ( V_114 )
F_124 ( V_64 , V_114 , L_16 ,
V_123 ) ;
return V_114 ;
}
static struct V_38 * F_125 ( struct
V_7
* V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
T_1 V_52 = V_46 -> V_52 ;
V_46 = V_46 -> V_61 ;
while ( V_46 ) {
if ( V_46 -> V_2 == V_2 && V_46 -> V_52 == V_52 && V_46 -> V_124 ) {
return V_46 -> V_124 ;
}
V_46 = V_46 -> V_61 ;
}
return NULL ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_125 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 , * V_126 ;
V_46 = V_39 -> V_127 ;
while ( V_46 ) {
if ( V_46 -> V_52 != 0 ) {
if ( V_125 ) {
F_27 ( V_2 , L_17 ,
L_18 ,
V_46 -> V_52 , V_46 -> V_9 ? 1 : 0 ,
V_46 -> V_128 ) ;
}
V_46 -> V_128 = 0 ;
F_127 ( V_2 , V_4 -> V_58 ,
V_39 , V_46 -> V_52 , 1 ) ;
}
V_126 = V_46 ;
V_46 = V_46 -> V_20 ;
F_33 ( V_2 , V_126 ) ;
}
V_39 -> V_127 = NULL ;
}
static int F_128 ( struct V_1 * V_2 ,
unsigned long V_129 ,
unsigned int V_66 )
{
struct V_130 * V_85 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_109 ;
if ( F_118 ( V_4 ) )
return - V_99 ;
if ( V_66 >= V_4 -> V_131 ) {
if ( F_102 ( ( V_4 -> V_132 ) ) ) {
V_109 = F_107 ( V_2 ) ;
F_114 ( V_4 -> V_132 ) ;
F_109 ( V_2 , V_109 ) ;
if ( F_103 ( ! F_74 ( V_4 -> V_132 ) ) ) {
#ifdef F_116
F_27 ( V_2 , L_19 ,
L_12 ) ;
#endif
return - V_99 ;
}
}
V_4 -> V_131 = V_66 ;
V_4 -> V_133 = V_129 ;
V_85 = (struct V_130 * ) ( V_4 -> V_132 ->
V_134 ) ;
V_85 -> V_131 = F_129 ( V_66 ) ;
V_85 -> V_133 = F_129 ( V_129 ) ;
V_85 -> V_135 = F_129 ( V_4 -> V_135 ) ;
F_130 ( V_4 -> V_132 ) ;
V_109 = F_107 ( V_2 ) ;
if ( F_120 ( V_2 ) )
F_121 ( V_4 -> V_132 , V_121 ) ;
else
F_115 ( V_4 -> V_132 ) ;
F_109 ( V_2 , V_109 ) ;
if ( ! F_74 ( V_4 -> V_132 ) ) {
F_27 ( V_2 , L_20 ,
L_21 ) ;
return - V_99 ;
}
}
return 0 ;
}
static int F_131 ( struct V_1 * V_2 ,
unsigned long V_129 ,
unsigned int V_66 )
{
return F_128 ( V_2 , V_129 , V_66 ) ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_17 * V_18 ;
struct V_38 * V_100 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_66 = V_39 -> V_65 ;
V_136:
V_18 = V_4 -> V_67 . V_20 ;
if ( V_18 == & V_4 -> V_67 )
return 0 ;
V_100 = F_55 ( V_18 ) ;
if ( V_100 -> V_65 < V_66 ) {
F_81 ( V_100 -> V_63 <= 0 ) ;
F_133 ( V_2 , V_100 , 0 ) ;
goto V_136;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
if ( ! F_54 ( & V_39 -> V_137 ) ) {
F_87 ( & V_39 -> V_137 ) ;
V_4 -> V_138 -- ;
}
}
static int F_133 ( struct V_1 * V_64 ,
struct V_38 * V_39 , int V_112 )
{
struct V_38 * V_139 ;
struct V_7 * V_46 , * V_126 ;
int V_140 ;
int V_141 = 0 ;
int V_142 = 0 ;
struct V_8 * V_143 ;
unsigned long V_144 = V_39 -> V_116 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
int V_145 = 0 ;
int V_109 ;
F_81 ( V_144 <= 0 ) ;
if ( F_88 ( & V_4 -> V_146 ) != 0 ) {
F_27 ( V_64 , L_22 , L_23 ,
F_88 ( & V_4 -> V_146 ) ) ;
}
if ( V_112 ) {
F_46 ( & V_4 -> V_147 , V_64 ) ;
} else if ( F_135 ( & V_4 -> V_147 ) ) {
F_43 () ;
}
V_140 = 0 ;
if ( V_144 > V_4 -> V_148 ) {
F_51 ( V_64 , L_24 , L_25 ,
V_144 , V_39 -> V_65 ) ;
return 0 ;
}
if ( F_88 ( & ( V_39 -> V_149 ) ) <= 0 &&
F_88 ( & ( V_39 -> V_107 ) ) <= 0 ) {
goto V_150;
}
F_29 ( V_64 , V_39 , 1 ) ;
if ( ! ( V_39 -> V_151 & V_152 )
&& ! F_118 ( V_4 ) )
F_43 () ;
if ( F_88 ( & ( V_39 -> V_149 ) ) <= 0 &&
F_88 ( & ( V_39 -> V_107 ) ) <= 0 ) {
goto V_150;
}
if ( F_88 ( & ( V_4 -> V_146 ) ) != 0 ) {
F_51 ( V_64 , L_26 , L_27
L_28 ) ;
}
V_46 = V_39 -> V_127 ;
while ( V_46 ) {
V_141 = 0 ;
V_142 = 0 ;
V_143 = NULL ;
if ( V_46 -> V_52 == 0 ) {
goto F_33;
}
if ( ! ( V_39 -> V_151 & V_152 ) )
goto F_33;
V_139 = F_125 ( V_46 ) ;
if ( ! V_139 && V_46 -> V_9 ) {
V_143 = V_46 -> V_9 ;
F_71 ( V_143 ) ;
if ( F_136 ( V_143 ) ) {
F_81 ( ! F_137 ( V_46 ) ) ;
V_141 = 1 ;
V_142 = 1 ;
} else if ( F_137 ( V_46 ) ) {
F_43 () ;
}
}
if ( V_139 ) {
if ( F_88 ( & V_139 -> V_107 ) )
F_29 ( V_64 , V_139 , 1 ) ;
goto F_33;
}
if ( V_143 == NULL ) {
goto F_33;
}
if ( ( ! V_141 ) && ! F_102 ( V_143 ) ) {
F_27 ( V_64 , L_29 ,
L_30
L_31 ,
( unsigned long long ) V_143 ->
V_74 , V_142 ? ' ' : '!' ,
V_141 ? ' ' : '!' ) ;
}
if ( V_142 ) {
F_71 ( V_143 ) ;
F_19 ( V_153 , & V_46 -> V_128 ) ;
F_138 ( V_143 ) ;
F_81 ( V_46 -> V_52 != V_143 -> V_74 ) ;
if ( F_97 ( V_143 ) )
F_70 ( V_143 ) ;
else
F_68 ( V_143 ) ;
V_140 ++ ;
} else {
F_27 ( V_64 , L_32 ,
L_33 ,
( unsigned long long ) V_143 ->
V_74 , V_123 ) ;
}
F_33:
V_126 = V_46 ;
V_46 = V_46 -> V_20 ;
if ( V_143 ) {
F_59 ( V_143 ) ;
if ( F_88 ( & ( V_143 -> V_154 ) ) < 0 ) {
F_27 ( V_64 , L_34 ,
L_35 ) ;
}
}
}
if ( V_140 > 0 ) {
V_46 = V_39 -> V_127 ;
while ( V_46 ) {
if ( F_41 ( V_153 , & V_46 -> V_128 ) ) {
if ( ! V_46 -> V_9 ) {
F_51 ( V_64 , L_36 ,
L_37 ) ;
}
V_109 = F_107 ( V_64 ) ;
F_114 ( V_46 -> V_9 ) ;
F_109 ( V_64 , V_109 ) ;
if ( ! V_46 -> V_9 ) {
F_51 ( V_64 , L_38 ,
L_37 ) ;
}
if ( F_103 ( ! F_74 ( V_46 -> V_9 ) ) ) {
#ifdef F_116
F_27 ( V_64 , L_39 ,
L_12 ) ;
#endif
V_145 = - V_99 ;
}
F_81 ( ! F_139
( V_46 -> V_9 ) ) ;
F_59 ( V_46 -> V_9 ) ;
F_56 ( V_46 -> V_9 ) ;
}
V_46 = V_46 -> V_20 ;
}
}
if ( V_145 )
F_124 ( V_64 , - V_99 ,
L_40 ,
V_123 ) ;
V_150:
if ( V_112 ) {
F_132 ( V_64 , V_39 ) ;
}
V_145 = V_4 -> V_96 ;
if ( ! V_145 && V_112 ) {
V_145 =
F_131 ( V_64 ,
( V_39 -> V_119 + V_39 -> V_116 +
2 ) % F_112 ( V_64 ) ,
V_39 -> V_65 ) ;
if ( V_145 )
F_124 ( V_64 , - V_99 ,
L_41 ,
V_123 ) ;
}
F_126 ( V_64 , V_39 , 0 ) ;
F_87 ( & V_39 -> V_105 ) ;
V_4 -> V_155 -- ;
F_134 ( V_64 , V_39 ) ;
if ( V_4 -> V_156 != 0 &&
( V_39 -> V_65 - V_4 -> V_156 ) != 1 ) {
F_27 ( V_64 , L_42 , L_43 ,
V_4 -> V_156 , V_39 -> V_65 ) ;
}
V_4 -> V_156 = V_39 -> V_65 ;
V_39 -> V_116 = 0 ;
F_110 ( & ( V_39 -> V_149 ) , 0 ) ;
V_39 -> V_119 = 0 ;
V_39 -> V_127 = NULL ;
V_39 -> V_120 = NULL ;
V_39 -> V_65 = 0 ;
V_39 -> V_151 = 0 ;
F_50 ( V_64 , V_39 ) ;
if ( V_112 )
F_48 ( & V_4 -> V_147 ) ;
return V_145 ;
}
static int F_140 ( struct V_1 * V_64 ,
struct V_38 * V_39 ,
struct V_78 * V_79 )
{
struct V_7 * V_46 ;
int V_82 = 0 ;
V_39 -> V_151 |= V_157 ;
F_134 ( V_64 , V_39 ) ;
if ( V_39 -> V_116 == 0 || F_88 ( & V_39 -> V_149 ) == 0 ) {
return 0 ;
}
V_46 = V_39 -> V_127 ;
while ( V_46 ) {
if ( V_46 -> V_52 == 0 ) {
goto V_20;
}
if ( V_46 -> V_9 && F_137 ( V_46 ) && F_97 ( V_46 -> V_9 ) ) {
struct V_8 * V_158 ;
V_158 = V_46 -> V_9 ;
F_71 ( V_158 ) ;
F_138 ( V_158 ) ;
if ( V_46 -> V_9 && F_137 ( V_46 ) && F_97 ( V_158 ) ) {
if ( ! F_136 ( V_158 ) ||
F_141 ( V_158 ) )
F_43 () ;
F_79 ( V_79 , V_158 , NULL , F_77 ) ;
V_82 ++ ;
} else {
F_68 ( V_158 ) ;
}
F_59 ( V_158 ) ;
}
V_20:
V_46 = V_46 -> V_20 ;
F_100 () ;
}
return V_82 ;
}
static int F_123 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
struct V_7 * V_46 ;
struct V_38 * V_139 ;
int V_82 = 0 ;
V_39 -> V_151 |= V_152 ;
V_46 = V_39 -> V_127 ;
while ( V_46 ) {
V_139 = F_125 ( V_46 ) ;
if ( ! V_139 && V_46 -> V_52 && V_46 -> V_9
&& F_136 ( V_46 -> V_9 ) ) {
F_81 ( ! F_137 ( V_46 ) ) ;
F_72 ( V_46 -> V_9 ) ;
if ( F_141 ( V_46 -> V_9 ) ) {
F_142 ( V_46 -> V_9 ) ;
} else {
F_143 ( V_46 -> V_9 ) ;
F_119 ( V_46 -> V_9 ) ;
}
}
V_46 = V_46 -> V_20 ;
}
return V_82 ;
}
static int F_144 ( struct V_1 * V_64 ,
struct V_38 * V_39 ,
struct V_38 * * V_159 ,
unsigned int * V_160 ,
int V_161 , int V_162 )
{
int V_82 = 0 ;
int V_163 = 0 ;
int V_164 = 0 ;
unsigned int V_165 = V_39 -> V_65 ;
struct V_78 V_79 ;
struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
V_79 . V_80 = 0 ;
F_46 ( & V_4 -> V_147 , V_64 ) ;
if ( ! F_53 ( V_64 , V_165 ) ) {
goto V_166;
}
while ( ( V_162 && V_164 < V_162 ) ||
( ! V_162 && V_163 < V_161 ) ) {
if ( V_39 -> V_116 == 0 || ( V_39 -> V_151 & V_157 ) ||
F_88 ( & V_39 -> V_107 )
|| ! ( V_39 -> V_151 & V_152 ) ) {
F_134 ( V_64 , V_39 ) ;
break;
}
V_82 = F_140 ( V_64 , V_39 , & V_79 ) ;
if ( V_82 < 0 )
goto V_166;
V_164 ++ ;
V_163 += V_82 ;
V_18 = V_39 -> V_105 . V_20 ;
if ( V_18 == & V_4 -> V_67 ) {
break;
}
V_39 = F_55 ( V_18 ) ;
if ( V_39 -> V_65 <= V_165 )
break;
}
if ( V_79 . V_80 ) {
F_77 ( & V_79 ) ;
}
V_166:
F_48 ( & V_4 -> V_147 ) ;
return V_82 ;
}
static int F_145 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
unsigned long V_167 = 0 ;
unsigned long V_168 ;
int V_82 ;
int V_25 ;
int V_169 = 256 ;
struct V_38 * V_170 ;
struct V_38 * V_171 ;
unsigned int V_66 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
V_171 = V_170 = V_39 ;
if ( F_146 ( V_64 ) )
V_169 = 1024 ;
for ( V_25 = 0 ; V_25 < 256 && V_167 < V_169 ; V_25 ++ ) {
if ( F_88 ( & V_170 -> V_107 ) ||
V_170 -> V_65 < V_39 -> V_65 ) {
break;
}
V_168 = F_88 ( & V_170 -> V_149 ) ;
if ( V_168 > 0 ) {
V_170 -> V_151 &= ~ V_157 ;
}
V_167 += V_168 ;
V_171 = V_170 ;
if ( V_170 -> V_105 . V_20 == & V_4 -> V_67 )
break;
V_170 = F_55 ( V_170 -> V_105 . V_20 ) ;
}
F_49 ( V_39 ) ;
F_49 ( V_171 ) ;
if ( V_171 != V_39 ) {
V_82 = F_144 ( V_64 , V_39 , & V_170 , & V_66 , V_167 , V_25 ) ;
}
F_133 ( V_64 , V_171 , 1 ) ;
F_50 ( V_64 , V_171 ) ;
F_50 ( V_64 , V_39 ) ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 ,
struct V_7 * * V_50 ,
struct V_38 * V_39 ,
unsigned long V_27 , int V_172 )
{
struct V_7 * V_173 ;
struct V_7 * * V_44 ;
V_44 = & ( F_38 ( V_50 , V_2 , V_27 ) ) ;
if ( ! V_44 ) {
return;
}
V_173 = * V_44 ;
while ( V_173 ) {
if ( V_173 -> V_52 == V_27 && V_173 -> V_2 == V_2
&& ( V_39 == NULL || V_39 == V_173 -> V_124 )
&& ( ! F_41 ( V_174 , & V_173 -> V_128 ) || V_172 ) ) {
if ( V_173 -> V_53 ) {
V_173 -> V_53 -> V_61 = V_173 -> V_61 ;
}
if ( V_173 -> V_61 ) {
V_173 -> V_61 -> V_53 = V_173 -> V_53 ;
} else {
* V_44 = V_173 -> V_53 ;
}
V_173 -> V_52 = 0 ;
V_173 -> V_2 = NULL ;
V_173 -> V_128 = 0 ;
if ( V_173 -> V_9 && V_173 -> V_124 )
F_89 ( & ( V_173 -> V_124 -> V_149 ) ) ;
V_173 -> V_9 = NULL ;
V_173 -> V_124 = NULL ;
}
V_173 = V_173 -> V_53 ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 -> V_91 ) ;
V_4 -> V_155 -- ;
F_23 ( V_4 -> V_175 ) ;
F_22 ( V_2 , V_4 -> V_42 ) ;
F_24 ( V_2 ) ;
if ( V_4 -> V_132 ) {
F_148 ( V_4 -> V_132 ) ;
}
F_149 ( V_2 , V_4 ) ;
F_23 ( V_4 ) ;
}
static int F_150 ( struct V_176 * V_177 ,
struct V_1 * V_2 , int error )
{
struct V_176 V_178 ;
int V_179 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! error && ! ( V_2 -> V_180 & V_181 ) ) {
F_81 ( ! V_177 -> V_182 ) ;
F_151 ( V_177 , V_2 , 10 , V_183 ) ;
if ( ! F_152 ( & V_178 , V_2 , 1 ) ) {
F_153 ( V_2 ,
F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_178 , V_2 ,
F_154 ( V_2 ) ) ;
F_151 ( & V_178 , V_2 , 1 , V_183 ) ;
V_179 = 1 ;
}
}
if ( ! error && F_118 ( V_4 ) ) {
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
if ( ! F_156 ( & V_178 , V_2 , 1 ) ) {
F_153 ( V_2 ,
F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_178 , V_2 ,
F_154 ( V_2 ) ) ;
F_151 ( & V_178 , V_2 , 1 , V_183 ) ;
}
}
V_184 -- ;
F_157 ( & F_2 ( V_2 ) -> V_185 ) ;
F_158 ( V_2 ) ;
F_159 ( & F_160 ( V_2 ) -> V_186 ) ;
F_161 ( V_187 ) ;
if ( ! V_184 ) {
F_162 ( V_187 ) ;
V_187 = NULL ;
}
F_147 ( V_2 ) ;
F_163 ( V_2 ) ;
return 0 ;
}
int F_164 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
return F_150 ( V_177 , V_2 , 0 ) ;
}
int F_165 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
return F_150 ( V_177 , V_2 , 1 ) ;
}
static int F_166 ( struct V_1 * V_2 ,
struct V_188 * V_189 ,
struct V_190 * V_191 )
{
if ( F_167 ( V_191 ) != F_168 ( V_189 ) ||
F_169 ( V_191 ) != F_170 ( V_189 ) ||
F_169 ( V_191 ) > F_2 ( V_2 ) -> V_148 ||
F_169 ( V_191 ) <= 0 ) {
return 1 ;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_8 * V_192 ,
unsigned int * V_193 ,
unsigned long * V_194 )
{
struct V_188 * V_189 ;
struct V_190 * V_191 ;
struct V_8 * V_195 ;
unsigned long V_129 ;
if ( ! V_192 )
return 0 ;
V_189 = (struct V_188 * ) V_192 -> V_134 ;
if ( F_170 ( V_189 ) > 0
&& ! memcmp ( F_172 ( V_192 ) , V_196 , 8 ) ) {
if ( V_193 && * V_193
&& F_168 ( V_189 ) > * V_193 ) {
F_173 ( V_2 , V_197 ,
L_44
L_45
L_46 ,
F_168 ( V_189 ) ,
* V_193 ) ;
return 0 ;
}
if ( V_194
&& * V_194 > F_174 ( V_189 ) ) {
F_173 ( V_2 , V_197 ,
L_47
L_48
L_49 ,
F_174 ( V_189 ) ,
* V_194 ) ;
return - 1 ;
}
if ( F_170 ( V_189 ) > F_2 ( V_2 ) -> V_148 ) {
F_27 ( V_2 , L_50 ,
L_51
L_52 ,
F_170 ( V_189 ) ) ;
return - 1 ;
}
V_129 = V_192 -> V_74 - F_111 ( V_2 ) ;
V_195 =
F_175 ( V_2 ,
F_111 ( V_2 ) +
( ( V_129 + F_170 ( V_189 ) +
1 ) % F_112 ( V_2 ) ) ) ;
if ( ! V_195 )
return 0 ;
V_191 = (struct V_190 * ) V_195 -> V_134 ;
if ( F_166 ( V_2 , V_189 , V_191 ) ) {
F_173 ( V_2 , V_197 ,
L_53
L_54 ,
V_195 -> V_74 -
F_111 ( V_2 ) ,
F_167 ( V_191 ) ,
F_169 ( V_191 ) ) ;
F_148 ( V_195 ) ;
if ( V_193 ) {
* V_193 =
F_168 ( V_189 ) ;
F_173 ( V_2 , V_197 ,
L_55
L_56
L_57 ,
F_168 ( V_189 ) ) ;
}
return - 1 ;
}
F_148 ( V_195 ) ;
F_173 ( V_2 , V_197 ,
L_58
L_59 ,
V_192 -> V_74 -
F_111 ( V_2 ) ,
F_170 ( V_189 ) ,
F_168 ( V_189 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static void F_176 ( struct V_8 * * V_198 , int V_199 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_199 ; V_25 ++ ) {
F_148 ( V_198 [ V_25 ] ) ;
}
}
static int F_177 ( struct V_1 * V_2 ,
unsigned long V_200 ,
unsigned long V_201 ,
unsigned int V_202 ,
unsigned long V_194 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_188 * V_189 ;
struct V_190 * V_191 ;
unsigned int V_66 = 0 ;
struct V_8 * V_195 ;
struct V_8 * V_192 ;
struct V_8 * * V_203 = NULL ;
struct V_8 * * V_204 = NULL ;
unsigned int V_205 ;
int V_25 ;
int V_206 ;
V_192 = F_175 ( V_2 , V_200 ) ;
if ( ! V_192 )
return 1 ;
V_189 = (struct V_188 * ) V_192 -> V_134 ;
V_205 = V_192 -> V_74 - F_111 ( V_2 ) ;
F_173 ( V_2 , V_197 , L_60
L_61 ,
V_192 -> V_74 - F_111 ( V_2 ) ,
F_170 ( V_189 ) , F_174 ( V_189 ) ) ;
if ( F_168 ( V_189 ) < V_202 ) {
F_173 ( V_2 , V_197 , L_62
L_63 ,
V_200 -
F_111 ( V_2 ) ) ;
F_148 ( V_192 ) ;
return 1 ;
}
if ( F_174 ( V_189 ) != V_194 ) {
F_173 ( V_2 , V_197 , L_64
L_65
L_49 , F_174 ( V_189 ) ,
V_194 ) ;
F_148 ( V_192 ) ;
return 1 ;
}
V_195 = F_175 ( V_2 , F_111 ( V_2 ) +
( ( V_205 + F_170 ( V_189 ) + 1 ) %
F_112 ( V_2 ) ) ) ;
if ( ! V_195 ) {
F_148 ( V_192 ) ;
return 1 ;
}
V_191 = (struct V_190 * ) V_195 -> V_134 ;
if ( F_166 ( V_2 , V_189 , V_191 ) ) {
F_173 ( V_2 , V_197 ,
L_66
L_67 ,
V_195 -> V_74 -
F_111 ( V_2 ) ,
F_167 ( V_191 ) ,
F_169 ( V_191 ) ) ;
F_148 ( V_195 ) ;
F_148 ( V_192 ) ;
return 1 ;
}
if ( F_178 ( V_2 -> V_207 ) ) {
F_27 ( V_2 , L_68 ,
L_69 ) ;
F_148 ( V_195 ) ;
F_148 ( V_192 ) ;
return - V_208 ;
}
V_66 = F_168 ( V_189 ) ;
V_203 = F_7 ( F_170 ( V_189 ) *
sizeof( struct V_8 * ) , V_13 ) ;
V_204 = F_7 ( F_170 ( V_189 ) *
sizeof( struct V_8 * ) , V_13 ) ;
if ( ! V_203 || ! V_204 ) {
F_148 ( V_195 ) ;
F_148 ( V_192 ) ;
F_9 ( V_203 ) ;
F_9 ( V_204 ) ;
F_27 ( V_2 , L_70 ,
L_71 ) ;
return - 1 ;
}
V_206 = F_179 ( V_2 -> V_15 ) ;
for ( V_25 = 0 ; V_25 < F_170 ( V_189 ) ; V_25 ++ ) {
V_203 [ V_25 ] =
F_180 ( V_2 ,
F_111 ( V_2 ) +
( V_205 + 1 +
V_25 ) % F_112 ( V_2 ) ) ;
if ( V_25 < V_206 ) {
V_204 [ V_25 ] =
F_181 ( V_2 ,
F_182 ( V_189 -> V_127 [ V_25 ] ) ) ;
} else {
V_204 [ V_25 ] =
F_181 ( V_2 ,
F_182 ( V_191 ->
V_127 [ V_25 - V_206 ] ) ) ;
}
if ( V_204 [ V_25 ] -> V_74 > F_183 ( V_2 ) ) {
F_27 ( V_2 , L_72 ,
L_73
L_74
L_75 ) ;
goto V_209;
}
if ( F_184
( V_2 , V_204 [ V_25 ] -> V_74 ) ) {
F_27 ( V_2 , L_76 ,
L_73
L_77 ) ;
V_209:
F_176 ( V_203 , V_25 ) ;
F_176 ( V_204 , V_25 ) ;
F_148 ( V_195 ) ;
F_148 ( V_192 ) ;
F_9 ( V_203 ) ;
F_9 ( V_204 ) ;
return - 1 ;
}
}
F_104 ( V_210 , F_170 ( V_189 ) , V_203 ) ;
for ( V_25 = 0 ; V_25 < F_170 ( V_189 ) ; V_25 ++ ) {
F_99 ( V_203 [ V_25 ] ) ;
if ( ! F_74 ( V_203 [ V_25 ] ) ) {
F_27 ( V_2 , L_78 ,
L_73
L_12 ) ;
F_176 ( V_203 + V_25 ,
F_170 ( V_189 ) - V_25 ) ;
F_176 ( V_204 , F_170 ( V_189 ) ) ;
F_148 ( V_195 ) ;
F_148 ( V_192 ) ;
F_9 ( V_203 ) ;
F_9 ( V_204 ) ;
return - 1 ;
}
memcpy ( V_204 [ V_25 ] -> V_134 , V_203 [ V_25 ] -> V_134 ,
V_204 [ V_25 ] -> V_211 ) ;
F_66 ( V_204 [ V_25 ] ) ;
F_148 ( V_203 [ V_25 ] ) ;
}
for ( V_25 = 0 ; V_25 < F_170 ( V_189 ) ; V_25 ++ ) {
F_130 ( V_204 [ V_25 ] ) ;
F_185 ( V_204 [ V_25 ] , V_77 ) ;
}
for ( V_25 = 0 ; V_25 < F_170 ( V_189 ) ; V_25 ++ ) {
F_99 ( V_204 [ V_25 ] ) ;
if ( ! F_74 ( V_204 [ V_25 ] ) ) {
F_27 ( V_2 , L_79 ,
L_80
L_12 ) ;
F_176 ( V_204 + V_25 ,
F_170 ( V_189 ) - V_25 ) ;
F_148 ( V_195 ) ;
F_148 ( V_192 ) ;
F_9 ( V_203 ) ;
F_9 ( V_204 ) ;
return - 1 ;
}
F_148 ( V_204 [ V_25 ] ) ;
}
V_200 =
F_111 ( V_2 ) +
( ( V_205 + F_170 ( V_189 ) +
2 ) % F_112 ( V_2 ) ) ;
F_173 ( V_2 , V_197 ,
L_81 L_82 ,
V_200 - F_111 ( V_2 ) ) ;
V_4 -> V_119 = V_200 - F_111 ( V_2 ) ;
V_4 -> V_131 = V_66 ;
V_4 -> V_65 = V_66 + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
F_148 ( V_195 ) ;
F_148 ( V_192 ) ;
F_9 ( V_203 ) ;
F_9 ( V_204 ) ;
return 0 ;
}
static struct V_8 * F_186 ( struct V_212 * V_213 ,
T_1 V_27 , int V_214 ,
T_1 V_215 )
{
struct V_8 * V_216 [ V_217 ] ;
unsigned int V_218 = V_217 ;
struct V_8 * V_9 ;
int V_25 , V_40 ;
V_9 = F_187 ( V_213 , V_27 , V_214 ) ;
if ( F_74 ( V_9 ) )
return ( V_9 ) ;
if ( V_27 + V_217 > V_215 ) {
V_218 = V_215 - V_27 ;
}
V_216 [ 0 ] = V_9 ;
V_40 = 1 ;
for ( V_25 = 1 ; V_25 < V_218 ; V_25 ++ ) {
V_9 = F_187 ( V_213 , V_27 + V_25 , V_214 ) ;
if ( F_74 ( V_9 ) ) {
F_148 ( V_9 ) ;
break;
} else
V_216 [ V_40 ++ ] = V_9 ;
}
F_104 ( V_210 , V_40 , V_216 ) ;
for ( V_25 = 1 ; V_25 < V_40 ; V_25 ++ )
F_148 ( V_216 [ V_25 ] ) ;
V_9 = V_216 [ 0 ] ;
F_99 ( V_9 ) ;
if ( F_74 ( V_9 ) )
return V_9 ;
F_148 ( V_9 ) ;
return NULL ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_188 * V_189 ;
unsigned int V_202 = 0 ;
unsigned int V_193 = 0 ;
T_3 V_219 ;
unsigned long V_201 = 0 ;
unsigned long V_200 = 0 ;
unsigned long V_194 = 9 ;
struct V_8 * V_192 ;
struct V_130 * V_85 ;
int V_220 = 0 ;
int V_221 = 0 ;
int V_222 = 1 ;
int V_82 ;
char V_72 [ V_73 ] ;
V_200 = F_111 ( V_2 ) ;
F_189 ( V_2 , L_83 ,
F_65 ( V_4 -> V_223 , V_72 ) ) ;
V_219 = F_190 () ;
V_4 -> V_132 = F_175 ( V_2 ,
F_111 ( V_2 )
+ F_112 ( V_2 ) ) ;
if ( ! V_4 -> V_132 ) {
return 1 ;
}
V_85 = (struct V_130 * ) ( V_4 -> V_132 -> V_134 ) ;
if ( F_182 ( V_85 -> V_133 ) <
F_112 ( V_2 )
&& F_182 ( V_85 -> V_131 ) > 0 ) {
V_201 =
F_111 ( V_2 ) +
F_182 ( V_85 -> V_133 ) ;
V_202 = F_182 ( V_85 -> V_131 ) + 1 ;
V_194 = F_182 ( V_85 -> V_135 ) ;
F_173 ( V_2 , V_197 ,
L_84
L_85
L_86 , F_182 ( V_85 -> V_133 ) ,
F_182 ( V_85 -> V_131 ) ) ;
V_220 = 1 ;
V_192 =
F_175 ( V_2 ,
F_111 ( V_2 ) +
F_182 ( V_85 -> V_133 ) ) ;
V_82 = F_171 ( V_2 , V_192 , NULL , NULL ) ;
if ( ! V_82 ) {
V_222 = 0 ;
}
F_148 ( V_192 ) ;
goto V_224;
}
while ( V_222
&& V_200 <
( F_111 ( V_2 ) +
F_112 ( V_2 ) ) ) {
V_192 =
F_186 ( V_4 -> V_223 , V_200 ,
V_2 -> V_15 ,
F_111 ( V_2 ) +
F_112 ( V_2 ) ) ;
V_82 =
F_171 ( V_2 , V_192 ,
& V_193 ,
& V_194 ) ;
if ( V_82 == 1 ) {
V_189 = (struct V_188 * ) V_192 -> V_134 ;
if ( V_201 == 0 ) {
V_202 = F_168 ( V_189 ) ;
V_201 = V_192 -> V_74 ;
V_194 = F_174 ( V_189 ) ;
F_173 ( V_2 , V_197 ,
L_87
L_88 ,
V_201 -
F_111
( V_2 ) , V_202 ) ;
} else if ( V_202 > F_168 ( V_189 ) ) {
V_202 = F_168 ( V_189 ) ;
V_201 = V_192 -> V_74 ;
F_173 ( V_2 , V_197 ,
L_89
L_90 ,
V_201 -
F_111
( V_2 ) , V_202 ) ;
}
if ( V_194 < F_174 ( V_189 ) ) {
V_194 = F_174 ( V_189 ) ;
F_173 ( V_2 , V_197 ,
L_91
L_92 ,
F_174 ( V_189 ) ) ;
}
V_200 += F_170 ( V_189 ) + 2 ;
} else {
V_200 ++ ;
}
F_148 ( V_192 ) ;
}
V_224:
V_200 = V_201 ;
if ( V_202 ) {
F_173 ( V_2 , V_197 ,
L_93
L_94 ,
V_200 - F_111 ( V_2 ) ,
V_202 ) ;
}
V_221 = 0 ;
while ( V_222 && V_202 > 0 ) {
V_82 =
F_177 ( V_2 , V_200 , V_201 ,
V_202 , V_194 ) ;
if ( V_82 < 0 ) {
return V_82 ;
} else if ( V_82 != 0 ) {
break;
}
V_200 =
F_111 ( V_2 ) + V_4 -> V_119 ;
V_221 ++ ;
if ( V_200 == V_201 )
break;
}
if ( V_202 == 0 ) {
F_173 ( V_2 , V_197 ,
L_95 L_96 ) ;
}
if ( V_220 && V_221 == 0 ) {
V_4 -> V_119 = F_182 ( V_85 -> V_133 ) ;
V_4 -> V_65 =
F_182 ( V_85 -> V_131 ) + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_131 =
F_182 ( V_85 -> V_131 ) ;
V_4 -> V_135 = F_182 ( V_85 -> V_135 ) + 1 ;
} else {
V_4 -> V_135 = V_194 + 1 ;
}
F_173 ( V_2 , V_197 , L_91
L_97 , V_4 -> V_135 ) ;
V_4 -> V_133 = V_4 -> V_119 ;
if ( V_221 > 0 ) {
F_189 ( V_2 ,
L_98 ,
V_221 , F_190 () - V_219 ) ;
}
F_163 ( V_2 ) ;
if ( ! F_178 ( V_2 -> V_207 ) &&
F_128 ( V_2 , V_4 -> V_119 ,
V_4 -> V_131 ) ) {
F_158 ( V_2 ) ;
return - 1 ;
}
F_158 ( V_2 ) ;
return 0 ;
}
static struct V_38 * F_191 ( struct V_1 * V_64 )
{
struct V_38 * V_39 ;
V_39 = F_8 ( sizeof( struct V_38 ) ,
V_13 | V_225 ) ;
F_10 ( & V_39 -> V_105 ) ;
F_10 ( & V_39 -> V_137 ) ;
F_10 ( & V_39 -> V_92 ) ;
F_10 ( & V_39 -> V_93 ) ;
F_192 ( & V_39 -> V_118 ) ;
F_2 ( V_64 ) -> V_155 ++ ;
F_49 ( V_39 ) ;
return V_39 ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) -> V_91 = F_191 ( V_2 ) ;
}
static void F_149 ( struct V_1 * V_226 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_223 != NULL ) {
F_194 ( V_4 -> V_223 , V_4 -> V_227 ) ;
V_4 -> V_223 = NULL ;
}
}
static int F_195 ( struct V_1 * V_226 ,
struct V_3 * V_4 ,
const char * V_228 )
{
int V_229 ;
T_4 V_230 ;
T_5 V_231 = V_232 | V_233 | V_234 ;
char V_72 [ V_73 ] ;
V_229 = 0 ;
V_4 -> V_223 = NULL ;
V_230 = F_196 ( V_226 ) ?
F_197 ( F_196 ( V_226 ) ) : V_226 -> V_235 ;
if ( F_178 ( V_226 -> V_207 ) )
V_231 = V_232 ;
if ( ( ! V_228 || ! V_228 [ 0 ] ) ) {
if ( V_230 == V_226 -> V_235 )
V_231 &= ~ V_234 ;
V_4 -> V_223 = F_198 ( V_230 , V_231 ,
V_4 ) ;
V_4 -> V_227 = V_231 ;
if ( F_199 ( V_4 -> V_223 ) ) {
V_229 = F_200 ( V_4 -> V_223 ) ;
V_4 -> V_223 = NULL ;
F_27 ( V_226 , L_99 ,
L_100 ,
F_201 ( V_230 , V_72 ) , V_229 ) ;
return V_229 ;
} else if ( V_230 != V_226 -> V_235 )
F_202 ( V_4 -> V_223 , V_226 -> V_15 ) ;
return 0 ;
}
V_4 -> V_227 = V_231 ;
V_4 -> V_223 = F_203 ( V_228 , V_231 , V_4 ) ;
if ( F_199 ( V_4 -> V_223 ) ) {
V_229 = F_200 ( V_4 -> V_223 ) ;
V_4 -> V_223 = NULL ;
F_27 ( V_226 ,
L_101 ,
V_228 , V_229 ) ;
return V_229 ;
}
F_202 ( V_4 -> V_223 , V_226 -> V_15 ) ;
F_189 ( V_226 ,
L_102 ,
F_65 ( V_4 -> V_223 , V_72 ) ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_148 ) {
int V_236 = 1 ;
if ( V_2 -> V_15 < V_237 )
V_236 = V_237 / V_2 -> V_15 ;
if ( V_4 -> V_148 > V_238 / V_236 ||
V_4 -> V_148 < V_239 / V_236 ||
F_112 ( V_2 ) / V_4 -> V_148 <
V_240 ) {
F_27 ( V_2 , L_103 ,
L_104
L_105 , V_4 -> V_148 ) ;
return 1 ;
}
if ( V_4 -> V_241 != ( V_4 -> V_148 ) *
V_242 / V_238 ) {
F_27 ( V_2 , L_106 ,
L_107
L_105 , V_4 -> V_241 ) ;
return 1 ;
}
} else {
if ( V_2 -> V_15 != V_237 ) {
F_27 ( V_2 , L_108 , L_109 ,
V_2 -> V_15 ) ;
return 1 ;
}
V_4 -> V_148 = V_238 ;
V_4 -> V_241 = V_242 ;
V_4 -> V_243 = V_244 ;
}
return 0 ;
}
int F_205 ( struct V_1 * V_2 , const char * V_245 ,
int V_246 , unsigned int V_247 )
{
int V_43 = F_112 ( V_2 ) * 2 ;
struct V_8 * V_248 ;
struct V_249 * V_250 ;
struct V_130 * V_85 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
char V_72 [ V_73 ] ;
int V_82 ;
V_4 = F_2 ( V_2 ) = F_26 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 ) {
F_27 ( V_2 , L_110 ,
L_111 ) ;
return 1 ;
}
F_10 ( & V_4 -> V_19 ) ;
F_10 ( & V_4 -> V_251 ) ;
F_10 ( & V_4 -> V_137 ) ;
F_10 ( & V_4 -> V_67 ) ;
V_4 -> V_252 = 0 ;
if ( F_25 ( V_2 , V_4 -> V_42 ,
F_21 ( V_2 ) ) )
goto V_253;
F_17 ( V_2 ) ;
F_206 ( V_2 ) = ( V_246 ?
V_254
/ V_2 -> V_15 +
F_21 ( V_2 ) +
1 :
V_255 /
V_2 -> V_15 + 2 ) ;
if ( ! F_196 ( V_2 ) &&
( F_206 ( V_2 ) +
F_112 ( V_2 ) > V_2 -> V_15 * 8 ) ) {
F_27 ( V_2 , L_112 ,
L_113
L_114
L_115 ,
F_206 ( V_2 ) ,
F_112 ( V_2 ) ,
V_2 -> V_15 ) ;
goto V_253;
}
if ( F_195 ( V_2 , V_4 , V_245 ) != 0 ) {
F_27 ( V_2 , L_103 ,
L_116 ) ;
goto V_253;
}
V_250 = F_207 ( V_2 ) ;
V_248 = F_175 ( V_2 ,
F_111 ( V_2 ) +
F_112 ( V_2 ) ) ;
if ( ! V_248 ) {
F_27 ( V_2 , L_117 ,
L_118 ) ;
goto V_253;
}
V_85 = (struct V_130 * ) ( V_248 -> V_134 ) ;
if ( F_208 ( V_250 )
&& ( F_182 ( V_85 -> V_256 . V_257 ) !=
F_209 ( V_250 ) ) ) {
F_27 ( V_2 , L_119 ,
L_120
L_121 ,
V_85 -> V_256 . V_257 ,
F_65 ( V_4 -> V_223 , V_72 ) ,
F_209 ( V_250 ) ) ;
F_148 ( V_248 ) ;
goto V_253;
}
V_4 -> V_148 = F_182 ( V_85 -> V_256 . V_258 ) ;
V_4 -> V_241 = F_182 ( V_85 -> V_256 . V_259 ) ;
V_4 -> V_243 =
F_182 ( V_85 -> V_256 . V_260 ) ;
V_4 -> V_261 = V_262 ;
if ( F_204 ( V_2 , V_4 ) != 0 )
goto V_253;
V_4 -> V_263 = V_4 -> V_243 ;
if ( V_247 != 0 ) {
V_4 -> V_243 = V_247 ;
V_4 -> V_261 = V_247 ;
}
F_189 ( V_2 , L_122
L_123
L_124 ,
F_65 ( V_4 -> V_223 , V_72 ) ,
F_112 ( V_2 ) ,
F_111 ( V_2 ) ,
V_4 -> V_148 ,
V_4 -> V_241 ,
V_4 -> V_243 , V_4 -> V_261 ) ;
F_148 ( V_248 ) ;
V_4 -> V_41 = 0 ;
F_193 ( V_2 ) ;
memset ( V_4 -> V_58 , 0 ,
V_6 * sizeof( struct V_7 * ) ) ;
F_10 ( & V_4 -> V_264 ) ;
F_210 ( & V_4 -> V_89 ) ;
V_4 -> V_119 = 0 ;
V_4 -> V_116 = 0 ;
V_4 -> V_265 = 0 ;
F_110 ( & ( V_4 -> V_146 ) , 0 ) ;
F_110 ( & ( V_4 -> V_108 ) , 0 ) ;
V_4 -> V_266 = 0 ;
V_4 -> V_267 = 0 ;
V_4 -> V_268 = NULL ;
V_4 -> V_269 = NULL ;
F_211 ( & ( V_4 -> V_270 ) ) ;
F_192 ( & V_4 -> V_62 ) ;
F_192 ( & V_4 -> V_147 ) ;
V_4 -> V_65 = 10 ;
V_4 -> V_135 = 10 ;
V_4 -> V_151 = 0 ;
F_110 ( & ( V_4 -> V_271 ) , 0 ) ;
V_4 -> V_49 = F_30 ( V_43 ) ;
V_4 -> V_175 = V_4 -> V_49 ;
V_4 -> V_47 = V_4 -> V_49 ? V_43 : 0 ;
V_4 -> V_48 = 0 ;
V_4 -> V_272 = 0 ;
if ( V_4 -> V_47 == 0 ) {
F_27 ( V_2 , L_125 , L_126
L_127
L_128
L_129 ,
sizeof ( struct V_7 ) * V_43 ) ;
goto V_253;
}
F_1 ( V_2 ) ;
V_39 = V_4 -> V_91 ;
F_163 ( V_2 ) ;
V_39 -> V_42 = F_28 ( V_2 , V_39 ) ;
F_158 ( V_2 ) ;
if ( ! V_39 -> V_42 ) {
F_27 ( V_2 , L_130 ,
L_131 ) ;
goto V_253;
}
V_82 = F_188 ( V_2 ) ;
if ( V_82 < 0 ) {
F_27 ( V_2 , L_132 ,
L_133 ) ;
goto V_253;
}
V_184 ++ ;
if ( V_184 <= 1 )
V_187 = F_212 ( L_134 , V_273 , 0 ) ;
F_213 ( & V_4 -> V_185 , V_274 ) ;
V_4 -> V_275 = V_2 ;
return 0 ;
V_253:
F_147 ( V_2 ) ;
return 1 ;
}
int F_214 ( struct V_176 * V_177 ,
int V_276 )
{
struct V_3 * V_4 = F_2 ( V_177 -> V_277 ) ;
T_3 V_278 = F_190 () ;
F_81 ( ! V_177 -> V_182 ) ;
if ( V_177 -> V_279 > 1 )
return 0 ;
if ( V_4 -> V_272 > 0 ||
( V_4 -> V_265 + V_276 ) >= V_4 -> V_241 ||
F_88 ( & ( V_4 -> V_271 ) ) ||
( V_278 - V_4 -> V_267 ) > V_4 -> V_261 ||
V_4 -> V_47 < ( V_4 -> V_148 * 3 ) ) {
return 1 ;
}
V_4 -> V_265 += V_276 ;
V_177 -> V_280 += V_276 ;
return 0 ;
}
void F_215 ( struct V_176 * V_177 )
{
struct V_3 * V_4 = F_2 ( V_177 -> V_277 ) ;
F_81 ( ! V_177 -> V_182 ) ;
V_4 -> V_272 = 1 ;
F_19 ( V_281 , & V_4 -> V_151 ) ;
return;
}
void F_216 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_217 ( V_281 , & V_4 -> V_151 ) ;
F_218 ( & V_4 -> V_270 ) ;
}
void F_219 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_220 ( V_4 -> V_270 ,
! F_41 ( V_281 , & V_4 -> V_151 ) ) ;
}
static void F_221 ( struct V_1 * V_64 )
{
T_6 V_282 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_19 ( V_283 , & V_4 -> V_151 ) ;
F_222 ( & V_282 , V_284 ) ;
F_223 ( & V_4 -> V_270 , & V_282 ) ;
F_224 ( V_285 ) ;
if ( F_41 ( V_283 , & V_4 -> V_151 ) ) {
int V_109 = F_107 ( V_64 ) ;
F_225 () ;
F_109 ( V_64 , V_109 ) ;
}
F_226 ( V_286 ) ;
F_227 ( & V_4 -> V_270 , & V_282 ) ;
}
static void F_228 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
if ( F_229 ( V_283 , & V_4 -> V_151 ) )
F_218 ( & V_4 -> V_270 ) ;
}
static void F_230 ( struct V_1 * V_2 , unsigned int V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_287 = V_4 -> V_266 ;
while ( 1 ) {
int V_109 ;
V_109 = F_107 ( V_2 ) ;
F_231 ( 1 ) ;
F_109 ( V_2 , V_109 ) ;
V_4 -> V_91 -> V_151 |= V_288 ;
while ( ( F_88 ( & V_4 -> V_146 ) > 0 ||
F_88 ( & V_4 -> V_271 ) ) &&
V_4 -> V_65 == V_66 ) {
F_221 ( V_2 ) ;
}
if ( V_4 -> V_65 != V_66 )
break;
if ( V_287 == V_4 -> V_266 )
break;
V_287 = V_4 -> V_266 ;
}
}
static int F_232 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 ,
int V_290 )
{
T_3 V_278 = F_190 () ;
unsigned int V_291 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_176 V_178 ;
int V_292 = 0 ;
int V_114 ;
int V_109 ;
F_32 ( V_2 , L_135 ) ;
F_81 ( V_289 > V_4 -> V_148 ) ;
F_40 ( V_2 , V_4 . V_293 ) ;
V_177 -> V_279 = 1 ;
V_177 -> V_277 = V_2 ;
V_294:
F_45 ( V_2 ) ;
if ( V_290 != V_295 && F_118 ( V_4 ) ) {
F_47 ( V_2 ) ;
V_114 = V_4 -> V_96 ;
goto V_296;
}
V_4 -> V_266 ++ ;
if ( F_41 ( V_281 , & V_4 -> V_151 ) ) {
F_47 ( V_2 ) ;
V_109 = F_107 ( V_2 ) ;
F_219 ( V_2 ) ;
F_109 ( V_2 , V_109 ) ;
F_40 ( V_2 , V_4 . V_297 ) ;
goto V_294;
}
V_278 = F_190 () ;
if ( ( ! V_290 && V_4 -> V_272 > 0 ) ||
( ! V_290
&& ( V_4 -> V_265 + V_289 + 2 ) >= V_4 -> V_241 )
|| ( ! V_290 && F_88 ( & V_4 -> V_146 ) > 0
&& V_4 -> V_267 > 0
&& ( V_278 - V_4 -> V_267 ) >
V_4 -> V_261 ) || ( ! V_290
&& F_88 ( & V_4 -> V_271 ) )
|| ( ! V_290 && V_4 -> V_47 < ( V_4 -> V_148 * 3 ) ) ) {
V_291 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
if ( ! V_290 && ( V_4 -> V_265 + V_289 + 2 ) >=
V_4 -> V_241 &&
( ( V_4 -> V_116 + V_289 + 2 ) * 100 ) <
( V_4 -> V_265 * 75 ) ) {
if ( F_88 ( & V_4 -> V_146 ) > 10 ) {
V_292 ++ ;
F_221 ( V_2 ) ;
goto V_294;
}
}
if ( F_88 ( & V_4 -> V_271 ) ) {
while ( V_4 -> V_65 == V_291 &&
F_88 ( & V_4 -> V_271 ) ) {
F_221 ( V_2 ) ;
}
goto V_294;
}
V_114 = F_152 ( & V_178 , V_2 , 1 ) ;
if ( V_114 )
goto V_296;
if ( V_291 != V_4 -> V_65 ) {
V_114 = F_151 ( & V_178 , V_2 , 1 , 0 ) ;
} else {
V_114 = F_151 ( & V_178 , V_2 , 1 , V_298 ) ;
}
if ( V_114 )
goto V_296;
F_40 ( V_2 , V_4 . V_299 ) ;
goto V_294;
}
if ( V_4 -> V_267 == 0 ) {
V_4 -> V_267 = F_190 () ;
}
F_85 ( & ( V_4 -> V_146 ) ) ;
V_4 -> V_265 += V_289 ;
V_177 -> V_300 = 0 ;
V_177 -> V_280 = V_289 ;
V_177 -> V_182 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
F_10 ( & V_177 -> V_301 ) ;
return 0 ;
V_296:
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_177 -> V_277 = V_2 ;
return V_114 ;
}
struct V_176 * F_233 ( struct
V_1
* V_64 ,
int V_289 )
{
int V_82 ;
struct V_176 * V_177 ;
if ( F_234 ( V_64 ) ) {
V_177 = V_284 -> V_302 ;
V_177 -> V_279 ++ ;
F_81 ( V_177 -> V_279 < 2 ) ;
return V_177 ;
}
V_177 = F_7 ( sizeof( struct V_176 ) , V_13 ) ;
if ( ! V_177 )
return NULL ;
V_82 = F_235 ( V_177 , V_64 , V_289 ) ;
if ( V_82 ) {
F_9 ( V_177 ) ;
return NULL ;
}
F_2 ( V_64 ) -> V_252 ++ ;
return V_177 ;
}
int F_236 ( struct V_176 * V_177 )
{
struct V_1 * V_64 = V_177 -> V_277 ;
int V_82 = 0 ;
if ( V_177 -> V_182 )
V_82 = F_237 ( V_177 , V_177 -> V_277 , V_177 -> V_280 ) ;
else
V_82 = - V_99 ;
if ( V_177 -> V_279 == 0 ) {
F_2 ( V_64 ) -> V_252 -- ;
F_9 ( V_177 ) ;
}
return V_82 ;
}
static int F_152 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 )
{
struct V_176 * V_303 = V_284 -> V_302 ;
V_177 -> V_304 = V_303 ;
F_81 ( V_303 && V_303 -> V_279 > 1 ) ;
return F_232 ( V_177 , V_2 , V_289 , V_305 ) ;
}
int F_156 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 )
{
struct V_176 * V_303 = V_284 -> V_302 ;
V_177 -> V_304 = V_303 ;
F_81 ( V_303 && V_303 -> V_279 > 1 ) ;
return F_232 ( V_177 , V_2 , V_289 , V_295 ) ;
}
int F_235 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 )
{
struct V_176 * V_303 = V_284 -> V_302 ;
int V_82 ;
V_177 -> V_304 = NULL ;
if ( V_303 ) {
if ( V_303 -> V_277 == V_2 ) {
F_81 ( ! V_303 -> V_279 ) ;
V_303 -> V_279 ++ ;
memcpy ( V_177 , V_303 , sizeof( * V_177 ) ) ;
if ( V_177 -> V_279 <= 1 )
F_27 ( V_2 , L_136 ,
L_137
L_138 ) ;
return 0 ;
} else {
F_27 ( V_2 , L_139 ,
L_140 ) ;
V_177 -> V_304 = V_284 -> V_302 ;
V_284 -> V_302 = V_177 ;
}
} else {
V_284 -> V_302 = V_177 ;
}
V_82 = F_232 ( V_177 , V_2 , V_289 , V_306 ) ;
F_81 ( V_284 -> V_302 != V_177 ) ;
if ( V_82 )
V_284 -> V_302 = V_177 -> V_304 ;
else
F_81 ( ! V_177 -> V_279 ) ;
return V_82 ;
}
int F_155 ( struct V_176 * V_177 ,
struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
int V_307 = 0 ;
int V_308 = 0 ;
F_81 ( ! V_177 -> V_182 ) ;
F_40 ( V_2 , V_4 . V_309 ) ;
if ( V_177 -> V_182 != V_4 -> V_65 ) {
F_51 ( V_177 -> V_277 , L_141 ,
L_142 ,
V_177 -> V_182 , V_4 -> V_65 ) ;
}
V_308 = F_238 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( F_64 ( V_9 ) ) {
F_40 ( V_2 , V_4 . V_310 ) ;
return 0 ;
}
if ( ! V_308 || F_97 ( V_9 ) ) {
F_27 ( V_2 , L_143 ,
L_144
L_145 ,
( unsigned long long ) V_9 -> V_74 ,
V_308 ? ' ' : '!' ,
F_102 ( V_9 ) ? ' ' : '!' ,
F_97 ( V_9 ) ? ' ' : '!' ,
F_136 ( V_9 ) ? ' ' : '!' ) ;
}
if ( F_88 ( & ( V_4 -> V_146 ) ) <= 0 ) {
F_27 ( V_2 , L_146 ,
L_147 ,
F_88 ( & ( V_4 -> V_146 ) ) ) ;
return 1 ;
}
if ( V_4 -> V_116 >= V_4 -> V_148 ) {
F_51 ( V_177 -> V_277 , L_148 ,
L_149 ,
V_4 -> V_116 ) ;
}
if ( F_136 ( V_9 ) ) {
V_307 = 1 ;
F_40 ( V_2 , V_4 . V_311 ) ;
F_239 ( V_9 ) ;
}
if ( V_4 -> V_116 > V_4 -> V_265 ) {
V_4 -> V_265 = V_4 -> V_116 + V_312 ;
}
F_240 ( V_9 ) ;
if ( ! V_46 ) {
V_46 = F_31 ( V_2 ) ;
if ( ! V_46 ) {
F_51 ( V_2 , L_150 , L_151 ) ;
}
if ( V_177 -> V_300 == V_177 -> V_280 ) {
V_177 -> V_280 += V_312 ;
V_4 -> V_265 += V_312 ;
}
V_177 -> V_300 ++ ;
V_4 -> V_116 ++ ;
V_46 -> V_9 = V_9 ;
V_46 -> V_52 = V_9 -> V_74 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_124 = NULL ;
F_44 ( V_4 -> V_5 , V_46 ) ;
if ( ! V_307 ) {
F_71 ( V_9 ) ;
}
}
V_46 -> V_20 = NULL ;
V_46 -> V_45 = V_4 -> V_268 ;
V_46 -> V_9 = V_9 ;
if ( V_4 -> V_268 ) {
V_4 -> V_268 -> V_20 = V_46 ;
V_4 -> V_268 = V_46 ;
} else {
V_4 -> V_269 = V_46 ;
V_4 -> V_268 = V_46 ;
}
F_241 ( V_2 ) ;
return 0 ;
}
int F_237 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 )
{
if ( ! V_284 -> V_302 && V_177 -> V_279 > 1 )
F_27 ( V_2 , L_152 ,
L_153 , V_177 -> V_279 ) ;
if ( ! V_177 -> V_182 ) {
F_242 ( 1 ) ;
return - V_99 ;
}
V_177 -> V_279 -- ;
if ( V_177 -> V_279 > 0 ) {
struct V_176 * V_303 =
V_284 -> V_302 ;
F_81 ( V_303 -> V_277 != V_177 -> V_277 ) ;
if ( V_177 != V_303 ) {
memcpy ( V_284 -> V_302 , V_177 , sizeof( * V_177 ) ) ;
V_177 -> V_182 = 0 ;
}
return 0 ;
} else {
return F_151 ( V_177 , V_2 , V_289 , 0 ) ;
}
}
static int F_243 ( struct V_1 * V_2 ,
T_1 V_52 , int V_313 )
{
struct V_8 * V_9 ;
struct V_7 * V_46 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_82 = 0 ;
V_46 = F_37 ( V_2 , V_4 -> V_5 , V_52 ) ;
if ( ! V_46 || ! V_46 -> V_9 ) {
return V_82 ;
}
V_9 = V_46 -> V_9 ;
if ( V_46 -> V_45 ) {
V_46 -> V_45 -> V_20 = V_46 -> V_20 ;
}
if ( V_46 -> V_20 ) {
V_46 -> V_20 -> V_45 = V_46 -> V_45 ;
}
if ( V_46 == V_4 -> V_269 ) {
V_4 -> V_269 = V_46 -> V_20 ;
}
if ( V_46 == V_4 -> V_268 ) {
V_4 -> V_268 = V_46 -> V_45 ;
}
if ( V_9 )
F_127 ( V_2 , V_4 -> V_5 , NULL ,
V_9 -> V_74 , 0 ) ;
F_244 ( V_9 ) ;
if ( ! V_313 ) {
F_239 ( V_9 ) ;
F_4 ( V_9 ) ;
F_5 ( V_9 ) ;
F_59 ( V_9 ) ;
if ( F_88 ( & ( V_9 -> V_154 ) ) < 0 ) {
F_27 ( V_2 , L_154 ,
L_155 ) ;
}
V_82 = 1 ;
}
V_4 -> V_116 -- ;
V_4 -> V_265 -- ;
F_33 ( V_2 , V_46 ) ;
return V_82 ;
}
static int F_137 ( struct V_7 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
T_1 V_52 = V_46 -> V_52 ;
struct V_7 * V_173 = V_46 -> V_61 ;
int F_137 = 1 ;
while ( V_173 && F_137 ) {
if ( V_173 -> V_124 && V_173 -> V_9 && V_173 -> V_52 && V_173 -> V_2 == V_2 &&
V_173 -> V_52 == V_52 ) {
F_137 = 0 ;
}
V_173 = V_173 -> V_61 ;
}
V_173 = V_46 -> V_53 ;
while ( V_173 && F_137 ) {
if ( V_173 -> V_124 && V_173 -> V_124 -> V_116 > 0 &&
F_88 ( & ( V_173 -> V_124 -> V_107 ) ) > 0 && V_173 -> V_9 &&
V_173 -> V_52 && V_173 -> V_2 == V_2 && V_173 -> V_52 == V_52 ) {
F_137 = 0 ;
}
V_173 = V_173 -> V_53 ;
}
return F_137 ;
}
int F_245 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_81 ( ! V_177 -> V_182 ) ;
F_81 ( V_177 -> V_279 > 1 ) ;
if ( V_4 -> V_116 == 0 ) {
F_153 ( V_2 , F_154 ( V_2 ) ,
1 ) ;
F_155 ( V_177 , V_2 , F_154 ( V_2 ) ) ;
}
return F_151 ( V_177 , V_2 , V_289 , V_298 | V_314 ) ;
}
static void V_274 ( struct V_315 * V_316 )
{
struct V_3 * V_4 =
F_246 ( V_316 , struct V_3 , V_185 . V_316 ) ;
struct V_1 * V_2 = V_4 -> V_275 ;
struct V_38 * V_39 ;
struct V_17 * V_18 ;
F_163 ( V_2 ) ;
if ( ! F_54 ( & V_4 -> V_67 ) ) {
V_18 = V_4 -> V_67 . V_45 ;
V_39 = F_55 ( V_18 ) ;
F_29 ( V_2 , V_39 , 1 ) ;
}
F_158 ( V_2 ) ;
}
void F_247 ( struct V_1 * V_2 )
{
T_3 V_278 ;
struct V_176 V_177 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_278 = F_190 () ;
if ( F_54 ( & V_4 -> V_67 ) )
return;
if ( F_88 ( & V_4 -> V_146 ) <= 0 &&
V_4 -> V_267 > 0 &&
V_4 -> V_116 > 0 &&
( V_278 - V_4 -> V_267 ) > V_4 -> V_261 ) {
if ( ! F_152 ( & V_177 , V_2 , 1 ) ) {
F_153 ( V_2 ,
F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_177 , V_2 ,
F_154 ( V_2 ) ) ;
F_151 ( & V_177 , V_2 , 1 , V_298 | V_314 ) ;
}
}
}
static int F_248 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 ,
int V_317 )
{
T_3 V_278 ;
int V_318 = V_317 & V_183 ;
int V_319 = V_317 & V_298 ;
int V_320 = V_317 & V_314 ;
struct V_38 * V_39 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_81 ( ! V_177 -> V_182 ) ;
if ( V_177 -> V_182 != V_4 -> V_65 ) {
F_51 ( V_177 -> V_277 , L_141 ,
L_142 ,
V_177 -> V_182 , V_4 -> V_65 ) ;
}
V_4 -> V_265 -= ( V_177 -> V_280 - V_177 -> V_300 ) ;
if ( F_88 ( & ( V_4 -> V_146 ) ) > 0 ) {
F_89 ( & ( V_4 -> V_146 ) ) ;
}
F_81 ( V_4 -> V_116 == 0 ) ;
if ( F_88 ( & ( V_4 -> V_146 ) ) > 0 ) {
if ( V_318 || V_319 ) {
unsigned V_66 ;
V_39 = V_4 -> V_91 ;
V_66 = V_39 -> V_65 ;
if ( V_320 )
V_39 -> V_151 |= V_288 ;
F_110 ( & ( V_4 -> V_271 ) , 1 ) ;
if ( V_318 ) {
V_4 -> V_321 = 1 ;
}
F_47 ( V_2 ) ;
while ( V_4 -> V_65 == V_66 ) {
if ( F_88 ( & V_4 -> V_271 ) ) {
F_221 ( V_2 ) ;
} else {
F_45 ( V_2 ) ;
if ( V_4 -> V_65 == V_66 ) {
F_110 ( & ( V_4 -> V_271 ) ,
1 ) ;
}
F_47 ( V_2 ) ;
}
}
F_81 ( V_4 -> V_65 == V_66 ) ;
if ( V_319
&& F_53 ( V_2 , V_66 )
&& V_320 ) {
F_29 ( V_2 , V_39 , 1 ) ;
}
return 0 ;
}
F_47 ( V_2 ) ;
return 0 ;
}
V_278 = F_190 () ;
if ( ( V_278 - V_4 -> V_267 ) > V_4 -> V_261 ) {
V_319 = 1 ;
V_4 -> V_322 = 1 ;
}
if ( ! ( V_4 -> V_272 > 0 ) && ! ( F_88 ( & ( V_4 -> V_271 ) ) )
&& ! V_318 && ! V_319 && ( V_4 -> V_116 < V_4 -> V_241 )
&& V_4 -> V_265 < V_4 -> V_241
&& V_4 -> V_47 > ( V_4 -> V_148 * 3 ) ) {
V_4 -> V_266 ++ ;
F_47 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_119 > F_112 ( V_2 ) ) {
F_51 ( V_2 , L_156 ,
L_157 ,
V_4 -> V_119 ) ;
}
return 1 ;
}
int F_249 ( struct V_176 * V_177 ,
struct V_1 * V_2 , T_1 V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_28 * V_29 = NULL ;
int V_323 = 0 ;
F_81 ( ! V_177 -> V_182 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_5 , V_52 ) ;
if ( V_46 && V_46 -> V_9 ) {
V_9 = V_46 -> V_9 ;
F_71 ( V_9 ) ;
}
if ( V_9 && F_250 ( V_9 ) ) {
F_72 ( V_9 ) ;
F_34 ( V_9 ) ;
F_3 ( V_9 ) ;
V_323 = F_243 ( V_2 , V_52 , V_323 ) ;
} else {
V_29 = V_4 -> V_91 -> V_42 ;
if ( ! V_29 ) {
F_51 ( V_2 , L_158 ,
L_159 ) ;
}
F_18 ( V_2 , V_52 , V_29 ) ;
if ( V_9 ) {
F_34 ( V_9 ) ;
F_3 ( V_9 ) ;
}
V_323 = F_243 ( V_2 , V_52 , V_323 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_58 ,
V_52 ) ;
while ( V_46 ) {
if ( V_2 == V_46 -> V_2 && V_52 == V_46 -> V_52 ) {
F_19 ( V_174 , & V_46 -> V_128 ) ;
if ( V_46 -> V_9 ) {
if ( ! V_323 ) {
F_239 ( V_46 ->
V_9 ) ;
F_4 ( V_46 -> V_9 ) ;
F_5 ( V_46 ->
V_9 ) ;
V_323 = 1 ;
F_59 ( V_46 -> V_9 ) ;
if ( F_88
( & ( V_46 -> V_9 -> V_154 ) ) < 0 ) {
F_27 ( V_2 ,
L_160 ,
L_161 ) ;
}
}
if ( V_46 -> V_124 ) {
F_89 ( &
( V_46 -> V_124 ->
V_149 ) ) ;
}
V_46 -> V_9 = NULL ;
}
}
V_46 = V_46 -> V_53 ;
}
}
if ( V_9 )
F_56 ( V_9 ) ;
return 0 ;
}
void F_251 ( struct V_94 * V_94 )
{
struct V_3 * V_4 = F_2 ( V_94 -> V_95 ) ;
F_252 ( V_94 ) -> V_324 = V_4 -> V_91 ;
F_252 ( V_94 ) -> V_325 = V_4 -> V_65 ;
}
static int F_253 ( struct V_94 * V_94 , unsigned long V_12 ,
struct V_38 * V_39 )
{
struct V_176 V_177 ;
struct V_1 * V_2 = V_94 -> V_95 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_82 = 0 ;
if ( V_12 == V_4 -> V_65 ) {
V_39 = V_4 -> V_91 ;
F_230 ( V_2 , V_12 ) ;
if ( V_4 -> V_65 != V_12 ) {
goto V_326;
}
V_82 = F_235 ( & V_177 , V_2 , 1 ) ;
if ( V_82 )
return V_82 ;
if ( V_4 -> V_65 != V_12 ) {
F_153 ( V_2 , F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_177 , V_2 , F_154 ( V_2 ) ) ;
V_82 = F_237 ( & V_177 , V_2 , 1 ) ;
goto V_326;
}
V_82 = F_245 ( & V_177 , V_2 , 1 ) ;
if ( ! V_82 )
V_82 = 1 ;
} else {
V_326:
if ( F_53 ( V_94 -> V_95 , V_12 ) ) {
if ( F_88 ( & V_39 -> V_107 ) > 1 )
V_82 = 1 ;
F_29 ( V_2 , V_39 , 1 ) ;
if ( V_4 -> V_96 )
V_82 = V_4 -> V_96 ;
}
}
return V_82 ;
}
int F_254 ( struct V_94 * V_94 )
{
unsigned int V_12 = F_252 ( V_94 ) -> V_325 ;
struct V_38 * V_39 = F_252 ( V_94 ) -> V_324 ;
if ( ! V_12 || ! V_39 ) {
F_251 ( V_94 ) ;
V_12 = F_252 ( V_94 ) -> V_325 ;
}
return F_253 ( V_94 , V_12 , V_39 ) ;
}
void F_255 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_40 ( V_2 , V_4 . V_327 ) ;
if ( ! V_9 ) {
return;
}
if ( F_256 ( V_9 ) &&
F_136 ( V_9 ) ) {
struct V_7 * V_46 ;
F_163 ( V_2 ) ;
V_46 = F_37 ( V_2 ,
V_4 -> V_58 ,
V_9 -> V_74 ) ;
if ( V_46 && F_137 ( V_46 ) ) {
F_143 ( V_9 ) ;
F_119 ( V_9 ) ;
}
F_158 ( V_2 ) ;
}
F_35 ( V_9 ) ;
}
int F_153 ( struct V_1 * V_2 ,
struct V_8 * V_9 , int V_282 )
{
F_40 ( V_2 , V_4 . V_328 ) ;
if ( ! F_96 ( V_9 ) ) {
if ( ! V_282 )
return 0 ;
F_138 ( V_9 ) ;
}
F_257 ( V_9 ) ;
if ( F_258 ( V_9 ) && F_136 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_142 ( V_9 ) ;
}
F_68 ( V_9 ) ;
return 1 ;
}
static int F_151 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_289 ,
int V_317 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 , * V_20 , * V_329 ;
struct V_7 * V_330 = NULL ;
struct V_188 * V_189 ;
struct V_190 * V_191 ;
struct V_8 * V_195 ;
struct V_8 * V_192 ;
int V_331 = 0 ;
int V_332 ;
int V_25 ;
int V_318 ;
int V_320 ;
struct V_38 * V_39 , * V_333 ;
struct V_17 * V_18 , * V_334 ;
unsigned long V_335 ;
unsigned int V_336 ;
int V_206 ;
int V_109 ;
F_81 ( V_177 -> V_279 > 1 ) ;
F_81 ( ! V_177 -> V_182 ) ;
if ( V_177 -> V_182 == ~ 0U )
V_317 |= V_183 | V_298 | V_314 ;
V_318 = V_317 & V_183 ;
V_320 = V_317 & V_314 ;
V_284 -> V_302 = V_177 -> V_304 ;
F_32 ( V_2 , L_162 ) ;
if ( V_4 -> V_116 == 0 ) {
F_153 ( V_2 , F_154 ( V_2 ) ,
1 ) ;
F_155 ( V_177 , V_2 , F_154 ( V_2 ) ) ;
}
F_45 ( V_2 ) ;
if ( V_4 -> V_321 ) {
V_317 |= V_183 ;
V_318 = 1 ;
}
if ( V_4 -> V_322 ) {
V_317 |= V_298 | V_314 ;
V_320 = 1 ;
}
if ( ! F_248 ( V_177 , V_2 , V_289 , V_317 ) ) {
F_241 ( V_2 ) ;
F_228 ( V_2 ) ;
F_106 ( V_2 ) ;
goto V_337;
}
if ( V_4 -> V_321 ) {
V_318 = 1 ;
}
if ( V_4 -> V_272 > 0 ) {
V_318 = 1 ;
}
#ifdef F_259
V_284 -> V_302 = V_177 ;
V_177 -> V_279 ++ ;
F_260 ( V_177 ) ;
V_177 -> V_279 -- ;
V_284 -> V_302 = V_177 -> V_304 ;
#endif
V_192 =
F_180 ( V_2 ,
F_111 ( V_2 ) +
V_4 -> V_119 ) ;
F_66 ( V_192 ) ;
V_189 = (struct V_188 * ) ( V_192 ) -> V_134 ;
memset ( V_192 -> V_134 , 0 , V_192 -> V_211 ) ;
memcpy ( F_172 ( V_192 ) , V_196 , 8 ) ;
F_261 ( V_189 , V_4 -> V_65 ) ;
V_195 = F_180 ( V_2 , F_111 ( V_2 ) +
( ( V_4 -> V_119 + V_4 -> V_116 +
1 ) % F_112 ( V_2 ) ) ) ;
V_191 = (struct V_190 * ) V_195 -> V_134 ;
memset ( V_195 -> V_134 , 0 , V_195 -> V_211 ) ;
F_262 ( V_191 , V_4 -> V_65 ) ;
F_66 ( V_195 ) ;
V_39 = V_4 -> V_91 ;
F_46 ( & V_39 -> V_118 , V_2 ) ;
V_336 = V_39 -> V_65 ;
F_110 ( & V_39 -> V_106 , 0 ) ;
V_39 -> V_65 = V_4 -> V_65 ;
V_39 -> V_338 = V_4 -> V_267 ;
V_39 -> V_120 = V_195 ;
V_39 -> V_119 = V_4 -> V_119 ;
V_39 -> V_116 = V_4 -> V_116 ;
F_110 ( & V_39 -> V_149 , V_4 -> V_116 ) ;
F_110 ( & V_39 -> V_107 , V_4 -> V_116 + 2 ) ;
V_39 -> V_127 = NULL ;
V_206 = F_179 ( V_2 -> V_15 ) ;
for ( V_25 = 0 , V_46 = V_4 -> V_269 ; V_46 ; V_46 = V_46 -> V_20 , V_25 ++ ) {
if ( F_64 ( V_46 -> V_9 ) ) {
V_329 = F_31 ( V_2 ) ;
if ( ! V_329 ) {
F_51 ( V_2 , L_163 ,
L_164 ) ;
}
if ( V_25 == 0 ) {
V_39 -> V_127 = V_329 ;
}
V_329 -> V_45 = V_330 ;
V_329 -> V_20 = NULL ;
if ( V_330 ) {
V_330 -> V_20 = V_329 ;
}
V_330 = V_329 ;
if ( F_184
( V_2 , V_46 -> V_9 -> V_74 ) ) {
F_51 ( V_2 , L_165 ,
L_166
L_167 ,
V_46 -> V_9 -> V_74 ) ;
}
V_329 -> V_52 = V_46 -> V_9 -> V_74 ;
V_329 -> V_128 = 0 ;
V_329 -> V_2 = V_2 ;
V_329 -> V_9 = V_46 -> V_9 ;
V_329 -> V_124 = V_39 ;
F_44 ( V_4 -> V_58 , V_329 ) ;
if ( V_25 < V_206 ) {
V_189 -> V_127 [ V_25 ] =
F_129 ( V_46 -> V_9 -> V_74 ) ;
} else {
V_191 -> V_127 [ V_25 - V_206 ] =
F_129 ( V_46 -> V_9 -> V_74 ) ;
}
} else {
V_25 -- ;
}
}
F_263 ( V_189 , V_4 -> V_116 ) ;
F_264 ( V_189 , V_4 -> V_135 ) ;
F_261 ( V_189 , V_4 -> V_65 ) ;
F_265 ( V_191 , V_4 -> V_116 ) ;
F_81 ( V_4 -> V_116 == 0 ) ;
F_119 ( V_192 ) ;
V_331 = V_4 -> V_119 ;
V_46 = V_4 -> V_269 ;
V_335 = 1 ;
while ( V_46 ) {
F_72 ( V_46 -> V_9 ) ;
if ( F_64 ( V_46 -> V_9 ) ) {
struct V_8 * V_158 ;
char * V_339 ;
struct V_68 * V_68 ;
V_158 =
F_180 ( V_2 ,
F_111 ( V_2 ) +
( ( V_331 +
V_335 ) %
F_112 ( V_2 ) ) ) ;
F_66 ( V_158 ) ;
V_68 = V_46 -> V_9 -> V_69 ;
V_339 = F_266 ( V_68 ) ;
memcpy ( V_158 -> V_134 ,
V_339 + F_267 ( V_46 -> V_9 -> V_134 ) ,
V_46 -> V_9 -> V_211 ) ;
F_268 ( V_68 ) ;
F_119 ( V_158 ) ;
V_335 ++ ;
F_269 ( V_46 -> V_9 ) ;
F_244 ( V_46 -> V_9 ) ;
} else {
F_27 ( V_2 , L_168 ,
L_169
L_170 ) ;
F_148 ( V_46 -> V_9 ) ;
}
V_20 = V_46 -> V_20 ;
F_33 ( V_2 , V_46 ) ;
V_46 = V_20 ;
F_270 ( V_2 ) ;
}
V_4 -> V_91 = F_191 ( V_2 ) ;
F_91 ( & V_39 -> V_105 , & V_4 -> V_67 ) ;
F_91 ( & V_39 -> V_137 , & V_4 -> V_137 ) ;
V_4 -> V_138 ++ ;
V_332 = V_4 -> V_119 ;
V_4 -> V_119 =
( V_4 -> V_119 + V_4 -> V_116 +
2 ) % F_112 ( V_2 ) ;
F_110 ( & ( V_4 -> V_146 ) , 0 ) ;
V_4 -> V_266 = 0 ;
V_4 -> V_268 = NULL ;
V_4 -> V_269 = NULL ;
V_4 -> V_116 = 0 ;
V_4 -> V_267 = 0 ;
if ( ++ V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_91 -> V_65 = V_4 -> V_65 ;
V_4 -> V_272 = 0 ;
V_4 -> V_265 = 0 ;
V_4 -> V_321 = 0 ;
V_4 -> V_322 = 0 ;
F_1 ( V_2 ) ;
F_271 () ;
if ( ! F_54 ( & V_39 -> V_92 ) ) {
V_109 = F_107 ( V_2 ) ;
F_94 ( & V_4 -> V_89 ,
V_4 , V_39 , & V_39 -> V_92 ) ;
F_109 ( V_2 , V_109 ) ;
}
F_81 ( ! F_54 ( & V_39 -> V_92 ) ) ;
F_48 ( & V_39 -> V_118 ) ;
if ( V_318 ) {
F_29 ( V_2 , V_39 , 1 ) ;
F_133 ( V_2 , V_39 , 1 ) ;
} else if ( ! ( V_39 -> V_151 & V_288 ) )
F_272 ( V_187 , & V_4 -> V_185 , V_111 / 10 ) ;
V_101:
F_273 (entry, safe, &journal->j_journal_list) {
V_333 = F_55 ( V_18 ) ;
if ( V_4 -> V_119 <= V_333 -> V_119 ) {
if ( ( V_4 -> V_119 + V_4 -> V_148 + 1 ) >=
V_333 -> V_119 ) {
F_145 ( V_2 , V_333 ) ;
goto V_101;
} else if ( ( V_4 -> V_119 +
V_4 -> V_148 + 1 ) <
F_112 ( V_2 ) ) {
break;
}
} else if ( ( V_4 -> V_119 +
V_4 -> V_148 + 1 ) >
F_112 ( V_2 ) ) {
if ( ( ( V_4 -> V_119 + V_4 -> V_148 + 1 ) %
F_112 ( V_2 ) ) >=
V_333 -> V_119 ) {
F_145 ( V_2 , V_333 ) ;
goto V_101;
} else {
break;
}
}
}
V_4 -> V_91 -> V_42 =
F_28 ( V_2 , V_4 -> V_91 ) ;
if ( ! ( V_4 -> V_91 -> V_42 ) ) {
F_51 ( V_2 , L_171 ,
L_172 ) ;
}
F_110 ( & ( V_4 -> V_271 ) , 0 ) ;
F_47 ( V_2 ) ;
F_217 ( V_283 , & V_4 -> V_151 ) ;
F_218 ( & ( V_4 -> V_270 ) ) ;
if ( ! V_318 && V_320 &&
F_53 ( V_2 , V_336 ) ) {
F_29 ( V_2 , V_39 , 1 ) ;
}
V_337:
F_32 ( V_2 , L_173 ) ;
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_177 -> V_277 = V_2 ;
return V_4 -> V_96 ;
}
void F_274 ( struct V_1 * V_2 , int V_340 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_41 ( V_341 , & V_4 -> V_151 ) )
return;
if ( ! V_4 -> V_96 )
V_4 -> V_96 = V_340 ;
V_2 -> V_180 |= V_181 ;
F_19 ( V_341 , & V_4 -> V_151 ) ;
#ifdef F_116
F_275 () ;
#endif
}
