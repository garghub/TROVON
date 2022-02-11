static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_2 -> V_3 , V_2 ) ;
F_3 ( V_2 -> V_4 , V_5 ) ;
}
struct V_1 * T_1 F_4 ( int V_6 )
{
struct V_1 * V_2 ;
unsigned * V_7 ;
int V_4 ;
int V_8 = 0 ;
V_2 = F_5 ( sizeof( struct V_9 ) ) ;
if ( ! V_2 )
return F_6 ( - V_10 ) ;
if ( V_6 >= 0 ) {
sprintf ( V_2 -> V_11 , L_1 , V_6 ) ;
F_7 ( V_2 ) ;
V_3 = V_2 -> V_3 ;
V_4 = V_2 -> V_4 ;
} else {
V_4 = V_2 -> V_4 = V_12 ;
}
if ( V_4 > 0x1ff ) {
V_8 = F_8 ( V_2 , V_4 ) ;
} else if ( V_4 != 0 ) {
V_8 = - V_13 ;
} else {
for ( V_7 = V_14 ; * V_7 && F_8 ( V_2 , * V_7 ) < 0 ; V_7 ++ )
;
if ( ! * V_7 )
V_8 = - V_15 ;
}
if ( V_8 )
goto V_16;
V_8 = F_9 ( V_2 ) ;
if ( V_8 )
goto V_17;
return V_2 ;
V_17:
F_1 ( V_2 ) ;
V_16:
F_10 ( V_2 ) ;
return F_6 ( V_8 ) ;
}
static int T_1 F_8 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_19 ;
static unsigned V_20 ;
int V_21 = V_22 ;
int V_23 ;
if( V_24 && V_20 ++ == 0 )
F_11 ( L_2 , V_25 ) ;
if ( ! F_12 ( V_18 , V_5 , V_2 -> V_11 ) )
return - V_26 ;
V_2 -> V_3 = V_3 ;
switch ( V_2 -> V_3 )
{
case 0 :
V_2 -> V_3 = F_13 ( V_18 , V_21 ) ;
if ( V_2 -> V_3 )
break;
case 1 :
V_23 = - V_27 ;
goto V_28;
case 2 :
V_2 -> V_3 = 9 ;
break;
case 0xff :
V_2 -> V_3 = 0 ;
break;
default:
break;
}
if ( V_2 -> V_3 ) {
V_23 = F_14 ( V_2 -> V_3 , V_29 , 0 , V_2 -> V_11 , V_2 ) ;
if ( V_23 )
goto V_28;
}
V_2 -> V_4 = V_18 ;
V_19 = F_15 ( V_2 ) ;
F_16 ( & V_19 -> V_30 ) ;
V_19 -> V_21 = V_21 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_34 * 2 ;
if( V_21 == V_35 )
F_11 ( L_3 ,
V_2 -> V_11 , V_36 , V_18 , V_2 -> V_3 ) ;
if( V_21 == V_37 ) {
if( V_2 -> V_3 )
F_11 ( L_4 ,
V_2 -> V_11 , V_36 , V_18 , V_2 -> V_3 ) ;
else
F_11 ( L_5 ,
V_2 -> V_11 , V_36 , V_18 ) ;
}
return 0 ;
V_28:
F_3 ( V_18 , V_5 ) ;
return V_23 ;
}
static int T_1 F_13 ( int V_18 , int V_21 )
{
int V_38 = 0 ;
int V_39 , V_40 , V_41 ;
if( V_21 == V_35 )
{
F_17 ( 0 , V_18 + V_42 ) ;
F_18 ( V_18 + V_42 ) ;
F_19 ( 333 ) ;
}
if( V_21 == V_37 )
{
F_18 ( V_18 ) ;
F_17 ( 0 , V_18 ) ;
F_17 ( 0 , V_18 + V_43 ) ;
}
for( V_39 = 0 ; V_44 [ V_39 ] != 0 ; V_39 ++ )
{
V_38 = V_44 [ V_39 ] ;
for( V_40 = 0xFFFF ; V_40 > 0 ; V_40 -- )
{
if( V_21 == V_35 )
{
V_41 = ( F_18 ( V_18 + V_45 ) & 3 ) ;
if( V_41 == 1 )
return V_38 ;
}
if( V_21 == V_37 )
{
if( ( F_18 ( V_18 + V_46 ) & V_47 ) != 0 )
return V_38 ;
}
}
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
if( V_2 -> V_3 == 0 )
{
if( V_19 -> V_21 == V_37 )
{
F_21 ( & V_48 ) ;
V_48 . V_49 = V_50 ;
V_48 . V_51 = ( unsigned long ) V_2 ;
V_48 . V_52 = V_53 + V_34 / 20 ;
F_22 ( & V_48 ) ;
}
else
{
F_11 ( V_54 L_6 , V_2 -> V_11 ) ;
return - V_55 ;
}
}
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
F_25 ( V_2 , 1 ) ;
F_26 ( V_2 ) ;
if( V_19 -> V_56 == 1 )
F_27 ( V_2 , V_19 -> V_57 ) ;
return 0 ;
}
static void F_28 ( int V_18 )
{
int V_58 = 0 ;
while( V_58 ++ < 5 && ( F_18 ( V_18 + V_46 ) & V_47 ) == 0 )
F_19 ( 1 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_59 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
int V_18 = V_2 -> V_4 ;
if( V_19 -> V_21 == V_37 )
{
F_18 ( V_18 ) ;
F_17 ( 0 , V_18 ) ;
F_17 ( 0 , V_18 + V_43 ) ;
F_28 ( V_18 ) ;
F_17 ( 0 , V_18 + V_60 ) ;
}
if( V_19 -> V_21 == V_35 )
{
F_17 ( 0 , V_18 + V_42 ) ;
F_18 ( V_18 + V_42 ) ;
if ( V_59 )
F_29 ( 333 ) ;
else
F_19 ( 333 ) ;
}
F_30 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_61 V_62 ;
struct V_63 * V_64 = (struct V_63 * ) & V_62 . V_65 ;
struct V_9 * V_19 = F_15 ( V_2 ) ;
int V_18 = V_2 -> V_4 ;
int V_66 , V_39 = 0 ;
strcpy ( V_62 . V_67 , L_7 ) ;
#ifdef F_31
if( V_19 -> V_21 == V_35 )
{
V_64 -> V_66 = sizeof( V_68 ) ;
V_64 -> V_51 = V_68 ;
}
else
#endif
#ifdef F_32
if( V_19 -> V_21 == V_37 )
{
V_64 -> V_66 = sizeof( V_69 ) ;
V_64 -> V_51 = V_69 ;
}
else
#endif
{
F_11 ( V_70 L_8 , V_2 -> V_11 ) ;
return;
}
if( V_19 -> V_21 == V_35 && V_64 -> V_66 != 5983 )
{
F_11 ( V_54 L_9 , V_2 -> V_11 ) ;
return;
}
if( V_19 -> V_21 == V_37 && V_64 -> V_66 != 2501 )
{
F_11 ( V_54 L_10 , V_2 -> V_11 ) ;
return;
}
if( V_19 -> V_21 == V_35 )
{
while( ++ V_39 < 65536 )
{
if( ( F_18 ( V_18 + V_45 ) & 3 ) == 1 )
break;
}
if( V_39 == 65536 )
return;
}
V_39 = 0 ;
V_66 = V_64 -> V_66 ;
while( V_66 -- )
{
F_17 ( V_64 -> V_51 [ V_39 ] , V_18 ) ;
V_39 ++ ;
}
if( V_24 > 1 )
F_11 ( L_11 ,
V_2 -> V_11 , V_39 , V_64 -> V_66 ) ;
if( V_19 -> V_21 == V_35 )
F_17 ( 1 , V_18 + V_71 ) ;
else
F_18 ( V_18 ) ;
if( V_19 -> V_21 == V_37 )
{
F_28 ( V_18 ) ;
F_18 ( V_18 ) ;
}
}
static int F_27 ( struct V_1 * V_2 , int V_56 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
int V_18 = V_2 -> V_4 ;
if( V_19 -> V_21 == V_35 )
{
while( ( F_18 ( V_18 + V_45 ) & V_72 ) == 0 )
{
F_17 ( 0 , V_18 + V_73 ) ;
if( ( F_18 ( V_18 + V_45 ) & 0x03 ) == V_74 )
F_33 ( V_2 ) ;
F_34 () ;
}
F_17 ( 2 , V_18 ) ;
F_17 ( 0 , V_18 ) ;
F_17 ( V_75 , V_18 ) ;
F_17 ( V_56 , V_18 ) ;
}
if( V_19 -> V_21 == V_37 )
{
while( F_18 ( V_18 + V_46 ) & V_76 )
{
F_17 ( 0 , V_18 + V_73 ) ;
F_33 ( V_2 ) ;
F_34 () ;
}
if( V_56 == 0 )
V_56 = V_53 & 0xFF ;
F_17 ( 2 , V_18 ) ;
F_17 ( 0 , V_18 ) ;
F_17 ( V_75 , V_18 ) ;
F_17 ( V_56 , V_18 ) ;
F_17 ( 0xFF , V_18 ) ;
}
V_19 -> V_57 = 0 ;
while( V_19 -> V_57 == 0 )
{
F_17 ( 0 , V_18 + V_73 ) ;
if( V_19 -> V_21 == V_35 )
{
if( ( F_18 ( V_18 + V_45 ) & 0x03 ) == V_74 )
F_33 ( V_2 ) ;
}
if( V_19 -> V_21 == V_37 )
{
if( F_18 ( V_18 + V_46 ) & V_76 )
F_33 ( V_2 ) ;
}
F_34 () ;
}
if( V_24 > 1 )
F_11 ( V_77 L_12 ,
V_2 -> V_11 , V_19 -> V_57 ) ;
V_19 -> V_56 = 1 ;
return 0 ;
}
static void V_50 ( unsigned long V_78 )
{
int V_18 , V_41 ;
int V_79 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_78 ;
F_35 ( & V_48 ) ;
if( V_2 == NULL )
return;
V_18 = V_2 -> V_4 ;
do {
V_41 = F_18 ( V_18 + V_46 ) ;
if( V_41 & V_76 )
F_33 ( V_2 ) ;
if( V_41 & V_47 )
F_30 ( V_2 ) ;
V_41 = F_18 ( V_18 + V_46 ) ;
} while( ( ++ V_79 < 20 ) && ( V_41 & ( V_76 | V_47 ) ) );
V_48 . V_52 = V_53 + V_34 / 20 ;
F_22 ( & V_48 ) ;
}
static T_2 V_29 ( int V_3 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
struct V_9 * V_19 ;
int V_18 , V_41 ;
int V_79 = 0 ;
V_18 = V_2 -> V_4 ;
V_19 = F_15 ( V_2 ) ;
if( V_19 -> V_21 == V_35 )
{
do {
F_17 ( 0 , V_18 + V_73 ) ;
V_41 = F_18 ( V_18 + V_45 ) ;
if( ( V_41 & 0x03 ) == V_74 )
F_33 ( V_2 ) ;
F_30 ( V_2 ) ;
} while( ++ V_79 < 20 );
}
else
{
do {
V_41 = F_18 ( V_18 + V_46 ) ;
if( V_41 & V_76 )
F_33 ( V_2 ) ;
if( V_41 & V_47 )
F_30 ( V_2 ) ;
V_41 = F_18 ( V_18 + V_46 ) ;
} while( ( ++ V_79 < 20 ) && ( V_41 & ( V_76 | V_47 ) ) );
}
return V_81 ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_82 = 0 ;
int V_83 = 0 ;
struct V_84 * V_85 = NULL ;
struct V_9 * V_19 = F_15 ( V_2 ) ;
int V_18 = V_2 -> V_4 ;
int V_79 = 0 ;
unsigned long V_86 ;
F_36 ( & V_19 -> V_30 , V_86 ) ;
if( V_19 -> V_21 == V_35 )
{
F_17 ( 0 , V_18 ) ;
F_17 ( 0 , V_18 ) ;
F_17 ( V_87 , V_18 ) ;
while( ++ V_79 < 1000000 )
{
F_37 () ;
if( ( F_18 ( V_18 + V_45 ) & 0x03 ) == V_88 )
break;
}
if( V_79 == 1000000 )
{
F_11 ( V_54 L_13 , V_2 -> V_11 ) ;
F_38 ( & V_19 -> V_30 , V_86 ) ;
return;
}
}
if( V_19 -> V_21 == V_35 )
V_82 = F_18 ( V_18 ) & 0xFF ;
else
V_82 = F_18 ( V_18 ) & 0x00FF ;
V_82 |= ( F_18 ( V_18 ) << 8 ) ;
V_83 = F_18 ( V_18 ) ;
V_85 = F_39 ( V_82 ) ;
if( V_85 == NULL )
{
F_11 ( V_54 L_14 ,
V_2 -> V_11 ) ;
V_2 -> V_89 . V_90 ++ ;
while( V_82 -- )
F_18 ( V_18 ) ;
F_38 ( & V_19 -> V_30 , V_86 ) ;
return;
}
V_85 -> V_2 = V_2 ;
F_40 ( V_85 , V_82 ) ;
V_85 -> V_91 = F_41 ( V_92 ) ;
F_42 ( V_18 , V_85 -> V_51 , V_82 ) ;
if( V_19 -> V_21 == V_35 )
F_17 ( 1 , V_18 + V_71 ) ;
F_38 ( & V_19 -> V_30 , V_86 ) ;
if( V_82 < 0 || V_82 > V_93 )
{
F_11 ( V_54 L_15 ,
V_2 -> V_11 , V_82 ) ;
V_2 -> V_89 . V_94 ++ ;
F_43 ( V_85 ) ;
return;
}
if( V_83 == V_95 )
{
V_19 -> V_57 = V_85 -> V_51 [ 0 ] ;
F_43 ( V_85 ) ;
return;
}
if( V_83 != V_96 )
{
F_11 ( V_54 L_16 , V_2 -> V_11 , V_83 ) ;
V_2 -> V_89 . V_94 ++ ;
F_43 ( V_85 ) ;
return;
}
F_44 ( V_85 ) ;
F_45 ( V_85 , 3 ) ;
F_46 ( V_85 ) ;
V_2 -> V_89 . V_97 ++ ;
V_2 -> V_89 . V_98 += V_85 -> V_99 ;
F_47 ( V_85 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
int V_18 = V_2 -> V_4 ;
V_2 -> V_89 . V_94 ++ ;
if( V_19 -> V_21 == V_37 )
{
if( ( F_18 ( V_18 + V_46 ) & V_47 ) == 0 )
F_11 ( V_54 L_17 , V_2 -> V_11 ) ;
}
F_11 ( V_54 L_18 , V_2 -> V_11 ) ;
F_23 ( V_2 ) ;
F_49 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static T_3 F_50 ( struct V_84 * V_85 ,
struct V_1 * V_2 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
int V_18 = V_2 -> V_4 ;
unsigned long V_86 ;
F_51 ( V_2 ) ;
F_36 ( & V_19 -> V_30 , V_86 ) ;
if( V_19 -> V_21 == V_35 )
while( ( F_18 ( V_18 + V_45 ) & V_72 ) == 0 )
F_52 () ;
if( V_19 -> V_21 == V_37 )
while( ( F_18 ( V_18 + V_46 ) & V_47 ) == 0 )
F_52 () ;
F_17 ( V_85 -> V_99 , V_18 ) ;
if( V_19 -> V_21 == V_35 )
F_17 ( V_85 -> V_99 >> 8 , V_18 ) ;
else
F_17 ( ( V_85 -> V_99 >> 8 ) & 0x0FF , V_18 ) ;
F_17 ( V_100 , V_18 ) ;
if( V_19 -> V_21 == V_35 )
while( ( F_18 ( V_18 + V_45 ) & V_72 ) == 0 ) ;
F_53 ( V_18 , V_85 -> V_51 , V_85 -> V_99 ) ;
if( V_19 -> V_21 == V_35 )
F_17 ( 1 , V_18 + V_71 ) ;
F_38 ( & V_19 -> V_30 , V_86 ) ;
V_2 -> V_89 . V_101 ++ ;
V_2 -> V_89 . V_102 += V_85 -> V_99 ;
F_54 ( V_85 ) ;
return V_103 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if( V_24 >= 3 )
F_11 ( L_19 , V_2 -> V_11 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_61 * V_62 , int V_104 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
struct V_105 * V_106 = (struct V_105 * ) & V_62 -> V_107 ;
struct V_108 * V_109 = & V_19 -> V_110 ;
switch( V_104 )
{
case V_111 :
F_27 ( V_2 , V_106 -> V_112 . V_113 ) ;
V_109 -> V_114 = V_106 -> V_112 . V_114 ;
V_109 -> V_113 = V_19 -> V_57 ;
V_2 -> V_115 [ 0 ] = 0xFF ;
V_2 -> V_116 [ 0 ] = V_109 -> V_113 ;
V_2 -> V_117 = 1 ;
return 0 ;
case V_118 :
V_106 -> V_112 . V_114 = V_109 -> V_114 ;
V_106 -> V_112 . V_113 = V_109 -> V_113 ;
return 0 ;
default:
return - V_119 ;
}
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_9 * V_19 = F_15 ( V_2 ) ;
if( V_19 -> V_21 == V_37 && V_2 -> V_3 == 0 )
F_35 ( & V_48 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int T_1 F_58 ( void )
{
if ( V_12 == 0 )
F_11 ( V_54 L_20 ,
V_36 ) ;
V_120 = F_4 ( - 1 ) ;
return F_59 ( V_120 ) ;
}
static void T_4 F_60 ( void )
{
F_61 ( V_120 ) ;
F_1 ( V_120 ) ;
F_10 ( V_120 ) ;
}
