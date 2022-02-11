static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 = F_3 ( V_7 -> V_9 ) ;
if ( ( V_4 [ V_7 -> V_10 ] . V_4 [ 0 ] & V_8 ) == V_7 -> V_4 )
return;
V_4 [ V_11 ] . V_12 = V_13 ;
}
static bool F_4 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_14 * V_15 )
{
const struct V_16 * V_7 = F_2 ( V_2 ) ;
const struct V_17 * V_18 = V_15 -> V_18 ;
struct V_3 * V_19 = & V_4 [ V_7 -> V_20 ] ;
unsigned char * V_21 ;
if ( V_7 -> V_22 == V_23 )
V_21 = F_5 ( V_18 ) ;
else
V_21 = F_5 ( V_18 ) + V_15 -> V_24 . V_25 ;
V_21 += V_7 -> V_26 ;
if ( F_6 ( V_21 + V_7 -> V_9 >= F_7 ( V_18 ) ) )
return false ;
if ( V_7 -> V_9 == 2 )
* ( V_27 * ) V_19 -> V_4 = * ( V_27 * ) V_21 ;
else if ( V_7 -> V_9 == 4 )
* ( T_1 * ) V_19 -> V_4 = * ( T_1 * ) V_21 ;
else
* ( V_28 * ) V_19 -> V_4 = * ( V_28 * ) V_21 ;
return true ;
}
static void F_8 ( const struct V_14 * V_15 ,
const struct V_29 * V_30 ,
int V_31 , enum V_32 type )
{
struct V_33 * V_33 = F_9 ( V_15 -> V_34 ? V_15 -> V_34 : V_15 -> V_35 ) ;
F_10 ( V_33 , V_15 -> V_24 . V_36 , V_15 -> V_37 -> V_38 , V_15 -> V_18 , V_15 -> V_34 ,
V_15 -> V_35 , & V_39 , L_1 ,
V_30 -> V_40 -> V_41 , V_30 -> V_41 , V_42 [ type ] ,
V_31 ) ;
}
unsigned int
F_11 ( struct V_14 * V_15 , const struct V_43 * V_37 )
{
const struct V_29 * V_30 = V_37 -> V_7 , * V_44 = V_30 ;
const struct V_45 * V_46 ;
const struct V_1 * V_2 , * V_47 ;
struct V_3 V_4 [ V_5 + 1 ] ;
unsigned int V_48 = 0 ;
struct V_49 V_50 [ V_51 ] ;
struct V_52 T_2 * V_53 ;
int V_31 ;
unsigned int V_54 = F_12 ( V_30 -> V_33 -> V_55 . V_54 ) ;
V_56:
V_31 = 0 ;
V_46 = F_13 ( & V_30 -> V_57 , struct V_45 , V_58 ) ;
V_59:
V_4 [ V_11 ] . V_12 = V_60 ;
F_14 (rule, &chain->rules, list) {
if ( F_6 ( V_46 -> V_61 & ( 1 << V_54 ) ) )
continue;
V_31 ++ ;
F_15 (expr, last, rule) {
if ( V_2 -> V_37 == & V_62 )
F_1 ( V_2 , V_4 ) ;
else if ( V_2 -> V_37 != & V_63 ||
! F_4 ( V_2 , V_4 , V_15 ) )
V_2 -> V_37 -> V_64 ( V_2 , V_4 , V_15 ) ;
if ( V_4 [ V_11 ] . V_12 != V_60 )
break;
}
switch ( V_4 [ V_11 ] . V_12 ) {
case V_13 :
V_4 [ V_11 ] . V_12 = V_60 ;
continue;
case V_60 :
if ( F_6 ( V_15 -> V_18 -> V_65 ) )
F_8 ( V_15 , V_30 , V_31 , V_66 ) ;
continue;
}
break;
}
switch ( V_4 [ V_11 ] . V_12 & V_67 ) {
case V_68 :
case V_69 :
case V_70 :
if ( F_6 ( V_15 -> V_18 -> V_65 ) )
F_8 ( V_15 , V_30 , V_31 , V_66 ) ;
return V_4 [ V_11 ] . V_12 ;
}
switch ( V_4 [ V_11 ] . V_12 ) {
case V_71 :
if ( F_6 ( V_15 -> V_18 -> V_65 ) )
F_8 ( V_15 , V_30 , V_31 , V_66 ) ;
F_16 ( V_48 >= V_51 ) ;
V_50 [ V_48 ] . V_30 = V_30 ;
V_50 [ V_48 ] . V_46 = V_46 ;
V_50 [ V_48 ] . V_31 = V_31 ;
V_48 ++ ;
V_30 = V_4 [ V_11 ] . V_30 ;
goto V_56;
case V_72 :
if ( F_6 ( V_15 -> V_18 -> V_65 ) )
F_8 ( V_15 , V_30 , V_31 , V_66 ) ;
V_30 = V_4 [ V_11 ] . V_30 ;
goto V_56;
case V_73 :
if ( F_6 ( V_15 -> V_18 -> V_65 ) )
F_8 ( V_15 , V_30 , V_31 , V_74 ) ;
break;
case V_60 :
if ( F_6 ( V_15 -> V_18 -> V_65 && ! ( V_30 -> V_75 & V_76 ) ) )
F_8 ( V_15 , V_30 , ++ V_31 , V_74 ) ;
break;
default:
F_17 ( 1 ) ;
}
if ( V_48 > 0 ) {
V_48 -- ;
V_30 = V_50 [ V_48 ] . V_30 ;
V_46 = V_50 [ V_48 ] . V_46 ;
V_31 = V_50 [ V_48 ] . V_31 ;
goto V_59;
}
if ( F_6 ( V_15 -> V_18 -> V_65 ) )
F_8 ( V_15 , V_44 , - 1 , V_77 ) ;
F_18 () ;
V_53 = F_19 ( F_20 ( V_44 ) -> V_53 ) ;
F_21 ( V_53 -> V_78 ) ;
F_22 ( V_53 -> V_79 , V_15 -> V_18 -> V_9 ) ;
F_23 () ;
return F_20 ( V_44 ) -> V_80 ;
}
int T_3 F_24 ( void )
{
int V_81 ;
V_81 = F_25 () ;
if ( V_81 < 0 )
goto V_82;
V_81 = F_26 () ;
if ( V_81 < 0 )
goto V_83;
V_81 = F_27 () ;
if ( V_81 < 0 )
goto V_84;
V_81 = F_28 () ;
if ( V_81 < 0 )
goto V_85;
V_81 = F_29 () ;
if ( V_81 < 0 )
goto V_86;
V_81 = F_30 () ;
if ( V_81 < 0 )
goto V_87;
return 0 ;
V_87:
F_31 () ;
V_86:
F_32 () ;
V_85:
F_33 () ;
V_84:
F_34 () ;
V_83:
F_35 () ;
V_82:
return V_81 ;
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
