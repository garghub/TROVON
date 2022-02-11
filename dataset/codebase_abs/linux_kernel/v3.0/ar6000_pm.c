static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
char V_4 [ 128 ] ;
union V_5 V_6 ;
snprintf ( V_4 , sizeof( V_4 ) , L_1 , V_3 ? L_2 : L_3 ) ;
F_2 ( & V_6 , sizeof( V_6 ) ) ;
V_6 . V_7 . V_8 = strlen ( V_4 ) ;
F_3 ( V_2 -> V_9 , V_10 , & V_6 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 != V_12 ) {
T_1 V_13 = ( V_2 -> V_14 . V_13 == 0 ) ? 1 : V_2 -> V_14 . V_13 ;
T_1 V_15 = ( V_2 -> V_14 . V_15 == 0 ) ? 60 : V_2 -> V_14 . V_15 ;
T_2 V_16 = { true , false } ;
V_2 -> V_11 = V_12 ;
if ( F_5 ( V_2 -> V_17 , & V_16 ) != 0 ) {
F_6 ( V_18 , ( L_4 ) ) ;
}
#if V_19
F_7 ( V_2 -> V_17 , V_13 ,
V_2 -> V_14 . V_20 ,
V_15 ,
V_2 -> V_14 . V_21 ,
V_2 -> V_14 . V_22 ,
V_2 -> V_14 . V_23 ,
V_2 -> V_14 . V_24 ,
V_2 -> V_14 . V_25 ,
V_2 -> V_14 . V_26 ,
V_2 -> V_14 . V_27 ) ;
#else
( void ) V_13 ;
( void ) V_15 ;
#endif
#if V_28
if ( F_8 ( V_2 -> V_17 , V_2 -> V_29 , V_2 -> V_30 ) == 0 ) {
}
#endif
F_1 ( V_2 , false ) ;
F_6 ( V_31 , ( L_5 ) ) ;
} else {
F_6 ( V_31 , ( L_6 ) ) ;
}
V_2 -> V_32 = V_33 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#define F_10 1
if ( V_2 -> V_34 != V_35 ) {
struct V_36 * * V_37 = NULL ;
struct V_36 * V_38 = NULL ;
struct V_39 * V_40 ;
T_3 V_41 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_42 ;
T_4 V_43 = { . V_44 = { 0 } } ;
T_5 V_45 ;
T_2 V_16 = { false , true } ;
T_6 V_46 = { . V_47 = true ,
. V_48 = 500 } ;
if ( V_2 -> V_11 != V_12 ) {
F_6 ( V_18 , ( L_7 ) ) ;
return;
}
F_11 ( V_2 ) ;
#if V_28
if ( F_8 ( V_2 -> V_17 , V_49 , 0 ) == 0 ) {
}
#endif
#if V_19
V_42 = F_7 ( V_2 -> V_17 , 0xFFFF , 0 , 0xFFFF , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
#endif
V_45 . V_50 = F_10 ;
V_45 . V_51 = 0 ;
F_12 ( V_2 -> V_17 , & V_45 ) ;
if ( V_2 -> V_9 -> V_52 [ 1 ] ) {
V_43 . V_50 = F_10 ;
V_43 . V_53 = 6 ;
V_43 . V_54 = 0 ;
V_42 = F_13 ( V_2 -> V_17 , & V_43 , V_2 -> V_9 -> V_52 , V_41 , V_43 . V_53 ) ;
if ( V_42 ) {
F_6 ( V_18 , ( L_8 ) ) ;
}
}
if ( ( V_40 = F_14 ( V_2 -> V_9 ) ) != NULL ) {
for ( V_37 = & V_40 -> V_55 ; ( V_38 = * V_37 ) != NULL ; V_37 = & V_38 -> V_56 ) {
if ( ! strcmp ( V_2 -> V_9 -> V_57 , V_38 -> V_58 ) ) {
break;
}
}
}
if ( V_38 && V_38 -> V_59 ) {
T_7 V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_61 [ 0 ] = V_38 -> V_59 ;
V_42 = F_15 ( V_2 -> V_17 , & V_60 ) ;
if ( V_42 ) {
F_6 ( V_18 , ( L_9 ) ) ;
}
}
#ifndef F_16
F_17 ( V_2 -> V_17 , V_62 ) ;
#endif
V_42 = F_18 ( V_2 -> V_17 , & V_46 ) ;
if ( V_42 ) {
F_6 ( V_18 , ( L_10 ) ) ;
}
F_1 ( V_2 , true ) ;
V_42 = F_5 ( V_2 -> V_17 , & V_16 ) ;
if ( V_42 ) {
F_6 ( V_18 , ( L_11 ) ) ;
}
V_2 -> V_11 = V_63 ;
if ( V_2 -> V_64 [ V_2 -> V_65 ] ) {
T_8 V_66 = F_19 ( V_67 ,
V_2 -> V_64 [ V_2 -> V_65 ] == 0 , V_68 * V_69 ) ;
if ( ! V_66 || F_20 ( V_70 ) ) {
F_6 ( V_18 , ( L_12 , V_2 -> V_64 [ V_2 -> V_65 ] ) ) ;
}
}
V_42 = F_21 ( V_2 -> V_71 ) ;
V_2 -> V_11 = V_72 ;
V_2 -> V_32 = V_73 ;
} else {
F_6 ( V_18 , ( L_13 ) ) ;
}
}
int F_22 ( void * V_74 )
{
int V_42 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
T_9 V_75 = V_2 -> V_76 ;
V_77:
switch ( V_75 ) {
case V_78 :
if ( V_2 -> V_79 && V_2 -> V_80 == V_81 && V_2 -> V_82 ) {
F_9 ( V_2 ) ;
F_6 ( V_31 , ( L_14 , V_83 , V_2 -> V_32 ) ) ;
} else {
V_75 = V_2 -> V_84 ;
goto V_77;
}
break;
case V_85 :
case V_86 :
case V_87 :
default:
V_42 = F_23 ( V_2 , V_88 , true ) ;
if ( V_2 -> V_32 == V_33 ||
V_2 -> V_32 == V_73 ) {
F_6 ( V_31 , ( L_15 , V_2 -> V_32 ) ) ;
}
F_6 ( V_31 , ( L_16 , V_83 , V_75 , V_2 -> V_32 , V_42 ) ) ;
V_42 = ( V_2 -> V_32 == V_89 ) ? 0 : V_90 ;
break;
}
V_2 -> V_91 = 0 ;
return V_42 ;
}
int F_24 ( void * V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
T_1 V_92 = V_2 -> V_32 ;
F_6 ( V_31 , ( L_17 , V_83 , V_92 , V_2 -> V_11 ) ) ;
switch ( V_92 ) {
case V_73 :
F_4 ( V_2 ) ;
break;
case V_89 :
case V_93 :
F_23 ( V_2 , V_81 , true ) ;
F_6 ( V_31 , ( L_18 , V_83 , V_92 , V_2 -> V_32 ) ) ;
break;
case V_33 :
break;
default:
F_6 ( V_18 , ( L_19 ) ) ;
break;
}
return 0 ;
}
void F_25 ( struct V_1 * V_2 , struct V_94 * V_95 , bool V_96 )
{
if ( V_2 -> V_11 != V_12 ) {
if ( V_2 -> V_11 == V_63 ) {
F_6 ( V_31 , ( L_20 , V_83 ) ) ;
return;
}
F_6 ( V_31 , ( L_21 , V_83 , V_2 -> V_32 ) ) ;
F_4 ( V_2 ) ;
}
}
int F_26 ( void * V_74 , T_8 V_97 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
int V_42 = 0 ;
F_6 ( V_31 , ( L_22 , V_83 , V_97 ) ) ;
switch ( V_97 ) {
case V_98 :
F_27 ( V_2 -> V_9 ) ;
V_42 = 0 ;
break;
case V_99 :
case V_100 :
V_42 = 0 ;
break;
}
return V_42 ;
}
int
F_28 ( struct V_1 * V_2 , T_10 V_101 )
{
int V_42 = 0 ;
T_11 V_97 ;
F_6 ( V_31 , ( L_23 , V_83 , V_101 , V_2 -> V_32 ) ) ;
#ifdef F_29
F_6 ( V_31 , ( L_24 , V_2 -> V_102 , V_2 -> V_103 ) ) ;
#endif
do {
if ( V_101 == V_81 ) {
if ( V_2 -> V_32 != V_89 ) {
break;
}
V_2 -> V_32 = V_33 ;
V_97 = V_98 ;
V_42 = F_30 ( V_2 -> V_71 ,
V_104 ,
& V_97 ,
sizeof( T_11 ) ) ;
if ( V_42 == V_105 ) {
} else if ( V_42 == 0 ) {
F_27 ( V_2 -> V_9 ) ;
V_42 = 0 ;
}
} else if ( V_101 == V_88 ) {
if ( V_2 -> V_32 == V_89 ) {
break;
}
F_31 ( V_2 -> V_9 , true , false ) ;
V_97 = V_100 ;
V_42 = F_30 ( V_2 -> V_71 ,
V_104 ,
& V_97 ,
sizeof( T_11 ) ) ;
V_2 -> V_32 = V_89 ;
}
} while ( 0 );
return V_42 ;
}
int
F_32 ( struct V_1 * V_2 , T_10 V_101 )
{
int V_42 = 0 ;
F_6 ( V_31 , ( L_25 , V_83 , V_101 , V_2 -> V_32 ) ) ;
#ifdef F_29
F_6 ( V_31 , ( L_24 , V_2 -> V_102 , V_2 -> V_103 ) ) ;
#endif
do {
T_2 V_16 ;
if ( V_101 == V_81 ) {
T_1 V_13 ;
if ( V_2 -> V_32 != V_93 ) {
if ( V_2 -> V_32 != V_33 ) {
F_6 ( V_18 , ( L_26 , V_2 -> V_32 ) ) ;
}
break;
}
V_13 = ( V_2 -> V_14 . V_13 == 0 ) ? 1 : V_2 -> V_14 . V_13 ;
V_16 . V_106 = true ;
V_16 . V_3 = false ;
if ( ( V_42 = F_5 ( V_2 -> V_17 , & V_16 ) ) != 0 ) {
break;
}
V_2 -> V_32 = V_33 ;
if ( ( V_42 = F_7 ( V_2 -> V_17 , V_13 ,
V_2 -> V_14 . V_20 ,
V_2 -> V_14 . V_15 ,
V_2 -> V_14 . V_21 ,
V_2 -> V_14 . V_22 ,
V_2 -> V_14 . V_23 ,
V_2 -> V_14 . V_24 ,
V_2 -> V_14 . V_25 ,
V_2 -> V_14 . V_26 ,
V_2 -> V_14 . V_27 ) ) != 0 )
{
break;
}
if ( V_2 -> V_34 != V_35 )
{
if ( V_2 -> V_107 ) {
if ( F_33 ( V_2 ) != 0 ) {
break;
}
}
}
} else if ( V_101 == V_88 ) {
T_6 V_46 = { . V_47 = false } ;
if ( V_2 -> V_32 != V_33 ) {
if ( V_2 -> V_32 != V_93 ) {
F_6 ( V_18 , ( L_27 , V_2 -> V_32 ) ) ;
}
break;
}
if ( V_2 -> V_34 != V_35 )
{
F_34 ( & V_2 -> V_108 , 0 ) ;
if ( V_2 -> V_82 == true || V_2 -> V_109 == true ) {
F_35 ( & V_2 -> V_108 , 0 ) ;
F_36 ( V_2 -> V_17 ) ;
} else {
F_35 ( & V_2 -> V_108 , 0 ) ;
}
}
V_2 -> V_91 = 0 ;
if ( ( V_42 = F_7 ( V_2 -> V_17 , 0xFFFF , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ) != 0 ) {
break;
}
if ( ( V_42 = F_18 ( V_2 -> V_17 , & V_46 ) ) != 0 )
{
break;
}
F_11 ( V_2 ) ;
#ifndef F_16
F_17 ( V_2 -> V_17 , V_62 ) ;
#endif
V_16 . V_106 = false ;
V_16 . V_3 = true ;
if ( ( V_42 = F_5 ( V_2 -> V_17 , & V_16 ) ) != 0 ) {
break;
}
if ( V_2 -> V_64 [ V_2 -> V_65 ] ) {
T_8 V_66 = F_19 ( V_67 ,
V_2 -> V_64 [ V_2 -> V_65 ] == 0 , V_68 * V_69 ) ;
if ( ! V_66 || F_20 ( V_70 ) ) {
V_42 = V_110 ;
break;
}
}
V_42 = F_21 ( V_2 -> V_71 ) ;
V_2 -> V_32 = V_93 ;
}
} while ( 0 );
if ( V_42 ) {
F_6 ( V_18 , ( L_28 , V_101 ) ) ;
}
return V_42 ;
}
int
F_23 ( struct V_1 * V_2 , T_10 V_101 , bool V_111 )
{
int V_42 = 0 ;
T_1 V_92 , V_112 ;
T_10 V_113 = V_2 -> V_80 ;
bool V_114 = V_2 -> V_102 ;
#ifdef F_29
bool V_115 = V_2 -> V_103 ;
#endif
if ( ( V_101 != V_88 && V_101 != V_81 ) ) {
return V_110 ;
}
if ( V_2 -> V_116 ) {
return V_90 ;
}
if ( F_37 ( & V_2 -> V_117 ) ) {
return V_110 ;
}
if ( V_2 -> V_116 ) {
F_38 ( & V_2 -> V_117 ) ;
return V_90 ;
}
V_2 -> V_80 = V_114 ? V_88 : V_101 ;
V_112 = V_2 -> V_32 ;
if ( V_101 == V_81 ) {
V_92 = V_2 -> V_32 ;
F_6 ( V_31 , ( L_29 ) ) ;
if ( ! V_114 ) {
if ( V_92 == V_93 ) {
V_42 = F_32 ( V_2 , V_81 ) ;
} else if ( V_92 == V_89 ) {
V_42 = F_28 ( V_2 , V_81 ) ;
}
}
#ifdef F_29
else if ( V_111 && V_114 ) {
bool V_118 = ( ( ! V_2 -> V_119 ) || V_115 ) ;
if ( ( V_92 == V_89 ) && ( ! V_118 ) ) {
F_28 ( V_2 , V_81 ) ;
V_42 = F_32 ( V_2 , V_88 ) ;
}
}
#endif
} else if ( V_101 == V_88 ) {
F_6 ( V_31 , ( L_30 ) ) ;
V_92 = V_93 ;
#ifdef F_29
if ( V_111 ) {
bool V_120 = ( V_2 -> V_76 == V_85 ||
( V_2 -> V_76 == V_78 &&
V_2 -> V_84 == V_85 ) ) ;
bool V_121 = ( ( V_2 -> V_76 ==
V_86 ||
( V_2 -> V_76 == V_78 &&
V_2 -> V_84 == V_86 ) ) &&
( ! V_2 -> V_119 || V_115 ) ) ;
if ( ( V_120 ) ||
( V_121 ) ||
( V_2 -> V_80 == V_89 ) )
{
V_92 = V_89 ;
}
} else {
if ( ( V_114 ) &&
( V_2 -> V_122 == V_123 ) &&
( ! V_2 -> V_119 || V_115 ) )
{
V_92 = V_89 ;
}
}
#endif
if ( V_92 == V_93 ) {
if ( V_2 -> V_32 == V_89 ) {
F_6 ( V_31 , ( L_31 ) ) ;
F_28 ( V_2 , V_81 ) ;
}
V_42 = F_32 ( V_2 , V_88 ) ;
} else if ( V_92 == V_89 ) {
V_42 = F_28 ( V_2 , V_88 ) ;
}
}
if ( V_42 ) {
F_6 ( V_18 , ( L_32 , V_2 -> V_80 ) ) ;
V_2 -> V_80 = V_113 ;
} else if ( V_42 == 0 ) {
T_12 V_124 , * V_125 = NULL ;
if ( ( V_2 -> V_32 == V_33 ) && ( V_112 != V_33 ) ) {
V_124 . V_126 = V_127 ;
V_125 = & V_124 ;
} else if ( ( V_2 -> V_32 != V_33 ) && ( V_112 == V_33 ) ) {
V_124 . V_126 = V_128 ;
V_125 = & V_124 ;
}
if ( V_125 ) {
F_6 ( V_31 , ( L_33 , V_124 . V_126 ) ) ;
}
}
F_38 ( & V_2 -> V_117 ) ;
return V_42 ;
}
int
F_39 ( struct V_1 * V_2 , T_8 V_129 )
{
#ifdef F_29
bool V_130 = ( V_129 == 0 ) ;
int V_42 ;
if ( V_2 -> V_103 == V_130 ) {
return 0 ;
}
V_2 -> V_103 = V_130 ;
V_42 = F_23 ( V_2 , V_2 -> V_102 ? V_88 : V_81 , false ) ;
return V_42 ;
#else
return 0 ;
#endif
}
int
F_40 ( struct V_1 * V_2 , T_10 V_101 )
{
int V_42 ;
bool V_130 = ( V_101 == V_88 ) ;
if ( V_2 -> V_102 == V_130 ) {
return 0 ;
}
V_2 -> V_102 = V_130 ;
V_42 = F_23 ( V_2 , V_101 , false ) ;
return V_42 ;
}
