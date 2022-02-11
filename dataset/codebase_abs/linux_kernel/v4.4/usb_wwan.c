static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_7 = 0 ;
int V_8 ;
int V_9 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_10 )
V_7 |= 0x01 ;
if ( V_6 -> V_11 )
V_7 |= 0x02 ;
V_8 = V_4 -> V_12 -> V_13 -> V_14 . V_15 ;
V_9 = F_3 ( V_4 -> V_12 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_4 -> V_16 , F_5 ( V_4 -> V_16 , 0 ) ,
0x22 , 0x21 , V_7 , V_8 , NULL , 0 ,
V_17 ) ;
F_6 ( V_2 -> V_4 -> V_12 ) ;
return V_9 ;
}
void F_7 ( struct V_1 * V_2 , int V_18 )
{
struct V_5 * V_6 ;
struct V_19 * V_20 ;
V_20 = F_8 ( V_2 -> V_4 ) ;
if ( ! V_20 -> V_21 )
return;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_11 = V_18 ;
V_6 -> V_10 = V_18 ;
F_1 ( V_2 ) ;
}
int F_9 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
unsigned int V_25 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
V_25 = ( ( V_6 -> V_11 ) ? V_26 : 0 ) |
( ( V_6 -> V_10 ) ? V_27 : 0 ) |
( ( V_6 -> V_28 ) ? V_29 : 0 ) |
( ( V_6 -> V_30 ) ? V_31 : 0 ) |
( ( V_6 -> V_32 ) ? V_33 : 0 ) |
( ( V_6 -> V_34 ) ? V_35 : 0 ) ;
return V_25 ;
}
int F_10 ( struct V_22 * V_23 ,
unsigned int V_36 , unsigned int V_37 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
V_6 = F_2 ( V_2 ) ;
V_20 = F_8 ( V_2 -> V_4 ) ;
if ( ! V_20 -> V_21 )
return - V_38 ;
if ( V_36 & V_26 )
V_6 -> V_11 = 1 ;
if ( V_36 & V_27 )
V_6 -> V_10 = 1 ;
if ( V_37 & V_26 )
V_6 -> V_11 = 0 ;
if ( V_37 & V_27 )
V_6 -> V_10 = 0 ;
return F_1 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_39 T_1 * V_40 )
{
struct V_39 V_41 ;
if ( ! V_40 )
return - V_42 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . line = V_2 -> V_43 ;
V_41 . V_2 = V_2 -> V_44 ;
V_41 . V_45 = F_12 ( V_2 -> V_2 . V_23 ) ;
V_41 . V_46 = V_2 -> V_2 . V_46 / 10 ;
V_41 . V_47 = V_2 -> V_2 . V_47 == V_48 ?
V_48 :
V_2 -> V_2 . V_47 / 10 ;
if ( F_13 ( V_40 , & V_41 , sizeof( * V_40 ) ) )
return - V_42 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_39 T_1 * V_49 )
{
struct V_39 V_50 ;
unsigned int V_47 , V_46 ;
int V_51 = 0 ;
if ( F_15 ( & V_50 , V_49 , sizeof( V_50 ) ) )
return - V_42 ;
V_46 = V_50 . V_46 * 10 ;
V_47 = V_50 . V_47 == V_48 ?
V_48 : V_50 . V_47 * 10 ;
F_16 ( & V_2 -> V_2 . V_52 ) ;
if ( ! F_17 ( V_53 ) ) {
if ( ( V_46 != V_2 -> V_2 . V_46 ) ||
( V_47 != V_2 -> V_2 . V_47 ) )
V_51 = - V_54 ;
else
V_51 = - V_55 ;
} else {
V_2 -> V_2 . V_46 = V_46 ;
V_2 -> V_2 . V_47 = V_47 ;
}
F_18 ( & V_2 -> V_2 . V_52 ) ;
return V_51 ;
}
int F_19 ( struct V_22 * V_23 ,
unsigned int V_56 , unsigned long V_57 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_20 ( & V_2 -> V_16 , L_1 , V_58 , V_56 ) ;
switch ( V_56 ) {
case V_59 :
return F_11 ( V_2 ,
(struct V_39 T_1 * ) V_57 ) ;
case V_60 :
return F_14 ( V_2 ,
(struct V_39 T_1 * ) V_57 ) ;
default:
break;
}
F_20 ( & V_2 -> V_16 , L_2 , V_58 ) ;
return - V_61 ;
}
int F_21 ( struct V_22 * V_23 , struct V_1 * V_2 ,
const unsigned char * V_62 , int V_63 )
{
struct V_5 * V_6 ;
struct V_19 * V_20 ;
int V_64 ;
int V_65 , V_66 ;
struct V_67 * V_68 = NULL ;
int V_69 ;
unsigned long V_70 ;
V_6 = F_2 ( V_2 ) ;
V_20 = F_8 ( V_2 -> V_4 ) ;
F_20 ( & V_2 -> V_16 , L_3 , V_58 , V_63 ) ;
V_64 = 0 ;
V_65 = V_63 ;
for ( V_64 = 0 ; V_65 > 0 && V_64 < V_71 ; V_64 ++ ) {
V_66 = V_65 ;
if ( V_66 > V_72 )
V_66 = V_72 ;
V_68 = V_6 -> V_73 [ V_64 ] ;
if ( F_22 ( V_64 , & V_6 -> V_74 ) ) {
if ( F_23 ( V_75 ,
V_6 -> V_76 [ V_64 ] + 10 * V_77 ) )
continue;
F_24 ( V_68 ) ;
continue;
}
F_20 ( & V_2 -> V_16 , L_4 , V_58 ,
F_25 ( V_68 -> V_78 ) , V_64 ) ;
V_69 = F_26 ( V_2 -> V_4 -> V_12 ) ;
if ( V_69 < 0 ) {
F_27 ( V_64 , & V_6 -> V_74 ) ;
break;
}
memcpy ( V_68 -> V_79 , V_62 , V_66 ) ;
V_68 -> V_80 = V_66 ;
F_28 ( & V_20 -> V_81 , V_70 ) ;
if ( V_20 -> V_82 ) {
F_29 ( V_68 , & V_6 -> V_83 ) ;
F_30 ( & V_20 -> V_81 , V_70 ) ;
} else {
V_20 -> V_84 ++ ;
F_30 ( & V_20 -> V_81 , V_70 ) ;
V_69 = F_31 ( V_68 , V_85 ) ;
if ( V_69 ) {
F_32 ( & V_2 -> V_16 ,
L_5 ,
V_58 , V_64 , V_69 ) ;
F_27 ( V_64 , & V_6 -> V_74 ) ;
F_28 ( & V_20 -> V_81 , V_70 ) ;
V_20 -> V_84 -- ;
F_30 ( & V_20 -> V_81 ,
V_70 ) ;
F_33 ( V_2 -> V_4 -> V_12 ) ;
break;
}
}
V_6 -> V_76 [ V_64 ] = V_75 ;
V_62 += V_66 ;
V_65 -= V_66 ;
}
V_63 -= V_65 ;
F_20 ( & V_2 -> V_16 , L_6 , V_58 , V_63 ) ;
return V_63 ;
}
static void F_34 ( struct V_67 * V_67 )
{
int V_69 ;
int V_86 ;
struct V_1 * V_2 ;
struct V_87 * V_16 ;
unsigned char * V_88 = V_67 -> V_79 ;
int V_89 = V_67 -> V_89 ;
V_86 = F_25 ( V_67 -> V_78 ) ;
V_2 = V_67 -> V_90 ;
V_16 = & V_2 -> V_16 ;
if ( V_89 ) {
F_20 ( V_16 , L_7 ,
V_58 , V_89 , V_86 ) ;
} else {
if ( V_67 -> V_91 ) {
F_35 ( & V_2 -> V_2 , V_88 ,
V_67 -> V_91 ) ;
F_36 ( & V_2 -> V_2 ) ;
} else
F_20 ( V_16 , L_8 , V_58 ) ;
}
V_69 = F_31 ( V_67 , V_85 ) ;
if ( V_69 ) {
if ( V_69 != - V_54 && V_69 != - V_92 ) {
F_32 ( V_16 , L_9 ,
V_58 , V_69 ) ;
F_37 ( V_2 -> V_4 -> V_16 ) ;
}
} else {
F_37 ( V_2 -> V_4 -> V_16 ) ;
}
}
static void F_38 ( struct V_67 * V_67 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
int V_64 ;
V_2 = V_67 -> V_90 ;
V_20 = F_8 ( V_2 -> V_4 ) ;
F_39 ( V_2 ) ;
F_33 ( V_2 -> V_4 -> V_12 ) ;
V_6 = F_2 ( V_2 ) ;
F_40 ( & V_20 -> V_81 ) ;
V_20 -> V_84 -- ;
F_41 ( & V_20 -> V_81 ) ;
for ( V_64 = 0 ; V_64 < V_71 ; ++ V_64 ) {
if ( V_6 -> V_73 [ V_64 ] == V_67 ) {
F_42 () ;
F_27 ( V_64 , & V_6 -> V_74 ) ;
break;
}
}
}
int F_43 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_5 * V_6 ;
int V_64 ;
int V_93 = 0 ;
struct V_67 * V_68 ;
V_6 = F_2 ( V_2 ) ;
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ ) {
V_68 = V_6 -> V_73 [ V_64 ] ;
if ( V_68 && ! F_44 ( V_64 , & V_6 -> V_74 ) )
V_93 += V_72 ;
}
F_20 ( & V_2 -> V_16 , L_10 , V_58 , V_93 ) ;
return V_93 ;
}
int F_45 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_5 * V_6 ;
int V_64 ;
int V_93 = 0 ;
struct V_67 * V_68 ;
V_6 = F_2 ( V_2 ) ;
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ ) {
V_68 = V_6 -> V_73 [ V_64 ] ;
if ( V_68 && F_44 ( V_64 , & V_6 -> V_74 ) )
V_93 += V_68 -> V_80 ;
}
F_20 ( & V_2 -> V_16 , L_10 , V_58 , V_93 ) ;
return V_93 ;
}
int F_46 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_19 * V_20 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_64 , V_69 ;
struct V_67 * V_67 ;
V_6 = F_2 ( V_2 ) ;
V_20 = F_8 ( V_4 ) ;
if ( V_2 -> V_94 ) {
V_69 = F_31 ( V_2 -> V_94 , V_95 ) ;
if ( V_69 ) {
F_32 ( & V_2 -> V_16 , L_11 ,
V_58 , V_69 ) ;
}
}
for ( V_64 = 0 ; V_64 < V_96 ; V_64 ++ ) {
V_67 = V_6 -> V_97 [ V_64 ] ;
if ( ! V_67 )
continue;
V_69 = F_31 ( V_67 , V_95 ) ;
if ( V_69 ) {
F_32 ( & V_2 -> V_16 ,
L_12 ,
V_58 , V_64 , V_69 ) ;
}
}
F_47 ( & V_20 -> V_81 ) ;
if ( ++ V_20 -> V_98 == 1 )
V_4 -> V_12 -> V_99 = 1 ;
F_48 ( & V_20 -> V_81 ) ;
F_6 ( V_4 -> V_12 ) ;
return 0 ;
}
static void F_49 ( struct V_67 * V_67 ,
struct V_5 * V_6 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ ) {
if ( V_67 == V_6 -> V_73 [ V_64 ] ) {
F_27 ( V_64 , & V_6 -> V_74 ) ;
break;
}
}
}
void F_50 ( struct V_1 * V_2 )
{
int V_64 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_19 * V_20 = F_8 ( V_4 ) ;
struct V_67 * V_67 ;
V_6 = F_2 ( V_2 ) ;
F_47 ( & V_20 -> V_81 ) ;
if ( -- V_20 -> V_98 == 0 )
V_4 -> V_12 -> V_99 = 0 ;
F_48 ( & V_20 -> V_81 ) ;
for (; ; ) {
V_67 = F_51 ( & V_6 -> V_83 ) ;
if ( ! V_67 )
break;
F_49 ( V_67 , V_6 ) ;
F_33 ( V_4 -> V_12 ) ;
}
for ( V_64 = 0 ; V_64 < V_96 ; V_64 ++ )
F_52 ( V_6 -> V_97 [ V_64 ] ) ;
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ )
F_52 ( V_6 -> V_73 [ V_64 ] ) ;
F_52 ( V_2 -> V_94 ) ;
F_53 ( V_4 -> V_12 ) ;
}
static struct V_67 * F_54 ( struct V_1 * V_2 ,
int V_86 ,
int V_100 , void * V_101 , char * V_62 , int V_102 ,
void (* F_55) ( struct V_67 * ) )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_67 * V_67 ;
V_67 = F_56 ( 0 , V_95 ) ;
if ( ! V_67 )
return NULL ;
F_57 ( V_67 , V_4 -> V_16 ,
F_58 ( V_4 -> V_16 , V_86 ) | V_100 ,
V_62 , V_102 , F_55 , V_101 ) ;
return V_67 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_67 * V_67 ;
T_2 * V_103 ;
int V_64 ;
if ( ! V_2 -> V_104 || ! V_2 -> V_105 )
return - V_92 ;
V_6 = F_60 ( sizeof( * V_6 ) , V_95 ) ;
if ( ! V_6 )
return - V_106 ;
F_61 ( & V_6 -> V_83 ) ;
for ( V_64 = 0 ; V_64 < V_96 ; V_64 ++ ) {
V_103 = ( T_2 * ) F_62 ( V_95 ) ;
if ( ! V_103 )
goto V_107;
V_6 -> V_108 [ V_64 ] = V_103 ;
V_67 = F_54 ( V_2 , V_2 -> V_109 ,
V_110 , V_2 ,
V_103 , V_111 ,
F_34 ) ;
V_6 -> V_97 [ V_64 ] = V_67 ;
}
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ ) {
V_103 = F_63 ( V_72 , V_95 ) ;
if ( ! V_103 )
goto V_112;
V_6 -> V_113 [ V_64 ] = V_103 ;
V_67 = F_54 ( V_2 , V_2 -> V_114 ,
V_115 , V_2 ,
V_103 , V_72 ,
F_38 ) ;
V_6 -> V_73 [ V_64 ] = V_67 ;
}
F_64 ( V_2 , V_6 ) ;
return 0 ;
V_112:
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ ) {
F_65 ( V_6 -> V_73 [ V_64 ] ) ;
F_66 ( V_6 -> V_113 [ V_64 ] ) ;
}
V_107:
for ( V_64 = 0 ; V_64 < V_96 ; V_64 ++ ) {
F_65 ( V_6 -> V_97 [ V_64 ] ) ;
F_67 ( ( unsigned long ) V_6 -> V_108 [ V_64 ] ) ;
}
F_66 ( V_6 ) ;
return - V_106 ;
}
int F_68 ( struct V_1 * V_2 )
{
int V_64 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
F_64 ( V_2 , NULL ) ;
for ( V_64 = 0 ; V_64 < V_96 ; V_64 ++ ) {
F_65 ( V_6 -> V_97 [ V_64 ] ) ;
F_67 ( ( unsigned long ) V_6 -> V_108 [ V_64 ] ) ;
}
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ ) {
F_65 ( V_6 -> V_73 [ V_64 ] ) ;
F_66 ( V_6 -> V_113 [ V_64 ] ) ;
}
F_66 ( V_6 ) ;
return 0 ;
}
static void F_69 ( struct V_3 * V_4 )
{
int V_64 , V_116 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
for ( V_64 = 0 ; V_64 < V_4 -> V_117 ; ++ V_64 ) {
V_2 = V_4 -> V_2 [ V_64 ] ;
V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
continue;
for ( V_116 = 0 ; V_116 < V_96 ; V_116 ++ )
F_52 ( V_6 -> V_97 [ V_116 ] ) ;
for ( V_116 = 0 ; V_116 < V_71 ; V_116 ++ )
F_52 ( V_6 -> V_73 [ V_116 ] ) ;
F_52 ( V_2 -> V_94 ) ;
}
}
int F_70 ( struct V_3 * V_4 , T_3 V_118 )
{
struct V_19 * V_20 = F_8 ( V_4 ) ;
F_47 ( & V_20 -> V_81 ) ;
if ( F_71 ( V_118 ) ) {
if ( V_20 -> V_84 ) {
F_48 ( & V_20 -> V_81 ) ;
return - V_119 ;
}
}
V_20 -> V_82 = 1 ;
F_48 ( & V_20 -> V_81 ) ;
F_69 ( V_4 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_19 * V_88 = F_8 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_67 * V_67 ;
int V_120 = 0 ;
int V_69 ;
V_6 = F_2 ( V_2 ) ;
for (; ; ) {
V_67 = F_51 ( & V_6 -> V_83 ) ;
if ( ! V_67 )
break;
V_69 = F_31 ( V_67 , V_85 ) ;
if ( V_69 ) {
F_32 ( & V_2 -> V_16 , L_13 ,
V_58 , V_69 ) ;
V_120 ++ ;
F_49 ( V_67 , V_6 ) ;
F_33 ( V_4 -> V_12 ) ;
continue;
}
V_88 -> V_84 ++ ;
}
if ( V_120 )
return - V_121 ;
return 0 ;
}
int F_73 ( struct V_3 * V_4 )
{
int V_64 , V_116 ;
struct V_1 * V_2 ;
struct V_19 * V_20 = F_8 ( V_4 ) ;
struct V_5 * V_6 ;
struct V_67 * V_67 ;
int V_69 ;
int V_120 = 0 ;
F_47 ( & V_20 -> V_81 ) ;
for ( V_64 = 0 ; V_64 < V_4 -> V_117 ; V_64 ++ ) {
V_2 = V_4 -> V_2 [ V_64 ] ;
if ( ! F_44 ( V_122 , & V_2 -> V_2 . V_70 ) )
continue;
V_6 = F_2 ( V_2 ) ;
if ( V_2 -> V_94 ) {
V_69 = F_31 ( V_2 -> V_94 ,
V_85 ) ;
if ( V_69 ) {
F_32 ( & V_2 -> V_16 ,
L_11 ,
V_58 , V_69 ) ;
V_120 ++ ;
}
}
V_69 = F_72 ( V_2 ) ;
if ( V_69 )
V_120 ++ ;
for ( V_116 = 0 ; V_116 < V_96 ; V_116 ++ ) {
V_67 = V_6 -> V_97 [ V_116 ] ;
V_69 = F_31 ( V_67 , V_85 ) ;
if ( V_69 < 0 ) {
F_32 ( & V_2 -> V_16 ,
L_12 ,
V_58 , V_64 , V_69 ) ;
V_120 ++ ;
}
}
}
V_20 -> V_82 = 0 ;
F_48 ( & V_20 -> V_81 ) ;
if ( V_120 )
return - V_121 ;
return 0 ;
}
