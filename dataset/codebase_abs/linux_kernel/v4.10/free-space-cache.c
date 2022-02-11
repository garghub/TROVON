static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 V_10 ;
struct V_9 V_11 ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_1 * V_1 = NULL ;
int V_18 ;
V_10 . V_19 = V_20 ;
V_10 . V_6 = V_6 ;
V_10 . type = 0 ;
V_18 = F_2 ( NULL , V_3 , & V_10 , V_5 , 0 , 0 ) ;
if ( V_18 < 0 )
return F_3 ( V_18 ) ;
if ( V_18 > 0 ) {
F_4 ( V_5 ) ;
return F_3 ( - V_21 ) ;
}
V_17 = V_5 -> V_22 [ 0 ] ;
V_15 = F_5 ( V_17 , V_5 -> V_23 [ 0 ] ,
struct V_14 ) ;
F_6 ( V_17 , V_15 , & V_13 ) ;
F_7 ( & V_11 , & V_13 ) ;
F_4 ( V_5 ) ;
V_1 = F_8 ( V_8 -> V_24 , & V_11 , V_3 , NULL ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
if ( F_10 ( V_1 ) ) {
F_11 ( V_1 ) ;
return F_3 ( - V_21 ) ;
}
F_12 ( V_1 -> V_25 ,
F_13 ( V_1 -> V_25 ,
~ ( V_26 | V_27 ) ) ) ;
return V_1 ;
}
struct V_1 * F_14 ( struct V_2 * V_3 ,
struct V_28
* V_29 , struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
struct V_7 * V_8 = V_3 -> V_8 ;
T_2 V_30 = V_31 | V_32 ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_1 )
V_1 = F_16 ( V_29 -> V_1 ) ;
F_17 ( & V_29 -> V_33 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 ,
V_29 -> V_10 . V_19 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_29 -> V_33 ) ;
if ( ! ( ( F_18 ( V_1 ) -> V_30 & V_30 ) == V_30 ) ) {
F_19 ( V_8 , L_1 ) ;
F_18 ( V_1 ) -> V_30 |= V_31 |
V_32 ;
V_29 -> V_34 = V_35 ;
}
if ( ! V_29 -> V_36 ) {
V_29 -> V_1 = F_16 ( V_1 ) ;
V_29 -> V_36 = 1 ;
}
F_17 ( & V_29 -> V_33 ) ;
return V_1 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_4 * V_5 ,
T_1 V_39 , T_1 V_6 )
{
struct V_9 V_10 ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_40 * V_41 ;
struct V_16 * V_17 ;
T_1 V_30 = V_42 | V_43 ;
int V_18 ;
V_18 = F_21 ( V_38 , V_3 , V_5 , V_39 ) ;
if ( V_18 )
return V_18 ;
if ( V_39 != V_44 )
V_30 |= V_31 | V_32 ;
V_17 = V_5 -> V_22 [ 0 ] ;
V_41 = F_5 ( V_17 , V_5 -> V_23 [ 0 ] ,
struct V_40 ) ;
F_22 ( V_17 , & V_13 , V_5 -> V_23 [ 0 ] ) ;
F_23 ( V_17 , ( unsigned long ) V_41 ,
sizeof( * V_41 ) ) ;
F_24 ( V_17 , V_41 , V_38 -> V_45 ) ;
F_25 ( V_17 , V_41 , 0 ) ;
F_26 ( V_17 , V_41 , 0 ) ;
F_27 ( V_17 , V_41 , 0 ) ;
F_28 ( V_17 , V_41 , 0 ) ;
F_29 ( V_17 , V_41 , V_46 | 0600 ) ;
F_30 ( V_17 , V_41 , V_30 ) ;
F_31 ( V_17 , V_41 , 1 ) ;
F_32 ( V_17 , V_41 , V_38 -> V_45 ) ;
F_33 ( V_17 , V_41 , V_6 ) ;
F_34 ( V_17 ) ;
F_4 ( V_5 ) ;
V_10 . V_19 = V_20 ;
V_10 . V_6 = V_6 ;
V_10 . type = 0 ;
V_18 = F_35 ( V_38 , V_3 , V_5 , & V_10 ,
sizeof( struct V_14 ) ) ;
if ( V_18 < 0 ) {
F_4 ( V_5 ) ;
return V_18 ;
}
V_17 = V_5 -> V_22 [ 0 ] ;
V_15 = F_5 ( V_17 , V_5 -> V_23 [ 0 ] ,
struct V_14 ) ;
F_23 ( V_17 , ( unsigned long ) V_15 , sizeof( * V_15 ) ) ;
F_36 ( V_17 , V_15 , & V_13 ) ;
F_34 ( V_17 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_28 * V_29 ,
struct V_4 * V_5 )
{
int V_18 ;
T_1 V_39 ;
V_18 = F_38 ( V_3 , & V_39 ) ;
if ( V_18 < 0 )
return V_18 ;
return F_20 ( V_3 , V_38 , V_5 , V_39 ,
V_29 -> V_10 . V_19 ) ;
}
int F_39 ( struct V_7 * V_8 ,
struct V_47 * V_48 )
{
T_1 V_49 ;
int V_18 ;
V_49 = F_40 ( V_8 , 1 ) +
F_41 ( V_8 , 1 ) ;
F_15 ( & V_48 -> V_33 ) ;
if ( V_48 -> V_50 < V_49 )
V_18 = - V_51 ;
else
V_18 = 0 ;
F_17 ( & V_48 -> V_33 ) ;
return V_18 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_28 * V_29 ,
struct V_1 * V_1 )
{
int V_18 = 0 ;
struct V_4 * V_5 = F_43 () ;
bool V_52 = false ;
if ( ! V_5 ) {
V_18 = - V_53 ;
goto V_54;
}
if ( V_29 ) {
V_52 = true ;
F_44 ( & V_38 -> V_55 -> V_56 ) ;
if ( ! F_45 ( & V_29 -> V_57 ) ) {
F_46 ( & V_29 -> V_57 ) ;
F_47 ( V_38 , V_29 , V_5 ) ;
F_48 ( V_29 ) ;
}
F_15 ( & V_29 -> V_33 ) ;
V_29 -> V_34 = V_35 ;
F_17 ( & V_29 -> V_33 ) ;
}
F_49 ( V_5 ) ;
F_50 ( V_1 , 0 ) ;
F_51 ( V_1 , 0 ) ;
V_18 = F_52 ( V_38 , V_3 , V_1 ,
0 , V_58 ) ;
if ( V_18 )
goto V_54;
V_18 = F_53 ( V_38 , V_3 , V_1 ) ;
V_54:
if ( V_52 )
F_54 ( & V_38 -> V_55 -> V_56 ) ;
if ( V_18 )
F_55 ( V_38 , V_18 ) ;
return V_18 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_59 * V_60 ;
unsigned long V_61 ;
V_60 = F_57 ( sizeof( * V_60 ) , V_62 ) ;
if ( ! V_60 )
return - V_53 ;
F_58 ( V_60 , V_1 -> V_25 ) ;
V_61 = ( F_59 ( V_1 ) - 1 ) >> V_63 ;
F_60 ( V_1 -> V_25 , V_60 , NULL , 0 , V_61 ) ;
F_61 ( V_60 ) ;
return 0 ;
}
static int F_62 ( struct V_64 * V_65 , struct V_1 * V_1 ,
int V_66 )
{
int V_67 ;
int V_68 = 0 ;
V_67 = F_63 ( F_59 ( V_1 ) , V_69 ) ;
if ( F_64 ( V_1 ) != V_44 )
V_68 = 1 ;
if ( V_66 && V_68 &&
( V_67 * sizeof( T_2 ) ) >= V_69 )
return - V_51 ;
memset ( V_65 , 0 , sizeof( struct V_64 ) ) ;
V_65 -> V_70 = F_65 ( V_67 , sizeof( struct V_71 * ) , V_62 ) ;
if ( ! V_65 -> V_70 )
return - V_53 ;
V_65 -> V_67 = V_67 ;
V_65 -> V_8 = F_66 ( V_1 -> V_72 ) ;
V_65 -> V_68 = V_68 ;
V_65 -> V_1 = V_1 ;
return 0 ;
}
static void F_67 ( struct V_64 * V_65 )
{
F_61 ( V_65 -> V_70 ) ;
V_65 -> V_70 = NULL ;
}
static void F_68 ( struct V_64 * V_65 )
{
if ( V_65 -> V_73 ) {
V_65 -> V_73 = NULL ;
V_65 -> V_74 = NULL ;
}
}
static void F_69 ( struct V_64 * V_65 , int V_75 )
{
ASSERT ( V_65 -> V_76 < V_65 -> V_67 ) ;
V_65 -> V_71 = V_65 -> V_70 [ V_65 -> V_76 ++ ] ;
V_65 -> V_73 = F_70 ( V_65 -> V_71 ) ;
V_65 -> V_74 = V_65 -> V_73 ;
V_65 -> V_77 = V_69 ;
if ( V_75 )
memset ( V_65 -> V_73 , 0 , V_69 ) ;
}
static void F_71 ( struct V_64 * V_65 )
{
int V_78 ;
F_68 ( V_65 ) ;
for ( V_78 = 0 ; V_78 < V_65 -> V_67 ; V_78 ++ ) {
if ( V_65 -> V_70 [ V_78 ] ) {
F_72 ( V_65 -> V_70 [ V_78 ] ) ;
F_73 ( V_65 -> V_70 [ V_78 ] ) ;
F_74 ( V_65 -> V_70 [ V_78 ] ) ;
}
}
}
static int F_75 ( struct V_64 * V_65 , struct V_1 * V_1 ,
int V_79 )
{
struct V_71 * V_71 ;
T_3 V_80 = F_76 ( V_1 -> V_25 ) ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_65 -> V_67 ; V_78 ++ ) {
V_71 = F_77 ( V_1 -> V_25 , V_78 , V_80 ) ;
if ( ! V_71 ) {
F_71 ( V_65 ) ;
return - V_53 ;
}
V_65 -> V_70 [ V_78 ] = V_71 ;
if ( V_79 && ! F_78 ( V_71 ) ) {
F_79 ( NULL , V_71 ) ;
F_80 ( V_71 ) ;
if ( ! F_78 ( V_71 ) ) {
F_81 ( F_18 ( V_1 ) -> V_3 -> V_8 ,
L_2 ) ;
F_71 ( V_65 ) ;
return - V_81 ;
}
}
}
for ( V_78 = 0 ; V_78 < V_65 -> V_67 ; V_78 ++ ) {
F_82 ( V_65 -> V_70 [ V_78 ] ) ;
F_83 ( V_65 -> V_70 [ V_78 ] ) ;
}
return 0 ;
}
static void F_84 ( struct V_64 * V_65 , T_1 V_82 )
{
T_4 * V_83 ;
F_69 ( V_65 , 1 ) ;
if ( V_65 -> V_68 ) {
V_65 -> V_73 += ( sizeof( T_2 ) * V_65 -> V_67 ) ;
V_65 -> V_77 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_65 -> V_67 ) ;
} else {
V_65 -> V_73 += sizeof( T_1 ) ;
V_65 -> V_77 -= sizeof( T_1 ) * 2 ;
}
V_83 = V_65 -> V_73 ;
* V_83 = F_85 ( V_82 ) ;
V_65 -> V_73 += sizeof( T_1 ) ;
}
static int F_86 ( struct V_64 * V_65 , T_1 V_82 )
{
T_4 * V_84 ;
if ( V_65 -> V_68 ) {
V_65 -> V_73 += sizeof( T_2 ) * V_65 -> V_67 ;
V_65 -> V_77 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_65 -> V_67 ) ;
} else {
V_65 -> V_73 += sizeof( T_1 ) ;
V_65 -> V_77 -= sizeof( T_1 ) * 2 ;
}
V_84 = V_65 -> V_73 ;
if ( F_87 ( * V_84 ) != V_82 ) {
F_88 ( V_65 -> V_8 ,
L_3 ,
* V_84 , V_82 ) ;
F_68 ( V_65 ) ;
return - V_81 ;
}
V_65 -> V_73 += sizeof( T_1 ) ;
return 0 ;
}
static void F_89 ( struct V_64 * V_65 , int V_76 )
{
T_2 * V_85 ;
T_2 V_86 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_65 -> V_68 ) {
F_68 ( V_65 ) ;
return;
}
if ( V_76 == 0 )
V_6 = sizeof( T_2 ) * V_65 -> V_67 ;
V_86 = F_90 ( V_65 -> V_74 + V_6 , V_86 ,
V_69 - V_6 ) ;
F_91 ( V_86 , ( V_87 * ) & V_86 ) ;
F_68 ( V_65 ) ;
V_85 = F_70 ( V_65 -> V_70 [ 0 ] ) ;
V_85 += V_76 ;
* V_85 = V_86 ;
}
static int F_92 ( struct V_64 * V_65 , int V_76 )
{
T_2 * V_85 , V_83 ;
T_2 V_86 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_65 -> V_68 ) {
F_69 ( V_65 , 0 ) ;
return 0 ;
}
if ( V_76 == 0 )
V_6 = sizeof( T_2 ) * V_65 -> V_67 ;
V_85 = F_70 ( V_65 -> V_70 [ 0 ] ) ;
V_85 += V_76 ;
V_83 = * V_85 ;
F_69 ( V_65 , 0 ) ;
V_86 = F_90 ( V_65 -> V_74 + V_6 , V_86 ,
V_69 - V_6 ) ;
F_91 ( V_86 , ( V_87 * ) & V_86 ) ;
if ( V_83 != V_86 ) {
F_88 ( V_65 -> V_8 ,
L_4 ) ;
F_68 ( V_65 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_93 ( struct V_64 * V_65 , T_1 V_6 , T_1 V_88 ,
void * V_89 )
{
struct V_90 * V_91 ;
if ( ! V_65 -> V_73 )
return - V_51 ;
V_91 = V_65 -> V_73 ;
V_91 -> V_6 = F_85 ( V_6 ) ;
V_91 -> V_88 = F_85 ( V_88 ) ;
V_91 -> type = ( V_89 ) ? V_92 :
V_93 ;
V_65 -> V_73 += sizeof( struct V_90 ) ;
V_65 -> V_77 -= sizeof( struct V_90 ) ;
if ( V_65 -> V_77 >= sizeof( struct V_90 ) )
return 0 ;
F_89 ( V_65 , V_65 -> V_76 - 1 ) ;
if ( V_65 -> V_76 >= V_65 -> V_67 )
return 0 ;
F_69 ( V_65 , 1 ) ;
return 0 ;
}
static int F_94 ( struct V_64 * V_65 , void * V_89 )
{
if ( ! V_65 -> V_73 )
return - V_51 ;
if ( V_65 -> V_73 != V_65 -> V_74 ) {
F_89 ( V_65 , V_65 -> V_76 - 1 ) ;
if ( V_65 -> V_76 >= V_65 -> V_67 )
return - V_51 ;
F_69 ( V_65 , 0 ) ;
}
memcpy ( V_65 -> V_73 , V_89 , V_69 ) ;
F_89 ( V_65 , V_65 -> V_76 - 1 ) ;
if ( V_65 -> V_76 < V_65 -> V_67 )
F_69 ( V_65 , 0 ) ;
return 0 ;
}
static void F_95 ( struct V_64 * V_65 )
{
if ( V_65 -> V_73 != V_65 -> V_74 )
F_89 ( V_65 , V_65 -> V_76 - 1 ) ;
else
F_68 ( V_65 ) ;
while ( V_65 -> V_76 < V_65 -> V_67 ) {
F_69 ( V_65 , 1 ) ;
F_89 ( V_65 , V_65 -> V_76 - 1 ) ;
}
}
static int F_96 ( struct V_64 * V_65 ,
struct V_94 * V_91 , V_87 * type )
{
struct V_90 * V_95 ;
int V_18 ;
if ( ! V_65 -> V_73 ) {
V_18 = F_92 ( V_65 , V_65 -> V_76 ) ;
if ( V_18 )
return V_18 ;
}
V_95 = V_65 -> V_73 ;
V_91 -> V_6 = F_87 ( V_95 -> V_6 ) ;
V_91 -> V_88 = F_87 ( V_95 -> V_88 ) ;
* type = V_95 -> type ;
V_65 -> V_73 += sizeof( struct V_90 ) ;
V_65 -> V_77 -= sizeof( struct V_90 ) ;
if ( V_65 -> V_77 >= sizeof( struct V_90 ) )
return 0 ;
F_68 ( V_65 ) ;
return 0 ;
}
static int F_97 ( struct V_64 * V_65 ,
struct V_94 * V_91 )
{
int V_18 ;
V_18 = F_92 ( V_65 , V_65 -> V_76 ) ;
if ( V_18 )
return V_18 ;
memcpy ( V_91 -> V_89 , V_65 -> V_73 , V_69 ) ;
F_68 ( V_65 ) ;
return 0 ;
}
static void F_98 ( struct V_96 * V_97 )
{
struct V_94 * V_95 , * V_98 = NULL ;
struct V_99 * V_100 ;
V_101:
F_15 ( & V_97 -> V_102 ) ;
for ( V_100 = F_99 ( & V_97 -> V_103 ) ; V_100 ; V_100 = F_100 ( V_100 ) ) {
V_95 = F_101 ( V_100 , struct V_94 , V_104 ) ;
if ( ! V_98 )
goto V_105;
if ( V_95 -> V_89 || V_98 -> V_89 )
goto V_105;
if ( V_98 -> V_6 + V_98 -> V_88 == V_95 -> V_6 ) {
F_102 ( V_97 , V_98 ) ;
F_102 ( V_97 , V_95 ) ;
V_98 -> V_88 += V_95 -> V_88 ;
F_103 ( V_106 , V_95 ) ;
F_104 ( V_97 , V_98 ) ;
V_98 = NULL ;
F_17 ( & V_97 -> V_102 ) ;
goto V_101;
}
V_105:
V_98 = V_95 ;
}
F_17 ( & V_97 -> V_102 ) ;
}
static int F_105 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_96 * V_97 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_66 ( V_1 -> V_72 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_64 V_65 ;
struct V_9 V_10 ;
struct V_94 * V_95 , * V_100 ;
F_106 ( V_107 ) ;
T_1 V_108 ;
T_1 V_109 ;
T_1 V_82 ;
V_87 type ;
int V_18 = 0 ;
if ( ! F_59 ( V_1 ) )
return 0 ;
V_10 . V_19 = V_20 ;
V_10 . V_6 = V_6 ;
V_10 . type = 0 ;
V_18 = F_2 ( NULL , V_3 , & V_10 , V_5 , 0 , 0 ) ;
if ( V_18 < 0 )
return 0 ;
else if ( V_18 > 0 ) {
F_4 ( V_5 ) ;
return 0 ;
}
V_18 = - 1 ;
V_17 = V_5 -> V_22 [ 0 ] ;
V_15 = F_5 ( V_17 , V_5 -> V_23 [ 0 ] ,
struct V_14 ) ;
V_108 = F_107 ( V_17 , V_15 ) ;
V_109 = F_108 ( V_17 , V_15 ) ;
V_82 = F_109 ( V_17 , V_15 ) ;
F_4 ( V_5 ) ;
if ( ! F_18 ( V_1 ) -> V_82 ) {
F_19 ( V_8 ,
L_5 ,
V_6 ) ;
return 0 ;
}
if ( F_18 ( V_1 ) -> V_82 != V_82 ) {
F_81 ( V_8 ,
L_6 ,
F_18 ( V_1 ) -> V_82 , V_82 ) ;
return 0 ;
}
if ( ! V_108 )
return 0 ;
V_18 = F_62 ( & V_65 , V_1 , 0 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_56 ( V_1 ) ;
if ( V_18 )
goto V_110;
V_18 = F_75 ( & V_65 , V_1 , 1 ) ;
if ( V_18 )
goto V_110;
V_18 = F_92 ( & V_65 , 0 ) ;
if ( V_18 )
goto V_111;
V_18 = F_86 ( & V_65 , V_82 ) ;
if ( V_18 )
goto V_111;
while ( V_108 ) {
V_95 = F_110 ( V_106 ,
V_62 ) ;
if ( ! V_95 )
goto V_111;
V_18 = F_96 ( & V_65 , V_95 , & type ) ;
if ( V_18 ) {
F_103 ( V_106 , V_95 ) ;
goto V_111;
}
if ( ! V_95 -> V_88 ) {
F_103 ( V_106 , V_95 ) ;
goto V_111;
}
if ( type == V_93 ) {
F_15 ( & V_97 -> V_102 ) ;
V_18 = F_104 ( V_97 , V_95 ) ;
F_17 ( & V_97 -> V_102 ) ;
if ( V_18 ) {
F_81 ( V_8 ,
L_7 ) ;
F_103 ( V_106 , V_95 ) ;
goto V_111;
}
} else {
ASSERT ( V_109 ) ;
V_109 -- ;
V_95 -> V_89 = F_57 ( V_69 , V_62 ) ;
if ( ! V_95 -> V_89 ) {
F_103 (
V_106 , V_95 ) ;
goto V_111;
}
F_15 ( & V_97 -> V_102 ) ;
V_18 = F_104 ( V_97 , V_95 ) ;
V_97 -> V_112 ++ ;
V_97 -> V_113 -> V_114 ( V_97 ) ;
F_17 ( & V_97 -> V_102 ) ;
if ( V_18 ) {
F_81 ( V_8 ,
L_7 ) ;
F_103 ( V_106 , V_95 ) ;
goto V_111;
}
F_111 ( & V_95 -> V_115 , & V_107 ) ;
}
V_108 -- ;
}
F_68 ( & V_65 ) ;
F_112 (e, n, &bitmaps, list) {
F_46 ( & V_95 -> V_115 ) ;
V_18 = F_97 ( & V_65 , V_95 ) ;
if ( V_18 )
goto V_111;
}
F_71 ( & V_65 ) ;
F_98 ( V_97 ) ;
V_18 = 1 ;
V_110:
F_67 ( & V_65 ) ;
return V_18 ;
V_111:
F_71 ( & V_65 ) ;
F_113 ( V_97 ) ;
goto V_110;
}
int F_114 ( struct V_7 * V_8 ,
struct V_28 * V_29 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_2 * V_3 = V_8 -> V_117 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_18 = 0 ;
bool V_118 ;
T_1 V_119 = F_115 ( & V_29 -> V_120 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_34 != V_121 ) {
F_17 ( & V_29 -> V_33 ) ;
return 0 ;
}
F_17 ( & V_29 -> V_33 ) ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_122 = 1 ;
V_5 -> V_123 = 1 ;
V_1 = F_14 ( V_3 , V_29 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_49 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_34 != V_121 ) {
F_17 ( & V_29 -> V_33 ) ;
F_49 ( V_5 ) ;
goto V_110;
}
F_17 ( & V_29 -> V_33 ) ;
V_18 = F_105 ( V_8 -> V_117 , V_1 , V_97 ,
V_5 , V_29 -> V_10 . V_19 ) ;
F_49 ( V_5 ) ;
if ( V_18 <= 0 )
goto V_110;
F_15 ( & V_97 -> V_102 ) ;
V_118 = ( V_97 -> V_124 == ( V_29 -> V_10 . V_6 - V_119 -
V_29 -> V_125 ) ) ;
F_17 ( & V_97 -> V_102 ) ;
if ( ! V_118 ) {
F_113 ( V_97 ) ;
F_116 ( V_8 ,
L_8 ,
V_29 -> V_10 . V_19 ) ;
V_18 = - 1 ;
}
V_110:
if ( V_18 < 0 ) {
F_15 ( & V_29 -> V_33 ) ;
V_29 -> V_34 = V_35 ;
F_17 ( & V_29 -> V_33 ) ;
V_18 = 0 ;
F_116 ( V_8 ,
L_9 ,
V_29 -> V_10 . V_19 ) ;
}
F_11 ( V_1 ) ;
return V_18 ;
}
static T_5
int F_117 ( struct V_64 * V_65 ,
struct V_96 * V_97 ,
struct V_28 * V_29 ,
int * V_126 , int * V_107 ,
struct V_127 * V_128 )
{
int V_18 ;
struct V_129 * V_130 = NULL ;
struct V_129 * V_131 = NULL ;
struct V_99 * V_132 = F_99 ( & V_97 -> V_103 ) ;
struct V_133 * V_134 ;
if ( V_29 && ! F_45 ( & V_29 -> V_135 ) ) {
V_130 = F_118 ( V_29 -> V_135 . V_105 ,
struct V_129 ,
V_136 ) ;
}
if ( ! V_132 && V_130 ) {
V_131 = V_130 ;
F_15 ( & V_131 -> V_33 ) ;
V_132 = F_99 ( & V_130 -> V_3 ) ;
V_130 = NULL ;
}
while ( V_132 ) {
struct V_94 * V_95 ;
V_95 = F_101 ( V_132 , struct V_94 , V_104 ) ;
* V_126 += 1 ;
V_18 = F_93 ( V_65 , V_95 -> V_6 , V_95 -> V_88 ,
V_95 -> V_89 ) ;
if ( V_18 )
goto V_54;
if ( V_95 -> V_89 ) {
F_111 ( & V_95 -> V_115 , V_128 ) ;
* V_107 += 1 ;
}
V_132 = F_100 ( V_132 ) ;
if ( ! V_132 && V_130 ) {
V_132 = F_99 ( & V_130 -> V_3 ) ;
V_131 = V_130 ;
F_15 ( & V_131 -> V_33 ) ;
V_130 = NULL ;
}
}
if ( V_131 ) {
F_17 ( & V_131 -> V_33 ) ;
V_131 = NULL ;
}
F_119 (trim_entry, &ctl->trimming_ranges, list) {
V_18 = F_93 ( V_65 , V_134 -> V_137 ,
V_134 -> V_88 , NULL ) ;
if ( V_18 )
goto V_54;
* V_126 += 1 ;
}
return 0 ;
V_54:
if ( V_131 )
F_17 ( & V_131 -> V_33 ) ;
return - V_51 ;
}
static T_5 int
F_120 ( struct V_37 * V_38 ,
struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 , T_1 V_6 ,
int V_126 , int V_107 )
{
struct V_9 V_10 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_10 . V_19 = V_20 ;
V_10 . V_6 = V_6 ;
V_10 . type = 0 ;
V_18 = F_2 ( V_38 , V_3 , & V_10 , V_5 , 0 , 1 ) ;
if ( V_18 < 0 ) {
F_121 ( & F_18 ( V_1 ) -> V_138 , 0 , V_1 -> V_139 - 1 ,
V_140 | V_141 , 0 , 0 , NULL ,
V_62 ) ;
goto V_54;
}
V_17 = V_5 -> V_22 [ 0 ] ;
if ( V_18 > 0 ) {
struct V_9 V_142 ;
ASSERT ( V_5 -> V_23 [ 0 ] ) ;
V_5 -> V_23 [ 0 ] -- ;
F_122 ( V_17 , & V_142 , V_5 -> V_23 [ 0 ] ) ;
if ( V_142 . V_19 != V_20 ||
V_142 . V_6 != V_6 ) {
F_121 ( & F_18 ( V_1 ) -> V_138 , 0 ,
V_1 -> V_139 - 1 ,
V_140 | V_141 , 0 , 0 ,
NULL , V_62 ) ;
F_4 ( V_5 ) ;
goto V_54;
}
}
F_18 ( V_1 ) -> V_82 = V_38 -> V_45 ;
V_15 = F_5 ( V_17 , V_5 -> V_23 [ 0 ] ,
struct V_14 ) ;
F_123 ( V_17 , V_15 , V_126 ) ;
F_124 ( V_17 , V_15 , V_107 ) ;
F_125 ( V_17 , V_15 , V_38 -> V_45 ) ;
F_34 ( V_17 ) ;
F_4 ( V_5 ) ;
return 0 ;
V_54:
return - 1 ;
}
static T_5 int
F_126 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
struct V_64 * V_65 ,
int * V_126 )
{
T_1 V_137 , V_143 , V_144 , V_145 ;
struct V_146 * V_147 = NULL ;
int V_18 ;
if ( ! V_29 )
return 0 ;
V_147 = V_8 -> V_148 ;
V_137 = V_29 -> V_10 . V_19 ;
while ( V_137 < V_29 -> V_10 . V_19 + V_29 -> V_10 . V_6 ) {
V_18 = F_127 ( V_147 , V_137 ,
& V_143 , & V_144 ,
V_140 , NULL ) ;
if ( V_18 )
return 0 ;
if ( V_143 >= V_29 -> V_10 . V_19 +
V_29 -> V_10 . V_6 )
return 0 ;
V_143 = F_128 ( V_143 , V_137 ) ;
V_144 = F_129 ( V_29 -> V_10 . V_19 +
V_29 -> V_10 . V_6 , V_144 + 1 ) ;
V_145 = V_144 - V_143 ;
* V_126 += 1 ;
V_18 = F_93 ( V_65 , V_143 , V_145 , NULL ) ;
if ( V_18 )
return - V_51 ;
V_137 = V_144 ;
}
return 0 ;
}
static T_5 int
F_130 ( struct V_64 * V_65 , struct V_127 * V_128 )
{
struct V_94 * V_91 , * V_105 ;
int V_18 ;
F_112 (entry, next, bitmap_list, list) {
V_18 = F_94 ( V_65 , V_91 -> V_89 ) ;
if ( V_18 )
return - V_51 ;
F_46 ( & V_91 -> V_115 ) ;
}
return 0 ;
}
static int F_131 ( struct V_1 * V_1 )
{
int V_18 ;
V_18 = F_132 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_18 )
F_121 ( & F_18 ( V_1 ) -> V_138 , 0 , V_1 -> V_139 - 1 ,
V_140 | V_141 , 0 , 0 , NULL ,
V_62 ) ;
return V_18 ;
}
static void T_5
F_133 ( struct V_127 * V_128 )
{
struct V_94 * V_91 , * V_105 ;
F_112 (entry, next, bitmap_list, list)
F_46 ( & V_91 -> V_115 ) ;
}
static void T_5
F_134 ( struct V_1 * V_1 ,
struct V_64 * V_65 ,
struct V_149 * * V_150 ,
struct V_127 * V_128 )
{
F_71 ( V_65 ) ;
F_135 ( & F_18 ( V_1 ) -> V_138 , 0 ,
F_59 ( V_1 ) - 1 , V_150 ,
V_62 ) ;
}
static int F_136 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_28 * V_29 ,
struct V_64 * V_65 ,
struct V_4 * V_5 , T_1 V_6 )
{
int V_18 ;
struct V_1 * V_1 = V_65 -> V_1 ;
struct V_7 * V_8 ;
if ( ! V_1 )
return 0 ;
V_8 = F_66 ( V_1 -> V_72 ) ;
V_18 = F_131 ( V_1 ) ;
if ( V_18 )
goto V_110;
V_18 = F_120 ( V_38 , V_3 , V_1 , V_5 , V_6 ,
V_65 -> V_126 , V_65 -> V_107 ) ;
V_110:
F_67 ( V_65 ) ;
if ( V_18 ) {
F_137 ( V_1 -> V_25 ) ;
F_18 ( V_1 ) -> V_82 = 0 ;
if ( V_29 ) {
#ifdef F_138
F_81 ( V_8 ,
L_10 ,
V_29 -> V_10 . V_19 ) ;
#endif
}
}
F_53 ( V_38 , V_3 , V_1 ) ;
if ( V_29 ) {
F_15 ( & V_38 -> V_55 -> V_151 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( ! V_18 && F_45 ( & V_29 -> V_152 ) )
V_29 -> V_34 = V_121 ;
else if ( V_18 )
V_29 -> V_34 = V_153 ;
F_17 ( & V_29 -> V_33 ) ;
F_17 ( & V_38 -> V_55 -> V_151 ) ;
V_65 -> V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_18 ;
}
static int F_139 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_64 * V_65 ,
struct V_4 * V_5 )
{
return F_136 ( V_3 , V_38 , NULL , V_65 , V_5 , 0 ) ;
}
int F_47 ( struct V_37 * V_38 ,
struct V_28 * V_29 ,
struct V_4 * V_5 )
{
return F_136 ( V_29 -> V_8 -> V_117 , V_38 ,
V_29 , & V_29 -> V_65 ,
V_5 , V_29 -> V_10 . V_19 ) ;
}
static int F_140 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_96 * V_97 ,
struct V_28 * V_29 ,
struct V_64 * V_65 ,
struct V_37 * V_38 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_149 * V_150 = NULL ;
F_106 ( V_128 ) ;
int V_126 = 0 ;
int V_107 = 0 ;
int V_18 ;
int V_154 = 0 ;
if ( ! F_59 ( V_1 ) )
return - V_81 ;
F_141 ( V_65 -> V_70 ) ;
V_18 = F_62 ( V_65 , V_1 , 1 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 && ( V_29 -> V_30 & V_155 ) ) {
F_142 ( & V_29 -> V_156 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_157 ) {
V_29 -> V_34 = V_121 ;
F_17 ( & V_29 -> V_33 ) ;
F_143 ( & V_29 -> V_156 ) ;
F_18 ( V_1 ) -> V_82 = 0 ;
V_18 = 0 ;
V_154 = 1 ;
goto V_110;
}
F_17 ( & V_29 -> V_33 ) ;
}
V_18 = F_75 ( V_65 , V_1 , 0 ) ;
if ( V_18 )
goto V_110;
F_144 ( & F_18 ( V_1 ) -> V_138 , 0 , F_59 ( V_1 ) - 1 ,
& V_150 ) ;
F_84 ( V_65 , V_38 -> V_45 ) ;
F_44 ( & V_97 -> V_158 ) ;
F_15 ( & V_97 -> V_102 ) ;
V_18 = F_117 ( V_65 , V_97 ,
V_29 , & V_126 , & V_107 ,
& V_128 ) ;
if ( V_18 )
goto V_159;
V_18 = F_126 ( V_8 , V_29 ,
V_65 , & V_126 ) ;
if ( V_18 )
goto V_159;
V_18 = F_130 ( V_65 , & V_128 ) ;
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
if ( V_18 )
goto V_160;
F_95 ( V_65 ) ;
V_18 = F_145 ( V_1 , V_65 -> V_70 , V_65 -> V_67 , 0 ,
F_59 ( V_1 ) , & V_150 ) ;
if ( V_18 )
goto V_160;
if ( V_29 && ( V_29 -> V_30 & V_155 ) )
F_143 ( & V_29 -> V_156 ) ;
F_71 ( V_65 ) ;
F_135 ( & F_18 ( V_1 ) -> V_138 , 0 ,
F_59 ( V_1 ) - 1 , & V_150 , V_62 ) ;
V_65 -> V_126 = V_126 ;
V_65 -> V_107 = V_107 ;
V_18 = F_146 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_18 )
goto V_110;
return 0 ;
V_110:
V_65 -> V_1 = NULL ;
F_67 ( V_65 ) ;
if ( V_18 ) {
F_137 ( V_1 -> V_25 ) ;
F_18 ( V_1 ) -> V_82 = 0 ;
}
F_53 ( V_38 , V_3 , V_1 ) ;
if ( V_154 )
F_11 ( V_1 ) ;
return V_18 ;
V_159:
F_133 ( & V_128 ) ;
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
V_160:
F_134 ( V_1 , V_65 , & V_150 , & V_128 ) ;
if ( V_29 && ( V_29 -> V_30 & V_155 ) )
F_143 ( & V_29 -> V_156 ) ;
goto V_110;
}
int F_147 ( struct V_7 * V_8 ,
struct V_37 * V_38 ,
struct V_28 * V_29 ,
struct V_4 * V_5 )
{
struct V_2 * V_3 = V_8 -> V_117 ;
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_1 * V_1 ;
int V_18 = 0 ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_34 < V_161 ) {
F_17 ( & V_29 -> V_33 ) ;
return 0 ;
}
F_17 ( & V_29 -> V_33 ) ;
V_1 = F_14 ( V_3 , V_29 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_18 = F_140 ( V_3 , V_1 , V_97 , V_29 ,
& V_29 -> V_65 , V_38 ,
V_5 , V_29 -> V_10 . V_19 ) ;
if ( V_18 ) {
#ifdef F_138
F_81 ( V_8 ,
L_10 ,
V_29 -> V_10 . V_19 ) ;
#endif
F_15 ( & V_29 -> V_33 ) ;
V_29 -> V_34 = V_153 ;
F_17 ( & V_29 -> V_33 ) ;
V_29 -> V_65 . V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_18 ;
}
static inline unsigned long F_148 ( T_1 V_162 , T_2 V_163 ,
T_1 V_6 )
{
ASSERT ( V_6 >= V_162 ) ;
V_6 -= V_162 ;
return ( unsigned long ) ( F_149 ( V_6 , V_163 ) ) ;
}
static inline unsigned long F_150 ( T_1 V_88 , T_2 V_163 )
{
return ( unsigned long ) ( F_149 ( V_88 , V_163 ) ) ;
}
static inline T_1 F_151 ( struct V_96 * V_97 ,
T_1 V_6 )
{
T_1 V_162 ;
T_1 V_164 ;
V_164 = V_165 * V_97 -> V_163 ;
V_162 = V_6 - V_97 -> V_137 ;
V_162 = F_152 ( V_162 , V_164 ) ;
V_162 *= V_164 ;
V_162 += V_97 -> V_137 ;
return V_162 ;
}
static int F_153 ( struct V_166 * V_3 , T_1 V_6 ,
struct V_99 * V_132 , int V_89 )
{
struct V_99 * * V_167 = & V_3 -> V_99 ;
struct V_99 * V_168 = NULL ;
struct V_94 * V_169 ;
while ( * V_167 ) {
V_168 = * V_167 ;
V_169 = F_101 ( V_168 , struct V_94 , V_104 ) ;
if ( V_6 < V_169 -> V_6 ) {
V_167 = & ( * V_167 ) -> V_170 ;
} else if ( V_6 > V_169 -> V_6 ) {
V_167 = & ( * V_167 ) -> V_171 ;
} else {
if ( V_89 ) {
if ( V_169 -> V_89 ) {
F_154 ( 1 ) ;
return - V_172 ;
}
V_167 = & ( * V_167 ) -> V_171 ;
} else {
if ( ! V_169 -> V_89 ) {
F_154 ( 1 ) ;
return - V_172 ;
}
V_167 = & ( * V_167 ) -> V_170 ;
}
}
}
F_155 ( V_132 , V_168 , V_167 ) ;
F_156 ( V_132 , V_3 ) ;
return 0 ;
}
static struct V_94 *
F_157 ( struct V_96 * V_97 ,
T_1 V_6 , int V_173 , int V_174 )
{
struct V_99 * V_100 = V_97 -> V_103 . V_99 ;
struct V_94 * V_91 , * V_98 = NULL ;
while ( 1 ) {
if ( ! V_100 ) {
V_91 = NULL ;
break;
}
V_91 = F_101 ( V_100 , struct V_94 , V_104 ) ;
V_98 = V_91 ;
if ( V_6 < V_91 -> V_6 )
V_100 = V_100 -> V_170 ;
else if ( V_6 > V_91 -> V_6 )
V_100 = V_100 -> V_171 ;
else
break;
}
if ( V_173 ) {
if ( ! V_91 )
return NULL ;
if ( V_91 -> V_89 )
return V_91 ;
V_100 = F_100 ( V_100 ) ;
if ( ! V_100 )
return NULL ;
V_91 = F_101 ( V_100 , struct V_94 , V_104 ) ;
if ( V_91 -> V_6 != V_6 )
return NULL ;
F_141 ( ! V_91 -> V_89 ) ;
return V_91 ;
} else if ( V_91 ) {
if ( V_91 -> V_89 ) {
V_100 = F_158 ( & V_91 -> V_104 ) ;
if ( V_100 ) {
V_98 = F_101 ( V_100 , struct V_94 ,
V_104 ) ;
if ( ! V_98 -> V_89 &&
V_98 -> V_6 + V_98 -> V_88 > V_6 )
V_91 = V_98 ;
}
}
return V_91 ;
}
if ( ! V_98 )
return NULL ;
V_91 = V_98 ;
if ( V_91 -> V_6 > V_6 ) {
V_100 = F_158 ( & V_91 -> V_104 ) ;
if ( V_100 ) {
V_91 = F_101 ( V_100 , struct V_94 ,
V_104 ) ;
ASSERT ( V_91 -> V_6 <= V_6 ) ;
} else {
if ( V_174 )
return V_91 ;
else
return NULL ;
}
}
if ( V_91 -> V_89 ) {
V_100 = F_158 ( & V_91 -> V_104 ) ;
if ( V_100 ) {
V_98 = F_101 ( V_100 , struct V_94 ,
V_104 ) ;
if ( ! V_98 -> V_89 &&
V_98 -> V_6 + V_98 -> V_88 > V_6 )
return V_98 ;
}
if ( V_91 -> V_6 + V_165 * V_97 -> V_163 > V_6 )
return V_91 ;
} else if ( V_91 -> V_6 + V_91 -> V_88 > V_6 )
return V_91 ;
if ( ! V_174 )
return NULL ;
while ( 1 ) {
if ( V_91 -> V_89 ) {
if ( V_91 -> V_6 + V_165 *
V_97 -> V_163 > V_6 )
break;
} else {
if ( V_91 -> V_6 + V_91 -> V_88 > V_6 )
break;
}
V_100 = F_100 ( & V_91 -> V_104 ) ;
if ( ! V_100 )
return NULL ;
V_91 = F_101 ( V_100 , struct V_94 , V_104 ) ;
}
return V_91 ;
}
static inline void
F_159 ( struct V_96 * V_97 ,
struct V_94 * V_169 )
{
F_160 ( & V_169 -> V_104 , & V_97 -> V_103 ) ;
V_97 -> V_175 -- ;
}
static void F_102 ( struct V_96 * V_97 ,
struct V_94 * V_169 )
{
F_159 ( V_97 , V_169 ) ;
V_97 -> V_124 -= V_169 -> V_88 ;
}
static int F_104 ( struct V_96 * V_97 ,
struct V_94 * V_169 )
{
int V_18 = 0 ;
ASSERT ( V_169 -> V_88 || V_169 -> V_89 ) ;
V_18 = F_153 ( & V_97 -> V_103 , V_169 -> V_6 ,
& V_169 -> V_104 , ( V_169 -> V_89 != NULL ) ) ;
if ( V_18 )
return V_18 ;
V_97 -> V_124 += V_169 -> V_88 ;
V_97 -> V_175 ++ ;
return V_18 ;
}
static void F_161 ( struct V_96 * V_97 )
{
struct V_28 * V_29 = V_97 -> V_176 ;
T_1 V_177 ;
T_1 V_178 ;
T_1 V_179 ;
T_1 V_77 = V_29 -> V_10 . V_6 ;
T_1 V_180 = V_165 * V_97 -> V_163 ;
T_1 V_181 = F_152 ( V_77 + V_180 - 1 , V_180 ) ;
V_181 = F_162 ( T_1 , V_181 , 1 ) ;
ASSERT ( V_97 -> V_112 <= V_181 ) ;
if ( V_77 < V_182 )
V_177 = V_183 ;
else
V_177 = V_183 * F_149 ( V_77 , V_182 ) ;
V_178 = ( V_97 -> V_112 + 1 ) * V_97 -> V_163 ;
if ( V_178 >= V_177 ) {
V_97 -> V_184 = 0 ;
return;
}
V_179 = V_177 - V_178 ;
V_179 = F_163 ( T_1 , V_179 , V_177 >> 1 ) ;
V_97 -> V_184 =
F_149 ( V_179 , sizeof( struct V_94 ) ) ;
}
static inline void F_164 ( struct V_96 * V_97 ,
struct V_94 * V_169 ,
T_1 V_6 , T_1 V_88 )
{
unsigned long V_137 , V_185 ;
V_137 = F_148 ( V_169 -> V_6 , V_97 -> V_163 , V_6 ) ;
V_185 = F_150 ( V_88 , V_97 -> V_163 ) ;
ASSERT ( V_137 + V_185 <= V_165 ) ;
F_165 ( V_169 -> V_89 , V_137 , V_185 ) ;
V_169 -> V_88 -= V_88 ;
}
static void F_166 ( struct V_96 * V_97 ,
struct V_94 * V_169 , T_1 V_6 ,
T_1 V_88 )
{
F_164 ( V_97 , V_169 , V_6 , V_88 ) ;
V_97 -> V_124 -= V_88 ;
}
static void F_167 ( struct V_96 * V_97 ,
struct V_94 * V_169 , T_1 V_6 ,
T_1 V_88 )
{
unsigned long V_137 , V_185 ;
V_137 = F_148 ( V_169 -> V_6 , V_97 -> V_163 , V_6 ) ;
V_185 = F_150 ( V_88 , V_97 -> V_163 ) ;
ASSERT ( V_137 + V_185 <= V_165 ) ;
F_168 ( V_169 -> V_89 , V_137 , V_185 ) ;
V_169 -> V_88 += V_88 ;
V_97 -> V_124 += V_88 ;
}
static int F_169 ( struct V_96 * V_97 ,
struct V_94 * V_186 , T_1 * V_6 ,
T_1 * V_88 , bool V_187 )
{
unsigned long V_188 = 0 ;
unsigned long V_189 = 0 ;
unsigned long V_190 , V_78 ;
unsigned long V_191 ;
unsigned long V_192 ;
if ( V_187 &&
V_186 -> V_193 &&
V_186 -> V_193 < * V_88 ) {
* V_88 = V_186 -> V_193 ;
return - 1 ;
}
V_78 = F_148 ( V_186 -> V_6 , V_97 -> V_163 ,
F_162 ( T_1 , * V_6 , V_186 -> V_6 ) ) ;
V_190 = F_150 ( * V_88 , V_97 -> V_163 ) ;
F_170 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
if ( V_187 && V_190 == 1 ) {
V_188 = 1 ;
break;
}
V_191 = F_171 ( V_186 -> V_89 ,
V_165 , V_78 ) ;
V_192 = V_191 - V_78 ;
if ( V_192 >= V_190 ) {
V_188 = V_192 ;
break;
} else if ( V_192 > V_189 ) {
V_189 = V_192 ;
}
V_78 = V_191 ;
}
if ( V_188 ) {
* V_6 = ( T_1 ) ( V_78 * V_97 -> V_163 ) + V_186 -> V_6 ;
* V_88 = ( T_1 ) ( V_188 ) * V_97 -> V_163 ;
return 0 ;
}
* V_88 = ( T_1 ) ( V_189 ) * V_97 -> V_163 ;
V_186 -> V_193 = * V_88 ;
return - 1 ;
}
static struct V_94 *
F_172 ( struct V_96 * V_97 , T_1 * V_6 , T_1 * V_88 ,
unsigned long V_194 , T_1 * V_193 )
{
struct V_94 * V_91 ;
struct V_99 * V_132 ;
T_1 V_85 ;
T_1 V_195 ;
int V_18 ;
if ( ! V_97 -> V_103 . V_99 )
goto V_110;
V_91 = F_157 ( V_97 , F_151 ( V_97 , * V_6 ) , 0 , 1 ) ;
if ( ! V_91 )
goto V_110;
for ( V_132 = & V_91 -> V_104 ; V_132 ; V_132 = F_100 ( V_132 ) ) {
V_91 = F_101 ( V_132 , struct V_94 , V_104 ) ;
if ( V_91 -> V_88 < * V_88 ) {
if ( V_91 -> V_88 > * V_193 )
* V_193 = V_91 -> V_88 ;
continue;
}
if ( * V_88 >= V_194 ) {
V_85 = V_91 -> V_6 - V_97 -> V_137 + V_194 - 1 ;
V_85 = F_152 ( V_85 , V_194 ) ;
V_85 = V_85 * V_194 + V_97 -> V_137 ;
V_195 = V_85 - V_91 -> V_6 ;
} else {
V_195 = 0 ;
V_85 = V_91 -> V_6 ;
}
if ( V_91 -> V_88 < * V_88 + V_195 ) {
if ( V_91 -> V_88 > * V_193 )
* V_193 = V_91 -> V_88 ;
continue;
}
if ( V_91 -> V_89 ) {
T_1 V_77 = * V_88 ;
V_18 = F_169 ( V_97 , V_91 , & V_85 , & V_77 , true ) ;
if ( ! V_18 ) {
* V_6 = V_85 ;
* V_88 = V_77 ;
return V_91 ;
} else if ( V_77 > * V_193 ) {
* V_193 = V_77 ;
}
continue;
}
* V_6 = V_85 ;
* V_88 = V_91 -> V_88 - V_195 ;
return V_91 ;
}
V_110:
return NULL ;
}
static void F_173 ( struct V_96 * V_97 ,
struct V_94 * V_169 , T_1 V_6 )
{
V_169 -> V_6 = F_151 ( V_97 , V_6 ) ;
V_169 -> V_88 = 0 ;
F_174 ( & V_169 -> V_115 ) ;
F_104 ( V_97 , V_169 ) ;
V_97 -> V_112 ++ ;
V_97 -> V_113 -> V_114 ( V_97 ) ;
}
static void F_175 ( struct V_96 * V_97 ,
struct V_94 * V_186 )
{
F_102 ( V_97 , V_186 ) ;
F_61 ( V_186 -> V_89 ) ;
F_103 ( V_106 , V_186 ) ;
V_97 -> V_112 -- ;
V_97 -> V_113 -> V_114 ( V_97 ) ;
}
static T_6 int F_176 ( struct V_96 * V_97 ,
struct V_94 * V_186 ,
T_1 * V_6 , T_1 * V_88 )
{
T_1 V_196 ;
T_1 V_197 , V_198 ;
int V_18 ;
V_101:
V_196 = V_186 -> V_6 + ( T_1 ) ( V_165 * V_97 -> V_163 ) - 1 ;
V_197 = * V_6 ;
V_198 = V_97 -> V_163 ;
V_198 = F_129 ( V_198 , V_196 - V_197 + 1 ) ;
V_18 = F_169 ( V_97 , V_186 , & V_197 , & V_198 ,
false ) ;
if ( V_18 < 0 || V_197 != * V_6 )
return - V_199 ;
V_198 = F_129 ( V_198 , * V_88 ) ;
V_198 = F_129 ( V_198 , V_196 - V_197 + 1 ) ;
F_166 ( V_97 , V_186 , V_197 , V_198 ) ;
* V_6 += V_198 ;
* V_88 -= V_198 ;
if ( * V_88 ) {
struct V_99 * V_105 = F_100 ( & V_186 -> V_104 ) ;
if ( ! V_186 -> V_88 )
F_175 ( V_97 , V_186 ) ;
if ( ! V_105 )
return - V_199 ;
V_186 = F_101 ( V_105 , struct V_94 ,
V_104 ) ;
if ( ! V_186 -> V_89 )
return - V_200 ;
V_197 = * V_6 ;
V_198 = V_97 -> V_163 ;
V_18 = F_169 ( V_97 , V_186 , & V_197 ,
& V_198 , false ) ;
if ( V_18 < 0 || V_197 != * V_6 )
return - V_200 ;
goto V_101;
} else if ( ! V_186 -> V_88 )
F_175 ( V_97 , V_186 ) ;
return 0 ;
}
static T_1 F_177 ( struct V_96 * V_97 ,
struct V_94 * V_169 , T_1 V_6 ,
T_1 V_88 )
{
T_1 V_201 = 0 ;
T_1 V_196 ;
V_196 = V_169 -> V_6 + ( T_1 ) ( V_165 * V_97 -> V_163 ) ;
V_201 = F_129 ( V_196 - V_6 , V_88 ) ;
F_167 ( V_97 , V_169 , V_6 , V_201 ) ;
V_169 -> V_193 = 0 ;
return V_201 ;
}
static bool F_178 ( struct V_96 * V_97 ,
struct V_94 * V_169 )
{
struct V_28 * V_29 = V_97 -> V_176 ;
struct V_7 * V_8 = V_29 -> V_8 ;
bool V_202 = false ;
#ifdef F_179
if ( F_180 ( V_29 ) )
V_202 = true ;
#endif
if ( ! V_202 && V_97 -> V_175 < V_97 -> V_184 ) {
if ( V_169 -> V_88 <= V_8 -> V_203 * 4 ) {
if ( V_97 -> V_175 * 2 <= V_97 -> V_184 )
return false ;
} else {
return false ;
}
}
if ( ( ( V_165 * V_97 -> V_163 ) >> 1 ) > V_29 -> V_10 . V_6 )
return false ;
return true ;
}
static int F_181 ( struct V_96 * V_97 ,
struct V_94 * V_169 )
{
struct V_94 * V_186 ;
struct V_28 * V_29 = NULL ;
int V_204 = 0 ;
T_1 V_88 , V_6 , V_205 ;
int V_18 ;
V_88 = V_169 -> V_88 ;
V_6 = V_169 -> V_6 ;
if ( ! V_97 -> V_113 -> F_178 ( V_97 , V_169 ) )
return 0 ;
if ( V_97 -> V_113 == & V_206 )
V_29 = V_97 -> V_176 ;
V_101:
if ( V_29 && ! F_45 ( & V_29 -> V_135 ) ) {
struct V_129 * V_130 ;
struct V_99 * V_132 ;
struct V_94 * V_91 ;
V_130 = F_118 ( V_29 -> V_135 . V_105 ,
struct V_129 ,
V_136 ) ;
F_15 ( & V_130 -> V_33 ) ;
V_132 = F_99 ( & V_130 -> V_3 ) ;
if ( ! V_132 ) {
F_17 ( & V_130 -> V_33 ) ;
goto V_207;
}
V_91 = F_101 ( V_132 , struct V_94 , V_104 ) ;
if ( ! V_91 -> V_89 ) {
F_17 ( & V_130 -> V_33 ) ;
goto V_207;
}
if ( V_91 -> V_6 == F_151 ( V_97 , V_6 ) ) {
V_205 = F_177 ( V_97 , V_91 ,
V_6 , V_88 ) ;
V_88 -= V_205 ;
V_6 += V_205 ;
}
F_17 ( & V_130 -> V_33 ) ;
if ( ! V_88 ) {
V_18 = 1 ;
goto V_110;
}
}
V_207:
V_186 = F_157 ( V_97 , F_151 ( V_97 , V_6 ) ,
1 , 0 ) ;
if ( ! V_186 ) {
ASSERT ( V_204 == 0 ) ;
goto V_208;
}
V_205 = F_177 ( V_97 , V_186 , V_6 , V_88 ) ;
V_88 -= V_205 ;
V_6 += V_205 ;
V_204 = 0 ;
if ( ! V_88 ) {
V_18 = 1 ;
goto V_110;
} else
goto V_101;
V_208:
if ( V_169 && V_169 -> V_89 ) {
F_173 ( V_97 , V_169 , V_6 ) ;
V_204 = 1 ;
V_169 = NULL ;
goto V_101;
} else {
F_17 ( & V_97 -> V_102 ) ;
if ( ! V_169 ) {
V_169 = F_110 ( V_106 ,
V_62 ) ;
if ( ! V_169 ) {
F_15 ( & V_97 -> V_102 ) ;
V_18 = - V_53 ;
goto V_110;
}
}
V_169 -> V_89 = F_57 ( V_69 , V_62 ) ;
F_15 ( & V_97 -> V_102 ) ;
if ( ! V_169 -> V_89 ) {
V_18 = - V_53 ;
goto V_110;
}
goto V_101;
}
V_110:
if ( V_169 ) {
if ( V_169 -> V_89 )
F_61 ( V_169 -> V_89 ) ;
F_103 ( V_106 , V_169 ) ;
}
return V_18 ;
}
static bool F_182 ( struct V_96 * V_97 ,
struct V_94 * V_169 , bool V_209 )
{
struct V_94 * V_210 ;
struct V_94 * V_211 ;
bool V_212 = false ;
T_1 V_6 = V_169 -> V_6 ;
T_1 V_88 = V_169 -> V_88 ;
V_211 = F_157 ( V_97 , V_6 + V_88 , 0 , 0 ) ;
if ( V_211 && F_158 ( & V_211 -> V_104 ) )
V_210 = F_101 ( F_158 ( & V_211 -> V_104 ) ,
struct V_94 , V_104 ) ;
else
V_210 = F_157 ( V_97 , V_6 - 1 , 0 , 0 ) ;
if ( V_211 && ! V_211 -> V_89 ) {
if ( V_209 )
F_102 ( V_97 , V_211 ) ;
else
F_159 ( V_97 , V_211 ) ;
V_169 -> V_88 += V_211 -> V_88 ;
F_103 ( V_106 , V_211 ) ;
V_212 = true ;
}
if ( V_210 && ! V_210 -> V_89 &&
V_210 -> V_6 + V_210 -> V_88 == V_6 ) {
if ( V_209 )
F_102 ( V_97 , V_210 ) ;
else
F_159 ( V_97 , V_210 ) ;
V_169 -> V_6 = V_210 -> V_6 ;
V_169 -> V_88 += V_210 -> V_88 ;
F_103 ( V_106 , V_210 ) ;
V_212 = true ;
}
return V_212 ;
}
static bool F_183 ( struct V_96 * V_97 ,
struct V_94 * V_169 ,
bool V_209 )
{
struct V_94 * V_89 ;
unsigned long V_78 ;
unsigned long V_213 ;
const T_1 V_196 = V_169 -> V_6 + V_169 -> V_88 ;
const T_1 V_214 = F_151 ( V_97 , V_196 ) ;
T_1 V_88 ;
V_89 = F_157 ( V_97 , V_214 , 1 , 0 ) ;
if ( ! V_89 )
return false ;
V_78 = F_148 ( V_89 -> V_6 , V_97 -> V_163 , V_196 ) ;
V_213 = F_171 ( V_89 -> V_89 , V_165 , V_78 ) ;
if ( V_213 == V_78 )
return false ;
V_88 = ( V_213 - V_78 ) * V_97 -> V_163 ;
V_169 -> V_88 += V_88 ;
if ( V_209 )
F_166 ( V_97 , V_89 , V_196 , V_88 ) ;
else
F_164 ( V_97 , V_89 , V_196 , V_88 ) ;
if ( ! V_89 -> V_88 )
F_175 ( V_97 , V_89 ) ;
return true ;
}
static bool F_184 ( struct V_96 * V_97 ,
struct V_94 * V_169 ,
bool V_209 )
{
struct V_94 * V_89 ;
T_1 V_214 ;
unsigned long V_78 ;
unsigned long V_213 ;
unsigned long V_215 ;
T_1 V_88 ;
V_214 = F_151 ( V_97 , V_169 -> V_6 ) ;
if ( V_214 == V_169 -> V_6 ) {
if ( V_169 -> V_6 == 0 )
return false ;
V_214 = F_151 ( V_97 , V_169 -> V_6 - 1 ) ;
}
V_89 = F_157 ( V_97 , V_214 , 1 , 0 ) ;
if ( ! V_89 )
return false ;
V_78 = F_148 ( V_89 -> V_6 , V_97 -> V_163 , V_169 -> V_6 ) - 1 ;
V_213 = 0 ;
V_215 = ( unsigned long ) - 1 ;
F_185 (j, bitmap->bitmap, BITS_PER_BITMAP) {
if ( V_213 > V_78 )
break;
V_215 = V_213 ;
}
if ( V_215 == V_78 )
return false ;
if ( V_215 == ( unsigned long ) - 1 )
V_88 = ( V_78 + 1 ) * V_97 -> V_163 ;
else
V_88 = ( V_78 - V_215 ) * V_97 -> V_163 ;
V_169 -> V_6 -= V_88 ;
V_169 -> V_88 += V_88 ;
if ( V_209 )
F_166 ( V_97 , V_89 , V_169 -> V_6 , V_88 ) ;
else
F_164 ( V_97 , V_89 , V_169 -> V_6 , V_88 ) ;
if ( ! V_89 -> V_88 )
F_175 ( V_97 , V_89 ) ;
return true ;
}
static void F_186 ( struct V_96 * V_97 ,
struct V_94 * V_169 ,
bool V_209 )
{
ASSERT ( ! V_169 -> V_89 ) ;
ASSERT ( F_187 ( & V_169 -> V_104 ) ) ;
if ( V_97 -> V_112 > 0 ) {
bool V_216 ;
bool V_217 = false ;
V_216 = F_183 ( V_97 , V_169 , V_209 ) ;
if ( V_97 -> V_112 > 0 )
V_217 = F_184 ( V_97 , V_169 ,
V_209 ) ;
if ( V_216 || V_217 )
F_182 ( V_97 , V_169 , V_209 ) ;
}
}
int F_188 ( struct V_7 * V_8 ,
struct V_96 * V_97 ,
T_1 V_6 , T_1 V_88 )
{
struct V_94 * V_169 ;
int V_18 = 0 ;
V_169 = F_110 ( V_106 , V_62 ) ;
if ( ! V_169 )
return - V_53 ;
V_169 -> V_6 = V_6 ;
V_169 -> V_88 = V_88 ;
F_189 ( & V_169 -> V_104 ) ;
F_15 ( & V_97 -> V_102 ) ;
if ( F_182 ( V_97 , V_169 , true ) )
goto V_218;
V_18 = F_181 ( V_97 , V_169 ) ;
if ( V_18 < 0 ) {
goto V_110;
} else if ( V_18 ) {
V_18 = 0 ;
goto V_110;
}
V_218:
F_186 ( V_97 , V_169 , true ) ;
V_18 = F_104 ( V_97 , V_169 ) ;
if ( V_18 )
F_103 ( V_106 , V_169 ) ;
V_110:
F_17 ( & V_97 -> V_102 ) ;
if ( V_18 ) {
F_190 ( V_8 , L_11 , V_18 ) ;
ASSERT ( V_18 != - V_172 ) ;
}
return V_18 ;
}
int F_191 ( struct V_28 * V_29 ,
T_1 V_6 , T_1 V_88 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_169 ;
int V_18 ;
bool V_219 = false ;
F_15 ( & V_97 -> V_102 ) ;
V_101:
V_18 = 0 ;
if ( ! V_88 )
goto V_220;
V_169 = F_157 ( V_97 , V_6 , 0 , 0 ) ;
if ( ! V_169 ) {
V_169 = F_157 ( V_97 , F_151 ( V_97 , V_6 ) ,
1 , 0 ) ;
if ( ! V_169 ) {
F_141 ( V_219 ) ;
goto V_220;
}
}
V_219 = false ;
if ( ! V_169 -> V_89 ) {
F_102 ( V_97 , V_169 ) ;
if ( V_6 == V_169 -> V_6 ) {
T_1 V_221 = F_129 ( V_88 , V_169 -> V_88 ) ;
V_169 -> V_88 -= V_221 ;
V_169 -> V_6 += V_221 ;
if ( V_169 -> V_88 ) {
V_18 = F_104 ( V_97 , V_169 ) ;
F_141 ( V_18 ) ;
} else {
F_103 ( V_106 , V_169 ) ;
}
V_6 += V_221 ;
V_88 -= V_221 ;
goto V_101;
} else {
T_1 V_222 = V_169 -> V_88 + V_169 -> V_6 ;
V_169 -> V_88 = V_6 - V_169 -> V_6 ;
V_18 = F_104 ( V_97 , V_169 ) ;
F_141 ( V_18 ) ;
if ( V_18 )
goto V_220;
if ( V_222 < V_6 + V_88 ) {
V_88 -= V_222 - V_6 ;
V_6 = V_222 ;
goto V_101;
} else if ( V_222 == V_6 + V_88 ) {
goto V_220;
}
F_17 ( & V_97 -> V_102 ) ;
V_18 = F_192 ( V_29 , V_6 + V_88 ,
V_222 - ( V_6 + V_88 ) ) ;
F_141 ( V_18 ) ;
goto V_110;
}
}
V_18 = F_176 ( V_97 , V_169 , & V_6 , & V_88 ) ;
if ( V_18 == - V_200 ) {
V_219 = true ;
goto V_101;
}
V_220:
F_17 ( & V_97 -> V_102 ) ;
V_110:
return V_18 ;
}
void F_193 ( struct V_28 * V_29 ,
T_1 V_88 )
{
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_169 ;
struct V_99 * V_100 ;
int V_185 = 0 ;
for ( V_100 = F_99 ( & V_97 -> V_103 ) ; V_100 ; V_100 = F_100 ( V_100 ) ) {
V_169 = F_101 ( V_100 , struct V_94 , V_104 ) ;
if ( V_169 -> V_88 >= V_88 && ! V_29 -> V_223 )
V_185 ++ ;
F_190 ( V_8 , L_12 ,
V_169 -> V_6 , V_169 -> V_88 ,
( V_169 -> V_89 ) ? L_13 : L_14 ) ;
}
F_19 ( V_8 , L_15 ,
F_45 ( & V_29 -> V_135 ) ? L_14 : L_13 ) ;
F_19 ( V_8 ,
L_16 , V_185 ) ;
}
void F_194 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_96 * V_97 = V_29 -> V_116 ;
F_195 ( & V_97 -> V_102 ) ;
V_97 -> V_163 = V_8 -> V_203 ;
V_97 -> V_137 = V_29 -> V_10 . V_19 ;
V_97 -> V_176 = V_29 ;
V_97 -> V_113 = & V_206 ;
F_174 ( & V_97 -> V_224 ) ;
F_196 ( & V_97 -> V_158 ) ;
V_97 -> V_184 = ( V_225 / 2 ) / sizeof( struct V_94 ) ;
}
static int
F_197 (
struct V_28 * V_29 ,
struct V_129 * V_130 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_91 ;
struct V_99 * V_132 ;
F_15 ( & V_130 -> V_33 ) ;
if ( V_130 -> V_29 != V_29 )
goto V_110;
V_130 -> V_29 = NULL ;
V_130 -> V_226 = 0 ;
F_46 ( & V_130 -> V_136 ) ;
V_132 = F_99 ( & V_130 -> V_3 ) ;
while ( V_132 ) {
bool V_89 ;
V_91 = F_101 ( V_132 , struct V_94 , V_104 ) ;
V_132 = F_100 ( & V_91 -> V_104 ) ;
F_160 ( & V_91 -> V_104 , & V_130 -> V_3 ) ;
F_189 ( & V_91 -> V_104 ) ;
V_89 = ( V_91 -> V_89 != NULL ) ;
if ( ! V_89 ) {
F_182 ( V_97 , V_91 , false ) ;
F_186 ( V_97 , V_91 , false ) ;
}
F_153 ( & V_97 -> V_103 ,
V_91 -> V_6 , & V_91 -> V_104 , V_89 ) ;
}
V_130 -> V_3 = V_227 ;
V_110:
F_17 ( & V_130 -> V_33 ) ;
F_48 ( V_29 ) ;
return 0 ;
}
static void F_198 (
struct V_96 * V_97 )
{
struct V_94 * V_169 ;
struct V_99 * V_132 ;
while ( ( V_132 = F_199 ( & V_97 -> V_103 ) ) != NULL ) {
V_169 = F_101 ( V_132 , struct V_94 , V_104 ) ;
if ( ! V_169 -> V_89 ) {
F_102 ( V_97 , V_169 ) ;
F_103 ( V_106 , V_169 ) ;
} else {
F_175 ( V_97 , V_169 ) ;
}
F_200 ( & V_97 -> V_102 ) ;
}
}
void F_113 ( struct V_96 * V_97 )
{
F_15 ( & V_97 -> V_102 ) ;
F_198 ( V_97 ) ;
F_17 ( & V_97 -> V_102 ) ;
}
void F_201 ( struct V_28 * V_29 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_129 * V_130 ;
struct V_127 * V_228 ;
F_15 ( & V_97 -> V_102 ) ;
while ( ( V_228 = V_29 -> V_135 . V_105 ) !=
& V_29 -> V_135 ) {
V_130 = F_118 ( V_228 , struct V_129 ,
V_136 ) ;
F_141 ( V_130 -> V_29 != V_29 ) ;
F_197 ( V_29 , V_130 ) ;
F_200 ( & V_97 -> V_102 ) ;
}
F_198 ( V_97 ) ;
F_17 ( & V_97 -> V_102 ) ;
}
T_1 F_202 ( struct V_28 * V_29 ,
T_1 V_6 , T_1 V_88 , T_1 V_229 ,
T_1 * V_193 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_91 = NULL ;
T_1 V_230 = V_88 + V_229 ;
T_1 V_18 = 0 ;
T_1 V_231 = 0 ;
T_1 V_232 = 0 ;
F_15 ( & V_97 -> V_102 ) ;
V_91 = F_172 ( V_97 , & V_6 , & V_230 ,
V_29 -> V_233 , V_193 ) ;
if ( ! V_91 )
goto V_110;
V_18 = V_6 ;
if ( V_91 -> V_89 ) {
F_166 ( V_97 , V_91 , V_6 , V_88 ) ;
if ( ! V_91 -> V_88 )
F_175 ( V_97 , V_91 ) ;
} else {
F_102 ( V_97 , V_91 ) ;
V_232 = V_6 - V_91 -> V_6 ;
V_231 = V_91 -> V_6 ;
V_91 -> V_6 = V_6 + V_88 ;
F_141 ( V_91 -> V_88 < V_88 + V_232 ) ;
V_91 -> V_88 -= V_88 + V_232 ;
if ( ! V_91 -> V_88 )
F_103 ( V_106 , V_91 ) ;
else
F_104 ( V_97 , V_91 ) ;
}
V_110:
F_17 ( & V_97 -> V_102 ) ;
if ( V_232 )
F_188 ( V_29 -> V_8 , V_97 ,
V_231 , V_232 ) ;
return V_18 ;
}
int F_203 (
struct V_28 * V_29 ,
struct V_129 * V_130 )
{
struct V_96 * V_97 ;
int V_18 ;
F_15 ( & V_130 -> V_33 ) ;
if ( ! V_29 ) {
V_29 = V_130 -> V_29 ;
if ( ! V_29 ) {
F_17 ( & V_130 -> V_33 ) ;
return 0 ;
}
} else if ( V_130 -> V_29 != V_29 ) {
F_17 ( & V_130 -> V_33 ) ;
return 0 ;
}
F_204 ( & V_29 -> V_185 ) ;
F_17 ( & V_130 -> V_33 ) ;
V_97 = V_29 -> V_116 ;
F_15 ( & V_97 -> V_102 ) ;
V_18 = F_197 ( V_29 , V_130 ) ;
F_17 ( & V_97 -> V_102 ) ;
F_48 ( V_29 ) ;
return V_18 ;
}
static T_1 F_205 ( struct V_28 * V_29 ,
struct V_129 * V_130 ,
struct V_94 * V_91 ,
T_1 V_88 , T_1 V_234 ,
T_1 * V_193 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
int V_235 ;
T_1 V_197 = V_130 -> V_226 ;
T_1 V_198 = V_88 ;
T_1 V_18 = 0 ;
V_197 = V_234 ;
V_198 = V_88 ;
V_235 = F_169 ( V_97 , V_91 , & V_197 , & V_198 , true ) ;
if ( V_235 ) {
if ( V_198 > * V_193 )
* V_193 = V_198 ;
return 0 ;
}
V_18 = V_197 ;
F_164 ( V_97 , V_91 , V_18 , V_88 ) ;
return V_18 ;
}
T_1 F_206 ( struct V_28 * V_29 ,
struct V_129 * V_130 , T_1 V_88 ,
T_1 V_234 , T_1 * V_193 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_91 = NULL ;
struct V_99 * V_132 ;
T_1 V_18 = 0 ;
F_15 ( & V_130 -> V_33 ) ;
if ( V_88 > V_130 -> V_236 )
goto V_110;
if ( V_130 -> V_29 != V_29 )
goto V_110;
V_132 = F_99 ( & V_130 -> V_3 ) ;
if ( ! V_132 )
goto V_110;
V_91 = F_101 ( V_132 , struct V_94 , V_104 ) ;
while ( 1 ) {
if ( V_91 -> V_88 < V_88 && V_91 -> V_88 > * V_193 )
* V_193 = V_91 -> V_88 ;
if ( V_91 -> V_88 < V_88 ||
( ! V_91 -> V_89 && V_91 -> V_6 < V_234 ) ) {
V_132 = F_100 ( & V_91 -> V_104 ) ;
if ( ! V_132 )
break;
V_91 = F_101 ( V_132 , struct V_94 ,
V_104 ) ;
continue;
}
if ( V_91 -> V_89 ) {
V_18 = F_205 ( V_29 ,
V_130 , V_91 , V_88 ,
V_130 -> V_226 ,
V_193 ) ;
if ( V_18 == 0 ) {
V_132 = F_100 ( & V_91 -> V_104 ) ;
if ( ! V_132 )
break;
V_91 = F_101 ( V_132 , struct V_94 ,
V_104 ) ;
continue;
}
V_130 -> V_226 += V_88 ;
} else {
V_18 = V_91 -> V_6 ;
V_91 -> V_6 += V_88 ;
V_91 -> V_88 -= V_88 ;
}
if ( V_91 -> V_88 == 0 )
F_160 ( & V_91 -> V_104 , & V_130 -> V_3 ) ;
break;
}
V_110:
F_17 ( & V_130 -> V_33 ) ;
if ( ! V_18 )
return 0 ;
F_15 ( & V_97 -> V_102 ) ;
V_97 -> V_124 -= V_88 ;
if ( V_91 -> V_88 == 0 ) {
V_97 -> V_175 -- ;
if ( V_91 -> V_89 ) {
F_61 ( V_91 -> V_89 ) ;
V_97 -> V_112 -- ;
V_97 -> V_113 -> V_114 ( V_97 ) ;
}
F_103 ( V_106 , V_91 ) ;
}
F_17 ( & V_97 -> V_102 ) ;
return V_18 ;
}
static int F_207 ( struct V_28 * V_29 ,
struct V_94 * V_91 ,
struct V_129 * V_130 ,
T_1 V_6 , T_1 V_88 ,
T_1 V_237 , T_1 V_238 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
unsigned long V_191 ;
unsigned long V_78 ;
unsigned long V_239 ;
unsigned long V_240 ;
unsigned long V_188 ;
unsigned long V_189 = 0 ;
unsigned long V_137 = 0 ;
unsigned long V_241 = 0 ;
int V_18 ;
V_78 = F_148 ( V_91 -> V_6 , V_97 -> V_163 ,
F_162 ( T_1 , V_6 , V_91 -> V_6 ) ) ;
V_239 = F_150 ( V_88 , V_97 -> V_163 ) ;
V_240 = F_150 ( V_238 , V_97 -> V_163 ) ;
if ( V_91 -> V_193 &&
V_91 -> V_193 < V_237 )
return - V_51 ;
V_101:
V_188 = 0 ;
F_170 (i, entry->bitmap, BITS_PER_BITMAP) {
V_191 = F_171 ( V_91 -> V_89 ,
V_165 , V_78 ) ;
if ( V_191 - V_78 >= V_240 ) {
V_188 = V_191 - V_78 ;
if ( V_188 > V_189 )
V_189 = V_188 ;
break;
}
if ( V_191 - V_78 > V_189 )
V_189 = V_191 - V_78 ;
V_78 = V_191 ;
}
if ( ! V_188 ) {
V_91 -> V_193 = ( T_1 ) V_189 * V_97 -> V_163 ;
return - V_51 ;
}
if ( ! V_241 ) {
V_137 = V_78 ;
V_130 -> V_236 = 0 ;
}
V_241 += V_188 ;
if ( V_130 -> V_236 < V_188 * V_97 -> V_163 )
V_130 -> V_236 = V_188 * V_97 -> V_163 ;
if ( V_241 < V_239 || V_130 -> V_236 < V_237 ) {
V_78 = V_191 + 1 ;
goto V_101;
}
V_130 -> V_226 = V_137 * V_97 -> V_163 + V_91 -> V_6 ;
F_160 ( & V_91 -> V_104 , & V_97 -> V_103 ) ;
V_18 = F_153 ( & V_130 -> V_3 , V_91 -> V_6 ,
& V_91 -> V_104 , 1 ) ;
ASSERT ( ! V_18 ) ;
F_208 ( V_29 , V_130 ,
V_241 * V_97 -> V_163 , 1 ) ;
return 0 ;
}
static T_6 int
F_209 ( struct V_28 * V_29 ,
struct V_129 * V_130 ,
struct V_127 * V_107 , T_1 V_6 , T_1 V_88 ,
T_1 V_237 , T_1 V_238 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_242 = NULL ;
struct V_94 * V_91 = NULL ;
struct V_94 * V_243 ;
struct V_99 * V_132 ;
T_1 V_244 ;
T_1 V_245 ;
T_1 V_246 = 0 ;
V_91 = F_157 ( V_97 , V_6 , 0 , 1 ) ;
if ( ! V_91 )
return - V_51 ;
while ( V_91 -> V_89 || V_91 -> V_88 < V_238 ) {
if ( V_91 -> V_89 && F_45 ( & V_91 -> V_115 ) )
F_111 ( & V_91 -> V_115 , V_107 ) ;
V_132 = F_100 ( & V_91 -> V_104 ) ;
if ( ! V_132 )
return - V_51 ;
V_91 = F_101 ( V_132 , struct V_94 , V_104 ) ;
}
V_244 = V_91 -> V_88 ;
V_245 = V_91 -> V_88 ;
V_242 = V_91 ;
V_243 = V_91 ;
for ( V_132 = F_100 ( & V_91 -> V_104 ) ; V_132 ;
V_132 = F_100 ( & V_91 -> V_104 ) ) {
V_91 = F_101 ( V_132 , struct V_94 , V_104 ) ;
if ( V_91 -> V_89 ) {
if ( F_45 ( & V_91 -> V_115 ) )
F_111 ( & V_91 -> V_115 , V_107 ) ;
continue;
}
if ( V_91 -> V_88 < V_238 )
continue;
V_243 = V_91 ;
V_244 += V_91 -> V_88 ;
if ( V_91 -> V_88 > V_245 )
V_245 = V_91 -> V_88 ;
}
if ( V_244 < V_88 || V_245 < V_237 )
return - V_51 ;
V_130 -> V_226 = V_242 -> V_6 ;
V_132 = & V_242 -> V_104 ;
do {
int V_18 ;
V_91 = F_101 ( V_132 , struct V_94 , V_104 ) ;
V_132 = F_100 ( & V_91 -> V_104 ) ;
if ( V_91 -> V_89 || V_91 -> V_88 < V_238 )
continue;
F_160 ( & V_91 -> V_104 , & V_97 -> V_103 ) ;
V_18 = F_153 ( & V_130 -> V_3 , V_91 -> V_6 ,
& V_91 -> V_104 , 0 ) ;
V_246 += V_91 -> V_88 ;
ASSERT ( ! V_18 ) ;
} while ( V_132 && V_91 != V_243 );
V_130 -> V_236 = V_245 ;
F_208 ( V_29 , V_130 , V_246 , 0 ) ;
return 0 ;
}
static T_6 int
F_210 ( struct V_28 * V_29 ,
struct V_129 * V_130 ,
struct V_127 * V_107 , T_1 V_6 , T_1 V_88 ,
T_1 V_237 , T_1 V_238 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_91 = NULL ;
int V_18 = - V_51 ;
T_1 V_214 = F_151 ( V_97 , V_6 ) ;
if ( V_97 -> V_112 == 0 )
return - V_51 ;
if ( ! F_45 ( V_107 ) )
V_91 = F_211 ( V_107 , struct V_94 , V_115 ) ;
if ( ! V_91 || V_91 -> V_6 != V_214 ) {
V_91 = F_157 ( V_97 , V_214 , 1 , 0 ) ;
if ( V_91 && F_45 ( & V_91 -> V_115 ) )
F_212 ( & V_91 -> V_115 , V_107 ) ;
}
F_119 (entry, bitmaps, list) {
if ( V_91 -> V_88 < V_88 )
continue;
V_18 = F_207 ( V_29 , V_91 , V_130 , V_6 ,
V_88 , V_237 , V_238 ) ;
if ( ! V_18 )
return 0 ;
}
return - V_51 ;
}
int F_213 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
struct V_129 * V_130 ,
T_1 V_6 , T_1 V_88 , T_1 V_229 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_91 , * V_85 ;
F_106 ( V_107 ) ;
T_1 V_238 ;
T_1 V_237 ;
int V_18 ;
if ( F_214 ( V_8 , V_247 ) ) {
V_237 = V_238 = V_88 + V_229 ;
} else if ( V_29 -> V_30 & V_248 ) {
V_237 = V_88 ;
V_238 = V_8 -> V_203 ;
} else {
V_237 = F_128 ( V_88 , ( V_88 + V_229 ) >> 2 ) ;
V_238 = V_8 -> V_203 ;
}
F_15 ( & V_97 -> V_102 ) ;
if ( V_97 -> V_124 < V_88 ) {
F_17 ( & V_97 -> V_102 ) ;
return - V_51 ;
}
F_15 ( & V_130 -> V_33 ) ;
if ( V_130 -> V_29 ) {
V_18 = 0 ;
goto V_110;
}
F_215 ( V_29 , V_6 , V_88 , V_229 ,
V_238 ) ;
V_18 = F_209 ( V_29 , V_130 , & V_107 , V_6 ,
V_88 + V_229 ,
V_237 , V_238 ) ;
if ( V_18 )
V_18 = F_210 ( V_29 , V_130 , & V_107 ,
V_6 , V_88 + V_229 ,
V_237 , V_238 ) ;
F_112 (entry, tmp, &bitmaps, list)
F_46 ( & V_91 -> V_115 ) ;
if ( ! V_18 ) {
F_204 ( & V_29 -> V_185 ) ;
F_111 ( & V_130 -> V_136 ,
& V_29 -> V_135 ) ;
V_130 -> V_29 = V_29 ;
} else {
F_216 ( V_29 ) ;
}
V_110:
F_17 ( & V_130 -> V_33 ) ;
F_17 ( & V_97 -> V_102 ) ;
return V_18 ;
}
void F_217 ( struct V_129 * V_130 )
{
F_195 ( & V_130 -> V_33 ) ;
F_195 ( & V_130 -> V_249 ) ;
V_130 -> V_3 = V_227 ;
V_130 -> V_236 = 0 ;
V_130 -> V_250 = false ;
F_174 ( & V_130 -> V_136 ) ;
V_130 -> V_29 = NULL ;
}
static int F_218 ( struct V_28 * V_29 ,
T_1 * V_251 , T_1 V_137 , T_1 V_88 ,
T_1 V_252 , T_1 V_253 ,
struct V_133 * V_134 )
{
struct V_254 * V_255 = V_29 -> V_255 ;
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_96 * V_97 = V_29 -> V_116 ;
int V_18 ;
int V_256 = 0 ;
T_1 V_257 = 0 ;
F_15 ( & V_255 -> V_33 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( ! V_29 -> V_223 ) {
V_29 -> V_50 += V_253 ;
V_255 -> V_258 += V_253 ;
V_256 = 1 ;
}
F_17 ( & V_29 -> V_33 ) ;
F_17 ( & V_255 -> V_33 ) ;
V_18 = F_219 ( V_8 , V_137 , V_88 , & V_257 ) ;
if ( ! V_18 )
* V_251 += V_257 ;
F_44 ( & V_97 -> V_158 ) ;
F_192 ( V_29 , V_252 , V_253 ) ;
F_220 ( & V_134 -> V_115 ) ;
F_54 ( & V_97 -> V_158 ) ;
if ( V_256 ) {
F_15 ( & V_255 -> V_33 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_223 )
V_255 -> V_259 += V_253 ;
V_29 -> V_50 -= V_253 ;
V_255 -> V_258 -= V_253 ;
F_17 ( & V_255 -> V_33 ) ;
F_17 ( & V_29 -> V_33 ) ;
}
return V_18 ;
}
static int F_221 ( struct V_28 * V_29 ,
T_1 * V_251 , T_1 V_137 , T_1 V_196 , T_1 V_260 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_91 ;
struct V_99 * V_132 ;
int V_18 = 0 ;
T_1 V_143 ;
T_1 V_179 ;
T_1 V_88 ;
while ( V_137 < V_196 ) {
struct V_133 V_134 ;
F_44 ( & V_97 -> V_158 ) ;
F_15 ( & V_97 -> V_102 ) ;
if ( V_97 -> V_124 < V_260 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
break;
}
V_91 = F_157 ( V_97 , V_137 , 0 , 1 ) ;
if ( ! V_91 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
break;
}
while ( V_91 -> V_89 ) {
V_132 = F_100 ( & V_91 -> V_104 ) ;
if ( ! V_132 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
goto V_110;
}
V_91 = F_101 ( V_132 , struct V_94 ,
V_104 ) ;
}
if ( V_91 -> V_6 >= V_196 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
break;
}
V_143 = V_91 -> V_6 ;
V_179 = V_91 -> V_88 ;
V_137 = F_128 ( V_137 , V_143 ) ;
V_88 = F_129 ( V_143 + V_179 , V_196 ) - V_137 ;
if ( V_88 < V_260 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
goto V_105;
}
F_102 ( V_97 , V_91 ) ;
F_103 ( V_106 , V_91 ) ;
F_17 ( & V_97 -> V_102 ) ;
V_134 . V_137 = V_143 ;
V_134 . V_88 = V_179 ;
F_111 ( & V_134 . V_115 , & V_97 -> V_224 ) ;
F_54 ( & V_97 -> V_158 ) ;
V_18 = F_218 ( V_29 , V_251 , V_137 , V_88 ,
V_143 , V_179 , & V_134 ) ;
if ( V_18 )
break;
V_105:
V_137 += V_88 ;
if ( F_222 ( V_261 ) ) {
V_18 = - V_262 ;
break;
}
F_223 () ;
}
V_110:
return V_18 ;
}
static int F_224 ( struct V_28 * V_29 ,
T_1 * V_251 , T_1 V_137 , T_1 V_196 , T_1 V_260 )
{
struct V_96 * V_97 = V_29 -> V_116 ;
struct V_94 * V_91 ;
int V_18 = 0 ;
int V_263 ;
T_1 V_88 ;
T_1 V_6 = F_151 ( V_97 , V_137 ) ;
while ( V_6 < V_196 ) {
bool V_264 = false ;
struct V_133 V_134 ;
F_44 ( & V_97 -> V_158 ) ;
F_15 ( & V_97 -> V_102 ) ;
if ( V_97 -> V_124 < V_260 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
break;
}
V_91 = F_157 ( V_97 , V_6 , 1 , 0 ) ;
if ( ! V_91 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
V_264 = true ;
goto V_105;
}
V_88 = V_260 ;
V_263 = F_169 ( V_97 , V_91 , & V_137 , & V_88 , false ) ;
if ( V_263 || V_137 >= V_196 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
V_264 = true ;
goto V_105;
}
V_88 = F_129 ( V_88 , V_196 - V_137 ) ;
if ( V_88 < V_260 ) {
F_17 ( & V_97 -> V_102 ) ;
F_54 ( & V_97 -> V_158 ) ;
goto V_105;
}
F_166 ( V_97 , V_91 , V_137 , V_88 ) ;
if ( V_91 -> V_88 == 0 )
F_175 ( V_97 , V_91 ) ;
F_17 ( & V_97 -> V_102 ) ;
V_134 . V_137 = V_137 ;
V_134 . V_88 = V_88 ;
F_111 ( & V_134 . V_115 , & V_97 -> V_224 ) ;
F_54 ( & V_97 -> V_158 ) ;
V_18 = F_218 ( V_29 , V_251 , V_137 , V_88 ,
V_137 , V_88 , & V_134 ) ;
if ( V_18 )
break;
V_105:
if ( V_264 ) {
V_6 += V_165 * V_97 -> V_163 ;
} else {
V_137 += V_88 ;
if ( V_137 >= V_6 + V_165 * V_97 -> V_163 )
V_6 += V_165 * V_97 -> V_163 ;
}
if ( F_222 ( V_261 ) ) {
V_18 = - V_262 ;
break;
}
F_223 () ;
}
return V_18 ;
}
void F_225 ( struct V_28 * V_265 )
{
F_204 ( & V_265 -> V_266 ) ;
}
void F_226 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_267 * V_268 ;
struct V_269 * V_270 ;
bool V_271 ;
F_15 ( & V_29 -> V_33 ) ;
V_271 = ( F_227 ( & V_29 -> V_266 ) &&
V_29 -> V_272 ) ;
F_17 ( & V_29 -> V_33 ) ;
if ( V_271 ) {
F_44 ( & V_8 -> V_273 ) ;
V_268 = & V_8 -> V_274 . V_275 ;
F_228 ( & V_268 -> V_33 ) ;
V_270 = F_229 ( V_268 , V_29 -> V_10 . V_19 ,
1 ) ;
F_230 ( ! V_270 ) ;
F_231 ( V_268 , V_270 ) ;
F_232 ( & V_268 -> V_33 ) ;
F_54 ( & V_8 -> V_273 ) ;
F_233 ( V_270 ) ;
F_233 ( V_270 ) ;
F_113 ( V_29 -> V_116 ) ;
}
}
int F_234 ( struct V_28 * V_29 ,
T_1 * V_257 , T_1 V_137 , T_1 V_196 , T_1 V_260 )
{
int V_18 ;
* V_257 = 0 ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_272 ) {
F_17 ( & V_29 -> V_33 ) ;
return 0 ;
}
F_225 ( V_29 ) ;
F_17 ( & V_29 -> V_33 ) ;
V_18 = F_221 ( V_29 , V_257 , V_137 , V_196 , V_260 ) ;
if ( V_18 )
goto V_110;
V_18 = F_224 ( V_29 , V_257 , V_137 , V_196 , V_260 ) ;
V_110:
F_226 ( V_29 ) ;
return V_18 ;
}
T_1 F_235 ( struct V_2 * V_276 )
{
struct V_96 * V_97 = V_276 -> V_277 ;
struct V_94 * V_91 = NULL ;
T_1 V_39 = 0 ;
F_15 ( & V_97 -> V_102 ) ;
if ( F_236 ( & V_97 -> V_103 ) )
goto V_110;
V_91 = F_101 ( F_99 ( & V_97 -> V_103 ) ,
struct V_94 , V_104 ) ;
if ( ! V_91 -> V_89 ) {
V_39 = V_91 -> V_6 ;
F_102 ( V_97 , V_91 ) ;
V_91 -> V_6 ++ ;
V_91 -> V_88 -- ;
if ( ! V_91 -> V_88 )
F_103 ( V_106 , V_91 ) ;
else
F_104 ( V_97 , V_91 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_185 = 1 ;
int V_18 ;
V_18 = F_169 ( V_97 , V_91 , & V_6 , & V_185 , true ) ;
ASSERT ( ! V_18 ) ;
V_39 = V_6 ;
F_166 ( V_97 , V_91 , V_6 , 1 ) ;
if ( V_91 -> V_88 == 0 )
F_175 ( V_97 , V_91 ) ;
}
V_110:
F_17 ( & V_97 -> V_102 ) ;
return V_39 ;
}
struct V_1 * F_237 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_278 ) ;
if ( V_3 -> V_279 )
V_1 = F_16 ( V_3 -> V_279 ) ;
F_17 ( & V_3 -> V_278 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_278 ) ;
if ( ! F_238 ( V_3 -> V_8 ) )
V_3 -> V_279 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_278 ) ;
return V_1 ;
}
int F_239 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_38 , V_5 ,
V_44 , 0 ) ;
}
int F_240 ( struct V_7 * V_8 , struct V_2 * V_3 )
{
struct V_96 * V_97 = V_3 -> V_277 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_18 = 0 ;
T_1 V_280 = F_241 ( & V_3 -> V_281 ) ;
if ( ! F_214 ( V_8 , V_282 ) )
return 0 ;
if ( F_238 ( V_8 ) )
return 0 ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_237 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_110;
if ( V_280 != F_18 ( V_1 ) -> V_82 )
goto V_283;
V_18 = F_105 ( V_3 , V_1 , V_97 , V_5 , 0 ) ;
if ( V_18 < 0 )
F_81 ( V_8 ,
L_17 ,
V_3 -> V_284 . V_19 ) ;
V_283:
F_11 ( V_1 ) ;
V_110:
F_49 ( V_5 ) ;
return V_18 ;
}
int F_242 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_96 * V_97 = V_3 -> V_277 ;
int V_18 ;
struct V_64 V_65 ;
bool V_285 = true ;
if ( ! F_214 ( V_8 , V_282 ) )
return 0 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_18 = F_140 ( V_3 , V_1 , V_97 , NULL , & V_65 ,
V_38 , V_5 , 0 ) ;
if ( ! V_18 ) {
V_285 = false ;
V_18 = F_139 ( V_3 , V_38 , & V_65 , V_5 ) ;
}
if ( V_18 ) {
if ( V_285 )
F_243 ( V_1 , V_1 -> V_139 ) ;
#ifdef F_138
F_81 ( V_8 ,
L_18 ,
V_3 -> V_284 . V_19 ) ;
#endif
}
return V_18 ;
}
int F_244 ( struct V_28 * V_265 ,
T_1 V_6 , T_1 V_88 , bool V_89 )
{
struct V_96 * V_97 = V_265 -> V_116 ;
struct V_94 * V_169 = NULL , * V_186 ;
void * V_286 = NULL ;
T_1 V_205 ;
int V_18 ;
V_101:
if ( ! V_169 ) {
V_169 = F_110 ( V_106 , V_62 ) ;
if ( ! V_169 )
return - V_53 ;
}
if ( ! V_89 ) {
F_15 ( & V_97 -> V_102 ) ;
V_169 -> V_6 = V_6 ;
V_169 -> V_88 = V_88 ;
V_169 -> V_193 = 0 ;
V_18 = F_104 ( V_97 , V_169 ) ;
F_17 ( & V_97 -> V_102 ) ;
if ( V_18 )
F_103 ( V_106 , V_169 ) ;
return V_18 ;
}
if ( ! V_286 ) {
V_286 = F_57 ( V_69 , V_62 ) ;
if ( ! V_286 ) {
F_103 ( V_106 , V_169 ) ;
return - V_53 ;
}
}
F_15 ( & V_97 -> V_102 ) ;
V_186 = F_157 ( V_97 , F_151 ( V_97 , V_6 ) ,
1 , 0 ) ;
if ( ! V_186 ) {
V_169 -> V_89 = V_286 ;
V_286 = NULL ;
F_173 ( V_97 , V_169 , V_6 ) ;
V_186 = V_169 ;
V_169 = NULL ;
}
V_205 = F_177 ( V_97 , V_186 , V_6 , V_88 ) ;
V_88 -= V_205 ;
V_6 += V_205 ;
F_17 ( & V_97 -> V_102 ) ;
if ( V_88 )
goto V_101;
if ( V_169 )
F_103 ( V_106 , V_169 ) ;
if ( V_286 )
F_61 ( V_286 ) ;
return 0 ;
}
int F_245 ( struct V_28 * V_265 ,
T_1 V_6 , T_1 V_88 )
{
struct V_96 * V_97 = V_265 -> V_116 ;
struct V_94 * V_169 ;
int V_18 = 0 ;
F_15 ( & V_97 -> V_102 ) ;
V_169 = F_157 ( V_97 , V_6 , 0 , 0 ) ;
if ( ! V_169 ) {
V_169 = F_157 ( V_97 , F_151 ( V_97 , V_6 ) ,
1 , 0 ) ;
if ( ! V_169 )
goto V_110;
}
V_287:
if ( V_169 -> V_89 ) {
T_1 V_288 , V_289 ;
struct V_99 * V_100 ;
struct V_94 * V_85 ;
V_288 = V_6 ;
V_289 = V_97 -> V_163 ;
V_18 = F_169 ( V_97 , V_169 , & V_288 , & V_289 , false ) ;
if ( ! V_18 ) {
if ( V_288 == V_6 ) {
V_18 = 1 ;
goto V_110;
} else if ( V_288 > V_6 &&
V_6 + V_88 > V_288 ) {
V_18 = 1 ;
goto V_110;
}
}
V_100 = F_158 ( & V_169 -> V_104 ) ;
while ( V_100 ) {
V_85 = F_101 ( V_100 , struct V_94 ,
V_104 ) ;
if ( V_85 -> V_6 + V_85 -> V_88 < V_6 )
break;
if ( V_6 + V_88 < V_85 -> V_6 ) {
V_100 = F_158 ( & V_85 -> V_104 ) ;
continue;
}
V_169 = V_85 ;
goto V_287;
}
V_100 = F_100 ( & V_169 -> V_104 ) ;
while ( V_100 ) {
V_85 = F_101 ( V_100 , struct V_94 ,
V_104 ) ;
if ( V_6 + V_88 < V_85 -> V_6 )
break;
if ( V_85 -> V_6 + V_85 -> V_88 < V_6 ) {
V_100 = F_100 ( & V_85 -> V_104 ) ;
continue;
}
V_169 = V_85 ;
goto V_287;
}
V_18 = 0 ;
goto V_110;
}
if ( V_169 -> V_6 == V_6 ) {
V_18 = 1 ;
goto V_110;
}
if ( V_6 > V_169 -> V_6 && V_6 < V_169 -> V_6 + V_169 -> V_88 )
V_18 = 1 ;
V_110:
F_17 ( & V_97 -> V_102 ) ;
return V_18 ;
}
