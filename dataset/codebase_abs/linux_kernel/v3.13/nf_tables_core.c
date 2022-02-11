static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
V_8 = ~ 0U >> ( sizeof( V_7 -> V_4 ) * V_9 - V_7 -> V_10 ) ;
if ( ( V_4 [ V_7 -> V_11 ] . V_4 [ 0 ] & V_8 ) == V_7 -> V_4 )
return;
V_4 [ V_12 ] . V_13 = V_14 ;
}
static bool F_3 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_15 * V_16 )
{
const struct V_17 * V_7 = F_2 ( V_2 ) ;
const struct V_18 * V_19 = V_16 -> V_19 ;
struct V_3 * V_20 = & V_4 [ V_7 -> V_21 ] ;
unsigned char * V_22 ;
if ( V_7 -> V_23 == V_24 )
V_22 = F_4 ( V_19 ) ;
else
V_22 = F_4 ( V_19 ) + V_16 -> V_25 . V_26 ;
V_22 += V_7 -> V_27 ;
if ( F_5 ( V_22 + V_7 -> V_10 >= F_6 ( V_19 ) ) )
return false ;
if ( V_7 -> V_10 == 2 )
* ( V_28 * ) V_20 -> V_4 = * ( V_28 * ) V_22 ;
else if ( V_7 -> V_10 == 4 )
* ( T_1 * ) V_20 -> V_4 = * ( T_1 * ) V_22 ;
else
* ( V_29 * ) V_20 -> V_4 = * ( V_29 * ) V_22 ;
return true ;
}
static inline void
F_7 ( const struct V_30 * V_31 , const struct V_15 * V_16 ,
struct V_32 * V_33 , unsigned int V_34 )
{
struct V_35 T_2 * V_36 ;
const struct V_30 * V_37 = V_34 ? V_33 [ 0 ] . V_37 : V_31 ;
F_8 () ;
V_36 = F_9 ( F_10 ( V_37 ) -> V_36 ) ;
F_11 ( V_36 -> V_38 ) ;
F_12 ( V_36 -> V_39 , V_16 -> V_19 -> V_10 ) ;
F_13 () ;
}
static inline void F_14 ( const struct V_15 * V_16 ,
const struct V_30 * V_37 ,
int V_40 , enum V_41 type )
{
struct V_42 * V_42 = F_15 ( V_16 -> V_43 ? V_16 -> V_43 : V_16 -> V_44 ) ;
F_16 ( V_42 , V_16 -> V_25 . V_45 , V_16 -> V_46 , V_16 -> V_19 , V_16 -> V_43 ,
V_16 -> V_44 , & V_47 , L_1 ,
V_37 -> V_48 -> V_49 , V_37 -> V_49 , V_50 [ type ] ,
V_40 ) ;
}
unsigned int
F_17 ( struct V_15 * V_16 , const struct V_51 * V_52 )
{
const struct V_30 * V_37 = V_52 -> V_7 ;
const struct V_53 * V_54 ;
const struct V_1 * V_2 , * V_55 ;
struct V_3 V_4 [ V_5 + 1 ] ;
unsigned int V_34 = 0 ;
struct V_32 V_33 [ V_56 ] ;
int V_40 = 0 ;
unsigned int V_57 = F_18 ( V_37 -> V_42 -> V_58 . V_57 ) ;
V_59:
V_54 = F_19 ( & V_37 -> V_60 , struct V_53 , V_61 ) ;
V_62:
V_4 [ V_12 ] . V_13 = V_63 ;
F_20 (rule, &chain->rules, list) {
if ( F_5 ( V_54 -> V_64 & ( 1 << V_57 ) ) )
continue;
V_40 ++ ;
F_21 (expr, last, rule) {
if ( V_2 -> V_52 == & V_65 )
F_1 ( V_2 , V_4 ) ;
else if ( V_2 -> V_52 != & V_66 ||
! F_3 ( V_2 , V_4 , V_16 ) )
V_2 -> V_52 -> V_67 ( V_2 , V_4 , V_16 ) ;
if ( V_4 [ V_12 ] . V_13 != V_63 )
break;
}
switch ( V_4 [ V_12 ] . V_13 ) {
case V_14 :
V_4 [ V_12 ] . V_13 = V_63 ;
case V_63 :
continue;
}
break;
}
switch ( V_4 [ V_12 ] . V_13 ) {
case V_68 :
case V_69 :
case V_70 :
if ( F_5 ( V_16 -> V_19 -> V_71 ) )
F_14 ( V_16 , V_37 , V_40 , V_72 ) ;
return V_4 [ V_12 ] . V_13 ;
case V_73 :
if ( F_5 ( V_16 -> V_19 -> V_71 ) )
F_14 ( V_16 , V_37 , V_40 , V_72 ) ;
F_22 ( V_34 >= V_56 ) ;
V_33 [ V_34 ] . V_37 = V_37 ;
V_33 [ V_34 ] . V_54 = V_54 ;
V_33 [ V_34 ] . V_40 = V_40 ;
V_34 ++ ;
case V_74 :
V_37 = V_4 [ V_12 ] . V_37 ;
goto V_59;
case V_75 :
if ( F_5 ( V_16 -> V_19 -> V_71 ) )
F_14 ( V_16 , V_37 , V_40 , V_76 ) ;
case V_63 :
break;
default:
F_23 ( 1 ) ;
}
if ( V_34 > 0 ) {
if ( F_5 ( V_16 -> V_19 -> V_71 ) )
F_14 ( V_16 , V_37 , ++ V_40 , V_76 ) ;
V_34 -- ;
V_37 = V_33 [ V_34 ] . V_37 ;
V_54 = V_33 [ V_34 ] . V_54 ;
V_40 = V_33 [ V_34 ] . V_40 ;
goto V_62;
}
F_7 ( V_37 , V_16 , V_33 , V_34 ) ;
if ( F_5 ( V_16 -> V_19 -> V_71 ) )
F_14 ( V_16 , V_37 , ++ V_40 , V_77 ) ;
return F_10 ( V_37 ) -> V_78 ;
}
int T_3 F_24 ( void )
{
int V_79 ;
V_79 = F_25 () ;
if ( V_79 < 0 )
goto V_80;
V_79 = F_26 () ;
if ( V_79 < 0 )
goto V_81;
V_79 = F_27 () ;
if ( V_79 < 0 )
goto V_82;
V_79 = F_28 () ;
if ( V_79 < 0 )
goto V_83;
V_79 = F_29 () ;
if ( V_79 < 0 )
goto V_84;
V_79 = F_30 () ;
if ( V_79 < 0 )
goto V_85;
return 0 ;
V_85:
F_31 () ;
V_84:
F_32 () ;
V_83:
F_33 () ;
V_82:
F_34 () ;
V_81:
F_35 () ;
V_80:
return V_79 ;
}
void F_36 ( void )
{
F_37 () ;
F_31 () ;
F_32 () ;
F_33 () ;
F_34 () ;
F_35 () ;
}
