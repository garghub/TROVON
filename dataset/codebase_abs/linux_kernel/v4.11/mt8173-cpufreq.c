static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
F_2 (info, &dvfs_info_list, list_head) {
if ( F_3 ( V_2 , & V_3 -> V_4 ) )
return V_3 ;
}
return NULL ;
}
static int F_4 ( struct V_1 * V_3 ,
int V_5 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_6 * V_8 = V_3 -> V_8 ;
int V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ;
V_9 = F_5 ( V_7 ) ;
if ( V_9 < 0 ) {
F_6 ( L_1 , V_15 , V_9 ) ;
return V_9 ;
}
V_11 = F_7 ( V_5 + V_16 , V_17 ) ;
if ( V_9 < V_5 ) {
do {
V_10 = F_5 ( V_8 ) ;
if ( V_10 < 0 ) {
F_6 ( L_2 ,
V_15 , V_10 ) ;
return V_10 ;
}
V_9 = F_5 ( V_7 ) ;
if ( V_9 < 0 ) {
F_6 ( L_1 ,
V_15 , V_9 ) ;
return V_9 ;
}
V_12 = F_7 ( V_11 , V_9 + V_18 ) ;
if ( V_12 + V_19 >= V_17 ) {
V_12 = V_17 ;
V_14 = F_8 ( V_8 , V_12 ,
V_12 ) ;
if ( V_14 )
V_14 = F_8 ( V_8 ,
V_12 - V_19 ,
V_12 ) ;
V_13 = V_5 ;
} else {
V_14 = F_8 ( V_8 , V_12 ,
V_12 + V_19 ) ;
V_13 = V_12 - V_16 ;
}
if ( V_14 )
return V_14 ;
V_14 = F_8 ( V_7 , V_13 ,
V_13 + V_19 ) ;
if ( V_14 ) {
F_8 ( V_8 , V_10 ,
V_10 ) ;
return V_14 ;
}
} while ( V_13 < V_5 || V_12 < V_11 );
} else if ( V_9 > V_5 ) {
do {
V_9 = F_5 ( V_7 ) ;
if ( V_9 < 0 ) {
F_6 ( L_1 ,
V_15 , V_9 ) ;
return V_9 ;
}
V_10 = F_5 ( V_8 ) ;
if ( V_10 < 0 ) {
F_6 ( L_2 ,
V_15 , V_10 ) ;
return V_10 ;
}
V_13 = F_9 ( V_5 , V_10 - V_18 ) ;
V_14 = F_8 ( V_7 , V_13 ,
V_13 + V_19 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 == V_5 )
V_12 = V_11 ;
else
V_12 = F_9 ( V_11 , V_13 + V_16 ) ;
if ( V_12 + V_19 >= V_17 ) {
V_12 = V_17 ;
V_14 = F_8 ( V_8 , V_12 ,
V_12 ) ;
if ( V_14 )
V_14 = F_8 ( V_8 ,
V_12 - V_19 ,
V_12 ) ;
} else {
V_14 = F_8 ( V_8 , V_12 ,
V_12 + V_19 ) ;
}
if ( V_14 ) {
F_8 ( V_7 , V_9 ,
V_9 ) ;
return V_14 ;
}
} while ( V_13 > V_5 + V_19 ||
V_12 > V_11 + V_19 );
}
return 0 ;
}
static int F_10 ( struct V_1 * V_3 , int V_13 )
{
if ( V_3 -> V_20 )
return F_4 ( V_3 , V_13 ) ;
else
return F_8 ( V_3 -> V_7 , V_13 ,
V_13 + V_19 ) ;
}
static int F_11 ( struct V_21 * V_22 ,
unsigned int V_23 )
{
struct V_24 * V_25 = V_22 -> V_25 ;
struct V_26 * V_27 = V_22 -> V_26 ;
struct V_26 * V_28 = F_12 ( V_27 ) ;
struct V_1 * V_3 = V_22 -> V_29 ;
struct V_30 * V_31 = V_3 -> V_31 ;
struct V_32 * V_33 ;
long V_34 , V_35 ;
int V_13 , V_9 , V_36 , V_37 , V_14 ;
V_36 = V_3 -> V_38 ;
V_35 = F_13 ( V_27 ) ;
V_9 = F_5 ( V_3 -> V_7 ) ;
if ( V_9 < 0 ) {
F_6 ( L_1 , V_15 , V_9 ) ;
return V_9 ;
}
V_34 = V_25 [ V_23 ] . V_39 * 1000 ;
V_33 = F_14 ( V_31 , & V_34 ) ;
if ( F_15 ( V_33 ) ) {
F_6 ( L_3 ,
V_22 -> V_2 , V_34 ) ;
return F_16 ( V_33 ) ;
}
V_13 = F_17 ( V_33 ) ;
F_18 ( V_33 ) ;
V_37 = ( V_36 > V_13 ) ? V_36 : V_13 ;
if ( V_9 < V_37 ) {
V_14 = F_10 ( V_3 , V_37 ) ;
if ( V_14 ) {
F_6 ( L_4 ,
V_22 -> V_2 ) ;
F_10 ( V_3 , V_9 ) ;
return V_14 ;
}
}
V_14 = F_19 ( V_27 , V_3 -> V_40 ) ;
if ( V_14 ) {
F_6 ( L_5 ,
V_22 -> V_2 ) ;
F_10 ( V_3 , V_9 ) ;
F_20 ( 1 ) ;
return V_14 ;
}
V_14 = F_21 ( V_28 , V_34 ) ;
if ( V_14 ) {
F_6 ( L_6 ,
V_22 -> V_2 ) ;
F_19 ( V_27 , V_28 ) ;
F_10 ( V_3 , V_9 ) ;
return V_14 ;
}
V_14 = F_19 ( V_27 , V_28 ) ;
if ( V_14 ) {
F_6 ( L_5 ,
V_22 -> V_2 ) ;
F_10 ( V_3 , V_36 ) ;
F_20 ( 1 ) ;
return V_14 ;
}
if ( V_13 < V_36 || V_13 < V_9 ) {
V_14 = F_10 ( V_3 , V_13 ) ;
if ( V_14 ) {
F_6 ( L_7 ,
V_22 -> V_2 ) ;
F_19 ( V_27 , V_3 -> V_40 ) ;
F_21 ( V_28 , V_35 ) ;
F_19 ( V_27 , V_28 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_22 ( struct V_21 * V_22 )
{
struct V_1 * V_3 = V_22 -> V_29 ;
struct V_41 * V_42 = F_23 ( V_3 -> V_31 -> V_43 ) ;
T_1 V_44 = 0 ;
if ( F_20 ( ! V_42 ) )
return;
if ( F_24 ( V_42 , L_8 , NULL ) ) {
F_25 ( V_42 , V_45 , & V_44 ) ;
V_3 -> V_46 = F_26 ( V_42 ,
V_22 -> V_47 ,
V_44 ,
NULL ) ;
if ( F_15 ( V_3 -> V_46 ) ) {
F_27 ( V_3 -> V_31 ,
L_9 ,
F_16 ( V_3 -> V_46 ) ) ;
V_3 -> V_46 = NULL ;
}
}
F_28 ( V_42 ) ;
}
static int F_29 ( struct V_1 * V_3 , int V_2 )
{
struct V_30 * V_31 ;
struct V_6 * V_7 = F_30 ( - V_48 ) ;
struct V_6 * V_8 = F_30 ( - V_48 ) ;
struct V_26 * V_27 = F_30 ( - V_48 ) ;
struct V_26 * V_40 = F_30 ( - V_48 ) ;
struct V_32 * V_33 ;
unsigned long V_49 ;
int V_14 ;
V_31 = F_31 ( V_2 ) ;
if ( ! V_31 ) {
F_6 ( L_10 , V_2 ) ;
return - V_48 ;
}
V_27 = F_32 ( V_31 , L_11 ) ;
if ( F_15 ( V_27 ) ) {
if ( F_16 ( V_27 ) == - V_50 )
F_33 ( L_12 , V_2 ) ;
else
F_6 ( L_13 , V_2 ) ;
V_14 = F_16 ( V_27 ) ;
return V_14 ;
}
V_40 = F_32 ( V_31 , L_14 ) ;
if ( F_15 ( V_40 ) ) {
if ( F_16 ( V_40 ) == - V_50 )
F_33 ( L_15 ,
V_2 ) ;
else
F_6 ( L_16 ,
V_2 ) ;
V_14 = F_16 ( V_40 ) ;
goto V_51;
}
V_7 = F_34 ( V_31 , L_17 ) ;
if ( F_15 ( V_7 ) ) {
if ( F_16 ( V_7 ) == - V_50 )
F_33 ( L_18 ,
V_2 ) ;
else
F_6 ( L_19 ,
V_2 ) ;
V_14 = F_16 ( V_7 ) ;
goto V_51;
}
V_8 = F_34 ( V_31 , L_20 ) ;
V_14 = F_35 ( V_31 , & V_3 -> V_4 ) ;
if ( V_14 ) {
F_6 ( L_21 ,
V_2 ) ;
goto V_51;
}
V_14 = F_36 ( & V_3 -> V_4 ) ;
if ( V_14 ) {
F_33 ( L_22 , V_2 ) ;
goto V_51;
}
V_49 = F_13 ( V_40 ) ;
V_33 = F_14 ( V_31 , & V_49 ) ;
if ( F_15 ( V_33 ) ) {
F_6 ( L_23 , V_2 ) ;
V_14 = F_16 ( V_33 ) ;
goto V_52;
}
V_3 -> V_38 = F_17 ( V_33 ) ;
F_18 ( V_33 ) ;
V_3 -> V_31 = V_31 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_8 = F_15 ( V_8 ) ? NULL : V_8 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_40 = V_40 ;
V_3 -> V_20 = ! F_15 ( V_8 ) ;
return 0 ;
V_52:
F_37 ( & V_3 -> V_4 ) ;
V_51:
if ( ! F_15 ( V_7 ) )
F_38 ( V_7 ) ;
if ( ! F_15 ( V_8 ) )
F_38 ( V_8 ) ;
if ( ! F_15 ( V_27 ) )
F_39 ( V_27 ) ;
if ( ! F_15 ( V_40 ) )
F_39 ( V_40 ) ;
return V_14 ;
}
static void F_40 ( struct V_1 * V_3 )
{
if ( ! F_15 ( V_3 -> V_7 ) )
F_38 ( V_3 -> V_7 ) ;
if ( ! F_15 ( V_3 -> V_8 ) )
F_38 ( V_3 -> V_8 ) ;
if ( ! F_15 ( V_3 -> V_27 ) )
F_39 ( V_3 -> V_27 ) ;
if ( ! F_15 ( V_3 -> V_40 ) )
F_39 ( V_3 -> V_40 ) ;
F_37 ( & V_3 -> V_4 ) ;
}
static int F_41 ( struct V_21 * V_22 )
{
struct V_1 * V_3 ;
struct V_24 * V_25 ;
int V_14 ;
V_3 = F_1 ( V_22 -> V_2 ) ;
if ( ! V_3 ) {
F_6 ( L_24 ,
V_22 -> V_2 ) ;
return - V_53 ;
}
V_14 = F_42 ( V_3 -> V_31 , & V_25 ) ;
if ( V_14 ) {
F_6 ( L_25 ,
V_22 -> V_2 , V_14 ) ;
return V_14 ;
}
V_14 = F_43 ( V_22 , V_25 ) ;
if ( V_14 ) {
F_6 ( L_26 , V_15 , V_14 ) ;
goto V_54;
}
F_44 ( V_22 -> V_4 , & V_3 -> V_4 ) ;
V_22 -> V_29 = V_3 ;
V_22 -> V_26 = V_3 -> V_27 ;
return 0 ;
V_54:
F_45 ( V_3 -> V_31 , & V_25 ) ;
return V_14 ;
}
static int F_46 ( struct V_21 * V_22 )
{
struct V_1 * V_3 = V_22 -> V_29 ;
F_47 ( V_3 -> V_46 ) ;
F_45 ( V_3 -> V_31 , & V_22 -> V_25 ) ;
return 0 ;
}
static int F_48 ( struct V_55 * V_56 )
{
struct V_1 * V_3 , * V_57 ;
int V_2 , V_14 ;
F_49 (cpu) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
continue;
V_3 = F_50 ( & V_56 -> V_58 , sizeof( * V_3 ) , V_59 ) ;
if ( ! V_3 ) {
V_14 = - V_60 ;
goto V_61;
}
V_14 = F_29 ( V_3 , V_2 ) ;
if ( V_14 ) {
F_27 ( & V_56 -> V_58 ,
L_27 ,
V_2 ) ;
goto V_61;
}
F_51 ( & V_3 -> V_62 , & V_63 ) ;
}
V_14 = F_52 ( & V_64 ) ;
if ( V_14 ) {
F_27 ( & V_56 -> V_58 , L_28 ) ;
goto V_61;
}
return 0 ;
V_61:
F_53 (info, tmp, &dvfs_info_list, list_head) {
F_40 ( V_3 ) ;
F_54 ( & V_3 -> V_62 ) ;
}
return V_14 ;
}
static int F_55 ( void )
{
struct V_55 * V_56 ;
int V_65 ;
if ( ! F_56 ( L_29 ) )
return - V_48 ;
V_65 = F_57 ( & V_66 ) ;
if ( V_65 )
return V_65 ;
V_56 = F_58 ( L_30 , - 1 , NULL , 0 ) ;
if ( F_15 ( V_56 ) ) {
F_6 ( L_31 ) ;
return F_16 ( V_56 ) ;
}
return 0 ;
}
