static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long args [ 6 ] ;
V_2 -> V_8 = F_3 ( V_4 , V_7 ) ;
V_2 -> V_9 = F_4 () ;
F_5 ( V_4 , V_7 , 0 , 6 , args ) ;
V_2 -> args [ 0 ] = args [ 0 ] ;
V_2 -> args [ 1 ] = args [ 1 ] ;
V_2 -> args [ 2 ] = args [ 2 ] ;
V_2 -> args [ 3 ] = args [ 3 ] ;
V_2 -> args [ 4 ] = args [ 4 ] ;
V_2 -> args [ 5 ] = args [ 5 ] ;
V_2 -> V_10 = F_6 ( V_4 ) ;
}
static int F_7 ( struct V_11 * V_12 , unsigned int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
struct V_11 * V_15 = & V_12 [ V_14 ] ;
T_1 V_16 = V_15 -> V_16 ;
T_2 V_17 = V_15 -> V_17 ;
switch ( V_16 ) {
case V_18 :
V_15 -> V_16 = V_19 | V_20 | V_21 ;
if ( V_17 >= sizeof( struct V_1 ) || V_17 & 3 )
return - V_22 ;
continue;
case V_23 :
V_15 -> V_16 = V_24 | V_25 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_26 :
V_15 -> V_16 = V_19 | V_25 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
F_8 ( V_15 , V_15 ) ;
continue;
default:
return - V_22 ;
}
}
return 0 ;
}
static T_2 F_9 ( int V_65 )
{
struct V_66 * V_67 ;
struct V_1 V_2 ;
T_2 V_68 = V_69 ;
if ( F_10 ( V_5 -> V_70 . V_12 == NULL ) )
return V_71 ;
F_1 ( & V_2 ) ;
for ( V_67 = V_5 -> V_70 . V_12 ; V_67 ; V_67 = V_67 -> V_72 ) {
T_2 V_73 = F_11 ( & V_2 , V_67 -> V_74 ) ;
if ( ( V_73 & V_75 ) < ( V_68 & V_75 ) )
V_68 = V_73 ;
}
return V_68 ;
}
static long F_12 ( struct V_76 * V_77 )
{
struct V_66 * V_12 ;
unsigned long V_78 = V_77 -> V_79 * sizeof( struct V_11 ) ;
unsigned long V_80 = V_77 -> V_79 ;
struct V_11 * V_81 ;
int V_82 ;
long V_68 ;
if ( V_77 -> V_79 == 0 || V_77 -> V_79 > V_83 )
return - V_22 ;
for ( V_12 = V_5 -> V_70 . V_12 ; V_12 ; V_12 = V_12 -> V_72 )
V_80 += V_12 -> V_79 + 4 ;
if ( V_80 > V_84 )
return - V_85 ;
if ( ! V_5 -> V_86 &&
F_13 ( F_14 () , F_15 () ,
V_87 ) != 0 )
return - V_88 ;
V_81 = F_16 ( V_78 , V_89 | V_90 ) ;
if ( ! V_81 )
return - V_85 ;
V_68 = - V_91 ;
if ( F_17 ( V_81 , V_77 -> V_12 , V_78 ) )
goto V_92;
V_68 = F_18 ( V_81 , V_77 -> V_79 ) ;
if ( V_68 )
goto V_92;
V_68 = F_7 ( V_81 , V_77 -> V_79 ) ;
if ( V_68 )
goto V_92;
V_68 = F_19 ( V_81 , V_77 -> V_79 , NULL , & V_82 ) ;
if ( V_68 )
goto V_92;
V_68 = - V_85 ;
V_12 = F_16 ( sizeof( struct V_66 ) +
sizeof( struct V_93 ) * V_82 ,
V_89 | V_90 ) ;
if ( ! V_12 )
goto V_92;
V_68 = F_19 ( V_81 , V_77 -> V_79 , V_12 -> V_74 , & V_82 ) ;
if ( V_68 )
goto V_94;
F_20 ( V_81 ) ;
F_21 ( & V_12 -> V_95 , 1 ) ;
V_12 -> V_79 = V_82 ;
V_12 -> V_72 = V_5 -> V_70 . V_12 ;
V_5 -> V_70 . V_12 = V_12 ;
return 0 ;
V_94:
F_20 ( V_12 ) ;
V_92:
F_20 ( V_81 ) ;
return V_68 ;
}
static long F_22 ( char T_3 * V_96 )
{
struct V_76 V_77 ;
long V_68 = - V_91 ;
#ifdef F_23
if ( F_24 () ) {
struct V_97 V_98 ;
if ( F_17 ( & V_98 , V_96 , sizeof( V_98 ) ) )
goto V_99;
V_77 . V_79 = V_98 . V_79 ;
V_77 . V_12 = F_25 ( V_98 . V_12 ) ;
} else
#endif
if ( F_17 ( & V_77 , V_96 , sizeof( V_77 ) ) )
goto V_99;
V_68 = F_12 ( & V_77 ) ;
V_99:
return V_68 ;
}
void F_26 ( struct V_3 * V_100 )
{
struct V_66 * V_101 = V_100 -> V_70 . V_12 ;
if ( ! V_101 )
return;
F_27 ( & V_101 -> V_95 ) ;
}
void F_28 ( struct V_3 * V_100 )
{
struct V_66 * V_101 = V_100 -> V_70 . V_12 ;
while ( V_101 && F_29 ( & V_101 -> V_95 ) ) {
struct V_66 * V_102 = V_101 ;
V_101 = V_101 -> V_72 ;
F_20 ( V_102 ) ;
}
}
static void F_30 ( int V_65 , int V_103 )
{
struct V_104 V_105 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_106 = V_107 ;
V_105 . V_108 = V_109 ;
V_105 . V_110 = ( void T_3 * ) F_6 ( V_5 ) ;
V_105 . V_111 = V_103 ;
V_105 . V_112 = F_4 () ;
V_105 . V_113 = V_65 ;
F_31 ( V_107 , & V_105 , V_5 ) ;
}
int F_32 ( int V_114 )
{
int V_115 = V_5 -> V_70 . V_115 ;
int V_116 = 0 ;
int * V_65 ;
T_2 V_68 ;
switch ( V_115 ) {
case V_117 :
V_65 = V_118 ;
#ifdef F_23
if ( F_24 () )
V_65 = V_119 ;
#endif
do {
if ( * V_65 == V_114 )
return 0 ;
} while ( * ++ V_65 );
V_116 = V_120 ;
V_68 = V_71 ;
break;
#ifdef F_33
case V_121 : {
int V_122 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
V_68 = F_9 ( V_114 ) ;
V_122 = V_68 & V_123 ;
V_68 &= V_75 ;
switch ( V_68 ) {
case V_124 :
F_34 ( V_5 , V_7 ,
- V_122 , 0 ) ;
goto V_125;
case V_126 :
F_35 ( V_5 , V_7 ) ;
F_30 ( V_114 , V_122 ) ;
goto V_125;
case V_127 :
if ( ! F_36 ( V_5 , V_128 ) ) {
F_34 ( V_5 , V_7 ,
- V_129 , 0 ) ;
goto V_125;
}
F_37 ( V_128 , V_122 ) ;
if ( F_38 ( V_5 ) )
break;
if ( F_3 ( V_5 , V_7 ) < 0 )
goto V_125;
return 0 ;
case V_69 :
return 0 ;
case V_71 :
default:
break;
}
V_116 = V_107 ;
break;
}
#endif
default:
F_39 () ;
}
#ifdef F_40
F_41 () ;
#endif
F_42 ( V_114 , V_116 , V_68 ) ;
F_43 ( V_116 ) ;
#ifdef F_33
V_125:
F_42 ( V_114 , V_116 , V_68 ) ;
#endif
return - 1 ;
}
long F_44 ( void )
{
return V_5 -> V_70 . V_115 ;
}
long F_45 ( unsigned long V_130 , char T_3 * V_12 )
{
long V_68 = - V_22 ;
if ( V_5 -> V_70 . V_115 &&
V_5 -> V_70 . V_115 != V_130 )
goto V_99;
switch ( V_130 ) {
case V_117 :
V_68 = 0 ;
#ifdef F_46
F_47 () ;
#endif
break;
#ifdef F_33
case V_121 :
V_68 = F_22 ( V_12 ) ;
if ( V_68 )
goto V_99;
break;
#endif
default:
goto V_99;
}
V_5 -> V_70 . V_115 = V_130 ;
F_48 ( V_131 ) ;
V_99:
return V_68 ;
}
