static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( & V_7 ) ;
if ( * V_3 == 0 )
return V_8 ;
if ( * V_3 >= ( F_3 ( V_5 -> V_9 ) /
F_4 ( V_5 -> V_10 ) ) )
return NULL ;
return V_5 -> V_11 +
( F_4 ( V_5 -> V_10 ) * ( * V_3 ) ++ ) ;
}
static void * F_5 ( struct V_1 * V_2 , void * V_12 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( * V_3 >= ( F_3 ( V_5 -> V_9 ) /
F_4 ( V_5 -> V_10 ) ) )
return NULL ;
return V_5 -> V_11 +
( F_4 ( V_5 -> V_10 ) * ( * V_3 ) ++ ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_13 * V_14 = V_5 -> V_14 ;
void T_2 * V_15 = V_5 -> V_14 -> V_16 ;
if ( V_12 == V_8 ) {
int V_17 , V_18 , V_19 ;
V_17 = F_7 ( V_15 , V_14 -> V_20 ,
V_5 -> V_21 ) ;
V_18 = F_8 ( V_15 , V_14 -> V_20 ,
V_5 -> V_21 ) ;
V_19 = F_9 ( V_15 , V_14 -> V_20 ) ;
F_10 ( V_2 , L_1 ) ;
F_11 ( V_2 , L_2 ,
V_5 -> V_22 -> V_23 ) ;
F_11 ( V_2 , L_3 ,
V_5 -> V_21 , V_5 -> V_14 -> V_20 ) ;
F_11 ( V_2 , L_4 ,
V_17 , V_18 , ( V_19 & 1 << V_5 -> V_21 )
>> V_5 -> V_21 ) ;
F_11 ( V_2 , L_5 ,
F_3 ( V_5 -> V_9 ) ,
F_4 ( V_5 -> V_10 ) ) ;
F_10 ( V_2 , L_6 ) ;
return 0 ;
}
F_12 ( V_2 , L_7 , V_24 , 32 , 4 ,
V_12 , F_4 ( V_5 -> V_10 ) , false ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , void * V_12 )
{
F_14 ( & V_7 ) ;
}
static int F_15 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
int V_27 = F_16 ( V_26 , & V_28 ) ;
if ( ! V_27 ) {
struct V_1 * V_29 = V_26 -> V_30 ;
V_29 -> V_6 = V_25 -> V_31 ;
}
return V_27 ;
}
int F_17 ( struct V_4 * V_5 , const char * V_32 )
{
struct V_33 * V_22 ;
char V_34 [ 8 ] ;
V_22 = F_18 ( sizeof( * V_22 ) , V_35 ) ;
if ( ! V_22 )
return - V_36 ;
F_19 ( V_22 -> V_23 , V_32 , sizeof( V_22 -> V_23 ) ) ;
snprintf ( V_34 , sizeof( V_34 ) , L_8 ,
V_5 -> V_21 ) ;
V_22 -> V_37 = F_20 ( V_34 , V_38 ,
V_5 -> V_14 -> V_39 ,
V_5 , & V_40 ) ;
if ( ! V_22 -> V_37 ) {
F_21 ( L_9 ) ;
F_22 ( V_22 ) ;
return - V_41 ;
}
V_5 -> V_22 = V_22 ;
return 0 ;
}
void F_23 ( struct V_4 * V_5 )
{
if ( V_5 -> V_22 ) {
F_24 ( V_5 -> V_22 -> V_37 ) ;
F_22 ( V_5 -> V_22 ) ;
V_5 -> V_22 = NULL ;
}
}
static void * F_25 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 ( & V_42 ) ;
if ( * V_3 == 0 )
return V_8 ;
if ( * V_3 >= V_43 )
return NULL ;
return V_3 ;
}
static void * F_26 ( struct V_1 * V_2 , void * V_12 , T_1 * V_3 )
{
if ( ++ ( * V_3 ) >= V_43 )
return NULL ;
return V_3 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_12 )
{
struct V_13 * V_14 = V_2 -> V_6 ;
if ( V_12 == V_8 ) {
F_11 ( V_2 , L_10 ,
V_14 -> V_20 ) ;
} else {
int V_44 = * ( ( int * ) V_12 ) - 1 ;
struct V_4 * V_5 = & V_14 -> V_45 [ V_44 ] ;
void T_2 * V_15 = V_14 -> V_16 ;
int V_17 , V_18 , V_19 ;
if ( ! ( V_14 -> V_46 & 1 << V_44 ) )
return 0 ;
V_17 = F_7 ( V_15 , V_14 -> V_20 ,
V_5 -> V_21 ) ;
V_18 = F_8 ( V_15 , V_14 -> V_20 ,
V_5 -> V_21 ) ;
V_19 = F_9 ( V_15 , V_14 -> V_20 ) ;
F_11 ( V_2 ,
L_11 ,
V_5 -> V_21 , V_17 , V_18 ,
( V_19 & 1 << V_5 -> V_21 ) >>
V_5 -> V_21 ) ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , void * V_12 )
{
F_14 ( & V_42 ) ;
}
static int F_29 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
int V_27 = F_16 ( V_26 , & V_47 ) ;
if ( ! V_27 ) {
struct V_1 * V_29 = V_26 -> V_30 ;
V_29 -> V_6 = V_25 -> V_31 ;
}
return V_27 ;
}
int F_30 ( struct V_13 * V_14 )
{
struct V_48 * V_49 = V_14 -> V_49 ;
struct V_50 * V_51 = V_49 -> V_52 -> V_37 ;
char V_32 [ 8 ] ;
snprintf ( V_32 , sizeof( V_32 ) , L_12 , V_14 -> V_20 ) ;
V_14 -> V_39 = F_31 ( V_32 , V_51 ) ;
if ( ! V_14 -> V_39 ) {
F_21 ( L_13 ) ;
return - V_41 ;
}
V_14 -> V_53 = F_20 ( L_14 , V_38 ,
V_14 -> V_39 , V_14 ,
& V_54 ) ;
if ( ! V_14 -> V_53 ) {
F_21 ( L_15 ) ;
F_24 ( V_14 -> V_39 ) ;
return - V_41 ;
}
return 0 ;
}
void F_32 ( struct V_13 * V_14 )
{
F_24 ( V_14 -> V_53 ) ;
F_24 ( V_14 -> V_39 ) ;
}
