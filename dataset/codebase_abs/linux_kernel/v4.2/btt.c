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
static int F_50 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_6 * V_108 , T_3 V_102 )
{
T_5 V_109 ;
if ( memcmp ( V_11 -> V_108 , V_108 , 16 ) )
return 0 ;
V_109 = F_51 ( V_11 -> V_109 ) ;
V_11 -> V_109 = 0 ;
if ( V_109 != F_52 ( V_11 ) )
return 0 ;
V_11 -> V_109 = F_53 ( V_109 ) ;
if ( V_102 != F_13 ( V_11 -> V_53 ) )
return 0 ;
if ( ( F_13 ( V_11 -> V_59 ) & V_110 ) != 0 )
F_28 ( F_26 ( V_2 ) , L_20 ) ;
return 1 ;
}
static void F_54 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_5 V_98 )
{
V_2 -> V_51 = F_13 ( V_11 -> V_51 ) ;
V_2 -> V_52 = F_13 ( V_11 -> V_52 ) ;
V_2 -> V_20 = F_13 ( V_11 -> V_20 ) ;
V_2 -> V_53 = F_13 ( V_11 -> V_53 ) ;
V_2 -> V_54 = F_13 ( V_11 -> V_54 ) ;
V_2 -> V_55 = F_55 ( V_11 -> V_55 ) ;
V_2 -> V_56 = F_55 ( V_11 -> V_56 ) ;
V_2 -> V_57 = ( V_11 -> V_57 == 0 ) ? 0 : ( V_98 +
F_51 ( V_11 -> V_57 ) ) ;
V_2 -> V_14 = V_98 ;
V_2 -> V_58 = V_98 + F_51 ( V_11 -> V_58 ) ;
V_2 -> V_18 = V_98 + F_51 ( V_11 -> V_18 ) ;
V_2 -> V_39 = V_98 + F_51 ( V_11 -> V_39 ) ;
V_2 -> V_13 = V_98 + F_51 ( V_11 -> V_13 ) ;
V_2 -> V_49 = ( V_11 -> V_57 > 0 ) ? ( F_51 ( V_11 -> V_57 ) ) :
( V_2 -> V_13 - V_2 -> V_14 + V_105 ) ;
V_2 -> V_59 = F_13 ( V_11 -> V_59 ) ;
}
static int F_56 ( struct V_60 * V_60 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
T_2 V_111 = V_60 -> V_112 ;
T_5 V_113 = 0 ;
T_2 V_114 = 0 ;
int V_115 = 0 ;
V_11 = F_32 ( sizeof( * V_11 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
while ( V_111 ) {
V_2 = F_43 ( V_60 , 0 , 0 , 0 ) ;
if ( ! V_2 ) {
V_12 = - V_82 ;
goto V_116;
}
V_2 -> V_14 = V_114 ;
V_12 = F_6 ( V_2 , V_11 ) ;
if ( V_12 )
goto V_117;
if ( ! F_50 ( V_2 , V_11 , V_60 -> V_6 -> V_108 ,
V_60 -> V_102 ) ) {
if ( V_111 == V_60 -> V_112 ) {
V_60 -> V_118 = V_119 ;
F_28 ( F_26 ( V_2 ) , L_21 ) ;
goto V_117;
} else {
F_28 ( F_26 ( V_2 ) ,
L_22 ) ;
V_12 = - V_120 ;
goto V_117;
}
}
V_2 -> V_50 = V_113 ;
F_54 ( V_2 , V_11 , V_114 ) ;
V_12 = F_37 ( V_2 ) ;
if ( V_12 )
goto V_117;
V_12 = F_40 ( V_2 ) ;
if ( V_12 )
goto V_117;
V_12 = F_41 ( V_2 ) ;
if ( V_12 )
goto V_117;
F_57 ( & V_2 -> V_107 , & V_60 -> V_121 ) ;
V_111 -= V_2 -> V_49 ;
V_114 += V_2 -> V_49 ;
V_113 += V_2 -> V_20 ;
V_115 ++ ;
if ( V_2 -> V_57 == 0 )
break;
}
V_60 -> V_115 = V_115 ;
V_60 -> V_122 = V_113 ;
V_60 -> V_118 = V_123 ;
F_35 ( V_11 ) ;
return V_12 ;
V_117:
F_35 ( V_2 ) ;
F_46 ( V_60 ) ;
V_116:
F_35 ( V_11 ) ;
return V_12 ;
}
static int F_58 ( struct V_60 * V_60 )
{
T_2 V_111 = V_60 -> V_112 ;
T_2 V_114 = 0 ;
while ( V_111 ) {
struct V_1 * V_2 ;
T_2 V_124 = F_59 ( T_5 , V_125 , V_111 ) ;
V_111 -= V_124 ;
if ( V_124 < V_126 )
break;
V_2 = F_43 ( V_60 , V_124 , V_60 -> V_122 , V_114 ) ;
if ( ! V_2 ) {
F_46 ( V_60 ) ;
return - V_82 ;
}
V_60 -> V_122 += V_2 -> V_20 ;
if ( V_111 >= V_126 )
V_2 -> V_57 = V_2 -> V_49 ;
else
V_2 -> V_57 = 0 ;
V_114 += V_124 ;
F_57 ( & V_2 -> V_107 , & V_60 -> V_121 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , T_6 * V_108 )
{
int V_12 ;
struct V_10 * V_11 ;
V_12 = F_31 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_36 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_11 = F_32 ( sizeof( struct V_10 ) , V_127 ) ;
if ( ! V_11 )
return - V_82 ;
strncpy ( V_11 -> V_128 , V_129 , V_130 ) ;
memcpy ( V_11 -> V_108 , V_108 , 16 ) ;
V_11 -> V_59 = F_11 ( V_2 -> V_59 ) ;
V_11 -> V_55 = F_61 ( V_2 -> V_55 ) ;
V_11 -> V_56 = F_61 ( V_2 -> V_56 ) ;
V_11 -> V_53 = F_11 ( V_2 -> V_53 ) ;
V_11 -> V_20 = F_11 ( V_2 -> V_20 ) ;
V_11 -> V_52 = F_11 ( V_2 -> V_52 ) ;
V_11 -> V_51 = F_11 ( V_2 -> V_51 ) ;
V_11 -> V_54 = F_11 ( V_2 -> V_54 ) ;
V_11 -> V_131 = F_11 ( sizeof( struct V_10 ) ) ;
V_11 -> V_57 = F_53 ( V_2 -> V_57 ) ;
V_11 -> V_58 = F_53 ( V_2 -> V_58 - V_2 -> V_14 ) ;
V_11 -> V_18 = F_53 ( V_2 -> V_18 - V_2 -> V_14 ) ;
V_11 -> V_39 = F_53 ( V_2 -> V_39 - V_2 -> V_14 ) ;
V_11 -> V_13 = F_53 ( V_2 -> V_13 - V_2 -> V_14 ) ;
V_11 -> V_59 = 0 ;
V_11 -> V_109 = F_53 ( F_52 ( V_11 ) ) ;
V_12 = F_5 ( V_2 , V_11 ) ;
F_35 ( V_11 ) ;
return V_12 ;
}
static int F_62 ( struct V_60 * V_60 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
F_63 ( & V_60 -> V_132 ) ;
F_24 (arena, &btt->arena_list, list) {
V_12 = F_60 ( V_2 , V_60 -> V_6 -> V_108 ) ;
if ( V_12 )
goto V_133;
V_12 = F_37 ( V_2 ) ;
if ( V_12 )
goto V_133;
V_12 = F_40 ( V_2 ) ;
if ( V_12 )
goto V_133;
V_12 = F_41 ( V_2 ) ;
if ( V_12 )
goto V_133;
}
V_60 -> V_118 = V_123 ;
V_133:
F_64 ( & V_60 -> V_132 ) ;
return V_12 ;
}
static T_3 F_65 ( struct V_60 * V_60 )
{
return V_60 -> V_102 - V_60 -> V_134 ;
}
static int F_66 ( struct V_60 * V_60 , T_7 V_135 , T_8 * V_136 ,
struct V_1 * * V_2 )
{
struct V_1 * V_121 ;
T_9 V_15 = F_45 ( V_135 << V_137 , V_60 -> V_134 ) ;
F_24 (arena_list, &btt->arena_list, list) {
if ( V_15 < V_121 -> V_20 ) {
* V_2 = V_121 ;
* V_136 = V_15 ;
return 0 ;
}
V_15 -= V_121 -> V_20 ;
}
return - V_29 ;
}
static void F_67 ( struct V_1 * V_2 , T_3 V_136 )
__acquires( &arena->map_locks[idx].lock
static void F_68 ( struct V_1 * V_2 , T_3 V_136 )
__releases( &arena->map_locks[idx].lock
static T_5 F_69 ( struct V_1 * V_2 , T_5 V_15 )
{
return V_2 -> V_58 + ( ( T_5 ) V_15 * V_2 -> V_52 ) ;
}
static int F_70 ( struct V_1 * V_2 , struct V_138 * V_138 ,
unsigned int V_139 , T_3 V_15 , T_3 V_140 )
{
int V_12 ;
T_5 V_141 = F_69 ( V_2 , V_15 ) ;
void * V_142 = F_71 ( V_138 ) ;
V_12 = F_1 ( V_2 , V_141 , V_142 + V_139 , V_140 ) ;
F_72 ( V_142 ) ;
return V_12 ;
}
static int F_73 ( struct V_1 * V_2 , T_3 V_15 ,
struct V_138 * V_138 , unsigned int V_139 , T_3 V_140 )
{
int V_12 ;
T_5 V_141 = F_69 ( V_2 , V_15 ) ;
void * V_142 = F_71 ( V_138 ) ;
V_12 = F_3 ( V_2 , V_141 , V_142 + V_139 , V_140 ) ;
F_72 ( V_142 ) ;
return V_12 ;
}
static void F_74 ( struct V_138 * V_138 , unsigned int V_139 , T_3 V_140 )
{
void * V_142 = F_71 ( V_138 ) ;
memset ( V_142 + V_139 , 0 , V_140 ) ;
F_72 ( V_142 ) ;
}
static int F_75 ( struct V_60 * V_60 , struct V_143 * V_144 ,
struct V_1 * V_2 , T_3 V_33 , int V_145 )
{
unsigned int V_140 = F_65 ( V_60 ) ;
T_5 V_146 ;
int V_12 = 0 ;
if ( V_144 == NULL )
return 0 ;
V_146 = F_69 ( V_2 , V_33 ) + V_60 -> V_134 ;
while ( V_140 ) {
unsigned int V_147 ;
struct V_148 V_149 ;
void * V_142 ;
V_149 = F_76 ( V_144 -> V_150 , V_144 -> V_151 ) ;
V_147 = F_33 ( V_140 , V_149 . V_152 ) ;
V_142 = F_71 ( V_149 . V_153 ) ;
if ( V_145 )
V_12 = F_3 ( V_2 , V_146 ,
V_142 + V_149 . V_154 , V_147 ) ;
else
V_12 = F_1 ( V_2 , V_146 ,
V_142 + V_149 . V_154 , V_147 ) ;
F_72 ( V_142 ) ;
if ( V_12 )
return V_12 ;
V_140 -= V_147 ;
V_146 += V_147 ;
F_77 ( V_144 -> V_150 , & V_144 -> V_151 , V_147 ) ;
}
return V_12 ;
}
static int F_75 ( struct V_60 * V_60 , struct V_143 * V_144 ,
struct V_1 * V_2 , T_3 V_33 , int V_145 )
{
return 0 ;
}
static int F_78 ( struct V_60 * V_60 , struct V_143 * V_144 ,
struct V_138 * V_138 , unsigned int V_139 , T_7 V_135 ,
unsigned int V_140 )
{
int V_12 = 0 ;
int V_155 , V_22 ;
struct V_1 * V_2 = NULL ;
T_3 V_36 = 0 , V_136 , V_33 ;
while ( V_140 ) {
T_3 V_147 ;
V_36 = F_79 ( V_60 -> V_156 ) ;
V_12 = F_66 ( V_60 , V_135 , & V_136 , & V_2 ) ;
if ( V_12 )
goto V_157;
V_147 = F_33 ( V_60 -> V_134 , V_140 ) ;
V_12 = F_12 ( V_2 , V_136 , & V_33 , & V_155 , & V_22 ) ;
if ( V_12 )
goto V_157;
while ( 1 ) {
T_3 V_84 ;
if ( V_155 ) {
F_74 ( V_138 , V_139 , V_147 ) ;
goto V_157;
}
if ( V_22 ) {
V_12 = - V_29 ;
goto V_157;
}
V_2 -> V_93 [ V_36 ] = V_158 | V_33 ;
F_80 () ;
V_12 = F_12 ( V_2 , V_136 , & V_84 , & V_155 ,
& V_22 ) ;
if ( V_12 )
goto V_159;
if ( V_33 == V_84 )
break;
V_33 = V_84 ;
}
V_12 = F_70 ( V_2 , V_138 , V_139 , V_33 , V_147 ) ;
if ( V_12 )
goto V_159;
if ( V_144 ) {
V_12 = F_75 ( V_60 , V_144 , V_2 , V_33 , V_160 ) ;
if ( V_12 )
goto V_159;
}
V_2 -> V_93 [ V_36 ] = V_161 ;
F_81 ( V_60 -> V_156 , V_36 ) ;
V_140 -= V_147 ;
V_139 += V_147 ;
V_135 += V_60 -> V_134 >> V_137 ;
}
return 0 ;
V_159:
V_2 -> V_93 [ V_36 ] = V_161 ;
V_157:
F_81 ( V_60 -> V_156 , V_36 ) ;
return V_12 ;
}
static int F_82 ( struct V_60 * V_60 , struct V_143 * V_144 ,
T_7 V_135 , struct V_138 * V_138 , unsigned int V_139 ,
unsigned int V_140 )
{
int V_12 = 0 ;
struct V_1 * V_2 = NULL ;
T_3 V_136 = 0 , V_162 , V_163 , V_36 = 0 , V_61 ;
struct V_37 log ;
int V_71 ;
while ( V_140 ) {
T_3 V_147 ;
V_36 = F_79 ( V_60 -> V_156 ) ;
V_12 = F_66 ( V_60 , V_135 , & V_136 , & V_2 ) ;
if ( V_12 )
goto V_157;
V_147 = F_33 ( V_60 -> V_134 , V_140 ) ;
if ( ( V_2 -> V_59 & V_110 ) != 0 ) {
V_12 = - V_29 ;
goto V_157;
}
V_163 = V_2 -> V_74 [ V_36 ] . V_75 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_54 ; V_61 ++ )
while ( V_2 -> V_93 [ V_61 ] == ( V_158 | V_163 ) )
F_83 () ;
if ( V_163 >= V_2 -> V_51 ) {
V_12 = - V_29 ;
goto V_157;
}
V_12 = F_73 ( V_2 , V_163 , V_138 , V_139 , V_147 ) ;
if ( V_12 )
goto V_157;
if ( V_144 ) {
V_12 = F_75 ( V_60 , V_144 , V_2 , V_163 ,
V_164 ) ;
if ( V_12 )
goto V_157;
}
F_67 ( V_2 , V_136 ) ;
V_12 = F_12 ( V_2 , V_136 , & V_162 , NULL , NULL ) ;
if ( V_12 )
goto V_165;
if ( V_162 >= V_2 -> V_51 ) {
V_12 = - V_29 ;
goto V_165;
}
log . V_15 = F_11 ( V_136 ) ;
log . V_76 = F_11 ( V_162 ) ;
log . V_84 = F_11 ( V_163 ) ;
log . V_65 = F_11 ( V_2 -> V_74 [ V_36 ] . V_65 ) ;
V_71 = V_2 -> V_74 [ V_36 ] . V_71 ;
V_12 = F_30 ( V_2 , V_36 , V_71 , & log ) ;
if ( V_12 )
goto V_165;
V_12 = F_9 ( V_2 , V_136 , V_163 , 0 , 0 ) ;
if ( V_12 )
goto V_165;
F_68 ( V_2 , V_136 ) ;
F_81 ( V_60 -> V_156 , V_36 ) ;
V_140 -= V_147 ;
V_139 += V_147 ;
V_135 += V_60 -> V_134 >> V_137 ;
}
return 0 ;
V_165:
F_68 ( V_2 , V_136 ) ;
V_157:
F_81 ( V_60 -> V_156 , V_36 ) ;
return V_12 ;
}
static int F_84 ( struct V_60 * V_60 , struct V_143 * V_144 ,
struct V_138 * V_138 , unsigned int V_140 , unsigned int V_139 ,
int V_145 , T_7 V_135 )
{
int V_12 ;
if ( V_145 == V_160 ) {
V_12 = F_78 ( V_60 , V_144 , V_138 , V_139 , V_135 , V_140 ) ;
F_85 ( V_138 ) ;
} else {
F_85 ( V_138 ) ;
V_12 = F_82 ( V_60 , V_144 , V_135 , V_138 , V_139 , V_140 ) ;
}
return V_12 ;
}
static void F_86 ( struct V_166 * V_167 , struct V_168 * V_168 )
{
struct V_143 * V_144 = F_87 ( V_168 ) ;
struct V_60 * V_60 = V_167 -> V_169 ;
struct V_170 V_171 ;
unsigned long V_97 ;
struct V_148 V_172 ;
int V_173 = 0 , V_145 ;
bool V_174 ;
if ( F_88 ( V_168 ) && F_89 ( V_168 ) ) {
V_173 = - V_29 ;
goto V_117;
}
V_174 = F_90 ( V_168 , & V_97 ) ;
V_145 = F_91 ( V_168 ) ;
F_92 (bvec, bio, iter) {
unsigned int V_140 = V_172 . V_152 ;
F_93 ( V_140 > V_175 ) ;
F_93 ( V_140 < V_60 -> V_134 ) ;
F_93 ( V_140 % V_60 -> V_134 ) ;
V_173 = F_84 ( V_60 , V_144 , V_172 . V_153 , V_140 , V_172 . V_154 ,
V_145 , V_171 . V_176 ) ;
if ( V_173 ) {
F_28 ( & V_60 -> V_6 -> V_62 ,
L_23 ,
( V_145 == V_160 ) ? L_24 : L_25 ,
( unsigned long long ) V_171 . V_176 , V_140 ) ;
break;
}
}
if ( V_174 )
F_94 ( V_168 , V_97 ) ;
V_117:
F_95 ( V_168 , V_173 ) ;
}
static int F_96 ( struct V_177 * V_178 , T_7 V_135 ,
struct V_138 * V_138 , int V_145 )
{
struct V_60 * V_60 = V_178 -> V_179 -> V_180 ;
F_84 ( V_60 , NULL , V_138 , V_181 , 0 , V_145 , V_135 ) ;
F_97 ( V_138 , V_145 & V_164 , 0 ) ;
return 0 ;
}
static int F_98 ( struct V_177 * V_182 , struct V_183 * V_184 )
{
V_184 -> V_185 = 1 << 6 ;
V_184 -> V_186 = 1 << 5 ;
V_184 -> V_187 = F_99 ( V_182 -> V_179 ) >> 11 ;
return 0 ;
}
static int F_100 ( struct V_60 * V_60 )
{
struct V_6 * V_6 = V_60 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_60 -> V_188 = F_101 ( V_81 ) ;
if ( ! V_60 -> V_188 )
return - V_82 ;
V_60 -> V_189 = F_102 ( 0 ) ;
if ( ! V_60 -> V_189 ) {
F_103 ( V_60 -> V_188 ) ;
return - V_82 ;
}
F_104 ( V_8 , V_60 -> V_189 -> V_190 ) ;
V_60 -> V_189 -> V_191 = & V_60 -> V_6 -> V_62 ;
V_60 -> V_189 -> V_192 = V_193 ;
V_60 -> V_189 -> V_194 = 0 ;
V_60 -> V_189 -> V_195 = & V_196 ;
V_60 -> V_189 -> V_180 = V_60 ;
V_60 -> V_189 -> V_197 = V_60 -> V_188 ;
V_60 -> V_189 -> V_59 = V_198 ;
F_105 ( V_60 -> V_188 , F_86 ) ;
F_106 ( V_60 -> V_188 , V_60 -> V_134 ) ;
F_107 ( V_60 -> V_188 , V_199 ) ;
F_108 ( V_60 -> V_188 , V_200 ) ;
F_109 ( V_201 , V_60 -> V_188 ) ;
V_60 -> V_188 -> V_169 = V_60 ;
F_110 ( V_60 -> V_189 , 0 ) ;
F_111 ( V_60 -> V_189 ) ;
if ( F_65 ( V_60 ) ) {
int V_202 = F_112 ( V_60 -> V_189 , F_65 ( V_60 ) ) ;
if ( V_202 ) {
F_113 ( V_60 -> V_189 ) ;
F_114 ( V_60 -> V_189 ) ;
F_103 ( V_60 -> V_188 ) ;
return V_202 ;
}
}
F_110 ( V_60 -> V_189 , V_60 -> V_122 * V_60 -> V_134 >> 9 ) ;
F_115 ( V_60 -> V_189 ) ;
return 0 ;
}
static void F_116 ( struct V_60 * V_60 )
{
F_117 ( V_60 -> V_189 ) ;
F_113 ( V_60 -> V_189 ) ;
F_114 ( V_60 -> V_189 ) ;
F_103 ( V_60 -> V_188 ) ;
}
static struct V_60 * F_118 ( struct V_6 * V_6 , unsigned long long V_112 ,
T_3 V_102 , T_6 * V_108 , struct V_156 * V_156 )
{
int V_12 ;
struct V_60 * V_60 ;
struct V_67 * V_62 = & V_6 -> V_62 ;
V_60 = F_32 ( sizeof( struct V_60 ) , V_81 ) ;
if ( ! V_60 )
return NULL ;
V_60 -> V_6 = V_6 ;
V_60 -> V_112 = V_112 ;
V_60 -> V_102 = V_102 ;
V_60 -> V_134 = ( ( V_102 >= 4096 ) ? 4096 : 512 ) ;
F_119 ( & V_60 -> V_121 ) ;
F_120 ( & V_60 -> V_132 ) ;
V_60 -> V_156 = V_156 ;
V_12 = F_56 ( V_60 ) ;
if ( V_12 ) {
F_121 ( V_62 , L_26 , V_12 ) ;
goto V_203;
}
if ( V_60 -> V_118 != V_123 && V_156 -> V_204 ) {
F_28 ( V_62 , L_27 ,
F_23 ( & V_156 -> V_62 ) ) ;
goto V_203;
} else if ( V_60 -> V_118 != V_123 ) {
V_60 -> V_115 = ( V_112 / V_125 ) +
( ( V_112 % V_125 ) ? 1 : 0 ) ;
F_122 ( V_62 , L_28 ,
V_60 -> V_115 , V_112 ) ;
V_12 = F_58 ( V_60 ) ;
if ( V_12 ) {
F_28 ( V_62 , L_29 , V_12 ) ;
goto V_203;
}
V_12 = F_62 ( V_60 ) ;
if ( V_12 ) {
F_121 ( V_62 , L_30 , V_12 ) ;
goto V_203;
}
}
V_12 = F_100 ( V_60 ) ;
if ( V_12 ) {
F_121 ( V_62 , L_31 , V_12 ) ;
goto V_203;
}
F_22 ( V_60 ) ;
return V_60 ;
V_203:
F_35 ( V_60 ) ;
return NULL ;
}
static void F_123 ( struct V_60 * V_60 )
{
if ( V_60 ) {
F_116 ( V_60 ) ;
F_46 ( V_60 ) ;
F_49 ( V_60 -> V_47 ) ;
F_35 ( V_60 ) ;
}
}
int F_124 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_125 ( V_8 -> V_205 ) ;
struct V_156 * V_156 ;
struct V_60 * V_60 ;
T_2 V_112 ;
if ( ! V_6 -> V_108 || ! V_6 -> V_8 || ! V_6 -> V_102 )
return - V_120 ;
V_112 = F_126 ( V_8 ) - V_9 ;
if ( V_112 < V_126 ) {
return - V_206 ;
}
V_156 = F_127 ( V_6 -> V_62 . V_43 ) ;
V_60 = F_118 ( V_6 , V_112 , V_6 -> V_102 , V_6 -> V_108 ,
V_156 ) ;
if ( ! V_60 )
return - V_82 ;
V_6 -> V_60 = V_60 ;
return 0 ;
}
int F_128 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_125 ( V_8 -> V_205 ) ;
struct V_60 * V_60 = V_6 -> V_60 ;
F_123 ( V_60 ) ;
V_6 -> V_60 = NULL ;
return 0 ;
}
static int T_10 F_129 ( void )
{
int V_202 ;
F_130 ( sizeof( struct V_10 ) != V_9 ) ;
V_193 = F_131 ( 0 , L_32 ) ;
if ( V_193 < 0 )
return V_193 ;
V_63 = F_16 ( L_32 , NULL ) ;
if ( F_17 ( V_63 ) ) {
V_202 = - V_206 ;
goto V_207;
}
return 0 ;
V_207:
F_132 ( V_193 , L_32 ) ;
return V_202 ;
}
static void T_11 F_133 ( void )
{
F_49 ( V_63 ) ;
F_132 ( V_193 , L_32 ) ;
}
