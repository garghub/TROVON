static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
char * V_5 , * V_6 , * V_7 ;
T_1 V_8 , V_9 ;
V_5 = V_3 ;
if ( * V_5 != '#' )
return - V_10 ;
V_5 ++ ;
if ( V_5 - V_3 >= V_4 - 1 )
return - V_10 ;
V_6 = strchr ( V_5 , '#' ) ;
if ( V_6 == NULL || V_6 == V_5 )
return - V_10 ;
* V_6 = '\0' ;
V_8 = F_2 ( V_5 , & V_7 , 0 ) ;
if ( V_7 != V_6 )
return - V_10 ;
V_5 = ++ V_6 ;
if ( V_5 - V_3 >= V_4 - 1 )
return - V_10 ;
V_6 = strchr ( V_5 , '#' ) ;
if ( V_6 == NULL || V_6 == V_5 )
return - V_10 ;
* V_6 = '\0' ;
V_9 = F_2 ( V_5 , & V_7 , 0 ) ;
if ( V_7 != V_6 )
return - V_10 ;
F_3 ( & V_2 -> V_11 , V_9 ) ;
F_4 ( & V_2 -> V_11 , V_8 ) ;
V_5 = ++ V_6 ;
if ( V_5 - V_3 >= V_4 - 1 )
return - V_10 ;
V_2 -> V_12 = F_5 ( V_5 , & V_7 , 16 ) ;
if ( * V_7 != '\0' )
return - V_10 ;
return 0 ;
}
static int F_6 ( const struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , void * V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_19 ;
static int V_22 , V_23 , V_24 , V_25 ;
static char * V_26 ;
char * V_7 ;
int V_27 , V_28 = 0 ;
if ( V_21 && V_21 -> V_29 > 0 ) {
V_22 = 0 ;
V_23 = V_21 -> V_30 +
F_7 ( V_21 -> V_29 ) +
F_7 ( V_21 -> V_31 ) +
F_7 ( V_21 -> V_32 ) ;
V_24 = F_8 ( V_21 -> V_33 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
return - V_10 ;
V_25 = F_8 ( V_21 -> V_34 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
return - V_10 ;
V_21 -> V_29 = 0 ;
V_26 = V_21 -> V_35 ;
}
V_27 = V_18 -> V_36 ;
if ( V_27 < V_24 )
return 0 ;
if ( V_25 > 0 && V_27 > V_25 )
return - V_37 ;
if ( V_16 -> V_38 -> V_39 & V_40 ) {
struct V_41 * V_42 = (struct V_41 * ) V_18 ;
struct V_15 * V_43 ;
if ( V_18 -> V_44 != V_45 ) {
V_22 = snprintf ( V_26 , V_23 , L_1
L_2 ,
V_27 , V_18 -> V_44 ,
V_18 -> V_46 ) ;
}
if ( V_16 -> V_47 == NULL )
return - V_48 ;
V_28 = F_9 ( V_14 , V_16 , & V_43 , & V_42 -> V_49 ) ;
if ( V_28 ) {
F_10 ( V_50 , L_3 V_51 L_4 ,
F_11 ( & V_42 -> V_49 . V_11 ) ,
V_42 -> V_49 . V_12 ) ;
return V_28 ;
}
V_28 = F_12 ( V_14 , V_43 , F_6 , NULL , NULL ) ;
F_13 ( V_43 ) ;
} else {
bool V_52 ;
switch ( V_18 -> V_44 ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
V_52 = true ;
break;
default:
V_52 = false ;
}
V_22 = snprintf ( V_26 , V_23 , L_1
L_5 ,
V_27 , V_18 -> V_44 , V_18 -> V_46 ,
V_52 ? L_6 : L_7 ) ;
V_26 += V_22 ;
V_23 -= V_22 ;
if ( V_23 <= 0 ) {
F_14 ( L_8 ,
V_16 -> V_47 -> V_60 -> V_61 ) ;
return - V_37 ;
}
}
return V_28 ;
}
static int F_15 ( const struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , void * V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_19 ;
static int V_22 , V_23 , V_24 , V_25 ;
static char * V_26 ;
char * V_7 ;
int V_27 ;
if ( V_21 != NULL && V_21 -> V_29 > 0 ) {
V_22 = 0 ;
V_23 = V_21 -> V_30 +
F_7 ( V_21 -> V_29 ) +
F_7 ( V_21 -> V_31 ) +
F_7 ( V_21 -> V_32 ) ;
V_24 = F_8 ( V_21 -> V_33 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
return - V_10 ;
V_25 = F_8 ( V_21 -> V_34 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
return - V_10 ;
V_26 = V_21 -> V_35 ;
V_21 -> V_29 = 0 ;
}
V_27 = V_18 -> V_36 ;
if ( V_27 < V_24 )
return 0 ;
if ( V_25 > 0 && V_27 > V_25 )
return - V_37 ;
if ( V_16 -> V_38 -> V_39 & V_40 ) {
struct V_41 * V_42 = (struct V_41 * ) V_18 ;
if ( V_18 -> V_44 != V_45 ) {
F_14 ( L_9 ) ;
return - V_10 ;
}
V_22 = snprintf ( V_26 , V_23 ,
L_10 V_51 L_4 ,
V_27 , F_11 ( & V_42 -> V_49 . V_11 ) ,
V_42 -> V_49 . V_12 ) ;
} else if ( V_18 -> V_44 == V_57 ) {
int V_28 ;
V_28 = F_16 ( V_18 , V_26 , V_23 ) ;
if ( V_28 < 0 )
return V_28 ;
V_22 = V_28 ;
} else {
V_22 = snprintf ( V_26 , V_23 ,
L_11 ,
V_27 , V_18 -> V_44 , V_18 -> V_46 ) ;
}
V_26 += V_22 ;
V_23 -= V_22 ;
if ( V_23 <= 0 ) {
F_14 ( L_12 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_17 ( const struct V_13 * V_14 , struct V_15 * V_62 ,
struct V_1 * V_2 )
{
struct V_15 * log ;
int V_28 ;
V_28 = F_9 ( V_14 , V_62 , & log , V_2 ) ;
if ( V_28 ) {
F_10 ( V_50 , L_3 V_51 L_4 ,
F_11 ( & V_2 -> V_11 ) , V_2 -> V_12 ) ;
return - V_63 ;
}
V_28 = F_18 ( V_14 , log ) ;
if ( V_28 ) {
F_10 ( V_50 , L_13 ) ;
GOTO ( V_26 , V_28 ) ;
}
F_19 ( V_14 , V_62 , log , log -> V_64 . V_65 . V_66 . V_67 ) ;
V_26:
F_13 ( log ) ;
return V_28 ;
}
static int F_20 ( const struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , void * V_19 )
{
struct V_41 * V_42 = (struct V_41 * ) V_18 ;
int V_28 ;
if ( V_18 -> V_44 != V_45 )
return - V_10 ;
V_28 = F_17 ( V_14 , V_16 , & V_42 -> V_49 ) ;
return V_28 ;
}
int F_21 ( const struct V_13 * V_14 , struct V_68 * V_69 , int V_70 ,
struct V_20 * V_19 )
{
struct V_1 V_2 ;
int V_28 = 0 ;
struct V_15 * V_16 = NULL ;
if ( * V_19 -> V_71 == '#' ) {
V_28 = F_1 ( & V_2 , V_19 -> V_71 , V_19 -> V_29 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_22 ( V_14 , V_69 , & V_16 , & V_2 , NULL ,
V_72 ) ;
if ( V_28 )
return V_28 ;
} else if ( * V_19 -> V_71 == '$' ) {
char * V_73 = V_19 -> V_71 + 1 ;
V_28 = F_22 ( V_14 , V_69 , & V_16 , NULL , V_73 ,
V_72 ) ;
if ( V_28 )
return V_28 ;
} else {
return - V_10 ;
}
V_28 = F_23 ( V_14 , V_16 , 0 , NULL ) ;
if ( V_28 )
GOTO ( V_74 , V_28 = - V_63 ) ;
switch ( V_70 ) {
case V_75 : {
int V_22 ;
int V_23 = V_19 -> V_31 +
F_7 ( V_19 -> V_29 ) ;
char * V_26 = V_19 -> V_35 ;
V_22 = snprintf ( V_26 , V_23 ,
L_14 V_51 L_4
L_15
L_16
L_17 ,
F_11 ( & V_16 -> V_76 . V_11 ) ,
V_16 -> V_76 . V_12 ,
V_16 -> V_38 -> V_39 ,
V_16 -> V_38 -> V_39 &
V_40 ? L_18 : L_19 ,
V_16 -> V_38 -> V_77 ,
V_16 -> V_78 ) ;
V_26 += V_22 ;
V_23 -= V_22 ;
if ( V_23 <= 0 ) {
F_14 ( L_20 ,
V_69 -> V_60 -> V_61 ) ;
V_28 = - V_79 ;
}
break;
}
case V_80 :
F_24 ( V_19 -> V_29 > 0 ) ;
V_28 = F_12 ( V_14 , V_16 , F_6 , V_19 , NULL ) ;
if ( V_28 == - V_37 )
V_28 = 0 ;
else if ( V_28 )
GOTO ( V_74 , V_28 ) ;
break;
case V_81 :
F_24 ( V_19 -> V_29 > 0 ) ;
V_28 = F_12 ( V_14 , V_16 , F_15 , V_19 , NULL ) ;
if ( V_28 == - V_37 )
V_28 = 0 ;
else if ( V_28 )
GOTO ( V_74 , V_28 ) ;
break;
case V_82 : {
struct V_83 V_84 ;
struct V_1 V_85 ;
char * V_7 ;
V_84 . V_67 = F_5 ( V_19 -> V_34 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
GOTO ( V_74 , V_28 = - V_10 ) ;
if ( V_16 -> V_38 -> V_39 & V_86 ) {
V_28 = F_25 ( NULL , V_16 , V_84 . V_67 ) ;
GOTO ( V_74 , V_28 ) ;
} else if ( ! ( V_16 -> V_38 -> V_39 & V_40 ) ) {
GOTO ( V_74 , V_28 = - V_10 ) ;
}
if ( V_19 -> V_33 == NULL )
GOTO ( V_74 , V_28 = - V_87 ) ;
V_28 = F_1 ( & V_85 , V_19 -> V_33 , V_19 -> V_31 ) ;
if ( V_28 )
GOTO ( V_74 , V_28 ) ;
V_84 . V_88 = V_85 ;
V_28 = F_26 ( V_14 , V_16 , 1 , & V_84 ) ;
if ( V_28 )
GOTO ( V_74 , V_28 ) ;
break;
}
case V_89 : {
struct V_1 V_85 ;
if ( V_16 -> V_38 -> V_39 & V_86 ) {
V_28 = F_18 ( V_14 , V_16 ) ;
GOTO ( V_74 , V_28 ) ;
} else if ( ! ( V_16 -> V_38 -> V_39 & V_40 ) ) {
GOTO ( V_74 , V_28 = - V_10 ) ;
}
if ( V_19 -> V_31 > 0 ) {
V_28 = F_1 ( & V_85 , V_19 -> V_33 ,
V_19 -> V_31 ) ;
if ( V_28 )
GOTO ( V_74 , V_28 ) ;
V_28 = F_17 ( V_14 , V_16 , & V_85 ) ;
} else {
V_28 = F_12 ( V_14 , V_16 , F_20 , NULL ,
NULL ) ;
if ( V_28 )
GOTO ( V_74 , V_28 ) ;
}
break;
}
default:
F_14 ( L_21 ,
V_69 -> V_60 -> V_61 , V_70 ) ;
GOTO ( V_74 , V_28 = - V_87 ) ;
}
V_74:
if ( V_16 -> V_38 &&
V_16 -> V_38 -> V_39 & V_40 )
F_27 ( V_14 , V_16 ) ;
else
F_28 ( V_14 , V_16 ) ;
return V_28 ;
}
