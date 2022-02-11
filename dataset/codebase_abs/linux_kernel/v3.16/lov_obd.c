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
V_2 -> V_49 , V_51 ? V_51 -> V_49 : L_18 ) ;
if ( V_12 -> V_69 ) {
V_12 -> V_69 = 0 ;
V_4 -> V_15 . V_70 -- ;
V_12 -> V_47 -> V_52 -> V_71 = 1 ;
}
if ( V_51 ) {
V_32 = V_2 -> V_50 ;
if ( V_32 ) {
F_32 ( V_51 -> V_49 , V_32 ) ;
}
V_51 -> V_72 = V_2 -> V_72 ;
V_51 -> V_73 = V_2 -> V_73 ;
V_51 -> V_45 = V_2 -> V_45 ;
}
F_18 ( V_51 , NULL ) ;
V_33 = F_33 ( V_12 -> V_47 ) ;
if ( V_33 ) {
F_15 ( L_19 ,
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
F_15 ( L_20 , V_4 -> V_65 ) ;
goto V_75;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( V_4 -> V_17 [ V_10 ] && V_4 -> V_17 [ V_10 ] -> V_47 ) {
F_35 ( V_2 , V_10 , NULL , V_4 -> V_17 [ V_10 ] -> V_76 ) ;
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
F_8 ( V_80 , L_21 ,
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
F_8 ( V_80 , L_22 V_82 L_23 ,
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
F_8 ( V_80 , L_24 ,
V_74 -> V_74 , V_22 ? L_9 : L_25 ) ;
} else {
V_4 -> V_17 [ V_21 ] -> V_67 = V_22 ;
F_8 ( V_14 , L_26 ,
V_22 ? L_9 : L_25 , F_16 ( V_74 ) ) ;
}
} else if ( V_78 == V_86 || V_78 == V_87 ) {
V_79 = ( V_78 == V_87 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_69 == V_79 ) {
F_8 ( V_80 , L_27 ,
V_74 -> V_74 , V_79 ? L_9 : L_10 ) ;
GOTO ( V_75 , V_21 ) ;
} else {
F_8 ( V_14 , L_28 ,
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
F_15 ( L_29 , V_78 , V_74 -> V_74 ) ;
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
F_15 ( L_30 ,
V_88 -> V_56 -> V_57 ,
V_88 -> V_49 ) ;
return - V_34 ;
}
V_74 = & V_88 -> V_5 . V_38 . V_91 ;
V_33 = F_37 ( V_2 , V_74 , V_78 ) ;
if ( V_33 < 0 ) {
F_40 ( & V_4 -> V_89 ) ;
F_15 ( L_31 , V_78 ,
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
F_15 ( L_32 ,
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
F_8 ( V_14 , L_33 ,
V_96 -> V_74 , V_21 , V_97 , V_79 ) ;
if ( V_97 <= 0 ) {
F_15 ( L_34 ,
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
F_15 ( L_35 ,
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
F_8 ( V_14 , L_36 ,
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
F_8 ( V_14 , L_37 ,
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
F_15 ( L_38 , V_33 ,
F_16 ( & V_12 -> V_35 ) ) ;
F_35 ( V_2 , V_21 , NULL , 0 ) ;
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
F_15 ( L_39 ,
V_21 , V_110 ) ;
return - V_34 ;
}
F_53 ( & V_4 -> V_89 ) ;
F_26 ( V_2 ) ;
if ( ! V_4 -> V_17 [ V_21 ] ) {
F_15 ( L_40 , V_21 ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
if ( V_96 && ! F_38 ( V_96 , & V_4 -> V_17 [ V_21 ] -> V_35 ) ) {
F_15 ( L_41 ,
F_54 ( V_4 , V_21 ) , V_21 ,
F_16 ( V_96 ) ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
F_8 ( V_14 , L_42 ,
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
F_8 ( V_14 , L_43 ,
V_12 -> V_35 . V_74 ,
V_51 ? V_51 -> V_49 : L_44 ) ;
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
F_58 ( L_45
L_46 ,
V_113 ) ;
* V_111 = V_113 ;
} else if ( * V_111 & ( V_112 - 1 ) ) {
* V_111 &= ~ ( V_112 - 1 ) ;
F_59 ( L_47 V_114 L_48
L_49 ,
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
F_59 ( L_50 , * V_111 ) ;
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
struct V_124 V_125 = { NULL } ;
struct V_117 * V_15 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_33 ;
if ( F_65 ( V_123 , 1 ) < 1 ) {
F_15 ( L_51 ) ;
return - V_34 ;
}
V_15 = (struct V_117 * ) F_66 ( V_123 , 1 ) ;
if ( sizeof( * V_15 ) > F_65 ( V_123 , 1 ) ) {
F_15 ( L_52 ,
( int ) sizeof( * V_15 ) , F_65 ( V_123 , 1 ) ) ;
return - V_34 ;
}
if ( V_15 -> V_126 != V_127 ) {
if ( V_15 -> V_126 == F_67 ( V_127 ) ) {
F_8 ( V_128 , L_53 ,
V_2 -> V_49 , V_15 ) ;
F_68 ( V_15 ) ;
} else {
F_15 ( L_54 ,
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
V_4 -> V_130 = F_72 ( L_55 , V_131 ,
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
V_141 = F_78 ( V_2 -> V_142 , L_56 ,
0444 , & V_143 , V_2 ) ;
if ( V_141 )
F_79 ( L_57 ) ;
}
#endif
V_4 -> V_144 = F_80 ( L_58 ,
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
default:
break;
}
return V_33 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_148 * V_149 , * V_150 ;
struct V_151 * V_152 ;
F_84 (pos, tmp, &lov->lov_pool_list) {
V_152 = F_85 ( V_149 , struct V_151 , V_153 ) ;
F_8 ( V_80 , L_59 , V_152 ) ;
F_86 ( V_2 , V_152 -> V_154 ) ;
}
F_87 ( V_4 -> V_130 ) ;
F_88 ( & V_4 -> V_20 ) ;
F_89 ( V_2 ) ;
if ( V_4 -> V_17 ) {
int V_10 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_4 -> V_17 [ V_10 ] -> V_69 ||
F_90 ( & V_4 -> V_7 ) )
F_15 ( L_60
L_61 ,
V_10 , V_4 -> V_8 ,
F_90 ( & V_4 -> V_7 ) ) ;
F_35 ( V_2 , V_10 , 0 , 0 ) ;
}
F_29 ( V_2 ) ;
F_47 ( V_4 -> V_17 , sizeof( * V_4 -> V_17 ) *
V_4 -> V_98 ) ;
V_4 -> V_98 = 0 ;
}
return 0 ;
}
int F_91 ( struct V_1 * V_2 , struct V_122 * V_123 ,
T_1 * V_155 , int * V_156 )
{
struct V_25 V_25 ;
int V_157 ;
int V_33 = 0 ;
switch ( V_157 = V_123 -> V_158 ) {
case V_159 :
case V_160 :
case V_161 : {
T_1 V_21 ;
int V_97 ;
if ( F_65 ( V_123 , 1 ) > sizeof( V_25 . V_74 ) )
GOTO ( V_75 , V_33 = - V_34 ) ;
F_92 ( & V_25 , F_66 ( V_123 , 1 ) ) ;
if ( sscanf ( F_66 ( V_123 , 2 ) , L_62 , V_155 ) != 1 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( sscanf ( F_66 ( V_123 , 3 ) , L_62 , V_156 ) != 1 )
GOTO ( V_75 , V_33 = - V_34 ) ;
V_21 = * V_155 ;
V_97 = * V_156 ;
if ( V_157 == V_159 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_97 , 1 ) ;
else if ( V_157 == V_160 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_97 , 0 ) ;
else
V_33 = F_35 ( V_2 , V_21 , & V_25 , V_97 ) ;
GOTO ( V_75 , V_33 ) ;
}
case V_162 : {
struct V_124 V_125 = { 0 } ;
struct V_117 * V_15 = & ( V_2 -> V_5 . V_4 . V_15 ) ;
if ( ! V_15 )
GOTO ( V_75 , V_33 = - V_34 ) ;
F_75 ( & V_125 ) ;
V_33 = F_93 ( V_163 , V_125 . V_140 ,
V_123 , V_2 ) ;
if ( V_33 > 0 )
V_33 = 0 ;
GOTO ( V_75 , V_33 ) ;
}
case V_164 :
case V_165 :
case V_166 :
case V_167 :
GOTO ( V_75 , V_33 ) ;
default: {
F_15 ( L_63 , V_123 -> V_158 ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
}
V_75:
return V_33 ;
}
static int F_94 ( struct V_60 * exp , struct V_168 * V_169 ,
struct V_170 * * V_171 , struct V_172 * V_173 )
{
struct V_170 * V_174 , * V_175 ;
struct V_3 * V_4 = & exp -> V_52 -> V_5 . V_4 ;
unsigned V_176 ;
int V_33 , V_10 ;
F_20 ( V_169 -> V_177 & V_178 &&
V_169 -> V_179 & V_180 ) ;
F_45 ( V_174 , sizeof( * V_174 ) ) ;
if ( V_174 == NULL )
return - V_104 ;
V_176 = V_169 -> V_181 ;
V_175 = * V_171 ;
if ( V_175 == NULL )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( V_176 >= V_4 -> V_15 . V_16 ||
! V_4 -> V_17 [ V_176 ] )
GOTO ( V_75 , V_33 = - V_34 ) ;
for ( V_10 = 0 ; V_10 < V_175 -> V_182 ; V_10 ++ ) {
if ( V_175 -> V_183 [ V_10 ] -> V_184 == V_176 ) {
if ( F_95 ( & V_175 -> V_183 [ V_10 ] -> V_185 ) !=
F_95 ( & V_169 -> V_186 ) )
GOTO ( V_75 , V_33 = - V_34 ) ;
break;
}
}
if ( V_10 == V_175 -> V_182 )
GOTO ( V_75 , V_33 = - V_34 ) ;
V_33 = F_96 ( NULL , V_4 -> V_17 [ V_176 ] -> V_47 ,
V_169 , & V_174 , V_173 ) ;
V_75:
F_47 ( V_174 , sizeof( * V_174 ) ) ;
return V_33 ;
}
static int F_97 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_168 * V_169 , struct V_170 * * V_171 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_171 != NULL ) ;
if ( exp == NULL )
return - V_34 ;
if ( ( V_169 -> V_177 & V_178 ) &&
V_169 -> V_179 == V_187 ) {
F_98 () ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
if ( ! V_4 -> V_15 . V_70 )
return - V_188 ;
F_26 ( exp -> V_52 ) ;
if ( ( V_169 -> V_177 & V_178 ) &&
( V_169 -> V_179 & V_180 ) ) {
V_33 = F_94 ( exp , V_169 , V_171 , V_173 ) ;
}
F_29 ( exp -> V_52 ) ;
return V_33 ;
}
static int F_99 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_168 * V_189 , struct V_170 * V_175 ,
struct V_172 * V_173 , struct V_60 * V_190 ,
void * V_191 )
{
struct V_192 * V_193 ;
struct V_194 V_195 ;
struct V_196 * V_197 ;
struct V_148 * V_149 ;
struct V_3 * V_4 ;
int V_33 = 0 , V_198 = 0 ;
F_100 ( V_175 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
if ( V_189 -> V_177 & V_199 ) {
F_20 ( V_173 ) ;
F_20 ( V_173 -> V_200 ) ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
F_26 ( exp -> V_52 ) ;
V_33 = F_101 ( exp , & V_195 , V_189 , V_175 , V_173 , & V_193 ) ;
if ( V_33 )
GOTO ( V_75 , V_33 ) ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
if ( V_189 -> V_177 & V_199 )
V_173 -> V_200 = V_193 -> V_202 + V_197 -> V_203 ;
V_198 = F_103 ( V_59 , V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
V_197 -> V_205 . V_206 , NULL , V_173 , NULL , V_191 ) ;
V_198 = F_104 ( V_193 , V_197 , V_198 ) ;
if ( V_198 ) {
F_15 ( L_64 V_207 L_65
V_207 L_66 ,
exp -> V_52 -> V_49 , F_105 ( & V_189 -> V_186 ) ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) ,
V_197 -> V_204 , V_198 ) ;
if ( ! V_33 )
V_33 = V_198 ;
}
}
if ( V_33 == 0 ) {
F_20 ( F_106 ( V_175 -> V_208 ) != NULL ) ;
V_33 = F_106 ( V_175 -> V_208 ) -> F_107 ( V_175 , V_189 , V_190 ) ;
}
V_198 = F_108 ( V_193 ) ;
V_75:
F_29 ( exp -> V_52 ) ;
return V_33 ? V_33 : V_198 ;
}
static int F_109 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_194 * V_195 )
{
struct V_192 * V_193 ;
struct V_196 * V_197 ;
struct V_148 * V_149 ;
struct V_3 * V_4 ;
int V_198 = 0 , V_33 = 0 ;
F_20 ( V_195 ) ;
F_100 ( V_195 -> V_209 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_110 ( exp , V_195 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
F_8 ( V_80 , L_67 V_207 L_68 V_207 L_69
L_70 , F_105 ( & V_195 -> V_206 -> V_186 ) , V_197 -> V_203 ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) , V_197 -> V_204 ) ;
V_33 = F_111 ( V_59 , V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 ) ;
V_198 = F_104 ( V_193 , V_197 , V_33 ) ;
if ( V_198 ) {
F_15 ( L_71 V_207 L_65
V_207 L_66 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_195 -> V_206 -> V_186 ) ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) ,
V_197 -> V_204 , V_198 ) ;
break;
}
}
V_33 = F_112 ( V_193 ) ;
if ( V_198 )
V_33 = V_198 ;
return V_33 ;
}
static int F_113 ( struct V_210 * V_211 ,
void * V_24 , int V_33 )
{
struct V_192 * V_212 = (struct V_192 * ) V_24 ;
int V_198 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_198 = F_112 ( V_212 ) ;
return V_33 ? V_33 : V_198 ;
}
static int F_114 ( struct V_60 * exp , struct V_194 * V_195 ,
struct V_210 * V_211 )
{
struct V_192 * V_212 ;
struct V_3 * V_4 ;
struct V_148 * V_149 ;
struct V_196 * V_197 ;
int V_33 = 0 , V_198 ;
F_20 ( V_195 ) ;
F_100 ( V_195 -> V_209 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_110 ( exp , V_195 , & V_212 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_67 V_207 L_72 ,
F_105 ( & V_195 -> V_209 -> V_214 ) , V_195 -> V_209 -> V_182 ,
V_195 -> V_209 -> V_215 ) ;
F_102 (pos, &lovset->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
F_8 ( V_80 , L_67 V_207 L_68 V_207 L_69
L_73 , F_105 ( & V_195 -> V_206 -> V_186 ) , V_197 -> V_203 ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) , V_197 -> V_204 ) ;
V_33 = F_115 ( V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 , V_211 ) ;
if ( V_33 ) {
F_15 ( L_71 V_207 L_74
V_207 L_66 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_195 -> V_206 -> V_186 ) ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) ,
V_197 -> V_204 , V_33 ) ;
GOTO ( V_75 , V_33 ) ;
}
}
if ( ! F_116 ( & V_211 -> V_216 ) ) {
F_20 ( V_33 == 0 ) ;
F_20 ( V_211 -> V_217 == NULL ) ;
V_211 -> V_217 = F_113 ;
V_211 -> V_218 = ( void * ) V_212 ;
return V_33 ;
}
V_75:
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_198 = F_112 ( V_212 ) ;
return V_33 ? V_33 : V_198 ;
}
static int F_117 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_194 * V_195 , struct V_172 * V_173 )
{
struct V_192 * V_193 ;
struct V_3 * V_4 ;
struct V_148 * V_149 ;
struct V_196 * V_197 ;
int V_198 = 0 , V_33 = 0 ;
F_20 ( V_195 ) ;
F_100 ( V_195 -> V_209 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
F_20 ( ! ( V_195 -> V_206 -> V_177 & ~ ( V_219 | V_220 |
V_221 | V_222 |
V_223 | V_224 |
V_178 | V_225 |
V_226 | V_227 |
V_228 | V_229 |
V_230 ) ) ) ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_118 ( exp , V_195 , V_173 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
V_33 = F_119 ( V_59 , V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 , NULL ) ;
V_198 = F_120 ( V_193 , V_197 , V_33 ) ;
if ( V_198 ) {
F_15 ( L_75 V_207 L_65
V_207 L_66 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_193 -> V_231 -> V_206 -> V_186 ) ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) , V_197 -> V_204 ,
V_198 ) ;
if ( ! V_33 )
V_33 = V_198 ;
}
}
V_198 = F_121 ( V_193 ) ;
if ( ! V_33 )
V_33 = V_198 ;
return V_33 ;
}
static int F_122 ( struct V_210 * V_211 ,
void * V_24 , int V_33 )
{
struct V_192 * V_212 = (struct V_192 * ) V_24 ;
int V_198 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_198 = F_121 ( V_212 ) ;
return V_33 ? V_33 : V_198 ;
}
static int F_123 ( struct V_60 * exp , struct V_194 * V_195 ,
struct V_172 * V_173 ,
struct V_210 * V_211 )
{
struct V_192 * V_193 ;
struct V_196 * V_197 ;
struct V_148 * V_149 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_195 ) ;
F_100 ( V_195 -> V_209 ) ;
if ( V_195 -> V_206 -> V_177 & V_199 ) {
F_20 ( V_173 ) ;
F_20 ( V_173 -> V_200 ) ;
}
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_118 ( exp , V_195 , V_173 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_67 V_207 L_72 ,
F_105 ( & V_195 -> V_209 -> V_214 ) ,
V_195 -> V_209 -> V_182 ,
V_195 -> V_209 -> V_215 ) ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
if ( V_195 -> V_206 -> V_177 & V_199 )
V_173 -> V_200 = V_193 -> V_202 + V_197 -> V_203 ;
F_8 ( V_80 , L_67 V_207 L_68 V_207 L_69
L_73 , F_105 ( & V_195 -> V_206 -> V_186 ) , V_197 -> V_203 ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) , V_197 -> V_204 ) ;
V_33 = F_124 ( V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 , V_173 , V_211 ) ;
if ( V_33 ) {
F_15 ( L_76 V_207 L_74
V_207 L_66 ,
F_105 ( & V_193 -> V_231 -> V_206 -> V_186 ) ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) ,
V_197 -> V_204 , V_33 ) ;
break;
}
}
if ( V_33 || ! V_211 || F_116 ( & V_211 -> V_216 ) ) {
int V_198 ;
if ( V_33 )
F_70 ( & V_193 -> V_213 , 0 ) ;
V_198 = F_121 ( V_193 ) ;
return V_33 ? V_33 : V_198 ;
}
F_20 ( V_211 -> V_217 == NULL ) ;
V_211 -> V_217 = F_122 ;
V_211 -> V_218 = ( void * ) V_193 ;
return 0 ;
}
static int F_125 ( struct V_210 * V_211 ,
void * V_24 , int V_33 )
{
struct V_192 * V_212 = (struct V_192 * ) V_24 ;
int V_198 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_198 = F_126 ( V_212 ) ;
return V_33 ? V_33 : V_198 ;
}
static int F_127 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_194 * V_195 , struct V_172 * V_173 ,
struct V_210 * V_211 )
{
struct V_192 * V_193 ;
struct V_3 * V_4 ;
struct V_148 * V_149 ;
struct V_196 * V_197 ;
int V_33 = 0 ;
F_20 ( V_195 ) ;
F_100 ( V_195 -> V_209 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_128 ( exp , V_195 , V_173 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
V_33 = F_129 ( V_59 , V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 , NULL , V_211 ) ;
if ( V_33 ) {
F_15 ( L_77 V_207 L_65 V_207
L_66 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_193 -> V_231 -> V_206 -> V_186 ) ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) , V_197 -> V_204 , V_33 ) ;
break;
}
}
if ( V_33 || F_116 ( & V_211 -> V_216 ) ) {
int V_198 ;
V_198 = F_126 ( V_193 ) ;
return V_33 ? V_33 : V_198 ;
}
F_20 ( V_211 -> V_217 == NULL ) ;
V_211 -> V_217 = F_125 ;
V_211 -> V_218 = ( void * ) V_193 ;
return 0 ;
}
static int F_130 ( struct V_210 * V_211 ,
void * V_24 , int V_33 )
{
struct V_192 * V_212 = V_24 ;
int V_198 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_198 = F_131 ( V_212 ) ;
return V_33 ? : V_198 ;
}
static int F_132 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_194 * V_195 , T_3 V_232 , T_3 V_233 ,
struct V_210 * V_211 )
{
struct V_192 * V_193 = NULL ;
struct V_3 * V_4 ;
struct V_148 * V_149 ;
struct V_196 * V_197 ;
int V_33 = 0 ;
F_100 ( V_195 -> V_209 ) ;
F_20 ( V_211 != NULL ) ;
if ( ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_133 ( exp , V_195 , V_232 , V_233 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_78 V_207 L_79 V_82 L_80 V_82 L_81 ,
F_105 ( & V_193 -> V_231 -> V_206 -> V_186 ) , V_232 , V_233 ) ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
V_33 = F_134 ( V_59 , V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 , V_197 -> V_205 . V_234 . V_235 . V_232 ,
V_197 -> V_205 . V_234 . V_235 . V_233 , V_211 ) ;
if ( V_33 ) {
F_15 ( L_82 V_207 L_65 V_207
L_66 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_193 -> V_231 -> V_206 -> V_186 ) ,
F_105 ( & V_197 -> V_205 . V_206 -> V_186 ) , V_197 -> V_204 ,
V_33 ) ;
break;
}
}
if ( V_33 || F_116 ( & V_211 -> V_216 ) ) {
int V_198 = F_131 ( V_193 ) ;
return V_33 ? : V_198 ;
}
F_20 ( V_211 -> V_217 == NULL ) ;
V_211 -> V_217 = F_130 ;
V_211 -> V_218 = ( void * ) V_193 ;
return 0 ;
}
static int F_135 ( struct V_3 * V_4 , struct V_194 * V_236 ,
T_4 V_237 , struct V_238 * V_239 )
{
struct V_194 V_195 = { { { 0 } } } ;
int V_10 , V_33 = 0 ;
V_195 . V_206 = V_236 -> V_206 ;
for ( V_10 = 0 ; V_10 < V_237 ; V_10 ++ ) {
int V_240 = F_136 ( V_236 -> V_209 , V_239 [ V_10 ] . V_241 ) ;
int V_242 = V_236 -> V_209 -> V_183 [ V_240 ] -> V_184 ;
T_3 V_232 , V_233 ;
if ( ! F_137 ( V_236 -> V_209 , V_10 , V_239 [ V_10 ] . V_241 ,
V_239 [ V_10 ] . V_241 + V_239 [ V_10 ] . V_110 - 1 ,
& V_232 , & V_233 ) )
continue;
if ( ! V_4 -> V_17 [ V_242 ] || ! V_4 -> V_17 [ V_242 ] -> V_69 ) {
F_8 ( V_243 , L_83 , V_242 ) ;
return - V_188 ;
}
V_33 = F_138 ( V_244 , V_4 -> V_17 [ V_242 ] -> V_47 , & V_195 ,
1 , & V_239 [ V_10 ] , NULL ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_139 ( int V_157 , struct V_60 * exp , struct V_194 * V_195 ,
T_4 V_237 , struct V_238 * V_239 ,
struct V_172 * V_173 )
{
struct V_192 * V_193 ;
struct V_196 * V_197 ;
struct V_148 * V_149 ;
struct V_3 * V_4 = & exp -> V_52 -> V_5 . V_4 ;
int V_198 , V_33 = 0 ;
F_100 ( V_195 -> V_209 ) ;
if ( V_157 == V_244 ) {
V_33 = F_135 ( V_4 , V_195 , V_237 , V_239 ) ;
return V_33 ;
}
V_33 = F_140 ( exp , V_195 , V_237 , V_239 , V_173 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
struct V_60 * V_245 ;
struct V_238 * V_246 ;
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
V_245 = V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ;
V_246 = V_193 -> V_247 + V_197 -> V_248 ;
V_33 = F_138 ( V_157 , V_245 , & V_197 -> V_205 , V_197 -> V_249 ,
V_246 , V_173 ) ;
if ( V_33 )
break;
F_104 ( V_193 , V_197 , V_33 ) ;
}
V_198 = F_141 ( V_193 ) ;
if ( ! V_33 )
V_33 = V_198 ;
return V_33 ;
}
static int F_142 ( struct V_210 * V_211 ,
void * V_24 , int V_33 )
{
struct V_192 * V_212 = (struct V_192 * ) V_24 ;
V_33 = F_143 ( V_212 , V_212 -> V_250 -> V_251 , V_33 , V_211 ) ;
return V_33 ;
}
static int F_144 ( struct V_60 * exp , struct V_194 * V_195 ,
struct V_252 * V_253 ,
struct V_210 * V_211 )
{
T_5 V_254 = V_253 -> V_251 ;
struct V_192 * V_193 ;
struct V_196 * V_197 ;
struct V_148 * V_149 ;
struct V_3 * V_4 ;
T_6 V_33 ;
F_20 ( V_195 ) ;
F_100 ( V_195 -> V_209 ) ;
F_20 ( V_254 == ( V_254 & - V_254 ) ) ;
F_20 ( ( V_195 -> V_255 & V_256 ) == 0 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_145 ( exp , V_195 , V_253 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
V_33 = F_146 ( V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 , V_253 , V_211 ) ;
if ( V_33 != V_257 )
GOTO ( V_75 , V_33 ) ;
}
if ( V_211 && ! F_116 ( & V_211 -> V_216 ) ) {
F_20 ( V_33 == 0 ) ;
F_20 ( V_211 -> V_217 == NULL ) ;
V_211 -> V_217 = F_142 ;
V_211 -> V_218 = ( void * ) V_193 ;
return V_33 ;
}
V_75:
V_33 = F_143 ( V_193 , V_254 , V_33 , V_211 ) ;
return V_33 ;
}
static int F_147 ( struct V_60 * exp ,
struct V_170 * V_175 , T_7 V_258 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
F_100 ( V_175 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_175 -> V_182 ; V_10 ++ ) {
struct V_170 V_259 ;
struct V_236 * V_260 = V_175 -> V_183 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_260 -> V_184 ] ) {
F_8 ( V_243 , L_84 , V_260 -> V_184 ) ;
continue;
}
V_259 . V_214 = V_260 -> V_185 ;
V_259 . V_182 = 0 ;
V_33 = F_148 ( V_4 -> V_17 [ V_260 -> V_184 ] -> V_47 ,
& V_259 , V_258 , V_24 ) ;
}
return V_33 ;
}
static int F_149 ( struct V_60 * exp ,
struct V_170 * V_175 , T_7 V_258 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
F_100 ( V_175 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_175 -> V_182 ; V_10 ++ ) {
struct V_170 V_259 ;
struct V_236 * V_260 = V_175 -> V_183 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_260 -> V_184 ] ) {
F_8 ( V_243 , L_84 , V_260 -> V_184 ) ;
continue;
}
V_259 . V_214 = V_260 -> V_185 ;
V_259 . V_182 = 0 ;
V_33 = F_150 ( V_4 -> V_17 [ V_260 -> V_184 ] -> V_47 ,
& V_259 , V_258 , V_24 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return V_33 ;
}
static int F_151 ( struct V_60 * exp , struct V_170 * V_175 ,
T_1 V_254 , struct V_63 * V_261 )
{
struct V_192 * V_193 ;
struct V_194 V_195 ;
struct V_196 * V_197 ;
struct V_148 * V_149 ;
struct V_3 * V_4 ;
struct V_63 * V_262 ;
int V_198 = 0 , V_33 = 0 ;
F_100 ( V_175 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
F_20 ( V_261 ) ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_152 ( exp , & V_195 , V_175 , V_254 , V_261 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
V_262 = V_193 -> V_263 -> V_264 + V_197 -> V_203 ;
V_33 = F_153 ( V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
V_197 -> V_205 . V_209 , V_254 , V_262 ) ;
V_33 = F_104 ( V_193 , V_197 , V_33 ) ;
if ( V_33 ) {
F_15 ( L_85 V_207 L_65
V_207 L_66 ,
exp -> V_52 -> V_49 , F_105 ( & V_175 -> V_214 ) ,
F_105 ( & V_197 -> V_205 . V_209 -> V_214 ) ,
V_197 -> V_204 , V_33 ) ;
V_198 = V_33 ;
}
}
F_154 ( V_193 ) ;
return V_198 ;
}
static int F_155 ( struct V_60 * exp ,
struct V_170 * V_175 ,
T_8 V_265 , void * V_266 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
if ( V_175 == NULL ) {
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_198 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_198 = F_156 ( V_4 -> V_17 [ V_10 ] -> V_47 , NULL ,
V_265 , V_266 ) ;
if ( ! V_33 )
V_33 = V_198 ;
}
return V_33 ;
}
F_100 ( V_175 ) ;
for ( V_10 = 0 ; V_10 < V_175 -> V_182 ; V_10 ++ ) {
struct V_170 V_259 ;
struct V_236 * V_260 = V_175 -> V_183 [ V_10 ] ;
int V_267 = V_260 -> V_184 ;
int V_198 ;
if ( ! V_4 -> V_17 [ V_267 ] ) {
F_8 ( V_243 , L_86 , V_267 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_267 ] -> V_69 )
F_8 ( V_243 , L_83 , V_267 ) ;
V_259 . V_214 = V_260 -> V_185 ;
V_259 . V_182 = 0 ;
V_198 = F_156 ( V_4 -> V_17 [ V_267 ] -> V_47 ,
& V_259 , V_265 , V_266 ) ;
if ( V_198 && V_4 -> V_17 [ V_267 ] -> V_69 ) {
F_15 ( L_87 V_207
L_65 V_207 L_66 ,
exp -> V_52 -> V_49 , F_105 ( & V_175 -> V_214 ) ,
F_105 ( & V_260 -> V_185 ) , V_267 , V_198 ) ;
if ( ! V_33 )
V_33 = V_198 ;
}
}
return V_33 ;
}
int F_157 ( struct V_210 * V_211 , void * V_24 , int V_33 )
{
struct V_192 * V_212 = (struct V_192 * ) V_24 ;
int V_198 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_198 = F_158 ( V_212 ) ;
return V_33 ? V_33 : V_198 ;
}
static int F_159 ( struct V_60 * exp , struct V_194 * V_195 ,
T_2 V_268 , struct V_210 * V_211 )
{
struct V_1 * V_2 = F_31 ( exp ) ;
struct V_192 * V_193 ;
struct V_196 * V_197 ;
struct V_148 * V_149 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_195 != NULL ) ;
F_20 ( V_195 -> V_269 != NULL ) ;
V_4 = & V_2 -> V_5 . V_4 ;
V_33 = F_160 ( V_2 , V_195 , & V_193 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_197 = F_85 ( V_149 , struct V_196 , V_201 ) ;
V_33 = F_161 ( V_4 -> V_17 [ V_197 -> V_204 ] -> V_47 ,
& V_197 -> V_205 , V_268 , V_211 ) ;
if ( V_33 )
break;
}
if ( V_33 || F_116 ( & V_211 -> V_216 ) ) {
int V_198 ;
if ( V_33 )
F_70 ( & V_193 -> V_213 , 0 ) ;
V_198 = F_158 ( V_193 ) ;
return V_33 ? V_33 : V_198 ;
}
F_20 ( V_211 -> V_217 == NULL ) ;
V_211 -> V_217 = F_157 ;
V_211 -> V_218 = ( void * ) V_193 ;
return 0 ;
}
static int F_162 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_270 * V_271 , T_2 V_268 , T_1 V_265 )
{
struct V_210 * V_193 = NULL ;
struct V_194 V_195 = { { { 0 } } } ;
int V_33 = 0 ;
V_193 = F_163 () ;
if ( V_193 == NULL )
return - V_104 ;
V_195 . V_269 = V_271 ;
V_195 . V_255 = V_265 ;
V_33 = F_159 ( exp , & V_195 , V_268 , V_193 ) ;
if ( V_33 == 0 )
V_33 = F_164 ( V_193 ) ;
F_165 ( V_193 ) ;
return V_33 ;
}
static int F_166 ( unsigned int V_157 , struct V_60 * exp , int V_272 ,
void * V_273 , void * V_274 )
{
struct V_1 * V_275 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_275 -> V_5 . V_4 ;
int V_10 = 0 , V_33 = 0 , V_110 = V_4 -> V_15 . V_16 ;
struct V_25 * V_96 ;
switch ( V_157 ) {
case V_276 : {
struct V_277 * V_24 = V_273 ;
struct V_1 * V_51 ;
struct V_270 V_278 = { 0 } ;
T_1 V_21 ;
T_1 V_265 ;
memcpy ( & V_21 , V_24 -> V_279 , sizeof( T_1 ) ) ;
if ( ( V_21 >= V_110 ) )
return - V_48 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_280 ;
if ( ! V_4 -> V_17 [ V_21 ] -> V_69 )
return - V_281 ;
V_51 = F_31 ( V_4 -> V_17 [ V_21 ] -> V_47 ) ;
if ( ! V_51 )
return - V_34 ;
if ( F_167 ( V_24 -> V_282 , F_168 ( V_51 ) ,
F_169 ( ( int ) V_24 -> V_283 ,
( int ) sizeof( struct V_25 ) ) ) )
return - V_284 ;
V_265 = V_274 ? * ( T_1 * ) V_274 : 0 ;
V_33 = V_270 ( NULL , V_4 -> V_17 [ V_21 ] -> V_47 , & V_278 ,
F_170 ( - V_285 ) ,
V_265 ) ;
if ( V_33 )
return V_33 ;
if ( F_167 ( V_24 -> V_286 , & V_278 ,
F_169 ( ( int ) V_24 -> V_287 ,
( int ) sizeof( V_278 ) ) ) )
return - V_284 ;
break;
}
case V_288 : {
struct V_277 * V_24 ;
struct V_117 * V_15 ;
char * V_289 = NULL ;
T_1 * V_156 ;
V_272 = 0 ;
if ( F_171 ( & V_289 , & V_272 , ( void * ) V_274 ) )
return - V_34 ;
V_24 = (struct V_277 * ) V_289 ;
if ( sizeof( * V_15 ) > V_24 -> V_290 ) {
F_172 ( V_289 , V_272 ) ;
return - V_34 ;
}
if ( sizeof( V_96 -> V_74 ) * V_110 > V_24 -> V_291 ) {
F_172 ( V_289 , V_272 ) ;
return - V_34 ;
}
if ( sizeof( T_1 ) * V_110 > V_24 -> V_292 ) {
F_172 ( V_289 , V_272 ) ;
return - V_34 ;
}
V_15 = (struct V_117 * ) V_24 -> V_293 ;
memcpy ( V_15 , & ( V_4 -> V_15 ) , sizeof( * V_15 ) ) ;
V_96 = (struct V_25 * ) V_24 -> V_279 ;
V_156 = ( T_1 * ) V_24 -> V_294 ;
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ , V_96 ++ , V_156 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
* V_96 = V_4 -> V_17 [ V_10 ] -> V_35 ;
* V_156 = V_4 -> V_17 [ V_10 ] -> V_76 ;
}
if ( F_167 ( ( void * ) V_274 , V_289 , V_272 ) )
V_33 = - V_284 ;
F_172 ( V_289 , V_272 ) ;
break;
}
case V_295 :
V_33 = F_173 ( exp , V_272 , V_273 , V_274 ) ;
break;
case V_296 :
V_33 = F_174 ( exp , V_273 , V_274 ) ;
break;
case V_297 :
V_33 = F_175 ( exp , V_273 , V_274 ) ;
break;
case V_298 : {
struct V_299 * V_300 = V_273 ;
struct V_11 * V_12 = NULL ;
struct V_301 * V_302 ;
if ( V_300 -> V_303 == V_304 ) {
if ( V_300 -> V_305 < 0 || V_110 <= V_300 -> V_305 )
return - V_34 ;
V_12 = V_4 -> V_17 [ V_300 -> V_305 ] ;
if ( ! V_12 || ! V_12 -> V_47 )
return - V_34 ;
} else if ( V_300 -> V_303 == V_306 ) {
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 ||
! F_38 ( & V_12 -> V_35 ,
& V_300 -> V_25 ) )
continue;
if ( V_12 -> V_47 == NULL )
return - V_34 ;
break;
}
} else {
return - V_34 ;
}
if ( V_10 >= V_110 )
return - V_280 ;
F_20 ( V_12 && V_12 -> V_47 ) ;
F_48 ( V_302 ) ;
if ( ! V_302 )
return - V_104 ;
F_176 ( V_302 , V_300 ) ;
V_33 = V_301 ( V_12 -> V_47 , V_302 ) ;
if ( V_33 == 0 ) {
F_176 ( V_300 , V_302 ) ;
V_300 -> V_303 = V_304 ;
V_300 -> V_25 = V_12 -> V_35 ;
}
F_50 ( V_302 ) ;
break;
}
default: {
int V_193 = 0 ;
if ( V_110 == 0 )
return - V_307 ;
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ ) {
int V_198 ;
struct V_1 * V_51 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_51 = F_31 ( V_4 -> V_17 [ V_10 ] -> V_47 ) ;
V_51 -> V_72 = V_275 -> V_72 ;
V_198 = F_177 ( V_157 , V_4 -> V_17 [ V_10 ] -> V_47 ,
V_272 , V_273 , V_274 ) ;
if ( V_198 == - V_281 && V_157 == V_308 ) {
return V_198 ;
} else if ( V_198 ) {
if ( V_4 -> V_17 [ V_10 ] -> V_69 ) {
F_8 ( V_198 == - V_307 ?
V_309 : V_310 ,
L_88
L_89 ,
F_54 ( V_4 , V_10 ) ,
V_10 , V_157 , V_198 ) ;
if ( ! V_33 )
V_33 = V_198 ;
}
} else {
V_193 = 1 ;
}
}
if ( ! V_193 && ! V_33 )
V_33 = - V_188 ;
}
}
return V_33 ;
}
T_9 F_178 ( struct V_311 * V_312 ,
struct V_170 * V_175 , T_9 V_313 ,
T_9 V_314 , int * V_315 )
{
T_9 V_316 = V_312 -> V_317 [ 0 ] . V_318 ;
T_3 V_319 , V_320 ;
T_9 V_321 ;
int V_322 = - 1 , V_10 ;
if ( V_312 -> V_323 == 0 ||
V_312 -> V_317 [ 0 ] . V_318 == 0 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_175 -> V_182 ; V_10 ++ ) {
if ( V_175 -> V_183 [ V_10 ] -> V_184 ==
V_312 -> V_317 [ 0 ] . V_324 ) {
V_322 = V_10 ;
break;
}
}
if ( V_322 == - 1 )
return - V_34 ;
if ( ( F_137 ( V_175 , V_322 , V_313 , V_314 ,
& V_319 , & V_320 ) ) != 0 &&
V_316 < V_320 ) {
V_321 = V_316 ;
* V_315 = V_322 ;
} else {
V_321 = 0 ;
* V_315 = ( V_322 + 1 ) % V_175 -> V_182 ;
}
return V_321 ;
}
int F_179 ( struct V_170 * V_175 , T_9 V_313 ,
T_9 V_314 , int V_315 ,
int * V_325 )
{
int V_326 ;
T_3 V_327 , V_328 ;
int V_10 , V_329 ;
if ( V_314 - V_313 > V_175 -> V_215 * V_175 -> V_182 ) {
V_326 = ( V_315 < 1 ? V_175 -> V_182 - 1 :
V_315 - 1 ) ;
* V_325 = V_175 -> V_182 ;
} else {
for ( V_329 = 0 , V_10 = V_315 ; V_329 < V_175 -> V_182 ;
V_10 = ( V_10 + 1 ) % V_175 -> V_182 , V_329 ++ ) {
if ( ( F_137 ( V_175 , V_10 , V_313 , V_314 ,
& V_327 , & V_328 ) ) == 0 )
break;
}
* V_325 = V_329 ;
V_326 = ( V_315 + V_329 - 1 ) % V_175 -> V_182 ;
}
return V_326 ;
}
void F_180 ( struct V_311 * V_312 ,
struct V_330 * V_331 ,
int V_332 , unsigned int V_333 ,
int V_334 )
{
char * V_335 ;
int V_336 ;
for ( V_336 = 0 ; V_336 < V_333 ; V_336 ++ ) {
V_331 [ V_336 ] . V_324 = V_332 ;
V_331 [ V_336 ] . V_337 |= V_338 ;
}
V_335 = ( char * ) V_312 + F_181 ( V_334 ) ;
memcpy ( V_335 , V_331 , V_333 * sizeof( struct V_330 ) ) ;
}
static int F_182 ( struct V_3 * V_4 , T_1 V_339 , void * V_340 ,
T_1 * V_341 , void * V_111 , struct V_170 * V_175 )
{
struct V_342 * V_343 = V_340 ;
struct V_311 * V_312 = V_111 ;
struct V_311 * V_344 = NULL ;
struct V_330 * V_331 ;
int V_345 ;
unsigned int V_346 = 0 ;
int V_332 = 0 , V_347 , V_315 ;
T_9 V_313 , V_314 , V_348 , V_321 ;
T_9 V_349 ;
int V_334 = 0 , V_33 = 0 , V_10 ;
int V_350 = 0 ;
int V_351 = 0 ;
int V_326 ;
int V_352 = 0 , V_353 = 0 , V_325 ;
unsigned int V_354 = V_355 ;
if ( ! F_183 ( V_175 ) )
GOTO ( V_75 , V_33 = 0 ) ;
if ( F_181 ( V_343 -> V_312 . V_323 ) < V_354 )
V_354 = F_181 ( V_343 -> V_312 . V_323 ) ;
F_184 ( V_344 , V_354 ) ;
if ( V_344 == NULL )
GOTO ( V_75 , V_33 = - V_104 ) ;
V_331 = & V_344 -> V_317 [ 0 ] ;
V_345 = F_185 ( V_354 ) ;
memcpy ( V_312 , & V_343 -> V_312 , sizeof( * V_312 ) ) ;
V_313 = V_312 -> V_313 ;
V_348 = V_312 -> V_348 ;
V_347 = V_315 = F_136 ( V_175 , V_313 ) ;
V_314 = ( V_348 == ~ 0ULL ? V_343 -> V_189 . V_356 :
V_313 + V_348 - 1 ) ;
if ( V_314 > V_343 -> V_189 . V_356 )
V_314 = V_343 -> V_189 . V_356 ;
V_326 = F_179 ( V_175 , V_313 , V_314 ,
V_347 , & V_325 ) ;
V_321 = F_178 ( V_312 , V_175 , V_313 ,
V_314 , & V_315 ) ;
if ( V_321 == - V_34 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( F_181 ( V_312 -> V_323 ) > * V_341 )
V_312 -> V_323 = F_185 ( * V_341 ) ;
if ( V_312 -> V_323 == 0 ) {
V_346 = 1 ;
V_345 = 0 ;
}
for ( V_352 = V_315 , V_10 = 0 ; V_10 < V_325 ;
V_10 ++ , V_352 = ( V_352 + 1 ) % V_175 -> V_182 ) {
T_9 V_357 ;
T_9 V_358 ;
T_3 V_319 , V_320 , V_359 ;
unsigned int V_333 ;
V_353 = V_352 ;
if ( ( F_137 ( V_175 , V_352 , V_313 , V_314 ,
& V_319 , & V_359 ) ) == 0 )
continue;
if ( V_321 != 0 && V_352 == V_315 )
V_319 = V_321 ;
if ( V_348 != ~ 0ULL ) {
if ( V_313 + V_348 < V_313 )
V_348 = ~ 0ULL - V_313 ;
V_320 = F_186 ( V_175 , V_313 + V_348 ,
V_352 ) ;
} else {
V_320 = ~ 0ULL ;
}
if ( V_319 == V_320 )
continue;
V_357 = V_359 - V_319 ;
V_344 -> V_348 = 0 ;
V_358 = 0 ;
V_350 = 0 ;
V_351 = 0 ;
do {
if ( V_346 == 0 ) {
if ( V_334 + V_345 >
V_312 -> V_323 )
V_345 = V_312 -> V_323 -
V_334 ;
}
V_319 += V_358 ;
V_344 -> V_348 = V_357 - V_358 ;
V_357 = V_344 -> V_348 ;
V_344 -> V_323 = V_345 ;
V_344 -> V_360 = 0 ;
V_344 -> V_361 = V_312 -> V_361 ;
V_343 -> V_189 . V_186 = V_175 -> V_183 [ V_352 ] -> V_185 ;
V_332 = V_175 -> V_183 [ V_352 ] -> V_184 ;
if ( V_332 < 0 || V_332 >= V_4 -> V_15 . V_16 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( ! V_4 -> V_17 [ V_332 ] -> V_69 ) {
V_344 -> V_361 |= V_362 ;
V_344 -> V_360 = 1 ;
V_331 [ 0 ] . V_318 = V_319 ;
V_331 [ 0 ] . V_363 = V_359 -
V_319 ;
V_331 [ 0 ] . V_337 |= V_364 ;
goto V_365;
}
V_344 -> V_313 = V_319 ;
V_344 -> V_361 &= ~ V_366 ;
memcpy ( & V_343 -> V_312 , V_344 , sizeof( * V_344 ) ) ;
* V_341 = F_181 ( V_344 -> V_323 ) ;
V_33 = F_187 ( NULL ,
V_4 -> V_17 [ V_332 ] -> V_47 ,
V_339 , V_340 , V_341 , V_344 , V_175 ) ;
if ( V_33 != 0 )
GOTO ( V_75 , V_33 ) ;
V_365:
V_333 = V_344 -> V_360 ;
if ( V_333 == 0 ) {
V_351 = 1 ;
if ( V_353 == V_326 ) {
V_312 -> V_360 = 0 ;
goto V_367;
}
break;
}
if ( V_346 ) {
V_334 += V_333 ;
break;
}
V_358 = V_331 [ V_333 - 1 ] . V_318 -
V_319 + V_331 [ V_333 - 1 ] . V_363 ;
if ( V_357 <= V_358 )
V_351 = 1 ;
if ( V_331 [ V_333 - 1 ] . V_337 & V_362 )
V_331 [ V_333 - 1 ] . V_337 &=
~ V_362 ;
V_349 = F_188 ( V_175 ,
V_331 [ V_333 - 1 ] . V_318 +
V_331 [ V_333 - 1 ] . V_363 ,
V_352 ) ;
if ( V_349 >= V_343 -> V_189 . V_356 )
V_350 = 1 ;
F_180 ( V_312 , V_331 ,
V_332 , V_333 ,
V_334 ) ;
V_334 += V_333 ;
if ( V_334 >= V_312 -> V_323 )
goto V_367;
} while ( V_351 == 0 && V_350 == 0 );
if ( V_353 == V_326 )
goto V_367;
}
V_367:
if ( V_175 -> V_182 > 1 )
V_312 -> V_361 |= V_366 ;
if ( V_346 )
goto V_368;
if ( V_353 == V_326 ) {
if ( V_351 || V_350 )
V_312 -> V_317 [ V_334 - 1 ] . V_337 |=
V_362 ;
}
V_368:
V_312 -> V_360 = V_334 ;
V_75:
F_189 ( V_344 , V_354 ) ;
return V_33 ;
}
static int F_190 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_1 V_339 , void * V_340 , T_1 * V_341 , void * V_111 ,
struct V_170 * V_175 )
{
struct V_1 * V_275 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_275 -> V_5 . V_4 ;
int V_10 , V_33 ;
if ( ! V_341 || ! V_111 )
return - V_284 ;
F_26 ( V_275 ) ;
if ( F_191 ( V_369 ) ) {
struct {
char V_370 [ 16 ] ;
struct V_371 * V_372 ;
} * V_24 = V_340 ;
struct V_373 * V_374 = & V_24 -> V_372 -> V_375 -> V_376 ;
struct V_236 * V_260 ;
T_1 * V_240 = V_111 ;
if ( * V_341 < sizeof( * V_240 ) )
GOTO ( V_75 , V_33 = - V_284 ) ;
* V_341 = sizeof( * V_240 ) ;
for ( V_10 = 0 ; V_10 < V_175 -> V_182 ; V_10 ++ ) {
V_260 = V_175 -> V_183 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_260 -> V_184 ] )
continue;
if ( V_4 -> V_17 [ V_260 -> V_184 ] -> V_47 ==
V_24 -> V_372 -> V_377 &&
F_192 ( & V_260 -> V_185 , V_374 ) ) {
* V_240 = V_10 ;
GOTO ( V_75 , V_33 = 0 ) ;
}
}
F_193 ( V_24 -> V_372 , L_90 ) ;
F_194 ( V_378 , V_175 ) ;
GOTO ( V_75 , V_33 = - V_379 ) ;
} else if ( F_191 ( V_380 ) ) {
struct V_381 * V_382 = V_111 ;
T_1 V_383 = sizeof( V_384 ) ;
struct V_11 * V_12 ;
F_20 ( * V_341 == sizeof( struct V_381 ) ) ;
V_12 = V_4 -> V_17 [ V_382 -> V_267 ] ;
if ( ! V_12 || ! V_12 -> V_69 )
GOTO ( V_75 , V_33 = - V_385 ) ;
V_33 = F_187 ( V_59 , V_12 -> V_47 , V_339 , V_340 ,
& V_383 , V_382 -> V_24 , NULL ) ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_191 ( V_386 ) ) {
struct V_117 * V_387 = V_111 ;
* V_387 = V_4 -> V_15 ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_191 ( V_388 ) ) {
V_33 = F_182 ( V_4 , V_339 , V_340 , V_341 , V_111 , V_175 ) ;
GOTO ( V_75 , V_33 ) ;
} else if ( F_191 ( V_389 ) ) {
struct V_11 * V_12 ;
T_2 V_176 = * ( ( T_2 * ) V_111 ) ;
F_20 ( * V_341 == sizeof( T_2 ) ) ;
F_20 ( V_176 < V_4 -> V_15 . V_16 ) ;
V_12 = V_4 -> V_17 [ V_176 ] ;
if ( ! V_12 || ! V_12 -> V_47 )
GOTO ( V_75 , V_33 = - V_385 ) ;
* ( ( T_2 * ) V_111 ) = F_195 ( V_12 -> V_47 ) ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_191 ( V_390 ) ) {
* ( ( int * ) V_111 ) = V_4 -> V_15 . V_16 ;
GOTO ( V_75 , V_33 = 0 ) ;
}
V_33 = - V_34 ;
V_75:
F_29 ( V_275 ) ;
return V_33 ;
}
static int F_196 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_4 V_339 , void * V_340 , T_4 V_341 ,
void * V_111 , struct V_210 * V_193 )
{
struct V_1 * V_275 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_275 -> V_5 . V_4 ;
T_4 V_110 ;
int V_10 , V_33 = 0 , V_198 ;
struct V_11 * V_12 ;
unsigned V_391 , V_392 ,
V_393 , V_394 ;
unsigned V_395 = 0 , V_396 = 0 , V_191 = 0 ;
V_391 = V_392 = V_393 = V_394 = 0 ;
if ( V_193 == NULL ) {
V_394 = 1 ;
V_193 = F_163 () ;
if ( ! V_193 )
return - V_104 ;
}
F_26 ( V_275 ) ;
V_110 = V_4 -> V_15 . V_16 ;
if ( F_191 ( V_397 ) ) {
V_110 = V_341 / sizeof( struct V_381 ) ;
V_341 = sizeof( V_384 ) ;
V_391 = sizeof( struct V_381 ) ;
V_393 = 1 ;
V_395 = 1 ;
} else if ( F_191 ( V_398 ) ) {
V_393 = 1 ;
} else if ( F_191 ( V_399 ) ) {
} else if ( F_191 ( V_400 ) ) {
V_396 = 1 ;
} else if ( F_191 ( V_401 ) ) {
V_191 = 1 ;
} else if ( F_191 ( V_108 ) ) {
F_20 ( V_4 -> V_107 == NULL ) ;
V_4 -> V_107 = V_111 ;
V_393 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_110 ; V_10 ++ , V_111 = ( char * ) V_111 + V_391 ) {
if ( V_395 ) {
V_12 = V_4 -> V_17 [ ( ( struct V_381 * )val )->idx] ;
}
int F_197 ( struct V_60 * exp , struct V_170 * V_175 ,
int V_157 , T_2 * V_402 )
{
T_1 V_403 = V_175 -> V_215 ;
T_2 V_232 ;
V_232 = * V_402 ;
F_198 ( V_232 , V_403 ) ;
V_232 = V_232 * V_403 ;
F_8 ( V_404 , L_91 V_114 L_92 V_114
L_93 V_114 L_23 , * V_402 , V_403 , V_232 ,
V_232 + V_403 - 1 ) ;
if ( V_157 == V_405 ) {
* V_402 = V_232 + V_403 - 1 ;
} else if ( V_157 == V_406 ) {
* V_402 = V_232 ;
} else {
F_98 () ;
}
return 0 ;
}
void F_199 ( struct V_170 * V_407 )
{
F_20 ( V_407 -> V_408 != F_200 () ) ;
F_201 ( & V_407 -> V_409 ) ;
F_20 ( V_407 -> V_408 == 0 ) ;
V_407 -> V_408 = F_200 () ;
}
void F_202 ( struct V_170 * V_407 )
{
F_20 ( V_407 -> V_408 == F_200 () ) ;
V_407 -> V_408 = 0 ;
F_203 ( & V_407 -> V_409 ) ;
}
static int F_204 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_301 * V_302 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
T_2 V_410 = 0 ;
T_2 V_411 = 0 ;
int V_10 , V_33 = 0 ;
if ( V_302 -> V_412 != V_413 &&
V_302 -> V_412 != V_414 &&
V_302 -> V_412 != V_415 &&
V_302 -> V_412 != V_416 &&
V_302 -> V_412 != V_417 &&
V_302 -> V_412 != V_418 ) {
F_15 ( L_94 , V_302 -> V_412 ) ;
return - V_284 ;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_198 ;
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 )
continue;
if ( ! V_12 -> V_69 || V_12 -> V_18 ) {
if ( V_302 -> V_412 == V_415 &&
V_4 -> V_17 [ V_10 ] -> V_67 ) {
V_33 = - V_419 ;
F_15 ( L_95 , V_10 ) ;
} else {
F_8 ( V_243 , L_95 , V_10 ) ;
}
continue;
}
V_198 = V_301 ( V_12 -> V_47 , V_302 ) ;
if ( V_198 ) {
if ( V_12 -> V_69 && ! V_33 )
V_33 = V_198 ;
continue;
}
if ( V_302 -> V_412 == V_415 ) {
V_410 += V_302 -> V_420 . V_421 ;
V_411 += V_302 -> V_420 . V_422 ;
}
}
F_29 ( V_2 ) ;
if ( V_302 -> V_412 == V_415 ) {
V_302 -> V_420 . V_421 = V_410 ;
V_302 -> V_420 . V_422 = V_411 ;
}
return V_33 ;
}
static int F_205 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_301 * V_302 )
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
V_33 = - V_188 ;
goto V_75;
}
}
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_198 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_67 )
continue;
V_198 = F_206 ( V_4 -> V_17 [ V_10 ] -> V_47 , V_302 ) ;
if ( V_198 && ! V_33 )
V_33 = V_198 ;
}
V_75:
F_29 ( V_2 ) ;
return V_33 ;
}
int T_10 F_207 ( void )
{
struct V_124 V_125 = { 0 } ;
int V_33 ;
F_8 ( V_80 , L_98 , & V_423 ) ;
V_33 = F_208 ( V_423 ) ;
if ( V_33 )
return V_33 ;
V_424 = F_209 ( L_99 ,
sizeof( struct V_236 ) ,
0 , V_425 , NULL ) ;
if ( V_424 == NULL ) {
F_210 ( V_423 ) ;
return - V_104 ;
}
F_75 ( & V_125 ) ;
V_33 = F_211 ( & V_426 , NULL , V_125 . V_427 ,
V_428 , & V_429 ) ;
if ( V_33 ) {
F_212 ( V_424 ) ;
F_210 ( V_423 ) ;
}
return V_33 ;
}
static void F_213 ( void )
{
F_214 ( V_428 ) ;
F_212 ( V_424 ) ;
F_210 ( V_423 ) ;
}
