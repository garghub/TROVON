void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
F_2 () ;
V_5 = F_3 ( V_8 ) ;
if ( V_5 == NULL )
goto V_9;
V_7 = F_4 ( V_2 ) ;
if ( V_7 == NULL )
goto V_9;
V_3 = F_5 ( & V_7 -> V_10 , 0 ) ;
if ( F_6 ( V_2 ) && ! F_7 ( V_2 ) && V_3 ) {
struct V_11 V_12 = {
. V_2 = V_2 ,
. V_13 = 0 ,
. V_14 = 0
} ;
int V_15 ;
unsigned long V_16 = V_7 -> V_16 ;
if ( ! ( ( V_3 | V_16 ) & V_7 -> V_17 ) )
goto V_9;
V_15 = V_5 -> V_18 ( V_3 | V_16 , & V_12 ) ;
if ( F_8 ( V_15 < 0 || V_16 ) ) {
F_9 ( & V_2 -> V_19 ) ;
if ( V_15 < 0 )
V_7 -> V_16 |= V_3 ;
else
V_7 -> V_16 &= ~ V_16 ;
F_10 ( & V_2 -> V_19 ) ;
}
}
V_9:
F_11 () ;
}
int F_12 ( struct V_4 * V_20 )
{
int V_15 = 0 ;
struct V_4 * V_5 ;
F_13 ( & V_21 ) ;
V_5 = F_14 ( V_8 ,
F_15 ( & V_21 ) ) ;
if ( V_5 != NULL ) {
V_15 = - V_22 ;
goto V_9;
}
F_16 ( V_8 , V_20 ) ;
F_17 ( & V_21 ) ;
return V_15 ;
V_9:
F_17 ( & V_21 ) ;
return V_15 ;
}
void F_18 ( struct V_4 * V_20 )
{
struct V_4 * V_5 ;
F_13 ( & V_21 ) ;
V_5 = F_14 ( V_8 ,
F_15 ( & V_21 ) ) ;
F_19 ( V_5 != V_20 ) ;
F_16 ( V_8 , NULL ) ;
F_17 ( & V_21 ) ;
}
int F_20 ( struct V_23 * V_20 )
{
int V_15 = 0 ;
struct V_23 * V_5 ;
F_13 ( & V_21 ) ;
V_5 = F_14 ( V_24 ,
F_15 ( & V_21 ) ) ;
if ( V_5 != NULL ) {
V_15 = - V_22 ;
goto V_9;
}
F_16 ( V_24 , V_20 ) ;
F_17 ( & V_21 ) ;
return V_15 ;
V_9:
F_17 ( & V_21 ) ;
return V_15 ;
}
void F_21 ( struct V_23 * V_20 )
{
struct V_23 * V_5 ;
F_13 ( & V_21 ) ;
V_5 = F_14 ( V_24 ,
F_15 ( & V_21 ) ) ;
F_19 ( V_5 != V_20 ) ;
F_16 ( V_24 , NULL ) ;
F_17 ( & V_21 ) ;
}
static int F_22 ( struct V_25 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_23 ( V_28 , sizeof( V_28 ) ,
V_29 ) ;
if ( ! V_27 )
goto V_30;
V_27 [ 0 ] . V_31 = & V_25 -> V_2 . V_32 ;
V_27 [ 1 ] . V_31 = & V_25 -> V_2 . V_33 ;
V_25 -> V_2 . V_34 =
F_24 ( V_25 ,
V_35 , V_27 ) ;
if ( ! V_25 -> V_2 . V_34 ) {
F_25 ( V_36 L_1 ) ;
goto V_37;
}
return 0 ;
V_37:
F_26 ( V_27 ) ;
V_30:
return - V_38 ;
}
static void F_27 ( struct V_25 * V_25 )
{
struct V_26 * V_27 ;
V_27 = V_25 -> V_2 . V_34 -> V_39 ;
F_28 ( V_25 -> V_2 . V_34 ) ;
F_26 ( V_27 ) ;
}
static int F_22 ( struct V_25 * V_25 )
{
return 0 ;
}
static void F_27 ( struct V_25 * V_25 )
{
}
int F_29 ( struct V_25 * V_25 )
{
int V_15 ;
V_25 -> V_2 . V_32 = V_40 ;
V_25 -> V_2 . V_33 = V_41 ;
if ( F_30 ( V_25 , & V_42 ) ) {
V_15 = F_31 ( & V_43 ) ;
if ( V_15 < 0 ) {
F_25 ( V_36 L_2
L_3 ) ;
goto V_44;
}
}
V_15 = F_22 ( V_25 ) ;
if ( V_15 < 0 )
goto V_45;
return 0 ;
V_45:
if ( F_30 ( V_25 , & V_42 ) )
F_32 ( & V_43 ) ;
V_44:
return V_15 ;
}
void F_33 ( struct V_25 * V_25 )
{
F_27 ( V_25 ) ;
if ( F_30 ( V_25 , & V_42 ) )
F_32 ( & V_43 ) ;
}
