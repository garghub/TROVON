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
V_27 -> V_49 = 1 ;
V_27 -> V_50 = 1 ;
V_41 = F_14 ( V_39 , V_25 , NULL , NULL , NULL , V_27 , true ) ;
if ( V_41 == NULL )
return - V_51 ;
V_42 = F_15 ( V_41 , V_36 -> V_52 , V_25 -> V_14 ) ;
F_16 ( V_39 , true ) ;
return V_42 ;
}
static int F_17 ( struct V_53 * V_54 ,
union V_55 * V_56 ,
struct V_26 * V_27 ,
struct V_35 * V_36 ,
struct V_57 * V_57 )
{
struct V_37 * V_38 = F_18 ( V_54 , struct V_37 , V_54 ) ;
struct V_24 V_25 ;
int V_42 = 0 ;
if ( F_19 ( V_57 , & V_25 , V_27 ) < 0 ) {
F_20 ( L_1 ,
V_56 -> V_58 . type ) ;
return - 1 ;
}
if ( V_38 -> V_59 && ! F_21 ( V_27 -> V_60 , V_38 -> V_61 ) )
goto V_62;
if ( ! V_25 . V_63 && F_9 ( V_36 , V_27 , & V_25 , V_38 ) ) {
F_20 ( L_2
L_3 ) ;
V_42 = - 1 ;
}
V_62:
F_22 ( & V_25 ) ;
return V_42 ;
}
static int F_23 ( struct V_40 * V_41 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
return F_24 ( V_41 -> V_64 . V_7 , V_41 -> V_64 . V_46 , V_36 ,
V_38 -> V_65 , V_38 -> V_66 , 0 , 0 ) ;
}
static void F_25 ( struct V_39 * V_39 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_45 * V_67 = F_26 ( & V_39 -> V_68 ) , * V_69 ;
int V_70 = V_71 ;
while ( V_67 ) {
struct V_40 * V_41 = F_27 ( V_67 , struct V_40 , V_45 ) ;
struct V_8 * V_9 ;
if ( V_41 -> V_64 . V_7 == NULL || V_41 -> V_64 . V_46 -> V_47 -> V_72 )
goto V_73;
V_9 = F_2 ( V_41 -> V_64 . V_7 ) ;
if ( V_9 -> V_74 == NULL ) {
V_73:
if ( V_70 == V_75 )
V_67 = F_28 ( V_67 ) ;
else
V_67 = F_29 ( V_67 ) ;
continue;
}
if ( V_76 == 2 ) {
int V_42 ;
int (* F_30)( struct V_40 * V_41 ,
struct V_35 * V_36 ,
struct V_77 * V_78 );
F_30 = F_31 ( V_79 ,
L_4 ) ;
if ( F_30 == NULL ) {
F_32 ( L_5 ) ;
return;
}
V_42 = F_30 ( V_41 , V_36 , NULL ) ;
if ( ! V_42 || ! V_38 -> V_80 )
return;
V_67 = F_29 ( V_67 ) ;
} else if ( V_76 == 1 ) {
V_70 = F_33 ( V_41 , V_36 , NULL ) ;
switch ( V_70 ) {
case - 1 :
if ( ! V_38 -> V_80 )
return;
case V_71 :
V_69 = F_29 ( V_67 ) ;
break;
case V_75 :
V_69 = F_28 ( V_67 ) ;
break;
default:
return;
}
if ( V_69 != NULL )
V_67 = V_69 ;
} else {
F_23 ( V_41 , V_36 , V_38 ) ;
V_67 = F_29 ( V_67 ) ;
F_34 ( & V_9 -> V_74 -> V_81 ) ;
F_34 ( & V_9 -> V_74 ) ;
}
}
}
static int F_35 ( struct V_37 * V_38 )
{
int V_42 ;
struct V_82 * V_83 = V_38 -> V_83 ;
struct V_35 * V_84 ;
T_1 V_85 ;
if ( V_38 -> V_59 ) {
V_42 = F_36 ( V_83 , V_38 -> V_59 ,
V_38 -> V_61 ) ;
if ( V_42 )
goto V_86;
}
if ( ! V_87 ) {
V_42 = F_37 ( & V_83 -> V_58 . V_88 ) ;
if ( V_42 )
goto V_86;
}
V_42 = F_38 ( V_83 ) ;
if ( V_42 )
goto V_86;
if ( V_89 ) {
F_39 ( V_83 , stdout ) ;
F_40 ( V_83 -> V_90 , stdout ) ;
goto V_86;
}
if ( V_91 > 3 )
F_41 ( V_83 , stdout ) ;
if ( V_91 > 2 )
F_42 ( V_83 , stdout ) ;
V_85 = 0 ;
F_43 (session->evlist, pos) {
struct V_39 * V_39 = F_10 ( V_84 ) ;
T_2 V_92 = V_39 -> V_93 . V_94 [ V_95 ] ;
if ( V_92 > 0 ) {
V_85 += V_92 ;
F_44 ( V_39 , NULL ) ;
F_45 ( V_84 , V_96 ) ;
F_46 ( V_84 , NULL ) ;
if ( V_97 . V_98 &&
! F_47 ( V_84 ) )
continue;
F_25 ( V_39 , V_84 , V_38 ) ;
}
}
if ( V_85 == 0 ) {
F_32 ( L_6 , V_83 -> V_99 -> V_100 ) ;
goto V_86;
}
if ( V_76 == 2 ) {
void (* F_48)( void );
F_48 = F_31 ( V_79 ,
L_7 ) ;
if ( F_48 == NULL ) {
F_32 ( L_5 ) ;
goto V_86;
}
F_48 () ;
}
V_86:
return V_42 ;
}
int F_49 ( int V_101 , const char * * V_102 , const char * T_3 V_103 )
{
struct V_37 F_30 = {
. V_54 = {
. V_27 = F_17 ,
. V_104 = V_105 ,
. V_106 = V_107 ,
. V_108 = V_109 ,
. exit = V_110 ,
. V_111 = V_112 ,
. V_113 = true ,
. V_114 = true ,
} ,
} ;
struct V_115 V_99 = {
. V_116 = V_117 ,
} ;
const struct V_118 V_119 [] = {
F_50 ( 'i' , L_8 , & V_120 , L_9 ,
L_10 ) ,
F_50 ( 'd' , L_11 , & V_97 . V_121 , L_12 ,
L_13 ) ,
F_50 ( 's' , L_14 , & F_30 . V_43 , L_14 ,
L_15 ) ,
F_51 ( 'f' , L_16 , & V_99 . V_122 , L_17 ) ,
F_52 ( 'v' , L_18 , & V_91 ,
L_19 ) ,
F_51 ( 'q' , L_20 , & V_123 , L_21 ) ,
F_51 ( 'D' , L_22 , & V_89 ,
L_23 ) ,
F_51 ( 0 , L_24 , & F_30 . V_124 , L_25 ) ,
F_51 ( 0 , L_26 , & F_30 . V_125 , L_27 ) ,
F_51 ( 0 , L_28 , & F_30 . V_126 , L_29 ) ,
F_50 ( 'k' , L_30 , & V_97 . V_127 ,
L_9 , L_31 ) ,
F_51 ( 'm' , L_32 , & V_97 . V_128 ,
L_33 ) ,
F_51 ( 'l' , L_34 , & F_30 . V_65 ,
L_35 ) ,
F_51 ( 'P' , L_36 , & F_30 . V_66 ,
L_37 ) ,
F_51 ( 0 , L_38 , & F_30 . V_80 ,
L_39 ) ,
F_50 ( 'C' , L_40 , & F_30 . V_59 , L_40 , L_41 ) ,
F_53 ( 0 , L_42 , NULL , L_43 ,
L_44 ,
V_129 ) ,
F_51 ( 0 , L_45 , & V_97 . V_130 ,
L_46 ) ,
F_51 ( 0 , L_47 , & V_97 . V_131 ,
L_48 ) ,
F_50 ( 'M' , L_49 , & V_132 , L_50 ,
L_51 ) ,
F_50 ( 0 , L_52 , & V_87 , L_53 ,
L_54 ) ,
F_51 ( 0 , L_55 , & V_97 . V_98 ,
L_56 ) ,
F_51 ( 0 , L_57 , & V_97 . V_133 ,
L_58 ) ,
F_54 ( 0 , L_59 , NULL , L_60 ,
L_61 ,
V_134 , L_62 ) ,
F_55 ()
} ;
int V_42 = F_56 () ;
if ( V_42 < 0 )
return V_42 ;
V_101 = F_57 ( V_101 , V_102 , V_119 , V_135 , 0 ) ;
if ( V_101 ) {
if ( V_101 > 1 )
F_58 ( V_135 , V_119 ) ;
F_30 . V_43 = V_102 [ 0 ] ;
}
if ( V_123 )
F_59 () ;
V_99 . V_100 = V_120 ;
F_30 . V_83 = F_60 ( & V_99 , false , & F_30 . V_54 ) ;
if ( F_30 . V_83 == NULL )
return - 1 ;
V_42 = F_61 () ;
if ( V_42 < 0 )
goto V_136;
V_97 . V_137 = true ;
V_42 = F_62 ( & F_30 . V_83 -> V_58 . V_88 ) ;
if ( V_42 < 0 )
goto V_136;
if ( F_63 ( NULL ) < 0 )
F_58 ( V_135 , V_119 ) ;
if ( F_30 . V_126 )
V_76 = 0 ;
else if ( F_30 . V_125 )
V_76 = 1 ;
else if ( F_30 . V_124 )
V_76 = 2 ;
F_64 ( true ) ;
V_42 = F_35 ( & F_30 ) ;
V_136:
return V_42 ;
}
