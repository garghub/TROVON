static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_3 += V_9 ;
return F_2 ( V_8 , V_3 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 )
{
struct V_6 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_3 += V_9 ;
return F_4 ( V_8 , V_3 , V_4 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_12 ;
V_12 = F_3 ( V_2 , V_2 -> V_13 , V_11 ,
sizeof( struct V_10 ) ) ;
if ( V_12 )
return V_12 ;
return F_3 ( V_2 , V_2 -> V_14 , V_11 ,
sizeof( struct V_10 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_7 ( ! V_11 ) ;
return F_1 ( V_2 , V_2 -> V_14 , V_11 ,
sizeof( struct V_10 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , T_3 V_15 , T_4 V_16 )
{
T_5 V_17 = V_2 -> V_18 + ( V_15 * V_19 ) ;
F_7 ( V_15 >= V_2 -> V_20 ) ;
return F_3 ( V_2 , V_17 , & V_16 , V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_3 V_15 , T_3 V_16 ,
T_3 V_21 , T_3 V_22 )
{
T_3 V_23 ;
T_4 V_24 ;
V_16 &= V_25 ;
V_23 = ( V_21 << 1 ) + V_22 ;
switch ( V_23 ) {
case 0 :
V_16 |= V_26 ;
break;
case 1 :
V_16 |= ( 1 << V_27 ) ;
break;
case 2 :
V_16 |= ( 1 << V_28 ) ;
break;
default:
F_10 ( 1 , L_1 ) ;
return - V_29 ;
}
V_24 = F_11 ( V_16 ) ;
return F_8 ( V_2 , V_15 , V_24 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_3 V_15 , T_3 * V_16 ,
int * V_30 , int * error )
{
int V_12 ;
T_4 V_31 ;
T_3 V_32 , V_33 , V_23 , V_21 , V_22 ;
T_5 V_17 = V_2 -> V_18 + ( V_15 * V_19 ) ;
F_7 ( V_15 >= V_2 -> V_20 ) ;
V_12 = F_1 ( V_2 , V_17 , & V_31 , V_19 ) ;
if ( V_12 )
return V_12 ;
V_32 = F_13 ( V_31 ) ;
V_21 = ( V_32 & V_34 ) >> V_28 ;
V_22 = ( V_32 & V_35 ) >> V_27 ;
V_23 = ( V_21 << 1 ) + V_22 ;
V_33 = V_32 & V_25 ;
V_21 = 0 ;
V_22 = 0 ;
switch ( V_23 ) {
case 0 :
* V_16 = V_15 ;
break;
case 1 :
* V_16 = V_33 ;
V_22 = 1 ;
break;
case 2 :
* V_16 = V_33 ;
V_21 = 1 ;
break;
case 3 :
* V_16 = V_33 ;
break;
default:
return - V_29 ;
}
if ( V_30 )
* V_30 = V_21 ;
if ( error )
* error = V_22 ;
return V_12 ;
}
static int F_14 ( struct V_1 * V_2 , T_3 V_36 ,
struct V_37 * V_38 )
{
F_7 ( ! V_38 ) ;
return F_1 ( V_2 ,
V_2 -> V_39 + ( 2 * V_36 * V_40 ) , V_38 ,
2 * V_40 ) ;
}
static void F_15 ( struct V_1 * V_41 , struct V_42 * V_43 ,
int V_44 )
{
char V_45 [ 32 ] ;
struct V_42 * V_46 ;
if ( ! V_43 )
return;
snprintf ( V_45 , 32 , L_2 , V_44 ) ;
V_46 = F_16 ( V_45 , V_43 ) ;
if ( F_17 ( V_46 ) )
return;
V_41 -> V_47 = V_46 ;
F_18 ( L_3 , V_48 , V_46 , & V_41 -> V_49 ) ;
F_18 ( L_4 , V_48 , V_46 ,
& V_41 -> V_50 ) ;
F_19 ( L_5 , V_48 , V_46 , & V_41 -> V_51 ) ;
F_20 ( L_6 , V_48 , V_46 ,
& V_41 -> V_52 ) ;
F_19 ( L_7 , V_48 , V_46 , & V_41 -> V_20 ) ;
F_20 ( L_8 , V_48 , V_46 ,
& V_41 -> V_53 ) ;
F_20 ( L_9 , V_48 , V_46 , & V_41 -> V_54 ) ;
F_21 ( L_10 , V_48 , V_46 , & V_41 -> V_55 ) ;
F_21 ( L_11 , V_48 , V_46 , & V_41 -> V_56 ) ;
F_18 ( L_12 , V_48 , V_46 , & V_41 -> V_57 ) ;
F_18 ( L_13 , V_48 , V_46 , & V_41 -> V_14 ) ;
F_18 ( L_14 , V_48 , V_46 , & V_41 -> V_58 ) ;
F_18 ( L_15 , V_48 , V_46 , & V_41 -> V_18 ) ;
F_18 ( L_16 , V_48 , V_46 , & V_41 -> V_39 ) ;
F_18 ( L_17 , V_48 , V_46 , & V_41 -> V_13 ) ;
F_19 ( L_18 , V_48 , V_46 , & V_41 -> V_59 ) ;
}
static void F_22 ( struct V_60 * V_60 )
{
int V_61 = 0 ;
struct V_1 * V_2 ;
V_60 -> V_47 = F_16 ( F_23 ( & V_60 -> V_6 -> V_62 ) ,
V_63 ) ;
if ( F_17 ( V_60 -> V_47 ) )
return;
F_24 (arena, &btt->arena_list, list) {
F_15 ( V_2 , V_60 -> V_47 , V_61 ) ;
V_61 ++ ;
}
}
static int F_25 ( struct V_37 * V_38 )
{
int V_64 ;
if ( V_38 [ 0 ] . V_65 == 0 ) {
V_38 [ 0 ] . V_65 = F_11 ( 1 ) ;
return 0 ;
}
if ( V_38 [ 0 ] . V_65 == V_38 [ 1 ] . V_65 )
return - V_66 ;
if ( F_13 ( V_38 [ 0 ] . V_65 ) + F_13 ( V_38 [ 1 ] . V_65 ) > 5 )
return - V_66 ;
if ( F_13 ( V_38 [ 0 ] . V_65 ) < F_13 ( V_38 [ 1 ] . V_65 ) ) {
if ( F_13 ( V_38 [ 1 ] . V_65 ) - F_13 ( V_38 [ 0 ] . V_65 ) == 1 )
V_64 = 0 ;
else
V_64 = 1 ;
} else {
if ( F_13 ( V_38 [ 0 ] . V_65 ) - F_13 ( V_38 [ 1 ] . V_65 ) == 1 )
V_64 = 1 ;
else
V_64 = 0 ;
}
return V_64 ;
}
static struct V_67 * F_26 ( struct V_1 * V_2 )
{
return & V_2 -> V_6 -> V_62 ;
}
static int F_27 ( struct V_1 * V_2 , T_3 V_36 ,
struct V_37 * V_38 , int V_68 )
{
int V_12 ;
int V_69 , V_70 ;
struct V_37 log [ 2 ] ;
V_12 = F_14 ( V_2 , V_36 , log ) ;
if ( V_12 )
return - V_29 ;
V_69 = F_25 ( log ) ;
if ( V_69 < 0 || V_69 > 1 ) {
F_28 ( F_26 ( V_2 ) ,
L_19 ,
V_69 , V_36 , log [ 0 ] . V_65 , log [ 1 ] . V_65 ) ;
return - V_29 ;
}
V_70 = ( V_68 ? V_69 : ( 1 - V_69 ) ) ;
if ( V_38 != NULL )
memcpy ( V_38 , & log [ V_70 ] , V_40 ) ;
return V_70 ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_36 ,
T_3 V_71 , struct V_37 * V_38 )
{
int V_12 ;
unsigned int V_72 = ( V_40 - 2 * sizeof( T_5 ) ) / 2 ;
T_5 V_17 = V_2 -> V_39 + ( ( ( 2 * V_36 ) + V_71 ) * V_40 ) ;
void * V_73 = V_38 ;
V_12 = F_3 ( V_2 , V_17 , V_73 , V_72 ) ;
if ( V_12 )
return V_12 ;
V_17 += V_72 ;
V_73 += V_72 ;
return F_3 ( V_2 , V_17 , V_73 , V_72 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_3 V_36 , T_3 V_71 ,
struct V_37 * V_38 )
{
int V_12 ;
V_12 = F_29 ( V_2 , V_36 , V_71 , V_38 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_74 [ V_36 ] . V_71 = 1 - V_2 -> V_74 [ V_36 ] . V_71 ;
if ( ++ ( V_2 -> V_74 [ V_36 ] . V_65 ) == 4 )
V_2 -> V_74 [ V_36 ] . V_65 = 1 ;
V_2 -> V_74 [ V_36 ] . V_75 = F_13 ( V_38 -> V_76 ) ;
return V_12 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_12 = - V_66 ;
void * V_77 ;
T_2 V_3 = 0 ;
T_2 V_78 = V_79 ;
T_2 V_80 = V_2 -> V_39 - V_2 -> V_18 ;
V_77 = F_32 ( V_78 , V_81 ) ;
if ( ! V_77 )
return - V_82 ;
while ( V_80 ) {
T_2 V_49 = F_33 ( V_80 , V_78 ) ;
V_12 = F_3 ( V_2 , V_2 -> V_18 + V_3 , V_77 ,
V_49 ) ;
if ( V_12 )
goto free;
V_3 += V_49 ;
V_80 -= V_49 ;
F_34 () ;
}
free:
F_35 ( V_77 ) ;
return V_12 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_12 ;
T_3 V_61 ;
struct V_37 log , V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_54 ; V_61 ++ ) {
log . V_15 = F_11 ( V_61 ) ;
log . V_76 = F_11 ( V_2 -> V_20 + V_61 ) ;
log . V_84 = F_11 ( V_2 -> V_20 + V_61 ) ;
log . V_65 = F_11 ( V_85 ) ;
V_12 = F_29 ( V_2 , V_61 , 0 , & log ) ;
if ( V_12 )
return V_12 ;
V_12 = F_29 ( V_2 , V_61 , 1 , & V_83 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_64 , V_86 , V_12 ;
T_3 V_61 , V_87 ;
struct V_37 V_88 , V_89 ;
V_2 -> V_74 = F_38 ( V_2 -> V_54 , sizeof( struct V_90 ) ,
V_81 ) ;
if ( ! V_2 -> V_74 )
return - V_82 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_54 ; V_61 ++ ) {
V_64 = F_27 ( V_2 , V_61 , & V_89 , V_91 ) ;
if ( V_64 < 0 )
return V_64 ;
V_86 = F_27 ( V_2 , V_61 , & V_88 , V_92 ) ;
if ( V_86 < 0 )
return V_86 ;
V_2 -> V_74 [ V_61 ] . V_71 = 1 - V_86 ;
V_2 -> V_74 [ V_61 ] . V_65 = F_39 ( F_13 ( V_88 . V_65 ) ) ;
V_2 -> V_74 [ V_61 ] . V_75 = F_13 ( V_88 . V_76 ) ;
if ( V_88 . V_76 == V_88 . V_84 )
continue;
V_12 = F_12 ( V_2 , F_13 ( V_88 . V_15 ) , & V_87 ,
NULL , NULL ) ;
if ( V_12 )
return V_12 ;
if ( ( F_13 ( V_88 . V_84 ) != V_87 ) &&
( F_13 ( V_88 . V_76 ) == V_87 ) ) {
V_12 = F_9 ( V_2 , F_13 ( V_88 . V_15 ) ,
F_13 ( V_88 . V_84 ) , 0 , 0 ) ;
if ( V_12 )
return V_12 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
V_2 -> V_93 = F_38 ( V_2 -> V_54 , sizeof( T_3 ) , V_81 ) ;
if ( V_2 -> V_93 == NULL )
return - V_82 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
T_3 V_61 ;
V_2 -> V_94 = F_38 ( V_2 -> V_54 , sizeof( struct V_95 ) ,
V_81 ) ;
if ( ! V_2 -> V_94 )
return - V_82 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_54 ; V_61 ++ )
F_42 ( & V_2 -> V_94 [ V_61 ] . V_96 ) ;
return 0 ;
}
static struct V_1 * F_43 ( struct V_60 * V_60 , T_2 V_49 ,
T_2 V_97 , T_2 V_98 )
{
struct V_1 * V_2 ;
T_5 V_99 , V_80 , V_100 ;
T_5 V_101 = V_49 ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = V_60 -> V_6 ;
if ( ! V_49 )
return V_2 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_50 = V_97 ;
V_2 -> V_53 = V_60 -> V_102 ;
V_2 -> V_52 = F_44 ( V_2 -> V_53 ,
V_103 ) ;
V_2 -> V_54 = V_104 ;
V_2 -> V_55 = 1 ;
V_2 -> V_56 = 1 ;
if ( V_101 % V_105 )
V_101 -= ( V_101 % V_105 ) ;
V_101 -= 2 * V_105 ;
V_99 = F_44 ( 2 * V_2 -> V_54 * sizeof( struct V_37 ) ,
V_105 ) ;
V_101 -= V_99 ;
V_2 -> V_51 = F_45 ( V_101 - V_105 ,
V_2 -> V_52 + V_19 ) ;
V_2 -> V_20 = V_2 -> V_51 - V_2 -> V_54 ;
V_80 = F_44 ( ( V_2 -> V_20 * V_19 ) , V_105 ) ;
V_100 = V_101 - V_80 ;
V_2 -> V_14 = V_98 ;
V_2 -> V_58 = V_2 -> V_14 + V_105 ;
V_2 -> V_18 = V_2 -> V_58 + V_100 ;
V_2 -> V_39 = V_2 -> V_18 + V_80 ;
V_2 -> V_13 = V_2 -> V_39 + V_99 ;
return V_2 ;
}
static void F_46 ( struct V_60 * V_60 )
{
struct V_1 * V_2 , * V_106 ;
F_47 (arena, next, &btt->arena_list, list) {
F_48 ( & V_2 -> V_107 ) ;
F_35 ( V_2 -> V_93 ) ;
F_35 ( V_2 -> V_94 ) ;
F_35 ( V_2 -> V_74 ) ;
F_49 ( V_2 -> V_47 ) ;
F_35 ( V_2 ) ;
}
}
static void F_50 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_5 V_98 )
{
V_2 -> V_51 = F_13 ( V_11 -> V_51 ) ;
V_2 -> V_52 = F_13 ( V_11 -> V_52 ) ;
V_2 -> V_20 = F_13 ( V_11 -> V_20 ) ;
V_2 -> V_53 = F_13 ( V_11 -> V_53 ) ;
V_2 -> V_54 = F_13 ( V_11 -> V_54 ) ;
V_2 -> V_55 = F_51 ( V_11 -> V_55 ) ;
V_2 -> V_56 = F_51 ( V_11 -> V_56 ) ;
V_2 -> V_57 = ( V_11 -> V_57 == 0 ) ? 0 : ( V_98 +
F_52 ( V_11 -> V_57 ) ) ;
V_2 -> V_14 = V_98 ;
V_2 -> V_58 = V_98 + F_52 ( V_11 -> V_58 ) ;
V_2 -> V_18 = V_98 + F_52 ( V_11 -> V_18 ) ;
V_2 -> V_39 = V_98 + F_52 ( V_11 -> V_39 ) ;
V_2 -> V_13 = V_98 + F_52 ( V_11 -> V_13 ) ;
V_2 -> V_49 = ( F_52 ( V_11 -> V_57 ) > 0 )
? ( F_52 ( V_11 -> V_57 ) )
: ( V_2 -> V_13 - V_2 -> V_14 + V_105 ) ;
V_2 -> V_59 = F_13 ( V_11 -> V_59 ) ;
}
static int F_53 ( struct V_60 * V_60 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
T_2 V_108 = V_60 -> V_109 ;
T_5 V_110 = 0 ;
T_2 V_111 = 0 ;
int V_112 = 0 ;
V_11 = F_32 ( sizeof( * V_11 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
while ( V_108 ) {
V_2 = F_43 ( V_60 , 0 , 0 , 0 ) ;
if ( ! V_2 ) {
V_12 = - V_82 ;
goto V_113;
}
V_2 -> V_14 = V_111 ;
V_12 = F_6 ( V_2 , V_11 ) ;
if ( V_12 )
goto V_114;
if ( ! F_54 ( V_60 -> V_6 , V_11 ) ) {
if ( V_108 == V_60 -> V_109 ) {
V_60 -> V_115 = V_116 ;
F_28 ( F_26 ( V_2 ) , L_20 ) ;
goto V_114;
} else {
F_28 ( F_26 ( V_2 ) ,
L_21 ) ;
V_12 = - V_117 ;
goto V_114;
}
}
V_2 -> V_50 = V_110 ;
F_50 ( V_2 , V_11 , V_111 ) ;
V_12 = F_37 ( V_2 ) ;
if ( V_12 )
goto V_114;
V_12 = F_40 ( V_2 ) ;
if ( V_12 )
goto V_114;
V_12 = F_41 ( V_2 ) ;
if ( V_12 )
goto V_114;
F_55 ( & V_2 -> V_107 , & V_60 -> V_118 ) ;
V_108 -= V_2 -> V_49 ;
V_111 += V_2 -> V_49 ;
V_110 += V_2 -> V_20 ;
V_112 ++ ;
if ( V_2 -> V_57 == 0 )
break;
}
V_60 -> V_112 = V_112 ;
V_60 -> V_119 = V_110 ;
V_60 -> V_115 = V_120 ;
F_35 ( V_11 ) ;
return V_12 ;
V_114:
F_35 ( V_2 ) ;
F_46 ( V_60 ) ;
V_113:
F_35 ( V_11 ) ;
return V_12 ;
}
static int F_56 ( struct V_60 * V_60 )
{
T_2 V_108 = V_60 -> V_109 ;
T_2 V_111 = 0 ;
while ( V_108 ) {
struct V_1 * V_2 ;
T_2 V_121 = F_57 ( T_5 , V_122 , V_108 ) ;
V_108 -= V_121 ;
if ( V_121 < V_123 )
break;
V_2 = F_43 ( V_60 , V_121 , V_60 -> V_119 , V_111 ) ;
if ( ! V_2 ) {
F_46 ( V_60 ) ;
return - V_82 ;
}
V_60 -> V_119 += V_2 -> V_20 ;
if ( V_108 >= V_123 )
V_2 -> V_57 = V_2 -> V_49 ;
else
V_2 -> V_57 = 0 ;
V_111 += V_121 ;
F_55 ( & V_2 -> V_107 , & V_60 -> V_118 ) ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_12 ;
T_5 V_124 ;
struct V_10 * V_11 ;
struct V_6 * V_6 = V_2 -> V_6 ;
const T_6 * V_125 = F_59 ( & V_6 -> V_8 -> V_62 ) ;
V_12 = F_31 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_36 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_11 = F_32 ( sizeof( struct V_10 ) , V_126 ) ;
if ( ! V_11 )
return - V_82 ;
strncpy ( V_11 -> V_127 , V_128 , V_129 ) ;
memcpy ( V_11 -> V_130 , V_6 -> V_130 , 16 ) ;
memcpy ( V_11 -> V_125 , V_125 , 16 ) ;
V_11 -> V_59 = F_11 ( V_2 -> V_59 ) ;
V_11 -> V_55 = F_60 ( V_2 -> V_55 ) ;
V_11 -> V_56 = F_60 ( V_2 -> V_56 ) ;
V_11 -> V_53 = F_11 ( V_2 -> V_53 ) ;
V_11 -> V_20 = F_11 ( V_2 -> V_20 ) ;
V_11 -> V_52 = F_11 ( V_2 -> V_52 ) ;
V_11 -> V_51 = F_11 ( V_2 -> V_51 ) ;
V_11 -> V_54 = F_11 ( V_2 -> V_54 ) ;
V_11 -> V_131 = F_11 ( sizeof( struct V_10 ) ) ;
V_11 -> V_57 = F_61 ( V_2 -> V_57 ) ;
V_11 -> V_58 = F_61 ( V_2 -> V_58 - V_2 -> V_14 ) ;
V_11 -> V_18 = F_61 ( V_2 -> V_18 - V_2 -> V_14 ) ;
V_11 -> V_39 = F_61 ( V_2 -> V_39 - V_2 -> V_14 ) ;
V_11 -> V_13 = F_61 ( V_2 -> V_13 - V_2 -> V_14 ) ;
V_11 -> V_59 = 0 ;
V_124 = F_62 ( (struct V_132 * ) V_11 ) ;
V_11 -> V_133 = F_61 ( V_124 ) ;
V_12 = F_5 ( V_2 , V_11 ) ;
F_35 ( V_11 ) ;
return V_12 ;
}
static int F_63 ( struct V_60 * V_60 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
F_64 ( & V_60 -> V_134 ) ;
F_24 (arena, &btt->arena_list, list) {
V_12 = F_58 ( V_2 ) ;
if ( V_12 )
goto V_135;
V_12 = F_37 ( V_2 ) ;
if ( V_12 )
goto V_135;
V_12 = F_40 ( V_2 ) ;
if ( V_12 )
goto V_135;
V_12 = F_41 ( V_2 ) ;
if ( V_12 )
goto V_135;
}
V_60 -> V_115 = V_120 ;
V_135:
F_65 ( & V_60 -> V_134 ) ;
return V_12 ;
}
static T_3 F_66 ( struct V_60 * V_60 )
{
return V_60 -> V_102 - V_60 -> V_136 ;
}
static int F_67 ( struct V_60 * V_60 , T_7 V_137 , T_8 * V_138 ,
struct V_1 * * V_2 )
{
struct V_1 * V_118 ;
T_9 V_15 = F_45 ( V_137 << V_139 , V_60 -> V_136 ) ;
F_24 (arena_list, &btt->arena_list, list) {
if ( V_15 < V_118 -> V_20 ) {
* V_2 = V_118 ;
* V_138 = V_15 ;
return 0 ;
}
V_15 -= V_118 -> V_20 ;
}
return - V_29 ;
}
static void F_68 ( struct V_1 * V_2 , T_3 V_138 )
__acquires( &arena->map_locks[idx].lock
static void F_69 ( struct V_1 * V_2 , T_3 V_138 )
__releases( &arena->map_locks[idx].lock
static T_5 F_70 ( struct V_1 * V_2 , T_5 V_15 )
{
return V_2 -> V_58 + ( ( T_5 ) V_15 * V_2 -> V_52 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_140 * V_140 ,
unsigned int V_141 , T_3 V_15 , T_3 V_142 )
{
int V_12 ;
T_5 V_143 = F_70 ( V_2 , V_15 ) ;
void * V_144 = F_72 ( V_140 ) ;
V_12 = F_1 ( V_2 , V_143 , V_144 + V_141 , V_142 ) ;
F_73 ( V_144 ) ;
return V_12 ;
}
static int F_74 ( struct V_1 * V_2 , T_3 V_15 ,
struct V_140 * V_140 , unsigned int V_141 , T_3 V_142 )
{
int V_12 ;
T_5 V_143 = F_70 ( V_2 , V_15 ) ;
void * V_144 = F_72 ( V_140 ) ;
V_12 = F_3 ( V_2 , V_143 , V_144 + V_141 , V_142 ) ;
F_73 ( V_144 ) ;
return V_12 ;
}
static void F_75 ( struct V_140 * V_140 , unsigned int V_141 , T_3 V_142 )
{
void * V_144 = F_72 ( V_140 ) ;
memset ( V_144 + V_141 , 0 , V_142 ) ;
F_73 ( V_144 ) ;
}
static int F_76 ( struct V_60 * V_60 , struct V_145 * V_146 ,
struct V_1 * V_2 , T_3 V_33 , int V_147 )
{
unsigned int V_142 = F_66 ( V_60 ) ;
T_5 V_148 ;
int V_12 = 0 ;
if ( V_146 == NULL )
return 0 ;
V_148 = F_70 ( V_2 , V_33 ) + V_60 -> V_136 ;
while ( V_142 ) {
unsigned int V_149 ;
struct V_150 V_151 ;
void * V_144 ;
V_151 = F_77 ( V_146 -> V_152 , V_146 -> V_153 ) ;
V_149 = F_33 ( V_142 , V_151 . V_154 ) ;
V_144 = F_72 ( V_151 . V_155 ) ;
if ( V_147 )
V_12 = F_3 ( V_2 , V_148 ,
V_144 + V_151 . V_156 , V_149 ) ;
else
V_12 = F_1 ( V_2 , V_148 ,
V_144 + V_151 . V_156 , V_149 ) ;
F_73 ( V_144 ) ;
if ( V_12 )
return V_12 ;
V_142 -= V_149 ;
V_148 += V_149 ;
F_78 ( V_146 -> V_152 , & V_146 -> V_153 , V_149 ) ;
}
return V_12 ;
}
static int F_76 ( struct V_60 * V_60 , struct V_145 * V_146 ,
struct V_1 * V_2 , T_3 V_33 , int V_147 )
{
return 0 ;
}
static int F_79 ( struct V_60 * V_60 , struct V_145 * V_146 ,
struct V_140 * V_140 , unsigned int V_141 , T_7 V_137 ,
unsigned int V_142 )
{
int V_12 = 0 ;
int V_157 , V_22 ;
struct V_1 * V_2 = NULL ;
T_3 V_36 = 0 , V_138 , V_33 ;
while ( V_142 ) {
T_3 V_149 ;
V_36 = F_80 ( V_60 -> V_158 ) ;
V_12 = F_67 ( V_60 , V_137 , & V_138 , & V_2 ) ;
if ( V_12 )
goto V_159;
V_149 = F_33 ( V_60 -> V_136 , V_142 ) ;
V_12 = F_12 ( V_2 , V_138 , & V_33 , & V_157 , & V_22 ) ;
if ( V_12 )
goto V_159;
while ( 1 ) {
T_3 V_84 ;
if ( V_157 ) {
F_75 ( V_140 , V_141 , V_149 ) ;
goto V_159;
}
if ( V_22 ) {
V_12 = - V_29 ;
goto V_159;
}
V_2 -> V_93 [ V_36 ] = V_160 | V_33 ;
F_81 () ;
V_12 = F_12 ( V_2 , V_138 , & V_84 , & V_157 ,
& V_22 ) ;
if ( V_12 )
goto V_161;
if ( V_33 == V_84 )
break;
V_33 = V_84 ;
}
V_12 = F_71 ( V_2 , V_140 , V_141 , V_33 , V_149 ) ;
if ( V_12 )
goto V_161;
if ( V_146 ) {
V_12 = F_76 ( V_60 , V_146 , V_2 , V_33 , V_162 ) ;
if ( V_12 )
goto V_161;
}
V_2 -> V_93 [ V_36 ] = V_163 ;
F_82 ( V_60 -> V_158 , V_36 ) ;
V_142 -= V_149 ;
V_141 += V_149 ;
V_137 += V_60 -> V_136 >> V_139 ;
}
return 0 ;
V_161:
V_2 -> V_93 [ V_36 ] = V_163 ;
V_159:
F_82 ( V_60 -> V_158 , V_36 ) ;
return V_12 ;
}
static int F_83 ( struct V_60 * V_60 , struct V_145 * V_146 ,
T_7 V_137 , struct V_140 * V_140 , unsigned int V_141 ,
unsigned int V_142 )
{
int V_12 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_138 = 0 , V_164 , V_165 , V_36 = 0 , V_61 ;
struct V_37 log ;
int V_71 ;
while ( V_142 ) {
T_3 V_149 ;
V_36 = F_80 ( V_60 -> V_158 ) ;
V_12 = F_67 ( V_60 , V_137 , & V_138 , & V_2 ) ;
if ( V_12 )
goto V_159;
V_149 = F_33 ( V_60 -> V_136 , V_142 ) ;
if ( ( V_2 -> V_59 & V_166 ) != 0 ) {
V_12 = - V_29 ;
goto V_159;
}
V_165 = V_2 -> V_74 [ V_36 ] . V_75 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_54 ; V_61 ++ )
while ( V_2 -> V_93 [ V_61 ] == ( V_160 | V_165 ) )
F_84 () ;
if ( V_165 >= V_2 -> V_51 ) {
V_12 = - V_29 ;
goto V_159;
}
V_12 = F_74 ( V_2 , V_165 , V_140 , V_141 , V_149 ) ;
if ( V_12 )
goto V_159;
if ( V_146 ) {
V_12 = F_76 ( V_60 , V_146 , V_2 , V_165 ,
V_167 ) ;
if ( V_12 )
goto V_159;
}
F_68 ( V_2 , V_138 ) ;
V_12 = F_12 ( V_2 , V_138 , & V_164 , NULL , NULL ) ;
if ( V_12 )
goto V_168;
if ( V_164 >= V_2 -> V_51 ) {
V_12 = - V_29 ;
goto V_168;
}
log . V_15 = F_11 ( V_138 ) ;
log . V_76 = F_11 ( V_164 ) ;
log . V_84 = F_11 ( V_165 ) ;
log . V_65 = F_11 ( V_2 -> V_74 [ V_36 ] . V_65 ) ;
V_71 = V_2 -> V_74 [ V_36 ] . V_71 ;
V_12 = F_30 ( V_2 , V_36 , V_71 , & log ) ;
if ( V_12 )
goto V_168;
V_12 = F_9 ( V_2 , V_138 , V_165 , 0 , 0 ) ;
if ( V_12 )
goto V_168;
F_69 ( V_2 , V_138 ) ;
F_82 ( V_60 -> V_158 , V_36 ) ;
V_142 -= V_149 ;
V_141 += V_149 ;
V_137 += V_60 -> V_136 >> V_139 ;
}
return 0 ;
V_168:
F_69 ( V_2 , V_138 ) ;
V_159:
F_82 ( V_60 -> V_158 , V_36 ) ;
return V_12 ;
}
static int F_85 ( struct V_60 * V_60 , struct V_145 * V_146 ,
struct V_140 * V_140 , unsigned int V_142 , unsigned int V_141 ,
int V_147 , T_7 V_137 )
{
int V_12 ;
if ( V_147 == V_162 ) {
V_12 = F_79 ( V_60 , V_146 , V_140 , V_141 , V_137 , V_142 ) ;
F_86 ( V_140 ) ;
} else {
F_86 ( V_140 ) ;
V_12 = F_83 ( V_60 , V_146 , V_137 , V_140 , V_141 , V_142 ) ;
}
return V_12 ;
}
static T_10 F_87 ( struct V_169 * V_170 , struct V_171 * V_171 )
{
struct V_145 * V_146 = F_88 ( V_171 ) ;
struct V_60 * V_60 = V_170 -> V_172 ;
struct V_173 V_174 ;
unsigned long V_97 ;
struct V_150 V_175 ;
int V_176 = 0 , V_147 ;
bool V_177 ;
if ( F_89 ( V_171 ) && F_90 ( V_171 ) ) {
V_171 -> V_178 = - V_29 ;
goto V_114;
}
V_177 = F_91 ( V_171 , & V_97 ) ;
V_147 = F_92 ( V_171 ) ;
F_93 (bvec, bio, iter) {
unsigned int V_142 = V_175 . V_154 ;
F_94 ( V_142 > V_179 ) ;
F_94 ( V_142 < V_60 -> V_136 ) ;
F_94 ( V_142 % V_60 -> V_136 ) ;
V_176 = F_85 ( V_60 , V_146 , V_175 . V_155 , V_142 , V_175 . V_156 ,
V_147 , V_174 . V_180 ) ;
if ( V_176 ) {
F_28 ( & V_60 -> V_6 -> V_62 ,
L_22 ,
( V_147 == V_162 ) ? L_23 : L_24 ,
( unsigned long long ) V_174 . V_180 , V_142 ) ;
V_171 -> V_178 = V_176 ;
break;
}
}
if ( V_177 )
F_95 ( V_171 , V_97 ) ;
V_114:
F_96 ( V_171 ) ;
return V_181 ;
}
static int F_97 ( struct V_182 * V_183 , T_7 V_137 ,
struct V_140 * V_140 , int V_147 )
{
struct V_60 * V_60 = V_183 -> V_184 -> V_185 ;
F_85 ( V_60 , NULL , V_140 , V_179 , 0 , V_147 , V_137 ) ;
F_98 ( V_140 , V_147 & V_167 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_182 * V_186 , struct V_187 * V_188 )
{
V_188 -> V_189 = 1 << 6 ;
V_188 -> V_190 = 1 << 5 ;
V_188 -> V_191 = F_100 ( V_186 -> V_184 ) >> 11 ;
return 0 ;
}
static int F_101 ( struct V_60 * V_60 )
{
struct V_6 * V_6 = V_60 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_60 -> V_192 = F_102 ( V_81 ) ;
if ( ! V_60 -> V_192 )
return - V_82 ;
V_60 -> V_193 = F_103 ( 0 ) ;
if ( ! V_60 -> V_193 ) {
F_104 ( V_60 -> V_192 ) ;
return - V_82 ;
}
F_105 ( V_8 , V_60 -> V_193 -> V_194 ) ;
V_60 -> V_193 -> V_195 = & V_60 -> V_6 -> V_62 ;
V_60 -> V_193 -> V_196 = 0 ;
V_60 -> V_193 -> V_197 = & V_198 ;
V_60 -> V_193 -> V_185 = V_60 ;
V_60 -> V_193 -> V_199 = V_60 -> V_192 ;
V_60 -> V_193 -> V_59 = V_200 ;
F_106 ( V_60 -> V_192 , F_87 ) ;
F_107 ( V_60 -> V_192 , V_60 -> V_136 ) ;
F_108 ( V_60 -> V_192 , V_201 ) ;
F_109 ( V_60 -> V_192 , V_202 ) ;
F_110 ( V_203 , V_60 -> V_192 ) ;
V_60 -> V_192 -> V_172 = V_60 ;
F_111 ( V_60 -> V_193 , 0 ) ;
F_112 ( V_60 -> V_193 ) ;
if ( F_66 ( V_60 ) ) {
int V_204 = F_113 ( V_60 -> V_193 , F_66 ( V_60 ) ) ;
if ( V_204 ) {
F_114 ( V_60 -> V_193 ) ;
F_115 ( V_60 -> V_193 ) ;
F_104 ( V_60 -> V_192 ) ;
return V_204 ;
}
}
F_111 ( V_60 -> V_193 , V_60 -> V_119 * V_60 -> V_136 >> 9 ) ;
F_116 ( V_60 -> V_193 ) ;
return 0 ;
}
static void F_117 ( struct V_60 * V_60 )
{
F_114 ( V_60 -> V_193 ) ;
F_115 ( V_60 -> V_193 ) ;
F_104 ( V_60 -> V_192 ) ;
}
static struct V_60 * F_118 ( struct V_6 * V_6 , unsigned long long V_109 ,
T_3 V_102 , T_6 * V_130 , struct V_158 * V_158 )
{
int V_12 ;
struct V_60 * V_60 ;
struct V_67 * V_62 = & V_6 -> V_62 ;
V_60 = F_32 ( sizeof( struct V_60 ) , V_81 ) ;
if ( ! V_60 )
return NULL ;
V_60 -> V_6 = V_6 ;
V_60 -> V_109 = V_109 ;
V_60 -> V_102 = V_102 ;
V_60 -> V_136 = ( ( V_102 >= 4096 ) ? 4096 : 512 ) ;
F_119 ( & V_60 -> V_118 ) ;
F_120 ( & V_60 -> V_134 ) ;
V_60 -> V_158 = V_158 ;
V_12 = F_53 ( V_60 ) ;
if ( V_12 ) {
F_121 ( V_62 , L_25 , V_12 ) ;
goto V_205;
}
if ( V_60 -> V_115 != V_120 && V_158 -> V_206 ) {
F_28 ( V_62 , L_26 ,
F_23 ( & V_158 -> V_62 ) ) ;
goto V_205;
} else if ( V_60 -> V_115 != V_120 ) {
V_60 -> V_112 = ( V_109 / V_122 ) +
( ( V_109 % V_122 ) ? 1 : 0 ) ;
F_122 ( V_62 , L_27 ,
V_60 -> V_112 , V_109 ) ;
V_12 = F_56 ( V_60 ) ;
if ( V_12 ) {
F_28 ( V_62 , L_28 , V_12 ) ;
goto V_205;
}
V_12 = F_63 ( V_60 ) ;
if ( V_12 ) {
F_121 ( V_62 , L_29 , V_12 ) ;
goto V_205;
}
}
V_12 = F_101 ( V_60 ) ;
if ( V_12 ) {
F_121 ( V_62 , L_30 , V_12 ) ;
goto V_205;
}
F_22 ( V_60 ) ;
return V_60 ;
V_205:
F_35 ( V_60 ) ;
return NULL ;
}
static void F_123 ( struct V_60 * V_60 )
{
if ( V_60 ) {
F_117 ( V_60 ) ;
F_46 ( V_60 ) ;
F_49 ( V_60 -> V_47 ) ;
F_35 ( V_60 ) ;
}
}
int F_124 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_125 ( V_8 -> V_207 ) ;
struct V_158 * V_158 ;
struct V_60 * V_60 ;
T_2 V_109 ;
if ( ! V_6 -> V_130 || ! V_6 -> V_8 || ! V_6 -> V_102 )
return - V_117 ;
V_109 = F_126 ( V_8 ) - V_9 ;
if ( V_109 < V_123 ) {
return - V_208 ;
}
V_158 = F_127 ( V_6 -> V_62 . V_43 ) ;
V_60 = F_118 ( V_6 , V_109 , V_6 -> V_102 , V_6 -> V_130 ,
V_158 ) ;
if ( ! V_60 )
return - V_82 ;
V_6 -> V_60 = V_60 ;
return 0 ;
}
int F_128 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_125 ( V_8 -> V_207 ) ;
struct V_60 * V_60 = V_6 -> V_60 ;
F_123 ( V_60 ) ;
V_6 -> V_60 = NULL ;
return 0 ;
}
static int T_11 F_129 ( void )
{
int V_204 = 0 ;
V_63 = F_16 ( L_31 , NULL ) ;
if ( F_17 ( V_63 ) )
V_204 = - V_208 ;
return V_204 ;
}
static void T_12 F_130 ( void )
{
F_49 ( V_63 ) ;
}
