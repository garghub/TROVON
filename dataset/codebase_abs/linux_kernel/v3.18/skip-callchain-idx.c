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
V_7 = F_9 ( V_15 , V_13 , & V_2 ) ;
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
V_7 = F_9 ( V_15 , V_13 , & V_2 ) ;
if ( V_7 ) {
F_3 ( L_4 , V_16 , F_8 ( - 1 ) ) ;
return NULL ;
}
return V_2 ;
}
static int F_12 ( const char * V_17 , T_5 V_13 )
{
int V_18 = - 1 ;
T_7 * V_19 ;
T_4 * V_12 ;
T_1 * V_2 ;
int V_1 ;
T_5 V_20 = V_13 ;
T_5 V_21 = V_13 ;
bool V_22 ;
V_19 = F_13 ( & V_23 ) ;
if ( ! V_19 ) {
F_3 ( L_5 , F_4 ( - 1 ) ) ;
return - 1 ;
}
if ( F_14 ( V_19 , L_6 , V_17 , - 1 ) == NULL ) {
F_3 ( L_7 , F_4 ( - 1 ) ) ;
goto V_24;
}
V_12 = F_15 ( V_19 , V_13 ) ;
if ( ! V_12 ) {
F_3 ( L_8 , F_4 ( - 1 ) ) ;
goto V_24;
}
V_2 = F_6 ( V_12 , V_13 ) ;
if ( ! V_2 ) {
V_2 = F_10 ( V_12 , V_13 ) ;
if ( ! V_2 )
goto V_24;
}
V_1 = F_16 ( V_2 , & V_20 , & V_21 , & V_22 ) ;
if ( V_1 < 0 ) {
F_3 ( L_9 ,
F_4 ( - 1 ) ) ;
goto V_24;
}
V_18 = F_1 ( V_1 , V_2 ) ;
V_24:
F_17 ( V_19 ) ;
return V_18 ;
}
int F_18 ( struct V_25 * V_25 , struct V_26 * V_26 ,
struct V_27 * V_28 )
{
struct V_29 V_30 ;
struct V_31 * V_31 = NULL ;
int V_18 ;
T_8 V_32 ;
T_8 V_33 = - 1 ;
if ( V_28 -> V_34 < 3 )
return V_33 ;
V_32 = V_28 -> V_35 [ 2 ] ;
F_19 ( V_26 , V_25 , V_36 ,
V_37 , V_32 , & V_30 ) ;
if ( V_30 . V_38 )
V_31 = V_30 . V_38 -> V_31 ;
if ( ! V_31 ) {
F_3 ( L_10 V_39 L_11 , V_32 ) ;
return V_33 ;
}
V_18 = F_12 ( V_31 -> V_40 , V_32 ) ;
F_3 ( L_12 V_39 L_13 V_39 L_14 ,
V_31 -> V_40 , V_28 -> V_34 , V_32 , V_18 ) ;
if ( V_18 == 0 ) {
V_33 = 2 ;
} else if ( V_18 == 2 ) {
V_33 = 3 ;
}
return V_33 ;
}
