static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
int V_5 = 0 ;
struct V_6 V_7 = { } ;
F_2 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_9 == V_3 )
goto V_10;
F_3 ( V_2 -> V_3 , & V_7 ) ;
V_4 = V_2 -> V_3 -> args . V_4 ;
V_7 . V_11 = F_4 ( V_3 * ( V_4 - 1 ) , V_12 ) ;
V_7 . V_13 = V_3 ? true : false ;
V_5 = F_5 ( V_2 -> V_3 , & V_7 ) ;
if ( ! V_5 )
V_2 -> V_9 = V_3 ;
V_10:
F_6 ( & V_2 -> V_8 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; ++ V_14 )
if ( V_3 < V_2 -> V_16 [ V_14 + 1 ] )
break;
V_2 -> V_17 = V_14 ;
}
static T_1 F_8 ( struct V_18 * V_19 , struct V_20 * V_21 ,
const char * V_22 , T_2 V_23 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
unsigned long V_3 ;
int V_5 ;
if ( F_10 ( V_22 , 10 , & V_3 ) || V_3 > V_12 )
return - V_24 ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_5 )
return V_5 ;
F_7 ( V_2 , V_3 ) ;
return V_23 ;
}
static T_1 F_11 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
return sprintf ( V_22 , L_1 , V_2 -> V_9 ) ;
}
static int F_12 ( struct V_25 * V_26 ,
unsigned long * V_7 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
if ( ! V_2 )
return - V_24 ;
* V_7 = V_2 -> V_15 ;
return 0 ;
}
static int F_13 ( struct V_25 * V_26 ,
unsigned long * V_7 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
if ( ! V_2 )
return - V_24 ;
* V_7 = V_2 -> V_17 ;
return 0 ;
}
static int
F_14 ( struct V_25 * V_26 , unsigned long V_7 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_5 ;
if ( ! V_2 || ( V_7 > V_2 -> V_15 ) )
return - V_24 ;
if ( V_7 == V_2 -> V_17 )
return 0 ;
V_5 = F_1 ( V_2 , V_2 -> V_16 [ V_7 ] ) ;
if ( V_5 ) {
F_15 ( & V_26 -> V_18 , L_2 ) ;
return V_5 ;
}
V_2 -> V_17 = V_7 ;
return V_5 ;
}
static int F_16 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = V_19 -> V_30 ;
int V_31 , V_14 , V_5 ;
if ( ! F_17 ( V_29 , L_3 , NULL ) )
return 0 ;
V_5 = F_18 ( V_29 , L_3 ) ;
if ( V_5 <= 0 ) {
F_15 ( V_19 , L_4 ) ;
return V_5 ? : - V_24 ;
}
V_31 = V_5 ;
V_2 -> V_16 = F_19 ( V_19 , V_31 * sizeof( V_32 ) ,
V_33 ) ;
if ( ! V_2 -> V_16 )
return - V_34 ;
V_5 = F_20 ( V_29 , L_3 ,
V_2 -> V_16 , V_31 ) ;
if ( V_5 ) {
F_15 ( V_19 , L_5 ) ;
return V_5 ;
}
for ( V_14 = 0 ; V_14 < V_31 ; V_14 ++ ) {
if ( V_2 -> V_16 [ V_14 ] > V_12 ) {
F_15 ( V_19 , L_6 , V_14 ,
V_2 -> V_16 [ V_14 ] , V_12 ) ;
return - V_24 ;
}
}
V_2 -> V_15 = V_31 - 1 ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_18 * V_37 ;
int V_5 ;
struct V_6 V_7 = { } ;
V_2 = F_19 ( & V_36 -> V_19 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
F_22 ( & V_2 -> V_8 ) ;
V_2 -> V_3 = F_23 ( & V_36 -> V_19 , V_36 -> V_19 . V_30 , NULL ) ;
if ( F_24 ( V_2 -> V_3 ) ) {
F_15 ( & V_36 -> V_19 , L_7 ) ;
return F_25 ( V_2 -> V_3 ) ;
}
F_26 ( V_36 , V_2 ) ;
V_2 -> V_9 = V_12 ;
F_3 ( V_2 -> V_3 , & V_7 ) ;
V_7 . V_11 = V_2 -> V_3 -> args . V_4 - 1 ;
V_7 . V_13 = true ;
V_5 = F_5 ( V_2 -> V_3 , & V_7 ) ;
if ( V_5 ) {
F_15 ( & V_36 -> V_19 , L_8 ) ;
return V_5 ;
}
V_37 = F_27 ( & V_36 -> V_19 , L_9 ,
V_2 , V_38 ) ;
if ( F_24 ( V_37 ) ) {
F_15 ( & V_36 -> V_19 , L_10 ) ;
V_5 = F_25 ( V_37 ) ;
goto V_39;
}
V_5 = F_16 ( & V_36 -> V_19 , V_2 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_17 = V_2 -> V_15 ;
if ( F_28 ( V_40 ) ) {
V_26 = F_29 ( V_36 -> V_19 . V_30 ,
L_11 , V_2 ,
& V_41 ) ;
if ( F_24 ( V_26 ) ) {
F_15 ( & V_36 -> V_19 ,
L_12 ) ;
V_5 = F_25 ( V_26 ) ;
goto V_39;
}
V_2 -> V_26 = V_26 ;
F_30 ( V_26 ) ;
}
return 0 ;
V_39:
V_7 . V_13 = false ;
F_5 ( V_2 -> V_3 , & V_7 ) ;
return V_5 ;
}
static int F_31 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_32 ( V_36 ) ;
F_33 ( V_2 -> V_26 ) ;
if ( V_2 -> V_9 )
F_34 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
if ( V_2 -> V_9 )
F_34 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
struct V_42 V_43 ;
unsigned long V_44 ;
int V_5 ;
if ( V_2 -> V_9 == 0 )
return 0 ;
F_37 ( V_2 -> V_3 , & V_43 ) ;
V_44 = F_4 ( V_2 -> V_9 * ( V_43 . V_4 - 1 ) , V_12 ) ;
V_5 = F_38 ( V_2 -> V_3 , V_44 , V_43 . V_4 ) ;
if ( V_5 )
return V_5 ;
return F_39 ( V_2 -> V_3 ) ;
}
