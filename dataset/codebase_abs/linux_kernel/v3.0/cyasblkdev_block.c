int F_1 (
int V_1
)
{
int V_2 = V_3 -> V_4 ;
V_5 ;
V_3 -> V_4 = V_1 ;
return V_2 ;
}
static struct V_6 * F_2 (
struct V_7 * V_8
)
{
struct V_6 * V_9 ;
V_5 ;
F_3 ( & V_10 ) ;
V_9 = V_8 -> V_11 ;
if ( V_9 && ( V_9 -> V_12 == 0 ) )
V_9 = NULL ;
if ( V_9 ) {
V_9 -> V_12 ++ ;
#ifndef F_4
F_5 (
L_1 , V_9 -> V_12 ) ;
#endif
}
F_6 ( & V_10 ) ;
return V_9 ;
}
static void F_7 (
struct V_6 * V_9
)
{
V_5 ;
F_3 ( & V_10 ) ;
if ( V_9 ) {
V_9 -> V_12 -- ;
#ifndef F_8
F_5 (
L_2 , V_9 -> V_12 ) ;
#endif
} else {
#ifndef F_8
F_5 (
L_3 ,
V_9 -> V_12 ) ;
#endif
F_6 ( & V_10 ) ;
return;
}
if ( V_9 -> V_12 == 0 ) {
F_9 ( V_9 -> V_13 ) ;
F_9 ( V_9 -> V_14 ) ;
F_9 ( V_9 -> V_15 ) ;
F_10 ( & V_9 -> V_16 ) ;
if ( V_17 !=
F_11 ( V_9 -> V_18 , 0 , 0 , 0 , 0 ) ) {
#ifndef F_8
F_5 (
L_4 ) ;
#endif
}
if ( V_17 !=
F_11 ( V_9 -> V_18 , 1 , 0 , 0 , 0 ) ) {
#ifndef F_8
F_5 (
L_5 ) ;
#endif
}
if ( V_17 !=
F_12 ( V_9 -> V_18 , 0 , 0 ) ) {
#ifndef F_8
F_5 (
L_6 ) ;
#endif
}
#ifdef F_13
F_14 ( F_15 () ) ;
#endif
V_3 = NULL ;
F_16 ( V_9 ) ;
}
#ifndef F_8
F_5 (
L_7 ,
V_9 -> V_12 ) ;
#endif
F_6 ( & V_10 ) ;
}
static int F_17 (
struct V_19 * V_20 ,
T_1 V_21
)
{
struct V_6 * V_9 = F_2 ( V_20 -> V_22 ) ;
int V_23 = - V_24 ;
V_5 ;
if ( V_9 ) {
if ( V_9 -> V_12 == 2 )
F_18 ( V_20 ) ;
V_23 = 0 ;
if ( V_20 -> V_22 == V_9 -> V_13 ) {
if ( ( V_21 & V_25 ) && V_9 -> V_26 ) {
#ifndef F_8
F_5 (
L_8
L_9 ) ;
#endif
F_7 ( V_9 ) ;
V_23 = - V_27 ;
}
} else if ( V_20 -> V_22 == V_9 -> V_14 ) {
if ( ( V_21 & V_25 ) && V_9 -> V_28 ) {
#ifndef F_8
F_5 (
L_8
L_9 ) ;
#endif
F_7 ( V_9 ) ;
V_23 = - V_27 ;
}
} else if ( V_20 -> V_22 == V_9 -> V_15 ) {
if ( ( V_21 & V_25 ) && V_9 -> V_29 ) {
#ifndef F_8
F_5 (
L_8
L_9 ) ;
#endif
F_7 ( V_9 ) ;
V_23 = - V_27 ;
}
}
}
return V_23 ;
}
static int F_19 (
struct V_7 * V_8 ,
T_1 V_21
)
{
struct V_6 * V_9 = V_8 -> V_11 ;
V_5 ;
F_7 ( V_9 ) ;
return 0 ;
}
static int F_20 (
struct V_19 * V_20 ,
T_1 V_21 ,
unsigned int V_30 ,
unsigned long V_31
)
{
V_5 ;
if ( V_30 == V_32 ) {
struct V_33 V_34 ;
memset ( & V_34 , 0 , sizeof( struct V_33 ) ) ;
V_34 . V_35 = F_21 ( V_20 -> V_22 ) / ( 4 * 16 ) ;
V_34 . V_36 = 4 ;
V_34 . V_37 = 16 ;
V_34 . V_38 = F_22 ( V_20 ) ;
return F_23 ( ( void V_39 * ) V_31 , & V_34 , sizeof( V_34 ) )
? - V_40 : 0 ;
}
return - V_41 ;
}
unsigned int F_24 ( struct V_7 * V_42 , unsigned int V_43 )
{
struct V_6 * V_9 ;
#ifndef F_8
F_5 ( L_10 ) ;
#endif
if ( V_42 )
V_9 = V_42 -> V_11 ;
else {
#ifndef F_8
F_5 (
L_11
L_12 ) ;
#endif
}
return 0 ;
}
int F_25 ( struct V_7 * V_42 )
{
#ifndef F_8
if ( V_42 )
F_5 (
L_13
L_14 , V_3 -> V_12 ) ;
#endif
return 0 ;
}
static int F_26 (
struct V_44 * V_45 ,
struct V_46 * V_47
)
{
struct V_6 * V_9 = V_45 -> V_48 ;
int V_49 = V_50 ;
V_5 ;
if ( ! V_9 || ! V_9 -> V_18 ) {
#ifndef F_8
F_5 ( V_51
L_15 ,
V_47 -> V_52 -> V_53 ) ;
#endif
V_49 = V_54 ;
}
if ( V_9 -> V_55 ) {
F_27 ( V_9 -> V_16 . V_16 ) ;
V_49 = V_56 ;
}
if ( F_28 ( V_47 ) + F_29 ( V_47 ) > F_21 ( V_47 -> V_52 ) ) {
F_5 ( L_16 ) ;
V_49 = V_54 ;
}
return V_49 ;
}
static void F_30 (
T_2 V_57 ,
T_3 type ,
T_4 V_58 ,
T_4 V_59 ,
T_4 V_60 ,
T_5 V_61 ,
T_6 V_62
)
{
int V_63 = 0 ;
V_5 ;
if ( V_62 != V_17 ) {
#ifndef F_8
F_5 (
L_17 ,
V_64 , V_61 , V_62 , V_60 ) ;
#endif
}
#ifndef F_8
F_5 (
L_18
L_19 ,
V_64 , ( unsigned int ) V_3 -> V_16 . V_47 , V_62 ,
( unsigned int ) F_29 ( V_3 -> V_16 . V_47 ) ) ;
#endif
while ( F_31 ( V_3 -> V_16 . V_47 ,
V_62 , F_29 ( V_3 -> V_16 . V_47 ) * 512 ) ) {
V_63 ++ ;
}
#ifndef F_8
F_5 (
L_20
L_21 , V_64 ,
( int ) F_29 ( V_3 -> V_16 . V_47 ) , V_62 ,
V_63
) ;
#endif
F_32 ( & V_3 -> V_65 ) ;
if ( ! F_33 ( V_3 -> V_16 . V_16 ) ) {
V_3 -> V_16 . V_47 = F_34 ( V_3 -> V_16 . V_16 ) ;
#ifndef F_8
F_5 ( L_22
L_23 ,
V_64 , V_3 -> V_16 . V_47 ) ;
#endif
}
if ( V_3 -> V_16 . V_47 ) {
F_35 ( & V_3 -> V_65 ) ;
#ifndef F_8
F_5 ( L_24
L_25 , V_64 , V_3 -> V_16 . V_47 ) ;
#endif
V_3 -> V_16 . V_66 ( & V_3 -> V_16 , V_3 -> V_16 . V_47 ) ;
} else {
F_35 ( & V_3 -> V_65 ) ;
}
}
static int F_36 (
struct V_44 * V_45 ,
struct V_46 * V_47
)
{
struct V_6 * V_9 = V_45 -> V_48 ;
int V_67 = 0 ;
int V_23 = V_17 ;
T_4 V_68 = 0 ;
T_4 V_69 = 0 ;
int V_70 = 0 ;
int V_71 = 0 ;
V_5 ;
F_32 ( & V_9 -> V_65 ) ;
V_67 = F_37 ( V_45 -> V_16 , V_47 , V_9 -> V_72 ) ;
if ( V_47 -> V_52 == V_9 -> V_13 ) {
V_70 = V_9 -> V_73 ;
V_68 = F_28 ( V_47 ) + V_3 -> V_74 ;
V_69 = F_29 ( V_47 ) ;
V_71 = V_3 -> V_75 ;
#ifndef F_8
F_5 ( L_26
L_27 ,
V_64 , V_68 , ( int ) F_29 ( V_47 ) ,
V_71 ) ;
#endif
} else if ( V_47 -> V_52 == V_9 -> V_14 ) {
V_70 = V_9 -> V_76 ;
V_68 = F_28 ( V_47 ) + V_3 -> V_77 ;
V_69 = F_29 ( V_47 ) ;
V_71 = V_3 -> V_78 ;
#ifndef F_8
F_5 ( L_28
L_29 , V_64 ,
V_68 , ( int ) F_29 ( V_47 ) , V_71 ) ;
#endif
} else if ( V_47 -> V_52 == V_9 -> V_15 ) {
V_70 = V_9 -> V_79 ;
V_68 = F_28 ( V_47 ) + V_3 -> V_80 ;
V_69 = F_29 ( V_47 ) ;
V_71 = V_3 -> V_81 ;
#ifndef F_8
F_5 ( L_30
L_27 , V_64 ,
V_68 , ( int ) F_29 ( V_47 ) , V_71 ) ;
#endif
}
#ifndef F_8
else {
F_5 (
L_31 , V_64 ) ;
}
#endif
F_35 ( & V_9 -> V_65 ) ;
if ( F_38 ( V_47 ) == V_82 ) {
#ifndef F_8
F_5 ( L_32
L_33 ,
V_64 , V_68 , V_69 , ( T_4 ) V_9 -> V_72 ) ;
#endif
V_23 = F_39 ( V_9 -> V_18 , V_70 , 0 ,
V_71 , V_68 , V_9 -> V_72 , V_69 ,
( V_83 ) F_30 ) ;
if ( V_23 != V_17 ) {
#ifndef F_8
F_5 ( L_34
L_35 , V_64 , V_23 ,
F_28 ( V_47 ) , V_71 ) ;
F_5 ( L_36
L_37 , V_64 , ( T_4 ) V_47 ) ;
#endif
while ( F_31 ( V_47 ,
( V_23 == V_17 ) ,
V_69 * 512 ) )
;
V_45 -> V_47 = NULL ;
}
} else {
V_23 = F_40 ( V_9 -> V_18 , V_70 , 0 ,
V_71 , V_68 , V_9 -> V_72 , V_69 ,
( V_83 ) F_30 ) ;
if ( V_23 != V_17 ) {
#ifndef F_8
F_5 ( L_38
L_39 ,
V_64 , V_23 , F_28 ( V_47 ) , V_71 ) ;
#endif
while ( F_31 ( V_47 ,
( V_23 == V_17 ) ,
V_69 * 512 ) )
;
V_45 -> V_47 = NULL ;
}
}
return V_23 ;
}
static void F_41 (
T_2 V_84 ,
T_7 V_85 ,
T_4 V_58 ,
T_8 V_86 ,
void * V_87
)
{
#ifndef F_8
F_5 ( L_40
L_41 , V_64 , V_85 , V_58 , V_86 , V_87 ) ;
#endif
switch ( V_86 ) {
case V_88 :
break;
case V_89 :
break;
case V_90 :
break;
default:
break;
}
}
T_4 F_42 ( int V_70 , int V_91 )
{
int V_92 , V_49 ;
T_9 * V_93 ;
bool V_94 = false ;
V_5 ;
V_93 = F_43 ( 1024 , V_95 ) ;
F_44 ( V_3 -> V_72 , V_93 , 512 ) ;
#ifndef F_8
F_5 (
L_42 , V_64 ) ;
#endif
for ( V_92 = 0 ; V_92 < V_96 ; V_92 ++ ) {
#ifndef F_8
F_5 ( L_43
L_44 , V_64 ,
( unsigned int ) V_3 -> V_72 ) ;
#endif
V_49 = F_45 (
V_3 -> V_18 ,
V_70 ,
0 ,
V_91 ,
V_92 ,
V_3 -> V_72 ,
1
) ;
if ( ( V_93 [ 510 ] == 0x55 ) && ( V_93 [ 511 ] == 0xaa ) ) {
if ( V_93 [ 0 ] == 0xEB ) {
#ifndef F_8
F_5 (
L_45
L_46 ,
V_64 , V_92 ) ;
#endif
V_94 = true ;
break;
}
}
if ( V_49 != 0 ) {
#ifndef F_8
F_5 ( L_47 ,
V_64 ) ;
#endif
break;
}
}
F_16 ( V_93 ) ;
if ( V_94 ) {
return V_92 ;
} else {
#ifndef F_8
F_5 (
L_48 ,
V_64 ) ;
#endif
return 0 ;
}
}
static int F_46 ( int V_70 ,
struct V_6 * V_9 ,
int V_97 ,
int V_98 )
{
int V_23 = 0 ;
T_10 V_99 ;
int V_71 ;
T_11 V_100 = { 0 } ;
#ifndef F_8
F_5 ( L_49
L_50
L_51
L_52 ,
V_64 ,
V_101 . V_102 . type ,
V_101 . V_102 . V_103 ,
V_101 . V_102 . V_104 ,
V_101 . V_102 . V_105 ,
V_101 . V_102 . V_106 ,
V_101 . V_102 . V_107 ,
V_101 . V_102 . V_108
) ;
#endif
if ( V_101 . V_102 . V_107 ) {
#ifndef F_8
F_5 (
L_53 , V_64 ) ;
#endif
V_23 = F_11 (
V_9 -> V_18 , V_70 , 0 , 0 , 0 ) ;
if ( V_23 != V_17 ) {
#ifndef F_8
F_5 ( L_54
L_55 , V_64 ) ;
#endif
goto V_109;
}
goto V_109;
}
V_100 . V_58 = 0 ;
V_100 . V_59 = 0 ;
V_100 . V_85 = V_70 ;
V_23 = F_47 ( V_9 -> V_18 ,
& V_100 , 0 , 0 ) ;
if ( V_23 != V_17 ) {
#ifndef F_8
F_5 ( L_56
L_57 ,
V_64 , V_70 , V_23 ) ;
#endif
goto V_109;
}
if ( V_110 == V_70 ) {
if ( V_111 > 0 ) {
V_23 = F_48 (
V_9 -> V_18 , V_70 , 0 ,
V_111 , 0 , 0 ) ;
if ( ( V_23 != V_17 ) &&
( V_23 != V_112 ) ) {
#ifndef F_8
F_5 ( L_58
L_59
L_60 ,
V_64 , V_23 ) ;
#endif
V_99 = ( T_10 )
( V_100 . V_102 . V_113 ) ;
V_71 = 0 ;
} else if ( V_23 == V_112 ) {
#ifndef F_8
F_5 (
L_61
L_62 ,
V_64 ) ;
#endif
if ( V_100 . V_102 . V_113 !=
V_111 ) {
V_23 = F_49 (
V_9 -> V_18 ,
V_70 , 0 , 0 , 0 ) ;
if ( V_23 == V_17 ) {
V_23 = F_48 (
V_9 -> V_18 , V_70 , 0 ,
V_111 , 0 , 0 ) ;
if ( V_23 == V_17 ) {
V_100 . V_85 = V_70 ;
V_100 . V_58 = 0 ;
V_100 . V_59 = 1 ;
} else {
#ifndef F_8
F_5 (
L_61
L_63
L_64 , V_64 , V_23 ) ;
#endif
V_100 . V_85 = V_70 ;
V_100 . V_58 = 0 ;
V_100 . V_59 = 0 ;
}
V_23 = F_47 (
V_9 -> V_18 ,
& V_100 , 0 , 0 ) ;
if ( V_23 != V_17 ) {
#ifndef F_8
F_5 (
L_65
L_66 ,
V_64 , V_70 , V_23 ) ;
#endif
goto V_109;
} else {
V_99 = ( T_10 )
( V_100 . V_102 . V_113 ) ;
V_71 =
V_100 . V_59 ;
}
} else {
#ifndef F_8
F_5 (
L_67
L_68 ,
V_64 , V_23 ) ;
#endif
V_100 . V_85 = V_70 ;
V_100 . V_58 = 0 ;
V_100 . V_59 = 1 ;
V_23 = F_47 (
V_9 -> V_18 , & V_100 , 0 , 0 ) ;
if ( V_23 != V_17 ) {
#ifndef F_8
F_5 (
L_65
L_69
L_70 , V_64 ,
V_70 , V_23 ) ;
#endif
goto V_109;
}
V_99 = ( T_10 )
( V_100 . V_102 . V_113 ) ;
V_71 =
V_100 . V_59 ;
}
} else {
#ifndef F_8
F_5 ( L_71
L_72 ,
V_64 ) ;
#endif
V_100 . V_85 = V_70 ;
V_100 . V_58 = 0 ;
V_100 . V_59 = 1 ;
V_23 = F_47 (
V_9 -> V_18 , & V_100 , 0 , 0 ) ;
if ( V_23 != V_17 ) {
#ifndef F_8
F_5 (
L_65
L_73
L_74 ,
V_64 , V_70 , V_23 ) ;
#endif
goto V_109;
} else {
V_99 = ( T_10 )
( V_100 . V_102 . V_113 ) ;
V_71 = V_100 . V_59 ;
}
}
} else {
#ifndef F_8
F_5 (
L_61
L_75 , V_64 ) ;
#endif
V_99 = ( T_10 )
( V_100 . V_102 . V_113 -
V_111 ) ;
V_71 = 1 ;
}
}
#ifndef F_8
else {
F_5 (
L_76 , V_64 ,
V_111 ) ;
V_99 = ( T_10 )
( V_100 . V_102 . V_113 ) ;
V_71 = 0 ;
}
#endif
} else {
V_99 = ( T_10 )
( V_100 . V_102 . V_113 ) ;
V_71 = 0 ;
}
if ( ( V_70 == 0 ) ||
( V_97 == 1 ) ) {
sprintf ( V_9 -> V_13 -> V_53 ,
L_77 , V_98 ) ;
#ifndef F_8
F_5 (
L_78
L_79 ,
V_64 , ( unsigned long )
V_100 . V_102 . V_113 ,
V_100 . V_102 . V_105 ,
( unsigned long )
V_100 . V_102 . V_114 ,
( T_10 ) V_99
) ;
#endif
#ifndef F_8
F_5 ( L_80
L_81 , V_64 , ( int ) V_99 ) ;
#endif
#ifndef F_8
F_5 ( L_82 ,
V_64 ) ;
#endif
F_50 (
& V_9 -> V_16 , & V_9 -> V_65 ) ;
V_9 -> V_16 . V_115 = F_26 ;
V_9 -> V_16 . V_66 = F_36 ;
V_9 -> V_16 . V_48 = V_9 ;
V_9 -> V_26 = ! V_101 . V_102 . V_104 ;
V_9 -> V_116 = V_101 . V_102 . V_105 ;
V_9 -> V_117 = V_101 . V_102 . type ;
V_9 -> V_73 = V_70 ;
V_9 -> V_13 -> V_118 = V_118 ;
V_9 -> V_13 -> V_119 = V_98 << V_120 ;
V_9 -> V_13 -> V_121 = 8 ;
V_9 -> V_13 -> V_122 = & V_123 ;
V_9 -> V_13 -> V_124 = V_125 ;
V_9 -> V_13 -> V_11 = V_9 ;
V_9 -> V_13 -> V_16 = V_9 -> V_16 . V_16 ;
V_9 -> V_4 = V_126 ;
V_9 -> V_75 = V_71 ;
F_51 ( V_9 -> V_16 . V_16 ,
V_9 -> V_116 ) ;
F_52 ( V_9 -> V_13 ,
V_99 ) ;
#ifndef F_8
F_5 (
L_83 ,
V_64 , ( int ) V_99 ) ;
#endif
if ( V_127 ) {
V_9 -> V_74 =
F_42 (
V_9 -> V_73 ,
V_9 -> V_75 ) ;
} else {
V_9 -> V_74 = 0 ;
}
#ifndef F_8
F_5 (
L_84
L_85 , V_64 ,
V_9 -> V_74 ) ;
F_5 (
L_86 ,
V_64 ,
V_9 -> V_13 -> V_118 ) ;
F_5 (
L_87
L_88 , V_64 ,
V_9 -> V_13 -> V_119 ) ;
F_5 (
L_87
L_89 , V_64 ,
V_9 -> V_13 -> V_121 ) ;
F_5 (
L_87
L_90 ,
V_64 ,
V_9 -> V_13 -> V_53 ) ;
F_5 (
L_87
L_91 , V_64 ,
( unsigned int )
V_9 -> V_13 -> V_128 ) ;
F_5 (
L_87
L_92 , V_64 ,
( unsigned int )
V_9 -> V_13 -> V_16 ) ;
F_5 (
L_87
L_93 ,
V_64 , ( unsigned int )
V_9 -> V_13 -> V_129 ) ;
F_5 (
L_87
L_94 ,
V_64 , ( unsigned int )
V_9 -> V_13 -> V_130 ) ;
F_5 (
L_87
L_95 ,
V_64 , ( unsigned int )
V_9 -> V_13 -> V_131 ) ;
F_5 (
L_87
L_96 ,
V_64 , ( unsigned int )
V_9 -> V_13 -> V_132 ) ;
F_5 (
L_87
L_97 ,
V_64 , ( unsigned int )
V_9 -> V_13 -> V_133 ) ;
#endif
F_53 ( V_9 -> V_13 ) ;
} else if ( ( V_70 == 1 ) &&
( V_97 == 2 ) ) {
V_9 -> V_28 = ! V_101 . V_102 . V_104 ;
V_9 -> V_134 = V_101 . V_102 . V_105 ;
V_9 -> V_135 = V_101 . V_102 . type ;
V_9 -> V_76 = V_70 ;
V_9 -> V_14 -> V_118 = V_118 ;
V_9 -> V_14 -> V_119 = ( V_98 + 1 ) << V_120 ;
V_9 -> V_14 -> V_121 = 8 ;
V_9 -> V_14 -> V_122 = & V_123 ;
V_9 -> V_14 -> V_124 = V_125 ;
V_9 -> V_14 -> V_11 = V_9 ;
V_9 -> V_14 -> V_16 = V_9 -> V_16 . V_16 ;
V_9 -> V_4 = V_126 ;
V_9 -> V_78 = V_71 ;
sprintf ( V_9 -> V_14 -> V_53 ,
L_77 , ( V_98 + 1 ) ) ;
#ifndef F_8
F_5 (
L_98
L_99
L_100
L_101 ,
V_64 ,
( unsigned long )
V_100 . V_102 . V_113 ,
V_100 . V_102 . V_105 ,
( unsigned long )
V_100 . V_102 . V_114 ,
( T_10 ) V_99
) ;
#endif
if ( V_9 -> V_116 >
V_9 -> V_134 ) {
F_51 ( V_9 -> V_16 . V_16 ,
V_9 -> V_116 ) ;
#ifndef F_8
F_5 (
L_102 ,
V_64 ,
V_9 -> V_116 ) ;
#endif
} else {
F_51 ( V_9 -> V_16 . V_16 ,
V_9 -> V_134 ) ;
#ifndef F_8
F_5 (
L_102 ,
V_64 ,
V_9 -> V_134 ) ;
#endif
}
F_52 ( V_9 -> V_14 , V_99 ) ;
if ( V_127 ) {
V_9 -> V_77 =
F_42 (
V_9 -> V_76 ,
V_9 -> V_78 ) ;
} else {
V_9 -> V_77
= 0 ;
}
F_53 ( V_9 -> V_14 ) ;
}
if ( V_71 > 0 ) {
if ( V_9 -> V_15 == NULL ) {
V_9 -> V_15 =
F_54 ( 8 ) ;
if ( V_9 -> V_15 == NULL ) {
F_16 ( V_9 ) ;
V_9 = F_55 ( - V_136 ) ;
return V_9 ;
}
V_99 = ( T_10 )
( V_111 ) ;
V_9 -> V_29 = ! V_101 . V_102 . V_104 ;
V_9 -> V_137 = V_101 . V_102 . V_105 ;
V_9 -> V_79 = V_70 ;
V_9 -> V_15 -> V_118 = V_118 ;
V_9 -> V_15 -> V_119 =
( V_98 + 2 ) << V_120 ;
V_9 -> V_15 -> V_121 = 8 ;
V_9 -> V_15 -> V_122 = & V_123 ;
V_9 -> V_15 -> V_124 = V_125 ;
V_9 -> V_15 -> V_11 = V_9 ;
V_9 -> V_15 -> V_16 = V_9 -> V_16 . V_16 ;
V_9 -> V_80 = 0 ;
sprintf (
V_9 -> V_15 -> V_53 ,
L_77 , ( V_98 + 2 ) ) ;
F_52 ( V_9 -> V_15 ,
V_99 ) ;
F_53 ( V_9 -> V_15 ) ;
}
#ifndef F_8
else {
F_5 (
L_103 ,
V_64 , V_70 ) ;
}
#endif
}
V_109:
return V_23 ;
}
static struct V_6 * F_56 ( void )
{
struct V_6 * V_9 ;
int V_23 = 0 ;
T_6 V_49 = - 1 ;
int V_70 = 0 ;
int V_97 = 0 ;
int V_98 = 0 ;
V_5 ;
V_97 = 0 ;
V_98 = F_57 ( V_138 , V_139 ) ;
if ( V_98 >= V_139 )
return F_55 ( - V_140 ) ;
F_58 ( V_98 , V_138 ) ;
F_58 ( V_98 + 1 , V_138 ) ;
V_9 = F_59 ( sizeof( struct V_6 ) , V_95 ) ;
if ( V_9 ) {
V_3 = V_9 ;
F_60 ( & V_9 -> V_65 ) ;
V_9 -> V_12 = 1 ;
V_9 -> V_141 = & V_123 ;
V_9 -> V_18 = F_61 () ;
if ( 0 == V_9 -> V_18 ) {
#ifndef F_8
F_5 (
L_104 , V_64 ) ;
#endif
V_23 = V_142 ;
goto V_109;
}
#ifndef F_8
F_5 ( L_105 ,
V_64 , ( T_4 ) V_9 -> V_18 ) ;
#endif
V_23 = V_143 ;
V_49 = F_62 ( V_9 -> V_18 , V_144 ) ;
if ( ( V_49 != V_17 ) &&
( V_49 != V_145 ) ) {
#ifndef F_8
F_5 ( L_106
L_107 ,
V_64 , V_49 ) ;
#endif
}
V_49 = F_62 ( V_9 -> V_18 , V_146 ) ;
if ( ( V_49 != V_17 ) &&
( V_49 != V_145 ) ) {
#ifndef F_8
F_5 ( L_106
L_107 ,
V_64 , V_49 ) ;
#endif
}
V_49 = F_63 ( V_9 -> V_18 , 0 , 0x101 ) ;
if ( V_49 != V_17 ) {
#ifndef F_8
F_5 ( L_108
L_109 , V_64 , V_49 ) ;
#endif
goto V_109;
}
#ifndef F_8
F_5 ( L_110 ,
V_64 , V_49 ) ;
#endif
V_49 = F_64 ( V_9 -> V_18 ,
F_41 ) ;
if ( V_49 != V_17 ) {
#ifndef F_8
F_5 ( L_111
L_74 , V_64 , V_49 ) ;
#endif
goto V_109;
}
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
V_49 = F_65 ( V_9 -> V_18 ,
V_70 , & V_9 -> V_147 [ V_70 ] , 0 , 0 ) ;
if ( V_49 == V_17 ) {
V_97 = V_97 +
V_9 -> V_147 [ V_70 ] ;
} else {
#ifndef F_8
F_5 ( L_112
L_113 ,
V_64 , V_70 , V_49 ) ;
#endif
goto V_109;
}
}
if ( V_97 == 0 ) {
#ifndef F_8
F_5 (
L_114 , V_64 ) ;
#endif
goto V_109;
} else if ( V_97 >= 1 ) {
if ( V_9 -> V_13 == NULL ) {
V_9 -> V_13 =
F_54 ( 8 ) ;
if ( V_9 -> V_13 == NULL ) {
F_16 ( V_9 ) ;
V_9 = F_55 ( - V_136 ) ;
return V_9 ;
}
}
#ifndef F_8
else {
F_5 ( L_115
L_116
L_117 , V_64 ) ;
}
#endif
}
if ( V_97 == 2 ) {
if ( V_9 -> V_14 == NULL ) {
V_9 -> V_14 =
F_54 ( 8 ) ;
if ( V_9 -> V_14 == NULL ) {
F_16 ( V_9 ) ;
V_9 = F_55 ( - V_136 ) ;
return V_9 ;
}
}
#ifndef F_8
else {
F_5 ( L_115
L_118
L_117 , V_64 ) ;
}
#endif
}
#ifndef F_8
else if ( V_97 > 2 ) {
F_5 ( L_119 ,
V_64 , V_97 ) ;
}
#endif
#ifndef F_8
F_5 ( L_120 ,
V_64 , V_97 ) ;
#endif
for ( V_70 = 0 ; V_70 <= 1 ; V_70 ++ ) {
V_49 = F_66 ( V_9 -> V_18 ,
V_70 , 0 , 0 , 0 ) ;
if ( V_49 != V_17 ) {
F_5 ( L_121
L_122 ,
V_64 , V_70 , V_49 ) ;
goto V_109;
}
V_101 . V_85 = V_70 ;
V_101 . V_58 = 0 ;
V_49 = F_67 ( V_9 -> V_18 ,
& V_101 , 0 , 0 ) ;
if ( V_49 == V_17 ) {
F_46 ( V_70 , V_9 ,
V_97 , V_98 ) ;
} else if ( V_49 == V_148 ) {
#ifndef F_8
F_5 (
L_123 ,
V_64 , V_70 ) ;
#endif
} else {
#ifndef F_8
F_5 (
L_124
L_74 ,
V_64 , V_70 , V_49 ) ;
#endif
goto V_109;
}
}
return V_9 ;
}
V_109:
#ifndef F_8
F_5 (
L_125 , V_64 ) ;
#endif
F_16 ( V_9 ) ;
V_9 = F_55 ( - V_23 ) ;
return V_9 ;
}
static int F_68 ( void )
{
struct V_6 * V_9 ;
int V_149 ;
V_5 ;
V_149 = F_69 ( V_118 , L_126 ) ;
if ( V_149 < 0 ) {
#ifndef F_8
F_5 ( V_150
L_127 ,
V_64 , V_118 , V_149 ) ;
#endif
return V_149 ;
}
if ( V_118 == 0 )
V_118 = V_149 ;
#ifndef F_8
F_5 (
L_128 ,
V_64 , V_118 ) ;
#endif
V_9 = F_56 () ;
if ( F_70 ( V_9 ) )
return F_71 ( V_9 ) ;
return 0 ;
}
static int T_12 F_72 ( void )
{
int V_149 = - V_136 ;
V_5 ;
V_151 = F_61 () ;
if ( F_68 () == 0 )
return 0 ;
#ifndef F_8
F_5 ( L_129 , V_149 ) ;
#endif
return V_149 ;
}
static void F_73 ( struct V_6 * V_9 )
{
V_5 ;
if ( V_9 ) {
int V_98 ;
if ( V_9 -> V_13 != NULL ) {
F_74 ( V_9 -> V_13 ) ;
V_98 = V_9 -> V_13 -> V_119
>> V_120 ;
F_75 ( V_98 , V_138 ) ;
}
if ( V_9 -> V_14 != NULL ) {
F_74 ( V_9 -> V_14 ) ;
V_98 = V_9 -> V_14 -> V_119
>> V_120 ;
F_75 ( V_98 , V_138 ) ;
}
if ( V_9 -> V_15 != NULL ) {
F_74 ( V_9 -> V_15 ) ;
V_98 = V_9 -> V_15 -> V_119
>> V_120 ;
F_75 ( V_98 , V_138 ) ;
}
F_7 ( V_9 ) ;
}
}
static void T_13 F_76 ( void )
{
V_5 ;
F_73 ( V_3 ) ;
F_77 ( V_118 , L_126 ) ;
}
