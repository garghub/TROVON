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
return 0 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
T_3 V_50 ;
int V_16 = 0 ;
V_50 = F_43 ( V_1 ) ;
F_44 ( V_1 , 0 ) ;
F_45 ( V_1 , V_50 , 0 ) ;
V_16 = F_46 ( V_36 , V_3 , V_1 ,
0 , V_51 ) ;
if ( V_16 ) {
F_47 ( V_36 , V_3 , V_16 ) ;
return V_16 ;
}
V_16 = F_48 ( V_36 , V_3 , V_1 ) ;
if ( V_16 )
F_47 ( V_36 , V_3 , V_16 ) ;
return V_16 ;
}
static int F_49 ( struct V_1 * V_1 )
{
struct V_52 * V_53 ;
unsigned long V_54 ;
V_53 = F_50 ( sizeof( * V_53 ) , V_55 ) ;
if ( ! V_53 )
return - V_56 ;
F_51 ( V_53 , V_1 -> V_24 ) ;
V_54 = ( F_43 ( V_1 ) - 1 ) >> V_57 ;
F_52 ( V_1 -> V_24 , V_53 , NULL , 0 , V_54 ) ;
F_53 ( V_53 ) ;
return 0 ;
}
static int F_54 ( struct V_58 * V_58 , struct V_1 * V_1 ,
struct V_2 * V_3 )
{
memset ( V_58 , 0 , sizeof( struct V_58 ) ) ;
V_58 -> V_59 = ( F_43 ( V_1 ) + V_60 - 1 ) >>
V_57 ;
V_58 -> V_61 = F_50 ( sizeof( struct V_62 * ) * V_58 -> V_59 ,
V_55 ) ;
if ( ! V_58 -> V_61 )
return - V_56 ;
V_58 -> V_3 = V_3 ;
if ( F_55 ( V_1 ) != V_42 )
V_58 -> V_63 = 1 ;
return 0 ;
}
static void F_56 ( struct V_58 * V_58 )
{
F_53 ( V_58 -> V_61 ) ;
}
static void F_57 ( struct V_58 * V_58 )
{
if ( V_58 -> V_64 ) {
F_58 ( V_58 -> V_62 ) ;
V_58 -> V_64 = NULL ;
V_58 -> V_65 = NULL ;
}
}
static void F_59 ( struct V_58 * V_58 , int V_66 )
{
F_60 ( V_58 -> V_67 >= V_58 -> V_59 ) ;
V_58 -> V_62 = V_58 -> V_61 [ V_58 -> V_67 ++ ] ;
V_58 -> V_64 = F_61 ( V_58 -> V_62 ) ;
V_58 -> V_65 = V_58 -> V_64 ;
V_58 -> V_68 = V_60 ;
if ( V_66 )
memset ( V_58 -> V_64 , 0 , V_60 ) ;
}
static void F_62 ( struct V_58 * V_58 )
{
int V_69 ;
F_57 ( V_58 ) ;
for ( V_69 = 0 ; V_69 < V_58 -> V_59 ; V_69 ++ ) {
if ( V_58 -> V_61 [ V_69 ] ) {
F_63 ( V_58 -> V_61 [ V_69 ] ) ;
F_64 ( V_58 -> V_61 [ V_69 ] ) ;
F_65 ( V_58 -> V_61 [ V_69 ] ) ;
}
}
}
static int F_66 ( struct V_58 * V_58 , struct V_1 * V_1 ,
int V_70 )
{
struct V_62 * V_62 ;
T_4 V_71 = F_67 ( V_1 -> V_24 ) ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_58 -> V_59 ; V_69 ++ ) {
V_62 = F_68 ( V_1 -> V_24 , V_69 , V_71 ) ;
if ( ! V_62 ) {
F_62 ( V_58 ) ;
return - V_56 ;
}
V_58 -> V_61 [ V_69 ] = V_62 ;
if ( V_70 && ! F_69 ( V_62 ) ) {
F_70 ( NULL , V_62 ) ;
F_71 ( V_62 ) ;
if ( ! F_69 ( V_62 ) ) {
F_72 ( V_72 L_2
L_3 ) ;
F_62 ( V_58 ) ;
return - V_73 ;
}
}
}
for ( V_69 = 0 ; V_69 < V_58 -> V_59 ; V_69 ++ ) {
F_73 ( V_58 -> V_61 [ V_69 ] ) ;
F_74 ( V_58 -> V_61 [ V_69 ] ) ;
}
return 0 ;
}
static void F_75 ( struct V_58 * V_58 , T_1 V_74 )
{
T_5 * V_75 ;
F_59 ( V_58 , 1 ) ;
if ( V_58 -> V_63 ) {
V_58 -> V_64 += ( sizeof( T_2 ) * V_58 -> V_59 ) ;
V_58 -> V_68 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_58 -> V_59 ) ;
} else {
V_58 -> V_64 += sizeof( T_1 ) ;
V_58 -> V_68 -= sizeof( T_1 ) * 2 ;
}
V_75 = V_58 -> V_64 ;
* V_75 = F_76 ( V_74 ) ;
V_58 -> V_64 += sizeof( T_1 ) ;
}
static int F_77 ( struct V_58 * V_58 , T_1 V_74 )
{
T_5 * V_76 ;
if ( V_58 -> V_63 ) {
V_58 -> V_64 += sizeof( T_2 ) * V_58 -> V_59 ;
V_58 -> V_68 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_58 -> V_59 ) ;
} else {
V_58 -> V_64 += sizeof( T_1 ) ;
V_58 -> V_68 -= sizeof( T_1 ) * 2 ;
}
V_76 = V_58 -> V_64 ;
if ( F_78 ( * V_76 ) != V_74 ) {
F_79 ( V_72 L_4
L_5 , * V_76 ,
V_74 ) ;
F_57 ( V_58 ) ;
return - V_73 ;
}
V_58 -> V_64 += sizeof( T_1 ) ;
return 0 ;
}
static void F_80 ( struct V_58 * V_58 , int V_67 )
{
T_2 * V_77 ;
T_2 V_78 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_58 -> V_63 ) {
F_57 ( V_58 ) ;
return;
}
if ( V_67 == 0 )
V_6 = sizeof( T_2 ) * V_58 -> V_59 ;
V_78 = F_81 ( V_58 -> V_65 + V_6 , V_78 ,
V_60 - V_6 ) ;
F_82 ( V_78 , ( char * ) & V_78 ) ;
F_57 ( V_58 ) ;
V_77 = F_61 ( V_58 -> V_61 [ 0 ] ) ;
V_77 += V_67 ;
* V_77 = V_78 ;
F_58 ( V_58 -> V_61 [ 0 ] ) ;
}
static int F_83 ( struct V_58 * V_58 , int V_67 )
{
T_2 * V_77 , V_75 ;
T_2 V_78 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_58 -> V_63 ) {
F_59 ( V_58 , 0 ) ;
return 0 ;
}
if ( V_67 == 0 )
V_6 = sizeof( T_2 ) * V_58 -> V_59 ;
V_77 = F_61 ( V_58 -> V_61 [ 0 ] ) ;
V_77 += V_67 ;
V_75 = * V_77 ;
F_58 ( V_58 -> V_61 [ 0 ] ) ;
F_59 ( V_58 , 0 ) ;
V_78 = F_81 ( V_58 -> V_65 + V_6 , V_78 ,
V_60 - V_6 ) ;
F_82 ( V_78 , ( char * ) & V_78 ) ;
if ( V_75 != V_78 ) {
F_79 ( V_72 L_6
L_3 ) ;
F_57 ( V_58 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_84 ( struct V_58 * V_58 , T_1 V_6 , T_1 V_79 ,
void * V_80 )
{
struct V_81 * V_82 ;
if ( ! V_58 -> V_64 )
return - V_49 ;
V_82 = V_58 -> V_64 ;
V_82 -> V_6 = F_76 ( V_6 ) ;
V_82 -> V_79 = F_76 ( V_79 ) ;
V_82 -> type = ( V_80 ) ? V_83 :
V_84 ;
V_58 -> V_64 += sizeof( struct V_81 ) ;
V_58 -> V_68 -= sizeof( struct V_81 ) ;
if ( V_58 -> V_68 >= sizeof( struct V_81 ) )
return 0 ;
F_80 ( V_58 , V_58 -> V_67 - 1 ) ;
if ( V_58 -> V_67 >= V_58 -> V_59 )
return 0 ;
F_59 ( V_58 , 1 ) ;
return 0 ;
}
static int F_85 ( struct V_58 * V_58 , void * V_80 )
{
if ( ! V_58 -> V_64 )
return - V_49 ;
if ( V_58 -> V_64 != V_58 -> V_65 ) {
F_80 ( V_58 , V_58 -> V_67 - 1 ) ;
if ( V_58 -> V_67 >= V_58 -> V_59 )
return - V_49 ;
F_59 ( V_58 , 0 ) ;
}
memcpy ( V_58 -> V_64 , V_80 , V_60 ) ;
F_80 ( V_58 , V_58 -> V_67 - 1 ) ;
if ( V_58 -> V_67 < V_58 -> V_59 )
F_59 ( V_58 , 0 ) ;
return 0 ;
}
static void F_86 ( struct V_58 * V_58 )
{
if ( V_58 -> V_64 != V_58 -> V_65 )
F_80 ( V_58 , V_58 -> V_67 - 1 ) ;
else
F_57 ( V_58 ) ;
while ( V_58 -> V_67 < V_58 -> V_59 ) {
F_59 ( V_58 , 1 ) ;
F_80 ( V_58 , V_58 -> V_67 - 1 ) ;
}
}
static int F_87 ( struct V_58 * V_58 ,
struct V_85 * V_82 , T_6 * type )
{
struct V_81 * V_86 ;
int V_16 ;
if ( ! V_58 -> V_64 ) {
V_16 = F_83 ( V_58 , V_58 -> V_67 ) ;
if ( V_16 )
return V_16 ;
}
V_86 = V_58 -> V_64 ;
V_82 -> V_6 = F_78 ( V_86 -> V_6 ) ;
V_82 -> V_79 = F_78 ( V_86 -> V_79 ) ;
* type = V_86 -> type ;
V_58 -> V_64 += sizeof( struct V_81 ) ;
V_58 -> V_68 -= sizeof( struct V_81 ) ;
if ( V_58 -> V_68 >= sizeof( struct V_81 ) )
return 0 ;
F_57 ( V_58 ) ;
return 0 ;
}
static int F_88 ( struct V_58 * V_58 ,
struct V_85 * V_82 )
{
int V_16 ;
V_16 = F_83 ( V_58 , V_58 -> V_67 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_82 -> V_80 , V_58 -> V_64 , V_60 ) ;
F_57 ( V_58 ) ;
return 0 ;
}
static void F_89 ( struct V_87 * V_88 )
{
struct V_85 * V_86 , * V_89 = NULL ;
struct V_90 * V_91 ;
V_92:
F_15 ( & V_88 -> V_93 ) ;
for ( V_91 = F_90 ( & V_88 -> V_94 ) ; V_91 ; V_91 = F_91 ( V_91 ) ) {
V_86 = F_92 ( V_91 , struct V_85 , V_95 ) ;
if ( ! V_89 )
goto V_96;
if ( V_86 -> V_80 || V_89 -> V_80 )
goto V_96;
if ( V_89 -> V_6 + V_89 -> V_79 == V_86 -> V_6 ) {
F_93 ( V_88 , V_89 ) ;
F_93 ( V_88 , V_86 ) ;
V_89 -> V_79 += V_86 -> V_79 ;
F_94 ( V_97 , V_86 ) ;
F_95 ( V_88 , V_89 ) ;
V_89 = NULL ;
F_17 ( & V_88 -> V_93 ) ;
goto V_92;
}
V_96:
V_89 = V_86 ;
}
F_17 ( & V_88 -> V_93 ) ;
}
static int F_96 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_87 * V_88 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_58 V_58 ;
struct V_7 V_8 ;
struct V_85 * V_86 , * V_91 ;
struct V_98 V_99 ;
T_1 V_100 ;
T_1 V_101 ;
T_1 V_74 ;
T_6 type ;
int V_16 = 0 ;
F_97 ( & V_99 ) ;
if ( ! F_43 ( V_1 ) )
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
V_100 = F_98 ( V_15 , V_13 ) ;
V_101 = F_99 ( V_15 , V_13 ) ;
V_74 = F_100 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( F_18 ( V_1 ) -> V_74 != V_74 ) {
F_101 ( V_3 -> V_22 ,
L_7
L_8 ,
( unsigned long long ) F_18 ( V_1 ) -> V_74 ,
( unsigned long long ) V_74 ) ;
return 0 ;
}
if ( ! V_100 )
return 0 ;
V_16 = F_54 ( & V_58 , V_1 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_49 ( V_1 ) ;
if ( V_16 )
goto V_102;
V_16 = F_66 ( & V_58 , V_1 , 1 ) ;
if ( V_16 )
goto V_102;
V_16 = F_83 ( & V_58 , 0 ) ;
if ( V_16 )
goto V_103;
V_16 = F_77 ( & V_58 , V_74 ) ;
if ( V_16 )
goto V_103;
while ( V_100 ) {
V_86 = F_102 ( V_97 ,
V_55 ) ;
if ( ! V_86 )
goto V_103;
V_16 = F_87 ( & V_58 , V_86 , & type ) ;
if ( V_16 ) {
F_94 ( V_97 , V_86 ) ;
goto V_103;
}
if ( ! V_86 -> V_79 ) {
F_94 ( V_97 , V_86 ) ;
goto V_103;
}
if ( type == V_84 ) {
F_15 ( & V_88 -> V_93 ) ;
V_16 = F_95 ( V_88 , V_86 ) ;
F_17 ( & V_88 -> V_93 ) ;
if ( V_16 ) {
F_101 ( V_3 -> V_22 ,
L_9 ) ;
F_94 ( V_97 , V_86 ) ;
goto V_103;
}
} else {
F_60 ( ! V_101 ) ;
V_101 -- ;
V_86 -> V_80 = F_50 ( V_60 , V_55 ) ;
if ( ! V_86 -> V_80 ) {
F_94 (
V_97 , V_86 ) ;
goto V_103;
}
F_15 ( & V_88 -> V_93 ) ;
V_16 = F_95 ( V_88 , V_86 ) ;
V_88 -> V_104 ++ ;
V_88 -> V_105 -> V_106 ( V_88 ) ;
F_17 ( & V_88 -> V_93 ) ;
if ( V_16 ) {
F_101 ( V_3 -> V_22 ,
L_9 ) ;
F_94 ( V_97 , V_86 ) ;
goto V_103;
}
F_103 ( & V_86 -> V_107 , & V_99 ) ;
}
V_100 -- ;
}
F_57 ( & V_58 ) ;
F_104 (e, n, &bitmaps, list) {
F_105 ( & V_86 -> V_107 ) ;
V_16 = F_88 ( & V_58 , V_86 ) ;
if ( V_16 )
goto V_103;
}
F_62 ( & V_58 ) ;
F_89 ( V_88 ) ;
V_16 = 1 ;
V_102:
F_56 ( & V_58 ) ;
return V_16 ;
V_103:
F_62 ( & V_58 ) ;
F_106 ( V_88 ) ;
goto V_102;
}
int F_107 ( struct V_108 * V_22 ,
struct V_26 * V_27 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_2 * V_3 = V_22 -> V_110 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 = 0 ;
bool V_111 ;
T_1 V_112 = F_108 ( & V_27 -> V_113 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 != V_114 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_5 = F_109 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_115 = 1 ;
V_5 -> V_116 = 1 ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_110 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 != V_114 ) {
F_17 ( & V_27 -> V_31 ) ;
F_110 ( V_5 ) ;
goto V_102;
}
F_17 ( & V_27 -> V_31 ) ;
V_16 = F_96 ( V_22 -> V_110 , V_1 , V_88 ,
V_5 , V_27 -> V_8 . V_17 ) ;
F_110 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_102;
F_15 ( & V_88 -> V_93 ) ;
V_111 = ( V_88 -> V_117 == ( V_27 -> V_8 . V_6 - V_112 -
V_27 -> V_118 ) ) ;
F_17 ( & V_88 -> V_93 ) ;
if ( ! V_111 ) {
F_106 ( V_88 ) ;
F_101 ( V_22 , L_10 ,
V_27 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_102:
if ( V_16 < 0 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_32 = V_33 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
F_101 ( V_22 , L_11 ,
V_27 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
static int F_111 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_87 * V_88 ,
struct V_26 * V_27 ,
struct V_35 * V_36 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_90 * V_119 ;
struct V_98 * V_120 , * V_91 ;
struct V_121 * V_122 = NULL ;
struct V_123 * V_124 = NULL ;
struct V_125 * V_126 = NULL ;
struct V_58 V_58 ;
struct V_98 V_127 ;
struct V_7 V_8 ;
T_1 V_128 , V_129 , V_130 , V_131 ;
int V_132 = 0 ;
int V_99 = 0 ;
int V_16 ;
int V_133 = - 1 ;
F_97 ( & V_127 ) ;
if ( ! F_43 ( V_1 ) )
return - 1 ;
V_16 = F_54 ( & V_58 , V_1 , V_3 ) ;
if ( V_16 )
return - 1 ;
if ( V_27 && ! F_112 ( & V_27 -> V_134 ) )
V_124 = F_113 ( V_27 -> V_134 . V_96 ,
struct V_123 ,
V_135 ) ;
F_66 ( & V_58 , V_1 , 0 ) ;
F_114 ( & F_18 ( V_1 ) -> V_136 , 0 , F_43 ( V_1 ) - 1 ,
0 , & V_122 ) ;
V_119 = F_90 ( & V_88 -> V_94 ) ;
if ( ! V_119 && V_124 ) {
V_119 = F_90 ( & V_124 -> V_3 ) ;
V_124 = NULL ;
}
if ( V_58 . V_63 &&
( V_58 . V_59 * sizeof( T_2 ) ) >= V_60 )
goto V_137;
F_75 ( & V_58 , V_36 -> V_43 ) ;
while ( V_119 ) {
struct V_85 * V_86 ;
V_86 = F_92 ( V_119 , struct V_85 , V_95 ) ;
V_132 ++ ;
V_16 = F_84 ( & V_58 , V_86 -> V_6 , V_86 -> V_79 ,
V_86 -> V_80 ) ;
if ( V_16 )
goto V_137;
if ( V_86 -> V_80 ) {
F_103 ( & V_86 -> V_107 , & V_127 ) ;
V_99 ++ ;
}
V_119 = F_91 ( V_119 ) ;
if ( ! V_119 && V_124 ) {
V_119 = F_90 ( & V_124 -> V_3 ) ;
V_124 = NULL ;
}
}
V_126 = V_3 -> V_22 -> V_138 ;
if ( V_27 )
V_128 = V_27 -> V_8 . V_17 ;
while ( V_27 && ( V_128 < V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 ) ) {
V_16 = F_115 ( V_126 , V_128 ,
& V_129 , & V_130 ,
V_139 , NULL ) ;
if ( V_16 ) {
V_16 = 0 ;
break;
}
if ( V_129 >= V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 )
break;
V_129 = F_116 ( V_129 , V_128 ) ;
V_130 = F_117 ( V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 , V_130 + 1 ) ;
V_131 = V_130 - V_129 ;
V_132 ++ ;
V_16 = F_84 ( & V_58 , V_129 , V_131 , NULL ) ;
if ( V_16 )
goto V_137;
V_128 = V_130 ;
}
F_118 (pos, n, &bitmap_list) {
struct V_85 * V_82 =
F_113 ( V_120 , struct V_85 , V_107 ) ;
V_16 = F_85 ( & V_58 , V_82 -> V_80 ) ;
if ( V_16 )
goto V_137;
F_105 ( & V_82 -> V_107 ) ;
}
F_86 ( & V_58 ) ;
V_16 = F_119 ( V_3 , V_1 , V_58 . V_61 , V_58 . V_59 ,
0 , F_43 ( V_1 ) , & V_122 ) ;
F_62 ( & V_58 ) ;
F_120 ( & F_18 ( V_1 ) -> V_136 , 0 ,
F_43 ( V_1 ) - 1 , & V_122 , V_55 ) ;
if ( V_16 )
goto V_102;
F_121 ( V_1 , 0 , ( T_1 ) - 1 ) ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_36 , V_3 , & V_8 , V_5 , 0 , 1 ) ;
if ( V_16 < 0 ) {
F_122 ( & F_18 ( V_1 ) -> V_136 , 0 , V_1 -> V_140 - 1 ,
V_139 | V_141 , 0 , 0 , NULL ,
V_55 ) ;
goto V_102;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_142 ;
F_60 ( ! V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_123 ( V_15 , & V_142 , V_5 -> V_21 [ 0 ] ) ;
if ( V_142 . V_17 != V_18 ||
V_142 . V_6 != V_6 ) {
F_122 ( & F_18 ( V_1 ) -> V_136 , 0 ,
V_1 -> V_140 - 1 ,
V_139 | V_141 , 0 , 0 ,
NULL , V_55 ) ;
F_4 ( V_5 ) ;
goto V_102;
}
}
F_18 ( V_1 ) -> V_74 = V_36 -> V_43 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_124 ( V_15 , V_13 , V_132 ) ;
F_125 ( V_15 , V_13 , V_99 ) ;
F_126 ( V_15 , V_13 , V_36 -> V_43 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
V_133 = 0 ;
V_102:
F_56 ( & V_58 ) ;
if ( V_133 ) {
F_127 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_74 = 0 ;
}
F_48 ( V_36 , V_3 , V_1 ) ;
return V_133 ;
V_137:
F_118 (pos, n, &bitmap_list) {
struct V_85 * V_82 =
F_113 ( V_120 , struct V_85 , V_107 ) ;
F_105 ( & V_82 -> V_107 ) ;
}
F_62 ( & V_58 ) ;
F_120 ( & F_18 ( V_1 ) -> V_136 , 0 ,
F_43 ( V_1 ) - 1 , & V_122 , V_55 ) ;
goto V_102;
}
int F_128 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_26 * V_27 ,
struct V_4 * V_5 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_110 ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 < V_143 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_111 ( V_3 , V_1 , V_88 , V_27 , V_36 ,
V_5 , V_27 -> V_8 . V_17 ) ;
if ( V_16 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_32 = V_144 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
#ifdef F_129
F_101 ( V_3 -> V_22 ,
L_12 ,
V_27 -> V_8 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_130 ( T_1 V_145 , T_2 V_146 ,
T_1 V_6 )
{
F_60 ( V_6 < V_145 ) ;
V_6 -= V_145 ;
return ( unsigned long ) ( F_131 ( V_6 , V_146 ) ) ;
}
static inline unsigned long F_132 ( T_1 V_79 , T_2 V_146 )
{
return ( unsigned long ) ( F_131 ( V_79 , V_146 ) ) ;
}
static inline T_1 F_133 ( struct V_87 * V_88 ,
T_1 V_6 )
{
T_1 V_145 ;
T_1 V_147 ;
V_147 = V_148 * V_88 -> V_146 ;
V_145 = V_6 - V_88 -> V_128 ;
V_145 = F_134 ( V_145 , V_147 ) ;
V_145 *= V_147 ;
V_145 += V_88 -> V_128 ;
return V_145 ;
}
static int F_135 ( struct V_149 * V_3 , T_1 V_6 ,
struct V_90 * V_119 , int V_80 )
{
struct V_90 * * V_150 = & V_3 -> V_90 ;
struct V_90 * V_151 = NULL ;
struct V_85 * V_152 ;
while ( * V_150 ) {
V_151 = * V_150 ;
V_152 = F_92 ( V_151 , struct V_85 , V_95 ) ;
if ( V_6 < V_152 -> V_6 ) {
V_150 = & ( * V_150 ) -> V_153 ;
} else if ( V_6 > V_152 -> V_6 ) {
V_150 = & ( * V_150 ) -> V_154 ;
} else {
if ( V_80 ) {
if ( V_152 -> V_80 ) {
F_136 ( 1 ) ;
return - V_155 ;
}
V_150 = & ( * V_150 ) -> V_154 ;
} else {
if ( ! V_152 -> V_80 ) {
F_136 ( 1 ) ;
return - V_155 ;
}
V_150 = & ( * V_150 ) -> V_153 ;
}
}
}
F_137 ( V_119 , V_151 , V_150 ) ;
F_138 ( V_119 , V_3 ) ;
return 0 ;
}
static struct V_85 *
F_139 ( struct V_87 * V_88 ,
T_1 V_6 , int V_156 , int V_157 )
{
struct V_90 * V_91 = V_88 -> V_94 . V_90 ;
struct V_85 * V_82 , * V_89 = NULL ;
while ( 1 ) {
if ( ! V_91 ) {
V_82 = NULL ;
break;
}
V_82 = F_92 ( V_91 , struct V_85 , V_95 ) ;
V_89 = V_82 ;
if ( V_6 < V_82 -> V_6 )
V_91 = V_91 -> V_153 ;
else if ( V_6 > V_82 -> V_6 )
V_91 = V_91 -> V_154 ;
else
break;
}
if ( V_156 ) {
if ( ! V_82 )
return NULL ;
if ( V_82 -> V_80 )
return V_82 ;
V_91 = F_91 ( V_91 ) ;
if ( ! V_91 )
return NULL ;
V_82 = F_92 ( V_91 , struct V_85 , V_95 ) ;
if ( V_82 -> V_6 != V_6 )
return NULL ;
F_140 ( ! V_82 -> V_80 ) ;
return V_82 ;
} else if ( V_82 ) {
if ( V_82 -> V_80 ) {
V_91 = F_141 ( & V_82 -> V_95 ) ;
if ( V_91 ) {
V_89 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
if ( ! V_89 -> V_80 &&
V_89 -> V_6 + V_89 -> V_79 > V_6 )
V_82 = V_89 ;
}
}
return V_82 ;
}
if ( ! V_89 )
return NULL ;
V_82 = V_89 ;
if ( V_82 -> V_6 > V_6 ) {
V_91 = F_141 ( & V_82 -> V_95 ) ;
if ( V_91 ) {
V_82 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
F_60 ( V_82 -> V_6 > V_6 ) ;
} else {
if ( V_157 )
return V_82 ;
else
return NULL ;
}
}
if ( V_82 -> V_80 ) {
V_91 = F_141 ( & V_82 -> V_95 ) ;
if ( V_91 ) {
V_89 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
if ( ! V_89 -> V_80 &&
V_89 -> V_6 + V_89 -> V_79 > V_6 )
return V_89 ;
}
if ( V_82 -> V_6 + V_148 * V_88 -> V_146 > V_6 )
return V_82 ;
} else if ( V_82 -> V_6 + V_82 -> V_79 > V_6 )
return V_82 ;
if ( ! V_157 )
return NULL ;
while ( 1 ) {
if ( V_82 -> V_80 ) {
if ( V_82 -> V_6 + V_148 *
V_88 -> V_146 > V_6 )
break;
} else {
if ( V_82 -> V_6 + V_82 -> V_79 > V_6 )
break;
}
V_91 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_91 )
return NULL ;
V_82 = F_92 ( V_91 , struct V_85 , V_95 ) ;
}
return V_82 ;
}
static inline void
F_142 ( struct V_87 * V_88 ,
struct V_85 * V_152 )
{
F_143 ( & V_152 -> V_95 , & V_88 -> V_94 ) ;
V_88 -> V_158 -- ;
}
static void F_93 ( struct V_87 * V_88 ,
struct V_85 * V_152 )
{
F_142 ( V_88 , V_152 ) ;
V_88 -> V_117 -= V_152 -> V_79 ;
}
static int F_95 ( struct V_87 * V_88 ,
struct V_85 * V_152 )
{
int V_16 = 0 ;
F_60 ( ! V_152 -> V_80 && ! V_152 -> V_79 ) ;
V_16 = F_135 ( & V_88 -> V_94 , V_152 -> V_6 ,
& V_152 -> V_95 , ( V_152 -> V_80 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_88 -> V_117 += V_152 -> V_79 ;
V_88 -> V_158 ++ ;
return V_16 ;
}
static void F_144 ( struct V_87 * V_88 )
{
struct V_26 * V_27 = V_88 -> V_159 ;
T_1 V_160 ;
T_1 V_161 ;
T_1 V_162 ;
T_1 V_68 = V_27 -> V_8 . V_6 ;
T_1 V_163 = V_148 * V_88 -> V_146 ;
int V_164 = F_134 ( V_68 + V_163 - 1 , V_163 ) ;
V_164 = F_116 ( V_164 , 1 ) ;
F_60 ( V_88 -> V_104 > V_164 ) ;
if ( V_68 < 1024 * 1024 * 1024 )
V_160 = V_165 ;
else
V_160 = V_165 *
F_134 ( V_68 , 1024 * 1024 * 1024 ) ;
V_161 = ( V_88 -> V_104 + 1 ) * V_60 ;
if ( V_161 >= V_160 ) {
V_88 -> V_166 = 0 ;
return;
}
V_162 = V_160 - V_161 ;
V_162 = F_145 ( T_1 , V_162 , F_134 ( V_160 , 2 ) ) ;
V_88 -> V_166 =
F_134 ( V_162 , ( sizeof( struct V_85 ) ) ) ;
}
static inline void F_146 ( struct V_87 * V_88 ,
struct V_85 * V_152 ,
T_1 V_6 , T_1 V_79 )
{
unsigned long V_128 , V_167 ;
V_128 = F_130 ( V_152 -> V_6 , V_88 -> V_146 , V_6 ) ;
V_167 = F_132 ( V_79 , V_88 -> V_146 ) ;
F_60 ( V_128 + V_167 > V_148 ) ;
F_147 ( V_152 -> V_80 , V_128 , V_167 ) ;
V_152 -> V_79 -= V_79 ;
}
static void F_148 ( struct V_87 * V_88 ,
struct V_85 * V_152 , T_1 V_6 ,
T_1 V_79 )
{
F_146 ( V_88 , V_152 , V_6 , V_79 ) ;
V_88 -> V_117 -= V_79 ;
}
static void F_149 ( struct V_87 * V_88 ,
struct V_85 * V_152 , T_1 V_6 ,
T_1 V_79 )
{
unsigned long V_128 , V_167 ;
V_128 = F_130 ( V_152 -> V_6 , V_88 -> V_146 , V_6 ) ;
V_167 = F_132 ( V_79 , V_88 -> V_146 ) ;
F_60 ( V_128 + V_167 > V_148 ) ;
F_150 ( V_152 -> V_80 , V_128 , V_167 ) ;
V_152 -> V_79 += V_79 ;
V_88 -> V_117 += V_79 ;
}
static int F_151 ( struct V_87 * V_88 ,
struct V_85 * V_168 , T_1 * V_6 ,
T_1 * V_79 )
{
unsigned long V_169 = 0 ;
unsigned long V_170 , V_69 ;
unsigned long V_171 ;
V_69 = F_130 ( V_168 -> V_6 , V_88 -> V_146 ,
F_152 ( T_1 , * V_6 , V_168 -> V_6 ) ) ;
V_170 = F_132 ( * V_79 , V_88 -> V_146 ) ;
F_153 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
V_171 = F_154 ( V_168 -> V_80 ,
V_148 , V_69 ) ;
if ( ( V_171 - V_69 ) >= V_170 ) {
V_169 = V_171 - V_69 ;
break;
}
V_69 = V_171 ;
}
if ( V_169 ) {
* V_6 = ( T_1 ) ( V_69 * V_88 -> V_146 ) + V_168 -> V_6 ;
* V_79 = ( T_1 ) ( V_169 ) * V_88 -> V_146 ;
return 0 ;
}
return - 1 ;
}
static struct V_85 *
F_155 ( struct V_87 * V_88 , T_1 * V_6 , T_1 * V_79 ,
unsigned long V_172 )
{
struct V_85 * V_82 ;
struct V_90 * V_119 ;
T_1 V_173 ;
T_1 V_77 ;
T_1 V_174 ;
int V_16 ;
if ( ! V_88 -> V_94 . V_90 )
return NULL ;
V_82 = F_139 ( V_88 , F_133 ( V_88 , * V_6 ) , 0 , 1 ) ;
if ( ! V_82 )
return NULL ;
for ( V_119 = & V_82 -> V_95 ; V_119 ; V_119 = F_91 ( V_119 ) ) {
V_82 = F_92 ( V_119 , struct V_85 , V_95 ) ;
if ( V_82 -> V_79 < * V_79 )
continue;
if ( * V_79 >= V_172 ) {
V_173 = V_82 -> V_6 - V_88 -> V_128 ;
V_77 = V_173 + V_172 - 1 ; ;
F_156 ( V_77 , V_172 ) ;
V_77 = V_77 * V_172 + V_88 -> V_128 ;
V_174 = V_77 - V_82 -> V_6 ;
} else {
V_174 = 0 ;
V_77 = V_82 -> V_6 ;
}
if ( V_82 -> V_79 < * V_79 + V_174 )
continue;
if ( V_82 -> V_80 ) {
V_16 = F_151 ( V_88 , V_82 , & V_77 , V_79 ) ;
if ( ! V_16 ) {
* V_6 = V_77 ;
return V_82 ;
}
continue;
}
* V_6 = V_77 ;
* V_79 = V_82 -> V_79 - V_174 ;
return V_82 ;
}
return NULL ;
}
static void F_157 ( struct V_87 * V_88 ,
struct V_85 * V_152 , T_1 V_6 )
{
V_152 -> V_6 = F_133 ( V_88 , V_6 ) ;
V_152 -> V_79 = 0 ;
F_97 ( & V_152 -> V_107 ) ;
F_95 ( V_88 , V_152 ) ;
V_88 -> V_104 ++ ;
V_88 -> V_105 -> V_106 ( V_88 ) ;
}
static void F_158 ( struct V_87 * V_88 ,
struct V_85 * V_168 )
{
F_93 ( V_88 , V_168 ) ;
F_53 ( V_168 -> V_80 ) ;
F_94 ( V_97 , V_168 ) ;
V_88 -> V_104 -- ;
V_88 -> V_105 -> V_106 ( V_88 ) ;
}
static T_7 int F_159 ( struct V_87 * V_88 ,
struct V_85 * V_168 ,
T_1 * V_6 , T_1 * V_79 )
{
T_1 V_175 ;
T_1 V_176 , V_177 ;
int V_16 ;
V_92:
V_175 = V_168 -> V_6 + ( T_1 ) ( V_148 * V_88 -> V_146 ) - 1 ;
V_176 = * V_6 ;
V_177 = V_88 -> V_146 ;
V_177 = F_117 ( V_177 , V_175 - V_176 + 1 ) ;
V_16 = F_151 ( V_88 , V_168 , & V_176 , & V_177 ) ;
if ( V_16 < 0 || V_176 != * V_6 )
return - V_178 ;
V_177 = F_117 ( V_177 , * V_79 ) ;
V_177 = F_117 ( V_177 , V_175 - V_176 + 1 ) ;
F_148 ( V_88 , V_168 , V_176 , V_177 ) ;
* V_6 += V_177 ;
* V_79 -= V_177 ;
if ( * V_79 ) {
struct V_90 * V_96 = F_91 ( & V_168 -> V_95 ) ;
if ( ! V_168 -> V_79 )
F_158 ( V_88 , V_168 ) ;
if ( ! V_96 )
return - V_178 ;
V_168 = F_92 ( V_96 , struct V_85 ,
V_95 ) ;
if ( ! V_168 -> V_80 )
return - V_179 ;
V_176 = * V_6 ;
V_177 = V_88 -> V_146 ;
V_16 = F_151 ( V_88 , V_168 , & V_176 ,
& V_177 ) ;
if ( V_16 < 0 || V_176 != * V_6 )
return - V_179 ;
goto V_92;
} else if ( ! V_168 -> V_79 )
F_158 ( V_88 , V_168 ) ;
return 0 ;
}
static T_1 F_160 ( struct V_87 * V_88 ,
struct V_85 * V_152 , T_1 V_6 ,
T_1 V_79 )
{
T_1 V_180 = 0 ;
T_1 V_175 ;
V_175 = V_152 -> V_6 + ( T_1 ) ( V_148 * V_88 -> V_146 ) ;
V_180 = F_117 ( V_175 - V_6 , V_79 ) ;
F_149 ( V_88 , V_152 , V_6 , V_180 ) ;
return V_180 ;
}
static bool F_161 ( struct V_87 * V_88 ,
struct V_85 * V_152 )
{
struct V_26 * V_27 = V_88 -> V_159 ;
if ( V_88 -> V_158 < V_88 -> V_166 ) {
if ( V_152 -> V_79 <= V_27 -> V_181 * 4 ) {
if ( V_88 -> V_158 * 2 <= V_88 -> V_166 )
return false ;
} else {
return false ;
}
}
if ( ( ( V_148 * V_88 -> V_146 ) >> 1 ) > V_27 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_162 ( struct V_87 * V_88 ,
struct V_85 * V_152 )
{
struct V_85 * V_168 ;
struct V_26 * V_27 = NULL ;
int V_182 = 0 ;
T_1 V_79 , V_6 , V_183 ;
int V_16 ;
V_79 = V_152 -> V_79 ;
V_6 = V_152 -> V_6 ;
if ( ! V_88 -> V_105 -> F_161 ( V_88 , V_152 ) )
return 0 ;
if ( V_88 -> V_105 == & V_184 )
V_27 = V_88 -> V_159 ;
V_92:
if ( V_27 && ! F_112 ( & V_27 -> V_134 ) ) {
struct V_123 * V_124 ;
struct V_90 * V_119 ;
struct V_85 * V_82 ;
V_124 = F_113 ( V_27 -> V_134 . V_96 ,
struct V_123 ,
V_135 ) ;
F_15 ( & V_124 -> V_31 ) ;
V_119 = F_90 ( & V_124 -> V_3 ) ;
if ( ! V_119 ) {
F_17 ( & V_124 -> V_31 ) ;
goto V_185;
}
V_82 = F_92 ( V_119 , struct V_85 , V_95 ) ;
if ( ! V_82 -> V_80 ) {
F_17 ( & V_124 -> V_31 ) ;
goto V_185;
}
if ( V_82 -> V_6 == F_133 ( V_88 , V_6 ) ) {
V_183 = F_160 ( V_88 , V_82 ,
V_6 , V_79 ) ;
V_79 -= V_183 ;
V_6 += V_183 ;
}
F_17 ( & V_124 -> V_31 ) ;
if ( ! V_79 ) {
V_16 = 1 ;
goto V_102;
}
}
V_185:
V_168 = F_139 ( V_88 , F_133 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_168 ) {
F_60 ( V_182 ) ;
goto V_186;
}
V_183 = F_160 ( V_88 , V_168 , V_6 , V_79 ) ;
V_79 -= V_183 ;
V_6 += V_183 ;
V_182 = 0 ;
if ( ! V_79 ) {
V_16 = 1 ;
goto V_102;
} else
goto V_92;
V_186:
if ( V_152 && V_152 -> V_80 ) {
F_157 ( V_88 , V_152 , V_6 ) ;
V_182 = 1 ;
V_152 = NULL ;
goto V_92;
} else {
F_17 ( & V_88 -> V_93 ) ;
if ( ! V_152 ) {
V_152 = F_102 ( V_97 ,
V_55 ) ;
if ( ! V_152 ) {
F_15 ( & V_88 -> V_93 ) ;
V_16 = - V_56 ;
goto V_102;
}
}
V_152 -> V_80 = F_50 ( V_60 , V_55 ) ;
F_15 ( & V_88 -> V_93 ) ;
if ( ! V_152 -> V_80 ) {
V_16 = - V_56 ;
goto V_102;
}
goto V_92;
}
V_102:
if ( V_152 ) {
if ( V_152 -> V_80 )
F_53 ( V_152 -> V_80 ) ;
F_94 ( V_97 , V_152 ) ;
}
return V_16 ;
}
static bool F_163 ( struct V_87 * V_88 ,
struct V_85 * V_152 , bool V_187 )
{
struct V_85 * V_188 ;
struct V_85 * V_189 ;
bool V_190 = false ;
T_1 V_6 = V_152 -> V_6 ;
T_1 V_79 = V_152 -> V_79 ;
V_189 = F_139 ( V_88 , V_6 + V_79 , 0 , 0 ) ;
if ( V_189 && F_141 ( & V_189 -> V_95 ) )
V_188 = F_92 ( F_141 ( & V_189 -> V_95 ) ,
struct V_85 , V_95 ) ;
else
V_188 = F_139 ( V_88 , V_6 - 1 , 0 , 0 ) ;
if ( V_189 && ! V_189 -> V_80 ) {
if ( V_187 )
F_93 ( V_88 , V_189 ) ;
else
F_142 ( V_88 , V_189 ) ;
V_152 -> V_79 += V_189 -> V_79 ;
F_94 ( V_97 , V_189 ) ;
V_190 = true ;
}
if ( V_188 && ! V_188 -> V_80 &&
V_188 -> V_6 + V_188 -> V_79 == V_6 ) {
if ( V_187 )
F_93 ( V_88 , V_188 ) ;
else
F_142 ( V_88 , V_188 ) ;
V_152 -> V_6 = V_188 -> V_6 ;
V_152 -> V_79 += V_188 -> V_79 ;
F_94 ( V_97 , V_188 ) ;
V_190 = true ;
}
return V_190 ;
}
int F_164 ( struct V_87 * V_88 ,
T_1 V_6 , T_1 V_79 )
{
struct V_85 * V_152 ;
int V_16 = 0 ;
V_152 = F_102 ( V_97 , V_55 ) ;
if ( ! V_152 )
return - V_56 ;
V_152 -> V_6 = V_6 ;
V_152 -> V_79 = V_79 ;
F_15 ( & V_88 -> V_93 ) ;
if ( F_163 ( V_88 , V_152 , true ) )
goto V_191;
V_16 = F_162 ( V_88 , V_152 ) ;
if ( V_16 < 0 ) {
goto V_102;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_102;
}
V_191:
V_16 = F_95 ( V_88 , V_152 ) ;
if ( V_16 )
F_94 ( V_97 , V_152 ) ;
V_102:
F_17 ( & V_88 -> V_93 ) ;
if ( V_16 ) {
F_72 ( V_192 L_13 , V_16 ) ;
F_60 ( V_16 == - V_155 ) ;
}
return V_16 ;
}
int F_165 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_79 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_152 ;
int V_16 ;
bool V_193 = false ;
F_15 ( & V_88 -> V_93 ) ;
V_92:
V_16 = 0 ;
if ( ! V_79 )
goto V_194;
V_152 = F_139 ( V_88 , V_6 , 0 , 0 ) ;
if ( ! V_152 ) {
V_152 = F_139 ( V_88 , F_133 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_152 ) {
F_140 ( V_193 ) ;
goto V_194;
}
}
V_193 = false ;
if ( ! V_152 -> V_80 ) {
F_93 ( V_88 , V_152 ) ;
if ( V_6 == V_152 -> V_6 ) {
T_1 V_195 = F_117 ( V_79 , V_152 -> V_79 ) ;
V_152 -> V_79 -= V_195 ;
V_152 -> V_6 += V_195 ;
if ( V_152 -> V_79 ) {
V_16 = F_95 ( V_88 , V_152 ) ;
F_140 ( V_16 ) ;
} else {
F_94 ( V_97 , V_152 ) ;
}
V_6 += V_195 ;
V_79 -= V_195 ;
goto V_92;
} else {
T_1 V_196 = V_152 -> V_79 + V_152 -> V_6 ;
V_152 -> V_79 = V_6 - V_152 -> V_6 ;
V_16 = F_95 ( V_88 , V_152 ) ;
F_140 ( V_16 ) ;
if ( V_16 )
goto V_194;
if ( V_196 < V_6 + V_79 ) {
V_79 -= V_196 - V_6 ;
V_6 = V_196 ;
goto V_92;
} else if ( V_196 == V_6 + V_79 ) {
goto V_194;
}
F_17 ( & V_88 -> V_93 ) ;
V_16 = F_166 ( V_27 , V_6 + V_79 ,
V_196 - ( V_6 + V_79 ) ) ;
F_140 ( V_16 ) ;
goto V_102;
}
}
V_16 = F_159 ( V_88 , V_152 , & V_6 , & V_79 ) ;
if ( V_16 == - V_179 ) {
V_193 = true ;
goto V_92;
}
V_194:
F_17 ( & V_88 -> V_93 ) ;
V_102:
return V_16 ;
}
void F_167 ( struct V_26 * V_27 ,
T_1 V_79 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_152 ;
struct V_90 * V_91 ;
int V_167 = 0 ;
for ( V_91 = F_90 ( & V_88 -> V_94 ) ; V_91 ; V_91 = F_91 ( V_91 ) ) {
V_152 = F_92 ( V_91 , struct V_85 , V_95 ) ;
if ( V_152 -> V_79 >= V_79 && ! V_27 -> V_197 )
V_167 ++ ;
F_72 ( V_192 L_14 ,
( unsigned long long ) V_152 -> V_6 ,
( unsigned long long ) V_152 -> V_79 ,
( V_152 -> V_80 ) ? L_15 : L_16 ) ;
}
F_72 ( V_198 L_17 ,
F_112 ( & V_27 -> V_134 ) ? L_16 : L_15 ) ;
F_72 ( V_198 L_18
L_19 , V_167 ) ;
}
void F_168 ( struct V_26 * V_27 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
F_169 ( & V_88 -> V_93 ) ;
V_88 -> V_146 = V_27 -> V_181 ;
V_88 -> V_128 = V_27 -> V_8 . V_17 ;
V_88 -> V_159 = V_27 ;
V_88 -> V_105 = & V_184 ;
V_88 -> V_166 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_85 ) ;
}
static int
F_170 (
struct V_26 * V_27 ,
struct V_123 * V_124 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
struct V_90 * V_119 ;
F_15 ( & V_124 -> V_31 ) ;
if ( V_124 -> V_27 != V_27 )
goto V_102;
V_124 -> V_27 = NULL ;
V_124 -> V_199 = 0 ;
F_105 ( & V_124 -> V_135 ) ;
V_119 = F_90 ( & V_124 -> V_3 ) ;
while ( V_119 ) {
bool V_80 ;
V_82 = F_92 ( V_119 , struct V_85 , V_95 ) ;
V_119 = F_91 ( & V_82 -> V_95 ) ;
F_143 ( & V_82 -> V_95 , & V_124 -> V_3 ) ;
V_80 = ( V_82 -> V_80 != NULL ) ;
if ( ! V_80 )
F_163 ( V_88 , V_82 , false ) ;
F_135 ( & V_88 -> V_94 ,
V_82 -> V_6 , & V_82 -> V_95 , V_80 ) ;
}
V_124 -> V_3 = V_200 ;
V_102:
F_17 ( & V_124 -> V_31 ) ;
F_171 ( V_27 ) ;
return 0 ;
}
static void F_172 (
struct V_87 * V_88 )
{
struct V_85 * V_152 ;
struct V_90 * V_119 ;
while ( ( V_119 = F_173 ( & V_88 -> V_94 ) ) != NULL ) {
V_152 = F_92 ( V_119 , struct V_85 , V_95 ) ;
if ( ! V_152 -> V_80 ) {
F_93 ( V_88 , V_152 ) ;
F_94 ( V_97 , V_152 ) ;
} else {
F_158 ( V_88 , V_152 ) ;
}
if ( F_174 () ) {
F_17 ( & V_88 -> V_93 ) ;
F_175 () ;
F_15 ( & V_88 -> V_93 ) ;
}
}
}
void F_106 ( struct V_87 * V_88 )
{
F_15 ( & V_88 -> V_93 ) ;
F_172 ( V_88 ) ;
F_17 ( & V_88 -> V_93 ) ;
}
void F_176 ( struct V_26 * V_27 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_123 * V_124 ;
struct V_98 * V_201 ;
F_15 ( & V_88 -> V_93 ) ;
while ( ( V_201 = V_27 -> V_134 . V_96 ) !=
& V_27 -> V_134 ) {
V_124 = F_113 ( V_201 , struct V_123 ,
V_135 ) ;
F_140 ( V_124 -> V_27 != V_27 ) ;
F_170 ( V_27 , V_124 ) ;
if ( F_174 () ) {
F_17 ( & V_88 -> V_93 ) ;
F_175 () ;
F_15 ( & V_88 -> V_93 ) ;
}
}
F_172 ( V_88 ) ;
F_17 ( & V_88 -> V_93 ) ;
}
T_1 F_177 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_79 , T_1 V_202 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 = NULL ;
T_1 V_203 = V_79 + V_202 ;
T_1 V_16 = 0 ;
T_1 V_204 = 0 ;
T_1 V_205 = 0 ;
F_15 ( & V_88 -> V_93 ) ;
V_82 = F_155 ( V_88 , & V_6 , & V_203 ,
V_27 -> V_206 ) ;
if ( ! V_82 )
goto V_102;
V_16 = V_6 ;
if ( V_82 -> V_80 ) {
F_148 ( V_88 , V_82 , V_6 , V_79 ) ;
if ( ! V_82 -> V_79 )
F_158 ( V_88 , V_82 ) ;
} else {
F_93 ( V_88 , V_82 ) ;
V_205 = V_6 - V_82 -> V_6 ;
V_204 = V_82 -> V_6 ;
V_82 -> V_6 = V_6 + V_79 ;
F_140 ( V_82 -> V_79 < V_79 + V_205 ) ;
V_82 -> V_79 -= V_79 + V_205 ;
if ( ! V_82 -> V_79 )
F_94 ( V_97 , V_82 ) ;
else
F_95 ( V_88 , V_82 ) ;
}
V_102:
F_17 ( & V_88 -> V_93 ) ;
if ( V_205 )
F_164 ( V_88 , V_204 , V_205 ) ;
return V_16 ;
}
int F_178 (
struct V_26 * V_27 ,
struct V_123 * V_124 )
{
struct V_87 * V_88 ;
int V_16 ;
F_15 ( & V_124 -> V_31 ) ;
if ( ! V_27 ) {
V_27 = V_124 -> V_27 ;
if ( ! V_27 ) {
F_17 ( & V_124 -> V_31 ) ;
return 0 ;
}
} else if ( V_124 -> V_27 != V_27 ) {
F_17 ( & V_124 -> V_31 ) ;
return 0 ;
}
F_179 ( & V_27 -> V_167 ) ;
F_17 ( & V_124 -> V_31 ) ;
V_88 = V_27 -> V_109 ;
F_15 ( & V_88 -> V_93 ) ;
V_16 = F_170 ( V_27 , V_124 ) ;
F_17 ( & V_88 -> V_93 ) ;
F_171 ( V_27 ) ;
return V_16 ;
}
static T_1 F_180 ( struct V_26 * V_27 ,
struct V_123 * V_124 ,
struct V_85 * V_82 ,
T_1 V_79 , T_1 V_207 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
int V_133 ;
T_1 V_176 = V_124 -> V_199 ;
T_1 V_177 = V_79 ;
T_1 V_16 = 0 ;
V_176 = V_207 ;
V_177 = V_79 ;
V_133 = F_151 ( V_88 , V_82 , & V_176 , & V_177 ) ;
if ( V_133 )
return 0 ;
V_16 = V_176 ;
F_146 ( V_88 , V_82 , V_16 , V_79 ) ;
return V_16 ;
}
T_1 F_181 ( struct V_26 * V_27 ,
struct V_123 * V_124 , T_1 V_79 ,
T_1 V_207 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 = NULL ;
struct V_90 * V_119 ;
T_1 V_16 = 0 ;
F_15 ( & V_124 -> V_31 ) ;
if ( V_79 > V_124 -> V_208 )
goto V_102;
if ( V_124 -> V_27 != V_27 )
goto V_102;
V_119 = F_90 ( & V_124 -> V_3 ) ;
if ( ! V_119 )
goto V_102;
V_82 = F_92 ( V_119 , struct V_85 , V_95 ) ;
while( 1 ) {
if ( V_82 -> V_79 < V_79 ||
( ! V_82 -> V_80 && V_82 -> V_6 < V_207 ) ) {
V_119 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_119 )
break;
V_82 = F_92 ( V_119 , struct V_85 ,
V_95 ) ;
continue;
}
if ( V_82 -> V_80 ) {
V_16 = F_180 ( V_27 ,
V_124 , V_82 , V_79 ,
V_124 -> V_199 ) ;
if ( V_16 == 0 ) {
V_119 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_119 )
break;
V_82 = F_92 ( V_119 , struct V_85 ,
V_95 ) ;
continue;
}
V_124 -> V_199 += V_79 ;
} else {
V_16 = V_82 -> V_6 ;
V_82 -> V_6 += V_79 ;
V_82 -> V_79 -= V_79 ;
}
if ( V_82 -> V_79 == 0 )
F_143 ( & V_82 -> V_95 , & V_124 -> V_3 ) ;
break;
}
V_102:
F_17 ( & V_124 -> V_31 ) ;
if ( ! V_16 )
return 0 ;
F_15 ( & V_88 -> V_93 ) ;
V_88 -> V_117 -= V_79 ;
if ( V_82 -> V_79 == 0 ) {
V_88 -> V_158 -- ;
if ( V_82 -> V_80 ) {
F_53 ( V_82 -> V_80 ) ;
V_88 -> V_104 -- ;
V_88 -> V_105 -> V_106 ( V_88 ) ;
}
F_94 ( V_97 , V_82 ) ;
}
F_17 ( & V_88 -> V_93 ) ;
return V_16 ;
}
static int F_182 ( struct V_26 * V_27 ,
struct V_85 * V_82 ,
struct V_123 * V_124 ,
T_1 V_6 , T_1 V_79 ,
T_1 V_209 , T_1 V_210 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
unsigned long V_171 ;
unsigned long V_69 ;
unsigned long V_211 ;
unsigned long V_212 ;
unsigned long V_169 ;
unsigned long V_128 = 0 ;
unsigned long V_213 = 0 ;
int V_16 ;
V_69 = F_130 ( V_82 -> V_6 , V_88 -> V_146 ,
F_152 ( T_1 , V_6 , V_82 -> V_6 ) ) ;
V_211 = F_132 ( V_79 , V_88 -> V_146 ) ;
V_212 = F_132 ( V_210 , V_88 -> V_146 ) ;
V_92:
V_169 = 0 ;
F_153 (i, entry->bitmap, BITS_PER_BITMAP) {
V_171 = F_154 ( V_82 -> V_80 ,
V_148 , V_69 ) ;
if ( V_171 - V_69 >= V_212 ) {
V_169 = V_171 - V_69 ;
break;
}
V_69 = V_171 ;
}
if ( ! V_169 )
return - V_49 ;
if ( ! V_213 ) {
V_128 = V_69 ;
V_124 -> V_208 = 0 ;
}
V_213 += V_169 ;
if ( V_124 -> V_208 < V_169 * V_88 -> V_146 )
V_124 -> V_208 = V_169 * V_88 -> V_146 ;
if ( V_213 < V_211 || V_124 -> V_208 < V_209 ) {
V_69 = V_171 + 1 ;
goto V_92;
}
V_124 -> V_199 = V_128 * V_88 -> V_146 + V_82 -> V_6 ;
F_143 ( & V_82 -> V_95 , & V_88 -> V_94 ) ;
V_16 = F_135 ( & V_124 -> V_3 , V_82 -> V_6 ,
& V_82 -> V_95 , 1 ) ;
F_60 ( V_16 ) ;
F_183 ( V_27 , V_124 ,
V_213 * V_88 -> V_146 , 1 ) ;
return 0 ;
}
static T_7 int
F_184 ( struct V_26 * V_27 ,
struct V_123 * V_124 ,
struct V_98 * V_99 , T_1 V_6 , T_1 V_79 ,
T_1 V_209 , T_1 V_210 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_214 = NULL ;
struct V_85 * V_82 = NULL ;
struct V_85 * V_215 ;
struct V_90 * V_119 ;
T_1 V_199 ;
T_1 V_216 ;
T_1 V_217 ;
T_1 V_218 = 0 ;
V_82 = F_139 ( V_88 , V_6 , 0 , 1 ) ;
if ( ! V_82 )
return - V_49 ;
while ( V_82 -> V_80 || V_82 -> V_79 < V_210 ) {
if ( V_82 -> V_80 && F_112 ( & V_82 -> V_107 ) )
F_103 ( & V_82 -> V_107 , V_99 ) ;
V_119 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_119 )
return - V_49 ;
V_82 = F_92 ( V_119 , struct V_85 , V_95 ) ;
}
V_199 = V_82 -> V_6 ;
V_216 = V_82 -> V_79 ;
V_217 = V_82 -> V_79 ;
V_214 = V_82 ;
V_215 = V_82 ;
for ( V_119 = F_91 ( & V_82 -> V_95 ) ; V_119 ;
V_119 = F_91 ( & V_82 -> V_95 ) ) {
V_82 = F_92 ( V_119 , struct V_85 , V_95 ) ;
if ( V_82 -> V_80 ) {
if ( F_112 ( & V_82 -> V_107 ) )
F_103 ( & V_82 -> V_107 , V_99 ) ;
continue;
}
if ( V_82 -> V_79 < V_210 )
continue;
V_215 = V_82 ;
V_216 += V_82 -> V_79 ;
if ( V_82 -> V_79 > V_217 )
V_217 = V_82 -> V_79 ;
}
if ( V_216 < V_79 || V_217 < V_209 )
return - V_49 ;
V_124 -> V_199 = V_214 -> V_6 ;
V_119 = & V_214 -> V_95 ;
do {
int V_16 ;
V_82 = F_92 ( V_119 , struct V_85 , V_95 ) ;
V_119 = F_91 ( & V_82 -> V_95 ) ;
if ( V_82 -> V_80 || V_82 -> V_79 < V_210 )
continue;
F_143 ( & V_82 -> V_95 , & V_88 -> V_94 ) ;
V_16 = F_135 ( & V_124 -> V_3 , V_82 -> V_6 ,
& V_82 -> V_95 , 0 ) ;
V_218 += V_82 -> V_79 ;
F_60 ( V_16 ) ;
} while ( V_119 && V_82 != V_215 );
V_124 -> V_208 = V_217 ;
F_183 ( V_27 , V_124 , V_218 , 0 ) ;
return 0 ;
}
static T_7 int
F_185 ( struct V_26 * V_27 ,
struct V_123 * V_124 ,
struct V_98 * V_99 , T_1 V_6 , T_1 V_79 ,
T_1 V_209 , T_1 V_210 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
int V_16 = - V_49 ;
T_1 V_219 = F_133 ( V_88 , V_6 ) ;
if ( V_88 -> V_104 == 0 )
return - V_49 ;
V_82 = F_186 ( V_99 , struct V_85 , V_107 ) ;
if ( V_82 -> V_6 != V_219 ) {
V_82 = F_139 ( V_88 , V_219 , 1 , 0 ) ;
if ( V_82 && F_112 ( & V_82 -> V_107 ) )
F_187 ( & V_82 -> V_107 , V_99 ) ;
}
F_188 (entry, bitmaps, list) {
if ( V_82 -> V_79 < V_79 )
continue;
V_16 = F_182 ( V_27 , V_82 , V_124 , V_6 ,
V_79 , V_209 , V_210 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_49 ;
}
int F_189 ( struct V_35 * V_36 ,
struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_123 * V_124 ,
T_1 V_6 , T_1 V_79 , T_1 V_202 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 , * V_77 ;
F_190 ( V_99 ) ;
T_1 V_210 ;
T_1 V_209 ;
int V_16 ;
if ( F_191 ( V_3 , V_220 ) ) {
V_209 = V_210 = V_79 + V_202 ;
} else if ( V_27 -> V_28 & V_221 ) {
V_209 = V_79 ;
V_210 = V_27 -> V_181 ;
} else {
V_209 = F_116 ( V_79 , ( V_79 + V_202 ) >> 2 ) ;
V_210 = V_27 -> V_181 ;
}
F_15 ( & V_88 -> V_93 ) ;
if ( V_88 -> V_117 < V_79 ) {
F_17 ( & V_88 -> V_93 ) ;
return - V_49 ;
}
F_15 ( & V_124 -> V_31 ) ;
if ( V_124 -> V_27 ) {
V_16 = 0 ;
goto V_102;
}
F_192 ( V_27 , V_6 , V_79 , V_202 ,
V_210 ) ;
F_97 ( & V_99 ) ;
V_16 = F_184 ( V_27 , V_124 , & V_99 , V_6 ,
V_79 + V_202 ,
V_209 , V_210 ) ;
if ( V_16 )
V_16 = F_185 ( V_27 , V_124 , & V_99 ,
V_6 , V_79 + V_202 ,
V_209 , V_210 ) ;
F_104 (entry, tmp, &bitmaps, list)
F_105 ( & V_82 -> V_107 ) ;
if ( ! V_16 ) {
F_179 ( & V_27 -> V_167 ) ;
F_103 ( & V_124 -> V_135 ,
& V_27 -> V_134 ) ;
V_124 -> V_27 = V_27 ;
} else {
F_193 ( V_27 ) ;
}
V_102:
F_17 ( & V_124 -> V_31 ) ;
F_17 ( & V_88 -> V_93 ) ;
return V_16 ;
}
void F_194 ( struct V_123 * V_124 )
{
F_169 ( & V_124 -> V_31 ) ;
F_169 ( & V_124 -> V_222 ) ;
V_124 -> V_3 = V_200 ;
V_124 -> V_208 = 0 ;
F_97 ( & V_124 -> V_135 ) ;
V_124 -> V_27 = NULL ;
}
static int F_195 ( struct V_26 * V_27 ,
T_1 * V_223 , T_1 V_128 , T_1 V_79 ,
T_1 V_224 , T_1 V_225 )
{
struct V_226 * V_227 = V_27 -> V_227 ;
struct V_108 * V_22 = V_27 -> V_22 ;
int V_16 ;
int V_228 = 0 ;
T_1 V_229 = 0 ;
F_15 ( & V_227 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( ! V_27 -> V_197 ) {
V_27 -> V_48 += V_225 ;
V_227 -> V_230 += V_225 ;
V_228 = 1 ;
}
F_17 ( & V_27 -> V_31 ) ;
F_17 ( & V_227 -> V_31 ) ;
V_16 = F_196 ( V_22 -> V_231 ,
V_128 , V_79 , & V_229 ) ;
if ( ! V_16 )
* V_223 += V_229 ;
F_166 ( V_27 , V_224 , V_225 ) ;
if ( V_228 ) {
F_15 ( & V_227 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_197 )
V_227 -> V_232 += V_225 ;
V_27 -> V_48 -= V_225 ;
V_227 -> V_230 -= V_225 ;
F_17 ( & V_227 -> V_31 ) ;
F_17 ( & V_27 -> V_31 ) ;
}
return V_16 ;
}
static int F_197 ( struct V_26 * V_27 ,
T_1 * V_223 , T_1 V_128 , T_1 V_175 , T_1 V_233 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
struct V_90 * V_119 ;
int V_16 = 0 ;
T_1 V_129 ;
T_1 V_162 ;
T_1 V_79 ;
while ( V_128 < V_175 ) {
F_15 ( & V_88 -> V_93 ) ;
if ( V_88 -> V_117 < V_233 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
V_82 = F_139 ( V_88 , V_128 , 0 , 1 ) ;
if ( ! V_82 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
while ( V_82 -> V_80 ) {
V_119 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_119 ) {
F_17 ( & V_88 -> V_93 ) ;
goto V_102;
}
V_82 = F_92 ( V_119 , struct V_85 ,
V_95 ) ;
}
if ( V_82 -> V_6 >= V_175 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
V_129 = V_82 -> V_6 ;
V_162 = V_82 -> V_79 ;
V_128 = F_116 ( V_128 , V_129 ) ;
V_79 = F_117 ( V_129 + V_162 , V_175 ) - V_128 ;
if ( V_79 < V_233 ) {
F_17 ( & V_88 -> V_93 ) ;
goto V_96;
}
F_93 ( V_88 , V_82 ) ;
F_94 ( V_97 , V_82 ) ;
F_17 ( & V_88 -> V_93 ) ;
V_16 = F_195 ( V_27 , V_223 , V_128 , V_79 ,
V_129 , V_162 ) ;
if ( V_16 )
break;
V_96:
V_128 += V_79 ;
if ( F_198 ( V_234 ) ) {
V_16 = - V_235 ;
break;
}
F_175 () ;
}
V_102:
return V_16 ;
}
static int F_199 ( struct V_26 * V_27 ,
T_1 * V_223 , T_1 V_128 , T_1 V_175 , T_1 V_233 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
int V_16 = 0 ;
int V_236 ;
T_1 V_79 ;
T_1 V_6 = F_133 ( V_88 , V_128 ) ;
while ( V_6 < V_175 ) {
bool V_237 = false ;
F_15 ( & V_88 -> V_93 ) ;
if ( V_88 -> V_117 < V_233 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
V_82 = F_139 ( V_88 , V_6 , 1 , 0 ) ;
if ( ! V_82 ) {
F_17 ( & V_88 -> V_93 ) ;
V_237 = true ;
goto V_96;
}
V_79 = V_233 ;
V_236 = F_151 ( V_88 , V_82 , & V_128 , & V_79 ) ;
if ( V_236 || V_128 >= V_175 ) {
F_17 ( & V_88 -> V_93 ) ;
V_237 = true ;
goto V_96;
}
V_79 = F_117 ( V_79 , V_175 - V_128 ) ;
if ( V_79 < V_233 ) {
F_17 ( & V_88 -> V_93 ) ;
goto V_96;
}
F_148 ( V_88 , V_82 , V_128 , V_79 ) ;
if ( V_82 -> V_79 == 0 )
F_158 ( V_88 , V_82 ) ;
F_17 ( & V_88 -> V_93 ) ;
V_16 = F_195 ( V_27 , V_223 , V_128 , V_79 ,
V_128 , V_79 ) ;
if ( V_16 )
break;
V_96:
if ( V_237 ) {
V_6 += V_148 * V_88 -> V_146 ;
} else {
V_128 += V_79 ;
if ( V_128 >= V_6 + V_148 * V_88 -> V_146 )
V_6 += V_148 * V_88 -> V_146 ;
}
if ( F_198 ( V_234 ) ) {
V_16 = - V_235 ;
break;
}
F_175 () ;
}
return V_16 ;
}
int F_200 ( struct V_26 * V_27 ,
T_1 * V_229 , T_1 V_128 , T_1 V_175 , T_1 V_233 )
{
int V_16 ;
* V_229 = 0 ;
V_16 = F_197 ( V_27 , V_229 , V_128 , V_175 , V_233 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_199 ( V_27 , V_229 , V_128 , V_175 , V_233 ) ;
return V_16 ;
}
T_1 F_201 ( struct V_2 * V_238 )
{
struct V_87 * V_88 = V_238 -> V_239 ;
struct V_85 * V_82 = NULL ;
T_1 V_37 = 0 ;
F_15 ( & V_88 -> V_93 ) ;
if ( F_202 ( & V_88 -> V_94 ) )
goto V_102;
V_82 = F_92 ( F_90 ( & V_88 -> V_94 ) ,
struct V_85 , V_95 ) ;
if ( ! V_82 -> V_80 ) {
V_37 = V_82 -> V_6 ;
F_93 ( V_88 , V_82 ) ;
V_82 -> V_6 ++ ;
V_82 -> V_79 -- ;
if ( ! V_82 -> V_79 )
F_94 ( V_97 , V_82 ) ;
else
F_95 ( V_88 , V_82 ) ;
} else {
T_1 V_6 = 0 ;
T_1 V_167 = 1 ;
int V_16 ;
V_16 = F_151 ( V_88 , V_82 , & V_6 , & V_167 ) ;
F_60 ( V_16 ) ;
V_37 = V_6 ;
F_148 ( V_88 , V_82 , V_6 , 1 ) ;
if ( V_82 -> V_79 == 0 )
F_158 ( V_88 , V_82 ) ;
}
V_102:
F_17 ( & V_88 -> V_93 ) ;
return V_37 ;
}
struct V_1 * F_203 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_240 ) ;
if ( V_3 -> V_241 )
V_1 = F_16 ( V_3 -> V_241 ) ;
F_17 ( & V_3 -> V_240 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_240 ) ;
if ( ! F_204 ( V_3 -> V_22 ) )
V_3 -> V_241 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_240 ) ;
return V_1 ;
}
int F_205 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_36 , V_5 ,
V_42 , 0 ) ;
}
int F_206 ( struct V_108 * V_22 , struct V_2 * V_3 )
{
struct V_87 * V_88 = V_3 -> V_239 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_242 = F_207 ( & V_3 -> V_243 ) ;
if ( ! F_191 ( V_3 , V_244 ) )
return 0 ;
if ( F_204 ( V_22 ) )
return 0 ;
V_5 = F_109 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_203 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_102;
if ( V_242 != F_18 ( V_1 ) -> V_74 )
goto V_245;
V_16 = F_96 ( V_3 , V_1 , V_88 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_101 ( V_22 ,
L_20 ,
V_3 -> V_246 . V_17 ) ;
V_245:
F_11 ( V_1 ) ;
V_102:
F_110 ( V_5 ) ;
return V_16 ;
}
int F_208 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 )
{
struct V_87 * V_88 = V_3 -> V_239 ;
struct V_1 * V_1 ;
int V_16 ;
if ( ! F_191 ( V_3 , V_244 ) )
return 0 ;
V_1 = F_203 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_111 ( V_3 , V_1 , V_88 , NULL , V_36 , V_5 , 0 ) ;
if ( V_16 ) {
F_209 ( V_1 , V_1 -> V_140 ) ;
#ifdef F_129
F_101 ( V_3 -> V_22 ,
L_21 ,
V_3 -> V_246 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
static struct V_26 * F_210 ( void )
{
struct V_26 * V_247 ;
V_247 = F_50 ( sizeof( * V_247 ) , V_55 ) ;
if ( ! V_247 )
return NULL ;
V_247 -> V_109 = F_50 ( sizeof( * V_247 -> V_109 ) ,
V_55 ) ;
if ( ! V_247 -> V_109 ) {
F_53 ( V_247 ) ;
return NULL ;
}
V_247 -> V_8 . V_17 = 0 ;
V_247 -> V_8 . V_6 = 1024 * 1024 * 1024 ;
V_247 -> V_8 . type = V_248 ;
V_247 -> V_181 = 4096 ;
F_169 ( & V_247 -> V_31 ) ;
F_97 ( & V_247 -> V_107 ) ;
F_97 ( & V_247 -> V_134 ) ;
F_97 ( & V_247 -> V_249 ) ;
F_168 ( V_247 ) ;
return V_247 ;
}
static int F_211 ( struct V_26 * V_247 , T_1 V_6 ,
T_1 V_79 )
{
struct V_87 * V_88 = V_247 -> V_109 ;
struct V_85 * V_152 ;
int V_16 = 0 ;
F_15 ( & V_88 -> V_93 ) ;
V_152 = F_139 ( V_88 , V_6 , 0 , 0 ) ;
if ( ! V_152 ) {
V_152 = F_139 ( V_88 , F_133 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_152 )
goto V_102;
}
V_250:
if ( V_152 -> V_80 ) {
T_1 V_251 , V_252 ;
struct V_90 * V_91 ;
struct V_85 * V_77 ;
V_251 = V_6 ;
V_252 = V_88 -> V_146 ;
V_16 = F_151 ( V_88 , V_152 , & V_251 , & V_252 ) ;
if ( ! V_16 ) {
if ( V_251 == V_6 ) {
V_16 = 1 ;
goto V_102;
} else if ( V_251 > V_6 &&
V_6 + V_79 > V_251 ) {
V_16 = 1 ;
goto V_102;
}
}
V_91 = F_141 ( & V_152 -> V_95 ) ;
while ( V_91 ) {
V_77 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
if ( V_77 -> V_6 + V_77 -> V_79 < V_6 )
break;
if ( V_6 + V_79 < V_77 -> V_6 ) {
V_91 = F_141 ( & V_152 -> V_95 ) ;
continue;
}
V_152 = V_77 ;
goto V_250;
}
V_91 = F_91 ( & V_152 -> V_95 ) ;
while ( V_91 ) {
V_77 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
if ( V_6 + V_79 < V_77 -> V_6 )
break;
if ( V_77 -> V_6 + V_77 -> V_79 < V_6 ) {
V_91 = F_91 ( & V_152 -> V_95 ) ;
continue;
}
V_152 = V_77 ;
goto V_250;
}
goto V_102;
}
if ( V_152 -> V_6 == V_6 ) {
V_16 = 1 ;
goto V_102;
}
if ( V_6 > V_152 -> V_6 && V_6 < V_152 -> V_6 + V_152 -> V_79 )
V_16 = 1 ;
V_102:
F_17 ( & V_88 -> V_93 ) ;
return V_16 ;
}
static int F_212 ( struct V_26 * V_247 ,
T_1 V_6 , T_1 V_79 , bool V_80 )
{
struct V_87 * V_88 = V_247 -> V_109 ;
struct V_85 * V_152 = NULL , * V_168 ;
void * V_253 = NULL ;
T_1 V_183 ;
int V_16 ;
V_92:
if ( ! V_152 ) {
V_152 = F_102 ( V_97 , V_55 ) ;
if ( ! V_152 )
return - V_56 ;
}
if ( ! V_80 ) {
F_15 ( & V_88 -> V_93 ) ;
V_152 -> V_6 = V_6 ;
V_152 -> V_79 = V_79 ;
V_16 = F_95 ( V_88 , V_152 ) ;
F_17 ( & V_88 -> V_93 ) ;
if ( V_16 )
F_94 ( V_97 , V_152 ) ;
return V_16 ;
}
if ( ! V_253 ) {
V_253 = F_50 ( V_60 , V_55 ) ;
if ( ! V_253 ) {
F_94 ( V_97 , V_152 ) ;
return - V_56 ;
}
}
F_15 ( & V_88 -> V_93 ) ;
V_168 = F_139 ( V_88 , F_133 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_168 ) {
V_152 -> V_80 = V_253 ;
V_253 = NULL ;
F_157 ( V_88 , V_152 , V_6 ) ;
V_168 = V_152 ;
}
V_183 = F_160 ( V_88 , V_168 , V_6 , V_79 ) ;
V_79 -= V_183 ;
V_6 += V_183 ;
F_17 ( & V_88 -> V_93 ) ;
if ( V_79 )
goto V_92;
if ( V_253 )
F_53 ( V_253 ) ;
return 0 ;
}
static int F_213 ( struct V_26 * V_247 )
{
int V_16 = 0 ;
F_72 ( V_72 L_22 ) ;
V_16 = F_166 ( V_247 , 0 , 4 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_23 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 0 , 4 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_24 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , 0 , 4 * 1024 * 1024 ) ) {
F_72 ( V_72 L_25 ) ;
return - 1 ;
}
V_16 = F_166 ( V_247 , 0 , 4 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_26 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 3 * 1024 * 1024 , 1 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_27 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 0 , 1 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_28 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 2 * 1024 * 1024 , 4096 ) ;
if ( V_16 ) {
F_72 ( V_72 L_29 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , 0 , 1 * 1024 * 1024 ) ) {
F_72 ( V_72 L_30 ) ;
return - 1 ;
}
if ( F_211 ( V_247 , 2 * 1024 * 1024 , 4096 ) ) {
F_72 ( V_72 L_31 ) ;
return - 1 ;
}
if ( F_211 ( V_247 , 3 * 1024 * 1024 , 1 * 1024 * 1024 ) ) {
F_72 ( V_72 L_32 ) ;
return - 1 ;
}
F_106 ( V_247 -> V_109 ) ;
return 0 ;
}
static int F_214 ( struct V_26 * V_247 )
{
T_1 V_254 ;
int V_16 ;
F_72 ( V_72 L_33 ) ;
V_16 = F_212 ( V_247 , 0 , 4 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_34 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 0 , 4 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_35 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , 0 , 4 * 1024 * 1024 ) ) {
F_72 ( V_72 L_36 ) ;
return - 1 ;
}
V_16 = F_212 ( V_247 , 0 , 4 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_37 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 1 * 1024 * 1024 , 2 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_38 , V_16 ) ;
return V_16 ;
}
V_254 = ( T_1 ) ( V_148 * 4096 ) ;
V_16 = F_212 ( V_247 , V_254 -
( 2 * 1024 * 1024 ) , 4 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_39
L_40 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , V_254 -
( 1 * 1024 * 1024 ) , 2 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_41 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , V_254 - ( 1 * 1024 * 1024 ) ,
2 * 1024 * 1024 ) ) {
F_72 ( V_72 L_42 ) ;
return - 1 ;
}
F_106 ( V_247 -> V_109 ) ;
return 0 ;
}
static int F_215 ( struct V_26 * V_247 )
{
T_1 V_219 = ( T_1 ) ( V_148 * 4096 ) ;
int V_16 ;
F_72 ( V_72 L_43 ) ;
V_16 = F_212 ( V_247 , 4 * 1024 * 1024 , 1 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_44 , V_16 ) ;
return V_16 ;
}
V_16 = F_212 ( V_247 , 0 , 1 * 1024 * 1024 , 0 ) ;
if ( V_16 ) {
F_72 ( V_72 L_45 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 0 , 1 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_46 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , 0 , 1 * 1024 * 1024 ) ) {
F_72 ( V_72 L_47 ) ;
return - 1 ;
}
V_16 = F_212 ( V_247 , 0 , 1 * 1024 * 1024 , 0 ) ;
if ( V_16 ) {
F_72 ( V_72 L_48 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 4 * 1024 * 1024 , 1 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_49 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , 4 * 1024 * 1024 , 1 * 1024 * 1024 ) ) {
F_72 ( V_72 L_50 ) ;
return - 1 ;
}
V_16 = F_212 ( V_247 , 1 * 1024 * 1024 , 4 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_51 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 512 * 1024 , 3 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_41 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , 512 * 1024 , 3 * 1024 * 1024 ) ) {
F_72 ( V_72 L_52
L_53 ) ;
return - 1 ;
}
F_106 ( V_247 -> V_109 ) ;
V_16 = F_212 ( V_247 , 4 * 1024 * 1024 , 4 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_54 , V_16 ) ;
return V_16 ;
}
V_16 = F_212 ( V_247 , 2 * 1024 * 1024 , 2 * 1024 * 1024 , 0 ) ;
if ( V_16 ) {
F_72 ( V_72 L_55 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 3 * 1024 * 1024 , 4 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_56 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , 3 * 1024 * 1024 , 4 * 1024 * 1024 ) ) {
F_72 ( V_72 L_57 ) ;
return - 1 ;
}
F_106 ( V_247 -> V_109 ) ;
V_16 = F_212 ( V_247 , V_219 + 4 * 1024 * 1024 ,
4 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_58 , V_16 ) ;
return V_16 ;
}
V_16 = F_212 ( V_247 , V_219 - 1 * 1024 * 1024 ,
5 * 1024 * 1024 , 0 ) ;
if ( V_16 ) {
F_72 ( V_72 L_45 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , V_219 + 1 * 1024 * 1024 ,
5 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_59 , V_16 ) ;
return V_16 ;
}
if ( F_211 ( V_247 , V_219 + 1 * 1024 * 1024 ,
5 * 1024 * 1024 ) ) {
F_72 ( V_72 L_60 ) ;
return - 1 ;
}
F_106 ( V_247 -> V_109 ) ;
V_16 = F_212 ( V_247 , 1 * 1024 * 1024 , 2 * 1024 * 1024 , 1 ) ;
if ( V_16 ) {
F_72 ( V_72 L_61 , V_16 ) ;
return V_16 ;
}
V_16 = F_212 ( V_247 , 3 * 1024 * 1024 , 1 * 1024 * 1024 , 0 ) ;
if ( V_16 ) {
F_72 ( V_72 L_45 , V_16 ) ;
return V_16 ;
}
V_16 = F_165 ( V_247 , 1 * 1024 * 1024 , 3 * 1024 * 1024 ) ;
if ( V_16 ) {
F_72 ( V_72 L_62
L_63 , V_16 ) ;
return V_16 ;
}
F_106 ( V_247 -> V_109 ) ;
return 0 ;
}
void F_216 ( void )
{
struct V_26 * V_247 ;
F_72 ( V_72 L_64 ) ;
V_247 = F_210 () ;
if ( ! V_247 ) {
F_72 ( V_72 L_65 ) ;
return;
}
if ( F_213 ( V_247 ) )
goto V_102;
if ( F_214 ( V_247 ) )
goto V_102;
if ( F_215 ( V_247 ) )
goto V_102;
V_102:
F_106 ( V_247 -> V_109 ) ;
F_53 ( V_247 -> V_109 ) ;
F_53 ( V_247 ) ;
F_72 ( V_72 L_66 ) ;
}
