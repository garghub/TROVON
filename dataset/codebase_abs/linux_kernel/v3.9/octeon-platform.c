static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 = 0 ;
struct V_4 V_5 [] = {
{
. V_6 = V_7 ,
. V_8 = F_2 ( V_9 ) ,
. V_10 = F_2 ( V_9 ) + 0xf
} , {
. V_6 = V_7 ,
. V_8 = F_3 ( 8 , 0 ) ,
. V_10 = F_3 ( 8 , 0 ) + 0x7
}
} ;
V_2 = F_4 ( L_1 , - 1 ) ;
if ( ! V_2 ) {
V_3 = - V_11 ;
goto V_12;
}
V_3 = F_5 ( V_2 , V_5 ,
F_6 ( V_5 ) ) ;
if ( V_3 )
goto V_13;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_13;
return V_3 ;
V_13:
F_8 ( V_2 ) ;
V_12:
return V_3 ;
}
static int T_1 F_9 ( void )
{
struct V_1 * V_2 ;
int V_3 = 0 ;
struct V_4 V_14 [] = {
{
. V_6 = V_7 ,
} , {
. V_6 = V_15 ,
}
} ;
if ( ! F_10 ( V_16 ) )
return 0 ;
if ( F_11 () || F_12 () )
return 0 ;
V_2 = F_4 ( L_2 , 0 ) ;
if ( ! V_2 ) {
V_3 = - V_11 ;
goto V_12;
}
V_14 [ 0 ] . V_8 = 0x00016F0000000000ULL ;
V_14 [ 0 ] . V_10 = V_14 [ 0 ] . V_8 + 0x100 ;
V_14 [ 1 ] . V_8 = V_17 ;
V_14 [ 1 ] . V_10 = V_17 ;
V_3 = F_5 ( V_2 , V_14 ,
F_6 ( V_14 ) ) ;
if ( V_3 )
goto V_13;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_13;
return V_3 ;
V_13:
F_8 ( V_2 ) ;
V_12:
return V_3 ;
}
static int T_1 F_13 ( void )
{
struct V_1 * V_2 ;
int V_3 = 0 ;
struct V_4 V_14 [] = {
{
. V_6 = V_7 ,
} , {
. V_6 = V_15 ,
}
} ;
if ( ! F_10 ( V_16 ) )
return 0 ;
if ( F_11 () || F_12 () )
return 0 ;
V_2 = F_4 ( L_3 , 0 ) ;
if ( ! V_2 ) {
V_3 = - V_11 ;
goto V_12;
}
V_14 [ 0 ] . V_8 = 0x00016F0000000400ULL ;
V_14 [ 0 ] . V_10 = V_14 [ 0 ] . V_8 + 0x100 ;
V_14 [ 1 ] . V_8 = V_17 ;
V_14 [ 1 ] . V_10 = V_17 ;
V_3 = F_5 ( V_2 , V_14 ,
F_6 ( V_14 ) ) ;
if ( V_3 )
goto V_13;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_13;
return V_3 ;
V_13:
F_8 ( V_2 ) ;
V_12:
return V_3 ;
}
static bool T_1 F_14 ( void )
{
return ! F_10 ( V_18 ) &&
! F_10 ( V_19 ) &&
! F_10 ( V_20 ) ;
}
static void T_1 F_15 ( int V_21 , int V_22 )
{
const T_2 * V_23 ;
const T_2 * V_24 ;
const T_2 * V_25 ;
T_3 V_26 ;
int V_27 ;
int V_28 ;
const char * V_29 ;
int V_30 ;
char V_31 [ 20 ] ;
V_23 = F_16 ( V_32 , V_21 , L_4 , NULL ) ;
if ( ! V_23 )
return;
V_26 = F_17 ( V_23 ) ;
V_27 = F_18 ( V_32 , V_26 ) ;
V_24 = F_16 ( V_32 , V_21 , L_5 , NULL ) ;
if ( V_24 ) {
T_3 V_33 = F_17 ( V_24 ) ;
V_28 = F_18 ( V_32 , V_33 ) ;
} else {
V_28 = - 1 ;
}
if ( V_22 < 0 || V_27 < 0 ) {
F_19 ( V_32 , V_21 , L_4 ) ;
F_19 ( V_32 , V_21 , L_5 ) ;
if ( V_27 >= 0 )
F_20 ( V_32 , V_27 ) ;
if ( V_28 >= 0 )
F_20 ( V_32 , V_28 ) ;
return;
}
if ( V_22 >= 256 && V_28 > 0 ) {
const struct V_34 * V_35 ;
struct V_34 * V_36 ;
T_3 V_37 ;
V_35 = F_21 ( V_32 , V_21 , L_4 , NULL ) ;
V_37 = V_35 -> V_38 ;
F_20 ( V_32 , V_27 ) ;
F_19 ( V_32 , V_21 , L_4 ) ;
V_36 = F_22 ( V_32 , V_21 , L_5 , NULL ) ;
V_36 -> V_38 = V_37 ;
V_27 = V_28 ;
}
V_22 &= 0xff ;
if ( F_14 () ) {
F_19 ( V_32 , V_27 , L_6 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
strcpy ( V_31 , L_7 ) ;
V_29 = F_16 ( V_32 , V_27 , L_8 ,
& V_30 ) ;
if ( V_29 && V_30 >= strlen ( V_31 ) )
F_23 ( V_32 , V_27 ,
L_8 , V_31 , V_30 ) ;
}
V_25 = F_16 ( V_32 , V_27 , L_9 , NULL ) ;
if ( V_22 == F_17 ( V_25 ) )
return;
F_24 ( V_32 , V_27 , L_9 , V_22 ) ;
snprintf ( V_31 , sizeof( V_31 ) , L_10 , V_22 ) ;
V_29 = F_25 ( V_32 , V_27 , & V_30 ) ;
if ( V_29 && V_30 == strlen ( V_31 ) )
F_26 ( V_32 , V_27 , V_31 ) ;
else
F_27 ( L_11 , V_29 ) ;
}
static void T_1 F_28 ( int V_39 , T_4 * V_40 )
{
T_5 V_41 [ 6 ] ;
T_4 V_42 = * V_40 ;
int V_43 ;
V_41 [ 0 ] = ( V_42 >> 40 ) & 0xff ;
V_41 [ 1 ] = ( V_42 >> 32 ) & 0xff ;
V_41 [ 2 ] = ( V_42 >> 24 ) & 0xff ;
V_41 [ 3 ] = ( V_42 >> 16 ) & 0xff ;
V_41 [ 4 ] = ( V_42 >> 8 ) & 0xff ;
V_41 [ 5 ] = V_42 & 0xff ;
V_43 = F_23 ( V_32 , V_39 , L_12 ,
V_41 , sizeof( V_41 ) ) ;
if ( V_43 ) {
F_27 ( L_13 , V_43 ) ;
return;
}
* V_40 = V_42 + 1 ;
}
static void T_1 F_29 ( int V_44 )
{
const T_2 * V_23 ;
V_23 = F_16 ( V_32 , V_44 , L_4 , NULL ) ;
if ( V_23 ) {
T_3 V_45 = F_17 ( V_23 ) ;
int V_29 = F_18 ( V_32 , V_45 ) ;
if ( V_29 >= 0 )
F_20 ( V_32 , V_29 ) ;
}
F_20 ( V_32 , V_44 ) ;
}
static void T_1 F_30 ( int V_46 , int V_47 , int V_29 , int V_48 , T_4 * V_40 )
{
char V_49 [ 20 ] ;
int V_21 ;
int V_22 ;
int V_50 ;
snprintf ( V_49 , sizeof( V_49 ) , L_14 , V_29 ) ;
V_21 = F_31 ( V_32 , V_46 , V_49 ) ;
if ( V_21 < 0 )
return;
if ( V_29 > V_48 ) {
F_32 ( L_15 , V_47 , V_29 ) ;
F_29 ( V_21 ) ;
return;
}
if ( F_10 ( V_51 ) )
V_50 = ( 0x100 * V_47 ) + ( 0x10 * V_29 ) + 0x800 ;
else
V_50 = 16 * V_47 + V_29 ;
V_22 = F_33 ( V_50 ) ;
F_15 ( V_21 , V_22 ) ;
F_28 ( V_21 , V_40 ) ;
}
static void T_1 F_34 ( int V_52 , int V_53 , T_4 * V_40 )
{
char V_49 [ 20 ] ;
int V_46 ;
int V_29 ;
int V_54 ;
V_54 = F_35 ( V_53 ) ;
snprintf ( V_49 , sizeof( V_49 ) , L_16 , V_53 ) ;
V_46 = F_31 ( V_32 , V_52 , V_49 ) ;
if ( V_46 < 0 )
return;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ )
F_30 ( V_46 , V_53 , V_29 , V_54 - 1 , V_40 ) ;
}
int T_1 F_36 ( void )
{
int V_47 , V_55 , V_56 ;
const char * V_57 ;
const char * V_58 ;
char V_49 [ 20 ] ;
int V_59 ;
T_4 V_60 ;
if ( F_37 ( V_32 ) )
F_38 ( L_17 ) ;
V_59 = F_39 ( V_32 , L_18 ) ;
if ( V_59 < 0 ) {
F_27 ( L_19 ) ;
return - V_61 ;
}
V_60 =
( ( V_62 -> V_60 [ 0 ] & 0xffull ) ) << 40 |
( ( V_62 -> V_60 [ 1 ] & 0xffull ) ) << 32 |
( ( V_62 -> V_60 [ 2 ] & 0xffull ) ) << 24 |
( ( V_62 -> V_60 [ 3 ] & 0xffull ) ) << 16 |
( ( V_62 -> V_60 [ 4 ] & 0xffull ) ) << 8 |
( V_62 -> V_60 [ 5 ] & 0xffull ) ;
if ( F_10 ( V_18 ) || F_10 ( V_16 ) )
V_55 = 2 ;
else if ( F_10 ( V_20 ) || F_10 ( V_51 ) )
V_55 = 1 ;
else
V_55 = 0 ;
if ( V_62 -> V_63 == V_64 )
V_55 = 0 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
int V_65 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_20 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_65 = F_39 ( V_32 , V_58 ) ;
if ( V_65 < 0 )
continue;
if ( V_47 >= V_55 ) {
F_32 ( L_21 , V_47 ) ;
F_29 ( V_65 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
} else {
int V_22 = F_33 ( V_66 + V_47 ) ;
F_15 ( V_65 , V_22 ) ;
F_28 ( V_65 , & V_60 ) ;
}
}
}
V_57 = F_16 ( V_32 , V_59 , L_22 , NULL ) ;
if ( V_57 ) {
int V_52 = F_39 ( V_32 , V_57 ) ;
if ( V_52 >= 0 )
for ( V_47 = 0 ; V_47 <= 4 ; V_47 ++ )
F_34 ( V_52 , V_47 , & V_60 ) ;
}
if ( F_10 ( V_18 ) ||
F_10 ( V_16 ) ||
F_10 ( V_51 ) ||
F_10 ( V_20 ) )
V_55 = 2 ;
else
V_55 = 1 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
int V_67 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_23 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_67 = F_39 ( V_32 , V_58 ) ;
if ( V_67 < 0 )
continue;
if ( V_47 >= V_55 ) {
F_32 ( L_24 , V_47 ) ;
F_20 ( V_32 , V_67 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
}
}
}
if ( F_10 ( V_51 ) )
V_55 = 4 ;
else if ( F_10 ( V_18 ) ||
F_10 ( V_16 ) ||
F_10 ( V_20 ) )
V_55 = 2 ;
else
V_55 = 1 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
int V_67 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_25 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_67 = F_39 ( V_32 , V_58 ) ;
if ( V_67 < 0 )
continue;
if ( V_47 >= V_55 ) {
F_32 ( L_26 , V_47 ) ;
F_20 ( V_32 , V_67 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
}
}
}
V_56 = 3 ;
if ( F_10 ( V_18 ) )
V_56 |= 4 ;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
int V_68 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_27 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_68 = F_39 ( V_32 , V_58 ) ;
if ( V_56 & ( 1 << V_47 ) )
continue;
F_32 ( L_28 , V_47 ) ;
F_20 ( V_32 , V_68 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
}
}
V_58 = F_16 ( V_32 , V_59 ,
L_29 , NULL ) ;
if ( V_58 ) {
union V_69 V_70 ;
unsigned long V_71 , V_72 , V_73 ;
unsigned long V_74 = 0 ;
unsigned long V_75 = 0 ;
int V_76 , V_77 ;
bool V_78 = false ;
bool V_79 = false ;
T_2 V_80 [ 6 ] ;
T_2 * V_81 ;
int V_82 ;
int V_83 = F_39 ( V_32 , V_58 ) ;
V_71 = 0 ;
if ( V_62 -> V_84 == 1
&& V_62 -> V_85 >= 1 ) {
if ( V_62 -> V_86 )
V_71 = V_62 -> V_86 ;
} else {
V_71 = 0x1d000800 ;
}
if ( ! V_71 )
goto V_87;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_70 . T_4 = F_40 ( F_41 ( V_76 ) ) ;
V_72 = V_70 . V_88 . V_89 << 16 ;
V_73 = ( V_70 . V_88 . V_90 + 1 ) << 16 ;
if ( V_70 . V_88 . V_91 && V_71 >= V_72
&& V_71 < V_72 + V_73 ) {
V_78 = V_70 . V_88 . V_92 ;
break;
}
}
if ( V_76 >= 7 ) {
goto V_87;
}
if ( ! ( V_71 & 0xfffful ) ) {
V_70 . T_4 =
F_40 ( F_41 ( V_76 + 1 ) ) ;
V_74 = V_70 . V_88 . V_89 << 16 ;
V_75 = ( V_70 . V_88 . V_90 + 1 ) << 16 ;
if ( ! V_70 . V_88 . V_91 )
goto V_87;
V_79 = true ;
} else {
F_19 ( V_32 , V_83 , L_30 ) ;
F_19 ( V_32 , V_83 , L_31 ) ;
if ( ! V_78 ) {
T_2 V_92 = F_42 ( 8 ) ;
F_23 ( V_32 , V_83 ,
L_32 , & V_92 , sizeof( V_92 ) ) ;
}
}
V_80 [ 0 ] = F_42 ( V_76 ) ;
V_80 [ 1 ] = F_42 ( 0 ) ;
V_80 [ 2 ] = F_42 ( 0x10000 ) ;
V_80 [ 3 ] = F_42 ( V_76 + 1 ) ;
V_80 [ 4 ] = F_42 ( 0 ) ;
V_80 [ 5 ] = F_42 ( 0x10000 ) ;
F_23 ( V_32 , V_83 ,
L_9 , V_80 , sizeof( V_80 ) ) ;
V_77 = F_43 ( V_32 , V_83 ) ;
if ( V_77 < 0 )
goto V_87;
V_81 = F_44 ( V_32 , V_77 , L_33 , & V_82 ) ;
if ( ! V_81 || V_82 < ( 5 * 8 * sizeof( T_2 ) ) )
goto V_87;
V_81 [ ( V_76 * 5 ) + 2 ] = F_42 ( V_72 >> 32 ) ;
V_81 [ ( V_76 * 5 ) + 3 ] = F_42 ( V_72 & 0xffffffff ) ;
V_81 [ ( V_76 * 5 ) + 4 ] = F_42 ( V_73 ) ;
if ( V_79 ) {
V_76 ++ ;
V_81 [ ( V_76 * 5 ) + 2 ] = F_42 ( V_74 >> 32 ) ;
V_81 [ ( V_76 * 5 ) + 3 ] = F_42 ( V_74 & 0xffffffff ) ;
V_81 [ ( V_76 * 5 ) + 4 ] = F_42 ( V_75 ) ;
}
goto V_93;
V_87:
F_20 ( V_32 , V_83 ) ;
V_93:
;
}
V_58 = F_16 ( V_32 , V_59 ,
L_34 , NULL ) ;
if ( V_58 ) {
union V_69 V_70 ;
unsigned long V_71 , V_72 , V_73 ;
int V_76 , V_77 ;
T_2 V_80 [ 6 ] ;
T_2 * V_81 ;
int V_82 ;
int V_94 = F_39 ( V_32 , V_58 ) ;
V_71 = V_62 -> V_95 ;
if ( V_71 == 0 )
goto V_96;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_70 . T_4 = F_40 ( F_41 ( V_76 ) ) ;
V_72 = V_70 . V_88 . V_89 << 16 ;
V_73 = ( V_70 . V_88 . V_90 + 1 ) << 16 ;
if ( V_70 . V_88 . V_91 && V_71 >= V_72
&& V_71 < V_72 + V_73 )
break;
}
if ( V_76 > 7 )
goto V_96;
V_80 [ 0 ] = F_42 ( V_76 ) ;
V_80 [ 1 ] = F_42 ( 0x20 ) ;
V_80 [ 2 ] = F_42 ( 0x20 ) ;
V_80 [ 3 ] = F_42 ( V_76 ) ;
V_80 [ 4 ] = F_42 ( 0 ) ;
V_80 [ 5 ] = F_42 ( 0x20 ) ;
F_23 ( V_32 , V_94 ,
L_9 , V_80 , sizeof( V_80 ) ) ;
V_77 = F_43 ( V_32 , V_94 ) ;
if ( V_77 < 0 )
goto V_96;
V_81 = F_44 ( V_32 , V_77 , L_33 , & V_82 ) ;
if ( ! V_81 || V_82 < ( 5 * 8 * sizeof( T_2 ) ) )
goto V_96;
V_81 [ ( V_76 * 5 ) + 2 ] = F_42 ( V_72 >> 32 ) ;
V_81 [ ( V_76 * 5 ) + 3 ] = F_42 ( V_72 & 0xffffffff ) ;
V_81 [ ( V_76 * 5 ) + 4 ] = F_42 ( V_73 ) ;
goto V_97;
V_96:
F_20 ( V_32 , V_94 ) ;
V_97:
;
}
V_58 = F_16 ( V_32 , V_59 ,
L_35 , NULL ) ;
if ( V_58 ) {
int V_98 = F_39 ( V_32 , V_58 ) ;
if ( V_98 >= 0 && ( ! F_10 ( V_19 ) ||
V_62 -> V_63 == V_99 ) ) {
F_32 ( L_36 ) ;
F_20 ( V_32 , V_98 ) ;
F_19 ( V_32 , V_59 , L_35 ) ;
} else if ( V_62 -> V_63 == V_64 ||
V_62 -> V_63 == V_100 ) {
F_19 ( V_32 , V_98 , L_37 ) ;
}
}
return 0 ;
}
static int T_1 F_45 ( void )
{
return F_46 ( NULL , V_101 , NULL ) ;
}
