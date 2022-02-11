static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 ;
int V_11 , V_12 ;
bool V_13 = F_2 ( V_2 -> V_14 ) & V_15 ;
if ( F_3 ( ! F_4 ( V_2 ) ) )
return V_16 ;
F_5 ( & V_7 -> V_17 ) ;
F_6 ( F_7 ( V_7 -> V_18 . V_19 ) , V_2 ) ;
F_8 () ;
V_10 = F_9 ( V_7 -> V_10 ) ;
if ( V_13 ) {
F_10 ( V_2 , V_2 -> V_20 ) ;
F_11 ( V_2 ) ;
V_12 = F_12 ( V_10 , V_2 ) ;
F_13 ( V_2 , V_2 -> V_20 ) ;
} else {
F_11 ( V_2 ) ;
V_12 = F_12 ( V_10 , V_2 ) ;
}
F_14 () ;
switch ( V_12 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_11 = V_12 ;
break;
case V_25 :
V_11 = V_12 ;
F_15 ( F_7 ( V_7 -> V_18 . V_26 ) ) ;
break;
case V_16 :
V_11 = V_7 -> V_27 ;
break;
default:
V_11 = V_16 ;
break;
}
return V_11 ;
}
static bool F_16 ( const struct F_1 * V_7 )
{
return ! V_7 -> V_28 ;
}
static int F_17 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
struct V_29 * V_30 ;
if ( F_18 ( V_2 , V_31 , V_7 -> V_32 ) )
return - V_33 ;
V_30 = F_19 ( V_2 , V_34 , V_7 -> V_32 *
sizeof( struct V_35 ) ) ;
if ( V_30 == NULL )
return - V_33 ;
memcpy ( F_20 ( V_30 ) , V_7 -> V_28 , F_21 ( V_30 ) ) ;
return 0 ;
}
static int F_22 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
if ( F_23 ( V_2 , V_36 , V_7 -> V_37 ) )
return - V_33 ;
if ( V_7 -> V_38 &&
F_24 ( V_2 , V_39 , V_7 -> V_38 ) )
return - V_33 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_40 , int V_41 )
{
unsigned char * V_42 = F_26 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_43 V_44 = {
. V_45 = V_7 -> V_46 ,
. V_47 = V_7 -> V_48 - V_41 ,
. V_49 = V_7 -> V_50 - V_40 ,
. V_11 = V_7 -> V_27 ,
} ;
struct V_51 V_52 ;
int V_53 ;
if ( F_27 ( V_2 , V_54 , sizeof( V_44 ) , & V_44 ) )
goto V_55;
if ( F_16 ( V_7 ) )
V_53 = F_22 ( V_7 , V_2 ) ;
else
V_53 = F_17 ( V_7 , V_2 ) ;
if ( V_53 )
goto V_55;
V_52 . V_56 = F_28 ( V_57 - V_7 -> V_17 . V_56 ) ;
V_52 . V_58 = F_28 ( V_57 - V_7 -> V_17 . V_58 ) ;
V_52 . V_59 = F_28 ( V_7 -> V_17 . V_59 ) ;
if ( F_29 ( V_2 , V_60 , sizeof( V_52 ) , & V_52 ,
V_61 ) )
goto V_55;
return V_2 -> V_62 ;
V_55:
F_30 ( V_2 , V_42 ) ;
return - 1 ;
}
static int F_31 ( struct V_29 * * V_63 , struct V_64 * V_65 )
{
struct V_35 * V_28 ;
struct V_66 V_67 ;
struct V_9 * V_68 ;
T_1 V_69 , V_32 ;
int V_53 ;
V_32 = F_32 ( V_63 [ V_31 ] ) ;
if ( V_32 > V_70 || V_32 == 0 )
return - V_71 ;
V_69 = V_32 * sizeof( * V_28 ) ;
if ( V_69 != F_21 ( V_63 [ V_34 ] ) )
return - V_71 ;
V_28 = F_33 ( V_69 , V_72 ) ;
if ( V_28 == NULL )
return - V_73 ;
memcpy ( V_28 , F_20 ( V_63 [ V_34 ] ) , V_69 ) ;
V_67 . V_62 = V_32 ;
V_67 . V_10 = V_28 ;
V_53 = F_34 ( & V_68 , & V_67 ) ;
if ( V_53 < 0 ) {
F_35 ( V_28 ) ;
return V_53 ;
}
V_65 -> V_28 = V_28 ;
V_65 -> V_32 = V_32 ;
V_65 -> V_10 = V_68 ;
V_65 -> V_74 = false ;
return 0 ;
}
static int F_36 ( struct V_29 * * V_63 , struct V_64 * V_65 )
{
struct V_9 * V_68 ;
char * V_75 = NULL ;
T_2 V_37 ;
V_37 = F_37 ( V_63 [ V_36 ] ) ;
V_68 = F_38 ( V_37 ) ;
if ( F_39 ( V_68 ) )
return F_40 ( V_68 ) ;
if ( V_68 -> type != V_76 ) {
F_41 ( V_68 ) ;
return - V_71 ;
}
if ( V_63 [ V_39 ] ) {
V_75 = F_42 ( F_20 ( V_63 [ V_39 ] ) ,
F_21 ( V_63 [ V_39 ] ) ,
V_72 ) ;
if ( ! V_75 ) {
F_41 ( V_68 ) ;
return - V_73 ;
}
}
V_65 -> V_37 = V_37 ;
V_65 -> V_38 = V_75 ;
V_65 -> V_10 = V_68 ;
V_65 -> V_74 = true ;
return 0 ;
}
static void F_43 ( const struct V_64 * V_65 )
{
if ( V_65 -> V_74 )
F_41 ( V_65 -> V_10 ) ;
else
F_44 ( V_65 -> V_10 ) ;
F_35 ( V_65 -> V_28 ) ;
F_35 ( V_65 -> V_38 ) ;
}
static void F_45 ( const struct F_1 * V_7 ,
struct V_64 * V_65 )
{
V_65 -> V_74 = F_16 ( V_7 ) ;
V_65 -> V_10 = F_46 ( V_7 -> V_10 , 1 ) ;
V_65 -> V_28 = V_7 -> V_28 ;
V_65 -> V_38 = V_7 -> V_38 ;
}
static int F_47 ( struct V_77 * V_77 , struct V_29 * V_30 ,
struct V_29 * V_78 , struct V_3 * V_4 ,
int V_79 , int V_40 )
{
struct V_80 * V_81 = F_48 ( V_77 , V_82 ) ;
struct V_29 * V_63 [ V_83 + 1 ] ;
struct V_64 V_65 , V_84 ;
struct V_43 * V_85 ;
struct F_1 * V_7 ;
bool V_86 , V_74 ;
int V_53 , V_6 = 0 ;
if ( ! V_30 )
return - V_71 ;
V_53 = F_49 ( V_63 , V_83 , V_30 , V_87 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( ! V_63 [ V_54 ] )
return - V_71 ;
V_85 = F_20 ( V_63 [ V_54 ] ) ;
if ( ! F_50 ( V_81 , V_85 -> V_45 , V_4 , V_40 ) ) {
V_53 = F_51 ( V_81 , V_85 -> V_45 , V_78 , V_4 ,
sizeof( * V_7 ) , V_40 , true ) ;
if ( V_53 < 0 )
return V_53 ;
V_6 = V_88 ;
} else {
if ( V_40 )
return 0 ;
F_52 ( V_4 , V_40 ) ;
if ( ! V_79 )
return - V_89 ;
}
V_86 = V_63 [ V_31 ] && V_63 [ V_34 ] ;
V_74 = V_63 [ V_36 ] ;
if ( ( ! V_86 && ! V_74 ) || ( V_86 && V_74 ) ) {
V_53 = - V_71 ;
goto V_90;
}
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_53 = V_86 ? F_31 ( V_63 , & V_65 ) :
F_36 ( V_63 , & V_65 ) ;
if ( V_53 < 0 )
goto V_90;
V_7 = F_53 ( V_4 ) ;
F_54 () ;
if ( V_6 != V_88 )
F_45 ( V_7 , & V_84 ) ;
V_7 -> V_28 = V_65 . V_28 ;
V_7 -> V_38 = V_65 . V_38 ;
if ( V_65 . V_32 )
V_7 -> V_32 = V_65 . V_32 ;
if ( V_65 . V_37 )
V_7 -> V_37 = V_65 . V_37 ;
V_7 -> V_27 = V_85 -> V_11 ;
F_55 ( V_7 -> V_10 , V_65 . V_10 ) ;
if ( V_6 == V_88 ) {
F_56 ( V_81 , V_4 ) ;
} else {
F_57 () ;
F_43 ( & V_84 ) ;
}
return V_6 ;
V_90:
if ( V_6 == V_88 )
F_58 ( V_4 , V_78 ) ;
return V_53 ;
}
static void F_59 ( struct V_3 * V_4 , int V_40 )
{
struct V_64 V_91 ;
F_45 ( V_4 -> V_8 , & V_91 ) ;
F_43 ( & V_91 ) ;
}
static int F_60 ( struct V_77 * V_77 , struct V_1 * V_2 ,
struct V_92 * V_93 , int type ,
struct V_3 * V_94 )
{
struct V_80 * V_81 = F_48 ( V_77 , V_82 ) ;
return F_61 ( V_81 , V_2 , V_93 , type , V_94 ) ;
}
static int F_62 ( struct V_77 * V_77 , struct V_3 * V_94 , T_2 V_45 )
{
struct V_80 * V_81 = F_48 ( V_77 , V_82 ) ;
return F_63 ( V_81 , V_94 , V_45 ) ;
}
static T_3 int F_64 ( struct V_77 * V_77 )
{
struct V_80 * V_81 = F_48 ( V_77 , V_82 ) ;
return F_65 ( V_81 , & V_95 , V_96 ) ;
}
static void T_4 F_66 ( struct V_77 * V_77 )
{
struct V_80 * V_81 = F_48 ( V_77 , V_82 ) ;
F_67 ( V_81 ) ;
}
static int T_5 F_68 ( void )
{
return F_69 ( & V_95 , & V_97 ) ;
}
static void T_6 F_70 ( void )
{
F_71 ( & V_95 , & V_97 ) ;
}
