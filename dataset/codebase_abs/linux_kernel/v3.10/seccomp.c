static inline T_1 F_1 ( T_2 V_1 , int V_2 )
{
return ( ( T_1 * ) & V_1 ) [ V_2 ] ;
}
T_1 F_2 ( int V_3 )
{
struct V_4 * V_5 = F_3 ( V_6 ) ;
if ( V_3 == F_4 ( V_7 ) )
return F_5 ( V_6 , V_5 ) ;
if ( V_3 == F_4 ( V_8 ) )
return F_6 ( V_6 , V_5 ) ;
if ( V_3 >= F_4 ( args [ 0 ] ) && V_3 < F_4 ( args [ 6 ] ) ) {
unsigned long V_9 ;
int V_10 = ( V_3 - F_4 ( args [ 0 ] ) ) / sizeof( T_2 ) ;
int V_2 = ! ! ( V_3 % sizeof( T_2 ) ) ;
F_7 ( V_6 , V_5 , V_10 , 1 , & V_9 ) ;
return F_1 ( V_9 , V_2 ) ;
}
if ( V_3 == F_4 ( V_11 ) )
return F_1 ( F_8 ( V_6 ) , 0 ) ;
if ( V_3 == F_4 ( V_11 ) + sizeof( T_1 ) )
return F_1 ( F_8 ( V_6 ) , 1 ) ;
F_9 () ;
}
static int F_10 ( struct V_12 * V_13 , unsigned int V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
struct V_12 * V_16 = & V_13 [ V_15 ] ;
T_3 V_17 = V_16 -> V_17 ;
T_1 V_18 = V_16 -> V_18 ;
switch ( V_17 ) {
case V_19 :
V_16 -> V_17 = V_20 ;
if ( V_18 >= sizeof( struct V_21 ) || V_18 & 3 )
return - V_22 ;
continue;
case V_23 :
V_16 -> V_17 = V_24 ;
V_16 -> V_18 = sizeof( struct V_21 ) ;
continue;
case V_25 :
V_16 -> V_17 = V_26 ;
V_16 -> V_18 = sizeof( struct V_21 ) ;
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
case V_24 :
case V_26 :
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
continue;
default:
return - V_22 ;
}
}
return 0 ;
}
static T_1 F_11 ( int V_63 )
{
struct V_64 * V_65 ;
T_1 V_66 = V_67 ;
if ( F_12 ( V_6 -> V_68 . V_13 == NULL ) )
return V_69 ;
for ( V_65 = V_6 -> V_68 . V_13 ; V_65 ; V_65 = V_65 -> V_70 ) {
T_1 V_71 = F_13 ( NULL , V_65 -> V_72 ) ;
if ( ( V_71 & V_73 ) < ( V_66 & V_73 ) )
V_66 = V_71 ;
}
return V_66 ;
}
static long F_14 ( struct V_74 * V_75 )
{
struct V_64 * V_13 ;
unsigned long V_76 = V_75 -> V_77 * sizeof( struct V_12 ) ;
unsigned long V_78 = V_75 -> V_77 ;
long V_66 ;
if ( V_75 -> V_77 == 0 || V_75 -> V_77 > V_79 )
return - V_22 ;
for ( V_13 = V_6 -> V_68 . V_13 ; V_13 ; V_13 = V_13 -> V_70 )
V_78 += V_13 -> V_77 + 4 ;
if ( V_78 > V_80 )
return - V_81 ;
if ( ! V_6 -> V_82 &&
F_15 ( F_16 () , F_17 () ,
V_83 ) != 0 )
return - V_84 ;
V_13 = F_18 ( sizeof( struct V_64 ) + V_76 ,
V_85 | V_86 ) ;
if ( ! V_13 )
return - V_81 ;
F_19 ( & V_13 -> V_87 , 1 ) ;
V_13 -> V_77 = V_75 -> V_77 ;
V_66 = - V_88 ;
if ( F_20 ( V_13 -> V_72 , V_75 -> V_13 , V_76 ) )
goto V_89;
V_66 = F_21 ( V_13 -> V_72 , V_13 -> V_77 ) ;
if ( V_66 )
goto V_89;
V_66 = F_10 ( V_13 -> V_72 , V_13 -> V_77 ) ;
if ( V_66 )
goto V_89;
V_13 -> V_70 = V_6 -> V_68 . V_13 ;
V_6 -> V_68 . V_13 = V_13 ;
return 0 ;
V_89:
F_22 ( V_13 ) ;
return V_66 ;
}
long F_23 ( char T_4 * V_90 )
{
struct V_74 V_75 ;
long V_66 = - V_88 ;
#ifdef F_24
if ( F_25 () ) {
struct V_91 V_92 ;
if ( F_20 ( & V_92 , V_90 , sizeof( V_92 ) ) )
goto V_93;
V_75 . V_77 = V_92 . V_77 ;
V_75 . V_13 = F_26 ( V_92 . V_13 ) ;
} else
#endif
if ( F_20 ( & V_75 , V_90 , sizeof( V_75 ) ) )
goto V_93;
V_66 = F_14 ( & V_75 ) ;
V_93:
return V_66 ;
}
void F_27 ( struct V_94 * V_95 )
{
struct V_64 * V_96 = V_95 -> V_68 . V_13 ;
if ( ! V_96 )
return;
F_28 ( & V_96 -> V_87 ) ;
}
void F_29 ( struct V_94 * V_95 )
{
struct V_64 * V_96 = V_95 -> V_68 . V_13 ;
while ( V_96 && F_30 ( & V_96 -> V_87 ) ) {
struct V_64 * V_97 = V_96 ;
V_96 = V_96 -> V_70 ;
F_22 ( V_97 ) ;
}
}
static void F_31 ( int V_63 , int V_98 )
{
struct V_99 V_100 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_101 = V_102 ;
V_100 . V_103 = V_104 ;
V_100 . V_105 = ( void T_4 * ) F_8 ( V_6 ) ;
V_100 . V_106 = V_98 ;
V_100 . V_107 = F_6 ( V_6 , F_3 ( V_6 ) ) ;
V_100 . V_108 = V_63 ;
F_32 ( V_102 , & V_100 , V_6 ) ;
}
int F_33 ( int V_109 )
{
int V_110 = V_6 -> V_68 . V_110 ;
int V_111 = 0 ;
int * V_63 ;
T_1 V_66 ;
switch ( V_110 ) {
case V_112 :
V_63 = V_113 ;
#ifdef F_24
if ( F_25 () )
V_63 = V_114 ;
#endif
do {
if ( * V_63 == V_109 )
return 0 ;
} while ( * ++ V_63 );
V_111 = V_115 ;
V_66 = V_69 ;
break;
#ifdef F_34
case V_116 : {
int V_1 ;
struct V_4 * V_5 = F_3 ( V_6 ) ;
V_66 = F_11 ( V_109 ) ;
V_1 = V_66 & V_117 ;
V_66 &= V_73 ;
switch ( V_66 ) {
case V_118 :
F_35 ( V_6 , V_5 ,
- V_1 , 0 ) ;
goto V_119;
case V_120 :
F_36 ( V_6 , V_5 ) ;
F_31 ( V_109 , V_1 ) ;
goto V_119;
case V_121 :
if ( ! F_37 ( V_6 , V_122 ) ) {
F_35 ( V_6 , V_5 ,
- V_123 , 0 ) ;
goto V_119;
}
F_38 ( V_122 , V_1 ) ;
if ( F_39 ( V_6 ) )
break;
if ( F_5 ( V_6 , V_5 ) < 0 )
goto V_119;
return 0 ;
case V_67 :
return 0 ;
case V_69 :
default:
break;
}
V_111 = V_102 ;
break;
}
#endif
default:
F_9 () ;
}
#ifdef F_40
F_41 () ;
#endif
F_42 ( V_109 , V_111 , V_66 ) ;
F_43 ( V_111 ) ;
#ifdef F_34
V_119:
F_42 ( V_109 , V_111 , V_66 ) ;
#endif
return - 1 ;
}
long F_44 ( void )
{
return V_6 -> V_68 . V_110 ;
}
long F_45 ( unsigned long V_124 , char T_4 * V_13 )
{
long V_66 = - V_22 ;
if ( V_6 -> V_68 . V_110 &&
V_6 -> V_68 . V_110 != V_124 )
goto V_93;
switch ( V_124 ) {
case V_112 :
V_66 = 0 ;
#ifdef F_46
F_47 () ;
#endif
break;
#ifdef F_34
case V_116 :
V_66 = F_23 ( V_13 ) ;
if ( V_66 )
goto V_93;
break;
#endif
default:
goto V_93;
}
V_6 -> V_68 . V_110 = V_124 ;
F_48 ( V_125 ) ;
V_93:
return V_66 ;
}
