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
if ( F_23 ( V_2 , V_35 , V_8 -> V_10 -> V_36 -> V_37 ) )
return - V_30 ;
V_27 = F_18 ( V_2 , V_38 , sizeof( V_8 -> V_10 -> V_39 ) ) ;
if ( V_27 == NULL )
return - V_30 ;
memcpy ( F_19 ( V_27 ) , V_8 -> V_10 -> V_39 , F_20 ( V_27 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_40 , int V_41 )
{
unsigned char * V_42 = F_25 ( V_2 ) ;
struct F_1 * V_8 = F_3 ( V_4 ) ;
struct V_43 V_44 = {
. V_45 = V_8 -> V_46 ,
. V_47 = V_8 -> V_48 - V_41 ,
. V_49 = V_8 -> V_50 - V_40 ,
. V_11 = V_8 -> V_24 ,
} ;
struct V_51 V_52 ;
int V_53 ;
if ( F_26 ( V_2 , V_54 , sizeof( V_44 ) , & V_44 ) )
goto V_55;
if ( F_15 ( V_8 ) )
V_53 = F_21 ( V_8 , V_2 ) ;
else
V_53 = F_16 ( V_8 , V_2 ) ;
if ( V_53 )
goto V_55;
F_27 ( & V_52 , & V_8 -> V_13 ) ;
if ( F_28 ( V_2 , V_56 , sizeof( V_52 ) , & V_52 ,
V_57 ) )
goto V_55;
return V_2 -> V_58 ;
V_55:
F_29 ( V_2 , V_42 ) ;
return - 1 ;
}
static int F_30 ( struct V_26 * * V_59 , struct V_60 * V_61 )
{
struct V_32 * V_25 ;
struct V_62 V_63 ;
struct V_9 * V_64 ;
T_1 V_65 , V_29 ;
int V_53 ;
V_29 = F_31 ( V_59 [ V_28 ] ) ;
if ( V_29 > V_66 || V_29 == 0 )
return - V_67 ;
V_65 = V_29 * sizeof( * V_25 ) ;
if ( V_65 != F_20 ( V_59 [ V_31 ] ) )
return - V_67 ;
V_25 = F_32 ( V_65 , V_68 ) ;
if ( V_25 == NULL )
return - V_69 ;
memcpy ( V_25 , F_19 ( V_59 [ V_31 ] ) , V_65 ) ;
V_63 . V_58 = V_29 ;
V_63 . V_10 = V_25 ;
V_53 = F_33 ( & V_64 , & V_63 ) ;
if ( V_53 < 0 ) {
F_34 ( V_25 ) ;
return V_53 ;
}
V_61 -> V_25 = V_25 ;
V_61 -> V_29 = V_29 ;
V_61 -> V_10 = V_64 ;
V_61 -> V_70 = false ;
return 0 ;
}
static int F_35 ( struct V_26 * * V_59 , struct V_60 * V_61 )
{
struct V_9 * V_64 ;
char * V_71 = NULL ;
T_2 V_72 ;
V_72 = F_36 ( V_59 [ V_73 ] ) ;
V_64 = F_37 ( V_72 , V_74 ) ;
if ( F_38 ( V_64 ) )
return F_39 ( V_64 ) ;
if ( V_59 [ V_34 ] ) {
V_71 = F_40 ( V_59 [ V_34 ] , V_68 ) ;
if ( ! V_71 ) {
F_41 ( V_64 ) ;
return - V_69 ;
}
}
V_61 -> V_33 = V_71 ;
V_61 -> V_10 = V_64 ;
V_61 -> V_70 = true ;
return 0 ;
}
static void F_42 ( const struct V_60 * V_61 )
{
if ( V_61 -> V_70 )
F_41 ( V_61 -> V_10 ) ;
else
F_43 ( V_61 -> V_10 ) ;
F_34 ( V_61 -> V_25 ) ;
F_34 ( V_61 -> V_33 ) ;
}
static void F_44 ( const struct F_1 * V_8 ,
struct V_60 * V_61 )
{
V_61 -> V_70 = F_15 ( V_8 ) ;
V_61 -> V_10 = F_45 ( V_8 -> V_10 , 1 ) ;
V_61 -> V_25 = V_8 -> V_25 ;
V_61 -> V_33 = V_8 -> V_33 ;
}
static int F_46 ( struct V_75 * V_75 , struct V_26 * V_27 ,
struct V_26 * V_76 , struct V_3 * * V_4 ,
int V_77 , int V_40 )
{
struct V_78 * V_79 = F_47 ( V_75 , V_80 ) ;
struct V_26 * V_59 [ V_81 + 1 ] ;
struct V_60 V_61 , V_82 ;
struct V_43 * V_83 ;
struct F_1 * V_8 ;
bool V_84 , V_70 ;
int V_53 , V_6 = 0 ;
if ( ! V_27 )
return - V_67 ;
V_53 = F_48 ( V_59 , V_81 , V_27 , V_85 , NULL ) ;
if ( V_53 < 0 )
return V_53 ;
if ( ! V_59 [ V_54 ] )
return - V_67 ;
V_83 = F_19 ( V_59 [ V_54 ] ) ;
if ( ! F_49 ( V_79 , V_83 -> V_45 , V_4 , V_40 ) ) {
V_53 = F_50 ( V_79 , V_83 -> V_45 , V_76 , V_4 ,
& V_86 , V_40 , true ) ;
if ( V_53 < 0 )
return V_53 ;
V_6 = V_87 ;
} else {
if ( V_40 )
return 0 ;
F_51 ( * V_4 , V_40 ) ;
if ( ! V_77 )
return - V_88 ;
}
V_84 = V_59 [ V_28 ] && V_59 [ V_31 ] ;
V_70 = V_59 [ V_73 ] ;
if ( ( ! V_84 && ! V_70 ) || ( V_84 && V_70 ) ) {
V_53 = - V_67 ;
goto V_89;
}
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_53 = V_84 ? F_30 ( V_59 , & V_61 ) :
F_35 ( V_59 , & V_61 ) ;
if ( V_53 < 0 )
goto V_89;
V_8 = F_3 ( * V_4 ) ;
F_52 () ;
if ( V_6 != V_87 )
F_44 ( V_8 , & V_82 ) ;
V_8 -> V_25 = V_61 . V_25 ;
V_8 -> V_33 = V_61 . V_33 ;
if ( V_61 . V_29 )
V_8 -> V_29 = V_61 . V_29 ;
V_8 -> V_24 = V_83 -> V_11 ;
F_53 ( V_8 -> V_10 , V_61 . V_10 ) ;
if ( V_6 == V_87 ) {
F_54 ( V_79 , * V_4 ) ;
} else {
F_55 () ;
F_42 ( & V_82 ) ;
}
return V_6 ;
V_89:
if ( V_6 == V_87 )
F_56 ( * V_4 , V_76 ) ;
return V_53 ;
}
static void F_57 ( struct V_3 * V_4 , int V_40 )
{
struct V_60 V_90 ;
F_44 ( F_3 ( V_4 ) , & V_90 ) ;
F_42 ( & V_90 ) ;
}
static int F_58 ( struct V_75 * V_75 , struct V_1 * V_2 ,
struct V_91 * V_92 , int type ,
const struct V_93 * V_94 )
{
struct V_78 * V_79 = F_47 ( V_75 , V_80 ) ;
return F_59 ( V_79 , V_2 , V_92 , type , V_94 ) ;
}
static int F_60 ( struct V_75 * V_75 , struct V_3 * * V_95 , T_2 V_45 )
{
struct V_78 * V_79 = F_47 ( V_75 , V_80 ) ;
return F_61 ( V_79 , V_95 , V_45 ) ;
}
static T_3 int F_62 ( struct V_75 * V_75 )
{
struct V_78 * V_79 = F_47 ( V_75 , V_80 ) ;
return F_63 ( V_79 , & V_86 , V_96 ) ;
}
static void T_4 F_64 ( struct V_75 * V_75 )
{
struct V_78 * V_79 = F_47 ( V_75 , V_80 ) ;
F_65 ( V_79 ) ;
}
static int T_5 F_66 ( void )
{
return F_67 ( & V_86 , & V_97 ) ;
}
static void T_6 F_68 ( void )
{
F_69 ( & V_86 , & V_97 ) ;
}
