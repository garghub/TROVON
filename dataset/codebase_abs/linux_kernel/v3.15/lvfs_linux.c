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
V_7 = F_4 () ;
if ( V_7 ) {
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
V_7 = F_4 () ;
if ( V_7 ) {
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
V_7 = F_4 () ;
if ( V_7 ) {
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
V_7 = F_4 () ;
if ( V_7 ) {
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
F_27 ( L_3 ) ;
F_32 ( V_43 , L_4 ,
( int ) strlen ( V_38 ) , V_38 , ( int ) strlen ( V_39 ) , V_39 ) ;
V_40 = F_33 ( V_38 , V_35 , strlen ( V_38 ) ) ;
if ( F_34 ( V_40 ) )
return F_35 ( V_40 ) ;
if ( ! V_40 -> V_44 )
GOTO ( V_45 , V_42 = - V_46 ) ;
V_41 = F_33 ( V_39 , V_35 , strlen ( V_39 ) ) ;
if ( F_34 ( V_41 ) )
GOTO ( V_45 , V_42 = F_35 ( V_41 ) ) ;
V_42 = F_36 ( V_35 -> V_44 , V_40 , V_37 ,
V_35 -> V_44 , V_41 , V_37 ) ;
F_29 ( V_41 ) ;
V_45:
F_29 ( V_40 ) ;
return V_42 ;
}
struct V_47 * F_37 ( struct V_1 * V_48 , struct V_49 * V_50 ,
int V_51 )
{
struct V_52 V_52 = {
. V_34 = V_50 ,
. V_37 = V_48 -> V_16 ,
} ;
return F_38 ( & V_52 , V_51 , F_3 () ) ;
}
T_1 F_39 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
enum V_57 V_51 ,
enum V_58 V_59 )
{
T_1 V_60 = 0 ;
if ( V_54 == NULL || V_56 == NULL )
return 0 ;
switch ( V_59 ) {
case V_61 :
V_60 = V_56 -> V_62 ;
break;
case V_63 :
V_60 = V_54 -> V_64 ;
if ( ( V_51 & V_65 ) != 0 )
V_60 += V_54 -> V_66 ;
break;
case V_67 :
V_60 = V_54 -> V_68 ;
break;
case V_69 :
V_60 = V_54 -> V_70 ;
break;
case V_71 :
V_60 = ( V_54 -> V_70 - V_54 -> V_68 ) / 2 ;
break;
case V_72 :
V_60 = V_54 -> V_73 ;
break;
case V_74 :
V_60 = V_54 -> V_75 ;
break;
default:
break;
}
return V_60 ;
}
