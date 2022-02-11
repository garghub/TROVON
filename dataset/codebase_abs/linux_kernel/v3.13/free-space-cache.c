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
F_19 ( V_3 -> V_22 ,
L_1 ) ;
F_18 ( V_1 ) -> V_28 |= V_29 |
V_30 ;
V_27 -> V_32 = V_33 ;
}
if ( ! V_27 -> V_34 ) {
V_27 -> V_1 = F_16 ( V_1 ) ;
V_27 -> V_34 = 1 ;
}
F_17 ( & V_27 -> V_31 ) ;
return V_1 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 ,
T_1 V_37 , T_1 V_6 )
{
struct V_7 V_8 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_38 * V_39 ;
struct V_14 * V_15 ;
T_1 V_28 = V_40 | V_41 ;
int V_16 ;
V_16 = F_21 ( V_36 , V_3 , V_5 , V_37 ) ;
if ( V_16 )
return V_16 ;
if ( V_37 != V_42 )
V_28 |= V_29 | V_30 ;
V_15 = V_5 -> V_20 [ 0 ] ;
V_39 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_38 ) ;
F_22 ( V_15 , & V_11 , V_5 -> V_21 [ 0 ] ) ;
F_23 ( V_15 , 0 , ( unsigned long ) V_39 ,
sizeof( * V_39 ) ) ;
F_24 ( V_15 , V_39 , V_36 -> V_43 ) ;
F_25 ( V_15 , V_39 , 0 ) ;
F_26 ( V_15 , V_39 , 0 ) ;
F_27 ( V_15 , V_39 , 0 ) ;
F_28 ( V_15 , V_39 , 0 ) ;
F_29 ( V_15 , V_39 , V_44 | 0600 ) ;
F_30 ( V_15 , V_39 , V_28 ) ;
F_31 ( V_15 , V_39 , 1 ) ;
F_32 ( V_15 , V_39 , V_36 -> V_43 ) ;
F_33 ( V_15 , V_39 , V_6 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_35 ( V_36 , V_3 , V_5 , & V_8 ,
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
struct V_35 * V_36 ,
struct V_26 * V_27 ,
struct V_4 * V_5 )
{
int V_16 ;
T_1 V_37 ;
V_16 = F_38 ( V_3 , & V_37 ) ;
if ( V_16 < 0 )
return V_16 ;
return F_20 ( V_3 , V_36 , V_5 , V_37 ,
V_27 -> V_8 . V_17 ) ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_45 * V_46 )
{
T_1 V_47 ;
int V_16 ;
V_47 = F_40 ( V_3 , 1 ) +
F_41 ( V_3 , 1 ) ;
F_15 ( & V_46 -> V_31 ) ;
if ( V_46 -> V_48 < V_47 )
V_16 = - V_49 ;
else
V_16 = 0 ;
F_17 ( & V_46 -> V_31 ) ;
return V_16 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_1 * V_1 )
{
int V_16 = 0 ;
F_43 ( V_1 , 0 ) ;
F_44 ( V_1 , 0 ) ;
V_16 = F_45 ( V_36 , V_3 , V_1 ,
0 , V_50 ) ;
if ( V_16 ) {
F_46 ( V_36 , V_3 , V_16 ) ;
return V_16 ;
}
V_16 = F_47 ( V_36 , V_3 , V_1 ) ;
if ( V_16 )
F_46 ( V_36 , V_3 , V_16 ) ;
return V_16 ;
}
static int F_48 ( struct V_1 * V_1 )
{
struct V_51 * V_52 ;
unsigned long V_53 ;
V_52 = F_49 ( sizeof( * V_52 ) , V_54 ) ;
if ( ! V_52 )
return - V_55 ;
F_50 ( V_52 , V_1 -> V_24 ) ;
V_53 = ( F_51 ( V_1 ) - 1 ) >> V_56 ;
F_52 ( V_1 -> V_24 , V_52 , NULL , 0 , V_53 ) ;
F_53 ( V_52 ) ;
return 0 ;
}
static int F_54 ( struct V_57 * V_57 , struct V_1 * V_1 ,
struct V_2 * V_3 )
{
memset ( V_57 , 0 , sizeof( struct V_57 ) ) ;
V_57 -> V_58 = ( F_51 ( V_1 ) + V_59 - 1 ) >>
V_56 ;
V_57 -> V_60 = F_49 ( sizeof( struct V_61 * ) * V_57 -> V_58 ,
V_54 ) ;
if ( ! V_57 -> V_60 )
return - V_55 ;
V_57 -> V_3 = V_3 ;
if ( F_55 ( V_1 ) != V_42 )
V_57 -> V_62 = 1 ;
return 0 ;
}
static void F_56 ( struct V_57 * V_57 )
{
F_53 ( V_57 -> V_60 ) ;
}
static void F_57 ( struct V_57 * V_57 )
{
if ( V_57 -> V_63 ) {
F_58 ( V_57 -> V_61 ) ;
V_57 -> V_63 = NULL ;
V_57 -> V_64 = NULL ;
}
}
static void F_59 ( struct V_57 * V_57 , int V_65 )
{
ASSERT ( V_57 -> V_66 < V_57 -> V_58 ) ;
V_57 -> V_61 = V_57 -> V_60 [ V_57 -> V_66 ++ ] ;
V_57 -> V_63 = F_60 ( V_57 -> V_61 ) ;
V_57 -> V_64 = V_57 -> V_63 ;
V_57 -> V_67 = V_59 ;
if ( V_65 )
memset ( V_57 -> V_63 , 0 , V_59 ) ;
}
static void F_61 ( struct V_57 * V_57 )
{
int V_68 ;
F_57 ( V_57 ) ;
for ( V_68 = 0 ; V_68 < V_57 -> V_58 ; V_68 ++ ) {
if ( V_57 -> V_60 [ V_68 ] ) {
F_62 ( V_57 -> V_60 [ V_68 ] ) ;
F_63 ( V_57 -> V_60 [ V_68 ] ) ;
F_64 ( V_57 -> V_60 [ V_68 ] ) ;
}
}
}
static int F_65 ( struct V_57 * V_57 , struct V_1 * V_1 ,
int V_69 )
{
struct V_61 * V_61 ;
T_3 V_70 = F_66 ( V_1 -> V_24 ) ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_57 -> V_58 ; V_68 ++ ) {
V_61 = F_67 ( V_1 -> V_24 , V_68 , V_70 ) ;
if ( ! V_61 ) {
F_61 ( V_57 ) ;
return - V_55 ;
}
V_57 -> V_60 [ V_68 ] = V_61 ;
if ( V_69 && ! F_68 ( V_61 ) ) {
F_69 ( NULL , V_61 ) ;
F_70 ( V_61 ) ;
if ( ! F_68 ( V_61 ) ) {
F_71 ( V_71 L_2
L_3 ) ;
F_61 ( V_57 ) ;
return - V_72 ;
}
}
}
for ( V_68 = 0 ; V_68 < V_57 -> V_58 ; V_68 ++ ) {
F_72 ( V_57 -> V_60 [ V_68 ] ) ;
F_73 ( V_57 -> V_60 [ V_68 ] ) ;
}
return 0 ;
}
static void F_74 ( struct V_57 * V_57 , T_1 V_73 )
{
T_4 * V_74 ;
F_59 ( V_57 , 1 ) ;
if ( V_57 -> V_62 ) {
V_57 -> V_63 += ( sizeof( T_2 ) * V_57 -> V_58 ) ;
V_57 -> V_67 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_57 -> V_58 ) ;
} else {
V_57 -> V_63 += sizeof( T_1 ) ;
V_57 -> V_67 -= sizeof( T_1 ) * 2 ;
}
V_74 = V_57 -> V_63 ;
* V_74 = F_75 ( V_73 ) ;
V_57 -> V_63 += sizeof( T_1 ) ;
}
static int F_76 ( struct V_57 * V_57 , T_1 V_73 )
{
T_4 * V_75 ;
if ( V_57 -> V_62 ) {
V_57 -> V_63 += sizeof( T_2 ) * V_57 -> V_58 ;
V_57 -> V_67 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_57 -> V_58 ) ;
} else {
V_57 -> V_63 += sizeof( T_1 ) ;
V_57 -> V_67 -= sizeof( T_1 ) * 2 ;
}
V_75 = V_57 -> V_63 ;
if ( F_77 ( * V_75 ) != V_73 ) {
F_78 ( V_71 L_4
L_5 , * V_75 ,
V_73 ) ;
F_57 ( V_57 ) ;
return - V_72 ;
}
V_57 -> V_63 += sizeof( T_1 ) ;
return 0 ;
}
static void F_79 ( struct V_57 * V_57 , int V_66 )
{
T_2 * V_76 ;
T_2 V_77 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_62 ) {
F_57 ( V_57 ) ;
return;
}
if ( V_66 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_58 ;
V_77 = F_80 ( V_57 -> V_64 + V_6 , V_77 ,
V_59 - V_6 ) ;
F_81 ( V_77 , ( char * ) & V_77 ) ;
F_57 ( V_57 ) ;
V_76 = F_60 ( V_57 -> V_60 [ 0 ] ) ;
V_76 += V_66 ;
* V_76 = V_77 ;
F_58 ( V_57 -> V_60 [ 0 ] ) ;
}
static int F_82 ( struct V_57 * V_57 , int V_66 )
{
T_2 * V_76 , V_74 ;
T_2 V_77 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_62 ) {
F_59 ( V_57 , 0 ) ;
return 0 ;
}
if ( V_66 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_58 ;
V_76 = F_60 ( V_57 -> V_60 [ 0 ] ) ;
V_76 += V_66 ;
V_74 = * V_76 ;
F_58 ( V_57 -> V_60 [ 0 ] ) ;
F_59 ( V_57 , 0 ) ;
V_77 = F_80 ( V_57 -> V_64 + V_6 , V_77 ,
V_59 - V_6 ) ;
F_81 ( V_77 , ( char * ) & V_77 ) ;
if ( V_74 != V_77 ) {
F_78 ( V_71 L_6
L_3 ) ;
F_57 ( V_57 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_83 ( struct V_57 * V_57 , T_1 V_6 , T_1 V_78 ,
void * V_79 )
{
struct V_80 * V_81 ;
if ( ! V_57 -> V_63 )
return - V_49 ;
V_81 = V_57 -> V_63 ;
V_81 -> V_6 = F_75 ( V_6 ) ;
V_81 -> V_78 = F_75 ( V_78 ) ;
V_81 -> type = ( V_79 ) ? V_82 :
V_83 ;
V_57 -> V_63 += sizeof( struct V_80 ) ;
V_57 -> V_67 -= sizeof( struct V_80 ) ;
if ( V_57 -> V_67 >= sizeof( struct V_80 ) )
return 0 ;
F_79 ( V_57 , V_57 -> V_66 - 1 ) ;
if ( V_57 -> V_66 >= V_57 -> V_58 )
return 0 ;
F_59 ( V_57 , 1 ) ;
return 0 ;
}
static int F_84 ( struct V_57 * V_57 , void * V_79 )
{
if ( ! V_57 -> V_63 )
return - V_49 ;
if ( V_57 -> V_63 != V_57 -> V_64 ) {
F_79 ( V_57 , V_57 -> V_66 - 1 ) ;
if ( V_57 -> V_66 >= V_57 -> V_58 )
return - V_49 ;
F_59 ( V_57 , 0 ) ;
}
memcpy ( V_57 -> V_63 , V_79 , V_59 ) ;
F_79 ( V_57 , V_57 -> V_66 - 1 ) ;
if ( V_57 -> V_66 < V_57 -> V_58 )
F_59 ( V_57 , 0 ) ;
return 0 ;
}
static void F_85 ( struct V_57 * V_57 )
{
if ( V_57 -> V_63 != V_57 -> V_64 )
F_79 ( V_57 , V_57 -> V_66 - 1 ) ;
else
F_57 ( V_57 ) ;
while ( V_57 -> V_66 < V_57 -> V_58 ) {
F_59 ( V_57 , 1 ) ;
F_79 ( V_57 , V_57 -> V_66 - 1 ) ;
}
}
static int F_86 ( struct V_57 * V_57 ,
struct V_84 * V_81 , T_5 * type )
{
struct V_80 * V_85 ;
int V_16 ;
if ( ! V_57 -> V_63 ) {
V_16 = F_82 ( V_57 , V_57 -> V_66 ) ;
if ( V_16 )
return V_16 ;
}
V_85 = V_57 -> V_63 ;
V_81 -> V_6 = F_77 ( V_85 -> V_6 ) ;
V_81 -> V_78 = F_77 ( V_85 -> V_78 ) ;
* type = V_85 -> type ;
V_57 -> V_63 += sizeof( struct V_80 ) ;
V_57 -> V_67 -= sizeof( struct V_80 ) ;
if ( V_57 -> V_67 >= sizeof( struct V_80 ) )
return 0 ;
F_57 ( V_57 ) ;
return 0 ;
}
static int F_87 ( struct V_57 * V_57 ,
struct V_84 * V_81 )
{
int V_16 ;
V_16 = F_82 ( V_57 , V_57 -> V_66 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_81 -> V_79 , V_57 -> V_63 , V_59 ) ;
F_57 ( V_57 ) ;
return 0 ;
}
static void F_88 ( struct V_86 * V_87 )
{
struct V_84 * V_85 , * V_88 = NULL ;
struct V_89 * V_90 ;
V_91:
F_15 ( & V_87 -> V_92 ) ;
for ( V_90 = F_89 ( & V_87 -> V_93 ) ; V_90 ; V_90 = F_90 ( V_90 ) ) {
V_85 = F_91 ( V_90 , struct V_84 , V_94 ) ;
if ( ! V_88 )
goto V_95;
if ( V_85 -> V_79 || V_88 -> V_79 )
goto V_95;
if ( V_88 -> V_6 + V_88 -> V_78 == V_85 -> V_6 ) {
F_92 ( V_87 , V_88 ) ;
F_92 ( V_87 , V_85 ) ;
V_88 -> V_78 += V_85 -> V_78 ;
F_93 ( V_96 , V_85 ) ;
F_94 ( V_87 , V_88 ) ;
V_88 = NULL ;
F_17 ( & V_87 -> V_92 ) ;
goto V_91;
}
V_95:
V_88 = V_85 ;
}
F_17 ( & V_87 -> V_92 ) ;
}
static int F_95 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_86 * V_87 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_57 V_57 ;
struct V_7 V_8 ;
struct V_84 * V_85 , * V_90 ;
struct V_97 V_98 ;
T_1 V_99 ;
T_1 V_100 ;
T_1 V_73 ;
T_5 type ;
int V_16 = 0 ;
F_96 ( & V_98 ) ;
if ( ! F_51 ( V_1 ) )
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
V_99 = F_97 ( V_15 , V_13 ) ;
V_100 = F_98 ( V_15 , V_13 ) ;
V_73 = F_99 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( F_18 ( V_1 ) -> V_73 != V_73 ) {
F_100 ( V_3 -> V_22 ,
L_7
L_8 ,
F_18 ( V_1 ) -> V_73 , V_73 ) ;
return 0 ;
}
if ( ! V_99 )
return 0 ;
V_16 = F_54 ( & V_57 , V_1 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_48 ( V_1 ) ;
if ( V_16 )
goto V_101;
V_16 = F_65 ( & V_57 , V_1 , 1 ) ;
if ( V_16 )
goto V_101;
V_16 = F_82 ( & V_57 , 0 ) ;
if ( V_16 )
goto V_102;
V_16 = F_76 ( & V_57 , V_73 ) ;
if ( V_16 )
goto V_102;
while ( V_99 ) {
V_85 = F_101 ( V_96 ,
V_54 ) ;
if ( ! V_85 )
goto V_102;
V_16 = F_86 ( & V_57 , V_85 , & type ) ;
if ( V_16 ) {
F_93 ( V_96 , V_85 ) ;
goto V_102;
}
if ( ! V_85 -> V_78 ) {
F_93 ( V_96 , V_85 ) ;
goto V_102;
}
if ( type == V_83 ) {
F_15 ( & V_87 -> V_92 ) ;
V_16 = F_94 ( V_87 , V_85 ) ;
F_17 ( & V_87 -> V_92 ) ;
if ( V_16 ) {
F_100 ( V_3 -> V_22 ,
L_9 ) ;
F_93 ( V_96 , V_85 ) ;
goto V_102;
}
} else {
ASSERT ( V_100 ) ;
V_100 -- ;
V_85 -> V_79 = F_49 ( V_59 , V_54 ) ;
if ( ! V_85 -> V_79 ) {
F_93 (
V_96 , V_85 ) ;
goto V_102;
}
F_15 ( & V_87 -> V_92 ) ;
V_16 = F_94 ( V_87 , V_85 ) ;
V_87 -> V_103 ++ ;
V_87 -> V_104 -> V_105 ( V_87 ) ;
F_17 ( & V_87 -> V_92 ) ;
if ( V_16 ) {
F_100 ( V_3 -> V_22 ,
L_9 ) ;
F_93 ( V_96 , V_85 ) ;
goto V_102;
}
F_102 ( & V_85 -> V_106 , & V_98 ) ;
}
V_99 -- ;
}
F_57 ( & V_57 ) ;
F_103 (e, n, &bitmaps, list) {
F_104 ( & V_85 -> V_106 ) ;
V_16 = F_87 ( & V_57 , V_85 ) ;
if ( V_16 )
goto V_102;
}
F_61 ( & V_57 ) ;
F_88 ( V_87 ) ;
V_16 = 1 ;
V_101:
F_56 ( & V_57 ) ;
return V_16 ;
V_102:
F_61 ( & V_57 ) ;
F_105 ( V_87 ) ;
goto V_101;
}
int F_106 ( struct V_107 * V_22 ,
struct V_26 * V_27 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_2 * V_3 = V_22 -> V_109 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 = 0 ;
bool V_110 ;
T_1 V_111 = F_107 ( & V_27 -> V_112 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 != V_113 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_5 = F_108 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_114 = 1 ;
V_5 -> V_115 = 1 ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_109 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 != V_113 ) {
F_17 ( & V_27 -> V_31 ) ;
F_109 ( V_5 ) ;
goto V_101;
}
F_17 ( & V_27 -> V_31 ) ;
V_16 = F_95 ( V_22 -> V_109 , V_1 , V_87 ,
V_5 , V_27 -> V_8 . V_17 ) ;
F_109 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_101;
F_15 ( & V_87 -> V_92 ) ;
V_110 = ( V_87 -> V_116 == ( V_27 -> V_8 . V_6 - V_111 -
V_27 -> V_117 ) ) ;
F_17 ( & V_87 -> V_92 ) ;
if ( ! V_110 ) {
F_105 ( V_87 ) ;
F_100 ( V_22 , L_10 ,
V_27 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_101:
if ( V_16 < 0 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_32 = V_33 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
F_100 ( V_22 , L_11 ,
V_27 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
static int F_110 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_86 * V_87 ,
struct V_26 * V_27 ,
struct V_35 * V_36 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_89 * V_118 ;
struct V_97 * V_119 , * V_90 ;
struct V_120 * V_121 = NULL ;
struct V_122 * V_123 = NULL ;
struct V_124 * V_125 = NULL ;
struct V_57 V_57 ;
struct V_97 V_126 ;
struct V_7 V_8 ;
T_1 V_127 , V_128 , V_129 , V_130 ;
int V_131 = 0 ;
int V_98 = 0 ;
int V_16 ;
int V_132 = - 1 ;
F_96 ( & V_126 ) ;
if ( ! F_51 ( V_1 ) )
return - 1 ;
V_16 = F_54 ( & V_57 , V_1 , V_3 ) ;
if ( V_16 )
return - 1 ;
if ( V_27 && ! F_111 ( & V_27 -> V_133 ) )
V_123 = F_112 ( V_27 -> V_133 . V_95 ,
struct V_122 ,
V_134 ) ;
F_65 ( & V_57 , V_1 , 0 ) ;
F_113 ( & F_18 ( V_1 ) -> V_135 , 0 , F_51 ( V_1 ) - 1 ,
0 , & V_121 ) ;
V_118 = F_89 ( & V_87 -> V_93 ) ;
if ( ! V_118 && V_123 ) {
V_118 = F_89 ( & V_123 -> V_3 ) ;
V_123 = NULL ;
}
if ( V_57 . V_62 &&
( V_57 . V_58 * sizeof( T_2 ) ) >= V_59 )
goto V_136;
F_74 ( & V_57 , V_36 -> V_43 ) ;
while ( V_118 ) {
struct V_84 * V_85 ;
V_85 = F_91 ( V_118 , struct V_84 , V_94 ) ;
V_131 ++ ;
V_16 = F_83 ( & V_57 , V_85 -> V_6 , V_85 -> V_78 ,
V_85 -> V_79 ) ;
if ( V_16 )
goto V_136;
if ( V_85 -> V_79 ) {
F_102 ( & V_85 -> V_106 , & V_126 ) ;
V_98 ++ ;
}
V_118 = F_90 ( V_118 ) ;
if ( ! V_118 && V_123 ) {
V_118 = F_89 ( & V_123 -> V_3 ) ;
V_123 = NULL ;
}
}
V_125 = V_3 -> V_22 -> V_137 ;
if ( V_27 )
V_127 = V_27 -> V_8 . V_17 ;
while ( V_27 && ( V_127 < V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 ) ) {
V_16 = F_114 ( V_125 , V_127 ,
& V_128 , & V_129 ,
V_138 , NULL ) ;
if ( V_16 ) {
V_16 = 0 ;
break;
}
if ( V_128 >= V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 )
break;
V_128 = F_115 ( V_128 , V_127 ) ;
V_129 = F_116 ( V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 , V_129 + 1 ) ;
V_130 = V_129 - V_128 ;
V_131 ++ ;
V_16 = F_83 ( & V_57 , V_128 , V_130 , NULL ) ;
if ( V_16 )
goto V_136;
V_127 = V_129 ;
}
F_117 (pos, n, &bitmap_list) {
struct V_84 * V_81 =
F_112 ( V_119 , struct V_84 , V_106 ) ;
V_16 = F_84 ( & V_57 , V_81 -> V_79 ) ;
if ( V_16 )
goto V_136;
F_104 ( & V_81 -> V_106 ) ;
}
F_85 ( & V_57 ) ;
V_16 = F_118 ( V_3 , V_1 , V_57 . V_60 , V_57 . V_58 ,
0 , F_51 ( V_1 ) , & V_121 ) ;
F_61 ( & V_57 ) ;
F_119 ( & F_18 ( V_1 ) -> V_135 , 0 ,
F_51 ( V_1 ) - 1 , & V_121 , V_54 ) ;
if ( V_16 )
goto V_101;
V_16 = F_120 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_16 ) {
F_121 ( & F_18 ( V_1 ) -> V_135 , 0 , V_1 -> V_139 - 1 ,
V_138 | V_140 , 0 , 0 , NULL ,
V_54 ) ;
goto V_101;
}
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_36 , V_3 , & V_8 , V_5 , 0 , 1 ) ;
if ( V_16 < 0 ) {
F_121 ( & F_18 ( V_1 ) -> V_135 , 0 , V_1 -> V_139 - 1 ,
V_138 | V_140 , 0 , 0 , NULL ,
V_54 ) ;
goto V_101;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_141 ;
ASSERT ( V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_122 ( V_15 , & V_141 , V_5 -> V_21 [ 0 ] ) ;
if ( V_141 . V_17 != V_18 ||
V_141 . V_6 != V_6 ) {
F_121 ( & F_18 ( V_1 ) -> V_135 , 0 ,
V_1 -> V_139 - 1 ,
V_138 | V_140 , 0 , 0 ,
NULL , V_54 ) ;
F_4 ( V_5 ) ;
goto V_101;
}
}
F_18 ( V_1 ) -> V_73 = V_36 -> V_43 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_123 ( V_15 , V_13 , V_131 ) ;
F_124 ( V_15 , V_13 , V_98 ) ;
F_125 ( V_15 , V_13 , V_36 -> V_43 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
V_132 = 0 ;
V_101:
F_56 ( & V_57 ) ;
if ( V_132 ) {
F_126 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_73 = 0 ;
}
F_47 ( V_36 , V_3 , V_1 ) ;
return V_132 ;
V_136:
F_117 (pos, n, &bitmap_list) {
struct V_84 * V_81 =
F_112 ( V_119 , struct V_84 , V_106 ) ;
F_104 ( & V_81 -> V_106 ) ;
}
F_61 ( & V_57 ) ;
F_119 ( & F_18 ( V_1 ) -> V_135 , 0 ,
F_51 ( V_1 ) - 1 , & V_121 , V_54 ) ;
goto V_101;
}
int F_127 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_26 * V_27 ,
struct V_4 * V_5 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_109 ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 < V_142 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_110 ( V_3 , V_1 , V_87 , V_27 , V_36 ,
V_5 , V_27 -> V_8 . V_17 ) ;
if ( V_16 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_32 = V_143 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
#ifdef F_128
F_100 ( V_3 -> V_22 ,
L_12 ,
V_27 -> V_8 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_129 ( T_1 V_144 , T_2 V_145 ,
T_1 V_6 )
{
ASSERT ( V_6 >= V_144 ) ;
V_6 -= V_144 ;
return ( unsigned long ) ( F_130 ( V_6 , V_145 ) ) ;
}
static inline unsigned long F_131 ( T_1 V_78 , T_2 V_145 )
{
return ( unsigned long ) ( F_130 ( V_78 , V_145 ) ) ;
}
static inline T_1 F_132 ( struct V_86 * V_87 ,
T_1 V_6 )
{
T_1 V_144 ;
T_1 V_146 ;
V_146 = V_147 * V_87 -> V_145 ;
V_144 = V_6 - V_87 -> V_127 ;
V_144 = F_133 ( V_144 , V_146 ) ;
V_144 *= V_146 ;
V_144 += V_87 -> V_127 ;
return V_144 ;
}
static int F_134 ( struct V_148 * V_3 , T_1 V_6 ,
struct V_89 * V_118 , int V_79 )
{
struct V_89 * * V_149 = & V_3 -> V_89 ;
struct V_89 * V_150 = NULL ;
struct V_84 * V_151 ;
while ( * V_149 ) {
V_150 = * V_149 ;
V_151 = F_91 ( V_150 , struct V_84 , V_94 ) ;
if ( V_6 < V_151 -> V_6 ) {
V_149 = & ( * V_149 ) -> V_152 ;
} else if ( V_6 > V_151 -> V_6 ) {
V_149 = & ( * V_149 ) -> V_153 ;
} else {
if ( V_79 ) {
if ( V_151 -> V_79 ) {
F_135 ( 1 ) ;
return - V_154 ;
}
V_149 = & ( * V_149 ) -> V_153 ;
} else {
if ( ! V_151 -> V_79 ) {
F_135 ( 1 ) ;
return - V_154 ;
}
V_149 = & ( * V_149 ) -> V_152 ;
}
}
}
F_136 ( V_118 , V_150 , V_149 ) ;
F_137 ( V_118 , V_3 ) ;
return 0 ;
}
static struct V_84 *
F_138 ( struct V_86 * V_87 ,
T_1 V_6 , int V_155 , int V_156 )
{
struct V_89 * V_90 = V_87 -> V_93 . V_89 ;
struct V_84 * V_81 , * V_88 = NULL ;
while ( 1 ) {
if ( ! V_90 ) {
V_81 = NULL ;
break;
}
V_81 = F_91 ( V_90 , struct V_84 , V_94 ) ;
V_88 = V_81 ;
if ( V_6 < V_81 -> V_6 )
V_90 = V_90 -> V_152 ;
else if ( V_6 > V_81 -> V_6 )
V_90 = V_90 -> V_153 ;
else
break;
}
if ( V_155 ) {
if ( ! V_81 )
return NULL ;
if ( V_81 -> V_79 )
return V_81 ;
V_90 = F_90 ( V_90 ) ;
if ( ! V_90 )
return NULL ;
V_81 = F_91 ( V_90 , struct V_84 , V_94 ) ;
if ( V_81 -> V_6 != V_6 )
return NULL ;
F_139 ( ! V_81 -> V_79 ) ;
return V_81 ;
} else if ( V_81 ) {
if ( V_81 -> V_79 ) {
V_90 = F_140 ( & V_81 -> V_94 ) ;
if ( V_90 ) {
V_88 = F_91 ( V_90 , struct V_84 ,
V_94 ) ;
if ( ! V_88 -> V_79 &&
V_88 -> V_6 + V_88 -> V_78 > V_6 )
V_81 = V_88 ;
}
}
return V_81 ;
}
if ( ! V_88 )
return NULL ;
V_81 = V_88 ;
if ( V_81 -> V_6 > V_6 ) {
V_90 = F_140 ( & V_81 -> V_94 ) ;
if ( V_90 ) {
V_81 = F_91 ( V_90 , struct V_84 ,
V_94 ) ;
ASSERT ( V_81 -> V_6 <= V_6 ) ;
} else {
if ( V_156 )
return V_81 ;
else
return NULL ;
}
}
if ( V_81 -> V_79 ) {
V_90 = F_140 ( & V_81 -> V_94 ) ;
if ( V_90 ) {
V_88 = F_91 ( V_90 , struct V_84 ,
V_94 ) ;
if ( ! V_88 -> V_79 &&
V_88 -> V_6 + V_88 -> V_78 > V_6 )
return V_88 ;
}
if ( V_81 -> V_6 + V_147 * V_87 -> V_145 > V_6 )
return V_81 ;
} else if ( V_81 -> V_6 + V_81 -> V_78 > V_6 )
return V_81 ;
if ( ! V_156 )
return NULL ;
while ( 1 ) {
if ( V_81 -> V_79 ) {
if ( V_81 -> V_6 + V_147 *
V_87 -> V_145 > V_6 )
break;
} else {
if ( V_81 -> V_6 + V_81 -> V_78 > V_6 )
break;
}
V_90 = F_90 ( & V_81 -> V_94 ) ;
if ( ! V_90 )
return NULL ;
V_81 = F_91 ( V_90 , struct V_84 , V_94 ) ;
}
return V_81 ;
}
static inline void
F_141 ( struct V_86 * V_87 ,
struct V_84 * V_151 )
{
F_142 ( & V_151 -> V_94 , & V_87 -> V_93 ) ;
V_87 -> V_157 -- ;
}
static void F_92 ( struct V_86 * V_87 ,
struct V_84 * V_151 )
{
F_141 ( V_87 , V_151 ) ;
V_87 -> V_116 -= V_151 -> V_78 ;
}
static int F_94 ( struct V_86 * V_87 ,
struct V_84 * V_151 )
{
int V_16 = 0 ;
ASSERT ( V_151 -> V_78 || V_151 -> V_79 ) ;
V_16 = F_134 ( & V_87 -> V_93 , V_151 -> V_6 ,
& V_151 -> V_94 , ( V_151 -> V_79 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_87 -> V_116 += V_151 -> V_78 ;
V_87 -> V_157 ++ ;
return V_16 ;
}
static void F_143 ( struct V_86 * V_87 )
{
struct V_26 * V_27 = V_87 -> V_158 ;
T_1 V_159 ;
T_1 V_160 ;
T_1 V_161 ;
T_1 V_67 = V_27 -> V_8 . V_6 ;
T_1 V_162 = V_147 * V_87 -> V_145 ;
int V_163 = F_133 ( V_67 + V_162 - 1 , V_162 ) ;
V_163 = F_115 ( V_163 , 1 ) ;
ASSERT ( V_87 -> V_103 <= V_163 ) ;
if ( V_67 < 1024 * 1024 * 1024 )
V_159 = V_164 ;
else
V_159 = V_164 *
F_133 ( V_67 , 1024 * 1024 * 1024 ) ;
V_160 = ( V_87 -> V_103 + 1 ) * V_59 ;
if ( V_160 >= V_159 ) {
V_87 -> V_165 = 0 ;
return;
}
V_161 = V_159 - V_160 ;
V_161 = F_144 ( T_1 , V_161 , F_133 ( V_159 , 2 ) ) ;
V_87 -> V_165 =
F_133 ( V_161 , ( sizeof( struct V_84 ) ) ) ;
}
static inline void F_145 ( struct V_86 * V_87 ,
struct V_84 * V_151 ,
T_1 V_6 , T_1 V_78 )
{
unsigned long V_127 , V_166 ;
V_127 = F_129 ( V_151 -> V_6 , V_87 -> V_145 , V_6 ) ;
V_166 = F_131 ( V_78 , V_87 -> V_145 ) ;
ASSERT ( V_127 + V_166 <= V_147 ) ;
F_146 ( V_151 -> V_79 , V_127 , V_166 ) ;
V_151 -> V_78 -= V_78 ;
}
static void F_147 ( struct V_86 * V_87 ,
struct V_84 * V_151 , T_1 V_6 ,
T_1 V_78 )
{
F_145 ( V_87 , V_151 , V_6 , V_78 ) ;
V_87 -> V_116 -= V_78 ;
}
static void F_148 ( struct V_86 * V_87 ,
struct V_84 * V_151 , T_1 V_6 ,
T_1 V_78 )
{
unsigned long V_127 , V_166 ;
V_127 = F_129 ( V_151 -> V_6 , V_87 -> V_145 , V_6 ) ;
V_166 = F_131 ( V_78 , V_87 -> V_145 ) ;
ASSERT ( V_127 + V_166 <= V_147 ) ;
F_149 ( V_151 -> V_79 , V_127 , V_166 ) ;
V_151 -> V_78 += V_78 ;
V_87 -> V_116 += V_78 ;
}
static int F_150 ( struct V_86 * V_87 ,
struct V_84 * V_167 , T_1 * V_6 ,
T_1 * V_78 )
{
unsigned long V_168 = 0 ;
unsigned long V_169 = 0 ;
unsigned long V_170 , V_68 ;
unsigned long V_171 ;
unsigned long V_172 ;
V_68 = F_129 ( V_167 -> V_6 , V_87 -> V_145 ,
F_151 ( T_1 , * V_6 , V_167 -> V_6 ) ) ;
V_170 = F_131 ( * V_78 , V_87 -> V_145 ) ;
F_152 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
V_171 = F_153 ( V_167 -> V_79 ,
V_147 , V_68 ) ;
V_172 = V_171 - V_68 ;
if ( V_172 >= V_170 ) {
V_168 = V_172 ;
break;
} else if ( V_172 > V_169 ) {
V_169 = V_172 ;
}
V_68 = V_171 ;
}
if ( V_168 ) {
* V_6 = ( T_1 ) ( V_68 * V_87 -> V_145 ) + V_167 -> V_6 ;
* V_78 = ( T_1 ) ( V_168 ) * V_87 -> V_145 ;
return 0 ;
}
* V_78 = ( T_1 ) ( V_169 ) * V_87 -> V_145 ;
return - 1 ;
}
static struct V_84 *
F_154 ( struct V_86 * V_87 , T_1 * V_6 , T_1 * V_78 ,
unsigned long V_173 , T_1 * V_174 )
{
struct V_84 * V_81 ;
struct V_89 * V_118 ;
T_1 V_76 ;
T_1 V_175 ;
int V_16 ;
if ( ! V_87 -> V_93 . V_89 )
goto V_101;
V_81 = F_138 ( V_87 , F_132 ( V_87 , * V_6 ) , 0 , 1 ) ;
if ( ! V_81 )
goto V_101;
for ( V_118 = & V_81 -> V_94 ; V_118 ; V_118 = F_90 ( V_118 ) ) {
V_81 = F_91 ( V_118 , struct V_84 , V_94 ) ;
if ( V_81 -> V_78 < * V_78 ) {
if ( V_81 -> V_78 > * V_174 )
* V_174 = V_81 -> V_78 ;
continue;
}
if ( * V_78 >= V_173 ) {
V_76 = V_81 -> V_6 - V_87 -> V_127 + V_173 - 1 ;
F_155 ( V_76 , V_173 ) ;
V_76 = V_76 * V_173 + V_87 -> V_127 ;
V_175 = V_76 - V_81 -> V_6 ;
} else {
V_175 = 0 ;
V_76 = V_81 -> V_6 ;
}
if ( V_81 -> V_78 < * V_78 + V_175 ) {
if ( V_81 -> V_78 > * V_174 )
* V_174 = V_81 -> V_78 ;
continue;
}
if ( V_81 -> V_79 ) {
T_1 V_67 = * V_78 ;
V_16 = F_150 ( V_87 , V_81 , & V_76 , & V_67 ) ;
if ( ! V_16 ) {
* V_6 = V_76 ;
* V_78 = V_67 ;
return V_81 ;
} else if ( V_67 > * V_174 ) {
* V_174 = V_67 ;
}
continue;
}
* V_6 = V_76 ;
* V_78 = V_81 -> V_78 - V_175 ;
return V_81 ;
}
V_101:
return NULL ;
}
static void F_156 ( struct V_86 * V_87 ,
struct V_84 * V_151 , T_1 V_6 )
{
V_151 -> V_6 = F_132 ( V_87 , V_6 ) ;
V_151 -> V_78 = 0 ;
F_96 ( & V_151 -> V_106 ) ;
F_94 ( V_87 , V_151 ) ;
V_87 -> V_103 ++ ;
V_87 -> V_104 -> V_105 ( V_87 ) ;
}
static void F_157 ( struct V_86 * V_87 ,
struct V_84 * V_167 )
{
F_92 ( V_87 , V_167 ) ;
F_53 ( V_167 -> V_79 ) ;
F_93 ( V_96 , V_167 ) ;
V_87 -> V_103 -- ;
V_87 -> V_104 -> V_105 ( V_87 ) ;
}
static T_6 int F_158 ( struct V_86 * V_87 ,
struct V_84 * V_167 ,
T_1 * V_6 , T_1 * V_78 )
{
T_1 V_176 ;
T_1 V_177 , V_178 ;
int V_16 ;
V_91:
V_176 = V_167 -> V_6 + ( T_1 ) ( V_147 * V_87 -> V_145 ) - 1 ;
V_177 = * V_6 ;
V_178 = V_87 -> V_145 ;
V_178 = F_116 ( V_178 , V_176 - V_177 + 1 ) ;
V_16 = F_150 ( V_87 , V_167 , & V_177 , & V_178 ) ;
if ( V_16 < 0 || V_177 != * V_6 )
return - V_179 ;
V_178 = F_116 ( V_178 , * V_78 ) ;
V_178 = F_116 ( V_178 , V_176 - V_177 + 1 ) ;
F_147 ( V_87 , V_167 , V_177 , V_178 ) ;
* V_6 += V_178 ;
* V_78 -= V_178 ;
if ( * V_78 ) {
struct V_89 * V_95 = F_90 ( & V_167 -> V_94 ) ;
if ( ! V_167 -> V_78 )
F_157 ( V_87 , V_167 ) ;
if ( ! V_95 )
return - V_179 ;
V_167 = F_91 ( V_95 , struct V_84 ,
V_94 ) ;
if ( ! V_167 -> V_79 )
return - V_180 ;
V_177 = * V_6 ;
V_178 = V_87 -> V_145 ;
V_16 = F_150 ( V_87 , V_167 , & V_177 ,
& V_178 ) ;
if ( V_16 < 0 || V_177 != * V_6 )
return - V_180 ;
goto V_91;
} else if ( ! V_167 -> V_78 )
F_157 ( V_87 , V_167 ) ;
return 0 ;
}
static T_1 F_159 ( struct V_86 * V_87 ,
struct V_84 * V_151 , T_1 V_6 ,
T_1 V_78 )
{
T_1 V_181 = 0 ;
T_1 V_176 ;
V_176 = V_151 -> V_6 + ( T_1 ) ( V_147 * V_87 -> V_145 ) ;
V_181 = F_116 ( V_176 - V_6 , V_78 ) ;
F_148 ( V_87 , V_151 , V_6 , V_181 ) ;
return V_181 ;
}
static bool F_160 ( struct V_86 * V_87 ,
struct V_84 * V_151 )
{
struct V_26 * V_27 = V_87 -> V_158 ;
if ( V_87 -> V_157 < V_87 -> V_165 ) {
if ( V_151 -> V_78 <= V_27 -> V_182 * 4 ) {
if ( V_87 -> V_157 * 2 <= V_87 -> V_165 )
return false ;
} else {
return false ;
}
}
if ( ( ( V_147 * V_87 -> V_145 ) >> 1 ) > V_27 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_161 ( struct V_86 * V_87 ,
struct V_84 * V_151 )
{
struct V_84 * V_167 ;
struct V_26 * V_27 = NULL ;
int V_183 = 0 ;
T_1 V_78 , V_6 , V_184 ;
int V_16 ;
V_78 = V_151 -> V_78 ;
V_6 = V_151 -> V_6 ;
if ( ! V_87 -> V_104 -> F_160 ( V_87 , V_151 ) )
return 0 ;
if ( V_87 -> V_104 == & V_185 )
V_27 = V_87 -> V_158 ;
V_91:
if ( V_27 && ! F_111 ( & V_27 -> V_133 ) ) {
struct V_122 * V_123 ;
struct V_89 * V_118 ;
struct V_84 * V_81 ;
V_123 = F_112 ( V_27 -> V_133 . V_95 ,
struct V_122 ,
V_134 ) ;
F_15 ( & V_123 -> V_31 ) ;
V_118 = F_89 ( & V_123 -> V_3 ) ;
if ( ! V_118 ) {
F_17 ( & V_123 -> V_31 ) ;
goto V_186;
}
V_81 = F_91 ( V_118 , struct V_84 , V_94 ) ;
if ( ! V_81 -> V_79 ) {
F_17 ( & V_123 -> V_31 ) ;
goto V_186;
}
if ( V_81 -> V_6 == F_132 ( V_87 , V_6 ) ) {
V_184 = F_159 ( V_87 , V_81 ,
V_6 , V_78 ) ;
V_78 -= V_184 ;
V_6 += V_184 ;
}
F_17 ( & V_123 -> V_31 ) ;
if ( ! V_78 ) {
V_16 = 1 ;
goto V_101;
}
}
V_186:
V_167 = F_138 ( V_87 , F_132 ( V_87 , V_6 ) ,
1 , 0 ) ;
if ( ! V_167 ) {
ASSERT ( V_183 == 0 ) ;
goto V_187;
}
V_184 = F_159 ( V_87 , V_167 , V_6 , V_78 ) ;
V_78 -= V_184 ;
V_6 += V_184 ;
V_183 = 0 ;
if ( ! V_78 ) {
V_16 = 1 ;
goto V_101;
} else
goto V_91;
V_187:
if ( V_151 && V_151 -> V_79 ) {
F_156 ( V_87 , V_151 , V_6 ) ;
V_183 = 1 ;
V_151 = NULL ;
goto V_91;
} else {
F_17 ( & V_87 -> V_92 ) ;
if ( ! V_151 ) {
V_151 = F_101 ( V_96 ,
V_54 ) ;
if ( ! V_151 ) {
F_15 ( & V_87 -> V_92 ) ;
V_16 = - V_55 ;
goto V_101;
}
}
V_151 -> V_79 = F_49 ( V_59 , V_54 ) ;
F_15 ( & V_87 -> V_92 ) ;
if ( ! V_151 -> V_79 ) {
V_16 = - V_55 ;
goto V_101;
}
goto V_91;
}
V_101:
if ( V_151 ) {
if ( V_151 -> V_79 )
F_53 ( V_151 -> V_79 ) ;
F_93 ( V_96 , V_151 ) ;
}
return V_16 ;
}
static bool F_162 ( struct V_86 * V_87 ,
struct V_84 * V_151 , bool V_188 )
{
struct V_84 * V_189 ;
struct V_84 * V_190 ;
bool V_191 = false ;
T_1 V_6 = V_151 -> V_6 ;
T_1 V_78 = V_151 -> V_78 ;
V_190 = F_138 ( V_87 , V_6 + V_78 , 0 , 0 ) ;
if ( V_190 && F_140 ( & V_190 -> V_94 ) )
V_189 = F_91 ( F_140 ( & V_190 -> V_94 ) ,
struct V_84 , V_94 ) ;
else
V_189 = F_138 ( V_87 , V_6 - 1 , 0 , 0 ) ;
if ( V_190 && ! V_190 -> V_79 ) {
if ( V_188 )
F_92 ( V_87 , V_190 ) ;
else
F_141 ( V_87 , V_190 ) ;
V_151 -> V_78 += V_190 -> V_78 ;
F_93 ( V_96 , V_190 ) ;
V_191 = true ;
}
if ( V_189 && ! V_189 -> V_79 &&
V_189 -> V_6 + V_189 -> V_78 == V_6 ) {
if ( V_188 )
F_92 ( V_87 , V_189 ) ;
else
F_141 ( V_87 , V_189 ) ;
V_151 -> V_6 = V_189 -> V_6 ;
V_151 -> V_78 += V_189 -> V_78 ;
F_93 ( V_96 , V_189 ) ;
V_191 = true ;
}
return V_191 ;
}
int F_163 ( struct V_86 * V_87 ,
T_1 V_6 , T_1 V_78 )
{
struct V_84 * V_151 ;
int V_16 = 0 ;
V_151 = F_101 ( V_96 , V_54 ) ;
if ( ! V_151 )
return - V_55 ;
V_151 -> V_6 = V_6 ;
V_151 -> V_78 = V_78 ;
F_15 ( & V_87 -> V_92 ) ;
if ( F_162 ( V_87 , V_151 , true ) )
goto V_192;
V_16 = F_161 ( V_87 , V_151 ) ;
if ( V_16 < 0 ) {
goto V_101;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_101;
}
V_192:
V_16 = F_94 ( V_87 , V_151 ) ;
if ( V_16 )
F_93 ( V_96 , V_151 ) ;
V_101:
F_17 ( & V_87 -> V_92 ) ;
if ( V_16 ) {
F_71 ( V_193 L_13 , V_16 ) ;
ASSERT ( V_16 != - V_154 ) ;
}
return V_16 ;
}
int F_164 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_78 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_151 ;
int V_16 ;
bool V_194 = false ;
F_15 ( & V_87 -> V_92 ) ;
V_91:
V_16 = 0 ;
if ( ! V_78 )
goto V_195;
V_151 = F_138 ( V_87 , V_6 , 0 , 0 ) ;
if ( ! V_151 ) {
V_151 = F_138 ( V_87 , F_132 ( V_87 , V_6 ) ,
1 , 0 ) ;
if ( ! V_151 ) {
F_139 ( V_194 ) ;
goto V_195;
}
}
V_194 = false ;
if ( ! V_151 -> V_79 ) {
F_92 ( V_87 , V_151 ) ;
if ( V_6 == V_151 -> V_6 ) {
T_1 V_196 = F_116 ( V_78 , V_151 -> V_78 ) ;
V_151 -> V_78 -= V_196 ;
V_151 -> V_6 += V_196 ;
if ( V_151 -> V_78 ) {
V_16 = F_94 ( V_87 , V_151 ) ;
F_139 ( V_16 ) ;
} else {
F_93 ( V_96 , V_151 ) ;
}
V_6 += V_196 ;
V_78 -= V_196 ;
goto V_91;
} else {
T_1 V_197 = V_151 -> V_78 + V_151 -> V_6 ;
V_151 -> V_78 = V_6 - V_151 -> V_6 ;
V_16 = F_94 ( V_87 , V_151 ) ;
F_139 ( V_16 ) ;
if ( V_16 )
goto V_195;
if ( V_197 < V_6 + V_78 ) {
V_78 -= V_197 - V_6 ;
V_6 = V_197 ;
goto V_91;
} else if ( V_197 == V_6 + V_78 ) {
goto V_195;
}
F_17 ( & V_87 -> V_92 ) ;
V_16 = F_165 ( V_27 , V_6 + V_78 ,
V_197 - ( V_6 + V_78 ) ) ;
F_139 ( V_16 ) ;
goto V_101;
}
}
V_16 = F_158 ( V_87 , V_151 , & V_6 , & V_78 ) ;
if ( V_16 == - V_180 ) {
V_194 = true ;
goto V_91;
}
V_195:
F_17 ( & V_87 -> V_92 ) ;
V_101:
return V_16 ;
}
void F_166 ( struct V_26 * V_27 ,
T_1 V_78 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_151 ;
struct V_89 * V_90 ;
int V_166 = 0 ;
for ( V_90 = F_89 ( & V_87 -> V_93 ) ; V_90 ; V_90 = F_90 ( V_90 ) ) {
V_151 = F_91 ( V_90 , struct V_84 , V_94 ) ;
if ( V_151 -> V_78 >= V_78 && ! V_27 -> V_198 )
V_166 ++ ;
F_71 ( V_193 L_14 ,
V_151 -> V_6 , V_151 -> V_78 ,
( V_151 -> V_79 ) ? L_15 : L_16 ) ;
}
F_71 ( V_199 L_17 ,
F_111 ( & V_27 -> V_133 ) ? L_16 : L_15 ) ;
F_71 ( V_199 L_18
L_19 , V_166 ) ;
}
void F_167 ( struct V_26 * V_27 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
F_168 ( & V_87 -> V_92 ) ;
V_87 -> V_145 = V_27 -> V_182 ;
V_87 -> V_127 = V_27 -> V_8 . V_17 ;
V_87 -> V_158 = V_27 ;
V_87 -> V_104 = & V_185 ;
V_87 -> V_165 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_84 ) ;
}
static int
F_169 (
struct V_26 * V_27 ,
struct V_122 * V_123 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_81 ;
struct V_89 * V_118 ;
F_15 ( & V_123 -> V_31 ) ;
if ( V_123 -> V_27 != V_27 )
goto V_101;
V_123 -> V_27 = NULL ;
V_123 -> V_200 = 0 ;
F_104 ( & V_123 -> V_134 ) ;
V_118 = F_89 ( & V_123 -> V_3 ) ;
while ( V_118 ) {
bool V_79 ;
V_81 = F_91 ( V_118 , struct V_84 , V_94 ) ;
V_118 = F_90 ( & V_81 -> V_94 ) ;
F_142 ( & V_81 -> V_94 , & V_123 -> V_3 ) ;
V_79 = ( V_81 -> V_79 != NULL ) ;
if ( ! V_79 )
F_162 ( V_87 , V_81 , false ) ;
F_134 ( & V_87 -> V_93 ,
V_81 -> V_6 , & V_81 -> V_94 , V_79 ) ;
}
V_123 -> V_3 = V_201 ;
V_101:
F_17 ( & V_123 -> V_31 ) ;
F_170 ( V_27 ) ;
return 0 ;
}
static void F_171 (
struct V_86 * V_87 )
{
struct V_84 * V_151 ;
struct V_89 * V_118 ;
while ( ( V_118 = F_172 ( & V_87 -> V_93 ) ) != NULL ) {
V_151 = F_91 ( V_118 , struct V_84 , V_94 ) ;
if ( ! V_151 -> V_79 ) {
F_92 ( V_87 , V_151 ) ;
F_93 ( V_96 , V_151 ) ;
} else {
F_157 ( V_87 , V_151 ) ;
}
if ( F_173 () ) {
F_17 ( & V_87 -> V_92 ) ;
F_174 () ;
F_15 ( & V_87 -> V_92 ) ;
}
}
}
void F_105 ( struct V_86 * V_87 )
{
F_15 ( & V_87 -> V_92 ) ;
F_171 ( V_87 ) ;
F_17 ( & V_87 -> V_92 ) ;
}
void F_175 ( struct V_26 * V_27 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_122 * V_123 ;
struct V_97 * V_202 ;
F_15 ( & V_87 -> V_92 ) ;
while ( ( V_202 = V_27 -> V_133 . V_95 ) !=
& V_27 -> V_133 ) {
V_123 = F_112 ( V_202 , struct V_122 ,
V_134 ) ;
F_139 ( V_123 -> V_27 != V_27 ) ;
F_169 ( V_27 , V_123 ) ;
if ( F_173 () ) {
F_17 ( & V_87 -> V_92 ) ;
F_174 () ;
F_15 ( & V_87 -> V_92 ) ;
}
}
F_171 ( V_87 ) ;
F_17 ( & V_87 -> V_92 ) ;
}
T_1 F_176 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_78 , T_1 V_203 ,
T_1 * V_174 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_81 = NULL ;
T_1 V_204 = V_78 + V_203 ;
T_1 V_16 = 0 ;
T_1 V_205 = 0 ;
T_1 V_206 = 0 ;
F_15 ( & V_87 -> V_92 ) ;
V_81 = F_154 ( V_87 , & V_6 , & V_204 ,
V_27 -> V_207 , V_174 ) ;
if ( ! V_81 )
goto V_101;
V_16 = V_6 ;
if ( V_81 -> V_79 ) {
F_147 ( V_87 , V_81 , V_6 , V_78 ) ;
if ( ! V_81 -> V_78 )
F_157 ( V_87 , V_81 ) ;
} else {
F_92 ( V_87 , V_81 ) ;
V_206 = V_6 - V_81 -> V_6 ;
V_205 = V_81 -> V_6 ;
V_81 -> V_6 = V_6 + V_78 ;
F_139 ( V_81 -> V_78 < V_78 + V_206 ) ;
V_81 -> V_78 -= V_78 + V_206 ;
if ( ! V_81 -> V_78 )
F_93 ( V_96 , V_81 ) ;
else
F_94 ( V_87 , V_81 ) ;
}
V_101:
F_17 ( & V_87 -> V_92 ) ;
if ( V_206 )
F_163 ( V_87 , V_205 , V_206 ) ;
return V_16 ;
}
int F_177 (
struct V_26 * V_27 ,
struct V_122 * V_123 )
{
struct V_86 * V_87 ;
int V_16 ;
F_15 ( & V_123 -> V_31 ) ;
if ( ! V_27 ) {
V_27 = V_123 -> V_27 ;
if ( ! V_27 ) {
F_17 ( & V_123 -> V_31 ) ;
return 0 ;
}
} else if ( V_123 -> V_27 != V_27 ) {
F_17 ( & V_123 -> V_31 ) ;
return 0 ;
}
F_178 ( & V_27 -> V_166 ) ;
F_17 ( & V_123 -> V_31 ) ;
V_87 = V_27 -> V_108 ;
F_15 ( & V_87 -> V_92 ) ;
V_16 = F_169 ( V_27 , V_123 ) ;
F_17 ( & V_87 -> V_92 ) ;
F_170 ( V_27 ) ;
return V_16 ;
}
static T_1 F_179 ( struct V_26 * V_27 ,
struct V_122 * V_123 ,
struct V_84 * V_81 ,
T_1 V_78 , T_1 V_208 ,
T_1 * V_174 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
int V_132 ;
T_1 V_177 = V_123 -> V_200 ;
T_1 V_178 = V_78 ;
T_1 V_16 = 0 ;
V_177 = V_208 ;
V_178 = V_78 ;
V_132 = F_150 ( V_87 , V_81 , & V_177 , & V_178 ) ;
if ( V_132 ) {
if ( V_178 > * V_174 )
* V_174 = V_178 ;
return 0 ;
}
V_16 = V_177 ;
F_145 ( V_87 , V_81 , V_16 , V_78 ) ;
return V_16 ;
}
T_1 F_180 ( struct V_26 * V_27 ,
struct V_122 * V_123 , T_1 V_78 ,
T_1 V_208 , T_1 * V_174 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_81 = NULL ;
struct V_89 * V_118 ;
T_1 V_16 = 0 ;
F_15 ( & V_123 -> V_31 ) ;
if ( V_78 > V_123 -> V_209 )
goto V_101;
if ( V_123 -> V_27 != V_27 )
goto V_101;
V_118 = F_89 ( & V_123 -> V_3 ) ;
if ( ! V_118 )
goto V_101;
V_81 = F_91 ( V_118 , struct V_84 , V_94 ) ;
while ( 1 ) {
if ( V_81 -> V_78 < V_78 && V_81 -> V_78 > * V_174 )
* V_174 = V_81 -> V_78 ;
if ( V_81 -> V_78 < V_78 ||
( ! V_81 -> V_79 && V_81 -> V_6 < V_208 ) ) {
V_118 = F_90 ( & V_81 -> V_94 ) ;
if ( ! V_118 )
break;
V_81 = F_91 ( V_118 , struct V_84 ,
V_94 ) ;
continue;
}
if ( V_81 -> V_79 ) {
V_16 = F_179 ( V_27 ,
V_123 , V_81 , V_78 ,
V_123 -> V_200 ,
V_174 ) ;
if ( V_16 == 0 ) {
V_118 = F_90 ( & V_81 -> V_94 ) ;
if ( ! V_118 )
break;
V_81 = F_91 ( V_118 , struct V_84 ,
V_94 ) ;
continue;
}
V_123 -> V_200 += V_78 ;
} else {
V_16 = V_81 -> V_6 ;
V_81 -> V_6 += V_78 ;
V_81 -> V_78 -= V_78 ;
}
if ( V_81 -> V_78 == 0 )
F_142 ( & V_81 -> V_94 , & V_123 -> V_3 ) ;
break;
}
V_101:
F_17 ( & V_123 -> V_31 ) ;
if ( ! V_16 )
return 0 ;
F_15 ( & V_87 -> V_92 ) ;
V_87 -> V_116 -= V_78 ;
if ( V_81 -> V_78 == 0 ) {
V_87 -> V_157 -- ;
if ( V_81 -> V_79 ) {
F_53 ( V_81 -> V_79 ) ;
V_87 -> V_103 -- ;
V_87 -> V_104 -> V_105 ( V_87 ) ;
}
F_93 ( V_96 , V_81 ) ;
}
F_17 ( & V_87 -> V_92 ) ;
return V_16 ;
}
static int F_181 ( struct V_26 * V_27 ,
struct V_84 * V_81 ,
struct V_122 * V_123 ,
T_1 V_6 , T_1 V_78 ,
T_1 V_210 , T_1 V_211 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
unsigned long V_171 ;
unsigned long V_68 ;
unsigned long V_212 ;
unsigned long V_213 ;
unsigned long V_168 ;
unsigned long V_127 = 0 ;
unsigned long V_214 = 0 ;
int V_16 ;
V_68 = F_129 ( V_81 -> V_6 , V_87 -> V_145 ,
F_151 ( T_1 , V_6 , V_81 -> V_6 ) ) ;
V_212 = F_131 ( V_78 , V_87 -> V_145 ) ;
V_213 = F_131 ( V_211 , V_87 -> V_145 ) ;
V_91:
V_168 = 0 ;
F_152 (i, entry->bitmap, BITS_PER_BITMAP) {
V_171 = F_153 ( V_81 -> V_79 ,
V_147 , V_68 ) ;
if ( V_171 - V_68 >= V_213 ) {
V_168 = V_171 - V_68 ;
break;
}
V_68 = V_171 ;
}
if ( ! V_168 )
return - V_49 ;
if ( ! V_214 ) {
V_127 = V_68 ;
V_123 -> V_209 = 0 ;
}
V_214 += V_168 ;
if ( V_123 -> V_209 < V_168 * V_87 -> V_145 )
V_123 -> V_209 = V_168 * V_87 -> V_145 ;
if ( V_214 < V_212 || V_123 -> V_209 < V_210 ) {
V_68 = V_171 + 1 ;
goto V_91;
}
V_123 -> V_200 = V_127 * V_87 -> V_145 + V_81 -> V_6 ;
F_142 ( & V_81 -> V_94 , & V_87 -> V_93 ) ;
V_16 = F_134 ( & V_123 -> V_3 , V_81 -> V_6 ,
& V_81 -> V_94 , 1 ) ;
ASSERT ( ! V_16 ) ;
F_182 ( V_27 , V_123 ,
V_214 * V_87 -> V_145 , 1 ) ;
return 0 ;
}
static T_6 int
F_183 ( struct V_26 * V_27 ,
struct V_122 * V_123 ,
struct V_97 * V_98 , T_1 V_6 , T_1 V_78 ,
T_1 V_210 , T_1 V_211 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_215 = NULL ;
struct V_84 * V_81 = NULL ;
struct V_84 * V_216 ;
struct V_89 * V_118 ;
T_1 V_200 ;
T_1 V_217 ;
T_1 V_218 ;
T_1 V_219 = 0 ;
V_81 = F_138 ( V_87 , V_6 , 0 , 1 ) ;
if ( ! V_81 )
return - V_49 ;
while ( V_81 -> V_79 || V_81 -> V_78 < V_211 ) {
if ( V_81 -> V_79 && F_111 ( & V_81 -> V_106 ) )
F_102 ( & V_81 -> V_106 , V_98 ) ;
V_118 = F_90 ( & V_81 -> V_94 ) ;
if ( ! V_118 )
return - V_49 ;
V_81 = F_91 ( V_118 , struct V_84 , V_94 ) ;
}
V_200 = V_81 -> V_6 ;
V_217 = V_81 -> V_78 ;
V_218 = V_81 -> V_78 ;
V_215 = V_81 ;
V_216 = V_81 ;
for ( V_118 = F_90 ( & V_81 -> V_94 ) ; V_118 ;
V_118 = F_90 ( & V_81 -> V_94 ) ) {
V_81 = F_91 ( V_118 , struct V_84 , V_94 ) ;
if ( V_81 -> V_79 ) {
if ( F_111 ( & V_81 -> V_106 ) )
F_102 ( & V_81 -> V_106 , V_98 ) ;
continue;
}
if ( V_81 -> V_78 < V_211 )
continue;
V_216 = V_81 ;
V_217 += V_81 -> V_78 ;
if ( V_81 -> V_78 > V_218 )
V_218 = V_81 -> V_78 ;
}
if ( V_217 < V_78 || V_218 < V_210 )
return - V_49 ;
V_123 -> V_200 = V_215 -> V_6 ;
V_118 = & V_215 -> V_94 ;
do {
int V_16 ;
V_81 = F_91 ( V_118 , struct V_84 , V_94 ) ;
V_118 = F_90 ( & V_81 -> V_94 ) ;
if ( V_81 -> V_79 || V_81 -> V_78 < V_211 )
continue;
F_142 ( & V_81 -> V_94 , & V_87 -> V_93 ) ;
V_16 = F_134 ( & V_123 -> V_3 , V_81 -> V_6 ,
& V_81 -> V_94 , 0 ) ;
V_219 += V_81 -> V_78 ;
ASSERT ( ! V_16 ) ;
} while ( V_118 && V_81 != V_216 );
V_123 -> V_209 = V_218 ;
F_182 ( V_27 , V_123 , V_219 , 0 ) ;
return 0 ;
}
static T_6 int
F_184 ( struct V_26 * V_27 ,
struct V_122 * V_123 ,
struct V_97 * V_98 , T_1 V_6 , T_1 V_78 ,
T_1 V_210 , T_1 V_211 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_81 ;
int V_16 = - V_49 ;
T_1 V_220 = F_132 ( V_87 , V_6 ) ;
if ( V_87 -> V_103 == 0 )
return - V_49 ;
V_81 = F_185 ( V_98 , struct V_84 , V_106 ) ;
if ( V_81 -> V_6 != V_220 ) {
V_81 = F_138 ( V_87 , V_220 , 1 , 0 ) ;
if ( V_81 && F_111 ( & V_81 -> V_106 ) )
F_186 ( & V_81 -> V_106 , V_98 ) ;
}
F_187 (entry, bitmaps, list) {
if ( V_81 -> V_78 < V_78 )
continue;
V_16 = F_181 ( V_27 , V_81 , V_123 , V_6 ,
V_78 , V_210 , V_211 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_49 ;
}
int F_188 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_122 * V_123 ,
T_1 V_6 , T_1 V_78 , T_1 V_203 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_81 , * V_76 ;
F_189 ( V_98 ) ;
T_1 V_211 ;
T_1 V_210 ;
int V_16 ;
if ( F_190 ( V_3 , V_221 ) ) {
V_210 = V_211 = V_78 + V_203 ;
} else if ( V_27 -> V_28 & V_222 ) {
V_210 = V_78 ;
V_211 = V_27 -> V_182 ;
} else {
V_210 = F_115 ( V_78 , ( V_78 + V_203 ) >> 2 ) ;
V_211 = V_27 -> V_182 ;
}
F_15 ( & V_87 -> V_92 ) ;
if ( V_87 -> V_116 < V_78 ) {
F_17 ( & V_87 -> V_92 ) ;
return - V_49 ;
}
F_15 ( & V_123 -> V_31 ) ;
if ( V_123 -> V_27 ) {
V_16 = 0 ;
goto V_101;
}
F_191 ( V_27 , V_6 , V_78 , V_203 ,
V_211 ) ;
F_96 ( & V_98 ) ;
V_16 = F_183 ( V_27 , V_123 , & V_98 , V_6 ,
V_78 + V_203 ,
V_210 , V_211 ) ;
if ( V_16 )
V_16 = F_184 ( V_27 , V_123 , & V_98 ,
V_6 , V_78 + V_203 ,
V_210 , V_211 ) ;
F_103 (entry, tmp, &bitmaps, list)
F_104 ( & V_81 -> V_106 ) ;
if ( ! V_16 ) {
F_178 ( & V_27 -> V_166 ) ;
F_102 ( & V_123 -> V_134 ,
& V_27 -> V_133 ) ;
V_123 -> V_27 = V_27 ;
} else {
F_192 ( V_27 ) ;
}
V_101:
F_17 ( & V_123 -> V_31 ) ;
F_17 ( & V_87 -> V_92 ) ;
return V_16 ;
}
void F_193 ( struct V_122 * V_123 )
{
F_168 ( & V_123 -> V_31 ) ;
F_168 ( & V_123 -> V_223 ) ;
V_123 -> V_3 = V_201 ;
V_123 -> V_209 = 0 ;
F_96 ( & V_123 -> V_134 ) ;
V_123 -> V_27 = NULL ;
}
static int F_194 ( struct V_26 * V_27 ,
T_1 * V_224 , T_1 V_127 , T_1 V_78 ,
T_1 V_225 , T_1 V_226 )
{
struct V_227 * V_228 = V_27 -> V_228 ;
struct V_107 * V_22 = V_27 -> V_22 ;
int V_16 ;
int V_229 = 0 ;
T_1 V_230 = 0 ;
F_15 ( & V_228 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( ! V_27 -> V_198 ) {
V_27 -> V_48 += V_226 ;
V_228 -> V_231 += V_226 ;
V_229 = 1 ;
}
F_17 ( & V_27 -> V_31 ) ;
F_17 ( & V_228 -> V_31 ) ;
V_16 = F_195 ( V_22 -> V_232 ,
V_127 , V_78 , & V_230 ) ;
if ( ! V_16 )
* V_224 += V_230 ;
F_165 ( V_27 , V_225 , V_226 ) ;
if ( V_229 ) {
F_15 ( & V_228 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_198 )
V_228 -> V_233 += V_226 ;
V_27 -> V_48 -= V_226 ;
V_228 -> V_231 -= V_226 ;
F_17 ( & V_228 -> V_31 ) ;
F_17 ( & V_27 -> V_31 ) ;
}
return V_16 ;
}
static int F_196 ( struct V_26 * V_27 ,
T_1 * V_224 , T_1 V_127 , T_1 V_176 , T_1 V_234 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_81 ;
struct V_89 * V_118 ;
int V_16 = 0 ;
T_1 V_128 ;
T_1 V_161 ;
T_1 V_78 ;
while ( V_127 < V_176 ) {
F_15 ( & V_87 -> V_92 ) ;
if ( V_87 -> V_116 < V_234 ) {
F_17 ( & V_87 -> V_92 ) ;
break;
}
V_81 = F_138 ( V_87 , V_127 , 0 , 1 ) ;
if ( ! V_81 ) {
F_17 ( & V_87 -> V_92 ) ;
break;
}
while ( V_81 -> V_79 ) {
V_118 = F_90 ( & V_81 -> V_94 ) ;
if ( ! V_118 ) {
F_17 ( & V_87 -> V_92 ) ;
goto V_101;
}
V_81 = F_91 ( V_118 , struct V_84 ,
V_94 ) ;
}
if ( V_81 -> V_6 >= V_176 ) {
F_17 ( & V_87 -> V_92 ) ;
break;
}
V_128 = V_81 -> V_6 ;
V_161 = V_81 -> V_78 ;
V_127 = F_115 ( V_127 , V_128 ) ;
V_78 = F_116 ( V_128 + V_161 , V_176 ) - V_127 ;
if ( V_78 < V_234 ) {
F_17 ( & V_87 -> V_92 ) ;
goto V_95;
}
F_92 ( V_87 , V_81 ) ;
F_93 ( V_96 , V_81 ) ;
F_17 ( & V_87 -> V_92 ) ;
V_16 = F_194 ( V_27 , V_224 , V_127 , V_78 ,
V_128 , V_161 ) ;
if ( V_16 )
break;
V_95:
V_127 += V_78 ;
if ( F_197 ( V_235 ) ) {
V_16 = - V_236 ;
break;
}
F_174 () ;
}
V_101:
return V_16 ;
}
static int F_198 ( struct V_26 * V_27 ,
T_1 * V_224 , T_1 V_127 , T_1 V_176 , T_1 V_234 )
{
struct V_86 * V_87 = V_27 -> V_108 ;
struct V_84 * V_81 ;
int V_16 = 0 ;
int V_237 ;
T_1 V_78 ;
T_1 V_6 = F_132 ( V_87 , V_127 ) ;
while ( V_6 < V_176 ) {
bool V_238 = false ;
F_15 ( & V_87 -> V_92 ) ;
if ( V_87 -> V_116 < V_234 ) {
F_17 ( & V_87 -> V_92 ) ;
break;
}
V_81 = F_138 ( V_87 , V_6 , 1 , 0 ) ;
if ( ! V_81 ) {
F_17 ( & V_87 -> V_92 ) ;
V_238 = true ;
goto V_95;
}
V_78 = V_234 ;
V_237 = F_150 ( V_87 , V_81 , & V_127 , & V_78 ) ;
if ( V_237 || V_127 >= V_176 ) {
F_17 ( & V_87 -> V_92 ) ;
V_238 = true ;
goto V_95;
}
V_78 = F_116 ( V_78 , V_176 - V_127 ) ;
if ( V_78 < V_234 ) {
F_17 ( & V_87 -> V_92 ) ;
goto V_95;
}
F_147 ( V_87 , V_81 , V_127 , V_78 ) ;
if ( V_81 -> V_78 == 0 )
F_157 ( V_87 , V_81 ) ;
F_17 ( & V_87 -> V_92 ) ;
V_16 = F_194 ( V_27 , V_224 , V_127 , V_78 ,
V_127 , V_78 ) ;
if ( V_16 )
break;
V_95:
if ( V_238 ) {
V_6 += V_147 * V_87 -> V_145 ;
} else {
V_127 += V_78 ;
if ( V_127 >= V_6 + V_147 * V_87 -> V_145 )
V_6 += V_147 * V_87 -> V_145 ;
}
if ( F_197 ( V_235 ) ) {
V_16 = - V_236 ;
break;
}
F_174 () ;
}
return V_16 ;
}
int F_199 ( struct V_26 * V_27 ,
T_1 * V_230 , T_1 V_127 , T_1 V_176 , T_1 V_234 )
{
int V_16 ;
* V_230 = 0 ;
V_16 = F_196 ( V_27 , V_230 , V_127 , V_176 , V_234 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_198 ( V_27 , V_230 , V_127 , V_176 , V_234 ) ;
return V_16 ;
}
T_1 F_200 ( struct V_2 * V_239 )
{
struct V_86 * V_87 = V_239 -> V_240 ;
struct V_84 * V_81 = NULL ;
T_1 V_37 = 0 ;
F_15 ( & V_87 -> V_92 ) ;
if ( F_201 ( & V_87 -> V_93 ) )
goto V_101;
V_81 = F_91 ( F_89 ( & V_87 -> V_93 ) ,
struct V_84 , V_94 ) ;
if ( ! V_81 -> V_79 ) {
V_37 = V_81 -> V_6 ;
F_92 ( V_87 , V_81 ) ;
V_81 -> V_6 ++ ;
V_81 -> V_78 -- ;
if ( ! V_81 -> V_78 )
F_93 ( V_96 , V_81 ) ;
else
F_94 ( V_87 , V_81 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_166 = 1 ;
int V_16 ;
V_16 = F_150 ( V_87 , V_81 , & V_6 , & V_166 ) ;
ASSERT ( ! V_16 ) ;
V_37 = V_6 ;
F_147 ( V_87 , V_81 , V_6 , 1 ) ;
if ( V_81 -> V_78 == 0 )
F_157 ( V_87 , V_81 ) ;
}
V_101:
F_17 ( & V_87 -> V_92 ) ;
return V_37 ;
}
struct V_1 * F_202 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_241 ) ;
if ( V_3 -> V_242 )
V_1 = F_16 ( V_3 -> V_242 ) ;
F_17 ( & V_3 -> V_241 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_241 ) ;
if ( ! F_203 ( V_3 -> V_22 ) )
V_3 -> V_242 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_241 ) ;
return V_1 ;
}
int F_204 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_36 , V_5 ,
V_42 , 0 ) ;
}
int F_205 ( struct V_107 * V_22 , struct V_2 * V_3 )
{
struct V_86 * V_87 = V_3 -> V_240 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_243 = F_206 ( & V_3 -> V_244 ) ;
if ( ! F_190 ( V_3 , V_245 ) )
return 0 ;
if ( F_203 ( V_22 ) )
return 0 ;
V_5 = F_108 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_202 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_101;
if ( V_243 != F_18 ( V_1 ) -> V_73 )
goto V_246;
V_16 = F_95 ( V_3 , V_1 , V_87 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_100 ( V_22 ,
L_20 ,
V_3 -> V_247 . V_17 ) ;
V_246:
F_11 ( V_1 ) ;
V_101:
F_109 ( V_5 ) ;
return V_16 ;
}
int F_207 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_86 * V_87 = V_3 -> V_240 ;
int V_16 ;
if ( ! F_190 ( V_3 , V_245 ) )
return 0 ;
V_16 = F_110 ( V_3 , V_1 , V_87 , NULL , V_36 , V_5 , 0 ) ;
if ( V_16 ) {
F_208 ( V_1 , V_1 -> V_139 ) ;
#ifdef F_128
F_100 ( V_3 -> V_22 ,
L_21 ,
V_3 -> V_247 . V_17 ) ;
#endif
}
return V_16 ;
}
int F_209 ( struct V_26 * V_248 ,
T_1 V_6 , T_1 V_78 , bool V_79 )
{
struct V_86 * V_87 = V_248 -> V_108 ;
struct V_84 * V_151 = NULL , * V_167 ;
void * V_249 = NULL ;
T_1 V_184 ;
int V_16 ;
V_91:
if ( ! V_151 ) {
V_151 = F_101 ( V_96 , V_54 ) ;
if ( ! V_151 )
return - V_55 ;
}
if ( ! V_79 ) {
F_15 ( & V_87 -> V_92 ) ;
V_151 -> V_6 = V_6 ;
V_151 -> V_78 = V_78 ;
V_16 = F_94 ( V_87 , V_151 ) ;
F_17 ( & V_87 -> V_92 ) ;
if ( V_16 )
F_93 ( V_96 , V_151 ) ;
return V_16 ;
}
if ( ! V_249 ) {
V_249 = F_49 ( V_59 , V_54 ) ;
if ( ! V_249 ) {
F_93 ( V_96 , V_151 ) ;
return - V_55 ;
}
}
F_15 ( & V_87 -> V_92 ) ;
V_167 = F_138 ( V_87 , F_132 ( V_87 , V_6 ) ,
1 , 0 ) ;
if ( ! V_167 ) {
V_151 -> V_79 = V_249 ;
V_249 = NULL ;
F_156 ( V_87 , V_151 , V_6 ) ;
V_167 = V_151 ;
}
V_184 = F_159 ( V_87 , V_167 , V_6 , V_78 ) ;
V_78 -= V_184 ;
V_6 += V_184 ;
F_17 ( & V_87 -> V_92 ) ;
if ( V_78 )
goto V_91;
if ( V_249 )
F_53 ( V_249 ) ;
return 0 ;
}
int F_210 ( struct V_26 * V_248 ,
T_1 V_6 , T_1 V_78 )
{
struct V_86 * V_87 = V_248 -> V_108 ;
struct V_84 * V_151 ;
int V_16 = 0 ;
F_15 ( & V_87 -> V_92 ) ;
V_151 = F_138 ( V_87 , V_6 , 0 , 0 ) ;
if ( ! V_151 ) {
V_151 = F_138 ( V_87 , F_132 ( V_87 , V_6 ) ,
1 , 0 ) ;
if ( ! V_151 )
goto V_101;
}
V_250:
if ( V_151 -> V_79 ) {
T_1 V_251 , V_252 ;
struct V_89 * V_90 ;
struct V_84 * V_76 ;
V_251 = V_6 ;
V_252 = V_87 -> V_145 ;
V_16 = F_150 ( V_87 , V_151 , & V_251 , & V_252 ) ;
if ( ! V_16 ) {
if ( V_251 == V_6 ) {
V_16 = 1 ;
goto V_101;
} else if ( V_251 > V_6 &&
V_6 + V_78 > V_251 ) {
V_16 = 1 ;
goto V_101;
}
}
V_90 = F_140 ( & V_151 -> V_94 ) ;
while ( V_90 ) {
V_76 = F_91 ( V_90 , struct V_84 ,
V_94 ) ;
if ( V_76 -> V_6 + V_76 -> V_78 < V_6 )
break;
if ( V_6 + V_78 < V_76 -> V_6 ) {
V_90 = F_140 ( & V_151 -> V_94 ) ;
continue;
}
V_151 = V_76 ;
goto V_250;
}
V_90 = F_90 ( & V_151 -> V_94 ) ;
while ( V_90 ) {
V_76 = F_91 ( V_90 , struct V_84 ,
V_94 ) ;
if ( V_6 + V_78 < V_76 -> V_6 )
break;
if ( V_76 -> V_6 + V_76 -> V_78 < V_6 ) {
V_90 = F_90 ( & V_151 -> V_94 ) ;
continue;
}
V_151 = V_76 ;
goto V_250;
}
goto V_101;
}
if ( V_151 -> V_6 == V_6 ) {
V_16 = 1 ;
goto V_101;
}
if ( V_6 > V_151 -> V_6 && V_6 < V_151 -> V_6 + V_151 -> V_78 )
V_16 = 1 ;
V_101:
F_17 ( & V_87 -> V_92 ) ;
return V_16 ;
}
