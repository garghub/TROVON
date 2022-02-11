static int F_1 ( const struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_3 : 0 ;
}
static int F_2 ( struct V_4 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
const struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_12 = 0 ;
if ( V_7 -> V_13 & V_14 ) {
V_5 -> V_15 = V_11 -> V_15 ;
V_5 -> V_16 = V_11 -> V_16 ;
} else {
V_5 -> V_15 = V_11 -> V_16 ;
V_5 -> V_16 = V_11 -> V_15 ;
}
if ( F_3 ( & V_5 -> V_15 ) & V_17 ) {
V_12 |= V_18 ;
V_5 -> V_19 = F_1 ( V_2 ? V_2 : V_9 -> V_20 -> V_2 ) ;
}
if ( F_3 ( & V_5 -> V_16 ) & V_21 )
V_12 |= V_22 ;
if ( V_7 -> V_13 & V_23 )
V_5 -> V_24 = V_9 -> V_20 -> V_25 ;
V_5 -> V_26 = ( * ( V_27 * ) V_11 ) & V_28 ;
return V_12 ;
}
static T_1 F_4 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_10 * V_11 )
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
V_32 = F_5 ( V_42 ) ;
if ( ! V_32 )
return V_43 ;
if ( V_7 -> V_13 & V_44 )
V_2 = F_6 ( V_9 ) ;
else if ( V_7 -> V_13 & V_45 )
V_2 = F_7 ( V_9 ) ;
F_2 ( & V_5 , V_7 , V_9 , V_2 , V_11 ) ;
V_30 = F_8 () ;
if ( V_2 && V_30 && V_30 -> V_46 ( F_9 ( V_9 ) , & V_5 . V_15 , V_2 , true ) )
V_41 = V_47 ;
V_33 = V_32 -> V_48 ( F_9 ( V_9 ) , (struct V_49 * * ) & V_36 ,
F_10 ( & V_5 ) , false ) ;
if ( V_33 )
goto V_50;
if ( V_36 -> V_51 & V_52 ) {
V_33 = V_36 -> V_53 . error ;
F_11 ( & V_36 -> V_53 ) ;
goto V_50;
}
if ( F_12 ( (struct V_49 * ) V_36 , & V_5 . V_15 ) )
V_41 = V_54 ;
else if ( ! V_2 && V_36 -> V_51 & V_55 )
V_41 = V_47 ;
F_11 ( & V_36 -> V_53 ) ;
if ( V_41 )
return V_41 ;
V_34 = F_3 ( & V_5 . V_15 ) ;
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
void F_13 ( const struct V_66 * V_67 , struct V_68 * V_69 ,
const struct V_8 * V_9 )
{
const struct V_6 * V_7 = F_14 ( V_67 ) ;
int V_70 = F_15 ( V_9 -> V_20 ) ;
T_1 * V_71 = & V_69 -> V_72 [ V_7 -> V_73 ] ;
struct V_10 * V_11 , V_74 ;
V_11 = F_16 ( V_9 -> V_20 , V_70 , sizeof( V_74 ) , & V_74 ) ;
if ( ! V_11 ) {
V_69 -> V_75 . V_76 = V_77 ;
return;
}
* V_71 = F_4 ( V_7 , V_9 , V_11 ) ;
}
void F_17 ( const struct V_66 * V_67 , struct V_68 * V_69 ,
const struct V_8 * V_9 )
{
const struct V_6 * V_7 = F_14 ( V_67 ) ;
int V_70 = F_15 ( V_9 -> V_20 ) ;
const struct V_1 * V_78 = NULL ;
T_1 * V_71 = & V_69 -> V_72 [ V_7 -> V_73 ] ;
struct V_10 * V_11 , V_74 ;
struct V_4 V_5 = {
. V_37 = V_38 ,
. V_39 = V_9 -> V_40 ,
} ;
struct V_35 * V_36 ;
int V_12 ;
if ( V_7 -> V_13 & V_44 )
V_78 = F_6 ( V_9 ) ;
else if ( V_7 -> V_13 & V_45 )
V_78 = F_7 ( V_9 ) ;
V_11 = F_16 ( V_9 -> V_20 , V_70 , sizeof( V_74 ) , & V_74 ) ;
if ( ! V_11 ) {
V_69 -> V_75 . V_76 = V_77 ;
return;
}
V_12 = F_2 ( & V_5 , V_7 , V_9 , V_78 , V_11 ) ;
if ( F_18 ( V_9 ) == V_79 &&
F_19 ( V_9 -> V_20 , F_6 ( V_9 ) ) ) {
F_20 ( V_71 , V_7 , V_9 ,
F_6 ( V_9 ) -> V_3 ) ;
return;
}
* V_71 = 0 ;
V_80:
V_36 = ( void * ) F_21 ( F_9 ( V_9 ) , & V_5 , V_12 ) ;
if ( V_36 -> V_53 . error )
goto V_81;
if ( V_36 -> V_51 & ( V_52 | V_82 | V_55 ) )
goto V_81;
if ( V_78 && V_78 != V_36 -> V_83 -> V_2 ) {
if ( ( V_12 & V_18 ) == 0 ) {
V_12 |= V_18 ;
V_5 . V_19 = V_78 -> V_3 ;
F_22 ( V_36 ) ;
goto V_80;
}
}
switch ( V_7 -> V_84 ) {
case V_85 :
* V_71 = V_36 -> V_83 -> V_2 -> V_3 ;
break;
case V_86 :
strncpy ( ( char * ) V_71 , V_36 -> V_83 -> V_2 -> V_87 , V_88 ) ;
break;
default:
F_23 ( 1 ) ;
break;
}
V_81:
F_22 ( V_36 ) ;
}
static const struct V_89 *
F_24 ( const struct V_90 * V_91 ,
const struct V_92 * const V_93 [] )
{
enum V_94 V_84 ;
if ( ! V_93 [ V_95 ] )
return F_25 ( - V_60 ) ;
V_84 = F_26 ( F_27 ( V_93 [ V_95 ] ) ) ;
switch ( V_84 ) {
case V_85 :
return & V_96 ;
case V_86 :
return & V_96 ;
case V_97 :
return & V_98 ;
default:
return F_25 ( - V_99 ) ;
}
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_100 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_100 ) ;
}
