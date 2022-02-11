void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 != NULL ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static struct V_6 *
F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_9 ;
int V_10 ;
if ( V_2 != NULL && V_2 -> V_11 != V_12 )
return & V_13 ;
V_9 = F_5 ( V_14 , 1 ) ;
if ( ! V_15 )
V_10 = V_9 ;
else
V_10 = V_15 [ V_9 ] ;
V_8 = V_16 [ V_10 ] ;
V_10 = V_8 -> V_17 ;
if ( ++ V_10 == V_8 -> V_18 )
V_10 = 0 ;
V_8 -> V_17 = V_10 ;
return & V_8 -> V_19 [ V_10 ] ;
}
static int F_6 ( struct V_3 * V_20 ,
struct V_3 * V_21 )
{
struct V_22 * V_23 , * V_24 ;
struct V_1 * V_2 ;
int V_25 = 0 ;
F_7 ( & V_21 -> V_26 ) ;
if ( F_8 ( ! F_9 ( & V_21 -> V_27 ) ) ) {
F_10 (pos, tmp, &src->set_new_requests) {
V_2 = F_11 ( V_24 , struct V_1 ,
V_28 ) ;
V_2 -> V_4 = V_20 ;
}
F_12 ( & V_21 -> V_27 ,
& V_20 -> V_29 ) ;
V_25 = F_13 ( & V_21 -> V_30 ) ;
F_14 ( V_25 , & V_20 -> V_31 ) ;
F_15 ( & V_21 -> V_30 , 0 ) ;
}
F_16 ( & V_21 -> V_26 ) ;
return V_25 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_32 ;
if ( V_2 -> V_33 )
F_18 ( V_2 -> V_33 , NULL ) ;
F_7 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_35 ) {
struct V_36 V_37 = F_19 ( F_20 ( 5 ) ,
V_38 , NULL ) ;
V_2 -> V_35 = 0 ;
F_16 ( & V_2 -> V_34 ) ;
F_21 ( V_2 -> V_39 , ( V_2 -> V_4 == NULL ) , & V_37 ) ;
} else if ( V_2 -> V_4 ) {
F_2 ( V_2 -> V_40 == V_41 ) ;
F_2 ( V_2 -> V_11 == V_42 ) ;
F_22 ( & V_2 -> V_4 -> V_31 ) ;
F_16 ( & V_2 -> V_34 ) ;
F_3 ( & V_2 -> V_4 -> V_5 ) ;
return;
} else {
F_16 ( & V_2 -> V_34 ) ;
}
V_32 = F_4 ( V_2 ) ;
F_23 ( V_43 , V_2 , L_1 ,
V_2 , V_32 -> V_44 , V_32 -> V_45 ) ;
F_24 ( V_32 , V_2 ) ;
}
static inline void F_25 ( struct V_3 * V_46 )
{
F_22 ( & V_46 -> V_47 ) ;
}
static int F_26 ( struct V_48 * V_49 , struct V_6 * V_32 )
{
struct V_22 * V_23 , * V_24 ;
struct V_1 * V_2 ;
struct V_3 * V_46 = V_32 -> V_50 ;
int V_25 = 0 ;
int V_51 ;
if ( F_13 ( & V_46 -> V_30 ) ) {
F_7 ( & V_46 -> V_26 ) ;
if ( F_8 ( ! F_9 ( & V_46 -> V_27 ) ) ) {
F_12 ( & V_46 -> V_27 ,
& V_46 -> V_29 ) ;
F_14 ( F_13 ( & V_46 -> V_30 ) ,
& V_46 -> V_31 ) ;
F_15 ( & V_46 -> V_30 , 0 ) ;
V_25 = 1 ;
}
F_16 ( & V_46 -> V_26 ) ;
}
V_51 = F_27 ( V_49 ) ;
if ( V_51 != 0 ) {
F_28 ( L_2 , V_51 ) ;
return V_25 ;
}
if ( F_13 ( & V_46 -> V_31 ) )
V_25 |= F_29 ( V_49 , V_46 ) ;
F_10 (pos, tmp, &set->set_requests) {
V_2 = F_11 ( V_24 , struct V_1 , V_28 ) ;
if ( V_2 -> V_40 != V_52 )
break;
F_30 ( & V_2 -> V_28 ) ;
V_2 -> V_4 = NULL ;
F_31 ( V_2 ) ;
}
if ( V_25 == 0 ) {
V_25 = F_13 ( & V_46 -> V_30 ) ;
if ( V_25 == 0 && V_32 -> V_53 > 0 ) {
struct V_6 * V_54 ;
struct V_3 * V_55 ;
int V_56 = V_32 -> V_57 ;
do {
V_54 = V_32 -> V_58 [ V_32 -> V_57 ++ ] ;
if ( V_32 -> V_57 >= V_32 -> V_53 )
V_32 -> V_57 = 0 ;
if ( V_54 == NULL )
continue;
F_7 ( & V_54 -> V_59 ) ;
V_55 = V_54 -> V_50 ;
if ( V_55 == NULL ) {
F_16 ( & V_54 -> V_59 ) ;
continue;
}
F_25 ( V_55 ) ;
F_16 ( & V_54 -> V_59 ) ;
if ( F_13 ( & V_55 -> V_30 ) ) {
V_25 = F_6 ( V_46 , V_55 ) ;
if ( V_25 > 0 )
F_32 ( V_60 , L_3 ,
V_25 , V_54 -> V_45 ,
V_32 -> V_45 ) ;
}
F_33 ( V_55 ) ;
} while ( V_25 == 0 && V_32 -> V_57 != V_56 );
}
}
return V_25 ;
}
static int V_7 ( void * V_61 )
{
struct V_6 * V_32 = V_61 ;
struct V_3 * V_46 ;
struct V_48 V_49 = { . V_62 = NULL } ;
int V_25 = 0 ;
int exit = 0 ;
F_34 () ;
if ( F_35 ( V_14 , V_32 -> V_63 ) != 0 )
F_36 ( L_4 , V_32 -> V_44 , V_32 -> V_63 ) ;
V_46 = F_37 () ;
if ( ! V_46 ) {
V_25 = - V_64 ;
goto V_65;
}
F_7 ( & V_32 -> V_59 ) ;
V_32 -> V_50 = V_46 ;
F_16 ( & V_32 -> V_59 ) ;
V_25 = F_38 ( & V_49 . V_66 ,
V_67 | V_68 | V_69 ) ;
if ( V_25 != 0 )
goto V_65;
F_39 ( & V_32 -> V_70 ) ;
do {
struct V_36 V_37 ;
int V_71 ;
V_71 = F_40 ( V_46 ) ;
V_37 = F_19 ( F_20 ( V_71 ? V_71 : 1 ) ,
V_72 , V_46 ) ;
F_41 ( & V_49 . V_66 ) ;
F_21 ( V_46 -> V_5 ,
F_26 ( & V_49 , V_32 ) , & V_37 ) ;
F_42 ( & V_49 . V_66 ) ;
if ( F_43 ( V_73 , & V_32 -> V_74 ) ) {
if ( F_43 ( V_75 , & V_32 -> V_74 ) )
F_44 ( V_46 ) ;
exit ++ ;
}
} while ( exit < 2 );
if ( ! F_9 ( & V_46 -> V_29 ) )
F_45 ( V_46 ) ;
F_46 ( & V_49 . V_66 ) ;
F_39 ( & V_32 -> V_76 ) ;
return 0 ;
V_65:
V_32 -> V_77 = V_25 ;
F_39 ( & V_32 -> V_70 ) ;
return V_25 ;
}
static void F_47 ( struct V_6 * V_32 , int V_78 , int V_9 )
{
V_32 -> V_45 = V_78 ;
V_32 -> V_63 = V_9 ;
F_48 ( & V_32 -> V_70 ) ;
F_48 ( & V_32 -> V_76 ) ;
F_49 ( & V_32 -> V_59 ) ;
if ( V_78 < 0 ) {
snprintf ( V_32 -> V_44 , sizeof( V_32 -> V_44 ) , L_5 ) ;
} else {
snprintf ( V_32 -> V_44 , sizeof( V_32 -> V_44 ) ,
L_6 , V_9 , V_78 ) ;
}
}
static int F_50 ( struct V_7 * V_8 , int V_78 )
{
struct V_6 * V_32 ;
struct V_6 * * V_79 ;
int V_56 ;
int V_80 ;
int V_25 = 0 ;
int V_81 ;
F_2 ( V_78 >= 0 && V_78 < V_8 -> V_18 ) ;
V_32 = & V_8 -> V_19 [ V_78 ] ;
V_32 -> V_53 = V_8 -> V_82 - 1 ;
if ( V_32 -> V_53 <= 0 )
goto V_83;
V_81 = sizeof( struct V_6 * ) * V_32 -> V_53 ;
V_32 -> V_58 = F_51 ( V_81 , V_84 ,
F_52 ( V_14 ,
V_32 -> V_63 ) ) ;
if ( ! V_32 -> V_58 ) {
V_32 -> V_53 = 0 ;
V_25 = - V_64 ;
goto V_83;
}
V_56 = V_78 - V_78 % V_8 -> V_82 ;
V_79 = V_32 -> V_58 ;
for ( V_80 = V_56 ; V_80 < V_56 + V_8 -> V_82 ; V_80 ++ ) {
if ( V_80 != V_78 )
* V_79 ++ = & V_8 -> V_19 [ V_80 ] ;
}
V_83:
return V_25 ;
}
int F_53 ( struct V_6 * V_32 )
{
struct V_85 * V_86 ;
int V_25 = 0 ;
if ( F_54 ( V_87 , & V_32 -> V_74 ) ) {
F_36 ( L_7 ,
V_32 -> V_44 , V_32 ) ;
return 0 ;
}
V_25 = F_38 ( & V_32 -> V_88 . V_66 , V_67 | V_68 ) ;
if ( V_25 != 0 )
goto V_83;
V_86 = F_55 ( V_7 , V_32 , L_8 , V_32 -> V_44 ) ;
if ( F_56 ( V_86 ) ) {
V_25 = F_57 ( V_86 ) ;
goto V_89;
}
F_58 ( & V_32 -> V_70 ) ;
V_25 = V_32 -> V_77 ;
if ( V_25 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_32 -> V_50 != NULL ) {
struct V_3 * V_46 = V_32 -> V_50 ;
F_7 ( & V_32 -> V_59 ) ;
V_32 -> V_50 = NULL ;
F_16 ( & V_32 -> V_59 ) ;
F_59 ( V_46 ) ;
}
F_46 ( & V_32 -> V_88 . V_66 ) ;
V_83:
F_60 ( V_87 , & V_32 -> V_74 ) ;
return V_25 ;
}
void F_61 ( struct V_6 * V_32 , int V_90 )
{
if ( ! F_43 ( V_87 , & V_32 -> V_74 ) ) {
F_36 ( L_9 , V_32 ) ;
return;
}
F_62 ( V_73 , & V_32 -> V_74 ) ;
if ( V_90 )
F_62 ( V_75 , & V_32 -> V_74 ) ;
F_3 ( & V_32 -> V_50 -> V_5 ) ;
}
void F_63 ( struct V_6 * V_32 )
{
struct V_3 * V_46 = V_32 -> V_50 ;
if ( ! F_43 ( V_87 , & V_32 -> V_74 ) ) {
F_36 ( L_9 , V_32 ) ;
goto V_83;
}
F_58 ( & V_32 -> V_76 ) ;
F_46 ( & V_32 -> V_88 . V_66 ) ;
F_7 ( & V_32 -> V_59 ) ;
V_32 -> V_50 = NULL ;
F_16 ( & V_32 -> V_59 ) ;
F_59 ( V_46 ) ;
F_60 ( V_87 , & V_32 -> V_74 ) ;
F_60 ( V_73 , & V_32 -> V_74 ) ;
F_60 ( V_75 , & V_32 -> V_74 ) ;
V_83:
if ( V_32 -> V_53 > 0 ) {
F_2 ( V_32 -> V_58 != NULL ) ;
F_64 ( V_32 -> V_58 ) ;
V_32 -> V_58 = NULL ;
}
V_32 -> V_53 = 0 ;
V_32 -> V_77 = 0 ;
}
static void F_65 ( void )
{
int V_80 ;
int V_91 ;
if ( V_16 != NULL ) {
for ( V_80 = 0 ; V_80 < V_92 ; V_80 ++ ) {
if ( ! V_16 [ V_80 ] )
break;
for ( V_91 = 0 ; V_91 < V_16 [ V_80 ] -> V_18 ; V_91 ++ )
F_61 ( & V_16 [ V_80 ] -> V_19 [ V_91 ] , 0 ) ;
for ( V_91 = 0 ; V_91 < V_16 [ V_80 ] -> V_18 ; V_91 ++ )
F_63 ( & V_16 [ V_80 ] -> V_19 [ V_91 ] ) ;
F_64 ( V_16 [ V_80 ] ) ;
V_16 [ V_80 ] = NULL ;
}
F_64 ( V_16 ) ;
}
V_92 = 0 ;
F_61 ( & V_13 , 0 ) ;
F_63 ( & V_13 ) ;
F_64 ( V_15 ) ;
V_15 = NULL ;
}
static int F_66 ( void )
{
int V_93 ;
int V_94 ;
int V_81 ;
int V_80 ;
int V_91 ;
int V_25 = 0 ;
struct V_14 * V_95 ;
T_1 * V_96 = NULL ;
int V_97 ;
int V_9 ;
struct V_7 * V_8 ;
V_95 = V_14 ;
V_97 = F_67 ( V_95 ) ;
if ( V_98 ) {
struct V_99 * V_100 ;
V_81 = V_97 * sizeof( V_15 [ 0 ] ) ;
V_15 = F_68 ( V_81 , V_101 ) ;
if ( ! V_15 ) {
V_25 = - V_64 ;
goto V_83;
}
V_25 = F_69 ( V_98 ,
strlen ( V_98 ) ,
0 , V_97 - 1 , & V_100 ) ;
if ( V_25 != 0 ) {
F_28 ( L_10 ,
V_98 ) ;
V_25 = - V_102 ;
goto V_83;
}
V_25 = F_70 ( V_100 , V_97 , & V_96 ) ;
F_71 ( V_100 ) ;
if ( V_25 <= 0 ) {
F_28 ( L_11 ,
V_98 , V_25 ) ;
if ( V_25 == 0 )
V_25 = - V_102 ;
goto V_83;
}
for ( V_9 = 0 ; V_9 < V_97 ; V_9 ++ ) {
for ( V_80 = 0 ; V_80 < V_25 ; V_80 ++ )
if ( V_96 [ V_80 ] == V_9 )
break;
if ( V_80 >= V_25 )
V_80 = V_9 % V_25 ;
V_15 [ V_9 ] = V_80 ;
}
F_72 ( V_96 , V_25 ) ;
V_97 = V_25 ;
}
V_92 = V_97 ;
V_81 = V_97 * sizeof( V_16 [ 0 ] ) ;
V_16 = F_68 ( V_81 , V_101 ) ;
if ( ! V_16 ) {
V_25 = - V_64 ;
goto V_83;
}
if ( V_103 != 0 ) {
F_36 ( L_12 ) ;
if ( V_104 == 0 ) {
V_104 = V_103 / V_97 ;
if ( V_103 % V_97 != 0 )
V_104 ++ ;
F_36 ( L_13 ,
V_104 ) ;
} else {
F_36 ( L_14 ) ;
}
}
if ( V_105 != 0 ) {
F_36 ( L_15 ) ;
if ( V_106 == 0 ) {
switch ( V_105 ) {
case 1 :
case 2 :
V_106 = 1 ;
break;
case 3 :
V_106 = 2 ;
break;
case 4 :
#ifdef F_73
V_106 = - 1 ;
#else
V_106 = 3 ;
#endif
break;
default:
V_106 = 2 ;
break;
}
F_36 ( L_16 ,
V_106 ) ;
} else {
F_36 ( L_17 ) ;
}
}
if ( V_106 == 0 )
V_106 = 2 ;
else if ( V_106 < 0 )
V_106 = - 1 ;
else if ( V_104 > 0 &&
V_106 > V_104 )
V_106 = V_104 ;
F_62 ( V_107 , & V_13 . V_74 ) ;
F_47 ( & V_13 , - 1 , V_108 ) ;
V_25 = F_53 ( & V_13 ) ;
if ( V_25 < 0 )
goto V_83;
for ( V_80 = 0 ; V_80 < V_97 ; V_80 ++ ) {
if ( ! V_96 )
V_9 = V_80 ;
else
V_9 = V_96 [ V_80 ] ;
V_93 = F_74 ( V_95 , V_9 ) ;
if ( V_104 > 0 && V_104 < V_93 )
V_93 = V_104 ;
if ( V_93 < 2 )
V_93 = 2 ;
if ( V_106 <= 0 ) {
V_94 = V_93 ;
} else if ( V_93 <= V_106 ) {
V_94 = V_93 ;
} else {
V_94 = V_106 ;
if ( V_93 % V_94 != 0 )
V_93 += V_94 - ( V_93 % V_94 ) ;
}
V_81 = F_75 ( struct V_7 , V_19 [ V_93 ] ) ;
V_8 = F_51 ( V_81 , V_84 ,
F_52 ( V_14 , V_9 ) ) ;
if ( ! V_8 ) {
V_25 = - V_64 ;
goto V_83;
}
V_8 -> V_109 = V_81 ;
V_8 -> V_110 = V_80 ;
V_8 -> V_111 = V_9 ;
V_8 -> V_17 = 0 ;
V_8 -> V_18 = V_93 ;
V_8 -> V_82 = V_94 ;
V_16 [ V_80 ] = V_8 ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
F_47 ( & V_8 -> V_19 [ V_91 ] , V_91 , V_9 ) ;
V_25 = F_50 ( V_8 , V_91 ) ;
if ( V_25 < 0 )
goto V_83;
}
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
V_25 = F_53 ( & V_8 -> V_19 [ V_91 ] ) ;
if ( V_25 < 0 )
goto V_83;
}
}
V_83:
if ( V_25 != 0 )
F_65 () ;
return V_25 ;
}
int F_76 ( void )
{
int V_25 = 0 ;
F_77 ( & V_112 ) ;
if ( ++ V_113 == 1 )
V_25 = F_66 () ;
F_78 ( & V_112 ) ;
return V_25 ;
}
void F_79 ( void )
{
F_77 ( & V_112 ) ;
if ( -- V_113 == 0 )
F_65 () ;
F_78 ( & V_112 ) ;
}
