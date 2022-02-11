static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_3 ( void )
{
F_4 ( V_5 ,
V_6 , V_7 | V_8 ) ;
F_4 ( V_5 ,
V_6 | V_9 ,
~ ( V_7 | V_8 ) ) ;
F_4 ( V_5 ,
V_10 ,
V_11 | V_12 | V_13 ) ;
F_4 ( V_5 ,
V_10 | V_9 ,
~ ( V_11 | V_12 | V_13 ) ) ;
F_4 ( V_5 ,
V_14 , V_15 | V_16 ) ;
F_4 ( V_5 ,
V_14 | V_9 ,
~ ( V_15 | V_16 ) ) ;
F_4 ( V_5 ,
V_17 | V_9 , 0xFF ) ;
F_4 ( V_5 ,
V_18 | V_9 ,
0xFF ) ;
F_4 ( V_5 ,
V_19 | V_9 ,
0xFF ) ;
}
static void F_5 ( void )
{
F_4 ( V_5 ,
( V_6 | V_9 ) ,
V_20 ) ;
F_4 ( V_5 ,
( V_6 | V_9 ) ,
~ V_8 ) ;
F_4 ( V_5 ,
V_6 , V_8 ) ;
F_4 ( V_5 ,
( V_10 | V_9 ) ,
~ 0 ) ;
F_4 ( V_5 ,
V_10 ,
( V_11 | V_12 | V_13 ) ) ;
F_4 ( V_5 ,
( V_14 | V_9 ) , ~ 0 ) ;
F_4 ( V_5 ,
V_6 , V_7 ) ;
F_4 ( V_5 ,
V_14 ,
( V_15 | V_16 ) ) ;
F_4 ( V_5 ,
( V_14 | V_9 ) ,
( V_21 | V_22 ) ) ;
F_4 ( V_5 ,
V_17 | V_9 , ~ 0 ) ;
F_4 ( V_5 ,
V_18 | V_9 ,
~ 0 ) ;
F_4 ( V_5 ,
V_19 | V_9 , ~ 0 ) ;
F_6 ( ( F_7 ( V_23 ) | ( 1 << 22 ) ) , V_23 ) ;
F_8 ( V_24 L_1 ,
F_9 ( V_5 , 0x00 ) ) ;
F_8 ( V_24 L_2 ,
F_9 ( V_5 , 0x02 ) ) ;
F_8 ( V_24 L_3 ,
F_9 ( V_5 , 0x14 ) ) ;
}
static void F_10 ( void )
{
if ( F_11 () )
F_3 () ;
else
F_5 () ;
}
static inline void F_12 ( void )
{
F_4 ( V_5 , V_14 ,
V_25 ) ;
}
static inline void F_13 ( void )
{
F_4 ( V_5 ,
V_14 | V_9 ,
V_25 ) ;
}
static void F_14 ( void )
{
unsigned long V_26 = F_7 ( V_27 ) | V_28 ;
F_6 ( V_26 , V_27 ) ;
F_12 () ;
}
static void F_15 ( void )
{
unsigned long V_26 ;
F_13 () ;
V_26 = F_7 ( V_27 ) & ~ V_28 ;
F_6 ( V_26 , V_27 ) ;
}
static int T_1 F_16 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_17 ( V_30 ) ;
int V_33 ;
if ( ( V_33 = F_18 ( V_32 ) ) < 0 )
return V_33 ;
if ( ( V_33 = F_19 ( V_32 ) ) < 0 ) {
F_20 ( V_30 -> V_34 . V_35 , L_4 ) ;
F_21 ( V_30 ) ;
return V_33 ;
}
return 0 ;
}
static void F_22 ( void )
{
if ( F_11 () ) {
F_23 ( V_36 ) ;
F_24 ( V_36 ) ;
F_25 ( V_36 ) ;
F_26 ( V_37 ) ;
F_24 ( V_37 ) ;
F_25 ( V_37 ) ;
F_26 ( V_38 ) ;
F_24 ( V_38 ) ;
F_25 ( V_38 ) ;
F_26 ( V_39 ) ;
F_24 ( V_39 ) ;
F_25 ( V_39 ) ;
F_26 ( V_40 ) ;
F_24 ( V_40 ) ;
F_25 ( V_40 ) ;
F_26 ( V_41 ) ;
F_24 ( V_41 ) ;
F_25 ( V_41 ) ;
}
}
static void F_27 ( void )
{
if ( F_11 () ) {
F_28 ( V_36 ) ;
F_28 ( V_37 ) ;
F_28 ( V_38 ) ;
F_28 ( V_39 ) ;
F_28 ( V_40 ) ;
F_28 ( V_41 ) ;
}
}
static int T_1 F_29 ( struct V_42 * V_43 )
{
struct V_29 * V_30 = 0 ;
struct V_31 * V_32 ;
const struct V_44 * V_45 = & V_46 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
int V_33 = 0 , V_51 ;
F_30 ( & V_43 -> V_52 , L_5 V_53 L_6 , V_54 ) ;
if ( F_31 () ) {
F_32 ( L_7 ) ;
V_33 = - V_55 ;
goto V_56;
}
if ( V_43 -> V_57 != 2
|| V_43 -> V_58 [ 0 ] . V_59 != V_60
|| V_43 -> V_58 [ 1 ] . V_59 != V_61 ) {
F_32 ( L_8 ) ;
V_33 = - V_55 ;
goto V_56;
}
F_6 ( V_62 | ( 1 << 19 ) , V_23 ) ;
V_33 = F_33 ( & V_63 ) ;
if ( V_33 < 0 ) {
F_32 ( L_9 ) ;
goto V_56;
}
V_48 = F_34 ( 2 ) ;
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
F_35 ( V_50 . type , L_10 , V_64 ) ;
V_5 = F_36 ( V_48 , & V_50 ,
V_65 , NULL ) ;
F_37 ( V_48 ) ;
if ( ! V_5 ) {
F_32 ( L_11 ) ;
V_33 = - V_55 ;
goto V_66;
}
F_10 () ;
V_67 = F_38 ( & V_43 -> V_52 , L_12 ) ;
if ( F_39 ( V_67 ) ) {
F_32 ( L_13 ) ;
V_33 = F_40 ( V_67 ) ;
goto V_68;
}
V_33 = F_41 ( V_67 ) ;
if ( V_33 < 0 ) {
F_32 ( L_14 ) ;
goto V_69;
}
V_33 = F_42 ( V_67 , 48000 ) ;
if ( V_33 < 0 ) {
F_32 ( L_15 ) ;
goto V_70;
}
F_6 ( F_7 ( V_23 ) | V_71 , V_23 ) ;
F_6 ( V_72 , V_73 ) ;
while ( ( F_7 ( V_74 ) & V_72 ) !=
V_72 ) ;
V_30 = F_43 ( V_45 , & V_43 -> V_52 , F_44 ( & V_43 -> V_52 ) ) ;
if ( ! V_30 ) {
F_32 ( L_16 ) ;
V_33 = - V_75 ;
goto V_70;
}
F_22 () ;
V_30 -> V_76 = V_43 -> V_58 [ 0 ] . V_77 ;
V_30 -> V_78 = V_43 -> V_58 [ 0 ] . V_79 - V_43 -> V_58 [ 0 ] . V_77 + 1 ;
if ( ! F_45 ( V_30 -> V_76 , V_30 -> V_78 , V_54 ) ) {
F_30 ( & V_43 -> V_52 , L_17 ) ;
V_33 = - V_75 ;
goto V_80;
}
V_30 -> V_81 = ( void V_82 * ) V_43 -> V_58 [ 0 ] . V_77 ;
V_51 = F_46 ( V_43 , 0 ) ;
if ( V_51 < 0 ) {
V_33 = - V_83 ;
goto V_80;
}
F_14 () ;
F_47 ( V_43 , V_30 ) ;
V_32 = F_17 ( V_30 ) ;
F_48 ( V_32 ) ;
F_49 ( & V_43 -> V_52 , L_18 , V_30 -> V_81 , V_30 -> V_51 ) ;
V_33 = F_50 ( V_30 , V_51 , 0 ) ;
if ( V_33 == 0 )
return V_33 ;
F_15 () ;
V_80:
F_27 () ;
F_51 ( V_30 ) ;
V_70:
F_52 ( V_67 ) ;
V_69:
F_53 ( V_67 ) ;
V_68:
F_54 ( V_5 ) ;
V_5 = NULL ;
V_66:
F_55 ( & V_63 ) ;
V_56:
return V_33 ;
}
static int F_56 ( struct V_42 * V_43 )
{
struct V_29 * V_30 = F_57 ( V_43 ) ;
F_58 ( V_30 ) ;
F_15 () ;
F_59 ( V_30 -> V_76 , V_30 -> V_78 ) ;
F_51 ( V_30 ) ;
F_27 () ;
F_52 ( V_67 ) ;
F_53 ( V_67 ) ;
F_54 ( V_5 ) ;
V_5 = NULL ;
F_55 ( & V_63 ) ;
F_47 ( V_43 , NULL ) ;
return 0 ;
}
