static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 )
F_2 ( V_4 -> V_5 ) ;
else
F_3 ( V_4 -> V_5 , 0 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_5 ( V_4 -> V_5 , V_2 ) ;
}
static void F_6 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 )
F_2 ( V_4 -> V_6 ) ;
else
F_3 ( V_4 -> V_6 , 0 ) ;
}
static void F_7 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_5 ( V_4 -> V_6 , V_2 ) ;
}
static int F_8 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return F_9 ( V_4 -> V_5 ) ;
}
static int F_10 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return F_9 ( V_4 -> V_6 ) ;
}
static int F_11 ( struct V_7 * V_8 ,
unsigned int * V_5 , unsigned int * V_6 )
{
if ( F_12 ( V_8 ) < 2 )
return - V_9 ;
* V_5 = F_13 ( V_8 , 0 ) ;
* V_6 = F_13 ( V_8 , 1 ) ;
if ( ! F_14 ( * V_5 ) || ! F_14 ( * V_6 ) ) {
F_15 ( L_1 ,
V_8 -> V_10 , * V_5 , * V_6 ) ;
return - V_9 ;
}
return 0 ;
}
static void F_16 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
T_1 V_11 ;
F_17 ( V_8 , L_2 , & V_4 -> V_12 ) ;
if ( ! F_17 ( V_8 , L_3 , & V_11 ) )
V_4 -> V_13 = F_18 ( V_11 ) ;
V_4 -> V_14 =
F_19 ( V_8 , L_4 ) ;
V_4 -> V_15 =
F_19 ( V_8 , L_5 ) ;
V_4 -> V_16 =
F_19 ( V_8 , L_6 ) ;
}
static int F_20 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
unsigned int V_5 , V_6 ;
int V_25 ;
if ( V_18 -> V_26 . V_27 ) {
V_25 = F_11 ( V_18 -> V_26 . V_27 ,
& V_5 , & V_6 ) ;
if ( V_25 )
return V_25 ;
} else {
if ( ! F_21 ( & V_18 -> V_26 ) )
return - V_28 ;
V_4 = F_21 ( & V_18 -> V_26 ) ;
V_5 = V_4 -> V_5 ;
V_6 = V_4 -> V_6 ;
}
V_25 = F_22 ( V_5 , L_7 ) ;
if ( V_25 ) {
if ( V_25 == - V_29 )
V_25 = - V_30 ;
goto V_31;
}
V_25 = F_22 ( V_6 , L_8 ) ;
if ( V_25 ) {
if ( V_25 == - V_29 )
V_25 = - V_30 ;
goto V_32;
}
V_20 = F_23 ( & V_18 -> V_26 , sizeof( * V_20 ) , V_33 ) ;
if ( ! V_20 ) {
V_25 = - V_34 ;
goto V_35;
}
V_24 = & V_20 -> V_24 ;
V_22 = & V_20 -> V_22 ;
V_4 = & V_20 -> V_4 ;
if ( V_18 -> V_26 . V_27 ) {
V_4 -> V_5 = V_5 ;
V_4 -> V_6 = V_6 ;
F_16 ( V_18 -> V_26 . V_27 , V_4 ) ;
} else {
memcpy ( V_4 , F_21 ( & V_18 -> V_26 ) , sizeof( * V_4 ) ) ;
}
if ( V_4 -> V_14 ) {
F_3 ( V_4 -> V_5 , 1 ) ;
V_22 -> V_36 = F_4 ;
} else {
F_2 ( V_4 -> V_5 ) ;
V_22 -> V_36 = F_1 ;
}
if ( V_4 -> V_15 || V_4 -> V_16 ) {
F_3 ( V_4 -> V_6 , 1 ) ;
V_22 -> V_37 = F_7 ;
} else {
F_2 ( V_4 -> V_6 ) ;
V_22 -> V_37 = F_6 ;
}
if ( ! V_4 -> V_16 )
V_22 -> V_38 = F_10 ;
V_22 -> V_39 = F_8 ;
if ( V_4 -> V_12 )
V_22 -> V_12 = V_4 -> V_12 ;
else if ( V_4 -> V_16 )
V_22 -> V_12 = 50 ;
else
V_22 -> V_12 = 5 ;
if ( V_4 -> V_13 )
V_22 -> V_13 = V_4 -> V_13 ;
else
V_22 -> V_13 = V_40 / 10 ;
V_22 -> V_1 = V_4 ;
V_24 -> V_41 = V_42 ;
if ( V_18 -> V_26 . V_27 )
F_24 ( V_24 -> V_43 , F_25 ( & V_18 -> V_26 ) , sizeof( V_24 -> V_43 ) ) ;
else
snprintf ( V_24 -> V_43 , sizeof( V_24 -> V_43 ) , L_9 , V_18 -> V_44 ) ;
V_24 -> V_45 = V_22 ;
V_24 -> V_46 = V_47 | V_48 ;
V_24 -> V_26 . V_49 = & V_18 -> V_26 ;
V_24 -> V_26 . V_27 = V_18 -> V_26 . V_27 ;
V_24 -> V_50 = V_18 -> V_44 ;
V_25 = F_26 ( V_24 ) ;
if ( V_25 )
goto V_35;
F_27 ( V_18 , V_20 ) ;
F_28 ( & V_18 -> V_26 , L_10 ,
V_4 -> V_5 , V_4 -> V_6 ,
V_4 -> V_16
? L_11 : L_12 ) ;
return 0 ;
V_35:
F_29 ( V_6 ) ;
V_32:
F_29 ( V_5 ) ;
V_31:
return V_25 ;
}
static int F_30 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
V_20 = F_31 ( V_18 ) ;
V_24 = & V_20 -> V_24 ;
V_4 = & V_20 -> V_4 ;
F_32 ( V_24 ) ;
F_29 ( V_4 -> V_6 ) ;
F_29 ( V_4 -> V_5 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
int V_25 ;
V_25 = F_34 ( & V_51 ) ;
if ( V_25 )
F_35 ( V_52 L_13 , V_25 ) ;
return V_25 ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_51 ) ;
}
