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
V_11 = V_12 ;
break;
case V_24 :
V_11 = V_12 ;
F_14 ( F_7 ( V_7 -> V_18 . V_25 ) ) ;
break;
case V_16 :
V_11 = V_7 -> V_26 ;
break;
default:
V_11 = V_16 ;
break;
}
return V_11 ;
}
static bool F_15 ( const struct F_1 * V_7 )
{
return ! V_7 -> V_27 ;
}
static int F_16 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 ;
if ( F_17 ( V_2 , V_30 , V_7 -> V_31 ) )
return - V_32 ;
V_29 = F_18 ( V_2 , V_33 , V_7 -> V_31 *
sizeof( struct V_34 ) ) ;
if ( V_29 == NULL )
return - V_32 ;
memcpy ( F_19 ( V_29 ) , V_7 -> V_27 , F_20 ( V_29 ) ) ;
return 0 ;
}
static int F_21 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
if ( F_22 ( V_2 , V_35 , V_7 -> V_36 ) )
return - V_32 ;
if ( V_7 -> V_37 &&
F_23 ( V_2 , V_38 , V_7 -> V_37 ) )
return - V_32 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_39 , int V_40 )
{
unsigned char * V_41 = F_25 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_42 V_43 = {
. V_44 = V_7 -> V_45 ,
. V_46 = V_7 -> V_47 - V_40 ,
. V_48 = V_7 -> V_49 - V_39 ,
. V_11 = V_7 -> V_26 ,
} ;
struct V_50 V_51 ;
int V_52 ;
if ( F_26 ( V_2 , V_53 , sizeof( V_43 ) , & V_43 ) )
goto V_54;
if ( F_15 ( V_7 ) )
V_52 = F_21 ( V_7 , V_2 ) ;
else
V_52 = F_16 ( V_7 , V_2 ) ;
if ( V_52 )
goto V_54;
V_51 . V_55 = F_27 ( V_56 - V_7 -> V_17 . V_55 ) ;
V_51 . V_57 = F_27 ( V_56 - V_7 -> V_17 . V_57 ) ;
V_51 . V_58 = F_27 ( V_7 -> V_17 . V_58 ) ;
if ( F_26 ( V_2 , V_59 , sizeof( V_51 ) , & V_51 ) )
goto V_54;
return V_2 -> V_60 ;
V_54:
F_28 ( V_2 , V_41 ) ;
return - 1 ;
}
static int F_29 ( struct V_28 * * V_61 , struct V_62 * V_63 )
{
struct V_34 * V_27 ;
struct V_64 V_65 ;
struct V_9 * V_66 ;
T_1 V_67 , V_31 ;
int V_52 ;
V_31 = F_30 ( V_61 [ V_30 ] ) ;
if ( V_31 > V_68 || V_31 == 0 )
return - V_69 ;
V_67 = V_31 * sizeof( * V_27 ) ;
if ( V_67 != F_20 ( V_61 [ V_33 ] ) )
return - V_69 ;
V_27 = F_31 ( V_67 , V_70 ) ;
if ( V_27 == NULL )
return - V_71 ;
memcpy ( V_27 , F_19 ( V_61 [ V_33 ] ) , V_67 ) ;
V_65 . V_60 = V_31 ;
V_65 . V_10 = V_27 ;
V_52 = F_32 ( & V_66 , & V_65 ) ;
if ( V_52 < 0 ) {
F_33 ( V_27 ) ;
return V_52 ;
}
V_63 -> V_27 = V_27 ;
V_63 -> V_31 = V_31 ;
V_63 -> V_10 = V_66 ;
V_63 -> V_72 = false ;
return 0 ;
}
static int F_34 ( struct V_28 * * V_61 , struct V_62 * V_63 )
{
struct V_9 * V_66 ;
char * V_73 = NULL ;
T_2 V_36 ;
V_36 = F_35 ( V_61 [ V_35 ] ) ;
V_66 = F_36 ( V_36 ) ;
if ( F_37 ( V_66 ) )
return F_38 ( V_66 ) ;
if ( V_66 -> type != V_74 ) {
F_39 ( V_66 ) ;
return - V_69 ;
}
if ( V_61 [ V_38 ] ) {
V_73 = F_40 ( F_19 ( V_61 [ V_38 ] ) ,
F_20 ( V_61 [ V_38 ] ) ,
V_70 ) ;
if ( ! V_73 ) {
F_39 ( V_66 ) ;
return - V_71 ;
}
}
V_63 -> V_36 = V_36 ;
V_63 -> V_37 = V_73 ;
V_63 -> V_10 = V_66 ;
V_63 -> V_72 = true ;
return 0 ;
}
static void F_41 ( const struct V_62 * V_63 )
{
if ( V_63 -> V_72 )
F_39 ( V_63 -> V_10 ) ;
else
F_42 ( V_63 -> V_10 ) ;
F_33 ( V_63 -> V_27 ) ;
F_33 ( V_63 -> V_37 ) ;
}
static void F_43 ( const struct F_1 * V_7 ,
struct V_62 * V_63 )
{
V_63 -> V_72 = F_15 ( V_7 ) ;
V_63 -> V_10 = F_44 ( V_7 -> V_10 , 1 ) ;
V_63 -> V_27 = V_7 -> V_27 ;
V_63 -> V_37 = V_7 -> V_37 ;
}
static int F_45 ( struct V_75 * V_75 , struct V_28 * V_29 ,
struct V_28 * V_76 , struct V_3 * V_4 ,
int V_77 , int V_39 )
{
struct V_28 * V_61 [ V_78 + 1 ] ;
struct V_62 V_63 , V_79 ;
struct V_42 * V_80 ;
struct F_1 * V_7 ;
bool V_81 , V_72 ;
int V_52 , V_6 = 0 ;
if ( ! V_29 )
return - V_69 ;
V_52 = F_46 ( V_61 , V_78 , V_29 , V_82 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( ! V_61 [ V_53 ] )
return - V_69 ;
V_80 = F_19 ( V_61 [ V_53 ] ) ;
if ( ! F_47 ( V_80 -> V_44 , V_4 , V_39 ) ) {
V_52 = F_48 ( V_80 -> V_44 , V_76 , V_4 ,
sizeof( * V_7 ) , V_39 , true ) ;
if ( V_52 < 0 )
return V_52 ;
V_6 = V_83 ;
} else {
if ( V_39 )
return 0 ;
F_49 ( V_4 , V_39 ) ;
if ( ! V_77 )
return - V_84 ;
}
V_81 = V_61 [ V_30 ] && V_61 [ V_33 ] ;
V_72 = V_61 [ V_35 ] ;
if ( ( ! V_81 && ! V_72 ) || ( V_81 && V_72 ) ) {
V_52 = - V_69 ;
goto V_85;
}
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_52 = V_81 ? F_29 ( V_61 , & V_63 ) :
F_34 ( V_61 , & V_63 ) ;
if ( V_52 < 0 )
goto V_85;
V_7 = F_50 ( V_4 ) ;
F_51 () ;
if ( V_6 != V_83 )
F_43 ( V_7 , & V_79 ) ;
V_7 -> V_27 = V_63 . V_27 ;
V_7 -> V_37 = V_63 . V_37 ;
if ( V_63 . V_31 )
V_7 -> V_31 = V_63 . V_31 ;
if ( V_63 . V_36 )
V_7 -> V_36 = V_63 . V_36 ;
V_7 -> V_26 = V_80 -> V_11 ;
F_52 ( V_7 -> V_10 , V_63 . V_10 ) ;
if ( V_6 == V_83 ) {
F_53 ( V_4 ) ;
} else {
F_54 () ;
F_41 ( & V_79 ) ;
}
return V_6 ;
V_85:
if ( V_6 == V_83 )
F_55 ( V_4 , V_76 ) ;
return V_52 ;
}
static void F_56 ( struct V_3 * V_4 , int V_39 )
{
struct V_62 V_86 ;
F_43 ( V_4 -> V_8 , & V_86 ) ;
F_41 ( & V_86 ) ;
}
static int T_3 F_57 ( void )
{
return F_58 ( & V_87 , V_88 ) ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_87 ) ;
}
