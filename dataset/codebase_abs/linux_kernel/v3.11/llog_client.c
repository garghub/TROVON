static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 , enum V_8 V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = V_4 -> V_16 ;
struct V_17 * V_18 = NULL ;
int V_19 ;
V_20 ;
F_2 ( V_15 , V_11 ) ;
F_3 ( V_9 != V_21 , L_1 , V_9 ) ;
F_4 ( V_4 ) ;
V_18 = F_5 ( V_11 , & V_22 ) ;
if ( V_18 == NULL )
GOTO ( V_23 , V_19 = - V_24 ) ;
if ( V_7 )
F_6 ( & V_18 -> V_25 , & V_26 , V_27 ,
strlen ( V_7 ) + 1 ) ;
V_19 = F_7 ( V_18 , V_28 ,
V_29 ) ;
if ( V_19 ) {
F_8 ( V_18 ) ;
V_18 = NULL ;
GOTO ( V_23 , V_19 ) ;
}
F_9 ( V_18 ) ;
V_13 = F_10 ( & V_18 -> V_25 , & V_30 ) ;
if ( V_6 )
V_13 -> V_31 = * V_6 ;
V_13 -> V_32 = V_15 -> V_33 - 1 ;
if ( V_7 ) {
char * V_34 ;
V_34 = F_11 ( & V_18 -> V_25 , & V_26 ,
strlen ( V_7 ) + 1 ) ;
F_4 ( V_34 ) ;
strcpy ( V_34 , V_7 ) ;
}
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_23 , V_19 ) ;
V_13 = F_13 ( & V_18 -> V_25 , & V_30 ) ;
if ( V_13 == NULL )
GOTO ( V_23 , V_19 = - V_35 ) ;
V_4 -> V_36 = V_13 -> V_31 ;
V_4 -> V_16 = V_15 ;
EXIT ;
V_23:
F_14 ( V_15 , V_11 ) ;
F_15 ( V_18 ) ;
return V_19 ;
}
static int F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_37 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
int V_19 ;
V_20 ;
F_2 ( V_37 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_38 ,
V_28 ,
V_39 ) ;
if ( V_18 == NULL )
GOTO ( V_40 , V_19 = - V_24 ) ;
V_13 = F_10 ( & V_18 -> V_25 , & V_30 ) ;
V_13 -> V_31 = V_37 -> V_36 ;
V_13 -> V_41 = V_37 -> V_42 -> V_43 ;
if ( ! ( V_13 -> V_41 & V_44 ) )
F_18 ( L_2 , V_11 -> V_45 -> V_46 ,
V_13 -> V_41 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
F_15 ( V_18 ) ;
V_40:
F_14 ( V_37 -> V_16 , V_11 ) ;
RETURN ( V_19 ) ;
}
static int F_19 ( const struct V_1 * V_2 ,
struct V_3 * V_37 ,
int * V_47 , int V_48 ,
T_1 * V_49 , void * V_50 , int V_51 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
void * V_52 ;
int V_19 ;
V_20 ;
F_2 ( V_37 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_53 ,
V_28 ,
V_54 ) ;
if ( V_18 == NULL )
GOTO ( V_40 , V_19 = - V_24 ) ;
V_13 = F_10 ( & V_18 -> V_25 , & V_30 ) ;
V_13 -> V_31 = V_37 -> V_36 ;
V_13 -> V_32 = V_37 -> V_16 -> V_33 - 1 ;
V_13 -> V_41 = V_37 -> V_42 -> V_43 ;
V_13 -> V_55 = V_48 ;
V_13 -> V_56 = * V_47 ;
V_13 -> V_57 = V_51 ;
V_13 -> V_58 = * V_49 ;
F_6 ( & V_18 -> V_25 , & V_59 , V_60 , V_51 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_23 , V_19 ) ;
V_13 = F_13 ( & V_18 -> V_25 , & V_30 ) ;
if ( V_13 == NULL )
GOTO ( V_23 , V_19 = - V_35 ) ;
V_52 = F_13 ( & V_18 -> V_25 , & V_59 ) ;
if ( V_52 == NULL )
GOTO ( V_23 , V_19 = - V_35 ) ;
* V_47 = V_13 -> V_56 ;
* V_49 = V_13 -> V_58 ;
memcpy ( V_50 , V_52 , V_51 ) ;
EXIT ;
V_23:
F_15 ( V_18 ) ;
V_40:
F_14 ( V_37 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_20 ( const struct V_1 * V_2 ,
struct V_3 * V_37 ,
int V_61 , void * V_50 , int V_51 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
void * V_52 ;
int V_19 ;
V_20 ;
F_2 ( V_37 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_62 ,
V_28 ,
V_63 ) ;
if ( V_18 == NULL )
GOTO ( V_40 , V_19 = - V_24 ) ;
V_13 = F_10 ( & V_18 -> V_25 , & V_30 ) ;
V_13 -> V_31 = V_37 -> V_36 ;
V_13 -> V_32 = V_37 -> V_16 -> V_33 - 1 ;
V_13 -> V_41 = V_37 -> V_42 -> V_43 ;
V_13 -> V_55 = V_61 ;
V_13 -> V_57 = V_51 ;
F_6 ( & V_18 -> V_25 , & V_59 , V_60 , V_51 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_23 , V_19 ) ;
V_13 = F_13 ( & V_18 -> V_25 , & V_30 ) ;
if ( V_13 == NULL )
GOTO ( V_23 , V_19 = - V_35 ) ;
V_52 = F_13 ( & V_18 -> V_25 , & V_59 ) ;
if ( V_52 == NULL )
GOTO ( V_23 , V_19 = - V_35 ) ;
memcpy ( V_50 , V_52 , V_51 ) ;
EXIT ;
V_23:
F_15 ( V_18 ) ;
V_40:
F_14 ( V_37 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_21 ( const struct V_1 * V_2 ,
struct V_3 * V_64 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int V_19 ;
V_20 ;
F_2 ( V_64 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_69 ,
V_28 ,
V_70 ) ;
if ( V_18 == NULL )
GOTO ( V_40 , V_19 = - V_24 ) ;
V_13 = F_10 ( & V_18 -> V_25 , & V_30 ) ;
V_13 -> V_31 = V_64 -> V_36 ;
V_13 -> V_32 = V_64 -> V_16 -> V_33 - 1 ;
V_13 -> V_41 = V_64 -> V_42 -> V_43 ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
GOTO ( V_23 , V_19 ) ;
V_66 = F_13 ( & V_18 -> V_25 , & V_71 ) ;
if ( V_66 == NULL )
GOTO ( V_23 , V_19 = - V_35 ) ;
memcpy ( V_64 -> V_42 , V_66 , sizeof ( * V_66 ) ) ;
V_64 -> V_72 = V_64 -> V_42 -> V_73 . V_74 ;
V_68 = & V_64 -> V_42 -> V_68 ;
if ( V_68 -> V_75 != V_76 ) {
F_18 ( L_3 ,
V_68 -> V_75 , V_76 ) ;
V_19 = - V_77 ;
} else if ( V_68 -> V_78 != V_79 ) {
F_18 ( L_4
L_5 ,
V_68 -> V_78 , V_79 ) ;
F_18 ( L_6 ) ;
V_19 = - V_77 ;
}
EXIT ;
V_23:
F_15 ( V_18 ) ;
V_40:
F_14 ( V_64 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_22 ( const struct V_1 * V_2 ,
struct V_3 * V_64 )
{
return ( 0 ) ;
}
