int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_2 V_5 ,
bool V_6 )
{
if ( ! V_2 || ! V_2 -> V_7 || ! V_2 -> V_7 -> V_8 )
return - V_9 ;
return V_2 -> V_7 -> V_8 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_3 F_2 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
return sprintf ( V_14 , L_1 , V_2 -> V_15 ) ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_17 * V_18 = & V_2 -> V_19 ;
int V_20 ;
V_20 = F_5 ( V_18 , V_16 , V_16 + 1 , V_21 ) ;
if ( V_20 < 0 ) {
F_6 ( & V_2 -> V_11 , L_2 , V_16 ) ;
return V_20 ;
}
return 0 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_17 * V_18 = & V_2 -> V_19 ;
F_8 ( V_18 , V_16 ) ;
}
int F_9 ( struct V_1 * V_2 , int V_16 ,
unsigned long V_22 )
{
struct V_17 * V_18 = & V_2 -> V_19 ;
int V_23 , V_24 ;
if ( V_2 -> V_7 -> V_25 )
return V_2 -> V_7 -> V_25 ( V_2 , V_16 , V_22 ) ;
if ( V_16 < 0 ) {
V_23 = 0 ;
V_24 = V_2 -> V_26 ;
} else if ( V_16 < V_2 -> V_26 ) {
V_23 = V_16 ;
V_24 = V_16 + 1 ;
} else {
F_6 ( & V_2 -> V_11 , L_3 , V_16 ) ;
return - V_9 ;
}
return F_5 ( V_18 , V_23 , V_24 , V_21 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_16 )
{
if ( V_2 -> V_7 -> V_27 ) {
V_2 -> V_7 -> V_27 ( V_2 , V_16 ) ;
return;
}
F_8 ( & V_2 -> V_19 , V_16 ) ;
}
static void F_11 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_28 )
F_13 ( V_2 -> V_28 ) ;
F_8 ( & V_29 , V_2 -> V_15 ) ;
F_14 ( & V_2 -> V_19 ) ;
F_15 ( V_2 ) ;
}
struct V_1 * F_16 ( struct V_30 * V_7 ,
struct V_10 * V_31 ,
T_4 V_32 ,
T_4 V_26 )
{
struct V_1 * V_2 ;
int V_20 ;
if ( ( ! V_7 -> V_33 ) || ( ! V_7 -> V_34 ) ) {
F_6 ( V_31 , L_4 ) ;
return F_17 ( - V_9 ) ;
}
if ( V_32 < V_35 ) {
F_6 ( V_31 , L_5 ) ;
return F_17 ( - V_9 ) ;
}
if ( V_26 == 0 || V_26 > V_36 + 1 ) {
F_6 ( V_31 , L_6 , V_26 ) ;
return F_17 ( - V_9 ) ;
}
if ( V_32 > V_37 ) {
F_18 ( V_31 , L_7 ,
V_37 ) ;
V_32 = V_37 ;
}
V_2 = F_19 ( sizeof( * V_2 ) + V_7 -> V_38 , V_21 ) ;
if ( ! V_2 )
return F_17 ( - V_39 ) ;
V_20 = F_5 ( & V_29 , 1 , 0 , V_21 ) ;
if ( V_20 < 0 ) {
F_15 ( V_2 ) ;
return F_17 ( V_20 ) ;
}
V_2 -> V_15 = V_20 ;
V_2 -> V_7 = V_7 ;
F_20 ( & V_2 -> V_40 ) ;
F_20 ( & V_2 -> V_41 ) ;
F_21 ( & V_2 -> V_19 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_11 . V_31 = V_31 ;
V_2 -> V_11 . V_42 = & V_43 ;
V_2 -> V_11 . type = & V_44 ;
V_2 -> V_11 . V_45 = V_46 ;
V_2 -> V_11 . V_47 = V_2 -> V_11 . V_31 -> V_47 ;
F_22 ( & V_2 -> V_11 ) ;
F_23 ( & V_2 -> V_11 , L_8 , V_2 -> V_15 ) ;
F_24 ( V_2 ) ;
V_2 -> V_28 = F_25 ( V_2 ) ;
if ( ! V_2 -> V_28 ) {
F_6 ( & V_2 -> V_11 , L_9 ) ;
F_26 ( & V_2 -> V_11 ) ;
return F_17 ( - V_39 ) ;
}
return V_2 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_28 ( & V_2 -> V_11 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_29 ( V_2 -> V_28 ) ;
if ( V_20 ) {
F_30 ( & V_2 -> V_11 ) ;
return V_20 ;
}
F_31 ( V_2 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_28 ) ;
F_30 ( & V_2 -> V_11 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_28 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_11 ) ;
}
int T_5 F_37 ( void )
{
F_21 ( & V_29 ) ;
return 0 ;
}
void F_38 ( void )
{
F_14 ( & V_29 ) ;
}
