struct V_1 * T_1 F_1 ( unsigned int V_2 )
{
int V_3 ;
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = F_3 ( V_2 , sizeof( * V_4 -> V_6 ) , V_5 ) ;
if ( ! V_4 -> V_6 )
goto V_7;
V_4 -> V_2 = V_2 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
V_4 -> V_6 [ V_3 ] = F_4 ( - V_8 ) ;
return V_4 ;
V_7:
F_5 ( V_4 ) ;
return NULL ;
}
void T_1 F_6 ( const struct V_9 * V_6 ,
int V_10 , struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_9 * V_12 = & V_6 [ V_3 ] ;
V_11 = F_7 ( NULL , V_12 -> V_13 , V_12 -> V_14 ,
V_12 -> V_14 ? 0 : V_15 , V_12 -> V_16 ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( L_1 ,
V_12 -> V_13 , F_10 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_12 -> V_17 ] = V_11 ;
}
}
void T_1 F_11 ( const struct V_18 * V_6 ,
int V_10 , struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_18 * V_19 = & V_6 [ V_3 ] ;
V_11 = F_12 ( NULL , V_19 -> V_13 , V_19 -> V_20 ,
V_21 , V_19 -> V_22 , V_19 -> div ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( L_1 ,
V_19 -> V_13 , F_10 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_19 -> V_17 ] = V_11 ;
}
}
int T_1 F_13 ( struct V_23 * V_24 ,
const struct V_25 * V_6 ,
int V_10 , struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
struct V_26 * V_26 ;
if ( ! V_4 )
return - V_27 ;
V_26 = F_14 ( V_24 ) ;
if ( F_8 ( V_26 ) ) {
F_9 ( L_2 , V_24 -> V_28 ,
F_10 ( V_26 ) ) ;
return F_10 ( V_26 ) ;
}
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_25 * V_29 = & V_6 [ V_3 ] ;
V_11 = F_15 ( V_29 -> V_13 , V_29 -> V_20 ,
V_26 ,
V_29 -> V_30 -> V_31 ,
V_29 -> V_30 -> V_32 ,
V_29 -> V_30 -> V_33 ,
V_29 -> V_34 , V_29 -> V_35 ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( L_1 ,
V_29 -> V_13 , F_10 ( V_11 ) ) ;
continue;
}
V_4 -> V_6 [ V_29 -> V_17 ] = V_11 ;
}
return 0 ;
}
struct V_11 * T_1 F_16 ( const struct V_36 * V_37 ,
void T_2 * V_38 , T_3 * V_39 )
{
struct V_11 * V_11 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_29 = NULL ;
struct V_43 * div = NULL ;
struct V_44 * V_45 = NULL , * V_46 = NULL , * V_47 = NULL ;
const struct V_48 * V_49 = NULL , * V_50 = NULL , * V_51 = NULL ;
const char * const * V_52 ;
const char * V_14 ;
int V_53 ;
int V_54 ;
if ( V_37 -> V_55 >= 0 ) {
V_41 = F_2 ( sizeof( * V_41 ) , V_5 ) ;
if ( ! V_41 )
return F_4 ( - V_27 ) ;
V_41 -> V_56 = V_38 + V_37 -> V_57 ;
V_41 -> V_58 = F_17 ( V_37 -> V_59 ) - 1 ;
V_41 -> V_34 = V_37 -> V_55 ;
V_41 -> V_39 = V_39 ;
V_45 = & V_41 -> V_60 ;
V_49 = & V_61 ;
V_52 = V_37 -> V_52 ;
V_53 = V_37 -> V_53 ;
} else {
V_14 = V_37 -> V_14 ;
V_52 = & V_14 ;
V_53 = 1 ;
}
if ( V_37 -> V_62 >= 0 ) {
V_29 = F_2 ( sizeof( * V_29 ) , V_5 ) ;
if ( ! V_29 ) {
V_54 = - V_27 ;
goto V_7;
}
V_29 -> V_56 = V_38 + V_37 -> V_63 ;
V_29 -> V_64 = V_37 -> V_62 ;
V_29 -> V_65 = V_66 ;
V_29 -> V_39 = V_39 ;
V_46 = & V_29 -> V_60 ;
V_50 = & V_67 ;
}
if ( V_37 -> V_68 >= 0 ) {
div = F_2 ( sizeof( * div ) , V_5 ) ;
if ( ! div ) {
V_54 = - V_27 ;
goto V_7;
}
div -> V_56 = V_38 + V_37 -> V_69 ;
div -> V_34 = V_37 -> V_68 ;
div -> V_70 = V_37 -> V_71 ;
div -> V_39 = V_39 ;
V_47 = & div -> V_60 ;
V_51 = & V_72 ;
}
V_11 = F_18 ( NULL , V_37 -> V_13 , V_52 , V_53 ,
V_45 , V_49 ,
V_47 , V_51 ,
V_46 , V_50 ,
V_37 -> V_65 ) ;
if ( F_8 ( V_11 ) ) {
F_5 ( V_29 ) ;
F_5 ( V_41 ) ;
}
return V_11 ;
V_7:
F_5 ( V_41 ) ;
return F_4 ( V_54 ) ;
}
void T_1 F_19 ( const struct V_36 * V_73 ,
int V_10 , void T_2 * V_38 , T_3 * V_39 ,
struct V_1 * V_4 )
{
struct V_11 * V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_36 * V_37 = & V_73 [ V_3 ] ;
V_11 = F_16 ( V_37 , V_38 , V_39 ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( L_1 ,
V_37 -> V_13 , F_10 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_37 -> V_17 ] = V_11 ;
}
}
