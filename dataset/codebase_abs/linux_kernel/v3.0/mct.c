static void F_1 ( unsigned int V_1 , void * V_2 )
{
void T_1 * V_3 ;
T_2 V_4 ;
T_2 V_5 ;
F_2 ( V_1 , V_2 ) ;
switch ( ( T_2 ) V_2 ) {
case ( T_2 ) V_6 :
V_3 = V_7 ;
V_4 = 1 << 16 ;
break;
case ( T_2 ) V_8 :
V_3 = V_7 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) V_9 :
V_3 = V_7 ;
V_4 = 1 << 1 ;
break;
case ( T_2 ) V_10 :
V_3 = V_7 ;
V_4 = 1 << 2 ;
break;
case ( T_2 ) V_11 :
V_3 = V_12 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) V_13 :
V_3 = V_12 ;
V_4 = 1 << 1 ;
break;
case ( T_2 ) ( V_14 + V_15 ) :
V_3 = V_14 + V_16 ;
V_4 = 1 << 3 ;
break;
case ( T_2 ) ( V_17 + V_15 ) :
V_3 = V_17 + V_16 ;
V_4 = 1 << 3 ;
break;
case ( T_2 ) ( V_14 + V_18 ) :
V_3 = V_14 + V_16 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) ( V_17 + V_18 ) :
V_3 = V_17 + V_16 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) ( V_14 + V_19 ) :
V_3 = V_14 + V_16 ;
V_4 = 1 << 1 ;
break;
case ( T_2 ) ( V_17 + V_19 ) :
V_3 = V_17 + V_16 ;
V_4 = 1 << 1 ;
break;
default:
return;
}
for ( V_5 = 0 ; V_5 < V_20 / 1000 * V_21 ; V_5 ++ )
if ( F_3 ( V_3 ) & V_4 ) {
F_2 ( V_4 , V_3 ) ;
return;
}
F_4 ( L_1 , V_1 , ( T_2 ) V_2 ) ;
}
static void F_5 ( T_2 V_22 , T_2 V_23 )
{
T_2 V_24 ;
F_1 ( V_23 , V_11 ) ;
F_1 ( V_22 , V_13 ) ;
V_24 = F_3 ( V_6 ) ;
V_24 |= V_25 ;
F_1 ( V_24 , V_6 ) ;
}
static T_3 F_6 ( struct V_26 * V_27 )
{
unsigned int V_23 , V_22 ;
T_2 V_28 = F_3 ( V_13 ) ;
do {
V_22 = V_28 ;
V_23 = F_3 ( V_11 ) ;
V_28 = F_3 ( V_13 ) ;
} while ( V_22 != V_28 );
return ( ( T_3 ) V_22 << 32 ) | V_23 ;
}
static void T_4 F_7 ( void )
{
F_5 ( 0 , 0 ) ;
if ( F_8 ( & V_29 , V_30 ) )
F_4 ( L_2 , V_29 . V_31 ) ;
}
static void F_9 ( void )
{
unsigned int V_32 ;
V_32 = F_3 ( V_6 ) ;
V_32 &= ~ ( V_33 | V_34 ) ;
F_1 ( V_32 , V_6 ) ;
F_1 ( 0 , V_35 ) ;
}
static void F_10 ( enum V_36 V_37 ,
unsigned long V_38 )
{
unsigned int V_32 ;
T_3 V_39 ;
V_32 = F_3 ( V_6 ) ;
if ( V_37 == V_40 ) {
V_32 |= V_34 ;
F_1 ( V_38 , V_10 ) ;
}
V_39 = F_6 ( & V_29 ) + V_38 ;
F_1 ( ( T_2 ) V_39 , V_8 ) ;
F_1 ( ( T_2 ) ( V_39 >> 32 ) , V_9 ) ;
F_1 ( 0x1 , V_35 ) ;
V_32 |= V_33 ;
F_1 ( V_32 , V_6 ) ;
}
static int F_11 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
F_10 ( V_42 -> V_37 , V_38 ) ;
return 0 ;
}
static void F_12 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
F_9 () ;
switch ( V_37 ) {
case V_40 :
F_10 ( V_37 , V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
}
}
static T_5 F_13 ( int V_48 , void * V_49 )
{
struct V_41 * V_42 = V_49 ;
F_1 ( 0x1 , V_50 ) ;
V_42 -> V_51 ( V_42 ) ;
return V_52 ;
}
static void F_14 ( void )
{
V_43 = V_30 / 2 / V_21 ;
F_15 ( & V_53 , V_30 / 2 , 5 ) ;
V_53 . V_54 =
F_16 ( 0xffffffff , & V_53 ) ;
V_53 . V_55 =
F_16 ( 0xf , & V_53 ) ;
V_53 . V_56 = F_17 ( 0 ) ;
F_18 ( & V_53 ) ;
F_19 ( V_57 , & V_58 ) ;
}
static void F_20 ( struct V_59 * V_60 )
{
unsigned long V_61 ;
unsigned long V_4 = V_62 | V_63 ;
void T_1 * V_2 = V_60 -> V_64 + V_15 ;
V_61 = F_3 ( V_2 ) ;
if ( V_61 & V_4 ) {
V_61 &= ~ V_4 ;
F_1 ( V_61 , V_2 ) ;
}
}
static void F_21 ( unsigned long V_38 ,
struct V_59 * V_60 )
{
unsigned long V_61 ;
F_20 ( V_60 ) ;
V_61 = ( 1 << 31 ) | V_38 ;
F_1 ( V_61 , V_60 -> V_64 + V_19 ) ;
F_1 ( 0x1 , V_60 -> V_64 + V_65 ) ;
V_61 = F_3 ( V_60 -> V_64 + V_15 ) ;
V_61 |= V_62 | V_63 |
V_66 ;
F_1 ( V_61 , V_60 -> V_64 + V_15 ) ;
}
static int F_22 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
struct V_59 * V_60 = & V_67 [ F_23 () ] ;
F_21 ( V_38 , V_60 ) ;
return 0 ;
}
static inline void F_24 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
struct V_59 * V_60 = & V_67 [ F_23 () ] ;
F_20 ( V_60 ) ;
switch ( V_37 ) {
case V_40 :
F_21 ( V_43 , V_60 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
}
}
static T_5 F_25 ( int V_48 , void * V_49 )
{
struct V_59 * V_60 = V_49 ;
struct V_41 * V_42 = V_60 -> V_42 ;
if ( V_42 -> V_37 != V_40 )
F_20 ( V_60 ) ;
F_1 ( 0x1 , V_60 -> V_64 + V_68 ) ;
V_42 -> V_51 ( V_42 ) ;
return V_52 ;
}
static void F_26 ( struct V_41 * V_42 )
{
unsigned int V_69 = F_23 () ;
V_67 [ V_69 ] . V_42 = V_42 ;
if ( V_69 == 0 ) {
V_67 [ V_69 ] . V_64 = V_14 ;
V_42 -> V_31 = L_3 ;
} else {
V_67 [ V_69 ] . V_64 = V_17 ;
V_42 -> V_31 = L_4 ;
}
V_42 -> V_56 = F_17 ( V_69 ) ;
V_42 -> V_70 = F_22 ;
V_42 -> V_71 = F_24 ;
V_42 -> V_72 = V_73 | V_74 ;
V_42 -> V_75 = 450 ;
F_15 ( V_42 , V_30 / 2 , 5 ) ;
V_42 -> V_54 =
F_16 ( 0x7fffffff , V_42 ) ;
V_42 -> V_55 =
F_16 ( 0xf , V_42 ) ;
F_18 ( V_42 ) ;
F_1 ( 0x1 , V_67 [ V_69 ] . V_64 + V_18 ) ;
if ( V_69 == 0 ) {
V_76 . V_49 = & V_67 [ V_69 ] ;
F_19 ( V_77 , & V_76 ) ;
} else {
V_78 . V_49 = & V_67 [ V_69 ] ;
F_27 ( V_79 , F_17 ( 1 ) ) ;
F_19 ( V_80 , & V_78 ) ;
}
}
void T_6 F_28 ( struct V_41 * V_42 )
{
F_26 ( V_42 ) ;
}
int F_29 ( void )
{
return 0 ;
}
static void T_4 F_30 ( void )
{
struct V_81 * V_82 ;
V_82 = F_31 ( NULL , L_5 ) ;
V_30 = F_32 ( V_82 ) ;
}
static void T_4 F_33 ( void )
{
F_30 () ;
F_7 () ;
F_14 () ;
}
