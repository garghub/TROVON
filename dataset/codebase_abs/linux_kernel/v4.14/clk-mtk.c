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
void F_6 ( const struct V_9 * V_6 ,
int V_10 , struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_9 * V_12 = & V_6 [ V_3 ] ;
if ( V_4 && ! F_7 ( V_4 -> V_6 [ V_12 -> V_13 ] ) )
continue;
V_11 = F_8 ( NULL , V_12 -> V_14 , V_12 -> V_15 , 0 ,
V_12 -> V_16 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_12 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_12 -> V_13 ] = V_11 ;
}
}
void F_12 ( const struct V_17 * V_6 ,
int V_10 , struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_17 * V_18 = & V_6 [ V_3 ] ;
if ( V_4 && ! F_7 ( V_4 -> V_6 [ V_18 -> V_13 ] ) )
continue;
V_11 = F_13 ( NULL , V_18 -> V_14 , V_18 -> V_19 ,
V_20 , V_18 -> V_21 , V_18 -> div ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_18 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_18 -> V_13 ] = V_11 ;
}
}
int F_14 ( struct V_22 * V_23 ,
const struct V_24 * V_6 ,
int V_10 , struct V_1 * V_4 )
{
int V_3 ;
struct V_11 * V_11 ;
struct V_25 * V_25 ;
if ( ! V_4 )
return - V_26 ;
V_25 = F_15 ( V_23 ) ;
if ( F_9 ( V_25 ) ) {
F_10 ( L_2 , V_23 ,
F_11 ( V_25 ) ) ;
return F_11 ( V_25 ) ;
}
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_24 * V_27 = & V_6 [ V_3 ] ;
if ( ! F_7 ( V_4 -> V_6 [ V_27 -> V_13 ] ) )
continue;
V_11 = F_16 ( V_27 -> V_14 , V_27 -> V_19 ,
V_25 ,
V_27 -> V_28 -> V_29 ,
V_27 -> V_28 -> V_30 ,
V_27 -> V_28 -> V_31 ,
V_27 -> V_32 , V_27 -> V_33 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_27 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
V_4 -> V_6 [ V_27 -> V_13 ] = V_11 ;
}
return 0 ;
}
struct V_11 * F_17 ( const struct V_34 * V_35 ,
void T_1 * V_36 , T_2 * V_37 )
{
struct V_11 * V_11 ;
struct V_38 * V_39 = NULL ;
struct V_40 * V_27 = NULL ;
struct V_41 * div = NULL ;
struct V_42 * V_43 = NULL , * V_44 = NULL , * V_45 = NULL ;
const struct V_46 * V_47 = NULL , * V_48 = NULL , * V_49 = NULL ;
const char * const * V_50 ;
const char * V_15 ;
int V_51 ;
int V_52 ;
if ( V_35 -> V_53 >= 0 ) {
V_39 = F_2 ( sizeof( * V_39 ) , V_5 ) ;
if ( ! V_39 )
return F_4 ( - V_26 ) ;
V_39 -> V_54 = V_36 + V_35 -> V_55 ;
V_39 -> V_56 = F_18 ( V_35 -> V_57 ) - 1 ;
V_39 -> V_32 = V_35 -> V_53 ;
V_39 -> V_37 = V_37 ;
V_43 = & V_39 -> V_58 ;
V_47 = & V_59 ;
V_50 = V_35 -> V_50 ;
V_51 = V_35 -> V_51 ;
} else {
V_15 = V_35 -> V_15 ;
V_50 = & V_15 ;
V_51 = 1 ;
}
if ( V_35 -> V_60 >= 0 ) {
V_27 = F_2 ( sizeof( * V_27 ) , V_5 ) ;
if ( ! V_27 ) {
V_52 = - V_26 ;
goto V_7;
}
V_27 -> V_54 = V_36 + V_35 -> V_61 ;
V_27 -> V_62 = V_35 -> V_60 ;
V_27 -> V_63 = V_64 ;
V_27 -> V_37 = V_37 ;
V_44 = & V_27 -> V_58 ;
V_48 = & V_65 ;
}
if ( V_35 -> V_66 >= 0 ) {
div = F_2 ( sizeof( * div ) , V_5 ) ;
if ( ! div ) {
V_52 = - V_26 ;
goto V_7;
}
div -> V_54 = V_36 + V_35 -> V_67 ;
div -> V_32 = V_35 -> V_66 ;
div -> V_68 = V_35 -> V_69 ;
div -> V_37 = V_37 ;
V_45 = & div -> V_58 ;
V_49 = & V_70 ;
}
V_11 = F_19 ( NULL , V_35 -> V_14 , V_50 , V_51 ,
V_43 , V_47 ,
V_45 , V_49 ,
V_44 , V_48 ,
V_35 -> V_63 ) ;
if ( F_9 ( V_11 ) ) {
V_52 = F_11 ( V_11 ) ;
goto V_7;
}
return V_11 ;
V_7:
F_5 ( div ) ;
F_5 ( V_27 ) ;
F_5 ( V_39 ) ;
return F_4 ( V_52 ) ;
}
void F_20 ( const struct V_34 * V_71 ,
int V_10 , void T_1 * V_36 , T_2 * V_37 ,
struct V_1 * V_4 )
{
struct V_11 * V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_34 * V_35 = & V_71 [ V_3 ] ;
if ( V_4 && ! F_7 ( V_4 -> V_6 [ V_35 -> V_13 ] ) )
continue;
V_11 = F_17 ( V_35 , V_36 , V_37 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_35 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_35 -> V_13 ] = V_11 ;
}
}
void F_21 ( const struct V_72 * V_73 ,
int V_10 , void T_1 * V_36 , T_2 * V_37 ,
struct V_1 * V_4 )
{
struct V_11 * V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_72 * V_74 = & V_73 [ V_3 ] ;
if ( V_4 && ! F_7 ( V_4 -> V_6 [ V_74 -> V_13 ] ) )
continue;
V_11 = F_22 ( NULL , V_74 -> V_14 , V_74 -> V_19 ,
V_74 -> V_63 , V_36 + V_74 -> V_75 , V_74 -> V_76 ,
V_74 -> V_77 , V_74 -> V_78 , V_37 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_74 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_74 -> V_13 ] = V_11 ;
}
}
