static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
F_2 (list, &dvfs_info_list) {
V_3 = F_3 ( V_5 , struct V_1 , V_4 ) ;
if ( F_4 ( V_2 , & V_3 -> V_6 ) )
return V_3 ;
}
return NULL ;
}
static int F_5 ( struct V_1 * V_3 ,
int V_7 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_8 * V_10 = V_3 -> V_10 ;
int V_11 , V_12 , V_13 , V_14 , V_15 , V_16 ;
V_11 = F_6 ( V_9 ) ;
if ( V_11 < 0 ) {
F_7 ( L_1 , V_17 , V_11 ) ;
return V_11 ;
}
V_13 = F_8 ( V_7 + V_18 , V_19 ) ;
if ( V_11 < V_7 ) {
do {
V_12 = F_6 ( V_10 ) ;
if ( V_12 < 0 ) {
F_7 ( L_2 ,
V_17 , V_12 ) ;
return V_12 ;
}
V_11 = F_6 ( V_9 ) ;
if ( V_11 < 0 ) {
F_7 ( L_1 ,
V_17 , V_11 ) ;
return V_11 ;
}
V_14 = F_8 ( V_13 , V_11 + V_20 ) ;
if ( V_14 + V_21 >= V_19 ) {
V_14 = V_19 ;
V_16 = F_9 ( V_10 , V_14 ,
V_14 ) ;
if ( V_16 )
V_16 = F_9 ( V_10 ,
V_14 - V_21 ,
V_14 ) ;
V_15 = V_7 ;
} else {
V_16 = F_9 ( V_10 , V_14 ,
V_14 + V_21 ) ;
V_15 = V_14 - V_18 ;
}
if ( V_16 )
return V_16 ;
V_16 = F_9 ( V_9 , V_15 ,
V_15 + V_21 ) ;
if ( V_16 ) {
F_9 ( V_10 , V_12 ,
V_12 ) ;
return V_16 ;
}
} while ( V_15 < V_7 || V_14 < V_13 );
} else if ( V_11 > V_7 ) {
do {
V_11 = F_6 ( V_9 ) ;
if ( V_11 < 0 ) {
F_7 ( L_1 ,
V_17 , V_11 ) ;
return V_11 ;
}
V_12 = F_6 ( V_10 ) ;
if ( V_12 < 0 ) {
F_7 ( L_2 ,
V_17 , V_12 ) ;
return V_12 ;
}
V_15 = F_10 ( V_7 , V_12 - V_20 ) ;
V_16 = F_9 ( V_9 , V_15 ,
V_15 + V_21 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 == V_7 )
V_14 = V_13 ;
else
V_14 = F_10 ( V_13 , V_15 + V_18 ) ;
if ( V_14 + V_21 >= V_19 ) {
V_14 = V_19 ;
V_16 = F_9 ( V_10 , V_14 ,
V_14 ) ;
if ( V_16 )
V_16 = F_9 ( V_10 ,
V_14 - V_21 ,
V_14 ) ;
} else {
V_16 = F_9 ( V_10 , V_14 ,
V_14 + V_21 ) ;
}
if ( V_16 ) {
F_9 ( V_9 , V_11 ,
V_11 ) ;
return V_16 ;
}
} while ( V_15 > V_7 + V_21 ||
V_14 > V_13 + V_21 );
}
return 0 ;
}
static int F_11 ( struct V_1 * V_3 , int V_15 )
{
if ( V_3 -> V_22 )
return F_5 ( V_3 , V_15 ) ;
else
return F_9 ( V_3 -> V_9 , V_15 ,
V_15 + V_21 ) ;
}
static int F_12 ( struct V_23 * V_24 ,
unsigned int V_25 )
{
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_28 * V_29 = V_24 -> V_28 ;
struct V_28 * V_30 = F_13 ( V_29 ) ;
struct V_1 * V_3 = V_24 -> V_31 ;
struct V_32 * V_33 = V_3 -> V_33 ;
struct V_34 * V_35 ;
long V_36 , V_37 ;
int V_15 , V_11 , V_38 , V_39 , V_16 ;
V_38 = V_3 -> V_40 ;
V_37 = F_14 ( V_29 ) ;
V_11 = F_6 ( V_3 -> V_9 ) ;
if ( V_11 < 0 ) {
F_7 ( L_1 , V_17 , V_11 ) ;
return V_11 ;
}
V_36 = V_27 [ V_25 ] . V_41 * 1000 ;
F_15 () ;
V_35 = F_16 ( V_33 , & V_36 ) ;
if ( F_17 ( V_35 ) ) {
F_18 () ;
F_7 ( L_3 ,
V_24 -> V_2 , V_36 ) ;
return F_19 ( V_35 ) ;
}
V_15 = F_20 ( V_35 ) ;
F_18 () ;
V_39 = ( V_38 > V_15 ) ? V_38 : V_15 ;
if ( V_11 < V_39 ) {
V_16 = F_11 ( V_3 , V_39 ) ;
if ( V_16 ) {
F_7 ( L_4 ,
V_24 -> V_2 ) ;
F_11 ( V_3 , V_11 ) ;
return V_16 ;
}
}
V_16 = F_21 ( V_29 , V_3 -> V_42 ) ;
if ( V_16 ) {
F_7 ( L_5 ,
V_24 -> V_2 ) ;
F_11 ( V_3 , V_11 ) ;
F_22 ( 1 ) ;
return V_16 ;
}
V_16 = F_23 ( V_30 , V_36 ) ;
if ( V_16 ) {
F_7 ( L_6 ,
V_24 -> V_2 ) ;
F_21 ( V_29 , V_30 ) ;
F_11 ( V_3 , V_11 ) ;
return V_16 ;
}
V_16 = F_21 ( V_29 , V_30 ) ;
if ( V_16 ) {
F_7 ( L_5 ,
V_24 -> V_2 ) ;
F_11 ( V_3 , V_38 ) ;
F_22 ( 1 ) ;
return V_16 ;
}
if ( V_15 < V_38 || V_15 < V_11 ) {
V_16 = F_11 ( V_3 , V_15 ) ;
if ( V_16 ) {
F_7 ( L_7 ,
V_24 -> V_2 ) ;
F_21 ( V_29 , V_3 -> V_42 ) ;
F_23 ( V_30 , V_37 ) ;
F_21 ( V_29 , V_30 ) ;
return V_16 ;
}
}
return 0 ;
}
static void F_24 ( struct V_23 * V_24 )
{
struct V_1 * V_3 = V_24 -> V_31 ;
struct V_43 * V_44 = F_25 ( V_3 -> V_33 -> V_45 ) ;
if ( F_22 ( ! V_44 ) )
return;
if ( F_26 ( V_44 , L_8 , NULL ) ) {
V_3 -> V_46 = F_27 ( V_44 ,
V_24 -> V_47 ) ;
if ( F_17 ( V_3 -> V_46 ) ) {
F_28 ( V_3 -> V_33 ,
L_9 ,
F_19 ( V_3 -> V_46 ) ) ;
V_3 -> V_46 = NULL ;
}
}
F_29 ( V_44 ) ;
}
static int F_30 ( struct V_1 * V_3 , int V_2 )
{
struct V_32 * V_33 ;
struct V_8 * V_9 = F_31 ( - V_48 ) ;
struct V_8 * V_10 = F_31 ( - V_48 ) ;
struct V_28 * V_29 = F_31 ( - V_48 ) ;
struct V_28 * V_42 = F_31 ( - V_48 ) ;
struct V_34 * V_35 ;
unsigned long V_49 ;
int V_16 ;
V_33 = F_32 ( V_2 ) ;
if ( ! V_33 ) {
F_7 ( L_10 , V_2 ) ;
return - V_48 ;
}
V_29 = F_33 ( V_33 , L_11 ) ;
if ( F_17 ( V_29 ) ) {
if ( F_19 ( V_29 ) == - V_50 )
F_34 ( L_12 , V_2 ) ;
else
F_7 ( L_13 , V_2 ) ;
V_16 = F_19 ( V_29 ) ;
return V_16 ;
}
V_42 = F_33 ( V_33 , L_14 ) ;
if ( F_17 ( V_42 ) ) {
if ( F_19 ( V_42 ) == - V_50 )
F_34 ( L_15 ,
V_2 ) ;
else
F_7 ( L_16 ,
V_2 ) ;
V_16 = F_19 ( V_42 ) ;
goto V_51;
}
V_9 = F_35 ( V_33 , L_17 ) ;
if ( F_17 ( V_9 ) ) {
if ( F_19 ( V_9 ) == - V_50 )
F_34 ( L_18 ,
V_2 ) ;
else
F_7 ( L_19 ,
V_2 ) ;
V_16 = F_19 ( V_9 ) ;
goto V_51;
}
V_10 = F_35 ( V_33 , L_20 ) ;
V_16 = F_36 ( V_33 , & V_3 -> V_6 ) ;
if ( V_16 ) {
F_7 ( L_21 ,
V_2 ) ;
goto V_51;
}
V_16 = F_37 ( & V_3 -> V_6 ) ;
if ( V_16 ) {
F_34 ( L_22 , V_2 ) ;
goto V_51;
}
V_49 = F_14 ( V_42 ) ;
F_15 () ;
V_35 = F_16 ( V_33 , & V_49 ) ;
if ( F_17 ( V_35 ) ) {
F_18 () ;
F_7 ( L_23 , V_2 ) ;
V_16 = F_19 ( V_35 ) ;
goto V_52;
}
V_3 -> V_40 = F_20 ( V_35 ) ;
F_18 () ;
V_3 -> V_33 = V_33 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_10 = F_17 ( V_10 ) ? NULL : V_10 ;
V_3 -> V_29 = V_29 ;
V_3 -> V_42 = V_42 ;
V_3 -> V_22 = ! F_17 ( V_10 ) ;
return 0 ;
V_52:
F_38 ( & V_3 -> V_6 ) ;
V_51:
if ( ! F_17 ( V_9 ) )
F_39 ( V_9 ) ;
if ( ! F_17 ( V_10 ) )
F_39 ( V_10 ) ;
if ( ! F_17 ( V_29 ) )
F_40 ( V_29 ) ;
if ( ! F_17 ( V_42 ) )
F_40 ( V_42 ) ;
return V_16 ;
}
static void F_41 ( struct V_1 * V_3 )
{
if ( ! F_17 ( V_3 -> V_9 ) )
F_39 ( V_3 -> V_9 ) ;
if ( ! F_17 ( V_3 -> V_10 ) )
F_39 ( V_3 -> V_10 ) ;
if ( ! F_17 ( V_3 -> V_29 ) )
F_40 ( V_3 -> V_29 ) ;
if ( ! F_17 ( V_3 -> V_42 ) )
F_40 ( V_3 -> V_42 ) ;
F_38 ( & V_3 -> V_6 ) ;
}
static int F_42 ( struct V_23 * V_24 )
{
struct V_1 * V_3 ;
struct V_26 * V_27 ;
int V_16 ;
V_3 = F_1 ( V_24 -> V_2 ) ;
if ( ! V_3 ) {
F_7 ( L_24 ,
V_24 -> V_2 ) ;
return - V_53 ;
}
V_16 = F_43 ( V_3 -> V_33 , & V_27 ) ;
if ( V_16 ) {
F_7 ( L_25 ,
V_24 -> V_2 , V_16 ) ;
return V_16 ;
}
V_16 = F_44 ( V_24 , V_27 ) ;
if ( V_16 ) {
F_7 ( L_26 , V_17 , V_16 ) ;
goto V_54;
}
F_45 ( V_24 -> V_6 , & V_3 -> V_6 ) ;
V_24 -> V_31 = V_3 ;
V_24 -> V_28 = V_3 -> V_29 ;
return 0 ;
V_54:
F_46 ( V_3 -> V_33 , & V_27 ) ;
return V_16 ;
}
static int F_47 ( struct V_23 * V_24 )
{
struct V_1 * V_3 = V_24 -> V_31 ;
F_48 ( V_3 -> V_46 ) ;
F_46 ( V_3 -> V_33 , & V_24 -> V_27 ) ;
return 0 ;
}
static int F_49 ( struct V_55 * V_56 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 , * V_57 ;
int V_2 , V_16 ;
F_50 (cpu) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
continue;
V_3 = F_51 ( & V_56 -> V_58 , sizeof( * V_3 ) , V_59 ) ;
if ( ! V_3 ) {
V_16 = - V_60 ;
goto V_61;
}
V_16 = F_30 ( V_3 , V_2 ) ;
if ( V_16 ) {
F_28 ( & V_56 -> V_58 ,
L_27 ,
V_2 ) ;
goto V_61;
}
F_52 ( & V_3 -> V_4 , & V_62 ) ;
}
V_16 = F_53 ( & V_63 ) ;
if ( V_16 ) {
F_28 ( & V_56 -> V_58 , L_28 ) ;
goto V_61;
}
return 0 ;
V_61:
F_54 (list, tmp, &dvfs_info_list) {
V_3 = F_3 ( V_5 , struct V_1 , V_4 ) ;
F_41 ( V_3 ) ;
F_55 ( V_5 ) ;
}
return V_16 ;
}
static int F_56 ( void )
{
struct V_55 * V_56 ;
int V_64 ;
if ( ! F_57 ( L_29 ) )
return - V_48 ;
V_64 = F_58 ( & V_65 ) ;
if ( V_64 )
return V_64 ;
V_56 = F_59 ( L_30 , - 1 , NULL , 0 ) ;
if ( F_17 ( V_56 ) ) {
F_7 ( L_31 ) ;
return F_19 ( V_56 ) ;
}
return 0 ;
}
