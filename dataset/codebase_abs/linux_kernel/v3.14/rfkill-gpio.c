static int F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 ) {
F_2 ( V_4 -> V_5 , 0 ) ;
F_2 ( V_4 -> V_6 , 0 ) ;
if ( ! F_3 ( V_4 -> V_7 ) && V_4 -> V_8 )
F_4 ( V_4 -> V_7 ) ;
} else {
if ( ! F_3 ( V_4 -> V_7 ) && ! V_4 -> V_8 )
F_5 ( V_4 -> V_7 ) ;
F_2 ( V_4 -> V_6 , 1 ) ;
F_2 ( V_4 -> V_5 , 1 ) ;
}
V_4 -> V_8 = V_2 ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_3 * V_4 )
{
const struct V_11 * V_12 ;
V_12 = F_7 ( V_10 -> V_13 -> V_14 , V_10 ) ;
if ( ! V_12 )
return - V_15 ;
V_4 -> V_16 = F_8 ( V_10 ) ;
V_4 -> type = ( unsigned ) V_12 -> V_17 ;
return 0 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_10 . V_22 ;
struct V_3 * V_4 ;
const char * V_23 = NULL ;
struct V_24 * V_25 ;
int V_26 ;
int V_27 ;
V_4 = F_10 ( & V_19 -> V_10 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return - V_29 ;
if ( F_11 ( & V_19 -> V_10 ) ) {
V_26 = F_6 ( & V_19 -> V_10 , V_4 ) ;
if ( V_26 )
return V_26 ;
} else if ( V_21 ) {
V_23 = V_21 -> V_30 ;
V_4 -> V_16 = V_21 -> V_16 ;
V_4 -> type = V_21 -> type ;
} else {
return - V_15 ;
}
V_27 = strlen ( V_4 -> V_16 ) ;
V_4 -> V_31 = F_10 ( & V_19 -> V_10 , V_27 + 7 , V_28 ) ;
if ( ! V_4 -> V_31 )
return - V_29 ;
V_4 -> V_32 = F_10 ( & V_19 -> V_10 , V_27 + 10 , V_28 ) ;
if ( ! V_4 -> V_32 )
return - V_29 ;
snprintf ( V_4 -> V_31 , V_27 + 6 , L_1 , V_4 -> V_16 ) ;
snprintf ( V_4 -> V_32 , V_27 + 9 , L_2 , V_4 -> V_16 ) ;
V_4 -> V_7 = F_12 ( & V_19 -> V_10 , V_23 ) ;
V_25 = F_13 ( & V_19 -> V_10 , V_4 -> V_31 , 0 ) ;
if ( ! F_3 ( V_25 ) ) {
V_26 = F_14 ( V_25 , 0 ) ;
if ( V_26 )
return V_26 ;
V_4 -> V_6 = V_25 ;
}
V_25 = F_13 ( & V_19 -> V_10 , V_4 -> V_32 , 1 ) ;
if ( ! F_3 ( V_25 ) ) {
V_26 = F_14 ( V_25 , 0 ) ;
if ( V_26 )
return V_26 ;
V_4 -> V_5 = V_25 ;
}
if ( ( ! V_4 -> V_6 && ! V_4 -> V_5 ) || ! V_4 -> V_16 ) {
F_15 ( & V_19 -> V_10 , L_3 ) ;
return - V_33 ;
}
if ( V_21 && V_21 -> V_34 ) {
V_26 = V_21 -> V_34 ( V_19 ) ;
if ( V_26 ) {
F_15 ( & V_19 -> V_10 , L_4 ) ;
return V_26 ;
}
}
V_4 -> V_35 = F_16 ( V_4 -> V_16 , & V_19 -> V_10 ,
V_4 -> type , & V_36 ,
V_4 ) ;
if ( ! V_4 -> V_35 )
return - V_29 ;
V_26 = F_17 ( V_4 -> V_35 ) ;
if ( V_26 < 0 )
return V_26 ;
F_18 ( V_19 , V_4 ) ;
F_19 ( & V_19 -> V_10 , L_5 , V_4 -> V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_21 ( V_19 ) ;
struct V_20 * V_21 = V_19 -> V_10 . V_22 ;
if ( V_21 && V_21 -> V_37 )
V_21 -> V_37 ( V_19 ) ;
F_22 ( V_4 -> V_35 ) ;
F_23 ( V_4 -> V_35 ) ;
return 0 ;
}
