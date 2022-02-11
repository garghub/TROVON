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
struct V_2 * V_3 , int V_58 )
{
int V_59 ;
int V_60 = 0 ;
V_59 = F_55 ( F_51 ( V_1 ) , V_61 ) ;
if ( F_56 ( V_1 ) != V_42 )
V_60 = 1 ;
if ( V_58 && V_60 &&
( V_59 * sizeof( T_2 ) ) >= V_61 )
return - V_49 ;
memset ( V_57 , 0 , sizeof( struct V_57 ) ) ;
V_57 -> V_62 = F_49 ( sizeof( struct V_63 * ) * V_59 , V_54 ) ;
if ( ! V_57 -> V_62 )
return - V_55 ;
V_57 -> V_59 = V_59 ;
V_57 -> V_3 = V_3 ;
V_57 -> V_60 = V_60 ;
return 0 ;
}
static void F_57 ( struct V_57 * V_57 )
{
F_53 ( V_57 -> V_62 ) ;
}
static void F_58 ( struct V_57 * V_57 )
{
if ( V_57 -> V_64 ) {
F_59 ( V_57 -> V_63 ) ;
V_57 -> V_64 = NULL ;
V_57 -> V_65 = NULL ;
}
}
static void F_60 ( struct V_57 * V_57 , int V_66 )
{
ASSERT ( V_57 -> V_67 < V_57 -> V_59 ) ;
V_57 -> V_63 = V_57 -> V_62 [ V_57 -> V_67 ++ ] ;
V_57 -> V_64 = F_61 ( V_57 -> V_63 ) ;
V_57 -> V_65 = V_57 -> V_64 ;
V_57 -> V_68 = V_61 ;
if ( V_66 )
memset ( V_57 -> V_64 , 0 , V_61 ) ;
}
static void F_62 ( struct V_57 * V_57 )
{
int V_69 ;
F_58 ( V_57 ) ;
for ( V_69 = 0 ; V_69 < V_57 -> V_59 ; V_69 ++ ) {
if ( V_57 -> V_62 [ V_69 ] ) {
F_63 ( V_57 -> V_62 [ V_69 ] ) ;
F_64 ( V_57 -> V_62 [ V_69 ] ) ;
F_65 ( V_57 -> V_62 [ V_69 ] ) ;
}
}
}
static int F_66 ( struct V_57 * V_57 , struct V_1 * V_1 ,
int V_70 )
{
struct V_63 * V_63 ;
T_3 V_71 = F_67 ( V_1 -> V_24 ) ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_57 -> V_59 ; V_69 ++ ) {
V_63 = F_68 ( V_1 -> V_24 , V_69 , V_71 ) ;
if ( ! V_63 ) {
F_62 ( V_57 ) ;
return - V_55 ;
}
V_57 -> V_62 [ V_69 ] = V_63 ;
if ( V_70 && ! F_69 ( V_63 ) ) {
F_70 ( NULL , V_63 ) ;
F_71 ( V_63 ) ;
if ( ! F_69 ( V_63 ) ) {
F_72 ( F_18 ( V_1 ) -> V_3 -> V_22 ,
L_2 ) ;
F_62 ( V_57 ) ;
return - V_72 ;
}
}
}
for ( V_69 = 0 ; V_69 < V_57 -> V_59 ; V_69 ++ ) {
F_73 ( V_57 -> V_62 [ V_69 ] ) ;
F_74 ( V_57 -> V_62 [ V_69 ] ) ;
}
return 0 ;
}
static void F_75 ( struct V_57 * V_57 , T_1 V_73 )
{
T_4 * V_74 ;
F_60 ( V_57 , 1 ) ;
if ( V_57 -> V_60 ) {
V_57 -> V_64 += ( sizeof( T_2 ) * V_57 -> V_59 ) ;
V_57 -> V_68 -= sizeof( T_1 ) + ( sizeof( T_2 ) * V_57 -> V_59 ) ;
} else {
V_57 -> V_64 += sizeof( T_1 ) ;
V_57 -> V_68 -= sizeof( T_1 ) * 2 ;
}
V_74 = V_57 -> V_64 ;
* V_74 = F_76 ( V_73 ) ;
V_57 -> V_64 += sizeof( T_1 ) ;
}
static int F_77 ( struct V_57 * V_57 , T_1 V_73 )
{
T_4 * V_75 ;
if ( V_57 -> V_60 ) {
V_57 -> V_64 += sizeof( T_2 ) * V_57 -> V_59 ;
V_57 -> V_68 -= sizeof( T_1 ) +
( sizeof( T_2 ) * V_57 -> V_59 ) ;
} else {
V_57 -> V_64 += sizeof( T_1 ) ;
V_57 -> V_68 -= sizeof( T_1 ) * 2 ;
}
V_75 = V_57 -> V_64 ;
if ( F_78 ( * V_75 ) != V_73 ) {
F_79 ( V_76 L_3
L_4 , * V_75 ,
V_73 ) ;
F_58 ( V_57 ) ;
return - V_72 ;
}
V_57 -> V_64 += sizeof( T_1 ) ;
return 0 ;
}
static void F_80 ( struct V_57 * V_57 , int V_67 )
{
T_2 * V_77 ;
T_2 V_78 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_60 ) {
F_58 ( V_57 ) ;
return;
}
if ( V_67 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_59 ;
V_78 = F_81 ( V_57 -> V_65 + V_6 , V_78 ,
V_61 - V_6 ) ;
F_82 ( V_78 , ( char * ) & V_78 ) ;
F_58 ( V_57 ) ;
V_77 = F_61 ( V_57 -> V_62 [ 0 ] ) ;
V_77 += V_67 ;
* V_77 = V_78 ;
F_59 ( V_57 -> V_62 [ 0 ] ) ;
}
static int F_83 ( struct V_57 * V_57 , int V_67 )
{
T_2 * V_77 , V_74 ;
T_2 V_78 = ~ ( T_2 ) 0 ;
unsigned V_6 = 0 ;
if ( ! V_57 -> V_60 ) {
F_60 ( V_57 , 0 ) ;
return 0 ;
}
if ( V_67 == 0 )
V_6 = sizeof( T_2 ) * V_57 -> V_59 ;
V_77 = F_61 ( V_57 -> V_62 [ 0 ] ) ;
V_77 += V_67 ;
V_74 = * V_77 ;
F_59 ( V_57 -> V_62 [ 0 ] ) ;
F_60 ( V_57 , 0 ) ;
V_78 = F_81 ( V_57 -> V_65 + V_6 , V_78 ,
V_61 - V_6 ) ;
F_82 ( V_78 , ( char * ) & V_78 ) ;
if ( V_74 != V_78 ) {
F_79 ( V_76 L_5
L_6 ) ;
F_58 ( V_57 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_84 ( struct V_57 * V_57 , T_1 V_6 , T_1 V_79 ,
void * V_80 )
{
struct V_81 * V_82 ;
if ( ! V_57 -> V_64 )
return - V_49 ;
V_82 = V_57 -> V_64 ;
V_82 -> V_6 = F_76 ( V_6 ) ;
V_82 -> V_79 = F_76 ( V_79 ) ;
V_82 -> type = ( V_80 ) ? V_83 :
V_84 ;
V_57 -> V_64 += sizeof( struct V_81 ) ;
V_57 -> V_68 -= sizeof( struct V_81 ) ;
if ( V_57 -> V_68 >= sizeof( struct V_81 ) )
return 0 ;
F_80 ( V_57 , V_57 -> V_67 - 1 ) ;
if ( V_57 -> V_67 >= V_57 -> V_59 )
return 0 ;
F_60 ( V_57 , 1 ) ;
return 0 ;
}
static int F_85 ( struct V_57 * V_57 , void * V_80 )
{
if ( ! V_57 -> V_64 )
return - V_49 ;
if ( V_57 -> V_64 != V_57 -> V_65 ) {
F_80 ( V_57 , V_57 -> V_67 - 1 ) ;
if ( V_57 -> V_67 >= V_57 -> V_59 )
return - V_49 ;
F_60 ( V_57 , 0 ) ;
}
memcpy ( V_57 -> V_64 , V_80 , V_61 ) ;
F_80 ( V_57 , V_57 -> V_67 - 1 ) ;
if ( V_57 -> V_67 < V_57 -> V_59 )
F_60 ( V_57 , 0 ) ;
return 0 ;
}
static void F_86 ( struct V_57 * V_57 )
{
if ( V_57 -> V_64 != V_57 -> V_65 )
F_80 ( V_57 , V_57 -> V_67 - 1 ) ;
else
F_58 ( V_57 ) ;
while ( V_57 -> V_67 < V_57 -> V_59 ) {
F_60 ( V_57 , 1 ) ;
F_80 ( V_57 , V_57 -> V_67 - 1 ) ;
}
}
static int F_87 ( struct V_57 * V_57 ,
struct V_85 * V_82 , T_5 * type )
{
struct V_81 * V_86 ;
int V_16 ;
if ( ! V_57 -> V_64 ) {
V_16 = F_83 ( V_57 , V_57 -> V_67 ) ;
if ( V_16 )
return V_16 ;
}
V_86 = V_57 -> V_64 ;
V_82 -> V_6 = F_78 ( V_86 -> V_6 ) ;
V_82 -> V_79 = F_78 ( V_86 -> V_79 ) ;
* type = V_86 -> type ;
V_57 -> V_64 += sizeof( struct V_81 ) ;
V_57 -> V_68 -= sizeof( struct V_81 ) ;
if ( V_57 -> V_68 >= sizeof( struct V_81 ) )
return 0 ;
F_58 ( V_57 ) ;
return 0 ;
}
static int F_88 ( struct V_57 * V_57 ,
struct V_85 * V_82 )
{
int V_16 ;
V_16 = F_83 ( V_57 , V_57 -> V_67 ) ;
if ( V_16 )
return V_16 ;
memcpy ( V_82 -> V_80 , V_57 -> V_64 , V_61 ) ;
F_58 ( V_57 ) ;
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
struct V_57 V_57 ;
struct V_7 V_8 ;
struct V_85 * V_86 , * V_91 ;
struct V_98 V_99 ;
T_1 V_100 ;
T_1 V_101 ;
T_1 V_73 ;
T_5 type ;
int V_16 = 0 ;
F_97 ( & V_99 ) ;
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
V_100 = F_98 ( V_15 , V_13 ) ;
V_101 = F_99 ( V_15 , V_13 ) ;
V_73 = F_100 ( V_15 , V_13 ) ;
F_4 ( V_5 ) ;
if ( ! F_18 ( V_1 ) -> V_73 ) {
F_19 ( V_3 -> V_22 ,
L_7 ,
V_6 ) ;
return 0 ;
}
if ( F_18 ( V_1 ) -> V_73 != V_73 ) {
F_72 ( V_3 -> V_22 ,
L_8
L_9 ,
F_18 ( V_1 ) -> V_73 , V_73 ) ;
return 0 ;
}
if ( ! V_100 )
return 0 ;
V_16 = F_54 ( & V_57 , V_1 , V_3 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_48 ( V_1 ) ;
if ( V_16 )
goto V_102;
V_16 = F_66 ( & V_57 , V_1 , 1 ) ;
if ( V_16 )
goto V_102;
V_16 = F_83 ( & V_57 , 0 ) ;
if ( V_16 )
goto V_103;
V_16 = F_77 ( & V_57 , V_73 ) ;
if ( V_16 )
goto V_103;
while ( V_100 ) {
V_86 = F_101 ( V_97 ,
V_54 ) ;
if ( ! V_86 )
goto V_103;
V_16 = F_87 ( & V_57 , V_86 , & type ) ;
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
F_72 ( V_3 -> V_22 ,
L_10 ) ;
F_94 ( V_97 , V_86 ) ;
goto V_103;
}
} else {
ASSERT ( V_101 ) ;
V_101 -- ;
V_86 -> V_80 = F_49 ( V_61 , V_54 ) ;
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
F_72 ( V_3 -> V_22 ,
L_10 ) ;
F_94 ( V_97 , V_86 ) ;
goto V_103;
}
F_102 ( & V_86 -> V_107 , & V_99 ) ;
}
V_100 -- ;
}
F_58 ( & V_57 ) ;
F_103 (e, n, &bitmaps, list) {
F_104 ( & V_86 -> V_107 ) ;
V_16 = F_88 ( & V_57 , V_86 ) ;
if ( V_16 )
goto V_103;
}
F_62 ( & V_57 ) ;
F_89 ( V_88 ) ;
V_16 = 1 ;
V_102:
F_57 ( & V_57 ) ;
return V_16 ;
V_103:
F_62 ( & V_57 ) ;
F_105 ( V_88 ) ;
goto V_102;
}
int F_106 ( struct V_108 * V_22 ,
struct V_26 * V_27 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_2 * V_3 = V_22 -> V_110 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
int V_16 = 0 ;
bool V_111 ;
T_1 V_112 = F_107 ( & V_27 -> V_113 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 != V_114 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_5 = F_108 () ;
if ( ! V_5 )
return 0 ;
V_5 -> V_115 = 1 ;
V_5 -> V_116 = 1 ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) ) {
F_109 ( V_5 ) ;
return 0 ;
}
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 != V_114 ) {
F_17 ( & V_27 -> V_31 ) ;
F_109 ( V_5 ) ;
goto V_102;
}
F_17 ( & V_27 -> V_31 ) ;
V_16 = F_96 ( V_22 -> V_110 , V_1 , V_88 ,
V_5 , V_27 -> V_8 . V_17 ) ;
F_109 ( V_5 ) ;
if ( V_16 <= 0 )
goto V_102;
F_15 ( & V_88 -> V_93 ) ;
V_111 = ( V_88 -> V_117 == ( V_27 -> V_8 . V_6 - V_112 -
V_27 -> V_118 ) ) ;
F_17 ( & V_88 -> V_93 ) ;
if ( ! V_111 ) {
F_105 ( V_88 ) ;
F_110 ( V_22 , L_11 ,
V_27 -> V_8 . V_17 ) ;
V_16 = - 1 ;
}
V_102:
if ( V_16 < 0 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_32 = V_33 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
F_110 ( V_22 , L_12 ,
V_27 -> V_8 . V_17 ) ;
}
F_11 ( V_1 ) ;
return V_16 ;
}
static T_6
int F_111 ( struct V_57 * V_57 ,
struct V_87 * V_88 ,
struct V_26 * V_27 ,
int * V_119 , int * V_99 ,
struct V_98 * V_120 )
{
int V_16 ;
struct V_121 * V_122 = NULL ;
struct V_90 * V_123 = F_90 ( & V_88 -> V_94 ) ;
if ( V_27 && ! F_112 ( & V_27 -> V_124 ) ) {
V_122 = F_113 ( V_27 -> V_124 . V_96 ,
struct V_121 ,
V_125 ) ;
}
if ( ! V_123 && V_122 ) {
V_123 = F_90 ( & V_122 -> V_3 ) ;
V_122 = NULL ;
}
while ( V_123 ) {
struct V_85 * V_86 ;
V_86 = F_92 ( V_123 , struct V_85 , V_95 ) ;
* V_119 += 1 ;
V_16 = F_84 ( V_57 , V_86 -> V_6 , V_86 -> V_79 ,
V_86 -> V_80 ) ;
if ( V_16 )
goto V_126;
if ( V_86 -> V_80 ) {
F_102 ( & V_86 -> V_107 , V_120 ) ;
* V_99 += 1 ;
}
V_123 = F_91 ( V_123 ) ;
if ( ! V_123 && V_122 ) {
V_123 = F_90 ( & V_122 -> V_3 ) ;
V_122 = NULL ;
}
}
return 0 ;
V_126:
return - V_49 ;
}
static T_6 int
F_114 ( struct V_35 * V_36 ,
struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_4 * V_5 , T_1 V_6 ,
int V_119 , int V_99 )
{
struct V_7 V_8 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
V_8 . V_17 = V_18 ;
V_8 . V_6 = V_6 ;
V_8 . type = 0 ;
V_16 = F_2 ( V_36 , V_3 , & V_8 , V_5 , 0 , 1 ) ;
if ( V_16 < 0 ) {
F_115 ( & F_18 ( V_1 ) -> V_127 , 0 , V_1 -> V_128 - 1 ,
V_129 | V_130 , 0 , 0 , NULL ,
V_54 ) ;
goto V_126;
}
V_15 = V_5 -> V_20 [ 0 ] ;
if ( V_16 > 0 ) {
struct V_7 V_131 ;
ASSERT ( V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_21 [ 0 ] -- ;
F_116 ( V_15 , & V_131 , V_5 -> V_21 [ 0 ] ) ;
if ( V_131 . V_17 != V_18 ||
V_131 . V_6 != V_6 ) {
F_115 ( & F_18 ( V_1 ) -> V_127 , 0 ,
V_1 -> V_128 - 1 ,
V_129 | V_130 , 0 , 0 ,
NULL , V_54 ) ;
F_4 ( V_5 ) ;
goto V_126;
}
}
F_18 ( V_1 ) -> V_73 = V_36 -> V_43 ;
V_13 = F_5 ( V_15 , V_5 -> V_21 [ 0 ] ,
struct V_12 ) ;
F_117 ( V_15 , V_13 , V_119 ) ;
F_118 ( V_15 , V_13 , V_99 ) ;
F_119 ( V_15 , V_13 , V_36 -> V_43 ) ;
F_34 ( V_15 ) ;
F_4 ( V_5 ) ;
return 0 ;
V_126:
return - 1 ;
}
static T_6 int
F_120 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_57 * V_57 ,
int * V_119 )
{
T_1 V_132 , V_133 , V_134 , V_135 ;
struct V_136 * V_137 = NULL ;
int V_16 ;
if ( ! V_27 )
return 0 ;
V_137 = V_3 -> V_22 -> V_138 ;
V_132 = V_27 -> V_8 . V_17 ;
while ( V_132 < V_27 -> V_8 . V_17 + V_27 -> V_8 . V_6 ) {
V_16 = F_121 ( V_137 , V_132 ,
& V_133 , & V_134 ,
V_129 , NULL ) ;
if ( V_16 )
return 0 ;
if ( V_133 >= V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 )
return 0 ;
V_133 = F_122 ( V_133 , V_132 ) ;
V_134 = F_123 ( V_27 -> V_8 . V_17 +
V_27 -> V_8 . V_6 , V_134 + 1 ) ;
V_135 = V_134 - V_133 ;
* V_119 += 1 ;
V_16 = F_84 ( V_57 , V_133 , V_135 , NULL ) ;
if ( V_16 )
return - V_49 ;
V_132 = V_134 ;
}
return 0 ;
}
static T_6 int
F_124 ( struct V_57 * V_57 , struct V_98 * V_120 )
{
struct V_98 * V_139 , * V_91 ;
int V_16 ;
F_125 (pos, n, bitmap_list) {
struct V_85 * V_82 =
F_113 ( V_139 , struct V_85 , V_107 ) ;
V_16 = F_85 ( V_57 , V_82 -> V_80 ) ;
if ( V_16 )
return - V_49 ;
F_104 ( & V_82 -> V_107 ) ;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_1 )
{
int V_16 ;
V_16 = F_127 ( V_1 , 0 , ( T_1 ) - 1 ) ;
if ( V_16 )
F_115 ( & F_18 ( V_1 ) -> V_127 , 0 , V_1 -> V_128 - 1 ,
V_129 | V_130 , 0 , 0 , NULL ,
V_54 ) ;
return V_16 ;
}
static void T_6
F_128 ( struct V_1 * V_1 ,
struct V_57 * V_57 ,
struct V_140 * * V_141 ,
struct V_98 * V_120 )
{
struct V_98 * V_139 , * V_91 ;
F_125 (pos, n, bitmap_list) {
struct V_85 * V_82 =
F_113 ( V_139 , struct V_85 , V_107 ) ;
F_104 ( & V_82 -> V_107 ) ;
}
F_62 ( V_57 ) ;
F_129 ( & F_18 ( V_1 ) -> V_127 , 0 ,
F_51 ( V_1 ) - 1 , V_141 ,
V_54 ) ;
}
static int F_130 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_87 * V_88 ,
struct V_26 * V_27 ,
struct V_35 * V_36 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_140 * V_141 = NULL ;
struct V_57 V_57 ;
F_131 ( V_120 ) ;
int V_119 = 0 ;
int V_99 = 0 ;
int V_16 ;
if ( ! F_51 ( V_1 ) )
return - 1 ;
V_16 = F_54 ( & V_57 , V_1 , V_3 , 1 ) ;
if ( V_16 )
return - 1 ;
if ( V_27 && ( V_27 -> V_28 & V_142 ) ) {
F_132 ( & V_27 -> V_143 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_144 ) {
V_27 -> V_32 = V_114 ;
F_17 ( & V_27 -> V_31 ) ;
F_133 ( & V_27 -> V_143 ) ;
F_18 ( V_1 ) -> V_73 = 0 ;
V_16 = 0 ;
goto V_102;
}
F_17 ( & V_27 -> V_31 ) ;
}
F_66 ( & V_57 , V_1 , 0 ) ;
F_134 ( & F_18 ( V_1 ) -> V_127 , 0 , F_51 ( V_1 ) - 1 ,
0 , & V_141 ) ;
F_75 ( & V_57 , V_36 -> V_43 ) ;
V_16 = F_111 ( & V_57 , V_88 ,
V_27 , & V_119 , & V_99 ,
& V_120 ) ;
if ( V_16 )
goto V_145;
V_16 = F_120 ( V_3 , V_27 , & V_57 , & V_119 ) ;
if ( V_16 )
goto V_145;
V_16 = F_124 ( & V_57 , & V_120 ) ;
if ( V_16 )
goto V_145;
F_86 ( & V_57 ) ;
V_16 = F_135 ( V_3 , V_1 , V_57 . V_62 , V_57 . V_59 ,
0 , F_51 ( V_1 ) , & V_141 ) ;
if ( V_16 )
goto V_145;
if ( V_27 && ( V_27 -> V_28 & V_142 ) )
F_133 ( & V_27 -> V_143 ) ;
F_62 ( & V_57 ) ;
F_129 ( & F_18 ( V_1 ) -> V_127 , 0 ,
F_51 ( V_1 ) - 1 , & V_141 , V_54 ) ;
V_16 = F_126 ( V_1 ) ;
if ( V_16 )
goto V_102;
V_16 = F_114 ( V_36 , V_3 , V_1 , V_5 , V_6 ,
V_119 , V_99 ) ;
V_102:
F_57 ( & V_57 ) ;
if ( V_16 ) {
F_136 ( V_1 -> V_24 ) ;
F_18 ( V_1 ) -> V_73 = 0 ;
}
F_47 ( V_36 , V_3 , V_1 ) ;
return V_16 ;
V_145:
F_128 ( V_1 , & V_57 , & V_141 , & V_120 ) ;
if ( V_27 && ( V_27 -> V_28 & V_142 ) )
F_133 ( & V_27 -> V_143 ) ;
goto V_102;
}
int F_137 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_26 * V_27 ,
struct V_4 * V_5 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
V_3 = V_3 -> V_22 -> V_110 ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_32 < V_146 ) {
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
if ( V_27 -> V_144 ) {
V_27 -> V_32 = V_114 ;
F_17 ( & V_27 -> V_31 ) ;
return 0 ;
}
F_17 ( & V_27 -> V_31 ) ;
V_1 = F_14 ( V_3 , V_27 , V_5 ) ;
if ( F_9 ( V_1 ) )
return 0 ;
V_16 = F_130 ( V_3 , V_1 , V_88 , V_27 , V_36 ,
V_5 , V_27 -> V_8 . V_17 ) ;
if ( V_16 ) {
F_15 ( & V_27 -> V_31 ) ;
V_27 -> V_32 = V_147 ;
F_17 ( & V_27 -> V_31 ) ;
V_16 = 0 ;
#ifdef F_138
F_72 ( V_3 -> V_22 ,
L_13 ,
V_27 -> V_8 . V_17 ) ;
#endif
}
F_11 ( V_1 ) ;
return V_16 ;
}
static inline unsigned long F_139 ( T_1 V_148 , T_2 V_149 ,
T_1 V_6 )
{
ASSERT ( V_6 >= V_148 ) ;
V_6 -= V_148 ;
return ( unsigned long ) ( F_140 ( V_6 , V_149 ) ) ;
}
static inline unsigned long F_141 ( T_1 V_79 , T_2 V_149 )
{
return ( unsigned long ) ( F_140 ( V_79 , V_149 ) ) ;
}
static inline T_1 F_142 ( struct V_87 * V_88 ,
T_1 V_6 )
{
T_1 V_148 ;
T_1 V_150 ;
V_150 = V_151 * V_88 -> V_149 ;
V_148 = V_6 - V_88 -> V_132 ;
V_148 = F_143 ( V_148 , V_150 ) ;
V_148 *= V_150 ;
V_148 += V_88 -> V_132 ;
return V_148 ;
}
static int F_144 ( struct V_152 * V_3 , T_1 V_6 ,
struct V_90 * V_123 , int V_80 )
{
struct V_90 * * V_153 = & V_3 -> V_90 ;
struct V_90 * V_154 = NULL ;
struct V_85 * V_155 ;
while ( * V_153 ) {
V_154 = * V_153 ;
V_155 = F_92 ( V_154 , struct V_85 , V_95 ) ;
if ( V_6 < V_155 -> V_6 ) {
V_153 = & ( * V_153 ) -> V_156 ;
} else if ( V_6 > V_155 -> V_6 ) {
V_153 = & ( * V_153 ) -> V_157 ;
} else {
if ( V_80 ) {
if ( V_155 -> V_80 ) {
F_145 ( 1 ) ;
return - V_158 ;
}
V_153 = & ( * V_153 ) -> V_157 ;
} else {
if ( ! V_155 -> V_80 ) {
F_145 ( 1 ) ;
return - V_158 ;
}
V_153 = & ( * V_153 ) -> V_156 ;
}
}
}
F_146 ( V_123 , V_154 , V_153 ) ;
F_147 ( V_123 , V_3 ) ;
return 0 ;
}
static struct V_85 *
F_148 ( struct V_87 * V_88 ,
T_1 V_6 , int V_159 , int V_160 )
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
V_91 = V_91 -> V_156 ;
else if ( V_6 > V_82 -> V_6 )
V_91 = V_91 -> V_157 ;
else
break;
}
if ( V_159 ) {
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
F_149 ( ! V_82 -> V_80 ) ;
return V_82 ;
} else if ( V_82 ) {
if ( V_82 -> V_80 ) {
V_91 = F_150 ( & V_82 -> V_95 ) ;
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
V_91 = F_150 ( & V_82 -> V_95 ) ;
if ( V_91 ) {
V_82 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
ASSERT ( V_82 -> V_6 <= V_6 ) ;
} else {
if ( V_160 )
return V_82 ;
else
return NULL ;
}
}
if ( V_82 -> V_80 ) {
V_91 = F_150 ( & V_82 -> V_95 ) ;
if ( V_91 ) {
V_89 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
if ( ! V_89 -> V_80 &&
V_89 -> V_6 + V_89 -> V_79 > V_6 )
return V_89 ;
}
if ( V_82 -> V_6 + V_151 * V_88 -> V_149 > V_6 )
return V_82 ;
} else if ( V_82 -> V_6 + V_82 -> V_79 > V_6 )
return V_82 ;
if ( ! V_160 )
return NULL ;
while ( 1 ) {
if ( V_82 -> V_80 ) {
if ( V_82 -> V_6 + V_151 *
V_88 -> V_149 > V_6 )
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
F_151 ( struct V_87 * V_88 ,
struct V_85 * V_155 )
{
F_152 ( & V_155 -> V_95 , & V_88 -> V_94 ) ;
V_88 -> V_161 -- ;
}
static void F_93 ( struct V_87 * V_88 ,
struct V_85 * V_155 )
{
F_151 ( V_88 , V_155 ) ;
V_88 -> V_117 -= V_155 -> V_79 ;
}
static int F_95 ( struct V_87 * V_88 ,
struct V_85 * V_155 )
{
int V_16 = 0 ;
ASSERT ( V_155 -> V_79 || V_155 -> V_80 ) ;
V_16 = F_144 ( & V_88 -> V_94 , V_155 -> V_6 ,
& V_155 -> V_95 , ( V_155 -> V_80 != NULL ) ) ;
if ( V_16 )
return V_16 ;
V_88 -> V_117 += V_155 -> V_79 ;
V_88 -> V_161 ++ ;
return V_16 ;
}
static void F_153 ( struct V_87 * V_88 )
{
struct V_26 * V_27 = V_88 -> V_162 ;
T_1 V_163 ;
T_1 V_164 ;
T_1 V_165 ;
T_1 V_68 = V_27 -> V_8 . V_6 ;
T_1 V_166 = V_151 * V_88 -> V_149 ;
int V_167 = F_143 ( V_68 + V_166 - 1 , V_166 ) ;
V_167 = F_122 ( V_167 , 1 ) ;
ASSERT ( V_88 -> V_104 <= V_167 ) ;
if ( V_68 < 1024 * 1024 * 1024 )
V_163 = V_168 ;
else
V_163 = V_168 *
F_143 ( V_68 , 1024 * 1024 * 1024 ) ;
V_164 = ( V_88 -> V_104 + 1 ) * V_61 ;
if ( V_164 >= V_163 ) {
V_88 -> V_169 = 0 ;
return;
}
V_165 = V_163 - V_164 ;
V_165 = F_154 ( T_1 , V_165 , F_143 ( V_163 , 2 ) ) ;
V_88 -> V_169 =
F_143 ( V_165 , ( sizeof( struct V_85 ) ) ) ;
}
static inline void F_155 ( struct V_87 * V_88 ,
struct V_85 * V_155 ,
T_1 V_6 , T_1 V_79 )
{
unsigned long V_132 , V_170 ;
V_132 = F_139 ( V_155 -> V_6 , V_88 -> V_149 , V_6 ) ;
V_170 = F_141 ( V_79 , V_88 -> V_149 ) ;
ASSERT ( V_132 + V_170 <= V_151 ) ;
F_156 ( V_155 -> V_80 , V_132 , V_170 ) ;
V_155 -> V_79 -= V_79 ;
}
static void F_157 ( struct V_87 * V_88 ,
struct V_85 * V_155 , T_1 V_6 ,
T_1 V_79 )
{
F_155 ( V_88 , V_155 , V_6 , V_79 ) ;
V_88 -> V_117 -= V_79 ;
}
static void F_158 ( struct V_87 * V_88 ,
struct V_85 * V_155 , T_1 V_6 ,
T_1 V_79 )
{
unsigned long V_132 , V_170 ;
V_132 = F_139 ( V_155 -> V_6 , V_88 -> V_149 , V_6 ) ;
V_170 = F_141 ( V_79 , V_88 -> V_149 ) ;
ASSERT ( V_132 + V_170 <= V_151 ) ;
F_159 ( V_155 -> V_80 , V_132 , V_170 ) ;
V_155 -> V_79 += V_79 ;
V_88 -> V_117 += V_79 ;
}
static int F_160 ( struct V_87 * V_88 ,
struct V_85 * V_171 , T_1 * V_6 ,
T_1 * V_79 )
{
unsigned long V_172 = 0 ;
unsigned long V_173 = 0 ;
unsigned long V_174 , V_69 ;
unsigned long V_175 ;
unsigned long V_176 ;
V_69 = F_139 ( V_171 -> V_6 , V_88 -> V_149 ,
F_161 ( T_1 , * V_6 , V_171 -> V_6 ) ) ;
V_174 = F_141 ( * V_79 , V_88 -> V_149 ) ;
F_162 (i, bitmap_info->bitmap, BITS_PER_BITMAP) {
V_175 = F_163 ( V_171 -> V_80 ,
V_151 , V_69 ) ;
V_176 = V_175 - V_69 ;
if ( V_176 >= V_174 ) {
V_172 = V_176 ;
break;
} else if ( V_176 > V_173 ) {
V_173 = V_176 ;
}
V_69 = V_175 ;
}
if ( V_172 ) {
* V_6 = ( T_1 ) ( V_69 * V_88 -> V_149 ) + V_171 -> V_6 ;
* V_79 = ( T_1 ) ( V_172 ) * V_88 -> V_149 ;
return 0 ;
}
* V_79 = ( T_1 ) ( V_173 ) * V_88 -> V_149 ;
return - 1 ;
}
static struct V_85 *
F_164 ( struct V_87 * V_88 , T_1 * V_6 , T_1 * V_79 ,
unsigned long V_177 , T_1 * V_178 )
{
struct V_85 * V_82 ;
struct V_90 * V_123 ;
T_1 V_77 ;
T_1 V_179 ;
int V_16 ;
if ( ! V_88 -> V_94 . V_90 )
goto V_102;
V_82 = F_148 ( V_88 , F_142 ( V_88 , * V_6 ) , 0 , 1 ) ;
if ( ! V_82 )
goto V_102;
for ( V_123 = & V_82 -> V_95 ; V_123 ; V_123 = F_91 ( V_123 ) ) {
V_82 = F_92 ( V_123 , struct V_85 , V_95 ) ;
if ( V_82 -> V_79 < * V_79 ) {
if ( V_82 -> V_79 > * V_178 )
* V_178 = V_82 -> V_79 ;
continue;
}
if ( * V_79 >= V_177 ) {
V_77 = V_82 -> V_6 - V_88 -> V_132 + V_177 - 1 ;
F_165 ( V_77 , V_177 ) ;
V_77 = V_77 * V_177 + V_88 -> V_132 ;
V_179 = V_77 - V_82 -> V_6 ;
} else {
V_179 = 0 ;
V_77 = V_82 -> V_6 ;
}
if ( V_82 -> V_79 < * V_79 + V_179 ) {
if ( V_82 -> V_79 > * V_178 )
* V_178 = V_82 -> V_79 ;
continue;
}
if ( V_82 -> V_80 ) {
T_1 V_68 = * V_79 ;
V_16 = F_160 ( V_88 , V_82 , & V_77 , & V_68 ) ;
if ( ! V_16 ) {
* V_6 = V_77 ;
* V_79 = V_68 ;
return V_82 ;
} else if ( V_68 > * V_178 ) {
* V_178 = V_68 ;
}
continue;
}
* V_6 = V_77 ;
* V_79 = V_82 -> V_79 - V_179 ;
return V_82 ;
}
V_102:
return NULL ;
}
static void F_166 ( struct V_87 * V_88 ,
struct V_85 * V_155 , T_1 V_6 )
{
V_155 -> V_6 = F_142 ( V_88 , V_6 ) ;
V_155 -> V_79 = 0 ;
F_97 ( & V_155 -> V_107 ) ;
F_95 ( V_88 , V_155 ) ;
V_88 -> V_104 ++ ;
V_88 -> V_105 -> V_106 ( V_88 ) ;
}
static void F_167 ( struct V_87 * V_88 ,
struct V_85 * V_171 )
{
F_93 ( V_88 , V_171 ) ;
F_53 ( V_171 -> V_80 ) ;
F_94 ( V_97 , V_171 ) ;
V_88 -> V_104 -- ;
V_88 -> V_105 -> V_106 ( V_88 ) ;
}
static T_7 int F_168 ( struct V_87 * V_88 ,
struct V_85 * V_171 ,
T_1 * V_6 , T_1 * V_79 )
{
T_1 V_180 ;
T_1 V_181 , V_182 ;
int V_16 ;
V_92:
V_180 = V_171 -> V_6 + ( T_1 ) ( V_151 * V_88 -> V_149 ) - 1 ;
V_181 = * V_6 ;
V_182 = V_88 -> V_149 ;
V_182 = F_123 ( V_182 , V_180 - V_181 + 1 ) ;
V_16 = F_160 ( V_88 , V_171 , & V_181 , & V_182 ) ;
if ( V_16 < 0 || V_181 != * V_6 )
return - V_183 ;
V_182 = F_123 ( V_182 , * V_79 ) ;
V_182 = F_123 ( V_182 , V_180 - V_181 + 1 ) ;
F_157 ( V_88 , V_171 , V_181 , V_182 ) ;
* V_6 += V_182 ;
* V_79 -= V_182 ;
if ( * V_79 ) {
struct V_90 * V_96 = F_91 ( & V_171 -> V_95 ) ;
if ( ! V_171 -> V_79 )
F_167 ( V_88 , V_171 ) ;
if ( ! V_96 )
return - V_183 ;
V_171 = F_92 ( V_96 , struct V_85 ,
V_95 ) ;
if ( ! V_171 -> V_80 )
return - V_184 ;
V_181 = * V_6 ;
V_182 = V_88 -> V_149 ;
V_16 = F_160 ( V_88 , V_171 , & V_181 ,
& V_182 ) ;
if ( V_16 < 0 || V_181 != * V_6 )
return - V_184 ;
goto V_92;
} else if ( ! V_171 -> V_79 )
F_167 ( V_88 , V_171 ) ;
return 0 ;
}
static T_1 F_169 ( struct V_87 * V_88 ,
struct V_85 * V_155 , T_1 V_6 ,
T_1 V_79 )
{
T_1 V_185 = 0 ;
T_1 V_180 ;
V_180 = V_155 -> V_6 + ( T_1 ) ( V_151 * V_88 -> V_149 ) ;
V_185 = F_123 ( V_180 - V_6 , V_79 ) ;
F_158 ( V_88 , V_155 , V_6 , V_185 ) ;
return V_185 ;
}
static bool F_170 ( struct V_87 * V_88 ,
struct V_85 * V_155 )
{
struct V_26 * V_27 = V_88 -> V_162 ;
if ( V_88 -> V_161 < V_88 -> V_169 ) {
if ( V_155 -> V_79 <= V_27 -> V_186 * 4 ) {
if ( V_88 -> V_161 * 2 <= V_88 -> V_169 )
return false ;
} else {
return false ;
}
}
if ( ( ( V_151 * V_88 -> V_149 ) >> 1 ) > V_27 -> V_8 . V_6 )
return false ;
return true ;
}
static int F_171 ( struct V_87 * V_88 ,
struct V_85 * V_155 )
{
struct V_85 * V_171 ;
struct V_26 * V_27 = NULL ;
int V_187 = 0 ;
T_1 V_79 , V_6 , V_188 ;
int V_16 ;
V_79 = V_155 -> V_79 ;
V_6 = V_155 -> V_6 ;
if ( ! V_88 -> V_105 -> F_170 ( V_88 , V_155 ) )
return 0 ;
if ( V_88 -> V_105 == & V_189 )
V_27 = V_88 -> V_162 ;
V_92:
if ( V_27 && ! F_112 ( & V_27 -> V_124 ) ) {
struct V_121 * V_122 ;
struct V_90 * V_123 ;
struct V_85 * V_82 ;
V_122 = F_113 ( V_27 -> V_124 . V_96 ,
struct V_121 ,
V_125 ) ;
F_15 ( & V_122 -> V_31 ) ;
V_123 = F_90 ( & V_122 -> V_3 ) ;
if ( ! V_123 ) {
F_17 ( & V_122 -> V_31 ) ;
goto V_190;
}
V_82 = F_92 ( V_123 , struct V_85 , V_95 ) ;
if ( ! V_82 -> V_80 ) {
F_17 ( & V_122 -> V_31 ) ;
goto V_190;
}
if ( V_82 -> V_6 == F_142 ( V_88 , V_6 ) ) {
V_188 = F_169 ( V_88 , V_82 ,
V_6 , V_79 ) ;
V_79 -= V_188 ;
V_6 += V_188 ;
}
F_17 ( & V_122 -> V_31 ) ;
if ( ! V_79 ) {
V_16 = 1 ;
goto V_102;
}
}
V_190:
V_171 = F_148 ( V_88 , F_142 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_171 ) {
ASSERT ( V_187 == 0 ) ;
goto V_191;
}
V_188 = F_169 ( V_88 , V_171 , V_6 , V_79 ) ;
V_79 -= V_188 ;
V_6 += V_188 ;
V_187 = 0 ;
if ( ! V_79 ) {
V_16 = 1 ;
goto V_102;
} else
goto V_92;
V_191:
if ( V_155 && V_155 -> V_80 ) {
F_166 ( V_88 , V_155 , V_6 ) ;
V_187 = 1 ;
V_155 = NULL ;
goto V_92;
} else {
F_17 ( & V_88 -> V_93 ) ;
if ( ! V_155 ) {
V_155 = F_101 ( V_97 ,
V_54 ) ;
if ( ! V_155 ) {
F_15 ( & V_88 -> V_93 ) ;
V_16 = - V_55 ;
goto V_102;
}
}
V_155 -> V_80 = F_49 ( V_61 , V_54 ) ;
F_15 ( & V_88 -> V_93 ) ;
if ( ! V_155 -> V_80 ) {
V_16 = - V_55 ;
goto V_102;
}
goto V_92;
}
V_102:
if ( V_155 ) {
if ( V_155 -> V_80 )
F_53 ( V_155 -> V_80 ) ;
F_94 ( V_97 , V_155 ) ;
}
return V_16 ;
}
static bool F_172 ( struct V_87 * V_88 ,
struct V_85 * V_155 , bool V_192 )
{
struct V_85 * V_193 ;
struct V_85 * V_194 ;
bool V_195 = false ;
T_1 V_6 = V_155 -> V_6 ;
T_1 V_79 = V_155 -> V_79 ;
V_194 = F_148 ( V_88 , V_6 + V_79 , 0 , 0 ) ;
if ( V_194 && F_150 ( & V_194 -> V_95 ) )
V_193 = F_92 ( F_150 ( & V_194 -> V_95 ) ,
struct V_85 , V_95 ) ;
else
V_193 = F_148 ( V_88 , V_6 - 1 , 0 , 0 ) ;
if ( V_194 && ! V_194 -> V_80 ) {
if ( V_192 )
F_93 ( V_88 , V_194 ) ;
else
F_151 ( V_88 , V_194 ) ;
V_155 -> V_79 += V_194 -> V_79 ;
F_94 ( V_97 , V_194 ) ;
V_195 = true ;
}
if ( V_193 && ! V_193 -> V_80 &&
V_193 -> V_6 + V_193 -> V_79 == V_6 ) {
if ( V_192 )
F_93 ( V_88 , V_193 ) ;
else
F_151 ( V_88 , V_193 ) ;
V_155 -> V_6 = V_193 -> V_6 ;
V_155 -> V_79 += V_193 -> V_79 ;
F_94 ( V_97 , V_193 ) ;
V_195 = true ;
}
return V_195 ;
}
static bool F_173 ( struct V_87 * V_88 ,
struct V_85 * V_155 ,
bool V_192 )
{
struct V_85 * V_80 ;
unsigned long V_69 ;
unsigned long V_196 ;
const T_1 V_180 = V_155 -> V_6 + V_155 -> V_79 ;
const T_1 V_197 = F_142 ( V_88 , V_180 ) ;
T_1 V_79 ;
V_80 = F_148 ( V_88 , V_197 , 1 , 0 ) ;
if ( ! V_80 )
return false ;
V_69 = F_139 ( V_80 -> V_6 , V_88 -> V_149 , V_180 ) ;
V_196 = F_163 ( V_80 -> V_80 , V_151 , V_69 ) ;
if ( V_196 == V_69 )
return false ;
V_79 = ( V_196 - V_69 ) * V_88 -> V_149 ;
V_155 -> V_79 += V_79 ;
if ( V_192 )
F_157 ( V_88 , V_80 , V_180 , V_79 ) ;
else
F_155 ( V_88 , V_80 , V_180 , V_79 ) ;
if ( ! V_80 -> V_79 )
F_167 ( V_88 , V_80 ) ;
return true ;
}
static bool F_174 ( struct V_87 * V_88 ,
struct V_85 * V_155 ,
bool V_192 )
{
struct V_85 * V_80 ;
T_1 V_197 ;
unsigned long V_69 ;
unsigned long V_196 ;
unsigned long V_198 ;
T_1 V_79 ;
V_197 = F_142 ( V_88 , V_155 -> V_6 ) ;
if ( V_197 == V_155 -> V_6 ) {
if ( V_155 -> V_6 == 0 )
return false ;
V_197 = F_142 ( V_88 , V_155 -> V_6 - 1 ) ;
}
V_80 = F_148 ( V_88 , V_197 , 1 , 0 ) ;
if ( ! V_80 )
return false ;
V_69 = F_139 ( V_80 -> V_6 , V_88 -> V_149 , V_155 -> V_6 ) - 1 ;
V_196 = 0 ;
V_198 = ( unsigned long ) - 1 ;
F_175 (j, bitmap->bitmap, BITS_PER_BITMAP) {
if ( V_196 > V_69 )
break;
V_198 = V_196 ;
}
if ( V_198 == V_69 )
return false ;
if ( V_198 == ( unsigned long ) - 1 )
V_79 = ( V_69 + 1 ) * V_88 -> V_149 ;
else
V_79 = ( V_69 - V_198 ) * V_88 -> V_149 ;
V_155 -> V_6 -= V_79 ;
V_155 -> V_79 += V_79 ;
if ( V_192 )
F_157 ( V_88 , V_80 , V_155 -> V_6 , V_79 ) ;
else
F_155 ( V_88 , V_80 , V_155 -> V_6 , V_79 ) ;
if ( ! V_80 -> V_79 )
F_167 ( V_88 , V_80 ) ;
return true ;
}
static void F_176 ( struct V_87 * V_88 ,
struct V_85 * V_155 ,
bool V_192 )
{
ASSERT ( ! V_155 -> V_80 ) ;
ASSERT ( F_177 ( & V_155 -> V_95 ) ) ;
if ( V_88 -> V_104 > 0 ) {
bool V_199 ;
bool V_200 = false ;
V_199 = F_173 ( V_88 , V_155 , V_192 ) ;
if ( V_88 -> V_104 > 0 )
V_200 = F_174 ( V_88 , V_155 ,
V_192 ) ;
if ( V_199 || V_200 )
F_172 ( V_88 , V_155 , V_192 ) ;
}
}
int F_178 ( struct V_87 * V_88 ,
T_1 V_6 , T_1 V_79 )
{
struct V_85 * V_155 ;
int V_16 = 0 ;
V_155 = F_101 ( V_97 , V_54 ) ;
if ( ! V_155 )
return - V_55 ;
V_155 -> V_6 = V_6 ;
V_155 -> V_79 = V_79 ;
F_179 ( & V_155 -> V_95 ) ;
F_15 ( & V_88 -> V_93 ) ;
if ( F_172 ( V_88 , V_155 , true ) )
goto V_201;
V_16 = F_171 ( V_88 , V_155 ) ;
if ( V_16 < 0 ) {
goto V_102;
} else if ( V_16 ) {
V_16 = 0 ;
goto V_102;
}
V_201:
F_176 ( V_88 , V_155 , true ) ;
V_16 = F_95 ( V_88 , V_155 ) ;
if ( V_16 )
F_94 ( V_97 , V_155 ) ;
V_102:
F_17 ( & V_88 -> V_93 ) ;
if ( V_16 ) {
F_180 ( V_202 L_14 , V_16 ) ;
ASSERT ( V_16 != - V_158 ) ;
}
return V_16 ;
}
int F_181 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_79 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_155 ;
int V_16 ;
bool V_203 = false ;
F_15 ( & V_88 -> V_93 ) ;
V_92:
V_16 = 0 ;
if ( ! V_79 )
goto V_204;
V_155 = F_148 ( V_88 , V_6 , 0 , 0 ) ;
if ( ! V_155 ) {
V_155 = F_148 ( V_88 , F_142 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_155 ) {
F_149 ( V_203 ) ;
goto V_204;
}
}
V_203 = false ;
if ( ! V_155 -> V_80 ) {
F_93 ( V_88 , V_155 ) ;
if ( V_6 == V_155 -> V_6 ) {
T_1 V_205 = F_123 ( V_79 , V_155 -> V_79 ) ;
V_155 -> V_79 -= V_205 ;
V_155 -> V_6 += V_205 ;
if ( V_155 -> V_79 ) {
V_16 = F_95 ( V_88 , V_155 ) ;
F_149 ( V_16 ) ;
} else {
F_94 ( V_97 , V_155 ) ;
}
V_6 += V_205 ;
V_79 -= V_205 ;
goto V_92;
} else {
T_1 V_206 = V_155 -> V_79 + V_155 -> V_6 ;
V_155 -> V_79 = V_6 - V_155 -> V_6 ;
V_16 = F_95 ( V_88 , V_155 ) ;
F_149 ( V_16 ) ;
if ( V_16 )
goto V_204;
if ( V_206 < V_6 + V_79 ) {
V_79 -= V_206 - V_6 ;
V_6 = V_206 ;
goto V_92;
} else if ( V_206 == V_6 + V_79 ) {
goto V_204;
}
F_17 ( & V_88 -> V_93 ) ;
V_16 = F_182 ( V_27 , V_6 + V_79 ,
V_206 - ( V_6 + V_79 ) ) ;
F_149 ( V_16 ) ;
goto V_102;
}
}
V_16 = F_168 ( V_88 , V_155 , & V_6 , & V_79 ) ;
if ( V_16 == - V_184 ) {
V_203 = true ;
goto V_92;
}
V_204:
F_17 ( & V_88 -> V_93 ) ;
V_102:
return V_16 ;
}
void F_183 ( struct V_26 * V_27 ,
T_1 V_79 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_155 ;
struct V_90 * V_91 ;
int V_170 = 0 ;
for ( V_91 = F_90 ( & V_88 -> V_94 ) ; V_91 ; V_91 = F_91 ( V_91 ) ) {
V_155 = F_92 ( V_91 , struct V_85 , V_95 ) ;
if ( V_155 -> V_79 >= V_79 && ! V_27 -> V_207 )
V_170 ++ ;
F_184 ( V_27 -> V_22 ,
L_15 ,
V_155 -> V_6 , V_155 -> V_79 ,
( V_155 -> V_80 ) ? L_16 : L_17 ) ;
}
F_19 ( V_27 -> V_22 , L_18 ,
F_112 ( & V_27 -> V_124 ) ? L_17 : L_16 ) ;
F_19 ( V_27 -> V_22 ,
L_19 , V_170 ) ;
}
void F_185 ( struct V_26 * V_27 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
F_186 ( & V_88 -> V_93 ) ;
V_88 -> V_149 = V_27 -> V_186 ;
V_88 -> V_132 = V_27 -> V_8 . V_17 ;
V_88 -> V_162 = V_27 ;
V_88 -> V_105 = & V_189 ;
V_88 -> V_169 = ( ( 1024 * 32 ) / 2 ) /
sizeof( struct V_85 ) ;
}
static int
F_187 (
struct V_26 * V_27 ,
struct V_121 * V_122 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
struct V_90 * V_123 ;
F_15 ( & V_122 -> V_31 ) ;
if ( V_122 -> V_27 != V_27 )
goto V_102;
V_122 -> V_27 = NULL ;
V_122 -> V_208 = 0 ;
F_104 ( & V_122 -> V_125 ) ;
V_123 = F_90 ( & V_122 -> V_3 ) ;
while ( V_123 ) {
bool V_80 ;
V_82 = F_92 ( V_123 , struct V_85 , V_95 ) ;
V_123 = F_91 ( & V_82 -> V_95 ) ;
F_152 ( & V_82 -> V_95 , & V_122 -> V_3 ) ;
F_179 ( & V_82 -> V_95 ) ;
V_80 = ( V_82 -> V_80 != NULL ) ;
if ( ! V_80 ) {
F_172 ( V_88 , V_82 , false ) ;
F_176 ( V_88 , V_82 , false ) ;
}
F_144 ( & V_88 -> V_94 ,
V_82 -> V_6 , & V_82 -> V_95 , V_80 ) ;
}
V_122 -> V_3 = V_209 ;
V_102:
F_17 ( & V_122 -> V_31 ) ;
F_188 ( V_27 ) ;
return 0 ;
}
static void F_189 (
struct V_87 * V_88 )
{
struct V_85 * V_155 ;
struct V_90 * V_123 ;
while ( ( V_123 = F_190 ( & V_88 -> V_94 ) ) != NULL ) {
V_155 = F_92 ( V_123 , struct V_85 , V_95 ) ;
if ( ! V_155 -> V_80 ) {
F_93 ( V_88 , V_155 ) ;
F_94 ( V_97 , V_155 ) ;
} else {
F_167 ( V_88 , V_155 ) ;
}
if ( F_191 () ) {
F_17 ( & V_88 -> V_93 ) ;
F_192 () ;
F_15 ( & V_88 -> V_93 ) ;
}
}
}
void F_105 ( struct V_87 * V_88 )
{
F_15 ( & V_88 -> V_93 ) ;
F_189 ( V_88 ) ;
F_17 ( & V_88 -> V_93 ) ;
}
void F_193 ( struct V_26 * V_27 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_121 * V_122 ;
struct V_98 * V_210 ;
F_15 ( & V_88 -> V_93 ) ;
while ( ( V_210 = V_27 -> V_124 . V_96 ) !=
& V_27 -> V_124 ) {
V_122 = F_113 ( V_210 , struct V_121 ,
V_125 ) ;
F_149 ( V_122 -> V_27 != V_27 ) ;
F_187 ( V_27 , V_122 ) ;
if ( F_191 () ) {
F_17 ( & V_88 -> V_93 ) ;
F_192 () ;
F_15 ( & V_88 -> V_93 ) ;
}
}
F_189 ( V_88 ) ;
F_17 ( & V_88 -> V_93 ) ;
}
T_1 F_194 ( struct V_26 * V_27 ,
T_1 V_6 , T_1 V_79 , T_1 V_211 ,
T_1 * V_178 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 = NULL ;
T_1 V_212 = V_79 + V_211 ;
T_1 V_16 = 0 ;
T_1 V_213 = 0 ;
T_1 V_214 = 0 ;
F_15 ( & V_88 -> V_93 ) ;
V_82 = F_164 ( V_88 , & V_6 , & V_212 ,
V_27 -> V_215 , V_178 ) ;
if ( ! V_82 )
goto V_102;
V_16 = V_6 ;
if ( V_82 -> V_80 ) {
F_157 ( V_88 , V_82 , V_6 , V_79 ) ;
if ( ! V_82 -> V_79 )
F_167 ( V_88 , V_82 ) ;
} else {
F_93 ( V_88 , V_82 ) ;
V_214 = V_6 - V_82 -> V_6 ;
V_213 = V_82 -> V_6 ;
V_82 -> V_6 = V_6 + V_79 ;
F_149 ( V_82 -> V_79 < V_79 + V_214 ) ;
V_82 -> V_79 -= V_79 + V_214 ;
if ( ! V_82 -> V_79 )
F_94 ( V_97 , V_82 ) ;
else
F_95 ( V_88 , V_82 ) ;
}
V_102:
F_17 ( & V_88 -> V_93 ) ;
if ( V_214 )
F_178 ( V_88 , V_213 , V_214 ) ;
return V_16 ;
}
int F_195 (
struct V_26 * V_27 ,
struct V_121 * V_122 )
{
struct V_87 * V_88 ;
int V_16 ;
F_15 ( & V_122 -> V_31 ) ;
if ( ! V_27 ) {
V_27 = V_122 -> V_27 ;
if ( ! V_27 ) {
F_17 ( & V_122 -> V_31 ) ;
return 0 ;
}
} else if ( V_122 -> V_27 != V_27 ) {
F_17 ( & V_122 -> V_31 ) ;
return 0 ;
}
F_196 ( & V_27 -> V_170 ) ;
F_17 ( & V_122 -> V_31 ) ;
V_88 = V_27 -> V_109 ;
F_15 ( & V_88 -> V_93 ) ;
V_16 = F_187 ( V_27 , V_122 ) ;
F_17 ( & V_88 -> V_93 ) ;
F_188 ( V_27 ) ;
return V_16 ;
}
static T_1 F_197 ( struct V_26 * V_27 ,
struct V_121 * V_122 ,
struct V_85 * V_82 ,
T_1 V_79 , T_1 V_216 ,
T_1 * V_178 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
int V_217 ;
T_1 V_181 = V_122 -> V_208 ;
T_1 V_182 = V_79 ;
T_1 V_16 = 0 ;
V_181 = V_216 ;
V_182 = V_79 ;
V_217 = F_160 ( V_88 , V_82 , & V_181 , & V_182 ) ;
if ( V_217 ) {
if ( V_182 > * V_178 )
* V_178 = V_182 ;
return 0 ;
}
V_16 = V_181 ;
F_155 ( V_88 , V_82 , V_16 , V_79 ) ;
return V_16 ;
}
T_1 F_198 ( struct V_26 * V_27 ,
struct V_121 * V_122 , T_1 V_79 ,
T_1 V_216 , T_1 * V_178 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 = NULL ;
struct V_90 * V_123 ;
T_1 V_16 = 0 ;
F_15 ( & V_122 -> V_31 ) ;
if ( V_79 > V_122 -> V_218 )
goto V_102;
if ( V_122 -> V_27 != V_27 )
goto V_102;
V_123 = F_90 ( & V_122 -> V_3 ) ;
if ( ! V_123 )
goto V_102;
V_82 = F_92 ( V_123 , struct V_85 , V_95 ) ;
while ( 1 ) {
if ( V_82 -> V_79 < V_79 && V_82 -> V_79 > * V_178 )
* V_178 = V_82 -> V_79 ;
if ( V_82 -> V_79 < V_79 ||
( ! V_82 -> V_80 && V_82 -> V_6 < V_216 ) ) {
V_123 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_123 )
break;
V_82 = F_92 ( V_123 , struct V_85 ,
V_95 ) ;
continue;
}
if ( V_82 -> V_80 ) {
V_16 = F_197 ( V_27 ,
V_122 , V_82 , V_79 ,
V_122 -> V_208 ,
V_178 ) ;
if ( V_16 == 0 ) {
V_123 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_123 )
break;
V_82 = F_92 ( V_123 , struct V_85 ,
V_95 ) ;
continue;
}
V_122 -> V_208 += V_79 ;
} else {
V_16 = V_82 -> V_6 ;
V_82 -> V_6 += V_79 ;
V_82 -> V_79 -= V_79 ;
}
if ( V_82 -> V_79 == 0 )
F_152 ( & V_82 -> V_95 , & V_122 -> V_3 ) ;
break;
}
V_102:
F_17 ( & V_122 -> V_31 ) ;
if ( ! V_16 )
return 0 ;
F_15 ( & V_88 -> V_93 ) ;
V_88 -> V_117 -= V_79 ;
if ( V_82 -> V_79 == 0 ) {
V_88 -> V_161 -- ;
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
static int F_199 ( struct V_26 * V_27 ,
struct V_85 * V_82 ,
struct V_121 * V_122 ,
T_1 V_6 , T_1 V_79 ,
T_1 V_219 , T_1 V_220 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
unsigned long V_175 ;
unsigned long V_69 ;
unsigned long V_221 ;
unsigned long V_222 ;
unsigned long V_172 ;
unsigned long V_132 = 0 ;
unsigned long V_223 = 0 ;
int V_16 ;
V_69 = F_139 ( V_82 -> V_6 , V_88 -> V_149 ,
F_161 ( T_1 , V_6 , V_82 -> V_6 ) ) ;
V_221 = F_141 ( V_79 , V_88 -> V_149 ) ;
V_222 = F_141 ( V_220 , V_88 -> V_149 ) ;
V_92:
V_172 = 0 ;
F_162 (i, entry->bitmap, BITS_PER_BITMAP) {
V_175 = F_163 ( V_82 -> V_80 ,
V_151 , V_69 ) ;
if ( V_175 - V_69 >= V_222 ) {
V_172 = V_175 - V_69 ;
break;
}
V_69 = V_175 ;
}
if ( ! V_172 )
return - V_49 ;
if ( ! V_223 ) {
V_132 = V_69 ;
V_122 -> V_218 = 0 ;
}
V_223 += V_172 ;
if ( V_122 -> V_218 < V_172 * V_88 -> V_149 )
V_122 -> V_218 = V_172 * V_88 -> V_149 ;
if ( V_223 < V_221 || V_122 -> V_218 < V_219 ) {
V_69 = V_175 + 1 ;
goto V_92;
}
V_122 -> V_208 = V_132 * V_88 -> V_149 + V_82 -> V_6 ;
F_152 ( & V_82 -> V_95 , & V_88 -> V_94 ) ;
V_16 = F_144 ( & V_122 -> V_3 , V_82 -> V_6 ,
& V_82 -> V_95 , 1 ) ;
ASSERT ( ! V_16 ) ;
F_200 ( V_27 , V_122 ,
V_223 * V_88 -> V_149 , 1 ) ;
return 0 ;
}
static T_7 int
F_201 ( struct V_26 * V_27 ,
struct V_121 * V_122 ,
struct V_98 * V_99 , T_1 V_6 , T_1 V_79 ,
T_1 V_219 , T_1 V_220 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_224 = NULL ;
struct V_85 * V_82 = NULL ;
struct V_85 * V_225 ;
struct V_90 * V_123 ;
T_1 V_226 ;
T_1 V_227 ;
T_1 V_228 = 0 ;
V_82 = F_148 ( V_88 , V_6 , 0 , 1 ) ;
if ( ! V_82 )
return - V_49 ;
while ( V_82 -> V_80 || V_82 -> V_79 < V_220 ) {
if ( V_82 -> V_80 && F_112 ( & V_82 -> V_107 ) )
F_102 ( & V_82 -> V_107 , V_99 ) ;
V_123 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_123 )
return - V_49 ;
V_82 = F_92 ( V_123 , struct V_85 , V_95 ) ;
}
V_226 = V_82 -> V_79 ;
V_227 = V_82 -> V_79 ;
V_224 = V_82 ;
V_225 = V_82 ;
for ( V_123 = F_91 ( & V_82 -> V_95 ) ; V_123 ;
V_123 = F_91 ( & V_82 -> V_95 ) ) {
V_82 = F_92 ( V_123 , struct V_85 , V_95 ) ;
if ( V_82 -> V_80 ) {
if ( F_112 ( & V_82 -> V_107 ) )
F_102 ( & V_82 -> V_107 , V_99 ) ;
continue;
}
if ( V_82 -> V_79 < V_220 )
continue;
V_225 = V_82 ;
V_226 += V_82 -> V_79 ;
if ( V_82 -> V_79 > V_227 )
V_227 = V_82 -> V_79 ;
}
if ( V_226 < V_79 || V_227 < V_219 )
return - V_49 ;
V_122 -> V_208 = V_224 -> V_6 ;
V_123 = & V_224 -> V_95 ;
do {
int V_16 ;
V_82 = F_92 ( V_123 , struct V_85 , V_95 ) ;
V_123 = F_91 ( & V_82 -> V_95 ) ;
if ( V_82 -> V_80 || V_82 -> V_79 < V_220 )
continue;
F_152 ( & V_82 -> V_95 , & V_88 -> V_94 ) ;
V_16 = F_144 ( & V_122 -> V_3 , V_82 -> V_6 ,
& V_82 -> V_95 , 0 ) ;
V_228 += V_82 -> V_79 ;
ASSERT ( ! V_16 ) ;
} while ( V_123 && V_82 != V_225 );
V_122 -> V_218 = V_227 ;
F_200 ( V_27 , V_122 , V_228 , 0 ) ;
return 0 ;
}
static T_7 int
F_202 ( struct V_26 * V_27 ,
struct V_121 * V_122 ,
struct V_98 * V_99 , T_1 V_6 , T_1 V_79 ,
T_1 V_219 , T_1 V_220 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
int V_16 = - V_49 ;
T_1 V_197 = F_142 ( V_88 , V_6 ) ;
if ( V_88 -> V_104 == 0 )
return - V_49 ;
V_82 = F_203 ( V_99 , struct V_85 , V_107 ) ;
if ( V_82 -> V_6 != V_197 ) {
V_82 = F_148 ( V_88 , V_197 , 1 , 0 ) ;
if ( V_82 && F_112 ( & V_82 -> V_107 ) )
F_204 ( & V_82 -> V_107 , V_99 ) ;
}
F_205 (entry, bitmaps, list) {
if ( V_82 -> V_79 < V_79 )
continue;
V_16 = F_199 ( V_27 , V_82 , V_122 , V_6 ,
V_79 , V_219 , V_220 ) ;
if ( ! V_16 )
return 0 ;
}
return - V_49 ;
}
int F_206 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
struct V_121 * V_122 ,
T_1 V_6 , T_1 V_79 , T_1 V_211 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 , * V_77 ;
F_131 ( V_99 ) ;
T_1 V_220 ;
T_1 V_219 ;
int V_16 ;
if ( F_207 ( V_3 , V_229 ) ) {
V_219 = V_220 = V_79 + V_211 ;
} else if ( V_27 -> V_28 & V_230 ) {
V_219 = V_79 ;
V_220 = V_27 -> V_186 ;
} else {
V_219 = F_122 ( V_79 , ( V_79 + V_211 ) >> 2 ) ;
V_220 = V_27 -> V_186 ;
}
F_15 ( & V_88 -> V_93 ) ;
if ( V_88 -> V_117 < V_79 ) {
F_17 ( & V_88 -> V_93 ) ;
return - V_49 ;
}
F_15 ( & V_122 -> V_31 ) ;
if ( V_122 -> V_27 ) {
V_16 = 0 ;
goto V_102;
}
F_208 ( V_27 , V_6 , V_79 , V_211 ,
V_220 ) ;
F_97 ( & V_99 ) ;
V_16 = F_201 ( V_27 , V_122 , & V_99 , V_6 ,
V_79 + V_211 ,
V_219 , V_220 ) ;
if ( V_16 )
V_16 = F_202 ( V_27 , V_122 , & V_99 ,
V_6 , V_79 + V_211 ,
V_219 , V_220 ) ;
F_103 (entry, tmp, &bitmaps, list)
F_104 ( & V_82 -> V_107 ) ;
if ( ! V_16 ) {
F_196 ( & V_27 -> V_170 ) ;
F_102 ( & V_122 -> V_125 ,
& V_27 -> V_124 ) ;
V_122 -> V_27 = V_27 ;
} else {
F_209 ( V_27 ) ;
}
V_102:
F_17 ( & V_122 -> V_31 ) ;
F_17 ( & V_88 -> V_93 ) ;
return V_16 ;
}
void F_210 ( struct V_121 * V_122 )
{
F_186 ( & V_122 -> V_31 ) ;
F_186 ( & V_122 -> V_231 ) ;
V_122 -> V_3 = V_209 ;
V_122 -> V_218 = 0 ;
F_97 ( & V_122 -> V_125 ) ;
V_122 -> V_27 = NULL ;
}
static int F_211 ( struct V_26 * V_27 ,
T_1 * V_232 , T_1 V_132 , T_1 V_79 ,
T_1 V_233 , T_1 V_234 )
{
struct V_235 * V_236 = V_27 -> V_236 ;
struct V_108 * V_22 = V_27 -> V_22 ;
int V_16 ;
int V_237 = 0 ;
T_1 V_238 = 0 ;
F_15 ( & V_236 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( ! V_27 -> V_207 ) {
V_27 -> V_48 += V_234 ;
V_236 -> V_239 += V_234 ;
V_237 = 1 ;
}
F_17 ( & V_27 -> V_31 ) ;
F_17 ( & V_236 -> V_31 ) ;
V_16 = F_212 ( V_22 -> V_240 ,
V_132 , V_79 , & V_238 ) ;
if ( ! V_16 )
* V_232 += V_238 ;
F_182 ( V_27 , V_233 , V_234 ) ;
if ( V_237 ) {
F_15 ( & V_236 -> V_31 ) ;
F_15 ( & V_27 -> V_31 ) ;
if ( V_27 -> V_207 )
V_236 -> V_241 += V_234 ;
V_27 -> V_48 -= V_234 ;
V_236 -> V_239 -= V_234 ;
F_17 ( & V_236 -> V_31 ) ;
F_17 ( & V_27 -> V_31 ) ;
}
return V_16 ;
}
static int F_213 ( struct V_26 * V_27 ,
T_1 * V_232 , T_1 V_132 , T_1 V_180 , T_1 V_242 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
struct V_90 * V_123 ;
int V_16 = 0 ;
T_1 V_133 ;
T_1 V_165 ;
T_1 V_79 ;
while ( V_132 < V_180 ) {
F_15 ( & V_88 -> V_93 ) ;
if ( V_88 -> V_117 < V_242 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
V_82 = F_148 ( V_88 , V_132 , 0 , 1 ) ;
if ( ! V_82 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
while ( V_82 -> V_80 ) {
V_123 = F_91 ( & V_82 -> V_95 ) ;
if ( ! V_123 ) {
F_17 ( & V_88 -> V_93 ) ;
goto V_102;
}
V_82 = F_92 ( V_123 , struct V_85 ,
V_95 ) ;
}
if ( V_82 -> V_6 >= V_180 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
V_133 = V_82 -> V_6 ;
V_165 = V_82 -> V_79 ;
V_132 = F_122 ( V_132 , V_133 ) ;
V_79 = F_123 ( V_133 + V_165 , V_180 ) - V_132 ;
if ( V_79 < V_242 ) {
F_17 ( & V_88 -> V_93 ) ;
goto V_96;
}
F_93 ( V_88 , V_82 ) ;
F_94 ( V_97 , V_82 ) ;
F_17 ( & V_88 -> V_93 ) ;
V_16 = F_211 ( V_27 , V_232 , V_132 , V_79 ,
V_133 , V_165 ) ;
if ( V_16 )
break;
V_96:
V_132 += V_79 ;
if ( F_214 ( V_243 ) ) {
V_16 = - V_244 ;
break;
}
F_192 () ;
}
V_102:
return V_16 ;
}
static int F_215 ( struct V_26 * V_27 ,
T_1 * V_232 , T_1 V_132 , T_1 V_180 , T_1 V_242 )
{
struct V_87 * V_88 = V_27 -> V_109 ;
struct V_85 * V_82 ;
int V_16 = 0 ;
int V_245 ;
T_1 V_79 ;
T_1 V_6 = F_142 ( V_88 , V_132 ) ;
while ( V_6 < V_180 ) {
bool V_246 = false ;
F_15 ( & V_88 -> V_93 ) ;
if ( V_88 -> V_117 < V_242 ) {
F_17 ( & V_88 -> V_93 ) ;
break;
}
V_82 = F_148 ( V_88 , V_6 , 1 , 0 ) ;
if ( ! V_82 ) {
F_17 ( & V_88 -> V_93 ) ;
V_246 = true ;
goto V_96;
}
V_79 = V_242 ;
V_245 = F_160 ( V_88 , V_82 , & V_132 , & V_79 ) ;
if ( V_245 || V_132 >= V_180 ) {
F_17 ( & V_88 -> V_93 ) ;
V_246 = true ;
goto V_96;
}
V_79 = F_123 ( V_79 , V_180 - V_132 ) ;
if ( V_79 < V_242 ) {
F_17 ( & V_88 -> V_93 ) ;
goto V_96;
}
F_157 ( V_88 , V_82 , V_132 , V_79 ) ;
if ( V_82 -> V_79 == 0 )
F_167 ( V_88 , V_82 ) ;
F_17 ( & V_88 -> V_93 ) ;
V_16 = F_211 ( V_27 , V_232 , V_132 , V_79 ,
V_132 , V_79 ) ;
if ( V_16 )
break;
V_96:
if ( V_246 ) {
V_6 += V_151 * V_88 -> V_149 ;
} else {
V_132 += V_79 ;
if ( V_132 >= V_6 + V_151 * V_88 -> V_149 )
V_6 += V_151 * V_88 -> V_149 ;
}
if ( F_214 ( V_243 ) ) {
V_16 = - V_244 ;
break;
}
F_192 () ;
}
return V_16 ;
}
int F_216 ( struct V_26 * V_27 ,
T_1 * V_238 , T_1 V_132 , T_1 V_180 , T_1 V_242 )
{
int V_16 ;
* V_238 = 0 ;
V_16 = F_213 ( V_27 , V_238 , V_132 , V_180 , V_242 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_215 ( V_27 , V_238 , V_132 , V_180 , V_242 ) ;
return V_16 ;
}
T_1 F_217 ( struct V_2 * V_247 )
{
struct V_87 * V_88 = V_247 -> V_248 ;
struct V_85 * V_82 = NULL ;
T_1 V_37 = 0 ;
F_15 ( & V_88 -> V_93 ) ;
if ( F_218 ( & V_88 -> V_94 ) )
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
T_1 V_170 = 1 ;
int V_16 ;
V_16 = F_160 ( V_88 , V_82 , & V_6 , & V_170 ) ;
ASSERT ( ! V_16 ) ;
V_37 = V_6 ;
F_157 ( V_88 , V_82 , V_6 , 1 ) ;
if ( V_82 -> V_79 == 0 )
F_167 ( V_88 , V_82 ) ;
}
V_102:
F_17 ( & V_88 -> V_93 ) ;
return V_37 ;
}
struct V_1 * F_219 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = NULL ;
F_15 ( & V_3 -> V_249 ) ;
if ( V_3 -> V_250 )
V_1 = F_16 ( V_3 -> V_250 ) ;
F_17 ( & V_3 -> V_249 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 ( V_3 , V_5 , 0 ) ;
if ( F_9 ( V_1 ) )
return V_1 ;
F_15 ( & V_3 -> V_249 ) ;
if ( ! F_220 ( V_3 -> V_22 ) )
V_3 -> V_250 = F_16 ( V_1 ) ;
F_17 ( & V_3 -> V_249 ) ;
return V_1 ;
}
int F_221 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 )
{
return F_20 ( V_3 , V_36 , V_5 ,
V_42 , 0 ) ;
}
int F_222 ( struct V_108 * V_22 , struct V_2 * V_3 )
{
struct V_87 * V_88 = V_3 -> V_248 ;
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_16 = 0 ;
T_1 V_251 = F_223 ( & V_3 -> V_252 ) ;
if ( ! F_207 ( V_3 , V_253 ) )
return 0 ;
if ( F_220 ( V_22 ) )
return 0 ;
V_5 = F_108 () ;
if ( ! V_5 )
return 0 ;
V_1 = F_219 ( V_3 , V_5 ) ;
if ( F_9 ( V_1 ) )
goto V_102;
if ( V_251 != F_18 ( V_1 ) -> V_73 )
goto V_254;
V_16 = F_96 ( V_3 , V_1 , V_88 , V_5 , 0 ) ;
if ( V_16 < 0 )
F_72 ( V_22 ,
L_20 ,
V_3 -> V_255 . V_17 ) ;
V_254:
F_11 ( V_1 ) ;
V_102:
F_109 ( V_5 ) ;
return V_16 ;
}
int F_224 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_87 * V_88 = V_3 -> V_248 ;
int V_16 ;
if ( ! F_207 ( V_3 , V_253 ) )
return 0 ;
V_16 = F_130 ( V_3 , V_1 , V_88 , NULL , V_36 , V_5 , 0 ) ;
if ( V_16 ) {
F_225 ( V_1 , V_1 -> V_128 ) ;
#ifdef F_138
F_72 ( V_3 -> V_22 ,
L_21 ,
V_3 -> V_255 . V_17 ) ;
#endif
}
return V_16 ;
}
int F_226 ( struct V_26 * V_256 ,
T_1 V_6 , T_1 V_79 , bool V_80 )
{
struct V_87 * V_88 = V_256 -> V_109 ;
struct V_85 * V_155 = NULL , * V_171 ;
void * V_257 = NULL ;
T_1 V_188 ;
int V_16 ;
V_92:
if ( ! V_155 ) {
V_155 = F_101 ( V_97 , V_54 ) ;
if ( ! V_155 )
return - V_55 ;
}
if ( ! V_80 ) {
F_15 ( & V_88 -> V_93 ) ;
V_155 -> V_6 = V_6 ;
V_155 -> V_79 = V_79 ;
V_16 = F_95 ( V_88 , V_155 ) ;
F_17 ( & V_88 -> V_93 ) ;
if ( V_16 )
F_94 ( V_97 , V_155 ) ;
return V_16 ;
}
if ( ! V_257 ) {
V_257 = F_49 ( V_61 , V_54 ) ;
if ( ! V_257 ) {
F_94 ( V_97 , V_155 ) ;
return - V_55 ;
}
}
F_15 ( & V_88 -> V_93 ) ;
V_171 = F_148 ( V_88 , F_142 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_171 ) {
V_155 -> V_80 = V_257 ;
V_257 = NULL ;
F_166 ( V_88 , V_155 , V_6 ) ;
V_171 = V_155 ;
V_155 = NULL ;
}
V_188 = F_169 ( V_88 , V_171 , V_6 , V_79 ) ;
V_79 -= V_188 ;
V_6 += V_188 ;
F_17 ( & V_88 -> V_93 ) ;
if ( V_79 )
goto V_92;
if ( V_155 )
F_94 ( V_97 , V_155 ) ;
if ( V_257 )
F_53 ( V_257 ) ;
return 0 ;
}
int F_227 ( struct V_26 * V_256 ,
T_1 V_6 , T_1 V_79 )
{
struct V_87 * V_88 = V_256 -> V_109 ;
struct V_85 * V_155 ;
int V_16 = 0 ;
F_15 ( & V_88 -> V_93 ) ;
V_155 = F_148 ( V_88 , V_6 , 0 , 0 ) ;
if ( ! V_155 ) {
V_155 = F_148 ( V_88 , F_142 ( V_88 , V_6 ) ,
1 , 0 ) ;
if ( ! V_155 )
goto V_102;
}
V_258:
if ( V_155 -> V_80 ) {
T_1 V_259 , V_260 ;
struct V_90 * V_91 ;
struct V_85 * V_77 ;
V_259 = V_6 ;
V_260 = V_88 -> V_149 ;
V_16 = F_160 ( V_88 , V_155 , & V_259 , & V_260 ) ;
if ( ! V_16 ) {
if ( V_259 == V_6 ) {
V_16 = 1 ;
goto V_102;
} else if ( V_259 > V_6 &&
V_6 + V_79 > V_259 ) {
V_16 = 1 ;
goto V_102;
}
}
V_91 = F_150 ( & V_155 -> V_95 ) ;
while ( V_91 ) {
V_77 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
if ( V_77 -> V_6 + V_77 -> V_79 < V_6 )
break;
if ( V_6 + V_79 < V_77 -> V_6 ) {
V_91 = F_150 ( & V_155 -> V_95 ) ;
continue;
}
V_155 = V_77 ;
goto V_258;
}
V_91 = F_91 ( & V_155 -> V_95 ) ;
while ( V_91 ) {
V_77 = F_92 ( V_91 , struct V_85 ,
V_95 ) ;
if ( V_6 + V_79 < V_77 -> V_6 )
break;
if ( V_77 -> V_6 + V_77 -> V_79 < V_6 ) {
V_91 = F_91 ( & V_155 -> V_95 ) ;
continue;
}
V_155 = V_77 ;
goto V_258;
}
V_16 = 0 ;
goto V_102;
}
if ( V_155 -> V_6 == V_6 ) {
V_16 = 1 ;
goto V_102;
}
if ( V_6 > V_155 -> V_6 && V_6 < V_155 -> V_6 + V_155 -> V_79 )
V_16 = 1 ;
V_102:
F_17 ( & V_88 -> V_93 ) ;
return V_16 ;
}
