static int T_1 F_1 ( void )
{
union V_1 V_2 ;
unsigned long V_3 , V_4 , V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 [ 3 ] ;
unsigned int V_10 ;
int V_11 ;
int V_12 = 0 ;
V_3 = 0 ;
if ( V_13 -> V_14 == 1
&& V_13 -> V_15 >= 1 ) {
if ( V_13 -> V_16 )
V_3 =
V_13 -> V_16 ;
} else {
V_3 = 0x1d000800 ;
}
if ( ! V_3 )
return V_12 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_2 . V_17 = F_2 ( F_3 ( V_11 ) ) ;
V_4 = V_2 . V_18 . V_19 << 16 ;
V_5 = ( V_2 . V_18 . V_20 + 1 ) << 16 ;
if ( V_2 . V_18 . V_21 && V_3 >= V_4
&& V_3 < V_4 + V_5 )
break;
}
if ( V_11 >= 7 ) {
goto V_22;
}
V_23 . V_24 = V_11 ;
V_23 . V_25 = V_2 . V_18 . V_26 ;
V_23 . V_27 = V_3 - V_4 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_10 = 0 ;
V_9 [ V_10 ] . V_28 = V_29 ;
V_9 [ V_10 ] . V_30 = V_4 ;
V_9 [ V_10 ] . V_31 = V_4 + V_5 - 1 ;
V_10 ++ ;
if ( ! ( V_3 & 0xfffful ) ) {
V_2 . V_17 =
F_2 ( F_3 ( V_11 + 1 ) ) ;
V_4 = V_2 . V_18 . V_19 << 16 ;
V_5 = ( V_2 . V_18 . V_20 + 1 ) << 16 ;
if ( ! V_2 . V_18 . V_21 )
goto V_22;
V_9 [ V_10 ] . V_28 = V_29 ;
V_9 [ V_10 ] . V_30 = V_4 ;
V_9 [ V_10 ] . V_31 = V_4 + V_5 - 1 ;
V_10 ++ ;
V_23 . V_32 = 0 ;
V_9 [ V_10 ] . V_28 = V_33 ;
V_9 [ V_10 ] . V_30 = V_34 ;
V_9 [ V_10 ] . V_31 = V_34 ;
V_10 ++ ;
} else {
V_23 . V_32 = - 1 ;
}
V_7 = F_4 ( L_1 , - 1 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_7 -> V_36 . V_37 = & V_23 ;
V_12 = F_5 ( V_7 , V_9 , V_10 ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_8 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_8 V_39 [] = {
{
. V_28 = V_29 ,
. V_30 = F_9 ( V_40 ) ,
. V_31 = F_9 ( V_40 ) + 0xf
} , {
. V_28 = V_29 ,
. V_30 = F_10 ( 8 , 0 ) ,
. V_31 = F_10 ( 8 , 0 ) + 0x7
}
} ;
V_7 = F_4 ( L_2 , - 1 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_12 = F_5 ( V_7 , V_39 ,
F_11 ( V_39 ) ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_12 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_8 V_41 [] = {
{
. V_28 = V_29 ,
} , {
. V_28 = V_33 ,
}
} ;
if ( ! F_13 ( V_42 ) )
return 0 ;
if ( F_14 () || F_15 () )
return 0 ;
V_7 = F_4 ( L_3 , 0 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_41 [ 0 ] . V_30 = 0x00016F0000000000ULL ;
V_41 [ 0 ] . V_31 = V_41 [ 0 ] . V_30 + 0x100 ;
V_41 [ 1 ] . V_30 = V_43 ;
V_41 [ 1 ] . V_31 = V_43 ;
V_12 = F_5 ( V_7 , V_41 ,
F_11 ( V_41 ) ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static int T_1 F_16 ( void )
{
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_8 V_41 [] = {
{
. V_28 = V_29 ,
} , {
. V_28 = V_33 ,
}
} ;
if ( ! F_13 ( V_42 ) )
return 0 ;
if ( F_14 () || F_15 () )
return 0 ;
V_7 = F_4 ( L_4 , 0 ) ;
if ( ! V_7 ) {
V_12 = - V_35 ;
goto V_22;
}
V_41 [ 0 ] . V_30 = 0x00016F0000000400ULL ;
V_41 [ 0 ] . V_31 = V_41 [ 0 ] . V_30 + 0x100 ;
V_41 [ 1 ] . V_30 = V_43 ;
V_41 [ 1 ] . V_31 = V_43 ;
V_12 = F_5 ( V_7 , V_41 ,
F_11 ( V_41 ) ) ;
if ( V_12 )
goto V_38;
V_12 = F_6 ( V_7 ) ;
if ( V_12 )
goto V_38;
return V_12 ;
V_38:
F_7 ( V_7 ) ;
V_22:
return V_12 ;
}
static bool T_1 F_17 ( void )
{
return ! F_13 ( V_44 ) &&
! F_13 ( V_45 ) &&
! F_13 ( V_46 ) ;
}
static void T_1 F_18 ( int V_47 , int V_48 )
{
const T_2 * V_49 ;
const T_2 * V_50 ;
const T_2 * V_51 ;
T_3 V_52 ;
int V_53 ;
int V_54 ;
const char * V_55 ;
int V_56 ;
char V_57 [ 20 ] ;
V_49 = F_19 ( V_58 , V_47 , L_5 , NULL ) ;
if ( ! V_49 )
return;
V_52 = F_20 ( V_49 ) ;
V_53 = F_21 ( V_58 , V_52 ) ;
V_50 = F_19 ( V_58 , V_47 , L_6 , NULL ) ;
if ( V_50 ) {
T_3 V_59 = F_20 ( V_50 ) ;
V_54 = F_21 ( V_58 , V_59 ) ;
} else {
V_54 = - 1 ;
}
if ( V_48 < 0 || V_53 < 0 ) {
F_22 ( V_58 , V_47 , L_5 ) ;
F_22 ( V_58 , V_47 , L_6 ) ;
if ( V_53 >= 0 )
F_23 ( V_58 , V_53 ) ;
if ( V_54 >= 0 )
F_23 ( V_58 , V_54 ) ;
return;
}
if ( V_48 >= 256 && V_54 > 0 ) {
const struct V_60 * V_61 ;
struct V_60 * V_62 ;
T_3 V_63 ;
V_61 = F_24 ( V_58 , V_47 , L_5 , NULL ) ;
V_63 = V_61 -> V_64 ;
F_23 ( V_58 , V_53 ) ;
F_22 ( V_58 , V_47 , L_5 ) ;
V_62 = F_25 ( V_58 , V_47 , L_6 , NULL ) ;
V_62 -> V_64 = V_63 ;
V_53 = V_54 ;
}
V_48 &= 0xff ;
if ( F_17 () ) {
F_22 ( V_58 , V_53 , L_7 ) ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
strcpy ( V_57 , L_8 ) ;
V_55 = F_19 ( V_58 , V_53 , L_9 ,
& V_56 ) ;
if ( V_55 && V_56 >= strlen ( V_57 ) )
F_26 ( V_58 , V_53 ,
L_9 , V_57 , V_56 ) ;
}
V_51 = F_19 ( V_58 , V_53 , L_10 , NULL ) ;
if ( V_48 == F_20 ( V_51 ) )
return;
F_27 ( V_58 , V_53 , L_10 , V_48 ) ;
snprintf ( V_57 , sizeof( V_57 ) , L_11 , V_48 ) ;
V_55 = F_28 ( V_58 , V_53 , & V_56 ) ;
if ( V_55 && V_56 == strlen ( V_57 ) )
F_29 ( V_58 , V_53 , V_57 ) ;
else
F_30 ( L_12 , V_55 ) ;
}
static void T_1 F_31 ( int V_65 , V_17 * V_66 )
{
T_4 V_67 [ 6 ] ;
V_17 V_68 = * V_66 ;
int V_69 ;
V_67 [ 0 ] = ( V_68 >> 40 ) & 0xff ;
V_67 [ 1 ] = ( V_68 >> 32 ) & 0xff ;
V_67 [ 2 ] = ( V_68 >> 24 ) & 0xff ;
V_67 [ 3 ] = ( V_68 >> 16 ) & 0xff ;
V_67 [ 4 ] = ( V_68 >> 8 ) & 0xff ;
V_67 [ 5 ] = V_68 & 0xff ;
V_69 = F_26 ( V_58 , V_65 , L_13 ,
V_67 , sizeof( V_67 ) ) ;
if ( V_69 ) {
F_30 ( L_14 , V_69 ) ;
return;
}
* V_66 = V_68 + 1 ;
}
static void T_1 F_32 ( int V_70 )
{
const T_2 * V_49 ;
V_49 = F_19 ( V_58 , V_70 , L_5 , NULL ) ;
if ( V_49 ) {
T_3 V_71 = F_20 ( V_49 ) ;
int V_55 = F_21 ( V_58 , V_71 ) ;
if ( V_55 >= 0 )
F_23 ( V_58 , V_55 ) ;
}
F_23 ( V_58 , V_70 ) ;
}
static void T_1 F_33 ( int V_72 , int V_11 , int V_55 , int V_73 , V_17 * V_66 )
{
char V_74 [ 20 ] ;
int V_47 ;
int V_48 ;
int V_75 ;
snprintf ( V_74 , sizeof( V_74 ) , L_15 , V_55 ) ;
V_47 = F_34 ( V_58 , V_72 , V_74 ) ;
if ( V_47 < 0 )
return;
if ( V_55 > V_73 ) {
F_35 ( L_16 , V_11 , V_55 ) ;
F_32 ( V_47 ) ;
return;
}
if ( F_13 ( V_76 ) )
V_75 = ( 0x100 * V_11 ) + ( 0x10 * V_55 ) + 0x800 ;
else
V_75 = 16 * V_11 + V_55 ;
V_48 = F_36 ( V_75 ) ;
F_18 ( V_47 , V_48 ) ;
F_31 ( V_47 , V_66 ) ;
}
static void T_1 F_37 ( int V_77 , int V_78 , V_17 * V_66 )
{
char V_74 [ 20 ] ;
int V_72 ;
int V_55 ;
int V_79 ;
V_79 = F_38 ( V_78 ) ;
snprintf ( V_74 , sizeof( V_74 ) , L_17 , V_78 ) ;
V_72 = F_34 ( V_58 , V_77 , V_74 ) ;
if ( V_72 < 0 )
return;
for ( V_55 = 0 ; V_55 < 16 ; V_55 ++ )
F_33 ( V_72 , V_78 , V_55 , V_79 - 1 , V_66 ) ;
}
int T_1 F_39 ( void )
{
int V_11 , V_80 , V_81 ;
const char * V_82 ;
const char * V_83 ;
char V_74 [ 20 ] ;
int V_84 ;
V_17 V_85 ;
if ( F_40 ( V_58 ) )
F_41 ( L_18 ) ;
V_84 = F_42 ( V_58 , L_19 ) ;
if ( V_84 < 0 ) {
F_30 ( L_20 ) ;
return - V_86 ;
}
V_85 =
( ( V_13 -> V_85 [ 0 ] & 0xffull ) ) << 40 |
( ( V_13 -> V_85 [ 1 ] & 0xffull ) ) << 32 |
( ( V_13 -> V_85 [ 2 ] & 0xffull ) ) << 24 |
( ( V_13 -> V_85 [ 3 ] & 0xffull ) ) << 16 |
( ( V_13 -> V_85 [ 4 ] & 0xffull ) ) << 8 |
( V_13 -> V_85 [ 5 ] & 0xffull ) ;
if ( F_13 ( V_44 ) || F_13 ( V_42 ) )
V_80 = 2 ;
else if ( F_13 ( V_46 ) || F_13 ( V_76 ) )
V_80 = 1 ;
else
V_80 = 0 ;
if ( V_13 -> V_87 == V_88 )
V_80 = 0 ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
int V_89 ;
snprintf ( V_74 , sizeof( V_74 ) ,
L_21 , V_11 ) ;
V_83 = F_19 ( V_58 , V_84 ,
V_74 , NULL ) ;
if ( V_83 ) {
V_89 = F_42 ( V_58 , V_83 ) ;
if ( V_89 < 0 )
continue;
if ( V_11 >= V_80 ) {
F_35 ( L_22 , V_11 ) ;
F_32 ( V_89 ) ;
F_22 ( V_58 , V_84 ,
V_74 ) ;
} else {
int V_48 = F_36 ( V_90 + V_11 ) ;
F_18 ( V_89 , V_48 ) ;
F_31 ( V_89 , & V_85 ) ;
}
}
}
V_82 = F_19 ( V_58 , V_84 , L_23 , NULL ) ;
if ( V_82 ) {
int V_77 = F_42 ( V_58 , V_82 ) ;
if ( V_77 >= 0 )
for ( V_11 = 0 ; V_11 <= 4 ; V_11 ++ )
F_37 ( V_77 , V_11 , & V_85 ) ;
}
if ( F_13 ( V_44 ) ||
F_13 ( V_42 ) ||
F_13 ( V_76 ) ||
F_13 ( V_46 ) )
V_80 = 2 ;
else
V_80 = 1 ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
int V_91 ;
snprintf ( V_74 , sizeof( V_74 ) ,
L_24 , V_11 ) ;
V_83 = F_19 ( V_58 , V_84 ,
V_74 , NULL ) ;
if ( V_83 ) {
V_91 = F_42 ( V_58 , V_83 ) ;
if ( V_91 < 0 )
continue;
if ( V_11 >= V_80 ) {
F_35 ( L_25 , V_11 ) ;
F_23 ( V_58 , V_91 ) ;
F_22 ( V_58 , V_84 ,
V_74 ) ;
}
}
}
if ( F_13 ( V_76 ) )
V_80 = 4 ;
else if ( F_13 ( V_44 ) ||
F_13 ( V_42 ) ||
F_13 ( V_46 ) )
V_80 = 2 ;
else
V_80 = 1 ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
int V_91 ;
snprintf ( V_74 , sizeof( V_74 ) ,
L_26 , V_11 ) ;
V_83 = F_19 ( V_58 , V_84 ,
V_74 , NULL ) ;
if ( V_83 ) {
V_91 = F_42 ( V_58 , V_83 ) ;
if ( V_91 < 0 )
continue;
if ( V_11 >= V_80 ) {
F_35 ( L_27 , V_11 ) ;
F_23 ( V_58 , V_91 ) ;
F_22 ( V_58 , V_84 ,
V_74 ) ;
}
}
}
V_81 = 3 ;
if ( F_13 ( V_44 ) )
V_81 |= 4 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
int V_92 ;
snprintf ( V_74 , sizeof( V_74 ) ,
L_28 , V_11 ) ;
V_83 = F_19 ( V_58 , V_84 ,
V_74 , NULL ) ;
if ( V_83 ) {
V_92 = F_42 ( V_58 , V_83 ) ;
if ( V_81 & ( 1 << V_11 ) )
continue;
F_35 ( L_29 , V_11 ) ;
F_23 ( V_58 , V_92 ) ;
F_22 ( V_58 , V_84 ,
V_74 ) ;
}
}
V_83 = F_19 ( V_58 , V_84 ,
L_30 , NULL ) ;
if ( V_83 ) {
union V_1 V_2 ;
unsigned long V_3 , V_4 , V_5 ;
unsigned long V_93 = 0 ;
unsigned long V_94 = 0 ;
int V_95 , V_96 ;
bool V_97 = false ;
bool V_98 = false ;
T_2 V_99 [ 6 ] ;
T_2 * V_100 ;
int V_101 ;
int V_102 = F_42 ( V_58 , V_83 ) ;
V_3 = 0 ;
if ( V_13 -> V_14 == 1
&& V_13 -> V_15 >= 1 ) {
if ( V_13 -> V_16 )
V_3 = V_13 -> V_16 ;
} else {
V_3 = 0x1d000800 ;
}
if ( ! V_3 )
goto V_103;
for ( V_95 = 0 ; V_95 < 8 ; V_95 ++ ) {
V_2 . V_17 = F_2 ( F_3 ( V_95 ) ) ;
V_4 = V_2 . V_18 . V_19 << 16 ;
V_5 = ( V_2 . V_18 . V_20 + 1 ) << 16 ;
if ( V_2 . V_18 . V_21 && V_3 >= V_4
&& V_3 < V_4 + V_5 ) {
V_97 = V_2 . V_18 . V_26 ;
break;
}
}
if ( V_95 >= 7 ) {
goto V_103;
}
if ( ! ( V_3 & 0xfffful ) ) {
V_2 . V_17 =
F_2 ( F_3 ( V_95 + 1 ) ) ;
V_93 = V_2 . V_18 . V_19 << 16 ;
V_94 = ( V_2 . V_18 . V_20 + 1 ) << 16 ;
if ( ! V_2 . V_18 . V_21 )
goto V_103;
V_98 = true ;
} else {
F_22 ( V_58 , V_102 , L_31 ) ;
F_22 ( V_58 , V_102 , L_32 ) ;
if ( ! V_97 ) {
T_2 V_26 = F_43 ( 8 ) ;
F_26 ( V_58 , V_102 ,
L_33 , & V_26 , sizeof( V_26 ) ) ;
}
}
V_99 [ 0 ] = F_43 ( V_95 ) ;
V_99 [ 1 ] = F_43 ( 0 ) ;
V_99 [ 2 ] = F_43 ( 0x10000 ) ;
V_99 [ 3 ] = F_43 ( V_95 + 1 ) ;
V_99 [ 4 ] = F_43 ( 0 ) ;
V_99 [ 5 ] = F_43 ( 0x10000 ) ;
F_26 ( V_58 , V_102 ,
L_10 , V_99 , sizeof( V_99 ) ) ;
V_96 = F_44 ( V_58 , V_102 ) ;
if ( V_96 < 0 )
goto V_103;
V_100 = F_45 ( V_58 , V_96 , L_34 , & V_101 ) ;
if ( ! V_100 || V_101 < ( 5 * 8 * sizeof( T_2 ) ) )
goto V_103;
V_100 [ ( V_95 * 5 ) + 2 ] = F_43 ( V_4 >> 32 ) ;
V_100 [ ( V_95 * 5 ) + 3 ] = F_43 ( V_4 & 0xffffffff ) ;
V_100 [ ( V_95 * 5 ) + 4 ] = F_43 ( V_5 ) ;
if ( V_98 ) {
V_95 ++ ;
V_100 [ ( V_95 * 5 ) + 2 ] = F_43 ( V_93 >> 32 ) ;
V_100 [ ( V_95 * 5 ) + 3 ] = F_43 ( V_93 & 0xffffffff ) ;
V_100 [ ( V_95 * 5 ) + 4 ] = F_43 ( V_94 ) ;
}
goto V_104;
V_103:
F_23 ( V_58 , V_102 ) ;
V_104:
;
}
V_83 = F_19 ( V_58 , V_84 ,
L_35 , NULL ) ;
if ( V_83 ) {
union V_1 V_2 ;
unsigned long V_3 , V_4 , V_5 ;
int V_95 , V_96 ;
T_2 V_99 [ 6 ] ;
T_2 * V_100 ;
int V_101 ;
int V_105 = F_42 ( V_58 , V_83 ) ;
V_3 = V_13 -> V_106 ;
if ( V_3 == 0 )
goto V_107;
for ( V_95 = 0 ; V_95 < 8 ; V_95 ++ ) {
V_2 . V_17 = F_2 ( F_3 ( V_95 ) ) ;
V_4 = V_2 . V_18 . V_19 << 16 ;
V_5 = ( V_2 . V_18 . V_20 + 1 ) << 16 ;
if ( V_2 . V_18 . V_21 && V_3 >= V_4
&& V_3 < V_4 + V_5 )
break;
}
if ( V_95 > 7 )
goto V_107;
V_99 [ 0 ] = F_43 ( V_95 ) ;
V_99 [ 1 ] = F_43 ( 0x20 ) ;
V_99 [ 2 ] = F_43 ( 0x20 ) ;
V_99 [ 3 ] = F_43 ( V_95 ) ;
V_99 [ 4 ] = F_43 ( 0 ) ;
V_99 [ 5 ] = F_43 ( 0x20 ) ;
F_26 ( V_58 , V_105 ,
L_10 , V_99 , sizeof( V_99 ) ) ;
V_96 = F_44 ( V_58 , V_105 ) ;
if ( V_96 < 0 )
goto V_107;
V_100 = F_45 ( V_58 , V_96 , L_34 , & V_101 ) ;
if ( ! V_100 || V_101 < ( 5 * 8 * sizeof( T_2 ) ) )
goto V_107;
V_100 [ ( V_95 * 5 ) + 2 ] = F_43 ( V_4 >> 32 ) ;
V_100 [ ( V_95 * 5 ) + 3 ] = F_43 ( V_4 & 0xffffffff ) ;
V_100 [ ( V_95 * 5 ) + 4 ] = F_43 ( V_5 ) ;
goto V_108;
V_107:
F_23 ( V_58 , V_105 ) ;
V_108:
;
}
V_83 = F_19 ( V_58 , V_84 ,
L_36 , NULL ) ;
if ( V_83 ) {
int V_109 = F_42 ( V_58 , V_83 ) ;
if ( V_109 >= 0 && ( ! F_13 ( V_45 ) ||
V_13 -> V_87 == V_110 ) ) {
F_35 ( L_37 ) ;
F_23 ( V_58 , V_109 ) ;
F_22 ( V_58 , V_84 , L_36 ) ;
} else if ( V_13 -> V_87 == V_88 ||
V_13 -> V_87 == V_111 ) {
F_22 ( V_58 , V_109 , L_38 ) ;
}
}
return 0 ;
}
static int T_1 F_46 ( void )
{
return F_47 ( NULL , V_112 , NULL ) ;
}
