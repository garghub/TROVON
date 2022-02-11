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
F_13 ( V_1 -> V_24 ,
~ ( V_25 | V_26 ) ) ) ;
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
F_87 ( V_57 -> V_3 -> V_22 ,
L_3 ,
* V_82 , V_80 ) ;
F_67 ( V_57 ) ;
return - V_79 ;
}
V_57 -> V_71 += sizeof( T_1 ) ;
return 0 ;
}
static void F_88 ( struct V_64 * V_57 , int V_74 )
{
T_2 * V_83 ;
T_2 V_84 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_67 ) {
F_67 ( V_57 ) ;
return;
}
if ( V_74 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_66 ;
V_84 = F_89 ( V_57 -> V_72 + V_6 , V_84 ,
V_68 - V_6 ) ;
F_90 ( V_84 , ( char * ) & V_84 ) ;
F_67 ( V_57 ) ;
V_83 = F_69 ( V_57 -> V_69 [ 0 ] ) ;
V_83 += V_74 ;
* V_83 = V_84 ;
}
static int F_91 ( struct V_64 * V_57 , int V_74 )
{
T_2 * V_83 , V_81 ;
T_2 V_84 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_67 ) {
F_68 ( V_57 , 0 ) ;
return 0 ;
}
if ( V_74 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_66 ;
V_83 = F_69 ( V_57 -> V_69 [ 0 ] ) ;
V_83 += V_74 ;
V_81 = * V_83 ;
F_68 ( V_57 , 0 ) ;
V_84 = F_89 ( V_57 -> V_72 + V_6 , V_84 ,
V_68 - V_6 ) ;
F_90 ( V_84 , ( char * ) & V_84 ) ;
if ( V_81 != V_84 ) {
F_87 ( V_57 -> V_3 -> V_22 ,
L_4 ) ;
F_67 ( V_57 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_92 ( struct V_64 * V_57 , T_1 V_6 , T_1 V_85 ,
void * V_86 )
{
struct V_87 * V_88 ;
if ( ! V_57 -> V_71 )
return - V_50 ;
V_88 = V_57 -> V_71 ;
V_88 -> V_6 = F_84 ( V_6 ) ;
V_88 -> V_85 = F_84 ( V_85 ) ;
V_88 -> type = ( V_86 ) ? V_89 :
V_90 ;
V_57 -> V_71 += sizeof( struct V_87 ) ;
V_57 -> V_75 -= sizeof( struct V_87 ) ;
if ( V_57 -> V_75 >= sizeof( struct V_87 ) )
return 0 ;
F_88 ( V_57 , V_57 -> V_74 - 1 ) ;
if ( V_57 -> V_74 >= V_57 -> V_66 )
return 0 ;
F_68 ( V_57 , 1 ) ;
return 0 ;
}
static int F_93 ( struct V_64 * V_57 , void * V_86 )
{
if ( ! V_57 -> V_71 )
return - V_50 ;
if ( V_57 -> V_71 != V_57 -> V_72 ) {
F_88 ( V_57 , V_57 -> V_74 - 1 ) ;
if ( V_57 -> V_74 >= V_57 -> V_66 )
return - V_50 ;
F_68 ( V_57 , 0 ) ;
}
memcpy ( V_57 -> V_71 , V_86 , V_68 ) ;
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
struct V_91 * V_88 , T_5 * type )
{
struct V_87 * V_92 ;
int V_16 ;
if ( ! V_57 -> V_71 ) {
V_16 = F_91 ( V_57 , V_57 -> V_74 ) ;
if ( V_16 )
return V_16 ;
}
V_92 = V_57 -> V_71 ;
V_88 -> V_6 = F_86 ( V_92 -> V_6 ) ;
V_88 -> V_85 = F_86 ( V_92 -> V_85 ) ;
* type = V_92 -> type ;
V_57 -> V_71 += sizeof( struct V_87 ) ;
V_57 -> V_75 -= sizeof( struct V_87 ) ;
if ( V_57 -> V_75 >= sizeof( struct V_87 ) )
return 0 ;
F_67 ( V_57 ) ;
return 0 ;
}
static int F_96 ( struct V_64 * V_57 ,
struct V_91 * V_88 )
{
int V_16 ;
V_16 = F_91 ( V_57 , V_57 -> V_74 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_88 -> V_86 , V_57 -> V_71 , V_68 ) ;
F_67 ( V_57 ) ;
return 0 ;
}
static void F_97 ( struct V_93 * V_94 )
{
struct V_91 * V_92 , * V_95 = NULL ;
struct V_96 * V_97 ;
V_98:
F_15 ( & V_94 -> V_99 ) ;
for ( V_97 = F_98 ( & V_94 -> V_100 ) ; V_97 ; V_97 = F_99 ( V_97 ) ) {
V_92 = F_100 ( V_97 , struct V_91 , V_101 ) ;
if ( ! V_95 )
goto V_102;
if ( V_92 -> V_86 || V_95 -> V_86 )
goto V_102;
if ( V_95 -> V_6 + V_95 -> V_85 == V_92 -> V_6 ) {
F_101 ( V_94 , V_95 ) ;
F_101 ( V_94 , V_92 ) ;
V_95 -> V_85 += V_92 -> V_85 ;
F_102 ( V_103 , V_92 ) ;
F_103 ( V_94 , V_95 ) ;
V_95 = NULL ;
F_17 ( & V_94 -> V_99 ) ;
goto V_98;
}
V_102:
V_95 = V_92 ;
}
F_17 ( & V_94 -> V_99 ) ;
}
static int F_104 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_93 * V_94 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_64 V_57 ;
struct V_7 V_8 ;
struct V_91 * V_92 , * V_97 ;
F_105 ( V_104 ) ;
T_1 V_105 ;
T_1 V_106 ;
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
V_105 = F_106 ( V_15 , V_13 ) ;
V_106 = F_107 ( V_15 , V_13 ) ;
V_80 = F_108 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( ! F_18 ( V_1 ) -> V_80 ) {
F_19 ( V_3 -> V_22 ,
L_5 ,
V_6 ) ;
return 0 ;
}
if ( F_18 ( V_1 ) -> V_80 != V_80 ) {
F_80 ( V_3 -> V_22 ,
L_6
L_7 ,
F_18 ( V_1 ) -> V_80 , V_80 ) ;
return 0 ;
}
if ( ! V_105 )
return 0 ;
V_16 = F_62 ( & V_57 , V_1 , V_3 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_56 ( V_1 ) ;
if ( V_16 )
goto V_107;
V_16 = F_74 ( & V_57 , V_1 , 1 ) ;
if ( V_16 )
goto V_107;
V_16 = F_91 ( & V_57 , 0 ) ;
if ( V_16 )
goto V_108;
V_16 = F_85 ( & V_57 , V_80 ) ;
if ( V_16 )
goto V_108;
while ( V_105 ) {
V_92 = F_109 ( V_103 ,
V_62 ) ;
if ( ! V_92 )
goto V_108;
V_16 = F_95 ( & V_57 , V_92 , & type ) ;
if ( V_16 ) {
F_102 ( V_103 , V_92 ) ;
goto V_108;
}
if ( ! V_92 -> V_85 ) {
F_102 ( V_103 , V_92 ) ;
goto V_108;
}
if ( type == V_90 ) {
F_15 ( & V_94 -> V_99 ) ;
V_16 = F_103 ( V_94 , V_92 ) ;
F_17 ( & V_94 -> V_99 ) ;
if ( V_16 ) {
F_80 ( V_3 -> V_22 ,
L_8 ) ;
F_102 ( V_103 , V_92 ) ;
goto V_108;
}
} else {
ASSERT ( V_106 ) ;
V_106 -- ;
V_92 -> V_86 = F_57 ( V_68 , V_62 ) ;
if ( ! V_92 -> V_86 ) {
F_102 (
V_103 , V_92 ) ;
goto V_108;
}
F_15 ( & V_94 -> V_99 ) ;
V_16 = F_103 ( V_94 , V_92 ) ;
V_94 -> V_109 ++ ;
V_94 -> V_110 -> V_111 ( V_94 ) ;
F_17 ( & V_94 -> V_99 ) ;
if ( V_16 ) {
F_80 ( V_3 -> V_22 ,
L_8 ) ;
F_102 ( V_103 , V_92 ) ;
goto V_108;
}
F_110 ( & V_92 -> V_112 , & V_104 ) ;
}
V_105 -- ;
}
F_67 ( & V_57 ) ;
F_111 (e, n, &bitmaps, list) {
F_46 ( & V_92 -> V_112 ) ;
V_16 = F_96 ( & V_57 , V_92 ) ;
if ( V_16 )
goto V_108;
}
F_70 ( & V_57 ) ;
F_97 ( V_94 ) ;
V_16 = 1 ;
V_107:
F_66 ( & V_57 ) ;
return V_16 ;
V_108:
F_70 ( & V_57 ) ;
F_112 ( V_94 ) ;
goto V_107;
}
int F_113 ( struct V_113 * V_22 ,
struct V_27 * V_28 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_2 * V_3 = V_22 -> V_115 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 = 0 ;
bool V_116 ;
T_1 V_117 = F_114 ( & V_28 -> V_118 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_33 != V_119 ) {
F_17 ( & V_28 -> V_32 ) ;
return 0 ;
}
F_17 ( & V_28 -> V_32 ) ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_120 = 1 ;
V_5 -> V_121 = 1 ;
V_1 = F_14 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_49 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_33 != V_119 ) {
F_17 ( & V_28 -> V_32 ) ;
F_49 ( V_5 ) ;
goto V_107;
}
F_17 ( & V_28 -> V_32 ) ;
V_16 = F_104 ( V_22 -> V_115 , V_1 , V_94 ,
V_5 , V_28 -> V_8 . V_17 ) ;
F_49 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_107;
F_15 ( & V_94 -> V_99 ) ;
V_116 = ( V_94 -> V_122 == ( V_28 -> V_8 . V_6 - V_117 -
V_28 -> V_123 ) ) ;
F_17 ( & V_94 -> V_99 ) ;
if ( ! V_116 ) {
F_112 ( V_94 ) ;
F_115 ( V_22 , L_9 ,
V_28 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_107:
if ( V_16 < 0 ) {
F_15 ( & V_28 -> V_32 ) ;
V_28 -> V_33 = V_34 ;
F_17 ( & V_28 -> V_32 ) ;
V_16 = 0 ;
F_115 ( V_22 , L_10 ,
V_28 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
static T_6
int F_116 ( struct V_64 * V_57 ,
struct V_93 * V_94 ,
struct V_27 * V_28 ,
int * V_124 , int * V_104 ,
struct V_125 * V_126 )
{
int V_16 ;
struct V_127 * V_128 = NULL ;
struct V_127 * V_129 = NULL ;
struct V_96 * V_130 = F_98 ( & V_94 -> V_100 ) ;
struct V_131 * V_132 ;
if ( V_28 && ! F_45 ( & V_28 -> V_133 ) ) {
V_128 = F_117 ( V_28 -> V_133 . V_102 ,
struct V_127 ,
V_134 ) ;
}
if ( ! V_130 && V_128 ) {
V_129 = V_128 ;
F_15 ( & V_129 -> V_32 ) ;
V_130 = F_98 ( & V_128 -> V_3 ) ;
V_128 = NULL ;
}
while ( V_130 ) {
struct V_91 * V_92 ;
V_92 = F_100 ( V_130 , struct V_91 , V_101 ) ;
* V_124 += 1 ;
V_16 = F_92 ( V_57 , V_92 -> V_6 , V_92 -> V_85 ,
V_92 -> V_86 ) ;
if ( V_16 )
goto V_53;
if ( V_92 -> V_86 ) {
F_110 ( & V_92 -> V_112 , V_126 ) ;
* V_104 += 1 ;
}
V_130 = F_99 ( V_130 ) ;
if ( ! V_130 && V_128 ) {
V_130 = F_98 ( & V_128 -> V_3 ) ;
V_129 = V_128 ;
F_15 ( & V_129 -> V_32 ) ;
V_128 = NULL ;
}
}
if ( V_129 ) {
F_17 ( & V_129 -> V_32 ) ;
V_129 = NULL ;
}
F_118 (trim_entry, &ctl->trimming_ranges, list) {
V_16 = F_92 ( V_57 , V_132 -> V_135 ,
V_132 -> V_85 , NULL ) ;
if ( V_16 )
goto V_53;
* V_124 += 1 ;
}
return 0 ;
V_53:
if ( V_129 )
F_17 ( & V_129 -> V_32 ) ;
return - V_50 ;
}
static T_6 int
F_119 ( struct V_36 * V_37 ,
struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 , T_1 V_6 ,
int V_124 , int V_104 )
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
F_120 ( & F_18 ( V_1 ) -> V_136 , 0 , V_1 -> V_137 - 1 ,
V_138 | V_139 , 0 , 0 , NULL ,
V_62 ) ;
goto V_53;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_140 ;
ASSERT ( V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_121 ( V_15 , & V_140 , V_5 -> V_21 [ 0 ] ) ;
if ( V_140 . V_17 != V_18 ||
V_140 . V_6 != V_6 ) {
F_120 ( & F_18 ( V_1 ) -> V_136 , 0 ,
V_1 -> V_137 - 1 ,
V_138 | V_139 , 0 , 0 ,
NULL , V_62 ) ;
F_4 ( V_5 ) ;
goto V_53;
}
}
F_18 ( V_1 ) -> V_80 = V_37 -> V_44 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_122 ( V_15 , V_13 , V_124 ) ;
F_123 ( V_15 , V_13 , V_104 ) ;
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
int * V_124 )
{
T_1 V_135 , V_141 , V_142 , V_143 ;
struct V_144 * V_145 = NULL ;
int V_16 ;
if ( ! V_28 )
return 0 ;
V_145 = V_3 -> V_22 -> V_146 ;
V_135 = V_28 -> V_8 . V_17 ;
while ( V_135 < V_28 -> V_8 . V_17 + V_28 -> V_8 . V_6 ) {
V_16 = F_126 ( V_145 , V_135 ,
& V_141 , & V_142 ,
V_138 , NULL ) ;
if ( V_16 )
return 0 ;
if ( V_141 >= V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 )
return 0 ;
V_141 = F_127 ( V_141 , V_135 ) ;
V_142 = F_128 ( V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 , V_142 + 1 ) ;
V_143 = V_142 - V_141 ;
* V_124 += 1 ;
V_16 = F_92 ( V_57 , V_141 , V_143 , NULL ) ;
if ( V_16 )
return - V_50 ;
V_135 = V_142 ;
}
return 0 ;
}
static T_6 int
F_129 ( struct V_64 * V_57 , struct V_125 * V_126 )
{
struct V_125 * V_147 , * V_97 ;
int V_16 ;
F_130 (pos, n, bitmap_list) {
struct V_91 * V_88 =
F_117 ( V_147 , struct V_91 , V_112 ) ;
V_16 = F_93 ( V_57 , V_88 -> V_86 ) ;
if ( V_16 )
return - V_50 ;
F_46 ( & V_88 -> V_112 ) ;
}
return 0 ;
}
static int F_131 ( struct V_1 * V_1 )
{
int V_16 ;
V_16 = F_132 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_16 )
F_120 ( & F_18 ( V_1 ) -> V_136 , 0 , V_1 -> V_137 - 1 ,
V_138 | V_139 , 0 , 0 , NULL ,
V_62 ) ;
return V_16 ;
}
static void T_6
F_133 ( struct V_125 * V_126 )
{
struct V_125 * V_147 , * V_97 ;
F_130 (pos, n, bitmap_list) {
struct V_91 * V_88 =
F_117 ( V_147 , struct V_91 , V_112 ) ;
F_46 ( & V_88 -> V_112 ) ;
}
}
static void T_6
F_134 ( struct V_1 * V_1 ,
struct V_64 * V_57 ,
struct V_148 * * V_149 ,
struct V_125 * V_126 )
{
F_70 ( V_57 ) ;
F_135 ( & F_18 ( V_1 ) -> V_136 , 0 ,
F_59 ( V_1 ) - 1 , V_149 ,
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
V_3 = V_3 -> V_22 -> V_115 ;
V_16 = F_131 ( V_1 ) ;
if ( V_16 )
goto V_107;
V_16 = F_119 ( V_37 , V_3 , V_1 , V_5 , V_6 ,
V_57 -> V_124 , V_57 -> V_104 ) ;
V_107:
F_66 ( V_57 ) ;
if ( V_16 ) {
F_136 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_80 = 0 ;
if ( V_28 ) {
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_11 ,
V_28 -> V_8 . V_17 ) ;
#endif
}
}
F_53 ( V_37 , V_3 , V_1 ) ;
if ( V_28 ) {
F_15 ( & V_37 -> V_54 -> V_150 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( ! V_16 && F_45 ( & V_28 -> V_151 ) )
V_28 -> V_33 = V_119 ;
else if ( V_16 )
V_28 -> V_33 = V_152 ;
F_17 ( & V_28 -> V_32 ) ;
F_17 ( & V_37 -> V_54 -> V_150 ) ;
V_57 -> V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_16 ;
}
static int F_138 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_93 * V_94 ,
struct V_27 * V_28 ,
struct V_64 * V_57 ,
struct V_36 * V_37 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_148 * V_149 = NULL ;
F_105 ( V_126 ) ;
int V_124 = 0 ;
int V_104 = 0 ;
int V_16 ;
int V_153 = 0 ;
if ( ! F_59 ( V_1 ) )
return - V_79 ;
F_139 ( V_57 -> V_69 ) ;
V_16 = F_62 ( V_57 , V_1 , V_3 , 1 ) ;
if ( V_16 )
return V_16 ;
if ( V_28 && ( V_28 -> V_29 & V_154 ) ) {
F_140 ( & V_28 -> V_155 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_156 ) {
V_28 -> V_33 = V_119 ;
F_17 ( & V_28 -> V_32 ) ;
F_141 ( & V_28 -> V_155 ) ;
F_18 ( V_1 ) -> V_80 = 0 ;
V_16 = 0 ;
V_153 = 1 ;
goto V_107;
}
F_17 ( & V_28 -> V_32 ) ;
}
V_16 = F_74 ( V_57 , V_1 , 0 ) ;
if ( V_16 )
goto V_107;
F_142 ( & F_18 ( V_1 ) -> V_136 , 0 , F_59 ( V_1 ) - 1 ,
0 , & V_149 ) ;
F_83 ( V_57 , V_37 -> V_44 ) ;
F_44 ( & V_94 -> V_157 ) ;
F_15 ( & V_94 -> V_99 ) ;
V_16 = F_116 ( V_57 , V_94 ,
V_28 , & V_124 , & V_104 ,
& V_126 ) ;
if ( V_16 )
goto V_158;
V_16 = F_125 ( V_3 , V_28 , V_57 , & V_124 ) ;
if ( V_16 )
goto V_158;
V_16 = F_129 ( V_57 , & V_126 ) ;
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
if ( V_16 )
goto V_159;
F_94 ( V_57 ) ;
V_16 = F_143 ( V_3 , V_1 , V_57 -> V_69 , V_57 -> V_66 ,
0 , F_59 ( V_1 ) , & V_149 ) ;
if ( V_16 )
goto V_159;
if ( V_28 && ( V_28 -> V_29 & V_154 ) )
F_141 ( & V_28 -> V_155 ) ;
F_70 ( V_57 ) ;
F_135 ( & F_18 ( V_1 ) -> V_136 , 0 ,
F_59 ( V_1 ) - 1 , & V_149 , V_62 ) ;
V_57 -> V_124 = V_124 ;
V_57 -> V_104 = V_104 ;
V_16 = F_144 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_16 )
goto V_107;
return 0 ;
V_107:
V_57 -> V_1 = NULL ;
F_66 ( V_57 ) ;
if ( V_16 ) {
F_136 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_80 = 0 ;
}
F_53 ( V_37 , V_3 , V_1 ) ;
if ( V_153 )
F_11 ( V_1 ) ;
return V_16 ;
V_158:
F_133 ( & V_126 ) ;
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
V_159:
F_134 ( V_1 , V_57 , & V_149 , & V_126 ) ;
if ( V_28 && ( V_28 -> V_29 & V_154 ) )
F_141 ( & V_28 -> V_155 ) ;
goto V_107;
}
int F_145 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_115 ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_33 < V_160 ) {
F_17 ( & V_28 -> V_32 ) ;
return 0 ;
}
F_17 ( & V_28 -> V_32 ) ;
V_1 = F_14 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_138 ( V_3 , V_1 , V_94 , V_28 ,
& V_28 -> V_57 , V_37 ,
V_5 , V_28 -> V_8 . V_17 ) ;
if ( V_16 ) {
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_11 ,
V_28 -> V_8 . V_17 ) ;
#endif
F_15 ( & V_28 -> V_32 ) ;
V_28 -> V_33 = V_152 ;
F_17 ( & V_28 -> V_32 ) ;
V_28 -> V_57 . V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_16 ;
}
static inline unsigned long F_146 ( T_1 V_161 , T_2 V_162 ,
T_1 V_6 )
{
ASSERT ( V_6 >= V_161 ) ;
V_6 -= V_161 ;
return ( unsigned long ) ( F_147 ( V_6 , V_162 ) ) ;
}
static inline unsigned long F_148 ( T_1 V_85 , T_2 V_162 )
{
return ( unsigned long ) ( F_147 ( V_85 , V_162 ) ) ;
}
static inline T_1 F_149 ( struct V_93 * V_94 ,
T_1 V_6 )
{
T_1 V_161 ;
T_2 V_163 ;
V_163 = V_164 * V_94 -> V_162 ;
V_161 = V_6 - V_94 -> V_135 ;
V_161 = F_147 ( V_161 , V_163 ) ;
V_161 *= V_163 ;
V_161 += V_94 -> V_135 ;
return V_161 ;
}
static int F_150 ( struct V_165 * V_3 , T_1 V_6 ,
struct V_96 * V_130 , int V_86 )
{
struct V_96 * * V_166 = & V_3 -> V_96 ;
struct V_96 * V_167 = NULL ;
struct V_91 * V_168 ;
while ( * V_166 ) {
V_167 = * V_166 ;
V_168 = F_100 ( V_167 , struct V_91 , V_101 ) ;
if ( V_6 < V_168 -> V_6 ) {
V_166 = & ( * V_166 ) -> V_169 ;
} else if ( V_6 > V_168 -> V_6 ) {
V_166 = & ( * V_166 ) -> V_170 ;
} else {
if ( V_86 ) {
if ( V_168 -> V_86 ) {
F_151 ( 1 ) ;
return - V_171 ;
}
V_166 = & ( * V_166 ) -> V_170 ;
} else {
if ( ! V_168 -> V_86 ) {
F_151 ( 1 ) ;
return - V_171 ;
}
V_166 = & ( * V_166 ) -> V_169 ;
}
}
}
F_152 ( V_130 , V_167 , V_166 ) ;
F_153 ( V_130 , V_3 ) ;
return 0 ;
}
static struct V_91 *
F_154 ( struct V_93 * V_94 ,
T_1 V_6 , int V_172 , int V_173 )
{
struct V_96 * V_97 = V_94 -> V_100 . V_96 ;
struct V_91 * V_88 , * V_95 = NULL ;
while ( 1 ) {
if ( ! V_97 ) {
V_88 = NULL ;
break;
}
V_88 = F_100 ( V_97 , struct V_91 , V_101 ) ;
V_95 = V_88 ;
if ( V_6 < V_88 -> V_6 )
V_97 = V_97 -> V_169 ;
else if ( V_6 > V_88 -> V_6 )
V_97 = V_97 -> V_170 ;
else
break;
}
if ( V_172 ) {
if ( ! V_88 )
return NULL ;
if ( V_88 -> V_86 )
return V_88 ;
V_97 = F_99 ( V_97 ) ;
if ( ! V_97 )
return NULL ;
V_88 = F_100 ( V_97 , struct V_91 , V_101 ) ;
if ( V_88 -> V_6 != V_6 )
return NULL ;
F_139 ( ! V_88 -> V_86 ) ;
return V_88 ;
} else if ( V_88 ) {
if ( V_88 -> V_86 ) {
V_97 = F_155 ( & V_88 -> V_101 ) ;
if ( V_97 ) {
V_95 = F_100 ( V_97 , struct V_91 ,
V_101 ) ;
if ( ! V_95 -> V_86 &&
V_95 -> V_6 + V_95 -> V_85 > V_6 )
V_88 = V_95 ;
}
}
return V_88 ;
}
if ( ! V_95 )
return NULL ;
V_88 = V_95 ;
if ( V_88 -> V_6 > V_6 ) {
V_97 = F_155 ( & V_88 -> V_101 ) ;
if ( V_97 ) {
V_88 = F_100 ( V_97 , struct V_91 ,
V_101 ) ;
ASSERT ( V_88 -> V_6 <= V_6 ) ;
} else {
if ( V_173 )
return V_88 ;
else
return NULL ;
}
}
if ( V_88 -> V_86 ) {
V_97 = F_155 ( & V_88 -> V_101 ) ;
if ( V_97 ) {
V_95 = F_100 ( V_97 , struct V_91 ,
V_101 ) ;
if ( ! V_95 -> V_86 &&
V_95 -> V_6 + V_95 -> V_85 > V_6 )
return V_95 ;
}
if ( V_88 -> V_6 + V_164 * V_94 -> V_162 > V_6 )
return V_88 ;
} else if ( V_88 -> V_6 + V_88 -> V_85 > V_6 )
return V_88 ;
if ( ! V_173 )
return NULL ;
while ( 1 ) {
if ( V_88 -> V_86 ) {
if ( V_88 -> V_6 + V_164 *
V_94 -> V_162 > V_6 )
break;
} else {
if ( V_88 -> V_6 + V_88 -> V_85 > V_6 )
break;
}
V_97 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_97 )
return NULL ;
V_88 = F_100 ( V_97 , struct V_91 , V_101 ) ;
}
return V_88 ;
}
static inline void
F_156 ( struct V_93 * V_94 ,
struct V_91 * V_168 )
{
F_157 ( & V_168 -> V_101 , & V_94 -> V_100 ) ;
V_94 -> V_174 -- ;
}
static void F_101 ( struct V_93 * V_94 ,
struct V_91 * V_168 )
{
F_156 ( V_94 , V_168 ) ;
V_94 -> V_122 -= V_168 -> V_85 ;
}
static int F_103 ( struct V_93 * V_94 ,
struct V_91 * V_168 )
{
int V_16 = 0 ;
ASSERT ( V_168 -> V_85 || V_168 -> V_86 ) ;
V_16 = F_150 ( & V_94 -> V_100 , V_168 -> V_6 ,
& V_168 -> V_101 , ( V_168 -> V_86 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_94 -> V_122 += V_168 -> V_85 ;
V_94 -> V_174 ++ ;
return V_16 ;
}
static void F_158 ( struct V_93 * V_94 )
{
struct V_27 * V_28 = V_94 -> V_175 ;
T_1 V_176 ;
T_1 V_177 ;
T_1 V_178 ;
T_1 V_75 = V_28 -> V_8 . V_6 ;
T_2 V_179 = V_164 * V_94 -> V_162 ;
T_2 V_180 = F_147 ( V_75 + V_179 - 1 , V_179 ) ;
V_180 = F_159 ( T_2 , V_180 , 1 ) ;
ASSERT ( V_94 -> V_109 <= V_180 ) ;
if ( V_75 < 1024 * 1024 * 1024 )
V_176 = V_181 ;
else
V_176 = V_181 *
F_147 ( V_75 , 1024 * 1024 * 1024 ) ;
V_177 = ( V_94 -> V_109 + 1 ) * V_68 ;
if ( V_177 >= V_176 ) {
V_94 -> V_182 = 0 ;
return;
}
V_178 = V_176 - V_177 ;
V_178 = F_160 ( T_1 , V_178 , V_176 >> 1 ) ;
V_94 -> V_182 =
F_147 ( V_178 , sizeof( struct V_91 ) ) ;
}
static inline void F_161 ( struct V_93 * V_94 ,
struct V_91 * V_168 ,
T_1 V_6 , T_1 V_85 )
{
unsigned long V_135 , V_183 ;
V_135 = F_146 ( V_168 -> V_6 , V_94 -> V_162 , V_6 ) ;
V_183 = F_148 ( V_85 , V_94 -> V_162 ) ;
ASSERT ( V_135 + V_183 <= V_164 ) ;
F_162 ( V_168 -> V_86 , V_135 , V_183 ) ;
V_168 -> V_85 -= V_85 ;
}
static void F_163 ( struct V_93 * V_94 ,
struct V_91 * V_168 , T_1 V_6 ,
T_1 V_85 )
{
F_161 ( V_94 , V_168 , V_6 , V_85 ) ;
V_94 -> V_122 -= V_85 ;
}
static void F_164 ( struct V_93 * V_94 ,
struct V_91 * V_168 , T_1 V_6 ,
T_1 V_85 )
{
unsigned long V_135 , V_183 ;
V_135 = F_146 ( V_168 -> V_6 , V_94 -> V_162 , V_6 ) ;
V_183 = F_148 ( V_85 , V_94 -> V_162 ) ;
ASSERT ( V_135 + V_183 <= V_164 ) ;
F_165 ( V_168 -> V_86 , V_135 , V_183 ) ;
V_168 -> V_85 += V_85 ;
V_94 -> V_122 += V_85 ;
}
static int F_166 ( struct V_93 * V_94 ,
struct V_91 * V_184 , T_1 * V_6 ,
T_1 * V_85 , bool V_185 )
{
unsigned long V_186 = 0 ;
unsigned long V_187 = 0 ;
unsigned long V_188 , V_76 ;
unsigned long V_189 ;
unsigned long V_190 ;
if ( V_185 &&
V_184 -> V_191 &&
V_184 -> V_191 < * V_85 ) {
* V_85 = V_184 -> V_191 ;
return - 1 ;
}
V_76 = F_146 ( V_184 -> V_6 , V_94 -> V_162 ,
F_159 ( T_1 , * V_6 , V_184 -> V_6 ) ) ;
V_188 = F_148 ( * V_85 , V_94 -> V_162 ) ;
F_167 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
if ( V_185 && V_188 == 1 ) {
V_186 = 1 ;
break;
}
V_189 = F_168 ( V_184 -> V_86 ,
V_164 , V_76 ) ;
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
* V_6 = ( T_1 ) ( V_76 * V_94 -> V_162 ) + V_184 -> V_6 ;
* V_85 = ( T_1 ) ( V_186 ) * V_94 -> V_162 ;
return 0 ;
}
* V_85 = ( T_1 ) ( V_187 ) * V_94 -> V_162 ;
V_184 -> V_191 = * V_85 ;
return - 1 ;
}
static struct V_91 *
F_169 ( struct V_93 * V_94 , T_1 * V_6 , T_1 * V_85 ,
unsigned long V_192 , T_1 * V_191 )
{
struct V_91 * V_88 ;
struct V_96 * V_130 ;
T_1 V_83 ;
T_1 V_193 ;
int V_16 ;
if ( ! V_94 -> V_100 . V_96 )
goto V_107;
V_88 = F_154 ( V_94 , F_149 ( V_94 , * V_6 ) , 0 , 1 ) ;
if ( ! V_88 )
goto V_107;
for ( V_130 = & V_88 -> V_101 ; V_130 ; V_130 = F_99 ( V_130 ) ) {
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
if ( V_88 -> V_85 < * V_85 ) {
if ( V_88 -> V_85 > * V_191 )
* V_191 = V_88 -> V_85 ;
continue;
}
if ( * V_85 >= V_192 ) {
V_83 = V_88 -> V_6 - V_94 -> V_135 + V_192 - 1 ;
V_83 = F_170 ( V_83 , V_192 ) ;
V_83 = V_83 * V_192 + V_94 -> V_135 ;
V_193 = V_83 - V_88 -> V_6 ;
} else {
V_193 = 0 ;
V_83 = V_88 -> V_6 ;
}
if ( V_88 -> V_85 < * V_85 + V_193 ) {
if ( V_88 -> V_85 > * V_191 )
* V_191 = V_88 -> V_85 ;
continue;
}
if ( V_88 -> V_86 ) {
T_1 V_75 = * V_85 ;
V_16 = F_166 ( V_94 , V_88 , & V_83 , & V_75 , true ) ;
if ( ! V_16 ) {
* V_6 = V_83 ;
* V_85 = V_75 ;
return V_88 ;
} else if ( V_75 > * V_191 ) {
* V_191 = V_75 ;
}
continue;
}
* V_6 = V_83 ;
* V_85 = V_88 -> V_85 - V_193 ;
return V_88 ;
}
V_107:
return NULL ;
}
static void F_171 ( struct V_93 * V_94 ,
struct V_91 * V_168 , T_1 V_6 )
{
V_168 -> V_6 = F_149 ( V_94 , V_6 ) ;
V_168 -> V_85 = 0 ;
F_172 ( & V_168 -> V_112 ) ;
F_103 ( V_94 , V_168 ) ;
V_94 -> V_109 ++ ;
V_94 -> V_110 -> V_111 ( V_94 ) ;
}
static void F_173 ( struct V_93 * V_94 ,
struct V_91 * V_184 )
{
F_101 ( V_94 , V_184 ) ;
F_61 ( V_184 -> V_86 ) ;
F_102 ( V_103 , V_184 ) ;
V_94 -> V_109 -- ;
V_94 -> V_110 -> V_111 ( V_94 ) ;
}
static T_7 int F_174 ( struct V_93 * V_94 ,
struct V_91 * V_184 ,
T_1 * V_6 , T_1 * V_85 )
{
T_1 V_194 ;
T_1 V_195 , V_196 ;
int V_16 ;
V_98:
V_194 = V_184 -> V_6 + ( T_1 ) ( V_164 * V_94 -> V_162 ) - 1 ;
V_195 = * V_6 ;
V_196 = V_94 -> V_162 ;
V_196 = F_128 ( V_196 , V_194 - V_195 + 1 ) ;
V_16 = F_166 ( V_94 , V_184 , & V_195 , & V_196 ,
false ) ;
if ( V_16 < 0 || V_195 != * V_6 )
return - V_197 ;
V_196 = F_128 ( V_196 , * V_85 ) ;
V_196 = F_128 ( V_196 , V_194 - V_195 + 1 ) ;
F_163 ( V_94 , V_184 , V_195 , V_196 ) ;
* V_6 += V_196 ;
* V_85 -= V_196 ;
if ( * V_85 ) {
struct V_96 * V_102 = F_99 ( & V_184 -> V_101 ) ;
if ( ! V_184 -> V_85 )
F_173 ( V_94 , V_184 ) ;
if ( ! V_102 )
return - V_197 ;
V_184 = F_100 ( V_102 , struct V_91 ,
V_101 ) ;
if ( ! V_184 -> V_86 )
return - V_198 ;
V_195 = * V_6 ;
V_196 = V_94 -> V_162 ;
V_16 = F_166 ( V_94 , V_184 , & V_195 ,
& V_196 , false ) ;
if ( V_16 < 0 || V_195 != * V_6 )
return - V_198 ;
goto V_98;
} else if ( ! V_184 -> V_85 )
F_173 ( V_94 , V_184 ) ;
return 0 ;
}
static T_1 F_175 ( struct V_93 * V_94 ,
struct V_91 * V_168 , T_1 V_6 ,
T_1 V_85 )
{
T_1 V_199 = 0 ;
T_1 V_194 ;
V_194 = V_168 -> V_6 + ( T_1 ) ( V_164 * V_94 -> V_162 ) ;
V_199 = F_128 ( V_194 - V_6 , V_85 ) ;
F_164 ( V_94 , V_168 , V_6 , V_199 ) ;
V_168 -> V_191 = 0 ;
return V_199 ;
}
static bool F_176 ( struct V_93 * V_94 ,
struct V_91 * V_168 )
{
struct V_27 * V_28 = V_94 -> V_175 ;
bool V_200 = false ;
#ifdef F_177
if ( F_178 ( V_28 -> V_22 -> V_201 ,
V_28 ) )
V_200 = true ;
#endif
if ( ! V_200 && V_94 -> V_174 < V_94 -> V_182 ) {
if ( V_168 -> V_85 <= V_28 -> V_202 * 4 ) {
if ( V_94 -> V_174 * 2 <= V_94 -> V_182 )
return false ;
} else {
return false ;
}
}
if ( ( ( V_164 * V_94 -> V_162 ) >> 1 ) > V_28 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_179 ( struct V_93 * V_94 ,
struct V_91 * V_168 )
{
struct V_91 * V_184 ;
struct V_27 * V_28 = NULL ;
int V_203 = 0 ;
T_1 V_85 , V_6 , V_204 ;
int V_16 ;
V_85 = V_168 -> V_85 ;
V_6 = V_168 -> V_6 ;
if ( ! V_94 -> V_110 -> F_176 ( V_94 , V_168 ) )
return 0 ;
if ( V_94 -> V_110 == & V_205 )
V_28 = V_94 -> V_175 ;
V_98:
if ( V_28 && ! F_45 ( & V_28 -> V_133 ) ) {
struct V_127 * V_128 ;
struct V_96 * V_130 ;
struct V_91 * V_88 ;
V_128 = F_117 ( V_28 -> V_133 . V_102 ,
struct V_127 ,
V_134 ) ;
F_15 ( & V_128 -> V_32 ) ;
V_130 = F_98 ( & V_128 -> V_3 ) ;
if ( ! V_130 ) {
F_17 ( & V_128 -> V_32 ) ;
goto V_206;
}
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
if ( ! V_88 -> V_86 ) {
F_17 ( & V_128 -> V_32 ) ;
goto V_206;
}
if ( V_88 -> V_6 == F_149 ( V_94 , V_6 ) ) {
V_204 = F_175 ( V_94 , V_88 ,
V_6 , V_85 ) ;
V_85 -= V_204 ;
V_6 += V_204 ;
}
F_17 ( & V_128 -> V_32 ) ;
if ( ! V_85 ) {
V_16 = 1 ;
goto V_107;
}
}
V_206:
V_184 = F_154 ( V_94 , F_149 ( V_94 , V_6 ) ,
1 , 0 ) ;
if ( ! V_184 ) {
ASSERT ( V_203 == 0 ) ;
goto V_207;
}
V_204 = F_175 ( V_94 , V_184 , V_6 , V_85 ) ;
V_85 -= V_204 ;
V_6 += V_204 ;
V_203 = 0 ;
if ( ! V_85 ) {
V_16 = 1 ;
goto V_107;
} else
goto V_98;
V_207:
if ( V_168 && V_168 -> V_86 ) {
F_171 ( V_94 , V_168 , V_6 ) ;
V_203 = 1 ;
V_168 = NULL ;
goto V_98;
} else {
F_17 ( & V_94 -> V_99 ) ;
if ( ! V_168 ) {
V_168 = F_109 ( V_103 ,
V_62 ) ;
if ( ! V_168 ) {
F_15 ( & V_94 -> V_99 ) ;
V_16 = - V_52 ;
goto V_107;
}
}
V_168 -> V_86 = F_57 ( V_68 , V_62 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( ! V_168 -> V_86 ) {
V_16 = - V_52 ;
goto V_107;
}
goto V_98;
}
V_107:
if ( V_168 ) {
if ( V_168 -> V_86 )
F_61 ( V_168 -> V_86 ) ;
F_102 ( V_103 , V_168 ) ;
}
return V_16 ;
}
static bool F_180 ( struct V_93 * V_94 ,
struct V_91 * V_168 , bool V_208 )
{
struct V_91 * V_209 ;
struct V_91 * V_210 ;
bool V_211 = false ;
T_1 V_6 = V_168 -> V_6 ;
T_1 V_85 = V_168 -> V_85 ;
V_210 = F_154 ( V_94 , V_6 + V_85 , 0 , 0 ) ;
if ( V_210 && F_155 ( & V_210 -> V_101 ) )
V_209 = F_100 ( F_155 ( & V_210 -> V_101 ) ,
struct V_91 , V_101 ) ;
else
V_209 = F_154 ( V_94 , V_6 - 1 , 0 , 0 ) ;
if ( V_210 && ! V_210 -> V_86 ) {
if ( V_208 )
F_101 ( V_94 , V_210 ) ;
else
F_156 ( V_94 , V_210 ) ;
V_168 -> V_85 += V_210 -> V_85 ;
F_102 ( V_103 , V_210 ) ;
V_211 = true ;
}
if ( V_209 && ! V_209 -> V_86 &&
V_209 -> V_6 + V_209 -> V_85 == V_6 ) {
if ( V_208 )
F_101 ( V_94 , V_209 ) ;
else
F_156 ( V_94 , V_209 ) ;
V_168 -> V_6 = V_209 -> V_6 ;
V_168 -> V_85 += V_209 -> V_85 ;
F_102 ( V_103 , V_209 ) ;
V_211 = true ;
}
return V_211 ;
}
static bool F_181 ( struct V_93 * V_94 ,
struct V_91 * V_168 ,
bool V_208 )
{
struct V_91 * V_86 ;
unsigned long V_76 ;
unsigned long V_212 ;
const T_1 V_194 = V_168 -> V_6 + V_168 -> V_85 ;
const T_1 V_213 = F_149 ( V_94 , V_194 ) ;
T_1 V_85 ;
V_86 = F_154 ( V_94 , V_213 , 1 , 0 ) ;
if ( ! V_86 )
return false ;
V_76 = F_146 ( V_86 -> V_6 , V_94 -> V_162 , V_194 ) ;
V_212 = F_168 ( V_86 -> V_86 , V_164 , V_76 ) ;
if ( V_212 == V_76 )
return false ;
V_85 = ( V_212 - V_76 ) * V_94 -> V_162 ;
V_168 -> V_85 += V_85 ;
if ( V_208 )
F_163 ( V_94 , V_86 , V_194 , V_85 ) ;
else
F_161 ( V_94 , V_86 , V_194 , V_85 ) ;
if ( ! V_86 -> V_85 )
F_173 ( V_94 , V_86 ) ;
return true ;
}
static bool F_182 ( struct V_93 * V_94 ,
struct V_91 * V_168 ,
bool V_208 )
{
struct V_91 * V_86 ;
T_1 V_213 ;
unsigned long V_76 ;
unsigned long V_212 ;
unsigned long V_214 ;
T_1 V_85 ;
V_213 = F_149 ( V_94 , V_168 -> V_6 ) ;
if ( V_213 == V_168 -> V_6 ) {
if ( V_168 -> V_6 == 0 )
return false ;
V_213 = F_149 ( V_94 , V_168 -> V_6 - 1 ) ;
}
V_86 = F_154 ( V_94 , V_213 , 1 , 0 ) ;
if ( ! V_86 )
return false ;
V_76 = F_146 ( V_86 -> V_6 , V_94 -> V_162 , V_168 -> V_6 ) - 1 ;
V_212 = 0 ;
V_214 = ( unsigned long ) - 1 ;
F_183 (j, bitmap->bitmap, BITS_PER_BITMAP) {
if ( V_212 > V_76 )
break;
V_214 = V_212 ;
}
if ( V_214 == V_76 )
return false ;
if ( V_214 == ( unsigned long ) - 1 )
V_85 = ( V_76 + 1 ) * V_94 -> V_162 ;
else
V_85 = ( V_76 - V_214 ) * V_94 -> V_162 ;
V_168 -> V_6 -= V_85 ;
V_168 -> V_85 += V_85 ;
if ( V_208 )
F_163 ( V_94 , V_86 , V_168 -> V_6 , V_85 ) ;
else
F_161 ( V_94 , V_86 , V_168 -> V_6 , V_85 ) ;
if ( ! V_86 -> V_85 )
F_173 ( V_94 , V_86 ) ;
return true ;
}
static void F_184 ( struct V_93 * V_94 ,
struct V_91 * V_168 ,
bool V_208 )
{
ASSERT ( ! V_168 -> V_86 ) ;
ASSERT ( F_185 ( & V_168 -> V_101 ) ) ;
if ( V_94 -> V_109 > 0 ) {
bool V_215 ;
bool V_216 = false ;
V_215 = F_181 ( V_94 , V_168 , V_208 ) ;
if ( V_94 -> V_109 > 0 )
V_216 = F_182 ( V_94 , V_168 ,
V_208 ) ;
if ( V_215 || V_216 )
F_180 ( V_94 , V_168 , V_208 ) ;
}
}
int F_186 ( struct V_93 * V_94 ,
T_1 V_6 , T_1 V_85 )
{
struct V_91 * V_168 ;
int V_16 = 0 ;
V_168 = F_109 ( V_103 , V_62 ) ;
if ( ! V_168 )
return - V_52 ;
V_168 -> V_6 = V_6 ;
V_168 -> V_85 = V_85 ;
F_187 ( & V_168 -> V_101 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( F_180 ( V_94 , V_168 , true ) )
goto V_217;
V_16 = F_179 ( V_94 , V_168 ) ;
if ( V_16 < 0 ) {
goto V_107;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_107;
}
V_217:
F_184 ( V_94 , V_168 , true ) ;
V_16 = F_103 ( V_94 , V_168 ) ;
if ( V_16 )
F_102 ( V_103 , V_168 ) ;
V_107:
F_17 ( & V_94 -> V_99 ) ;
if ( V_16 ) {
F_188 ( V_218 L_12 , V_16 ) ;
ASSERT ( V_16 != - V_171 ) ;
}
return V_16 ;
}
int F_189 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_85 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_168 ;
int V_16 ;
bool V_219 = false ;
F_15 ( & V_94 -> V_99 ) ;
V_98:
V_16 = 0 ;
if ( ! V_85 )
goto V_220;
V_168 = F_154 ( V_94 , V_6 , 0 , 0 ) ;
if ( ! V_168 ) {
V_168 = F_154 ( V_94 , F_149 ( V_94 , V_6 ) ,
1 , 0 ) ;
if ( ! V_168 ) {
F_139 ( V_219 ) ;
goto V_220;
}
}
V_219 = false ;
if ( ! V_168 -> V_86 ) {
F_101 ( V_94 , V_168 ) ;
if ( V_6 == V_168 -> V_6 ) {
T_1 V_221 = F_128 ( V_85 , V_168 -> V_85 ) ;
V_168 -> V_85 -= V_221 ;
V_168 -> V_6 += V_221 ;
if ( V_168 -> V_85 ) {
V_16 = F_103 ( V_94 , V_168 ) ;
F_139 ( V_16 ) ;
} else {
F_102 ( V_103 , V_168 ) ;
}
V_6 += V_221 ;
V_85 -= V_221 ;
goto V_98;
} else {
T_1 V_222 = V_168 -> V_85 + V_168 -> V_6 ;
V_168 -> V_85 = V_6 - V_168 -> V_6 ;
V_16 = F_103 ( V_94 , V_168 ) ;
F_139 ( V_16 ) ;
if ( V_16 )
goto V_220;
if ( V_222 < V_6 + V_85 ) {
V_85 -= V_222 - V_6 ;
V_6 = V_222 ;
goto V_98;
} else if ( V_222 == V_6 + V_85 ) {
goto V_220;
}
F_17 ( & V_94 -> V_99 ) ;
V_16 = F_190 ( V_28 , V_6 + V_85 ,
V_222 - ( V_6 + V_85 ) ) ;
F_139 ( V_16 ) ;
goto V_107;
}
}
V_16 = F_174 ( V_94 , V_168 , & V_6 , & V_85 ) ;
if ( V_16 == - V_198 ) {
V_219 = true ;
goto V_98;
}
V_220:
F_17 ( & V_94 -> V_99 ) ;
V_107:
return V_16 ;
}
void F_191 ( struct V_27 * V_28 ,
T_1 V_85 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_168 ;
struct V_96 * V_97 ;
int V_183 = 0 ;
for ( V_97 = F_98 ( & V_94 -> V_100 ) ; V_97 ; V_97 = F_99 ( V_97 ) ) {
V_168 = F_100 ( V_97 , struct V_91 , V_101 ) ;
if ( V_168 -> V_85 >= V_85 && ! V_28 -> V_223 )
V_183 ++ ;
F_192 ( V_28 -> V_22 ,
L_13 ,
V_168 -> V_6 , V_168 -> V_85 ,
( V_168 -> V_86 ) ? L_14 : L_15 ) ;
}
F_19 ( V_28 -> V_22 , L_16 ,
F_45 ( & V_28 -> V_133 ) ? L_15 : L_14 ) ;
F_19 ( V_28 -> V_22 ,
L_17 , V_183 ) ;
}
void F_193 ( struct V_27 * V_28 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
F_194 ( & V_94 -> V_99 ) ;
V_94 -> V_162 = V_28 -> V_202 ;
V_94 -> V_135 = V_28 -> V_8 . V_17 ;
V_94 -> V_175 = V_28 ;
V_94 -> V_110 = & V_205 ;
F_172 ( & V_94 -> V_224 ) ;
F_195 ( & V_94 -> V_157 ) ;
V_94 -> V_182 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_91 ) ;
}
static int
F_196 (
struct V_27 * V_28 ,
struct V_127 * V_128 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 ;
struct V_96 * V_130 ;
F_15 ( & V_128 -> V_32 ) ;
if ( V_128 -> V_28 != V_28 )
goto V_107;
V_128 -> V_28 = NULL ;
V_128 -> V_225 = 0 ;
F_46 ( & V_128 -> V_134 ) ;
V_130 = F_98 ( & V_128 -> V_3 ) ;
while ( V_130 ) {
bool V_86 ;
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
V_130 = F_99 ( & V_88 -> V_101 ) ;
F_157 ( & V_88 -> V_101 , & V_128 -> V_3 ) ;
F_187 ( & V_88 -> V_101 ) ;
V_86 = ( V_88 -> V_86 != NULL ) ;
if ( ! V_86 ) {
F_180 ( V_94 , V_88 , false ) ;
F_184 ( V_94 , V_88 , false ) ;
}
F_150 ( & V_94 -> V_100 ,
V_88 -> V_6 , & V_88 -> V_101 , V_86 ) ;
}
V_128 -> V_3 = V_226 ;
V_107:
F_17 ( & V_128 -> V_32 ) ;
F_48 ( V_28 ) ;
return 0 ;
}
static void F_197 (
struct V_93 * V_94 )
{
struct V_91 * V_168 ;
struct V_96 * V_130 ;
while ( ( V_130 = F_198 ( & V_94 -> V_100 ) ) != NULL ) {
V_168 = F_100 ( V_130 , struct V_91 , V_101 ) ;
if ( ! V_168 -> V_86 ) {
F_101 ( V_94 , V_168 ) ;
F_102 ( V_103 , V_168 ) ;
} else {
F_173 ( V_94 , V_168 ) ;
}
F_199 ( & V_94 -> V_99 ) ;
}
}
void F_112 ( struct V_93 * V_94 )
{
F_15 ( & V_94 -> V_99 ) ;
F_197 ( V_94 ) ;
F_17 ( & V_94 -> V_99 ) ;
}
void F_200 ( struct V_27 * V_28 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_127 * V_128 ;
struct V_125 * V_227 ;
F_15 ( & V_94 -> V_99 ) ;
while ( ( V_227 = V_28 -> V_133 . V_102 ) !=
& V_28 -> V_133 ) {
V_128 = F_117 ( V_227 , struct V_127 ,
V_134 ) ;
F_139 ( V_128 -> V_28 != V_28 ) ;
F_196 ( V_28 , V_128 ) ;
F_199 ( & V_94 -> V_99 ) ;
}
F_197 ( V_94 ) ;
F_17 ( & V_94 -> V_99 ) ;
}
T_1 F_201 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_85 , T_1 V_228 ,
T_1 * V_191 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 = NULL ;
T_1 V_229 = V_85 + V_228 ;
T_1 V_16 = 0 ;
T_1 V_230 = 0 ;
T_1 V_231 = 0 ;
F_15 ( & V_94 -> V_99 ) ;
V_88 = F_169 ( V_94 , & V_6 , & V_229 ,
V_28 -> V_232 , V_191 ) ;
if ( ! V_88 )
goto V_107;
V_16 = V_6 ;
if ( V_88 -> V_86 ) {
F_163 ( V_94 , V_88 , V_6 , V_85 ) ;
if ( ! V_88 -> V_85 )
F_173 ( V_94 , V_88 ) ;
} else {
F_101 ( V_94 , V_88 ) ;
V_231 = V_6 - V_88 -> V_6 ;
V_230 = V_88 -> V_6 ;
V_88 -> V_6 = V_6 + V_85 ;
F_139 ( V_88 -> V_85 < V_85 + V_231 ) ;
V_88 -> V_85 -= V_85 + V_231 ;
if ( ! V_88 -> V_85 )
F_102 ( V_103 , V_88 ) ;
else
F_103 ( V_94 , V_88 ) ;
}
V_107:
F_17 ( & V_94 -> V_99 ) ;
if ( V_231 )
F_186 ( V_94 , V_230 , V_231 ) ;
return V_16 ;
}
int F_202 (
struct V_27 * V_28 ,
struct V_127 * V_128 )
{
struct V_93 * V_94 ;
int V_16 ;
F_15 ( & V_128 -> V_32 ) ;
if ( ! V_28 ) {
V_28 = V_128 -> V_28 ;
if ( ! V_28 ) {
F_17 ( & V_128 -> V_32 ) ;
return 0 ;
}
} else if ( V_128 -> V_28 != V_28 ) {
F_17 ( & V_128 -> V_32 ) ;
return 0 ;
}
F_203 ( & V_28 -> V_183 ) ;
F_17 ( & V_128 -> V_32 ) ;
V_94 = V_28 -> V_114 ;
F_15 ( & V_94 -> V_99 ) ;
V_16 = F_196 ( V_28 , V_128 ) ;
F_17 ( & V_94 -> V_99 ) ;
F_48 ( V_28 ) ;
return V_16 ;
}
static T_1 F_204 ( struct V_27 * V_28 ,
struct V_127 * V_128 ,
struct V_91 * V_88 ,
T_1 V_85 , T_1 V_233 ,
T_1 * V_191 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
int V_234 ;
T_1 V_195 = V_128 -> V_225 ;
T_1 V_196 = V_85 ;
T_1 V_16 = 0 ;
V_195 = V_233 ;
V_196 = V_85 ;
V_234 = F_166 ( V_94 , V_88 , & V_195 , & V_196 , true ) ;
if ( V_234 ) {
if ( V_196 > * V_191 )
* V_191 = V_196 ;
return 0 ;
}
V_16 = V_195 ;
F_161 ( V_94 , V_88 , V_16 , V_85 ) ;
return V_16 ;
}
T_1 F_205 ( struct V_27 * V_28 ,
struct V_127 * V_128 , T_1 V_85 ,
T_1 V_233 , T_1 * V_191 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 = NULL ;
struct V_96 * V_130 ;
T_1 V_16 = 0 ;
F_15 ( & V_128 -> V_32 ) ;
if ( V_85 > V_128 -> V_235 )
goto V_107;
if ( V_128 -> V_28 != V_28 )
goto V_107;
V_130 = F_98 ( & V_128 -> V_3 ) ;
if ( ! V_130 )
goto V_107;
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
while ( 1 ) {
if ( V_88 -> V_85 < V_85 && V_88 -> V_85 > * V_191 )
* V_191 = V_88 -> V_85 ;
if ( V_88 -> V_85 < V_85 ||
( ! V_88 -> V_86 && V_88 -> V_6 < V_233 ) ) {
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 )
break;
V_88 = F_100 ( V_130 , struct V_91 ,
V_101 ) ;
continue;
}
if ( V_88 -> V_86 ) {
V_16 = F_204 ( V_28 ,
V_128 , V_88 , V_85 ,
V_128 -> V_225 ,
V_191 ) ;
if ( V_16 == 0 ) {
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 )
break;
V_88 = F_100 ( V_130 , struct V_91 ,
V_101 ) ;
continue;
}
V_128 -> V_225 += V_85 ;
} else {
V_16 = V_88 -> V_6 ;
V_88 -> V_6 += V_85 ;
V_88 -> V_85 -= V_85 ;
}
if ( V_88 -> V_85 == 0 )
F_157 ( & V_88 -> V_101 , & V_128 -> V_3 ) ;
break;
}
V_107:
F_17 ( & V_128 -> V_32 ) ;
if ( ! V_16 )
return 0 ;
F_15 ( & V_94 -> V_99 ) ;
V_94 -> V_122 -= V_85 ;
if ( V_88 -> V_85 == 0 ) {
V_94 -> V_174 -- ;
if ( V_88 -> V_86 ) {
F_61 ( V_88 -> V_86 ) ;
V_94 -> V_109 -- ;
V_94 -> V_110 -> V_111 ( V_94 ) ;
}
F_102 ( V_103 , V_88 ) ;
}
F_17 ( & V_94 -> V_99 ) ;
return V_16 ;
}
static int F_206 ( struct V_27 * V_28 ,
struct V_91 * V_88 ,
struct V_127 * V_128 ,
T_1 V_6 , T_1 V_85 ,
T_1 V_236 , T_1 V_237 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
unsigned long V_189 ;
unsigned long V_76 ;
unsigned long V_238 ;
unsigned long V_239 ;
unsigned long V_186 ;
unsigned long V_187 = 0 ;
unsigned long V_135 = 0 ;
unsigned long V_240 = 0 ;
int V_16 ;
V_76 = F_146 ( V_88 -> V_6 , V_94 -> V_162 ,
F_159 ( T_1 , V_6 , V_88 -> V_6 ) ) ;
V_238 = F_148 ( V_85 , V_94 -> V_162 ) ;
V_239 = F_148 ( V_237 , V_94 -> V_162 ) ;
if ( V_88 -> V_191 &&
V_88 -> V_191 < V_236 )
return - V_50 ;
V_98:
V_186 = 0 ;
F_167 (i, entry->bitmap, BITS_PER_BITMAP) {
V_189 = F_168 ( V_88 -> V_86 ,
V_164 , V_76 ) ;
if ( V_189 - V_76 >= V_239 ) {
V_186 = V_189 - V_76 ;
if ( V_186 > V_187 )
V_187 = V_186 ;
break;
}
if ( V_189 - V_76 > V_187 )
V_187 = V_189 - V_76 ;
V_76 = V_189 ;
}
if ( ! V_186 ) {
V_88 -> V_191 = ( T_1 ) V_187 * V_94 -> V_162 ;
return - V_50 ;
}
if ( ! V_240 ) {
V_135 = V_76 ;
V_128 -> V_235 = 0 ;
}
V_240 += V_186 ;
if ( V_128 -> V_235 < V_186 * V_94 -> V_162 )
V_128 -> V_235 = V_186 * V_94 -> V_162 ;
if ( V_240 < V_238 || V_128 -> V_235 < V_236 ) {
V_76 = V_189 + 1 ;
goto V_98;
}
V_128 -> V_225 = V_135 * V_94 -> V_162 + V_88 -> V_6 ;
F_157 ( & V_88 -> V_101 , & V_94 -> V_100 ) ;
V_16 = F_150 ( & V_128 -> V_3 , V_88 -> V_6 ,
& V_88 -> V_101 , 1 ) ;
ASSERT ( ! V_16 ) ;
F_207 ( V_28 , V_128 ,
V_240 * V_94 -> V_162 , 1 ) ;
return 0 ;
}
static T_7 int
F_208 ( struct V_27 * V_28 ,
struct V_127 * V_128 ,
struct V_125 * V_104 , T_1 V_6 , T_1 V_85 ,
T_1 V_236 , T_1 V_237 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_241 = NULL ;
struct V_91 * V_88 = NULL ;
struct V_91 * V_242 ;
struct V_96 * V_130 ;
T_1 V_243 ;
T_1 V_244 ;
T_1 V_245 = 0 ;
V_88 = F_154 ( V_94 , V_6 , 0 , 1 ) ;
if ( ! V_88 )
return - V_50 ;
while ( V_88 -> V_86 || V_88 -> V_85 < V_237 ) {
if ( V_88 -> V_86 && F_45 ( & V_88 -> V_112 ) )
F_110 ( & V_88 -> V_112 , V_104 ) ;
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 )
return - V_50 ;
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
}
V_243 = V_88 -> V_85 ;
V_244 = V_88 -> V_85 ;
V_241 = V_88 ;
V_242 = V_88 ;
for ( V_130 = F_99 ( & V_88 -> V_101 ) ; V_130 ;
V_130 = F_99 ( & V_88 -> V_101 ) ) {
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
if ( V_88 -> V_86 ) {
if ( F_45 ( & V_88 -> V_112 ) )
F_110 ( & V_88 -> V_112 , V_104 ) ;
continue;
}
if ( V_88 -> V_85 < V_237 )
continue;
V_242 = V_88 ;
V_243 += V_88 -> V_85 ;
if ( V_88 -> V_85 > V_244 )
V_244 = V_88 -> V_85 ;
}
if ( V_243 < V_85 || V_244 < V_236 )
return - V_50 ;
V_128 -> V_225 = V_241 -> V_6 ;
V_130 = & V_241 -> V_101 ;
do {
int V_16 ;
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( V_88 -> V_86 || V_88 -> V_85 < V_237 )
continue;
F_157 ( & V_88 -> V_101 , & V_94 -> V_100 ) ;
V_16 = F_150 ( & V_128 -> V_3 , V_88 -> V_6 ,
& V_88 -> V_101 , 0 ) ;
V_245 += V_88 -> V_85 ;
ASSERT ( ! V_16 ) ;
} while ( V_130 && V_88 != V_242 );
V_128 -> V_235 = V_244 ;
F_207 ( V_28 , V_128 , V_245 , 0 ) ;
return 0 ;
}
static T_7 int
F_209 ( struct V_27 * V_28 ,
struct V_127 * V_128 ,
struct V_125 * V_104 , T_1 V_6 , T_1 V_85 ,
T_1 V_236 , T_1 V_237 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 = NULL ;
int V_16 = - V_50 ;
T_1 V_213 = F_149 ( V_94 , V_6 ) ;
if ( V_94 -> V_109 == 0 )
return - V_50 ;
if ( ! F_45 ( V_104 ) )
V_88 = F_210 ( V_104 , struct V_91 , V_112 ) ;
if ( ! V_88 || V_88 -> V_6 != V_213 ) {
V_88 = F_154 ( V_94 , V_213 , 1 , 0 ) ;
if ( V_88 && F_45 ( & V_88 -> V_112 ) )
F_211 ( & V_88 -> V_112 , V_104 ) ;
}
F_118 (entry, bitmaps, list) {
if ( V_88 -> V_85 < V_85 )
continue;
V_16 = F_206 ( V_28 , V_88 , V_128 , V_6 ,
V_85 , V_236 , V_237 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_50 ;
}
int F_212 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_127 * V_128 ,
T_1 V_6 , T_1 V_85 , T_1 V_228 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 , * V_83 ;
F_105 ( V_104 ) ;
T_1 V_237 ;
T_1 V_236 ;
int V_16 ;
if ( F_213 ( V_3 , V_246 ) ) {
V_236 = V_237 = V_85 + V_228 ;
} else if ( V_28 -> V_29 & V_247 ) {
V_236 = V_85 ;
V_237 = V_28 -> V_202 ;
} else {
V_236 = F_127 ( V_85 , ( V_85 + V_228 ) >> 2 ) ;
V_237 = V_28 -> V_202 ;
}
F_15 ( & V_94 -> V_99 ) ;
if ( V_94 -> V_122 < V_85 ) {
F_17 ( & V_94 -> V_99 ) ;
return - V_50 ;
}
F_15 ( & V_128 -> V_32 ) ;
if ( V_128 -> V_28 ) {
V_16 = 0 ;
goto V_107;
}
F_214 ( V_28 , V_6 , V_85 , V_228 ,
V_237 ) ;
V_16 = F_208 ( V_28 , V_128 , & V_104 , V_6 ,
V_85 + V_228 ,
V_236 , V_237 ) ;
if ( V_16 )
V_16 = F_209 ( V_28 , V_128 , & V_104 ,
V_6 , V_85 + V_228 ,
V_236 , V_237 ) ;
F_111 (entry, tmp, &bitmaps, list)
F_46 ( & V_88 -> V_112 ) ;
if ( ! V_16 ) {
F_203 ( & V_28 -> V_183 ) ;
F_110 ( & V_128 -> V_134 ,
& V_28 -> V_133 ) ;
V_128 -> V_28 = V_28 ;
} else {
F_215 ( V_28 ) ;
}
V_107:
F_17 ( & V_128 -> V_32 ) ;
F_17 ( & V_94 -> V_99 ) ;
return V_16 ;
}
void F_216 ( struct V_127 * V_128 )
{
F_194 ( & V_128 -> V_32 ) ;
F_194 ( & V_128 -> V_248 ) ;
V_128 -> V_3 = V_226 ;
V_128 -> V_235 = 0 ;
V_128 -> V_249 = false ;
F_172 ( & V_128 -> V_134 ) ;
V_128 -> V_28 = NULL ;
}
static int F_217 ( struct V_27 * V_28 ,
T_1 * V_250 , T_1 V_135 , T_1 V_85 ,
T_1 V_251 , T_1 V_252 ,
struct V_131 * V_132 )
{
struct V_253 * V_254 = V_28 -> V_254 ;
struct V_113 * V_22 = V_28 -> V_22 ;
struct V_93 * V_94 = V_28 -> V_114 ;
int V_16 ;
int V_255 = 0 ;
T_1 V_256 = 0 ;
F_15 ( & V_254 -> V_32 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( ! V_28 -> V_223 ) {
V_28 -> V_49 += V_252 ;
V_254 -> V_257 += V_252 ;
V_255 = 1 ;
}
F_17 ( & V_28 -> V_32 ) ;
F_17 ( & V_254 -> V_32 ) ;
V_16 = F_218 ( V_22 -> V_201 ,
V_135 , V_85 , & V_256 ) ;
if ( ! V_16 )
* V_250 += V_256 ;
F_44 ( & V_94 -> V_157 ) ;
F_190 ( V_28 , V_251 , V_252 ) ;
F_219 ( & V_132 -> V_112 ) ;
F_54 ( & V_94 -> V_157 ) ;
if ( V_255 ) {
F_15 ( & V_254 -> V_32 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_223 )
V_254 -> V_258 += V_252 ;
V_28 -> V_49 -= V_252 ;
V_254 -> V_257 -= V_252 ;
F_17 ( & V_254 -> V_32 ) ;
F_17 ( & V_28 -> V_32 ) ;
}
return V_16 ;
}
static int F_220 ( struct V_27 * V_28 ,
T_1 * V_250 , T_1 V_135 , T_1 V_194 , T_1 V_259 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 ;
struct V_96 * V_130 ;
int V_16 = 0 ;
T_1 V_141 ;
T_1 V_178 ;
T_1 V_85 ;
while ( V_135 < V_194 ) {
struct V_131 V_132 ;
F_44 ( & V_94 -> V_157 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( V_94 -> V_122 < V_259 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
break;
}
V_88 = F_154 ( V_94 , V_135 , 0 , 1 ) ;
if ( ! V_88 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
break;
}
while ( V_88 -> V_86 ) {
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
goto V_107;
}
V_88 = F_100 ( V_130 , struct V_91 ,
V_101 ) ;
}
if ( V_88 -> V_6 >= V_194 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
break;
}
V_141 = V_88 -> V_6 ;
V_178 = V_88 -> V_85 ;
V_135 = F_127 ( V_135 , V_141 ) ;
V_85 = F_128 ( V_141 + V_178 , V_194 ) - V_135 ;
if ( V_85 < V_259 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
goto V_102;
}
F_101 ( V_94 , V_88 ) ;
F_102 ( V_103 , V_88 ) ;
F_17 ( & V_94 -> V_99 ) ;
V_132 . V_135 = V_141 ;
V_132 . V_85 = V_178 ;
F_110 ( & V_132 . V_112 , & V_94 -> V_224 ) ;
F_54 ( & V_94 -> V_157 ) ;
V_16 = F_217 ( V_28 , V_250 , V_135 , V_85 ,
V_141 , V_178 , & V_132 ) ;
if ( V_16 )
break;
V_102:
V_135 += V_85 ;
if ( F_221 ( V_260 ) ) {
V_16 = - V_261 ;
break;
}
F_222 () ;
}
V_107:
return V_16 ;
}
static int F_223 ( struct V_27 * V_28 ,
T_1 * V_250 , T_1 V_135 , T_1 V_194 , T_1 V_259 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 ;
int V_16 = 0 ;
int V_262 ;
T_1 V_85 ;
T_1 V_6 = F_149 ( V_94 , V_135 ) ;
while ( V_6 < V_194 ) {
bool V_263 = false ;
struct V_131 V_132 ;
F_44 ( & V_94 -> V_157 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( V_94 -> V_122 < V_259 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
break;
}
V_88 = F_154 ( V_94 , V_6 , 1 , 0 ) ;
if ( ! V_88 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
V_263 = true ;
goto V_102;
}
V_85 = V_259 ;
V_262 = F_166 ( V_94 , V_88 , & V_135 , & V_85 , false ) ;
if ( V_262 || V_135 >= V_194 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
V_263 = true ;
goto V_102;
}
V_85 = F_128 ( V_85 , V_194 - V_135 ) ;
if ( V_85 < V_259 ) {
F_17 ( & V_94 -> V_99 ) ;
F_54 ( & V_94 -> V_157 ) ;
goto V_102;
}
F_163 ( V_94 , V_88 , V_135 , V_85 ) ;
if ( V_88 -> V_85 == 0 )
F_173 ( V_94 , V_88 ) ;
F_17 ( & V_94 -> V_99 ) ;
V_132 . V_135 = V_135 ;
V_132 . V_85 = V_85 ;
F_110 ( & V_132 . V_112 , & V_94 -> V_224 ) ;
F_54 ( & V_94 -> V_157 ) ;
V_16 = F_217 ( V_28 , V_250 , V_135 , V_85 ,
V_135 , V_85 , & V_132 ) ;
if ( V_16 )
break;
V_102:
if ( V_263 ) {
V_6 += V_164 * V_94 -> V_162 ;
} else {
V_135 += V_85 ;
if ( V_135 >= V_6 + V_164 * V_94 -> V_162 )
V_6 += V_164 * V_94 -> V_162 ;
}
if ( F_221 ( V_260 ) ) {
V_16 = - V_261 ;
break;
}
F_222 () ;
}
return V_16 ;
}
void F_224 ( struct V_27 * V_264 )
{
F_203 ( & V_264 -> V_265 ) ;
}
void F_225 ( struct V_27 * V_28 )
{
struct V_266 * V_267 ;
struct V_268 * V_269 ;
bool V_270 ;
F_15 ( & V_28 -> V_32 ) ;
V_270 = ( F_226 ( & V_28 -> V_265 ) &&
V_28 -> V_271 ) ;
F_17 ( & V_28 -> V_32 ) ;
if ( V_270 ) {
F_227 ( V_28 -> V_22 -> V_272 ) ;
V_267 = & V_28 -> V_22 -> V_273 . V_274 ;
F_228 ( & V_267 -> V_32 ) ;
V_269 = F_229 ( V_267 , V_28 -> V_8 . V_17 ,
1 ) ;
F_230 ( ! V_269 ) ;
F_231 ( V_267 , V_269 ) ;
F_232 ( & V_267 -> V_32 ) ;
F_233 ( V_28 -> V_22 -> V_272 ) ;
F_234 ( V_269 ) ;
F_234 ( V_269 ) ;
F_112 ( V_28 -> V_114 ) ;
}
}
int F_235 ( struct V_27 * V_28 ,
T_1 * V_256 , T_1 V_135 , T_1 V_194 , T_1 V_259 )
{
int V_16 ;
* V_256 = 0 ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_271 ) {
F_17 ( & V_28 -> V_32 ) ;
return 0 ;
}
F_224 ( V_28 ) ;
F_17 ( & V_28 -> V_32 ) ;
V_16 = F_220 ( V_28 , V_256 , V_135 , V_194 , V_259 ) ;
if ( V_16 )
goto V_107;
V_16 = F_223 ( V_28 , V_256 , V_135 , V_194 , V_259 ) ;
V_107:
F_225 ( V_28 ) ;
return V_16 ;
}
T_1 F_236 ( struct V_2 * V_275 )
{
struct V_93 * V_94 = V_275 -> V_276 ;
struct V_91 * V_88 = NULL ;
T_1 V_38 = 0 ;
F_15 ( & V_94 -> V_99 ) ;
if ( F_237 ( & V_94 -> V_100 ) )
goto V_107;
V_88 = F_100 ( F_98 ( & V_94 -> V_100 ) ,
struct V_91 , V_101 ) ;
if ( ! V_88 -> V_86 ) {
V_38 = V_88 -> V_6 ;
F_101 ( V_94 , V_88 ) ;
V_88 -> V_6 ++ ;
V_88 -> V_85 -- ;
if ( ! V_88 -> V_85 )
F_102 ( V_103 , V_88 ) ;
else
F_103 ( V_94 , V_88 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_183 = 1 ;
int V_16 ;
V_16 = F_166 ( V_94 , V_88 , & V_6 , & V_183 , true ) ;
ASSERT ( ! V_16 ) ;
V_38 = V_6 ;
F_163 ( V_94 , V_88 , V_6 , 1 ) ;
if ( V_88 -> V_85 == 0 )
F_173 ( V_94 , V_88 ) ;
}
V_107:
F_17 ( & V_94 -> V_99 ) ;
return V_38 ;
}
struct V_1 * F_238 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_277 ) ;
if ( V_3 -> V_278 )
V_1 = F_16 ( V_3 -> V_278 ) ;
F_17 ( & V_3 -> V_277 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_277 ) ;
if ( ! F_239 ( V_3 -> V_22 ) )
V_3 -> V_278 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_277 ) ;
return V_1 ;
}
int F_240 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_37 , V_5 ,
V_43 , 0 ) ;
}
int F_241 ( struct V_113 * V_22 , struct V_2 * V_3 )
{
struct V_93 * V_94 = V_3 -> V_276 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_279 = F_242 ( & V_3 -> V_280 ) ;
if ( ! F_213 ( V_3 , V_281 ) )
return 0 ;
if ( F_239 ( V_22 ) )
return 0 ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_238 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_107;
if ( V_279 != F_18 ( V_1 ) -> V_80 )
goto V_282;
V_16 = F_104 ( V_3 , V_1 , V_94 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_80 ( V_22 ,
L_18 ,
V_3 -> V_283 . V_17 ) ;
V_282:
F_11 ( V_1 ) ;
V_107:
F_49 ( V_5 ) ;
return V_16 ;
}
int F_243 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_93 * V_94 = V_3 -> V_276 ;
int V_16 ;
struct V_64 V_57 ;
bool V_284 = true ;
if ( ! F_213 ( V_3 , V_281 ) )
return 0 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_16 = F_138 ( V_3 , V_1 , V_94 , NULL , & V_57 ,
V_37 , V_5 , 0 ) ;
if ( ! V_16 ) {
V_284 = false ;
V_16 = F_47 ( V_3 , V_37 , NULL , & V_57 , V_5 , 0 ) ;
}
if ( V_16 ) {
if ( V_284 )
F_244 ( V_1 , V_1 -> V_137 ) ;
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_19 ,
V_3 -> V_283 . V_17 ) ;
#endif
}
return V_16 ;
}
int F_245 ( struct V_27 * V_264 ,
T_1 V_6 , T_1 V_85 , bool V_86 )
{
struct V_93 * V_94 = V_264 -> V_114 ;
struct V_91 * V_168 = NULL , * V_184 ;
void * V_285 = NULL ;
T_1 V_204 ;
int V_16 ;
V_98:
if ( ! V_168 ) {
V_168 = F_109 ( V_103 , V_62 ) ;
if ( ! V_168 )
return - V_52 ;
}
if ( ! V_86 ) {
F_15 ( & V_94 -> V_99 ) ;
V_168 -> V_6 = V_6 ;
V_168 -> V_85 = V_85 ;
V_168 -> V_191 = 0 ;
V_16 = F_103 ( V_94 , V_168 ) ;
F_17 ( & V_94 -> V_99 ) ;
if ( V_16 )
F_102 ( V_103 , V_168 ) ;
return V_16 ;
}
if ( ! V_285 ) {
V_285 = F_57 ( V_68 , V_62 ) ;
if ( ! V_285 ) {
F_102 ( V_103 , V_168 ) ;
return - V_52 ;
}
}
F_15 ( & V_94 -> V_99 ) ;
V_184 = F_154 ( V_94 , F_149 ( V_94 , V_6 ) ,
1 , 0 ) ;
if ( ! V_184 ) {
V_168 -> V_86 = V_285 ;
V_285 = NULL ;
F_171 ( V_94 , V_168 , V_6 ) ;
V_184 = V_168 ;
V_168 = NULL ;
}
V_204 = F_175 ( V_94 , V_184 , V_6 , V_85 ) ;
V_85 -= V_204 ;
V_6 += V_204 ;
F_17 ( & V_94 -> V_99 ) ;
if ( V_85 )
goto V_98;
if ( V_168 )
F_102 ( V_103 , V_168 ) ;
if ( V_285 )
F_61 ( V_285 ) ;
return 0 ;
}
int F_246 ( struct V_27 * V_264 ,
T_1 V_6 , T_1 V_85 )
{
struct V_93 * V_94 = V_264 -> V_114 ;
struct V_91 * V_168 ;
int V_16 = 0 ;
F_15 ( & V_94 -> V_99 ) ;
V_168 = F_154 ( V_94 , V_6 , 0 , 0 ) ;
if ( ! V_168 ) {
V_168 = F_154 ( V_94 , F_149 ( V_94 , V_6 ) ,
1 , 0 ) ;
if ( ! V_168 )
goto V_107;
}
V_286:
if ( V_168 -> V_86 ) {
T_1 V_287 , V_288 ;
struct V_96 * V_97 ;
struct V_91 * V_83 ;
V_287 = V_6 ;
V_288 = V_94 -> V_162 ;
V_16 = F_166 ( V_94 , V_168 , & V_287 , & V_288 , false ) ;
if ( ! V_16 ) {
if ( V_287 == V_6 ) {
V_16 = 1 ;
goto V_107;
} else if ( V_287 > V_6 &&
V_6 + V_85 > V_287 ) {
V_16 = 1 ;
goto V_107;
}
}
V_97 = F_155 ( & V_168 -> V_101 ) ;
while ( V_97 ) {
V_83 = F_100 ( V_97 , struct V_91 ,
V_101 ) ;
if ( V_83 -> V_6 + V_83 -> V_85 < V_6 )
break;
if ( V_6 + V_85 < V_83 -> V_6 ) {
V_97 = F_155 ( & V_168 -> V_101 ) ;
continue;
}
V_168 = V_83 ;
goto V_286;
}
V_97 = F_99 ( & V_168 -> V_101 ) ;
while ( V_97 ) {
V_83 = F_100 ( V_97 , struct V_91 ,
V_101 ) ;
if ( V_6 + V_85 < V_83 -> V_6 )
break;
if ( V_83 -> V_6 + V_83 -> V_85 < V_6 ) {
V_97 = F_99 ( & V_168 -> V_101 ) ;
continue;
}
V_168 = V_83 ;
goto V_286;
}
V_16 = 0 ;
goto V_107;
}
if ( V_168 -> V_6 == V_6 ) {
V_16 = 1 ;
goto V_107;
}
if ( V_6 > V_168 -> V_6 && V_6 < V_168 -> V_6 + V_168 -> V_85 )
V_16 = 1 ;
V_107:
F_17 ( & V_94 -> V_99 ) ;
return V_16 ;
}
