struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static int F_3 ( struct V_1 * V_7 )
{
int V_8 ;
if ( ! V_7 )
return 0 ;
V_8 = F_4 ( V_7 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_5 ( V_7 , & V_7 -> V_9 -> V_3 ,
V_10 ) ;
if ( V_8 ) {
F_6 ( V_7 ) ;
return V_8 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_7 )
{
if ( ! V_7 )
return;
F_8 ( V_7 ) ;
F_6 ( V_7 ) ;
}
static int F_9 ( struct V_11 * V_9 ,
const struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
int V_8 , V_16 ;
T_1 V_17 ;
T_2 V_18 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return - V_20 ;
for ( V_16 = 0 ; V_16 < V_9 -> V_21 ; V_16 ++ ) {
V_15 = & V_9 -> V_15 [ V_16 ] ;
V_17 = F_11 ( V_15 -> V_13 ) ;
V_18 = V_15 -> V_18 ;
switch ( V_18 ) {
case V_22 :
if ( V_5 -> V_6 ) {
F_12 ( & V_9 -> V_3 ,
L_1 ) ;
V_8 = - V_23 ;
goto V_24;
}
V_7 = F_13 ( V_9 , V_17 ,
V_25 ) ;
if ( F_14 ( V_7 ) ) {
V_8 = F_15 ( V_7 ) ;
F_12 ( & V_9 -> V_3 ,
L_2 ,
V_8 ) ;
goto V_24;
}
V_5 -> V_6 = V_7 ;
break;
case V_26 :
if ( V_5 -> V_27 ) {
F_12 ( & V_9 -> V_3 ,
L_3 ) ;
V_8 = - V_23 ;
goto V_24;
}
V_7 = F_13 ( V_9 , V_17 ,
V_28 ) ;
if ( F_14 ( V_7 ) ) {
F_12 ( & V_9 -> V_3 , L_4 ,
F_15 ( V_7 ) ) ;
} else {
V_5 -> V_27 = V_7 ;
}
break;
case V_29 :
if ( V_5 -> V_30 ) {
F_12 ( & V_9 -> V_3 ,
L_5 ) ;
V_8 = - V_23 ;
goto V_24;
}
V_7 = F_13 ( V_9 , V_17 ,
NULL ) ;
if ( F_14 ( V_7 ) ) {
F_12 ( & V_9 -> V_3 , L_6 ,
F_15 ( V_7 ) ) ;
} else {
V_5 -> V_30 = V_7 ;
}
break;
case V_31 :
if ( V_5 -> V_32 ) {
F_12 ( & V_9 -> V_3 , L_7 ) ;
V_8 = - V_23 ;
goto V_24;
}
V_7 = F_13 ( V_9 , V_17 ,
NULL ) ;
if ( F_14 ( V_7 ) ) {
F_12 ( & V_9 -> V_3 , L_8 ,
F_15 ( V_7 ) ) ;
} else {
V_5 -> V_32 = V_7 ;
}
break;
default:
F_12 ( & V_9 -> V_3 , L_9 ,
V_18 ) ;
V_8 = - V_23 ;
goto V_24;
}
}
if ( ! V_5 -> V_6 ) {
F_12 ( & V_9 -> V_3 , L_10 ) ;
V_8 = - V_33 ;
goto V_24;
}
V_8 = F_16 ( V_5 -> V_27 ) ;
if ( V_8 ) {
F_12 ( & V_9 -> V_3 , L_11 ,
V_8 ) ;
F_17 ( V_5 -> V_27 ) ;
V_5 -> V_27 = NULL ;
}
V_8 = F_3 ( V_5 -> V_30 ) ;
if ( V_8 ) {
F_12 ( & V_9 -> V_3 , L_12 ,
V_8 ) ;
F_17 ( V_5 -> V_30 ) ;
V_5 -> V_30 = NULL ;
}
V_8 = F_18 ( V_5 -> V_32 ) ;
if ( V_8 ) {
F_12 ( & V_9 -> V_3 , L_13 ,
V_8 ) ;
F_17 ( V_5 -> V_32 ) ;
V_5 -> V_32 = NULL ;
}
V_8 = F_19 ( V_5 -> V_6 ) ;
if ( V_8 ) {
F_12 ( & V_9 -> V_3 , L_14 ,
V_8 ) ;
goto V_34;
}
F_20 ( V_9 , V_5 ) ;
if ( ! ( V_9 -> V_35 -> V_36 & V_37 ) )
F_21 ( V_9 ) ;
return 0 ;
V_34:
F_22 ( V_5 -> V_32 ) ;
F_7 ( V_5 -> V_30 ) ;
F_23 ( V_5 -> V_27 ) ;
V_24:
F_17 ( V_5 -> V_6 ) ;
F_17 ( V_5 -> V_32 ) ;
F_17 ( V_5 -> V_30 ) ;
F_17 ( V_5 -> V_27 ) ;
F_24 ( V_5 ) ;
return V_8 ;
}
static void F_25 ( struct V_11 * V_9 )
{
struct V_4 * V_5 = F_26 ( V_9 ) ;
int V_8 ;
if ( ! ( V_9 -> V_35 -> V_36 & V_37 ) ) {
V_8 = F_27 ( V_9 ) ;
if ( V_8 )
F_28 ( V_9 ) ;
}
F_29 ( V_5 -> V_6 ) ;
F_22 ( V_5 -> V_32 ) ;
F_7 ( V_5 -> V_30 ) ;
F_23 ( V_5 -> V_27 ) ;
F_17 ( V_5 -> V_6 ) ;
F_17 ( V_5 -> V_32 ) ;
F_17 ( V_5 -> V_30 ) ;
F_17 ( V_5 -> V_27 ) ;
F_24 ( V_5 ) ;
}
static int F_30 ( void )
{
int V_8 ;
V_8 = F_31 () ;
if ( V_8 ) {
F_32 ( L_15 , V_8 ) ;
return V_8 ;
}
V_8 = F_33 () ;
if ( V_8 ) {
F_32 ( L_16 ,
V_8 ) ;
goto V_38;
}
V_8 = F_34 ( & V_39 ) ;
if ( V_8 )
goto V_40;
return 0 ;
V_40:
V_40 () ;
V_38:
V_38 () ;
return V_8 ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_39 ) ;
V_40 () ;
V_38 () ;
}
