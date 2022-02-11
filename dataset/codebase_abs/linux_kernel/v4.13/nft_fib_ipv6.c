static int F_1 ( const struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_3 : 0 ;
}
static int F_2 ( struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
const struct V_10 * V_11 = F_3 ( V_9 -> V_12 ) ;
int V_13 = 0 ;
if ( V_7 -> V_14 & V_15 ) {
V_5 -> V_16 = V_11 -> V_16 ;
V_5 -> V_17 = V_11 -> V_17 ;
} else {
V_5 -> V_16 = V_11 -> V_17 ;
V_5 -> V_17 = V_11 -> V_16 ;
}
if ( F_4 ( & V_5 -> V_16 ) & V_18 ) {
V_13 |= V_19 ;
V_5 -> V_20 = F_1 ( V_2 ? V_2 : V_9 -> V_12 -> V_2 ) ;
}
if ( F_4 ( & V_5 -> V_17 ) & V_21 )
V_13 |= V_22 ;
if ( V_7 -> V_14 & V_23 )
V_5 -> V_24 = V_9 -> V_12 -> V_25 ;
V_5 -> V_26 = ( * ( V_27 * ) V_11 ) & V_28 ;
return V_13 ;
}
static T_1 F_5 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
const struct V_1 * V_2 = NULL ;
const struct V_29 * V_30 ;
const struct V_31 * V_32 ;
int V_33 , V_34 ;
struct V_35 * V_36 ;
struct V_4 V_5 = {
. V_37 = V_38 ,
. V_39 = V_9 -> V_40 ,
} ;
T_1 V_41 = 0 ;
V_32 = F_6 ( V_42 ) ;
if ( ! V_32 )
return V_43 ;
if ( V_7 -> V_14 & V_44 )
V_2 = F_7 ( V_9 ) ;
else if ( V_7 -> V_14 & V_45 )
V_2 = F_8 ( V_9 ) ;
F_2 ( & V_5 , V_7 , V_9 , V_2 ) ;
V_30 = F_9 () ;
if ( V_2 && V_30 && V_30 -> V_46 ( F_10 ( V_9 ) , & V_5 . V_16 , V_2 , true ) )
V_41 = V_47 ;
V_33 = V_32 -> V_48 ( F_10 ( V_9 ) , (struct V_49 * * ) & V_36 ,
F_11 ( & V_5 ) , false ) ;
if ( V_33 )
goto V_50;
if ( V_36 -> V_51 & V_52 ) {
V_33 = V_36 -> V_53 . error ;
F_12 ( & V_36 -> V_53 ) ;
goto V_50;
}
if ( F_13 ( (struct V_49 * ) V_36 , & V_5 . V_16 ) )
V_41 = V_54 ;
else if ( ! V_2 && V_36 -> V_51 & V_55 )
V_41 = V_47 ;
F_12 ( & V_36 -> V_53 ) ;
if ( V_41 )
return V_41 ;
V_34 = F_4 ( & V_5 . V_16 ) ;
if ( V_34 & V_56 )
return V_57 ;
if ( V_34 & V_21 )
return V_58 ;
return V_59 ;
V_50:
switch ( V_33 ) {
case - V_60 :
return V_61 ;
case - V_62 :
return V_63 ;
case - V_64 :
return V_65 ;
default:
break;
}
return V_43 ;
}
void F_14 ( const struct V_66 * V_67 , struct V_68 * V_69 ,
const struct V_8 * V_9 )
{
const struct V_6 * V_7 = F_15 ( V_67 ) ;
T_1 * V_70 = & V_69 -> V_71 [ V_7 -> V_72 ] ;
* V_70 = F_5 ( V_7 , V_9 ) ;
}
void F_16 ( const struct V_66 * V_67 , struct V_68 * V_69 ,
const struct V_8 * V_9 )
{
const struct V_6 * V_7 = F_15 ( V_67 ) ;
const struct V_1 * V_73 = NULL ;
T_1 * V_70 = & V_69 -> V_71 [ V_7 -> V_72 ] ;
struct V_4 V_5 = {
. V_37 = V_38 ,
. V_39 = V_9 -> V_40 ,
} ;
struct V_35 * V_36 ;
int V_13 ;
if ( V_7 -> V_14 & V_44 )
V_73 = F_7 ( V_9 ) ;
else if ( V_7 -> V_14 & V_45 )
V_73 = F_8 ( V_9 ) ;
V_13 = F_2 ( & V_5 , V_7 , V_9 , V_73 ) ;
if ( F_17 ( V_9 ) == V_74 &&
F_18 ( V_9 -> V_12 , F_7 ( V_9 ) ) ) {
F_19 ( V_70 , V_7 , V_9 ,
F_7 ( V_9 ) -> V_3 ) ;
return;
}
* V_70 = 0 ;
V_75:
V_36 = ( void * ) F_20 ( F_10 ( V_9 ) , & V_5 , V_13 ) ;
if ( V_36 -> V_53 . error )
goto V_76;
if ( V_36 -> V_51 & ( V_52 | V_77 | V_55 ) )
goto V_76;
if ( V_73 && V_73 != V_36 -> V_78 -> V_2 ) {
if ( ( V_13 & V_19 ) == 0 ) {
V_13 |= V_19 ;
V_5 . V_20 = V_73 -> V_3 ;
F_21 ( V_36 ) ;
goto V_75;
}
}
switch ( V_7 -> V_79 ) {
case V_80 :
* V_70 = V_36 -> V_78 -> V_2 -> V_3 ;
break;
case V_81 :
strncpy ( ( char * ) V_70 , V_36 -> V_78 -> V_2 -> V_82 , V_83 ) ;
break;
default:
F_22 ( 1 ) ;
break;
}
V_76:
F_21 ( V_36 ) ;
}
static const struct V_84 *
F_23 ( const struct V_85 * V_86 ,
const struct V_87 * const V_88 [] )
{
enum V_89 V_79 ;
if ( ! V_88 [ V_90 ] )
return F_24 ( - V_60 ) ;
V_79 = F_25 ( F_26 ( V_88 [ V_90 ] ) ) ;
switch ( V_79 ) {
case V_80 :
return & V_91 ;
case V_81 :
return & V_91 ;
case V_92 :
return & V_93 ;
default:
return F_24 ( - V_94 ) ;
}
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_95 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_95 ) ;
}
