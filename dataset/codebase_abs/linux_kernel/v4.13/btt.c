static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned long V_6 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_3 += V_2 -> V_7 -> V_10 ;
return F_2 ( V_9 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned long V_6 )
{
struct V_7 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_3 += V_2 -> V_7 -> V_10 ;
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
T_2 V_80 = V_86 , V_3 = 0 ;
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
log . V_87 = F_13 ( V_2 -> V_21 + V_62 ) ;
log . V_66 = F_13 ( V_88 ) ;
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
int V_65 , V_89 , V_13 ;
T_3 V_62 , V_90 ;
struct V_39 V_91 , V_92 ;
V_2 -> V_76 = F_40 ( V_2 -> V_56 , sizeof( struct V_93 ) ,
V_83 ) ;
if ( ! V_2 -> V_76 )
return - V_84 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_56 ; V_62 ++ ) {
V_65 = F_29 ( V_2 , V_62 , & V_92 , V_94 ) ;
if ( V_65 < 0 )
return V_65 ;
V_89 = F_29 ( V_2 , V_62 , & V_91 , V_95 ) ;
if ( V_89 < 0 )
return V_89 ;
V_2 -> V_76 [ V_62 ] . V_72 = 1 - V_89 ;
V_2 -> V_76 [ V_62 ] . V_66 = F_41 ( F_15 ( V_91 . V_66 ) ) ;
V_2 -> V_76 [ V_62 ] . V_77 = F_15 ( V_91 . V_78 ) ;
if ( V_91 . V_78 == V_91 . V_87 )
continue;
V_13 = F_14 ( V_2 , F_15 ( V_91 . V_16 ) , & V_90 ,
NULL , NULL , 0 ) ;
if ( V_13 )
return V_13 ;
if ( ( F_15 ( V_91 . V_87 ) != V_90 ) &&
( F_15 ( V_91 . V_78 ) == V_90 ) ) {
V_13 = F_11 ( V_2 , F_15 ( V_91 . V_16 ) ,
F_15 ( V_91 . V_87 ) , 0 , 0 , 0 ) ;
if ( V_13 )
return V_13 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
V_2 -> V_96 = F_40 ( V_2 -> V_56 , sizeof( T_3 ) , V_83 ) ;
if ( V_2 -> V_96 == NULL )
return - V_84 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_3 V_62 ;
V_2 -> V_97 = F_40 ( V_2 -> V_56 , sizeof( struct V_98 ) ,
V_83 ) ;
if ( ! V_2 -> V_97 )
return - V_84 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_56 ; V_62 ++ )
F_44 ( & V_2 -> V_97 [ V_62 ] . V_99 ) ;
return 0 ;
}
static struct V_1 * F_45 ( struct V_61 * V_61 , T_2 V_51 ,
T_2 V_100 , T_2 V_101 )
{
struct V_1 * V_2 ;
T_5 V_85 , V_82 , V_102 ;
T_5 V_103 = V_51 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_83 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_7 = V_61 -> V_7 ;
if ( ! V_51 )
return V_2 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_52 = V_100 ;
V_2 -> V_55 = V_61 -> V_104 ;
V_2 -> V_54 = F_46 ( V_2 -> V_55 ,
V_105 ) ;
V_2 -> V_56 = V_106 ;
V_2 -> V_57 = V_61 -> V_7 -> V_57 ;
V_2 -> V_58 = V_61 -> V_7 -> V_58 ;
if ( V_103 % V_107 )
V_103 -= ( V_103 % V_107 ) ;
V_103 -= 2 * V_107 ;
V_85 = F_46 ( 2 * V_2 -> V_56 * sizeof( struct V_39 ) ,
V_107 ) ;
V_103 -= V_85 ;
V_2 -> V_53 = F_47 ( V_103 - V_107 ,
V_2 -> V_54 + V_20 ) ;
V_2 -> V_21 = V_2 -> V_53 - V_2 -> V_56 ;
V_82 = F_46 ( ( V_2 -> V_21 * V_20 ) , V_107 ) ;
V_102 = V_103 - V_82 ;
V_2 -> V_14 = V_101 ;
V_2 -> V_60 = V_2 -> V_14 + V_107 ;
V_2 -> V_19 = V_2 -> V_60 + V_102 ;
V_2 -> V_41 = V_2 -> V_19 + V_82 ;
V_2 -> V_15 = V_2 -> V_41 + V_85 ;
return V_2 ;
}
static void F_48 ( struct V_61 * V_61 )
{
struct V_1 * V_2 , * V_108 ;
F_49 (arena, next, &btt->arena_list, list) {
F_50 ( & V_2 -> V_109 ) ;
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_97 ) ;
F_37 ( V_2 -> V_76 ) ;
F_51 ( V_2 -> V_49 ) ;
F_37 ( V_2 ) ;
}
}
static void F_52 ( struct V_1 * V_2 , struct V_11 * V_12 ,
T_5 V_101 )
{
V_2 -> V_53 = F_15 ( V_12 -> V_53 ) ;
V_2 -> V_54 = F_15 ( V_12 -> V_54 ) ;
V_2 -> V_21 = F_15 ( V_12 -> V_21 ) ;
V_2 -> V_55 = F_15 ( V_12 -> V_55 ) ;
V_2 -> V_56 = F_15 ( V_12 -> V_56 ) ;
V_2 -> V_57 = F_53 ( V_12 -> V_57 ) ;
V_2 -> V_58 = F_53 ( V_12 -> V_58 ) ;
V_2 -> V_59 = ( V_12 -> V_59 == 0 ) ? 0 : ( V_101 +
F_54 ( V_12 -> V_59 ) ) ;
V_2 -> V_14 = V_101 ;
V_2 -> V_60 = V_101 + F_54 ( V_12 -> V_60 ) ;
V_2 -> V_19 = V_101 + F_54 ( V_12 -> V_19 ) ;
V_2 -> V_41 = V_101 + F_54 ( V_12 -> V_41 ) ;
V_2 -> V_15 = V_101 + F_54 ( V_12 -> V_15 ) ;
V_2 -> V_51 = ( F_54 ( V_12 -> V_59 ) > 0 )
? ( F_54 ( V_12 -> V_59 ) )
: ( V_2 -> V_15 - V_2 -> V_14 + V_107 ) ;
V_2 -> V_6 = F_15 ( V_12 -> V_6 ) ;
}
static int F_55 ( struct V_61 * V_61 )
{
int V_13 = 0 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
T_2 V_110 = V_61 -> V_111 ;
T_5 V_112 = 0 ;
T_2 V_113 = 0 ;
int V_114 = 0 ;
V_12 = F_34 ( sizeof( * V_12 ) , V_83 ) ;
if ( ! V_12 )
return - V_84 ;
while ( V_110 ) {
V_2 = F_45 ( V_61 , 0 , 0 , 0 ) ;
if ( ! V_2 ) {
V_13 = - V_84 ;
goto V_115;
}
V_2 -> V_14 = V_113 ;
V_13 = F_8 ( V_2 , V_12 ) ;
if ( V_13 )
goto V_116;
if ( ! F_56 ( V_61 -> V_7 , V_12 ) ) {
if ( V_110 == V_61 -> V_111 ) {
V_61 -> V_117 = V_118 ;
F_57 ( F_28 ( V_2 ) , L_20 ) ;
goto V_116;
} else {
F_30 ( F_28 ( V_2 ) ,
L_21 ) ;
V_13 = - V_119 ;
goto V_116;
}
}
V_2 -> V_52 = V_112 ;
F_52 ( V_2 , V_12 , V_113 ) ;
V_13 = F_39 ( V_2 ) ;
if ( V_13 )
goto V_116;
V_13 = F_42 ( V_2 ) ;
if ( V_13 )
goto V_116;
V_13 = F_43 ( V_2 ) ;
if ( V_13 )
goto V_116;
F_58 ( & V_2 -> V_109 , & V_61 -> V_120 ) ;
V_110 -= V_2 -> V_51 ;
V_113 += V_2 -> V_51 ;
V_112 += V_2 -> V_21 ;
V_114 ++ ;
if ( V_2 -> V_59 == 0 )
break;
}
V_61 -> V_114 = V_114 ;
V_61 -> V_121 = V_112 ;
V_61 -> V_117 = V_122 ;
F_37 ( V_12 ) ;
return V_13 ;
V_116:
F_37 ( V_2 ) ;
F_48 ( V_61 ) ;
V_115:
F_37 ( V_12 ) ;
return V_13 ;
}
static int F_59 ( struct V_61 * V_61 )
{
T_2 V_110 = V_61 -> V_111 ;
T_2 V_113 = 0 ;
while ( V_110 ) {
struct V_1 * V_2 ;
T_2 V_123 = F_60 ( T_5 , V_124 , V_110 ) ;
V_110 -= V_123 ;
if ( V_123 < V_125 )
break;
V_2 = F_45 ( V_61 , V_123 , V_61 -> V_121 , V_113 ) ;
if ( ! V_2 ) {
F_48 ( V_61 ) ;
return - V_84 ;
}
V_61 -> V_121 += V_2 -> V_21 ;
if ( V_110 >= V_125 )
V_2 -> V_59 = V_2 -> V_51 ;
else
V_2 -> V_59 = 0 ;
V_113 += V_123 ;
F_58 ( & V_2 -> V_109 , & V_61 -> V_120 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_13 ;
T_5 V_126 ;
struct V_11 * V_12 ;
struct V_7 * V_7 = V_2 -> V_7 ;
const T_6 * V_127 = F_62 ( & V_7 -> V_9 -> V_63 ) ;
V_13 = F_33 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_38 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_12 = F_34 ( sizeof( struct V_11 ) , V_128 ) ;
if ( ! V_12 )
return - V_84 ;
strncpy ( V_12 -> V_129 , V_130 , V_131 ) ;
memcpy ( V_12 -> V_132 , V_7 -> V_132 , 16 ) ;
memcpy ( V_12 -> V_127 , V_127 , 16 ) ;
V_12 -> V_6 = F_13 ( V_2 -> V_6 ) ;
V_12 -> V_57 = F_63 ( V_2 -> V_57 ) ;
V_12 -> V_58 = F_63 ( V_2 -> V_58 ) ;
V_12 -> V_55 = F_13 ( V_2 -> V_55 ) ;
V_12 -> V_21 = F_13 ( V_2 -> V_21 ) ;
V_12 -> V_54 = F_13 ( V_2 -> V_54 ) ;
V_12 -> V_53 = F_13 ( V_2 -> V_53 ) ;
V_12 -> V_56 = F_13 ( V_2 -> V_56 ) ;
V_12 -> V_133 = F_13 ( sizeof( struct V_11 ) ) ;
V_12 -> V_59 = F_64 ( V_2 -> V_59 ) ;
V_12 -> V_60 = F_64 ( V_2 -> V_60 - V_2 -> V_14 ) ;
V_12 -> V_19 = F_64 ( V_2 -> V_19 - V_2 -> V_14 ) ;
V_12 -> V_41 = F_64 ( V_2 -> V_41 - V_2 -> V_14 ) ;
V_12 -> V_15 = F_64 ( V_2 -> V_15 - V_2 -> V_14 ) ;
V_12 -> V_6 = 0 ;
V_126 = F_65 ( (struct V_134 * ) V_12 ) ;
V_12 -> V_135 = F_64 ( V_126 ) ;
V_13 = F_5 ( V_2 , V_12 ) ;
F_37 ( V_12 ) ;
return V_13 ;
}
static int F_66 ( struct V_61 * V_61 )
{
int V_13 = 0 ;
struct V_1 * V_2 ;
F_67 ( & V_61 -> V_136 ) ;
F_26 (arena, &btt->arena_list, list) {
V_13 = F_61 ( V_2 ) ;
if ( V_13 )
goto V_137;
V_13 = F_39 ( V_2 ) ;
if ( V_13 )
goto V_137;
V_13 = F_42 ( V_2 ) ;
if ( V_13 )
goto V_137;
V_13 = F_43 ( V_2 ) ;
if ( V_13 )
goto V_137;
}
V_61 -> V_117 = V_122 ;
V_137:
F_68 ( & V_61 -> V_136 ) ;
return V_13 ;
}
static T_3 F_69 ( struct V_61 * V_61 )
{
return V_61 -> V_104 - V_61 -> V_138 ;
}
static int F_70 ( struct V_61 * V_61 , T_7 V_139 , T_8 * V_140 ,
struct V_1 * * V_2 )
{
struct V_1 * V_120 ;
T_9 V_16 = F_47 ( V_139 << V_141 , V_61 -> V_138 ) ;
F_26 (arena_list, &btt->arena_list, list) {
if ( V_16 < V_120 -> V_21 ) {
* V_2 = V_120 ;
* V_140 = V_16 ;
return 0 ;
}
V_16 -= V_120 -> V_21 ;
}
return - V_31 ;
}
static void F_71 ( struct V_1 * V_2 , T_3 V_140 )
__acquires( &arena->map_locks[idx].lock
static void F_72 ( struct V_1 * V_2 , T_3 V_140 )
__releases( &arena->map_locks[idx].lock
static T_5 F_73 ( struct V_1 * V_2 , T_5 V_16 )
{
return V_2 -> V_60 + ( ( T_5 ) V_16 * V_2 -> V_54 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_142 * V_142 ,
unsigned int V_143 , T_3 V_16 , T_3 V_144 )
{
int V_13 ;
T_5 V_145 = F_73 ( V_2 , V_16 ) ;
void * V_146 = F_75 ( V_142 ) ;
V_13 = F_1 ( V_2 , V_145 , V_146 + V_143 , V_144 , V_75 ) ;
F_76 ( V_146 ) ;
return V_13 ;
}
static int F_77 ( struct V_1 * V_2 , T_3 V_16 ,
struct V_142 * V_142 , unsigned int V_143 , T_3 V_144 )
{
int V_13 ;
T_5 V_145 = F_73 ( V_2 , V_16 ) ;
void * V_146 = F_75 ( V_142 ) ;
V_13 = F_3 ( V_2 , V_145 , V_146 + V_143 , V_144 , V_75 ) ;
F_76 ( V_146 ) ;
return V_13 ;
}
static void F_78 ( struct V_142 * V_142 , unsigned int V_143 , T_3 V_144 )
{
void * V_146 = F_75 ( V_142 ) ;
memset ( V_146 + V_143 , 0 , V_144 ) ;
F_76 ( V_146 ) ;
}
static int F_79 ( struct V_61 * V_61 , struct V_147 * V_148 ,
struct V_1 * V_2 , T_3 V_35 , int V_149 )
{
unsigned int V_144 = F_69 ( V_61 ) ;
T_5 V_150 ;
int V_13 = 0 ;
if ( V_148 == NULL )
return 0 ;
V_150 = F_73 ( V_2 , V_35 ) + V_61 -> V_138 ;
while ( V_144 ) {
unsigned int V_151 ;
struct V_152 V_153 ;
void * V_146 ;
V_153 = F_80 ( V_148 -> V_154 , V_148 -> V_155 ) ;
V_151 = F_35 ( V_144 , V_153 . V_156 ) ;
V_146 = F_75 ( V_153 . V_157 ) ;
if ( V_149 )
V_13 = F_3 ( V_2 , V_150 ,
V_146 + V_153 . V_158 , V_151 ,
V_75 ) ;
else
V_13 = F_1 ( V_2 , V_150 ,
V_146 + V_153 . V_158 , V_151 ,
V_75 ) ;
F_76 ( V_146 ) ;
if ( V_13 )
return V_13 ;
V_144 -= V_151 ;
V_150 += V_151 ;
if ( ! F_81 ( V_148 -> V_154 , & V_148 -> V_155 , V_151 ) )
return - V_31 ;
}
return V_13 ;
}
static int F_79 ( struct V_61 * V_61 , struct V_147 * V_148 ,
struct V_1 * V_2 , T_3 V_35 , int V_149 )
{
return 0 ;
}
static int F_82 ( struct V_61 * V_61 , struct V_147 * V_148 ,
struct V_142 * V_142 , unsigned int V_143 , T_7 V_139 ,
unsigned int V_144 )
{
int V_13 = 0 ;
int V_159 , V_23 ;
struct V_1 * V_2 = NULL ;
T_3 V_38 = 0 , V_140 , V_35 ;
while ( V_144 ) {
T_3 V_151 ;
V_38 = F_83 ( V_61 -> V_160 ) ;
V_13 = F_70 ( V_61 , V_139 , & V_140 , & V_2 ) ;
if ( V_13 )
goto V_161;
V_151 = F_35 ( V_61 -> V_138 , V_144 ) ;
V_13 = F_14 ( V_2 , V_140 , & V_35 , & V_159 , & V_23 ,
V_75 ) ;
if ( V_13 )
goto V_161;
while ( 1 ) {
T_3 V_87 ;
if ( V_159 ) {
F_78 ( V_142 , V_143 , V_151 ) ;
goto V_161;
}
if ( V_23 ) {
V_13 = - V_31 ;
goto V_161;
}
V_2 -> V_96 [ V_38 ] = V_162 | V_35 ;
F_84 () ;
V_13 = F_14 ( V_2 , V_140 , & V_87 , & V_159 ,
& V_23 , V_75 ) ;
if ( V_13 )
goto V_163;
if ( V_35 == V_87 )
break;
V_35 = V_87 ;
}
V_13 = F_74 ( V_2 , V_142 , V_143 , V_35 , V_151 ) ;
if ( V_13 )
goto V_163;
if ( V_148 ) {
V_13 = F_79 ( V_61 , V_148 , V_2 , V_35 , V_164 ) ;
if ( V_13 )
goto V_163;
}
V_2 -> V_96 [ V_38 ] = V_165 ;
F_85 ( V_61 -> V_160 , V_38 ) ;
V_144 -= V_151 ;
V_143 += V_151 ;
V_139 += V_61 -> V_138 >> V_141 ;
}
return 0 ;
V_163:
V_2 -> V_96 [ V_38 ] = V_165 ;
V_161:
F_85 ( V_61 -> V_160 , V_38 ) ;
return V_13 ;
}
static int F_86 ( struct V_61 * V_61 , struct V_147 * V_148 ,
T_7 V_139 , struct V_142 * V_142 , unsigned int V_143 ,
unsigned int V_144 )
{
int V_13 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_140 = 0 , V_166 , V_167 , V_38 = 0 , V_62 ;
struct V_39 log ;
int V_72 ;
while ( V_144 ) {
T_3 V_151 ;
V_38 = F_83 ( V_61 -> V_160 ) ;
V_13 = F_70 ( V_61 , V_139 , & V_140 , & V_2 ) ;
if ( V_13 )
goto V_161;
V_151 = F_35 ( V_61 -> V_138 , V_144 ) ;
if ( ( V_2 -> V_6 & V_168 ) != 0 ) {
V_13 = - V_31 ;
goto V_161;
}
V_167 = V_2 -> V_76 [ V_38 ] . V_77 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_56 ; V_62 ++ )
while ( V_2 -> V_96 [ V_62 ] == ( V_162 | V_167 ) )
F_87 () ;
if ( V_167 >= V_2 -> V_53 ) {
V_13 = - V_31 ;
goto V_161;
}
V_13 = F_77 ( V_2 , V_167 , V_142 , V_143 , V_151 ) ;
if ( V_13 )
goto V_161;
if ( V_148 ) {
V_13 = F_79 ( V_61 , V_148 , V_2 , V_167 ,
V_169 ) ;
if ( V_13 )
goto V_161;
}
F_71 ( V_2 , V_140 ) ;
V_13 = F_14 ( V_2 , V_140 , & V_166 , NULL , NULL ,
V_75 ) ;
if ( V_13 )
goto V_170;
if ( V_166 >= V_2 -> V_53 ) {
V_13 = - V_31 ;
goto V_170;
}
log . V_16 = F_13 ( V_140 ) ;
log . V_78 = F_13 ( V_166 ) ;
log . V_87 = F_13 ( V_167 ) ;
log . V_66 = F_13 ( V_2 -> V_76 [ V_38 ] . V_66 ) ;
V_72 = V_2 -> V_76 [ V_38 ] . V_72 ;
V_13 = F_32 ( V_2 , V_38 , V_72 , & log ) ;
if ( V_13 )
goto V_170;
V_13 = F_11 ( V_2 , V_140 , V_167 , 0 , 0 , 0 ) ;
if ( V_13 )
goto V_170;
F_72 ( V_2 , V_140 ) ;
F_85 ( V_61 -> V_160 , V_38 ) ;
V_144 -= V_151 ;
V_143 += V_151 ;
V_139 += V_61 -> V_138 >> V_141 ;
}
return 0 ;
V_170:
F_72 ( V_2 , V_140 ) ;
V_161:
F_85 ( V_61 -> V_160 , V_38 ) ;
return V_13 ;
}
static int F_88 ( struct V_61 * V_61 , struct V_147 * V_148 ,
struct V_142 * V_142 , unsigned int V_144 , unsigned int V_143 ,
bool V_171 , T_7 V_139 )
{
int V_13 ;
if ( ! V_171 ) {
V_13 = F_82 ( V_61 , V_148 , V_142 , V_143 , V_139 , V_144 ) ;
F_89 ( V_142 ) ;
} else {
F_89 ( V_142 ) ;
V_13 = F_86 ( V_61 , V_148 , V_139 , V_142 , V_143 , V_144 ) ;
}
return V_13 ;
}
static T_10 F_90 ( struct V_172 * V_173 , struct V_174 * V_174 )
{
struct V_147 * V_148 = F_91 ( V_174 ) ;
struct V_61 * V_61 = V_173 -> V_175 ;
struct V_176 V_177 ;
unsigned long V_100 ;
struct V_152 V_178 ;
int V_179 = 0 ;
bool V_180 ;
if ( ! F_92 ( V_174 ) )
return V_181 ;
V_180 = F_93 ( V_174 , & V_100 ) ;
F_94 (bvec, bio, iter) {
unsigned int V_144 = V_178 . V_156 ;
F_95 ( V_144 > V_182 ) ;
F_95 ( V_144 < V_61 -> V_138 ) ;
F_95 ( V_144 % V_61 -> V_138 ) ;
V_179 = F_88 ( V_61 , V_148 , V_178 . V_157 , V_144 , V_178 . V_158 ,
F_96 ( F_97 ( V_174 ) ) , V_177 . V_183 ) ;
if ( V_179 ) {
F_30 ( & V_61 -> V_7 -> V_63 ,
L_22 ,
( F_96 ( F_97 ( V_174 ) ) ) ? L_23 :
L_24 ,
( unsigned long long ) V_177 . V_183 , V_144 ) ;
V_174 -> V_184 = F_98 ( V_179 ) ;
break;
}
}
if ( V_180 )
F_99 ( V_174 , V_100 ) ;
F_100 ( V_174 ) ;
return V_181 ;
}
static int F_101 ( struct V_185 * V_186 , T_7 V_139 ,
struct V_142 * V_142 , bool V_171 )
{
struct V_61 * V_61 = V_186 -> V_187 -> V_188 ;
int V_189 ;
V_189 = F_88 ( V_61 , NULL , V_142 , V_182 , 0 , V_171 , V_139 ) ;
if ( V_189 == 0 )
F_102 ( V_142 , V_171 , 0 ) ;
return V_189 ;
}
static int F_103 ( struct V_185 * V_190 , struct V_191 * V_192 )
{
V_192 -> V_193 = 1 << 6 ;
V_192 -> V_194 = 1 << 5 ;
V_192 -> V_195 = F_104 ( V_190 -> V_187 ) >> 11 ;
return 0 ;
}
static int F_105 ( struct V_61 * V_61 )
{
struct V_7 * V_7 = V_61 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_61 -> V_196 = F_106 ( V_83 ) ;
if ( ! V_61 -> V_196 )
return - V_84 ;
V_61 -> V_197 = F_107 ( 0 ) ;
if ( ! V_61 -> V_197 ) {
F_108 ( V_61 -> V_196 ) ;
return - V_84 ;
}
F_109 ( V_9 , V_61 -> V_197 -> V_198 ) ;
V_61 -> V_197 -> V_199 = 0 ;
V_61 -> V_197 -> V_200 = & V_201 ;
V_61 -> V_197 -> V_188 = V_61 ;
V_61 -> V_197 -> V_202 = V_61 -> V_196 ;
V_61 -> V_197 -> V_6 = V_203 ;
F_110 ( V_61 -> V_196 , F_90 ) ;
F_111 ( V_61 -> V_196 , V_61 -> V_138 ) ;
F_112 ( V_61 -> V_196 , V_204 ) ;
F_113 ( V_205 , V_61 -> V_196 ) ;
V_61 -> V_196 -> V_175 = V_61 ;
F_114 ( V_61 -> V_197 , 0 ) ;
F_115 ( & V_61 -> V_7 -> V_63 , V_61 -> V_197 ) ;
if ( F_69 ( V_61 ) ) {
int V_189 = F_116 ( V_61 -> V_197 , F_69 ( V_61 ) ) ;
if ( V_189 ) {
F_117 ( V_61 -> V_197 ) ;
F_118 ( V_61 -> V_197 ) ;
F_108 ( V_61 -> V_196 ) ;
return V_189 ;
}
}
F_114 ( V_61 -> V_197 , V_61 -> V_121 * V_61 -> V_138 >> 9 ) ;
V_61 -> V_7 -> V_51 = V_61 -> V_121 * ( T_5 ) V_61 -> V_138 ;
F_119 ( V_61 -> V_197 ) ;
return 0 ;
}
static void F_120 ( struct V_61 * V_61 )
{
F_117 ( V_61 -> V_197 ) ;
F_118 ( V_61 -> V_197 ) ;
F_108 ( V_61 -> V_196 ) ;
}
static struct V_61 * F_121 ( struct V_7 * V_7 , unsigned long long V_111 ,
T_3 V_104 , T_6 * V_132 , struct V_160 * V_160 )
{
int V_13 ;
struct V_61 * V_61 ;
struct V_68 * V_63 = & V_7 -> V_63 ;
V_61 = F_122 ( V_63 , sizeof( struct V_61 ) , V_83 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_7 = V_7 ;
V_61 -> V_111 = V_111 ;
V_61 -> V_104 = V_104 ;
V_61 -> V_138 = ( ( V_104 >= 4096 ) ? 4096 : 512 ) ;
F_123 ( & V_61 -> V_120 ) ;
F_124 ( & V_61 -> V_136 ) ;
V_61 -> V_160 = V_160 ;
V_13 = F_55 ( V_61 ) ;
if ( V_13 ) {
F_30 ( V_63 , L_25 , V_13 ) ;
return NULL ;
}
if ( V_61 -> V_117 != V_122 && V_160 -> V_206 ) {
F_125 ( V_63 , L_26 ,
F_25 ( & V_160 -> V_63 ) ) ;
return NULL ;
} else if ( V_61 -> V_117 != V_122 ) {
V_61 -> V_114 = ( V_111 / V_124 ) +
( ( V_111 % V_124 ) ? 1 : 0 ) ;
F_126 ( V_63 , L_27 ,
V_61 -> V_114 , V_111 ) ;
V_13 = F_59 ( V_61 ) ;
if ( V_13 ) {
F_57 ( V_63 , L_28 , V_13 ) ;
return NULL ;
}
V_13 = F_66 ( V_61 ) ;
if ( V_13 ) {
F_30 ( V_63 , L_29 , V_13 ) ;
return NULL ;
}
}
V_13 = F_105 ( V_61 ) ;
if ( V_13 ) {
F_30 ( V_63 , L_30 , V_13 ) ;
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
struct V_160 * V_160 ;
struct V_11 * V_11 ;
struct V_61 * V_61 ;
T_2 V_111 ;
if ( ! V_7 -> V_132 || ! V_7 -> V_9 || ! V_7 -> V_104 ) {
F_126 ( & V_7 -> V_63 , L_31 ) ;
return - V_119 ;
}
V_11 = F_122 ( & V_7 -> V_63 , sizeof( * V_11 ) , V_83 ) ;
F_130 ( V_7 , V_9 , V_11 ) ;
V_111 = F_131 ( V_9 ) - V_7 -> V_10 ;
if ( V_111 < V_125 ) {
F_126 ( & V_7 -> V_63 , L_32 ,
F_25 ( & V_9 -> V_63 ) ,
V_125 + V_7 -> V_10 ) ;
return - V_208 ;
}
V_160 = F_132 ( V_7 -> V_63 . V_45 ) ;
V_61 = F_121 ( V_7 , V_111 , V_7 -> V_104 , V_7 -> V_132 ,
V_160 ) ;
if ( ! V_61 )
return - V_84 ;
V_7 -> V_61 = V_61 ;
return 0 ;
}
int F_133 ( struct V_7 * V_7 )
{
struct V_61 * V_61 = V_7 -> V_61 ;
F_127 ( V_61 ) ;
V_7 -> V_61 = NULL ;
return 0 ;
}
static int T_11 F_134 ( void )
{
int V_189 = 0 ;
V_64 = F_18 ( L_33 , NULL ) ;
if ( F_19 ( V_64 ) )
V_189 = - V_208 ;
return V_189 ;
}
static void T_12 F_135 ( void )
{
F_51 ( V_64 ) ;
}
