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
case V_18 | V_19 | V_20 :
V_15 -> V_16 = V_21 | V_19 | V_20 ;
if ( V_17 >= sizeof( struct V_1 ) || V_17 & 3 )
return - V_22 ;
continue;
case V_18 | V_19 | V_23 :
V_15 -> V_16 = V_18 | V_24 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_21 | V_19 | V_23 :
V_15 -> V_16 = V_21 | V_24 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_25 | V_26 :
case V_25 | V_27 :
case V_28 | V_29 | V_26 :
case V_28 | V_29 | V_30 :
case V_28 | V_31 | V_26 :
case V_28 | V_31 | V_30 :
case V_28 | V_32 | V_26 :
case V_28 | V_32 | V_30 :
case V_28 | V_33 | V_26 :
case V_28 | V_33 | V_30 :
case V_28 | V_34 | V_26 :
case V_28 | V_34 | V_30 :
case V_28 | V_35 | V_26 :
case V_28 | V_35 | V_30 :
case V_28 | V_36 | V_26 :
case V_28 | V_36 | V_30 :
case V_28 | V_37 | V_26 :
case V_28 | V_37 | V_30 :
case V_28 | V_38 | V_26 :
case V_28 | V_38 | V_30 :
case V_28 | V_39 :
case V_18 | V_24 :
case V_21 | V_24 :
case V_40 | V_41 :
case V_40 | V_42 :
case V_18 | V_43 :
case V_21 | V_43 :
case V_44 :
case V_45 :
case V_46 | V_47 :
case V_46 | V_48 | V_26 :
case V_46 | V_48 | V_30 :
case V_46 | V_49 | V_26 :
case V_46 | V_49 | V_30 :
case V_46 | V_50 | V_26 :
case V_46 | V_50 | V_30 :
case V_46 | V_51 | V_26 :
case V_46 | V_51 | V_30 :
continue;
default:
return - V_22 ;
}
}
return 0 ;
}
static T_2 F_8 ( int V_52 )
{
struct V_53 * V_54 ;
struct V_1 V_2 ;
T_2 V_55 = V_56 ;
if ( F_9 ( V_5 -> V_57 . V_12 == NULL ) )
return V_58 ;
F_1 ( & V_2 ) ;
for ( V_54 = V_5 -> V_57 . V_12 ; V_54 ; V_54 = V_54 -> V_59 ) {
T_2 V_60 = F_10 ( V_54 -> V_61 , ( void * ) & V_2 ) ;
if ( ( V_60 & V_62 ) < ( V_55 & V_62 ) )
V_55 = V_60 ;
}
return V_55 ;
}
static long F_11 ( struct V_63 * V_64 )
{
struct V_53 * V_12 ;
unsigned long V_65 = V_64 -> V_66 * sizeof( struct V_11 ) ;
unsigned long V_67 = V_64 -> V_66 ;
struct V_11 * V_68 ;
int V_69 ;
long V_55 ;
if ( V_64 -> V_66 == 0 || V_64 -> V_66 > V_70 )
return - V_22 ;
for ( V_12 = V_5 -> V_57 . V_12 ; V_12 ; V_12 = V_12 -> V_59 )
V_67 += V_12 -> V_61 -> V_66 + 4 ;
if ( V_67 > V_71 )
return - V_72 ;
if ( ! V_5 -> V_73 &&
F_12 ( F_13 () , F_14 () ,
V_74 ) != 0 )
return - V_75 ;
V_68 = F_15 ( V_65 , V_76 | V_77 ) ;
if ( ! V_68 )
return - V_72 ;
V_55 = - V_78 ;
if ( F_16 ( V_68 , V_64 -> V_12 , V_65 ) )
goto V_79;
V_55 = F_17 ( V_68 , V_64 -> V_66 ) ;
if ( V_55 )
goto V_79;
V_55 = F_7 ( V_68 , V_64 -> V_66 ) ;
if ( V_55 )
goto V_79;
V_55 = F_18 ( V_68 , V_64 -> V_66 , NULL , & V_69 ) ;
if ( V_55 )
goto V_79;
V_55 = - V_72 ;
V_12 = F_15 ( sizeof( struct V_53 ) ,
V_76 | V_77 ) ;
if ( ! V_12 )
goto V_79;
V_12 -> V_61 = F_15 ( F_19 ( V_69 ) ,
V_76 | V_77 ) ;
if ( ! V_12 -> V_61 )
goto V_80;
V_55 = F_18 ( V_68 , V_64 -> V_66 , V_12 -> V_61 -> V_81 , & V_69 ) ;
if ( V_55 )
goto V_82;
F_20 ( V_68 ) ;
F_21 ( & V_12 -> V_83 , 1 ) ;
V_12 -> V_61 -> V_66 = V_69 ;
F_22 ( V_12 -> V_61 ) ;
V_12 -> V_59 = V_5 -> V_57 . V_12 ;
V_5 -> V_57 . V_12 = V_12 ;
return 0 ;
V_82:
F_20 ( V_12 -> V_61 ) ;
V_80:
F_20 ( V_12 ) ;
V_79:
F_20 ( V_68 ) ;
return V_55 ;
}
static long F_23 ( char T_3 * V_84 )
{
struct V_63 V_64 ;
long V_55 = - V_78 ;
#ifdef F_24
if ( F_25 () ) {
struct V_85 V_86 ;
if ( F_16 ( & V_86 , V_84 , sizeof( V_86 ) ) )
goto V_87;
V_64 . V_66 = V_86 . V_66 ;
V_64 . V_12 = F_26 ( V_86 . V_12 ) ;
} else
#endif
if ( F_16 ( & V_64 , V_84 , sizeof( V_64 ) ) )
goto V_87;
V_55 = F_11 ( & V_64 ) ;
V_87:
return V_55 ;
}
void F_27 ( struct V_3 * V_88 )
{
struct V_53 * V_89 = V_88 -> V_57 . V_12 ;
if ( ! V_89 )
return;
F_28 ( & V_89 -> V_83 ) ;
}
void F_29 ( struct V_3 * V_88 )
{
struct V_53 * V_89 = V_88 -> V_57 . V_12 ;
while ( V_89 && F_30 ( & V_89 -> V_83 ) ) {
struct V_53 * V_90 = V_89 ;
V_89 = V_89 -> V_59 ;
F_31 ( V_90 -> V_61 ) ;
F_20 ( V_90 ) ;
}
}
static void F_32 ( int V_52 , int V_91 )
{
struct V_92 V_93 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_94 = V_95 ;
V_93 . V_96 = V_97 ;
V_93 . V_98 = ( void T_3 * ) F_6 ( V_5 ) ;
V_93 . V_99 = V_91 ;
V_93 . V_100 = F_4 () ;
V_93 . V_101 = V_52 ;
F_33 ( V_95 , & V_93 , V_5 ) ;
}
int F_34 ( int V_102 )
{
int V_103 = V_5 -> V_57 . V_103 ;
int V_104 = 0 ;
int * V_52 ;
T_2 V_55 ;
switch ( V_103 ) {
case V_105 :
V_52 = V_106 ;
#ifdef F_24
if ( F_25 () )
V_52 = V_107 ;
#endif
do {
if ( * V_52 == V_102 )
return 0 ;
} while ( * ++ V_52 );
V_104 = V_108 ;
V_55 = V_58 ;
break;
#ifdef F_35
case V_109 : {
int V_110 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
V_55 = F_8 ( V_102 ) ;
V_110 = V_55 & V_111 ;
V_55 &= V_62 ;
switch ( V_55 ) {
case V_112 :
F_36 ( V_5 , V_7 ,
- V_110 , 0 ) ;
goto V_113;
case V_114 :
F_37 ( V_5 , V_7 ) ;
F_32 ( V_102 , V_110 ) ;
goto V_113;
case V_115 :
if ( ! F_38 ( V_5 , V_116 ) ) {
F_36 ( V_5 , V_7 ,
- V_117 , 0 ) ;
goto V_113;
}
F_39 ( V_116 , V_110 ) ;
if ( F_40 ( V_5 ) )
break;
if ( F_3 ( V_5 , V_7 ) < 0 )
goto V_113;
return 0 ;
case V_56 :
return 0 ;
case V_58 :
default:
break;
}
V_104 = V_95 ;
break;
}
#endif
default:
F_41 () ;
}
#ifdef F_42
F_43 () ;
#endif
F_44 ( V_102 , V_104 , V_55 ) ;
F_45 ( V_104 ) ;
#ifdef F_35
V_113:
F_44 ( V_102 , V_104 , V_55 ) ;
#endif
return - 1 ;
}
long F_46 ( void )
{
return V_5 -> V_57 . V_103 ;
}
long F_47 ( unsigned long V_118 , char T_3 * V_12 )
{
long V_55 = - V_22 ;
if ( V_5 -> V_57 . V_103 &&
V_5 -> V_57 . V_103 != V_118 )
goto V_87;
switch ( V_118 ) {
case V_105 :
V_55 = 0 ;
#ifdef F_48
F_49 () ;
#endif
break;
#ifdef F_35
case V_109 :
V_55 = F_23 ( V_12 ) ;
if ( V_55 )
goto V_87;
break;
#endif
default:
goto V_87;
}
V_5 -> V_57 . V_103 = V_118 ;
F_50 ( V_119 ) ;
V_87:
return V_55 ;
}
