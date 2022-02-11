static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 ;
int V_10 , V_11 ;
bool V_12 = F_3 ( V_2 -> V_13 ) & V_14 ;
if ( F_4 ( ! F_5 ( V_2 ) ) )
return V_15 ;
F_6 ( & V_7 -> V_16 ) ;
F_7 ( F_8 ( V_7 -> V_17 . V_18 ) , V_2 ) ;
F_9 () ;
V_9 = F_10 ( V_7 -> V_9 ) ;
if ( V_12 ) {
F_11 ( V_2 , V_2 -> V_19 ) ;
F_12 ( V_2 ) ;
V_11 = F_13 ( V_9 , V_2 ) ;
F_14 ( V_2 , V_2 -> V_19 ) ;
} else {
F_12 ( V_2 ) ;
V_11 = F_13 ( V_9 , V_2 ) ;
}
F_15 () ;
switch ( V_11 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_10 = V_11 ;
break;
case V_24 :
V_10 = V_11 ;
F_16 ( F_8 ( V_7 -> V_17 . V_25 ) ) ;
break;
case V_15 :
V_10 = V_7 -> V_26 ;
break;
default:
V_10 = V_15 ;
break;
}
return V_10 ;
}
static bool F_17 ( const struct F_1 * V_7 )
{
return ! V_7 -> V_27 ;
}
static int F_18 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 ;
if ( F_19 ( V_2 , V_30 , V_7 -> V_31 ) )
return - V_32 ;
V_29 = F_20 ( V_2 , V_33 , V_7 -> V_31 *
sizeof( struct V_34 ) ) ;
if ( V_29 == NULL )
return - V_32 ;
memcpy ( F_21 ( V_29 ) , V_7 -> V_27 , F_22 ( V_29 ) ) ;
return 0 ;
}
static int F_23 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
if ( F_24 ( V_2 , V_35 , V_7 -> V_36 ) )
return - V_32 ;
if ( V_7 -> V_37 &&
F_25 ( V_2 , V_38 , V_7 -> V_37 ) )
return - V_32 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_39 , int V_40 )
{
unsigned char * V_41 = F_27 ( V_2 ) ;
struct F_1 * V_7 = F_2 ( V_4 ) ;
struct V_42 V_43 = {
. V_44 = V_7 -> V_45 ,
. V_46 = V_7 -> V_47 - V_40 ,
. V_48 = V_7 -> V_49 - V_39 ,
. V_10 = V_7 -> V_26 ,
} ;
struct V_50 V_51 ;
int V_52 ;
if ( F_28 ( V_2 , V_53 , sizeof( V_43 ) , & V_43 ) )
goto V_54;
if ( F_17 ( V_7 ) )
V_52 = F_23 ( V_7 , V_2 ) ;
else
V_52 = F_18 ( V_7 , V_2 ) ;
if ( V_52 )
goto V_54;
F_29 ( & V_51 , & V_7 -> V_16 ) ;
if ( F_30 ( V_2 , V_55 , sizeof( V_51 ) , & V_51 ,
V_56 ) )
goto V_54;
return V_2 -> V_57 ;
V_54:
F_31 ( V_2 , V_41 ) ;
return - 1 ;
}
static int F_32 ( struct V_28 * * V_58 , struct V_59 * V_60 )
{
struct V_34 * V_27 ;
struct V_61 V_62 ;
struct V_8 * V_63 ;
T_1 V_64 , V_31 ;
int V_52 ;
V_31 = F_33 ( V_58 [ V_30 ] ) ;
if ( V_31 > V_65 || V_31 == 0 )
return - V_66 ;
V_64 = V_31 * sizeof( * V_27 ) ;
if ( V_64 != F_22 ( V_58 [ V_33 ] ) )
return - V_66 ;
V_27 = F_34 ( V_64 , V_67 ) ;
if ( V_27 == NULL )
return - V_68 ;
memcpy ( V_27 , F_21 ( V_58 [ V_33 ] ) , V_64 ) ;
V_62 . V_57 = V_31 ;
V_62 . V_9 = V_27 ;
V_52 = F_35 ( & V_63 , & V_62 ) ;
if ( V_52 < 0 ) {
F_36 ( V_27 ) ;
return V_52 ;
}
V_60 -> V_27 = V_27 ;
V_60 -> V_31 = V_31 ;
V_60 -> V_9 = V_63 ;
V_60 -> V_69 = false ;
return 0 ;
}
static int F_37 ( struct V_28 * * V_58 , struct V_59 * V_60 )
{
struct V_8 * V_63 ;
char * V_70 = NULL ;
T_2 V_36 ;
V_36 = F_38 ( V_58 [ V_35 ] ) ;
V_63 = F_39 ( V_36 , V_71 ) ;
if ( F_40 ( V_63 ) )
return F_41 ( V_63 ) ;
if ( V_58 [ V_38 ] ) {
V_70 = F_42 ( F_21 ( V_58 [ V_38 ] ) ,
F_22 ( V_58 [ V_38 ] ) ,
V_67 ) ;
if ( ! V_70 ) {
F_43 ( V_63 ) ;
return - V_68 ;
}
}
V_60 -> V_36 = V_36 ;
V_60 -> V_37 = V_70 ;
V_60 -> V_9 = V_63 ;
V_60 -> V_69 = true ;
return 0 ;
}
static void F_44 ( const struct V_59 * V_60 )
{
if ( V_60 -> V_69 )
F_43 ( V_60 -> V_9 ) ;
else
F_45 ( V_60 -> V_9 ) ;
F_36 ( V_60 -> V_27 ) ;
F_36 ( V_60 -> V_37 ) ;
}
static void F_46 ( const struct F_1 * V_7 ,
struct V_59 * V_60 )
{
V_60 -> V_69 = F_17 ( V_7 ) ;
V_60 -> V_9 = F_47 ( V_7 -> V_9 , 1 ) ;
V_60 -> V_27 = V_7 -> V_27 ;
V_60 -> V_37 = V_7 -> V_37 ;
}
static int F_48 ( struct V_72 * V_72 , struct V_28 * V_29 ,
struct V_28 * V_73 , struct V_3 * * V_4 ,
int V_74 , int V_39 )
{
struct V_75 * V_76 = F_49 ( V_72 , V_77 ) ;
struct V_28 * V_58 [ V_78 + 1 ] ;
struct V_59 V_60 , V_79 ;
struct V_42 * V_80 ;
struct F_1 * V_7 ;
bool V_81 , V_69 ;
int V_52 , V_6 = 0 ;
if ( ! V_29 )
return - V_66 ;
V_52 = F_50 ( V_58 , V_78 , V_29 , V_82 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( ! V_58 [ V_53 ] )
return - V_66 ;
V_80 = F_21 ( V_58 [ V_53 ] ) ;
if ( ! F_51 ( V_76 , V_80 -> V_44 , V_4 , V_39 ) ) {
V_52 = F_52 ( V_76 , V_80 -> V_44 , V_73 , V_4 ,
& V_83 , V_39 , true ) ;
if ( V_52 < 0 )
return V_52 ;
V_6 = V_84 ;
} else {
if ( V_39 )
return 0 ;
F_53 ( * V_4 , V_39 ) ;
if ( ! V_74 )
return - V_85 ;
}
V_81 = V_58 [ V_30 ] && V_58 [ V_33 ] ;
V_69 = V_58 [ V_35 ] ;
if ( ( ! V_81 && ! V_69 ) || ( V_81 && V_69 ) ) {
V_52 = - V_66 ;
goto V_86;
}
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_52 = V_81 ? F_32 ( V_58 , & V_60 ) :
F_37 ( V_58 , & V_60 ) ;
if ( V_52 < 0 )
goto V_86;
V_7 = F_2 ( * V_4 ) ;
F_54 () ;
if ( V_6 != V_84 )
F_46 ( V_7 , & V_79 ) ;
V_7 -> V_27 = V_60 . V_27 ;
V_7 -> V_37 = V_60 . V_37 ;
if ( V_60 . V_31 )
V_7 -> V_31 = V_60 . V_31 ;
if ( V_60 . V_36 )
V_7 -> V_36 = V_60 . V_36 ;
V_7 -> V_26 = V_80 -> V_10 ;
F_55 ( V_7 -> V_9 , V_60 . V_9 ) ;
if ( V_6 == V_84 ) {
F_56 ( V_76 , * V_4 ) ;
} else {
F_57 () ;
F_44 ( & V_79 ) ;
}
return V_6 ;
V_86:
if ( V_6 == V_84 )
F_58 ( * V_4 , V_73 ) ;
return V_52 ;
}
static void F_59 ( struct V_3 * V_4 , int V_39 )
{
struct V_59 V_87 ;
F_46 ( F_2 ( V_4 ) , & V_87 ) ;
F_44 ( & V_87 ) ;
}
static int F_60 ( struct V_72 * V_72 , struct V_1 * V_2 ,
struct V_88 * V_89 , int type ,
const struct V_90 * V_91 )
{
struct V_75 * V_76 = F_49 ( V_72 , V_77 ) ;
return F_61 ( V_76 , V_2 , V_89 , type , V_91 ) ;
}
static int F_62 ( struct V_72 * V_72 , struct V_3 * * V_92 , T_2 V_44 )
{
struct V_75 * V_76 = F_49 ( V_72 , V_77 ) ;
return F_63 ( V_76 , V_92 , V_44 ) ;
}
static T_3 int F_64 ( struct V_72 * V_72 )
{
struct V_75 * V_76 = F_49 ( V_72 , V_77 ) ;
return F_65 ( V_76 , & V_83 , V_93 ) ;
}
static void T_4 F_66 ( struct V_72 * V_72 )
{
struct V_75 * V_76 = F_49 ( V_72 , V_77 ) ;
F_67 ( V_76 ) ;
}
static int T_5 F_68 ( void )
{
return F_69 ( & V_83 , & V_94 ) ;
}
static void T_6 F_70 ( void )
{
F_71 ( & V_83 , & V_94 ) ;
}
