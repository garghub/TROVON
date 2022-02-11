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
if ( V_4 -> V_21 )
F_14 ( V_4 -> V_21 ) ;
} else {
F_4 ( & V_4 -> V_6 ) ;
}
}
int F_15 ( struct V_1 * V_2 , T_1 V_22 , int V_23 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_26 * V_27 ;
struct V_1 * V_28 ;
static struct V_26 V_29 = { L_2 } ;
struct V_30 * V_31 ;
int V_32 ;
if ( ! V_4 -> V_17 [ V_22 ] )
return - V_33 ;
V_27 = & V_4 -> V_17 [ V_22 ] -> V_34 ;
V_28 = V_4 -> V_17 [ V_22 ] -> V_35 ;
if ( ! V_28 -> V_36 ) {
F_16 ( L_3 , F_17 ( V_27 ) ) ;
return - V_33 ;
}
V_28 -> V_5 . V_37 . V_38 = V_4 -> V_39 ;
if ( V_25 && ( V_25 -> V_40 & V_41 ) )
V_25 -> V_42 = V_22 ;
V_31 = V_28 -> V_5 . V_37 . V_43 ;
if ( V_23 ) {
V_28 -> V_44 = 0 ;
F_18 ( V_31 ) ;
}
V_32 = F_19 ( V_28 , V_2 ) ;
if ( V_32 ) {
F_16 ( L_4 ,
F_17 ( V_27 ) , V_32 ) ;
return V_32 ;
}
if ( V_31 -> V_45 ) {
F_8 ( V_14 , L_5 ,
F_17 ( V_27 ) ) ;
return 0 ;
}
V_32 = F_20 ( NULL , & V_4 -> V_17 [ V_22 ] -> V_46 , V_28 ,
& V_29 , V_25 , NULL ) ;
if ( V_32 || ! V_4 -> V_17 [ V_22 ] -> V_46 ) {
F_16 ( L_6 ,
F_17 ( V_27 ) , V_32 ) ;
return - V_47 ;
}
V_4 -> V_17 [ V_22 ] -> V_18 = 0 ;
F_8 ( V_14 , L_7 , V_22 ,
F_17 ( V_27 ) , V_28 -> V_48 , V_23 ? L_8 : L_9 ) ;
if ( V_4 -> V_21 )
V_32 = F_21 ( V_4 -> V_21 , & V_28 -> V_49 ,
V_28 -> V_48 ) ;
return 0 ;
}
static int F_22 ( const struct V_50 * V_51 ,
struct V_52 * * exp , struct V_1 * V_2 ,
struct V_26 * V_53 , struct V_24 * V_25 ,
void * V_54 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
struct V_55 V_56 ;
int V_10 , V_32 ;
F_8 ( V_14 , L_10 , V_4 -> V_57 ) ;
V_32 = F_23 ( & V_56 , V_2 , V_53 ) ;
if ( V_32 )
return V_32 ;
* exp = F_24 ( & V_56 ) ;
V_4 -> V_57 ++ ;
F_25 ( V_4 -> V_57 == 1 ) ;
memset ( & V_4 -> V_58 , 0 , sizeof( V_4 -> V_58 ) ) ;
if ( V_25 )
V_4 -> V_58 = * V_25 ;
F_26 ( V_2 ) ;
V_4 -> V_21 = F_27 ( L_11 ,
& V_2 -> V_49 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 || F_28 ( & V_12 -> V_34 ) )
continue;
V_32 = F_15 ( V_2 , V_10 , V_12 -> V_59 , & V_4 -> V_58 ) ;
if ( V_32 ) {
F_16 ( L_12 ,
V_2 -> V_48 , V_10 , V_32 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_46 )
continue;
V_32 = F_29 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_46 -> V_60 ,
V_61 , ( void * ) & V_10 ) ;
if ( V_32 ) {
F_16 ( L_13 ,
V_2 -> V_48 , V_32 ) ;
}
}
F_30 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_1 * V_62 ;
int V_32 ;
V_62 = F_32 ( V_12 -> V_46 ) ;
F_8 ( V_14 , L_14 ,
V_2 -> V_48 , V_62 ? V_62 -> V_48 : L_15 ) ;
if ( V_12 -> V_63 ) {
V_12 -> V_63 = 0 ;
V_4 -> V_15 . V_64 -- ;
V_12 -> V_46 -> V_60 -> V_65 = 1 ;
}
if ( V_62 ) {
if ( V_4 -> V_21 )
F_33 ( V_4 -> V_21 ,
V_62 -> V_48 ) ;
V_62 -> V_66 = V_2 -> V_66 ;
V_62 -> V_67 = V_2 -> V_67 ;
V_62 -> V_44 = V_2 -> V_44 ;
}
F_19 ( V_62 , NULL ) ;
V_32 = F_34 ( V_12 -> V_46 ) ;
if ( V_32 ) {
F_16 ( L_16 ,
V_12 -> V_34 . V_68 , V_32 ) ;
V_32 = 0 ;
}
V_12 -> V_46 = NULL ;
return 0 ;
}
static int F_35 ( struct V_52 * exp )
{
struct V_1 * V_2 = F_32 ( exp ) ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_32 ;
if ( ! V_4 -> V_17 )
goto V_69;
V_4 -> V_57 -- ;
if ( V_4 -> V_57 != 0 ) {
F_16 ( L_17 , V_4 -> V_57 ) ;
goto V_69;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( V_4 -> V_17 [ V_10 ] && V_4 -> V_17 [ V_10 ] -> V_46 ) {
F_36 ( V_2 , V_10 , NULL , V_4 -> V_17 [ V_10 ] -> V_70 ) ;
}
}
F_30 ( V_2 ) ;
V_69:
V_32 = F_37 ( exp ) ;
return V_32 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_26 * V_68 ,
enum V_71 V_72 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
int V_22 , V_23 , V_73 ;
F_8 ( V_74 , L_18 ,
V_4 , V_68 -> V_68 , V_72 ) ;
F_26 ( V_2 ) ;
for ( V_22 = 0 ; V_22 < V_4 -> V_15 . V_16 ; V_22 ++ ) {
V_12 = V_4 -> V_17 [ V_22 ] ;
if ( ! V_12 )
continue;
if ( V_72 == V_75 && V_12 -> V_46 == NULL &&
F_39 ( V_68 , & V_12 -> V_34 ) ) {
struct V_26 V_29 = { L_2 } ;
F_20 ( NULL , & V_12 -> V_46 , V_12 -> V_35 ,
& V_29 , & V_4 -> V_58 , NULL ) ;
}
if ( ! V_12 -> V_46 )
continue;
F_8 ( V_74 , L_19 ,
V_22 , F_17 ( & V_12 -> V_34 ) ,
V_12 -> V_46 -> V_76 . V_77 ) ;
if ( F_39 ( V_68 , & V_12 -> V_34 ) )
break;
}
if ( V_22 == V_4 -> V_15 . V_16 ) {
V_22 = - V_33 ;
goto V_69;
}
if ( V_72 == V_78 || V_72 == V_75 ) {
V_23 = ( V_72 == V_75 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_22 ] -> V_59 == V_23 ) {
F_8 ( V_74 , L_20 ,
V_68 -> V_68 , V_23 ? L_8 : L_21 ) ;
} else {
V_4 -> V_17 [ V_22 ] -> V_59 = V_23 ;
F_8 ( V_14 , L_22 ,
V_23 ? L_8 : L_21 , F_17 ( V_68 ) ) ;
}
} else if ( V_72 == V_79 || V_72 == V_80 ) {
V_73 = ( V_72 == V_80 ) ? 1 : 0 ;
if ( V_4 -> V_17 [ V_22 ] -> V_63 == V_73 ) {
F_8 ( V_74 , L_23 ,
V_68 -> V_68 , V_73 ? L_8 : L_9 ) ;
goto V_69;
} else {
F_8 ( V_14 , L_24 ,
F_17 ( V_68 ) , V_73 ? L_8 : L_9 ) ;
}
V_4 -> V_17 [ V_22 ] -> V_63 = V_73 ;
if ( V_73 ) {
V_4 -> V_15 . V_64 ++ ;
V_4 -> V_17 [ V_22 ] -> V_46 -> V_60 -> V_65 = 0 ;
} else {
V_4 -> V_15 . V_64 -- ;
V_4 -> V_17 [ V_22 ] -> V_46 -> V_60 -> V_65 = 1 ;
}
} else {
F_16 ( L_25 , V_72 , V_68 -> V_68 ) ;
}
V_69:
F_30 ( V_2 ) ;
return V_22 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_1 * V_81 ,
enum V_71 V_72 , void * V_25 )
{
int V_32 = 0 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
F_40 ( & V_4 -> V_82 ) ;
if ( ! V_4 -> V_57 ) {
F_41 ( & V_4 -> V_82 ) ;
return V_32 ;
}
if ( V_72 == V_80 || V_72 == V_79 ||
V_72 == V_75 || V_72 == V_78 ) {
struct V_26 * V_68 ;
F_25 ( V_81 ) ;
if ( strcmp ( V_81 -> V_83 -> V_84 , V_85 ) ) {
F_41 ( & V_4 -> V_82 ) ;
F_16 ( L_26 ,
V_81 -> V_83 -> V_84 ,
V_81 -> V_48 ) ;
return - V_33 ;
}
V_68 = & V_81 -> V_5 . V_37 . V_86 ;
V_32 = F_38 ( V_2 , V_68 , V_72 ) ;
if ( V_32 < 0 ) {
F_41 ( & V_4 -> V_82 ) ;
F_16 ( L_27 , V_72 ,
F_17 ( V_68 ) , V_32 ) ;
return V_32 ;
}
V_25 = & V_32 ;
}
if ( V_81 ) {
V_32 = F_42 ( V_2 , V_81 , V_72 , V_25 ) ;
} else {
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_87 ;
V_25 = & V_10 ;
V_87 = ( V_72 == V_88 ) ||
( V_72 == V_89 ) ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_87 && ! V_4 -> V_17 [ V_10 ] -> V_63 )
continue;
V_32 = F_42 ( V_2 , V_4 -> V_17 [ V_10 ] -> V_35 ,
V_72 , V_25 ) ;
if ( V_32 ) {
F_16 ( L_28 ,
V_2 -> V_48 ,
V_2 -> V_90 -> V_48 ,
V_4 -> V_17 [ V_10 ] -> V_35 -> V_48 ,
V_32 ) ;
}
}
F_30 ( V_2 ) ;
}
F_41 ( & V_4 -> V_82 ) ;
return V_32 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_26 * V_91 ,
T_1 V_22 , int V_92 , int V_73 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
struct V_1 * V_28 ;
int V_32 ;
F_8 ( V_14 , L_29 ,
V_91 -> V_68 , V_22 , V_92 , V_73 ) ;
if ( V_92 <= 0 ) {
F_16 ( L_30 ,
V_91 -> V_68 , V_92 ) ;
return - V_33 ;
}
V_28 = F_44 ( V_91 , V_85 ,
& V_2 -> V_26 ) ;
if ( V_28 == NULL )
return - V_33 ;
F_2 ( & V_4 -> V_6 ) ;
if ( ( V_22 < V_4 -> V_93 ) && ( V_4 -> V_17 [ V_22 ] != NULL ) ) {
V_12 = V_4 -> V_17 [ V_22 ] ;
F_16 ( L_31 ,
F_17 ( & V_12 -> V_34 ) , V_22 ) ;
F_4 ( & V_4 -> V_6 ) ;
return - V_94 ;
}
if ( V_22 >= V_4 -> V_93 ) {
struct V_11 * * V_95 , * * V_96 = NULL ;
T_1 V_97 , V_98 = 0 ;
V_97 = F_45 ( T_1 , V_4 -> V_93 , 2 ) ;
while ( V_97 < V_22 + 1 )
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
V_32 = F_50 ( & V_4 -> V_20 , V_22 , V_4 -> V_93 ) ;
if ( V_32 ) {
F_4 ( & V_4 -> V_6 ) ;
F_48 ( V_12 ) ;
return V_32 ;
}
V_12 -> V_34 = * V_91 ;
V_12 -> V_35 = V_28 ;
V_12 -> V_70 = V_92 ;
V_12 -> V_101 = V_22 ;
V_12 -> V_59 = V_73 ;
V_4 -> V_17 [ V_22 ] = V_12 ;
if ( V_22 >= V_4 -> V_15 . V_16 )
V_4 -> V_15 . V_16 = V_22 + 1 ;
F_4 ( & V_4 -> V_6 ) ;
F_8 ( V_14 , L_33 ,
V_22 , V_12 -> V_70 , V_4 -> V_15 . V_16 ) ;
V_32 = F_51 ( V_2 , V_28 , V_102 , & V_22 ) ;
if ( V_4 -> V_57 == 0 ) {
return 0 ;
}
F_26 ( V_2 ) ;
V_32 = F_15 ( V_2 , V_22 , V_73 , & V_4 -> V_58 ) ;
if ( V_32 )
goto V_69;
if ( ! V_12 -> V_46 ) {
V_32 = 0 ;
goto V_69;
}
if ( V_4 -> V_103 != NULL ) {
V_32 = F_52 ( NULL , V_12 -> V_46 ,
sizeof( V_104 ) , V_104 ,
sizeof( struct V_105 ) , V_4 -> V_103 ,
NULL ) ;
if ( V_32 < 0 )
goto V_69;
}
V_32 = F_29 ( V_2 , V_12 -> V_46 -> V_60 ,
V_73 ? V_61 : V_79 ,
( void * ) & V_22 ) ;
V_69:
if ( V_32 ) {
F_16 ( L_34 , V_32 ,
F_17 ( & V_12 -> V_34 ) ) ;
F_36 ( V_2 , V_22 , NULL , 0 ) ;
}
F_30 ( V_2 ) ;
return V_32 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_22 ,
struct V_26 * V_91 , int V_92 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_106 = V_4 -> V_15 . V_16 ;
int V_32 = 0 ;
if ( V_22 >= V_106 ) {
F_16 ( L_35 ,
V_22 , V_106 ) ;
return - V_33 ;
}
F_53 ( & V_4 -> V_82 ) ;
F_26 ( V_2 ) ;
if ( ! V_4 -> V_17 [ V_22 ] ) {
F_16 ( L_36 , V_22 ) ;
V_32 = - V_33 ;
goto V_69;
}
if ( V_91 && ! F_39 ( V_91 , & V_4 -> V_17 [ V_22 ] -> V_34 ) ) {
F_16 ( L_37 ,
F_54 ( V_4 , V_22 ) , V_22 ,
F_17 ( V_91 ) ) ;
V_32 = - V_33 ;
goto V_69;
}
F_8 ( V_14 , L_38 ,
F_54 ( V_4 , V_22 ) , V_22 ,
V_4 -> V_17 [ V_22 ] -> V_70 , V_4 -> V_17 [ V_22 ] -> V_46 ,
V_4 -> V_17 [ V_22 ] -> V_63 ) ;
V_4 -> V_17 [ V_22 ] -> V_18 = 1 ;
V_4 -> V_8 ++ ;
V_69:
F_30 ( V_2 ) ;
F_55 ( & V_4 -> V_82 ) ;
return V_32 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_1 * V_62 ;
F_25 ( V_12 ) ;
F_25 ( V_12 -> V_18 ) ;
V_62 = F_32 ( V_12 -> V_46 ) ;
F_8 ( V_14 , L_39 ,
V_12 -> V_34 . V_68 ,
V_62 ? V_62 -> V_48 : L_40 ) ;
if ( V_12 -> V_46 )
F_31 ( V_2 , V_12 ) ;
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
int V_32 ;
if ( F_65 ( V_118 , 1 ) < 1 ) {
F_16 ( L_44 ) ;
return - V_33 ;
}
V_15 = (struct V_112 * ) F_66 ( V_118 , 1 ) ;
if ( sizeof( * V_15 ) > F_65 ( V_118 , 1 ) ) {
F_16 ( L_45 ,
( int ) sizeof( * V_15 ) , F_65 ( V_118 , 1 ) ) ;
return - V_33 ;
}
if ( V_15 -> V_121 != V_122 ) {
if ( V_15 -> V_121 == F_67 ( V_122 ) ) {
F_8 ( V_123 , L_46 ,
V_2 -> V_48 , V_15 ) ;
F_68 ( V_15 ) ;
} else {
F_16 ( L_47 ,
V_2 -> V_48 , V_15 -> V_121 ) ;
return - V_33 ;
}
}
F_63 ( V_15 ) ;
V_15 -> V_64 = 0 ;
V_4 -> V_15 = * V_15 ;
V_4 -> V_93 = 0 ;
F_69 ( & V_4 -> V_6 ) ;
F_70 ( & V_4 -> V_7 , 0 ) ;
V_4 -> V_39 = V_124 ;
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
V_32 = F_74 ( & V_4 -> V_20 , 0 ) ;
if ( V_32 )
goto V_69;
F_75 ( & V_120 ) ;
F_76 ( V_2 , V_120 . V_135 , V_120 . V_136 ) ;
V_32 = F_77 ( V_2 -> V_137 , L_49 ,
0444 , & V_138 , V_2 ) ;
if ( V_32 )
F_78 ( L_50 ) ;
V_4 -> V_139 = F_79 ( L_51 ,
V_2 -> V_137 ,
NULL , NULL ) ;
return 0 ;
V_69:
return V_32 ;
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
F_81 ( F_32 ( V_4 -> V_17 [ V_10 ] -> V_46 ) ,
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
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_4 -> V_17 [ V_10 ] -> V_63 ||
F_89 ( & V_4 -> V_7 ) )
F_16 ( L_53 ,
V_10 , V_4 -> V_8 ,
F_89 ( & V_4 -> V_7 ) ) ;
F_36 ( V_2 , V_10 , NULL , 0 ) ;
}
F_30 ( V_2 ) ;
F_48 ( V_4 -> V_17 ) ;
V_4 -> V_93 = 0 ;
}
return 0 ;
}
int F_90 ( struct V_1 * V_2 , struct V_117 * V_118 ,
T_1 * V_150 , int * V_151 )
{
struct V_26 V_26 ;
int V_152 ;
int V_32 = 0 ;
switch ( V_152 = V_118 -> V_153 ) {
case V_154 :
case V_155 :
case V_156 : {
T_1 V_22 ;
int V_92 ;
if ( F_65 ( V_118 , 1 ) > sizeof( V_26 . V_68 ) ) {
V_32 = - V_33 ;
goto V_69;
}
F_91 ( & V_26 , F_66 ( V_118 , 1 ) ) ;
V_32 = F_92 ( F_66 ( V_118 , 2 ) , 10 , V_150 ) ;
if ( V_32 < 0 )
goto V_69;
V_32 = F_92 ( F_66 ( V_118 , 3 ) , 10 , V_151 ) ;
if ( V_32 < 0 )
goto V_69;
V_22 = * V_150 ;
V_92 = * V_151 ;
if ( V_152 == V_154 )
V_32 = F_43 ( V_2 , & V_26 , V_22 , V_92 , 1 ) ;
else if ( V_152 == V_155 )
V_32 = F_43 ( V_2 , & V_26 , V_22 , V_92 , 0 ) ;
else
V_32 = F_36 ( V_2 , V_22 , & V_26 , V_92 ) ;
goto V_69;
}
case V_157 : {
struct V_119 V_120 = { NULL } ;
struct V_112 * V_15 = & ( V_2 -> V_5 . V_4 . V_15 ) ;
if ( ! V_15 ) {
V_32 = - V_33 ;
goto V_69;
}
F_75 ( & V_120 ) ;
V_32 = F_93 ( V_158 , V_120 . V_135 ,
V_118 , V_2 ) ;
if ( V_32 > 0 )
V_32 = 0 ;
goto V_69;
}
case V_159 :
case V_160 :
case V_161 :
case V_162 :
goto V_69;
default: {
F_16 ( L_54 , V_118 -> V_153 ) ;
V_32 = - V_33 ;
goto V_69;
}
}
V_69:
return V_32 ;
}
static int F_94 ( struct V_52 * exp , struct V_163 * V_164 ,
struct V_165 * * V_166 , struct V_167 * V_168 )
{
struct V_165 * V_169 , * V_170 ;
struct V_3 * V_4 = & exp -> V_60 -> V_5 . V_4 ;
unsigned V_171 ;
int V_32 , V_10 ;
F_25 ( V_164 -> V_172 & V_173 &&
V_164 -> V_174 & V_175 ) ;
V_169 = F_49 ( sizeof( * V_169 ) , V_99 ) ;
if ( ! V_169 )
return - V_100 ;
V_171 = V_164 -> V_176 ;
V_170 = * V_166 ;
if ( V_170 == NULL ) {
V_32 = - V_33 ;
goto V_69;
}
if ( V_171 >= V_4 -> V_15 . V_16 ||
! V_4 -> V_17 [ V_171 ] ) {
V_32 = - V_33 ;
goto V_69;
}
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
struct V_178 * V_179 = V_170 -> V_180 [ V_10 ] ;
if ( F_95 ( V_179 ) )
continue;
if ( V_179 -> V_181 == V_171 ) {
if ( F_96 ( & V_179 -> V_182 ) != F_96 ( & V_164 -> V_183 ) ) {
V_32 = - V_33 ;
goto V_69;
}
break;
}
}
if ( V_10 == V_170 -> V_177 ) {
V_32 = - V_33 ;
goto V_69;
}
V_32 = F_97 ( NULL , V_4 -> V_17 [ V_171 ] -> V_46 ,
V_164 , & V_169 , V_168 ) ;
V_69:
F_48 ( V_169 ) ;
return V_32 ;
}
static int F_98 ( const struct V_50 * V_51 , struct V_52 * exp ,
struct V_163 * V_164 , struct V_165 * * V_166 ,
struct V_167 * V_168 )
{
struct V_3 * V_4 ;
int V_32 = 0 ;
F_25 ( V_166 != NULL ) ;
if ( exp == NULL )
return - V_33 ;
if ( ( V_164 -> V_172 & V_173 ) &&
V_164 -> V_174 == V_184 ) {
F_99 () ;
}
V_4 = & exp -> V_60 -> V_5 . V_4 ;
if ( ! V_4 -> V_15 . V_64 )
return - V_185 ;
F_26 ( exp -> V_60 ) ;
if ( ( V_164 -> V_172 & V_173 ) &&
( V_164 -> V_174 & V_175 ) ) {
V_32 = F_94 ( exp , V_164 , V_166 , V_168 ) ;
}
F_30 ( exp -> V_60 ) ;
return V_32 ;
}
static int F_100 ( const struct V_50 * V_51 , struct V_52 * exp ,
struct V_163 * V_186 , struct V_165 * V_170 ,
struct V_167 * V_168 , struct V_52 * V_187 )
{
struct V_188 * V_189 ;
struct V_190 V_191 ;
struct V_192 * V_193 ;
struct V_143 * V_144 ;
struct V_3 * V_4 ;
int V_32 = 0 , V_194 = 0 ;
F_101 ( V_170 ) ;
if ( ! exp || ! exp -> V_60 )
return - V_47 ;
if ( V_186 -> V_172 & V_195 ) {
F_25 ( V_168 ) ;
F_25 ( V_168 -> V_196 ) ;
}
V_4 = & exp -> V_60 -> V_5 . V_4 ;
F_26 ( exp -> V_60 ) ;
V_32 = F_102 ( exp , & V_191 , V_186 , V_170 , V_168 , & V_189 ) ;
if ( V_32 )
goto V_69;
F_103 (pos, &set->set_list) {
V_193 = F_84 ( V_144 , struct V_192 , V_197 ) ;
if ( V_186 -> V_172 & V_195 )
V_168 -> V_196 = V_189 -> V_198 + V_193 -> V_199 ;
V_194 = F_104 ( V_51 , V_4 -> V_17 [ V_193 -> V_200 ] -> V_46 ,
V_193 -> V_201 . V_202 , NULL , V_168 , NULL ) ;
V_194 = F_105 ( V_189 , V_193 , V_194 ) ;
if ( V_194 ) {
F_16 ( L_55 V_203 L_56
V_203 L_57 ,
exp -> V_60 -> V_48 , F_106 ( & V_186 -> V_183 ) ,
F_106 ( & V_193 -> V_201 . V_202 -> V_183 ) ,
V_193 -> V_200 , V_194 ) ;
if ( ! V_32 )
V_32 = V_194 ;
}
}
if ( V_32 == 0 ) {
F_25 ( F_107 ( V_170 -> V_204 ) != NULL ) ;
V_32 = F_107 ( V_170 -> V_204 ) -> F_108 ( V_170 , V_186 , V_187 ) ;
}
V_194 = F_109 ( V_189 ) ;
V_69:
F_30 ( exp -> V_60 ) ;
return V_32 ? V_32 : V_194 ;
}
static int F_110 ( struct V_205 * V_206 ,
void * V_25 , int V_32 )
{
struct V_188 * V_207 = (struct V_188 * ) V_25 ;
int V_194 ;
if ( V_32 )
F_70 ( & V_207 -> V_208 , 0 ) ;
V_194 = F_111 ( V_207 ) ;
return V_32 ? V_32 : V_194 ;
}
static int F_112 ( struct V_52 * exp , struct V_190 * V_191 ,
struct V_205 * V_206 )
{
struct V_188 * V_207 ;
struct V_3 * V_4 ;
struct V_143 * V_144 ;
struct V_192 * V_193 ;
int V_32 = 0 , V_194 ;
F_25 ( V_191 ) ;
F_101 ( V_191 -> V_209 ) ;
if ( ! exp || ! exp -> V_60 )
return - V_47 ;
V_4 = & exp -> V_60 -> V_5 . V_4 ;
V_32 = F_113 ( exp , V_191 , & V_207 ) ;
if ( V_32 )
return V_32 ;
F_8 ( V_74 , L_58 V_203 L_59 ,
F_106 ( & V_191 -> V_209 -> V_210 ) , V_191 -> V_209 -> V_177 ,
V_191 -> V_209 -> V_211 ) ;
F_103 (pos, &lovset->set_list) {
V_193 = F_84 ( V_144 , struct V_192 , V_197 ) ;
F_8 ( V_74 , L_58 V_203 L_60 V_203 L_61 ,
F_106 ( & V_191 -> V_202 -> V_183 ) , V_193 -> V_199 ,
F_106 ( & V_193 -> V_201 . V_202 -> V_183 ) , V_193 -> V_200 ) ;
V_32 = F_114 ( V_4 -> V_17 [ V_193 -> V_200 ] -> V_46 ,
& V_193 -> V_201 , V_206 ) ;
if ( V_32 ) {
F_16 ( L_62 V_203 L_63
V_203 L_57 ,
exp -> V_60 -> V_48 ,
F_106 ( & V_191 -> V_202 -> V_183 ) ,
F_106 ( & V_193 -> V_201 . V_202 -> V_183 ) ,
V_193 -> V_200 , V_32 ) ;
goto V_69;
}
}
if ( ! F_115 ( & V_206 -> V_212 ) ) {
F_25 ( V_32 == 0 ) ;
F_25 ( V_206 -> V_213 == NULL ) ;
V_206 -> V_213 = F_110 ;
V_206 -> V_214 = ( void * ) V_207 ;
return V_32 ;
}
V_69:
if ( V_32 )
F_70 ( & V_207 -> V_208 , 0 ) ;
V_194 = F_111 ( V_207 ) ;
return V_32 ? V_32 : V_194 ;
}
static int F_116 ( struct V_205 * V_206 ,
void * V_25 , int V_32 )
{
struct V_188 * V_207 = (struct V_188 * ) V_25 ;
int V_194 ;
if ( V_32 )
F_70 ( & V_207 -> V_208 , 0 ) ;
V_194 = F_117 ( V_207 ) ;
return V_32 ? V_32 : V_194 ;
}
static int F_118 ( struct V_52 * exp , struct V_190 * V_191 ,
struct V_167 * V_168 ,
struct V_205 * V_206 )
{
struct V_188 * V_189 ;
struct V_192 * V_193 ;
struct V_143 * V_144 ;
struct V_3 * V_4 ;
int V_32 = 0 ;
F_25 ( V_191 ) ;
F_101 ( V_191 -> V_209 ) ;
if ( V_191 -> V_202 -> V_172 & V_195 ) {
F_25 ( V_168 ) ;
F_25 ( V_168 -> V_196 ) ;
}
if ( ! exp || ! exp -> V_60 )
return - V_47 ;
V_4 = & exp -> V_60 -> V_5 . V_4 ;
V_32 = F_119 ( exp , V_191 , V_168 , & V_189 ) ;
if ( V_32 )
return V_32 ;
F_8 ( V_74 , L_58 V_203 L_59 ,
F_106 ( & V_191 -> V_209 -> V_210 ) ,
V_191 -> V_209 -> V_177 ,
V_191 -> V_209 -> V_211 ) ;
F_103 (pos, &set->set_list) {
V_193 = F_84 ( V_144 , struct V_192 , V_197 ) ;
if ( V_191 -> V_202 -> V_172 & V_195 )
V_168 -> V_196 = V_189 -> V_198 + V_193 -> V_199 ;
F_8 ( V_74 , L_58 V_203 L_60 V_203 L_61 ,
F_106 ( & V_191 -> V_202 -> V_183 ) , V_193 -> V_199 ,
F_106 ( & V_193 -> V_201 . V_202 -> V_183 ) , V_193 -> V_200 ) ;
V_32 = F_120 ( V_4 -> V_17 [ V_193 -> V_200 ] -> V_46 ,
& V_193 -> V_201 , V_168 , V_206 ) ;
if ( V_32 ) {
F_16 ( L_64 V_203 L_63
V_203 L_57 ,
F_106 ( & V_189 -> V_215 -> V_202 -> V_183 ) ,
F_106 ( & V_193 -> V_201 . V_202 -> V_183 ) ,
V_193 -> V_200 , V_32 ) ;
break;
}
}
if ( V_32 || ! V_206 || F_115 ( & V_206 -> V_212 ) ) {
int V_194 ;
if ( V_32 )
F_70 ( & V_189 -> V_208 , 0 ) ;
V_194 = F_117 ( V_189 ) ;
return V_32 ? V_32 : V_194 ;
}
F_25 ( V_206 -> V_213 == NULL ) ;
V_206 -> V_213 = F_116 ;
V_206 -> V_214 = ( void * ) V_189 ;
return 0 ;
}
static int F_121 ( struct V_52 * exp ,
struct V_165 * V_170 , T_3 V_216 ,
void * V_25 )
{
struct V_3 * V_4 ;
int V_32 = 0 , V_10 ;
F_101 ( V_170 ) ;
if ( ! exp || ! exp -> V_60 )
return - V_47 ;
V_4 = & exp -> V_60 -> V_5 . V_4 ;
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
struct V_165 V_217 ;
struct V_178 * V_179 = V_170 -> V_180 [ V_10 ] ;
if ( F_95 ( V_179 ) )
continue;
if ( ! V_4 -> V_17 [ V_179 -> V_181 ] ) {
F_8 ( V_218 , L_65 , V_179 -> V_181 ) ;
continue;
}
V_217 . V_210 = V_179 -> V_182 ;
V_217 . V_177 = 0 ;
V_32 = F_122 ( V_4 -> V_17 [ V_179 -> V_181 ] -> V_46 ,
& V_217 , V_216 , V_25 ) ;
if ( V_32 != 0 )
return V_32 ;
}
return V_32 ;
}
int F_123 ( struct V_205 * V_206 , void * V_25 , int V_32 )
{
struct V_188 * V_207 = (struct V_188 * ) V_25 ;
int V_194 ;
if ( V_32 )
F_70 ( & V_207 -> V_208 , 0 ) ;
V_194 = F_124 ( V_207 ) ;
return V_32 ? V_32 : V_194 ;
}
static int F_125 ( struct V_52 * exp , struct V_190 * V_191 ,
T_2 V_219 , struct V_205 * V_206 )
{
struct V_1 * V_2 = F_32 ( exp ) ;
struct V_188 * V_189 ;
struct V_192 * V_193 ;
struct V_143 * V_144 ;
struct V_3 * V_4 ;
int V_32 = 0 ;
F_25 ( V_191 != NULL ) ;
F_25 ( V_191 -> V_220 != NULL ) ;
V_4 = & V_2 -> V_5 . V_4 ;
V_32 = F_126 ( V_2 , V_191 , & V_189 ) ;
if ( V_32 )
return V_32 ;
F_103 (pos, &set->set_list) {
V_193 = F_84 ( V_144 , struct V_192 , V_197 ) ;
V_32 = F_127 ( V_4 -> V_17 [ V_193 -> V_200 ] -> V_46 ,
& V_193 -> V_201 , V_219 , V_206 ) ;
if ( V_32 )
break;
}
if ( V_32 || F_115 ( & V_206 -> V_212 ) ) {
int V_194 ;
if ( V_32 )
F_70 ( & V_189 -> V_208 , 0 ) ;
V_194 = F_124 ( V_189 ) ;
return V_32 ? V_32 : V_194 ;
}
F_25 ( V_206 -> V_213 == NULL ) ;
V_206 -> V_213 = F_123 ;
V_206 -> V_214 = ( void * ) V_189 ;
return 0 ;
}
static int F_128 ( const struct V_50 * V_51 , struct V_52 * exp ,
struct V_221 * V_222 , T_2 V_219 , T_1 V_223 )
{
struct V_205 * V_189 = NULL ;
struct V_190 V_191 = { } ;
int V_32 = 0 ;
V_189 = F_129 () ;
if ( V_189 == NULL )
return - V_100 ;
V_191 . V_220 = V_222 ;
V_191 . V_224 = V_223 ;
V_32 = F_125 ( exp , & V_191 , V_219 , V_189 ) ;
if ( V_32 == 0 )
V_32 = F_130 ( V_189 ) ;
F_131 ( V_189 ) ;
return V_32 ;
}
static int F_132 ( unsigned int V_152 , struct V_52 * exp , int V_225 ,
void * V_226 , void * V_227 )
{
struct V_1 * V_228 = F_32 ( exp ) ;
struct V_3 * V_4 = & V_228 -> V_5 . V_4 ;
int V_10 = 0 , V_32 = 0 , V_106 = V_4 -> V_15 . V_16 ;
struct V_26 * V_91 ;
switch ( V_152 ) {
case V_229 : {
struct V_230 * V_25 = V_226 ;
struct V_1 * V_62 ;
struct V_221 V_231 = { 0 } ;
T_1 V_22 ;
T_1 V_223 ;
memcpy ( & V_22 , V_25 -> V_232 , sizeof( T_1 ) ) ;
if ( V_22 >= V_106 )
return - V_47 ;
if ( ! V_4 -> V_17 [ V_22 ] )
return - V_233 ;
if ( ! V_4 -> V_17 [ V_22 ] -> V_63 )
return - V_234 ;
V_62 = F_32 ( V_4 -> V_17 [ V_22 ] -> V_46 ) ;
if ( ! V_62 )
return - V_33 ;
if ( F_133 ( V_25 -> V_235 , F_134 ( V_62 ) ,
F_135 ( ( int ) V_25 -> V_236 ,
( int ) sizeof( struct V_26 ) ) ) )
return - V_237 ;
V_223 = V_227 ? * ( T_1 * ) V_227 : 0 ;
V_32 = V_221 ( NULL , V_4 -> V_17 [ V_22 ] -> V_46 , & V_231 ,
F_136 ( - V_238 ) ,
V_223 ) ;
if ( V_32 )
return V_32 ;
if ( F_133 ( V_25 -> V_239 , & V_231 ,
F_135 ( ( int ) V_25 -> V_240 ,
( int ) sizeof( V_231 ) ) ) )
return - V_237 ;
break;
}
case V_241 : {
struct V_230 * V_25 ;
struct V_112 * V_15 ;
char * V_242 = NULL ;
T_1 * V_151 ;
V_225 = 0 ;
if ( F_137 ( & V_242 , & V_225 , V_227 ) )
return - V_33 ;
V_25 = (struct V_230 * ) V_242 ;
if ( sizeof( * V_15 ) > V_25 -> V_243 ) {
F_138 ( V_242 , V_225 ) ;
return - V_33 ;
}
if ( sizeof( V_91 -> V_68 ) * V_106 > V_25 -> V_244 ) {
F_138 ( V_242 , V_225 ) ;
return - V_33 ;
}
if ( sizeof( T_1 ) * V_106 > V_25 -> V_245 ) {
F_138 ( V_242 , V_225 ) ;
return - V_33 ;
}
V_15 = (struct V_112 * ) V_25 -> V_246 ;
memcpy ( V_15 , & ( V_4 -> V_15 ) , sizeof( * V_15 ) ) ;
V_91 = (struct V_26 * ) V_25 -> V_232 ;
V_151 = ( T_1 * ) V_25 -> V_247 ;
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ , V_91 ++ , V_151 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
* V_91 = V_4 -> V_17 [ V_10 ] -> V_34 ;
* V_151 = V_4 -> V_17 [ V_10 ] -> V_70 ;
}
if ( F_133 ( V_227 , V_242 , V_225 ) )
V_32 = - V_237 ;
F_138 ( V_242 , V_225 ) ;
break;
}
case V_248 :
V_32 = F_139 ( exp , V_226 , V_227 ) ;
break;
case V_249 : {
struct V_250 * V_251 = V_226 ;
struct V_11 * V_12 = NULL ;
struct V_252 * V_253 ;
if ( V_251 -> V_254 == V_255 ) {
if ( V_106 <= V_251 -> V_256 )
return - V_33 ;
V_12 = V_4 -> V_17 [ V_251 -> V_256 ] ;
if ( ! V_12 || ! V_12 -> V_46 )
return - V_33 ;
} else if ( V_251 -> V_254 == V_257 ) {
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 ||
! F_39 ( & V_12 -> V_34 ,
& V_251 -> V_26 ) )
continue;
if ( V_12 -> V_46 == NULL )
return - V_33 ;
break;
}
} else {
return - V_33 ;
}
if ( V_10 >= V_106 )
return - V_233 ;
F_25 ( V_12 && V_12 -> V_46 ) ;
V_253 = F_49 ( sizeof( * V_253 ) , V_99 ) ;
if ( ! V_253 )
return - V_100 ;
F_140 ( V_253 , V_251 ) ;
V_32 = V_252 ( V_12 -> V_46 , V_253 ) ;
if ( V_32 == 0 ) {
F_140 ( V_251 , V_253 ) ;
V_251 -> V_254 = V_255 ;
V_251 -> V_26 = V_12 -> V_34 ;
}
F_48 ( V_253 ) ;
break;
}
default: {
int V_189 = 0 ;
if ( V_106 == 0 )
return - V_258 ;
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ ) {
int V_194 ;
struct V_1 * V_62 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_46 )
continue;
V_62 = F_32 ( V_4 -> V_17 [ V_10 ] -> V_46 ) ;
V_62 -> V_66 = V_228 -> V_66 ;
V_194 = F_141 ( V_152 , V_4 -> V_17 [ V_10 ] -> V_46 ,
V_225 , V_226 , V_227 ) ;
if ( V_194 == - V_234 && V_152 == V_259 ) {
return V_194 ;
} else if ( V_194 ) {
if ( V_4 -> V_17 [ V_10 ] -> V_63 ) {
F_8 ( V_194 == - V_258 ?
V_260 : V_261 ,
L_66 ,
F_54 ( V_4 , V_10 ) ,
V_10 , V_152 , V_194 ) ;
if ( ! V_32 )
V_32 = V_194 ;
}
} else {
V_189 = 1 ;
}
}
if ( ! V_189 && ! V_32 )
V_32 = - V_185 ;
}
}
return V_32 ;
}
static T_4 F_142 ( struct V_262 * V_263 ,
struct V_165 * V_170 , T_4 V_264 ,
T_4 V_265 , int * V_266 )
{
T_4 V_267 = V_263 -> V_268 [ 0 ] . V_269 ;
T_4 V_270 , V_271 ;
T_4 V_272 ;
int V_273 = - 1 , V_10 ;
if ( V_263 -> V_274 == 0 ||
V_263 -> V_268 [ 0 ] . V_269 == 0 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
struct V_178 * V_191 = V_170 -> V_180 [ V_10 ] ;
if ( F_95 ( V_191 ) )
continue;
if ( V_191 -> V_181 == V_263 -> V_268 [ 0 ] . V_275 ) {
V_273 = V_10 ;
break;
}
}
if ( V_273 == - 1 )
return - V_33 ;
if ( ( F_143 ( V_170 , V_273 , V_264 , V_265 ,
& V_270 , & V_271 ) ) != 0 &&
V_267 < V_271 ) {
V_272 = V_267 ;
* V_266 = V_273 ;
} else {
V_272 = 0 ;
* V_266 = ( V_273 + 1 ) % V_170 -> V_177 ;
}
return V_272 ;
}
static int F_144 ( struct V_165 * V_170 , T_4 V_264 ,
T_4 V_265 , int V_266 ,
int * V_276 )
{
int V_277 ;
T_4 V_278 , V_279 ;
int V_10 , V_280 ;
if ( V_265 - V_264 > V_170 -> V_211 * V_170 -> V_177 ) {
V_277 = V_266 < 1 ? V_170 -> V_177 - 1 :
V_266 - 1 ;
* V_276 = V_170 -> V_177 ;
} else {
for ( V_280 = 0 , V_10 = V_266 ; V_280 < V_170 -> V_177 ;
V_10 = ( V_10 + 1 ) % V_170 -> V_177 , V_280 ++ ) {
if ( ( F_143 ( V_170 , V_10 , V_264 , V_265 ,
& V_278 , & V_279 ) ) == 0 )
break;
}
* V_276 = V_280 ;
V_277 = ( V_266 + V_280 - 1 ) % V_170 -> V_177 ;
}
return V_277 ;
}
static void F_145 ( struct V_262 * V_263 ,
struct V_281 * V_282 ,
int V_283 , unsigned int V_284 ,
int V_285 )
{
char * V_286 ;
int V_287 ;
for ( V_287 = 0 ; V_287 < V_284 ; V_287 ++ ) {
V_282 [ V_287 ] . V_275 = V_283 ;
V_282 [ V_287 ] . V_288 |= V_289 ;
}
V_286 = ( char * ) V_263 + F_146 ( V_285 ) ;
memcpy ( V_286 , V_282 , V_284 * sizeof( struct V_281 ) ) ;
}
static int F_147 ( struct V_3 * V_4 , T_1 V_290 , void * V_291 ,
T_1 * V_292 , void * V_107 , struct V_165 * V_170 )
{
struct V_293 * V_294 = V_291 ;
struct V_262 * V_263 = V_107 ;
struct V_262 * V_295 = NULL ;
struct V_281 * V_282 ;
int V_296 ;
unsigned int V_297 = 0 ;
int V_283 = 0 , V_298 , V_266 ;
T_4 V_264 , V_265 , V_299 , V_272 ;
T_4 V_300 ;
int V_285 = 0 , V_32 = 0 , V_10 ;
int V_301 = 0 ;
int V_302 = 0 ;
int V_277 ;
int V_303 = 0 , V_304 = 0 , V_276 ;
unsigned int V_305 = V_306 ;
if ( ! F_148 ( V_170 ) ) {
V_32 = 0 ;
goto V_69;
}
if ( F_146 ( V_294 -> V_263 . V_274 ) < V_305 )
V_305 = F_146 ( V_294 -> V_263 . V_274 ) ;
V_295 = F_149 ( V_305 , V_99 ) ;
if ( V_295 == NULL ) {
V_32 = - V_100 ;
goto V_69;
}
V_282 = & V_295 -> V_268 [ 0 ] ;
V_296 = F_150 ( V_305 ) ;
memcpy ( V_263 , & V_294 -> V_263 , sizeof( * V_263 ) ) ;
V_264 = V_263 -> V_264 ;
V_299 = V_263 -> V_299 ;
V_298 = V_266 = F_151 ( V_170 , V_264 ) ;
V_265 = ( V_299 == ~ 0ULL ? V_294 -> V_186 . V_307 :
V_264 + V_299 - 1 ) ;
if ( V_265 > V_294 -> V_186 . V_307 )
V_265 = V_294 -> V_186 . V_307 ;
V_277 = F_144 ( V_170 , V_264 , V_265 ,
V_298 , & V_276 ) ;
V_272 = F_142 ( V_263 , V_170 , V_264 ,
V_265 , & V_266 ) ;
if ( V_272 == - V_33 ) {
V_32 = - V_33 ;
goto V_69;
}
if ( F_146 ( V_263 -> V_274 ) > * V_292 )
V_263 -> V_274 = F_150 ( * V_292 ) ;
if ( V_263 -> V_274 == 0 ) {
V_297 = 1 ;
V_296 = 0 ;
}
for ( V_303 = V_266 , V_10 = 0 ; V_10 < V_276 ;
V_10 ++ , V_303 = ( V_303 + 1 ) % V_170 -> V_177 ) {
T_4 V_308 ;
T_4 V_309 ;
T_4 V_270 , V_271 , V_310 ;
unsigned int V_284 ;
V_304 = V_303 ;
if ( ( F_143 ( V_170 , V_303 , V_264 , V_265 ,
& V_270 , & V_310 ) ) == 0 )
continue;
if ( F_95 ( V_170 -> V_180 [ V_303 ] ) ) {
V_32 = - V_185 ;
goto V_69;
}
if ( V_272 != 0 && V_303 == V_266 )
V_270 = V_272 ;
if ( V_299 != ~ 0ULL ) {
if ( V_264 + V_299 < V_264 )
V_299 = ~ 0ULL - V_264 ;
V_271 = F_152 ( V_170 , V_264 + V_299 ,
V_303 ) ;
} else {
V_271 = ~ 0ULL ;
}
if ( V_270 == V_271 )
continue;
V_308 = V_310 - V_270 ;
V_295 -> V_299 = 0 ;
V_309 = 0 ;
V_301 = 0 ;
V_302 = 0 ;
do {
if ( V_297 == 0 ) {
if ( V_285 + V_296 >
V_263 -> V_274 )
V_296 = V_263 -> V_274 -
V_285 ;
}
V_270 += V_309 ;
V_295 -> V_299 = V_308 - V_309 ;
V_308 = V_295 -> V_299 ;
V_295 -> V_274 = V_296 ;
V_295 -> V_311 = 0 ;
V_295 -> V_312 = V_263 -> V_312 ;
V_294 -> V_186 . V_183 = V_170 -> V_180 [ V_303 ] -> V_182 ;
V_283 = V_170 -> V_180 [ V_303 ] -> V_181 ;
if ( V_283 < 0 ||
V_283 >= V_4 -> V_15 . V_16 ) {
V_32 = - V_33 ;
goto V_69;
}
if ( ! V_4 -> V_17 [ V_283 ] -> V_63 ) {
V_295 -> V_312 |= V_313 ;
V_295 -> V_311 = 1 ;
V_282 [ 0 ] . V_269 = V_270 ;
V_282 [ 0 ] . V_314 = V_310 -
V_270 ;
V_282 [ 0 ] . V_288 |= V_315 ;
goto V_316;
}
V_295 -> V_264 = V_270 ;
V_295 -> V_312 &= ~ V_317 ;
memcpy ( & V_294 -> V_263 , V_295 , sizeof( * V_295 ) ) ;
* V_292 = F_146 ( V_295 -> V_274 ) ;
V_32 = F_153 ( NULL ,
V_4 -> V_17 [ V_283 ] -> V_46 ,
V_290 , V_291 , V_292 , V_295 , V_170 ) ;
if ( V_32 != 0 )
goto V_69;
V_316:
V_284 = V_295 -> V_311 ;
if ( V_284 == 0 ) {
V_302 = 1 ;
if ( V_304 == V_277 ) {
V_263 -> V_311 = 0 ;
goto V_318;
}
break;
}
if ( V_297 ) {
V_285 += V_284 ;
break;
}
V_309 = V_282 [ V_284 - 1 ] . V_269 -
V_270 + V_282 [ V_284 - 1 ] . V_314 ;
if ( V_308 <= V_309 )
V_302 = 1 ;
if ( V_282 [ V_284 - 1 ] . V_288 & V_313 )
V_282 [ V_284 - 1 ] . V_288 &=
~ V_313 ;
V_300 = F_154 ( V_170 ,
V_282 [ V_284 - 1 ] . V_269 +
V_282 [ V_284 - 1 ] . V_314 ,
V_303 ) ;
if ( V_300 >= V_294 -> V_186 . V_307 )
V_301 = 1 ;
F_145 ( V_263 , V_282 ,
V_283 , V_284 ,
V_285 ) ;
V_285 += V_284 ;
if ( V_285 >= V_263 -> V_274 )
goto V_318;
} while ( V_302 == 0 && V_301 == 0 );
if ( V_304 == V_277 )
goto V_318;
}
V_318:
if ( V_170 -> V_177 > 1 )
V_263 -> V_312 |= V_317 ;
if ( V_297 )
goto V_319;
if ( V_304 == V_277 ) {
if ( V_302 || V_301 )
V_263 -> V_268 [ V_285 - 1 ] . V_288 |=
V_313 ;
}
V_319:
V_263 -> V_311 = V_285 ;
V_69:
F_155 ( V_295 ) ;
return V_32 ;
}
static int F_156 ( const struct V_50 * V_51 , struct V_52 * exp ,
T_1 V_290 , void * V_291 , T_1 * V_292 , void * V_107 ,
struct V_165 * V_170 )
{
struct V_1 * V_228 = F_32 ( exp ) ;
struct V_3 * V_4 = & V_228 -> V_5 . V_4 ;
int V_10 , V_32 ;
if ( ! V_292 || ! V_107 )
return - V_237 ;
F_26 ( V_228 ) ;
if ( F_157 ( V_320 ) ) {
struct {
char V_321 [ 16 ] ;
struct V_322 * V_323 ;
} * V_25 = V_291 ;
struct V_324 * V_325 = & V_25 -> V_323 -> V_326 -> V_327 ;
struct V_178 * V_179 ;
T_1 * V_328 = V_107 ;
if ( * V_292 < sizeof( * V_328 ) ) {
V_32 = - V_237 ;
goto V_69;
}
* V_292 = sizeof( * V_328 ) ;
for ( V_10 = 0 ; V_10 < V_170 -> V_177 ; V_10 ++ ) {
V_179 = V_170 -> V_180 [ V_10 ] ;
if ( F_95 ( V_179 ) )
continue;
if ( ! V_4 -> V_17 [ V_179 -> V_181 ] )
continue;
if ( V_4 -> V_17 [ V_179 -> V_181 ] -> V_46 ==
V_25 -> V_323 -> V_329 &&
F_158 ( & V_179 -> V_182 , V_325 ) ) {
* V_328 = V_10 ;
V_32 = 0 ;
goto V_69;
}
}
F_159 ( V_25 -> V_323 , L_67 ) ;
F_160 ( V_330 , V_170 ) ;
V_32 = - V_331 ;
goto V_69;
} else if ( F_157 ( V_332 ) ) {
struct V_333 * V_334 = V_107 ;
T_1 V_335 = sizeof( T_4 ) ;
struct V_11 * V_12 ;
F_25 ( * V_292 == sizeof( struct V_333 ) ) ;
V_12 = V_4 -> V_17 [ V_334 -> V_336 ] ;
if ( ! V_12 || ! V_12 -> V_63 ) {
V_32 = - V_337 ;
goto V_69;
}
V_32 = F_153 ( V_51 , V_12 -> V_46 , V_290 , V_291 ,
& V_335 , V_334 -> V_25 , NULL ) ;
V_32 = 0 ;
goto V_69;
} else if ( F_157 ( V_338 ) ) {
struct V_112 * V_339 = V_107 ;
* V_339 = V_4 -> V_15 ;
V_32 = 0 ;
goto V_69;
} else if ( F_157 ( V_340 ) ) {
V_32 = F_147 ( V_4 , V_290 , V_291 , V_292 , V_107 , V_170 ) ;
goto V_69;
} else if ( F_157 ( V_341 ) ) {
struct V_11 * V_12 ;
T_2 V_171 = * ( ( T_2 * ) V_107 ) ;
F_25 ( * V_292 == sizeof( T_2 ) ) ;
F_25 ( V_171 < V_4 -> V_15 . V_16 ) ;
V_12 = V_4 -> V_17 [ V_171 ] ;
if ( ! V_12 || ! V_12 -> V_46 ) {
V_32 = - V_337 ;
goto V_69;
}
* ( ( T_2 * ) V_107 ) = F_161 ( V_12 -> V_46 ) ;
V_32 = 0 ;
goto V_69;
} else if ( F_157 ( V_342 ) ) {
* ( ( int * ) V_107 ) = V_4 -> V_15 . V_16 ;
V_32 = 0 ;
goto V_69;
}
V_32 = - V_33 ;
V_69:
F_30 ( V_228 ) ;
return V_32 ;
}
static int F_162 ( const struct V_50 * V_51 , struct V_52 * exp ,
T_5 V_290 , void * V_291 , T_5 V_292 ,
void * V_107 , struct V_205 * V_189 )
{
struct V_1 * V_228 = F_32 ( exp ) ;
struct V_3 * V_4 = & V_228 -> V_5 . V_4 ;
T_5 V_106 ;
int V_10 , V_32 = 0 , V_194 ;
struct V_11 * V_12 ;
unsigned V_343 , V_344 ,
V_345 , V_346 ;
unsigned V_347 = 0 , V_348 = 0 ;
V_343 = V_344 = V_345 = V_346 = 0 ;
if ( V_189 == NULL ) {
V_346 = 1 ;
V_189 = F_129 () ;
if ( ! V_189 )
return - V_100 ;
}
F_26 ( V_228 ) ;
V_106 = V_4 -> V_15 . V_16 ;
if ( F_157 ( V_349 ) ) {
V_106 = V_292 / sizeof( struct V_333 ) ;
V_292 = sizeof( T_4 ) ;
V_343 = sizeof( struct V_333 ) ;
V_345 = 1 ;
V_347 = 1 ;
} else if ( F_157 ( V_350 ) ) {
V_345 = 1 ;
} else if ( F_157 ( V_351 ) ) {
} else if ( F_157 ( V_352 ) ) {
V_348 = 1 ;
} else if ( F_157 ( V_104 ) ) {
F_25 ( V_4 -> V_103 == NULL ) ;
V_4 -> V_103 = V_107 ;
V_345 = 1 ;
}
for ( V_10 = 0 ; V_10 < V_106 ; V_10 ++ , V_107 = ( char * ) V_107 + V_343 ) {
if ( V_347 )
V_12 = V_4 -> V_17 [ ( ( struct V_333 * )val )->idx];
void F_163 ( struct V_165 * V_353 )
__releases( &md->lsm_lock
static int F_164 ( struct V_1 * V_2 , struct V_52 * exp ,
struct V_252 * V_253 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
T_2 V_354 = 0 ;
T_2 V_355 = 0 ;
int V_10 , V_32 = 0 ;
if ( V_253 -> V_356 != V_357 &&
V_253 -> V_356 != V_358 &&
V_253 -> V_356 != V_359 &&
V_253 -> V_356 != V_360 &&
V_253 -> V_356 != V_361 &&
V_253 -> V_356 != V_362 ) {
F_16 ( L_68 , V_253 -> V_356 ) ;
return - V_237 ;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_194 ;
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 )
continue;
if ( ! V_12 -> V_63 || V_12 -> V_18 ) {
if ( V_253 -> V_356 == V_359 &&
V_4 -> V_17 [ V_10 ] -> V_59 ) {
V_32 = - V_363 ;
F_16 ( L_69 , V_10 ) ;
} else {
F_8 ( V_218 , L_69 , V_10 ) ;
}
continue;
}
V_194 = V_252 ( V_12 -> V_46 , V_253 ) ;
if ( V_194 ) {
if ( V_12 -> V_63 && ! V_32 )
V_32 = V_194 ;
continue;
}
if ( V_253 -> V_356 == V_359 ) {
V_354 += V_253 -> V_364 . V_365 ;
V_355 += V_253 -> V_364 . V_366 ;
}
}
F_30 ( V_2 ) ;
if ( V_253 -> V_356 == V_359 ) {
V_253 -> V_364 . V_365 = V_354 ;
V_253 -> V_364 . V_366 = V_355 ;
}
return V_32 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_52 * exp ,
struct V_252 * V_253 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_10 , V_32 = 0 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( ! V_4 -> V_17 [ V_10 ] -> V_59 ) {
F_78 ( L_70 ,
V_10 ) ;
continue;
}
if ( ! V_4 -> V_17 [ V_10 ] -> V_63 ) {
F_16 ( L_71 , V_10 ) ;
V_32 = - V_185 ;
goto V_69;
}
}
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_194 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_59 )
continue;
V_194 = F_166 ( V_4 -> V_17 [ V_10 ] -> V_46 , V_253 ) ;
if ( V_194 && ! V_32 )
V_32 = V_194 ;
}
V_69:
F_30 ( V_2 ) ;
return V_32 ;
}
static int T_6 F_167 ( void )
{
struct V_119 V_120 = { NULL } ;
int V_32 ;
F_8 ( V_74 , L_72 , & V_367 ) ;
V_32 = F_168 ( V_367 ) ;
if ( V_32 )
return V_32 ;
V_368 = F_169 ( L_73 ,
sizeof( struct V_178 ) ,
0 , V_369 , NULL ) ;
if ( V_368 == NULL ) {
F_170 ( V_367 ) ;
return - V_100 ;
}
F_75 ( & V_120 ) ;
V_32 = F_171 ( & V_370 , NULL ,
V_371 , & V_372 ) ;
if ( V_32 ) {
F_172 ( V_368 ) ;
F_170 ( V_367 ) ;
}
return V_32 ;
}
static void F_173 ( void )
{
F_174 ( V_371 ) ;
F_172 ( V_368 ) ;
F_170 ( V_367 ) ;
}
