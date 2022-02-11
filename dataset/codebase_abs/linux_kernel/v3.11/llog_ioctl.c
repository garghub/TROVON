static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
char * V_5 , * V_6 , * V_7 ;
T_1 V_8 , V_9 ;
V_10 ;
V_5 = V_3 ;
if ( * V_5 != '#' )
RETURN ( - V_11 ) ;
V_5 ++ ;
if ( V_5 - V_3 >= V_4 - 1 )
RETURN ( - V_11 ) ;
V_6 = strchr ( V_5 , '#' ) ;
if ( V_6 == NULL || V_6 == V_5 )
RETURN ( - V_11 ) ;
* V_6 = '\0' ;
V_8 = F_2 ( V_5 , & V_7 , 0 ) ;
if ( V_7 != V_6 )
RETURN ( - V_11 ) ;
V_5 = ++ V_6 ;
if ( V_5 - V_3 >= V_4 - 1 )
RETURN ( - V_11 ) ;
V_6 = strchr ( V_5 , '#' ) ;
if ( V_6 == NULL || V_6 == V_5 )
RETURN ( - V_11 ) ;
* V_6 = '\0' ;
V_9 = F_2 ( V_5 , & V_7 , 0 ) ;
if ( V_7 != V_6 )
RETURN ( - V_11 ) ;
F_3 ( & V_2 -> V_12 , V_9 ) ;
F_4 ( & V_2 -> V_12 , V_8 ) ;
V_5 = ++ V_6 ;
if ( V_5 - V_3 >= V_4 - 1 )
RETURN ( - V_11 ) ;
V_2 -> V_13 = F_5 ( V_5 , & V_7 , 16 ) ;
if ( * V_7 != '\0' )
RETURN ( - V_11 ) ;
RETURN ( 0 ) ;
}
static int F_6 ( const struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 , void * V_20 )
{
struct V_21 * V_22 = (struct V_21 * ) V_20 ;
static int V_23 , V_24 , V_25 , V_26 ;
static char * V_27 ;
char * V_7 ;
int V_28 , V_29 = 0 ;
V_10 ;
if ( V_22 && V_22 -> V_30 > 0 ) {
V_23 = 0 ;
V_24 = V_22 -> V_31 +
F_7 ( V_22 -> V_30 ) +
F_7 ( V_22 -> V_32 ) +
F_7 ( V_22 -> V_33 ) ;
V_25 = F_8 ( V_22 -> V_34 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
RETURN ( - V_11 ) ;
V_26 = F_8 ( V_22 -> V_35 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
RETURN ( - V_11 ) ;
V_22 -> V_30 = 0 ;
V_27 = V_22 -> V_36 ;
}
V_28 = V_19 -> V_37 ;
if ( V_28 < V_25 )
RETURN ( 0 ) ;
if ( V_26 > 0 && V_28 > V_26 )
RETURN ( - V_38 ) ;
if ( V_17 -> V_39 -> V_40 & V_41 ) {
struct V_42 * V_43 = (struct V_42 * ) V_19 ;
struct V_16 * V_44 ;
if ( V_19 -> V_45 != V_46 ) {
V_23 = snprintf ( V_27 , V_24 , L_1
L_2 ,
V_28 , V_19 -> V_45 ,
V_19 -> V_47 ) ;
}
if ( V_17 -> V_48 == NULL )
RETURN ( - V_49 ) ;
V_29 = F_9 ( V_15 , V_17 , & V_44 , & V_43 -> V_50 ) ;
if ( V_29 ) {
F_10 ( V_51 , L_3 V_52 L_4 ,
F_11 ( & V_43 -> V_50 . V_12 ) ,
V_43 -> V_50 . V_13 ) ;
RETURN ( V_29 ) ;
}
V_29 = F_12 ( V_15 , V_44 , F_6 , NULL , NULL ) ;
F_13 ( V_44 ) ;
} else {
bool V_53 ;
switch ( V_19 -> V_45 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_53 = true ;
break;
default:
V_53 = false ;
}
V_23 = snprintf ( V_27 , V_24 , L_1
L_5 ,
V_28 , V_19 -> V_45 , V_19 -> V_47 ,
V_53 ? L_6 : L_7 ) ;
V_27 += V_23 ;
V_24 -= V_23 ;
if ( V_24 <= 0 ) {
F_14 ( L_8 ,
V_17 -> V_48 -> V_61 -> V_62 ) ;
RETURN ( - V_38 ) ;
}
}
RETURN ( V_29 ) ;
}
static int F_15 ( const struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 , void * V_20 )
{
struct V_21 * V_22 = (struct V_21 * ) V_20 ;
static int V_23 , V_24 , V_25 , V_26 ;
static char * V_27 ;
char * V_7 ;
int V_28 ;
V_10 ;
if ( V_22 != NULL && V_22 -> V_30 > 0 ) {
V_23 = 0 ;
V_24 = V_22 -> V_31 +
F_7 ( V_22 -> V_30 ) +
F_7 ( V_22 -> V_32 ) +
F_7 ( V_22 -> V_33 ) ;
V_25 = F_8 ( V_22 -> V_34 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
RETURN ( - V_11 ) ;
V_26 = F_8 ( V_22 -> V_35 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
RETURN ( - V_11 ) ;
V_27 = V_22 -> V_36 ;
V_22 -> V_30 = 0 ;
}
V_28 = V_19 -> V_37 ;
if ( V_28 < V_25 )
RETURN ( 0 ) ;
if ( V_26 > 0 && V_28 > V_26 )
RETURN ( - V_38 ) ;
if ( V_17 -> V_39 -> V_40 & V_41 ) {
struct V_42 * V_43 = (struct V_42 * ) V_19 ;
if ( V_19 -> V_45 != V_46 ) {
F_14 ( L_9 ) ;
RETURN ( - V_11 ) ;
}
V_23 = snprintf ( V_27 , V_24 ,
L_10 V_52 L_4 ,
V_28 , F_11 ( & V_43 -> V_50 . V_12 ) ,
V_43 -> V_50 . V_13 ) ;
} else if ( V_19 -> V_45 == V_58 ) {
int V_29 ;
V_29 = F_16 ( V_19 , V_27 , V_24 ) ;
if ( V_29 < 0 )
RETURN ( V_29 ) ;
V_23 = V_29 ;
} else {
V_23 = snprintf ( V_27 , V_24 ,
L_11 ,
V_28 , V_19 -> V_45 , V_19 -> V_47 ) ;
}
V_27 += V_23 ;
V_24 -= V_23 ;
if ( V_24 <= 0 ) {
F_14 ( L_12 ) ;
RETURN ( - V_38 ) ;
}
RETURN ( 0 ) ;
}
static int F_17 ( const struct V_14 * V_15 , struct V_16 * V_63 ,
struct V_1 * V_2 )
{
struct V_16 * log ;
int V_29 ;
V_10 ;
V_29 = F_9 ( V_15 , V_63 , & log , V_2 ) ;
if ( V_29 ) {
F_10 ( V_51 , L_3 V_52 L_4 ,
F_11 ( & V_2 -> V_12 ) , V_2 -> V_13 ) ;
RETURN ( - V_64 ) ;
}
V_29 = F_18 ( V_15 , log ) ;
if ( V_29 ) {
F_10 ( V_51 , L_13 ) ;
GOTO ( V_27 , V_29 ) ;
}
F_19 ( V_15 , V_63 , log , log -> V_65 . V_66 . V_67 . V_68 ) ;
V_27:
F_13 ( log ) ;
RETURN ( V_29 ) ;
}
static int F_20 ( const struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 , void * V_20 )
{
struct V_42 * V_43 = (struct V_42 * ) V_19 ;
int V_29 ;
V_10 ;
if ( V_19 -> V_45 != V_46 )
RETURN ( - V_11 ) ;
V_29 = F_17 ( V_15 , V_17 , & V_43 -> V_50 ) ;
RETURN ( V_29 ) ;
}
int F_21 ( const struct V_14 * V_15 , struct V_69 * V_70 , int V_71 ,
struct V_21 * V_20 )
{
struct V_1 V_2 ;
int V_29 = 0 ;
struct V_16 * V_17 = NULL ;
V_10 ;
if ( * V_20 -> V_72 == '#' ) {
V_29 = F_1 ( & V_2 , V_20 -> V_72 , V_20 -> V_30 ) ;
if ( V_29 )
RETURN ( V_29 ) ;
V_29 = F_22 ( V_15 , V_70 , & V_17 , & V_2 , NULL ,
V_73 ) ;
if ( V_29 )
RETURN ( V_29 ) ;
} else if ( * V_20 -> V_72 == '$' ) {
char * V_74 = V_20 -> V_72 + 1 ;
V_29 = F_22 ( V_15 , V_70 , & V_17 , NULL , V_74 ,
V_73 ) ;
if ( V_29 )
RETURN ( V_29 ) ;
} else {
RETURN ( - V_11 ) ;
}
V_29 = F_23 ( V_15 , V_17 , 0 , NULL ) ;
if ( V_29 )
GOTO ( V_75 , V_29 = - V_64 ) ;
switch ( V_71 ) {
case V_76 : {
int V_23 ;
int V_24 = V_20 -> V_32 +
F_7 ( V_20 -> V_30 ) ;
char * V_27 = V_20 -> V_36 ;
V_23 = snprintf ( V_27 , V_24 ,
L_14 V_52 L_4
L_15
L_16
L_17 ,
F_11 ( & V_17 -> V_77 . V_12 ) ,
V_17 -> V_77 . V_13 ,
V_17 -> V_39 -> V_40 ,
V_17 -> V_39 -> V_40 &
V_41 ? L_18 : L_19 ,
V_17 -> V_39 -> V_78 ,
V_17 -> V_79 ) ;
V_27 += V_23 ;
V_24 -= V_23 ;
if ( V_24 <= 0 ) {
F_14 ( L_20 ,
V_70 -> V_61 -> V_62 ) ;
V_29 = - V_80 ;
}
break;
}
case V_81 :
F_24 ( V_20 -> V_30 > 0 ) ;
V_29 = F_12 ( V_15 , V_17 , F_6 , V_20 , NULL ) ;
if ( V_29 == - V_38 )
V_29 = 0 ;
else if ( V_29 )
GOTO ( V_75 , V_29 ) ;
break;
case V_82 :
F_24 ( V_20 -> V_30 > 0 ) ;
V_29 = F_12 ( V_15 , V_17 , F_15 , V_20 , NULL ) ;
if ( V_29 == - V_38 )
V_29 = 0 ;
else if ( V_29 )
GOTO ( V_75 , V_29 ) ;
break;
case V_83 : {
struct V_84 V_85 ;
struct V_1 V_86 ;
char * V_7 ;
V_85 . V_68 = F_5 ( V_20 -> V_35 , & V_7 , 0 ) ;
if ( * V_7 != '\0' )
GOTO ( V_75 , V_29 = - V_11 ) ;
if ( V_17 -> V_39 -> V_40 & V_87 ) {
V_29 = F_25 ( NULL , V_17 , V_85 . V_68 ) ;
GOTO ( V_75 , V_29 ) ;
} else if ( ! ( V_17 -> V_39 -> V_40 & V_41 ) ) {
GOTO ( V_75 , V_29 = - V_11 ) ;
}
if ( V_20 -> V_34 == NULL )
GOTO ( V_75 , V_29 = - V_88 ) ;
V_29 = F_1 ( & V_86 , V_20 -> V_34 , V_20 -> V_32 ) ;
if ( V_29 )
GOTO ( V_75 , V_29 ) ;
V_85 . V_89 = V_86 ;
V_29 = F_26 ( V_15 , V_17 , 1 , & V_85 ) ;
if ( V_29 )
GOTO ( V_75 , V_29 ) ;
break;
}
case V_90 : {
struct V_1 V_86 ;
if ( V_17 -> V_39 -> V_40 & V_87 ) {
V_29 = F_18 ( V_15 , V_17 ) ;
GOTO ( V_75 , V_29 ) ;
} else if ( ! ( V_17 -> V_39 -> V_40 & V_41 ) ) {
GOTO ( V_75 , V_29 = - V_11 ) ;
}
if ( V_20 -> V_34 > 0 ) {
V_29 = F_1 ( & V_86 , V_20 -> V_34 ,
V_20 -> V_32 ) ;
if ( V_29 )
GOTO ( V_75 , V_29 ) ;
V_29 = F_17 ( V_15 , V_17 , & V_86 ) ;
} else {
V_29 = F_12 ( V_15 , V_17 , F_20 , NULL ,
NULL ) ;
if ( V_29 )
GOTO ( V_75 , V_29 ) ;
}
break;
}
default:
F_14 ( L_21 ,
V_70 -> V_61 -> V_62 , V_71 ) ;
GOTO ( V_75 , V_29 = - V_88 ) ;
}
V_75:
if ( V_17 -> V_39 &&
V_17 -> V_39 -> V_40 & V_41 )
F_27 ( V_15 , V_17 ) ;
else
F_28 ( V_15 , V_17 ) ;
RETURN ( V_29 ) ;
}
