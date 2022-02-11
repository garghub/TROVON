static unsigned int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == & V_4 )
return sizeof( struct V_5 * ) ;
if ( V_2 -> V_3 == & V_6 ||
V_2 -> V_3 == & V_7 )
return sizeof( struct V_8 * ) ;
return F_2 ( V_2 ) ;
}
static int F_3 ( struct V_9 * V_10 ,
const T_1 * V_11 , unsigned int V_12 )
{
struct V_5 * * V_13 = F_4 ( V_10 ) ;
struct V_5 * V_14 = * V_13 ;
int V_15 ;
F_5 ( V_14 , ~ 0 ) ;
F_6 ( V_14 , F_7 ( V_10 ) &
V_16 ) ;
V_15 = F_8 ( V_14 , V_11 , V_12 ) ;
F_9 ( V_10 , F_10 ( V_14 ) &
V_17 ) ;
return V_15 ;
}
static int F_11 ( struct V_18 * V_19 ,
int (* F_12)( struct V_20 * ,
struct V_21 * ,
struct V_21 * ,
unsigned int ) )
{
struct V_9 * V_10 = F_13 ( V_19 ) ;
struct V_5 * * V_13 = F_4 ( V_10 ) ;
struct V_20 V_22 = {
. V_10 = * V_13 ,
. V_23 = V_19 -> V_24 ,
. V_25 = V_19 -> V_26 . V_25 ,
} ;
return F_12 ( & V_22 , V_19 -> V_27 , V_19 -> V_28 , V_19 -> V_29 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_32 * V_2 = & V_10 -> V_33 -> V_34 ;
return F_11 ( V_19 , V_2 -> V_35 ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_32 * V_2 = & V_10 -> V_33 -> V_34 ;
return F_11 ( V_19 , V_2 -> V_36 ) ;
}
static void F_17 ( struct V_31 * V_10 )
{
struct V_5 * * V_13 = F_18 ( V_10 ) ;
F_19 ( * V_13 ) ;
}
static int F_20 ( struct V_31 * V_10 )
{
struct V_1 * V_37 = V_10 -> V_33 ;
struct V_9 * V_30 = F_21 ( V_10 ) ;
struct V_5 * * V_13 = F_18 ( V_10 ) ;
struct V_5 * V_14 ;
struct V_31 * V_38 ;
if ( ! F_22 ( V_37 ) )
return - V_39 ;
V_38 = F_23 ( V_37 , V_40 ,
V_41 ) ;
if ( F_24 ( V_38 ) ) {
F_25 ( V_37 ) ;
return F_26 ( V_38 ) ;
}
V_14 = F_27 ( V_38 ) ;
* V_13 = V_14 ;
V_10 -> exit = F_17 ;
V_30 -> V_42 = F_3 ;
V_30 -> V_35 = F_14 ;
V_30 -> V_36 = F_16 ;
V_30 -> V_43 = F_28 ( V_14 ) ;
V_30 -> V_44 = V_37 -> V_34 . V_45 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 ,
const T_1 * V_11 , unsigned int V_12 )
{
struct V_8 * * V_13 = F_4 ( V_10 ) ;
struct V_8 * V_46 = * V_13 ;
int V_15 ;
F_30 ( V_46 , ~ 0 ) ;
F_31 ( V_46 ,
F_7 ( V_10 ) &
V_16 ) ;
V_15 = F_32 ( V_46 , V_11 , V_12 ) ;
F_9 ( V_10 ,
F_33 ( V_46 ) &
V_17 ) ;
return V_15 ;
}
static int F_34 ( struct V_18 * V_19 ,
int (* F_12)( struct V_47 * ) )
{
struct V_9 * V_10 = F_13 ( V_19 ) ;
struct V_8 * * V_13 = F_4 ( V_10 ) ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
F_36 ( V_48 , * V_13 ) ;
F_37 ( V_48 , F_38 ( V_19 ) ,
V_19 -> V_26 . V_49 , V_19 -> V_26 . V_50 ) ;
F_39 ( V_48 , V_19 -> V_28 , V_19 -> V_27 , V_19 -> V_29 ,
V_19 -> V_24 ) ;
return F_12 ( V_48 ) ;
}
static int F_40 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_51 * V_2 = & V_10 -> V_33 -> V_52 ;
return F_34 ( V_19 , V_2 -> V_35 ) ;
}
static int F_41 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_51 * V_2 = & V_10 -> V_33 -> V_52 ;
return F_34 ( V_19 , V_2 -> V_36 ) ;
}
static void F_42 ( struct V_31 * V_10 )
{
struct V_8 * * V_13 = F_18 ( V_10 ) ;
F_43 ( * V_13 ) ;
}
static int F_44 ( struct V_31 * V_10 )
{
struct V_1 * V_37 = V_10 -> V_33 ;
struct V_9 * V_30 = F_21 ( V_10 ) ;
struct V_8 * * V_13 = F_18 ( V_10 ) ;
struct V_8 * V_46 ;
struct V_31 * V_53 ;
if ( ! F_22 ( V_37 ) )
return - V_39 ;
V_53 = F_23 ( V_37 , 0 , 0 ) ;
if ( F_24 ( V_53 ) ) {
F_25 ( V_37 ) ;
return F_26 ( V_53 ) ;
}
V_46 = F_45 ( V_53 ) ;
* V_13 = V_46 ;
V_10 -> exit = F_42 ;
V_30 -> V_42 = F_29 ;
V_30 -> V_35 = F_40 ;
V_30 -> V_36 = F_41 ;
V_30 -> V_43 = F_46 ( V_46 ) ;
V_30 -> V_54 = F_47 ( V_46 ) +
sizeof( struct V_47 ) ;
V_30 -> V_44 = V_37 -> V_52 . V_45 ;
return 0 ;
}
static void F_48 ( struct V_31 * V_10 )
{
struct V_9 * V_30 = F_21 ( V_10 ) ;
struct V_55 * V_2 = F_49 ( V_30 ) ;
V_2 -> exit ( V_30 ) ;
}
static int F_50 ( struct V_31 * V_10 )
{
struct V_9 * V_30 = F_21 ( V_10 ) ;
struct V_55 * V_2 = F_49 ( V_30 ) ;
if ( V_10 -> V_33 -> V_3 == & V_4 )
return F_20 ( V_10 ) ;
if ( V_10 -> V_33 -> V_3 == & V_6 ||
V_10 -> V_33 -> V_3 == & V_7 )
return F_44 ( V_10 ) ;
V_30 -> V_42 = V_2 -> V_42 ;
V_30 -> V_35 = V_2 -> V_35 ;
V_30 -> V_36 = V_2 -> V_36 ;
V_30 -> V_43 = V_2 -> V_43 ;
V_30 -> V_44 = V_2 -> V_45 ;
if ( V_2 -> exit )
V_30 -> V_26 . exit = F_48 ;
if ( V_2 -> V_56 )
return V_2 -> V_56 ( V_30 ) ;
return 0 ;
}
static void F_51 ( struct V_57 * V_58 )
{
struct V_59 * V_30 =
F_52 ( V_58 , struct V_59 , V_60 . V_26 ) ;
V_30 -> free ( V_30 ) ;
}
static void F_53 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
struct V_55 * V_30 = F_52 ( V_2 , struct V_55 ,
V_26 ) ;
F_54 ( V_62 , L_1 ) ;
F_54 ( V_62 , L_2 ,
V_2 -> V_63 & V_64 ? L_3 : L_4 ) ;
F_54 ( V_62 , L_5 , V_2 -> V_65 ) ;
F_54 ( V_62 , L_6 , V_30 -> V_66 ) ;
F_54 ( V_62 , L_7 , V_30 -> V_45 ) ;
F_54 ( V_62 , L_8 , V_30 -> V_43 ) ;
F_54 ( V_62 , L_9 , V_30 -> V_67 ) ;
}
static int F_55 ( struct V_68 * V_69 , struct V_1 * V_2 )
{
struct V_70 V_71 ;
struct V_55 * V_30 = F_52 ( V_2 , struct V_55 ,
V_26 ) ;
strncpy ( V_71 . type , L_10 , sizeof( V_71 . type ) ) ;
strncpy ( V_71 . V_72 , L_11 , sizeof( V_71 . V_72 ) ) ;
V_71 . V_73 = V_2 -> V_65 ;
V_71 . V_66 = V_30 -> V_66 ;
V_71 . V_45 = V_30 -> V_45 ;
V_71 . V_43 = V_30 -> V_43 ;
if ( F_56 ( V_69 , V_74 ,
sizeof( struct V_70 ) , & V_71 ) )
goto V_75;
return 0 ;
V_75:
return - V_76 ;
}
static int F_55 ( struct V_68 * V_69 , struct V_1 * V_2 )
{
return - V_77 ;
}
int F_57 ( struct V_78 * V_79 ,
const char * V_80 , T_2 type , T_2 V_81 )
{
V_79 -> V_26 . V_82 = & V_83 ;
return F_58 ( & V_79 -> V_26 , V_80 , type , V_81 ) ;
}
struct V_9 * F_59 ( const char * V_84 ,
T_2 type , T_2 V_81 )
{
return F_60 ( V_84 , & V_83 , type , V_81 ) ;
}
int F_61 ( const char * V_84 , T_2 type , T_2 V_81 )
{
return F_62 ( V_84 , & V_83 ,
type , V_81 ) ;
}
static int F_63 ( struct V_55 * V_2 )
{
struct V_1 * V_26 = & V_2 -> V_26 ;
if ( V_2 -> V_43 > V_85 / 8 || V_2 -> V_67 > V_85 / 8 )
return - V_86 ;
if ( ! V_2 -> V_67 )
V_2 -> V_67 = V_26 -> V_65 ;
V_26 -> V_3 = & V_83 ;
V_26 -> V_63 &= ~ V_41 ;
V_26 -> V_63 |= V_87 ;
return 0 ;
}
int F_64 ( struct V_55 * V_2 )
{
struct V_1 * V_26 = & V_2 -> V_26 ;
int V_15 ;
V_15 = F_63 ( V_2 ) ;
if ( V_15 )
return V_15 ;
return F_65 ( V_26 ) ;
}
void F_66 ( struct V_55 * V_2 )
{
F_67 ( & V_2 -> V_26 ) ;
}
int F_68 ( struct V_55 * V_88 , int V_89 )
{
int V_90 , V_91 ;
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ ) {
V_91 = F_64 ( & V_88 [ V_90 ] ) ;
if ( V_91 )
goto V_15;
}
return 0 ;
V_15:
for ( -- V_90 ; V_90 >= 0 ; -- V_90 )
F_66 ( & V_88 [ V_90 ] ) ;
return V_91 ;
}
void F_69 ( struct V_55 * V_88 , int V_89 )
{
int V_90 ;
for ( V_90 = V_89 - 1 ; V_90 >= 0 ; -- V_90 )
F_66 ( & V_88 [ V_90 ] ) ;
}
int F_70 ( struct V_92 * V_93 ,
struct V_59 * V_58 )
{
int V_15 ;
V_15 = F_63 ( & V_58 -> V_2 ) ;
if ( V_15 )
return V_15 ;
return F_71 ( V_93 , F_72 ( V_58 ) ) ;
}
