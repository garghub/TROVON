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
if ( ( ! V_82 ) && V_3 )
F_52 ( V_52 ) ;
#endif
while ( V_3 && ( F_23 ( & V_60 ) +
F_23 ( & V_61 ) ) != V_56 )
F_47 () ;
F_18 () ;
V_82 = 0 ;
V_83 = V_19 ;
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
if ( error == V_84 ) {
V_43 = ! V_43 ;
} else if ( error == V_85 ) {
V_57 [ V_86 ] . V_51 |=
V_72 ;
goto V_71;
} else {
V_57 [ V_54 ] . V_66 = error ;
break;
}
}
if ( V_40 -> V_87 )
V_40 -> V_87 () ;
if ( ! V_82 ) {
F_49 ( & V_74 ) ;
while ( V_3 && F_23 ( & V_61 ) )
F_47 () ;
}
V_80:
if ( F_23 ( & V_77 ) != - 1 ) {
int V_88 = F_23 ( & V_77 ) ;
if ( V_57 [ V_88 ] . V_65 )
V_79 = V_57 [ V_88 ] . V_65 -> V_78 ;
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
F_57 ( int V_89 , int V_90 , int V_91 , struct V_16 * V_17 )
{
struct V_45 V_92 ;
struct V_45 * V_46 = & V_92 ;
V_46 -> V_54 = F_26 () ;
V_46 -> V_49 = V_89 ;
V_46 -> V_90 = V_90 ;
V_46 -> V_93 = V_91 ;
V_46 -> V_94 = 0 ;
V_46 -> V_50 = V_17 ;
if ( F_25 ( V_46 ) )
return 0 ;
if ( V_57 [ V_46 -> V_54 ] . V_58 != 0 )
return 0 ;
return F_34 ( V_46 , V_17 , V_59 ) ;
}
int F_58 ( int V_54 , void * V_17 )
{
#ifdef F_51
struct V_45 V_92 ;
struct V_45 * V_46 = & V_92 ;
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
static void F_59 ( struct V_95 * V_96 , const char * V_97 ,
unsigned V_98 )
{
unsigned long V_52 ;
if ( ! V_41 || F_23 ( & V_47 ) != - 1 || V_43 )
return;
F_37 ( V_52 ) ;
F_60 ( V_97 , V_98 ) ;
F_46 ( V_52 ) ;
}
static void F_61 ( int V_99 )
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
F_62 () ;
}
static int F_63 ( struct V_100 * V_101 ,
unsigned long V_102 ,
void * V_103 )
{
if ( V_43 )
F_64 ( L_14 , ( char * ) V_103 ) ;
F_62 () ;
return V_104 ;
}
void __weak F_65 ( void )
{
}
void T_1 F_66 ( void )
{
V_105 = false ;
if ( V_106 )
F_65 () ;
F_67 ( V_107 ) ;
}
static int
F_68 ( struct V_100 * V_108 , unsigned long V_109 , void * V_110 )
{
switch ( V_111 ) {
case 1 :
F_62 () ;
case - 1 :
goto V_112;
}
if ( ! V_43 )
F_69 ( V_109 ) ;
V_112:
return V_104 ;
}
static void F_70 ( void )
{
if ( ! V_106 ) {
V_106 = 1 ;
F_11 () ;
if ( ! V_105 )
F_65 () ;
F_71 ( & V_113 ) ;
F_72 ( & V_114 ,
& V_115 ) ;
#ifdef F_73
F_74 ( 'g' , & V_116 ) ;
#endif
if ( V_2 && ! V_117 ) {
F_75 ( & V_118 ) ;
V_117 = 1 ;
}
}
}
static void F_76 ( void )
{
if ( V_106 ) {
V_106 = 0 ;
F_77 ( & V_113 ) ;
F_78 ( & V_114 ,
& V_115 ) ;
F_79 () ;
#ifdef F_73
F_80 ( 'g' , & V_116 ) ;
#endif
if ( V_117 ) {
F_81 ( & V_118 ) ;
V_117 = 0 ;
}
}
}
static void F_82 ( unsigned long V_119 )
{
F_62 () ;
F_48 ( & V_120 , 0 ) ;
}
void F_83 ( void )
{
if ( F_23 ( & V_120 ) ||
F_23 ( & V_47 ) != - 1 ||
F_23 ( & V_42 ) )
return;
F_36 ( & V_120 ) ;
F_84 ( & V_121 ) ;
}
static void F_85 ( void )
{
V_122 = 0 ;
F_8 ( V_44 L_15 ) ;
F_62 () ;
}
int F_86 ( struct V_123 * V_124 )
{
int V_6 ;
F_87 ( & V_125 ) ;
if ( V_40 ) {
F_88 ( & V_125 ) ;
F_8 ( V_14 L_16
L_17 ) ;
return - V_126 ;
}
if ( V_124 -> V_127 ) {
V_6 = V_124 -> V_127 () ;
if ( V_6 ) {
F_88 ( & V_125 ) ;
return V_6 ;
}
}
V_40 = V_124 ;
F_88 ( & V_125 ) ;
F_8 ( V_28 L_18 ,
V_124 -> V_128 ) ;
F_70 () ;
if ( V_122 )
F_85 () ;
return 0 ;
}
void F_89 ( struct V_123 * V_129 )
{
F_90 ( V_41 ) ;
F_76 () ;
F_87 ( & V_125 ) ;
F_27 ( V_40 != V_129 ) ;
V_40 = NULL ;
F_88 ( & V_125 ) ;
F_8 ( V_28
L_19 ,
V_129 -> V_128 ) ;
}
int F_91 ( void )
{
int V_22 = V_40 -> V_130 () ;
if ( V_22 == V_131 )
return - 1 ;
if ( ! V_43 )
return V_22 ;
if ( V_22 == 127 )
return 8 ;
return V_22 ;
}
void F_62 ( void )
{
F_36 ( & V_42 ) ;
F_92 () ;
F_93 () ;
F_92 () ;
F_45 ( & V_42 ) ;
}
static int T_1 F_94 ( char * V_1 )
{
V_122 = 1 ;
F_67 ( V_132 ) ;
if ( V_106 )
F_85 () ;
return 0 ;
}
