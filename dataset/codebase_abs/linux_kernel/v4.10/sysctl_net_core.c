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
if ( V_17 ) {
F_12 ( & V_26 ) ;
F_12 ( & V_27 ) ;
}
if ( V_16 ) {
F_13 ( & V_26 ) ;
F_13 ( & V_27 ) ;
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
struct V_28 * V_29 ;
struct V_30 * V_31 ;
T_4 V_19 ;
int V_10 , V_32 , V_9 = 0 ;
if ( ! F_17 ( & V_19 , V_33 ) )
return - V_21 ;
if ( V_3 ) {
V_9 = F_18 ( V_4 , * V_5 , V_19 ) ;
if ( V_9 )
goto V_34;
F_3 ( & V_35 ) ;
V_32 = sizeof( * V_29 ) + V_36 ;
F_19 (i) {
V_31 = & F_20 ( V_30 , V_10 ) ;
V_29 = F_4 ( V_31 -> V_37 ,
F_5 ( & V_35 ) ) ;
if ( V_29 && ! F_21 ( V_10 , V_19 ) ) {
F_22 ( V_31 -> V_37 , NULL ) ;
F_14 () ;
F_23 ( V_29 ) ;
} else if ( ! V_29 && F_21 ( V_10 , V_19 ) ) {
V_29 = F_24 ( V_32 , V_33 ,
F_25 ( V_10 ) ) ;
if ( ! V_29 ) {
V_9 = - V_21 ;
goto V_38;
}
V_29 -> V_39 = V_36 ;
F_11 ( V_31 -> V_37 , V_29 ) ;
}
}
V_38:
F_7 ( & V_35 ) ;
} else {
char V_40 [ 128 ] ;
if ( * V_6 || ! * V_5 ) {
* V_5 = 0 ;
goto V_34;
}
F_26 ( V_19 ) ;
F_27 () ;
F_19 (i) {
V_31 = & F_20 ( V_30 , V_10 ) ;
if ( F_28 ( V_31 -> V_37 ) )
F_29 ( V_10 , V_19 ) ;
}
F_30 () ;
V_32 = F_31 ( sizeof( V_40 ) - 1 , * V_5 ) ;
V_32 = F_32 ( V_40 , V_32 , L_1 , F_33 ( V_19 ) ) ;
if ( ! V_32 ) {
* V_5 = 0 ;
goto V_34;
}
if ( V_32 < * V_5 )
V_40 [ V_32 ++ ] = '\n' ;
if ( F_34 ( V_4 , V_40 , V_32 ) ) {
V_9 = - V_41 ;
goto V_34;
}
* V_5 = V_32 ;
* V_6 += V_32 ;
}
V_34:
F_35 ( V_19 ) ;
return V_9 ;
}
static int F_36 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 ,
T_3 * V_6 )
{
unsigned int V_42 , * V_43 ;
int V_9 ;
F_3 ( & V_35 ) ;
V_43 = V_2 -> V_12 ;
V_42 = * V_43 ;
V_9 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_9 && V_3 && ! F_37 ( * V_43 ) ) {
* V_43 = V_42 ;
V_9 = - V_20 ;
}
F_7 ( & V_35 ) ;
return V_9 ;
}
static int F_38 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
char V_44 [ V_45 ] ;
struct V_1 V_46 = {
. V_12 = V_44 ,
. V_13 = V_45 ,
} ;
int V_9 ;
F_39 ( V_44 , V_45 ) ;
V_9 = F_40 ( & V_46 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_3 && V_9 == 0 )
V_9 = F_41 ( V_44 ) ;
return V_9 ;
}
static int F_42 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_1 V_47 ;
char V_48 [ V_49 * 3 ] ;
snprintf ( V_48 , sizeof( V_48 ) , L_2 , V_49 , V_50 ) ;
V_47 . V_12 = V_48 ;
V_47 . V_13 = sizeof( V_48 ) ;
return F_40 ( & V_47 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_5 int F_43 ( struct V_51 * V_51 )
{
struct V_1 * V_46 ;
V_51 -> V_52 . V_53 = V_54 ;
V_46 = V_55 ;
if ( ! F_44 ( V_51 , & V_56 ) ) {
V_46 = F_45 ( V_46 , sizeof( V_55 ) , V_33 ) ;
if ( V_46 == NULL )
goto V_57;
V_46 [ 0 ] . V_12 = & V_51 -> V_52 . V_53 ;
if ( V_51 -> V_58 != & V_59 ) {
V_46 [ 0 ] . V_60 = NULL ;
}
}
V_51 -> V_52 . V_61 = F_46 ( V_51 , L_3 , V_46 ) ;
if ( V_51 -> V_52 . V_61 == NULL )
goto V_62;
return 0 ;
V_62:
if ( V_46 != V_55 )
F_23 ( V_46 ) ;
V_57:
return - V_21 ;
}
static T_6 void F_47 ( struct V_51 * V_51 )
{
struct V_1 * V_46 ;
V_46 = V_51 -> V_52 . V_61 -> V_63 ;
F_48 ( V_51 -> V_52 . V_61 ) ;
F_49 ( V_46 == V_55 ) ;
F_23 ( V_46 ) ;
}
static T_7 int F_50 ( void )
{
F_46 ( & V_56 , L_3 , V_64 ) ;
return F_51 ( & V_65 ) ;
}
