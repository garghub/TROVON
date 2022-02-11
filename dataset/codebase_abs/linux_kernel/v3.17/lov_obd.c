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
F_8 ( V_80 , L_22 ,
V_21 , F_16 ( & V_12 -> V_35 ) ,
V_12 -> V_47 -> V_82 . V_83 ) ;
if ( F_38 ( V_74 , & V_12 -> V_35 ) )
break;
}
if ( V_21 == V_4 -> V_15 . V_16 )
GOTO ( V_75 , V_21 = - V_34 ) ;
if ( V_78 == V_84 || V_78 == V_81 ) {
V_22 = ( V_78 == V_81 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_67 == V_22 ) {
F_8 ( V_80 , L_23 ,
V_74 -> V_74 , V_22 ? L_9 : L_24 ) ;
} else {
V_4 -> V_17 [ V_21 ] -> V_67 = V_22 ;
F_8 ( V_14 , L_25 ,
V_22 ? L_9 : L_24 , F_16 ( V_74 ) ) ;
}
} else if ( V_78 == V_85 || V_78 == V_86 ) {
V_79 = ( V_78 == V_86 ) ? 1 : 0 ;
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
static int F_28 ( struct V_1 * V_2 , struct V_1 * V_87 ,
enum V_77 V_78 , void * V_24 )
{
int V_33 = 0 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
F_39 ( & V_4 -> V_88 ) ;
if ( ! V_4 -> V_65 ) {
F_40 ( & V_4 -> V_88 ) ;
return V_33 ;
}
if ( V_78 == V_86 || V_78 == V_85 ||
V_78 == V_81 || V_78 == V_84 ) {
struct V_25 * V_74 ;
F_20 ( V_87 ) ;
if ( strcmp ( V_87 -> V_56 -> V_57 , V_89 ) ) {
F_40 ( & V_4 -> V_88 ) ;
F_15 ( L_29 ,
V_87 -> V_56 -> V_57 ,
V_87 -> V_49 ) ;
return - V_34 ;
}
V_74 = & V_87 -> V_5 . V_38 . V_90 ;
V_33 = F_37 ( V_2 , V_74 , V_78 ) ;
if ( V_33 < 0 ) {
F_40 ( & V_4 -> V_88 ) ;
F_15 ( L_30 , V_78 ,
F_16 ( V_74 ) , V_33 ) ;
return V_33 ;
}
V_24 = & V_33 ;
}
if ( V_87 ) {
V_33 = F_41 ( V_2 , V_87 , V_78 , V_24 ) ;
} else {
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_91 ;
V_24 = & V_10 ;
V_91 = ( V_78 == V_92 ) ||
( V_78 == V_93 ) ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_91 && ! V_4 -> V_17 [ V_10 ] -> V_69 )
continue;
V_33 = F_41 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_36 ,
V_78 , V_24 ) ;
if ( V_33 ) {
F_15 ( L_31 ,
V_2 -> V_49 ,
V_2 -> V_94 -> V_49 ,
V_4 -> V_17 [ V_10 ] -> V_36 -> V_49 ,
V_33 ) ;
}
}
F_29 ( V_2 ) ;
}
F_40 ( & V_4 -> V_88 ) ;
return V_33 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_25 * V_95 ,
T_1 V_21 , int V_96 , int V_79 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
struct V_1 * V_27 ;
int V_33 ;
F_8 ( V_14 , L_32 ,
V_95 -> V_74 , V_21 , V_96 , V_79 ) ;
if ( V_96 <= 0 ) {
F_15 ( L_33 ,
V_95 -> V_74 , V_96 ) ;
return - V_34 ;
}
V_27 = F_43 ( V_95 , V_89 ,
& V_2 -> V_25 ) ;
if ( V_27 == NULL )
return - V_34 ;
F_2 ( & V_4 -> V_6 ) ;
if ( ( V_21 < V_4 -> V_97 ) && ( V_4 -> V_17 [ V_21 ] != NULL ) ) {
V_12 = V_4 -> V_17 [ V_21 ] ;
F_15 ( L_34 ,
F_16 ( & V_12 -> V_35 ) , V_21 ) ;
F_4 ( & V_4 -> V_6 ) ;
return - V_98 ;
}
if ( V_21 >= V_4 -> V_97 ) {
struct V_11 * * V_99 , * * V_100 = NULL ;
T_1 V_101 , V_102 = 0 ;
V_101 = F_44 ( T_1 , V_4 -> V_97 , 2 ) ;
while ( V_101 < V_21 + 1 )
V_101 = V_101 << 1 ;
F_45 ( V_99 , sizeof( * V_99 ) * V_101 ) ;
if ( V_99 == NULL ) {
F_4 ( & V_4 -> V_6 ) ;
return - V_103 ;
}
if ( V_4 -> V_97 ) {
memcpy ( V_99 , V_4 -> V_17 , sizeof( * V_99 ) *
V_4 -> V_97 ) ;
V_100 = V_4 -> V_17 ;
V_102 = V_4 -> V_97 ;
}
V_4 -> V_17 = V_99 ;
V_4 -> V_97 = V_101 ;
F_46 () ;
if ( V_100 )
F_47 ( V_100 , sizeof( * V_100 ) * V_102 ) ;
F_8 ( V_14 , L_35 ,
V_4 -> V_17 , V_4 -> V_97 ) ;
}
F_48 ( V_12 ) ;
if ( ! V_12 ) {
F_4 ( & V_4 -> V_6 ) ;
return - V_103 ;
}
V_33 = F_49 ( & V_4 -> V_20 , V_21 , V_4 -> V_97 ) ;
if ( V_33 ) {
F_4 ( & V_4 -> V_6 ) ;
F_50 ( V_12 ) ;
return V_33 ;
}
V_12 -> V_35 = * V_95 ;
V_12 -> V_36 = V_27 ;
V_12 -> V_76 = V_96 ;
V_12 -> V_104 = V_21 ;
V_12 -> V_67 = V_79 ;
V_4 -> V_17 [ V_21 ] = V_12 ;
if ( V_21 >= V_4 -> V_15 . V_16 )
V_4 -> V_15 . V_16 = V_21 + 1 ;
F_4 ( & V_4 -> V_6 ) ;
F_8 ( V_14 , L_36 ,
V_21 , V_12 -> V_76 , V_4 -> V_15 . V_16 ) ;
V_33 = F_51 ( V_2 , V_27 , V_105 , & V_21 ) ;
if ( V_4 -> V_65 == 0 ) {
return 0 ;
}
F_26 ( V_2 ) ;
V_33 = F_14 ( V_2 , V_21 , V_79 , & V_4 -> V_66 ) ;
if ( V_33 )
GOTO ( V_75 , V_33 ) ;
if ( ! V_12 -> V_47 )
GOTO ( V_75 , V_33 = 0 ) ;
if ( V_4 -> V_106 != NULL ) {
V_33 = F_52 ( NULL , V_12 -> V_47 ,
sizeof( V_107 ) , V_107 ,
sizeof( struct V_108 ) , V_4 -> V_106 ,
NULL ) ;
if ( V_33 < 0 )
GOTO ( V_75 , V_33 ) ;
}
V_33 = F_28 ( V_2 , V_12 -> V_47 -> V_52 ,
V_79 ? V_68 : V_85 ,
( void * ) & V_21 ) ;
V_75:
if ( V_33 ) {
F_15 ( L_37 , V_33 ,
F_16 ( & V_12 -> V_35 ) ) ;
F_35 ( V_2 , V_21 , NULL , 0 ) ;
}
F_29 ( V_2 ) ;
return V_33 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_21 ,
struct V_25 * V_95 , int V_96 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_109 = V_4 -> V_15 . V_16 ;
int V_33 = 0 ;
if ( V_21 >= V_109 ) {
F_15 ( L_38 ,
V_21 , V_109 ) ;
return - V_34 ;
}
F_53 ( & V_4 -> V_88 ) ;
F_26 ( V_2 ) ;
if ( ! V_4 -> V_17 [ V_21 ] ) {
F_15 ( L_39 , V_21 ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
if ( V_95 && ! F_38 ( V_95 , & V_4 -> V_17 [ V_21 ] -> V_35 ) ) {
F_15 ( L_40 ,
F_54 ( V_4 , V_21 ) , V_21 ,
F_16 ( V_95 ) ) ;
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
F_55 ( & V_4 -> V_88 ) ;
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
void F_57 ( T_2 * V_110 )
{
if ( * V_110 < V_111 ) {
if ( * V_110 != 0 )
F_58 ( L_44
L_45 ,
V_112 ) ;
* V_110 = V_112 ;
} else if ( * V_110 & ( V_111 - 1 ) ) {
* V_110 &= ~ ( V_111 - 1 ) ;
F_59 ( L_46 ,
* V_110 , V_111 ) ;
}
}
void F_60 ( T_1 * V_110 )
{
if ( * V_110 == 0 )
* V_110 = 1 ;
}
void F_61 ( T_1 * V_110 )
{
if ( ( * V_110 != 0 ) && ( * V_110 != V_113 ) ) {
F_59 ( L_47 , * V_110 ) ;
* V_110 = 0 ;
}
}
void F_62 ( T_1 * V_110 )
{
if ( * V_110 == 0 )
* V_110 = V_114 ;
}
void F_63 ( struct V_115 * V_15 )
{
F_57 ( & V_15 -> V_116 ) ;
F_60 ( & V_15 -> V_117 ) ;
F_61 ( & V_15 -> V_118 ) ;
F_62 ( & V_15 -> V_119 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
struct V_122 V_123 = { NULL } ;
struct V_115 * V_15 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_33 ;
if ( F_65 ( V_121 , 1 ) < 1 ) {
F_15 ( L_48 ) ;
return - V_34 ;
}
V_15 = (struct V_115 * ) F_66 ( V_121 , 1 ) ;
if ( sizeof( * V_15 ) > F_65 ( V_121 , 1 ) ) {
F_15 ( L_49 ,
( int ) sizeof( * V_15 ) , F_65 ( V_121 , 1 ) ) ;
return - V_34 ;
}
if ( V_15 -> V_124 != V_125 ) {
if ( V_15 -> V_124 == F_67 ( V_125 ) ) {
F_8 ( V_126 , L_50 ,
V_2 -> V_49 , V_15 ) ;
F_68 ( V_15 ) ;
} else {
F_15 ( L_51 ,
V_2 -> V_49 , V_15 -> V_124 ) ;
return - V_34 ;
}
}
F_63 ( V_15 ) ;
V_15 -> V_70 = 0 ;
V_4 -> V_15 = * V_15 ;
V_4 -> V_97 = 0 ;
F_69 ( & V_4 -> V_6 ) ;
F_70 ( & V_4 -> V_7 , 0 ) ;
V_4 -> V_40 = V_127 ;
F_71 ( & V_4 -> V_88 ) ;
V_4 -> V_128 = F_72 ( L_52 , V_129 ,
V_130 ,
V_131 , 0 ,
V_132 ,
V_133 ,
& V_134 ,
V_135 ) ;
F_73 ( & V_4 -> V_136 ) ;
V_4 -> V_137 = 0 ;
V_33 = F_74 ( & V_4 -> V_20 , 0 ) ;
if ( V_33 )
GOTO ( V_75 , V_33 ) ;
F_75 ( & V_123 ) ;
F_76 ( V_2 , V_123 . V_138 ) ;
#if F_77 ( V_139 )
{
int V_140 ;
V_140 = F_78 ( V_2 -> V_141 , L_53 ,
0444 , & V_142 , V_2 ) ;
if ( V_140 )
F_79 ( L_54 ) ;
}
#endif
V_4 -> V_143 = F_80 ( L_55 ,
V_2 -> V_141 ,
NULL , NULL ) ;
return 0 ;
V_75:
return V_33 ;
}
static int F_81 ( struct V_1 * V_2 , enum V_144 V_145 )
{
int V_33 = 0 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
switch ( V_145 ) {
case V_146 : {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_69 )
continue;
F_82 ( F_31 ( V_4 -> V_17 [ V_10 ] -> V_47 ) ,
V_146 ) ;
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
struct V_147 * V_148 , * V_149 ;
struct V_150 * V_151 ;
F_84 (pos, tmp, &lov->lov_pool_list) {
V_151 = F_85 ( V_148 , struct V_150 , V_152 ) ;
F_8 ( V_80 , L_56 , V_151 ) ;
F_86 ( V_2 , V_151 -> V_153 ) ;
}
F_87 ( V_4 -> V_128 ) ;
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
F_15 ( L_57
L_58 ,
V_10 , V_4 -> V_8 ,
F_90 ( & V_4 -> V_7 ) ) ;
F_35 ( V_2 , V_10 , NULL , 0 ) ;
}
F_29 ( V_2 ) ;
F_47 ( V_4 -> V_17 , sizeof( * V_4 -> V_17 ) *
V_4 -> V_97 ) ;
V_4 -> V_97 = 0 ;
}
return 0 ;
}
int F_91 ( struct V_1 * V_2 , struct V_120 * V_121 ,
T_1 * V_154 , int * V_155 )
{
struct V_25 V_25 ;
int V_156 ;
int V_33 = 0 ;
switch ( V_156 = V_121 -> V_157 ) {
case V_158 :
case V_159 :
case V_160 : {
T_1 V_21 ;
int V_96 ;
if ( F_65 ( V_121 , 1 ) > sizeof( V_25 . V_74 ) )
GOTO ( V_75 , V_33 = - V_34 ) ;
F_92 ( & V_25 , F_66 ( V_121 , 1 ) ) ;
if ( sscanf ( F_66 ( V_121 , 2 ) , L_59 , V_154 ) != 1 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( sscanf ( F_66 ( V_121 , 3 ) , L_59 , V_155 ) != 1 )
GOTO ( V_75 , V_33 = - V_34 ) ;
V_21 = * V_154 ;
V_96 = * V_155 ;
if ( V_156 == V_158 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_96 , 1 ) ;
else if ( V_156 == V_159 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_96 , 0 ) ;
else
V_33 = F_35 ( V_2 , V_21 , & V_25 , V_96 ) ;
GOTO ( V_75 , V_33 ) ;
}
case V_161 : {
struct V_122 V_123 = { NULL } ;
struct V_115 * V_15 = & ( V_2 -> V_5 . V_4 . V_15 ) ;
if ( ! V_15 )
GOTO ( V_75 , V_33 = - V_34 ) ;
F_75 ( & V_123 ) ;
V_33 = F_93 ( V_162 , V_123 . V_138 ,
V_121 , V_2 ) ;
if ( V_33 > 0 )
V_33 = 0 ;
GOTO ( V_75 , V_33 ) ;
}
case V_163 :
case V_164 :
case V_165 :
case V_166 :
GOTO ( V_75 , V_33 ) ;
default: {
F_15 ( L_60 , V_121 -> V_157 ) ;
GOTO ( V_75 , V_33 = - V_34 ) ;
}
}
V_75:
return V_33 ;
}
static int F_94 ( struct V_60 * exp , struct V_167 * V_168 ,
struct V_169 * * V_170 , struct V_171 * V_172 )
{
struct V_169 * V_173 , * V_174 ;
struct V_3 * V_4 = & exp -> V_52 -> V_5 . V_4 ;
unsigned V_175 ;
int V_33 , V_10 ;
F_20 ( V_168 -> V_176 & V_177 &&
V_168 -> V_178 & V_179 ) ;
F_45 ( V_173 , sizeof( * V_173 ) ) ;
if ( V_173 == NULL )
return - V_103 ;
V_175 = V_168 -> V_180 ;
V_174 = * V_170 ;
if ( V_174 == NULL )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( V_175 >= V_4 -> V_15 . V_16 ||
! V_4 -> V_17 [ V_175 ] )
GOTO ( V_75 , V_33 = - V_34 ) ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
if ( V_174 -> V_182 [ V_10 ] -> V_183 == V_175 ) {
if ( F_95 ( & V_174 -> V_182 [ V_10 ] -> V_184 ) !=
F_95 ( & V_168 -> V_185 ) )
GOTO ( V_75 , V_33 = - V_34 ) ;
break;
}
}
if ( V_10 == V_174 -> V_181 )
GOTO ( V_75 , V_33 = - V_34 ) ;
V_33 = F_96 ( NULL , V_4 -> V_17 [ V_175 ] -> V_47 ,
V_168 , & V_173 , V_172 ) ;
V_75:
F_47 ( V_173 , sizeof( * V_173 ) ) ;
return V_33 ;
}
static int F_97 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_167 * V_168 , struct V_169 * * V_170 ,
struct V_171 * V_172 )
{
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_170 != NULL ) ;
if ( exp == NULL )
return - V_34 ;
if ( ( V_168 -> V_176 & V_177 ) &&
V_168 -> V_178 == V_186 ) {
F_98 () ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
if ( ! V_4 -> V_15 . V_70 )
return - V_187 ;
F_26 ( exp -> V_52 ) ;
if ( ( V_168 -> V_176 & V_177 ) &&
( V_168 -> V_178 & V_179 ) ) {
V_33 = F_94 ( exp , V_168 , V_170 , V_172 ) ;
}
F_29 ( exp -> V_52 ) ;
return V_33 ;
}
static int F_99 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_167 * V_188 , struct V_169 * V_174 ,
struct V_171 * V_172 , struct V_60 * V_189 ,
void * V_190 )
{
struct V_191 * V_192 ;
struct V_193 V_194 ;
struct V_195 * V_196 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
int V_33 = 0 , V_197 = 0 ;
F_100 ( V_174 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
if ( V_188 -> V_176 & V_198 ) {
F_20 ( V_172 ) ;
F_20 ( V_172 -> V_199 ) ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
F_26 ( exp -> V_52 ) ;
V_33 = F_101 ( exp , & V_194 , V_188 , V_174 , V_172 , & V_192 ) ;
if ( V_33 )
GOTO ( V_75 , V_33 ) ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
if ( V_188 -> V_176 & V_198 )
V_172 -> V_199 = V_192 -> V_201 + V_196 -> V_202 ;
V_197 = F_103 ( V_59 , V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
V_196 -> V_204 . V_205 , NULL , V_172 , NULL , V_190 ) ;
V_197 = F_104 ( V_192 , V_196 , V_197 ) ;
if ( V_197 ) {
F_15 ( L_61 V_206 L_62
V_206 L_63 ,
exp -> V_52 -> V_49 , F_105 ( & V_188 -> V_185 ) ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) ,
V_196 -> V_203 , V_197 ) ;
if ( ! V_33 )
V_33 = V_197 ;
}
}
if ( V_33 == 0 ) {
F_20 ( F_106 ( V_174 -> V_207 ) != NULL ) ;
V_33 = F_106 ( V_174 -> V_207 ) -> F_107 ( V_174 , V_188 , V_189 ) ;
}
V_197 = F_108 ( V_192 ) ;
V_75:
F_29 ( exp -> V_52 ) ;
return V_33 ? V_33 : V_197 ;
}
static int F_109 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_193 * V_194 )
{
struct V_191 * V_192 ;
struct V_195 * V_196 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
int V_197 = 0 , V_33 = 0 ;
F_20 ( V_194 ) ;
F_100 ( V_194 -> V_208 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_110 ( exp , V_194 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
F_8 ( V_80 , L_64 V_206 L_65 V_206 L_66
L_67 , F_105 ( & V_194 -> V_205 -> V_185 ) , V_196 -> V_202 ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) , V_196 -> V_203 ) ;
V_33 = F_111 ( V_59 , V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 ) ;
V_197 = F_104 ( V_192 , V_196 , V_33 ) ;
if ( V_197 ) {
F_15 ( L_68 V_206 L_62
V_206 L_63 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_194 -> V_205 -> V_185 ) ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) ,
V_196 -> V_203 , V_197 ) ;
break;
}
}
V_33 = F_112 ( V_192 ) ;
if ( V_197 )
V_33 = V_197 ;
return V_33 ;
}
static int F_113 ( struct V_209 * V_210 ,
void * V_24 , int V_33 )
{
struct V_191 * V_211 = (struct V_191 * ) V_24 ;
int V_197 ;
if ( V_33 )
F_70 ( & V_211 -> V_212 , 0 ) ;
V_197 = F_112 ( V_211 ) ;
return V_33 ? V_33 : V_197 ;
}
static int F_114 ( struct V_60 * exp , struct V_193 * V_194 ,
struct V_209 * V_210 )
{
struct V_191 * V_211 ;
struct V_3 * V_4 ;
struct V_147 * V_148 ;
struct V_195 * V_196 ;
int V_33 = 0 , V_197 ;
F_20 ( V_194 ) ;
F_100 ( V_194 -> V_208 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_110 ( exp , V_194 , & V_211 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_64 V_206 L_69 ,
F_105 ( & V_194 -> V_208 -> V_213 ) , V_194 -> V_208 -> V_181 ,
V_194 -> V_208 -> V_214 ) ;
F_102 (pos, &lovset->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
F_8 ( V_80 , L_64 V_206 L_65 V_206 L_66
L_70 , F_105 ( & V_194 -> V_205 -> V_185 ) , V_196 -> V_202 ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) , V_196 -> V_203 ) ;
V_33 = F_115 ( V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 , V_210 ) ;
if ( V_33 ) {
F_15 ( L_68 V_206 L_71
V_206 L_63 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_194 -> V_205 -> V_185 ) ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) ,
V_196 -> V_203 , V_33 ) ;
GOTO ( V_75 , V_33 ) ;
}
}
if ( ! F_116 ( & V_210 -> V_215 ) ) {
F_20 ( V_33 == 0 ) ;
F_20 ( V_210 -> V_216 == NULL ) ;
V_210 -> V_216 = F_113 ;
V_210 -> V_217 = ( void * ) V_211 ;
return V_33 ;
}
V_75:
if ( V_33 )
F_70 ( & V_211 -> V_212 , 0 ) ;
V_197 = F_112 ( V_211 ) ;
return V_33 ? V_33 : V_197 ;
}
static int F_117 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_193 * V_194 , struct V_171 * V_172 )
{
struct V_191 * V_192 ;
struct V_3 * V_4 ;
struct V_147 * V_148 ;
struct V_195 * V_196 ;
int V_197 = 0 , V_33 = 0 ;
F_20 ( V_194 ) ;
F_100 ( V_194 -> V_208 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
F_20 ( ! ( V_194 -> V_205 -> V_176 & ~ ( V_218 | V_219 |
V_220 | V_221 |
V_222 | V_223 |
V_177 | V_224 |
V_225 | V_226 |
V_227 | V_228 |
V_229 ) ) ) ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_118 ( exp , V_194 , V_172 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
V_33 = F_119 ( V_59 , V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 , NULL ) ;
V_197 = F_120 ( V_192 , V_196 , V_33 ) ;
if ( V_197 ) {
F_15 ( L_72 V_206 L_62
V_206 L_63 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_192 -> V_230 -> V_205 -> V_185 ) ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) , V_196 -> V_203 ,
V_197 ) ;
if ( ! V_33 )
V_33 = V_197 ;
}
}
V_197 = F_121 ( V_192 ) ;
if ( ! V_33 )
V_33 = V_197 ;
return V_33 ;
}
static int F_122 ( struct V_209 * V_210 ,
void * V_24 , int V_33 )
{
struct V_191 * V_211 = (struct V_191 * ) V_24 ;
int V_197 ;
if ( V_33 )
F_70 ( & V_211 -> V_212 , 0 ) ;
V_197 = F_121 ( V_211 ) ;
return V_33 ? V_33 : V_197 ;
}
static int F_123 ( struct V_60 * exp , struct V_193 * V_194 ,
struct V_171 * V_172 ,
struct V_209 * V_210 )
{
struct V_191 * V_192 ;
struct V_195 * V_196 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_194 ) ;
F_100 ( V_194 -> V_208 ) ;
if ( V_194 -> V_205 -> V_176 & V_198 ) {
F_20 ( V_172 ) ;
F_20 ( V_172 -> V_199 ) ;
}
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_118 ( exp , V_194 , V_172 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_64 V_206 L_69 ,
F_105 ( & V_194 -> V_208 -> V_213 ) ,
V_194 -> V_208 -> V_181 ,
V_194 -> V_208 -> V_214 ) ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
if ( V_194 -> V_205 -> V_176 & V_198 )
V_172 -> V_199 = V_192 -> V_201 + V_196 -> V_202 ;
F_8 ( V_80 , L_64 V_206 L_65 V_206 L_66
L_70 , F_105 ( & V_194 -> V_205 -> V_185 ) , V_196 -> V_202 ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) , V_196 -> V_203 ) ;
V_33 = F_124 ( V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 , V_172 , V_210 ) ;
if ( V_33 ) {
F_15 ( L_73 V_206 L_71
V_206 L_63 ,
F_105 ( & V_192 -> V_230 -> V_205 -> V_185 ) ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) ,
V_196 -> V_203 , V_33 ) ;
break;
}
}
if ( V_33 || ! V_210 || F_116 ( & V_210 -> V_215 ) ) {
int V_197 ;
if ( V_33 )
F_70 ( & V_192 -> V_212 , 0 ) ;
V_197 = F_121 ( V_192 ) ;
return V_33 ? V_33 : V_197 ;
}
F_20 ( V_210 -> V_216 == NULL ) ;
V_210 -> V_216 = F_122 ;
V_210 -> V_217 = ( void * ) V_192 ;
return 0 ;
}
static int F_125 ( struct V_209 * V_210 ,
void * V_24 , int V_33 )
{
struct V_191 * V_211 = (struct V_191 * ) V_24 ;
int V_197 ;
if ( V_33 )
F_70 ( & V_211 -> V_212 , 0 ) ;
V_197 = F_126 ( V_211 ) ;
return V_33 ? V_33 : V_197 ;
}
static int F_127 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_193 * V_194 , struct V_171 * V_172 ,
struct V_209 * V_210 )
{
struct V_191 * V_192 ;
struct V_3 * V_4 ;
struct V_147 * V_148 ;
struct V_195 * V_196 ;
int V_33 = 0 ;
F_20 ( V_194 ) ;
F_100 ( V_194 -> V_208 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_128 ( exp , V_194 , V_172 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
V_33 = F_129 ( V_59 , V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 , NULL , V_210 ) ;
if ( V_33 ) {
F_15 ( L_74 V_206 L_62 V_206
L_63 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_192 -> V_230 -> V_205 -> V_185 ) ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) , V_196 -> V_203 , V_33 ) ;
break;
}
}
if ( V_33 || F_116 ( & V_210 -> V_215 ) ) {
int V_197 ;
V_197 = F_126 ( V_192 ) ;
return V_33 ? V_33 : V_197 ;
}
F_20 ( V_210 -> V_216 == NULL ) ;
V_210 -> V_216 = F_125 ;
V_210 -> V_217 = ( void * ) V_192 ;
return 0 ;
}
static int F_130 ( struct V_209 * V_210 ,
void * V_24 , int V_33 )
{
struct V_191 * V_211 = V_24 ;
int V_197 ;
if ( V_33 )
F_70 ( & V_211 -> V_212 , 0 ) ;
V_197 = F_131 ( V_211 ) ;
return V_33 ? : V_197 ;
}
static int F_132 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_193 * V_194 , T_3 V_231 , T_3 V_232 ,
struct V_209 * V_210 )
{
struct V_191 * V_192 = NULL ;
struct V_3 * V_4 ;
struct V_147 * V_148 ;
struct V_195 * V_196 ;
int V_33 = 0 ;
F_100 ( V_194 -> V_208 ) ;
F_20 ( V_210 != NULL ) ;
if ( ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_133 ( exp , V_194 , V_231 , V_232 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_75 V_206 L_76 ,
F_105 ( & V_192 -> V_230 -> V_205 -> V_185 ) , V_231 , V_232 ) ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
V_33 = F_134 ( V_59 , V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 , V_196 -> V_204 . V_233 . V_234 . V_231 ,
V_196 -> V_204 . V_233 . V_234 . V_232 , V_210 ) ;
if ( V_33 ) {
F_15 ( L_77 V_206 L_62 V_206
L_63 ,
exp -> V_52 -> V_49 ,
F_105 ( & V_192 -> V_230 -> V_205 -> V_185 ) ,
F_105 ( & V_196 -> V_204 . V_205 -> V_185 ) , V_196 -> V_203 ,
V_33 ) ;
break;
}
}
if ( V_33 || F_116 ( & V_210 -> V_215 ) ) {
int V_197 = F_131 ( V_192 ) ;
return V_33 ? : V_197 ;
}
F_20 ( V_210 -> V_216 == NULL ) ;
V_210 -> V_216 = F_130 ;
V_210 -> V_217 = ( void * ) V_192 ;
return 0 ;
}
static int F_135 ( struct V_3 * V_4 , struct V_193 * V_235 ,
T_4 V_236 , struct V_237 * V_238 )
{
struct V_193 V_194 = { { { 0 } } } ;
int V_10 , V_33 = 0 ;
V_194 . V_205 = V_235 -> V_205 ;
for ( V_10 = 0 ; V_10 < V_236 ; V_10 ++ ) {
int V_239 = F_136 ( V_235 -> V_208 , V_238 [ V_10 ] . V_240 ) ;
int V_241 = V_235 -> V_208 -> V_182 [ V_239 ] -> V_183 ;
T_3 V_231 , V_232 ;
if ( ! F_137 ( V_235 -> V_208 , V_10 , V_238 [ V_10 ] . V_240 ,
V_238 [ V_10 ] . V_240 + V_238 [ V_10 ] . V_109 - 1 ,
& V_231 , & V_232 ) )
continue;
if ( ! V_4 -> V_17 [ V_241 ] || ! V_4 -> V_17 [ V_241 ] -> V_69 ) {
F_8 ( V_242 , L_78 , V_241 ) ;
return - V_187 ;
}
V_33 = F_138 ( V_243 , V_4 -> V_17 [ V_241 ] -> V_47 , & V_194 ,
1 , & V_238 [ V_10 ] , NULL ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_139 ( int V_156 , struct V_60 * exp , struct V_193 * V_194 ,
T_4 V_236 , struct V_237 * V_238 ,
struct V_171 * V_172 )
{
struct V_191 * V_192 ;
struct V_195 * V_196 ;
struct V_147 * V_148 ;
struct V_3 * V_4 = & exp -> V_52 -> V_5 . V_4 ;
int V_197 , V_33 = 0 ;
F_100 ( V_194 -> V_208 ) ;
if ( V_156 == V_243 ) {
V_33 = F_135 ( V_4 , V_194 , V_236 , V_238 ) ;
return V_33 ;
}
V_33 = F_140 ( exp , V_194 , V_236 , V_238 , V_172 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
struct V_60 * V_244 ;
struct V_237 * V_245 ;
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
V_244 = V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ;
V_245 = V_192 -> V_246 + V_196 -> V_247 ;
V_33 = F_138 ( V_156 , V_244 , & V_196 -> V_204 , V_196 -> V_248 ,
V_245 , V_172 ) ;
if ( V_33 )
break;
F_104 ( V_192 , V_196 , V_33 ) ;
}
V_197 = F_141 ( V_192 ) ;
if ( ! V_33 )
V_33 = V_197 ;
return V_33 ;
}
static int F_142 ( struct V_209 * V_210 ,
void * V_24 , int V_33 )
{
struct V_191 * V_211 = (struct V_191 * ) V_24 ;
V_33 = F_143 ( V_211 , V_211 -> V_249 -> V_250 , V_33 , V_210 ) ;
return V_33 ;
}
static int F_144 ( struct V_60 * exp , struct V_193 * V_194 ,
struct V_251 * V_252 ,
struct V_209 * V_210 )
{
T_5 V_253 = V_252 -> V_250 ;
struct V_191 * V_192 ;
struct V_195 * V_196 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
T_6 V_33 ;
F_20 ( V_194 ) ;
F_100 ( V_194 -> V_208 ) ;
F_20 ( V_253 == ( V_253 & - V_253 ) ) ;
F_20 ( ( V_194 -> V_254 & V_255 ) == 0 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_145 ( exp , V_194 , V_252 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
V_33 = F_146 ( V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 , V_252 , V_210 ) ;
if ( V_33 != V_256 )
GOTO ( V_75 , V_33 ) ;
}
if ( V_210 && ! F_116 ( & V_210 -> V_215 ) ) {
F_20 ( V_33 == 0 ) ;
F_20 ( V_210 -> V_216 == NULL ) ;
V_210 -> V_216 = F_142 ;
V_210 -> V_217 = ( void * ) V_192 ;
return V_33 ;
}
V_75:
V_33 = F_143 ( V_192 , V_253 , V_33 , V_210 ) ;
return V_33 ;
}
static int F_147 ( struct V_60 * exp ,
struct V_169 * V_174 , T_7 V_257 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
F_100 ( V_174 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
struct V_169 V_258 ;
struct V_235 * V_259 = V_174 -> V_182 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_259 -> V_183 ] ) {
F_8 ( V_242 , L_79 , V_259 -> V_183 ) ;
continue;
}
V_258 . V_213 = V_259 -> V_184 ;
V_258 . V_181 = 0 ;
V_33 = F_148 ( V_4 -> V_17 [ V_259 -> V_183 ] -> V_47 ,
& V_258 , V_257 , V_24 ) ;
}
return V_33 ;
}
static int F_149 ( struct V_60 * exp ,
struct V_169 * V_174 , T_7 V_257 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
F_100 ( V_174 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
struct V_169 V_258 ;
struct V_235 * V_259 = V_174 -> V_182 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_259 -> V_183 ] ) {
F_8 ( V_242 , L_79 , V_259 -> V_183 ) ;
continue;
}
V_258 . V_213 = V_259 -> V_184 ;
V_258 . V_181 = 0 ;
V_33 = F_150 ( V_4 -> V_17 [ V_259 -> V_183 ] -> V_47 ,
& V_258 , V_257 , V_24 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return V_33 ;
}
static int F_151 ( struct V_60 * exp , struct V_169 * V_174 ,
T_1 V_253 , struct V_63 * V_260 )
{
struct V_191 * V_192 ;
struct V_193 V_194 ;
struct V_195 * V_196 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
struct V_63 * V_261 ;
int V_197 = 0 , V_33 = 0 ;
F_100 ( V_174 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
F_20 ( V_260 ) ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_152 ( exp , & V_194 , V_174 , V_253 , V_260 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
V_261 = V_192 -> V_262 -> V_263 + V_196 -> V_202 ;
V_33 = F_153 ( V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
V_196 -> V_204 . V_208 , V_253 , V_261 ) ;
V_33 = F_104 ( V_192 , V_196 , V_33 ) ;
if ( V_33 ) {
F_15 ( L_80 V_206 L_62
V_206 L_63 ,
exp -> V_52 -> V_49 , F_105 ( & V_174 -> V_213 ) ,
F_105 ( & V_196 -> V_204 . V_208 -> V_213 ) ,
V_196 -> V_203 , V_33 ) ;
V_197 = V_33 ;
}
}
F_154 ( V_192 ) ;
return V_197 ;
}
static int F_155 ( struct V_60 * exp ,
struct V_169 * V_174 ,
T_8 V_264 , void * V_265 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
if ( V_174 == NULL ) {
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_197 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_197 = F_156 ( V_4 -> V_17 [ V_10 ] -> V_47 , NULL ,
V_264 , V_265 ) ;
if ( ! V_33 )
V_33 = V_197 ;
}
return V_33 ;
}
F_100 ( V_174 ) ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
struct V_169 V_258 ;
struct V_235 * V_259 = V_174 -> V_182 [ V_10 ] ;
int V_266 = V_259 -> V_183 ;
int V_197 ;
if ( ! V_4 -> V_17 [ V_266 ] ) {
F_8 ( V_242 , L_81 , V_266 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_266 ] -> V_69 )
F_8 ( V_242 , L_78 , V_266 ) ;
V_258 . V_213 = V_259 -> V_184 ;
V_258 . V_181 = 0 ;
V_197 = F_156 ( V_4 -> V_17 [ V_266 ] -> V_47 ,
& V_258 , V_264 , V_265 ) ;
if ( V_197 && V_4 -> V_17 [ V_266 ] -> V_69 ) {
F_15 ( L_82 V_206
L_62 V_206 L_63 ,
exp -> V_52 -> V_49 , F_105 ( & V_174 -> V_213 ) ,
F_105 ( & V_259 -> V_184 ) , V_266 , V_197 ) ;
if ( ! V_33 )
V_33 = V_197 ;
}
}
return V_33 ;
}
int F_157 ( struct V_209 * V_210 , void * V_24 , int V_33 )
{
struct V_191 * V_211 = (struct V_191 * ) V_24 ;
int V_197 ;
if ( V_33 )
F_70 ( & V_211 -> V_212 , 0 ) ;
V_197 = F_158 ( V_211 ) ;
return V_33 ? V_33 : V_197 ;
}
static int F_159 ( struct V_60 * exp , struct V_193 * V_194 ,
T_2 V_267 , struct V_209 * V_210 )
{
struct V_1 * V_2 = F_31 ( exp ) ;
struct V_191 * V_192 ;
struct V_195 * V_196 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_194 != NULL ) ;
F_20 ( V_194 -> V_268 != NULL ) ;
V_4 = & V_2 -> V_5 . V_4 ;
V_33 = F_160 ( V_2 , V_194 , & V_192 ) ;
if ( V_33 )
return V_33 ;
F_102 (pos, &set->set_list) {
V_196 = F_85 ( V_148 , struct V_195 , V_200 ) ;
V_33 = F_161 ( V_4 -> V_17 [ V_196 -> V_203 ] -> V_47 ,
& V_196 -> V_204 , V_267 , V_210 ) ;
if ( V_33 )
break;
}
if ( V_33 || F_116 ( & V_210 -> V_215 ) ) {
int V_197 ;
if ( V_33 )
F_70 ( & V_192 -> V_212 , 0 ) ;
V_197 = F_158 ( V_192 ) ;
return V_33 ? V_33 : V_197 ;
}
F_20 ( V_210 -> V_216 == NULL ) ;
V_210 -> V_216 = F_157 ;
V_210 -> V_217 = ( void * ) V_192 ;
return 0 ;
}
static int F_162 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_269 * V_270 , T_2 V_267 , T_1 V_264 )
{
struct V_209 * V_192 = NULL ;
struct V_193 V_194 = { { { 0 } } } ;
int V_33 = 0 ;
V_192 = F_163 () ;
if ( V_192 == NULL )
return - V_103 ;
V_194 . V_268 = V_270 ;
V_194 . V_254 = V_264 ;
V_33 = F_159 ( exp , & V_194 , V_267 , V_192 ) ;
if ( V_33 == 0 )
V_33 = F_164 ( V_192 ) ;
F_165 ( V_192 ) ;
return V_33 ;
}
static int F_166 ( unsigned int V_156 , struct V_60 * exp , int V_271 ,
void * V_272 , void * V_273 )
{
struct V_1 * V_274 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_274 -> V_5 . V_4 ;
int V_10 = 0 , V_33 = 0 , V_109 = V_4 -> V_15 . V_16 ;
struct V_25 * V_95 ;
switch ( V_156 ) {
case V_275 : {
struct V_276 * V_24 = V_272 ;
struct V_1 * V_51 ;
struct V_269 V_277 = { 0 } ;
T_1 V_21 ;
T_1 V_264 ;
memcpy ( & V_21 , V_24 -> V_278 , sizeof( T_1 ) ) ;
if ( ( V_21 >= V_109 ) )
return - V_48 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_279 ;
if ( ! V_4 -> V_17 [ V_21 ] -> V_69 )
return - V_280 ;
V_51 = F_31 ( V_4 -> V_17 [ V_21 ] -> V_47 ) ;
if ( ! V_51 )
return - V_34 ;
if ( F_167 ( V_24 -> V_281 , F_168 ( V_51 ) ,
F_169 ( ( int ) V_24 -> V_282 ,
( int ) sizeof( struct V_25 ) ) ) )
return - V_283 ;
V_264 = V_273 ? * ( T_1 * ) V_273 : 0 ;
V_33 = V_269 ( NULL , V_4 -> V_17 [ V_21 ] -> V_47 , & V_277 ,
F_170 ( - V_284 ) ,
V_264 ) ;
if ( V_33 )
return V_33 ;
if ( F_167 ( V_24 -> V_285 , & V_277 ,
F_169 ( ( int ) V_24 -> V_286 ,
( int ) sizeof( V_277 ) ) ) )
return - V_283 ;
break;
}
case V_287 : {
struct V_276 * V_24 ;
struct V_115 * V_15 ;
char * V_288 = NULL ;
T_1 * V_155 ;
V_271 = 0 ;
if ( F_171 ( & V_288 , & V_271 , ( void * ) V_273 ) )
return - V_34 ;
V_24 = (struct V_276 * ) V_288 ;
if ( sizeof( * V_15 ) > V_24 -> V_289 ) {
F_172 ( V_288 , V_271 ) ;
return - V_34 ;
}
if ( sizeof( V_95 -> V_74 ) * V_109 > V_24 -> V_290 ) {
F_172 ( V_288 , V_271 ) ;
return - V_34 ;
}
if ( sizeof( T_1 ) * V_109 > V_24 -> V_291 ) {
F_172 ( V_288 , V_271 ) ;
return - V_34 ;
}
V_15 = (struct V_115 * ) V_24 -> V_292 ;
memcpy ( V_15 , & ( V_4 -> V_15 ) , sizeof( * V_15 ) ) ;
V_95 = (struct V_25 * ) V_24 -> V_278 ;
V_155 = ( T_1 * ) V_24 -> V_293 ;
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ , V_95 ++ , V_155 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
* V_95 = V_4 -> V_17 [ V_10 ] -> V_35 ;
* V_155 = V_4 -> V_17 [ V_10 ] -> V_76 ;
}
if ( F_167 ( ( void * ) V_273 , V_288 , V_271 ) )
V_33 = - V_283 ;
F_172 ( V_288 , V_271 ) ;
break;
}
case V_294 :
V_33 = F_173 ( exp , V_271 , V_272 , V_273 ) ;
break;
case V_295 :
V_33 = F_174 ( exp , V_272 , V_273 ) ;
break;
case V_296 :
V_33 = F_175 ( exp , V_272 , V_273 ) ;
break;
case V_297 : {
struct V_298 * V_299 = V_272 ;
struct V_11 * V_12 = NULL ;
struct V_300 * V_301 ;
if ( V_299 -> V_302 == V_303 ) {
if ( V_299 -> V_304 < 0 || V_109 <= V_299 -> V_304 )
return - V_34 ;
V_12 = V_4 -> V_17 [ V_299 -> V_304 ] ;
if ( ! V_12 || ! V_12 -> V_47 )
return - V_34 ;
} else if ( V_299 -> V_302 == V_305 ) {
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 ||
! F_38 ( & V_12 -> V_35 ,
& V_299 -> V_25 ) )
continue;
if ( V_12 -> V_47 == NULL )
return - V_34 ;
break;
}
} else {
return - V_34 ;
}
if ( V_10 >= V_109 )
return - V_279 ;
F_20 ( V_12 && V_12 -> V_47 ) ;
F_48 ( V_301 ) ;
if ( ! V_301 )
return - V_103 ;
F_176 ( V_301 , V_299 ) ;
V_33 = V_300 ( V_12 -> V_47 , V_301 ) ;
if ( V_33 == 0 ) {
F_176 ( V_299 , V_301 ) ;
V_299 -> V_302 = V_303 ;
V_299 -> V_25 = V_12 -> V_35 ;
}
F_50 ( V_301 ) ;
break;
}
default: {
int V_192 = 0 ;
if ( V_109 == 0 )
return - V_306 ;
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
int V_197 ;
struct V_1 * V_51 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_51 = F_31 ( V_4 -> V_17 [ V_10 ] -> V_47 ) ;
V_51 -> V_72 = V_274 -> V_72 ;
V_197 = F_177 ( V_156 , V_4 -> V_17 [ V_10 ] -> V_47 ,
V_271 , V_272 , V_273 ) ;
if ( V_197 == - V_280 && V_156 == V_307 ) {
return V_197 ;
} else if ( V_197 ) {
if ( V_4 -> V_17 [ V_10 ] -> V_69 ) {
F_8 ( V_197 == - V_306 ?
V_308 : V_309 ,
L_83
L_84 ,
F_54 ( V_4 , V_10 ) ,
V_10 , V_156 , V_197 ) ;
if ( ! V_33 )
V_33 = V_197 ;
}
} else {
V_192 = 1 ;
}
}
if ( ! V_192 && ! V_33 )
V_33 = - V_187 ;
}
}
return V_33 ;
}
T_9 F_178 ( struct V_310 * V_311 ,
struct V_169 * V_174 , T_9 V_312 ,
T_9 V_313 , int * V_314 )
{
T_9 V_315 = V_311 -> V_316 [ 0 ] . V_317 ;
T_3 V_318 , V_319 ;
T_9 V_320 ;
int V_321 = - 1 , V_10 ;
if ( V_311 -> V_322 == 0 ||
V_311 -> V_316 [ 0 ] . V_317 == 0 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
if ( V_174 -> V_182 [ V_10 ] -> V_183 ==
V_311 -> V_316 [ 0 ] . V_323 ) {
V_321 = V_10 ;
break;
}
}
if ( V_321 == - 1 )
return - V_34 ;
if ( ( F_137 ( V_174 , V_321 , V_312 , V_313 ,
& V_318 , & V_319 ) ) != 0 &&
V_315 < V_319 ) {
V_320 = V_315 ;
* V_314 = V_321 ;
} else {
V_320 = 0 ;
* V_314 = ( V_321 + 1 ) % V_174 -> V_181 ;
}
return V_320 ;
}
int F_179 ( struct V_169 * V_174 , T_9 V_312 ,
T_9 V_313 , int V_314 ,
int * V_324 )
{
int V_325 ;
T_3 V_326 , V_327 ;
int V_10 , V_328 ;
if ( V_313 - V_312 > V_174 -> V_214 * V_174 -> V_181 ) {
V_325 = ( V_314 < 1 ? V_174 -> V_181 - 1 :
V_314 - 1 ) ;
* V_324 = V_174 -> V_181 ;
} else {
for ( V_328 = 0 , V_10 = V_314 ; V_328 < V_174 -> V_181 ;
V_10 = ( V_10 + 1 ) % V_174 -> V_181 , V_328 ++ ) {
if ( ( F_137 ( V_174 , V_10 , V_312 , V_313 ,
& V_326 , & V_327 ) ) == 0 )
break;
}
* V_324 = V_328 ;
V_325 = ( V_314 + V_328 - 1 ) % V_174 -> V_181 ;
}
return V_325 ;
}
void F_180 ( struct V_310 * V_311 ,
struct V_329 * V_330 ,
int V_331 , unsigned int V_332 ,
int V_333 )
{
char * V_334 ;
int V_335 ;
for ( V_335 = 0 ; V_335 < V_332 ; V_335 ++ ) {
V_330 [ V_335 ] . V_323 = V_331 ;
V_330 [ V_335 ] . V_336 |= V_337 ;
}
V_334 = ( char * ) V_311 + F_181 ( V_333 ) ;
memcpy ( V_334 , V_330 , V_332 * sizeof( struct V_329 ) ) ;
}
static int F_182 ( struct V_3 * V_4 , T_1 V_338 , void * V_339 ,
T_1 * V_340 , void * V_110 , struct V_169 * V_174 )
{
struct V_341 * V_342 = V_339 ;
struct V_310 * V_311 = V_110 ;
struct V_310 * V_343 = NULL ;
struct V_329 * V_330 ;
int V_344 ;
unsigned int V_345 = 0 ;
int V_331 = 0 , V_346 , V_314 ;
T_9 V_312 , V_313 , V_347 , V_320 ;
T_9 V_348 ;
int V_333 = 0 , V_33 = 0 , V_10 ;
int V_349 = 0 ;
int V_350 = 0 ;
int V_325 ;
int V_351 = 0 , V_352 = 0 , V_324 ;
unsigned int V_353 = V_354 ;
if ( ! F_183 ( V_174 ) )
GOTO ( V_75 , V_33 = 0 ) ;
if ( F_181 ( V_342 -> V_311 . V_322 ) < V_353 )
V_353 = F_181 ( V_342 -> V_311 . V_322 ) ;
F_184 ( V_343 , V_353 ) ;
if ( V_343 == NULL )
GOTO ( V_75 , V_33 = - V_103 ) ;
V_330 = & V_343 -> V_316 [ 0 ] ;
V_344 = F_185 ( V_353 ) ;
memcpy ( V_311 , & V_342 -> V_311 , sizeof( * V_311 ) ) ;
V_312 = V_311 -> V_312 ;
V_347 = V_311 -> V_347 ;
V_346 = V_314 = F_136 ( V_174 , V_312 ) ;
V_313 = ( V_347 == ~ 0ULL ? V_342 -> V_188 . V_355 :
V_312 + V_347 - 1 ) ;
if ( V_313 > V_342 -> V_188 . V_355 )
V_313 = V_342 -> V_188 . V_355 ;
V_325 = F_179 ( V_174 , V_312 , V_313 ,
V_346 , & V_324 ) ;
V_320 = F_178 ( V_311 , V_174 , V_312 ,
V_313 , & V_314 ) ;
if ( V_320 == - V_34 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( F_181 ( V_311 -> V_322 ) > * V_340 )
V_311 -> V_322 = F_185 ( * V_340 ) ;
if ( V_311 -> V_322 == 0 ) {
V_345 = 1 ;
V_344 = 0 ;
}
for ( V_351 = V_314 , V_10 = 0 ; V_10 < V_324 ;
V_10 ++ , V_351 = ( V_351 + 1 ) % V_174 -> V_181 ) {
T_9 V_356 ;
T_9 V_357 ;
T_3 V_318 , V_319 , V_358 ;
unsigned int V_332 ;
V_352 = V_351 ;
if ( ( F_137 ( V_174 , V_351 , V_312 , V_313 ,
& V_318 , & V_358 ) ) == 0 )
continue;
if ( V_320 != 0 && V_351 == V_314 )
V_318 = V_320 ;
if ( V_347 != ~ 0ULL ) {
if ( V_312 + V_347 < V_312 )
V_347 = ~ 0ULL - V_312 ;
V_319 = F_186 ( V_174 , V_312 + V_347 ,
V_351 ) ;
} else {
V_319 = ~ 0ULL ;
}
if ( V_318 == V_319 )
continue;
V_356 = V_358 - V_318 ;
V_343 -> V_347 = 0 ;
V_357 = 0 ;
V_349 = 0 ;
V_350 = 0 ;
do {
if ( V_345 == 0 ) {
if ( V_333 + V_344 >
V_311 -> V_322 )
V_344 = V_311 -> V_322 -
V_333 ;
}
V_318 += V_357 ;
V_343 -> V_347 = V_356 - V_357 ;
V_356 = V_343 -> V_347 ;
V_343 -> V_322 = V_344 ;
V_343 -> V_359 = 0 ;
V_343 -> V_360 = V_311 -> V_360 ;
V_342 -> V_188 . V_185 = V_174 -> V_182 [ V_351 ] -> V_184 ;
V_331 = V_174 -> V_182 [ V_351 ] -> V_183 ;
if ( V_331 < 0 || V_331 >= V_4 -> V_15 . V_16 )
GOTO ( V_75 , V_33 = - V_34 ) ;
if ( ! V_4 -> V_17 [ V_331 ] -> V_69 ) {
V_343 -> V_360 |= V_361 ;
V_343 -> V_359 = 1 ;
V_330 [ 0 ] . V_317 = V_318 ;
V_330 [ 0 ] . V_362 = V_358 -
V_318 ;
V_330 [ 0 ] . V_336 |= V_363 ;
goto V_364;
}
V_343 -> V_312 = V_318 ;
V_343 -> V_360 &= ~ V_365 ;
memcpy ( & V_342 -> V_311 , V_343 , sizeof( * V_343 ) ) ;
* V_340 = F_181 ( V_343 -> V_322 ) ;
V_33 = F_187 ( NULL ,
V_4 -> V_17 [ V_331 ] -> V_47 ,
V_338 , V_339 , V_340 , V_343 , V_174 ) ;
if ( V_33 != 0 )
GOTO ( V_75 , V_33 ) ;
V_364:
V_332 = V_343 -> V_359 ;
if ( V_332 == 0 ) {
V_350 = 1 ;
if ( V_352 == V_325 ) {
V_311 -> V_359 = 0 ;
goto V_366;
}
break;
}
if ( V_345 ) {
V_333 += V_332 ;
break;
}
V_357 = V_330 [ V_332 - 1 ] . V_317 -
V_318 + V_330 [ V_332 - 1 ] . V_362 ;
if ( V_356 <= V_357 )
V_350 = 1 ;
if ( V_330 [ V_332 - 1 ] . V_336 & V_361 )
V_330 [ V_332 - 1 ] . V_336 &=
~ V_361 ;
V_348 = F_188 ( V_174 ,
V_330 [ V_332 - 1 ] . V_317 +
V_330 [ V_332 - 1 ] . V_362 ,
V_351 ) ;
if ( V_348 >= V_342 -> V_188 . V_355 )
V_349 = 1 ;
F_180 ( V_311 , V_330 ,
V_331 , V_332 ,
V_333 ) ;
V_333 += V_332 ;
if ( V_333 >= V_311 -> V_322 )
goto V_366;
} while ( V_350 == 0 && V_349 == 0 );
if ( V_352 == V_325 )
goto V_366;
}
V_366:
if ( V_174 -> V_181 > 1 )
V_311 -> V_360 |= V_365 ;
if ( V_345 )
goto V_367;
if ( V_352 == V_325 ) {
if ( V_350 || V_349 )
V_311 -> V_316 [ V_333 - 1 ] . V_336 |=
V_361 ;
}
V_367:
V_311 -> V_359 = V_333 ;
V_75:
F_189 ( V_343 , V_353 ) ;
return V_33 ;
}
static int F_190 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_1 V_338 , void * V_339 , T_1 * V_340 , void * V_110 ,
struct V_169 * V_174 )
{
struct V_1 * V_274 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_274 -> V_5 . V_4 ;
int V_10 , V_33 ;
if ( ! V_340 || ! V_110 )
return - V_283 ;
F_26 ( V_274 ) ;
if ( F_191 ( V_368 ) ) {
struct {
char V_369 [ 16 ] ;
struct V_370 * V_371 ;
} * V_24 = V_339 ;
struct V_372 * V_373 = & V_24 -> V_371 -> V_374 -> V_375 ;
struct V_235 * V_259 ;
T_1 * V_239 = V_110 ;
if ( * V_340 < sizeof( * V_239 ) )
GOTO ( V_75 , V_33 = - V_283 ) ;
* V_340 = sizeof( * V_239 ) ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
V_259 = V_174 -> V_182 [ V_10 ] ;
if ( ! V_4 -> V_17 [ V_259 -> V_183 ] )
continue;
if ( V_4 -> V_17 [ V_259 -> V_183 ] -> V_47 ==
V_24 -> V_371 -> V_376 &&
F_192 ( & V_259 -> V_184 , V_373 ) ) {
* V_239 = V_10 ;
GOTO ( V_75 , V_33 = 0 ) ;
}
}
F_193 ( V_24 -> V_371 , L_85 ) ;
F_194 ( V_377 , V_174 ) ;
GOTO ( V_75 , V_33 = - V_378 ) ;
} else if ( F_191 ( V_379 ) ) {
struct V_380 * V_381 = V_110 ;
T_1 V_382 = sizeof( V_383 ) ;
struct V_11 * V_12 ;
F_20 ( * V_340 == sizeof( struct V_380 ) ) ;
V_12 = V_4 -> V_17 [ V_381 -> V_266 ] ;
if ( ! V_12 || ! V_12 -> V_69 )
GOTO ( V_75 , V_33 = - V_384 ) ;
V_33 = F_187 ( V_59 , V_12 -> V_47 , V_338 , V_339 ,
& V_382 , V_381 -> V_24 , NULL ) ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_191 ( V_385 ) ) {
struct V_115 * V_386 = V_110 ;
* V_386 = V_4 -> V_15 ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_191 ( V_387 ) ) {
V_33 = F_182 ( V_4 , V_338 , V_339 , V_340 , V_110 , V_174 ) ;
GOTO ( V_75 , V_33 ) ;
} else if ( F_191 ( V_388 ) ) {
struct V_11 * V_12 ;
T_2 V_175 = * ( ( T_2 * ) V_110 ) ;
F_20 ( * V_340 == sizeof( T_2 ) ) ;
F_20 ( V_175 < V_4 -> V_15 . V_16 ) ;
V_12 = V_4 -> V_17 [ V_175 ] ;
if ( ! V_12 || ! V_12 -> V_47 )
GOTO ( V_75 , V_33 = - V_384 ) ;
* ( ( T_2 * ) V_110 ) = F_195 ( V_12 -> V_47 ) ;
GOTO ( V_75 , V_33 = 0 ) ;
} else if ( F_191 ( V_389 ) ) {
* ( ( int * ) V_110 ) = V_4 -> V_15 . V_16 ;
GOTO ( V_75 , V_33 = 0 ) ;
}
V_33 = - V_34 ;
V_75:
F_29 ( V_274 ) ;
return V_33 ;
}
static int F_196 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_4 V_338 , void * V_339 , T_4 V_340 ,
void * V_110 , struct V_209 * V_192 )
{
struct V_1 * V_274 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_274 -> V_5 . V_4 ;
T_4 V_109 ;
int V_10 , V_33 = 0 , V_197 ;
struct V_11 * V_12 ;
unsigned V_390 , V_391 ,
V_392 , V_393 ;
unsigned V_394 = 0 , V_395 = 0 , V_190 = 0 ;
V_390 = V_391 = V_392 = V_393 = 0 ;
if ( V_192 == NULL ) {
V_393 = 1 ;
V_192 = F_163 () ;
if ( ! V_192 )
return - V_103 ;
}
F_26 ( V_274 ) ;
V_109 = V_4 -> V_15 . V_16 ;
if ( F_191 ( V_396 ) ) {
V_109 = V_340 / sizeof( struct V_380 ) ;
V_340 = sizeof( V_383 ) ;
V_390 = sizeof( struct V_380 ) ;
V_392 = 1 ;
V_394 = 1 ;
} else if ( F_191 ( V_397 ) ) {
V_392 = 1 ;
} else if ( F_191 ( V_398 ) ) {
} else if ( F_191 ( V_399 ) ) {
V_395 = 1 ;
} else if ( F_191 ( V_400 ) ) {
V_190 = 1 ;
} else if ( F_191 ( V_107 ) ) {
F_20 ( V_4 -> V_106 == NULL ) ;
V_4 -> V_106 = V_110 ;
V_392 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ , V_110 = ( char * ) V_110 + V_390 ) {
if ( V_394 ) {
V_12 = V_4 -> V_17 [ ( ( struct V_380 * )val )->idx] ;
}
int F_197 ( struct V_60 * exp , struct V_169 * V_174 ,
int V_156 , T_2 * V_401 )
{
T_1 V_402 = V_174 -> V_214 ;
T_2 V_231 ;
V_231 = * V_401 ;
F_198 ( V_231 , V_402 ) ;
V_231 = V_231 * V_402 ;
F_8 ( V_403 , L_86 ,
* V_401 , V_402 , V_231 , V_231 + V_402 - 1 ) ;
if ( V_156 == V_404 ) {
* V_401 = V_231 + V_402 - 1 ;
} else if ( V_156 == V_405 ) {
* V_401 = V_231 ;
} else {
F_98 () ;
}
return 0 ;
}
void F_199 ( struct V_169 * V_406 )
{
F_20 ( V_406 -> V_407 != F_200 () ) ;
F_201 ( & V_406 -> V_408 ) ;
F_20 ( V_406 -> V_407 == 0 ) ;
V_406 -> V_407 = F_200 () ;
}
void F_202 ( struct V_169 * V_406 )
{
F_20 ( V_406 -> V_407 == F_200 () ) ;
V_406 -> V_407 = 0 ;
F_203 ( & V_406 -> V_408 ) ;
}
static int F_204 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_300 * V_301 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
T_2 V_409 = 0 ;
T_2 V_410 = 0 ;
int V_10 , V_33 = 0 ;
if ( V_301 -> V_411 != V_412 &&
V_301 -> V_411 != V_413 &&
V_301 -> V_411 != V_414 &&
V_301 -> V_411 != V_415 &&
V_301 -> V_411 != V_416 &&
V_301 -> V_411 != V_417 ) {
F_15 ( L_87 , V_301 -> V_411 ) ;
return - V_283 ;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_197 ;
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 )
continue;
if ( ! V_12 -> V_69 || V_12 -> V_18 ) {
if ( V_301 -> V_411 == V_414 &&
V_4 -> V_17 [ V_10 ] -> V_67 ) {
V_33 = - V_418 ;
F_15 ( L_88 , V_10 ) ;
} else {
F_8 ( V_242 , L_88 , V_10 ) ;
}
continue;
}
V_197 = V_300 ( V_12 -> V_47 , V_301 ) ;
if ( V_197 ) {
if ( V_12 -> V_69 && ! V_33 )
V_33 = V_197 ;
continue;
}
if ( V_301 -> V_411 == V_414 ) {
V_409 += V_301 -> V_419 . V_420 ;
V_410 += V_301 -> V_419 . V_421 ;
}
}
F_29 ( V_2 ) ;
if ( V_301 -> V_411 == V_414 ) {
V_301 -> V_419 . V_420 = V_409 ;
V_301 -> V_419 . V_421 = V_410 ;
}
return V_33 ;
}
static int F_205 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_300 * V_301 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_33 = 0 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( ! V_4 -> V_17 [ V_10 ] -> V_67 ) {
F_79 ( L_89
L_90 , V_10 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_69 ) {
F_15 ( L_78 , V_10 ) ;
V_33 = - V_187 ;
goto V_75;
}
}
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_197 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_67 )
continue;
V_197 = F_206 ( V_4 -> V_17 [ V_10 ] -> V_47 , V_301 ) ;
if ( V_197 && ! V_33 )
V_33 = V_197 ;
}
V_75:
F_29 ( V_2 ) ;
return V_33 ;
}
int T_10 F_207 ( void )
{
struct V_122 V_123 = { NULL } ;
int V_33 ;
F_8 ( V_80 , L_91 , & V_422 ) ;
V_33 = F_208 ( V_422 ) ;
if ( V_33 )
return V_33 ;
V_423 = F_209 ( L_92 ,
sizeof( struct V_235 ) ,
0 , V_424 , NULL ) ;
if ( V_423 == NULL ) {
F_210 ( V_422 ) ;
return - V_103 ;
}
F_75 ( & V_123 ) ;
V_33 = F_211 ( & V_425 , NULL , V_123 . V_426 ,
V_427 , & V_428 ) ;
if ( V_33 ) {
F_212 ( V_423 ) ;
F_210 ( V_422 ) ;
}
return V_33 ;
}
static void F_213 ( void )
{
F_214 ( V_427 ) ;
F_212 ( V_423 ) ;
F_210 ( V_422 ) ;
}
