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
F_10 ( L_2 , V_23 -> V_27 ,
F_11 ( V_25 ) ) ;
return F_11 ( V_25 ) ;
}
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_24 * V_28 = & V_6 [ V_3 ] ;
if ( ! F_7 ( V_4 -> V_6 [ V_28 -> V_13 ] ) )
continue;
V_11 = F_16 ( V_28 -> V_14 , V_28 -> V_19 ,
V_25 ,
V_28 -> V_29 -> V_30 ,
V_28 -> V_29 -> V_31 ,
V_28 -> V_29 -> V_32 ,
V_28 -> V_33 , V_28 -> V_34 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_28 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
V_4 -> V_6 [ V_28 -> V_13 ] = V_11 ;
}
return 0 ;
}
struct V_11 * F_17 ( const struct V_35 * V_36 ,
void T_1 * V_37 , T_2 * V_38 )
{
struct V_11 * V_11 ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_28 = NULL ;
struct V_42 * div = NULL ;
struct V_43 * V_44 = NULL , * V_45 = NULL , * V_46 = NULL ;
const struct V_47 * V_48 = NULL , * V_49 = NULL , * V_50 = NULL ;
const char * const * V_51 ;
const char * V_15 ;
int V_52 ;
int V_53 ;
if ( V_36 -> V_54 >= 0 ) {
V_40 = F_2 ( sizeof( * V_40 ) , V_5 ) ;
if ( ! V_40 )
return F_4 ( - V_26 ) ;
V_40 -> V_55 = V_37 + V_36 -> V_56 ;
V_40 -> V_57 = F_18 ( V_36 -> V_58 ) - 1 ;
V_40 -> V_33 = V_36 -> V_54 ;
V_40 -> V_38 = V_38 ;
V_44 = & V_40 -> V_59 ;
V_48 = & V_60 ;
V_51 = V_36 -> V_51 ;
V_52 = V_36 -> V_52 ;
} else {
V_15 = V_36 -> V_15 ;
V_51 = & V_15 ;
V_52 = 1 ;
}
if ( V_36 -> V_61 >= 0 ) {
V_28 = F_2 ( sizeof( * V_28 ) , V_5 ) ;
if ( ! V_28 ) {
V_53 = - V_26 ;
goto V_7;
}
V_28 -> V_55 = V_37 + V_36 -> V_62 ;
V_28 -> V_63 = V_36 -> V_61 ;
V_28 -> V_64 = V_65 ;
V_28 -> V_38 = V_38 ;
V_45 = & V_28 -> V_59 ;
V_49 = & V_66 ;
}
if ( V_36 -> V_67 >= 0 ) {
div = F_2 ( sizeof( * div ) , V_5 ) ;
if ( ! div ) {
V_53 = - V_26 ;
goto V_7;
}
div -> V_55 = V_37 + V_36 -> V_68 ;
div -> V_33 = V_36 -> V_67 ;
div -> V_69 = V_36 -> V_70 ;
div -> V_38 = V_38 ;
V_46 = & div -> V_59 ;
V_50 = & V_71 ;
}
V_11 = F_19 ( NULL , V_36 -> V_14 , V_51 , V_52 ,
V_44 , V_48 ,
V_46 , V_50 ,
V_45 , V_49 ,
V_36 -> V_64 ) ;
if ( F_9 ( V_11 ) ) {
V_53 = F_11 ( V_11 ) ;
goto V_7;
}
return V_11 ;
V_7:
F_5 ( div ) ;
F_5 ( V_28 ) ;
F_5 ( V_40 ) ;
return F_4 ( V_53 ) ;
}
void F_20 ( const struct V_35 * V_72 ,
int V_10 , void T_1 * V_37 , T_2 * V_38 ,
struct V_1 * V_4 )
{
struct V_11 * V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_35 * V_36 = & V_72 [ V_3 ] ;
if ( V_4 && ! F_7 ( V_4 -> V_6 [ V_36 -> V_13 ] ) )
continue;
V_11 = F_17 ( V_36 , V_37 , V_38 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_36 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_36 -> V_13 ] = V_11 ;
}
}
void F_21 ( const struct V_73 * V_74 ,
int V_10 , void T_1 * V_37 , T_2 * V_38 ,
struct V_1 * V_4 )
{
struct V_11 * V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
const struct V_73 * V_75 = & V_74 [ V_3 ] ;
if ( V_4 && ! F_7 ( V_4 -> V_6 [ V_75 -> V_13 ] ) )
continue;
V_11 = F_22 ( NULL , V_75 -> V_14 , V_75 -> V_19 ,
V_75 -> V_64 , V_37 + V_75 -> V_76 , V_75 -> V_77 ,
V_75 -> V_78 , V_75 -> V_79 , V_38 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( L_1 ,
V_75 -> V_14 , F_11 ( V_11 ) ) ;
continue;
}
if ( V_4 )
V_4 -> V_6 [ V_75 -> V_13 ] = V_11 ;
}
}
