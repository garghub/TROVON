static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , V_11 , V_11 ,
32768 , F_3 ( V_4 ) * 256 ) ;
if ( V_10 < 0 ) {
F_4 ( L_1 , V_12 ) ;
return V_10 ;
}
V_10 = F_5 ( V_9 , V_13 ,
0 , V_14 ) ;
if ( V_10 < 0 ) {
F_4 ( L_2 , V_12 ) ;
return V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
enum V_19 V_20 )
{
if ( V_18 -> V_21 == V_22 ) {
switch ( V_20 ) {
case V_23 :
F_7 ( V_24 ) ;
break;
case V_25 :
F_8 ( V_24 ) ;
break;
default:
break;
}
}
return 0 ;
}
static int F_9 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 . V_31 ;
struct V_28 * V_32 , * V_33 ;
struct V_15 * V_16 = & V_34 ;
struct V_35 * V_36 = & V_37 ;
int V_10 ;
if ( ! V_29 ) {
F_10 ( & V_27 -> V_30 , L_3 ) ;
return - V_38 ;
}
V_10 = F_11 ( V_16 , L_4 ) ;
if ( V_10 ) {
F_10 ( & V_27 -> V_30 , L_5 ) ;
return V_10 ;
}
V_10 = F_12 ( V_16 , L_6 ) ;
if ( V_10 ) {
F_10 ( & V_27 -> V_30 , L_7 ) ;
return V_10 ;
}
V_33 = F_13 ( V_29 , L_8 , 0 ) ;
if ( ! V_33 ) {
F_10 ( & V_27 -> V_30 , L_9 ) ;
V_10 = - V_38 ;
return V_10 ;
}
V_36 -> V_39 = V_33 ;
V_36 -> V_40 = V_33 ;
F_14 ( V_33 ) ;
V_32 = F_13 ( V_29 , L_10 , 0 ) ;
if ( ! V_32 ) {
F_10 ( & V_27 -> V_30 , L_11 ) ;
V_10 = - V_38 ;
return V_10 ;
}
V_36 -> V_41 = V_32 ;
F_14 ( V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_15 * V_16 = & V_34 ;
struct V_35 * V_36 = & V_37 ;
struct V_42 * V_43 ;
struct V_44 * V_44 ;
int V_45 , V_10 ;
V_44 = F_16 ( & V_27 -> V_30 ) ;
if ( F_17 ( V_44 ) ) {
F_10 ( & V_27 -> V_30 , L_12 ) ;
return F_18 ( V_44 ) ;
}
V_16 -> V_30 = & V_27 -> V_30 ;
V_10 = F_9 ( V_27 ) ;
if ( V_10 ) {
F_10 ( & V_27 -> V_30 , L_13 ) ;
return V_10 ;
}
V_45 = F_19 ( (struct V_28 * ) V_36 -> V_39 , L_14 ) ;
V_10 = F_20 ( V_45 ) ;
if ( V_10 != 0 ) {
F_10 ( & V_27 -> V_30 , L_15 , V_45 ) ;
return V_10 ;
}
V_24 = F_21 ( NULL , L_16 ) ;
if ( F_17 ( V_24 ) ) {
F_10 ( & V_27 -> V_30 , L_17 ) ;
V_10 = F_18 ( V_24 ) ;
goto V_46;
}
V_43 = F_21 ( NULL , L_18 ) ;
if ( F_17 ( V_43 ) ) {
F_10 ( & V_27 -> V_30 , L_19 ) ;
V_10 = F_18 ( V_43 ) ;
goto V_46;
}
V_10 = F_22 ( V_24 , V_43 ) ;
F_23 ( V_43 ) ;
if ( V_10 != 0 ) {
F_10 ( & V_27 -> V_30 , L_20 ) ;
goto V_46;
}
F_24 ( & V_27 -> V_30 , L_21 , V_47 ) ;
F_25 ( V_24 , V_47 ) ;
V_10 = F_26 ( V_16 ) ;
if ( V_10 ) {
F_10 ( & V_27 -> V_30 , L_22 ) ;
goto V_46;
}
return 0 ;
V_46:
F_27 ( V_45 ) ;
return V_10 ;
}
static int F_28 ( struct V_26 * V_27 )
{
struct V_15 * V_16 = F_29 ( V_27 ) ;
struct V_35 * V_36 = & V_37 ;
int V_45 ;
V_45 = F_19 ( (struct V_28 * ) V_36 -> V_39 , L_14 ) ;
F_30 ( V_16 ) ;
F_27 ( V_45 ) ;
return 0 ;
}
