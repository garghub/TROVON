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
int __weak F_3 ( unsigned long V_4 , char * V_5 )
{
int V_6 ;
V_6 = F_4 ( V_5 , ( char * ) V_4 , V_7 ) ;
if ( V_6 )
return V_6 ;
return F_5 ( ( char * ) V_4 , V_8 . V_9 ,
V_7 ) ;
}
int __weak F_6 ( unsigned long V_4 , char * V_10 )
{
return F_5 ( ( char * ) V_4 ,
( char * ) V_10 , V_7 ) ;
}
int __weak F_7 ( unsigned long V_4 )
{
char V_11 [ V_7 ] ;
int V_6 ;
V_6 = F_3 ( V_4 , V_11 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_4 , V_11 ) ;
if ( V_6 )
F_8 ( V_12 L_1
L_2 , V_4 ) ;
return V_6 ;
}
unsigned long __weak F_9 ( int V_13 , struct V_14 * V_15 )
{
return F_10 ( V_15 ) ;
}
int __weak F_11 ( void )
{
return 0 ;
}
int __weak F_12 ( int V_13 , struct V_14 * V_15 )
{
return 0 ;
}
static void F_13 ( unsigned long V_4 )
{
if ( ! V_16 )
return;
if ( V_17 -> V_18 && V_17 -> V_18 -> V_19 ) {
F_14 ( V_17 -> V_18 -> V_19 ,
V_4 , V_4 + V_7 ) ;
}
F_15 ( V_4 , V_4 + V_7 ) ;
}
int F_16 ( void )
{
unsigned long V_4 ;
int error ;
int V_20 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_23 [ V_21 ] . V_24 != V_25 )
continue;
V_4 = V_23 [ V_21 ] . V_26 ;
error = F_3 ( V_4 ,
V_23 [ V_21 ] . V_5 ) ;
if ( error ) {
V_20 = error ;
F_8 ( V_27 L_3 , V_4 ) ;
continue;
}
F_13 ( V_4 ) ;
V_23 [ V_21 ] . V_24 = V_28 ;
}
return V_20 ;
}
int F_17 ( unsigned long V_4 )
{
int V_6 = F_7 ( V_4 ) ;
int V_29 = - 1 ;
int V_21 ;
if ( V_6 )
return V_6 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( ( V_23 [ V_21 ] . V_24 == V_25 ) &&
( V_23 [ V_21 ] . V_26 == V_4 ) )
return - V_30 ;
}
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_23 [ V_21 ] . V_24 == V_31 &&
V_23 [ V_21 ] . V_26 == V_4 ) {
V_29 = V_21 ;
break;
}
}
if ( V_29 == - 1 ) {
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_23 [ V_21 ] . V_24 == V_32 ) {
V_29 = V_21 ;
break;
}
}
}
if ( V_29 == - 1 )
return - V_33 ;
V_23 [ V_29 ] . V_24 = V_25 ;
V_23 [ V_29 ] . type = V_34 ;
V_23 [ V_29 ] . V_26 = V_4 ;
return 0 ;
}
int F_18 ( void )
{
unsigned long V_4 ;
int error ;
int V_20 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_23 [ V_21 ] . V_24 != V_28 )
continue;
V_4 = V_23 [ V_21 ] . V_26 ;
error = F_6 ( V_4 ,
V_23 [ V_21 ] . V_5 ) ;
if ( error ) {
F_8 ( V_27 L_4 , V_4 ) ;
V_20 = error ;
}
F_13 ( V_4 ) ;
V_23 [ V_21 ] . V_24 = V_25 ;
}
return V_20 ;
}
int F_19 ( unsigned long V_4 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( ( V_23 [ V_21 ] . V_24 == V_25 ) &&
( V_23 [ V_21 ] . V_26 == V_4 ) ) {
V_23 [ V_21 ] . V_24 = V_31 ;
return 0 ;
}
}
return - V_35 ;
}
int F_20 ( unsigned long V_4 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( ( V_23 [ V_21 ] . V_24 == V_31 ) &&
( V_23 [ V_21 ] . V_26 == V_4 ) )
return 1 ;
}
return 0 ;
}
int F_21 ( void )
{
unsigned long V_4 ;
int error ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_23 [ V_21 ] . V_24 != V_28 )
goto V_36;
V_4 = V_23 [ V_21 ] . V_26 ;
error = F_6 ( V_4 ,
V_23 [ V_21 ] . V_5 ) ;
if ( error )
F_8 ( V_12 L_5 ,
V_4 ) ;
V_36:
V_23 [ V_21 ] . V_24 = V_32 ;
}
if ( V_8 . V_37 )
V_8 . V_37 () ;
return 0 ;
}
static int F_22 ( int V_38 )
{
if ( ! V_39 )
return 0 ;
if ( V_40 )
return 1 ;
if ( F_23 ( & V_41 ) )
return 1 ;
if ( V_38 ) {
#ifdef F_24
if ( ! V_42 )
F_8 ( V_43 L_6 ) ;
#else
F_8 ( V_43 L_7 ) ;
#endif
}
return 1 ;
}
static int F_25 ( struct V_44 * V_45 )
{
unsigned long V_4 ;
if ( F_23 ( & V_46 ) != F_26 () )
return 0 ;
V_47 ++ ;
V_4 = F_9 ( V_45 -> V_48 , V_45 -> V_49 ) ;
F_18 () ;
if ( F_19 ( V_4 ) == 0 ) {
V_47 = 0 ;
F_12 ( V_45 -> V_48 , V_45 -> V_49 ) ;
F_16 () ;
F_8 ( V_43 L_8 ,
V_4 ) ;
F_27 ( 1 ) ;
return 1 ;
}
F_21 () ;
F_12 ( V_45 -> V_48 , V_45 -> V_49 ) ;
if ( V_47 > 1 ) {
F_28 () ;
F_29 ( L_9 ) ;
}
F_8 ( V_43 L_10 ) ;
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
static int F_34 ( struct V_44 * V_45 , struct V_14 * V_15 ,
int V_50 )
{
unsigned long V_51 ;
int V_52 = 100 ;
int error ;
int V_53 ;
int V_54 = 0 ;
int V_55 = F_35 () ;
V_56 [ V_45 -> V_53 ] . V_57 ++ ;
V_56 [ V_45 -> V_53 ] . V_50 |= V_50 ;
if ( V_50 == V_58 )
F_36 ( & V_59 ) ;
else
F_36 ( & V_60 ) ;
if ( V_8 . V_61 )
V_8 . V_61 ( V_15 ) ;
V_62:
F_37 ( V_51 ) ;
V_53 = V_45 -> V_53 ;
V_56 [ V_53 ] . V_63 = V_15 ;
V_56 [ V_53 ] . V_64 = V_17 ;
V_56 [ V_53 ] . V_65 = 0 ;
V_56 [ V_53 ] . V_66 = F_38 () >> V_67 ;
F_39 () ;
if ( V_47 == 1 ) {
if ( F_40 ( & V_68 ) )
F_41 ( & V_46 , V_53 ) ;
goto V_69;
}
while ( 1 ) {
V_70:
if ( V_56 [ V_53 ] . V_50 & V_71 ) {
V_56 [ V_53 ] . V_50 &= ~ V_71 ;
goto V_69;
} else if ( V_56 [ V_53 ] . V_50 & V_58 ) {
if ( F_40 ( & V_68 ) ) {
F_41 ( & V_46 , V_53 ) ;
break;
}
} else if ( V_56 [ V_53 ] . V_50 & V_72 ) {
if ( ! F_42 ( & V_73 ) )
goto V_74;
} else {
V_74:
if ( V_8 . V_75 )
V_8 . V_75 () ;
if ( V_54 )
F_43 () ;
V_56 [ V_53 ] . V_50 &=
~ ( V_58 | V_72 ) ;
V_56 [ V_53 ] . V_57 -- ;
F_44 () ;
F_45 ( & V_60 ) ;
F_30 () ;
F_46 ( V_51 ) ;
return 0 ;
}
F_47 () ;
}
if ( F_23 ( & V_76 ) != - 1 &&
( V_56 [ V_53 ] . V_64 &&
V_56 [ V_53 ] . V_64 -> V_77 != V_78 ) && -- V_52 ) {
F_48 ( & V_46 , - 1 ) ;
F_49 ( & V_68 ) ;
F_30 () ;
F_46 ( V_51 ) ;
goto V_62;
}
if ( ! F_22 ( 1 ) ) {
V_56 [ V_53 ] . V_65 = 1 ;
goto V_79;
}
if ( F_12 ( V_45 -> V_48 , V_45 -> V_49 ) )
goto V_79;
if ( V_39 -> V_80 )
V_39 -> V_80 () ;
if ( ! V_81 )
F_50 ( & V_73 ) ;
#ifdef F_51
if ( ( ! V_81 ) && V_3 )
F_52 ( V_51 ) ;
#endif
while ( V_3 && ( F_23 ( & V_59 ) +
F_23 ( & V_60 ) ) != V_55 )
F_47 () ;
F_18 () ;
V_81 = 0 ;
V_82 = V_17 ;
V_47 = 0 ;
V_54 = F_53 () ;
if ( V_54 )
F_54 () ;
while ( 1 ) {
V_69:
if ( V_42 ) {
V_40 = 1 ;
error = F_55 ( V_45 ) ;
if ( error == - 1 )
continue;
V_40 = 0 ;
} else {
error = F_56 ( V_45 ) ;
}
if ( error == V_83 ) {
V_42 = ! V_42 ;
} else if ( error == V_84 ) {
V_56 [ V_85 ] . V_50 |=
V_71 ;
goto V_70;
} else {
V_56 [ V_53 ] . V_65 = error ;
break;
}
}
if ( V_39 -> V_86 )
V_39 -> V_86 () ;
if ( ! V_81 ) {
F_49 ( & V_73 ) ;
while ( V_3 && F_23 ( & V_60 ) )
F_47 () ;
}
V_79:
if ( F_23 ( & V_76 ) != - 1 ) {
int V_87 = F_23 ( & V_76 ) ;
if ( V_56 [ V_87 ] . V_64 )
V_78 = V_56 [ V_87 ] . V_64 -> V_77 ;
else
V_78 = 0 ;
}
if ( V_8 . V_75 )
V_8 . V_75 () ;
if ( V_54 )
F_43 () ;
V_56 [ V_53 ] . V_50 &=
~ ( V_58 | V_72 ) ;
V_56 [ V_53 ] . V_57 -- ;
F_44 () ;
F_45 ( & V_59 ) ;
F_48 ( & V_46 , - 1 ) ;
F_49 ( & V_68 ) ;
F_30 () ;
F_46 ( V_51 ) ;
return V_56 [ V_53 ] . V_65 ;
}
int
F_57 ( int V_88 , int V_89 , int V_90 , struct V_14 * V_15 )
{
struct V_44 V_91 ;
struct V_44 * V_45 = & V_91 ;
V_45 -> V_53 = F_26 () ;
V_45 -> V_48 = V_88 ;
V_45 -> V_89 = V_89 ;
V_45 -> V_92 = V_90 ;
V_45 -> V_93 = 0 ;
V_45 -> V_49 = V_15 ;
if ( F_25 ( V_45 ) )
return 0 ;
if ( V_56 [ V_45 -> V_53 ] . V_57 != 0 )
return 0 ;
return F_34 ( V_45 , V_15 , V_58 ) ;
}
int F_58 ( int V_53 , void * V_15 )
{
#ifdef F_51
struct V_44 V_91 ;
struct V_44 * V_45 = & V_91 ;
memset ( V_45 , 0 , sizeof( struct V_44 ) ) ;
V_45 -> V_53 = V_53 ;
V_45 -> V_49 = V_15 ;
if ( V_56 [ V_45 -> V_53 ] . V_57 == 0 &&
F_42 ( & V_68 ) ) {
F_34 ( V_45 , V_15 , V_72 ) ;
return 0 ;
}
#endif
return 1 ;
}
static void F_59 ( struct V_94 * V_95 , const char * V_96 ,
unsigned V_97 )
{
unsigned long V_51 ;
if ( ! V_40 || F_23 ( & V_46 ) != - 1 || V_42 )
return;
F_37 ( V_51 ) ;
F_60 ( V_96 , V_97 ) ;
F_46 ( V_51 ) ;
}
static void F_61 ( int V_98 )
{
if ( ! V_39 ) {
F_8 ( V_43 L_11 ) ;
return;
}
if ( ! V_40 ) {
#ifdef F_24
if ( ! V_42 )
F_8 ( V_43 L_12 ) ;
#else
F_8 ( V_43 L_13 ) ;
#endif
}
F_62 () ;
}
static int F_63 ( struct V_99 * V_100 ,
unsigned long V_101 ,
void * V_102 )
{
if ( V_42 )
F_64 ( L_14 , ( char * ) V_102 ) ;
F_62 () ;
return V_103 ;
}
void __weak F_65 ( void )
{
}
void T_1 F_66 ( void )
{
V_104 = false ;
if ( V_105 )
F_65 () ;
F_67 ( V_106 ) ;
}
static void F_68 ( void )
{
if ( ! V_105 ) {
V_105 = 1 ;
F_11 () ;
if ( ! V_104 )
F_65 () ;
F_69 ( & V_107 ,
& V_108 ) ;
#ifdef F_70
F_71 ( 'g' , & V_109 ) ;
#endif
if ( V_2 && ! V_110 ) {
F_72 ( & V_111 ) ;
V_110 = 1 ;
}
}
}
static void F_73 ( void )
{
if ( V_105 ) {
V_105 = 0 ;
F_74 ( & V_107 ,
& V_108 ) ;
F_75 () ;
#ifdef F_70
F_76 ( 'g' , & V_109 ) ;
#endif
if ( V_110 ) {
F_77 ( & V_111 ) ;
V_110 = 0 ;
}
}
}
static void F_78 ( unsigned long V_112 )
{
F_62 () ;
F_48 ( & V_113 , 0 ) ;
}
void F_79 ( void )
{
if ( F_23 ( & V_113 ) ||
F_23 ( & V_46 ) != - 1 ||
F_23 ( & V_41 ) )
return;
F_36 ( & V_113 ) ;
F_80 ( & V_114 ) ;
}
static void F_81 ( void )
{
V_115 = 0 ;
F_8 ( V_43 L_15 ) ;
F_62 () ;
}
int F_82 ( struct V_116 * V_117 )
{
int V_6 ;
F_83 ( & V_118 ) ;
if ( V_39 ) {
F_84 ( & V_118 ) ;
F_8 ( V_12 L_16
L_17 ) ;
return - V_119 ;
}
if ( V_117 -> V_120 ) {
V_6 = V_117 -> V_120 () ;
if ( V_6 ) {
F_84 ( & V_118 ) ;
return V_6 ;
}
}
V_39 = V_117 ;
F_84 ( & V_118 ) ;
F_8 ( V_27 L_18 ,
V_117 -> V_121 ) ;
F_68 () ;
if ( V_115 )
F_81 () ;
return 0 ;
}
void F_85 ( struct V_116 * V_122 )
{
F_86 ( V_40 ) ;
F_73 () ;
F_83 ( & V_118 ) ;
F_27 ( V_39 != V_122 ) ;
V_39 = NULL ;
F_84 ( & V_118 ) ;
F_8 ( V_27
L_19 ,
V_122 -> V_121 ) ;
}
int F_87 ( void )
{
int V_20 = V_39 -> V_123 () ;
if ( V_20 == V_124 )
return - 1 ;
if ( ! V_42 )
return V_20 ;
if ( V_20 == 127 )
return 8 ;
return V_20 ;
}
void F_62 ( void )
{
F_36 ( & V_41 ) ;
F_88 () ;
F_89 () ;
F_88 () ;
F_45 ( & V_41 ) ;
}
static int T_1 F_90 ( char * V_1 )
{
V_115 = 1 ;
F_67 ( V_125 ) ;
if ( V_105 )
F_81 () ;
return 0 ;
}
