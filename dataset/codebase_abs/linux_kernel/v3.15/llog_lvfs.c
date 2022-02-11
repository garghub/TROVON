static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 V_8 = { 0 } ;
struct V_9 V_10 ;
int V_11 ;
F_2 ( V_5 >= V_12 && ( V_5 & 0x7 ) == 0 ) ;
V_10 . V_13 = V_8 . V_14 = V_5 ;
V_10 . V_15 = V_8 . V_16 = V_6 ;
V_8 . V_17 = V_18 ;
V_11 = F_3 ( V_2 , V_4 , & V_8 , sizeof( V_8 ) , & V_4 -> V_19 , 0 ) ;
if ( V_11 ) {
F_4 ( L_1 , V_11 ) ;
goto V_20;
}
V_4 -> V_19 += V_5 - sizeof( V_8 ) - sizeof( V_10 ) ;
V_11 = F_3 ( V_2 , V_4 , & V_10 , sizeof( V_10 ) , & V_4 -> V_19 , 0 ) ;
if ( V_11 ) {
F_4 ( L_1 , V_11 ) ;
goto V_20;
}
V_20:
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , void * V_21 , T_1 V_22 )
{
int V_11 ;
struct V_9 V_23 ;
T_1 V_24 = V_4 -> V_19 ;
int V_25 = V_8 -> V_14 ;
V_4 -> V_19 = V_22 ;
if ( V_25 == 0 )
F_6 ( L_2 ) ;
if ( ! V_21 ) {
V_11 = F_3 ( V_2 , V_4 , V_8 , V_25 , & V_4 -> V_19 , 0 ) ;
if ( V_11 ) {
F_4 ( L_3 , V_11 ) ;
goto V_20;
}
GOTO ( V_20 , V_11 = 0 ) ;
}
V_8 -> V_14 = sizeof( * V_8 ) + V_25 + sizeof( V_23 ) ;
V_11 = F_3 ( V_2 , V_4 , V_8 , sizeof( * V_8 ) , & V_4 -> V_19 , 0 ) ;
if ( V_11 ) {
F_4 ( L_4 , V_11 ) ;
goto V_20;
}
V_11 = F_3 ( V_2 , V_4 , V_21 , V_25 , & V_4 -> V_19 , 0 ) ;
if ( V_11 ) {
F_4 ( L_5 , V_11 ) ;
goto V_20;
}
V_23 . V_13 = V_8 -> V_14 ;
V_23 . V_15 = V_8 -> V_16 ;
V_11 = F_3 ( V_2 , V_4 , & V_23 , sizeof( V_23 ) , & V_4 -> V_19 , 0 ) ;
if ( V_11 ) {
F_4 ( L_6 , V_11 ) ;
goto V_20;
}
V_11 = 0 ;
V_20:
if ( V_24 > V_4 -> V_19 )
V_4 -> V_19 = V_24 ;
F_2 ( V_11 <= 0 ) ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_21 , int V_26 , T_1 V_22 )
{
T_1 V_27 = V_22 ;
int V_11 ;
V_11 = F_8 ( V_2 , V_4 , V_21 , V_26 , & V_27 ) ;
if ( V_11 ) {
F_4 ( L_7 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_9 ( const struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 ;
int V_11 ;
F_2 ( sizeof( * V_31 -> V_32 ) == V_33 ) ;
V_2 = V_31 -> V_34 -> V_35 -> V_36 ;
if ( F_10 ( V_31 -> V_37 -> V_38 -> V_39 ) == 0 ) {
F_11 ( V_40 , L_8 ) ;
return V_41 ;
}
V_11 = F_7 ( V_2 , V_31 -> V_37 , V_31 -> V_32 ,
V_33 , 0 ) ;
if ( V_11 ) {
F_4 ( L_9 ,
V_31 -> V_37 -> V_38 -> V_42 . V_5 ,
V_31 -> V_37 -> V_38 -> V_42 . V_43 ) ;
} else {
struct V_7 * V_44 = & V_31 -> V_32 -> V_44 ;
if ( F_12 ( V_44 ) )
F_13 ( V_31 -> V_32 ) ;
if ( V_44 -> V_17 != V_45 ) {
F_4 ( L_10 ,
V_31 -> V_37 -> V_38 -> V_42 . V_5 ,
V_31 -> V_37 -> V_38 -> V_42 . V_43 ,
V_44 -> V_17 , V_45 ) ;
V_11 = - V_46 ;
} else if ( V_44 -> V_14 != V_33 ) {
F_4 ( L_11
L_12 ,
V_31 -> V_37 -> V_38 -> V_42 . V_5 ,
V_31 -> V_37 -> V_38 -> V_42 . V_43 ,
V_44 -> V_14 , V_33 ) ;
F_4 ( L_13 ) ;
V_11 = - V_46 ;
}
}
V_31 -> V_47 = V_31 -> V_32 -> V_48 . V_15 ;
V_31 -> V_37 -> V_19 = F_10 ( V_31 -> V_37 -> V_38 -> V_39 ) ;
return V_11 ;
}
static int F_14 ( const struct V_28 * V_29 ,
struct V_30 * V_49 ,
struct V_7 * V_8 ,
struct V_50 * V_51 , int V_52 ,
void * V_21 , int V_53 , struct V_54 * V_55 )
{
struct V_56 * V_57 ;
int V_58 = V_8 -> V_14 , V_6 , V_11 ;
struct V_9 * V_59 ;
struct V_1 * V_2 ;
struct V_4 * V_4 ;
T_2 V_60 ;
V_57 = V_49 -> V_32 ;
V_4 = V_49 -> V_37 ;
V_2 = V_49 -> V_34 -> V_35 -> V_36 ;
if ( V_21 )
V_11 = ( V_58 > V_33 - sizeof( struct V_7 ) -
sizeof( struct V_9 ) ) ? - V_61 : 0 ;
else
V_11 = ( V_58 > V_33 ) ? - V_61 : 0 ;
if ( V_11 )
return V_11 ;
if ( V_21 )
V_58 = sizeof( * V_8 ) + V_8 -> V_14 +
sizeof( struct V_9 ) ;
if ( V_53 != - 1 ) {
T_1 V_62 ;
if ( V_53 != 1 && ! F_10 ( V_4 -> V_38 -> V_39 ) ) {
F_4 ( L_14 ) ;
F_15 () ;
}
if ( V_53 && V_57 -> V_63 && V_57 -> V_63 != V_8 -> V_14 )
return - V_64 ;
if ( ! F_16 ( V_53 , V_57 -> V_65 ) )
F_4 ( L_15 , V_53 ) ;
if ( V_53 != V_8 -> V_16 )
F_4 ( L_16 , V_53 , V_8 -> V_16 ) ;
V_11 = F_5 ( V_2 , V_4 , & V_57 -> V_44 , NULL , 0 ) ;
if ( V_11 || V_53 == 0 )
return V_11 ;
if ( V_21 ) {
V_62 = V_49 -> V_66 ;
F_11 ( V_67 ,
L_17 V_68 L_18
L_19 ,
F_17 ( & V_49 -> V_69 . V_70 ) , V_53 , V_8 -> V_16 ,
V_49 -> V_71 , V_8 -> V_14 ,
( long long ) ( V_62 - sizeof( * V_57 ) ) ) ;
if ( V_8 -> V_16 != V_49 -> V_71 ) {
F_4 ( L_20 ,
V_53 , V_49 -> V_71 ) ;
return - V_72 ;
}
} else {
V_62 = sizeof( * V_57 ) + ( V_53 - 1 ) * V_58 ;
}
V_11 = F_5 ( V_2 , V_4 , V_8 , V_21 , V_62 ) ;
if ( V_11 == 0 && V_51 ) {
V_51 -> V_73 = V_49 -> V_69 ;
V_51 -> V_74 = V_53 ;
V_11 = 1 ;
}
return V_11 ;
}
V_60 = V_33 - ( V_4 -> V_19 & ( V_33 - 1 ) ) ;
if ( V_60 != 0 && V_60 != V_58 &&
V_60 < ( V_58 + V_12 ) ) {
V_6 = V_49 -> V_47 + 1 ;
V_11 = F_1 ( V_2 , V_4 , V_60 , V_6 ) ;
if ( V_11 )
return V_11 ;
V_49 -> V_47 ++ ;
}
if ( V_49 -> V_47 >= F_18 ( V_57 ) - 1 )
return - V_75 ;
V_49 -> V_47 ++ ;
V_6 = V_49 -> V_47 ;
F_2 ( V_6 < F_18 ( V_57 ) ) ;
V_8 -> V_16 = V_6 ;
if ( V_21 == NULL ) {
V_59 = (struct V_9 * )
( ( char * ) V_8 + V_8 -> V_14 - sizeof( * V_59 ) ) ;
V_59 -> V_13 = V_8 -> V_14 ;
V_59 -> V_15 = V_8 -> V_16 ;
}
F_2 ( V_6 < F_18 ( V_57 ) ) ;
F_19 ( & V_49 -> V_76 ) ;
if ( F_20 ( V_6 , V_57 -> V_65 ) ) {
F_4 ( L_21 , V_6 ) ;
F_21 ( & V_49 -> V_76 ) ;
F_15 () ;
}
V_57 -> V_77 ++ ;
F_21 ( & V_49 -> V_76 ) ;
V_57 -> V_48 . V_15 = V_6 ;
V_11 = F_5 ( V_2 , V_4 , & V_57 -> V_44 , NULL , 0 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_2 , V_4 , V_8 , V_21 , V_4 -> V_19 ) ;
if ( V_11 )
return V_11 ;
F_11 ( V_78 , L_22 V_68 L_23 ,
F_17 ( & V_49 -> V_69 . V_70 ) , V_6 , V_8 -> V_14 ) ;
if ( V_11 == 0 && V_51 ) {
V_51 -> V_73 = V_49 -> V_69 ;
V_51 -> V_74 = V_6 ;
if ( ( V_8 -> V_17 == V_79 ) ||
( V_8 -> V_17 == V_80 ) )
V_51 -> V_81 = V_82 ;
else if ( V_8 -> V_17 == V_83 )
V_51 -> V_81 = V_84 ;
else
V_51 -> V_81 = - 1 ;
V_11 = 1 ;
}
if ( V_11 == 0 && V_8 -> V_17 == V_85 )
V_11 = 1 ;
return V_11 ;
}
static void F_22 ( T_3 * V_22 , int V_86 , int V_87 )
{
if ( V_87 <= V_86 )
return;
* V_22 = ( * V_22 + ( V_87 - V_86 - 1 ) * V_12 ) &
~ ( V_33 - 1 ) ;
}
static int F_23 ( const struct V_28 * V_29 ,
struct V_30 * V_49 , int * V_88 ,
int V_89 , T_3 * V_90 , void * V_21 ,
int V_5 )
{
int V_11 ;
if ( V_5 == 0 || V_5 & ( V_33 - 1 ) )
return - V_64 ;
F_11 ( V_67 , L_24 V_91 L_25 ,
V_89 , * V_88 , * V_90 ) ;
while ( * V_90 < F_10 ( V_49 -> V_37 -> V_38 -> V_39 ) ) {
struct V_7 * V_8 , * V_92 ;
struct V_9 * V_10 ;
T_1 V_93 ;
int V_94 ;
F_22 ( V_90 , * V_88 , V_89 ) ;
V_93 = * V_90 ;
V_94 = V_33 - ( * V_90 & ( V_33 - 1 ) ) ;
V_11 = F_8 ( V_49 -> V_34 -> V_35 -> V_36 ,
V_49 -> V_37 , V_21 , V_94 ,
V_90 ) ;
if ( V_11 < 0 ) {
F_4 ( L_26 V_68
L_27 V_91 L_28 ,
F_17 ( & V_49 -> V_69 . V_70 ) ,
V_49 -> V_69 . V_95 ,
* V_90 ) ;
return V_11 ;
}
V_11 = * V_90 - V_93 ;
if ( V_11 < V_5 ) {
memset ( V_21 + V_11 , 0 , V_5 - V_11 ) ;
}
if ( V_11 == 0 )
return 0 ;
if ( V_11 < sizeof( * V_10 ) ) {
F_4 ( L_29 V_68 L_30
V_91 L_28 , F_17 ( & V_49 -> V_69 . V_70 ) ,
V_49 -> V_69 . V_95 , * V_90 ) ;
return - V_64 ;
}
V_8 = V_21 ;
if ( F_12 ( V_8 ) )
F_24 ( V_8 ) ;
V_10 = (struct V_9 * ) ( V_21 + V_11 -
sizeof( struct V_9 ) ) ;
V_92 = (struct V_7 * ) ( V_21 + V_11 -
F_25 ( V_10 -> V_13 ) ) ;
if ( F_12 ( V_92 ) )
F_24 ( V_92 ) ;
F_2 ( V_92 -> V_16 == V_10 -> V_15 ) ;
* V_88 = V_10 -> V_15 ;
if ( V_10 -> V_15 == 0 ) {
F_4 ( L_31 V_68 L_27
V_91 L_28 , F_17 ( & V_49 -> V_69 . V_70 ) ,
V_49 -> V_69 . V_95 , * V_90 ) ;
return - V_64 ;
}
if ( V_10 -> V_15 < V_89 )
continue;
if ( V_8 -> V_16 > V_89 ) {
F_4 ( L_32 ,
V_8 -> V_16 , V_89 ) ;
return - V_96 ;
}
return 0 ;
}
return - V_46 ;
}
static int F_26 ( const struct V_28 * V_29 ,
struct V_30 * V_49 ,
int V_97 , void * V_21 , int V_5 )
{
T_3 V_90 ;
int V_11 ;
if ( V_5 == 0 || V_5 & ( V_33 - 1 ) )
return - V_64 ;
F_11 ( V_67 , L_33 , V_97 ) ;
V_90 = V_33 ;
F_22 ( & V_90 , 0 , V_97 ) ;
while ( V_90 < F_10 ( V_49 -> V_37 -> V_38 -> V_39 ) ) {
struct V_7 * V_8 , * V_92 ;
struct V_9 * V_10 ;
T_1 V_93 = V_90 ;
V_11 = F_8 ( V_49 -> V_34 -> V_35 -> V_36 ,
V_49 -> V_37 , V_21 , V_5 ,
& V_90 ) ;
if ( V_11 < 0 ) {
F_4 ( L_26 V_68
L_27 V_91 L_28 ,
F_17 ( & V_49 -> V_69 . V_70 ) ,
V_49 -> V_69 . V_95 ,
V_90 ) ;
return V_11 ;
}
V_11 = V_90 - V_93 ;
if ( V_11 == 0 )
return 0 ;
if ( V_11 < sizeof( * V_10 ) ) {
F_4 ( L_29 V_68 L_30
V_91 L_28 , F_17 ( & V_49 -> V_69 . V_70 ) ,
V_49 -> V_69 . V_95 , V_90 ) ;
return - V_64 ;
}
V_8 = V_21 ;
if ( F_12 ( V_8 ) )
F_24 ( V_8 ) ;
V_10 = (struct V_9 * ) ( V_21 + V_11 -
sizeof( struct V_9 ) ) ;
V_92 = (struct V_7 * ) ( V_21 + V_11 -
F_25 ( V_10 -> V_13 ) ) ;
if ( F_12 ( V_92 ) )
F_24 ( V_92 ) ;
F_2 ( V_92 -> V_16 == V_10 -> V_15 ) ;
if ( V_10 -> V_15 == 0 ) {
F_4 ( L_31 V_68 L_30
V_91 L_28 , F_17 ( & V_49 -> V_69 . V_70 ) ,
V_49 -> V_69 . V_95 , V_90 ) ;
return - V_64 ;
}
if ( V_10 -> V_15 < V_97 )
continue;
if ( V_8 -> V_16 > V_97 ) {
F_4 ( L_32 ,
V_8 -> V_16 , V_97 ) ;
return - V_96 ;
}
return 0 ;
}
return - V_46 ;
}
static struct V_4 * F_27 ( char * V_98 , char * V_43 , int V_99 , int V_100 )
{
char * V_101 ;
struct V_4 * V_102 ;
int V_5 ;
F_28 ( V_101 , V_103 ) ;
if ( V_101 == NULL )
return F_29 ( - V_104 ) ;
V_5 = snprintf ( V_101 , V_103 , L_34 , V_98 , V_43 ) ;
if ( V_5 >= V_103 - 1 ) {
V_102 = F_29 ( - V_105 ) ;
} else {
V_102 = F_30 ( V_101 , V_99 , V_100 ) ;
if ( F_31 ( V_102 ) && F_32 ( V_102 ) != - V_96 )
F_4 ( L_35 , V_101 ,
F_32 ( V_102 ) ) ;
}
F_33 ( V_101 , V_103 ) ;
return V_102 ;
}
static int F_34 ( const struct V_28 * V_29 , struct V_30 * V_31 ,
struct V_106 * V_107 , char * V_43 ,
enum V_108 V_109 )
{
struct V_110 * V_111 = V_31 -> V_34 ;
struct V_112 * V_113 = NULL ;
struct V_1 * V_2 ;
int V_11 = 0 ;
F_2 ( V_111 ) ;
F_2 ( V_111 -> V_35 ) ;
F_2 ( V_111 -> V_35 -> V_36 ) ;
V_2 = V_111 -> V_35 -> V_36 ;
F_2 ( V_31 ) ;
if ( V_107 != NULL ) {
V_113 = F_35 ( V_111 -> V_35 , & V_107 -> V_70 ,
V_107 -> V_95 ) ;
if ( F_31 ( V_113 ) ) {
V_11 = F_32 ( V_113 ) ;
F_4 ( L_36 V_68 L_37
L_38 , V_111 -> V_114 -> V_115 ,
F_17 ( & V_107 -> V_70 ) , V_107 -> V_95 , V_11 ) ;
GOTO ( V_20 , V_11 ) ;
}
if ( V_113 -> V_39 == NULL ) {
F_36 ( V_113 ) ;
V_11 = - V_96 ;
F_4 ( L_39 V_68 L_37
L_40 , V_111 -> V_114 -> V_115 ,
F_17 ( & V_107 -> V_70 ) , V_107 -> V_95 , V_11 ) ;
GOTO ( V_20 , V_11 ) ;
}
V_31 -> V_37 = F_37 ( & V_2 -> V_116 , V_113 ,
V_117 | V_118 ) ;
F_36 ( V_113 ) ;
if ( F_31 ( V_31 -> V_37 ) ) {
V_11 = F_32 ( V_31 -> V_37 ) ;
V_31 -> V_37 = NULL ;
F_4 ( L_41 V_68 L_37
L_40 , V_111 -> V_114 -> V_115 ,
F_17 ( & V_107 -> V_70 ) , V_107 -> V_95 , V_11 ) ;
GOTO ( V_20 , V_11 ) ;
}
V_31 -> V_69 = * V_107 ;
} else if ( V_43 ) {
V_31 -> V_37 = F_27 ( V_119 , V_43 ,
V_117 | V_118 , 0644 ) ;
if ( F_31 ( V_31 -> V_37 ) ) {
V_11 = F_32 ( V_31 -> V_37 ) ;
V_31 -> V_37 = NULL ;
if ( V_11 == - V_96 && V_109 == V_120 ) {
F_28 ( V_31 -> V_121 , strlen ( V_43 ) + 1 ) ;
if ( V_31 -> V_121 )
strcpy ( V_31 -> V_121 , V_43 ) ;
else
GOTO ( V_20 , V_11 = - V_104 ) ;
V_11 = 0 ;
} else {
GOTO ( V_20 , V_11 ) ;
}
} else {
F_38 ( & V_31 -> V_69 ,
V_31 -> V_37 -> V_38 -> V_39 -> V_122 ,
V_31 -> V_37 -> V_38 -> V_39 -> V_123 ) ;
}
} else {
F_39 ( V_109 == V_120 , L_42 , V_109 ) ;
V_31 -> V_37 = NULL ;
}
if ( V_109 != V_120 && V_31 -> V_37 == NULL )
GOTO ( V_124 , V_11 = - V_96 ) ;
return 0 ;
V_124:
if ( V_31 -> V_121 != NULL )
F_33 ( V_31 -> V_121 , strlen ( V_43 ) + 1 ) ;
V_20:
return V_11 ;
}
static int F_40 ( struct V_30 * V_31 )
{
return ( V_31 -> V_37 != NULL ) ;
}
static int F_41 ( const struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_54 * V_55 )
{
struct V_110 * V_111 = V_31 -> V_34 ;
struct V_1 * V_2 ;
struct V_112 * V_113 = NULL ;
struct V_4 * V_4 ;
struct V_125 * V_126 = NULL ;
int V_11 = 0 ;
int V_127 = V_117 | V_128 | V_118 ;
F_2 ( V_111 ) ;
F_2 ( V_111 -> V_35 ) ;
V_2 = V_111 -> V_35 -> V_36 ;
F_2 ( V_31 -> V_37 == NULL ) ;
if ( V_31 -> V_121 ) {
V_4 = F_27 ( V_119 , V_31 -> V_121 ,
V_127 , 0644 ) ;
if ( F_31 ( V_4 ) )
return F_32 ( V_4 ) ;
F_38 ( & V_31 -> V_69 ,
V_4 -> V_38 -> V_39 -> V_122 ,
V_4 -> V_38 -> V_39 -> V_123 ) ;
V_31 -> V_37 = V_4 ;
} else {
F_42 ( V_126 ) ;
if ( V_126 == NULL )
return - V_104 ;
F_43 ( & V_126 -> V_129 ) ;
V_126 -> V_130 = V_131 | V_132 ;
V_11 = F_44 ( NULL , V_111 -> V_35 , V_126 , NULL , NULL ) ;
if ( V_11 )
GOTO ( V_20 , V_11 ) ;
#define F_45 o_parent_oid
V_113 = F_35 ( V_111 -> V_35 , & V_126 -> V_129 ,
V_126 -> F_45 ) ;
if ( F_31 ( V_113 ) )
GOTO ( V_20 , V_11 = F_32 ( V_113 ) ) ;
V_4 = F_37 ( & V_2 -> V_116 , V_113 , V_127 ) ;
F_36 ( V_113 ) ;
if ( F_31 ( V_4 ) )
GOTO ( V_20 , V_11 = F_32 ( V_4 ) ) ;
V_31 -> V_69 . V_70 = V_126 -> V_129 ;
V_31 -> V_69 . V_95 = V_126 -> F_45 ;
V_31 -> V_37 = V_4 ;
V_20:
F_46 ( V_126 ) ;
}
return V_11 ;
}
static int F_47 ( const struct V_28 * V_29 ,
struct V_30 * V_31 )
{
int V_11 ;
if ( V_31 -> V_37 == NULL )
return 0 ;
V_11 = F_48 ( V_31 -> V_37 , 0 ) ;
if ( V_11 )
F_4 ( L_43 V_68 L_44
L_40 , V_31 -> V_34 -> V_114 -> V_115 ,
F_17 ( & V_31 -> V_69 . V_70 ) ,
V_31 -> V_69 . V_95 , V_11 ) ;
V_31 -> V_37 = NULL ;
if ( V_31 -> V_121 ) {
F_33 ( V_31 -> V_121 , strlen ( V_31 -> V_121 ) + 1 ) ;
V_31 -> V_121 = NULL ;
}
return V_11 ;
}
static int F_49 ( const struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_133 * V_134 ;
struct V_125 * V_126 ;
struct V_1 * V_2 = V_31 -> V_34 -> V_35 -> V_36 ;
char * V_98 ;
void * V_55 ;
struct V_135 * V_135 ;
int V_11 , V_136 ;
V_98 = V_119 ;
F_2 ( V_31 -> V_37 ) ;
V_134 = V_31 -> V_37 -> V_38 ;
V_135 = V_134 -> V_137 -> V_39 ;
if ( strcmp ( V_134 -> V_137 -> V_42 . V_43 , V_98 ) == 0 ) {
struct V_138 V_139 ;
struct V_140 * V_141 = F_50 ( V_31 -> V_37 -> V_142 ) ;
F_51 ( & V_139 , & V_2 -> V_116 , NULL ) ;
F_52 ( V_134 ) ;
V_11 = F_47 ( V_29 , V_31 ) ;
if ( V_11 == 0 ) {
F_53 ( & V_135 -> V_143 , V_144 ) ;
V_11 = F_54 ( V_135 , V_134 , V_141 ) ;
F_55 ( & V_135 -> V_143 ) ;
}
F_56 ( V_141 ) ;
F_57 ( V_134 ) ;
F_58 ( & V_139 , & V_2 -> V_116 , NULL ) ;
return V_11 ;
}
F_42 ( V_126 ) ;
if ( V_126 == NULL )
return - V_104 ;
V_126 -> V_129 = V_31 -> V_69 . V_70 ;
V_126 -> F_45 = V_31 -> V_69 . V_95 ;
#undef F_45
V_126 -> V_130 = V_145 | V_132 | V_131 ;
V_11 = F_47 ( V_29 , V_31 ) ;
if ( V_11 )
GOTO ( V_20 , V_11 ) ;
V_55 = F_59 ( V_2 , V_135 , V_146 , NULL , 1 ) ;
if ( F_31 ( V_55 ) ) {
F_4 ( L_45 , F_32 ( V_55 ) ) ;
GOTO ( V_20 , V_11 = F_32 ( V_55 ) ) ;
}
V_11 = F_60 ( NULL , V_31 -> V_34 -> V_35 , V_126 ,
NULL , NULL , NULL , NULL ) ;
V_136 = F_61 ( V_2 , V_135 , V_55 , 0 ) ;
if ( V_11 == 0 && V_136 != 0 )
V_11 = V_136 ;
V_20:
F_46 ( V_126 ) ;
return V_11 ;
}
static int F_62 ( const struct V_28 * V_29 ,
struct V_30 * V_147 ,
struct V_54 * V_55 )
{
return 0 ;
}
static int F_63 ( const struct V_28 * V_29 ,
struct V_30 * V_49 ,
struct V_7 * V_8 ,
int V_53 , struct V_54 * V_55 )
{
return 0 ;
}
