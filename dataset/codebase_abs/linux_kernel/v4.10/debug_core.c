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
if ( ! V_18 -> V_22 [ V_20 ] )
continue;
F_14 ( V_18 -> V_22 [ V_20 ] ,
V_12 , V_12 + V_9 ) ;
}
}
F_15 ( V_12 , V_12 + V_9 ) ;
}
int F_16 ( void )
{
int error ;
int V_23 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( V_25 [ V_20 ] . V_26 != V_27 )
continue;
error = F_3 ( & V_25 [ V_20 ] ) ;
if ( error ) {
V_23 = error ;
F_17 ( L_2 ,
V_25 [ V_20 ] . V_8 ) ;
continue;
}
F_13 ( V_25 [ V_20 ] . V_8 ) ;
V_25 [ V_20 ] . V_26 = V_28 ;
}
return V_23 ;
}
int F_18 ( unsigned long V_12 )
{
int V_6 = F_7 ( V_12 ) ;
int V_29 = - 1 ;
int V_20 ;
if ( V_6 )
return V_6 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( ( V_25 [ V_20 ] . V_26 == V_27 ) &&
( V_25 [ V_20 ] . V_8 == V_12 ) )
return - V_30 ;
}
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( V_25 [ V_20 ] . V_26 == V_31 &&
V_25 [ V_20 ] . V_8 == V_12 ) {
V_29 = V_20 ;
break;
}
}
if ( V_29 == - 1 ) {
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( V_25 [ V_20 ] . V_26 == V_32 ) {
V_29 = V_20 ;
break;
}
}
}
if ( V_29 == - 1 )
return - V_33 ;
V_25 [ V_29 ] . V_26 = V_27 ;
V_25 [ V_29 ] . type = V_34 ;
V_25 [ V_29 ] . V_8 = V_12 ;
return 0 ;
}
int F_19 ( void )
{
int error ;
int V_23 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( V_25 [ V_20 ] . V_26 != V_28 )
continue;
error = F_6 ( & V_25 [ V_20 ] ) ;
if ( error ) {
F_17 ( L_3 ,
V_25 [ V_20 ] . V_8 ) ;
V_23 = error ;
}
F_13 ( V_25 [ V_20 ] . V_8 ) ;
V_25 [ V_20 ] . V_26 = V_27 ;
}
return V_23 ;
}
int F_20 ( unsigned long V_12 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( ( V_25 [ V_20 ] . V_26 == V_27 ) &&
( V_25 [ V_20 ] . V_8 == V_12 ) ) {
V_25 [ V_20 ] . V_26 = V_31 ;
return 0 ;
}
}
return - V_35 ;
}
int F_21 ( unsigned long V_12 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( ( V_25 [ V_20 ] . V_26 == V_31 ) &&
( V_25 [ V_20 ] . V_8 == V_12 ) )
return 1 ;
}
return 0 ;
}
int F_22 ( void )
{
int error ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( V_25 [ V_20 ] . V_26 != V_28 )
goto V_36;
error = F_6 ( & V_25 [ V_20 ] ) ;
if ( error )
F_8 ( L_4 ,
V_25 [ V_20 ] . V_8 ) ;
V_36:
V_25 [ V_20 ] . V_26 = V_32 ;
}
if ( V_10 . V_37 )
V_10 . V_37 () ;
return 0 ;
}
static int F_23 ( int V_38 )
{
if ( ! V_39 )
return 0 ;
if ( V_40 )
return 1 ;
if ( F_24 ( & V_41 ) )
return 1 ;
if ( V_38 ) {
#ifdef F_25
if ( ! V_42 )
F_26 ( L_5 ) ;
#else
F_26 ( L_6 ) ;
#endif
}
return 1 ;
}
static int F_27 ( struct V_43 * V_44 )
{
unsigned long V_12 ;
if ( F_24 ( & V_45 ) != F_28 () )
return 0 ;
V_46 ++ ;
V_12 = F_9 ( V_44 -> V_47 , V_44 -> V_48 ) ;
F_19 () ;
if ( F_20 ( V_12 ) == 0 ) {
V_46 = 0 ;
F_12 ( V_44 -> V_47 , V_44 -> V_48 ) ;
F_16 () ;
F_26 ( L_7 , V_12 ) ;
F_29 ( 1 ) ;
return 1 ;
}
F_22 () ;
F_12 ( V_44 -> V_47 , V_44 -> V_48 ) ;
if ( V_46 > 1 ) {
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
static int F_36 ( struct V_43 * V_44 , struct V_15 * V_16 ,
int V_49 )
{
unsigned long V_50 ;
int V_51 = 100 ;
int error ;
int V_52 ;
int V_53 = 0 ;
int V_54 = F_37 () ;
T_2 V_55 ;
V_56 [ V_44 -> V_52 ] . V_57 ++ ;
V_56 [ V_44 -> V_52 ] . V_49 |= V_49 ;
if ( V_49 == V_58 )
F_38 ( & V_59 ) ;
else
F_38 ( & V_60 ) ;
if ( V_10 . V_61 )
V_10 . V_61 ( V_16 ) ;
V_62:
F_39 ( V_50 ) ;
V_52 = V_44 -> V_52 ;
V_56 [ V_52 ] . V_63 = V_16 ;
V_56 [ V_52 ] . V_64 = V_18 ;
V_56 [ V_52 ] . V_65 = 0 ;
V_56 [ V_52 ] . V_66 = F_40 () >> V_67 ;
F_41 () ;
if ( V_46 == 1 ) {
if ( F_42 ( & V_68 ) )
F_43 ( & V_45 , V_52 ) ;
goto V_69;
}
while ( 1 ) {
V_70:
if ( V_56 [ V_52 ] . V_49 & V_71 ) {
V_56 [ V_52 ] . V_49 &= ~ V_71 ;
goto V_69;
} else if ( V_56 [ V_52 ] . V_49 & V_58 ) {
if ( F_42 ( & V_68 ) ) {
F_43 ( & V_45 , V_52 ) ;
break;
}
} else if ( V_56 [ V_52 ] . V_49 & V_72 ) {
if ( ! F_44 ( & V_73 ) )
goto V_74;
} else {
V_74:
if ( V_10 . V_75 )
V_10 . V_75 () ;
if ( V_53 )
F_45 () ;
V_56 [ V_52 ] . V_49 &=
~ ( V_58 | V_72 ) ;
V_56 [ V_52 ] . V_57 -- ;
F_46 () ;
F_47 ( & V_60 ) ;
F_32 () ;
F_48 ( V_50 ) ;
return 0 ;
}
F_49 () ;
}
if ( F_24 ( & V_76 ) != - 1 &&
( V_56 [ V_52 ] . V_64 &&
V_56 [ V_52 ] . V_64 -> V_77 != V_78 ) && -- V_51 ) {
F_50 ( & V_45 , - 1 ) ;
F_51 ( & V_68 ) ;
F_32 () ;
F_48 ( V_50 ) ;
goto V_62;
}
if ( ! F_23 ( 1 ) ) {
V_56 [ V_52 ] . V_65 = 1 ;
goto V_79;
}
if ( F_12 ( V_44 -> V_47 , V_44 -> V_48 ) )
goto V_79;
if ( V_39 -> V_80 )
V_39 -> V_80 () ;
if ( ! V_81 )
F_52 ( & V_73 ) ;
#ifdef F_53
if ( V_44 -> V_82 )
F_50 ( V_44 -> V_82 , 1 ) ;
else if ( ( ! V_81 ) && V_3 )
F_54 ( V_50 ) ;
#endif
V_55 = V_83 ;
while ( V_3 && -- V_55 &&
( F_24 ( & V_59 ) + F_24 ( & V_60 ) ) !=
V_54 )
F_55 ( 1000 ) ;
if ( ! V_55 )
F_26 ( L_10 ) ;
F_19 () ;
V_81 = 0 ;
V_84 = V_18 ;
V_46 = 0 ;
V_53 = F_56 () ;
if ( V_53 )
F_57 () ;
while ( 1 ) {
V_69:
if ( V_42 ) {
V_40 = 1 ;
error = F_58 ( V_44 ) ;
if ( error == - 1 )
continue;
V_40 = 0 ;
} else {
error = F_59 ( V_44 ) ;
}
if ( error == V_85 ) {
V_42 = ! V_42 ;
} else if ( error == V_86 ) {
V_56 [ V_87 ] . V_49 |=
V_71 ;
goto V_70;
} else {
V_56 [ V_52 ] . V_65 = error ;
break;
}
}
if ( V_39 -> V_88 )
V_39 -> V_88 () ;
if ( ! V_81 ) {
F_51 ( & V_73 ) ;
while ( V_3 && F_24 ( & V_60 ) )
F_49 () ;
}
V_79:
if ( F_24 ( & V_76 ) != - 1 ) {
int V_89 = F_24 ( & V_76 ) ;
if ( V_56 [ V_89 ] . V_64 )
V_78 = V_56 [ V_89 ] . V_64 -> V_77 ;
else
V_78 = 0 ;
}
if ( V_10 . V_75 )
V_10 . V_75 () ;
if ( V_53 )
F_45 () ;
V_56 [ V_52 ] . V_49 &=
~ ( V_58 | V_72 ) ;
V_56 [ V_52 ] . V_57 -- ;
F_46 () ;
F_47 ( & V_59 ) ;
F_50 ( & V_45 , - 1 ) ;
F_51 ( & V_68 ) ;
F_32 () ;
F_48 ( V_50 ) ;
return V_56 [ V_52 ] . V_65 ;
}
int
F_60 ( int V_90 , int V_91 , int V_92 , struct V_15 * V_16 )
{
struct V_43 V_93 ;
struct V_43 * V_44 = & V_93 ;
int V_23 = 0 ;
if ( V_10 . V_94 )
V_10 . V_94 ( 0 ) ;
if ( V_91 != V_95 && V_96 )
return 1 ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 -> V_52 = F_28 () ;
V_44 -> V_47 = V_90 ;
V_44 -> V_91 = V_91 ;
V_44 -> V_97 = V_92 ;
V_44 -> V_48 = V_16 ;
if ( F_27 ( V_44 ) )
goto V_98;
if ( V_56 [ V_44 -> V_52 ] . V_57 != 0 )
goto V_98;
V_23 = F_36 ( V_44 , V_16 , V_58 ) ;
V_98:
if ( V_10 . V_94 )
V_10 . V_94 ( 1 ) ;
return V_23 ;
}
static int F_61 ( struct V_99 * V_100 , unsigned long V_101 ,
void * V_102 )
{
return 0 ;
}
int F_62 ( int V_52 , void * V_16 )
{
#ifdef F_53
struct V_43 V_93 ;
struct V_43 * V_44 = & V_93 ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 -> V_52 = V_52 ;
V_44 -> V_48 = V_16 ;
if ( V_56 [ V_44 -> V_52 ] . V_57 == 0 &&
F_44 ( & V_68 ) ) {
F_36 ( V_44 , V_16 , V_72 ) ;
return 0 ;
}
#endif
return 1 ;
}
int F_63 ( int V_52 , int V_103 , void * V_16 , int V_97 ,
T_3 * V_82 )
{
#ifdef F_53
if ( ! F_23 ( 0 ) || ! V_82 )
return 1 ;
if ( V_56 [ V_52 ] . V_57 == 0 ) {
struct V_43 V_93 ;
struct V_43 * V_44 = & V_93 ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 -> V_52 = V_52 ;
V_44 -> V_47 = V_103 ;
V_44 -> V_91 = V_95 ;
V_44 -> V_97 = V_97 ;
V_44 -> V_48 = V_16 ;
V_44 -> V_82 = V_82 ;
F_36 ( V_44 , V_16 , V_58 ) ;
return 0 ;
}
#endif
return 1 ;
}
static void F_64 ( struct V_104 * V_105 , const char * V_106 ,
unsigned V_107 )
{
unsigned long V_50 ;
if ( ! V_40 || F_24 ( & V_45 ) != - 1 || V_42 )
return;
F_39 ( V_50 ) ;
F_65 ( V_106 , V_107 ) ;
F_48 ( V_50 ) ;
}
static void F_66 ( int V_108 )
{
if ( ! V_39 ) {
F_26 ( L_11 ) ;
return;
}
if ( ! V_40 ) {
#ifdef F_25
if ( ! V_42 )
F_26 ( L_12 ) ;
#else
F_26 ( L_13 ) ;
#endif
}
F_67 () ;
}
static int F_68 ( struct V_99 * V_100 ,
unsigned long V_101 ,
void * V_102 )
{
if ( V_96 )
return V_109 ;
if ( V_42 )
F_69 ( L_14 , ( char * ) V_102 ) ;
F_67 () ;
return V_109 ;
}
void __weak F_70 ( void )
{
}
void T_1 F_71 ( void )
{
V_110 = false ;
if ( V_111 )
F_70 () ;
F_72 ( V_112 ) ;
}
static int
F_73 ( struct V_99 * V_113 , unsigned long V_114 , void * V_115 )
{
switch ( V_116 ) {
case 1 :
F_67 () ;
case - 1 :
goto V_117;
}
if ( ! V_42 )
F_74 ( V_114 ) ;
V_117:
return V_109 ;
}
static void F_75 ( void )
{
if ( ! V_111 ) {
V_111 = 1 ;
F_11 () ;
if ( ! V_110 )
F_70 () ;
F_76 ( & V_118 ) ;
F_77 ( & V_119 ) ;
F_78 ( & V_120 ,
& V_121 ) ;
#ifdef F_79
F_80 ( 'g' , & V_122 ) ;
#endif
if ( V_2 && ! V_123 ) {
F_81 ( & V_124 ) ;
V_123 = 1 ;
}
}
}
static void F_82 ( void )
{
if ( V_111 ) {
V_111 = 0 ;
F_83 ( & V_119 ) ;
F_84 ( & V_118 ) ;
F_85 ( & V_120 ,
& V_121 ) ;
F_86 () ;
#ifdef F_79
F_87 ( 'g' , & V_122 ) ;
#endif
if ( V_123 ) {
F_88 ( & V_124 ) ;
V_123 = 0 ;
}
}
}
static void F_89 ( unsigned long V_125 )
{
F_67 () ;
F_50 ( & V_126 , 0 ) ;
}
void F_90 ( void )
{
if ( F_24 ( & V_126 ) ||
F_24 ( & V_45 ) != - 1 ||
F_24 ( & V_41 ) )
return;
F_38 ( & V_126 ) ;
F_91 ( & V_127 ) ;
}
static void F_92 ( void )
{
V_128 = 0 ;
F_26 ( L_15 ) ;
F_67 () ;
}
int F_93 ( struct V_129 * V_130 )
{
int V_6 ;
F_94 ( & V_131 ) ;
if ( V_39 ) {
F_95 ( & V_131 ) ;
F_8 ( L_16 ) ;
return - V_132 ;
}
if ( V_130 -> V_133 ) {
V_6 = V_130 -> V_133 () ;
if ( V_6 ) {
F_95 ( & V_131 ) ;
return V_6 ;
}
}
V_39 = V_130 ;
F_95 ( & V_131 ) ;
F_17 ( L_17 , V_130 -> V_134 ) ;
F_75 () ;
if ( V_128 )
F_92 () ;
return 0 ;
}
void F_96 ( struct V_129 * V_135 )
{
F_97 ( V_40 ) ;
F_82 () ;
F_94 ( & V_131 ) ;
F_29 ( V_39 != V_135 ) ;
V_39 = NULL ;
F_95 ( & V_131 ) ;
F_17 ( L_18 ,
V_135 -> V_134 ) ;
}
int F_98 ( void )
{
int V_23 = V_39 -> V_136 () ;
if ( V_23 == V_137 )
return - 1 ;
if ( ! V_42 )
return V_23 ;
if ( V_23 == 127 )
return 8 ;
return V_23 ;
}
T_4 void F_67 ( void )
{
F_38 ( & V_41 ) ;
F_99 () ;
F_100 () ;
F_99 () ;
F_47 ( & V_41 ) ;
}
static int T_1 F_101 ( char * V_1 )
{
V_128 = 1 ;
F_72 ( V_138 ) ;
if ( V_111 )
F_92 () ;
return 0 ;
}
