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
case V_24 :
case V_26 :
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
continue;
default:
return - V_22 ;
}
}
return 0 ;
}
static T_1 F_11 ( int V_61 )
{
struct V_62 * V_63 ;
T_1 V_64 = V_65 ;
if ( F_12 ( V_6 -> V_66 . V_13 == NULL ) )
return V_67 ;
for ( V_63 = V_6 -> V_66 . V_13 ; V_63 ; V_63 = V_63 -> V_68 ) {
T_1 V_69 = F_13 ( NULL , V_63 -> V_70 ) ;
if ( ( V_69 & V_71 ) < ( V_64 & V_71 ) )
V_64 = V_69 ;
}
return V_64 ;
}
static long F_14 ( struct V_72 * V_73 )
{
struct V_62 * V_13 ;
unsigned long V_74 = V_73 -> V_75 * sizeof( struct V_12 ) ;
unsigned long V_76 = V_73 -> V_75 ;
long V_64 ;
if ( V_73 -> V_75 == 0 || V_73 -> V_75 > V_77 )
return - V_22 ;
for ( V_13 = V_6 -> V_66 . V_13 ; V_13 ; V_13 = V_13 -> V_68 )
V_76 += V_13 -> V_75 + 4 ;
if ( V_76 > V_78 )
return - V_79 ;
if ( ! V_6 -> V_80 &&
F_15 ( F_16 () , F_17 () ,
V_81 ) != 0 )
return - V_82 ;
V_13 = F_18 ( sizeof( struct V_62 ) + V_74 ,
V_83 | V_84 ) ;
if ( ! V_13 )
return - V_79 ;
F_19 ( & V_13 -> V_85 , 1 ) ;
V_13 -> V_75 = V_73 -> V_75 ;
V_64 = - V_86 ;
if ( F_20 ( V_13 -> V_70 , V_73 -> V_13 , V_74 ) )
goto V_87;
V_64 = F_21 ( V_13 -> V_70 , V_13 -> V_75 ) ;
if ( V_64 )
goto V_87;
V_64 = F_10 ( V_13 -> V_70 , V_13 -> V_75 ) ;
if ( V_64 )
goto V_87;
V_13 -> V_68 = V_6 -> V_66 . V_13 ;
V_6 -> V_66 . V_13 = V_13 ;
return 0 ;
V_87:
F_22 ( V_13 ) ;
return V_64 ;
}
long F_23 ( char T_4 * V_88 )
{
struct V_72 V_73 ;
long V_64 = - V_86 ;
#ifdef F_24
if ( F_25 () ) {
struct V_89 V_90 ;
if ( F_20 ( & V_90 , V_88 , sizeof( V_90 ) ) )
goto V_91;
V_73 . V_75 = V_90 . V_75 ;
V_73 . V_13 = F_26 ( V_90 . V_13 ) ;
} else
#endif
if ( F_20 ( & V_73 , V_88 , sizeof( V_73 ) ) )
goto V_91;
V_64 = F_14 ( & V_73 ) ;
V_91:
return V_64 ;
}
void F_27 ( struct V_92 * V_93 )
{
struct V_62 * V_94 = V_93 -> V_66 . V_13 ;
if ( ! V_94 )
return;
F_28 ( & V_94 -> V_85 ) ;
}
void F_29 ( struct V_92 * V_93 )
{
struct V_62 * V_94 = V_93 -> V_66 . V_13 ;
while ( V_94 && F_30 ( & V_94 -> V_85 ) ) {
struct V_62 * V_95 = V_94 ;
V_94 = V_94 -> V_68 ;
F_22 ( V_95 ) ;
}
}
static void F_31 ( int V_61 , int V_96 )
{
struct V_97 V_98 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_99 = V_100 ;
V_98 . V_101 = V_102 ;
V_98 . V_103 = ( void T_4 * ) F_8 ( V_6 ) ;
V_98 . V_104 = V_96 ;
V_98 . V_105 = F_6 ( V_6 , F_3 ( V_6 ) ) ;
V_98 . V_106 = V_61 ;
F_32 ( V_100 , & V_98 , V_6 ) ;
}
int F_33 ( int V_107 )
{
int V_108 = V_6 -> V_66 . V_108 ;
int V_109 = 0 ;
int * V_61 ;
T_1 V_64 ;
switch ( V_108 ) {
case V_110 :
V_61 = V_111 ;
#ifdef F_24
if ( F_25 () )
V_61 = V_112 ;
#endif
do {
if ( * V_61 == V_107 )
return 0 ;
} while ( * ++ V_61 );
V_109 = V_113 ;
V_64 = V_67 ;
break;
#ifdef F_34
case V_114 : {
int V_1 ;
V_64 = F_11 ( V_107 ) ;
V_1 = V_64 & V_115 ;
V_64 &= V_71 ;
switch ( V_64 ) {
case V_116 :
F_35 ( V_6 , F_3 ( V_6 ) ,
- V_1 , 0 ) ;
goto V_117;
case V_118 :
F_36 ( V_6 , F_3 ( V_6 ) ) ;
F_31 ( V_107 , V_1 ) ;
goto V_117;
case V_119 :
if ( ! F_37 ( V_6 , V_120 ) )
goto V_117;
F_38 ( V_120 , V_1 ) ;
if ( F_39 ( V_6 ) )
break;
return 0 ;
case V_65 :
return 0 ;
case V_67 :
default:
break;
}
V_109 = V_100 ;
break;
}
#endif
default:
F_9 () ;
}
#ifdef F_40
F_41 () ;
#endif
F_42 ( V_107 , V_109 , V_64 ) ;
F_43 ( V_109 ) ;
#ifdef F_34
V_117:
F_42 ( V_107 , V_109 , V_64 ) ;
#endif
return - 1 ;
}
long F_44 ( void )
{
return V_6 -> V_66 . V_108 ;
}
long F_45 ( unsigned long V_121 , char T_4 * V_13 )
{
long V_64 = - V_22 ;
if ( V_6 -> V_66 . V_108 &&
V_6 -> V_66 . V_108 != V_121 )
goto V_91;
switch ( V_121 ) {
case V_110 :
V_64 = 0 ;
#ifdef F_46
F_47 () ;
#endif
break;
#ifdef F_34
case V_114 :
V_64 = F_23 ( V_13 ) ;
if ( V_64 )
goto V_91;
break;
#endif
default:
goto V_91;
}
V_6 -> V_66 . V_108 = V_121 ;
F_48 ( V_122 ) ;
V_91:
return V_64 ;
}
