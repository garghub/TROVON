static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_3 = 0 ;
return 0 ;
}
int __weak F_3 ( struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_4 ( V_5 -> V_7 , ( char * ) V_5 -> V_8 ,
V_9 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_5 ( ( char * ) V_5 -> V_8 ,
V_10 . V_11 , V_9 ) ;
return V_6 ;
}
int __weak F_6 ( struct V_4 * V_5 )
{
return F_5 ( ( char * ) V_5 -> V_8 ,
( char * ) V_5 -> V_7 , V_9 ) ;
}
int __weak F_7 ( unsigned long V_12 )
{
struct V_4 V_13 ;
int V_6 ;
V_13 . V_8 = V_12 ;
V_6 = F_3 ( & V_13 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( & V_13 ) ;
if ( V_6 )
F_8 ( L_1 ,
V_12 ) ;
return V_6 ;
}
unsigned long __weak F_9 ( int V_14 , struct V_15 * V_16 )
{
return F_10 ( V_16 ) ;
}
int __weak F_11 ( void )
{
return 0 ;
}
int __weak F_12 ( int V_14 , struct V_15 * V_16 )
{
return 0 ;
}
static void F_13 ( unsigned long V_12 )
{
if ( ! V_17 )
return;
if ( V_18 -> V_19 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( ! V_18 -> V_22 . V_23 [ V_20 ] )
continue;
F_14 ( V_18 -> V_22 . V_23 [ V_20 ] ,
V_12 , V_12 + V_9 ) ;
}
}
F_15 ( V_12 , V_12 + V_9 ) ;
}
int F_16 ( void )
{
int error ;
int V_24 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( V_26 [ V_20 ] . V_27 != V_28 )
continue;
error = F_3 ( & V_26 [ V_20 ] ) ;
if ( error ) {
V_24 = error ;
F_17 ( L_2 ,
V_26 [ V_20 ] . V_8 ) ;
continue;
}
F_13 ( V_26 [ V_20 ] . V_8 ) ;
V_26 [ V_20 ] . V_27 = V_29 ;
}
return V_24 ;
}
int F_18 ( unsigned long V_12 )
{
int V_6 = F_7 ( V_12 ) ;
int V_30 = - 1 ;
int V_20 ;
if ( V_6 )
return V_6 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( ( V_26 [ V_20 ] . V_27 == V_28 ) &&
( V_26 [ V_20 ] . V_8 == V_12 ) )
return - V_31 ;
}
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( V_26 [ V_20 ] . V_27 == V_32 &&
V_26 [ V_20 ] . V_8 == V_12 ) {
V_30 = V_20 ;
break;
}
}
if ( V_30 == - 1 ) {
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( V_26 [ V_20 ] . V_27 == V_33 ) {
V_30 = V_20 ;
break;
}
}
}
if ( V_30 == - 1 )
return - V_34 ;
V_26 [ V_30 ] . V_27 = V_28 ;
V_26 [ V_30 ] . type = V_35 ;
V_26 [ V_30 ] . V_8 = V_12 ;
return 0 ;
}
int F_19 ( void )
{
int error ;
int V_24 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( V_26 [ V_20 ] . V_27 != V_29 )
continue;
error = F_6 ( & V_26 [ V_20 ] ) ;
if ( error ) {
F_17 ( L_3 ,
V_26 [ V_20 ] . V_8 ) ;
V_24 = error ;
}
F_13 ( V_26 [ V_20 ] . V_8 ) ;
V_26 [ V_20 ] . V_27 = V_28 ;
}
return V_24 ;
}
int F_20 ( unsigned long V_12 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( ( V_26 [ V_20 ] . V_27 == V_28 ) &&
( V_26 [ V_20 ] . V_8 == V_12 ) ) {
V_26 [ V_20 ] . V_27 = V_32 ;
return 0 ;
}
}
return - V_36 ;
}
int F_21 ( unsigned long V_12 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( ( V_26 [ V_20 ] . V_27 == V_32 ) &&
( V_26 [ V_20 ] . V_8 == V_12 ) )
return 1 ;
}
return 0 ;
}
int F_22 ( void )
{
int error ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( V_26 [ V_20 ] . V_27 != V_29 )
goto V_37;
error = F_6 ( & V_26 [ V_20 ] ) ;
if ( error )
F_8 ( L_4 ,
V_26 [ V_20 ] . V_8 ) ;
V_37:
V_26 [ V_20 ] . V_27 = V_33 ;
}
if ( V_10 . V_38 )
V_10 . V_38 () ;
return 0 ;
}
static int F_23 ( int V_39 )
{
if ( ! V_40 )
return 0 ;
if ( V_41 )
return 1 ;
if ( F_24 ( & V_42 ) )
return 1 ;
if ( V_39 ) {
#ifdef F_25
if ( ! V_43 )
F_26 ( L_5 ) ;
#else
F_26 ( L_6 ) ;
#endif
}
return 1 ;
}
static int F_27 ( struct V_44 * V_45 )
{
unsigned long V_12 ;
if ( F_24 ( & V_46 ) != F_28 () )
return 0 ;
V_47 ++ ;
V_12 = F_9 ( V_45 -> V_48 , V_45 -> V_49 ) ;
F_19 () ;
if ( F_20 ( V_12 ) == 0 ) {
V_47 = 0 ;
F_12 ( V_45 -> V_48 , V_45 -> V_49 ) ;
F_16 () ;
F_26 ( L_7 , V_12 ) ;
F_29 ( 1 ) ;
return 1 ;
}
F_22 () ;
F_12 ( V_45 -> V_48 , V_45 -> V_49 ) ;
if ( V_47 > 1 ) {
F_30 () ;
F_31 ( L_8 ) ;
}
F_26 ( L_9 ) ;
#ifdef F_25
return 0 ;
#endif
F_30 () ;
F_31 ( L_8 ) ;
return 1 ;
}
static void F_32 ( void )
{
F_33 () ;
F_34 () ;
F_35 () ;
}
static int F_36 ( struct V_44 * V_45 , struct V_15 * V_16 ,
int V_50 )
{
unsigned long V_51 ;
int V_52 = 100 ;
int error ;
int V_53 ;
int V_54 = 0 ;
int V_55 = F_37 () ;
T_2 V_56 ;
V_57 [ V_45 -> V_53 ] . V_58 ++ ;
V_57 [ V_45 -> V_53 ] . V_50 |= V_50 ;
if ( V_50 == V_59 )
F_38 ( & V_60 ) ;
else
F_38 ( & V_61 ) ;
if ( V_10 . V_62 )
V_10 . V_62 ( V_16 ) ;
V_63:
F_39 ( V_51 ) ;
V_53 = V_45 -> V_53 ;
V_57 [ V_53 ] . V_64 = V_16 ;
V_57 [ V_53 ] . V_65 = V_18 ;
V_57 [ V_53 ] . V_66 = 0 ;
V_57 [ V_53 ] . V_67 = F_40 () >> V_68 ;
F_41 () ;
if ( V_47 == 1 ) {
if ( F_42 ( & V_69 ) )
F_43 ( & V_46 , V_53 ) ;
goto V_70;
}
while ( 1 ) {
V_71:
if ( V_57 [ V_53 ] . V_50 & V_72 ) {
V_57 [ V_53 ] . V_50 &= ~ V_72 ;
goto V_70;
} else if ( V_57 [ V_53 ] . V_50 & V_59 ) {
if ( F_42 ( & V_69 ) ) {
F_43 ( & V_46 , V_53 ) ;
break;
}
} else if ( V_57 [ V_53 ] . V_50 & V_73 ) {
if ( ! F_44 ( & V_74 ) )
goto V_75;
} else {
V_75:
if ( V_10 . V_76 )
V_10 . V_76 () ;
if ( V_54 )
F_45 () ;
V_57 [ V_53 ] . V_50 &=
~ ( V_59 | V_73 ) ;
V_57 [ V_53 ] . V_58 -- ;
F_46 () ;
F_47 ( & V_61 ) ;
F_32 () ;
F_48 ( V_51 ) ;
return 0 ;
}
F_49 () ;
}
if ( F_24 ( & V_77 ) != - 1 &&
( V_57 [ V_53 ] . V_65 &&
V_57 [ V_53 ] . V_65 -> V_78 != V_79 ) && -- V_52 ) {
F_50 ( & V_46 , - 1 ) ;
F_51 ( & V_69 ) ;
F_32 () ;
F_48 ( V_51 ) ;
goto V_63;
}
if ( ! F_23 ( 1 ) ) {
V_57 [ V_53 ] . V_66 = 1 ;
goto V_80;
}
if ( F_12 ( V_45 -> V_48 , V_45 -> V_49 ) )
goto V_80;
if ( V_40 -> V_81 )
V_40 -> V_81 () ;
if ( ! V_82 )
F_52 ( & V_74 ) ;
#ifdef F_53
if ( V_45 -> V_83 )
F_50 ( V_45 -> V_83 , 1 ) ;
else if ( ( ! V_82 ) && V_3 )
F_54 ( V_51 ) ;
#endif
V_56 = V_84 ;
while ( V_3 && -- V_56 &&
( F_24 ( & V_60 ) + F_24 ( & V_61 ) ) !=
V_55 )
F_55 ( 1000 ) ;
if ( ! V_56 )
F_26 ( L_10 ) ;
F_19 () ;
V_82 = 0 ;
V_85 = V_18 ;
V_47 = 0 ;
V_54 = F_56 () ;
if ( V_54 )
F_57 () ;
while ( 1 ) {
V_70:
if ( V_43 ) {
V_41 = 1 ;
error = F_58 ( V_45 ) ;
if ( error == - 1 )
continue;
V_41 = 0 ;
} else {
error = F_59 ( V_45 ) ;
}
if ( error == V_86 ) {
V_43 = ! V_43 ;
} else if ( error == V_87 ) {
V_57 [ V_88 ] . V_50 |=
V_72 ;
goto V_71;
} else {
V_57 [ V_53 ] . V_66 = error ;
break;
}
}
if ( V_40 -> V_89 )
V_40 -> V_89 () ;
if ( ! V_82 ) {
F_51 ( & V_74 ) ;
while ( V_3 && F_24 ( & V_61 ) )
F_49 () ;
}
V_80:
if ( F_24 ( & V_77 ) != - 1 ) {
int V_90 = F_24 ( & V_77 ) ;
if ( V_57 [ V_90 ] . V_65 )
V_79 = V_57 [ V_90 ] . V_65 -> V_78 ;
else
V_79 = 0 ;
}
if ( V_10 . V_76 )
V_10 . V_76 () ;
if ( V_54 )
F_45 () ;
V_57 [ V_53 ] . V_50 &=
~ ( V_59 | V_73 ) ;
V_57 [ V_53 ] . V_58 -- ;
F_46 () ;
F_47 ( & V_60 ) ;
F_50 ( & V_46 , - 1 ) ;
F_51 ( & V_69 ) ;
F_32 () ;
F_48 ( V_51 ) ;
return V_57 [ V_53 ] . V_66 ;
}
int
F_60 ( int V_91 , int V_92 , int V_93 , struct V_15 * V_16 )
{
struct V_44 V_94 ;
struct V_44 * V_45 = & V_94 ;
int V_24 = 0 ;
if ( V_10 . V_95 )
V_10 . V_95 ( 0 ) ;
if ( V_92 != V_96 && V_97 )
return 1 ;
memset ( V_45 , 0 , sizeof( struct V_44 ) ) ;
V_45 -> V_53 = F_28 () ;
V_45 -> V_48 = V_91 ;
V_45 -> V_92 = V_92 ;
V_45 -> V_98 = V_93 ;
V_45 -> V_49 = V_16 ;
if ( F_27 ( V_45 ) )
goto V_99;
if ( V_57 [ V_45 -> V_53 ] . V_58 != 0 )
goto V_99;
V_24 = F_36 ( V_45 , V_16 , V_59 ) ;
V_99:
if ( V_10 . V_95 )
V_10 . V_95 ( 1 ) ;
return V_24 ;
}
static int F_61 ( struct V_100 * V_101 , unsigned long V_102 ,
void * V_103 )
{
return 0 ;
}
int F_62 ( int V_53 , void * V_16 )
{
#ifdef F_53
struct V_44 V_94 ;
struct V_44 * V_45 = & V_94 ;
memset ( V_45 , 0 , sizeof( struct V_44 ) ) ;
V_45 -> V_53 = V_53 ;
V_45 -> V_49 = V_16 ;
if ( V_57 [ V_45 -> V_53 ] . V_58 == 0 &&
F_44 ( & V_69 ) ) {
F_36 ( V_45 , V_16 , V_73 ) ;
return 0 ;
}
#endif
return 1 ;
}
int F_63 ( int V_53 , int V_104 , void * V_16 , int V_98 ,
T_3 * V_83 )
{
#ifdef F_53
if ( ! F_23 ( 0 ) || ! V_83 )
return 1 ;
if ( V_57 [ V_53 ] . V_58 == 0 ) {
struct V_44 V_94 ;
struct V_44 * V_45 = & V_94 ;
memset ( V_45 , 0 , sizeof( struct V_44 ) ) ;
V_45 -> V_53 = V_53 ;
V_45 -> V_48 = V_104 ;
V_45 -> V_92 = V_96 ;
V_45 -> V_98 = V_98 ;
V_45 -> V_49 = V_16 ;
V_45 -> V_83 = V_83 ;
F_36 ( V_45 , V_16 , V_59 ) ;
return 0 ;
}
#endif
return 1 ;
}
static void F_64 ( struct V_105 * V_106 , const char * V_107 ,
unsigned V_108 )
{
unsigned long V_51 ;
if ( ! V_41 || F_24 ( & V_46 ) != - 1 || V_43 )
return;
F_39 ( V_51 ) ;
F_65 ( V_107 , V_108 ) ;
F_48 ( V_51 ) ;
}
static void F_66 ( int V_109 )
{
if ( ! V_40 ) {
F_26 ( L_11 ) ;
return;
}
if ( ! V_41 ) {
#ifdef F_25
if ( ! V_43 )
F_26 ( L_12 ) ;
#else
F_26 ( L_13 ) ;
#endif
}
F_67 () ;
}
static int F_68 ( struct V_100 * V_101 ,
unsigned long V_102 ,
void * V_103 )
{
if ( V_97 )
return V_110 ;
if ( V_43 )
F_69 ( L_14 , ( char * ) V_103 ) ;
F_67 () ;
return V_110 ;
}
void __weak F_70 ( void )
{
}
void T_1 F_71 ( void )
{
V_111 = false ;
if ( V_112 )
F_70 () ;
F_72 ( V_113 ) ;
}
static int
F_73 ( struct V_100 * V_114 , unsigned long V_115 , void * V_116 )
{
switch ( V_117 ) {
case 1 :
F_67 () ;
case - 1 :
goto V_118;
}
if ( ! V_43 )
F_74 ( V_115 ) ;
V_118:
return V_110 ;
}
static void F_75 ( void )
{
if ( ! V_112 ) {
V_112 = 1 ;
F_11 () ;
if ( ! V_111 )
F_70 () ;
F_76 ( & V_119 ) ;
F_77 ( & V_120 ) ;
F_78 ( & V_121 ,
& V_122 ) ;
#ifdef F_79
F_80 ( 'g' , & V_123 ) ;
#endif
if ( V_2 && ! V_124 ) {
F_81 ( & V_125 ) ;
V_124 = 1 ;
}
}
}
static void F_82 ( void )
{
if ( V_112 ) {
V_112 = 0 ;
F_83 ( & V_120 ) ;
F_84 ( & V_119 ) ;
F_85 ( & V_121 ,
& V_122 ) ;
F_86 () ;
#ifdef F_79
F_87 ( 'g' , & V_123 ) ;
#endif
if ( V_124 ) {
F_88 ( & V_125 ) ;
V_124 = 0 ;
}
}
}
static void F_89 ( unsigned long V_126 )
{
F_67 () ;
F_50 ( & V_127 , 0 ) ;
}
void F_90 ( void )
{
if ( F_24 ( & V_127 ) ||
F_24 ( & V_46 ) != - 1 ||
F_24 ( & V_42 ) )
return;
F_38 ( & V_127 ) ;
F_91 ( & V_128 ) ;
}
static void F_92 ( void )
{
V_129 = 0 ;
F_26 ( L_15 ) ;
F_67 () ;
}
int F_93 ( struct V_130 * V_131 )
{
int V_6 ;
F_94 ( & V_132 ) ;
if ( V_40 ) {
F_95 ( & V_132 ) ;
F_8 ( L_16 ) ;
return - V_133 ;
}
if ( V_131 -> V_134 ) {
V_6 = V_131 -> V_134 () ;
if ( V_6 ) {
F_95 ( & V_132 ) ;
return V_6 ;
}
}
V_40 = V_131 ;
F_95 ( & V_132 ) ;
F_17 ( L_17 , V_131 -> V_135 ) ;
F_75 () ;
if ( V_129 )
F_92 () ;
return 0 ;
}
void F_96 ( struct V_130 * V_136 )
{
F_97 ( V_41 ) ;
F_82 () ;
F_94 ( & V_132 ) ;
F_29 ( V_40 != V_136 ) ;
V_40 = NULL ;
F_95 ( & V_132 ) ;
F_17 ( L_18 ,
V_136 -> V_135 ) ;
}
int F_98 ( void )
{
int V_24 = V_40 -> V_137 () ;
if ( V_24 == V_138 )
return - 1 ;
if ( ! V_43 )
return V_24 ;
if ( V_24 == 127 )
return 8 ;
return V_24 ;
}
T_4 void F_67 ( void )
{
F_38 ( & V_42 ) ;
F_99 () ;
F_100 () ;
F_99 () ;
F_47 ( & V_42 ) ;
}
static int T_1 F_101 ( char * V_1 )
{
V_129 = 1 ;
F_72 ( V_139 ) ;
if ( V_112 )
F_92 () ;
return 0 ;
}
