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
static struct V_5 * F_11 ( struct V_9 * V_10 ,
int V_11 )
{
struct V_5 * V_6 = F_12 ( V_10 ) ;
F_13 ( & V_6 -> V_12 ) ;
if ( F_14 ( V_13 , V_6 -> V_14 + V_15 + V_15 / 2 ) || V_11 ) {
int V_16 , V_17 ;
V_17 = V_6 -> type == V_18 ? 3 : 2 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_6 -> V_19 [ V_16 ] = F_7 ( V_6 ,
V_20 [ V_16 ] ) ;
V_6 -> V_21 [ V_16 ] = F_7 ( V_6 ,
V_22 [ V_16 ] ) ;
V_6 -> V_23 [ V_16 ] = F_7 ( V_6 ,
V_24 [ V_16 ] ) ;
}
V_16 = F_7 ( V_6 , V_25 ) ;
V_6 -> V_26 [ 0 ] = ( V_16 >> 4 ) & 0x03 ;
V_6 -> V_26 [ 1 ] = V_16 >> 6 ;
V_6 -> V_27 = F_7 ( V_6 ,
V_28 ) >> 6 ;
if ( V_6 -> V_27 )
F_9 ( V_6 , V_28 , 0xC0 ) ;
if ( V_17 >= 3 ) {
V_6 -> V_26 [ 2 ] = ( F_7 ( V_6 ,
V_29 ) >> 4 ) & 0x03 ;
V_6 -> V_27 |= ( F_7 ( V_6 ,
V_30 ) & 0x40 ) >> 4 ;
if ( V_6 -> V_27 & 0x04 )
F_9 ( V_6 ,
V_30 ,
0x40 ) ;
}
V_6 -> V_14 = V_13 ;
}
F_15 ( & V_6 -> V_12 ) ;
return V_6 ;
}
static T_2 F_16 ( struct V_9 * V_10 , struct V_31
* V_32 , char * V_33 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_11 ( V_10 , 0 ) ;
int V_36 = V_35 -> V_37 ;
int V_38 = ( V_6 -> V_23 [ V_36 ] & 0x7F ) == 0x00 ? 0 :
F_18 ( V_6 -> V_19 [ V_36 ] ,
F_19 ( V_6 -> V_26 [ V_36 ] ) ,
V_6 -> V_21 [ V_36 ] ) ;
return sprintf ( V_33 , L_1 , V_38 ) ;
}
static T_2 F_20 ( struct V_9 * V_10 , struct V_31
* V_32 , char * V_33 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_11 ( V_10 , 0 ) ;
int V_36 = V_35 -> V_37 ;
int V_38 = F_21 ( V_6 -> V_21 [ V_36 ] ,
F_19 ( V_6 -> V_26 [ V_36 ] ) ) ;
return sprintf ( V_33 , L_1 , V_38 ) ;
}
static T_2 F_22 ( struct V_9 * V_10 , struct V_31
* V_32 , char * V_33 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_11 ( V_10 , 0 ) ;
return sprintf ( V_33 , L_1 , F_19 ( V_6 -> V_26 [ V_35 -> V_37 ] ) ) ;
}
static T_2 F_23 ( struct V_9 * V_10 , struct V_31
* V_32 , char * V_33 )
{
int V_39 = F_17 ( V_32 ) -> V_37 ;
struct V_5 * V_6 = F_11 ( V_10 , 0 ) ;
return sprintf ( V_33 , L_2 , ( V_6 -> V_27 >> V_39 ) & 1 ) ;
}
static T_2 F_24 ( struct V_9 * V_10 , struct V_31
* V_32 , char * V_33 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_11 ( V_10 , 0 ) ;
return sprintf ( V_33 , L_1 , F_25 ( V_6 -> V_23 [ V_35 -> V_37 ] ) ) ;
}
static T_2 F_26 ( struct V_9 * V_10 , struct V_31
* V_32 , char * V_33 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_11 ( V_10 , 0 ) ;
return sprintf ( V_33 , L_1 , F_27 ( V_6 -> V_23 [ V_35 -> V_37 ] ) ) ;
}
static T_2 F_28 ( struct V_9 * V_10 ,
struct V_31 * V_32 , char * V_33 )
{
struct V_5 * V_6 = F_11 ( V_10 , 0 ) ;
return sprintf ( V_33 , L_1 , V_6 -> V_27 ) ;
}
static T_2 F_29 ( struct V_9 * V_10 , struct V_31
* V_32 , const char * V_33 , T_3 V_40 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_12 ( V_10 ) ;
int V_36 = V_35 -> V_37 ;
long V_41 ;
long V_2 ;
int V_42 ;
V_42 = F_30 ( V_33 , 10 , & V_2 ) ;
if ( V_42 )
return V_42 ;
F_13 ( & V_6 -> V_12 ) ;
V_41 = V_2 * F_19 ( V_6 -> V_26 [ V_36 ] ) ;
if ( 983040 > 192 * V_41 || 2 * V_41 > 983040 ) {
F_15 ( & V_6 -> V_12 ) ;
return - V_43 ;
}
V_6 -> V_21 [ V_36 ] = 192 - ( ( 983040 + V_41 / 2 ) / V_41 ) ;
F_9 ( V_6 , V_22 [ V_36 ] ,
V_6 -> V_21 [ V_36 ] ) ;
F_15 ( & V_6 -> V_12 ) ;
return V_40 ;
}
static T_2 F_31 ( struct V_9 * V_10 , struct V_31
* V_32 , const char * V_33 , T_3 V_40 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_12 ( V_10 ) ;
int V_36 = V_35 -> V_37 ;
long V_44 ;
int V_42 ;
long V_45 ;
T_1 V_46 = F_19 ( V_6 -> V_26 [ V_36 ] ) ;
V_42 = F_30 ( V_33 , 10 , & V_44 ) ;
if ( V_42 )
return V_42 ;
if ( V_44 == V_46 )
return V_40 ;
F_13 ( & V_6 -> V_12 ) ;
switch ( V_44 ) {
case 1 :
V_6 -> V_26 [ V_36 ] = 0 ;
break;
case 2 :
V_6 -> V_26 [ V_36 ] = 1 ;
break;
case 4 :
V_6 -> V_26 [ V_36 ] = 2 ;
break;
case 8 :
V_6 -> V_26 [ V_36 ] = 3 ;
break;
default:
F_15 ( & V_6 -> V_12 ) ;
return - V_43 ;
}
switch ( V_36 ) {
case 0 :
case 1 :
V_45 = F_7 ( V_6 , V_25 )
& ~ ( 0x03 << ( 4 + 2 * V_36 ) ) ;
V_45 |= V_6 -> V_26 [ V_36 ] << ( 4 + 2 * V_36 ) ;
F_9 ( V_6 , V_25 , V_45 ) ;
break;
case 2 :
V_45 = F_7 ( V_6 , V_29 ) & 0xCF ;
V_45 |= V_6 -> V_26 [ 2 ] << 4 ;
F_9 ( V_6 , V_29 , V_45 ) ;
break;
}
V_45 = 192 - ( V_46 * ( 192 - V_6 -> V_21 [ V_36 ] )
+ V_44 / 2 ) / V_44 ;
V_6 -> V_21 [ V_36 ] = F_32 ( V_45 , 0 , 191 ) ;
F_9 ( V_6 , V_22 [ V_36 ] ,
V_6 -> V_21 [ V_36 ] ) ;
F_15 ( & V_6 -> V_12 ) ;
return V_40 ;
}
static T_2 F_33 ( struct V_9 * V_10 , struct V_31
* V_32 , const char * V_33 , T_3 V_40 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_12 ( V_10 ) ;
int V_36 = V_35 -> V_37 ;
long V_2 ;
int V_42 ;
V_42 = F_30 ( V_33 , 10 , & V_2 ) ;
if ( V_42 )
return V_42 ;
if ( V_2 < 0 || V_2 > 255 )
return - V_43 ;
F_13 ( & V_6 -> V_12 ) ;
V_6 -> V_23 [ V_36 ] &= 0x81 ;
V_6 -> V_23 [ V_36 ] |= F_34 ( V_2 ) ;
F_9 ( V_6 , V_24 [ V_36 ] ,
V_6 -> V_23 [ V_36 ] ) ;
F_15 ( & V_6 -> V_12 ) ;
return V_40 ;
}
static T_2 F_35 ( struct V_9 * V_10 , struct V_31
* V_32 , const char * V_33 , T_3 V_40 )
{
struct V_34 * V_35 = F_17 ( V_32 ) ;
struct V_5 * V_6 = F_12 ( V_10 ) ;
int V_36 = V_35 -> V_37 ;
unsigned long V_2 ;
int V_42 ;
V_42 = F_36 ( V_33 , 10 , & V_2 ) ;
if ( V_42 )
return V_42 ;
if ( V_2 > 1 )
return - V_43 ;
F_13 ( & V_6 -> V_12 ) ;
V_6 -> V_23 [ V_36 ] &= 0xFE ;
V_6 -> V_23 [ V_36 ] |= ! V_2 ;
F_9 ( V_6 , V_24 [ V_36 ] ,
V_6 -> V_23 [ V_36 ] ) ;
F_15 ( & V_6 -> V_12 ) ;
return V_40 ;
}
static T_2 F_37 ( struct V_9 * V_10 , struct V_31
* V_32 , char * V_33 )
{
struct V_5 * V_6 = F_12 ( V_10 ) ;
return sprintf ( V_33 , L_3 , V_6 -> V_47 ) ;
}
static int T_4 F_38 ( struct V_48 * V_49 )
{
T_1 V_2 ;
unsigned short V_7 ;
F_5 () ;
V_2 = V_50 ? V_50 : F_3 ( V_51 ) ;
switch ( V_2 ) {
case 0x51 :
F_39 ( L_4 ) ;
V_49 -> type = V_52 ;
break;
case 0x59 :
F_39 ( L_5 ) ;
V_49 -> type = V_52 ;
break;
case 0x5F :
F_39 ( L_6 ) ;
V_49 -> type = V_52 ;
break;
case 0x60 :
F_39 ( L_7 ) ;
V_49 -> type = V_52 ;
break;
case 0x6B :
if ( F_3 ( V_53 ) & 0x80 ) {
F_40 ( L_8 ) ;
F_6 () ;
return - V_54 ;
}
F_39 ( L_9 ) ;
V_49 -> type = V_18 ;
break;
default:
F_6 () ;
return - V_54 ;
}
F_41 () ;
V_7 = ( F_3 ( V_55 ) << 8 )
| F_3 ( V_55 + 1 ) ;
if ( V_7 == 0 ) {
F_39 ( L_10 ) ;
F_6 () ;
return - V_54 ;
}
V_49 -> V_56 = F_3 ( V_57 ) ;
if ( ( V_49 -> V_56 & 0x01 ) == 0 ) {
F_39 ( L_11 ) ;
F_1 ( V_57 , V_49 -> V_56 | 0x01 ) ;
}
F_6 () ;
return V_7 ;
}
static void F_42 ( const struct V_48 * V_49 )
{
if ( ( V_49 -> V_56 & 0x01 ) == 0 ) {
F_5 () ;
F_41 () ;
F_39 ( L_12 ) ;
F_1 ( V_57 , V_49 -> V_56 ) ;
F_6 () ;
}
}
static int T_4 F_43 ( unsigned short V_58 ,
enum V_59 type , int V_60 ,
struct V_9 * V_10 )
{
static const T_1 V_61 [] = {
0x04 , 1 ,
0x33 , 4 ,
0x56 , 7 ,
} ;
static const T_1 V_62 [] = {
0x04 , 1 ,
0x09 , 1 ,
0x2c , 2 ,
0x35 , 4 ,
0x56 , 7 ,
0x69 , 4 ,
} ;
int V_16 , V_63 , V_42 ;
const T_1 * V_64 ;
switch ( type ) {
case V_52 :
default:
V_64 = V_61 ;
V_63 = F_44 ( V_61 ) ;
break;
case V_18 :
V_64 = V_62 ;
V_63 = F_44 ( V_62 ) ;
break;
}
for ( V_16 = 0 ; V_16 + 1 < V_63 ; V_16 += 2 ) {
unsigned short V_65 = V_58 + V_64 [ V_16 ] ;
unsigned short V_66 = V_64 [ V_16 + 1 ] ;
switch ( V_60 ) {
case V_67 :
V_42 = F_45 ( V_65 , V_66 , V_68 ) ;
if ( V_42 )
return V_42 ;
break;
case V_69 :
if ( ! F_46 ( V_10 , V_65 , V_66 , V_68 ) ) {
F_47 ( V_10 ,
L_13 ,
V_65 , V_65 + V_66 ) ;
return - V_70 ;
}
break;
}
}
return 0 ;
}
static void F_48 ( struct V_9 * V_10 )
{
F_49 ( & V_10 -> V_71 , & V_72 ) ;
F_49 ( & V_10 -> V_71 , & V_73 ) ;
F_49 ( & V_10 -> V_71 , & V_74 ) ;
F_49 ( & V_10 -> V_71 , & V_75 ) ;
F_49 ( & V_10 -> V_71 , & V_76 ) ;
F_49 ( & V_10 -> V_71 , & V_77 ) ;
F_49 ( & V_10 -> V_71 , & V_78 ) ;
}
static int T_4 F_50 ( struct V_79 * V_80 )
{
struct V_9 * V_10 = & V_80 -> V_10 ;
struct V_48 * V_49 = F_51 ( V_10 ) ;
struct V_5 * V_6 ;
struct V_81 * V_82 ;
int V_42 ;
int V_83 , V_84 , V_85 , V_86 , V_87 , V_88 ;
static const char * const V_89 [] = {
L_14 ,
L_15 ,
} ;
V_82 = F_52 ( V_80 , V_90 , 0 ) ;
V_42 = F_43 ( V_82 -> V_65 , V_49 -> type ,
V_69 , V_10 ) ;
if ( V_42 < 0 )
return V_42 ;
V_6 = F_53 ( V_10 , sizeof( struct V_5 ) , V_91 ) ;
if ( ! V_6 )
return - V_92 ;
V_6 -> V_7 = V_82 -> V_65 ;
V_6 -> type = V_49 -> type ;
V_6 -> V_47 = V_89 [ V_49 -> type ] ;
F_54 ( & V_6 -> V_12 ) ;
F_55 ( V_80 , V_6 ) ;
V_86 = ( F_7 ( V_6 , F_56 ( 0 ) ) & 0x05 )
== 0x04 ;
V_87 = ( F_7 ( V_6 , F_56 ( 1 ) ) & 0x05 )
== 0x04 ;
if ( V_6 -> type == V_18 ) {
V_83 = ( F_7 ( V_6 , V_93 )
& 0x0d ) == 0x09 ;
V_84 = ( F_7 ( V_6 , V_94 )
& 0x0d ) == 0x09 ;
V_85 = ( F_7 ( V_6 , V_95 )
& 0x0d ) == 0x0d ;
V_88 = ( F_7 ( V_6 , V_96 )
& 0x0d ) == 0x08 ;
} else {
V_83 = ( F_7 ( V_6 , F_57 ( 0 ) )
& 0x05 ) == 0x05 ;
V_84 = ( F_7 ( V_6 , F_57 ( 1 ) )
& 0x05 ) == 0x05 ;
V_85 = 0 ;
V_88 = 0 ;
}
if ( ! ( V_83 || V_84 || V_85 || V_86 || V_87 || V_88 ) ) {
F_58 ( V_10 , L_16 ) ;
return - V_54 ;
}
F_11 ( V_10 , 1 ) ;
if ( V_83 ) {
V_42 = F_59 ( & V_10 -> V_71 ,
& V_73 ) ;
if ( V_42 )
goto V_97;
} else
F_60 ( V_10 , L_17 ) ;
if ( V_84 ) {
V_42 = F_59 ( & V_10 -> V_71 ,
& V_74 ) ;
if ( V_42 )
goto V_97;
} else
F_60 ( V_10 , L_18 ) ;
if ( V_85 ) {
V_42 = F_59 ( & V_10 -> V_71 ,
& V_75 ) ;
if ( V_42 )
goto V_97;
} else if ( V_6 -> type == V_18 )
F_60 ( V_10 , L_19 ) ;
if ( V_86 ) {
V_42 = F_59 ( & V_10 -> V_71 ,
& V_76 ) ;
if ( V_42 )
goto V_97;
} else
F_60 ( V_10 , L_20 ) ;
if ( V_87 ) {
V_42 = F_59 ( & V_10 -> V_71 ,
& V_77 ) ;
if ( V_42 )
goto V_97;
} else
F_60 ( V_10 , L_21 ) ;
if ( V_88 ) {
V_42 = F_59 ( & V_10 -> V_71 ,
& V_78 ) ;
if ( V_42 )
goto V_97;
} else if ( V_6 -> type == V_18 )
F_60 ( V_10 , L_22 ) ;
V_42 = F_59 ( & V_10 -> V_71 , & V_72 ) ;
if ( V_42 )
goto V_97;
V_6 -> V_98 = F_61 ( V_10 ) ;
if ( F_62 ( V_6 -> V_98 ) ) {
V_42 = F_63 ( V_6 -> V_98 ) ;
goto V_97;
}
return 0 ;
V_97:
F_48 ( V_10 ) ;
return V_42 ;
}
static int T_5 F_64 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = F_65 ( V_80 ) ;
F_66 ( V_6 -> V_98 ) ;
F_48 ( & V_80 -> V_10 ) ;
return 0 ;
}
static int T_4 F_67 ( unsigned short V_58 ,
const struct V_48 * V_49 )
{
struct V_81 V_82 = {
. V_65 = V_58 ,
. V_99 = V_58 + V_100 - 1 ,
. V_47 = V_68 ,
. V_101 = V_90 ,
} ;
int V_42 ;
V_42 = F_43 ( V_58 , V_49 -> type , V_67 , NULL ) ;
if ( V_42 )
goto exit;
V_80 = F_68 ( V_68 , V_58 ) ;
if ( ! V_80 ) {
V_42 = - V_92 ;
F_69 ( L_23 ) ;
goto exit;
}
V_42 = F_70 ( V_80 , & V_82 , 1 ) ;
if ( V_42 ) {
F_69 ( L_24 , V_42 ) ;
goto V_102;
}
V_42 = F_71 ( V_80 , V_49 ,
sizeof( struct V_48 ) ) ;
if ( V_42 ) {
F_69 ( L_25 ) ;
goto V_102;
}
V_42 = F_72 ( V_80 ) ;
if ( V_42 ) {
F_69 ( L_26 , V_42 ) ;
goto V_102;
}
return 0 ;
V_102:
F_73 ( V_80 ) ;
exit:
return V_42 ;
}
static int T_4 F_74 ( void )
{
int V_42 ;
unsigned short V_58 ;
struct V_48 V_49 ;
V_42 = F_38 ( & V_49 ) ;
if ( V_42 < 0 )
return V_42 ;
V_58 = V_42 ;
V_42 = F_67 ( V_58 , & V_49 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_75 ( & V_103 , F_50 ) ;
if ( V_42 )
goto V_104;
return 0 ;
V_104:
F_76 ( V_80 ) ;
F_42 ( & V_49 ) ;
return V_42 ;
}
static void T_5 F_77 ( void )
{
F_78 ( & V_103 ) ;
F_42 ( F_51 ( & V_80 -> V_10 ) ) ;
F_76 ( V_80 ) ;
}
