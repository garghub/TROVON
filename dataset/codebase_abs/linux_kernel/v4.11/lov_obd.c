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
if ( V_72 == V_75 && ! V_12 -> V_46 &&
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
}
F_8 ( V_14 , L_24 ,
F_17 ( V_68 ) , V_73 ? L_8 : L_9 ) ;
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
if ( ! V_28 )
return - V_33 ;
F_2 ( & V_4 -> V_6 ) ;
if ( ( V_22 < V_4 -> V_93 ) && V_4 -> V_17 [ V_22 ] ) {
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
if ( ! V_95 ) {
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
if ( V_4 -> V_102 ) {
V_32 = F_51 ( NULL , V_12 -> V_46 ,
sizeof( V_103 ) , V_103 ,
sizeof( struct V_104 ) ,
V_4 -> V_102 , NULL ) ;
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
int V_105 = V_4 -> V_15 . V_16 ;
int V_32 = 0 ;
if ( V_22 >= V_105 ) {
F_16 ( L_35 ,
V_22 , V_105 ) ;
return - V_33 ;
}
F_52 ( & V_4 -> V_82 ) ;
F_26 ( V_2 ) ;
if ( ! V_4 -> V_17 [ V_22 ] ) {
F_16 ( L_36 , V_22 ) ;
V_32 = - V_33 ;
goto V_69;
}
if ( V_91 && ! F_39 ( V_91 , & V_4 -> V_17 [ V_22 ] -> V_34 ) ) {
F_16 ( L_37 ,
F_53 ( V_4 , V_22 ) , V_22 ,
F_17 ( V_91 ) ) ;
V_32 = - V_33 ;
goto V_69;
}
F_8 ( V_14 , L_38 ,
F_53 ( V_4 , V_22 ) , V_22 ,
V_4 -> V_17 [ V_22 ] -> V_70 , V_4 -> V_17 [ V_22 ] -> V_46 ,
V_4 -> V_17 [ V_22 ] -> V_63 ) ;
V_4 -> V_17 [ V_22 ] -> V_18 = 1 ;
V_4 -> V_8 ++ ;
V_69:
F_30 ( V_2 ) ;
F_54 ( & V_4 -> V_82 ) ;
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
F_55 ( V_62 ) ;
}
void F_56 ( T_2 * V_106 )
{
if ( * V_106 < V_107 ) {
if ( * V_106 != 0 )
F_57 ( L_41 ,
V_108 ) ;
* V_106 = V_108 ;
} else if ( * V_106 & ( V_107 - 1 ) ) {
* V_106 &= ~ ( V_107 - 1 ) ;
F_58 ( L_42 ,
* V_106 , V_107 ) ;
}
}
void F_59 ( T_1 * V_106 )
{
if ( * V_106 == 0 )
* V_106 = 1 ;
}
void F_60 ( T_1 * V_106 )
{
if ( ( * V_106 != 0 ) && ( * V_106 != V_109 ) ) {
F_58 ( L_43 , * V_106 ) ;
* V_106 = 0 ;
}
}
void F_61 ( T_1 * V_106 )
{
if ( * V_106 == 0 )
* V_106 = V_110 ;
}
void F_62 ( struct V_111 * V_15 )
{
F_56 ( & V_15 -> V_112 ) ;
F_59 ( & V_15 -> V_113 ) ;
F_60 ( & V_15 -> V_114 ) ;
F_61 ( & V_15 -> V_115 ) ;
}
int F_63 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
struct V_118 V_119 = { NULL } ;
struct V_111 * V_15 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_32 ;
if ( F_64 ( V_117 , 1 ) < 1 ) {
F_16 ( L_44 ) ;
return - V_33 ;
}
V_15 = (struct V_111 * ) F_65 ( V_117 , 1 ) ;
if ( sizeof( * V_15 ) > F_64 ( V_117 , 1 ) ) {
F_16 ( L_45 ,
( int ) sizeof( * V_15 ) , F_64 ( V_117 , 1 ) ) ;
return - V_33 ;
}
if ( V_15 -> V_120 != V_121 ) {
if ( V_15 -> V_120 == F_66 ( V_121 ) ) {
F_8 ( V_122 , L_46 ,
V_2 -> V_48 , V_15 ) ;
F_67 ( V_15 ) ;
} else {
F_16 ( L_47 ,
V_2 -> V_48 , V_15 -> V_120 ) ;
return - V_33 ;
}
}
F_62 ( V_15 ) ;
V_15 -> V_64 = 0 ;
V_4 -> V_15 = * V_15 ;
V_4 -> V_93 = 0 ;
F_68 ( & V_4 -> V_6 ) ;
F_69 ( & V_4 -> V_7 , 0 ) ;
V_4 -> V_39 = V_123 ;
F_70 ( & V_4 -> V_82 ) ;
V_4 -> V_124 = F_71 ( L_48 , V_125 ,
V_126 ,
V_127 , 0 ,
V_128 ,
V_129 ,
& V_130 ,
V_131 ) ;
F_72 ( & V_4 -> V_132 ) ;
V_4 -> V_133 = 0 ;
V_32 = F_73 ( & V_4 -> V_20 , 0 ) ;
if ( V_32 )
goto V_69;
F_74 ( & V_119 ) ;
F_75 ( V_2 , V_119 . V_134 , V_119 . V_135 ) ;
V_32 = F_76 ( V_2 -> V_136 , L_49 ,
0444 , & V_137 , V_2 ) ;
if ( V_32 )
F_77 ( L_50 ) ;
V_4 -> V_138 = F_78 ( L_51 ,
V_2 -> V_136 ,
NULL , NULL ) ;
return 0 ;
V_69:
return V_32 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_139 * V_140 , * V_141 ;
struct V_142 * V_143 ;
F_80 (pos, tmp, &lov->lov_pool_list) {
V_143 = F_81 ( V_140 , struct V_142 , V_144 ) ;
F_8 ( V_74 , L_52 , V_143 ) ;
F_82 ( V_2 , V_143 -> V_145 ) ;
}
F_83 ( V_4 -> V_124 ) ;
F_84 ( & V_4 -> V_20 ) ;
F_85 ( V_2 ) ;
if ( V_4 -> V_17 ) {
int V_10 ;
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
if ( V_4 -> V_17 [ V_10 ] -> V_63 ||
F_86 ( & V_4 -> V_7 ) )
F_16 ( L_53 ,
V_10 , V_4 -> V_8 ,
F_86 ( & V_4 -> V_7 ) ) ;
F_36 ( V_2 , V_10 , NULL , 0 ) ;
}
F_30 ( V_2 ) ;
F_48 ( V_4 -> V_17 ) ;
V_4 -> V_93 = 0 ;
}
if ( V_4 -> V_102 ) {
F_87 ( V_4 -> V_102 ) ;
V_4 -> V_102 = NULL ;
}
return 0 ;
}
int F_88 ( struct V_1 * V_2 , struct V_116 * V_117 ,
T_1 * V_146 , int * V_147 )
{
struct V_26 V_26 ;
int V_148 ;
int V_32 = 0 ;
switch ( V_148 = V_117 -> V_149 ) {
case V_150 :
case V_151 :
case V_152 : {
T_1 V_22 ;
int V_92 ;
if ( F_64 ( V_117 , 1 ) > sizeof( V_26 . V_68 ) ) {
V_32 = - V_33 ;
goto V_69;
}
F_89 ( & V_26 , F_65 ( V_117 , 1 ) ) ;
V_32 = F_90 ( F_65 ( V_117 , 2 ) , 10 , V_146 ) ;
if ( V_32 < 0 )
goto V_69;
V_32 = F_90 ( F_65 ( V_117 , 3 ) , 10 , V_147 ) ;
if ( V_32 < 0 )
goto V_69;
V_22 = * V_146 ;
V_92 = * V_147 ;
if ( V_148 == V_150 )
V_32 = F_43 ( V_2 , & V_26 , V_22 , V_92 , 1 ) ;
else if ( V_148 == V_151 )
V_32 = F_43 ( V_2 , & V_26 , V_22 , V_92 , 0 ) ;
else
V_32 = F_36 ( V_2 , V_22 , & V_26 , V_92 ) ;
goto V_69;
}
case V_153 : {
struct V_118 V_119 = { NULL } ;
struct V_111 * V_15 = & V_2 -> V_5 . V_4 . V_15 ;
if ( ! V_15 ) {
V_32 = - V_33 ;
goto V_69;
}
F_74 ( & V_119 ) ;
V_32 = F_91 ( V_154 , V_119 . V_134 ,
V_117 , V_2 ) ;
if ( V_32 > 0 )
V_32 = 0 ;
goto V_69;
}
case V_155 :
case V_156 :
case V_157 :
case V_158 :
goto V_69;
default: {
F_16 ( L_54 , V_117 -> V_149 ) ;
V_32 = - V_33 ;
goto V_69;
}
}
V_69:
return V_32 ;
}
int F_92 ( struct V_159 * V_160 , void * V_25 , int V_32 )
{
struct V_161 * V_162 = (struct V_161 * ) V_25 ;
int V_163 ;
if ( V_32 )
F_69 ( & V_162 -> V_164 , 0 ) ;
V_163 = F_93 ( V_162 ) ;
return V_32 ? V_32 : V_163 ;
}
static int F_94 ( struct V_52 * exp , struct V_165 * V_166 ,
T_2 V_167 , struct V_159 * V_160 )
{
struct V_1 * V_2 = F_32 ( exp ) ;
struct V_161 * V_168 ;
struct V_169 * V_170 ;
struct V_3 * V_4 ;
int V_32 = 0 ;
F_25 ( V_166 -> V_171 ) ;
V_4 = & V_2 -> V_5 . V_4 ;
V_32 = F_95 ( V_2 , V_166 , & V_168 ) ;
if ( V_32 )
return V_32 ;
F_96 (req, &set->set_list, rq_link) {
V_32 = F_97 ( V_4 -> V_17 [ V_170 -> V_172 ] -> V_46 ,
& V_170 -> V_173 , V_167 , V_160 ) ;
if ( V_32 )
break;
}
if ( V_32 || F_98 ( & V_160 -> V_174 ) ) {
int V_163 ;
if ( V_32 )
F_69 ( & V_168 -> V_164 , 0 ) ;
V_163 = F_93 ( V_168 ) ;
return V_32 ? V_32 : V_163 ;
}
F_25 ( ! V_160 -> V_175 ) ;
V_160 -> V_175 = F_92 ;
V_160 -> V_176 = ( void * ) V_168 ;
return 0 ;
}
static int F_99 ( const struct V_50 * V_51 , struct V_52 * exp ,
struct V_177 * V_178 , T_2 V_167 , T_1 V_179 )
{
struct V_159 * V_168 = NULL ;
struct V_165 V_166 = {
. V_171 = V_178 ,
. V_180 = V_179 ,
} ;
int V_32 = 0 ;
V_168 = F_100 () ;
if ( ! V_168 )
return - V_100 ;
V_32 = F_94 ( exp , & V_166 , V_167 , V_168 ) ;
if ( V_32 == 0 )
V_32 = F_101 ( V_168 ) ;
F_102 ( V_168 ) ;
return V_32 ;
}
static int F_103 ( unsigned int V_148 , struct V_52 * exp , int V_181 ,
void * V_182 , void T_3 * V_183 )
{
struct V_1 * V_184 = F_32 ( exp ) ;
struct V_3 * V_4 = & V_184 -> V_5 . V_4 ;
int V_10 = 0 , V_32 = 0 , V_105 = V_4 -> V_15 . V_16 ;
struct V_26 * V_91 ;
switch ( V_148 ) {
case V_185 : {
struct V_186 * V_25 = V_182 ;
struct V_1 * V_62 ;
struct V_177 V_187 = { 0 } ;
T_1 V_22 ;
T_1 V_179 ;
memcpy ( & V_22 , V_25 -> V_188 , sizeof( T_1 ) ) ;
if ( V_22 >= V_105 )
return - V_47 ;
if ( ! V_4 -> V_17 [ V_22 ] )
return - V_189 ;
if ( ! V_4 -> V_17 [ V_22 ] -> V_63 )
return - V_190 ;
V_62 = F_32 ( V_4 -> V_17 [ V_22 ] -> V_46 ) ;
if ( ! V_62 )
return - V_33 ;
if ( F_104 ( V_25 -> V_191 , F_105 ( V_62 ) ,
F_106 (unsigned long, data->ioc_plen2,
sizeof(struct obd_uuid)) ) )
return - V_192 ;
memcpy ( & V_179 , V_25 -> V_193 , sizeof( T_1 ) ) ;
V_179 = V_179 & V_194 ? V_195 : 0 ;
V_32 = V_177 ( NULL , V_4 -> V_17 [ V_22 ] -> V_46 , & V_187 ,
F_107 ( - V_196 ) ,
V_179 ) ;
if ( V_32 )
return V_32 ;
if ( F_104 ( V_25 -> V_197 , & V_187 ,
F_106 (unsigned long, data->ioc_plen1,
sizeof(stat_buf)) ) )
return - V_192 ;
break;
}
case V_198 : {
struct V_186 * V_25 ;
struct V_111 * V_15 ;
char * V_199 = NULL ;
T_1 * V_147 ;
V_181 = 0 ;
if ( F_108 ( & V_199 , & V_181 , V_183 ) )
return - V_33 ;
V_25 = (struct V_186 * ) V_199 ;
if ( sizeof( * V_15 ) > V_25 -> V_200 ) {
F_109 ( V_199 , V_181 ) ;
return - V_33 ;
}
if ( sizeof( V_91 -> V_68 ) * V_105 > V_25 -> V_201 ) {
F_109 ( V_199 , V_181 ) ;
return - V_33 ;
}
if ( sizeof( T_1 ) * V_105 > V_25 -> V_202 ) {
F_109 ( V_199 , V_181 ) ;
return - V_33 ;
}
V_15 = (struct V_111 * ) V_25 -> V_193 ;
memcpy ( V_15 , & V_4 -> V_15 , sizeof( * V_15 ) ) ;
V_91 = (struct V_26 * ) V_25 -> V_188 ;
V_147 = ( T_1 * ) V_25 -> V_203 ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ , V_91 ++ , V_147 ++ ) {
if ( ! V_4 -> V_17 [ V_10 ] )
continue;
* V_91 = V_4 -> V_17 [ V_10 ] -> V_34 ;
* V_147 = V_4 -> V_17 [ V_10 ] -> V_70 ;
}
if ( F_104 ( V_183 , V_199 , V_181 ) )
V_32 = - V_192 ;
F_109 ( V_199 , V_181 ) ;
break;
}
case V_204 : {
struct V_205 * V_206 = V_182 ;
struct V_11 * V_12 = NULL ;
struct V_207 * V_208 ;
if ( V_206 -> V_209 == V_210 ) {
if ( V_105 <= V_206 -> V_211 )
return - V_33 ;
V_12 = V_4 -> V_17 [ V_206 -> V_211 ] ;
if ( ! V_12 || ! V_12 -> V_46 )
return - V_33 ;
} else if ( V_206 -> V_209 == V_212 ) {
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 ||
! F_39 ( & V_12 -> V_34 ,
& V_206 -> V_26 ) )
continue;
if ( ! V_12 -> V_46 )
return - V_33 ;
break;
}
} else {
return - V_33 ;
}
if ( V_10 >= V_105 )
return - V_189 ;
F_25 ( V_12 && V_12 -> V_46 ) ;
V_208 = F_49 ( sizeof( * V_208 ) , V_99 ) ;
if ( ! V_208 )
return - V_100 ;
F_110 ( V_208 , V_206 ) ;
V_32 = V_207 ( V_12 -> V_46 , V_208 ) ;
if ( V_32 == 0 ) {
F_110 ( V_206 , V_208 ) ;
V_206 -> V_209 = V_210 ;
V_206 -> V_26 = V_12 -> V_34 ;
}
F_48 ( V_208 ) ;
break;
}
default: {
int V_168 = 0 ;
if ( V_105 == 0 )
return - V_213 ;
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
int V_163 ;
struct V_1 * V_62 ;
if ( ! V_4 -> V_17 [ V_10 ] || ! V_4 -> V_17 [ V_10 ] -> V_46 )
continue;
V_62 = F_32 ( V_4 -> V_17 [ V_10 ] -> V_46 ) ;
V_62 -> V_66 = V_184 -> V_66 ;
V_163 = F_111 ( V_148 , V_4 -> V_17 [ V_10 ] -> V_46 ,
V_181 , V_182 , V_183 ) ;
if ( V_163 ) {
if ( V_4 -> V_17 [ V_10 ] -> V_63 ) {
F_8 ( V_163 == - V_213 ?
V_214 : V_215 ,
L_55 ,
F_53 ( V_4 , V_10 ) ,
V_10 , V_148 , V_163 ) ;
if ( ! V_32 )
V_32 = V_163 ;
}
} else {
V_168 = 1 ;
}
}
if ( ! V_168 && ! V_32 )
V_32 = - V_216 ;
}
}
return V_32 ;
}
static int F_112 ( const struct V_50 * V_51 , struct V_52 * exp ,
T_1 V_217 , void * V_218 , T_1 * V_219 , void * V_106 )
{
struct V_1 * V_184 = F_32 ( exp ) ;
struct V_3 * V_4 = & V_184 -> V_5 . V_4 ;
struct V_111 * V_220 = & V_4 -> V_15 ;
int V_32 = 0 ;
if ( ! V_219 || ! V_106 )
return - V_192 ;
F_26 ( V_184 ) ;
if ( F_113 ( V_221 ) ) {
T_4 V_222 = F_106 ( T_4 , V_220 -> V_64 ,
V_223 ) ;
* ( ( T_4 * ) V_106 ) = F_114 ( V_222 , V_224 ) ;
} else if ( F_113 ( V_225 ) ) {
T_4 V_226 = F_106 ( T_4 , V_220 -> V_113 ,
V_223 ) ;
* ( ( T_4 * ) V_106 ) = F_114 ( V_226 , V_224 ) ;
} else if ( F_113 ( V_227 ) ) {
* ( ( int * ) V_106 ) = V_4 -> V_15 . V_16 ;
} else {
V_32 = - V_33 ;
}
F_30 ( V_184 ) ;
return V_32 ;
}
static int F_115 ( const struct V_50 * V_51 , struct V_52 * exp ,
T_4 V_217 , void * V_218 , T_4 V_219 ,
void * V_106 , struct V_159 * V_168 )
{
struct V_1 * V_184 = F_32 ( exp ) ;
struct V_3 * V_4 = & V_184 -> V_5 . V_4 ;
T_4 V_105 ;
int V_10 , V_32 = 0 , V_163 ;
struct V_11 * V_12 ;
int V_228 = 0 , V_229 = 0 ;
if ( ! V_168 ) {
V_229 = 1 ;
V_168 = F_100 () ;
if ( ! V_168 )
return - V_100 ;
}
F_26 ( V_184 ) ;
V_105 = V_4 -> V_15 . V_16 ;
if ( F_113 ( V_230 ) ) {
V_228 = 1 ;
} else if ( F_113 ( V_103 ) ) {
F_25 ( ! V_4 -> V_102 ) ;
V_4 -> V_102 = V_106 ;
V_228 = 1 ;
F_116 ( V_4 -> V_102 ) ;
}
for ( V_10 = 0 ; V_10 < V_105 ; V_10 ++ ) {
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 || ! V_12 -> V_46 )
continue;
if ( ! V_12 -> V_63 && ! V_228 )
continue;
V_163 = F_51 ( V_51 , V_12 -> V_46 , V_217 , V_218 ,
V_219 , V_106 , V_168 ) ;
if ( ! V_32 )
V_32 = V_163 ;
}
F_30 ( V_184 ) ;
if ( V_229 ) {
V_163 = F_101 ( V_168 ) ;
if ( ! V_32 )
V_32 = V_163 ;
F_102 ( V_168 ) ;
}
return V_32 ;
}
void F_117 ( struct V_231 * V_232 )
__acquires( &md->lsm_lock
void F_118 ( struct V_231 * V_232 )
__releases( &md->lsm_lock
static int F_119 ( struct V_1 * V_2 , struct V_52 * exp ,
struct V_207 * V_208 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
struct V_11 * V_12 ;
T_2 V_233 = 0 ;
T_2 V_234 = 0 ;
int V_10 , V_32 = 0 ;
if ( V_208 -> V_235 != V_236 &&
V_208 -> V_235 != V_237 ) {
F_16 ( L_56 , V_208 -> V_235 ) ;
return - V_192 ;
}
F_26 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 . V_16 ; V_10 ++ ) {
int V_163 ;
V_12 = V_4 -> V_17 [ V_10 ] ;
if ( ! V_12 )
continue;
if ( ! V_12 -> V_63 || V_12 -> V_18 ) {
if ( V_208 -> V_235 == V_236 &&
V_4 -> V_17 [ V_10 ] -> V_59 ) {
V_32 = - V_238 ;
F_16 ( L_57 , V_10 ) ;
} else {
F_8 ( V_239 , L_57 , V_10 ) ;
}
continue;
}
V_163 = V_207 ( V_12 -> V_46 , V_208 ) ;
if ( V_163 ) {
if ( V_12 -> V_63 && ! V_32 )
V_32 = V_163 ;
continue;
}
if ( V_208 -> V_235 == V_236 ) {
V_233 += V_208 -> V_240 . V_241 ;
V_234 += V_208 -> V_240 . V_242 ;
}
}
F_30 ( V_2 ) ;
if ( V_208 -> V_235 == V_236 ) {
V_208 -> V_240 . V_241 = V_233 ;
V_208 -> V_240 . V_242 = V_234 ;
}
return V_32 ;
}
static int T_5 F_120 ( void )
{
struct V_118 V_119 = { NULL } ;
int V_32 ;
F_8 ( V_74 , L_58 , & V_243 ) ;
V_32 = F_121 ( V_243 ) ;
if ( V_32 )
return V_32 ;
V_244 = F_122 ( L_59 ,
sizeof( struct V_245 ) ,
0 , V_246 , NULL ) ;
if ( ! V_244 ) {
F_123 ( V_243 ) ;
return - V_100 ;
}
F_74 ( & V_119 ) ;
V_32 = F_124 ( & V_247 , NULL ,
V_248 , & V_249 ) ;
if ( V_32 ) {
F_125 ( V_244 ) ;
F_123 ( V_243 ) ;
}
return V_32 ;
}
static void F_126 ( void )
{
F_127 ( V_248 ) ;
F_125 ( V_244 ) ;
F_123 ( V_243 ) ;
}
