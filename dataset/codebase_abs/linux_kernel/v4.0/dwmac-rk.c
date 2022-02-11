static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 , V_9 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_10 ,
V_11 | V_12 ) ;
F_4 ( V_2 -> V_8 , V_13 ,
V_14 | V_15 |
F_5 ( V_4 ) |
F_6 ( V_3 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 , V_9 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_10 ,
V_16 | V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_18 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 , V_9 ) ;
return;
}
if ( V_18 == 10 )
F_4 ( V_2 -> V_8 , V_10 , V_19 ) ;
else if ( V_18 == 100 )
F_4 ( V_2 -> V_8 , V_10 , V_20 ) ;
else if ( V_18 == 1000 )
F_4 ( V_2 -> V_8 , V_10 , V_21 ) ;
else
F_3 ( V_6 , L_2 , V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_18 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 , V_9 ) ;
return;
}
if ( V_18 == 10 ) {
F_4 ( V_2 -> V_8 , V_10 ,
V_22 | V_23 ) ;
} else if ( V_18 == 100 ) {
F_4 ( V_2 -> V_8 , V_10 ,
V_24 | V_25 ) ;
} else {
F_3 ( V_6 , L_3 , V_18 ) ;
}
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
V_2 -> V_26 = false ;
V_2 -> V_27 = F_11 ( V_6 , L_4 ) ;
if ( F_2 ( V_2 -> V_27 ) )
F_3 ( V_6 , L_5 ,
V_9 , L_4 ) ;
V_2 -> V_28 = F_11 ( V_6 , L_6 ) ;
if ( F_2 ( V_2 -> V_28 ) )
F_3 ( V_6 , L_5 ,
V_9 , L_6 ) ;
V_2 -> V_29 = F_11 ( V_6 , L_7 ) ;
if ( F_2 ( V_2 -> V_29 ) )
F_3 ( V_6 , L_5 ,
V_9 , L_7 ) ;
V_2 -> V_30 = F_11 ( V_6 , L_8 ) ;
if ( F_2 ( V_2 -> V_30 ) )
F_3 ( V_6 , L_5 ,
V_9 , L_8 ) ;
V_2 -> V_31 = F_11 ( V_6 , L_9 ) ;
if ( F_2 ( V_2 -> V_31 ) )
F_3 ( V_6 , L_5 ,
V_9 , L_9 ) ;
if ( V_2 -> V_32 == V_33 ) {
V_2 -> V_34 = F_11 ( V_6 , L_10 ) ;
if ( F_2 ( V_2 -> V_34 ) )
F_3 ( V_6 , L_5 ,
V_9 , L_10 ) ;
if ( ! V_2 -> V_35 ) {
V_2 -> V_36 =
F_11 ( V_6 , L_11 ) ;
if ( F_2 ( V_2 -> V_36 ) )
F_3 ( V_6 , L_5 ,
V_9 , L_11 ) ;
}
}
if ( V_2 -> V_35 ) {
F_12 ( V_6 , L_12 , V_9 ) ;
} else {
if ( V_2 -> V_32 == V_33 )
F_13 ( V_2 -> V_37 , 50000000 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , bool V_38 )
{
int V_32 = V_32 = V_2 -> V_32 ;
if ( V_38 ) {
if ( ! V_2 -> V_26 ) {
if ( V_32 == V_33 ) {
if ( ! F_2 ( V_2 -> V_27 ) )
F_15 (
V_2 -> V_27 ) ;
if ( ! F_2 ( V_2 -> V_34 ) )
F_15 (
V_2 -> V_34 ) ;
if ( ! F_2 ( V_2 -> V_36 ) )
F_15 (
V_2 -> V_36 ) ;
}
if ( ! F_2 ( V_2 -> V_29 ) )
F_15 ( V_2 -> V_29 ) ;
if ( ! F_2 ( V_2 -> V_30 ) )
F_15 ( V_2 -> V_30 ) ;
if ( ! F_2 ( V_2 -> V_28 ) )
F_15 ( V_2 -> V_28 ) ;
F_16 ( 5 ) ;
V_2 -> V_26 = true ;
}
} else {
if ( V_2 -> V_26 ) {
if ( V_32 == V_33 ) {
if ( ! F_2 ( V_2 -> V_27 ) )
F_17 (
V_2 -> V_27 ) ;
if ( ! F_2 ( V_2 -> V_34 ) )
F_17 (
V_2 -> V_34 ) ;
if ( ! F_2 ( V_2 -> V_36 ) )
F_17 (
V_2 -> V_36 ) ;
}
if ( ! F_2 ( V_2 -> V_29 ) )
F_17 ( V_2 -> V_29 ) ;
if ( ! F_2 ( V_2 -> V_30 ) )
F_17 ( V_2 -> V_30 ) ;
if ( ! F_2 ( V_2 -> V_28 ) )
F_17 ( V_2 -> V_28 ) ;
V_2 -> V_26 = false ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , bool V_38 )
{
struct V_39 * V_40 = V_2 -> V_39 ;
int V_41 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( ! V_40 ) {
F_3 ( V_6 , L_13 , V_9 ) ;
return - 1 ;
}
if ( V_38 ) {
V_41 = F_19 ( V_40 ) ;
if ( V_41 )
F_3 ( V_6 , L_14 ,
V_9 ) ;
} else {
V_41 = F_20 ( V_40 ) ;
if ( V_41 )
F_3 ( V_6 , L_15 ,
V_9 ) ;
}
return 0 ;
}
static void * F_21 ( struct V_42 * V_7 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = & V_7 -> V_6 ;
int V_41 ;
const char * V_43 = NULL ;
int V_44 ;
V_2 = F_22 ( V_6 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return F_23 ( - V_46 ) ;
V_2 -> V_32 = F_24 ( V_6 -> V_47 ) ;
V_2 -> V_39 = F_25 ( V_6 , L_16 ) ;
if ( F_2 ( V_2 -> V_39 ) ) {
if ( F_26 ( V_2 -> V_39 ) == - V_48 ) {
F_3 ( V_6 , L_17 ) ;
return F_23 ( - V_48 ) ;
}
F_3 ( V_6 , L_18 ) ;
V_2 -> V_39 = NULL ;
}
V_41 = F_27 ( V_6 -> V_47 , L_19 , & V_43 ) ;
if ( V_41 ) {
F_3 ( V_6 , L_20 ,
V_9 ) ;
V_2 -> V_35 = true ;
} else {
F_12 ( V_6 , L_21 ,
V_9 , V_43 ) ;
if ( ! strcmp ( V_43 , L_22 ) )
V_2 -> V_35 = true ;
else
V_2 -> V_35 = false ;
}
V_41 = F_28 ( V_6 -> V_47 , L_23 , & V_44 ) ;
if ( V_41 ) {
V_2 -> V_3 = 0x30 ;
F_3 ( V_6 , L_24 , V_9 ) ;
F_3 ( V_6 , L_25 ,
V_9 , V_2 -> V_3 ) ;
} else {
F_12 ( V_6 , L_26 , V_9 , V_44 ) ;
V_2 -> V_3 = V_44 ;
}
V_41 = F_28 ( V_6 -> V_47 , L_27 , & V_44 ) ;
if ( V_41 ) {
V_2 -> V_4 = 0x10 ;
F_3 ( V_6 , L_28 , V_9 ) ;
F_3 ( V_6 , L_29 ,
V_9 , V_2 -> V_4 ) ;
} else {
F_12 ( V_6 , L_30 , V_9 , V_44 ) ;
V_2 -> V_4 = V_44 ;
}
V_2 -> V_8 = F_29 ( V_6 -> V_47 ,
L_31 ) ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_32 == V_49 ) {
F_12 ( V_6 , L_32 , V_9 ) ;
F_1 ( V_2 , V_2 -> V_3 , V_2 -> V_4 ) ;
} else if ( V_2 -> V_32 == V_33 ) {
F_12 ( V_6 , L_33 , V_9 ) ;
F_7 ( V_2 ) ;
} else {
F_3 ( V_6 , L_34 , V_9 ) ;
}
F_10 ( V_2 ) ;
return V_2 ;
}
static int F_30 ( struct V_42 * V_7 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
int V_41 ;
V_41 = F_18 ( V_2 , true ) ;
if ( V_41 )
return V_41 ;
V_41 = F_14 ( V_2 , true ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static void F_31 ( struct V_42 * V_7 , void * V_50 )
{
struct V_1 * V_51 = V_50 ;
F_18 ( V_51 , false ) ;
F_14 ( V_51 , false ) ;
}
static void F_32 ( void * V_50 , unsigned int V_18 )
{
struct V_1 * V_2 = V_50 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( V_2 -> V_32 == V_49 )
F_8 ( V_2 , V_18 ) ;
else if ( V_2 -> V_32 == V_33 )
F_9 ( V_2 , V_18 ) ;
else
F_3 ( V_6 , L_35 , V_2 -> V_32 ) ;
}
