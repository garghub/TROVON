static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * * V_6 )
{
int V_7 , V_8 = 0 ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_12 ;
struct V_13 * V_14 , * V_15 ;
V_7 = F_2 ( V_10 , 0 , 0xff , V_4 , & V_12 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
F_4 (win, tmp, resources) {
struct V_5 * V_16 = V_14 -> V_16 ;
switch ( F_5 ( V_16 ) ) {
case V_17 :
V_7 = F_6 ( V_16 , V_12 ) ;
if ( V_7 ) {
F_7 ( V_2 , L_1 ,
V_7 , V_16 ) ;
F_8 ( V_14 ) ;
}
break;
case V_18 :
V_8 |= ! ( V_16 -> V_19 & V_20 ) ;
break;
case V_21 :
* V_6 = V_16 ;
break;
}
}
if ( V_8 )
return 0 ;
F_9 ( V_2 , L_2 ) ;
return - V_22 ;
}
static void F_10 ( void * V_23 )
{
F_11 ( (struct V_24 * ) V_23 ) ;
}
static struct V_24 * F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_25 * V_26 )
{
int V_7 ;
struct V_5 V_27 ;
struct V_5 * V_6 = NULL ;
struct V_24 * V_28 ;
V_7 = F_1 ( V_2 , V_4 , & V_6 ) ;
if ( V_7 )
goto V_29;
V_7 = F_13 ( V_2 -> V_11 , 0 , & V_27 ) ;
if ( V_7 ) {
F_9 ( V_2 , L_3 ) ;
goto V_29;
}
V_28 = F_14 ( V_2 , & V_27 , V_6 , V_26 ) ;
if ( F_15 ( V_28 ) ) {
V_7 = F_16 ( V_28 ) ;
goto V_29;
}
V_7 = F_17 ( V_2 , F_10 , V_28 ) ;
if ( V_7 ) {
F_10 ( V_28 ) ;
goto V_29;
}
return V_28 ;
V_29:
F_18 ( V_4 ) ;
return F_19 ( V_7 ) ;
}
int F_20 ( struct V_30 * V_31 ,
struct V_25 * V_26 )
{
const char * type ;
struct V_1 * V_2 = & V_31 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_32 * V_33 , * V_34 ;
struct V_24 * V_28 ;
struct V_3 V_4 ;
type = F_21 ( V_10 , L_4 , NULL ) ;
if ( ! type || strcmp ( type , L_5 ) ) {
F_9 ( V_2 , L_6 , type ) ;
return - V_22 ;
}
F_22 () ;
F_23 ( & V_4 ) ;
V_28 = F_12 ( V_2 , & V_4 , V_26 ) ;
if ( F_15 ( V_28 ) )
return F_16 ( V_28 ) ;
if ( ! F_24 ( V_35 ) )
F_25 ( V_36 | V_37 ) ;
V_33 = F_26 ( V_2 , V_28 -> V_38 . V_39 , & V_26 -> V_40 , V_28 ,
& V_4 ) ;
if ( ! V_33 ) {
F_9 ( V_2 , L_7 ) ;
return - V_41 ;
}
#ifdef F_27
F_28 ( V_42 , V_43 ) ;
#endif
if ( F_24 ( V_35 ) ) {
F_29 ( V_33 ) ;
} else {
F_30 ( V_33 ) ;
F_31 ( V_33 ) ;
F_32 (child, &bus->children, node)
F_33 ( V_34 ) ;
}
F_34 ( V_33 ) ;
return 0 ;
}
