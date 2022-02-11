static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
int V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
V_7 = F_2 ( V_5 ) ;
V_8 = F_2 ( V_6 ) ;
V_9 = F_3 ( V_3 + V_13 , V_14 ) ;
if ( V_7 < V_3 ) {
do {
V_8 = F_2 ( V_6 ) ;
V_7 = F_2 ( V_5 ) ;
V_10 = F_3 ( V_9 , V_7 + V_15 ) ;
if ( V_10 + V_16 >= V_14 ) {
V_10 = V_14 ;
V_12 = F_4 ( V_6 , V_10 ,
V_10 ) ;
if ( V_12 )
V_12 = F_4 ( V_6 ,
V_10 - V_16 ,
V_10 ) ;
V_11 = V_3 ;
} else {
V_12 = F_4 ( V_6 , V_10 ,
V_10 + V_16 ) ;
V_11 = V_10 - V_13 ;
}
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_5 , V_11 ,
V_11 + V_16 ) ;
if ( V_12 ) {
F_4 ( V_6 , V_8 ,
V_8 ) ;
return V_12 ;
}
} while ( V_11 < V_3 || V_10 < V_9 );
} else if ( V_7 > V_3 ) {
do {
V_7 = F_2 ( V_5 ) ;
V_8 = F_2 ( V_6 ) ;
V_11 = F_5 ( V_3 , V_8 - V_15 ) ;
V_12 = F_4 ( V_5 , V_11 ,
V_11 + V_16 ) ;
if ( V_12 )
return V_12 ;
if ( V_11 == V_3 )
V_10 = V_9 ;
else
V_10 = F_5 ( V_9 , V_11 + V_13 ) ;
if ( V_10 + V_16 >= V_14 ) {
V_10 = V_14 ;
V_12 = F_4 ( V_6 , V_10 ,
V_10 ) ;
if ( V_12 )
V_12 = F_4 ( V_6 ,
V_10 - V_16 ,
V_10 ) ;
} else {
V_12 = F_4 ( V_6 , V_10 ,
V_10 + V_16 ) ;
}
if ( V_12 ) {
F_4 ( V_5 , V_7 ,
V_7 ) ;
return V_12 ;
}
} while ( V_11 > V_3 + V_16 ||
V_10 > V_9 + V_16 );
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_11 )
{
if ( V_2 -> V_17 )
return F_1 ( V_2 , V_11 ) ;
else
return F_4 ( V_2 -> V_5 , V_11 ,
V_11 + V_16 ) ;
}
static int F_7 ( struct V_18 * V_19 ,
unsigned int V_20 )
{
struct V_21 * V_22 = V_19 -> V_22 ;
struct V_23 * V_24 = V_19 -> V_23 ;
struct V_23 * V_25 = F_8 ( V_24 ) ;
struct V_1 * V_2 = V_19 -> V_26 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_29 * V_30 ;
long V_31 , V_32 ;
int V_11 , V_7 , V_33 , V_34 , V_12 ;
V_33 = V_2 -> V_35 ;
V_32 = F_9 ( V_24 ) ;
V_7 = F_2 ( V_2 -> V_5 ) ;
V_31 = V_22 [ V_20 ] . V_36 * 1000 ;
F_10 () ;
V_30 = F_11 ( V_28 , & V_31 ) ;
if ( F_12 ( V_30 ) ) {
F_13 () ;
F_14 ( L_1 ,
V_19 -> V_37 , V_31 ) ;
return F_15 ( V_30 ) ;
}
V_11 = F_16 ( V_30 ) ;
F_13 () ;
V_34 = ( V_33 > V_11 ) ? V_33 : V_11 ;
if ( V_7 < V_34 ) {
V_12 = F_6 ( V_2 , V_34 ) ;
if ( V_12 ) {
F_14 ( L_2 ,
V_19 -> V_37 ) ;
F_6 ( V_2 , V_7 ) ;
return V_12 ;
}
}
V_12 = F_17 ( V_24 , V_2 -> V_38 ) ;
if ( V_12 ) {
F_14 ( L_3 ,
V_19 -> V_37 ) ;
F_6 ( V_2 , V_7 ) ;
F_18 ( 1 ) ;
return V_12 ;
}
V_12 = F_19 ( V_25 , V_31 ) ;
if ( V_12 ) {
F_14 ( L_4 ,
V_19 -> V_37 ) ;
F_17 ( V_24 , V_25 ) ;
F_6 ( V_2 , V_7 ) ;
return V_12 ;
}
V_12 = F_17 ( V_24 , V_25 ) ;
if ( V_12 ) {
F_14 ( L_3 ,
V_19 -> V_37 ) ;
F_6 ( V_2 , V_33 ) ;
F_18 ( 1 ) ;
return V_12 ;
}
if ( V_11 < V_33 || V_11 < V_7 ) {
V_12 = F_6 ( V_2 , V_11 ) ;
if ( V_12 ) {
F_14 ( L_5 ,
V_19 -> V_37 ) ;
F_17 ( V_24 , V_2 -> V_38 ) ;
F_19 ( V_25 , V_32 ) ;
F_17 ( V_24 , V_25 ) ;
return V_12 ;
}
}
return 0 ;
}
static void F_20 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_26 ;
struct V_39 * V_40 = F_21 ( V_2 -> V_28 -> V_41 ) ;
if ( F_18 ( ! V_40 ) )
return;
if ( F_22 ( V_40 , L_6 , NULL ) ) {
V_2 -> V_42 = F_23 ( V_40 ,
V_19 -> V_43 ) ;
if ( F_12 ( V_2 -> V_42 ) ) {
F_24 ( V_2 -> V_28 ,
L_7 ,
F_15 ( V_2 -> V_42 ) ) ;
V_2 -> V_42 = NULL ;
}
}
F_25 ( V_40 ) ;
}
static int F_26 ( struct V_1 * V_2 , int V_37 )
{
struct V_27 * V_28 ;
struct V_4 * V_5 = F_27 ( - V_44 ) ;
struct V_4 * V_6 = F_27 ( - V_44 ) ;
struct V_23 * V_24 = F_27 ( - V_44 ) ;
struct V_23 * V_38 = F_27 ( - V_44 ) ;
struct V_29 * V_30 ;
unsigned long V_45 ;
int V_12 ;
V_28 = F_28 ( V_37 ) ;
if ( ! V_28 ) {
F_14 ( L_8 , V_37 ) ;
return - V_44 ;
}
V_24 = F_29 ( V_28 , L_9 ) ;
if ( F_12 ( V_24 ) ) {
if ( F_15 ( V_24 ) == - V_46 )
F_30 ( L_10 , V_37 ) ;
else
F_14 ( L_11 , V_37 ) ;
V_12 = F_15 ( V_24 ) ;
return V_12 ;
}
V_38 = F_29 ( V_28 , L_12 ) ;
if ( F_12 ( V_38 ) ) {
if ( F_15 ( V_38 ) == - V_46 )
F_30 ( L_13 ,
V_37 ) ;
else
F_14 ( L_14 ,
V_37 ) ;
V_12 = F_15 ( V_38 ) ;
goto V_47;
}
V_5 = F_31 ( V_28 , L_15 ) ;
if ( F_12 ( V_5 ) ) {
if ( F_15 ( V_5 ) == - V_46 )
F_30 ( L_16 ,
V_37 ) ;
else
F_14 ( L_17 ,
V_37 ) ;
V_12 = F_15 ( V_5 ) ;
goto V_47;
}
V_6 = F_31 ( V_28 , L_18 ) ;
V_12 = F_32 ( V_28 ) ;
if ( V_12 ) {
F_30 ( L_19 , V_37 ) ;
goto V_47;
}
V_45 = F_9 ( V_38 ) ;
F_10 () ;
V_30 = F_11 ( V_28 , & V_45 ) ;
if ( F_12 ( V_30 ) ) {
F_13 () ;
F_14 ( L_20 , V_37 ) ;
V_12 = F_15 ( V_30 ) ;
goto V_48;
}
V_2 -> V_35 = F_16 ( V_30 ) ;
F_13 () ;
V_2 -> V_28 = V_28 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = F_12 ( V_6 ) ? NULL : V_6 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_17 = ! F_12 ( V_6 ) ;
return 0 ;
V_48:
F_33 ( V_28 ) ;
V_47:
if ( ! F_12 ( V_5 ) )
F_34 ( V_5 ) ;
if ( ! F_12 ( V_6 ) )
F_34 ( V_6 ) ;
if ( ! F_12 ( V_24 ) )
F_35 ( V_24 ) ;
if ( ! F_12 ( V_38 ) )
F_35 ( V_38 ) ;
return V_12 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_2 -> V_5 ) )
F_34 ( V_2 -> V_5 ) ;
if ( ! F_12 ( V_2 -> V_6 ) )
F_34 ( V_2 -> V_6 ) ;
if ( ! F_12 ( V_2 -> V_24 ) )
F_35 ( V_2 -> V_24 ) ;
if ( ! F_12 ( V_2 -> V_38 ) )
F_35 ( V_2 -> V_38 ) ;
F_33 ( V_2 -> V_28 ) ;
}
static int F_37 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_12 ;
V_2 = F_38 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return - V_50 ;
V_12 = F_26 ( V_2 , V_19 -> V_37 ) ;
if ( V_12 ) {
F_14 ( L_21 ,
V_51 , V_19 -> V_37 ) ;
goto V_52;
}
V_12 = F_39 ( V_2 -> V_28 , & V_22 ) ;
if ( V_12 ) {
F_14 ( L_22 ,
V_19 -> V_37 , V_12 ) ;
goto V_53;
}
V_12 = F_40 ( V_19 , V_22 ) ;
if ( V_12 ) {
F_14 ( L_23 , V_51 , V_12 ) ;
goto V_54;
}
F_41 ( V_19 -> V_55 , & V_56 [ V_19 -> V_37 ] . V_57 ) ;
V_19 -> V_26 = V_2 ;
V_19 -> V_23 = V_2 -> V_24 ;
return 0 ;
V_54:
F_42 ( V_2 -> V_28 , & V_22 ) ;
V_53:
F_36 ( V_2 ) ;
V_52:
F_43 ( V_2 ) ;
return V_12 ;
}
static int F_44 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_26 ;
F_45 ( V_2 -> V_42 ) ;
F_42 ( V_2 -> V_28 , & V_19 -> V_22 ) ;
F_36 ( V_2 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_58 * V_59 )
{
int V_12 ;
V_12 = F_47 ( & V_60 ) ;
if ( V_12 )
F_14 ( L_24 ) ;
return V_12 ;
}
static int F_48 ( void )
{
struct V_58 * V_59 ;
int V_61 ;
if ( ! F_49 ( L_25 ) )
return - V_44 ;
V_61 = F_50 ( & V_62 ) ;
if ( V_61 )
return V_61 ;
V_59 = F_51 ( L_26 , - 1 , NULL , 0 ) ;
if ( F_12 ( V_59 ) ) {
F_14 ( L_27 ) ;
return F_15 ( V_59 ) ;
}
return 0 ;
}
