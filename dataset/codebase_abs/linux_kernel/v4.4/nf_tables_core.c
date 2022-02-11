static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , enum V_6 type )
{
F_2 ( V_2 -> V_7 , V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_10 , V_2 -> V_11 ,
V_2 -> V_12 , & V_13 , L_1 ,
V_4 -> V_14 -> V_15 , V_4 -> V_15 , V_16 [ type ] ,
V_5 ) ;
}
static inline void F_3 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , enum V_6 type )
{
if ( F_4 ( V_2 -> V_10 -> V_17 ) )
F_1 ( V_2 , V_4 , V_5 , type ) ;
}
static void F_5 ( const struct V_18 * V_19 ,
struct V_20 * V_21 )
{
const struct V_22 * V_23 = F_6 ( V_19 ) ;
T_1 V_24 = F_7 ( V_23 -> V_25 ) ;
if ( ( V_21 -> V_26 [ V_23 -> V_27 ] & V_24 ) == V_23 -> V_26 )
return;
V_21 -> V_28 . V_29 = V_30 ;
}
static bool F_8 ( const struct V_18 * V_19 ,
struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
const struct V_31 * V_23 = F_6 ( V_19 ) ;
const struct V_32 * V_10 = V_2 -> V_10 ;
T_1 * V_33 = & V_21 -> V_26 [ V_23 -> V_34 ] ;
unsigned char * V_35 ;
if ( V_23 -> V_36 == V_37 )
V_35 = F_9 ( V_10 ) ;
else
V_35 = F_9 ( V_10 ) + V_2 -> V_38 . V_39 ;
V_35 += V_23 -> V_40 ;
if ( F_4 ( V_35 + V_23 -> V_25 >= F_10 ( V_10 ) ) )
return false ;
* V_33 = 0 ;
if ( V_23 -> V_25 == 2 )
* ( V_41 * ) V_33 = * ( V_41 * ) V_35 ;
else if ( V_23 -> V_25 == 4 )
* ( T_1 * ) V_33 = * ( T_1 * ) V_35 ;
else
* ( V_42 * ) V_33 = * ( V_42 * ) V_35 ;
return true ;
}
unsigned int
F_11 ( struct V_1 * V_2 , void * V_23 )
{
const struct V_3 * V_4 = V_23 , * V_43 = V_4 ;
const struct V_7 * V_7 = V_2 -> V_7 ;
const struct V_44 * V_45 ;
const struct V_18 * V_19 , * V_46 ;
struct V_20 V_21 ;
unsigned int V_47 = 0 ;
struct V_48 V_49 [ V_50 ] ;
struct V_51 * V_52 ;
int V_5 ;
unsigned int V_53 = F_12 ( V_7 ) ;
V_54:
V_5 = 0 ;
V_45 = F_13 ( & V_4 -> V_55 , struct V_44 , V_56 ) ;
V_57:
V_21 . V_28 . V_29 = V_58 ;
F_14 (rule, &chain->rules, list) {
if ( F_4 ( V_45 -> V_59 & ( 1 << V_53 ) ) )
continue;
V_5 ++ ;
F_15 (expr, last, rule) {
if ( V_19 -> V_60 == & V_61 )
F_5 ( V_19 , & V_21 ) ;
else if ( V_19 -> V_60 != & V_62 ||
! F_8 ( V_19 , & V_21 , V_2 ) )
V_19 -> V_60 -> V_63 ( V_19 , & V_21 , V_2 ) ;
if ( V_21 . V_28 . V_29 != V_58 )
break;
}
switch ( V_21 . V_28 . V_29 ) {
case V_30 :
V_21 . V_28 . V_29 = V_58 ;
continue;
case V_58 :
F_3 ( V_2 , V_4 , V_5 , V_64 ) ;
continue;
}
break;
}
switch ( V_21 . V_28 . V_29 & V_65 ) {
case V_66 :
case V_67 :
case V_68 :
F_3 ( V_2 , V_4 , V_5 , V_64 ) ;
return V_21 . V_28 . V_29 ;
}
switch ( V_21 . V_28 . V_29 ) {
case V_69 :
F_16 ( V_47 >= V_50 ) ;
V_49 [ V_47 ] . V_4 = V_4 ;
V_49 [ V_47 ] . V_45 = V_45 ;
V_49 [ V_47 ] . V_5 = V_5 ;
V_47 ++ ;
case V_70 :
F_3 ( V_2 , V_4 , V_5 , V_64 ) ;
V_4 = V_21 . V_28 . V_4 ;
goto V_54;
case V_58 :
V_5 ++ ;
case V_71 :
F_3 ( V_2 , V_4 , V_5 , V_72 ) ;
break;
default:
F_17 ( 1 ) ;
}
if ( V_47 > 0 ) {
V_47 -- ;
V_4 = V_49 [ V_47 ] . V_4 ;
V_45 = V_49 [ V_47 ] . V_45 ;
V_5 = V_49 [ V_47 ] . V_5 ;
goto V_57;
}
F_3 ( V_2 , V_43 , - 1 , V_73 ) ;
F_18 () ;
V_52 = F_19 ( F_20 ( F_21 ( V_43 ) -> V_52 ) ) ;
F_22 ( & V_52 -> V_74 ) ;
V_52 -> V_75 ++ ;
V_52 -> V_76 += V_2 -> V_10 -> V_25 ;
F_23 ( & V_52 -> V_74 ) ;
F_24 () ;
return F_21 ( V_43 ) -> V_77 ;
}
int T_2 F_25 ( void )
{
int V_78 ;
V_78 = F_26 () ;
if ( V_78 < 0 )
goto V_79;
V_78 = F_27 () ;
if ( V_78 < 0 )
goto V_80;
V_78 = F_28 () ;
if ( V_78 < 0 )
goto V_81;
V_78 = F_29 () ;
if ( V_78 < 0 )
goto V_82;
V_78 = F_30 () ;
if ( V_78 < 0 )
goto V_83;
V_78 = F_31 () ;
if ( V_78 < 0 )
goto V_84;
V_78 = F_32 () ;
if ( V_78 < 0 )
goto V_85;
return 0 ;
V_85:
F_33 () ;
V_84:
F_34 () ;
V_83:
F_35 () ;
V_82:
F_36 () ;
V_81:
F_37 () ;
V_80:
F_38 () ;
V_79:
return V_78 ;
}
void F_39 ( void )
{
F_40 () ;
F_33 () ;
F_34 () ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
}
