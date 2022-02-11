static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
V_2 = ( unsigned long ) V_3 ;
F_4 ( F_5 ( V_4 ) ) ;
}
static int F_6 ( void )
{
V_5 = F_7 ( V_6 + V_7 ) ;
return 0 ;
}
static void F_8 ( void )
{
F_9 ( - 1 , V_8 + V_9 ) ;
F_9 ( - 1 , V_6 + V_9 ) ;
F_9 ( - 1 , V_6 + V_10 ) ;
F_9 ( V_5 , V_6 + V_11 ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
T_2 V_15 ;
F_9 ( V_16 | V_17 , V_18 ) ;
V_15 = F_7 ( V_19 ) | V_20 ;
F_9 ( V_15 , V_19 ) ;
if ( ! ( F_7 ( V_19 ) & V_20 ) ) {
F_9 ( 0xa05f , V_21 ) ;
F_9 ( V_15 , V_19 ) ;
F_9 ( 0 , V_21 ) ;
}
return 0 ;
}
static void F_13 ( struct V_13 * V_14 )
{
T_2 V_15 ;
F_9 ( V_16 | V_17 , V_18 ) ;
V_15 = F_7 ( V_19 ) & ~ V_20 ;
F_9 ( V_15 , V_19 ) ;
if ( F_7 ( V_19 ) & V_20 ) {
F_9 ( 0xa05f , V_21 ) ;
F_9 ( V_15 , V_19 ) ;
F_9 ( 0 , V_21 ) ;
}
}
static void F_14 ( struct V_13 * V_22 , int V_23 )
{
void T_3 * V_24 = V_23 ? V_25 : V_18 ;
F_9 ( V_16 , V_24 ) ;
}
static T_2 T_4 F_15 ( void )
{
return - F_7 ( ( void T_3 * ) V_26 + V_27 ) ;
}
static void F_16 ( unsigned long V_28 ,
void T_3 * V_29 )
{
T_2 V_30 = V_31 | V_32 ;
unsigned long V_33 = V_28 ;
if ( V_33 >= 1500000 ) {
V_33 /= 16 ;
V_30 |= V_34 ;
}
F_9 ( 0xffff , V_29 + V_35 ) ;
F_9 ( V_30 , V_29 + V_36 ) ;
F_17 ( V_29 + V_27 , L_1 ,
V_33 , 200 , 16 , V_37 ) ;
F_18 ( F_15 , 16 , V_33 ) ;
}
static T_5 F_19 ( int V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
F_9 ( 1 , V_42 + V_43 ) ;
V_41 -> V_44 ( V_41 ) ;
return V_45 ;
}
static void F_20 ( enum V_46 V_47 , struct V_40 * V_41 )
{
T_2 V_30 = F_7 ( V_42 + V_36 ) & ~ V_31 ;
F_9 ( V_30 , V_42 + V_36 ) ;
switch ( V_47 ) {
case V_48 :
F_9 ( V_49 , V_42 + V_35 ) ;
V_30 |= V_32 | V_31 ;
F_9 ( V_30 , V_42 + V_36 ) ;
break;
case V_50 :
V_30 &= ~ V_32 ;
F_9 ( V_30 , V_42 + V_36 ) ;
break;
case V_51 :
case V_52 :
case V_53 :
default:
break;
}
}
static int F_21 ( unsigned long V_54 , struct V_40 * V_41 )
{
unsigned long V_30 = F_7 ( V_42 + V_36 ) ;
F_9 ( V_30 & ~ V_31 , V_42 + V_36 ) ;
F_9 ( V_54 , V_42 + V_35 ) ;
F_9 ( V_30 | V_31 , V_42 + V_36 ) ;
return 0 ;
}
static void F_22 ( unsigned long V_28 ,
void T_3 * V_29 , int V_38 )
{
unsigned long V_33 = V_28 ;
unsigned int V_30 = 0 ;
V_42 = V_29 ;
if ( V_33 > 0x100000 * V_55 ) {
V_33 /= 256 ;
V_30 |= V_56 ;
} else if ( V_33 > 0x10000 * V_55 ) {
V_33 /= 16 ;
V_30 |= V_34 ;
}
V_49 = V_33 / V_55 ;
F_9 ( V_30 , V_42 + V_36 ) ;
F_23 ( V_38 , & V_57 ) ;
F_24 ( & V_58 ,
V_33 ,
1 ,
0xffffU ) ;
}
void T_1 F_25 ( void )
{
}
static void T_1 F_26 ( void )
{
struct V_59 * V_60 ;
const char * V_61 ;
void T_3 * V_29 ;
int V_62 ;
int V_38 ;
struct V_63 * V_63 ;
unsigned long V_33 ;
V_63 = F_27 ( L_2 , NULL ) ;
F_28 ( F_29 ( V_63 ) ) ;
F_30 ( V_63 ) ;
V_33 = F_31 ( V_63 ) ;
V_62 = F_32 ( V_64 ,
L_3 , & V_61 ) ;
if ( F_33 ( V_62 ) )
return;
V_60 = F_34 ( V_61 ) ;
V_29 = F_35 ( V_60 , 0 ) ;
if ( F_33 ( ! V_29 ) )
return;
F_9 ( 0 , V_29 + V_36 ) ;
F_16 ( V_33 , V_29 ) ;
V_62 = F_32 ( V_64 ,
L_4 , & V_61 ) ;
if ( F_33 ( V_62 ) )
return;
V_60 = F_34 ( V_61 ) ;
V_29 = F_35 ( V_60 , 0 ) ;
if ( F_33 ( ! V_29 ) )
return;
V_38 = F_36 ( V_60 , 0 ) ;
F_9 ( 0 , V_29 + V_36 ) ;
F_22 ( V_33 , V_29 , V_38 ) ;
}
static void T_1 F_37 ( void )
{
F_9 ( 0xffffffffU , V_8 + V_9 ) ;
F_38 ( V_65 ) ;
F_39 ( false ) ;
}
static void T_1 F_40 ( void )
{
unsigned long V_66 ;
int V_67 ;
F_41 ( NULL , V_68 ,
V_69 , NULL ) ;
V_66 = F_7 ( V_70 + V_71 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
struct V_72 * V_73 ;
if ( ( V_66 & ( 16 << V_67 ) ) == 0 )
continue;
V_73 = F_42 ( sizeof( struct V_72 ) , V_74 ) ;
if ( ! V_73 )
continue;
V_73 -> V_75 . V_76 = 0xc0000000 + 0x10000000 * V_67 ;
V_73 -> V_75 . V_77 = V_73 -> V_75 . V_76 + 0x0fffffff ;
V_73 -> V_75 . V_78 = V_79 ;
V_73 -> V_38 = V_80 + V_67 ;
V_73 -> V_81 = V_67 ;
F_43 ( V_73 ) ;
}
}
static void T_1 F_44 ( void )
{
struct V_63 * V_63 ;
unsigned long V_33 ;
V_63 = F_27 ( L_2 , NULL ) ;
F_28 ( F_29 ( V_63 ) ) ;
F_30 ( V_63 ) ;
V_33 = F_31 ( V_63 ) ;
F_9 ( 0 , V_82 + V_36 ) ;
F_9 ( 0 , V_83 + V_36 ) ;
F_9 ( 0 , V_26 + V_36 ) ;
F_16 ( V_33 , ( void T_3 * ) V_26 ) ;
F_22 ( V_33 , ( void T_3 * ) V_83 ,
V_84 ) ;
}
static void T_1 F_45 ( void )
{
F_9 ( - 1 , V_8 + V_9 ) ;
F_9 ( - 1 , V_6 + V_9 ) ;
F_9 ( - 1 , V_6 + V_10 ) ;
F_46 ( V_6 , L_5 , V_85 ,
- 1 , V_86 , NULL ) ;
F_39 ( false ) ;
}
static void T_1 F_47 ( void )
{
unsigned long V_66 ;
int V_67 ;
F_48 ( & V_87 ) ;
V_66 = F_7 ( V_70 + V_71 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
struct V_72 * V_73 ;
if ( ( V_66 & ( 16 << V_67 ) ) == 0 )
continue;
V_73 = F_42 ( sizeof( struct V_72 ) , V_74 ) ;
if ( ! V_73 )
continue;
V_73 -> V_75 . V_76 = 0xc0000000 + 0x10000000 * V_67 ;
V_73 -> V_75 . V_77 = V_73 -> V_75 . V_76 + 0x0fffffff ;
V_73 -> V_75 . V_78 = V_79 ;
V_73 -> V_38 = V_80 + V_67 ;
V_73 -> V_81 = V_67 ;
F_43 ( V_73 ) ;
}
F_49 ( false ) ;
}
