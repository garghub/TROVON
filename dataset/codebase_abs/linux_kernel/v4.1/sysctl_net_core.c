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
if ( V_8 > 1 << 29 ) {
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
V_22 = F_8 ( V_23 ) - 1 ;
V_17 -> V_19 = V_8 - 1 ;
} else
V_17 = V_16 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_17 -> V_24 [ V_10 ] = V_25 ;
} else
V_17 = NULL ;
if ( V_17 != V_16 ) {
F_11 ( V_15 , V_17 ) ;
if ( V_17 )
F_12 ( & V_26 ) ;
if ( V_16 ) {
F_13 ( & V_26 ) ;
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
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_4 V_19 ;
int V_10 , V_31 , V_9 = 0 ;
if ( ! F_17 ( & V_19 , V_32 ) )
return - V_21 ;
if ( V_3 ) {
V_9 = F_18 ( V_4 , * V_5 , V_19 ) ;
if ( V_9 )
goto V_33;
F_3 ( & V_34 ) ;
V_31 = sizeof( * V_28 ) + V_35 ;
F_19 (i) {
V_30 = & F_20 ( V_29 , V_10 ) ;
V_28 = F_4 ( V_30 -> V_36 ,
F_5 ( & V_34 ) ) ;
if ( V_28 && ! F_21 ( V_10 , V_19 ) ) {
F_22 ( V_30 -> V_36 , NULL ) ;
F_14 () ;
F_23 ( V_28 ) ;
} else if ( ! V_28 && F_21 ( V_10 , V_19 ) ) {
V_28 = F_24 ( V_31 , V_32 ,
F_25 ( V_10 ) ) ;
if ( ! V_28 ) {
V_9 = - V_21 ;
goto V_37;
}
V_28 -> V_38 = V_35 ;
F_11 ( V_30 -> V_36 , V_28 ) ;
}
}
V_37:
F_7 ( & V_34 ) ;
} else {
char V_39 [ 128 ] ;
if ( * V_6 || ! * V_5 ) {
* V_5 = 0 ;
goto V_33;
}
F_26 ( V_19 ) ;
F_27 () ;
F_19 (i) {
V_30 = & F_20 ( V_29 , V_10 ) ;
if ( F_28 ( V_30 -> V_36 ) )
F_29 ( V_10 , V_19 ) ;
}
F_30 () ;
V_31 = F_31 ( sizeof( V_39 ) - 1 , * V_5 ) ;
V_31 = F_32 ( V_39 , V_31 , L_1 , F_33 ( V_19 ) ) ;
if ( ! V_31 ) {
* V_5 = 0 ;
goto V_33;
}
if ( V_31 < * V_5 )
V_39 [ V_31 ++ ] = '\n' ;
if ( F_34 ( V_4 , V_39 , V_31 ) ) {
V_9 = - V_40 ;
goto V_33;
}
* V_5 = V_31 ;
* V_6 += V_31 ;
}
V_33:
F_35 ( V_19 ) ;
return V_9 ;
}
static int F_36 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 ,
T_3 * V_6 )
{
unsigned int V_41 , * V_42 ;
int V_9 ;
F_3 ( & V_34 ) ;
V_42 = V_2 -> V_12 ;
V_41 = * V_42 ;
V_9 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_9 && V_3 && ! F_37 ( * V_42 ) ) {
* V_42 = V_41 ;
V_9 = - V_20 ;
}
F_7 ( & V_34 ) ;
return V_9 ;
}
static int F_38 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
char V_43 [ V_44 ] ;
struct V_1 V_45 = {
. V_12 = V_43 ,
. V_13 = V_44 ,
} ;
int V_9 ;
F_39 ( V_43 , V_44 ) ;
V_9 = F_40 ( & V_45 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_3 && V_9 == 0 )
V_9 = F_41 ( V_43 ) ;
return V_9 ;
}
static int F_42 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_1 V_46 ;
char V_47 [ V_48 * 3 ] ;
snprintf ( V_47 , sizeof( V_47 ) , L_2 , V_48 , V_49 ) ;
V_46 . V_12 = V_47 ;
V_46 . V_13 = sizeof( V_47 ) ;
return F_40 ( & V_46 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_5 int F_43 ( struct V_50 * V_50 )
{
struct V_1 * V_45 ;
V_50 -> V_51 . V_52 = V_53 ;
V_45 = V_54 ;
if ( ! F_44 ( V_50 , & V_55 ) ) {
V_45 = F_45 ( V_45 , sizeof( V_54 ) , V_32 ) ;
if ( V_45 == NULL )
goto V_56;
V_45 [ 0 ] . V_12 = & V_50 -> V_51 . V_52 ;
if ( V_50 -> V_57 != & V_58 ) {
V_45 [ 0 ] . V_59 = NULL ;
}
}
V_50 -> V_51 . V_60 = F_46 ( V_50 , L_3 , V_45 ) ;
if ( V_50 -> V_51 . V_60 == NULL )
goto V_61;
return 0 ;
V_61:
if ( V_45 != V_54 )
F_23 ( V_45 ) ;
V_56:
return - V_21 ;
}
static T_6 void F_47 ( struct V_50 * V_50 )
{
struct V_1 * V_45 ;
V_45 = V_50 -> V_51 . V_60 -> V_62 ;
F_48 ( V_50 -> V_51 . V_60 ) ;
F_49 ( V_45 == V_54 ) ;
F_23 ( V_45 ) ;
}
static T_7 int F_50 ( void )
{
F_46 ( & V_55 , L_3 , V_63 ) ;
return F_51 ( & V_64 ) ;
}
