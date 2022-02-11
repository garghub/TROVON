static int F_1 ( int V_1 , T_1 * V_2 )
{
T_2 V_3 [ 2 ] ;
T_2 V_4 ;
T_2 * V_5 = & V_4 ;
T_3 V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , V_1 , V_3 , & V_5 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( L_1 , F_4 ( - 1 ) ) ;
return - 1 ;
}
if ( V_6 != 0 || V_5 != NULL )
return 0 ;
V_7 = F_5 ( V_2 , & V_5 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( L_2 , V_7 ,
F_4 ( - 1 ) ) ;
return - 1 ;
}
if ( V_6 == 1 && V_5 [ 0 ] . V_8 == V_9 && V_5 [ 0 ] . V_10 == 1 &&
V_5 [ 0 ] . V_11 == 0 )
return 1 ;
return 2 ;
}
static T_1 * F_6 ( T_4 * V_12 , T_5 V_13 )
{
int V_7 ;
T_5 V_14 ;
T_6 * V_15 ;
T_1 * V_2 ;
V_15 = F_7 ( V_12 , & V_14 ) ;
if ( ! V_15 ) {
F_3 ( L_3 , V_16 , F_8 ( - 1 ) ) ;
return NULL ;
}
V_7 = F_9 ( V_15 , V_13 - V_14 , & V_2 ) ;
if ( V_7 ) {
F_3 ( L_4 , V_16 , F_8 ( - 1 ) ) ;
return NULL ;
}
return V_2 ;
}
static T_1 * F_10 ( T_4 * V_12 , T_5 V_13 )
{
T_6 * V_15 ;
T_5 V_14 ;
T_1 * V_2 ;
int V_7 ;
V_15 = F_11 ( V_12 , & V_14 ) ;
if ( ! V_15 ) {
F_3 ( L_3 , V_16 , F_8 ( - 1 ) ) ;
return NULL ;
}
V_7 = F_9 ( V_15 , V_13 - V_14 , & V_2 ) ;
if ( V_7 ) {
F_3 ( L_4 , V_16 , F_8 ( - 1 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_12 ( struct V_17 * V_17 , T_7 V_18 , T_5 V_13 )
{
int V_19 = - 1 ;
T_8 * V_20 ;
T_4 * V_12 ;
T_1 * V_2 ;
int V_1 ;
T_5 V_21 = V_13 ;
T_5 V_22 = V_13 ;
bool V_23 ;
const char * V_24 = V_17 -> V_25 ;
V_20 = V_17 -> V_20 ;
if ( ! V_20 ) {
V_20 = F_13 ( & V_26 ) ;
if ( ! V_20 ) {
F_3 ( L_5 , F_4 ( - 1 ) ) ;
return - 1 ;
}
V_12 = F_14 ( V_20 , V_24 , V_24 , - 1 ,
V_18 , false ) ;
if ( ! V_12 ) {
F_3 ( L_6 ,
F_4 ( - 1 ) ) ;
F_15 ( V_20 ) ;
goto V_27;
}
V_17 -> V_20 = V_20 ;
}
V_12 = F_16 ( V_20 , V_13 ) ;
if ( ! V_12 ) {
F_3 ( L_7 , F_4 ( - 1 ) ) ;
goto V_27;
}
V_2 = F_6 ( V_12 , V_13 ) ;
if ( ! V_2 ) {
V_2 = F_10 ( V_12 , V_13 ) ;
if ( ! V_2 )
goto V_27;
}
V_1 = F_17 ( V_2 , & V_21 , & V_22 , & V_23 ) ;
if ( V_1 < 0 ) {
F_3 ( L_8 ,
F_4 ( - 1 ) ) ;
goto V_27;
}
V_19 = F_1 ( V_1 , V_2 ) ;
V_27:
return V_19 ;
}
int F_18 ( struct V_28 * V_28 , struct V_29 * V_30 )
{
struct V_31 V_32 ;
struct V_17 * V_17 = NULL ;
int V_19 ;
T_7 V_33 ;
T_7 V_34 = - 1 ;
if ( V_30 -> V_35 < 3 )
return V_34 ;
V_33 = V_30 -> V_36 [ 2 ] ;
F_19 ( V_28 , V_37 ,
V_38 , V_33 , & V_32 ) ;
if ( V_32 . V_39 )
V_17 = V_32 . V_39 -> V_17 ;
if ( ! V_17 ) {
F_3 ( L_9 V_40 L_10 , V_33 ) ;
return V_34 ;
}
V_19 = F_12 ( V_17 , V_32 . V_39 -> V_21 , V_33 ) ;
F_3 ( L_11 V_40 L_12 ,
V_17 -> V_25 , V_32 . V_41 -> V_42 , V_33 , V_19 ) ;
if ( V_19 == 0 ) {
V_34 = 2 ;
} else if ( V_19 == 2 ) {
V_34 = 3 ;
}
return V_34 ;
}
