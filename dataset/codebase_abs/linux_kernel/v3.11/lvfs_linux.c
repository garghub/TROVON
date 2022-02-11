static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_4 ) {
V_2 -> V_5 = V_6 ;
V_6 = 0 ;
} else {
struct V_7 * V_7 ;
F_2 ( V_8 ) ;
V_2 -> V_3 = F_3 () -> V_3 ;
if ( ( V_7 = F_4 () ) ) {
V_7 -> V_3 = V_4 ;
F_5 ( V_7 ) ;
}
F_6 ( V_8 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_4 ) {
V_6 = V_2 -> V_5 ;
} else {
struct V_7 * V_7 ;
F_2 ( V_8 ) ;
if ( ( V_7 = F_4 () ) ) {
V_7 -> V_3 = V_2 -> V_3 ;
F_5 ( V_7 ) ;
}
F_6 ( V_8 ) ;
}
}
void F_8 ( struct V_1 * V_2 , struct V_1 * V_9 ,
struct V_10 * V_11 )
{
if ( V_9 -> V_12 != NULL )
return;
F_9 ( V_9 -> V_13 ) ;
F_10 ( V_2 ) ;
V_2 -> V_14 = F_11 () ;
F_12 ( F_13 ( F_14 ( V_8 -> V_14 ) ) ) ;
F_12 ( F_13 ( V_9 -> V_15 ) ) ;
V_2 -> V_15 = F_15 ( F_14 ( V_8 -> V_14 ) ) ;
V_2 -> V_16 = F_16 ( F_17 ( V_8 -> V_14 ) ) ;
V_2 -> V_17 . V_18 = F_18 () ;
V_2 -> V_5 = F_3 () -> V_3 -> V_5 ;
F_12 ( V_2 -> V_15 ) ;
F_12 ( V_2 -> V_16 ) ;
F_12 ( V_9 -> V_15 ) ;
F_12 ( V_9 -> V_16 ) ;
if ( V_11 ) {
struct V_7 * V_7 ;
V_2 -> V_17 . V_19 = F_19 () ;
V_2 -> V_17 . V_20 = F_20 () ;
V_2 -> V_17 . V_21 = F_21 () ;
V_2 -> V_17 . V_22 = F_22 () ;
V_2 -> V_17 . V_23 = F_23 () ;
if ( ( V_7 = F_4 () ) ) {
V_7 -> V_24 = V_11 -> V_19 ;
V_7 -> V_25 = V_11 -> V_20 ;
V_7 -> V_26 = V_11 -> V_21 ;
V_7 -> V_27 = V_11 -> V_22 ;
V_7 -> V_28 = V_11 -> V_23 ;
F_5 ( V_7 ) ;
}
F_1 ( V_2 ,
V_11 -> V_29 ? :
V_11 -> V_30 ? V_11 -> V_30 -> V_31 :
NULL ) ;
}
V_8 -> V_14 -> V_32 = 0 ;
F_24 ( V_9 -> V_14 ) ;
F_25 ( V_8 -> V_14 , V_9 -> V_16 , V_9 -> V_15 ) ;
}
void F_26 ( struct V_1 * V_33 , struct V_1 * V_9 ,
struct V_10 * V_11 )
{
if ( V_9 -> V_12 != NULL )
return;
F_9 ( V_33 -> V_13 ) ;
F_27 ( L_1 ) ;
F_28 ( F_14 ( V_8 -> V_14 ) == V_9 -> V_15 , L_2 ,
F_14 ( V_8 -> V_14 ) , V_9 -> V_15 ) ;
F_28 ( F_17 ( V_8 -> V_14 ) == V_9 -> V_16 , L_2 ,
F_17 ( V_8 -> V_14 ) , V_9 -> V_16 ) ;
F_24 ( V_33 -> V_14 ) ;
F_25 ( V_8 -> V_14 , V_33 -> V_16 , V_33 -> V_15 ) ;
F_29 ( V_33 -> V_15 ) ;
F_30 ( V_33 -> V_16 ) ;
V_8 -> V_14 -> V_32 = V_33 -> V_17 . V_18 ;
if ( V_11 ) {
struct V_7 * V_7 ;
if ( ( V_7 = F_4 () ) ) {
V_7 -> V_24 = V_33 -> V_17 . V_19 ;
V_7 -> V_25 = V_33 -> V_17 . V_20 ;
V_7 -> V_26 = V_33 -> V_17 . V_21 ;
V_7 -> V_27 = V_33 -> V_17 . V_22 ;
V_7 -> V_28 = V_33 -> V_17 . V_23 ;
F_5 ( V_7 ) ;
}
F_7 ( V_33 ,
V_11 -> V_29 ? :
V_11 -> V_30 ? V_11 -> V_30 -> V_31 :
NULL ) ;
}
}
int F_31 ( struct V_34 * V_35 , struct V_36 * V_37 ,
char * V_38 , char * V_39 )
{
struct V_34 * V_40 , * V_41 ;
int V_42 = 0 ;
V_43 ;
F_27 ( L_3 ) ;
F_32 ( V_44 , L_4 ,
( int ) strlen ( V_38 ) , V_38 , ( int ) strlen ( V_39 ) , V_39 ) ;
V_40 = F_33 ( V_38 , V_35 , strlen ( V_38 ) ) ;
if ( F_34 ( V_40 ) )
RETURN ( F_35 ( V_40 ) ) ;
if ( ! V_40 -> V_45 )
GOTO ( V_46 , V_42 = - V_47 ) ;
V_41 = F_33 ( V_39 , V_35 , strlen ( V_39 ) ) ;
if ( F_34 ( V_41 ) )
GOTO ( V_46 , V_42 = F_35 ( V_41 ) ) ;
V_42 = F_36 ( V_35 -> V_45 , V_40 , V_37 ,
V_35 -> V_45 , V_41 , V_37 ) ;
F_29 ( V_41 ) ;
V_46:
F_29 ( V_40 ) ;
RETURN ( V_42 ) ;
}
struct V_48 * F_37 ( struct V_1 * V_49 , struct V_50 * V_51 ,
int V_52 )
{
struct V_53 V_53 = {
. V_34 = V_51 ,
. V_37 = V_49 -> V_16 ,
} ;
return F_38 ( & V_53 , V_52 , F_3 () ) ;
}
T_1 F_39 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
enum V_58 V_52 ,
enum V_59 V_60 )
{
T_1 V_61 = 0 ;
if ( V_55 == NULL || V_57 == NULL )
RETURN ( 0 ) ;
switch ( V_60 ) {
case V_62 :
V_61 = V_57 -> V_63 ;
break;
case V_64 :
V_61 = V_55 -> V_65 ;
if ( ( V_52 & V_66 ) != 0 )
V_61 += V_55 -> V_67 ;
break;
case V_68 :
V_61 = V_55 -> V_69 ;
break;
case V_70 :
V_61 = V_55 -> V_71 ;
break;
case V_72 :
V_61 = ( V_55 -> V_71 - V_55 -> V_69 ) / 2 ;
break;
case V_73 :
V_61 = V_55 -> V_74 ;
break;
case V_75 :
V_61 = V_55 -> V_76 ;
break;
default:
break;
} ;
RETURN ( V_61 ) ;
}
