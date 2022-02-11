static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( L_1 , V_3 -> V_4 ) ;
if ( V_3 -> V_5 < V_6 )
F_3 ( V_3 , V_7 , F_4 () ) ;
}
struct V_2 * F_5 ( struct V_8 * V_9 ,
unsigned long V_10 )
{
struct V_2 * V_3 ;
struct V_11 * V_12 ;
F_2 ( L_2 , V_9 , V_10 ) ;
F_6 ( & V_9 -> V_13 ) ;
V_12 = V_9 -> V_14 . V_11 ;
while ( V_12 ) {
V_3 = F_7 ( V_12 , struct V_2 , V_15 ) ;
if ( V_10 < V_3 -> V_10 )
V_12 = V_12 -> V_16 ;
else if ( V_10 > V_3 -> V_10 )
V_12 = V_12 -> V_17 ;
else
goto V_18;
}
F_8 ( & V_9 -> V_13 ) ;
F_9 ( L_3 ) ;
return NULL ;
V_18:
F_10 ( V_3 , V_19 ) ;
F_8 ( & V_9 -> V_13 ) ;
F_9 ( L_4 , V_3 , F_11 ( & V_3 -> V_20 ) ) ;
return V_3 ;
}
struct V_2 * F_12 ( T_1 V_21 )
{
struct V_2 * V_3 ;
V_3 = F_13 ( V_22 , V_21 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_23 = F_14 ( V_24 ,
sizeof( struct V_25 * ) ,
V_21 ) ;
if ( ! V_3 -> V_23 )
goto V_26;
V_3 -> V_27 = F_14 ( V_24 , sizeof( V_28 ) , V_21 ) ;
if ( ! V_3 -> V_27 )
goto V_29;
F_15 ( & V_3 -> V_30 , F_1 ,
( unsigned long ) V_3 ) ;
F_16 ( & V_3 -> V_31 , & V_32 ) ;
F_17 ( & V_3 -> V_33 ) ;
F_17 ( & V_3 -> V_34 ) ;
F_17 ( & V_3 -> V_35 ) ;
F_17 ( & V_3 -> V_36 ) ;
F_17 ( & V_3 -> V_37 ) ;
F_18 ( & V_3 -> V_38 ) ;
F_19 ( & V_3 -> V_39 ) ;
F_20 ( & V_3 -> V_40 ) ;
F_21 ( & V_3 -> V_20 , 1 ) ;
V_3 -> V_4 = F_22 ( & V_41 ) ;
memset ( & V_3 -> V_15 , 0xed , sizeof( V_3 -> V_15 ) ) ;
V_3 -> V_42 = V_43 ;
V_3 -> V_44 = 16 ;
V_3 -> V_45 = 1 ;
if ( V_46 > 2190 )
V_3 -> V_47 = 2 ;
else if ( V_46 > 1095 )
V_3 -> V_47 = 3 ;
else
V_3 -> V_47 = 4 ;
V_3 -> V_48 = V_24 - 1 ;
return V_3 ;
V_29:
F_23 ( V_3 -> V_23 ) ;
V_26:
F_24 ( V_22 , V_3 ) ;
return NULL ;
}
static struct V_2 * F_25 ( struct V_49 * V_50 ,
T_1 V_21 )
{
struct V_2 * V_3 ;
T_2 V_51 ;
F_2 ( L_5 ) ;
V_3 = F_12 ( V_21 ) ;
if ( ! V_3 )
return F_26 ( - V_52 ) ;
V_3 -> V_5 = V_53 ;
V_3 -> V_54 = V_50 -> V_55 ;
V_3 -> V_56 = true ;
V_51 = F_4 () ;
V_3 -> V_57 = V_51 ;
V_3 -> V_58 = V_51 ;
F_9 ( L_6 , V_3 ) ;
return V_3 ;
}
static void F_27 ( struct V_2 * V_3 )
{
T_2 V_51 = F_4 () , V_59 ;
V_59 = F_28 ( V_51 , V_60 ) ;
V_3 -> V_59 = V_59 ;
V_3 -> V_61 = V_59 ;
V_3 -> V_62 = V_59 ;
V_3 -> V_63 = V_59 ;
V_3 -> V_30 . V_64 = V_65 + V_66 / 2 ;
F_3 ( V_3 , V_67 , V_51 ) ;
}
struct V_2 * F_29 ( struct V_8 * V_9 ,
struct V_68 * V_69 ,
struct V_49 * V_50 ,
unsigned long V_10 ,
T_1 V_21 )
{
struct V_2 * V_3 , * V_70 ;
struct V_11 * V_71 , * * V_72 ;
const void * V_73 = F_30 ( 0 ) ;
int V_74 ;
F_2 ( L_2 , V_9 , V_10 ) ;
V_3 = F_25 ( V_50 , V_21 ) ;
if ( F_31 ( V_3 ) ) {
F_9 ( L_7 , F_32 ( V_3 ) ) ;
return V_3 ;
}
F_33 ( V_3 , V_75 , F_11 ( & V_3 -> V_20 ) ,
V_73 , ( const void * ) V_10 ) ;
F_34 ( & V_9 -> V_13 ) ;
V_72 = & V_9 -> V_14 . V_11 ;
V_71 = NULL ;
while ( * V_72 ) {
V_71 = * V_72 ;
V_70 = F_7 ( V_71 , struct V_2 , V_15 ) ;
if ( V_10 < V_70 -> V_10 )
V_72 = & ( * V_72 ) -> V_16 ;
else if ( V_10 > V_70 -> V_10 )
V_72 = & ( * V_72 ) -> V_17 ;
else
goto V_76;
}
F_35 ( V_3 -> V_77 , V_9 ) ;
V_3 -> V_10 = V_10 ;
F_36 ( V_78 , & V_3 -> V_79 ) ;
F_10 ( V_3 , V_80 ) ;
F_37 ( & V_3 -> V_15 , V_71 , V_72 ) ;
F_38 ( & V_3 -> V_15 , & V_9 -> V_14 ) ;
F_39 ( & V_3 -> V_37 , & V_9 -> V_81 ) ;
F_40 ( & V_9 -> V_13 ) ;
F_34 ( & V_82 ) ;
F_41 ( & V_3 -> V_33 , & V_83 ) ;
F_40 ( & V_82 ) ;
V_74 = F_42 ( V_3 , V_69 , V_50 , V_21 ) ;
if ( V_74 < 0 )
goto error;
F_33 ( V_3 , V_84 , F_11 ( & V_3 -> V_20 ) ,
V_73 , NULL ) ;
F_43 ( & V_3 -> V_85 -> V_86 . V_87 -> V_39 ) ;
F_44 ( & V_3 -> V_88 ,
& V_3 -> V_85 -> V_86 . V_87 -> V_89 ) ;
F_45 ( & V_3 -> V_85 -> V_86 . V_87 -> V_39 ) ;
F_27 ( V_3 ) ;
F_46 ( L_8 , V_3 -> V_4 , V_3 -> V_85 -> V_4 ) ;
F_9 ( L_9 , V_3 ) ;
return V_3 ;
V_76:
F_40 ( & V_9 -> V_13 ) ;
V_74 = - V_90 ;
error:
F_47 ( V_3 , V_91 ,
V_92 , V_74 ) ;
F_33 ( V_3 , V_93 , F_11 ( & V_3 -> V_20 ) ,
V_73 , F_26 ( V_74 ) ) ;
F_48 ( V_9 , V_3 ) ;
F_49 ( V_3 , V_94 ) ;
F_9 ( L_10 , V_74 ) ;
return F_26 ( V_74 ) ;
}
void F_50 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
struct V_25 * V_95 )
{
struct V_96 * V_85 = V_3 -> V_85 ;
struct V_97 * V_98 = F_51 ( V_95 ) ;
T_3 V_99 ;
F_2 ( L_11 , V_3 -> V_85 -> V_4 ) ;
F_35 ( V_3 -> V_77 , V_9 ) ;
V_3 -> V_100 = V_98 -> V_101 . V_102 ;
V_3 -> V_54 = V_98 -> V_101 . V_103 ;
V_3 -> V_104 = V_98 -> V_101 . V_104 ;
V_3 -> V_5 = V_105 ;
if ( V_98 -> V_101 . V_106 > 0 )
V_3 -> V_5 = V_107 ;
V_3 -> V_58 = V_95 -> V_108 ;
V_99 = V_98 -> V_101 . V_104 & V_109 ;
V_85 -> V_110 [ V_99 ] . V_111 = V_3 -> V_100 ;
V_85 -> V_110 [ V_99 ] . V_100 = V_3 -> V_100 ;
F_35 ( V_85 -> V_110 [ V_99 ] . V_3 , V_3 ) ;
F_52 ( & V_85 -> V_86 . V_87 -> V_39 ) ;
F_44 ( & V_3 -> V_88 , & V_85 -> V_86 . V_87 -> V_89 ) ;
F_53 ( & V_85 -> V_86 . V_87 -> V_39 ) ;
F_46 ( L_12 , V_3 -> V_4 , V_3 -> V_85 -> V_4 ) ;
F_27 ( V_3 ) ;
F_9 ( L_5 ) ;
}
bool F_54 ( struct V_2 * V_3 )
{
const void * V_73 = F_30 ( 0 ) ;
int V_112 = F_55 ( & V_3 -> V_20 , 1 , 0 ) ;
if ( V_112 == 0 )
return false ;
if ( F_56 ( & V_3 -> V_31 ) )
F_33 ( V_3 , V_113 , V_112 + 1 , V_73 , NULL ) ;
else
F_49 ( V_3 , V_114 ) ;
return true ;
}
bool F_57 ( struct V_2 * V_3 )
{
const void * V_73 = F_30 ( 0 ) ;
int V_112 = F_11 ( & V_3 -> V_20 ) ;
F_58 ( V_112 , >= , 1 ) ;
if ( F_56 ( & V_3 -> V_31 ) )
F_33 ( V_3 , V_115 , V_112 , V_73 , NULL ) ;
else
F_49 ( V_3 , V_114 ) ;
return true ;
}
void F_59 ( struct V_2 * V_3 )
{
const void * V_73 = F_30 ( 0 ) ;
if ( V_3 ) {
int V_112 = F_11 ( & V_3 -> V_20 ) ;
F_33 ( V_3 , V_116 , V_112 , V_73 , NULL ) ;
}
}
void F_10 ( struct V_2 * V_3 , enum V_117 V_118 )
{
const void * V_73 = F_30 ( 0 ) ;
int V_112 = F_22 ( & V_3 -> V_20 ) ;
F_33 ( V_3 , V_118 , V_112 , V_73 , NULL ) ;
}
void F_48 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
const void * V_73 = F_30 ( 0 ) ;
struct V_96 * V_85 = V_3 -> V_85 ;
bool V_119 = false ;
int V_120 ;
F_2 ( L_13 , V_3 -> V_4 , F_11 ( & V_3 -> V_20 ) ) ;
F_33 ( V_3 , V_121 , F_11 ( & V_3 -> V_20 ) ,
V_73 , ( const void * ) V_3 -> V_79 ) ;
F_58 ( V_3 -> V_5 , == , V_6 ) ;
F_43 ( & V_3 -> V_39 ) ;
if ( F_60 ( V_122 , & V_3 -> V_79 ) )
F_61 () ;
F_45 ( & V_3 -> V_39 ) ;
F_62 ( & V_3 -> V_30 ) ;
F_63 ( & V_9 -> V_123 ) ;
if ( ! F_64 ( & V_3 -> V_36 ) ) {
F_65 ( L_14 ,
V_3 , V_3 -> V_124 , V_3 -> V_79 ) ;
F_66 ( & V_3 -> V_36 ) ;
V_119 = true ;
}
V_3 -> V_36 . V_125 = NULL ;
V_3 -> V_36 . V_126 = NULL ;
F_67 ( & V_9 -> V_123 ) ;
if ( V_119 )
F_49 ( V_3 , V_94 ) ;
F_34 ( & V_9 -> V_13 ) ;
if ( F_68 ( V_78 , & V_3 -> V_79 ) ) {
F_69 ( & V_3 -> V_15 , & V_9 -> V_14 ) ;
memset ( & V_3 -> V_15 , 0xdd , sizeof( V_3 -> V_15 ) ) ;
F_49 ( V_3 , V_127 ) ;
}
F_66 ( & V_3 -> V_37 ) ;
F_40 ( & V_9 -> V_13 ) ;
F_65 ( L_15 , V_3 , V_3 -> V_4 , V_85 ) ;
if ( V_85 )
F_70 ( V_3 ) ;
for ( V_120 = 0 ; V_120 < V_24 ; V_120 ++ ) {
F_71 ( V_3 -> V_23 [ V_120 ] ,
( V_3 -> V_56 ? V_128 :
V_129 ) ) ;
V_3 -> V_23 [ V_120 ] = NULL ;
}
F_9 ( L_5 ) ;
}
void F_72 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
F_2 ( L_16 , V_9 ) ;
while ( ! F_64 ( & V_9 -> V_130 ) ) {
V_3 = F_73 ( V_9 -> V_130 . V_125 ,
struct V_2 , V_35 ) ;
F_66 ( & V_3 -> V_35 ) ;
F_74 ( L_17 , V_3 , 0 , V_92 , V_131 ) ;
F_49 ( V_3 , V_94 ) ;
}
while ( ! F_64 ( & V_9 -> V_81 ) ) {
V_3 = F_73 ( V_9 -> V_81 . V_125 ,
struct V_2 , V_37 ) ;
F_10 ( V_3 , V_19 ) ;
F_74 ( L_18 , V_3 , 0 , V_92 , V_131 ) ;
F_75 ( V_3 ) ;
F_48 ( V_9 , V_3 ) ;
F_49 ( V_3 , V_94 ) ;
}
F_9 ( L_5 ) ;
}
void F_49 ( struct V_2 * V_3 , enum V_117 V_118 )
{
const void * V_73 = F_30 ( 0 ) ;
int V_112 ;
ASSERT ( V_3 != NULL ) ;
V_112 = F_76 ( & V_3 -> V_20 ) ;
F_33 ( V_3 , V_118 , V_112 , V_73 , NULL ) ;
F_58 ( V_112 , >= , 0 ) ;
if ( V_112 == 0 ) {
F_65 ( L_19 , V_3 -> V_4 ) ;
F_58 ( V_3 -> V_5 , == , V_6 ) ;
F_34 ( & V_82 ) ;
F_77 ( & V_3 -> V_33 ) ;
F_40 ( & V_82 ) ;
F_78 ( V_3 ) ;
}
}
static void F_79 ( struct V_132 * V_133 )
{
struct V_2 * V_3 = F_80 ( V_133 , struct V_2 , V_133 ) ;
F_81 ( V_3 -> V_87 ) ;
F_23 ( V_3 -> V_23 ) ;
F_23 ( V_3 -> V_27 ) ;
F_24 ( V_22 , V_3 ) ;
}
void F_78 ( struct V_2 * V_3 )
{
int V_120 ;
F_46 ( L_20 , V_3 -> V_4 ) ;
memset ( & V_3 -> V_15 , 0xcd , sizeof( V_3 -> V_15 ) ) ;
F_62 ( & V_3 -> V_30 ) ;
F_58 ( V_3 -> V_5 , == , V_6 ) ;
ASSERT ( F_82 ( V_122 , & V_3 -> V_79 ) ) ;
F_58 ( V_3 -> V_85 , == , NULL ) ;
for ( V_120 = 0 ; V_120 < V_24 ; V_120 ++ )
F_71 ( V_3 -> V_23 [ V_120 ] ,
( V_3 -> V_56 ? V_128 :
V_129 ) ) ;
F_71 ( V_3 -> V_134 , V_128 ) ;
F_83 ( & V_3 -> V_133 , F_79 ) ;
}
void T_4 F_84 ( void )
{
struct V_2 * V_3 ;
F_2 ( L_5 ) ;
if ( F_64 ( & V_83 ) )
return;
F_34 ( & V_82 ) ;
while ( ! F_64 ( & V_83 ) ) {
V_3 = F_73 ( V_83 . V_125 , struct V_2 , V_33 ) ;
F_65 ( L_21 , V_3 ) ;
F_59 ( V_3 ) ;
F_77 ( & V_3 -> V_33 ) ;
F_85 ( L_22 ,
V_3 , F_11 ( & V_3 -> V_20 ) ,
V_135 [ V_3 -> V_5 ] ,
V_3 -> V_79 , V_3 -> V_124 ) ;
F_40 ( & V_82 ) ;
F_86 () ;
F_34 ( & V_82 ) ;
}
F_40 ( & V_82 ) ;
}
