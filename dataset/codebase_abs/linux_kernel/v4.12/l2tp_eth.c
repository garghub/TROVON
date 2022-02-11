static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
F_5 ( V_5 ) ;
F_6 ( V_5 -> V_8 ) ;
F_7 ( V_5 ) ;
return 0 ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( F_9 ( V_5 ) ) ;
F_10 ( & V_9 -> V_10 ) ;
F_11 ( & V_7 -> V_11 ) ;
F_12 ( & V_9 -> V_10 ) ;
F_13 ( V_5 ) ;
}
static int F_14 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_14 * V_15 = V_7 -> V_15 ;
unsigned int V_16 = V_13 -> V_16 ;
int V_17 = F_15 ( V_15 , V_13 , V_15 -> V_18 ) ;
if ( F_16 ( V_17 == V_19 ) ) {
F_17 ( V_16 , & V_7 -> V_20 ) ;
F_18 ( & V_7 -> V_21 ) ;
} else {
F_18 ( & V_7 -> V_22 ) ;
}
return V_23 ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
V_25 -> V_20 = ( unsigned long ) F_20 ( & V_7 -> V_20 ) ;
V_25 -> V_21 = ( unsigned long ) F_20 ( & V_7 -> V_21 ) ;
V_25 -> V_22 = ( unsigned long ) F_20 ( & V_7 -> V_22 ) ;
V_25 -> V_26 = ( unsigned long ) F_20 ( & V_7 -> V_26 ) ;
V_25 -> V_27 = ( unsigned long ) F_20 ( & V_7 -> V_27 ) ;
V_25 -> V_28 = ( unsigned long ) F_20 ( & V_7 -> V_28 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_22 ( V_5 , & V_29 ) ;
F_23 ( V_5 ) ;
V_5 -> V_30 &= ~ V_31 ;
V_5 -> V_32 |= V_33 ;
V_5 -> V_34 = & V_35 ;
V_5 -> V_36 = true ;
}
static void F_24 ( struct V_14 * V_15 , struct V_12 * V_13 , int V_37 )
{
struct V_38 * V_39 = F_25 ( V_15 ) ;
struct V_4 * V_5 = V_39 -> V_5 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
if ( V_15 -> V_40 & V_41 ) {
unsigned int V_42 ;
V_42 = F_26 ( 32u , V_13 -> V_16 ) ;
if ( ! F_27 ( V_13 , V_42 ) )
goto error;
F_28 ( L_1 , V_15 -> V_43 ) ;
F_29 ( L_2 , V_44 , V_13 -> V_45 , V_42 ) ;
}
if ( ! F_27 ( V_13 , V_46 ) )
goto error;
F_30 ( V_13 ) ;
V_13 -> V_47 = V_48 ;
F_31 ( V_13 ) ;
F_32 ( V_13 ) ;
if ( F_33 ( V_5 , V_13 ) == V_49 ) {
F_18 ( & V_7 -> V_27 ) ;
F_17 ( V_37 , & V_7 -> V_26 ) ;
} else {
F_18 ( & V_7 -> V_28 ) ;
}
return;
error:
F_18 ( & V_7 -> V_28 ) ;
F_34 ( V_13 ) ;
}
static void F_35 ( struct V_14 * V_15 )
{
struct V_38 * V_39 ;
struct V_4 * V_5 ;
if ( V_15 ) {
V_39 = F_25 ( V_15 ) ;
V_5 = V_39 -> V_5 ;
if ( V_5 ) {
F_36 ( V_5 ) ;
V_39 -> V_5 = NULL ;
F_37 ( V_50 ) ;
}
}
}
static void F_38 ( struct V_51 * V_52 , void * V_53 )
{
struct V_14 * V_15 = V_53 ;
struct V_38 * V_39 = F_25 ( V_15 ) ;
struct V_4 * V_5 = V_39 -> V_5 ;
F_39 ( V_52 , L_3 , V_5 -> V_43 ) ;
}
static void F_40 ( struct V_54 * V_55 ,
struct V_14 * V_15 ,
struct V_4 * V_5 )
{
unsigned int V_56 = 0 ;
struct V_57 * V_58 ;
T_1 V_59 = 0 ;
if ( V_55 -> V_60 == V_61 ) {
V_56 += sizeof( struct V_62 ) ;
V_5 -> V_63 += sizeof( struct V_62 ) ;
}
if ( V_15 -> V_64 != 0 ) {
V_5 -> V_64 = V_15 -> V_64 ;
V_5 -> V_63 += V_15 -> V_18 ;
return;
}
F_41 ( V_55 -> V_65 ) ;
V_59 = F_42 ( V_55 -> V_65 ) ;
F_43 ( V_55 -> V_65 ) ;
if ( V_59 == 0 ) {
return;
}
V_56 += V_15 -> V_18 + V_46 + V_59 ;
V_58 = F_44 ( V_55 -> V_65 ) ;
if ( V_58 ) {
T_1 V_66 = F_45 ( V_58 ) ;
if ( V_66 != 0 )
V_5 -> V_64 = V_66 ;
F_46 ( V_58 ) ;
}
V_15 -> V_64 = V_5 -> V_64 - V_56 ;
V_5 -> V_64 = V_15 -> V_64 ;
V_5 -> V_63 += V_15 -> V_18 ;
}
static int F_47 ( struct V_2 * V_2 , T_1 V_67 , T_1 V_68 , T_1 V_69 , struct V_70 * V_71 )
{
unsigned char V_72 ;
struct V_4 * V_5 ;
char V_43 [ V_73 ] ;
struct V_54 * V_55 ;
struct V_14 * V_15 ;
struct V_6 * V_7 ;
struct V_38 * V_39 ;
int V_74 ;
struct V_1 * V_9 ;
V_55 = F_48 ( V_2 , V_67 ) ;
if ( ! V_55 ) {
V_74 = - V_75 ;
goto V_76;
}
if ( V_71 -> V_77 ) {
F_49 ( V_43 , V_71 -> V_77 , V_73 ) ;
V_72 = V_78 ;
} else {
strcpy ( V_43 , V_79 ) ;
V_72 = V_80 ;
}
V_15 = F_50 ( sizeof( * V_39 ) , V_55 , V_68 ,
V_69 , V_71 ) ;
if ( F_51 ( V_15 ) ) {
V_74 = F_52 ( V_15 ) ;
goto V_76;
}
V_5 = F_53 ( sizeof( * V_7 ) , V_43 , V_72 ,
F_21 ) ;
if ( ! V_5 ) {
V_74 = - V_81 ;
goto V_82;
}
F_54 ( V_5 , V_2 ) ;
V_5 -> V_83 = 0 ;
V_5 -> V_84 = V_85 ;
F_40 ( V_55 , V_15 , V_5 ) ;
V_7 = F_4 ( V_5 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_15 = V_15 ;
F_55 ( & V_7 -> V_11 ) ;
V_7 -> V_86 = V_55 -> V_65 ;
V_15 -> V_87 = F_24 ;
V_15 -> V_88 = F_35 ;
#if F_56 ( V_89 )
V_15 -> V_90 = F_38 ;
#endif
V_39 = F_25 ( V_15 ) ;
V_39 -> V_5 = V_5 ;
V_74 = F_57 ( V_5 ) ;
if ( V_74 < 0 )
goto V_91;
F_58 ( V_50 ) ;
F_49 ( V_15 -> V_77 , V_5 -> V_43 , V_73 ) ;
F_59 ( V_5 ) ;
V_9 = F_1 ( F_9 ( V_5 ) ) ;
F_10 ( & V_9 -> V_10 ) ;
F_60 ( & V_7 -> V_11 , & V_9 -> V_92 ) ;
F_12 ( & V_9 -> V_10 ) ;
return 0 ;
V_91:
F_61 ( V_5 ) ;
V_39 -> V_5 = NULL ;
V_82:
F_62 ( V_15 ) ;
V_76:
return V_74 ;
}
static T_2 int F_63 ( struct V_2 * V_2 )
{
struct V_1 * V_9 = F_2 ( V_2 , V_3 ) ;
F_55 ( & V_9 -> V_92 ) ;
F_64 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int T_3 F_65 ( void )
{
int V_93 = 0 ;
V_93 = F_66 ( V_94 , & V_95 ) ;
if ( V_93 )
goto V_76;
V_93 = F_67 ( & V_96 ) ;
if ( V_93 )
goto V_97;
F_68 ( L_4 ) ;
return 0 ;
V_97:
F_69 ( V_94 ) ;
V_76:
return V_93 ;
}
static void T_4 F_70 ( void )
{
F_71 ( & V_96 ) ;
F_69 ( V_94 ) ;
}
