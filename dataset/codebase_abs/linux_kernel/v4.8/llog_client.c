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
if ( ! V_18 ) {
V_19 = - V_22 ;
goto V_23;
}
if ( V_7 )
F_6 ( & V_18 -> V_24 , & V_25 , V_26 ,
strlen ( V_7 ) + 1 ) ;
V_19 = F_7 ( V_18 , V_27 ,
V_28 ) ;
if ( V_19 ) {
F_8 ( V_18 ) ;
V_18 = NULL ;
goto V_23;
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
goto V_23;
V_13 = F_13 ( & V_18 -> V_24 , & V_29 ) ;
if ( ! V_13 ) {
V_19 = - V_34 ;
goto V_23;
}
V_4 -> V_35 = V_13 -> V_30 ;
V_4 -> V_16 = V_15 ;
V_23:
F_14 ( V_15 , V_11 ) ;
F_15 ( V_18 ) ;
return V_19 ;
}
static int F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_36 ,
int * V_37 , int V_38 ,
T_1 * V_39 , void * V_40 , int V_41 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
void * V_42 ;
int V_19 ;
F_2 ( V_36 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_43 ,
V_27 ,
V_44 ) ;
if ( ! V_18 ) {
V_19 = - V_22 ;
goto V_45;
}
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
V_13 -> V_30 = V_36 -> V_35 ;
V_13 -> V_31 = V_36 -> V_16 -> V_32 - 1 ;
V_13 -> V_46 = V_36 -> V_47 -> V_48 ;
V_13 -> V_49 = V_38 ;
V_13 -> V_50 = * V_37 ;
V_13 -> V_51 = V_41 ;
V_13 -> V_52 = * V_39 ;
F_6 ( & V_18 -> V_24 , & V_53 , V_54 , V_41 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
goto V_23;
V_13 = F_13 ( & V_18 -> V_24 , & V_29 ) ;
if ( ! V_13 ) {
V_19 = - V_34 ;
goto V_23;
}
V_42 = F_13 ( & V_18 -> V_24 , & V_53 ) ;
if ( ! V_42 ) {
V_19 = - V_34 ;
goto V_23;
}
* V_37 = V_13 -> V_50 ;
* V_39 = V_13 -> V_52 ;
memcpy ( V_40 , V_42 , V_41 ) ;
V_23:
F_15 ( V_18 ) ;
V_45:
F_14 ( V_36 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_18 ( const struct V_1 * V_2 ,
struct V_3 * V_36 ,
int V_55 , void * V_40 , int V_41 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
void * V_42 ;
int V_19 ;
F_2 ( V_36 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_56 ,
V_27 ,
V_57 ) ;
if ( ! V_18 ) {
V_19 = - V_22 ;
goto V_45;
}
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
V_13 -> V_30 = V_36 -> V_35 ;
V_13 -> V_31 = V_36 -> V_16 -> V_32 - 1 ;
V_13 -> V_46 = V_36 -> V_47 -> V_48 ;
V_13 -> V_49 = V_55 ;
V_13 -> V_51 = V_41 ;
F_6 ( & V_18 -> V_24 , & V_53 , V_54 , V_41 ) ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
goto V_23;
V_13 = F_13 ( & V_18 -> V_24 , & V_29 ) ;
if ( ! V_13 ) {
V_19 = - V_34 ;
goto V_23;
}
V_42 = F_13 ( & V_18 -> V_24 , & V_53 ) ;
if ( ! V_42 ) {
V_19 = - V_34 ;
goto V_23;
}
memcpy ( V_40 , V_42 , V_41 ) ;
V_23:
F_15 ( V_18 ) ;
V_45:
F_14 ( V_36 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_19 ( const struct V_1 * V_2 ,
struct V_3 * V_58 )
{
struct V_10 * V_11 ;
struct V_17 * V_18 = NULL ;
struct V_12 * V_13 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
int V_19 ;
F_2 ( V_58 -> V_16 , V_11 ) ;
V_18 = F_17 ( V_11 , & V_63 ,
V_27 ,
V_64 ) ;
if ( ! V_18 ) {
V_19 = - V_22 ;
goto V_45;
}
V_13 = F_10 ( & V_18 -> V_24 , & V_29 ) ;
V_13 -> V_30 = V_58 -> V_35 ;
V_13 -> V_31 = V_58 -> V_16 -> V_32 - 1 ;
V_13 -> V_46 = V_58 -> V_47 -> V_48 ;
F_9 ( V_18 ) ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 )
goto V_23;
V_60 = F_13 ( & V_18 -> V_24 , & V_65 ) ;
if ( ! V_60 ) {
V_19 = - V_34 ;
goto V_23;
}
memcpy ( V_58 -> V_47 , V_60 , sizeof( * V_60 ) ) ;
V_58 -> V_66 = V_58 -> V_47 -> V_67 . V_68 ;
V_62 = & V_58 -> V_47 -> V_62 ;
if ( V_62 -> V_69 != V_70 ) {
F_20 ( L_2 ,
V_62 -> V_69 , V_70 ) ;
V_19 = - V_71 ;
} else if ( V_62 -> V_72 != V_73 ) {
F_20 ( L_3 ,
V_62 -> V_72 , V_73 ) ;
F_20 ( L_4 ) ;
V_19 = - V_71 ;
}
V_23:
F_15 ( V_18 ) ;
V_45:
F_14 ( V_58 -> V_16 , V_11 ) ;
return V_19 ;
}
static int F_21 ( const struct V_1 * V_2 ,
struct V_3 * V_58 )
{
return 0 ;
}
