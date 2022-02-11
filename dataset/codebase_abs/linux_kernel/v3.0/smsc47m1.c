static inline void
F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
}
static inline int
F_3 ( int V_1 )
{
F_2 ( V_1 , V_3 ) ;
return F_4 ( V_4 ) ;
}
static inline void
F_5 ( void )
{
F_2 ( 0x55 , V_3 ) ;
}
static inline void
F_6 ( void )
{
F_2 ( 0xAA , V_3 ) ;
}
static inline int F_7 ( struct V_5 * V_6 , T_1 V_1 )
{
return F_8 ( V_6 -> V_7 + V_1 ) ;
}
static inline void F_9 ( struct V_5 * V_6 , T_1 V_1 ,
T_1 V_8 )
{
F_10 ( V_8 , V_6 -> V_7 + V_1 ) ;
}
static T_2 F_11 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_13 ( V_10 , 0 ) ;
int V_16 = V_15 -> V_17 ;
int V_18 = ( V_6 -> V_19 [ V_16 ] & 0x7F ) == 0x00 ? 0 :
F_14 ( V_6 -> V_20 [ V_16 ] ,
F_15 ( V_6 -> V_21 [ V_16 ] ) ,
V_6 -> V_22 [ V_16 ] ) ;
return sprintf ( V_13 , L_1 , V_18 ) ;
}
static T_2 F_16 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_13 ( V_10 , 0 ) ;
int V_16 = V_15 -> V_17 ;
int V_18 = F_17 ( V_6 -> V_22 [ V_16 ] ,
F_15 ( V_6 -> V_21 [ V_16 ] ) ) ;
return sprintf ( V_13 , L_1 , V_18 ) ;
}
static T_2 F_18 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_13 ( V_10 , 0 ) ;
return sprintf ( V_13 , L_1 , F_15 ( V_6 -> V_21 [ V_15 -> V_17 ] ) ) ;
}
static T_2 F_19 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
int V_23 = F_12 ( V_12 ) -> V_17 ;
struct V_5 * V_6 = F_13 ( V_10 , 0 ) ;
return sprintf ( V_13 , L_2 , ( V_6 -> V_24 >> V_23 ) & 1 ) ;
}
static T_2 F_20 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_13 ( V_10 , 0 ) ;
return sprintf ( V_13 , L_1 , F_21 ( V_6 -> V_19 [ V_15 -> V_17 ] ) ) ;
}
static T_2 F_22 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_13 ( V_10 , 0 ) ;
return sprintf ( V_13 , L_1 , F_23 ( V_6 -> V_19 [ V_15 -> V_17 ] ) ) ;
}
static T_2 F_24 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_5 * V_6 = F_13 ( V_10 , 0 ) ;
return sprintf ( V_13 , L_1 , V_6 -> V_24 ) ;
}
static T_2 F_25 ( struct V_9 * V_10 , struct V_11
* V_12 , const char * V_13 , T_3 V_25 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_26 ( V_10 ) ;
int V_16 = V_15 -> V_17 ;
long V_26 , V_2 = F_27 ( V_13 , NULL , 10 ) ;
F_28 ( & V_6 -> V_27 ) ;
V_26 = V_2 * F_15 ( V_6 -> V_21 [ V_16 ] ) ;
if ( 983040 > 192 * V_26 || 2 * V_26 > 983040 ) {
F_29 ( & V_6 -> V_27 ) ;
return - V_28 ;
}
V_6 -> V_22 [ V_16 ] = 192 - ( ( 983040 + V_26 / 2 ) / V_26 ) ;
F_9 ( V_6 , V_29 [ V_16 ] ,
V_6 -> V_22 [ V_16 ] ) ;
F_29 ( & V_6 -> V_27 ) ;
return V_25 ;
}
static T_2 F_30 ( struct V_9 * V_10 , struct V_11
* V_12 , const char * V_13 , T_3 V_25 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_26 ( V_10 ) ;
int V_16 = V_15 -> V_17 ;
long V_30 = F_27 ( V_13 , NULL , 10 ) , V_31 ;
T_1 V_32 = F_15 ( V_6 -> V_21 [ V_16 ] ) ;
if ( V_30 == V_32 )
return V_25 ;
F_28 ( & V_6 -> V_27 ) ;
switch ( V_30 ) {
case 1 : V_6 -> V_21 [ V_16 ] = 0 ; break;
case 2 : V_6 -> V_21 [ V_16 ] = 1 ; break;
case 4 : V_6 -> V_21 [ V_16 ] = 2 ; break;
case 8 : V_6 -> V_21 [ V_16 ] = 3 ; break;
default:
F_29 ( & V_6 -> V_27 ) ;
return - V_28 ;
}
switch ( V_16 ) {
case 0 :
case 1 :
V_31 = F_7 ( V_6 , V_33 )
& ~ ( 0x03 << ( 4 + 2 * V_16 ) ) ;
V_31 |= V_6 -> V_21 [ V_16 ] << ( 4 + 2 * V_16 ) ;
F_9 ( V_6 , V_33 , V_31 ) ;
break;
case 2 :
V_31 = F_7 ( V_6 , V_34 ) & 0xCF ;
V_31 |= V_6 -> V_21 [ 2 ] << 4 ;
F_9 ( V_6 , V_34 , V_31 ) ;
break;
}
V_31 = 192 - ( V_32 * ( 192 - V_6 -> V_22 [ V_16 ] )
+ V_30 / 2 ) / V_30 ;
V_6 -> V_22 [ V_16 ] = F_31 ( V_31 , 0 , 191 ) ;
F_9 ( V_6 , V_29 [ V_16 ] ,
V_6 -> V_22 [ V_16 ] ) ;
F_29 ( & V_6 -> V_27 ) ;
return V_25 ;
}
static T_2 F_32 ( struct V_9 * V_10 , struct V_11
* V_12 , const char * V_13 , T_3 V_25 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_26 ( V_10 ) ;
int V_16 = V_15 -> V_17 ;
long V_2 = F_27 ( V_13 , NULL , 10 ) ;
if ( V_2 < 0 || V_2 > 255 )
return - V_28 ;
F_28 ( & V_6 -> V_27 ) ;
V_6 -> V_19 [ V_16 ] &= 0x81 ;
V_6 -> V_19 [ V_16 ] |= F_33 ( V_2 ) ;
F_9 ( V_6 , V_35 [ V_16 ] ,
V_6 -> V_19 [ V_16 ] ) ;
F_29 ( & V_6 -> V_27 ) ;
return V_25 ;
}
static T_2 F_34 ( struct V_9 * V_10 , struct V_11
* V_12 , const char * V_13 , T_3 V_25 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_26 ( V_10 ) ;
int V_16 = V_15 -> V_17 ;
long V_2 = F_27 ( V_13 , NULL , 10 ) ;
if ( V_2 != 0 && V_2 != 1 )
return - V_28 ;
F_28 ( & V_6 -> V_27 ) ;
V_6 -> V_19 [ V_16 ] &= 0xFE ;
V_6 -> V_19 [ V_16 ] |= ! V_2 ;
F_9 ( V_6 , V_35 [ V_16 ] ,
V_6 -> V_19 [ V_16 ] ) ;
F_29 ( & V_6 -> V_27 ) ;
return V_25 ;
}
static T_2 F_35 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_5 * V_6 = F_26 ( V_10 ) ;
return sprintf ( V_13 , L_3 , V_6 -> V_36 ) ;
}
static int T_4 F_36 ( unsigned short * V_7 ,
struct V_37 * V_38 )
{
T_1 V_2 ;
F_5 () ;
V_2 = V_39 ? V_39 : F_3 ( V_40 ) ;
switch ( V_2 ) {
case 0x51 :
F_37 ( L_4 ) ;
V_38 -> type = V_41 ;
break;
case 0x59 :
F_37 ( L_5 ) ;
V_38 -> type = V_41 ;
break;
case 0x5F :
F_37 ( L_6 ) ;
V_38 -> type = V_41 ;
break;
case 0x60 :
F_37 ( L_7 ) ;
V_38 -> type = V_41 ;
break;
case 0x6B :
if ( F_3 ( V_42 ) & 0x80 ) {
F_38 ( L_8 ) ;
F_6 () ;
return - V_43 ;
}
F_37 ( L_9 ) ;
V_38 -> type = V_44 ;
break;
default:
F_6 () ;
return - V_43 ;
}
F_39 () ;
* V_7 = ( F_3 ( V_45 ) << 8 )
| F_3 ( V_45 + 1 ) ;
if ( * V_7 == 0 ) {
F_37 ( L_10 ) ;
F_6 () ;
return - V_43 ;
}
V_38 -> V_46 = F_3 ( V_47 ) ;
if ( ( V_38 -> V_46 & 0x01 ) == 0 ) {
F_37 ( L_11 ) ;
F_1 ( V_47 , V_38 -> V_46 | 0x01 ) ;
}
F_6 () ;
return 0 ;
}
static void F_40 ( const struct V_37 * V_38 )
{
if ( ( V_38 -> V_46 & 0x01 ) == 0 ) {
F_5 () ;
F_39 () ;
F_37 ( L_12 ) ;
F_1 ( V_47 , V_38 -> V_46 ) ;
F_6 () ;
}
}
static int F_41 ( unsigned short V_48 , enum V_49 type ,
int V_50 , struct V_9 * V_10 )
{
static const T_1 V_51 [] = {
0x04 , 1 ,
0x33 , 4 ,
0x56 , 7 ,
} ;
static const T_1 V_52 [] = {
0x04 , 1 ,
0x09 , 1 ,
0x2c , 2 ,
0x35 , 4 ,
0x56 , 7 ,
0x69 , 4 ,
} ;
int V_53 , V_54 , V_55 ;
const T_1 * V_56 ;
switch ( type ) {
case V_41 :
default:
V_56 = V_51 ;
V_54 = F_42 ( V_51 ) ;
break;
case V_44 :
V_56 = V_52 ;
V_54 = F_42 ( V_52 ) ;
break;
}
for ( V_53 = 0 ; V_53 + 1 < V_54 ; V_53 += 2 ) {
unsigned short V_57 = V_48 + V_56 [ V_53 ] ;
unsigned short V_58 = V_56 [ V_53 + 1 ] ;
switch ( V_50 ) {
case V_59 :
V_55 = F_43 ( V_57 , V_58 , V_60 ) ;
if ( V_55 )
return V_55 ;
break;
case V_61 :
if ( ! F_44 ( V_57 , V_58 , V_60 ) ) {
F_45 ( V_10 , L_13
L_14 , V_57 , V_57 + V_58 ) ;
for ( V_53 -= 2 ; V_53 >= 0 ; V_53 -= 2 )
F_46 ( V_48 + V_56 [ V_53 ] ,
V_56 [ V_53 + 1 ] ) ;
return - V_62 ;
}
break;
case V_63 :
F_46 ( V_57 , V_58 ) ;
break;
}
}
return 0 ;
}
static int T_4 F_47 ( struct V_64 * V_65 )
{
struct V_9 * V_10 = & V_65 -> V_10 ;
struct V_37 * V_38 = V_10 -> V_66 ;
struct V_5 * V_6 ;
struct V_67 * V_68 ;
int V_55 ;
int V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ;
static const char * V_75 [] = {
L_15 ,
L_16 ,
} ;
V_68 = F_48 ( V_65 , V_76 , 0 ) ;
V_55 = F_41 ( V_68 -> V_57 , V_38 -> type ,
V_61 , V_10 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! ( V_6 = F_49 ( sizeof( struct V_5 ) , V_77 ) ) ) {
V_55 = - V_78 ;
goto V_79;
}
V_6 -> V_7 = V_68 -> V_57 ;
V_6 -> type = V_38 -> type ;
V_6 -> V_36 = V_75 [ V_38 -> type ] ;
F_50 ( & V_6 -> V_27 ) ;
F_51 ( V_65 , V_6 ) ;
V_72 = ( F_7 ( V_6 , F_52 ( 0 ) ) & 0x05 )
== 0x04 ;
V_73 = ( F_7 ( V_6 , F_52 ( 1 ) ) & 0x05 )
== 0x04 ;
if ( V_6 -> type == V_44 ) {
V_69 = ( F_7 ( V_6 , V_80 )
& 0x0d ) == 0x09 ;
V_70 = ( F_7 ( V_6 , V_81 )
& 0x0d ) == 0x09 ;
V_71 = ( F_7 ( V_6 , V_82 )
& 0x0d ) == 0x0d ;
V_74 = ( F_7 ( V_6 , V_83 )
& 0x0d ) == 0x08 ;
} else {
V_69 = ( F_7 ( V_6 , F_53 ( 0 ) )
& 0x05 ) == 0x05 ;
V_70 = ( F_7 ( V_6 , F_53 ( 1 ) )
& 0x05 ) == 0x05 ;
V_71 = 0 ;
V_74 = 0 ;
}
if ( ! ( V_69 || V_70 || V_71 || V_72 || V_73 || V_74 ) ) {
F_54 ( V_10 , L_17 ) ;
V_55 = - V_43 ;
goto V_84;
}
F_13 ( V_10 , 1 ) ;
if ( V_69 ) {
if ( ( V_55 = F_55 ( V_10 ,
& V_85 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_87 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_88 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_89 . V_86 ) ) )
goto V_90;
} else
F_56 ( V_10 , L_18 ) ;
if ( V_70 ) {
if ( ( V_55 = F_55 ( V_10 ,
& V_91 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_92 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_93 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_94 . V_86 ) ) )
goto V_90;
} else
F_56 ( V_10 , L_19 ) ;
if ( V_71 ) {
if ( ( V_55 = F_55 ( V_10 ,
& V_95 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_96 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_97 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_98 . V_86 ) ) )
goto V_90;
} else if ( V_6 -> type == V_44 )
F_56 ( V_10 , L_20 ) ;
if ( V_72 ) {
if ( ( V_55 = F_55 ( V_10 ,
& V_99 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_100 . V_86 ) ) )
goto V_90;
} else
F_56 ( V_10 , L_21 ) ;
if ( V_73 ) {
if ( ( V_55 = F_55 ( V_10 ,
& V_101 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_102 . V_86 ) ) )
goto V_90;
} else
F_56 ( V_10 , L_22 ) ;
if ( V_74 ) {
if ( ( V_55 = F_55 ( V_10 ,
& V_103 . V_86 ) )
|| ( V_55 = F_55 ( V_10 ,
& V_104 . V_86 ) ) )
goto V_90;
} else if ( V_6 -> type == V_44 )
F_56 ( V_10 , L_23 ) ;
if ( ( V_55 = F_55 ( V_10 , & V_105 ) ) )
goto V_90;
if ( ( V_55 = F_55 ( V_10 , & V_106 ) ) )
goto V_90;
V_6 -> V_107 = F_57 ( V_10 ) ;
if ( F_58 ( V_6 -> V_107 ) ) {
V_55 = F_59 ( V_6 -> V_107 ) ;
goto V_90;
}
return 0 ;
V_90:
F_60 ( & V_10 -> V_108 , & V_109 ) ;
V_84:
F_51 ( V_65 , NULL ) ;
F_61 ( V_6 ) ;
V_79:
F_41 ( V_68 -> V_57 , V_38 -> type , V_63 , V_10 ) ;
return V_55 ;
}
static int T_5 F_62 ( struct V_64 * V_65 )
{
struct V_5 * V_6 = F_63 ( V_65 ) ;
struct V_67 * V_68 ;
F_64 ( V_6 -> V_107 ) ;
F_60 ( & V_65 -> V_10 . V_108 , & V_109 ) ;
V_68 = F_48 ( V_65 , V_76 , 0 ) ;
F_41 ( V_68 -> V_57 , V_6 -> type , V_63 , & V_65 -> V_10 ) ;
F_51 ( V_65 , NULL ) ;
F_61 ( V_6 ) ;
return 0 ;
}
static struct V_5 * F_13 ( struct V_9 * V_10 ,
int V_110 )
{
struct V_5 * V_6 = F_26 ( V_10 ) ;
F_28 ( & V_6 -> V_27 ) ;
if ( F_65 ( V_111 , V_6 -> V_112 + V_113 + V_113 / 2 ) || V_110 ) {
int V_53 , V_114 ;
V_114 = V_6 -> type == V_44 ? 3 : 2 ;
for ( V_53 = 0 ; V_53 < V_114 ; V_53 ++ ) {
V_6 -> V_20 [ V_53 ] = F_7 ( V_6 ,
V_115 [ V_53 ] ) ;
V_6 -> V_22 [ V_53 ] = F_7 ( V_6 ,
V_29 [ V_53 ] ) ;
V_6 -> V_19 [ V_53 ] = F_7 ( V_6 ,
V_35 [ V_53 ] ) ;
}
V_53 = F_7 ( V_6 , V_33 ) ;
V_6 -> V_21 [ 0 ] = ( V_53 >> 4 ) & 0x03 ;
V_6 -> V_21 [ 1 ] = V_53 >> 6 ;
V_6 -> V_24 = F_7 ( V_6 ,
V_116 ) >> 6 ;
if ( V_6 -> V_24 )
F_9 ( V_6 , V_116 , 0xC0 ) ;
if ( V_114 >= 3 ) {
V_6 -> V_21 [ 2 ] = ( F_7 ( V_6 ,
V_34 ) >> 4 ) & 0x03 ;
V_6 -> V_24 |= ( F_7 ( V_6 ,
V_117 ) & 0x40 ) >> 4 ;
if ( V_6 -> V_24 & 0x04 )
F_9 ( V_6 ,
V_117 ,
0x40 ) ;
}
V_6 -> V_112 = V_111 ;
}
F_29 ( & V_6 -> V_27 ) ;
return V_6 ;
}
static int T_4 F_66 ( unsigned short V_48 ,
const struct V_37 * V_38 )
{
struct V_67 V_68 = {
. V_57 = V_48 ,
. V_118 = V_48 + V_119 - 1 ,
. V_36 = V_60 ,
. V_120 = V_76 ,
} ;
int V_55 ;
V_55 = F_41 ( V_48 , V_38 -> type , V_59 , NULL ) ;
if ( V_55 )
goto exit;
V_65 = F_67 ( V_60 , V_48 ) ;
if ( ! V_65 ) {
V_55 = - V_78 ;
F_68 ( L_24 ) ;
goto exit;
}
V_55 = F_69 ( V_65 , & V_68 , 1 ) ;
if ( V_55 ) {
F_68 ( L_25 , V_55 ) ;
goto V_121;
}
V_55 = F_70 ( V_65 , V_38 ,
sizeof( struct V_37 ) ) ;
if ( V_55 ) {
F_68 ( L_26 ) ;
goto V_121;
}
V_55 = F_71 ( V_65 ) ;
if ( V_55 ) {
F_68 ( L_27 , V_55 ) ;
goto V_121;
}
return 0 ;
V_121:
F_72 ( V_65 ) ;
exit:
return V_55 ;
}
static int T_4 F_73 ( void )
{
int V_55 ;
unsigned short V_48 ;
struct V_37 V_38 ;
if ( F_36 ( & V_48 , & V_38 ) )
return - V_43 ;
V_55 = F_66 ( V_48 , & V_38 ) ;
if ( V_55 )
goto exit;
V_55 = F_74 ( & V_122 , F_47 ) ;
if ( V_55 )
goto V_123;
return 0 ;
V_123:
F_75 ( V_65 ) ;
F_40 ( & V_38 ) ;
exit:
return V_55 ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_122 ) ;
F_40 ( V_65 -> V_10 . V_66 ) ;
F_75 ( V_65 ) ;
}
