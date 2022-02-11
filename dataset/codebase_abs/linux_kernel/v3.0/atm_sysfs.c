static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> type ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
char * V_8 = V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < ( V_10 - 1 ) ; V_9 ++ )
V_8 += sprintf ( V_8 , L_2 , V_7 -> V_11 [ V_9 ] ) ;
V_8 += sprintf ( V_8 , L_3 , V_7 -> V_11 [ V_9 ] ) ;
return V_8 - V_5 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned long V_12 ;
char * V_8 = V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
int V_15 [] = { 1 , 2 , 10 , 6 , 1 } , * V_16 = V_15 ;
int V_9 , V_17 ;
F_5 ( & V_7 -> V_18 , V_12 ) ;
F_6 (aaddr, &adev->local, entry) {
for ( V_9 = 0 , V_17 = 0 ; V_9 < V_19 ; ++ V_9 , ++ V_17 ) {
if ( V_17 == * V_16 ) {
V_8 += sprintf ( V_8 , L_4 ) ;
++ V_16 ;
V_17 = 0 ;
}
V_8 += sprintf ( V_8 , L_5 ,
V_14 -> V_20 . V_21 . V_22 [ V_9 ] ) ;
}
V_8 += sprintf ( V_8 , L_6 ) ;
}
F_7 ( & V_7 -> V_18 , V_12 ) ;
return V_8 - V_5 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_7 , V_7 -> V_23 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
char * V_8 = V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_8 += sprintf ( V_8 , L_7 ,
V_7 -> signal == V_24 ? 0 : 1 ) ;
return V_8 - V_5 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
char * V_8 = V_5 ;
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
V_8 += sprintf ( V_8 , L_7 , V_25 ) ;
return V_8 - V_5 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return - V_31 ;
V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_31 ;
if ( F_12 ( V_30 , L_8 , V_7 -> type , V_7 -> V_23 ) )
return - V_32 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_14 ( V_7 ) ;
}
int F_15 ( struct V_6 * V_7 , struct V_1 * V_33 )
{
struct V_1 * V_2 = & V_7 -> V_34 ;
int V_9 , V_17 , V_35 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_33 = V_33 ;
F_16 ( V_2 , V_7 ) ;
F_17 ( V_2 , L_9 , V_7 -> type , V_7 -> V_23 ) ;
V_35 = F_18 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
for ( V_9 = 0 ; V_38 [ V_9 ] ; V_9 ++ ) {
V_35 = F_19 ( V_2 , V_38 [ V_9 ] ) ;
if ( V_35 )
goto V_39;
}
return 0 ;
V_39:
for ( V_17 = 0 ; V_17 < V_9 ; V_17 ++ )
F_20 ( V_2 , V_38 [ V_17 ] ) ;
F_21 ( V_2 ) ;
return V_35 ;
}
void F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_34 ;
F_21 ( V_2 ) ;
}
int T_2 F_23 ( void )
{
return F_24 ( & V_37 ) ;
}
void T_3 F_25 ( void )
{
F_26 ( & V_37 ) ;
}
