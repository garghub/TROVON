static void F_1 ( void T_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
T_2 V_4 , V_5 , V_6 ;
T_3 V_7 ;
T_4 V_8 ;
V_6 = F_2 ( V_9 [ V_3 ] . V_10 ,
V_11 ) - 1 ;
V_4 = F_2 ( 20 , V_11 ) - 1 ;
V_5 = F_2 ( V_9 [ V_3 ] . V_12 ,
V_11 ) - 1 ;
V_7 = F_3 ( V_1 + V_13 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_6 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_13 ) ;
V_7 = F_3 ( V_1 + V_14 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_5 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_14 ) ;
V_7 = F_3 ( V_1 + V_15 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_4 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_15 ) ;
V_8 = F_5 ( V_1 + V_16 ) | ( 1 << V_2 ) ;
F_6 ( V_8 , V_1 + V_16 ) ;
}
static void F_7 ( void T_1 * V_1 , unsigned int V_2 ,
unsigned short V_17 ,
unsigned int V_3 )
{
T_2 V_18 , V_19 , V_6 ;
T_3 V_7 ;
T_4 V_8 ;
struct V_20 * V_21 ;
int V_10 ;
V_21 = F_8 ( V_3 ) ;
V_10 = F_9 ( int , V_21 -> V_22 , V_17 ) ;
V_6 = F_2 ( V_10 , V_11 ) ;
V_18 = F_2 ( V_21 -> V_23 , V_11 ) ;
V_19 = V_6 - V_18 - 1 ;
V_18 -= 1 ;
V_7 = F_3 ( V_1 + V_24 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_18 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_24 ) ;
V_7 = F_3 ( V_1 + V_25 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_19 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_25 ) ;
V_8 = F_5 ( V_1 + V_16 ) & ~ ( 1 << V_2 ) ;
F_6 ( V_8 , V_1 + V_16 ) ;
}
static void F_10 ( void T_1 * V_1 , T_5 * V_26 ,
unsigned int V_2 , unsigned int V_10 ,
unsigned int V_3 )
{
T_2 V_27 , V_28 , V_6 ;
T_3 V_7 ;
struct V_20 * V_21 ;
V_21 = F_8 ( V_29 + V_3 ) ;
V_6 = F_2 ( V_10 , V_11 ) ;
V_27 = F_2 ( V_21 -> V_23 , V_11 ) ;
V_28 = V_6 - V_27 - 1 ;
V_27 -= 1 ;
V_7 = F_3 ( V_1 + V_30 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_27 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_30 ) ;
V_7 = F_3 ( V_1 + V_31 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_28 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_31 ) ;
if ( V_26 ) {
T_2 V_32 = V_26 -> V_33 - V_29 ;
if ( V_32 < V_3 )
V_3 = V_32 ;
}
V_6 = F_2 ( V_21 -> V_34 , V_11 ) ;
V_27 = F_2 ( V_21 -> V_35 , V_11 ) ;
V_28 = V_6 - V_27 - 1 ;
V_27 -= 1 ;
V_7 = F_3 ( V_1 + V_36 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_27 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_36 ) ;
V_7 = F_3 ( V_1 + V_37 ) & ( 0xFF << ( V_2 ? 0 : 8 ) ) ;
V_7 |= ( V_28 << ( V_2 ? 8 : 0 ) ) ;
F_4 ( V_7 , V_1 + V_37 ) ;
}
static void F_11 ( T_6 * V_38 , T_5 * V_39 )
{
int V_40 = V_39 -> V_41 & 1 ;
void T_1 * V_1 = ( void * ) V_38 -> V_42 ;
const T_2 V_43 = V_39 -> V_44 ;
if ( V_43 >= V_45 ) {
F_1 ( V_1 , V_40 ,
V_43 - V_45 ) ;
} else {
F_7 ( V_1 , V_40 ,
V_39 -> V_46 [ V_47 ] ,
V_43 ) ;
}
}
static void F_12 ( T_6 * V_38 , T_5 * V_39 )
{
unsigned int V_48 ;
int V_40 = V_39 -> V_41 & 1 ;
T_5 * V_26 ;
void T_1 * V_1 = ( void * ) V_38 -> V_42 ;
const T_2 V_49 = V_39 -> V_33 - V_29 ;
V_48 = F_13 ( V_39 , V_49 ) ;
V_26 = F_14 ( V_39 ) ;
F_10 ( V_1 , V_26 , V_40 , V_48 , V_49 ) ;
}
static void T_7 F_15 ( void T_1 * V_1 )
{
F_6 ( F_16 ( 15 ) , V_1 + V_50 ) ;
F_6 ( 0 , V_1 + V_16 ) ;
F_4 ( 0x001 , V_1 + V_51 ) ;
F_4 ( 0xFFFF , V_1 + V_52 ) ;
F_6 ( 0 , V_1 + V_53 ) ;
F_10 ( V_1 , NULL , 0 , 600 , 0 ) ;
F_10 ( V_1 , NULL , 1 , 600 , 0 ) ;
}
static T_2 F_17 ( T_6 * V_38 )
{
return V_54 ;
}
static int T_7 F_18 ( T_6 * V_38 ,
const struct V_55 * V_56 )
{
F_19 ( V_57 L_1 , V_38 -> V_58 ) ;
if ( F_20 ( V_38 ) )
return - 1 ;
V_38 -> V_42 = V_38 -> V_59 . V_60 - V_61 ;
return 0 ;
}
static int T_8 F_21 ( struct V_62 * V_63 )
{
struct V_64 * V_64 ;
struct V_65 * V_66 , * V_67 ;
void T_1 * V_1 ;
unsigned long V_68 , V_69 ;
int V_70 , V_71 ;
struct V_72 V_73 , * V_74 [] = { & V_73 } ;
V_64 = F_22 ( & V_63 -> V_2 , NULL ) ;
if ( F_23 ( V_64 ) )
return - V_75 ;
F_24 ( V_64 ) ;
V_68 = F_25 ( V_64 ) ;
V_11 = 1000000000UL / V_68 ;
V_66 = F_26 ( V_63 , V_76 , 0 ) ;
if ( V_66 == NULL ) {
F_19 ( V_77 L_2 ) ;
return - V_75 ;
}
V_67 = F_26 ( V_63 , V_78 , 0 ) ;
if ( V_67 == NULL ) {
F_19 ( V_77 L_3 ) ;
return - V_75 ;
}
V_69 = F_27 ( V_66 ) ;
if ( F_28 ( V_66 -> V_79 , V_69 , L_4 ) == NULL ) {
F_19 ( V_77 L_5 ) ;
return - V_80 ;
}
V_1 = F_29 ( V_66 -> V_79 , V_69 ) ;
if ( ! V_1 ) {
F_19 ( V_77 L_6 ) ;
F_30 ( V_66 -> V_79 , V_69 ) ;
return - V_81 ;
}
F_15 ( V_1 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
for ( V_70 = 0 ; V_70 < V_82 - 2 ; V_70 ++ )
V_73 . V_83 [ V_70 ] = ( unsigned long )
( V_1 + V_61 + V_70 ) ;
V_73 . V_59 . V_84 = ( unsigned long )
( V_1 + V_85 ) ;
V_73 . V_67 = V_67 -> V_79 ;
V_73 . V_2 = & V_63 -> V_2 ;
V_86 . V_87 = V_68 < 100000000 ? V_88 :
V_89 ;
V_71 = F_31 ( & V_86 , V_74 , 1 , NULL ) ;
if ( V_71 )
goto V_90;
return 0 ;
V_90:
F_19 ( V_91 L_7 ) ;
return V_71 ;
}
static int T_8 F_32 ( void )
{
return F_33 ( & V_92 , F_21 ) ;
}
