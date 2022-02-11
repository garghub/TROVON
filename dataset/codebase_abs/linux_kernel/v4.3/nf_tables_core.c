static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , enum V_6 type )
{
struct V_7 * V_7 = F_2 ( V_2 -> V_8 ? V_2 -> V_8 : V_2 -> V_9 ) ;
F_3 ( V_7 , V_2 -> V_10 . V_11 , V_2 -> V_12 -> V_13 , V_2 -> V_14 , V_2 -> V_8 ,
V_2 -> V_9 , & V_15 , L_1 ,
V_4 -> V_16 -> V_17 , V_4 -> V_17 , V_18 [ type ] ,
V_5 ) ;
}
static inline void F_4 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , enum V_6 type )
{
if ( F_5 ( V_2 -> V_14 -> V_19 ) )
F_1 ( V_2 , V_4 , V_5 , type ) ;
}
static void F_6 ( const struct V_20 * V_21 ,
struct V_22 * V_23 )
{
const struct V_24 * V_25 = F_7 ( V_21 ) ;
T_1 V_26 = F_8 ( V_25 -> V_27 ) ;
if ( ( V_23 -> V_28 [ V_25 -> V_29 ] & V_26 ) == V_25 -> V_28 )
return;
V_23 -> V_30 . V_31 = V_32 ;
}
static bool F_9 ( const struct V_20 * V_21 ,
struct V_22 * V_23 ,
const struct V_1 * V_2 )
{
const struct V_33 * V_25 = F_7 ( V_21 ) ;
const struct V_34 * V_14 = V_2 -> V_14 ;
T_1 * V_35 = & V_23 -> V_28 [ V_25 -> V_36 ] ;
unsigned char * V_37 ;
if ( V_25 -> V_38 == V_39 )
V_37 = F_10 ( V_14 ) ;
else
V_37 = F_10 ( V_14 ) + V_2 -> V_10 . V_40 ;
V_37 += V_25 -> V_41 ;
if ( F_5 ( V_37 + V_25 -> V_27 >= F_11 ( V_14 ) ) )
return false ;
* V_35 = 0 ;
if ( V_25 -> V_27 == 2 )
* ( V_42 * ) V_35 = * ( V_42 * ) V_37 ;
else if ( V_25 -> V_27 == 4 )
* ( T_1 * ) V_35 = * ( T_1 * ) V_37 ;
else
* ( V_43 * ) V_35 = * ( V_43 * ) V_37 ;
return true ;
}
unsigned int
F_12 ( struct V_1 * V_2 , const struct V_44 * V_12 )
{
const struct V_3 * V_4 = V_12 -> V_25 , * V_45 = V_4 ;
const struct V_7 * V_7 = F_2 ( V_2 -> V_8 ? V_2 -> V_8 : V_2 -> V_9 ) ;
const struct V_46 * V_47 ;
const struct V_20 * V_21 , * V_48 ;
struct V_22 V_23 ;
unsigned int V_49 = 0 ;
struct V_50 V_51 [ V_52 ] ;
struct V_53 * V_54 ;
int V_5 ;
unsigned int V_55 = F_13 ( V_7 ) ;
V_56:
V_5 = 0 ;
V_47 = F_14 ( & V_4 -> V_57 , struct V_46 , V_58 ) ;
V_59:
V_23 . V_30 . V_31 = V_60 ;
F_15 (rule, &chain->rules, list) {
if ( F_5 ( V_47 -> V_61 & ( 1 << V_55 ) ) )
continue;
V_5 ++ ;
F_16 (expr, last, rule) {
if ( V_21 -> V_12 == & V_62 )
F_6 ( V_21 , & V_23 ) ;
else if ( V_21 -> V_12 != & V_63 ||
! F_9 ( V_21 , & V_23 , V_2 ) )
V_21 -> V_12 -> V_64 ( V_21 , & V_23 , V_2 ) ;
if ( V_23 . V_30 . V_31 != V_60 )
break;
}
switch ( V_23 . V_30 . V_31 ) {
case V_32 :
V_23 . V_30 . V_31 = V_60 ;
continue;
case V_60 :
F_4 ( V_2 , V_4 , V_5 , V_65 ) ;
continue;
}
break;
}
switch ( V_23 . V_30 . V_31 & V_66 ) {
case V_67 :
case V_68 :
case V_69 :
F_4 ( V_2 , V_4 , V_5 , V_65 ) ;
return V_23 . V_30 . V_31 ;
}
switch ( V_23 . V_30 . V_31 ) {
case V_70 :
F_17 ( V_49 >= V_52 ) ;
V_51 [ V_49 ] . V_4 = V_4 ;
V_51 [ V_49 ] . V_47 = V_47 ;
V_51 [ V_49 ] . V_5 = V_5 ;
V_49 ++ ;
case V_71 :
F_4 ( V_2 , V_4 , V_5 , V_65 ) ;
V_4 = V_23 . V_30 . V_4 ;
goto V_56;
case V_60 :
V_5 ++ ;
case V_72 :
F_4 ( V_2 , V_4 , V_5 , V_73 ) ;
break;
default:
F_18 ( 1 ) ;
}
if ( V_49 > 0 ) {
V_49 -- ;
V_4 = V_51 [ V_49 ] . V_4 ;
V_47 = V_51 [ V_49 ] . V_47 ;
V_5 = V_51 [ V_49 ] . V_5 ;
goto V_59;
}
F_4 ( V_2 , V_45 , - 1 , V_74 ) ;
F_19 () ;
V_54 = F_20 ( F_21 ( F_22 ( V_45 ) -> V_54 ) ) ;
F_23 ( & V_54 -> V_75 ) ;
V_54 -> V_76 ++ ;
V_54 -> V_77 += V_2 -> V_14 -> V_27 ;
F_24 ( & V_54 -> V_75 ) ;
F_25 () ;
return F_22 ( V_45 ) -> V_78 ;
}
int T_2 F_26 ( void )
{
int V_79 ;
V_79 = F_27 () ;
if ( V_79 < 0 )
goto V_80;
V_79 = F_28 () ;
if ( V_79 < 0 )
goto V_81;
V_79 = F_29 () ;
if ( V_79 < 0 )
goto V_82;
V_79 = F_30 () ;
if ( V_79 < 0 )
goto V_83;
V_79 = F_31 () ;
if ( V_79 < 0 )
goto V_84;
V_79 = F_32 () ;
if ( V_79 < 0 )
goto V_85;
V_79 = F_33 () ;
if ( V_79 < 0 )
goto V_86;
return 0 ;
V_86:
F_34 () ;
V_85:
F_35 () ;
V_84:
F_36 () ;
V_83:
F_37 () ;
V_82:
F_38 () ;
V_81:
F_39 () ;
V_80:
return V_79 ;
}
void F_40 ( void )
{
F_41 () ;
F_34 () ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
F_39 () ;
}
