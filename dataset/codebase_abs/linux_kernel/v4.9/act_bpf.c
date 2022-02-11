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
if ( F_22 ( V_2 , V_33 , V_8 -> V_34 ) )
return - V_30 ;
if ( V_8 -> V_35 &&
F_23 ( V_2 , V_36 , V_8 -> V_35 ) )
return - V_30 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_37 , int V_38 )
{
unsigned char * V_39 = F_25 ( V_2 ) ;
struct F_1 * V_8 = F_3 ( V_4 ) ;
struct V_40 V_41 = {
. V_42 = V_8 -> V_43 ,
. V_44 = V_8 -> V_45 - V_38 ,
. V_46 = V_8 -> V_47 - V_37 ,
. V_11 = V_8 -> V_24 ,
} ;
struct V_48 V_49 ;
int V_50 ;
if ( F_26 ( V_2 , V_51 , sizeof( V_41 ) , & V_41 ) )
goto V_52;
if ( F_15 ( V_8 ) )
V_50 = F_21 ( V_8 , V_2 ) ;
else
V_50 = F_16 ( V_8 , V_2 ) ;
if ( V_50 )
goto V_52;
F_27 ( & V_49 , & V_8 -> V_13 ) ;
if ( F_28 ( V_2 , V_53 , sizeof( V_49 ) , & V_49 ,
V_54 ) )
goto V_52;
return V_2 -> V_55 ;
V_52:
F_29 ( V_2 , V_39 ) ;
return - 1 ;
}
static int F_30 ( struct V_26 * * V_56 , struct V_57 * V_58 )
{
struct V_32 * V_25 ;
struct V_59 V_60 ;
struct V_9 * V_61 ;
T_1 V_62 , V_29 ;
int V_50 ;
V_29 = F_31 ( V_56 [ V_28 ] ) ;
if ( V_29 > V_63 || V_29 == 0 )
return - V_64 ;
V_62 = V_29 * sizeof( * V_25 ) ;
if ( V_62 != F_20 ( V_56 [ V_31 ] ) )
return - V_64 ;
V_25 = F_32 ( V_62 , V_65 ) ;
if ( V_25 == NULL )
return - V_66 ;
memcpy ( V_25 , F_19 ( V_56 [ V_31 ] ) , V_62 ) ;
V_60 . V_55 = V_29 ;
V_60 . V_10 = V_25 ;
V_50 = F_33 ( & V_61 , & V_60 ) ;
if ( V_50 < 0 ) {
F_34 ( V_25 ) ;
return V_50 ;
}
V_58 -> V_25 = V_25 ;
V_58 -> V_29 = V_29 ;
V_58 -> V_10 = V_61 ;
V_58 -> V_67 = false ;
return 0 ;
}
static int F_35 ( struct V_26 * * V_56 , struct V_57 * V_58 )
{
struct V_9 * V_61 ;
char * V_68 = NULL ;
T_2 V_34 ;
V_34 = F_36 ( V_56 [ V_33 ] ) ;
V_61 = F_37 ( V_34 , V_69 ) ;
if ( F_38 ( V_61 ) )
return F_39 ( V_61 ) ;
if ( V_56 [ V_36 ] ) {
V_68 = F_40 ( F_19 ( V_56 [ V_36 ] ) ,
F_20 ( V_56 [ V_36 ] ) ,
V_65 ) ;
if ( ! V_68 ) {
F_41 ( V_61 ) ;
return - V_66 ;
}
}
V_58 -> V_34 = V_34 ;
V_58 -> V_35 = V_68 ;
V_58 -> V_10 = V_61 ;
V_58 -> V_67 = true ;
return 0 ;
}
static void F_42 ( const struct V_57 * V_58 )
{
if ( V_58 -> V_67 )
F_41 ( V_58 -> V_10 ) ;
else
F_43 ( V_58 -> V_10 ) ;
F_34 ( V_58 -> V_25 ) ;
F_34 ( V_58 -> V_35 ) ;
}
static void F_44 ( const struct F_1 * V_8 ,
struct V_57 * V_58 )
{
V_58 -> V_67 = F_15 ( V_8 ) ;
V_58 -> V_10 = F_45 ( V_8 -> V_10 , 1 ) ;
V_58 -> V_25 = V_8 -> V_25 ;
V_58 -> V_35 = V_8 -> V_35 ;
}
static int F_46 ( struct V_70 * V_70 , struct V_26 * V_27 ,
struct V_26 * V_71 , struct V_3 * * V_4 ,
int V_72 , int V_37 )
{
struct V_73 * V_74 = F_47 ( V_70 , V_75 ) ;
struct V_26 * V_56 [ V_76 + 1 ] ;
struct V_57 V_58 , V_77 ;
struct V_40 * V_78 ;
struct F_1 * V_8 ;
bool V_79 , V_67 ;
int V_50 , V_6 = 0 ;
if ( ! V_27 )
return - V_64 ;
V_50 = F_48 ( V_56 , V_76 , V_27 , V_80 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( ! V_56 [ V_51 ] )
return - V_64 ;
V_78 = F_19 ( V_56 [ V_51 ] ) ;
if ( ! F_49 ( V_74 , V_78 -> V_42 , V_4 , V_37 ) ) {
V_50 = F_50 ( V_74 , V_78 -> V_42 , V_71 , V_4 ,
& V_81 , V_37 , true ) ;
if ( V_50 < 0 )
return V_50 ;
V_6 = V_82 ;
} else {
if ( V_37 )
return 0 ;
F_51 ( * V_4 , V_37 ) ;
if ( ! V_72 )
return - V_83 ;
}
V_79 = V_56 [ V_28 ] && V_56 [ V_31 ] ;
V_67 = V_56 [ V_33 ] ;
if ( ( ! V_79 && ! V_67 ) || ( V_79 && V_67 ) ) {
V_50 = - V_64 ;
goto V_84;
}
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_50 = V_79 ? F_30 ( V_56 , & V_58 ) :
F_35 ( V_56 , & V_58 ) ;
if ( V_50 < 0 )
goto V_84;
V_8 = F_3 ( * V_4 ) ;
F_52 () ;
if ( V_6 != V_82 )
F_44 ( V_8 , & V_77 ) ;
V_8 -> V_25 = V_58 . V_25 ;
V_8 -> V_35 = V_58 . V_35 ;
if ( V_58 . V_29 )
V_8 -> V_29 = V_58 . V_29 ;
if ( V_58 . V_34 )
V_8 -> V_34 = V_58 . V_34 ;
V_8 -> V_24 = V_78 -> V_11 ;
F_53 ( V_8 -> V_10 , V_58 . V_10 ) ;
if ( V_6 == V_82 ) {
F_54 ( V_74 , * V_4 ) ;
} else {
F_55 () ;
F_42 ( & V_77 ) ;
}
return V_6 ;
V_84:
if ( V_6 == V_82 )
F_56 ( * V_4 , V_71 ) ;
return V_50 ;
}
static void F_57 ( struct V_3 * V_4 , int V_37 )
{
struct V_57 V_85 ;
F_44 ( F_3 ( V_4 ) , & V_85 ) ;
F_42 ( & V_85 ) ;
}
static int F_58 ( struct V_70 * V_70 , struct V_1 * V_2 ,
struct V_86 * V_87 , int type ,
const struct V_88 * V_89 )
{
struct V_73 * V_74 = F_47 ( V_70 , V_75 ) ;
return F_59 ( V_74 , V_2 , V_87 , type , V_89 ) ;
}
static int F_60 ( struct V_70 * V_70 , struct V_3 * * V_90 , T_2 V_42 )
{
struct V_73 * V_74 = F_47 ( V_70 , V_75 ) ;
return F_61 ( V_74 , V_90 , V_42 ) ;
}
static T_3 int F_62 ( struct V_70 * V_70 )
{
struct V_73 * V_74 = F_47 ( V_70 , V_75 ) ;
return F_63 ( V_74 , & V_81 , V_91 ) ;
}
static void T_4 F_64 ( struct V_70 * V_70 )
{
struct V_73 * V_74 = F_47 ( V_70 , V_75 ) ;
F_65 ( V_74 ) ;
}
static int T_5 F_66 ( void )
{
return F_67 ( & V_81 , & V_92 ) ;
}
static void T_6 F_68 ( void )
{
F_69 ( & V_81 , & V_92 ) ;
}
