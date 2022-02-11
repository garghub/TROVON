static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_3 ( T_1 V_5 , T_1 V_6 )
{
char V_7 [ 2 ] ;
V_7 [ 0 ] = V_6 ;
V_7 [ 1 ] = V_5 ;
F_4 ( V_8 , & V_7 [ 0 ] , 2 ) ;
}
static void F_5 ( void )
{
F_3 ( V_9 | V_10 , V_11 ) ;
F_3 ( ~ ( V_9 | V_10 ) ,
V_11 | V_12 ) ;
F_3 ( V_13 | V_14 | V_15 ,
V_16 ) ;
F_3 ( ~ ( V_13 | V_14 | V_15 ) ,
V_16 | V_12 ) ;
F_3 ( V_17 | V_18 ,
V_19 ) ;
F_3 ( ~ ( V_17 | V_18 ) ,
V_19 | V_12 ) ;
F_3 ( 0xFF ,
V_20 | V_12 ) ;
F_3 ( 0xFF ,
V_21 | V_12 ) ;
F_3 ( 0xFF ,
V_22 | V_12 ) ;
}
static inline void F_6 ( void )
{
F_3 ( V_23 , V_19 ) ;
}
static inline void F_7 ( void )
{
F_3 ( V_23 ,
V_19 | V_12 ) ;
}
static void F_8 ( void )
{
unsigned long V_24 = F_9 ( V_25 ) | V_26 ;
F_10 ( V_24 , V_25 ) ;
F_6 () ;
}
static void F_11 ( void )
{
unsigned long V_24 ;
F_7 () ;
V_24 = F_9 ( V_25 ) & ~ V_26 ;
F_10 ( V_24 , V_25 ) ;
}
static int T_2 F_12 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_13 ( V_28 ) ;
int V_31 ;
if ( ( V_31 = F_14 ( V_30 ) ) < 0 )
return V_31 ;
if ( ( V_31 = F_15 ( V_30 ) ) < 0 ) {
F_16 ( V_28 -> V_32 . V_33 , L_1 ) ;
F_17 ( V_28 ) ;
return V_31 ;
}
return 0 ;
}
static void F_18 ( void )
{
F_19 ( V_34 ) ;
F_20 ( V_34 ) ;
F_21 ( V_34 ) ;
F_22 ( V_35 ) ;
F_20 ( V_35 ) ;
F_21 ( V_35 ) ;
F_22 ( V_36 ) ;
F_20 ( V_36 ) ;
F_21 ( V_36 ) ;
F_22 ( V_37 ) ;
F_20 ( V_37 ) ;
F_21 ( V_37 ) ;
F_22 ( V_38 ) ;
F_20 ( V_38 ) ;
F_21 ( V_38 ) ;
F_22 ( V_39 ) ;
F_20 ( V_39 ) ;
F_21 ( V_39 ) ;
}
static void F_23 ( void )
{
F_24 ( V_34 ) ;
F_24 ( V_35 ) ;
F_24 ( V_36 ) ;
F_24 ( V_37 ) ;
F_24 ( V_38 ) ;
F_24 ( V_39 ) ;
}
static int T_2 F_25 ( struct V_40 * V_41 )
{
struct V_27 * V_28 = 0 ;
struct V_29 * V_30 ;
const struct V_42 * V_43 = & V_44 ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
int V_31 = 0 , V_49 ;
F_26 ( & V_41 -> V_50 , L_2 V_51 L_3 , V_52 ) ;
if ( F_27 () ) {
F_28 ( L_4 ) ;
V_31 = - V_53 ;
goto V_54;
}
if ( V_41 -> V_55 != 2
|| V_41 -> V_56 [ 0 ] . V_57 != V_58
|| V_41 -> V_56 [ 1 ] . V_57 != V_59 ) {
F_28 ( L_5 ) ;
V_31 = - V_53 ;
goto V_54;
}
F_10 ( V_60 | ( 1 << 19 ) , V_61 ) ;
V_31 = F_29 ( & V_62 ) ;
if ( V_31 < 0 ) {
F_28 ( L_6 ) ;
goto V_54;
}
V_46 = F_30 ( 2 ) ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
F_31 ( V_48 . type , L_7 , V_63 ) ;
V_8 = F_32 ( V_46 , & V_48 ,
V_64 , NULL ) ;
F_33 ( V_46 ) ;
if ( ! V_8 ) {
F_28 ( L_8 ) ;
V_31 = - V_53 ;
goto V_65;
}
F_5 () ;
V_66 = F_34 ( & V_41 -> V_50 , L_9 ) ;
if ( F_35 ( V_66 ) ) {
F_28 ( L_10 ) ;
V_31 = F_36 ( V_66 ) ;
goto V_67;
}
V_31 = F_37 ( V_66 ) ;
if ( V_31 < 0 ) {
F_28 ( L_11 ) ;
goto V_68;
}
V_31 = F_38 ( V_66 , 48000 ) ;
if ( V_31 < 0 ) {
F_28 ( L_12 ) ;
goto V_69;
}
F_10 ( F_9 ( V_61 ) | V_70 , V_61 ) ;
F_10 ( V_71 , V_72 ) ;
while ( ( F_9 ( V_73 ) & V_71 ) !=
V_71 ) ;
V_28 = F_39 ( V_43 , & V_41 -> V_50 , F_40 ( & V_41 -> V_50 ) ) ;
if ( ! V_28 ) {
F_28 ( L_13 ) ;
V_31 = - V_74 ;
goto V_69;
}
F_18 () ;
V_28 -> V_75 = V_41 -> V_56 [ 0 ] . V_76 ;
V_28 -> V_77 = V_41 -> V_56 [ 0 ] . V_78 - V_41 -> V_56 [ 0 ] . V_76 + 1 ;
if ( ! F_41 ( V_28 -> V_75 , V_28 -> V_77 , V_52 ) ) {
F_26 ( & V_41 -> V_50 , L_14 ) ;
V_31 = - V_74 ;
goto V_79;
}
V_28 -> V_80 = ( void V_81 * ) V_41 -> V_56 [ 0 ] . V_76 ;
V_49 = F_42 ( V_41 , 0 ) ;
if ( V_49 < 0 ) {
V_31 = - V_82 ;
goto V_79;
}
F_8 () ;
F_43 ( V_41 , V_28 ) ;
V_30 = F_13 ( V_28 ) ;
F_44 ( V_30 ) ;
F_45 ( & V_41 -> V_50 , L_15 , V_28 -> V_80 , V_28 -> V_49 ) ;
V_31 = F_46 ( V_28 , V_49 , V_83 ) ;
if ( V_31 == 0 )
return V_31 ;
F_11 () ;
V_79:
F_23 () ;
F_47 ( V_28 ) ;
V_69:
F_48 ( V_66 ) ;
V_68:
F_49 ( V_66 ) ;
V_67:
F_50 ( V_8 ) ;
V_8 = NULL ;
V_65:
F_51 ( & V_62 ) ;
V_54:
return V_31 ;
}
static int F_52 ( struct V_40 * V_41 )
{
struct V_27 * V_28 = F_53 ( V_41 ) ;
F_54 ( V_28 ) ;
F_11 () ;
F_55 ( V_28 -> V_75 , V_28 -> V_77 ) ;
F_47 ( V_28 ) ;
F_23 () ;
F_48 ( V_66 ) ;
F_49 ( V_66 ) ;
F_50 ( V_8 ) ;
V_8 = NULL ;
F_51 ( & V_62 ) ;
F_43 ( V_41 , NULL ) ;
return 0 ;
}
