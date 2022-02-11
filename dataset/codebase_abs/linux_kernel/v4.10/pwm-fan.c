static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 V_5 ;
unsigned long V_6 ;
int V_7 = 0 ;
F_2 ( V_2 -> V_3 , & V_5 ) ;
F_3 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_9 == V_3 )
goto V_10;
V_6 = F_4 ( V_3 * ( V_5 . V_11 - 1 ) , V_12 ) ;
V_7 = F_5 ( V_2 -> V_3 , V_6 , V_5 . V_11 ) ;
if ( V_7 )
goto V_10;
if ( V_3 == 0 )
F_6 ( V_2 -> V_3 ) ;
if ( V_2 -> V_9 == 0 ) {
V_7 = F_7 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_10;
}
V_2 -> V_9 = V_3 ;
V_10:
F_8 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; ++ V_13 )
if ( V_3 < V_2 -> V_15 [ V_13 + 1 ] )
break;
V_2 -> V_16 = V_13 ;
}
static T_1 F_10 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_2 V_22 )
{
struct V_1 * V_2 = F_11 ( V_18 ) ;
unsigned long V_3 ;
int V_7 ;
if ( F_12 ( V_21 , 10 , & V_3 ) || V_3 > V_12 )
return - V_23 ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 )
return V_7 ;
F_9 ( V_2 , V_3 ) ;
return V_22 ;
}
static T_1 F_13 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_1 * V_2 = F_11 ( V_18 ) ;
return sprintf ( V_21 , L_1 , V_2 -> V_9 ) ;
}
static int F_14 ( struct V_24 * V_25 ,
unsigned long * V_26 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
if ( ! V_2 )
return - V_23 ;
* V_26 = V_2 -> V_14 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 ,
unsigned long * V_26 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
if ( ! V_2 )
return - V_23 ;
* V_26 = V_2 -> V_16 ;
return 0 ;
}
static int
F_16 ( struct V_24 * V_25 , unsigned long V_26 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
if ( ! V_2 || ( V_26 > V_2 -> V_14 ) )
return - V_23 ;
if ( V_26 == V_2 -> V_16 )
return 0 ;
V_7 = F_1 ( V_2 , V_2 -> V_15 [ V_26 ] ) ;
if ( V_7 ) {
F_17 ( & V_25 -> V_17 , L_2 ) ;
return V_7 ;
}
V_2 -> V_16 = V_26 ;
return V_7 ;
}
static int F_18 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = V_18 -> V_30 ;
int V_31 , V_13 , V_7 ;
if ( ! F_19 ( V_29 , L_3 , NULL ) )
return 0 ;
V_7 = F_20 ( V_29 , L_3 ) ;
if ( V_7 <= 0 ) {
F_17 ( V_18 , L_4 ) ;
return V_7 ? : - V_23 ;
}
V_31 = V_7 ;
V_2 -> V_15 = F_21 ( V_18 , V_31 * sizeof( V_32 ) ,
V_33 ) ;
if ( ! V_2 -> V_15 )
return - V_34 ;
V_7 = F_22 ( V_29 , L_3 ,
V_2 -> V_15 , V_31 ) ;
if ( V_7 ) {
F_17 ( V_18 , L_5 ) ;
return V_7 ;
}
for ( V_13 = 0 ; V_13 < V_31 ; V_13 ++ ) {
if ( V_2 -> V_15 [ V_13 ] > V_12 ) {
F_17 ( V_18 , L_6 , V_13 ,
V_2 -> V_15 [ V_13 ] , V_12 ) ;
return - V_23 ;
}
}
V_2 -> V_14 = V_31 - 1 ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
struct V_4 V_5 ;
struct V_17 * V_37 ;
int V_38 ;
int V_7 ;
V_2 = F_21 ( & V_36 -> V_18 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
F_24 ( & V_2 -> V_8 ) ;
V_2 -> V_3 = F_25 ( & V_36 -> V_18 , V_36 -> V_18 . V_30 , NULL ) ;
if ( F_26 ( V_2 -> V_3 ) ) {
F_17 ( & V_36 -> V_18 , L_7 ) ;
return F_27 ( V_2 -> V_3 ) ;
}
F_28 ( V_36 , V_2 ) ;
F_29 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_3 , & V_5 ) ;
V_38 = V_5 . V_11 - 1 ;
V_2 -> V_9 = V_12 ;
V_7 = F_5 ( V_2 -> V_3 , V_38 , V_5 . V_11 ) ;
if ( V_7 ) {
F_17 ( & V_36 -> V_18 , L_8 ) ;
return V_7 ;
}
V_7 = F_7 ( V_2 -> V_3 ) ;
if ( V_7 ) {
F_17 ( & V_36 -> V_18 , L_9 ) ;
return V_7 ;
}
V_37 = F_30 ( & V_36 -> V_18 , L_10 ,
V_2 , V_39 ) ;
if ( F_26 ( V_37 ) ) {
F_17 ( & V_36 -> V_18 , L_11 ) ;
F_6 ( V_2 -> V_3 ) ;
return F_27 ( V_37 ) ;
}
V_7 = F_18 ( & V_36 -> V_18 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_16 = V_2 -> V_14 ;
if ( F_31 ( V_40 ) ) {
V_25 = F_32 ( V_36 -> V_18 . V_30 ,
L_12 , V_2 ,
& V_41 ) ;
if ( F_26 ( V_25 ) ) {
F_17 ( & V_36 -> V_18 ,
L_13 ) ;
F_6 ( V_2 -> V_3 ) ;
return F_27 ( V_25 ) ;
}
V_2 -> V_25 = V_25 ;
F_33 ( V_25 ) ;
}
return 0 ;
}
static int F_34 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_35 ( V_36 ) ;
F_36 ( V_2 -> V_25 ) ;
if ( V_2 -> V_9 )
F_6 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_18 ) ;
if ( V_2 -> V_9 )
F_6 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_18 ) ;
struct V_4 V_5 ;
unsigned long V_6 ;
int V_7 ;
if ( V_2 -> V_9 == 0 )
return 0 ;
F_2 ( V_2 -> V_3 , & V_5 ) ;
V_6 = F_4 ( V_2 -> V_9 * ( V_5 . V_11 - 1 ) , V_12 ) ;
V_7 = F_5 ( V_2 -> V_3 , V_6 , V_5 . V_11 ) ;
if ( V_7 )
return V_7 ;
return F_7 ( V_2 -> V_3 ) ;
}
