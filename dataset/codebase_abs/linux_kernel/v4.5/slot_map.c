static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
F_2 ( ( V_3 < 0 ) || ( V_3 >= V_2 -> V_4 ) ) ;
V_2 -> V_5 [ V_3 ] . V_6 = 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_7 )
{
F_2 ( ( V_3 < 0 ) || ( V_3 >= V_2 -> V_4 ) ) ;
V_2 -> V_5 [ V_3 ] . V_6 = 1 ;
V_2 -> V_5 [ V_3 ] . V_8 = V_7 ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_9 , V_10 , V_11 ;
struct V_12 * V_13 ;
V_11 = 0 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_13 = (struct V_12 * ) V_2 -> V_15 [ V_9 ] -> V_16 ;
for ( V_10 = 0 ;
( V_10 < V_2 -> V_17 ) &&
( V_11 < V_2 -> V_4 ) ;
V_10 ++ , V_11 ++ ) {
if ( V_13 -> V_18 [ V_10 ] . V_19 )
F_3 ( V_2 , V_11 ,
F_5 ( V_13 -> V_18 [ V_10 ] . V_20 ) ) ;
else
F_1 ( V_2 , V_11 ) ;
}
}
}
static void F_6 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) V_2 -> V_15 [ 0 ] -> V_16 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_4 ; V_10 ++ ) {
if ( F_7 ( V_22 -> V_23 [ V_10 ] ) == ( V_24 ) V_25 )
F_1 ( V_2 , V_10 ) ;
else
F_3 ( V_2 , V_10 , F_7 ( V_22 -> V_23 [ V_10 ] ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 )
F_4 ( V_2 ) ;
else
F_6 ( V_2 ) ;
}
int F_9 ( struct V_27 * V_28 )
{
int V_29 ;
struct V_1 * V_2 = V_28 -> V_30 ;
if ( V_2 == NULL )
return 0 ;
F_2 ( V_2 -> V_14 == 0 ) ;
F_2 ( V_2 -> V_15 == NULL ) ;
F_10 ( V_2 -> V_14 ) ;
V_29 = F_11 ( F_12 ( V_2 -> V_31 ) , - 1 , V_2 -> V_14 ,
V_2 -> V_15 , V_32 , NULL ) ;
if ( V_29 == 0 ) {
F_13 ( & V_28 -> V_33 ) ;
F_8 ( V_2 ) ;
F_14 ( & V_28 -> V_33 ) ;
}
return V_29 ;
}
static void F_15 ( struct V_1 * V_2 ,
int V_3 ,
struct V_34 * * V_35 )
{
int V_36 = V_3 / V_2 -> V_17 ;
int V_11 = V_3 % V_2 -> V_17 ;
struct V_12 * V_13 ;
F_2 ( V_36 >= V_2 -> V_14 ) ;
V_13 = (struct V_12 * ) V_2 -> V_15 [ V_36 ] -> V_16 ;
V_13 -> V_18 [ V_11 ] . V_19 = V_2 -> V_5 [ V_3 ] . V_6 ;
if ( V_2 -> V_5 [ V_3 ] . V_6 )
V_13 -> V_18 [ V_11 ] . V_20 =
F_16 ( V_2 -> V_5 [ V_3 ] . V_8 ) ;
* V_35 = V_2 -> V_15 [ V_36 ] ;
}
static void F_17 ( struct V_1 * V_2 ,
int V_3 ,
struct V_34 * * V_35 )
{
int V_10 ;
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) V_2 -> V_15 [ 0 ] -> V_16 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_4 ; V_10 ++ ) {
if ( V_2 -> V_5 [ V_10 ] . V_6 )
V_22 -> V_23 [ V_10 ] =
F_18 ( V_2 -> V_5 [ V_10 ] . V_8 ) ;
else
V_22 -> V_23 [ V_10 ] = F_18 ( V_25 ) ;
}
* V_35 = V_2 -> V_15 [ 0 ] ;
}
static int F_19 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
int V_3 )
{
int V_37 ;
struct V_34 * V_35 ;
F_13 ( & V_28 -> V_33 ) ;
if ( V_2 -> V_26 )
F_15 ( V_2 , V_3 , & V_35 ) ;
else
F_17 ( V_2 , V_3 , & V_35 ) ;
F_14 ( & V_28 -> V_33 ) ;
V_37 = F_20 ( V_28 , V_35 , F_12 ( V_2 -> V_31 ) ) ;
if ( V_37 < 0 )
F_21 ( V_37 ) ;
return V_37 ;
}
static int F_22 ( struct V_27 * V_28 ,
struct V_38 * V_38 ,
unsigned long long * V_39 )
{
unsigned long long V_40 ;
if ( F_23 ( V_28 ) ) {
V_40 = V_28 -> V_41 *
sizeof( struct V_42 ) ;
} else {
V_40 = V_28 -> V_41 * sizeof( V_43 ) ;
}
if ( V_40 > F_24 ( V_38 ) ) {
F_25 ( V_44 ,
L_1 ,
F_24 ( V_38 ) , V_40 ) ;
return - V_45 ;
}
* V_39 = V_40 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
int V_10 , V_29 = - V_46 ;
for( V_10 = 0 ; V_10 < V_2 -> V_4 ; V_10 ++ ) {
if ( V_2 -> V_5 [ V_10 ] . V_6 &&
( V_7 == V_2 -> V_5 [ V_10 ] . V_8 ) ) {
V_29 = V_10 ;
break;
}
}
return V_29 ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_47 )
{
int V_10 , V_29 = - V_45 ;
if ( ( V_47 >= 0 ) && ( V_47 < V_2 -> V_4 ) ) {
if ( ! V_2 -> V_5 [ V_47 ] . V_6 ) {
V_29 = V_47 ;
goto V_48;
}
}
for( V_10 = 0 ; V_10 < V_2 -> V_4 ; V_10 ++ ) {
if ( ! V_2 -> V_5 [ V_10 ] . V_6 ) {
V_29 = V_10 ;
break;
}
}
V_48:
return V_29 ;
}
int F_28 ( struct V_27 * V_28 , unsigned int V_7 )
{
int V_49 ;
struct V_1 * V_2 = V_28 -> V_30 ;
F_13 ( & V_28 -> V_33 ) ;
V_49 = F_26 ( V_2 , V_7 ) ;
F_14 ( & V_28 -> V_33 ) ;
return V_49 ;
}
int F_29 ( struct V_27 * V_28 , int V_3 ,
unsigned int * V_7 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_30 ( & V_28 -> V_33 ) ;
F_2 ( V_3 < 0 ) ;
F_2 ( V_3 >= V_28 -> V_41 ) ;
if ( ! V_2 -> V_5 [ V_3 ] . V_6 )
return - V_46 ;
* V_7 = V_2 -> V_5 [ V_3 ] . V_8 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
if ( V_2 == NULL )
return;
F_32 ( V_2 -> V_31 ) ;
if ( V_2 -> V_15 ) {
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ ) {
if ( V_2 -> V_15 [ V_10 ] ) {
F_33 ( V_2 -> V_15 [ V_10 ] ) ;
V_2 -> V_15 [ V_10 ] = NULL ;
}
}
F_34 ( V_2 -> V_15 ) ;
}
F_34 ( V_2 ) ;
}
int F_35 ( struct V_27 * V_28 , int V_3 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
if ( V_2 == NULL )
return 0 ;
F_13 ( & V_28 -> V_33 ) ;
F_1 ( V_2 , V_3 ) ;
F_14 ( & V_28 -> V_33 ) ;
return F_19 ( V_28 , V_28 -> V_30 , V_3 ) ;
}
static int F_36 ( struct V_27 * V_28 ,
struct V_1 * V_2 )
{
int V_37 = 0 ;
T_1 V_50 ;
unsigned long long V_51 , V_39 = 0 ;
unsigned int V_10 ;
struct V_34 * V_35 ;
V_37 = F_22 ( V_28 , V_2 -> V_31 , & V_39 ) ;
if ( V_37 )
goto V_52;
V_51 = F_37 ( V_2 -> V_31 -> V_53 , V_39 ) ;
F_2 ( V_51 > V_54 ) ;
V_2 -> V_14 = V_51 ;
if ( ! V_2 -> V_14 )
goto V_52;
if ( V_2 -> V_26 )
V_2 -> V_17 =
( V_28 -> V_55 -> V_56 /
sizeof( struct V_42 ) ) ;
else
V_2 -> V_17 = V_28 -> V_55 -> V_56 / sizeof( V_43 ) ;
F_2 ( ( V_28 -> V_41 / V_2 -> V_17 ) > V_51 ) ;
F_38 ( V_39 , V_2 -> V_14 ) ;
V_2 -> V_15 = F_39 ( V_2 -> V_14 , sizeof( struct V_34 * ) ,
V_57 ) ;
if ( ! V_2 -> V_15 ) {
V_37 = - V_58 ;
F_21 ( V_37 ) ;
goto V_52;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ ) {
V_37 = F_40 ( V_2 -> V_31 , V_10 ,
& V_50 , NULL , NULL ) ;
if ( V_37 < 0 ) {
F_21 ( V_37 ) ;
goto V_52;
}
F_41 ( ( unsigned long long ) V_50 , V_10 ) ;
V_35 = NULL ;
V_37 = F_11 ( F_12 ( V_2 -> V_31 ) , V_50 ,
1 , & V_35 , V_32 , NULL ) ;
if ( V_37 < 0 ) {
F_21 ( V_37 ) ;
goto V_52;
}
V_2 -> V_15 [ V_10 ] = V_35 ;
}
V_52:
return V_37 ;
}
int F_42 ( struct V_27 * V_28 )
{
int V_37 ;
struct V_38 * V_38 = NULL ;
struct V_1 * V_2 ;
V_2 = F_43 ( sizeof( struct V_1 ) +
( sizeof( struct V_59 ) * V_28 -> V_41 ) ,
V_57 ) ;
if ( ! V_2 ) {
V_37 = - V_58 ;
F_21 ( V_37 ) ;
return V_37 ;
}
V_2 -> V_26 = F_23 ( V_28 ) ;
V_2 -> V_4 = V_28 -> V_41 ;
V_2 -> V_5 = (struct V_59 * ) ( ( char * ) V_2 +
sizeof( struct V_1 ) ) ;
V_38 = F_44 ( V_28 , V_60 ,
V_25 ) ;
if ( ! V_38 ) {
V_37 = - V_61 ;
F_21 ( V_37 ) ;
goto V_52;
}
V_2 -> V_31 = V_38 ;
V_37 = F_36 ( V_28 , V_2 ) ;
if ( V_37 < 0 ) {
F_21 ( V_37 ) ;
goto V_52;
}
V_28 -> V_30 = (struct V_1 * ) V_2 ;
V_52:
if ( V_37 < 0 )
F_31 ( V_2 ) ;
return V_37 ;
}
void F_45 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
V_28 -> V_30 = NULL ;
F_31 ( V_2 ) ;
}
int F_46 ( struct V_27 * V_28 )
{
int V_37 ;
int V_49 ;
struct V_1 * V_2 ;
V_2 = V_28 -> V_30 ;
F_13 ( & V_28 -> V_33 ) ;
F_8 ( V_2 ) ;
V_49 = F_26 ( V_2 , V_28 -> V_7 ) ;
if ( V_49 < 0 ) {
V_49 = F_27 ( V_2 , V_28 -> V_62 ) ;
if ( V_49 < 0 ) {
F_14 ( & V_28 -> V_33 ) ;
F_25 ( V_44 , L_2 ) ;
V_37 = - V_61 ;
goto V_52;
}
} else
F_47 ( V_63 L_3
L_4 , V_49 , V_28 -> V_64 ) ;
F_3 ( V_2 , V_49 , V_28 -> V_7 ) ;
V_28 -> V_3 = V_49 ;
F_14 ( & V_28 -> V_33 ) ;
F_48 ( V_28 -> V_3 ) ;
V_37 = F_19 ( V_28 , V_2 , V_28 -> V_3 ) ;
if ( V_37 < 0 ) {
F_21 ( V_37 ) ;
F_13 ( & V_28 -> V_33 ) ;
F_1 ( V_2 , V_28 -> V_3 ) ;
V_28 -> V_3 = V_25 ;
F_14 ( & V_28 -> V_33 ) ;
}
V_52:
return V_37 ;
}
void F_49 ( struct V_27 * V_28 )
{
int V_37 , V_3 ;
struct V_1 * V_2 = V_28 -> V_30 ;
if ( ! V_2 )
return;
F_13 ( & V_28 -> V_33 ) ;
F_8 ( V_2 ) ;
V_3 = V_28 -> V_3 ;
F_1 ( V_2 , V_28 -> V_3 ) ;
V_28 -> V_3 = V_25 ;
F_14 ( & V_28 -> V_33 ) ;
V_37 = F_19 ( V_28 , V_2 , V_3 ) ;
if ( V_37 < 0 ) {
F_21 ( V_37 ) ;
goto V_52;
}
V_52:
F_45 ( V_28 ) ;
}
