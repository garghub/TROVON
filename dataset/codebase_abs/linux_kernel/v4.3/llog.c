static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 . V_7 . V_8 ) ;
F_6 ( & V_2 -> V_9 , 1 ) ;
return V_2 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 != NULL ) ;
if ( ! V_2 -> V_10 )
goto V_11;
if ( V_2 -> V_10 -> V_12 & V_13 )
F_8 ( F_9 ( & V_2 -> V_6 . V_7 . V_8 ) ) ;
else if ( V_2 -> V_10 -> V_12 & V_14 )
F_8 ( F_9 ( & V_2 -> V_6 . V_15 . V_16 ) ) ;
F_8 ( sizeof( * ( V_2 -> V_10 ) ) == V_17 ) ;
F_10 ( V_2 -> V_10 ) ;
V_11:
F_10 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_9 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_8 ( F_14 ( & V_2 -> V_9 ) > 0 ) ;
if ( F_15 ( & V_2 -> V_9 ) )
F_7 ( V_2 ) ;
}
int F_16 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
int V_20 )
{
struct V_21 * V_22 = V_2 -> V_10 ;
int V_23 = 0 ;
F_17 ( V_24 , L_1 V_25 L_2 ,
V_20 , F_18 ( & V_2 -> V_26 . V_27 ) ) ;
if ( V_20 == 0 ) {
F_19 ( L_3 ) ;
return - V_28 ;
}
F_20 ( & V_2 -> V_5 ) ;
if ( ! F_21 ( V_20 , V_22 -> V_29 ) ) {
F_22 ( & V_2 -> V_5 ) ;
F_17 ( V_24 , L_4 , V_20 ) ;
return - V_30 ;
}
V_22 -> V_31 -- ;
if ( ( V_22 -> V_12 & V_32 ) &&
( V_22 -> V_31 == 1 ) &&
( V_2 -> V_33 == ( V_34 * 8 ) - 1 ) ) {
F_22 ( & V_2 -> V_5 ) ;
V_23 = F_23 ( V_19 , V_2 ) ;
if ( V_23 < 0 ) {
F_19 ( L_5 V_25
L_6 ,
V_2 -> V_35 -> V_36 -> V_37 ,
F_18 ( & V_2 -> V_26 . V_27 ) ,
V_2 -> V_26 . V_38 , V_23 ) ;
goto V_39;
}
return 1 ;
}
F_22 ( & V_2 -> V_5 ) ;
V_23 = F_24 ( V_19 , V_2 , & V_22 -> V_40 , NULL , 0 , NULL , 0 ) ;
if ( V_23 < 0 ) {
F_19 ( L_7 V_25
L_6 ,
V_2 -> V_35 -> V_36 -> V_37 ,
F_18 ( & V_2 -> V_26 . V_27 ) ,
V_2 -> V_26 . V_38 , V_23 ) ;
goto V_39;
}
return 0 ;
V_39:
F_20 ( & V_2 -> V_5 ) ;
F_25 ( V_20 , V_22 -> V_29 ) ;
V_22 -> V_31 ++ ;
F_22 ( & V_2 -> V_5 ) ;
return V_23 ;
}
static int F_26 ( const struct V_18 * V_19 ,
struct V_1 * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_23 ;
V_23 = F_27 ( V_41 , & V_45 ) ;
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
V_22 -> V_56 = F_28 () ;
if ( V_43 )
memcpy ( & V_22 -> V_57 , V_43 ,
sizeof( V_22 -> V_57 ) ) ;
V_22 -> V_58 = F_29 ( F_30 ( * V_22 ) , V_29 ) ;
F_25 ( 0 , V_22 -> V_29 ) ;
V_23 = 0 ;
}
return V_23 ;
}
int F_31 ( const struct V_18 * V_19 , struct V_1 * V_41 ,
int V_59 , struct V_42 * V_43 )
{
struct V_21 * V_22 ;
int V_23 ;
F_8 ( V_41 -> V_10 == NULL ) ;
V_22 = F_2 ( sizeof( * V_22 ) , V_3 ) ;
if ( ! V_22 )
return - V_60 ;
V_41 -> V_10 = V_22 ;
V_22 -> V_12 = V_59 ;
V_23 = F_26 ( V_19 , V_41 , V_43 ) ;
if ( V_23 == 0 ) {
if ( F_32 ( ( V_22 -> V_12 & V_13 &&
V_59 & V_14 ) ||
( V_22 -> V_12 & V_14 &&
V_59 & V_13 ) ) ) {
F_19 ( L_8 ,
V_41 -> V_35 -> V_36 -> V_37 ,
V_22 -> V_12 & V_14 ?
L_9 : L_10 ,
V_59 & V_14 ? L_9 : L_10 ) ;
V_23 = - V_28 ;
goto V_11;
} else if ( V_22 -> V_12 &
( V_13 | V_14 ) ) {
V_59 = V_22 -> V_12 ;
} else {
F_19 ( L_11 ) ;
V_23 = - V_28 ;
goto V_11;
}
if ( F_32 ( V_43 &&
! F_33 ( V_43 , & V_22 -> V_57 ) ) ) {
F_19 ( L_12 ,
V_41 -> V_35 -> V_36 -> V_37 ,
( char * ) V_43 -> V_43 ,
( char * ) V_22 -> V_57 . V_43 ) ;
V_23 = - V_61 ;
goto V_11;
}
}
if ( V_59 & V_14 ) {
F_8 ( F_9 ( & V_41 -> V_6 . V_15 . V_16 ) ) ;
F_5 ( & V_41 -> V_6 . V_15 . V_16 ) ;
V_22 -> V_62 = sizeof( struct V_63 ) ;
} else if ( ! ( V_59 & V_13 ) ) {
F_19 ( L_13 ,
V_41 -> V_35 -> V_36 -> V_37 ,
V_59 , V_14 , V_13 ) ;
V_23 = - V_28 ;
}
V_11:
if ( V_23 ) {
F_10 ( V_22 ) ;
V_41 -> V_10 = NULL ;
}
return V_23 ;
}
static int F_34 ( void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_1 * V_2 = V_66 -> V_67 ;
struct V_21 * V_22 = V_2 -> V_10 ;
struct V_68 * V_69 = V_66 -> V_70 ;
char * V_71 ;
T_1 V_72 = V_17 ;
T_1 V_73 ;
int V_23 = 0 , V_20 = 1 , V_74 ;
int V_75 = 0 ;
int V_76 = 0 ;
F_8 ( V_22 ) ;
V_71 = F_2 ( V_17 , V_3 ) ;
if ( ! V_71 ) {
V_66 -> V_77 = - V_60 ;
return 0 ;
}
if ( V_69 != NULL ) {
V_76 = V_69 -> V_78 ;
V_20 = V_69 -> V_78 + 1 ;
}
if ( V_69 != NULL && V_69 -> V_79 )
V_74 = V_69 -> V_79 ;
else
V_74 = V_34 * 8 - 1 ;
while ( V_23 == 0 ) {
struct V_80 * V_81 ;
while ( V_20 <= V_74 &&
! F_35 ( V_20 , V_22 -> V_29 ) )
++ V_20 ;
F_8 ( V_20 <= V_74 + 1 ) ;
if ( V_20 == V_74 + 1 )
break;
V_82:
F_17 ( V_83 , L_14 ,
V_20 , V_74 ) ;
memset ( V_71 , 0 , V_17 ) ;
V_73 = V_72 ;
V_23 = F_36 ( V_66 -> V_84 , V_2 , & V_75 ,
V_20 , & V_72 , V_71 , V_17 ) ;
if ( V_23 )
goto V_11;
for ( V_81 = (struct V_80 * ) V_71 ;
( char * ) V_81 < V_71 + V_17 ;
V_81 = (struct V_80 * ) ( ( char * ) V_81 + V_81 -> V_51 ) ) {
F_17 ( V_83 , L_15 ,
V_81 , V_81 -> V_49 ) ;
if ( F_37 ( V_81 ) )
F_38 ( V_81 ) ;
F_17 ( V_83 , L_16 ,
V_81 -> V_49 , V_81 -> V_54 ) ;
if ( V_81 -> V_54 == 0 ) {
V_23 = 0 ;
if ( V_20 <= V_2 -> V_33 )
goto V_82;
goto V_11;
}
if ( V_81 -> V_51 == 0 ||
V_81 -> V_51 > V_17 ) {
F_39 ( L_17 ,
V_81 -> V_51 ,
V_81 -> V_54 , V_20 ) ;
V_23 = - V_28 ;
goto V_11;
}
if ( V_81 -> V_54 < V_20 ) {
F_17 ( V_83 , L_18 ,
V_81 -> V_54 ) ;
continue;
}
F_17 ( V_83 ,
L_19 ,
V_81 -> V_54 , V_81 -> V_51 ,
( int ) ( V_71 + V_17 - ( char * ) V_81 ) ) ;
V_2 -> V_85 = V_81 -> V_54 ;
V_2 -> V_86 = ( char * ) V_81 - ( char * ) V_71 +
V_73 ;
if ( F_35 ( V_20 , V_22 -> V_29 ) ) {
V_23 = V_66 -> V_87 ( V_66 -> V_84 , V_2 , V_81 ,
V_66 -> V_88 ) ;
V_76 = V_20 ;
if ( V_23 == V_89 ) {
goto V_11;
} else if ( V_23 == V_90 ) {
F_16 ( V_66 -> V_84 ,
V_2 ,
V_81 -> V_54 ) ;
V_23 = 0 ;
}
if ( V_23 )
goto V_11;
} else {
F_17 ( V_83 , L_20 , V_20 ) ;
}
++ V_20 ;
if ( V_20 > V_74 ) {
V_23 = 0 ;
goto V_11;
}
}
}
V_11:
if ( V_69 != NULL )
V_69 -> V_79 = V_76 ;
F_10 ( V_71 ) ;
V_66 -> V_77 = V_23 ;
return 0 ;
}
static int F_40 ( void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_18 V_19 ;
int V_23 ;
F_41 () ;
V_23 = F_42 ( & V_19 , V_91 | V_92 ) ;
if ( V_23 )
goto V_11;
V_66 -> V_84 = & V_19 ;
V_23 = F_34 ( V_64 ) ;
F_43 ( & V_19 ) ;
V_11:
F_44 ( & V_66 -> V_93 ) ;
return V_23 ;
}
int F_45 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
T_2 V_94 , void * V_95 , void * V_96 , bool V_97 )
{
struct V_65 * V_66 ;
int V_23 ;
V_66 = F_2 ( sizeof( * V_66 ) , V_3 ) ;
if ( ! V_66 ) {
F_19 ( L_21 ) ;
return - V_60 ;
}
V_66 -> V_67 = V_2 ;
V_66 -> V_87 = V_94 ;
V_66 -> V_88 = V_95 ;
V_66 -> V_70 = V_96 ;
if ( V_97 ) {
V_66 -> V_84 = NULL ;
F_46 ( & V_66 -> V_93 ) ;
V_23 = F_47 ( F_48 ( F_40 , V_66 ,
L_22 ) ) ;
if ( F_49 ( V_23 ) ) {
F_19 ( L_23 ,
V_2 -> V_35 -> V_36 -> V_37 , V_23 ) ;
F_10 ( V_66 ) ;
return V_23 ;
}
F_50 ( & V_66 -> V_93 ) ;
} else {
V_66 -> V_84 = V_19 ;
F_34 ( V_66 ) ;
}
V_23 = V_66 -> V_77 ;
F_10 ( V_66 ) ;
return V_23 ;
}
int F_51 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
T_2 V_94 , void * V_95 , void * V_96 )
{
return F_45 ( V_19 , V_2 , V_94 , V_95 , V_96 , true ) ;
}
int F_52 ( const struct V_18 * V_19 ,
struct V_1 * V_2 , T_2 V_94 ,
void * V_95 , void * V_96 )
{
struct V_21 * V_22 = V_2 -> V_10 ;
struct V_68 * V_69 = V_96 ;
void * V_71 ;
int V_23 = 0 , V_98 = 1 , V_20 , V_99 ;
V_71 = F_2 ( V_17 , V_3 ) ;
if ( ! V_71 )
return - V_60 ;
if ( V_69 != NULL )
V_98 = V_69 -> V_78 + 1 ;
if ( V_69 != NULL && V_69 -> V_79 )
V_20 = V_69 -> V_79 ;
else
V_20 = V_34 * 8 - 1 ;
while ( V_23 == 0 ) {
struct V_80 * V_81 ;
struct V_100 * V_101 ;
while ( V_20 >= V_98 &&
! F_35 ( V_20 , V_22 -> V_29 ) )
-- V_20 ;
F_8 ( V_20 >= V_98 - 1 ) ;
if ( V_20 == V_98 - 1 )
break;
memset ( V_71 , 0 , V_17 ) ;
V_23 = F_53 ( V_19 , V_2 , V_20 , V_71 ,
V_17 ) ;
if ( V_23 )
goto V_11;
V_81 = V_71 ;
V_99 = V_81 -> V_54 ;
F_17 ( V_24 , L_24 , V_20 , V_99 ) ;
while ( V_99 < V_20 ) {
V_81 = ( void * ) V_81 + V_81 -> V_51 ;
if ( F_37 ( V_81 ) )
F_38 ( V_81 ) ;
V_99 ++ ;
}
F_8 ( V_99 == V_20 ) ;
V_101 = ( void * ) V_81 + V_81 -> V_51 - sizeof( * V_101 ) ;
while ( ( void * ) V_101 > V_71 ) {
if ( V_101 -> V_55 == 0 ) {
V_23 = 0 ;
goto V_11;
}
if ( F_35 ( V_20 , V_22 -> V_29 ) ) {
V_81 = ( void * ) V_101 - V_101 -> V_53 +
sizeof( * V_101 ) ;
V_23 = V_94 ( V_19 , V_2 , V_81 , V_95 ) ;
if ( V_23 == V_89 ) {
goto V_11;
} else if ( V_23 == V_90 ) {
F_16 ( V_19 , V_2 ,
V_101 -> V_55 ) ;
V_23 = 0 ;
}
if ( V_23 )
goto V_11;
}
-- V_20 ;
if ( V_20 < V_98 ) {
V_23 = 0 ;
goto V_11;
}
V_101 = ( void * ) V_101 - V_101 -> V_53 ;
}
}
V_11:
F_10 ( V_71 ) ;
return V_23 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
int V_23 ;
V_23 = F_27 ( V_2 , & V_45 ) ;
if ( V_23 )
return V_23 ;
if ( V_45 -> V_102 == NULL )
return - V_47 ;
V_23 = V_45 -> V_102 ( V_2 ) ;
return V_23 ;
}
int F_55 ( const struct V_18 * V_19 ,
struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_44 * V_45 ;
int V_105 , V_23 ;
V_23 = F_27 ( V_2 , & V_45 ) ;
if ( V_23 )
return V_23 ;
if ( V_45 -> V_106 == NULL )
return - V_47 ;
V_105 = F_56 ( V_107 ) ;
if ( ! V_105 )
F_57 ( V_107 ) ;
V_23 = V_45 -> V_106 ( V_19 , V_2 , V_104 ) ;
if ( ! V_105 )
F_58 ( V_107 ) ;
return V_23 ;
}
int F_59 ( const struct V_18 * V_19 , struct V_1 * V_41 ,
struct V_103 * V_104 )
{
struct V_44 * V_45 ;
int V_105 , V_23 ;
V_23 = F_27 ( V_41 , & V_45 ) ;
if ( V_23 )
return V_23 ;
if ( V_45 -> V_108 == NULL )
return - V_47 ;
V_105 = F_56 ( V_107 ) ;
if ( ! V_105 )
F_57 ( V_107 ) ;
V_23 = V_45 -> V_108 ( V_19 , V_41 , V_104 ) ;
if ( ! V_105 )
F_58 ( V_107 ) ;
return V_23 ;
}
int F_60 ( const struct V_18 * V_19 ,
struct V_1 * V_41 ,
struct V_80 * V_81 , int V_99 ,
struct V_103 * V_104 )
{
struct V_44 * V_45 ;
int V_105 , V_23 ;
V_23 = F_27 ( V_41 , & V_45 ) ;
if ( V_23 )
return V_23 ;
F_8 ( V_45 ) ;
if ( V_45 -> V_109 == NULL )
return - V_47 ;
V_105 = F_56 ( V_107 ) ;
if ( ! V_105 )
F_57 ( V_107 ) ;
V_23 = V_45 -> V_109 ( V_19 , V_41 , V_81 , V_99 , V_104 ) ;
if ( ! V_105 )
F_58 ( V_107 ) ;
return V_23 ;
}
int F_61 ( const struct V_18 * V_19 , struct V_1 * V_41 ,
struct V_80 * V_81 , struct V_110 * V_111 ,
int V_112 , void * V_71 , int V_99 , struct V_103 * V_104 )
{
struct V_44 * V_45 ;
int V_105 , V_23 , V_113 ;
V_23 = F_27 ( V_41 , & V_45 ) ;
if ( V_23 )
return V_23 ;
F_8 ( V_45 ) ;
if ( V_45 -> V_114 == NULL )
return - V_47 ;
if ( V_71 )
V_113 = V_81 -> V_51 + sizeof( struct V_80 ) +
sizeof( struct V_100 ) ;
else
V_113 = V_81 -> V_51 ;
F_8 ( F_62 ( V_113 ) == V_113 ) ;
V_105 = F_56 ( V_107 ) ;
if ( ! V_105 )
F_57 ( V_107 ) ;
V_23 = V_45 -> V_114 ( V_19 , V_41 , V_81 , V_111 , V_112 ,
V_71 , V_99 , V_104 ) ;
if ( ! V_105 )
F_58 ( V_107 ) ;
return V_23 ;
}
int F_63 ( const struct V_18 * V_19 , struct V_1 * V_115 ,
struct V_80 * V_81 , struct V_110 * V_111 ,
void * V_71 , struct V_103 * V_104 )
{
int V_105 , V_23 ;
if ( V_115 -> V_116 -> V_117 == NULL )
return - V_47 ;
V_105 = F_56 ( V_107 ) ;
if ( ! V_105 )
F_57 ( V_107 ) ;
V_23 = V_115 -> V_116 -> V_117 ( V_19 , V_115 , V_81 , V_111 , V_71 , V_104 ) ;
if ( ! V_105 )
F_58 ( V_107 ) ;
return V_23 ;
}
int F_64 ( const struct V_18 * V_19 , struct V_1 * V_115 ,
struct V_80 * V_81 , struct V_103 * V_104 )
{
int V_105 , V_23 ;
if ( V_115 -> V_116 -> V_118 == NULL )
return - V_47 ;
V_105 = F_56 ( V_107 ) ;
if ( ! V_105 )
F_57 ( V_107 ) ;
V_23 = V_115 -> V_116 -> V_118 ( V_19 , V_115 , V_81 , V_104 ) ;
if ( ! V_105 )
F_58 ( V_107 ) ;
return V_23 ;
}
int F_65 ( const struct V_18 * V_19 , struct V_119 * V_120 ,
struct V_1 * * V_121 , struct V_122 * V_123 ,
char * V_124 )
{
struct V_125 * V_126 ;
struct V_103 * V_104 ;
int V_23 ;
V_23 = F_66 ( V_19 , V_120 , V_121 , V_123 , V_124 , V_127 ) ;
if ( V_23 )
return V_23 ;
if ( F_54 ( * V_121 ) )
return 0 ;
F_8 ( ( * V_121 ) -> V_128 != NULL ) ;
V_126 = F_67 ( ( * V_121 ) -> V_128 -> V_129 . V_130 ) ;
V_104 = F_68 ( V_19 , V_126 ) ;
if ( F_69 ( V_104 ) ) {
V_23 = F_47 ( V_104 ) ;
goto V_11;
}
V_23 = F_55 ( V_19 , * V_121 , V_104 ) ;
if ( V_23 == 0 ) {
V_23 = F_70 ( V_19 , V_126 , V_104 ) ;
if ( V_23 == 0 )
V_23 = F_59 ( V_19 , * V_121 , V_104 ) ;
}
F_71 ( V_19 , V_126 , V_104 ) ;
V_11:
if ( V_23 )
F_72 ( V_19 , * V_121 ) ;
return V_23 ;
}
int F_73 ( const struct V_18 * V_19 , struct V_119 * V_120 ,
struct V_122 * V_123 , char * V_124 )
{
struct V_1 * V_41 ;
int V_23 = 0 , V_131 ;
if ( V_124 == NULL && V_123 == NULL )
return 0 ;
V_23 = F_66 ( V_19 , V_120 , & V_41 , V_123 , V_124 , V_132 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_31 ( V_19 , V_41 , V_13 , NULL ) ;
if ( V_23 == 0 )
V_23 = F_23 ( V_19 , V_41 ) ;
V_131 = F_72 ( V_19 , V_41 ) ;
if ( V_23 == 0 )
V_23 = V_131 ;
return V_23 ;
}
int F_24 ( const struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_80 * V_81 , struct V_110 * V_133 ,
int V_134 , void * V_71 , int V_99 )
{
struct V_125 * V_135 ;
struct V_103 * V_104 ;
int V_23 ;
F_8 ( V_2 ) ;
F_8 ( V_2 -> V_35 ) ;
F_8 ( V_2 -> V_128 != NULL ) ;
V_135 = F_67 ( V_2 -> V_128 -> V_129 . V_130 ) ;
V_104 = F_68 ( V_19 , V_135 ) ;
if ( F_69 ( V_104 ) )
return F_47 ( V_104 ) ;
V_23 = F_60 ( V_19 , V_2 , V_81 , V_99 , V_104 ) ;
if ( V_23 )
goto V_136;
V_23 = F_70 ( V_19 , V_135 , V_104 ) ;
if ( V_23 )
goto V_136;
F_74 ( & V_2 -> V_4 ) ;
V_23 = F_61 ( V_19 , V_2 , V_81 , V_133 ,
V_134 , V_71 , V_99 , V_104 ) ;
F_75 ( & V_2 -> V_4 ) ;
V_136:
F_71 ( V_19 , V_135 , V_104 ) ;
return V_23 ;
}
int F_66 ( const struct V_18 * V_19 , struct V_119 * V_120 ,
struct V_1 * * V_115 , struct V_122 * V_123 ,
char * V_124 , enum V_137 V_138 )
{
int V_105 ;
int V_23 ;
F_8 ( V_120 ) ;
F_8 ( V_120 -> V_139 ) ;
if ( V_120 -> V_139 -> V_140 == NULL ) {
* V_115 = NULL ;
return - V_47 ;
}
* V_115 = F_1 () ;
if ( * V_115 == NULL )
return - V_60 ;
( * V_115 ) -> V_35 = V_120 ;
( * V_115 ) -> V_116 = V_120 -> V_139 ;
V_105 = F_56 ( V_107 ) ;
if ( ! V_105 )
F_57 ( V_107 ) ;
V_23 = V_120 -> V_139 -> V_140 ( V_19 , * V_115 , V_123 , V_124 , V_138 ) ;
if ( ! V_105 )
F_58 ( V_107 ) ;
if ( V_23 ) {
F_7 ( * V_115 ) ;
* V_115 = NULL ;
}
return V_23 ;
}
int F_72 ( const struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_44 * V_45 ;
int V_23 ;
V_23 = F_27 ( V_2 , & V_45 ) ;
if ( V_23 )
goto V_11;
if ( V_45 -> V_141 == NULL ) {
V_23 = - V_47 ;
goto V_11;
}
V_23 = V_45 -> V_141 ( V_19 , V_2 ) ;
V_11:
F_13 ( V_2 ) ;
return V_23 ;
}
int F_76 ( const struct V_18 * V_19 , struct V_119 * V_120 ,
char * V_124 )
{
struct V_1 * V_22 ;
int V_23 ;
V_23 = F_66 ( V_19 , V_120 , & V_22 , NULL , V_124 , V_132 ) ;
if ( V_23 < 0 ) {
if ( F_77 ( V_23 == - V_30 ) )
V_23 = 0 ;
goto V_11;
}
V_23 = F_31 ( V_19 , V_22 , V_13 , NULL ) ;
if ( V_23 )
goto V_142;
V_23 = F_78 ( V_22 ) ;
V_142:
F_72 ( V_19 , V_22 ) ;
V_11:
return V_23 <= 1 ;
}
int F_79 ( const struct V_18 * V_19 , struct V_1 * V_22 ,
struct V_80 * V_81 , void * V_95 )
{
struct V_1 * V_143 = V_95 ;
return F_24 ( V_19 , V_143 , V_81 , NULL , 0 , NULL , - 1 ) ;
}
int F_80 ( const struct V_18 * V_19 , struct V_144 * V_145 ,
struct V_119 * V_120 , struct V_119 * V_146 ,
char * V_124 , char * V_147 )
{
struct V_1 * V_22 , * V_148 ;
int V_23 ;
V_23 = F_66 ( V_19 , V_120 , & V_22 , NULL , V_124 , V_132 ) ;
if ( V_23 < 0 ) {
if ( V_23 != - V_30 )
F_19 ( L_25 ,
V_145 -> V_37 , V_124 , V_23 ) ;
return V_23 ;
}
V_23 = F_31 ( V_19 , V_22 , V_13 , NULL ) ;
if ( V_23 )
goto V_142;
V_23 = F_73 ( V_19 , V_146 , NULL , V_147 ) ;
if ( V_23 < 0 && V_23 != - V_30 )
goto V_142;
V_23 = F_65 ( V_19 , V_146 , & V_148 , NULL , V_147 ) ;
if ( V_23 ) {
F_19 ( L_26 ,
V_145 -> V_37 , V_147 , V_23 ) ;
goto V_142;
}
if ( V_22 -> V_128 == V_148 -> V_128 ) {
F_19 ( L_27 ,
V_145 -> V_37 , V_124 , V_147 , V_22 -> V_128 ,
V_148 -> V_128 ) ;
V_23 = - V_61 ;
goto V_149;
}
V_23 = F_31 ( V_19 , V_148 , V_13 , NULL ) ;
if ( V_23 )
goto V_149;
V_23 = F_45 ( V_19 , V_22 , F_79 , ( void * ) V_148 ,
NULL , false ) ;
if ( V_23 )
F_19 ( L_28 ,
V_145 -> V_37 , V_124 , V_23 ) ;
V_149:
F_72 ( V_19 , V_148 ) ;
V_142:
F_72 ( V_19 , V_22 ) ;
return V_23 ;
}
