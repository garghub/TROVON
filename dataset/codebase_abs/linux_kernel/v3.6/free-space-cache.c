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
F_13 ( V_1 -> V_24 ) & ~ V_25 ) ;
return V_1 ;
}
struct V_1 * F_14 ( struct V_2 * V_3 ,
struct V_26
* V_27 , struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
T_2 V_28 = V_29 | V_30 ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_1 )
V_1 = F_16 ( V_27 -> V_1 ) ;
F_17 ( & V_27 -> V_31 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 ,
V_27 -> V_8 . V_17 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_27 -> V_31 ) ;
if ( ! ( ( F_18 ( V_1 ) -> V_28 & V_28 ) == V_28 ) ) {
F_19 ( V_32 L_1 ) ;
F_18 ( V_1 ) -> V_28 |= V_29 |
V_30 ;
V_27 -> V_33 = V_34 ;
}
if ( ! V_27 -> V_35 ) {
V_27 -> V_1 = F_16 ( V_1 ) ;
V_27 -> V_35 = 1 ;
}
F_17 ( & V_27 -> V_31 ) ;
return V_1 ;
}
int F_20 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 , T_1 V_38 , T_1 V_6 )
{
struct V_7 V_8 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_39 * V_40 ;
struct V_14 * V_15 ;
T_1 V_28 = V_41 | V_42 ;
int V_16 ;
V_16 = F_21 ( V_37 , V_3 , V_5 , V_38 ) ;
if ( V_16 )
return V_16 ;
if ( V_38 != V_43 )
V_28 |= V_29 | V_30 ;
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
F_30 ( V_15 , V_40 , V_28 ) ;
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
struct V_26 * V_27 ,
struct V_4 * V_5 )
{
int V_16 ;
T_1 V_38 ;
V_16 = F_38 ( V_3 , & V_38 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_20 ( V_3 , V_37 , V_5 , V_38 ,
V_27 -> V_8 . V_17 ) ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_46 * V_47 ;
T_1 V_48 ;
T_3 V_49 ;
int V_16 = 0 ;
V_47 = V_37 -> V_50 ;
V_37 -> V_50 = & V_3 -> V_22 -> V_51 ;
V_48 = F_40 ( V_3 , 1 ) +
F_41 ( V_3 , 1 ) ;
F_15 ( & V_37 -> V_50 -> V_31 ) ;
if ( V_37 -> V_50 -> V_52 < V_48 ) {
F_17 ( & V_37 -> V_50 -> V_31 ) ;
V_37 -> V_50 = V_47 ;
return - V_53 ;
}
F_17 ( & V_37 -> V_50 -> V_31 ) ;
V_49 = F_42 ( V_1 ) ;
F_43 ( V_1 , 0 ) ;
F_44 ( V_1 , V_49 , 0 ) ;
V_16 = F_45 ( V_37 , V_3 , V_1 ,
0 , V_54 ) ;
if ( V_16 ) {
V_37 -> V_50 = V_47 ;
F_46 ( V_37 , V_3 , V_16 ) ;
return V_16 ;
}
V_16 = F_47 ( V_37 , V_3 , V_1 ) ;
if ( V_16 )
F_46 ( V_37 , V_3 , V_16 ) ;
V_37 -> V_50 = V_47 ;
return V_16 ;
}
static int F_48 ( struct V_1 * V_1 )
{
struct V_55 * V_56 ;
unsigned long V_57 ;
V_56 = F_49 ( sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
F_50 ( V_56 , V_1 -> V_24 ) ;
V_57 = ( F_42 ( V_1 ) - 1 ) >> V_60 ;
F_51 ( V_1 -> V_24 , V_56 , NULL , 0 , V_57 ) ;
F_52 ( V_56 ) ;
return 0 ;
}
static int F_53 ( struct V_61 * V_61 , struct V_1 * V_1 ,
struct V_2 * V_3 )
{
memset ( V_61 , 0 , sizeof( struct V_61 ) ) ;
V_61 -> V_62 = ( F_42 ( V_1 ) + V_63 - 1 ) >>
V_60 ;
V_61 -> V_64 = F_49 ( sizeof( struct V_65 * ) * V_61 -> V_62 ,
V_58 ) ;
if ( ! V_61 -> V_64 )
return - V_59 ;
V_61 -> V_3 = V_3 ;
if ( F_54 ( V_1 ) != V_43 )
V_61 -> V_66 = 1 ;
return 0 ;
}
static void F_55 ( struct V_61 * V_61 )
{
F_52 ( V_61 -> V_64 ) ;
}
static void F_56 ( struct V_61 * V_61 )
{
if ( V_61 -> V_67 ) {
F_57 ( V_61 -> V_65 ) ;
V_61 -> V_67 = NULL ;
V_61 -> V_68 = NULL ;
}
}
static void F_58 ( struct V_61 * V_61 , int V_69 )
{
F_59 ( V_61 -> V_67 ) ;
F_60 ( V_61 -> V_70 >= V_61 -> V_62 ) ;
V_61 -> V_65 = V_61 -> V_64 [ V_61 -> V_70 ++ ] ;
V_61 -> V_67 = F_61 ( V_61 -> V_65 ) ;
V_61 -> V_68 = V_61 -> V_67 ;
V_61 -> V_71 = V_63 ;
if ( V_69 )
memset ( V_61 -> V_67 , 0 , V_63 ) ;
}
static void F_62 ( struct V_61 * V_61 )
{
int V_72 ;
F_56 ( V_61 ) ;
for ( V_72 = 0 ; V_72 < V_61 -> V_62 ; V_72 ++ ) {
if ( V_61 -> V_64 [ V_72 ] ) {
F_63 ( V_61 -> V_64 [ V_72 ] ) ;
F_64 ( V_61 -> V_64 [ V_72 ] ) ;
F_65 ( V_61 -> V_64 [ V_72 ] ) ;
}
}
}
static int F_66 ( struct V_61 * V_61 , struct V_1 * V_1 ,
int V_73 )
{
struct V_65 * V_65 ;
T_4 V_74 = F_67 ( V_1 -> V_24 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_61 -> V_62 ; V_72 ++ ) {
V_65 = F_68 ( V_1 -> V_24 , V_72 , V_74 ) ;
if ( ! V_65 ) {
F_62 ( V_61 ) ;
return - V_59 ;
}
V_61 -> V_64 [ V_72 ] = V_65 ;
if ( V_73 && ! F_69 ( V_65 ) ) {
F_70 ( NULL , V_65 ) ;
F_71 ( V_65 ) ;
if ( ! F_69 ( V_65 ) ) {
F_19 ( V_75 L_2
L_3 ) ;
F_62 ( V_61 ) ;
return - V_76 ;
}
}
}
for ( V_72 = 0 ; V_72 < V_61 -> V_62 ; V_72 ++ ) {
F_72 ( V_61 -> V_64 [ V_72 ] ) ;
F_73 ( V_61 -> V_64 [ V_72 ] ) ;
}
return 0 ;
}
static void F_74 ( struct V_61 * V_61 , T_1 V_77 )
{
T_5 * V_78 ;
F_58 ( V_61 , 1 ) ;
if ( V_61 -> V_66 ) {
V_61 -> V_67 += ( sizeof( T_2 ) * V_61 -> V_62 ) ;
V_61 -> V_71 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_61 -> V_62 ) ;
} else {
V_61 -> V_67 += sizeof( T_1 ) ;
V_61 -> V_71 -= sizeof( T_1 ) * 2 ;
}
V_78 = V_61 -> V_67 ;
* V_78 = F_75 ( V_77 ) ;
V_61 -> V_67 += sizeof( T_1 ) ;
}
static int F_76 ( struct V_61 * V_61 , T_1 V_77 )
{
T_5 * V_79 ;
if ( V_61 -> V_66 ) {
V_61 -> V_67 += sizeof( T_2 ) * V_61 -> V_62 ;
V_61 -> V_71 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_61 -> V_62 ) ;
} else {
V_61 -> V_67 += sizeof( T_1 ) ;
V_61 -> V_71 -= sizeof( T_1 ) * 2 ;
}
V_79 = V_61 -> V_67 ;
if ( F_77 ( * V_79 ) != V_77 ) {
F_78 ( V_75 L_4
L_5 , * V_79 ,
V_77 ) ;
F_56 ( V_61 ) ;
return - V_76 ;
}
V_61 -> V_67 += sizeof( T_1 ) ;
return 0 ;
}
static void F_79 ( struct V_61 * V_61 , int V_70 )
{
T_2 * V_80 ;
T_2 V_81 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_61 -> V_66 ) {
F_56 ( V_61 ) ;
return;
}
if ( V_70 == 0 )
V_6 = sizeof( T_2 ) * V_61 -> V_62 ;
V_81 = F_80 ( V_61 -> V_3 , V_61 -> V_68 + V_6 , V_81 ,
V_63 - V_6 ) ;
F_81 ( V_81 , ( char * ) & V_81 ) ;
F_56 ( V_61 ) ;
V_80 = F_61 ( V_61 -> V_64 [ 0 ] ) ;
V_80 += V_70 ;
* V_80 = V_81 ;
F_57 ( V_61 -> V_64 [ 0 ] ) ;
}
static int F_82 ( struct V_61 * V_61 , int V_70 )
{
T_2 * V_80 , V_78 ;
T_2 V_81 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_61 -> V_66 ) {
F_58 ( V_61 , 0 ) ;
return 0 ;
}
if ( V_70 == 0 )
V_6 = sizeof( T_2 ) * V_61 -> V_62 ;
V_80 = F_61 ( V_61 -> V_64 [ 0 ] ) ;
V_80 += V_70 ;
V_78 = * V_80 ;
F_57 ( V_61 -> V_64 [ 0 ] ) ;
F_58 ( V_61 , 0 ) ;
V_81 = F_80 ( V_61 -> V_3 , V_61 -> V_68 + V_6 , V_81 ,
V_63 - V_6 ) ;
F_81 ( V_81 , ( char * ) & V_81 ) ;
if ( V_78 != V_81 ) {
F_78 ( V_75 L_6
L_3 ) ;
F_56 ( V_61 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_83 ( struct V_61 * V_61 , T_1 V_6 , T_1 V_82 ,
void * V_83 )
{
struct V_84 * V_85 ;
if ( ! V_61 -> V_67 )
return - V_53 ;
V_85 = V_61 -> V_67 ;
V_85 -> V_6 = F_75 ( V_6 ) ;
V_85 -> V_82 = F_75 ( V_82 ) ;
V_85 -> type = ( V_83 ) ? V_86 :
V_87 ;
V_61 -> V_67 += sizeof( struct V_84 ) ;
V_61 -> V_71 -= sizeof( struct V_84 ) ;
if ( V_61 -> V_71 >= sizeof( struct V_84 ) )
return 0 ;
F_79 ( V_61 , V_61 -> V_70 - 1 ) ;
if ( V_61 -> V_70 >= V_61 -> V_62 )
return 0 ;
F_58 ( V_61 , 1 ) ;
return 0 ;
}
static int F_84 ( struct V_61 * V_61 , void * V_83 )
{
if ( ! V_61 -> V_67 )
return - V_53 ;
if ( V_61 -> V_67 != V_61 -> V_68 ) {
F_79 ( V_61 , V_61 -> V_70 - 1 ) ;
if ( V_61 -> V_70 >= V_61 -> V_62 )
return - V_53 ;
F_58 ( V_61 , 0 ) ;
}
memcpy ( V_61 -> V_67 , V_83 , V_63 ) ;
F_79 ( V_61 , V_61 -> V_70 - 1 ) ;
if ( V_61 -> V_70 < V_61 -> V_62 )
F_58 ( V_61 , 0 ) ;
return 0 ;
}
static void F_85 ( struct V_61 * V_61 )
{
if ( V_61 -> V_67 != V_61 -> V_68 )
F_79 ( V_61 , V_61 -> V_70 - 1 ) ;
else
F_56 ( V_61 ) ;
while ( V_61 -> V_70 < V_61 -> V_62 ) {
F_58 ( V_61 , 1 ) ;
F_79 ( V_61 , V_61 -> V_70 - 1 ) ;
}
}
static int F_86 ( struct V_61 * V_61 ,
struct V_88 * V_85 , T_6 * type )
{
struct V_84 * V_89 ;
int V_16 ;
if ( ! V_61 -> V_67 ) {
V_16 = F_82 ( V_61 , V_61 -> V_70 ) ;
if ( V_16 )
return V_16 ;
}
V_89 = V_61 -> V_67 ;
V_85 -> V_6 = F_77 ( V_89 -> V_6 ) ;
V_85 -> V_82 = F_77 ( V_89 -> V_82 ) ;
* type = V_89 -> type ;
V_61 -> V_67 += sizeof( struct V_84 ) ;
V_61 -> V_71 -= sizeof( struct V_84 ) ;
if ( V_61 -> V_71 >= sizeof( struct V_84 ) )
return 0 ;
F_56 ( V_61 ) ;
return 0 ;
}
static int F_87 ( struct V_61 * V_61 ,
struct V_88 * V_85 )
{
int V_16 ;
V_16 = F_82 ( V_61 , V_61 -> V_70 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_85 -> V_83 , V_61 -> V_67 , V_63 ) ;
F_56 ( V_61 ) ;
return 0 ;
}
static void F_88 ( struct V_90 * V_91 )
{
struct V_88 * V_89 , * V_92 = NULL ;
struct V_93 * V_94 ;
V_95:
F_15 ( & V_91 -> V_96 ) ;
for ( V_94 = F_89 ( & V_91 -> V_97 ) ; V_94 ; V_94 = F_90 ( V_94 ) ) {
V_89 = F_91 ( V_94 , struct V_88 , V_98 ) ;
if ( ! V_92 )
goto V_99;
if ( V_89 -> V_83 || V_92 -> V_83 )
goto V_99;
if ( V_92 -> V_6 + V_92 -> V_82 == V_89 -> V_6 ) {
F_92 ( V_91 , V_92 ) ;
F_92 ( V_91 , V_89 ) ;
V_92 -> V_82 += V_89 -> V_82 ;
F_93 ( V_100 , V_89 ) ;
F_94 ( V_91 , V_92 ) ;
V_92 = NULL ;
F_17 ( & V_91 -> V_96 ) ;
goto V_95;
}
V_99:
V_92 = V_89 ;
}
F_17 ( & V_91 -> V_96 ) ;
}
int F_95 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_90 * V_91 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_61 V_61 ;
struct V_7 V_8 ;
struct V_88 * V_89 , * V_94 ;
struct V_101 V_102 ;
T_1 V_103 ;
T_1 V_104 ;
T_1 V_77 ;
T_6 type ;
int V_16 = 0 ;
F_96 ( & V_102 ) ;
if ( ! F_42 ( V_1 ) )
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
V_103 = F_97 ( V_15 , V_13 ) ;
V_104 = F_98 ( V_15 , V_13 ) ;
V_77 = F_99 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( F_18 ( V_1 ) -> V_77 != V_77 ) {
F_19 ( V_75 L_7
L_8 ,
( unsigned long long ) F_18 ( V_1 ) -> V_77 ,
( unsigned long long ) V_77 ) ;
return 0 ;
}
if ( ! V_103 )
return 0 ;
V_16 = F_53 ( & V_61 , V_1 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_48 ( V_1 ) ;
if ( V_16 )
goto V_105;
V_16 = F_66 ( & V_61 , V_1 , 1 ) ;
if ( V_16 )
goto V_105;
V_16 = F_82 ( & V_61 , 0 ) ;
if ( V_16 )
goto V_106;
V_16 = F_76 ( & V_61 , V_77 ) ;
if ( V_16 )
goto V_106;
while ( V_103 ) {
V_89 = F_100 ( V_100 ,
V_58 ) ;
if ( ! V_89 )
goto V_106;
V_16 = F_86 ( & V_61 , V_89 , & type ) ;
if ( V_16 ) {
F_93 ( V_100 , V_89 ) ;
goto V_106;
}
if ( ! V_89 -> V_82 ) {
F_93 ( V_100 , V_89 ) ;
goto V_106;
}
if ( type == V_87 ) {
F_15 ( & V_91 -> V_96 ) ;
V_16 = F_94 ( V_91 , V_89 ) ;
F_17 ( & V_91 -> V_96 ) ;
if ( V_16 ) {
F_19 ( V_75 L_9
L_10 ) ;
F_93 ( V_100 , V_89 ) ;
goto V_106;
}
} else {
F_60 ( ! V_104 ) ;
V_104 -- ;
V_89 -> V_83 = F_49 ( V_63 , V_58 ) ;
if ( ! V_89 -> V_83 ) {
F_93 (
V_100 , V_89 ) ;
goto V_106;
}
F_15 ( & V_91 -> V_96 ) ;
V_16 = F_94 ( V_91 , V_89 ) ;
V_91 -> V_107 ++ ;
V_91 -> V_108 -> V_109 ( V_91 ) ;
F_17 ( & V_91 -> V_96 ) ;
if ( V_16 ) {
F_19 ( V_75 L_9
L_10 ) ;
F_93 ( V_100 , V_89 ) ;
goto V_106;
}
F_101 ( & V_89 -> V_110 , & V_102 ) ;
}
V_103 -- ;
}
F_56 ( & V_61 ) ;
F_102 (e, n, &bitmaps, list) {
F_103 ( & V_89 -> V_110 ) ;
V_16 = F_87 ( & V_61 , V_89 ) ;
if ( V_16 )
goto V_106;
}
F_62 ( & V_61 ) ;
F_88 ( V_91 ) ;
V_16 = 1 ;
V_105:
F_55 ( & V_61 ) ;
return V_16 ;
V_106:
F_62 ( & V_61 ) ;
F_104 ( V_91 ) ;
goto V_105;
}
int F_105 ( struct V_111 * V_22 ,
struct V_26 * V_27 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_2 * V_3 = V_22 -> V_113 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 = 0 ;
bool V_114 ;
T_1 V_115 = F_106 ( & V_27 -> V_116 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_33 != V_117 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_5 = F_107 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_118 = 1 ;
V_5 -> V_119 = 1 ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_108 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_33 != V_117 ) {
F_17 ( & V_27 -> V_31 ) ;
F_108 ( V_5 ) ;
goto V_105;
}
F_17 ( & V_27 -> V_31 ) ;
V_16 = F_95 ( V_22 -> V_113 , V_1 , V_91 ,
V_5 , V_27 -> V_8 . V_17 ) ;
F_108 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_105;
F_15 ( & V_91 -> V_96 ) ;
V_114 = ( V_91 -> V_120 == ( V_27 -> V_8 . V_6 - V_115 -
V_27 -> V_121 ) ) ;
F_17 ( & V_91 -> V_96 ) ;
if ( ! V_114 ) {
F_104 ( V_91 ) ;
F_19 ( V_75 L_11
L_12 , V_27 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_105:
if ( V_16 < 0 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_33 = V_34 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
F_19 ( V_75 L_13
L_14 , V_27 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
int F_109 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_90 * V_91 ,
struct V_26 * V_27 ,
struct V_36 * V_37 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_93 * V_122 ;
struct V_101 * V_123 , * V_94 ;
struct V_124 * V_125 = NULL ;
struct V_126 * V_127 = NULL ;
struct V_128 * V_129 = NULL ;
struct V_61 V_61 ;
struct V_101 V_130 ;
struct V_7 V_8 ;
T_1 V_131 , V_132 , V_133 , V_134 ;
int V_135 = 0 ;
int V_102 = 0 ;
int V_16 ;
int V_136 = - 1 ;
F_96 ( & V_130 ) ;
if ( ! F_42 ( V_1 ) )
return - 1 ;
V_16 = F_53 ( & V_61 , V_1 , V_3 ) ;
if ( V_16 )
return - 1 ;
if ( V_27 && ! F_110 ( & V_27 -> V_137 ) )
V_127 = F_111 ( V_27 -> V_137 . V_99 ,
struct V_126 ,
V_138 ) ;
F_66 ( & V_61 , V_1 , 0 ) ;
F_112 ( & F_18 ( V_1 ) -> V_139 , 0 , F_42 ( V_1 ) - 1 ,
0 , & V_125 ) ;
V_122 = F_89 ( & V_91 -> V_97 ) ;
if ( ! V_122 && V_127 ) {
V_122 = F_89 ( & V_127 -> V_3 ) ;
V_127 = NULL ;
}
if ( V_61 . V_66 &&
( V_61 . V_62 * sizeof( T_2 ) ) >= V_63 ) {
F_59 ( 1 ) ;
goto V_140;
}
F_74 ( & V_61 , V_37 -> V_44 ) ;
while ( V_122 ) {
struct V_88 * V_89 ;
V_89 = F_91 ( V_122 , struct V_88 , V_98 ) ;
V_135 ++ ;
V_16 = F_83 ( & V_61 , V_89 -> V_6 , V_89 -> V_82 ,
V_89 -> V_83 ) ;
if ( V_16 )
goto V_140;
if ( V_89 -> V_83 ) {
F_101 ( & V_89 -> V_110 , & V_130 ) ;
V_102 ++ ;
}
V_122 = F_90 ( V_122 ) ;
if ( ! V_122 && V_127 ) {
V_122 = F_89 ( & V_127 -> V_3 ) ;
V_127 = NULL ;
}
}
V_129 = V_3 -> V_22 -> V_141 ;
if ( V_27 )
V_131 = V_27 -> V_8 . V_17 ;
while ( V_27 && ( V_131 < V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 ) ) {
V_16 = F_113 ( V_129 , V_131 ,
& V_132 , & V_133 ,
V_142 ) ;
if ( V_16 ) {
V_16 = 0 ;
break;
}
if ( V_132 >= V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 )
break;
V_132 = F_114 ( V_132 , V_131 ) ;
V_133 = F_115 ( V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 , V_133 + 1 ) ;
V_134 = V_133 - V_132 ;
V_135 ++ ;
V_16 = F_83 ( & V_61 , V_132 , V_134 , NULL ) ;
if ( V_16 )
goto V_140;
V_131 = V_133 ;
}
F_116 (pos, n, &bitmap_list) {
struct V_88 * V_85 =
F_111 ( V_123 , struct V_88 , V_110 ) ;
V_16 = F_84 ( & V_61 , V_85 -> V_83 ) ;
if ( V_16 )
goto V_140;
F_103 ( & V_85 -> V_110 ) ;
}
F_85 ( & V_61 ) ;
V_16 = F_117 ( V_3 , V_1 , V_61 . V_64 , V_61 . V_62 ,
0 , F_42 ( V_1 ) , & V_125 ) ;
F_62 ( & V_61 ) ;
F_118 ( & F_18 ( V_1 ) -> V_139 , 0 ,
F_42 ( V_1 ) - 1 , & V_125 , V_58 ) ;
if ( V_16 )
goto V_105;
F_119 ( V_1 , 0 , ( T_1 ) - 1 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_37 , V_3 , & V_8 , V_5 , 0 , 1 ) ;
if ( V_16 < 0 ) {
F_120 ( & F_18 ( V_1 ) -> V_139 , 0 , V_1 -> V_143 - 1 ,
V_142 | V_144 , 0 , 0 , NULL ,
V_58 ) ;
goto V_105;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_145 ;
F_60 ( ! V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_121 ( V_15 , & V_145 , V_5 -> V_21 [ 0 ] ) ;
if ( V_145 . V_17 != V_18 ||
V_145 . V_6 != V_6 ) {
F_120 ( & F_18 ( V_1 ) -> V_139 , 0 ,
V_1 -> V_143 - 1 ,
V_142 | V_144 , 0 , 0 ,
NULL , V_58 ) ;
F_4 ( V_5 ) ;
goto V_105;
}
}
F_18 ( V_1 ) -> V_77 = V_37 -> V_44 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_122 ( V_15 , V_13 , V_135 ) ;
F_123 ( V_15 , V_13 , V_102 ) ;
F_124 ( V_15 , V_13 , V_37 -> V_44 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
V_136 = 0 ;
V_105:
F_55 ( & V_61 ) ;
if ( V_136 ) {
F_125 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_77 = 0 ;
}
F_47 ( V_37 , V_3 , V_1 ) ;
return V_136 ;
V_140:
F_116 (pos, n, &bitmap_list) {
struct V_88 * V_85 =
F_111 ( V_123 , struct V_88 , V_110 ) ;
F_103 ( & V_85 -> V_110 ) ;
}
F_62 ( & V_61 ) ;
F_118 ( & F_18 ( V_1 ) -> V_139 , 0 ,
F_42 ( V_1 ) - 1 , & V_125 , V_58 ) ;
goto V_105;
}
int F_126 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_113 ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_33 < V_146 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_109 ( V_3 , V_1 , V_91 , V_27 , V_37 ,
V_5 , V_27 -> V_8 . V_17 ) ;
if ( V_16 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_33 = V_147 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
#ifdef F_127
F_19 ( V_75 L_15
L_14 , V_27 -> V_8 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_128 ( T_1 V_148 , T_2 V_149 ,
T_1 V_6 )
{
F_60 ( V_6 < V_148 ) ;
V_6 -= V_148 ;
return ( unsigned long ) ( F_129 ( V_6 , V_149 ) ) ;
}
static inline unsigned long F_130 ( T_1 V_82 , T_2 V_149 )
{
return ( unsigned long ) ( F_129 ( V_82 , V_149 ) ) ;
}
static inline T_1 F_131 ( struct V_90 * V_91 ,
T_1 V_6 )
{
T_1 V_148 ;
T_1 V_150 ;
V_150 = V_151 * V_91 -> V_149 ;
V_148 = V_6 - V_91 -> V_131 ;
V_148 = F_132 ( V_148 , V_150 ) ;
V_148 *= V_150 ;
V_148 += V_91 -> V_131 ;
return V_148 ;
}
static int F_133 ( struct V_152 * V_3 , T_1 V_6 ,
struct V_93 * V_122 , int V_83 )
{
struct V_93 * * V_153 = & V_3 -> V_93 ;
struct V_93 * V_154 = NULL ;
struct V_88 * V_155 ;
while ( * V_153 ) {
V_154 = * V_153 ;
V_155 = F_91 ( V_154 , struct V_88 , V_98 ) ;
if ( V_6 < V_155 -> V_6 ) {
V_153 = & ( * V_153 ) -> V_156 ;
} else if ( V_6 > V_155 -> V_6 ) {
V_153 = & ( * V_153 ) -> V_157 ;
} else {
if ( V_83 ) {
if ( V_155 -> V_83 ) {
F_134 ( 1 ) ;
return - V_158 ;
}
V_153 = & ( * V_153 ) -> V_157 ;
} else {
if ( ! V_155 -> V_83 ) {
F_134 ( 1 ) ;
return - V_158 ;
}
V_153 = & ( * V_153 ) -> V_156 ;
}
}
}
F_135 ( V_122 , V_154 , V_153 ) ;
F_136 ( V_122 , V_3 ) ;
return 0 ;
}
static struct V_88 *
F_137 ( struct V_90 * V_91 ,
T_1 V_6 , int V_159 , int V_160 )
{
struct V_93 * V_94 = V_91 -> V_97 . V_93 ;
struct V_88 * V_85 , * V_92 = NULL ;
while ( 1 ) {
if ( ! V_94 ) {
V_85 = NULL ;
break;
}
V_85 = F_91 ( V_94 , struct V_88 , V_98 ) ;
V_92 = V_85 ;
if ( V_6 < V_85 -> V_6 )
V_94 = V_94 -> V_156 ;
else if ( V_6 > V_85 -> V_6 )
V_94 = V_94 -> V_157 ;
else
break;
}
if ( V_159 ) {
if ( ! V_85 )
return NULL ;
if ( V_85 -> V_83 )
return V_85 ;
V_94 = F_90 ( V_94 ) ;
if ( ! V_94 )
return NULL ;
V_85 = F_91 ( V_94 , struct V_88 , V_98 ) ;
if ( V_85 -> V_6 != V_6 )
return NULL ;
F_59 ( ! V_85 -> V_83 ) ;
return V_85 ;
} else if ( V_85 ) {
if ( V_85 -> V_83 ) {
V_94 = & V_85 -> V_98 ;
while ( 1 ) {
V_94 = F_138 ( V_94 ) ;
if ( ! V_94 )
break;
V_92 = F_91 ( V_94 , struct V_88 ,
V_98 ) ;
if ( ! V_92 -> V_83 ) {
if ( V_92 -> V_6 + V_92 -> V_82 > V_6 )
V_85 = V_92 ;
break;
}
}
}
return V_85 ;
}
if ( ! V_92 )
return NULL ;
V_85 = V_92 ;
if ( V_85 -> V_6 > V_6 ) {
V_94 = F_138 ( & V_85 -> V_98 ) ;
if ( V_94 ) {
V_85 = F_91 ( V_94 , struct V_88 ,
V_98 ) ;
F_60 ( V_85 -> V_6 > V_6 ) ;
} else {
if ( V_160 )
return V_85 ;
else
return NULL ;
}
}
if ( V_85 -> V_83 ) {
V_94 = & V_85 -> V_98 ;
while ( 1 ) {
V_94 = F_138 ( V_94 ) ;
if ( ! V_94 )
break;
V_92 = F_91 ( V_94 , struct V_88 ,
V_98 ) ;
if ( ! V_92 -> V_83 ) {
if ( V_92 -> V_6 + V_92 -> V_82 > V_6 )
return V_92 ;
break;
}
}
if ( V_85 -> V_6 + V_151 * V_91 -> V_149 > V_6 )
return V_85 ;
} else if ( V_85 -> V_6 + V_85 -> V_82 > V_6 )
return V_85 ;
if ( ! V_160 )
return NULL ;
while ( 1 ) {
if ( V_85 -> V_83 ) {
if ( V_85 -> V_6 + V_151 *
V_91 -> V_149 > V_6 )
break;
} else {
if ( V_85 -> V_6 + V_85 -> V_82 > V_6 )
break;
}
V_94 = F_90 ( & V_85 -> V_98 ) ;
if ( ! V_94 )
return NULL ;
V_85 = F_91 ( V_94 , struct V_88 , V_98 ) ;
}
return V_85 ;
}
static inline void
F_139 ( struct V_90 * V_91 ,
struct V_88 * V_155 )
{
F_140 ( & V_155 -> V_98 , & V_91 -> V_97 ) ;
V_91 -> V_161 -- ;
}
static void F_92 ( struct V_90 * V_91 ,
struct V_88 * V_155 )
{
F_139 ( V_91 , V_155 ) ;
V_91 -> V_120 -= V_155 -> V_82 ;
}
static int F_94 ( struct V_90 * V_91 ,
struct V_88 * V_155 )
{
int V_16 = 0 ;
F_60 ( ! V_155 -> V_83 && ! V_155 -> V_82 ) ;
V_16 = F_133 ( & V_91 -> V_97 , V_155 -> V_6 ,
& V_155 -> V_98 , ( V_155 -> V_83 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_91 -> V_120 += V_155 -> V_82 ;
V_91 -> V_161 ++ ;
return V_16 ;
}
static void F_141 ( struct V_90 * V_91 )
{
struct V_26 * V_27 = V_91 -> V_162 ;
T_1 V_163 ;
T_1 V_164 ;
T_1 V_165 ;
T_1 V_71 = V_27 -> V_8 . V_6 ;
T_1 V_166 = V_151 * V_27 -> V_167 ;
int V_168 = F_132 ( V_71 + V_166 - 1 , V_166 ) ;
F_60 ( V_91 -> V_107 > V_168 ) ;
if ( V_71 < 1024 * 1024 * 1024 )
V_163 = V_169 ;
else
V_163 = V_169 *
F_132 ( V_71 , 1024 * 1024 * 1024 ) ;
V_164 = ( V_91 -> V_107 + 1 ) * V_63 ;
if ( V_164 >= V_163 ) {
V_91 -> V_170 = 0 ;
return;
}
V_165 = V_163 - V_164 ;
V_165 = F_142 ( T_1 , V_165 , F_132 ( V_163 , 2 ) ) ;
V_91 -> V_170 =
F_132 ( V_165 , ( sizeof( struct V_88 ) ) ) ;
}
static inline void F_143 ( struct V_90 * V_91 ,
struct V_88 * V_155 ,
T_1 V_6 , T_1 V_82 )
{
unsigned long V_131 , V_171 ;
V_131 = F_128 ( V_155 -> V_6 , V_91 -> V_149 , V_6 ) ;
V_171 = F_130 ( V_82 , V_91 -> V_149 ) ;
F_60 ( V_131 + V_171 > V_151 ) ;
F_144 ( V_155 -> V_83 , V_131 , V_171 ) ;
V_155 -> V_82 -= V_82 ;
}
static void F_145 ( struct V_90 * V_91 ,
struct V_88 * V_155 , T_1 V_6 ,
T_1 V_82 )
{
F_143 ( V_91 , V_155 , V_6 , V_82 ) ;
V_91 -> V_120 -= V_82 ;
}
static void F_146 ( struct V_90 * V_91 ,
struct V_88 * V_155 , T_1 V_6 ,
T_1 V_82 )
{
unsigned long V_131 , V_171 ;
V_131 = F_128 ( V_155 -> V_6 , V_91 -> V_149 , V_6 ) ;
V_171 = F_130 ( V_82 , V_91 -> V_149 ) ;
F_60 ( V_131 + V_171 > V_151 ) ;
F_147 ( V_155 -> V_83 , V_131 , V_171 ) ;
V_155 -> V_82 += V_82 ;
V_91 -> V_120 += V_82 ;
}
static int F_148 ( struct V_90 * V_91 ,
struct V_88 * V_172 , T_1 * V_6 ,
T_1 * V_82 )
{
unsigned long V_173 = 0 ;
unsigned long V_174 , V_72 ;
unsigned long V_175 ;
V_72 = F_128 ( V_172 -> V_6 , V_91 -> V_149 ,
F_149 ( T_1 , * V_6 , V_172 -> V_6 ) ) ;
V_174 = F_130 ( * V_82 , V_91 -> V_149 ) ;
for ( V_72 = F_150 ( V_172 -> V_83 , V_151 , V_72 ) ;
V_72 < V_151 ;
V_72 = F_150 ( V_172 -> V_83 , V_151 , V_72 + 1 ) ) {
V_175 = F_151 ( V_172 -> V_83 ,
V_151 , V_72 ) ;
if ( ( V_175 - V_72 ) >= V_174 ) {
V_173 = V_175 - V_72 ;
break;
}
V_72 = V_175 ;
}
if ( V_173 ) {
* V_6 = ( T_1 ) ( V_72 * V_91 -> V_149 ) + V_172 -> V_6 ;
* V_82 = ( T_1 ) ( V_173 ) * V_91 -> V_149 ;
return 0 ;
}
return - 1 ;
}
static struct V_88 *
F_152 ( struct V_90 * V_91 , T_1 * V_6 , T_1 * V_82 )
{
struct V_88 * V_85 ;
struct V_93 * V_122 ;
int V_16 ;
if ( ! V_91 -> V_97 . V_93 )
return NULL ;
V_85 = F_137 ( V_91 , F_131 ( V_91 , * V_6 ) , 0 , 1 ) ;
if ( ! V_85 )
return NULL ;
for ( V_122 = & V_85 -> V_98 ; V_122 ; V_122 = F_90 ( V_122 ) ) {
V_85 = F_91 ( V_122 , struct V_88 , V_98 ) ;
if ( V_85 -> V_82 < * V_82 )
continue;
if ( V_85 -> V_83 ) {
V_16 = F_148 ( V_91 , V_85 , V_6 , V_82 ) ;
if ( ! V_16 )
return V_85 ;
continue;
}
* V_6 = V_85 -> V_6 ;
* V_82 = V_85 -> V_82 ;
return V_85 ;
}
return NULL ;
}
static void F_153 ( struct V_90 * V_91 ,
struct V_88 * V_155 , T_1 V_6 )
{
V_155 -> V_6 = F_131 ( V_91 , V_6 ) ;
V_155 -> V_82 = 0 ;
F_96 ( & V_155 -> V_110 ) ;
F_94 ( V_91 , V_155 ) ;
V_91 -> V_107 ++ ;
V_91 -> V_108 -> V_109 ( V_91 ) ;
}
static void F_154 ( struct V_90 * V_91 ,
struct V_88 * V_172 )
{
F_92 ( V_91 , V_172 ) ;
F_52 ( V_172 -> V_83 ) ;
F_93 ( V_100 , V_172 ) ;
V_91 -> V_107 -- ;
V_91 -> V_108 -> V_109 ( V_91 ) ;
}
static T_7 int F_155 ( struct V_90 * V_91 ,
struct V_88 * V_172 ,
T_1 * V_6 , T_1 * V_82 )
{
T_1 V_176 ;
T_1 V_177 , V_178 ;
int V_16 ;
V_95:
V_176 = V_172 -> V_6 + ( T_1 ) ( V_151 * V_91 -> V_149 ) - 1 ;
V_177 = * V_6 ;
V_178 = V_91 -> V_149 ;
V_178 = F_115 ( V_178 , V_176 - V_177 + 1 ) ;
V_16 = F_148 ( V_91 , V_172 , & V_177 , & V_178 ) ;
F_60 ( V_16 < 0 || V_177 != * V_6 ) ;
V_178 = F_115 ( V_178 , * V_82 ) ;
V_178 = F_115 ( V_178 , V_176 - V_177 + 1 ) ;
F_145 ( V_91 , V_172 , V_177 , V_178 ) ;
* V_6 += V_178 ;
* V_82 -= V_178 ;
if ( * V_82 ) {
struct V_93 * V_99 = F_90 ( & V_172 -> V_98 ) ;
if ( ! V_172 -> V_82 )
F_154 ( V_91 , V_172 ) ;
if ( ! V_99 )
return - V_179 ;
V_172 = F_91 ( V_99 , struct V_88 ,
V_98 ) ;
if ( ! V_172 -> V_83 )
return - V_180 ;
V_177 = * V_6 ;
V_178 = V_91 -> V_149 ;
V_16 = F_148 ( V_91 , V_172 , & V_177 ,
& V_178 ) ;
if ( V_16 < 0 || V_177 != * V_6 )
return - V_180 ;
goto V_95;
} else if ( ! V_172 -> V_82 )
F_154 ( V_91 , V_172 ) ;
return 0 ;
}
static T_1 F_156 ( struct V_90 * V_91 ,
struct V_88 * V_155 , T_1 V_6 ,
T_1 V_82 )
{
T_1 V_181 = 0 ;
T_1 V_176 ;
V_176 = V_155 -> V_6 + ( T_1 ) ( V_151 * V_91 -> V_149 ) ;
V_181 = F_115 ( V_176 - V_6 , V_82 ) ;
F_146 ( V_91 , V_155 , V_6 , V_181 ) ;
return V_181 ;
}
static bool F_157 ( struct V_90 * V_91 ,
struct V_88 * V_155 )
{
struct V_26 * V_27 = V_91 -> V_162 ;
if ( V_91 -> V_161 < V_91 -> V_170 ) {
if ( V_155 -> V_82 <= V_27 -> V_167 * 4 ) {
if ( V_91 -> V_161 * 2 <= V_91 -> V_170 )
return false ;
} else {
return false ;
}
}
if ( V_151 * V_27 -> V_167 >
V_27 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_158 ( struct V_90 * V_91 ,
struct V_88 * V_155 )
{
struct V_88 * V_172 ;
struct V_26 * V_27 = NULL ;
int V_182 = 0 ;
T_1 V_82 , V_6 , V_183 ;
int V_16 ;
V_82 = V_155 -> V_82 ;
V_6 = V_155 -> V_6 ;
if ( ! V_91 -> V_108 -> F_157 ( V_91 , V_155 ) )
return 0 ;
if ( V_91 -> V_108 == & V_184 )
V_27 = V_91 -> V_162 ;
V_95:
if ( V_27 && ! F_110 ( & V_27 -> V_137 ) ) {
struct V_126 * V_127 ;
struct V_93 * V_122 ;
struct V_88 * V_85 ;
V_127 = F_111 ( V_27 -> V_137 . V_99 ,
struct V_126 ,
V_138 ) ;
F_15 ( & V_127 -> V_31 ) ;
V_122 = F_89 ( & V_127 -> V_3 ) ;
if ( ! V_122 ) {
F_17 ( & V_127 -> V_31 ) ;
goto V_185;
}
V_85 = F_91 ( V_122 , struct V_88 , V_98 ) ;
if ( ! V_85 -> V_83 ) {
F_17 ( & V_127 -> V_31 ) ;
goto V_185;
}
if ( V_85 -> V_6 == F_131 ( V_91 , V_6 ) ) {
V_183 = F_156 ( V_91 , V_85 ,
V_6 , V_82 ) ;
V_82 -= V_183 ;
V_6 += V_183 ;
}
F_17 ( & V_127 -> V_31 ) ;
if ( ! V_82 ) {
V_16 = 1 ;
goto V_105;
}
}
V_185:
V_172 = F_137 ( V_91 , F_131 ( V_91 , V_6 ) ,
1 , 0 ) ;
if ( ! V_172 ) {
F_60 ( V_182 ) ;
goto V_186;
}
V_183 = F_156 ( V_91 , V_172 , V_6 , V_82 ) ;
V_82 -= V_183 ;
V_6 += V_183 ;
V_182 = 0 ;
if ( ! V_82 ) {
V_16 = 1 ;
goto V_105;
} else
goto V_95;
V_186:
if ( V_155 && V_155 -> V_83 ) {
F_153 ( V_91 , V_155 , V_6 ) ;
V_182 = 1 ;
V_155 = NULL ;
goto V_95;
} else {
F_17 ( & V_91 -> V_96 ) ;
if ( ! V_155 ) {
V_155 = F_100 ( V_100 ,
V_58 ) ;
if ( ! V_155 ) {
F_15 ( & V_91 -> V_96 ) ;
V_16 = - V_59 ;
goto V_105;
}
}
V_155 -> V_83 = F_49 ( V_63 , V_58 ) ;
F_15 ( & V_91 -> V_96 ) ;
if ( ! V_155 -> V_83 ) {
V_16 = - V_59 ;
goto V_105;
}
goto V_95;
}
V_105:
if ( V_155 ) {
if ( V_155 -> V_83 )
F_52 ( V_155 -> V_83 ) ;
F_93 ( V_100 , V_155 ) ;
}
return V_16 ;
}
static bool F_159 ( struct V_90 * V_91 ,
struct V_88 * V_155 , bool V_187 )
{
struct V_88 * V_188 ;
struct V_88 * V_189 ;
bool V_190 = false ;
T_1 V_6 = V_155 -> V_6 ;
T_1 V_82 = V_155 -> V_82 ;
V_189 = F_137 ( V_91 , V_6 + V_82 , 0 , 0 ) ;
if ( V_189 && F_138 ( & V_189 -> V_98 ) )
V_188 = F_91 ( F_138 ( & V_189 -> V_98 ) ,
struct V_88 , V_98 ) ;
else
V_188 = F_137 ( V_91 , V_6 - 1 , 0 , 0 ) ;
if ( V_189 && ! V_189 -> V_83 ) {
if ( V_187 )
F_92 ( V_91 , V_189 ) ;
else
F_139 ( V_91 , V_189 ) ;
V_155 -> V_82 += V_189 -> V_82 ;
F_93 ( V_100 , V_189 ) ;
V_190 = true ;
}
if ( V_188 && ! V_188 -> V_83 &&
V_188 -> V_6 + V_188 -> V_82 == V_6 ) {
if ( V_187 )
F_92 ( V_91 , V_188 ) ;
else
F_139 ( V_91 , V_188 ) ;
V_155 -> V_6 = V_188 -> V_6 ;
V_155 -> V_82 += V_188 -> V_82 ;
F_93 ( V_100 , V_188 ) ;
V_190 = true ;
}
return V_190 ;
}
int F_160 ( struct V_90 * V_91 ,
T_1 V_6 , T_1 V_82 )
{
struct V_88 * V_155 ;
int V_16 = 0 ;
V_155 = F_100 ( V_100 , V_58 ) ;
if ( ! V_155 )
return - V_59 ;
V_155 -> V_6 = V_6 ;
V_155 -> V_82 = V_82 ;
F_15 ( & V_91 -> V_96 ) ;
if ( F_159 ( V_91 , V_155 , true ) )
goto V_191;
V_16 = F_158 ( V_91 , V_155 ) ;
if ( V_16 < 0 ) {
goto V_105;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_105;
}
V_191:
V_16 = F_94 ( V_91 , V_155 ) ;
if ( V_16 )
F_93 ( V_100 , V_155 ) ;
V_105:
F_17 ( & V_91 -> V_96 ) ;
if ( V_16 ) {
F_19 ( V_192 L_16 , V_16 ) ;
F_60 ( V_16 == - V_158 ) ;
}
return V_16 ;
}
int F_161 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_82 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_155 ;
int V_16 = 0 ;
F_15 ( & V_91 -> V_96 ) ;
V_95:
if ( ! V_82 )
goto V_193;
V_155 = F_137 ( V_91 , V_6 , 0 , 0 ) ;
if ( ! V_155 ) {
V_155 = F_137 ( V_91 , F_131 ( V_91 , V_6 ) ,
1 , 0 ) ;
if ( ! V_155 ) {
goto V_193;
}
}
if ( ! V_155 -> V_83 ) {
F_92 ( V_91 , V_155 ) ;
if ( V_6 == V_155 -> V_6 ) {
T_1 V_194 = F_115 ( V_82 , V_155 -> V_82 ) ;
V_155 -> V_82 -= V_194 ;
V_155 -> V_6 += V_194 ;
if ( V_155 -> V_82 ) {
V_16 = F_94 ( V_91 , V_155 ) ;
F_59 ( V_16 ) ;
} else {
F_93 ( V_100 , V_155 ) ;
}
V_6 += V_194 ;
V_82 -= V_194 ;
goto V_95;
} else {
T_1 V_195 = V_155 -> V_82 + V_155 -> V_6 ;
V_155 -> V_82 = V_6 - V_155 -> V_6 ;
V_16 = F_94 ( V_91 , V_155 ) ;
F_59 ( V_16 ) ;
if ( V_16 )
goto V_193;
if ( V_195 < V_6 + V_82 ) {
V_82 -= V_195 - V_6 ;
V_6 = V_195 ;
goto V_95;
} else if ( V_195 == V_6 + V_82 ) {
goto V_193;
}
F_17 ( & V_91 -> V_96 ) ;
V_16 = F_162 ( V_27 , V_6 + V_82 ,
V_195 - ( V_6 + V_82 ) ) ;
F_59 ( V_16 ) ;
goto V_105;
}
}
V_16 = F_155 ( V_91 , V_155 , & V_6 , & V_82 ) ;
if ( V_16 == - V_180 )
goto V_95;
F_60 ( V_16 ) ;
V_193:
F_17 ( & V_91 -> V_96 ) ;
V_105:
return V_16 ;
}
void F_163 ( struct V_26 * V_27 ,
T_1 V_82 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_155 ;
struct V_93 * V_94 ;
int V_171 = 0 ;
for ( V_94 = F_89 ( & V_91 -> V_97 ) ; V_94 ; V_94 = F_90 ( V_94 ) ) {
V_155 = F_91 ( V_94 , struct V_88 , V_98 ) ;
if ( V_155 -> V_82 >= V_82 && ! V_27 -> V_196 )
V_171 ++ ;
F_19 ( V_192 L_17 ,
( unsigned long long ) V_155 -> V_6 ,
( unsigned long long ) V_155 -> V_82 ,
( V_155 -> V_83 ) ? L_18 : L_19 ) ;
}
F_19 ( V_32 L_20 ,
F_110 ( & V_27 -> V_137 ) ? L_19 : L_18 ) ;
F_19 ( V_32 L_21
L_22 , V_171 ) ;
}
void F_164 ( struct V_26 * V_27 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
F_165 ( & V_91 -> V_96 ) ;
V_91 -> V_149 = V_27 -> V_167 ;
V_91 -> V_131 = V_27 -> V_8 . V_17 ;
V_91 -> V_162 = V_27 ;
V_91 -> V_108 = & V_184 ;
V_91 -> V_170 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_88 ) ;
}
static int
F_166 (
struct V_26 * V_27 ,
struct V_126 * V_127 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_85 ;
struct V_93 * V_122 ;
F_15 ( & V_127 -> V_31 ) ;
if ( V_127 -> V_27 != V_27 )
goto V_105;
V_127 -> V_27 = NULL ;
V_127 -> V_197 = 0 ;
F_103 ( & V_127 -> V_138 ) ;
V_122 = F_89 ( & V_127 -> V_3 ) ;
while ( V_122 ) {
bool V_83 ;
V_85 = F_91 ( V_122 , struct V_88 , V_98 ) ;
V_122 = F_90 ( & V_85 -> V_98 ) ;
F_140 ( & V_85 -> V_98 , & V_127 -> V_3 ) ;
V_83 = ( V_85 -> V_83 != NULL ) ;
if ( ! V_83 )
F_159 ( V_91 , V_85 , false ) ;
F_133 ( & V_91 -> V_97 ,
V_85 -> V_6 , & V_85 -> V_98 , V_83 ) ;
}
V_127 -> V_3 = V_198 ;
V_105:
F_17 ( & V_127 -> V_31 ) ;
F_167 ( V_27 ) ;
return 0 ;
}
void F_168 ( struct V_90 * V_91 )
{
struct V_88 * V_155 ;
struct V_93 * V_122 ;
while ( ( V_122 = F_169 ( & V_91 -> V_97 ) ) != NULL ) {
V_155 = F_91 ( V_122 , struct V_88 , V_98 ) ;
if ( ! V_155 -> V_83 ) {
F_92 ( V_91 , V_155 ) ;
F_93 ( V_100 , V_155 ) ;
} else {
F_154 ( V_91 , V_155 ) ;
}
if ( F_170 () ) {
F_17 ( & V_91 -> V_96 ) ;
F_171 () ;
F_15 ( & V_91 -> V_96 ) ;
}
}
}
void F_104 ( struct V_90 * V_91 )
{
F_15 ( & V_91 -> V_96 ) ;
F_168 ( V_91 ) ;
F_17 ( & V_91 -> V_96 ) ;
}
void F_172 ( struct V_26 * V_27 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_126 * V_127 ;
struct V_101 * V_199 ;
F_15 ( & V_91 -> V_96 ) ;
while ( ( V_199 = V_27 -> V_137 . V_99 ) !=
& V_27 -> V_137 ) {
V_127 = F_111 ( V_199 , struct V_126 ,
V_138 ) ;
F_59 ( V_127 -> V_27 != V_27 ) ;
F_166 ( V_27 , V_127 ) ;
if ( F_170 () ) {
F_17 ( & V_91 -> V_96 ) ;
F_171 () ;
F_15 ( & V_91 -> V_96 ) ;
}
}
F_168 ( V_91 ) ;
F_17 ( & V_91 -> V_96 ) ;
}
T_1 F_173 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_82 , T_1 V_200 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_85 = NULL ;
T_1 V_201 = V_82 + V_200 ;
T_1 V_16 = 0 ;
F_15 ( & V_91 -> V_96 ) ;
V_85 = F_152 ( V_91 , & V_6 , & V_201 ) ;
if ( ! V_85 )
goto V_105;
V_16 = V_6 ;
if ( V_85 -> V_83 ) {
F_145 ( V_91 , V_85 , V_6 , V_82 ) ;
if ( ! V_85 -> V_82 )
F_154 ( V_91 , V_85 ) ;
} else {
F_92 ( V_91 , V_85 ) ;
V_85 -> V_6 += V_82 ;
V_85 -> V_82 -= V_82 ;
if ( ! V_85 -> V_82 )
F_93 ( V_100 , V_85 ) ;
else
F_94 ( V_91 , V_85 ) ;
}
V_105:
F_17 ( & V_91 -> V_96 ) ;
return V_16 ;
}
int F_174 (
struct V_26 * V_27 ,
struct V_126 * V_127 )
{
struct V_90 * V_91 ;
int V_16 ;
F_15 ( & V_127 -> V_31 ) ;
if ( ! V_27 ) {
V_27 = V_127 -> V_27 ;
if ( ! V_27 ) {
F_17 ( & V_127 -> V_31 ) ;
return 0 ;
}
} else if ( V_127 -> V_27 != V_27 ) {
F_17 ( & V_127 -> V_31 ) ;
return 0 ;
}
F_175 ( & V_27 -> V_171 ) ;
F_17 ( & V_127 -> V_31 ) ;
V_91 = V_27 -> V_112 ;
F_15 ( & V_91 -> V_96 ) ;
V_16 = F_166 ( V_27 , V_127 ) ;
F_17 ( & V_91 -> V_96 ) ;
F_167 ( V_27 ) ;
return V_16 ;
}
static T_1 F_176 ( struct V_26 * V_27 ,
struct V_126 * V_127 ,
struct V_88 * V_85 ,
T_1 V_82 , T_1 V_202 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
int V_136 ;
T_1 V_177 = V_127 -> V_197 ;
T_1 V_178 = V_82 ;
T_1 V_16 = 0 ;
V_177 = V_202 ;
V_178 = V_82 ;
V_136 = F_148 ( V_91 , V_85 , & V_177 , & V_178 ) ;
if ( V_136 )
return 0 ;
V_16 = V_177 ;
F_143 ( V_91 , V_85 , V_16 , V_82 ) ;
return V_16 ;
}
T_1 F_177 ( struct V_26 * V_27 ,
struct V_126 * V_127 , T_1 V_82 ,
T_1 V_202 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_85 = NULL ;
struct V_93 * V_122 ;
T_1 V_16 = 0 ;
F_15 ( & V_127 -> V_31 ) ;
if ( V_82 > V_127 -> V_203 )
goto V_105;
if ( V_127 -> V_27 != V_27 )
goto V_105;
V_122 = F_89 ( & V_127 -> V_3 ) ;
if ( ! V_122 )
goto V_105;
V_85 = F_91 ( V_122 , struct V_88 , V_98 ) ;
while( 1 ) {
if ( V_85 -> V_82 < V_82 ||
( ! V_85 -> V_83 && V_85 -> V_6 < V_202 ) ) {
V_122 = F_90 ( & V_85 -> V_98 ) ;
if ( ! V_122 )
break;
V_85 = F_91 ( V_122 , struct V_88 ,
V_98 ) ;
continue;
}
if ( V_85 -> V_83 ) {
V_16 = F_176 ( V_27 ,
V_127 , V_85 , V_82 ,
V_127 -> V_197 ) ;
if ( V_16 == 0 ) {
V_122 = F_90 ( & V_85 -> V_98 ) ;
if ( ! V_122 )
break;
V_85 = F_91 ( V_122 , struct V_88 ,
V_98 ) ;
continue;
}
V_127 -> V_197 += V_82 ;
} else {
V_16 = V_85 -> V_6 ;
V_85 -> V_6 += V_82 ;
V_85 -> V_82 -= V_82 ;
}
if ( V_85 -> V_82 == 0 )
F_140 ( & V_85 -> V_98 , & V_127 -> V_3 ) ;
break;
}
V_105:
F_17 ( & V_127 -> V_31 ) ;
if ( ! V_16 )
return 0 ;
F_15 ( & V_91 -> V_96 ) ;
V_91 -> V_120 -= V_82 ;
if ( V_85 -> V_82 == 0 ) {
V_91 -> V_161 -- ;
if ( V_85 -> V_83 ) {
F_52 ( V_85 -> V_83 ) ;
V_91 -> V_107 -- ;
V_91 -> V_108 -> V_109 ( V_91 ) ;
}
F_93 ( V_100 , V_85 ) ;
}
F_17 ( & V_91 -> V_96 ) ;
return V_16 ;
}
static int F_178 ( struct V_26 * V_27 ,
struct V_88 * V_85 ,
struct V_126 * V_127 ,
T_1 V_6 , T_1 V_82 ,
T_1 V_204 , T_1 V_205 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
unsigned long V_175 ;
unsigned long V_72 ;
unsigned long V_206 ;
unsigned long V_207 ;
unsigned long V_173 ;
unsigned long V_131 = 0 ;
unsigned long V_208 = 0 ;
int V_16 ;
V_72 = F_128 ( V_85 -> V_6 , V_27 -> V_167 ,
F_149 ( T_1 , V_6 , V_85 -> V_6 ) ) ;
V_206 = F_130 ( V_82 , V_27 -> V_167 ) ;
V_207 = F_130 ( V_205 , V_27 -> V_167 ) ;
V_95:
V_173 = 0 ;
for ( V_72 = F_150 ( V_85 -> V_83 , V_151 , V_72 ) ;
V_72 < V_151 ;
V_72 = F_150 ( V_85 -> V_83 , V_151 , V_72 + 1 ) ) {
V_175 = F_151 ( V_85 -> V_83 ,
V_151 , V_72 ) ;
if ( V_175 - V_72 >= V_207 ) {
V_173 = V_175 - V_72 ;
break;
}
V_72 = V_175 ;
}
if ( ! V_173 )
return - V_53 ;
if ( ! V_208 ) {
V_131 = V_72 ;
V_127 -> V_203 = 0 ;
}
V_208 += V_173 ;
if ( V_127 -> V_203 < V_173 * V_27 -> V_167 )
V_127 -> V_203 = V_173 * V_27 -> V_167 ;
if ( V_208 < V_206 || V_127 -> V_203 < V_204 ) {
V_72 = V_175 + 1 ;
goto V_95;
}
V_127 -> V_197 = V_131 * V_27 -> V_167 +
V_85 -> V_6 ;
F_140 ( & V_85 -> V_98 , & V_91 -> V_97 ) ;
V_16 = F_133 ( & V_127 -> V_3 , V_85 -> V_6 ,
& V_85 -> V_98 , 1 ) ;
F_60 ( V_16 ) ;
F_179 ( V_27 , V_127 ,
V_208 * V_27 -> V_167 , 1 ) ;
return 0 ;
}
static T_7 int
F_180 ( struct V_26 * V_27 ,
struct V_126 * V_127 ,
struct V_101 * V_102 , T_1 V_6 , T_1 V_82 ,
T_1 V_204 , T_1 V_205 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_209 = NULL ;
struct V_88 * V_85 = NULL ;
struct V_88 * V_210 ;
struct V_93 * V_122 ;
T_1 V_197 ;
T_1 V_211 ;
T_1 V_212 ;
T_1 V_213 = 0 ;
V_85 = F_137 ( V_91 , V_6 , 0 , 1 ) ;
if ( ! V_85 )
return - V_53 ;
while ( V_85 -> V_83 || V_85 -> V_82 < V_205 ) {
if ( V_85 -> V_83 && F_110 ( & V_85 -> V_110 ) )
F_101 ( & V_85 -> V_110 , V_102 ) ;
V_122 = F_90 ( & V_85 -> V_98 ) ;
if ( ! V_122 )
return - V_53 ;
V_85 = F_91 ( V_122 , struct V_88 , V_98 ) ;
}
V_197 = V_85 -> V_6 ;
V_211 = V_85 -> V_82 ;
V_212 = V_85 -> V_82 ;
V_209 = V_85 ;
V_210 = V_85 ;
for ( V_122 = F_90 ( & V_85 -> V_98 ) ; V_122 ;
V_122 = F_90 ( & V_85 -> V_98 ) ) {
V_85 = F_91 ( V_122 , struct V_88 , V_98 ) ;
if ( V_85 -> V_83 ) {
if ( F_110 ( & V_85 -> V_110 ) )
F_101 ( & V_85 -> V_110 , V_102 ) ;
continue;
}
if ( V_85 -> V_82 < V_205 )
continue;
V_210 = V_85 ;
V_211 += V_85 -> V_82 ;
if ( V_85 -> V_82 > V_212 )
V_212 = V_85 -> V_82 ;
}
if ( V_211 < V_82 || V_212 < V_204 )
return - V_53 ;
V_127 -> V_197 = V_209 -> V_6 ;
V_122 = & V_209 -> V_98 ;
do {
int V_16 ;
V_85 = F_91 ( V_122 , struct V_88 , V_98 ) ;
V_122 = F_90 ( & V_85 -> V_98 ) ;
if ( V_85 -> V_83 || V_85 -> V_82 < V_205 )
continue;
F_140 ( & V_85 -> V_98 , & V_91 -> V_97 ) ;
V_16 = F_133 ( & V_127 -> V_3 , V_85 -> V_6 ,
& V_85 -> V_98 , 0 ) ;
V_213 += V_85 -> V_82 ;
F_60 ( V_16 ) ;
} while ( V_122 && V_85 != V_210 );
V_127 -> V_203 = V_212 ;
F_179 ( V_27 , V_127 , V_213 , 0 ) ;
return 0 ;
}
static T_7 int
F_181 ( struct V_26 * V_27 ,
struct V_126 * V_127 ,
struct V_101 * V_102 , T_1 V_6 , T_1 V_82 ,
T_1 V_204 , T_1 V_205 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_85 ;
int V_16 = - V_53 ;
T_1 V_214 = F_131 ( V_91 , V_6 ) ;
if ( V_91 -> V_107 == 0 )
return - V_53 ;
V_85 = F_182 ( V_102 , struct V_88 , V_110 ) ;
if ( V_85 -> V_6 != V_214 ) {
V_85 = F_137 ( V_91 , V_214 , 1 , 0 ) ;
if ( V_85 && F_110 ( & V_85 -> V_110 ) )
F_183 ( & V_85 -> V_110 , V_102 ) ;
}
F_184 (entry, bitmaps, list) {
if ( V_85 -> V_82 < V_82 )
continue;
V_16 = F_178 ( V_27 , V_85 , V_127 , V_6 ,
V_82 , V_204 , V_205 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_53 ;
}
int F_185 ( struct V_36 * V_37 ,
struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_126 * V_127 ,
T_1 V_6 , T_1 V_82 , T_1 V_200 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_85 , * V_80 ;
F_186 ( V_102 ) ;
T_1 V_205 ;
T_1 V_204 ;
int V_16 ;
if ( F_187 ( V_3 , V_215 ) ) {
V_204 = V_205 = V_82 + V_200 ;
} else if ( V_27 -> V_28 & V_216 ) {
V_204 = V_82 ;
V_205 = V_27 -> V_167 ;
} else {
V_204 = F_114 ( V_82 , ( V_82 + V_200 ) >> 2 ) ;
V_205 = V_27 -> V_167 ;
}
F_15 ( & V_91 -> V_96 ) ;
if ( V_91 -> V_120 < V_82 ) {
F_17 ( & V_91 -> V_96 ) ;
return - V_53 ;
}
F_15 ( & V_127 -> V_31 ) ;
if ( V_127 -> V_27 ) {
V_16 = 0 ;
goto V_105;
}
F_188 ( V_27 , V_6 , V_82 , V_200 ,
V_205 ) ;
F_96 ( & V_102 ) ;
V_16 = F_180 ( V_27 , V_127 , & V_102 , V_6 ,
V_82 + V_200 ,
V_204 , V_205 ) ;
if ( V_16 )
V_16 = F_181 ( V_27 , V_127 , & V_102 ,
V_6 , V_82 + V_200 ,
V_204 , V_205 ) ;
F_102 (entry, tmp, &bitmaps, list)
F_103 ( & V_85 -> V_110 ) ;
if ( ! V_16 ) {
F_175 ( & V_27 -> V_171 ) ;
F_101 ( & V_127 -> V_138 ,
& V_27 -> V_137 ) ;
V_127 -> V_27 = V_27 ;
} else {
F_189 ( V_27 ) ;
}
V_105:
F_17 ( & V_127 -> V_31 ) ;
F_17 ( & V_91 -> V_96 ) ;
return V_16 ;
}
void F_190 ( struct V_126 * V_127 )
{
F_165 ( & V_127 -> V_31 ) ;
F_165 ( & V_127 -> V_217 ) ;
V_127 -> V_3 = V_198 ;
V_127 -> V_203 = 0 ;
F_96 ( & V_127 -> V_138 ) ;
V_127 -> V_27 = NULL ;
}
static int F_191 ( struct V_26 * V_27 ,
T_1 * V_218 , T_1 V_131 , T_1 V_82 ,
T_1 V_219 , T_1 V_220 )
{
struct V_221 * V_222 = V_27 -> V_222 ;
struct V_111 * V_22 = V_27 -> V_22 ;
int V_16 ;
int V_223 = 0 ;
T_1 V_224 = 0 ;
F_15 ( & V_222 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( ! V_27 -> V_196 ) {
V_27 -> V_52 += V_220 ;
V_222 -> V_225 += V_220 ;
V_223 = 1 ;
}
F_17 ( & V_27 -> V_31 ) ;
F_17 ( & V_222 -> V_31 ) ;
V_16 = F_192 ( V_22 -> V_226 ,
V_131 , V_82 , & V_224 ) ;
if ( ! V_16 )
* V_218 += V_224 ;
F_162 ( V_27 , V_219 , V_220 ) ;
if ( V_223 ) {
F_15 ( & V_222 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_196 )
V_222 -> V_227 += V_220 ;
V_27 -> V_52 -= V_220 ;
V_222 -> V_225 -= V_220 ;
F_17 ( & V_222 -> V_31 ) ;
F_17 ( & V_27 -> V_31 ) ;
}
return V_16 ;
}
static int F_193 ( struct V_26 * V_27 ,
T_1 * V_218 , T_1 V_131 , T_1 V_176 , T_1 V_228 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_85 ;
struct V_93 * V_122 ;
int V_16 = 0 ;
T_1 V_132 ;
T_1 V_165 ;
T_1 V_82 ;
while ( V_131 < V_176 ) {
F_15 ( & V_91 -> V_96 ) ;
if ( V_91 -> V_120 < V_228 ) {
F_17 ( & V_91 -> V_96 ) ;
break;
}
V_85 = F_137 ( V_91 , V_131 , 0 , 1 ) ;
if ( ! V_85 ) {
F_17 ( & V_91 -> V_96 ) ;
break;
}
while ( V_85 -> V_83 ) {
V_122 = F_90 ( & V_85 -> V_98 ) ;
if ( ! V_122 ) {
F_17 ( & V_91 -> V_96 ) ;
goto V_105;
}
V_85 = F_91 ( V_122 , struct V_88 ,
V_98 ) ;
}
if ( V_85 -> V_6 >= V_176 ) {
F_17 ( & V_91 -> V_96 ) ;
break;
}
V_132 = V_85 -> V_6 ;
V_165 = V_85 -> V_82 ;
V_131 = F_114 ( V_131 , V_132 ) ;
V_82 = F_115 ( V_132 + V_165 , V_176 ) - V_131 ;
if ( V_82 < V_228 ) {
F_17 ( & V_91 -> V_96 ) ;
goto V_99;
}
F_92 ( V_91 , V_85 ) ;
F_93 ( V_100 , V_85 ) ;
F_17 ( & V_91 -> V_96 ) ;
V_16 = F_191 ( V_27 , V_218 , V_131 , V_82 ,
V_132 , V_165 ) ;
if ( V_16 )
break;
V_99:
V_131 += V_82 ;
if ( F_194 ( V_229 ) ) {
V_16 = - V_230 ;
break;
}
F_171 () ;
}
V_105:
return V_16 ;
}
static int F_195 ( struct V_26 * V_27 ,
T_1 * V_218 , T_1 V_131 , T_1 V_176 , T_1 V_228 )
{
struct V_90 * V_91 = V_27 -> V_112 ;
struct V_88 * V_85 ;
int V_16 = 0 ;
int V_231 ;
T_1 V_82 ;
T_1 V_6 = F_131 ( V_91 , V_131 ) ;
while ( V_6 < V_176 ) {
bool V_232 = false ;
F_15 ( & V_91 -> V_96 ) ;
if ( V_91 -> V_120 < V_228 ) {
F_17 ( & V_91 -> V_96 ) ;
break;
}
V_85 = F_137 ( V_91 , V_6 , 1 , 0 ) ;
if ( ! V_85 ) {
F_17 ( & V_91 -> V_96 ) ;
V_232 = true ;
goto V_99;
}
V_82 = V_228 ;
V_231 = F_148 ( V_91 , V_85 , & V_131 , & V_82 ) ;
if ( V_231 || V_131 >= V_176 ) {
F_17 ( & V_91 -> V_96 ) ;
V_232 = true ;
goto V_99;
}
V_82 = F_115 ( V_82 , V_176 - V_131 ) ;
if ( V_82 < V_228 ) {
F_17 ( & V_91 -> V_96 ) ;
goto V_99;
}
F_145 ( V_91 , V_85 , V_131 , V_82 ) ;
if ( V_85 -> V_82 == 0 )
F_154 ( V_91 , V_85 ) ;
F_17 ( & V_91 -> V_96 ) ;
V_16 = F_191 ( V_27 , V_218 , V_131 , V_82 ,
V_131 , V_82 ) ;
if ( V_16 )
break;
V_99:
if ( V_232 ) {
V_6 += V_151 * V_91 -> V_149 ;
} else {
V_131 += V_82 ;
if ( V_131 >= V_6 + V_151 * V_91 -> V_149 )
V_6 += V_151 * V_91 -> V_149 ;
}
if ( F_194 ( V_229 ) ) {
V_16 = - V_230 ;
break;
}
F_171 () ;
}
return V_16 ;
}
int F_196 ( struct V_26 * V_27 ,
T_1 * V_224 , T_1 V_131 , T_1 V_176 , T_1 V_228 )
{
int V_16 ;
* V_224 = 0 ;
V_16 = F_193 ( V_27 , V_224 , V_131 , V_176 , V_228 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_195 ( V_27 , V_224 , V_131 , V_176 , V_228 ) ;
return V_16 ;
}
T_1 F_197 ( struct V_2 * V_233 )
{
struct V_90 * V_91 = V_233 -> V_234 ;
struct V_88 * V_85 = NULL ;
T_1 V_38 = 0 ;
F_15 ( & V_91 -> V_96 ) ;
if ( F_198 ( & V_91 -> V_97 ) )
goto V_105;
V_85 = F_91 ( F_89 ( & V_91 -> V_97 ) ,
struct V_88 , V_98 ) ;
if ( ! V_85 -> V_83 ) {
V_38 = V_85 -> V_6 ;
F_92 ( V_91 , V_85 ) ;
V_85 -> V_6 ++ ;
V_85 -> V_82 -- ;
if ( ! V_85 -> V_82 )
F_93 ( V_100 , V_85 ) ;
else
F_94 ( V_91 , V_85 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_171 = 1 ;
int V_16 ;
V_16 = F_148 ( V_91 , V_85 , & V_6 , & V_171 ) ;
F_60 ( V_16 ) ;
V_38 = V_6 ;
F_145 ( V_91 , V_85 , V_6 , 1 ) ;
if ( V_85 -> V_82 == 0 )
F_154 ( V_91 , V_85 ) ;
}
V_105:
F_17 ( & V_91 -> V_96 ) ;
return V_38 ;
}
struct V_1 * F_199 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_235 ) ;
if ( V_3 -> V_236 )
V_1 = F_16 ( V_3 -> V_236 ) ;
F_17 ( & V_3 -> V_235 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_235 ) ;
if ( ! F_200 ( V_3 -> V_22 ) )
V_3 -> V_236 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_235 ) ;
return V_1 ;
}
int F_201 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_37 , V_5 ,
V_43 , 0 ) ;
}
int F_202 ( struct V_111 * V_22 , struct V_2 * V_3 )
{
struct V_90 * V_91 = V_3 -> V_234 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_237 = F_203 ( & V_3 -> V_238 ) ;
if ( ! F_187 ( V_3 , V_239 ) )
return 0 ;
if ( F_200 ( V_22 ) )
return 0 ;
V_5 = F_107 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_199 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_105;
if ( V_237 != F_18 ( V_1 ) -> V_77 )
goto V_240;
V_16 = F_95 ( V_3 , V_1 , V_91 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_19 ( V_75 L_23
L_24 , V_3 -> V_241 . V_17 ) ;
V_240:
F_11 ( V_1 ) ;
V_105:
F_108 ( V_5 ) ;
return V_16 ;
}
int F_204 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 = V_3 -> V_234 ;
struct V_1 * V_1 ;
int V_16 ;
if ( ! F_187 ( V_3 , V_239 ) )
return 0 ;
V_1 = F_199 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_109 ( V_3 , V_1 , V_91 , NULL , V_37 , V_5 , 0 ) ;
if ( V_16 ) {
F_205 ( V_1 , V_1 -> V_143 ) ;
#ifdef F_127
F_19 ( V_75 L_25
L_26 , V_3 -> V_241 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
