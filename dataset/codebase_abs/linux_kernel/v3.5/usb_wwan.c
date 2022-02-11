void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_2 -> V_5 -> V_10 ;
if ( ! V_9 -> V_11 )
return;
V_7 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_12 ) ;
V_7 -> V_13 = V_3 ;
V_7 -> V_14 = V_3 ;
if ( V_5 -> V_15 )
V_9 -> V_11 ( V_2 ) ;
F_4 ( & V_5 -> V_12 ) ;
}
void F_5 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_8 * V_9 = V_2 -> V_5 -> V_10 ;
F_6 ( V_17 -> V_20 , V_19 ) ;
if ( V_9 -> V_11 )
V_9 -> V_11 ( V_2 ) ;
}
int F_7 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
unsigned int V_22 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
V_22 = ( ( V_7 -> V_13 ) ? V_23 : 0 ) |
( ( V_7 -> V_14 ) ? V_24 : 0 ) |
( ( V_7 -> V_25 ) ? V_26 : 0 ) |
( ( V_7 -> V_27 ) ? V_28 : 0 ) |
( ( V_7 -> V_29 ) ? V_30 : 0 ) |
( ( V_7 -> V_31 ) ? V_32 : 0 ) ;
return V_22 ;
}
int F_8 ( struct V_16 * V_17 ,
unsigned int V_33 , unsigned int V_34 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_2 ( V_2 ) ;
V_9 = V_2 -> V_5 -> V_10 ;
if ( ! V_9 -> V_11 )
return - V_35 ;
if ( V_33 & V_23 )
V_7 -> V_13 = 1 ;
if ( V_33 & V_24 )
V_7 -> V_14 = 1 ;
if ( V_34 & V_23 )
V_7 -> V_13 = 0 ;
if ( V_34 & V_24 )
V_7 -> V_14 = 0 ;
return V_9 -> V_11 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_36 T_1 * V_37 )
{
struct V_36 V_38 ;
if ( ! V_37 )
return - V_39 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . line = V_2 -> V_5 -> V_40 ;
V_38 . V_2 = V_2 -> V_41 ;
V_38 . V_42 = F_10 ( V_2 -> V_2 . V_17 ) ;
V_38 . V_43 = V_2 -> V_2 . V_43 / 10 ;
V_38 . V_44 = V_2 -> V_2 . V_44 == V_45 ?
V_45 :
V_2 -> V_2 . V_44 / 10 ;
if ( F_11 ( V_37 , & V_38 , sizeof( * V_37 ) ) )
return - V_39 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_36 T_1 * V_46 )
{
struct V_36 V_47 ;
unsigned int V_44 , V_43 ;
int V_48 = 0 ;
if ( F_13 ( & V_47 , V_46 , sizeof( V_47 ) ) )
return - V_39 ;
V_43 = V_47 . V_43 * 10 ;
V_44 = V_47 . V_44 == V_45 ?
V_45 : V_47 . V_44 * 10 ;
F_3 ( & V_2 -> V_2 . V_49 ) ;
if ( ! F_14 ( V_50 ) ) {
if ( ( V_43 != V_2 -> V_2 . V_43 ) ||
( V_44 != V_2 -> V_2 . V_44 ) )
V_48 = - V_51 ;
else
V_48 = - V_52 ;
} else {
V_2 -> V_2 . V_43 = V_43 ;
V_2 -> V_2 . V_44 = V_44 ;
}
F_4 ( & V_2 -> V_2 . V_49 ) ;
return V_48 ;
}
int F_15 ( struct V_16 * V_17 ,
unsigned int V_53 , unsigned long V_54 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
F_16 ( L_1 , V_55 , V_53 ) ;
switch ( V_53 ) {
case V_56 :
return F_9 ( V_2 ,
(struct V_36 T_1 * ) V_54 ) ;
case V_57 :
return F_12 ( V_2 ,
(struct V_36 T_1 * ) V_54 ) ;
default:
break;
}
F_16 ( L_2 , V_55 ) ;
return - V_58 ;
}
int F_17 ( struct V_16 * V_17 , struct V_1 * V_2 ,
const unsigned char * V_59 , int V_60 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_61 ;
int V_62 , V_63 ;
struct V_64 * V_65 = NULL ;
int V_66 ;
unsigned long V_67 ;
V_7 = F_2 ( V_2 ) ;
V_9 = V_2 -> V_5 -> V_10 ;
F_16 ( L_3 , V_55 , V_60 ) ;
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
F_16 ( L_4 , V_55 ,
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
F_16 ( L_5
L_6 , V_65 , V_66 ) ;
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
F_16 ( L_7 , V_55 , V_60 ) ;
return V_60 ;
}
static void F_29 ( struct V_64 * V_64 )
{
int V_66 ;
int V_84 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
unsigned char * V_85 = V_64 -> V_77 ;
int V_86 = V_64 -> V_86 ;
V_84 = F_21 ( V_64 -> V_75 ) ;
V_2 = V_64 -> V_87 ;
if ( V_86 ) {
F_16 ( L_8 ,
V_55 , V_86 , V_84 ) ;
} else {
V_17 = F_30 ( & V_2 -> V_2 ) ;
if ( V_17 ) {
if ( V_64 -> V_88 ) {
F_31 ( V_17 , V_85 ,
V_64 -> V_88 ) ;
F_32 ( V_17 ) ;
} else
F_16 ( L_9 , V_55 ) ;
F_33 ( V_17 ) ;
}
V_66 = F_26 ( V_64 , V_83 ) ;
if ( V_66 ) {
if ( V_66 != - V_51 ) {
F_34 ( V_89 L_10
L_6 , V_55 , V_66 ) ;
F_35 ( V_2 -> V_5 -> V_15 ) ;
}
} else {
F_35 ( V_2 -> V_5 -> V_15 ) ;
}
}
}
static void F_36 ( struct V_64 * V_64 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_61 ;
V_2 = V_64 -> V_87 ;
V_9 = V_2 -> V_5 -> V_10 ;
F_37 ( V_2 ) ;
F_28 ( V_2 -> V_5 -> V_76 ) ;
V_7 = F_2 ( V_2 ) ;
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
int F_41 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
struct V_6 * V_7 ;
int V_61 ;
int V_90 = 0 ;
struct V_64 * V_65 ;
V_7 = F_2 ( V_2 ) ;
for ( V_61 = 0 ; V_61 < V_68 ; V_61 ++ ) {
V_65 = V_7 -> V_70 [ V_61 ] ;
if ( V_65 && ! F_42 ( V_61 , & V_7 -> V_71 ) )
V_90 += V_69 ;
}
F_16 ( L_11 , V_55 , V_90 ) ;
return V_90 ;
}
int F_43 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
struct V_6 * V_7 ;
int V_61 ;
int V_90 = 0 ;
struct V_64 * V_65 ;
V_7 = F_2 ( V_2 ) ;
for ( V_61 = 0 ; V_61 < V_68 ; V_61 ++ ) {
V_65 = V_7 -> V_70 [ V_61 ] ;
if ( V_65 && F_42 ( V_61 , & V_7 -> V_71 ) )
V_90 += V_65 -> V_78 ;
}
F_16 ( L_11 , V_55 , V_90 ) ;
return V_90 ;
}
int F_44 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_61 , V_66 ;
struct V_64 * V_64 ;
V_7 = F_2 ( V_2 ) ;
V_9 = V_5 -> V_10 ;
for ( V_61 = 0 ; V_61 < V_91 ; V_61 ++ ) {
V_64 = V_7 -> V_92 [ V_61 ] ;
if ( ! V_64 )
continue;
V_66 = F_26 ( V_64 , V_93 ) ;
if ( V_66 ) {
F_16 ( L_12 ,
V_55 , V_61 , V_66 , V_64 -> V_78 ) ;
}
}
if ( V_9 -> V_11 )
V_9 -> V_11 ( V_2 ) ;
V_5 -> V_76 -> V_94 = 1 ;
F_45 ( & V_9 -> V_79 ) ;
V_7 -> V_95 = 1 ;
F_46 ( & V_9 -> V_79 ) ;
F_47 ( V_5 -> V_76 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
int V_61 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = V_2 -> V_5 -> V_10 ;
V_7 = F_2 ( V_2 ) ;
if ( V_5 -> V_15 ) {
F_45 ( & V_9 -> V_79 ) ;
V_7 -> V_95 = 0 ;
F_46 ( & V_9 -> V_79 ) ;
for ( V_61 = 0 ; V_61 < V_91 ; V_61 ++ )
F_49 ( V_7 -> V_92 [ V_61 ] ) ;
for ( V_61 = 0 ; V_61 < V_68 ; V_61 ++ )
F_49 ( V_7 -> V_70 [ V_61 ] ) ;
F_50 ( V_5 -> V_76 ) ;
V_5 -> V_76 -> V_94 = 0 ;
}
}
static struct V_64 * F_51 ( struct V_4 * V_5 , int V_84 ,
int V_96 , void * V_97 , char * V_59 , int V_98 ,
void (* F_52) ( struct V_64 * ) )
{
struct V_64 * V_64 ;
if ( V_84 == - 1 )
return NULL ;
V_64 = F_53 ( 0 , V_93 ) ;
if ( V_64 == NULL ) {
F_16 ( L_13 , V_55 , V_84 ) ;
return NULL ;
}
F_54 ( V_64 , V_5 -> V_15 ,
F_55 ( V_5 -> V_15 , V_84 ) | V_96 ,
V_59 , V_98 , F_52 , V_97 ) ;
return V_64 ;
}
static void F_56 ( struct V_4 * V_5 )
{
int V_61 , V_99 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
for ( V_61 = 0 ; V_61 < V_5 -> V_100 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_2 ( V_2 ) ;
for ( V_99 = 0 ; V_99 < V_91 ; ++ V_99 ) {
V_7 -> V_92 [ V_99 ] = F_51 ( V_5 ,
V_2 ->
V_101 ,
V_102 ,
V_2 ,
V_7 ->
V_103 [ V_99 ] ,
V_104 ,
F_29 ) ;
}
for ( V_99 = 0 ; V_99 < V_68 ; ++ V_99 ) {
V_7 -> V_70 [ V_99 ] = F_51 ( V_5 ,
V_2 ->
V_105 ,
V_106 ,
V_2 ,
V_7 ->
V_107
[ V_99 ] ,
V_69 ,
F_36 ) ;
}
}
}
int F_57 ( struct V_4 * V_5 )
{
int V_61 , V_99 , V_66 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_2 * V_108 ;
for ( V_61 = 0 ; V_61 < V_5 -> V_100 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_58 ( sizeof( * V_7 ) , V_93 ) ;
if ( ! V_7 ) {
F_16 ( L_14 ,
V_55 , V_61 ) ;
return 1 ;
}
F_59 ( & V_7 -> V_81 ) ;
for ( V_99 = 0 ; V_99 < V_91 ; V_99 ++ ) {
V_108 = ( T_2 * ) F_60 ( V_93 ) ;
if ( ! V_108 )
goto V_109;
V_7 -> V_103 [ V_99 ] = V_108 ;
}
for ( V_99 = 0 ; V_99 < V_68 ; V_99 ++ ) {
V_108 = F_61 ( V_69 , V_93 ) ;
if ( ! V_108 )
goto V_110;
V_7 -> V_107 [ V_99 ] = V_108 ;
}
F_62 ( V_2 , V_7 ) ;
if ( ! V_2 -> V_111 )
continue;
V_66 = F_26 ( V_2 -> V_111 , V_93 ) ;
if ( V_66 )
F_16 ( L_15 , V_55 , V_66 ) ;
}
F_56 ( V_5 ) ;
return 0 ;
V_110:
for ( V_99 = 0 ; V_99 < V_68 ; V_99 ++ )
F_63 ( V_7 -> V_107 [ V_99 ] ) ;
V_109:
for ( V_99 = 0 ; V_99 < V_91 ; V_99 ++ )
if ( V_7 -> V_103 [ V_99 ] )
F_64 ( ( unsigned long ) V_7 -> V_103 [ V_99 ] ) ;
F_63 ( V_7 ) ;
return 1 ;
}
static void F_65 ( struct V_4 * V_5 )
{
int V_61 , V_99 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
for ( V_61 = 0 ; V_61 < V_5 -> V_100 ; ++ V_61 ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_2 ( V_2 ) ;
for ( V_99 = 0 ; V_99 < V_91 ; V_99 ++ )
F_49 ( V_7 -> V_92 [ V_99 ] ) ;
for ( V_99 = 0 ; V_99 < V_68 ; V_99 ++ )
F_49 ( V_7 -> V_70 [ V_99 ] ) ;
}
}
void F_66 ( struct V_4 * V_5 )
{
F_65 ( V_5 ) ;
}
void F_67 ( struct V_4 * V_5 )
{
int V_61 , V_99 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
for ( V_61 = 0 ; V_61 < V_5 -> V_100 ; ++ V_61 ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_2 ( V_2 ) ;
for ( V_99 = 0 ; V_99 < V_91 ; V_99 ++ ) {
F_68 ( V_7 -> V_92 [ V_99 ] ) ;
F_64 ( ( unsigned long )
V_7 -> V_103 [ V_99 ] ) ;
V_7 -> V_92 [ V_99 ] = NULL ;
}
for ( V_99 = 0 ; V_99 < V_68 ; V_99 ++ ) {
F_68 ( V_7 -> V_70 [ V_99 ] ) ;
F_63 ( V_7 -> V_107 [ V_99 ] ) ;
V_7 -> V_70 [ V_99 ] = NULL ;
}
}
for ( V_61 = 0 ; V_61 < V_5 -> V_100 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
F_63 ( F_2 ( V_2 ) ) ;
}
}
int F_69 ( struct V_4 * V_5 , T_3 V_112 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
int V_113 ;
if ( F_70 ( V_112 ) ) {
F_45 ( & V_9 -> V_79 ) ;
V_113 = V_9 -> V_82 ;
F_46 ( & V_9 -> V_79 ) ;
if ( V_113 )
return - V_114 ;
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
V_7 = F_2 ( V_2 ) ;
V_85 = V_2 -> V_5 -> V_10 ;
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
int V_61 , V_99 ;
struct V_1 * V_2 ;
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_6 * V_7 ;
struct V_64 * V_64 ;
int V_66 = 0 ;
for ( V_61 = 0 ; V_61 < V_5 -> V_100 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
if ( ! V_2 -> V_111 ) {
F_16 ( L_16 , V_55 , V_61 ) ;
continue;
}
V_66 = F_26 ( V_2 -> V_111 , V_115 ) ;
F_16 ( L_17 , V_61 , V_66 ) ;
if ( V_66 < 0 ) {
F_76 ( & V_2 -> V_15 , L_18 ,
V_55 , V_66 ) ;
goto V_116;
}
}
for ( V_61 = 0 ; V_61 < V_5 -> V_100 ; V_61 ++ ) {
V_2 = V_5 -> V_2 [ V_61 ] ;
V_7 = F_2 ( V_2 ) ;
F_45 ( & V_9 -> V_79 ) ;
if ( ! V_7 -> V_95 ) {
F_46 ( & V_9 -> V_79 ) ;
continue;
}
for ( V_99 = 0 ; V_99 < V_91 ; V_99 ++ ) {
V_64 = V_7 -> V_92 [ V_99 ] ;
V_66 = F_26 ( V_64 , V_83 ) ;
if ( V_66 < 0 ) {
F_76 ( & V_2 -> V_15 , L_19 ,
V_55 , V_66 , V_61 ) ;
F_46 ( & V_9 -> V_79 ) ;
goto V_116;
}
}
F_72 ( V_2 ) ;
F_46 ( & V_9 -> V_79 ) ;
}
F_45 ( & V_9 -> V_79 ) ;
V_9 -> V_80 = 0 ;
F_46 ( & V_9 -> V_79 ) ;
V_116:
return V_66 ;
}
