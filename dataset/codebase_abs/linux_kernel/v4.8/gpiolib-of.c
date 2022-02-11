static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
return V_2 -> V_4 -> V_5 . V_6 == V_3 ;
}
static struct V_1 * F_2 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , F_1 ) ;
}
static struct V_9 * F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_12 * V_13 )
{
int V_14 ;
if ( V_2 -> V_15 != V_11 -> V_16 )
return F_5 ( - V_17 ) ;
V_14 = V_2 -> V_18 ( V_2 , V_11 , V_13 ) ;
if ( V_14 < 0 )
return F_5 ( V_14 ) ;
return F_6 ( V_2 , V_14 ) ;
}
struct V_9 * F_7 ( struct V_7 * V_8 ,
const char * V_19 , int V_20 , enum V_12 * V_13 )
{
struct V_10 V_11 ;
struct V_1 * V_2 ;
struct V_9 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_8 , V_19 , L_1 , V_20 ,
& V_11 ) ;
if ( V_14 ) {
F_9 ( L_2 ,
V_22 , V_19 , V_8 -> V_23 , V_20 ) ;
return F_5 ( V_14 ) ;
}
V_2 = F_2 ( V_11 . V_8 ) ;
if ( ! V_2 ) {
V_21 = F_5 ( - V_24 ) ;
goto V_25;
}
V_21 = F_4 ( V_2 , & V_11 , V_13 ) ;
if ( F_10 ( V_21 ) )
goto V_25;
F_9 ( L_3 ,
V_22 , V_19 , V_8 -> V_23 , V_20 ,
F_11 ( V_21 ) ) ;
V_25:
F_12 ( V_11 . V_8 ) ;
return V_21 ;
}
int F_13 ( struct V_7 * V_8 , const char * V_26 ,
int V_20 , enum V_12 * V_13 )
{
struct V_9 * V_21 ;
V_21 = F_7 ( V_8 , V_26 , V_20 , V_13 ) ;
if ( F_10 ( V_21 ) )
return F_14 ( V_21 ) ;
else
return F_15 ( V_21 ) ;
}
static struct V_9 * F_16 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
const char * * V_27 ,
enum V_28 * V_29 ,
enum V_30 * V_31 )
{
struct V_7 * V_32 ;
enum V_12 V_33 ;
struct V_10 V_11 ;
struct V_9 * V_21 ;
T_1 V_34 ;
int V_14 ;
V_32 = V_2 -> V_6 ;
if ( ! V_32 )
return F_5 ( - V_17 ) ;
V_33 = 0 ;
* V_29 = 0 ;
* V_31 = 0 ;
V_14 = F_17 ( V_32 , L_1 , & V_34 ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
V_11 . V_8 = V_32 ;
V_11 . V_16 = V_34 ;
V_14 = F_18 ( V_8 , L_4 , V_11 . args , V_34 ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
V_21 = F_4 ( V_2 , & V_11 , & V_33 ) ;
if ( F_10 ( V_21 ) )
return V_21 ;
if ( V_33 & V_35 )
* V_29 |= V_36 ;
if ( F_19 ( V_8 , L_5 ) )
* V_31 |= V_37 ;
else if ( F_19 ( V_8 , L_6 ) )
* V_31 |= V_38 ;
else if ( F_19 ( V_8 , L_7 ) )
* V_31 |= V_39 ;
else {
F_20 ( L_8 ,
F_15 ( V_21 ) , V_8 -> V_27 ) ;
return F_5 ( - V_17 ) ;
}
if ( V_27 && F_21 ( V_8 , L_9 , V_27 ) )
* V_27 = V_8 -> V_27 ;
return V_21 ;
}
static void F_22 ( struct V_1 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_4 ;
struct V_7 * V_8 = V_40 -> V_6 ;
int V_43 ;
int V_44 ;
V_44 = F_23 ( V_8 , L_10 ) ;
if ( V_44 <= 0 )
return;
if ( V_42 -> V_45 != V_44 )
F_24 ( & V_42 -> V_5 , L_11
L_12 ,
V_44 , V_42 -> V_45 ) ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
const char * V_27 ;
int V_14 ;
V_14 = F_25 ( V_8 ,
L_10 ,
V_43 ,
& V_27 ) ;
if ( V_14 ) {
if ( V_14 != - V_46 )
F_26 ( & V_42 -> V_5 ,
L_13 ,
V_43 , V_14 ) ;
break;
}
V_42 -> V_47 [ V_43 ] . V_27 = V_27 ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_21 = NULL ;
struct V_7 * V_8 ;
const char * V_27 ;
enum V_28 V_29 ;
enum V_30 V_31 ;
int V_14 ;
F_28 (chip->of_node, np) {
if ( ! F_19 ( V_8 , L_14 ) )
continue;
V_21 = F_16 ( V_8 , V_2 , & V_27 , & V_29 , & V_31 ) ;
if ( F_10 ( V_21 ) )
continue;
V_14 = F_29 ( V_21 , V_27 , V_29 , V_31 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_40 ,
const struct V_10 * V_11 , T_1 * V_13 )
{
if ( V_40 -> V_15 < 2 ) {
F_31 ( 1 ) ;
return - V_17 ;
}
if ( F_31 ( V_11 -> V_16 < V_40 -> V_15 ) )
return - V_17 ;
if ( V_11 -> args [ 0 ] >= V_40 -> V_45 )
return - V_17 ;
if ( V_13 )
* V_13 = V_11 -> args [ 1 ] ;
return V_11 -> args [ 0 ] ;
}
int F_32 ( struct V_7 * V_8 ,
struct V_48 * V_49 ,
void * V_3 )
{
int V_14 = - V_50 ;
struct V_1 * V_40 = & V_49 -> V_40 ;
V_40 -> V_51 = F_33 ( V_8 -> V_23 , V_52 ) ;
if ( ! V_40 -> V_51 )
goto V_53;
V_49 -> V_54 = F_34 ( V_8 , 0 ) ;
if ( ! V_49 -> V_54 )
goto V_55;
V_40 -> V_56 = - 1 ;
if ( V_49 -> V_57 )
V_49 -> V_57 ( V_49 ) ;
V_49 -> V_40 . V_6 = V_8 ;
V_14 = F_35 ( V_40 , V_3 ) ;
if ( V_14 )
goto V_58;
return 0 ;
V_58:
F_36 ( V_49 -> V_54 ) ;
V_55:
F_37 ( V_40 -> V_51 ) ;
V_53:
F_38 ( L_15 ,
V_8 -> V_23 , V_14 ) ;
return V_14 ;
}
void F_39 ( struct V_48 * V_49 )
{
struct V_1 * V_40 = & V_49 -> V_40 ;
if ( ! V_49 )
return;
F_40 ( V_40 ) ;
F_36 ( V_49 -> V_54 ) ;
F_37 ( V_40 -> V_51 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_6 ;
struct V_10 V_59 ;
struct V_60 * V_61 ;
int V_20 = 0 , V_14 ;
const char * V_27 ;
static const char V_62 [] = L_16 ;
struct V_63 * V_64 ;
if ( ! V_8 )
return 0 ;
V_64 = F_42 ( V_8 , V_62 , NULL ) ;
for (; ; V_20 ++ ) {
V_14 = F_43 ( V_8 , L_17 , 3 ,
V_20 , & V_59 ) ;
if ( V_14 )
break;
V_61 = F_44 ( V_59 . V_8 ) ;
F_12 ( V_59 . V_8 ) ;
if ( ! V_61 )
return - V_24 ;
if ( V_59 . args [ 2 ] ) {
if ( V_64 ) {
F_25 ( V_8 ,
V_62 ,
V_20 , & V_27 ) ;
if ( strlen ( V_27 ) ) {
F_38 ( L_18 ,
V_8 -> V_23 ) ;
break;
}
}
V_14 = F_45 ( V_2 ,
F_46 ( V_61 ) ,
V_59 . args [ 0 ] ,
V_59 . args [ 1 ] ,
V_59 . args [ 2 ] ) ;
if ( V_14 )
return V_14 ;
} else {
if ( V_59 . args [ 1 ] ) {
F_38 ( L_19 ,
V_8 -> V_23 ) ;
break;
}
if ( ! V_64 ) {
F_38 ( L_20 ,
V_8 -> V_23 , V_62 ) ;
break;
}
V_14 = F_25 ( V_8 ,
V_62 ,
V_20 , & V_27 ) ;
if ( V_14 )
break;
if ( ! strlen ( V_27 ) ) {
F_38 ( L_21 ,
V_8 -> V_23 ) ;
break;
}
V_14 = F_47 ( V_2 , V_61 ,
V_59 . args [ 0 ] , V_27 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ) { return 0 ; }
int F_48 ( struct V_1 * V_2 )
{
int V_65 ;
if ( ( ! V_2 -> V_6 ) && ( V_2 -> V_66 ) )
V_2 -> V_6 = V_2 -> V_66 -> V_6 ;
if ( ! V_2 -> V_6 )
return 0 ;
if ( ! V_2 -> V_18 ) {
V_2 -> V_15 = 2 ;
V_2 -> V_18 = F_30 ;
}
if ( V_2 -> V_15 > V_67 )
return - V_17 ;
V_65 = F_41 ( V_2 ) ;
if ( V_65 )
return V_65 ;
if ( ! V_2 -> V_68 )
F_22 ( V_2 ) ;
F_49 ( V_2 -> V_6 ) ;
return F_27 ( V_2 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_12 ( V_2 -> V_6 ) ;
}
