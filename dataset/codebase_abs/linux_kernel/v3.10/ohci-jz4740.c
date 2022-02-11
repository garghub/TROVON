static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 -> V_4 ) ;
}
static inline struct V_2 * F_2 ( struct V_1 * V_5 )
{
return F_3 ( ( void * ) V_5 , struct V_2 , V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_5 ( V_3 ) ;
int V_8 ;
V_8 = F_6 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 -> V_9 = 1 ;
V_8 = F_7 ( V_7 ) ;
if ( V_8 < 0 ) {
F_8 ( V_3 -> V_10 . V_11 , L_1 ,
V_3 -> V_10 . V_12 ) ;
F_9 ( V_3 ) ;
return V_8 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_5 ,
bool V_13 )
{
int V_8 = 0 ;
if ( ! V_5 -> V_14 )
return 0 ;
if ( V_13 && ! V_5 -> V_15 ) {
V_8 = F_11 ( V_5 -> V_14 ) ;
if ( V_8 )
F_8 ( F_2 ( V_5 ) -> V_10 . V_11 ,
L_2 ) ;
} else if ( ! V_13 && V_5 -> V_15 ) {
V_8 = F_12 ( V_5 -> V_14 ) ;
}
if ( V_8 == 0 )
V_5 -> V_15 = V_13 ;
return V_8 ;
}
static int F_13 ( struct V_2 * V_3 , T_1 V_16 , T_1 V_17 ,
T_1 V_18 , char * V_19 , T_1 V_20 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_8 ;
switch ( V_16 ) {
case V_21 :
if ( V_17 == V_22 )
V_8 = F_10 ( V_5 , true ) ;
break;
case V_23 :
if ( V_17 == V_22 )
V_8 = F_10 ( V_5 , false ) ;
break;
}
if ( V_8 )
return V_8 ;
return F_14 ( V_3 , V_16 , V_17 , V_18 , V_19 , V_20 ) ;
}
static int F_15 ( struct V_24 * V_25 )
{
int V_8 ;
struct V_2 * V_3 ;
struct V_1 * V_5 ;
struct V_26 * V_27 ;
int V_28 ;
V_27 = F_16 ( V_25 , V_29 , 0 ) ;
if ( ! V_27 ) {
F_8 ( & V_25 -> V_30 , L_3 ) ;
return - V_31 ;
}
V_28 = F_17 ( V_25 , 0 ) ;
if ( V_28 < 0 ) {
F_8 ( & V_25 -> V_30 , L_4 ) ;
return V_28 ;
}
V_3 = F_18 ( & V_32 , & V_25 -> V_30 , L_5 ) ;
if ( ! V_3 ) {
F_8 ( & V_25 -> V_30 , L_6 ) ;
return - V_33 ;
}
V_5 = F_1 ( V_3 ) ;
V_27 = F_19 ( V_27 -> V_34 , F_20 ( V_27 ) , V_35 ) ;
if ( ! V_27 ) {
F_8 ( & V_25 -> V_30 , L_7 ) ;
V_8 = - V_36 ;
goto V_37;
}
V_3 -> V_38 = V_27 -> V_34 ;
V_3 -> V_39 = F_20 ( V_27 ) ;
V_3 -> V_40 = F_21 ( V_27 -> V_34 , F_20 ( V_27 ) ) ;
if ( ! V_3 -> V_40 ) {
F_8 ( & V_25 -> V_30 , L_8 ) ;
V_8 = - V_36 ;
goto V_41;
}
V_5 -> V_42 = F_22 ( & V_25 -> V_30 , L_9 ) ;
if ( F_23 ( V_5 -> V_42 ) ) {
V_8 = F_24 ( V_5 -> V_42 ) ;
F_8 ( & V_25 -> V_30 , L_10 , V_8 ) ;
goto V_43;
}
V_5 -> V_14 = F_25 ( & V_25 -> V_30 , L_11 ) ;
if ( F_23 ( V_5 -> V_14 ) )
V_5 -> V_14 = NULL ;
F_26 ( V_5 -> V_42 , 48000000 ) ;
F_27 ( V_5 -> V_42 ) ;
if ( V_5 -> V_14 )
F_10 ( V_5 , true ) ;
F_28 ( V_25 , V_3 ) ;
F_29 ( F_5 ( V_3 ) ) ;
V_8 = F_30 ( V_3 , V_28 , 0 ) ;
if ( V_8 ) {
F_8 ( & V_25 -> V_30 , L_12 , V_8 ) ;
goto V_44;
}
return 0 ;
V_44:
F_28 ( V_25 , NULL ) ;
if ( V_5 -> V_14 ) {
F_12 ( V_5 -> V_14 ) ;
F_31 ( V_5 -> V_14 ) ;
}
F_32 ( V_5 -> V_42 ) ;
F_33 ( V_5 -> V_42 ) ;
V_43:
F_34 ( V_3 -> V_40 ) ;
V_41:
F_35 ( V_27 -> V_34 , F_20 ( V_27 ) ) ;
V_37:
F_36 ( V_3 ) ;
return V_8 ;
}
static int F_37 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_38 ( V_25 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_39 ( V_3 ) ;
F_28 ( V_25 , NULL ) ;
if ( V_5 -> V_14 ) {
F_12 ( V_5 -> V_14 ) ;
F_31 ( V_5 -> V_14 ) ;
}
F_32 ( V_5 -> V_42 ) ;
F_33 ( V_5 -> V_42 ) ;
F_34 ( V_3 -> V_40 ) ;
F_35 ( V_3 -> V_38 , V_3 -> V_39 ) ;
F_36 ( V_3 ) ;
return 0 ;
}
