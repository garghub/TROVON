static unsigned char F_1 ( const unsigned char V_1 , struct V_2 * V_3 )
{
return ( V_1 & ~ V_3 -> V_3 ) ;
}
static struct V_2 * F_2 ( const unsigned char V_1 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
if ( V_1 & V_5 [ V_4 ] . V_3 ) {
return & V_5 [ V_4 ] ;
}
}
return NULL ;
}
static void F_4 ( void )
{
struct V_6 * V_7 = V_8 ;
F_5 ( F_6 ( L_1 ) ) ;
while ( NULL != V_7 ) {
V_7 -> V_9 ( ( const unsigned int ) V_10 ,
( const unsigned int ) V_11 ,
( const unsigned char ) V_12 ,
( const unsigned char ) V_13 ) ;
V_7 = V_7 -> V_14 ;
}
}
int F_7 ( enum V_15 V_16 , const char * V_17 )
{
int V_18 = 0 ;
int V_19 = 0 ;
unsigned long int V_20 ;
unsigned long int V_21 ;
struct V_2 * V_22 ;
unsigned char V_23 ;
unsigned long V_24 ;
int V_25 = 0 ;
( void ) F_8 () ;
F_5 ( F_6 ( L_2 , V_16 , V_17 ) ) ;
if ( ( V_16 >= V_26 ) || ( V_16 < 0 ) ) {
F_6 ( V_27 L_3
L_4 ,
V_16 ,
V_17 ) ;
return - V_28 ;
}
F_9 ( V_24 ) ;
if ( V_29 [ V_16 ] . V_30 ) {
F_6 ( V_27 L_5
L_6 ,
V_29 [ V_16 ] . V_31 ,
V_17 ,
V_29 [ V_16 ] . V_32 ) ;
V_25 = - V_33 ;
goto exit;
}
V_23 = V_29 [ V_16 ] . V_1 ;
while ( NULL != ( V_22 = F_2 ( V_23 ) ) ) {
unsigned int V_34 = 0 ;
switch ( V_22 -> V_3 ) {
case V_35 :
V_34 = V_29 [ V_16 ] . V_35 ;
break;
case V_36 :
V_34 = V_29 [ V_16 ] . V_36 ;
break;
case V_37 :
V_34 = V_29 [ V_16 ] . V_37 ;
break;
case V_38 :
V_34 = V_29 [ V_16 ] . V_38 ;
break;
case V_39 :
V_34 = V_29 [ V_16 ] . V_39 ;
break;
case V_40 :
V_34 = V_29 [ V_16 ] . V_40 ;
break;
default:
F_10 ( 1 ) ;
}
if ( V_34 & V_22 -> V_30 ) {
F_6 ( V_41 L_7
L_8 ,
V_22 -> V_31 , V_29 [ V_16 ] . V_31 ) ;
V_25 = - V_33 ;
goto exit;
}
V_23 = F_1 ( V_23 , V_22 ) ;
}
if ( ( ( V_29 [ V_16 ] . V_42 & V_10 ) !=
V_29 [ V_16 ] . V_42 ) ||
( ( V_29 [ V_16 ] . V_43 & V_11 ) !=
V_29 [ V_16 ] . V_43 ) ||
( ( V_29 [ V_16 ] . V_44 & V_13 ) !=
V_29 [ V_16 ] . V_44 ) ) {
F_6 ( V_27 L_9
L_10 , V_16 ) ;
V_25 = - V_33 ;
goto exit;
}
V_20 = V_45 ;
V_21 = V_46 ;
V_18 = 1 ;
switch ( V_16 )
{
case V_47 :
case V_48 :
V_18 = 0 ;
break;
case V_49 :
V_19 = 1 ;
F_11 ( V_21 , V_50 , V_51 , V_52 ) ;
break;
case V_53 :
F_11 ( V_20 , V_54 , V_55 , V_56 ) ;
break;
case V_57 :
F_11 ( V_20 , V_54 , V_58 , V_56 ) ;
V_19 = 1 ;
F_11 ( V_21 , V_50 , V_59 , V_52 ) ;
break;
case V_60 :
V_19 = 1 ;
F_11 ( V_21 , V_50 , V_51 , V_61 ) ;
break;
case V_62 :
F_11 ( V_20 , V_54 , V_58 , V_56 ) ;
V_19 = 1 ;
F_11 ( V_21 , V_50 , V_59 , V_61 ) ;
break;
case V_63 :
F_11 ( V_20 , V_54 , V_64 , V_56 ) ;
break;
case V_65 :
F_11 ( V_20 , V_54 , V_66 , V_56 ) ;
break;
case V_67 :
F_11 ( V_20 , V_54 , V_68 , V_56 ) ;
break;
case V_69 :
F_11 ( V_20 , V_54 , V_70 , V_56 ) ;
break;
case V_71 :
F_11 ( V_20 , V_54 , V_68 , V_56 ) ;
F_11 ( V_20 , V_54 , V_72 , V_56 ) ;
break;
case V_73 :
F_11 ( V_20 , V_54 , V_74 , V_56 ) ;
break;
case V_75 :
F_11 ( V_20 , V_54 , V_76 , V_56 ) ;
break;
case V_77 :
F_11 ( V_20 , V_54 , V_74 , V_56 ) ;
F_11 ( V_20 , V_54 , V_78 , V_56 ) ;
break;
case V_79 :
F_11 ( V_20 , V_54 , V_80 , V_56 ) ;
break;
case V_81 :
case V_82 :
V_18 = 0 ;
break;
case V_83 :
F_11 ( V_20 , V_54 , V_84 , V_56 ) ;
break;
case V_85 :
F_11 ( V_20 , V_54 , V_86 , V_56 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
V_18 = 0 ;
break;
default:
F_6 ( V_41 L_3
L_4 ,
V_16 , V_17 ) ;
V_25 = - V_33 ;
goto exit;
}
V_23 = V_29 [ V_16 ] . V_1 ;
while ( NULL != ( V_22 = F_2 ( V_23 ) ) ) {
unsigned int V_34 = 0 ;
switch ( V_22 -> V_3 ) {
case V_35 :
V_34 = V_29 [ V_16 ] . V_35 ;
break;
case V_36 :
V_34 = V_29 [ V_16 ] . V_36 ;
break;
case V_37 :
V_34 = V_29 [ V_16 ] . V_37 ;
break;
case V_38 :
V_34 = V_29 [ V_16 ] . V_38 ;
break;
case V_39 :
V_34 = V_29 [ V_16 ] . V_39 ;
break;
case V_40 :
V_34 = V_29 [ V_16 ] . V_40 ;
break;
default:
F_10 ( 1 ) ;
}
V_22 -> V_30 |= V_34 ;
V_23 = F_1 ( V_23 , V_22 ) ;
}
V_29 [ V_16 ] . V_30 = 1 ;
V_29 [ V_16 ] . V_32 = ( char * ) V_17 ;
if ( V_18 ) {
volatile int V_4 ;
V_45 = V_20 ;
* V_54 = V_45 ;
for( V_4 = 6 ; V_4 > 0 ; V_4 -- )
F_12 () ;
}
if ( V_19 ) {
V_46 = V_21 ;
* V_50 = V_46 ;
}
F_5 ( F_6 ( V_93 L_11
L_12 ,
V_10 , V_11 , V_13 ) ) ;
F_5 ( F_6 ( V_93
L_13 ,
V_29 [ V_16 ] . V_42 ,
V_29 [ V_16 ] . V_43 ,
V_29 [ V_16 ] . V_44 ) ) ;
V_10 &= ~ V_29 [ V_16 ] . V_42 ;
V_11 &= ~ V_29 [ V_16 ] . V_43 ;
V_13 &= ~ V_29 [ V_16 ] . V_44 ;
F_5 ( F_6 ( V_93 L_14
L_12 ,
V_10 , V_11 , V_13 ) ) ;
exit:
F_13 ( V_24 ) ;
if ( V_25 == 0 )
F_4 () ;
return V_25 ;
}
void F_14 ( enum V_15 V_16 )
{
struct V_2 * V_22 ;
unsigned char V_23 ;
unsigned long V_24 ;
( void ) F_8 () ;
if ( ( V_16 >= V_26 ) || ( V_16 < 0 ) ) {
F_6 ( V_27 L_15 ,
V_16 ) ;
return;
}
F_9 ( V_24 ) ;
if ( ! V_29 [ V_16 ] . V_30 ) {
F_6 ( V_27 L_16 ,
V_16 ) ;
F_13 ( V_24 ) ;
return;
}
V_23 = V_29 [ V_16 ] . V_1 ;
while ( NULL != ( V_22 = F_2 ( V_23 ) ) ) {
unsigned int V_34 = 0 ;
switch ( V_22 -> V_3 ) {
case V_35 :
V_34 = V_29 [ V_16 ] . V_35 ;
break;
case V_36 :
V_34 = V_29 [ V_16 ] . V_36 ;
break;
case V_37 :
V_34 = V_29 [ V_16 ] . V_37 ;
break;
case V_38 :
V_34 = V_29 [ V_16 ] . V_38 ;
break;
case V_39 :
V_34 = V_29 [ V_16 ] . V_39 ;
break;
case V_40 :
V_34 = V_29 [ V_16 ] . V_40 ;
break;
default:
F_10 ( 1 ) ;
}
if ( ( V_22 -> V_30 & V_34 ) != V_34 )
F_10 ( 1 ) ;
V_22 -> V_30 = V_22 -> V_30 & ~ V_34 ;
V_23 = F_1 ( V_23 , V_22 ) ;
}
V_29 [ V_16 ] . V_30 = 0 ;
V_29 [ V_16 ] . V_32 = NULL ;
F_5 ( F_6 ( L_17 ,
V_10 , V_11 , V_13 ) ) ;
F_5 ( F_6 ( L_18 ,
V_29 [ V_16 ] . V_42 ,
V_29 [ V_16 ] . V_43 ,
V_29 [ V_16 ] . V_44 ) ) ;
V_10 |= V_29 [ V_16 ] . V_42 ;
V_11 |= V_29 [ V_16 ] . V_43 ;
V_13 |= V_29 [ V_16 ] . V_44 ;
F_5 ( F_6 ( L_19 ,
V_10 , V_11 , V_13 ) ) ;
F_13 ( V_24 ) ;
F_4 () ;
}
static inline unsigned int F_15 ( const unsigned V_94 )
{
if ( V_94 >= 32 ) {
return 0xffffffff ;
}
return ( 1 << V_94 ) - 1 ;
}
int F_16 ( const enum V_15 V_16 ,
const char V_95 ,
const unsigned V_96 ,
const unsigned V_94 )
{
unsigned int V_4 ;
unsigned int V_97 = 0 ;
unsigned int V_98 ;
unsigned long int V_24 ;
enum V_15 * V_99 ;
( void ) F_8 () ;
F_5 ( F_6 ( L_20 ,
V_16 , V_95 , V_96 , V_94 ) ) ;
if ( ! ( ( V_96 <= V_94 ) &&
( ( ( ( V_95 == 'a' ) || ( V_95 == 'b' ) ) && ( V_94 < 8 ) ) ||
( ( V_95 == 'g' ) && ( V_94 < 32 ) ) ) ) ) {
return - V_28 ;
}
V_97 = F_15 ( V_94 + 1 ) ;
V_98 = F_15 ( V_96 ) ;
V_97 &= ~ V_98 ;
F_5 ( F_6 ( L_21 ,
V_95 , V_96 , V_94 , V_97 ) ) ;
F_9 ( V_24 ) ;
switch ( V_95 ) {
case 'a' :
if ( ( V_12 & V_97 ) != V_97 ) {
F_13 ( V_24 ) ;
return - V_33 ;
}
V_99 = V_100 ;
V_12 &= ~ V_97 ;
break;
case 'b' :
if ( ( V_13 & V_97 ) != V_97 ) {
F_13 ( V_24 ) ;
return - V_33 ;
}
V_99 = V_101 ;
V_13 &= ~ V_97 ;
break;
case 'g' :
if ( ( ( V_10 & V_97 ) != V_97 ) ||
( ( V_11 & V_97 ) != V_97 ) ) {
F_13 ( V_24 ) ;
return - V_33 ;
}
V_99 = V_102 ;
V_10 &= ~ V_97 ;
V_11 &= ~ V_97 ;
break;
default:
F_13 ( V_24 ) ;
return - V_28 ;
}
for ( V_4 = V_96 ; V_4 <= V_94 ; V_4 ++ ) {
V_99 [ V_4 ] = V_16 ;
}
F_13 ( V_24 ) ;
F_4 () ;
return 0 ;
}
int F_17 ( const enum V_15 V_16 ,
const char V_95 ,
const unsigned V_96 ,
const unsigned V_94 )
{
unsigned int V_4 ;
unsigned int V_97 = 0 ;
unsigned int V_98 ;
unsigned long int V_24 ;
enum V_15 * V_99 ;
( void ) F_8 () ;
if ( ! ( ( V_96 <= V_94 ) &&
( ( ( ( V_95 == 'a' ) || ( V_95 == 'b' ) ) && ( V_94 < 8 ) ) ||
( ( V_95 == 'g' ) && ( V_94 < 32 ) ) ) ) ) {
return - V_28 ;
}
V_97 = F_15 ( V_94 + 1 ) ;
V_98 = F_15 ( V_96 ) ;
V_97 &= ~ V_98 ;
F_5 ( F_6 ( L_22 ,
V_95 , V_96 , V_94 , V_97 ) ) ;
F_9 ( V_24 ) ;
switch ( V_95 ) {
case 'a' :
if ( ( ~ V_12 & V_97 ) != V_97 ) {
F_13 ( V_24 ) ;
F_6 ( V_27 L_23 ) ;
}
V_99 = V_100 ;
break;
case 'b' :
if ( ( ~ V_13 & V_97 ) != V_97 ) {
F_13 ( V_24 ) ;
F_6 ( V_27 L_23 ) ;
}
V_99 = V_101 ;
break;
case 'g' :
if ( ( ( ~ V_10 & V_97 ) != V_97 ) ||
( ( ~ V_11 & V_97 ) != V_97 ) ) {
F_13 ( V_24 ) ;
F_6 ( V_27 L_23 ) ;
}
V_99 = V_102 ;
break;
default:
V_99 = NULL ;
}
for ( V_4 = V_96 ; V_4 <= V_94 ; V_4 ++ ) {
if ( V_99 [ V_4 ] != V_16 ) {
F_6 ( V_27 L_24 ) ;
}
}
switch ( V_95 ) {
case 'a' :
V_12 |= V_97 ;
break;
case 'b' :
V_13 |= V_97 ;
break;
case 'g' :
V_10 |= V_97 ;
V_11 |= V_97 ;
break;
}
for ( V_4 = V_96 ; V_4 <= V_94 ; V_4 ++ ) {
V_99 [ V_4 ] = V_103 ;
}
F_13 ( V_24 ) ;
F_4 () ;
return 0 ;
}
int F_18 ( void (* V_9)( const unsigned int V_104 ,
const unsigned int V_105 ,
const unsigned char V_106 ,
const unsigned char V_107 ) )
{
struct V_6 * V_7 ;
( void ) F_8 () ;
if ( NULL == V_9 ) {
return - V_28 ;
}
V_7 = F_19 ( sizeof( * V_7 ) , V_108 ) ;
if ( ! V_7 ) {
return - V_109 ;
}
V_7 -> V_9 = V_9 ;
V_7 -> V_14 = V_8 ;
V_8 = V_7 ;
V_7 -> V_9 ( ( const unsigned int ) V_10 ,
( const unsigned int ) V_11 ,
( const unsigned char ) V_12 ,
( const unsigned char ) V_13 ) ;
return 0 ;
}
void F_20 ( void (* V_9)( const unsigned int V_104 ,
const unsigned int V_105 ,
const unsigned char V_106 ,
const unsigned char V_107 ) )
{
struct V_6 * V_7 = V_8 , * V_110 = NULL ;
( void ) F_8 () ;
while ( ( NULL != V_7 ) && ( V_7 -> V_9 != V_9 ) ) {
V_110 = V_7 ;
V_7 = V_7 -> V_14 ;
}
if ( NULL != V_7 ) {
if ( NULL != V_110 ) {
V_110 -> V_14 = V_7 -> V_14 ;
} else {
V_8 = V_7 -> V_14 ;
}
F_21 ( V_7 ) ;
return;
}
F_6 ( V_111 L_25 , V_9 ) ;
}
static int F_8 ( void )
{
static int V_112 = 1 ;
int V_4 ;
if ( ! V_112 ) {
return 0 ;
}
V_112 = 0 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
V_100 [ V_4 ] = V_103 ;
V_101 [ V_4 ] = V_103 ;
V_102 [ V_4 ] = V_103 ;
}
for (; V_4 < 32 ; V_4 ++ ) {
V_102 [ V_4 ] = V_103 ;
}
return 0 ;
}
