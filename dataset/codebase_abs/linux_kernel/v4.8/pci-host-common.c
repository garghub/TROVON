static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * * V_6 )
{
int V_7 , V_8 = 0 ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_12 ;
struct V_13 * V_14 ;
V_7 = F_2 ( V_10 , 0 , 0xff , V_4 , & V_12 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
F_4 (win, resources) {
struct V_5 * V_15 = V_14 -> V_15 ;
switch ( F_5 ( V_15 ) ) {
case V_16 :
V_7 = F_6 ( V_15 , V_12 ) ;
if ( V_7 )
F_7 ( V_2 , L_1 ,
V_7 , V_15 ) ;
break;
case V_17 :
V_8 |= ! ( V_15 -> V_18 & V_19 ) ;
break;
case V_20 :
* V_6 = V_15 ;
break;
}
}
if ( V_8 )
return 0 ;
F_8 ( V_2 , L_2 ) ;
return - V_21 ;
}
static void F_9 ( void * V_22 )
{
F_10 ( (struct V_23 * ) V_22 ) ;
}
static struct V_23 * F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_24 * V_25 )
{
int V_7 ;
struct V_5 V_26 ;
struct V_5 * V_6 = NULL ;
struct V_23 * V_27 ;
V_7 = F_1 ( V_2 , V_4 , & V_6 ) ;
if ( V_7 )
goto V_28;
V_7 = F_12 ( V_2 -> V_11 , 0 , & V_26 ) ;
if ( V_7 ) {
F_8 ( V_2 , L_3 ) ;
goto V_28;
}
V_27 = F_13 ( V_2 , & V_26 , V_6 , V_25 ) ;
if ( F_14 ( V_27 ) ) {
V_7 = F_15 ( V_27 ) ;
goto V_28;
}
V_7 = F_16 ( V_2 , F_9 , V_27 ) ;
if ( V_7 ) {
F_9 ( V_27 ) ;
goto V_28;
}
return V_27 ;
V_28:
F_17 ( V_4 ) ;
return F_18 ( V_7 ) ;
}
int F_19 ( struct V_29 * V_30 ,
struct V_24 * V_25 )
{
const char * type ;
struct V_1 * V_2 = & V_30 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_31 * V_32 , * V_33 ;
struct V_23 * V_27 ;
struct V_3 V_4 ;
type = F_20 ( V_10 , L_4 , NULL ) ;
if ( ! type || strcmp ( type , L_5 ) ) {
F_8 ( V_2 , L_6 , type ) ;
return - V_21 ;
}
F_21 () ;
F_22 ( & V_4 ) ;
V_27 = F_11 ( V_2 , & V_4 , V_25 ) ;
if ( F_14 ( V_27 ) )
return F_15 ( V_27 ) ;
if ( ! F_23 ( V_34 ) )
F_24 ( V_35 | V_36 ) ;
V_32 = F_25 ( V_2 , V_27 -> V_37 . V_38 , & V_25 -> V_39 , V_27 ,
& V_4 ) ;
if ( ! V_32 ) {
F_8 ( V_2 , L_7 ) ;
return - V_40 ;
}
F_26 ( V_41 , V_42 ) ;
if ( F_23 ( V_34 ) ) {
F_27 ( V_32 ) ;
} else {
F_28 ( V_32 ) ;
F_29 ( V_32 ) ;
F_30 (child, &bus->children, node)
F_31 ( V_33 ) ;
}
F_32 ( V_32 ) ;
return 0 ;
}
