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
F_74 ( V_75 , 0 , V_9 ) ;
}
static void F_75 ( struct V_8 * V_9 )
{
F_70 ( V_9 ) ;
V_9 -> V_74 = F_68 ;
F_4 ( V_9 ) ;
if ( ! F_73 ( V_9 ) )
F_43 () ;
F_74 ( V_75 , 0 , V_9 ) ;
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
F_103 ( V_75 , 0 , 1 , & V_9 ) ;
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
F_103 ( V_75 , 0 , 1 , & V_111 ) ;
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
F_120 ( V_39 -> V_118 ,
V_119 | V_120 | V_121 ) ;
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
if ( V_4 -> V_122 != 0 &&
( V_39 -> V_65 - V_4 -> V_122 ) != 1 ) {
F_27 ( V_64 , L_14 , L_15 ,
V_4 -> V_122 , V_39 -> V_65 ) ;
}
V_4 -> V_122 = V_39 -> V_65 ;
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
V_123 ) ;
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
if ( V_46 -> V_2 == V_2 && V_46 -> V_52 == V_52 && V_46 -> V_124 ) {
return V_46 -> V_124 ;
}
V_46 = V_46 -> V_61 ;
}
return NULL ;
}
static void F_125 ( struct V_1 * V_2 ,
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
F_126 ( V_2 , V_4 -> V_58 ,
V_39 , V_46 -> V_52 , 1 ) ;
}
V_126 = V_46 ;
V_46 = V_46 -> V_20 ;
F_33 ( V_2 , V_126 ) ;
}
V_39 -> V_127 = NULL ;
}
static int F_127 ( struct V_1 * V_2 ,
unsigned long V_129 ,
unsigned int V_66 )
{
struct V_130 * V_83 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_107 ;
if ( F_117 ( V_4 ) )
return - V_97 ;
if ( V_66 >= V_4 -> V_131 ) {
if ( F_101 ( ( V_4 -> V_132 ) ) ) {
V_107 = F_106 ( V_2 ) ;
F_113 ( V_4 -> V_132 ) ;
F_108 ( V_2 , V_107 ) ;
if ( F_102 ( ! F_73 ( V_4 -> V_132 ) ) ) {
#ifdef F_115
F_27 ( V_2 , L_19 ,
L_12 ) ;
#endif
return - V_97 ;
}
}
V_4 -> V_131 = V_66 ;
V_4 -> V_133 = V_129 ;
V_83 = (struct V_130 * ) ( V_4 -> V_132 ->
V_134 ) ;
V_83 -> V_131 = F_128 ( V_66 ) ;
V_83 -> V_133 = F_128 ( V_129 ) ;
V_83 -> V_135 = F_128 ( V_4 -> V_135 ) ;
F_129 ( V_4 -> V_132 ) ;
V_107 = F_106 ( V_2 ) ;
if ( F_119 ( V_2 ) )
F_120 ( V_4 -> V_132 ,
V_119 | V_120 | V_121 ) ;
else
F_114 ( V_4 -> V_132 ) ;
F_108 ( V_2 , V_107 ) ;
if ( ! F_73 ( V_4 -> V_132 ) ) {
F_27 ( V_2 , L_20 ,
L_21 ) ;
return - V_97 ;
}
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 ,
unsigned long V_129 ,
unsigned int V_66 )
{
return F_127 ( V_2 , V_129 , V_66 ) ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_17 * V_18 ;
struct V_38 * V_98 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_66 = V_39 -> V_65 ;
V_136:
V_18 = V_4 -> V_67 . V_20 ;
if ( V_18 == & V_4 -> V_67 )
return 0 ;
V_98 = F_55 ( V_18 ) ;
if ( V_98 -> V_65 < V_66 ) {
F_80 ( V_98 -> V_63 <= 0 ) ;
F_132 ( V_2 , V_98 , 0 ) ;
goto V_136;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
if ( ! F_54 ( & V_39 -> V_137 ) ) {
F_86 ( & V_39 -> V_137 ) ;
V_4 -> V_138 -- ;
}
}
static int F_132 ( struct V_1 * V_64 ,
struct V_38 * V_39 , int V_110 )
{
struct V_38 * V_139 ;
struct V_7 * V_46 , * V_126 ;
int V_140 ;
int V_141 = 0 ;
int V_142 = 0 ;
struct V_8 * V_143 ;
unsigned long V_144 = V_39 -> V_114 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
int V_145 = 0 ;
int V_107 ;
F_80 ( V_144 <= 0 ) ;
if ( F_87 ( & V_4 -> V_146 ) != 0 ) {
F_27 ( V_64 , L_22 , L_23 ,
F_87 ( & V_4 -> V_146 ) ) ;
}
if ( V_110 ) {
F_46 ( & V_4 -> V_147 , V_64 ) ;
} else if ( F_134 ( & V_4 -> V_147 ) ) {
F_43 () ;
}
V_140 = 0 ;
if ( V_144 > V_4 -> V_148 ) {
F_51 ( V_64 , L_24 , L_25 ,
V_144 , V_39 -> V_65 ) ;
return 0 ;
}
if ( F_87 ( & V_39 -> V_149 ) <= 0 &&
F_87 ( & V_39 -> V_105 ) <= 0 ) {
goto V_150;
}
F_29 ( V_64 , V_39 , 1 ) ;
if ( ! ( V_39 -> V_151 & V_152 )
&& ! F_117 ( V_4 ) )
F_43 () ;
if ( F_87 ( & V_39 -> V_149 ) <= 0 &&
F_87 ( & V_39 -> V_105 ) <= 0 ) {
goto V_150;
}
if ( F_87 ( & V_4 -> V_146 ) != 0 ) {
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
V_139 = F_124 ( V_46 ) ;
if ( ! V_139 && V_46 -> V_9 ) {
V_143 = V_46 -> V_9 ;
F_70 ( V_143 ) ;
if ( F_135 ( V_143 ) ) {
F_80 ( ! F_136 ( V_46 ) ) ;
V_141 = 1 ;
V_142 = 1 ;
} else if ( F_136 ( V_46 ) ) {
F_43 () ;
}
}
if ( V_139 ) {
if ( F_87 ( & V_139 -> V_105 ) )
F_29 ( V_64 , V_139 , 1 ) ;
goto F_33;
}
if ( V_143 == NULL ) {
goto F_33;
}
if ( ( ! V_141 ) && ! F_101 ( V_143 ) ) {
F_27 ( V_64 , L_29 ,
L_30
L_31 ,
( unsigned long long ) V_143 ->
V_72 , V_142 ? ' ' : '!' ,
V_141 ? ' ' : '!' ) ;
}
if ( V_142 ) {
F_70 ( V_143 ) ;
F_19 ( V_153 , & V_46 -> V_128 ) ;
F_137 ( V_143 ) ;
F_80 ( V_46 -> V_52 != V_143 -> V_72 ) ;
if ( F_96 ( V_143 ) )
F_69 ( V_143 ) ;
else
F_67 ( V_143 ) ;
V_140 ++ ;
} else {
F_27 ( V_64 , L_32 ,
L_33 ,
( unsigned long long ) V_143 ->
V_72 , V_123 ) ;
}
F_33:
V_126 = V_46 ;
V_46 = V_46 -> V_20 ;
if ( V_143 ) {
F_59 ( V_143 ) ;
if ( F_87 ( & V_143 -> V_154 ) < 0 ) {
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
V_145 = - V_97 ;
}
F_80 ( ! F_138
( V_46 -> V_9 ) ) ;
F_59 ( V_46 -> V_9 ) ;
F_56 ( V_46 -> V_9 ) ;
}
V_46 = V_46 -> V_20 ;
}
}
if ( V_145 )
F_123 ( V_64 , - V_97 ,
L_40 ,
V_123 ) ;
V_150:
if ( V_110 ) {
F_131 ( V_64 , V_39 ) ;
}
V_145 = V_4 -> V_94 ;
if ( ! V_145 && V_110 ) {
V_145 =
F_130 ( V_64 ,
( V_39 -> V_117 + V_39 -> V_114 +
2 ) % F_111 ( V_64 ) ,
V_39 -> V_65 ) ;
if ( V_145 )
F_123 ( V_64 , - V_97 ,
L_41 ,
V_123 ) ;
}
F_125 ( V_64 , V_39 , 0 ) ;
F_86 ( & V_39 -> V_103 ) ;
V_4 -> V_155 -- ;
F_133 ( V_64 , V_39 ) ;
if ( V_4 -> V_156 != 0 &&
( V_39 -> V_65 - V_4 -> V_156 ) != 1 ) {
F_27 ( V_64 , L_42 , L_43 ,
V_4 -> V_156 , V_39 -> V_65 ) ;
}
V_4 -> V_156 = V_39 -> V_65 ;
V_39 -> V_114 = 0 ;
F_109 ( & V_39 -> V_149 , 0 ) ;
V_39 -> V_117 = 0 ;
V_39 -> V_127 = NULL ;
V_39 -> V_118 = NULL ;
V_39 -> V_65 = 0 ;
V_39 -> V_151 = 0 ;
F_50 ( V_64 , V_39 ) ;
if ( V_110 )
F_48 ( & V_4 -> V_147 ) ;
return V_145 ;
}
static int F_139 ( struct V_1 * V_64 ,
struct V_38 * V_39 ,
struct V_76 * V_77 )
{
struct V_7 * V_46 ;
int V_80 = 0 ;
V_39 -> V_151 |= V_157 ;
F_133 ( V_64 , V_39 ) ;
if ( V_39 -> V_114 == 0 || F_87 ( & V_39 -> V_149 ) == 0 ) {
return 0 ;
}
V_46 = V_39 -> V_127 ;
while ( V_46 ) {
if ( V_46 -> V_52 == 0 ) {
goto V_20;
}
if ( V_46 -> V_9 && F_136 ( V_46 ) && F_96 ( V_46 -> V_9 ) ) {
struct V_8 * V_158 ;
V_158 = V_46 -> V_9 ;
F_70 ( V_158 ) ;
F_137 ( V_158 ) ;
if ( V_46 -> V_9 && F_136 ( V_46 ) && F_96 ( V_158 ) ) {
if ( ! F_135 ( V_158 ) ||
F_140 ( V_158 ) )
F_43 () ;
F_78 ( V_77 , V_158 , NULL , F_76 ) ;
V_80 ++ ;
} else {
F_67 ( V_158 ) ;
}
F_59 ( V_158 ) ;
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
struct V_38 * V_139 ;
int V_80 = 0 ;
V_39 -> V_151 |= V_152 ;
V_46 = V_39 -> V_127 ;
while ( V_46 ) {
V_139 = F_124 ( V_46 ) ;
if ( ! V_139 && V_46 -> V_52 && V_46 -> V_9
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
struct V_38 * * V_159 ,
unsigned int * V_160 ,
int V_161 , int V_162 )
{
int V_80 = 0 ;
int V_163 = 0 ;
int V_164 = 0 ;
unsigned int V_165 = V_39 -> V_65 ;
struct V_76 V_77 ;
struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
V_77 . V_78 = 0 ;
F_46 ( & V_4 -> V_147 , V_64 ) ;
if ( ! F_53 ( V_64 , V_165 ) ) {
goto V_166;
}
while ( ( V_162 && V_164 < V_162 ) ||
( ! V_162 && V_163 < V_161 ) ) {
if ( V_39 -> V_114 == 0 || ( V_39 -> V_151 & V_157 ) ||
F_87 ( & V_39 -> V_105 )
|| ! ( V_39 -> V_151 & V_152 ) ) {
F_133 ( V_64 , V_39 ) ;
break;
}
V_80 = F_139 ( V_64 , V_39 , & V_77 ) ;
if ( V_80 < 0 )
goto V_166;
V_164 ++ ;
V_163 += V_80 ;
V_18 = V_39 -> V_103 . V_20 ;
if ( V_18 == & V_4 -> V_67 ) {
break;
}
V_39 = F_55 ( V_18 ) ;
if ( V_39 -> V_65 <= V_165 )
break;
}
if ( V_77 . V_78 ) {
F_76 ( & V_77 ) ;
}
V_166:
F_48 ( & V_4 -> V_147 ) ;
return V_80 ;
}
static int F_144 ( struct V_1 * V_64 ,
struct V_38 * V_39 )
{
unsigned long V_167 = 0 ;
unsigned long V_168 ;
int V_80 ;
int V_25 ;
int V_169 = 256 ;
struct V_38 * V_170 ;
struct V_38 * V_171 ;
unsigned int V_66 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
V_171 = V_170 = V_39 ;
if ( F_145 ( V_64 ) )
V_169 = 1024 ;
for ( V_25 = 0 ; V_25 < 256 && V_167 < V_169 ; V_25 ++ ) {
if ( F_87 ( & V_170 -> V_105 ) ||
V_170 -> V_65 < V_39 -> V_65 ) {
break;
}
V_168 = F_87 ( & V_170 -> V_149 ) ;
if ( V_168 > 0 ) {
V_170 -> V_151 &= ~ V_157 ;
}
V_167 += V_168 ;
V_171 = V_170 ;
if ( V_170 -> V_103 . V_20 == & V_4 -> V_67 )
break;
V_170 = F_55 ( V_170 -> V_103 . V_20 ) ;
}
F_49 ( V_39 ) ;
F_49 ( V_171 ) ;
if ( V_171 != V_39 ) {
V_80 = F_143 ( V_64 , V_39 , & V_170 , & V_66 , V_167 , V_25 ) ;
}
F_132 ( V_64 , V_171 , 1 ) ;
F_50 ( V_64 , V_171 ) ;
F_50 ( V_64 , V_39 ) ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 ,
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
F_88 ( & V_173 -> V_124 -> V_149 ) ;
V_173 -> V_9 = NULL ;
V_173 -> V_124 = NULL ;
}
V_173 = V_173 -> V_53 ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 -> V_89 ) ;
V_4 -> V_155 -- ;
F_23 ( V_4 -> V_175 ) ;
F_22 ( V_2 , V_4 -> V_42 ) ;
F_24 ( V_2 ) ;
if ( V_4 -> V_132 ) {
F_147 ( V_4 -> V_132 ) ;
}
F_148 ( V_2 , V_4 ) ;
F_23 ( V_4 ) ;
}
static int F_149 ( struct V_176 * V_177 ,
struct V_1 * V_2 , int error )
{
struct V_176 V_178 ;
int V_179 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! error && ! ( V_2 -> V_180 & V_181 ) ) {
F_80 ( ! V_177 -> V_182 ) ;
F_150 ( V_177 , V_183 ) ;
if ( ! F_151 ( & V_178 , V_2 ) ) {
F_152 ( V_2 ,
F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_178 , F_153 ( V_2 ) ) ;
F_150 ( & V_178 , V_183 ) ;
V_179 = 1 ;
}
}
if ( ! error && F_117 ( V_4 ) ) {
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
if ( ! F_155 ( & V_178 , V_2 ) ) {
F_152 ( V_2 ,
F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_178 , F_153 ( V_2 ) ) ;
F_150 ( & V_178 , V_183 ) ;
}
}
F_156 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( & F_2 ( V_2 ) -> V_184 ) ;
F_146 ( V_2 ) ;
F_159 ( V_2 ) ;
return 0 ;
}
int F_160 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
return F_149 ( V_177 , V_2 , 0 ) ;
}
int F_161 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
return F_149 ( V_177 , V_2 , 1 ) ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_185 * V_186 ,
struct V_187 * V_188 )
{
if ( F_163 ( V_188 ) != F_164 ( V_186 ) ||
F_165 ( V_188 ) != F_166 ( V_186 ) ||
F_165 ( V_188 ) > F_2 ( V_2 ) -> V_148 ||
F_165 ( V_188 ) <= 0 ) {
return 1 ;
}
return 0 ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_8 * V_189 ,
unsigned int * V_190 ,
unsigned long * V_191 )
{
struct V_185 * V_186 ;
struct V_187 * V_188 ;
struct V_8 * V_192 ;
unsigned long V_129 ;
if ( ! V_189 )
return 0 ;
V_186 = (struct V_185 * ) V_189 -> V_134 ;
if ( F_166 ( V_186 ) > 0
&& ! memcmp ( F_168 ( V_189 ) , V_193 , 8 ) ) {
if ( V_190 && * V_190
&& F_164 ( V_186 ) > * V_190 ) {
F_169 ( V_2 , V_194 ,
L_44
L_45
L_46 ,
F_164 ( V_186 ) ,
* V_190 ) ;
return 0 ;
}
if ( V_191
&& * V_191 > F_170 ( V_186 ) ) {
F_169 ( V_2 , V_194 ,
L_47
L_48
L_49 ,
F_170 ( V_186 ) ,
* V_191 ) ;
return - 1 ;
}
if ( F_166 ( V_186 ) > F_2 ( V_2 ) -> V_148 ) {
F_27 ( V_2 , L_50 ,
L_51
L_52 ,
F_166 ( V_186 ) ) ;
return - 1 ;
}
V_129 = V_189 -> V_72 - F_110 ( V_2 ) ;
V_192 =
F_171 ( V_2 ,
F_110 ( V_2 ) +
( ( V_129 + F_166 ( V_186 ) +
1 ) % F_111 ( V_2 ) ) ) ;
if ( ! V_192 )
return 0 ;
V_188 = (struct V_187 * ) V_192 -> V_134 ;
if ( F_162 ( V_2 , V_186 , V_188 ) ) {
F_169 ( V_2 , V_194 ,
L_53
L_54 ,
V_192 -> V_72 -
F_110 ( V_2 ) ,
F_163 ( V_188 ) ,
F_165 ( V_188 ) ) ;
F_147 ( V_192 ) ;
if ( V_190 ) {
* V_190 =
F_164 ( V_186 ) ;
F_169 ( V_2 , V_194 ,
L_55
L_56
L_57 ,
F_164 ( V_186 ) ) ;
}
return - 1 ;
}
F_147 ( V_192 ) ;
F_169 ( V_2 , V_194 ,
L_58
L_59 ,
V_189 -> V_72 -
F_110 ( V_2 ) ,
F_166 ( V_186 ) ,
F_164 ( V_186 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static void F_172 ( struct V_8 * * V_195 , int V_196 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_196 ; V_25 ++ ) {
F_147 ( V_195 [ V_25 ] ) ;
}
}
static int F_173 ( struct V_1 * V_2 ,
unsigned long V_197 ,
unsigned long V_198 ,
unsigned int V_199 ,
unsigned long V_191 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_185 * V_186 ;
struct V_187 * V_188 ;
unsigned int V_66 = 0 ;
struct V_8 * V_192 ;
struct V_8 * V_189 ;
struct V_8 * * V_200 = NULL ;
struct V_8 * * V_201 = NULL ;
unsigned int V_202 ;
int V_25 ;
int V_203 ;
V_189 = F_171 ( V_2 , V_197 ) ;
if ( ! V_189 )
return 1 ;
V_186 = (struct V_185 * ) V_189 -> V_134 ;
V_202 = V_189 -> V_72 - F_110 ( V_2 ) ;
F_169 ( V_2 , V_194 , L_60
L_61 ,
V_189 -> V_72 - F_110 ( V_2 ) ,
F_166 ( V_186 ) , F_170 ( V_186 ) ) ;
if ( F_164 ( V_186 ) < V_199 ) {
F_169 ( V_2 , V_194 , L_62
L_63 ,
V_197 -
F_110 ( V_2 ) ) ;
F_147 ( V_189 ) ;
return 1 ;
}
if ( F_170 ( V_186 ) != V_191 ) {
F_169 ( V_2 , V_194 , L_64
L_65
L_49 , F_170 ( V_186 ) ,
V_191 ) ;
F_147 ( V_189 ) ;
return 1 ;
}
V_192 = F_171 ( V_2 , F_110 ( V_2 ) +
( ( V_202 + F_166 ( V_186 ) + 1 ) %
F_111 ( V_2 ) ) ) ;
if ( ! V_192 ) {
F_147 ( V_189 ) ;
return 1 ;
}
V_188 = (struct V_187 * ) V_192 -> V_134 ;
if ( F_162 ( V_2 , V_186 , V_188 ) ) {
F_169 ( V_2 , V_194 ,
L_66
L_67 ,
V_192 -> V_72 -
F_110 ( V_2 ) ,
F_163 ( V_188 ) ,
F_165 ( V_188 ) ) ;
F_147 ( V_192 ) ;
F_147 ( V_189 ) ;
return 1 ;
}
if ( F_174 ( V_2 -> V_204 ) ) {
F_27 ( V_2 , L_68 ,
L_69 ) ;
F_147 ( V_192 ) ;
F_147 ( V_189 ) ;
return - V_205 ;
}
V_66 = F_164 ( V_186 ) ;
V_200 = F_7 ( F_166 ( V_186 ) *
sizeof( struct V_8 * ) , V_13 ) ;
V_201 = F_7 ( F_166 ( V_186 ) *
sizeof( struct V_8 * ) , V_13 ) ;
if ( ! V_200 || ! V_201 ) {
F_147 ( V_192 ) ;
F_147 ( V_189 ) ;
F_9 ( V_200 ) ;
F_9 ( V_201 ) ;
F_27 ( V_2 , L_70 ,
L_71 ) ;
return - 1 ;
}
V_203 = F_175 ( V_2 -> V_15 ) ;
for ( V_25 = 0 ; V_25 < F_166 ( V_186 ) ; V_25 ++ ) {
V_200 [ V_25 ] =
F_176 ( V_2 ,
F_110 ( V_2 ) +
( V_202 + 1 +
V_25 ) % F_111 ( V_2 ) ) ;
if ( V_25 < V_203 ) {
V_201 [ V_25 ] =
F_177 ( V_2 ,
F_178 ( V_186 -> V_127 [ V_25 ] ) ) ;
} else {
V_201 [ V_25 ] =
F_177 ( V_2 ,
F_178 ( V_188 ->
V_127 [ V_25 - V_203 ] ) ) ;
}
if ( V_201 [ V_25 ] -> V_72 > F_179 ( V_2 ) ) {
F_27 ( V_2 , L_72 ,
L_73
L_74
L_75 ) ;
goto V_206;
}
if ( F_180
( V_2 , V_201 [ V_25 ] -> V_72 ) ) {
F_27 ( V_2 , L_76 ,
L_73
L_77 ) ;
V_206:
F_172 ( V_200 , V_25 ) ;
F_172 ( V_201 , V_25 ) ;
F_147 ( V_192 ) ;
F_147 ( V_189 ) ;
F_9 ( V_200 ) ;
F_9 ( V_201 ) ;
return - 1 ;
}
}
F_103 ( V_207 , 0 , F_166 ( V_186 ) , V_200 ) ;
for ( V_25 = 0 ; V_25 < F_166 ( V_186 ) ; V_25 ++ ) {
F_98 ( V_200 [ V_25 ] ) ;
if ( ! F_73 ( V_200 [ V_25 ] ) ) {
F_27 ( V_2 , L_78 ,
L_73
L_12 ) ;
F_172 ( V_200 + V_25 ,
F_166 ( V_186 ) - V_25 ) ;
F_172 ( V_201 , F_166 ( V_186 ) ) ;
F_147 ( V_192 ) ;
F_147 ( V_189 ) ;
F_9 ( V_200 ) ;
F_9 ( V_201 ) ;
return - 1 ;
}
memcpy ( V_201 [ V_25 ] -> V_134 , V_200 [ V_25 ] -> V_134 ,
V_201 [ V_25 ] -> V_208 ) ;
F_65 ( V_201 [ V_25 ] ) ;
F_147 ( V_200 [ V_25 ] ) ;
}
for ( V_25 = 0 ; V_25 < F_166 ( V_186 ) ; V_25 ++ ) {
F_129 ( V_201 [ V_25 ] ) ;
F_181 ( V_201 [ V_25 ] , 0 ) ;
}
for ( V_25 = 0 ; V_25 < F_166 ( V_186 ) ; V_25 ++ ) {
F_98 ( V_201 [ V_25 ] ) ;
if ( ! F_73 ( V_201 [ V_25 ] ) ) {
F_27 ( V_2 , L_79 ,
L_80
L_12 ) ;
F_172 ( V_201 + V_25 ,
F_166 ( V_186 ) - V_25 ) ;
F_147 ( V_192 ) ;
F_147 ( V_189 ) ;
F_9 ( V_200 ) ;
F_9 ( V_201 ) ;
return - 1 ;
}
F_147 ( V_201 [ V_25 ] ) ;
}
V_197 =
F_110 ( V_2 ) +
( ( V_202 + F_166 ( V_186 ) +
2 ) % F_111 ( V_2 ) ) ;
F_169 ( V_2 , V_194 ,
L_81 L_82 ,
V_197 - F_110 ( V_2 ) ) ;
V_4 -> V_117 = V_197 - F_110 ( V_2 ) ;
V_4 -> V_131 = V_66 ;
V_4 -> V_65 = V_66 + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
F_147 ( V_192 ) ;
F_147 ( V_189 ) ;
F_9 ( V_200 ) ;
F_9 ( V_201 ) ;
return 0 ;
}
static struct V_8 * F_182 ( struct V_209 * V_210 ,
T_1 V_27 , int V_211 ,
T_1 V_212 )
{
struct V_8 * V_213 [ V_214 ] ;
unsigned int V_215 = V_214 ;
struct V_8 * V_9 ;
int V_25 , V_40 ;
V_9 = F_183 ( V_210 , V_27 , V_211 ) ;
if ( F_73 ( V_9 ) )
return ( V_9 ) ;
if ( V_27 + V_214 > V_212 ) {
V_215 = V_212 - V_27 ;
}
V_213 [ 0 ] = V_9 ;
V_40 = 1 ;
for ( V_25 = 1 ; V_25 < V_215 ; V_25 ++ ) {
V_9 = F_183 ( V_210 , V_27 + V_25 , V_211 ) ;
if ( F_73 ( V_9 ) ) {
F_147 ( V_9 ) ;
break;
} else
V_213 [ V_40 ++ ] = V_9 ;
}
F_103 ( V_207 , 0 , V_40 , V_213 ) ;
for ( V_25 = 1 ; V_25 < V_40 ; V_25 ++ )
F_147 ( V_213 [ V_25 ] ) ;
V_9 = V_213 [ 0 ] ;
F_98 ( V_9 ) ;
if ( F_73 ( V_9 ) )
return V_9 ;
F_147 ( V_9 ) ;
return NULL ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_185 * V_186 ;
unsigned int V_199 = 0 ;
unsigned int V_190 = 0 ;
T_3 V_216 ;
unsigned long V_198 = 0 ;
unsigned long V_197 = 0 ;
unsigned long V_191 = 9 ;
struct V_8 * V_189 ;
struct V_130 * V_83 ;
int V_217 = 0 ;
int V_218 = 0 ;
int V_219 = 1 ;
int V_80 ;
V_197 = F_110 ( V_2 ) ;
F_185 ( V_2 , L_83 ,
V_4 -> V_220 ) ;
V_216 = F_186 () ;
V_4 -> V_132 = F_171 ( V_2 ,
F_110 ( V_2 )
+ F_111 ( V_2 ) ) ;
if ( ! V_4 -> V_132 ) {
return 1 ;
}
V_83 = (struct V_130 * ) ( V_4 -> V_132 -> V_134 ) ;
if ( F_178 ( V_83 -> V_133 ) <
F_111 ( V_2 )
&& F_178 ( V_83 -> V_131 ) > 0 ) {
V_198 =
F_110 ( V_2 ) +
F_178 ( V_83 -> V_133 ) ;
V_199 = F_178 ( V_83 -> V_131 ) + 1 ;
V_191 = F_178 ( V_83 -> V_135 ) ;
F_169 ( V_2 , V_194 ,
L_84
L_85
L_86 , F_178 ( V_83 -> V_133 ) ,
F_178 ( V_83 -> V_131 ) ) ;
V_217 = 1 ;
V_189 =
F_171 ( V_2 ,
F_110 ( V_2 ) +
F_178 ( V_83 -> V_133 ) ) ;
V_80 = F_167 ( V_2 , V_189 , NULL , NULL ) ;
if ( ! V_80 ) {
V_219 = 0 ;
}
F_147 ( V_189 ) ;
goto V_221;
}
while ( V_219
&& V_197 <
( F_110 ( V_2 ) +
F_111 ( V_2 ) ) ) {
V_189 =
F_182 ( V_4 -> V_220 , V_197 ,
V_2 -> V_15 ,
F_110 ( V_2 ) +
F_111 ( V_2 ) ) ;
V_80 =
F_167 ( V_2 , V_189 ,
& V_190 ,
& V_191 ) ;
if ( V_80 == 1 ) {
V_186 = (struct V_185 * ) V_189 -> V_134 ;
if ( V_198 == 0 ) {
V_199 = F_164 ( V_186 ) ;
V_198 = V_189 -> V_72 ;
V_191 = F_170 ( V_186 ) ;
F_169 ( V_2 , V_194 ,
L_87
L_88 ,
V_198 -
F_110
( V_2 ) , V_199 ) ;
} else if ( V_199 > F_164 ( V_186 ) ) {
V_199 = F_164 ( V_186 ) ;
V_198 = V_189 -> V_72 ;
F_169 ( V_2 , V_194 ,
L_89
L_90 ,
V_198 -
F_110
( V_2 ) , V_199 ) ;
}
if ( V_191 < F_170 ( V_186 ) ) {
V_191 = F_170 ( V_186 ) ;
F_169 ( V_2 , V_194 ,
L_91
L_92 ,
F_170 ( V_186 ) ) ;
}
V_197 += F_166 ( V_186 ) + 2 ;
} else {
V_197 ++ ;
}
F_147 ( V_189 ) ;
}
V_221:
V_197 = V_198 ;
if ( V_199 ) {
F_169 ( V_2 , V_194 ,
L_93
L_94 ,
V_197 - F_110 ( V_2 ) ,
V_199 ) ;
}
V_218 = 0 ;
while ( V_219 && V_199 > 0 ) {
V_80 =
F_173 ( V_2 , V_197 , V_198 ,
V_199 , V_191 ) ;
if ( V_80 < 0 ) {
return V_80 ;
} else if ( V_80 != 0 ) {
break;
}
V_197 =
F_110 ( V_2 ) + V_4 -> V_117 ;
V_218 ++ ;
if ( V_197 == V_198 )
break;
}
if ( V_199 == 0 ) {
F_169 ( V_2 , V_194 ,
L_95 L_96 ) ;
}
if ( V_217 && V_218 == 0 ) {
V_4 -> V_117 = F_178 ( V_83 -> V_133 ) ;
V_4 -> V_65 =
F_178 ( V_83 -> V_131 ) + 1 ;
if ( V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_131 =
F_178 ( V_83 -> V_131 ) ;
V_4 -> V_135 = F_178 ( V_83 -> V_135 ) + 1 ;
} else {
V_4 -> V_135 = V_191 + 1 ;
}
F_169 ( V_2 , V_194 , L_91
L_97 , V_4 -> V_135 ) ;
V_4 -> V_133 = V_4 -> V_117 ;
if ( V_218 > 0 ) {
F_185 ( V_2 ,
L_98 ,
V_218 , F_186 () - V_216 ) ;
}
F_159 ( V_2 ) ;
if ( ! F_174 ( V_2 -> V_204 ) &&
F_127 ( V_2 , V_4 -> V_117 ,
V_4 -> V_131 ) ) {
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
V_13 | V_222 ) ;
F_10 ( & V_39 -> V_103 ) ;
F_10 ( & V_39 -> V_137 ) ;
F_10 ( & V_39 -> V_90 ) ;
F_10 ( & V_39 -> V_91 ) ;
F_188 ( & V_39 -> V_116 ) ;
F_2 ( V_64 ) -> V_155 ++ ;
F_49 ( V_39 ) ;
return V_39 ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) -> V_89 = F_187 ( V_2 ) ;
}
static void F_148 ( struct V_1 * V_223 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_220 != NULL ) {
F_190 ( V_4 -> V_220 , V_4 -> V_224 ) ;
V_4 -> V_220 = NULL ;
}
}
static int F_191 ( struct V_1 * V_223 ,
struct V_3 * V_4 ,
const char * V_225 )
{
int V_226 ;
T_4 V_227 ;
T_5 V_228 = V_229 | V_230 | V_231 ;
char V_232 [ V_233 ] ;
V_226 = 0 ;
V_4 -> V_220 = NULL ;
V_227 = F_192 ( V_223 ) ?
F_193 ( F_192 ( V_223 ) ) : V_223 -> V_234 ;
if ( F_174 ( V_223 -> V_204 ) )
V_228 = V_229 ;
if ( ( ! V_225 || ! V_225 [ 0 ] ) ) {
if ( V_227 == V_223 -> V_234 )
V_228 &= ~ V_231 ;
V_4 -> V_220 = F_194 ( V_227 , V_228 ,
V_4 ) ;
V_4 -> V_224 = V_228 ;
if ( F_195 ( V_4 -> V_220 ) ) {
V_226 = F_196 ( V_4 -> V_220 ) ;
V_4 -> V_220 = NULL ;
F_27 ( V_223 , L_99 ,
L_100 ,
F_197 ( V_227 , V_232 ) , V_226 ) ;
return V_226 ;
} else if ( V_227 != V_223 -> V_234 )
F_198 ( V_4 -> V_220 , V_223 -> V_15 ) ;
return 0 ;
}
V_4 -> V_224 = V_228 ;
V_4 -> V_220 = F_199 ( V_225 , V_228 , V_4 ) ;
if ( F_195 ( V_4 -> V_220 ) ) {
V_226 = F_196 ( V_4 -> V_220 ) ;
V_4 -> V_220 = NULL ;
F_27 ( V_223 ,
L_101 ,
V_225 , V_226 ) ;
return V_226 ;
}
F_198 ( V_4 -> V_220 , V_223 -> V_15 ) ;
F_185 ( V_223 ,
L_102 ,
V_4 -> V_220 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_148 ) {
int V_235 = 1 ;
if ( V_2 -> V_15 < V_236 )
V_235 = V_236 / V_2 -> V_15 ;
if ( V_4 -> V_148 > V_237 / V_235 ||
V_4 -> V_148 < V_238 / V_235 ||
F_111 ( V_2 ) / V_4 -> V_148 <
V_239 ) {
F_27 ( V_2 , L_103 ,
L_104
L_105 , V_4 -> V_148 ) ;
return 1 ;
}
if ( V_4 -> V_240 != ( V_4 -> V_148 ) *
V_241 / V_237 ) {
F_27 ( V_2 , L_106 ,
L_107
L_105 , V_4 -> V_240 ) ;
return 1 ;
}
} else {
if ( V_2 -> V_15 != V_236 ) {
F_27 ( V_2 , L_108 , L_109 ,
V_2 -> V_15 ) ;
return 1 ;
}
V_4 -> V_148 = V_237 ;
V_4 -> V_240 = V_241 ;
V_4 -> V_242 = V_243 ;
}
return 0 ;
}
int F_201 ( struct V_1 * V_2 , const char * V_244 ,
int V_245 , unsigned int V_246 )
{
int V_43 = F_111 ( V_2 ) * 2 ;
struct V_8 * V_247 ;
struct V_248 * V_249 ;
struct V_130 * V_83 ;
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
F_10 ( & V_4 -> V_250 ) ;
F_10 ( & V_4 -> V_137 ) ;
F_10 ( & V_4 -> V_67 ) ;
V_4 -> V_251 = 0 ;
if ( F_25 ( V_2 , V_4 -> V_42 ,
F_21 ( V_2 ) ) )
goto V_252;
F_17 ( V_2 ) ;
F_202 ( V_2 ) = ( V_245 ?
V_253
/ V_2 -> V_15 +
F_21 ( V_2 ) +
1 :
V_254 /
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
goto V_252;
}
if ( F_191 ( V_2 , V_4 , V_244 ) != 0 ) {
F_27 ( V_2 , L_103 ,
L_116 ) ;
goto V_252;
}
V_249 = F_203 ( V_2 ) ;
V_247 = F_171 ( V_2 ,
F_110 ( V_2 ) +
F_111 ( V_2 ) ) ;
if ( ! V_247 ) {
F_27 ( V_2 , L_117 ,
L_118 ) ;
goto V_252;
}
V_83 = (struct V_130 * ) ( V_247 -> V_134 ) ;
if ( F_204 ( V_249 )
&& ( F_178 ( V_83 -> V_255 . V_256 ) !=
F_205 ( V_249 ) ) ) {
F_27 ( V_2 , L_119 ,
L_120
L_121 ,
V_83 -> V_255 . V_256 ,
V_4 -> V_220 ,
F_205 ( V_249 ) ) ;
F_147 ( V_247 ) ;
goto V_252;
}
V_4 -> V_148 = F_178 ( V_83 -> V_255 . V_257 ) ;
V_4 -> V_240 = F_178 ( V_83 -> V_255 . V_258 ) ;
V_4 -> V_242 =
F_178 ( V_83 -> V_255 . V_259 ) ;
V_4 -> V_260 = V_261 ;
if ( F_200 ( V_2 , V_4 ) != 0 )
goto V_252;
V_4 -> V_262 = V_4 -> V_242 ;
if ( V_246 != 0 ) {
V_4 -> V_242 = V_246 ;
V_4 -> V_260 = V_246 ;
}
F_185 ( V_2 , L_122
L_123
L_124 ,
V_4 -> V_220 ,
F_111 ( V_2 ) ,
F_110 ( V_2 ) ,
V_4 -> V_148 ,
V_4 -> V_240 ,
V_4 -> V_242 , V_4 -> V_260 ) ;
F_147 ( V_247 ) ;
V_4 -> V_41 = 0 ;
F_189 ( V_2 ) ;
memset ( V_4 -> V_58 , 0 ,
V_6 * sizeof( struct V_7 * ) ) ;
F_10 ( & V_4 -> V_263 ) ;
F_206 ( & V_4 -> V_87 ) ;
V_4 -> V_117 = 0 ;
V_4 -> V_114 = 0 ;
V_4 -> V_264 = 0 ;
F_109 ( & V_4 -> V_146 , 0 ) ;
F_109 ( & V_4 -> V_106 , 0 ) ;
V_4 -> V_265 = 0 ;
V_4 -> V_266 = 0 ;
V_4 -> V_267 = NULL ;
V_4 -> V_268 = NULL ;
F_207 ( & V_4 -> V_269 ) ;
F_188 ( & V_4 -> V_62 ) ;
F_188 ( & V_4 -> V_147 ) ;
V_4 -> V_65 = 10 ;
V_4 -> V_135 = 10 ;
V_4 -> V_151 = 0 ;
F_109 ( & V_4 -> V_270 , 0 ) ;
V_4 -> V_49 = F_30 ( V_43 ) ;
V_4 -> V_175 = V_4 -> V_49 ;
V_4 -> V_47 = V_4 -> V_49 ? V_43 : 0 ;
V_4 -> V_48 = 0 ;
V_4 -> V_271 = 0 ;
if ( V_4 -> V_47 == 0 ) {
F_27 ( V_2 , L_125 , L_126
L_127
L_128
L_129 ,
sizeof ( struct V_7 ) * V_43 ) ;
goto V_252;
}
F_1 ( V_2 ) ;
V_39 = V_4 -> V_89 ;
F_159 ( V_2 ) ;
V_39 -> V_42 = F_28 ( V_2 , V_39 ) ;
F_156 ( V_2 ) ;
if ( ! V_39 -> V_42 ) {
F_27 ( V_2 , L_130 ,
L_131 ) ;
goto V_252;
}
V_80 = F_184 ( V_2 ) ;
if ( V_80 < 0 ) {
F_27 ( V_2 , L_132 ,
L_133 ) ;
goto V_252;
}
F_208 ( & V_4 -> V_184 , V_272 ) ;
V_4 -> V_273 = V_2 ;
return 0 ;
V_252:
F_146 ( V_2 ) ;
return 1 ;
}
int F_209 ( struct V_176 * V_177 ,
int V_274 )
{
struct V_3 * V_4 = F_2 ( V_177 -> V_275 ) ;
T_3 V_276 = F_186 () ;
F_80 ( ! V_177 -> V_182 ) ;
if ( V_177 -> V_277 > 1 )
return 0 ;
if ( V_4 -> V_271 > 0 ||
( V_4 -> V_264 + V_274 ) >= V_4 -> V_240 ||
F_87 ( & V_4 -> V_270 ) ||
( V_276 - V_4 -> V_266 ) > V_4 -> V_260 ||
V_4 -> V_47 < ( V_4 -> V_148 * 3 ) ) {
return 1 ;
}
V_4 -> V_264 += V_274 ;
V_177 -> V_278 += V_274 ;
return 0 ;
}
void F_210 ( struct V_176 * V_177 )
{
struct V_3 * V_4 = F_2 ( V_177 -> V_275 ) ;
F_80 ( ! V_177 -> V_182 ) ;
V_4 -> V_271 = 1 ;
F_19 ( V_279 , & V_4 -> V_151 ) ;
return;
}
void F_211 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_212 ( V_279 , & V_4 -> V_151 ) ;
F_213 ( & V_4 -> V_269 ) ;
}
void F_214 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_215 ( V_4 -> V_269 ,
! F_41 ( V_279 , & V_4 -> V_151 ) ) ;
}
static void F_216 ( struct V_1 * V_64 )
{
T_6 V_280 ;
struct V_3 * V_4 = F_2 ( V_64 ) ;
F_19 ( V_281 , & V_4 -> V_151 ) ;
F_217 ( & V_280 , V_282 ) ;
F_218 ( & V_4 -> V_269 , & V_280 ) ;
F_219 ( V_283 ) ;
if ( F_41 ( V_281 , & V_4 -> V_151 ) ) {
int V_107 = F_106 ( V_64 ) ;
F_220 () ;
F_108 ( V_64 , V_107 ) ;
}
F_221 ( V_284 ) ;
F_222 ( & V_4 -> V_269 , & V_280 ) ;
}
static void F_223 ( struct V_1 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 ) ;
if ( F_224 ( V_281 , & V_4 -> V_151 ) )
F_213 ( & V_4 -> V_269 ) ;
}
static void F_225 ( struct V_1 * V_2 , unsigned int V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_285 = V_4 -> V_265 ;
while ( 1 ) {
int V_107 ;
V_107 = F_106 ( V_2 ) ;
F_226 ( 1 ) ;
F_108 ( V_2 , V_107 ) ;
V_4 -> V_89 -> V_151 |= V_286 ;
while ( ( F_87 ( & V_4 -> V_146 ) > 0 ||
F_87 ( & V_4 -> V_270 ) ) &&
V_4 -> V_65 == V_66 ) {
F_216 ( V_2 ) ;
}
if ( V_4 -> V_65 != V_66 )
break;
if ( V_285 == V_4 -> V_265 )
break;
V_285 = V_4 -> V_265 ;
}
}
static int F_227 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_287 ,
int V_288 )
{
T_3 V_276 = F_186 () ;
unsigned int V_289 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_176 V_178 ;
int V_290 = 0 ;
int V_112 ;
int V_107 ;
F_32 ( V_2 , L_134 ) ;
F_80 ( V_287 > V_4 -> V_148 ) ;
F_40 ( V_2 , V_4 . V_291 ) ;
V_177 -> V_277 = 1 ;
V_177 -> V_275 = V_2 ;
V_292:
F_45 ( V_2 ) ;
if ( V_288 != V_293 && F_117 ( V_4 ) ) {
F_47 ( V_2 ) ;
V_112 = V_4 -> V_94 ;
goto V_294;
}
V_4 -> V_265 ++ ;
if ( F_41 ( V_279 , & V_4 -> V_151 ) ) {
F_47 ( V_2 ) ;
V_107 = F_106 ( V_2 ) ;
F_214 ( V_2 ) ;
F_108 ( V_2 , V_107 ) ;
F_40 ( V_2 , V_4 . V_295 ) ;
goto V_292;
}
V_276 = F_186 () ;
if ( ( ! V_288 && V_4 -> V_271 > 0 ) ||
( ! V_288
&& ( V_4 -> V_264 + V_287 + 2 ) >= V_4 -> V_240 )
|| ( ! V_288 && F_87 ( & V_4 -> V_146 ) > 0
&& V_4 -> V_266 > 0
&& ( V_276 - V_4 -> V_266 ) >
V_4 -> V_260 ) || ( ! V_288
&& F_87 ( & V_4 -> V_270 ) )
|| ( ! V_288 && V_4 -> V_47 < ( V_4 -> V_148 * 3 ) ) ) {
V_289 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
if ( ! V_288 && ( V_4 -> V_264 + V_287 + 2 ) >=
V_4 -> V_240 &&
( ( V_4 -> V_114 + V_287 + 2 ) * 100 ) <
( V_4 -> V_264 * 75 ) ) {
if ( F_87 ( & V_4 -> V_146 ) > 10 ) {
V_290 ++ ;
F_216 ( V_2 ) ;
goto V_292;
}
}
if ( F_87 ( & V_4 -> V_270 ) ) {
while ( V_4 -> V_65 == V_289 &&
F_87 ( & V_4 -> V_270 ) ) {
F_216 ( V_2 ) ;
}
goto V_292;
}
V_112 = F_151 ( & V_178 , V_2 ) ;
if ( V_112 )
goto V_294;
if ( V_289 != V_4 -> V_65 ) {
V_112 = F_150 ( & V_178 , 0 ) ;
} else {
V_112 = F_150 ( & V_178 , V_296 ) ;
}
if ( V_112 )
goto V_294;
F_40 ( V_2 , V_4 . V_297 ) ;
goto V_292;
}
if ( V_4 -> V_266 == 0 ) {
V_4 -> V_266 = F_186 () ;
}
F_84 ( & V_4 -> V_146 ) ;
V_4 -> V_264 += V_287 ;
V_177 -> V_298 = 0 ;
V_177 -> V_278 = V_287 ;
V_177 -> V_182 = V_4 -> V_65 ;
F_47 ( V_2 ) ;
F_10 ( & V_177 -> V_299 ) ;
return 0 ;
V_294:
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_177 -> V_275 = V_2 ;
return V_112 ;
}
struct V_176 * F_228 ( struct
V_1
* V_64 ,
int V_287 )
{
int V_80 ;
struct V_176 * V_177 ;
if ( F_229 ( V_64 ) ) {
V_177 = V_282 -> V_300 ;
V_177 -> V_277 ++ ;
F_80 ( V_177 -> V_277 < 2 ) ;
return V_177 ;
}
V_177 = F_7 ( sizeof( struct V_176 ) , V_13 ) ;
if ( ! V_177 )
return NULL ;
V_80 = F_230 ( V_177 , V_64 , V_287 ) ;
if ( V_80 ) {
F_9 ( V_177 ) ;
return NULL ;
}
F_2 ( V_64 ) -> V_251 ++ ;
return V_177 ;
}
int F_231 ( struct V_176 * V_177 )
{
struct V_1 * V_64 = V_177 -> V_275 ;
int V_80 = 0 ;
if ( V_177 -> V_182 )
V_80 = F_232 ( V_177 ) ;
else
V_80 = - V_97 ;
if ( V_177 -> V_277 == 0 ) {
F_2 ( V_64 ) -> V_251 -- ;
F_9 ( V_177 ) ;
}
return V_80 ;
}
static int F_151 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_176 * V_301 = V_282 -> V_300 ;
V_177 -> V_302 = V_301 ;
F_80 ( V_301 && V_301 -> V_277 > 1 ) ;
return F_227 ( V_177 , V_2 , 1 , V_303 ) ;
}
int F_155 ( struct V_176 * V_177 ,
struct V_1 * V_2 )
{
struct V_176 * V_301 = V_282 -> V_300 ;
V_177 -> V_302 = V_301 ;
F_80 ( V_301 && V_301 -> V_277 > 1 ) ;
return F_227 ( V_177 , V_2 , 1 , V_293 ) ;
}
int F_230 ( struct V_176 * V_177 ,
struct V_1 * V_2 , unsigned long V_287 )
{
struct V_176 * V_301 = V_282 -> V_300 ;
int V_80 ;
V_177 -> V_302 = NULL ;
if ( V_301 ) {
if ( V_301 -> V_275 == V_2 ) {
F_80 ( ! V_301 -> V_277 ) ;
V_301 -> V_277 ++ ;
memcpy ( V_177 , V_301 , sizeof( * V_177 ) ) ;
if ( V_177 -> V_277 <= 1 )
F_27 ( V_2 , L_135 ,
L_136
L_137 ) ;
return 0 ;
} else {
F_27 ( V_2 , L_138 ,
L_139 ) ;
V_177 -> V_302 = V_282 -> V_300 ;
V_282 -> V_300 = V_177 ;
}
} else {
V_282 -> V_300 = V_177 ;
}
V_80 = F_227 ( V_177 , V_2 , V_287 , V_304 ) ;
F_80 ( V_282 -> V_300 != V_177 ) ;
if ( V_80 )
V_282 -> V_300 = V_177 -> V_302 ;
else
F_80 ( ! V_177 -> V_277 ) ;
return V_80 ;
}
int F_154 ( struct V_176 * V_177 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_177 -> V_275 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
int V_305 = 0 ;
int V_306 = 0 ;
F_80 ( ! V_177 -> V_182 ) ;
F_40 ( V_2 , V_4 . V_307 ) ;
if ( V_177 -> V_182 != V_4 -> V_65 ) {
F_51 ( V_177 -> V_275 , L_140 ,
L_141 ,
V_177 -> V_182 , V_4 -> V_65 ) ;
}
V_306 = F_233 ( V_9 ) ;
F_36 ( V_9 ) ;
if ( F_64 ( V_9 ) ) {
F_40 ( V_2 , V_4 . V_308 ) ;
return 0 ;
}
if ( ! V_306 || F_96 ( V_9 ) ) {
F_27 ( V_2 , L_142 ,
L_143
L_144 ,
( unsigned long long ) V_9 -> V_72 ,
V_306 ? ' ' : '!' ,
F_101 ( V_9 ) ? ' ' : '!' ,
F_96 ( V_9 ) ? ' ' : '!' ,
F_135 ( V_9 ) ? ' ' : '!' ) ;
}
if ( F_87 ( & V_4 -> V_146 ) <= 0 ) {
F_27 ( V_2 , L_145 ,
L_146 ,
F_87 ( & V_4 -> V_146 ) ) ;
return 1 ;
}
if ( V_4 -> V_114 >= V_4 -> V_148 ) {
F_51 ( V_177 -> V_275 , L_147 ,
L_148 ,
V_4 -> V_114 ) ;
}
if ( F_135 ( V_9 ) ) {
V_305 = 1 ;
F_40 ( V_2 , V_4 . V_309 ) ;
F_234 ( V_9 ) ;
}
if ( V_4 -> V_114 > V_4 -> V_264 ) {
V_4 -> V_264 = V_4 -> V_114 + V_310 ;
}
F_235 ( V_9 ) ;
if ( ! V_46 ) {
V_46 = F_31 ( V_2 ) ;
if ( ! V_46 ) {
F_51 ( V_2 , L_149 , L_150 ) ;
}
if ( V_177 -> V_298 == V_177 -> V_278 ) {
V_177 -> V_278 += V_310 ;
V_4 -> V_264 += V_310 ;
}
V_177 -> V_298 ++ ;
V_4 -> V_114 ++ ;
V_46 -> V_9 = V_9 ;
V_46 -> V_52 = V_9 -> V_72 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_124 = NULL ;
F_44 ( V_4 -> V_5 , V_46 ) ;
if ( ! V_305 ) {
F_70 ( V_9 ) ;
}
}
V_46 -> V_20 = NULL ;
V_46 -> V_45 = V_4 -> V_267 ;
V_46 -> V_9 = V_9 ;
if ( V_4 -> V_267 ) {
V_4 -> V_267 -> V_20 = V_46 ;
V_4 -> V_267 = V_46 ;
} else {
V_4 -> V_268 = V_46 ;
V_4 -> V_267 = V_46 ;
}
F_236 ( V_2 ) ;
return 0 ;
}
int F_232 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = V_177 -> V_275 ;
if ( ! V_282 -> V_300 && V_177 -> V_277 > 1 )
F_27 ( V_2 , L_151 ,
L_152 , V_177 -> V_277 ) ;
if ( ! V_177 -> V_182 ) {
F_237 ( 1 ) ;
return - V_97 ;
}
V_177 -> V_277 -- ;
if ( V_177 -> V_277 > 0 ) {
struct V_176 * V_301 =
V_282 -> V_300 ;
F_80 ( V_301 -> V_275 != V_177 -> V_275 ) ;
if ( V_177 != V_301 ) {
memcpy ( V_282 -> V_300 , V_177 , sizeof( * V_177 ) ) ;
V_177 -> V_182 = 0 ;
}
return 0 ;
} else {
return F_150 ( V_177 , 0 ) ;
}
}
static int F_238 ( struct V_1 * V_2 ,
T_1 V_52 , int V_311 )
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
if ( V_46 == V_4 -> V_268 ) {
V_4 -> V_268 = V_46 -> V_20 ;
}
if ( V_46 == V_4 -> V_267 ) {
V_4 -> V_267 = V_46 -> V_45 ;
}
if ( V_9 )
F_126 ( V_2 , V_4 -> V_5 , NULL ,
V_9 -> V_72 , 0 ) ;
F_239 ( V_9 ) ;
if ( ! V_311 ) {
F_234 ( V_9 ) ;
F_4 ( V_9 ) ;
F_5 ( V_9 ) ;
F_59 ( V_9 ) ;
if ( F_87 ( & V_9 -> V_154 ) < 0 ) {
F_27 ( V_2 , L_153 ,
L_154 ) ;
}
V_80 = 1 ;
}
V_4 -> V_114 -- ;
V_4 -> V_264 -- ;
F_33 ( V_2 , V_46 ) ;
return V_80 ;
}
static int F_136 ( struct V_7 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
T_1 V_52 = V_46 -> V_52 ;
struct V_7 * V_173 = V_46 -> V_61 ;
int F_136 = 1 ;
while ( V_173 && F_136 ) {
if ( V_173 -> V_124 && V_173 -> V_9 && V_173 -> V_52 && V_173 -> V_2 == V_2 &&
V_173 -> V_52 == V_52 ) {
F_136 = 0 ;
}
V_173 = V_173 -> V_61 ;
}
V_173 = V_46 -> V_53 ;
while ( V_173 && F_136 ) {
if ( V_173 -> V_124 && V_173 -> V_124 -> V_114 > 0 &&
F_87 ( & V_173 -> V_124 -> V_105 ) > 0 && V_173 -> V_9 &&
V_173 -> V_52 && V_173 -> V_2 == V_2 && V_173 -> V_52 == V_52 ) {
F_136 = 0 ;
}
V_173 = V_173 -> V_53 ;
}
return F_136 ;
}
int F_240 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = V_177 -> V_275 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_80 ( ! V_177 -> V_182 ) ;
F_80 ( V_177 -> V_277 > 1 ) ;
if ( V_4 -> V_114 == 0 ) {
F_152 ( V_2 , F_153 ( V_2 ) ,
1 ) ;
F_154 ( V_177 , F_153 ( V_2 ) ) ;
}
return F_150 ( V_177 , V_296 | V_312 ) ;
}
static void V_272 ( struct V_313 * V_314 )
{
struct V_3 * V_4 =
F_241 ( V_314 , struct V_3 , V_184 . V_314 ) ;
struct V_1 * V_2 = V_4 -> V_273 ;
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
T_3 V_276 ;
struct V_176 V_177 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_276 = F_186 () ;
if ( F_54 ( & V_4 -> V_67 ) )
return;
if ( F_87 ( & V_4 -> V_146 ) <= 0 &&
V_4 -> V_266 > 0 &&
V_4 -> V_114 > 0 &&
( V_276 - V_4 -> V_266 ) > V_4 -> V_260 ) {
if ( ! F_151 ( & V_177 , V_2 ) ) {
F_152 ( V_2 ,
F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_177 , F_153 ( V_2 ) ) ;
F_150 ( & V_177 , V_296 | V_312 ) ;
}
}
}
static int F_243 ( struct V_176 * V_177 , int V_315 )
{
T_3 V_276 ;
int V_316 = V_315 & V_183 ;
int V_317 = V_315 & V_296 ;
int V_318 = V_315 & V_312 ;
struct V_38 * V_39 ;
struct V_1 * V_2 = V_177 -> V_275 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_80 ( ! V_177 -> V_182 ) ;
if ( V_177 -> V_182 != V_4 -> V_65 ) {
F_51 ( V_177 -> V_275 , L_140 ,
L_141 ,
V_177 -> V_182 , V_4 -> V_65 ) ;
}
V_4 -> V_264 -= ( V_177 -> V_278 - V_177 -> V_298 ) ;
if ( F_87 ( & V_4 -> V_146 ) > 0 )
F_88 ( & V_4 -> V_146 ) ;
F_80 ( V_4 -> V_114 == 0 ) ;
if ( F_87 ( & V_4 -> V_146 ) > 0 ) {
if ( V_316 || V_317 ) {
unsigned V_66 ;
V_39 = V_4 -> V_89 ;
V_66 = V_39 -> V_65 ;
if ( V_318 )
V_39 -> V_151 |= V_286 ;
F_109 ( & V_4 -> V_270 , 1 ) ;
if ( V_316 ) {
V_4 -> V_319 = 1 ;
}
F_47 ( V_2 ) ;
while ( V_4 -> V_65 == V_66 ) {
if ( F_87 ( & V_4 -> V_270 ) ) {
F_216 ( V_2 ) ;
} else {
F_45 ( V_2 ) ;
if ( V_4 -> V_65 == V_66 ) {
F_109 ( & V_4 -> V_270 ,
1 ) ;
}
F_47 ( V_2 ) ;
}
}
F_80 ( V_4 -> V_65 == V_66 ) ;
if ( V_317
&& F_53 ( V_2 , V_66 )
&& V_318 ) {
F_29 ( V_2 , V_39 , 1 ) ;
}
return 0 ;
}
F_47 ( V_2 ) ;
return 0 ;
}
V_276 = F_186 () ;
if ( ( V_276 - V_4 -> V_266 ) > V_4 -> V_260 ) {
V_317 = 1 ;
V_4 -> V_320 = 1 ;
}
if ( ! ( V_4 -> V_271 > 0 ) && ! ( F_87 ( & V_4 -> V_270 ) )
&& ! V_316 && ! V_317 && ( V_4 -> V_114 < V_4 -> V_240 )
&& V_4 -> V_264 < V_4 -> V_240
&& V_4 -> V_47 > ( V_4 -> V_148 * 3 ) ) {
V_4 -> V_265 ++ ;
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
int F_244 ( struct V_176 * V_177 ,
struct V_1 * V_2 , T_1 V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_28 * V_29 = NULL ;
int V_321 = 0 ;
F_80 ( ! V_177 -> V_182 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_5 , V_52 ) ;
if ( V_46 && V_46 -> V_9 ) {
V_9 = V_46 -> V_9 ;
F_70 ( V_9 ) ;
}
if ( V_9 && F_245 ( V_9 ) ) {
F_71 ( V_9 ) ;
F_34 ( V_9 ) ;
F_3 ( V_9 ) ;
V_321 = F_238 ( V_2 , V_52 , V_321 ) ;
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
V_321 = F_238 ( V_2 , V_52 , V_321 ) ;
V_46 = F_37 ( V_2 , V_4 -> V_58 ,
V_52 ) ;
while ( V_46 ) {
if ( V_2 == V_46 -> V_2 && V_52 == V_46 -> V_52 ) {
F_19 ( V_174 , & V_46 -> V_128 ) ;
if ( V_46 -> V_9 ) {
if ( ! V_321 ) {
F_234 ( V_46 ->
V_9 ) ;
F_4 ( V_46 -> V_9 ) ;
F_5 ( V_46 ->
V_9 ) ;
V_321 = 1 ;
F_59 ( V_46 -> V_9 ) ;
if ( F_87
( & V_46 -> V_9 -> V_154 ) < 0 ) {
F_27 ( V_2 ,
L_159 ,
L_160 ) ;
}
}
if ( V_46 -> V_124 ) {
F_88 ( & V_46 -> V_124 ->
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
void F_246 ( struct V_92 * V_92 )
{
struct V_3 * V_4 = F_2 ( V_92 -> V_93 ) ;
F_247 ( V_92 ) -> V_322 = V_4 -> V_89 ;
F_247 ( V_92 ) -> V_323 = V_4 -> V_65 ;
}
static int F_248 ( struct V_92 * V_92 , unsigned long V_12 ,
struct V_38 * V_39 )
{
struct V_176 V_177 ;
struct V_1 * V_2 = V_92 -> V_93 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_80 = 0 ;
if ( V_12 == V_4 -> V_65 ) {
V_39 = V_4 -> V_89 ;
F_225 ( V_2 , V_12 ) ;
if ( V_4 -> V_65 != V_12 ) {
goto V_324;
}
V_80 = F_230 ( & V_177 , V_2 , 1 ) ;
if ( V_80 )
return V_80 ;
if ( V_4 -> V_65 != V_12 ) {
F_152 ( V_2 , F_153 ( V_2 ) ,
1 ) ;
F_154 ( & V_177 , F_153 ( V_2 ) ) ;
V_80 = F_232 ( & V_177 ) ;
goto V_324;
}
V_80 = F_240 ( & V_177 ) ;
if ( ! V_80 )
V_80 = 1 ;
} else {
V_324:
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
unsigned int V_12 = F_247 ( V_92 ) -> V_323 ;
struct V_38 * V_39 = F_247 ( V_92 ) -> V_322 ;
if ( ! V_12 || ! V_39 ) {
F_246 ( V_92 ) ;
V_12 = F_247 ( V_92 ) -> V_323 ;
}
return F_248 ( V_92 , V_12 , V_39 ) ;
}
void F_250 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_40 ( V_2 , V_4 . V_325 ) ;
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
struct V_8 * V_9 , int V_280 )
{
F_40 ( V_2 , V_4 . V_326 ) ;
if ( ! F_95 ( V_9 ) ) {
if ( ! V_280 )
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
static int F_150 ( struct V_176 * V_177 , int V_315 )
{
struct V_1 * V_2 = V_177 -> V_275 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_46 , * V_20 , * V_327 ;
struct V_7 * V_328 = NULL ;
struct V_185 * V_186 ;
struct V_187 * V_188 ;
struct V_8 * V_192 ;
struct V_8 * V_189 ;
int V_329 = 0 ;
int V_330 ;
int V_25 ;
int V_316 ;
int V_318 ;
struct V_38 * V_39 , * V_331 ;
struct V_17 * V_18 , * V_332 ;
unsigned long V_333 ;
unsigned int V_334 ;
int V_203 ;
int V_107 ;
F_80 ( V_177 -> V_277 > 1 ) ;
F_80 ( ! V_177 -> V_182 ) ;
F_80 ( ! V_177 -> V_275 ) ;
if ( V_177 -> V_182 == ~ 0U )
V_315 |= V_183 | V_296 | V_312 ;
V_316 = V_315 & V_183 ;
V_318 = V_315 & V_312 ;
V_282 -> V_300 = V_177 -> V_302 ;
F_32 ( V_2 , L_161 ) ;
if ( V_4 -> V_114 == 0 ) {
F_152 ( V_2 , F_153 ( V_2 ) ,
1 ) ;
F_154 ( V_177 , F_153 ( V_2 ) ) ;
}
F_45 ( V_2 ) ;
if ( V_4 -> V_319 ) {
V_315 |= V_183 ;
V_316 = 1 ;
}
if ( V_4 -> V_320 ) {
V_315 |= V_296 | V_312 ;
V_318 = 1 ;
}
if ( ! F_243 ( V_177 , V_315 ) ) {
F_236 ( V_2 ) ;
F_223 ( V_2 ) ;
F_105 ( V_2 ) ;
goto V_335;
}
if ( V_4 -> V_319 ) {
V_316 = 1 ;
}
if ( V_4 -> V_271 > 0 ) {
V_316 = 1 ;
}
#ifdef F_254
V_282 -> V_300 = V_177 ;
V_177 -> V_277 ++ ;
F_255 ( V_177 ) ;
V_177 -> V_277 -- ;
V_282 -> V_300 = V_177 -> V_302 ;
#endif
V_189 =
F_176 ( V_2 ,
F_110 ( V_2 ) +
V_4 -> V_117 ) ;
F_65 ( V_189 ) ;
V_186 = (struct V_185 * ) ( V_189 ) -> V_134 ;
memset ( V_189 -> V_134 , 0 , V_189 -> V_208 ) ;
memcpy ( F_168 ( V_189 ) , V_193 , 8 ) ;
F_256 ( V_186 , V_4 -> V_65 ) ;
V_192 = F_176 ( V_2 , F_110 ( V_2 ) +
( ( V_4 -> V_117 + V_4 -> V_114 +
1 ) % F_111 ( V_2 ) ) ) ;
V_188 = (struct V_187 * ) V_192 -> V_134 ;
memset ( V_192 -> V_134 , 0 , V_192 -> V_208 ) ;
F_257 ( V_188 , V_4 -> V_65 ) ;
F_65 ( V_192 ) ;
V_39 = V_4 -> V_89 ;
F_46 ( & V_39 -> V_116 , V_2 ) ;
V_334 = V_39 -> V_65 ;
F_109 ( & V_39 -> V_104 , 0 ) ;
V_39 -> V_65 = V_4 -> V_65 ;
V_39 -> V_336 = V_4 -> V_266 ;
V_39 -> V_118 = V_192 ;
V_39 -> V_117 = V_4 -> V_117 ;
V_39 -> V_114 = V_4 -> V_114 ;
F_109 ( & V_39 -> V_149 , V_4 -> V_114 ) ;
F_109 ( & V_39 -> V_105 , V_4 -> V_114 + 2 ) ;
V_39 -> V_127 = NULL ;
V_203 = F_175 ( V_2 -> V_15 ) ;
for ( V_25 = 0 , V_46 = V_4 -> V_268 ; V_46 ; V_46 = V_46 -> V_20 , V_25 ++ ) {
if ( F_64 ( V_46 -> V_9 ) ) {
V_327 = F_31 ( V_2 ) ;
if ( ! V_327 ) {
F_51 ( V_2 , L_162 ,
L_163 ) ;
}
if ( V_25 == 0 ) {
V_39 -> V_127 = V_327 ;
}
V_327 -> V_45 = V_328 ;
V_327 -> V_20 = NULL ;
if ( V_328 ) {
V_328 -> V_20 = V_327 ;
}
V_328 = V_327 ;
if ( F_180
( V_2 , V_46 -> V_9 -> V_72 ) ) {
F_51 ( V_2 , L_164 ,
L_165
L_166 ,
V_46 -> V_9 -> V_72 ) ;
}
V_327 -> V_52 = V_46 -> V_9 -> V_72 ;
V_327 -> V_128 = 0 ;
V_327 -> V_2 = V_2 ;
V_327 -> V_9 = V_46 -> V_9 ;
V_327 -> V_124 = V_39 ;
F_44 ( V_4 -> V_58 , V_327 ) ;
if ( V_25 < V_203 ) {
V_186 -> V_127 [ V_25 ] =
F_128 ( V_46 -> V_9 -> V_72 ) ;
} else {
V_188 -> V_127 [ V_25 - V_203 ] =
F_128 ( V_46 -> V_9 -> V_72 ) ;
}
} else {
V_25 -- ;
}
}
F_258 ( V_186 , V_4 -> V_114 ) ;
F_259 ( V_186 , V_4 -> V_135 ) ;
F_256 ( V_186 , V_4 -> V_65 ) ;
F_260 ( V_188 , V_4 -> V_114 ) ;
F_80 ( V_4 -> V_114 == 0 ) ;
F_118 ( V_189 ) ;
V_329 = V_4 -> V_117 ;
V_46 = V_4 -> V_268 ;
V_333 = 1 ;
while ( V_46 ) {
F_71 ( V_46 -> V_9 ) ;
if ( F_64 ( V_46 -> V_9 ) ) {
struct V_8 * V_158 ;
char * V_337 ;
struct V_68 * V_68 ;
V_158 =
F_176 ( V_2 ,
F_110 ( V_2 ) +
( ( V_329 +
V_333 ) %
F_111 ( V_2 ) ) ) ;
F_65 ( V_158 ) ;
V_68 = V_46 -> V_9 -> V_69 ;
V_337 = F_261 ( V_68 ) ;
memcpy ( V_158 -> V_134 ,
V_337 + F_262 ( V_46 -> V_9 -> V_134 ) ,
V_46 -> V_9 -> V_208 ) ;
F_263 ( V_68 ) ;
F_118 ( V_158 ) ;
V_333 ++ ;
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
F_90 ( & V_39 -> V_137 , & V_4 -> V_137 ) ;
V_4 -> V_138 ++ ;
V_330 = V_4 -> V_117 ;
V_4 -> V_117 =
( V_4 -> V_117 + V_4 -> V_114 +
2 ) % F_111 ( V_2 ) ;
F_109 ( & V_4 -> V_146 , 0 ) ;
V_4 -> V_265 = 0 ;
V_4 -> V_267 = NULL ;
V_4 -> V_268 = NULL ;
V_4 -> V_114 = 0 ;
V_4 -> V_266 = 0 ;
if ( ++ V_4 -> V_65 == 0 )
V_4 -> V_65 = 10 ;
V_4 -> V_89 -> V_65 = V_4 -> V_65 ;
V_4 -> V_271 = 0 ;
V_4 -> V_264 = 0 ;
V_4 -> V_319 = 0 ;
V_4 -> V_320 = 0 ;
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
if ( V_316 ) {
F_29 ( V_2 , V_39 , 1 ) ;
F_132 ( V_2 , V_39 , 1 ) ;
} else if ( ! ( V_39 -> V_151 & V_286 ) ) {
if ( V_2 -> V_180 & V_338 )
F_267 ( F_268 ( V_2 ) -> V_339 ,
& V_4 -> V_184 , V_109 / 10 ) ;
}
V_99:
F_269 (entry, safe, &journal->j_journal_list) {
V_331 = F_55 ( V_18 ) ;
if ( V_4 -> V_117 <= V_331 -> V_117 ) {
if ( ( V_4 -> V_117 + V_4 -> V_148 + 1 ) >=
V_331 -> V_117 ) {
F_144 ( V_2 , V_331 ) ;
goto V_99;
} else if ( ( V_4 -> V_117 +
V_4 -> V_148 + 1 ) <
F_111 ( V_2 ) ) {
break;
}
} else if ( ( V_4 -> V_117 +
V_4 -> V_148 + 1 ) >
F_111 ( V_2 ) ) {
if ( ( ( V_4 -> V_117 + V_4 -> V_148 + 1 ) %
F_111 ( V_2 ) ) >=
V_331 -> V_117 ) {
F_144 ( V_2 , V_331 ) ;
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
F_109 ( & V_4 -> V_270 , 0 ) ;
F_47 ( V_2 ) ;
F_212 ( V_281 , & V_4 -> V_151 ) ;
F_213 ( & V_4 -> V_269 ) ;
if ( ! V_316 && V_318 &&
F_53 ( V_2 , V_334 ) ) {
F_29 ( V_2 , V_39 , 1 ) ;
}
V_335:
F_32 ( V_2 , L_172 ) ;
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_177 -> V_275 = V_2 ;
return V_4 -> V_94 ;
}
void F_270 ( struct V_1 * V_2 , int V_340 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_41 ( V_341 , & V_4 -> V_151 ) )
return;
if ( ! V_4 -> V_94 )
V_4 -> V_94 = V_340 ;
V_2 -> V_180 |= V_181 ;
F_19 ( V_341 , & V_4 -> V_151 ) ;
#ifdef F_115
F_271 () ;
#endif
}
