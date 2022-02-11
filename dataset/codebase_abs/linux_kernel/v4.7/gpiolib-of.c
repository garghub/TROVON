static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
int V_5 ;
if ( ( V_2 -> V_6 != V_4 -> V_7 . V_8 ) ||
( V_2 -> V_9 != V_4 -> V_7 . V_10 ) ||
( ! V_2 -> V_11 ) )
return false ;
V_5 = V_2 -> V_11 ( V_2 , & V_4 -> V_7 , V_4 -> V_12 ) ;
if ( V_5 < 0 ) {
V_4 -> V_13 = F_2 ( V_5 ) ;
return false ;
}
V_4 -> V_13 = F_3 ( V_2 , V_5 ) ;
return true ;
}
struct V_14 * F_4 ( struct V_15 * V_8 ,
const char * V_16 , int V_17 , enum V_18 * V_12 )
{
struct V_4 V_4 = {
. V_12 = V_12 ,
. V_13 = F_2 (-EPROBE_DEFER)
} ;
int V_5 ;
if ( V_12 )
* V_12 = 0 ;
V_5 = F_5 ( V_8 , V_16 , L_1 , V_17 ,
& V_4 . V_7 ) ;
if ( V_5 ) {
F_6 ( L_2 ,
V_19 , V_16 , V_8 -> V_20 , V_17 ) ;
return F_2 ( V_5 ) ;
}
F_7 ( & V_4 , F_1 ) ;
F_8 ( V_4 . V_7 . V_8 ) ;
F_6 ( L_3 ,
V_19 , V_16 , V_8 -> V_20 , V_17 ,
F_9 ( V_4 . V_13 ) ) ;
return V_4 . V_13 ;
}
int F_10 ( struct V_15 * V_8 , const char * V_21 ,
int V_17 , enum V_18 * V_12 )
{
struct V_14 * V_22 ;
V_22 = F_4 ( V_8 , V_21 , V_17 , V_12 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
else
return F_13 ( V_22 ) ;
}
static struct V_14 * F_14 ( struct V_15 * V_8 ,
const char * * V_23 ,
enum V_24 * V_25 ,
enum V_26 * V_27 )
{
struct V_15 * V_28 ;
enum V_18 V_29 ;
struct V_4 V_4 = {
. V_12 = & V_29 ,
} ;
T_1 V_30 ;
int V_31 , V_5 ;
V_28 = V_8 -> V_32 ;
if ( ! V_28 )
return F_2 ( - V_33 ) ;
V_29 = 0 ;
* V_25 = 0 ;
* V_27 = 0 ;
V_5 = F_15 ( V_28 , L_1 , & V_30 ) ;
if ( V_5 )
return F_2 ( V_5 ) ;
if ( V_30 > V_34 )
return F_2 ( - V_33 ) ;
V_4 . V_7 . V_10 = V_30 ;
V_4 . V_7 . V_8 = V_28 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_5 = F_16 ( V_8 , L_4 , V_31 ,
& V_4 . V_7 . args [ V_31 ] ) ;
if ( V_5 )
return F_2 ( V_5 ) ;
}
F_7 ( & V_4 , F_1 ) ;
if ( ! V_4 . V_13 ) {
if ( V_8 -> V_32 == V_8 )
return F_2 ( - V_35 ) ;
else
return F_2 ( - V_33 ) ;
}
if ( V_29 & V_36 )
* V_25 |= V_37 ;
if ( F_17 ( V_8 , L_5 ) )
* V_27 |= V_38 ;
else if ( F_17 ( V_8 , L_6 ) )
* V_27 |= V_39 ;
else if ( F_17 ( V_8 , L_7 ) )
* V_27 |= V_40 ;
else {
F_18 ( L_8 ,
F_13 ( V_4 . V_13 ) , V_8 -> V_23 ) ;
return F_2 ( - V_33 ) ;
}
if ( V_23 && F_19 ( V_8 , L_9 , V_23 ) )
* V_23 = V_8 -> V_23 ;
return V_4 . V_13 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_43 ;
struct V_15 * V_8 = V_2 -> V_6 ;
int V_31 ;
int V_44 ;
V_44 = F_21 ( V_8 , L_10 ) ;
if ( V_44 <= 0 )
return;
if ( V_42 -> V_45 != V_44 )
F_22 ( & V_42 -> V_46 , L_11
L_12 ,
V_44 , V_42 -> V_45 ) ;
for ( V_31 = 0 ; V_31 < V_42 -> V_45 ; V_31 ++ ) {
const char * V_23 ;
int V_5 ;
V_5 = F_23 ( V_8 ,
L_10 ,
V_31 ,
& V_23 ) ;
if ( V_5 ) {
if ( V_5 != - V_47 )
F_24 ( & V_42 -> V_46 ,
L_13 ,
V_31 , V_5 ) ;
break;
}
V_42 -> V_48 [ V_31 ] . V_23 = V_23 ;
}
}
static int F_25 ( struct V_1 * V_49 )
{
struct V_14 * V_22 = NULL ;
struct V_15 * V_8 ;
const char * V_23 ;
enum V_24 V_25 ;
enum V_26 V_27 ;
int V_5 ;
F_26 (chip->of_node, np) {
if ( ! F_17 ( V_8 , L_14 ) )
continue;
V_22 = F_14 ( V_8 , & V_23 , & V_25 , & V_27 ) ;
if ( F_11 ( V_22 ) )
continue;
V_5 = F_27 ( V_22 , V_23 , V_25 , V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
const struct V_50 * V_7 , T_1 * V_12 )
{
if ( V_2 -> V_9 < 2 ) {
F_29 ( 1 ) ;
return - V_33 ;
}
if ( F_29 ( V_7 -> V_10 < V_2 -> V_9 ) )
return - V_33 ;
if ( V_7 -> args [ 0 ] >= V_2 -> V_45 )
return - V_33 ;
if ( V_12 )
* V_12 = V_7 -> args [ 1 ] ;
return V_7 -> args [ 0 ] ;
}
int F_30 ( struct V_15 * V_8 ,
struct V_51 * V_52 ,
void * V_3 )
{
int V_5 = - V_53 ;
struct V_1 * V_2 = & V_52 -> V_2 ;
V_2 -> V_54 = F_31 ( V_8 -> V_20 , V_55 ) ;
if ( ! V_2 -> V_54 )
goto V_56;
V_52 -> V_57 = F_32 ( V_8 , 0 ) ;
if ( ! V_52 -> V_57 )
goto V_58;
V_2 -> V_59 = - 1 ;
if ( V_52 -> V_60 )
V_52 -> V_60 ( V_52 ) ;
V_52 -> V_2 . V_6 = V_8 ;
V_5 = F_33 ( V_2 , V_3 ) ;
if ( V_5 )
goto V_61;
return 0 ;
V_61:
F_34 ( V_52 -> V_57 ) ;
V_58:
F_35 ( V_2 -> V_54 ) ;
V_56:
F_36 ( L_15 ,
V_8 -> V_20 , V_5 ) ;
return V_5 ;
}
void F_37 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = & V_52 -> V_2 ;
if ( ! V_52 )
return;
F_38 ( V_2 ) ;
F_34 ( V_52 -> V_57 ) ;
F_35 ( V_2 -> V_54 ) ;
}
static int F_39 ( struct V_1 * V_49 )
{
struct V_15 * V_8 = V_49 -> V_6 ;
struct V_50 V_62 ;
struct V_63 * V_64 ;
int V_17 = 0 , V_5 ;
const char * V_23 ;
static const char V_65 [] = L_16 ;
struct V_66 * V_67 ;
if ( ! V_8 )
return 0 ;
V_67 = F_40 ( V_8 , V_65 , NULL ) ;
for (; ; V_17 ++ ) {
V_5 = F_41 ( V_8 , L_17 , 3 ,
V_17 , & V_62 ) ;
if ( V_5 )
break;
V_64 = F_42 ( V_62 . V_8 ) ;
if ( ! V_64 )
return - V_68 ;
if ( V_62 . args [ 2 ] ) {
if ( V_67 ) {
F_23 ( V_8 ,
V_65 ,
V_17 , & V_23 ) ;
if ( strlen ( V_23 ) ) {
F_36 ( L_18 ,
V_8 -> V_20 ) ;
break;
}
}
V_5 = F_43 ( V_49 ,
F_44 ( V_64 ) ,
V_62 . args [ 0 ] ,
V_62 . args [ 1 ] ,
V_62 . args [ 2 ] ) ;
if ( V_5 )
return V_5 ;
} else {
if ( V_62 . args [ 1 ] ) {
F_36 ( L_19 ,
V_8 -> V_20 ) ;
break;
}
if ( ! V_67 ) {
F_36 ( L_20 ,
V_8 -> V_20 , V_65 ) ;
break;
}
V_5 = F_23 ( V_8 ,
V_65 ,
V_17 , & V_23 ) ;
if ( V_5 )
break;
if ( ! strlen ( V_23 ) ) {
F_36 ( L_21 ,
V_8 -> V_20 ) ;
break;
}
V_5 = F_45 ( V_49 , V_64 ,
V_62 . args [ 0 ] , V_23 ) ;
if ( V_5 )
return V_5 ;
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_49 ) { return 0 ; }
int F_46 ( struct V_1 * V_49 )
{
int V_69 ;
if ( ( ! V_49 -> V_6 ) && ( V_49 -> V_32 ) )
V_49 -> V_6 = V_49 -> V_32 -> V_6 ;
if ( ! V_49 -> V_6 )
return 0 ;
if ( ! V_49 -> V_11 ) {
V_49 -> V_9 = 2 ;
V_49 -> V_11 = F_28 ;
}
V_69 = F_39 ( V_49 ) ;
if ( V_69 )
return V_69 ;
if ( ! V_49 -> V_70 )
F_20 ( V_49 ) ;
F_47 ( V_49 -> V_6 ) ;
return F_25 ( V_49 ) ;
}
void F_48 ( struct V_1 * V_49 )
{
F_49 ( V_49 ) ;
F_8 ( V_49 -> V_6 ) ;
}
