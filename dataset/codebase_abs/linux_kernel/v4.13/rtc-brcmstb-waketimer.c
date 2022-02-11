static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_2 -> V_3 + V_4 ) ;
( void ) F_3 ( V_2 -> V_3 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_5 )
{
F_1 ( V_2 ) ;
F_2 ( V_5 + 1 , V_2 -> V_3 + V_6 ) ;
}
static T_1 F_5 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
F_6 ( V_2 -> V_9 , 0 ) ;
return V_10 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_2 V_13 ;
do {
V_12 -> V_14 = F_3 ( V_2 -> V_3 + V_15 ) ;
V_13 = F_3 ( V_2 -> V_3 + V_16 ) ;
} while ( V_13 >= V_2 -> V_17 );
V_12 -> V_18 = V_2 -> V_17 - V_13 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = V_2 -> V_9 ;
int V_20 = 0 ;
if ( F_9 ( V_9 ) ) {
V_20 = F_10 ( V_2 -> V_7 ) ;
if ( V_20 ) {
F_11 ( V_9 , L_1 ) ;
return V_20 ;
}
}
return V_20 ;
}
static int F_12 ( struct V_21 * V_22 ,
unsigned long V_23 , void * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_22 , struct V_1 , V_24 ) ;
if ( V_23 == V_25 )
F_8 ( V_2 ) ;
return V_26 ;
}
static int F_14 ( struct V_19 * V_9 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
struct V_11 V_29 ;
F_7 ( V_2 , & V_29 ) ;
F_16 ( V_29 . V_14 , V_28 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_9 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
T_3 V_14 ;
V_14 = F_18 ( V_28 ) ;
if ( V_14 > V_30 || V_14 < 0 )
return - V_31 ;
F_2 ( V_14 , V_2 -> V_3 + V_15 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_9 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
T_3 V_14 ;
T_2 V_34 ;
V_14 = F_3 ( V_2 -> V_3 + V_6 ) ;
if ( V_14 != 0 ) {
V_33 -> V_35 = 1 ;
F_20 ( V_14 , & V_33 -> time ) ;
}
V_34 = F_3 ( V_2 -> V_3 + V_4 ) ;
V_33 -> V_36 = ! ! ( V_34 & 1 ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_9 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
T_3 V_14 ;
if ( V_33 -> V_35 )
V_14 = F_18 ( & V_33 -> time ) ;
else
V_14 = 0 ;
if ( V_14 > V_30 || V_14 < 0 )
return - V_31 ;
F_4 ( V_2 , V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_9 ,
unsigned int V_35 )
{
return 0 ;
}
static int F_23 ( struct V_37 * V_38 )
{
struct V_19 * V_9 = & V_38 -> V_9 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
int V_20 ;
V_2 = F_24 ( V_9 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
F_25 ( V_38 , V_2 ) ;
V_2 -> V_9 = V_9 ;
V_40 = F_26 ( V_38 , V_43 , 0 ) ;
V_2 -> V_3 = F_27 ( V_9 , V_40 ) ;
if ( F_28 ( V_2 -> V_3 ) )
return F_29 ( V_2 -> V_3 ) ;
F_30 ( V_9 , true ) ;
F_31 ( V_9 ) ;
V_2 -> V_7 = F_32 ( V_38 , 0 ) ;
if ( V_2 -> V_7 < 0 )
return - V_44 ;
V_2 -> V_45 = F_33 ( V_9 , NULL ) ;
if ( ! F_28 ( V_2 -> V_45 ) ) {
V_20 = F_34 ( V_2 -> V_45 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_17 = F_35 ( V_2 -> V_45 ) ;
if ( ! V_2 -> V_17 )
V_2 -> V_17 = V_46 ;
} else {
V_2 -> V_17 = V_46 ;
V_2 -> V_45 = NULL ;
}
V_20 = F_36 ( V_9 , V_2 -> V_7 , F_5 , 0 ,
L_2 , V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_2 -> V_24 . V_47 = F_12 ;
F_37 ( & V_2 -> V_24 ) ;
V_2 -> V_48 = F_38 ( L_3 , V_9 ,
& V_49 , V_50 ) ;
if ( F_28 ( V_2 -> V_48 ) ) {
F_11 ( V_9 , L_4 ) ;
F_39 ( & V_2 -> V_24 ) ;
return F_29 ( V_2 -> V_48 ) ;
}
F_40 ( V_9 , L_5 , V_2 -> V_7 ) ;
return V_20 ;
}
static int F_41 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_15 ( & V_38 -> V_9 ) ;
F_39 ( & V_2 -> V_24 ) ;
F_42 ( V_2 -> V_48 ) ;
return 0 ;
}
static int F_43 ( struct V_19 * V_9 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
return F_8 ( V_2 ) ;
}
static int F_44 ( struct V_19 * V_9 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
int V_20 ;
if ( ! F_9 ( V_9 ) )
return 0 ;
V_20 = F_45 ( V_2 -> V_7 ) ;
F_1 ( V_2 ) ;
return V_20 ;
}
