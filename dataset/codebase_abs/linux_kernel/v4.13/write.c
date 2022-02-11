int F_1 ( struct V_1 * V_1 )
{
F_2 ( L_1 ) ;
return F_3 ( V_1 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_2 * V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
F_5 ( & V_3 -> V_7 ) ;
if ( ! F_6 ( & V_6 -> V_8 ) ) {
V_4 = F_7 ( V_6 -> V_8 . V_9 ,
struct V_2 , V_7 ) ;
if ( V_4 -> V_10 == V_11 ) {
F_8 ( L_2 ) ;
V_4 -> V_10 = V_12 ;
F_9 ( & V_4 -> V_13 ) ;
}
}
}
static void F_10 ( struct V_2 * V_3 )
{
F_2 ( L_1 ) ;
F_11 ( V_3 -> V_14 ) ;
F_12 ( V_3 ) ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_2 ( L_3 , V_3 -> V_15 ) ;
F_14 ( & V_6 -> V_16 ) ;
if ( -- V_3 -> V_15 == 0 )
F_4 ( V_3 ) ;
else
V_3 = NULL ;
F_15 ( & V_6 -> V_16 ) ;
if ( V_3 )
F_10 ( V_3 ) ;
}
static int F_16 ( struct V_5 * V_6 , struct V_14 * V_14 ,
T_1 V_17 , unsigned int V_18 , struct V_1 * V_1 )
{
struct V_19 * V_20 ;
int V_21 ;
F_2 ( L_4 , ( unsigned long long ) V_17 ) ;
V_20 = F_17 ( sizeof( struct V_19 ) + sizeof( struct V_1 * ) ,
V_22 ) ;
if ( ! V_20 )
return - V_23 ;
F_18 ( & V_20 -> V_15 , 1 ) ;
V_20 -> V_17 = V_17 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_24 = 1 ;
V_20 -> V_25 [ 0 ] = V_1 ;
F_19 ( V_1 ) ;
V_21 = F_20 ( V_6 , V_14 , V_20 ) ;
F_21 ( V_20 ) ;
if ( V_21 < 0 ) {
if ( V_21 == - V_26 ) {
F_8 ( L_5
L_6 ) ;
F_22 ( V_27 , & V_6 -> V_28 ) ;
V_21 = - V_29 ;
}
}
F_23 ( L_7 , V_21 ) ;
return V_21 ;
}
int F_24 ( struct V_30 * V_30 , struct V_31 * V_32 ,
T_1 V_17 , unsigned V_18 , unsigned V_28 ,
struct V_1 * * V_33 , void * * V_34 )
{
struct V_2 * V_35 , * V_3 ;
struct V_5 * V_6 = F_25 ( F_26 ( V_30 ) ) ;
struct V_1 * V_1 ;
struct V_14 * V_14 = V_30 -> V_36 ;
unsigned V_37 = V_17 & ( V_38 - 1 ) ;
unsigned V_39 = V_37 + V_18 ;
T_2 V_40 = V_17 >> V_41 ;
int V_21 ;
F_2 ( L_8 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_6 , V_40 , V_37 , V_39 ) ;
V_35 = F_17 ( sizeof( * V_35 ) , V_22 ) ;
if ( ! V_35 )
return - V_23 ;
V_35 -> V_6 = V_6 ;
V_35 -> V_44 = V_35 -> V_45 = V_40 ;
V_35 -> V_46 = V_37 ;
V_35 -> V_47 = V_39 ;
F_27 ( & V_35 -> V_7 ) ;
V_35 -> V_15 = 1 ;
V_35 -> V_10 = V_48 ;
F_28 ( & V_35 -> V_13 ) ;
V_1 = F_29 ( V_32 , V_40 , V_28 ) ;
if ( ! V_1 ) {
F_12 ( V_35 ) ;
return - V_23 ;
}
if ( ! F_30 ( V_1 ) && V_18 != V_38 ) {
V_21 = F_16 ( V_6 , V_14 , V_17 & V_49 , V_38 , V_1 ) ;
if ( V_21 < 0 ) {
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
F_12 ( V_35 ) ;
F_23 ( L_9 , V_21 ) ;
return V_21 ;
}
F_33 ( V_1 ) ;
}
* V_33 = V_1 ;
V_50:
F_14 ( & V_6 -> V_16 ) ;
V_3 = (struct V_2 * ) F_34 ( V_1 ) ;
if ( V_3 ) {
if ( V_3 -> V_14 == V_14 && V_3 -> V_10 == V_48 )
goto V_51;
goto V_52;
}
if ( V_40 > 0 ) {
F_35 (wb, &vnode->writebacks, link) {
if ( V_3 -> V_45 == V_40 - 1 && V_3 -> V_14 == V_14 &&
V_3 -> V_10 == V_48 )
goto V_53;
}
}
F_36 ( & V_35 -> V_7 , & V_6 -> V_8 ) ;
V_35 -> V_14 = F_37 ( V_14 ) ;
F_15 ( & V_6 -> V_16 ) ;
F_38 ( V_1 ) ;
F_39 ( V_1 , ( unsigned long ) V_35 ) ;
F_23 ( L_10 ) ;
return 0 ;
V_51:
F_8 ( L_11 ) ;
F_40 ( V_3 -> V_44 , <= , V_40 , <= , V_3 -> V_45 ) ;
if ( V_40 == V_3 -> V_44 && V_37 < V_3 -> V_46 )
V_3 -> V_46 = V_37 ;
if ( V_40 == V_3 -> V_45 && V_39 > V_3 -> V_47 )
V_3 -> V_47 = V_39 ;
F_15 ( & V_6 -> V_16 ) ;
F_12 ( V_35 ) ;
F_23 ( L_12 ) ;
return 0 ;
V_53:
F_8 ( L_13 , V_3 -> V_44 , V_3 -> V_45 ) ;
V_3 -> V_15 ++ ;
V_3 -> V_45 ++ ;
V_3 -> V_47 = V_39 ;
F_15 ( & V_6 -> V_16 ) ;
F_38 ( V_1 ) ;
F_39 ( V_1 , ( unsigned long ) V_3 ) ;
F_12 ( V_35 ) ;
F_23 ( L_14 ) ;
return 0 ;
V_52:
F_8 ( L_15 ) ;
if ( V_3 -> V_10 == V_48 )
V_3 -> V_10 = V_54 ;
F_15 ( & V_6 -> V_16 ) ;
if ( F_41 ( V_1 ) ) {
V_21 = F_42 ( V_3 , V_1 ) ;
if ( V_21 < 0 ) {
F_13 ( V_35 ) ;
F_23 ( L_7 , V_21 ) ;
return V_21 ;
}
}
F_13 ( V_3 ) ;
F_39 ( V_1 , 0 ) ;
F_43 ( V_1 ) ;
goto V_50;
}
int F_44 ( struct V_30 * V_30 , struct V_31 * V_32 ,
T_1 V_17 , unsigned V_18 , unsigned V_55 ,
struct V_1 * V_1 , void * V_34 )
{
struct V_5 * V_6 = F_25 ( F_26 ( V_30 ) ) ;
struct V_14 * V_14 = V_30 -> V_36 ;
T_1 V_56 , V_57 ;
int V_21 ;
F_2 ( L_16 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_6 , V_1 -> V_40 ) ;
V_57 = V_17 + V_55 ;
V_56 = F_45 ( & V_6 -> V_58 ) ;
if ( V_57 > V_56 ) {
F_14 ( & V_6 -> V_16 ) ;
V_56 = F_45 ( & V_6 -> V_58 ) ;
if ( V_57 > V_56 )
F_46 ( & V_6 -> V_58 , V_57 ) ;
F_15 ( & V_6 -> V_16 ) ;
}
if ( ! F_30 ( V_1 ) ) {
if ( V_55 < V_18 ) {
V_21 = F_16 ( V_6 , V_14 , V_17 + V_55 ,
V_18 - V_55 , V_1 ) ;
if ( V_21 < 0 )
return V_21 ;
}
F_33 ( V_1 ) ;
}
F_47 ( V_1 ) ;
if ( F_48 ( V_1 ) )
F_8 ( L_17 ) ;
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
return V_55 ;
}
static void F_49 ( struct V_5 * V_6 , bool error ,
T_2 V_44 , T_2 V_45 )
{
struct V_59 V_60 ;
unsigned V_61 , V_62 ;
F_2 ( L_18 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_6 , V_44 , V_45 ) ;
F_50 ( & V_60 , 0 ) ;
do {
F_8 ( L_19 , V_44 , V_45 ) ;
V_61 = V_45 - V_44 + 1 ;
if ( V_61 > V_63 )
V_61 = V_63 ;
V_60 . V_64 = F_51 ( V_6 -> V_58 . V_65 ,
V_44 , V_61 , V_60 . V_25 ) ;
F_52 ( V_60 . V_64 , == , V_61 ) ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
struct V_1 * V_1 = V_60 . V_25 [ V_62 ] ;
F_53 ( V_1 ) ;
if ( error )
F_54 ( V_1 ) ;
if ( F_55 ( V_1 ) )
F_56 ( V_1 ) ;
if ( V_1 -> V_40 >= V_44 )
V_44 = V_1 -> V_40 + 1 ;
}
F_57 ( & V_60 ) ;
} while ( V_44 < V_45 );
F_23 ( L_1 ) ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_1 * V_66 )
{
struct V_1 * V_25 [ 8 ] , * V_1 ;
unsigned long V_61 ;
unsigned V_67 , V_68 , V_39 ;
T_2 V_69 , V_44 , V_45 ;
int V_62 , V_21 ;
F_2 ( L_20 , V_66 -> V_40 ) ;
V_61 = 1 ;
if ( F_58 ( V_66 ) )
F_59 () ;
V_69 = V_66 -> V_40 ;
if ( V_69 >= V_3 -> V_45 )
goto V_70;
V_69 ++ ;
do {
F_8 ( L_21 , V_69 , V_61 ) ;
V_67 = V_3 -> V_45 - V_69 + 1 ;
if ( V_67 > F_60 ( V_25 ) )
V_67 = F_60 ( V_25 ) ;
V_67 = F_51 ( V_3 -> V_6 -> V_58 . V_65 ,
V_69 , V_67 , V_25 ) ;
F_8 ( L_22 , V_67 ) ;
if ( V_67 == 0 )
goto V_70;
if ( V_25 [ 0 ] -> V_40 != V_69 ) {
do {
F_32 ( V_25 [ -- V_67 ] ) ;
} while ( V_67 > 0 );
goto V_70;
}
for ( V_62 = 0 ; V_62 < V_67 ; V_62 ++ ) {
V_1 = V_25 [ V_62 ] ;
if ( V_1 -> V_40 > V_3 -> V_45 )
break;
if ( ! F_61 ( V_1 ) )
break;
if ( ! F_48 ( V_1 ) ||
F_34 ( V_1 ) != ( unsigned long ) V_3 ) {
F_31 ( V_1 ) ;
break;
}
if ( ! F_41 ( V_1 ) )
F_59 () ;
if ( F_58 ( V_1 ) )
F_59 () ;
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
}
V_61 += V_62 ;
if ( V_62 < V_67 ) {
for (; V_62 < V_67 ; V_62 ++ )
F_32 ( V_25 [ V_62 ] ) ;
goto V_70;
}
V_69 += V_62 ;
} while ( V_69 <= V_3 -> V_45 && V_61 < 65536 );
V_70:
V_44 = V_66 -> V_40 ;
V_45 = V_44 + V_61 - 1 ;
V_68 = ( V_44 == V_3 -> V_44 ) ? V_3 -> V_46 : 0 ;
V_39 = ( V_45 == V_3 -> V_45 ) ? V_3 -> V_47 : V_38 ;
F_8 ( L_23 , V_44 , V_68 , V_45 , V_39 ) ;
V_21 = F_62 ( V_3 , V_44 , V_45 , V_68 , V_39 ) ;
if ( V_21 < 0 ) {
switch ( V_21 ) {
case - V_71 :
case - V_72 :
F_63 ( V_3 -> V_6 -> V_58 . V_65 , - V_72 ) ;
break;
case - V_73 :
case - V_74 :
case - V_75 :
case - V_76 :
case - V_26 :
case - V_77 :
case - V_78 :
F_49 ( V_3 -> V_6 , true , V_44 , V_45 ) ;
F_63 ( V_3 -> V_6 -> V_58 . V_65 , - V_74 ) ;
break;
case - V_79 :
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
F_49 ( V_3 -> V_6 , false , V_44 , V_45 ) ;
break;
default:
break;
}
} else {
V_21 = V_61 ;
}
F_23 ( L_7 , V_21 ) ;
return V_21 ;
}
int F_64 ( struct V_1 * V_1 , struct V_85 * V_86 )
{
struct V_2 * V_3 ;
int V_21 ;
F_2 ( L_24 , V_1 -> V_40 ) ;
V_3 = (struct V_2 * ) F_34 ( V_1 ) ;
ASSERT ( V_3 != NULL ) ;
V_21 = F_42 ( V_3 , V_1 ) ;
F_31 ( V_1 ) ;
if ( V_21 < 0 ) {
F_23 ( L_7 , V_21 ) ;
return 0 ;
}
V_86 -> V_87 -= V_21 ;
F_23 ( L_25 ) ;
return 0 ;
}
static int F_65 ( struct V_31 * V_32 ,
struct V_85 * V_86 ,
T_2 V_40 , T_2 V_88 , T_2 * V_89 )
{
struct V_2 * V_3 ;
struct V_1 * V_1 ;
int V_21 , V_67 ;
F_2 ( L_26 , V_40 , V_88 ) ;
do {
V_67 = F_66 ( V_32 , & V_40 , V_90 ,
1 , & V_1 ) ;
if ( ! V_67 )
break;
F_8 ( L_27 , V_1 -> V_40 ) ;
if ( V_1 -> V_40 > V_88 ) {
* V_89 = V_40 ;
F_32 ( V_1 ) ;
F_23 ( L_28 , * V_89 ) ;
return 0 ;
}
F_67 ( V_1 ) ;
if ( V_1 -> V_32 != V_32 || ! F_48 ( V_1 ) ) {
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
continue;
}
if ( F_55 ( V_1 ) ) {
F_31 ( V_1 ) ;
if ( V_86 -> V_91 != V_92 )
F_68 ( V_1 ) ;
F_32 ( V_1 ) ;
continue;
}
V_3 = (struct V_2 * ) F_34 ( V_1 ) ;
ASSERT ( V_3 != NULL ) ;
F_14 ( & V_3 -> V_6 -> V_16 ) ;
V_3 -> V_10 = V_93 ;
F_15 ( & V_3 -> V_6 -> V_16 ) ;
if ( ! F_41 ( V_1 ) )
F_59 () ;
V_21 = F_42 ( V_3 , V_1 ) ;
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
if ( V_21 < 0 ) {
F_23 ( L_7 , V_21 ) ;
return V_21 ;
}
V_86 -> V_87 -= V_21 ;
F_69 () ;
} while ( V_40 < V_88 && V_86 -> V_87 > 0 );
* V_89 = V_40 ;
F_23 ( L_28 , * V_89 ) ;
return 0 ;
}
int F_70 ( struct V_31 * V_32 ,
struct V_85 * V_86 )
{
T_2 V_69 , V_88 , V_9 ;
int V_21 ;
F_2 ( L_1 ) ;
if ( V_86 -> V_94 ) {
V_69 = V_32 -> V_95 ;
V_88 = - 1 ;
V_21 = F_65 ( V_32 , V_86 , V_69 , V_88 , & V_9 ) ;
if ( V_69 > 0 && V_86 -> V_87 > 0 && V_21 == 0 )
V_21 = F_65 ( V_32 , V_86 , 0 , V_69 ,
& V_9 ) ;
V_32 -> V_95 = V_9 ;
} else if ( V_86 -> V_96 == 0 && V_86 -> V_97 == V_98 ) {
V_88 = ( T_2 ) ( V_98 >> V_41 ) ;
V_21 = F_65 ( V_32 , V_86 , 0 , V_88 , & V_9 ) ;
if ( V_86 -> V_87 > 0 )
V_32 -> V_95 = V_9 ;
} else {
V_69 = V_86 -> V_96 >> V_41 ;
V_88 = V_86 -> V_97 >> V_41 ;
V_21 = F_65 ( V_32 , V_86 , V_69 , V_88 , & V_9 ) ;
}
F_23 ( L_7 , V_21 ) ;
return V_21 ;
}
void F_71 ( struct V_5 * V_6 , struct V_99 * V_100 )
{
struct V_2 * V_3 = V_100 -> V_3 ;
struct V_59 V_60 ;
unsigned V_61 , V_62 ;
T_2 V_44 = V_100 -> V_44 , V_45 = V_100 -> V_45 ;
bool V_101 ;
F_2 ( L_29 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_6 , V_44 , V_45 ) ;
ASSERT ( V_3 != NULL ) ;
F_50 ( & V_60 , 0 ) ;
do {
F_8 ( L_30 , V_44 , V_45 ) ;
V_61 = V_45 - V_44 + 1 ;
if ( V_61 > V_63 )
V_61 = V_63 ;
V_60 . V_64 = F_51 ( V_100 -> V_32 , V_44 , V_61 ,
V_60 . V_25 ) ;
F_52 ( V_60 . V_64 , == , V_61 ) ;
F_14 ( & V_6 -> V_16 ) ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
struct V_1 * V_1 = V_60 . V_25 [ V_62 ] ;
F_56 ( V_1 ) ;
if ( F_34 ( V_1 ) == ( unsigned long ) V_3 ) {
F_39 ( V_1 , 0 ) ;
F_43 ( V_1 ) ;
V_3 -> V_15 -- ;
}
}
V_101 = false ;
if ( V_3 -> V_15 == 0 ) {
F_4 ( V_3 ) ;
V_101 = true ;
}
F_15 ( & V_6 -> V_16 ) ;
V_44 += V_61 ;
if ( V_101 ) {
F_10 ( V_3 ) ;
V_3 = NULL ;
}
F_57 ( & V_60 ) ;
} while ( V_44 <= V_45 );
F_23 ( L_1 ) ;
}
T_3 F_72 ( struct V_102 * V_103 , struct V_104 * V_37 )
{
struct V_5 * V_6 = F_25 ( F_26 ( V_103 -> V_105 ) ) ;
T_3 V_106 ;
T_4 V_61 = F_73 ( V_37 ) ;
F_2 ( L_31 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_6 , V_61 ) ;
if ( F_74 ( & V_6 -> V_58 ) ) {
F_75 ( V_107
L_32 ) ;
return - V_108 ;
}
if ( ! V_61 )
return 0 ;
V_106 = F_76 ( V_103 , V_37 ) ;
F_23 ( L_33 , V_106 ) ;
return V_106 ;
}
int F_77 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = V_6 -> V_58 . V_65 ;
struct V_85 V_86 = {
. V_91 = V_109 ,
. V_87 = V_110 ,
. V_94 = 1 ,
} ;
int V_21 ;
F_2 ( L_1 ) ;
V_21 = V_32 -> V_111 -> V_112 ( V_32 , & V_86 ) ;
F_78 ( V_32 -> V_113 , V_114 ) ;
F_23 ( L_7 , V_21 ) ;
return V_21 ;
}
int F_79 ( struct V_30 * V_30 , T_1 V_69 , T_1 V_88 , int V_115 )
{
struct V_116 * V_116 = F_26 ( V_30 ) ;
struct V_2 * V_3 , * V_117 ;
struct V_5 * V_6 = F_25 ( V_116 ) ;
int V_21 ;
F_2 ( L_34 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_6 , V_30 ,
V_115 ) ;
V_21 = F_80 ( V_116 -> V_65 , V_69 , V_88 ) ;
if ( V_21 )
return V_21 ;
F_81 ( V_116 ) ;
V_3 = F_17 ( sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 ) {
V_21 = - V_23 ;
goto V_118;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_44 = 0 ;
V_3 -> V_45 = - 1 ;
V_3 -> V_46 = 0 ;
V_3 -> V_47 = V_38 ;
V_3 -> V_15 = 1 ;
V_3 -> V_10 = V_11 ;
F_28 ( & V_3 -> V_13 ) ;
F_14 ( & V_6 -> V_16 ) ;
F_35 (xwb, &vnode->writebacks, link) {
if ( V_117 -> V_10 == V_48 )
V_117 -> V_10 = V_54 ;
}
F_36 ( & V_3 -> V_7 , & V_6 -> V_8 ) ;
F_15 ( & V_6 -> V_16 ) ;
V_21 = F_77 ( V_6 ) ;
if ( V_21 < 0 ) {
F_13 ( V_3 ) ;
F_23 ( L_35 , V_21 ) ;
goto V_118;
}
V_21 = F_82 ( V_3 -> V_13 ,
V_3 -> V_10 == V_12 ||
V_6 -> V_8 . V_9 == & V_3 -> V_7 ) ;
F_13 ( V_3 ) ;
F_23 ( L_7 , V_21 ) ;
V_118:
F_83 ( V_116 ) ;
return V_21 ;
}
int F_84 ( struct V_30 * V_30 , T_5 V_119 )
{
F_2 ( L_1 ) ;
if ( ( V_30 -> V_120 & V_121 ) == 0 )
return 0 ;
return F_85 ( V_30 , 0 ) ;
}
int F_86 ( struct V_122 * V_123 , struct V_1 * V_1 )
{
struct V_5 * V_6 = F_25 ( V_123 -> V_124 -> V_125 -> V_113 ) ;
F_2 ( L_36 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_6 , V_1 -> V_40 ) ;
#ifdef F_87
F_88 ( V_6 -> V_126 , V_1 ) ;
#endif
F_23 ( L_25 ) ;
return 0 ;
}
