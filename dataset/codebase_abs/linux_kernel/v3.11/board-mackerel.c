static int F_1 ( int V_1 )
{
F_2 ( 31 , V_1 ) ;
return 0 ;
}
static void T_1 F_3 ( void )
{
struct V_2 * V_3 = F_4 ( & V_4 . V_5 , L_1 ) ;
int V_6 ;
long V_7 ;
if ( F_5 ( V_3 ) ) {
V_6 = F_6 ( V_3 ) ;
F_7 ( L_2 , V_6 ) ;
goto V_8;
}
V_6 = F_8 ( & V_9 , & V_10 ) ;
if ( V_6 < 0 ) {
F_7 ( L_3 ,
V_6 , V_9 . V_11 ) ;
goto V_8;
}
F_9 ( L_4 ,
F_10 ( & V_9 ) ) ;
V_7 = F_11 ( & V_9 , 594000000 ) ;
if ( V_7 < 0 ) {
F_7 ( L_5 , V_7 ) ;
V_6 = V_7 ;
goto V_8;
}
V_6 = F_12 ( & V_9 , V_7 ) ;
if ( V_6 < 0 ) {
F_7 ( L_6 , V_7 , V_6 ) ;
goto V_8;
}
F_9 ( L_7 , V_7 ) ;
V_6 = F_8 ( V_3 , & V_9 ) ;
if ( V_6 < 0 )
F_7 ( L_8 , V_6 ) ;
V_8:
if ( ! F_5 ( V_3 ) )
F_13 ( V_3 ) ;
}
static int F_14 ( struct V_12 * V_13 )
{
return F_15 ( F_16 ( V_13 ) ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_16 ( V_13 ) ;
F_18 ( 0x8a0a , V_15 -> V_16 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 )
{
return V_17 ;
}
static void F_20 ( struct V_18 * V_19 )
{
struct V_14 * V_15 = F_21 ( V_19 , struct V_14 ,
V_19 . V_19 ) ;
F_22 ( V_15 -> V_13 ) ;
F_23 ( & V_15 -> V_19 , V_20 ) ;
}
static int F_24 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_16 ( V_13 ) ;
V_15 -> V_13 = V_13 ;
F_25 ( & V_15 -> V_19 , F_20 ) ;
F_23 ( & V_15 -> V_19 , V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_16 ( V_13 ) ;
F_27 ( & V_15 -> V_19 ) ;
return 0 ;
}
static T_2 F_28 ( int V_21 , void * V_22 )
{
struct V_12 * V_13 = V_22 ;
struct V_14 * V_15 = F_16 ( V_13 ) ;
F_29 ( & V_13 -> V_5 , L_9 , V_23 ) ;
F_22 ( V_13 ) ;
F_18 ( F_30 ( V_15 -> V_24 ) | V_25 ,
V_15 -> V_24 ) ;
return V_26 ;
}
static int F_31 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_16 ( V_13 ) ;
int V_6 ;
F_18 ( V_27 | V_25 , V_15 -> V_24 ) ;
V_6 = F_32 ( V_28 , F_28 , V_29 ,
F_33 ( & V_13 -> V_5 ) , V_13 ) ;
if ( V_6 ) {
F_34 ( & V_13 -> V_5 , L_10 ) ;
return V_6 ;
}
F_18 ( V_27 | V_30 , V_15 -> V_24 ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_16 ( V_13 ) ;
F_18 ( V_27 | V_25 , V_15 -> V_24 ) ;
F_36 ( V_28 , V_13 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 )
{
return V_31 ;
}
static int F_38 ( struct V_32 * V_33 ,
int V_34 )
{
return 0 ;
}
static void F_39 ( struct V_35 * V_5 )
{
F_40 ( & V_36 ) ;
}
static int F_41 ( struct V_37 * V_38 )
{
return F_42 ( V_38 , & V_36 , & V_39 ,
F_39 , 0 ) ;
}
static void F_43 ( struct V_37 * V_38 )
{
F_44 ( V_38 , V_36 , & V_39 ) ;
}
static void T_1 F_45 ( void )
{
struct V_40 V_41 [] = {
{ L_11 , & V_42 , } ,
{ L_11 , & V_43 , } ,
{ L_11 , & V_44 , } ,
{ L_12 , & V_45 , } ,
{ L_13 , & V_46 , } ,
{ L_13 , & V_47 , } ,
{ L_13 , & V_48 , } ,
{ L_13 , & V_49 , } ,
#if ! F_46 ( V_50 )
{ L_13 , & V_51 , } ,
#else
{ L_13 , & V_52 , } ,
#endif
{ L_13 , & V_53 , } ,
{ L_14 , & V_54 , } ,
} ;
T_3 V_55 ;
struct V_2 * V_2 ;
F_47 ( 0 , L_15 , V_56 ,
F_48 ( V_56 ) , 1800000 ) ;
F_47 ( 1 , L_16 , V_57 ,
F_48 ( V_57 ) , 3300000 ) ;
F_49 ( 2 , V_58 , F_48 ( V_58 ) ) ;
F_12 ( & V_59 , 27000000 ) ;
F_50 ( V_60 ,
F_48 ( V_60 ) ) ;
F_51 () ;
F_52 ( 31 , V_61 , NULL ) ;
F_52 ( 151 , V_62 , NULL ) ;
F_53 ( V_63 ) ;
F_53 ( V_64 ) ;
F_52 ( 161 , V_61 , NULL ) ;
F_54 ( 9 , NULL ) ;
F_54 ( 10 , NULL ) ;
F_55 ( V_65 ) ;
F_55 ( V_66 ) ;
F_56 ( V_67 , 3 ) ;
F_18 ( F_30 ( V_68 ) & ~ ( 1 << 6 ) , V_68 ) ;
V_2 = F_4 ( NULL , L_17 ) ;
if ( ! F_5 ( V_2 ) ) {
F_12 ( V_2 , F_11 ( V_2 , 119600000 ) ) ;
F_13 ( V_2 ) ;
}
F_57 ( V_69 , V_70 ) ;
F_57 ( V_71 , V_72 ) ;
F_57 ( V_73 , V_70 ) ;
V_55 = F_58 ( V_74 ) ;
F_59 ( V_55 | ( 1 << 13 ) , V_74 ) ;
F_60 ( 50 ) ;
F_59 ( V_55 & ~ ( 1 << 13 ) , V_74 ) ;
F_61 ( 0 , V_75 ,
F_48 ( V_75 ) ) ;
F_61 ( 1 , V_76 ,
F_48 ( V_76 ) ) ;
F_62 () ;
F_63 ( V_77 , F_48 ( V_77 ) ) ;
F_64 ( V_41 ,
F_48 ( V_41 ) ) ;
F_3 () ;
F_65 () ;
F_66 ( & V_45 . V_5 , L_18 ) ;
F_66 ( & V_43 . V_5 , L_19 ) ;
}
