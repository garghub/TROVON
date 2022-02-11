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
if ( V_61 -> V_64 [ V_72 ] ) {
F_60 ( V_61 -> V_64 [ V_72 ] ) ;
F_61 ( V_61 -> V_64 [ V_72 ] ) ;
F_62 ( V_61 -> V_64 [ V_72 ] ) ;
}
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
V_6 = sizeof( T_2 ) * V_61 -> V_62 ;
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
V_16 = F_51 ( & V_61 , V_1 , V_3 ) ;
if ( V_16 )
return V_16 ;
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
F_101 ( V_5 ) ;
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
T_1 V_124 , V_125 , V_126 , V_127 ;
int V_128 = 0 ;
int V_94 = 0 ;
int V_16 ;
int V_129 = - 1 ;
F_86 ( & V_123 ) ;
if ( ! F_40 ( V_1 ) )
return - 1 ;
V_16 = F_51 ( & V_61 , V_1 , V_3 ) ;
if ( V_16 )
return - 1 ;
if ( V_28 && ! F_103 ( & V_28 -> V_130 ) )
V_120 = F_104 ( V_28 -> V_130 . V_131 ,
struct V_119 ,
V_132 ) ;
F_63 ( & V_61 , V_1 , 0 ) ;
F_105 ( & F_16 ( V_1 ) -> V_133 , 0 , F_40 ( V_1 ) - 1 ,
0 , & V_118 , V_58 ) ;
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
V_128 ++ ;
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
V_122 = V_3 -> V_22 -> V_137 ;
if ( V_28 )
V_124 = V_28 -> V_8 . V_17 ;
while ( V_28 && ( V_124 < V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 ) ) {
V_16 = F_109 ( V_122 , V_124 ,
& V_125 , & V_126 ,
V_138 ) ;
if ( V_16 ) {
V_16 = 0 ;
break;
}
if ( V_125 >= V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 )
break;
V_125 = F_110 ( V_125 , V_124 ) ;
V_126 = F_111 ( V_28 -> V_8 . V_17 +
V_28 -> V_8 . V_6 , V_126 + 1 ) ;
V_127 = V_126 - V_125 ;
V_128 ++ ;
V_16 = F_80 ( & V_61 , V_125 , V_127 , NULL ) ;
if ( V_16 )
goto V_135;
V_124 = V_126 ;
}
F_112 (pos, n, &bitmap_list) {
struct V_88 * V_85 =
F_104 ( V_116 , struct V_88 , V_104 ) ;
V_16 = F_81 ( & V_61 , V_85 -> V_83 ) ;
if ( V_16 )
goto V_135;
F_95 ( & V_85 -> V_104 ) ;
}
F_82 ( & V_61 ) ;
V_16 = F_113 ( V_3 , V_1 , V_61 . V_64 , V_61 . V_62 ,
0 , F_40 ( V_1 ) , & V_118 ) ;
F_59 ( & V_61 ) ;
F_114 ( & F_16 ( V_1 ) -> V_133 , 0 ,
F_40 ( V_1 ) - 1 , & V_118 , V_58 ) ;
if ( V_16 )
goto V_97;
V_16 = F_115 ( V_1 -> V_24 ) ;
if ( V_16 )
goto V_97;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_37 , V_3 , & V_8 , V_5 , 0 , 1 ) ;
if ( V_16 < 0 ) {
F_116 ( & F_16 ( V_1 ) -> V_133 , 0 , V_1 -> V_139 - 1 ,
V_138 | V_140 , 0 , 0 , NULL ,
V_58 ) ;
goto V_97;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_141 ;
F_57 ( ! V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_117 ( V_15 , & V_141 , V_5 -> V_21 [ 0 ] ) ;
if ( V_141 . V_17 != V_18 ||
V_141 . V_6 != V_6 ) {
F_116 ( & F_16 ( V_1 ) -> V_133 , 0 ,
V_1 -> V_139 - 1 ,
V_138 | V_140 , 0 , 0 ,
NULL , V_58 ) ;
F_4 ( V_5 ) ;
goto V_97;
}
}
F_16 ( V_1 ) -> V_77 = V_37 -> V_44 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_118 ( V_15 , V_13 , V_128 ) ;
F_119 ( V_15 , V_13 , V_94 ) ;
F_120 ( V_15 , V_13 , V_37 -> V_44 ) ;
F_32 ( V_15 ) ;
F_4 ( V_5 ) ;
V_129 = 0 ;
V_97:
F_53 ( & V_61 ) ;
if ( V_129 ) {
F_121 ( V_1 -> V_24 ) ;
F_16 ( V_1 ) -> V_77 = 0 ;
}
F_45 ( V_37 , V_3 , V_1 ) ;
return V_129 ;
V_135:
F_112 (pos, n, &bitmap_list) {
struct V_88 * V_85 =
F_104 ( V_116 , struct V_88 , V_104 ) ;
F_95 ( & V_85 -> V_104 ) ;
}
F_59 ( & V_61 ) ;
F_114 ( & F_16 ( V_1 ) -> V_133 , 0 ,
F_40 ( V_1 ) - 1 , & V_118 , V_58 ) ;
goto V_97;
}
int F_122 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_107 ;
F_13 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_33 < V_142 ) {
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
V_28 -> V_33 = V_143 ;
F_15 ( & V_28 -> V_31 ) ;
V_16 = 0 ;
#ifdef F_123
F_17 ( V_75 L_15
L_14 , V_28 -> V_8 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_124 ( T_1 V_144 , T_2 V_145 ,
T_1 V_6 )
{
F_57 ( V_6 < V_144 ) ;
V_6 -= V_144 ;
return ( unsigned long ) ( F_125 ( V_6 , V_145 ) ) ;
}
static inline unsigned long F_126 ( T_1 V_82 , T_2 V_145 )
{
return ( unsigned long ) ( F_125 ( V_82 , V_145 ) ) ;
}
static inline T_1 F_127 ( struct V_90 * V_91 ,
T_1 V_6 )
{
T_1 V_144 ;
T_1 V_146 ;
V_146 = V_147 * V_91 -> V_145 ;
V_144 = V_6 - V_91 -> V_124 ;
V_144 = F_128 ( V_144 , V_146 ) ;
V_144 *= V_146 ;
V_144 += V_91 -> V_124 ;
return V_144 ;
}
static int F_129 ( struct V_148 * V_3 , T_1 V_6 ,
struct V_114 * V_115 , int V_83 )
{
struct V_114 * * V_149 = & V_3 -> V_114 ;
struct V_114 * V_150 = NULL ;
struct V_88 * V_151 ;
while ( * V_149 ) {
V_150 = * V_149 ;
V_151 = F_107 ( V_150 , struct V_88 , V_136 ) ;
if ( V_6 < V_151 -> V_6 ) {
V_149 = & ( * V_149 ) -> V_152 ;
} else if ( V_6 > V_151 -> V_6 ) {
V_149 = & ( * V_149 ) -> V_153 ;
} else {
if ( V_83 ) {
if ( V_151 -> V_83 ) {
F_130 ( 1 ) ;
return - V_154 ;
}
V_149 = & ( * V_149 ) -> V_153 ;
} else {
if ( ! V_151 -> V_83 ) {
F_130 ( 1 ) ;
return - V_154 ;
}
V_149 = & ( * V_149 ) -> V_152 ;
}
}
}
F_131 ( V_115 , V_150 , V_149 ) ;
F_132 ( V_115 , V_3 ) ;
return 0 ;
}
static struct V_88 *
F_133 ( struct V_90 * V_91 ,
T_1 V_6 , int V_155 , int V_156 )
{
struct V_114 * V_92 = V_91 -> V_134 . V_114 ;
struct V_88 * V_85 , * V_157 = NULL ;
while ( 1 ) {
if ( ! V_92 ) {
V_85 = NULL ;
break;
}
V_85 = F_107 ( V_92 , struct V_88 , V_136 ) ;
V_157 = V_85 ;
if ( V_6 < V_85 -> V_6 )
V_92 = V_92 -> V_152 ;
else if ( V_6 > V_85 -> V_6 )
V_92 = V_92 -> V_153 ;
else
break;
}
if ( V_155 ) {
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
V_92 = F_134 ( V_92 ) ;
if ( ! V_92 )
break;
V_157 = F_107 ( V_92 , struct V_88 ,
V_136 ) ;
if ( ! V_157 -> V_83 ) {
if ( V_157 -> V_6 + V_157 -> V_82 > V_6 )
V_85 = V_157 ;
break;
}
}
}
return V_85 ;
}
if ( ! V_157 )
return NULL ;
V_85 = V_157 ;
if ( V_85 -> V_6 > V_6 ) {
V_92 = F_134 ( & V_85 -> V_136 ) ;
if ( V_92 ) {
V_85 = F_107 ( V_92 , struct V_88 ,
V_136 ) ;
F_57 ( V_85 -> V_6 > V_6 ) ;
} else {
if ( V_156 )
return V_85 ;
else
return NULL ;
}
}
if ( V_85 -> V_83 ) {
V_92 = & V_85 -> V_136 ;
while ( 1 ) {
V_92 = F_134 ( V_92 ) ;
if ( ! V_92 )
break;
V_157 = F_107 ( V_92 , struct V_88 ,
V_136 ) ;
if ( ! V_157 -> V_83 ) {
if ( V_157 -> V_6 + V_157 -> V_82 > V_6 )
return V_157 ;
break;
}
}
if ( V_85 -> V_6 + V_147 * V_91 -> V_145 > V_6 )
return V_85 ;
} else if ( V_85 -> V_6 + V_85 -> V_82 > V_6 )
return V_85 ;
if ( ! V_156 )
return NULL ;
while ( 1 ) {
if ( V_85 -> V_83 ) {
if ( V_85 -> V_6 + V_147 *
V_91 -> V_145 > V_6 )
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
F_135 ( struct V_90 * V_91 ,
struct V_88 * V_151 )
{
F_136 ( & V_151 -> V_136 , & V_91 -> V_134 ) ;
V_91 -> V_158 -- ;
}
static void F_137 ( struct V_90 * V_91 ,
struct V_88 * V_151 )
{
F_135 ( V_91 , V_151 ) ;
V_91 -> V_112 -= V_151 -> V_82 ;
}
static int F_92 ( struct V_90 * V_91 ,
struct V_88 * V_151 )
{
int V_16 = 0 ;
F_57 ( ! V_151 -> V_83 && ! V_151 -> V_82 ) ;
V_16 = F_129 ( & V_91 -> V_134 , V_151 -> V_6 ,
& V_151 -> V_136 , ( V_151 -> V_83 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_91 -> V_112 += V_151 -> V_82 ;
V_91 -> V_158 ++ ;
return V_16 ;
}
static void F_138 ( struct V_90 * V_91 )
{
struct V_27 * V_28 = V_91 -> V_159 ;
T_1 V_160 ;
T_1 V_161 ;
T_1 V_162 ;
T_1 V_71 = V_28 -> V_8 . V_6 ;
T_1 V_163 = V_147 * V_28 -> V_164 ;
int V_165 = F_128 ( V_71 + V_163 - 1 , V_163 ) ;
F_57 ( V_91 -> V_101 > V_165 ) ;
if ( V_71 < 1024 * 1024 * 1024 )
V_160 = V_166 ;
else
V_160 = V_166 *
F_128 ( V_71 , 1024 * 1024 * 1024 ) ;
V_161 = ( V_91 -> V_101 + 1 ) * V_63 ;
if ( V_161 >= V_160 ) {
V_91 -> V_167 = 0 ;
return;
}
V_162 = V_160 - V_161 ;
V_162 = F_139 ( T_1 , V_162 , F_128 ( V_160 , 2 ) ) ;
V_91 -> V_167 =
F_128 ( V_162 , ( sizeof( struct V_88 ) ) ) ;
}
static inline void F_140 ( struct V_90 * V_91 ,
struct V_88 * V_151 ,
T_1 V_6 , T_1 V_82 )
{
unsigned long V_124 , V_168 ;
V_124 = F_124 ( V_151 -> V_6 , V_91 -> V_145 , V_6 ) ;
V_168 = F_126 ( V_82 , V_91 -> V_145 ) ;
F_57 ( V_124 + V_168 > V_147 ) ;
F_141 ( V_151 -> V_83 , V_124 , V_168 ) ;
V_151 -> V_82 -= V_82 ;
}
static void F_142 ( struct V_90 * V_91 ,
struct V_88 * V_151 , T_1 V_6 ,
T_1 V_82 )
{
F_140 ( V_91 , V_151 , V_6 , V_82 ) ;
V_91 -> V_112 -= V_82 ;
}
static void F_143 ( struct V_90 * V_91 ,
struct V_88 * V_151 , T_1 V_6 ,
T_1 V_82 )
{
unsigned long V_124 , V_168 ;
V_124 = F_124 ( V_151 -> V_6 , V_91 -> V_145 , V_6 ) ;
V_168 = F_126 ( V_82 , V_91 -> V_145 ) ;
F_57 ( V_124 + V_168 > V_147 ) ;
F_144 ( V_151 -> V_83 , V_124 , V_168 ) ;
V_151 -> V_82 += V_82 ;
V_91 -> V_112 += V_82 ;
}
static int F_145 ( struct V_90 * V_91 ,
struct V_88 * V_169 , T_1 * V_6 ,
T_1 * V_82 )
{
unsigned long V_170 = 0 ;
unsigned long V_171 , V_72 ;
unsigned long V_172 ;
V_72 = F_124 ( V_169 -> V_6 , V_91 -> V_145 ,
F_146 ( T_1 , * V_6 , V_169 -> V_6 ) ) ;
V_171 = F_126 ( * V_82 , V_91 -> V_145 ) ;
for ( V_72 = F_147 ( V_169 -> V_83 , V_147 , V_72 ) ;
V_72 < V_147 ;
V_72 = F_147 ( V_169 -> V_83 , V_147 , V_72 + 1 ) ) {
V_172 = F_148 ( V_169 -> V_83 ,
V_147 , V_72 ) ;
if ( ( V_172 - V_72 ) >= V_171 ) {
V_170 = V_172 - V_72 ;
break;
}
V_72 = V_172 ;
}
if ( V_170 ) {
* V_6 = ( T_1 ) ( V_72 * V_91 -> V_145 ) + V_169 -> V_6 ;
* V_82 = ( T_1 ) ( V_170 ) * V_91 -> V_145 ;
return 0 ;
}
return - 1 ;
}
static struct V_88 *
F_149 ( struct V_90 * V_91 , T_1 * V_6 , T_1 * V_82 )
{
struct V_88 * V_85 ;
struct V_114 * V_115 ;
int V_16 ;
if ( ! V_91 -> V_134 . V_114 )
return NULL ;
V_85 = F_133 ( V_91 , F_127 ( V_91 , * V_6 ) , 0 , 1 ) ;
if ( ! V_85 )
return NULL ;
for ( V_115 = & V_85 -> V_136 ; V_115 ; V_115 = F_108 ( V_115 ) ) {
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( V_85 -> V_82 < * V_82 )
continue;
if ( V_85 -> V_83 ) {
V_16 = F_145 ( V_91 , V_85 , V_6 , V_82 ) ;
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
static void F_150 ( struct V_90 * V_91 ,
struct V_88 * V_151 , T_1 V_6 )
{
V_151 -> V_6 = F_127 ( V_91 , V_6 ) ;
V_151 -> V_82 = 0 ;
F_86 ( & V_151 -> V_104 ) ;
F_92 ( V_91 , V_151 ) ;
V_91 -> V_101 ++ ;
V_91 -> V_102 -> V_103 ( V_91 ) ;
}
static void F_151 ( struct V_90 * V_91 ,
struct V_88 * V_169 )
{
F_137 ( V_91 , V_169 ) ;
F_50 ( V_169 -> V_83 ) ;
F_91 ( V_99 , V_169 ) ;
V_91 -> V_101 -- ;
V_91 -> V_102 -> V_103 ( V_91 ) ;
}
static T_6 int F_152 ( struct V_90 * V_91 ,
struct V_88 * V_169 ,
T_1 * V_6 , T_1 * V_82 )
{
T_1 V_173 ;
T_1 V_174 , V_175 ;
int V_16 ;
V_176:
V_173 = V_169 -> V_6 + ( T_1 ) ( V_147 * V_91 -> V_145 ) - 1 ;
V_174 = * V_6 ;
V_175 = * V_82 ;
V_175 = F_111 ( V_175 , V_173 - V_174 + 1 ) ;
V_16 = F_145 ( V_91 , V_169 , & V_174 , & V_175 ) ;
F_57 ( V_16 < 0 || V_174 != * V_6 ) ;
if ( * V_6 > V_169 -> V_6 && * V_6 + * V_82 > V_173 ) {
F_142 ( V_91 , V_169 , * V_6 , V_173 - * V_6 + 1 ) ;
* V_82 -= V_173 - * V_6 + 1 ;
* V_6 = V_173 + 1 ;
} else if ( * V_6 >= V_169 -> V_6 && * V_6 + * V_82 <= V_173 ) {
F_142 ( V_91 , V_169 , * V_6 , * V_82 ) ;
* V_82 = 0 ;
}
if ( * V_82 ) {
struct V_114 * V_131 = F_108 ( & V_169 -> V_136 ) ;
if ( ! V_169 -> V_82 )
F_151 ( V_91 , V_169 ) ;
if ( ! V_131 )
return - V_177 ;
V_169 = F_107 ( V_131 , struct V_88 ,
V_136 ) ;
if ( ! V_169 -> V_83 )
return - V_178 ;
V_174 = * V_6 ;
V_175 = * V_82 ;
V_16 = F_145 ( V_91 , V_169 , & V_174 ,
& V_175 ) ;
if ( V_16 < 0 || V_174 != * V_6 )
return - V_178 ;
goto V_176;
} else if ( ! V_169 -> V_82 )
F_151 ( V_91 , V_169 ) ;
return 0 ;
}
static T_1 F_153 ( struct V_90 * V_91 ,
struct V_88 * V_151 , T_1 V_6 ,
T_1 V_82 )
{
T_1 V_179 = 0 ;
T_1 V_173 ;
V_173 = V_151 -> V_6 + ( T_1 ) ( V_147 * V_91 -> V_145 ) ;
V_179 = F_111 ( V_173 - V_6 , V_82 ) ;
F_143 ( V_91 , V_151 , V_6 , V_179 ) ;
return V_179 ;
}
static bool F_154 ( struct V_90 * V_91 ,
struct V_88 * V_151 )
{
struct V_27 * V_28 = V_91 -> V_159 ;
if ( V_91 -> V_158 < V_91 -> V_167 ) {
if ( V_151 -> V_82 <= V_28 -> V_164 * 4 ) {
if ( V_91 -> V_158 * 2 <= V_91 -> V_167 )
return false ;
} else {
return false ;
}
}
if ( V_147 * V_28 -> V_164 >
V_28 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_155 ( struct V_90 * V_91 ,
struct V_88 * V_151 )
{
struct V_88 * V_169 ;
struct V_27 * V_28 = NULL ;
int V_180 = 0 ;
T_1 V_82 , V_6 , V_181 ;
int V_16 ;
V_82 = V_151 -> V_82 ;
V_6 = V_151 -> V_6 ;
if ( ! V_91 -> V_102 -> F_154 ( V_91 , V_151 ) )
return 0 ;
if ( V_91 -> V_102 == & V_182 )
V_28 = V_91 -> V_159 ;
V_176:
if ( V_28 && ! F_103 ( & V_28 -> V_130 ) ) {
struct V_119 * V_120 ;
struct V_114 * V_115 ;
struct V_88 * V_85 ;
V_120 = F_104 ( V_28 -> V_130 . V_131 ,
struct V_119 ,
V_132 ) ;
F_13 ( & V_120 -> V_31 ) ;
V_115 = F_106 ( & V_120 -> V_3 ) ;
if ( ! V_115 ) {
F_15 ( & V_120 -> V_31 ) ;
goto V_183;
}
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( ! V_85 -> V_83 ) {
F_15 ( & V_120 -> V_31 ) ;
goto V_183;
}
if ( V_85 -> V_6 == F_127 ( V_91 , V_6 ) ) {
V_181 = F_153 ( V_91 , V_85 ,
V_6 , V_82 ) ;
V_82 -= V_181 ;
V_6 += V_181 ;
}
F_15 ( & V_120 -> V_31 ) ;
if ( ! V_82 ) {
V_16 = 1 ;
goto V_97;
}
}
V_183:
V_169 = F_133 ( V_91 , F_127 ( V_91 , V_6 ) ,
1 , 0 ) ;
if ( ! V_169 ) {
F_57 ( V_180 ) ;
goto V_184;
}
V_181 = F_153 ( V_91 , V_169 , V_6 , V_82 ) ;
V_82 -= V_181 ;
V_6 += V_181 ;
V_180 = 0 ;
if ( ! V_82 ) {
V_16 = 1 ;
goto V_97;
} else
goto V_176;
V_184:
if ( V_151 && V_151 -> V_83 ) {
F_150 ( V_91 , V_151 , V_6 ) ;
V_180 = 1 ;
V_151 = NULL ;
goto V_176;
} else {
F_15 ( & V_91 -> V_100 ) ;
if ( ! V_151 ) {
V_151 = F_90 ( V_99 ,
V_58 ) ;
if ( ! V_151 ) {
F_13 ( & V_91 -> V_100 ) ;
V_16 = - V_59 ;
goto V_97;
}
}
V_151 -> V_83 = F_47 ( V_63 , V_58 ) ;
F_13 ( & V_91 -> V_100 ) ;
if ( ! V_151 -> V_83 ) {
V_16 = - V_59 ;
goto V_97;
}
goto V_176;
}
V_97:
if ( V_151 ) {
if ( V_151 -> V_83 )
F_50 ( V_151 -> V_83 ) ;
F_91 ( V_99 , V_151 ) ;
}
return V_16 ;
}
static bool F_156 ( struct V_90 * V_91 ,
struct V_88 * V_151 , bool V_185 )
{
struct V_88 * V_186 ;
struct V_88 * V_187 ;
bool V_188 = false ;
T_1 V_6 = V_151 -> V_6 ;
T_1 V_82 = V_151 -> V_82 ;
V_187 = F_133 ( V_91 , V_6 + V_82 , 0 , 0 ) ;
if ( V_187 && F_134 ( & V_187 -> V_136 ) )
V_186 = F_107 ( F_134 ( & V_187 -> V_136 ) ,
struct V_88 , V_136 ) ;
else
V_186 = F_133 ( V_91 , V_6 - 1 , 0 , 0 ) ;
if ( V_187 && ! V_187 -> V_83 ) {
if ( V_185 )
F_137 ( V_91 , V_187 ) ;
else
F_135 ( V_91 , V_187 ) ;
V_151 -> V_82 += V_187 -> V_82 ;
F_91 ( V_99 , V_187 ) ;
V_188 = true ;
}
if ( V_186 && ! V_186 -> V_83 &&
V_186 -> V_6 + V_186 -> V_82 == V_6 ) {
if ( V_185 )
F_137 ( V_91 , V_186 ) ;
else
F_135 ( V_91 , V_186 ) ;
V_151 -> V_6 = V_186 -> V_6 ;
V_151 -> V_82 += V_186 -> V_82 ;
F_91 ( V_99 , V_186 ) ;
V_188 = true ;
}
return V_188 ;
}
int F_157 ( struct V_90 * V_91 ,
T_1 V_6 , T_1 V_82 )
{
struct V_88 * V_151 ;
int V_16 = 0 ;
V_151 = F_90 ( V_99 , V_58 ) ;
if ( ! V_151 )
return - V_59 ;
V_151 -> V_6 = V_6 ;
V_151 -> V_82 = V_82 ;
F_13 ( & V_91 -> V_100 ) ;
if ( F_156 ( V_91 , V_151 , true ) )
goto V_189;
V_16 = F_155 ( V_91 , V_151 ) ;
if ( V_16 < 0 ) {
goto V_97;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_97;
}
V_189:
V_16 = F_92 ( V_91 , V_151 ) ;
if ( V_16 )
F_91 ( V_99 , V_151 ) ;
V_97:
F_15 ( & V_91 -> V_100 ) ;
if ( V_16 ) {
F_17 ( V_190 L_16 , V_16 ) ;
F_57 ( V_16 == - V_154 ) ;
}
return V_16 ;
}
int F_158 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_82 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_151 ;
struct V_88 * V_191 = NULL ;
int V_16 = 0 ;
F_13 ( & V_91 -> V_100 ) ;
V_176:
V_151 = F_133 ( V_91 , V_6 , 0 , 0 ) ;
if ( ! V_151 ) {
V_151 = F_133 ( V_91 , F_127 ( V_91 , V_6 ) ,
1 , 0 ) ;
if ( ! V_151 ) {
goto V_192;
}
}
if ( V_151 -> V_82 < V_82 && F_108 ( & V_151 -> V_136 ) ) {
T_1 V_173 ;
V_191 = F_107 ( F_108 ( & V_151 -> V_136 ) ,
struct V_88 ,
V_136 ) ;
if ( V_191 -> V_83 )
V_173 = V_191 -> V_6 +
V_147 * V_91 -> V_145 - 1 ;
else
V_173 = V_191 -> V_6 + V_191 -> V_82 ;
if ( V_191 -> V_82 < V_82 ||
V_191 -> V_6 > V_6 || V_6 > V_173 ) {
F_17 ( V_190 L_17
L_18 ,
( unsigned long long ) V_151 -> V_6 ,
( unsigned long long ) V_151 -> V_82 ,
( unsigned long long ) V_82 ) ;
F_44 ( 1 ) ;
V_16 = - V_177 ;
goto V_192;
}
V_151 = V_191 ;
}
if ( V_151 -> V_82 == V_82 ) {
F_137 ( V_91 , V_151 ) ;
if ( V_151 -> V_83 ) {
F_50 ( V_151 -> V_83 ) ;
V_91 -> V_101 -- ;
}
F_91 ( V_99 , V_151 ) ;
V_16 = 0 ;
goto V_192;
}
if ( ! V_151 -> V_83 && V_151 -> V_6 == V_6 ) {
F_137 ( V_91 , V_151 ) ;
V_151 -> V_6 += V_82 ;
V_151 -> V_82 -= V_82 ;
V_16 = F_92 ( V_91 , V_151 ) ;
F_44 ( V_16 ) ;
goto V_192;
}
if ( ! V_151 -> V_83 && V_151 -> V_6 <= V_6 &&
V_151 -> V_6 + V_151 -> V_82 >= V_6 + V_82 ) {
T_1 V_193 = V_151 -> V_6 ;
F_137 ( V_91 , V_151 ) ;
if ( V_6 + V_82 < V_151 -> V_6 + V_151 -> V_82 ) {
T_1 V_194 = V_151 -> V_6 + V_151 -> V_82 ;
V_151 -> V_6 = V_6 + V_82 ;
V_151 -> V_82 = V_194 - V_151 -> V_6 ;
V_16 = F_92 ( V_91 , V_151 ) ;
F_44 ( V_16 ) ;
if ( V_16 )
goto V_192;
} else {
F_91 ( V_99 , V_151 ) ;
}
F_15 ( & V_91 -> V_100 ) ;
V_16 = F_159 ( V_28 , V_193 ,
V_6 - V_193 ) ;
F_44 ( V_16 ) ;
goto V_97;
}
V_16 = F_152 ( V_91 , V_151 , & V_6 , & V_82 ) ;
if ( V_16 == - V_178 )
goto V_176;
F_57 ( V_16 ) ;
V_192:
F_15 ( & V_91 -> V_100 ) ;
V_97:
return V_16 ;
}
void F_160 ( struct V_27 * V_28 ,
T_1 V_82 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_151 ;
struct V_114 * V_92 ;
int V_168 = 0 ;
for ( V_92 = F_106 ( & V_91 -> V_134 ) ; V_92 ; V_92 = F_108 ( V_92 ) ) {
V_151 = F_107 ( V_92 , struct V_88 , V_136 ) ;
if ( V_151 -> V_82 >= V_82 )
V_168 ++ ;
F_17 ( V_190 L_19 ,
( unsigned long long ) V_151 -> V_6 ,
( unsigned long long ) V_151 -> V_82 ,
( V_151 -> V_83 ) ? L_20 : L_21 ) ;
}
F_17 ( V_32 L_22 ,
F_103 ( & V_28 -> V_130 ) ? L_21 : L_20 ) ;
F_17 ( V_32 L_23
L_24 , V_168 ) ;
}
void F_161 ( struct V_27 * V_28 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
F_162 ( & V_91 -> V_100 ) ;
V_91 -> V_145 = V_28 -> V_164 ;
V_91 -> V_124 = V_28 -> V_8 . V_17 ;
V_91 -> V_159 = V_28 ;
V_91 -> V_102 = & V_182 ;
V_91 -> V_167 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_88 ) ;
}
static int
F_163 (
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
V_120 -> V_195 = 0 ;
F_95 ( & V_120 -> V_132 ) ;
V_115 = F_106 ( & V_120 -> V_3 ) ;
while ( V_115 ) {
bool V_83 ;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
V_115 = F_108 ( & V_85 -> V_136 ) ;
F_136 ( & V_85 -> V_136 , & V_120 -> V_3 ) ;
V_83 = ( V_85 -> V_83 != NULL ) ;
if ( ! V_83 )
F_156 ( V_91 , V_85 , false ) ;
F_129 ( & V_91 -> V_134 ,
V_85 -> V_6 , & V_85 -> V_136 , V_83 ) ;
}
V_120 -> V_3 = V_196 ;
V_97:
F_15 ( & V_120 -> V_31 ) ;
F_164 ( V_28 ) ;
return 0 ;
}
void F_165 ( struct V_90 * V_91 )
{
struct V_88 * V_151 ;
struct V_114 * V_115 ;
while ( ( V_115 = F_166 ( & V_91 -> V_134 ) ) != NULL ) {
V_151 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( ! V_151 -> V_83 ) {
F_137 ( V_91 , V_151 ) ;
F_91 ( V_99 , V_151 ) ;
} else {
F_151 ( V_91 , V_151 ) ;
}
if ( F_167 () ) {
F_15 ( & V_91 -> V_100 ) ;
F_168 () ;
F_13 ( & V_91 -> V_100 ) ;
}
}
}
void F_96 ( struct V_90 * V_91 )
{
F_13 ( & V_91 -> V_100 ) ;
F_165 ( V_91 ) ;
F_15 ( & V_91 -> V_100 ) ;
}
void F_169 ( struct V_27 * V_28 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_119 * V_120 ;
struct V_93 * V_197 ;
F_13 ( & V_91 -> V_100 ) ;
while ( ( V_197 = V_28 -> V_130 . V_131 ) !=
& V_28 -> V_130 ) {
V_120 = F_104 ( V_197 , struct V_119 ,
V_132 ) ;
F_44 ( V_120 -> V_28 != V_28 ) ;
F_163 ( V_28 , V_120 ) ;
if ( F_167 () ) {
F_15 ( & V_91 -> V_100 ) ;
F_168 () ;
F_13 ( & V_91 -> V_100 ) ;
}
}
F_165 ( V_91 ) ;
F_15 ( & V_91 -> V_100 ) ;
}
T_1 F_170 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_82 , T_1 V_198 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 = NULL ;
T_1 V_199 = V_82 + V_198 ;
T_1 V_16 = 0 ;
F_13 ( & V_91 -> V_100 ) ;
V_85 = F_149 ( V_91 , & V_6 , & V_199 ) ;
if ( ! V_85 )
goto V_97;
V_16 = V_6 ;
if ( V_85 -> V_83 ) {
F_142 ( V_91 , V_85 , V_6 , V_82 ) ;
if ( ! V_85 -> V_82 )
F_151 ( V_91 , V_85 ) ;
} else {
F_137 ( V_91 , V_85 ) ;
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
int F_171 (
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
F_172 ( & V_28 -> V_168 ) ;
F_15 ( & V_120 -> V_31 ) ;
V_91 = V_28 -> V_106 ;
F_13 ( & V_91 -> V_100 ) ;
V_16 = F_163 ( V_28 , V_120 ) ;
F_15 ( & V_91 -> V_100 ) ;
F_164 ( V_28 ) ;
return V_16 ;
}
static T_1 F_173 ( struct V_27 * V_28 ,
struct V_119 * V_120 ,
struct V_88 * V_85 ,
T_1 V_82 , T_1 V_200 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
int V_129 ;
T_1 V_174 = V_120 -> V_195 ;
T_1 V_175 = V_82 ;
T_1 V_16 = 0 ;
V_174 = V_200 ;
V_175 = V_82 ;
V_129 = F_145 ( V_91 , V_85 , & V_174 , & V_175 ) ;
if ( V_129 )
return 0 ;
V_16 = V_174 ;
F_140 ( V_91 , V_85 , V_16 , V_82 ) ;
return V_16 ;
}
T_1 F_174 ( struct V_27 * V_28 ,
struct V_119 * V_120 , T_1 V_82 ,
T_1 V_200 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 = NULL ;
struct V_114 * V_115 ;
T_1 V_16 = 0 ;
F_13 ( & V_120 -> V_31 ) ;
if ( V_82 > V_120 -> V_201 )
goto V_97;
if ( V_120 -> V_28 != V_28 )
goto V_97;
V_115 = F_106 ( & V_120 -> V_3 ) ;
if ( ! V_115 )
goto V_97;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
while( 1 ) {
if ( V_85 -> V_82 < V_82 ||
( ! V_85 -> V_83 && V_85 -> V_6 < V_200 ) ) {
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 )
break;
V_85 = F_107 ( V_115 , struct V_88 ,
V_136 ) ;
continue;
}
if ( V_85 -> V_83 ) {
V_16 = F_173 ( V_28 ,
V_120 , V_85 , V_82 ,
V_120 -> V_195 ) ;
if ( V_16 == 0 ) {
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 )
break;
V_85 = F_107 ( V_115 , struct V_88 ,
V_136 ) ;
continue;
}
V_120 -> V_195 += V_82 ;
} else {
V_16 = V_85 -> V_6 ;
V_85 -> V_6 += V_82 ;
V_85 -> V_82 -= V_82 ;
}
if ( V_85 -> V_82 == 0 )
F_136 ( & V_85 -> V_136 , & V_120 -> V_3 ) ;
break;
}
V_97:
F_15 ( & V_120 -> V_31 ) ;
if ( ! V_16 )
return 0 ;
F_13 ( & V_91 -> V_100 ) ;
V_91 -> V_112 -= V_82 ;
if ( V_85 -> V_82 == 0 ) {
V_91 -> V_158 -- ;
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
static int F_175 ( struct V_27 * V_28 ,
struct V_88 * V_85 ,
struct V_119 * V_120 ,
T_1 V_6 , T_1 V_82 ,
T_1 V_202 , T_1 V_203 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
unsigned long V_172 ;
unsigned long V_72 ;
unsigned long V_204 ;
unsigned long V_205 ;
unsigned long V_170 ;
unsigned long V_124 = 0 ;
unsigned long V_206 = 0 ;
int V_16 ;
V_72 = F_124 ( V_85 -> V_6 , V_28 -> V_164 ,
F_146 ( T_1 , V_6 , V_85 -> V_6 ) ) ;
V_204 = F_126 ( V_82 , V_28 -> V_164 ) ;
V_205 = F_126 ( V_203 , V_28 -> V_164 ) ;
V_176:
V_170 = 0 ;
for ( V_72 = F_147 ( V_85 -> V_83 , V_147 , V_72 ) ;
V_72 < V_147 ;
V_72 = F_147 ( V_85 -> V_83 , V_147 , V_72 + 1 ) ) {
V_172 = F_148 ( V_85 -> V_83 ,
V_147 , V_72 ) ;
if ( V_172 - V_72 >= V_205 ) {
V_170 = V_172 - V_72 ;
break;
}
V_72 = V_172 ;
}
if ( ! V_170 )
return - V_53 ;
if ( ! V_206 ) {
V_124 = V_72 ;
V_120 -> V_201 = 0 ;
}
V_206 += V_170 ;
if ( V_120 -> V_201 < V_170 * V_28 -> V_164 )
V_120 -> V_201 = V_170 * V_28 -> V_164 ;
if ( V_206 < V_204 || V_120 -> V_201 < V_202 ) {
V_72 = V_172 + 1 ;
goto V_176;
}
V_120 -> V_195 = V_124 * V_28 -> V_164 +
V_85 -> V_6 ;
F_136 ( & V_85 -> V_136 , & V_91 -> V_134 ) ;
V_16 = F_129 ( & V_120 -> V_3 , V_85 -> V_6 ,
& V_85 -> V_136 , 1 ) ;
F_57 ( V_16 ) ;
F_176 ( V_28 , V_120 ,
V_206 * V_28 -> V_164 , 1 ) ;
return 0 ;
}
static T_6 int
F_177 ( struct V_27 * V_28 ,
struct V_119 * V_120 ,
struct V_93 * V_94 , T_1 V_6 , T_1 V_82 ,
T_1 V_202 , T_1 V_203 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_207 = NULL ;
struct V_88 * V_85 = NULL ;
struct V_88 * V_208 ;
struct V_114 * V_115 ;
T_1 V_195 ;
T_1 V_209 ;
T_1 V_210 ;
T_1 V_211 = 0 ;
V_85 = F_133 ( V_91 , V_6 , 0 , 1 ) ;
if ( ! V_85 )
return - V_53 ;
while ( V_85 -> V_83 || V_85 -> V_82 < V_203 ) {
if ( V_85 -> V_83 && F_103 ( & V_85 -> V_104 ) )
F_93 ( & V_85 -> V_104 , V_94 ) ;
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 )
return - V_53 ;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
}
V_195 = V_85 -> V_6 ;
V_209 = V_85 -> V_82 ;
V_210 = V_85 -> V_82 ;
V_207 = V_85 ;
V_208 = V_85 ;
for ( V_115 = F_108 ( & V_85 -> V_136 ) ; V_115 ;
V_115 = F_108 ( & V_85 -> V_136 ) ) {
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
if ( V_85 -> V_83 ) {
if ( F_103 ( & V_85 -> V_104 ) )
F_93 ( & V_85 -> V_104 , V_94 ) ;
continue;
}
if ( V_85 -> V_82 < V_203 )
continue;
V_208 = V_85 ;
V_209 += V_85 -> V_82 ;
if ( V_85 -> V_82 > V_210 )
V_210 = V_85 -> V_82 ;
}
if ( V_209 < V_82 || V_210 < V_202 )
return - V_53 ;
V_120 -> V_195 = V_207 -> V_6 ;
V_115 = & V_207 -> V_136 ;
do {
int V_16 ;
V_85 = F_107 ( V_115 , struct V_88 , V_136 ) ;
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( V_85 -> V_83 || V_85 -> V_82 < V_203 )
continue;
F_136 ( & V_85 -> V_136 , & V_91 -> V_134 ) ;
V_16 = F_129 ( & V_120 -> V_3 , V_85 -> V_6 ,
& V_85 -> V_136 , 0 ) ;
V_211 += V_85 -> V_82 ;
F_57 ( V_16 ) ;
} while ( V_115 && V_85 != V_208 );
V_120 -> V_201 = V_210 ;
F_176 ( V_28 , V_120 , V_211 , 0 ) ;
return 0 ;
}
static T_6 int
F_178 ( struct V_27 * V_28 ,
struct V_119 * V_120 ,
struct V_93 * V_94 , T_1 V_6 , T_1 V_82 ,
T_1 V_202 , T_1 V_203 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 ;
int V_16 = - V_53 ;
T_1 V_212 = F_127 ( V_91 , V_6 ) ;
if ( V_91 -> V_101 == 0 )
return - V_53 ;
V_85 = F_179 ( V_94 , struct V_88 , V_104 ) ;
if ( V_85 -> V_6 != V_212 ) {
V_85 = F_133 ( V_91 , V_212 , 1 , 0 ) ;
if ( V_85 && F_103 ( & V_85 -> V_104 ) )
F_180 ( & V_85 -> V_104 , V_94 ) ;
}
F_181 (entry, bitmaps, list) {
if ( V_85 -> V_82 < V_82 )
continue;
V_16 = F_175 ( V_28 , V_85 , V_120 , V_6 ,
V_82 , V_202 , V_203 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_53 ;
}
int F_182 ( struct V_36 * V_37 ,
struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_119 * V_120 ,
T_1 V_6 , T_1 V_82 , T_1 V_198 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 , * V_80 ;
F_183 ( V_94 ) ;
T_1 V_203 ;
T_1 V_202 ;
int V_16 ;
if ( F_184 ( V_3 , V_213 ) ) {
V_202 = V_203 = V_82 + V_198 ;
} else if ( V_28 -> V_25 & V_214 ) {
V_202 = V_82 ;
V_203 = V_28 -> V_164 ;
} else {
V_202 = F_110 ( V_82 , ( V_82 + V_198 ) >> 2 ) ;
V_203 = V_28 -> V_164 ;
}
F_13 ( & V_91 -> V_100 ) ;
if ( V_91 -> V_112 < V_82 ) {
F_15 ( & V_91 -> V_100 ) ;
return - V_53 ;
}
F_13 ( & V_120 -> V_31 ) ;
if ( V_120 -> V_28 ) {
V_16 = 0 ;
goto V_97;
}
F_185 ( V_28 , V_6 , V_82 , V_198 ,
V_203 ) ;
F_86 ( & V_94 ) ;
V_16 = F_177 ( V_28 , V_120 , & V_94 , V_6 ,
V_82 + V_198 ,
V_202 , V_203 ) ;
if ( V_16 )
V_16 = F_178 ( V_28 , V_120 , & V_94 ,
V_6 , V_82 + V_198 ,
V_202 , V_203 ) ;
F_94 (entry, tmp, &bitmaps, list)
F_95 ( & V_85 -> V_104 ) ;
if ( ! V_16 ) {
F_172 ( & V_28 -> V_168 ) ;
F_93 ( & V_120 -> V_132 ,
& V_28 -> V_130 ) ;
V_120 -> V_28 = V_28 ;
} else {
F_186 ( V_28 ) ;
}
V_97:
F_15 ( & V_120 -> V_31 ) ;
F_15 ( & V_91 -> V_100 ) ;
return V_16 ;
}
void F_187 ( struct V_119 * V_120 )
{
F_162 ( & V_120 -> V_31 ) ;
F_162 ( & V_120 -> V_215 ) ;
V_120 -> V_3 = V_196 ;
V_120 -> V_201 = 0 ;
F_86 ( & V_120 -> V_132 ) ;
V_120 -> V_28 = NULL ;
}
static int F_188 ( struct V_27 * V_28 ,
T_1 * V_216 , T_1 V_124 , T_1 V_82 ,
T_1 V_217 , T_1 V_218 )
{
struct V_219 * V_220 = V_28 -> V_220 ;
struct V_105 * V_22 = V_28 -> V_22 ;
int V_16 ;
int V_221 = 0 ;
T_1 V_222 = 0 ;
F_13 ( & V_220 -> V_31 ) ;
F_13 ( & V_28 -> V_31 ) ;
if ( ! V_28 -> V_223 ) {
V_28 -> V_52 += V_218 ;
V_220 -> V_224 += V_218 ;
V_221 = 1 ;
}
F_15 ( & V_28 -> V_31 ) ;
F_15 ( & V_220 -> V_31 ) ;
V_16 = F_189 ( V_22 -> V_225 ,
V_124 , V_82 , & V_222 ) ;
if ( ! V_16 )
* V_216 += V_222 ;
F_159 ( V_28 , V_217 , V_218 ) ;
if ( V_221 ) {
F_13 ( & V_220 -> V_31 ) ;
F_13 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_223 )
V_220 -> V_226 += V_218 ;
V_28 -> V_52 -= V_218 ;
V_220 -> V_224 -= V_218 ;
F_15 ( & V_220 -> V_31 ) ;
F_15 ( & V_28 -> V_31 ) ;
}
return V_16 ;
}
static int F_190 ( struct V_27 * V_28 ,
T_1 * V_216 , T_1 V_124 , T_1 V_173 , T_1 V_227 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 ;
struct V_114 * V_115 ;
int V_16 = 0 ;
T_1 V_125 ;
T_1 V_162 ;
T_1 V_82 ;
while ( V_124 < V_173 ) {
F_13 ( & V_91 -> V_100 ) ;
if ( V_91 -> V_112 < V_227 ) {
F_15 ( & V_91 -> V_100 ) ;
break;
}
V_85 = F_133 ( V_91 , V_124 , 0 , 1 ) ;
if ( ! V_85 ) {
F_15 ( & V_91 -> V_100 ) ;
break;
}
while ( V_85 -> V_83 ) {
V_115 = F_108 ( & V_85 -> V_136 ) ;
if ( ! V_115 ) {
F_15 ( & V_91 -> V_100 ) ;
goto V_97;
}
V_85 = F_107 ( V_115 , struct V_88 ,
V_136 ) ;
}
if ( V_85 -> V_6 >= V_173 ) {
F_15 ( & V_91 -> V_100 ) ;
break;
}
V_125 = V_85 -> V_6 ;
V_162 = V_85 -> V_82 ;
V_124 = F_110 ( V_124 , V_125 ) ;
V_82 = F_111 ( V_125 + V_162 , V_173 ) - V_124 ;
if ( V_82 < V_227 ) {
F_15 ( & V_91 -> V_100 ) ;
goto V_131;
}
F_137 ( V_91 , V_85 ) ;
F_91 ( V_99 , V_85 ) ;
F_15 ( & V_91 -> V_100 ) ;
V_16 = F_188 ( V_28 , V_216 , V_124 , V_82 ,
V_125 , V_162 ) ;
if ( V_16 )
break;
V_131:
V_124 += V_82 ;
if ( F_191 ( V_228 ) ) {
V_16 = - V_229 ;
break;
}
F_168 () ;
}
V_97:
return V_16 ;
}
static int F_192 ( struct V_27 * V_28 ,
T_1 * V_216 , T_1 V_124 , T_1 V_173 , T_1 V_227 )
{
struct V_90 * V_91 = V_28 -> V_106 ;
struct V_88 * V_85 ;
int V_16 = 0 ;
int V_230 ;
T_1 V_82 ;
T_1 V_6 = F_127 ( V_91 , V_124 ) ;
while ( V_6 < V_173 ) {
bool V_231 = false ;
F_13 ( & V_91 -> V_100 ) ;
if ( V_91 -> V_112 < V_227 ) {
F_15 ( & V_91 -> V_100 ) ;
break;
}
V_85 = F_133 ( V_91 , V_6 , 1 , 0 ) ;
if ( ! V_85 ) {
F_15 ( & V_91 -> V_100 ) ;
V_231 = true ;
goto V_131;
}
V_82 = V_227 ;
V_230 = F_145 ( V_91 , V_85 , & V_124 , & V_82 ) ;
if ( V_230 || V_124 >= V_173 ) {
F_15 ( & V_91 -> V_100 ) ;
V_231 = true ;
goto V_131;
}
V_82 = F_111 ( V_82 , V_173 - V_124 ) ;
if ( V_82 < V_227 ) {
F_15 ( & V_91 -> V_100 ) ;
goto V_131;
}
F_142 ( V_91 , V_85 , V_124 , V_82 ) ;
if ( V_85 -> V_82 == 0 )
F_151 ( V_91 , V_85 ) ;
F_15 ( & V_91 -> V_100 ) ;
V_16 = F_188 ( V_28 , V_216 , V_124 , V_82 ,
V_124 , V_82 ) ;
if ( V_16 )
break;
V_131:
if ( V_231 ) {
V_6 += V_147 * V_91 -> V_145 ;
} else {
V_124 += V_82 ;
if ( V_124 >= V_6 + V_147 * V_91 -> V_145 )
V_6 += V_147 * V_91 -> V_145 ;
}
if ( F_191 ( V_228 ) ) {
V_16 = - V_229 ;
break;
}
F_168 () ;
}
return V_16 ;
}
int F_193 ( struct V_27 * V_28 ,
T_1 * V_222 , T_1 V_124 , T_1 V_173 , T_1 V_227 )
{
int V_16 ;
* V_222 = 0 ;
V_16 = F_190 ( V_28 , V_222 , V_124 , V_173 , V_227 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_192 ( V_28 , V_222 , V_124 , V_173 , V_227 ) ;
return V_16 ;
}
T_1 F_194 ( struct V_2 * V_232 )
{
struct V_90 * V_91 = V_232 -> V_233 ;
struct V_88 * V_85 = NULL ;
T_1 V_38 = 0 ;
F_13 ( & V_91 -> V_100 ) ;
if ( F_195 ( & V_91 -> V_134 ) )
goto V_97;
V_85 = F_107 ( F_106 ( & V_91 -> V_134 ) ,
struct V_88 , V_136 ) ;
if ( ! V_85 -> V_83 ) {
V_38 = V_85 -> V_6 ;
F_137 ( V_91 , V_85 ) ;
V_85 -> V_6 ++ ;
V_85 -> V_82 -- ;
if ( ! V_85 -> V_82 )
F_91 ( V_99 , V_85 ) ;
else
F_92 ( V_91 , V_85 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_168 = 1 ;
int V_16 ;
V_16 = F_145 ( V_91 , V_85 , & V_6 , & V_168 ) ;
F_57 ( V_16 ) ;
V_38 = V_6 ;
F_142 ( V_91 , V_85 , V_6 , 1 ) ;
if ( V_85 -> V_82 == 0 )
F_151 ( V_91 , V_85 ) ;
}
V_97:
F_15 ( & V_91 -> V_100 ) ;
return V_38 ;
}
struct V_1 * F_196 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_13 ( & V_3 -> V_234 ) ;
if ( V_3 -> V_235 )
V_1 = F_14 ( V_3 -> V_235 ) ;
F_15 ( & V_3 -> V_234 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_13 ( & V_3 -> V_234 ) ;
if ( ! F_99 ( V_3 -> V_22 ) )
V_3 -> V_235 = F_14 ( V_1 ) ;
F_15 ( & V_3 -> V_234 ) ;
return V_1 ;
}
int F_197 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
return F_18 ( V_3 , V_37 , V_5 ,
V_43 , 0 ) ;
}
int F_198 ( struct V_105 * V_22 , struct V_2 * V_3 )
{
struct V_90 * V_91 = V_3 -> V_233 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_236 = F_199 ( & V_3 -> V_237 ) ;
if ( ! F_184 ( V_3 , V_238 ) )
return 0 ;
if ( F_99 ( V_22 ) )
return 0 ;
V_5 = F_100 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_196 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_97;
if ( V_236 != F_16 ( V_1 ) -> V_77 )
goto V_239;
V_16 = F_85 ( V_3 , V_1 , V_91 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_17 ( V_75 L_25
L_26 , V_3 -> V_240 . V_17 ) ;
V_239:
F_11 ( V_1 ) ;
V_97:
F_101 ( V_5 ) ;
return V_16 ;
}
int F_200 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 = V_3 -> V_233 ;
struct V_1 * V_1 ;
int V_16 ;
if ( ! F_184 ( V_3 , V_238 ) )
return 0 ;
V_1 = F_196 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_102 ( V_3 , V_1 , V_91 , NULL , V_37 , V_5 , 0 ) ;
if ( V_16 ) {
F_201 ( V_1 , V_1 -> V_139 ) ;
#ifdef F_123
F_17 ( V_75 L_27
L_28 , V_3 -> V_240 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
