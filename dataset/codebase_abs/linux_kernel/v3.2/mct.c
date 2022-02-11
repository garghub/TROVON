static void F_1 ( unsigned int V_1 , void * V_2 )
{
void T_1 * V_3 ;
T_2 V_4 ;
T_2 V_5 ;
F_2 ( V_1 , V_2 ) ;
if ( F_3 ( V_2 >= F_4 ( 0 ) ) ) {
T_2 V_6 = ( T_2 ) V_2 & V_7 ;
switch ( ( T_2 ) V_2 & ~ V_7 ) {
case ( T_2 ) V_8 :
V_3 = ( void T_1 * ) V_6 + V_9 ;
V_4 = 1 << 3 ;
break;
case ( T_2 ) V_10 :
V_3 = ( void T_1 * ) V_6 + V_9 ;
V_4 = 1 << 1 ;
break;
case ( T_2 ) V_11 :
V_3 = ( void T_1 * ) V_6 + V_9 ;
V_4 = 1 << 0 ;
break;
default:
return;
}
} else {
switch ( ( T_2 ) V_2 ) {
case ( T_2 ) V_12 :
V_3 = V_13 ;
V_4 = 1 << 16 ;
break;
case ( T_2 ) V_14 :
V_3 = V_13 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) V_15 :
V_3 = V_13 ;
V_4 = 1 << 1 ;
break;
case ( T_2 ) V_16 :
V_3 = V_13 ;
V_4 = 1 << 2 ;
break;
case ( T_2 ) V_17 :
V_3 = V_18 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) V_19 :
V_3 = V_18 ;
V_4 = 1 << 1 ;
break;
default:
return;
}
}
for ( V_5 = 0 ; V_5 < V_20 / 1000 * V_21 ; V_5 ++ )
if ( F_5 ( V_3 ) & V_4 ) {
F_2 ( V_4 , V_3 ) ;
return;
}
F_6 ( L_1 , V_1 , ( T_2 ) V_2 ) ;
}
static void F_7 ( T_2 V_22 , T_2 V_23 )
{
T_2 V_24 ;
F_1 ( V_23 , V_17 ) ;
F_1 ( V_22 , V_19 ) ;
V_24 = F_5 ( V_12 ) ;
V_24 |= V_25 ;
F_1 ( V_24 , V_12 ) ;
}
static T_3 F_8 ( struct V_26 * V_27 )
{
unsigned int V_23 , V_22 ;
T_2 V_28 = F_5 ( V_19 ) ;
do {
V_22 = V_28 ;
V_23 = F_5 ( V_17 ) ;
V_28 = F_5 ( V_19 ) ;
} while ( V_22 != V_28 );
return ( ( T_3 ) V_22 << 32 ) | V_23 ;
}
static void F_9 ( struct V_26 * V_27 )
{
F_7 ( 0 , 0 ) ;
}
static void T_4 F_10 ( void )
{
F_7 ( 0 , 0 ) ;
if ( F_11 ( & V_29 , V_30 ) )
F_6 ( L_2 , V_29 . V_31 ) ;
}
static void F_12 ( void )
{
unsigned int V_32 ;
V_32 = F_5 ( V_12 ) ;
V_32 &= ~ ( V_33 | V_34 ) ;
F_1 ( V_32 , V_12 ) ;
F_1 ( 0 , V_35 ) ;
}
static void F_13 ( enum V_36 V_37 ,
unsigned long V_38 )
{
unsigned int V_32 ;
T_3 V_39 ;
V_32 = F_5 ( V_12 ) ;
if ( V_37 == V_40 ) {
V_32 |= V_34 ;
F_1 ( V_38 , V_16 ) ;
}
V_39 = F_8 ( & V_29 ) + V_38 ;
F_1 ( ( T_2 ) V_39 , V_14 ) ;
F_1 ( ( T_2 ) ( V_39 >> 32 ) , V_15 ) ;
F_1 ( 0x1 , V_35 ) ;
V_32 |= V_33 ;
F_1 ( V_32 , V_12 ) ;
}
static int F_14 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
F_13 ( V_42 -> V_37 , V_38 ) ;
return 0 ;
}
static void F_15 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
F_12 () ;
switch ( V_37 ) {
case V_40 :
F_13 ( V_37 , V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
}
}
static T_5 F_16 ( int V_48 , void * V_49 )
{
struct V_41 * V_42 = V_49 ;
F_1 ( 0x1 , V_50 ) ;
V_42 -> V_51 ( V_42 ) ;
return V_52 ;
}
static void F_17 ( void )
{
V_43 = V_30 / 2 / V_21 ;
F_18 ( & V_53 , V_30 / 2 , 5 ) ;
V_53 . V_54 =
F_19 ( 0xffffffff , & V_53 ) ;
V_53 . V_55 =
F_19 ( 0xf , & V_53 ) ;
V_53 . V_56 = F_20 ( 0 ) ;
F_21 ( & V_53 ) ;
F_22 ( V_57 , & V_58 ) ;
}
static void F_23 ( struct V_59 * V_60 )
{
unsigned long V_61 ;
unsigned long V_4 = V_62 | V_63 ;
void T_1 * V_2 = V_60 -> V_6 + V_8 ;
V_61 = F_5 ( V_2 ) ;
if ( V_61 & V_4 ) {
V_61 &= ~ V_4 ;
F_1 ( V_61 , V_2 ) ;
}
}
static void F_24 ( unsigned long V_38 ,
struct V_59 * V_60 )
{
unsigned long V_61 ;
F_23 ( V_60 ) ;
V_61 = ( 1 << 31 ) | V_38 ;
F_1 ( V_61 , V_60 -> V_6 + V_10 ) ;
F_1 ( 0x1 , V_60 -> V_6 + V_64 ) ;
V_61 = F_5 ( V_60 -> V_6 + V_8 ) ;
V_61 |= V_62 | V_63 |
V_65 ;
F_1 ( V_61 , V_60 -> V_6 + V_8 ) ;
}
static int F_25 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
struct V_59 * V_60 = F_26 ( & V_66 ) ;
F_24 ( V_38 , V_60 ) ;
return 0 ;
}
static inline void F_27 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
struct V_59 * V_60 = F_26 ( & V_66 ) ;
F_23 ( V_60 ) ;
switch ( V_37 ) {
case V_40 :
F_24 ( V_43 , V_60 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
}
}
static int F_28 ( struct V_59 * V_60 )
{
struct V_41 * V_42 = V_60 -> V_42 ;
if ( V_42 -> V_37 != V_40 )
F_23 ( V_60 ) ;
if ( F_5 ( V_60 -> V_6 + V_67 ) & 1 ) {
F_1 ( 0x1 , V_60 -> V_6 + V_67 ) ;
return 1 ;
} else {
return 0 ;
}
}
static T_5 F_29 ( int V_48 , void * V_49 )
{
struct V_59 * V_60 = V_49 ;
struct V_41 * V_42 = V_60 -> V_42 ;
F_28 ( V_60 ) ;
V_42 -> V_51 ( V_42 ) ;
return V_52 ;
}
static void F_30 ( struct V_41 * V_42 )
{
struct V_59 * V_60 ;
unsigned int V_68 = F_31 () ;
V_60 = F_26 ( & V_66 ) ;
V_60 -> V_42 = V_42 ;
V_60 -> V_6 = F_4 ( V_68 ) ;
sprintf ( V_60 -> V_31 , L_3 , V_68 ) ;
V_42 -> V_31 = V_60 -> V_31 ;
V_42 -> V_56 = F_20 ( V_68 ) ;
V_42 -> V_69 = F_25 ;
V_42 -> V_70 = F_27 ;
V_42 -> V_71 = V_72 | V_73 ;
V_42 -> V_74 = 450 ;
F_18 ( V_42 , V_30 / 2 , 5 ) ;
V_42 -> V_54 =
F_19 ( 0x7fffffff , V_42 ) ;
V_42 -> V_55 =
F_19 ( 0xf , V_42 ) ;
F_21 ( V_42 ) ;
F_1 ( 0x1 , V_60 -> V_6 + V_11 ) ;
if ( V_75 == V_76 ) {
if ( V_68 == 0 ) {
V_77 . V_49 = V_60 ;
V_42 -> V_48 = V_78 ;
F_22 ( V_78 , & V_77 ) ;
} else {
V_79 . V_49 = V_60 ;
V_42 -> V_48 = V_80 ;
F_22 ( V_80 , & V_79 ) ;
F_32 ( V_80 , F_20 ( 1 ) ) ;
}
} else {
F_33 ( V_81 , 0 ) ;
}
}
int T_6 F_34 ( struct V_41 * V_42 )
{
F_30 ( V_42 ) ;
return 0 ;
}
void F_35 ( struct V_41 * V_42 )
{
unsigned int V_68 = F_31 () ;
V_42 -> V_70 ( V_45 , V_42 ) ;
if ( V_75 == V_76 )
if ( V_68 == 0 )
F_36 ( V_42 -> V_48 , & V_77 ) ;
else
F_36 ( V_42 -> V_48 , & V_79 ) ;
else
F_37 ( V_81 ) ;
}
static void T_4 F_38 ( void )
{
struct V_82 * V_83 ;
V_83 = F_39 ( NULL , L_4 ) ;
V_30 = F_40 ( V_83 ) ;
#ifdef F_41
if ( V_75 == V_84 ) {
int V_85 ;
V_85 = F_42 ( V_81 ,
F_29 , L_5 ,
& V_66 ) ;
F_43 ( V_85 , L_6 ,
V_81 , V_85 ) ;
}
#endif
}
static void T_4 F_44 ( void )
{
if ( F_45 () )
V_75 = V_76 ;
else
V_75 = V_84 ;
F_38 () ;
F_10 () ;
F_17 () ;
}
