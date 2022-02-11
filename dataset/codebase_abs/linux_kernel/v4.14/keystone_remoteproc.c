static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
int V_5 ;
if ( V_4 & ( V_6 - 1 ) ) {
F_4 ( V_2 -> V_7 , L_1 ,
V_4 ) ;
return - V_8 ;
}
V_5 = F_5 ( V_2 -> V_9 , V_2 -> V_10 , V_4 ) ;
if ( V_5 ) {
F_4 ( V_2 -> V_7 , L_2 ,
V_5 ) ;
return V_5 ;
}
F_6 ( V_2 -> V_3 ) ;
return 0 ;
}
static T_2 F_7 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
F_8 ( V_2 -> V_13 , V_14 ) ;
return V_15 ;
}
static void F_9 ( struct V_16 * V_17 )
{
struct V_1 * V_2 =
F_10 ( V_17 , struct V_1 , V_18 ) ;
F_11 ( V_2 -> V_13 , 0 ) ;
F_11 ( V_2 -> V_13 , 1 ) ;
}
static T_2 F_12 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
F_13 ( & V_2 -> V_18 ) ;
return V_15 ;
}
static int F_14 ( struct V_13 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_19 ;
int V_5 ;
F_15 ( & V_2 -> V_18 , F_9 ) ;
V_5 = F_16 ( V_2 -> V_20 , F_12 , 0 ,
F_17 ( V_2 -> V_7 ) , V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 -> V_7 , L_3 ,
V_5 ) ;
goto V_21;
}
V_5 = F_16 ( V_2 -> V_22 , F_7 ,
0 , F_17 ( V_2 -> V_7 ) , V_2 ) ;
if ( V_5 ) {
F_4 ( V_2 -> V_7 , L_4 ,
V_5 ) ;
goto V_23;
}
V_5 = F_3 ( V_2 , V_13 -> V_24 ) ;
if ( V_5 )
goto V_25;
return 0 ;
V_25:
F_18 ( V_2 -> V_22 , V_2 ) ;
V_23:
F_18 ( V_2 -> V_20 , V_2 ) ;
F_19 ( & V_2 -> V_18 ) ;
V_21:
return V_5 ;
}
static int F_20 ( struct V_13 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_19 ;
F_1 ( V_2 ) ;
F_18 ( V_2 -> V_22 , V_2 ) ;
F_18 ( V_2 -> V_20 , V_2 ) ;
F_19 ( & V_2 -> V_18 ) ;
return 0 ;
}
static void F_21 ( struct V_13 * V_13 , int V_26 )
{
struct V_1 * V_2 = V_13 -> V_19 ;
if ( F_22 ( V_2 -> V_27 < 0 ) )
return;
F_23 ( V_2 -> V_27 , 1 ) ;
}
static void * F_24 ( struct V_13 * V_13 , T_3 V_28 , int V_29 )
{
struct V_1 * V_2 = V_13 -> V_19 ;
void T_4 * V_30 = NULL ;
T_5 V_31 ;
T_1 V_32 , V_33 ;
T_6 V_34 ;
int V_35 ;
if ( V_29 <= 0 )
return NULL ;
for ( V_35 = 0 ; V_35 < V_2 -> V_36 ; V_35 ++ ) {
V_31 = V_2 -> V_37 [ V_35 ] . V_31 ;
V_32 = V_2 -> V_37 [ V_35 ] . V_32 ;
V_34 = V_2 -> V_37 [ V_35 ] . V_34 ;
if ( V_28 < V_38 ) {
if ( ( V_28 >= V_32 ) &&
( ( V_28 + V_29 ) <= ( V_32 + V_34 ) ) ) {
V_33 = V_28 - V_32 ;
V_30 = V_2 -> V_37 [ V_35 ] . V_39 + V_33 ;
break;
}
} else {
if ( ( V_28 >= V_31 ) &&
( V_28 + V_29 ) <= ( V_31 + V_34 ) ) {
V_33 = V_28 - V_31 ;
V_30 = V_2 -> V_37 [ V_35 ] . V_39 + V_33 ;
break;
}
}
}
return ( V_40 void * ) V_30 ;
}
static int F_25 ( struct V_41 * V_42 ,
struct V_1 * V_2 )
{
static const char * const V_43 [] = { L_5 , L_6 , L_7 } ;
struct V_44 * V_7 = & V_42 -> V_7 ;
struct V_45 * V_46 ;
int V_36 = 0 ;
int V_35 ;
V_36 = F_26 ( V_43 ) ;
V_2 -> V_37 = F_27 ( V_2 -> V_7 , V_36 ,
sizeof( * V_2 -> V_37 ) , V_47 ) ;
if ( ! V_2 -> V_37 )
return - V_48 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_46 = F_28 ( V_42 , V_49 ,
V_43 [ V_35 ] ) ;
V_2 -> V_37 [ V_35 ] . V_39 = F_29 ( V_7 , V_46 ) ;
if ( F_30 ( V_2 -> V_37 [ V_35 ] . V_39 ) ) {
F_4 ( V_7 , L_8 ,
V_43 [ V_35 ] ) ;
return F_31 ( V_2 -> V_37 [ V_35 ] . V_39 ) ;
}
V_2 -> V_37 [ V_35 ] . V_31 = V_46 -> V_50 ;
V_2 -> V_37 [ V_35 ] . V_32 =
V_46 -> V_50 & V_38 ;
V_2 -> V_37 [ V_35 ] . V_34 = F_32 ( V_46 ) ;
memset ( ( V_40 void * ) V_2 -> V_37 [ V_35 ] . V_39 , 0 ,
V_2 -> V_37 [ V_35 ] . V_34 ) ;
}
V_2 -> V_36 = V_36 ;
return 0 ;
}
static int F_33 ( struct V_41 * V_42 ,
struct V_1 * V_2 )
{
struct V_51 * V_52 = V_42 -> V_7 . V_53 ;
struct V_44 * V_7 = & V_42 -> V_7 ;
int V_5 ;
if ( ! F_34 ( V_52 , L_9 ) ) {
F_4 ( V_7 , L_10 ) ;
return - V_8 ;
}
V_2 -> V_9 =
F_35 ( V_52 , L_9 ) ;
if ( F_30 ( V_2 -> V_9 ) ) {
V_5 = F_31 ( V_2 -> V_9 ) ;
return V_5 ;
}
if ( F_36 ( V_52 , L_9 , 1 ,
& V_2 -> V_10 ) ) {
F_4 ( V_7 , L_11 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_37 ( struct V_41 * V_42 )
{
struct V_44 * V_7 = & V_42 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_1 * V_2 ;
struct V_13 * V_13 ;
int V_54 ;
char * V_55 = NULL ;
char * V_56 = L_12 ;
int V_57 = 0 ;
int V_5 = 0 ;
if ( ! V_52 ) {
F_4 ( V_7 , L_13 ) ;
return - V_58 ;
}
V_54 = F_38 ( V_52 , L_14 ) ;
if ( V_54 < 0 ) {
F_39 ( V_7 , L_15 ) ;
return V_54 ;
}
V_57 = strlen ( V_56 ) ;
V_55 = F_40 ( V_7 , V_57 , V_47 ) ;
if ( ! V_55 )
return - V_48 ;
snprintf ( V_55 , V_57 , V_56 , V_54 ) ;
V_13 = F_41 ( V_7 , F_17 ( V_7 ) , & V_59 , V_55 ,
sizeof( * V_2 ) ) ;
if ( ! V_13 )
return - V_48 ;
V_13 -> V_60 = false ;
V_2 = V_13 -> V_19 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_7 = V_7 ;
V_5 = F_33 ( V_42 , V_2 ) ;
if ( V_5 )
goto V_61;
V_2 -> V_3 = F_42 ( V_7 , NULL ) ;
if ( F_30 ( V_2 -> V_3 ) ) {
V_5 = F_31 ( V_2 -> V_3 ) ;
goto V_61;
}
F_43 ( V_7 ) ;
V_5 = F_44 ( V_7 ) ;
if ( V_5 < 0 ) {
F_4 ( V_7 , L_16 , V_5 ) ;
F_45 ( V_7 ) ;
goto V_62;
}
V_5 = F_25 ( V_42 , V_2 ) ;
if ( V_5 )
goto V_63;
V_2 -> V_20 = F_46 ( V_42 , L_17 ) ;
if ( V_2 -> V_20 < 0 ) {
V_5 = V_2 -> V_20 ;
F_4 ( V_7 , L_18 ,
V_5 ) ;
goto V_63;
}
V_2 -> V_22 = F_46 ( V_42 , L_19 ) ;
if ( V_2 -> V_22 < 0 ) {
V_5 = V_2 -> V_22 ;
F_4 ( V_7 , L_20 ,
V_5 ) ;
goto V_63;
}
V_2 -> V_27 = F_47 ( V_52 , L_21 , 0 , NULL ) ;
if ( V_2 -> V_27 < 0 ) {
V_5 = V_2 -> V_27 ;
F_4 ( V_7 , L_22 ,
V_5 ) ;
goto V_63;
}
if ( F_48 ( V_7 ) )
F_39 ( V_7 , L_23 ) ;
V_5 = F_49 ( V_2 -> V_3 ) ;
if ( V_5 < 0 ) {
F_4 ( V_7 , L_24 , V_5 ) ;
goto V_64;
} else if ( V_5 == 0 ) {
F_50 ( 1 , L_25 ) ;
F_1 ( V_2 ) ;
}
V_5 = F_51 ( V_13 ) ;
if ( V_5 ) {
F_4 ( V_7 , L_26 ,
V_5 ) ;
goto V_64;
}
F_52 ( V_42 , V_2 ) ;
return 0 ;
V_64:
F_53 ( V_7 ) ;
V_63:
F_54 ( V_7 ) ;
V_62:
F_55 ( V_7 ) ;
V_61:
F_56 ( V_13 ) ;
return V_5 ;
}
static int F_57 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_58 ( V_42 ) ;
F_59 ( V_2 -> V_13 ) ;
F_54 ( & V_42 -> V_7 ) ;
F_55 ( & V_42 -> V_7 ) ;
F_56 ( V_2 -> V_13 ) ;
F_53 ( & V_42 -> V_7 ) ;
return 0 ;
}
