static int F_1 ( struct V_1 * V_2 )
{
long V_3 ;
unsigned char V_4 ;
for ( V_3 = 1 ; V_3 <= V_5 + 30 ; V_3 ++ ) {
V_4 = F_2 ( V_2 -> V_6 + V_7 ) ;
if ( ( V_4 & 1 ) == 0 ) {
if ( V_3 >= V_5 )
F_3 ( L_1 ,
V_3 - V_5 ) ;
return V_4 ;
}
if ( V_3 >= V_5 ) {
long V_8 = 10 * V_9 ;
switch ( V_3 - V_5 ) {
case 0 ... 9 :
V_8 /= 10 ;
case 10 ... 19 :
V_8 /= 10 ;
case 20 ... 30 :
V_8 /= 10 ;
default:
F_4 ( V_10 ) ;
F_5 ( V_8 ) ;
break;
}
}
}
F_6 ( V_11 L_2 ) ;
return - V_12 ;
}
static inline int F_7 ( struct V_1 * V_2 , unsigned char V_4 )
{
if ( F_1 ( V_2 ) >= 0 ) {
F_8 ( V_4 , V_2 -> V_6 + V_13 ) ;
return 0 ;
} else {
F_6 ( V_11 L_3 , V_4 ) ;
return - V_12 ;
}
}
static inline int F_9 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( F_1 ( V_2 ) >= 0 ) {
V_4 = F_2 ( V_2 -> V_6 + V_14 ) ;
return V_4 ;
} else {
F_6 ( V_11 L_4 ) ;
return - V_12 ;
}
}
int F_10 ( struct V_1 * V_2 , int V_15 , int V_16 , int V_17 )
{
int V_18 [] = { V_15 , V_16 , V_17 } ;
int V_19 , V_20 ;
if ( F_11 ( & V_2 -> V_21 ) )
return - V_22 ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ ) {
if ( V_18 [ V_20 ] < 0 || V_18 [ V_20 ] > 255 )
break;
else {
V_19 = F_7 ( V_2 , V_18 [ V_20 ] ) ;
if ( V_19 < 0 )
goto V_8;
}
}
V_19 = F_9 ( V_2 ) ;
V_8: F_12 ( & V_2 -> V_21 ) ;
return V_19 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned char V_23 )
{
return F_10 ( V_2 , V_24 , V_23 , - 1 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned char V_23 ,
int V_19 )
{
return F_10 ( V_2 , V_23 , V_19 , - 1 ) ;
}
struct V_1 * F_15 ( void )
{
if ( V_25 . V_6 == 0 )
return NULL ;
return & V_25 ;
}
static int F_16 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
int V_19 ;
V_19 = F_13 ( V_31 -> V_2 , V_32 ) ;
if ( V_19 < 0 ) {
F_6 ( V_11 L_5 ,
V_19 ) ;
return V_19 ;
}
V_29 -> V_19 . integer . V_19 [ 0 ] = V_19 & 0x20 ;
return 0 ;
}
static int F_18 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
int V_33 , V_19 , error ;
V_19 = ! ( V_29 -> V_19 . integer . V_19 [ 0 ] ) ;
error = F_14 ( V_31 -> V_2 , V_34 , V_19 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_6 ,
error ) ;
return error ;
}
V_33 = ( V_19 != V_31 -> V_2 -> V_35 ) ;
V_31 -> V_2 -> V_35 = V_19 ;
return V_33 ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_36 * V_37 )
{
V_37 -> type = V_38 ;
V_37 -> V_39 = 1 ;
V_37 -> V_19 . integer . V_40 = 0 ;
V_37 -> V_19 . integer . V_41 = 3 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
int V_19 ;
if ( V_31 -> V_2 -> V_42 <= 176 ) {
V_29 -> V_19 . integer . V_19 [ 0 ] = V_31 -> V_2 -> V_43 ;
return 0 ;
}
V_19 = F_13 ( V_31 -> V_2 , V_44 ) ;
if ( V_19 < 0 ) {
F_6 ( V_11 L_7 ,
V_19 ) ;
return V_19 ;
}
V_29 -> V_19 . integer . V_19 [ 0 ] = V_19 ;
return 0 ;
}
static int F_21 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
int error , V_19 , V_33 ;
V_19 = V_29 -> V_19 . integer . V_19 [ 0 ] ;
error = F_14 ( V_31 -> V_2 , V_45 , V_19 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_8 ,
error ) ;
return error ;
}
V_33 = ( V_19 != V_31 -> V_2 -> V_43 ) ;
V_31 -> V_2 -> V_43 = V_19 ;
return V_33 ;
}
static int F_22 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
V_29 -> V_19 . integer . V_19 [ 0 ] = V_31 -> V_2 -> V_46 ;
return 0 ;
}
static int F_23 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
int error , V_19 , V_33 ;
V_19 = V_29 -> V_19 . integer . V_19 [ 0 ] ;
error = F_14 ( V_31 -> V_2 , V_47 , V_19 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_9 , V_19 , error ) ;
return error ;
}
V_33 = ( V_19 != V_31 -> V_2 -> V_46 ) ;
V_31 -> V_2 -> V_46 = V_19 ;
return V_33 ;
}
static int F_24 ( struct V_26 * V_27 ,
struct V_36 * V_37 )
{
int V_48 = V_27 -> V_49 & 0xff ;
V_37 -> type = V_38 ;
V_37 -> V_39 = 2 ;
if ( ( V_48 >= V_50 ) && ( V_48 <= V_51 ) ) {
V_37 -> V_19 . integer . V_40 = - 0x7f ;
V_37 -> V_19 . integer . V_41 = 0x7f ;
} else {
V_37 -> V_19 . integer . V_40 = 0 ;
V_37 -> V_19 . integer . V_41 = 0x20 ;
}
return 0 ;
}
static int F_25 ( struct V_26 * V_27 ,
struct V_28 * V_37 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
int V_52 , V_53 ;
int V_54 = V_27 -> V_49 & 0xff ;
int V_55 = V_54 + 1 ;
V_53 = F_13 ( V_31 -> V_2 , V_54 ) ;
if ( V_53 < 0 ) {
F_6 ( V_11 L_10 , V_54 , V_53 ) ;
return V_53 ;
}
V_52 = F_13 ( V_31 -> V_2 , V_55 ) ;
if ( V_52 < 0 ) {
F_6 ( V_11 L_10 , V_55 , V_52 ) ;
return V_52 ;
}
if ( ( V_54 >= V_50 ) && ( V_54 <= V_51 ) ) {
if ( V_52 < 0x80 ) {
V_37 -> V_19 . integer . V_19 [ 0 ] = V_52 ;
} else {
V_37 -> V_19 . integer . V_19 [ 0 ] = 0x80 - V_52 ;
}
if ( V_53 < 0x80 ) {
V_37 -> V_19 . integer . V_19 [ 1 ] = V_53 ;
} else {
V_37 -> V_19 . integer . V_19 [ 1 ] = 0x80 - V_53 ;
}
} else {
V_37 -> V_19 . integer . V_19 [ 0 ] = 0x20 - V_52 ;
V_37 -> V_19 . integer . V_19 [ 1 ] = 0x20 - V_53 ;
}
return 0 ;
}
static int F_26 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_27 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_56 , V_57 , V_58 , V_59 ;
int V_60 , V_61 , V_62 , V_63 ;
int V_33 , error ;
V_56 = V_29 -> V_19 . integer . V_19 [ 0 ] ;
V_57 = V_29 -> V_19 . integer . V_19 [ 1 ] ;
V_61 = ( V_27 -> V_49 >> 8 ) & 0xff ;
V_60 = V_61 + 8 ;
if ( V_61 == V_64 )
V_60 -= 7 ;
V_63 = V_27 -> V_49 & 0xff ;
V_62 = V_63 + 1 ;
V_58 = F_13 ( V_2 , V_62 ) ;
if ( V_58 < 0 ) {
F_6 ( V_11 L_10 , V_62 , V_58 ) ;
return V_58 ;
}
V_59 = F_13 ( V_2 , V_63 ) ;
if ( V_59 < 0 ) {
F_6 ( V_11 L_10 , V_63 , V_59 ) ;
return V_59 ;
}
if ( ( V_63 >= V_50 ) && ( V_63 <= V_51 ) ) {
if ( V_56 < - 0x7f || V_56 > 0x7f ||
V_57 < - 0x7f || V_57 > 0x7f )
return - V_65 ;
if ( V_58 > 0x80 )
V_58 = 0x80 - V_58 ;
if ( V_59 > 0x80 )
V_59 = 0x80 - V_59 ;
if ( V_56 >= 0 ) {
error = F_14 ( V_2 , V_60 , V_56 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_11 ,
V_56 , error ) ;
return error ;
}
} else {
error = F_14 ( V_2 , V_60 , 0x80 - V_56 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_11 ,
0x80 - V_56 , error ) ;
return error ;
}
}
if ( V_57 >= 0 ) {
error = F_14 ( V_2 , V_61 , V_57 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_11 ,
V_57 , error ) ;
return error ;
}
} else {
error = F_14 ( V_2 , V_61 , 0x80 - V_57 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_11 ,
0x80 - V_57 , error ) ;
return error ;
}
}
} else {
if ( V_56 < 0 || V_56 > 0x20 ||
V_57 < 0 || V_57 > 0x20 )
return - V_65 ;
V_58 = 0x20 - V_58 ;
V_59 = 0x20 - V_59 ;
error = F_14 ( V_2 , V_60 , 0x20 - V_56 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_11 ,
0x20 - V_56 , error ) ;
return error ;
}
error = F_14 ( V_2 , V_61 , 0x20 - V_57 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_11 ,
0x20 - V_57 , error ) ;
return error ;
}
}
V_33 = ( V_56 != V_58 ) || ( V_57 != V_59 ) ;
return V_33 ;
}
static int T_1 F_27 ( struct V_30 * V_31 )
{
int V_66 , error ;
struct V_1 * V_2 = V_31 -> V_2 ;
if ( ( V_2 -> V_67 == 'A' ) && V_68 ) {
error = F_14 ( V_2 , V_69 , V_68 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_12 ) ;
return error ;
}
}
if ( V_70 ) {
error = F_14 ( V_2 , V_71 , V_70 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_13 ) ;
return error ;
}
}
for ( V_66 = 0 ; V_66 < F_28 ( V_72 ) ; V_66 ++ ) {
error = F_14 ( V_2 , V_72 [ V_66 ] [ 0 ] ,
V_72 [ V_66 ] [ 1 ] ) ;
if ( error < 0 ) {
F_6 ( V_11 L_11 ,
V_72 [ V_66 ] [ 0 ] , error ) ;
return error ;
}
}
V_2 -> V_46 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_35 = 1 ;
return 0 ;
}
static int T_1 F_29 ( struct V_73 * V_74 ,
struct V_30 * V_31 )
{
unsigned int V_66 ;
int V_75 ;
if ( F_30 ( ! V_31 || ! V_74 ) )
return - V_65 ;
switch ( V_31 -> V_76 ) {
case V_77 :
strcpy ( V_74 -> V_78 , L_14 ) ;
break;
case V_79 :
strcpy ( V_74 -> V_78 , L_15 ) ;
break;
default:
F_31 () ;
break;
}
for ( V_66 = 0 ; V_66 < F_28 ( V_80 ) ; V_66 ++ ) {
if ( ( V_75 = F_32 ( V_74 , F_33 ( & V_80 [ V_66 ] , V_31 ) ) ) < 0 )
return V_75 ;
}
if ( ( V_31 -> V_2 -> V_67 == 'A' ) ||
( V_31 -> V_2 -> V_67 == 'B' ) ) {
if ( ( V_75 = F_32 ( V_74 , F_33 ( & V_81 [ 0 ] , V_31 ) ) ) < 0 )
return V_75 ;
if ( ( V_75 = F_32 ( V_74 , F_33 ( & V_82 [ 0 ] , V_31 ) ) ) < 0 )
return V_75 ;
}
if ( ( V_31 -> V_2 -> V_67 == 'B' ) ||
( V_31 -> V_2 -> V_67 == 'C' ) ) {
if ( ( V_75 = F_32 ( V_74 , F_33 ( & V_83 [ 0 ] , V_31 ) ) ) < 0 )
return V_75 ;
if ( V_31 -> V_2 -> V_42 >= 176 )
if ( ( V_75 = F_32 ( V_74 , F_33 ( & V_84 [ 0 ] , V_31 ) ) ) < 0 )
return V_75 ;
}
if ( V_31 -> V_2 -> V_67 == 'C' ) {
if ( ( V_75 = F_32 ( V_74 , F_33 ( & V_85 [ 0 ] , V_31 ) ) ) < 0 )
return V_75 ;
for ( V_66 = 0 ; V_66 < F_28 ( V_86 ) ; V_66 ++ ) {
if ( ( V_75 = F_32 ( V_74 , F_33 ( & V_86 [ V_66 ] , V_31 ) ) ) < 0 )
return V_75 ;
}
}
return 0 ;
}
static long F_34 ( long * V_87 , long V_88 )
{
while ( * V_87 != - 1 ) {
struct V_89 * V_90 ;
if ( ( V_90 = F_35 ( * V_87 , V_88 ,
L_16 ) ) != NULL ) {
F_36 ( V_90 ) ;
return * V_87 ;
}
V_87 ++ ;
}
return - 1 ;
}
static int T_1 F_37 ( struct V_30 * V_91 ,
unsigned short V_76 )
{
static int V_92 [] = { 7 , 7 , 10 , 10 , 2 , 2 , 2 } ;
V_91 -> V_76 = V_76 ;
strcpy ( V_91 -> V_93 , V_94 [ V_76 ] ) ;
V_91 -> V_95 = V_92 [ V_76 ] ;
F_38 ( & V_91 -> V_96 ) ;
V_91 -> V_97 = - 1 ;
V_91 -> V_98 = - 1 ;
V_91 -> V_99 = - 1 ;
V_91 -> V_100 = - 1 ;
V_91 -> V_101 = - 1 ;
V_91 -> V_102 = - 1 ;
V_91 -> V_103 = 3 ;
#ifdef F_39
if ( V_104 && V_91 -> V_105 )
V_91 -> V_105 |= 0xc00 ;
else
#endif
V_91 -> V_105 = 0xf8c ;
switch ( V_76 ) {
case V_79 :
V_91 -> V_106 = 0xe3 ;
break;
case V_77 :
V_91 -> V_106 = 0xe5 ;
break;
default:
F_6 ( V_11 L_17 , V_76 ) ;
return - V_107 ;
}
return 0 ;
}
static unsigned char F_40 ( struct V_30 * V_91 ,
unsigned char V_48 )
{
unsigned long V_108 ;
unsigned char V_109 = 0xff ;
F_41 ( & V_91 -> V_96 , V_108 ) ;
F_8 ( V_91 -> V_106 , V_91 -> V_105 + V_91 -> V_103 ) ;
switch ( V_91 -> V_76 ) {
case V_77 :
if ( V_48 > 7 ) {
F_8 ( V_48 , V_91 -> V_105 + 8 ) ;
F_8 ( V_91 -> V_106 , V_91 -> V_105 + V_91 -> V_103 ) ;
V_109 = F_2 ( V_91 -> V_105 + 9 ) ;
break;
}
case V_79 :
V_109 = F_2 ( V_91 -> V_105 + V_48 ) ;
break;
default:
F_6 ( V_11 L_17 , V_91 -> V_76 ) ;
}
F_42 ( & V_91 -> V_96 , V_108 ) ;
return V_109 ;
}
static void F_43 ( struct V_30 * V_91 , unsigned char V_48 ,
unsigned char V_19 )
{
unsigned long V_108 ;
F_41 ( & V_91 -> V_96 , V_108 ) ;
F_8 ( V_91 -> V_106 , V_91 -> V_105 + V_91 -> V_103 ) ;
switch ( V_91 -> V_76 ) {
case V_77 :
if ( V_48 > 7 ) {
F_8 ( V_48 , V_91 -> V_105 + 8 ) ;
F_8 ( V_91 -> V_106 , V_91 -> V_105 + V_91 -> V_103 ) ;
F_8 ( V_19 , V_91 -> V_105 + 9 ) ;
break;
}
case V_79 :
F_8 ( V_19 , V_91 -> V_105 + V_48 ) ;
break;
default:
F_6 ( V_11 L_17 , V_91 -> V_76 ) ;
}
F_42 ( & V_91 -> V_96 , V_108 ) ;
}
static void F_44 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_30 * V_31 = (struct V_30 * ) V_111 -> V_114 ;
struct V_1 * V_2 = V_31 -> V_2 ;
char * V_115 = L_18 ;
if ( ( V_31 -> V_76 == V_79 ) &&
( V_2 -> V_116 == 'm' ) &&
( V_2 -> V_67 == 'A' ) ) {
switch ( V_2 -> V_42 ) {
case 3 :
V_115 = L_19 ;
break;
default:
V_115 = L_20 ;
break;
}
}
if ( ( V_31 -> V_76 == V_77 ) &&
( V_2 -> V_116 == 'm' ) &&
( V_2 -> V_67 == 'B' ) ) {
switch ( V_2 -> V_42 ) {
case 4 :
V_115 = L_21 ;
break;
case 176 :
V_115 = L_22 ;
break;
default:
V_115 = L_23 ;
break;
}
}
if ( ( V_31 -> V_76 == V_77 ) &&
( V_2 -> V_116 == 'm' ) &&
( V_2 -> V_67 == 'C' ) ) {
switch ( V_2 -> V_42 ) {
case 7 :
V_115 = L_24 ;
break;
default:
V_115 = L_25 ;
break;
}
}
F_45 ( V_113 , L_26 ) ;
F_45 ( V_113 , L_27 , V_115 ) ;
F_45 ( V_113 , L_28 , V_31 -> V_93 ) ;
F_45 ( V_113 , L_29 , V_31 -> V_117 -> V_93 ) ;
F_45 ( V_113 , L_30 , V_31 -> V_97 ) ;
F_45 ( V_113 , L_31 , V_31 -> V_98 ) ;
F_45 ( V_113 , L_32 , V_31 -> V_99 , V_31 -> V_100 ) ;
F_45 ( V_113 , L_33 ) ;
F_45 ( V_113 , L_30 , V_31 -> V_101 ) ;
F_45 ( V_113 , L_34 , V_31 -> V_102 ) ;
F_45 ( V_113 , L_35 ) ;
F_45 ( V_113 , L_36 ) ;
switch ( V_2 -> V_116 ) {
case 'm' :
F_45 ( V_113 , L_37 ) ;
break;
default:
F_45 ( V_113 , L_38 , V_2 -> V_116 ) ;
break;
}
F_45 ( V_113 , L_39 ) ;
switch ( V_2 -> V_67 ) {
case 'A' :
F_45 ( V_113 , L_40 ) ;
break;
case 'B' :
F_45 ( V_113 , L_41 ) ;
break;
case 'C' :
F_45 ( V_113 , L_42 ) ;
break;
default:
F_45 ( V_113 , L_38 , V_2 -> V_67 ) ;
break;
}
F_45 ( V_113 , L_43 ,
V_2 -> V_42 , V_2 -> V_42 ) ;
F_45 ( V_113 , L_44 ,
V_2 -> V_6 , V_2 -> V_6 + 2 ) ;
F_45 ( V_113 , L_45 , V_68 ) ;
F_45 ( V_113 , L_46 , V_70 ) ;
F_45 ( V_113 , L_47 , V_2 -> V_35 ) ;
F_45 ( V_113 , L_48 , V_2 -> V_46 ) ;
F_45 ( V_113 , L_49 , V_2 -> V_43 ) ;
}
static void T_1 F_46 ( struct V_73 * V_74 ,
struct V_30 * V_31 )
{
struct V_110 * V_111 ;
if ( ! F_47 ( V_74 , L_50 , & V_111 ) )
F_48 ( V_111 , V_31 , F_44 ) ;
}
static int T_1 F_49 ( struct V_30 * V_91 )
{
unsigned char V_118 ;
unsigned char V_119 ;
unsigned char V_120 ;
unsigned char V_121 = 0 ;
unsigned char V_122 ;
unsigned long V_108 ;
F_50 ( V_91 , F_51 ( 1 ) , 0x80 , 0x80 ) ;
F_50 ( V_91 , F_51 ( 2 ) , 0x20 , 0x20 ) ;
F_50 ( V_91 , F_51 ( 5 ) , 0x02 , 0x02 ) ;
switch ( V_91 -> V_76 ) {
case V_77 :
F_50 ( V_91 , F_51 ( 6 ) , 0x02 , 0x02 ) ;
F_50 ( V_91 , F_51 ( 3 ) , 0xf0 , 0xff ) ;
break;
case V_79 :
F_50 ( V_91 , F_51 ( 4 ) , 0x00 , 0x0c ) ;
break;
default:
F_6 ( V_11 L_51 , V_91 -> V_76 ) ;
return - V_65 ;
}
switch ( V_91 -> V_97 & 0x3ff ) {
case 0x130 :
V_91 -> V_97 = 0x530 ;
V_118 = 0x00 ;
break;
case 0x204 :
V_91 -> V_97 = 0x604 ;
V_118 = 0x03 ;
break;
case 0x280 :
V_91 -> V_97 = 0xe80 ;
V_118 = 0x01 ;
break;
case 0x340 :
V_91 -> V_97 = 0xf40 ;
V_118 = 0x02 ;
break;
default:
F_6 ( V_11 L_52 , V_91 -> V_97 ) ;
goto V_123;
}
F_50 ( V_91 , F_51 ( 1 ) , V_118 << 4 , 0x30 ) ;
V_123:
switch ( V_91 -> V_98 ) {
case 5 :
V_119 = 0x05 ;
break;
case 7 :
V_119 = 0x01 ;
break;
case 9 :
V_119 = 0x02 ;
break;
case 10 :
V_119 = 0x03 ;
break;
case 11 :
V_119 = 0x04 ;
break;
default:
F_6 ( V_11 L_53 , V_91 -> V_98 ) ;
goto V_124;
}
switch ( V_91 -> V_99 ) {
case 0 :
V_120 = 0x01 ;
break;
case 1 :
V_120 = 0x02 ;
break;
case 3 :
V_120 = 0x03 ;
break;
default:
F_6 ( V_11 L_54 , V_91 -> V_99 ) ;
goto V_124;
}
if ( V_91 -> V_99 == V_91 -> V_100 ) {
F_6 ( V_11 L_55 ) ;
return - V_12 ;
}
switch ( V_91 -> V_100 ) {
case 0 :
case 1 :
break;
default:
F_6 ( V_11 L_56 , V_91 -> V_100 ) ;
goto V_124;
}
V_120 |= 0x04 ;
F_41 ( & V_91 -> V_96 , V_108 ) ;
F_8 ( V_119 << 3 | V_120 , V_91 -> V_97 ) ;
F_42 ( & V_91 -> V_96 , V_108 ) ;
V_124:
if ( V_91 -> V_76 > V_125 ) {
switch ( V_91 -> V_101 ) {
case 0 :
case - 1 :
break;
case 0x300 :
V_121 = 0x03 ;
break;
case 0x310 :
V_121 = 0x02 ;
break;
case 0x320 :
V_121 = 0x01 ;
break;
case 0x330 :
V_121 = 0x00 ;
break;
default:
F_6 ( V_11 L_57 ,
V_91 -> V_101 ) ;
goto V_126;
}
switch ( V_91 -> V_102 ) {
case 5 :
V_122 = 0x02 ;
break;
case 7 :
V_122 = 0x03 ;
break;
case 9 :
V_122 = 0x00 ;
break;
case 10 :
V_122 = 0x01 ;
break;
default:
F_6 ( V_11 L_58 ,
V_91 -> V_102 ) ;
goto V_126;
}
F_50 ( V_91 , F_51 ( 6 ) ,
( V_91 -> V_101 <= 0 ) ? 0x00 :
0x80 | V_121 << 5 | V_122 << 3 ,
0xf8 ) ;
}
V_126:
return 0 ;
}
static int T_1 F_52 ( struct V_30 * V_91 )
{
unsigned char V_19 ;
V_91 -> V_127 = F_35 ( V_91 -> V_105 , V_91 -> V_95 ,
L_59 ) ;
if ( V_91 -> V_127 == NULL )
return - V_128 ;
V_19 = F_40 ( V_91 , F_51 ( 1 ) ) ;
if ( V_19 != 0xff && V_19 != F_2 ( V_91 -> V_105 + F_51 ( 1 ) ) )
if ( V_19 == F_40 ( V_91 , F_51 ( 1 ) ) )
return 0 ;
F_36 ( V_91 -> V_127 ) ;
V_91 -> V_127 = NULL ;
return - V_107 ;
}
static int T_1 F_53 ( struct V_73 * V_74 ,
struct V_30 * V_91 )
{
int V_20 , V_75 ;
for ( V_20 = V_79 ; V_20 <= V_77 ; V_20 ++ ) {
if ( ( V_75 = F_37 ( V_91 , V_20 ) ) < 0 )
return V_75 ;
V_75 = F_52 ( V_91 ) ;
if ( V_75 == 0 )
return 1 ;
}
return - V_107 ;
}
static int T_1 F_54 ( struct V_73 * V_74 ,
struct V_30 * V_31 )
{
unsigned char V_129 ;
int V_20 ;
struct V_1 * V_2 = & V_25 ;
V_31 -> V_2 = V_2 ;
F_55 ( & V_2 -> V_21 ) ;
V_129 = F_2 ( V_31 -> V_105 + 4 ) ;
V_2 -> V_6 = ( V_129 & 0x10 ) ? 0x344 : 0x354 ;
V_31 -> V_130 = F_35 ( V_2 -> V_6 , 3 , L_60 ) ;
if ( V_31 -> V_130 == NULL ) {
F_6 ( V_11 L_61 ,
V_2 -> V_6 , V_2 -> V_6 + 2 ) ;
return - V_128 ;
}
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ )
if ( F_10 ( V_2 , V_131 , - 1 , - 1 ) < 0 ) {
F_6 ( V_11 L_62 ) ;
return - V_132 ;
}
V_2 -> V_116 = F_10 ( V_2 , V_133 , - 1 , - 1 ) ;
V_2 -> V_67 = F_10 ( V_2 , V_133 , - 1 , - 1 ) ;
if ( V_2 -> V_116 < 0 || V_2 -> V_67 < 0 ) {
F_6 ( V_11 L_63 ,
V_2 -> V_6 ) ;
return - V_132 ;
}
V_2 -> V_42 = F_10 ( V_2 , V_134 , - 1 , - 1 ) ;
if ( V_2 -> V_42 < 0 ) {
F_6 ( V_11 L_64 ,
V_2 -> V_6 ) ;
return - V_132 ;
}
if ( F_10 ( V_2 , V_135 , - 1 , - 1 ) < 0 ||
F_10 ( V_2 , V_131 , V_131 , V_131 ) < 0 ||
F_10 ( V_2 , V_131 , V_131 , V_131 ) < 0 ) {
F_6 ( V_11 L_65 ) ;
return - V_132 ;
}
return 0 ;
}
static void F_56 ( struct V_73 * V_74 )
{
struct V_30 * V_31 = V_74 -> V_114 ;
F_36 ( V_31 -> V_130 ) ;
if ( V_31 -> V_2 )
V_31 -> V_2 -> V_6 = 0 ;
F_36 ( V_31 -> V_127 ) ;
}
static int T_1 F_57 ( struct V_73 * V_74 )
{
int error ;
struct V_30 * V_31 = V_74 -> V_114 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_140 * V_117 ;
struct V_141 * V_142 ;
if ( ! V_31 -> V_127 ) {
V_31 -> V_127 = F_35 ( V_31 -> V_105 ,
V_31 -> V_95 ,
L_66 ) ;
if ( V_31 -> V_127 == NULL ) {
F_6 ( V_11 L_67 ) ;
return - V_128 ;
}
}
error = F_54 ( V_74 , V_31 ) ;
if ( error < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11 L_68 ) ;
return - V_107 ;
}
V_31 -> V_97 = V_143 ;
V_31 -> V_101 = V_101 ;
V_31 -> V_98 = V_98 ;
V_31 -> V_102 = V_102 ;
V_31 -> V_99 = V_99 ;
V_31 -> V_100 = V_100 ;
F_46 ( V_74 , V_31 ) ;
error = F_49 ( V_31 ) ;
if ( error )
return error ;
error = F_59 ( V_74 , V_31 -> V_97 + 4 , - 1 ,
V_31 -> V_98 , V_31 -> V_99 , V_31 -> V_100 ,
V_144 , 0 , & V_137 ) ;
if ( error < 0 )
return error ;
error = F_60 ( V_137 , 0 , & V_117 ) ;
if ( error < 0 )
return error ;
error = F_61 ( V_137 ) ;
if ( error < 0 )
return error ;
error = F_62 ( V_137 , 0 , & V_139 ) ;
if ( error < 0 )
return error ;
V_31 -> V_117 = V_117 ;
error = F_29 ( V_74 , V_31 ) ;
if ( error < 0 )
return error ;
if ( V_31 -> V_2 -> V_116 == 'm' ) {
switch ( V_31 -> V_2 -> V_67 ) {
case 'A' :
sprintf ( V_74 -> V_145 ,
L_69 ) ;
break;
case 'B' :
sprintf ( V_74 -> V_145 ,
L_21 ) ;
break;
case 'C' :
sprintf ( V_74 -> V_145 ,
L_25 ) ;
break;
default:
sprintf ( V_74 -> V_145 ,
L_70 ) ;
F_6 ( V_146 L_71 ) ;
break;
}
} else {
F_6 ( V_146 L_72 ) ;
sprintf ( V_74 -> V_145 , L_73 ) ;
}
strcpy ( V_74 -> V_147 , L_50 ) ;
sprintf ( V_74 -> V_148 , L_74 ,
V_74 -> V_145 , V_31 -> V_93 , V_117 -> V_93 , V_31 -> V_97 + 4 ,
V_31 -> V_98 , V_31 -> V_99 , V_31 -> V_100 ) ;
if ( V_101 <= 0 || V_101 == V_149 )
V_142 = NULL ;
else {
error = F_63 ( V_74 , 0 , V_150 ,
V_101 , 0 , V_31 -> V_102 , V_151 ,
& V_142 ) ;
if ( error < 0 )
F_6 ( V_152 L_75 ,
V_101 ) ;
}
if ( V_153 > 0 && V_153 != V_149 ) {
struct V_154 * V_155 = NULL ;
struct V_156 * V_157 ;
if ( F_64 ( V_74 , V_153 , V_153 - 8 ,
2 , & V_155 , & V_157 ) < 0 )
F_6 ( V_152 L_76 ,
V_153 ) ;
}
error = F_27 ( V_31 ) ;
if ( error < 0 )
return error ;
return F_65 ( V_74 ) ;
}
static int T_1 F_66 ( struct V_158 * V_159 , unsigned int V_160 )
{
#ifdef F_39
if ( V_161 )
return 0 ;
if ( V_104 )
return 0 ;
#endif
return 1 ;
}
static int T_1 F_67 ( struct V_158 * V_159 , unsigned int V_160 )
{
static long V_162 [] = { 0x530 , 0xe80 , 0xf40 , 0x604 , - 1 } ;
static long V_163 [] = { 0x330 , 0x300 , 0x310 , 0x320 , - 1 } ;
static int V_164 [] = { 11 , 9 , 10 , 7 , - 1 } ;
static int V_165 [] = { 10 , 5 , 9 , 7 , - 1 } ;
static int V_166 [] = { 3 , 1 , 0 , - 1 } ;
static int V_167 [] [ 2 ] = { { 1 , - 1 } , { 0 , - 1 } , { - 1 , - 1 } ,
{ 0 , - 1 } } ;
int error ;
struct V_30 * V_31 ;
struct V_73 * V_74 ;
error = F_68 ( V_23 , V_168 , V_169 ,
sizeof( struct V_30 ) , & V_74 ) ;
if ( error < 0 )
return error ;
V_74 -> V_170 = F_56 ;
V_31 = V_74 -> V_114 ;
error = F_53 ( V_74 , V_31 ) ;
if ( error < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11 L_77 ) ;
return - V_107 ;
}
if ( V_143 == V_149 ) {
V_143 = F_34 ( V_162 , 4 ) ;
if ( V_143 < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11 L_78 ) ;
return - V_12 ;
}
}
if ( V_101 == V_149 ) {
V_101 = F_34 ( V_163 , 2 ) ;
if ( V_101 < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11
L_79 ) ;
return - V_12 ;
}
}
if ( V_98 == V_171 ) {
V_98 = F_69 ( V_164 ) ;
if ( V_98 < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11 L_80 ) ;
return - V_12 ;
}
}
if ( V_102 == V_171 ) {
V_102 = F_69 ( V_165 ) ;
if ( V_102 < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11
L_81 ) ;
return - V_12 ;
}
}
if ( V_99 == V_172 ) {
V_99 = F_70 ( V_166 ) ;
if ( V_99 < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11 L_82 ) ;
return - V_12 ;
}
}
if ( V_100 == V_172 ) {
V_100 = F_70 ( V_167 [ V_99 % 4 ] ) ;
if ( V_100 < 0 ) {
F_58 ( V_74 ) ;
F_6 ( V_11 L_83 ) ;
return - V_12 ;
}
}
F_71 ( V_74 , V_159 ) ;
error = F_57 ( V_74 ) ;
if ( error < 0 ) {
F_58 ( V_74 ) ;
return error ;
}
F_72 ( V_159 , V_74 ) ;
return 0 ;
}
static int T_2 F_73 ( struct V_158 * V_159 ,
unsigned int V_173 )
{
F_58 ( F_74 ( V_159 ) ) ;
F_72 ( V_159 , NULL ) ;
return 0 ;
}
static int T_1 F_75 ( struct V_30 * V_91 ,
struct V_174 * V_74 ,
const struct V_175 * V_176 )
{
struct V_177 * V_178 ;
int V_75 ;
struct V_177 * V_179 ;
struct V_177 * V_180 ;
V_178 = F_76 ( V_74 , V_176 -> V_181 [ 0 ] . V_168 , NULL ) ;
if ( V_178 == NULL )
return - V_12 ;
V_179 = F_76 ( V_74 , V_176 -> V_181 [ 1 ] . V_168 , NULL ) ;
if ( V_179 == NULL )
return - V_12 ;
V_180 = F_76 ( V_74 , V_176 -> V_181 [ 2 ] . V_168 , NULL ) ;
if ( V_180 == NULL )
return - V_12 ;
V_75 = F_77 ( V_178 ) ;
if ( V_75 < 0 ) {
F_6 ( V_11 L_84 , V_75 ) ;
return V_75 ;
}
V_75 = F_77 ( V_180 ) ;
if ( V_75 < 0 ) {
F_6 ( V_11 L_85 ,
V_75 ) ;
return V_75 ;
}
V_143 = F_78 ( V_178 , 1 ) ;
V_153 = F_78 ( V_178 , 2 ) + 8 ;
V_91 -> V_105 = F_78 ( V_180 , 0 ) - 1 ;
V_91 -> V_95 = F_79 ( V_180 , 0 ) + 1 ;
V_98 = F_80 ( V_178 , 0 ) ;
V_99 = F_81 ( V_178 , 0 ) ;
V_100 = F_81 ( V_178 , 1 ) ;
if ( V_101 > 0 ) {
V_75 = F_77 ( V_179 ) ;
if ( V_75 < 0 ) {
F_6 ( V_11 L_86 ) ;
V_101 = - 1 ;
return V_75 ;
}
V_101 = F_78 ( V_179 , 0 ) ;
V_102 = F_80 ( V_179 , 0 ) ;
}
return 0 ;
}
static int T_1 F_82 ( struct V_174 * V_182 ,
const struct V_175 * V_176 )
{
struct V_73 * V_74 ;
int V_75 ;
struct V_30 * V_31 ;
if ( V_161 )
return - V_12 ;
if ( ! V_104 )
return - V_107 ;
V_75 = F_68 ( V_23 , V_168 , V_169 ,
sizeof( struct V_30 ) , & V_74 ) ;
if ( V_75 < 0 )
return V_75 ;
V_74 -> V_170 = F_56 ;
V_31 = V_74 -> V_114 ;
V_75 = F_75 ( V_31 , V_182 , V_176 ) ;
if ( V_75 ) {
F_58 ( V_74 ) ;
return V_75 ;
}
V_75 = F_37 ( V_31 , V_77 ) ;
if ( V_75 ) {
F_58 ( V_74 ) ;
return V_75 ;
}
V_75 = F_52 ( V_31 ) ;
if ( V_75 ) {
F_6 ( V_11 L_87 ) ;
F_58 ( V_74 ) ;
return V_75 ;
}
F_71 ( V_74 , & V_182 -> V_74 -> V_173 ) ;
V_75 = F_57 ( V_74 ) ;
if ( V_75 < 0 ) {
F_58 ( V_74 ) ;
return V_75 ;
}
F_83 ( V_182 , V_74 ) ;
V_161 = 1 ;
return 0 ;
}
static void T_2 F_84 ( struct V_174 * V_182 )
{
F_58 ( F_85 ( V_182 ) ) ;
F_83 ( V_182 , NULL ) ;
V_161 = 0 ;
}
static int T_3 F_86 ( void )
{
#ifdef F_39
F_87 ( & V_183 ) ;
if ( V_161 )
return 0 ;
F_88 ( & V_183 ) ;
#endif
return F_89 ( & V_184 , 1 ) ;
}
static void T_4 F_90 ( void )
{
if ( ! V_161 ) {
F_91 ( & V_184 ) ;
return;
}
#ifdef F_39
F_88 ( & V_183 ) ;
#endif
}
