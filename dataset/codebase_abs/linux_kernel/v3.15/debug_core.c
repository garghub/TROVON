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
F_8 ( V_14 L_1
L_2 , V_12 ) ;
return V_6 ;
}
unsigned long __weak F_9 ( int V_15 , struct V_16 * V_17 )
{
return F_10 ( V_17 ) ;
}
int __weak F_11 ( void )
{
return 0 ;
}
int __weak F_12 ( int V_15 , struct V_16 * V_17 )
{
return 0 ;
}
static void F_13 ( unsigned long V_12 )
{
if ( ! V_18 )
return;
if ( V_19 -> V_20 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( ! V_19 -> V_23 [ V_21 ] )
continue;
F_14 ( V_19 -> V_23 [ V_21 ] ,
V_12 , V_12 + V_9 ) ;
}
}
F_15 ( V_12 , V_12 + V_9 ) ;
}
int F_16 ( void )
{
int error ;
int V_24 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( V_26 [ V_21 ] . V_27 != V_28 )
continue;
error = F_3 ( & V_26 [ V_21 ] ) ;
if ( error ) {
V_24 = error ;
F_8 ( V_29 L_3 ,
V_26 [ V_21 ] . V_8 ) ;
continue;
}
F_13 ( V_26 [ V_21 ] . V_8 ) ;
V_26 [ V_21 ] . V_27 = V_30 ;
}
return V_24 ;
}
int F_17 ( unsigned long V_12 )
{
int V_6 = F_7 ( V_12 ) ;
int V_31 = - 1 ;
int V_21 ;
if ( V_6 )
return V_6 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( ( V_26 [ V_21 ] . V_27 == V_28 ) &&
( V_26 [ V_21 ] . V_8 == V_12 ) )
return - V_32 ;
}
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( V_26 [ V_21 ] . V_27 == V_33 &&
V_26 [ V_21 ] . V_8 == V_12 ) {
V_31 = V_21 ;
break;
}
}
if ( V_31 == - 1 ) {
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( V_26 [ V_21 ] . V_27 == V_34 ) {
V_31 = V_21 ;
break;
}
}
}
if ( V_31 == - 1 )
return - V_35 ;
V_26 [ V_31 ] . V_27 = V_28 ;
V_26 [ V_31 ] . type = V_36 ;
V_26 [ V_31 ] . V_8 = V_12 ;
return 0 ;
}
int F_18 ( void )
{
int error ;
int V_24 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( V_26 [ V_21 ] . V_27 != V_30 )
continue;
error = F_6 ( & V_26 [ V_21 ] ) ;
if ( error ) {
F_8 ( V_29 L_4 ,
V_26 [ V_21 ] . V_8 ) ;
V_24 = error ;
}
F_13 ( V_26 [ V_21 ] . V_8 ) ;
V_26 [ V_21 ] . V_27 = V_28 ;
}
return V_24 ;
}
int F_19 ( unsigned long V_12 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( ( V_26 [ V_21 ] . V_27 == V_28 ) &&
( V_26 [ V_21 ] . V_8 == V_12 ) ) {
V_26 [ V_21 ] . V_27 = V_33 ;
return 0 ;
}
}
return - V_37 ;
}
int F_20 ( unsigned long V_12 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( ( V_26 [ V_21 ] . V_27 == V_33 ) &&
( V_26 [ V_21 ] . V_8 == V_12 ) )
return 1 ;
}
return 0 ;
}
int F_21 ( void )
{
int error ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
if ( V_26 [ V_21 ] . V_27 != V_30 )
goto V_38;
error = F_6 ( & V_26 [ V_21 ] ) ;
if ( error )
F_8 ( V_14 L_5 ,
V_26 [ V_21 ] . V_8 ) ;
V_38:
V_26 [ V_21 ] . V_27 = V_34 ;
}
if ( V_10 . V_39 )
V_10 . V_39 () ;
return 0 ;
}
static int F_22 ( int V_40 )
{
if ( ! V_41 )
return 0 ;
if ( V_42 )
return 1 ;
if ( F_23 ( & V_43 ) )
return 1 ;
if ( V_40 ) {
#ifdef F_24
if ( ! V_44 )
F_8 ( V_45 L_6 ) ;
#else
F_8 ( V_45 L_7 ) ;
#endif
}
return 1 ;
}
static int F_25 ( struct V_46 * V_47 )
{
unsigned long V_12 ;
if ( F_23 ( & V_48 ) != F_26 () )
return 0 ;
V_49 ++ ;
V_12 = F_9 ( V_47 -> V_50 , V_47 -> V_51 ) ;
F_18 () ;
if ( F_19 ( V_12 ) == 0 ) {
V_49 = 0 ;
F_12 ( V_47 -> V_50 , V_47 -> V_51 ) ;
F_16 () ;
F_8 ( V_45 L_8 ,
V_12 ) ;
F_27 ( 1 ) ;
return 1 ;
}
F_21 () ;
F_12 ( V_47 -> V_50 , V_47 -> V_51 ) ;
if ( V_49 > 1 ) {
F_28 () ;
F_29 ( L_9 ) ;
}
F_8 ( V_45 L_10 ) ;
#ifdef F_24
return 0 ;
#endif
F_28 () ;
F_29 ( L_9 ) ;
return 1 ;
}
static void F_30 ( void )
{
F_31 () ;
F_32 () ;
F_33 () ;
}
static int F_34 ( struct V_46 * V_47 , struct V_16 * V_17 ,
int V_52 )
{
unsigned long V_53 ;
int V_54 = 100 ;
int error ;
int V_55 ;
int V_56 = 0 ;
int V_57 = F_35 () ;
V_58 [ V_47 -> V_55 ] . V_59 ++ ;
V_58 [ V_47 -> V_55 ] . V_52 |= V_52 ;
if ( V_52 == V_60 )
F_36 ( & V_61 ) ;
else
F_36 ( & V_62 ) ;
if ( V_10 . V_63 )
V_10 . V_63 ( V_17 ) ;
V_64:
F_37 ( V_53 ) ;
V_55 = V_47 -> V_55 ;
V_58 [ V_55 ] . V_65 = V_17 ;
V_58 [ V_55 ] . V_66 = V_19 ;
V_58 [ V_55 ] . V_67 = 0 ;
V_58 [ V_55 ] . V_68 = F_38 () >> V_69 ;
F_39 () ;
if ( V_49 == 1 ) {
if ( F_40 ( & V_70 ) )
F_41 ( & V_48 , V_55 ) ;
goto V_71;
}
while ( 1 ) {
V_72:
if ( V_58 [ V_55 ] . V_52 & V_73 ) {
V_58 [ V_55 ] . V_52 &= ~ V_73 ;
goto V_71;
} else if ( V_58 [ V_55 ] . V_52 & V_60 ) {
if ( F_40 ( & V_70 ) ) {
F_41 ( & V_48 , V_55 ) ;
break;
}
} else if ( V_58 [ V_55 ] . V_52 & V_74 ) {
if ( ! F_42 ( & V_75 ) )
goto V_76;
} else {
V_76:
if ( V_10 . V_77 )
V_10 . V_77 () ;
if ( V_56 )
F_43 () ;
V_58 [ V_55 ] . V_52 &=
~ ( V_60 | V_74 ) ;
V_58 [ V_55 ] . V_59 -- ;
F_44 () ;
F_45 ( & V_62 ) ;
F_30 () ;
F_46 ( V_53 ) ;
return 0 ;
}
F_47 () ;
}
if ( F_23 ( & V_78 ) != - 1 &&
( V_58 [ V_55 ] . V_66 &&
V_58 [ V_55 ] . V_66 -> V_79 != V_80 ) && -- V_54 ) {
F_48 ( & V_48 , - 1 ) ;
F_49 ( & V_70 ) ;
F_30 () ;
F_46 ( V_53 ) ;
goto V_64;
}
if ( ! F_22 ( 1 ) ) {
V_58 [ V_55 ] . V_67 = 1 ;
goto V_81;
}
if ( F_12 ( V_47 -> V_50 , V_47 -> V_51 ) )
goto V_81;
if ( V_41 -> V_82 )
V_41 -> V_82 () ;
if ( ! V_83 )
F_50 ( & V_75 ) ;
#ifdef F_51
if ( V_47 -> V_84 )
F_48 ( V_47 -> V_84 , 1 ) ;
else if ( ( ! V_83 ) && V_3 )
F_52 ( V_53 ) ;
#endif
while ( V_3 && ( F_23 ( & V_61 ) +
F_23 ( & V_62 ) ) != V_57 )
F_47 () ;
F_18 () ;
V_83 = 0 ;
V_85 = V_19 ;
V_49 = 0 ;
V_56 = F_53 () ;
if ( V_56 )
F_54 () ;
while ( 1 ) {
V_71:
if ( V_44 ) {
V_42 = 1 ;
error = F_55 ( V_47 ) ;
if ( error == - 1 )
continue;
V_42 = 0 ;
} else {
error = F_56 ( V_47 ) ;
}
if ( error == V_86 ) {
V_44 = ! V_44 ;
} else if ( error == V_87 ) {
V_58 [ V_88 ] . V_52 |=
V_73 ;
goto V_72;
} else {
V_58 [ V_55 ] . V_67 = error ;
break;
}
}
if ( V_41 -> V_89 )
V_41 -> V_89 () ;
if ( ! V_83 ) {
F_49 ( & V_75 ) ;
while ( V_3 && F_23 ( & V_62 ) )
F_47 () ;
}
V_81:
if ( F_23 ( & V_78 ) != - 1 ) {
int V_90 = F_23 ( & V_78 ) ;
if ( V_58 [ V_90 ] . V_66 )
V_80 = V_58 [ V_90 ] . V_66 -> V_79 ;
else
V_80 = 0 ;
}
if ( V_10 . V_77 )
V_10 . V_77 () ;
if ( V_56 )
F_43 () ;
V_58 [ V_55 ] . V_52 &=
~ ( V_60 | V_74 ) ;
V_58 [ V_55 ] . V_59 -- ;
F_44 () ;
F_45 ( & V_61 ) ;
F_48 ( & V_48 , - 1 ) ;
F_49 ( & V_70 ) ;
F_30 () ;
F_46 ( V_53 ) ;
return V_58 [ V_55 ] . V_67 ;
}
int
F_57 ( int V_91 , int V_92 , int V_93 , struct V_16 * V_17 )
{
struct V_46 V_94 ;
struct V_46 * V_47 = & V_94 ;
int V_24 = 0 ;
if ( V_10 . V_95 )
V_10 . V_95 ( 0 ) ;
memset ( V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 -> V_55 = F_26 () ;
V_47 -> V_50 = V_91 ;
V_47 -> V_92 = V_92 ;
V_47 -> V_96 = V_93 ;
V_47 -> V_51 = V_17 ;
if ( F_25 ( V_47 ) )
goto V_97;
if ( V_58 [ V_47 -> V_55 ] . V_59 != 0 )
goto V_97;
V_24 = F_34 ( V_47 , V_17 , V_60 ) ;
V_97:
if ( V_10 . V_95 )
V_10 . V_95 ( 1 ) ;
return V_24 ;
}
static int F_58 ( struct V_98 * V_99 , unsigned long V_100 ,
void * V_101 )
{
return 0 ;
}
int F_59 ( int V_55 , void * V_17 )
{
#ifdef F_51
struct V_46 V_94 ;
struct V_46 * V_47 = & V_94 ;
memset ( V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 -> V_55 = V_55 ;
V_47 -> V_51 = V_17 ;
if ( V_58 [ V_47 -> V_55 ] . V_59 == 0 &&
F_42 ( & V_70 ) ) {
F_34 ( V_47 , V_17 , V_74 ) ;
return 0 ;
}
#endif
return 1 ;
}
int F_60 ( int V_55 , int V_102 , void * V_17 , int V_96 ,
T_2 * V_84 )
{
#ifdef F_51
if ( ! F_22 ( 0 ) || ! V_84 )
return 1 ;
if ( V_58 [ V_55 ] . V_59 == 0 ) {
struct V_46 V_94 ;
struct V_46 * V_47 = & V_94 ;
memset ( V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 -> V_55 = V_55 ;
V_47 -> V_50 = V_102 ;
V_47 -> V_92 = V_103 ;
V_47 -> V_96 = V_96 ;
V_47 -> V_51 = V_17 ;
V_47 -> V_84 = V_84 ;
F_34 ( V_47 , V_17 , V_60 ) ;
return 0 ;
}
#endif
return 1 ;
}
static void F_61 ( struct V_104 * V_105 , const char * V_106 ,
unsigned V_107 )
{
unsigned long V_53 ;
if ( ! V_42 || F_23 ( & V_48 ) != - 1 || V_44 )
return;
F_37 ( V_53 ) ;
F_62 ( V_106 , V_107 ) ;
F_46 ( V_53 ) ;
}
static void F_63 ( int V_108 )
{
if ( ! V_41 ) {
F_8 ( V_45 L_11 ) ;
return;
}
if ( ! V_42 ) {
#ifdef F_24
if ( ! V_44 )
F_8 ( V_45 L_12 ) ;
#else
F_8 ( V_45 L_13 ) ;
#endif
}
F_64 () ;
}
static int F_65 ( struct V_98 * V_99 ,
unsigned long V_100 ,
void * V_101 )
{
if ( V_44 )
F_66 ( L_14 , ( char * ) V_101 ) ;
F_64 () ;
return V_109 ;
}
void __weak F_67 ( void )
{
}
void T_1 F_68 ( void )
{
V_110 = false ;
if ( V_111 )
F_67 () ;
F_69 ( V_112 ) ;
}
static int
F_70 ( struct V_98 * V_113 , unsigned long V_114 , void * V_115 )
{
switch ( V_116 ) {
case 1 :
F_64 () ;
case - 1 :
goto V_117;
}
if ( ! V_44 )
F_71 ( V_114 ) ;
V_117:
return V_109 ;
}
static void F_72 ( void )
{
if ( ! V_111 ) {
V_111 = 1 ;
F_11 () ;
if ( ! V_110 )
F_67 () ;
F_73 ( & V_118 ) ;
F_74 ( & V_119 ) ;
F_75 ( & V_120 ,
& V_121 ) ;
#ifdef F_76
F_77 ( 'g' , & V_122 ) ;
#endif
if ( V_2 && ! V_123 ) {
F_78 ( & V_124 ) ;
V_123 = 1 ;
}
}
}
static void F_79 ( void )
{
if ( V_111 ) {
V_111 = 0 ;
F_80 ( & V_119 ) ;
F_81 ( & V_118 ) ;
F_82 ( & V_120 ,
& V_121 ) ;
F_83 () ;
#ifdef F_76
F_84 ( 'g' , & V_122 ) ;
#endif
if ( V_123 ) {
F_85 ( & V_124 ) ;
V_123 = 0 ;
}
}
}
static void F_86 ( unsigned long V_125 )
{
F_64 () ;
F_48 ( & V_126 , 0 ) ;
}
void F_87 ( void )
{
if ( F_23 ( & V_126 ) ||
F_23 ( & V_48 ) != - 1 ||
F_23 ( & V_43 ) )
return;
F_36 ( & V_126 ) ;
F_88 ( & V_127 ) ;
}
static void F_89 ( void )
{
V_128 = 0 ;
F_8 ( V_45 L_15 ) ;
F_64 () ;
}
int F_90 ( struct V_129 * V_130 )
{
int V_6 ;
F_91 ( & V_131 ) ;
if ( V_41 ) {
F_92 ( & V_131 ) ;
F_8 ( V_14 L_16
L_17 ) ;
return - V_132 ;
}
if ( V_130 -> V_133 ) {
V_6 = V_130 -> V_133 () ;
if ( V_6 ) {
F_92 ( & V_131 ) ;
return V_6 ;
}
}
V_41 = V_130 ;
F_92 ( & V_131 ) ;
F_8 ( V_29 L_18 ,
V_130 -> V_134 ) ;
F_72 () ;
if ( V_128 )
F_89 () ;
return 0 ;
}
void F_93 ( struct V_129 * V_135 )
{
F_94 ( V_42 ) ;
F_79 () ;
F_91 ( & V_131 ) ;
F_27 ( V_41 != V_135 ) ;
V_41 = NULL ;
F_92 ( & V_131 ) ;
F_8 ( V_29
L_19 ,
V_135 -> V_134 ) ;
}
int F_95 ( void )
{
int V_24 = V_41 -> V_136 () ;
if ( V_24 == V_137 )
return - 1 ;
if ( ! V_44 )
return V_24 ;
if ( V_24 == 127 )
return 8 ;
return V_24 ;
}
T_3 void F_64 ( void )
{
F_36 ( & V_43 ) ;
F_96 () ;
F_97 () ;
F_96 () ;
F_45 ( & V_43 ) ;
}
static int T_1 F_98 ( char * V_1 )
{
V_128 = 1 ;
F_69 ( V_138 ) ;
if ( V_111 )
F_89 () ;
return 0 ;
}
