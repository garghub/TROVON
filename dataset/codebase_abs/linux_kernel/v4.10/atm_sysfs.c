static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_8 , L_1 , V_7 -> type ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_8 , L_2 , V_7 -> V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned long V_10 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_13 [] = { 1 , 2 , 10 , 6 , 1 } , * V_14 = V_13 ;
int V_15 , V_16 , V_17 = 0 ;
F_6 ( & V_7 -> V_18 , V_10 ) ;
F_7 (aaddr, &adev->local, entry) {
for ( V_15 = 0 , V_16 = 0 ; V_15 < V_19 ; ++ V_15 , ++ V_16 ) {
if ( V_16 == * V_14 ) {
V_17 += F_3 ( V_5 + V_17 ,
V_8 - V_17 , L_3 ) ;
++ V_14 ;
V_16 = 0 ;
}
V_17 += F_3 ( V_5 + V_17 ,
V_8 - V_17 , L_4 ,
V_12 -> V_20 . V_21 . V_22 [ V_15 ] ) ;
}
V_17 += F_3 ( V_5 + V_17 , V_8 - V_17 , L_5 ) ;
}
F_8 ( & V_7 -> V_18 , V_10 ) ;
return V_17 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_8 , L_6 , V_7 -> V_23 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_8 , L_6 ,
V_7 -> signal == V_24 ? 0 : 1 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_25 ;
switch ( V_7 -> V_25 ) {
case V_26 :
V_25 = 155520000 ;
break;
case V_27 :
V_25 = 622080000 ;
break;
case V_28 :
V_25 = 25600000 ;
break;
default:
V_25 = V_7 -> V_25 * 8 * 53 ;
}
return F_3 ( V_5 , V_8 , L_6 , V_25 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return - V_31 ;
V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_31 ;
if ( F_13 ( V_30 , L_7 , V_7 -> type , V_7 -> V_23 ) )
return - V_32 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_15 ( V_7 ) ;
}
int F_16 ( struct V_6 * V_7 , struct V_1 * V_33 )
{
struct V_1 * V_2 = & V_7 -> V_34 ;
int V_15 , V_16 , V_35 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_33 = V_33 ;
F_17 ( V_2 , V_7 ) ;
F_18 ( V_2 , L_8 , V_7 -> type , V_7 -> V_23 ) ;
V_35 = F_19 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
for ( V_15 = 0 ; V_38 [ V_15 ] ; V_15 ++ ) {
V_35 = F_20 ( V_2 , V_38 [ V_15 ] ) ;
if ( V_35 )
goto V_39;
}
return 0 ;
V_39:
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
F_21 ( V_2 , V_38 [ V_16 ] ) ;
F_22 ( V_2 ) ;
return V_35 ;
}
void F_23 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_34 ;
F_22 ( V_2 ) ;
}
int T_2 F_24 ( void )
{
return F_25 ( & V_37 ) ;
}
void T_3 F_26 ( void )
{
F_27 ( & V_37 ) ;
}
