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
F_3 (win, resources) {
struct V_5 * V_15 , * V_16 = V_14 -> V_16 ;
switch ( F_4 ( V_16 ) ) {
case V_17 :
V_15 = & V_18 ;
V_7 = F_5 ( V_16 , V_12 ) ;
if ( V_7 ) {
F_6 ( V_2 , L_1 ,
V_7 , V_16 ) ;
continue;
}
break;
case V_19 :
V_15 = & V_20 ;
V_8 |= ! ( V_16 -> V_21 & V_22 ) ;
break;
case V_23 :
* V_6 = V_16 ;
default:
continue;
}
V_7 = F_7 ( V_2 , V_15 , V_16 ) ;
if ( V_7 )
goto V_24;
}
if ( ! V_8 ) {
F_8 ( V_2 , L_2 ) ;
V_7 = - V_25 ;
goto V_24;
}
return 0 ;
V_24:
return V_7 ;
}
static void F_9 ( void * V_26 )
{
F_10 ( (struct V_27 * ) V_26 ) ;
}
static struct V_27 * F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_28 * V_29 )
{
int V_7 ;
struct V_5 V_30 ;
struct V_5 * V_6 = NULL ;
struct V_27 * V_31 ;
V_7 = F_1 ( V_2 , V_4 , & V_6 ) ;
if ( V_7 )
goto V_32;
V_7 = F_12 ( V_2 -> V_11 , 0 , & V_30 ) ;
if ( V_7 ) {
F_8 ( V_2 , L_3 ) ;
goto V_32;
}
V_31 = F_13 ( V_2 , & V_30 , V_6 , V_29 ) ;
if ( F_14 ( V_31 ) ) {
V_7 = F_15 ( V_31 ) ;
goto V_32;
}
V_7 = F_16 ( V_2 , F_9 , V_31 ) ;
if ( V_7 ) {
F_9 ( V_31 ) ;
goto V_32;
}
return V_31 ;
V_32:
F_17 ( V_4 ) ;
return F_18 ( V_7 ) ;
}
int F_19 ( struct V_33 * V_34 ,
struct V_28 * V_29 )
{
const char * type ;
struct V_1 * V_2 = & V_34 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_35 * V_36 , * V_37 ;
struct V_27 * V_31 ;
struct V_3 V_4 ;
type = F_20 ( V_10 , L_4 , NULL ) ;
if ( ! type || strcmp ( type , L_5 ) ) {
F_8 ( V_2 , L_6 , type ) ;
return - V_25 ;
}
F_21 () ;
F_22 ( & V_4 ) ;
V_31 = F_11 ( V_2 , & V_4 , V_29 ) ;
if ( F_14 ( V_31 ) )
return F_15 ( V_31 ) ;
if ( ! F_23 ( V_38 ) )
F_24 ( V_39 | V_40 ) ;
V_36 = F_25 ( V_2 , V_31 -> V_41 . V_42 , & V_29 -> V_43 , V_31 ,
& V_4 ) ;
if ( ! V_36 ) {
F_8 ( V_2 , L_7 ) ;
return - V_44 ;
}
F_26 ( V_45 , V_46 ) ;
if ( ! F_23 ( V_38 ) ) {
F_27 ( V_36 ) ;
F_28 ( V_36 ) ;
F_29 (child, &bus->children, node)
F_30 ( V_37 ) ;
}
F_31 ( V_36 ) ;
return 0 ;
}
