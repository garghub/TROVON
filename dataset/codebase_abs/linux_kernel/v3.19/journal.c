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
if ( V_29 -> V_35 )
return NULL ;
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
if ( V_81 ) {
F_82 ( V_81 ) ;
F_80 ( V_79 ) ;
F_83 ( V_81 ) ;
} else {
F_80 ( V_79 ) ;
}
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
if ( F_88 ( & V_39 -> V_107 ) <= 0 ) {
if ( V_112 ) {
F_110 ( & V_39 -> V_106 , 1 ) ;
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
F_89 ( & V_39 -> V_107 ) ;
}
F_81 ( F_88 ( & V_39 -> V_107 ) != 1 ) ;
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
F_89 ( & V_39 -> V_107 ) ;
if ( V_112 ) {
F_110 ( & V_39 -> V_106 , 1 ) ;
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
if ( F_88 ( & V_39 -> V_149 ) <= 0 &&
F_88 ( & V_39 -> V_107 ) <= 0 ) {
goto V_150;
}
F_29 ( V_64 , V_39 , 1 ) ;
if ( ! ( V_39 -> V_151 & V_152 )
&& ! F_118 ( V_4 ) )
F_43 () ;
if ( F_88 ( & V_39 -> V_149 ) <= 0 &&
F_88 ( & V_39 -> V_107 ) <= 0 ) {
goto V_150;
}
if ( F_88 ( & V_4 -> V_146 ) != 0 ) {
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
if ( F_88 ( & V_143 -> V_154 ) < 0 ) {
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
F_110 ( & V_39 -> V_149 , 0 ) ;
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
F_89 ( & V_173 -> V_124 -> V_149 ) ;
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
F_151 ( V_177 , V_183 ) ;
if ( ! F_152 ( & V_178 , V_2 ) ) {
F_153 ( V_2 ,
F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_178 , F_154 ( V_2 ) ) ;
F_151 ( & V_178 , V_183 ) ;
V_179 = 1 ;
}
}
if ( ! error && F_118 ( V_4 ) ) {
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
if ( ! F_156 ( & V_178 , V_2 ) ) {
F_153 ( V_2 ,
F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_178 , F_154 ( V_2 ) ) ;
F_151 ( & V_178 , V_183 ) ;
}
}
F_157 ( V_2 ) ;
F_158 ( & F_159 ( V_2 ) -> V_184 ) ;
F_158 ( & F_2 ( V_2 ) -> V_185 ) ;
F_147 ( V_2 ) ;
F_160 ( V_2 ) ;
return 0 ;
}
int F_161 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
return F_150 ( V_177 , V_2 , 0 ) ;
}
int F_162 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
return F_150 ( V_177 , V_2 , 1 ) ;
}
static int F_163 ( struct V_1 * V_2 ,
struct V_186 * V_187 ,
struct V_188 * V_189 )
{
if ( F_164 ( V_189 ) != F_165 ( V_187 ) ||
F_166 ( V_189 ) != F_167 ( V_187 ) ||
F_166 ( V_189 ) > F_2 ( V_2 ) -> V_148 ||
F_166 ( V_189 ) <= 0 ) {
return 1 ;
}
return 0 ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_8 * V_190 ,
unsigned int * V_191 ,
unsigned long * V_192 )
{
struct V_186 * V_187 ;
struct V_188 * V_189 ;
struct V_8 * V_193 ;
unsigned long V_129 ;
if ( ! V_190 )
return 0 ;
V_187 = (struct V_186 * ) V_190 -> V_134 ;
if ( F_167 ( V_187 ) > 0
&& ! memcmp ( F_169 ( V_190 ) , V_194 , 8 ) ) {
if ( V_191 && * V_191
&& F_165 ( V_187 ) > * V_191 ) {
F_170 ( V_2 , V_195 ,
L_44
L_45
L_46 ,
F_165 ( V_187 ) ,
* V_191 ) ;
return 0 ;
}
if ( V_192
&& * V_192 > F_171 ( V_187 ) ) {
F_170 ( V_2 , V_195 ,
L_47
L_48
L_49 ,
F_171 ( V_187 ) ,
* V_192 ) ;
return - 1 ;
}
if ( F_167 ( V_187 ) > F_2 ( V_2 ) -> V_148 ) {
F_27 ( V_2 , L_50 ,
L_51
L_52 ,
F_167 ( V_187 ) ) ;
return - 1 ;
}
V_129 = V_190 -> V_74 - F_111 ( V_2 ) ;
V_193 =
F_172 ( V_2 ,
F_111 ( V_2 ) +
( ( V_129 + F_167 ( V_187 ) +
1 ) % F_112 ( V_2 ) ) ) ;
if ( ! V_193 )
return 0 ;
V_189 = (struct V_188 * ) V_193 -> V_134 ;
if ( F_163 ( V_2 , V_187 , V_189 ) ) {
F_170 ( V_2 , V_195 ,
L_53
L_54 ,
V_193 -> V_74 -
F_111 ( V_2 ) ,
F_164 ( V_189 ) ,
F_166 ( V_189 ) ) ;
F_148 ( V_193 ) ;
if ( V_191 ) {
* V_191 =
F_165 ( V_187 ) ;
F_170 ( V_2 , V_195 ,
L_55
L_56
L_57 ,
F_165 ( V_187 ) ) ;
}
return - 1 ;
}
F_148 ( V_193 ) ;
F_170 ( V_2 , V_195 ,
L_58
L_59 ,
V_190 -> V_74 -
F_111 ( V_2 ) ,
F_167 ( V_187 ) ,
F_165 ( V_187 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static void F_173 ( struct V_8 * * V_196 , int V_197 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_197 ; V_25 ++ ) {
F_148 ( V_196 [ V_25 ] ) ;
}
}
static int F_174 ( struct V_1 * V_2 ,
unsigned long V_198 ,
unsigned long V_199 ,
unsigned int V_200 ,
unsigned long V_192 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 ;
struct V_188 * V_189 ;
unsigned int V_66 = 0 ;
struct V_8 * V_193 ;
struct V_8 * V_190 ;
struct V_8 * * V_201 = NULL ;
struct V_8 * * V_202 = NULL ;
unsigned int V_203 ;
int V_25 ;
int V_204 ;
V_190 = F_172 ( V_2 , V_198 ) ;
if ( ! V_190 )
return 1 ;
V_187 = (struct V_186 * ) V_190 -> V_134 ;
V_203 = V_190 -> V_74 - F_111 ( V_2 ) ;
F_170 ( V_2 , V_195 , L_60
L_61 ,
V_190 -> V_74 - F_111 ( V_2 ) ,
F_167 ( V_187 ) , F_171 ( V_187 ) ) ;
if ( F_165 ( V_187 ) < V_200 ) {
F_170 ( V_2 , V_195 , L_62
L_63 ,
V_198 -
F_111 ( V_2 ) ) ;
F_148 ( V_190 ) ;
return 1 ;
}
if ( F_171 ( V_187 ) != V_192 ) {
F_170 ( V_2 , V_195 , L_64
L_65
L_49 , F_171 ( V_187 ) ,
V_192 ) ;
F_148 ( V_190 ) ;
return 1 ;
}
V_193 = F_172 ( V_2 , F_111 ( V_2 ) +
( ( V_203 + F_167 ( V_187 ) + 1 ) %
F_112 ( V_2 ) ) ) ;
if ( ! V_193 ) {
F_148 ( V_190 ) ;
return 1 ;
}
V_189 = (struct V_188 * ) V_193 -> V_134 ;
if ( F_163 ( V_2 , V_187 , V_189 ) ) {
F_170 ( V_2 , V_195 ,
L_66
L_67 ,
V_193 -> V_74 -
F_111 ( V_2 ) ,
F_164 ( V_189 ) ,
F_166 ( V_189 ) ) ;
F_148 ( V_193 ) ;
F_148 ( V_190 ) ;
return 1 ;
}
if ( F_175 ( V_2 -> V_205 ) ) {
F_27 ( V_2 , L_68 ,
L_69 ) ;
F_148 ( V_193 ) ;
F_148 ( V_190 ) ;
return - V_206 ;
}
V_66 = F_165 ( V_187 ) ;
V_201 = F_7 ( F_167 ( V_187 ) *
sizeof( struct V_8 * ) , V_13 ) ;
V_202 = F_7 ( F_167 ( V_187 ) *
sizeof( struct V_8 * ) , V_13 ) ;
if ( ! V_201 || ! V_202 ) {
F_148 ( V_193 ) ;
F_148 ( V_190 ) ;
F_9 ( V_201 ) ;
F_9 ( V_202 ) ;
F_27 ( V_2 , L_70 ,
L_71 ) ;
return - 1 ;
}
V_204 = F_176 ( V_2 -> V_15 ) ;
for ( V_25 = 0 ; V_25 < F_167 ( V_187 ) ; V_25 ++ ) {
V_201 [ V_25 ] =
F_177 ( V_2 ,
F_111 ( V_2 ) +
( V_203 + 1 +
V_25 ) % F_112 ( V_2 ) ) ;
if ( V_25 < V_204 ) {
V_202 [ V_25 ] =
F_178 ( V_2 ,
F_179 ( V_187 -> V_127 [ V_25 ] ) ) ;
} else {
V_202 [ V_25 ] =
F_178 ( V_2 ,
F_179 ( V_189 ->
V_127 [ V_25 - V_204 ] ) ) ;
}
if ( V_202 [ V_25 ] -> V_74 > F_180 ( V_2 ) ) {
F_27 ( V_2 , L_72 ,
L_73
L_74
L_75 ) ;
goto V_207;
}
if ( F_181
( V_2 , V_202 [ V_25 ] -> V_74 ) ) {
F_27 ( V_2 , L_76 ,
L_73
L_77 ) ;
V_207:
F_173 ( V_201 , V_25 ) ;
F_173 ( V_202 , V_25 ) ;
F_148 ( V_193 ) ;
F_148 ( V_190 ) ;
F_9 ( V_201 ) ;
F_9 ( V_202 ) ;
return - 1 ;
}
}
F_104 ( V_208 , F_167 ( V_187 ) , V_201 ) ;
for ( V_25 = 0 ; V_25 < F_167 ( V_187 ) ; V_25 ++ ) {
F_99 ( V_201 [ V_25 ] ) ;
if ( ! F_74 ( V_201 [ V_25 ] ) ) {
F_27 ( V_2 , L_78 ,
L_73
L_12 ) ;
F_173 ( V_201 + V_25 ,
F_167 ( V_187 ) - V_25 ) ;
F_173 ( V_202 , F_167 ( V_187 ) ) ;
F_148 ( V_193 ) ;
F_148 ( V_190 ) ;
F_9 ( V_201 ) ;
F_9 ( V_202 ) ;
return - 1 ;
}
memcpy ( V_202 [ V_25 ] -> V_134 , V_201 [ V_25 ] -> V_134 ,
V_202 [ V_25 ] -> V_209 ) ;
F_66 ( V_202 [ V_25 ] ) ;
F_148 ( V_201 [ V_25 ] ) ;
}
for ( V_25 = 0 ; V_25 < F_167 ( V_187 ) ; V_25 ++ ) {
F_130 ( V_202 [ V_25 ] ) ;
F_182 ( V_202 [ V_25 ] , V_77 ) ;
}
for ( V_25 = 0 ; V_25 < F_167 ( V_187 ) ; V_25 ++ ) {
F_99 ( V_202 [ V_25 ] ) ;
if ( ! F_74 ( V_202 [ V_25 ] ) ) {
F_27 ( V_2 , L_79 ,
L_80
L_12 ) ;
F_173 ( V_202 + V_25 ,
F_167 ( V_187 ) - V_25 ) ;
F_148 ( V_193 ) ;
F_148 ( V_190 ) ;
F_9 ( V_201 ) ;
F_9 ( V_202 ) ;
return - 1 ;
}
F_148 ( V_202 [ V_25 ] ) ;
}
V_198 =
F_111 ( V_2 ) +
( ( V_203 + F_167 ( V_187 ) +
2 ) % F_112 ( V_2 ) ) ;
F_170 ( V_2 , V_195 ,
L_81 L_82 ,
V_198 - F_111 ( V_2 ) ) ;
V_4 -> V_119 = V_198 - F_111 ( V_2 ) ;
V_4 -> V_131 = V_66 ;
V_4 -> V_65 = V_66 + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
F_148 ( V_193 ) ;
F_148 ( V_190 ) ;
F_9 ( V_201 ) ;
F_9 ( V_202 ) ;
return 0 ;
}
static struct V_8 * F_183 ( struct V_210 * V_211 ,
T_1 V_27 , int V_212 ,
T_1 V_213 )
{
struct V_8 * V_214 [ V_215 ] ;
unsigned int V_216 = V_215 ;
struct V_8 * V_9 ;
int V_25 , V_40 ;
V_9 = F_184 ( V_211 , V_27 , V_212 ) ;
if ( F_74 ( V_9 ) )
return ( V_9 ) ;
if ( V_27 + V_215 > V_213 ) {
V_216 = V_213 - V_27 ;
}
V_214 [ 0 ] = V_9 ;
V_40 = 1 ;
for ( V_25 = 1 ; V_25 < V_216 ; V_25 ++ ) {
V_9 = F_184 ( V_211 , V_27 + V_25 , V_212 ) ;
if ( F_74 ( V_9 ) ) {
F_148 ( V_9 ) ;
break;
} else
V_214 [ V_40 ++ ] = V_9 ;
}
F_104 ( V_208 , V_40 , V_214 ) ;
for ( V_25 = 1 ; V_25 < V_40 ; V_25 ++ )
F_148 ( V_214 [ V_25 ] ) ;
V_9 = V_214 [ 0 ] ;
F_99 ( V_9 ) ;
if ( F_74 ( V_9 ) )
return V_9 ;
F_148 ( V_9 ) ;
return NULL ;
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_186 * V_187 ;
unsigned int V_200 = 0 ;
unsigned int V_191 = 0 ;
T_3 V_217 ;
unsigned long V_199 = 0 ;
unsigned long V_198 = 0 ;
unsigned long V_192 = 9 ;
struct V_8 * V_190 ;
struct V_130 * V_85 ;
int V_218 = 0 ;
int V_219 = 0 ;
int V_220 = 1 ;
int V_82 ;
char V_72 [ V_73 ] ;
V_198 = F_111 ( V_2 ) ;
F_186 ( V_2 , L_83 ,
F_65 ( V_4 -> V_221 , V_72 ) ) ;
V_217 = F_187 () ;
V_4 -> V_132 = F_172 ( V_2 ,
F_111 ( V_2 )
+ F_112 ( V_2 ) ) ;
if ( ! V_4 -> V_132 ) {
return 1 ;
}
V_85 = (struct V_130 * ) ( V_4 -> V_132 -> V_134 ) ;
if ( F_179 ( V_85 -> V_133 ) <
F_112 ( V_2 )
&& F_179 ( V_85 -> V_131 ) > 0 ) {
V_199 =
F_111 ( V_2 ) +
F_179 ( V_85 -> V_133 ) ;
V_200 = F_179 ( V_85 -> V_131 ) + 1 ;
V_192 = F_179 ( V_85 -> V_135 ) ;
F_170 ( V_2 , V_195 ,
L_84
L_85
L_86 , F_179 ( V_85 -> V_133 ) ,
F_179 ( V_85 -> V_131 ) ) ;
V_218 = 1 ;
V_190 =
F_172 ( V_2 ,
F_111 ( V_2 ) +
F_179 ( V_85 -> V_133 ) ) ;
V_82 = F_168 ( V_2 , V_190 , NULL , NULL ) ;
if ( ! V_82 ) {
V_220 = 0 ;
}
F_148 ( V_190 ) ;
goto V_222;
}
while ( V_220
&& V_198 <
( F_111 ( V_2 ) +
F_112 ( V_2 ) ) ) {
V_190 =
F_183 ( V_4 -> V_221 , V_198 ,
V_2 -> V_15 ,
F_111 ( V_2 ) +
F_112 ( V_2 ) ) ;
V_82 =
F_168 ( V_2 , V_190 ,
& V_191 ,
& V_192 ) ;
if ( V_82 == 1 ) {
V_187 = (struct V_186 * ) V_190 -> V_134 ;
if ( V_199 == 0 ) {
V_200 = F_165 ( V_187 ) ;
V_199 = V_190 -> V_74 ;
V_192 = F_171 ( V_187 ) ;
F_170 ( V_2 , V_195 ,
L_87
L_88 ,
V_199 -
F_111
( V_2 ) , V_200 ) ;
} else if ( V_200 > F_165 ( V_187 ) ) {
V_200 = F_165 ( V_187 ) ;
V_199 = V_190 -> V_74 ;
F_170 ( V_2 , V_195 ,
L_89
L_90 ,
V_199 -
F_111
( V_2 ) , V_200 ) ;
}
if ( V_192 < F_171 ( V_187 ) ) {
V_192 = F_171 ( V_187 ) ;
F_170 ( V_2 , V_195 ,
L_91
L_92 ,
F_171 ( V_187 ) ) ;
}
V_198 += F_167 ( V_187 ) + 2 ;
} else {
V_198 ++ ;
}
F_148 ( V_190 ) ;
}
V_222:
V_198 = V_199 ;
if ( V_200 ) {
F_170 ( V_2 , V_195 ,
L_93
L_94 ,
V_198 - F_111 ( V_2 ) ,
V_200 ) ;
}
V_219 = 0 ;
while ( V_220 && V_200 > 0 ) {
V_82 =
F_174 ( V_2 , V_198 , V_199 ,
V_200 , V_192 ) ;
if ( V_82 < 0 ) {
return V_82 ;
} else if ( V_82 != 0 ) {
break;
}
V_198 =
F_111 ( V_2 ) + V_4 -> V_119 ;
V_219 ++ ;
if ( V_198 == V_199 )
break;
}
if ( V_200 == 0 ) {
F_170 ( V_2 , V_195 ,
L_95 L_96 ) ;
}
if ( V_218 && V_219 == 0 ) {
V_4 -> V_119 = F_179 ( V_85 -> V_133 ) ;
V_4 -> V_65 =
F_179 ( V_85 -> V_131 ) + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_131 =
F_179 ( V_85 -> V_131 ) ;
V_4 -> V_135 = F_179 ( V_85 -> V_135 ) + 1 ;
} else {
V_4 -> V_135 = V_192 + 1 ;
}
F_170 ( V_2 , V_195 , L_91
L_97 , V_4 -> V_135 ) ;
V_4 -> V_133 = V_4 -> V_119 ;
if ( V_219 > 0 ) {
F_186 ( V_2 ,
L_98 ,
V_219 , F_187 () - V_217 ) ;
}
F_160 ( V_2 ) ;
if ( ! F_175 ( V_2 -> V_205 ) &&
F_128 ( V_2 , V_4 -> V_119 ,
V_4 -> V_131 ) ) {
F_157 ( V_2 ) ;
return - 1 ;
}
F_157 ( V_2 ) ;
return 0 ;
}
static struct V_38 * F_188 ( struct V_1 * V_64 )
{
struct V_38 * V_39 ;
V_39 = F_8 ( sizeof( struct V_38 ) ,
V_13 | V_223 ) ;
F_10 ( & V_39 -> V_105 ) ;
F_10 ( & V_39 -> V_137 ) ;
F_10 ( & V_39 -> V_92 ) ;
F_10 ( & V_39 -> V_93 ) ;
F_189 ( & V_39 -> V_118 ) ;
F_2 ( V_64 ) -> V_155 ++ ;
F_49 ( V_39 ) ;
return V_39 ;
}
static void F_190 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) -> V_91 = F_188 ( V_2 ) ;
}
static void F_149 ( struct V_1 * V_224 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_221 != NULL ) {
F_191 ( V_4 -> V_221 , V_4 -> V_225 ) ;
V_4 -> V_221 = NULL ;
}
}
static int F_192 ( struct V_1 * V_224 ,
struct V_3 * V_4 ,
const char * V_226 )
{
int V_227 ;
T_4 V_228 ;
T_5 V_229 = V_230 | V_231 | V_232 ;
char V_72 [ V_73 ] ;
V_227 = 0 ;
V_4 -> V_221 = NULL ;
V_228 = F_193 ( V_224 ) ?
F_194 ( F_193 ( V_224 ) ) : V_224 -> V_233 ;
if ( F_175 ( V_224 -> V_205 ) )
V_229 = V_230 ;
if ( ( ! V_226 || ! V_226 [ 0 ] ) ) {
if ( V_228 == V_224 -> V_233 )
V_229 &= ~ V_232 ;
V_4 -> V_221 = F_195 ( V_228 , V_229 ,
V_4 ) ;
V_4 -> V_225 = V_229 ;
if ( F_196 ( V_4 -> V_221 ) ) {
V_227 = F_197 ( V_4 -> V_221 ) ;
V_4 -> V_221 = NULL ;
F_27 ( V_224 , L_99 ,
L_100 ,
F_198 ( V_228 , V_72 ) , V_227 ) ;
return V_227 ;
} else if ( V_228 != V_224 -> V_233 )
F_199 ( V_4 -> V_221 , V_224 -> V_15 ) ;
return 0 ;
}
V_4 -> V_225 = V_229 ;
V_4 -> V_221 = F_200 ( V_226 , V_229 , V_4 ) ;
if ( F_196 ( V_4 -> V_221 ) ) {
V_227 = F_197 ( V_4 -> V_221 ) ;
V_4 -> V_221 = NULL ;
F_27 ( V_224 ,
L_101 ,
V_226 , V_227 ) ;
return V_227 ;
}
F_199 ( V_4 -> V_221 , V_224 -> V_15 ) ;
F_186 ( V_224 ,
L_102 ,
F_65 ( V_4 -> V_221 , V_72 ) ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_148 ) {
int V_234 = 1 ;
if ( V_2 -> V_15 < V_235 )
V_234 = V_235 / V_2 -> V_15 ;
if ( V_4 -> V_148 > V_236 / V_234 ||
V_4 -> V_148 < V_237 / V_234 ||
F_112 ( V_2 ) / V_4 -> V_148 <
V_238 ) {
F_27 ( V_2 , L_103 ,
L_104
L_105 , V_4 -> V_148 ) ;
return 1 ;
}
if ( V_4 -> V_239 != ( V_4 -> V_148 ) *
V_240 / V_236 ) {
F_27 ( V_2 , L_106 ,
L_107
L_105 , V_4 -> V_239 ) ;
return 1 ;
}
} else {
if ( V_2 -> V_15 != V_235 ) {
F_27 ( V_2 , L_108 , L_109 ,
V_2 -> V_15 ) ;
return 1 ;
}
V_4 -> V_148 = V_236 ;
V_4 -> V_239 = V_240 ;
V_4 -> V_241 = V_242 ;
}
return 0 ;
}
int F_202 ( struct V_1 * V_2 , const char * V_243 ,
int V_244 , unsigned int V_245 )
{
int V_43 = F_112 ( V_2 ) * 2 ;
struct V_8 * V_246 ;
struct V_247 * V_248 ;
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
F_10 ( & V_4 -> V_249 ) ;
F_10 ( & V_4 -> V_137 ) ;
F_10 ( & V_4 -> V_67 ) ;
V_4 -> V_250 = 0 ;
if ( F_25 ( V_2 , V_4 -> V_42 ,
F_21 ( V_2 ) ) )
goto V_251;
F_17 ( V_2 ) ;
F_203 ( V_2 ) = ( V_244 ?
V_252
/ V_2 -> V_15 +
F_21 ( V_2 ) +
1 :
V_253 /
V_2 -> V_15 + 2 ) ;
if ( ! F_193 ( V_2 ) &&
( F_203 ( V_2 ) +
F_112 ( V_2 ) > V_2 -> V_15 * 8 ) ) {
F_27 ( V_2 , L_112 ,
L_113
L_114
L_115 ,
F_203 ( V_2 ) ,
F_112 ( V_2 ) ,
V_2 -> V_15 ) ;
goto V_251;
}
if ( F_192 ( V_2 , V_4 , V_243 ) != 0 ) {
F_27 ( V_2 , L_103 ,
L_116 ) ;
goto V_251;
}
V_248 = F_204 ( V_2 ) ;
V_246 = F_172 ( V_2 ,
F_111 ( V_2 ) +
F_112 ( V_2 ) ) ;
if ( ! V_246 ) {
F_27 ( V_2 , L_117 ,
L_118 ) ;
goto V_251;
}
V_85 = (struct V_130 * ) ( V_246 -> V_134 ) ;
if ( F_205 ( V_248 )
&& ( F_179 ( V_85 -> V_254 . V_255 ) !=
F_206 ( V_248 ) ) ) {
F_27 ( V_2 , L_119 ,
L_120
L_121 ,
V_85 -> V_254 . V_255 ,
F_65 ( V_4 -> V_221 , V_72 ) ,
F_206 ( V_248 ) ) ;
F_148 ( V_246 ) ;
goto V_251;
}
V_4 -> V_148 = F_179 ( V_85 -> V_254 . V_256 ) ;
V_4 -> V_239 = F_179 ( V_85 -> V_254 . V_257 ) ;
V_4 -> V_241 =
F_179 ( V_85 -> V_254 . V_258 ) ;
V_4 -> V_259 = V_260 ;
if ( F_201 ( V_2 , V_4 ) != 0 )
goto V_251;
V_4 -> V_261 = V_4 -> V_241 ;
if ( V_245 != 0 ) {
V_4 -> V_241 = V_245 ;
V_4 -> V_259 = V_245 ;
}
F_186 ( V_2 , L_122
L_123
L_124 ,
F_65 ( V_4 -> V_221 , V_72 ) ,
F_112 ( V_2 ) ,
F_111 ( V_2 ) ,
V_4 -> V_148 ,
V_4 -> V_239 ,
V_4 -> V_241 , V_4 -> V_259 ) ;
F_148 ( V_246 ) ;
V_4 -> V_41 = 0 ;
F_190 ( V_2 ) ;
memset ( V_4 -> V_58 , 0 ,
V_6 * sizeof( struct V_7 * ) ) ;
F_10 ( & V_4 -> V_262 ) ;
F_207 ( & V_4 -> V_89 ) ;
V_4 -> V_119 = 0 ;
V_4 -> V_116 = 0 ;
V_4 -> V_263 = 0 ;
F_110 ( & V_4 -> V_146 , 0 ) ;
F_110 ( & V_4 -> V_108 , 0 ) ;
V_4 -> V_264 = 0 ;
V_4 -> V_265 = 0 ;
V_4 -> V_266 = NULL ;
V_4 -> V_267 = NULL ;
F_208 ( & V_4 -> V_268 ) ;
F_189 ( & V_4 -> V_62 ) ;
F_189 ( & V_4 -> V_147 ) ;
V_4 -> V_65 = 10 ;
V_4 -> V_135 = 10 ;
V_4 -> V_151 = 0 ;
F_110 ( & V_4 -> V_269 , 0 ) ;
V_4 -> V_49 = F_30 ( V_43 ) ;
V_4 -> V_175 = V_4 -> V_49 ;
V_4 -> V_47 = V_4 -> V_49 ? V_43 : 0 ;
V_4 -> V_48 = 0 ;
V_4 -> V_270 = 0 ;
if ( V_4 -> V_47 == 0 ) {
F_27 ( V_2 , L_125 , L_126
L_127
L_128
L_129 ,
sizeof ( struct V_7 ) * V_43 ) ;
goto V_251;
}
F_1 ( V_2 ) ;
V_39 = V_4 -> V_91 ;
F_160 ( V_2 ) ;
V_39 -> V_42 = F_28 ( V_2 , V_39 ) ;
F_157 ( V_2 ) ;
if ( ! V_39 -> V_42 ) {
F_27 ( V_2 , L_130 ,
L_131 ) ;
goto V_251;
}
V_82 = F_185 ( V_2 ) ;
if ( V_82 < 0 ) {
F_27 ( V_2 , L_132 ,
L_133 ) ;
goto V_251;
}
F_209 ( & V_4 -> V_185 , V_271 ) ;
V_4 -> V_272 = V_2 ;
return 0 ;
V_251:
F_147 ( V_2 ) ;
return 1 ;
}
int F_210 ( struct V_176 * V_177 ,
int V_273 )
{
struct V_3 * V_4 = F_2 ( V_177 -> V_274 ) ;
T_3 V_275 = F_187 () ;
F_81 ( ! V_177 -> V_182 ) ;
if ( V_177 -> V_276 > 1 )
return 0 ;
if ( V_4 -> V_270 > 0 ||
( V_4 -> V_263 + V_273 ) >= V_4 -> V_239 ||
F_88 ( & V_4 -> V_269 ) ||
( V_275 - V_4 -> V_265 ) > V_4 -> V_259 ||
V_4 -> V_47 < ( V_4 -> V_148 * 3 ) ) {
return 1 ;
}
V_4 -> V_263 += V_273 ;
V_177 -> V_277 += V_273 ;
return 0 ;
}
void F_211 ( struct V_176 * V_177 )
{
struct V_3 * V_4 = F_2 ( V_177 -> V_274 ) ;
F_81 ( ! V_177 -> V_182 ) ;
V_4 -> V_270 = 1 ;
F_19 ( V_278 , & V_4 -> V_151 ) ;
return;
}
void F_212 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_213 ( V_278 , & V_4 -> V_151 ) ;
F_214 ( & V_4 -> V_268 ) ;
}
void F_215 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_216 ( V_4 -> V_268 ,
! F_41 ( V_278 , & V_4 -> V_151 ) ) ;
}
static void F_217 ( struct V_1 * V_64 )
{
T_6 V_279 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_19 ( V_280 , & V_4 -> V_151 ) ;
F_218 ( & V_279 , V_281 ) ;
F_219 ( & V_4 -> V_268 , & V_279 ) ;
F_220 ( V_282 ) ;
if ( F_41 ( V_280 , & V_4 -> V_151 ) ) {
int V_109 = F_107 ( V_64 ) ;
F_221 () ;
F_109 ( V_64 , V_109 ) ;
}
F_222 ( V_283 ) ;
F_223 ( & V_4 -> V_268 , & V_279 ) ;
}
static void F_224 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
if ( F_225 ( V_280 , & V_4 -> V_151 ) )
F_214 ( & V_4 -> V_268 ) ;
}
static void F_226 ( struct V_1 * V_2 , unsigned int V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_284 = V_4 -> V_264 ;
while ( 1 ) {
int V_109 ;
V_109 = F_107 ( V_2 ) ;
F_227 ( 1 ) ;
F_109 ( V_2 , V_109 ) ;
V_4 -> V_91 -> V_151 |= V_285 ;
while ( ( F_88 ( & V_4 -> V_146 ) > 0 ||
F_88 ( & V_4 -> V_269 ) ) &&
V_4 -> V_65 == V_66 ) {
F_217 ( V_2 ) ;
}
if ( V_4 -> V_65 != V_66 )
break;
if ( V_284 == V_4 -> V_264 )
break;
V_284 = V_4 -> V_264 ;
}
}
static int F_228 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_286 ,
int V_287 )
{
T_3 V_275 = F_187 () ;
unsigned int V_288 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_176 V_178 ;
int V_289 = 0 ;
int V_114 ;
int V_109 ;
F_32 ( V_2 , L_134 ) ;
F_81 ( V_286 > V_4 -> V_148 ) ;
F_40 ( V_2 , V_4 . V_290 ) ;
V_177 -> V_276 = 1 ;
V_177 -> V_274 = V_2 ;
V_291:
F_45 ( V_2 ) ;
if ( V_287 != V_292 && F_118 ( V_4 ) ) {
F_47 ( V_2 ) ;
V_114 = V_4 -> V_96 ;
goto V_293;
}
V_4 -> V_264 ++ ;
if ( F_41 ( V_278 , & V_4 -> V_151 ) ) {
F_47 ( V_2 ) ;
V_109 = F_107 ( V_2 ) ;
F_215 ( V_2 ) ;
F_109 ( V_2 , V_109 ) ;
F_40 ( V_2 , V_4 . V_294 ) ;
goto V_291;
}
V_275 = F_187 () ;
if ( ( ! V_287 && V_4 -> V_270 > 0 ) ||
( ! V_287
&& ( V_4 -> V_263 + V_286 + 2 ) >= V_4 -> V_239 )
|| ( ! V_287 && F_88 ( & V_4 -> V_146 ) > 0
&& V_4 -> V_265 > 0
&& ( V_275 - V_4 -> V_265 ) >
V_4 -> V_259 ) || ( ! V_287
&& F_88 ( & V_4 -> V_269 ) )
|| ( ! V_287 && V_4 -> V_47 < ( V_4 -> V_148 * 3 ) ) ) {
V_288 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
if ( ! V_287 && ( V_4 -> V_263 + V_286 + 2 ) >=
V_4 -> V_239 &&
( ( V_4 -> V_116 + V_286 + 2 ) * 100 ) <
( V_4 -> V_263 * 75 ) ) {
if ( F_88 ( & V_4 -> V_146 ) > 10 ) {
V_289 ++ ;
F_217 ( V_2 ) ;
goto V_291;
}
}
if ( F_88 ( & V_4 -> V_269 ) ) {
while ( V_4 -> V_65 == V_288 &&
F_88 ( & V_4 -> V_269 ) ) {
F_217 ( V_2 ) ;
}
goto V_291;
}
V_114 = F_152 ( & V_178 , V_2 ) ;
if ( V_114 )
goto V_293;
if ( V_288 != V_4 -> V_65 ) {
V_114 = F_151 ( & V_178 , 0 ) ;
} else {
V_114 = F_151 ( & V_178 , V_295 ) ;
}
if ( V_114 )
goto V_293;
F_40 ( V_2 , V_4 . V_296 ) ;
goto V_291;
}
if ( V_4 -> V_265 == 0 ) {
V_4 -> V_265 = F_187 () ;
}
F_85 ( & V_4 -> V_146 ) ;
V_4 -> V_263 += V_286 ;
V_177 -> V_297 = 0 ;
V_177 -> V_277 = V_286 ;
V_177 -> V_182 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
F_10 ( & V_177 -> V_298 ) ;
return 0 ;
V_293:
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_177 -> V_274 = V_2 ;
return V_114 ;
}
struct V_176 * F_229 ( struct
V_1
* V_64 ,
int V_286 )
{
int V_82 ;
struct V_176 * V_177 ;
if ( F_230 ( V_64 ) ) {
V_177 = V_281 -> V_299 ;
V_177 -> V_276 ++ ;
F_81 ( V_177 -> V_276 < 2 ) ;
return V_177 ;
}
V_177 = F_7 ( sizeof( struct V_176 ) , V_13 ) ;
if ( ! V_177 )
return NULL ;
V_82 = F_231 ( V_177 , V_64 , V_286 ) ;
if ( V_82 ) {
F_9 ( V_177 ) ;
return NULL ;
}
F_2 ( V_64 ) -> V_250 ++ ;
return V_177 ;
}
int F_232 ( struct V_176 * V_177 )
{
struct V_1 * V_64 = V_177 -> V_274 ;
int V_82 = 0 ;
if ( V_177 -> V_182 )
V_82 = F_233 ( V_177 ) ;
else
V_82 = - V_99 ;
if ( V_177 -> V_276 == 0 ) {
F_2 ( V_64 ) -> V_250 -- ;
F_9 ( V_177 ) ;
}
return V_82 ;
}
static int F_152 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_176 * V_300 = V_281 -> V_299 ;
V_177 -> V_301 = V_300 ;
F_81 ( V_300 && V_300 -> V_276 > 1 ) ;
return F_228 ( V_177 , V_2 , 1 , V_302 ) ;
}
int F_156 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_176 * V_300 = V_281 -> V_299 ;
V_177 -> V_301 = V_300 ;
F_81 ( V_300 && V_300 -> V_276 > 1 ) ;
return F_228 ( V_177 , V_2 , 1 , V_292 ) ;
}
int F_231 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_286 )
{
struct V_176 * V_300 = V_281 -> V_299 ;
int V_82 ;
V_177 -> V_301 = NULL ;
if ( V_300 ) {
if ( V_300 -> V_274 == V_2 ) {
F_81 ( ! V_300 -> V_276 ) ;
V_300 -> V_276 ++ ;
memcpy ( V_177 , V_300 , sizeof( * V_177 ) ) ;
if ( V_177 -> V_276 <= 1 )
F_27 ( V_2 , L_135 ,
L_136
L_137 ) ;
return 0 ;
} else {
F_27 ( V_2 , L_138 ,
L_139 ) ;
V_177 -> V_301 = V_281 -> V_299 ;
V_281 -> V_299 = V_177 ;
}
} else {
V_281 -> V_299 = V_177 ;
}
V_82 = F_228 ( V_177 , V_2 , V_286 , V_303 ) ;
F_81 ( V_281 -> V_299 != V_177 ) ;
if ( V_82 )
V_281 -> V_299 = V_177 -> V_301 ;
else
F_81 ( ! V_177 -> V_276 ) ;
return V_82 ;
}
int F_155 ( struct V_176 * V_177 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_177 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
int V_304 = 0 ;
int V_305 = 0 ;
F_81 ( ! V_177 -> V_182 ) ;
F_40 ( V_2 , V_4 . V_306 ) ;
if ( V_177 -> V_182 != V_4 -> V_65 ) {
F_51 ( V_177 -> V_274 , L_140 ,
L_141 ,
V_177 -> V_182 , V_4 -> V_65 ) ;
}
V_305 = F_234 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( F_64 ( V_9 ) ) {
F_40 ( V_2 , V_4 . V_307 ) ;
return 0 ;
}
if ( ! V_305 || F_97 ( V_9 ) ) {
F_27 ( V_2 , L_142 ,
L_143
L_144 ,
( unsigned long long ) V_9 -> V_74 ,
V_305 ? ' ' : '!' ,
F_102 ( V_9 ) ? ' ' : '!' ,
F_97 ( V_9 ) ? ' ' : '!' ,
F_136 ( V_9 ) ? ' ' : '!' ) ;
}
if ( F_88 ( & V_4 -> V_146 ) <= 0 ) {
F_27 ( V_2 , L_145 ,
L_146 ,
F_88 ( & V_4 -> V_146 ) ) ;
return 1 ;
}
if ( V_4 -> V_116 >= V_4 -> V_148 ) {
F_51 ( V_177 -> V_274 , L_147 ,
L_148 ,
V_4 -> V_116 ) ;
}
if ( F_136 ( V_9 ) ) {
V_304 = 1 ;
F_40 ( V_2 , V_4 . V_308 ) ;
F_235 ( V_9 ) ;
}
if ( V_4 -> V_116 > V_4 -> V_263 ) {
V_4 -> V_263 = V_4 -> V_116 + V_309 ;
}
F_236 ( V_9 ) ;
if ( ! V_46 ) {
V_46 = F_31 ( V_2 ) ;
if ( ! V_46 ) {
F_51 ( V_2 , L_149 , L_150 ) ;
}
if ( V_177 -> V_297 == V_177 -> V_277 ) {
V_177 -> V_277 += V_309 ;
V_4 -> V_263 += V_309 ;
}
V_177 -> V_297 ++ ;
V_4 -> V_116 ++ ;
V_46 -> V_9 = V_9 ;
V_46 -> V_52 = V_9 -> V_74 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_124 = NULL ;
F_44 ( V_4 -> V_5 , V_46 ) ;
if ( ! V_304 ) {
F_71 ( V_9 ) ;
}
}
V_46 -> V_20 = NULL ;
V_46 -> V_45 = V_4 -> V_266 ;
V_46 -> V_9 = V_9 ;
if ( V_4 -> V_266 ) {
V_4 -> V_266 -> V_20 = V_46 ;
V_4 -> V_266 = V_46 ;
} else {
V_4 -> V_267 = V_46 ;
V_4 -> V_266 = V_46 ;
}
F_237 ( V_2 ) ;
return 0 ;
}
int F_233 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = V_177 -> V_274 ;
if ( ! V_281 -> V_299 && V_177 -> V_276 > 1 )
F_27 ( V_2 , L_151 ,
L_152 , V_177 -> V_276 ) ;
if ( ! V_177 -> V_182 ) {
F_238 ( 1 ) ;
return - V_99 ;
}
V_177 -> V_276 -- ;
if ( V_177 -> V_276 > 0 ) {
struct V_176 * V_300 =
V_281 -> V_299 ;
F_81 ( V_300 -> V_274 != V_177 -> V_274 ) ;
if ( V_177 != V_300 ) {
memcpy ( V_281 -> V_299 , V_177 , sizeof( * V_177 ) ) ;
V_177 -> V_182 = 0 ;
}
return 0 ;
} else {
return F_151 ( V_177 , 0 ) ;
}
}
static int F_239 ( struct V_1 * V_2 ,
T_1 V_52 , int V_310 )
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
if ( V_46 == V_4 -> V_267 ) {
V_4 -> V_267 = V_46 -> V_20 ;
}
if ( V_46 == V_4 -> V_266 ) {
V_4 -> V_266 = V_46 -> V_45 ;
}
if ( V_9 )
F_127 ( V_2 , V_4 -> V_5 , NULL ,
V_9 -> V_74 , 0 ) ;
F_240 ( V_9 ) ;
if ( ! V_310 ) {
F_235 ( V_9 ) ;
F_4 ( V_9 ) ;
F_5 ( V_9 ) ;
F_59 ( V_9 ) ;
if ( F_88 ( & V_9 -> V_154 ) < 0 ) {
F_27 ( V_2 , L_153 ,
L_154 ) ;
}
V_82 = 1 ;
}
V_4 -> V_116 -- ;
V_4 -> V_263 -- ;
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
F_88 ( & V_173 -> V_124 -> V_107 ) > 0 && V_173 -> V_9 &&
V_173 -> V_52 && V_173 -> V_2 == V_2 && V_173 -> V_52 == V_52 ) {
F_137 = 0 ;
}
V_173 = V_173 -> V_53 ;
}
return F_137 ;
}
int F_241 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = V_177 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_81 ( ! V_177 -> V_182 ) ;
F_81 ( V_177 -> V_276 > 1 ) ;
if ( V_4 -> V_116 == 0 ) {
F_153 ( V_2 , F_154 ( V_2 ) ,
1 ) ;
F_155 ( V_177 , F_154 ( V_2 ) ) ;
}
return F_151 ( V_177 , V_295 | V_311 ) ;
}
static void V_271 ( struct V_312 * V_313 )
{
struct V_3 * V_4 =
F_242 ( V_313 , struct V_3 , V_185 . V_313 ) ;
struct V_1 * V_2 = V_4 -> V_272 ;
struct V_38 * V_39 ;
struct V_17 * V_18 ;
F_160 ( V_2 ) ;
if ( ! F_54 ( & V_4 -> V_67 ) ) {
V_18 = V_4 -> V_67 . V_45 ;
V_39 = F_55 ( V_18 ) ;
F_29 ( V_2 , V_39 , 1 ) ;
}
F_157 ( V_2 ) ;
}
void F_243 ( struct V_1 * V_2 )
{
T_3 V_275 ;
struct V_176 V_177 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_275 = F_187 () ;
if ( F_54 ( & V_4 -> V_67 ) )
return;
if ( F_88 ( & V_4 -> V_146 ) <= 0 &&
V_4 -> V_265 > 0 &&
V_4 -> V_116 > 0 &&
( V_275 - V_4 -> V_265 ) > V_4 -> V_259 ) {
if ( ! F_152 ( & V_177 , V_2 ) ) {
F_153 ( V_2 ,
F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_177 , F_154 ( V_2 ) ) ;
F_151 ( & V_177 , V_295 | V_311 ) ;
}
}
}
static int F_244 ( struct V_176 * V_177 , int V_314 )
{
T_3 V_275 ;
int V_315 = V_314 & V_183 ;
int V_316 = V_314 & V_295 ;
int V_317 = V_314 & V_311 ;
struct V_38 * V_39 ;
struct V_1 * V_2 = V_177 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_81 ( ! V_177 -> V_182 ) ;
if ( V_177 -> V_182 != V_4 -> V_65 ) {
F_51 ( V_177 -> V_274 , L_140 ,
L_141 ,
V_177 -> V_182 , V_4 -> V_65 ) ;
}
V_4 -> V_263 -= ( V_177 -> V_277 - V_177 -> V_297 ) ;
if ( F_88 ( & V_4 -> V_146 ) > 0 )
F_89 ( & V_4 -> V_146 ) ;
F_81 ( V_4 -> V_116 == 0 ) ;
if ( F_88 ( & V_4 -> V_146 ) > 0 ) {
if ( V_315 || V_316 ) {
unsigned V_66 ;
V_39 = V_4 -> V_91 ;
V_66 = V_39 -> V_65 ;
if ( V_317 )
V_39 -> V_151 |= V_285 ;
F_110 ( & V_4 -> V_269 , 1 ) ;
if ( V_315 ) {
V_4 -> V_318 = 1 ;
}
F_47 ( V_2 ) ;
while ( V_4 -> V_65 == V_66 ) {
if ( F_88 ( & V_4 -> V_269 ) ) {
F_217 ( V_2 ) ;
} else {
F_45 ( V_2 ) ;
if ( V_4 -> V_65 == V_66 ) {
F_110 ( & V_4 -> V_269 ,
1 ) ;
}
F_47 ( V_2 ) ;
}
}
F_81 ( V_4 -> V_65 == V_66 ) ;
if ( V_316
&& F_53 ( V_2 , V_66 )
&& V_317 ) {
F_29 ( V_2 , V_39 , 1 ) ;
}
return 0 ;
}
F_47 ( V_2 ) ;
return 0 ;
}
V_275 = F_187 () ;
if ( ( V_275 - V_4 -> V_265 ) > V_4 -> V_259 ) {
V_316 = 1 ;
V_4 -> V_319 = 1 ;
}
if ( ! ( V_4 -> V_270 > 0 ) && ! ( F_88 ( & V_4 -> V_269 ) )
&& ! V_315 && ! V_316 && ( V_4 -> V_116 < V_4 -> V_239 )
&& V_4 -> V_263 < V_4 -> V_239
&& V_4 -> V_47 > ( V_4 -> V_148 * 3 ) ) {
V_4 -> V_264 ++ ;
F_47 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_119 > F_112 ( V_2 ) ) {
F_51 ( V_2 , L_155 ,
L_156 ,
V_4 -> V_119 ) ;
}
return 1 ;
}
int F_245 ( struct V_176 * V_177 ,
struct V_1 * V_2 , T_1 V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_28 * V_29 = NULL ;
int V_320 = 0 ;
F_81 ( ! V_177 -> V_182 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_5 , V_52 ) ;
if ( V_46 && V_46 -> V_9 ) {
V_9 = V_46 -> V_9 ;
F_71 ( V_9 ) ;
}
if ( V_9 && F_246 ( V_9 ) ) {
F_72 ( V_9 ) ;
F_34 ( V_9 ) ;
F_3 ( V_9 ) ;
V_320 = F_239 ( V_2 , V_52 , V_320 ) ;
} else {
V_29 = V_4 -> V_91 -> V_42 ;
if ( ! V_29 ) {
F_51 ( V_2 , L_157 ,
L_158 ) ;
}
F_18 ( V_2 , V_52 , V_29 ) ;
if ( V_9 ) {
F_34 ( V_9 ) ;
F_3 ( V_9 ) ;
}
V_320 = F_239 ( V_2 , V_52 , V_320 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_58 ,
V_52 ) ;
while ( V_46 ) {
if ( V_2 == V_46 -> V_2 && V_52 == V_46 -> V_52 ) {
F_19 ( V_174 , & V_46 -> V_128 ) ;
if ( V_46 -> V_9 ) {
if ( ! V_320 ) {
F_235 ( V_46 ->
V_9 ) ;
F_4 ( V_46 -> V_9 ) ;
F_5 ( V_46 ->
V_9 ) ;
V_320 = 1 ;
F_59 ( V_46 -> V_9 ) ;
if ( F_88
( & V_46 -> V_9 -> V_154 ) < 0 ) {
F_27 ( V_2 ,
L_159 ,
L_160 ) ;
}
}
if ( V_46 -> V_124 ) {
F_89 ( & V_46 -> V_124 ->
V_149 ) ;
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
void F_247 ( struct V_94 * V_94 )
{
struct V_3 * V_4 = F_2 ( V_94 -> V_95 ) ;
F_248 ( V_94 ) -> V_321 = V_4 -> V_91 ;
F_248 ( V_94 ) -> V_322 = V_4 -> V_65 ;
}
static int F_249 ( struct V_94 * V_94 , unsigned long V_12 ,
struct V_38 * V_39 )
{
struct V_176 V_177 ;
struct V_1 * V_2 = V_94 -> V_95 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_82 = 0 ;
if ( V_12 == V_4 -> V_65 ) {
V_39 = V_4 -> V_91 ;
F_226 ( V_2 , V_12 ) ;
if ( V_4 -> V_65 != V_12 ) {
goto V_323;
}
V_82 = F_231 ( & V_177 , V_2 , 1 ) ;
if ( V_82 )
return V_82 ;
if ( V_4 -> V_65 != V_12 ) {
F_153 ( V_2 , F_154 ( V_2 ) ,
1 ) ;
F_155 ( & V_177 , F_154 ( V_2 ) ) ;
V_82 = F_233 ( & V_177 ) ;
goto V_323;
}
V_82 = F_241 ( & V_177 ) ;
if ( ! V_82 )
V_82 = 1 ;
} else {
V_323:
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
int F_250 ( struct V_94 * V_94 )
{
unsigned int V_12 = F_248 ( V_94 ) -> V_322 ;
struct V_38 * V_39 = F_248 ( V_94 ) -> V_321 ;
if ( ! V_12 || ! V_39 ) {
F_247 ( V_94 ) ;
V_12 = F_248 ( V_94 ) -> V_322 ;
}
return F_249 ( V_94 , V_12 , V_39 ) ;
}
void F_251 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_40 ( V_2 , V_4 . V_324 ) ;
if ( ! V_9 ) {
return;
}
if ( F_252 ( V_9 ) &&
F_136 ( V_9 ) ) {
struct V_7 * V_46 ;
F_160 ( V_2 ) ;
V_46 = F_37 ( V_2 ,
V_4 -> V_58 ,
V_9 -> V_74 ) ;
if ( V_46 && F_137 ( V_46 ) ) {
F_143 ( V_9 ) ;
F_119 ( V_9 ) ;
}
F_157 ( V_2 ) ;
}
F_35 ( V_9 ) ;
}
int F_153 ( struct V_1 * V_2 ,
struct V_8 * V_9 , int V_279 )
{
F_40 ( V_2 , V_4 . V_325 ) ;
if ( ! F_96 ( V_9 ) ) {
if ( ! V_279 )
return 0 ;
F_138 ( V_9 ) ;
}
F_253 ( V_9 ) ;
if ( F_254 ( V_9 ) && F_136 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_142 ( V_9 ) ;
}
F_68 ( V_9 ) ;
return 1 ;
}
static int F_151 ( struct V_176 * V_177 , int V_314 )
{
struct V_1 * V_2 = V_177 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 , * V_20 , * V_326 ;
struct V_7 * V_327 = NULL ;
struct V_186 * V_187 ;
struct V_188 * V_189 ;
struct V_8 * V_193 ;
struct V_8 * V_190 ;
int V_328 = 0 ;
int V_329 ;
int V_25 ;
int V_315 ;
int V_317 ;
struct V_38 * V_39 , * V_330 ;
struct V_17 * V_18 , * V_331 ;
unsigned long V_332 ;
unsigned int V_333 ;
int V_204 ;
int V_109 ;
F_81 ( V_177 -> V_276 > 1 ) ;
F_81 ( ! V_177 -> V_182 ) ;
F_81 ( ! V_177 -> V_274 ) ;
if ( V_177 -> V_182 == ~ 0U )
V_314 |= V_183 | V_295 | V_311 ;
V_315 = V_314 & V_183 ;
V_317 = V_314 & V_311 ;
V_281 -> V_299 = V_177 -> V_301 ;
F_32 ( V_2 , L_161 ) ;
if ( V_4 -> V_116 == 0 ) {
F_153 ( V_2 , F_154 ( V_2 ) ,
1 ) ;
F_155 ( V_177 , F_154 ( V_2 ) ) ;
}
F_45 ( V_2 ) ;
if ( V_4 -> V_318 ) {
V_314 |= V_183 ;
V_315 = 1 ;
}
if ( V_4 -> V_319 ) {
V_314 |= V_295 | V_311 ;
V_317 = 1 ;
}
if ( ! F_244 ( V_177 , V_314 ) ) {
F_237 ( V_2 ) ;
F_224 ( V_2 ) ;
F_106 ( V_2 ) ;
goto V_334;
}
if ( V_4 -> V_318 ) {
V_315 = 1 ;
}
if ( V_4 -> V_270 > 0 ) {
V_315 = 1 ;
}
#ifdef F_255
V_281 -> V_299 = V_177 ;
V_177 -> V_276 ++ ;
F_256 ( V_177 ) ;
V_177 -> V_276 -- ;
V_281 -> V_299 = V_177 -> V_301 ;
#endif
V_190 =
F_177 ( V_2 ,
F_111 ( V_2 ) +
V_4 -> V_119 ) ;
F_66 ( V_190 ) ;
V_187 = (struct V_186 * ) ( V_190 ) -> V_134 ;
memset ( V_190 -> V_134 , 0 , V_190 -> V_209 ) ;
memcpy ( F_169 ( V_190 ) , V_194 , 8 ) ;
F_257 ( V_187 , V_4 -> V_65 ) ;
V_193 = F_177 ( V_2 , F_111 ( V_2 ) +
( ( V_4 -> V_119 + V_4 -> V_116 +
1 ) % F_112 ( V_2 ) ) ) ;
V_189 = (struct V_188 * ) V_193 -> V_134 ;
memset ( V_193 -> V_134 , 0 , V_193 -> V_209 ) ;
F_258 ( V_189 , V_4 -> V_65 ) ;
F_66 ( V_193 ) ;
V_39 = V_4 -> V_91 ;
F_46 ( & V_39 -> V_118 , V_2 ) ;
V_333 = V_39 -> V_65 ;
F_110 ( & V_39 -> V_106 , 0 ) ;
V_39 -> V_65 = V_4 -> V_65 ;
V_39 -> V_335 = V_4 -> V_265 ;
V_39 -> V_120 = V_193 ;
V_39 -> V_119 = V_4 -> V_119 ;
V_39 -> V_116 = V_4 -> V_116 ;
F_110 ( & V_39 -> V_149 , V_4 -> V_116 ) ;
F_110 ( & V_39 -> V_107 , V_4 -> V_116 + 2 ) ;
V_39 -> V_127 = NULL ;
V_204 = F_176 ( V_2 -> V_15 ) ;
for ( V_25 = 0 , V_46 = V_4 -> V_267 ; V_46 ; V_46 = V_46 -> V_20 , V_25 ++ ) {
if ( F_64 ( V_46 -> V_9 ) ) {
V_326 = F_31 ( V_2 ) ;
if ( ! V_326 ) {
F_51 ( V_2 , L_162 ,
L_163 ) ;
}
if ( V_25 == 0 ) {
V_39 -> V_127 = V_326 ;
}
V_326 -> V_45 = V_327 ;
V_326 -> V_20 = NULL ;
if ( V_327 ) {
V_327 -> V_20 = V_326 ;
}
V_327 = V_326 ;
if ( F_181
( V_2 , V_46 -> V_9 -> V_74 ) ) {
F_51 ( V_2 , L_164 ,
L_165
L_166 ,
V_46 -> V_9 -> V_74 ) ;
}
V_326 -> V_52 = V_46 -> V_9 -> V_74 ;
V_326 -> V_128 = 0 ;
V_326 -> V_2 = V_2 ;
V_326 -> V_9 = V_46 -> V_9 ;
V_326 -> V_124 = V_39 ;
F_44 ( V_4 -> V_58 , V_326 ) ;
if ( V_25 < V_204 ) {
V_187 -> V_127 [ V_25 ] =
F_129 ( V_46 -> V_9 -> V_74 ) ;
} else {
V_189 -> V_127 [ V_25 - V_204 ] =
F_129 ( V_46 -> V_9 -> V_74 ) ;
}
} else {
V_25 -- ;
}
}
F_259 ( V_187 , V_4 -> V_116 ) ;
F_260 ( V_187 , V_4 -> V_135 ) ;
F_257 ( V_187 , V_4 -> V_65 ) ;
F_261 ( V_189 , V_4 -> V_116 ) ;
F_81 ( V_4 -> V_116 == 0 ) ;
F_119 ( V_190 ) ;
V_328 = V_4 -> V_119 ;
V_46 = V_4 -> V_267 ;
V_332 = 1 ;
while ( V_46 ) {
F_72 ( V_46 -> V_9 ) ;
if ( F_64 ( V_46 -> V_9 ) ) {
struct V_8 * V_158 ;
char * V_336 ;
struct V_68 * V_68 ;
V_158 =
F_177 ( V_2 ,
F_111 ( V_2 ) +
( ( V_328 +
V_332 ) %
F_112 ( V_2 ) ) ) ;
F_66 ( V_158 ) ;
V_68 = V_46 -> V_9 -> V_69 ;
V_336 = F_262 ( V_68 ) ;
memcpy ( V_158 -> V_134 ,
V_336 + F_263 ( V_46 -> V_9 -> V_134 ) ,
V_46 -> V_9 -> V_209 ) ;
F_264 ( V_68 ) ;
F_119 ( V_158 ) ;
V_332 ++ ;
F_265 ( V_46 -> V_9 ) ;
F_240 ( V_46 -> V_9 ) ;
} else {
F_27 ( V_2 , L_167 ,
L_168
L_169 ) ;
F_148 ( V_46 -> V_9 ) ;
}
V_20 = V_46 -> V_20 ;
F_33 ( V_2 , V_46 ) ;
V_46 = V_20 ;
F_266 ( V_2 ) ;
}
V_4 -> V_91 = F_188 ( V_2 ) ;
F_91 ( & V_39 -> V_105 , & V_4 -> V_67 ) ;
F_91 ( & V_39 -> V_137 , & V_4 -> V_137 ) ;
V_4 -> V_138 ++ ;
V_329 = V_4 -> V_119 ;
V_4 -> V_119 =
( V_4 -> V_119 + V_4 -> V_116 +
2 ) % F_112 ( V_2 ) ;
F_110 ( & V_4 -> V_146 , 0 ) ;
V_4 -> V_264 = 0 ;
V_4 -> V_266 = NULL ;
V_4 -> V_267 = NULL ;
V_4 -> V_116 = 0 ;
V_4 -> V_265 = 0 ;
if ( ++ V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_91 -> V_65 = V_4 -> V_65 ;
V_4 -> V_270 = 0 ;
V_4 -> V_263 = 0 ;
V_4 -> V_318 = 0 ;
V_4 -> V_319 = 0 ;
F_1 ( V_2 ) ;
F_267 () ;
if ( ! F_54 ( & V_39 -> V_92 ) ) {
V_109 = F_107 ( V_2 ) ;
F_94 ( & V_4 -> V_89 ,
V_4 , V_39 , & V_39 -> V_92 ) ;
F_109 ( V_2 , V_109 ) ;
}
F_81 ( ! F_54 ( & V_39 -> V_92 ) ) ;
F_48 ( & V_39 -> V_118 ) ;
if ( V_315 ) {
F_29 ( V_2 , V_39 , 1 ) ;
F_133 ( V_2 , V_39 , 1 ) ;
} else if ( ! ( V_39 -> V_151 & V_285 ) ) {
if ( V_2 -> V_180 & V_337 )
F_268 ( F_159 ( V_2 ) -> V_338 ,
& V_4 -> V_185 , V_111 / 10 ) ;
}
V_101:
F_269 (entry, safe, &journal->j_journal_list) {
V_330 = F_55 ( V_18 ) ;
if ( V_4 -> V_119 <= V_330 -> V_119 ) {
if ( ( V_4 -> V_119 + V_4 -> V_148 + 1 ) >=
V_330 -> V_119 ) {
F_145 ( V_2 , V_330 ) ;
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
V_330 -> V_119 ) {
F_145 ( V_2 , V_330 ) ;
goto V_101;
} else {
break;
}
}
}
V_4 -> V_91 -> V_42 =
F_28 ( V_2 , V_4 -> V_91 ) ;
if ( ! ( V_4 -> V_91 -> V_42 ) ) {
F_51 ( V_2 , L_170 ,
L_171 ) ;
}
F_110 ( & V_4 -> V_269 , 0 ) ;
F_47 ( V_2 ) ;
F_213 ( V_280 , & V_4 -> V_151 ) ;
F_214 ( & V_4 -> V_268 ) ;
if ( ! V_315 && V_317 &&
F_53 ( V_2 , V_333 ) ) {
F_29 ( V_2 , V_39 , 1 ) ;
}
V_334:
F_32 ( V_2 , L_172 ) ;
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_177 -> V_274 = V_2 ;
return V_4 -> V_96 ;
}
void F_270 ( struct V_1 * V_2 , int V_339 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_41 ( V_340 , & V_4 -> V_151 ) )
return;
if ( ! V_4 -> V_96 )
V_4 -> V_96 = V_339 ;
V_2 -> V_180 |= V_181 ;
F_19 ( V_340 , & V_4 -> V_151 ) ;
#ifdef F_116
F_271 () ;
#endif
}
