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
if ( F_64 ( V_9 ) ) {
F_27 ( NULL , L_8 ,
L_9 ,
V_9 -> V_72 , V_9 -> V_73 ) ;
}
if ( V_71 )
F_65 ( V_9 ) ;
else
F_66 ( V_9 ) ;
F_67 ( V_9 ) ;
F_56 ( V_9 ) ;
}
static void F_68 ( struct V_8 * V_9 , int V_71 )
{
if ( V_71 )
F_65 ( V_9 ) ;
else
F_66 ( V_9 ) ;
F_67 ( V_9 ) ;
F_59 ( V_9 ) ;
}
static void F_69 ( struct V_8 * V_9 )
{
F_70 ( V_9 ) ;
V_9 -> V_74 = F_63 ;
F_71 ( V_9 ) ;
F_4 ( V_9 ) ;
if ( ! F_72 ( V_9 ) )
F_43 () ;
if ( ! F_73 ( V_9 ) )
F_43 () ;
F_74 ( V_75 , V_9 ) ;
}
static void F_75 ( struct V_8 * V_9 )
{
F_70 ( V_9 ) ;
V_9 -> V_74 = F_68 ;
F_4 ( V_9 ) ;
if ( ! F_73 ( V_9 ) )
F_43 () ;
F_74 ( V_75 , V_9 ) ;
}
static void F_76 ( struct V_76 * V_77 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_77 -> V_78 ; V_25 ++ ) {
F_69 ( V_77 -> V_9 [ V_25 ] ) ;
}
V_77 -> V_78 = 0 ;
}
static void F_77 ( struct V_76 * V_77 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_77 -> V_78 ; V_25 ++ ) {
F_75 ( V_77 -> V_9 [ V_25 ] ) ;
}
V_77 -> V_78 = 0 ;
}
static int F_78 ( struct V_76 * V_77 , struct V_8 * V_9 ,
T_2 * V_79 , void (F_79) ( struct V_76 * ) )
{
int V_80 = 0 ;
F_80 ( V_77 -> V_78 >= V_81 ) ;
V_77 -> V_9 [ V_77 -> V_78 ++ ] = V_9 ;
if ( V_77 -> V_78 >= V_81 ) {
V_80 = 1 ;
if ( V_79 ) {
F_81 ( V_79 ) ;
F_79 ( V_77 ) ;
F_82 ( V_79 ) ;
} else {
F_79 ( V_77 ) ;
}
}
return V_80 ;
}
static struct V_82 * F_83 ( void )
{
struct V_82 * V_83 ;
while ( 1 ) {
V_83 = F_7 ( sizeof( * V_83 ) , V_13 ) ;
if ( V_83 ) {
F_84 ( & V_84 ) ;
return V_83 ;
}
F_14 () ;
}
}
void F_85 ( struct V_8 * V_9 )
{
struct V_82 * V_83 ;
V_83 = V_9 -> V_85 ;
if ( V_83 ) {
V_9 -> V_85 = NULL ;
V_83 -> V_9 = NULL ;
F_86 ( & V_83 -> V_16 ) ;
F_9 ( V_83 ) ;
if ( F_87 ( & V_84 ) <= 0 )
F_43 () ;
F_88 ( & V_84 ) ;
F_59 ( V_9 ) ;
}
}
static inline int F_89 ( struct V_3 * V_40 , struct V_8 * V_9 ,
int V_86 )
{
struct V_82 * V_83 ;
if ( V_9 -> V_85 ) {
F_82 ( & V_40 -> V_87 ) ;
if ( ! V_9 -> V_85 ) {
F_81 ( & V_40 -> V_87 ) ;
goto V_88;
}
V_83 = V_9 -> V_85 ;
F_86 ( & V_83 -> V_16 ) ;
} else {
V_88:
F_70 ( V_9 ) ;
V_83 = F_83 () ;
F_82 ( & V_40 -> V_87 ) ;
F_80 ( V_9 -> V_85 ) ;
V_83 -> V_9 = V_9 ;
V_9 -> V_85 = V_83 ;
}
V_83 -> V_39 = V_40 -> V_89 ;
if ( V_86 )
F_90 ( & V_83 -> V_16 , & V_83 -> V_39 -> V_90 ) ;
else {
F_90 ( & V_83 -> V_16 , & V_83 -> V_39 -> V_91 ) ;
}
F_81 ( & V_40 -> V_87 ) ;
return 0 ;
}
int F_91 ( struct V_92 * V_92 , struct V_8 * V_9 )
{
return F_89 ( F_2 ( V_92 -> V_93 ) , V_9 , 1 ) ;
}
int F_92 ( struct V_92 * V_92 , struct V_8 * V_9 )
{
return F_89 ( F_2 ( V_92 -> V_93 ) , V_9 , 0 ) ;
}
static int F_93 ( T_2 * V_79 ,
struct V_3 * V_40 ,
struct V_38 * V_39 ,
struct V_17 * V_16 )
{
struct V_8 * V_9 ;
struct V_82 * V_83 ;
int V_80 = V_40 -> V_94 ;
struct V_76 V_77 ;
struct V_17 V_95 ;
F_10 ( & V_95 ) ;
V_77 . V_78 = 0 ;
F_82 ( V_79 ) ;
while ( ! F_54 ( V_16 ) ) {
V_83 = F_94 ( V_16 -> V_20 ) ;
V_9 = V_83 -> V_9 ;
F_70 ( V_9 ) ;
if ( ! F_95 ( V_9 ) ) {
if ( ! F_96 ( V_9 ) ) {
F_97 ( & V_83 -> V_16 , & V_95 ) ;
goto V_96;
}
F_81 ( V_79 ) ;
if ( V_77 . V_78 )
F_77 ( & V_77 ) ;
F_98 ( V_9 ) ;
F_99 () ;
F_82 ( V_79 ) ;
goto V_96;
}
if ( ! F_73 ( V_9 ) && F_96 ( V_9 ) ) {
F_4 ( V_9 ) ;
V_80 = - V_97 ;
}
if ( F_96 ( V_9 ) ) {
F_97 ( & V_83 -> V_16 , & V_95 ) ;
F_78 ( & V_77 , V_9 , V_79 , F_77 ) ;
} else {
F_85 ( V_9 ) ;
F_67 ( V_9 ) ;
}
V_96:
F_59 ( V_9 ) ;
F_100 ( V_79 ) ;
}
if ( V_77 . V_78 ) {
F_81 ( V_79 ) ;
F_77 ( & V_77 ) ;
F_82 ( V_79 ) ;
}
while ( ! F_54 ( & V_95 ) ) {
V_83 = F_94 ( V_95 . V_45 ) ;
V_9 = V_83 -> V_9 ;
F_70 ( V_9 ) ;
F_85 ( V_9 ) ;
if ( F_101 ( V_9 ) ) {
F_81 ( V_79 ) ;
F_98 ( V_9 ) ;
F_82 ( V_79 ) ;
}
if ( ! F_73 ( V_9 ) ) {
V_80 = - V_97 ;
}
if ( F_96 ( V_9 ) && F_102 ( V_9 -> V_69 -> V_70 == NULL ) ) {
F_81 ( V_79 ) ;
F_103 ( V_75 , 1 , & V_9 ) ;
F_82 ( V_79 ) ;
}
F_59 ( V_9 ) ;
F_100 ( V_79 ) ;
}
F_81 ( V_79 ) ;
return V_80 ;
}
static int F_104 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
struct V_38 * V_98 ;
struct V_38 * V_99 ;
struct V_17 * V_18 ;
unsigned int V_66 = V_39 -> V_65 ;
unsigned int V_100 ;
unsigned int V_101 ;
V_102:
V_99 = V_39 ;
V_18 = V_39 -> V_103 . V_45 ;
while ( 1 ) {
V_98 = F_55 ( V_18 ) ;
if ( V_18 == & V_4 -> V_67 ||
F_87 ( & V_98 -> V_104 ) )
break;
V_99 = V_98 ;
V_18 = V_98 -> V_103 . V_45 ;
}
if ( V_99 == V_39 ) {
return 0 ;
}
V_101 = V_99 -> V_65 ;
V_18 = & V_99 -> V_103 ;
while ( 1 ) {
V_98 = F_55 ( V_18 ) ;
V_100 = V_98 -> V_65 ;
if ( V_100 < V_66 ) {
if ( F_87 ( & V_98 -> V_105 ) != 0 ) {
F_29 ( V_64 , V_98 , 0 ) ;
if ( ! F_53 ( V_64 , V_66 ) )
return 1 ;
if ( ! F_53
( V_64 , V_100 ) ) {
goto V_102;
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
static int F_105 ( struct V_1 * V_64 )
{
struct V_3 * V_40 = F_2 ( V_64 ) ;
if ( F_87 ( & V_40 -> V_106 ) ) {
int V_107 ;
V_107 = F_106 ( V_64 ) ;
F_107 ( V_108 , V_109 / 10 ) ;
F_108 ( V_64 , V_107 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_64 ,
struct V_38 * V_39 , int V_110 )
{
int V_25 ;
T_1 V_11 ;
struct V_8 * V_111 = NULL ;
unsigned int V_66 = V_39 -> V_65 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
int V_112 = 0 ;
int V_113 ;
int V_107 ;
F_32 ( V_64 , L_10 ) ;
if ( F_87 ( & V_39 -> V_104 ) ) {
return 0 ;
}
F_80 ( V_39 -> V_114 <= 0 ) ;
F_80 ( V_66 == V_4 -> V_65 ) ;
F_49 ( V_39 ) ;
if ( V_110 ) {
if ( F_104 ( V_64 , V_39 ) == 1 ) {
goto V_115;
}
}
F_46 ( & V_39 -> V_116 , V_64 ) ;
if ( ! F_53 ( V_64 , V_66 ) ) {
F_48 ( & V_39 -> V_116 ) ;
goto V_115;
}
F_80 ( V_39 -> V_65 == 0 ) ;
if ( F_87 ( & V_39 -> V_105 ) <= 0 ) {
if ( V_110 ) {
F_109 ( & V_39 -> V_104 , 1 ) ;
}
F_48 ( & V_39 -> V_116 ) ;
goto V_115;
}
if ( ! F_54 ( & V_39 -> V_91 ) ) {
int V_80 ;
V_107 = F_106 ( V_64 ) ;
V_80 = F_93 ( & V_4 -> V_87 ,
V_4 , V_39 , & V_39 -> V_91 ) ;
if ( V_80 < 0 && V_112 == 0 )
V_112 = V_80 ;
F_108 ( V_64 , V_107 ) ;
}
F_80 ( ! F_54 ( & V_39 -> V_91 ) ) ;
F_84 ( & V_4 -> V_106 ) ;
V_113 = V_39 -> V_114 + 1 ;
if ( V_113 < 256 )
V_113 = 256 ;
for ( V_25 = 0 ; V_25 < V_113 ; V_25 ++ ) {
V_11 = F_110 ( V_64 ) + ( V_39 -> V_117 + V_25 ) %
F_111 ( V_64 ) ;
V_111 = F_112 ( V_64 , V_11 ) ;
if ( V_111 ) {
if ( F_96 ( V_111 ) ) {
V_107 = F_106 ( V_64 ) ;
F_103 ( V_75 , 1 , & V_111 ) ;
F_108 ( V_64 , V_107 ) ;
}
F_59 ( V_111 ) ;
}
}
F_88 ( & V_4 -> V_106 ) ;
for ( V_25 = 0 ; V_25 < ( V_39 -> V_114 + 1 ) ; V_25 ++ ) {
V_11 = F_110 ( V_64 ) +
( V_39 -> V_117 + V_25 ) % F_111 ( V_64 ) ;
V_111 = F_112 ( V_64 , V_11 ) ;
V_107 = F_106 ( V_64 ) ;
F_113 ( V_111 ) ;
F_108 ( V_64 , V_107 ) ;
if ( F_96 ( V_111 ) ) {
V_107 = F_106 ( V_64 ) ;
F_114 ( V_111 ) ;
F_108 ( V_64 , V_107 ) ;
}
if ( F_102 ( ! F_73 ( V_111 ) ) ) {
#ifdef F_115
F_27 ( V_64 , L_11 ,
L_12 ) ;
#endif
V_112 = - V_97 ;
}
F_59 ( V_111 ) ;
F_59 ( V_111 ) ;
F_88 ( & V_39 -> V_105 ) ;
}
F_80 ( F_87 ( & V_39 -> V_105 ) != 1 ) ;
if ( F_116 ( ! V_112 && ! F_117 ( V_4 ) ) ) {
if ( F_96 ( V_39 -> V_118 ) )
F_43 () ;
F_118 ( V_39 -> V_118 ) ;
V_107 = F_106 ( V_64 ) ;
if ( F_119 ( V_64 ) )
F_120 ( V_39 -> V_118 , V_119 ) ;
else
F_114 ( V_39 -> V_118 ) ;
F_108 ( V_64 , V_107 ) ;
}
if ( F_102 ( ! F_73 ( V_39 -> V_118 ) ) ) {
#ifdef F_115
F_27 ( V_64 , L_13 , L_12 ) ;
#endif
V_112 = - V_97 ;
}
F_121 ( V_39 -> V_118 ) ;
if ( V_4 -> V_120 != 0 &&
( V_39 -> V_65 - V_4 -> V_120 ) != 1 ) {
F_27 ( V_64 , L_14 , L_15 ,
V_4 -> V_120 , V_39 -> V_65 ) ;
}
V_4 -> V_120 = V_39 -> V_65 ;
F_52 ( V_64 , V_39 ) ;
V_112 = V_112 ? V_112 : V_4 -> V_94 ;
if ( ! V_112 )
F_122 ( V_64 , V_39 ) ;
F_88 ( & V_39 -> V_105 ) ;
if ( V_110 ) {
F_109 ( & V_39 -> V_104 , 1 ) ;
}
F_48 ( & V_39 -> V_116 ) ;
V_115:
F_50 ( V_64 , V_39 ) ;
if ( V_112 )
F_123 ( V_64 , V_112 , L_16 ,
V_121 ) ;
return V_112 ;
}
static struct V_38 * F_124 ( struct
V_7
* V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
T_1 V_52 = V_46 -> V_52 ;
V_46 = V_46 -> V_61 ;
while ( V_46 ) {
if ( V_46 -> V_2 == V_2 && V_46 -> V_52 == V_52 && V_46 -> V_122 ) {
return V_46 -> V_122 ;
}
V_46 = V_46 -> V_61 ;
}
return NULL ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_123 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 , * V_124 ;
V_46 = V_39 -> V_125 ;
while ( V_46 ) {
if ( V_46 -> V_52 != 0 ) {
if ( V_123 ) {
F_27 ( V_2 , L_17 ,
L_18 ,
V_46 -> V_52 , V_46 -> V_9 ? 1 : 0 ,
V_46 -> V_126 ) ;
}
V_46 -> V_126 = 0 ;
F_126 ( V_2 , V_4 -> V_58 ,
V_39 , V_46 -> V_52 , 1 ) ;
}
V_124 = V_46 ;
V_46 = V_46 -> V_20 ;
F_33 ( V_2 , V_124 ) ;
}
V_39 -> V_125 = NULL ;
}
static int F_127 ( struct V_1 * V_2 ,
unsigned long V_127 ,
unsigned int V_66 )
{
struct V_128 * V_83 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_107 ;
if ( F_117 ( V_4 ) )
return - V_97 ;
if ( V_66 >= V_4 -> V_129 ) {
if ( F_101 ( ( V_4 -> V_130 ) ) ) {
V_107 = F_106 ( V_2 ) ;
F_113 ( V_4 -> V_130 ) ;
F_108 ( V_2 , V_107 ) ;
if ( F_102 ( ! F_73 ( V_4 -> V_130 ) ) ) {
#ifdef F_115
F_27 ( V_2 , L_19 ,
L_12 ) ;
#endif
return - V_97 ;
}
}
V_4 -> V_129 = V_66 ;
V_4 -> V_131 = V_127 ;
V_83 = (struct V_128 * ) ( V_4 -> V_130 ->
V_132 ) ;
V_83 -> V_129 = F_128 ( V_66 ) ;
V_83 -> V_131 = F_128 ( V_127 ) ;
V_83 -> V_133 = F_128 ( V_4 -> V_133 ) ;
F_129 ( V_4 -> V_130 ) ;
V_107 = F_106 ( V_2 ) ;
if ( F_119 ( V_2 ) )
F_120 ( V_4 -> V_130 , V_119 ) ;
else
F_114 ( V_4 -> V_130 ) ;
F_108 ( V_2 , V_107 ) ;
if ( ! F_73 ( V_4 -> V_130 ) ) {
F_27 ( V_2 , L_20 ,
L_21 ) ;
return - V_97 ;
}
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 ,
unsigned long V_127 ,
unsigned int V_66 )
{
return F_127 ( V_2 , V_127 , V_66 ) ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_17 * V_18 ;
struct V_38 * V_98 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_66 = V_39 -> V_65 ;
V_134:
V_18 = V_4 -> V_67 . V_20 ;
if ( V_18 == & V_4 -> V_67 )
return 0 ;
V_98 = F_55 ( V_18 ) ;
if ( V_98 -> V_65 < V_66 ) {
F_80 ( V_98 -> V_63 <= 0 ) ;
F_132 ( V_2 , V_98 , 0 ) ;
goto V_134;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
if ( ! F_54 ( & V_39 -> V_135 ) ) {
F_86 ( & V_39 -> V_135 ) ;
V_4 -> V_136 -- ;
}
}
static int F_132 ( struct V_1 * V_64 ,
struct V_38 * V_39 , int V_110 )
{
struct V_38 * V_137 ;
struct V_7 * V_46 , * V_124 ;
int V_138 ;
int V_139 = 0 ;
int V_140 = 0 ;
struct V_8 * V_141 ;
unsigned long V_142 = V_39 -> V_114 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
int V_143 = 0 ;
int V_107 ;
F_80 ( V_142 <= 0 ) ;
if ( F_87 ( & V_4 -> V_144 ) != 0 ) {
F_27 ( V_64 , L_22 , L_23 ,
F_87 ( & V_4 -> V_144 ) ) ;
}
if ( V_110 ) {
F_46 ( & V_4 -> V_145 , V_64 ) ;
} else if ( F_134 ( & V_4 -> V_145 ) ) {
F_43 () ;
}
V_138 = 0 ;
if ( V_142 > V_4 -> V_146 ) {
F_51 ( V_64 , L_24 , L_25 ,
V_142 , V_39 -> V_65 ) ;
return 0 ;
}
if ( F_87 ( & V_39 -> V_147 ) <= 0 &&
F_87 ( & V_39 -> V_105 ) <= 0 ) {
goto V_148;
}
F_29 ( V_64 , V_39 , 1 ) ;
if ( ! ( V_39 -> V_149 & V_150 )
&& ! F_117 ( V_4 ) )
F_43 () ;
if ( F_87 ( & V_39 -> V_147 ) <= 0 &&
F_87 ( & V_39 -> V_105 ) <= 0 ) {
goto V_148;
}
if ( F_87 ( & V_4 -> V_144 ) != 0 ) {
F_51 ( V_64 , L_26 , L_27
L_28 ) ;
}
V_46 = V_39 -> V_125 ;
while ( V_46 ) {
V_139 = 0 ;
V_140 = 0 ;
V_141 = NULL ;
if ( V_46 -> V_52 == 0 ) {
goto F_33;
}
if ( ! ( V_39 -> V_149 & V_150 ) )
goto F_33;
V_137 = F_124 ( V_46 ) ;
if ( ! V_137 && V_46 -> V_9 ) {
V_141 = V_46 -> V_9 ;
F_70 ( V_141 ) ;
if ( F_135 ( V_141 ) ) {
F_80 ( ! F_136 ( V_46 ) ) ;
V_139 = 1 ;
V_140 = 1 ;
} else if ( F_136 ( V_46 ) ) {
F_43 () ;
}
}
if ( V_137 ) {
if ( F_87 ( & V_137 -> V_105 ) )
F_29 ( V_64 , V_137 , 1 ) ;
goto F_33;
}
if ( V_141 == NULL ) {
goto F_33;
}
if ( ( ! V_139 ) && ! F_101 ( V_141 ) ) {
F_27 ( V_64 , L_29 ,
L_30
L_31 ,
( unsigned long long ) V_141 ->
V_72 , V_140 ? ' ' : '!' ,
V_139 ? ' ' : '!' ) ;
}
if ( V_140 ) {
F_70 ( V_141 ) ;
F_19 ( V_151 , & V_46 -> V_126 ) ;
F_137 ( V_141 ) ;
F_80 ( V_46 -> V_52 != V_141 -> V_72 ) ;
if ( F_96 ( V_141 ) )
F_69 ( V_141 ) ;
else
F_67 ( V_141 ) ;
V_138 ++ ;
} else {
F_27 ( V_64 , L_32 ,
L_33 ,
( unsigned long long ) V_141 ->
V_72 , V_121 ) ;
}
F_33:
V_124 = V_46 ;
V_46 = V_46 -> V_20 ;
if ( V_141 ) {
F_59 ( V_141 ) ;
if ( F_87 ( & V_141 -> V_152 ) < 0 ) {
F_27 ( V_64 , L_34 ,
L_35 ) ;
}
}
}
if ( V_138 > 0 ) {
V_46 = V_39 -> V_125 ;
while ( V_46 ) {
if ( F_41 ( V_151 , & V_46 -> V_126 ) ) {
if ( ! V_46 -> V_9 ) {
F_51 ( V_64 , L_36 ,
L_37 ) ;
}
V_107 = F_106 ( V_64 ) ;
F_113 ( V_46 -> V_9 ) ;
F_108 ( V_64 , V_107 ) ;
if ( ! V_46 -> V_9 ) {
F_51 ( V_64 , L_38 ,
L_37 ) ;
}
if ( F_102 ( ! F_73 ( V_46 -> V_9 ) ) ) {
#ifdef F_115
F_27 ( V_64 , L_39 ,
L_12 ) ;
#endif
V_143 = - V_97 ;
}
F_80 ( ! F_138
( V_46 -> V_9 ) ) ;
F_59 ( V_46 -> V_9 ) ;
F_56 ( V_46 -> V_9 ) ;
}
V_46 = V_46 -> V_20 ;
}
}
if ( V_143 )
F_123 ( V_64 , - V_97 ,
L_40 ,
V_121 ) ;
V_148:
if ( V_110 ) {
F_131 ( V_64 , V_39 ) ;
}
V_143 = V_4 -> V_94 ;
if ( ! V_143 && V_110 ) {
V_143 =
F_130 ( V_64 ,
( V_39 -> V_117 + V_39 -> V_114 +
2 ) % F_111 ( V_64 ) ,
V_39 -> V_65 ) ;
if ( V_143 )
F_123 ( V_64 , - V_97 ,
L_41 ,
V_121 ) ;
}
F_125 ( V_64 , V_39 , 0 ) ;
F_86 ( & V_39 -> V_103 ) ;
V_4 -> V_153 -- ;
F_133 ( V_64 , V_39 ) ;
if ( V_4 -> V_154 != 0 &&
( V_39 -> V_65 - V_4 -> V_154 ) != 1 ) {
F_27 ( V_64 , L_42 , L_43 ,
V_4 -> V_154 , V_39 -> V_65 ) ;
}
V_4 -> V_154 = V_39 -> V_65 ;
V_39 -> V_114 = 0 ;
F_109 ( & V_39 -> V_147 , 0 ) ;
V_39 -> V_117 = 0 ;
V_39 -> V_125 = NULL ;
V_39 -> V_118 = NULL ;
V_39 -> V_65 = 0 ;
V_39 -> V_149 = 0 ;
F_50 ( V_64 , V_39 ) ;
if ( V_110 )
F_48 ( & V_4 -> V_145 ) ;
return V_143 ;
}
static int F_139 ( struct V_1 * V_64 ,
struct V_38 * V_39 ,
struct V_76 * V_77 )
{
struct V_7 * V_46 ;
int V_80 = 0 ;
V_39 -> V_149 |= V_155 ;
F_133 ( V_64 , V_39 ) ;
if ( V_39 -> V_114 == 0 || F_87 ( & V_39 -> V_147 ) == 0 ) {
return 0 ;
}
V_46 = V_39 -> V_125 ;
while ( V_46 ) {
if ( V_46 -> V_52 == 0 ) {
goto V_20;
}
if ( V_46 -> V_9 && F_136 ( V_46 ) && F_96 ( V_46 -> V_9 ) ) {
struct V_8 * V_156 ;
V_156 = V_46 -> V_9 ;
F_70 ( V_156 ) ;
F_137 ( V_156 ) ;
if ( V_46 -> V_9 && F_136 ( V_46 ) && F_96 ( V_156 ) ) {
if ( ! F_135 ( V_156 ) ||
F_140 ( V_156 ) )
F_43 () ;
F_78 ( V_77 , V_156 , NULL , F_76 ) ;
V_80 ++ ;
} else {
F_67 ( V_156 ) ;
}
F_59 ( V_156 ) ;
}
V_20:
V_46 = V_46 -> V_20 ;
F_99 () ;
}
return V_80 ;
}
static int F_122 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
struct V_7 * V_46 ;
struct V_38 * V_137 ;
int V_80 = 0 ;
V_39 -> V_149 |= V_150 ;
V_46 = V_39 -> V_125 ;
while ( V_46 ) {
V_137 = F_124 ( V_46 ) ;
if ( ! V_137 && V_46 -> V_52 && V_46 -> V_9
&& F_135 ( V_46 -> V_9 ) ) {
F_80 ( ! F_136 ( V_46 ) ) ;
F_71 ( V_46 -> V_9 ) ;
if ( F_140 ( V_46 -> V_9 ) ) {
F_141 ( V_46 -> V_9 ) ;
} else {
F_142 ( V_46 -> V_9 ) ;
F_118 ( V_46 -> V_9 ) ;
}
}
V_46 = V_46 -> V_20 ;
}
return V_80 ;
}
static int F_143 ( struct V_1 * V_64 ,
struct V_38 * V_39 ,
struct V_38 * * V_157 ,
unsigned int * V_158 ,
int V_159 , int V_160 )
{
int V_80 = 0 ;
int V_161 = 0 ;
int V_162 = 0 ;
unsigned int V_163 = V_39 -> V_65 ;
struct V_76 V_77 ;
struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
V_77 . V_78 = 0 ;
F_46 ( & V_4 -> V_145 , V_64 ) ;
if ( ! F_53 ( V_64 , V_163 ) ) {
goto V_164;
}
while ( ( V_160 && V_162 < V_160 ) ||
( ! V_160 && V_161 < V_159 ) ) {
if ( V_39 -> V_114 == 0 || ( V_39 -> V_149 & V_155 ) ||
F_87 ( & V_39 -> V_105 )
|| ! ( V_39 -> V_149 & V_150 ) ) {
F_133 ( V_64 , V_39 ) ;
break;
}
V_80 = F_139 ( V_64 , V_39 , & V_77 ) ;
if ( V_80 < 0 )
goto V_164;
V_162 ++ ;
V_161 += V_80 ;
V_18 = V_39 -> V_103 . V_20 ;
if ( V_18 == & V_4 -> V_67 ) {
break;
}
V_39 = F_55 ( V_18 ) ;
if ( V_39 -> V_65 <= V_163 )
break;
}
if ( V_77 . V_78 ) {
F_76 ( & V_77 ) ;
}
V_164:
F_48 ( & V_4 -> V_145 ) ;
return V_80 ;
}
static int F_144 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
unsigned long V_165 = 0 ;
unsigned long V_166 ;
int V_80 ;
int V_25 ;
int V_167 = 256 ;
struct V_38 * V_168 ;
struct V_38 * V_169 ;
unsigned int V_66 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
V_169 = V_168 = V_39 ;
if ( F_145 ( V_64 ) )
V_167 = 1024 ;
for ( V_25 = 0 ; V_25 < 256 && V_165 < V_167 ; V_25 ++ ) {
if ( F_87 ( & V_168 -> V_105 ) ||
V_168 -> V_65 < V_39 -> V_65 ) {
break;
}
V_166 = F_87 ( & V_168 -> V_147 ) ;
if ( V_166 > 0 ) {
V_168 -> V_149 &= ~ V_155 ;
}
V_165 += V_166 ;
V_169 = V_168 ;
if ( V_168 -> V_103 . V_20 == & V_4 -> V_67 )
break;
V_168 = F_55 ( V_168 -> V_103 . V_20 ) ;
}
F_49 ( V_39 ) ;
F_49 ( V_169 ) ;
if ( V_169 != V_39 ) {
V_80 = F_143 ( V_64 , V_39 , & V_168 , & V_66 , V_165 , V_25 ) ;
}
F_132 ( V_64 , V_169 , 1 ) ;
F_50 ( V_64 , V_169 ) ;
F_50 ( V_64 , V_39 ) ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 ,
struct V_7 * * V_50 ,
struct V_38 * V_39 ,
unsigned long V_27 , int V_170 )
{
struct V_7 * V_171 ;
struct V_7 * * V_44 ;
V_44 = & ( F_38 ( V_50 , V_2 , V_27 ) ) ;
if ( ! V_44 ) {
return;
}
V_171 = * V_44 ;
while ( V_171 ) {
if ( V_171 -> V_52 == V_27 && V_171 -> V_2 == V_2
&& ( V_39 == NULL || V_39 == V_171 -> V_122 )
&& ( ! F_41 ( V_172 , & V_171 -> V_126 ) || V_170 ) ) {
if ( V_171 -> V_53 ) {
V_171 -> V_53 -> V_61 = V_171 -> V_61 ;
}
if ( V_171 -> V_61 ) {
V_171 -> V_61 -> V_53 = V_171 -> V_53 ;
} else {
* V_44 = V_171 -> V_53 ;
}
V_171 -> V_52 = 0 ;
V_171 -> V_2 = NULL ;
V_171 -> V_126 = 0 ;
if ( V_171 -> V_9 && V_171 -> V_122 )
F_88 ( & V_171 -> V_122 -> V_147 ) ;
V_171 -> V_9 = NULL ;
V_171 -> V_122 = NULL ;
}
V_171 = V_171 -> V_53 ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 -> V_89 ) ;
V_4 -> V_153 -- ;
F_23 ( V_4 -> V_173 ) ;
F_22 ( V_2 , V_4 -> V_42 ) ;
F_24 ( V_2 ) ;
if ( V_4 -> V_130 ) {
F_147 ( V_4 -> V_130 ) ;
}
F_148 ( V_2 , V_4 ) ;
F_23 ( V_4 ) ;
}
static int F_149 ( struct V_174 * V_175 ,
struct V_1 * V_2 , int error )
{
struct V_174 V_176 ;
int V_177 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! error && ! ( V_2 -> V_178 & V_179 ) ) {
F_80 ( ! V_175 -> V_180 ) ;
F_150 ( V_175 , V_181 ) ;
if ( ! F_151 ( & V_176 , V_2 ) ) {
F_152 ( V_2 ,
F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_176 , F_153 ( V_2 ) ) ;
F_150 ( & V_176 , V_181 ) ;
V_177 = 1 ;
}
}
if ( ! error && F_117 ( V_4 ) ) {
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
if ( ! F_155 ( & V_176 , V_2 ) ) {
F_152 ( V_2 ,
F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_176 , F_153 ( V_2 ) ) ;
F_150 ( & V_176 , V_181 ) ;
}
}
F_156 ( V_2 ) ;
F_157 ( & F_158 ( V_2 ) -> V_182 ) ;
F_157 ( & F_2 ( V_2 ) -> V_183 ) ;
F_146 ( V_2 ) ;
F_159 ( V_2 ) ;
return 0 ;
}
int F_160 ( struct V_174 * V_175 ,
struct V_1 * V_2 )
{
return F_149 ( V_175 , V_2 , 0 ) ;
}
int F_161 ( struct V_174 * V_175 ,
struct V_1 * V_2 )
{
return F_149 ( V_175 , V_2 , 1 ) ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_184 * V_185 ,
struct V_186 * V_187 )
{
if ( F_163 ( V_187 ) != F_164 ( V_185 ) ||
F_165 ( V_187 ) != F_166 ( V_185 ) ||
F_165 ( V_187 ) > F_2 ( V_2 ) -> V_146 ||
F_165 ( V_187 ) <= 0 ) {
return 1 ;
}
return 0 ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_8 * V_188 ,
unsigned int * V_189 ,
unsigned long * V_190 )
{
struct V_184 * V_185 ;
struct V_186 * V_187 ;
struct V_8 * V_191 ;
unsigned long V_127 ;
if ( ! V_188 )
return 0 ;
V_185 = (struct V_184 * ) V_188 -> V_132 ;
if ( F_166 ( V_185 ) > 0
&& ! memcmp ( F_168 ( V_188 ) , V_192 , 8 ) ) {
if ( V_189 && * V_189
&& F_164 ( V_185 ) > * V_189 ) {
F_169 ( V_2 , V_193 ,
L_44
L_45
L_46 ,
F_164 ( V_185 ) ,
* V_189 ) ;
return 0 ;
}
if ( V_190
&& * V_190 > F_170 ( V_185 ) ) {
F_169 ( V_2 , V_193 ,
L_47
L_48
L_49 ,
F_170 ( V_185 ) ,
* V_190 ) ;
return - 1 ;
}
if ( F_166 ( V_185 ) > F_2 ( V_2 ) -> V_146 ) {
F_27 ( V_2 , L_50 ,
L_51
L_52 ,
F_166 ( V_185 ) ) ;
return - 1 ;
}
V_127 = V_188 -> V_72 - F_110 ( V_2 ) ;
V_191 =
F_171 ( V_2 ,
F_110 ( V_2 ) +
( ( V_127 + F_166 ( V_185 ) +
1 ) % F_111 ( V_2 ) ) ) ;
if ( ! V_191 )
return 0 ;
V_187 = (struct V_186 * ) V_191 -> V_132 ;
if ( F_162 ( V_2 , V_185 , V_187 ) ) {
F_169 ( V_2 , V_193 ,
L_53
L_54 ,
V_191 -> V_72 -
F_110 ( V_2 ) ,
F_163 ( V_187 ) ,
F_165 ( V_187 ) ) ;
F_147 ( V_191 ) ;
if ( V_189 ) {
* V_189 =
F_164 ( V_185 ) ;
F_169 ( V_2 , V_193 ,
L_55
L_56
L_57 ,
F_164 ( V_185 ) ) ;
}
return - 1 ;
}
F_147 ( V_191 ) ;
F_169 ( V_2 , V_193 ,
L_58
L_59 ,
V_188 -> V_72 -
F_110 ( V_2 ) ,
F_166 ( V_185 ) ,
F_164 ( V_185 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static void F_172 ( struct V_8 * * V_194 , int V_195 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_195 ; V_25 ++ ) {
F_147 ( V_194 [ V_25 ] ) ;
}
}
static int F_173 ( struct V_1 * V_2 ,
unsigned long V_196 ,
unsigned long V_197 ,
unsigned int V_198 ,
unsigned long V_190 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
unsigned int V_66 = 0 ;
struct V_8 * V_191 ;
struct V_8 * V_188 ;
struct V_8 * * V_199 = NULL ;
struct V_8 * * V_200 = NULL ;
unsigned int V_201 ;
int V_25 ;
int V_202 ;
V_188 = F_171 ( V_2 , V_196 ) ;
if ( ! V_188 )
return 1 ;
V_185 = (struct V_184 * ) V_188 -> V_132 ;
V_201 = V_188 -> V_72 - F_110 ( V_2 ) ;
F_169 ( V_2 , V_193 , L_60
L_61 ,
V_188 -> V_72 - F_110 ( V_2 ) ,
F_166 ( V_185 ) , F_170 ( V_185 ) ) ;
if ( F_164 ( V_185 ) < V_198 ) {
F_169 ( V_2 , V_193 , L_62
L_63 ,
V_196 -
F_110 ( V_2 ) ) ;
F_147 ( V_188 ) ;
return 1 ;
}
if ( F_170 ( V_185 ) != V_190 ) {
F_169 ( V_2 , V_193 , L_64
L_65
L_49 , F_170 ( V_185 ) ,
V_190 ) ;
F_147 ( V_188 ) ;
return 1 ;
}
V_191 = F_171 ( V_2 , F_110 ( V_2 ) +
( ( V_201 + F_166 ( V_185 ) + 1 ) %
F_111 ( V_2 ) ) ) ;
if ( ! V_191 ) {
F_147 ( V_188 ) ;
return 1 ;
}
V_187 = (struct V_186 * ) V_191 -> V_132 ;
if ( F_162 ( V_2 , V_185 , V_187 ) ) {
F_169 ( V_2 , V_193 ,
L_66
L_67 ,
V_191 -> V_72 -
F_110 ( V_2 ) ,
F_163 ( V_187 ) ,
F_165 ( V_187 ) ) ;
F_147 ( V_191 ) ;
F_147 ( V_188 ) ;
return 1 ;
}
if ( F_174 ( V_2 -> V_203 ) ) {
F_27 ( V_2 , L_68 ,
L_69 ) ;
F_147 ( V_191 ) ;
F_147 ( V_188 ) ;
return - V_204 ;
}
V_66 = F_164 ( V_185 ) ;
V_199 = F_7 ( F_166 ( V_185 ) *
sizeof( struct V_8 * ) , V_13 ) ;
V_200 = F_7 ( F_166 ( V_185 ) *
sizeof( struct V_8 * ) , V_13 ) ;
if ( ! V_199 || ! V_200 ) {
F_147 ( V_191 ) ;
F_147 ( V_188 ) ;
F_9 ( V_199 ) ;
F_9 ( V_200 ) ;
F_27 ( V_2 , L_70 ,
L_71 ) ;
return - 1 ;
}
V_202 = F_175 ( V_2 -> V_15 ) ;
for ( V_25 = 0 ; V_25 < F_166 ( V_185 ) ; V_25 ++ ) {
V_199 [ V_25 ] =
F_176 ( V_2 ,
F_110 ( V_2 ) +
( V_201 + 1 +
V_25 ) % F_111 ( V_2 ) ) ;
if ( V_25 < V_202 ) {
V_200 [ V_25 ] =
F_177 ( V_2 ,
F_178 ( V_185 -> V_125 [ V_25 ] ) ) ;
} else {
V_200 [ V_25 ] =
F_177 ( V_2 ,
F_178 ( V_187 ->
V_125 [ V_25 - V_202 ] ) ) ;
}
if ( V_200 [ V_25 ] -> V_72 > F_179 ( V_2 ) ) {
F_27 ( V_2 , L_72 ,
L_73
L_74
L_75 ) ;
goto V_205;
}
if ( F_180
( V_2 , V_200 [ V_25 ] -> V_72 ) ) {
F_27 ( V_2 , L_76 ,
L_73
L_77 ) ;
V_205:
F_172 ( V_199 , V_25 ) ;
F_172 ( V_200 , V_25 ) ;
F_147 ( V_191 ) ;
F_147 ( V_188 ) ;
F_9 ( V_199 ) ;
F_9 ( V_200 ) ;
return - 1 ;
}
}
F_103 ( V_206 , F_166 ( V_185 ) , V_199 ) ;
for ( V_25 = 0 ; V_25 < F_166 ( V_185 ) ; V_25 ++ ) {
F_98 ( V_199 [ V_25 ] ) ;
if ( ! F_73 ( V_199 [ V_25 ] ) ) {
F_27 ( V_2 , L_78 ,
L_73
L_12 ) ;
F_172 ( V_199 + V_25 ,
F_166 ( V_185 ) - V_25 ) ;
F_172 ( V_200 , F_166 ( V_185 ) ) ;
F_147 ( V_191 ) ;
F_147 ( V_188 ) ;
F_9 ( V_199 ) ;
F_9 ( V_200 ) ;
return - 1 ;
}
memcpy ( V_200 [ V_25 ] -> V_132 , V_199 [ V_25 ] -> V_132 ,
V_200 [ V_25 ] -> V_207 ) ;
F_65 ( V_200 [ V_25 ] ) ;
F_147 ( V_199 [ V_25 ] ) ;
}
for ( V_25 = 0 ; V_25 < F_166 ( V_185 ) ; V_25 ++ ) {
F_129 ( V_200 [ V_25 ] ) ;
F_181 ( V_200 [ V_25 ] , V_75 ) ;
}
for ( V_25 = 0 ; V_25 < F_166 ( V_185 ) ; V_25 ++ ) {
F_98 ( V_200 [ V_25 ] ) ;
if ( ! F_73 ( V_200 [ V_25 ] ) ) {
F_27 ( V_2 , L_79 ,
L_80
L_12 ) ;
F_172 ( V_200 + V_25 ,
F_166 ( V_185 ) - V_25 ) ;
F_147 ( V_191 ) ;
F_147 ( V_188 ) ;
F_9 ( V_199 ) ;
F_9 ( V_200 ) ;
return - 1 ;
}
F_147 ( V_200 [ V_25 ] ) ;
}
V_196 =
F_110 ( V_2 ) +
( ( V_201 + F_166 ( V_185 ) +
2 ) % F_111 ( V_2 ) ) ;
F_169 ( V_2 , V_193 ,
L_81 L_82 ,
V_196 - F_110 ( V_2 ) ) ;
V_4 -> V_117 = V_196 - F_110 ( V_2 ) ;
V_4 -> V_129 = V_66 ;
V_4 -> V_65 = V_66 + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
F_147 ( V_191 ) ;
F_147 ( V_188 ) ;
F_9 ( V_199 ) ;
F_9 ( V_200 ) ;
return 0 ;
}
static struct V_8 * F_182 ( struct V_208 * V_209 ,
T_1 V_27 , int V_210 ,
T_1 V_211 )
{
struct V_8 * V_212 [ V_213 ] ;
unsigned int V_214 = V_213 ;
struct V_8 * V_9 ;
int V_25 , V_40 ;
V_9 = F_183 ( V_209 , V_27 , V_210 ) ;
if ( F_73 ( V_9 ) )
return ( V_9 ) ;
if ( V_27 + V_213 > V_211 ) {
V_214 = V_211 - V_27 ;
}
V_212 [ 0 ] = V_9 ;
V_40 = 1 ;
for ( V_25 = 1 ; V_25 < V_214 ; V_25 ++ ) {
V_9 = F_183 ( V_209 , V_27 + V_25 , V_210 ) ;
if ( F_73 ( V_9 ) ) {
F_147 ( V_9 ) ;
break;
} else
V_212 [ V_40 ++ ] = V_9 ;
}
F_103 ( V_206 , V_40 , V_212 ) ;
for ( V_25 = 1 ; V_25 < V_40 ; V_25 ++ )
F_147 ( V_212 [ V_25 ] ) ;
V_9 = V_212 [ 0 ] ;
F_98 ( V_9 ) ;
if ( F_73 ( V_9 ) )
return V_9 ;
F_147 ( V_9 ) ;
return NULL ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_184 * V_185 ;
unsigned int V_198 = 0 ;
unsigned int V_189 = 0 ;
T_3 V_215 ;
unsigned long V_197 = 0 ;
unsigned long V_196 = 0 ;
unsigned long V_190 = 9 ;
struct V_8 * V_188 ;
struct V_128 * V_83 ;
int V_216 = 0 ;
int V_217 = 0 ;
int V_218 = 1 ;
int V_80 ;
V_196 = F_110 ( V_2 ) ;
F_185 ( V_2 , L_83 ,
V_4 -> V_219 ) ;
V_215 = F_186 () ;
V_4 -> V_130 = F_171 ( V_2 ,
F_110 ( V_2 )
+ F_111 ( V_2 ) ) ;
if ( ! V_4 -> V_130 ) {
return 1 ;
}
V_83 = (struct V_128 * ) ( V_4 -> V_130 -> V_132 ) ;
if ( F_178 ( V_83 -> V_131 ) <
F_111 ( V_2 )
&& F_178 ( V_83 -> V_129 ) > 0 ) {
V_197 =
F_110 ( V_2 ) +
F_178 ( V_83 -> V_131 ) ;
V_198 = F_178 ( V_83 -> V_129 ) + 1 ;
V_190 = F_178 ( V_83 -> V_133 ) ;
F_169 ( V_2 , V_193 ,
L_84
L_85
L_86 , F_178 ( V_83 -> V_131 ) ,
F_178 ( V_83 -> V_129 ) ) ;
V_216 = 1 ;
V_188 =
F_171 ( V_2 ,
F_110 ( V_2 ) +
F_178 ( V_83 -> V_131 ) ) ;
V_80 = F_167 ( V_2 , V_188 , NULL , NULL ) ;
if ( ! V_80 ) {
V_218 = 0 ;
}
F_147 ( V_188 ) ;
goto V_220;
}
while ( V_218
&& V_196 <
( F_110 ( V_2 ) +
F_111 ( V_2 ) ) ) {
V_188 =
F_182 ( V_4 -> V_219 , V_196 ,
V_2 -> V_15 ,
F_110 ( V_2 ) +
F_111 ( V_2 ) ) ;
V_80 =
F_167 ( V_2 , V_188 ,
& V_189 ,
& V_190 ) ;
if ( V_80 == 1 ) {
V_185 = (struct V_184 * ) V_188 -> V_132 ;
if ( V_197 == 0 ) {
V_198 = F_164 ( V_185 ) ;
V_197 = V_188 -> V_72 ;
V_190 = F_170 ( V_185 ) ;
F_169 ( V_2 , V_193 ,
L_87
L_88 ,
V_197 -
F_110
( V_2 ) , V_198 ) ;
} else if ( V_198 > F_164 ( V_185 ) ) {
V_198 = F_164 ( V_185 ) ;
V_197 = V_188 -> V_72 ;
F_169 ( V_2 , V_193 ,
L_89
L_90 ,
V_197 -
F_110
( V_2 ) , V_198 ) ;
}
if ( V_190 < F_170 ( V_185 ) ) {
V_190 = F_170 ( V_185 ) ;
F_169 ( V_2 , V_193 ,
L_91
L_92 ,
F_170 ( V_185 ) ) ;
}
V_196 += F_166 ( V_185 ) + 2 ;
} else {
V_196 ++ ;
}
F_147 ( V_188 ) ;
}
V_220:
V_196 = V_197 ;
if ( V_198 ) {
F_169 ( V_2 , V_193 ,
L_93
L_94 ,
V_196 - F_110 ( V_2 ) ,
V_198 ) ;
}
V_217 = 0 ;
while ( V_218 && V_198 > 0 ) {
V_80 =
F_173 ( V_2 , V_196 , V_197 ,
V_198 , V_190 ) ;
if ( V_80 < 0 ) {
return V_80 ;
} else if ( V_80 != 0 ) {
break;
}
V_196 =
F_110 ( V_2 ) + V_4 -> V_117 ;
V_217 ++ ;
if ( V_196 == V_197 )
break;
}
if ( V_198 == 0 ) {
F_169 ( V_2 , V_193 ,
L_95 L_96 ) ;
}
if ( V_216 && V_217 == 0 ) {
V_4 -> V_117 = F_178 ( V_83 -> V_131 ) ;
V_4 -> V_65 =
F_178 ( V_83 -> V_129 ) + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_129 =
F_178 ( V_83 -> V_129 ) ;
V_4 -> V_133 = F_178 ( V_83 -> V_133 ) + 1 ;
} else {
V_4 -> V_133 = V_190 + 1 ;
}
F_169 ( V_2 , V_193 , L_91
L_97 , V_4 -> V_133 ) ;
V_4 -> V_131 = V_4 -> V_117 ;
if ( V_217 > 0 ) {
F_185 ( V_2 ,
L_98 ,
V_217 , F_186 () - V_215 ) ;
}
F_159 ( V_2 ) ;
if ( ! F_174 ( V_2 -> V_203 ) &&
F_127 ( V_2 , V_4 -> V_117 ,
V_4 -> V_129 ) ) {
F_156 ( V_2 ) ;
return - 1 ;
}
F_156 ( V_2 ) ;
return 0 ;
}
static struct V_38 * F_187 ( struct V_1 * V_64 )
{
struct V_38 * V_39 ;
V_39 = F_8 ( sizeof( struct V_38 ) ,
V_13 | V_221 ) ;
F_10 ( & V_39 -> V_103 ) ;
F_10 ( & V_39 -> V_135 ) ;
F_10 ( & V_39 -> V_90 ) ;
F_10 ( & V_39 -> V_91 ) ;
F_188 ( & V_39 -> V_116 ) ;
F_2 ( V_64 ) -> V_153 ++ ;
F_49 ( V_39 ) ;
return V_39 ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) -> V_89 = F_187 ( V_2 ) ;
}
static void F_148 ( struct V_1 * V_222 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_219 != NULL ) {
F_190 ( V_4 -> V_219 , V_4 -> V_223 ) ;
V_4 -> V_219 = NULL ;
}
}
static int F_191 ( struct V_1 * V_222 ,
struct V_3 * V_4 ,
const char * V_224 )
{
int V_225 ;
T_4 V_226 ;
T_5 V_227 = V_228 | V_229 | V_230 ;
char V_231 [ V_232 ] ;
V_225 = 0 ;
V_4 -> V_219 = NULL ;
V_226 = F_192 ( V_222 ) ?
F_193 ( F_192 ( V_222 ) ) : V_222 -> V_233 ;
if ( F_174 ( V_222 -> V_203 ) )
V_227 = V_228 ;
if ( ( ! V_224 || ! V_224 [ 0 ] ) ) {
if ( V_226 == V_222 -> V_233 )
V_227 &= ~ V_230 ;
V_4 -> V_219 = F_194 ( V_226 , V_227 ,
V_4 ) ;
V_4 -> V_223 = V_227 ;
if ( F_195 ( V_4 -> V_219 ) ) {
V_225 = F_196 ( V_4 -> V_219 ) ;
V_4 -> V_219 = NULL ;
F_27 ( V_222 , L_99 ,
L_100 ,
F_197 ( V_226 , V_231 ) , V_225 ) ;
return V_225 ;
} else if ( V_226 != V_222 -> V_233 )
F_198 ( V_4 -> V_219 , V_222 -> V_15 ) ;
return 0 ;
}
V_4 -> V_223 = V_227 ;
V_4 -> V_219 = F_199 ( V_224 , V_227 , V_4 ) ;
if ( F_195 ( V_4 -> V_219 ) ) {
V_225 = F_196 ( V_4 -> V_219 ) ;
V_4 -> V_219 = NULL ;
F_27 ( V_222 ,
L_101 ,
V_224 , V_225 ) ;
return V_225 ;
}
F_198 ( V_4 -> V_219 , V_222 -> V_15 ) ;
F_185 ( V_222 ,
L_102 ,
V_4 -> V_219 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_146 ) {
int V_234 = 1 ;
if ( V_2 -> V_15 < V_235 )
V_234 = V_235 / V_2 -> V_15 ;
if ( V_4 -> V_146 > V_236 / V_234 ||
V_4 -> V_146 < V_237 / V_234 ||
F_111 ( V_2 ) / V_4 -> V_146 <
V_238 ) {
F_27 ( V_2 , L_103 ,
L_104
L_105 , V_4 -> V_146 ) ;
return 1 ;
}
if ( V_4 -> V_239 != ( V_4 -> V_146 ) *
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
V_4 -> V_146 = V_236 ;
V_4 -> V_239 = V_240 ;
V_4 -> V_241 = V_242 ;
}
return 0 ;
}
int F_201 ( struct V_1 * V_2 , const char * V_243 ,
int V_244 , unsigned int V_245 )
{
int V_43 = F_111 ( V_2 ) * 2 ;
struct V_8 * V_246 ;
struct V_247 * V_248 ;
struct V_128 * V_83 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
int V_80 ;
V_4 = F_2 ( V_2 ) = F_26 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 ) {
F_27 ( V_2 , L_110 ,
L_111 ) ;
return 1 ;
}
F_10 ( & V_4 -> V_19 ) ;
F_10 ( & V_4 -> V_249 ) ;
F_10 ( & V_4 -> V_135 ) ;
F_10 ( & V_4 -> V_67 ) ;
V_4 -> V_250 = 0 ;
if ( F_25 ( V_2 , V_4 -> V_42 ,
F_21 ( V_2 ) ) )
goto V_251;
F_17 ( V_2 ) ;
F_202 ( V_2 ) = ( V_244 ?
V_252
/ V_2 -> V_15 +
F_21 ( V_2 ) +
1 :
V_253 /
V_2 -> V_15 + 2 ) ;
if ( ! F_192 ( V_2 ) &&
( F_202 ( V_2 ) +
F_111 ( V_2 ) > V_2 -> V_15 * 8 ) ) {
F_27 ( V_2 , L_112 ,
L_113
L_114
L_115 ,
F_202 ( V_2 ) ,
F_111 ( V_2 ) ,
V_2 -> V_15 ) ;
goto V_251;
}
if ( F_191 ( V_2 , V_4 , V_243 ) != 0 ) {
F_27 ( V_2 , L_103 ,
L_116 ) ;
goto V_251;
}
V_248 = F_203 ( V_2 ) ;
V_246 = F_171 ( V_2 ,
F_110 ( V_2 ) +
F_111 ( V_2 ) ) ;
if ( ! V_246 ) {
F_27 ( V_2 , L_117 ,
L_118 ) ;
goto V_251;
}
V_83 = (struct V_128 * ) ( V_246 -> V_132 ) ;
if ( F_204 ( V_248 )
&& ( F_178 ( V_83 -> V_254 . V_255 ) !=
F_205 ( V_248 ) ) ) {
F_27 ( V_2 , L_119 ,
L_120
L_121 ,
V_83 -> V_254 . V_255 ,
V_4 -> V_219 ,
F_205 ( V_248 ) ) ;
F_147 ( V_246 ) ;
goto V_251;
}
V_4 -> V_146 = F_178 ( V_83 -> V_254 . V_256 ) ;
V_4 -> V_239 = F_178 ( V_83 -> V_254 . V_257 ) ;
V_4 -> V_241 =
F_178 ( V_83 -> V_254 . V_258 ) ;
V_4 -> V_259 = V_260 ;
if ( F_200 ( V_2 , V_4 ) != 0 )
goto V_251;
V_4 -> V_261 = V_4 -> V_241 ;
if ( V_245 != 0 ) {
V_4 -> V_241 = V_245 ;
V_4 -> V_259 = V_245 ;
}
F_185 ( V_2 , L_122
L_123
L_124 ,
V_4 -> V_219 ,
F_111 ( V_2 ) ,
F_110 ( V_2 ) ,
V_4 -> V_146 ,
V_4 -> V_239 ,
V_4 -> V_241 , V_4 -> V_259 ) ;
F_147 ( V_246 ) ;
V_4 -> V_41 = 0 ;
F_189 ( V_2 ) ;
memset ( V_4 -> V_58 , 0 ,
V_6 * sizeof( struct V_7 * ) ) ;
F_10 ( & V_4 -> V_262 ) ;
F_206 ( & V_4 -> V_87 ) ;
V_4 -> V_117 = 0 ;
V_4 -> V_114 = 0 ;
V_4 -> V_263 = 0 ;
F_109 ( & V_4 -> V_144 , 0 ) ;
F_109 ( & V_4 -> V_106 , 0 ) ;
V_4 -> V_264 = 0 ;
V_4 -> V_265 = 0 ;
V_4 -> V_266 = NULL ;
V_4 -> V_267 = NULL ;
F_207 ( & V_4 -> V_268 ) ;
F_188 ( & V_4 -> V_62 ) ;
F_188 ( & V_4 -> V_145 ) ;
V_4 -> V_65 = 10 ;
V_4 -> V_133 = 10 ;
V_4 -> V_149 = 0 ;
F_109 ( & V_4 -> V_269 , 0 ) ;
V_4 -> V_49 = F_30 ( V_43 ) ;
V_4 -> V_173 = V_4 -> V_49 ;
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
V_39 = V_4 -> V_89 ;
F_159 ( V_2 ) ;
V_39 -> V_42 = F_28 ( V_2 , V_39 ) ;
F_156 ( V_2 ) ;
if ( ! V_39 -> V_42 ) {
F_27 ( V_2 , L_130 ,
L_131 ) ;
goto V_251;
}
V_80 = F_184 ( V_2 ) ;
if ( V_80 < 0 ) {
F_27 ( V_2 , L_132 ,
L_133 ) ;
goto V_251;
}
F_208 ( & V_4 -> V_183 , V_271 ) ;
V_4 -> V_272 = V_2 ;
return 0 ;
V_251:
F_146 ( V_2 ) ;
return 1 ;
}
int F_209 ( struct V_174 * V_175 ,
int V_273 )
{
struct V_3 * V_4 = F_2 ( V_175 -> V_274 ) ;
T_3 V_275 = F_186 () ;
F_80 ( ! V_175 -> V_180 ) ;
if ( V_175 -> V_276 > 1 )
return 0 ;
if ( V_4 -> V_270 > 0 ||
( V_4 -> V_263 + V_273 ) >= V_4 -> V_239 ||
F_87 ( & V_4 -> V_269 ) ||
( V_275 - V_4 -> V_265 ) > V_4 -> V_259 ||
V_4 -> V_47 < ( V_4 -> V_146 * 3 ) ) {
return 1 ;
}
V_4 -> V_263 += V_273 ;
V_175 -> V_277 += V_273 ;
return 0 ;
}
void F_210 ( struct V_174 * V_175 )
{
struct V_3 * V_4 = F_2 ( V_175 -> V_274 ) ;
F_80 ( ! V_175 -> V_180 ) ;
V_4 -> V_270 = 1 ;
F_19 ( V_278 , & V_4 -> V_149 ) ;
return;
}
void F_211 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_212 ( V_278 , & V_4 -> V_149 ) ;
F_213 ( & V_4 -> V_268 ) ;
}
void F_214 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_215 ( V_4 -> V_268 ,
! F_41 ( V_278 , & V_4 -> V_149 ) ) ;
}
static void F_216 ( struct V_1 * V_64 )
{
T_6 V_279 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_19 ( V_280 , & V_4 -> V_149 ) ;
F_217 ( & V_279 , V_281 ) ;
F_218 ( & V_4 -> V_268 , & V_279 ) ;
F_219 ( V_282 ) ;
if ( F_41 ( V_280 , & V_4 -> V_149 ) ) {
int V_107 = F_106 ( V_64 ) ;
F_220 () ;
F_108 ( V_64 , V_107 ) ;
}
F_221 ( V_283 ) ;
F_222 ( & V_4 -> V_268 , & V_279 ) ;
}
static void F_223 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
if ( F_224 ( V_280 , & V_4 -> V_149 ) )
F_213 ( & V_4 -> V_268 ) ;
}
static void F_225 ( struct V_1 * V_2 , unsigned int V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_284 = V_4 -> V_264 ;
while ( 1 ) {
int V_107 ;
V_107 = F_106 ( V_2 ) ;
F_226 ( 1 ) ;
F_108 ( V_2 , V_107 ) ;
V_4 -> V_89 -> V_149 |= V_285 ;
while ( ( F_87 ( & V_4 -> V_144 ) > 0 ||
F_87 ( & V_4 -> V_269 ) ) &&
V_4 -> V_65 == V_66 ) {
F_216 ( V_2 ) ;
}
if ( V_4 -> V_65 != V_66 )
break;
if ( V_284 == V_4 -> V_264 )
break;
V_284 = V_4 -> V_264 ;
}
}
static int F_227 ( struct V_174 * V_175 ,
struct V_1 * V_2 , unsigned long V_286 ,
int V_287 )
{
T_3 V_275 = F_186 () ;
unsigned int V_288 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_174 V_176 ;
int V_289 = 0 ;
int V_112 ;
int V_107 ;
F_32 ( V_2 , L_134 ) ;
F_80 ( V_286 > V_4 -> V_146 ) ;
F_40 ( V_2 , V_4 . V_290 ) ;
V_175 -> V_276 = 1 ;
V_175 -> V_274 = V_2 ;
V_291:
F_45 ( V_2 ) ;
if ( V_287 != V_292 && F_117 ( V_4 ) ) {
F_47 ( V_2 ) ;
V_112 = V_4 -> V_94 ;
goto V_293;
}
V_4 -> V_264 ++ ;
if ( F_41 ( V_278 , & V_4 -> V_149 ) ) {
F_47 ( V_2 ) ;
V_107 = F_106 ( V_2 ) ;
F_214 ( V_2 ) ;
F_108 ( V_2 , V_107 ) ;
F_40 ( V_2 , V_4 . V_294 ) ;
goto V_291;
}
V_275 = F_186 () ;
if ( ( ! V_287 && V_4 -> V_270 > 0 ) ||
( ! V_287
&& ( V_4 -> V_263 + V_286 + 2 ) >= V_4 -> V_239 )
|| ( ! V_287 && F_87 ( & V_4 -> V_144 ) > 0
&& V_4 -> V_265 > 0
&& ( V_275 - V_4 -> V_265 ) >
V_4 -> V_259 ) || ( ! V_287
&& F_87 ( & V_4 -> V_269 ) )
|| ( ! V_287 && V_4 -> V_47 < ( V_4 -> V_146 * 3 ) ) ) {
V_288 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
if ( ! V_287 && ( V_4 -> V_263 + V_286 + 2 ) >=
V_4 -> V_239 &&
( ( V_4 -> V_114 + V_286 + 2 ) * 100 ) <
( V_4 -> V_263 * 75 ) ) {
if ( F_87 ( & V_4 -> V_144 ) > 10 ) {
V_289 ++ ;
F_216 ( V_2 ) ;
goto V_291;
}
}
if ( F_87 ( & V_4 -> V_269 ) ) {
while ( V_4 -> V_65 == V_288 &&
F_87 ( & V_4 -> V_269 ) ) {
F_216 ( V_2 ) ;
}
goto V_291;
}
V_112 = F_151 ( & V_176 , V_2 ) ;
if ( V_112 )
goto V_293;
if ( V_288 != V_4 -> V_65 ) {
V_112 = F_150 ( & V_176 , 0 ) ;
} else {
V_112 = F_150 ( & V_176 , V_295 ) ;
}
if ( V_112 )
goto V_293;
F_40 ( V_2 , V_4 . V_296 ) ;
goto V_291;
}
if ( V_4 -> V_265 == 0 ) {
V_4 -> V_265 = F_186 () ;
}
F_84 ( & V_4 -> V_144 ) ;
V_4 -> V_263 += V_286 ;
V_175 -> V_297 = 0 ;
V_175 -> V_277 = V_286 ;
V_175 -> V_180 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
F_10 ( & V_175 -> V_298 ) ;
return 0 ;
V_293:
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_274 = V_2 ;
return V_112 ;
}
struct V_174 * F_228 ( struct
V_1
* V_64 ,
int V_286 )
{
int V_80 ;
struct V_174 * V_175 ;
if ( F_229 ( V_64 ) ) {
V_175 = V_281 -> V_299 ;
V_175 -> V_276 ++ ;
F_80 ( V_175 -> V_276 < 2 ) ;
return V_175 ;
}
V_175 = F_7 ( sizeof( struct V_174 ) , V_13 ) ;
if ( ! V_175 )
return NULL ;
V_80 = F_230 ( V_175 , V_64 , V_286 ) ;
if ( V_80 ) {
F_9 ( V_175 ) ;
return NULL ;
}
F_2 ( V_64 ) -> V_250 ++ ;
return V_175 ;
}
int F_231 ( struct V_174 * V_175 )
{
struct V_1 * V_64 = V_175 -> V_274 ;
int V_80 = 0 ;
if ( V_175 -> V_180 )
V_80 = F_232 ( V_175 ) ;
else
V_80 = - V_97 ;
if ( V_175 -> V_276 == 0 ) {
F_2 ( V_64 ) -> V_250 -- ;
F_9 ( V_175 ) ;
}
return V_80 ;
}
static int F_151 ( struct V_174 * V_175 ,
struct V_1 * V_2 )
{
struct V_174 * V_300 = V_281 -> V_299 ;
V_175 -> V_301 = V_300 ;
F_80 ( V_300 && V_300 -> V_276 > 1 ) ;
return F_227 ( V_175 , V_2 , 1 , V_302 ) ;
}
int F_155 ( struct V_174 * V_175 ,
struct V_1 * V_2 )
{
struct V_174 * V_300 = V_281 -> V_299 ;
V_175 -> V_301 = V_300 ;
F_80 ( V_300 && V_300 -> V_276 > 1 ) ;
return F_227 ( V_175 , V_2 , 1 , V_292 ) ;
}
int F_230 ( struct V_174 * V_175 ,
struct V_1 * V_2 , unsigned long V_286 )
{
struct V_174 * V_300 = V_281 -> V_299 ;
int V_80 ;
V_175 -> V_301 = NULL ;
if ( V_300 ) {
if ( V_300 -> V_274 == V_2 ) {
F_80 ( ! V_300 -> V_276 ) ;
V_300 -> V_276 ++ ;
memcpy ( V_175 , V_300 , sizeof( * V_175 ) ) ;
if ( V_175 -> V_276 <= 1 )
F_27 ( V_2 , L_135 ,
L_136
L_137 ) ;
return 0 ;
} else {
F_27 ( V_2 , L_138 ,
L_139 ) ;
V_175 -> V_301 = V_281 -> V_299 ;
V_281 -> V_299 = V_175 ;
}
} else {
V_281 -> V_299 = V_175 ;
}
V_80 = F_227 ( V_175 , V_2 , V_286 , V_303 ) ;
F_80 ( V_281 -> V_299 != V_175 ) ;
if ( V_80 )
V_281 -> V_299 = V_175 -> V_301 ;
else
F_80 ( ! V_175 -> V_276 ) ;
return V_80 ;
}
int F_154 ( struct V_174 * V_175 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_175 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
int V_304 = 0 ;
int V_305 = 0 ;
F_80 ( ! V_175 -> V_180 ) ;
F_40 ( V_2 , V_4 . V_306 ) ;
if ( V_175 -> V_180 != V_4 -> V_65 ) {
F_51 ( V_175 -> V_274 , L_140 ,
L_141 ,
V_175 -> V_180 , V_4 -> V_65 ) ;
}
V_305 = F_233 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( F_64 ( V_9 ) ) {
F_40 ( V_2 , V_4 . V_307 ) ;
return 0 ;
}
if ( ! V_305 || F_96 ( V_9 ) ) {
F_27 ( V_2 , L_142 ,
L_143
L_144 ,
( unsigned long long ) V_9 -> V_72 ,
V_305 ? ' ' : '!' ,
F_101 ( V_9 ) ? ' ' : '!' ,
F_96 ( V_9 ) ? ' ' : '!' ,
F_135 ( V_9 ) ? ' ' : '!' ) ;
}
if ( F_87 ( & V_4 -> V_144 ) <= 0 ) {
F_27 ( V_2 , L_145 ,
L_146 ,
F_87 ( & V_4 -> V_144 ) ) ;
return 1 ;
}
if ( V_4 -> V_114 >= V_4 -> V_146 ) {
F_51 ( V_175 -> V_274 , L_147 ,
L_148 ,
V_4 -> V_114 ) ;
}
if ( F_135 ( V_9 ) ) {
V_304 = 1 ;
F_40 ( V_2 , V_4 . V_308 ) ;
F_234 ( V_9 ) ;
}
if ( V_4 -> V_114 > V_4 -> V_263 ) {
V_4 -> V_263 = V_4 -> V_114 + V_309 ;
}
F_235 ( V_9 ) ;
if ( ! V_46 ) {
V_46 = F_31 ( V_2 ) ;
if ( ! V_46 ) {
F_51 ( V_2 , L_149 , L_150 ) ;
}
if ( V_175 -> V_297 == V_175 -> V_277 ) {
V_175 -> V_277 += V_309 ;
V_4 -> V_263 += V_309 ;
}
V_175 -> V_297 ++ ;
V_4 -> V_114 ++ ;
V_46 -> V_9 = V_9 ;
V_46 -> V_52 = V_9 -> V_72 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_122 = NULL ;
F_44 ( V_4 -> V_5 , V_46 ) ;
if ( ! V_304 ) {
F_70 ( V_9 ) ;
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
F_236 ( V_2 ) ;
return 0 ;
}
int F_232 ( struct V_174 * V_175 )
{
struct V_1 * V_2 = V_175 -> V_274 ;
if ( ! V_281 -> V_299 && V_175 -> V_276 > 1 )
F_27 ( V_2 , L_151 ,
L_152 , V_175 -> V_276 ) ;
if ( ! V_175 -> V_180 ) {
F_237 ( 1 ) ;
return - V_97 ;
}
V_175 -> V_276 -- ;
if ( V_175 -> V_276 > 0 ) {
struct V_174 * V_300 =
V_281 -> V_299 ;
F_80 ( V_300 -> V_274 != V_175 -> V_274 ) ;
if ( V_175 != V_300 ) {
memcpy ( V_281 -> V_299 , V_175 , sizeof( * V_175 ) ) ;
V_175 -> V_180 = 0 ;
}
return 0 ;
} else {
return F_150 ( V_175 , 0 ) ;
}
}
static int F_238 ( struct V_1 * V_2 ,
T_1 V_52 , int V_310 )
{
struct V_8 * V_9 ;
struct V_7 * V_46 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_80 = 0 ;
V_46 = F_37 ( V_2 , V_4 -> V_5 , V_52 ) ;
if ( ! V_46 || ! V_46 -> V_9 ) {
return V_80 ;
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
F_126 ( V_2 , V_4 -> V_5 , NULL ,
V_9 -> V_72 , 0 ) ;
F_239 ( V_9 ) ;
if ( ! V_310 ) {
F_234 ( V_9 ) ;
F_4 ( V_9 ) ;
F_5 ( V_9 ) ;
F_59 ( V_9 ) ;
if ( F_87 ( & V_9 -> V_152 ) < 0 ) {
F_27 ( V_2 , L_153 ,
L_154 ) ;
}
V_80 = 1 ;
}
V_4 -> V_114 -- ;
V_4 -> V_263 -- ;
F_33 ( V_2 , V_46 ) ;
return V_80 ;
}
static int F_136 ( struct V_7 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
T_1 V_52 = V_46 -> V_52 ;
struct V_7 * V_171 = V_46 -> V_61 ;
int F_136 = 1 ;
while ( V_171 && F_136 ) {
if ( V_171 -> V_122 && V_171 -> V_9 && V_171 -> V_52 && V_171 -> V_2 == V_2 &&
V_171 -> V_52 == V_52 ) {
F_136 = 0 ;
}
V_171 = V_171 -> V_61 ;
}
V_171 = V_46 -> V_53 ;
while ( V_171 && F_136 ) {
if ( V_171 -> V_122 && V_171 -> V_122 -> V_114 > 0 &&
F_87 ( & V_171 -> V_122 -> V_105 ) > 0 && V_171 -> V_9 &&
V_171 -> V_52 && V_171 -> V_2 == V_2 && V_171 -> V_52 == V_52 ) {
F_136 = 0 ;
}
V_171 = V_171 -> V_53 ;
}
return F_136 ;
}
int F_240 ( struct V_174 * V_175 )
{
struct V_1 * V_2 = V_175 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_80 ( ! V_175 -> V_180 ) ;
F_80 ( V_175 -> V_276 > 1 ) ;
if ( V_4 -> V_114 == 0 ) {
F_152 ( V_2 , F_153 ( V_2 ) ,
1 ) ;
F_154 ( V_175 , F_153 ( V_2 ) ) ;
}
return F_150 ( V_175 , V_295 | V_311 ) ;
}
static void V_271 ( struct V_312 * V_313 )
{
struct V_3 * V_4 =
F_241 ( V_313 , struct V_3 , V_183 . V_313 ) ;
struct V_1 * V_2 = V_4 -> V_272 ;
struct V_38 * V_39 ;
struct V_17 * V_18 ;
F_159 ( V_2 ) ;
if ( ! F_54 ( & V_4 -> V_67 ) ) {
V_18 = V_4 -> V_67 . V_45 ;
V_39 = F_55 ( V_18 ) ;
F_29 ( V_2 , V_39 , 1 ) ;
}
F_156 ( V_2 ) ;
}
void F_242 ( struct V_1 * V_2 )
{
T_3 V_275 ;
struct V_174 V_175 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_275 = F_186 () ;
if ( F_54 ( & V_4 -> V_67 ) )
return;
if ( F_87 ( & V_4 -> V_144 ) <= 0 &&
V_4 -> V_265 > 0 &&
V_4 -> V_114 > 0 &&
( V_275 - V_4 -> V_265 ) > V_4 -> V_259 ) {
if ( ! F_151 ( & V_175 , V_2 ) ) {
F_152 ( V_2 ,
F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_175 , F_153 ( V_2 ) ) ;
F_150 ( & V_175 , V_295 | V_311 ) ;
}
}
}
static int F_243 ( struct V_174 * V_175 , int V_314 )
{
T_3 V_275 ;
int V_315 = V_314 & V_181 ;
int V_316 = V_314 & V_295 ;
int V_317 = V_314 & V_311 ;
struct V_38 * V_39 ;
struct V_1 * V_2 = V_175 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_80 ( ! V_175 -> V_180 ) ;
if ( V_175 -> V_180 != V_4 -> V_65 ) {
F_51 ( V_175 -> V_274 , L_140 ,
L_141 ,
V_175 -> V_180 , V_4 -> V_65 ) ;
}
V_4 -> V_263 -= ( V_175 -> V_277 - V_175 -> V_297 ) ;
if ( F_87 ( & V_4 -> V_144 ) > 0 )
F_88 ( & V_4 -> V_144 ) ;
F_80 ( V_4 -> V_114 == 0 ) ;
if ( F_87 ( & V_4 -> V_144 ) > 0 ) {
if ( V_315 || V_316 ) {
unsigned V_66 ;
V_39 = V_4 -> V_89 ;
V_66 = V_39 -> V_65 ;
if ( V_317 )
V_39 -> V_149 |= V_285 ;
F_109 ( & V_4 -> V_269 , 1 ) ;
if ( V_315 ) {
V_4 -> V_318 = 1 ;
}
F_47 ( V_2 ) ;
while ( V_4 -> V_65 == V_66 ) {
if ( F_87 ( & V_4 -> V_269 ) ) {
F_216 ( V_2 ) ;
} else {
F_45 ( V_2 ) ;
if ( V_4 -> V_65 == V_66 ) {
F_109 ( & V_4 -> V_269 ,
1 ) ;
}
F_47 ( V_2 ) ;
}
}
F_80 ( V_4 -> V_65 == V_66 ) ;
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
V_275 = F_186 () ;
if ( ( V_275 - V_4 -> V_265 ) > V_4 -> V_259 ) {
V_316 = 1 ;
V_4 -> V_319 = 1 ;
}
if ( ! ( V_4 -> V_270 > 0 ) && ! ( F_87 ( & V_4 -> V_269 ) )
&& ! V_315 && ! V_316 && ( V_4 -> V_114 < V_4 -> V_239 )
&& V_4 -> V_263 < V_4 -> V_239
&& V_4 -> V_47 > ( V_4 -> V_146 * 3 ) ) {
V_4 -> V_264 ++ ;
F_47 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_117 > F_111 ( V_2 ) ) {
F_51 ( V_2 , L_155 ,
L_156 ,
V_4 -> V_117 ) ;
}
return 1 ;
}
int F_244 ( struct V_174 * V_175 ,
struct V_1 * V_2 , T_1 V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_28 * V_29 = NULL ;
int V_320 = 0 ;
F_80 ( ! V_175 -> V_180 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_5 , V_52 ) ;
if ( V_46 && V_46 -> V_9 ) {
V_9 = V_46 -> V_9 ;
F_70 ( V_9 ) ;
}
if ( V_9 && F_245 ( V_9 ) ) {
F_71 ( V_9 ) ;
F_34 ( V_9 ) ;
F_3 ( V_9 ) ;
V_320 = F_238 ( V_2 , V_52 , V_320 ) ;
} else {
V_29 = V_4 -> V_89 -> V_42 ;
if ( ! V_29 ) {
F_51 ( V_2 , L_157 ,
L_158 ) ;
}
F_18 ( V_2 , V_52 , V_29 ) ;
if ( V_9 ) {
F_34 ( V_9 ) ;
F_3 ( V_9 ) ;
}
V_320 = F_238 ( V_2 , V_52 , V_320 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_58 ,
V_52 ) ;
while ( V_46 ) {
if ( V_2 == V_46 -> V_2 && V_52 == V_46 -> V_52 ) {
F_19 ( V_172 , & V_46 -> V_126 ) ;
if ( V_46 -> V_9 ) {
if ( ! V_320 ) {
F_234 ( V_46 ->
V_9 ) ;
F_4 ( V_46 -> V_9 ) ;
F_5 ( V_46 ->
V_9 ) ;
V_320 = 1 ;
F_59 ( V_46 -> V_9 ) ;
if ( F_87
( & V_46 -> V_9 -> V_152 ) < 0 ) {
F_27 ( V_2 ,
L_159 ,
L_160 ) ;
}
}
if ( V_46 -> V_122 ) {
F_88 ( & V_46 -> V_122 ->
V_147 ) ;
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
void F_246 ( struct V_92 * V_92 )
{
struct V_3 * V_4 = F_2 ( V_92 -> V_93 ) ;
F_247 ( V_92 ) -> V_321 = V_4 -> V_89 ;
F_247 ( V_92 ) -> V_322 = V_4 -> V_65 ;
}
static int F_248 ( struct V_92 * V_92 , unsigned long V_12 ,
struct V_38 * V_39 )
{
struct V_174 V_175 ;
struct V_1 * V_2 = V_92 -> V_93 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_80 = 0 ;
if ( V_12 == V_4 -> V_65 ) {
V_39 = V_4 -> V_89 ;
F_225 ( V_2 , V_12 ) ;
if ( V_4 -> V_65 != V_12 ) {
goto V_323;
}
V_80 = F_230 ( & V_175 , V_2 , 1 ) ;
if ( V_80 )
return V_80 ;
if ( V_4 -> V_65 != V_12 ) {
F_152 ( V_2 , F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_175 , F_153 ( V_2 ) ) ;
V_80 = F_232 ( & V_175 ) ;
goto V_323;
}
V_80 = F_240 ( & V_175 ) ;
if ( ! V_80 )
V_80 = 1 ;
} else {
V_323:
if ( F_53 ( V_92 -> V_93 , V_12 ) ) {
if ( F_87 ( & V_39 -> V_105 ) > 1 )
V_80 = 1 ;
F_29 ( V_2 , V_39 , 1 ) ;
if ( V_4 -> V_94 )
V_80 = V_4 -> V_94 ;
}
}
return V_80 ;
}
int F_249 ( struct V_92 * V_92 )
{
unsigned int V_12 = F_247 ( V_92 ) -> V_322 ;
struct V_38 * V_39 = F_247 ( V_92 ) -> V_321 ;
if ( ! V_12 || ! V_39 ) {
F_246 ( V_92 ) ;
V_12 = F_247 ( V_92 ) -> V_322 ;
}
return F_248 ( V_92 , V_12 , V_39 ) ;
}
void F_250 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_40 ( V_2 , V_4 . V_324 ) ;
if ( ! V_9 ) {
return;
}
if ( F_251 ( V_9 ) &&
F_135 ( V_9 ) ) {
struct V_7 * V_46 ;
F_159 ( V_2 ) ;
V_46 = F_37 ( V_2 ,
V_4 -> V_58 ,
V_9 -> V_72 ) ;
if ( V_46 && F_136 ( V_46 ) ) {
F_142 ( V_9 ) ;
F_118 ( V_9 ) ;
}
F_156 ( V_2 ) ;
}
F_35 ( V_9 ) ;
}
int F_152 ( struct V_1 * V_2 ,
struct V_8 * V_9 , int V_279 )
{
F_40 ( V_2 , V_4 . V_325 ) ;
if ( ! F_95 ( V_9 ) ) {
if ( ! V_279 )
return 0 ;
F_137 ( V_9 ) ;
}
F_252 ( V_9 ) ;
if ( F_253 ( V_9 ) && F_135 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_141 ( V_9 ) ;
}
F_67 ( V_9 ) ;
return 1 ;
}
static int F_150 ( struct V_174 * V_175 , int V_314 )
{
struct V_1 * V_2 = V_175 -> V_274 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 , * V_20 , * V_326 ;
struct V_7 * V_327 = NULL ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
struct V_8 * V_191 ;
struct V_8 * V_188 ;
int V_328 = 0 ;
int V_329 ;
int V_25 ;
int V_315 ;
int V_317 ;
struct V_38 * V_39 , * V_330 ;
struct V_17 * V_18 , * V_331 ;
unsigned long V_332 ;
unsigned int V_333 ;
int V_202 ;
int V_107 ;
F_80 ( V_175 -> V_276 > 1 ) ;
F_80 ( ! V_175 -> V_180 ) ;
F_80 ( ! V_175 -> V_274 ) ;
if ( V_175 -> V_180 == ~ 0U )
V_314 |= V_181 | V_295 | V_311 ;
V_315 = V_314 & V_181 ;
V_317 = V_314 & V_311 ;
V_281 -> V_299 = V_175 -> V_301 ;
F_32 ( V_2 , L_161 ) ;
if ( V_4 -> V_114 == 0 ) {
F_152 ( V_2 , F_153 ( V_2 ) ,
1 ) ;
F_154 ( V_175 , F_153 ( V_2 ) ) ;
}
F_45 ( V_2 ) ;
if ( V_4 -> V_318 ) {
V_314 |= V_181 ;
V_315 = 1 ;
}
if ( V_4 -> V_319 ) {
V_314 |= V_295 | V_311 ;
V_317 = 1 ;
}
if ( ! F_243 ( V_175 , V_314 ) ) {
F_236 ( V_2 ) ;
F_223 ( V_2 ) ;
F_105 ( V_2 ) ;
goto V_334;
}
if ( V_4 -> V_318 ) {
V_315 = 1 ;
}
if ( V_4 -> V_270 > 0 ) {
V_315 = 1 ;
}
#ifdef F_254
V_281 -> V_299 = V_175 ;
V_175 -> V_276 ++ ;
F_255 ( V_175 ) ;
V_175 -> V_276 -- ;
V_281 -> V_299 = V_175 -> V_301 ;
#endif
V_188 =
F_176 ( V_2 ,
F_110 ( V_2 ) +
V_4 -> V_117 ) ;
F_65 ( V_188 ) ;
V_185 = (struct V_184 * ) ( V_188 ) -> V_132 ;
memset ( V_188 -> V_132 , 0 , V_188 -> V_207 ) ;
memcpy ( F_168 ( V_188 ) , V_192 , 8 ) ;
F_256 ( V_185 , V_4 -> V_65 ) ;
V_191 = F_176 ( V_2 , F_110 ( V_2 ) +
( ( V_4 -> V_117 + V_4 -> V_114 +
1 ) % F_111 ( V_2 ) ) ) ;
V_187 = (struct V_186 * ) V_191 -> V_132 ;
memset ( V_191 -> V_132 , 0 , V_191 -> V_207 ) ;
F_257 ( V_187 , V_4 -> V_65 ) ;
F_65 ( V_191 ) ;
V_39 = V_4 -> V_89 ;
F_46 ( & V_39 -> V_116 , V_2 ) ;
V_333 = V_39 -> V_65 ;
F_109 ( & V_39 -> V_104 , 0 ) ;
V_39 -> V_65 = V_4 -> V_65 ;
V_39 -> V_335 = V_4 -> V_265 ;
V_39 -> V_118 = V_191 ;
V_39 -> V_117 = V_4 -> V_117 ;
V_39 -> V_114 = V_4 -> V_114 ;
F_109 ( & V_39 -> V_147 , V_4 -> V_114 ) ;
F_109 ( & V_39 -> V_105 , V_4 -> V_114 + 2 ) ;
V_39 -> V_125 = NULL ;
V_202 = F_175 ( V_2 -> V_15 ) ;
for ( V_25 = 0 , V_46 = V_4 -> V_267 ; V_46 ; V_46 = V_46 -> V_20 , V_25 ++ ) {
if ( F_64 ( V_46 -> V_9 ) ) {
V_326 = F_31 ( V_2 ) ;
if ( ! V_326 ) {
F_51 ( V_2 , L_162 ,
L_163 ) ;
}
if ( V_25 == 0 ) {
V_39 -> V_125 = V_326 ;
}
V_326 -> V_45 = V_327 ;
V_326 -> V_20 = NULL ;
if ( V_327 ) {
V_327 -> V_20 = V_326 ;
}
V_327 = V_326 ;
if ( F_180
( V_2 , V_46 -> V_9 -> V_72 ) ) {
F_51 ( V_2 , L_164 ,
L_165
L_166 ,
V_46 -> V_9 -> V_72 ) ;
}
V_326 -> V_52 = V_46 -> V_9 -> V_72 ;
V_326 -> V_126 = 0 ;
V_326 -> V_2 = V_2 ;
V_326 -> V_9 = V_46 -> V_9 ;
V_326 -> V_122 = V_39 ;
F_44 ( V_4 -> V_58 , V_326 ) ;
if ( V_25 < V_202 ) {
V_185 -> V_125 [ V_25 ] =
F_128 ( V_46 -> V_9 -> V_72 ) ;
} else {
V_187 -> V_125 [ V_25 - V_202 ] =
F_128 ( V_46 -> V_9 -> V_72 ) ;
}
} else {
V_25 -- ;
}
}
F_258 ( V_185 , V_4 -> V_114 ) ;
F_259 ( V_185 , V_4 -> V_133 ) ;
F_256 ( V_185 , V_4 -> V_65 ) ;
F_260 ( V_187 , V_4 -> V_114 ) ;
F_80 ( V_4 -> V_114 == 0 ) ;
F_118 ( V_188 ) ;
V_328 = V_4 -> V_117 ;
V_46 = V_4 -> V_267 ;
V_332 = 1 ;
while ( V_46 ) {
F_71 ( V_46 -> V_9 ) ;
if ( F_64 ( V_46 -> V_9 ) ) {
struct V_8 * V_156 ;
char * V_336 ;
struct V_68 * V_68 ;
V_156 =
F_176 ( V_2 ,
F_110 ( V_2 ) +
( ( V_328 +
V_332 ) %
F_111 ( V_2 ) ) ) ;
F_65 ( V_156 ) ;
V_68 = V_46 -> V_9 -> V_69 ;
V_336 = F_261 ( V_68 ) ;
memcpy ( V_156 -> V_132 ,
V_336 + F_262 ( V_46 -> V_9 -> V_132 ) ,
V_46 -> V_9 -> V_207 ) ;
F_263 ( V_68 ) ;
F_118 ( V_156 ) ;
V_332 ++ ;
F_264 ( V_46 -> V_9 ) ;
F_239 ( V_46 -> V_9 ) ;
} else {
F_27 ( V_2 , L_167 ,
L_168
L_169 ) ;
F_147 ( V_46 -> V_9 ) ;
}
V_20 = V_46 -> V_20 ;
F_33 ( V_2 , V_46 ) ;
V_46 = V_20 ;
F_265 ( V_2 ) ;
}
V_4 -> V_89 = F_187 ( V_2 ) ;
F_90 ( & V_39 -> V_103 , & V_4 -> V_67 ) ;
F_90 ( & V_39 -> V_135 , & V_4 -> V_135 ) ;
V_4 -> V_136 ++ ;
V_329 = V_4 -> V_117 ;
V_4 -> V_117 =
( V_4 -> V_117 + V_4 -> V_114 +
2 ) % F_111 ( V_2 ) ;
F_109 ( & V_4 -> V_144 , 0 ) ;
V_4 -> V_264 = 0 ;
V_4 -> V_266 = NULL ;
V_4 -> V_267 = NULL ;
V_4 -> V_114 = 0 ;
V_4 -> V_265 = 0 ;
if ( ++ V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_89 -> V_65 = V_4 -> V_65 ;
V_4 -> V_270 = 0 ;
V_4 -> V_263 = 0 ;
V_4 -> V_318 = 0 ;
V_4 -> V_319 = 0 ;
F_1 ( V_2 ) ;
F_266 () ;
if ( ! F_54 ( & V_39 -> V_90 ) ) {
V_107 = F_106 ( V_2 ) ;
F_93 ( & V_4 -> V_87 ,
V_4 , V_39 , & V_39 -> V_90 ) ;
F_108 ( V_2 , V_107 ) ;
}
F_80 ( ! F_54 ( & V_39 -> V_90 ) ) ;
F_48 ( & V_39 -> V_116 ) ;
if ( V_315 ) {
F_29 ( V_2 , V_39 , 1 ) ;
F_132 ( V_2 , V_39 , 1 ) ;
} else if ( ! ( V_39 -> V_149 & V_285 ) ) {
if ( V_2 -> V_178 & V_337 )
F_267 ( F_158 ( V_2 ) -> V_338 ,
& V_4 -> V_183 , V_109 / 10 ) ;
}
V_99:
F_268 (entry, safe, &journal->j_journal_list) {
V_330 = F_55 ( V_18 ) ;
if ( V_4 -> V_117 <= V_330 -> V_117 ) {
if ( ( V_4 -> V_117 + V_4 -> V_146 + 1 ) >=
V_330 -> V_117 ) {
F_144 ( V_2 , V_330 ) ;
goto V_99;
} else if ( ( V_4 -> V_117 +
V_4 -> V_146 + 1 ) <
F_111 ( V_2 ) ) {
break;
}
} else if ( ( V_4 -> V_117 +
V_4 -> V_146 + 1 ) >
F_111 ( V_2 ) ) {
if ( ( ( V_4 -> V_117 + V_4 -> V_146 + 1 ) %
F_111 ( V_2 ) ) >=
V_330 -> V_117 ) {
F_144 ( V_2 , V_330 ) ;
goto V_99;
} else {
break;
}
}
}
V_4 -> V_89 -> V_42 =
F_28 ( V_2 , V_4 -> V_89 ) ;
if ( ! ( V_4 -> V_89 -> V_42 ) ) {
F_51 ( V_2 , L_170 ,
L_171 ) ;
}
F_109 ( & V_4 -> V_269 , 0 ) ;
F_47 ( V_2 ) ;
F_212 ( V_280 , & V_4 -> V_149 ) ;
F_213 ( & V_4 -> V_268 ) ;
if ( ! V_315 && V_317 &&
F_53 ( V_2 , V_333 ) ) {
F_29 ( V_2 , V_39 , 1 ) ;
}
V_334:
F_32 ( V_2 , L_172 ) ;
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_274 = V_2 ;
return V_4 -> V_94 ;
}
void F_269 ( struct V_1 * V_2 , int V_339 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_41 ( V_340 , & V_4 -> V_149 ) )
return;
if ( ! V_4 -> V_94 )
V_4 -> V_94 = V_339 ;
V_2 -> V_178 |= V_179 ;
F_19 ( V_340 , & V_4 -> V_149 ) ;
#ifdef F_115
F_270 () ;
#endif
}
