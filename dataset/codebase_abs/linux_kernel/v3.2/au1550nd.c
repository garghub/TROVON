static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = F_2 ( V_4 -> V_7 ) ;
F_3 () ;
return V_6 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_8 , V_4 -> V_9 ) ;
F_3 () ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = ( T_1 ) F_7 ( F_8 ( V_4 -> V_7 ) ) ;
F_3 () ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_10 ( F_11 ( ( V_10 ) V_8 ) , V_4 -> V_9 ) ;
F_3 () ;
}
static V_10 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 V_6 = F_8 ( V_4 -> V_7 ) ;
F_3 () ;
return V_6 ;
}
static void F_13 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_5 ( V_11 [ V_13 ] , V_4 -> V_9 ) ;
F_3 () ;
}
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_11 [ V_13 ] = F_2 ( V_4 -> V_7 ) ;
F_3 () ;
}
}
static int F_15 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_11 [ V_13 ] != F_2 ( V_4 -> V_7 ) )
return - V_14 ;
F_3 () ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_15 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_10 ( V_15 [ V_13 ] , V_4 -> V_9 ) ;
F_3 () ;
}
}
static void F_17 ( struct V_1 * V_2 , T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_15 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_15 [ V_13 ] = F_8 ( V_4 -> V_7 ) ;
F_3 () ;
}
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_15 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_15 [ V_13 ] != F_8 ( V_4 -> V_7 ) )
return - V_14 ;
F_3 () ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , int V_16 )
{
register struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_16 ) {
case V_17 :
V_4 -> V_9 = V_18 + V_19 ;
break;
case V_20 :
V_4 -> V_9 = V_18 + V_21 ;
break;
case V_22 :
V_4 -> V_9 = V_18 + V_23 ;
break;
case V_24 :
V_4 -> V_9 = V_18 + V_21 ;
F_20 ( 1 ) ;
break;
case V_25 :
F_21 ( ( 1 << ( 4 + V_26 ) ) , V_27 ) ;
break;
case V_28 :
F_21 ( 0 , V_27 ) ;
break;
}
V_4 -> V_7 = V_4 -> V_9 ;
F_3 () ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_6 = ( F_23 ( V_29 ) & 0x1 ) ? 1 : 0 ;
F_3 () ;
return V_6 ;
}
static void F_24 ( struct V_1 * V_2 , int V_30 )
{
}
static void F_25 ( struct V_1 * V_2 , unsigned V_31 , int V_32 , int V_33 )
{
register struct V_3 * V_4 = V_2 -> V_5 ;
int V_34 = 0 , V_13 ;
T_2 V_35 ;
F_19 ( V_2 , V_17 ) ;
if ( V_31 == V_36 ) {
int V_37 ;
if ( V_32 >= V_2 -> V_38 ) {
V_32 -= V_2 -> V_38 ;
V_37 = V_39 ;
} else if ( V_32 < 256 ) {
V_37 = V_40 ;
} else {
V_32 -= 256 ;
V_37 = V_41 ;
}
F_26 ( V_2 , V_37 ) ;
}
F_26 ( V_2 , V_31 ) ;
F_19 ( V_2 , V_20 ) ;
if ( V_32 != - 1 || V_33 != - 1 ) {
F_19 ( V_2 , V_22 ) ;
if ( V_32 != - 1 ) {
if ( V_4 -> V_42 & V_43 )
V_32 >>= 1 ;
F_26 ( V_2 , V_32 ) ;
}
if ( V_33 != - 1 ) {
F_26 ( V_2 , ( V_44 ) ( V_33 & 0xff ) ) ;
if ( V_31 == V_40 ||
V_31 == V_41 ||
V_31 == V_39 ) {
V_34 = 1 ;
F_27 ( V_35 ) ;
F_19 ( V_2 , V_25 ) ;
}
F_26 ( V_2 , ( V_44 ) ( V_33 >> 8 ) ) ;
if ( V_4 -> V_45 > ( 32 << 20 ) )
F_26 ( V_2 , ( V_44 ) ( ( V_33 >> 16 ) & 0x0f ) ) ;
}
F_19 ( V_2 , V_24 ) ;
}
switch ( V_31 ) {
case V_46 :
case V_47 :
case V_48 :
case V_36 :
case V_49 :
return;
case V_50 :
break;
case V_40 :
case V_41 :
case V_39 :
if ( F_28 ( ! V_34 ) )
break;
F_29 ( 100 ) ;
for ( V_13 = V_4 -> V_51 ; ! V_4 -> V_52 ( V_2 ) && V_13 > 0 ; -- V_13 )
F_20 ( 1 ) ;
F_19 ( V_2 , V_28 ) ;
F_30 ( V_35 ) ;
return;
}
F_29 ( 100 ) ;
while( ! V_4 -> V_52 ( V_2 ) ) ;
}
static int T_3 F_31 ( void )
{
struct V_3 * V_4 ;
V_10 V_53 = 0 ;
int V_54 ;
T_4 V_55 ;
T_4 V_56 ;
V_57 = F_32 ( sizeof( struct V_1 ) + sizeof( struct V_3 ) , V_58 ) ;
if ( ! V_57 ) {
F_33 ( L_1 ) ;
return - V_59 ;
}
V_4 = (struct V_3 * ) ( & V_57 [ 1 ] ) ;
V_57 -> V_5 = V_4 ;
V_57 -> V_60 = V_61 ;
F_21 ( 0 , V_27 ) ;
#ifdef F_34
F_35 ( 206 ) ;
V_53 = ( F_23 ( V_29 ) & ( 0x7 << 1 ) ) | ( ( F_36 ( V_62 ) >> 6 ) & 0x1 ) ;
switch ( V_53 ) {
case 0 :
case 2 :
case 8 :
case 0xC :
case 0xD :
V_63 = 0 ;
break;
case 1 :
case 9 :
case 3 :
case 0xE :
case 0xF :
V_63 = 1 ;
break;
default:
F_33 ( L_2 ) ;
V_54 = - V_64 ;
goto V_65;
}
#endif
#ifdef F_37
if ( V_26 == 0 ) {
F_21 ( F_37 , V_66 ) ;
F_21 ( V_67 , V_68 ) ;
F_21 ( V_69 , V_70 ) ;
}
if ( V_26 == 1 ) {
F_21 ( F_37 , V_71 ) ;
F_21 ( V_67 , V_72 ) ;
F_21 ( V_69 , V_73 ) ;
}
if ( V_26 == 2 ) {
F_21 ( F_37 , V_74 ) ;
F_21 ( V_67 , V_75 ) ;
F_21 ( V_69 , V_76 ) ;
}
if ( V_26 == 3 ) {
F_21 ( F_37 , V_77 ) ;
F_21 ( V_67 , V_78 ) ;
F_21 ( V_69 , V_79 ) ;
}
#endif
V_55 = 0x00000000 ;
if ( ( ( F_23 ( V_66 ) & 0x7 ) == 0x5 ) && ( V_26 == 0 ) )
V_55 = F_23 ( V_70 ) ;
else if ( ( ( F_23 ( V_71 ) & 0x7 ) == 0x5 ) && ( V_26 == 1 ) )
V_55 = F_23 ( V_73 ) ;
else if ( ( ( F_23 ( V_74 ) & 0x7 ) == 0x5 ) && ( V_26 == 2 ) )
V_55 = F_23 ( V_76 ) ;
else if ( ( ( F_23 ( V_77 ) & 0x7 ) == 0x5 ) && ( V_26 == 3 ) )
V_55 = F_23 ( V_79 ) ;
if ( V_55 == 0x00000000 ) {
F_33 ( L_3 ) ;
F_38 ( V_57 ) ;
return 1 ;
}
V_56 = ( V_55 << 4 ) & 0xFFFC0000 ;
V_18 = F_39 ( V_56 , 0x1000 ) ;
if ( V_26 == 0 )
V_63 = F_23 ( V_66 ) & ( 1 << 22 ) ;
if ( V_26 == 1 )
V_63 = F_23 ( V_71 ) & ( 1 << 22 ) ;
if ( V_26 == 2 )
V_63 = F_23 ( V_74 ) & ( 1 << 22 ) ;
if ( V_26 == 3 )
V_63 = F_23 ( V_77 ) & ( 1 << 22 ) ;
V_4 -> V_52 = F_22 ;
V_4 -> V_80 = F_24 ;
V_4 -> V_81 = F_25 ;
V_4 -> V_51 = 30 ;
V_4 -> V_82 . V_83 = V_84 ;
V_4 -> V_42 = V_85 ;
if ( ! V_63 )
V_4 -> V_42 |= V_43 ;
V_4 -> V_86 = ( ! V_63 ) ? F_6 : F_1 ;
F_26 = ( ! V_63 ) ? F_9 : F_4 ;
V_4 -> V_87 = F_12 ;
V_4 -> V_88 = ( ! V_63 ) ? F_16 : F_13 ;
V_4 -> V_89 = ( ! V_63 ) ? F_17 : F_14 ;
V_4 -> V_90 = ( ! V_63 ) ? F_18 : F_15 ;
if ( F_40 ( V_57 , 1 ) ) {
V_54 = - V_91 ;
goto V_92;
}
F_41 ( V_57 , V_93 ,
F_42 ( V_93 ) ) ;
return 0 ;
V_92:
F_43 ( V_18 ) ;
V_65:
F_38 ( V_57 ) ;
return V_54 ;
}
static void T_5 F_44 ( void )
{
F_45 ( V_57 ) ;
F_38 ( V_57 ) ;
F_43 ( V_18 ) ;
}
