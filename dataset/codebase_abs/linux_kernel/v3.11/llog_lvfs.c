static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 V_8 = { 0 } ;
struct V_9 V_10 ;
int V_11 ;
V_12 ;
F_2 ( V_5 >= V_13 && ( V_5 & 0x7 ) == 0 ) ;
V_10 . V_14 = V_8 . V_15 = V_5 ;
V_10 . V_16 = V_8 . V_17 = V_6 ;
V_8 . V_18 = V_19 ;
V_11 = F_3 ( V_2 , V_4 , & V_8 , sizeof( V_8 ) , & V_4 -> V_20 , 0 ) ;
if ( V_11 ) {
F_4 ( L_1 , V_11 ) ;
goto V_21;
}
V_4 -> V_20 += V_5 - sizeof( V_8 ) - sizeof( V_10 ) ;
V_11 = F_3 ( V_2 , V_4 , & V_10 , sizeof( V_10 ) , & V_4 -> V_20 , 0 ) ;
if ( V_11 ) {
F_4 ( L_1 , V_11 ) ;
goto V_21;
}
V_21:
RETURN ( V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , void * V_22 , T_1 V_23 )
{
int V_11 ;
struct V_9 V_24 ;
T_1 V_25 = V_4 -> V_20 ;
int V_26 = V_8 -> V_15 ;
V_12 ;
V_4 -> V_20 = V_23 ;
if ( V_26 == 0 )
F_6 ( L_2 ) ;
if ( ! V_22 ) {
V_11 = F_3 ( V_2 , V_4 , V_8 , V_26 , & V_4 -> V_20 , 0 ) ;
if ( V_11 ) {
F_4 ( L_3 , V_11 ) ;
goto V_21;
}
GOTO ( V_21 , V_11 = 0 ) ;
}
V_8 -> V_15 = sizeof( * V_8 ) + V_26 + sizeof( V_24 ) ;
V_11 = F_3 ( V_2 , V_4 , V_8 , sizeof( * V_8 ) , & V_4 -> V_20 , 0 ) ;
if ( V_11 ) {
F_4 ( L_4 , V_11 ) ;
goto V_21;
}
V_11 = F_3 ( V_2 , V_4 , V_22 , V_26 , & V_4 -> V_20 , 0 ) ;
if ( V_11 ) {
F_4 ( L_5 , V_11 ) ;
goto V_21;
}
V_24 . V_14 = V_8 -> V_15 ;
V_24 . V_16 = V_8 -> V_17 ;
V_11 = F_3 ( V_2 , V_4 , & V_24 , sizeof( V_24 ) , & V_4 -> V_20 , 0 ) ;
if ( V_11 ) {
F_4 ( L_6 , V_11 ) ;
goto V_21;
}
V_11 = 0 ;
V_21:
if ( V_25 > V_4 -> V_20 )
V_4 -> V_20 = V_25 ;
F_2 ( V_11 <= 0 ) ;
RETURN ( V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_22 , int V_27 , T_1 V_23 )
{
T_1 V_28 = V_23 ;
int V_11 ;
V_12 ;
V_11 = F_8 ( V_2 , V_4 , V_22 , V_27 , & V_28 ) ;
if ( V_11 ) {
F_4 ( L_7 , V_11 ) ;
RETURN ( V_11 ) ;
}
RETURN ( 0 ) ;
}
static int F_9 ( const struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 ;
int V_11 ;
V_12 ;
F_2 ( sizeof( * V_32 -> V_33 ) == V_34 ) ;
V_2 = V_32 -> V_35 -> V_36 -> V_37 ;
if ( F_10 ( V_32 -> V_38 -> V_39 -> V_40 ) == 0 ) {
F_11 ( V_41 , L_8 ) ;
RETURN ( V_42 ) ;
}
V_11 = F_7 ( V_2 , V_32 -> V_38 , V_32 -> V_33 ,
V_34 , 0 ) ;
if ( V_11 ) {
F_4 ( L_9 ,
V_32 -> V_38 -> V_39 -> V_43 . V_5 ,
V_32 -> V_38 -> V_39 -> V_43 . V_44 ) ;
} else {
struct V_7 * V_45 = & V_32 -> V_33 -> V_45 ;
if ( F_12 ( V_45 ) )
F_13 ( V_32 -> V_33 ) ;
if ( V_45 -> V_18 != V_46 ) {
F_4 ( L_10 ,
V_32 -> V_38 -> V_39 -> V_43 . V_5 ,
V_32 -> V_38 -> V_39 -> V_43 . V_44 ,
V_45 -> V_18 , V_46 ) ;
V_11 = - V_47 ;
} else if ( V_45 -> V_15 != V_34 ) {
F_4 ( L_11
L_12 ,
V_32 -> V_38 -> V_39 -> V_43 . V_5 ,
V_32 -> V_38 -> V_39 -> V_43 . V_44 ,
V_45 -> V_15 , V_34 ) ;
F_4 ( L_13 ) ;
V_11 = - V_47 ;
}
}
V_32 -> V_48 = V_32 -> V_33 -> V_49 . V_16 ;
V_32 -> V_38 -> V_20 = F_10 ( V_32 -> V_38 -> V_39 -> V_40 ) ;
RETURN ( V_11 ) ;
}
static int F_14 ( const struct V_29 * V_30 ,
struct V_31 * V_50 ,
struct V_7 * V_8 ,
struct V_51 * V_52 , int V_53 ,
void * V_22 , int V_54 , struct V_55 * V_56 )
{
struct V_57 * V_58 ;
int V_59 = V_8 -> V_15 , V_6 , V_11 ;
struct V_9 * V_60 ;
struct V_1 * V_2 ;
struct V_4 * V_4 ;
T_2 V_61 ;
V_12 ;
V_58 = V_50 -> V_33 ;
V_4 = V_50 -> V_38 ;
V_2 = V_50 -> V_35 -> V_36 -> V_37 ;
if ( V_22 )
V_11 = ( V_59 > V_34 - sizeof( struct V_7 ) -
sizeof( struct V_9 ) ) ? - V_62 : 0 ;
else
V_11 = ( V_59 > V_34 ) ? - V_62 : 0 ;
if ( V_11 )
RETURN ( V_11 ) ;
if ( V_22 )
V_59 = sizeof( * V_8 ) + V_8 -> V_15 +
sizeof( struct V_9 ) ;
if ( V_54 != - 1 ) {
T_1 V_63 ;
if ( V_54 != 1 && ! F_10 ( V_4 -> V_39 -> V_40 ) ) {
F_4 ( L_14 ) ;
F_15 () ;
}
if ( V_54 && V_58 -> V_64 && V_58 -> V_64 != V_8 -> V_15 )
RETURN ( - V_65 ) ;
if ( ! F_16 ( V_54 , V_58 -> V_66 ) )
F_4 ( L_15 , V_54 ) ;
if ( V_54 != V_8 -> V_17 )
F_4 ( L_16 , V_54 , V_8 -> V_17 ) ;
V_11 = F_5 ( V_2 , V_4 , & V_58 -> V_45 , NULL , 0 ) ;
if ( V_11 || V_54 == 0 )
RETURN ( V_11 ) ;
if ( V_22 ) {
V_63 = V_50 -> V_67 ;
F_11 ( V_68 ,
L_17 V_69 L_18
L_19 ,
F_17 ( & V_50 -> V_70 . V_71 ) , V_54 , V_8 -> V_17 ,
V_50 -> V_72 , V_8 -> V_15 ,
( long long ) ( V_63 - sizeof( * V_58 ) ) ) ;
if ( V_8 -> V_17 != V_50 -> V_72 ) {
F_4 ( L_20 ,
V_54 , V_50 -> V_72 ) ;
RETURN ( - V_73 ) ;
}
} else {
V_63 = sizeof( * V_58 ) + ( V_54 - 1 ) * V_59 ;
}
V_11 = F_5 ( V_2 , V_4 , V_8 , V_22 , V_63 ) ;
if ( V_11 == 0 && V_52 ) {
V_52 -> V_74 = V_50 -> V_70 ;
V_52 -> V_75 = V_54 ;
V_11 = 1 ;
}
RETURN ( V_11 ) ;
}
V_61 = V_34 - ( V_4 -> V_20 & ( V_34 - 1 ) ) ;
if ( V_61 != 0 && V_61 != V_59 &&
V_61 < ( V_59 + V_13 ) ) {
V_6 = V_50 -> V_48 + 1 ;
V_11 = F_1 ( V_2 , V_4 , V_61 , V_6 ) ;
if ( V_11 )
RETURN ( V_11 ) ;
V_50 -> V_48 ++ ;
}
if ( V_50 -> V_48 >= F_18 ( V_58 ) - 1 )
RETURN ( - V_76 ) ;
V_50 -> V_48 ++ ;
V_6 = V_50 -> V_48 ;
F_2 ( V_6 < F_18 ( V_58 ) ) ;
V_8 -> V_17 = V_6 ;
if ( V_22 == NULL ) {
V_60 = (struct V_9 * )
( ( char * ) V_8 + V_8 -> V_15 - sizeof( * V_60 ) ) ;
V_60 -> V_14 = V_8 -> V_15 ;
V_60 -> V_16 = V_8 -> V_17 ;
}
F_2 ( V_6 < F_18 ( V_58 ) ) ;
F_19 ( & V_50 -> V_77 ) ;
if ( F_20 ( V_6 , V_58 -> V_66 ) ) {
F_4 ( L_21 , V_6 ) ;
F_21 ( & V_50 -> V_77 ) ;
F_15 () ;
}
V_58 -> V_78 ++ ;
F_21 ( & V_50 -> V_77 ) ;
V_58 -> V_49 . V_16 = V_6 ;
V_11 = F_5 ( V_2 , V_4 , & V_58 -> V_45 , NULL , 0 ) ;
if ( V_11 )
RETURN ( V_11 ) ;
V_11 = F_5 ( V_2 , V_4 , V_8 , V_22 , V_4 -> V_20 ) ;
if ( V_11 )
RETURN ( V_11 ) ;
F_11 ( V_79 , L_22 V_69 L_23 ,
F_17 ( & V_50 -> V_70 . V_71 ) , V_6 , V_8 -> V_15 ) ;
if ( V_11 == 0 && V_52 ) {
V_52 -> V_74 = V_50 -> V_70 ;
V_52 -> V_75 = V_6 ;
if ( ( V_8 -> V_18 == V_80 ) ||
( V_8 -> V_18 == V_81 ) )
V_52 -> V_82 = V_83 ;
else if ( V_8 -> V_18 == V_84 )
V_52 -> V_82 = V_85 ;
else
V_52 -> V_82 = - 1 ;
V_11 = 1 ;
}
if ( V_11 == 0 && V_8 -> V_18 == V_86 )
V_11 = 1 ;
RETURN ( V_11 ) ;
}
static void F_22 ( T_3 * V_23 , int V_87 , int V_88 )
{
if ( V_88 <= V_87 )
return;
* V_23 = ( * V_23 + ( V_88 - V_87 - 1 ) * V_13 ) &
~ ( V_34 - 1 ) ;
}
static int F_23 ( const struct V_29 * V_30 ,
struct V_31 * V_50 , int * V_89 ,
int V_90 , T_3 * V_91 , void * V_22 ,
int V_5 )
{
int V_11 ;
V_12 ;
if ( V_5 == 0 || V_5 & ( V_34 - 1 ) )
RETURN ( - V_65 ) ;
F_11 ( V_68 , L_24 V_92 L_25 ,
V_90 , * V_89 , * V_91 ) ;
while ( * V_91 < F_10 ( V_50 -> V_38 -> V_39 -> V_40 ) ) {
struct V_7 * V_8 , * V_93 ;
struct V_9 * V_10 ;
T_1 V_94 ;
int V_95 ;
F_22 ( V_91 , * V_89 , V_90 ) ;
V_94 = * V_91 ;
V_95 = V_34 - ( * V_91 & ( V_34 - 1 ) ) ;
V_11 = F_8 ( V_50 -> V_35 -> V_36 -> V_37 ,
V_50 -> V_38 , V_22 , V_95 ,
V_91 ) ;
if ( V_11 < 0 ) {
F_4 ( L_26 V_69
L_27 V_92 L_28 ,
F_17 ( & V_50 -> V_70 . V_71 ) ,
V_50 -> V_70 . V_96 ,
* V_91 ) ;
RETURN ( V_11 ) ;
}
V_11 = * V_91 - V_94 ;
if ( V_11 < V_5 ) {
memset ( V_22 + V_11 , 0 , V_5 - V_11 ) ;
}
if ( V_11 == 0 )
RETURN ( 0 ) ;
if ( V_11 < sizeof( * V_10 ) ) {
F_4 ( L_29 V_69 L_30
V_92 L_28 , F_17 ( & V_50 -> V_70 . V_71 ) ,
V_50 -> V_70 . V_96 , * V_91 ) ;
RETURN ( - V_65 ) ;
}
V_8 = V_22 ;
if ( F_12 ( V_8 ) )
F_24 ( V_8 ) ;
V_10 = (struct V_9 * ) ( V_22 + V_11 -
sizeof( struct V_9 ) ) ;
V_93 = (struct V_7 * ) ( V_22 + V_11 -
F_25 ( V_10 -> V_14 ) ) ;
if ( F_12 ( V_93 ) )
F_24 ( V_93 ) ;
F_2 ( V_93 -> V_17 == V_10 -> V_16 ) ;
* V_89 = V_10 -> V_16 ;
if ( V_10 -> V_16 == 0 ) {
F_4 ( L_31 V_69 L_27
V_92 L_28 , F_17 ( & V_50 -> V_70 . V_71 ) ,
V_50 -> V_70 . V_96 , * V_91 ) ;
RETURN ( - V_65 ) ;
}
if ( V_10 -> V_16 < V_90 )
continue;
if ( V_8 -> V_17 > V_90 ) {
F_4 ( L_32 ,
V_8 -> V_17 , V_90 ) ;
RETURN ( - V_97 ) ;
}
RETURN ( 0 ) ;
}
RETURN ( - V_47 ) ;
}
static int F_26 ( const struct V_29 * V_30 ,
struct V_31 * V_50 ,
int V_98 , void * V_22 , int V_5 )
{
T_3 V_91 ;
int V_11 ;
V_12 ;
if ( V_5 == 0 || V_5 & ( V_34 - 1 ) )
RETURN ( - V_65 ) ;
F_11 ( V_68 , L_33 , V_98 ) ;
V_91 = V_34 ;
F_22 ( & V_91 , 0 , V_98 ) ;
while ( V_91 < F_10 ( V_50 -> V_38 -> V_39 -> V_40 ) ) {
struct V_7 * V_8 , * V_93 ;
struct V_9 * V_10 ;
T_1 V_94 = V_91 ;
V_11 = F_8 ( V_50 -> V_35 -> V_36 -> V_37 ,
V_50 -> V_38 , V_22 , V_5 ,
& V_91 ) ;
if ( V_11 < 0 ) {
F_4 ( L_26 V_69
L_27 V_92 L_28 ,
F_17 ( & V_50 -> V_70 . V_71 ) ,
V_50 -> V_70 . V_96 ,
V_91 ) ;
RETURN ( V_11 ) ;
}
V_11 = V_91 - V_94 ;
if ( V_11 == 0 )
RETURN ( 0 ) ;
if ( V_11 < sizeof( * V_10 ) ) {
F_4 ( L_29 V_69 L_30
V_92 L_28 , F_17 ( & V_50 -> V_70 . V_71 ) ,
V_50 -> V_70 . V_96 , V_91 ) ;
RETURN ( - V_65 ) ;
}
V_8 = V_22 ;
if ( F_12 ( V_8 ) )
F_24 ( V_8 ) ;
V_10 = (struct V_9 * ) ( V_22 + V_11 -
sizeof( struct V_9 ) ) ;
V_93 = (struct V_7 * ) ( V_22 + V_11 -
F_25 ( V_10 -> V_14 ) ) ;
if ( F_12 ( V_93 ) )
F_24 ( V_93 ) ;
F_2 ( V_93 -> V_17 == V_10 -> V_16 ) ;
if ( V_10 -> V_16 == 0 ) {
F_4 ( L_31 V_69 L_30
V_92 L_28 , F_17 ( & V_50 -> V_70 . V_71 ) ,
V_50 -> V_70 . V_96 , V_91 ) ;
RETURN ( - V_65 ) ;
}
if ( V_10 -> V_16 < V_98 )
continue;
if ( V_8 -> V_17 > V_98 ) {
F_4 ( L_32 ,
V_8 -> V_17 , V_98 ) ;
RETURN ( - V_97 ) ;
}
RETURN ( 0 ) ;
}
RETURN ( - V_47 ) ;
}
static struct V_4 * F_27 ( char * V_99 , char * V_44 , int V_100 , int V_101 )
{
char * V_102 ;
struct V_4 * V_103 ;
int V_5 ;
F_28 ( V_102 , V_104 ) ;
if ( V_102 == NULL )
return F_29 ( - V_105 ) ;
V_5 = snprintf ( V_102 , V_104 , L_34 , V_99 , V_44 ) ;
if ( V_5 >= V_104 - 1 ) {
V_103 = F_29 ( - V_106 ) ;
} else {
V_103 = F_30 ( V_102 , V_100 , V_101 ) ;
if ( F_31 ( V_103 ) && F_32 ( V_103 ) != - V_97 )
F_4 ( L_35 , V_102 ,
F_32 ( V_103 ) ) ;
}
F_33 ( V_102 , V_104 ) ;
return V_103 ;
}
static int F_34 ( const struct V_29 * V_30 , struct V_31 * V_32 ,
struct V_107 * V_108 , char * V_44 ,
enum V_109 V_110 )
{
struct V_111 * V_112 = V_32 -> V_35 ;
struct V_113 * V_114 = NULL ;
struct V_1 * V_2 ;
int V_11 = 0 ;
V_12 ;
F_2 ( V_112 ) ;
F_2 ( V_112 -> V_36 ) ;
F_2 ( V_112 -> V_36 -> V_37 ) ;
V_2 = V_112 -> V_36 -> V_37 ;
F_2 ( V_32 ) ;
if ( V_108 != NULL ) {
V_114 = F_35 ( V_112 -> V_36 , & V_108 -> V_71 ,
V_108 -> V_96 ) ;
if ( F_31 ( V_114 ) ) {
V_11 = F_32 ( V_114 ) ;
F_4 ( L_36 V_69 L_37
L_38 , V_112 -> V_115 -> V_116 ,
F_17 ( & V_108 -> V_71 ) , V_108 -> V_96 , V_11 ) ;
GOTO ( V_21 , V_11 ) ;
}
if ( V_114 -> V_40 == NULL ) {
F_36 ( V_114 ) ;
V_11 = - V_97 ;
F_4 ( L_39 V_69 L_37
L_40 , V_112 -> V_115 -> V_116 ,
F_17 ( & V_108 -> V_71 ) , V_108 -> V_96 , V_11 ) ;
GOTO ( V_21 , V_11 ) ;
}
V_32 -> V_38 = F_37 ( & V_2 -> V_117 , V_114 ,
V_118 | V_119 ) ;
F_36 ( V_114 ) ;
if ( F_31 ( V_32 -> V_38 ) ) {
V_11 = F_32 ( V_32 -> V_38 ) ;
V_32 -> V_38 = NULL ;
F_4 ( L_41 V_69 L_37
L_40 , V_112 -> V_115 -> V_116 ,
F_17 ( & V_108 -> V_71 ) , V_108 -> V_96 , V_11 ) ;
GOTO ( V_21 , V_11 ) ;
}
V_32 -> V_70 = * V_108 ;
} else if ( V_44 ) {
V_32 -> V_38 = F_27 ( V_120 , V_44 ,
V_118 | V_119 , 0644 ) ;
if ( F_31 ( V_32 -> V_38 ) ) {
V_11 = F_32 ( V_32 -> V_38 ) ;
V_32 -> V_38 = NULL ;
if ( V_11 == - V_97 && V_110 == V_121 ) {
F_28 ( V_32 -> V_122 , strlen ( V_44 ) + 1 ) ;
if ( V_32 -> V_122 )
strcpy ( V_32 -> V_122 , V_44 ) ;
else
GOTO ( V_21 , V_11 = - V_105 ) ;
V_11 = 0 ;
} else {
GOTO ( V_21 , V_11 ) ;
}
} else {
F_38 ( & V_32 -> V_70 ,
V_32 -> V_38 -> V_39 -> V_40 -> V_123 ,
V_32 -> V_38 -> V_39 -> V_40 -> V_124 ) ;
}
} else {
F_39 ( V_110 == V_121 , L_42 , V_110 ) ;
V_32 -> V_38 = NULL ;
}
if ( V_110 != V_121 && V_32 -> V_38 == NULL )
GOTO ( V_125 , V_11 = - V_97 ) ;
RETURN ( 0 ) ;
V_125:
if ( V_32 -> V_122 != NULL )
F_33 ( V_32 -> V_122 , strlen ( V_44 ) + 1 ) ;
V_21:
RETURN ( V_11 ) ;
}
static int F_40 ( struct V_31 * V_32 )
{
return ( V_32 -> V_38 != NULL ) ;
}
static int F_41 ( const struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_55 * V_56 )
{
struct V_111 * V_112 = V_32 -> V_35 ;
struct V_1 * V_2 ;
struct V_113 * V_114 = NULL ;
struct V_4 * V_4 ;
struct V_126 * V_127 = NULL ;
int V_11 = 0 ;
int V_128 = V_118 | V_129 | V_119 ;
V_12 ;
F_2 ( V_112 ) ;
F_2 ( V_112 -> V_36 ) ;
V_2 = V_112 -> V_36 -> V_37 ;
F_2 ( V_32 -> V_38 == NULL ) ;
if ( V_32 -> V_122 ) {
V_4 = F_27 ( V_120 , V_32 -> V_122 ,
V_128 , 0644 ) ;
if ( F_31 ( V_4 ) )
RETURN ( F_32 ( V_4 ) ) ;
F_38 ( & V_32 -> V_70 ,
V_4 -> V_39 -> V_40 -> V_123 ,
V_4 -> V_39 -> V_40 -> V_124 ) ;
V_32 -> V_38 = V_4 ;
} else {
F_42 ( V_127 ) ;
if ( V_127 == NULL )
RETURN ( - V_105 ) ;
F_43 ( & V_127 -> V_130 ) ;
V_127 -> V_131 = V_132 | V_133 ;
V_11 = F_44 ( NULL , V_112 -> V_36 , V_127 , NULL , NULL ) ;
if ( V_11 )
GOTO ( V_21 , V_11 ) ;
#define F_45 o_parent_oid
V_114 = F_35 ( V_112 -> V_36 , & V_127 -> V_130 ,
V_127 -> F_45 ) ;
if ( F_31 ( V_114 ) )
GOTO ( V_21 , V_11 = F_32 ( V_114 ) ) ;
V_4 = F_37 ( & V_2 -> V_117 , V_114 , V_128 ) ;
F_36 ( V_114 ) ;
if ( F_31 ( V_4 ) )
GOTO ( V_21 , V_11 = F_32 ( V_4 ) ) ;
V_32 -> V_70 . V_71 = V_127 -> V_130 ;
V_32 -> V_70 . V_96 = V_127 -> F_45 ;
V_32 -> V_38 = V_4 ;
V_21:
F_46 ( V_127 ) ;
}
RETURN ( V_11 ) ;
}
static int F_47 ( const struct V_29 * V_30 ,
struct V_31 * V_32 )
{
int V_11 ;
V_12 ;
if ( V_32 -> V_38 == NULL )
RETURN ( 0 ) ;
V_11 = F_48 ( V_32 -> V_38 , 0 ) ;
if ( V_11 )
F_4 ( L_43 V_69 L_44
L_40 , V_32 -> V_35 -> V_115 -> V_116 ,
F_17 ( & V_32 -> V_70 . V_71 ) ,
V_32 -> V_70 . V_96 , V_11 ) ;
V_32 -> V_38 = NULL ;
if ( V_32 -> V_122 ) {
F_33 ( V_32 -> V_122 , strlen ( V_32 -> V_122 ) + 1 ) ;
V_32 -> V_122 = NULL ;
}
RETURN ( V_11 ) ;
}
static int F_49 ( const struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_134 * V_135 ;
struct V_126 * V_127 ;
struct V_1 * V_2 = V_32 -> V_35 -> V_36 -> V_37 ;
char * V_99 ;
void * V_56 ;
struct V_136 * V_136 ;
int V_11 , V_137 ;
V_12 ;
V_99 = V_120 ;
F_2 ( V_32 -> V_38 ) ;
V_135 = V_32 -> V_38 -> V_39 ;
V_136 = V_135 -> V_138 -> V_40 ;
if ( strcmp ( V_135 -> V_138 -> V_43 . V_44 , V_99 ) == 0 ) {
struct V_139 V_140 ;
struct V_141 * V_142 = F_50 ( V_32 -> V_38 -> V_143 ) ;
F_51 ( & V_140 , & V_2 -> V_117 , NULL ) ;
F_52 ( V_135 ) ;
V_11 = F_47 ( V_30 , V_32 ) ;
if ( V_11 == 0 ) {
F_53 ( & V_136 -> V_144 , V_145 ) ;
V_11 = F_54 ( V_136 , V_135 , V_142 ) ;
F_55 ( & V_136 -> V_144 ) ;
}
F_56 ( V_142 ) ;
F_57 ( V_135 ) ;
F_58 ( & V_140 , & V_2 -> V_117 , NULL ) ;
RETURN ( V_11 ) ;
}
F_42 ( V_127 ) ;
if ( V_127 == NULL )
RETURN ( - V_105 ) ;
V_127 -> V_130 = V_32 -> V_70 . V_71 ;
V_127 -> F_45 = V_32 -> V_70 . V_96 ;
#undef F_45
V_127 -> V_131 = V_146 | V_133 | V_132 ;
V_11 = F_47 ( V_30 , V_32 ) ;
if ( V_11 )
GOTO ( V_21 , V_11 ) ;
V_56 = F_59 ( V_2 , V_136 , V_147 , NULL , 1 ) ;
if ( F_31 ( V_56 ) ) {
F_4 ( L_45 , F_32 ( V_56 ) ) ;
GOTO ( V_21 , V_11 = F_32 ( V_56 ) ) ;
}
V_11 = F_60 ( NULL , V_32 -> V_35 -> V_36 , V_127 ,
NULL , NULL , NULL , NULL ) ;
V_137 = F_61 ( V_2 , V_136 , V_56 , 0 ) ;
if ( V_11 == 0 && V_137 != 0 )
V_11 = V_137 ;
V_21:
F_46 ( V_127 ) ;
RETURN ( V_11 ) ;
}
static int F_62 ( const struct V_29 * V_30 ,
struct V_31 * V_148 ,
struct V_55 * V_56 )
{
return 0 ;
}
static int F_63 ( const struct V_29 * V_30 ,
struct V_31 * V_50 ,
struct V_7 * V_8 ,
int V_54 , struct V_55 * V_56 )
{
return 0 ;
}
