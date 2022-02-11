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
if ( ! V_5 ) {
V_16 = - V_51 ;
goto V_52;
}
if ( V_28 ) {
F_44 ( & V_37 -> V_53 -> V_54 ) ;
if ( ! F_45 ( & V_28 -> V_55 ) ) {
F_46 ( & V_28 -> V_55 ) ;
F_47 ( V_3 , V_37 , V_28 ,
& V_28 -> V_56 , V_5 ,
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
0 , V_57 ) ;
if ( V_16 ) {
F_53 ( & V_37 -> V_53 -> V_54 ) ;
F_54 ( V_37 , V_3 , V_16 ) ;
return V_16 ;
}
V_16 = F_55 ( V_37 , V_3 , V_1 ) ;
if ( V_28 )
F_53 ( & V_37 -> V_53 -> V_54 ) ;
V_52:
if ( V_16 )
F_54 ( V_37 , V_3 , V_16 ) ;
return V_16 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_58 * V_59 ;
unsigned long V_60 ;
V_59 = F_57 ( sizeof( * V_59 ) , V_61 ) ;
if ( ! V_59 )
return - V_51 ;
F_58 ( V_59 , V_1 -> V_24 ) ;
V_60 = ( F_59 ( V_1 ) - 1 ) >> V_62 ;
F_60 ( V_1 -> V_24 , V_59 , NULL , 0 , V_60 ) ;
F_61 ( V_59 ) ;
return 0 ;
}
static int F_62 ( struct V_63 * V_56 , struct V_1 * V_1 ,
struct V_2 * V_3 , int V_64 )
{
int V_65 ;
int V_66 = 0 ;
V_65 = F_63 ( F_59 ( V_1 ) , V_67 ) ;
if ( F_64 ( V_1 ) != V_43 )
V_66 = 1 ;
if ( V_64 && V_66 &&
( V_65 * sizeof( T_2 ) ) >= V_67 )
return - V_50 ;
memset ( V_56 , 0 , sizeof( struct V_63 ) ) ;
V_56 -> V_68 = F_65 ( V_65 , sizeof( struct V_69 * ) , V_61 ) ;
if ( ! V_56 -> V_68 )
return - V_51 ;
V_56 -> V_65 = V_65 ;
V_56 -> V_3 = V_3 ;
V_56 -> V_66 = V_66 ;
V_56 -> V_1 = V_1 ;
return 0 ;
}
static void F_66 ( struct V_63 * V_56 )
{
F_61 ( V_56 -> V_68 ) ;
V_56 -> V_68 = NULL ;
}
static void F_67 ( struct V_63 * V_56 )
{
if ( V_56 -> V_70 ) {
V_56 -> V_70 = NULL ;
V_56 -> V_71 = NULL ;
}
}
static void F_68 ( struct V_63 * V_56 , int V_72 )
{
ASSERT ( V_56 -> V_73 < V_56 -> V_65 ) ;
V_56 -> V_69 = V_56 -> V_68 [ V_56 -> V_73 ++ ] ;
V_56 -> V_70 = F_69 ( V_56 -> V_69 ) ;
V_56 -> V_71 = V_56 -> V_70 ;
V_56 -> V_74 = V_67 ;
if ( V_72 )
memset ( V_56 -> V_70 , 0 , V_67 ) ;
}
static void F_70 ( struct V_63 * V_56 )
{
int V_75 ;
F_67 ( V_56 ) ;
for ( V_75 = 0 ; V_75 < V_56 -> V_65 ; V_75 ++ ) {
if ( V_56 -> V_68 [ V_75 ] ) {
F_71 ( V_56 -> V_68 [ V_75 ] ) ;
F_72 ( V_56 -> V_68 [ V_75 ] ) ;
F_73 ( V_56 -> V_68 [ V_75 ] ) ;
}
}
}
static int F_74 ( struct V_63 * V_56 , struct V_1 * V_1 ,
int V_76 )
{
struct V_69 * V_69 ;
T_3 V_77 = F_75 ( V_1 -> V_24 ) ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_56 -> V_65 ; V_75 ++ ) {
V_69 = F_76 ( V_1 -> V_24 , V_75 , V_77 ) ;
if ( ! V_69 ) {
F_70 ( V_56 ) ;
return - V_51 ;
}
V_56 -> V_68 [ V_75 ] = V_69 ;
if ( V_76 && ! F_77 ( V_69 ) ) {
F_78 ( NULL , V_69 ) ;
F_79 ( V_69 ) ;
if ( ! F_77 ( V_69 ) ) {
F_80 ( F_18 ( V_1 ) -> V_3 -> V_22 ,
L_2 ) ;
F_70 ( V_56 ) ;
return - V_78 ;
}
}
}
for ( V_75 = 0 ; V_75 < V_56 -> V_65 ; V_75 ++ ) {
F_81 ( V_56 -> V_68 [ V_75 ] ) ;
F_82 ( V_56 -> V_68 [ V_75 ] ) ;
}
return 0 ;
}
static void F_83 ( struct V_63 * V_56 , T_1 V_79 )
{
T_4 * V_80 ;
F_68 ( V_56 , 1 ) ;
if ( V_56 -> V_66 ) {
V_56 -> V_70 += ( sizeof( T_2 ) * V_56 -> V_65 ) ;
V_56 -> V_74 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_56 -> V_65 ) ;
} else {
V_56 -> V_70 += sizeof( T_1 ) ;
V_56 -> V_74 -= sizeof( T_1 ) * 2 ;
}
V_80 = V_56 -> V_70 ;
* V_80 = F_84 ( V_79 ) ;
V_56 -> V_70 += sizeof( T_1 ) ;
}
static int F_85 ( struct V_63 * V_56 , T_1 V_79 )
{
T_4 * V_81 ;
if ( V_56 -> V_66 ) {
V_56 -> V_70 += sizeof( T_2 ) * V_56 -> V_65 ;
V_56 -> V_74 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_56 -> V_65 ) ;
} else {
V_56 -> V_70 += sizeof( T_1 ) ;
V_56 -> V_74 -= sizeof( T_1 ) * 2 ;
}
V_81 = V_56 -> V_70 ;
if ( F_86 ( * V_81 ) != V_79 ) {
F_87 ( V_82 L_3
L_4 , * V_81 ,
V_79 ) ;
F_67 ( V_56 ) ;
return - V_78 ;
}
V_56 -> V_70 += sizeof( T_1 ) ;
return 0 ;
}
static void F_88 ( struct V_63 * V_56 , int V_73 )
{
T_2 * V_83 ;
T_2 V_84 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_56 -> V_66 ) {
F_67 ( V_56 ) ;
return;
}
if ( V_73 == 0 )
V_6 = sizeof( T_2 ) * V_56 -> V_65 ;
V_84 = F_89 ( V_56 -> V_71 + V_6 , V_84 ,
V_67 - V_6 ) ;
F_90 ( V_84 , ( char * ) & V_84 ) ;
F_67 ( V_56 ) ;
V_83 = F_69 ( V_56 -> V_68 [ 0 ] ) ;
V_83 += V_73 ;
* V_83 = V_84 ;
}
static int F_91 ( struct V_63 * V_56 , int V_73 )
{
T_2 * V_83 , V_80 ;
T_2 V_84 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_56 -> V_66 ) {
F_68 ( V_56 , 0 ) ;
return 0 ;
}
if ( V_73 == 0 )
V_6 = sizeof( T_2 ) * V_56 -> V_65 ;
V_83 = F_69 ( V_56 -> V_68 [ 0 ] ) ;
V_83 += V_73 ;
V_80 = * V_83 ;
F_68 ( V_56 , 0 ) ;
V_84 = F_89 ( V_56 -> V_71 + V_6 , V_84 ,
V_67 - V_6 ) ;
F_90 ( V_84 , ( char * ) & V_84 ) ;
if ( V_80 != V_84 ) {
F_87 ( V_82 L_5
L_6 ) ;
F_67 ( V_56 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_92 ( struct V_63 * V_56 , T_1 V_6 , T_1 V_85 ,
void * V_86 )
{
struct V_87 * V_88 ;
if ( ! V_56 -> V_70 )
return - V_50 ;
V_88 = V_56 -> V_70 ;
V_88 -> V_6 = F_84 ( V_6 ) ;
V_88 -> V_85 = F_84 ( V_85 ) ;
V_88 -> type = ( V_86 ) ? V_89 :
V_90 ;
V_56 -> V_70 += sizeof( struct V_87 ) ;
V_56 -> V_74 -= sizeof( struct V_87 ) ;
if ( V_56 -> V_74 >= sizeof( struct V_87 ) )
return 0 ;
F_88 ( V_56 , V_56 -> V_73 - 1 ) ;
if ( V_56 -> V_73 >= V_56 -> V_65 )
return 0 ;
F_68 ( V_56 , 1 ) ;
return 0 ;
}
static int F_93 ( struct V_63 * V_56 , void * V_86 )
{
if ( ! V_56 -> V_70 )
return - V_50 ;
if ( V_56 -> V_70 != V_56 -> V_71 ) {
F_88 ( V_56 , V_56 -> V_73 - 1 ) ;
if ( V_56 -> V_73 >= V_56 -> V_65 )
return - V_50 ;
F_68 ( V_56 , 0 ) ;
}
memcpy ( V_56 -> V_70 , V_86 , V_67 ) ;
F_88 ( V_56 , V_56 -> V_73 - 1 ) ;
if ( V_56 -> V_73 < V_56 -> V_65 )
F_68 ( V_56 , 0 ) ;
return 0 ;
}
static void F_94 ( struct V_63 * V_56 )
{
if ( V_56 -> V_70 != V_56 -> V_71 )
F_88 ( V_56 , V_56 -> V_73 - 1 ) ;
else
F_67 ( V_56 ) ;
while ( V_56 -> V_73 < V_56 -> V_65 ) {
F_68 ( V_56 , 1 ) ;
F_88 ( V_56 , V_56 -> V_73 - 1 ) ;
}
}
static int F_95 ( struct V_63 * V_56 ,
struct V_91 * V_88 , T_5 * type )
{
struct V_87 * V_92 ;
int V_16 ;
if ( ! V_56 -> V_70 ) {
V_16 = F_91 ( V_56 , V_56 -> V_73 ) ;
if ( V_16 )
return V_16 ;
}
V_92 = V_56 -> V_70 ;
V_88 -> V_6 = F_86 ( V_92 -> V_6 ) ;
V_88 -> V_85 = F_86 ( V_92 -> V_85 ) ;
* type = V_92 -> type ;
V_56 -> V_70 += sizeof( struct V_87 ) ;
V_56 -> V_74 -= sizeof( struct V_87 ) ;
if ( V_56 -> V_74 >= sizeof( struct V_87 ) )
return 0 ;
F_67 ( V_56 ) ;
return 0 ;
}
static int F_96 ( struct V_63 * V_56 ,
struct V_91 * V_88 )
{
int V_16 ;
V_16 = F_91 ( V_56 , V_56 -> V_73 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_88 -> V_86 , V_56 -> V_70 , V_67 ) ;
F_67 ( V_56 ) ;
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
struct V_63 V_56 ;
struct V_7 V_8 ;
struct V_91 * V_92 , * V_97 ;
F_105 ( V_104 ) ;
T_1 V_105 ;
T_1 V_106 ;
T_1 V_79 ;
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
V_79 = F_108 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( ! F_18 ( V_1 ) -> V_79 ) {
F_19 ( V_3 -> V_22 ,
L_7 ,
V_6 ) ;
return 0 ;
}
if ( F_18 ( V_1 ) -> V_79 != V_79 ) {
F_80 ( V_3 -> V_22 ,
L_8
L_9 ,
F_18 ( V_1 ) -> V_79 , V_79 ) ;
return 0 ;
}
if ( ! V_105 )
return 0 ;
V_16 = F_62 ( & V_56 , V_1 , V_3 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_56 ( V_1 ) ;
if ( V_16 )
goto V_107;
V_16 = F_74 ( & V_56 , V_1 , 1 ) ;
if ( V_16 )
goto V_107;
V_16 = F_91 ( & V_56 , 0 ) ;
if ( V_16 )
goto V_108;
V_16 = F_85 ( & V_56 , V_79 ) ;
if ( V_16 )
goto V_108;
while ( V_105 ) {
V_92 = F_109 ( V_103 ,
V_61 ) ;
if ( ! V_92 )
goto V_108;
V_16 = F_95 ( & V_56 , V_92 , & type ) ;
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
L_10 ) ;
F_102 ( V_103 , V_92 ) ;
goto V_108;
}
} else {
ASSERT ( V_106 ) ;
V_106 -- ;
V_92 -> V_86 = F_57 ( V_67 , V_61 ) ;
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
L_10 ) ;
F_102 ( V_103 , V_92 ) ;
goto V_108;
}
F_110 ( & V_92 -> V_112 , & V_104 ) ;
}
V_105 -- ;
}
F_67 ( & V_56 ) ;
F_111 (e, n, &bitmaps, list) {
F_46 ( & V_92 -> V_112 ) ;
V_16 = F_96 ( & V_56 , V_92 ) ;
if ( V_16 )
goto V_108;
}
F_70 ( & V_56 ) ;
F_97 ( V_94 ) ;
V_16 = 1 ;
V_107:
F_66 ( & V_56 ) ;
return V_16 ;
V_108:
F_70 ( & V_56 ) ;
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
F_115 ( V_22 , L_11 ,
V_28 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_107:
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
int F_116 ( struct V_63 * V_56 ,
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
V_16 = F_92 ( V_56 , V_92 -> V_6 , V_92 -> V_85 ,
V_92 -> V_86 ) ;
if ( V_16 )
goto V_52;
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
V_16 = F_92 ( V_56 , V_132 -> V_135 ,
V_132 -> V_85 , NULL ) ;
if ( V_16 )
goto V_52;
* V_124 += 1 ;
}
return 0 ;
V_52:
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
V_61 ) ;
goto V_52;
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
NULL , V_61 ) ;
F_4 ( V_5 ) ;
goto V_52;
}
}
F_18 ( V_1 ) -> V_79 = V_37 -> V_44 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_122 ( V_15 , V_13 , V_124 ) ;
F_123 ( V_15 , V_13 , V_104 ) ;
F_124 ( V_15 , V_13 , V_37 -> V_44 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
return 0 ;
V_52:
return - 1 ;
}
static T_6 int
F_125 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_63 * V_56 ,
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
V_16 = F_92 ( V_56 , V_141 , V_143 , NULL ) ;
if ( V_16 )
return - V_50 ;
V_135 = V_142 ;
}
return 0 ;
}
static T_6 int
F_129 ( struct V_63 * V_56 , struct V_125 * V_126 )
{
struct V_125 * V_147 , * V_97 ;
int V_16 ;
F_130 (pos, n, bitmap_list) {
struct V_91 * V_88 =
F_117 ( V_147 , struct V_91 , V_112 ) ;
V_16 = F_93 ( V_56 , V_88 -> V_86 ) ;
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
V_61 ) ;
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
struct V_63 * V_56 ,
struct V_148 * * V_149 ,
struct V_125 * V_126 )
{
F_70 ( V_56 ) ;
F_135 ( & F_18 ( V_1 ) -> V_136 , 0 ,
F_59 ( V_1 ) - 1 , V_149 ,
V_61 ) ;
}
int F_47 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_27 * V_28 ,
struct V_63 * V_56 ,
struct V_4 * V_5 , T_1 V_6 )
{
int V_16 ;
struct V_1 * V_1 = V_56 -> V_1 ;
if ( ! V_1 )
return 0 ;
if ( V_28 )
V_3 = V_3 -> V_22 -> V_115 ;
V_16 = F_131 ( V_1 ) ;
if ( V_16 )
goto V_107;
V_16 = F_119 ( V_37 , V_3 , V_1 , V_5 , V_6 ,
V_56 -> V_124 , V_56 -> V_104 ) ;
V_107:
F_66 ( V_56 ) ;
if ( V_16 ) {
F_136 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_79 = 0 ;
if ( V_28 ) {
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_13 ,
V_28 -> V_8 . V_17 ) ;
#endif
}
}
F_55 ( V_37 , V_3 , V_1 ) ;
if ( V_28 ) {
F_15 ( & V_37 -> V_53 -> V_150 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( ! V_16 && F_45 ( & V_28 -> V_151 ) )
V_28 -> V_33 = V_119 ;
else if ( V_16 )
V_28 -> V_33 = V_152 ;
F_17 ( & V_28 -> V_32 ) ;
F_17 ( & V_37 -> V_53 -> V_150 ) ;
V_56 -> V_1 = NULL ;
F_11 ( V_1 ) ;
}
return V_16 ;
}
static int F_138 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_93 * V_94 ,
struct V_27 * V_28 ,
struct V_63 * V_56 ,
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
return - V_78 ;
F_139 ( V_56 -> V_68 ) ;
V_16 = F_62 ( V_56 , V_1 , V_3 , 1 ) ;
if ( V_16 )
return V_16 ;
if ( V_28 && ( V_28 -> V_29 & V_154 ) ) {
F_140 ( & V_28 -> V_155 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_156 ) {
V_28 -> V_33 = V_119 ;
F_17 ( & V_28 -> V_32 ) ;
F_141 ( & V_28 -> V_155 ) ;
F_18 ( V_1 ) -> V_79 = 0 ;
V_16 = 0 ;
V_153 = 1 ;
goto V_107;
}
F_17 ( & V_28 -> V_32 ) ;
}
V_16 = F_74 ( V_56 , V_1 , 0 ) ;
if ( V_16 )
goto V_107;
F_142 ( & F_18 ( V_1 ) -> V_136 , 0 , F_59 ( V_1 ) - 1 ,
0 , & V_149 ) ;
F_83 ( V_56 , V_37 -> V_44 ) ;
F_44 ( & V_94 -> V_157 ) ;
F_15 ( & V_94 -> V_99 ) ;
V_16 = F_116 ( V_56 , V_94 ,
V_28 , & V_124 , & V_104 ,
& V_126 ) ;
if ( V_16 )
goto V_158;
V_16 = F_125 ( V_3 , V_28 , V_56 , & V_124 ) ;
if ( V_16 )
goto V_158;
V_16 = F_129 ( V_56 , & V_126 ) ;
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
if ( V_16 )
goto V_159;
F_94 ( V_56 ) ;
V_16 = F_143 ( V_3 , V_1 , V_56 -> V_68 , V_56 -> V_65 ,
0 , F_59 ( V_1 ) , & V_149 ) ;
if ( V_16 )
goto V_159;
if ( V_28 && ( V_28 -> V_29 & V_154 ) )
F_141 ( & V_28 -> V_155 ) ;
F_70 ( V_56 ) ;
F_135 ( & F_18 ( V_1 ) -> V_136 , 0 ,
F_59 ( V_1 ) - 1 , & V_149 , V_61 ) ;
V_56 -> V_124 = V_124 ;
V_56 -> V_104 = V_104 ;
V_16 = F_144 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_16 )
goto V_107;
return 0 ;
V_107:
V_56 -> V_1 = NULL ;
F_66 ( V_56 ) ;
if ( V_16 ) {
F_136 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_79 = 0 ;
}
F_55 ( V_37 , V_3 , V_1 ) ;
if ( V_153 )
F_11 ( V_1 ) ;
return V_16 ;
V_158:
F_133 ( & V_126 ) ;
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
V_159:
F_134 ( V_1 , V_56 , & V_149 , & V_126 ) ;
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
& V_28 -> V_56 , V_37 ,
V_5 , V_28 -> V_8 . V_17 ) ;
if ( V_16 ) {
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_13 ,
V_28 -> V_8 . V_17 ) ;
#endif
F_15 ( & V_28 -> V_32 ) ;
V_28 -> V_33 = V_152 ;
F_17 ( & V_28 -> V_32 ) ;
V_28 -> V_56 . V_1 = NULL ;
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
T_1 V_74 = V_28 -> V_8 . V_6 ;
T_2 V_179 = V_164 * V_94 -> V_162 ;
T_2 V_180 = F_147 ( V_74 + V_179 - 1 , V_179 ) ;
V_180 = F_159 ( T_2 , V_180 , 1 ) ;
ASSERT ( V_94 -> V_109 <= V_180 ) ;
if ( V_74 < 1024 * 1024 * 1024 )
V_176 = V_181 ;
else
V_176 = V_181 *
F_147 ( V_74 , 1024 * 1024 * 1024 ) ;
V_177 = ( V_94 -> V_109 + 1 ) * V_67 ;
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
T_1 * V_85 )
{
unsigned long V_185 = 0 ;
unsigned long V_186 = 0 ;
unsigned long V_187 , V_75 ;
unsigned long V_188 ;
unsigned long V_189 ;
V_75 = F_146 ( V_184 -> V_6 , V_94 -> V_162 ,
F_159 ( T_1 , * V_6 , V_184 -> V_6 ) ) ;
V_187 = F_148 ( * V_85 , V_94 -> V_162 ) ;
F_167 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
V_188 = F_168 ( V_184 -> V_86 ,
V_164 , V_75 ) ;
V_189 = V_188 - V_75 ;
if ( V_189 >= V_187 ) {
V_185 = V_189 ;
break;
} else if ( V_189 > V_186 ) {
V_186 = V_189 ;
}
V_75 = V_188 ;
}
if ( V_185 ) {
* V_6 = ( T_1 ) ( V_75 * V_94 -> V_162 ) + V_184 -> V_6 ;
* V_85 = ( T_1 ) ( V_185 ) * V_94 -> V_162 ;
return 0 ;
}
* V_85 = ( T_1 ) ( V_186 ) * V_94 -> V_162 ;
return - 1 ;
}
static struct V_91 *
F_169 ( struct V_93 * V_94 , T_1 * V_6 , T_1 * V_85 ,
unsigned long V_190 , T_1 * V_191 )
{
struct V_91 * V_88 ;
struct V_96 * V_130 ;
T_1 V_83 ;
T_1 V_192 ;
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
if ( * V_85 >= V_190 ) {
V_83 = V_88 -> V_6 - V_94 -> V_135 + V_190 - 1 ;
V_83 = F_170 ( V_83 , V_190 ) ;
V_83 = V_83 * V_190 + V_94 -> V_135 ;
V_192 = V_83 - V_88 -> V_6 ;
} else {
V_192 = 0 ;
V_83 = V_88 -> V_6 ;
}
if ( V_88 -> V_85 < * V_85 + V_192 ) {
if ( V_88 -> V_85 > * V_191 )
* V_191 = V_88 -> V_85 ;
continue;
}
if ( V_88 -> V_86 ) {
T_1 V_74 = * V_85 ;
V_16 = F_166 ( V_94 , V_88 , & V_83 , & V_74 ) ;
if ( ! V_16 ) {
* V_6 = V_83 ;
* V_85 = V_74 ;
return V_88 ;
} else if ( V_74 > * V_191 ) {
* V_191 = V_74 ;
}
continue;
}
* V_6 = V_83 ;
* V_85 = V_88 -> V_85 - V_192 ;
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
T_1 V_193 ;
T_1 V_194 , V_195 ;
int V_16 ;
V_98:
V_193 = V_184 -> V_6 + ( T_1 ) ( V_164 * V_94 -> V_162 ) - 1 ;
V_194 = * V_6 ;
V_195 = V_94 -> V_162 ;
V_195 = F_128 ( V_195 , V_193 - V_194 + 1 ) ;
V_16 = F_166 ( V_94 , V_184 , & V_194 , & V_195 ) ;
if ( V_16 < 0 || V_194 != * V_6 )
return - V_196 ;
V_195 = F_128 ( V_195 , * V_85 ) ;
V_195 = F_128 ( V_195 , V_193 - V_194 + 1 ) ;
F_163 ( V_94 , V_184 , V_194 , V_195 ) ;
* V_6 += V_195 ;
* V_85 -= V_195 ;
if ( * V_85 ) {
struct V_96 * V_102 = F_99 ( & V_184 -> V_101 ) ;
if ( ! V_184 -> V_85 )
F_173 ( V_94 , V_184 ) ;
if ( ! V_102 )
return - V_196 ;
V_184 = F_100 ( V_102 , struct V_91 ,
V_101 ) ;
if ( ! V_184 -> V_86 )
return - V_197 ;
V_194 = * V_6 ;
V_195 = V_94 -> V_162 ;
V_16 = F_166 ( V_94 , V_184 , & V_194 ,
& V_195 ) ;
if ( V_16 < 0 || V_194 != * V_6 )
return - V_197 ;
goto V_98;
} else if ( ! V_184 -> V_85 )
F_173 ( V_94 , V_184 ) ;
return 0 ;
}
static T_1 F_175 ( struct V_93 * V_94 ,
struct V_91 * V_168 , T_1 V_6 ,
T_1 V_85 )
{
T_1 V_198 = 0 ;
T_1 V_193 ;
V_193 = V_168 -> V_6 + ( T_1 ) ( V_164 * V_94 -> V_162 ) ;
V_198 = F_128 ( V_193 - V_6 , V_85 ) ;
F_164 ( V_94 , V_168 , V_6 , V_198 ) ;
return V_198 ;
}
static bool F_176 ( struct V_93 * V_94 ,
struct V_91 * V_168 )
{
struct V_27 * V_28 = V_94 -> V_175 ;
if ( V_94 -> V_174 < V_94 -> V_182 ) {
if ( V_168 -> V_85 <= V_28 -> V_199 * 4 ) {
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
static int F_177 ( struct V_93 * V_94 ,
struct V_91 * V_168 )
{
struct V_91 * V_184 ;
struct V_27 * V_28 = NULL ;
int V_200 = 0 ;
T_1 V_85 , V_6 , V_201 ;
int V_16 ;
V_85 = V_168 -> V_85 ;
V_6 = V_168 -> V_6 ;
if ( ! V_94 -> V_110 -> F_176 ( V_94 , V_168 ) )
return 0 ;
if ( V_94 -> V_110 == & V_202 )
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
goto V_203;
}
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
if ( ! V_88 -> V_86 ) {
F_17 ( & V_128 -> V_32 ) ;
goto V_203;
}
if ( V_88 -> V_6 == F_149 ( V_94 , V_6 ) ) {
V_201 = F_175 ( V_94 , V_88 ,
V_6 , V_85 ) ;
V_85 -= V_201 ;
V_6 += V_201 ;
}
F_17 ( & V_128 -> V_32 ) ;
if ( ! V_85 ) {
V_16 = 1 ;
goto V_107;
}
}
V_203:
V_184 = F_154 ( V_94 , F_149 ( V_94 , V_6 ) ,
1 , 0 ) ;
if ( ! V_184 ) {
ASSERT ( V_200 == 0 ) ;
goto V_204;
}
V_201 = F_175 ( V_94 , V_184 , V_6 , V_85 ) ;
V_85 -= V_201 ;
V_6 += V_201 ;
V_200 = 0 ;
if ( ! V_85 ) {
V_16 = 1 ;
goto V_107;
} else
goto V_98;
V_204:
if ( V_168 && V_168 -> V_86 ) {
F_171 ( V_94 , V_168 , V_6 ) ;
V_200 = 1 ;
V_168 = NULL ;
goto V_98;
} else {
F_17 ( & V_94 -> V_99 ) ;
if ( ! V_168 ) {
V_168 = F_109 ( V_103 ,
V_61 ) ;
if ( ! V_168 ) {
F_15 ( & V_94 -> V_99 ) ;
V_16 = - V_51 ;
goto V_107;
}
}
V_168 -> V_86 = F_57 ( V_67 , V_61 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( ! V_168 -> V_86 ) {
V_16 = - V_51 ;
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
static bool F_178 ( struct V_93 * V_94 ,
struct V_91 * V_168 , bool V_205 )
{
struct V_91 * V_206 ;
struct V_91 * V_207 ;
bool V_208 = false ;
T_1 V_6 = V_168 -> V_6 ;
T_1 V_85 = V_168 -> V_85 ;
V_207 = F_154 ( V_94 , V_6 + V_85 , 0 , 0 ) ;
if ( V_207 && F_155 ( & V_207 -> V_101 ) )
V_206 = F_100 ( F_155 ( & V_207 -> V_101 ) ,
struct V_91 , V_101 ) ;
else
V_206 = F_154 ( V_94 , V_6 - 1 , 0 , 0 ) ;
if ( V_207 && ! V_207 -> V_86 ) {
if ( V_205 )
F_101 ( V_94 , V_207 ) ;
else
F_156 ( V_94 , V_207 ) ;
V_168 -> V_85 += V_207 -> V_85 ;
F_102 ( V_103 , V_207 ) ;
V_208 = true ;
}
if ( V_206 && ! V_206 -> V_86 &&
V_206 -> V_6 + V_206 -> V_85 == V_6 ) {
if ( V_205 )
F_101 ( V_94 , V_206 ) ;
else
F_156 ( V_94 , V_206 ) ;
V_168 -> V_6 = V_206 -> V_6 ;
V_168 -> V_85 += V_206 -> V_85 ;
F_102 ( V_103 , V_206 ) ;
V_208 = true ;
}
return V_208 ;
}
static bool F_179 ( struct V_93 * V_94 ,
struct V_91 * V_168 ,
bool V_205 )
{
struct V_91 * V_86 ;
unsigned long V_75 ;
unsigned long V_209 ;
const T_1 V_193 = V_168 -> V_6 + V_168 -> V_85 ;
const T_1 V_210 = F_149 ( V_94 , V_193 ) ;
T_1 V_85 ;
V_86 = F_154 ( V_94 , V_210 , 1 , 0 ) ;
if ( ! V_86 )
return false ;
V_75 = F_146 ( V_86 -> V_6 , V_94 -> V_162 , V_193 ) ;
V_209 = F_168 ( V_86 -> V_86 , V_164 , V_75 ) ;
if ( V_209 == V_75 )
return false ;
V_85 = ( V_209 - V_75 ) * V_94 -> V_162 ;
V_168 -> V_85 += V_85 ;
if ( V_205 )
F_163 ( V_94 , V_86 , V_193 , V_85 ) ;
else
F_161 ( V_94 , V_86 , V_193 , V_85 ) ;
if ( ! V_86 -> V_85 )
F_173 ( V_94 , V_86 ) ;
return true ;
}
static bool F_180 ( struct V_93 * V_94 ,
struct V_91 * V_168 ,
bool V_205 )
{
struct V_91 * V_86 ;
T_1 V_210 ;
unsigned long V_75 ;
unsigned long V_209 ;
unsigned long V_211 ;
T_1 V_85 ;
V_210 = F_149 ( V_94 , V_168 -> V_6 ) ;
if ( V_210 == V_168 -> V_6 ) {
if ( V_168 -> V_6 == 0 )
return false ;
V_210 = F_149 ( V_94 , V_168 -> V_6 - 1 ) ;
}
V_86 = F_154 ( V_94 , V_210 , 1 , 0 ) ;
if ( ! V_86 )
return false ;
V_75 = F_146 ( V_86 -> V_6 , V_94 -> V_162 , V_168 -> V_6 ) - 1 ;
V_209 = 0 ;
V_211 = ( unsigned long ) - 1 ;
F_181 (j, bitmap->bitmap, BITS_PER_BITMAP) {
if ( V_209 > V_75 )
break;
V_211 = V_209 ;
}
if ( V_211 == V_75 )
return false ;
if ( V_211 == ( unsigned long ) - 1 )
V_85 = ( V_75 + 1 ) * V_94 -> V_162 ;
else
V_85 = ( V_75 - V_211 ) * V_94 -> V_162 ;
V_168 -> V_6 -= V_85 ;
V_168 -> V_85 += V_85 ;
if ( V_205 )
F_163 ( V_94 , V_86 , V_168 -> V_6 , V_85 ) ;
else
F_161 ( V_94 , V_86 , V_168 -> V_6 , V_85 ) ;
if ( ! V_86 -> V_85 )
F_173 ( V_94 , V_86 ) ;
return true ;
}
static void F_182 ( struct V_93 * V_94 ,
struct V_91 * V_168 ,
bool V_205 )
{
ASSERT ( ! V_168 -> V_86 ) ;
ASSERT ( F_183 ( & V_168 -> V_101 ) ) ;
if ( V_94 -> V_109 > 0 ) {
bool V_212 ;
bool V_213 = false ;
V_212 = F_179 ( V_94 , V_168 , V_205 ) ;
if ( V_94 -> V_109 > 0 )
V_213 = F_180 ( V_94 , V_168 ,
V_205 ) ;
if ( V_212 || V_213 )
F_178 ( V_94 , V_168 , V_205 ) ;
}
}
int F_184 ( struct V_93 * V_94 ,
T_1 V_6 , T_1 V_85 )
{
struct V_91 * V_168 ;
int V_16 = 0 ;
V_168 = F_109 ( V_103 , V_61 ) ;
if ( ! V_168 )
return - V_51 ;
V_168 -> V_6 = V_6 ;
V_168 -> V_85 = V_85 ;
F_185 ( & V_168 -> V_101 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( F_178 ( V_94 , V_168 , true ) )
goto V_214;
V_16 = F_177 ( V_94 , V_168 ) ;
if ( V_16 < 0 ) {
goto V_107;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_107;
}
V_214:
F_182 ( V_94 , V_168 , true ) ;
V_16 = F_103 ( V_94 , V_168 ) ;
if ( V_16 )
F_102 ( V_103 , V_168 ) ;
V_107:
F_17 ( & V_94 -> V_99 ) ;
if ( V_16 ) {
F_186 ( V_215 L_14 , V_16 ) ;
ASSERT ( V_16 != - V_171 ) ;
}
return V_16 ;
}
int F_187 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_85 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_168 ;
int V_16 ;
bool V_216 = false ;
F_15 ( & V_94 -> V_99 ) ;
V_98:
V_16 = 0 ;
if ( ! V_85 )
goto V_217;
V_168 = F_154 ( V_94 , V_6 , 0 , 0 ) ;
if ( ! V_168 ) {
V_168 = F_154 ( V_94 , F_149 ( V_94 , V_6 ) ,
1 , 0 ) ;
if ( ! V_168 ) {
F_139 ( V_216 ) ;
goto V_217;
}
}
V_216 = false ;
if ( ! V_168 -> V_86 ) {
F_101 ( V_94 , V_168 ) ;
if ( V_6 == V_168 -> V_6 ) {
T_1 V_218 = F_128 ( V_85 , V_168 -> V_85 ) ;
V_168 -> V_85 -= V_218 ;
V_168 -> V_6 += V_218 ;
if ( V_168 -> V_85 ) {
V_16 = F_103 ( V_94 , V_168 ) ;
F_139 ( V_16 ) ;
} else {
F_102 ( V_103 , V_168 ) ;
}
V_6 += V_218 ;
V_85 -= V_218 ;
goto V_98;
} else {
T_1 V_219 = V_168 -> V_85 + V_168 -> V_6 ;
V_168 -> V_85 = V_6 - V_168 -> V_6 ;
V_16 = F_103 ( V_94 , V_168 ) ;
F_139 ( V_16 ) ;
if ( V_16 )
goto V_217;
if ( V_219 < V_6 + V_85 ) {
V_85 -= V_219 - V_6 ;
V_6 = V_219 ;
goto V_98;
} else if ( V_219 == V_6 + V_85 ) {
goto V_217;
}
F_17 ( & V_94 -> V_99 ) ;
V_16 = F_188 ( V_28 , V_6 + V_85 ,
V_219 - ( V_6 + V_85 ) ) ;
F_139 ( V_16 ) ;
goto V_107;
}
}
V_16 = F_174 ( V_94 , V_168 , & V_6 , & V_85 ) ;
if ( V_16 == - V_197 ) {
V_216 = true ;
goto V_98;
}
V_217:
F_17 ( & V_94 -> V_99 ) ;
V_107:
return V_16 ;
}
void F_189 ( struct V_27 * V_28 ,
T_1 V_85 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_168 ;
struct V_96 * V_97 ;
int V_183 = 0 ;
for ( V_97 = F_98 ( & V_94 -> V_100 ) ; V_97 ; V_97 = F_99 ( V_97 ) ) {
V_168 = F_100 ( V_97 , struct V_91 , V_101 ) ;
if ( V_168 -> V_85 >= V_85 && ! V_28 -> V_220 )
V_183 ++ ;
F_190 ( V_28 -> V_22 ,
L_15 ,
V_168 -> V_6 , V_168 -> V_85 ,
( V_168 -> V_86 ) ? L_16 : L_17 ) ;
}
F_19 ( V_28 -> V_22 , L_18 ,
F_45 ( & V_28 -> V_133 ) ? L_17 : L_16 ) ;
F_19 ( V_28 -> V_22 ,
L_19 , V_183 ) ;
}
void F_191 ( struct V_27 * V_28 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
F_192 ( & V_94 -> V_99 ) ;
V_94 -> V_162 = V_28 -> V_199 ;
V_94 -> V_135 = V_28 -> V_8 . V_17 ;
V_94 -> V_175 = V_28 ;
V_94 -> V_110 = & V_202 ;
F_172 ( & V_94 -> V_221 ) ;
F_193 ( & V_94 -> V_157 ) ;
V_94 -> V_182 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_91 ) ;
}
static int
F_194 (
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
V_128 -> V_222 = 0 ;
F_46 ( & V_128 -> V_134 ) ;
V_130 = F_98 ( & V_128 -> V_3 ) ;
while ( V_130 ) {
bool V_86 ;
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
V_130 = F_99 ( & V_88 -> V_101 ) ;
F_157 ( & V_88 -> V_101 , & V_128 -> V_3 ) ;
F_185 ( & V_88 -> V_101 ) ;
V_86 = ( V_88 -> V_86 != NULL ) ;
if ( ! V_86 ) {
F_178 ( V_94 , V_88 , false ) ;
F_182 ( V_94 , V_88 , false ) ;
}
F_150 ( & V_94 -> V_100 ,
V_88 -> V_6 , & V_88 -> V_101 , V_86 ) ;
}
V_128 -> V_3 = V_223 ;
V_107:
F_17 ( & V_128 -> V_32 ) ;
F_48 ( V_28 ) ;
return 0 ;
}
static void F_195 (
struct V_93 * V_94 )
{
struct V_91 * V_168 ;
struct V_96 * V_130 ;
while ( ( V_130 = F_196 ( & V_94 -> V_100 ) ) != NULL ) {
V_168 = F_100 ( V_130 , struct V_91 , V_101 ) ;
if ( ! V_168 -> V_86 ) {
F_101 ( V_94 , V_168 ) ;
F_102 ( V_103 , V_168 ) ;
} else {
F_173 ( V_94 , V_168 ) ;
}
F_197 ( & V_94 -> V_99 ) ;
}
}
void F_112 ( struct V_93 * V_94 )
{
F_15 ( & V_94 -> V_99 ) ;
F_195 ( V_94 ) ;
F_17 ( & V_94 -> V_99 ) ;
}
void F_198 ( struct V_27 * V_28 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_127 * V_128 ;
struct V_125 * V_224 ;
F_15 ( & V_94 -> V_99 ) ;
while ( ( V_224 = V_28 -> V_133 . V_102 ) !=
& V_28 -> V_133 ) {
V_128 = F_117 ( V_224 , struct V_127 ,
V_134 ) ;
F_139 ( V_128 -> V_28 != V_28 ) ;
F_194 ( V_28 , V_128 ) ;
F_197 ( & V_94 -> V_99 ) ;
}
F_195 ( V_94 ) ;
F_17 ( & V_94 -> V_99 ) ;
}
T_1 F_199 ( struct V_27 * V_28 ,
T_1 V_6 , T_1 V_85 , T_1 V_225 ,
T_1 * V_191 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 = NULL ;
T_1 V_226 = V_85 + V_225 ;
T_1 V_16 = 0 ;
T_1 V_227 = 0 ;
T_1 V_228 = 0 ;
F_15 ( & V_94 -> V_99 ) ;
V_88 = F_169 ( V_94 , & V_6 , & V_226 ,
V_28 -> V_229 , V_191 ) ;
if ( ! V_88 )
goto V_107;
V_16 = V_6 ;
if ( V_88 -> V_86 ) {
F_163 ( V_94 , V_88 , V_6 , V_85 ) ;
if ( ! V_88 -> V_85 )
F_173 ( V_94 , V_88 ) ;
} else {
F_101 ( V_94 , V_88 ) ;
V_228 = V_6 - V_88 -> V_6 ;
V_227 = V_88 -> V_6 ;
V_88 -> V_6 = V_6 + V_85 ;
F_139 ( V_88 -> V_85 < V_85 + V_228 ) ;
V_88 -> V_85 -= V_85 + V_228 ;
if ( ! V_88 -> V_85 )
F_102 ( V_103 , V_88 ) ;
else
F_103 ( V_94 , V_88 ) ;
}
V_107:
F_17 ( & V_94 -> V_99 ) ;
if ( V_228 )
F_184 ( V_94 , V_227 , V_228 ) ;
return V_16 ;
}
int F_200 (
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
F_201 ( & V_28 -> V_183 ) ;
F_17 ( & V_128 -> V_32 ) ;
V_94 = V_28 -> V_114 ;
F_15 ( & V_94 -> V_99 ) ;
V_16 = F_194 ( V_28 , V_128 ) ;
F_17 ( & V_94 -> V_99 ) ;
F_48 ( V_28 ) ;
return V_16 ;
}
static T_1 F_202 ( struct V_27 * V_28 ,
struct V_127 * V_128 ,
struct V_91 * V_88 ,
T_1 V_85 , T_1 V_230 ,
T_1 * V_191 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
int V_231 ;
T_1 V_194 = V_128 -> V_222 ;
T_1 V_195 = V_85 ;
T_1 V_16 = 0 ;
V_194 = V_230 ;
V_195 = V_85 ;
V_231 = F_166 ( V_94 , V_88 , & V_194 , & V_195 ) ;
if ( V_231 ) {
if ( V_195 > * V_191 )
* V_191 = V_195 ;
return 0 ;
}
V_16 = V_194 ;
F_161 ( V_94 , V_88 , V_16 , V_85 ) ;
return V_16 ;
}
T_1 F_203 ( struct V_27 * V_28 ,
struct V_127 * V_128 , T_1 V_85 ,
T_1 V_230 , T_1 * V_191 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 = NULL ;
struct V_96 * V_130 ;
T_1 V_16 = 0 ;
F_15 ( & V_128 -> V_32 ) ;
if ( V_85 > V_128 -> V_232 )
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
( ! V_88 -> V_86 && V_88 -> V_6 < V_230 ) ) {
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 )
break;
V_88 = F_100 ( V_130 , struct V_91 ,
V_101 ) ;
continue;
}
if ( V_88 -> V_86 ) {
V_16 = F_202 ( V_28 ,
V_128 , V_88 , V_85 ,
V_128 -> V_222 ,
V_191 ) ;
if ( V_16 == 0 ) {
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 )
break;
V_88 = F_100 ( V_130 , struct V_91 ,
V_101 ) ;
continue;
}
V_128 -> V_222 += V_85 ;
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
static int F_204 ( struct V_27 * V_28 ,
struct V_91 * V_88 ,
struct V_127 * V_128 ,
T_1 V_6 , T_1 V_85 ,
T_1 V_233 , T_1 V_234 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
unsigned long V_188 ;
unsigned long V_75 ;
unsigned long V_235 ;
unsigned long V_236 ;
unsigned long V_185 ;
unsigned long V_135 = 0 ;
unsigned long V_237 = 0 ;
int V_16 ;
V_75 = F_146 ( V_88 -> V_6 , V_94 -> V_162 ,
F_159 ( T_1 , V_6 , V_88 -> V_6 ) ) ;
V_235 = F_148 ( V_85 , V_94 -> V_162 ) ;
V_236 = F_148 ( V_234 , V_94 -> V_162 ) ;
V_98:
V_185 = 0 ;
F_167 (i, entry->bitmap, BITS_PER_BITMAP) {
V_188 = F_168 ( V_88 -> V_86 ,
V_164 , V_75 ) ;
if ( V_188 - V_75 >= V_236 ) {
V_185 = V_188 - V_75 ;
break;
}
V_75 = V_188 ;
}
if ( ! V_185 )
return - V_50 ;
if ( ! V_237 ) {
V_135 = V_75 ;
V_128 -> V_232 = 0 ;
}
V_237 += V_185 ;
if ( V_128 -> V_232 < V_185 * V_94 -> V_162 )
V_128 -> V_232 = V_185 * V_94 -> V_162 ;
if ( V_237 < V_235 || V_128 -> V_232 < V_233 ) {
V_75 = V_188 + 1 ;
goto V_98;
}
V_128 -> V_222 = V_135 * V_94 -> V_162 + V_88 -> V_6 ;
F_157 ( & V_88 -> V_101 , & V_94 -> V_100 ) ;
V_16 = F_150 ( & V_128 -> V_3 , V_88 -> V_6 ,
& V_88 -> V_101 , 1 ) ;
ASSERT ( ! V_16 ) ;
F_205 ( V_28 , V_128 ,
V_237 * V_94 -> V_162 , 1 ) ;
return 0 ;
}
static T_7 int
F_206 ( struct V_27 * V_28 ,
struct V_127 * V_128 ,
struct V_125 * V_104 , T_1 V_6 , T_1 V_85 ,
T_1 V_233 , T_1 V_234 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_238 = NULL ;
struct V_91 * V_88 = NULL ;
struct V_91 * V_239 ;
struct V_96 * V_130 ;
T_1 V_240 ;
T_1 V_241 ;
T_1 V_242 = 0 ;
V_88 = F_154 ( V_94 , V_6 , 0 , 1 ) ;
if ( ! V_88 )
return - V_50 ;
while ( V_88 -> V_86 || V_88 -> V_85 < V_234 ) {
if ( V_88 -> V_86 && F_45 ( & V_88 -> V_112 ) )
F_110 ( & V_88 -> V_112 , V_104 ) ;
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 )
return - V_50 ;
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
}
V_240 = V_88 -> V_85 ;
V_241 = V_88 -> V_85 ;
V_238 = V_88 ;
V_239 = V_88 ;
for ( V_130 = F_99 ( & V_88 -> V_101 ) ; V_130 ;
V_130 = F_99 ( & V_88 -> V_101 ) ) {
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
if ( V_88 -> V_86 ) {
if ( F_45 ( & V_88 -> V_112 ) )
F_110 ( & V_88 -> V_112 , V_104 ) ;
continue;
}
if ( V_88 -> V_85 < V_234 )
continue;
V_239 = V_88 ;
V_240 += V_88 -> V_85 ;
if ( V_88 -> V_85 > V_241 )
V_241 = V_88 -> V_85 ;
}
if ( V_240 < V_85 || V_241 < V_233 )
return - V_50 ;
V_128 -> V_222 = V_238 -> V_6 ;
V_130 = & V_238 -> V_101 ;
do {
int V_16 ;
V_88 = F_100 ( V_130 , struct V_91 , V_101 ) ;
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( V_88 -> V_86 || V_88 -> V_85 < V_234 )
continue;
F_157 ( & V_88 -> V_101 , & V_94 -> V_100 ) ;
V_16 = F_150 ( & V_128 -> V_3 , V_88 -> V_6 ,
& V_88 -> V_101 , 0 ) ;
V_242 += V_88 -> V_85 ;
ASSERT ( ! V_16 ) ;
} while ( V_130 && V_88 != V_239 );
V_128 -> V_232 = V_241 ;
F_205 ( V_28 , V_128 , V_242 , 0 ) ;
return 0 ;
}
static T_7 int
F_207 ( struct V_27 * V_28 ,
struct V_127 * V_128 ,
struct V_125 * V_104 , T_1 V_6 , T_1 V_85 ,
T_1 V_233 , T_1 V_234 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 ;
int V_16 = - V_50 ;
T_1 V_210 = F_149 ( V_94 , V_6 ) ;
if ( V_94 -> V_109 == 0 )
return - V_50 ;
V_88 = F_208 ( V_104 , struct V_91 , V_112 ) ;
if ( V_88 -> V_6 != V_210 ) {
V_88 = F_154 ( V_94 , V_210 , 1 , 0 ) ;
if ( V_88 && F_45 ( & V_88 -> V_112 ) )
F_209 ( & V_88 -> V_112 , V_104 ) ;
}
F_118 (entry, bitmaps, list) {
if ( V_88 -> V_85 < V_85 )
continue;
V_16 = F_204 ( V_28 , V_88 , V_128 , V_6 ,
V_85 , V_233 , V_234 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_50 ;
}
int F_210 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_127 * V_128 ,
T_1 V_6 , T_1 V_85 , T_1 V_225 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 , * V_83 ;
F_105 ( V_104 ) ;
T_1 V_234 ;
T_1 V_233 ;
int V_16 ;
if ( F_211 ( V_3 , V_243 ) ) {
V_233 = V_234 = V_85 + V_225 ;
} else if ( V_28 -> V_29 & V_244 ) {
V_233 = V_85 ;
V_234 = V_28 -> V_199 ;
} else {
V_233 = F_127 ( V_85 , ( V_85 + V_225 ) >> 2 ) ;
V_234 = V_28 -> V_199 ;
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
F_212 ( V_28 , V_6 , V_85 , V_225 ,
V_234 ) ;
V_16 = F_206 ( V_28 , V_128 , & V_104 , V_6 ,
V_85 + V_225 ,
V_233 , V_234 ) ;
if ( V_16 )
V_16 = F_207 ( V_28 , V_128 , & V_104 ,
V_6 , V_85 + V_225 ,
V_233 , V_234 ) ;
F_111 (entry, tmp, &bitmaps, list)
F_46 ( & V_88 -> V_112 ) ;
if ( ! V_16 ) {
F_201 ( & V_28 -> V_183 ) ;
F_110 ( & V_128 -> V_134 ,
& V_28 -> V_133 ) ;
V_128 -> V_28 = V_28 ;
} else {
F_213 ( V_28 ) ;
}
V_107:
F_17 ( & V_128 -> V_32 ) ;
F_17 ( & V_94 -> V_99 ) ;
return V_16 ;
}
void F_214 ( struct V_127 * V_128 )
{
F_192 ( & V_128 -> V_32 ) ;
F_192 ( & V_128 -> V_245 ) ;
V_128 -> V_3 = V_223 ;
V_128 -> V_232 = 0 ;
F_172 ( & V_128 -> V_134 ) ;
V_128 -> V_28 = NULL ;
}
static int F_215 ( struct V_27 * V_28 ,
T_1 * V_246 , T_1 V_135 , T_1 V_85 ,
T_1 V_247 , T_1 V_248 ,
struct V_131 * V_132 )
{
struct V_249 * V_250 = V_28 -> V_250 ;
struct V_113 * V_22 = V_28 -> V_22 ;
struct V_93 * V_94 = V_28 -> V_114 ;
int V_16 ;
int V_251 = 0 ;
T_1 V_252 = 0 ;
F_15 ( & V_250 -> V_32 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( ! V_28 -> V_220 ) {
V_28 -> V_49 += V_248 ;
V_250 -> V_253 += V_248 ;
V_251 = 1 ;
}
F_17 ( & V_28 -> V_32 ) ;
F_17 ( & V_250 -> V_32 ) ;
V_16 = F_216 ( V_22 -> V_254 ,
V_135 , V_85 , & V_252 ) ;
if ( ! V_16 )
* V_246 += V_252 ;
F_44 ( & V_94 -> V_157 ) ;
F_188 ( V_28 , V_247 , V_248 ) ;
F_217 ( & V_132 -> V_112 ) ;
F_53 ( & V_94 -> V_157 ) ;
if ( V_251 ) {
F_15 ( & V_250 -> V_32 ) ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_220 )
V_250 -> V_255 += V_248 ;
V_28 -> V_49 -= V_248 ;
V_250 -> V_253 -= V_248 ;
F_17 ( & V_250 -> V_32 ) ;
F_17 ( & V_28 -> V_32 ) ;
}
return V_16 ;
}
static int F_218 ( struct V_27 * V_28 ,
T_1 * V_246 , T_1 V_135 , T_1 V_193 , T_1 V_256 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 ;
struct V_96 * V_130 ;
int V_16 = 0 ;
T_1 V_141 ;
T_1 V_178 ;
T_1 V_85 ;
while ( V_135 < V_193 ) {
struct V_131 V_132 ;
F_44 ( & V_94 -> V_157 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( V_94 -> V_122 < V_256 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
break;
}
V_88 = F_154 ( V_94 , V_135 , 0 , 1 ) ;
if ( ! V_88 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
break;
}
while ( V_88 -> V_86 ) {
V_130 = F_99 ( & V_88 -> V_101 ) ;
if ( ! V_130 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
goto V_107;
}
V_88 = F_100 ( V_130 , struct V_91 ,
V_101 ) ;
}
if ( V_88 -> V_6 >= V_193 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
break;
}
V_141 = V_88 -> V_6 ;
V_178 = V_88 -> V_85 ;
V_135 = F_127 ( V_135 , V_141 ) ;
V_85 = F_128 ( V_141 + V_178 , V_193 ) - V_135 ;
if ( V_85 < V_256 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
goto V_102;
}
F_101 ( V_94 , V_88 ) ;
F_102 ( V_103 , V_88 ) ;
F_17 ( & V_94 -> V_99 ) ;
V_132 . V_135 = V_141 ;
V_132 . V_85 = V_178 ;
F_110 ( & V_132 . V_112 , & V_94 -> V_221 ) ;
F_53 ( & V_94 -> V_157 ) ;
V_16 = F_215 ( V_28 , V_246 , V_135 , V_85 ,
V_141 , V_178 , & V_132 ) ;
if ( V_16 )
break;
V_102:
V_135 += V_85 ;
if ( F_219 ( V_257 ) ) {
V_16 = - V_258 ;
break;
}
F_220 () ;
}
V_107:
return V_16 ;
}
static int F_221 ( struct V_27 * V_28 ,
T_1 * V_246 , T_1 V_135 , T_1 V_193 , T_1 V_256 )
{
struct V_93 * V_94 = V_28 -> V_114 ;
struct V_91 * V_88 ;
int V_16 = 0 ;
int V_259 ;
T_1 V_85 ;
T_1 V_6 = F_149 ( V_94 , V_135 ) ;
while ( V_6 < V_193 ) {
bool V_260 = false ;
struct V_131 V_132 ;
F_44 ( & V_94 -> V_157 ) ;
F_15 ( & V_94 -> V_99 ) ;
if ( V_94 -> V_122 < V_256 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
break;
}
V_88 = F_154 ( V_94 , V_6 , 1 , 0 ) ;
if ( ! V_88 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
V_260 = true ;
goto V_102;
}
V_85 = V_256 ;
V_259 = F_166 ( V_94 , V_88 , & V_135 , & V_85 ) ;
if ( V_259 || V_135 >= V_193 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
V_260 = true ;
goto V_102;
}
V_85 = F_128 ( V_85 , V_193 - V_135 ) ;
if ( V_85 < V_256 ) {
F_17 ( & V_94 -> V_99 ) ;
F_53 ( & V_94 -> V_157 ) ;
goto V_102;
}
F_163 ( V_94 , V_88 , V_135 , V_85 ) ;
if ( V_88 -> V_85 == 0 )
F_173 ( V_94 , V_88 ) ;
F_17 ( & V_94 -> V_99 ) ;
V_132 . V_135 = V_135 ;
V_132 . V_85 = V_85 ;
F_110 ( & V_132 . V_112 , & V_94 -> V_221 ) ;
F_53 ( & V_94 -> V_157 ) ;
V_16 = F_215 ( V_28 , V_246 , V_135 , V_85 ,
V_135 , V_85 , & V_132 ) ;
if ( V_16 )
break;
V_102:
if ( V_260 ) {
V_6 += V_164 * V_94 -> V_162 ;
} else {
V_135 += V_85 ;
if ( V_135 >= V_6 + V_164 * V_94 -> V_162 )
V_6 += V_164 * V_94 -> V_162 ;
}
if ( F_219 ( V_257 ) ) {
V_16 = - V_258 ;
break;
}
F_220 () ;
}
return V_16 ;
}
int F_222 ( struct V_27 * V_28 ,
T_1 * V_252 , T_1 V_135 , T_1 V_193 , T_1 V_256 )
{
int V_16 ;
* V_252 = 0 ;
F_15 ( & V_28 -> V_32 ) ;
if ( V_28 -> V_261 ) {
F_17 ( & V_28 -> V_32 ) ;
return 0 ;
}
F_201 ( & V_28 -> V_262 ) ;
F_17 ( & V_28 -> V_32 ) ;
V_16 = F_218 ( V_28 , V_252 , V_135 , V_193 , V_256 ) ;
if ( V_16 )
goto V_107;
V_16 = F_221 ( V_28 , V_252 , V_135 , V_193 , V_256 ) ;
V_107:
F_15 ( & V_28 -> V_32 ) ;
if ( F_223 ( & V_28 -> V_262 ) &&
V_28 -> V_261 ) {
struct V_263 * V_264 ;
struct V_265 * V_266 ;
F_17 ( & V_28 -> V_32 ) ;
F_224 ( V_28 -> V_22 -> V_267 ) ;
V_264 = & V_28 -> V_22 -> V_268 . V_269 ;
F_225 ( & V_264 -> V_32 ) ;
V_266 = F_226 ( V_264 , V_28 -> V_8 . V_17 ,
1 ) ;
F_227 ( ! V_266 ) ;
F_228 ( V_264 , V_266 ) ;
F_229 ( & V_264 -> V_32 ) ;
F_230 ( V_28 -> V_22 -> V_267 ) ;
F_231 ( V_266 ) ;
F_231 ( V_266 ) ;
F_112 ( V_28 -> V_114 ) ;
} else {
F_17 ( & V_28 -> V_32 ) ;
}
return V_16 ;
}
T_1 F_232 ( struct V_2 * V_270 )
{
struct V_93 * V_94 = V_270 -> V_271 ;
struct V_91 * V_88 = NULL ;
T_1 V_38 = 0 ;
F_15 ( & V_94 -> V_99 ) ;
if ( F_233 ( & V_94 -> V_100 ) )
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
V_16 = F_166 ( V_94 , V_88 , & V_6 , & V_183 ) ;
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
struct V_1 * F_234 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_272 ) ;
if ( V_3 -> V_273 )
V_1 = F_16 ( V_3 -> V_273 ) ;
F_17 ( & V_3 -> V_272 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_272 ) ;
if ( ! F_235 ( V_3 -> V_22 ) )
V_3 -> V_273 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_272 ) ;
return V_1 ;
}
int F_236 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_37 , V_5 ,
V_43 , 0 ) ;
}
int F_237 ( struct V_113 * V_22 , struct V_2 * V_3 )
{
struct V_93 * V_94 = V_3 -> V_271 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_274 = F_238 ( & V_3 -> V_275 ) ;
if ( ! F_211 ( V_3 , V_276 ) )
return 0 ;
if ( F_235 ( V_22 ) )
return 0 ;
V_5 = F_43 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_234 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_107;
if ( V_274 != F_18 ( V_1 ) -> V_79 )
goto V_277;
V_16 = F_104 ( V_3 , V_1 , V_94 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_80 ( V_22 ,
L_20 ,
V_3 -> V_278 . V_17 ) ;
V_277:
F_11 ( V_1 ) ;
V_107:
F_49 ( V_5 ) ;
return V_16 ;
}
int F_239 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_93 * V_94 = V_3 -> V_271 ;
int V_16 ;
struct V_63 V_56 ;
bool V_279 = true ;
if ( ! F_211 ( V_3 , V_276 ) )
return 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_16 = F_138 ( V_3 , V_1 , V_94 , NULL , & V_56 ,
V_37 , V_5 , 0 ) ;
if ( ! V_16 ) {
V_279 = false ;
V_16 = F_47 ( V_3 , V_37 , NULL , & V_56 , V_5 , 0 ) ;
}
if ( V_16 ) {
if ( V_279 )
F_240 ( V_1 , V_1 -> V_137 ) ;
#ifdef F_137
F_80 ( V_3 -> V_22 ,
L_21 ,
V_3 -> V_278 . V_17 ) ;
#endif
}
return V_16 ;
}
int F_241 ( struct V_27 * V_280 ,
T_1 V_6 , T_1 V_85 , bool V_86 )
{
struct V_93 * V_94 = V_280 -> V_114 ;
struct V_91 * V_168 = NULL , * V_184 ;
void * V_281 = NULL ;
T_1 V_201 ;
int V_16 ;
V_98:
if ( ! V_168 ) {
V_168 = F_109 ( V_103 , V_61 ) ;
if ( ! V_168 )
return - V_51 ;
}
if ( ! V_86 ) {
F_15 ( & V_94 -> V_99 ) ;
V_168 -> V_6 = V_6 ;
V_168 -> V_85 = V_85 ;
V_16 = F_103 ( V_94 , V_168 ) ;
F_17 ( & V_94 -> V_99 ) ;
if ( V_16 )
F_102 ( V_103 , V_168 ) ;
return V_16 ;
}
if ( ! V_281 ) {
V_281 = F_57 ( V_67 , V_61 ) ;
if ( ! V_281 ) {
F_102 ( V_103 , V_168 ) ;
return - V_51 ;
}
}
F_15 ( & V_94 -> V_99 ) ;
V_184 = F_154 ( V_94 , F_149 ( V_94 , V_6 ) ,
1 , 0 ) ;
if ( ! V_184 ) {
V_168 -> V_86 = V_281 ;
V_281 = NULL ;
F_171 ( V_94 , V_168 , V_6 ) ;
V_184 = V_168 ;
V_168 = NULL ;
}
V_201 = F_175 ( V_94 , V_184 , V_6 , V_85 ) ;
V_85 -= V_201 ;
V_6 += V_201 ;
F_17 ( & V_94 -> V_99 ) ;
if ( V_85 )
goto V_98;
if ( V_168 )
F_102 ( V_103 , V_168 ) ;
if ( V_281 )
F_61 ( V_281 ) ;
return 0 ;
}
int F_242 ( struct V_27 * V_280 ,
T_1 V_6 , T_1 V_85 )
{
struct V_93 * V_94 = V_280 -> V_114 ;
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
V_282:
if ( V_168 -> V_86 ) {
T_1 V_283 , V_284 ;
struct V_96 * V_97 ;
struct V_91 * V_83 ;
V_283 = V_6 ;
V_284 = V_94 -> V_162 ;
V_16 = F_166 ( V_94 , V_168 , & V_283 , & V_284 ) ;
if ( ! V_16 ) {
if ( V_283 == V_6 ) {
V_16 = 1 ;
goto V_107;
} else if ( V_283 > V_6 &&
V_6 + V_85 > V_283 ) {
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
goto V_282;
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
goto V_282;
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
