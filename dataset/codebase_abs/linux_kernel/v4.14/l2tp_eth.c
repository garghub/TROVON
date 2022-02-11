static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_5 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_10 = V_7 -> V_10 ;
int V_11 = F_9 ( V_9 , V_7 , V_9 -> V_12 ) ;
if ( F_10 ( V_11 == V_13 ) ) {
F_11 ( V_10 , & V_4 -> V_14 ) ;
F_12 ( & V_4 -> V_15 ) ;
} else {
F_12 ( & V_4 -> V_16 ) ;
}
return V_17 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_19 -> V_14 = ( unsigned long ) F_14 ( & V_4 -> V_14 ) ;
V_19 -> V_15 = ( unsigned long ) F_14 ( & V_4 -> V_15 ) ;
V_19 -> V_16 = ( unsigned long ) F_14 ( & V_4 -> V_16 ) ;
V_19 -> V_20 = ( unsigned long ) F_14 ( & V_4 -> V_20 ) ;
V_19 -> V_21 = ( unsigned long ) F_14 ( & V_4 -> V_21 ) ;
V_19 -> V_22 = ( unsigned long ) F_14 ( & V_4 -> V_22 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 , & V_23 ) ;
F_17 ( V_2 ) ;
V_2 -> V_24 &= ~ V_25 ;
V_2 -> V_26 |= V_27 ;
V_2 -> V_28 = & V_29 ;
V_2 -> V_30 = true ;
}
static void F_18 ( struct V_8 * V_9 , struct V_6 * V_7 , int V_31 )
{
struct V_32 * V_33 = F_19 ( V_9 ) ;
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_9 -> V_34 & V_35 ) {
unsigned int V_36 ;
V_36 = F_20 ( 32u , V_7 -> V_10 ) ;
if ( ! F_21 ( V_7 , V_36 ) )
goto error;
F_22 ( L_1 , V_9 -> V_37 ) ;
F_23 ( L_2 , V_38 , V_7 -> V_39 , V_36 ) ;
}
if ( ! F_21 ( V_7 , V_40 ) )
goto error;
F_24 ( V_7 ) ;
V_7 -> V_41 = V_42 ;
F_25 ( V_7 ) ;
F_26 ( V_7 ) ;
if ( F_27 ( V_2 , V_7 ) == V_43 ) {
F_12 ( & V_4 -> V_21 ) ;
F_11 ( V_31 , & V_4 -> V_20 ) ;
} else {
F_12 ( & V_4 -> V_22 ) ;
}
return;
error:
F_12 ( & V_4 -> V_22 ) ;
F_28 ( V_7 ) ;
}
static void F_29 ( struct V_8 * V_9 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
if ( V_9 ) {
V_33 = F_19 ( V_9 ) ;
V_2 = V_33 -> V_2 ;
if ( V_2 ) {
F_30 ( V_2 ) ;
V_33 -> V_2 = NULL ;
F_31 ( V_44 ) ;
}
}
}
static void F_32 ( struct V_45 * V_46 , void * V_47 )
{
struct V_8 * V_9 = V_47 ;
struct V_32 * V_33 = F_19 ( V_9 ) ;
struct V_1 * V_2 = V_33 -> V_2 ;
F_33 ( V_46 , L_3 , V_2 -> V_37 ) ;
}
static void F_34 ( struct V_48 * V_49 ,
struct V_8 * V_9 ,
struct V_1 * V_2 )
{
unsigned int V_50 = 0 ;
struct V_51 * V_52 ;
T_1 V_53 = 0 ;
if ( V_49 -> V_54 == V_55 ) {
V_50 += sizeof( struct V_56 ) ;
V_2 -> V_57 += sizeof( struct V_56 ) ;
}
if ( V_9 -> V_58 != 0 ) {
V_2 -> V_58 = V_9 -> V_58 ;
V_2 -> V_57 += V_9 -> V_12 ;
return;
}
F_35 ( V_49 -> V_59 ) ;
V_53 = F_36 ( V_49 -> V_59 ) ;
F_37 ( V_49 -> V_59 ) ;
if ( V_53 == 0 ) {
return;
}
V_50 += V_9 -> V_12 + V_40 + V_53 ;
V_52 = F_38 ( V_49 -> V_59 ) ;
if ( V_52 ) {
T_1 V_60 = F_39 ( V_52 ) ;
if ( V_60 != 0 )
V_2 -> V_58 = V_60 ;
F_40 ( V_52 ) ;
}
V_9 -> V_58 = V_2 -> V_58 - V_50 ;
V_2 -> V_58 = V_9 -> V_58 ;
V_2 -> V_57 += V_9 -> V_12 ;
}
static int F_41 ( struct V_61 * V_61 , struct V_48 * V_49 ,
T_1 V_62 , T_1 V_63 ,
struct V_64 * V_65 )
{
unsigned char V_66 ;
struct V_1 * V_2 ;
char V_37 [ V_67 ] ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
struct V_32 * V_33 ;
int V_68 ;
if ( V_65 -> V_69 ) {
F_42 ( V_37 , V_65 -> V_69 , V_67 ) ;
V_66 = V_70 ;
} else {
strcpy ( V_37 , V_71 ) ;
V_66 = V_72 ;
}
V_9 = F_43 ( sizeof( * V_33 ) , V_49 , V_62 ,
V_63 , V_65 ) ;
if ( F_44 ( V_9 ) ) {
V_68 = F_45 ( V_9 ) ;
goto V_73;
}
V_2 = F_46 ( sizeof( * V_4 ) , V_37 , V_66 ,
F_15 ) ;
if ( ! V_2 ) {
V_68 = - V_74 ;
goto V_75;
}
F_47 ( V_2 , V_61 ) ;
V_2 -> V_76 = 0 ;
V_2 -> V_77 = V_78 ;
F_34 ( V_49 , V_9 , V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_79 = V_49 -> V_59 ;
V_9 -> V_80 = F_18 ;
V_9 -> V_81 = F_29 ;
#if F_48 ( V_82 )
V_9 -> V_83 = F_32 ;
#endif
V_33 = F_19 ( V_9 ) ;
V_33 -> V_2 = V_2 ;
V_68 = F_49 ( V_2 ) ;
if ( V_68 < 0 )
goto V_84;
F_50 ( V_44 ) ;
F_42 ( V_9 -> V_69 , V_2 -> V_37 , V_67 ) ;
F_51 ( V_2 ) ;
return 0 ;
V_84:
F_52 ( V_2 ) ;
V_33 -> V_2 = NULL ;
V_75:
F_53 ( V_9 ) ;
V_73:
return V_68 ;
}
static int T_2 F_54 ( void )
{
int V_85 = 0 ;
V_85 = F_55 ( V_86 , & V_87 ) ;
if ( V_85 )
goto V_85;
F_56 ( L_4 ) ;
return 0 ;
V_85:
return V_85 ;
}
static void T_3 F_57 ( void )
{
F_58 ( V_86 ) ;
}
