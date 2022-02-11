static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
int V_9 , V_10 ;
bool V_11 = F_2 ( V_2 -> V_12 ) & V_13 ;
if ( F_3 ( ! F_4 ( V_2 ) ) )
return V_14 ;
F_5 ( & V_7 -> V_15 ) ;
V_7 -> V_16 . V_17 = V_18 ;
F_6 ( & V_7 -> V_19 , V_2 ) ;
F_7 () ;
if ( V_11 ) {
F_8 ( V_2 , V_2 -> V_20 ) ;
V_10 = F_9 ( V_7 -> V_21 , V_2 ) ;
F_10 ( V_2 , V_2 -> V_20 ) ;
} else {
V_10 = F_9 ( V_7 -> V_21 , V_2 ) ;
}
F_11 () ;
switch ( V_10 ) {
case V_22 :
case V_23 :
case V_24 :
V_9 = V_10 ;
break;
case V_25 :
V_9 = V_10 ;
V_7 -> V_26 . V_27 ++ ;
break;
case V_14 :
V_9 = V_7 -> V_28 ;
break;
default:
V_9 = V_14 ;
break;
}
F_12 ( & V_7 -> V_15 ) ;
return V_9 ;
}
static bool F_13 ( const struct F_1 * V_7 )
{
return ! V_7 -> V_29 ;
}
static int F_14 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
struct V_30 * V_31 ;
if ( F_15 ( V_2 , V_32 , V_7 -> V_33 ) )
return - V_34 ;
V_31 = F_16 ( V_2 , V_35 , V_7 -> V_33 *
sizeof( struct V_36 ) ) ;
if ( V_31 == NULL )
return - V_34 ;
memcpy ( F_17 ( V_31 ) , V_7 -> V_29 , F_18 ( V_31 ) ) ;
return 0 ;
}
static int F_19 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
if ( F_20 ( V_2 , V_37 , V_7 -> V_38 ) )
return - V_34 ;
if ( V_7 -> V_39 &&
F_21 ( V_2 , V_40 , V_7 -> V_39 ) )
return - V_34 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_41 , int V_42 )
{
unsigned char * V_43 = F_23 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_44 V_45 = {
. V_46 = V_7 -> V_47 ,
. V_48 = V_7 -> V_49 - V_42 ,
. V_50 = V_7 -> V_51 - V_41 ,
. V_9 = V_7 -> V_28 ,
} ;
struct V_52 V_53 ;
int V_54 ;
if ( F_24 ( V_2 , V_55 , sizeof( V_45 ) , & V_45 ) )
goto V_56;
if ( F_13 ( V_7 ) )
V_54 = F_19 ( V_7 , V_2 ) ;
else
V_54 = F_14 ( V_7 , V_2 ) ;
if ( V_54 )
goto V_56;
V_53 . V_57 = F_25 ( V_18 - V_7 -> V_16 . V_57 ) ;
V_53 . V_17 = F_25 ( V_18 - V_7 -> V_16 . V_17 ) ;
V_53 . V_58 = F_25 ( V_7 -> V_16 . V_58 ) ;
if ( F_24 ( V_2 , V_59 , sizeof( V_53 ) , & V_53 ) )
goto V_56;
return V_2 -> V_60 ;
V_56:
F_26 ( V_2 , V_43 ) ;
return - 1 ;
}
static int F_27 ( struct V_30 * * V_61 , struct V_62 * V_63 )
{
struct V_36 * V_29 ;
struct V_64 V_65 ;
struct V_66 * V_67 ;
T_1 V_68 , V_33 ;
int V_54 ;
V_33 = F_28 ( V_61 [ V_32 ] ) ;
if ( V_33 > V_69 || V_33 == 0 )
return - V_70 ;
V_68 = V_33 * sizeof( * V_29 ) ;
if ( V_68 != F_18 ( V_61 [ V_35 ] ) )
return - V_70 ;
V_29 = F_29 ( V_68 , V_71 ) ;
if ( V_29 == NULL )
return - V_72 ;
memcpy ( V_29 , F_17 ( V_61 [ V_35 ] ) , V_68 ) ;
V_65 . V_60 = V_33 ;
V_65 . V_21 = V_29 ;
V_54 = F_30 ( & V_67 , & V_65 ) ;
if ( V_54 < 0 ) {
F_31 ( V_29 ) ;
return V_54 ;
}
V_63 -> V_29 = V_29 ;
V_63 -> V_33 = V_33 ;
V_63 -> V_21 = V_67 ;
V_63 -> V_73 = false ;
return 0 ;
}
static int F_32 ( struct V_30 * * V_61 , struct V_62 * V_63 )
{
struct V_66 * V_67 ;
char * V_74 = NULL ;
T_2 V_38 ;
V_38 = F_33 ( V_61 [ V_37 ] ) ;
V_67 = F_34 ( V_38 ) ;
if ( F_35 ( V_67 ) )
return F_36 ( V_67 ) ;
if ( V_67 -> type != V_75 ) {
F_37 ( V_67 ) ;
return - V_70 ;
}
if ( V_61 [ V_40 ] ) {
V_74 = F_38 ( F_17 ( V_61 [ V_40 ] ) ,
F_18 ( V_61 [ V_40 ] ) ,
V_71 ) ;
if ( ! V_74 ) {
F_37 ( V_67 ) ;
return - V_72 ;
}
}
V_63 -> V_38 = V_38 ;
V_63 -> V_39 = V_74 ;
V_63 -> V_21 = V_67 ;
V_63 -> V_73 = true ;
return 0 ;
}
static void F_39 ( const struct V_62 * V_63 )
{
if ( V_63 -> V_73 )
F_37 ( V_63 -> V_21 ) ;
else
F_40 ( V_63 -> V_21 ) ;
F_31 ( V_63 -> V_29 ) ;
F_31 ( V_63 -> V_39 ) ;
}
static void F_41 ( const struct F_1 * V_7 ,
struct V_62 * V_63 )
{
V_63 -> V_73 = F_13 ( V_7 ) ;
V_63 -> V_21 = V_7 -> V_21 ;
V_63 -> V_29 = V_7 -> V_29 ;
V_63 -> V_39 = V_7 -> V_39 ;
}
static int F_42 ( struct V_76 * V_76 , struct V_30 * V_31 ,
struct V_30 * V_77 , struct V_3 * V_4 ,
int V_78 , int V_41 )
{
struct V_30 * V_61 [ V_79 + 1 ] ;
struct V_62 V_63 , V_80 ;
struct V_44 * V_81 ;
struct F_1 * V_7 ;
bool V_82 , V_73 ;
int V_54 ;
if ( ! V_31 )
return - V_70 ;
V_54 = F_43 ( V_61 , V_79 , V_31 , V_83 ) ;
if ( V_54 < 0 )
return V_54 ;
V_82 = V_61 [ V_32 ] && V_61 [ V_35 ] ;
V_73 = V_61 [ V_37 ] ;
if ( ( ! V_82 && ! V_73 ) || ( V_82 && V_73 ) ||
! V_61 [ V_55 ] )
return - V_70 ;
V_81 = F_17 ( V_61 [ V_55 ] ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_54 = V_82 ? F_27 ( V_61 , & V_63 ) :
F_32 ( V_61 , & V_63 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! F_44 ( V_81 -> V_46 , V_4 , V_41 ) ) {
V_54 = F_45 ( V_81 -> V_46 , V_77 , V_4 ,
sizeof( * V_7 ) , V_41 ) ;
if ( V_54 < 0 )
goto V_84;
V_54 = V_85 ;
} else {
if ( V_41 )
goto V_84;
F_46 ( V_4 , V_41 ) ;
if ( ! V_78 ) {
V_54 = - V_86 ;
goto V_84;
}
}
V_7 = F_47 ( V_4 ) ;
F_48 ( & V_7 -> V_15 ) ;
if ( V_54 != V_85 )
F_41 ( V_7 , & V_80 ) ;
V_7 -> V_29 = V_63 . V_29 ;
V_7 -> V_39 = V_63 . V_39 ;
if ( V_63 . V_33 )
V_7 -> V_33 = V_63 . V_33 ;
if ( V_63 . V_38 )
V_7 -> V_38 = V_63 . V_38 ;
V_7 -> V_28 = V_81 -> V_9 ;
V_7 -> V_21 = V_63 . V_21 ;
F_49 ( & V_7 -> V_15 ) ;
if ( V_54 == V_85 )
F_50 ( V_4 ) ;
else
F_39 ( & V_80 ) ;
return V_54 ;
V_84:
F_39 ( & V_63 ) ;
return V_54 ;
}
static void F_51 ( struct V_3 * V_4 , int V_41 )
{
struct V_62 V_87 ;
F_41 ( V_4 -> V_8 , & V_87 ) ;
F_39 ( & V_87 ) ;
}
static int T_3 F_52 ( void )
{
return F_53 ( & V_88 , V_89 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_88 ) ;
}
