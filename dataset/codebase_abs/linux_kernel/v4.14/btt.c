static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 -> V_5 ;
}
static T_1 F_2 ( struct V_4 * V_4 , T_1 V_6 )
{
return V_6 + V_4 -> V_7 ;
}
static int F_3 ( struct V_2 * V_3 , T_2 V_6 ,
void * V_8 , T_3 V_9 , unsigned long V_10 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_6 = F_2 ( V_4 , V_6 ) ;
return F_4 ( V_12 , V_6 , V_8 , V_9 , V_10 ) ;
}
static int F_5 ( struct V_2 * V_3 , T_2 V_6 ,
void * V_8 , T_3 V_9 , unsigned long V_10 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_6 = F_2 ( V_4 , V_6 ) ;
return F_6 ( V_12 , V_6 , V_8 , V_9 , V_10 ) ;
}
static int F_7 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
int V_15 ;
F_8 ( F_1 ( V_3 ) , ! F_9 ( V_3 -> V_16 , 512 ) ,
L_1 , V_3 -> V_16 ) ;
F_8 ( F_1 ( V_3 ) , ! F_9 ( V_3 -> V_17 , 512 ) ,
L_2 , V_3 -> V_17 ) ;
V_15 = F_5 ( V_3 , V_3 -> V_17 , V_14 ,
sizeof( struct V_13 ) , 0 ) ;
if ( V_15 )
return V_15 ;
return F_5 ( V_3 , V_3 -> V_16 , V_14 ,
sizeof( struct V_13 ) , 0 ) ;
}
static int F_10 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
return F_3 ( V_3 , V_3 -> V_16 , V_14 ,
sizeof( struct V_13 ) , 0 ) ;
}
static int F_11 ( struct V_2 * V_3 , T_4 V_18 , T_5 V_19 ,
unsigned long V_10 )
{
T_1 V_20 = V_3 -> V_21 + ( V_18 * V_22 ) ;
if ( F_12 ( V_18 >= V_3 -> V_23 ) )
F_13 ( F_1 ( V_3 ) ,
L_3 ,
V_24 , V_18 , V_3 -> V_23 ) ;
return F_5 ( V_3 , V_20 , & V_19 , V_22 , V_10 ) ;
}
static int F_14 ( struct V_2 * V_3 , T_4 V_18 , T_4 V_19 ,
T_4 V_25 , T_4 V_26 , unsigned long V_27 )
{
T_4 V_28 ;
T_5 V_29 ;
V_19 = F_15 ( V_19 ) ;
V_28 = ( V_25 << 1 ) + V_26 ;
switch ( V_28 ) {
case 0 :
V_19 |= V_30 ;
break;
case 1 :
V_19 |= ( 1 << V_31 ) ;
break;
case 2 :
V_19 |= ( 1 << V_32 ) ;
break;
default:
F_13 ( F_1 ( V_3 ) ,
L_4 ) ;
return - V_33 ;
}
V_29 = F_16 ( V_19 ) ;
return F_11 ( V_3 , V_18 , V_29 , V_27 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_4 V_18 , T_4 * V_19 ,
int * V_34 , int * error , unsigned long V_27 )
{
int V_15 ;
T_5 V_35 ;
T_4 V_36 , V_37 , V_28 , V_25 , V_26 ;
T_1 V_20 = V_3 -> V_21 + ( V_18 * V_22 ) ;
if ( F_12 ( V_18 >= V_3 -> V_23 ) )
F_13 ( F_1 ( V_3 ) ,
L_3 ,
V_24 , V_18 , V_3 -> V_23 ) ;
V_15 = F_3 ( V_3 , V_20 , & V_35 , V_22 , V_27 ) ;
if ( V_15 )
return V_15 ;
V_36 = F_18 ( V_35 ) ;
V_25 = F_19 ( V_36 ) ;
V_26 = F_20 ( V_36 ) ;
V_28 = ( V_25 << 1 ) + V_26 ;
V_37 = F_15 ( V_36 ) ;
V_25 = 0 ;
V_26 = 0 ;
switch ( V_28 ) {
case 0 :
* V_19 = V_18 ;
break;
case 1 :
* V_19 = V_37 ;
V_26 = 1 ;
break;
case 2 :
* V_19 = V_37 ;
V_25 = 1 ;
break;
case 3 :
* V_19 = V_37 ;
break;
default:
return - V_33 ;
}
if ( V_34 )
* V_34 = V_25 ;
if ( error )
* error = V_26 ;
return V_15 ;
}
static int F_21 ( struct V_2 * V_3 , T_4 V_38 ,
struct V_39 * V_40 )
{
return F_3 ( V_3 ,
V_3 -> V_41 + ( 2 * V_38 * V_42 ) , V_40 ,
2 * V_42 , 0 ) ;
}
static void F_22 ( struct V_2 * V_43 , struct V_44 * V_45 ,
int V_46 )
{
char V_47 [ 32 ] ;
struct V_44 * V_48 ;
if ( ! V_45 )
return;
snprintf ( V_47 , 32 , L_5 , V_46 ) ;
V_48 = F_23 ( V_47 , V_45 ) ;
if ( F_24 ( V_48 ) )
return;
V_43 -> V_49 = V_48 ;
F_25 ( L_6 , V_50 , V_48 , & V_43 -> V_51 ) ;
F_25 ( L_7 , V_50 , V_48 ,
& V_43 -> V_52 ) ;
F_26 ( L_8 , V_50 , V_48 , & V_43 -> V_53 ) ;
F_27 ( L_9 , V_50 , V_48 ,
& V_43 -> V_54 ) ;
F_26 ( L_10 , V_50 , V_48 , & V_43 -> V_23 ) ;
F_27 ( L_11 , V_50 , V_48 ,
& V_43 -> V_55 ) ;
F_27 ( L_12 , V_50 , V_48 , & V_43 -> V_56 ) ;
F_28 ( L_13 , V_50 , V_48 , & V_43 -> V_57 ) ;
F_28 ( L_14 , V_50 , V_48 , & V_43 -> V_58 ) ;
F_25 ( L_15 , V_50 , V_48 , & V_43 -> V_59 ) ;
F_25 ( L_16 , V_50 , V_48 , & V_43 -> V_16 ) ;
F_25 ( L_17 , V_50 , V_48 , & V_43 -> V_60 ) ;
F_25 ( L_18 , V_50 , V_48 , & V_43 -> V_21 ) ;
F_25 ( L_19 , V_50 , V_48 , & V_43 -> V_41 ) ;
F_25 ( L_20 , V_50 , V_48 , & V_43 -> V_17 ) ;
F_26 ( L_21 , V_50 , V_48 , & V_43 -> V_10 ) ;
}
static void F_29 ( struct V_61 * V_61 )
{
int V_62 = 0 ;
struct V_2 * V_3 ;
V_61 -> V_49 = F_23 ( F_30 ( & V_61 -> V_4 -> V_5 ) ,
V_63 ) ;
if ( F_24 ( V_61 -> V_49 ) )
return;
F_31 (arena, &btt->arena_list, list) {
F_22 ( V_3 , V_61 -> V_49 , V_62 ) ;
V_62 ++ ;
}
}
static int F_32 ( struct V_39 * V_40 )
{
int V_64 ;
if ( V_40 [ 0 ] . V_65 == 0 ) {
V_40 [ 0 ] . V_65 = F_16 ( 1 ) ;
return 0 ;
}
if ( V_40 [ 0 ] . V_65 == V_40 [ 1 ] . V_65 )
return - V_66 ;
if ( F_18 ( V_40 [ 0 ] . V_65 ) + F_18 ( V_40 [ 1 ] . V_65 ) > 5 )
return - V_66 ;
if ( F_18 ( V_40 [ 0 ] . V_65 ) < F_18 ( V_40 [ 1 ] . V_65 ) ) {
if ( F_18 ( V_40 [ 1 ] . V_65 ) - F_18 ( V_40 [ 0 ] . V_65 ) == 1 )
V_64 = 0 ;
else
V_64 = 1 ;
} else {
if ( F_18 ( V_40 [ 0 ] . V_65 ) - F_18 ( V_40 [ 1 ] . V_65 ) == 1 )
V_64 = 1 ;
else
V_64 = 0 ;
}
return V_64 ;
}
static int F_33 ( struct V_2 * V_3 , T_4 V_38 ,
struct V_39 * V_40 , int V_67 )
{
int V_15 ;
int V_68 , V_69 ;
struct V_39 log [ 2 ] ;
V_15 = F_21 ( V_3 , V_38 , log ) ;
if ( V_15 )
return - V_33 ;
V_68 = F_32 ( log ) ;
if ( V_68 < 0 || V_68 > 1 ) {
F_34 ( F_1 ( V_3 ) ,
L_22 ,
V_68 , V_38 , log [ 0 ] . V_65 , log [ 1 ] . V_65 ) ;
return - V_33 ;
}
V_69 = ( V_67 ? V_68 : ( 1 - V_68 ) ) ;
if ( V_40 != NULL )
memcpy ( V_40 , & log [ V_69 ] , V_42 ) ;
return V_69 ;
}
static int F_35 ( struct V_2 * V_3 , T_4 V_38 ,
T_4 V_70 , struct V_39 * V_40 , unsigned long V_10 )
{
int V_15 ;
unsigned int V_71 = ( V_42 - 2 * sizeof( T_1 ) ) / 2 ;
T_1 V_20 = V_3 -> V_41 + ( ( ( 2 * V_38 ) + V_70 ) * V_42 ) ;
void * V_72 = V_40 ;
V_15 = F_5 ( V_3 , V_20 , V_72 , V_71 , V_10 ) ;
if ( V_15 )
return V_15 ;
V_20 += V_71 ;
V_72 += V_71 ;
return F_5 ( V_3 , V_20 , V_72 , V_71 , V_10 ) ;
}
static int F_36 ( struct V_2 * V_3 , T_4 V_38 , T_4 V_70 ,
struct V_39 * V_40 )
{
int V_15 ;
V_15 = F_35 ( V_3 , V_38 , V_70 , V_40 , V_73 ) ;
if ( V_15 )
return V_15 ;
V_3 -> V_74 [ V_38 ] . V_70 = 1 - V_3 -> V_74 [ V_38 ] . V_70 ;
if ( ++ ( V_3 -> V_74 [ V_38 ] . V_65 ) == 4 )
V_3 -> V_74 [ V_38 ] . V_65 = 1 ;
if ( F_20 ( V_40 -> V_75 ) )
V_3 -> V_74 [ V_38 ] . V_76 = 1 ;
V_3 -> V_74 [ V_38 ] . V_77 = F_18 ( F_15 ( V_40 -> V_75 ) ) ;
return V_15 ;
}
static int F_37 ( struct V_2 * V_3 )
{
int V_15 = - V_66 ;
void * V_78 ;
T_3 V_6 = 0 ;
T_3 V_79 = V_80 ;
T_3 V_81 = V_3 -> V_41 - V_3 -> V_21 ;
V_78 = F_38 ( V_79 , V_82 ) ;
if ( ! V_78 )
return - V_83 ;
F_8 ( F_1 ( V_3 ) , ! F_9 ( V_3 -> V_21 , 512 ) ,
L_23 , V_3 -> V_21 ) ;
while ( V_81 ) {
T_3 V_51 = F_39 ( V_81 , V_79 ) ;
F_8 ( F_1 ( V_3 ) , V_51 < 512 ,
L_24 , V_51 ) ;
V_15 = F_5 ( V_3 , V_3 -> V_21 + V_6 , V_78 ,
V_51 , 0 ) ;
if ( V_15 )
goto free;
V_6 += V_51 ;
V_81 -= V_51 ;
F_40 () ;
}
free:
F_41 ( V_78 ) ;
return V_15 ;
}
static int F_42 ( struct V_2 * V_3 )
{
T_3 V_84 = V_3 -> V_17 - V_3 -> V_41 ;
T_3 V_79 = V_85 , V_6 = 0 ;
struct V_39 log ;
void * V_78 ;
int V_15 ;
T_4 V_62 ;
V_78 = F_38 ( V_79 , V_82 ) ;
if ( ! V_78 )
return - V_83 ;
F_8 ( F_1 ( V_3 ) , ! F_9 ( V_3 -> V_41 , 512 ) ,
L_25 , V_3 -> V_41 ) ;
while ( V_84 ) {
T_3 V_51 = F_39 ( V_84 , V_79 ) ;
F_8 ( F_1 ( V_3 ) , V_51 < 512 ,
L_24 , V_51 ) ;
V_15 = F_5 ( V_3 , V_3 -> V_41 + V_6 , V_78 ,
V_51 , 0 ) ;
if ( V_15 )
goto free;
V_6 += V_51 ;
V_84 -= V_51 ;
F_40 () ;
}
for ( V_62 = 0 ; V_62 < V_3 -> V_56 ; V_62 ++ ) {
log . V_18 = F_16 ( V_62 ) ;
log . V_75 = F_16 ( V_3 -> V_23 + V_62 ) ;
log . V_86 = F_16 ( V_3 -> V_23 + V_62 ) ;
log . V_65 = F_16 ( V_87 ) ;
V_15 = F_35 ( V_3 , V_62 , 0 , & log , 0 ) ;
if ( V_15 )
goto free;
}
free:
F_41 ( V_78 ) ;
return V_15 ;
}
static T_1 F_43 ( struct V_2 * V_3 , T_1 V_18 )
{
return V_3 -> V_60 + ( ( T_1 ) V_18 * V_3 -> V_54 ) ;
}
static int F_44 ( struct V_2 * V_3 , T_4 V_38 )
{
int V_15 = 0 ;
if ( V_3 -> V_74 [ V_38 ] . V_76 ) {
void * V_88 = F_45 ( F_46 ( 0 ) ) ;
T_4 V_18 = V_3 -> V_74 [ V_38 ] . V_77 ;
T_1 V_89 = F_43 ( V_3 , V_18 ) ;
unsigned long V_90 = V_3 -> V_91 ;
F_47 ( & V_3 -> V_92 ) ;
while ( V_90 ) {
unsigned long V_93 = F_39 ( V_90 , V_94 ) ;
V_15 = F_5 ( V_3 , V_89 , V_88 ,
V_93 , 0 ) ;
if ( V_15 )
break;
V_90 -= V_93 ;
V_89 += V_93 ;
if ( V_90 == 0 )
V_3 -> V_74 [ V_38 ] . V_76 = 0 ;
}
F_48 ( & V_3 -> V_92 ) ;
}
return V_15 ;
}
static int F_49 ( struct V_2 * V_3 )
{
int V_64 , V_95 , V_15 ;
T_4 V_62 , V_96 ;
struct V_39 V_97 , V_98 ;
V_3 -> V_74 = F_50 ( V_3 -> V_56 , sizeof( struct V_99 ) ,
V_82 ) ;
if ( ! V_3 -> V_74 )
return - V_83 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_56 ; V_62 ++ ) {
V_64 = F_33 ( V_3 , V_62 , & V_98 , V_100 ) ;
if ( V_64 < 0 )
return V_64 ;
V_95 = F_33 ( V_3 , V_62 , & V_97 , V_101 ) ;
if ( V_95 < 0 )
return V_95 ;
V_3 -> V_74 [ V_62 ] . V_70 = 1 - V_95 ;
V_3 -> V_74 [ V_62 ] . V_65 = F_51 ( F_18 ( V_97 . V_65 ) ) ;
V_3 -> V_74 [ V_62 ] . V_77 = F_18 ( V_97 . V_75 ) ;
if ( F_20 ( V_97 . V_75 ) ) {
V_15 = F_44 ( V_3 , V_62 ) ;
if ( V_15 )
F_13 ( F_1 ( V_3 ) ,
L_26 ) ;
}
if ( V_97 . V_75 == V_97 . V_86 )
continue;
V_15 = F_17 ( V_3 , F_18 ( V_97 . V_18 ) , & V_96 ,
NULL , NULL , 0 ) ;
if ( V_15 )
return V_15 ;
if ( ( F_18 ( V_97 . V_86 ) != V_96 ) &&
( F_18 ( V_97 . V_75 ) == V_96 ) ) {
V_15 = F_14 ( V_3 , F_18 ( V_97 . V_18 ) ,
F_18 ( V_97 . V_86 ) , 0 , 0 , 0 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
V_3 -> V_102 = F_50 ( V_3 -> V_56 , sizeof( T_4 ) , V_82 ) ;
if ( V_3 -> V_102 == NULL )
return - V_83 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 )
{
T_4 V_62 ;
V_3 -> V_103 = F_50 ( V_3 -> V_56 , sizeof( struct V_104 ) ,
V_82 ) ;
if ( ! V_3 -> V_103 )
return - V_83 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_56 ; V_62 ++ )
F_54 ( & V_3 -> V_103 [ V_62 ] . V_105 ) ;
return 0 ;
}
static struct V_2 * F_55 ( struct V_61 * V_61 , T_3 V_51 ,
T_3 V_106 , T_3 V_107 )
{
struct V_2 * V_3 ;
T_1 V_84 , V_81 , V_108 ;
T_1 V_109 = V_51 ;
V_3 = F_38 ( sizeof( struct V_2 ) , V_82 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_4 = V_61 -> V_4 ;
V_3 -> V_91 = V_61 -> V_91 ;
if ( ! V_51 )
return V_3 ;
V_3 -> V_51 = V_51 ;
V_3 -> V_52 = V_106 ;
V_3 -> V_55 = V_61 -> V_110 ;
V_3 -> V_54 = F_56 ( V_3 -> V_55 ,
V_111 ) ;
V_3 -> V_56 = V_112 ;
V_3 -> V_57 = V_61 -> V_4 -> V_57 ;
V_3 -> V_58 = V_61 -> V_4 -> V_58 ;
if ( V_109 % V_113 )
V_109 -= ( V_109 % V_113 ) ;
V_109 -= 2 * V_113 ;
V_84 = F_56 ( 2 * V_3 -> V_56 * sizeof( struct V_39 ) ,
V_113 ) ;
V_109 -= V_84 ;
V_3 -> V_53 = F_57 ( V_109 - V_113 ,
V_3 -> V_54 + V_22 ) ;
V_3 -> V_23 = V_3 -> V_53 - V_3 -> V_56 ;
V_81 = F_56 ( ( V_3 -> V_23 * V_22 ) , V_113 ) ;
V_108 = V_109 - V_81 ;
V_3 -> V_16 = V_107 ;
V_3 -> V_60 = V_3 -> V_16 + V_113 ;
V_3 -> V_21 = V_3 -> V_60 + V_108 ;
V_3 -> V_41 = V_3 -> V_21 + V_81 ;
V_3 -> V_17 = V_3 -> V_41 + V_84 ;
return V_3 ;
}
static void F_58 ( struct V_61 * V_61 )
{
struct V_2 * V_3 , * V_114 ;
F_59 (arena, next, &btt->arena_list, list) {
F_60 ( & V_3 -> V_115 ) ;
F_41 ( V_3 -> V_102 ) ;
F_41 ( V_3 -> V_103 ) ;
F_41 ( V_3 -> V_74 ) ;
F_61 ( V_3 -> V_49 ) ;
F_41 ( V_3 ) ;
}
}
static void F_62 ( struct V_2 * V_3 , struct V_13 * V_14 ,
T_1 V_107 )
{
V_3 -> V_53 = F_18 ( V_14 -> V_53 ) ;
V_3 -> V_54 = F_18 ( V_14 -> V_54 ) ;
V_3 -> V_23 = F_18 ( V_14 -> V_23 ) ;
V_3 -> V_55 = F_18 ( V_14 -> V_55 ) ;
V_3 -> V_56 = F_18 ( V_14 -> V_56 ) ;
V_3 -> V_57 = F_63 ( V_14 -> V_57 ) ;
V_3 -> V_58 = F_63 ( V_14 -> V_58 ) ;
V_3 -> V_59 = ( V_14 -> V_59 == 0 ) ? 0 : ( V_107 +
F_64 ( V_14 -> V_59 ) ) ;
V_3 -> V_16 = V_107 ;
V_3 -> V_60 = V_107 + F_64 ( V_14 -> V_60 ) ;
V_3 -> V_21 = V_107 + F_64 ( V_14 -> V_21 ) ;
V_3 -> V_41 = V_107 + F_64 ( V_14 -> V_41 ) ;
V_3 -> V_17 = V_107 + F_64 ( V_14 -> V_17 ) ;
V_3 -> V_51 = ( F_64 ( V_14 -> V_59 ) > 0 )
? ( F_64 ( V_14 -> V_59 ) )
: ( V_3 -> V_17 - V_3 -> V_16 + V_113 ) ;
V_3 -> V_10 = F_18 ( V_14 -> V_10 ) ;
}
static int F_65 ( struct V_61 * V_61 )
{
int V_15 = 0 ;
struct V_2 * V_3 ;
struct V_13 * V_14 ;
T_3 V_116 = V_61 -> V_117 ;
T_1 V_118 = 0 ;
T_3 V_119 = 0 ;
int V_120 = 0 ;
V_14 = F_38 ( sizeof( * V_14 ) , V_82 ) ;
if ( ! V_14 )
return - V_83 ;
while ( V_116 ) {
V_3 = F_55 ( V_61 , 0 , 0 , 0 ) ;
if ( ! V_3 ) {
V_15 = - V_83 ;
goto V_121;
}
V_3 -> V_16 = V_119 ;
V_15 = F_10 ( V_3 , V_14 ) ;
if ( V_15 )
goto V_122;
if ( ! F_66 ( V_61 -> V_4 , V_14 ) ) {
if ( V_116 == V_61 -> V_117 ) {
V_61 -> V_123 = V_124 ;
F_67 ( F_1 ( V_3 ) , L_27 ) ;
goto V_122;
} else {
F_34 ( F_1 ( V_3 ) ,
L_28 ) ;
V_15 = - V_125 ;
goto V_122;
}
}
V_3 -> V_52 = V_118 ;
F_62 ( V_3 , V_14 , V_119 ) ;
F_68 ( & V_3 -> V_92 ) ;
V_15 = F_49 ( V_3 ) ;
if ( V_15 )
goto V_122;
V_15 = F_52 ( V_3 ) ;
if ( V_15 )
goto V_122;
V_15 = F_53 ( V_3 ) ;
if ( V_15 )
goto V_122;
F_69 ( & V_3 -> V_115 , & V_61 -> V_126 ) ;
V_116 -= V_3 -> V_51 ;
V_119 += V_3 -> V_51 ;
V_118 += V_3 -> V_23 ;
V_120 ++ ;
if ( V_3 -> V_59 == 0 )
break;
}
V_61 -> V_120 = V_120 ;
V_61 -> V_127 = V_118 ;
V_61 -> V_123 = V_128 ;
F_41 ( V_14 ) ;
return V_15 ;
V_122:
F_41 ( V_3 ) ;
F_58 ( V_61 ) ;
V_121:
F_41 ( V_14 ) ;
return V_15 ;
}
static int F_70 ( struct V_61 * V_61 )
{
T_3 V_116 = V_61 -> V_117 ;
T_3 V_119 = 0 ;
while ( V_116 ) {
struct V_2 * V_3 ;
T_3 V_129 = F_71 ( T_1 , V_130 , V_116 ) ;
V_116 -= V_129 ;
if ( V_129 < V_131 )
break;
V_3 = F_55 ( V_61 , V_129 , V_61 -> V_127 , V_119 ) ;
if ( ! V_3 ) {
F_58 ( V_61 ) ;
return - V_83 ;
}
V_61 -> V_127 += V_3 -> V_23 ;
if ( V_116 >= V_131 )
V_3 -> V_59 = V_3 -> V_51 ;
else
V_3 -> V_59 = 0 ;
V_119 += V_129 ;
F_69 ( & V_3 -> V_115 , & V_61 -> V_126 ) ;
}
return 0 ;
}
static int F_72 ( struct V_2 * V_3 )
{
int V_15 ;
T_1 V_132 ;
struct V_13 * V_14 ;
struct V_4 * V_4 = V_3 -> V_4 ;
const T_6 * V_133 = F_73 ( & V_4 -> V_12 -> V_5 ) ;
V_15 = F_37 ( V_3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_42 ( V_3 ) ;
if ( V_15 )
return V_15 ;
V_14 = F_38 ( sizeof( struct V_13 ) , V_134 ) ;
if ( ! V_14 )
return - V_83 ;
strncpy ( V_14 -> V_135 , V_136 , V_137 ) ;
memcpy ( V_14 -> V_138 , V_4 -> V_138 , 16 ) ;
memcpy ( V_14 -> V_133 , V_133 , 16 ) ;
V_14 -> V_10 = F_16 ( V_3 -> V_10 ) ;
V_14 -> V_57 = F_74 ( V_3 -> V_57 ) ;
V_14 -> V_58 = F_74 ( V_3 -> V_58 ) ;
V_14 -> V_55 = F_16 ( V_3 -> V_55 ) ;
V_14 -> V_23 = F_16 ( V_3 -> V_23 ) ;
V_14 -> V_54 = F_16 ( V_3 -> V_54 ) ;
V_14 -> V_53 = F_16 ( V_3 -> V_53 ) ;
V_14 -> V_56 = F_16 ( V_3 -> V_56 ) ;
V_14 -> V_139 = F_16 ( sizeof( struct V_13 ) ) ;
V_14 -> V_59 = F_75 ( V_3 -> V_59 ) ;
V_14 -> V_60 = F_75 ( V_3 -> V_60 - V_3 -> V_16 ) ;
V_14 -> V_21 = F_75 ( V_3 -> V_21 - V_3 -> V_16 ) ;
V_14 -> V_41 = F_75 ( V_3 -> V_41 - V_3 -> V_16 ) ;
V_14 -> V_17 = F_75 ( V_3 -> V_17 - V_3 -> V_16 ) ;
V_14 -> V_10 = 0 ;
V_132 = F_76 ( (struct V_140 * ) V_14 ) ;
V_14 -> V_141 = F_75 ( V_132 ) ;
V_15 = F_7 ( V_3 , V_14 ) ;
F_41 ( V_14 ) ;
return V_15 ;
}
static int F_77 ( struct V_61 * V_61 )
{
int V_15 = 0 ;
struct V_2 * V_3 ;
F_47 ( & V_61 -> V_142 ) ;
F_31 (arena, &btt->arena_list, list) {
V_15 = F_72 ( V_3 ) ;
if ( V_15 )
goto V_143;
V_15 = F_49 ( V_3 ) ;
if ( V_15 )
goto V_143;
V_15 = F_52 ( V_3 ) ;
if ( V_15 )
goto V_143;
V_15 = F_53 ( V_3 ) ;
if ( V_15 )
goto V_143;
}
V_61 -> V_123 = V_128 ;
V_143:
F_48 ( & V_61 -> V_142 ) ;
return V_15 ;
}
static T_4 F_78 ( struct V_61 * V_61 )
{
return V_61 -> V_110 - V_61 -> V_91 ;
}
static int F_79 ( struct V_61 * V_61 , T_7 V_144 , T_8 * V_145 ,
struct V_2 * * V_3 )
{
struct V_2 * V_126 ;
T_9 V_18 = F_57 ( V_144 << V_146 , V_61 -> V_91 ) ;
F_31 (arena_list, &btt->arena_list, list) {
if ( V_18 < V_126 -> V_23 ) {
* V_3 = V_126 ;
* V_145 = V_18 ;
return 0 ;
}
V_18 -= V_126 -> V_23 ;
}
return - V_33 ;
}
static void F_80 ( struct V_2 * V_3 , T_4 V_145 )
__acquires( &arena->map_locks[idx].lock
static void F_81 ( struct V_2 * V_3 , T_4 V_145 )
__releases( &arena->map_locks[idx].lock
static int F_82 ( struct V_2 * V_3 , struct V_147 * V_147 ,
unsigned int V_148 , T_4 V_18 , T_4 V_90 )
{
int V_15 ;
T_1 V_89 = F_43 ( V_3 , V_18 ) ;
void * V_149 = F_83 ( V_147 ) ;
V_15 = F_3 ( V_3 , V_89 , V_149 + V_148 , V_90 , V_73 ) ;
F_84 ( V_149 ) ;
return V_15 ;
}
static int F_85 ( struct V_2 * V_3 , T_4 V_18 ,
struct V_147 * V_147 , unsigned int V_148 , T_4 V_90 )
{
int V_15 ;
T_1 V_89 = F_43 ( V_3 , V_18 ) ;
void * V_149 = F_83 ( V_147 ) ;
V_15 = F_5 ( V_3 , V_89 , V_149 + V_148 , V_90 , V_73 ) ;
F_84 ( V_149 ) ;
return V_15 ;
}
static void F_86 ( struct V_147 * V_147 , unsigned int V_148 , T_4 V_90 )
{
void * V_149 = F_83 ( V_147 ) ;
memset ( V_149 + V_148 , 0 , V_90 ) ;
F_84 ( V_149 ) ;
}
static int F_87 ( struct V_61 * V_61 , struct V_150 * V_151 ,
struct V_2 * V_3 , T_4 V_37 , int V_152 )
{
unsigned int V_90 = F_78 ( V_61 ) ;
T_1 V_153 ;
int V_15 = 0 ;
if ( V_151 == NULL )
return 0 ;
V_153 = F_43 ( V_3 , V_37 ) + V_61 -> V_91 ;
while ( V_90 ) {
unsigned int V_154 ;
struct V_155 V_156 ;
void * V_149 ;
V_156 = F_88 ( V_151 -> V_157 , V_151 -> V_158 ) ;
V_154 = F_39 ( V_90 , V_156 . V_159 ) ;
V_149 = F_83 ( V_156 . V_160 ) ;
if ( V_152 )
V_15 = F_5 ( V_3 , V_153 ,
V_149 + V_156 . V_161 , V_154 ,
V_73 ) ;
else
V_15 = F_3 ( V_3 , V_153 ,
V_149 + V_156 . V_161 , V_154 ,
V_73 ) ;
F_84 ( V_149 ) ;
if ( V_15 )
return V_15 ;
V_90 -= V_154 ;
V_153 += V_154 ;
if ( ! F_89 ( V_151 -> V_157 , & V_151 -> V_158 , V_154 ) )
return - V_33 ;
}
return V_15 ;
}
static int F_87 ( struct V_61 * V_61 , struct V_150 * V_151 ,
struct V_2 * V_3 , T_4 V_37 , int V_152 )
{
return 0 ;
}
static int F_90 ( struct V_61 * V_61 , struct V_150 * V_151 ,
struct V_147 * V_147 , unsigned int V_148 , T_7 V_144 ,
unsigned int V_90 )
{
int V_15 = 0 ;
int V_162 , V_26 ;
struct V_2 * V_3 = NULL ;
T_4 V_38 = 0 , V_145 , V_37 ;
while ( V_90 ) {
T_4 V_154 ;
V_38 = F_91 ( V_61 -> V_163 ) ;
V_15 = F_79 ( V_61 , V_144 , & V_145 , & V_3 ) ;
if ( V_15 )
goto V_164;
V_154 = F_39 ( V_61 -> V_91 , V_90 ) ;
V_15 = F_17 ( V_3 , V_145 , & V_37 , & V_162 , & V_26 ,
V_73 ) ;
if ( V_15 )
goto V_164;
while ( 1 ) {
T_4 V_86 ;
int V_165 , V_166 ;
if ( V_162 ) {
F_86 ( V_147 , V_148 , V_154 ) ;
goto V_164;
}
if ( V_26 ) {
V_15 = - V_33 ;
goto V_164;
}
V_3 -> V_102 [ V_38 ] = V_167 | V_37 ;
F_92 () ;
V_15 = F_17 ( V_3 , V_145 , & V_86 , & V_165 ,
& V_166 , V_73 ) ;
if ( V_15 )
goto V_168;
if ( ( V_37 == V_86 ) && ( V_162 == V_165 ) &&
( V_26 == V_166 ) )
break;
V_37 = V_86 ;
V_162 = V_165 ;
V_26 = V_166 ;
}
V_15 = F_82 ( V_3 , V_147 , V_148 , V_37 , V_154 ) ;
if ( V_15 ) {
int V_169 ;
V_169 = F_14 ( V_3 , V_145 , V_37 , 0 , 1 ,
V_73 ) ;
goto V_168;
}
if ( V_151 ) {
V_15 = F_87 ( V_61 , V_151 , V_3 , V_37 , V_170 ) ;
if ( V_15 )
goto V_168;
}
V_3 -> V_102 [ V_38 ] = V_171 ;
F_93 ( V_61 -> V_163 , V_38 ) ;
V_90 -= V_154 ;
V_148 += V_154 ;
V_144 += V_61 -> V_91 >> V_146 ;
}
return 0 ;
V_168:
V_3 -> V_102 [ V_38 ] = V_171 ;
V_164:
F_93 ( V_61 -> V_163 , V_38 ) ;
return V_15 ;
}
static bool F_94 ( struct V_61 * V_61 , struct V_2 * V_3 ,
T_4 V_37 )
{
T_1 V_89 = F_2 ( V_3 -> V_4 ,
F_43 ( V_3 , V_37 ) ) ;
T_7 V_172 = V_89 >> 9 ;
return F_95 ( V_61 -> V_173 , V_172 , V_3 -> V_54 ) ;
}
static int F_96 ( struct V_61 * V_61 , struct V_150 * V_151 ,
T_7 V_144 , struct V_147 * V_147 , unsigned int V_148 ,
unsigned int V_90 )
{
int V_15 = 0 ;
struct V_2 * V_3 = NULL ;
T_4 V_145 = 0 , V_174 , V_175 , V_38 = 0 , V_62 ;
struct V_39 log ;
int V_70 ;
while ( V_90 ) {
T_4 V_154 ;
int V_26 ;
V_176:
V_38 = F_91 ( V_61 -> V_163 ) ;
V_15 = F_79 ( V_61 , V_144 , & V_145 , & V_3 ) ;
if ( V_15 )
goto V_164;
V_154 = F_39 ( V_61 -> V_91 , V_90 ) ;
if ( ( V_3 -> V_10 & V_177 ) != 0 ) {
V_15 = - V_33 ;
goto V_164;
}
if ( F_94 ( V_61 , V_3 , V_3 -> V_74 [ V_38 ] . V_77 ) )
V_3 -> V_74 [ V_38 ] . V_76 = 1 ;
if ( F_97 ( & V_3 -> V_92 )
|| V_3 -> V_74 [ V_38 ] . V_76 ) {
F_93 ( V_61 -> V_163 , V_38 ) ;
V_15 = F_44 ( V_3 , V_38 ) ;
if ( V_15 )
return V_15 ;
goto V_176;
}
V_175 = V_3 -> V_74 [ V_38 ] . V_77 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_56 ; V_62 ++ )
while ( V_3 -> V_102 [ V_62 ] == ( V_167 | V_175 ) )
F_98 () ;
if ( V_175 >= V_3 -> V_53 ) {
V_15 = - V_33 ;
goto V_164;
}
V_15 = F_85 ( V_3 , V_175 , V_147 , V_148 , V_154 ) ;
if ( V_15 )
goto V_164;
if ( V_151 ) {
V_15 = F_87 ( V_61 , V_151 , V_3 , V_175 ,
V_178 ) ;
if ( V_15 )
goto V_164;
}
F_80 ( V_3 , V_145 ) ;
V_15 = F_17 ( V_3 , V_145 , & V_174 , NULL , & V_26 ,
V_73 ) ;
if ( V_15 )
goto V_179;
if ( V_174 >= V_3 -> V_53 ) {
V_15 = - V_33 ;
goto V_179;
}
if ( V_26 )
F_99 ( V_174 ) ;
log . V_18 = F_16 ( V_145 ) ;
log . V_75 = F_16 ( V_174 ) ;
log . V_86 = F_16 ( V_175 ) ;
log . V_65 = F_16 ( V_3 -> V_74 [ V_38 ] . V_65 ) ;
V_70 = V_3 -> V_74 [ V_38 ] . V_70 ;
V_15 = F_36 ( V_3 , V_38 , V_70 , & log ) ;
if ( V_15 )
goto V_179;
V_15 = F_14 ( V_3 , V_145 , V_175 , 0 , 0 ,
V_73 ) ;
if ( V_15 )
goto V_179;
F_81 ( V_3 , V_145 ) ;
F_93 ( V_61 -> V_163 , V_38 ) ;
if ( V_26 ) {
V_15 = F_44 ( V_3 , V_38 ) ;
if ( V_15 )
return V_15 ;
}
V_90 -= V_154 ;
V_148 += V_154 ;
V_144 += V_61 -> V_91 >> V_146 ;
}
return 0 ;
V_179:
F_81 ( V_3 , V_145 ) ;
V_164:
F_93 ( V_61 -> V_163 , V_38 ) ;
return V_15 ;
}
static int F_100 ( struct V_61 * V_61 , struct V_150 * V_151 ,
struct V_147 * V_147 , unsigned int V_90 , unsigned int V_148 ,
bool V_180 , T_7 V_144 )
{
int V_15 ;
if ( ! V_180 ) {
V_15 = F_90 ( V_61 , V_151 , V_147 , V_148 , V_144 , V_90 ) ;
F_101 ( V_147 ) ;
} else {
F_101 ( V_147 ) ;
V_15 = F_96 ( V_61 , V_151 , V_144 , V_147 , V_148 , V_90 ) ;
}
return V_15 ;
}
static T_10 F_102 ( struct V_181 * V_182 , struct V_183 * V_183 )
{
struct V_150 * V_151 = F_103 ( V_183 ) ;
struct V_61 * V_61 = V_182 -> V_184 ;
struct V_185 V_186 ;
unsigned long V_106 ;
struct V_155 V_187 ;
int V_188 = 0 ;
bool V_189 ;
if ( ! F_104 ( V_183 ) )
return V_190 ;
V_189 = F_105 ( V_183 , & V_106 ) ;
F_106 (bvec, bio, iter) {
unsigned int V_90 = V_187 . V_159 ;
if ( V_90 > V_94 || V_90 < V_61 -> V_91 ||
V_90 % V_61 -> V_91 ) {
F_13 ( & V_61 -> V_4 -> V_5 ,
L_29 , V_90 ) ;
V_183 -> V_191 = V_192 ;
break;
}
V_188 = F_100 ( V_61 , V_151 , V_187 . V_160 , V_90 , V_187 . V_161 ,
F_107 ( F_108 ( V_183 ) ) , V_186 . V_193 ) ;
if ( V_188 ) {
F_34 ( & V_61 -> V_4 -> V_5 ,
L_30 ,
( F_107 ( F_108 ( V_183 ) ) ) ? L_31 :
L_32 ,
( unsigned long long ) V_186 . V_193 , V_90 ) ;
V_183 -> V_191 = F_109 ( V_188 ) ;
break;
}
}
if ( V_189 )
F_110 ( V_183 , V_106 ) ;
F_111 ( V_183 ) ;
return V_190 ;
}
static int F_112 ( struct V_194 * V_195 , T_7 V_144 ,
struct V_147 * V_147 , bool V_180 )
{
struct V_61 * V_61 = V_195 -> V_196 -> V_197 ;
int V_169 ;
unsigned int V_90 ;
V_90 = F_113 ( V_147 ) * V_94 ;
V_169 = F_100 ( V_61 , NULL , V_147 , V_90 , 0 , V_180 , V_144 ) ;
if ( V_169 == 0 )
F_114 ( V_147 , V_180 , 0 ) ;
return V_169 ;
}
static int F_115 ( struct V_194 * V_198 , struct V_199 * V_200 )
{
V_200 -> V_201 = 1 << 6 ;
V_200 -> V_202 = 1 << 5 ;
V_200 -> V_203 = F_116 ( V_198 -> V_196 ) >> 11 ;
return 0 ;
}
static int F_117 ( struct V_61 * V_61 )
{
struct V_4 * V_4 = V_61 -> V_4 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_61 -> V_204 = F_118 ( V_82 ) ;
if ( ! V_61 -> V_204 )
return - V_83 ;
V_61 -> V_205 = F_119 ( 0 ) ;
if ( ! V_61 -> V_205 ) {
F_120 ( V_61 -> V_204 ) ;
return - V_83 ;
}
F_121 ( V_12 , V_61 -> V_205 -> V_206 ) ;
V_61 -> V_205 -> V_207 = 0 ;
V_61 -> V_205 -> V_208 = & V_209 ;
V_61 -> V_205 -> V_197 = V_61 ;
V_61 -> V_205 -> V_210 = V_61 -> V_204 ;
V_61 -> V_205 -> V_10 = V_211 ;
F_122 ( V_61 -> V_204 , F_102 ) ;
F_123 ( V_61 -> V_204 , V_61 -> V_91 ) ;
F_124 ( V_61 -> V_204 , V_212 ) ;
F_125 ( V_213 , V_61 -> V_204 ) ;
V_61 -> V_204 -> V_184 = V_61 ;
F_126 ( V_61 -> V_205 , 0 ) ;
F_127 ( & V_61 -> V_4 -> V_5 , V_61 -> V_205 ) ;
if ( F_78 ( V_61 ) ) {
int V_169 = F_128 ( V_61 -> V_205 , F_78 ( V_61 ) ) ;
if ( V_169 ) {
F_129 ( V_61 -> V_205 ) ;
F_130 ( V_61 -> V_205 ) ;
F_120 ( V_61 -> V_204 ) ;
return V_169 ;
}
}
F_126 ( V_61 -> V_205 , V_61 -> V_127 * V_61 -> V_91 >> 9 ) ;
V_61 -> V_4 -> V_51 = V_61 -> V_127 * ( T_1 ) V_61 -> V_91 ;
F_131 ( V_61 -> V_205 ) ;
return 0 ;
}
static void F_132 ( struct V_61 * V_61 )
{
F_129 ( V_61 -> V_205 ) ;
F_130 ( V_61 -> V_205 ) ;
F_120 ( V_61 -> V_204 ) ;
}
static struct V_61 * F_133 ( struct V_4 * V_4 , unsigned long long V_117 ,
T_4 V_110 , T_6 * V_138 , struct V_163 * V_163 )
{
int V_15 ;
struct V_61 * V_61 ;
struct V_214 * V_215 ;
struct V_1 * V_5 = & V_4 -> V_5 ;
V_61 = F_134 ( V_5 , sizeof( struct V_61 ) , V_82 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_4 = V_4 ;
V_61 -> V_117 = V_117 ;
V_61 -> V_110 = V_110 ;
V_61 -> V_91 = ( ( V_110 >= 4096 ) ? 4096 : 512 ) ;
F_135 ( & V_61 -> V_126 ) ;
F_68 ( & V_61 -> V_142 ) ;
V_61 -> V_163 = V_163 ;
V_215 = F_136 ( & V_4 -> V_12 -> V_5 ) ;
V_61 -> V_173 = & V_215 -> V_216 ;
V_15 = F_65 ( V_61 ) ;
if ( V_15 ) {
F_34 ( V_5 , L_33 , V_15 ) ;
return NULL ;
}
if ( V_61 -> V_123 != V_128 && V_163 -> V_217 ) {
F_137 ( V_5 , L_34 ,
F_30 ( & V_163 -> V_5 ) ) ;
return NULL ;
} else if ( V_61 -> V_123 != V_128 ) {
V_61 -> V_120 = ( V_117 / V_130 ) +
( ( V_117 % V_130 ) ? 1 : 0 ) ;
F_138 ( V_5 , L_35 ,
V_61 -> V_120 , V_117 ) ;
V_15 = F_70 ( V_61 ) ;
if ( V_15 ) {
F_67 ( V_5 , L_36 , V_15 ) ;
return NULL ;
}
V_15 = F_77 ( V_61 ) ;
if ( V_15 ) {
F_34 ( V_5 , L_37 , V_15 ) ;
return NULL ;
}
}
V_15 = F_117 ( V_61 ) ;
if ( V_15 ) {
F_34 ( V_5 , L_38 , V_15 ) ;
return NULL ;
}
F_29 ( V_61 ) ;
return V_61 ;
}
static void F_139 ( struct V_61 * V_61 )
{
if ( V_61 ) {
F_132 ( V_61 ) ;
F_58 ( V_61 ) ;
F_61 ( V_61 -> V_49 ) ;
}
}
int F_140 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_141 ( V_12 -> V_218 ) ;
struct V_163 * V_163 ;
struct V_13 * V_13 ;
struct V_61 * V_61 ;
T_3 V_117 ;
if ( ! V_4 -> V_138 || ! V_4 -> V_12 || ! V_4 -> V_110 ) {
F_138 ( & V_4 -> V_5 , L_39 ) ;
return - V_125 ;
}
V_13 = F_134 ( & V_4 -> V_5 , sizeof( * V_13 ) , V_82 ) ;
if ( ! V_13 )
return - V_83 ;
F_142 ( V_4 , V_12 , V_13 ) ;
V_117 = F_143 ( V_12 ) - V_4 -> V_7 ;
if ( V_117 < V_131 ) {
F_138 ( & V_4 -> V_5 , L_40 ,
F_30 ( & V_12 -> V_5 ) ,
V_131 + V_4 -> V_7 ) ;
return - V_219 ;
}
V_163 = F_144 ( V_4 -> V_5 . V_45 ) ;
V_61 = F_133 ( V_4 , V_117 , V_4 -> V_110 , V_4 -> V_138 ,
V_163 ) ;
if ( ! V_61 )
return - V_83 ;
V_4 -> V_61 = V_61 ;
return 0 ;
}
int F_145 ( struct V_4 * V_4 )
{
struct V_61 * V_61 = V_4 -> V_61 ;
F_139 ( V_61 ) ;
V_4 -> V_61 = NULL ;
return 0 ;
}
static int T_11 F_146 ( void )
{
int V_169 = 0 ;
V_63 = F_23 ( L_41 , NULL ) ;
if ( F_24 ( V_63 ) )
V_169 = - V_219 ;
return V_169 ;
}
static void T_12 F_147 ( void )
{
F_61 ( V_63 ) ;
}
