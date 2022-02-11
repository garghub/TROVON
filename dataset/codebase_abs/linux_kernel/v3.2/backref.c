static int F_1 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * V_9 )
{
int V_10 ;
struct V_8 V_11 ;
struct V_12 * V_13 ;
V_11 . type = V_3 ;
V_11 . V_14 = V_1 ;
V_11 . V_15 = V_2 ;
V_10 = F_2 ( NULL , V_5 , & V_11 , V_7 , 0 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_13 = V_7 -> V_16 [ 0 ] ;
if ( V_10 && V_7 -> V_17 [ 0 ] >= F_3 ( V_13 ) ) {
V_10 = F_4 ( V_5 , V_7 ) ;
if ( V_10 )
return V_10 ;
V_13 = V_7 -> V_16 [ 0 ] ;
}
F_5 ( V_13 , V_9 , V_7 -> V_17 [ 0 ] ) ;
if ( V_9 -> type != V_11 . type || V_9 -> V_14 != V_11 . V_14 )
return 1 ;
return 0 ;
}
int F_6 ( T_1 V_1 , T_1 V_2 , struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 V_11 ;
return F_1 ( V_1 , V_2 , V_18 , V_5 , V_7 ,
& V_11 ) ;
}
static int F_7 ( T_1 V_1 , T_1 V_2 , struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
return F_1 ( V_1 , V_2 , V_19 , V_5 , V_7 ,
V_9 ) ;
}
static char * F_8 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_20 * V_21 ,
struct V_12 * V_22 , T_1 V_23 ,
char * V_24 , T_3 V_25 )
{
T_3 V_26 ;
int V_27 ;
T_1 V_28 ;
int V_10 ;
T_4 V_29 = V_25 - 1 ;
struct V_12 * V_13 = V_22 ;
struct V_8 V_9 ;
if ( V_29 >= 0 )
V_24 [ V_29 ] = '\0' ;
while ( 1 ) {
V_26 = F_9 ( V_13 , V_21 ) ;
V_29 -= V_26 ;
if ( V_29 >= 0 )
F_10 ( V_13 , V_24 + V_29 ,
( unsigned long ) ( V_21 + 1 ) , V_26 ) ;
if ( V_13 != V_22 )
F_11 ( V_13 ) ;
V_10 = F_7 ( V_23 , 0 , V_5 , V_7 , & V_9 ) ;
if ( V_10 )
break;
V_28 = V_9 . V_15 ;
if ( V_23 == V_28 )
break;
V_27 = V_7 -> V_17 [ 0 ] ;
V_13 = V_7 -> V_16 [ 0 ] ;
if ( V_13 != V_22 )
F_12 ( & V_13 -> V_30 ) ;
F_13 ( V_7 ) ;
V_21 = F_14 ( V_13 , V_27 , struct V_20 ) ;
V_23 = V_28 ;
-- V_29 ;
if ( V_29 >= 0 )
V_24 [ V_29 ] = '/' ;
}
F_13 ( V_7 ) ;
if ( V_10 )
return F_15 ( V_10 ) ;
return V_24 + V_29 ;
}
int F_16 ( struct V_31 * V_32 , T_1 V_33 ,
struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_10 ;
T_1 V_34 ;
T_3 V_35 ;
struct V_12 * V_13 ;
struct V_36 * V_37 ;
struct V_8 V_11 ;
V_11 . type = V_38 ;
V_11 . V_14 = V_33 ;
V_11 . V_15 = ( T_1 ) - 1 ;
V_10 = F_2 ( NULL , V_32 -> V_39 , & V_11 , V_7 , 0 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_32 -> V_39 , V_7 ,
0 , V_38 ) ;
if ( V_10 < 0 )
return V_10 ;
F_5 ( V_7 -> V_16 [ 0 ] , V_9 , V_7 -> V_17 [ 0 ] ) ;
if ( V_9 -> type != V_38 ||
V_9 -> V_14 > V_33 ||
V_9 -> V_14 + V_9 -> V_15 <= V_33 )
return - V_40 ;
V_13 = V_7 -> V_16 [ 0 ] ;
V_35 = F_18 ( V_13 , V_7 -> V_17 [ 0 ] ) ;
F_19 ( V_35 < sizeof( * V_37 ) ) ;
V_37 = F_14 ( V_13 , V_7 -> V_17 [ 0 ] , struct V_36 ) ;
V_34 = F_20 ( V_13 , V_37 ) ;
if ( V_34 & V_41 )
return V_41 ;
if ( V_34 & V_42 )
return V_42 ;
return - V_43 ;
}
static int F_21 ( unsigned long * V_44 , struct V_12 * V_13 ,
struct V_36 * V_37 , T_3 V_35 ,
struct V_45 * * V_46 ,
int * V_47 )
{
unsigned long V_48 ;
T_1 V_34 ;
struct V_49 * V_50 ;
if ( ! * V_44 ) {
V_34 = F_20 ( V_13 , V_37 ) ;
if ( V_34 & V_41 ) {
V_50 = (struct V_49 * ) ( V_37 + 1 ) ;
* V_46 =
(struct V_45 * ) ( V_50 + 1 ) ;
} else {
* V_46 = (struct V_45 * ) ( V_37 + 1 ) ;
}
* V_44 = ( unsigned long ) * V_46 ;
if ( ( void * ) * V_44 >= ( void * ) V_37 + V_35 )
return - V_40 ;
}
V_48 = ( unsigned long ) V_37 + V_35 ;
* V_46 = (struct V_45 * ) * V_44 ;
* V_47 = F_22 ( V_13 , * V_46 ) ;
* V_44 += F_23 ( * V_47 ) ;
F_24 ( * V_44 > V_48 ) ;
if ( * V_44 == V_48 )
return 1 ;
return 0 ;
}
int F_25 ( unsigned long * V_44 , struct V_12 * V_13 ,
struct V_36 * V_37 , T_3 V_35 ,
T_1 * V_51 , T_2 * V_52 )
{
int V_10 ;
int type ;
struct V_49 * V_50 ;
struct V_45 * V_53 ;
if ( * V_44 == ( unsigned long ) - 1 )
return 1 ;
while ( 1 ) {
V_10 = F_21 ( V_44 , V_13 , V_37 , V_35 ,
& V_53 , & type ) ;
if ( V_10 < 0 )
return V_10 ;
if ( type == V_54 ||
type == V_55 )
break;
if ( V_10 == 1 )
return 1 ;
}
V_50 = (struct V_49 * ) ( V_37 + 1 ) ;
* V_51 = F_26 ( V_13 , V_53 ) ;
* V_52 = F_27 ( V_13 , V_50 ) ;
if ( V_10 == 1 )
* V_44 = ( unsigned long ) - 1 ;
return 0 ;
}
static int F_28 ( struct V_56 * V_57 , T_1 V_1 ,
T_1 V_58 , T_1 V_59 )
{
struct V_60 * V_61 ;
V_61 = F_29 ( sizeof( * V_61 ) , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
V_61 -> V_1 = V_1 ;
V_61 -> V_58 = V_58 ;
V_61 -> V_59 = V_59 ;
F_30 ( & V_61 -> V_64 , V_57 ) ;
return 0 ;
}
static int F_31 ( struct V_56 * V_57 , struct V_12 * V_13 ,
struct V_65 * V_66 )
{
return F_28 ( V_57 , F_32 ( V_13 , V_66 ) ,
F_33 ( V_13 , V_66 ) ,
F_34 ( V_13 , V_66 ) ) ;
}
static int F_35 ( struct V_56 * V_57 , T_1 V_67 )
{
struct V_68 * V_61 ;
V_61 = F_29 ( sizeof( * V_61 ) , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
V_61 -> V_67 = V_67 ;
F_30 ( & V_61 -> V_64 , V_57 ) ;
return 0 ;
}
static int F_36 ( struct V_31 * V_32 ,
T_1 V_33 , T_1 V_1 ,
T_1 V_58 ,
T_1 V_69 ,
struct V_6 * V_7 ,
struct V_56 * V_70 ,
T_5 * V_71 ,
void * V_72 )
{
T_1 V_73 ;
T_3 V_35 ;
struct V_8 V_11 ;
struct V_12 * V_13 ;
struct V_36 * V_37 ;
struct V_45 * V_53 ;
struct V_60 * V_61 ;
int V_10 ;
int type ;
int V_74 ;
unsigned long V_44 = 0 ;
F_24 ( ! F_37 ( V_70 ) ) ;
V_10 = F_16 ( V_32 , V_33 , V_7 , & V_11 ) ;
if ( V_10 & V_42 )
V_10 = - V_43 ;
if ( V_10 < 0 )
goto V_75;
V_13 = V_7 -> V_16 [ 0 ] ;
V_37 = F_14 ( V_13 , V_7 -> V_17 [ 0 ] , struct V_36 ) ;
V_35 = F_18 ( V_13 , V_7 -> V_17 [ 0 ] ) ;
V_10 = 0 ;
V_73 = 0 ;
do {
V_74 = F_21 ( & V_44 , V_13 , V_37 , V_35 ,
& V_53 , & type ) ;
if ( V_74 < 0 ) {
V_10 = V_74 ;
goto V_75;
}
if ( type == V_54 ||
type == V_55 ) {
V_73 = F_26 ( V_13 , V_53 ) ;
V_10 = F_28 ( V_70 , V_1 ,
V_58 ,
V_73 ) ;
}
} while ( ! V_10 && ! V_74 );
F_13 ( V_7 ) ;
if ( V_73 == 0 ) {
F_38 ( V_76 L_1
L_2 , V_33 ) ;
F_24 ( 1 ) ;
V_10 = - V_43 ;
}
V_75:
while ( ! F_37 ( V_70 ) ) {
V_61 = F_39 ( V_70 , struct V_60 , V_64 ) ;
F_40 ( & V_61 -> V_64 ) ;
if ( ! V_10 )
V_10 = V_71 ( V_61 -> V_1 , V_69 +
V_61 -> V_58 ,
V_61 -> V_59 , V_72 ) ;
F_41 ( V_61 ) ;
}
return V_10 ;
}
static int F_42 ( struct V_31 * V_32 ,
T_1 V_33 , T_1 V_77 ,
T_1 V_69 , struct V_6 * V_7 ,
struct V_56 * V_70 ,
T_5 * V_71 ,
void * V_72 )
{
T_1 V_67 ;
struct V_8 V_11 ;
struct V_78 * V_79 ;
struct V_12 * V_13 ;
int V_27 ;
int V_80 ;
int V_10 ;
int V_81 = 0 ;
V_13 = F_43 ( V_32 -> V_82 , V_33 ,
V_32 -> V_82 -> V_83 , 0 ) ;
if ( ! V_13 )
return - V_43 ;
V_80 = F_3 ( V_13 ) ;
for ( V_27 = 0 ; V_27 < V_80 ; ++ V_27 ) {
F_5 ( V_13 , & V_11 , V_27 ) ;
if ( V_11 . type != V_84 )
continue;
V_79 = F_14 ( V_13 , V_27 , struct V_78 ) ;
if ( ! V_79 ) {
F_11 ( V_13 ) ;
return - V_43 ;
}
V_67 = F_44 ( V_13 , V_79 ) ;
if ( V_67 != V_77 ) {
if ( V_81 )
break;
else
continue;
}
++ V_81 ;
V_10 = F_36 ( V_32 , V_33 ,
V_11 . V_14 ,
V_11 . V_15 ,
V_69 , V_7 ,
V_70 ,
V_71 , V_72 ) ;
if ( V_10 )
break;
}
if ( ! V_81 ) {
F_38 ( V_76 L_3
L_4 , V_33 ) ;
F_24 ( 1 ) ;
V_10 = - V_43 ;
}
F_11 ( V_13 ) ;
return V_10 ;
}
int F_45 ( struct V_31 * V_32 ,
struct V_6 * V_7 ,
T_1 V_85 ,
T_1 V_69 ,
T_5 * V_71 , void * V_72 )
{
unsigned long V_44 = 0 ;
int V_74 ;
int V_10 ;
int type ;
T_1 V_33 ;
T_3 V_35 ;
struct V_45 * V_53 ;
struct V_65 * V_66 ;
struct V_12 * V_13 ;
struct V_36 * V_37 ;
struct V_8 V_11 ;
struct V_56 V_70 = F_46 ( V_70 ) ;
struct V_56 V_86 = F_46 ( V_86 ) ;
struct V_60 * V_87 ;
struct V_68 * V_88 ;
V_13 = V_7 -> V_16 [ 0 ] ;
V_37 = F_14 ( V_13 , V_7 -> V_17 [ 0 ] , struct V_36 ) ;
V_35 = F_18 ( V_13 , V_7 -> V_17 [ 0 ] ) ;
do {
V_74 = F_21 ( & V_44 , V_13 , V_37 , V_35 ,
& V_53 , & type ) ;
if ( V_74 == - V_40 ) {
V_10 = 0 ;
break;
}
if ( V_74 < 0 ) {
V_10 = V_74 ;
break;
}
if ( type == V_89 ) {
V_66 = (struct V_65 * ) ( & V_53 -> V_15 ) ;
V_10 = F_31 ( & V_70 , V_13 , V_66 ) ;
} else if ( type == V_90 ) {
V_33 = F_26 ( V_13 , V_53 ) ;
V_10 = F_35 ( & V_86 , V_33 ) ;
}
} while ( ! V_10 && ! V_74 );
while ( ! V_10 ) {
++ V_7 -> V_17 [ 0 ] ;
if ( V_7 -> V_17 [ 0 ] > F_3 ( V_13 ) ) {
V_10 = F_4 ( V_32 -> V_39 , V_7 ) ;
if ( V_10 ) {
if ( V_10 == 1 )
V_10 = 0 ;
break;
}
V_13 = V_7 -> V_16 [ 0 ] ;
}
F_5 ( V_13 , & V_11 , V_7 -> V_17 [ 0 ] ) ;
if ( V_11 . V_14 != V_85 )
break;
if ( V_11 . type == V_89 ) {
V_66 = F_14 ( V_13 , V_7 -> V_17 [ 0 ] ,
struct V_65 ) ;
V_10 = F_31 ( & V_70 , V_13 , V_66 ) ;
} else if ( V_11 . type == V_90 ) {
V_10 = F_35 ( & V_86 , V_11 . V_15 ) ;
}
}
F_13 ( V_7 ) ;
while ( ! F_37 ( & V_70 ) ) {
V_87 = F_39 ( & V_70 , struct V_60 , V_64 ) ;
F_40 ( & V_87 -> V_64 ) ;
if ( ! V_10 )
V_10 = V_71 ( V_87 -> V_1 , V_69 +
V_87 -> V_58 ,
V_87 -> V_59 , V_72 ) ;
F_41 ( V_87 ) ;
}
while ( ! F_37 ( & V_86 ) ) {
V_88 = F_39 ( & V_86 , struct V_68 ,
V_64 ) ;
F_40 ( & V_88 -> V_64 ) ;
if ( ! V_10 )
V_10 = F_42 ( V_32 ,
V_88 -> V_67 ,
V_85 ,
V_69 , V_7 ,
& V_70 ,
V_71 , V_72 ) ;
F_41 ( V_88 ) ;
}
return V_10 ;
}
int F_47 ( T_1 V_33 , struct V_31 * V_32 ,
struct V_6 * V_7 ,
T_5 * V_71 , void * V_72 )
{
int V_10 ;
T_1 V_15 ;
struct V_8 V_9 ;
V_10 = F_16 ( V_32 , V_33 , V_7 ,
& V_9 ) ;
if ( V_10 & V_41 )
V_10 = - V_91 ;
if ( V_10 < 0 )
return V_10 ;
V_15 = V_33 - V_9 . V_14 ;
V_10 = F_45 ( V_32 , V_7 , V_9 . V_14 ,
V_15 , V_71 , V_72 ) ;
return V_10 ;
}
static int F_48 ( T_1 V_1 , struct V_4 * V_5 ,
struct V_6 * V_7 ,
T_6 * V_71 , void * V_72 )
{
int V_10 ;
int V_27 ;
T_3 V_92 ;
T_3 V_26 ;
T_3 V_93 ;
T_1 V_23 = 0 ;
int V_81 = 0 ;
struct V_12 * V_13 ;
struct V_94 * V_95 ;
struct V_20 * V_21 ;
struct V_8 V_9 ;
while ( 1 ) {
V_10 = F_7 ( V_1 , V_23 ? V_23 + 1 : 0 , V_5 , V_7 ,
& V_9 ) ;
if ( V_10 < 0 )
break;
if ( V_10 ) {
V_10 = V_81 ? 0 : - V_40 ;
break;
}
++ V_81 ;
V_23 = V_9 . V_15 ;
V_27 = V_7 -> V_17 [ 0 ] ;
V_13 = V_7 -> V_16 [ 0 ] ;
F_12 ( & V_13 -> V_30 ) ;
F_13 ( V_7 ) ;
V_95 = F_49 ( V_13 , V_27 ) ;
V_21 = F_14 ( V_13 , V_27 , struct V_20 ) ;
for ( V_92 = 0 ; V_92 < F_50 ( V_13 , V_95 ) ; V_92 += V_26 ) {
V_93 = F_9 ( V_13 , V_21 ) ;
V_10 = V_71 ( V_23 , V_21 , V_13 , V_72 ) ;
if ( V_10 ) {
F_11 ( V_13 ) ;
break;
}
V_26 = sizeof( * V_21 ) + V_93 ;
V_21 = (struct V_20 * ) ( ( char * ) V_21 + V_26 ) ;
}
F_11 ( V_13 ) ;
}
F_13 ( V_7 ) ;
return V_10 ;
}
static int F_51 ( T_1 V_1 , struct V_20 * V_21 ,
struct V_12 * V_13 , void * V_72 )
{
struct V_96 * V_97 = V_72 ;
char * V_98 ;
char * V_99 ;
int V_100 = V_97 -> V_98 -> V_101 ;
const int V_102 = sizeof( char * ) ;
T_3 V_29 ;
V_29 = V_97 -> V_98 -> V_29 > V_102 ?
V_97 -> V_98 -> V_29 - V_102 : 0 ;
V_99 = ( char * ) V_97 -> V_98 -> V_103 + ( V_100 + 1 ) * V_102 ;
V_98 = F_8 ( V_97 -> V_5 , V_97 -> V_6 , V_21 , V_13 ,
V_1 , V_99 , V_29 ) ;
if ( F_52 ( V_98 ) )
return F_53 ( V_98 ) ;
if ( V_98 > V_99 ) {
V_97 -> V_98 -> V_103 [ V_100 ] = ( T_1 ) ( unsigned long ) V_98 ;
++ V_97 -> V_98 -> V_101 ;
V_97 -> V_98 -> V_29 = V_98 - V_99 ;
} else {
++ V_97 -> V_98 -> V_104 ;
V_97 -> V_98 -> V_105 += V_99 - V_98 ;
V_97 -> V_98 -> V_29 = 0 ;
}
return 0 ;
}
int F_54 ( T_1 V_1 , struct V_96 * V_97 )
{
return F_48 ( V_1 , V_97 -> V_5 , V_97 -> V_6 ,
F_51 , V_97 ) ;
}
struct V_106 * F_55 ( T_3 V_107 )
{
struct V_106 * V_108 ;
T_7 V_109 ;
V_109 = F_56 ( T_7 , V_107 , sizeof( * V_108 ) ) ;
V_108 = F_29 ( V_109 , V_62 ) ;
if ( ! V_108 )
return F_15 ( - V_63 ) ;
if ( V_107 >= sizeof( * V_108 ) ) {
V_108 -> V_29 = V_107 - sizeof( * V_108 ) ;
V_108 -> V_105 = 0 ;
} else {
V_108 -> V_105 = sizeof( * V_108 ) - V_107 ;
V_108 -> V_29 = 0 ;
}
V_108 -> V_101 = 0 ;
V_108 -> V_104 = 0 ;
return V_108 ;
}
struct V_96 * F_57 ( T_8 V_107 , struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_96 * V_110 ;
struct V_106 * V_98 ;
V_98 = F_55 ( V_107 ) ;
if ( F_52 ( V_98 ) )
return ( void * ) V_98 ;
V_110 = F_29 ( sizeof( * V_110 ) , V_62 ) ;
if ( ! V_110 ) {
F_41 ( V_98 ) ;
return F_15 ( - V_63 ) ;
}
V_110 -> V_6 = V_7 ;
V_110 -> V_98 = V_98 ;
V_110 -> V_5 = V_5 ;
return V_110 ;
}
void F_58 ( struct V_96 * V_97 )
{
F_41 ( V_97 ) ;
}
