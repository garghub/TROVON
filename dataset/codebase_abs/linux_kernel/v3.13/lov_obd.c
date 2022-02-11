static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_4 ( & V_4 -> V_6 ) ;
return;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
F_2 ( & V_4 -> V_6 ) ;
if ( F_6 ( & V_4 -> V_7 ) && V_4 -> V_8 ) {
F_7 ( V_9 ) ;
int V_10 ;
struct V_11 * V_12 , * V_13 ;
F_8 ( V_14 , L_1 ,
V_4 -> V_8 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 || ! V_12 -> V_18 )
continue;
F_9 ( & V_12 -> V_19 , & V_9 ) ;
F_10 ( & V_4 -> V_20 , V_10 ) ;
V_4 -> V_17 [ V_10 ] = NULL ;
V_4 -> V_8 -- ;
}
F_4 ( & V_4 -> V_6 ) ;
F_11 (tgt, n, &kill, ltd_kill) {
F_12 ( & V_12 -> V_19 ) ;
F_13 ( V_2 , V_12 ) ;
}
} else {
F_4 ( & V_4 -> V_6 ) ;
}
}
int F_14 ( struct V_1 * V_2 , T_1 V_21 , int V_22 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_25 * V_26 ;
struct V_1 * V_27 ;
static struct V_25 V_28 = { L_2 } ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_33 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_34 ;
V_26 = & V_4 -> V_17 [ V_21 ] -> V_35 ;
V_27 = V_4 -> V_17 [ V_21 ] -> V_36 ;
if ( ! V_27 -> V_37 ) {
F_15 ( L_3 , F_16 ( V_26 ) ) ;
return - V_34 ;
}
V_27 -> V_5 . V_38 . V_39 = V_4 -> V_40 ;
if ( V_24 && ( V_24 -> V_41 & V_42 ) )
V_24 -> V_43 = V_21 ;
V_30 = V_27 -> V_5 . V_38 . V_44 ;
if ( V_22 ) {
V_27 -> V_45 = 0 ;
F_17 ( V_30 ) ;
}
V_33 = F_18 ( V_27 , V_2 ) ;
if ( V_33 ) {
F_15 ( L_4 ,
F_16 ( V_26 ) , V_33 ) ;
return V_33 ;
}
if ( V_30 -> V_46 ) {
F_8 ( V_14 , L_5
L_6 , F_16 ( V_26 ) ) ;
return 0 ;
}
V_33 = F_19 ( NULL , & V_4 -> V_17 [ V_21 ] -> V_47 , V_27 ,
& V_28 , V_24 , NULL ) ;
if ( V_33 || ! V_4 -> V_17 [ V_21 ] -> V_47 ) {
F_15 ( L_7 ,
F_16 ( V_26 ) , V_33 ) ;
return - V_48 ;
}
V_4 -> V_17 [ V_21 ] -> V_18 = 0 ;
F_8 ( V_14 , L_8 , V_21 ,
F_16 ( V_26 ) , V_27 -> V_49 , V_22 ? L_9 : L_10 ) ;
V_32 = V_2 -> V_50 ;
if ( V_32 ) {
struct V_1 * V_51 = V_4 -> V_17 [ V_21 ] -> V_47 -> V_52 ;
struct V_31 * V_53 ;
F_20 ( V_51 != NULL ) ;
F_20 ( V_51 -> V_54 == V_55 ) ;
F_20 ( V_51 -> V_56 -> V_57 != NULL ) ;
V_53 = F_21 ( V_51 -> V_49 ,
V_32 ,
L_11 ,
V_51 -> V_56 -> V_57 ,
V_51 -> V_49 ) ;
if ( V_53 == NULL ) {
F_15 ( L_12
L_13 ,
V_2 -> V_56 -> V_57 , V_2 -> V_49 ,
V_51 -> V_49 ) ;
F_22 ( & V_32 ) ;
V_2 -> V_50 = NULL ;
}
}
return 0 ;
}
static int F_23 ( const struct V_58 * V_59 ,
struct V_60 * * exp , struct V_1 * V_2 ,
struct V_25 * V_61 , struct V_23 * V_24 ,
void * V_62 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
struct V_63 V_64 ;
int V_10 , V_33 ;
F_8 ( V_14 , L_14 , V_4 -> V_65 ) ;
V_33 = F_24 ( & V_64 , V_2 , V_61 ) ;
if ( V_33 )
return V_33 ;
* exp = F_25 ( & V_64 ) ;
V_4 -> V_65 ++ ;
F_20 ( V_4 -> V_65 == 1 ) ;
memset ( & V_4 -> V_66 , 0 , sizeof( V_4 -> V_66 ) ) ;
if ( V_24 )
V_4 -> V_66 = * V_24 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 || F_27 ( & V_12 -> V_35 ) )
continue;
V_33 = F_14 ( V_2 , V_10 , V_12 -> V_67 , & V_4 -> V_66 ) ;
if ( V_33 ) {
F_15 ( L_15 ,
V_2 -> V_49 , V_10 , V_33 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_33 = F_28 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_47 -> V_52 ,
V_68 , ( void * ) & V_10 ) ;
if ( V_33 ) {
F_15 ( L_16 ,
V_2 -> V_49 , V_33 ) ;
}
}
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_31 * V_32 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_1 * V_51 ;
int V_33 ;
V_51 = F_31 ( V_12 -> V_47 ) ;
F_8 ( V_14 , L_17 ,
V_2 -> V_49 , V_51 -> V_49 ) ;
if ( V_12 -> V_69 ) {
V_12 -> V_69 = 0 ;
V_4 -> V_15 . V_70 -- ;
V_12 -> V_47 -> V_52 -> V_71 = 1 ;
}
V_32 = V_2 -> V_50 ;
if ( V_32 )
F_32 ( V_51 -> V_49 , V_32 ) ;
if ( V_51 ) {
V_51 -> V_72 = V_2 -> V_72 ;
V_51 -> V_73 = V_2 -> V_73 ;
V_51 -> V_45 = V_2 -> V_45 ;
}
F_18 ( V_51 , NULL ) ;
V_33 = F_33 ( V_12 -> V_47 ) ;
if ( V_33 ) {
F_15 ( L_18 ,
V_12 -> V_35 . V_74 , V_33 ) ;
V_33 = 0 ;
}
V_12 -> V_47 = NULL ;
return 0 ;
}
static int F_34 ( struct V_60 * exp )
{
struct V_1 * V_2 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_33 ;
if ( ! V_4 -> V_17 )
goto V_75;
V_4 -> V_65 -- ;
if ( V_4 -> V_65 != 0 ) {
F_15 ( L_19 , V_4 -> V_65 ) ;
goto V_75;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( V_4 -> V_17 [ V_10 ] && V_4 -> V_17 [ V_10 ] -> V_47 ) {
F_35 ( V_2 , V_10 , 0 , V_4 -> V_17 [ V_10 ] -> V_76 ) ;
}
}
F_29 ( V_2 ) ;
V_75:
V_33 = F_36 ( exp ) ;
return V_33 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_25 * V_74 ,
enum V_77 V_78 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
int V_21 , V_22 , V_79 ;
F_8 ( V_80 , L_20 ,
V_4 , V_74 -> V_74 , V_78 ) ;
F_26 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_15 . V_16 ; V_21 ++ ) {
V_12 = V_4 -> V_17 [ V_21 ] ;
if ( ! V_12 )
continue;
if ( V_78 == V_81 && V_12 -> V_47 == NULL &&
F_38 ( V_74 , & V_12 -> V_35 ) ) {
struct V_25 V_28 = { L_2 } ;
F_19 ( NULL , & V_12 -> V_47 , V_12 -> V_36 ,
& V_28 , & V_4 -> V_66 , NULL ) ;
}
if ( ! V_12 -> V_47 )
continue;
F_8 ( V_80 , L_21 V_82 L_22 ,
V_21 , F_16 ( & V_12 -> V_35 ) ,
V_12 -> V_47 -> V_83 . V_84 ) ;
if ( F_38 ( V_74 , & V_12 -> V_35 ) )
break;
}
if ( V_21 == V_4 -> V_15 . V_16 )
GOTO ( V_75 , V_21 = - V_34 ) ;
if ( V_78 == V_85 || V_78 == V_81 ) {
V_22 = ( V_78 == V_81 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_67 == V_22 ) {
F_8 ( V_80 , L_23 ,
V_74 -> V_74 , V_22 ? L_9 : L_24 ) ;
} else {
V_4 -> V_17 [ V_21 ] -> V_67 = V_22 ;
F_8 ( V_14 , L_25 ,
V_22 ? L_9 : L_24 , F_16 ( V_74 ) ) ;
}
} else if ( V_78 == V_86 || V_78 == V_87 ) {
V_79 = ( V_78 == V_87 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_69 == V_79 ) {
F_8 ( V_80 , L_26 ,
V_74 -> V_74 , V_79 ? L_9 : L_10 ) ;
GOTO ( V_75 , V_21 ) ;
} else {
F_8 ( V_14 , L_27 ,
F_16 ( V_74 ) , V_79 ? L_9 : L_10 ) ;
}
V_4 -> V_17 [ V_21 ] -> V_69 = V_79 ;
if ( V_79 ) {
V_4 -> V_15 . V_70 ++ ;
V_4 -> V_17 [ V_21 ] -> V_47 -> V_52 -> V_71 = 0 ;
} else {
V_4 -> V_15 . V_70 -- ;
V_4 -> V_17 [ V_21 ] -> V_47 -> V_52 -> V_71 = 1 ;
}
} else {
F_15 ( L_28 , V_78 , V_74 -> V_74 ) ;
}
V_75:
F_29 ( V_2 ) ;
return V_21 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_1 * V_88 ,
enum V_77 V_78 , void * V_24 )
{
int V_33 = 0 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
F_39 ( & V_4 -> V_89 ) ;
if ( ! V_4 -> V_65 ) {
F_40 ( & V_4 -> V_89 ) ;
return V_33 ;
}
if ( V_78 == V_87 || V_78 == V_86 ||
V_78 == V_81 || V_78 == V_85 ) {
struct V_25 * V_74 ;
F_20 ( V_88 ) ;
if ( strcmp ( V_88 -> V_56 -> V_57 , V_90 ) ) {
F_40 ( & V_4 -> V_89 ) ;
F_15 ( L_29 ,
V_88 -> V_56 -> V_57 ,
V_88 -> V_49 ) ;
return - V_34 ;
}
V_74 = & V_88 -> V_5 . V_38 . V_91 ;
V_33 = F_37 ( V_2 , V_74 , V_78 ) ;
if ( V_33 < 0 ) {
F_40 ( & V_4 -> V_89 ) ;
F_15 ( L_30 , V_78 ,
F_16 ( V_74 ) , V_33 ) ;
return V_33 ;
}
V_24 = & V_33 ;
}
if ( V_88 ) {
V_33 = F_41 ( V_2 , V_88 , V_78 , V_24 ) ;
} else {
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_92 ;
V_24 = & V_10 ;
V_92 = ( V_78 == V_93 ) ||
( V_78 == V_94 ) ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_92 && ! V_4 -> V_17 [ V_10 ] -> V_69 )
continue;
V_33 = F_41 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_36 ,
V_78 , V_24 ) ;
if ( V_33 ) {
F_15 ( L_31 ,
V_2 -> V_49 ,
V_2 -> V_95 -> V_49 ,
V_4 -> V_17 [ V_10 ] -> V_36 -> V_49 ,
V_33 ) ;
}
}
F_29 ( V_2 ) ;
}
F_40 ( & V_4 -> V_89 ) ;
return V_33 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_25 * V_96 ,
T_1 V_21 , int V_97 , int V_79 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
struct V_1 * V_27 ;
int V_33 ;
F_8 ( V_14 , L_32 ,
V_96 -> V_74 , V_21 , V_97 , V_79 ) ;
if ( V_97 <= 0 ) {
F_15 ( L_33 ,
V_96 -> V_74 , V_97 ) ;
return - V_34 ;
}
V_27 = F_43 ( V_96 , V_90 ,
& V_2 -> V_25 ) ;
if ( V_27 == NULL )
return - V_34 ;
F_2 ( & V_4 -> V_6 ) ;
if ( ( V_21 < V_4 -> V_98 ) && ( V_4 -> V_17 [ V_21 ] != NULL ) ) {
V_12 = V_4 -> V_17 [ V_21 ] ;
F_15 ( L_34 ,
F_16 ( & V_12 -> V_35 ) , V_21 ) ;
F_4 ( & V_4 -> V_6 ) ;
return - V_99 ;
}
if ( V_21 >= V_4 -> V_98 ) {
struct V_11 * * V_100 , * * V_101 = NULL ;
T_1 V_102 , V_103 = 0 ;
V_102 = F_44 ( T_1 , V_4 -> V_98 , 2 ) ;
while ( V_102 < V_21 + 1 )
V_102 = V_102 << 1 ;
F_45 ( V_100 , sizeof( * V_100 ) * V_102 ) ;
if ( V_100 == NULL ) {
F_4 ( & V_4 -> V_6 ) ;
return - V_104 ;
}
if ( V_4 -> V_98 ) {
memcpy ( V_100 , V_4 -> V_17 , sizeof( * V_100 ) *
V_4 -> V_98 ) ;
V_101 = V_4 -> V_17 ;
V_103 = V_4 -> V_98 ;
}
V_4 -> V_17 = V_100 ;
V_4 -> V_98 = V_102 ;
F_46 () ;
if ( V_101 )
F_47 ( V_101 , sizeof( * V_101 ) * V_103 ) ;
F_8 ( V_14 , L_35 ,
V_4 -> V_17 , V_4 -> V_98 ) ;
}
F_48 ( V_12 ) ;
if ( ! V_12 ) {
F_4 ( & V_4 -> V_6 ) ;
return - V_104 ;
}
V_33 = F_49 ( & V_4 -> V_20 , V_21 , V_4 -> V_98 ) ;
if ( V_33 ) {
F_4 ( & V_4 -> V_6 ) ;
F_50 ( V_12 ) ;
return V_33 ;
}
V_12 -> V_35 = * V_96 ;
V_12 -> V_36 = V_27 ;
V_12 -> V_76 = V_97 ;
V_12 -> V_105 = V_21 ;
V_12 -> V_67 = V_79 ;
V_4 -> V_17 [ V_21 ] = V_12 ;
if ( V_21 >= V_4 -> V_15 . V_16 )
V_4 -> V_15 . V_16 = V_21 + 1 ;
F_4 ( & V_4 -> V_6 ) ;
F_8 ( V_14 , L_36 ,
V_21 , V_12 -> V_76 , V_4 -> V_15 . V_16 ) ;
V_33 = F_51 ( V_2 , V_27 , V_106 , & V_21 ) ;
if ( V_4 -> V_65 == 0 ) {
return 0 ;
}
F_26 ( V_2 ) ;
V_33 = F_14 ( V_2 , V_21 , V_79 , & V_4 -> V_66 ) ;
if ( V_33 )
GOTO ( V_75 , V_33 ) ;
if ( ! V_12 -> V_47 )
GOTO ( V_75 , V_33 = 0 ) ;
if ( V_4 -> V_107 != NULL ) {
V_33 = F_52 ( NULL , V_12 -> V_47 ,
sizeof( V_108 ) , V_108 ,
sizeof( struct V_109 ) , V_4 -> V_107 ,
NULL ) ;
if ( V_33 < 0 )
GOTO ( V_75 , V_33 ) ;
}
V_33 = F_28 ( V_2 , V_12 -> V_47 -> V_52 ,
V_79 ? V_68 : V_86 ,
( void * ) & V_21 ) ;
V_75:
if ( V_33 ) {
F_15 ( L_37 , V_33 ,
F_16 ( & V_12 -> V_35 ) ) ;
F_35 ( V_2 , V_21 , 0 , 0 ) ;
}
F_29 ( V_2 ) ;
return V_33 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_21 ,
struct V_25 * V_96 , int V_97 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_110 = V_4 -> V_15 . V_16 ;
int V_33 = 0 ;
if ( V_21 >= V_110 ) {
F_15 ( L_38 ,
V_21 , V_110 ) ;
return - V_34 ;
}
F_53 ( & V_4 -> V_89 ) ;
F_26 ( V_2 ) ;
if ( ! V_4 -> V_17 [ V_21 ] ) {
F_15 ( L_39 , V_21 ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
if ( V_96 && ! F_38 ( V_96 , & V_4 -> V_17 [ V_21 ] -> V_35 ) ) {
F_15 ( L_40 ,
F_54 ( V_4 , V_21 ) , V_21 ,
F_16 ( V_96 ) ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
F_8 ( V_14 , L_41 ,
F_54 ( V_4 , V_21 ) , V_21 ,
V_4 -> V_17 [ V_21 ] -> V_76 , V_4 -> V_17 [ V_21 ] -> V_47 ,
V_4 -> V_17 [ V_21 ] -> V_69 ) ;
V_4 -> V_17 [ V_21 ] -> V_18 = 1 ;
V_4 -> V_8 ++ ;
V_75:
F_29 ( V_2 ) ;
F_55 ( & V_4 -> V_89 ) ;
return V_33 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_1 * V_51 ;
F_20 ( V_12 ) ;
F_20 ( V_12 -> V_18 ) ;
V_51 = F_31 ( V_12 -> V_47 ) ;
F_8 ( V_14 , L_42 ,
V_12 -> V_35 . V_74 ,
V_51 ? V_51 -> V_49 : L_43 ) ;
if ( V_12 -> V_47 )
F_30 ( V_2 , V_12 ) ;
F_50 ( V_12 ) ;
if ( V_51 )
F_56 ( V_51 ) ;
}
void F_57 ( T_2 * V_111 )
{
if ( * V_111 < V_112 ) {
if ( * V_111 != 0 )
F_58 ( L_44
L_45 ,
V_113 ) ;
* V_111 = V_113 ;
} else if ( * V_111 & ( V_112 - 1 ) ) {
* V_111 &= ~ ( V_112 - 1 ) ;
F_59 ( L_46 V_114 L_47
L_48 ,
* V_111 , V_112 ) ;
}
}
void F_60 ( T_1 * V_111 )
{
if ( * V_111 == 0 )
* V_111 = 1 ;
}
void F_61 ( T_1 * V_111 )
{
if ( ( * V_111 != 0 ) && ( * V_111 != V_115 ) ) {
F_59 ( L_49 , * V_111 ) ;
* V_111 = 0 ;
}
}
void F_62 ( T_1 * V_111 )
{
if ( * V_111 == 0 )
* V_111 = V_116 ;
}
void F_63 ( struct V_117 * V_15 )
{
F_57 ( & V_15 -> V_118 ) ;
F_60 ( & V_15 -> V_119 ) ;
F_61 ( & V_15 -> V_120 ) ;
F_62 ( & V_15 -> V_121 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
struct V_124 V_125 = { 0 } ;
struct V_117 * V_15 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_33 ;
if ( F_65 ( V_123 , 1 ) < 1 ) {
F_15 ( L_50 ) ;
return - V_34 ;
}
V_15 = (struct V_117 * ) F_66 ( V_123 , 1 ) ;
if ( sizeof( * V_15 ) > F_65 ( V_123 , 1 ) ) {
F_15 ( L_51 ,
( int ) sizeof( * V_15 ) , F_65 ( V_123 , 1 ) ) ;
return - V_34 ;
}
if ( V_15 -> V_126 != V_127 ) {
if ( V_15 -> V_126 == F_67 ( V_127 ) ) {
F_8 ( V_128 , L_52 ,
V_2 -> V_49 , V_15 ) ;
F_68 ( V_15 ) ;
} else {
F_15 ( L_53 ,
V_2 -> V_49 , V_15 -> V_126 ) ;
return - V_34 ;
}
}
F_63 ( V_15 ) ;
V_15 -> V_70 = 0 ;
V_4 -> V_15 = * V_15 ;
V_4 -> V_98 = 0 ;
F_69 ( & V_4 -> V_6 ) ;
F_70 ( & V_4 -> V_7 , 0 ) ;
V_4 -> V_40 = V_129 ;
F_71 ( & V_4 -> V_89 ) ;
V_4 -> V_130 = F_72 ( L_54 , V_131 ,
V_132 ,
V_133 , 0 ,
V_134 ,
V_135 ,
& V_136 ,
V_137 ) ;
F_73 ( & V_4 -> V_138 ) ;
V_4 -> V_139 = 0 ;
V_33 = F_74 ( & V_4 -> V_20 , 0 ) ;
if ( V_33 )
GOTO ( V_75 , V_33 ) ;
F_75 ( & V_125 ) ;
F_76 ( V_2 , V_125 . V_140 ) ;
#ifdef F_77
{
int V_141 ;
V_141 = F_78 ( V_2 -> V_142 , L_55 ,
0444 , & V_143 , V_2 ) ;
if ( V_141 )
F_79 ( L_56 ) ;
}
#endif
V_4 -> V_144 = F_80 ( L_57 ,
V_2 -> V_142 ,
NULL , NULL ) ;
return 0 ;
V_75:
return V_33 ;
}
static int F_81 ( struct V_1 * V_2 , enum V_145 V_146 )
{
int V_33 = 0 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
switch ( V_146 ) {
case V_147 : {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_69 )
continue;
F_82 ( F_31 ( V_4 -> V_17 [ V_10 ] -> V_47 ) ,
V_147 ) ;
}
break;
}
case V_148 :
V_33 = F_83 ( V_2 , 0 ) ;
if ( V_33 != 0 )
F_15 ( L_58 ) ;
break;
}
return V_33 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_149 * V_150 , * V_151 ;
struct V_152 * V_153 ;
F_85 (pos, tmp, &lov->lov_pool_list) {
V_153 = F_86 ( V_150 , struct V_152 , V_154 ) ;
F_8 ( V_80 , L_59 , V_153 ) ;
F_87 ( V_2 , V_153 -> V_155 ) ;
}
F_88 ( V_4 -> V_130 ) ;
F_89 ( & V_4 -> V_20 ) ;
F_90 ( V_2 ) ;
if ( V_4 -> V_17 ) {
int V_10 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_4 -> V_17 [ V_10 ] -> V_69 ||
F_91 ( & V_4 -> V_7 ) )
F_15 ( L_60
L_61 ,
V_10 , V_4 -> V_8 ,
F_91 ( & V_4 -> V_7 ) ) ;
F_35 ( V_2 , V_10 , 0 , 0 ) ;
}
F_29 ( V_2 ) ;
F_47 ( V_4 -> V_17 , sizeof( * V_4 -> V_17 ) *
V_4 -> V_98 ) ;
V_4 -> V_98 = 0 ;
}
return 0 ;
}
int F_92 ( struct V_1 * V_2 , struct V_122 * V_123 ,
T_1 * V_156 , int * V_157 )
{
struct V_25 V_25 ;
int V_158 ;
int V_33 = 0 ;
switch ( V_158 = V_123 -> V_159 ) {
case V_160 :
case V_161 :
case V_162 : {
T_1 V_21 ;
int V_97 ;
if ( F_65 ( V_123 , 1 ) > sizeof( V_25 . V_74 ) )
GOTO ( V_75 , V_33 = - V_34 ) ;
F_93 ( & V_25 , F_66 ( V_123 , 1 ) ) ;
if ( sscanf ( F_66 ( V_123 , 2 ) , L_62 , V_156 ) != 1 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( sscanf ( F_66 ( V_123 , 3 ) , L_62 , V_157 ) != 1 )
GOTO ( V_75 , V_33 = - V_34 ) ;
V_21 = * V_156 ;
V_97 = * V_157 ;
if ( V_158 == V_160 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_97 , 1 ) ;
else if ( V_158 == V_161 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_97 , 0 ) ;
else
V_33 = F_35 ( V_2 , V_21 , & V_25 , V_97 ) ;
GOTO ( V_75 , V_33 ) ;
}
case V_163 : {
struct V_124 V_125 = { 0 } ;
struct V_117 * V_15 = & ( V_2 -> V_5 . V_4 . V_15 ) ;
if ( ! V_15 )
GOTO ( V_75 , V_33 = - V_34 ) ;
F_75 ( & V_125 ) ;
V_33 = F_94 ( V_164 , V_125 . V_140 ,
V_123 , V_2 ) ;
if ( V_33 > 0 )
V_33 = 0 ;
GOTO ( V_75 , V_33 ) ;
}
case V_165 :
case V_166 :
case V_167 :
case V_168 :
GOTO ( V_75 , V_33 ) ;
default: {
F_15 ( L_63 , V_123 -> V_159 ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
}
V_75:
return V_33 ;
}
static int F_95 ( struct V_60 * exp , struct V_169 * V_170 ,
struct V_171 * * V_172 , struct V_173 * V_174 )
{
struct V_171 * V_175 , * V_176 ;
struct V_3 * V_4 = & exp -> V_52 -> V_5 . V_4 ;
unsigned V_177 ;
int V_33 , V_10 ;
F_20 ( V_170 -> V_178 & V_179 &&
V_170 -> V_180 & V_181 ) ;
F_45 ( V_175 , sizeof( * V_175 ) ) ;
if ( V_175 == NULL )
return - V_104 ;
V_177 = V_170 -> V_182 ;
V_176 = * V_172 ;
if ( V_176 == NULL )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( V_177 >= V_4 -> V_15 . V_16 ||
! V_4 -> V_17 [ V_177 ] )
GOTO ( V_75 , V_33 = - V_34 ) ;
for ( V_10 = 0 ; V_10 < V_176 -> V_183 ; V_10 ++ ) {
if ( V_176 -> V_184 [ V_10 ] -> V_185 == V_177 ) {
if ( F_96 ( & V_176 -> V_184 [ V_10 ] -> V_186 ) !=
F_96 ( & V_170 -> V_187 ) )
GOTO ( V_75 , V_33 = - V_34 ) ;
break;
}
}
if ( V_10 == V_176 -> V_183 )
GOTO ( V_75 , V_33 = - V_34 ) ;
V_33 = F_97 ( NULL , V_4 -> V_17 [ V_177 ] -> V_47 ,
V_170 , & V_175 , V_174 ) ;
V_75:
F_47 ( V_175 , sizeof( * V_175 ) ) ;
return V_33 ;
}
static int F_98 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_169 * V_170 , struct V_171 * * V_172 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_172 != NULL ) ;
if ( exp == NULL )
return - V_34 ;
if ( ( V_170 -> V_178 & V_179 ) &&
V_170 -> V_180 == V_188 ) {
F_99 () ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
if ( ! V_4 -> V_15 . V_70 )
return - V_189 ;
F_26 ( exp -> V_52 ) ;
if ( ( V_170 -> V_178 & V_179 ) &&
( V_170 -> V_180 & V_181 ) ) {
V_33 = F_95 ( exp , V_170 , V_172 , V_174 ) ;
}
F_29 ( exp -> V_52 ) ;
return V_33 ;
}
static int F_100 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_169 * V_190 , struct V_171 * V_176 ,
struct V_173 * V_174 , struct V_60 * V_191 ,
void * V_192 )
{
struct V_193 * V_194 ;
struct V_195 V_196 ;
struct V_197 * V_198 ;
struct V_149 * V_150 ;
struct V_3 * V_4 ;
int V_33 = 0 , V_199 = 0 ;
F_101 ( V_176 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
if ( V_190 -> V_178 & V_200 ) {
F_20 ( V_174 ) ;
F_20 ( V_174 -> V_201 ) ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
F_26 ( exp -> V_52 ) ;
V_33 = F_102 ( exp , & V_196 , V_190 , V_176 , V_174 , & V_194 ) ;
if ( V_33 )
GOTO ( V_75 , V_33 ) ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
if ( V_190 -> V_178 & V_200 )
V_174 -> V_201 = V_194 -> V_203 + V_198 -> V_204 ;
V_199 = F_104 ( V_59 , V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
V_198 -> V_206 . V_207 , NULL , V_174 , NULL , V_192 ) ;
V_199 = F_105 ( V_194 , V_198 , V_199 ) ;
if ( V_199 ) {
F_15 ( L_64 V_208 L_65
V_208 L_66 ,
exp -> V_52 -> V_49 , F_106 ( & V_190 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) ,
V_198 -> V_205 , V_199 ) ;
if ( ! V_33 )
V_33 = V_199 ;
}
}
if ( V_33 == 0 ) {
F_20 ( F_107 ( V_176 -> V_209 ) != NULL ) ;
V_33 = F_107 ( V_176 -> V_209 ) -> F_108 ( V_176 , V_190 , V_191 ) ;
}
V_199 = F_109 ( V_194 ) ;
V_75:
F_29 ( exp -> V_52 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_110 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_195 * V_196 )
{
struct V_193 * V_194 ;
struct V_197 * V_198 ;
struct V_149 * V_150 ;
struct V_3 * V_4 ;
int V_199 = 0 , V_33 = 0 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_210 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_111 ( exp , V_196 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
F_8 ( V_80 , L_67 V_208 L_68 V_208 L_69
L_70 , F_106 ( & V_196 -> V_207 -> V_187 ) , V_198 -> V_204 ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 ) ;
V_33 = F_112 ( V_59 , V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 ) ;
V_199 = F_105 ( V_194 , V_198 , V_33 ) ;
if ( V_199 ) {
F_15 ( L_71 V_208 L_65
V_208 L_66 ,
exp -> V_52 -> V_49 ,
F_106 ( & V_196 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) ,
V_198 -> V_205 , V_199 ) ;
break;
}
}
V_33 = F_113 ( V_194 ) ;
if ( V_199 )
V_33 = V_199 ;
return V_33 ;
}
static int F_114 ( struct V_211 * V_212 ,
void * V_24 , int V_33 )
{
struct V_193 * V_213 = (struct V_193 * ) V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_213 -> V_214 , 0 ) ;
V_199 = F_113 ( V_213 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_115 ( struct V_60 * exp , struct V_195 * V_196 ,
struct V_211 * V_212 )
{
struct V_193 * V_213 ;
struct V_3 * V_4 ;
struct V_149 * V_150 ;
struct V_197 * V_198 ;
int V_33 = 0 , V_199 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_210 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_111 ( exp , V_196 , & V_213 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_67 V_208 L_72 ,
F_106 ( & V_196 -> V_210 -> V_215 ) , V_196 -> V_210 -> V_183 ,
V_196 -> V_210 -> V_216 ) ;
F_103 (pos, &lovset->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
F_8 ( V_80 , L_67 V_208 L_68 V_208 L_69
L_73 , F_106 ( & V_196 -> V_207 -> V_187 ) , V_198 -> V_204 ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 ) ;
V_33 = F_116 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_212 ) ;
if ( V_33 ) {
F_15 ( L_71 V_208 L_74
V_208 L_66 ,
exp -> V_52 -> V_49 ,
F_106 ( & V_196 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) ,
V_198 -> V_205 , V_33 ) ;
GOTO ( V_75 , V_33 ) ;
}
}
if ( ! F_117 ( & V_212 -> V_217 ) ) {
F_20 ( V_33 == 0 ) ;
F_20 ( V_212 -> V_218 == NULL ) ;
V_212 -> V_218 = F_114 ;
V_212 -> V_219 = ( void * ) V_213 ;
return V_33 ;
}
V_75:
if ( V_33 )
F_70 ( & V_213 -> V_214 , 0 ) ;
V_199 = F_113 ( V_213 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_118 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_195 * V_196 , struct V_173 * V_174 )
{
struct V_193 * V_194 ;
struct V_3 * V_4 ;
struct V_149 * V_150 ;
struct V_197 * V_198 ;
int V_199 = 0 , V_33 = 0 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_210 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
F_20 ( ! ( V_196 -> V_207 -> V_178 & ~ ( V_220 | V_221 |
V_222 | V_223 |
V_224 | V_225 |
V_179 | V_226 |
V_227 | V_228 |
V_229 | V_230 |
V_231 ) ) ) ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_119 ( exp , V_196 , V_174 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
V_33 = F_120 ( V_59 , V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , NULL ) ;
V_199 = F_121 ( V_194 , V_198 , V_33 ) ;
if ( V_199 ) {
F_15 ( L_75 V_208 L_65
V_208 L_66 ,
exp -> V_52 -> V_49 ,
F_106 ( & V_194 -> V_232 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 ,
V_199 ) ;
if ( ! V_33 )
V_33 = V_199 ;
}
}
V_199 = F_122 ( V_194 ) ;
if ( ! V_33 )
V_33 = V_199 ;
return V_33 ;
}
static int F_123 ( struct V_211 * V_212 ,
void * V_24 , int V_33 )
{
struct V_193 * V_213 = (struct V_193 * ) V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_213 -> V_214 , 0 ) ;
V_199 = F_122 ( V_213 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_124 ( struct V_60 * exp , struct V_195 * V_196 ,
struct V_173 * V_174 ,
struct V_211 * V_212 )
{
struct V_193 * V_194 ;
struct V_197 * V_198 ;
struct V_149 * V_150 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_210 ) ;
if ( V_196 -> V_207 -> V_178 & V_200 ) {
F_20 ( V_174 ) ;
F_20 ( V_174 -> V_201 ) ;
}
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_119 ( exp , V_196 , V_174 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_67 V_208 L_72 ,
F_106 ( & V_196 -> V_210 -> V_215 ) ,
V_196 -> V_210 -> V_183 ,
V_196 -> V_210 -> V_216 ) ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
if ( V_196 -> V_207 -> V_178 & V_200 )
V_174 -> V_201 = V_194 -> V_203 + V_198 -> V_204 ;
F_8 ( V_80 , L_67 V_208 L_68 V_208 L_69
L_73 , F_106 ( & V_196 -> V_207 -> V_187 ) , V_198 -> V_204 ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 ) ;
V_33 = F_125 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_174 , V_212 ) ;
if ( V_33 ) {
F_15 ( L_76 V_208 L_74
V_208 L_66 ,
F_106 ( & V_194 -> V_232 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) ,
V_198 -> V_205 , V_33 ) ;
break;
}
}
if ( V_33 || ! V_212 || F_117 ( & V_212 -> V_217 ) ) {
int V_199 ;
if ( V_33 )
F_70 ( & V_194 -> V_214 , 0 ) ;
V_199 = F_122 ( V_194 ) ;
return V_33 ? V_33 : V_199 ;
}
F_20 ( V_212 -> V_218 == NULL ) ;
V_212 -> V_218 = F_123 ;
V_212 -> V_219 = ( void * ) V_194 ;
return 0 ;
}
static int F_126 ( struct V_211 * V_212 ,
void * V_24 , int V_33 )
{
struct V_193 * V_213 = (struct V_193 * ) V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_213 -> V_214 , 0 ) ;
V_199 = F_127 ( V_213 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_128 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_195 * V_196 , struct V_173 * V_174 ,
struct V_211 * V_212 )
{
struct V_193 * V_194 ;
struct V_3 * V_4 ;
struct V_149 * V_150 ;
struct V_197 * V_198 ;
int V_33 = 0 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_210 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_129 ( exp , V_196 , V_174 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
V_33 = F_130 ( V_59 , V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , NULL , V_212 ) ;
if ( V_33 ) {
F_15 ( L_77 V_208 L_65 V_208
L_66 ,
exp -> V_52 -> V_49 ,
F_106 ( & V_194 -> V_232 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 , V_33 ) ;
break;
}
}
if ( V_33 || F_117 ( & V_212 -> V_217 ) ) {
int V_199 ;
V_199 = F_127 ( V_194 ) ;
return V_33 ? V_33 : V_199 ;
}
F_20 ( V_212 -> V_218 == NULL ) ;
V_212 -> V_218 = F_126 ;
V_212 -> V_219 = ( void * ) V_194 ;
return 0 ;
}
static int F_131 ( struct V_211 * V_212 ,
void * V_24 , int V_33 )
{
struct V_193 * V_213 = V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_213 -> V_214 , 0 ) ;
V_199 = F_132 ( V_213 ) ;
return V_33 ? : V_199 ;
}
static int F_133 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_195 * V_196 , T_3 V_233 , T_3 V_234 ,
struct V_211 * V_212 )
{
struct V_193 * V_194 = NULL ;
struct V_3 * V_4 ;
struct V_149 * V_150 ;
struct V_197 * V_198 ;
int V_33 = 0 ;
F_101 ( V_196 -> V_210 ) ;
F_20 ( V_212 != NULL ) ;
if ( ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_134 ( exp , V_196 , V_233 , V_234 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_78 V_208 L_79 V_82 L_80 V_82 L_81 ,
F_106 ( & V_194 -> V_232 -> V_207 -> V_187 ) , V_233 , V_234 ) ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
V_33 = F_135 ( V_59 , V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_198 -> V_206 . V_235 . V_236 . V_233 ,
V_198 -> V_206 . V_235 . V_236 . V_234 , V_212 ) ;
if ( V_33 ) {
F_15 ( L_82 V_208 L_65 V_208
L_66 ,
exp -> V_52 -> V_49 ,
F_106 ( & V_194 -> V_232 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 ,
V_33 ) ;
break;
}
}
if ( V_33 || F_117 ( & V_212 -> V_217 ) ) {
int V_199 = F_132 ( V_194 ) ;
return V_33 ? : V_199 ;
}
F_20 ( V_212 -> V_218 == NULL ) ;
V_212 -> V_218 = F_131 ;
V_212 -> V_219 = ( void * ) V_194 ;
return 0 ;
}
static int F_136 ( struct V_3 * V_4 , struct V_195 * V_237 ,
T_4 V_238 , struct V_239 * V_240 )
{
struct V_195 V_196 = { { { 0 } } } ;
int V_10 , V_33 = 0 ;
V_196 . V_207 = V_237 -> V_207 ;
for ( V_10 = 0 ; V_10 < V_238 ; V_10 ++ ) {
int V_241 = F_137 ( V_237 -> V_210 , V_240 [ V_10 ] . V_242 ) ;
int V_243 = V_237 -> V_210 -> V_184 [ V_241 ] -> V_185 ;
T_3 V_233 , V_234 ;
if ( ! F_138 ( V_237 -> V_210 , V_10 , V_240 [ V_10 ] . V_242 ,
V_240 [ V_10 ] . V_242 + V_240 [ V_10 ] . V_110 - 1 ,
& V_233 , & V_234 ) )
continue;
if ( ! V_4 -> V_17 [ V_243 ] || ! V_4 -> V_17 [ V_243 ] -> V_69 ) {
F_8 ( V_244 , L_83 , V_243 ) ;
return - V_189 ;
}
V_33 = F_139 ( V_245 , V_4 -> V_17 [ V_243 ] -> V_47 , & V_196 ,
1 , & V_240 [ V_10 ] , NULL ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_140 ( int V_158 , struct V_60 * exp , struct V_195 * V_196 ,
T_4 V_238 , struct V_239 * V_240 ,
struct V_173 * V_174 )
{
struct V_193 * V_194 ;
struct V_197 * V_198 ;
struct V_149 * V_150 ;
struct V_3 * V_4 = & exp -> V_52 -> V_5 . V_4 ;
int V_199 , V_33 = 0 ;
F_101 ( V_196 -> V_210 ) ;
if ( V_158 == V_245 ) {
V_33 = F_136 ( V_4 , V_196 , V_238 , V_240 ) ;
return V_33 ;
}
V_33 = F_141 ( exp , V_196 , V_238 , V_240 , V_174 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
struct V_60 * V_246 ;
struct V_239 * V_247 ;
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
V_246 = V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ;
V_247 = V_194 -> V_248 + V_198 -> V_249 ;
V_33 = F_139 ( V_158 , V_246 , & V_198 -> V_206 , V_198 -> V_250 ,
V_247 , V_174 ) ;
if ( V_33 )
break;
F_105 ( V_194 , V_198 , V_33 ) ;
}
V_199 = F_142 ( V_194 ) ;
if ( ! V_33 )
V_33 = V_199 ;
return V_33 ;
}
static int F_143 ( struct V_211 * V_212 ,
void * V_24 , int V_33 )
{
struct V_193 * V_213 = (struct V_193 * ) V_24 ;
V_33 = F_144 ( V_213 , V_213 -> V_251 -> V_252 , V_33 , V_212 ) ;
return V_33 ;
}
static int F_145 ( struct V_60 * exp , struct V_195 * V_196 ,
struct V_253 * V_254 ,
struct V_211 * V_212 )
{
T_5 V_255 = V_254 -> V_252 ;
struct V_193 * V_194 ;
struct V_197 * V_198 ;
struct V_149 * V_150 ;
struct V_3 * V_4 ;
T_6 V_33 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_210 ) ;
F_20 ( V_255 == ( V_255 & - V_255 ) ) ;
F_20 ( ( V_196 -> V_256 & V_257 ) == 0 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_146 ( exp , V_196 , V_254 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
V_33 = F_147 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_254 , V_212 ) ;
if ( V_33 != V_258 )
GOTO ( V_75 , V_33 ) ;
}
if ( V_212 && ! F_117 ( & V_212 -> V_217 ) ) {
F_20 ( V_33 == 0 ) ;
F_20 ( V_212 -> V_218 == NULL ) ;
V_212 -> V_218 = F_143 ;
V_212 -> V_219 = ( void * ) V_194 ;
return V_33 ;
}
V_75:
V_33 = F_144 ( V_194 , V_255 , V_33 , V_212 ) ;
return V_33 ;
}
static int F_148 ( struct V_60 * exp ,
struct V_171 * V_176 , T_7 V_259 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
F_101 ( V_176 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_176 -> V_183 ; V_10 ++ ) {
struct V_171 V_260 ;
struct V_237 * V_261 = V_176 -> V_184 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_261 -> V_185 ] ) {
F_8 ( V_244 , L_84 , V_261 -> V_185 ) ;
continue;
}
V_260 . V_215 = V_261 -> V_186 ;
V_260 . V_183 = 0 ;
V_33 = F_149 ( V_4 -> V_17 [ V_261 -> V_185 ] -> V_47 ,
& V_260 , V_259 , V_24 ) ;
}
return V_33 ;
}
static int F_150 ( struct V_60 * exp ,
struct V_171 * V_176 , T_7 V_259 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
F_101 ( V_176 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_176 -> V_183 ; V_10 ++ ) {
struct V_171 V_260 ;
struct V_237 * V_261 = V_176 -> V_184 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_261 -> V_185 ] ) {
F_8 ( V_244 , L_84 , V_261 -> V_185 ) ;
continue;
}
V_260 . V_215 = V_261 -> V_186 ;
V_260 . V_183 = 0 ;
V_33 = F_151 ( V_4 -> V_17 [ V_261 -> V_185 ] -> V_47 ,
& V_260 , V_259 , V_24 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return V_33 ;
}
static int F_152 ( struct V_60 * exp , struct V_171 * V_176 ,
T_1 V_255 , struct V_63 * V_262 )
{
struct V_193 * V_194 ;
struct V_195 V_196 ;
struct V_197 * V_198 ;
struct V_149 * V_150 ;
struct V_3 * V_4 ;
struct V_63 * V_263 ;
int V_199 = 0 , V_33 = 0 ;
F_101 ( V_176 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
F_20 ( V_262 ) ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_153 ( exp , & V_196 , V_176 , V_255 , V_262 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
V_263 = V_194 -> V_264 -> V_265 + V_198 -> V_204 ;
V_33 = F_154 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
V_198 -> V_206 . V_210 , V_255 , V_263 ) ;
V_33 = F_105 ( V_194 , V_198 , V_33 ) ;
if ( V_33 ) {
F_15 ( L_85 V_208 L_65
V_208 L_66 ,
exp -> V_52 -> V_49 , F_106 ( & V_176 -> V_215 ) ,
F_106 ( & V_198 -> V_206 . V_210 -> V_215 ) ,
V_198 -> V_205 , V_33 ) ;
V_199 = V_33 ;
}
}
F_155 ( V_194 ) ;
return V_199 ;
}
static int F_156 ( struct V_60 * exp ,
struct V_171 * V_176 ,
T_8 V_266 , void * V_267 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
if ( V_176 == NULL ) {
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_199 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_199 = F_157 ( V_4 -> V_17 [ V_10 ] -> V_47 , NULL ,
V_266 , V_267 ) ;
if ( ! V_33 )
V_33 = V_199 ;
}
return V_33 ;
}
F_101 ( V_176 ) ;
for ( V_10 = 0 ; V_10 < V_176 -> V_183 ; V_10 ++ ) {
struct V_171 V_260 ;
struct V_237 * V_261 = V_176 -> V_184 [ V_10 ] ;
int V_268 = V_261 -> V_185 ;
int V_199 ;
if ( ! V_4 -> V_17 [ V_268 ] ) {
F_8 ( V_244 , L_86 , V_268 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_268 ] -> V_69 )
F_8 ( V_244 , L_83 , V_268 ) ;
V_260 . V_215 = V_261 -> V_186 ;
V_260 . V_183 = 0 ;
V_199 = F_157 ( V_4 -> V_17 [ V_268 ] -> V_47 ,
& V_260 , V_266 , V_267 ) ;
if ( V_199 && V_4 -> V_17 [ V_268 ] -> V_69 ) {
F_15 ( L_87 V_208
L_65 V_208 L_66 ,
exp -> V_52 -> V_49 , F_106 ( & V_176 -> V_215 ) ,
F_106 ( & V_261 -> V_186 ) , V_268 , V_199 ) ;
if ( ! V_33 )
V_33 = V_199 ;
}
}
return V_33 ;
}
int F_158 ( struct V_211 * V_212 , void * V_24 , int V_33 )
{
struct V_193 * V_213 = (struct V_193 * ) V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_213 -> V_214 , 0 ) ;
V_199 = F_159 ( V_213 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_160 ( struct V_60 * exp , struct V_195 * V_196 ,
T_2 V_269 , struct V_211 * V_212 )
{
struct V_1 * V_2 = F_31 ( exp ) ;
struct V_193 * V_194 ;
struct V_197 * V_198 ;
struct V_149 * V_150 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_196 != NULL ) ;
F_20 ( V_196 -> V_270 != NULL ) ;
V_4 = & V_2 -> V_5 . V_4 ;
V_33 = F_161 ( V_2 , V_196 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
V_198 = F_86 ( V_150 , struct V_197 , V_202 ) ;
V_33 = F_162 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_269 , V_212 ) ;
if ( V_33 )
break;
}
if ( V_33 || F_117 ( & V_212 -> V_217 ) ) {
int V_199 ;
if ( V_33 )
F_70 ( & V_194 -> V_214 , 0 ) ;
V_199 = F_159 ( V_194 ) ;
return V_33 ? V_33 : V_199 ;
}
F_20 ( V_212 -> V_218 == NULL ) ;
V_212 -> V_218 = F_158 ;
V_212 -> V_219 = ( void * ) V_194 ;
return 0 ;
}
static int F_163 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_271 * V_272 , T_2 V_269 , T_1 V_266 )
{
struct V_211 * V_194 = NULL ;
struct V_195 V_196 = { { { 0 } } } ;
int V_33 = 0 ;
V_194 = F_164 () ;
if ( V_194 == NULL )
return - V_104 ;
V_196 . V_270 = V_272 ;
V_196 . V_256 = V_266 ;
V_33 = F_160 ( exp , & V_196 , V_269 , V_194 ) ;
if ( V_33 == 0 )
V_33 = F_165 ( V_194 ) ;
F_166 ( V_194 ) ;
return V_33 ;
}
static int F_167 ( unsigned int V_158 , struct V_60 * exp , int V_273 ,
void * V_274 , void * V_275 )
{
struct V_1 * V_276 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_276 -> V_5 . V_4 ;
int V_10 = 0 , V_33 = 0 , V_110 = V_4 -> V_15 . V_16 ;
struct V_25 * V_96 ;
switch ( V_158 ) {
case V_277 : {
struct V_278 * V_24 = V_274 ;
struct V_1 * V_51 ;
struct V_271 V_279 = { 0 } ;
T_1 V_21 ;
T_1 V_266 ;
memcpy ( & V_21 , V_24 -> V_280 , sizeof( T_1 ) ) ;
if ( ( V_21 >= V_110 ) )
return - V_48 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_281 ;
if ( ! V_4 -> V_17 [ V_21 ] -> V_69 )
return - V_282 ;
V_51 = F_31 ( V_4 -> V_17 [ V_21 ] -> V_47 ) ;
if ( ! V_51 )
return - V_34 ;
if ( F_168 ( V_24 -> V_283 , F_169 ( V_51 ) ,
F_170 ( ( int ) V_24 -> V_284 ,
( int ) sizeof( struct V_25 ) ) ) )
return - V_285 ;
V_266 = V_275 ? * ( T_1 * ) V_275 : 0 ;
V_33 = V_271 ( NULL , V_4 -> V_17 [ V_21 ] -> V_47 , & V_279 ,
F_171 ( - V_286 ) ,
V_266 ) ;
if ( V_33 )
return V_33 ;
if ( F_168 ( V_24 -> V_287 , & V_279 ,
F_170 ( ( int ) V_24 -> V_288 ,
( int ) sizeof( V_279 ) ) ) )
return - V_285 ;
break;
}
case V_289 : {
struct V_278 * V_24 ;
struct V_117 * V_15 ;
char * V_290 = NULL ;
T_1 * V_157 ;
V_273 = 0 ;
if ( F_172 ( & V_290 , & V_273 , ( void * ) V_275 ) )
return - V_34 ;
V_24 = (struct V_278 * ) V_290 ;
if ( sizeof( * V_15 ) > V_24 -> V_291 ) {
F_173 ( V_290 , V_273 ) ;
return - V_34 ;
}
if ( sizeof( V_96 -> V_74 ) * V_110 > V_24 -> V_292 ) {
F_173 ( V_290 , V_273 ) ;
return - V_34 ;
}
if ( sizeof( T_1 ) * V_110 > V_24 -> V_293 ) {
F_173 ( V_290 , V_273 ) ;
return - V_34 ;
}
V_15 = (struct V_117 * ) V_24 -> V_294 ;
memcpy ( V_15 , & ( V_4 -> V_15 ) , sizeof( * V_15 ) ) ;
V_96 = (struct V_25 * ) V_24 -> V_280 ;
V_157 = ( T_1 * ) V_24 -> V_295 ;
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ , V_96 ++ , V_157 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
* V_96 = V_4 -> V_17 [ V_10 ] -> V_35 ;
* V_157 = V_4 -> V_17 [ V_10 ] -> V_76 ;
}
if ( F_168 ( ( void * ) V_275 , V_290 , V_273 ) )
V_33 = - V_285 ;
F_173 ( V_290 , V_273 ) ;
break;
}
case V_296 :
V_33 = F_174 ( exp , V_273 , V_274 , V_275 ) ;
break;
case V_297 :
V_33 = F_175 ( exp , V_274 , V_275 ) ;
break;
case V_298 :
V_33 = F_176 ( exp , V_274 , V_275 ) ;
break;
case V_299 : {
struct V_300 * V_301 = V_274 ;
struct V_11 * V_12 = NULL ;
struct V_302 * V_303 ;
if ( V_301 -> V_304 == V_305 ) {
if ( V_301 -> V_306 < 0 || V_110 <= V_301 -> V_306 )
return - V_34 ;
V_12 = V_4 -> V_17 [ V_301 -> V_306 ] ;
if ( ! V_12 || ! V_12 -> V_47 )
return - V_34 ;
} else if ( V_301 -> V_304 == V_307 ) {
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 ||
! F_38 ( & V_12 -> V_35 ,
& V_301 -> V_25 ) )
continue;
if ( V_12 -> V_47 == NULL )
return - V_34 ;
break;
}
} else {
return - V_34 ;
}
if ( V_10 >= V_110 )
return - V_281 ;
F_20 ( V_12 && V_12 -> V_47 ) ;
F_48 ( V_303 ) ;
if ( ! V_303 )
return - V_104 ;
F_177 ( V_303 , V_301 ) ;
V_33 = V_302 ( V_12 -> V_47 , V_303 ) ;
if ( V_33 == 0 ) {
F_177 ( V_301 , V_303 ) ;
V_301 -> V_304 = V_305 ;
V_301 -> V_25 = V_12 -> V_35 ;
}
F_50 ( V_303 ) ;
break;
}
default: {
int V_194 = 0 ;
if ( V_110 == 0 )
return - V_308 ;
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ ) {
int V_199 ;
struct V_1 * V_51 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_51 = F_31 ( V_4 -> V_17 [ V_10 ] -> V_47 ) ;
V_51 -> V_72 = V_276 -> V_72 ;
V_199 = F_178 ( V_158 , V_4 -> V_17 [ V_10 ] -> V_47 ,
V_273 , V_274 , V_275 ) ;
if ( V_199 == - V_282 && V_158 == V_309 ) {
return V_199 ;
} else if ( V_199 ) {
if ( V_4 -> V_17 [ V_10 ] -> V_69 ) {
F_8 ( V_199 == - V_308 ?
V_310 : V_311 ,
L_88
L_89 ,
F_54 ( V_4 , V_10 ) ,
V_10 , V_158 , V_199 ) ;
if ( ! V_33 )
V_33 = V_199 ;
}
} else {
V_194 = 1 ;
}
}
if ( ! V_194 && ! V_33 )
V_33 = - V_189 ;
}
}
return V_33 ;
}
T_9 F_179 ( struct V_312 * V_313 ,
struct V_171 * V_176 , T_9 V_314 ,
T_9 V_315 , int * V_316 )
{
T_9 V_317 = V_313 -> V_318 [ 0 ] . V_319 ;
T_3 V_320 , V_321 ;
T_9 V_322 ;
int V_323 = - 1 , V_10 ;
if ( V_313 -> V_324 == 0 ||
V_313 -> V_318 [ 0 ] . V_319 == 0 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_176 -> V_183 ; V_10 ++ ) {
if ( V_176 -> V_184 [ V_10 ] -> V_185 ==
V_313 -> V_318 [ 0 ] . V_325 ) {
V_323 = V_10 ;
break;
}
}
if ( V_323 == - 1 )
return - V_34 ;
if ( ( F_138 ( V_176 , V_323 , V_314 , V_315 ,
& V_320 , & V_321 ) ) != 0 &&
V_317 < V_321 ) {
V_322 = V_317 ;
* V_316 = V_323 ;
} else {
V_322 = 0 ;
* V_316 = ( V_323 + 1 ) % V_176 -> V_183 ;
}
return V_322 ;
}
int F_180 ( struct V_171 * V_176 , T_9 V_314 ,
T_9 V_315 , int V_316 ,
int * V_326 )
{
int V_327 ;
T_3 V_328 , V_329 ;
int V_10 , V_330 ;
if ( V_315 - V_314 > V_176 -> V_216 * V_176 -> V_183 ) {
V_327 = ( V_316 < 1 ? V_176 -> V_183 - 1 :
V_316 - 1 ) ;
* V_326 = V_176 -> V_183 ;
} else {
for ( V_330 = 0 , V_10 = V_316 ; V_330 < V_176 -> V_183 ;
V_10 = ( V_10 + 1 ) % V_176 -> V_183 , V_330 ++ ) {
if ( ( F_138 ( V_176 , V_10 , V_314 , V_315 ,
& V_328 , & V_329 ) ) == 0 )
break;
}
* V_326 = V_330 ;
V_327 = ( V_316 + V_330 - 1 ) % V_176 -> V_183 ;
}
return V_327 ;
}
void F_181 ( struct V_312 * V_313 ,
struct V_331 * V_332 ,
int V_333 , unsigned int V_334 ,
int V_335 )
{
char * V_336 ;
int V_337 ;
for ( V_337 = 0 ; V_337 < V_334 ; V_337 ++ ) {
V_332 [ V_337 ] . V_325 = V_333 ;
V_332 [ V_337 ] . V_338 |= V_339 ;
}
V_336 = ( char * ) V_313 + F_182 ( V_335 ) ;
memcpy ( V_336 , V_332 , V_334 * sizeof( struct V_331 ) ) ;
}
static int F_183 ( struct V_3 * V_4 , T_1 V_340 , void * V_341 ,
T_1 * V_342 , void * V_111 , struct V_171 * V_176 )
{
struct V_343 * V_344 = V_341 ;
struct V_312 * V_313 = V_111 ;
struct V_312 * V_345 = NULL ;
struct V_331 * V_332 ;
int V_346 ;
unsigned int V_347 = 0 ;
int V_333 = 0 , V_348 , V_316 ;
T_9 V_314 , V_315 , V_349 , V_322 ;
T_9 V_350 ;
int V_335 = 0 , V_33 = 0 , V_10 ;
int V_351 = 0 ;
int V_352 = 0 ;
int V_327 ;
int V_353 = 0 , V_354 = 0 , V_326 ;
unsigned int V_355 = V_356 ;
if ( ! F_184 ( V_176 ) )
GOTO ( V_75 , V_33 = 0 ) ;
if ( F_182 ( V_344 -> V_313 . V_324 ) < V_355 )
V_355 = F_182 ( V_344 -> V_313 . V_324 ) ;
F_185 ( V_345 , V_355 ) ;
if ( V_345 == NULL )
GOTO ( V_75 , V_33 = - V_104 ) ;
V_332 = & V_345 -> V_318 [ 0 ] ;
V_346 = F_186 ( V_355 ) ;
memcpy ( V_313 , & V_344 -> V_313 , sizeof( * V_313 ) ) ;
V_314 = V_313 -> V_314 ;
V_349 = V_313 -> V_349 ;
V_348 = V_316 = F_137 ( V_176 , V_314 ) ;
V_315 = ( V_349 == ~ 0ULL ? V_344 -> V_190 . V_357 :
V_314 + V_349 - 1 ) ;
if ( V_315 > V_344 -> V_190 . V_357 )
V_315 = V_344 -> V_190 . V_357 ;
V_327 = F_180 ( V_176 , V_314 , V_315 ,
V_348 , & V_326 ) ;
V_322 = F_179 ( V_313 , V_176 , V_314 ,
V_315 , & V_316 ) ;
if ( V_322 == - V_34 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( V_313 -> V_324 == 0 ) {
V_347 = 1 ;
V_346 = 0 ;
}
for ( V_353 = V_316 , V_10 = 0 ; V_10 < V_326 ;
V_10 ++ , V_353 = ( V_353 + 1 ) % V_176 -> V_183 ) {
T_9 V_358 ;
T_9 V_359 ;
T_3 V_320 , V_321 , V_360 ;
unsigned int V_334 ;
V_354 = V_353 ;
if ( ( F_138 ( V_176 , V_353 , V_314 , V_315 ,
& V_320 , & V_360 ) ) == 0 )
continue;
if ( V_322 != 0 && V_353 == V_316 )
V_320 = V_322 ;
if ( V_349 != ~ 0ULL ) {
if ( V_314 + V_349 < V_314 )
V_349 = ~ 0ULL - V_314 ;
V_321 = F_187 ( V_176 , V_314 + V_349 ,
V_353 ) ;
} else {
V_321 = ~ 0ULL ;
}
if ( V_320 == V_321 )
continue;
V_358 = V_360 - V_320 ;
V_345 -> V_349 = 0 ;
V_359 = 0 ;
V_351 = 0 ;
V_352 = 0 ;
do {
if ( V_347 == 0 ) {
if ( V_335 + V_346 >
V_313 -> V_324 )
V_346 = V_313 -> V_324 -
V_335 ;
}
V_320 += V_359 ;
V_345 -> V_349 = V_358 - V_359 ;
V_358 = V_345 -> V_349 ;
V_345 -> V_324 = V_346 ;
V_345 -> V_361 = 0 ;
V_345 -> V_362 = V_313 -> V_362 ;
V_344 -> V_190 . V_187 = V_176 -> V_184 [ V_353 ] -> V_186 ;
V_333 = V_176 -> V_184 [ V_353 ] -> V_185 ;
if ( V_333 < 0 || V_333 >= V_4 -> V_15 . V_16 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( ! V_4 -> V_17 [ V_333 ] -> V_69 ) {
V_345 -> V_362 |= V_363 ;
V_345 -> V_361 = 1 ;
V_332 [ 0 ] . V_319 = V_320 ;
V_332 [ 0 ] . V_364 = V_360 -
V_320 ;
V_332 [ 0 ] . V_338 |= V_365 ;
goto V_366;
}
V_345 -> V_314 = V_320 ;
V_345 -> V_362 &= ~ V_367 ;
memcpy ( & V_344 -> V_313 , V_345 , sizeof( * V_345 ) ) ;
* V_342 = F_182 ( V_345 -> V_324 ) ;
V_33 = F_188 ( NULL ,
V_4 -> V_17 [ V_333 ] -> V_47 ,
V_340 , V_341 , V_342 , V_345 , V_176 ) ;
if ( V_33 != 0 )
GOTO ( V_75 , V_33 ) ;
V_366:
V_334 = V_345 -> V_361 ;
if ( V_334 == 0 ) {
V_352 = 1 ;
if ( V_354 == V_327 ) {
V_313 -> V_361 = 0 ;
goto V_368;
}
break;
}
if ( V_347 ) {
V_335 += V_334 ;
break;
}
V_359 = V_332 [ V_334 - 1 ] . V_319 -
V_320 + V_332 [ V_334 - 1 ] . V_364 ;
if ( V_358 <= V_359 )
V_352 = 1 ;
if ( V_332 [ V_334 - 1 ] . V_338 & V_363 )
V_332 [ V_334 - 1 ] . V_338 &=
~ V_363 ;
V_350 = F_189 ( V_176 ,
V_332 [ V_334 - 1 ] . V_319 +
V_332 [ V_334 - 1 ] . V_364 ,
V_353 ) ;
if ( V_350 >= V_344 -> V_190 . V_357 )
V_351 = 1 ;
F_181 ( V_313 , V_332 ,
V_333 , V_334 ,
V_335 ) ;
V_335 += V_334 ;
if ( V_335 >= V_313 -> V_324 )
goto V_368;
} while ( V_352 == 0 && V_351 == 0 );
if ( V_354 == V_327 )
goto V_368;
}
V_368:
if ( V_176 -> V_183 > 1 )
V_313 -> V_362 |= V_367 ;
if ( V_347 )
goto V_369;
if ( V_354 == V_327 ) {
if ( V_352 || V_351 )
V_313 -> V_318 [ V_335 - 1 ] . V_338 |=
V_363 ;
}
V_369:
V_313 -> V_361 = V_335 ;
V_75:
F_190 ( V_345 , V_355 ) ;
return V_33 ;
}
static int F_191 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_1 V_340 , void * V_341 , T_1 * V_342 , void * V_111 ,
struct V_171 * V_176 )
{
struct V_1 * V_276 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_276 -> V_5 . V_4 ;
int V_10 , V_33 ;
if ( ! V_342 || ! V_111 )
return - V_285 ;
F_26 ( V_276 ) ;
if ( F_192 ( V_370 ) ) {
struct {
char V_371 [ 16 ] ;
struct V_372 * V_373 ;
} * V_24 = V_341 ;
struct V_374 * V_375 = & V_24 -> V_373 -> V_376 -> V_377 ;
struct V_237 * V_261 ;
T_1 * V_241 = V_111 ;
if ( * V_342 < sizeof( * V_241 ) )
GOTO ( V_75 , V_33 = - V_285 ) ;
* V_342 = sizeof( * V_241 ) ;
for ( V_10 = 0 ; V_10 < V_176 -> V_183 ; V_10 ++ ) {
V_261 = V_176 -> V_184 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_261 -> V_185 ] )
continue;
if ( V_4 -> V_17 [ V_261 -> V_185 ] -> V_47 ==
V_24 -> V_373 -> V_378 &&
F_193 ( & V_261 -> V_186 , V_375 ) ) {
* V_241 = V_10 ;
GOTO ( V_75 , V_33 = 0 ) ;
}
}
F_194 ( V_24 -> V_373 , L_90 ) ;
F_195 ( V_379 , V_176 ) ;
GOTO ( V_75 , V_33 = - V_380 ) ;
} else if ( F_192 ( V_381 ) ) {
struct V_382 * V_383 = V_111 ;
T_1 V_384 = sizeof( V_385 ) ;
struct V_11 * V_12 ;
F_20 ( * V_342 == sizeof( struct V_382 ) ) ;
V_12 = V_4 -> V_17 [ V_383 -> V_268 ] ;
if ( ! V_12 || ! V_12 -> V_69 )
GOTO ( V_75 , V_33 = - V_386 ) ;
V_33 = F_188 ( V_59 , V_12 -> V_47 , V_340 , V_341 ,
& V_384 , V_383 -> V_24 , NULL ) ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_192 ( V_387 ) ) {
struct V_117 * V_388 = V_111 ;
* V_388 = V_4 -> V_15 ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_192 ( V_389 ) ) {
V_33 = F_183 ( V_4 , V_340 , V_341 , V_342 , V_111 , V_176 ) ;
GOTO ( V_75 , V_33 ) ;
} else if ( F_192 ( V_390 ) ) {
struct V_11 * V_12 ;
T_2 V_177 = * ( ( T_2 * ) V_111 ) ;
F_20 ( * V_342 == sizeof( T_2 ) ) ;
F_20 ( V_177 < V_4 -> V_15 . V_16 ) ;
V_12 = V_4 -> V_17 [ V_177 ] ;
if ( ! V_12 || ! V_12 -> V_47 )
GOTO ( V_75 , V_33 = - V_386 ) ;
* ( ( T_2 * ) V_111 ) = F_196 ( V_12 -> V_47 ) ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_192 ( V_391 ) ) {
* ( ( int * ) V_111 ) = V_4 -> V_15 . V_16 ;
GOTO ( V_75 , V_33 = 0 ) ;
}
V_33 = - V_34 ;
V_75:
F_29 ( V_276 ) ;
return V_33 ;
}
static int F_197 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_4 V_340 , void * V_341 , T_4 V_342 ,
void * V_111 , struct V_211 * V_194 )
{
struct V_1 * V_276 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_276 -> V_5 . V_4 ;
T_4 V_110 ;
int V_10 , V_33 = 0 , V_199 ;
struct V_11 * V_12 ;
unsigned V_392 , V_393 ,
V_394 , V_395 ;
unsigned V_396 = 0 , V_397 = 0 , V_192 = 0 ;
V_392 = V_393 = V_394 = V_395 = 0 ;
if ( V_194 == NULL ) {
V_395 = 1 ;
V_194 = F_164 () ;
if ( ! V_194 )
return - V_104 ;
}
F_26 ( V_276 ) ;
V_110 = V_4 -> V_15 . V_16 ;
if ( F_192 ( V_398 ) ) {
V_110 = V_342 / sizeof( struct V_382 ) ;
V_342 = sizeof( V_385 ) ;
V_392 = sizeof( struct V_382 ) ;
V_394 = 1 ;
V_396 = 1 ;
} else if ( F_192 ( V_399 ) ) {
V_394 = 1 ;
} else if ( F_192 ( V_400 ) ) {
} else if ( F_192 ( V_401 ) ) {
V_397 = 1 ;
} else if ( F_192 ( V_402 ) ) {
V_192 = 1 ;
} else if ( F_192 ( V_108 ) ) {
F_20 ( V_4 -> V_107 == NULL ) ;
V_4 -> V_107 = V_111 ;
V_394 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ , V_111 = ( char * ) V_111 + V_392 ) {
if ( V_396 ) {
V_12 = V_4 -> V_17 [ ( ( struct V_382 * )val )->idx] ;
}
int F_198 ( struct V_60 * exp , struct V_171 * V_176 ,
int V_158 , T_2 * V_403 )
{
T_1 V_404 = V_176 -> V_216 ;
T_2 V_233 ;
V_233 = * V_403 ;
F_199 ( V_233 , V_404 ) ;
V_233 = V_233 * V_404 ;
F_8 ( V_405 , L_91 V_114 L_92 V_114
L_93 V_114 L_22 , * V_403 , V_404 , V_233 ,
V_233 + V_404 - 1 ) ;
if ( V_158 == V_406 ) {
* V_403 = V_233 + V_404 - 1 ;
} else if ( V_158 == V_407 ) {
* V_403 = V_233 ;
} else {
F_99 () ;
}
return 0 ;
}
void F_200 ( struct V_171 * V_408 )
{
F_20 ( V_408 -> V_409 != F_201 () ) ;
F_202 ( & V_408 -> V_410 ) ;
F_20 ( V_408 -> V_409 == 0 ) ;
V_408 -> V_409 = F_201 () ;
}
void F_203 ( struct V_171 * V_408 )
{
F_20 ( V_408 -> V_409 == F_201 () ) ;
V_408 -> V_409 = 0 ;
F_204 ( & V_408 -> V_410 ) ;
}
static int F_205 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_302 * V_303 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
T_2 V_411 = 0 ;
T_2 V_412 = 0 ;
int V_10 , V_33 = 0 ;
if ( V_303 -> V_413 != V_414 &&
V_303 -> V_413 != V_415 &&
V_303 -> V_413 != V_416 &&
V_303 -> V_413 != V_417 &&
V_303 -> V_413 != V_418 &&
V_303 -> V_413 != V_419 ) {
F_15 ( L_94 , V_303 -> V_413 ) ;
return - V_285 ;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_199 ;
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 )
continue;
if ( ! V_12 -> V_69 || V_12 -> V_18 ) {
if ( V_303 -> V_413 == V_416 &&
V_4 -> V_17 [ V_10 ] -> V_67 ) {
V_33 = - V_420 ;
F_15 ( L_95 , V_10 ) ;
} else {
F_8 ( V_244 , L_95 , V_10 ) ;
}
continue;
}
V_199 = V_302 ( V_12 -> V_47 , V_303 ) ;
if ( V_199 ) {
if ( V_12 -> V_69 && ! V_33 )
V_33 = V_199 ;
continue;
}
if ( V_303 -> V_413 == V_416 ) {
V_411 += V_303 -> V_421 . V_422 ;
V_412 += V_303 -> V_421 . V_423 ;
}
}
F_29 ( V_2 ) ;
if ( V_303 -> V_413 == V_416 ) {
V_303 -> V_421 . V_422 = V_411 ;
V_303 -> V_421 . V_423 = V_412 ;
}
return V_33 ;
}
static int F_206 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_302 * V_303 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_33 = 0 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( ! V_4 -> V_17 [ V_10 ] -> V_67 ) {
F_79 ( L_96
L_97 , V_10 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_69 ) {
F_15 ( L_83 , V_10 ) ;
V_33 = - V_189 ;
goto V_75;
}
}
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_199 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_67 )
continue;
V_199 = F_207 ( V_4 -> V_17 [ V_10 ] -> V_47 , V_303 ) ;
if ( V_199 && ! V_33 )
V_33 = V_199 ;
}
V_75:
F_29 ( V_2 ) ;
return V_33 ;
}
int T_10 F_208 ( void )
{
struct V_124 V_125 = { 0 } ;
int V_33 ;
F_8 ( V_80 , L_98 , & V_424 ) ;
V_33 = F_209 ( V_424 ) ;
if ( V_33 )
return V_33 ;
V_425 = F_210 ( L_99 ,
sizeof( struct V_237 ) ,
0 , V_426 , NULL ) ;
if ( V_425 == NULL ) {
F_211 ( V_424 ) ;
return - V_104 ;
}
F_75 ( & V_125 ) ;
V_33 = F_212 ( & V_427 , NULL , V_125 . V_428 ,
V_429 , & V_430 ) ;
if ( V_33 ) {
F_213 ( V_425 ) ;
F_211 ( V_424 ) ;
}
return V_33 ;
}
static void F_214 ( void )
{
F_215 ( V_429 ) ;
F_213 ( V_425 ) ;
F_211 ( V_424 ) ;
}
