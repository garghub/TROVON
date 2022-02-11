int F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 ,
unsigned long * V_5 , T_1 * V_6 , T_2 * V_7 )
{
const T_3 * V_8 , * V_9 ;
int V_10 , V_11 = 0 ;
char V_12 [ V_13 ] , V_14 [ V_13 ] , V_15 [ V_13 ] ;
if ( ! V_2 || ! V_6 || ! V_7 )
return - V_16 ;
if ( ! V_3 )
V_3 = L_1 ;
snprintf ( V_12 , sizeof( V_12 ) , L_2 , V_3 ) ;
snprintf ( V_14 , sizeof( V_14 ) , L_3 , V_3 ) ;
snprintf ( V_15 , sizeof( V_15 ) , L_4 , V_3 ) ;
V_8 = F_2 ( V_2 , V_12 , & V_10 ) ;
if ( ! V_8 )
return - V_17 ;
V_9 = V_8 + V_10 / sizeof( * V_8 ) ;
while ( V_8 < V_9 ) {
T_4 V_18 ;
const void * V_19 ;
if ( V_5 )
* V_5 = F_3 ( V_8 ++ ) ;
V_19 = F_2 ( V_2 , V_14 , NULL ) ;
if ( ! V_19 )
V_19 = F_2 ( V_2 , L_5 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_4 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_6 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
V_19 = F_2 ( V_2 , V_15 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_6 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_7 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
if ( V_11 ++ == V_4 )
break;
}
return 0 ;
}
static bool F_7 ( struct V_1 * V_20 )
{
if ( V_21 >= V_22 )
return false ;
return F_8 ( & V_23 , V_20 ) ;
}
static int F_9 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
const struct V_28 * V_29 ;
struct V_30 * V_31 = & V_27 -> V_20 -> V_31 ;
int V_32 ;
V_29 = F_10 ( V_31 ) ;
if ( ( V_29 && ! V_29 -> V_33 ) ||
! F_11 ( V_27 -> V_20 ) ||
( ! V_29 && ! F_7 ( V_27 -> V_20 ) ) )
return V_34 ;
V_32 = F_12 ( V_25 , & V_27 -> V_20 -> V_31 , V_29 ) ;
if ( V_32 )
return V_32 ;
if ( ! V_29 )
return - V_35 ;
return V_29 -> V_33 ( V_25 , V_27 ) ;
}
static int F_13 ( struct V_36 * V_37 , T_5 V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_26 V_27 = { . V_42 = 1 } ;
int V_32 ;
V_32 = F_14 ( V_41 -> V_20 , V_38 , L_6 ,
L_7 , & V_27 . V_20 ,
V_27 . args ) ;
if ( V_32 )
return V_32 == - V_17 ? V_34 : V_32 ;
V_32 = F_9 ( V_41 -> V_25 , & V_27 ) ;
F_15 ( V_27 . V_20 ) ;
return V_32 ;
}
const struct V_28 * F_16 ( struct V_24 * V_25 ,
struct V_1 * V_43 )
{
const struct V_28 * V_29 = NULL ;
struct V_44 * V_45 = V_25 -> V_44 ;
int V_32 = V_34 ;
if ( ! V_43 )
return NULL ;
if ( V_45 ) {
if ( V_45 -> V_29 )
return V_45 -> V_29 ;
F_17 ( V_25 ) ;
}
if ( F_18 ( V_25 ) ) {
struct V_40 V_41 = {
. V_25 = V_25 ,
. V_20 = V_43 ,
} ;
V_32 = F_19 ( F_20 ( V_25 ) ,
F_13 , & V_41 ) ;
} else {
struct V_26 V_27 ;
int V_46 = 0 ;
while ( ! F_21 ( V_43 , L_8 ,
L_9 ,
V_46 , & V_27 ) ) {
V_32 = F_9 ( V_25 , & V_27 ) ;
F_15 ( V_27 . V_20 ) ;
V_46 ++ ;
if ( V_32 )
break;
}
}
if ( ! V_32 )
V_29 = V_25 -> V_44 -> V_29 ;
if ( V_29 && V_29 -> V_47 && V_25 -> V_48 && ! V_25 -> V_49 )
V_32 = V_29 -> V_47 ( V_25 ) ;
if ( V_32 == - V_35 ) {
V_29 = F_22 ( V_32 ) ;
} else if ( V_32 < 0 ) {
F_23 ( V_25 , L_10 , V_32 ) ;
V_29 = NULL ;
}
return V_29 ;
}
static int T_6 F_24 ( void )
{
struct V_1 * V_20 ;
const struct V_50 * V_51 , * V_52 = & V_23 ;
F_25 (np, matches, &match) {
const T_7 V_53 = V_51 -> V_39 ;
if ( V_53 && V_53 ( V_20 ) )
F_26 ( L_11 , V_20 ) ;
}
return 0 ;
}
