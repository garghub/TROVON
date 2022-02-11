void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_7 = V_2 -> V_8 -> V_9 ;
if ( ! V_7 -> V_10 )
return;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_11 = V_3 ;
V_5 -> V_12 = V_3 ;
V_7 -> V_10 ( V_2 ) ;
}
void F_3 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
F_4 ( & V_14 -> V_17 , V_16 ) ;
if ( V_7 -> V_10 )
V_7 -> V_10 ( V_2 ) ;
}
int F_5 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_18 ;
unsigned int V_19 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
V_19 = ( ( V_5 -> V_11 ) ? V_20 : 0 ) |
( ( V_5 -> V_12 ) ? V_21 : 0 ) |
( ( V_5 -> V_22 ) ? V_23 : 0 ) |
( ( V_5 -> V_24 ) ? V_25 : 0 ) |
( ( V_5 -> V_26 ) ? V_27 : 0 ) |
( ( V_5 -> V_28 ) ? V_29 : 0 ) ;
return V_19 ;
}
int F_6 ( struct V_13 * V_14 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_1 * V_2 = V_14 -> V_18 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_2 ) ;
V_7 = V_2 -> V_8 -> V_9 ;
if ( ! V_7 -> V_10 )
return - V_32 ;
if ( V_30 & V_20 )
V_5 -> V_11 = 1 ;
if ( V_30 & V_21 )
V_5 -> V_12 = 1 ;
if ( V_31 & V_20 )
V_5 -> V_11 = 0 ;
if ( V_31 & V_21 )
V_5 -> V_12 = 0 ;
return V_7 -> V_10 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_33 T_1 * V_34 )
{
struct V_33 V_35 ;
if ( ! V_34 )
return - V_36 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . line = V_2 -> V_37 ;
V_35 . V_2 = V_2 -> V_38 ;
V_35 . V_39 = F_8 ( V_2 -> V_2 . V_14 ) ;
V_35 . V_40 = V_2 -> V_2 . V_40 / 10 ;
V_35 . V_41 = V_2 -> V_2 . V_41 == V_42 ?
V_42 :
V_2 -> V_2 . V_41 / 10 ;
if ( F_9 ( V_34 , & V_35 , sizeof( * V_34 ) ) )
return - V_36 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_33 T_1 * V_43 )
{
struct V_33 V_44 ;
unsigned int V_41 , V_40 ;
int V_45 = 0 ;
if ( F_11 ( & V_44 , V_43 , sizeof( V_44 ) ) )
return - V_36 ;
V_40 = V_44 . V_40 * 10 ;
V_41 = V_44 . V_41 == V_42 ?
V_42 : V_44 . V_41 * 10 ;
F_12 ( & V_2 -> V_2 . V_46 ) ;
if ( ! F_13 ( V_47 ) ) {
if ( ( V_40 != V_2 -> V_2 . V_40 ) ||
( V_41 != V_2 -> V_2 . V_41 ) )
V_45 = - V_48 ;
else
V_45 = - V_49 ;
} else {
V_2 -> V_2 . V_40 = V_40 ;
V_2 -> V_2 . V_41 = V_41 ;
}
F_14 ( & V_2 -> V_2 . V_46 ) ;
return V_45 ;
}
int F_15 ( struct V_13 * V_14 ,
unsigned int V_50 , unsigned long V_51 )
{
struct V_1 * V_2 = V_14 -> V_18 ;
F_16 ( & V_2 -> V_52 , L_1 , V_53 , V_50 ) ;
switch ( V_50 ) {
case V_54 :
return F_7 ( V_2 ,
(struct V_33 T_1 * ) V_51 ) ;
case V_55 :
return F_10 ( V_2 ,
(struct V_33 T_1 * ) V_51 ) ;
default:
break;
}
F_16 ( & V_2 -> V_52 , L_2 , V_53 ) ;
return - V_56 ;
}
int F_17 ( struct V_13 * V_14 , struct V_1 * V_2 ,
const unsigned char * V_57 , int V_58 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_59 ;
int V_60 , V_61 ;
struct V_62 * V_63 = NULL ;
int V_64 ;
unsigned long V_65 ;
V_5 = F_2 ( V_2 ) ;
V_7 = V_2 -> V_8 -> V_9 ;
F_16 ( & V_2 -> V_52 , L_3 , V_53 , V_58 ) ;
V_59 = 0 ;
V_60 = V_58 ;
for ( V_59 = 0 ; V_60 > 0 && V_59 < V_66 ; V_59 ++ ) {
V_61 = V_60 ;
if ( V_61 > V_67 )
V_61 = V_67 ;
V_63 = V_5 -> V_68 [ V_59 ] ;
if ( F_18 ( V_59 , & V_5 -> V_69 ) ) {
if ( F_19 ( V_70 ,
V_5 -> V_71 [ V_59 ] + 10 * V_72 ) )
continue;
F_20 ( V_63 ) ;
continue;
}
F_16 ( & V_2 -> V_52 , L_4 , V_53 ,
F_21 ( V_63 -> V_73 ) , V_59 ) ;
V_64 = F_22 ( V_2 -> V_8 -> V_74 ) ;
if ( V_64 < 0 )
break;
memcpy ( V_63 -> V_75 , V_57 , V_61 ) ;
V_63 -> V_76 = V_61 ;
F_23 ( & V_7 -> V_77 , V_65 ) ;
if ( V_7 -> V_78 ) {
F_24 ( V_63 , & V_5 -> V_79 ) ;
F_25 ( & V_7 -> V_77 , V_65 ) ;
} else {
V_7 -> V_80 ++ ;
F_25 ( & V_7 -> V_77 , V_65 ) ;
V_64 = F_26 ( V_63 , V_81 ) ;
if ( V_64 ) {
F_16 ( & V_2 -> V_52 ,
L_5 ,
V_63 , V_64 ) ;
F_27 ( V_59 , & V_5 -> V_69 ) ;
F_23 ( & V_7 -> V_77 , V_65 ) ;
V_7 -> V_80 -- ;
F_25 ( & V_7 -> V_77 ,
V_65 ) ;
F_28 ( V_2 -> V_8 -> V_74 ) ;
break;
}
}
V_5 -> V_71 [ V_59 ] = V_70 ;
V_57 += V_61 ;
V_60 -= V_61 ;
}
V_58 -= V_60 ;
F_16 ( & V_2 -> V_52 , L_6 , V_53 , V_58 ) ;
return V_58 ;
}
static void F_29 ( struct V_62 * V_62 )
{
int V_64 ;
int V_82 ;
struct V_1 * V_2 ;
struct V_83 * V_52 ;
unsigned char * V_84 = V_62 -> V_75 ;
int V_85 = V_62 -> V_85 ;
V_82 = F_21 ( V_62 -> V_73 ) ;
V_2 = V_62 -> V_86 ;
V_52 = & V_2 -> V_52 ;
if ( V_85 ) {
F_16 ( V_52 , L_7 ,
V_53 , V_85 , V_82 ) ;
} else {
if ( V_62 -> V_87 ) {
F_30 ( & V_2 -> V_2 , V_84 ,
V_62 -> V_87 ) ;
F_31 ( & V_2 -> V_2 ) ;
} else
F_16 ( V_52 , L_8 , V_53 ) ;
}
V_64 = F_26 ( V_62 , V_81 ) ;
if ( V_64 ) {
if ( V_64 != - V_48 ) {
F_32 ( V_52 , L_9 ,
V_53 , V_64 ) ;
F_33 ( V_2 -> V_8 -> V_52 ) ;
}
} else {
F_33 ( V_2 -> V_8 -> V_52 ) ;
}
}
static void F_34 ( struct V_62 * V_62 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_59 ;
V_2 = V_62 -> V_86 ;
V_7 = V_2 -> V_8 -> V_9 ;
F_35 ( V_2 ) ;
F_28 ( V_2 -> V_8 -> V_74 ) ;
V_5 = F_2 ( V_2 ) ;
F_36 ( & V_7 -> V_77 ) ;
V_7 -> V_80 -- ;
F_37 ( & V_7 -> V_77 ) ;
for ( V_59 = 0 ; V_59 < V_66 ; ++ V_59 ) {
if ( V_5 -> V_68 [ V_59 ] == V_62 ) {
F_38 () ;
F_27 ( V_59 , & V_5 -> V_69 ) ;
break;
}
}
}
int F_39 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_18 ;
struct V_4 * V_5 ;
int V_59 ;
int V_88 = 0 ;
struct V_62 * V_63 ;
V_5 = F_2 ( V_2 ) ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_63 = V_5 -> V_68 [ V_59 ] ;
if ( V_63 && ! F_40 ( V_59 , & V_5 -> V_69 ) )
V_88 += V_67 ;
}
F_16 ( & V_2 -> V_52 , L_10 , V_53 , V_88 ) ;
return V_88 ;
}
int F_41 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_18 ;
struct V_4 * V_5 ;
int V_59 ;
int V_88 = 0 ;
struct V_62 * V_63 ;
V_5 = F_2 ( V_2 ) ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_63 = V_5 -> V_68 [ V_59 ] ;
if ( V_63 && F_40 ( V_59 , & V_5 -> V_69 ) )
V_88 += V_63 -> V_76 ;
}
F_16 ( & V_2 -> V_52 , L_10 , V_53 , V_88 ) ;
return V_88 ;
}
int F_42 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_89 * V_8 = V_2 -> V_8 ;
int V_59 , V_64 ;
struct V_62 * V_62 ;
V_5 = F_2 ( V_2 ) ;
V_7 = V_8 -> V_9 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
V_62 = V_5 -> V_91 [ V_59 ] ;
if ( ! V_62 )
continue;
V_64 = F_26 ( V_62 , V_92 ) ;
if ( V_64 ) {
F_16 ( & V_2 -> V_52 , L_11 ,
V_53 , V_59 , V_64 , V_62 -> V_76 ) ;
}
}
if ( V_7 -> V_10 )
V_7 -> V_10 ( V_2 ) ;
V_8 -> V_74 -> V_93 = 1 ;
F_43 ( & V_7 -> V_77 ) ;
V_5 -> V_94 = 1 ;
F_44 ( & V_7 -> V_77 ) ;
F_45 ( V_8 -> V_74 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
int V_59 ;
struct V_89 * V_8 = V_2 -> V_8 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
V_5 = F_2 ( V_2 ) ;
F_43 ( & V_7 -> V_77 ) ;
V_5 -> V_94 = 0 ;
F_44 ( & V_7 -> V_77 ) ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ )
F_47 ( V_5 -> V_91 [ V_59 ] ) ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ )
F_47 ( V_5 -> V_68 [ V_59 ] ) ;
F_48 ( V_8 -> V_74 ) ;
V_8 -> V_74 -> V_93 = 0 ;
}
static struct V_62 * F_49 ( struct V_1 * V_2 ,
int V_82 ,
int V_95 , void * V_96 , char * V_57 , int V_97 ,
void (* F_50) ( struct V_62 * ) )
{
struct V_89 * V_8 = V_2 -> V_8 ;
struct V_62 * V_62 ;
V_62 = F_51 ( 0 , V_92 ) ;
if ( V_62 == NULL ) {
F_16 ( & V_8 -> V_74 -> V_52 ,
L_12 , V_53 ,
V_82 ) ;
return NULL ;
}
F_52 ( V_62 , V_8 -> V_52 ,
F_53 ( V_8 -> V_52 , V_82 ) | V_95 ,
V_57 , V_97 , F_50 , V_96 ) ;
return V_62 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_62 * V_62 ;
T_2 * V_98 ;
int V_64 ;
int V_59 ;
V_5 = F_55 ( sizeof( * V_5 ) , V_92 ) ;
if ( ! V_5 )
return - V_99 ;
F_56 ( & V_5 -> V_79 ) ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
if ( ! V_2 -> V_100 )
break;
V_98 = ( T_2 * ) F_57 ( V_92 ) ;
if ( ! V_98 )
goto V_101;
V_5 -> V_102 [ V_59 ] = V_98 ;
V_62 = F_49 ( V_2 , V_2 -> V_103 ,
V_104 , V_2 ,
V_98 , V_105 ,
F_29 ) ;
V_5 -> V_91 [ V_59 ] = V_62 ;
}
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
if ( ! V_2 -> V_106 )
break;
V_98 = F_58 ( V_67 , V_92 ) ;
if ( ! V_98 )
goto V_107;
V_5 -> V_108 [ V_59 ] = V_98 ;
V_62 = F_49 ( V_2 , V_2 -> V_109 ,
V_110 , V_2 ,
V_98 , V_67 ,
F_34 ) ;
V_5 -> V_68 [ V_59 ] = V_62 ;
}
F_59 ( V_2 , V_5 ) ;
if ( V_2 -> V_111 ) {
V_64 = F_26 ( V_2 -> V_111 , V_92 ) ;
if ( V_64 )
F_16 ( & V_2 -> V_52 , L_13 ,
V_53 , V_64 ) ;
}
return 0 ;
V_107:
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
F_60 ( V_5 -> V_68 [ V_59 ] ) ;
F_61 ( V_5 -> V_108 [ V_59 ] ) ;
}
V_101:
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
F_60 ( V_5 -> V_91 [ V_59 ] ) ;
F_62 ( ( unsigned long ) V_5 -> V_102 [ V_59 ] ) ;
}
F_61 ( V_5 ) ;
return - V_99 ;
}
int F_63 ( struct V_1 * V_2 )
{
int V_59 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
F_59 ( V_2 , NULL ) ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
F_47 ( V_5 -> V_91 [ V_59 ] ) ;
F_60 ( V_5 -> V_91 [ V_59 ] ) ;
F_62 ( ( unsigned long ) V_5 -> V_102 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
F_47 ( V_5 -> V_68 [ V_59 ] ) ;
F_60 ( V_5 -> V_68 [ V_59 ] ) ;
F_61 ( V_5 -> V_108 [ V_59 ] ) ;
}
F_61 ( V_5 ) ;
return 0 ;
}
static void F_64 ( struct V_89 * V_8 )
{
int V_59 , V_112 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
for ( V_59 = 0 ; V_59 < V_8 -> V_113 ; ++ V_59 ) {
V_2 = V_8 -> V_2 [ V_59 ] ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
continue;
for ( V_112 = 0 ; V_112 < V_90 ; V_112 ++ )
F_47 ( V_5 -> V_91 [ V_112 ] ) ;
for ( V_112 = 0 ; V_112 < V_66 ; V_112 ++ )
F_47 ( V_5 -> V_68 [ V_112 ] ) ;
}
}
int F_65 ( struct V_89 * V_8 , T_3 V_114 )
{
struct V_6 * V_7 = V_8 -> V_9 ;
int V_115 ;
if ( F_66 ( V_114 ) ) {
F_43 ( & V_7 -> V_77 ) ;
V_115 = V_7 -> V_80 ;
F_44 ( & V_7 -> V_77 ) ;
if ( V_115 )
return - V_116 ;
}
F_43 ( & V_7 -> V_77 ) ;
V_7 -> V_78 = 1 ;
F_44 ( & V_7 -> V_77 ) ;
F_64 ( V_8 ) ;
return 0 ;
}
static void F_67 ( struct V_62 * V_62 , struct V_4 * V_5 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
if ( V_62 == V_5 -> V_68 [ V_59 ] ) {
F_27 ( V_59 , & V_5 -> V_69 ) ;
break;
}
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_84 ;
struct V_4 * V_5 ;
struct V_62 * V_62 ;
int V_64 ;
V_5 = F_2 ( V_2 ) ;
V_84 = V_2 -> V_8 -> V_9 ;
while ( ( V_62 = F_69 ( & V_5 -> V_79 ) ) ) {
V_64 = F_26 ( V_62 , V_81 ) ;
if ( ! V_64 ) {
V_84 -> V_80 ++ ;
} else {
do {
F_67 ( V_62 , V_5 ) ;
F_70 ( V_2 -> V_8 -> V_74 ) ;
} while ( ( V_62 = F_69 ( & V_5 -> V_79 ) ) );
break;
}
}
}
int F_71 ( struct V_89 * V_8 )
{
int V_59 , V_112 ;
struct V_1 * V_2 ;
struct V_6 * V_7 = V_8 -> V_9 ;
struct V_4 * V_5 ;
struct V_62 * V_62 ;
int V_64 = 0 ;
for ( V_59 = 0 ; V_59 < V_8 -> V_113 ; V_59 ++ ) {
V_2 = V_8 -> V_2 [ V_59 ] ;
if ( ! V_2 -> V_111 ) {
F_16 ( & V_2 -> V_52 , L_14 , V_53 ) ;
continue;
}
V_64 = F_26 ( V_2 -> V_111 , V_117 ) ;
F_16 ( & V_2 -> V_52 , L_15 , V_64 ) ;
if ( V_64 < 0 ) {
F_32 ( & V_2 -> V_52 , L_16 ,
V_53 , V_64 ) ;
goto V_118;
}
}
for ( V_59 = 0 ; V_59 < V_8 -> V_113 ; V_59 ++ ) {
V_2 = V_8 -> V_2 [ V_59 ] ;
V_5 = F_2 ( V_2 ) ;
F_43 ( & V_7 -> V_77 ) ;
if ( ! V_5 || ! V_5 -> V_94 ) {
F_44 ( & V_7 -> V_77 ) ;
continue;
}
for ( V_112 = 0 ; V_112 < V_90 ; V_112 ++ ) {
V_62 = V_5 -> V_91 [ V_112 ] ;
V_64 = F_26 ( V_62 , V_81 ) ;
if ( V_64 < 0 ) {
F_32 ( & V_2 -> V_52 , L_17 ,
V_53 , V_64 , V_59 ) ;
F_44 ( & V_7 -> V_77 ) ;
goto V_118;
}
}
F_68 ( V_2 ) ;
F_44 ( & V_7 -> V_77 ) ;
}
F_43 ( & V_7 -> V_77 ) ;
V_7 -> V_78 = 0 ;
F_44 ( & V_7 -> V_77 ) ;
V_118:
return V_64 ;
}
