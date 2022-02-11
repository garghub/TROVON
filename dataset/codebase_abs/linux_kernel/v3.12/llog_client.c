static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 , enum V_8 V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = V_4 -> V_16 ;
struct V_17 * V_18 = NULL ;
int V_19 ;
F_2 ( V_15 , V_11 ) ;
F_3 ( V_9 != V_20 , L_1 , V_9 ) ;
F_4 ( V_4 ) ;
V_18 = F_5 ( V_11 , & V_21 ) ;
if ( V_18 == NULL )
GOTO ( V_22 , V_19 = - V_23 ) ;
if ( V_7 )
F_6 ( & V_18 -> V_24 , & V_25 , V_26 ,
strlen ( V_7 ) + 1 ) ;
V_19 = F_7 ( V_18 , V_27 ,
V_28 ) ;
if ( V_19 ) {
F_8 ( V_18 ) ;
V_18 = NULL ;
GOTO ( V_22 , V_19 ) ;
}
F_9 ( V_18 ) ;
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
if ( V_6 )
V_13 -> V_30 = * V_6 ;
V_13 -> V_31 = V_15 -> V_32 - 1 ;
if ( V_7 ) {
char * V_33 ;
V_33 = F_11 ( & V_18 -> V_24 , & V_25 ,
strlen ( V_7 ) + 1 ) ;
F_4 ( V_33 ) ;
strcpy ( V_33 , V_7 ) ;
}
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_22 , V_19 ) ;
V_13 = F_13 ( & V_18 -> V_24 , & V_29 ) ;
if ( V_13 == NULL )
GOTO ( V_22 , V_19 = - V_34 ) ;
V_4 -> V_35 = V_13 -> V_30 ;
V_4 -> V_16 = V_15 ;
V_22:
F_14 ( V_15 , V_11 ) ;
F_15 ( V_18 ) ;
return V_19 ;
}
static int F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_36 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
int V_19 ;
F_2 ( V_36 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_37 ,
V_27 ,
V_38 ) ;
if ( V_18 == NULL )
GOTO ( V_39 , V_19 = - V_23 ) ;
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
V_13 -> V_30 = V_36 -> V_35 ;
V_13 -> V_40 = V_36 -> V_41 -> V_42 ;
if ( ! ( V_13 -> V_40 & V_43 ) )
F_18 ( L_2 , V_11 -> V_44 -> V_45 ,
V_13 -> V_40 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
F_15 ( V_18 ) ;
V_39:
F_14 ( V_36 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_19 ( const struct V_1 * V_2 ,
struct V_3 * V_36 ,
int * V_46 , int V_47 ,
T_1 * V_48 , void * V_49 , int V_50 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
void * V_51 ;
int V_19 ;
F_2 ( V_36 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_52 ,
V_27 ,
V_53 ) ;
if ( V_18 == NULL )
GOTO ( V_39 , V_19 = - V_23 ) ;
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
V_13 -> V_30 = V_36 -> V_35 ;
V_13 -> V_31 = V_36 -> V_16 -> V_32 - 1 ;
V_13 -> V_40 = V_36 -> V_41 -> V_42 ;
V_13 -> V_54 = V_47 ;
V_13 -> V_55 = * V_46 ;
V_13 -> V_56 = V_50 ;
V_13 -> V_57 = * V_48 ;
F_6 ( & V_18 -> V_24 , & V_58 , V_59 , V_50 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_22 , V_19 ) ;
V_13 = F_13 ( & V_18 -> V_24 , & V_29 ) ;
if ( V_13 == NULL )
GOTO ( V_22 , V_19 = - V_34 ) ;
V_51 = F_13 ( & V_18 -> V_24 , & V_58 ) ;
if ( V_51 == NULL )
GOTO ( V_22 , V_19 = - V_34 ) ;
* V_46 = V_13 -> V_55 ;
* V_48 = V_13 -> V_57 ;
memcpy ( V_49 , V_51 , V_50 ) ;
V_22:
F_15 ( V_18 ) ;
V_39:
F_14 ( V_36 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_20 ( const struct V_1 * V_2 ,
struct V_3 * V_36 ,
int V_60 , void * V_49 , int V_50 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
void * V_51 ;
int V_19 ;
F_2 ( V_36 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_61 ,
V_27 ,
V_62 ) ;
if ( V_18 == NULL )
GOTO ( V_39 , V_19 = - V_23 ) ;
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
V_13 -> V_30 = V_36 -> V_35 ;
V_13 -> V_31 = V_36 -> V_16 -> V_32 - 1 ;
V_13 -> V_40 = V_36 -> V_41 -> V_42 ;
V_13 -> V_54 = V_60 ;
V_13 -> V_56 = V_50 ;
F_6 ( & V_18 -> V_24 , & V_58 , V_59 , V_50 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_22 , V_19 ) ;
V_13 = F_13 ( & V_18 -> V_24 , & V_29 ) ;
if ( V_13 == NULL )
GOTO ( V_22 , V_19 = - V_34 ) ;
V_51 = F_13 ( & V_18 -> V_24 , & V_58 ) ;
if ( V_51 == NULL )
GOTO ( V_22 , V_19 = - V_34 ) ;
memcpy ( V_49 , V_51 , V_50 ) ;
V_22:
F_15 ( V_18 ) ;
V_39:
F_14 ( V_36 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_21 ( const struct V_1 * V_2 ,
struct V_3 * V_63 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int V_19 ;
F_2 ( V_63 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_68 ,
V_27 ,
V_69 ) ;
if ( V_18 == NULL )
GOTO ( V_39 , V_19 = - V_23 ) ;
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
V_13 -> V_30 = V_63 -> V_35 ;
V_13 -> V_31 = V_63 -> V_16 -> V_32 - 1 ;
V_13 -> V_40 = V_63 -> V_41 -> V_42 ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_22 , V_19 ) ;
V_65 = F_13 ( & V_18 -> V_24 , & V_70 ) ;
if ( V_65 == NULL )
GOTO ( V_22 , V_19 = - V_34 ) ;
memcpy ( V_63 -> V_41 , V_65 , sizeof ( * V_65 ) ) ;
V_63 -> V_71 = V_63 -> V_41 -> V_72 . V_73 ;
V_67 = & V_63 -> V_41 -> V_67 ;
if ( V_67 -> V_74 != V_75 ) {
F_18 ( L_3 ,
V_67 -> V_74 , V_75 ) ;
V_19 = - V_76 ;
} else if ( V_67 -> V_77 != V_78 ) {
F_18 ( L_4
L_5 ,
V_67 -> V_77 , V_78 ) ;
F_18 ( L_6 ) ;
V_19 = - V_76 ;
}
V_22:
F_15 ( V_18 ) ;
V_39:
F_14 ( V_63 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_22 ( const struct V_1 * V_2 ,
struct V_3 * V_63 )
{
return ( 0 ) ;
}
