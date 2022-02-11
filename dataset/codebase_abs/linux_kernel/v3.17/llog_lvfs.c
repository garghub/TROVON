static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 , int V_4 ,
int V_5 )
{
struct V_6 V_7 = { 0 } ;
struct V_8 V_9 ;
int V_10 ;
F_2 ( V_4 >= V_11 && ( V_4 & 0x7 ) == 0 ) ;
V_9 . V_12 = V_7 . V_13 = V_4 ;
V_9 . V_14 = V_7 . V_15 = V_5 ;
V_7 . V_16 = V_17 ;
V_10 = F_3 ( V_2 , V_3 , & V_7 , sizeof( V_7 ) , & V_3 -> V_18 , 0 ) ;
if ( V_10 ) {
F_4 ( L_1 , V_10 ) ;
goto V_19;
}
V_3 -> V_18 += V_4 - sizeof( V_7 ) - sizeof( V_9 ) ;
V_10 = F_3 ( V_2 , V_3 , & V_9 , sizeof( V_9 ) , & V_3 -> V_18 , 0 ) ;
if ( V_10 ) {
F_4 ( L_1 , V_10 ) ;
goto V_19;
}
V_19:
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_6 * V_7 , void * V_20 , T_1 V_21 )
{
int V_10 ;
struct V_8 V_22 ;
T_1 V_23 = V_3 -> V_18 ;
int V_24 = V_7 -> V_13 ;
V_3 -> V_18 = V_21 ;
if ( V_24 == 0 )
F_6 ( L_2 ) ;
if ( ! V_20 ) {
V_10 = F_3 ( V_2 , V_3 , V_7 , V_24 , & V_3 -> V_18 , 0 ) ;
if ( V_10 ) {
F_4 ( L_3 , V_10 ) ;
goto V_19;
}
GOTO ( V_19 , V_10 = 0 ) ;
}
V_7 -> V_13 = sizeof( * V_7 ) + V_24 + sizeof( V_22 ) ;
V_10 = F_3 ( V_2 , V_3 , V_7 , sizeof( * V_7 ) , & V_3 -> V_18 , 0 ) ;
if ( V_10 ) {
F_4 ( L_4 , V_10 ) ;
goto V_19;
}
V_10 = F_3 ( V_2 , V_3 , V_20 , V_24 , & V_3 -> V_18 , 0 ) ;
if ( V_10 ) {
F_4 ( L_5 , V_10 ) ;
goto V_19;
}
V_22 . V_12 = V_7 -> V_13 ;
V_22 . V_14 = V_7 -> V_15 ;
V_10 = F_3 ( V_2 , V_3 , & V_22 , sizeof( V_22 ) , & V_3 -> V_18 , 0 ) ;
if ( V_10 ) {
F_4 ( L_6 , V_10 ) ;
goto V_19;
}
V_10 = 0 ;
V_19:
if ( V_23 > V_3 -> V_18 )
V_3 -> V_18 = V_23 ;
F_2 ( V_10 <= 0 ) ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_3 ,
void * V_20 , int V_25 , T_1 V_21 )
{
T_1 V_26 = V_21 ;
int V_10 ;
V_10 = F_8 ( V_2 , V_3 , V_20 , V_25 , & V_26 ) ;
if ( V_10 ) {
F_4 ( L_7 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_9 ( const struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 ;
int V_10 ;
F_2 ( sizeof( * V_30 -> V_31 ) == V_32 ) ;
V_2 = V_30 -> V_33 -> V_34 -> V_35 ;
if ( F_10 ( V_30 -> V_36 -> V_37 -> V_38 ) == 0 ) {
F_11 ( V_39 , L_8 ) ;
return V_40 ;
}
V_10 = F_7 ( V_2 , V_30 -> V_36 , V_30 -> V_31 ,
V_32 , 0 ) ;
if ( V_10 ) {
F_4 ( L_9 ,
V_30 -> V_36 -> V_37 -> V_41 . V_4 ,
V_30 -> V_36 -> V_37 -> V_41 . V_42 ) ;
} else {
struct V_6 * V_43 = & V_30 -> V_31 -> V_43 ;
if ( F_12 ( V_43 ) )
F_13 ( V_30 -> V_31 ) ;
if ( V_43 -> V_16 != V_44 ) {
F_4 ( L_10 ,
V_30 -> V_36 -> V_37 -> V_41 . V_4 ,
V_30 -> V_36 -> V_37 -> V_41 . V_42 ,
V_43 -> V_16 , V_44 ) ;
V_10 = - V_45 ;
} else if ( V_43 -> V_13 != V_32 ) {
F_4 ( L_11
L_12 ,
V_30 -> V_36 -> V_37 -> V_41 . V_4 ,
V_30 -> V_36 -> V_37 -> V_41 . V_42 ,
V_43 -> V_13 , V_32 ) ;
F_4 ( L_13 ) ;
V_10 = - V_45 ;
}
}
V_30 -> V_46 = V_30 -> V_31 -> V_47 . V_14 ;
V_30 -> V_36 -> V_18 = F_10 ( V_30 -> V_36 -> V_37 -> V_38 ) ;
return V_10 ;
}
static int F_14 ( const struct V_27 * V_28 ,
struct V_29 * V_48 ,
struct V_6 * V_7 ,
struct V_49 * V_50 , int V_51 ,
void * V_20 , int V_52 , struct V_53 * V_54 )
{
struct V_55 * V_56 ;
int V_57 = V_7 -> V_13 , V_5 , V_10 ;
struct V_8 * V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
T_2 V_59 ;
V_56 = V_48 -> V_31 ;
V_3 = V_48 -> V_36 ;
V_2 = V_48 -> V_33 -> V_34 -> V_35 ;
if ( V_20 )
V_10 = ( V_57 > V_32 - sizeof( struct V_6 ) -
sizeof( struct V_8 ) ) ? - V_60 : 0 ;
else
V_10 = ( V_57 > V_32 ) ? - V_60 : 0 ;
if ( V_10 )
return V_10 ;
if ( V_20 )
V_57 = sizeof( * V_7 ) + V_7 -> V_13 +
sizeof( struct V_8 ) ;
if ( V_52 != - 1 ) {
T_1 V_61 ;
if ( V_52 != 1 && ! F_10 ( V_3 -> V_37 -> V_38 ) ) {
F_4 ( L_14 ) ;
F_15 () ;
}
if ( V_52 && V_56 -> V_62 && V_56 -> V_62 != V_7 -> V_13 )
return - V_63 ;
if ( ! F_16 ( V_52 , V_56 -> V_64 ) )
F_4 ( L_15 , V_52 ) ;
if ( V_52 != V_7 -> V_15 )
F_4 ( L_16 , V_52 , V_7 -> V_15 ) ;
V_10 = F_5 ( V_2 , V_3 , & V_56 -> V_43 , NULL , 0 ) ;
if ( V_10 || V_52 == 0 )
return V_10 ;
if ( V_20 ) {
V_61 = V_48 -> V_65 ;
F_11 ( V_66 ,
L_17 V_67 L_18
L_19 ,
F_17 ( & V_48 -> V_68 . V_69 ) , V_52 , V_7 -> V_15 ,
V_48 -> V_70 , V_7 -> V_13 ,
( long long ) ( V_61 - sizeof( * V_56 ) ) ) ;
if ( V_7 -> V_15 != V_48 -> V_70 ) {
F_4 ( L_20 ,
V_52 , V_48 -> V_70 ) ;
return - V_71 ;
}
} else {
V_61 = sizeof( * V_56 ) + ( V_52 - 1 ) * V_57 ;
}
V_10 = F_5 ( V_2 , V_3 , V_7 , V_20 , V_61 ) ;
if ( V_10 == 0 && V_50 ) {
V_50 -> V_72 = V_48 -> V_68 ;
V_50 -> V_73 = V_52 ;
V_10 = 1 ;
}
return V_10 ;
}
V_59 = V_32 - ( V_3 -> V_18 & ( V_32 - 1 ) ) ;
if ( V_59 != 0 && V_59 != V_57 &&
V_59 < ( V_57 + V_11 ) ) {
V_5 = V_48 -> V_46 + 1 ;
V_10 = F_1 ( V_2 , V_3 , V_59 , V_5 ) ;
if ( V_10 )
return V_10 ;
V_48 -> V_46 ++ ;
}
if ( V_48 -> V_46 >= F_18 ( V_56 ) - 1 )
return - V_74 ;
V_48 -> V_46 ++ ;
V_5 = V_48 -> V_46 ;
F_2 ( V_5 < F_18 ( V_56 ) ) ;
V_7 -> V_15 = V_5 ;
if ( V_20 == NULL ) {
V_58 = (struct V_8 * )
( ( char * ) V_7 + V_7 -> V_13 - sizeof( * V_58 ) ) ;
V_58 -> V_12 = V_7 -> V_13 ;
V_58 -> V_14 = V_7 -> V_15 ;
}
F_2 ( V_5 < F_18 ( V_56 ) ) ;
F_19 ( & V_48 -> V_75 ) ;
if ( F_20 ( V_5 , V_56 -> V_64 ) ) {
F_4 ( L_21 , V_5 ) ;
F_21 ( & V_48 -> V_75 ) ;
F_15 () ;
}
V_56 -> V_76 ++ ;
F_21 ( & V_48 -> V_75 ) ;
V_56 -> V_47 . V_14 = V_5 ;
V_10 = F_5 ( V_2 , V_3 , & V_56 -> V_43 , NULL , 0 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_5 ( V_2 , V_3 , V_7 , V_20 , V_3 -> V_18 ) ;
if ( V_10 )
return V_10 ;
F_11 ( V_77 , L_22 V_67 L_23 ,
F_17 ( & V_48 -> V_68 . V_69 ) , V_5 , V_7 -> V_13 ) ;
if ( V_10 == 0 && V_50 ) {
V_50 -> V_72 = V_48 -> V_68 ;
V_50 -> V_73 = V_5 ;
if ( ( V_7 -> V_16 == V_78 ) ||
( V_7 -> V_16 == V_79 ) )
V_50 -> V_80 = V_81 ;
else if ( V_7 -> V_16 == V_82 )
V_50 -> V_80 = V_83 ;
else
V_50 -> V_80 = - 1 ;
V_10 = 1 ;
}
if ( V_10 == 0 && V_7 -> V_16 == V_84 )
V_10 = 1 ;
return V_10 ;
}
static void F_22 ( T_3 * V_21 , int V_85 , int V_86 )
{
if ( V_86 <= V_85 )
return;
* V_21 = ( * V_21 + ( V_86 - V_85 - 1 ) * V_11 ) &
~ ( V_32 - 1 ) ;
}
static int F_23 ( const struct V_27 * V_28 ,
struct V_29 * V_48 , int * V_87 ,
int V_88 , T_3 * V_89 , void * V_20 ,
int V_4 )
{
int V_10 ;
if ( V_4 == 0 || V_4 & ( V_32 - 1 ) )
return - V_63 ;
F_11 ( V_66 , L_24 ,
V_88 , * V_87 , * V_89 ) ;
while ( * V_89 < F_10 ( V_48 -> V_36 -> V_37 -> V_38 ) ) {
struct V_6 * V_7 , * V_90 ;
struct V_8 * V_9 ;
T_1 V_91 ;
int V_92 ;
F_22 ( V_89 , * V_87 , V_88 ) ;
V_91 = * V_89 ;
V_92 = V_32 - ( * V_89 & ( V_32 - 1 ) ) ;
V_10 = F_8 ( V_48 -> V_33 -> V_34 -> V_35 ,
V_48 -> V_36 , V_20 , V_92 ,
V_89 ) ;
if ( V_10 < 0 ) {
F_4 ( L_25 V_67
L_26 ,
F_17 ( & V_48 -> V_68 . V_69 ) ,
V_48 -> V_68 . V_93 ,
* V_89 ) ;
return V_10 ;
}
V_10 = * V_89 - V_91 ;
if ( V_10 < V_4 ) {
memset ( V_20 + V_10 , 0 , V_4 - V_10 ) ;
}
if ( V_10 == 0 )
return 0 ;
if ( V_10 < sizeof( * V_9 ) ) {
F_4 ( L_27 V_67 L_28 ,
F_17 ( & V_48 -> V_68 . V_69 ) ,
V_48 -> V_68 . V_93 , * V_89 ) ;
return - V_63 ;
}
V_7 = V_20 ;
if ( F_12 ( V_7 ) )
F_24 ( V_7 ) ;
V_9 = (struct V_8 * ) ( V_20 + V_10 -
sizeof( struct V_8 ) ) ;
V_90 = (struct V_6 * ) ( V_20 + V_10 -
F_25 ( V_9 -> V_12 ) ) ;
if ( F_12 ( V_90 ) )
F_24 ( V_90 ) ;
F_2 ( V_90 -> V_15 == V_9 -> V_14 ) ;
* V_87 = V_9 -> V_14 ;
if ( V_9 -> V_14 == 0 ) {
F_4 ( L_29 V_67 L_26 ,
F_17 ( & V_48 -> V_68 . V_69 ) ,
V_48 -> V_68 . V_93 , * V_89 ) ;
return - V_63 ;
}
if ( V_9 -> V_14 < V_88 )
continue;
if ( V_7 -> V_15 > V_88 ) {
F_4 ( L_30 ,
V_7 -> V_15 , V_88 ) ;
return - V_94 ;
}
return 0 ;
}
return - V_45 ;
}
static int F_26 ( const struct V_27 * V_28 ,
struct V_29 * V_48 ,
int V_95 , void * V_20 , int V_4 )
{
T_3 V_89 ;
int V_10 ;
if ( V_4 == 0 || V_4 & ( V_32 - 1 ) )
return - V_63 ;
F_11 ( V_66 , L_31 , V_95 ) ;
V_89 = V_32 ;
F_22 ( & V_89 , 0 , V_95 ) ;
while ( V_89 < F_10 ( V_48 -> V_36 -> V_37 -> V_38 ) ) {
struct V_6 * V_7 , * V_90 ;
struct V_8 * V_9 ;
T_1 V_91 = V_89 ;
V_10 = F_8 ( V_48 -> V_33 -> V_34 -> V_35 ,
V_48 -> V_36 , V_20 , V_4 ,
& V_89 ) ;
if ( V_10 < 0 ) {
F_4 ( L_25 V_67
L_26 ,
F_17 ( & V_48 -> V_68 . V_69 ) ,
V_48 -> V_68 . V_93 ,
V_89 ) ;
return V_10 ;
}
V_10 = V_89 - V_91 ;
if ( V_10 == 0 )
return 0 ;
if ( V_10 < sizeof( * V_9 ) ) {
F_4 ( L_27 V_67 L_28 ,
F_17 ( & V_48 -> V_68 . V_69 ) ,
V_48 -> V_68 . V_93 , V_89 ) ;
return - V_63 ;
}
V_7 = V_20 ;
if ( F_12 ( V_7 ) )
F_24 ( V_7 ) ;
V_9 = (struct V_8 * ) ( V_20 + V_10 -
sizeof( struct V_8 ) ) ;
V_90 = (struct V_6 * ) ( V_20 + V_10 -
F_25 ( V_9 -> V_12 ) ) ;
if ( F_12 ( V_90 ) )
F_24 ( V_90 ) ;
F_2 ( V_90 -> V_15 == V_9 -> V_14 ) ;
if ( V_9 -> V_14 == 0 ) {
F_4 ( L_29 V_67 L_28 ,
F_17 ( & V_48 -> V_68 . V_69 ) ,
V_48 -> V_68 . V_93 , V_89 ) ;
return - V_63 ;
}
if ( V_9 -> V_14 < V_95 )
continue;
if ( V_7 -> V_15 > V_95 ) {
F_4 ( L_30 ,
V_7 -> V_15 , V_95 ) ;
return - V_94 ;
}
return 0 ;
}
return - V_45 ;
}
static struct V_3 * F_27 ( char * V_96 , char * V_42 , int V_97 , int V_98 )
{
char * V_99 ;
struct V_3 * V_100 ;
int V_4 ;
F_28 ( V_99 , V_101 ) ;
if ( V_99 == NULL )
return F_29 ( - V_102 ) ;
V_4 = snprintf ( V_99 , V_101 , L_32 , V_96 , V_42 ) ;
if ( V_4 >= V_101 - 1 ) {
V_100 = F_29 ( - V_103 ) ;
} else {
V_100 = F_30 ( V_99 , V_97 , V_98 ) ;
if ( F_31 ( V_100 ) && F_32 ( V_100 ) != - V_94 )
F_4 ( L_33 , V_99 ,
F_32 ( V_100 ) ) ;
}
F_33 ( V_99 , V_101 ) ;
return V_100 ;
}
static int F_34 ( const struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_104 * V_105 , char * V_42 ,
enum V_106 V_107 )
{
struct V_108 * V_109 = V_30 -> V_33 ;
struct V_110 * V_111 = NULL ;
struct V_1 * V_2 ;
int V_10 = 0 ;
F_2 ( V_109 ) ;
F_2 ( V_109 -> V_34 ) ;
F_2 ( V_109 -> V_34 -> V_35 ) ;
V_2 = V_109 -> V_34 -> V_35 ;
F_2 ( V_30 ) ;
if ( V_105 != NULL ) {
V_111 = F_35 ( V_109 -> V_34 , & V_105 -> V_69 ,
V_105 -> V_93 ) ;
if ( F_31 ( V_111 ) ) {
V_10 = F_32 ( V_111 ) ;
F_4 ( L_34 V_67 L_35
L_36 , V_109 -> V_112 -> V_113 ,
F_17 ( & V_105 -> V_69 ) , V_105 -> V_93 , V_10 ) ;
GOTO ( V_19 , V_10 ) ;
}
if ( V_111 -> V_38 == NULL ) {
F_36 ( V_111 ) ;
V_10 = - V_94 ;
F_4 ( L_37 V_67 L_35
L_38 , V_109 -> V_112 -> V_113 ,
F_17 ( & V_105 -> V_69 ) , V_105 -> V_93 , V_10 ) ;
GOTO ( V_19 , V_10 ) ;
}
V_30 -> V_36 = F_37 ( & V_2 -> V_114 , V_111 ,
V_115 | V_116 ) ;
F_36 ( V_111 ) ;
if ( F_31 ( V_30 -> V_36 ) ) {
V_10 = F_32 ( V_30 -> V_36 ) ;
V_30 -> V_36 = NULL ;
F_4 ( L_39 V_67 L_35
L_38 , V_109 -> V_112 -> V_113 ,
F_17 ( & V_105 -> V_69 ) , V_105 -> V_93 , V_10 ) ;
GOTO ( V_19 , V_10 ) ;
}
V_30 -> V_68 = * V_105 ;
} else if ( V_42 ) {
V_30 -> V_36 = F_27 ( V_117 , V_42 ,
V_115 | V_116 , 0644 ) ;
if ( F_31 ( V_30 -> V_36 ) ) {
V_10 = F_32 ( V_30 -> V_36 ) ;
V_30 -> V_36 = NULL ;
if ( V_10 == - V_94 && V_107 == V_118 ) {
F_28 ( V_30 -> V_119 , strlen ( V_42 ) + 1 ) ;
if ( V_30 -> V_119 )
strcpy ( V_30 -> V_119 , V_42 ) ;
else
GOTO ( V_19 , V_10 = - V_102 ) ;
V_10 = 0 ;
} else {
GOTO ( V_19 , V_10 ) ;
}
} else {
F_38 ( & V_30 -> V_68 ,
V_30 -> V_36 -> V_37 -> V_38 -> V_120 ,
V_30 -> V_36 -> V_37 -> V_38 -> V_121 ) ;
}
} else {
F_39 ( V_107 == V_118 , L_40 , V_107 ) ;
V_30 -> V_36 = NULL ;
}
if ( V_107 != V_118 && V_30 -> V_36 == NULL )
GOTO ( V_122 , V_10 = - V_94 ) ;
return 0 ;
V_122:
if ( V_30 -> V_119 != NULL )
F_33 ( V_30 -> V_119 , strlen ( V_42 ) + 1 ) ;
V_19:
return V_10 ;
}
static int F_40 ( struct V_29 * V_30 )
{
return ( V_30 -> V_36 != NULL ) ;
}
static int F_41 ( const struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_53 * V_54 )
{
struct V_108 * V_109 = V_30 -> V_33 ;
struct V_1 * V_2 ;
struct V_110 * V_111 = NULL ;
struct V_3 * V_3 ;
struct V_123 * V_124 = NULL ;
int V_10 = 0 ;
int V_125 = V_115 | V_126 | V_116 ;
F_2 ( V_109 ) ;
F_2 ( V_109 -> V_34 ) ;
V_2 = V_109 -> V_34 -> V_35 ;
F_2 ( V_30 -> V_36 == NULL ) ;
if ( V_30 -> V_119 ) {
V_3 = F_27 ( V_117 , V_30 -> V_119 ,
V_125 , 0644 ) ;
if ( F_31 ( V_3 ) )
return F_32 ( V_3 ) ;
F_38 ( & V_30 -> V_68 ,
V_3 -> V_37 -> V_38 -> V_120 ,
V_3 -> V_37 -> V_38 -> V_121 ) ;
V_30 -> V_36 = V_3 ;
} else {
F_42 ( V_124 ) ;
if ( V_124 == NULL )
return - V_102 ;
F_43 ( & V_124 -> V_127 ) ;
V_124 -> V_128 = V_129 | V_130 ;
V_10 = F_44 ( NULL , V_109 -> V_34 , V_124 , NULL , NULL ) ;
if ( V_10 )
GOTO ( V_19 , V_10 ) ;
#define F_45 o_parent_oid
V_111 = F_35 ( V_109 -> V_34 , & V_124 -> V_127 ,
V_124 -> F_45 ) ;
if ( F_31 ( V_111 ) )
GOTO ( V_19 , V_10 = F_32 ( V_111 ) ) ;
V_3 = F_37 ( & V_2 -> V_114 , V_111 , V_125 ) ;
F_36 ( V_111 ) ;
if ( F_31 ( V_3 ) )
GOTO ( V_19 , V_10 = F_32 ( V_3 ) ) ;
V_30 -> V_68 . V_69 = V_124 -> V_127 ;
V_30 -> V_68 . V_93 = V_124 -> F_45 ;
V_30 -> V_36 = V_3 ;
V_19:
F_46 ( V_124 ) ;
}
return V_10 ;
}
static int F_47 ( const struct V_27 * V_28 ,
struct V_29 * V_30 )
{
int V_10 ;
if ( V_30 -> V_36 == NULL )
return 0 ;
V_10 = F_48 ( V_30 -> V_36 , 0 ) ;
if ( V_10 )
F_4 ( L_41 V_67 L_42
L_38 , V_30 -> V_33 -> V_112 -> V_113 ,
F_17 ( & V_30 -> V_68 . V_69 ) ,
V_30 -> V_68 . V_93 , V_10 ) ;
V_30 -> V_36 = NULL ;
if ( V_30 -> V_119 ) {
F_33 ( V_30 -> V_119 , strlen ( V_30 -> V_119 ) + 1 ) ;
V_30 -> V_119 = NULL ;
}
return V_10 ;
}
static int F_49 ( const struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_110 * V_131 ;
struct V_123 * V_124 ;
struct V_1 * V_2 = V_30 -> V_33 -> V_34 -> V_35 ;
char * V_96 ;
void * V_54 ;
struct V_132 * V_132 ;
int V_10 , V_133 ;
V_96 = V_117 ;
F_2 ( V_30 -> V_36 ) ;
V_131 = V_30 -> V_36 -> V_37 ;
V_132 = V_131 -> V_134 -> V_38 ;
if ( strcmp ( V_131 -> V_134 -> V_41 . V_42 , V_96 ) == 0 ) {
struct V_135 V_136 ;
struct V_137 * V_138 = F_50 ( V_30 -> V_36 -> V_139 ) ;
F_51 ( & V_136 , & V_2 -> V_114 , NULL ) ;
F_52 ( V_131 ) ;
V_10 = F_47 ( V_28 , V_30 ) ;
if ( V_10 == 0 ) {
F_53 ( & V_132 -> V_140 , V_141 ) ;
V_10 = F_54 ( V_132 , V_131 , V_138 ) ;
F_55 ( & V_132 -> V_140 ) ;
}
F_56 ( V_138 ) ;
F_57 ( V_131 ) ;
F_58 ( & V_136 , & V_2 -> V_114 , NULL ) ;
return V_10 ;
}
F_42 ( V_124 ) ;
if ( V_124 == NULL )
return - V_102 ;
V_124 -> V_127 = V_30 -> V_68 . V_69 ;
V_124 -> F_45 = V_30 -> V_68 . V_93 ;
#undef F_45
V_124 -> V_128 = V_142 | V_130 | V_129 ;
V_10 = F_47 ( V_28 , V_30 ) ;
if ( V_10 )
GOTO ( V_19 , V_10 ) ;
V_54 = F_59 ( V_2 , V_132 , V_143 , NULL , 1 ) ;
if ( F_31 ( V_54 ) ) {
F_4 ( L_43 , F_32 ( V_54 ) ) ;
GOTO ( V_19 , V_10 = F_32 ( V_54 ) ) ;
}
V_10 = F_60 ( NULL , V_30 -> V_33 -> V_34 , V_124 ,
NULL , NULL , NULL , NULL ) ;
V_133 = F_61 ( V_2 , V_132 , V_54 , 0 ) ;
if ( V_10 == 0 && V_133 != 0 )
V_10 = V_133 ;
V_19:
F_46 ( V_124 ) ;
return V_10 ;
}
static int F_62 ( const struct V_27 * V_28 ,
struct V_29 * V_144 ,
struct V_53 * V_54 )
{
return 0 ;
}
static int F_63 ( const struct V_27 * V_28 ,
struct V_29 * V_48 ,
struct V_6 * V_7 ,
int V_52 , struct V_53 * V_54 )
{
return 0 ;
}
