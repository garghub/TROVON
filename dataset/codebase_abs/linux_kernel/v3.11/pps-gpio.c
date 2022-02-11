static T_1 F_1 ( int V_1 , void * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 ;
F_2 ( & V_6 ) ;
V_4 = V_2 ;
V_7 = F_3 ( V_4 -> V_8 ) ;
if ( ( V_7 && ! V_4 -> V_9 ) ||
( ! V_7 && V_4 -> V_9 ) )
F_4 ( V_4 -> V_10 , & V_6 , V_11 , NULL ) ;
else if ( V_4 -> V_12 &&
( ( V_7 && V_4 -> V_9 ) ||
( ! V_7 && ! V_4 -> V_9 ) ) )
F_4 ( V_4 -> V_10 , & V_6 , V_13 , NULL ) ;
return V_14 ;
}
static unsigned long
F_5 ( const struct V_3 * V_2 )
{
unsigned long V_15 = V_2 -> V_9 ?
V_16 : V_17 ;
if ( V_2 -> V_12 ) {
V_15 |= ( ( V_15 & V_17 ) ?
V_16 : V_17 ) ;
}
return V_15 ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_3 * V_2 ;
const char * V_20 ;
int V_21 ;
int V_22 ;
const struct V_23 * V_24 = V_19 -> V_25 . V_26 ;
struct V_27 * V_28 = V_19 -> V_25 . V_29 ;
V_2 = F_7 ( & V_19 -> V_25 , sizeof( struct V_3 ) ,
V_30 ) ;
if ( ! V_2 )
return - V_31 ;
if ( V_24 ) {
V_2 -> V_8 = V_24 -> V_8 ;
V_20 = V_24 -> V_20 ;
V_2 -> V_9 = V_24 -> V_9 ;
V_2 -> V_12 = V_24 -> V_12 ;
} else {
V_21 = F_8 ( V_28 , 0 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_19 -> V_25 , L_1 ) ;
return V_21 ;
}
V_2 -> V_8 = V_21 ;
V_20 = V_32 ;
if ( F_10 ( V_28 , L_2 , NULL ) )
V_2 -> V_9 = true ;
}
V_21 = F_11 ( & V_19 -> V_25 , V_2 -> V_8 , V_20 ) ;
if ( V_21 ) {
F_9 ( & V_19 -> V_25 , L_3 ,
V_2 -> V_8 ) ;
return V_21 ;
}
V_21 = F_12 ( V_2 -> V_8 ) ;
if ( V_21 ) {
F_9 ( & V_19 -> V_25 , L_4 ) ;
return - V_33 ;
}
V_21 = F_13 ( V_2 -> V_8 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_19 -> V_25 , L_5 , V_21 ) ;
return - V_33 ;
}
V_2 -> V_1 = V_21 ;
V_2 -> V_4 . V_34 = V_11 | V_35 |
V_36 | V_37 | V_38 ;
if ( V_2 -> V_12 )
V_2 -> V_4 . V_34 |= V_13 | V_39 |
V_40 ;
V_2 -> V_4 . V_41 = V_42 ;
snprintf ( V_2 -> V_4 . V_43 , V_44 - 1 , L_6 ,
V_19 -> V_43 , V_19 -> V_45 ) ;
V_22 = V_11 | V_35 ;
if ( V_2 -> V_12 )
V_22 |= V_13 | V_39 ;
V_2 -> V_10 = F_14 ( & V_2 -> V_4 , V_22 ) ;
if ( V_2 -> V_10 == NULL ) {
F_9 ( & V_19 -> V_25 , L_7 ,
V_2 -> V_1 ) ;
return - V_33 ;
}
V_21 = F_15 ( & V_19 -> V_25 , V_2 -> V_1 , F_1 ,
F_5 ( V_2 ) , V_2 -> V_4 . V_43 , V_2 ) ;
if ( V_21 ) {
F_16 ( V_2 -> V_10 ) ;
F_9 ( & V_19 -> V_25 , L_8 , V_2 -> V_1 ) ;
return - V_33 ;
}
F_17 ( V_19 , V_2 ) ;
F_18 ( V_2 -> V_10 -> V_25 , L_9 ,
V_2 -> V_1 ) ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_3 * V_2 = F_20 ( V_19 ) ;
F_17 ( V_19 , NULL ) ;
F_16 ( V_2 -> V_10 ) ;
F_18 ( & V_19 -> V_25 , L_10 , V_2 -> V_1 ) ;
return 0 ;
}
