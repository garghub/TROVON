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
V_1 -> V_24 -> V_25 &= ~ V_26 ;
return V_1 ;
}
struct V_1 * F_12 ( struct V_2 * V_3 ,
struct V_27
* V_28 , struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
T_2 V_25 = V_29 | V_30 ;
F_13 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_1 )
V_1 = F_14 ( V_28 -> V_1 ) ;
F_15 ( & V_28 -> V_31 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 ,
V_28 -> V_8 . V_17 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_13 ( & V_28 -> V_31 ) ;
if ( ! ( ( F_16 ( V_1 ) -> V_25 & V_25 ) == V_25 ) ) {
F_17 ( V_32 L_1 ) ;
F_16 ( V_1 ) -> V_25 |= V_29 |
V_30 ;
V_28 -> V_33 = V_34 ;
}
if ( ! V_28 -> V_35 ) {
V_28 -> V_1 = F_14 ( V_1 ) ;
V_28 -> V_35 = 1 ;
}
F_15 ( & V_28 -> V_31 ) ;
return V_1 ;
}
int F_18 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 , T_1 V_38 , T_1 V_6 )
{
struct V_7 V_8 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_39 * V_40 ;
struct V_14 * V_15 ;
T_1 V_25 = V_41 | V_42 ;
int V_16 ;
V_16 = F_19 ( V_37 , V_3 , V_5 , V_38 ) ;
if ( V_16 )
return V_16 ;
if ( V_38 != V_43 )
V_25 |= V_29 | V_30 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_40 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_39 ) ;
F_20 ( V_15 , & V_11 , V_5 -> V_21 [ 0 ] ) ;
F_21 ( V_15 , 0 , ( unsigned long ) V_40 ,
sizeof( * V_40 ) ) ;
F_22 ( V_15 , V_40 , V_37 -> V_44 ) ;
F_23 ( V_15 , V_40 , 0 ) ;
F_24 ( V_15 , V_40 , 0 ) ;
F_25 ( V_15 , V_40 , 0 ) ;
F_26 ( V_15 , V_40 , 0 ) ;
F_27 ( V_15 , V_40 , V_45 | 0600 ) ;
F_28 ( V_15 , V_40 , V_25 ) ;
F_29 ( V_15 , V_40 , 1 ) ;
F_30 ( V_15 , V_40 , V_37 -> V_44 ) ;
F_31 ( V_15 , V_40 , V_6 ) ;
F_32 ( V_15 ) ;
F_4 ( V_5 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_33 ( V_37 , V_3 , V_5 , & V_8 ,
sizeof( struct V_12 ) ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 ) ;
return V_16 ;
}
V_15 = V_5 -> V_20 [ 0 ] ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_21 ( V_15 , 0 , ( unsigned long ) V_13 , sizeof( * V_13 ) ) ;
F_34 ( V_15 , V_13 , & V_11 ) ;
F_32 ( V_15 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
int V_16 ;
T_1 V_38 ;
V_16 = F_36 ( V_3 , & V_38 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_18 ( V_3 , V_37 , V_5 , V_38 ,
V_28 -> V_8 . V_17 ) ;
}
int F_37 ( struct V_2 * V_3 ,
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
V_48 = F_38 ( V_3 , 1 ) +
F_39 ( V_3 , 1 ) ;
F_13 ( & V_37 -> V_50 -> V_31 ) ;
if ( V_37 -> V_50 -> V_52 < V_48 ) {
F_15 ( & V_37 -> V_50 -> V_31 ) ;
V_37 -> V_50 = V_47 ;
return - V_53 ;
}
F_15 ( & V_37 -> V_50 -> V_31 ) ;
V_49 = F_40 ( V_1 ) ;
F_41 ( V_1 , 0 ) ;
F_42 ( V_1 , V_49 , 0 ) ;
V_16 = F_43 ( V_37 , V_3 , V_1 ,
0 , V_54 ) ;
if ( V_16 ) {
V_37 -> V_50 = V_47 ;
F_44 ( 1 ) ;
return V_16 ;
}
V_16 = F_45 ( V_37 , V_3 , V_1 ) ;
V_37 -> V_50 = V_47 ;
return V_16 ;
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_55 * V_56 ;
unsigned long V_57 ;
V_56 = F_47 ( sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
F_48 ( V_56 , V_1 -> V_24 ) ;
V_57 = ( F_40 ( V_1 ) - 1 ) >> V_60 ;
F_49 ( V_1 -> V_24 , V_56 , NULL , 0 , V_57 ) ;
F_50 ( V_56 ) ;
return 0 ;
}
static int F_51 ( struct V_61 * V_61 , struct V_1 * V_1 ,
struct V_2 * V_3 )
{
memset ( V_61 , 0 , sizeof( struct V_61 ) ) ;
V_61 -> V_62 = ( F_40 ( V_1 ) + V_63 - 1 ) >>
V_60 ;
V_61 -> V_64 = F_47 ( sizeof( struct V_65 * ) * V_61 -> V_62 ,
V_58 ) ;
if ( ! V_61 -> V_64 )
return - V_59 ;
V_61 -> V_3 = V_3 ;
if ( F_52 ( V_1 ) != V_43 )
V_61 -> V_66 = 1 ;
return 0 ;
}
static void F_53 ( struct V_61 * V_61 )
{
F_50 ( V_61 -> V_64 ) ;
}
static void F_54 ( struct V_61 * V_61 )
{
if ( V_61 -> V_67 ) {
F_55 ( V_61 -> V_65 ) ;
V_61 -> V_67 = NULL ;
V_61 -> V_68 = NULL ;
}
}
static void F_56 ( struct V_61 * V_61 , int V_69 )
{
F_44 ( V_61 -> V_67 ) ;
F_57 ( V_61 -> V_70 >= V_61 -> V_62 ) ;
V_61 -> V_65 = V_61 -> V_64 [ V_61 -> V_70 ++ ] ;
V_61 -> V_67 = F_58 ( V_61 -> V_65 ) ;
V_61 -> V_68 = V_61 -> V_67 ;
V_61 -> V_71 = V_63 ;
if ( V_69 )
memset ( V_61 -> V_67 , 0 , V_63 ) ;
}
static void F_59 ( struct V_61 * V_61 )
{
int V_72 ;
F_54 ( V_61 ) ;
for ( V_72 = 0 ; V_72 < V_61 -> V_62 ; V_72 ++ ) {
F_60 ( V_61 -> V_64 [ V_72 ] ) ;
F_61 ( V_61 -> V_64 [ V_72 ] ) ;
F_62 ( V_61 -> V_64 [ V_72 ] ) ;
}
}
static int F_63 ( struct V_61 * V_61 , struct V_1 * V_1 ,
int V_73 )
{
struct V_65 * V_65 ;
T_4 V_74 = F_64 ( V_1 -> V_24 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_61 -> V_62 ; V_72 ++ ) {
V_65 = F_65 ( V_1 -> V_24 , V_72 , V_74 ) ;
if ( ! V_65 ) {
F_59 ( V_61 ) ;
return - V_59 ;
}
V_61 -> V_64 [ V_72 ] = V_65 ;
if ( V_73 && ! F_66 ( V_65 ) ) {
F_67 ( NULL , V_65 ) ;
F_68 ( V_65 ) ;
if ( ! F_66 ( V_65 ) ) {
F_17 ( V_75 L_2
L_3 ) ;
F_59 ( V_61 ) ;
return - V_76 ;
}
}
}
for ( V_72 = 0 ; V_72 < V_61 -> V_62 ; V_72 ++ ) {
F_69 ( V_61 -> V_64 [ V_72 ] ) ;
F_70 ( V_61 -> V_64 [ V_72 ] ) ;
}
return 0 ;
}
static void F_71 ( struct V_61 * V_61 , T_1 V_77 )
{
T_1 * V_78 ;
F_56 ( V_61 , 1 ) ;
if ( V_61 -> V_66 ) {
V_61 -> V_67 += ( sizeof( T_2 ) * V_61 -> V_62 ) ;
V_61 -> V_71 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_61 -> V_62 ) ;
} else {
V_61 -> V_67 += sizeof( T_1 ) ;
V_61 -> V_71 -= sizeof( T_1 ) * 2 ;
}
V_78 = V_61 -> V_67 ;
* V_78 = F_72 ( V_77 ) ;
V_61 -> V_67 += sizeof( T_1 ) ;
}
static int F_73 ( struct V_61 * V_61 , T_1 V_77 )
{
T_1 * V_79 ;
if ( V_61 -> V_66 ) {
V_61 -> V_67 += sizeof( T_2 ) * V_61 -> V_62 ;
V_61 -> V_71 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_61 -> V_62 ) ;
} else {
V_61 -> V_67 += sizeof( T_1 ) ;
V_61 -> V_71 -= sizeof( T_1 ) * 2 ;
}
V_79 = V_61 -> V_67 ;
if ( F_74 ( * V_79 ) != V_77 ) {
F_75 ( V_75 L_4
L_5 , * V_79 ,
V_77 ) ;
F_54 ( V_61 ) ;
return - V_76 ;
}
V_61 -> V_67 += sizeof( T_1 ) ;
return 0 ;
}
static void F_76 ( struct V_61 * V_61 , int V_70 )
{
T_2 * V_80 ;
T_2 V_81 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_61 -> V_66 ) {
F_54 ( V_61 ) ;
return;
}
if ( V_70 == 0 )
V_6 = sizeof( T_2 ) * V_61 -> V_62 ; ;
V_81 = F_77 ( V_61 -> V_3 , V_61 -> V_68 + V_6 , V_81 ,
V_63 - V_6 ) ;
F_78 ( V_81 , ( char * ) & V_81 ) ;
F_54 ( V_61 ) ;
V_80 = F_58 ( V_61 -> V_64 [ 0 ] ) ;
V_80 += V_70 ;
* V_80 = V_81 ;
F_55 ( V_61 -> V_64 [ 0 ] ) ;
}
static int F_79 ( struct V_61 * V_61 , int V_70 )
{
T_2 * V_80 , V_78 ;
T_2 V_81 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_61 -> V_66 ) {
F_56 ( V_61 , 0 ) ;
return 0 ;
}
if ( V_70 == 0 )
V_6 = sizeof( T_2 ) * V_61 -> V_62 ;
V_80 = F_58 ( V_61 -> V_64 [ 0 ] ) ;
V_80 += V_70 ;
V_78 = * V_80 ;
F_55 ( V_61 -> V_64 [ 0 ] ) ;
F_56 ( V_61 , 0 ) ;
V_81 = F_77 ( V_61 -> V_3 , V_61 -> V_68 + V_6 , V_81 ,
V_63 - V_6 ) ;
F_78 ( V_81 , ( char * ) & V_81 ) ;
if ( V_78 != V_81 ) {
F_75 ( V_75 L_6
L_3 ) ;
F_54 ( V_61 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_80 ( struct V_61 * V_61 , T_1 V_6 , T_1 V_82 ,
void * V_83 )
{
struct V_84 * V_85 ;
if ( ! V_61 -> V_67 )
return - V_53 ;
V_85 = V_61 -> V_67 ;
V_85 -> V_6 = F_72 ( V_6 ) ;
V_85 -> V_82 = F_72 ( V_82 ) ;
V_85 -> type = ( V_83 ) ? V_86 :
V_87 ;
V_61 -> V_67 += sizeof( struct V_84 ) ;
V_61 -> V_71 -= sizeof( struct V_84 ) ;
if ( V_61 -> V_71 >= sizeof( struct V_84 ) )
return 0 ;
F_76 ( V_61 , V_61 -> V_70 - 1 ) ;
if ( V_61 -> V_70 >= V_61 -> V_62 )
return 0 ;
F_56 ( V_61 , 1 ) ;
return 0 ;
}
static int F_81 ( struct V_61 * V_61 , void * V_83 )
{
if ( ! V_61 -> V_67 )
return - V_53 ;
if ( V_61 -> V_67 != V_61 -> V_68 ) {
F_76 ( V_61 , V_61 -> V_70 - 1 ) ;
if ( V_61 -> V_70 >= V_61 -> V_62 )
return - V_53 ;
F_56 ( V_61 , 0 ) ;
}
memcpy ( V_61 -> V_67 , V_83 , V_63 ) ;
F_76 ( V_61 , V_61 -> V_70 - 1 ) ;
if ( V_61 -> V_70 < V_61 -> V_62 )
F_56 ( V_61 , 0 ) ;
return 0 ;
}
static void F_82 ( struct V_61 * V_61 )
{
if ( V_61 -> V_67 != V_61 -> V_68 )
F_76 ( V_61 , V_61 -> V_70 - 1 ) ;
else
F_54 ( V_61 ) ;
while ( V_61 -> V_70 < V_61 -> V_62 ) {
F_56 ( V_61 , 1 ) ;
F_76 ( V_61 , V_61 -> V_70 - 1 ) ;
}
}
static int F_83 ( struct V_61 * V_61 ,
struct V_88 * V_85 , T_5 * type )
{
struct V_84 * V_89 ;
int V_16 ;
if ( ! V_61 -> V_67 ) {
V_16 = F_79 ( V_61 , V_61 -> V_70 ) ;
if ( V_16 )
return V_16 ;
}
V_89 = V_61 -> V_67 ;
V_85 -> V_6 = F_74 ( V_89 -> V_6 ) ;
V_85 -> V_82 = F_74 ( V_89 -> V_82 ) ;
* type = V_89 -> type ;
V_61 -> V_67 += sizeof( struct V_84 ) ;
V_61 -> V_71 -= sizeof( struct V_84 ) ;
if ( V_61 -> V_71 >= sizeof( struct V_84 ) )
return 0 ;
F_54 ( V_61 ) ;
return 0 ;
}
static int F_84 ( struct V_61 * V_61 ,
struct V_88 * V_85 )
{
int V_16 ;
V_16 = F_79 ( V_61 , V_61 -> V_70 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_85 -> V_83 , V_61 -> V_67 , V_63 ) ;
F_54 ( V_61 ) ;
return 0 ;
}
int F_85 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_90 * V_91 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_61 V_61 ;
struct V_7 V_8 ;
struct V_88 * V_89 , * V_92 ;
struct V_93 V_94 ;
T_1 V_95 ;
T_1 V_96 ;
T_1 V_77 ;
T_5 type ;
int V_16 = 0 ;
F_86 ( & V_94 ) ;
if ( ! F_40 ( V_1 ) )
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
V_95 = F_87 ( V_15 , V_13 ) ;
V_96 = F_88 ( V_15 , V_13 ) ;
V_77 = F_89 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( F_16 ( V_1 ) -> V_77 != V_77 ) {
F_17 ( V_75 L_7
L_8 ,
( unsigned long long ) F_16 ( V_1 ) -> V_77 ,
( unsigned long long ) V_77 ) ;
return 0 ;
}
if ( ! V_95 )
return 0 ;
F_51 ( & V_61 , V_1 , V_3 ) ;
V_16 = F_46 ( V_1 ) ;
if ( V_16 )
goto V_97;
V_16 = F_63 ( & V_61 , V_1 , 1 ) ;
if ( V_16 )
goto V_97;
V_16 = F_79 ( & V_61 , 0 ) ;
if ( V_16 )
goto V_98;
V_16 = F_73 ( & V_61 , V_77 ) ;
if ( V_16 )
goto V_98;
while ( V_95 ) {
V_89 = F_90 ( V_99 ,
V_58 ) ;
if ( ! V_89 )
goto V_98;
V_16 = F_83 ( & V_61 , V_89 , & type ) ;
if ( V_16 ) {
F_91 ( V_99 , V_89 ) ;
goto V_98;
}
if ( ! V_89 -> V_82 ) {
F_91 ( V_99 , V_89 ) ;
goto V_98;
}
if ( type == V_87 ) {
F_13 ( & V_91 -> V_100 ) ;
V_16 = F_92 ( V_91 , V_89 ) ;
F_15 ( & V_91 -> V_100 ) ;
if ( V_16 ) {
F_17 ( V_75 L_9
L_10 ) ;
F_91 ( V_99 , V_89 ) ;
goto V_98;
}
} else {
F_57 ( ! V_96 ) ;
V_96 -- ;
V_89 -> V_83 = F_47 ( V_63 , V_58 ) ;
if ( ! V_89 -> V_83 ) {
F_91 (
V_99 , V_89 ) ;
goto V_98;
}
F_13 ( & V_91 -> V_100 ) ;
V_16 = F_92 ( V_91 , V_89 ) ;
V_91 -> V_101 ++ ;
V_91 -> V_102 -> V_103 ( V_91 ) ;
F_15 ( & V_91 -> V_100 ) ;
if ( V_16 ) {
F_17 ( V_75 L_9
L_10 ) ;
F_91 ( V_99 , V_89 ) ;
goto V_98;
}
F_93 ( & V_89 -> V_104 , & V_94 ) ;
}
V_95 -- ;
}
F_54 ( & V_61 ) ;
F_94 (e, n, &bitmaps, list) {
F_95 ( & V_89 -> V_104 ) ;
V_16 = F_84 ( & V_61 , V_89 ) ;
if ( V_16 )
goto V_98;
}
F_59 ( & V_61 ) ;
V_16 = 1 ;
V_97:
F_53 ( & V_61 ) ;
return V_16 ;
V_98:
F_59 ( & V_61 ) ;
F_96 ( V_91 ) ;
goto V_97;
}
int F_97 ( struct V_105 * V_22 ,
struct V_27 * V_28 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_2 * V_3 = V_22 -> V_107 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 = 0 ;
bool V_108 ;
T_1 V_109 = F_98 ( & V_28 -> V_110 ) ;
if ( F_99 ( V_22 ) )
return 0 ;
F_13 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_33 != V_111 ) {
F_15 ( & V_28 -> V_31 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_31 ) ;
V_5 = F_100 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_12 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_101 ( V_5 ) ;
return 0 ;
}
F_13 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_33 != V_111 ) {
F_15 ( & V_28 -> V_31 ) ;
goto V_97;
}
F_15 ( & V_28 -> V_31 ) ;
V_16 = F_85 ( V_22 -> V_107 , V_1 , V_91 ,
V_5 , V_28 -> V_8 . V_17 ) ;
F_101 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_97;
F_13 ( & V_91 -> V_100 ) ;
V_108 = ( V_91 -> V_112 == ( V_28 -> V_8 . V_6 - V_109 -
V_28 -> V_113 ) ) ;
F_15 ( & V_91 -> V_100 ) ;
if ( ! V_108 ) {
F_96 ( V_91 ) ;
F_17 ( V_75 L_11
L_12 , V_28 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_97:
if ( V_16 < 0 ) {
F_13 ( & V_28 -> V_31 ) ;
V_28 -> V_33 = V_34 ;
F_15 ( & V_28 -> V_31 ) ;
V_16 = 0 ;
F_17 ( V_75 L_13
L_14 , V_28 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
int F_102 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_90 * V_91 ,
struct V_27 * V_28 ,
struct V_36 * V_37 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_114 * V_115 ;
struct V_93 * V_116 , * V_92 ;
struct V_117 * V_118 = NULL ;
struct V_119 * V_120 = NULL ;
struct V_121 * V_122 = NULL ;
struct V_61 V_61 ;
struct V_93 V_123 ;
struct V_7 V_8 ;
T_1 V_124 , V_125 , V_126 ;
int V_127 = 0 ;
int V_94 = 0 ;
int V_16 ;
int V_128 = - 1 ;
F_86 ( & V_123 ) ;
if ( ! F_40 ( V_1 ) )
return - 1 ;
F_51 ( & V_61 , V_1 , V_3 ) ;
if ( V_28 && ! F_103 ( & V_28 -> V_129 ) )
V_120 = F_104 ( V_28 -> V_129 . V_130 ,
struct V_119 ,
V_131 ) ;
V_122 = V_3 -> V_22 -> V_132 ;
F_63 ( & V_61 , V_1 , 0 ) ;
F_105 ( & F_16 ( V_1 ) -> V_133 , 0 , F_40 ( V_1 ) - 1 ,
0 , & V_118 , V_58 ) ;
if ( V_28 )
V_124 = V_28 -> V_8 . V_17 ;
V_115 = F_106 ( & V_91 -> V_134 ) ;
if ( ! V_115 && V_120 ) {
V_115 = F_106 ( & V_120 -> V_3 ) ;
V_120 = NULL ;
}
if ( V_61 . V_66 &&
( V_61 . V_62 * sizeof( T_2 ) ) >= V_63 ) {
F_44 ( 1 ) ;
goto V_135;
}
F_71 ( & V_61 , V_37 -> V_44 ) ;
while ( V_115 ) {
struct V_88 * V_89 ;
V_89 = F_107 ( V_115 , struct V_88 , V_136 ) ;
V_127 ++ ;
V_16 = F_80 ( & V_61 , V_89 -> V_6 , V_89 -> V_82 ,
V_89 -> V_83 ) ;
if ( V_16 )
goto V_135;
if ( V_89 -> V_83 ) {
F_93 ( & V_89 -> V_104 , & V_123 ) ;
V_94 ++ ;
}
V_115 = F_108 ( V_115 ) ;
if ( ! V_115 && V_120 ) {
V_115 = F_106 ( & V_120 -> V_3 ) ;
V_120 = NULL ;
}
}
while ( V_28 && ( V_124 < V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 ) ) {
V_16 = F_109 ( V_122 , V_124 , & V_124 , & V_125 ,
V_137 ) ;
if ( V_16 ) {
V_16 = 0 ;
break;
}
if ( V_124 >= V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 )
break;
V_126 = V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 - V_124 ;
V_126 = F_110 ( V_126 , V_125 + 1 - V_124 ) ;
V_127 ++ ;
V_16 = F_80 ( & V_61 , V_124 , V_126 , NULL ) ;
if ( V_16 )
goto V_135;
V_124 = V_125 + 1 ;
}
F_111 (pos, n, &bitmap_list) {
struct V_88 * V_85 =
F_104 ( V_116 , struct V_88 , V_104 ) ;
V_16 = F_81 ( & V_61 , V_85 -> V_83 ) ;
if ( V_16 )
goto V_135;
F_95 ( & V_85 -> V_104 ) ;
}
F_82 ( & V_61 ) ;
V_16 = F_112 ( V_3 , V_1 , V_61 . V_64 , V_61 . V_62 ,
0 , F_40 ( V_1 ) , & V_118 ) ;
F_59 ( & V_61 ) ;
F_113 ( & F_16 ( V_1 ) -> V_133 , 0 ,
F_40 ( V_1 ) - 1 , & V_118 , V_58 ) ;
if ( V_16 )
goto V_97;
V_16 = F_114 ( V_1 -> V_24 ) ;
if ( V_16 )
goto V_97;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_37 , V_3 , & V_8 , V_5 , 0 , 1 ) ;
if ( V_16 < 0 ) {
F_115 ( & F_16 ( V_1 ) -> V_133 , 0 , V_1 -> V_138 - 1 ,
V_137 | V_139 , 0 , 0 , NULL ,
V_58 ) ;
goto V_97;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_140 ;
F_57 ( ! V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_116 ( V_15 , & V_140 , V_5 -> V_21 [ 0 ] ) ;
if ( V_140 . V_17 != V_18 ||
V_140 . V_6 != V_6 ) {
F_115 ( & F_16 ( V_1 ) -> V_133 , 0 ,
V_1 -> V_138 - 1 ,
V_137 | V_139 , 0 , 0 ,
NULL , V_58 ) ;
F_4 ( V_5 ) ;
goto V_97;
}
}
F_16 ( V_1 ) -> V_77 = V_37 -> V_44 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_117 ( V_15 , V_13 , V_127 ) ;
F_118 ( V_15 , V_13 , V_94 ) ;
F_119 ( V_15 , V_13 , V_37 -> V_44 ) ;
F_32 ( V_15 ) ;
F_4 ( V_5 ) ;
V_128 = 0 ;
V_97:
F_53 ( & V_61 ) ;
if ( V_128 ) {
F_120 ( V_1 -> V_24 ) ;
F_16 ( V_1 ) -> V_77 = 0 ;
}
F_45 ( V_37 , V_3 , V_1 ) ;
return V_128 ;
V_135:
F_111 (pos, n, &bitmap_list) {
struct V_88 * V_85 =
F_104 ( V_116 , struct V_88 , V_104 ) ;
F_95 ( & V_85 -> V_104 ) ;
}
F_59 ( & V_61 ) ;
F_113 ( & F_16 ( V_1 ) -> V_133 , 0 ,
F_40 ( V_1 ) - 1 , & V_118 , V_58 ) ;
goto V_97;
}
int F_121 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_107 ;
F_13 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_33 < V_141 ) {
F_15 ( & V_28 -> V_31 ) ;
return 0 ;
}
F_15 ( & V_28 -> V_31 ) ;
V_1 = F_12 ( V_3 , V_28 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_102 ( V_3 , V_1 , V_91 , V_28 , V_37 ,
V_5 , V_28 -> V_8 . V_17 ) ;
if ( V_16 ) {
F_13 ( & V_28 -> V_31 ) ;
V_28 -> V_33 = V_142 ;
F_15 ( & V_28 -> V_31 ) ;
V_16 = 0 ;
#ifdef F_122
F_17 ( V_75 L_15
L_14 , V_28 -> V_8 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_123 ( T_1 V_143 , T_2 V_144 ,
T_1 V_6 )
{
F_57 ( V_6 < V_143 ) ;
V_6 -= V_143 ;
return ( unsigned long ) ( F_124 ( V_6 , V_144 ) ) ;
}
static inline unsigned long F_125 ( T_1 V_82 , T_2 V_144 )
{
return ( unsigned long ) ( F_124 ( V_82 , V_144 ) ) ;
}
static inline T_1 F_126 ( struct V_90 * V_91 ,
T_1 V_6 )
{
T_1 V_143 ;
T_1 V_145 ;
V_145 = V_146 * V_91 -> V_144 ;
V_143 = V_6 - V_91 -> V_124 ;
V_143 = F_127 ( V_143 , V_145 ) ;
V_143 *= V_145 ;
V_143 += V_91 -> V_124 ;
return V_143 ;
}
static int F_128 ( struct V_147 * V_3 , T_1 V_6 ,
struct V_114 * V_115 , int V_83 )
{
struct V_114 * * V_148 = & V_3 -> V_114 ;
struct V_114 * V_149 = NULL ;
struct V_88 * V_150 ;
while ( * V_148 ) {
V_149 = * V_148 ;
V_150 = F_107 ( V_149 , struct V_88 , V_136 ) ;
if ( V_6 < V_150 -> V_6 ) {
V_148 = & ( * V_148 ) -> V_151 ;
} else if ( V_6 > V_150 -> V_6 ) {
V_148 = & ( * V_148 ) -> V_152 ;
} else {
if ( V_83 ) {
if ( V_150 -> V_83 ) {
F_129 ( 1 ) ;
return - V_153 ;
}
V_148 = & ( * V_148 ) -> V_152 ;
} else {
if ( ! V_150 -> V_83 ) {
F_129 ( 1 ) ;
return - V_153 ;
}
V_148 = & ( * V_148 ) -> V_151 ;
}
}
}
F_130 ( V_115 , V_149 , V_148 ) ;
F_131 ( V_115 , V_3 ) ;
return 0 ;
}
static struct V_88 *
F_132 ( struct V_90 * V_91 ,
T_1 V_6 , int V_154 , int V_155 )
{
struct V_114 * V_92 = V_91 -> V_134 . V_114 ;
struct V_88 * V_85 , * V_156 = NULL ;
while ( 1 ) {
if ( ! V_92 ) {
V_85 = NULL ;
break;
}
V_85 = F_107 ( V_92 , struct V_88 , V_136 ) ;
V_156 = V_85 ;
if ( V_6 < V_85 -> V_6 )
V_92 = V_92 -> V_151 ;
else if ( V_6 > V_85 -> V_6 )
V_92 = V_92 -> V_152 ;
else
break;
}
if ( V_154 ) {
if ( ! V_85 )
return NULL ;
if ( V_85 -> V_83 )
return V_85 ;
V_92 = F_108 ( V_92 ) ;
if ( ! V_92 )
return NULL ;
V_85 = F_107 ( V_92 , struct V_88 , V_136 ) ;
if ( V_85 -> V_6 != V_6 )
return NULL ;
F_44 ( ! V_85 -> V_83 ) ;
return V_85 ;
} else if ( V_85 ) {
if ( V_85 -> V_83 ) {
V_92 = & V_85 -> V_136 ;
while ( 1 ) {
V_92 = F_133 ( V_92 ) ;
if ( ! V_92 )
break;
V_156 = F_107 ( V_92 , struct V_88 ,
V_136 ) ;
if ( ! V_156 -> V_83 ) {
if ( V_156 -> V_6 + V_156 -> V_82 > V_6 )
V_85 = V_156 ;
break;
}
}
}
return V_85 ;
}
if ( ! V_156 )
return NULL ;
V_85 = V_156 ;
if ( V_85 -> V_6 > V_6 ) {
V_92 = F_133 ( & V_85 -> V_136 ) ;
if ( V_92 ) {
V_85 = F_107 ( V_92 , struct V_88 ,
V_136 ) ;
F_57 ( V_85 -> V_6 > V_6 ) ;
} else {
if ( V_155 )
return V_85 ;
else
return NULL ;
}
}
if ( V_85 -> V_83 ) {
V_92 = & V_85 -> V_136 ;
while ( 1 ) {
V_92 = F_133 ( V_92 ) ;
if ( ! V_92 )
break;
V_156 = F_107 ( V_92 , struct V_88 ,
V_136 ) ;
if ( ! V_156 -> V_83 ) {
if ( V_156 -> V_6 + V_156 -> V_82 > V_6 )
return V_156 ;
break;
}
}
if ( V_85 -> V_6 + V_146 * V_91 -> V_144 > V_6 )
return V_85 ;
} else if ( V_85 -> V_6 + V_85 -> V_82 > V_6 )
return V_85 ;
if ( ! V_155 )
return NULL ;
while ( 1 ) {
if ( V_85 -> V_83 ) {
if ( V_85 -> V_6 + V_146 *
V_91 -> V_144 > V_6 )
break;
} else {
if ( V_85 -> V_6 + V_85 -> V_82 > V_6 )
break;
}
V_92 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_92 )
return NULL ;
V_85 = F_107 ( V_92 , struct V_88 , V_136 ) ;
}
return V_85 ;
}
static inline void
F_134 ( struct V_90 * V_91 ,
struct V_88 * V_150 )
{
F_135 ( & V_150 -> V_136 , & V_91 -> V_134 ) ;
V_91 -> V_157 -- ;
}
static void F_136 ( struct V_90 * V_91 ,
struct V_88 * V_150 )
{
F_134 ( V_91 , V_150 ) ;
V_91 -> V_112 -= V_150 -> V_82 ;
}
static int F_92 ( struct V_90 * V_91 ,
struct V_88 * V_150 )
{
int V_16 = 0 ;
F_57 ( ! V_150 -> V_83 && ! V_150 -> V_82 ) ;
V_16 = F_128 ( & V_91 -> V_134 , V_150 -> V_6 ,
& V_150 -> V_136 , ( V_150 -> V_83 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_91 -> V_112 += V_150 -> V_82 ;
V_91 -> V_157 ++ ;
return V_16 ;
}
static void F_137 ( struct V_90 * V_91 )
{
struct V_27 * V_28 = V_91 -> V_158 ;
T_1 V_159 ;
T_1 V_160 ;
T_1 V_161 ;
T_1 V_71 = V_28 -> V_8 . V_6 ;
T_1 V_162 = V_146 * V_28 -> V_163 ;
int V_164 = F_127 ( V_71 + V_162 - 1 , V_162 ) ;
F_57 ( V_91 -> V_101 > V_164 ) ;
if ( V_71 < 1024 * 1024 * 1024 )
V_159 = V_165 ;
else
V_159 = V_165 *
F_127 ( V_71 , 1024 * 1024 * 1024 ) ;
V_160 = ( V_91 -> V_101 + 1 ) * V_63 ;
if ( V_160 >= V_159 ) {
V_91 -> V_166 = 0 ;
return;
}
V_161 = V_159 - V_160 ;
V_161 = F_138 ( T_1 , V_161 , F_127 ( V_159 , 2 ) ) ;
V_91 -> V_166 =
F_127 ( V_161 , ( sizeof( struct V_88 ) ) ) ;
}
static inline void F_139 ( struct V_90 * V_91 ,
struct V_88 * V_150 ,
T_1 V_6 , T_1 V_82 )
{
unsigned long V_124 , V_167 ;
V_124 = F_123 ( V_150 -> V_6 , V_91 -> V_144 , V_6 ) ;
V_167 = F_125 ( V_82 , V_91 -> V_144 ) ;
F_57 ( V_124 + V_167 > V_146 ) ;
F_140 ( V_150 -> V_83 , V_124 , V_167 ) ;
V_150 -> V_82 -= V_82 ;
}
static void F_141 ( struct V_90 * V_91 ,
struct V_88 * V_150 , T_1 V_6 ,
T_1 V_82 )
{
F_139 ( V_91 , V_150 , V_6 , V_82 ) ;
V_91 -> V_112 -= V_82 ;
}
static void F_142 ( struct V_90 * V_91 ,
struct V_88 * V_150 , T_1 V_6 ,
T_1 V_82 )
{
unsigned long V_124 , V_167 ;
V_124 = F_123 ( V_150 -> V_6 , V_91 -> V_144 , V_6 ) ;
V_167 = F_125 ( V_82 , V_91 -> V_144 ) ;
F_57 ( V_124 + V_167 > V_146 ) ;
F_143 ( V_150 -> V_83 , V_124 , V_167 ) ;
V_150 -> V_82 += V_82 ;
V_91 -> V_112 += V_82 ;
}
static int F_144 ( struct V_90 * V_91 ,
struct V_88 * V_168 , T_1 * V_6 ,
T_1 * V_82 )
{
unsigned long V_169 = 0 ;
unsigned long V_170 , V_72 ;
unsigned long V_171 ;
V_72 = F_123 ( V_168 -> V_6 , V_91 -> V_144 ,
F_145 ( T_1 , * V_6 , V_168 -> V_6 ) ) ;
V_170 = F_125 ( * V_82 , V_91 -> V_144 ) ;
for ( V_72 = F_146 ( V_168 -> V_83 , V_146 , V_72 ) ;
V_72 < V_146 ;
V_72 = F_146 ( V_168 -> V_83 , V_146 , V_72 + 1 ) ) {
V_171 = F_147 ( V_168 -> V_83 ,
V_146 , V_72 ) ;
if ( ( V_171 - V_72 ) >= V_170 ) {
V_169 = V_171 - V_72 ;
break;
}
V_72 = V_171 ;
}
if ( V_169 ) {
* V_6 = ( T_1 ) ( V_72 * V_91 -> V_144 ) + V_168 -> V_6 ;
* V_82 = ( T_1 ) ( V_169 ) * V_91 -> V_144 ;
return 0 ;
}
return - 1 ;
}
static struct V_88 *
F_148 ( struct V_90 * V_91 , T_1 * V_6 , T_1 * V_82 )
{
struct V_88 * V_85 ;
struct V_114 * V_115 ;
int V_16 ;
if ( ! V_91 -> V_134 . V_114 )
return NULL ;
V_85 = F_132 ( V_91 , F_126 ( V_91 , * V_6 ) , 0 , 1 ) ;
if ( ! V_85 )
return NULL ;
for ( V_115 = & V_85 -> V_136 ; V_115 ; V_115 = F_108 ( V_115 ) ) {
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( V_85 -> V_82 < * V_82 )
continue;
if ( V_85 -> V_83 ) {
V_16 = F_144 ( V_91 , V_85 , V_6 , V_82 ) ;
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
static void F_149 ( struct V_90 * V_91 ,
struct V_88 * V_150 , T_1 V_6 )
{
V_150 -> V_6 = F_126 ( V_91 , V_6 ) ;
V_150 -> V_82 = 0 ;
F_86 ( & V_150 -> V_104 ) ;
F_92 ( V_91 , V_150 ) ;
V_91 -> V_101 ++ ;
V_91 -> V_102 -> V_103 ( V_91 ) ;
}
static void F_150 ( struct V_90 * V_91 ,
struct V_88 * V_168 )
{
F_136 ( V_91 , V_168 ) ;
F_50 ( V_168 -> V_83 ) ;
F_91 ( V_99 , V_168 ) ;
V_91 -> V_101 -- ;
V_91 -> V_102 -> V_103 ( V_91 ) ;
}
static T_6 int F_151 ( struct V_90 * V_91 ,
struct V_88 * V_168 ,
T_1 * V_6 , T_1 * V_82 )
{
T_1 V_125 ;
T_1 V_172 , V_173 ;
int V_16 ;
V_174:
V_125 = V_168 -> V_6 + ( T_1 ) ( V_146 * V_91 -> V_144 ) - 1 ;
V_172 = * V_6 ;
V_173 = * V_82 ;
V_173 = F_110 ( V_173 , V_125 - V_172 + 1 ) ;
V_16 = F_144 ( V_91 , V_168 , & V_172 , & V_173 ) ;
F_57 ( V_16 < 0 || V_172 != * V_6 ) ;
if ( * V_6 > V_168 -> V_6 && * V_6 + * V_82 > V_125 ) {
F_141 ( V_91 , V_168 , * V_6 , V_125 - * V_6 + 1 ) ;
* V_82 -= V_125 - * V_6 + 1 ;
* V_6 = V_125 + 1 ;
} else if ( * V_6 >= V_168 -> V_6 && * V_6 + * V_82 <= V_125 ) {
F_141 ( V_91 , V_168 , * V_6 , * V_82 ) ;
* V_82 = 0 ;
}
if ( * V_82 ) {
struct V_114 * V_130 = F_108 ( & V_168 -> V_136 ) ;
if ( ! V_168 -> V_82 )
F_150 ( V_91 , V_168 ) ;
if ( ! V_130 )
return - V_175 ;
V_168 = F_107 ( V_130 , struct V_88 ,
V_136 ) ;
if ( ! V_168 -> V_83 )
return - V_176 ;
V_172 = * V_6 ;
V_173 = * V_82 ;
V_16 = F_144 ( V_91 , V_168 , & V_172 ,
& V_173 ) ;
if ( V_16 < 0 || V_172 != * V_6 )
return - V_176 ;
goto V_174;
} else if ( ! V_168 -> V_82 )
F_150 ( V_91 , V_168 ) ;
return 0 ;
}
static T_1 F_152 ( struct V_90 * V_91 ,
struct V_88 * V_150 , T_1 V_6 ,
T_1 V_82 )
{
T_1 V_177 = 0 ;
T_1 V_125 ;
V_125 = V_150 -> V_6 + ( T_1 ) ( V_146 * V_91 -> V_144 ) ;
V_177 = F_110 ( V_125 - V_6 , V_82 ) ;
F_142 ( V_91 , V_150 , V_6 , V_177 ) ;
return V_177 ;
}
static bool F_153 ( struct V_90 * V_91 ,
struct V_88 * V_150 )
{
struct V_27 * V_28 = V_91 -> V_158 ;
if ( V_91 -> V_157 < V_91 -> V_166 ) {
if ( V_150 -> V_82 <= V_28 -> V_163 * 4 ) {
if ( V_91 -> V_157 * 2 <= V_91 -> V_166 )
return false ;
} else {
return false ;
}
}
if ( V_146 * V_28 -> V_163 >
V_28 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_154 ( struct V_90 * V_91 ,
struct V_88 * V_150 )
{
struct V_88 * V_168 ;
struct V_27 * V_28 = NULL ;
int V_178 = 0 ;
T_1 V_82 , V_6 , V_179 ;
int V_16 ;
V_82 = V_150 -> V_82 ;
V_6 = V_150 -> V_6 ;
if ( ! V_91 -> V_102 -> F_153 ( V_91 , V_150 ) )
return 0 ;
if ( V_91 -> V_102 == & V_180 )
V_28 = V_91 -> V_158 ;
V_174:
if ( V_28 && ! F_103 ( & V_28 -> V_129 ) ) {
struct V_119 * V_120 ;
struct V_114 * V_115 ;
struct V_88 * V_85 ;
V_120 = F_104 ( V_28 -> V_129 . V_130 ,
struct V_119 ,
V_131 ) ;
F_13 ( & V_120 -> V_31 ) ;
V_115 = F_106 ( & V_120 -> V_3 ) ;
if ( ! V_115 ) {
F_15 ( & V_120 -> V_31 ) ;
goto V_181;
}
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( ! V_85 -> V_83 ) {
F_15 ( & V_120 -> V_31 ) ;
goto V_181;
}
if ( V_85 -> V_6 == F_126 ( V_91 , V_6 ) ) {
V_179 = F_152 ( V_91 , V_85 ,
V_6 , V_82 ) ;
V_82 -= V_179 ;
V_6 += V_179 ;
}
F_15 ( & V_120 -> V_31 ) ;
if ( ! V_82 ) {
V_16 = 1 ;
goto V_97;
}
}
V_181:
V_168 = F_132 ( V_91 , F_126 ( V_91 , V_6 ) ,
1 , 0 ) ;
if ( ! V_168 ) {
F_57 ( V_178 ) ;
goto V_182;
}
V_179 = F_152 ( V_91 , V_168 , V_6 , V_82 ) ;
V_82 -= V_179 ;
V_6 += V_179 ;
V_178 = 0 ;
if ( ! V_82 ) {
V_16 = 1 ;
goto V_97;
} else
goto V_174;
V_182:
if ( V_150 && V_150 -> V_83 ) {
F_149 ( V_91 , V_150 , V_6 ) ;
V_178 = 1 ;
V_150 = NULL ;
goto V_174;
} else {
F_15 ( & V_91 -> V_100 ) ;
if ( ! V_150 ) {
V_150 = F_90 ( V_99 ,
V_58 ) ;
if ( ! V_150 ) {
F_13 ( & V_91 -> V_100 ) ;
V_16 = - V_59 ;
goto V_97;
}
}
V_150 -> V_83 = F_47 ( V_63 , V_58 ) ;
F_13 ( & V_91 -> V_100 ) ;
if ( ! V_150 -> V_83 ) {
V_16 = - V_59 ;
goto V_97;
}
goto V_174;
}
V_97:
if ( V_150 ) {
if ( V_150 -> V_83 )
F_50 ( V_150 -> V_83 ) ;
F_91 ( V_99 , V_150 ) ;
}
return V_16 ;
}
static bool F_155 ( struct V_90 * V_91 ,
struct V_88 * V_150 , bool V_183 )
{
struct V_88 * V_184 ;
struct V_88 * V_185 ;
bool V_186 = false ;
T_1 V_6 = V_150 -> V_6 ;
T_1 V_82 = V_150 -> V_82 ;
V_185 = F_132 ( V_91 , V_6 + V_82 , 0 , 0 ) ;
if ( V_185 && F_133 ( & V_185 -> V_136 ) )
V_184 = F_107 ( F_133 ( & V_185 -> V_136 ) ,
struct V_88 , V_136 ) ;
else
V_184 = F_132 ( V_91 , V_6 - 1 , 0 , 0 ) ;
if ( V_185 && ! V_185 -> V_83 ) {
if ( V_183 )
F_136 ( V_91 , V_185 ) ;
else
F_134 ( V_91 , V_185 ) ;
V_150 -> V_82 += V_185 -> V_82 ;
F_91 ( V_99 , V_185 ) ;
V_186 = true ;
}
if ( V_184 && ! V_184 -> V_83 &&
V_184 -> V_6 + V_184 -> V_82 == V_6 ) {
if ( V_183 )
F_136 ( V_91 , V_184 ) ;
else
F_134 ( V_91 , V_184 ) ;
V_150 -> V_6 = V_184 -> V_6 ;
V_150 -> V_82 += V_184 -> V_82 ;
F_91 ( V_99 , V_184 ) ;
V_186 = true ;
}
return V_186 ;
}
int F_156 ( struct V_90 * V_91 ,
T_1 V_6 , T_1 V_82 )
{
struct V_88 * V_150 ;
int V_16 = 0 ;
V_150 = F_90 ( V_99 , V_58 ) ;
if ( ! V_150 )
return - V_59 ;
V_150 -> V_6 = V_6 ;
V_150 -> V_82 = V_82 ;
F_13 ( & V_91 -> V_100 ) ;
if ( F_155 ( V_91 , V_150 , true ) )
goto V_187;
V_16 = F_154 ( V_91 , V_150 ) ;
if ( V_16 < 0 ) {
goto V_97;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_97;
}
V_187:
V_16 = F_92 ( V_91 , V_150 ) ;
if ( V_16 )
F_91 ( V_99 , V_150 ) ;
V_97:
F_15 ( & V_91 -> V_100 ) ;
if ( V_16 ) {
F_17 ( V_188 L_16 , V_16 ) ;
F_57 ( V_16 == - V_153 ) ;
}
return V_16 ;
}
int F_157 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_82 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_150 ;
struct V_88 * V_189 = NULL ;
int V_16 = 0 ;
F_13 ( & V_91 -> V_100 ) ;
V_174:
V_150 = F_132 ( V_91 , V_6 , 0 , 0 ) ;
if ( ! V_150 ) {
V_150 = F_132 ( V_91 , F_126 ( V_91 , V_6 ) ,
1 , 0 ) ;
if ( ! V_150 ) {
goto V_190;
}
}
if ( V_150 -> V_82 < V_82 && F_108 ( & V_150 -> V_136 ) ) {
T_1 V_125 ;
V_189 = F_107 ( F_108 ( & V_150 -> V_136 ) ,
struct V_88 ,
V_136 ) ;
if ( V_189 -> V_83 )
V_125 = V_189 -> V_6 +
V_146 * V_91 -> V_144 - 1 ;
else
V_125 = V_189 -> V_6 + V_189 -> V_82 ;
if ( V_189 -> V_82 < V_82 ||
V_189 -> V_6 > V_6 || V_6 > V_125 ) {
F_17 ( V_188 L_17
L_18 ,
( unsigned long long ) V_150 -> V_6 ,
( unsigned long long ) V_150 -> V_82 ,
( unsigned long long ) V_82 ) ;
F_44 ( 1 ) ;
V_16 = - V_175 ;
goto V_190;
}
V_150 = V_189 ;
}
if ( V_150 -> V_82 == V_82 ) {
F_136 ( V_91 , V_150 ) ;
if ( V_150 -> V_83 ) {
F_50 ( V_150 -> V_83 ) ;
V_91 -> V_101 -- ;
}
F_91 ( V_99 , V_150 ) ;
V_16 = 0 ;
goto V_190;
}
if ( ! V_150 -> V_83 && V_150 -> V_6 == V_6 ) {
F_136 ( V_91 , V_150 ) ;
V_150 -> V_6 += V_82 ;
V_150 -> V_82 -= V_82 ;
V_16 = F_92 ( V_91 , V_150 ) ;
F_44 ( V_16 ) ;
goto V_190;
}
if ( ! V_150 -> V_83 && V_150 -> V_6 <= V_6 &&
V_150 -> V_6 + V_150 -> V_82 >= V_6 + V_82 ) {
T_1 V_191 = V_150 -> V_6 ;
F_136 ( V_91 , V_150 ) ;
if ( V_6 + V_82 < V_150 -> V_6 + V_150 -> V_82 ) {
T_1 V_192 = V_150 -> V_6 + V_150 -> V_82 ;
V_150 -> V_6 = V_6 + V_82 ;
V_150 -> V_82 = V_192 - V_150 -> V_6 ;
V_16 = F_92 ( V_91 , V_150 ) ;
F_44 ( V_16 ) ;
if ( V_16 )
goto V_190;
} else {
F_91 ( V_99 , V_150 ) ;
}
F_15 ( & V_91 -> V_100 ) ;
V_16 = F_158 ( V_28 , V_191 ,
V_6 - V_191 ) ;
F_44 ( V_16 ) ;
goto V_97;
}
V_16 = F_151 ( V_91 , V_150 , & V_6 , & V_82 ) ;
if ( V_16 == - V_176 )
goto V_174;
F_57 ( V_16 ) ;
V_190:
F_15 ( & V_91 -> V_100 ) ;
V_97:
return V_16 ;
}
void F_159 ( struct V_27 * V_28 ,
T_1 V_82 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_150 ;
struct V_114 * V_92 ;
int V_167 = 0 ;
for ( V_92 = F_106 ( & V_91 -> V_134 ) ; V_92 ; V_92 = F_108 ( V_92 ) ) {
V_150 = F_107 ( V_92 , struct V_88 , V_136 ) ;
if ( V_150 -> V_82 >= V_82 )
V_167 ++ ;
F_17 ( V_188 L_19 ,
( unsigned long long ) V_150 -> V_6 ,
( unsigned long long ) V_150 -> V_82 ,
( V_150 -> V_83 ) ? L_20 : L_21 ) ;
}
F_17 ( V_32 L_22 ,
F_103 ( & V_28 -> V_129 ) ? L_21 : L_20 ) ;
F_17 ( V_32 L_23
L_24 , V_167 ) ;
}
void F_160 ( struct V_27 * V_28 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
F_161 ( & V_91 -> V_100 ) ;
V_91 -> V_144 = V_28 -> V_163 ;
V_91 -> V_124 = V_28 -> V_8 . V_17 ;
V_91 -> V_158 = V_28 ;
V_91 -> V_102 = & V_180 ;
V_91 -> V_166 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_88 ) ;
}
static int
F_162 (
struct V_27 * V_28 ,
struct V_119 * V_120 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 ;
struct V_114 * V_115 ;
F_13 ( & V_120 -> V_31 ) ;
if ( V_120 -> V_28 != V_28 )
goto V_97;
V_120 -> V_28 = NULL ;
V_120 -> V_193 = 0 ;
F_95 ( & V_120 -> V_131 ) ;
V_115 = F_106 ( & V_120 -> V_3 ) ;
while ( V_115 ) {
bool V_83 ;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
V_115 = F_108 ( & V_85 -> V_136 ) ;
F_135 ( & V_85 -> V_136 , & V_120 -> V_3 ) ;
V_83 = ( V_85 -> V_83 != NULL ) ;
if ( ! V_83 )
F_155 ( V_91 , V_85 , false ) ;
F_128 ( & V_91 -> V_134 ,
V_85 -> V_6 , & V_85 -> V_136 , V_83 ) ;
}
V_120 -> V_3 = V_194 ;
V_97:
F_15 ( & V_120 -> V_31 ) ;
F_163 ( V_28 ) ;
return 0 ;
}
void F_164 ( struct V_90 * V_91 )
{
struct V_88 * V_150 ;
struct V_114 * V_115 ;
while ( ( V_115 = F_165 ( & V_91 -> V_134 ) ) != NULL ) {
V_150 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( ! V_150 -> V_83 ) {
F_136 ( V_91 , V_150 ) ;
F_91 ( V_99 , V_150 ) ;
} else {
F_150 ( V_91 , V_150 ) ;
}
if ( F_166 () ) {
F_15 ( & V_91 -> V_100 ) ;
F_167 () ;
F_13 ( & V_91 -> V_100 ) ;
}
}
}
void F_96 ( struct V_90 * V_91 )
{
F_13 ( & V_91 -> V_100 ) ;
F_164 ( V_91 ) ;
F_15 ( & V_91 -> V_100 ) ;
}
void F_168 ( struct V_27 * V_28 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_119 * V_120 ;
struct V_93 * V_195 ;
F_13 ( & V_91 -> V_100 ) ;
while ( ( V_195 = V_28 -> V_129 . V_130 ) !=
& V_28 -> V_129 ) {
V_120 = F_104 ( V_195 , struct V_119 ,
V_131 ) ;
F_44 ( V_120 -> V_28 != V_28 ) ;
F_162 ( V_28 , V_120 ) ;
if ( F_166 () ) {
F_15 ( & V_91 -> V_100 ) ;
F_167 () ;
F_13 ( & V_91 -> V_100 ) ;
}
}
F_164 ( V_91 ) ;
F_15 ( & V_91 -> V_100 ) ;
}
T_1 F_169 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_82 , T_1 V_196 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 = NULL ;
T_1 V_197 = V_82 + V_196 ;
T_1 V_16 = 0 ;
F_13 ( & V_91 -> V_100 ) ;
V_85 = F_148 ( V_91 , & V_6 , & V_197 ) ;
if ( ! V_85 )
goto V_97;
V_16 = V_6 ;
if ( V_85 -> V_83 ) {
F_141 ( V_91 , V_85 , V_6 , V_82 ) ;
if ( ! V_85 -> V_82 )
F_150 ( V_91 , V_85 ) ;
} else {
F_136 ( V_91 , V_85 ) ;
V_85 -> V_6 += V_82 ;
V_85 -> V_82 -= V_82 ;
if ( ! V_85 -> V_82 )
F_91 ( V_99 , V_85 ) ;
else
F_92 ( V_91 , V_85 ) ;
}
V_97:
F_15 ( & V_91 -> V_100 ) ;
return V_16 ;
}
int F_170 (
struct V_27 * V_28 ,
struct V_119 * V_120 )
{
struct V_90 * V_91 ;
int V_16 ;
F_13 ( & V_120 -> V_31 ) ;
if ( ! V_28 ) {
V_28 = V_120 -> V_28 ;
if ( ! V_28 ) {
F_15 ( & V_120 -> V_31 ) ;
return 0 ;
}
} else if ( V_120 -> V_28 != V_28 ) {
F_15 ( & V_120 -> V_31 ) ;
return 0 ;
}
F_171 ( & V_28 -> V_167 ) ;
F_15 ( & V_120 -> V_31 ) ;
V_91 = V_28 -> V_106 ;
F_13 ( & V_91 -> V_100 ) ;
V_16 = F_162 ( V_28 , V_120 ) ;
F_15 ( & V_91 -> V_100 ) ;
F_163 ( V_28 ) ;
return V_16 ;
}
static T_1 F_172 ( struct V_27 * V_28 ,
struct V_119 * V_120 ,
struct V_88 * V_85 ,
T_1 V_82 , T_1 V_198 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
int V_128 ;
T_1 V_172 = V_120 -> V_193 ;
T_1 V_173 = V_82 ;
T_1 V_16 = 0 ;
V_172 = V_198 ;
V_173 = V_82 ;
V_128 = F_144 ( V_91 , V_85 , & V_172 , & V_173 ) ;
if ( V_128 )
return 0 ;
V_16 = V_172 ;
F_139 ( V_91 , V_85 , V_16 , V_82 ) ;
return V_16 ;
}
T_1 F_173 ( struct V_27 * V_28 ,
struct V_119 * V_120 , T_1 V_82 ,
T_1 V_198 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 = NULL ;
struct V_114 * V_115 ;
T_1 V_16 = 0 ;
F_13 ( & V_120 -> V_31 ) ;
if ( V_82 > V_120 -> V_199 )
goto V_97;
if ( V_120 -> V_28 != V_28 )
goto V_97;
V_115 = F_106 ( & V_120 -> V_3 ) ;
if ( ! V_115 )
goto V_97;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
while( 1 ) {
if ( V_85 -> V_82 < V_82 ||
( ! V_85 -> V_83 && V_85 -> V_6 < V_198 ) ) {
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 )
break;
V_85 = F_107 ( V_115 , struct V_88 ,
V_136 ) ;
continue;
}
if ( V_85 -> V_83 ) {
V_16 = F_172 ( V_28 ,
V_120 , V_85 , V_82 ,
V_198 ) ;
if ( V_16 == 0 ) {
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 )
break;
V_85 = F_107 ( V_115 , struct V_88 ,
V_136 ) ;
continue;
}
} else {
V_16 = V_85 -> V_6 ;
V_85 -> V_6 += V_82 ;
V_85 -> V_82 -= V_82 ;
}
if ( V_85 -> V_82 == 0 )
F_135 ( & V_85 -> V_136 , & V_120 -> V_3 ) ;
break;
}
V_97:
F_15 ( & V_120 -> V_31 ) ;
if ( ! V_16 )
return 0 ;
F_13 ( & V_91 -> V_100 ) ;
V_91 -> V_112 -= V_82 ;
if ( V_85 -> V_82 == 0 ) {
V_91 -> V_157 -- ;
if ( V_85 -> V_83 ) {
F_50 ( V_85 -> V_83 ) ;
V_91 -> V_101 -- ;
V_91 -> V_102 -> V_103 ( V_91 ) ;
}
F_91 ( V_99 , V_85 ) ;
}
F_15 ( & V_91 -> V_100 ) ;
return V_16 ;
}
static int F_174 ( struct V_27 * V_28 ,
struct V_88 * V_85 ,
struct V_119 * V_120 ,
T_1 V_6 , T_1 V_82 , T_1 V_200 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
unsigned long V_171 ;
unsigned long V_72 ;
unsigned long V_201 ;
unsigned long V_202 ;
unsigned long V_169 ;
unsigned long V_124 = 0 ;
unsigned long V_203 = 0 ;
int V_16 ;
bool V_204 = false ;
V_72 = F_123 ( V_85 -> V_6 , V_28 -> V_163 ,
F_145 ( T_1 , V_6 , V_85 -> V_6 ) ) ;
V_201 = F_125 ( V_82 , V_28 -> V_163 ) ;
V_202 = F_125 ( V_200 , V_28 -> V_163 ) ;
V_174:
V_169 = 0 ;
for ( V_72 = F_146 ( V_85 -> V_83 , V_146 , V_72 ) ;
V_72 < V_146 ;
V_72 = F_146 ( V_85 -> V_83 , V_146 , V_72 + 1 ) ) {
V_171 = F_147 ( V_85 -> V_83 ,
V_146 , V_72 ) ;
if ( V_171 - V_72 >= V_201 ) {
V_169 = V_171 - V_72 ;
break;
}
V_72 = V_171 ;
}
if ( ! V_169 )
return - V_53 ;
if ( ! V_204 ) {
V_124 = V_72 ;
V_120 -> V_199 = 0 ;
V_204 = true ;
}
V_203 += V_169 ;
if ( V_120 -> V_199 < V_169 * V_28 -> V_163 )
V_120 -> V_199 = V_169 * V_28 -> V_163 ;
if ( V_203 < V_202 ) {
V_72 = F_146 ( V_85 -> V_83 , V_146 , V_171 ) ;
if ( V_72 - V_124 > V_202 * 2 ) {
V_203 = 0 ;
V_120 -> V_199 = 0 ;
V_204 = false ;
}
goto V_174;
}
V_120 -> V_193 = V_124 * V_28 -> V_163 +
V_85 -> V_6 ;
F_135 ( & V_85 -> V_136 , & V_91 -> V_134 ) ;
V_16 = F_128 ( & V_120 -> V_3 , V_85 -> V_6 ,
& V_85 -> V_136 , 1 ) ;
F_57 ( V_16 ) ;
return 0 ;
}
static T_6 int
F_175 ( struct V_27 * V_28 ,
struct V_119 * V_120 ,
struct V_93 * V_94 , T_1 V_6 , T_1 V_82 ,
T_1 V_200 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_205 = NULL ;
struct V_88 * V_85 = NULL ;
struct V_88 * V_156 = NULL ;
struct V_88 * V_206 ;
struct V_114 * V_115 ;
T_1 V_193 ;
T_1 V_207 ;
T_1 V_208 ;
T_1 V_209 = 128 * 1024 ;
V_85 = F_132 ( V_91 , V_6 , 0 , 1 ) ;
if ( ! V_85 )
return - V_53 ;
while ( V_85 -> V_83 ) {
if ( F_103 ( & V_85 -> V_104 ) )
F_93 ( & V_85 -> V_104 , V_94 ) ;
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 )
return - V_53 ;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
}
V_193 = V_85 -> V_6 ;
V_207 = V_85 -> V_82 ;
V_208 = V_85 -> V_82 ;
V_205 = V_85 ;
V_206 = V_85 ;
V_156 = V_85 ;
while ( V_207 <= V_200 ) {
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 )
return - V_53 ;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( V_85 -> V_83 ) {
if ( F_103 ( & V_85 -> V_104 ) )
F_93 ( & V_85 -> V_104 , V_94 ) ;
continue;
}
if ( V_85 -> V_6 - ( V_156 -> V_6 + V_156 -> V_82 ) > V_209 ||
V_85 -> V_6 - V_193 > ( V_200 * 2 ) ) {
V_205 = V_85 ;
V_193 = V_85 -> V_6 ;
V_207 = V_85 -> V_82 ;
V_206 = V_85 ;
V_208 = V_85 -> V_82 ;
} else {
V_206 = V_85 ;
V_207 += V_85 -> V_82 ;
if ( V_85 -> V_82 > V_208 )
V_208 = V_85 -> V_82 ;
}
V_156 = V_85 ;
}
V_120 -> V_193 = V_205 -> V_6 ;
V_115 = & V_205 -> V_136 ;
do {
int V_16 ;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( V_85 -> V_83 )
continue;
F_135 ( & V_85 -> V_136 , & V_91 -> V_134 ) ;
V_16 = F_128 ( & V_120 -> V_3 , V_85 -> V_6 ,
& V_85 -> V_136 , 0 ) ;
F_57 ( V_16 ) ;
} while ( V_115 && V_85 != V_206 );
V_120 -> V_199 = V_208 ;
return 0 ;
}
static T_6 int
F_176 ( struct V_27 * V_28 ,
struct V_119 * V_120 ,
struct V_93 * V_94 , T_1 V_6 , T_1 V_82 ,
T_1 V_200 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 ;
int V_16 = - V_53 ;
T_1 V_210 = F_126 ( V_91 , V_6 ) ;
if ( V_91 -> V_101 == 0 )
return - V_53 ;
V_85 = F_177 ( V_94 , struct V_88 , V_104 ) ;
if ( V_85 -> V_6 != V_210 ) {
V_85 = F_132 ( V_91 , V_210 , 1 , 0 ) ;
if ( V_85 && F_103 ( & V_85 -> V_104 ) )
F_178 ( & V_85 -> V_104 , V_94 ) ;
}
F_179 (entry, bitmaps, list) {
if ( V_85 -> V_82 < V_200 )
continue;
V_16 = F_174 ( V_28 , V_85 , V_120 , V_6 ,
V_82 , V_200 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_53 ;
}
int F_180 ( struct V_36 * V_37 ,
struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_119 * V_120 ,
T_1 V_6 , T_1 V_82 , T_1 V_196 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 , * V_80 ;
F_181 ( V_94 ) ;
T_1 V_200 ;
int V_16 ;
if ( F_182 ( V_3 , V_211 ) ) {
V_200 = V_82 + V_196 ;
} else if ( V_28 -> V_25 & V_212 ) {
if ( V_37 -> V_213 -> V_214 . V_215 )
V_200 = F_183 ( V_82 , ( V_82 + V_196 ) >> 1 ) ;
else
V_200 = F_183 ( V_82 , ( V_82 + V_196 ) >> 4 ) ;
} else
V_200 = F_183 ( V_82 , ( V_82 + V_196 ) >> 2 ) ;
F_13 ( & V_91 -> V_100 ) ;
if ( V_91 -> V_112 < V_200 ) {
F_15 ( & V_91 -> V_100 ) ;
return - V_53 ;
}
F_13 ( & V_120 -> V_31 ) ;
if ( V_120 -> V_28 ) {
V_16 = 0 ;
goto V_97;
}
V_16 = F_175 ( V_28 , V_120 , & V_94 , V_6 ,
V_82 , V_200 ) ;
if ( V_16 )
V_16 = F_176 ( V_28 , V_120 , & V_94 ,
V_6 , V_82 , V_200 ) ;
F_94 (entry, tmp, &bitmaps, list)
F_95 ( & V_85 -> V_104 ) ;
if ( ! V_16 ) {
F_171 ( & V_28 -> V_167 ) ;
F_93 ( & V_120 -> V_131 ,
& V_28 -> V_129 ) ;
V_120 -> V_28 = V_28 ;
}
V_97:
F_15 ( & V_120 -> V_31 ) ;
F_15 ( & V_91 -> V_100 ) ;
return V_16 ;
}
void F_184 ( struct V_119 * V_120 )
{
F_161 ( & V_120 -> V_31 ) ;
F_161 ( & V_120 -> V_216 ) ;
V_120 -> V_3 = V_194 ;
V_120 -> V_199 = 0 ;
F_86 ( & V_120 -> V_131 ) ;
V_120 -> V_28 = NULL ;
}
int F_185 ( struct V_27 * V_28 ,
T_1 * V_217 , T_1 V_124 , T_1 V_125 , T_1 V_218 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 = NULL ;
struct V_105 * V_22 = V_28 -> V_22 ;
T_1 V_82 = 0 ;
T_1 V_219 ;
int V_16 = 0 ;
* V_217 = 0 ;
while ( V_124 < V_125 ) {
F_13 ( & V_91 -> V_100 ) ;
if ( V_91 -> V_112 < V_218 ) {
F_15 ( & V_91 -> V_100 ) ;
break;
}
V_85 = F_132 ( V_91 , V_124 , 0 , 1 ) ;
if ( ! V_85 )
V_85 = F_132 ( V_91 ,
F_126 ( V_91 , V_124 ) ,
1 , 1 ) ;
if ( ! V_85 || V_85 -> V_6 >= V_125 ) {
F_15 ( & V_91 -> V_100 ) ;
break;
}
if ( V_85 -> V_83 ) {
V_16 = F_144 ( V_91 , V_85 , & V_124 , & V_82 ) ;
if ( ! V_16 ) {
if ( V_124 >= V_125 ) {
F_15 ( & V_91 -> V_100 ) ;
break;
}
V_82 = F_110 ( V_82 , V_125 - V_124 ) ;
F_141 ( V_91 , V_85 , V_124 , V_82 ) ;
if ( V_85 -> V_82 == 0 )
F_150 ( V_91 , V_85 ) ;
} else {
V_124 = V_85 -> V_6 + V_146 *
V_28 -> V_163 ;
F_15 ( & V_91 -> V_100 ) ;
V_16 = 0 ;
continue;
}
} else {
V_124 = V_85 -> V_6 ;
V_82 = F_110 ( V_85 -> V_82 , V_125 - V_124 ) ;
F_136 ( V_91 , V_85 ) ;
F_91 ( V_99 , V_85 ) ;
}
F_15 ( & V_91 -> V_100 ) ;
if ( V_82 >= V_218 ) {
struct V_220 * V_221 ;
int V_222 = 0 ;
V_221 = V_28 -> V_221 ;
F_13 ( & V_221 -> V_31 ) ;
F_13 ( & V_28 -> V_31 ) ;
if ( ! V_28 -> V_223 ) {
V_28 -> V_52 += V_82 ;
V_221 -> V_224 += V_82 ;
V_222 = 1 ;
}
F_15 ( & V_28 -> V_31 ) ;
F_15 ( & V_221 -> V_31 ) ;
V_16 = F_186 ( V_22 -> V_225 ,
V_124 ,
V_82 ,
& V_219 ) ;
F_158 ( V_28 , V_124 , V_82 ) ;
if ( V_222 ) {
F_13 ( & V_221 -> V_31 ) ;
F_13 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_223 )
V_221 -> V_226 += V_82 ;
V_28 -> V_52 -= V_82 ;
V_221 -> V_224 -= V_82 ;
F_15 ( & V_221 -> V_31 ) ;
F_15 ( & V_28 -> V_31 ) ;
}
if ( V_16 )
break;
* V_217 += V_219 ;
}
V_124 += V_82 ;
V_82 = 0 ;
if ( F_187 ( V_227 ) ) {
V_16 = - V_228 ;
break;
}
F_167 () ;
}
return V_16 ;
}
T_1 F_188 ( struct V_2 * V_229 )
{
struct V_90 * V_91 = V_229 -> V_230 ;
struct V_88 * V_85 = NULL ;
T_1 V_38 = 0 ;
F_13 ( & V_91 -> V_100 ) ;
if ( F_189 ( & V_91 -> V_134 ) )
goto V_97;
V_85 = F_107 ( F_106 ( & V_91 -> V_134 ) ,
struct V_88 , V_136 ) ;
if ( ! V_85 -> V_83 ) {
V_38 = V_85 -> V_6 ;
F_136 ( V_91 , V_85 ) ;
V_85 -> V_6 ++ ;
V_85 -> V_82 -- ;
if ( ! V_85 -> V_82 )
F_91 ( V_99 , V_85 ) ;
else
F_92 ( V_91 , V_85 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_167 = 1 ;
int V_16 ;
V_16 = F_144 ( V_91 , V_85 , & V_6 , & V_167 ) ;
F_57 ( V_16 ) ;
V_38 = V_6 ;
F_141 ( V_91 , V_85 , V_6 , 1 ) ;
if ( V_85 -> V_82 == 0 )
F_150 ( V_91 , V_85 ) ;
}
V_97:
F_15 ( & V_91 -> V_100 ) ;
return V_38 ;
}
struct V_1 * F_190 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_13 ( & V_3 -> V_231 ) ;
if ( V_3 -> V_232 )
V_1 = F_14 ( V_3 -> V_232 ) ;
F_15 ( & V_3 -> V_231 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_13 ( & V_3 -> V_231 ) ;
if ( ! F_99 ( V_3 -> V_22 ) )
V_3 -> V_232 = F_14 ( V_1 ) ;
F_15 ( & V_3 -> V_231 ) ;
return V_1 ;
}
int F_191 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
return F_18 ( V_3 , V_37 , V_5 ,
V_43 , 0 ) ;
}
int F_192 ( struct V_105 * V_22 , struct V_2 * V_3 )
{
struct V_90 * V_91 = V_3 -> V_230 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_233 = F_193 ( & V_3 -> V_234 ) ;
if ( ! F_182 ( V_3 , V_235 ) )
return 0 ;
if ( F_99 ( V_22 ) )
return 0 ;
V_5 = F_100 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_190 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_97;
if ( V_233 != F_16 ( V_1 ) -> V_77 )
goto V_236;
V_16 = F_85 ( V_3 , V_1 , V_91 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_17 ( V_75 L_25
L_26 , V_3 -> V_237 . V_17 ) ;
V_236:
F_11 ( V_1 ) ;
V_97:
F_101 ( V_5 ) ;
return V_16 ;
}
int F_194 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 = V_3 -> V_230 ;
struct V_1 * V_1 ;
int V_16 ;
if ( ! F_182 ( V_3 , V_235 ) )
return 0 ;
V_1 = F_190 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_102 ( V_3 , V_1 , V_91 , NULL , V_37 , V_5 , 0 ) ;
if ( V_16 ) {
F_195 ( V_1 , V_1 -> V_138 ) ;
#ifdef F_122
F_17 ( V_75 L_27
L_28 , V_3 -> V_237 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
