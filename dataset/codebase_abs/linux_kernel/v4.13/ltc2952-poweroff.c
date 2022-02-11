static enum V_1 F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = F_2 ( V_3 , V_9 ) ;
if ( V_8 -> V_10 )
return V_11 ;
V_5 = F_3 ( V_8 -> V_12 ) ;
F_4 ( V_8 -> V_12 , ! V_5 ) ;
V_4 = F_5 ( V_3 ) ;
V_6 = F_6 ( V_3 , V_4 , V_8 -> V_13 ) ;
return V_14 ;
}
static void F_7 ( struct V_7 * V_8 )
{
F_8 ( & V_8 -> V_9 , V_8 -> V_13 , V_15 ) ;
}
static enum V_1
F_9 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_3 , V_16 ) ;
F_7 ( V_8 ) ;
F_10 ( V_8 -> V_17 , L_1 ) ;
F_11 ( true ) ;
return V_11 ;
}
static T_2 F_12 ( int V_18 , void * V_19 )
{
struct V_7 * V_8 = V_19 ;
if ( V_8 -> V_10 || F_13 ( & V_8 -> V_9 ) ) {
return V_20 ;
}
if ( F_3 ( V_8 -> V_21 ) ) {
F_8 ( & V_8 -> V_16 , V_8 -> V_22 ,
V_15 ) ;
} else {
F_14 ( & V_8 -> V_16 ) ;
}
return V_20 ;
}
static void F_15 ( void )
{
F_4 ( V_23 -> V_24 , 1 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
V_8 -> V_13 = 300L * 1E6L ;
V_8 -> V_22 = F_17 ( 2 , 500L * 1E6L ) ;
F_18 ( & V_8 -> V_16 , V_25 , V_15 ) ;
V_8 -> V_16 . V_26 = F_9 ;
F_18 ( & V_8 -> V_9 , V_25 , V_15 ) ;
V_8 -> V_9 . V_26 = F_1 ;
}
static int F_19 ( struct V_27 * V_28 )
{
int V_29 ;
struct V_7 * V_8 = F_20 ( V_28 ) ;
F_16 ( V_8 ) ;
V_8 -> V_12 = F_21 ( & V_28 -> V_17 , L_2 ,
V_30 ) ;
if ( F_22 ( V_8 -> V_12 ) ) {
V_29 = F_23 ( V_8 -> V_12 ) ;
F_24 ( & V_28 -> V_17 , L_3 ) ;
return V_29 ;
}
V_8 -> V_24 = F_21 ( & V_28 -> V_17 , L_4 , V_30 ) ;
if ( F_22 ( V_8 -> V_24 ) ) {
V_29 = F_23 ( V_8 -> V_24 ) ;
F_24 ( & V_28 -> V_17 , L_5 ) ;
return V_29 ;
}
V_8 -> V_21 = F_25 ( & V_28 -> V_17 , L_6 ,
V_31 ) ;
if ( F_22 ( V_8 -> V_21 ) ) {
F_24 ( & V_28 -> V_17 , L_7 ) ;
V_8 -> V_21 = NULL ;
}
if ( F_26 ( & V_28 -> V_17 , F_27 ( V_8 -> V_21 ) ,
F_12 ,
( V_32 | V_33 ) ,
L_8 ,
V_8 ) ) {
if ( V_8 -> V_21 ) {
F_28 ( & V_28 -> V_17 ,
L_9 ) ;
F_29 ( & V_28 -> V_17 , V_8 -> V_21 ) ;
V_8 -> V_21 = NULL ;
}
F_10 ( & V_28 -> V_17 ,
L_10 ) ;
F_7 ( V_8 ) ;
}
return 0 ;
}
static int F_30 ( struct V_34 * V_35 ,
unsigned long V_36 , void * V_37 )
{
struct V_7 * V_8 = F_2 ( V_35 , V_38 ) ;
V_8 -> V_10 = true ;
return V_39 ;
}
static int F_31 ( struct V_27 * V_28 )
{
int V_29 ;
struct V_7 * V_8 ;
if ( V_40 ) {
F_24 ( & V_28 -> V_17 , L_11 ) ;
return - V_41 ;
}
V_8 = F_32 ( & V_28 -> V_17 , sizeof( * V_8 ) , V_42 ) ;
if ( ! V_8 )
return - V_43 ;
V_8 -> V_17 = & V_28 -> V_17 ;
F_33 ( V_28 , V_8 ) ;
V_29 = F_19 ( V_28 ) ;
if ( V_29 )
return V_29 ;
V_23 = V_8 ;
V_40 = F_15 ;
V_8 -> V_38 . V_44 = F_30 ;
F_34 ( & V_45 ,
& V_8 -> V_38 ) ;
F_10 ( & V_28 -> V_17 , L_12 ) ;
return 0 ;
}
static int F_35 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = F_20 ( V_28 ) ;
V_40 = NULL ;
F_14 ( & V_8 -> V_16 ) ;
F_14 ( & V_8 -> V_9 ) ;
F_36 ( & V_45 ,
& V_8 -> V_38 ) ;
return 0 ;
}
