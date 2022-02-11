static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned long V_6 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_3 += V_10 ;
return F_2 ( V_9 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned long V_6 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_3 += V_10 ;
return F_4 ( V_9 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_13 ;
F_6 ( ! F_7 ( V_2 -> V_14 , 512 ) ) ;
F_6 ( ! F_7 ( V_2 -> V_15 , 512 ) ) ;
V_13 = F_3 ( V_2 , V_2 -> V_15 , V_12 ,
sizeof( struct V_11 ) , 0 ) ;
if ( V_13 )
return V_13 ;
return F_3 ( V_2 , V_2 -> V_14 , V_12 ,
sizeof( struct V_11 ) , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_9 ( ! V_12 ) ;
return F_1 ( V_2 , V_2 -> V_14 , V_12 ,
sizeof( struct V_11 ) , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_3 V_16 , T_4 V_17 ,
unsigned long V_6 )
{
T_5 V_18 = V_2 -> V_19 + ( V_16 * V_20 ) ;
F_9 ( V_16 >= V_2 -> V_21 ) ;
return F_3 ( V_2 , V_18 , & V_17 , V_20 , V_6 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_3 V_16 , T_3 V_17 ,
T_3 V_22 , T_3 V_23 , unsigned long V_24 )
{
T_3 V_25 ;
T_4 V_26 ;
V_17 &= V_27 ;
V_25 = ( V_22 << 1 ) + V_23 ;
switch ( V_25 ) {
case 0 :
V_17 |= V_28 ;
break;
case 1 :
V_17 |= ( 1 << V_29 ) ;
break;
case 2 :
V_17 |= ( 1 << V_30 ) ;
break;
default:
F_12 ( 1 , L_1 ) ;
return - V_31 ;
}
V_26 = F_13 ( V_17 ) ;
return F_10 ( V_2 , V_16 , V_26 , V_24 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_3 V_16 , T_3 * V_17 ,
int * V_32 , int * error , unsigned long V_24 )
{
int V_13 ;
T_4 V_33 ;
T_3 V_34 , V_35 , V_25 , V_22 , V_23 ;
T_5 V_18 = V_2 -> V_19 + ( V_16 * V_20 ) ;
F_9 ( V_16 >= V_2 -> V_21 ) ;
V_13 = F_1 ( V_2 , V_18 , & V_33 , V_20 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_34 = F_15 ( V_33 ) ;
V_22 = ( V_34 & V_36 ) >> V_30 ;
V_23 = ( V_34 & V_37 ) >> V_29 ;
V_25 = ( V_22 << 1 ) + V_23 ;
V_35 = V_34 & V_27 ;
V_22 = 0 ;
V_23 = 0 ;
switch ( V_25 ) {
case 0 :
* V_17 = V_16 ;
break;
case 1 :
* V_17 = V_35 ;
V_23 = 1 ;
break;
case 2 :
* V_17 = V_35 ;
V_22 = 1 ;
break;
case 3 :
* V_17 = V_35 ;
break;
default:
return - V_31 ;
}
if ( V_32 )
* V_32 = V_22 ;
if ( error )
* error = V_23 ;
return V_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_38 ,
struct V_39 * V_40 )
{
F_9 ( ! V_40 ) ;
return F_1 ( V_2 ,
V_2 -> V_41 + ( 2 * V_38 * V_42 ) , V_40 ,
2 * V_42 , 0 ) ;
}
static void F_17 ( struct V_1 * V_43 , struct V_44 * V_45 ,
int V_46 )
{
char V_47 [ 32 ] ;
struct V_44 * V_48 ;
if ( ! V_45 )
return;
snprintf ( V_47 , 32 , L_2 , V_46 ) ;
V_48 = F_18 ( V_47 , V_45 ) ;
if ( F_19 ( V_48 ) )
return;
V_43 -> V_49 = V_48 ;
F_20 ( L_3 , V_50 , V_48 , & V_43 -> V_51 ) ;
F_20 ( L_4 , V_50 , V_48 ,
& V_43 -> V_52 ) ;
F_21 ( L_5 , V_50 , V_48 , & V_43 -> V_53 ) ;
F_22 ( L_6 , V_50 , V_48 ,
& V_43 -> V_54 ) ;
F_21 ( L_7 , V_50 , V_48 , & V_43 -> V_21 ) ;
F_22 ( L_8 , V_50 , V_48 ,
& V_43 -> V_55 ) ;
F_22 ( L_9 , V_50 , V_48 , & V_43 -> V_56 ) ;
F_23 ( L_10 , V_50 , V_48 , & V_43 -> V_57 ) ;
F_23 ( L_11 , V_50 , V_48 , & V_43 -> V_58 ) ;
F_20 ( L_12 , V_50 , V_48 , & V_43 -> V_59 ) ;
F_20 ( L_13 , V_50 , V_48 , & V_43 -> V_14 ) ;
F_20 ( L_14 , V_50 , V_48 , & V_43 -> V_60 ) ;
F_20 ( L_15 , V_50 , V_48 , & V_43 -> V_19 ) ;
F_20 ( L_16 , V_50 , V_48 , & V_43 -> V_41 ) ;
F_20 ( L_17 , V_50 , V_48 , & V_43 -> V_15 ) ;
F_21 ( L_18 , V_50 , V_48 , & V_43 -> V_6 ) ;
}
static void F_24 ( struct V_61 * V_61 )
{
int V_62 = 0 ;
struct V_1 * V_2 ;
V_61 -> V_49 = F_18 ( F_25 ( & V_61 -> V_7 -> V_63 ) ,
V_64 ) ;
if ( F_19 ( V_61 -> V_49 ) )
return;
F_26 (arena, &btt->arena_list, list) {
F_17 ( V_2 , V_61 -> V_49 , V_62 ) ;
V_62 ++ ;
}
}
static int F_27 ( struct V_39 * V_40 )
{
int V_65 ;
if ( V_40 [ 0 ] . V_66 == 0 ) {
V_40 [ 0 ] . V_66 = F_13 ( 1 ) ;
return 0 ;
}
if ( V_40 [ 0 ] . V_66 == V_40 [ 1 ] . V_66 )
return - V_67 ;
if ( F_15 ( V_40 [ 0 ] . V_66 ) + F_15 ( V_40 [ 1 ] . V_66 ) > 5 )
return - V_67 ;
if ( F_15 ( V_40 [ 0 ] . V_66 ) < F_15 ( V_40 [ 1 ] . V_66 ) ) {
if ( F_15 ( V_40 [ 1 ] . V_66 ) - F_15 ( V_40 [ 0 ] . V_66 ) == 1 )
V_65 = 0 ;
else
V_65 = 1 ;
} else {
if ( F_15 ( V_40 [ 0 ] . V_66 ) - F_15 ( V_40 [ 1 ] . V_66 ) == 1 )
V_65 = 1 ;
else
V_65 = 0 ;
}
return V_65 ;
}
static struct V_68 * F_28 ( struct V_1 * V_2 )
{
return & V_2 -> V_7 -> V_63 ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_38 ,
struct V_39 * V_40 , int V_69 )
{
int V_13 ;
int V_70 , V_71 ;
struct V_39 log [ 2 ] ;
V_13 = F_16 ( V_2 , V_38 , log ) ;
if ( V_13 )
return - V_31 ;
V_70 = F_27 ( log ) ;
if ( V_70 < 0 || V_70 > 1 ) {
F_30 ( F_28 ( V_2 ) ,
L_19 ,
V_70 , V_38 , log [ 0 ] . V_66 , log [ 1 ] . V_66 ) ;
return - V_31 ;
}
V_71 = ( V_69 ? V_70 : ( 1 - V_70 ) ) ;
if ( V_40 != NULL )
memcpy ( V_40 , & log [ V_71 ] , V_42 ) ;
return V_71 ;
}
static int F_31 ( struct V_1 * V_2 , T_3 V_38 ,
T_3 V_72 , struct V_39 * V_40 , unsigned long V_6 )
{
int V_13 ;
unsigned int V_73 = ( V_42 - 2 * sizeof( T_5 ) ) / 2 ;
T_5 V_18 = V_2 -> V_41 + ( ( ( 2 * V_38 ) + V_72 ) * V_42 ) ;
void * V_74 = V_40 ;
V_13 = F_3 ( V_2 , V_18 , V_74 , V_73 , V_6 ) ;
if ( V_13 )
return V_13 ;
V_18 += V_73 ;
V_74 += V_73 ;
return F_3 ( V_2 , V_18 , V_74 , V_73 , V_6 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_3 V_38 , T_3 V_72 ,
struct V_39 * V_40 )
{
int V_13 ;
V_13 = F_31 ( V_2 , V_38 , V_72 , V_40 , V_75 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_76 [ V_38 ] . V_72 = 1 - V_2 -> V_76 [ V_38 ] . V_72 ;
if ( ++ ( V_2 -> V_76 [ V_38 ] . V_66 ) == 4 )
V_2 -> V_76 [ V_38 ] . V_66 = 1 ;
V_2 -> V_76 [ V_38 ] . V_77 = F_15 ( V_40 -> V_78 ) ;
return V_13 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_13 = - V_67 ;
void * V_79 ;
T_2 V_3 = 0 ;
T_2 V_80 = V_81 ;
T_2 V_82 = V_2 -> V_41 - V_2 -> V_19 ;
V_79 = F_34 ( V_80 , V_83 ) ;
if ( ! V_79 )
return - V_84 ;
F_6 ( ! F_7 ( V_2 -> V_19 , 512 ) ) ;
while ( V_82 ) {
T_2 V_51 = F_35 ( V_82 , V_80 ) ;
F_6 ( V_51 < 512 ) ;
V_13 = F_3 ( V_2 , V_2 -> V_19 + V_3 , V_79 ,
V_51 , 0 ) ;
if ( V_13 )
goto free;
V_3 += V_51 ;
V_82 -= V_51 ;
F_36 () ;
}
free:
F_37 ( V_79 ) ;
return V_13 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_2 V_85 = V_2 -> V_15 - V_2 -> V_41 ;
T_2 V_80 = V_10 , V_3 = 0 ;
struct V_39 log ;
void * V_79 ;
int V_13 ;
T_3 V_62 ;
V_79 = F_34 ( V_80 , V_83 ) ;
if ( ! V_79 )
return - V_84 ;
F_6 ( ! F_7 ( V_2 -> V_41 , 512 ) ) ;
while ( V_85 ) {
T_2 V_51 = F_35 ( V_85 , V_80 ) ;
F_6 ( V_51 < 512 ) ;
V_13 = F_3 ( V_2 , V_2 -> V_41 + V_3 , V_79 ,
V_51 , 0 ) ;
if ( V_13 )
goto free;
V_3 += V_51 ;
V_85 -= V_51 ;
F_36 () ;
}
for ( V_62 = 0 ; V_62 < V_2 -> V_56 ; V_62 ++ ) {
log . V_16 = F_13 ( V_62 ) ;
log . V_78 = F_13 ( V_2 -> V_21 + V_62 ) ;
log . V_86 = F_13 ( V_2 -> V_21 + V_62 ) ;
log . V_66 = F_13 ( V_87 ) ;
V_13 = F_31 ( V_2 , V_62 , 0 , & log , 0 ) ;
if ( V_13 )
goto free;
}
free:
F_37 ( V_79 ) ;
return V_13 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_65 , V_88 , V_13 ;
T_3 V_62 , V_89 ;
struct V_39 V_90 , V_91 ;
V_2 -> V_76 = F_40 ( V_2 -> V_56 , sizeof( struct V_92 ) ,
V_83 ) ;
if ( ! V_2 -> V_76 )
return - V_84 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_56 ; V_62 ++ ) {
V_65 = F_29 ( V_2 , V_62 , & V_91 , V_93 ) ;
if ( V_65 < 0 )
return V_65 ;
V_88 = F_29 ( V_2 , V_62 , & V_90 , V_94 ) ;
if ( V_88 < 0 )
return V_88 ;
V_2 -> V_76 [ V_62 ] . V_72 = 1 - V_88 ;
V_2 -> V_76 [ V_62 ] . V_66 = F_41 ( F_15 ( V_90 . V_66 ) ) ;
V_2 -> V_76 [ V_62 ] . V_77 = F_15 ( V_90 . V_78 ) ;
if ( V_90 . V_78 == V_90 . V_86 )
continue;
V_13 = F_14 ( V_2 , F_15 ( V_90 . V_16 ) , & V_89 ,
NULL , NULL , 0 ) ;
if ( V_13 )
return V_13 ;
if ( ( F_15 ( V_90 . V_86 ) != V_89 ) &&
( F_15 ( V_90 . V_78 ) == V_89 ) ) {
V_13 = F_11 ( V_2 , F_15 ( V_90 . V_16 ) ,
F_15 ( V_90 . V_86 ) , 0 , 0 , 0 ) ;
if ( V_13 )
return V_13 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
V_2 -> V_95 = F_40 ( V_2 -> V_56 , sizeof( T_3 ) , V_83 ) ;
if ( V_2 -> V_95 == NULL )
return - V_84 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_3 V_62 ;
V_2 -> V_96 = F_40 ( V_2 -> V_56 , sizeof( struct V_97 ) ,
V_83 ) ;
if ( ! V_2 -> V_96 )
return - V_84 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_56 ; V_62 ++ )
F_44 ( & V_2 -> V_96 [ V_62 ] . V_98 ) ;
return 0 ;
}
static struct V_1 * F_45 ( struct V_61 * V_61 , T_2 V_51 ,
T_2 V_99 , T_2 V_100 )
{
struct V_1 * V_2 ;
T_5 V_85 , V_82 , V_101 ;
T_5 V_102 = V_51 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_83 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_7 = V_61 -> V_7 ;
if ( ! V_51 )
return V_2 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_52 = V_99 ;
V_2 -> V_55 = V_61 -> V_103 ;
V_2 -> V_54 = F_46 ( V_2 -> V_55 ,
V_104 ) ;
V_2 -> V_56 = V_105 ;
V_2 -> V_57 = 1 ;
V_2 -> V_58 = 1 ;
if ( V_102 % V_106 )
V_102 -= ( V_102 % V_106 ) ;
V_102 -= 2 * V_106 ;
V_85 = F_46 ( 2 * V_2 -> V_56 * sizeof( struct V_39 ) ,
V_106 ) ;
V_102 -= V_85 ;
V_2 -> V_53 = F_47 ( V_102 - V_106 ,
V_2 -> V_54 + V_20 ) ;
V_2 -> V_21 = V_2 -> V_53 - V_2 -> V_56 ;
V_82 = F_46 ( ( V_2 -> V_21 * V_20 ) , V_106 ) ;
V_101 = V_102 - V_82 ;
V_2 -> V_14 = V_100 ;
V_2 -> V_60 = V_2 -> V_14 + V_106 ;
V_2 -> V_19 = V_2 -> V_60 + V_101 ;
V_2 -> V_41 = V_2 -> V_19 + V_82 ;
V_2 -> V_15 = V_2 -> V_41 + V_85 ;
return V_2 ;
}
static void F_48 ( struct V_61 * V_61 )
{
struct V_1 * V_2 , * V_107 ;
F_49 (arena, next, &btt->arena_list, list) {
F_50 ( & V_2 -> V_108 ) ;
F_37 ( V_2 -> V_95 ) ;
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_76 ) ;
F_51 ( V_2 -> V_49 ) ;
F_37 ( V_2 ) ;
}
}
static void F_52 ( struct V_1 * V_2 , struct V_11 * V_12 ,
T_5 V_100 )
{
V_2 -> V_53 = F_15 ( V_12 -> V_53 ) ;
V_2 -> V_54 = F_15 ( V_12 -> V_54 ) ;
V_2 -> V_21 = F_15 ( V_12 -> V_21 ) ;
V_2 -> V_55 = F_15 ( V_12 -> V_55 ) ;
V_2 -> V_56 = F_15 ( V_12 -> V_56 ) ;
V_2 -> V_57 = F_53 ( V_12 -> V_57 ) ;
V_2 -> V_58 = F_53 ( V_12 -> V_58 ) ;
V_2 -> V_59 = ( V_12 -> V_59 == 0 ) ? 0 : ( V_100 +
F_54 ( V_12 -> V_59 ) ) ;
V_2 -> V_14 = V_100 ;
V_2 -> V_60 = V_100 + F_54 ( V_12 -> V_60 ) ;
V_2 -> V_19 = V_100 + F_54 ( V_12 -> V_19 ) ;
V_2 -> V_41 = V_100 + F_54 ( V_12 -> V_41 ) ;
V_2 -> V_15 = V_100 + F_54 ( V_12 -> V_15 ) ;
V_2 -> V_51 = ( F_54 ( V_12 -> V_59 ) > 0 )
? ( F_54 ( V_12 -> V_59 ) )
: ( V_2 -> V_15 - V_2 -> V_14 + V_106 ) ;
V_2 -> V_6 = F_15 ( V_12 -> V_6 ) ;
}
static int F_55 ( struct V_61 * V_61 )
{
int V_13 = 0 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
T_2 V_109 = V_61 -> V_110 ;
T_5 V_111 = 0 ;
T_2 V_112 = 0 ;
int V_113 = 0 ;
V_12 = F_34 ( sizeof( * V_12 ) , V_83 ) ;
if ( ! V_12 )
return - V_84 ;
while ( V_109 ) {
V_2 = F_45 ( V_61 , 0 , 0 , 0 ) ;
if ( ! V_2 ) {
V_13 = - V_84 ;
goto V_114;
}
V_2 -> V_14 = V_112 ;
V_13 = F_8 ( V_2 , V_12 ) ;
if ( V_13 )
goto V_115;
if ( ! F_56 ( V_61 -> V_7 , V_12 ) ) {
if ( V_109 == V_61 -> V_110 ) {
V_61 -> V_116 = V_117 ;
F_30 ( F_28 ( V_2 ) , L_20 ) ;
goto V_115;
} else {
F_30 ( F_28 ( V_2 ) ,
L_21 ) ;
V_13 = - V_118 ;
goto V_115;
}
}
V_2 -> V_52 = V_111 ;
F_52 ( V_2 , V_12 , V_112 ) ;
V_13 = F_39 ( V_2 ) ;
if ( V_13 )
goto V_115;
V_13 = F_42 ( V_2 ) ;
if ( V_13 )
goto V_115;
V_13 = F_43 ( V_2 ) ;
if ( V_13 )
goto V_115;
F_57 ( & V_2 -> V_108 , & V_61 -> V_119 ) ;
V_109 -= V_2 -> V_51 ;
V_112 += V_2 -> V_51 ;
V_111 += V_2 -> V_21 ;
V_113 ++ ;
if ( V_2 -> V_59 == 0 )
break;
}
V_61 -> V_113 = V_113 ;
V_61 -> V_120 = V_111 ;
V_61 -> V_116 = V_121 ;
F_37 ( V_12 ) ;
return V_13 ;
V_115:
F_37 ( V_2 ) ;
F_48 ( V_61 ) ;
V_114:
F_37 ( V_12 ) ;
return V_13 ;
}
static int F_58 ( struct V_61 * V_61 )
{
T_2 V_109 = V_61 -> V_110 ;
T_2 V_112 = 0 ;
while ( V_109 ) {
struct V_1 * V_2 ;
T_2 V_122 = F_59 ( T_5 , V_123 , V_109 ) ;
V_109 -= V_122 ;
if ( V_122 < V_124 )
break;
V_2 = F_45 ( V_61 , V_122 , V_61 -> V_120 , V_112 ) ;
if ( ! V_2 ) {
F_48 ( V_61 ) ;
return - V_84 ;
}
V_61 -> V_120 += V_2 -> V_21 ;
if ( V_109 >= V_124 )
V_2 -> V_59 = V_2 -> V_51 ;
else
V_2 -> V_59 = 0 ;
V_112 += V_122 ;
F_57 ( & V_2 -> V_108 , & V_61 -> V_119 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_13 ;
T_5 V_125 ;
struct V_11 * V_12 ;
struct V_7 * V_7 = V_2 -> V_7 ;
const T_6 * V_126 = F_61 ( & V_7 -> V_9 -> V_63 ) ;
V_13 = F_33 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_38 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_12 = F_34 ( sizeof( struct V_11 ) , V_127 ) ;
if ( ! V_12 )
return - V_84 ;
strncpy ( V_12 -> V_128 , V_129 , V_130 ) ;
memcpy ( V_12 -> V_131 , V_7 -> V_131 , 16 ) ;
memcpy ( V_12 -> V_126 , V_126 , 16 ) ;
V_12 -> V_6 = F_13 ( V_2 -> V_6 ) ;
V_12 -> V_57 = F_62 ( V_2 -> V_57 ) ;
V_12 -> V_58 = F_62 ( V_2 -> V_58 ) ;
V_12 -> V_55 = F_13 ( V_2 -> V_55 ) ;
V_12 -> V_21 = F_13 ( V_2 -> V_21 ) ;
V_12 -> V_54 = F_13 ( V_2 -> V_54 ) ;
V_12 -> V_53 = F_13 ( V_2 -> V_53 ) ;
V_12 -> V_56 = F_13 ( V_2 -> V_56 ) ;
V_12 -> V_132 = F_13 ( sizeof( struct V_11 ) ) ;
V_12 -> V_59 = F_63 ( V_2 -> V_59 ) ;
V_12 -> V_60 = F_63 ( V_2 -> V_60 - V_2 -> V_14 ) ;
V_12 -> V_19 = F_63 ( V_2 -> V_19 - V_2 -> V_14 ) ;
V_12 -> V_41 = F_63 ( V_2 -> V_41 - V_2 -> V_14 ) ;
V_12 -> V_15 = F_63 ( V_2 -> V_15 - V_2 -> V_14 ) ;
V_12 -> V_6 = 0 ;
V_125 = F_64 ( (struct V_133 * ) V_12 ) ;
V_12 -> V_134 = F_63 ( V_125 ) ;
V_13 = F_5 ( V_2 , V_12 ) ;
F_37 ( V_12 ) ;
return V_13 ;
}
static int F_65 ( struct V_61 * V_61 )
{
int V_13 = 0 ;
struct V_1 * V_2 ;
F_66 ( & V_61 -> V_135 ) ;
F_26 (arena, &btt->arena_list, list) {
V_13 = F_60 ( V_2 ) ;
if ( V_13 )
goto V_136;
V_13 = F_39 ( V_2 ) ;
if ( V_13 )
goto V_136;
V_13 = F_42 ( V_2 ) ;
if ( V_13 )
goto V_136;
V_13 = F_43 ( V_2 ) ;
if ( V_13 )
goto V_136;
}
V_61 -> V_116 = V_121 ;
V_136:
F_67 ( & V_61 -> V_135 ) ;
return V_13 ;
}
static T_3 F_68 ( struct V_61 * V_61 )
{
return V_61 -> V_103 - V_61 -> V_137 ;
}
static int F_69 ( struct V_61 * V_61 , T_7 V_138 , T_8 * V_139 ,
struct V_1 * * V_2 )
{
struct V_1 * V_119 ;
T_9 V_16 = F_47 ( V_138 << V_140 , V_61 -> V_137 ) ;
F_26 (arena_list, &btt->arena_list, list) {
if ( V_16 < V_119 -> V_21 ) {
* V_2 = V_119 ;
* V_139 = V_16 ;
return 0 ;
}
V_16 -= V_119 -> V_21 ;
}
return - V_31 ;
}
static void F_70 ( struct V_1 * V_2 , T_3 V_139 )
__acquires( &arena->map_locks[idx].lock
static void F_71 ( struct V_1 * V_2 , T_3 V_139 )
__releases( &arena->map_locks[idx].lock
static T_5 F_72 ( struct V_1 * V_2 , T_5 V_16 )
{
return V_2 -> V_60 + ( ( T_5 ) V_16 * V_2 -> V_54 ) ;
}
static int F_73 ( struct V_1 * V_2 , struct V_141 * V_141 ,
unsigned int V_142 , T_3 V_16 , T_3 V_143 )
{
int V_13 ;
T_5 V_144 = F_72 ( V_2 , V_16 ) ;
void * V_145 = F_74 ( V_141 ) ;
V_13 = F_1 ( V_2 , V_144 , V_145 + V_142 , V_143 , V_75 ) ;
F_75 ( V_145 ) ;
return V_13 ;
}
static int F_76 ( struct V_1 * V_2 , T_3 V_16 ,
struct V_141 * V_141 , unsigned int V_142 , T_3 V_143 )
{
int V_13 ;
T_5 V_144 = F_72 ( V_2 , V_16 ) ;
void * V_145 = F_74 ( V_141 ) ;
V_13 = F_3 ( V_2 , V_144 , V_145 + V_142 , V_143 , V_75 ) ;
F_75 ( V_145 ) ;
return V_13 ;
}
static void F_77 ( struct V_141 * V_141 , unsigned int V_142 , T_3 V_143 )
{
void * V_145 = F_74 ( V_141 ) ;
memset ( V_145 + V_142 , 0 , V_143 ) ;
F_75 ( V_145 ) ;
}
static int F_78 ( struct V_61 * V_61 , struct V_146 * V_147 ,
struct V_1 * V_2 , T_3 V_35 , int V_148 )
{
unsigned int V_143 = F_68 ( V_61 ) ;
T_5 V_149 ;
int V_13 = 0 ;
if ( V_147 == NULL )
return 0 ;
V_149 = F_72 ( V_2 , V_35 ) + V_61 -> V_137 ;
while ( V_143 ) {
unsigned int V_150 ;
struct V_151 V_152 ;
void * V_145 ;
V_152 = F_79 ( V_147 -> V_153 , V_147 -> V_154 ) ;
V_150 = F_35 ( V_143 , V_152 . V_155 ) ;
V_145 = F_74 ( V_152 . V_156 ) ;
if ( V_148 )
V_13 = F_3 ( V_2 , V_149 ,
V_145 + V_152 . V_157 , V_150 ,
V_75 ) ;
else
V_13 = F_1 ( V_2 , V_149 ,
V_145 + V_152 . V_157 , V_150 ,
V_75 ) ;
F_75 ( V_145 ) ;
if ( V_13 )
return V_13 ;
V_143 -= V_150 ;
V_149 += V_150 ;
F_80 ( V_147 -> V_153 , & V_147 -> V_154 , V_150 ) ;
}
return V_13 ;
}
static int F_78 ( struct V_61 * V_61 , struct V_146 * V_147 ,
struct V_1 * V_2 , T_3 V_35 , int V_148 )
{
return 0 ;
}
static int F_81 ( struct V_61 * V_61 , struct V_146 * V_147 ,
struct V_141 * V_141 , unsigned int V_142 , T_7 V_138 ,
unsigned int V_143 )
{
int V_13 = 0 ;
int V_158 , V_23 ;
struct V_1 * V_2 = NULL ;
T_3 V_38 = 0 , V_139 , V_35 ;
while ( V_143 ) {
T_3 V_150 ;
V_38 = F_82 ( V_61 -> V_159 ) ;
V_13 = F_69 ( V_61 , V_138 , & V_139 , & V_2 ) ;
if ( V_13 )
goto V_160;
V_150 = F_35 ( V_61 -> V_137 , V_143 ) ;
V_13 = F_14 ( V_2 , V_139 , & V_35 , & V_158 , & V_23 ,
V_75 ) ;
if ( V_13 )
goto V_160;
while ( 1 ) {
T_3 V_86 ;
if ( V_158 ) {
F_77 ( V_141 , V_142 , V_150 ) ;
goto V_160;
}
if ( V_23 ) {
V_13 = - V_31 ;
goto V_160;
}
V_2 -> V_95 [ V_38 ] = V_161 | V_35 ;
F_83 () ;
V_13 = F_14 ( V_2 , V_139 , & V_86 , & V_158 ,
& V_23 , V_75 ) ;
if ( V_13 )
goto V_162;
if ( V_35 == V_86 )
break;
V_35 = V_86 ;
}
V_13 = F_73 ( V_2 , V_141 , V_142 , V_35 , V_150 ) ;
if ( V_13 )
goto V_162;
if ( V_147 ) {
V_13 = F_78 ( V_61 , V_147 , V_2 , V_35 , V_163 ) ;
if ( V_13 )
goto V_162;
}
V_2 -> V_95 [ V_38 ] = V_164 ;
F_84 ( V_61 -> V_159 , V_38 ) ;
V_143 -= V_150 ;
V_142 += V_150 ;
V_138 += V_61 -> V_137 >> V_140 ;
}
return 0 ;
V_162:
V_2 -> V_95 [ V_38 ] = V_164 ;
V_160:
F_84 ( V_61 -> V_159 , V_38 ) ;
return V_13 ;
}
static int F_85 ( struct V_61 * V_61 , struct V_146 * V_147 ,
T_7 V_138 , struct V_141 * V_141 , unsigned int V_142 ,
unsigned int V_143 )
{
int V_13 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_139 = 0 , V_165 , V_166 , V_38 = 0 , V_62 ;
struct V_39 log ;
int V_72 ;
while ( V_143 ) {
T_3 V_150 ;
V_38 = F_82 ( V_61 -> V_159 ) ;
V_13 = F_69 ( V_61 , V_138 , & V_139 , & V_2 ) ;
if ( V_13 )
goto V_160;
V_150 = F_35 ( V_61 -> V_137 , V_143 ) ;
if ( ( V_2 -> V_6 & V_167 ) != 0 ) {
V_13 = - V_31 ;
goto V_160;
}
V_166 = V_2 -> V_76 [ V_38 ] . V_77 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_56 ; V_62 ++ )
while ( V_2 -> V_95 [ V_62 ] == ( V_161 | V_166 ) )
F_86 () ;
if ( V_166 >= V_2 -> V_53 ) {
V_13 = - V_31 ;
goto V_160;
}
V_13 = F_76 ( V_2 , V_166 , V_141 , V_142 , V_150 ) ;
if ( V_13 )
goto V_160;
if ( V_147 ) {
V_13 = F_78 ( V_61 , V_147 , V_2 , V_166 ,
V_168 ) ;
if ( V_13 )
goto V_160;
}
F_70 ( V_2 , V_139 ) ;
V_13 = F_14 ( V_2 , V_139 , & V_165 , NULL , NULL ,
V_75 ) ;
if ( V_13 )
goto V_169;
if ( V_165 >= V_2 -> V_53 ) {
V_13 = - V_31 ;
goto V_169;
}
log . V_16 = F_13 ( V_139 ) ;
log . V_78 = F_13 ( V_165 ) ;
log . V_86 = F_13 ( V_166 ) ;
log . V_66 = F_13 ( V_2 -> V_76 [ V_38 ] . V_66 ) ;
V_72 = V_2 -> V_76 [ V_38 ] . V_72 ;
V_13 = F_32 ( V_2 , V_38 , V_72 , & log ) ;
if ( V_13 )
goto V_169;
V_13 = F_11 ( V_2 , V_139 , V_166 , 0 , 0 , 0 ) ;
if ( V_13 )
goto V_169;
F_71 ( V_2 , V_139 ) ;
F_84 ( V_61 -> V_159 , V_38 ) ;
V_143 -= V_150 ;
V_142 += V_150 ;
V_138 += V_61 -> V_137 >> V_140 ;
}
return 0 ;
V_169:
F_71 ( V_2 , V_139 ) ;
V_160:
F_84 ( V_61 -> V_159 , V_38 ) ;
return V_13 ;
}
static int F_87 ( struct V_61 * V_61 , struct V_146 * V_147 ,
struct V_141 * V_141 , unsigned int V_143 , unsigned int V_142 ,
bool V_170 , T_7 V_138 )
{
int V_13 ;
if ( ! V_170 ) {
V_13 = F_81 ( V_61 , V_147 , V_141 , V_142 , V_138 , V_143 ) ;
F_88 ( V_141 ) ;
} else {
F_88 ( V_141 ) ;
V_13 = F_85 ( V_61 , V_147 , V_138 , V_141 , V_142 , V_143 ) ;
}
return V_13 ;
}
static T_10 F_89 ( struct V_171 * V_172 , struct V_173 * V_173 )
{
struct V_146 * V_147 = F_90 ( V_173 ) ;
struct V_61 * V_61 = V_172 -> V_174 ;
struct V_175 V_176 ;
unsigned long V_99 ;
struct V_151 V_177 ;
int V_178 = 0 ;
bool V_179 ;
if ( F_91 ( V_173 ) && F_92 ( V_173 ) ) {
V_173 -> V_180 = - V_31 ;
goto V_115;
}
V_179 = F_93 ( V_173 , & V_99 ) ;
F_94 (bvec, bio, iter) {
unsigned int V_143 = V_177 . V_155 ;
F_95 ( V_143 > V_181 ) ;
F_95 ( V_143 < V_61 -> V_137 ) ;
F_95 ( V_143 % V_61 -> V_137 ) ;
V_178 = F_87 ( V_61 , V_147 , V_177 . V_156 , V_143 , V_177 . V_157 ,
F_96 ( F_97 ( V_173 ) ) , V_176 . V_182 ) ;
if ( V_178 ) {
F_30 ( & V_61 -> V_7 -> V_63 ,
L_22 ,
( F_96 ( F_97 ( V_173 ) ) ) ? L_23 :
L_24 ,
( unsigned long long ) V_176 . V_182 , V_143 ) ;
V_173 -> V_180 = V_178 ;
break;
}
}
if ( V_179 )
F_98 ( V_173 , V_99 ) ;
V_115:
F_99 ( V_173 ) ;
return V_183 ;
}
static int F_100 ( struct V_184 * V_185 , T_7 V_138 ,
struct V_141 * V_141 , bool V_170 )
{
struct V_61 * V_61 = V_185 -> V_186 -> V_187 ;
F_87 ( V_61 , NULL , V_141 , V_181 , 0 , V_170 , V_138 ) ;
F_101 ( V_141 , V_170 , 0 ) ;
return 0 ;
}
static int F_102 ( struct V_184 * V_188 , struct V_189 * V_190 )
{
V_190 -> V_191 = 1 << 6 ;
V_190 -> V_192 = 1 << 5 ;
V_190 -> V_193 = F_103 ( V_188 -> V_186 ) >> 11 ;
return 0 ;
}
static int F_104 ( struct V_61 * V_61 )
{
struct V_7 * V_7 = V_61 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_61 -> V_194 = F_105 ( V_83 ) ;
if ( ! V_61 -> V_194 )
return - V_84 ;
V_61 -> V_195 = F_106 ( 0 ) ;
if ( ! V_61 -> V_195 ) {
F_107 ( V_61 -> V_194 ) ;
return - V_84 ;
}
F_108 ( V_9 , V_61 -> V_195 -> V_196 ) ;
V_61 -> V_195 -> V_197 = 0 ;
V_61 -> V_195 -> V_198 = & V_199 ;
V_61 -> V_195 -> V_187 = V_61 ;
V_61 -> V_195 -> V_200 = V_61 -> V_194 ;
V_61 -> V_195 -> V_6 = V_201 ;
F_109 ( V_61 -> V_194 , F_89 ) ;
F_110 ( V_61 -> V_194 , V_61 -> V_137 ) ;
F_111 ( V_61 -> V_194 , V_202 ) ;
F_112 ( V_61 -> V_194 , V_203 ) ;
F_113 ( V_204 , V_61 -> V_194 ) ;
V_61 -> V_194 -> V_174 = V_61 ;
F_114 ( V_61 -> V_195 , 0 ) ;
F_115 ( & V_61 -> V_7 -> V_63 , V_61 -> V_195 ) ;
if ( F_68 ( V_61 ) ) {
int V_205 = F_116 ( V_61 -> V_195 , F_68 ( V_61 ) ) ;
if ( V_205 ) {
F_117 ( V_61 -> V_195 ) ;
F_118 ( V_61 -> V_195 ) ;
F_107 ( V_61 -> V_194 ) ;
return V_205 ;
}
}
F_114 ( V_61 -> V_195 , V_61 -> V_120 * V_61 -> V_137 >> 9 ) ;
V_61 -> V_7 -> V_51 = V_61 -> V_120 * ( T_5 ) V_61 -> V_137 ;
F_119 ( V_61 -> V_195 ) ;
return 0 ;
}
static void F_120 ( struct V_61 * V_61 )
{
F_117 ( V_61 -> V_195 ) ;
F_118 ( V_61 -> V_195 ) ;
F_107 ( V_61 -> V_194 ) ;
}
static struct V_61 * F_121 ( struct V_7 * V_7 , unsigned long long V_110 ,
T_3 V_103 , T_6 * V_131 , struct V_159 * V_159 )
{
int V_13 ;
struct V_61 * V_61 ;
struct V_68 * V_63 = & V_7 -> V_63 ;
V_61 = F_122 ( V_63 , sizeof( struct V_61 ) , V_83 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_7 = V_7 ;
V_61 -> V_110 = V_110 ;
V_61 -> V_103 = V_103 ;
V_61 -> V_137 = ( ( V_103 >= 4096 ) ? 4096 : 512 ) ;
F_123 ( & V_61 -> V_119 ) ;
F_124 ( & V_61 -> V_135 ) ;
V_61 -> V_159 = V_159 ;
V_13 = F_55 ( V_61 ) ;
if ( V_13 ) {
F_125 ( V_63 , L_25 , V_13 ) ;
return NULL ;
}
if ( V_61 -> V_116 != V_121 && V_159 -> V_206 ) {
F_30 ( V_63 , L_26 ,
F_25 ( & V_159 -> V_63 ) ) ;
return NULL ;
} else if ( V_61 -> V_116 != V_121 ) {
V_61 -> V_113 = ( V_110 / V_123 ) +
( ( V_110 % V_123 ) ? 1 : 0 ) ;
F_126 ( V_63 , L_27 ,
V_61 -> V_113 , V_110 ) ;
V_13 = F_58 ( V_61 ) ;
if ( V_13 ) {
F_30 ( V_63 , L_28 , V_13 ) ;
return NULL ;
}
V_13 = F_65 ( V_61 ) ;
if ( V_13 ) {
F_125 ( V_63 , L_29 , V_13 ) ;
return NULL ;
}
}
V_13 = F_104 ( V_61 ) ;
if ( V_13 ) {
F_125 ( V_63 , L_30 , V_13 ) ;
return NULL ;
}
F_24 ( V_61 ) ;
return V_61 ;
}
static void F_127 ( struct V_61 * V_61 )
{
if ( V_61 ) {
F_120 ( V_61 ) ;
F_48 ( V_61 ) ;
F_51 ( V_61 -> V_49 ) ;
}
}
int F_128 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_129 ( V_9 -> V_207 ) ;
struct V_159 * V_159 ;
struct V_61 * V_61 ;
T_2 V_110 ;
if ( ! V_7 -> V_131 || ! V_7 -> V_9 || ! V_7 -> V_103 ) {
F_126 ( & V_7 -> V_63 , L_31 ) ;
return - V_118 ;
}
V_110 = F_130 ( V_9 ) - V_10 ;
if ( V_110 < V_124 ) {
F_126 ( & V_7 -> V_63 , L_32 ,
F_25 ( & V_9 -> V_63 ) , V_124 + V_10 ) ;
return - V_208 ;
}
V_159 = F_131 ( V_7 -> V_63 . V_45 ) ;
V_61 = F_121 ( V_7 , V_110 , V_7 -> V_103 , V_7 -> V_131 ,
V_159 ) ;
if ( ! V_61 )
return - V_84 ;
V_7 -> V_61 = V_61 ;
return 0 ;
}
int F_132 ( struct V_7 * V_7 )
{
struct V_61 * V_61 = V_7 -> V_61 ;
F_127 ( V_61 ) ;
V_7 -> V_61 = NULL ;
return 0 ;
}
static int T_11 F_133 ( void )
{
int V_205 = 0 ;
V_64 = F_18 ( L_33 , NULL ) ;
if ( F_19 ( V_64 ) )
V_205 = - V_208 ;
return V_205 ;
}
static void T_12 F_134 ( void )
{
F_51 ( V_64 ) ;
}
