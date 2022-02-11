static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
int V_9 , V_10 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return V_11 ;
F_4 ( & V_7 -> V_12 ) ;
V_7 -> V_13 . V_14 = V_15 ;
F_5 ( & V_7 -> V_16 , V_2 ) ;
F_6 () ;
V_10 = F_7 ( V_7 -> V_17 , V_2 ) ;
F_8 () ;
switch ( V_10 ) {
case V_18 :
case V_19 :
case V_20 :
V_9 = V_10 ;
break;
case V_21 :
V_9 = V_10 ;
V_7 -> V_22 . V_23 ++ ;
break;
case V_11 :
V_9 = V_7 -> V_24 ;
break;
default:
V_9 = V_11 ;
break;
}
F_9 ( & V_7 -> V_12 ) ;
return V_9 ;
}
static bool F_10 ( const struct F_1 * V_7 )
{
return ! V_7 -> V_25 ;
}
static int F_11 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 ;
if ( F_12 ( V_2 , V_28 , V_7 -> V_29 ) )
return - V_30 ;
V_27 = F_13 ( V_2 , V_31 , V_7 -> V_29 *
sizeof( struct V_32 ) ) ;
if ( V_27 == NULL )
return - V_30 ;
memcpy ( F_14 ( V_27 ) , V_7 -> V_25 , F_15 ( V_27 ) ) ;
return 0 ;
}
static int F_16 ( const struct F_1 * V_7 ,
struct V_1 * V_2 )
{
if ( F_17 ( V_2 , V_33 , V_7 -> V_34 ) )
return - V_30 ;
if ( V_7 -> V_35 &&
F_18 ( V_2 , V_36 , V_7 -> V_35 ) )
return - V_30 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_37 , int V_38 )
{
unsigned char * V_39 = F_20 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_40 V_41 = {
. V_42 = V_7 -> V_43 ,
. V_44 = V_7 -> V_45 - V_38 ,
. V_46 = V_7 -> V_47 - V_37 ,
. V_9 = V_7 -> V_24 ,
} ;
struct V_48 V_49 ;
int V_50 ;
if ( F_21 ( V_2 , V_51 , sizeof( V_41 ) , & V_41 ) )
goto V_52;
if ( F_10 ( V_7 ) )
V_50 = F_16 ( V_7 , V_2 ) ;
else
V_50 = F_11 ( V_7 , V_2 ) ;
if ( V_50 )
goto V_52;
V_49 . V_53 = F_22 ( V_15 - V_7 -> V_13 . V_53 ) ;
V_49 . V_14 = F_22 ( V_15 - V_7 -> V_13 . V_14 ) ;
V_49 . V_54 = F_22 ( V_7 -> V_13 . V_54 ) ;
if ( F_21 ( V_2 , V_55 , sizeof( V_49 ) , & V_49 ) )
goto V_52;
return V_2 -> V_56 ;
V_52:
F_23 ( V_2 , V_39 ) ;
return - 1 ;
}
static int F_24 ( struct V_26 * * V_57 , struct V_58 * V_59 )
{
struct V_32 * V_25 ;
struct V_60 V_61 ;
struct V_62 * V_63 ;
T_1 V_64 , V_29 ;
int V_50 ;
V_29 = F_25 ( V_57 [ V_28 ] ) ;
if ( V_29 > V_65 || V_29 == 0 )
return - V_66 ;
V_64 = V_29 * sizeof( * V_25 ) ;
if ( V_64 != F_15 ( V_57 [ V_31 ] ) )
return - V_66 ;
V_25 = F_26 ( V_64 , V_67 ) ;
if ( V_25 == NULL )
return - V_68 ;
memcpy ( V_25 , F_14 ( V_57 [ V_31 ] ) , V_64 ) ;
V_61 . V_56 = V_29 ;
V_61 . V_17 = V_25 ;
V_50 = F_27 ( & V_63 , & V_61 ) ;
if ( V_50 < 0 ) {
F_28 ( V_25 ) ;
return V_50 ;
}
V_59 -> V_25 = V_25 ;
V_59 -> V_29 = V_29 ;
V_59 -> V_17 = V_63 ;
return 0 ;
}
static int F_29 ( struct V_26 * * V_57 , struct V_58 * V_59 )
{
struct V_62 * V_63 ;
char * V_69 = NULL ;
T_2 V_34 ;
V_34 = F_30 ( V_57 [ V_33 ] ) ;
V_63 = F_31 ( V_34 ) ;
if ( F_32 ( V_63 ) )
return F_33 ( V_63 ) ;
if ( V_63 -> type != V_70 ) {
F_34 ( V_63 ) ;
return - V_66 ;
}
if ( V_57 [ V_36 ] ) {
V_69 = F_35 ( F_14 ( V_57 [ V_36 ] ) ,
F_15 ( V_57 [ V_36 ] ) ,
V_67 ) ;
if ( ! V_69 ) {
F_34 ( V_63 ) ;
return - V_68 ;
}
}
V_59 -> V_34 = V_34 ;
V_59 -> V_35 = V_69 ;
V_59 -> V_17 = V_63 ;
return 0 ;
}
static int F_36 ( struct V_71 * V_71 , struct V_26 * V_27 ,
struct V_26 * V_72 , struct V_3 * V_4 ,
int V_73 , int V_37 )
{
struct V_26 * V_57 [ V_74 + 1 ] ;
struct V_40 * V_75 ;
struct F_1 * V_7 ;
struct V_58 V_59 ;
bool V_76 , V_77 ;
int V_50 ;
if ( ! V_27 )
return - V_66 ;
V_50 = F_37 ( V_57 , V_74 , V_27 , V_78 ) ;
if ( V_50 < 0 )
return V_50 ;
V_76 = V_57 [ V_28 ] && V_57 [ V_31 ] ;
V_77 = V_57 [ V_33 ] ;
if ( ( ! V_76 && ! V_77 ) || ( V_76 && V_77 ) ||
! V_57 [ V_51 ] )
return - V_66 ;
V_75 = F_14 ( V_57 [ V_51 ] ) ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_50 = V_76 ? F_24 ( V_57 , & V_59 ) :
F_29 ( V_57 , & V_59 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( ! F_38 ( V_75 -> V_42 , V_4 , V_37 ) ) {
V_50 = F_39 ( V_75 -> V_42 , V_72 , V_4 ,
sizeof( * V_7 ) , V_37 ) ;
if ( V_50 < 0 )
goto V_79;
V_50 = V_80 ;
} else {
if ( V_37 )
goto V_79;
F_40 ( V_4 , V_37 ) ;
if ( ! V_73 ) {
V_50 = - V_81 ;
goto V_79;
}
}
V_7 = F_41 ( V_4 ) ;
F_42 ( & V_7 -> V_12 ) ;
V_7 -> V_25 = V_59 . V_25 ;
V_7 -> V_35 = V_59 . V_35 ;
if ( V_59 . V_29 )
V_7 -> V_29 = V_59 . V_29 ;
if ( V_59 . V_34 )
V_7 -> V_34 = V_59 . V_34 ;
V_7 -> V_24 = V_75 -> V_9 ;
V_7 -> V_17 = V_59 . V_17 ;
F_43 ( & V_7 -> V_12 ) ;
if ( V_50 == V_80 )
F_44 ( V_4 ) ;
return V_50 ;
V_79:
if ( V_77 )
F_34 ( V_59 . V_17 ) ;
else
F_45 ( V_59 . V_17 ) ;
F_28 ( V_59 . V_25 ) ;
F_28 ( V_59 . V_35 ) ;
return V_50 ;
}
static void F_46 ( struct V_3 * V_4 , int V_37 )
{
const struct F_1 * V_7 = V_4 -> V_8 ;
if ( F_10 ( V_7 ) )
F_34 ( V_7 -> V_17 ) ;
else
F_45 ( V_7 -> V_17 ) ;
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_82 , V_83 ) ;
}
static void T_4 F_49 ( void )
{
F_50 ( & V_82 ) ;
}
