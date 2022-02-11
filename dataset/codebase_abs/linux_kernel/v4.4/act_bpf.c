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
V_12 = F_11 ( V_10 , V_2 ) ;
F_12 ( V_2 , V_2 -> V_20 ) ;
} else {
V_12 = F_11 ( V_10 , V_2 ) ;
}
F_13 () ;
switch ( V_12 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_11 = V_12 ;
break;
case V_25 :
V_11 = V_12 ;
F_14 ( F_7 ( V_7 -> V_18 . V_26 ) ) ;
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
static bool F_15 ( const struct F_1 * V_7 )
{
return ! V_7 -> V_28 ;
}
static int F_16 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
struct V_29 * V_30 ;
if ( F_17 ( V_2 , V_31 , V_7 -> V_32 ) )
return - V_33 ;
V_30 = F_18 ( V_2 , V_34 , V_7 -> V_32 *
sizeof( struct V_35 ) ) ;
if ( V_30 == NULL )
return - V_33 ;
memcpy ( F_19 ( V_30 ) , V_7 -> V_28 , F_20 ( V_30 ) ) ;
return 0 ;
}
static int F_21 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
if ( F_22 ( V_2 , V_36 , V_7 -> V_37 ) )
return - V_33 ;
if ( V_7 -> V_38 &&
F_23 ( V_2 , V_39 , V_7 -> V_38 ) )
return - V_33 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_40 , int V_41 )
{
unsigned char * V_42 = F_25 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_43 V_44 = {
. V_45 = V_7 -> V_46 ,
. V_47 = V_7 -> V_48 - V_41 ,
. V_49 = V_7 -> V_50 - V_40 ,
. V_11 = V_7 -> V_27 ,
} ;
struct V_51 V_52 ;
int V_53 ;
if ( F_26 ( V_2 , V_54 , sizeof( V_44 ) , & V_44 ) )
goto V_55;
if ( F_15 ( V_7 ) )
V_53 = F_21 ( V_7 , V_2 ) ;
else
V_53 = F_16 ( V_7 , V_2 ) ;
if ( V_53 )
goto V_55;
V_52 . V_56 = F_27 ( V_57 - V_7 -> V_17 . V_56 ) ;
V_52 . V_58 = F_27 ( V_57 - V_7 -> V_17 . V_58 ) ;
V_52 . V_59 = F_27 ( V_7 -> V_17 . V_59 ) ;
if ( F_26 ( V_2 , V_60 , sizeof( V_52 ) , & V_52 ) )
goto V_55;
return V_2 -> V_61 ;
V_55:
F_28 ( V_2 , V_42 ) ;
return - 1 ;
}
static int F_29 ( struct V_29 * * V_62 , struct V_63 * V_64 )
{
struct V_35 * V_28 ;
struct V_65 V_66 ;
struct V_9 * V_67 ;
T_1 V_68 , V_32 ;
int V_53 ;
V_32 = F_30 ( V_62 [ V_31 ] ) ;
if ( V_32 > V_69 || V_32 == 0 )
return - V_70 ;
V_68 = V_32 * sizeof( * V_28 ) ;
if ( V_68 != F_20 ( V_62 [ V_34 ] ) )
return - V_70 ;
V_28 = F_31 ( V_68 , V_71 ) ;
if ( V_28 == NULL )
return - V_72 ;
memcpy ( V_28 , F_19 ( V_62 [ V_34 ] ) , V_68 ) ;
V_66 . V_61 = V_32 ;
V_66 . V_10 = V_28 ;
V_53 = F_32 ( & V_67 , & V_66 ) ;
if ( V_53 < 0 ) {
F_33 ( V_28 ) ;
return V_53 ;
}
V_64 -> V_28 = V_28 ;
V_64 -> V_32 = V_32 ;
V_64 -> V_10 = V_67 ;
V_64 -> V_73 = false ;
return 0 ;
}
static int F_34 ( struct V_29 * * V_62 , struct V_63 * V_64 )
{
struct V_9 * V_67 ;
char * V_74 = NULL ;
T_2 V_37 ;
V_37 = F_35 ( V_62 [ V_36 ] ) ;
V_67 = F_36 ( V_37 ) ;
if ( F_37 ( V_67 ) )
return F_38 ( V_67 ) ;
if ( V_67 -> type != V_75 ) {
F_39 ( V_67 ) ;
return - V_70 ;
}
if ( V_62 [ V_39 ] ) {
V_74 = F_40 ( F_19 ( V_62 [ V_39 ] ) ,
F_20 ( V_62 [ V_39 ] ) ,
V_71 ) ;
if ( ! V_74 ) {
F_39 ( V_67 ) ;
return - V_72 ;
}
}
V_64 -> V_37 = V_37 ;
V_64 -> V_38 = V_74 ;
V_64 -> V_10 = V_67 ;
V_64 -> V_73 = true ;
return 0 ;
}
static void F_41 ( const struct V_63 * V_64 )
{
if ( V_64 -> V_73 )
F_39 ( V_64 -> V_10 ) ;
else
F_42 ( V_64 -> V_10 ) ;
F_33 ( V_64 -> V_28 ) ;
F_33 ( V_64 -> V_38 ) ;
}
static void F_43 ( const struct F_1 * V_7 ,
struct V_63 * V_64 )
{
V_64 -> V_73 = F_15 ( V_7 ) ;
V_64 -> V_10 = F_44 ( V_7 -> V_10 , 1 ) ;
V_64 -> V_28 = V_7 -> V_28 ;
V_64 -> V_38 = V_7 -> V_38 ;
}
static int F_45 ( struct V_76 * V_76 , struct V_29 * V_30 ,
struct V_29 * V_77 , struct V_3 * V_4 ,
int V_78 , int V_40 )
{
struct V_29 * V_62 [ V_79 + 1 ] ;
struct V_63 V_64 , V_80 ;
struct V_43 * V_81 ;
struct F_1 * V_7 ;
bool V_82 , V_73 ;
int V_53 , V_6 = 0 ;
if ( ! V_30 )
return - V_70 ;
V_53 = F_46 ( V_62 , V_79 , V_30 , V_83 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( ! V_62 [ V_54 ] )
return - V_70 ;
V_81 = F_19 ( V_62 [ V_54 ] ) ;
if ( ! F_47 ( V_81 -> V_45 , V_4 , V_40 ) ) {
V_53 = F_48 ( V_81 -> V_45 , V_77 , V_4 ,
sizeof( * V_7 ) , V_40 , true ) ;
if ( V_53 < 0 )
return V_53 ;
V_6 = V_84 ;
} else {
if ( V_40 )
return 0 ;
F_49 ( V_4 , V_40 ) ;
if ( ! V_78 )
return - V_85 ;
}
V_82 = V_62 [ V_31 ] && V_62 [ V_34 ] ;
V_73 = V_62 [ V_36 ] ;
if ( ( ! V_82 && ! V_73 ) || ( V_82 && V_73 ) ) {
V_53 = - V_70 ;
goto V_86;
}
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_53 = V_82 ? F_29 ( V_62 , & V_64 ) :
F_34 ( V_62 , & V_64 ) ;
if ( V_53 < 0 )
goto V_86;
V_7 = F_50 ( V_4 ) ;
F_51 () ;
if ( V_6 != V_84 )
F_43 ( V_7 , & V_80 ) ;
V_7 -> V_28 = V_64 . V_28 ;
V_7 -> V_38 = V_64 . V_38 ;
if ( V_64 . V_32 )
V_7 -> V_32 = V_64 . V_32 ;
if ( V_64 . V_37 )
V_7 -> V_37 = V_64 . V_37 ;
V_7 -> V_27 = V_81 -> V_11 ;
F_52 ( V_7 -> V_10 , V_64 . V_10 ) ;
if ( V_6 == V_84 ) {
F_53 ( V_4 ) ;
} else {
F_54 () ;
F_41 ( & V_80 ) ;
}
return V_6 ;
V_86:
if ( V_6 == V_84 )
F_55 ( V_4 , V_77 ) ;
return V_53 ;
}
static void F_56 ( struct V_3 * V_4 , int V_40 )
{
struct V_63 V_87 ;
F_43 ( V_4 -> V_8 , & V_87 ) ;
F_41 ( & V_87 ) ;
}
static int T_3 F_57 ( void )
{
return F_58 ( & V_88 , V_89 ) ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_88 ) ;
}
