struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( V_2 ) ;
if ( V_2 == NULL )
return NULL ;
F_3 ( & V_2 -> V_3 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_5 ( & V_2 -> V_5 . V_6 . V_7 ) ;
F_6 ( & V_2 -> V_8 , 1 ) ;
return V_2 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 != NULL ) ;
if ( ! V_2 -> V_9 )
goto V_10;
if ( V_2 -> V_9 -> V_11 & V_12 )
F_8 ( F_9 ( & V_2 -> V_5 . V_6 . V_7 ) ) ;
else if ( V_2 -> V_9 -> V_11 & V_13 )
F_8 ( F_9 ( & V_2 -> V_5 . V_14 . V_15 ) ) ;
F_8 ( sizeof( * ( V_2 -> V_9 ) ) == V_16 ) ;
F_10 ( V_2 -> V_9 , V_16 ) ;
V_10:
F_11 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_8 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_8 ( F_15 ( & V_2 -> V_8 ) > 0 ) ;
if ( F_16 ( & V_2 -> V_8 ) )
F_7 ( V_2 ) ;
}
int F_17 ( const struct V_17 * V_18 , struct V_1 * V_2 ,
int V_19 )
{
struct V_20 * V_21 = V_2 -> V_9 ;
int V_22 = 0 ;
F_18 ( V_23 , L_1 V_24 L_2 ,
V_19 , F_19 ( & V_2 -> V_25 . V_26 ) ) ;
if ( V_19 == 0 ) {
F_20 ( L_3 ) ;
return - V_27 ;
}
F_21 ( & V_2 -> V_4 ) ;
if ( ! F_22 ( V_19 , V_21 -> V_28 ) ) {
F_23 ( & V_2 -> V_4 ) ;
F_18 ( V_23 , L_4 , V_19 ) ;
return - V_29 ;
}
V_21 -> V_30 -- ;
if ( ( V_21 -> V_11 & V_31 ) &&
( V_21 -> V_30 == 1 ) &&
( V_2 -> V_32 == ( V_33 * 8 ) - 1 ) ) {
F_23 ( & V_2 -> V_4 ) ;
V_22 = F_24 ( V_18 , V_2 ) ;
if ( V_22 < 0 ) {
F_20 ( L_5 V_24
L_6 ,
V_2 -> V_34 -> V_35 -> V_36 ,
F_19 ( & V_2 -> V_25 . V_26 ) ,
V_2 -> V_25 . V_37 , V_22 ) ;
GOTO ( V_38 , V_22 ) ;
}
return 1 ;
}
F_23 ( & V_2 -> V_4 ) ;
V_22 = F_25 ( V_18 , V_2 , & V_21 -> V_39 , NULL , 0 , NULL , 0 ) ;
if ( V_22 < 0 ) {
F_20 ( L_7 V_24
L_6 ,
V_2 -> V_34 -> V_35 -> V_36 ,
F_19 ( & V_2 -> V_25 . V_26 ) ,
V_2 -> V_25 . V_37 , V_22 ) ;
GOTO ( V_38 , V_22 ) ;
}
return 0 ;
V_38:
F_21 ( & V_2 -> V_4 ) ;
F_26 ( V_19 , V_21 -> V_28 ) ;
V_21 -> V_30 ++ ;
F_23 ( & V_2 -> V_4 ) ;
return V_22 ;
}
static int F_27 ( const struct V_17 * V_18 ,
struct V_1 * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 ;
int V_22 ;
V_22 = F_28 ( V_40 , & V_44 ) ;
if ( V_22 )
return V_22 ;
if ( V_44 -> V_45 == NULL )
return - V_46 ;
V_22 = V_44 -> V_45 ( V_18 , V_40 ) ;
if ( V_22 == V_47 ) {
struct V_20 * V_21 = V_40 -> V_9 ;
V_40 -> V_32 = 0 ;
V_21 -> V_30 = 1 ;
V_21 -> V_39 . V_48 = V_49 ;
V_21 -> V_39 . V_50 = V_21 -> V_51 . V_52 = V_16 ;
V_21 -> V_39 . V_53 = V_21 -> V_51 . V_54 = 0 ;
V_21 -> V_55 = F_29 () ;
if ( V_42 )
memcpy ( & V_21 -> V_56 , V_42 ,
sizeof( V_21 -> V_56 ) ) ;
V_21 -> V_57 = F_30 ( F_31 ( * V_21 ) , V_28 ) ;
F_26 ( 0 , V_21 -> V_28 ) ;
V_22 = 0 ;
}
return V_22 ;
}
int F_32 ( const struct V_17 * V_18 , struct V_1 * V_40 ,
int V_58 , struct V_41 * V_42 )
{
struct V_20 * V_21 ;
int V_22 ;
F_8 ( V_40 -> V_9 == NULL ) ;
F_2 ( V_21 ) ;
if ( V_21 == NULL )
return - V_59 ;
V_40 -> V_9 = V_21 ;
V_21 -> V_11 = V_58 ;
V_22 = F_27 ( V_18 , V_40 , V_42 ) ;
if ( V_22 == 0 ) {
if ( F_33 ( ( V_21 -> V_11 & V_12 &&
V_58 & V_13 ) ||
( V_21 -> V_11 & V_13 &&
V_58 & V_12 ) ) ) {
F_20 ( L_8 ,
V_40 -> V_34 -> V_35 -> V_36 ,
V_21 -> V_11 & V_13 ?
L_9 : L_10 ,
V_58 & V_13 ? L_9 : L_10 ) ;
GOTO ( V_10 , V_22 = - V_27 ) ;
} else if ( V_21 -> V_11 &
( V_12 | V_13 ) ) {
V_58 = V_21 -> V_11 ;
} else {
F_20 ( L_11 ) ;
GOTO ( V_10 , V_22 = - V_27 ) ;
}
if ( F_33 ( V_42 &&
! F_34 ( V_42 , & V_21 -> V_56 ) ) ) {
F_20 ( L_12 ,
V_40 -> V_34 -> V_35 -> V_36 ,
( char * ) V_42 -> V_42 ,
( char * ) V_21 -> V_56 . V_42 ) ;
GOTO ( V_10 , V_22 = - V_60 ) ;
}
}
if ( V_58 & V_13 ) {
F_8 ( F_9 ( & V_40 -> V_5 . V_14 . V_15 ) ) ;
F_5 ( & V_40 -> V_5 . V_14 . V_15 ) ;
V_21 -> V_61 = sizeof( struct V_62 ) ;
} else if ( ! ( V_58 & V_12 ) ) {
F_20 ( L_13 ,
V_40 -> V_34 -> V_35 -> V_36 ,
V_58 , V_13 , V_12 ) ;
V_22 = - V_27 ;
}
V_10:
if ( V_22 ) {
F_11 ( V_21 ) ;
V_40 -> V_9 = NULL ;
}
return V_22 ;
}
static int F_35 ( void * V_63 )
{
struct V_64 * V_65 = V_63 ;
struct V_1 * V_2 = V_65 -> V_66 ;
struct V_20 * V_21 = V_2 -> V_9 ;
struct V_67 * V_68 = V_65 -> V_69 ;
char * V_70 ;
T_1 V_71 = V_16 ;
T_1 V_72 ;
int V_22 = 0 , V_19 = 1 , V_73 ;
int V_74 = 0 ;
int V_75 = 0 ;
F_8 ( V_21 ) ;
F_36 ( V_70 , V_16 ) ;
if ( ! V_70 ) {
V_65 -> V_76 = - V_59 ;
return 0 ;
}
if ( V_68 != NULL ) {
V_75 = V_68 -> V_77 ;
V_19 = V_68 -> V_77 + 1 ;
}
if ( V_68 != NULL && V_68 -> V_78 )
V_73 = V_68 -> V_78 ;
else
V_73 = V_33 * 8 - 1 ;
while ( V_22 == 0 ) {
struct V_79 * V_80 ;
while ( V_19 <= V_73 &&
! F_37 ( V_19 , V_21 -> V_28 ) )
++ V_19 ;
F_8 ( V_19 <= V_73 + 1 ) ;
if ( V_19 == V_73 + 1 )
break;
V_81:
F_18 ( V_82 , L_14 ,
V_19 , V_73 ) ;
memset ( V_70 , 0 , V_16 ) ;
V_72 = V_71 ;
V_22 = F_38 ( V_65 -> V_83 , V_2 , & V_74 ,
V_19 , & V_71 , V_70 , V_16 ) ;
if ( V_22 )
GOTO ( V_10 , V_22 ) ;
for ( V_80 = (struct V_79 * ) V_70 ;
( char * ) V_80 < V_70 + V_16 ;
V_80 = (struct V_79 * ) ( ( char * ) V_80 + V_80 -> V_50 ) ) {
F_18 ( V_82 , L_15 ,
V_80 , V_80 -> V_48 ) ;
if ( F_39 ( V_80 ) )
F_40 ( V_80 ) ;
F_18 ( V_82 , L_16 ,
V_80 -> V_48 , V_80 -> V_53 ) ;
if ( V_80 -> V_53 == 0 ) {
if ( V_19 <= V_2 -> V_32 )
GOTO ( V_81 , V_22 = 0 ) ;
GOTO ( V_10 , V_22 = 0 ) ;
}
if ( V_80 -> V_50 == 0 ||
V_80 -> V_50 > V_16 ) {
F_41 ( L_17
L_18 , V_80 -> V_50 ,
V_80 -> V_53 , V_19 ) ;
GOTO ( V_10 , V_22 = - V_27 ) ;
}
if ( V_80 -> V_53 < V_19 ) {
F_18 ( V_82 , L_19 ,
V_80 -> V_53 ) ;
continue;
}
F_18 ( V_82 ,
L_20 ,
V_80 -> V_53 , V_80 -> V_50 ,
( int ) ( V_70 + V_16 - ( char * ) V_80 ) ) ;
V_2 -> V_84 = V_80 -> V_53 ;
V_2 -> V_85 = ( char * ) V_80 - ( char * ) V_70 +
V_72 ;
if ( F_37 ( V_19 , V_21 -> V_28 ) ) {
V_22 = V_65 -> V_86 ( V_65 -> V_83 , V_2 , V_80 ,
V_65 -> V_87 ) ;
V_75 = V_19 ;
if ( V_22 == V_88 ) {
GOTO ( V_10 , V_22 ) ;
} else if ( V_22 == V_89 ) {
F_17 ( V_65 -> V_83 ,
V_2 ,
V_80 -> V_53 ) ;
V_22 = 0 ;
}
if ( V_22 )
GOTO ( V_10 , V_22 ) ;
} else {
F_18 ( V_82 , L_21 , V_19 ) ;
}
++ V_19 ;
if ( V_19 > V_73 )
GOTO ( V_10 , V_22 = 0 ) ;
}
}
V_10:
if ( V_68 != NULL )
V_68 -> V_78 = V_75 ;
F_10 ( V_70 , V_16 ) ;
V_65 -> V_76 = V_22 ;
return 0 ;
}
static int F_42 ( void * V_63 )
{
struct V_64 * V_65 = V_63 ;
struct V_17 V_18 ;
int V_22 ;
F_43 () ;
V_22 = F_44 ( & V_18 , V_90 | V_91 ) ;
if ( V_22 )
goto V_10;
V_65 -> V_83 = & V_18 ;
V_22 = F_35 ( V_63 ) ;
F_45 ( & V_18 ) ;
V_10:
F_46 ( & V_65 -> V_92 ) ;
return V_22 ;
}
int F_47 ( const struct V_17 * V_18 ,
struct V_1 * V_2 ,
T_2 V_93 , void * V_94 , void * V_95 , bool V_96 )
{
struct V_64 * V_65 ;
int V_22 ;
F_2 ( V_65 ) ;
if ( V_65 == NULL ) {
F_20 ( L_22 ) ;
return - V_59 ;
}
V_65 -> V_66 = V_2 ;
V_65 -> V_86 = V_93 ;
V_65 -> V_87 = V_94 ;
V_65 -> V_69 = V_95 ;
if ( V_96 ) {
V_65 -> V_83 = NULL ;
F_48 ( & V_65 -> V_92 ) ;
V_22 = F_49 ( F_50 ( F_42 , V_65 ,
L_23 ) ) ;
if ( F_51 ( V_22 ) ) {
F_20 ( L_24 ,
V_2 -> V_34 -> V_35 -> V_36 , V_22 ) ;
F_11 ( V_65 ) ;
return V_22 ;
}
F_52 ( & V_65 -> V_92 ) ;
} else {
V_65 -> V_83 = V_18 ;
F_35 ( V_65 ) ;
}
V_22 = V_65 -> V_76 ;
F_11 ( V_65 ) ;
return V_22 ;
}
int F_53 ( const struct V_17 * V_18 , struct V_1 * V_2 ,
T_2 V_93 , void * V_94 , void * V_95 )
{
return F_47 ( V_18 , V_2 , V_93 , V_94 , V_95 , true ) ;
}
int F_54 ( const struct V_17 * V_18 ,
struct V_1 * V_2 , T_2 V_93 ,
void * V_94 , void * V_95 )
{
struct V_20 * V_21 = V_2 -> V_9 ;
struct V_67 * V_68 = V_95 ;
void * V_70 ;
int V_22 = 0 , V_97 = 1 , V_19 , V_98 ;
F_36 ( V_70 , V_16 ) ;
if ( ! V_70 )
return - V_59 ;
if ( V_68 != NULL )
V_97 = V_68 -> V_77 + 1 ;
if ( V_68 != NULL && V_68 -> V_78 )
V_19 = V_68 -> V_78 ;
else
V_19 = V_33 * 8 - 1 ;
while ( V_22 == 0 ) {
struct V_79 * V_80 ;
struct V_99 * V_100 ;
while ( V_19 >= V_97 &&
! F_37 ( V_19 , V_21 -> V_28 ) )
-- V_19 ;
F_8 ( V_19 >= V_97 - 1 ) ;
if ( V_19 == V_97 - 1 )
break;
memset ( V_70 , 0 , V_16 ) ;
V_22 = F_55 ( V_18 , V_2 , V_19 , V_70 ,
V_16 ) ;
if ( V_22 )
GOTO ( V_10 , V_22 ) ;
V_80 = V_70 ;
V_98 = V_80 -> V_53 ;
F_18 ( V_23 , L_25 , V_19 , V_98 ) ;
while ( V_98 < V_19 ) {
V_80 = ( void * ) V_80 + V_80 -> V_50 ;
if ( F_39 ( V_80 ) )
F_40 ( V_80 ) ;
V_98 ++ ;
}
F_8 ( V_98 == V_19 ) ;
V_100 = ( void * ) V_80 + V_80 -> V_50 - sizeof( * V_100 ) ;
while ( ( void * ) V_100 > V_70 ) {
if ( V_100 -> V_54 == 0 )
GOTO ( V_10 , V_22 = 0 ) ;
if ( F_37 ( V_19 , V_21 -> V_28 ) ) {
V_80 = ( void * ) V_100 - V_100 -> V_52 +
sizeof( * V_100 ) ;
V_22 = V_93 ( V_18 , V_2 , V_80 , V_94 ) ;
if ( V_22 == V_88 ) {
GOTO ( V_10 , V_22 ) ;
} else if ( V_22 == V_89 ) {
F_17 ( V_18 , V_2 ,
V_100 -> V_54 ) ;
V_22 = 0 ;
}
if ( V_22 )
GOTO ( V_10 , V_22 ) ;
}
-- V_19 ;
if ( V_19 < V_97 )
GOTO ( V_10 , V_22 = 0 ) ;
V_100 = ( void * ) V_100 - V_100 -> V_52 ;
}
}
V_10:
if ( V_70 )
F_10 ( V_70 , V_16 ) ;
return V_22 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
int V_22 ;
V_22 = F_28 ( V_2 , & V_44 ) ;
if ( V_22 )
return V_22 ;
if ( V_44 -> V_101 == NULL )
return - V_46 ;
V_22 = V_44 -> V_101 ( V_2 ) ;
return V_22 ;
}
int F_57 ( const struct V_17 * V_18 ,
struct V_1 * V_2 , struct V_102 * V_103 )
{
struct V_43 * V_44 ;
int V_104 , V_22 ;
V_22 = F_28 ( V_2 , & V_44 ) ;
if ( V_22 )
return V_22 ;
if ( V_44 -> V_105 == NULL )
return - V_46 ;
V_104 = F_58 ( V_106 ) ;
if ( ! V_104 )
F_59 ( V_106 ) ;
V_22 = V_44 -> V_105 ( V_18 , V_2 , V_103 ) ;
if ( ! V_104 )
F_60 ( V_106 ) ;
return V_22 ;
}
int F_61 ( const struct V_17 * V_18 , struct V_1 * V_40 ,
struct V_102 * V_103 )
{
struct V_43 * V_44 ;
int V_104 , V_22 ;
V_22 = F_28 ( V_40 , & V_44 ) ;
if ( V_22 )
return V_22 ;
if ( V_44 -> V_107 == NULL )
return - V_46 ;
V_104 = F_58 ( V_106 ) ;
if ( ! V_104 )
F_59 ( V_106 ) ;
V_22 = V_44 -> V_107 ( V_18 , V_40 , V_103 ) ;
if ( ! V_104 )
F_60 ( V_106 ) ;
return V_22 ;
}
int F_62 ( const struct V_17 * V_18 ,
struct V_1 * V_40 ,
struct V_79 * V_80 , int V_98 ,
struct V_102 * V_103 )
{
struct V_43 * V_44 ;
int V_104 , V_22 ;
V_22 = F_28 ( V_40 , & V_44 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_44 ) ;
if ( V_44 -> V_108 == NULL )
return - V_46 ;
V_104 = F_58 ( V_106 ) ;
if ( ! V_104 )
F_59 ( V_106 ) ;
V_22 = V_44 -> V_108 ( V_18 , V_40 , V_80 , V_98 , V_103 ) ;
if ( ! V_104 )
F_60 ( V_106 ) ;
return V_22 ;
}
int F_63 ( const struct V_17 * V_18 , struct V_1 * V_40 ,
struct V_79 * V_80 , struct V_109 * V_110 ,
int V_111 , void * V_70 , int V_98 , struct V_102 * V_103 )
{
struct V_43 * V_44 ;
int V_104 , V_22 , V_112 ;
V_22 = F_28 ( V_40 , & V_44 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_44 ) ;
if ( V_44 -> V_113 == NULL )
return - V_46 ;
if ( V_70 )
V_112 = V_80 -> V_50 + sizeof( struct V_79 ) +
sizeof( struct V_99 ) ;
else
V_112 = V_80 -> V_50 ;
F_8 ( F_64 ( V_112 ) == V_112 ) ;
V_104 = F_58 ( V_106 ) ;
if ( ! V_104 )
F_59 ( V_106 ) ;
V_22 = V_44 -> V_113 ( V_18 , V_40 , V_80 , V_110 , V_111 ,
V_70 , V_98 , V_103 ) ;
if ( ! V_104 )
F_60 ( V_106 ) ;
return V_22 ;
}
int F_65 ( const struct V_17 * V_18 , struct V_1 * V_114 ,
struct V_79 * V_80 , struct V_109 * V_110 ,
void * V_70 , struct V_102 * V_103 )
{
int V_104 , V_22 ;
if ( V_114 -> V_115 -> V_116 == NULL )
return - V_46 ;
V_104 = F_58 ( V_106 ) ;
if ( ! V_104 )
F_59 ( V_106 ) ;
V_22 = V_114 -> V_115 -> V_116 ( V_18 , V_114 , V_80 , V_110 , V_70 , V_103 ) ;
if ( ! V_104 )
F_60 ( V_106 ) ;
return V_22 ;
}
int F_66 ( const struct V_17 * V_18 , struct V_1 * V_114 ,
struct V_79 * V_80 , struct V_102 * V_103 )
{
int V_104 , V_22 ;
if ( V_114 -> V_115 -> V_117 == NULL )
return - V_46 ;
V_104 = F_58 ( V_106 ) ;
if ( ! V_104 )
F_59 ( V_106 ) ;
V_22 = V_114 -> V_115 -> V_117 ( V_18 , V_114 , V_80 , V_103 ) ;
if ( ! V_104 )
F_60 ( V_106 ) ;
return V_22 ;
}
int F_67 ( const struct V_17 * V_18 , struct V_118 * V_119 ,
struct V_1 * * V_120 , struct V_121 * V_122 ,
char * V_123 )
{
struct V_124 * V_125 ;
struct V_102 * V_103 ;
int V_22 ;
V_22 = F_68 ( V_18 , V_119 , V_120 , V_122 , V_123 , V_126 ) ;
if ( V_22 )
return V_22 ;
if ( F_56 ( * V_120 ) )
return 0 ;
F_8 ( ( * V_120 ) -> V_127 != NULL ) ;
V_125 = F_69 ( ( * V_120 ) -> V_127 -> V_128 . V_129 ) ;
V_103 = F_70 ( V_18 , V_125 ) ;
if ( F_71 ( V_103 ) )
GOTO ( V_10 , V_22 = F_49 ( V_103 ) ) ;
V_22 = F_57 ( V_18 , * V_120 , V_103 ) ;
if ( V_22 == 0 ) {
V_22 = F_72 ( V_18 , V_125 , V_103 ) ;
if ( V_22 == 0 )
V_22 = F_61 ( V_18 , * V_120 , V_103 ) ;
}
F_73 ( V_18 , V_125 , V_103 ) ;
V_10:
if ( V_22 )
F_74 ( V_18 , * V_120 ) ;
return V_22 ;
}
int F_75 ( const struct V_17 * V_18 , struct V_118 * V_119 ,
struct V_121 * V_122 , char * V_123 )
{
struct V_1 * V_40 ;
int V_22 = 0 , V_130 ;
if ( V_123 == NULL && V_122 == NULL )
return 0 ;
V_22 = F_68 ( V_18 , V_119 , & V_40 , V_122 , V_123 , V_131 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_32 ( V_18 , V_40 , V_12 , NULL ) ;
if ( V_22 == 0 )
V_22 = F_24 ( V_18 , V_40 ) ;
V_130 = F_74 ( V_18 , V_40 ) ;
if ( V_22 == 0 )
V_22 = V_130 ;
return V_22 ;
}
int F_25 ( const struct V_17 * V_18 , struct V_1 * V_2 ,
struct V_79 * V_80 , struct V_109 * V_132 ,
int V_133 , void * V_70 , int V_98 )
{
struct V_124 * V_134 ;
struct V_102 * V_103 ;
int V_22 ;
F_8 ( V_2 ) ;
F_8 ( V_2 -> V_34 ) ;
F_8 ( V_2 -> V_127 != NULL ) ;
V_134 = F_69 ( V_2 -> V_127 -> V_128 . V_129 ) ;
V_103 = F_70 ( V_18 , V_134 ) ;
if ( F_71 ( V_103 ) )
return F_49 ( V_103 ) ;
V_22 = F_62 ( V_18 , V_2 , V_80 , V_98 , V_103 ) ;
if ( V_22 )
GOTO ( V_135 , V_22 ) ;
V_22 = F_72 ( V_18 , V_134 , V_103 ) ;
if ( V_22 )
GOTO ( V_135 , V_22 ) ;
F_76 ( & V_2 -> V_3 ) ;
V_22 = F_63 ( V_18 , V_2 , V_80 , V_132 ,
V_133 , V_70 , V_98 , V_103 ) ;
F_77 ( & V_2 -> V_3 ) ;
V_135:
F_73 ( V_18 , V_134 , V_103 ) ;
return V_22 ;
}
int F_68 ( const struct V_17 * V_18 , struct V_118 * V_119 ,
struct V_1 * * V_114 , struct V_121 * V_122 ,
char * V_123 , enum V_136 V_137 )
{
int V_104 ;
int V_22 ;
F_8 ( V_119 ) ;
F_8 ( V_119 -> V_138 ) ;
if ( V_119 -> V_138 -> V_139 == NULL ) {
* V_114 = NULL ;
return - V_46 ;
}
* V_114 = F_1 () ;
if ( * V_114 == NULL )
return - V_59 ;
( * V_114 ) -> V_34 = V_119 ;
( * V_114 ) -> V_115 = V_119 -> V_138 ;
V_104 = F_58 ( V_106 ) ;
if ( ! V_104 )
F_59 ( V_106 ) ;
V_22 = V_119 -> V_138 -> V_139 ( V_18 , * V_114 , V_122 , V_123 , V_137 ) ;
if ( ! V_104 )
F_60 ( V_106 ) ;
if ( V_22 ) {
F_7 ( * V_114 ) ;
* V_114 = NULL ;
}
return V_22 ;
}
int F_74 ( const struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_43 * V_44 ;
int V_22 ;
V_22 = F_28 ( V_2 , & V_44 ) ;
if ( V_22 )
GOTO ( V_10 , V_22 ) ;
if ( V_44 -> V_140 == NULL )
GOTO ( V_10 , V_22 = - V_46 ) ;
V_22 = V_44 -> V_140 ( V_18 , V_2 ) ;
V_10:
F_14 ( V_2 ) ;
return V_22 ;
}
int F_78 ( const struct V_17 * V_18 , struct V_118 * V_119 ,
char * V_123 )
{
struct V_1 * V_21 ;
int V_22 = 0 ;
V_22 = F_68 ( V_18 , V_119 , & V_21 , NULL , V_123 , V_131 ) ;
if ( V_22 < 0 ) {
if ( F_79 ( V_22 == - V_29 ) )
V_22 = 0 ;
GOTO ( V_10 , V_22 ) ;
}
V_22 = F_32 ( V_18 , V_21 , V_12 , NULL ) ;
if ( V_22 )
GOTO ( V_141 , V_22 ) ;
V_22 = F_80 ( V_21 ) ;
V_141:
F_74 ( V_18 , V_21 ) ;
V_10:
return V_22 <= 1 ;
}
int F_81 ( const struct V_17 * V_18 , struct V_1 * V_21 ,
struct V_79 * V_80 , void * V_94 )
{
struct V_1 * V_142 = V_94 ;
return F_25 ( V_18 , V_142 , V_80 , NULL , 0 , NULL , - 1 ) ;
}
int F_82 ( const struct V_17 * V_18 , struct V_143 * V_144 ,
struct V_118 * V_119 , struct V_118 * V_145 ,
char * V_123 , char * V_146 )
{
struct V_1 * V_21 , * V_147 ;
int V_22 ;
V_22 = F_68 ( V_18 , V_119 , & V_21 , NULL , V_123 , V_131 ) ;
if ( V_22 < 0 ) {
if ( V_22 != - V_29 )
F_20 ( L_26 ,
V_144 -> V_36 , V_123 , V_22 ) ;
return V_22 ;
}
V_22 = F_32 ( V_18 , V_21 , V_12 , NULL ) ;
if ( V_22 )
GOTO ( V_141 , V_22 ) ;
V_22 = F_75 ( V_18 , V_145 , NULL , V_146 ) ;
if ( V_22 < 0 && V_22 != - V_29 )
GOTO ( V_141 , V_22 ) ;
V_22 = F_67 ( V_18 , V_145 , & V_147 , NULL , V_146 ) ;
if ( V_22 ) {
F_20 ( L_27 ,
V_144 -> V_36 , V_146 , V_22 ) ;
GOTO ( V_141 , V_22 ) ;
}
if ( V_21 -> V_127 == V_147 -> V_127 ) {
F_20 ( L_28 ,
V_144 -> V_36 , V_123 , V_146 , V_21 -> V_127 ,
V_147 -> V_127 ) ;
GOTO ( V_148 , V_22 = - V_60 ) ;
}
V_22 = F_32 ( V_18 , V_147 , V_12 , NULL ) ;
if ( V_22 )
GOTO ( V_148 , V_22 ) ;
V_22 = F_47 ( V_18 , V_21 , F_81 , ( void * ) V_147 ,
NULL , false ) ;
if ( V_22 )
F_20 ( L_29 ,
V_144 -> V_36 , V_123 , V_22 ) ;
V_148:
F_74 ( V_18 , V_147 ) ;
V_141:
F_74 ( V_18 , V_21 ) ;
return V_22 ;
}
