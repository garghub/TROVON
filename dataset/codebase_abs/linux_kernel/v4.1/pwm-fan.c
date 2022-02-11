static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
int V_5 = 0 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 == V_3 )
goto V_8;
V_4 = F_3 ( V_3 * ( V_2 -> V_3 -> V_9 - 1 ) , V_10 ) ;
V_5 = F_4 ( V_2 -> V_3 , V_4 , V_2 -> V_3 -> V_9 ) ;
if ( V_5 )
goto V_8;
if ( V_3 == 0 )
F_5 ( V_2 -> V_3 ) ;
if ( V_2 -> V_7 == 0 ) {
V_5 = F_6 ( V_2 -> V_3 ) ;
if ( V_5 )
goto V_8;
}
V_2 -> V_7 = V_3 ;
V_8:
F_7 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 )
if ( V_3 < V_2 -> V_13 [ V_11 + 1 ] )
break;
V_2 -> V_14 = V_11 ;
}
static T_1 F_9 ( struct V_15 * V_16 , struct V_17 * V_18 ,
const char * V_19 , T_2 V_20 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
unsigned long V_3 ;
int V_5 ;
if ( F_11 ( V_19 , 10 , & V_3 ) || V_3 > V_10 )
return - V_21 ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_5 )
return V_5 ;
F_8 ( V_2 , V_3 ) ;
return V_20 ;
}
static T_1 F_12 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
return sprintf ( V_19 , L_1 , V_2 -> V_7 ) ;
}
static int F_13 ( struct V_22 * V_23 ,
unsigned long * V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
if ( ! V_2 )
return - V_21 ;
* V_24 = V_2 -> V_12 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 ,
unsigned long * V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
if ( ! V_2 )
return - V_21 ;
* V_24 = V_2 -> V_14 ;
return 0 ;
}
static int
F_15 ( struct V_22 * V_23 , unsigned long V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
int V_5 ;
if ( ! V_2 || ( V_24 > V_2 -> V_12 ) )
return - V_21 ;
if ( V_24 == V_2 -> V_14 )
return 0 ;
V_5 = F_1 ( V_2 , V_2 -> V_13 [ V_24 ] ) ;
if ( V_5 ) {
F_16 ( & V_23 -> V_15 , L_2 ) ;
return V_5 ;
}
V_2 -> V_14 = V_24 ;
return V_5 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 = V_16 -> V_28 ;
int V_29 , V_11 , V_5 ;
if ( ! F_18 ( V_27 , L_3 , NULL ) )
return 0 ;
V_5 = F_19 ( V_27 , L_3 ) ;
if ( V_5 <= 0 ) {
F_16 ( V_16 , L_4 ) ;
return V_5 ? : - V_21 ;
}
V_29 = V_5 ;
V_2 -> V_13 = F_20 ( V_16 , V_29 * sizeof( V_30 ) ,
V_31 ) ;
if ( ! V_2 -> V_13 )
return - V_32 ;
V_5 = F_21 ( V_27 , L_3 ,
V_2 -> V_13 , V_29 ) ;
if ( V_5 ) {
F_16 ( V_16 , L_5 ) ;
return V_5 ;
}
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
if ( V_2 -> V_13 [ V_11 ] > V_10 ) {
F_16 ( V_16 , L_6 , V_11 ,
V_2 -> V_13 [ V_11 ] , V_10 ) ;
return - V_21 ;
}
}
V_2 -> V_12 = V_29 - 1 ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_15 * V_35 ;
int V_36 ;
int V_5 ;
V_2 = F_20 ( & V_34 -> V_16 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
F_23 ( & V_2 -> V_6 ) ;
V_2 -> V_3 = F_24 ( & V_34 -> V_16 , V_34 -> V_16 . V_28 , NULL ) ;
if ( F_25 ( V_2 -> V_3 ) ) {
F_16 ( & V_34 -> V_16 , L_7 ) ;
return F_26 ( V_2 -> V_3 ) ;
}
F_27 ( V_34 , V_2 ) ;
V_36 = V_2 -> V_3 -> V_9 - 1 ;
V_2 -> V_7 = V_10 ;
V_5 = F_4 ( V_2 -> V_3 , V_36 , V_2 -> V_3 -> V_9 ) ;
if ( V_5 ) {
F_16 ( & V_34 -> V_16 , L_8 ) ;
return V_5 ;
}
V_5 = F_6 ( V_2 -> V_3 ) ;
if ( V_5 ) {
F_16 ( & V_34 -> V_16 , L_9 ) ;
return V_5 ;
}
V_35 = F_28 ( & V_34 -> V_16 , L_10 ,
V_2 , V_37 ) ;
if ( F_25 ( V_35 ) ) {
F_16 ( & V_34 -> V_16 , L_11 ) ;
F_5 ( V_2 -> V_3 ) ;
return F_26 ( V_35 ) ;
}
V_5 = F_17 ( & V_34 -> V_16 , V_2 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_14 = V_2 -> V_12 ;
if ( F_29 ( V_38 ) ) {
V_23 = F_30 ( V_34 -> V_16 . V_28 ,
L_12 , V_2 ,
& V_39 ) ;
if ( F_25 ( V_23 ) ) {
F_16 ( & V_34 -> V_16 ,
L_13 ) ;
F_5 ( V_2 -> V_3 ) ;
return F_26 ( V_23 ) ;
}
V_2 -> V_23 = V_23 ;
F_31 ( V_23 ) ;
}
return 0 ;
}
static int F_32 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_33 ( V_34 ) ;
F_34 ( V_2 -> V_23 ) ;
if ( V_2 -> V_7 )
F_5 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
if ( V_2 -> V_7 )
F_5 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
unsigned long V_4 ;
int V_5 ;
if ( V_2 -> V_7 == 0 )
return 0 ;
V_4 = F_3 ( V_2 -> V_7 * ( V_2 -> V_3 -> V_9 - 1 ) , V_10 ) ;
V_5 = F_4 ( V_2 -> V_3 , V_4 , V_2 -> V_3 -> V_9 ) ;
if ( V_5 )
return V_5 ;
return F_6 ( V_2 -> V_3 ) ;
}
