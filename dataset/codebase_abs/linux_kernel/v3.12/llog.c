struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( V_2 ) ;
if ( V_2 == NULL )
return F_3 ( - V_3 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_5 ( & V_2 -> V_5 ) ;
F_6 ( & V_2 -> V_6 . V_7 . V_8 ) ;
F_7 ( & V_2 -> V_9 , 1 ) ;
return V_2 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 != NULL ) ;
if ( ! V_2 -> V_10 )
goto V_11;
if ( V_2 -> V_10 -> V_12 & V_13 )
F_9 ( F_10 ( & V_2 -> V_6 . V_7 . V_8 ) ) ;
else if ( V_2 -> V_10 -> V_12 & V_14 )
F_9 ( F_10 ( & V_2 -> V_6 . V_15 . V_16 ) ) ;
F_9 ( sizeof( * ( V_2 -> V_10 ) ) == V_17 ) ;
F_11 ( V_2 -> V_10 , V_17 ) ;
V_11:
F_12 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_9 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_9 ( F_16 ( & V_2 -> V_9 ) > 0 ) ;
if ( F_17 ( & V_2 -> V_9 ) )
F_8 ( V_2 ) ;
}
int F_18 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
int V_20 )
{
struct V_21 * V_22 = V_2 -> V_10 ;
int V_23 = 0 ;
F_19 ( V_24 , L_1 V_25 L_2 ,
V_20 , F_20 ( & V_2 -> V_26 . V_27 ) ) ;
if ( V_20 == 0 ) {
F_21 ( L_3 ) ;
return - V_28 ;
}
F_22 ( & V_2 -> V_5 ) ;
if ( ! F_23 ( V_20 , V_22 -> V_29 ) ) {
F_24 ( & V_2 -> V_5 ) ;
F_19 ( V_24 , L_4 , V_20 ) ;
return - V_30 ;
}
V_22 -> V_31 -- ;
if ( ( V_22 -> V_12 & V_32 ) &&
( V_22 -> V_31 == 1 ) &&
( V_2 -> V_33 == ( V_34 * 8 ) - 1 ) ) {
F_24 ( & V_2 -> V_5 ) ;
V_23 = F_25 ( V_19 , V_2 ) ;
if ( V_23 < 0 ) {
F_21 ( L_5 V_25
L_6 ,
V_2 -> V_35 -> V_36 -> V_37 ,
F_20 ( & V_2 -> V_26 . V_27 ) ,
V_2 -> V_26 . V_38 , V_23 ) ;
GOTO ( V_39 , V_23 ) ;
}
return 1 ;
}
F_24 ( & V_2 -> V_5 ) ;
V_23 = F_26 ( V_19 , V_2 , & V_22 -> V_40 , NULL , 0 , NULL , 0 ) ;
if ( V_23 < 0 ) {
F_21 ( L_7 V_25
L_6 ,
V_2 -> V_35 -> V_36 -> V_37 ,
F_20 ( & V_2 -> V_26 . V_27 ) ,
V_2 -> V_26 . V_38 , V_23 ) ;
GOTO ( V_39 , V_23 ) ;
}
return 0 ;
V_39:
F_22 ( & V_2 -> V_5 ) ;
F_27 ( V_20 , V_22 -> V_29 ) ;
V_22 -> V_31 ++ ;
F_24 ( & V_2 -> V_5 ) ;
return V_23 ;
}
static int F_28 ( const struct V_18 * V_19 ,
struct V_1 * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_23 ;
V_23 = F_29 ( V_41 , & V_45 ) ;
if ( V_23 )
return V_23 ;
if ( V_45 -> V_46 == NULL )
return - V_47 ;
V_23 = V_45 -> V_46 ( V_19 , V_41 ) ;
if ( V_23 == V_48 ) {
struct V_21 * V_22 = V_41 -> V_10 ;
V_41 -> V_33 = 0 ;
V_22 -> V_31 = 1 ;
V_22 -> V_40 . V_49 = V_50 ;
V_22 -> V_40 . V_51 = V_22 -> V_52 . V_53 = V_17 ;
V_22 -> V_40 . V_54 = V_22 -> V_52 . V_55 = 0 ;
V_22 -> V_56 = F_30 () ;
if ( V_43 )
memcpy ( & V_22 -> V_57 , V_43 ,
sizeof( V_22 -> V_57 ) ) ;
V_22 -> V_58 = F_31 ( F_32 ( * V_22 ) , V_29 ) ;
F_27 ( 0 , V_22 -> V_29 ) ;
V_23 = 0 ;
}
return V_23 ;
}
int F_33 ( const struct V_18 * V_19 , struct V_1 * V_41 ,
int V_59 , struct V_42 * V_43 )
{
struct V_21 * V_22 ;
int V_23 ;
F_9 ( V_41 -> V_10 == NULL ) ;
F_2 ( V_22 ) ;
if ( V_22 == NULL )
return - V_3 ;
V_41 -> V_10 = V_22 ;
V_22 -> V_12 = V_59 ;
V_23 = F_28 ( V_19 , V_41 , V_43 ) ;
if ( V_23 == 0 ) {
if ( F_34 ( ( V_22 -> V_12 & V_13 &&
V_59 & V_14 ) ||
( V_22 -> V_12 & V_14 &&
V_59 & V_13 ) ) ) {
F_21 ( L_8 ,
V_41 -> V_35 -> V_36 -> V_37 ,
V_22 -> V_12 & V_14 ?
L_9 : L_10 ,
V_59 & V_14 ? L_9 : L_10 ) ;
GOTO ( V_11 , V_23 = - V_28 ) ;
} else if ( V_22 -> V_12 &
( V_13 | V_14 ) ) {
V_59 = V_22 -> V_12 ;
} else {
F_21 ( L_11 ) ;
GOTO ( V_11 , V_23 = - V_28 ) ;
}
if ( F_34 ( V_43 &&
! F_35 ( V_43 , & V_22 -> V_57 ) ) ) {
F_21 ( L_12 ,
V_41 -> V_35 -> V_36 -> V_37 ,
( char * ) V_43 -> V_43 ,
( char * ) V_22 -> V_57 . V_43 ) ;
GOTO ( V_11 , V_23 = - V_60 ) ;
}
}
if ( V_59 & V_14 ) {
F_9 ( F_10 ( & V_41 -> V_6 . V_15 . V_16 ) ) ;
F_6 ( & V_41 -> V_6 . V_15 . V_16 ) ;
V_22 -> V_61 = sizeof( struct V_62 ) ;
} else if ( ! ( V_59 & V_13 ) ) {
F_21 ( L_13 ,
V_41 -> V_35 -> V_36 -> V_37 ,
V_59 , V_14 , V_13 ) ;
V_23 = - V_28 ;
}
V_11:
if ( V_23 ) {
F_12 ( V_22 ) ;
V_41 -> V_10 = NULL ;
}
return V_23 ;
}
int F_36 ( const struct V_18 * V_19 ,
struct V_1 * V_22 ,
struct V_63 * V_64 ,
void * V_65 )
{
struct V_63 V_66 = * V_64 ;
struct V_1 * V_67 = (struct V_1 * ) V_65 ;
char * V_68 = ( char * ) ( V_64 + 1 ) ;
struct V_69 * V_70 ;
int V_23 = 0 ;
V_66 . V_51 -= sizeof( * V_64 ) + sizeof( struct V_71 ) ;
V_23 = F_26 ( V_19 , V_67 , & V_66 , NULL , 0 ,
( void * ) V_68 , - 1 ) ;
V_70 = (struct V_69 * ) V_68 ;
F_19 ( V_72 , L_14 ,
V_64 -> V_54 , V_23 , V_64 -> V_51 , V_70 -> V_73 ,
F_37 ( V_70 , 0 ) , F_37 ( V_70 , 1 ) ) ;
return V_23 ;
}
static int F_38 ( void * V_74 )
{
struct V_75 * V_76 = V_74 ;
struct V_1 * V_2 = V_76 -> V_77 ;
struct V_21 * V_22 = V_2 -> V_10 ;
struct V_78 * V_79 = V_76 -> V_80 ;
char * V_81 ;
T_1 V_82 = V_17 ;
T_1 V_83 ;
int V_23 = 0 , V_20 = 1 , V_84 ;
int V_85 = 0 ;
int V_86 = 0 ;
F_9 ( V_22 ) ;
F_39 ( V_81 , V_17 ) ;
if ( ! V_81 ) {
V_76 -> V_87 = - V_3 ;
return 0 ;
}
if ( V_79 != NULL ) {
V_86 = V_79 -> V_88 ;
V_20 = V_79 -> V_88 + 1 ;
}
if ( V_79 != NULL && V_79 -> V_89 )
V_84 = V_79 -> V_89 ;
else
V_84 = V_34 * 8 - 1 ;
while ( V_23 == 0 ) {
struct V_63 * V_64 ;
while ( V_20 <= V_84 &&
! F_40 ( V_20 , V_22 -> V_29 ) )
++ V_20 ;
F_9 ( V_20 <= V_84 + 1 ) ;
if ( V_20 == V_84 + 1 )
break;
V_90:
F_19 ( V_91 , L_15 ,
V_20 , V_84 ) ;
memset ( V_81 , 0 , V_17 ) ;
V_83 = V_82 ;
V_23 = F_41 ( V_76 -> V_92 , V_2 , & V_85 ,
V_20 , & V_82 , V_81 , V_17 ) ;
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
for ( V_64 = (struct V_63 * ) V_81 ;
( char * ) V_64 < V_81 + V_17 ;
V_64 = (struct V_63 * ) ( ( char * ) V_64 + V_64 -> V_51 ) ) {
F_19 ( V_91 , L_16 ,
V_64 , V_64 -> V_49 ) ;
if ( F_42 ( V_64 ) )
F_43 ( V_64 ) ;
F_19 ( V_91 , L_17 ,
V_64 -> V_49 , V_64 -> V_54 ) ;
if ( V_64 -> V_54 == 0 ) {
if ( V_20 <= V_2 -> V_33 )
GOTO ( V_90 , V_23 = 0 ) ;
GOTO ( V_11 , V_23 = 0 ) ;
}
if ( V_64 -> V_51 == 0 ||
V_64 -> V_51 > V_17 ) {
F_44 ( L_18
L_19 , V_64 -> V_51 ,
V_64 -> V_54 , V_20 ) ;
GOTO ( V_11 , V_23 = - V_28 ) ;
}
if ( V_64 -> V_54 < V_20 ) {
F_19 ( V_91 , L_20 ,
V_64 -> V_54 ) ;
continue;
}
F_19 ( V_91 ,
L_21 ,
V_64 -> V_54 , V_64 -> V_51 ,
( int ) ( V_81 + V_17 - ( char * ) V_64 ) ) ;
V_2 -> V_93 = V_64 -> V_54 ;
V_2 -> V_94 = ( char * ) V_64 - ( char * ) V_81 +
V_83 ;
if ( F_40 ( V_20 , V_22 -> V_29 ) ) {
V_23 = V_76 -> V_95 ( V_76 -> V_92 , V_2 , V_64 ,
V_76 -> V_96 ) ;
V_86 = V_20 ;
if ( V_23 == V_97 ) {
GOTO ( V_11 , V_23 ) ;
} else if ( V_23 == V_98 ) {
F_18 ( V_76 -> V_92 ,
V_2 ,
V_64 -> V_54 ) ;
V_23 = 0 ;
}
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
} else {
F_19 ( V_91 , L_22 , V_20 ) ;
}
++ V_20 ;
if ( V_20 > V_84 )
GOTO ( V_11 , V_23 = 0 ) ;
}
}
V_11:
if ( V_79 != NULL )
V_79 -> V_89 = V_86 ;
F_11 ( V_81 , V_17 ) ;
V_76 -> V_87 = V_23 ;
return 0 ;
}
static int F_45 ( void * V_74 )
{
struct V_75 * V_76 = V_74 ;
struct V_18 V_19 ;
int V_23 ;
F_46 () ;
V_23 = F_47 ( & V_19 , V_99 | V_100 ) ;
if ( V_23 )
goto V_11;
V_76 -> V_92 = & V_19 ;
V_23 = F_38 ( V_74 ) ;
F_48 ( & V_19 ) ;
V_11:
F_49 ( & V_76 -> V_101 ) ;
return V_23 ;
}
int F_50 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
T_2 V_102 , void * V_65 , void * V_103 , bool V_104 )
{
struct V_75 * V_76 ;
int V_23 ;
F_2 ( V_76 ) ;
if ( V_76 == NULL ) {
F_21 ( L_23 ) ;
return - V_3 ;
}
V_76 -> V_77 = V_2 ;
V_76 -> V_95 = V_102 ;
V_76 -> V_96 = V_65 ;
V_76 -> V_80 = V_103 ;
if ( V_104 ) {
V_76 -> V_92 = NULL ;
F_51 ( & V_76 -> V_101 ) ;
V_23 = F_52 ( F_53 ( F_45 , V_76 ,
L_24 ) ) ;
if ( F_54 ( V_23 ) ) {
F_21 ( L_25 ,
V_2 -> V_35 -> V_36 -> V_37 , V_23 ) ;
F_12 ( V_76 ) ;
return V_23 ;
}
F_55 ( & V_76 -> V_101 ) ;
} else {
V_76 -> V_92 = V_19 ;
F_38 ( V_76 ) ;
}
V_23 = V_76 -> V_87 ;
F_12 ( V_76 ) ;
return V_23 ;
}
int F_56 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_102 , void * V_65 , void * V_103 )
{
return F_50 ( V_19 , V_2 , V_102 , V_65 , V_103 , true ) ;
}
inline int F_57 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_10 )
return V_2 -> V_10 -> V_31 ;
return 0 ;
}
int F_58 ( const struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_102 ,
void * V_65 , void * V_103 )
{
struct V_21 * V_22 = V_2 -> V_10 ;
struct V_78 * V_79 = V_103 ;
void * V_81 ;
int V_23 = 0 , V_105 = 1 , V_20 , V_106 ;
F_39 ( V_81 , V_17 ) ;
if ( ! V_81 )
return - V_3 ;
if ( V_79 != NULL )
V_105 = V_79 -> V_88 + 1 ;
if ( V_79 != NULL && V_79 -> V_89 )
V_20 = V_79 -> V_89 ;
else
V_20 = V_34 * 8 - 1 ;
while ( V_23 == 0 ) {
struct V_63 * V_64 ;
struct V_71 * V_107 ;
while ( V_20 >= V_105 &&
! F_40 ( V_20 , V_22 -> V_29 ) )
-- V_20 ;
F_9 ( V_20 >= V_105 - 1 ) ;
if ( V_20 == V_105 - 1 )
break;
memset ( V_81 , 0 , V_17 ) ;
V_23 = F_59 ( V_19 , V_2 , V_20 , V_81 ,
V_17 ) ;
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
V_64 = V_81 ;
V_106 = V_64 -> V_54 ;
F_19 ( V_24 , L_26 , V_20 , V_106 ) ;
while ( V_106 < V_20 ) {
V_64 = ( void * ) V_64 + V_64 -> V_51 ;
if ( F_42 ( V_64 ) )
F_43 ( V_64 ) ;
V_106 ++ ;
}
F_9 ( V_106 == V_20 ) ;
V_107 = ( void * ) V_64 + V_64 -> V_51 - sizeof( * V_107 ) ;
while ( ( void * ) V_107 > V_81 ) {
if ( V_107 -> V_55 == 0 )
GOTO ( V_11 , V_23 = 0 ) ;
if ( F_40 ( V_20 , V_22 -> V_29 ) ) {
V_64 = ( void * ) V_107 - V_107 -> V_53 +
sizeof( * V_107 ) ;
V_23 = V_102 ( V_19 , V_2 , V_64 , V_65 ) ;
if ( V_23 == V_97 ) {
GOTO ( V_11 , V_23 ) ;
} else if ( V_23 == V_98 ) {
F_18 ( V_19 , V_2 ,
V_107 -> V_55 ) ;
V_23 = 0 ;
}
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
}
-- V_20 ;
if ( V_20 < V_105 )
GOTO ( V_11 , V_23 = 0 ) ;
V_107 = ( void * ) V_107 - V_107 -> V_53 ;
}
}
V_11:
if ( V_81 )
F_11 ( V_81 , V_17 ) ;
return V_23 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
int V_23 ;
V_23 = F_29 ( V_2 , & V_45 ) ;
if ( V_23 )
return V_23 ;
if ( V_45 -> V_108 == NULL )
return - V_47 ;
V_23 = V_45 -> V_108 ( V_2 ) ;
return V_23 ;
}
int F_61 ( const struct V_18 * V_19 ,
struct V_1 * V_2 , struct V_109 * V_110 )
{
struct V_44 * V_45 ;
int V_111 , V_23 ;
V_23 = F_29 ( V_2 , & V_45 ) ;
if ( V_23 )
return V_23 ;
if ( V_45 -> V_112 == NULL )
return - V_47 ;
V_111 = F_62 ( V_113 ) ;
if ( ! V_111 )
F_63 ( V_113 ) ;
V_23 = V_45 -> V_112 ( V_19 , V_2 , V_110 ) ;
if ( ! V_111 )
F_64 ( V_113 ) ;
return V_23 ;
}
int F_65 ( const struct V_18 * V_19 , struct V_1 * V_41 ,
struct V_109 * V_110 )
{
struct V_44 * V_45 ;
int V_111 , V_23 ;
V_23 = F_29 ( V_41 , & V_45 ) ;
if ( V_23 )
return V_23 ;
if ( V_45 -> V_114 == NULL )
return - V_47 ;
V_111 = F_62 ( V_113 ) ;
if ( ! V_111 )
F_63 ( V_113 ) ;
V_23 = V_45 -> V_114 ( V_19 , V_41 , V_110 ) ;
if ( ! V_111 )
F_64 ( V_113 ) ;
return V_23 ;
}
int F_66 ( const struct V_18 * V_19 ,
struct V_1 * V_41 ,
struct V_63 * V_64 , int V_106 ,
struct V_109 * V_110 )
{
struct V_44 * V_45 ;
int V_111 , V_23 ;
V_23 = F_29 ( V_41 , & V_45 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_45 ) ;
if ( V_45 -> V_115 == NULL )
return - V_47 ;
V_111 = F_62 ( V_113 ) ;
if ( ! V_111 )
F_63 ( V_113 ) ;
V_23 = V_45 -> V_115 ( V_19 , V_41 , V_64 , V_106 , V_110 ) ;
if ( ! V_111 )
F_64 ( V_113 ) ;
return V_23 ;
}
int F_67 ( const struct V_18 * V_19 , struct V_1 * V_41 ,
struct V_63 * V_64 , struct V_116 * V_117 ,
int V_118 , void * V_81 , int V_106 , struct V_109 * V_110 )
{
struct V_44 * V_45 ;
int V_111 , V_23 , V_119 ;
V_23 = F_29 ( V_41 , & V_45 ) ;
if ( V_23 )
return V_23 ;
F_9 ( V_45 ) ;
if ( V_45 -> V_120 == NULL )
return - V_47 ;
if ( V_81 )
V_119 = V_64 -> V_51 + sizeof( struct V_63 ) +
sizeof( struct V_71 ) ;
else
V_119 = V_64 -> V_51 ;
F_9 ( F_68 ( V_119 ) == V_119 ) ;
V_111 = F_62 ( V_113 ) ;
if ( ! V_111 )
F_63 ( V_113 ) ;
V_23 = V_45 -> V_120 ( V_19 , V_41 , V_64 , V_117 , V_118 ,
V_81 , V_106 , V_110 ) ;
if ( ! V_111 )
F_64 ( V_113 ) ;
return V_23 ;
}
int F_69 ( const struct V_18 * V_19 , struct V_1 * V_121 ,
struct V_63 * V_64 , struct V_116 * V_117 ,
void * V_81 , struct V_109 * V_110 )
{
int V_111 , V_23 ;
if ( V_121 -> V_122 -> V_123 == NULL )
return - V_47 ;
V_111 = F_62 ( V_113 ) ;
if ( ! V_111 )
F_63 ( V_113 ) ;
V_23 = V_121 -> V_122 -> V_123 ( V_19 , V_121 , V_64 , V_117 , V_81 , V_110 ) ;
if ( ! V_111 )
F_64 ( V_113 ) ;
return V_23 ;
}
int F_70 ( const struct V_18 * V_19 , struct V_1 * V_121 ,
struct V_63 * V_64 , struct V_109 * V_110 )
{
int V_111 , V_23 ;
if ( V_121 -> V_122 -> V_124 == NULL )
return - V_47 ;
V_111 = F_62 ( V_113 ) ;
if ( ! V_111 )
F_63 ( V_113 ) ;
V_23 = V_121 -> V_122 -> V_124 ( V_19 , V_121 , V_64 , V_110 ) ;
if ( ! V_111 )
F_64 ( V_113 ) ;
return V_23 ;
}
int F_71 ( const struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_1 * * V_127 , struct V_128 * V_129 ,
char * V_130 )
{
struct V_109 * V_110 ;
int V_23 ;
V_23 = F_72 ( V_19 , V_126 , V_127 , V_129 , V_130 , V_131 ) ;
if ( V_23 )
return V_23 ;
if ( F_60 ( * V_127 ) )
return 0 ;
if ( ( * V_127 ) -> V_132 != NULL ) {
struct V_133 * V_134 ;
V_134 = F_73 ( ( * V_127 ) -> V_132 -> V_135 . V_136 ) ;
V_110 = F_74 ( V_19 , V_134 ) ;
if ( F_75 ( V_110 ) )
GOTO ( V_11 , V_23 = F_52 ( V_110 ) ) ;
V_23 = F_61 ( V_19 , * V_127 , V_110 ) ;
if ( V_23 == 0 ) {
V_23 = F_76 ( V_19 , V_134 , V_110 ) ;
if ( V_23 == 0 )
V_23 = F_65 ( V_19 , * V_127 , V_110 ) ;
}
F_77 ( V_19 , V_134 , V_110 ) ;
} else {
F_9 ( ( * V_127 ) -> V_137 == NULL ) ;
V_23 = F_65 ( V_19 , * V_127 , NULL ) ;
}
V_11:
if ( V_23 )
F_78 ( V_19 , * V_127 ) ;
return V_23 ;
}
int F_79 ( const struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_128 * V_129 , char * V_130 )
{
struct V_1 * V_41 ;
int V_23 = 0 , V_138 ;
if ( V_130 == NULL && V_129 == NULL )
return 0 ;
V_23 = F_72 ( V_19 , V_126 , & V_41 , V_129 , V_130 , V_139 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_33 ( V_19 , V_41 , V_13 , NULL ) ;
if ( V_23 == 0 )
V_23 = F_25 ( V_19 , V_41 ) ;
V_138 = F_78 ( V_19 , V_41 ) ;
if ( V_23 == 0 )
V_23 = V_138 ;
return V_23 ;
}
int F_26 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_63 * V_64 , struct V_116 * V_140 ,
int V_141 , void * V_81 , int V_106 )
{
int V_23 ;
F_9 ( V_2 ) ;
F_9 ( V_2 -> V_35 ) ;
if ( V_2 -> V_132 != NULL ) {
struct V_133 * V_142 ;
struct V_109 * V_110 ;
V_142 = F_73 ( V_2 -> V_132 -> V_135 . V_136 ) ;
V_110 = F_74 ( V_19 , V_142 ) ;
if ( F_75 ( V_110 ) )
return F_52 ( V_110 ) ;
V_23 = F_66 ( V_19 , V_2 , V_64 , V_106 , V_110 ) ;
if ( V_23 )
GOTO ( V_143 , V_23 ) ;
V_23 = F_76 ( V_19 , V_142 , V_110 ) ;
if ( V_23 )
GOTO ( V_143 , V_23 ) ;
F_80 ( & V_2 -> V_4 ) ;
V_23 = F_67 ( V_19 , V_2 , V_64 , V_140 ,
V_141 , V_81 , V_106 , V_110 ) ;
F_81 ( & V_2 -> V_4 ) ;
V_143:
F_77 ( V_19 , V_142 , V_110 ) ;
} else {
F_80 ( & V_2 -> V_4 ) ;
V_23 = F_67 ( V_19 , V_2 , V_64 , V_140 ,
V_141 , V_81 , V_106 , NULL ) ;
F_81 ( & V_2 -> V_4 ) ;
}
return V_23 ;
}
int F_72 ( const struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_1 * * V_121 , struct V_128 * V_129 ,
char * V_130 , enum V_144 V_145 )
{
int V_111 ;
int V_23 ;
F_9 ( V_126 ) ;
F_9 ( V_126 -> V_146 ) ;
if ( V_126 -> V_146 -> V_147 == NULL ) {
* V_121 = NULL ;
return - V_47 ;
}
* V_121 = F_1 () ;
if ( * V_121 == NULL )
return - V_3 ;
( * V_121 ) -> V_35 = V_126 ;
( * V_121 ) -> V_122 = V_126 -> V_146 ;
V_111 = F_62 ( V_113 ) ;
if ( ! V_111 )
F_63 ( V_113 ) ;
V_23 = V_126 -> V_146 -> V_147 ( V_19 , * V_121 , V_129 , V_130 , V_145 ) ;
if ( ! V_111 )
F_64 ( V_113 ) ;
if ( V_23 ) {
F_8 ( * V_121 ) ;
* V_121 = NULL ;
}
return V_23 ;
}
int F_78 ( const struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_44 * V_45 ;
int V_23 ;
V_23 = F_29 ( V_2 , & V_45 ) ;
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
if ( V_45 -> V_148 == NULL )
GOTO ( V_11 , V_23 = - V_47 ) ;
V_23 = V_45 -> V_148 ( V_19 , V_2 ) ;
V_11:
F_15 ( V_2 ) ;
return V_23 ;
}
