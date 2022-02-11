static void F_1 ( struct V_1 * V_1 , struct V_2 V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
T_1 V_7 = V_3 . V_8 | ( V_3 . V_9 << 9 ) | ( V_3 . V_10 << 16 ) ;
F_2 ( 0xa05f , V_5 -> V_11 + V_12 ) ;
F_2 ( V_7 , V_1 -> V_13 ) ;
F_2 ( 0 , V_5 -> V_11 + V_12 ) ;
#ifdef F_3
V_3 . V_8 = V_7 & 0x1ff ;
V_3 . V_9 = ( V_7 >> 9 ) & 0x7f ;
V_3 . V_10 = ( V_7 >> 16 ) & 7 ;
F_4 ( L_1 ,
V_14 , F_5 ( & V_15 , V_3 ) ) ;
#endif
}
void F_6 ( struct V_16 * V_17 , T_1 V_18 , T_1 V_7 )
{
struct V_4 * V_5 = F_7 ( V_17 ) ;
T_1 V_19 ;
V_7 &= V_18 ;
V_19 = F_8 ( V_5 -> V_11 + V_20 ) & ~ V_18 ;
F_2 ( V_19 | V_7 , V_5 -> V_11 + V_20 ) ;
}
static void F_9 ( struct V_21 * V_22 )
{
F_6 ( V_22 -> V_17 -> V_17 . V_23 , V_24 , 0 ) ;
}
static void F_10 ( struct V_21 * V_22 )
{
F_6 ( V_22 -> V_17 -> V_17 . V_23 , V_24 ,
V_22 -> V_25 -> V_26 | V_27 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
unsigned long V_28 = V_22 -> V_17 -> V_29 . V_30 + 0x01000000 ;
unsigned long V_31 = V_32 ;
int V_33 = 0 ;
V_22 -> V_25 = & V_34 ;
if ( ! F_12 ( V_28 , V_31 , L_2 ) ) {
F_13 ( V_35 L_3 ) ;
return - V_36 ;
}
V_22 -> V_22 . V_37 = F_14 ( V_28 , V_31 ) ;
if ( ! V_22 -> V_22 . V_37 ) {
F_13 ( V_35 L_4 ) ;
V_33 = - V_38 ;
goto V_39;
}
V_22 -> V_22 . V_40 . V_41 = V_28 ;
V_22 -> V_22 . V_40 . V_42 = V_31 ;
return 0 ;
V_39:
F_15 ( V_28 , V_31 ) ;
return V_33 ;
}
static int F_16 ( struct V_21 * V_22 , struct V_43 * V_44 )
{
unsigned long V_30 , V_45 ;
V_30 = V_44 -> V_46 + ( V_22 -> V_22 . V_40 . V_41 >> V_47 ) ;
V_45 = V_44 -> V_48 - V_44 -> V_49 ;
return F_17 ( V_44 , V_44 -> V_49 , V_30 , V_45 ,
V_44 -> V_50 ) ;
}
static void F_18 ( struct V_21 * V_22 )
{
F_19 ( V_22 -> V_22 . V_37 ) ;
F_15 ( V_22 -> V_22 . V_40 . V_41 , V_22 -> V_22 . V_40 . V_42 ) ;
}
static int F_20 ( struct V_51 * V_17 )
{
struct V_4 * V_5 ;
int V_52 , V_33 ;
if ( V_17 -> V_53 != V_54 )
return - V_55 ;
if ( ! F_12 ( V_17 -> V_56 . V_30 , V_57 , L_5 ) )
return - V_36 ;
V_5 = F_21 ( sizeof( struct V_4 ) , V_58 ) ;
if ( ! V_5 ) {
V_33 = - V_38 ;
goto V_59;
}
V_5 -> V_11 = F_14 ( V_17 -> V_56 . V_30 , V_57 ) ;
if ( ! V_5 -> V_11 ) {
V_33 = - V_38 ;
goto V_60;
}
F_22 ( V_17 , V_5 ) ;
F_13 ( L_6 ,
( unsigned long ) V_17 -> V_56 . V_30 ) ;
for ( V_52 = 0 ; V_52 < F_23 ( V_5 -> V_61 ) ; V_52 ++ ) {
V_5 -> V_61 [ V_52 ] . V_62 = & V_63 ,
V_5 -> V_61 [ V_52 ] . V_64 = V_65 ,
V_5 -> V_61 [ V_52 ] . V_66 = & V_15 ,
V_5 -> V_61 [ V_52 ] . V_6 = V_5 ;
}
V_5 -> V_61 [ 0 ] . V_13 = V_5 -> V_11 + V_67 ;
V_5 -> V_61 [ 1 ] . V_13 = V_5 -> V_11 + V_68 ;
V_5 -> V_69 [ 0 ] = F_24 ( & V_5 -> V_61 [ 0 ] , NULL , L_7 ,
V_17 -> V_53 ) ;
V_5 -> V_69 [ 1 ] = F_24 ( & V_70 , NULL , L_8 ,
V_17 -> V_53 ) ;
V_5 -> V_69 [ 2 ] = F_24 ( & V_70 , NULL , L_9 ,
V_17 -> V_53 ) ;
for ( V_52 = 0 ; V_52 < F_23 ( V_5 -> V_69 ) ; V_52 ++ )
F_25 ( V_5 -> V_69 [ V_52 ] ) ;
for ( V_52 = 0 ; V_52 < F_23 ( V_71 ) ; V_52 ++ ) {
struct V_72 * V_73 = V_71 + V_52 ;
struct V_74 * V_75 ;
unsigned long V_76 ;
char V_77 [ 32 ] ;
V_76 = V_17 -> V_56 . V_30 + V_73 -> V_78 ;
snprintf ( V_77 , 32 , L_10 , V_17 -> V_53 , V_73 -> V_78 >> 12 ) ;
V_75 = F_26 ( & V_17 -> V_17 , V_77 , V_76 , V_57 ,
V_17 -> V_79 , V_17 -> V_79 ,
V_73 -> V_80 , V_73 -> V_53 ) ;
if ( F_27 ( V_75 ) ) {
F_28 ( & V_17 -> V_17 , L_11 , F_29 ( V_75 ) ) ;
continue;
}
}
return 0 ;
V_60:
if ( V_5 && V_5 -> V_11 )
F_19 ( V_5 -> V_11 ) ;
F_30 ( V_5 ) ;
V_59:
F_15 ( V_17 -> V_56 . V_30 , V_57 ) ;
return V_33 ;
}
static int F_31 ( struct V_16 * V_17 , void * V_6 )
{
F_32 ( V_17 ) ;
return 0 ;
}
static void F_33 ( struct V_51 * V_17 )
{
struct V_4 * V_5 = F_34 ( V_17 ) ;
int V_52 ;
F_35 ( & V_17 -> V_17 , NULL , F_31 ) ;
for ( V_52 = 0 ; V_52 < F_23 ( V_5 -> V_69 ) ; V_52 ++ )
F_36 ( V_5 -> V_69 [ V_52 ] ) ;
F_22 ( V_17 , NULL ) ;
F_19 ( V_5 -> V_11 ) ;
F_30 ( V_5 ) ;
F_15 ( V_17 -> V_56 . V_30 , V_57 ) ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_81 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_81 ) ;
}
