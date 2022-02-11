static void F_1 ( int V_1 )
{
if ( F_2 () )
F_3 ( V_1 ) ;
else
F_4 ( F_5 ( V_1 ) ) ;
}
static void F_6 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
if ( ! V_3 -> V_7 -> V_8 )
return;
F_8 ( & V_6 -> V_9 ) ;
if ( ! V_6 -> V_10 )
V_3 -> V_7 -> V_8 ( V_3 , V_4 ) ;
F_9 ( & V_6 -> V_9 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_11 ( V_12 ) ;
struct V_5 * V_6 =
F_12 ( V_14 , struct V_5 , V_15 ) ;
F_8 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_10 ) {
V_6 -> V_10 = false ;
if ( ! ( V_6 -> V_16 & V_17 ) )
V_6 -> V_3 . V_7 -> V_8 ( & V_6 -> V_3 , 0 ) ;
}
F_9 ( & V_6 -> V_9 ) ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
if ( ! V_3 -> V_7 -> V_8 )
return;
F_14 ( & V_6 -> V_15 ) ;
F_8 ( & V_6 -> V_9 ) ;
if ( ! V_6 -> V_10 && ! ( V_6 -> V_16 & V_17 ) )
V_3 -> V_7 -> V_8 ( V_3 , 1 ) ;
V_6 -> V_10 = true ;
F_15 ( & V_6 -> V_15 , V_18 * V_19 ) ;
F_9 ( & V_6 -> V_9 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
unsigned int V_20 ;
V_20 = V_6 -> V_20 . V_21 < V_3 -> V_22 ? V_6 -> V_20 . V_21 & ( V_3 -> V_23 - 1 )
: V_3 -> V_22 - 1 ;
if ( V_6 -> V_20 . V_24 & 1 )
V_20 += V_3 -> V_23 ;
if ( V_6 -> V_20 . V_24 & 2 )
V_20 += V_3 -> V_22 ;
V_3 -> V_7 -> V_25 ( V_3 , V_26 | V_20 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
V_6 -> V_20 . V_21 = 0 ;
V_6 -> V_20 . V_24 = 0 ;
F_16 ( V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 , char V_27 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
if ( V_6 -> V_20 . V_21 < V_3 -> V_22 ) {
if ( V_3 -> V_28 )
V_27 = V_3 -> V_28 [ ( unsigned char ) V_27 ] ;
V_3 -> V_7 -> V_29 ( V_3 , V_27 ) ;
V_6 -> V_20 . V_21 ++ ;
}
if ( V_6 -> V_20 . V_21 == V_3 -> V_22 )
F_16 ( V_3 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
int V_30 ;
F_17 ( V_3 ) ;
if ( V_3 -> V_7 -> V_31 )
V_3 -> V_7 -> V_31 ( V_3 ) ;
else
for ( V_30 = 0 ; V_30 < F_20 ( 2 , V_3 -> V_32 ) * V_3 -> V_23 ; V_30 ++ )
V_3 -> V_7 -> V_29 ( V_3 , ' ' ) ;
F_17 ( V_3 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
V_3 -> V_7 -> V_25 ( V_3 , V_33 ) ;
V_6 -> V_20 . V_21 = 0 ;
V_6 -> V_20 . V_24 = 0 ;
F_1 ( 15 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
void (* F_23)( struct V_2 * V_3 , int V_34 );
struct V_5 * V_6 = F_7 ( V_3 ) ;
T_1 V_35 ;
if ( V_3 -> V_36 != 4 && V_3 -> V_36 != 8 )
return - V_37 ;
V_6 -> V_16 = ( ( V_3 -> V_32 > 1 ) ? V_38 : 0 ) | V_39 |
V_40 | V_41 ;
F_1 ( 20 ) ;
V_35 = V_42 | V_43 ;
if ( V_3 -> V_36 == 4 ) {
V_35 >>= 4 ;
F_23 = V_3 -> V_7 -> V_44 ;
} else {
F_23 = V_3 -> V_7 -> V_25 ;
}
F_23 ( V_3 , V_35 ) ;
F_1 ( 10 ) ;
F_23 ( V_3 , V_35 ) ;
F_1 ( 10 ) ;
F_23 ( V_3 , V_35 ) ;
F_1 ( 10 ) ;
if ( V_3 -> V_36 == 4 ) {
V_3 -> V_7 -> V_44 ( V_3 , V_42 >> 4 ) ;
F_1 ( 10 ) ;
}
V_3 -> V_7 -> V_25 ( V_3 ,
V_42 |
( ( V_3 -> V_36 == 8 ) ? V_43 : 0 ) |
( ( V_6 -> V_16 & V_45 ) ? V_46 : 0 ) |
( ( V_6 -> V_16 & V_38 ) ? V_47 : 0 ) ) ;
F_1 ( 10 ) ;
V_3 -> V_7 -> V_25 ( V_3 , V_48 ) ;
F_1 ( 10 ) ;
V_3 -> V_7 -> V_25 ( V_3 ,
V_48 |
( ( V_6 -> V_16 & V_39 ) ? V_49 : 0 ) |
( ( V_6 -> V_16 & V_40 ) ? V_50 : 0 ) |
( ( V_6 -> V_16 & V_41 ) ? V_51 : 0 ) ) ;
F_6 ( V_3 , ( V_6 -> V_16 & V_17 ) ? 1 : 0 ) ;
F_1 ( 10 ) ;
V_3 -> V_7 -> V_25 ( V_3 , V_52 | V_53 ) ;
F_21 ( V_3 ) ;
return 0 ;
}
static inline int F_24 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
int V_54 = 0 ;
char * V_55 = V_6 -> V_56 . V_57 + 2 ;
int V_58 = V_6 -> V_16 ;
switch ( * V_55 ) {
case 'D' :
V_6 -> V_16 |= V_39 ;
V_54 = 1 ;
break;
case 'd' :
V_6 -> V_16 &= ~ V_39 ;
V_54 = 1 ;
break;
case 'C' :
V_6 -> V_16 |= V_40 ;
V_54 = 1 ;
break;
case 'c' :
V_6 -> V_16 &= ~ V_40 ;
V_54 = 1 ;
break;
case 'B' :
V_6 -> V_16 |= V_41 ;
V_54 = 1 ;
break;
case 'b' :
V_6 -> V_16 &= ~ V_41 ;
V_54 = 1 ;
break;
case '+' :
V_6 -> V_16 |= V_17 ;
V_54 = 1 ;
break;
case '-' :
V_6 -> V_16 &= ~ V_17 ;
V_54 = 1 ;
break;
case '*' :
F_13 ( V_3 ) ;
V_54 = 1 ;
break;
case 'f' :
V_6 -> V_16 &= ~ V_45 ;
V_54 = 1 ;
break;
case 'F' :
V_6 -> V_16 |= V_45 ;
V_54 = 1 ;
break;
case 'n' :
V_6 -> V_16 &= ~ V_38 ;
V_54 = 1 ;
break;
case 'N' :
V_6 -> V_16 |= V_38 ;
break;
case 'l' :
if ( V_6 -> V_20 . V_21 > 0 ) {
if ( V_6 -> V_20 . V_21 < V_3 -> V_22 )
V_3 -> V_7 -> V_25 ( V_3 , V_59 ) ;
V_6 -> V_20 . V_21 -- ;
}
V_54 = 1 ;
break;
case 'r' :
if ( V_6 -> V_20 . V_21 < V_3 -> V_60 ) {
if ( V_6 -> V_20 . V_21 < ( V_3 -> V_22 - 1 ) )
V_3 -> V_7 -> V_25 ( V_3 ,
V_59 | V_61 ) ;
V_6 -> V_20 . V_21 ++ ;
}
V_54 = 1 ;
break;
case 'L' :
V_3 -> V_7 -> V_25 ( V_3 , V_59 | V_62 ) ;
V_54 = 1 ;
break;
case 'R' :
V_3 -> V_7 -> V_25 ( V_3 ,
V_59 | V_62 |
V_61 ) ;
V_54 = 1 ;
break;
case 'k' : {
int V_21 ;
for ( V_21 = V_6 -> V_20 . V_21 ; V_21 < V_3 -> V_22 ; V_21 ++ )
V_3 -> V_7 -> V_29 ( V_3 , ' ' ) ;
F_16 ( V_3 ) ;
V_54 = 1 ;
break;
}
case 'I' :
F_22 ( V_3 ) ;
V_54 = 1 ;
break;
case 'G' : {
unsigned char V_63 [ 8 ] ;
unsigned char V_64 ;
int V_65 ;
int V_66 ;
char V_67 ;
int V_20 ;
if ( ! strchr ( V_55 , ';' ) )
break;
V_55 ++ ;
V_64 = * ( V_55 ++ ) - '0' ;
if ( V_64 > 7 ) {
V_54 = 1 ;
break;
}
V_65 = 0 ;
V_66 = 0 ;
V_67 = 0 ;
while ( * V_55 && V_65 < 8 ) {
V_66 ^= 4 ;
if ( * V_55 >= '0' && * V_55 <= '9' ) {
V_67 |= ( * V_55 - '0' ) << V_66 ;
} else if ( * V_55 >= 'A' && * V_55 <= 'Z' ) {
V_67 |= ( * V_55 - 'A' + 10 ) << V_66 ;
} else if ( * V_55 >= 'a' && * V_55 <= 'z' ) {
V_67 |= ( * V_55 - 'a' + 10 ) << V_66 ;
} else {
V_55 ++ ;
continue;
}
if ( V_66 == 0 ) {
V_63 [ V_65 ++ ] = V_67 ;
V_67 = 0 ;
}
V_55 ++ ;
}
V_3 -> V_7 -> V_25 ( V_3 , V_68 | ( V_64 * 8 ) ) ;
for ( V_20 = 0 ; V_20 < V_65 ; V_20 ++ )
V_3 -> V_7 -> V_29 ( V_3 , V_63 [ V_20 ] ) ;
F_16 ( V_3 ) ;
V_54 = 1 ;
break;
}
case 'x' :
case 'y' :
if ( ! strchr ( V_55 , ';' ) )
break;
while ( * V_55 ) {
if ( * V_55 == 'x' ) {
V_55 ++ ;
if ( F_25 ( V_55 , 10 , & V_6 -> V_20 . V_21 ) < 0 )
break;
} else if ( * V_55 == 'y' ) {
V_55 ++ ;
if ( F_25 ( V_55 , 10 , & V_6 -> V_20 . V_24 ) < 0 )
break;
} else {
break;
}
}
F_16 ( V_3 ) ;
V_54 = 1 ;
break;
}
if ( V_58 == V_6 -> V_16 )
return V_54 ;
if ( ( V_58 ^ V_6 -> V_16 ) &
( V_41 | V_40 | V_39 ) )
V_3 -> V_7 -> V_25 ( V_3 ,
V_48 |
( ( V_6 -> V_16 & V_39 ) ? V_49 : 0 ) |
( ( V_6 -> V_16 & V_40 ) ? V_50 : 0 ) |
( ( V_6 -> V_16 & V_41 ) ? V_51 : 0 ) ) ;
else if ( ( V_58 ^ V_6 -> V_16 ) & ( V_45 | V_38 ) )
V_3 -> V_7 -> V_25 ( V_3 ,
V_42 |
( ( V_3 -> V_36 == 8 ) ? V_43 : 0 ) |
( ( V_6 -> V_16 & V_45 ) ? V_46 : 0 ) |
( ( V_6 -> V_16 & V_38 ) ? V_47 : 0 ) ) ;
else if ( ( V_58 ^ V_6 -> V_16 ) & V_17 )
F_6 ( V_3 , ! ! ( V_6 -> V_16 & V_17 ) ) ;
return V_54 ;
}
static void F_26 ( struct V_2 * V_3 , char V_27 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
if ( ( V_27 != '\n' ) && V_6 -> V_56 . V_69 >= 0 ) {
V_6 -> V_56 . V_57 [ V_6 -> V_56 . V_69 ++ ] = V_27 ;
V_6 -> V_56 . V_57 [ V_6 -> V_56 . V_69 ] = 0 ;
} else {
V_6 -> V_56 . V_69 = - 1 ;
switch ( V_27 ) {
case V_70 :
V_6 -> V_56 . V_69 = 0 ;
V_6 -> V_56 . V_57 [ V_6 -> V_56 . V_69 ] = 0 ;
break;
case '\b' :
if ( V_6 -> V_20 . V_21 > 0 ) {
if ( V_6 -> V_20 . V_21 < V_3 -> V_22 )
V_3 -> V_7 -> V_25 ( V_3 , V_59 ) ;
V_6 -> V_20 . V_21 -- ;
}
V_3 -> V_7 -> V_29 ( V_3 , ' ' ) ;
V_3 -> V_7 -> V_25 ( V_3 , V_59 ) ;
break;
case '\014' :
F_19 ( V_3 ) ;
break;
case '\n' :
for (; V_6 -> V_20 . V_21 < V_3 -> V_22 ; V_6 -> V_20 . V_21 ++ )
V_3 -> V_7 -> V_29 ( V_3 , ' ' ) ;
V_6 -> V_20 . V_21 = 0 ;
V_6 -> V_20 . V_24 = ( V_6 -> V_20 . V_24 + 1 ) % V_3 -> V_32 ;
F_16 ( V_3 ) ;
break;
case '\r' :
V_6 -> V_20 . V_21 = 0 ;
F_16 ( V_3 ) ;
break;
case '\t' :
F_18 ( V_3 , ' ' ) ;
break;
default:
F_18 ( V_3 , V_27 ) ;
break;
}
}
if ( V_6 -> V_56 . V_69 >= 2 ) {
int V_54 = 0 ;
if ( ! strcmp ( V_6 -> V_56 . V_57 , L_1 ) ) {
F_19 ( V_3 ) ;
V_54 = 1 ;
} else if ( ! strcmp ( V_6 -> V_56 . V_57 , L_2 ) ) {
F_17 ( V_3 ) ;
V_54 = 1 ;
}
else if ( ( V_6 -> V_56 . V_69 >= 3 ) &&
( V_6 -> V_56 . V_57 [ 0 ] == '[' ) &&
( V_6 -> V_56 . V_57 [ 1 ] == 'L' ) ) {
V_54 = F_24 ( V_3 ) ;
}
if ( V_54 || ( V_6 -> V_56 . V_69 >= V_71 ) )
V_6 -> V_56 . V_69 = - 1 ;
}
}
static T_2 F_27 ( struct V_72 * V_72 , const char T_3 * V_57 ,
T_4 V_73 , T_5 * V_74 )
{
const char T_3 * V_75 = V_57 ;
char V_27 ;
for (; V_73 -- > 0 ; ( * V_74 ) ++ , V_75 ++ ) {
if ( ! F_2 () && ( ( ( V_73 + 1 ) & 0x1f ) == 0 ) )
F_28 () ;
if ( F_29 ( V_27 , V_75 ) )
return - V_76 ;
F_26 ( V_77 , V_27 ) ;
}
return V_75 - V_57 ;
}
static int F_30 ( struct V_78 * V_78 , struct V_72 * V_72 )
{
struct V_5 * V_6 = F_7 ( V_77 ) ;
int V_79 ;
V_79 = - V_80 ;
if ( ! F_31 ( & V_81 ) )
goto V_82;
V_79 = - V_83 ;
if ( V_72 -> V_84 & V_85 )
goto V_82;
if ( V_6 -> V_86 ) {
F_21 ( & V_6 -> V_3 ) ;
V_6 -> V_86 = false ;
}
return F_32 ( V_78 , V_72 ) ;
V_82:
F_33 ( & V_81 ) ;
return V_79 ;
}
static int F_34 ( struct V_78 * V_78 , struct V_72 * V_72 )
{
F_33 ( & V_81 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , const char * V_87 )
{
const char * V_75 = V_87 ;
int V_73 = strlen ( V_87 ) ;
for (; V_73 -- > 0 ; V_75 ++ ) {
if ( ! F_2 () && ( ( ( V_73 + 1 ) & 0x1f ) == 0 ) )
F_28 () ;
F_26 ( V_3 , * V_75 ) ;
}
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
int V_79 ;
if ( V_3 -> V_7 -> V_8 ) {
F_37 ( & V_6 -> V_9 ) ;
F_38 ( & V_6 -> V_15 , F_10 ) ;
}
V_79 = F_22 ( V_3 ) ;
if ( V_79 )
return V_79 ;
#ifdef F_39
#ifdef F_40
F_35 ( V_3 , L_3 F_40 ) ;
#endif
#else
F_35 ( V_3 , L_4 V_88 L_5 ) ;
#endif
V_6 -> V_86 = true ;
F_17 ( V_3 ) ;
return 0 ;
}
struct V_2 * F_41 ( unsigned int V_89 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
V_6 = F_42 ( sizeof( * V_6 ) + V_89 , V_90 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_56 . V_69 = - 1 ;
V_3 = & V_6 -> V_3 ;
V_3 -> V_36 = 8 ;
V_3 -> V_22 = V_91 ;
V_3 -> V_23 = V_92 ;
V_3 -> V_93 = V_6 -> V_93 ;
return V_3 ;
}
static int F_43 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
struct V_2 * V_3 = V_77 ;
switch ( V_96 ) {
case V_98 :
F_35 ( V_3 ,
L_6 ) ;
break;
case V_99 :
F_35 ( V_3 , L_7 ) ;
break;
case V_100 :
F_35 ( V_3 , L_8 ) ;
break;
default:
break;
}
return V_101 ;
}
int F_44 ( struct V_2 * V_3 )
{
int V_79 ;
V_79 = F_36 ( V_3 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_45 ( & V_102 ) ;
if ( V_79 )
return V_79 ;
V_77 = V_3 ;
F_46 ( & V_103 ) ;
return 0 ;
}
int F_47 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
F_48 ( & V_103 ) ;
F_35 ( V_3 , L_9 ) ;
F_49 ( & V_102 ) ;
V_77 = NULL ;
if ( V_3 -> V_7 -> V_8 ) {
F_14 ( & V_6 -> V_15 ) ;
V_6 -> V_3 . V_7 -> V_8 ( & V_6 -> V_3 , 0 ) ;
}
return 0 ;
}
