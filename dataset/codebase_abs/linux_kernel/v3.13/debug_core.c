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
if ( V_19 -> V_20 && V_19 -> V_20 -> V_21 ) {
F_14 ( V_19 -> V_20 -> V_21 ,
V_12 , V_12 + V_9 ) ;
}
F_15 ( V_12 , V_12 + V_9 ) ;
}
int F_16 ( void )
{
int error ;
int V_22 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( V_25 [ V_23 ] . V_26 != V_27 )
continue;
error = F_3 ( & V_25 [ V_23 ] ) ;
if ( error ) {
V_22 = error ;
F_8 ( V_28 L_3 ,
V_25 [ V_23 ] . V_8 ) ;
continue;
}
F_13 ( V_25 [ V_23 ] . V_8 ) ;
V_25 [ V_23 ] . V_26 = V_29 ;
}
return V_22 ;
}
int F_17 ( unsigned long V_12 )
{
int V_6 = F_7 ( V_12 ) ;
int V_30 = - 1 ;
int V_23 ;
if ( V_6 )
return V_6 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ( V_25 [ V_23 ] . V_26 == V_27 ) &&
( V_25 [ V_23 ] . V_8 == V_12 ) )
return - V_31 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( V_25 [ V_23 ] . V_26 == V_32 &&
V_25 [ V_23 ] . V_8 == V_12 ) {
V_30 = V_23 ;
break;
}
}
if ( V_30 == - 1 ) {
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( V_25 [ V_23 ] . V_26 == V_33 ) {
V_30 = V_23 ;
break;
}
}
}
if ( V_30 == - 1 )
return - V_34 ;
V_25 [ V_30 ] . V_26 = V_27 ;
V_25 [ V_30 ] . type = V_35 ;
V_25 [ V_30 ] . V_8 = V_12 ;
return 0 ;
}
int F_18 ( void )
{
int error ;
int V_22 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( V_25 [ V_23 ] . V_26 != V_29 )
continue;
error = F_6 ( & V_25 [ V_23 ] ) ;
if ( error ) {
F_8 ( V_28 L_4 ,
V_25 [ V_23 ] . V_8 ) ;
V_22 = error ;
}
F_13 ( V_25 [ V_23 ] . V_8 ) ;
V_25 [ V_23 ] . V_26 = V_27 ;
}
return V_22 ;
}
int F_19 ( unsigned long V_12 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ( V_25 [ V_23 ] . V_26 == V_27 ) &&
( V_25 [ V_23 ] . V_8 == V_12 ) ) {
V_25 [ V_23 ] . V_26 = V_32 ;
return 0 ;
}
}
return - V_36 ;
}
int F_20 ( unsigned long V_12 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ( V_25 [ V_23 ] . V_26 == V_32 ) &&
( V_25 [ V_23 ] . V_8 == V_12 ) )
return 1 ;
}
return 0 ;
}
int F_21 ( void )
{
int error ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( V_25 [ V_23 ] . V_26 != V_29 )
goto V_37;
error = F_6 ( & V_25 [ V_23 ] ) ;
if ( error )
F_8 ( V_14 L_5 ,
V_25 [ V_23 ] . V_8 ) ;
V_37:
V_25 [ V_23 ] . V_26 = V_33 ;
}
if ( V_10 . V_38 )
V_10 . V_38 () ;
return 0 ;
}
static int F_22 ( int V_39 )
{
if ( ! V_40 )
return 0 ;
if ( V_41 )
return 1 ;
if ( F_23 ( & V_42 ) )
return 1 ;
if ( V_39 ) {
#ifdef F_24
if ( ! V_43 )
F_8 ( V_44 L_6 ) ;
#else
F_8 ( V_44 L_7 ) ;
#endif
}
return 1 ;
}
static int F_25 ( struct V_45 * V_46 )
{
unsigned long V_12 ;
if ( F_23 ( & V_47 ) != F_26 () )
return 0 ;
V_48 ++ ;
V_12 = F_9 ( V_46 -> V_49 , V_46 -> V_50 ) ;
F_18 () ;
if ( F_19 ( V_12 ) == 0 ) {
V_48 = 0 ;
F_12 ( V_46 -> V_49 , V_46 -> V_50 ) ;
F_16 () ;
F_8 ( V_44 L_8 ,
V_12 ) ;
F_27 ( 1 ) ;
return 1 ;
}
F_21 () ;
F_12 ( V_46 -> V_49 , V_46 -> V_50 ) ;
if ( V_48 > 1 ) {
F_28 () ;
F_29 ( L_9 ) ;
}
F_8 ( V_44 L_10 ) ;
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
static int F_34 ( struct V_45 * V_46 , struct V_16 * V_17 ,
int V_51 )
{
unsigned long V_52 ;
int V_53 = 100 ;
int error ;
int V_54 ;
int V_55 = 0 ;
int V_56 = F_35 () ;
V_57 [ V_46 -> V_54 ] . V_58 ++ ;
V_57 [ V_46 -> V_54 ] . V_51 |= V_51 ;
if ( V_51 == V_59 )
F_36 ( & V_60 ) ;
else
F_36 ( & V_61 ) ;
if ( V_10 . V_62 )
V_10 . V_62 ( V_17 ) ;
V_63:
F_37 ( V_52 ) ;
V_54 = V_46 -> V_54 ;
V_57 [ V_54 ] . V_64 = V_17 ;
V_57 [ V_54 ] . V_65 = V_19 ;
V_57 [ V_54 ] . V_66 = 0 ;
V_57 [ V_54 ] . V_67 = F_38 () >> V_68 ;
F_39 () ;
if ( V_48 == 1 ) {
if ( F_40 ( & V_69 ) )
F_41 ( & V_47 , V_54 ) ;
goto V_70;
}
while ( 1 ) {
V_71:
if ( V_57 [ V_54 ] . V_51 & V_72 ) {
V_57 [ V_54 ] . V_51 &= ~ V_72 ;
goto V_70;
} else if ( V_57 [ V_54 ] . V_51 & V_59 ) {
if ( F_40 ( & V_69 ) ) {
F_41 ( & V_47 , V_54 ) ;
break;
}
} else if ( V_57 [ V_54 ] . V_51 & V_73 ) {
if ( ! F_42 ( & V_74 ) )
goto V_75;
} else {
V_75:
if ( V_10 . V_76 )
V_10 . V_76 () ;
if ( V_55 )
F_43 () ;
V_57 [ V_54 ] . V_51 &=
~ ( V_59 | V_73 ) ;
V_57 [ V_54 ] . V_58 -- ;
F_44 () ;
F_45 ( & V_61 ) ;
F_30 () ;
F_46 ( V_52 ) ;
return 0 ;
}
F_47 () ;
}
if ( F_23 ( & V_77 ) != - 1 &&
( V_57 [ V_54 ] . V_65 &&
V_57 [ V_54 ] . V_65 -> V_78 != V_79 ) && -- V_53 ) {
F_48 ( & V_47 , - 1 ) ;
F_49 ( & V_69 ) ;
F_30 () ;
F_46 ( V_52 ) ;
goto V_63;
}
if ( ! F_22 ( 1 ) ) {
V_57 [ V_54 ] . V_66 = 1 ;
goto V_80;
}
if ( F_12 ( V_46 -> V_49 , V_46 -> V_50 ) )
goto V_80;
if ( V_40 -> V_81 )
V_40 -> V_81 () ;
if ( ! V_82 )
F_50 ( & V_74 ) ;
#ifdef F_51
if ( V_46 -> V_83 )
F_48 ( V_46 -> V_83 , 1 ) ;
else if ( ( ! V_82 ) && V_3 )
F_52 ( V_52 ) ;
#endif
while ( V_3 && ( F_23 ( & V_60 ) +
F_23 ( & V_61 ) ) != V_56 )
F_47 () ;
F_18 () ;
V_82 = 0 ;
V_84 = V_19 ;
V_48 = 0 ;
V_55 = F_53 () ;
if ( V_55 )
F_54 () ;
while ( 1 ) {
V_70:
if ( V_43 ) {
V_41 = 1 ;
error = F_55 ( V_46 ) ;
if ( error == - 1 )
continue;
V_41 = 0 ;
} else {
error = F_56 ( V_46 ) ;
}
if ( error == V_85 ) {
V_43 = ! V_43 ;
} else if ( error == V_86 ) {
V_57 [ V_87 ] . V_51 |=
V_72 ;
goto V_71;
} else {
V_57 [ V_54 ] . V_66 = error ;
break;
}
}
if ( V_40 -> V_88 )
V_40 -> V_88 () ;
if ( ! V_82 ) {
F_49 ( & V_74 ) ;
while ( V_3 && F_23 ( & V_61 ) )
F_47 () ;
}
V_80:
if ( F_23 ( & V_77 ) != - 1 ) {
int V_89 = F_23 ( & V_77 ) ;
if ( V_57 [ V_89 ] . V_65 )
V_79 = V_57 [ V_89 ] . V_65 -> V_78 ;
else
V_79 = 0 ;
}
if ( V_10 . V_76 )
V_10 . V_76 () ;
if ( V_55 )
F_43 () ;
V_57 [ V_54 ] . V_51 &=
~ ( V_59 | V_73 ) ;
V_57 [ V_54 ] . V_58 -- ;
F_44 () ;
F_45 ( & V_60 ) ;
F_48 ( & V_47 , - 1 ) ;
F_49 ( & V_69 ) ;
F_30 () ;
F_46 ( V_52 ) ;
return V_57 [ V_54 ] . V_66 ;
}
int
F_57 ( int V_90 , int V_91 , int V_92 , struct V_16 * V_17 )
{
struct V_45 V_93 ;
struct V_45 * V_46 = & V_93 ;
int V_22 = 0 ;
if ( V_10 . V_94 )
V_10 . V_94 ( 0 ) ;
memset ( V_46 , 0 , sizeof( struct V_45 ) ) ;
V_46 -> V_54 = F_26 () ;
V_46 -> V_49 = V_90 ;
V_46 -> V_91 = V_91 ;
V_46 -> V_95 = V_92 ;
V_46 -> V_50 = V_17 ;
if ( F_25 ( V_46 ) )
goto V_96;
if ( V_57 [ V_46 -> V_54 ] . V_58 != 0 )
goto V_96;
V_22 = F_34 ( V_46 , V_17 , V_59 ) ;
V_96:
if ( V_10 . V_94 )
V_10 . V_94 ( 1 ) ;
return V_22 ;
}
static int F_58 ( struct V_97 * V_98 , unsigned long V_99 ,
void * V_100 )
{
return 0 ;
}
int F_59 ( int V_54 , void * V_17 )
{
#ifdef F_51
struct V_45 V_93 ;
struct V_45 * V_46 = & V_93 ;
memset ( V_46 , 0 , sizeof( struct V_45 ) ) ;
V_46 -> V_54 = V_54 ;
V_46 -> V_50 = V_17 ;
if ( V_57 [ V_46 -> V_54 ] . V_58 == 0 &&
F_42 ( & V_69 ) ) {
F_34 ( V_46 , V_17 , V_73 ) ;
return 0 ;
}
#endif
return 1 ;
}
int F_60 ( int V_54 , int V_101 , void * V_17 , T_2 * V_83 )
{
#ifdef F_51
if ( ! F_22 ( 0 ) || ! V_83 )
return 1 ;
if ( V_57 [ V_54 ] . V_58 == 0 ) {
struct V_45 V_93 ;
struct V_45 * V_46 = & V_93 ;
memset ( V_46 , 0 , sizeof( struct V_45 ) ) ;
V_46 -> V_54 = V_54 ;
V_46 -> V_49 = V_101 ;
V_46 -> V_91 = V_102 ;
V_46 -> V_95 = V_103 ;
V_46 -> V_50 = V_17 ;
V_46 -> V_83 = V_83 ;
F_34 ( V_46 , V_17 , V_59 ) ;
return 0 ;
}
#endif
return 1 ;
}
static void F_61 ( struct V_104 * V_105 , const char * V_106 ,
unsigned V_107 )
{
unsigned long V_52 ;
if ( ! V_41 || F_23 ( & V_47 ) != - 1 || V_43 )
return;
F_37 ( V_52 ) ;
F_62 ( V_106 , V_107 ) ;
F_46 ( V_52 ) ;
}
static void F_63 ( int V_108 )
{
if ( ! V_40 ) {
F_8 ( V_44 L_11 ) ;
return;
}
if ( ! V_41 ) {
#ifdef F_24
if ( ! V_43 )
F_8 ( V_44 L_12 ) ;
#else
F_8 ( V_44 L_13 ) ;
#endif
}
F_64 () ;
}
static int F_65 ( struct V_97 * V_98 ,
unsigned long V_99 ,
void * V_100 )
{
if ( V_43 )
F_66 ( L_14 , ( char * ) V_100 ) ;
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
F_70 ( struct V_97 * V_113 , unsigned long V_114 , void * V_115 )
{
switch ( V_116 ) {
case 1 :
F_64 () ;
case - 1 :
goto V_117;
}
if ( ! V_43 )
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
F_23 ( & V_47 ) != - 1 ||
F_23 ( & V_42 ) )
return;
F_36 ( & V_126 ) ;
F_88 ( & V_127 ) ;
}
static void F_89 ( void )
{
V_128 = 0 ;
F_8 ( V_44 L_15 ) ;
F_64 () ;
}
int F_90 ( struct V_129 * V_130 )
{
int V_6 ;
F_91 ( & V_131 ) ;
if ( V_40 ) {
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
V_40 = V_130 ;
F_92 ( & V_131 ) ;
F_8 ( V_28 L_18 ,
V_130 -> V_134 ) ;
F_72 () ;
if ( V_128 )
F_89 () ;
return 0 ;
}
void F_93 ( struct V_129 * V_135 )
{
F_94 ( V_41 ) ;
F_79 () ;
F_91 ( & V_131 ) ;
F_27 ( V_40 != V_135 ) ;
V_40 = NULL ;
F_92 ( & V_131 ) ;
F_8 ( V_28
L_19 ,
V_135 -> V_134 ) ;
}
int F_95 ( void )
{
int V_22 = V_40 -> V_136 () ;
if ( V_22 == V_137 )
return - 1 ;
if ( ! V_43 )
return V_22 ;
if ( V_22 == 127 )
return 8 ;
return V_22 ;
}
void F_64 ( void )
{
F_36 ( & V_42 ) ;
F_96 () ;
F_97 () ;
F_96 () ;
F_45 ( & V_42 ) ;
}
static int T_1 F_98 ( char * V_1 )
{
V_128 = 1 ;
F_69 ( V_138 ) ;
if ( V_111 )
F_89 () ;
return 0 ;
}
