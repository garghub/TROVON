static int F_1 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
unsigned int V_7 , V_8 ;
int V_9 , V_10 ;
struct V_1 V_11 = {
. V_12 = & V_8 ,
. V_13 = sizeof( V_8 ) ,
. V_14 = V_2 -> V_14
} ;
struct V_15 * V_16 , * V_17 ;
static F_2 ( V_18 ) ;
F_3 ( & V_18 ) ;
V_16 = F_4 ( V_15 ,
F_5 ( & V_18 ) ) ;
V_8 = V_7 = V_16 ? V_16 -> V_19 + 1 : 0 ;
V_9 = F_6 ( & V_11 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_3 ) {
if ( V_8 ) {
if ( V_8 > 1 << 30 ) {
F_7 ( & V_18 ) ;
return - V_20 ;
}
V_8 = F_8 ( V_8 ) ;
if ( V_8 != V_7 ) {
V_17 =
F_9 ( F_10 ( V_8 ) ) ;
if ( ! V_17 ) {
F_7 ( & V_18 ) ;
return - V_21 ;
}
V_17 -> V_19 = V_8 - 1 ;
} else
V_17 = V_16 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_17 -> V_22 [ V_10 ] = V_23 ;
} else
V_17 = NULL ;
if ( V_17 != V_16 ) {
F_11 ( V_15 , V_17 ) ;
if ( V_17 )
F_12 ( & V_24 ) ;
if ( V_16 ) {
F_13 ( & V_24 ) ;
F_14 () ;
F_15 ( V_16 ) ;
}
}
}
F_7 ( & V_18 ) ;
return V_9 ;
}
static int F_16 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 ,
T_3 * V_6 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_4 V_19 ;
int V_10 , V_29 , V_9 = 0 ;
if ( ! F_17 ( & V_19 , V_30 ) )
return - V_21 ;
if ( V_3 ) {
V_9 = F_18 ( V_4 , * V_5 , V_19 ) ;
if ( V_9 )
goto V_31;
F_3 ( & V_32 ) ;
V_29 = sizeof( * V_26 ) + V_33 ;
F_19 (i) {
V_28 = & F_20 ( V_27 , V_10 ) ;
V_26 = F_4 ( V_28 -> V_34 ,
F_5 ( & V_32 ) ) ;
if ( V_26 && ! F_21 ( V_10 , V_19 ) ) {
F_22 ( V_28 -> V_34 , NULL ) ;
F_14 () ;
F_23 ( V_26 ) ;
} else if ( ! V_26 && F_21 ( V_10 , V_19 ) ) {
V_26 = F_24 ( V_29 , V_30 ,
F_25 ( V_10 ) ) ;
if ( ! V_26 ) {
V_9 = - V_21 ;
goto V_35;
}
V_26 -> V_36 = V_33 ;
F_11 ( V_28 -> V_34 , V_26 ) ;
}
}
V_35:
F_7 ( & V_32 ) ;
} else {
char V_37 [ 128 ] ;
if ( * V_6 || ! * V_5 ) {
* V_5 = 0 ;
goto V_31;
}
F_26 ( V_19 ) ;
F_27 () ;
F_19 (i) {
V_28 = & F_20 ( V_27 , V_10 ) ;
if ( F_28 ( V_28 -> V_34 ) )
F_29 ( V_10 , V_19 ) ;
}
F_30 () ;
V_29 = F_31 ( sizeof( V_37 ) - 1 , * V_5 ) ;
V_29 = F_32 ( V_37 , V_29 , V_19 ) ;
if ( ! V_29 ) {
* V_5 = 0 ;
goto V_31;
}
if ( V_29 < * V_5 )
V_37 [ V_29 ++ ] = '\n' ;
if ( F_33 ( V_4 , V_37 , V_29 ) ) {
V_9 = - V_38 ;
goto V_31;
}
* V_5 = V_29 ;
* V_6 += V_29 ;
}
V_31:
F_34 ( V_19 ) ;
return V_9 ;
}
static int F_35 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 ,
T_3 * V_6 )
{
unsigned int V_39 , * V_40 ;
int V_9 ;
F_3 ( & V_32 ) ;
V_40 = V_2 -> V_12 ;
V_39 = * V_40 ;
V_9 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_9 && V_3 && ! F_36 ( * V_40 ) ) {
* V_40 = V_39 ;
V_9 = - V_20 ;
}
F_7 ( & V_32 ) ;
return V_9 ;
}
static int F_37 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
char V_41 [ V_42 ] ;
struct V_1 V_43 = {
. V_12 = V_41 ,
. V_13 = V_42 ,
} ;
int V_9 ;
F_38 ( V_41 , V_42 ) ;
V_9 = F_39 ( & V_43 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_3 && V_9 == 0 )
V_9 = F_40 ( V_41 ) ;
return V_9 ;
}
static int F_41 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_1 V_44 ;
char V_45 [ V_46 * 3 ] ;
snprintf ( V_45 , sizeof( V_45 ) , L_1 , V_46 , V_47 ) ;
V_44 . V_12 = V_45 ;
V_44 . V_13 = sizeof( V_45 ) ;
return F_39 ( & V_44 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_5 int F_42 ( struct V_48 * V_48 )
{
struct V_1 * V_43 ;
V_48 -> V_49 . V_50 = V_51 ;
V_43 = V_52 ;
if ( ! F_43 ( V_48 , & V_53 ) ) {
V_43 = F_44 ( V_43 , sizeof( V_52 ) , V_30 ) ;
if ( V_43 == NULL )
goto V_54;
V_43 [ 0 ] . V_12 = & V_48 -> V_49 . V_50 ;
if ( V_48 -> V_55 != & V_56 ) {
V_43 [ 0 ] . V_57 = NULL ;
}
}
V_48 -> V_49 . V_58 = F_45 ( V_48 , L_2 , V_43 ) ;
if ( V_48 -> V_49 . V_58 == NULL )
goto V_59;
return 0 ;
V_59:
if ( V_43 != V_52 )
F_23 ( V_43 ) ;
V_54:
return - V_21 ;
}
static T_6 void F_46 ( struct V_48 * V_48 )
{
struct V_1 * V_43 ;
V_43 = V_48 -> V_49 . V_58 -> V_60 ;
F_47 ( V_48 -> V_49 . V_58 ) ;
F_48 ( V_43 == V_52 ) ;
F_23 ( V_43 ) ;
}
static T_7 int F_49 ( void )
{
F_45 ( & V_53 , L_2 , V_61 ) ;
return F_50 ( & V_62 ) ;
}
