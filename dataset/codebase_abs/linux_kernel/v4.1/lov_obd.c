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
F_8 ( V_14 , L_5 ,
F_16 ( V_26 ) ) ;
return 0 ;
}
V_33 = F_19 ( NULL , & V_4 -> V_17 [ V_21 ] -> V_47 , V_27 ,
& V_28 , V_24 , NULL ) ;
if ( V_33 || ! V_4 -> V_17 [ V_21 ] -> V_47 ) {
F_15 ( L_6 ,
F_16 ( V_26 ) , V_33 ) ;
return - V_48 ;
}
V_4 -> V_17 [ V_21 ] -> V_18 = 0 ;
F_8 ( V_14 , L_7 , V_21 ,
F_16 ( V_26 ) , V_27 -> V_49 , V_22 ? L_8 : L_9 ) ;
V_32 = V_2 -> V_50 ;
if ( V_32 ) {
struct V_1 * V_51 = V_4 -> V_17 [ V_21 ] -> V_47 -> V_52 ;
struct V_31 * V_53 ;
F_20 ( V_51 != NULL ) ;
F_20 ( V_51 -> V_54 == V_55 ) ;
F_20 ( V_51 -> V_56 -> V_57 != NULL ) ;
V_53 = F_21 ( V_51 -> V_49 ,
V_32 ,
L_10 ,
V_51 -> V_56 -> V_57 ,
V_51 -> V_49 ) ;
if ( V_53 == NULL ) {
F_15 ( L_11 ,
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
F_8 ( V_14 , L_12 , V_4 -> V_65 ) ;
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
F_15 ( L_13 ,
V_2 -> V_49 , V_10 , V_33 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_33 = F_28 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_47 -> V_52 ,
V_68 , ( void * ) & V_10 ) ;
if ( V_33 ) {
F_15 ( L_14 ,
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
F_8 ( V_14 , L_15 ,
V_2 -> V_49 , V_51 ? V_51 -> V_49 : L_16 ) ;
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
F_15 ( L_17 ,
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
F_15 ( L_18 , V_4 -> V_65 ) ;
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
F_8 ( V_80 , L_19 ,
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
F_8 ( V_80 , L_20 ,
V_21 , F_16 ( & V_12 -> V_35 ) ,
V_12 -> V_47 -> V_82 . V_83 ) ;
if ( F_38 ( V_74 , & V_12 -> V_35 ) )
break;
}
if ( V_21 == V_4 -> V_15 . V_16 ) {
V_21 = - V_34 ;
goto V_75;
}
if ( V_78 == V_84 || V_78 == V_81 ) {
V_22 = ( V_78 == V_81 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_67 == V_22 ) {
F_8 ( V_80 , L_21 ,
V_74 -> V_74 , V_22 ? L_8 : L_22 ) ;
} else {
V_4 -> V_17 [ V_21 ] -> V_67 = V_22 ;
F_8 ( V_14 , L_23 ,
V_22 ? L_8 : L_22 , F_16 ( V_74 ) ) ;
}
} else if ( V_78 == V_85 || V_78 == V_86 ) {
V_79 = ( V_78 == V_86 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_69 == V_79 ) {
F_8 ( V_80 , L_24 ,
V_74 -> V_74 , V_79 ? L_8 : L_9 ) ;
goto V_75;
} else {
F_8 ( V_14 , L_25 ,
F_16 ( V_74 ) , V_79 ? L_8 : L_9 ) ;
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
F_15 ( L_26 , V_78 , V_74 -> V_74 ) ;
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
F_15 ( L_27 ,
V_87 -> V_56 -> V_57 ,
V_87 -> V_49 ) ;
return - V_34 ;
}
V_74 = & V_87 -> V_5 . V_38 . V_90 ;
V_33 = F_37 ( V_2 , V_74 , V_78 ) ;
if ( V_33 < 0 ) {
F_40 ( & V_4 -> V_88 ) ;
F_15 ( L_28 , V_78 ,
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
F_15 ( L_29 ,
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
F_8 ( V_14 , L_30 ,
V_95 -> V_74 , V_21 , V_96 , V_79 ) ;
if ( V_96 <= 0 ) {
F_15 ( L_31 ,
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
F_15 ( L_32 ,
F_16 ( & V_12 -> V_35 ) , V_21 ) ;
F_4 ( & V_4 -> V_6 ) ;
return - V_98 ;
}
if ( V_21 >= V_4 -> V_97 ) {
struct V_11 * * V_99 , * * V_100 = NULL ;
T_1 V_101 , V_102 = 0 ;
V_101 = F_44 ( T_1 , V_4 -> V_97 , 2 ) ;
while ( V_101 < V_21 + 1 )
V_101 <<= 1 ;
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
F_8 ( V_14 , L_33 ,
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
F_8 ( V_14 , L_34 ,
V_21 , V_12 -> V_76 , V_4 -> V_15 . V_16 ) ;
V_33 = F_51 ( V_2 , V_27 , V_105 , & V_21 ) ;
if ( V_4 -> V_65 == 0 ) {
return 0 ;
}
F_26 ( V_2 ) ;
V_33 = F_14 ( V_2 , V_21 , V_79 , & V_4 -> V_66 ) ;
if ( V_33 )
goto V_75;
if ( ! V_12 -> V_47 ) {
V_33 = 0 ;
goto V_75;
}
if ( V_4 -> V_106 != NULL ) {
V_33 = F_52 ( NULL , V_12 -> V_47 ,
sizeof( V_107 ) , V_107 ,
sizeof( struct V_108 ) , V_4 -> V_106 ,
NULL ) ;
if ( V_33 < 0 )
goto V_75;
}
V_33 = F_28 ( V_2 , V_12 -> V_47 -> V_52 ,
V_79 ? V_68 : V_85 ,
( void * ) & V_21 ) ;
V_75:
if ( V_33 ) {
F_15 ( L_35 , V_33 ,
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
F_15 ( L_36 ,
V_21 , V_109 ) ;
return - V_34 ;
}
F_53 ( & V_4 -> V_88 ) ;
F_26 ( V_2 ) ;
if ( ! V_4 -> V_17 [ V_21 ] ) {
F_15 ( L_37 , V_21 ) ;
V_33 = - V_34 ;
goto V_75;
}
if ( V_95 && ! F_38 ( V_95 , & V_4 -> V_17 [ V_21 ] -> V_35 ) ) {
F_15 ( L_38 ,
F_54 ( V_4 , V_21 ) , V_21 ,
F_16 ( V_95 ) ) ;
V_33 = - V_34 ;
goto V_75;
}
F_8 ( V_14 , L_39 ,
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
F_8 ( V_14 , L_40 ,
V_12 -> V_35 . V_74 ,
V_51 ? V_51 -> V_49 : L_41 ) ;
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
F_58 ( L_42 ,
V_112 ) ;
* V_110 = V_112 ;
} else if ( * V_110 & ( V_111 - 1 ) ) {
* V_110 &= ~ ( V_111 - 1 ) ;
F_59 ( L_43 ,
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
F_59 ( L_44 , * V_110 ) ;
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
F_15 ( L_45 ) ;
return - V_34 ;
}
V_15 = (struct V_115 * ) F_66 ( V_121 , 1 ) ;
if ( sizeof( * V_15 ) > F_65 ( V_121 , 1 ) ) {
F_15 ( L_46 ,
( int ) sizeof( * V_15 ) , F_65 ( V_121 , 1 ) ) ;
return - V_34 ;
}
if ( V_15 -> V_124 != V_125 ) {
if ( V_15 -> V_124 == F_67 ( V_125 ) ) {
F_8 ( V_126 , L_47 ,
V_2 -> V_49 , V_15 ) ;
F_68 ( V_15 ) ;
} else {
F_15 ( L_48 ,
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
V_4 -> V_128 = F_72 ( L_49 , V_129 ,
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
goto V_75;
F_75 ( & V_123 ) ;
F_76 ( V_2 , V_123 . V_138 ) ;
#if F_77 ( V_139 )
{
int V_140 ;
V_140 = F_78 ( V_2 -> V_141 , L_50 ,
0444 , & V_142 , V_2 ) ;
if ( V_140 )
F_79 ( L_51 ) ;
}
#endif
V_4 -> V_143 = F_80 ( L_52 ,
V_2 -> V_141 ,
NULL , NULL ) ;
return 0 ;
V_75:
return V_33 ;
}
static int F_81 ( struct V_1 * V_2 , enum V_144 V_145 )
{
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
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_147 * V_148 , * V_149 ;
struct V_150 * V_151 ;
F_84 (pos, tmp, &lov->lov_pool_list) {
V_151 = F_85 ( V_148 , struct V_150 , V_152 ) ;
F_8 ( V_80 , L_53 , V_151 ) ;
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
F_15 ( L_54 ,
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
if ( F_65 ( V_121 , 1 ) > sizeof( V_25 . V_74 ) ) {
V_33 = - V_34 ;
goto V_75;
}
F_92 ( & V_25 , F_66 ( V_121 , 1 ) ) ;
if ( sscanf ( F_66 ( V_121 , 2 ) , L_55 , V_154 ) != 1 ) {
V_33 = - V_34 ;
goto V_75;
}
if ( sscanf ( F_66 ( V_121 , 3 ) , L_55 , V_155 ) != 1 ) {
V_33 = - V_34 ;
goto V_75;
}
V_21 = * V_154 ;
V_96 = * V_155 ;
if ( V_156 == V_158 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_96 , 1 ) ;
else if ( V_156 == V_159 )
V_33 = F_42 ( V_2 , & V_25 , V_21 , V_96 , 0 ) ;
else
V_33 = F_35 ( V_2 , V_21 , & V_25 , V_96 ) ;
goto V_75;
}
case V_161 : {
struct V_122 V_123 = { NULL } ;
struct V_115 * V_15 = & ( V_2 -> V_5 . V_4 . V_15 ) ;
if ( ! V_15 ) {
V_33 = - V_34 ;
goto V_75;
}
F_75 ( & V_123 ) ;
V_33 = F_93 ( V_162 , V_123 . V_138 ,
V_121 , V_2 ) ;
if ( V_33 > 0 )
V_33 = 0 ;
goto V_75;
}
case V_163 :
case V_164 :
case V_165 :
case V_166 :
goto V_75;
default: {
F_15 ( L_56 , V_121 -> V_157 ) ;
V_33 = - V_34 ;
goto V_75;
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
if ( V_174 == NULL ) {
V_33 = - V_34 ;
goto V_75;
}
if ( V_175 >= V_4 -> V_15 . V_16 ||
! V_4 -> V_17 [ V_175 ] ) {
V_33 = - V_34 ;
goto V_75;
}
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
struct V_182 * V_183 = V_174 -> V_184 [ V_10 ] ;
if ( F_95 ( V_183 ) )
continue;
if ( V_183 -> V_185 == V_175 ) {
if ( F_96 ( & V_183 -> V_186 ) != F_96 ( & V_168 -> V_187 ) ) {
V_33 = - V_34 ;
goto V_75;
}
break;
}
}
if ( V_10 == V_174 -> V_181 ) {
V_33 = - V_34 ;
goto V_75;
}
V_33 = F_97 ( NULL , V_4 -> V_17 [ V_175 ] -> V_47 ,
V_168 , & V_173 , V_172 ) ;
V_75:
F_47 ( V_173 , sizeof( * V_173 ) ) ;
return V_33 ;
}
static int F_98 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_167 * V_168 , struct V_169 * * V_170 ,
struct V_171 * V_172 )
{
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_170 != NULL ) ;
if ( exp == NULL )
return - V_34 ;
if ( ( V_168 -> V_176 & V_177 ) &&
V_168 -> V_178 == V_188 ) {
F_99 () ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
if ( ! V_4 -> V_15 . V_70 )
return - V_189 ;
F_26 ( exp -> V_52 ) ;
if ( ( V_168 -> V_176 & V_177 ) &&
( V_168 -> V_178 & V_179 ) ) {
V_33 = F_94 ( exp , V_168 , V_170 , V_172 ) ;
}
F_29 ( exp -> V_52 ) ;
return V_33 ;
}
static int F_100 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_167 * V_190 , struct V_169 * V_174 ,
struct V_171 * V_172 , struct V_60 * V_191 ,
void * V_192 )
{
struct V_193 * V_194 ;
struct V_195 V_196 ;
struct V_197 * V_198 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
int V_33 = 0 , V_199 = 0 ;
F_101 ( V_174 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
if ( V_190 -> V_176 & V_200 ) {
F_20 ( V_172 ) ;
F_20 ( V_172 -> V_201 ) ;
}
V_4 = & exp -> V_52 -> V_5 . V_4 ;
F_26 ( exp -> V_52 ) ;
V_33 = F_102 ( exp , & V_196 , V_190 , V_174 , V_172 , & V_194 ) ;
if ( V_33 )
goto V_75;
F_103 (pos, &set->set_list) {
V_198 = F_85 ( V_148 , struct V_197 , V_202 ) ;
if ( V_190 -> V_176 & V_200 )
V_172 -> V_201 = V_194 -> V_203 + V_198 -> V_204 ;
V_199 = F_104 ( V_59 , V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
V_198 -> V_206 . V_207 , NULL , V_172 , NULL , V_192 ) ;
V_199 = F_105 ( V_194 , V_198 , V_199 ) ;
if ( V_199 ) {
F_15 ( L_57 V_208 L_58
V_208 L_59 ,
exp -> V_52 -> V_49 , F_106 ( & V_190 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) ,
V_198 -> V_205 , V_199 ) ;
if ( ! V_33 )
V_33 = V_199 ;
}
}
if ( V_33 == 0 ) {
F_20 ( F_107 ( V_174 -> V_209 ) != NULL ) ;
V_33 = F_107 ( V_174 -> V_209 ) -> F_108 ( V_174 , V_190 , V_191 ) ;
}
V_199 = F_109 ( V_194 ) ;
V_75:
F_29 ( exp -> V_52 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_110 ( struct V_210 * V_211 ,
void * V_24 , int V_33 )
{
struct V_193 * V_212 = (struct V_193 * ) V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_199 = F_111 ( V_212 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_112 ( struct V_60 * exp , struct V_195 * V_196 ,
struct V_210 * V_211 )
{
struct V_193 * V_212 ;
struct V_3 * V_4 ;
struct V_147 * V_148 ;
struct V_197 * V_198 ;
int V_33 = 0 , V_199 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_214 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_113 ( exp , V_196 , & V_212 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_60 V_208 L_61 ,
F_106 ( & V_196 -> V_214 -> V_215 ) , V_196 -> V_214 -> V_181 ,
V_196 -> V_214 -> V_216 ) ;
F_103 (pos, &lovset->set_list) {
V_198 = F_85 ( V_148 , struct V_197 , V_202 ) ;
F_8 ( V_80 , L_60 V_208 L_62 V_208 L_63 ,
F_106 ( & V_196 -> V_207 -> V_187 ) , V_198 -> V_204 ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 ) ;
V_33 = F_114 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_211 ) ;
if ( V_33 ) {
F_15 ( L_64 V_208 L_65
V_208 L_59 ,
exp -> V_52 -> V_49 ,
F_106 ( & V_196 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) ,
V_198 -> V_205 , V_33 ) ;
goto V_75;
}
}
if ( ! F_115 ( & V_211 -> V_217 ) ) {
F_20 ( V_33 == 0 ) ;
F_20 ( V_211 -> V_218 == NULL ) ;
V_211 -> V_218 = F_110 ;
V_211 -> V_219 = ( void * ) V_212 ;
return V_33 ;
}
V_75:
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_199 = F_111 ( V_212 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_116 ( struct V_210 * V_211 ,
void * V_24 , int V_33 )
{
struct V_193 * V_212 = (struct V_193 * ) V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_199 = F_117 ( V_212 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_118 ( struct V_60 * exp , struct V_195 * V_196 ,
struct V_171 * V_172 ,
struct V_210 * V_211 )
{
struct V_193 * V_194 ;
struct V_197 * V_198 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_196 ) ;
F_101 ( V_196 -> V_214 ) ;
if ( V_196 -> V_207 -> V_176 & V_200 ) {
F_20 ( V_172 ) ;
F_20 ( V_172 -> V_201 ) ;
}
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
V_33 = F_119 ( exp , V_196 , V_172 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_8 ( V_80 , L_60 V_208 L_61 ,
F_106 ( & V_196 -> V_214 -> V_215 ) ,
V_196 -> V_214 -> V_181 ,
V_196 -> V_214 -> V_216 ) ;
F_103 (pos, &set->set_list) {
V_198 = F_85 ( V_148 , struct V_197 , V_202 ) ;
if ( V_196 -> V_207 -> V_176 & V_200 )
V_172 -> V_201 = V_194 -> V_203 + V_198 -> V_204 ;
F_8 ( V_80 , L_60 V_208 L_62 V_208 L_63 ,
F_106 ( & V_196 -> V_207 -> V_187 ) , V_198 -> V_204 ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) , V_198 -> V_205 ) ;
V_33 = F_120 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_172 , V_211 ) ;
if ( V_33 ) {
F_15 ( L_66 V_208 L_65
V_208 L_59 ,
F_106 ( & V_194 -> V_220 -> V_207 -> V_187 ) ,
F_106 ( & V_198 -> V_206 . V_207 -> V_187 ) ,
V_198 -> V_205 , V_33 ) ;
break;
}
}
if ( V_33 || ! V_211 || F_115 ( & V_211 -> V_217 ) ) {
int V_199 ;
if ( V_33 )
F_70 ( & V_194 -> V_213 , 0 ) ;
V_199 = F_117 ( V_194 ) ;
return V_33 ? V_33 : V_199 ;
}
F_20 ( V_211 -> V_218 == NULL ) ;
V_211 -> V_218 = F_116 ;
V_211 -> V_219 = ( void * ) V_194 ;
return 0 ;
}
static int F_121 ( struct V_60 * exp ,
struct V_169 * V_174 , T_3 V_221 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_33 = 0 , V_10 ;
F_101 ( V_174 ) ;
if ( ! exp || ! exp -> V_52 )
return - V_48 ;
V_4 = & exp -> V_52 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
struct V_169 V_222 ;
struct V_182 * V_183 = V_174 -> V_184 [ V_10 ] ;
if ( F_95 ( V_183 ) )
continue;
if ( ! V_4 -> V_17 [ V_183 -> V_185 ] ) {
F_8 ( V_223 , L_67 , V_183 -> V_185 ) ;
continue;
}
V_222 . V_215 = V_183 -> V_186 ;
V_222 . V_181 = 0 ;
V_33 = F_122 ( V_4 -> V_17 [ V_183 -> V_185 ] -> V_47 ,
& V_222 , V_221 , V_24 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return V_33 ;
}
int F_123 ( struct V_210 * V_211 , void * V_24 , int V_33 )
{
struct V_193 * V_212 = (struct V_193 * ) V_24 ;
int V_199 ;
if ( V_33 )
F_70 ( & V_212 -> V_213 , 0 ) ;
V_199 = F_124 ( V_212 ) ;
return V_33 ? V_33 : V_199 ;
}
static int F_125 ( struct V_60 * exp , struct V_195 * V_196 ,
T_2 V_224 , struct V_210 * V_211 )
{
struct V_1 * V_2 = F_31 ( exp ) ;
struct V_193 * V_194 ;
struct V_197 * V_198 ;
struct V_147 * V_148 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
F_20 ( V_196 != NULL ) ;
F_20 ( V_196 -> V_225 != NULL ) ;
V_4 = & V_2 -> V_5 . V_4 ;
V_33 = F_126 ( V_2 , V_196 , & V_194 ) ;
if ( V_33 )
return V_33 ;
F_103 (pos, &set->set_list) {
V_198 = F_85 ( V_148 , struct V_197 , V_202 ) ;
V_33 = F_127 ( V_4 -> V_17 [ V_198 -> V_205 ] -> V_47 ,
& V_198 -> V_206 , V_224 , V_211 ) ;
if ( V_33 )
break;
}
if ( V_33 || F_115 ( & V_211 -> V_217 ) ) {
int V_199 ;
if ( V_33 )
F_70 ( & V_194 -> V_213 , 0 ) ;
V_199 = F_124 ( V_194 ) ;
return V_33 ? V_33 : V_199 ;
}
F_20 ( V_211 -> V_218 == NULL ) ;
V_211 -> V_218 = F_123 ;
V_211 -> V_219 = ( void * ) V_194 ;
return 0 ;
}
static int F_128 ( const struct V_58 * V_59 , struct V_60 * exp ,
struct V_226 * V_227 , T_2 V_224 , T_1 V_228 )
{
struct V_210 * V_194 = NULL ;
struct V_195 V_196 = { { { 0 } } } ;
int V_33 = 0 ;
V_194 = F_129 () ;
if ( V_194 == NULL )
return - V_103 ;
V_196 . V_225 = V_227 ;
V_196 . V_229 = V_228 ;
V_33 = F_125 ( exp , & V_196 , V_224 , V_194 ) ;
if ( V_33 == 0 )
V_33 = F_130 ( V_194 ) ;
F_131 ( V_194 ) ;
return V_33 ;
}
static int F_132 ( unsigned int V_156 , struct V_60 * exp , int V_230 ,
void * V_231 , void * V_232 )
{
struct V_1 * V_233 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_233 -> V_5 . V_4 ;
int V_10 = 0 , V_33 = 0 , V_109 = V_4 -> V_15 . V_16 ;
struct V_25 * V_95 ;
switch ( V_156 ) {
case V_234 : {
struct V_235 * V_24 = V_231 ;
struct V_1 * V_51 ;
struct V_226 V_236 = { 0 } ;
T_1 V_21 ;
T_1 V_228 ;
memcpy ( & V_21 , V_24 -> V_237 , sizeof( T_1 ) ) ;
if ( ( V_21 >= V_109 ) )
return - V_48 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_238 ;
if ( ! V_4 -> V_17 [ V_21 ] -> V_69 )
return - V_239 ;
V_51 = F_31 ( V_4 -> V_17 [ V_21 ] -> V_47 ) ;
if ( ! V_51 )
return - V_34 ;
if ( F_133 ( V_24 -> V_240 , F_134 ( V_51 ) ,
F_135 ( ( int ) V_24 -> V_241 ,
( int ) sizeof( struct V_25 ) ) ) )
return - V_242 ;
V_228 = V_232 ? * ( T_1 * ) V_232 : 0 ;
V_33 = V_226 ( NULL , V_4 -> V_17 [ V_21 ] -> V_47 , & V_236 ,
F_136 ( - V_243 ) ,
V_228 ) ;
if ( V_33 )
return V_33 ;
if ( F_133 ( V_24 -> V_244 , & V_236 ,
F_135 ( ( int ) V_24 -> V_245 ,
( int ) sizeof( V_236 ) ) ) )
return - V_242 ;
break;
}
case V_246 : {
struct V_235 * V_24 ;
struct V_115 * V_15 ;
char * V_247 = NULL ;
T_1 * V_155 ;
V_230 = 0 ;
if ( F_137 ( & V_247 , & V_230 , ( void * ) V_232 ) )
return - V_34 ;
V_24 = (struct V_235 * ) V_247 ;
if ( sizeof( * V_15 ) > V_24 -> V_248 ) {
F_138 ( V_247 , V_230 ) ;
return - V_34 ;
}
if ( sizeof( V_95 -> V_74 ) * V_109 > V_24 -> V_249 ) {
F_138 ( V_247 , V_230 ) ;
return - V_34 ;
}
if ( sizeof( T_1 ) * V_109 > V_24 -> V_250 ) {
F_138 ( V_247 , V_230 ) ;
return - V_34 ;
}
V_15 = (struct V_115 * ) V_24 -> V_251 ;
memcpy ( V_15 , & ( V_4 -> V_15 ) , sizeof( * V_15 ) ) ;
V_95 = (struct V_25 * ) V_24 -> V_237 ;
V_155 = ( T_1 * ) V_24 -> V_252 ;
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ , V_95 ++ , V_155 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
* V_95 = V_4 -> V_17 [ V_10 ] -> V_35 ;
* V_155 = V_4 -> V_17 [ V_10 ] -> V_76 ;
}
if ( F_133 ( ( void * ) V_232 , V_247 , V_230 ) )
V_33 = - V_242 ;
F_138 ( V_247 , V_230 ) ;
break;
}
case V_253 :
V_33 = F_139 ( exp , V_231 , V_232 ) ;
break;
case V_254 : {
struct V_255 * V_256 = V_231 ;
struct V_11 * V_12 = NULL ;
struct V_257 * V_258 ;
if ( V_256 -> V_259 == V_260 ) {
if ( V_256 -> V_261 < 0 || V_109 <= V_256 -> V_261 )
return - V_34 ;
V_12 = V_4 -> V_17 [ V_256 -> V_261 ] ;
if ( ! V_12 || ! V_12 -> V_47 )
return - V_34 ;
} else if ( V_256 -> V_259 == V_262 ) {
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 ||
! F_38 ( & V_12 -> V_35 ,
& V_256 -> V_25 ) )
continue;
if ( V_12 -> V_47 == NULL )
return - V_34 ;
break;
}
} else {
return - V_34 ;
}
if ( V_10 >= V_109 )
return - V_238 ;
F_20 ( V_12 && V_12 -> V_47 ) ;
F_48 ( V_258 ) ;
if ( ! V_258 )
return - V_103 ;
F_140 ( V_258 , V_256 ) ;
V_33 = V_257 ( V_12 -> V_47 , V_258 ) ;
if ( V_33 == 0 ) {
F_140 ( V_256 , V_258 ) ;
V_256 -> V_259 = V_260 ;
V_256 -> V_25 = V_12 -> V_35 ;
}
F_50 ( V_258 ) ;
break;
}
default: {
int V_194 = 0 ;
if ( V_109 == 0 )
return - V_263 ;
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ ) {
int V_199 ;
struct V_1 * V_51 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_47 )
continue;
V_51 = F_31 ( V_4 -> V_17 [ V_10 ] -> V_47 ) ;
V_51 -> V_72 = V_233 -> V_72 ;
V_199 = F_141 ( V_156 , V_4 -> V_17 [ V_10 ] -> V_47 ,
V_230 , V_231 , V_232 ) ;
if ( V_199 == - V_239 && V_156 == V_264 ) {
return V_199 ;
} else if ( V_199 ) {
if ( V_4 -> V_17 [ V_10 ] -> V_69 ) {
F_8 ( V_199 == - V_263 ?
V_265 : V_266 ,
L_68 ,
F_54 ( V_4 , V_10 ) ,
V_10 , V_156 , V_199 ) ;
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
static T_4 F_142 ( struct V_267 * V_268 ,
struct V_169 * V_174 , T_4 V_269 ,
T_4 V_270 , int * V_271 )
{
T_4 V_272 = V_268 -> V_273 [ 0 ] . V_274 ;
T_4 V_275 , V_276 ;
T_4 V_277 ;
int V_278 = - 1 , V_10 ;
if ( V_268 -> V_279 == 0 ||
V_268 -> V_273 [ 0 ] . V_274 == 0 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
struct V_182 * V_196 = V_174 -> V_184 [ V_10 ] ;
if ( F_95 ( V_196 ) )
continue;
if ( V_196 -> V_185 == V_268 -> V_273 [ 0 ] . V_280 ) {
V_278 = V_10 ;
break;
}
}
if ( V_278 == - 1 )
return - V_34 ;
if ( ( F_143 ( V_174 , V_278 , V_269 , V_270 ,
& V_275 , & V_276 ) ) != 0 &&
V_272 < V_276 ) {
V_277 = V_272 ;
* V_271 = V_278 ;
} else {
V_277 = 0 ;
* V_271 = ( V_278 + 1 ) % V_174 -> V_181 ;
}
return V_277 ;
}
static int F_144 ( struct V_169 * V_174 , T_4 V_269 ,
T_4 V_270 , int V_271 ,
int * V_281 )
{
int V_282 ;
T_4 V_283 , V_284 ;
int V_10 , V_285 ;
if ( V_270 - V_269 > V_174 -> V_216 * V_174 -> V_181 ) {
V_282 = V_271 < 1 ? V_174 -> V_181 - 1 :
V_271 - 1 ;
* V_281 = V_174 -> V_181 ;
} else {
for ( V_285 = 0 , V_10 = V_271 ; V_285 < V_174 -> V_181 ;
V_10 = ( V_10 + 1 ) % V_174 -> V_181 , V_285 ++ ) {
if ( ( F_143 ( V_174 , V_10 , V_269 , V_270 ,
& V_283 , & V_284 ) ) == 0 )
break;
}
* V_281 = V_285 ;
V_282 = ( V_271 + V_285 - 1 ) % V_174 -> V_181 ;
}
return V_282 ;
}
static void F_145 ( struct V_267 * V_268 ,
struct V_286 * V_287 ,
int V_288 , unsigned int V_289 ,
int V_290 )
{
char * V_291 ;
int V_292 ;
for ( V_292 = 0 ; V_292 < V_289 ; V_292 ++ ) {
V_287 [ V_292 ] . V_280 = V_288 ;
V_287 [ V_292 ] . V_293 |= V_294 ;
}
V_291 = ( char * ) V_268 + F_146 ( V_290 ) ;
memcpy ( V_291 , V_287 , V_289 * sizeof( struct V_286 ) ) ;
}
static int F_147 ( struct V_3 * V_4 , T_1 V_295 , void * V_296 ,
T_1 * V_297 , void * V_110 , struct V_169 * V_174 )
{
struct V_298 * V_299 = V_296 ;
struct V_267 * V_268 = V_110 ;
struct V_267 * V_300 = NULL ;
struct V_286 * V_287 ;
int V_301 ;
unsigned int V_302 = 0 ;
int V_288 = 0 , V_303 , V_271 ;
T_4 V_269 , V_270 , V_304 , V_277 ;
T_4 V_305 ;
int V_290 = 0 , V_33 = 0 , V_10 ;
int V_306 = 0 ;
int V_307 = 0 ;
int V_282 ;
int V_308 = 0 , V_309 = 0 , V_281 ;
unsigned int V_310 = V_311 ;
if ( ! F_148 ( V_174 ) ) {
V_33 = 0 ;
goto V_75;
}
if ( F_146 ( V_299 -> V_268 . V_279 ) < V_310 )
V_310 = F_146 ( V_299 -> V_268 . V_279 ) ;
F_149 ( V_300 , V_310 ) ;
if ( V_300 == NULL ) {
V_33 = - V_103 ;
goto V_75;
}
V_287 = & V_300 -> V_273 [ 0 ] ;
V_301 = F_150 ( V_310 ) ;
memcpy ( V_268 , & V_299 -> V_268 , sizeof( * V_268 ) ) ;
V_269 = V_268 -> V_269 ;
V_304 = V_268 -> V_304 ;
V_303 = V_271 = F_151 ( V_174 , V_269 ) ;
V_270 = ( V_304 == ~ 0ULL ? V_299 -> V_190 . V_312 :
V_269 + V_304 - 1 ) ;
if ( V_270 > V_299 -> V_190 . V_312 )
V_270 = V_299 -> V_190 . V_312 ;
V_282 = F_144 ( V_174 , V_269 , V_270 ,
V_303 , & V_281 ) ;
V_277 = F_142 ( V_268 , V_174 , V_269 ,
V_270 , & V_271 ) ;
if ( V_277 == - V_34 ) {
V_33 = - V_34 ;
goto V_75;
}
if ( F_146 ( V_268 -> V_279 ) > * V_297 )
V_268 -> V_279 = F_150 ( * V_297 ) ;
if ( V_268 -> V_279 == 0 ) {
V_302 = 1 ;
V_301 = 0 ;
}
for ( V_308 = V_271 , V_10 = 0 ; V_10 < V_281 ;
V_10 ++ , V_308 = ( V_308 + 1 ) % V_174 -> V_181 ) {
T_4 V_313 ;
T_4 V_314 ;
T_4 V_275 , V_276 , V_315 ;
unsigned int V_289 ;
V_309 = V_308 ;
if ( ( F_143 ( V_174 , V_308 , V_269 , V_270 ,
& V_275 , & V_315 ) ) == 0 )
continue;
if ( F_95 ( V_174 -> V_184 [ V_308 ] ) ) {
V_33 = - V_189 ;
goto V_75;
}
if ( V_277 != 0 && V_308 == V_271 )
V_275 = V_277 ;
if ( V_304 != ~ 0ULL ) {
if ( V_269 + V_304 < V_269 )
V_304 = ~ 0ULL - V_269 ;
V_276 = F_152 ( V_174 , V_269 + V_304 ,
V_308 ) ;
} else {
V_276 = ~ 0ULL ;
}
if ( V_275 == V_276 )
continue;
V_313 = V_315 - V_275 ;
V_300 -> V_304 = 0 ;
V_314 = 0 ;
V_306 = 0 ;
V_307 = 0 ;
do {
if ( V_302 == 0 ) {
if ( V_290 + V_301 >
V_268 -> V_279 )
V_301 = V_268 -> V_279 -
V_290 ;
}
V_275 += V_314 ;
V_300 -> V_304 = V_313 - V_314 ;
V_313 = V_300 -> V_304 ;
V_300 -> V_279 = V_301 ;
V_300 -> V_316 = 0 ;
V_300 -> V_317 = V_268 -> V_317 ;
V_299 -> V_190 . V_187 = V_174 -> V_184 [ V_308 ] -> V_186 ;
V_288 = V_174 -> V_184 [ V_308 ] -> V_185 ;
if ( V_288 < 0 ||
V_288 >= V_4 -> V_15 . V_16 ) {
V_33 = - V_34 ;
goto V_75;
}
if ( ! V_4 -> V_17 [ V_288 ] -> V_69 ) {
V_300 -> V_317 |= V_318 ;
V_300 -> V_316 = 1 ;
V_287 [ 0 ] . V_274 = V_275 ;
V_287 [ 0 ] . V_319 = V_315 -
V_275 ;
V_287 [ 0 ] . V_293 |= V_320 ;
goto V_321;
}
V_300 -> V_269 = V_275 ;
V_300 -> V_317 &= ~ V_322 ;
memcpy ( & V_299 -> V_268 , V_300 , sizeof( * V_300 ) ) ;
* V_297 = F_146 ( V_300 -> V_279 ) ;
V_33 = F_153 ( NULL ,
V_4 -> V_17 [ V_288 ] -> V_47 ,
V_295 , V_296 , V_297 , V_300 , V_174 ) ;
if ( V_33 != 0 )
goto V_75;
V_321:
V_289 = V_300 -> V_316 ;
if ( V_289 == 0 ) {
V_307 = 1 ;
if ( V_309 == V_282 ) {
V_268 -> V_316 = 0 ;
goto V_323;
}
break;
}
if ( V_302 ) {
V_290 += V_289 ;
break;
}
V_314 = V_287 [ V_289 - 1 ] . V_274 -
V_275 + V_287 [ V_289 - 1 ] . V_319 ;
if ( V_313 <= V_314 )
V_307 = 1 ;
if ( V_287 [ V_289 - 1 ] . V_293 & V_318 )
V_287 [ V_289 - 1 ] . V_293 &=
~ V_318 ;
V_305 = F_154 ( V_174 ,
V_287 [ V_289 - 1 ] . V_274 +
V_287 [ V_289 - 1 ] . V_319 ,
V_308 ) ;
if ( V_305 >= V_299 -> V_190 . V_312 )
V_306 = 1 ;
F_145 ( V_268 , V_287 ,
V_288 , V_289 ,
V_290 ) ;
V_290 += V_289 ;
if ( V_290 >= V_268 -> V_279 )
goto V_323;
} while ( V_307 == 0 && V_306 == 0 );
if ( V_309 == V_282 )
goto V_323;
}
V_323:
if ( V_174 -> V_181 > 1 )
V_268 -> V_317 |= V_322 ;
if ( V_302 )
goto V_324;
if ( V_309 == V_282 ) {
if ( V_307 || V_306 )
V_268 -> V_273 [ V_290 - 1 ] . V_293 |=
V_318 ;
}
V_324:
V_268 -> V_316 = V_290 ;
V_75:
F_155 ( V_300 , V_310 ) ;
return V_33 ;
}
static int F_156 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_1 V_295 , void * V_296 , T_1 * V_297 , void * V_110 ,
struct V_169 * V_174 )
{
struct V_1 * V_233 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_233 -> V_5 . V_4 ;
int V_10 , V_33 ;
if ( ! V_297 || ! V_110 )
return - V_242 ;
F_26 ( V_233 ) ;
if ( F_157 ( V_325 ) ) {
struct {
char V_326 [ 16 ] ;
struct V_327 * V_328 ;
} * V_24 = V_296 ;
struct V_329 * V_330 = & V_24 -> V_328 -> V_331 -> V_332 ;
struct V_182 * V_183 ;
T_1 * V_333 = V_110 ;
if ( * V_297 < sizeof( * V_333 ) ) {
V_33 = - V_242 ;
goto V_75;
}
* V_297 = sizeof( * V_333 ) ;
for ( V_10 = 0 ; V_10 < V_174 -> V_181 ; V_10 ++ ) {
V_183 = V_174 -> V_184 [ V_10 ] ;
if ( F_95 ( V_183 ) )
continue;
if ( ! V_4 -> V_17 [ V_183 -> V_185 ] )
continue;
if ( V_4 -> V_17 [ V_183 -> V_185 ] -> V_47 ==
V_24 -> V_328 -> V_334 &&
F_158 ( & V_183 -> V_186 , V_330 ) ) {
* V_333 = V_10 ;
V_33 = 0 ;
goto V_75;
}
}
F_159 ( V_24 -> V_328 , L_69 ) ;
F_160 ( V_335 , V_174 ) ;
V_33 = - V_336 ;
goto V_75;
} else if ( F_157 ( V_337 ) ) {
struct V_338 * V_339 = V_110 ;
T_1 V_340 = sizeof( T_4 ) ;
struct V_11 * V_12 ;
F_20 ( * V_297 == sizeof( struct V_338 ) ) ;
V_12 = V_4 -> V_17 [ V_339 -> V_341 ] ;
if ( ! V_12 || ! V_12 -> V_69 ) {
V_33 = - V_342 ;
goto V_75;
}
V_33 = F_153 ( V_59 , V_12 -> V_47 , V_295 , V_296 ,
& V_340 , V_339 -> V_24 , NULL ) ;
V_33 = 0 ;
goto V_75;
} else if ( F_157 ( V_343 ) ) {
struct V_115 * V_344 = V_110 ;
* V_344 = V_4 -> V_15 ;
V_33 = 0 ;
goto V_75;
} else if ( F_157 ( V_345 ) ) {
V_33 = F_147 ( V_4 , V_295 , V_296 , V_297 , V_110 , V_174 ) ;
goto V_75;
} else if ( F_157 ( V_346 ) ) {
struct V_11 * V_12 ;
T_2 V_175 = * ( ( T_2 * ) V_110 ) ;
F_20 ( * V_297 == sizeof( T_2 ) ) ;
F_20 ( V_175 < V_4 -> V_15 . V_16 ) ;
V_12 = V_4 -> V_17 [ V_175 ] ;
if ( ! V_12 || ! V_12 -> V_47 ) {
V_33 = - V_342 ;
goto V_75;
}
* ( ( T_2 * ) V_110 ) = F_161 ( V_12 -> V_47 ) ;
V_33 = 0 ;
goto V_75;
} else if ( F_157 ( V_347 ) ) {
* ( ( int * ) V_110 ) = V_4 -> V_15 . V_16 ;
V_33 = 0 ;
goto V_75;
}
V_33 = - V_34 ;
V_75:
F_29 ( V_233 ) ;
return V_33 ;
}
static int F_162 ( const struct V_58 * V_59 , struct V_60 * exp ,
T_5 V_295 , void * V_296 , T_5 V_297 ,
void * V_110 , struct V_210 * V_194 )
{
struct V_1 * V_233 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_233 -> V_5 . V_4 ;
T_5 V_109 ;
int V_10 , V_33 = 0 , V_199 ;
struct V_11 * V_12 ;
unsigned V_348 , V_349 ,
V_350 , V_351 ;
unsigned V_352 = 0 , V_353 = 0 , V_192 = 0 ;
V_348 = V_349 = V_350 = V_351 = 0 ;
if ( V_194 == NULL ) {
V_351 = 1 ;
V_194 = F_129 () ;
if ( ! V_194 )
return - V_103 ;
}
F_26 ( V_233 ) ;
V_109 = V_4 -> V_15 . V_16 ;
if ( F_157 ( V_354 ) ) {
V_109 = V_297 / sizeof( struct V_338 ) ;
V_297 = sizeof( T_4 ) ;
V_348 = sizeof( struct V_338 ) ;
V_350 = 1 ;
V_352 = 1 ;
} else if ( F_157 ( V_355 ) ) {
V_350 = 1 ;
} else if ( F_157 ( V_356 ) ) {
} else if ( F_157 ( V_357 ) ) {
V_353 = 1 ;
} else if ( F_157 ( V_358 ) ) {
V_192 = 1 ;
} else if ( F_157 ( V_107 ) ) {
F_20 ( V_4 -> V_106 == NULL ) ;
V_4 -> V_106 = V_110 ;
V_350 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_109 ; V_10 ++ , V_110 = ( char * ) V_110 + V_348 ) {
if ( V_352 ) {
V_12 = V_4 -> V_17 [ ( ( struct V_338 * )val )->idx] ;
}
void F_163 ( struct V_169 * V_359 )
__releases( &md->lsm_lock
static int F_164 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_257 * V_258 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
T_2 V_360 = 0 ;
T_2 V_361 = 0 ;
int V_10 , V_33 = 0 ;
if ( V_258 -> V_362 != V_363 &&
V_258 -> V_362 != V_364 &&
V_258 -> V_362 != V_365 &&
V_258 -> V_362 != V_366 &&
V_258 -> V_362 != V_367 &&
V_258 -> V_362 != V_368 ) {
F_15 ( L_70 , V_258 -> V_362 ) ;
return - V_242 ;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_199 ;
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 )
continue;
if ( ! V_12 -> V_69 || V_12 -> V_18 ) {
if ( V_258 -> V_362 == V_365 &&
V_4 -> V_17 [ V_10 ] -> V_67 ) {
V_33 = - V_369 ;
F_15 ( L_71 , V_10 ) ;
} else {
F_8 ( V_223 , L_71 , V_10 ) ;
}
continue;
}
V_199 = V_257 ( V_12 -> V_47 , V_258 ) ;
if ( V_199 ) {
if ( V_12 -> V_69 && ! V_33 )
V_33 = V_199 ;
continue;
}
if ( V_258 -> V_362 == V_365 ) {
V_360 += V_258 -> V_370 . V_371 ;
V_361 += V_258 -> V_370 . V_372 ;
}
}
F_29 ( V_2 ) ;
if ( V_258 -> V_362 == V_365 ) {
V_258 -> V_370 . V_371 = V_360 ;
V_258 -> V_370 . V_372 = V_361 ;
}
return V_33 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_60 * exp ,
struct V_257 * V_258 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_33 = 0 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( ! V_4 -> V_17 [ V_10 ] -> V_67 ) {
F_79 ( L_72 ,
V_10 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_69 ) {
F_15 ( L_73 , V_10 ) ;
V_33 = - V_189 ;
goto V_75;
}
}
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_199 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_67 )
continue;
V_199 = F_166 ( V_4 -> V_17 [ V_10 ] -> V_47 , V_258 ) ;
if ( V_199 && ! V_33 )
V_33 = V_199 ;
}
V_75:
F_29 ( V_2 ) ;
return V_33 ;
}
static int T_6 F_167 ( void )
{
struct V_122 V_123 = { NULL } ;
int V_33 ;
F_8 ( V_80 , L_74 , & V_373 ) ;
V_33 = F_168 ( V_373 ) ;
if ( V_33 )
return V_33 ;
V_374 = F_169 ( L_75 ,
sizeof( struct V_182 ) ,
0 , V_375 , NULL ) ;
if ( V_374 == NULL ) {
F_170 ( V_373 ) ;
return - V_103 ;
}
F_75 ( & V_123 ) ;
V_33 = F_171 ( & V_376 , NULL , V_123 . V_377 ,
V_378 , & V_379 ) ;
if ( V_33 ) {
F_172 ( V_374 ) ;
F_170 ( V_373 ) ;
}
return V_33 ;
}
static void F_173 ( void )
{
F_174 ( V_378 ) ;
F_172 ( V_374 ) ;
F_170 ( V_373 ) ;
}
