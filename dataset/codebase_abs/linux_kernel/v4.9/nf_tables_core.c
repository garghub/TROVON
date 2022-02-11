static T_1 void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , enum V_6 type )
{
const struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_2 -> V_9 || ! V_8 -> V_10 -> V_11 )
return;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
F_2 ( V_2 ) ;
F_3 ( V_8 -> V_12 , V_8 -> V_13 , V_8 -> V_14 , V_8 -> V_10 , V_8 -> V_15 ,
V_8 -> V_16 , & V_17 , L_1 ,
V_4 -> V_18 -> V_19 , V_4 -> V_19 , V_20 [ type ] ,
V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_21 * V_22 ,
int V_5 ,
enum V_6 type )
{
if ( F_5 ( & V_23 ) ) {
V_2 -> V_22 = V_22 ;
F_1 ( V_2 , V_4 , V_5 , type ) ;
}
}
static void F_6 ( const struct V_24 * V_25 ,
struct V_26 * V_27 )
{
const struct V_28 * V_29 = F_7 ( V_25 ) ;
T_2 V_30 = F_8 ( V_29 -> V_31 ) ;
if ( ( V_27 -> V_32 [ V_29 -> V_33 ] & V_30 ) == V_29 -> V_32 )
return;
V_27 -> V_34 . V_35 = V_36 ;
}
static bool F_9 ( const struct V_24 * V_25 ,
struct V_26 * V_27 ,
const struct V_7 * V_8 )
{
const struct V_37 * V_29 = F_7 ( V_25 ) ;
const struct V_38 * V_10 = V_8 -> V_10 ;
T_2 * V_39 = & V_27 -> V_32 [ V_29 -> V_40 ] ;
unsigned char * V_41 ;
if ( V_29 -> V_42 == V_43 )
V_41 = F_10 ( V_10 ) ;
else {
if ( ! V_8 -> V_44 )
return false ;
V_41 = F_10 ( V_10 ) + V_8 -> V_45 . V_46 ;
}
V_41 += V_29 -> V_47 ;
if ( F_11 ( V_41 + V_29 -> V_31 > F_12 ( V_10 ) ) )
return false ;
* V_39 = 0 ;
if ( V_29 -> V_31 == 2 )
* ( V_48 * ) V_39 = * ( V_48 * ) V_41 ;
else if ( V_29 -> V_31 == 4 )
* ( T_2 * ) V_39 = * ( T_2 * ) V_41 ;
else
* ( V_49 * ) V_39 = * ( V_49 * ) V_41 ;
return true ;
}
unsigned int
F_13 ( struct V_7 * V_8 , void * V_29 )
{
const struct V_3 * V_4 = V_29 , * V_50 = V_4 ;
const struct V_12 * V_12 = V_8 -> V_12 ;
const struct V_21 * V_22 ;
const struct V_24 * V_25 , * V_51 ;
struct V_26 V_27 ;
unsigned int V_52 = 0 ;
struct V_53 V_54 [ V_55 ] ;
struct V_56 * V_57 ;
int V_5 ;
unsigned int V_58 = F_14 ( V_12 ) ;
struct V_1 V_2 ;
V_2 . V_9 = false ;
if ( F_5 ( & V_23 ) )
F_15 ( & V_2 , V_8 , & V_27 . V_34 , V_50 ) ;
V_59:
V_5 = 0 ;
V_22 = F_16 ( & V_4 -> V_60 , struct V_21 , V_61 ) ;
V_62:
V_27 . V_34 . V_35 = V_63 ;
F_17 (rule, &chain->rules, list) {
if ( F_11 ( V_22 -> V_64 & V_58 ) )
continue;
V_5 ++ ;
F_18 (expr, last, rule) {
if ( V_25 -> V_65 == & V_66 )
F_6 ( V_25 , & V_27 ) ;
else if ( V_25 -> V_65 != & V_67 ||
! F_9 ( V_25 , & V_27 , V_8 ) )
V_25 -> V_65 -> V_68 ( V_25 , & V_27 , V_8 ) ;
if ( V_27 . V_34 . V_35 != V_63 )
break;
}
switch ( V_27 . V_34 . V_35 ) {
case V_36 :
V_27 . V_34 . V_35 = V_63 ;
continue;
case V_63 :
F_4 ( & V_2 , V_4 , V_22 ,
V_5 , V_69 ) ;
continue;
}
break;
}
switch ( V_27 . V_34 . V_35 & V_70 ) {
case V_71 :
case V_72 :
case V_73 :
F_4 ( & V_2 , V_4 , V_22 ,
V_5 , V_69 ) ;
return V_27 . V_34 . V_35 ;
}
switch ( V_27 . V_34 . V_35 ) {
case V_74 :
F_19 ( V_52 >= V_55 ) ;
V_54 [ V_52 ] . V_4 = V_4 ;
V_54 [ V_52 ] . V_22 = V_22 ;
V_54 [ V_52 ] . V_5 = V_5 ;
V_52 ++ ;
case V_75 :
F_4 ( & V_2 , V_4 , V_22 ,
V_5 , V_69 ) ;
V_4 = V_27 . V_34 . V_4 ;
goto V_59;
case V_63 :
V_5 ++ ;
case V_76 :
F_4 ( & V_2 , V_4 , V_22 ,
V_5 , V_77 ) ;
break;
default:
F_20 ( 1 ) ;
}
if ( V_52 > 0 ) {
V_52 -- ;
V_4 = V_54 [ V_52 ] . V_4 ;
V_22 = V_54 [ V_52 ] . V_22 ;
V_5 = V_54 [ V_52 ] . V_5 ;
goto V_62;
}
F_4 ( & V_2 , V_50 , NULL , - 1 ,
V_78 ) ;
F_21 () ;
V_57 = F_22 ( F_23 ( F_24 ( V_50 ) -> V_57 ) ) ;
F_25 ( & V_57 -> V_79 ) ;
V_57 -> V_80 ++ ;
V_57 -> V_81 += V_8 -> V_10 -> V_31 ;
F_26 ( & V_57 -> V_79 ) ;
F_27 () ;
return F_24 ( V_50 ) -> V_82 ;
}
int T_3 F_28 ( void )
{
int V_83 ;
V_83 = F_29 () ;
if ( V_83 < 0 )
goto V_84;
V_83 = F_30 () ;
if ( V_83 < 0 )
goto V_85;
V_83 = F_31 () ;
if ( V_83 < 0 )
goto V_86;
V_83 = F_32 () ;
if ( V_83 < 0 )
goto V_87;
V_83 = F_33 () ;
if ( V_83 < 0 )
goto V_88;
V_83 = F_34 () ;
if ( V_83 < 0 )
goto V_89;
V_83 = F_35 () ;
if ( V_83 < 0 )
goto V_90;
V_83 = F_36 () ;
if ( V_83 < 0 )
goto V_91;
return 0 ;
V_91:
F_37 () ;
V_90:
F_38 () ;
V_89:
F_39 () ;
V_88:
F_40 () ;
V_87:
F_41 () ;
V_86:
F_42 () ;
V_85:
F_43 () ;
V_84:
return V_83 ;
}
void F_44 ( void )
{
F_37 () ;
F_38 () ;
F_39 () ;
F_40 () ;
F_41 () ;
F_42 () ;
F_43 () ;
}
