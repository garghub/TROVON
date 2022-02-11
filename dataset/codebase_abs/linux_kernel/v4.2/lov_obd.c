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
int V_31 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_32 ;
V_26 = & V_4 -> V_17 [ V_21 ] -> V_33 ;
V_27 = V_4 -> V_17 [ V_21 ] -> V_34 ;
if ( ! V_27 -> V_35 ) {
F_15 ( L_3 , F_16 ( V_26 ) ) ;
return - V_32 ;
}
V_27 -> V_5 . V_36 . V_37 = V_4 -> V_38 ;
if ( V_24 && ( V_24 -> V_39 & V_40 ) )
V_24 -> V_41 = V_21 ;
V_30 = V_27 -> V_5 . V_36 . V_42 ;
if ( V_22 ) {
V_27 -> V_43 = 0 ;
F_17 ( V_30 ) ;
}
V_31 = F_18 ( V_27 , V_2 ) ;
if ( V_31 ) {
F_15 ( L_4 ,
F_16 ( V_26 ) , V_31 ) ;
return V_31 ;
}
if ( V_30 -> V_44 ) {
F_8 ( V_14 , L_5 ,
F_16 ( V_26 ) ) ;
return 0 ;
}
V_31 = F_19 ( NULL , & V_4 -> V_17 [ V_21 ] -> V_45 , V_27 ,
& V_28 , V_24 , NULL ) ;
if ( V_31 || ! V_4 -> V_17 [ V_21 ] -> V_45 ) {
F_15 ( L_6 ,
F_16 ( V_26 ) , V_31 ) ;
return - V_46 ;
}
V_4 -> V_17 [ V_21 ] -> V_18 = 0 ;
F_8 ( V_14 , L_7 , V_21 ,
F_16 ( V_26 ) , V_27 -> V_47 , V_22 ? L_8 : L_9 ) ;
if ( V_4 -> V_48 )
V_31 = F_20 ( V_4 -> V_48 , & V_27 -> V_49 ,
V_27 -> V_47 ) ;
return 0 ;
}
static int F_21 ( const struct V_50 * V_51 ,
struct V_52 * * exp , struct V_1 * V_2 ,
struct V_25 * V_53 , struct V_23 * V_24 ,
void * V_54 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
struct V_55 V_56 ;
int V_10 , V_31 ;
F_8 ( V_14 , L_10 , V_4 -> V_57 ) ;
V_31 = F_22 ( & V_56 , V_2 , V_53 ) ;
if ( V_31 )
return V_31 ;
* exp = F_23 ( & V_56 ) ;
V_4 -> V_57 ++ ;
F_24 ( V_4 -> V_57 == 1 ) ;
memset ( & V_4 -> V_58 , 0 , sizeof( V_4 -> V_58 ) ) ;
if ( V_24 )
V_4 -> V_58 = * V_24 ;
F_25 ( V_2 ) ;
V_4 -> V_48 = F_26 ( L_11 ,
& V_2 -> V_49 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 || F_27 ( & V_12 -> V_33 ) )
continue;
V_31 = F_14 ( V_2 , V_10 , V_12 -> V_59 , & V_4 -> V_58 ) ;
if ( V_31 ) {
F_15 ( L_12 ,
V_2 -> V_47 , V_10 , V_31 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_45 )
continue;
V_31 = F_28 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_45 -> V_60 ,
V_61 , ( void * ) & V_10 ) ;
if ( V_31 ) {
F_15 ( L_13 ,
V_2 -> V_47 , V_31 ) ;
}
}
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_1 * V_62 ;
int V_31 ;
V_62 = F_31 ( V_12 -> V_45 ) ;
F_8 ( V_14 , L_14 ,
V_2 -> V_47 , V_62 ? V_62 -> V_47 : L_15 ) ;
if ( V_12 -> V_63 ) {
V_12 -> V_63 = 0 ;
V_4 -> V_15 . V_64 -- ;
V_12 -> V_45 -> V_60 -> V_65 = 1 ;
}
if ( V_62 ) {
if ( V_4 -> V_48 )
F_32 ( V_4 -> V_48 ,
V_62 -> V_47 ) ;
V_62 -> V_66 = V_2 -> V_66 ;
V_62 -> V_67 = V_2 -> V_67 ;
V_62 -> V_43 = V_2 -> V_43 ;
}
F_18 ( V_62 , NULL ) ;
V_31 = F_33 ( V_12 -> V_45 ) ;
if ( V_31 ) {
F_15 ( L_16 ,
V_12 -> V_33 . V_68 , V_31 ) ;
V_31 = 0 ;
}
V_12 -> V_45 = NULL ;
return 0 ;
}
static int F_34 ( struct V_52 * exp )
{
struct V_1 * V_2 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_31 ;
if ( ! V_4 -> V_17 )
goto V_69;
V_4 -> V_57 -- ;
if ( V_4 -> V_57 != 0 ) {
F_15 ( L_17 , V_4 -> V_57 ) ;
goto V_69;
}
F_25 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( V_4 -> V_17 [ V_10 ] && V_4 -> V_17 [ V_10 ] -> V_45 ) {
F_35 ( V_2 , V_10 , NULL , V_4 -> V_17 [ V_10 ] -> V_70 ) ;
}
}
if ( V_4 -> V_48 )
F_36 ( V_4 -> V_48 ) ;
F_29 ( V_2 ) ;
V_69:
V_31 = F_37 ( exp ) ;
return V_31 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_25 * V_68 ,
enum V_71 V_72 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
int V_21 , V_22 , V_73 ;
F_8 ( V_74 , L_18 ,
V_4 , V_68 -> V_68 , V_72 ) ;
F_25 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_15 . V_16 ; V_21 ++ ) {
V_12 = V_4 -> V_17 [ V_21 ] ;
if ( ! V_12 )
continue;
if ( V_72 == V_75 && V_12 -> V_45 == NULL &&
F_39 ( V_68 , & V_12 -> V_33 ) ) {
struct V_25 V_28 = { L_2 } ;
F_19 ( NULL , & V_12 -> V_45 , V_12 -> V_34 ,
& V_28 , & V_4 -> V_58 , NULL ) ;
}
if ( ! V_12 -> V_45 )
continue;
F_8 ( V_74 , L_19 ,
V_21 , F_16 ( & V_12 -> V_33 ) ,
V_12 -> V_45 -> V_76 . V_77 ) ;
if ( F_39 ( V_68 , & V_12 -> V_33 ) )
break;
}
if ( V_21 == V_4 -> V_15 . V_16 ) {
V_21 = - V_32 ;
goto V_69;
}
if ( V_72 == V_78 || V_72 == V_75 ) {
V_22 = ( V_72 == V_75 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_59 == V_22 ) {
F_8 ( V_74 , L_20 ,
V_68 -> V_68 , V_22 ? L_8 : L_21 ) ;
} else {
V_4 -> V_17 [ V_21 ] -> V_59 = V_22 ;
F_8 ( V_14 , L_22 ,
V_22 ? L_8 : L_21 , F_16 ( V_68 ) ) ;
}
} else if ( V_72 == V_79 || V_72 == V_80 ) {
V_73 = ( V_72 == V_80 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_21 ] -> V_63 == V_73 ) {
F_8 ( V_74 , L_23 ,
V_68 -> V_68 , V_73 ? L_8 : L_9 ) ;
goto V_69;
} else {
F_8 ( V_14 , L_24 ,
F_16 ( V_68 ) , V_73 ? L_8 : L_9 ) ;
}
V_4 -> V_17 [ V_21 ] -> V_63 = V_73 ;
if ( V_73 ) {
V_4 -> V_15 . V_64 ++ ;
V_4 -> V_17 [ V_21 ] -> V_45 -> V_60 -> V_65 = 0 ;
} else {
V_4 -> V_15 . V_64 -- ;
V_4 -> V_17 [ V_21 ] -> V_45 -> V_60 -> V_65 = 1 ;
}
} else {
F_15 ( L_25 , V_72 , V_68 -> V_68 ) ;
}
V_69:
F_29 ( V_2 ) ;
return V_21 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_1 * V_81 ,
enum V_71 V_72 , void * V_24 )
{
int V_31 = 0 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
F_40 ( & V_4 -> V_82 ) ;
if ( ! V_4 -> V_57 ) {
F_41 ( & V_4 -> V_82 ) ;
return V_31 ;
}
if ( V_72 == V_80 || V_72 == V_79 ||
V_72 == V_75 || V_72 == V_78 ) {
struct V_25 * V_68 ;
F_24 ( V_81 ) ;
if ( strcmp ( V_81 -> V_83 -> V_84 , V_85 ) ) {
F_41 ( & V_4 -> V_82 ) ;
F_15 ( L_26 ,
V_81 -> V_83 -> V_84 ,
V_81 -> V_47 ) ;
return - V_32 ;
}
V_68 = & V_81 -> V_5 . V_36 . V_86 ;
V_31 = F_38 ( V_2 , V_68 , V_72 ) ;
if ( V_31 < 0 ) {
F_41 ( & V_4 -> V_82 ) ;
F_15 ( L_27 , V_72 ,
F_16 ( V_68 ) , V_31 ) ;
return V_31 ;
}
V_24 = & V_31 ;
}
if ( V_81 ) {
V_31 = F_42 ( V_2 , V_81 , V_72 , V_24 ) ;
} else {
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_87 ;
V_24 = & V_10 ;
V_87 = ( V_72 == V_88 ) ||
( V_72 == V_89 ) ;
F_25 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_87 && ! V_4 -> V_17 [ V_10 ] -> V_63 )
continue;
V_31 = F_42 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_34 ,
V_72 , V_24 ) ;
if ( V_31 ) {
F_15 ( L_28 ,
V_2 -> V_47 ,
V_2 -> V_90 -> V_47 ,
V_4 -> V_17 [ V_10 ] -> V_34 -> V_47 ,
V_31 ) ;
}
}
F_29 ( V_2 ) ;
}
F_41 ( & V_4 -> V_82 ) ;
return V_31 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_25 * V_91 ,
T_1 V_21 , int V_92 , int V_73 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
struct V_1 * V_27 ;
int V_31 ;
F_8 ( V_14 , L_29 ,
V_91 -> V_68 , V_21 , V_92 , V_73 ) ;
if ( V_92 <= 0 ) {
F_15 ( L_30 ,
V_91 -> V_68 , V_92 ) ;
return - V_32 ;
}
V_27 = F_44 ( V_91 , V_85 ,
& V_2 -> V_25 ) ;
if ( V_27 == NULL )
return - V_32 ;
F_2 ( & V_4 -> V_6 ) ;
if ( ( V_21 < V_4 -> V_93 ) && ( V_4 -> V_17 [ V_21 ] != NULL ) ) {
V_12 = V_4 -> V_17 [ V_21 ] ;
F_15 ( L_31 ,
F_16 ( & V_12 -> V_33 ) , V_21 ) ;
F_4 ( & V_4 -> V_6 ) ;
return - V_94 ;
}
if ( V_21 >= V_4 -> V_93 ) {
struct V_11 * * V_95 , * * V_96 = NULL ;
T_1 V_97 , V_98 = 0 ;
V_97 = F_45 ( T_1 , V_4 -> V_93 , 2 ) ;
while ( V_97 < V_21 + 1 )
V_97 <<= 1 ;
V_95 = F_46 ( V_97 , sizeof( * V_95 ) , V_99 ) ;
if ( V_95 == NULL ) {
F_4 ( & V_4 -> V_6 ) ;
return - V_100 ;
}
if ( V_4 -> V_93 ) {
memcpy ( V_95 , V_4 -> V_17 , sizeof( * V_95 ) *
V_4 -> V_93 ) ;
V_96 = V_4 -> V_17 ;
V_98 = V_4 -> V_93 ;
}
V_4 -> V_17 = V_95 ;
V_4 -> V_93 = V_97 ;
F_47 () ;
F_48 ( V_96 ) ;
F_8 ( V_14 , L_32 ,
V_4 -> V_17 , V_4 -> V_93 ) ;
}
V_12 = F_49 ( sizeof( * V_12 ) , V_99 ) ;
if ( ! V_12 ) {
F_4 ( & V_4 -> V_6 ) ;
return - V_100 ;
}
V_31 = F_50 ( & V_4 -> V_20 , V_21 , V_4 -> V_93 ) ;
if ( V_31 ) {
F_4 ( & V_4 -> V_6 ) ;
F_48 ( V_12 ) ;
return V_31 ;
}
V_12 -> V_33 = * V_91 ;
V_12 -> V_34 = V_27 ;
V_12 -> V_70 = V_92 ;
V_12 -> V_101 = V_21 ;
V_12 -> V_59 = V_73 ;
V_4 -> V_17 [ V_21 ] = V_12 ;
if ( V_21 >= V_4 -> V_15 . V_16 )
V_4 -> V_15 . V_16 = V_21 + 1 ;
F_4 ( & V_4 -> V_6 ) ;
F_8 ( V_14 , L_33 ,
V_21 , V_12 -> V_70 , V_4 -> V_15 . V_16 ) ;
V_31 = F_51 ( V_2 , V_27 , V_102 , & V_21 ) ;
if ( V_4 -> V_57 == 0 ) {
return 0 ;
}
F_25 ( V_2 ) ;
V_31 = F_14 ( V_2 , V_21 , V_73 , & V_4 -> V_58 ) ;
if ( V_31 )
goto V_69;
if ( ! V_12 -> V_45 ) {
V_31 = 0 ;
goto V_69;
}
if ( V_4 -> V_103 != NULL ) {
V_31 = F_52 ( NULL , V_12 -> V_45 ,
sizeof( V_104 ) , V_104 ,
sizeof( struct V_105 ) , V_4 -> V_103 ,
NULL ) ;
if ( V_31 < 0 )
goto V_69;
}
V_31 = F_28 ( V_2 , V_12 -> V_45 -> V_60 ,
V_73 ? V_61 : V_79 ,
( void * ) & V_21 ) ;
V_69:
if ( V_31 ) {
F_15 ( L_34 , V_31 ,
F_16 ( & V_12 -> V_33 ) ) ;
F_35 ( V_2 , V_21 , NULL , 0 ) ;
}
F_29 ( V_2 ) ;
return V_31 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_21 ,
struct V_25 * V_91 , int V_92 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_106 = V_4 -> V_15 . V_16 ;
int V_31 = 0 ;
if ( V_21 >= V_106 ) {
F_15 ( L_35 ,
V_21 , V_106 ) ;
return - V_32 ;
}
F_53 ( & V_4 -> V_82 ) ;
F_25 ( V_2 ) ;
if ( ! V_4 -> V_17 [ V_21 ] ) {
F_15 ( L_36 , V_21 ) ;
V_31 = - V_32 ;
goto V_69;
}
if ( V_91 && ! F_39 ( V_91 , & V_4 -> V_17 [ V_21 ] -> V_33 ) ) {
F_15 ( L_37 ,
F_54 ( V_4 , V_21 ) , V_21 ,
F_16 ( V_91 ) ) ;
V_31 = - V_32 ;
goto V_69;
}
F_8 ( V_14 , L_38 ,
F_54 ( V_4 , V_21 ) , V_21 ,
V_4 -> V_17 [ V_21 ] -> V_70 , V_4 -> V_17 [ V_21 ] -> V_45 ,
V_4 -> V_17 [ V_21 ] -> V_63 ) ;
V_4 -> V_17 [ V_21 ] -> V_18 = 1 ;
V_4 -> V_8 ++ ;
V_69:
F_29 ( V_2 ) ;
F_55 ( & V_4 -> V_82 ) ;
return V_31 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_1 * V_62 ;
F_24 ( V_12 ) ;
F_24 ( V_12 -> V_18 ) ;
V_62 = F_31 ( V_12 -> V_45 ) ;
F_8 ( V_14 , L_39 ,
V_12 -> V_33 . V_68 ,
V_62 ? V_62 -> V_47 : L_40 ) ;
if ( V_12 -> V_45 )
F_30 ( V_2 , V_12 ) ;
F_48 ( V_12 ) ;
if ( V_62 )
F_56 ( V_62 ) ;
}
void F_57 ( T_2 * V_107 )
{
if ( * V_107 < V_108 ) {
if ( * V_107 != 0 )
F_58 ( L_41 ,
V_109 ) ;
* V_107 = V_109 ;
} else if ( * V_107 & ( V_108 - 1 ) ) {
* V_107 &= ~ ( V_108 - 1 ) ;
F_59 ( L_42 ,
* V_107 , V_108 ) ;
}
}
void F_60 ( T_1 * V_107 )
{
if ( * V_107 == 0 )
* V_107 = 1 ;
}
void F_61 ( T_1 * V_107 )
{
if ( ( * V_107 != 0 ) && ( * V_107 != V_110 ) ) {
F_59 ( L_43 , * V_107 ) ;
* V_107 = 0 ;
}
}
void F_62 ( T_1 * V_107 )
{
if ( * V_107 == 0 )
* V_107 = V_111 ;
}
void F_63 ( struct V_112 * V_15 )
{
F_57 ( & V_15 -> V_113 ) ;
F_60 ( & V_15 -> V_114 ) ;
F_61 ( & V_15 -> V_115 ) ;
F_62 ( & V_15 -> V_116 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
struct V_119 V_120 = { NULL } ;
struct V_112 * V_15 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_31 ;
if ( F_65 ( V_118 , 1 ) < 1 ) {
F_15 ( L_44 ) ;
return - V_32 ;
}
V_15 = (struct V_112 * ) F_66 ( V_118 , 1 ) ;
if ( sizeof( * V_15 ) > F_65 ( V_118 , 1 ) ) {
F_15 ( L_45 ,
( int ) sizeof( * V_15 ) , F_65 ( V_118 , 1 ) ) ;
return - V_32 ;
}
if ( V_15 -> V_121 != V_122 ) {
if ( V_15 -> V_121 == F_67 ( V_122 ) ) {
F_8 ( V_123 , L_46 ,
V_2 -> V_47 , V_15 ) ;
F_68 ( V_15 ) ;
} else {
F_15 ( L_47 ,
V_2 -> V_47 , V_15 -> V_121 ) ;
return - V_32 ;
}
}
F_63 ( V_15 ) ;
V_15 -> V_64 = 0 ;
V_4 -> V_15 = * V_15 ;
V_4 -> V_93 = 0 ;
F_69 ( & V_4 -> V_6 ) ;
F_70 ( & V_4 -> V_7 , 0 ) ;
V_4 -> V_38 = V_124 ;
F_71 ( & V_4 -> V_82 ) ;
V_4 -> V_125 = F_72 ( L_48 , V_126 ,
V_127 ,
V_128 , 0 ,
V_129 ,
V_130 ,
& V_131 ,
V_132 ) ;
F_73 ( & V_4 -> V_133 ) ;
V_4 -> V_134 = 0 ;
V_31 = F_74 ( & V_4 -> V_20 , 0 ) ;
if ( V_31 )
goto V_69;
F_75 ( & V_120 ) ;
F_76 ( V_2 , V_120 . V_135 , V_120 . V_136 ) ;
V_31 = F_77 ( V_2 -> V_137 , L_49 ,
0444 , & V_138 , V_2 ) ;
if ( V_31 )
F_78 ( L_50 ) ;
V_4 -> V_139 = F_79 ( L_51 ,
V_2 -> V_137 ,
NULL , NULL ) ;
return 0 ;
V_69:
return V_31 ;
}
static int F_80 ( struct V_1 * V_2 , enum V_140 V_141 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
switch ( V_141 ) {
case V_142 : {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_63 )
continue;
F_81 ( F_31 ( V_4 -> V_17 [ V_10 ] -> V_45 ) ,
V_142 ) ;
}
break;
}
default:
break;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_143 * V_144 , * V_145 ;
struct V_146 * V_147 ;
F_83 (pos, tmp, &lov->lov_pool_list) {
V_147 = F_84 ( V_144 , struct V_146 , V_148 ) ;
F_8 ( V_74 , L_52 , V_147 ) ;
F_85 ( V_2 , V_147 -> V_149 ) ;
}
F_86 ( V_4 -> V_125 ) ;
F_87 ( & V_4 -> V_20 ) ;
F_88 ( V_2 ) ;
if ( V_4 -> V_17 ) {
int V_10 ;
F_25 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_4 -> V_17 [ V_10 ] -> V_63 ||
F_89 ( & V_4 -> V_7 ) )
F_15 ( L_53 ,
V_10 , V_4 -> V_8 ,
F_89 ( & V_4 -> V_7 ) ) ;
F_35 ( V_2 , V_10 , NULL , 0 ) ;
}
F_29 ( V_2 ) ;
F_48 ( V_4 -> V_17 ) ;
V_4 -> V_93 = 0 ;
}
return 0 ;
}
int F_90 ( struct V_1 * V_2 , struct V_117 * V_118 ,
T_1 * V_150 , int * V_151 )
{
struct V_25 V_25 ;
int V_152 ;
int V_31 = 0 ;
switch ( V_152 = V_118 -> V_153 ) {
case V_154 :
case V_155 :
case V_156 : {
T_1 V_21 ;
int V_92 ;
if ( F_65 ( V_118 , 1 ) > sizeof( V_25 . V_68 ) ) {
V_31 = - V_32 ;
goto V_69;
}
F_91 ( & V_25 , F_66 ( V_118 , 1 ) ) ;
if ( sscanf ( F_66 ( V_118 , 2 ) , L_54 , V_150 ) != 1 ) {
V_31 = - V_32 ;
goto V_69;
}
if ( sscanf ( F_66 ( V_118 , 3 ) , L_54 , V_151 ) != 1 ) {
V_31 = - V_32 ;
goto V_69;
}
V_21 = * V_150 ;
V_92 = * V_151 ;
if ( V_152 == V_154 )
V_31 = F_43 ( V_2 , & V_25 , V_21 , V_92 , 1 ) ;
else if ( V_152 == V_155 )
V_31 = F_43 ( V_2 , & V_25 , V_21 , V_92 , 0 ) ;
else
V_31 = F_35 ( V_2 , V_21 , & V_25 , V_92 ) ;
goto V_69;
}
case V_157 : {
struct V_119 V_120 = { NULL } ;
struct V_112 * V_15 = & ( V_2 -> V_5 . V_4 . V_15 ) ;
if ( ! V_15 ) {
V_31 = - V_32 ;
goto V_69;
}
F_75 ( & V_120 ) ;
V_31 = F_92 ( V_158 , V_120 . V_135 ,
V_118 , V_2 ) ;
if ( V_31 > 0 )
V_31 = 0 ;
goto V_69;
}
case V_159 :
case V_160 :
case V_161 :
case V_162 :
goto V_69;
default: {
F_15 ( L_55 , V_118 -> V_153 ) ;
V_31 = - V_32 ;
goto V_69;
}
}
V_69:
return V_31 ;
}
static int F_93 ( struct V_52 * exp , struct V_163 * V_164 ,
struct V_165 * * V_166 , struct V_167 * V_168 )
{
struct V_165 * V_169 , * V_170 ;
struct V_3 * V_4 = & exp -> V_60 -> V_5 . V_4 ;
unsigned V_171 ;
int V_31 , V_10 ;
F_24 ( V_164 -> V_172 & V_173 &&
V_164 -> V_174 & V_175 ) ;
V_169 = F_49 ( sizeof( * V_169 ) , V_99 ) ;
if ( V_169 == NULL )
return - V_100 ;
V_171 = V_164 -> V_176 ;
V_170 = * V_166 ;
if ( V_170 == NULL ) {
V_31 = - V_32 ;
goto V_69;
}
if ( V_171 >= V_4 -> V_15 . V_16 ||
! V_4 -> V_17 [ V_171 ] ) {
V_31 = - V_32 ;
goto V_69;
}
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
struct V_178 * V_179 = V_170 -> V_180 [ V_10 ] ;
if ( F_94 ( V_179 ) )
continue;
if ( V_179 -> V_181 == V_171 ) {
if ( F_95 ( & V_179 -> V_182 ) != F_95 ( & V_164 -> V_183 ) ) {
V_31 = - V_32 ;
goto V_69;
}
break;
}
}
if ( V_10 == V_170 -> V_177 ) {
V_31 = - V_32 ;
goto V_69;
}
V_31 = F_96 ( NULL , V_4 -> V_17 [ V_171 ] -> V_45 ,
V_164 , & V_169 , V_168 ) ;
V_69:
F_48 ( V_169 ) ;
return V_31 ;
}
static int F_97 ( const struct V_50 * V_51 , struct V_52 * exp ,
struct V_163 * V_164 , struct V_165 * * V_166 ,
struct V_167 * V_168 )
{
struct V_3 * V_4 ;
int V_31 = 0 ;
F_24 ( V_166 != NULL ) ;
if ( exp == NULL )
return - V_32 ;
if ( ( V_164 -> V_172 & V_173 ) &&
V_164 -> V_174 == V_184 ) {
F_98 () ;
}
V_4 = & exp -> V_60 -> V_5 . V_4 ;
if ( ! V_4 -> V_15 . V_64 )
return - V_185 ;
F_25 ( exp -> V_60 ) ;
if ( ( V_164 -> V_172 & V_173 ) &&
( V_164 -> V_174 & V_175 ) ) {
V_31 = F_93 ( exp , V_164 , V_166 , V_168 ) ;
}
F_29 ( exp -> V_60 ) ;
return V_31 ;
}
static int F_99 ( const struct V_50 * V_51 , struct V_52 * exp ,
struct V_163 * V_186 , struct V_165 * V_170 ,
struct V_167 * V_168 , struct V_52 * V_187 ,
void * V_188 )
{
struct V_189 * V_190 ;
struct V_191 V_192 ;
struct V_193 * V_194 ;
struct V_143 * V_144 ;
struct V_3 * V_4 ;
int V_31 = 0 , V_195 = 0 ;
F_100 ( V_170 ) ;
if ( ! exp || ! exp -> V_60 )
return - V_46 ;
if ( V_186 -> V_172 & V_196 ) {
F_24 ( V_168 ) ;
F_24 ( V_168 -> V_197 ) ;
}
V_4 = & exp -> V_60 -> V_5 . V_4 ;
F_25 ( exp -> V_60 ) ;
V_31 = F_101 ( exp , & V_192 , V_186 , V_170 , V_168 , & V_190 ) ;
if ( V_31 )
goto V_69;
F_102 (pos, &set->set_list) {
V_194 = F_84 ( V_144 , struct V_193 , V_198 ) ;
if ( V_186 -> V_172 & V_196 )
V_168 -> V_197 = V_190 -> V_199 + V_194 -> V_200 ;
V_195 = F_103 ( V_51 , V_4 -> V_17 [ V_194 -> V_201 ] -> V_45 ,
V_194 -> V_202 . V_203 , NULL , V_168 , NULL , V_188 ) ;
V_195 = F_104 ( V_190 , V_194 , V_195 ) ;
if ( V_195 ) {
F_15 ( L_56 V_204 L_57
V_204 L_58 ,
exp -> V_60 -> V_47 , F_105 ( & V_186 -> V_183 ) ,
F_105 ( & V_194 -> V_202 . V_203 -> V_183 ) ,
V_194 -> V_201 , V_195 ) ;
if ( ! V_31 )
V_31 = V_195 ;
}
}
if ( V_31 == 0 ) {
F_24 ( F_106 ( V_170 -> V_205 ) != NULL ) ;
V_31 = F_106 ( V_170 -> V_205 ) -> F_107 ( V_170 , V_186 , V_187 ) ;
}
V_195 = F_108 ( V_190 ) ;
V_69:
F_29 ( exp -> V_60 ) ;
return V_31 ? V_31 : V_195 ;
}
static int F_109 ( struct V_206 * V_207 ,
void * V_24 , int V_31 )
{
struct V_189 * V_208 = (struct V_189 * ) V_24 ;
int V_195 ;
if ( V_31 )
F_70 ( & V_208 -> V_209 , 0 ) ;
V_195 = F_110 ( V_208 ) ;
return V_31 ? V_31 : V_195 ;
}
static int F_111 ( struct V_52 * exp , struct V_191 * V_192 ,
struct V_206 * V_207 )
{
struct V_189 * V_208 ;
struct V_3 * V_4 ;
struct V_143 * V_144 ;
struct V_193 * V_194 ;
int V_31 = 0 , V_195 ;
F_24 ( V_192 ) ;
F_100 ( V_192 -> V_210 ) ;
if ( ! exp || ! exp -> V_60 )
return - V_46 ;
V_4 = & exp -> V_60 -> V_5 . V_4 ;
V_31 = F_112 ( exp , V_192 , & V_208 ) ;
if ( V_31 )
return V_31 ;
F_8 ( V_74 , L_59 V_204 L_60 ,
F_105 ( & V_192 -> V_210 -> V_211 ) , V_192 -> V_210 -> V_177 ,
V_192 -> V_210 -> V_212 ) ;
F_102 (pos, &lovset->set_list) {
V_194 = F_84 ( V_144 , struct V_193 , V_198 ) ;
F_8 ( V_74 , L_59 V_204 L_61 V_204 L_62 ,
F_105 ( & V_192 -> V_203 -> V_183 ) , V_194 -> V_200 ,
F_105 ( & V_194 -> V_202 . V_203 -> V_183 ) , V_194 -> V_201 ) ;
V_31 = F_113 ( V_4 -> V_17 [ V_194 -> V_201 ] -> V_45 ,
& V_194 -> V_202 , V_207 ) ;
if ( V_31 ) {
F_15 ( L_63 V_204 L_64
V_204 L_58 ,
exp -> V_60 -> V_47 ,
F_105 ( & V_192 -> V_203 -> V_183 ) ,
F_105 ( & V_194 -> V_202 . V_203 -> V_183 ) ,
V_194 -> V_201 , V_31 ) ;
goto V_69;
}
}
if ( ! F_114 ( & V_207 -> V_213 ) ) {
F_24 ( V_31 == 0 ) ;
F_24 ( V_207 -> V_214 == NULL ) ;
V_207 -> V_214 = F_109 ;
V_207 -> V_215 = ( void * ) V_208 ;
return V_31 ;
}
V_69:
if ( V_31 )
F_70 ( & V_208 -> V_209 , 0 ) ;
V_195 = F_110 ( V_208 ) ;
return V_31 ? V_31 : V_195 ;
}
static int F_115 ( struct V_206 * V_207 ,
void * V_24 , int V_31 )
{
struct V_189 * V_208 = (struct V_189 * ) V_24 ;
int V_195 ;
if ( V_31 )
F_70 ( & V_208 -> V_209 , 0 ) ;
V_195 = F_116 ( V_208 ) ;
return V_31 ? V_31 : V_195 ;
}
static int F_117 ( struct V_52 * exp , struct V_191 * V_192 ,
struct V_167 * V_168 ,
struct V_206 * V_207 )
{
struct V_189 * V_190 ;
struct V_193 * V_194 ;
struct V_143 * V_144 ;
struct V_3 * V_4 ;
int V_31 = 0 ;
F_24 ( V_192 ) ;
F_100 ( V_192 -> V_210 ) ;
if ( V_192 -> V_203 -> V_172 & V_196 ) {
F_24 ( V_168 ) ;
F_24 ( V_168 -> V_197 ) ;
}
if ( ! exp || ! exp -> V_60 )
return - V_46 ;
V_4 = & exp -> V_60 -> V_5 . V_4 ;
V_31 = F_118 ( exp , V_192 , V_168 , & V_190 ) ;
if ( V_31 )
return V_31 ;
F_8 ( V_74 , L_59 V_204 L_60 ,
F_105 ( & V_192 -> V_210 -> V_211 ) ,
V_192 -> V_210 -> V_177 ,
V_192 -> V_210 -> V_212 ) ;
F_102 (pos, &set->set_list) {
V_194 = F_84 ( V_144 , struct V_193 , V_198 ) ;
if ( V_192 -> V_203 -> V_172 & V_196 )
V_168 -> V_197 = V_190 -> V_199 + V_194 -> V_200 ;
F_8 ( V_74 , L_59 V_204 L_61 V_204 L_62 ,
F_105 ( & V_192 -> V_203 -> V_183 ) , V_194 -> V_200 ,
F_105 ( & V_194 -> V_202 . V_203 -> V_183 ) , V_194 -> V_201 ) ;
V_31 = F_119 ( V_4 -> V_17 [ V_194 -> V_201 ] -> V_45 ,
& V_194 -> V_202 , V_168 , V_207 ) ;
if ( V_31 ) {
F_15 ( L_65 V_204 L_64
V_204 L_58 ,
F_105 ( & V_190 -> V_216 -> V_203 -> V_183 ) ,
F_105 ( & V_194 -> V_202 . V_203 -> V_183 ) ,
V_194 -> V_201 , V_31 ) ;
break;
}
}
if ( V_31 || ! V_207 || F_114 ( & V_207 -> V_213 ) ) {
int V_195 ;
if ( V_31 )
F_70 ( & V_190 -> V_209 , 0 ) ;
V_195 = F_116 ( V_190 ) ;
return V_31 ? V_31 : V_195 ;
}
F_24 ( V_207 -> V_214 == NULL ) ;
V_207 -> V_214 = F_115 ;
V_207 -> V_215 = ( void * ) V_190 ;
return 0 ;
}
static int F_120 ( struct V_52 * exp ,
struct V_165 * V_170 , T_3 V_217 ,
void * V_24 )
{
struct V_3 * V_4 ;
int V_31 = 0 , V_10 ;
F_100 ( V_170 ) ;
if ( ! exp || ! exp -> V_60 )
return - V_46 ;
V_4 = & exp -> V_60 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
struct V_165 V_218 ;
struct V_178 * V_179 = V_170 -> V_180 [ V_10 ] ;
if ( F_94 ( V_179 ) )
continue;
if ( ! V_4 -> V_17 [ V_179 -> V_181 ] ) {
F_8 ( V_219 , L_66 , V_179 -> V_181 ) ;
continue;
}
V_218 . V_211 = V_179 -> V_182 ;
V_218 . V_177 = 0 ;
V_31 = F_121 ( V_4 -> V_17 [ V_179 -> V_181 ] -> V_45 ,
& V_218 , V_217 , V_24 ) ;
if ( V_31 != 0 )
return V_31 ;
}
return V_31 ;
}
int F_122 ( struct V_206 * V_207 , void * V_24 , int V_31 )
{
struct V_189 * V_208 = (struct V_189 * ) V_24 ;
int V_195 ;
if ( V_31 )
F_70 ( & V_208 -> V_209 , 0 ) ;
V_195 = F_123 ( V_208 ) ;
return V_31 ? V_31 : V_195 ;
}
static int F_124 ( struct V_52 * exp , struct V_191 * V_192 ,
T_2 V_220 , struct V_206 * V_207 )
{
struct V_1 * V_2 = F_31 ( exp ) ;
struct V_189 * V_190 ;
struct V_193 * V_194 ;
struct V_143 * V_144 ;
struct V_3 * V_4 ;
int V_31 = 0 ;
F_24 ( V_192 != NULL ) ;
F_24 ( V_192 -> V_221 != NULL ) ;
V_4 = & V_2 -> V_5 . V_4 ;
V_31 = F_125 ( V_2 , V_192 , & V_190 ) ;
if ( V_31 )
return V_31 ;
F_102 (pos, &set->set_list) {
V_194 = F_84 ( V_144 , struct V_193 , V_198 ) ;
V_31 = F_126 ( V_4 -> V_17 [ V_194 -> V_201 ] -> V_45 ,
& V_194 -> V_202 , V_220 , V_207 ) ;
if ( V_31 )
break;
}
if ( V_31 || F_114 ( & V_207 -> V_213 ) ) {
int V_195 ;
if ( V_31 )
F_70 ( & V_190 -> V_209 , 0 ) ;
V_195 = F_123 ( V_190 ) ;
return V_31 ? V_31 : V_195 ;
}
F_24 ( V_207 -> V_214 == NULL ) ;
V_207 -> V_214 = F_122 ;
V_207 -> V_215 = ( void * ) V_190 ;
return 0 ;
}
static int F_127 ( const struct V_50 * V_51 , struct V_52 * exp ,
struct V_222 * V_223 , T_2 V_220 , T_1 V_224 )
{
struct V_206 * V_190 = NULL ;
struct V_191 V_192 = { { { 0 } } } ;
int V_31 = 0 ;
V_190 = F_128 () ;
if ( V_190 == NULL )
return - V_100 ;
V_192 . V_221 = V_223 ;
V_192 . V_225 = V_224 ;
V_31 = F_124 ( exp , & V_192 , V_220 , V_190 ) ;
if ( V_31 == 0 )
V_31 = F_129 ( V_190 ) ;
F_130 ( V_190 ) ;
return V_31 ;
}
static int F_131 ( unsigned int V_152 , struct V_52 * exp , int V_226 ,
void * V_227 , void * V_228 )
{
struct V_1 * V_229 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_229 -> V_5 . V_4 ;
int V_10 = 0 , V_31 = 0 , V_106 = V_4 -> V_15 . V_16 ;
struct V_25 * V_91 ;
switch ( V_152 ) {
case V_230 : {
struct V_231 * V_24 = V_227 ;
struct V_1 * V_62 ;
struct V_222 V_232 = { 0 } ;
T_1 V_21 ;
T_1 V_224 ;
memcpy ( & V_21 , V_24 -> V_233 , sizeof( T_1 ) ) ;
if ( V_21 >= V_106 )
return - V_46 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_234 ;
if ( ! V_4 -> V_17 [ V_21 ] -> V_63 )
return - V_235 ;
V_62 = F_31 ( V_4 -> V_17 [ V_21 ] -> V_45 ) ;
if ( ! V_62 )
return - V_32 ;
if ( F_132 ( V_24 -> V_236 , F_133 ( V_62 ) ,
F_134 ( ( int ) V_24 -> V_237 ,
( int ) sizeof( struct V_25 ) ) ) )
return - V_238 ;
V_224 = V_228 ? * ( T_1 * ) V_228 : 0 ;
V_31 = V_222 ( NULL , V_4 -> V_17 [ V_21 ] -> V_45 , & V_232 ,
F_135 ( - V_239 ) ,
V_224 ) ;
if ( V_31 )
return V_31 ;
if ( F_132 ( V_24 -> V_240 , & V_232 ,
F_134 ( ( int ) V_24 -> V_241 ,
( int ) sizeof( V_232 ) ) ) )
return - V_238 ;
break;
}
case V_242 : {
struct V_231 * V_24 ;
struct V_112 * V_15 ;
char * V_243 = NULL ;
T_1 * V_151 ;
V_226 = 0 ;
if ( F_136 ( & V_243 , & V_226 , ( void * ) V_228 ) )
return - V_32 ;
V_24 = (struct V_231 * ) V_243 ;
if ( sizeof( * V_15 ) > V_24 -> V_244 ) {
F_137 ( V_243 , V_226 ) ;
return - V_32 ;
}
if ( sizeof( V_91 -> V_68 ) * V_106 > V_24 -> V_245 ) {
F_137 ( V_243 , V_226 ) ;
return - V_32 ;
}
if ( sizeof( T_1 ) * V_106 > V_24 -> V_246 ) {
F_137 ( V_243 , V_226 ) ;
return - V_32 ;
}
V_15 = (struct V_112 * ) V_24 -> V_247 ;
memcpy ( V_15 , & ( V_4 -> V_15 ) , sizeof( * V_15 ) ) ;
V_91 = (struct V_25 * ) V_24 -> V_233 ;
V_151 = ( T_1 * ) V_24 -> V_248 ;
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ , V_91 ++ , V_151 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
* V_91 = V_4 -> V_17 [ V_10 ] -> V_33 ;
* V_151 = V_4 -> V_17 [ V_10 ] -> V_70 ;
}
if ( F_132 ( ( void * ) V_228 , V_243 , V_226 ) )
V_31 = - V_238 ;
F_137 ( V_243 , V_226 ) ;
break;
}
case V_249 :
V_31 = F_138 ( exp , V_227 , V_228 ) ;
break;
case V_250 : {
struct V_251 * V_252 = V_227 ;
struct V_11 * V_12 = NULL ;
struct V_253 * V_254 ;
if ( V_252 -> V_255 == V_256 ) {
if ( V_252 -> V_257 < 0 || V_106 <= V_252 -> V_257 )
return - V_32 ;
V_12 = V_4 -> V_17 [ V_252 -> V_257 ] ;
if ( ! V_12 || ! V_12 -> V_45 )
return - V_32 ;
} else if ( V_252 -> V_255 == V_258 ) {
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 ||
! F_39 ( & V_12 -> V_33 ,
& V_252 -> V_25 ) )
continue;
if ( V_12 -> V_45 == NULL )
return - V_32 ;
break;
}
} else {
return - V_32 ;
}
if ( V_10 >= V_106 )
return - V_234 ;
F_24 ( V_12 && V_12 -> V_45 ) ;
V_254 = F_49 ( sizeof( * V_254 ) , V_99 ) ;
if ( ! V_254 )
return - V_100 ;
F_139 ( V_254 , V_252 ) ;
V_31 = V_253 ( V_12 -> V_45 , V_254 ) ;
if ( V_31 == 0 ) {
F_139 ( V_252 , V_254 ) ;
V_252 -> V_255 = V_256 ;
V_252 -> V_25 = V_12 -> V_33 ;
}
F_48 ( V_254 ) ;
break;
}
default: {
int V_190 = 0 ;
if ( V_106 == 0 )
return - V_259 ;
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ ) {
int V_195 ;
struct V_1 * V_62 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_45 )
continue;
V_62 = F_31 ( V_4 -> V_17 [ V_10 ] -> V_45 ) ;
V_62 -> V_66 = V_229 -> V_66 ;
V_195 = F_140 ( V_152 , V_4 -> V_17 [ V_10 ] -> V_45 ,
V_226 , V_227 , V_228 ) ;
if ( V_195 == - V_235 && V_152 == V_260 ) {
return V_195 ;
} else if ( V_195 ) {
if ( V_4 -> V_17 [ V_10 ] -> V_63 ) {
F_8 ( V_195 == - V_259 ?
V_261 : V_262 ,
L_67 ,
F_54 ( V_4 , V_10 ) ,
V_10 , V_152 , V_195 ) ;
if ( ! V_31 )
V_31 = V_195 ;
}
} else {
V_190 = 1 ;
}
}
if ( ! V_190 && ! V_31 )
V_31 = - V_185 ;
}
}
return V_31 ;
}
static T_4 F_141 ( struct V_263 * V_264 ,
struct V_165 * V_170 , T_4 V_265 ,
T_4 V_266 , int * V_267 )
{
T_4 V_268 = V_264 -> V_269 [ 0 ] . V_270 ;
T_4 V_271 , V_272 ;
T_4 V_273 ;
int V_274 = - 1 , V_10 ;
if ( V_264 -> V_275 == 0 ||
V_264 -> V_269 [ 0 ] . V_270 == 0 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
struct V_178 * V_192 = V_170 -> V_180 [ V_10 ] ;
if ( F_94 ( V_192 ) )
continue;
if ( V_192 -> V_181 == V_264 -> V_269 [ 0 ] . V_276 ) {
V_274 = V_10 ;
break;
}
}
if ( V_274 == - 1 )
return - V_32 ;
if ( ( F_142 ( V_170 , V_274 , V_265 , V_266 ,
& V_271 , & V_272 ) ) != 0 &&
V_268 < V_272 ) {
V_273 = V_268 ;
* V_267 = V_274 ;
} else {
V_273 = 0 ;
* V_267 = ( V_274 + 1 ) % V_170 -> V_177 ;
}
return V_273 ;
}
static int F_143 ( struct V_165 * V_170 , T_4 V_265 ,
T_4 V_266 , int V_267 ,
int * V_277 )
{
int V_278 ;
T_4 V_279 , V_280 ;
int V_10 , V_281 ;
if ( V_266 - V_265 > V_170 -> V_212 * V_170 -> V_177 ) {
V_278 = V_267 < 1 ? V_170 -> V_177 - 1 :
V_267 - 1 ;
* V_277 = V_170 -> V_177 ;
} else {
for ( V_281 = 0 , V_10 = V_267 ; V_281 < V_170 -> V_177 ;
V_10 = ( V_10 + 1 ) % V_170 -> V_177 , V_281 ++ ) {
if ( ( F_142 ( V_170 , V_10 , V_265 , V_266 ,
& V_279 , & V_280 ) ) == 0 )
break;
}
* V_277 = V_281 ;
V_278 = ( V_267 + V_281 - 1 ) % V_170 -> V_177 ;
}
return V_278 ;
}
static void F_144 ( struct V_263 * V_264 ,
struct V_282 * V_283 ,
int V_284 , unsigned int V_285 ,
int V_286 )
{
char * V_287 ;
int V_288 ;
for ( V_288 = 0 ; V_288 < V_285 ; V_288 ++ ) {
V_283 [ V_288 ] . V_276 = V_284 ;
V_283 [ V_288 ] . V_289 |= V_290 ;
}
V_287 = ( char * ) V_264 + F_145 ( V_286 ) ;
memcpy ( V_287 , V_283 , V_285 * sizeof( struct V_282 ) ) ;
}
static int F_146 ( struct V_3 * V_4 , T_1 V_291 , void * V_292 ,
T_1 * V_293 , void * V_107 , struct V_165 * V_170 )
{
struct V_294 * V_295 = V_292 ;
struct V_263 * V_264 = V_107 ;
struct V_263 * V_296 = NULL ;
struct V_282 * V_283 ;
int V_297 ;
unsigned int V_298 = 0 ;
int V_284 = 0 , V_299 , V_267 ;
T_4 V_265 , V_266 , V_300 , V_273 ;
T_4 V_301 ;
int V_286 = 0 , V_31 = 0 , V_10 ;
int V_302 = 0 ;
int V_303 = 0 ;
int V_278 ;
int V_304 = 0 , V_305 = 0 , V_277 ;
unsigned int V_306 = V_307 ;
if ( ! F_147 ( V_170 ) ) {
V_31 = 0 ;
goto V_69;
}
if ( F_145 ( V_295 -> V_264 . V_275 ) < V_306 )
V_306 = F_145 ( V_295 -> V_264 . V_275 ) ;
V_296 = F_148 ( V_306 , V_99 ) ;
if ( V_296 == NULL ) {
V_31 = - V_100 ;
goto V_69;
}
V_283 = & V_296 -> V_269 [ 0 ] ;
V_297 = F_149 ( V_306 ) ;
memcpy ( V_264 , & V_295 -> V_264 , sizeof( * V_264 ) ) ;
V_265 = V_264 -> V_265 ;
V_300 = V_264 -> V_300 ;
V_299 = V_267 = F_150 ( V_170 , V_265 ) ;
V_266 = ( V_300 == ~ 0ULL ? V_295 -> V_186 . V_308 :
V_265 + V_300 - 1 ) ;
if ( V_266 > V_295 -> V_186 . V_308 )
V_266 = V_295 -> V_186 . V_308 ;
V_278 = F_143 ( V_170 , V_265 , V_266 ,
V_299 , & V_277 ) ;
V_273 = F_141 ( V_264 , V_170 , V_265 ,
V_266 , & V_267 ) ;
if ( V_273 == - V_32 ) {
V_31 = - V_32 ;
goto V_69;
}
if ( F_145 ( V_264 -> V_275 ) > * V_293 )
V_264 -> V_275 = F_149 ( * V_293 ) ;
if ( V_264 -> V_275 == 0 ) {
V_298 = 1 ;
V_297 = 0 ;
}
for ( V_304 = V_267 , V_10 = 0 ; V_10 < V_277 ;
V_10 ++ , V_304 = ( V_304 + 1 ) % V_170 -> V_177 ) {
T_4 V_309 ;
T_4 V_310 ;
T_4 V_271 , V_272 , V_311 ;
unsigned int V_285 ;
V_305 = V_304 ;
if ( ( F_142 ( V_170 , V_304 , V_265 , V_266 ,
& V_271 , & V_311 ) ) == 0 )
continue;
if ( F_94 ( V_170 -> V_180 [ V_304 ] ) ) {
V_31 = - V_185 ;
goto V_69;
}
if ( V_273 != 0 && V_304 == V_267 )
V_271 = V_273 ;
if ( V_300 != ~ 0ULL ) {
if ( V_265 + V_300 < V_265 )
V_300 = ~ 0ULL - V_265 ;
V_272 = F_151 ( V_170 , V_265 + V_300 ,
V_304 ) ;
} else {
V_272 = ~ 0ULL ;
}
if ( V_271 == V_272 )
continue;
V_309 = V_311 - V_271 ;
V_296 -> V_300 = 0 ;
V_310 = 0 ;
V_302 = 0 ;
V_303 = 0 ;
do {
if ( V_298 == 0 ) {
if ( V_286 + V_297 >
V_264 -> V_275 )
V_297 = V_264 -> V_275 -
V_286 ;
}
V_271 += V_310 ;
V_296 -> V_300 = V_309 - V_310 ;
V_309 = V_296 -> V_300 ;
V_296 -> V_275 = V_297 ;
V_296 -> V_312 = 0 ;
V_296 -> V_313 = V_264 -> V_313 ;
V_295 -> V_186 . V_183 = V_170 -> V_180 [ V_304 ] -> V_182 ;
V_284 = V_170 -> V_180 [ V_304 ] -> V_181 ;
if ( V_284 < 0 ||
V_284 >= V_4 -> V_15 . V_16 ) {
V_31 = - V_32 ;
goto V_69;
}
if ( ! V_4 -> V_17 [ V_284 ] -> V_63 ) {
V_296 -> V_313 |= V_314 ;
V_296 -> V_312 = 1 ;
V_283 [ 0 ] . V_270 = V_271 ;
V_283 [ 0 ] . V_315 = V_311 -
V_271 ;
V_283 [ 0 ] . V_289 |= V_316 ;
goto V_317;
}
V_296 -> V_265 = V_271 ;
V_296 -> V_313 &= ~ V_318 ;
memcpy ( & V_295 -> V_264 , V_296 , sizeof( * V_296 ) ) ;
* V_293 = F_145 ( V_296 -> V_275 ) ;
V_31 = F_152 ( NULL ,
V_4 -> V_17 [ V_284 ] -> V_45 ,
V_291 , V_292 , V_293 , V_296 , V_170 ) ;
if ( V_31 != 0 )
goto V_69;
V_317:
V_285 = V_296 -> V_312 ;
if ( V_285 == 0 ) {
V_303 = 1 ;
if ( V_305 == V_278 ) {
V_264 -> V_312 = 0 ;
goto V_319;
}
break;
}
if ( V_298 ) {
V_286 += V_285 ;
break;
}
V_310 = V_283 [ V_285 - 1 ] . V_270 -
V_271 + V_283 [ V_285 - 1 ] . V_315 ;
if ( V_309 <= V_310 )
V_303 = 1 ;
if ( V_283 [ V_285 - 1 ] . V_289 & V_314 )
V_283 [ V_285 - 1 ] . V_289 &=
~ V_314 ;
V_301 = F_153 ( V_170 ,
V_283 [ V_285 - 1 ] . V_270 +
V_283 [ V_285 - 1 ] . V_315 ,
V_304 ) ;
if ( V_301 >= V_295 -> V_186 . V_308 )
V_302 = 1 ;
F_144 ( V_264 , V_283 ,
V_284 , V_285 ,
V_286 ) ;
V_286 += V_285 ;
if ( V_286 >= V_264 -> V_275 )
goto V_319;
} while ( V_303 == 0 && V_302 == 0 );
if ( V_305 == V_278 )
goto V_319;
}
V_319:
if ( V_170 -> V_177 > 1 )
V_264 -> V_313 |= V_318 ;
if ( V_298 )
goto V_320;
if ( V_305 == V_278 ) {
if ( V_303 || V_302 )
V_264 -> V_269 [ V_286 - 1 ] . V_289 |=
V_314 ;
}
V_320:
V_264 -> V_312 = V_286 ;
V_69:
F_154 ( V_296 ) ;
return V_31 ;
}
static int F_155 ( const struct V_50 * V_51 , struct V_52 * exp ,
T_1 V_291 , void * V_292 , T_1 * V_293 , void * V_107 ,
struct V_165 * V_170 )
{
struct V_1 * V_229 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_229 -> V_5 . V_4 ;
int V_10 , V_31 ;
if ( ! V_293 || ! V_107 )
return - V_238 ;
F_25 ( V_229 ) ;
if ( F_156 ( V_321 ) ) {
struct {
char V_322 [ 16 ] ;
struct V_323 * V_324 ;
} * V_24 = V_292 ;
struct V_325 * V_326 = & V_24 -> V_324 -> V_327 -> V_328 ;
struct V_178 * V_179 ;
T_1 * V_329 = V_107 ;
if ( * V_293 < sizeof( * V_329 ) ) {
V_31 = - V_238 ;
goto V_69;
}
* V_293 = sizeof( * V_329 ) ;
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
V_179 = V_170 -> V_180 [ V_10 ] ;
if ( F_94 ( V_179 ) )
continue;
if ( ! V_4 -> V_17 [ V_179 -> V_181 ] )
continue;
if ( V_4 -> V_17 [ V_179 -> V_181 ] -> V_45 ==
V_24 -> V_324 -> V_330 &&
F_157 ( & V_179 -> V_182 , V_326 ) ) {
* V_329 = V_10 ;
V_31 = 0 ;
goto V_69;
}
}
F_158 ( V_24 -> V_324 , L_68 ) ;
F_159 ( V_331 , V_170 ) ;
V_31 = - V_332 ;
goto V_69;
} else if ( F_156 ( V_333 ) ) {
struct V_334 * V_335 = V_107 ;
T_1 V_336 = sizeof( T_4 ) ;
struct V_11 * V_12 ;
F_24 ( * V_293 == sizeof( struct V_334 ) ) ;
V_12 = V_4 -> V_17 [ V_335 -> V_337 ] ;
if ( ! V_12 || ! V_12 -> V_63 ) {
V_31 = - V_338 ;
goto V_69;
}
V_31 = F_152 ( V_51 , V_12 -> V_45 , V_291 , V_292 ,
& V_336 , V_335 -> V_24 , NULL ) ;
V_31 = 0 ;
goto V_69;
} else if ( F_156 ( V_339 ) ) {
struct V_112 * V_340 = V_107 ;
* V_340 = V_4 -> V_15 ;
V_31 = 0 ;
goto V_69;
} else if ( F_156 ( V_341 ) ) {
V_31 = F_146 ( V_4 , V_291 , V_292 , V_293 , V_107 , V_170 ) ;
goto V_69;
} else if ( F_156 ( V_342 ) ) {
struct V_11 * V_12 ;
T_2 V_171 = * ( ( T_2 * ) V_107 ) ;
F_24 ( * V_293 == sizeof( T_2 ) ) ;
F_24 ( V_171 < V_4 -> V_15 . V_16 ) ;
V_12 = V_4 -> V_17 [ V_171 ] ;
if ( ! V_12 || ! V_12 -> V_45 ) {
V_31 = - V_338 ;
goto V_69;
}
* ( ( T_2 * ) V_107 ) = F_160 ( V_12 -> V_45 ) ;
V_31 = 0 ;
goto V_69;
} else if ( F_156 ( V_343 ) ) {
* ( ( int * ) V_107 ) = V_4 -> V_15 . V_16 ;
V_31 = 0 ;
goto V_69;
}
V_31 = - V_32 ;
V_69:
F_29 ( V_229 ) ;
return V_31 ;
}
static int F_161 ( const struct V_50 * V_51 , struct V_52 * exp ,
T_5 V_291 , void * V_292 , T_5 V_293 ,
void * V_107 , struct V_206 * V_190 )
{
struct V_1 * V_229 = F_31 ( exp ) ;
struct V_3 * V_4 = & V_229 -> V_5 . V_4 ;
T_5 V_106 ;
int V_10 , V_31 = 0 , V_195 ;
struct V_11 * V_12 ;
unsigned V_344 , V_345 ,
V_346 , V_347 ;
unsigned V_348 = 0 , V_349 = 0 , V_188 = 0 ;
V_344 = V_345 = V_346 = V_347 = 0 ;
if ( V_190 == NULL ) {
V_347 = 1 ;
V_190 = F_128 () ;
if ( ! V_190 )
return - V_100 ;
}
F_25 ( V_229 ) ;
V_106 = V_4 -> V_15 . V_16 ;
if ( F_156 ( V_350 ) ) {
V_106 = V_293 / sizeof( struct V_334 ) ;
V_293 = sizeof( T_4 ) ;
V_344 = sizeof( struct V_334 ) ;
V_346 = 1 ;
V_348 = 1 ;
} else if ( F_156 ( V_351 ) ) {
V_346 = 1 ;
} else if ( F_156 ( V_352 ) ) {
} else if ( F_156 ( V_353 ) ) {
V_349 = 1 ;
} else if ( F_156 ( V_354 ) ) {
V_188 = 1 ;
} else if ( F_156 ( V_104 ) ) {
F_24 ( V_4 -> V_103 == NULL ) ;
V_4 -> V_103 = V_107 ;
V_346 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ , V_107 = ( char * ) V_107 + V_344 ) {
if ( V_348 ) {
V_12 = V_4 -> V_17 [ ( ( struct V_334 * )val )->idx] ;
}
void F_162 ( struct V_165 * V_355 )
__releases( &md->lsm_lock
static int F_163 ( struct V_1 * V_2 , struct V_52 * exp ,
struct V_253 * V_254 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
T_2 V_356 = 0 ;
T_2 V_357 = 0 ;
int V_10 , V_31 = 0 ;
if ( V_254 -> V_358 != V_359 &&
V_254 -> V_358 != V_360 &&
V_254 -> V_358 != V_361 &&
V_254 -> V_358 != V_362 &&
V_254 -> V_358 != V_363 &&
V_254 -> V_358 != V_364 ) {
F_15 ( L_69 , V_254 -> V_358 ) ;
return - V_238 ;
}
F_25 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_195 ;
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 )
continue;
if ( ! V_12 -> V_63 || V_12 -> V_18 ) {
if ( V_254 -> V_358 == V_361 &&
V_4 -> V_17 [ V_10 ] -> V_59 ) {
V_31 = - V_365 ;
F_15 ( L_70 , V_10 ) ;
} else {
F_8 ( V_219 , L_70 , V_10 ) ;
}
continue;
}
V_195 = V_253 ( V_12 -> V_45 , V_254 ) ;
if ( V_195 ) {
if ( V_12 -> V_63 && ! V_31 )
V_31 = V_195 ;
continue;
}
if ( V_254 -> V_358 == V_361 ) {
V_356 += V_254 -> V_366 . V_367 ;
V_357 += V_254 -> V_366 . V_368 ;
}
}
F_29 ( V_2 ) ;
if ( V_254 -> V_358 == V_361 ) {
V_254 -> V_366 . V_367 = V_356 ;
V_254 -> V_366 . V_368 = V_357 ;
}
return V_31 ;
}
static int F_164 ( struct V_1 * V_2 , struct V_52 * exp ,
struct V_253 * V_254 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_31 = 0 ;
F_25 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( ! V_4 -> V_17 [ V_10 ] -> V_59 ) {
F_78 ( L_71 ,
V_10 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_63 ) {
F_15 ( L_72 , V_10 ) ;
V_31 = - V_185 ;
goto V_69;
}
}
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_195 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_59 )
continue;
V_195 = F_165 ( V_4 -> V_17 [ V_10 ] -> V_45 , V_254 ) ;
if ( V_195 && ! V_31 )
V_31 = V_195 ;
}
V_69:
F_29 ( V_2 ) ;
return V_31 ;
}
static int T_6 F_166 ( void )
{
struct V_119 V_120 = { NULL } ;
int V_31 ;
F_8 ( V_74 , L_73 , & V_369 ) ;
V_31 = F_167 ( V_369 ) ;
if ( V_31 )
return V_31 ;
V_370 = F_168 ( L_74 ,
sizeof( struct V_178 ) ,
0 , V_371 , NULL ) ;
if ( V_370 == NULL ) {
F_169 ( V_369 ) ;
return - V_100 ;
}
F_75 ( & V_120 ) ;
V_31 = F_170 ( & V_372 , NULL ,
V_373 , & V_374 ) ;
if ( V_31 ) {
F_171 ( V_370 ) ;
F_169 ( V_369 ) ;
}
return V_31 ;
}
static void F_172 ( void )
{
F_173 ( V_373 ) ;
F_171 ( V_370 ) ;
F_169 ( V_369 ) ;
}
