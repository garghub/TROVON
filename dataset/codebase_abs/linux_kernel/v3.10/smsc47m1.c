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
long V_26 ;
long V_2 ;
int V_27 ;
V_27 = F_27 ( V_13 , 10 , & V_2 ) ;
if ( V_27 )
return V_27 ;
F_28 ( & V_6 -> V_28 ) ;
V_26 = V_2 * F_15 ( V_6 -> V_21 [ V_16 ] ) ;
if ( 983040 > 192 * V_26 || 2 * V_26 > 983040 ) {
F_29 ( & V_6 -> V_28 ) ;
return - V_29 ;
}
V_6 -> V_22 [ V_16 ] = 192 - ( ( 983040 + V_26 / 2 ) / V_26 ) ;
F_9 ( V_6 , V_30 [ V_16 ] ,
V_6 -> V_22 [ V_16 ] ) ;
F_29 ( & V_6 -> V_28 ) ;
return V_25 ;
}
static T_2 F_30 ( struct V_9 * V_10 , struct V_11
* V_12 , const char * V_13 , T_3 V_25 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_26 ( V_10 ) ;
int V_16 = V_15 -> V_17 ;
long V_31 ;
int V_27 ;
long V_32 ;
T_1 V_33 = F_15 ( V_6 -> V_21 [ V_16 ] ) ;
V_27 = F_27 ( V_13 , 10 , & V_31 ) ;
if ( V_27 )
return V_27 ;
if ( V_31 == V_33 )
return V_25 ;
F_28 ( & V_6 -> V_28 ) ;
switch ( V_31 ) {
case 1 :
V_6 -> V_21 [ V_16 ] = 0 ;
break;
case 2 :
V_6 -> V_21 [ V_16 ] = 1 ;
break;
case 4 :
V_6 -> V_21 [ V_16 ] = 2 ;
break;
case 8 :
V_6 -> V_21 [ V_16 ] = 3 ;
break;
default:
F_29 ( & V_6 -> V_28 ) ;
return - V_29 ;
}
switch ( V_16 ) {
case 0 :
case 1 :
V_32 = F_7 ( V_6 , V_34 )
& ~ ( 0x03 << ( 4 + 2 * V_16 ) ) ;
V_32 |= V_6 -> V_21 [ V_16 ] << ( 4 + 2 * V_16 ) ;
F_9 ( V_6 , V_34 , V_32 ) ;
break;
case 2 :
V_32 = F_7 ( V_6 , V_35 ) & 0xCF ;
V_32 |= V_6 -> V_21 [ 2 ] << 4 ;
F_9 ( V_6 , V_35 , V_32 ) ;
break;
}
V_32 = 192 - ( V_33 * ( 192 - V_6 -> V_22 [ V_16 ] )
+ V_31 / 2 ) / V_31 ;
V_6 -> V_22 [ V_16 ] = F_31 ( V_32 , 0 , 191 ) ;
F_9 ( V_6 , V_30 [ V_16 ] ,
V_6 -> V_22 [ V_16 ] ) ;
F_29 ( & V_6 -> V_28 ) ;
return V_25 ;
}
static T_2 F_32 ( struct V_9 * V_10 , struct V_11
* V_12 , const char * V_13 , T_3 V_25 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_26 ( V_10 ) ;
int V_16 = V_15 -> V_17 ;
long V_2 ;
int V_27 ;
V_27 = F_27 ( V_13 , 10 , & V_2 ) ;
if ( V_27 )
return V_27 ;
if ( V_2 < 0 || V_2 > 255 )
return - V_29 ;
F_28 ( & V_6 -> V_28 ) ;
V_6 -> V_19 [ V_16 ] &= 0x81 ;
V_6 -> V_19 [ V_16 ] |= F_33 ( V_2 ) ;
F_9 ( V_6 , V_36 [ V_16 ] ,
V_6 -> V_19 [ V_16 ] ) ;
F_29 ( & V_6 -> V_28 ) ;
return V_25 ;
}
static T_2 F_34 ( struct V_9 * V_10 , struct V_11
* V_12 , const char * V_13 , T_3 V_25 )
{
struct V_14 * V_15 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_26 ( V_10 ) ;
int V_16 = V_15 -> V_17 ;
unsigned long V_2 ;
int V_27 ;
V_27 = F_35 ( V_13 , 10 , & V_2 ) ;
if ( V_27 )
return V_27 ;
if ( V_2 > 1 )
return - V_29 ;
F_28 ( & V_6 -> V_28 ) ;
V_6 -> V_19 [ V_16 ] &= 0xFE ;
V_6 -> V_19 [ V_16 ] |= ! V_2 ;
F_9 ( V_6 , V_36 [ V_16 ] ,
V_6 -> V_19 [ V_16 ] ) ;
F_29 ( & V_6 -> V_28 ) ;
return V_25 ;
}
static T_2 F_36 ( struct V_9 * V_10 , struct V_11
* V_12 , char * V_13 )
{
struct V_5 * V_6 = F_26 ( V_10 ) ;
return sprintf ( V_13 , L_3 , V_6 -> V_37 ) ;
}
static int T_4 F_37 ( struct V_38 * V_39 )
{
T_1 V_2 ;
unsigned short V_7 ;
F_5 () ;
V_2 = V_40 ? V_40 : F_3 ( V_41 ) ;
switch ( V_2 ) {
case 0x51 :
F_38 ( L_4 ) ;
V_39 -> type = V_42 ;
break;
case 0x59 :
F_38 ( L_5 ) ;
V_39 -> type = V_42 ;
break;
case 0x5F :
F_38 ( L_6 ) ;
V_39 -> type = V_42 ;
break;
case 0x60 :
F_38 ( L_7 ) ;
V_39 -> type = V_42 ;
break;
case 0x6B :
if ( F_3 ( V_43 ) & 0x80 ) {
F_39 ( L_8 ) ;
F_6 () ;
return - V_44 ;
}
F_38 ( L_9 ) ;
V_39 -> type = V_45 ;
break;
default:
F_6 () ;
return - V_44 ;
}
F_40 () ;
V_7 = ( F_3 ( V_46 ) << 8 )
| F_3 ( V_46 + 1 ) ;
if ( V_7 == 0 ) {
F_38 ( L_10 ) ;
F_6 () ;
return - V_44 ;
}
V_39 -> V_47 = F_3 ( V_48 ) ;
if ( ( V_39 -> V_47 & 0x01 ) == 0 ) {
F_38 ( L_11 ) ;
F_1 ( V_48 , V_39 -> V_47 | 0x01 ) ;
}
F_6 () ;
return V_7 ;
}
static void F_41 ( const struct V_38 * V_39 )
{
if ( ( V_39 -> V_47 & 0x01 ) == 0 ) {
F_5 () ;
F_40 () ;
F_38 ( L_12 ) ;
F_1 ( V_48 , V_39 -> V_47 ) ;
F_6 () ;
}
}
static int T_4 F_42 ( unsigned short V_49 ,
enum V_50 type , int V_51 ,
struct V_9 * V_10 )
{
static const T_1 V_52 [] = {
0x04 , 1 ,
0x33 , 4 ,
0x56 , 7 ,
} ;
static const T_1 V_53 [] = {
0x04 , 1 ,
0x09 , 1 ,
0x2c , 2 ,
0x35 , 4 ,
0x56 , 7 ,
0x69 , 4 ,
} ;
int V_54 , V_55 , V_27 ;
const T_1 * V_56 ;
switch ( type ) {
case V_42 :
default:
V_56 = V_52 ;
V_55 = F_43 ( V_52 ) ;
break;
case V_45 :
V_56 = V_53 ;
V_55 = F_43 ( V_53 ) ;
break;
}
for ( V_54 = 0 ; V_54 + 1 < V_55 ; V_54 += 2 ) {
unsigned short V_57 = V_49 + V_56 [ V_54 ] ;
unsigned short V_58 = V_56 [ V_54 + 1 ] ;
switch ( V_51 ) {
case V_59 :
V_27 = F_44 ( V_57 , V_58 , V_60 ) ;
if ( V_27 )
return V_27 ;
break;
case V_61 :
if ( ! F_45 ( V_10 , V_57 , V_58 , V_60 ) ) {
F_46 ( V_10 ,
L_13 ,
V_57 , V_57 + V_58 ) ;
return - V_62 ;
}
break;
}
}
return 0 ;
}
static void F_47 ( struct V_9 * V_10 )
{
F_48 ( & V_10 -> V_63 , & V_64 ) ;
F_48 ( & V_10 -> V_63 , & V_65 ) ;
F_48 ( & V_10 -> V_63 , & V_66 ) ;
F_48 ( & V_10 -> V_63 , & V_67 ) ;
F_48 ( & V_10 -> V_63 , & V_68 ) ;
F_48 ( & V_10 -> V_63 , & V_69 ) ;
F_48 ( & V_10 -> V_63 , & V_70 ) ;
}
static int T_4 F_49 ( struct V_71 * V_72 )
{
struct V_9 * V_10 = & V_72 -> V_10 ;
struct V_38 * V_39 = V_10 -> V_73 ;
struct V_5 * V_6 ;
struct V_74 * V_75 ;
int V_27 ;
int V_76 , V_77 , V_78 , V_79 , V_80 , V_81 ;
static const char * const V_82 [] = {
L_14 ,
L_15 ,
} ;
V_75 = F_50 ( V_72 , V_83 , 0 ) ;
V_27 = F_42 ( V_75 -> V_57 , V_39 -> type ,
V_61 , V_10 ) ;
if ( V_27 < 0 )
return V_27 ;
V_6 = F_51 ( V_10 , sizeof( struct V_5 ) , V_84 ) ;
if ( ! V_6 )
return - V_85 ;
V_6 -> V_7 = V_75 -> V_57 ;
V_6 -> type = V_39 -> type ;
V_6 -> V_37 = V_82 [ V_39 -> type ] ;
F_52 ( & V_6 -> V_28 ) ;
F_53 ( V_72 , V_6 ) ;
V_79 = ( F_7 ( V_6 , F_54 ( 0 ) ) & 0x05 )
== 0x04 ;
V_80 = ( F_7 ( V_6 , F_54 ( 1 ) ) & 0x05 )
== 0x04 ;
if ( V_6 -> type == V_45 ) {
V_76 = ( F_7 ( V_6 , V_86 )
& 0x0d ) == 0x09 ;
V_77 = ( F_7 ( V_6 , V_87 )
& 0x0d ) == 0x09 ;
V_78 = ( F_7 ( V_6 , V_88 )
& 0x0d ) == 0x0d ;
V_81 = ( F_7 ( V_6 , V_89 )
& 0x0d ) == 0x08 ;
} else {
V_76 = ( F_7 ( V_6 , F_55 ( 0 ) )
& 0x05 ) == 0x05 ;
V_77 = ( F_7 ( V_6 , F_55 ( 1 ) )
& 0x05 ) == 0x05 ;
V_78 = 0 ;
V_81 = 0 ;
}
if ( ! ( V_76 || V_77 || V_78 || V_79 || V_80 || V_81 ) ) {
F_56 ( V_10 , L_16 ) ;
return - V_44 ;
}
F_13 ( V_10 , 1 ) ;
if ( V_76 ) {
V_27 = F_57 ( & V_10 -> V_63 ,
& V_65 ) ;
if ( V_27 )
goto V_90;
} else
F_58 ( V_10 , L_17 ) ;
if ( V_77 ) {
V_27 = F_57 ( & V_10 -> V_63 ,
& V_66 ) ;
if ( V_27 )
goto V_90;
} else
F_58 ( V_10 , L_18 ) ;
if ( V_78 ) {
V_27 = F_57 ( & V_10 -> V_63 ,
& V_67 ) ;
if ( V_27 )
goto V_90;
} else if ( V_6 -> type == V_45 )
F_58 ( V_10 , L_19 ) ;
if ( V_79 ) {
V_27 = F_57 ( & V_10 -> V_63 ,
& V_68 ) ;
if ( V_27 )
goto V_90;
} else
F_58 ( V_10 , L_20 ) ;
if ( V_80 ) {
V_27 = F_57 ( & V_10 -> V_63 ,
& V_69 ) ;
if ( V_27 )
goto V_90;
} else
F_58 ( V_10 , L_21 ) ;
if ( V_81 ) {
V_27 = F_57 ( & V_10 -> V_63 ,
& V_70 ) ;
if ( V_27 )
goto V_90;
} else if ( V_6 -> type == V_45 )
F_58 ( V_10 , L_22 ) ;
V_27 = F_57 ( & V_10 -> V_63 , & V_64 ) ;
if ( V_27 )
goto V_90;
V_6 -> V_91 = F_59 ( V_10 ) ;
if ( F_60 ( V_6 -> V_91 ) ) {
V_27 = F_61 ( V_6 -> V_91 ) ;
goto V_90;
}
return 0 ;
V_90:
F_47 ( V_10 ) ;
return V_27 ;
}
static int T_5 F_62 ( struct V_71 * V_72 )
{
struct V_5 * V_6 = F_63 ( V_72 ) ;
F_64 ( V_6 -> V_91 ) ;
F_47 ( & V_72 -> V_10 ) ;
return 0 ;
}
static struct V_5 * F_13 ( struct V_9 * V_10 ,
int V_92 )
{
struct V_5 * V_6 = F_26 ( V_10 ) ;
F_28 ( & V_6 -> V_28 ) ;
if ( F_65 ( V_93 , V_6 -> V_94 + V_95 + V_95 / 2 ) || V_92 ) {
int V_54 , V_96 ;
V_96 = V_6 -> type == V_45 ? 3 : 2 ;
for ( V_54 = 0 ; V_54 < V_96 ; V_54 ++ ) {
V_6 -> V_20 [ V_54 ] = F_7 ( V_6 ,
V_97 [ V_54 ] ) ;
V_6 -> V_22 [ V_54 ] = F_7 ( V_6 ,
V_30 [ V_54 ] ) ;
V_6 -> V_19 [ V_54 ] = F_7 ( V_6 ,
V_36 [ V_54 ] ) ;
}
V_54 = F_7 ( V_6 , V_34 ) ;
V_6 -> V_21 [ 0 ] = ( V_54 >> 4 ) & 0x03 ;
V_6 -> V_21 [ 1 ] = V_54 >> 6 ;
V_6 -> V_24 = F_7 ( V_6 ,
V_98 ) >> 6 ;
if ( V_6 -> V_24 )
F_9 ( V_6 , V_98 , 0xC0 ) ;
if ( V_96 >= 3 ) {
V_6 -> V_21 [ 2 ] = ( F_7 ( V_6 ,
V_35 ) >> 4 ) & 0x03 ;
V_6 -> V_24 |= ( F_7 ( V_6 ,
V_99 ) & 0x40 ) >> 4 ;
if ( V_6 -> V_24 & 0x04 )
F_9 ( V_6 ,
V_99 ,
0x40 ) ;
}
V_6 -> V_94 = V_93 ;
}
F_29 ( & V_6 -> V_28 ) ;
return V_6 ;
}
static int T_4 F_66 ( unsigned short V_49 ,
const struct V_38 * V_39 )
{
struct V_74 V_75 = {
. V_57 = V_49 ,
. V_100 = V_49 + V_101 - 1 ,
. V_37 = V_60 ,
. V_102 = V_83 ,
} ;
int V_27 ;
V_27 = F_42 ( V_49 , V_39 -> type , V_59 , NULL ) ;
if ( V_27 )
goto exit;
V_72 = F_67 ( V_60 , V_49 ) ;
if ( ! V_72 ) {
V_27 = - V_85 ;
F_68 ( L_23 ) ;
goto exit;
}
V_27 = F_69 ( V_72 , & V_75 , 1 ) ;
if ( V_27 ) {
F_68 ( L_24 , V_27 ) ;
goto V_103;
}
V_27 = F_70 ( V_72 , V_39 ,
sizeof( struct V_38 ) ) ;
if ( V_27 ) {
F_68 ( L_25 ) ;
goto V_103;
}
V_27 = F_71 ( V_72 ) ;
if ( V_27 ) {
F_68 ( L_26 , V_27 ) ;
goto V_103;
}
return 0 ;
V_103:
F_72 ( V_72 ) ;
exit:
return V_27 ;
}
static int T_4 F_73 ( void )
{
int V_27 ;
unsigned short V_49 ;
struct V_38 V_39 ;
V_27 = F_37 ( & V_39 ) ;
if ( V_27 < 0 )
return V_27 ;
V_49 = V_27 ;
V_27 = F_66 ( V_49 , & V_39 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_74 ( & V_104 , F_49 ) ;
if ( V_27 )
goto V_105;
return 0 ;
V_105:
F_75 ( V_72 ) ;
F_41 ( & V_39 ) ;
return V_27 ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_104 ) ;
F_41 ( V_72 -> V_10 . V_73 ) ;
F_75 ( V_72 ) ;
}
