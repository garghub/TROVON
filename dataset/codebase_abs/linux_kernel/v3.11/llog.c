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
V_24 ;
F_19 ( V_25 , L_1 V_26 L_2 ,
V_20 , F_20 ( & V_2 -> V_27 . V_28 ) ) ;
if ( V_20 == 0 ) {
F_21 ( L_3 ) ;
RETURN ( - V_29 ) ;
}
F_22 ( & V_2 -> V_5 ) ;
if ( ! F_23 ( V_20 , V_22 -> V_30 ) ) {
F_24 ( & V_2 -> V_5 ) ;
F_19 ( V_25 , L_4 , V_20 ) ;
RETURN ( - V_31 ) ;
}
V_22 -> V_32 -- ;
if ( ( V_22 -> V_12 & V_33 ) &&
( V_22 -> V_32 == 1 ) &&
( V_2 -> V_34 == ( V_35 * 8 ) - 1 ) ) {
F_24 ( & V_2 -> V_5 ) ;
V_23 = F_25 ( V_19 , V_2 ) ;
if ( V_23 < 0 ) {
F_21 ( L_5 V_26
L_6 ,
V_2 -> V_36 -> V_37 -> V_38 ,
F_20 ( & V_2 -> V_27 . V_28 ) ,
V_2 -> V_27 . V_39 , V_23 ) ;
GOTO ( V_40 , V_23 ) ;
}
RETURN ( 1 ) ;
}
F_24 ( & V_2 -> V_5 ) ;
V_23 = F_26 ( V_19 , V_2 , & V_22 -> V_41 , NULL , 0 , NULL , 0 ) ;
if ( V_23 < 0 ) {
F_21 ( L_7 V_26
L_6 ,
V_2 -> V_36 -> V_37 -> V_38 ,
F_20 ( & V_2 -> V_27 . V_28 ) ,
V_2 -> V_27 . V_39 , V_23 ) ;
GOTO ( V_40 , V_23 ) ;
}
RETURN ( 0 ) ;
V_40:
F_22 ( & V_2 -> V_5 ) ;
F_27 ( V_20 , V_22 -> V_30 ) ;
V_22 -> V_32 ++ ;
F_24 ( & V_2 -> V_5 ) ;
return V_23 ;
}
static int F_28 ( const struct V_18 * V_19 ,
struct V_1 * V_42 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 ;
int V_23 ;
V_23 = F_29 ( V_42 , & V_46 ) ;
if ( V_23 )
RETURN ( V_23 ) ;
if ( V_46 -> V_47 == NULL )
RETURN ( - V_48 ) ;
V_23 = V_46 -> V_47 ( V_19 , V_42 ) ;
if ( V_23 == V_49 ) {
struct V_21 * V_22 = V_42 -> V_10 ;
V_42 -> V_34 = 0 ;
V_22 -> V_32 = 1 ;
V_22 -> V_41 . V_50 = V_51 ;
V_22 -> V_41 . V_52 = V_22 -> V_53 . V_54 = V_17 ;
V_22 -> V_41 . V_55 = V_22 -> V_53 . V_56 = 0 ;
V_22 -> V_57 = F_30 () ;
if ( V_44 )
memcpy ( & V_22 -> V_58 , V_44 ,
sizeof( V_22 -> V_58 ) ) ;
V_22 -> V_59 = F_31 ( F_32 ( * V_22 ) , V_30 ) ;
F_27 ( 0 , V_22 -> V_30 ) ;
V_23 = 0 ;
}
return V_23 ;
}
int F_33 ( const struct V_18 * V_19 , struct V_1 * V_42 ,
int V_60 , struct V_43 * V_44 )
{
struct V_21 * V_22 ;
int V_23 ;
V_24 ;
F_9 ( V_42 -> V_10 == NULL ) ;
F_2 ( V_22 ) ;
if ( V_22 == NULL )
RETURN ( - V_3 ) ;
V_42 -> V_10 = V_22 ;
V_22 -> V_12 = V_60 ;
V_23 = F_28 ( V_19 , V_42 , V_44 ) ;
if ( V_23 == 0 ) {
if ( F_34 ( ( V_22 -> V_12 & V_13 &&
V_60 & V_14 ) ||
( V_22 -> V_12 & V_14 &&
V_60 & V_13 ) ) ) {
F_21 ( L_8 ,
V_42 -> V_36 -> V_37 -> V_38 ,
V_22 -> V_12 & V_14 ?
L_9 : L_10 ,
V_60 & V_14 ? L_9 : L_10 ) ;
GOTO ( V_11 , V_23 = - V_29 ) ;
} else if ( V_22 -> V_12 &
( V_13 | V_14 ) ) {
V_60 = V_22 -> V_12 ;
} else {
F_21 ( L_11 ) ;
GOTO ( V_11 , V_23 = - V_29 ) ;
}
if ( F_34 ( V_44 &&
! F_35 ( V_44 , & V_22 -> V_58 ) ) ) {
F_21 ( L_12 ,
V_42 -> V_36 -> V_37 -> V_38 ,
( char * ) V_44 -> V_44 ,
( char * ) V_22 -> V_58 . V_44 ) ;
GOTO ( V_11 , V_23 = - V_61 ) ;
}
}
if ( V_60 & V_14 ) {
F_9 ( F_10 ( & V_42 -> V_6 . V_15 . V_16 ) ) ;
F_6 ( & V_42 -> V_6 . V_15 . V_16 ) ;
V_22 -> V_62 = sizeof( struct V_63 ) ;
} else if ( ! ( V_60 & V_13 ) ) {
F_21 ( L_13 ,
V_42 -> V_36 -> V_37 -> V_38 ,
V_60 , V_14 , V_13 ) ;
V_23 = - V_29 ;
}
V_11:
if ( V_23 ) {
F_12 ( V_22 ) ;
V_42 -> V_10 = NULL ;
}
RETURN ( V_23 ) ;
}
int F_36 ( const struct V_18 * V_19 ,
struct V_1 * V_22 ,
struct V_64 * V_65 ,
void * V_66 )
{
struct V_64 V_67 = * V_65 ;
struct V_1 * V_68 = (struct V_1 * ) V_66 ;
char * V_69 = ( char * ) ( V_65 + 1 ) ;
struct V_70 * V_71 ;
int V_23 = 0 ;
V_24 ;
V_67 . V_52 -= sizeof( * V_65 ) + sizeof( struct V_72 ) ;
V_23 = F_26 ( V_19 , V_68 , & V_67 , NULL , 0 ,
( void * ) V_69 , - 1 ) ;
V_71 = (struct V_70 * ) V_69 ;
F_19 ( V_73 , L_14 ,
V_65 -> V_55 , V_23 , V_65 -> V_52 , V_71 -> V_74 ,
F_37 ( V_71 , 0 ) , F_37 ( V_71 , 1 ) ) ;
RETURN ( V_23 ) ;
}
static int F_38 ( void * V_75 )
{
struct V_76 * V_77 = V_75 ;
struct V_1 * V_2 = V_77 -> V_78 ;
struct V_21 * V_22 = V_2 -> V_10 ;
struct V_79 * V_80 = V_77 -> V_81 ;
char * V_82 ;
T_1 V_83 = V_17 ;
T_1 V_84 ;
int V_23 = 0 , V_20 = 1 , V_85 ;
int V_86 = 0 ;
int V_87 = 0 ;
V_24 ;
F_9 ( V_22 ) ;
F_39 ( V_82 , V_17 ) ;
if ( ! V_82 ) {
V_77 -> V_88 = - V_3 ;
RETURN ( 0 ) ;
}
if ( V_80 != NULL ) {
V_87 = V_80 -> V_89 ;
V_20 = V_80 -> V_89 + 1 ;
}
if ( V_80 != NULL && V_80 -> V_90 )
V_85 = V_80 -> V_90 ;
else
V_85 = V_35 * 8 - 1 ;
while ( V_23 == 0 ) {
struct V_64 * V_65 ;
while ( V_20 <= V_85 &&
! F_40 ( V_20 , V_22 -> V_30 ) )
++ V_20 ;
F_9 ( V_20 <= V_85 + 1 ) ;
if ( V_20 == V_85 + 1 )
break;
V_91:
F_19 ( V_92 , L_15 ,
V_20 , V_85 ) ;
memset ( V_82 , 0 , V_17 ) ;
V_84 = V_83 ;
V_23 = F_41 ( V_77 -> V_93 , V_2 , & V_86 ,
V_20 , & V_83 , V_82 , V_17 ) ;
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
for ( V_65 = (struct V_64 * ) V_82 ;
( char * ) V_65 < V_82 + V_17 ;
V_65 = (struct V_64 * ) ( ( char * ) V_65 + V_65 -> V_52 ) ) {
F_19 ( V_92 , L_16 ,
V_65 , V_65 -> V_50 ) ;
if ( F_42 ( V_65 ) )
F_43 ( V_65 ) ;
F_19 ( V_92 , L_17 ,
V_65 -> V_50 , V_65 -> V_55 ) ;
if ( V_65 -> V_55 == 0 ) {
if ( V_20 <= V_2 -> V_34 )
GOTO ( V_91 , V_23 = 0 ) ;
GOTO ( V_11 , V_23 = 0 ) ;
}
if ( V_65 -> V_52 == 0 ||
V_65 -> V_52 > V_17 ) {
F_44 ( L_18
L_19 , V_65 -> V_52 ,
V_65 -> V_55 , V_20 ) ;
GOTO ( V_11 , V_23 = - V_29 ) ;
}
if ( V_65 -> V_55 < V_20 ) {
F_19 ( V_92 , L_20 ,
V_65 -> V_55 ) ;
continue;
}
F_19 ( V_92 ,
L_21 ,
V_65 -> V_55 , V_65 -> V_52 ,
( int ) ( V_82 + V_17 - ( char * ) V_65 ) ) ;
V_2 -> V_94 = V_65 -> V_55 ;
V_2 -> V_95 = ( char * ) V_65 - ( char * ) V_82 +
V_84 ;
if ( F_40 ( V_20 , V_22 -> V_30 ) ) {
V_23 = V_77 -> V_96 ( V_77 -> V_93 , V_2 , V_65 ,
V_77 -> V_97 ) ;
V_87 = V_20 ;
if ( V_23 == V_98 ) {
GOTO ( V_11 , V_23 ) ;
} else if ( V_23 == V_99 ) {
F_18 ( V_77 -> V_93 ,
V_2 ,
V_65 -> V_55 ) ;
V_23 = 0 ;
}
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
} else {
F_19 ( V_92 , L_22 , V_20 ) ;
}
++ V_20 ;
if ( V_20 > V_85 )
GOTO ( V_11 , V_23 = 0 ) ;
}
}
V_11:
if ( V_80 != NULL )
V_80 -> V_90 = V_87 ;
F_11 ( V_82 , V_17 ) ;
V_77 -> V_88 = V_23 ;
return 0 ;
}
static int F_45 ( void * V_75 )
{
struct V_76 * V_77 = V_75 ;
struct V_18 V_19 ;
int V_23 ;
F_46 () ;
V_23 = F_47 ( & V_19 , V_100 | V_101 ) ;
if ( V_23 )
goto V_11;
V_77 -> V_93 = & V_19 ;
V_23 = F_38 ( V_75 ) ;
F_48 ( & V_19 ) ;
V_11:
F_49 ( & V_77 -> V_102 ) ;
return V_23 ;
}
int F_50 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
T_2 V_103 , void * V_66 , void * V_104 , bool V_105 )
{
struct V_76 * V_77 ;
int V_23 ;
V_24 ;
F_2 ( V_77 ) ;
if ( V_77 == NULL ) {
F_21 ( L_23 ) ;
RETURN ( - V_3 ) ;
}
V_77 -> V_78 = V_2 ;
V_77 -> V_96 = V_103 ;
V_77 -> V_97 = V_66 ;
V_77 -> V_81 = V_104 ;
if ( V_105 ) {
V_77 -> V_93 = NULL ;
F_51 ( & V_77 -> V_102 ) ;
V_23 = F_52 ( F_53 ( F_45 , V_77 ,
L_24 ) ) ;
if ( F_54 ( V_23 ) ) {
F_21 ( L_25 ,
V_2 -> V_36 -> V_37 -> V_38 , V_23 ) ;
F_12 ( V_77 ) ;
RETURN ( V_23 ) ;
}
F_55 ( & V_77 -> V_102 ) ;
} else {
V_77 -> V_93 = V_19 ;
F_38 ( V_77 ) ;
}
V_23 = V_77 -> V_88 ;
F_12 ( V_77 ) ;
RETURN ( V_23 ) ;
}
int F_56 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_103 , void * V_66 , void * V_104 )
{
return F_50 ( V_19 , V_2 , V_103 , V_66 , V_104 , true ) ;
}
inline int F_57 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_10 )
return V_2 -> V_10 -> V_32 ;
return 0 ;
}
int F_58 ( const struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_103 ,
void * V_66 , void * V_104 )
{
struct V_21 * V_22 = V_2 -> V_10 ;
struct V_79 * V_80 = V_104 ;
void * V_82 ;
int V_23 = 0 , V_106 = 1 , V_20 , V_107 ;
V_24 ;
F_39 ( V_82 , V_17 ) ;
if ( ! V_82 )
RETURN ( - V_3 ) ;
if ( V_80 != NULL )
V_106 = V_80 -> V_89 + 1 ;
if ( V_80 != NULL && V_80 -> V_90 )
V_20 = V_80 -> V_90 ;
else
V_20 = V_35 * 8 - 1 ;
while ( V_23 == 0 ) {
struct V_64 * V_65 ;
struct V_72 * V_108 ;
while ( V_20 >= V_106 &&
! F_40 ( V_20 , V_22 -> V_30 ) )
-- V_20 ;
F_9 ( V_20 >= V_106 - 1 ) ;
if ( V_20 == V_106 - 1 )
break;
memset ( V_82 , 0 , V_17 ) ;
V_23 = F_59 ( V_19 , V_2 , V_20 , V_82 ,
V_17 ) ;
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
V_65 = V_82 ;
V_107 = V_65 -> V_55 ;
F_19 ( V_25 , L_26 , V_20 , V_107 ) ;
while ( V_107 < V_20 ) {
V_65 = ( void * ) V_65 + V_65 -> V_52 ;
if ( F_42 ( V_65 ) )
F_43 ( V_65 ) ;
V_107 ++ ;
}
F_9 ( V_107 == V_20 ) ;
V_108 = ( void * ) V_65 + V_65 -> V_52 - sizeof( * V_108 ) ;
while ( ( void * ) V_108 > V_82 ) {
if ( V_108 -> V_56 == 0 )
GOTO ( V_11 , V_23 = 0 ) ;
if ( F_40 ( V_20 , V_22 -> V_30 ) ) {
V_65 = ( void * ) V_108 - V_108 -> V_54 +
sizeof( * V_108 ) ;
V_23 = V_103 ( V_19 , V_2 , V_65 , V_66 ) ;
if ( V_23 == V_98 ) {
GOTO ( V_11 , V_23 ) ;
} else if ( V_23 == V_99 ) {
F_18 ( V_19 , V_2 ,
V_108 -> V_56 ) ;
V_23 = 0 ;
}
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
}
-- V_20 ;
if ( V_20 < V_106 )
GOTO ( V_11 , V_23 = 0 ) ;
V_108 = ( void * ) V_108 - V_108 -> V_54 ;
}
}
V_11:
if ( V_82 )
F_11 ( V_82 , V_17 ) ;
RETURN ( V_23 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
int V_23 ;
V_24 ;
V_23 = F_29 ( V_2 , & V_46 ) ;
if ( V_23 )
RETURN ( V_23 ) ;
if ( V_46 -> V_109 == NULL )
RETURN ( - V_48 ) ;
V_23 = V_46 -> V_109 ( V_2 ) ;
RETURN ( V_23 ) ;
}
int F_61 ( const struct V_18 * V_19 ,
struct V_1 * V_2 , struct V_110 * V_111 )
{
struct V_45 * V_46 ;
int V_112 , V_23 ;
V_24 ;
V_23 = F_29 ( V_2 , & V_46 ) ;
if ( V_23 )
RETURN ( V_23 ) ;
if ( V_46 -> V_113 == NULL )
RETURN ( - V_48 ) ;
V_112 = F_62 ( V_114 ) ;
if ( ! V_112 )
F_63 ( V_114 ) ;
V_23 = V_46 -> V_113 ( V_19 , V_2 , V_111 ) ;
if ( ! V_112 )
F_64 ( V_114 ) ;
RETURN ( V_23 ) ;
}
int F_65 ( const struct V_18 * V_19 , struct V_1 * V_42 ,
struct V_110 * V_111 )
{
struct V_45 * V_46 ;
int V_112 , V_23 ;
V_24 ;
V_23 = F_29 ( V_42 , & V_46 ) ;
if ( V_23 )
RETURN ( V_23 ) ;
if ( V_46 -> V_115 == NULL )
RETURN ( - V_48 ) ;
V_112 = F_62 ( V_114 ) ;
if ( ! V_112 )
F_63 ( V_114 ) ;
V_23 = V_46 -> V_115 ( V_19 , V_42 , V_111 ) ;
if ( ! V_112 )
F_64 ( V_114 ) ;
RETURN ( V_23 ) ;
}
int F_66 ( const struct V_18 * V_19 ,
struct V_1 * V_42 ,
struct V_64 * V_65 , int V_107 ,
struct V_110 * V_111 )
{
struct V_45 * V_46 ;
int V_112 , V_23 ;
V_24 ;
V_23 = F_29 ( V_42 , & V_46 ) ;
if ( V_23 )
RETURN ( V_23 ) ;
F_9 ( V_46 ) ;
if ( V_46 -> V_116 == NULL )
RETURN ( - V_48 ) ;
V_112 = F_62 ( V_114 ) ;
if ( ! V_112 )
F_63 ( V_114 ) ;
V_23 = V_46 -> V_116 ( V_19 , V_42 , V_65 , V_107 , V_111 ) ;
if ( ! V_112 )
F_64 ( V_114 ) ;
RETURN ( V_23 ) ;
}
int F_67 ( const struct V_18 * V_19 , struct V_1 * V_42 ,
struct V_64 * V_65 , struct V_117 * V_118 ,
int V_119 , void * V_82 , int V_107 , struct V_110 * V_111 )
{
struct V_45 * V_46 ;
int V_112 , V_23 , V_120 ;
V_24 ;
V_23 = F_29 ( V_42 , & V_46 ) ;
if ( V_23 )
RETURN ( V_23 ) ;
F_9 ( V_46 ) ;
if ( V_46 -> V_121 == NULL )
RETURN ( - V_48 ) ;
if ( V_82 )
V_120 = V_65 -> V_52 + sizeof( struct V_64 ) +
sizeof( struct V_72 ) ;
else
V_120 = V_65 -> V_52 ;
F_9 ( F_68 ( V_120 ) == V_120 ) ;
V_112 = F_62 ( V_114 ) ;
if ( ! V_112 )
F_63 ( V_114 ) ;
V_23 = V_46 -> V_121 ( V_19 , V_42 , V_65 , V_118 , V_119 ,
V_82 , V_107 , V_111 ) ;
if ( ! V_112 )
F_64 ( V_114 ) ;
RETURN ( V_23 ) ;
}
int F_69 ( const struct V_18 * V_19 , struct V_1 * V_122 ,
struct V_64 * V_65 , struct V_117 * V_118 ,
void * V_82 , struct V_110 * V_111 )
{
int V_112 , V_23 ;
V_24 ;
if ( V_122 -> V_123 -> V_124 == NULL )
RETURN ( - V_48 ) ;
V_112 = F_62 ( V_114 ) ;
if ( ! V_112 )
F_63 ( V_114 ) ;
V_23 = V_122 -> V_123 -> V_124 ( V_19 , V_122 , V_65 , V_118 , V_82 , V_111 ) ;
if ( ! V_112 )
F_64 ( V_114 ) ;
RETURN ( V_23 ) ;
}
int F_70 ( const struct V_18 * V_19 , struct V_1 * V_122 ,
struct V_64 * V_65 , struct V_110 * V_111 )
{
int V_112 , V_23 ;
V_24 ;
if ( V_122 -> V_123 -> V_125 == NULL )
RETURN ( - V_48 ) ;
V_112 = F_62 ( V_114 ) ;
if ( ! V_112 )
F_63 ( V_114 ) ;
V_23 = V_122 -> V_123 -> V_125 ( V_19 , V_122 , V_65 , V_111 ) ;
if ( ! V_112 )
F_64 ( V_114 ) ;
RETURN ( V_23 ) ;
}
int F_71 ( const struct V_18 * V_19 , struct V_126 * V_127 ,
struct V_1 * * V_128 , struct V_129 * V_130 ,
char * V_131 )
{
struct V_110 * V_111 ;
int V_23 ;
V_24 ;
V_23 = F_72 ( V_19 , V_127 , V_128 , V_130 , V_131 , V_132 ) ;
if ( V_23 )
RETURN ( V_23 ) ;
if ( F_60 ( * V_128 ) )
RETURN ( 0 ) ;
if ( ( * V_128 ) -> V_133 != NULL ) {
struct V_134 * V_135 ;
V_135 = F_73 ( ( * V_128 ) -> V_133 -> V_136 . V_137 ) ;
V_111 = F_74 ( V_19 , V_135 ) ;
if ( F_75 ( V_111 ) )
GOTO ( V_11 , V_23 = F_52 ( V_111 ) ) ;
V_23 = F_61 ( V_19 , * V_128 , V_111 ) ;
if ( V_23 == 0 ) {
V_23 = F_76 ( V_19 , V_135 , V_111 ) ;
if ( V_23 == 0 )
V_23 = F_65 ( V_19 , * V_128 , V_111 ) ;
}
F_77 ( V_19 , V_135 , V_111 ) ;
} else {
F_9 ( ( * V_128 ) -> V_138 == NULL ) ;
V_23 = F_65 ( V_19 , * V_128 , NULL ) ;
}
V_11:
if ( V_23 )
F_78 ( V_19 , * V_128 ) ;
RETURN ( V_23 ) ;
}
int F_79 ( const struct V_18 * V_19 , struct V_126 * V_127 ,
struct V_129 * V_130 , char * V_131 )
{
struct V_1 * V_42 ;
int V_23 = 0 , V_139 ;
V_24 ;
if ( V_131 == NULL && V_130 == NULL )
RETURN ( 0 ) ;
V_23 = F_72 ( V_19 , V_127 , & V_42 , V_130 , V_131 , V_140 ) ;
if ( V_23 < 0 )
RETURN ( V_23 ) ;
V_23 = F_33 ( V_19 , V_42 , V_13 , NULL ) ;
if ( V_23 == 0 )
V_23 = F_25 ( V_19 , V_42 ) ;
V_139 = F_78 ( V_19 , V_42 ) ;
if ( V_23 == 0 )
V_23 = V_139 ;
RETURN ( V_23 ) ;
}
int F_26 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_64 * V_65 , struct V_117 * V_141 ,
int V_142 , void * V_82 , int V_107 )
{
int V_23 ;
V_24 ;
F_9 ( V_2 ) ;
F_9 ( V_2 -> V_36 ) ;
if ( V_2 -> V_133 != NULL ) {
struct V_134 * V_143 ;
struct V_110 * V_111 ;
V_143 = F_73 ( V_2 -> V_133 -> V_136 . V_137 ) ;
V_111 = F_74 ( V_19 , V_143 ) ;
if ( F_75 ( V_111 ) )
RETURN ( F_52 ( V_111 ) ) ;
V_23 = F_66 ( V_19 , V_2 , V_65 , V_107 , V_111 ) ;
if ( V_23 )
GOTO ( V_144 , V_23 ) ;
V_23 = F_76 ( V_19 , V_143 , V_111 ) ;
if ( V_23 )
GOTO ( V_144 , V_23 ) ;
F_80 ( & V_2 -> V_4 ) ;
V_23 = F_67 ( V_19 , V_2 , V_65 , V_141 ,
V_142 , V_82 , V_107 , V_111 ) ;
F_81 ( & V_2 -> V_4 ) ;
V_144:
F_77 ( V_19 , V_143 , V_111 ) ;
} else {
F_80 ( & V_2 -> V_4 ) ;
V_23 = F_67 ( V_19 , V_2 , V_65 , V_141 ,
V_142 , V_82 , V_107 , NULL ) ;
F_81 ( & V_2 -> V_4 ) ;
}
RETURN ( V_23 ) ;
}
int F_72 ( const struct V_18 * V_19 , struct V_126 * V_127 ,
struct V_1 * * V_122 , struct V_129 * V_130 ,
char * V_131 , enum V_145 V_146 )
{
int V_112 ;
int V_23 ;
V_24 ;
F_9 ( V_127 ) ;
F_9 ( V_127 -> V_147 ) ;
if ( V_127 -> V_147 -> V_148 == NULL ) {
* V_122 = NULL ;
RETURN ( - V_48 ) ;
}
* V_122 = F_1 () ;
if ( * V_122 == NULL )
RETURN ( - V_3 ) ;
( * V_122 ) -> V_36 = V_127 ;
( * V_122 ) -> V_123 = V_127 -> V_147 ;
V_112 = F_62 ( V_114 ) ;
if ( ! V_112 )
F_63 ( V_114 ) ;
V_23 = V_127 -> V_147 -> V_148 ( V_19 , * V_122 , V_130 , V_131 , V_146 ) ;
if ( ! V_112 )
F_64 ( V_114 ) ;
if ( V_23 ) {
F_8 ( * V_122 ) ;
* V_122 = NULL ;
}
RETURN ( V_23 ) ;
}
int F_78 ( const struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_45 * V_46 ;
int V_23 ;
V_24 ;
V_23 = F_29 ( V_2 , & V_46 ) ;
if ( V_23 )
GOTO ( V_11 , V_23 ) ;
if ( V_46 -> V_149 == NULL )
GOTO ( V_11 , V_23 = - V_48 ) ;
V_23 = V_46 -> V_149 ( V_19 , V_2 ) ;
V_11:
F_15 ( V_2 ) ;
RETURN ( V_23 ) ;
}
