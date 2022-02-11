static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 ? F_2 ( V_7 ) : NULL ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
if ( ! V_2 -> V_14 || V_2 -> V_14 > V_3 -> V_14 )
return;
V_11 = F_3 ( V_2 -> V_14 , V_3 -> V_14 ) ;
if ( ! F_4 ( & V_11 ) )
return;
V_13 = V_10 ( & V_11 ) ;
assert ( V_13 -> V_15 ) ;
V_13 -> V_13 ++ ;
do {
V_13 = V_10 ( & V_11 ) ;
V_13 -> V_16 ++ ;
V_13 -> V_7 = V_7 ;
if ( V_9 )
V_9 -> V_17 = F_5 ( V_9 -> V_17 , V_13 -> V_16 ) ;
} while ( F_6 ( & V_11 ) );
V_13 = V_10 ( & V_11 ) ;
assert ( V_13 -> V_18 ) ;
V_13 -> V_19 ++ ;
if ( V_5 -> V_20 )
V_13 -> V_21 ++ ;
}
static void F_7 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_28 = NULL ;
struct V_29 * V_30 ;
int V_31 ;
if ( ! V_23 || ! V_23 -> V_32 )
return;
V_30 = F_8 ( V_27 , V_25 ) ;
if ( ! V_30 )
return;
for ( V_31 = V_23 -> V_32 - 1 ; V_31 >= 0 ; V_31 -- ) {
if ( V_28 )
F_1 ( V_28 , & V_30 [ V_31 ] . V_33 , & V_30 [ V_31 ] . V_5 ) ;
V_28 = & V_30 [ V_31 ] . V_34 ;
}
free ( V_30 ) ;
}
static int F_9 ( struct V_35 * V_36 ,
struct V_26 * V_27 ,
struct V_24 * V_25 ,
struct V_37 * V_38 )
{
struct V_39 * V_39 = F_10 ( V_36 ) ;
struct V_40 * V_41 ;
int V_42 ;
if ( V_38 -> V_43 != NULL &&
( V_25 -> V_7 == NULL ||
strcmp ( V_38 -> V_43 , V_25 -> V_7 -> V_44 ) != 0 ) ) {
if ( V_25 -> V_7 != NULL ) {
F_11 ( & V_25 -> V_7 -> V_45 ,
& V_25 -> V_46 -> V_47 -> V_48 [ V_25 -> V_46 -> type ] ) ;
F_12 ( V_25 -> V_7 ) ;
F_13 ( V_25 -> V_46 -> V_47 ) ;
}
return 0 ;
}
F_7 ( V_27 -> V_22 , V_25 , V_27 ) ;
V_41 = F_14 ( V_39 , V_25 , NULL , NULL , NULL , V_27 , true ) ;
if ( V_41 == NULL )
return - V_49 ;
V_42 = F_15 ( V_41 , V_27 , V_36 -> V_50 , V_25 -> V_14 ) ;
F_16 ( V_39 , true ) ;
return V_42 ;
}
static int F_17 ( struct V_51 * V_52 ,
union V_53 * V_54 ,
struct V_26 * V_27 ,
struct V_35 * V_36 ,
struct V_55 * V_55 )
{
struct V_37 * V_38 = F_18 ( V_52 , struct V_37 , V_52 ) ;
struct V_24 V_25 ;
int V_42 = 0 ;
if ( F_19 ( V_55 , & V_25 , V_27 ) < 0 ) {
F_20 ( L_1 ,
V_54 -> V_56 . type ) ;
return - 1 ;
}
if ( V_38 -> V_57 && ! F_21 ( V_27 -> V_58 , V_38 -> V_59 ) )
goto V_60;
if ( ! V_25 . V_61 && F_9 ( V_36 , V_27 , & V_25 , V_38 ) ) {
F_20 ( L_2
L_3 ) ;
V_42 = - 1 ;
}
V_60:
F_22 ( & V_25 ) ;
return V_42 ;
}
static int F_23 ( struct V_40 * V_41 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
return F_24 ( V_41 -> V_62 . V_7 , V_41 -> V_62 . V_46 , V_36 ,
V_38 -> V_63 , V_38 -> V_64 , 0 , 0 ) ;
}
static void F_25 ( struct V_39 * V_39 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_45 * V_65 = F_26 ( & V_39 -> V_66 ) , * V_67 ;
int V_68 = V_69 ;
while ( V_65 ) {
struct V_40 * V_41 = F_27 ( V_65 , struct V_40 , V_45 ) ;
struct V_8 * V_9 ;
if ( V_41 -> V_62 . V_7 == NULL || V_41 -> V_62 . V_46 -> V_47 -> V_70 )
goto V_71;
V_9 = F_2 ( V_41 -> V_62 . V_7 ) ;
if ( V_9 -> V_72 == NULL ) {
V_71:
if ( V_68 == V_73 )
V_65 = F_28 ( V_65 ) ;
else
V_65 = F_29 ( V_65 ) ;
continue;
}
if ( V_74 == 2 ) {
int V_42 ;
int (* F_30)( struct V_40 * V_41 ,
struct V_35 * V_36 ,
struct V_75 * V_76 );
F_30 = F_31 ( V_77 ,
L_4 ) ;
if ( F_30 == NULL ) {
F_32 ( L_5 ) ;
return;
}
V_42 = F_30 ( V_41 , V_36 , NULL ) ;
if ( ! V_42 || ! V_38 -> V_78 )
return;
V_65 = F_29 ( V_65 ) ;
} else if ( V_74 == 1 ) {
V_68 = F_33 ( V_41 , V_36 , NULL ) ;
switch ( V_68 ) {
case - 1 :
if ( ! V_38 -> V_78 )
return;
case V_69 :
V_67 = F_29 ( V_65 ) ;
break;
case V_73 :
V_67 = F_28 ( V_65 ) ;
break;
default:
return;
}
if ( V_67 != NULL )
V_65 = V_67 ;
} else {
F_23 ( V_41 , V_36 , V_38 ) ;
V_65 = F_29 ( V_65 ) ;
F_34 ( & V_9 -> V_72 -> V_79 ) ;
F_34 ( & V_9 -> V_72 ) ;
}
}
}
static int F_35 ( struct V_37 * V_38 )
{
int V_42 ;
struct V_80 * V_81 = V_38 -> V_81 ;
struct V_35 * V_82 ;
T_1 V_83 ;
if ( V_38 -> V_57 ) {
V_42 = F_36 ( V_81 , V_38 -> V_57 ,
V_38 -> V_59 ) ;
if ( V_42 )
goto V_84;
}
if ( ! V_85 ) {
V_42 = F_37 ( & V_81 -> V_56 . V_86 ) ;
if ( V_42 )
goto V_84;
}
V_42 = F_38 ( V_81 ) ;
if ( V_42 )
goto V_84;
if ( V_87 ) {
F_39 ( V_81 , stdout ) ;
F_40 ( V_81 -> V_88 , stdout ) ;
goto V_84;
}
if ( V_89 > 3 )
F_41 ( V_81 , stdout ) ;
if ( V_89 > 2 )
F_42 ( V_81 , stdout ) ;
V_83 = 0 ;
F_43 (session->evlist, pos) {
struct V_39 * V_39 = F_10 ( V_82 ) ;
T_2 V_90 = V_39 -> V_91 . V_92 [ V_93 ] ;
if ( V_90 > 0 ) {
V_83 += V_90 ;
F_44 ( V_39 , NULL ) ;
F_45 ( V_82 , V_94 ) ;
F_46 ( V_82 , NULL ) ;
if ( V_95 . V_96 &&
! F_47 ( V_82 ) )
continue;
F_25 ( V_39 , V_82 , V_38 ) ;
}
}
if ( V_83 == 0 ) {
F_32 ( L_6 , V_81 -> V_97 -> V_98 ) ;
goto V_84;
}
if ( V_74 == 2 ) {
void (* F_48)( void );
F_48 = F_31 ( V_77 ,
L_7 ) ;
if ( F_48 == NULL ) {
F_32 ( L_5 ) ;
goto V_84;
}
F_48 () ;
}
V_84:
return V_42 ;
}
int F_49 ( int V_99 , const char * * V_100 )
{
struct V_37 F_30 = {
. V_52 = {
. V_27 = F_17 ,
. V_101 = V_102 ,
. V_103 = V_104 ,
. V_105 = V_106 ,
. exit = V_107 ,
. V_108 = V_109 ,
. V_110 = V_111 ,
. V_112 = V_113 ,
. V_114 = V_115 ,
. V_116 = V_117 ,
. V_118 = V_119 ,
. V_120 = true ,
. V_121 = true ,
} ,
} ;
struct V_122 V_97 = {
. V_123 = V_124 ,
} ;
struct V_125 V_126 [] = {
F_50 ( 'i' , L_8 , & V_127 , L_9 ,
L_10 ) ,
F_50 ( 'd' , L_11 , & V_95 . V_128 , L_12 ,
L_13 ) ,
F_50 ( 's' , L_14 , & F_30 . V_43 , L_14 ,
L_15 ) ,
F_51 ( 'f' , L_16 , & V_97 . V_129 , L_17 ) ,
F_52 ( 'v' , L_18 , & V_89 ,
L_19 ) ,
F_51 ( 'q' , L_20 , & V_130 , L_21 ) ,
F_51 ( 'D' , L_22 , & V_87 ,
L_23 ) ,
F_51 ( 0 , L_24 , & F_30 . V_131 , L_25 ) ,
F_51 ( 0 , L_26 , & F_30 . V_132 , L_27 ) ,
F_51 ( 0 , L_28 , & F_30 . V_133 , L_29 ) ,
F_50 ( 'k' , L_30 , & V_95 . V_134 ,
L_9 , L_31 ) ,
F_51 ( 'm' , L_32 , & V_95 . V_135 ,
L_33 ) ,
F_51 ( 'l' , L_34 , & F_30 . V_63 ,
L_35 ) ,
F_51 ( 'P' , L_36 , & F_30 . V_64 ,
L_37 ) ,
F_51 ( 0 , L_38 , & F_30 . V_78 ,
L_39 ) ,
F_50 ( 'C' , L_40 , & F_30 . V_57 , L_40 , L_41 ) ,
F_53 ( 0 , L_42 , NULL , L_43 ,
L_44 ,
V_136 ) ,
F_51 ( 0 , L_45 , & V_95 . V_137 ,
L_46 ) ,
F_51 ( 0 , L_47 , & V_95 . V_138 ,
L_48 ) ,
F_50 ( 'M' , L_49 , & V_139 , L_50 ,
L_51 ) ,
F_50 ( 0 , L_52 , & V_85 , L_53 ,
L_54 ) ,
F_51 ( 0 , L_55 , & V_95 . V_96 ,
L_56 ) ,
F_51 ( 0 , L_57 , & V_95 . V_140 ,
L_58 ) ,
F_51 ( 'n' , L_59 , & V_95 . V_141 ,
L_60 ) ,
F_54 ( 0 , L_61 , NULL , L_62 ,
L_63 ,
V_142 , L_64 ) ,
F_55 ()
} ;
int V_42 ;
F_56 ( V_126 , 0 , L_57 , V_143 ) ;
F_56 ( V_126 , 0 , L_59 , V_143 ) ;
V_42 = F_57 () ;
if ( V_42 < 0 )
return V_42 ;
V_99 = F_58 ( V_99 , V_100 , V_126 , V_144 , 0 ) ;
if ( V_99 ) {
if ( V_99 > 1 )
F_59 ( V_144 , V_126 ) ;
F_30 . V_43 = V_100 [ 0 ] ;
}
if ( V_95 . V_141 && F_30 . V_131 ) {
F_60 ( L_65 ) ;
return V_42 ;
}
if ( V_130 )
F_61 () ;
V_97 . V_98 = V_127 ;
F_30 . V_81 = F_62 ( & V_97 , false , & F_30 . V_52 ) ;
if ( F_30 . V_81 == NULL )
return - 1 ;
V_42 = F_63 () ;
if ( V_42 < 0 )
goto V_145;
V_95 . V_146 = true ;
V_42 = F_64 ( & F_30 . V_81 -> V_56 . V_86 ) ;
if ( V_42 < 0 )
goto V_145;
if ( F_65 ( NULL ) < 0 )
F_59 ( V_144 , V_126 ) ;
if ( F_30 . V_133 )
V_74 = 0 ;
else if ( F_30 . V_132 )
V_74 = 1 ;
else if ( F_30 . V_131 )
V_74 = 2 ;
F_66 ( true ) ;
V_42 = F_35 ( & F_30 ) ;
V_145:
return V_42 ;
}
