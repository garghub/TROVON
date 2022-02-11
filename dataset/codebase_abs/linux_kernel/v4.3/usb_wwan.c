void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 -> V_8 ) ;
if ( ! V_7 -> V_9 )
return;
V_5 = F_3 ( V_2 ) ;
V_5 -> V_10 = V_3 ;
V_5 -> V_11 = V_3 ;
V_7 -> V_9 ( V_2 ) ;
}
int F_4 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
unsigned int V_15 ;
struct V_4 * V_5 ;
V_5 = F_3 ( V_2 ) ;
V_15 = ( ( V_5 -> V_10 ) ? V_16 : 0 ) |
( ( V_5 -> V_11 ) ? V_17 : 0 ) |
( ( V_5 -> V_18 ) ? V_19 : 0 ) |
( ( V_5 -> V_20 ) ? V_21 : 0 ) |
( ( V_5 -> V_22 ) ? V_23 : 0 ) |
( ( V_5 -> V_24 ) ? V_25 : 0 ) ;
return V_15 ;
}
int F_5 ( struct V_12 * V_13 ,
unsigned int V_26 , unsigned int V_27 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_3 ( V_2 ) ;
V_7 = F_2 ( V_2 -> V_8 ) ;
if ( ! V_7 -> V_9 )
return - V_28 ;
if ( V_26 & V_16 )
V_5 -> V_10 = 1 ;
if ( V_26 & V_17 )
V_5 -> V_11 = 1 ;
if ( V_27 & V_16 )
V_5 -> V_10 = 0 ;
if ( V_27 & V_17 )
V_5 -> V_11 = 0 ;
return V_7 -> V_9 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_29 T_1 * V_30 )
{
struct V_29 V_31 ;
if ( ! V_30 )
return - V_32 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . line = V_2 -> V_33 ;
V_31 . V_2 = V_2 -> V_34 ;
V_31 . V_35 = F_7 ( V_2 -> V_2 . V_13 ) ;
V_31 . V_36 = V_2 -> V_2 . V_36 / 10 ;
V_31 . V_37 = V_2 -> V_2 . V_37 == V_38 ?
V_38 :
V_2 -> V_2 . V_37 / 10 ;
if ( F_8 ( V_30 , & V_31 , sizeof( * V_30 ) ) )
return - V_32 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_29 T_1 * V_39 )
{
struct V_29 V_40 ;
unsigned int V_37 , V_36 ;
int V_41 = 0 ;
if ( F_10 ( & V_40 , V_39 , sizeof( V_40 ) ) )
return - V_32 ;
V_36 = V_40 . V_36 * 10 ;
V_37 = V_40 . V_37 == V_38 ?
V_38 : V_40 . V_37 * 10 ;
F_11 ( & V_2 -> V_2 . V_42 ) ;
if ( ! F_12 ( V_43 ) ) {
if ( ( V_36 != V_2 -> V_2 . V_36 ) ||
( V_37 != V_2 -> V_2 . V_37 ) )
V_41 = - V_44 ;
else
V_41 = - V_45 ;
} else {
V_2 -> V_2 . V_36 = V_36 ;
V_2 -> V_2 . V_37 = V_37 ;
}
F_13 ( & V_2 -> V_2 . V_42 ) ;
return V_41 ;
}
int F_14 ( struct V_12 * V_13 ,
unsigned int V_46 , unsigned long V_47 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
F_15 ( & V_2 -> V_48 , L_1 , V_49 , V_46 ) ;
switch ( V_46 ) {
case V_50 :
return F_6 ( V_2 ,
(struct V_29 T_1 * ) V_47 ) ;
case V_51 :
return F_9 ( V_2 ,
(struct V_29 T_1 * ) V_47 ) ;
default:
break;
}
F_15 ( & V_2 -> V_48 , L_2 , V_49 ) ;
return - V_52 ;
}
int F_16 ( struct V_12 * V_13 , struct V_1 * V_2 ,
const unsigned char * V_53 , int V_54 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_55 ;
int V_56 , V_57 ;
struct V_58 * V_59 = NULL ;
int V_60 ;
unsigned long V_61 ;
V_5 = F_3 ( V_2 ) ;
V_7 = F_2 ( V_2 -> V_8 ) ;
F_15 ( & V_2 -> V_48 , L_3 , V_49 , V_54 ) ;
V_55 = 0 ;
V_56 = V_54 ;
for ( V_55 = 0 ; V_56 > 0 && V_55 < V_62 ; V_55 ++ ) {
V_57 = V_56 ;
if ( V_57 > V_63 )
V_57 = V_63 ;
V_59 = V_5 -> V_64 [ V_55 ] ;
if ( F_17 ( V_55 , & V_5 -> V_65 ) ) {
if ( F_18 ( V_66 ,
V_5 -> V_67 [ V_55 ] + 10 * V_68 ) )
continue;
F_19 ( V_59 ) ;
continue;
}
F_15 ( & V_2 -> V_48 , L_4 , V_49 ,
F_20 ( V_59 -> V_69 ) , V_55 ) ;
V_60 = F_21 ( V_2 -> V_8 -> V_70 ) ;
if ( V_60 < 0 ) {
F_22 ( V_55 , & V_5 -> V_65 ) ;
break;
}
memcpy ( V_59 -> V_71 , V_53 , V_57 ) ;
V_59 -> V_72 = V_57 ;
F_23 ( & V_7 -> V_73 , V_61 ) ;
if ( V_7 -> V_74 ) {
F_24 ( V_59 , & V_5 -> V_75 ) ;
F_25 ( & V_7 -> V_73 , V_61 ) ;
} else {
V_7 -> V_76 ++ ;
F_25 ( & V_7 -> V_73 , V_61 ) ;
V_60 = F_26 ( V_59 , V_77 ) ;
if ( V_60 ) {
F_27 ( & V_2 -> V_48 ,
L_5 ,
V_49 , V_55 , V_60 ) ;
F_22 ( V_55 , & V_5 -> V_65 ) ;
F_23 ( & V_7 -> V_73 , V_61 ) ;
V_7 -> V_76 -- ;
F_25 ( & V_7 -> V_73 ,
V_61 ) ;
F_28 ( V_2 -> V_8 -> V_70 ) ;
break;
}
}
V_5 -> V_67 [ V_55 ] = V_66 ;
V_53 += V_57 ;
V_56 -= V_57 ;
}
V_54 -= V_56 ;
F_15 ( & V_2 -> V_48 , L_6 , V_49 , V_54 ) ;
return V_54 ;
}
static void F_29 ( struct V_58 * V_58 )
{
int V_60 ;
int V_78 ;
struct V_1 * V_2 ;
struct V_79 * V_48 ;
unsigned char * V_80 = V_58 -> V_71 ;
int V_81 = V_58 -> V_81 ;
V_78 = F_20 ( V_58 -> V_69 ) ;
V_2 = V_58 -> V_82 ;
V_48 = & V_2 -> V_48 ;
if ( V_81 ) {
F_15 ( V_48 , L_7 ,
V_49 , V_81 , V_78 ) ;
} else {
if ( V_58 -> V_83 ) {
F_30 ( & V_2 -> V_2 , V_80 ,
V_58 -> V_83 ) ;
F_31 ( & V_2 -> V_2 ) ;
} else
F_15 ( V_48 , L_8 , V_49 ) ;
}
V_60 = F_26 ( V_58 , V_77 ) ;
if ( V_60 ) {
if ( V_60 != - V_44 && V_60 != - V_84 ) {
F_27 ( V_48 , L_9 ,
V_49 , V_60 ) ;
F_32 ( V_2 -> V_8 -> V_48 ) ;
}
} else {
F_32 ( V_2 -> V_8 -> V_48 ) ;
}
}
static void F_33 ( struct V_58 * V_58 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_55 ;
V_2 = V_58 -> V_82 ;
V_7 = F_2 ( V_2 -> V_8 ) ;
F_34 ( V_2 ) ;
F_28 ( V_2 -> V_8 -> V_70 ) ;
V_5 = F_3 ( V_2 ) ;
F_35 ( & V_7 -> V_73 ) ;
V_7 -> V_76 -- ;
F_36 ( & V_7 -> V_73 ) ;
for ( V_55 = 0 ; V_55 < V_62 ; ++ V_55 ) {
if ( V_5 -> V_64 [ V_55 ] == V_58 ) {
F_37 () ;
F_22 ( V_55 , & V_5 -> V_65 ) ;
break;
}
}
}
int F_38 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_4 * V_5 ;
int V_55 ;
int V_85 = 0 ;
struct V_58 * V_59 ;
V_5 = F_3 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < V_62 ; V_55 ++ ) {
V_59 = V_5 -> V_64 [ V_55 ] ;
if ( V_59 && ! F_39 ( V_55 , & V_5 -> V_65 ) )
V_85 += V_63 ;
}
F_15 ( & V_2 -> V_48 , L_10 , V_49 , V_85 ) ;
return V_85 ;
}
int F_40 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_4 * V_5 ;
int V_55 ;
int V_85 = 0 ;
struct V_58 * V_59 ;
V_5 = F_3 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < V_62 ; V_55 ++ ) {
V_59 = V_5 -> V_64 [ V_55 ] ;
if ( V_59 && F_39 ( V_55 , & V_5 -> V_65 ) )
V_85 += V_59 -> V_72 ;
}
F_15 ( & V_2 -> V_48 , L_10 , V_49 , V_85 ) ;
return V_85 ;
}
int F_41 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_86 * V_8 = V_2 -> V_8 ;
int V_55 , V_60 ;
struct V_58 * V_58 ;
V_5 = F_3 ( V_2 ) ;
V_7 = F_2 ( V_8 ) ;
if ( V_2 -> V_87 ) {
V_60 = F_26 ( V_2 -> V_87 , V_88 ) ;
if ( V_60 ) {
F_27 ( & V_2 -> V_48 , L_11 ,
V_49 , V_60 ) ;
}
}
for ( V_55 = 0 ; V_55 < V_89 ; V_55 ++ ) {
V_58 = V_5 -> V_90 [ V_55 ] ;
if ( ! V_58 )
continue;
V_60 = F_26 ( V_58 , V_88 ) ;
if ( V_60 ) {
F_27 ( & V_2 -> V_48 ,
L_12 ,
V_49 , V_55 , V_60 ) ;
}
}
F_42 ( & V_7 -> V_73 ) ;
if ( ++ V_7 -> V_91 == 1 )
V_8 -> V_70 -> V_92 = 1 ;
F_43 ( & V_7 -> V_73 ) ;
F_44 ( V_8 -> V_70 ) ;
return 0 ;
}
static void F_45 ( struct V_58 * V_58 ,
struct V_4 * V_5 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_62 ; V_55 ++ ) {
if ( V_58 == V_5 -> V_64 [ V_55 ] ) {
F_22 ( V_55 , & V_5 -> V_65 ) ;
break;
}
}
}
void F_46 ( struct V_1 * V_2 )
{
int V_55 ;
struct V_86 * V_8 = V_2 -> V_8 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
struct V_58 * V_58 ;
V_5 = F_3 ( V_2 ) ;
F_42 ( & V_7 -> V_73 ) ;
if ( -- V_7 -> V_91 == 0 )
V_8 -> V_70 -> V_92 = 0 ;
F_43 ( & V_7 -> V_73 ) ;
for (; ; ) {
V_58 = F_47 ( & V_5 -> V_75 ) ;
if ( ! V_58 )
break;
F_45 ( V_58 , V_5 ) ;
F_28 ( V_8 -> V_70 ) ;
}
for ( V_55 = 0 ; V_55 < V_89 ; V_55 ++ )
F_48 ( V_5 -> V_90 [ V_55 ] ) ;
for ( V_55 = 0 ; V_55 < V_62 ; V_55 ++ )
F_48 ( V_5 -> V_64 [ V_55 ] ) ;
F_48 ( V_2 -> V_87 ) ;
F_49 ( V_8 -> V_70 ) ;
}
static struct V_58 * F_50 ( struct V_1 * V_2 ,
int V_78 ,
int V_93 , void * V_94 , char * V_53 , int V_95 ,
void (* F_51) ( struct V_58 * ) )
{
struct V_86 * V_8 = V_2 -> V_8 ;
struct V_58 * V_58 ;
V_58 = F_52 ( 0 , V_88 ) ;
if ( ! V_58 )
return NULL ;
F_53 ( V_58 , V_8 -> V_48 ,
F_54 ( V_8 -> V_48 , V_78 ) | V_93 ,
V_53 , V_95 , F_51 , V_94 ) ;
return V_58 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_58 * V_58 ;
T_2 * V_96 ;
int V_55 ;
if ( ! V_2 -> V_97 || ! V_2 -> V_98 )
return - V_84 ;
V_5 = F_56 ( sizeof( * V_5 ) , V_88 ) ;
if ( ! V_5 )
return - V_99 ;
F_57 ( & V_5 -> V_75 ) ;
for ( V_55 = 0 ; V_55 < V_89 ; V_55 ++ ) {
V_96 = ( T_2 * ) F_58 ( V_88 ) ;
if ( ! V_96 )
goto V_100;
V_5 -> V_101 [ V_55 ] = V_96 ;
V_58 = F_50 ( V_2 , V_2 -> V_102 ,
V_103 , V_2 ,
V_96 , V_104 ,
F_29 ) ;
V_5 -> V_90 [ V_55 ] = V_58 ;
}
for ( V_55 = 0 ; V_55 < V_62 ; V_55 ++ ) {
V_96 = F_59 ( V_63 , V_88 ) ;
if ( ! V_96 )
goto V_105;
V_5 -> V_106 [ V_55 ] = V_96 ;
V_58 = F_50 ( V_2 , V_2 -> V_107 ,
V_108 , V_2 ,
V_96 , V_63 ,
F_33 ) ;
V_5 -> V_64 [ V_55 ] = V_58 ;
}
F_60 ( V_2 , V_5 ) ;
return 0 ;
V_105:
for ( V_55 = 0 ; V_55 < V_62 ; V_55 ++ ) {
F_61 ( V_5 -> V_64 [ V_55 ] ) ;
F_62 ( V_5 -> V_106 [ V_55 ] ) ;
}
V_100:
for ( V_55 = 0 ; V_55 < V_89 ; V_55 ++ ) {
F_61 ( V_5 -> V_90 [ V_55 ] ) ;
F_63 ( ( unsigned long ) V_5 -> V_101 [ V_55 ] ) ;
}
F_62 ( V_5 ) ;
return - V_99 ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_55 ;
struct V_4 * V_5 ;
V_5 = F_3 ( V_2 ) ;
F_60 ( V_2 , NULL ) ;
for ( V_55 = 0 ; V_55 < V_89 ; V_55 ++ ) {
F_61 ( V_5 -> V_90 [ V_55 ] ) ;
F_63 ( ( unsigned long ) V_5 -> V_101 [ V_55 ] ) ;
}
for ( V_55 = 0 ; V_55 < V_62 ; V_55 ++ ) {
F_61 ( V_5 -> V_64 [ V_55 ] ) ;
F_62 ( V_5 -> V_106 [ V_55 ] ) ;
}
F_62 ( V_5 ) ;
return 0 ;
}
static void F_65 ( struct V_86 * V_8 )
{
int V_55 , V_109 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
for ( V_55 = 0 ; V_55 < V_8 -> V_110 ; ++ V_55 ) {
V_2 = V_8 -> V_2 [ V_55 ] ;
V_5 = F_3 ( V_2 ) ;
if ( ! V_5 )
continue;
for ( V_109 = 0 ; V_109 < V_89 ; V_109 ++ )
F_48 ( V_5 -> V_90 [ V_109 ] ) ;
for ( V_109 = 0 ; V_109 < V_62 ; V_109 ++ )
F_48 ( V_5 -> V_64 [ V_109 ] ) ;
F_48 ( V_2 -> V_87 ) ;
}
}
int F_66 ( struct V_86 * V_8 , T_3 V_111 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
F_42 ( & V_7 -> V_73 ) ;
if ( F_67 ( V_111 ) ) {
if ( V_7 -> V_76 ) {
F_43 ( & V_7 -> V_73 ) ;
return - V_112 ;
}
}
V_7 -> V_74 = 1 ;
F_43 ( & V_7 -> V_73 ) ;
F_65 ( V_8 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_86 * V_8 = V_2 -> V_8 ;
struct V_6 * V_80 = F_2 ( V_8 ) ;
struct V_4 * V_5 ;
struct V_58 * V_58 ;
int V_113 = 0 ;
int V_60 ;
V_5 = F_3 ( V_2 ) ;
for (; ; ) {
V_58 = F_47 ( & V_5 -> V_75 ) ;
if ( ! V_58 )
break;
V_60 = F_26 ( V_58 , V_77 ) ;
if ( V_60 ) {
F_27 ( & V_2 -> V_48 , L_13 ,
V_49 , V_60 ) ;
V_113 ++ ;
F_45 ( V_58 , V_5 ) ;
F_28 ( V_8 -> V_70 ) ;
continue;
}
V_80 -> V_76 ++ ;
}
if ( V_113 )
return - V_114 ;
return 0 ;
}
int F_69 ( struct V_86 * V_8 )
{
int V_55 , V_109 ;
struct V_1 * V_2 ;
struct V_6 * V_7 = F_2 ( V_8 ) ;
struct V_4 * V_5 ;
struct V_58 * V_58 ;
int V_60 ;
int V_113 = 0 ;
F_42 ( & V_7 -> V_73 ) ;
for ( V_55 = 0 ; V_55 < V_8 -> V_110 ; V_55 ++ ) {
V_2 = V_8 -> V_2 [ V_55 ] ;
if ( ! F_39 ( V_115 , & V_2 -> V_2 . V_61 ) )
continue;
V_5 = F_3 ( V_2 ) ;
if ( V_2 -> V_87 ) {
V_60 = F_26 ( V_2 -> V_87 ,
V_77 ) ;
if ( V_60 ) {
F_27 ( & V_2 -> V_48 ,
L_11 ,
V_49 , V_60 ) ;
V_113 ++ ;
}
}
V_60 = F_68 ( V_2 ) ;
if ( V_60 )
V_113 ++ ;
for ( V_109 = 0 ; V_109 < V_89 ; V_109 ++ ) {
V_58 = V_5 -> V_90 [ V_109 ] ;
V_60 = F_26 ( V_58 , V_77 ) ;
if ( V_60 < 0 ) {
F_27 ( & V_2 -> V_48 ,
L_12 ,
V_49 , V_55 , V_60 ) ;
V_113 ++ ;
}
}
}
V_7 -> V_74 = 0 ;
F_43 ( & V_7 -> V_73 ) ;
if ( V_113 )
return - V_114 ;
return 0 ;
}
