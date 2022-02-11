void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_2 ( L_1 , V_10 ) ;
V_9 = V_2 -> V_5 -> V_11 ;
if ( ! V_9 -> V_12 )
return;
V_7 = F_3 ( V_2 ) ;
F_4 ( & V_5 -> V_13 ) ;
V_7 -> V_14 = V_3 ;
V_7 -> V_15 = V_3 ;
if ( V_5 -> V_16 )
V_9 -> V_12 ( V_2 ) ;
F_5 ( & V_5 -> V_13 ) ;
}
void F_6 ( struct V_17 * V_18 ,
struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_2 -> V_5 -> V_11 ;
F_2 ( L_1 , V_10 ) ;
F_7 ( V_18 -> V_21 , V_20 ) ;
if ( V_9 -> V_12 )
V_9 -> V_12 ( V_2 ) ;
}
int F_8 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_22 ;
unsigned int V_23 ;
struct V_6 * V_7 ;
V_7 = F_3 ( V_2 ) ;
V_23 = ( ( V_7 -> V_14 ) ? V_24 : 0 ) |
( ( V_7 -> V_15 ) ? V_25 : 0 ) |
( ( V_7 -> V_26 ) ? V_27 : 0 ) |
( ( V_7 -> V_28 ) ? V_29 : 0 ) |
( ( V_7 -> V_30 ) ? V_31 : 0 ) |
( ( V_7 -> V_32 ) ? V_33 : 0 ) ;
return V_23 ;
}
int F_9 ( struct V_17 * V_18 ,
unsigned int V_34 , unsigned int V_35 )
{
struct V_1 * V_2 = V_18 -> V_22 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_3 ( V_2 ) ;
V_9 = V_2 -> V_5 -> V_11 ;
if ( ! V_9 -> V_12 )
return - V_36 ;
if ( V_34 & V_24 )
V_7 -> V_14 = 1 ;
if ( V_34 & V_25 )
V_7 -> V_15 = 1 ;
if ( V_35 & V_24 )
V_7 -> V_14 = 0 ;
if ( V_35 & V_25 )
V_7 -> V_15 = 0 ;
return V_9 -> V_12 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_37 T_1 * V_38 )
{
struct V_37 V_39 ;
if ( ! V_38 )
return - V_40 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . line = V_2 -> V_5 -> V_41 ;
V_39 . V_2 = V_2 -> V_42 ;
V_39 . V_43 = F_11 ( V_2 -> V_2 . V_18 ) ;
V_39 . V_44 = V_2 -> V_2 . V_44 / 10 ;
V_39 . V_45 = V_2 -> V_2 . V_45 == V_46 ?
V_46 :
V_2 -> V_2 . V_45 / 10 ;
if ( F_12 ( V_38 , & V_39 , sizeof( * V_38 ) ) )
return - V_40 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_37 T_1 * V_47 )
{
struct V_37 V_48 ;
unsigned int V_45 , V_44 ;
int V_49 = 0 ;
if ( F_14 ( & V_48 , V_47 , sizeof( V_48 ) ) )
return - V_40 ;
V_44 = V_48 . V_44 * 10 ;
V_45 = V_48 . V_45 == V_46 ?
V_46 : V_48 . V_45 * 10 ;
F_4 ( & V_2 -> V_2 . V_50 ) ;
if ( ! F_15 ( V_51 ) ) {
if ( ( V_44 != V_2 -> V_2 . V_44 ) ||
( V_45 != V_2 -> V_2 . V_45 ) )
V_49 = - V_52 ;
else
V_49 = - V_53 ;
} else {
V_2 -> V_2 . V_44 = V_44 ;
V_2 -> V_2 . V_45 = V_45 ;
}
F_5 ( & V_2 -> V_2 . V_50 ) ;
return V_49 ;
}
int F_16 ( struct V_17 * V_18 ,
unsigned int V_54 , unsigned long V_55 )
{
struct V_1 * V_2 = V_18 -> V_22 ;
F_2 ( L_2 , V_10 , V_54 ) ;
switch ( V_54 ) {
case V_56 :
return F_10 ( V_2 ,
(struct V_37 T_1 * ) V_55 ) ;
case V_57 :
return F_13 ( V_2 ,
(struct V_37 T_1 * ) V_55 ) ;
default:
break;
}
F_2 ( L_3 , V_10 ) ;
return - V_58 ;
}
int F_17 ( struct V_17 * V_18 , struct V_1 * V_2 ,
const unsigned char * V_59 , int V_60 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_61 ;
int V_62 , V_63 ;
struct V_64 * V_65 = NULL ;
int V_66 ;
unsigned long V_67 ;
V_7 = F_3 ( V_2 ) ;
V_9 = V_2 -> V_5 -> V_11 ;
F_2 ( L_4 , V_10 , V_60 ) ;
V_61 = 0 ;
V_62 = V_60 ;
for ( V_61 = 0 ; V_62 > 0 && V_61 < V_68 ; V_61 ++ ) {
V_63 = V_62 ;
if ( V_63 > V_69 )
V_63 = V_69 ;
V_65 = V_7 -> V_70 [ V_61 ] ;
if ( F_18 ( V_61 , & V_7 -> V_71 ) ) {
if ( F_19 ( V_72 ,
V_7 -> V_73 [ V_61 ] + 10 * V_74 ) )
continue;
F_20 ( V_65 ) ;
continue;
}
F_2 ( L_5 , V_10 ,
F_21 ( V_65 -> V_75 ) , V_61 ) ;
V_66 = F_22 ( V_2 -> V_5 -> V_76 ) ;
if ( V_66 < 0 )
break;
memcpy ( V_65 -> V_77 , V_59 , V_63 ) ;
V_65 -> V_78 = V_63 ;
F_23 ( & V_9 -> V_79 , V_67 ) ;
if ( V_9 -> V_80 ) {
F_24 ( V_65 , & V_7 -> V_81 ) ;
F_25 ( & V_9 -> V_79 , V_67 ) ;
} else {
V_9 -> V_82 ++ ;
F_25 ( & V_9 -> V_79 , V_67 ) ;
V_66 = F_26 ( V_65 , V_83 ) ;
if ( V_66 ) {
F_2 ( L_6
L_7 , V_65 , V_66 ) ;
F_27 ( V_61 , & V_7 -> V_71 ) ;
F_23 ( & V_9 -> V_79 , V_67 ) ;
V_9 -> V_82 -- ;
F_25 ( & V_9 -> V_79 ,
V_67 ) ;
F_28 ( V_2 -> V_5 -> V_76 ) ;
break;
}
}
V_7 -> V_73 [ V_61 ] = V_72 ;
V_59 += V_63 ;
V_62 -= V_63 ;
}
V_60 -= V_62 ;
F_2 ( L_8 , V_10 , V_60 ) ;
return V_60 ;
}
static void F_29 ( struct V_64 * V_64 )
{
int V_66 ;
int V_84 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
unsigned char * V_85 = V_64 -> V_77 ;
int V_86 = V_64 -> V_86 ;
F_2 ( L_9 , V_10 , V_64 ) ;
V_84 = F_21 ( V_64 -> V_75 ) ;
V_2 = V_64 -> V_87 ;
if ( V_86 ) {
F_2 ( L_10 ,
V_10 , V_86 , V_84 ) ;
} else {
V_18 = F_30 ( & V_2 -> V_2 ) ;
if ( V_18 ) {
if ( V_64 -> V_88 ) {
F_31 ( V_18 , V_85 ,
V_64 -> V_88 ) ;
F_32 ( V_18 ) ;
} else
F_2 ( L_11 , V_10 ) ;
F_33 ( V_18 ) ;
}
if ( V_86 != - V_89 ) {
V_66 = F_26 ( V_64 , V_83 ) ;
if ( V_66 ) {
if ( V_66 != - V_52 ) {
F_34 ( V_90 L_12
L_7 , V_10 , V_66 ) ;
F_35 ( V_2 -> V_5 -> V_16 ) ;
}
} else {
F_35 ( V_2 -> V_5 -> V_16 ) ;
}
}
}
}
static void F_36 ( struct V_64 * V_64 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_61 ;
F_2 ( L_1 , V_10 ) ;
V_2 = V_64 -> V_87 ;
V_9 = V_2 -> V_5 -> V_11 ;
F_37 ( V_2 ) ;
F_28 ( V_2 -> V_5 -> V_76 ) ;
V_7 = F_3 ( V_2 ) ;
F_38 ( & V_9 -> V_79 ) ;
V_9 -> V_82 -- ;
F_39 ( & V_9 -> V_79 ) ;
for ( V_61 = 0 ; V_61 < V_68 ; ++ V_61 ) {
if ( V_7 -> V_70 [ V_61 ] == V_64 ) {
F_40 () ;
F_27 ( V_61 , & V_7 -> V_71 ) ;
break;
}
}
}
int F_41 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_22 ;
struct V_6 * V_7 ;
int V_61 ;
int V_91 = 0 ;
struct V_64 * V_65 ;
V_7 = F_3 ( V_2 ) ;
for ( V_61 = 0 ; V_61 < V_68 ; V_61 ++ ) {
V_65 = V_7 -> V_70 [ V_61 ] ;
if ( V_65 && ! F_42 ( V_61 , & V_7 -> V_71 ) )
V_91 += V_69 ;
}
F_2 ( L_13 , V_10 , V_91 ) ;
return V_91 ;
}
int F_43 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_22 ;
struct V_6 * V_7 ;
int V_61 ;
int V_91 = 0 ;
struct V_64 * V_65 ;
V_7 = F_3 ( V_2 ) ;
for ( V_61 = 0 ; V_61 < V_68 ; V_61 ++ ) {
V_65 = V_7 -> V_70 [ V_61 ] ;
if ( V_65 && F_42 ( V_61 , & V_7 -> V_71 ) )
V_91 += V_65 -> V_78 ;
}
F_2 ( L_13 , V_10 , V_91 ) ;
return V_91 ;
}
int F_44 ( struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_61 , V_66 ;
struct V_64 * V_64 ;
V_7 = F_3 ( V_2 ) ;
V_9 = V_5 -> V_11 ;
F_2 ( L_1 , V_10 ) ;
for ( V_61 = 0 ; V_61 < V_92 ; V_61 ++ ) {
V_64 = V_7 -> V_93 [ V_61 ] ;
if ( ! V_64 )
continue;
V_66 = F_26 ( V_64 , V_94 ) ;
if ( V_66 ) {
F_2 ( L_14 ,
V_10 , V_61 , V_66 , V_64 -> V_78 ) ;
}
}
if ( V_9 -> V_12 )
V_9 -> V_12 ( V_2 ) ;
V_5 -> V_76 -> V_95 = 1 ;
F_45 ( & V_9 -> V_79 ) ;
V_7 -> V_96 = 1 ;
F_46 ( & V_9 -> V_79 ) ;
F_47 ( V_5 -> V_76 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
int V_61 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = V_2 -> V_5 -> V_11 ;
F_2 ( L_1 , V_10 ) ;
V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_16 ) {
F_45 ( & V_9 -> V_79 ) ;
V_7 -> V_96 = 0 ;
F_46 ( & V_9 -> V_79 ) ;
for ( V_61 = 0 ; V_61 < V_92 ; V_61 ++ )
F_49 ( V_7 -> V_93 [ V_61 ] ) ;
for ( V_61 = 0 ; V_61 < V_68 ; V_61 ++ )
F_49 ( V_7 -> V_70 [ V_61 ] ) ;
F_50 ( V_5 -> V_76 ) ;
V_5 -> V_76 -> V_95 = 0 ;
}
}
static struct V_64 * F_51 ( struct V_4 * V_5 , int V_84 ,
int V_97 , void * V_98 , char * V_59 , int V_99 ,
void (* F_52) ( struct V_64 * ) )
{
struct V_64 * V_64 ;
if ( V_84 == - 1 )
return NULL ;
V_64 = F_53 ( 0 , V_94 ) ;
if ( V_64 == NULL ) {
F_2 ( L_15 , V_10 , V_84 ) ;
return NULL ;
}
F_54 ( V_64 , V_5 -> V_16 ,
F_55 ( V_5 -> V_16 , V_84 ) | V_97 ,
V_59 , V_99 , F_52 , V_98 ) ;
return V_64 ;
}
static void F_56 ( struct V_4 * V_5 )
{
int V_61 , V_100 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
F_2 ( L_1 , V_10 ) ;
for ( V_61 = 0 ; V_61 < V_5 -> V_101 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_3 ( V_2 ) ;
for ( V_100 = 0 ; V_100 < V_92 ; ++ V_100 ) {
V_7 -> V_93 [ V_100 ] = F_51 ( V_5 ,
V_2 ->
V_102 ,
V_103 ,
V_2 ,
V_7 ->
V_104 [ V_100 ] ,
V_105 ,
F_29 ) ;
}
for ( V_100 = 0 ; V_100 < V_68 ; ++ V_100 ) {
V_7 -> V_70 [ V_100 ] = F_51 ( V_5 ,
V_2 ->
V_106 ,
V_107 ,
V_2 ,
V_7 ->
V_108
[ V_100 ] ,
V_69 ,
F_36 ) ;
}
}
}
int F_57 ( struct V_4 * V_5 )
{
int V_61 , V_100 , V_66 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_2 * V_109 ;
F_2 ( L_1 , V_10 ) ;
for ( V_61 = 0 ; V_61 < V_5 -> V_101 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_58 ( sizeof( * V_7 ) , V_94 ) ;
if ( ! V_7 ) {
F_2 ( L_16 ,
V_10 , V_61 ) ;
return 1 ;
}
F_59 ( & V_7 -> V_81 ) ;
for ( V_100 = 0 ; V_100 < V_92 ; V_100 ++ ) {
V_109 = ( T_2 * ) F_60 ( V_94 ) ;
if ( ! V_109 )
goto V_110;
V_7 -> V_104 [ V_100 ] = V_109 ;
}
for ( V_100 = 0 ; V_100 < V_68 ; V_100 ++ ) {
V_109 = F_61 ( V_69 , V_94 ) ;
if ( ! V_109 )
goto V_111;
V_7 -> V_108 [ V_100 ] = V_109 ;
}
F_62 ( V_2 , V_7 ) ;
if ( ! V_2 -> V_112 )
continue;
V_66 = F_26 ( V_2 -> V_112 , V_94 ) ;
if ( V_66 )
F_2 ( L_17 , V_10 , V_66 ) ;
}
F_56 ( V_5 ) ;
return 0 ;
V_111:
for ( V_100 = 0 ; V_100 < V_68 ; V_100 ++ )
F_63 ( V_7 -> V_108 [ V_100 ] ) ;
V_110:
for ( V_100 = 0 ; V_100 < V_92 ; V_100 ++ )
if ( V_7 -> V_104 [ V_100 ] )
F_64 ( ( unsigned long ) V_7 -> V_104 [ V_100 ] ) ;
F_63 ( V_7 ) ;
return 1 ;
}
static void F_65 ( struct V_4 * V_5 )
{
int V_61 , V_100 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
for ( V_61 = 0 ; V_61 < V_5 -> V_101 ; ++ V_61 ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_3 ( V_2 ) ;
for ( V_100 = 0 ; V_100 < V_92 ; V_100 ++ )
F_49 ( V_7 -> V_93 [ V_100 ] ) ;
for ( V_100 = 0 ; V_100 < V_68 ; V_100 ++ )
F_49 ( V_7 -> V_70 [ V_100 ] ) ;
}
}
void F_66 ( struct V_4 * V_5 )
{
F_2 ( L_1 , V_10 ) ;
F_65 ( V_5 ) ;
}
void F_67 ( struct V_4 * V_5 )
{
int V_61 , V_100 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
F_2 ( L_1 , V_10 ) ;
for ( V_61 = 0 ; V_61 < V_5 -> V_101 ; ++ V_61 ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_3 ( V_2 ) ;
for ( V_100 = 0 ; V_100 < V_92 ; V_100 ++ ) {
F_68 ( V_7 -> V_93 [ V_100 ] ) ;
F_64 ( ( unsigned long )
V_7 -> V_104 [ V_100 ] ) ;
V_7 -> V_93 [ V_100 ] = NULL ;
}
for ( V_100 = 0 ; V_100 < V_68 ; V_100 ++ ) {
F_68 ( V_7 -> V_70 [ V_100 ] ) ;
F_63 ( V_7 -> V_108 [ V_100 ] ) ;
V_7 -> V_70 [ V_100 ] = NULL ;
}
}
for ( V_61 = 0 ; V_61 < V_5 -> V_101 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
F_63 ( F_3 ( V_2 ) ) ;
}
}
int F_69 ( struct V_4 * V_5 , T_3 V_113 )
{
struct V_8 * V_9 = V_5 -> V_11 ;
int V_114 ;
F_2 ( L_18 , V_10 ) ;
if ( F_70 ( V_113 ) ) {
F_45 ( & V_9 -> V_79 ) ;
V_114 = V_9 -> V_82 ;
F_46 ( & V_9 -> V_79 ) ;
if ( V_114 )
return - V_115 ;
}
F_45 ( & V_9 -> V_79 ) ;
V_9 -> V_80 = 1 ;
F_46 ( & V_9 -> V_79 ) ;
F_65 ( V_5 ) ;
return 0 ;
}
static void F_71 ( struct V_64 * V_64 , struct V_6 * V_7 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_68 ; V_61 ++ ) {
if ( V_64 == V_7 -> V_70 [ V_61 ] ) {
F_27 ( V_61 , & V_7 -> V_71 ) ;
break;
}
}
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_8 * V_85 ;
struct V_6 * V_7 ;
struct V_64 * V_64 ;
int V_66 ;
V_7 = F_3 ( V_2 ) ;
V_85 = V_2 -> V_5 -> V_11 ;
while ( ( V_64 = F_73 ( & V_7 -> V_81 ) ) ) {
V_66 = F_26 ( V_64 , V_83 ) ;
if ( ! V_66 ) {
V_85 -> V_82 ++ ;
} else {
do {
F_71 ( V_64 , V_7 ) ;
F_74 ( V_2 -> V_5 -> V_76 ) ;
} while ( ( V_64 = F_73 ( & V_7 -> V_81 ) ) );
break;
}
}
}
int F_75 ( struct V_4 * V_5 )
{
int V_61 , V_100 ;
struct V_1 * V_2 ;
struct V_8 * V_9 = V_5 -> V_11 ;
struct V_6 * V_7 ;
struct V_64 * V_64 ;
int V_66 = 0 ;
F_2 ( L_18 , V_10 ) ;
for ( V_61 = 0 ; V_61 < V_5 -> V_101 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
if ( ! V_2 -> V_112 ) {
F_2 ( L_19 , V_10 , V_61 ) ;
continue;
}
V_66 = F_26 ( V_2 -> V_112 , V_116 ) ;
F_2 ( L_20 , V_61 , V_66 ) ;
if ( V_66 < 0 ) {
V_66 ( L_21 ,
V_10 , V_66 , V_61 ) ;
goto V_117;
}
}
for ( V_61 = 0 ; V_61 < V_5 -> V_101 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_3 ( V_2 ) ;
F_45 ( & V_9 -> V_79 ) ;
if ( ! V_7 -> V_96 ) {
F_46 ( & V_9 -> V_79 ) ;
continue;
}
for ( V_100 = 0 ; V_100 < V_92 ; V_100 ++ ) {
V_64 = V_7 -> V_93 [ V_100 ] ;
V_66 = F_26 ( V_64 , V_83 ) ;
if ( V_66 < 0 ) {
V_66 ( L_22 ,
V_10 , V_66 , V_61 ) ;
F_46 ( & V_9 -> V_79 ) ;
goto V_117;
}
}
F_72 ( V_2 ) ;
F_46 ( & V_9 -> V_79 ) ;
}
F_45 ( & V_9 -> V_79 ) ;
V_9 -> V_80 = 0 ;
F_46 ( & V_9 -> V_79 ) ;
V_117:
return V_66 ;
}
