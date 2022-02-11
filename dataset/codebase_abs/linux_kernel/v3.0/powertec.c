static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_7 , V_5 -> V_8 + V_9 ) ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_10 , V_5 -> V_8 + V_9 ) ;
}
static void
F_4 ( struct V_11 * V_12 , int V_13 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
V_5 -> V_15 = V_13 ? V_16 : 0 ;
F_2 ( V_5 -> V_15 , V_5 -> V_8 + V_17 ) ;
}
static T_1 F_5 ( int V_18 , void * V_19 )
{
struct V_4 * V_5 = V_19 ;
return F_6 ( & V_5 -> V_5 ) ;
}
static T_2
F_7 ( struct V_11 * V_12 , struct V_20 * V_21 ,
T_3 V_22 , T_2 V_23 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
struct V_24 * V_25 = F_8 ( V_12 ) ;
int V_26 = V_5 -> V_5 . V_27 . V_28 ;
if ( V_5 -> V_5 . V_29 . V_30 & V_31 &&
V_23 == V_32 ) {
int V_33 , V_34 , V_35 ;
V_33 = F_9 ( & V_5 -> V_36 [ 0 ] , V_21 , V_37 ) ;
if ( V_22 == V_38 )
V_34 = V_39 ,
V_35 = V_40 ;
else
V_34 = V_41 ,
V_35 = V_42 ;
F_10 ( V_25 , V_5 -> V_36 , V_33 , V_34 ) ;
F_11 ( V_26 ) ;
F_12 ( V_26 , V_5 -> V_36 , V_33 ) ;
F_13 ( V_26 , V_35 ) ;
F_14 ( V_26 ) ;
return V_32 ;
}
return V_43 ;
}
static void
F_15 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
if ( V_5 -> V_5 . V_27 . V_28 != V_44 )
F_11 ( V_5 -> V_5 . V_27 . V_28 ) ;
}
const char * F_16 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
static char string [ 150 ] ;
sprintf ( string , L_1 ,
V_12 -> V_45 -> V_46 , V_5 -> V_5 . V_27 . type , V_5 -> V_2 -> V_47 ,
V_48 , V_5 -> V_15 ? L_2 : L_3 ) ;
return string ;
}
static int
F_17 ( struct V_11 * V_12 , char * V_49 , int V_50 )
{
int V_51 = V_50 ;
if ( V_50 >= 12 && strncmp ( V_49 , L_4 , 12 ) == 0 ) {
V_49 += 12 ;
V_50 -= 12 ;
if ( V_50 >= 5 && strncmp ( V_49 , L_5 , 5 ) == 0 ) {
if ( V_49 [ 5 ] == '1' )
F_4 ( V_12 , 1 ) ;
else if ( V_49 [ 5 ] == '0' )
F_4 ( V_12 , 0 ) ;
else
V_51 = - V_52 ;
} else
V_51 = - V_52 ;
} else
V_51 = - V_52 ;
return V_51 ;
}
int F_18 ( struct V_11 * V_12 , char * V_49 , char * * V_53 , T_4 V_54 ,
int V_50 , int V_55 )
{
struct V_4 * V_5 ;
char * V_56 = V_49 ;
int V_57 ;
if ( V_55 == 1 )
return F_17 ( V_12 , V_49 , V_50 ) ;
V_5 = (struct V_4 * ) V_12 -> V_14 ;
V_56 += sprintf ( V_56 , L_6 , V_48 ) ;
V_56 += F_19 ( & V_5 -> V_5 , V_56 ) ;
V_56 += sprintf ( V_56 , L_7 ,
V_5 -> V_15 ? L_2 : L_3 ) ;
V_56 += F_20 ( & V_5 -> V_5 , V_56 ) ;
V_56 += F_21 ( & V_5 -> V_5 , V_56 ) ;
* V_53 = V_49 + V_54 ;
V_57 = V_56 - V_49 - V_54 ;
if ( V_57 > V_50 )
V_57 = V_50 ;
return V_57 ;
}
static T_5 F_22 ( struct V_24 * V_25 , struct V_58 * V_59 , char * V_60 )
{
struct V_1 * V_2 = F_23 ( V_25 ) ;
struct V_11 * V_12 = F_24 ( V_2 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
return sprintf ( V_60 , L_8 , V_5 -> V_15 ? 1 : 0 ) ;
}
static T_5
F_25 ( struct V_24 * V_25 , struct V_58 * V_59 , const char * V_60 , T_6 V_61 )
{
struct V_1 * V_2 = F_23 ( V_25 ) ;
struct V_11 * V_12 = F_24 ( V_2 ) ;
if ( V_61 > 1 )
F_4 ( V_12 , V_60 [ 0 ] != '0' ) ;
return V_61 ;
}
static int T_7
F_26 ( struct V_1 * V_2 , const struct V_62 * V_63 )
{
struct V_11 * V_12 ;
struct V_4 * V_5 ;
void T_8 * V_8 ;
int V_51 ;
V_51 = F_27 ( V_2 ) ;
if ( V_51 )
goto V_64;
V_8 = F_28 ( V_2 , V_65 , 0 , 0 ) ;
if ( ! V_8 ) {
V_51 = - V_66 ;
goto V_67;
}
V_12 = F_29 ( & V_68 ,
sizeof ( struct V_4 ) ) ;
if ( ! V_12 ) {
V_51 = - V_66 ;
goto V_67;
}
F_30 ( V_2 , V_12 ) ;
V_5 = (struct V_4 * ) V_12 -> V_14 ;
V_5 -> V_8 = V_8 ;
F_4 ( V_12 , V_69 [ V_2 -> V_47 ] ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_5 . V_27 . V_70 = V_8 + V_71 ;
V_5 -> V_5 . V_27 . V_72 = V_73 ;
V_5 -> V_5 . V_27 . V_18 = V_2 -> V_18 ;
V_5 -> V_5 . V_27 . V_28 = V_2 -> V_28 ;
V_5 -> V_5 . V_29 . V_74 = 40 ;
V_5 -> V_5 . V_29 . V_75 = 255 ;
V_5 -> V_5 . V_29 . V_76 = 200 ;
V_5 -> V_5 . V_29 . V_77 = 7 ;
V_5 -> V_5 . V_29 . V_78 = V_79 | V_80 | V_81 ;
V_5 -> V_5 . V_29 . V_82 = 1 ;
V_5 -> V_5 . V_29 . V_83 = 0 ;
V_5 -> V_5 . V_29 . V_30 = 0 ;
V_5 -> V_5 . V_28 . V_84 = F_7 ;
V_5 -> V_5 . V_28 . V_85 = NULL ;
V_5 -> V_5 . V_28 . V_86 = F_15 ;
V_2 -> V_87 = V_8 + V_88 ;
V_2 -> V_89 = V_90 ;
F_31 ( V_2 , & V_91 , V_5 ) ;
F_32 ( & V_2 -> V_25 , & V_92 ) ;
V_51 = F_33 ( V_12 ) ;
if ( V_51 )
goto V_93;
V_51 = F_34 ( V_2 -> V_18 , F_5 ,
V_94 , L_9 , V_5 ) ;
if ( V_51 ) {
F_35 ( L_10 ,
V_12 -> V_95 , V_2 -> V_18 , V_51 ) ;
goto V_96;
}
if ( V_5 -> V_5 . V_27 . V_28 != V_44 ) {
if ( F_36 ( V_5 -> V_5 . V_27 . V_28 , L_9 ) ) {
F_35 ( L_11 ,
V_12 -> V_95 , V_5 -> V_5 . V_27 . V_28 ) ;
V_5 -> V_5 . V_27 . V_28 = V_44 ;
} else {
F_37 ( V_5 -> V_5 . V_27 . V_28 , 180 ) ;
V_5 -> V_5 . V_29 . V_30 |= V_31 ;
}
}
V_51 = F_38 ( V_12 , & V_2 -> V_25 ) ;
if ( V_51 == 0 )
goto V_64;
if ( V_5 -> V_5 . V_27 . V_28 != V_44 )
F_39 ( V_5 -> V_5 . V_27 . V_28 ) ;
F_40 ( V_2 -> V_18 , V_12 ) ;
V_96:
F_41 ( V_12 ) ;
V_93:
F_42 ( & V_2 -> V_25 , & V_92 ) ;
F_43 ( V_12 ) ;
V_67:
F_44 ( V_2 ) ;
V_64:
return V_51 ;
}
static void T_9 F_45 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_24 ( V_2 ) ;
struct V_4 * V_5 = (struct V_4 * ) V_12 -> V_14 ;
F_30 ( V_2 , NULL ) ;
F_46 ( V_12 ) ;
F_42 ( & V_2 -> V_25 , & V_92 ) ;
if ( V_5 -> V_5 . V_27 . V_28 != V_44 )
F_39 ( V_5 -> V_5 . V_27 . V_28 ) ;
F_40 ( V_2 -> V_18 , V_5 ) ;
F_41 ( V_12 ) ;
F_43 ( V_12 ) ;
F_44 ( V_2 ) ;
}
static int T_10 F_47 ( void )
{
return F_48 ( & V_97 ) ;
}
static void T_11 F_49 ( void )
{
F_50 ( & V_97 ) ;
}
