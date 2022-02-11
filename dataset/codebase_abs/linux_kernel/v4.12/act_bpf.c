static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
bool V_7 = F_2 ( V_2 ) ;
struct F_1 * V_8 = F_3 ( V_4 ) ;
struct V_9 * V_10 ;
int V_11 , V_12 ;
F_4 ( & V_8 -> V_13 ) ;
F_5 ( F_6 ( V_8 -> V_14 . V_15 ) , V_2 ) ;
F_7 () ;
V_10 = F_8 ( V_8 -> V_10 ) ;
if ( V_7 ) {
F_9 ( V_2 , V_2 -> V_16 ) ;
F_10 ( V_2 ) ;
V_12 = F_11 ( V_10 , V_2 ) ;
F_12 ( V_2 , V_2 -> V_16 ) ;
} else {
F_10 ( V_2 ) ;
V_12 = F_11 ( V_10 , V_2 ) ;
}
F_13 () ;
switch ( V_12 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
V_11 = V_12 ;
break;
case V_21 :
V_11 = V_12 ;
F_14 ( F_6 ( V_8 -> V_14 . V_22 ) ) ;
break;
case V_23 :
V_11 = V_8 -> V_24 ;
break;
default:
V_11 = V_23 ;
break;
}
return V_11 ;
}
static bool F_15 ( const struct F_1 * V_8 )
{
return ! V_8 -> V_25 ;
}
static int F_16 ( const struct F_1 * V_8 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 ;
if ( F_17 ( V_2 , V_28 , V_8 -> V_29 ) )
return - V_30 ;
V_27 = F_18 ( V_2 , V_31 , V_8 -> V_29 *
sizeof( struct V_32 ) ) ;
if ( V_27 == NULL )
return - V_30 ;
memcpy ( F_19 ( V_27 ) , V_8 -> V_25 , F_20 ( V_27 ) ) ;
return 0 ;
}
static int F_21 ( const struct F_1 * V_8 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 ;
if ( V_8 -> V_33 &&
F_22 ( V_2 , V_34 , V_8 -> V_33 ) )
return - V_30 ;
V_27 = F_18 ( V_2 , V_35 , sizeof( V_8 -> V_10 -> V_36 ) ) ;
if ( V_27 == NULL )
return - V_30 ;
memcpy ( F_19 ( V_27 ) , V_8 -> V_10 -> V_36 , F_20 ( V_27 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_37 , int V_38 )
{
unsigned char * V_39 = F_24 ( V_2 ) ;
struct F_1 * V_8 = F_3 ( V_4 ) ;
struct V_40 V_41 = {
. V_42 = V_8 -> V_43 ,
. V_44 = V_8 -> V_45 - V_38 ,
. V_46 = V_8 -> V_47 - V_37 ,
. V_11 = V_8 -> V_24 ,
} ;
struct V_48 V_49 ;
int V_50 ;
if ( F_25 ( V_2 , V_51 , sizeof( V_41 ) , & V_41 ) )
goto V_52;
if ( F_15 ( V_8 ) )
V_50 = F_21 ( V_8 , V_2 ) ;
else
V_50 = F_16 ( V_8 , V_2 ) ;
if ( V_50 )
goto V_52;
F_26 ( & V_49 , & V_8 -> V_13 ) ;
if ( F_27 ( V_2 , V_53 , sizeof( V_49 ) , & V_49 ,
V_54 ) )
goto V_52;
return V_2 -> V_55 ;
V_52:
F_28 ( V_2 , V_39 ) ;
return - 1 ;
}
static int F_29 ( struct V_26 * * V_56 , struct V_57 * V_58 )
{
struct V_32 * V_25 ;
struct V_59 V_60 ;
struct V_9 * V_61 ;
T_1 V_62 , V_29 ;
int V_50 ;
V_29 = F_30 ( V_56 [ V_28 ] ) ;
if ( V_29 > V_63 || V_29 == 0 )
return - V_64 ;
V_62 = V_29 * sizeof( * V_25 ) ;
if ( V_62 != F_20 ( V_56 [ V_31 ] ) )
return - V_64 ;
V_25 = F_31 ( V_62 , V_65 ) ;
if ( V_25 == NULL )
return - V_66 ;
memcpy ( V_25 , F_19 ( V_56 [ V_31 ] ) , V_62 ) ;
V_60 . V_55 = V_29 ;
V_60 . V_10 = V_25 ;
V_50 = F_32 ( & V_61 , & V_60 ) ;
if ( V_50 < 0 ) {
F_33 ( V_25 ) ;
return V_50 ;
}
V_58 -> V_25 = V_25 ;
V_58 -> V_29 = V_29 ;
V_58 -> V_10 = V_61 ;
V_58 -> V_67 = false ;
return 0 ;
}
static int F_34 ( struct V_26 * * V_56 , struct V_57 * V_58 )
{
struct V_9 * V_61 ;
char * V_68 = NULL ;
T_2 V_69 ;
V_69 = F_35 ( V_56 [ V_70 ] ) ;
V_61 = F_36 ( V_69 , V_71 ) ;
if ( F_37 ( V_61 ) )
return F_38 ( V_61 ) ;
if ( V_56 [ V_34 ] ) {
V_68 = F_39 ( V_56 [ V_34 ] , V_65 ) ;
if ( ! V_68 ) {
F_40 ( V_61 ) ;
return - V_66 ;
}
}
V_58 -> V_33 = V_68 ;
V_58 -> V_10 = V_61 ;
V_58 -> V_67 = true ;
return 0 ;
}
static void F_41 ( const struct V_57 * V_58 )
{
if ( V_58 -> V_67 )
F_40 ( V_58 -> V_10 ) ;
else
F_42 ( V_58 -> V_10 ) ;
F_33 ( V_58 -> V_25 ) ;
F_33 ( V_58 -> V_33 ) ;
}
static void F_43 ( const struct F_1 * V_8 ,
struct V_57 * V_58 )
{
V_58 -> V_67 = F_15 ( V_8 ) ;
V_58 -> V_10 = F_44 ( V_8 -> V_10 , 1 ) ;
V_58 -> V_25 = V_8 -> V_25 ;
V_58 -> V_33 = V_8 -> V_33 ;
}
static int F_45 ( struct V_72 * V_72 , struct V_26 * V_27 ,
struct V_26 * V_73 , struct V_3 * * V_4 ,
int V_74 , int V_37 )
{
struct V_75 * V_76 = F_46 ( V_72 , V_77 ) ;
struct V_26 * V_56 [ V_78 + 1 ] ;
struct V_57 V_58 , V_79 ;
struct V_40 * V_80 ;
struct F_1 * V_8 ;
bool V_81 , V_67 ;
int V_50 , V_6 = 0 ;
if ( ! V_27 )
return - V_64 ;
V_50 = F_47 ( V_56 , V_78 , V_27 , V_82 , NULL ) ;
if ( V_50 < 0 )
return V_50 ;
if ( ! V_56 [ V_51 ] )
return - V_64 ;
V_80 = F_19 ( V_56 [ V_51 ] ) ;
if ( ! F_48 ( V_76 , V_80 -> V_42 , V_4 , V_37 ) ) {
V_50 = F_49 ( V_76 , V_80 -> V_42 , V_73 , V_4 ,
& V_83 , V_37 , true ) ;
if ( V_50 < 0 )
return V_50 ;
V_6 = V_84 ;
} else {
if ( V_37 )
return 0 ;
F_50 ( * V_4 , V_37 ) ;
if ( ! V_74 )
return - V_85 ;
}
V_81 = V_56 [ V_28 ] && V_56 [ V_31 ] ;
V_67 = V_56 [ V_70 ] ;
if ( ( ! V_81 && ! V_67 ) || ( V_81 && V_67 ) ) {
V_50 = - V_64 ;
goto V_86;
}
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_50 = V_81 ? F_29 ( V_56 , & V_58 ) :
F_34 ( V_56 , & V_58 ) ;
if ( V_50 < 0 )
goto V_86;
V_8 = F_3 ( * V_4 ) ;
F_51 () ;
if ( V_6 != V_84 )
F_43 ( V_8 , & V_79 ) ;
V_8 -> V_25 = V_58 . V_25 ;
V_8 -> V_33 = V_58 . V_33 ;
if ( V_58 . V_29 )
V_8 -> V_29 = V_58 . V_29 ;
V_8 -> V_24 = V_80 -> V_11 ;
F_52 ( V_8 -> V_10 , V_58 . V_10 ) ;
if ( V_6 == V_84 ) {
F_53 ( V_76 , * V_4 ) ;
} else {
F_54 () ;
F_41 ( & V_79 ) ;
}
return V_6 ;
V_86:
if ( V_6 == V_84 )
F_55 ( * V_4 , V_73 ) ;
return V_50 ;
}
static void F_56 ( struct V_3 * V_4 , int V_37 )
{
struct V_57 V_87 ;
F_43 ( F_3 ( V_4 ) , & V_87 ) ;
F_41 ( & V_87 ) ;
}
static int F_57 ( struct V_72 * V_72 , struct V_1 * V_2 ,
struct V_88 * V_89 , int type ,
const struct V_90 * V_91 )
{
struct V_75 * V_76 = F_46 ( V_72 , V_77 ) ;
return F_58 ( V_76 , V_2 , V_89 , type , V_91 ) ;
}
static int F_59 ( struct V_72 * V_72 , struct V_3 * * V_92 , T_2 V_42 )
{
struct V_75 * V_76 = F_46 ( V_72 , V_77 ) ;
return F_60 ( V_76 , V_92 , V_42 ) ;
}
static T_3 int F_61 ( struct V_72 * V_72 )
{
struct V_75 * V_76 = F_46 ( V_72 , V_77 ) ;
return F_62 ( V_76 , & V_83 , V_93 ) ;
}
static void T_4 F_63 ( struct V_72 * V_72 )
{
struct V_75 * V_76 = F_46 ( V_72 , V_77 ) ;
F_64 ( V_76 ) ;
}
static int T_5 F_65 ( void )
{
return F_66 ( & V_83 , & V_94 ) ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_83 , & V_94 ) ;
}
