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
static int F_27 ( struct V_30 * V_31 )
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
static int F_29 ( struct V_73 * V_74 ,
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
static int F_34 ( struct V_30 * V_87 ,
unsigned short V_76 )
{
static int V_88 [] = { 7 , 7 , 10 , 10 , 2 , 2 , 2 } ;
V_87 -> V_76 = V_76 ;
strcpy ( V_87 -> V_89 , V_90 [ V_76 ] ) ;
V_87 -> V_91 = V_88 [ V_76 ] ;
F_35 ( & V_87 -> V_92 ) ;
V_87 -> V_93 = - 1 ;
V_87 -> V_94 = - 1 ;
V_87 -> V_95 = - 1 ;
V_87 -> V_96 = - 1 ;
V_87 -> V_97 = - 1 ;
V_87 -> V_98 = - 1 ;
V_87 -> V_99 = 3 ;
#ifdef F_36
if ( V_100 && V_87 -> V_101 )
V_87 -> V_101 |= 0xc00 ;
else
#endif
V_87 -> V_101 = 0xf8c ;
switch ( V_76 ) {
case V_79 :
V_87 -> V_102 = 0xe3 ;
break;
case V_77 :
V_87 -> V_102 = 0xe5 ;
break;
default:
F_6 ( V_11 L_16 , V_76 ) ;
return - V_103 ;
}
return 0 ;
}
static unsigned char F_37 ( struct V_30 * V_87 ,
unsigned char V_48 )
{
unsigned long V_104 ;
unsigned char V_105 = 0xff ;
F_38 ( & V_87 -> V_92 , V_104 ) ;
F_8 ( V_87 -> V_102 , V_87 -> V_101 + V_87 -> V_99 ) ;
switch ( V_87 -> V_76 ) {
case V_77 :
if ( V_48 > 7 ) {
F_8 ( V_48 , V_87 -> V_101 + 8 ) ;
F_8 ( V_87 -> V_102 , V_87 -> V_101 + V_87 -> V_99 ) ;
V_105 = F_2 ( V_87 -> V_101 + 9 ) ;
break;
}
case V_79 :
V_105 = F_2 ( V_87 -> V_101 + V_48 ) ;
break;
default:
F_6 ( V_11 L_16 , V_87 -> V_76 ) ;
}
F_39 ( & V_87 -> V_92 , V_104 ) ;
return V_105 ;
}
static void F_40 ( struct V_30 * V_87 , unsigned char V_48 ,
unsigned char V_19 )
{
unsigned long V_104 ;
F_38 ( & V_87 -> V_92 , V_104 ) ;
F_8 ( V_87 -> V_102 , V_87 -> V_101 + V_87 -> V_99 ) ;
switch ( V_87 -> V_76 ) {
case V_77 :
if ( V_48 > 7 ) {
F_8 ( V_48 , V_87 -> V_101 + 8 ) ;
F_8 ( V_87 -> V_102 , V_87 -> V_101 + V_87 -> V_99 ) ;
F_8 ( V_19 , V_87 -> V_101 + 9 ) ;
break;
}
case V_79 :
F_8 ( V_19 , V_87 -> V_101 + V_48 ) ;
break;
default:
F_6 ( V_11 L_16 , V_87 -> V_76 ) ;
}
F_39 ( & V_87 -> V_92 , V_104 ) ;
}
static void F_41 ( struct V_106 * V_107 ,
struct V_108 * V_109 )
{
struct V_30 * V_31 = (struct V_30 * ) V_107 -> V_110 ;
struct V_1 * V_2 = V_31 -> V_2 ;
char * V_111 = L_17 ;
if ( ( V_31 -> V_76 == V_79 ) &&
( V_2 -> V_112 == 'm' ) &&
( V_2 -> V_67 == 'A' ) ) {
switch ( V_2 -> V_42 ) {
case 3 :
V_111 = L_18 ;
break;
default:
V_111 = L_19 ;
break;
}
}
if ( ( V_31 -> V_76 == V_77 ) &&
( V_2 -> V_112 == 'm' ) &&
( V_2 -> V_67 == 'B' ) ) {
switch ( V_2 -> V_42 ) {
case 4 :
V_111 = L_20 ;
break;
case 176 :
V_111 = L_21 ;
break;
default:
V_111 = L_22 ;
break;
}
}
if ( ( V_31 -> V_76 == V_77 ) &&
( V_2 -> V_112 == 'm' ) &&
( V_2 -> V_67 == 'C' ) ) {
switch ( V_2 -> V_42 ) {
case 7 :
V_111 = L_23 ;
break;
default:
V_111 = L_24 ;
break;
}
}
F_42 ( V_109 , L_25 ) ;
F_42 ( V_109 , L_26 , V_111 ) ;
F_42 ( V_109 , L_27 , V_31 -> V_89 ) ;
F_42 ( V_109 , L_28 , V_31 -> V_113 -> V_89 ) ;
F_42 ( V_109 , L_29 , V_31 -> V_93 ) ;
F_42 ( V_109 , L_30 , V_31 -> V_94 ) ;
F_42 ( V_109 , L_31 , V_31 -> V_95 , V_31 -> V_96 ) ;
F_42 ( V_109 , L_32 ) ;
F_42 ( V_109 , L_29 , V_31 -> V_97 ) ;
F_42 ( V_109 , L_33 , V_31 -> V_98 ) ;
F_42 ( V_109 , L_34 ) ;
F_42 ( V_109 , L_35 ) ;
switch ( V_2 -> V_112 ) {
case 'm' :
F_42 ( V_109 , L_36 ) ;
break;
default:
F_42 ( V_109 , L_37 , V_2 -> V_112 ) ;
break;
}
F_42 ( V_109 , L_38 ) ;
switch ( V_2 -> V_67 ) {
case 'A' :
F_42 ( V_109 , L_39 ) ;
break;
case 'B' :
F_42 ( V_109 , L_40 ) ;
break;
case 'C' :
F_42 ( V_109 , L_41 ) ;
break;
default:
F_42 ( V_109 , L_37 , V_2 -> V_67 ) ;
break;
}
F_42 ( V_109 , L_42 ,
V_2 -> V_42 , V_2 -> V_42 ) ;
F_42 ( V_109 , L_43 ,
V_2 -> V_6 , V_2 -> V_6 + 2 ) ;
F_42 ( V_109 , L_44 , V_68 ) ;
F_42 ( V_109 , L_45 , V_70 ) ;
F_42 ( V_109 , L_46 , V_2 -> V_35 ) ;
F_42 ( V_109 , L_47 , V_2 -> V_46 ) ;
F_42 ( V_109 , L_48 , V_2 -> V_43 ) ;
}
static void F_43 ( struct V_73 * V_74 ,
struct V_30 * V_31 )
{
struct V_106 * V_107 ;
if ( ! F_44 ( V_74 , L_49 , & V_107 ) )
F_45 ( V_107 , V_31 , F_41 ) ;
}
static int F_46 ( struct V_30 * V_87 )
{
unsigned char V_114 ;
unsigned char V_115 ;
unsigned char V_116 ;
unsigned char V_117 = 0 ;
unsigned char V_118 ;
unsigned long V_104 ;
F_47 ( V_87 , F_48 ( 1 ) , 0x80 , 0x80 ) ;
F_47 ( V_87 , F_48 ( 2 ) , 0x20 , 0x20 ) ;
F_47 ( V_87 , F_48 ( 5 ) , 0x02 , 0x02 ) ;
switch ( V_87 -> V_76 ) {
case V_77 :
F_47 ( V_87 , F_48 ( 6 ) , 0x02 , 0x02 ) ;
F_47 ( V_87 , F_48 ( 3 ) , 0xf0 , 0xff ) ;
break;
case V_79 :
F_47 ( V_87 , F_48 ( 4 ) , 0x00 , 0x0c ) ;
break;
default:
F_6 ( V_11 L_50 , V_87 -> V_76 ) ;
return - V_65 ;
}
switch ( V_87 -> V_93 & 0x3ff ) {
case 0x130 :
V_87 -> V_93 = 0x530 ;
V_114 = 0x00 ;
break;
case 0x204 :
V_87 -> V_93 = 0x604 ;
V_114 = 0x03 ;
break;
case 0x280 :
V_87 -> V_93 = 0xe80 ;
V_114 = 0x01 ;
break;
case 0x340 :
V_87 -> V_93 = 0xf40 ;
V_114 = 0x02 ;
break;
default:
F_6 ( V_11 L_51 , V_87 -> V_93 ) ;
goto V_119;
}
F_47 ( V_87 , F_48 ( 1 ) , V_114 << 4 , 0x30 ) ;
V_119:
switch ( V_87 -> V_94 ) {
case 5 :
V_115 = 0x05 ;
break;
case 7 :
V_115 = 0x01 ;
break;
case 9 :
V_115 = 0x02 ;
break;
case 10 :
V_115 = 0x03 ;
break;
case 11 :
V_115 = 0x04 ;
break;
default:
F_6 ( V_11 L_52 , V_87 -> V_94 ) ;
goto V_120;
}
switch ( V_87 -> V_95 ) {
case 0 :
V_116 = 0x01 ;
break;
case 1 :
V_116 = 0x02 ;
break;
case 3 :
V_116 = 0x03 ;
break;
default:
F_6 ( V_11 L_53 , V_87 -> V_95 ) ;
goto V_120;
}
if ( V_87 -> V_95 == V_87 -> V_96 ) {
F_6 ( V_11 L_54 ) ;
return - V_12 ;
}
switch ( V_87 -> V_96 ) {
case 0 :
case 1 :
break;
default:
F_6 ( V_11 L_55 , V_87 -> V_96 ) ;
goto V_120;
}
V_116 |= 0x04 ;
F_38 ( & V_87 -> V_92 , V_104 ) ;
F_8 ( V_115 << 3 | V_116 , V_87 -> V_93 ) ;
F_39 ( & V_87 -> V_92 , V_104 ) ;
V_120:
if ( V_87 -> V_76 > V_121 ) {
switch ( V_87 -> V_97 ) {
case 0 :
case - 1 :
break;
case 0x300 :
V_117 = 0x03 ;
break;
case 0x310 :
V_117 = 0x02 ;
break;
case 0x320 :
V_117 = 0x01 ;
break;
case 0x330 :
V_117 = 0x00 ;
break;
default:
F_6 ( V_11 L_56 ,
V_87 -> V_97 ) ;
goto V_122;
}
switch ( V_87 -> V_98 ) {
case 5 :
V_118 = 0x02 ;
break;
case 7 :
V_118 = 0x03 ;
break;
case 9 :
V_118 = 0x00 ;
break;
case 10 :
V_118 = 0x01 ;
break;
default:
F_6 ( V_11 L_57 ,
V_87 -> V_98 ) ;
goto V_122;
}
F_47 ( V_87 , F_48 ( 6 ) ,
( V_87 -> V_97 <= 0 ) ? 0x00 :
0x80 | V_117 << 5 | V_118 << 3 ,
0xf8 ) ;
}
V_122:
return 0 ;
}
static int F_49 ( struct V_30 * V_87 )
{
unsigned char V_19 ;
V_87 -> V_123 = F_50 ( V_87 -> V_101 , V_87 -> V_91 ,
L_58 ) ;
if ( V_87 -> V_123 == NULL )
return - V_124 ;
V_19 = F_37 ( V_87 , F_48 ( 1 ) ) ;
if ( V_19 != 0xff && V_19 != F_2 ( V_87 -> V_101 + F_48 ( 1 ) ) )
if ( V_19 == F_37 ( V_87 , F_48 ( 1 ) ) )
return 0 ;
F_51 ( V_87 -> V_123 ) ;
V_87 -> V_123 = NULL ;
return - V_103 ;
}
static int F_52 ( struct V_73 * V_74 ,
struct V_30 * V_87 )
{
int V_20 , V_75 ;
for ( V_20 = V_79 ; V_20 <= V_77 ; V_20 ++ ) {
if ( ( V_75 = F_34 ( V_87 , V_20 ) ) < 0 )
return V_75 ;
V_75 = F_49 ( V_87 ) ;
if ( V_75 == 0 )
return 1 ;
}
return - V_103 ;
}
static int F_53 ( struct V_73 * V_74 ,
struct V_30 * V_31 )
{
unsigned char V_125 ;
int V_20 ;
struct V_1 * V_2 = & V_25 ;
V_31 -> V_2 = V_2 ;
F_54 ( & V_2 -> V_21 ) ;
V_125 = F_2 ( V_31 -> V_101 + 4 ) ;
V_2 -> V_6 = ( V_125 & 0x10 ) ? 0x344 : 0x354 ;
V_31 -> V_126 = F_50 ( V_2 -> V_6 , 3 , L_59 ) ;
if ( V_31 -> V_126 == NULL ) {
F_6 ( V_11 L_60 ,
V_2 -> V_6 , V_2 -> V_6 + 2 ) ;
return - V_124 ;
}
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ )
if ( F_10 ( V_2 , V_127 , - 1 , - 1 ) < 0 ) {
F_6 ( V_11 L_61 ) ;
return - V_128 ;
}
V_2 -> V_112 = F_10 ( V_2 , V_129 , - 1 , - 1 ) ;
V_2 -> V_67 = F_10 ( V_2 , V_129 , - 1 , - 1 ) ;
if ( V_2 -> V_112 < 0 || V_2 -> V_67 < 0 ) {
F_6 ( V_11 L_62 ,
V_2 -> V_6 ) ;
return - V_128 ;
}
V_2 -> V_42 = F_10 ( V_2 , V_130 , - 1 , - 1 ) ;
if ( V_2 -> V_42 < 0 ) {
F_6 ( V_11 L_63 ,
V_2 -> V_6 ) ;
return - V_128 ;
}
if ( F_10 ( V_2 , V_131 , - 1 , - 1 ) < 0 ||
F_10 ( V_2 , V_127 , V_127 , V_127 ) < 0 ||
F_10 ( V_2 , V_127 , V_127 , V_127 ) < 0 ) {
F_6 ( V_11 L_64 ) ;
return - V_128 ;
}
return 0 ;
}
static void F_55 ( struct V_73 * V_74 )
{
struct V_30 * V_31 = V_74 -> V_110 ;
F_51 ( V_31 -> V_126 ) ;
if ( V_31 -> V_2 )
V_31 -> V_2 -> V_6 = 0 ;
F_51 ( V_31 -> V_123 ) ;
}
static int F_56 ( struct V_73 * V_74 )
{
int error ;
struct V_30 * V_31 = V_74 -> V_110 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_136 * V_113 ;
struct V_137 * V_138 ;
if ( ! V_31 -> V_123 ) {
V_31 -> V_123 = F_50 ( V_31 -> V_101 ,
V_31 -> V_91 ,
L_65 ) ;
if ( V_31 -> V_123 == NULL ) {
F_6 ( V_11 L_66 ) ;
return - V_124 ;
}
}
error = F_53 ( V_74 , V_31 ) ;
if ( error < 0 ) {
F_6 ( V_11 L_67 ) ;
return - V_103 ;
}
V_31 -> V_93 = V_139 ;
V_31 -> V_97 = V_97 ;
V_31 -> V_94 = V_94 ;
V_31 -> V_98 = V_98 ;
V_31 -> V_95 = V_95 ;
V_31 -> V_96 = V_96 ;
F_43 ( V_74 , V_31 ) ;
error = F_46 ( V_31 ) ;
if ( error )
return error ;
error = F_57 ( V_74 , V_31 -> V_93 + 4 , - 1 ,
V_31 -> V_94 , V_31 -> V_95 , V_31 -> V_96 ,
V_140 , 0 , & V_133 ) ;
if ( error < 0 )
return error ;
error = F_58 ( V_133 , 0 , & V_113 ) ;
if ( error < 0 )
return error ;
error = F_59 ( V_133 ) ;
if ( error < 0 )
return error ;
error = F_60 ( V_133 , 0 , & V_135 ) ;
if ( error < 0 )
return error ;
V_31 -> V_113 = V_113 ;
error = F_29 ( V_74 , V_31 ) ;
if ( error < 0 )
return error ;
if ( V_31 -> V_2 -> V_112 == 'm' ) {
switch ( V_31 -> V_2 -> V_67 ) {
case 'A' :
sprintf ( V_74 -> V_141 ,
L_68 ) ;
break;
case 'B' :
sprintf ( V_74 -> V_141 ,
L_20 ) ;
break;
case 'C' :
sprintf ( V_74 -> V_141 ,
L_24 ) ;
break;
default:
sprintf ( V_74 -> V_141 ,
L_69 ) ;
F_6 ( V_142 L_70 ) ;
break;
}
} else {
F_6 ( V_142 L_71 ) ;
sprintf ( V_74 -> V_141 , L_72 ) ;
}
strcpy ( V_74 -> V_143 , L_49 ) ;
sprintf ( V_74 -> V_144 , L_73 ,
V_74 -> V_141 , V_31 -> V_89 , V_113 -> V_89 , V_31 -> V_93 + 4 ,
V_31 -> V_94 , V_31 -> V_95 , V_31 -> V_96 ) ;
if ( V_97 <= 0 || V_97 == V_145 )
V_138 = NULL ;
else {
error = F_61 ( V_74 , 0 , V_146 ,
V_97 , 0 , V_31 -> V_98 , & V_138 ) ;
if ( error < 0 )
F_6 ( V_147 L_74 ,
V_97 ) ;
}
if ( V_148 > 0 && V_148 != V_145 ) {
struct V_149 * V_150 = NULL ;
struct V_151 * V_152 ;
if ( F_62 ( V_74 , V_148 , V_148 - 8 ,
2 , & V_150 , & V_152 ) < 0 )
F_6 ( V_147 L_75 ,
V_148 ) ;
}
error = F_27 ( V_31 ) ;
if ( error < 0 )
return error ;
return F_63 ( V_74 ) ;
}
static int F_64 ( struct V_153 * V_154 , unsigned int V_155 )
{
#ifdef F_36
if ( V_156 )
return 0 ;
if ( V_100 )
return 0 ;
#endif
return 1 ;
}
static int F_65 ( struct V_153 * V_154 , unsigned int V_155 )
{
static long V_157 [] = { 0x530 , 0xe80 , 0xf40 , 0x604 , - 1 } ;
static long V_158 [] = { 0x330 , 0x300 , 0x310 , 0x320 , - 1 } ;
static int V_159 [] = { 11 , 9 , 10 , 7 , - 1 } ;
static int V_160 [] = { 10 , 5 , 9 , 7 , - 1 } ;
static int V_161 [] = { 3 , 1 , 0 , - 1 } ;
static int V_162 [] [ 2 ] = { { 1 , - 1 } , { 0 , - 1 } , { - 1 , - 1 } ,
{ 0 , - 1 } } ;
int error ;
struct V_30 * V_31 ;
struct V_73 * V_74 ;
error = F_66 ( V_23 , V_163 , V_164 ,
sizeof( struct V_30 ) , & V_74 ) ;
if ( error < 0 )
return error ;
V_74 -> V_165 = F_55 ;
V_31 = V_74 -> V_110 ;
error = F_52 ( V_74 , V_31 ) ;
if ( error < 0 ) {
F_67 ( V_74 ) ;
F_6 ( V_11 L_76 ) ;
return - V_103 ;
}
if ( V_139 == V_145 ) {
V_139 = F_68 ( V_157 , 4 ) ;
if ( V_139 < 0 ) {
F_67 ( V_74 ) ;
F_6 ( V_11 L_77 ) ;
return - V_12 ;
}
}
if ( V_97 == V_145 ) {
V_97 = F_68 ( V_158 , 2 ) ;
if ( V_97 < 0 ) {
F_67 ( V_74 ) ;
F_6 ( V_11
L_78 ) ;
return - V_12 ;
}
}
if ( V_94 == V_166 ) {
V_94 = F_69 ( V_159 ) ;
if ( V_94 < 0 ) {
F_67 ( V_74 ) ;
F_6 ( V_11 L_79 ) ;
return - V_12 ;
}
}
if ( V_98 == V_166 ) {
V_98 = F_69 ( V_160 ) ;
if ( V_98 < 0 ) {
F_67 ( V_74 ) ;
F_6 ( V_11
L_80 ) ;
return - V_12 ;
}
}
if ( V_95 == V_167 ) {
V_95 = F_70 ( V_161 ) ;
if ( V_95 < 0 ) {
F_67 ( V_74 ) ;
F_6 ( V_11 L_81 ) ;
return - V_12 ;
}
}
if ( V_96 == V_167 ) {
V_96 = F_70 ( V_162 [ V_95 % 4 ] ) ;
if ( V_96 < 0 ) {
F_67 ( V_74 ) ;
F_6 ( V_11 L_82 ) ;
return - V_12 ;
}
}
F_71 ( V_74 , V_154 ) ;
error = F_56 ( V_74 ) ;
if ( error < 0 ) {
F_67 ( V_74 ) ;
return error ;
}
F_72 ( V_154 , V_74 ) ;
return 0 ;
}
static int F_73 ( struct V_153 * V_154 ,
unsigned int V_168 )
{
F_67 ( F_74 ( V_154 ) ) ;
F_72 ( V_154 , NULL ) ;
return 0 ;
}
static int F_75 ( struct V_30 * V_87 ,
struct V_169 * V_74 ,
const struct V_170 * V_171 )
{
struct V_172 * V_173 ;
int V_75 ;
struct V_172 * V_174 ;
struct V_172 * V_175 ;
V_173 = F_76 ( V_74 , V_171 -> V_176 [ 0 ] . V_163 , NULL ) ;
if ( V_173 == NULL )
return - V_12 ;
V_174 = F_76 ( V_74 , V_171 -> V_176 [ 1 ] . V_163 , NULL ) ;
if ( V_174 == NULL )
return - V_12 ;
V_175 = F_76 ( V_74 , V_171 -> V_176 [ 2 ] . V_163 , NULL ) ;
if ( V_175 == NULL )
return - V_12 ;
V_75 = F_77 ( V_173 ) ;
if ( V_75 < 0 ) {
F_6 ( V_11 L_83 , V_75 ) ;
return V_75 ;
}
V_75 = F_77 ( V_175 ) ;
if ( V_75 < 0 ) {
F_6 ( V_11 L_84 ,
V_75 ) ;
return V_75 ;
}
V_139 = F_78 ( V_173 , 1 ) ;
V_148 = F_78 ( V_173 , 2 ) + 8 ;
V_87 -> V_101 = F_78 ( V_175 , 0 ) - 1 ;
V_87 -> V_91 = F_79 ( V_175 , 0 ) + 1 ;
V_94 = F_80 ( V_173 , 0 ) ;
V_95 = F_81 ( V_173 , 0 ) ;
V_96 = F_81 ( V_173 , 1 ) ;
if ( V_97 > 0 ) {
V_75 = F_77 ( V_174 ) ;
if ( V_75 < 0 ) {
F_6 ( V_11 L_85 ) ;
V_97 = - 1 ;
return V_75 ;
}
V_97 = F_78 ( V_174 , 0 ) ;
V_98 = F_80 ( V_174 , 0 ) ;
}
return 0 ;
}
static int F_82 ( struct V_169 * V_177 ,
const struct V_170 * V_171 )
{
struct V_73 * V_74 ;
int V_75 ;
struct V_30 * V_31 ;
if ( V_156 )
return - V_12 ;
if ( ! V_100 )
return - V_103 ;
V_75 = F_66 ( V_23 , V_163 , V_164 ,
sizeof( struct V_30 ) , & V_74 ) ;
if ( V_75 < 0 )
return V_75 ;
V_74 -> V_165 = F_55 ;
V_31 = V_74 -> V_110 ;
V_75 = F_75 ( V_31 , V_177 , V_171 ) ;
if ( V_75 ) {
F_67 ( V_74 ) ;
return V_75 ;
}
V_75 = F_34 ( V_31 , V_77 ) ;
if ( V_75 ) {
F_67 ( V_74 ) ;
return V_75 ;
}
V_75 = F_49 ( V_31 ) ;
if ( V_75 ) {
F_6 ( V_11 L_86 ) ;
F_67 ( V_74 ) ;
return V_75 ;
}
F_71 ( V_74 , & V_177 -> V_74 -> V_168 ) ;
V_75 = F_56 ( V_74 ) ;
if ( V_75 < 0 ) {
F_67 ( V_74 ) ;
return V_75 ;
}
F_83 ( V_177 , V_74 ) ;
V_156 = 1 ;
return 0 ;
}
static void F_84 ( struct V_169 * V_177 )
{
F_67 ( F_85 ( V_177 ) ) ;
F_83 ( V_177 , NULL ) ;
V_156 = 0 ;
}
static int T_1 F_86 ( void )
{
#ifdef F_36
F_87 ( & V_178 ) ;
if ( V_156 )
return 0 ;
F_88 ( & V_178 ) ;
#endif
return F_89 ( & V_179 , 1 ) ;
}
static void T_2 F_90 ( void )
{
if ( ! V_156 ) {
F_91 ( & V_179 ) ;
return;
}
#ifdef F_36
F_88 ( & V_178 ) ;
#endif
}
