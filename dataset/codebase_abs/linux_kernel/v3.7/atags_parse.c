static int T_1 F_1 ( const struct V_1 * V_1 )
{
if ( V_1 -> V_2 . V_3 > 2 ) {
if ( ( V_1 -> V_4 . V_5 . V_6 & 1 ) == 0 )
V_7 &= ~ V_8 ;
V_9 = F_2 ( V_1 -> V_4 . V_5 . V_10 ) ;
}
return 0 ;
}
static int T_1 F_3 ( const struct V_1 * V_1 )
{
return F_4 ( V_1 -> V_4 . V_11 . V_12 , V_1 -> V_4 . V_11 . V_3 ) ;
}
static int T_1 F_5 ( const struct V_1 * V_1 )
{
V_13 . V_14 = V_1 -> V_4 . V_15 . V_16 ;
V_13 . V_17 = V_1 -> V_4 . V_15 . V_18 ;
V_13 . V_19 = V_1 -> V_4 . V_15 . V_20 ;
V_13 . V_21 = V_1 -> V_4 . V_15 . V_22 ;
V_13 . V_23 = V_1 -> V_4 . V_15 . V_24 ;
V_13 . V_25 = V_1 -> V_4 . V_15 . V_26 ;
V_13 . V_27 = V_1 -> V_4 . V_15 . V_28 ;
V_13 . V_29 = V_1 -> V_4 . V_15 . V_30 ;
V_13 . V_31 = V_1 -> V_4 . V_15 . V_32 ;
return 0 ;
}
static int T_1 F_6 ( const struct V_1 * V_1 )
{
extern int V_33 , V_34 , V_35 , V_36 ;
V_34 = V_1 -> V_4 . V_37 . V_12 ;
V_36 = ( V_1 -> V_4 . V_37 . V_6 & 1 ) == 0 ;
V_35 = ( V_1 -> V_4 . V_37 . V_6 & 2 ) == 0 ;
if ( V_1 -> V_4 . V_37 . V_3 )
V_33 = V_1 -> V_4 . V_37 . V_3 ;
return 0 ;
}
static int T_1 F_7 ( const struct V_1 * V_1 )
{
V_38 = V_1 -> V_4 . V_39 . V_40 ;
V_41 = V_1 -> V_4 . V_39 . V_42 ;
return 0 ;
}
static int T_1 F_8 ( const struct V_1 * V_1 )
{
V_43 = V_1 -> V_4 . V_44 . V_45 ;
return 0 ;
}
static int T_1 F_9 ( const struct V_1 * V_1 )
{
#if F_10 ( V_46 )
F_11 ( V_47 , L_1 , V_48 ) ;
F_11 ( V_47 , V_1 -> V_4 . V_49 . V_49 ,
V_48 ) ;
#elif F_10 ( V_50 )
F_12 ( L_2 ) ;
#else
F_13 ( V_47 , V_1 -> V_4 . V_49 . V_49 ,
V_48 ) ;
#endif
return 0 ;
}
static int T_1 F_14 ( const struct V_1 * V_1 )
{
extern struct V_51 V_52 , V_53 ;
struct V_51 * V_54 ;
for ( V_54 = & V_52 ; V_54 < & V_53 ; V_54 ++ )
if ( V_1 -> V_2 . V_1 == V_54 -> V_1 ) {
V_54 -> V_55 ( V_1 ) ;
break;
}
return V_54 < & V_53 ;
}
static void T_1 F_15 ( const struct V_1 * V_54 )
{
for (; V_54 -> V_2 . V_3 ; V_54 = F_16 ( V_54 ) )
if ( ! F_14 ( V_54 ) )
F_17 ( V_56
L_3 ,
V_54 -> V_2 . V_1 ) ;
}
static void T_1 F_18 ( struct V_1 * V_1 )
{
for (; V_1 -> V_2 . V_3 ; V_1 = F_16 ( V_1 ) )
if ( V_1 -> V_2 . V_1 == V_57 )
V_1 -> V_2 . V_1 = V_58 ;
}
struct V_59 * T_1 F_19 ( T_2 V_60 ,
unsigned int V_61 )
{
struct V_1 * V_62 = (struct V_1 * ) & V_63 ;
struct V_59 * V_64 = NULL , * V_65 ;
char * V_66 = V_47 ;
V_63 . V_11 . V_12 = V_67 ;
F_20 (p)
if ( V_61 == V_65 -> V_68 ) {
F_17 ( L_4 , V_65 -> V_69 ) ;
V_64 = V_65 ;
break;
}
if ( ! V_64 ) {
F_21 ( L_5
L_6 , V_61 ) ;
F_22 () ;
}
if ( V_60 )
V_62 = F_23 ( V_60 ) ;
else if ( V_64 -> V_70 )
V_62 = ( void * ) ( V_71 + V_64 -> V_70 ) ;
#if F_10 ( V_72 )
if ( V_62 -> V_2 . V_1 != V_73 )
F_24 ( V_62 ) ;
#endif
if ( V_62 -> V_2 . V_1 != V_73 ) {
F_21 ( L_7 ) ;
V_62 = (struct V_1 * ) & V_63 ;
}
if ( V_64 -> V_74 )
V_64 -> V_74 ( V_62 , & V_66 , & V_75 ) ;
if ( V_62 -> V_2 . V_1 == V_73 ) {
if ( V_75 . V_76 != 0 )
F_18 ( V_62 ) ;
F_25 ( V_62 ) ;
F_15 ( V_62 ) ;
}
F_13 ( V_77 , V_66 , V_48 ) ;
return V_64 ;
}
