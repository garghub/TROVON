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
const struct V_7 * V_7 = F_13 ( & F_14 ( V_45 ) -> V_46 ) ;
const struct V_47 * V_48 ;
const struct V_20 * V_21 , * V_49 ;
struct V_22 V_23 ;
unsigned int V_50 = 0 ;
struct V_51 V_52 [ V_53 ] ;
struct V_54 * V_55 ;
int V_5 ;
unsigned int V_56 = F_15 ( V_7 ) ;
V_57:
V_5 = 0 ;
V_48 = F_16 ( & V_4 -> V_58 , struct V_47 , V_59 ) ;
V_60:
V_23 . V_30 . V_31 = V_61 ;
F_17 (rule, &chain->rules, list) {
if ( F_5 ( V_48 -> V_62 & ( 1 << V_56 ) ) )
continue;
V_5 ++ ;
F_18 (expr, last, rule) {
if ( V_21 -> V_12 == & V_63 )
F_6 ( V_21 , & V_23 ) ;
else if ( V_21 -> V_12 != & V_64 ||
! F_9 ( V_21 , & V_23 , V_2 ) )
V_21 -> V_12 -> V_65 ( V_21 , & V_23 , V_2 ) ;
if ( V_23 . V_30 . V_31 != V_61 )
break;
}
switch ( V_23 . V_30 . V_31 ) {
case V_32 :
V_23 . V_30 . V_31 = V_61 ;
continue;
case V_61 :
F_4 ( V_2 , V_4 , V_5 , V_66 ) ;
continue;
}
break;
}
switch ( V_23 . V_30 . V_31 & V_67 ) {
case V_68 :
case V_69 :
case V_70 :
F_4 ( V_2 , V_4 , V_5 , V_66 ) ;
return V_23 . V_30 . V_31 ;
}
switch ( V_23 . V_30 . V_31 ) {
case V_71 :
F_19 ( V_50 >= V_53 ) ;
V_52 [ V_50 ] . V_4 = V_4 ;
V_52 [ V_50 ] . V_48 = V_48 ;
V_52 [ V_50 ] . V_5 = V_5 ;
V_50 ++ ;
case V_72 :
F_4 ( V_2 , V_4 , V_5 , V_66 ) ;
V_4 = V_23 . V_30 . V_4 ;
goto V_57;
case V_61 :
V_5 ++ ;
case V_73 :
F_4 ( V_2 , V_4 , V_5 , V_74 ) ;
break;
default:
F_20 ( 1 ) ;
}
if ( V_50 > 0 ) {
V_50 -- ;
V_4 = V_52 [ V_50 ] . V_4 ;
V_48 = V_52 [ V_50 ] . V_48 ;
V_5 = V_52 [ V_50 ] . V_5 ;
goto V_60;
}
F_4 ( V_2 , V_45 , - 1 , V_75 ) ;
F_21 () ;
V_55 = F_22 ( F_23 ( F_14 ( V_45 ) -> V_55 ) ) ;
F_24 ( & V_55 -> V_76 ) ;
V_55 -> V_77 ++ ;
V_55 -> V_78 += V_2 -> V_14 -> V_27 ;
F_25 ( & V_55 -> V_76 ) ;
F_26 () ;
return F_14 ( V_45 ) -> V_79 ;
}
int T_2 F_27 ( void )
{
int V_80 ;
V_80 = F_28 () ;
if ( V_80 < 0 )
goto V_81;
V_80 = F_29 () ;
if ( V_80 < 0 )
goto V_82;
V_80 = F_30 () ;
if ( V_80 < 0 )
goto V_83;
V_80 = F_31 () ;
if ( V_80 < 0 )
goto V_84;
V_80 = F_32 () ;
if ( V_80 < 0 )
goto V_85;
V_80 = F_33 () ;
if ( V_80 < 0 )
goto V_86;
V_80 = F_34 () ;
if ( V_80 < 0 )
goto V_87;
return 0 ;
V_87:
F_35 () ;
V_86:
F_36 () ;
V_85:
F_37 () ;
V_84:
F_38 () ;
V_83:
F_39 () ;
V_82:
F_40 () ;
V_81:
return V_80 ;
}
void F_41 ( void )
{
F_42 () ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
F_39 () ;
F_40 () ;
}
