static int T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 , V_3 ;
int V_4 , V_5 , V_6 ;
struct V_7 * V_8 = F_2 ( V_1 ) ;
struct V_9 * V_10 ;
if ( ! ( V_10 = F_3 () ) ) {
F_4 ( L_1 ) ;
return - V_11 ;
}
F_5 ( V_10 , V_1 ) ;
F_6 ( V_1 , V_10 ) ;
V_2 = V_8 -> V_12 ;
if ( ! F_7 ( V_2 , V_13 , V_14 ) ) {
V_5 = - V_15 ;
goto V_16;
}
if ( ! F_7 ( V_2 + V_17 ,
V_18 , V_14 ) ) {
V_5 = - V_15 ;
goto V_19;
}
#if V_20 & V_21
F_4 ( L_2 , V_2 , V_8 -> V_22 . V_23 ) ;
F_4 ( L_3 ,
F_8 ( V_2 + V_17 ) , F_8 ( V_2 + V_24 ) ) ;
#endif
V_6 = F_8 ( V_2 + V_24 ) >> 6 ;
for ( V_4 = 0 ; V_4 < V_25 ; V_4 ++ )
V_10 -> V_26 [ V_4 ] = F_8 ( V_2 + V_27 + V_4 ) ;
F_4 ( L_4 ,
V_8 -> V_28 , V_29 [ V_6 ] , V_10 -> V_26 ) ;
V_10 -> V_30 = V_31 [ ( F_8 ( V_2 + V_24 ) >> 3 ) & 0x07 ] ;
F_4 ( L_5 , V_10 -> V_30 ) ;
V_5 = F_9 ( V_10 -> V_30 , V_32 , 0 , V_14 , V_10 ) ;
if ( V_5 ) {
F_4 ( L_6 , V_10 -> V_30 ) ;
goto V_33;
}
V_3 = V_34 [ F_8 ( V_2 + V_24 ) & 0x07 ] * 0x1000 ;
if ( V_3 > 1024 * 1024 ) {
if ( V_3 < F_10 ( V_35 ) ) {
F_4 ( V_36 L_7 ) ;
F_4 ( V_36 L_8 ) ;
F_4 ( V_36 L_9 ,
( V_37 ) F_10 ( V_35 ) ) ;
F_4 ( V_36 L_10 ) ;
V_5 = - V_38 ;
goto V_39;
}
}
if ( ! F_11 ( V_3 , V_40 * 0x100 , V_14 ) ) {
F_4 ( L_11 ,
V_3 ) ;
goto V_39;
}
F_4 ( L_12 ,
V_40 / 4 , V_3 ) ;
V_41 . V_42 = F_12 ( V_3 , V_40 * 0x100 ) ;
if ( ! V_41 . V_42 ) {
F_4 ( V_43 L_13 ) ;
F_4 ( V_43 L_10 ) ;
V_5 = - V_44 ;
goto V_45;
}
F_4 ( L_14 ,
V_40 / 4 , V_41 . V_42 ) ;
V_10 -> V_46 = ( unsigned long ) V_41 . V_42 ;
V_10 -> V_47 = V_10 -> V_46 + ( V_40 - V_48 ) * 256 ;
V_10 -> V_12 = V_2 ;
V_41 . V_49 = L_15 ;
V_41 . V_50 = V_48 ;
V_41 . V_51 = V_48 + V_52 ;
V_41 . V_53 = V_40 ;
V_41 . V_54 = 1 ;
V_41 . V_55 = V_3 ;
if ( V_56 > 0 )
F_4 ( L_16 ) ;
V_41 . V_57 = & V_58 ;
V_41 . V_59 = & V_60 ;
V_41 . V_61 = & V_62 ;
V_41 . V_63 = & V_64 ;
V_10 -> V_65 = & V_66 ;
V_10 -> V_67 = V_68 [ V_6 ] ;
if ( ( V_5 = F_13 ( V_10 ) ) )
goto V_69;
F_14 ( V_10 , 0 ) ;
return 0 ;
V_69:
F_15 ( V_41 . V_42 ) ;
V_45:
F_16 ( V_3 , V_40 * 0x100 ) ;
V_39:
F_17 ( V_10 -> V_30 , V_10 ) ;
V_33:
F_18 ( V_2 + V_17 , V_18 ) ;
V_19:
F_18 ( V_2 , V_13 ) ;
V_16:
F_19 ( V_10 ) ;
return V_5 ;
}
static int T_2 F_20 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_21 ( V_1 ) ;
unsigned long V_2 = F_2 ( V_1 ) -> V_12 ;
F_22 ( V_10 ) ;
F_15 ( V_41 . V_42 ) ;
F_16 ( V_41 . V_55 , V_40 * 0x100 ) ;
F_17 ( V_10 -> V_30 , V_10 ) ;
F_18 ( V_2 + V_17 , V_18 ) ;
F_18 ( V_2 , V_13 ) ;
F_19 ( V_10 ) ;
return 0 ;
}
static void V_58 ( struct V_9 * V_10 )
{
unsigned short V_2 = V_10 -> V_12 ;
F_23 ( 0x04 , V_2 + V_70 ) ;
if ( V_56 > 1 ) F_4 ( L_17 , V_10 -> V_49 ) ;
F_24 ( 2 ) ;
V_41 . V_71 = 0 ;
F_23 ( 0x01 , V_2 + V_70 ) ;
if ( V_56 > 1 ) F_4 ( L_18 ) ;
}
static void
V_64 ( struct V_9 * V_10 , struct V_72 * V_73 , int V_74 )
{
void T_3 * V_75 = V_41 . V_42 + ( ( V_74 - V_48 ) << 8 ) ;
F_25 ( V_73 , V_75 , sizeof( struct V_72 ) ) ;
V_73 -> V_76 = ( V_73 -> V_76 + 3 ) & ~ 3 ;
}
static void V_60 ( struct V_9 * V_10 , int V_76 , struct V_77 * V_78 ,
int V_79 )
{
void T_3 * V_80 = V_41 . V_42 + V_79 - V_48 * 256 ;
if ( V_79 + V_76 > V_40 * 256 ) {
int V_81 = V_40 * 256 - V_79 ;
F_25 ( V_78 -> V_82 , V_80 , V_81 ) ;
V_76 -= V_81 ;
F_25 ( V_78 -> V_82 + V_81 ,
V_41 . V_42 + V_52 * 256 , V_76 ) ;
} else {
F_25 ( V_78 -> V_82 , V_80 , V_76 ) ;
}
}
static void V_62 ( struct V_9 * V_10 , int V_76 ,
const unsigned char * V_83 , int V_84 )
{
void T_3 * V_85 = V_41 . V_42 + ( ( V_84 - V_48 ) << 8 ) ;
V_76 = ( V_76 + 3 ) & ~ 3 ;
F_26 ( V_85 , V_83 , V_76 ) ;
}
static int F_27 ( void )
{
return F_28 ( & V_86 ) ;
}
static void F_29 ( void )
{
F_30 ( & V_86 ) ;
}
