struct V_1 * F_1 ( unsigned int V_2 )
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
void F_6 ( const struct V_9 * V_6 , int V_10 ,
struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_9 * V_12 = & V_6 [ V_3 ] ;
V_11 = F_7 ( NULL , V_12 -> V_13 , V_12 -> V_14 ,
V_15 , V_12 -> V_16 , V_12 -> div ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( L_1 ,
V_12 -> V_13 , F_10 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_12 -> V_17 ] = V_11 ;
}
}
int F_11 ( struct V_18 * V_19 , const struct V_20 * V_6 ,
int V_10 , struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
struct V_21 * V_21 ;
if ( ! V_4 )
return - V_22 ;
V_21 = F_12 ( V_19 ) ;
if ( F_8 ( V_21 ) ) {
F_9 ( L_2 , V_19 -> V_23 ,
F_10 ( V_21 ) ) ;
return F_10 ( V_21 ) ;
}
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_20 * V_24 = & V_6 [ V_3 ] ;
V_11 = F_13 ( V_24 -> V_13 , V_24 -> V_14 ,
V_21 ,
V_24 -> V_25 -> V_26 ,
V_24 -> V_25 -> V_27 ,
V_24 -> V_25 -> V_28 ,
V_24 -> V_29 , V_24 -> V_30 ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( L_1 ,
V_24 -> V_13 , F_10 ( V_11 ) ) ;
continue;
}
V_4 -> V_6 [ V_24 -> V_17 ] = V_11 ;
}
return 0 ;
}
struct V_11 * F_14 ( const struct V_31 * V_32 ,
void T_1 * V_33 , T_2 * V_34 )
{
struct V_11 * V_11 ;
struct V_35 * V_36 = NULL ;
struct V_37 * V_24 = NULL ;
struct V_38 * div = NULL ;
struct V_39 * V_40 = NULL , * V_41 = NULL , * V_42 = NULL ;
const struct V_43 * V_44 = NULL , * V_45 = NULL , * V_46 = NULL ;
const char * const * V_47 ;
const char * V_48 ;
int V_49 ;
int V_50 ;
if ( V_32 -> V_51 >= 0 ) {
V_36 = F_2 ( sizeof( * V_36 ) , V_5 ) ;
if ( ! V_36 )
return F_4 ( - V_22 ) ;
V_36 -> V_52 = V_33 + V_32 -> V_53 ;
V_36 -> V_54 = F_15 ( V_32 -> V_55 ) - 1 ;
V_36 -> V_29 = V_32 -> V_51 ;
V_36 -> V_34 = V_34 ;
V_40 = & V_36 -> V_56 ;
V_44 = & V_57 ;
V_47 = V_32 -> V_47 ;
V_49 = V_32 -> V_49 ;
} else {
V_48 = V_32 -> V_48 ;
V_47 = & V_48 ;
V_49 = 1 ;
}
if ( V_32 -> V_58 >= 0 ) {
V_24 = F_2 ( sizeof( * V_24 ) , V_5 ) ;
if ( ! V_24 ) {
V_50 = - V_22 ;
goto V_7;
}
V_24 -> V_52 = V_33 + V_32 -> V_59 ;
V_24 -> V_60 = V_32 -> V_58 ;
V_24 -> V_61 = V_62 ;
V_24 -> V_34 = V_34 ;
V_41 = & V_24 -> V_56 ;
V_45 = & V_63 ;
}
if ( V_32 -> V_64 >= 0 ) {
div = F_2 ( sizeof( * div ) , V_5 ) ;
if ( ! div ) {
V_50 = - V_22 ;
goto V_7;
}
div -> V_52 = V_33 + V_32 -> V_65 ;
div -> V_29 = V_32 -> V_64 ;
div -> V_66 = V_32 -> V_67 ;
div -> V_34 = V_34 ;
V_42 = & div -> V_56 ;
V_46 = & V_68 ;
}
V_11 = F_16 ( NULL , V_32 -> V_13 , V_47 , V_49 ,
V_40 , V_44 ,
V_42 , V_46 ,
V_41 , V_45 ,
V_32 -> V_61 ) ;
if ( F_8 ( V_11 ) ) {
F_5 ( V_24 ) ;
F_5 ( V_36 ) ;
}
return V_11 ;
V_7:
F_5 ( V_36 ) ;
return F_4 ( V_50 ) ;
}
void F_17 ( const struct V_31 * V_69 ,
int V_10 , void T_1 * V_33 , T_2 * V_34 ,
struct V_1 * V_4 )
{
struct V_11 * V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_31 * V_32 = & V_69 [ V_3 ] ;
V_11 = F_14 ( V_32 , V_33 , V_34 ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( L_1 ,
V_32 -> V_13 , F_10 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_32 -> V_17 ] = V_11 ;
}
}
