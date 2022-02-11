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
struct V_1 * F_14 ( struct V_7 * V_8 ,
struct V_28
* V_29 , struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
T_2 V_30 = V_31 | V_32 ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_1 )
V_1 = F_16 ( V_29 -> V_1 ) ;
F_17 ( & V_29 -> V_33 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_8 -> V_34 , V_5 ,
V_29 -> V_10 . V_19 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_29 -> V_33 ) ;
if ( ! ( ( F_18 ( V_1 ) -> V_30 & V_30 ) == V_30 ) ) {
F_19 ( V_8 , L_1 ) ;
F_18 ( V_1 ) -> V_30 |= V_31 |
V_32 ;
V_29 -> V_35 = V_36 ;
}
if ( ! V_29 -> V_37 ) {
V_29 -> V_1 = F_16 ( V_1 ) ;
V_29 -> V_37 = 1 ;
}
F_17 ( & V_29 -> V_33 ) ;
return V_1 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
struct V_4 * V_5 ,
T_1 V_40 , T_1 V_6 )
{
struct V_9 V_10 ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_41 * V_42 ;
struct V_16 * V_17 ;
T_1 V_30 = V_43 | V_44 ;
int V_18 ;
V_18 = F_21 ( V_39 , V_3 , V_5 , V_40 ) ;
if ( V_18 )
return V_18 ;
if ( V_40 != V_45 )
V_30 |= V_31 | V_32 ;
V_17 = V_5 -> V_22 [ 0 ] ;
V_42 = F_5 ( V_17 , V_5 -> V_23 [ 0 ] ,
struct V_41 ) ;
F_22 ( V_17 , & V_13 , V_5 -> V_23 [ 0 ] ) ;
F_23 ( V_17 , ( unsigned long ) V_42 ,
sizeof( * V_42 ) ) ;
F_24 ( V_17 , V_42 , V_39 -> V_46 ) ;
F_25 ( V_17 , V_42 , 0 ) ;
F_26 ( V_17 , V_42 , 0 ) ;
F_27 ( V_17 , V_42 , 0 ) ;
F_28 ( V_17 , V_42 , 0 ) ;
F_29 ( V_17 , V_42 , V_47 | 0600 ) ;
F_30 ( V_17 , V_42 , V_30 ) ;
F_31 ( V_17 , V_42 , 1 ) ;
F_32 ( V_17 , V_42 , V_39 -> V_46 ) ;
F_33 ( V_17 , V_42 , V_6 ) ;
F_34 ( V_17 ) ;
F_4 ( V_5 ) ;
V_10 . V_19 = V_20 ;
V_10 . V_6 = V_6 ;
V_10 . type = 0 ;
V_18 = F_35 ( V_39 , V_3 , V_5 , & V_10 ,
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
int F_37 ( struct V_7 * V_8 ,
struct V_38 * V_39 ,
struct V_28 * V_29 ,
struct V_4 * V_5 )
{
int V_18 ;
T_1 V_40 ;
V_18 = F_38 ( V_8 -> V_34 , & V_40 ) ;
if ( V_18 < 0 )
return V_18 ;
return F_20 ( V_8 -> V_34 , V_39 , V_5 , V_40 ,
V_29 -> V_10 . V_19 ) ;
}
int F_39 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
T_1 V_50 ;
int V_18 ;
V_50 = F_40 ( V_8 , 1 ) +
F_41 ( V_8 , 1 ) ;
F_15 ( & V_49 -> V_33 ) ;
if ( V_49 -> V_51 < V_50 )
V_18 = - V_52 ;
else
V_18 = 0 ;
F_17 ( & V_49 -> V_33 ) ;
return V_18 ;
}
int F_42 ( struct V_38 * V_39 ,
struct V_28 * V_29 ,
struct V_1 * V_1 )
{
struct V_2 * V_3 = F_18 ( V_1 ) -> V_3 ;
int V_18 = 0 ;
bool V_53 = false ;
if ( V_29 ) {
struct V_4 * V_5 = F_43 () ;
if ( ! V_5 ) {
V_18 = - V_54 ;
goto V_55;
}
V_53 = true ;
F_44 ( & V_39 -> V_56 -> V_57 ) ;
if ( ! F_45 ( & V_29 -> V_58 ) ) {
F_46 ( & V_29 -> V_58 ) ;
F_47 ( V_39 , V_29 , V_5 ) ;
F_48 ( V_29 ) ;
}
F_15 ( & V_29 -> V_33 ) ;
V_29 -> V_35 = V_36 ;
F_17 ( & V_29 -> V_33 ) ;
F_49 ( V_5 ) ;
}
F_50 ( F_18 ( V_1 ) , 0 ) ;
F_51 ( V_1 , 0 ) ;
V_18 = F_52 ( V_39 , V_3 , V_1 ,
0 , V_59 ) ;
if ( V_18 )
goto V_55;
V_18 = F_53 ( V_39 , V_3 , V_1 ) ;
V_55:
if ( V_53 )
F_54 ( & V_39 -> V_56 -> V_57 ) ;
if ( V_18 )
F_55 ( V_39 , V_18 ) ;
return V_18 ;
}
static void F_56 ( struct V_1 * V_1 )
{
struct V_60 * V_61 ;
unsigned long V_62 ;
V_61 = F_57 ( sizeof( * V_61 ) , V_63 ) ;
if ( ! V_61 )
return;
F_58 ( V_61 , V_1 -> V_25 ) ;
V_62 = ( F_59 ( V_1 ) - 1 ) >> V_64 ;
F_60 ( V_1 -> V_25 , V_61 , NULL , 0 , V_62 ) ;
F_61 ( V_61 ) ;
}
static int F_62 ( struct V_65 * V_66 , struct V_1 * V_1 ,
int V_67 )
{
int V_68 ;
int V_69 = 0 ;
V_68 = F_63 ( F_59 ( V_1 ) , V_70 ) ;
if ( F_64 ( F_18 ( V_1 ) ) != V_45 )
V_69 = 1 ;
if ( V_67 && V_69 &&
( V_68 * sizeof( T_2 ) ) >= V_70 )
return - V_52 ;
memset ( V_66 , 0 , sizeof( struct V_65 ) ) ;
V_66 -> V_71 = F_65 ( V_68 , sizeof( struct V_72 * ) , V_63 ) ;
if ( ! V_66 -> V_71 )
return - V_54 ;
V_66 -> V_68 = V_68 ;
V_66 -> V_8 = F_66 ( V_1 -> V_73 ) ;
V_66 -> V_69 = V_69 ;
V_66 -> V_1 = V_1 ;
return 0 ;
}
static void F_67 ( struct V_65 * V_66 )
{
F_61 ( V_66 -> V_71 ) ;
V_66 -> V_71 = NULL ;
}
static void F_68 ( struct V_65 * V_66 )
{
if ( V_66 -> V_74 ) {
V_66 -> V_74 = NULL ;
V_66 -> V_75 = NULL ;
}
}
static void F_69 ( struct V_65 * V_66 , int V_76 )
{
ASSERT ( V_66 -> V_77 < V_66 -> V_68 ) ;
V_66 -> V_72 = V_66 -> V_71 [ V_66 -> V_77 ++ ] ;
V_66 -> V_74 = F_70 ( V_66 -> V_72 ) ;
V_66 -> V_75 = V_66 -> V_74 ;
V_66 -> V_78 = V_70 ;
if ( V_76 )
memset ( V_66 -> V_74 , 0 , V_70 ) ;
}
static void F_71 ( struct V_65 * V_66 )
{
int V_79 ;
F_68 ( V_66 ) ;
for ( V_79 = 0 ; V_79 < V_66 -> V_68 ; V_79 ++ ) {
if ( V_66 -> V_71 [ V_79 ] ) {
F_72 ( V_66 -> V_71 [ V_79 ] ) ;
F_73 ( V_66 -> V_71 [ V_79 ] ) ;
F_74 ( V_66 -> V_71 [ V_79 ] ) ;
}
}
}
static int F_75 ( struct V_65 * V_66 , struct V_1 * V_1 ,
int V_80 )
{
struct V_72 * V_72 ;
T_3 V_81 = F_76 ( V_1 -> V_25 ) ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_66 -> V_68 ; V_79 ++ ) {
V_72 = F_77 ( V_1 -> V_25 , V_79 , V_81 ) ;
if ( ! V_72 ) {
F_71 ( V_66 ) ;
return - V_54 ;
}
V_66 -> V_71 [ V_79 ] = V_72 ;
if ( V_80 && ! F_78 ( V_72 ) ) {
F_79 ( NULL , V_72 ) ;
F_80 ( V_72 ) ;
if ( ! F_78 ( V_72 ) ) {
F_81 ( F_18 ( V_1 ) -> V_3 -> V_8 ,
L_2 ) ;
F_71 ( V_66 ) ;
return - V_82 ;
}
}
}
for ( V_79 = 0 ; V_79 < V_66 -> V_68 ; V_79 ++ ) {
F_82 ( V_66 -> V_71 [ V_79 ] ) ;
F_83 ( V_66 -> V_71 [ V_79 ] ) ;
}
return 0 ;
}
static void F_84 ( struct V_65 * V_66 , T_1 V_83 )
{
T_4 * V_84 ;
F_69 ( V_66 , 1 ) ;
if ( V_66 -> V_69 ) {
V_66 -> V_74 += ( sizeof( T_2 ) * V_66 -> V_68 ) ;
V_66 -> V_78 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_66 -> V_68 ) ;
} else {
V_66 -> V_74 += sizeof( T_1 ) ;
V_66 -> V_78 -= sizeof( T_1 ) * 2 ;
}
V_84 = V_66 -> V_74 ;
* V_84 = F_85 ( V_83 ) ;
V_66 -> V_74 += sizeof( T_1 ) ;
}
static int F_86 ( struct V_65 * V_66 , T_1 V_83 )
{
T_4 * V_85 ;
if ( V_66 -> V_69 ) {
V_66 -> V_74 += sizeof( T_2 ) * V_66 -> V_68 ;
V_66 -> V_78 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_66 -> V_68 ) ;
} else {
V_66 -> V_74 += sizeof( T_1 ) ;
V_66 -> V_78 -= sizeof( T_1 ) * 2 ;
}
V_85 = V_66 -> V_74 ;
if ( F_87 ( * V_85 ) != V_83 ) {
F_88 ( V_66 -> V_8 ,
L_3 ,
* V_85 , V_83 ) ;
F_68 ( V_66 ) ;
return - V_82 ;
}
V_66 -> V_74 += sizeof( T_1 ) ;
return 0 ;
}
static void F_89 ( struct V_65 * V_66 , int V_77 )
{
T_2 * V_86 ;
T_2 V_87 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_66 -> V_69 ) {
F_68 ( V_66 ) ;
return;
}
if ( V_77 == 0 )
V_6 = sizeof( T_2 ) * V_66 -> V_68 ;
V_87 = F_90 ( V_66 -> V_75 + V_6 , V_87 ,
V_70 - V_6 ) ;
F_91 ( V_87 , ( V_88 * ) & V_87 ) ;
F_68 ( V_66 ) ;
V_86 = F_70 ( V_66 -> V_71 [ 0 ] ) ;
V_86 += V_77 ;
* V_86 = V_87 ;
}
static int F_92 ( struct V_65 * V_66 , int V_77 )
{
T_2 * V_86 , V_84 ;
T_2 V_87 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_66 -> V_69 ) {
F_69 ( V_66 , 0 ) ;
return 0 ;
}
if ( V_77 == 0 )
V_6 = sizeof( T_2 ) * V_66 -> V_68 ;
V_86 = F_70 ( V_66 -> V_71 [ 0 ] ) ;
V_86 += V_77 ;
V_84 = * V_86 ;
F_69 ( V_66 , 0 ) ;
V_87 = F_90 ( V_66 -> V_75 + V_6 , V_87 ,
V_70 - V_6 ) ;
F_91 ( V_87 , ( V_88 * ) & V_87 ) ;
if ( V_84 != V_87 ) {
F_88 ( V_66 -> V_8 ,
L_4 ) ;
F_68 ( V_66 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_93 ( struct V_65 * V_66 , T_1 V_6 , T_1 V_89 ,
void * V_90 )
{
struct V_91 * V_92 ;
if ( ! V_66 -> V_74 )
return - V_52 ;
V_92 = V_66 -> V_74 ;
V_92 -> V_6 = F_85 ( V_6 ) ;
V_92 -> V_89 = F_85 ( V_89 ) ;
V_92 -> type = ( V_90 ) ? V_93 :
V_94 ;
V_66 -> V_74 += sizeof( struct V_91 ) ;
V_66 -> V_78 -= sizeof( struct V_91 ) ;
if ( V_66 -> V_78 >= sizeof( struct V_91 ) )
return 0 ;
F_89 ( V_66 , V_66 -> V_77 - 1 ) ;
if ( V_66 -> V_77 >= V_66 -> V_68 )
return 0 ;
F_69 ( V_66 , 1 ) ;
return 0 ;
}
static int F_94 ( struct V_65 * V_66 , void * V_90 )
{
if ( ! V_66 -> V_74 )
return - V_52 ;
if ( V_66 -> V_74 != V_66 -> V_75 ) {
F_89 ( V_66 , V_66 -> V_77 - 1 ) ;
if ( V_66 -> V_77 >= V_66 -> V_68 )
return - V_52 ;
F_69 ( V_66 , 0 ) ;
}
memcpy ( V_66 -> V_74 , V_90 , V_70 ) ;
F_89 ( V_66 , V_66 -> V_77 - 1 ) ;
if ( V_66 -> V_77 < V_66 -> V_68 )
F_69 ( V_66 , 0 ) ;
return 0 ;
}
static void F_95 ( struct V_65 * V_66 )
{
if ( V_66 -> V_74 != V_66 -> V_75 )
F_89 ( V_66 , V_66 -> V_77 - 1 ) ;
else
F_68 ( V_66 ) ;
while ( V_66 -> V_77 < V_66 -> V_68 ) {
F_69 ( V_66 , 1 ) ;
F_89 ( V_66 , V_66 -> V_77 - 1 ) ;
}
}
static int F_96 ( struct V_65 * V_66 ,
struct V_95 * V_92 , V_88 * type )
{
struct V_91 * V_96 ;
int V_18 ;
if ( ! V_66 -> V_74 ) {
V_18 = F_92 ( V_66 , V_66 -> V_77 ) ;
if ( V_18 )
return V_18 ;
}
V_96 = V_66 -> V_74 ;
V_92 -> V_6 = F_87 ( V_96 -> V_6 ) ;
V_92 -> V_89 = F_87 ( V_96 -> V_89 ) ;
* type = V_96 -> type ;
V_66 -> V_74 += sizeof( struct V_91 ) ;
V_66 -> V_78 -= sizeof( struct V_91 ) ;
if ( V_66 -> V_78 >= sizeof( struct V_91 ) )
return 0 ;
F_68 ( V_66 ) ;
return 0 ;
}
static int F_97 ( struct V_65 * V_66 ,
struct V_95 * V_92 )
{
int V_18 ;
V_18 = F_92 ( V_66 , V_66 -> V_77 ) ;
if ( V_18 )
return V_18 ;
memcpy ( V_92 -> V_90 , V_66 -> V_74 , V_70 ) ;
F_68 ( V_66 ) ;
return 0 ;
}
static void F_98 ( struct V_97 * V_98 )
{
struct V_95 * V_96 , * V_99 = NULL ;
struct V_100 * V_101 ;
V_102:
F_15 ( & V_98 -> V_103 ) ;
for ( V_101 = F_99 ( & V_98 -> V_104 ) ; V_101 ; V_101 = F_100 ( V_101 ) ) {
V_96 = F_101 ( V_101 , struct V_95 , V_105 ) ;
if ( ! V_99 )
goto V_106;
if ( V_96 -> V_90 || V_99 -> V_90 )
goto V_106;
if ( V_99 -> V_6 + V_99 -> V_89 == V_96 -> V_6 ) {
F_102 ( V_98 , V_99 ) ;
F_102 ( V_98 , V_96 ) ;
V_99 -> V_89 += V_96 -> V_89 ;
F_103 ( V_107 , V_96 ) ;
F_104 ( V_98 , V_99 ) ;
V_99 = NULL ;
F_17 ( & V_98 -> V_103 ) ;
goto V_102;
}
V_106:
V_99 = V_96 ;
}
F_17 ( & V_98 -> V_103 ) ;
}
static int F_105 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_97 * V_98 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_66 ( V_1 -> V_73 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_65 V_66 ;
struct V_9 V_10 ;
struct V_95 * V_96 , * V_101 ;
F_106 ( V_108 ) ;
T_1 V_109 ;
T_1 V_110 ;
T_1 V_83 ;
V_88 type ;
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
V_109 = F_107 ( V_17 , V_15 ) ;
V_110 = F_108 ( V_17 , V_15 ) ;
V_83 = F_109 ( V_17 , V_15 ) ;
F_4 ( V_5 ) ;
if ( ! F_18 ( V_1 ) -> V_83 ) {
F_19 ( V_8 ,
L_5 ,
V_6 ) ;
return 0 ;
}
if ( F_18 ( V_1 ) -> V_83 != V_83 ) {
F_81 ( V_8 ,
L_6 ,
F_18 ( V_1 ) -> V_83 , V_83 ) ;
return 0 ;
}
if ( ! V_109 )
return 0 ;
V_18 = F_62 ( & V_66 , V_1 , 0 ) ;
if ( V_18 )
return V_18 ;
F_56 ( V_1 ) ;
V_18 = F_75 ( & V_66 , V_1 , 1 ) ;
if ( V_18 )
goto V_111;
V_18 = F_92 ( & V_66 , 0 ) ;
if ( V_18 )
goto V_112;
V_18 = F_86 ( & V_66 , V_83 ) ;
if ( V_18 )
goto V_112;
while ( V_109 ) {
V_96 = F_110 ( V_107 ,
V_63 ) ;
if ( ! V_96 )
goto V_112;
V_18 = F_96 ( & V_66 , V_96 , & type ) ;
if ( V_18 ) {
F_103 ( V_107 , V_96 ) ;
goto V_112;
}
if ( ! V_96 -> V_89 ) {
F_103 ( V_107 , V_96 ) ;
goto V_112;
}
if ( type == V_94 ) {
F_15 ( & V_98 -> V_103 ) ;
V_18 = F_104 ( V_98 , V_96 ) ;
F_17 ( & V_98 -> V_103 ) ;
if ( V_18 ) {
F_81 ( V_8 ,
L_7 ) ;
F_103 ( V_107 , V_96 ) ;
goto V_112;
}
} else {
ASSERT ( V_110 ) ;
V_110 -- ;
V_96 -> V_90 = F_57 ( V_70 , V_63 ) ;
if ( ! V_96 -> V_90 ) {
F_103 (
V_107 , V_96 ) ;
goto V_112;
}
F_15 ( & V_98 -> V_103 ) ;
V_18 = F_104 ( V_98 , V_96 ) ;
V_98 -> V_113 ++ ;
V_98 -> V_114 -> V_115 ( V_98 ) ;
F_17 ( & V_98 -> V_103 ) ;
if ( V_18 ) {
F_81 ( V_8 ,
L_7 ) ;
F_103 ( V_107 , V_96 ) ;
goto V_112;
}
F_111 ( & V_96 -> V_116 , & V_108 ) ;
}
V_109 -- ;
}
F_68 ( & V_66 ) ;
F_112 (e, n, &bitmaps, list) {
F_46 ( & V_96 -> V_116 ) ;
V_18 = F_97 ( & V_66 , V_96 ) ;
if ( V_18 )
goto V_112;
}
F_71 ( & V_66 ) ;
F_98 ( V_98 ) ;
V_18 = 1 ;
V_111:
F_67 ( & V_66 ) ;
return V_18 ;
V_112:
F_71 ( & V_66 ) ;
F_113 ( V_98 ) ;
goto V_111;
}
int F_114 ( struct V_7 * V_8 ,
struct V_28 * V_29 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_18 = 0 ;
bool V_118 ;
T_1 V_119 = F_115 ( & V_29 -> V_120 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_35 != V_121 ) {
F_17 ( & V_29 -> V_33 ) ;
return 0 ;
}
F_17 ( & V_29 -> V_33 ) ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_122 = 1 ;
V_5 -> V_123 = 1 ;
V_1 = F_14 ( V_8 , V_29 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_49 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_35 != V_121 ) {
F_17 ( & V_29 -> V_33 ) ;
F_49 ( V_5 ) ;
goto V_111;
}
F_17 ( & V_29 -> V_33 ) ;
V_18 = F_105 ( V_8 -> V_34 , V_1 , V_98 ,
V_5 , V_29 -> V_10 . V_19 ) ;
F_49 ( V_5 ) ;
if ( V_18 <= 0 )
goto V_111;
F_15 ( & V_98 -> V_103 ) ;
V_118 = ( V_98 -> V_124 == ( V_29 -> V_10 . V_6 - V_119 -
V_29 -> V_125 ) ) ;
F_17 ( & V_98 -> V_103 ) ;
if ( ! V_118 ) {
F_113 ( V_98 ) ;
F_116 ( V_8 ,
L_8 ,
V_29 -> V_10 . V_19 ) ;
V_18 = - 1 ;
}
V_111:
if ( V_18 < 0 ) {
F_15 ( & V_29 -> V_33 ) ;
V_29 -> V_35 = V_36 ;
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
int F_117 ( struct V_65 * V_66 ,
struct V_97 * V_98 ,
struct V_28 * V_29 ,
int * V_126 , int * V_108 ,
struct V_127 * V_128 )
{
int V_18 ;
struct V_129 * V_130 = NULL ;
struct V_129 * V_131 = NULL ;
struct V_100 * V_132 = F_99 ( & V_98 -> V_104 ) ;
struct V_133 * V_134 ;
if ( V_29 && ! F_45 ( & V_29 -> V_135 ) ) {
V_130 = F_118 ( V_29 -> V_135 . V_106 ,
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
struct V_95 * V_96 ;
V_96 = F_101 ( V_132 , struct V_95 , V_105 ) ;
* V_126 += 1 ;
V_18 = F_93 ( V_66 , V_96 -> V_6 , V_96 -> V_89 ,
V_96 -> V_90 ) ;
if ( V_18 )
goto V_55;
if ( V_96 -> V_90 ) {
F_111 ( & V_96 -> V_116 , V_128 ) ;
* V_108 += 1 ;
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
V_18 = F_93 ( V_66 , V_134 -> V_137 ,
V_134 -> V_89 , NULL ) ;
if ( V_18 )
goto V_55;
* V_126 += 1 ;
}
return 0 ;
V_55:
if ( V_131 )
F_17 ( & V_131 -> V_33 ) ;
return - V_52 ;
}
static T_5 int
F_120 ( struct V_38 * V_39 ,
struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 , T_1 V_6 ,
int V_126 , int V_108 )
{
struct V_9 V_10 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_10 . V_19 = V_20 ;
V_10 . V_6 = V_6 ;
V_10 . type = 0 ;
V_18 = F_2 ( V_39 , V_3 , & V_10 , V_5 , 0 , 1 ) ;
if ( V_18 < 0 ) {
F_121 ( & F_18 ( V_1 ) -> V_138 , 0 , V_1 -> V_139 - 1 ,
V_140 | V_141 , 0 , 0 , NULL ,
V_63 ) ;
goto V_55;
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
NULL , V_63 ) ;
F_4 ( V_5 ) ;
goto V_55;
}
}
F_18 ( V_1 ) -> V_83 = V_39 -> V_46 ;
V_15 = F_5 ( V_17 , V_5 -> V_23 [ 0 ] ,
struct V_14 ) ;
F_123 ( V_17 , V_15 , V_126 ) ;
F_124 ( V_17 , V_15 , V_108 ) ;
F_125 ( V_17 , V_15 , V_39 -> V_46 ) ;
F_34 ( V_17 ) ;
F_4 ( V_5 ) ;
return 0 ;
V_55:
return - 1 ;
}
static T_5 int
F_126 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
struct V_65 * V_66 ,
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
V_18 = F_93 ( V_66 , V_143 , V_145 , NULL ) ;
if ( V_18 )
return - V_52 ;
V_137 = V_144 ;
}
return 0 ;
}
static T_5 int
F_130 ( struct V_65 * V_66 , struct V_127 * V_128 )
{
struct V_95 * V_92 , * V_106 ;
int V_18 ;
F_112 (entry, next, bitmap_list, list) {
V_18 = F_94 ( V_66 , V_92 -> V_90 ) ;
if ( V_18 )
return - V_52 ;
F_46 ( & V_92 -> V_116 ) ;
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
V_63 ) ;
return V_18 ;
}
static void T_5
F_133 ( struct V_127 * V_128 )
{
struct V_95 * V_92 , * V_106 ;
F_112 (entry, next, bitmap_list, list)
F_46 ( & V_92 -> V_116 ) ;
}
static void T_5
F_134 ( struct V_1 * V_1 ,
struct V_65 * V_66 ,
struct V_149 * * V_150 )
{
F_71 ( V_66 ) ;
F_135 ( & F_18 ( V_1 ) -> V_138 , 0 ,
F_59 ( V_1 ) - 1 , V_150 ,
V_63 ) ;
}
static int F_136 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
struct V_28 * V_29 ,
struct V_65 * V_66 ,
struct V_4 * V_5 , T_1 V_6 )
{
int V_18 ;
struct V_1 * V_1 = V_66 -> V_1 ;
struct V_7 * V_8 ;
if ( ! V_1 )
return 0 ;
V_8 = F_66 ( V_1 -> V_73 ) ;
V_18 = F_131 ( V_1 ) ;
if ( V_18 )
goto V_111;
V_18 = F_120 ( V_39 , V_3 , V_1 , V_5 , V_6 ,
V_66 -> V_126 , V_66 -> V_108 ) ;
V_111:
F_67 ( V_66 ) ;
if ( V_18 ) {
F_137 ( V_1 -> V_25 ) ;
F_18 ( V_1 ) -> V_83 = 0 ;
if ( V_29 ) {
#ifdef F_138
F_81 ( V_8 ,
L_10 ,
V_29 -> V_10 . V_19 ) ;
#endif
}
}
F_53 ( V_39 , V_3 , V_1 ) ;
if ( V_29 ) {
F_15 ( & V_39 -> V_56 -> V_151 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( ! V_18 && F_45 ( & V_29 -> V_152 ) )
V_29 -> V_35 = V_121 ;
else if ( V_18 )
V_29 -> V_35 = V_153 ;
F_17 ( & V_29 -> V_33 ) ;
F_17 ( & V_39 -> V_56 -> V_151 ) ;
V_66 -> V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_18 ;
}
static int F_139 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
struct V_65 * V_66 ,
struct V_4 * V_5 )
{
return F_136 ( V_3 , V_39 , NULL , V_66 , V_5 , 0 ) ;
}
int F_47 ( struct V_38 * V_39 ,
struct V_28 * V_29 ,
struct V_4 * V_5 )
{
return F_136 ( V_29 -> V_8 -> V_34 , V_39 ,
V_29 , & V_29 -> V_66 ,
V_5 , V_29 -> V_10 . V_19 ) ;
}
static int F_140 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_97 * V_98 ,
struct V_28 * V_29 ,
struct V_65 * V_66 ,
struct V_38 * V_39 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_149 * V_150 = NULL ;
F_106 ( V_128 ) ;
int V_126 = 0 ;
int V_108 = 0 ;
int V_18 ;
int V_154 = 0 ;
if ( ! F_59 ( V_1 ) )
return - V_82 ;
F_141 ( V_66 -> V_71 ) ;
V_18 = F_62 ( V_66 , V_1 , 1 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 && ( V_29 -> V_30 & V_155 ) ) {
F_142 ( & V_29 -> V_156 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_157 ) {
V_29 -> V_35 = V_121 ;
F_17 ( & V_29 -> V_33 ) ;
F_143 ( & V_29 -> V_156 ) ;
F_18 ( V_1 ) -> V_83 = 0 ;
V_18 = 0 ;
V_154 = 1 ;
goto V_111;
}
F_17 ( & V_29 -> V_33 ) ;
}
V_18 = F_75 ( V_66 , V_1 , 0 ) ;
if ( V_18 )
goto V_111;
F_144 ( & F_18 ( V_1 ) -> V_138 , 0 , F_59 ( V_1 ) - 1 ,
& V_150 ) ;
F_84 ( V_66 , V_39 -> V_46 ) ;
F_44 ( & V_98 -> V_158 ) ;
F_15 ( & V_98 -> V_103 ) ;
V_18 = F_117 ( V_66 , V_98 ,
V_29 , & V_126 , & V_108 ,
& V_128 ) ;
if ( V_18 )
goto V_159;
V_18 = F_126 ( V_8 , V_29 ,
V_66 , & V_126 ) ;
if ( V_18 )
goto V_159;
V_18 = F_130 ( V_66 , & V_128 ) ;
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
if ( V_18 )
goto V_160;
F_95 ( V_66 ) ;
V_18 = F_145 ( V_1 , V_66 -> V_71 , V_66 -> V_68 , 0 ,
F_59 ( V_1 ) , & V_150 ) ;
if ( V_18 )
goto V_160;
if ( V_29 && ( V_29 -> V_30 & V_155 ) )
F_143 ( & V_29 -> V_156 ) ;
F_71 ( V_66 ) ;
F_135 ( & F_18 ( V_1 ) -> V_138 , 0 ,
F_59 ( V_1 ) - 1 , & V_150 , V_63 ) ;
V_66 -> V_126 = V_126 ;
V_66 -> V_108 = V_108 ;
V_18 = F_146 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_18 )
goto V_111;
return 0 ;
V_111:
V_66 -> V_1 = NULL ;
F_67 ( V_66 ) ;
if ( V_18 ) {
F_137 ( V_1 -> V_25 ) ;
F_18 ( V_1 ) -> V_83 = 0 ;
}
F_53 ( V_39 , V_3 , V_1 ) ;
if ( V_154 )
F_11 ( V_1 ) ;
return V_18 ;
V_159:
F_133 ( & V_128 ) ;
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
V_160:
F_134 ( V_1 , V_66 , & V_150 ) ;
if ( V_29 && ( V_29 -> V_30 & V_155 ) )
F_143 ( & V_29 -> V_156 ) ;
goto V_111;
}
int F_147 ( struct V_7 * V_8 ,
struct V_38 * V_39 ,
struct V_28 * V_29 ,
struct V_4 * V_5 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_1 * V_1 ;
int V_18 = 0 ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_35 < V_161 ) {
F_17 ( & V_29 -> V_33 ) ;
return 0 ;
}
F_17 ( & V_29 -> V_33 ) ;
V_1 = F_14 ( V_8 , V_29 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_18 = F_140 ( V_8 -> V_34 , V_1 , V_98 ,
V_29 , & V_29 -> V_66 , V_39 ) ;
if ( V_18 ) {
#ifdef F_138
F_81 ( V_8 ,
L_10 ,
V_29 -> V_10 . V_19 ) ;
#endif
F_15 ( & V_29 -> V_33 ) ;
V_29 -> V_35 = V_153 ;
F_17 ( & V_29 -> V_33 ) ;
V_29 -> V_66 . V_1 = NULL ;
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
static inline unsigned long F_150 ( T_1 V_89 , T_2 V_163 )
{
return ( unsigned long ) ( F_149 ( V_89 , V_163 ) ) ;
}
static inline T_1 F_151 ( struct V_97 * V_98 ,
T_1 V_6 )
{
T_1 V_162 ;
T_1 V_164 ;
V_164 = V_165 * V_98 -> V_163 ;
V_162 = V_6 - V_98 -> V_137 ;
V_162 = F_152 ( V_162 , V_164 ) ;
V_162 *= V_164 ;
V_162 += V_98 -> V_137 ;
return V_162 ;
}
static int F_153 ( struct V_166 * V_3 , T_1 V_6 ,
struct V_100 * V_132 , int V_90 )
{
struct V_100 * * V_167 = & V_3 -> V_100 ;
struct V_100 * V_168 = NULL ;
struct V_95 * V_169 ;
while ( * V_167 ) {
V_168 = * V_167 ;
V_169 = F_101 ( V_168 , struct V_95 , V_105 ) ;
if ( V_6 < V_169 -> V_6 ) {
V_167 = & ( * V_167 ) -> V_170 ;
} else if ( V_6 > V_169 -> V_6 ) {
V_167 = & ( * V_167 ) -> V_171 ;
} else {
if ( V_90 ) {
if ( V_169 -> V_90 ) {
F_154 ( 1 ) ;
return - V_172 ;
}
V_167 = & ( * V_167 ) -> V_171 ;
} else {
if ( ! V_169 -> V_90 ) {
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
static struct V_95 *
F_157 ( struct V_97 * V_98 ,
T_1 V_6 , int V_173 , int V_174 )
{
struct V_100 * V_101 = V_98 -> V_104 . V_100 ;
struct V_95 * V_92 , * V_99 = NULL ;
while ( 1 ) {
if ( ! V_101 ) {
V_92 = NULL ;
break;
}
V_92 = F_101 ( V_101 , struct V_95 , V_105 ) ;
V_99 = V_92 ;
if ( V_6 < V_92 -> V_6 )
V_101 = V_101 -> V_170 ;
else if ( V_6 > V_92 -> V_6 )
V_101 = V_101 -> V_171 ;
else
break;
}
if ( V_173 ) {
if ( ! V_92 )
return NULL ;
if ( V_92 -> V_90 )
return V_92 ;
V_101 = F_100 ( V_101 ) ;
if ( ! V_101 )
return NULL ;
V_92 = F_101 ( V_101 , struct V_95 , V_105 ) ;
if ( V_92 -> V_6 != V_6 )
return NULL ;
F_141 ( ! V_92 -> V_90 ) ;
return V_92 ;
} else if ( V_92 ) {
if ( V_92 -> V_90 ) {
V_101 = F_158 ( & V_92 -> V_105 ) ;
if ( V_101 ) {
V_99 = F_101 ( V_101 , struct V_95 ,
V_105 ) ;
if ( ! V_99 -> V_90 &&
V_99 -> V_6 + V_99 -> V_89 > V_6 )
V_92 = V_99 ;
}
}
return V_92 ;
}
if ( ! V_99 )
return NULL ;
V_92 = V_99 ;
if ( V_92 -> V_6 > V_6 ) {
V_101 = F_158 ( & V_92 -> V_105 ) ;
if ( V_101 ) {
V_92 = F_101 ( V_101 , struct V_95 ,
V_105 ) ;
ASSERT ( V_92 -> V_6 <= V_6 ) ;
} else {
if ( V_174 )
return V_92 ;
else
return NULL ;
}
}
if ( V_92 -> V_90 ) {
V_101 = F_158 ( & V_92 -> V_105 ) ;
if ( V_101 ) {
V_99 = F_101 ( V_101 , struct V_95 ,
V_105 ) ;
if ( ! V_99 -> V_90 &&
V_99 -> V_6 + V_99 -> V_89 > V_6 )
return V_99 ;
}
if ( V_92 -> V_6 + V_165 * V_98 -> V_163 > V_6 )
return V_92 ;
} else if ( V_92 -> V_6 + V_92 -> V_89 > V_6 )
return V_92 ;
if ( ! V_174 )
return NULL ;
while ( 1 ) {
if ( V_92 -> V_90 ) {
if ( V_92 -> V_6 + V_165 *
V_98 -> V_163 > V_6 )
break;
} else {
if ( V_92 -> V_6 + V_92 -> V_89 > V_6 )
break;
}
V_101 = F_100 ( & V_92 -> V_105 ) ;
if ( ! V_101 )
return NULL ;
V_92 = F_101 ( V_101 , struct V_95 , V_105 ) ;
}
return V_92 ;
}
static inline void
F_159 ( struct V_97 * V_98 ,
struct V_95 * V_169 )
{
F_160 ( & V_169 -> V_105 , & V_98 -> V_104 ) ;
V_98 -> V_175 -- ;
}
static void F_102 ( struct V_97 * V_98 ,
struct V_95 * V_169 )
{
F_159 ( V_98 , V_169 ) ;
V_98 -> V_124 -= V_169 -> V_89 ;
}
static int F_104 ( struct V_97 * V_98 ,
struct V_95 * V_169 )
{
int V_18 = 0 ;
ASSERT ( V_169 -> V_89 || V_169 -> V_90 ) ;
V_18 = F_153 ( & V_98 -> V_104 , V_169 -> V_6 ,
& V_169 -> V_105 , ( V_169 -> V_90 != NULL ) ) ;
if ( V_18 )
return V_18 ;
V_98 -> V_124 += V_169 -> V_89 ;
V_98 -> V_175 ++ ;
return V_18 ;
}
static void F_161 ( struct V_97 * V_98 )
{
struct V_28 * V_29 = V_98 -> V_176 ;
T_1 V_177 ;
T_1 V_178 ;
T_1 V_179 ;
T_1 V_78 = V_29 -> V_10 . V_6 ;
T_1 V_180 = V_165 * V_98 -> V_163 ;
T_1 V_181 = F_152 ( V_78 + V_180 - 1 , V_180 ) ;
V_181 = F_162 ( T_1 , V_181 , 1 ) ;
ASSERT ( V_98 -> V_113 <= V_181 ) ;
if ( V_78 < V_182 )
V_177 = V_183 ;
else
V_177 = V_183 * F_149 ( V_78 , V_182 ) ;
V_178 = ( V_98 -> V_113 + 1 ) * V_98 -> V_163 ;
if ( V_178 >= V_177 ) {
V_98 -> V_184 = 0 ;
return;
}
V_179 = V_177 - V_178 ;
V_179 = F_163 ( T_1 , V_179 , V_177 >> 1 ) ;
V_98 -> V_184 =
F_149 ( V_179 , sizeof( struct V_95 ) ) ;
}
static inline void F_164 ( struct V_97 * V_98 ,
struct V_95 * V_169 ,
T_1 V_6 , T_1 V_89 )
{
unsigned long V_137 , V_185 ;
V_137 = F_148 ( V_169 -> V_6 , V_98 -> V_163 , V_6 ) ;
V_185 = F_150 ( V_89 , V_98 -> V_163 ) ;
ASSERT ( V_137 + V_185 <= V_165 ) ;
F_165 ( V_169 -> V_90 , V_137 , V_185 ) ;
V_169 -> V_89 -= V_89 ;
}
static void F_166 ( struct V_97 * V_98 ,
struct V_95 * V_169 , T_1 V_6 ,
T_1 V_89 )
{
F_164 ( V_98 , V_169 , V_6 , V_89 ) ;
V_98 -> V_124 -= V_89 ;
}
static void F_167 ( struct V_97 * V_98 ,
struct V_95 * V_169 , T_1 V_6 ,
T_1 V_89 )
{
unsigned long V_137 , V_185 ;
V_137 = F_148 ( V_169 -> V_6 , V_98 -> V_163 , V_6 ) ;
V_185 = F_150 ( V_89 , V_98 -> V_163 ) ;
ASSERT ( V_137 + V_185 <= V_165 ) ;
F_168 ( V_169 -> V_90 , V_137 , V_185 ) ;
V_169 -> V_89 += V_89 ;
V_98 -> V_124 += V_89 ;
}
static int F_169 ( struct V_97 * V_98 ,
struct V_95 * V_186 , T_1 * V_6 ,
T_1 * V_89 , bool V_187 )
{
unsigned long V_188 = 0 ;
unsigned long V_189 = 0 ;
unsigned long V_190 , V_79 ;
unsigned long V_191 ;
unsigned long V_192 ;
if ( V_187 &&
V_186 -> V_193 &&
V_186 -> V_193 < * V_89 ) {
* V_89 = V_186 -> V_193 ;
return - 1 ;
}
V_79 = F_148 ( V_186 -> V_6 , V_98 -> V_163 ,
F_162 ( T_1 , * V_6 , V_186 -> V_6 ) ) ;
V_190 = F_150 ( * V_89 , V_98 -> V_163 ) ;
F_170 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
if ( V_187 && V_190 == 1 ) {
V_188 = 1 ;
break;
}
V_191 = F_171 ( V_186 -> V_90 ,
V_165 , V_79 ) ;
V_192 = V_191 - V_79 ;
if ( V_192 >= V_190 ) {
V_188 = V_192 ;
break;
} else if ( V_192 > V_189 ) {
V_189 = V_192 ;
}
V_79 = V_191 ;
}
if ( V_188 ) {
* V_6 = ( T_1 ) ( V_79 * V_98 -> V_163 ) + V_186 -> V_6 ;
* V_89 = ( T_1 ) ( V_188 ) * V_98 -> V_163 ;
return 0 ;
}
* V_89 = ( T_1 ) ( V_189 ) * V_98 -> V_163 ;
V_186 -> V_193 = * V_89 ;
return - 1 ;
}
static struct V_95 *
F_172 ( struct V_97 * V_98 , T_1 * V_6 , T_1 * V_89 ,
unsigned long V_194 , T_1 * V_193 )
{
struct V_95 * V_92 ;
struct V_100 * V_132 ;
T_1 V_86 ;
T_1 V_195 ;
int V_18 ;
if ( ! V_98 -> V_104 . V_100 )
goto V_111;
V_92 = F_157 ( V_98 , F_151 ( V_98 , * V_6 ) , 0 , 1 ) ;
if ( ! V_92 )
goto V_111;
for ( V_132 = & V_92 -> V_105 ; V_132 ; V_132 = F_100 ( V_132 ) ) {
V_92 = F_101 ( V_132 , struct V_95 , V_105 ) ;
if ( V_92 -> V_89 < * V_89 ) {
if ( V_92 -> V_89 > * V_193 )
* V_193 = V_92 -> V_89 ;
continue;
}
if ( * V_89 >= V_194 ) {
V_86 = V_92 -> V_6 - V_98 -> V_137 + V_194 - 1 ;
V_86 = F_152 ( V_86 , V_194 ) ;
V_86 = V_86 * V_194 + V_98 -> V_137 ;
V_195 = V_86 - V_92 -> V_6 ;
} else {
V_195 = 0 ;
V_86 = V_92 -> V_6 ;
}
if ( V_92 -> V_89 < * V_89 + V_195 ) {
if ( V_92 -> V_89 > * V_193 )
* V_193 = V_92 -> V_89 ;
continue;
}
if ( V_92 -> V_90 ) {
T_1 V_78 = * V_89 ;
V_18 = F_169 ( V_98 , V_92 , & V_86 , & V_78 , true ) ;
if ( ! V_18 ) {
* V_6 = V_86 ;
* V_89 = V_78 ;
return V_92 ;
} else if ( V_78 > * V_193 ) {
* V_193 = V_78 ;
}
continue;
}
* V_6 = V_86 ;
* V_89 = V_92 -> V_89 - V_195 ;
return V_92 ;
}
V_111:
return NULL ;
}
static void F_173 ( struct V_97 * V_98 ,
struct V_95 * V_169 , T_1 V_6 )
{
V_169 -> V_6 = F_151 ( V_98 , V_6 ) ;
V_169 -> V_89 = 0 ;
F_174 ( & V_169 -> V_116 ) ;
F_104 ( V_98 , V_169 ) ;
V_98 -> V_113 ++ ;
V_98 -> V_114 -> V_115 ( V_98 ) ;
}
static void F_175 ( struct V_97 * V_98 ,
struct V_95 * V_186 )
{
F_102 ( V_98 , V_186 ) ;
F_61 ( V_186 -> V_90 ) ;
F_103 ( V_107 , V_186 ) ;
V_98 -> V_113 -- ;
V_98 -> V_114 -> V_115 ( V_98 ) ;
}
static T_6 int F_176 ( struct V_97 * V_98 ,
struct V_95 * V_186 ,
T_1 * V_6 , T_1 * V_89 )
{
T_1 V_196 ;
T_1 V_197 , V_198 ;
int V_18 ;
V_102:
V_196 = V_186 -> V_6 + ( T_1 ) ( V_165 * V_98 -> V_163 ) - 1 ;
V_197 = * V_6 ;
V_198 = V_98 -> V_163 ;
V_198 = F_129 ( V_198 , V_196 - V_197 + 1 ) ;
V_18 = F_169 ( V_98 , V_186 , & V_197 , & V_198 ,
false ) ;
if ( V_18 < 0 || V_197 != * V_6 )
return - V_199 ;
V_198 = F_129 ( V_198 , * V_89 ) ;
V_198 = F_129 ( V_198 , V_196 - V_197 + 1 ) ;
F_166 ( V_98 , V_186 , V_197 , V_198 ) ;
* V_6 += V_198 ;
* V_89 -= V_198 ;
if ( * V_89 ) {
struct V_100 * V_106 = F_100 ( & V_186 -> V_105 ) ;
if ( ! V_186 -> V_89 )
F_175 ( V_98 , V_186 ) ;
if ( ! V_106 )
return - V_199 ;
V_186 = F_101 ( V_106 , struct V_95 ,
V_105 ) ;
if ( ! V_186 -> V_90 )
return - V_200 ;
V_197 = * V_6 ;
V_198 = V_98 -> V_163 ;
V_18 = F_169 ( V_98 , V_186 , & V_197 ,
& V_198 , false ) ;
if ( V_18 < 0 || V_197 != * V_6 )
return - V_200 ;
goto V_102;
} else if ( ! V_186 -> V_89 )
F_175 ( V_98 , V_186 ) ;
return 0 ;
}
static T_1 F_177 ( struct V_97 * V_98 ,
struct V_95 * V_169 , T_1 V_6 ,
T_1 V_89 )
{
T_1 V_201 = 0 ;
T_1 V_196 ;
V_196 = V_169 -> V_6 + ( T_1 ) ( V_165 * V_98 -> V_163 ) ;
V_201 = F_129 ( V_196 - V_6 , V_89 ) ;
F_167 ( V_98 , V_169 , V_6 , V_201 ) ;
V_169 -> V_193 = 0 ;
return V_201 ;
}
static bool F_178 ( struct V_97 * V_98 ,
struct V_95 * V_169 )
{
struct V_28 * V_29 = V_98 -> V_176 ;
struct V_7 * V_8 = V_29 -> V_8 ;
bool V_202 = false ;
#ifdef F_179
if ( F_180 ( V_29 ) )
V_202 = true ;
#endif
if ( ! V_202 && V_98 -> V_175 < V_98 -> V_184 ) {
if ( V_169 -> V_89 <= V_8 -> V_203 * 4 ) {
if ( V_98 -> V_175 * 2 <= V_98 -> V_184 )
return false ;
} else {
return false ;
}
}
if ( ( ( V_165 * V_98 -> V_163 ) >> 1 ) > V_29 -> V_10 . V_6 )
return false ;
return true ;
}
static int F_181 ( struct V_97 * V_98 ,
struct V_95 * V_169 )
{
struct V_95 * V_186 ;
struct V_28 * V_29 = NULL ;
int V_204 = 0 ;
T_1 V_89 , V_6 , V_205 ;
int V_18 ;
V_89 = V_169 -> V_89 ;
V_6 = V_169 -> V_6 ;
if ( ! V_98 -> V_114 -> F_178 ( V_98 , V_169 ) )
return 0 ;
if ( V_98 -> V_114 == & V_206 )
V_29 = V_98 -> V_176 ;
V_102:
if ( V_29 && ! F_45 ( & V_29 -> V_135 ) ) {
struct V_129 * V_130 ;
struct V_100 * V_132 ;
struct V_95 * V_92 ;
V_130 = F_118 ( V_29 -> V_135 . V_106 ,
struct V_129 ,
V_136 ) ;
F_15 ( & V_130 -> V_33 ) ;
V_132 = F_99 ( & V_130 -> V_3 ) ;
if ( ! V_132 ) {
F_17 ( & V_130 -> V_33 ) ;
goto V_207;
}
V_92 = F_101 ( V_132 , struct V_95 , V_105 ) ;
if ( ! V_92 -> V_90 ) {
F_17 ( & V_130 -> V_33 ) ;
goto V_207;
}
if ( V_92 -> V_6 == F_151 ( V_98 , V_6 ) ) {
V_205 = F_177 ( V_98 , V_92 ,
V_6 , V_89 ) ;
V_89 -= V_205 ;
V_6 += V_205 ;
}
F_17 ( & V_130 -> V_33 ) ;
if ( ! V_89 ) {
V_18 = 1 ;
goto V_111;
}
}
V_207:
V_186 = F_157 ( V_98 , F_151 ( V_98 , V_6 ) ,
1 , 0 ) ;
if ( ! V_186 ) {
ASSERT ( V_204 == 0 ) ;
goto V_208;
}
V_205 = F_177 ( V_98 , V_186 , V_6 , V_89 ) ;
V_89 -= V_205 ;
V_6 += V_205 ;
V_204 = 0 ;
if ( ! V_89 ) {
V_18 = 1 ;
goto V_111;
} else
goto V_102;
V_208:
if ( V_169 && V_169 -> V_90 ) {
F_173 ( V_98 , V_169 , V_6 ) ;
V_204 = 1 ;
V_169 = NULL ;
goto V_102;
} else {
F_17 ( & V_98 -> V_103 ) ;
if ( ! V_169 ) {
V_169 = F_110 ( V_107 ,
V_63 ) ;
if ( ! V_169 ) {
F_15 ( & V_98 -> V_103 ) ;
V_18 = - V_54 ;
goto V_111;
}
}
V_169 -> V_90 = F_57 ( V_70 , V_63 ) ;
F_15 ( & V_98 -> V_103 ) ;
if ( ! V_169 -> V_90 ) {
V_18 = - V_54 ;
goto V_111;
}
goto V_102;
}
V_111:
if ( V_169 ) {
if ( V_169 -> V_90 )
F_61 ( V_169 -> V_90 ) ;
F_103 ( V_107 , V_169 ) ;
}
return V_18 ;
}
static bool F_182 ( struct V_97 * V_98 ,
struct V_95 * V_169 , bool V_209 )
{
struct V_95 * V_210 ;
struct V_95 * V_211 ;
bool V_212 = false ;
T_1 V_6 = V_169 -> V_6 ;
T_1 V_89 = V_169 -> V_89 ;
V_211 = F_157 ( V_98 , V_6 + V_89 , 0 , 0 ) ;
if ( V_211 && F_158 ( & V_211 -> V_105 ) )
V_210 = F_101 ( F_158 ( & V_211 -> V_105 ) ,
struct V_95 , V_105 ) ;
else
V_210 = F_157 ( V_98 , V_6 - 1 , 0 , 0 ) ;
if ( V_211 && ! V_211 -> V_90 ) {
if ( V_209 )
F_102 ( V_98 , V_211 ) ;
else
F_159 ( V_98 , V_211 ) ;
V_169 -> V_89 += V_211 -> V_89 ;
F_103 ( V_107 , V_211 ) ;
V_212 = true ;
}
if ( V_210 && ! V_210 -> V_90 &&
V_210 -> V_6 + V_210 -> V_89 == V_6 ) {
if ( V_209 )
F_102 ( V_98 , V_210 ) ;
else
F_159 ( V_98 , V_210 ) ;
V_169 -> V_6 = V_210 -> V_6 ;
V_169 -> V_89 += V_210 -> V_89 ;
F_103 ( V_107 , V_210 ) ;
V_212 = true ;
}
return V_212 ;
}
static bool F_183 ( struct V_97 * V_98 ,
struct V_95 * V_169 ,
bool V_209 )
{
struct V_95 * V_90 ;
unsigned long V_79 ;
unsigned long V_213 ;
const T_1 V_196 = V_169 -> V_6 + V_169 -> V_89 ;
const T_1 V_214 = F_151 ( V_98 , V_196 ) ;
T_1 V_89 ;
V_90 = F_157 ( V_98 , V_214 , 1 , 0 ) ;
if ( ! V_90 )
return false ;
V_79 = F_148 ( V_90 -> V_6 , V_98 -> V_163 , V_196 ) ;
V_213 = F_171 ( V_90 -> V_90 , V_165 , V_79 ) ;
if ( V_213 == V_79 )
return false ;
V_89 = ( V_213 - V_79 ) * V_98 -> V_163 ;
V_169 -> V_89 += V_89 ;
if ( V_209 )
F_166 ( V_98 , V_90 , V_196 , V_89 ) ;
else
F_164 ( V_98 , V_90 , V_196 , V_89 ) ;
if ( ! V_90 -> V_89 )
F_175 ( V_98 , V_90 ) ;
return true ;
}
static bool F_184 ( struct V_97 * V_98 ,
struct V_95 * V_169 ,
bool V_209 )
{
struct V_95 * V_90 ;
T_1 V_214 ;
unsigned long V_79 ;
unsigned long V_213 ;
unsigned long V_215 ;
T_1 V_89 ;
V_214 = F_151 ( V_98 , V_169 -> V_6 ) ;
if ( V_214 == V_169 -> V_6 ) {
if ( V_169 -> V_6 == 0 )
return false ;
V_214 = F_151 ( V_98 , V_169 -> V_6 - 1 ) ;
}
V_90 = F_157 ( V_98 , V_214 , 1 , 0 ) ;
if ( ! V_90 )
return false ;
V_79 = F_148 ( V_90 -> V_6 , V_98 -> V_163 , V_169 -> V_6 ) - 1 ;
V_213 = 0 ;
V_215 = ( unsigned long ) - 1 ;
F_185 (j, bitmap->bitmap, BITS_PER_BITMAP) {
if ( V_213 > V_79 )
break;
V_215 = V_213 ;
}
if ( V_215 == V_79 )
return false ;
if ( V_215 == ( unsigned long ) - 1 )
V_89 = ( V_79 + 1 ) * V_98 -> V_163 ;
else
V_89 = ( V_79 - V_215 ) * V_98 -> V_163 ;
V_169 -> V_6 -= V_89 ;
V_169 -> V_89 += V_89 ;
if ( V_209 )
F_166 ( V_98 , V_90 , V_169 -> V_6 , V_89 ) ;
else
F_164 ( V_98 , V_90 , V_169 -> V_6 , V_89 ) ;
if ( ! V_90 -> V_89 )
F_175 ( V_98 , V_90 ) ;
return true ;
}
static void F_186 ( struct V_97 * V_98 ,
struct V_95 * V_169 ,
bool V_209 )
{
ASSERT ( ! V_169 -> V_90 ) ;
ASSERT ( F_187 ( & V_169 -> V_105 ) ) ;
if ( V_98 -> V_113 > 0 ) {
bool V_216 ;
bool V_217 = false ;
V_216 = F_183 ( V_98 , V_169 , V_209 ) ;
if ( V_98 -> V_113 > 0 )
V_217 = F_184 ( V_98 , V_169 ,
V_209 ) ;
if ( V_216 || V_217 )
F_182 ( V_98 , V_169 , V_209 ) ;
}
}
int F_188 ( struct V_7 * V_8 ,
struct V_97 * V_98 ,
T_1 V_6 , T_1 V_89 )
{
struct V_95 * V_169 ;
int V_18 = 0 ;
V_169 = F_110 ( V_107 , V_63 ) ;
if ( ! V_169 )
return - V_54 ;
V_169 -> V_6 = V_6 ;
V_169 -> V_89 = V_89 ;
F_189 ( & V_169 -> V_105 ) ;
F_15 ( & V_98 -> V_103 ) ;
if ( F_182 ( V_98 , V_169 , true ) )
goto V_218;
V_18 = F_181 ( V_98 , V_169 ) ;
if ( V_18 < 0 ) {
goto V_111;
} else if ( V_18 ) {
V_18 = 0 ;
goto V_111;
}
V_218:
F_186 ( V_98 , V_169 , true ) ;
V_18 = F_104 ( V_98 , V_169 ) ;
if ( V_18 )
F_103 ( V_107 , V_169 ) ;
V_111:
F_17 ( & V_98 -> V_103 ) ;
if ( V_18 ) {
F_190 ( V_8 , L_11 , V_18 ) ;
ASSERT ( V_18 != - V_172 ) ;
}
return V_18 ;
}
int F_191 ( struct V_28 * V_29 ,
T_1 V_6 , T_1 V_89 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_169 ;
int V_18 ;
bool V_219 = false ;
F_15 ( & V_98 -> V_103 ) ;
V_102:
V_18 = 0 ;
if ( ! V_89 )
goto V_220;
V_169 = F_157 ( V_98 , V_6 , 0 , 0 ) ;
if ( ! V_169 ) {
V_169 = F_157 ( V_98 , F_151 ( V_98 , V_6 ) ,
1 , 0 ) ;
if ( ! V_169 ) {
F_141 ( V_219 ) ;
goto V_220;
}
}
V_219 = false ;
if ( ! V_169 -> V_90 ) {
F_102 ( V_98 , V_169 ) ;
if ( V_6 == V_169 -> V_6 ) {
T_1 V_221 = F_129 ( V_89 , V_169 -> V_89 ) ;
V_169 -> V_89 -= V_221 ;
V_169 -> V_6 += V_221 ;
if ( V_169 -> V_89 ) {
V_18 = F_104 ( V_98 , V_169 ) ;
F_141 ( V_18 ) ;
} else {
F_103 ( V_107 , V_169 ) ;
}
V_6 += V_221 ;
V_89 -= V_221 ;
goto V_102;
} else {
T_1 V_222 = V_169 -> V_89 + V_169 -> V_6 ;
V_169 -> V_89 = V_6 - V_169 -> V_6 ;
V_18 = F_104 ( V_98 , V_169 ) ;
F_141 ( V_18 ) ;
if ( V_18 )
goto V_220;
if ( V_222 < V_6 + V_89 ) {
V_89 -= V_222 - V_6 ;
V_6 = V_222 ;
goto V_102;
} else if ( V_222 == V_6 + V_89 ) {
goto V_220;
}
F_17 ( & V_98 -> V_103 ) ;
V_18 = F_192 ( V_29 , V_6 + V_89 ,
V_222 - ( V_6 + V_89 ) ) ;
F_141 ( V_18 ) ;
goto V_111;
}
}
V_18 = F_176 ( V_98 , V_169 , & V_6 , & V_89 ) ;
if ( V_18 == - V_200 ) {
V_219 = true ;
goto V_102;
}
V_220:
F_17 ( & V_98 -> V_103 ) ;
V_111:
return V_18 ;
}
void F_193 ( struct V_28 * V_29 ,
T_1 V_89 )
{
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_169 ;
struct V_100 * V_101 ;
int V_185 = 0 ;
for ( V_101 = F_99 ( & V_98 -> V_104 ) ; V_101 ; V_101 = F_100 ( V_101 ) ) {
V_169 = F_101 ( V_101 , struct V_95 , V_105 ) ;
if ( V_169 -> V_89 >= V_89 && ! V_29 -> V_223 )
V_185 ++ ;
F_190 ( V_8 , L_12 ,
V_169 -> V_6 , V_169 -> V_89 ,
( V_169 -> V_90 ) ? L_13 : L_14 ) ;
}
F_19 ( V_8 , L_15 ,
F_45 ( & V_29 -> V_135 ) ? L_14 : L_13 ) ;
F_19 ( V_8 ,
L_16 , V_185 ) ;
}
void F_194 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_97 * V_98 = V_29 -> V_117 ;
F_195 ( & V_98 -> V_103 ) ;
V_98 -> V_163 = V_8 -> V_203 ;
V_98 -> V_137 = V_29 -> V_10 . V_19 ;
V_98 -> V_176 = V_29 ;
V_98 -> V_114 = & V_206 ;
F_174 ( & V_98 -> V_224 ) ;
F_196 ( & V_98 -> V_158 ) ;
V_98 -> V_184 = ( V_225 / 2 ) / sizeof( struct V_95 ) ;
}
static int
F_197 (
struct V_28 * V_29 ,
struct V_129 * V_130 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_92 ;
struct V_100 * V_132 ;
F_15 ( & V_130 -> V_33 ) ;
if ( V_130 -> V_29 != V_29 )
goto V_111;
V_130 -> V_29 = NULL ;
V_130 -> V_226 = 0 ;
F_46 ( & V_130 -> V_136 ) ;
V_132 = F_99 ( & V_130 -> V_3 ) ;
while ( V_132 ) {
bool V_90 ;
V_92 = F_101 ( V_132 , struct V_95 , V_105 ) ;
V_132 = F_100 ( & V_92 -> V_105 ) ;
F_160 ( & V_92 -> V_105 , & V_130 -> V_3 ) ;
F_189 ( & V_92 -> V_105 ) ;
V_90 = ( V_92 -> V_90 != NULL ) ;
if ( ! V_90 ) {
F_182 ( V_98 , V_92 , false ) ;
F_186 ( V_98 , V_92 , false ) ;
}
F_153 ( & V_98 -> V_104 ,
V_92 -> V_6 , & V_92 -> V_105 , V_90 ) ;
}
V_130 -> V_3 = V_227 ;
V_111:
F_17 ( & V_130 -> V_33 ) ;
F_48 ( V_29 ) ;
return 0 ;
}
static void F_198 (
struct V_97 * V_98 )
{
struct V_95 * V_169 ;
struct V_100 * V_132 ;
while ( ( V_132 = F_199 ( & V_98 -> V_104 ) ) != NULL ) {
V_169 = F_101 ( V_132 , struct V_95 , V_105 ) ;
if ( ! V_169 -> V_90 ) {
F_102 ( V_98 , V_169 ) ;
F_103 ( V_107 , V_169 ) ;
} else {
F_175 ( V_98 , V_169 ) ;
}
F_200 ( & V_98 -> V_103 ) ;
}
}
void F_113 ( struct V_97 * V_98 )
{
F_15 ( & V_98 -> V_103 ) ;
F_198 ( V_98 ) ;
F_17 ( & V_98 -> V_103 ) ;
}
void F_201 ( struct V_28 * V_29 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_129 * V_130 ;
struct V_127 * V_228 ;
F_15 ( & V_98 -> V_103 ) ;
while ( ( V_228 = V_29 -> V_135 . V_106 ) !=
& V_29 -> V_135 ) {
V_130 = F_118 ( V_228 , struct V_129 ,
V_136 ) ;
F_141 ( V_130 -> V_29 != V_29 ) ;
F_197 ( V_29 , V_130 ) ;
F_200 ( & V_98 -> V_103 ) ;
}
F_198 ( V_98 ) ;
F_17 ( & V_98 -> V_103 ) ;
}
T_1 F_202 ( struct V_28 * V_29 ,
T_1 V_6 , T_1 V_89 , T_1 V_229 ,
T_1 * V_193 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_92 = NULL ;
T_1 V_230 = V_89 + V_229 ;
T_1 V_18 = 0 ;
T_1 V_231 = 0 ;
T_1 V_232 = 0 ;
F_15 ( & V_98 -> V_103 ) ;
V_92 = F_172 ( V_98 , & V_6 , & V_230 ,
V_29 -> V_233 , V_193 ) ;
if ( ! V_92 )
goto V_111;
V_18 = V_6 ;
if ( V_92 -> V_90 ) {
F_166 ( V_98 , V_92 , V_6 , V_89 ) ;
if ( ! V_92 -> V_89 )
F_175 ( V_98 , V_92 ) ;
} else {
F_102 ( V_98 , V_92 ) ;
V_232 = V_6 - V_92 -> V_6 ;
V_231 = V_92 -> V_6 ;
V_92 -> V_6 = V_6 + V_89 ;
F_141 ( V_92 -> V_89 < V_89 + V_232 ) ;
V_92 -> V_89 -= V_89 + V_232 ;
if ( ! V_92 -> V_89 )
F_103 ( V_107 , V_92 ) ;
else
F_104 ( V_98 , V_92 ) ;
}
V_111:
F_17 ( & V_98 -> V_103 ) ;
if ( V_232 )
F_188 ( V_29 -> V_8 , V_98 ,
V_231 , V_232 ) ;
return V_18 ;
}
int F_203 (
struct V_28 * V_29 ,
struct V_129 * V_130 )
{
struct V_97 * V_98 ;
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
V_98 = V_29 -> V_117 ;
F_15 ( & V_98 -> V_103 ) ;
V_18 = F_197 ( V_29 , V_130 ) ;
F_17 ( & V_98 -> V_103 ) ;
F_48 ( V_29 ) ;
return V_18 ;
}
static T_1 F_205 ( struct V_28 * V_29 ,
struct V_129 * V_130 ,
struct V_95 * V_92 ,
T_1 V_89 , T_1 V_234 ,
T_1 * V_193 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
int V_235 ;
T_1 V_197 = V_130 -> V_226 ;
T_1 V_198 = V_89 ;
T_1 V_18 = 0 ;
V_197 = V_234 ;
V_198 = V_89 ;
V_235 = F_169 ( V_98 , V_92 , & V_197 , & V_198 , true ) ;
if ( V_235 ) {
if ( V_198 > * V_193 )
* V_193 = V_198 ;
return 0 ;
}
V_18 = V_197 ;
F_164 ( V_98 , V_92 , V_18 , V_89 ) ;
return V_18 ;
}
T_1 F_206 ( struct V_28 * V_29 ,
struct V_129 * V_130 , T_1 V_89 ,
T_1 V_234 , T_1 * V_193 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_92 = NULL ;
struct V_100 * V_132 ;
T_1 V_18 = 0 ;
F_15 ( & V_130 -> V_33 ) ;
if ( V_89 > V_130 -> V_236 )
goto V_111;
if ( V_130 -> V_29 != V_29 )
goto V_111;
V_132 = F_99 ( & V_130 -> V_3 ) ;
if ( ! V_132 )
goto V_111;
V_92 = F_101 ( V_132 , struct V_95 , V_105 ) ;
while ( 1 ) {
if ( V_92 -> V_89 < V_89 && V_92 -> V_89 > * V_193 )
* V_193 = V_92 -> V_89 ;
if ( V_92 -> V_89 < V_89 ||
( ! V_92 -> V_90 && V_92 -> V_6 < V_234 ) ) {
V_132 = F_100 ( & V_92 -> V_105 ) ;
if ( ! V_132 )
break;
V_92 = F_101 ( V_132 , struct V_95 ,
V_105 ) ;
continue;
}
if ( V_92 -> V_90 ) {
V_18 = F_205 ( V_29 ,
V_130 , V_92 , V_89 ,
V_130 -> V_226 ,
V_193 ) ;
if ( V_18 == 0 ) {
V_132 = F_100 ( & V_92 -> V_105 ) ;
if ( ! V_132 )
break;
V_92 = F_101 ( V_132 , struct V_95 ,
V_105 ) ;
continue;
}
V_130 -> V_226 += V_89 ;
} else {
V_18 = V_92 -> V_6 ;
V_92 -> V_6 += V_89 ;
V_92 -> V_89 -= V_89 ;
}
if ( V_92 -> V_89 == 0 )
F_160 ( & V_92 -> V_105 , & V_130 -> V_3 ) ;
break;
}
V_111:
F_17 ( & V_130 -> V_33 ) ;
if ( ! V_18 )
return 0 ;
F_15 ( & V_98 -> V_103 ) ;
V_98 -> V_124 -= V_89 ;
if ( V_92 -> V_89 == 0 ) {
V_98 -> V_175 -- ;
if ( V_92 -> V_90 ) {
F_61 ( V_92 -> V_90 ) ;
V_98 -> V_113 -- ;
V_98 -> V_114 -> V_115 ( V_98 ) ;
}
F_103 ( V_107 , V_92 ) ;
}
F_17 ( & V_98 -> V_103 ) ;
return V_18 ;
}
static int F_207 ( struct V_28 * V_29 ,
struct V_95 * V_92 ,
struct V_129 * V_130 ,
T_1 V_6 , T_1 V_89 ,
T_1 V_237 , T_1 V_238 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
unsigned long V_191 ;
unsigned long V_79 ;
unsigned long V_239 ;
unsigned long V_240 ;
unsigned long V_188 ;
unsigned long V_189 = 0 ;
unsigned long V_137 = 0 ;
unsigned long V_241 = 0 ;
int V_18 ;
V_79 = F_148 ( V_92 -> V_6 , V_98 -> V_163 ,
F_162 ( T_1 , V_6 , V_92 -> V_6 ) ) ;
V_239 = F_150 ( V_89 , V_98 -> V_163 ) ;
V_240 = F_150 ( V_238 , V_98 -> V_163 ) ;
if ( V_92 -> V_193 &&
V_92 -> V_193 < V_237 )
return - V_52 ;
V_102:
V_188 = 0 ;
F_170 (i, entry->bitmap, BITS_PER_BITMAP) {
V_191 = F_171 ( V_92 -> V_90 ,
V_165 , V_79 ) ;
if ( V_191 - V_79 >= V_240 ) {
V_188 = V_191 - V_79 ;
if ( V_188 > V_189 )
V_189 = V_188 ;
break;
}
if ( V_191 - V_79 > V_189 )
V_189 = V_191 - V_79 ;
V_79 = V_191 ;
}
if ( ! V_188 ) {
V_92 -> V_193 = ( T_1 ) V_189 * V_98 -> V_163 ;
return - V_52 ;
}
if ( ! V_241 ) {
V_137 = V_79 ;
V_130 -> V_236 = 0 ;
}
V_241 += V_188 ;
if ( V_130 -> V_236 < V_188 * V_98 -> V_163 )
V_130 -> V_236 = V_188 * V_98 -> V_163 ;
if ( V_241 < V_239 || V_130 -> V_236 < V_237 ) {
V_79 = V_191 + 1 ;
goto V_102;
}
V_130 -> V_226 = V_137 * V_98 -> V_163 + V_92 -> V_6 ;
F_160 ( & V_92 -> V_105 , & V_98 -> V_104 ) ;
V_18 = F_153 ( & V_130 -> V_3 , V_92 -> V_6 ,
& V_92 -> V_105 , 1 ) ;
ASSERT ( ! V_18 ) ;
F_208 ( V_29 , V_130 ,
V_241 * V_98 -> V_163 , 1 ) ;
return 0 ;
}
static T_6 int
F_209 ( struct V_28 * V_29 ,
struct V_129 * V_130 ,
struct V_127 * V_108 , T_1 V_6 , T_1 V_89 ,
T_1 V_237 , T_1 V_238 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_242 = NULL ;
struct V_95 * V_92 = NULL ;
struct V_95 * V_243 ;
struct V_100 * V_132 ;
T_1 V_244 ;
T_1 V_245 ;
T_1 V_246 = 0 ;
V_92 = F_157 ( V_98 , V_6 , 0 , 1 ) ;
if ( ! V_92 )
return - V_52 ;
while ( V_92 -> V_90 || V_92 -> V_89 < V_238 ) {
if ( V_92 -> V_90 && F_45 ( & V_92 -> V_116 ) )
F_111 ( & V_92 -> V_116 , V_108 ) ;
V_132 = F_100 ( & V_92 -> V_105 ) ;
if ( ! V_132 )
return - V_52 ;
V_92 = F_101 ( V_132 , struct V_95 , V_105 ) ;
}
V_244 = V_92 -> V_89 ;
V_245 = V_92 -> V_89 ;
V_242 = V_92 ;
V_243 = V_92 ;
for ( V_132 = F_100 ( & V_92 -> V_105 ) ; V_132 ;
V_132 = F_100 ( & V_92 -> V_105 ) ) {
V_92 = F_101 ( V_132 , struct V_95 , V_105 ) ;
if ( V_92 -> V_90 ) {
if ( F_45 ( & V_92 -> V_116 ) )
F_111 ( & V_92 -> V_116 , V_108 ) ;
continue;
}
if ( V_92 -> V_89 < V_238 )
continue;
V_243 = V_92 ;
V_244 += V_92 -> V_89 ;
if ( V_92 -> V_89 > V_245 )
V_245 = V_92 -> V_89 ;
}
if ( V_244 < V_89 || V_245 < V_237 )
return - V_52 ;
V_130 -> V_226 = V_242 -> V_6 ;
V_132 = & V_242 -> V_105 ;
do {
int V_18 ;
V_92 = F_101 ( V_132 , struct V_95 , V_105 ) ;
V_132 = F_100 ( & V_92 -> V_105 ) ;
if ( V_92 -> V_90 || V_92 -> V_89 < V_238 )
continue;
F_160 ( & V_92 -> V_105 , & V_98 -> V_104 ) ;
V_18 = F_153 ( & V_130 -> V_3 , V_92 -> V_6 ,
& V_92 -> V_105 , 0 ) ;
V_246 += V_92 -> V_89 ;
ASSERT ( ! V_18 ) ;
} while ( V_132 && V_92 != V_243 );
V_130 -> V_236 = V_245 ;
F_208 ( V_29 , V_130 , V_246 , 0 ) ;
return 0 ;
}
static T_6 int
F_210 ( struct V_28 * V_29 ,
struct V_129 * V_130 ,
struct V_127 * V_108 , T_1 V_6 , T_1 V_89 ,
T_1 V_237 , T_1 V_238 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_92 = NULL ;
int V_18 = - V_52 ;
T_1 V_214 = F_151 ( V_98 , V_6 ) ;
if ( V_98 -> V_113 == 0 )
return - V_52 ;
if ( ! F_45 ( V_108 ) )
V_92 = F_211 ( V_108 , struct V_95 , V_116 ) ;
if ( ! V_92 || V_92 -> V_6 != V_214 ) {
V_92 = F_157 ( V_98 , V_214 , 1 , 0 ) ;
if ( V_92 && F_45 ( & V_92 -> V_116 ) )
F_212 ( & V_92 -> V_116 , V_108 ) ;
}
F_119 (entry, bitmaps, list) {
if ( V_92 -> V_89 < V_89 )
continue;
V_18 = F_207 ( V_29 , V_92 , V_130 , V_6 ,
V_89 , V_237 , V_238 ) ;
if ( ! V_18 )
return 0 ;
}
return - V_52 ;
}
int F_213 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
struct V_129 * V_130 ,
T_1 V_6 , T_1 V_89 , T_1 V_229 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_92 , * V_86 ;
F_106 ( V_108 ) ;
T_1 V_238 ;
T_1 V_237 ;
int V_18 ;
if ( F_214 ( V_8 , V_247 ) ) {
V_237 = V_238 = V_89 + V_229 ;
} else if ( V_29 -> V_30 & V_248 ) {
V_237 = V_89 ;
V_238 = V_8 -> V_203 ;
} else {
V_237 = F_128 ( V_89 , ( V_89 + V_229 ) >> 2 ) ;
V_238 = V_8 -> V_203 ;
}
F_15 ( & V_98 -> V_103 ) ;
if ( V_98 -> V_124 < V_89 ) {
F_17 ( & V_98 -> V_103 ) ;
return - V_52 ;
}
F_15 ( & V_130 -> V_33 ) ;
if ( V_130 -> V_29 ) {
V_18 = 0 ;
goto V_111;
}
F_215 ( V_29 , V_6 , V_89 , V_229 ,
V_238 ) ;
V_18 = F_209 ( V_29 , V_130 , & V_108 , V_6 ,
V_89 + V_229 ,
V_237 , V_238 ) ;
if ( V_18 )
V_18 = F_210 ( V_29 , V_130 , & V_108 ,
V_6 , V_89 + V_229 ,
V_237 , V_238 ) ;
F_112 (entry, tmp, &bitmaps, list)
F_46 ( & V_92 -> V_116 ) ;
if ( ! V_18 ) {
F_204 ( & V_29 -> V_185 ) ;
F_111 ( & V_130 -> V_136 ,
& V_29 -> V_135 ) ;
V_130 -> V_29 = V_29 ;
} else {
F_216 ( V_29 ) ;
}
V_111:
F_17 ( & V_130 -> V_33 ) ;
F_17 ( & V_98 -> V_103 ) ;
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
T_1 * V_251 , T_1 V_137 , T_1 V_89 ,
T_1 V_252 , T_1 V_253 ,
struct V_133 * V_134 )
{
struct V_254 * V_255 = V_29 -> V_255 ;
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_97 * V_98 = V_29 -> V_117 ;
int V_18 ;
int V_256 = 0 ;
T_1 V_257 = 0 ;
F_15 ( & V_255 -> V_33 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( ! V_29 -> V_223 ) {
V_29 -> V_51 += V_253 ;
V_255 -> V_258 += V_253 ;
V_256 = 1 ;
}
F_17 ( & V_29 -> V_33 ) ;
F_17 ( & V_255 -> V_33 ) ;
V_18 = F_219 ( V_8 , V_137 , V_89 , & V_257 ) ;
if ( ! V_18 )
* V_251 += V_257 ;
F_44 ( & V_98 -> V_158 ) ;
F_192 ( V_29 , V_252 , V_253 ) ;
F_220 ( & V_134 -> V_116 ) ;
F_54 ( & V_98 -> V_158 ) ;
if ( V_256 ) {
F_15 ( & V_255 -> V_33 ) ;
F_15 ( & V_29 -> V_33 ) ;
if ( V_29 -> V_223 )
V_255 -> V_259 += V_253 ;
V_29 -> V_51 -= V_253 ;
V_255 -> V_258 -= V_253 ;
F_17 ( & V_255 -> V_33 ) ;
F_17 ( & V_29 -> V_33 ) ;
}
return V_18 ;
}
static int F_221 ( struct V_28 * V_29 ,
T_1 * V_251 , T_1 V_137 , T_1 V_196 , T_1 V_260 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_92 ;
struct V_100 * V_132 ;
int V_18 = 0 ;
T_1 V_143 ;
T_1 V_179 ;
T_1 V_89 ;
while ( V_137 < V_196 ) {
struct V_133 V_134 ;
F_44 ( & V_98 -> V_158 ) ;
F_15 ( & V_98 -> V_103 ) ;
if ( V_98 -> V_124 < V_260 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
break;
}
V_92 = F_157 ( V_98 , V_137 , 0 , 1 ) ;
if ( ! V_92 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
break;
}
while ( V_92 -> V_90 ) {
V_132 = F_100 ( & V_92 -> V_105 ) ;
if ( ! V_132 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
goto V_111;
}
V_92 = F_101 ( V_132 , struct V_95 ,
V_105 ) ;
}
if ( V_92 -> V_6 >= V_196 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
break;
}
V_143 = V_92 -> V_6 ;
V_179 = V_92 -> V_89 ;
V_137 = F_128 ( V_137 , V_143 ) ;
V_89 = F_129 ( V_143 + V_179 , V_196 ) - V_137 ;
if ( V_89 < V_260 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
goto V_106;
}
F_102 ( V_98 , V_92 ) ;
F_103 ( V_107 , V_92 ) ;
F_17 ( & V_98 -> V_103 ) ;
V_134 . V_137 = V_143 ;
V_134 . V_89 = V_179 ;
F_111 ( & V_134 . V_116 , & V_98 -> V_224 ) ;
F_54 ( & V_98 -> V_158 ) ;
V_18 = F_218 ( V_29 , V_251 , V_137 , V_89 ,
V_143 , V_179 , & V_134 ) ;
if ( V_18 )
break;
V_106:
V_137 += V_89 ;
if ( F_222 ( V_261 ) ) {
V_18 = - V_262 ;
break;
}
F_223 () ;
}
V_111:
return V_18 ;
}
static int F_224 ( struct V_28 * V_29 ,
T_1 * V_251 , T_1 V_137 , T_1 V_196 , T_1 V_260 )
{
struct V_97 * V_98 = V_29 -> V_117 ;
struct V_95 * V_92 ;
int V_18 = 0 ;
int V_263 ;
T_1 V_89 ;
T_1 V_6 = F_151 ( V_98 , V_137 ) ;
while ( V_6 < V_196 ) {
bool V_264 = false ;
struct V_133 V_134 ;
F_44 ( & V_98 -> V_158 ) ;
F_15 ( & V_98 -> V_103 ) ;
if ( V_98 -> V_124 < V_260 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
break;
}
V_92 = F_157 ( V_98 , V_6 , 1 , 0 ) ;
if ( ! V_92 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
V_264 = true ;
goto V_106;
}
V_89 = V_260 ;
V_263 = F_169 ( V_98 , V_92 , & V_137 , & V_89 , false ) ;
if ( V_263 || V_137 >= V_196 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
V_264 = true ;
goto V_106;
}
V_89 = F_129 ( V_89 , V_196 - V_137 ) ;
if ( V_89 < V_260 ) {
F_17 ( & V_98 -> V_103 ) ;
F_54 ( & V_98 -> V_158 ) ;
goto V_106;
}
F_166 ( V_98 , V_92 , V_137 , V_89 ) ;
if ( V_92 -> V_89 == 0 )
F_175 ( V_98 , V_92 ) ;
F_17 ( & V_98 -> V_103 ) ;
V_134 . V_137 = V_137 ;
V_134 . V_89 = V_89 ;
F_111 ( & V_134 . V_116 , & V_98 -> V_224 ) ;
F_54 ( & V_98 -> V_158 ) ;
V_18 = F_218 ( V_29 , V_251 , V_137 , V_89 ,
V_137 , V_89 , & V_134 ) ;
if ( V_18 )
break;
V_106:
if ( V_264 ) {
V_6 += V_165 * V_98 -> V_163 ;
} else {
V_137 += V_89 ;
if ( V_137 >= V_6 + V_165 * V_98 -> V_163 )
V_6 += V_165 * V_98 -> V_163 ;
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
F_113 ( V_29 -> V_117 ) ;
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
goto V_111;
V_18 = F_224 ( V_29 , V_257 , V_137 , V_196 , V_260 ) ;
V_111:
F_226 ( V_29 ) ;
return V_18 ;
}
T_1 F_235 ( struct V_2 * V_276 )
{
struct V_97 * V_98 = V_276 -> V_277 ;
struct V_95 * V_92 = NULL ;
T_1 V_40 = 0 ;
F_15 ( & V_98 -> V_103 ) ;
if ( F_236 ( & V_98 -> V_104 ) )
goto V_111;
V_92 = F_101 ( F_99 ( & V_98 -> V_104 ) ,
struct V_95 , V_105 ) ;
if ( ! V_92 -> V_90 ) {
V_40 = V_92 -> V_6 ;
F_102 ( V_98 , V_92 ) ;
V_92 -> V_6 ++ ;
V_92 -> V_89 -- ;
if ( ! V_92 -> V_89 )
F_103 ( V_107 , V_92 ) ;
else
F_104 ( V_98 , V_92 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_185 = 1 ;
int V_18 ;
V_18 = F_169 ( V_98 , V_92 , & V_6 , & V_185 , true ) ;
ASSERT ( ! V_18 ) ;
V_40 = V_6 ;
F_166 ( V_98 , V_92 , V_6 , 1 ) ;
if ( V_92 -> V_89 == 0 )
F_175 ( V_98 , V_92 ) ;
}
V_111:
F_17 ( & V_98 -> V_103 ) ;
return V_40 ;
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
struct V_38 * V_39 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_39 , V_5 ,
V_45 , 0 ) ;
}
int F_240 ( struct V_7 * V_8 , struct V_2 * V_3 )
{
struct V_97 * V_98 = V_3 -> V_277 ;
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
goto V_111;
if ( V_280 != F_18 ( V_1 ) -> V_83 )
goto V_283;
V_18 = F_105 ( V_3 , V_1 , V_98 , V_5 , 0 ) ;
if ( V_18 < 0 )
F_81 ( V_8 ,
L_17 ,
V_3 -> V_284 . V_19 ) ;
V_283:
F_11 ( V_1 ) ;
V_111:
F_49 ( V_5 ) ;
return V_18 ;
}
int F_242 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_97 * V_98 = V_3 -> V_277 ;
int V_18 ;
struct V_65 V_66 ;
bool V_285 = true ;
if ( ! F_214 ( V_8 , V_282 ) )
return 0 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_18 = F_140 ( V_3 , V_1 , V_98 , NULL , & V_66 , V_39 ) ;
if ( ! V_18 ) {
V_285 = false ;
V_18 = F_139 ( V_3 , V_39 , & V_66 , V_5 ) ;
}
if ( V_18 ) {
if ( V_285 )
F_243 ( F_18 ( V_1 ) ,
V_1 -> V_139 ) ;
#ifdef F_138
F_81 ( V_8 ,
L_18 ,
V_3 -> V_284 . V_19 ) ;
#endif
}
return V_18 ;
}
int F_244 ( struct V_28 * V_265 ,
T_1 V_6 , T_1 V_89 , bool V_90 )
{
struct V_97 * V_98 = V_265 -> V_117 ;
struct V_95 * V_169 = NULL , * V_186 ;
void * V_286 = NULL ;
T_1 V_205 ;
int V_18 ;
V_102:
if ( ! V_169 ) {
V_169 = F_110 ( V_107 , V_63 ) ;
if ( ! V_169 )
return - V_54 ;
}
if ( ! V_90 ) {
F_15 ( & V_98 -> V_103 ) ;
V_169 -> V_6 = V_6 ;
V_169 -> V_89 = V_89 ;
V_169 -> V_193 = 0 ;
V_18 = F_104 ( V_98 , V_169 ) ;
F_17 ( & V_98 -> V_103 ) ;
if ( V_18 )
F_103 ( V_107 , V_169 ) ;
return V_18 ;
}
if ( ! V_286 ) {
V_286 = F_57 ( V_70 , V_63 ) ;
if ( ! V_286 ) {
F_103 ( V_107 , V_169 ) ;
return - V_54 ;
}
}
F_15 ( & V_98 -> V_103 ) ;
V_186 = F_157 ( V_98 , F_151 ( V_98 , V_6 ) ,
1 , 0 ) ;
if ( ! V_186 ) {
V_169 -> V_90 = V_286 ;
V_286 = NULL ;
F_173 ( V_98 , V_169 , V_6 ) ;
V_186 = V_169 ;
V_169 = NULL ;
}
V_205 = F_177 ( V_98 , V_186 , V_6 , V_89 ) ;
V_89 -= V_205 ;
V_6 += V_205 ;
F_17 ( & V_98 -> V_103 ) ;
if ( V_89 )
goto V_102;
if ( V_169 )
F_103 ( V_107 , V_169 ) ;
if ( V_286 )
F_61 ( V_286 ) ;
return 0 ;
}
int F_245 ( struct V_28 * V_265 ,
T_1 V_6 , T_1 V_89 )
{
struct V_97 * V_98 = V_265 -> V_117 ;
struct V_95 * V_169 ;
int V_18 = 0 ;
F_15 ( & V_98 -> V_103 ) ;
V_169 = F_157 ( V_98 , V_6 , 0 , 0 ) ;
if ( ! V_169 ) {
V_169 = F_157 ( V_98 , F_151 ( V_98 , V_6 ) ,
1 , 0 ) ;
if ( ! V_169 )
goto V_111;
}
V_287:
if ( V_169 -> V_90 ) {
T_1 V_288 , V_289 ;
struct V_100 * V_101 ;
struct V_95 * V_86 ;
V_288 = V_6 ;
V_289 = V_98 -> V_163 ;
V_18 = F_169 ( V_98 , V_169 , & V_288 , & V_289 , false ) ;
if ( ! V_18 ) {
if ( V_288 == V_6 ) {
V_18 = 1 ;
goto V_111;
} else if ( V_288 > V_6 &&
V_6 + V_89 > V_288 ) {
V_18 = 1 ;
goto V_111;
}
}
V_101 = F_158 ( & V_169 -> V_105 ) ;
while ( V_101 ) {
V_86 = F_101 ( V_101 , struct V_95 ,
V_105 ) ;
if ( V_86 -> V_6 + V_86 -> V_89 < V_6 )
break;
if ( V_6 + V_89 < V_86 -> V_6 ) {
V_101 = F_158 ( & V_86 -> V_105 ) ;
continue;
}
V_169 = V_86 ;
goto V_287;
}
V_101 = F_100 ( & V_169 -> V_105 ) ;
while ( V_101 ) {
V_86 = F_101 ( V_101 , struct V_95 ,
V_105 ) ;
if ( V_6 + V_89 < V_86 -> V_6 )
break;
if ( V_86 -> V_6 + V_86 -> V_89 < V_6 ) {
V_101 = F_100 ( & V_86 -> V_105 ) ;
continue;
}
V_169 = V_86 ;
goto V_287;
}
V_18 = 0 ;
goto V_111;
}
if ( V_169 -> V_6 == V_6 ) {
V_18 = 1 ;
goto V_111;
}
if ( V_6 > V_169 -> V_6 && V_6 < V_169 -> V_6 + V_169 -> V_89 )
V_18 = 1 ;
V_111:
F_17 ( & V_98 -> V_103 ) ;
return V_18 ;
}
