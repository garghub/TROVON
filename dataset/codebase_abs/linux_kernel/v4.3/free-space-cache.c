static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_7 V_8 ;
struct V_7 V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_1 = NULL ;
int V_16 ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( NULL , V_3 , & V_8 , V_5 , 0 , 0 ) ;
if ( V_16 < 0 )
return F_3 ( V_16 ) ;
if ( V_16 > 0 ) {
F_4 ( V_5 ) ;
return F_3 ( - V_19 ) ;
}
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_6 ( V_15 , V_13 , & V_11 ) ;
F_7 ( & V_9 , & V_11 ) ;
F_4 ( V_5 ) ;
V_1 = F_8 ( V_3 -> V_22 -> V_23 , & V_9 , V_3 , NULL ) ;
if ( ! V_1 )
return F_3 ( - V_19 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
if ( F_10 ( V_1 ) ) {
F_11 ( V_1 ) ;
return F_3 ( - V_19 ) ;
}
F_12 ( V_1 -> V_24 ,
F_13 ( V_1 -> V_24 ) &
~ ( V_25 | V_26 ) ) ;
return V_1 ;
}
struct V_1 * F_14 ( struct V_2 * V_3 ,
struct V_27
* V_28 , struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
T_2 V_29 = V_30 | V_31 ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_1 )
V_1 = F_16 ( V_28 -> V_1 ) ;
F_17 ( & V_28 -> V_32 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 ,
V_28 -> V_8 . V_17 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_28 -> V_32 ) ;
if ( ! ( ( F_18 ( V_1 ) -> V_29 & V_29 ) == V_29 ) ) {
F_19 ( V_3 -> V_22 ,
L_1 ) ;
F_18 ( V_1 ) -> V_29 |= V_30 |
V_31 ;
V_28 -> V_33 = V_34 ;
}
if ( ! V_28 -> V_35 ) {
V_28 -> V_1 = F_16 ( V_1 ) ;
V_28 -> V_35 = 1 ;
}
F_17 ( & V_28 -> V_32 ) ;
return V_1 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 ,
T_1 V_38 , T_1 V_6 )
{
struct V_7 V_8 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_39 * V_40 ;
struct V_14 * V_15 ;
T_1 V_29 = V_41 | V_42 ;
int V_16 ;
V_16 = F_21 ( V_37 , V_3 , V_5 , V_38 ) ;
if ( V_16 )
return V_16 ;
if ( V_38 != V_43 )
V_29 |= V_30 | V_31 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_40 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_39 ) ;
F_22 ( V_15 , & V_11 , V_5 -> V_21 [ 0 ] ) ;
F_23 ( V_15 , 0 , ( unsigned long ) V_40 ,
sizeof( * V_40 ) ) ;
F_24 ( V_15 , V_40 , V_37 -> V_44 ) ;
F_25 ( V_15 , V_40 , 0 ) ;
F_26 ( V_15 , V_40 , 0 ) ;
F_27 ( V_15 , V_40 , 0 ) ;
F_28 ( V_15 , V_40 , 0 ) ;
F_29 ( V_15 , V_40 , V_45 | 0600 ) ;
F_30 ( V_15 , V_40 , V_29 ) ;
F_31 ( V_15 , V_40 , 1 ) ;
F_32 ( V_15 , V_40 , V_37 -> V_44 ) ;
F_33 ( V_15 , V_40 , V_6 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_35 ( V_37 , V_3 , V_5 , & V_8 ,
sizeof( struct V_12 ) ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 ) ;
return V_16 ;
}
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_23 ( V_15 , 0 , ( unsigned long ) V_13 , sizeof( * V_13 ) ) ;
F_36 ( V_15 , V_13 , & V_11 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
int V_16 ;
T_1 V_38 ;
V_16 = F_38 ( V_3 , & V_38 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_20 ( V_3 , V_37 , V_5 , V_38 ,
V_28 -> V_8 . V_17 ) ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_46 * V_47 )
{
T_1 V_48 ;
int V_16 ;
V_48 = F_40 ( V_3 , 1 ) +
F_41 ( V_3 , 1 ) ;
F_15 ( & V_47 -> V_32 ) ;
if ( V_47 -> V_49 < V_48 )
V_16 = - V_50 ;
else
V_16 = 0 ;
F_17 ( & V_47 -> V_32 ) ;
return V_16 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_1 * V_1 )
{
int V_16 = 0 ;
struct V_4 * V_5 = F_43 () ;
bool V_51 = false ;
if ( ! V_5 ) {
V_16 = - V_52 ;
goto V_53;
}
if ( V_28 ) {
V_51 = true ;
F_44 ( & V_37 -> V_54 -> V_55 ) ;
if ( ! F_45 ( & V_28 -> V_56 ) ) {
F_46 ( & V_28 -> V_56 ) ;
F_47 ( V_3 , V_37 , V_28 ,
& V_28 -> V_57 , V_5 ,
V_28 -> V_8 . V_17 ) ;
F_48 ( V_28 ) ;
}
F_15 ( & V_28 -> V_32 ) ;
V_28 -> V_33 = V_34 ;
F_17 ( & V_28 -> V_32 ) ;
}
F_49 ( V_5 ) ;
F_50 ( V_1 , 0 ) ;
F_51 ( V_1 , 0 ) ;
V_16 = F_52 ( V_37 , V_3 , V_1 ,
0 , V_58 ) ;
if ( V_16 )
goto V_53;
V_16 = F_53 ( V_37 , V_3 , V_1 ) ;
V_53:
if ( V_51 )
F_54 ( & V_37 -> V_54 -> V_55 ) ;
if ( V_16 )
F_55 ( V_37 , V_3 , V_16 ) ;
return V_16 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_59 * V_60 ;
unsigned long V_61 ;
V_60 = F_57 ( sizeof( * V_60 ) , V_62 ) ;
if ( ! V_60 )
return - V_52 ;
F_58 ( V_60 , V_1 -> V_24 ) ;
V_61 = ( F_59 ( V_1 ) - 1 ) >> V_63 ;
F_60 ( V_1 -> V_24 , V_60 , NULL , 0 , V_61 ) ;
F_61 ( V_60 ) ;
return 0 ;
}
static int F_62 ( struct V_64 * V_57 , struct V_1 * V_1 ,
struct V_2 * V_3 , int V_65 )
{
int V_66 ;
int V_67 = 0 ;
V_66 = F_63 ( F_59 ( V_1 ) , V_68 ) ;
if ( F_64 ( V_1 ) != V_43 )
V_67 = 1 ;
if ( V_65 && V_67 &&
( V_66 * sizeof( T_2 ) ) >= V_68 )
return - V_50 ;
memset ( V_57 , 0 , sizeof( struct V_64 ) ) ;
V_57 -> V_69 = F_65 ( V_66 , sizeof( struct V_70 * ) , V_62 ) ;
if ( ! V_57 -> V_69 )
return - V_52 ;
V_57 -> V_66 = V_66 ;
V_57 -> V_3 = V_3 ;
V_57 -> V_67 = V_67 ;
V_57 -> V_1 = V_1 ;
return 0 ;
}
static void F_66 ( struct V_64 * V_57 )
{
F_61 ( V_57 -> V_69 ) ;
V_57 -> V_69 = NULL ;
}
static void F_67 ( struct V_64 * V_57 )
{
if ( V_57 -> V_71 ) {
V_57 -> V_71 = NULL ;
V_57 -> V_72 = NULL ;
}
}
static void F_68 ( struct V_64 * V_57 , int V_73 )
{
ASSERT ( V_57 -> V_74 < V_57 -> V_66 ) ;
V_57 -> V_70 = V_57 -> V_69 [ V_57 -> V_74 ++ ] ;
V_57 -> V_71 = F_69 ( V_57 -> V_70 ) ;
V_57 -> V_72 = V_57 -> V_71 ;
V_57 -> V_75 = V_68 ;
if ( V_73 )
memset ( V_57 -> V_71 , 0 , V_68 ) ;
}
static void F_70 ( struct V_64 * V_57 )
{
int V_76 ;
F_67 ( V_57 ) ;
for ( V_76 = 0 ; V_76 < V_57 -> V_66 ; V_76 ++ ) {
if ( V_57 -> V_69 [ V_76 ] ) {
F_71 ( V_57 -> V_69 [ V_76 ] ) ;
F_72 ( V_57 -> V_69 [ V_76 ] ) ;
F_73 ( V_57 -> V_69 [ V_76 ] ) ;
}
}
}
static int F_74 ( struct V_64 * V_57 , struct V_1 * V_1 ,
int V_77 )
{
struct V_70 * V_70 ;
T_3 V_78 = F_75 ( V_1 -> V_24 ) ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_57 -> V_66 ; V_76 ++ ) {
V_70 = F_76 ( V_1 -> V_24 , V_76 , V_78 ) ;
if ( ! V_70 ) {
F_70 ( V_57 ) ;
return - V_52 ;
}
V_57 -> V_69 [ V_76 ] = V_70 ;
if ( V_77 && ! F_77 ( V_70 ) ) {
F_78 ( NULL , V_70 ) ;
F_79 ( V_70 ) ;
if ( ! F_77 ( V_70 ) ) {
F_80 ( F_18 ( V_1 ) -> V_3 -> V_22 ,
L_2 ) ;
F_70 ( V_57 ) ;
return - V_79 ;
}
}
}
for ( V_76 = 0 ; V_76 < V_57 -> V_66 ; V_76 ++ ) {
F_81 ( V_57 -> V_69 [ V_76 ] ) ;
F_82 ( V_57 -> V_69 [ V_76 ] ) ;
}
return 0 ;
}
static void F_83 ( struct V_64 * V_57 , T_1 V_80 )
{
T_4 * V_81 ;
F_68 ( V_57 , 1 ) ;
if ( V_57 -> V_67 ) {
V_57 -> V_71 += ( sizeof( T_2 ) * V_57 -> V_66 ) ;
V_57 -> V_75 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_57 -> V_66 ) ;
} else {
V_57 -> V_71 += sizeof( T_1 ) ;
V_57 -> V_75 -= sizeof( T_1 ) * 2 ;
}
V_81 = V_57 -> V_71 ;
* V_81 = F_84 ( V_80 ) ;
V_57 -> V_71 += sizeof( T_1 ) ;
}
static int F_85 ( struct V_64 * V_57 , T_1 V_80 )
{
T_4 * V_82 ;
if ( V_57 -> V_67 ) {
V_57 -> V_71 += sizeof( T_2 ) * V_57 -> V_66 ;
V_57 -> V_75 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_57 -> V_66 ) ;
} else {
V_57 -> V_71 += sizeof( T_1 ) ;
V_57 -> V_75 -= sizeof( T_1 ) * 2 ;
}
V_82 = V_57 -> V_71 ;
if ( F_86 ( * V_82 ) != V_80 ) {
F_87 ( V_83 L_3
L_4 , * V_82 ,
V_80 ) ;
F_67 ( V_57 ) ;
return - V_79 ;
}
V_57 -> V_71 += sizeof( T_1 ) ;
return 0 ;
}
static void F_88 ( struct V_64 * V_57 , int V_74 )
{
T_2 * V_84 ;
T_2 V_85 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_67 ) {
F_67 ( V_57 ) ;
return;
}
if ( V_74 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_66 ;
V_85 = F_89 ( V_57 -> V_72 + V_6 , V_85 ,
V_68 - V_6 ) ;
F_90 ( V_85 , ( char * ) & V_85 ) ;
F_67 ( V_57 ) ;
V_84 = F_69 ( V_57 -> V_69 [ 0 ] ) ;
V_84 += V_74 ;
* V_84 = V_85 ;
}
static int F_91 ( struct V_64 * V_57 , int V_74 )
{
T_2 * V_84 , V_81 ;
T_2 V_85 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_67 ) {
F_68 ( V_57 , 0 ) ;
return 0 ;
}
if ( V_74 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_66 ;
V_84 = F_69 ( V_57 -> V_69 [ 0 ] ) ;
V_84 += V_74 ;
V_81 = * V_84 ;
F_68 ( V_57 , 0 ) ;
V_85 = F_89 ( V_57 -> V_72 + V_6 , V_85 ,
V_68 - V_6 ) ;
F_90 ( V_85 , ( char * ) & V_85 ) ;
if ( V_81 != V_85 ) {
F_87 ( V_83 L_5
L_6 ) ;
F_67 ( V_57 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_92 ( struct V_64 * V_57 , T_1 V_6 , T_1 V_86 ,
void * V_87 )
{
struct V_88 * V_89 ;
if ( ! V_57 -> V_71 )
return - V_50 ;
V_89 = V_57 -> V_71 ;
V_89 -> V_6 = F_84 ( V_6 ) ;
V_89 -> V_86 = F_84 ( V_86 ) ;
V_89 -> type = ( V_87 ) ? V_90 :
V_91 ;
V_57 -> V_71 += sizeof( struct V_88 ) ;
V_57 -> V_75 -= sizeof( struct V_88 ) ;
if ( V_57 -> V_75 >= sizeof( struct V_88 ) )
return 0 ;
F_88 ( V_57 , V_57 -> V_74 - 1 ) ;
if ( V_57 -> V_74 >= V_57 -> V_66 )
return 0 ;
F_68 ( V_57 , 1 ) ;
return 0 ;
}
static int F_93 ( struct V_64 * V_57 , void * V_87 )
{
if ( ! V_57 -> V_71 )
return - V_50 ;
if ( V_57 -> V_71 != V_57 -> V_72 ) {
F_88 ( V_57 , V_57 -> V_74 - 1 ) ;
if ( V_57 -> V_74 >= V_57 -> V_66 )
return - V_50 ;
F_68 ( V_57 , 0 ) ;
}
memcpy ( V_57 -> V_71 , V_87 , V_68 ) ;
F_88 ( V_57 , V_57 -> V_74 - 1 ) ;
if ( V_57 -> V_74 < V_57 -> V_66 )
F_68 ( V_57 , 0 ) ;
return 0 ;
}
static void F_94 ( struct V_64 * V_57 )
{
if ( V_57 -> V_71 != V_57 -> V_72 )
F_88 ( V_57 , V_57 -> V_74 - 1 ) ;
else
F_67 ( V_57 ) ;
while ( V_57 -> V_74 < V_57 -> V_66 ) {
F_68 ( V_57 , 1 ) ;
F_88 ( V_57 , V_57 -> V_74 - 1 ) ;
}
}
static int F_95 ( struct V_64 * V_57 ,
struct V_92 * V_89 , T_5 * type )
{
struct V_88 * V_93 ;
int V_16 ;
if ( ! V_57 -> V_71 ) {
V_16 = F_91 ( V_57 , V_57 -> V_74 ) ;
if ( V_16 )
return V_16 ;
}
V_93 = V_57 -> V_71 ;
V_89 -> V_6 = F_86 ( V_93 -> V_6 ) ;
V_89 -> V_86 = F_86 ( V_93 -> V_86 ) ;
* type = V_93 -> type ;
V_57 -> V_71 += sizeof( struct V_88 ) ;
V_57 -> V_75 -= sizeof( struct V_88 ) ;
if ( V_57 -> V_75 >= sizeof( struct V_88 ) )
return 0 ;
F_67 ( V_57 ) ;
return 0 ;
}
static int F_96 ( struct V_64 * V_57 ,
struct V_92 * V_89 )
{
int V_16 ;
V_16 = F_91 ( V_57 , V_57 -> V_74 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_89 -> V_87 , V_57 -> V_71 , V_68 ) ;
F_67 ( V_57 ) ;
return 0 ;
}
static void F_97 ( struct V_94 * V_95 )
{
struct V_92 * V_93 , * V_96 = NULL ;
struct V_97 * V_98 ;
V_99:
F_15 ( & V_95 -> V_100 ) ;
for ( V_98 = F_98 ( & V_95 -> V_101 ) ; V_98 ; V_98 = F_99 ( V_98 ) ) {
V_93 = F_100 ( V_98 , struct V_92 , V_102 ) ;
if ( ! V_96 )
goto V_103;
if ( V_93 -> V_87 || V_96 -> V_87 )
goto V_103;
if ( V_96 -> V_6 + V_96 -> V_86 == V_93 -> V_6 ) {
F_101 ( V_95 , V_96 ) ;
F_101 ( V_95 , V_93 ) ;
V_96 -> V_86 += V_93 -> V_86 ;
F_102 ( V_104 , V_93 ) ;
F_103 ( V_95 , V_96 ) ;
V_96 = NULL ;
F_17 ( & V_95 -> V_100 ) ;
goto V_99;
}
V_103:
V_96 = V_93 ;
}
F_17 ( & V_95 -> V_100 ) ;
}
static int F_104 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_94 * V_95 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_64 V_57 ;
struct V_7 V_8 ;
struct V_92 * V_93 , * V_98 ;
F_105 ( V_105 ) ;
T_1 V_106 ;
T_1 V_107 ;
T_1 V_80 ;
T_5 type ;
int V_16 = 0 ;
if ( ! F_59 ( V_1 ) )
return 0 ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( NULL , V_3 , & V_8 , V_5 , 0 , 0 ) ;
if ( V_16 < 0 )
return 0 ;
else if ( V_16 > 0 ) {
F_4 ( V_5 ) ;
return 0 ;
}
V_16 = - 1 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
V_106 = F_106 ( V_15 , V_13 ) ;
V_107 = F_107 ( V_15 , V_13 ) ;
V_80 = F_108 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( ! F_18 ( V_1 ) -> V_80 ) {
F_19 ( V_3 -> V_22 ,
L_7 ,
V_6 ) ;
return 0 ;
}
if ( F_18 ( V_1 ) -> V_80 != V_80 ) {
F_80 ( V_3 -> V_22 ,
L_8
L_9 ,
F_18 ( V_1 ) -> V_80 , V_80 ) ;
return 0 ;
}
if ( ! V_106 )
return 0 ;
V_16 = F_62 ( & V_57 , V_1 , V_3 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_56 ( V_1 ) ;
if ( V_16 )
goto V_108;
V_16 = F_74 ( & V_57 , V_1 , 1 ) ;
if ( V_16 )
goto V_108;
V_16 = F_91 ( & V_57 , 0 ) ;
if ( V_16 )
goto V_109;
V_16 = F_85 ( & V_57 , V_80 ) ;
if ( V_16 )
goto V_109;
while ( V_106 ) {
V_93 = F_109 ( V_104 ,
V_62 ) ;
if ( ! V_93 )
goto V_109;
V_16 = F_95 ( & V_57 , V_93 , & type ) ;
if ( V_16 ) {
F_102 ( V_104 , V_93 ) ;
goto V_109;
}
if ( ! V_93 -> V_86 ) {
F_102 ( V_104 , V_93 ) ;
goto V_109;
}
if ( type == V_91 ) {
F_15 ( & V_95 -> V_100 ) ;
V_16 = F_103 ( V_95 , V_93 ) ;
F_17 ( & V_95 -> V_100 ) ;
if ( V_16 ) {
F_80 ( V_3 -> V_22 ,
L_10 ) ;
F_102 ( V_104 , V_93 ) ;
goto V_109;
}
} else {
ASSERT ( V_107 ) ;
V_107 -- ;
V_93 -> V_87 = F_57 ( V_68 , V_62 ) ;
if ( ! V_93 -> V_87 ) {
F_102 (
V_104 , V_93 ) ;
goto V_109;
}
F_15 ( & V_95 -> V_100 ) ;
V_16 = F_103 ( V_95 , V_93 ) ;
V_95 -> V_110 ++ ;
V_95 -> V_111 -> V_112 ( V_95 ) ;
F_17 ( & V_95 -> V_100 ) ;
if ( V_16 ) {
F_80 ( V_3 -> V_22 ,
L_10 ) ;
F_102 ( V_104 , V_93 ) ;
goto V_109;
}
F_110 ( & V_93 -> V_113 , & V_105 ) ;
}
V_106 -- ;
}
F_67 ( & V_57 ) ;
F_111 (e, n, &bitmaps, list) {
F_46 ( & V_93 -> V_113 ) ;
V_16 = F_96 ( & V_57 , V_93 ) ;
if ( V_16 )
goto V_109;
}
F_70 ( & V_57 ) ;
F_97 ( V_95 ) ;
V_16 = 1 ;
V_108:
F_66 ( & V_57 ) ;
return V_16 ;
V_109:
F_70 ( & V_57 ) ;
F_112 ( V_95 ) ;
goto V_108;
}
int F_113 ( struct V_114 * V_22 ,
struct V_27 * V_28 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_2 * V_3 = V_22 -> V_116 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 = 0 ;
bool V_117 ;
T_1 V_118 = F_114 ( & V_28 -> V_119 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_33 != V_120 ) {
F_17 ( & V_28 -> V_32 ) ;
return 0 ;
}
F_17 ( & V_28 -> V_32 ) ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_121 = 1 ;
V_5 -> V_122 = 1 ;
V_1 = F_14 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_49 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_33 != V_120 ) {
F_17 ( & V_28 -> V_32 ) ;
F_49 ( V_5 ) ;
goto V_108;
}
F_17 ( & V_28 -> V_32 ) ;
V_16 = F_104 ( V_22 -> V_116 , V_1 , V_95 ,
V_5 , V_28 -> V_8 . V_17 ) ;
F_49 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_108;
F_15 ( & V_95 -> V_100 ) ;
V_117 = ( V_95 -> V_123 == ( V_28 -> V_8 . V_6 - V_118 -
V_28 -> V_124 ) ) ;
F_17 ( & V_95 -> V_100 ) ;
if ( ! V_117 ) {
F_112 ( V_95 ) ;
F_115 ( V_22 , L_11 ,
V_28 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_108:
if ( V_16 < 0 ) {
F_15 ( & V_28 -> V_32 ) ;
V_28 -> V_33 = V_34 ;
F_17 ( & V_28 -> V_32 ) ;
V_16 = 0 ;
F_115 ( V_22 , L_12 ,
V_28 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
static T_6
int F_116 ( struct V_64 * V_57 ,
struct V_94 * V_95 ,
struct V_27 * V_28 ,
int * V_125 , int * V_105 ,
struct V_126 * V_127 )
{
int V_16 ;
struct V_128 * V_129 = NULL ;
struct V_128 * V_130 = NULL ;
struct V_97 * V_131 = F_98 ( & V_95 -> V_101 ) ;
struct V_132 * V_133 ;
if ( V_28 && ! F_45 ( & V_28 -> V_134 ) ) {
V_129 = F_117 ( V_28 -> V_134 . V_103 ,
struct V_128 ,
V_135 ) ;
}
if ( ! V_131 && V_129 ) {
V_130 = V_129 ;
F_15 ( & V_130 -> V_32 ) ;
V_131 = F_98 ( & V_129 -> V_3 ) ;
V_129 = NULL ;
}
while ( V_131 ) {
struct V_92 * V_93 ;
V_93 = F_100 ( V_131 , struct V_92 , V_102 ) ;
* V_125 += 1 ;
V_16 = F_92 ( V_57 , V_93 -> V_6 , V_93 -> V_86 ,
V_93 -> V_87 ) ;
if ( V_16 )
goto V_53;
if ( V_93 -> V_87 ) {
F_110 ( & V_93 -> V_113 , V_127 ) ;
* V_105 += 1 ;
}
V_131 = F_99 ( V_131 ) ;
if ( ! V_131 && V_129 ) {
V_131 = F_98 ( & V_129 -> V_3 ) ;
V_130 = V_129 ;
F_15 ( & V_130 -> V_32 ) ;
V_129 = NULL ;
}
}
if ( V_130 ) {
F_17 ( & V_130 -> V_32 ) ;
V_130 = NULL ;
}
F_118 (trim_entry, &ctl->trimming_ranges, list) {
V_16 = F_92 ( V_57 , V_133 -> V_136 ,
V_133 -> V_86 , NULL ) ;
if ( V_16 )
goto V_53;
* V_125 += 1 ;
}
return 0 ;
V_53:
if ( V_130 )
F_17 ( & V_130 -> V_32 ) ;
return - V_50 ;
}
static T_6 int
F_119 ( struct V_36 * V_37 ,
struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 , T_1 V_6 ,
int V_125 , int V_105 )
{
struct V_7 V_8 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_37 , V_3 , & V_8 , V_5 , 0 , 1 ) ;
if ( V_16 < 0 ) {
F_120 ( & F_18 ( V_1 ) -> V_137 , 0 , V_1 -> V_138 - 1 ,
V_139 | V_140 , 0 , 0 , NULL ,
V_62 ) ;
goto V_53;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_141 ;
ASSERT ( V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_121 ( V_15 , & V_141 , V_5 -> V_21 [ 0 ] ) ;
if ( V_141 . V_17 != V_18 ||
V_141 . V_6 != V_6 ) {
F_120 ( & F_18 ( V_1 ) -> V_137 , 0 ,
V_1 -> V_138 - 1 ,
V_139 | V_140 , 0 , 0 ,
NULL , V_62 ) ;
F_4 ( V_5 ) ;
goto V_53;
}
}
F_18 ( V_1 ) -> V_80 = V_37 -> V_44 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_122 ( V_15 , V_13 , V_125 ) ;
F_123 ( V_15 , V_13 , V_105 ) ;
F_124 ( V_15 , V_13 , V_37 -> V_44 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
return 0 ;
V_53:
return - 1 ;
}
static T_6 int
F_125 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_64 * V_57 ,
int * V_125 )
{
T_1 V_136 , V_142 , V_143 , V_144 ;
struct V_145 * V_146 = NULL ;
int V_16 ;
if ( ! V_28 )
return 0 ;
V_146 = V_3 -> V_22 -> V_147 ;
V_136 = V_28 -> V_8 . V_17 ;
while ( V_136 < V_28 -> V_8 . V_17 + V_28 -> V_8 . V_6 ) {
V_16 = F_126 ( V_146 , V_136 ,
& V_142 , & V_143 ,
V_139 , NULL ) ;
if ( V_16 )
return 0 ;
if ( V_142 >= V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 )
return 0 ;
V_142 = F_127 ( V_142 , V_136 ) ;
V_143 = F_128 ( V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 , V_143 + 1 ) ;
V_144 = V_143 - V_142 ;
* V_125 += 1 ;
V_16 = F_92 ( V_57 , V_142 , V_144 , NULL ) ;
if ( V_16 )
return - V_50 ;
V_136 = V_143 ;
}
return 0 ;
}
static T_6 int
F_129 ( struct V_64 * V_57 , struct V_126 * V_127 )
{
struct V_126 * V_148 , * V_98 ;
int V_16 ;
F_130 (pos, n, bitmap_list) {
struct V_92 * V_89 =
F_117 ( V_148 , struct V_92 , V_113 ) ;
V_16 = F_93 ( V_57 , V_89 -> V_87 ) ;
if ( V_16 )
return - V_50 ;
F_46 ( & V_89 -> V_113 ) ;
}
return 0 ;
}
static int F_131 ( struct V_1 * V_1 )
{
int V_16 ;
V_16 = F_132 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_16 )
F_120 ( & F_18 ( V_1 ) -> V_137 , 0 , V_1 -> V_138 - 1 ,
V_139 | V_140 , 0 , 0 , NULL ,
V_62 ) ;
return V_16 ;
}
static void T_6
F_133 ( struct V_126 * V_127 )
{
struct V_126 * V_148 , * V_98 ;
F_130 (pos, n, bitmap_list) {
struct V_92 * V_89 =
F_117 ( V_148 , struct V_92 , V_113 ) ;
F_46 ( & V_89 -> V_113 ) ;
}
}
static void T_6
F_134 ( struct V_1 * V_1 ,
struct V_64 * V_57 ,
struct V_149 * * V_150 ,
struct V_126 * V_127 )
{
F_70 ( V_57 ) ;
F_135 ( & F_18 ( V_1 ) -> V_137 , 0 ,
F_59 ( V_1 ) - 1 , V_150 ,
V_62 ) ;
}
int F_47 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_64 * V_57 ,
struct V_4 * V_5 , T_1 V_6 )
{
int V_16 ;
struct V_1 * V_1 = V_57 -> V_1 ;
if ( ! V_1 )
return 0 ;
if ( V_28 )
V_3 = V_3 -> V_22 -> V_116 ;
V_16 = F_131 ( V_1 ) ;
if ( V_16 )
goto V_108;
V_16 = F_119 ( V_37 , V_3 , V_1 , V_5 , V_6 ,
V_57 -> V_125 , V_57 -> V_105 ) ;
V_108:
F_66 ( V_57 ) ;
if ( V_16 ) {
F_136 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_80 = 0 ;
if ( V_28 ) {
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_13 ,
V_28 -> V_8 . V_17 ) ;
#endif
}
}
F_53 ( V_37 , V_3 , V_1 ) ;
if ( V_28 ) {
F_15 ( & V_37 -> V_54 -> V_151 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( ! V_16 && F_45 ( & V_28 -> V_152 ) )
V_28 -> V_33 = V_120 ;
else if ( V_16 )
V_28 -> V_33 = V_153 ;
F_17 ( & V_28 -> V_32 ) ;
F_17 ( & V_37 -> V_54 -> V_151 ) ;
V_57 -> V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_16 ;
}
static int F_138 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_94 * V_95 ,
struct V_27 * V_28 ,
struct V_64 * V_57 ,
struct V_36 * V_37 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_149 * V_150 = NULL ;
F_105 ( V_127 ) ;
int V_125 = 0 ;
int V_105 = 0 ;
int V_16 ;
int V_154 = 0 ;
if ( ! F_59 ( V_1 ) )
return - V_79 ;
F_139 ( V_57 -> V_69 ) ;
V_16 = F_62 ( V_57 , V_1 , V_3 , 1 ) ;
if ( V_16 )
return V_16 ;
if ( V_28 && ( V_28 -> V_29 & V_155 ) ) {
F_140 ( & V_28 -> V_156 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_157 ) {
V_28 -> V_33 = V_120 ;
F_17 ( & V_28 -> V_32 ) ;
F_141 ( & V_28 -> V_156 ) ;
F_18 ( V_1 ) -> V_80 = 0 ;
V_16 = 0 ;
V_154 = 1 ;
goto V_108;
}
F_17 ( & V_28 -> V_32 ) ;
}
V_16 = F_74 ( V_57 , V_1 , 0 ) ;
if ( V_16 )
goto V_108;
F_142 ( & F_18 ( V_1 ) -> V_137 , 0 , F_59 ( V_1 ) - 1 ,
0 , & V_150 ) ;
F_83 ( V_57 , V_37 -> V_44 ) ;
F_44 ( & V_95 -> V_158 ) ;
F_15 ( & V_95 -> V_100 ) ;
V_16 = F_116 ( V_57 , V_95 ,
V_28 , & V_125 , & V_105 ,
& V_127 ) ;
if ( V_16 )
goto V_159;
V_16 = F_125 ( V_3 , V_28 , V_57 , & V_125 ) ;
if ( V_16 )
goto V_159;
V_16 = F_129 ( V_57 , & V_127 ) ;
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
if ( V_16 )
goto V_160;
F_94 ( V_57 ) ;
V_16 = F_143 ( V_3 , V_1 , V_57 -> V_69 , V_57 -> V_66 ,
0 , F_59 ( V_1 ) , & V_150 ) ;
if ( V_16 )
goto V_160;
if ( V_28 && ( V_28 -> V_29 & V_155 ) )
F_141 ( & V_28 -> V_156 ) ;
F_70 ( V_57 ) ;
F_135 ( & F_18 ( V_1 ) -> V_137 , 0 ,
F_59 ( V_1 ) - 1 , & V_150 , V_62 ) ;
V_57 -> V_125 = V_125 ;
V_57 -> V_105 = V_105 ;
V_16 = F_144 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_16 )
goto V_108;
return 0 ;
V_108:
V_57 -> V_1 = NULL ;
F_66 ( V_57 ) ;
if ( V_16 ) {
F_136 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_80 = 0 ;
}
F_53 ( V_37 , V_3 , V_1 ) ;
if ( V_154 )
F_11 ( V_1 ) ;
return V_16 ;
V_159:
F_133 ( & V_127 ) ;
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
V_160:
F_134 ( V_1 , V_57 , & V_150 , & V_127 ) ;
if ( V_28 && ( V_28 -> V_29 & V_155 ) )
F_141 ( & V_28 -> V_156 ) ;
goto V_108;
}
int F_145 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_116 ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_33 < V_161 ) {
F_17 ( & V_28 -> V_32 ) ;
return 0 ;
}
F_17 ( & V_28 -> V_32 ) ;
V_1 = F_14 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_138 ( V_3 , V_1 , V_95 , V_28 ,
& V_28 -> V_57 , V_37 ,
V_5 , V_28 -> V_8 . V_17 ) ;
if ( V_16 ) {
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_13 ,
V_28 -> V_8 . V_17 ) ;
#endif
F_15 ( & V_28 -> V_32 ) ;
V_28 -> V_33 = V_153 ;
F_17 ( & V_28 -> V_32 ) ;
V_28 -> V_57 . V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_16 ;
}
static inline unsigned long F_146 ( T_1 V_162 , T_2 V_163 ,
T_1 V_6 )
{
ASSERT ( V_6 >= V_162 ) ;
V_6 -= V_162 ;
return ( unsigned long ) ( F_147 ( V_6 , V_163 ) ) ;
}
static inline unsigned long F_148 ( T_1 V_86 , T_2 V_163 )
{
return ( unsigned long ) ( F_147 ( V_86 , V_163 ) ) ;
}
static inline T_1 F_149 ( struct V_94 * V_95 ,
T_1 V_6 )
{
T_1 V_162 ;
T_2 V_164 ;
V_164 = V_165 * V_95 -> V_163 ;
V_162 = V_6 - V_95 -> V_136 ;
V_162 = F_147 ( V_162 , V_164 ) ;
V_162 *= V_164 ;
V_162 += V_95 -> V_136 ;
return V_162 ;
}
static int F_150 ( struct V_166 * V_3 , T_1 V_6 ,
struct V_97 * V_131 , int V_87 )
{
struct V_97 * * V_167 = & V_3 -> V_97 ;
struct V_97 * V_168 = NULL ;
struct V_92 * V_169 ;
while ( * V_167 ) {
V_168 = * V_167 ;
V_169 = F_100 ( V_168 , struct V_92 , V_102 ) ;
if ( V_6 < V_169 -> V_6 ) {
V_167 = & ( * V_167 ) -> V_170 ;
} else if ( V_6 > V_169 -> V_6 ) {
V_167 = & ( * V_167 ) -> V_171 ;
} else {
if ( V_87 ) {
if ( V_169 -> V_87 ) {
F_151 ( 1 ) ;
return - V_172 ;
}
V_167 = & ( * V_167 ) -> V_171 ;
} else {
if ( ! V_169 -> V_87 ) {
F_151 ( 1 ) ;
return - V_172 ;
}
V_167 = & ( * V_167 ) -> V_170 ;
}
}
}
F_152 ( V_131 , V_168 , V_167 ) ;
F_153 ( V_131 , V_3 ) ;
return 0 ;
}
static struct V_92 *
F_154 ( struct V_94 * V_95 ,
T_1 V_6 , int V_173 , int V_174 )
{
struct V_97 * V_98 = V_95 -> V_101 . V_97 ;
struct V_92 * V_89 , * V_96 = NULL ;
while ( 1 ) {
if ( ! V_98 ) {
V_89 = NULL ;
break;
}
V_89 = F_100 ( V_98 , struct V_92 , V_102 ) ;
V_96 = V_89 ;
if ( V_6 < V_89 -> V_6 )
V_98 = V_98 -> V_170 ;
else if ( V_6 > V_89 -> V_6 )
V_98 = V_98 -> V_171 ;
else
break;
}
if ( V_173 ) {
if ( ! V_89 )
return NULL ;
if ( V_89 -> V_87 )
return V_89 ;
V_98 = F_99 ( V_98 ) ;
if ( ! V_98 )
return NULL ;
V_89 = F_100 ( V_98 , struct V_92 , V_102 ) ;
if ( V_89 -> V_6 != V_6 )
return NULL ;
F_139 ( ! V_89 -> V_87 ) ;
return V_89 ;
} else if ( V_89 ) {
if ( V_89 -> V_87 ) {
V_98 = F_155 ( & V_89 -> V_102 ) ;
if ( V_98 ) {
V_96 = F_100 ( V_98 , struct V_92 ,
V_102 ) ;
if ( ! V_96 -> V_87 &&
V_96 -> V_6 + V_96 -> V_86 > V_6 )
V_89 = V_96 ;
}
}
return V_89 ;
}
if ( ! V_96 )
return NULL ;
V_89 = V_96 ;
if ( V_89 -> V_6 > V_6 ) {
V_98 = F_155 ( & V_89 -> V_102 ) ;
if ( V_98 ) {
V_89 = F_100 ( V_98 , struct V_92 ,
V_102 ) ;
ASSERT ( V_89 -> V_6 <= V_6 ) ;
} else {
if ( V_174 )
return V_89 ;
else
return NULL ;
}
}
if ( V_89 -> V_87 ) {
V_98 = F_155 ( & V_89 -> V_102 ) ;
if ( V_98 ) {
V_96 = F_100 ( V_98 , struct V_92 ,
V_102 ) ;
if ( ! V_96 -> V_87 &&
V_96 -> V_6 + V_96 -> V_86 > V_6 )
return V_96 ;
}
if ( V_89 -> V_6 + V_165 * V_95 -> V_163 > V_6 )
return V_89 ;
} else if ( V_89 -> V_6 + V_89 -> V_86 > V_6 )
return V_89 ;
if ( ! V_174 )
return NULL ;
while ( 1 ) {
if ( V_89 -> V_87 ) {
if ( V_89 -> V_6 + V_165 *
V_95 -> V_163 > V_6 )
break;
} else {
if ( V_89 -> V_6 + V_89 -> V_86 > V_6 )
break;
}
V_98 = F_99 ( & V_89 -> V_102 ) ;
if ( ! V_98 )
return NULL ;
V_89 = F_100 ( V_98 , struct V_92 , V_102 ) ;
}
return V_89 ;
}
static inline void
F_156 ( struct V_94 * V_95 ,
struct V_92 * V_169 )
{
F_157 ( & V_169 -> V_102 , & V_95 -> V_101 ) ;
V_95 -> V_175 -- ;
}
static void F_101 ( struct V_94 * V_95 ,
struct V_92 * V_169 )
{
F_156 ( V_95 , V_169 ) ;
V_95 -> V_123 -= V_169 -> V_86 ;
}
static int F_103 ( struct V_94 * V_95 ,
struct V_92 * V_169 )
{
int V_16 = 0 ;
ASSERT ( V_169 -> V_86 || V_169 -> V_87 ) ;
V_16 = F_150 ( & V_95 -> V_101 , V_169 -> V_6 ,
& V_169 -> V_102 , ( V_169 -> V_87 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_95 -> V_123 += V_169 -> V_86 ;
V_95 -> V_175 ++ ;
return V_16 ;
}
static void F_158 ( struct V_94 * V_95 )
{
struct V_27 * V_28 = V_95 -> V_176 ;
T_1 V_177 ;
T_1 V_178 ;
T_1 V_179 ;
T_1 V_75 = V_28 -> V_8 . V_6 ;
T_2 V_180 = V_165 * V_95 -> V_163 ;
T_2 V_181 = F_147 ( V_75 + V_180 - 1 , V_180 ) ;
V_181 = F_159 ( T_2 , V_181 , 1 ) ;
ASSERT ( V_95 -> V_110 <= V_181 ) ;
if ( V_75 < 1024 * 1024 * 1024 )
V_177 = V_182 ;
else
V_177 = V_182 *
F_147 ( V_75 , 1024 * 1024 * 1024 ) ;
V_178 = ( V_95 -> V_110 + 1 ) * V_68 ;
if ( V_178 >= V_177 ) {
V_95 -> V_183 = 0 ;
return;
}
V_179 = V_177 - V_178 ;
V_179 = F_160 ( T_1 , V_179 , V_177 >> 1 ) ;
V_95 -> V_183 =
F_147 ( V_179 , sizeof( struct V_92 ) ) ;
}
static inline void F_161 ( struct V_94 * V_95 ,
struct V_92 * V_169 ,
T_1 V_6 , T_1 V_86 )
{
unsigned long V_136 , V_184 ;
V_136 = F_146 ( V_169 -> V_6 , V_95 -> V_163 , V_6 ) ;
V_184 = F_148 ( V_86 , V_95 -> V_163 ) ;
ASSERT ( V_136 + V_184 <= V_165 ) ;
F_162 ( V_169 -> V_87 , V_136 , V_184 ) ;
V_169 -> V_86 -= V_86 ;
}
static void F_163 ( struct V_94 * V_95 ,
struct V_92 * V_169 , T_1 V_6 ,
T_1 V_86 )
{
F_161 ( V_95 , V_169 , V_6 , V_86 ) ;
V_95 -> V_123 -= V_86 ;
}
static void F_164 ( struct V_94 * V_95 ,
struct V_92 * V_169 , T_1 V_6 ,
T_1 V_86 )
{
unsigned long V_136 , V_184 ;
V_136 = F_146 ( V_169 -> V_6 , V_95 -> V_163 , V_6 ) ;
V_184 = F_148 ( V_86 , V_95 -> V_163 ) ;
ASSERT ( V_136 + V_184 <= V_165 ) ;
F_165 ( V_169 -> V_87 , V_136 , V_184 ) ;
V_169 -> V_86 += V_86 ;
V_95 -> V_123 += V_86 ;
}
static int F_166 ( struct V_94 * V_95 ,
struct V_92 * V_185 , T_1 * V_6 ,
T_1 * V_86 )
{
unsigned long V_186 = 0 ;
unsigned long V_187 = 0 ;
unsigned long V_188 , V_76 ;
unsigned long V_189 ;
unsigned long V_190 ;
V_76 = F_146 ( V_185 -> V_6 , V_95 -> V_163 ,
F_159 ( T_1 , * V_6 , V_185 -> V_6 ) ) ;
V_188 = F_148 ( * V_86 , V_95 -> V_163 ) ;
F_167 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
V_189 = F_168 ( V_185 -> V_87 ,
V_165 , V_76 ) ;
V_190 = V_189 - V_76 ;
if ( V_190 >= V_188 ) {
V_186 = V_190 ;
break;
} else if ( V_190 > V_187 ) {
V_187 = V_190 ;
}
V_76 = V_189 ;
}
if ( V_186 ) {
* V_6 = ( T_1 ) ( V_76 * V_95 -> V_163 ) + V_185 -> V_6 ;
* V_86 = ( T_1 ) ( V_186 ) * V_95 -> V_163 ;
return 0 ;
}
* V_86 = ( T_1 ) ( V_187 ) * V_95 -> V_163 ;
return - 1 ;
}
static struct V_92 *
F_169 ( struct V_94 * V_95 , T_1 * V_6 , T_1 * V_86 ,
unsigned long V_191 , T_1 * V_192 )
{
struct V_92 * V_89 ;
struct V_97 * V_131 ;
T_1 V_84 ;
T_1 V_193 ;
int V_16 ;
if ( ! V_95 -> V_101 . V_97 )
goto V_108;
V_89 = F_154 ( V_95 , F_149 ( V_95 , * V_6 ) , 0 , 1 ) ;
if ( ! V_89 )
goto V_108;
for ( V_131 = & V_89 -> V_102 ; V_131 ; V_131 = F_99 ( V_131 ) ) {
V_89 = F_100 ( V_131 , struct V_92 , V_102 ) ;
if ( V_89 -> V_86 < * V_86 ) {
if ( V_89 -> V_86 > * V_192 )
* V_192 = V_89 -> V_86 ;
continue;
}
if ( * V_86 >= V_191 ) {
V_84 = V_89 -> V_6 - V_95 -> V_136 + V_191 - 1 ;
V_84 = F_170 ( V_84 , V_191 ) ;
V_84 = V_84 * V_191 + V_95 -> V_136 ;
V_193 = V_84 - V_89 -> V_6 ;
} else {
V_193 = 0 ;
V_84 = V_89 -> V_6 ;
}
if ( V_89 -> V_86 < * V_86 + V_193 ) {
if ( V_89 -> V_86 > * V_192 )
* V_192 = V_89 -> V_86 ;
continue;
}
if ( V_89 -> V_87 ) {
T_1 V_75 = * V_86 ;
V_16 = F_166 ( V_95 , V_89 , & V_84 , & V_75 ) ;
if ( ! V_16 ) {
* V_6 = V_84 ;
* V_86 = V_75 ;
return V_89 ;
} else if ( V_75 > * V_192 ) {
* V_192 = V_75 ;
}
continue;
}
* V_6 = V_84 ;
* V_86 = V_89 -> V_86 - V_193 ;
return V_89 ;
}
V_108:
return NULL ;
}
static void F_171 ( struct V_94 * V_95 ,
struct V_92 * V_169 , T_1 V_6 )
{
V_169 -> V_6 = F_149 ( V_95 , V_6 ) ;
V_169 -> V_86 = 0 ;
F_172 ( & V_169 -> V_113 ) ;
F_103 ( V_95 , V_169 ) ;
V_95 -> V_110 ++ ;
V_95 -> V_111 -> V_112 ( V_95 ) ;
}
static void F_173 ( struct V_94 * V_95 ,
struct V_92 * V_185 )
{
F_101 ( V_95 , V_185 ) ;
F_61 ( V_185 -> V_87 ) ;
F_102 ( V_104 , V_185 ) ;
V_95 -> V_110 -- ;
V_95 -> V_111 -> V_112 ( V_95 ) ;
}
static T_7 int F_174 ( struct V_94 * V_95 ,
struct V_92 * V_185 ,
T_1 * V_6 , T_1 * V_86 )
{
T_1 V_194 ;
T_1 V_195 , V_196 ;
int V_16 ;
V_99:
V_194 = V_185 -> V_6 + ( T_1 ) ( V_165 * V_95 -> V_163 ) - 1 ;
V_195 = * V_6 ;
V_196 = V_95 -> V_163 ;
V_196 = F_128 ( V_196 , V_194 - V_195 + 1 ) ;
V_16 = F_166 ( V_95 , V_185 , & V_195 , & V_196 ) ;
if ( V_16 < 0 || V_195 != * V_6 )
return - V_197 ;
V_196 = F_128 ( V_196 , * V_86 ) ;
V_196 = F_128 ( V_196 , V_194 - V_195 + 1 ) ;
F_163 ( V_95 , V_185 , V_195 , V_196 ) ;
* V_6 += V_196 ;
* V_86 -= V_196 ;
if ( * V_86 ) {
struct V_97 * V_103 = F_99 ( & V_185 -> V_102 ) ;
if ( ! V_185 -> V_86 )
F_173 ( V_95 , V_185 ) ;
if ( ! V_103 )
return - V_197 ;
V_185 = F_100 ( V_103 , struct V_92 ,
V_102 ) ;
if ( ! V_185 -> V_87 )
return - V_198 ;
V_195 = * V_6 ;
V_196 = V_95 -> V_163 ;
V_16 = F_166 ( V_95 , V_185 , & V_195 ,
& V_196 ) ;
if ( V_16 < 0 || V_195 != * V_6 )
return - V_198 ;
goto V_99;
} else if ( ! V_185 -> V_86 )
F_173 ( V_95 , V_185 ) ;
return 0 ;
}
static T_1 F_175 ( struct V_94 * V_95 ,
struct V_92 * V_169 , T_1 V_6 ,
T_1 V_86 )
{
T_1 V_199 = 0 ;
T_1 V_194 ;
V_194 = V_169 -> V_6 + ( T_1 ) ( V_165 * V_95 -> V_163 ) ;
V_199 = F_128 ( V_194 - V_6 , V_86 ) ;
F_164 ( V_95 , V_169 , V_6 , V_199 ) ;
return V_199 ;
}
static bool F_176 ( struct V_94 * V_95 ,
struct V_92 * V_169 )
{
struct V_27 * V_28 = V_95 -> V_176 ;
if ( V_95 -> V_175 < V_95 -> V_183 ) {
if ( V_169 -> V_86 <= V_28 -> V_200 * 4 ) {
if ( V_95 -> V_175 * 2 <= V_95 -> V_183 )
return false ;
} else {
return false ;
}
}
if ( ( ( V_165 * V_95 -> V_163 ) >> 1 ) > V_28 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_177 ( struct V_94 * V_95 ,
struct V_92 * V_169 )
{
struct V_92 * V_185 ;
struct V_27 * V_28 = NULL ;
int V_201 = 0 ;
T_1 V_86 , V_6 , V_202 ;
int V_16 ;
V_86 = V_169 -> V_86 ;
V_6 = V_169 -> V_6 ;
if ( ! V_95 -> V_111 -> F_176 ( V_95 , V_169 ) )
return 0 ;
if ( V_95 -> V_111 == & V_203 )
V_28 = V_95 -> V_176 ;
V_99:
if ( V_28 && ! F_45 ( & V_28 -> V_134 ) ) {
struct V_128 * V_129 ;
struct V_97 * V_131 ;
struct V_92 * V_89 ;
V_129 = F_117 ( V_28 -> V_134 . V_103 ,
struct V_128 ,
V_135 ) ;
F_15 ( & V_129 -> V_32 ) ;
V_131 = F_98 ( & V_129 -> V_3 ) ;
if ( ! V_131 ) {
F_17 ( & V_129 -> V_32 ) ;
goto V_204;
}
V_89 = F_100 ( V_131 , struct V_92 , V_102 ) ;
if ( ! V_89 -> V_87 ) {
F_17 ( & V_129 -> V_32 ) ;
goto V_204;
}
if ( V_89 -> V_6 == F_149 ( V_95 , V_6 ) ) {
V_202 = F_175 ( V_95 , V_89 ,
V_6 , V_86 ) ;
V_86 -= V_202 ;
V_6 += V_202 ;
}
F_17 ( & V_129 -> V_32 ) ;
if ( ! V_86 ) {
V_16 = 1 ;
goto V_108;
}
}
V_204:
V_185 = F_154 ( V_95 , F_149 ( V_95 , V_6 ) ,
1 , 0 ) ;
if ( ! V_185 ) {
ASSERT ( V_201 == 0 ) ;
goto V_205;
}
V_202 = F_175 ( V_95 , V_185 , V_6 , V_86 ) ;
V_86 -= V_202 ;
V_6 += V_202 ;
V_201 = 0 ;
if ( ! V_86 ) {
V_16 = 1 ;
goto V_108;
} else
goto V_99;
V_205:
if ( V_169 && V_169 -> V_87 ) {
F_171 ( V_95 , V_169 , V_6 ) ;
V_201 = 1 ;
V_169 = NULL ;
goto V_99;
} else {
F_17 ( & V_95 -> V_100 ) ;
if ( ! V_169 ) {
V_169 = F_109 ( V_104 ,
V_62 ) ;
if ( ! V_169 ) {
F_15 ( & V_95 -> V_100 ) ;
V_16 = - V_52 ;
goto V_108;
}
}
V_169 -> V_87 = F_57 ( V_68 , V_62 ) ;
F_15 ( & V_95 -> V_100 ) ;
if ( ! V_169 -> V_87 ) {
V_16 = - V_52 ;
goto V_108;
}
goto V_99;
}
V_108:
if ( V_169 ) {
if ( V_169 -> V_87 )
F_61 ( V_169 -> V_87 ) ;
F_102 ( V_104 , V_169 ) ;
}
return V_16 ;
}
static bool F_178 ( struct V_94 * V_95 ,
struct V_92 * V_169 , bool V_206 )
{
struct V_92 * V_207 ;
struct V_92 * V_208 ;
bool V_209 = false ;
T_1 V_6 = V_169 -> V_6 ;
T_1 V_86 = V_169 -> V_86 ;
V_208 = F_154 ( V_95 , V_6 + V_86 , 0 , 0 ) ;
if ( V_208 && F_155 ( & V_208 -> V_102 ) )
V_207 = F_100 ( F_155 ( & V_208 -> V_102 ) ,
struct V_92 , V_102 ) ;
else
V_207 = F_154 ( V_95 , V_6 - 1 , 0 , 0 ) ;
if ( V_208 && ! V_208 -> V_87 ) {
if ( V_206 )
F_101 ( V_95 , V_208 ) ;
else
F_156 ( V_95 , V_208 ) ;
V_169 -> V_86 += V_208 -> V_86 ;
F_102 ( V_104 , V_208 ) ;
V_209 = true ;
}
if ( V_207 && ! V_207 -> V_87 &&
V_207 -> V_6 + V_207 -> V_86 == V_6 ) {
if ( V_206 )
F_101 ( V_95 , V_207 ) ;
else
F_156 ( V_95 , V_207 ) ;
V_169 -> V_6 = V_207 -> V_6 ;
V_169 -> V_86 += V_207 -> V_86 ;
F_102 ( V_104 , V_207 ) ;
V_209 = true ;
}
return V_209 ;
}
static bool F_179 ( struct V_94 * V_95 ,
struct V_92 * V_169 ,
bool V_206 )
{
struct V_92 * V_87 ;
unsigned long V_76 ;
unsigned long V_210 ;
const T_1 V_194 = V_169 -> V_6 + V_169 -> V_86 ;
const T_1 V_211 = F_149 ( V_95 , V_194 ) ;
T_1 V_86 ;
V_87 = F_154 ( V_95 , V_211 , 1 , 0 ) ;
if ( ! V_87 )
return false ;
V_76 = F_146 ( V_87 -> V_6 , V_95 -> V_163 , V_194 ) ;
V_210 = F_168 ( V_87 -> V_87 , V_165 , V_76 ) ;
if ( V_210 == V_76 )
return false ;
V_86 = ( V_210 - V_76 ) * V_95 -> V_163 ;
V_169 -> V_86 += V_86 ;
if ( V_206 )
F_163 ( V_95 , V_87 , V_194 , V_86 ) ;
else
F_161 ( V_95 , V_87 , V_194 , V_86 ) ;
if ( ! V_87 -> V_86 )
F_173 ( V_95 , V_87 ) ;
return true ;
}
static bool F_180 ( struct V_94 * V_95 ,
struct V_92 * V_169 ,
bool V_206 )
{
struct V_92 * V_87 ;
T_1 V_211 ;
unsigned long V_76 ;
unsigned long V_210 ;
unsigned long V_212 ;
T_1 V_86 ;
V_211 = F_149 ( V_95 , V_169 -> V_6 ) ;
if ( V_211 == V_169 -> V_6 ) {
if ( V_169 -> V_6 == 0 )
return false ;
V_211 = F_149 ( V_95 , V_169 -> V_6 - 1 ) ;
}
V_87 = F_154 ( V_95 , V_211 , 1 , 0 ) ;
if ( ! V_87 )
return false ;
V_76 = F_146 ( V_87 -> V_6 , V_95 -> V_163 , V_169 -> V_6 ) - 1 ;
V_210 = 0 ;
V_212 = ( unsigned long ) - 1 ;
F_181 (j, bitmap->bitmap, BITS_PER_BITMAP) {
if ( V_210 > V_76 )
break;
V_212 = V_210 ;
}
if ( V_212 == V_76 )
return false ;
if ( V_212 == ( unsigned long ) - 1 )
V_86 = ( V_76 + 1 ) * V_95 -> V_163 ;
else
V_86 = ( V_76 - V_212 ) * V_95 -> V_163 ;
V_169 -> V_6 -= V_86 ;
V_169 -> V_86 += V_86 ;
if ( V_206 )
F_163 ( V_95 , V_87 , V_169 -> V_6 , V_86 ) ;
else
F_161 ( V_95 , V_87 , V_169 -> V_6 , V_86 ) ;
if ( ! V_87 -> V_86 )
F_173 ( V_95 , V_87 ) ;
return true ;
}
static void F_182 ( struct V_94 * V_95 ,
struct V_92 * V_169 ,
bool V_206 )
{
ASSERT ( ! V_169 -> V_87 ) ;
ASSERT ( F_183 ( & V_169 -> V_102 ) ) ;
if ( V_95 -> V_110 > 0 ) {
bool V_213 ;
bool V_214 = false ;
V_213 = F_179 ( V_95 , V_169 , V_206 ) ;
if ( V_95 -> V_110 > 0 )
V_214 = F_180 ( V_95 , V_169 ,
V_206 ) ;
if ( V_213 || V_214 )
F_178 ( V_95 , V_169 , V_206 ) ;
}
}
int F_184 ( struct V_94 * V_95 ,
T_1 V_6 , T_1 V_86 )
{
struct V_92 * V_169 ;
int V_16 = 0 ;
V_169 = F_109 ( V_104 , V_62 ) ;
if ( ! V_169 )
return - V_52 ;
V_169 -> V_6 = V_6 ;
V_169 -> V_86 = V_86 ;
F_185 ( & V_169 -> V_102 ) ;
F_15 ( & V_95 -> V_100 ) ;
if ( F_178 ( V_95 , V_169 , true ) )
goto V_215;
V_16 = F_177 ( V_95 , V_169 ) ;
if ( V_16 < 0 ) {
goto V_108;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_108;
}
V_215:
F_182 ( V_95 , V_169 , true ) ;
V_16 = F_103 ( V_95 , V_169 ) ;
if ( V_16 )
F_102 ( V_104 , V_169 ) ;
V_108:
F_17 ( & V_95 -> V_100 ) ;
if ( V_16 ) {
F_186 ( V_216 L_14 , V_16 ) ;
ASSERT ( V_16 != - V_172 ) ;
}
return V_16 ;
}
int F_187 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_86 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_169 ;
int V_16 ;
bool V_217 = false ;
F_15 ( & V_95 -> V_100 ) ;
V_99:
V_16 = 0 ;
if ( ! V_86 )
goto V_218;
V_169 = F_154 ( V_95 , V_6 , 0 , 0 ) ;
if ( ! V_169 ) {
V_169 = F_154 ( V_95 , F_149 ( V_95 , V_6 ) ,
1 , 0 ) ;
if ( ! V_169 ) {
F_139 ( V_217 ) ;
goto V_218;
}
}
V_217 = false ;
if ( ! V_169 -> V_87 ) {
F_101 ( V_95 , V_169 ) ;
if ( V_6 == V_169 -> V_6 ) {
T_1 V_219 = F_128 ( V_86 , V_169 -> V_86 ) ;
V_169 -> V_86 -= V_219 ;
V_169 -> V_6 += V_219 ;
if ( V_169 -> V_86 ) {
V_16 = F_103 ( V_95 , V_169 ) ;
F_139 ( V_16 ) ;
} else {
F_102 ( V_104 , V_169 ) ;
}
V_6 += V_219 ;
V_86 -= V_219 ;
goto V_99;
} else {
T_1 V_220 = V_169 -> V_86 + V_169 -> V_6 ;
V_169 -> V_86 = V_6 - V_169 -> V_6 ;
V_16 = F_103 ( V_95 , V_169 ) ;
F_139 ( V_16 ) ;
if ( V_16 )
goto V_218;
if ( V_220 < V_6 + V_86 ) {
V_86 -= V_220 - V_6 ;
V_6 = V_220 ;
goto V_99;
} else if ( V_220 == V_6 + V_86 ) {
goto V_218;
}
F_17 ( & V_95 -> V_100 ) ;
V_16 = F_188 ( V_28 , V_6 + V_86 ,
V_220 - ( V_6 + V_86 ) ) ;
F_139 ( V_16 ) ;
goto V_108;
}
}
V_16 = F_174 ( V_95 , V_169 , & V_6 , & V_86 ) ;
if ( V_16 == - V_198 ) {
V_217 = true ;
goto V_99;
}
V_218:
F_17 ( & V_95 -> V_100 ) ;
V_108:
return V_16 ;
}
void F_189 ( struct V_27 * V_28 ,
T_1 V_86 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_169 ;
struct V_97 * V_98 ;
int V_184 = 0 ;
for ( V_98 = F_98 ( & V_95 -> V_101 ) ; V_98 ; V_98 = F_99 ( V_98 ) ) {
V_169 = F_100 ( V_98 , struct V_92 , V_102 ) ;
if ( V_169 -> V_86 >= V_86 && ! V_28 -> V_221 )
V_184 ++ ;
F_190 ( V_28 -> V_22 ,
L_15 ,
V_169 -> V_6 , V_169 -> V_86 ,
( V_169 -> V_87 ) ? L_16 : L_17 ) ;
}
F_19 ( V_28 -> V_22 , L_18 ,
F_45 ( & V_28 -> V_134 ) ? L_17 : L_16 ) ;
F_19 ( V_28 -> V_22 ,
L_19 , V_184 ) ;
}
void F_191 ( struct V_27 * V_28 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
F_192 ( & V_95 -> V_100 ) ;
V_95 -> V_163 = V_28 -> V_200 ;
V_95 -> V_136 = V_28 -> V_8 . V_17 ;
V_95 -> V_176 = V_28 ;
V_95 -> V_111 = & V_203 ;
F_172 ( & V_95 -> V_222 ) ;
F_193 ( & V_95 -> V_158 ) ;
V_95 -> V_183 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_92 ) ;
}
static int
F_194 (
struct V_27 * V_28 ,
struct V_128 * V_129 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_89 ;
struct V_97 * V_131 ;
F_15 ( & V_129 -> V_32 ) ;
if ( V_129 -> V_28 != V_28 )
goto V_108;
V_129 -> V_28 = NULL ;
V_129 -> V_223 = 0 ;
F_46 ( & V_129 -> V_135 ) ;
V_131 = F_98 ( & V_129 -> V_3 ) ;
while ( V_131 ) {
bool V_87 ;
V_89 = F_100 ( V_131 , struct V_92 , V_102 ) ;
V_131 = F_99 ( & V_89 -> V_102 ) ;
F_157 ( & V_89 -> V_102 , & V_129 -> V_3 ) ;
F_185 ( & V_89 -> V_102 ) ;
V_87 = ( V_89 -> V_87 != NULL ) ;
if ( ! V_87 ) {
F_178 ( V_95 , V_89 , false ) ;
F_182 ( V_95 , V_89 , false ) ;
}
F_150 ( & V_95 -> V_101 ,
V_89 -> V_6 , & V_89 -> V_102 , V_87 ) ;
}
V_129 -> V_3 = V_224 ;
V_108:
F_17 ( & V_129 -> V_32 ) ;
F_48 ( V_28 ) ;
return 0 ;
}
static void F_195 (
struct V_94 * V_95 )
{
struct V_92 * V_169 ;
struct V_97 * V_131 ;
while ( ( V_131 = F_196 ( & V_95 -> V_101 ) ) != NULL ) {
V_169 = F_100 ( V_131 , struct V_92 , V_102 ) ;
if ( ! V_169 -> V_87 ) {
F_101 ( V_95 , V_169 ) ;
F_102 ( V_104 , V_169 ) ;
} else {
F_173 ( V_95 , V_169 ) ;
}
F_197 ( & V_95 -> V_100 ) ;
}
}
void F_112 ( struct V_94 * V_95 )
{
F_15 ( & V_95 -> V_100 ) ;
F_195 ( V_95 ) ;
F_17 ( & V_95 -> V_100 ) ;
}
void F_198 ( struct V_27 * V_28 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_128 * V_129 ;
struct V_126 * V_225 ;
F_15 ( & V_95 -> V_100 ) ;
while ( ( V_225 = V_28 -> V_134 . V_103 ) !=
& V_28 -> V_134 ) {
V_129 = F_117 ( V_225 , struct V_128 ,
V_135 ) ;
F_139 ( V_129 -> V_28 != V_28 ) ;
F_194 ( V_28 , V_129 ) ;
F_197 ( & V_95 -> V_100 ) ;
}
F_195 ( V_95 ) ;
F_17 ( & V_95 -> V_100 ) ;
}
T_1 F_199 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_86 , T_1 V_226 ,
T_1 * V_192 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_89 = NULL ;
T_1 V_227 = V_86 + V_226 ;
T_1 V_16 = 0 ;
T_1 V_228 = 0 ;
T_1 V_229 = 0 ;
F_15 ( & V_95 -> V_100 ) ;
V_89 = F_169 ( V_95 , & V_6 , & V_227 ,
V_28 -> V_230 , V_192 ) ;
if ( ! V_89 )
goto V_108;
V_16 = V_6 ;
if ( V_89 -> V_87 ) {
F_163 ( V_95 , V_89 , V_6 , V_86 ) ;
if ( ! V_89 -> V_86 )
F_173 ( V_95 , V_89 ) ;
} else {
F_101 ( V_95 , V_89 ) ;
V_229 = V_6 - V_89 -> V_6 ;
V_228 = V_89 -> V_6 ;
V_89 -> V_6 = V_6 + V_86 ;
F_139 ( V_89 -> V_86 < V_86 + V_229 ) ;
V_89 -> V_86 -= V_86 + V_229 ;
if ( ! V_89 -> V_86 )
F_102 ( V_104 , V_89 ) ;
else
F_103 ( V_95 , V_89 ) ;
}
V_108:
F_17 ( & V_95 -> V_100 ) ;
if ( V_229 )
F_184 ( V_95 , V_228 , V_229 ) ;
return V_16 ;
}
int F_200 (
struct V_27 * V_28 ,
struct V_128 * V_129 )
{
struct V_94 * V_95 ;
int V_16 ;
F_15 ( & V_129 -> V_32 ) ;
if ( ! V_28 ) {
V_28 = V_129 -> V_28 ;
if ( ! V_28 ) {
F_17 ( & V_129 -> V_32 ) ;
return 0 ;
}
} else if ( V_129 -> V_28 != V_28 ) {
F_17 ( & V_129 -> V_32 ) ;
return 0 ;
}
F_201 ( & V_28 -> V_184 ) ;
F_17 ( & V_129 -> V_32 ) ;
V_95 = V_28 -> V_115 ;
F_15 ( & V_95 -> V_100 ) ;
V_16 = F_194 ( V_28 , V_129 ) ;
F_17 ( & V_95 -> V_100 ) ;
F_48 ( V_28 ) ;
return V_16 ;
}
static T_1 F_202 ( struct V_27 * V_28 ,
struct V_128 * V_129 ,
struct V_92 * V_89 ,
T_1 V_86 , T_1 V_231 ,
T_1 * V_192 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
int V_232 ;
T_1 V_195 = V_129 -> V_223 ;
T_1 V_196 = V_86 ;
T_1 V_16 = 0 ;
V_195 = V_231 ;
V_196 = V_86 ;
V_232 = F_166 ( V_95 , V_89 , & V_195 , & V_196 ) ;
if ( V_232 ) {
if ( V_196 > * V_192 )
* V_192 = V_196 ;
return 0 ;
}
V_16 = V_195 ;
F_161 ( V_95 , V_89 , V_16 , V_86 ) ;
return V_16 ;
}
T_1 F_203 ( struct V_27 * V_28 ,
struct V_128 * V_129 , T_1 V_86 ,
T_1 V_231 , T_1 * V_192 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_89 = NULL ;
struct V_97 * V_131 ;
T_1 V_16 = 0 ;
F_15 ( & V_129 -> V_32 ) ;
if ( V_86 > V_129 -> V_233 )
goto V_108;
if ( V_129 -> V_28 != V_28 )
goto V_108;
V_131 = F_98 ( & V_129 -> V_3 ) ;
if ( ! V_131 )
goto V_108;
V_89 = F_100 ( V_131 , struct V_92 , V_102 ) ;
while ( 1 ) {
if ( V_89 -> V_86 < V_86 && V_89 -> V_86 > * V_192 )
* V_192 = V_89 -> V_86 ;
if ( V_89 -> V_86 < V_86 ||
( ! V_89 -> V_87 && V_89 -> V_6 < V_231 ) ) {
V_131 = F_99 ( & V_89 -> V_102 ) ;
if ( ! V_131 )
break;
V_89 = F_100 ( V_131 , struct V_92 ,
V_102 ) ;
continue;
}
if ( V_89 -> V_87 ) {
V_16 = F_202 ( V_28 ,
V_129 , V_89 , V_86 ,
V_129 -> V_223 ,
V_192 ) ;
if ( V_16 == 0 ) {
V_131 = F_99 ( & V_89 -> V_102 ) ;
if ( ! V_131 )
break;
V_89 = F_100 ( V_131 , struct V_92 ,
V_102 ) ;
continue;
}
V_129 -> V_223 += V_86 ;
} else {
V_16 = V_89 -> V_6 ;
V_89 -> V_6 += V_86 ;
V_89 -> V_86 -= V_86 ;
}
if ( V_89 -> V_86 == 0 )
F_157 ( & V_89 -> V_102 , & V_129 -> V_3 ) ;
break;
}
V_108:
F_17 ( & V_129 -> V_32 ) ;
if ( ! V_16 )
return 0 ;
F_15 ( & V_95 -> V_100 ) ;
V_95 -> V_123 -= V_86 ;
if ( V_89 -> V_86 == 0 ) {
V_95 -> V_175 -- ;
if ( V_89 -> V_87 ) {
F_61 ( V_89 -> V_87 ) ;
V_95 -> V_110 -- ;
V_95 -> V_111 -> V_112 ( V_95 ) ;
}
F_102 ( V_104 , V_89 ) ;
}
F_17 ( & V_95 -> V_100 ) ;
return V_16 ;
}
static int F_204 ( struct V_27 * V_28 ,
struct V_92 * V_89 ,
struct V_128 * V_129 ,
T_1 V_6 , T_1 V_86 ,
T_1 V_234 , T_1 V_235 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
unsigned long V_189 ;
unsigned long V_76 ;
unsigned long V_236 ;
unsigned long V_237 ;
unsigned long V_186 ;
unsigned long V_136 = 0 ;
unsigned long V_238 = 0 ;
int V_16 ;
V_76 = F_146 ( V_89 -> V_6 , V_95 -> V_163 ,
F_159 ( T_1 , V_6 , V_89 -> V_6 ) ) ;
V_236 = F_148 ( V_86 , V_95 -> V_163 ) ;
V_237 = F_148 ( V_235 , V_95 -> V_163 ) ;
V_99:
V_186 = 0 ;
F_167 (i, entry->bitmap, BITS_PER_BITMAP) {
V_189 = F_168 ( V_89 -> V_87 ,
V_165 , V_76 ) ;
if ( V_189 - V_76 >= V_237 ) {
V_186 = V_189 - V_76 ;
break;
}
V_76 = V_189 ;
}
if ( ! V_186 )
return - V_50 ;
if ( ! V_238 ) {
V_136 = V_76 ;
V_129 -> V_233 = 0 ;
}
V_238 += V_186 ;
if ( V_129 -> V_233 < V_186 * V_95 -> V_163 )
V_129 -> V_233 = V_186 * V_95 -> V_163 ;
if ( V_238 < V_236 || V_129 -> V_233 < V_234 ) {
V_76 = V_189 + 1 ;
goto V_99;
}
V_129 -> V_223 = V_136 * V_95 -> V_163 + V_89 -> V_6 ;
F_157 ( & V_89 -> V_102 , & V_95 -> V_101 ) ;
V_16 = F_150 ( & V_129 -> V_3 , V_89 -> V_6 ,
& V_89 -> V_102 , 1 ) ;
ASSERT ( ! V_16 ) ;
F_205 ( V_28 , V_129 ,
V_238 * V_95 -> V_163 , 1 ) ;
return 0 ;
}
static T_7 int
F_206 ( struct V_27 * V_28 ,
struct V_128 * V_129 ,
struct V_126 * V_105 , T_1 V_6 , T_1 V_86 ,
T_1 V_234 , T_1 V_235 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_239 = NULL ;
struct V_92 * V_89 = NULL ;
struct V_92 * V_240 ;
struct V_97 * V_131 ;
T_1 V_241 ;
T_1 V_242 ;
T_1 V_243 = 0 ;
V_89 = F_154 ( V_95 , V_6 , 0 , 1 ) ;
if ( ! V_89 )
return - V_50 ;
while ( V_89 -> V_87 || V_89 -> V_86 < V_235 ) {
if ( V_89 -> V_87 && F_45 ( & V_89 -> V_113 ) )
F_110 ( & V_89 -> V_113 , V_105 ) ;
V_131 = F_99 ( & V_89 -> V_102 ) ;
if ( ! V_131 )
return - V_50 ;
V_89 = F_100 ( V_131 , struct V_92 , V_102 ) ;
}
V_241 = V_89 -> V_86 ;
V_242 = V_89 -> V_86 ;
V_239 = V_89 ;
V_240 = V_89 ;
for ( V_131 = F_99 ( & V_89 -> V_102 ) ; V_131 ;
V_131 = F_99 ( & V_89 -> V_102 ) ) {
V_89 = F_100 ( V_131 , struct V_92 , V_102 ) ;
if ( V_89 -> V_87 ) {
if ( F_45 ( & V_89 -> V_113 ) )
F_110 ( & V_89 -> V_113 , V_105 ) ;
continue;
}
if ( V_89 -> V_86 < V_235 )
continue;
V_240 = V_89 ;
V_241 += V_89 -> V_86 ;
if ( V_89 -> V_86 > V_242 )
V_242 = V_89 -> V_86 ;
}
if ( V_241 < V_86 || V_242 < V_234 )
return - V_50 ;
V_129 -> V_223 = V_239 -> V_6 ;
V_131 = & V_239 -> V_102 ;
do {
int V_16 ;
V_89 = F_100 ( V_131 , struct V_92 , V_102 ) ;
V_131 = F_99 ( & V_89 -> V_102 ) ;
if ( V_89 -> V_87 || V_89 -> V_86 < V_235 )
continue;
F_157 ( & V_89 -> V_102 , & V_95 -> V_101 ) ;
V_16 = F_150 ( & V_129 -> V_3 , V_89 -> V_6 ,
& V_89 -> V_102 , 0 ) ;
V_243 += V_89 -> V_86 ;
ASSERT ( ! V_16 ) ;
} while ( V_131 && V_89 != V_240 );
V_129 -> V_233 = V_242 ;
F_205 ( V_28 , V_129 , V_243 , 0 ) ;
return 0 ;
}
static T_7 int
F_207 ( struct V_27 * V_28 ,
struct V_128 * V_129 ,
struct V_126 * V_105 , T_1 V_6 , T_1 V_86 ,
T_1 V_234 , T_1 V_235 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_89 ;
int V_16 = - V_50 ;
T_1 V_211 = F_149 ( V_95 , V_6 ) ;
if ( V_95 -> V_110 == 0 )
return - V_50 ;
V_89 = F_208 ( V_105 , struct V_92 , V_113 ) ;
if ( V_89 -> V_6 != V_211 ) {
V_89 = F_154 ( V_95 , V_211 , 1 , 0 ) ;
if ( V_89 && F_45 ( & V_89 -> V_113 ) )
F_209 ( & V_89 -> V_113 , V_105 ) ;
}
F_118 (entry, bitmaps, list) {
if ( V_89 -> V_86 < V_86 )
continue;
V_16 = F_204 ( V_28 , V_89 , V_129 , V_6 ,
V_86 , V_234 , V_235 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_50 ;
}
int F_210 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_128 * V_129 ,
T_1 V_6 , T_1 V_86 , T_1 V_226 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_89 , * V_84 ;
F_105 ( V_105 ) ;
T_1 V_235 ;
T_1 V_234 ;
int V_16 ;
if ( F_211 ( V_3 , V_244 ) ) {
V_234 = V_235 = V_86 + V_226 ;
} else if ( V_28 -> V_29 & V_245 ) {
V_234 = V_86 ;
V_235 = V_28 -> V_200 ;
} else {
V_234 = F_127 ( V_86 , ( V_86 + V_226 ) >> 2 ) ;
V_235 = V_28 -> V_200 ;
}
F_15 ( & V_95 -> V_100 ) ;
if ( V_95 -> V_123 < V_86 ) {
F_17 ( & V_95 -> V_100 ) ;
return - V_50 ;
}
F_15 ( & V_129 -> V_32 ) ;
if ( V_129 -> V_28 ) {
V_16 = 0 ;
goto V_108;
}
F_212 ( V_28 , V_6 , V_86 , V_226 ,
V_235 ) ;
V_16 = F_206 ( V_28 , V_129 , & V_105 , V_6 ,
V_86 + V_226 ,
V_234 , V_235 ) ;
if ( V_16 )
V_16 = F_207 ( V_28 , V_129 , & V_105 ,
V_6 , V_86 + V_226 ,
V_234 , V_235 ) ;
F_111 (entry, tmp, &bitmaps, list)
F_46 ( & V_89 -> V_113 ) ;
if ( ! V_16 ) {
F_201 ( & V_28 -> V_184 ) ;
F_110 ( & V_129 -> V_135 ,
& V_28 -> V_134 ) ;
V_129 -> V_28 = V_28 ;
} else {
F_213 ( V_28 ) ;
}
V_108:
F_17 ( & V_129 -> V_32 ) ;
F_17 ( & V_95 -> V_100 ) ;
return V_16 ;
}
void F_214 ( struct V_128 * V_129 )
{
F_192 ( & V_129 -> V_32 ) ;
F_192 ( & V_129 -> V_246 ) ;
V_129 -> V_3 = V_224 ;
V_129 -> V_233 = 0 ;
F_172 ( & V_129 -> V_135 ) ;
V_129 -> V_28 = NULL ;
}
static int F_215 ( struct V_27 * V_28 ,
T_1 * V_247 , T_1 V_136 , T_1 V_86 ,
T_1 V_248 , T_1 V_249 ,
struct V_132 * V_133 )
{
struct V_250 * V_251 = V_28 -> V_251 ;
struct V_114 * V_22 = V_28 -> V_22 ;
struct V_94 * V_95 = V_28 -> V_115 ;
int V_16 ;
int V_252 = 0 ;
T_1 V_253 = 0 ;
F_15 ( & V_251 -> V_32 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( ! V_28 -> V_221 ) {
V_28 -> V_49 += V_249 ;
V_251 -> V_254 += V_249 ;
V_252 = 1 ;
}
F_17 ( & V_28 -> V_32 ) ;
F_17 ( & V_251 -> V_32 ) ;
V_16 = F_216 ( V_22 -> V_255 ,
V_136 , V_86 , & V_253 ) ;
if ( ! V_16 )
* V_247 += V_253 ;
F_44 ( & V_95 -> V_158 ) ;
F_188 ( V_28 , V_248 , V_249 ) ;
F_217 ( & V_133 -> V_113 ) ;
F_54 ( & V_95 -> V_158 ) ;
if ( V_252 ) {
F_15 ( & V_251 -> V_32 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_221 )
V_251 -> V_256 += V_249 ;
V_28 -> V_49 -= V_249 ;
V_251 -> V_254 -= V_249 ;
F_17 ( & V_251 -> V_32 ) ;
F_17 ( & V_28 -> V_32 ) ;
}
return V_16 ;
}
static int F_218 ( struct V_27 * V_28 ,
T_1 * V_247 , T_1 V_136 , T_1 V_194 , T_1 V_257 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_89 ;
struct V_97 * V_131 ;
int V_16 = 0 ;
T_1 V_142 ;
T_1 V_179 ;
T_1 V_86 ;
while ( V_136 < V_194 ) {
struct V_132 V_133 ;
F_44 ( & V_95 -> V_158 ) ;
F_15 ( & V_95 -> V_100 ) ;
if ( V_95 -> V_123 < V_257 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
break;
}
V_89 = F_154 ( V_95 , V_136 , 0 , 1 ) ;
if ( ! V_89 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
break;
}
while ( V_89 -> V_87 ) {
V_131 = F_99 ( & V_89 -> V_102 ) ;
if ( ! V_131 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
goto V_108;
}
V_89 = F_100 ( V_131 , struct V_92 ,
V_102 ) ;
}
if ( V_89 -> V_6 >= V_194 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
break;
}
V_142 = V_89 -> V_6 ;
V_179 = V_89 -> V_86 ;
V_136 = F_127 ( V_136 , V_142 ) ;
V_86 = F_128 ( V_142 + V_179 , V_194 ) - V_136 ;
if ( V_86 < V_257 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
goto V_103;
}
F_101 ( V_95 , V_89 ) ;
F_102 ( V_104 , V_89 ) ;
F_17 ( & V_95 -> V_100 ) ;
V_133 . V_136 = V_142 ;
V_133 . V_86 = V_179 ;
F_110 ( & V_133 . V_113 , & V_95 -> V_222 ) ;
F_54 ( & V_95 -> V_158 ) ;
V_16 = F_215 ( V_28 , V_247 , V_136 , V_86 ,
V_142 , V_179 , & V_133 ) ;
if ( V_16 )
break;
V_103:
V_136 += V_86 ;
if ( F_219 ( V_258 ) ) {
V_16 = - V_259 ;
break;
}
F_220 () ;
}
V_108:
return V_16 ;
}
static int F_221 ( struct V_27 * V_28 ,
T_1 * V_247 , T_1 V_136 , T_1 V_194 , T_1 V_257 )
{
struct V_94 * V_95 = V_28 -> V_115 ;
struct V_92 * V_89 ;
int V_16 = 0 ;
int V_260 ;
T_1 V_86 ;
T_1 V_6 = F_149 ( V_95 , V_136 ) ;
while ( V_6 < V_194 ) {
bool V_261 = false ;
struct V_132 V_133 ;
F_44 ( & V_95 -> V_158 ) ;
F_15 ( & V_95 -> V_100 ) ;
if ( V_95 -> V_123 < V_257 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
break;
}
V_89 = F_154 ( V_95 , V_6 , 1 , 0 ) ;
if ( ! V_89 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
V_261 = true ;
goto V_103;
}
V_86 = V_257 ;
V_260 = F_166 ( V_95 , V_89 , & V_136 , & V_86 ) ;
if ( V_260 || V_136 >= V_194 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
V_261 = true ;
goto V_103;
}
V_86 = F_128 ( V_86 , V_194 - V_136 ) ;
if ( V_86 < V_257 ) {
F_17 ( & V_95 -> V_100 ) ;
F_54 ( & V_95 -> V_158 ) ;
goto V_103;
}
F_163 ( V_95 , V_89 , V_136 , V_86 ) ;
if ( V_89 -> V_86 == 0 )
F_173 ( V_95 , V_89 ) ;
F_17 ( & V_95 -> V_100 ) ;
V_133 . V_136 = V_136 ;
V_133 . V_86 = V_86 ;
F_110 ( & V_133 . V_113 , & V_95 -> V_222 ) ;
F_54 ( & V_95 -> V_158 ) ;
V_16 = F_215 ( V_28 , V_247 , V_136 , V_86 ,
V_136 , V_86 , & V_133 ) ;
if ( V_16 )
break;
V_103:
if ( V_261 ) {
V_6 += V_165 * V_95 -> V_163 ;
} else {
V_136 += V_86 ;
if ( V_136 >= V_6 + V_165 * V_95 -> V_163 )
V_6 += V_165 * V_95 -> V_163 ;
}
if ( F_219 ( V_258 ) ) {
V_16 = - V_259 ;
break;
}
F_220 () ;
}
return V_16 ;
}
void F_222 ( struct V_27 * V_262 )
{
F_201 ( & V_262 -> V_263 ) ;
}
void F_223 ( struct V_27 * V_28 )
{
struct V_264 * V_265 ;
struct V_266 * V_267 ;
bool V_268 ;
F_15 ( & V_28 -> V_32 ) ;
V_268 = ( F_224 ( & V_28 -> V_263 ) &&
V_28 -> V_269 ) ;
F_17 ( & V_28 -> V_32 ) ;
if ( V_268 ) {
F_225 ( V_28 -> V_22 -> V_270 ) ;
V_265 = & V_28 -> V_22 -> V_271 . V_272 ;
F_226 ( & V_265 -> V_32 ) ;
V_267 = F_227 ( V_265 , V_28 -> V_8 . V_17 ,
1 ) ;
F_228 ( ! V_267 ) ;
F_229 ( V_265 , V_267 ) ;
F_230 ( & V_265 -> V_32 ) ;
F_231 ( V_28 -> V_22 -> V_270 ) ;
F_232 ( V_267 ) ;
F_232 ( V_267 ) ;
F_112 ( V_28 -> V_115 ) ;
}
}
int F_233 ( struct V_27 * V_28 ,
T_1 * V_253 , T_1 V_136 , T_1 V_194 , T_1 V_257 )
{
int V_16 ;
* V_253 = 0 ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_269 ) {
F_17 ( & V_28 -> V_32 ) ;
return 0 ;
}
F_222 ( V_28 ) ;
F_17 ( & V_28 -> V_32 ) ;
V_16 = F_218 ( V_28 , V_253 , V_136 , V_194 , V_257 ) ;
if ( V_16 )
goto V_108;
V_16 = F_221 ( V_28 , V_253 , V_136 , V_194 , V_257 ) ;
V_108:
F_223 ( V_28 ) ;
return V_16 ;
}
T_1 F_234 ( struct V_2 * V_273 )
{
struct V_94 * V_95 = V_273 -> V_274 ;
struct V_92 * V_89 = NULL ;
T_1 V_38 = 0 ;
F_15 ( & V_95 -> V_100 ) ;
if ( F_235 ( & V_95 -> V_101 ) )
goto V_108;
V_89 = F_100 ( F_98 ( & V_95 -> V_101 ) ,
struct V_92 , V_102 ) ;
if ( ! V_89 -> V_87 ) {
V_38 = V_89 -> V_6 ;
F_101 ( V_95 , V_89 ) ;
V_89 -> V_6 ++ ;
V_89 -> V_86 -- ;
if ( ! V_89 -> V_86 )
F_102 ( V_104 , V_89 ) ;
else
F_103 ( V_95 , V_89 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_184 = 1 ;
int V_16 ;
V_16 = F_166 ( V_95 , V_89 , & V_6 , & V_184 ) ;
ASSERT ( ! V_16 ) ;
V_38 = V_6 ;
F_163 ( V_95 , V_89 , V_6 , 1 ) ;
if ( V_89 -> V_86 == 0 )
F_173 ( V_95 , V_89 ) ;
}
V_108:
F_17 ( & V_95 -> V_100 ) ;
return V_38 ;
}
struct V_1 * F_236 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_275 ) ;
if ( V_3 -> V_276 )
V_1 = F_16 ( V_3 -> V_276 ) ;
F_17 ( & V_3 -> V_275 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_275 ) ;
if ( ! F_237 ( V_3 -> V_22 ) )
V_3 -> V_276 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_275 ) ;
return V_1 ;
}
int F_238 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_37 , V_5 ,
V_43 , 0 ) ;
}
int F_239 ( struct V_114 * V_22 , struct V_2 * V_3 )
{
struct V_94 * V_95 = V_3 -> V_274 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_277 = F_240 ( & V_3 -> V_278 ) ;
if ( ! F_211 ( V_3 , V_279 ) )
return 0 ;
if ( F_237 ( V_22 ) )
return 0 ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_236 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_108;
if ( V_277 != F_18 ( V_1 ) -> V_80 )
goto V_280;
V_16 = F_104 ( V_3 , V_1 , V_95 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_80 ( V_22 ,
L_20 ,
V_3 -> V_281 . V_17 ) ;
V_280:
F_11 ( V_1 ) ;
V_108:
F_49 ( V_5 ) ;
return V_16 ;
}
int F_241 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_94 * V_95 = V_3 -> V_274 ;
int V_16 ;
struct V_64 V_57 ;
bool V_282 = true ;
if ( ! F_211 ( V_3 , V_279 ) )
return 0 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_16 = F_138 ( V_3 , V_1 , V_95 , NULL , & V_57 ,
V_37 , V_5 , 0 ) ;
if ( ! V_16 ) {
V_282 = false ;
V_16 = F_47 ( V_3 , V_37 , NULL , & V_57 , V_5 , 0 ) ;
}
if ( V_16 ) {
if ( V_282 )
F_242 ( V_1 , V_1 -> V_138 ) ;
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_21 ,
V_3 -> V_281 . V_17 ) ;
#endif
}
return V_16 ;
}
int F_243 ( struct V_27 * V_262 ,
T_1 V_6 , T_1 V_86 , bool V_87 )
{
struct V_94 * V_95 = V_262 -> V_115 ;
struct V_92 * V_169 = NULL , * V_185 ;
void * V_283 = NULL ;
T_1 V_202 ;
int V_16 ;
V_99:
if ( ! V_169 ) {
V_169 = F_109 ( V_104 , V_62 ) ;
if ( ! V_169 )
return - V_52 ;
}
if ( ! V_87 ) {
F_15 ( & V_95 -> V_100 ) ;
V_169 -> V_6 = V_6 ;
V_169 -> V_86 = V_86 ;
V_16 = F_103 ( V_95 , V_169 ) ;
F_17 ( & V_95 -> V_100 ) ;
if ( V_16 )
F_102 ( V_104 , V_169 ) ;
return V_16 ;
}
if ( ! V_283 ) {
V_283 = F_57 ( V_68 , V_62 ) ;
if ( ! V_283 ) {
F_102 ( V_104 , V_169 ) ;
return - V_52 ;
}
}
F_15 ( & V_95 -> V_100 ) ;
V_185 = F_154 ( V_95 , F_149 ( V_95 , V_6 ) ,
1 , 0 ) ;
if ( ! V_185 ) {
V_169 -> V_87 = V_283 ;
V_283 = NULL ;
F_171 ( V_95 , V_169 , V_6 ) ;
V_185 = V_169 ;
V_169 = NULL ;
}
V_202 = F_175 ( V_95 , V_185 , V_6 , V_86 ) ;
V_86 -= V_202 ;
V_6 += V_202 ;
F_17 ( & V_95 -> V_100 ) ;
if ( V_86 )
goto V_99;
if ( V_169 )
F_102 ( V_104 , V_169 ) ;
if ( V_283 )
F_61 ( V_283 ) ;
return 0 ;
}
int F_244 ( struct V_27 * V_262 ,
T_1 V_6 , T_1 V_86 )
{
struct V_94 * V_95 = V_262 -> V_115 ;
struct V_92 * V_169 ;
int V_16 = 0 ;
F_15 ( & V_95 -> V_100 ) ;
V_169 = F_154 ( V_95 , V_6 , 0 , 0 ) ;
if ( ! V_169 ) {
V_169 = F_154 ( V_95 , F_149 ( V_95 , V_6 ) ,
1 , 0 ) ;
if ( ! V_169 )
goto V_108;
}
V_284:
if ( V_169 -> V_87 ) {
T_1 V_285 , V_286 ;
struct V_97 * V_98 ;
struct V_92 * V_84 ;
V_285 = V_6 ;
V_286 = V_95 -> V_163 ;
V_16 = F_166 ( V_95 , V_169 , & V_285 , & V_286 ) ;
if ( ! V_16 ) {
if ( V_285 == V_6 ) {
V_16 = 1 ;
goto V_108;
} else if ( V_285 > V_6 &&
V_6 + V_86 > V_285 ) {
V_16 = 1 ;
goto V_108;
}
}
V_98 = F_155 ( & V_169 -> V_102 ) ;
while ( V_98 ) {
V_84 = F_100 ( V_98 , struct V_92 ,
V_102 ) ;
if ( V_84 -> V_6 + V_84 -> V_86 < V_6 )
break;
if ( V_6 + V_86 < V_84 -> V_6 ) {
V_98 = F_155 ( & V_169 -> V_102 ) ;
continue;
}
V_169 = V_84 ;
goto V_284;
}
V_98 = F_99 ( & V_169 -> V_102 ) ;
while ( V_98 ) {
V_84 = F_100 ( V_98 , struct V_92 ,
V_102 ) ;
if ( V_6 + V_86 < V_84 -> V_6 )
break;
if ( V_84 -> V_6 + V_84 -> V_86 < V_6 ) {
V_98 = F_99 ( & V_169 -> V_102 ) ;
continue;
}
V_169 = V_84 ;
goto V_284;
}
V_16 = 0 ;
goto V_108;
}
if ( V_169 -> V_6 == V_6 ) {
V_16 = 1 ;
goto V_108;
}
if ( V_6 > V_169 -> V_6 && V_6 < V_169 -> V_6 + V_169 -> V_86 )
V_16 = 1 ;
V_108:
F_17 ( & V_95 -> V_100 ) ;
return V_16 ;
}
