void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_3 () ;
V_6 = F_4 ( V_3 -> V_2 . V_9 ) ;
if ( V_6 == NULL )
goto V_10;
V_8 = F_5 ( V_2 ) ;
if ( V_8 == NULL )
goto V_10;
V_4 = F_6 ( & V_8 -> V_11 , 0 ) ;
if ( F_7 ( V_2 ) && ! F_8 ( V_2 ) && V_4 ) {
struct V_12 V_13 = {
. V_2 = V_2 ,
. V_14 = 0 ,
. V_15 = 0
} ;
int V_16 ;
unsigned long V_17 = V_8 -> V_17 ;
if ( ! ( ( V_4 | V_17 ) & V_8 -> V_18 ) )
goto V_10;
V_16 = V_6 -> V_19 ( V_4 | V_17 , & V_13 ) ;
if ( F_9 ( V_16 < 0 || V_17 ) ) {
F_10 ( & V_2 -> V_20 ) ;
if ( V_16 < 0 )
V_8 -> V_17 |= V_4 ;
else
V_8 -> V_17 &= ~ V_17 ;
F_11 ( & V_2 -> V_20 ) ;
}
}
V_10:
F_12 () ;
}
int F_13 ( struct V_3 * V_3 ,
struct V_5 * V_21 )
{
int V_16 = 0 ;
struct V_5 * V_6 ;
F_14 ( & V_22 ) ;
V_6 = F_15 ( V_3 -> V_2 . V_9 ,
F_16 ( & V_22 ) ) ;
if ( V_6 != NULL ) {
V_16 = - V_23 ;
goto V_10;
}
F_17 ( V_3 -> V_2 . V_9 , V_21 ) ;
F_18 ( & V_22 ) ;
return V_16 ;
V_10:
F_18 ( & V_22 ) ;
return V_16 ;
}
void F_19 ( struct V_3 * V_3 ,
struct V_5 * V_21 )
{
struct V_5 * V_6 ;
F_14 ( & V_22 ) ;
V_6 = F_15 ( V_3 -> V_2 . V_9 ,
F_16 ( & V_22 ) ) ;
F_20 ( V_6 != V_21 ) ;
F_21 ( V_3 -> V_2 . V_9 , NULL ) ;
F_18 ( & V_22 ) ;
}
int F_22 ( struct V_3 * V_3 ,
struct V_24 * V_21 )
{
int V_16 = 0 ;
struct V_24 * V_6 ;
F_14 ( & V_22 ) ;
V_6 = F_15 ( V_3 -> V_2 . V_25 ,
F_16 ( & V_22 ) ) ;
if ( V_6 != NULL ) {
V_16 = - V_23 ;
goto V_10;
}
F_17 ( V_3 -> V_2 . V_25 , V_21 ) ;
F_18 ( & V_22 ) ;
return V_16 ;
V_10:
F_18 ( & V_22 ) ;
return V_16 ;
}
void F_23 ( struct V_3 * V_3 ,
struct V_24 * V_21 )
{
struct V_24 * V_6 ;
F_14 ( & V_22 ) ;
V_6 = F_15 ( V_3 -> V_2 . V_25 ,
F_16 ( & V_22 ) ) ;
F_20 ( V_6 != V_21 ) ;
F_21 ( V_3 -> V_2 . V_25 , NULL ) ;
F_18 ( & V_22 ) ;
}
static int F_24 ( struct V_3 * V_3 )
{
struct V_26 * V_27 ;
V_27 = F_25 ( V_28 , sizeof( V_28 ) ,
V_29 ) ;
if ( ! V_27 )
goto V_30;
V_27 [ 0 ] . V_31 = & V_3 -> V_2 . V_32 ;
V_27 [ 1 ] . V_31 = & V_3 -> V_2 . V_33 ;
V_3 -> V_2 . V_34 =
F_26 ( V_3 ,
V_35 , V_27 ) ;
if ( ! V_3 -> V_2 . V_34 ) {
F_27 ( V_36 L_1 ) ;
goto V_37;
}
return 0 ;
V_37:
F_28 ( V_27 ) ;
V_30:
return - V_38 ;
}
static void F_29 ( struct V_3 * V_3 )
{
struct V_26 * V_27 ;
V_27 = V_3 -> V_2 . V_34 -> V_39 ;
F_30 ( V_3 -> V_2 . V_34 ) ;
F_28 ( V_27 ) ;
}
static int F_24 ( struct V_3 * V_3 )
{
return 0 ;
}
static void F_29 ( struct V_3 * V_3 )
{
}
int F_31 ( struct V_3 * V_3 )
{
int V_16 ;
V_3 -> V_2 . V_32 = V_40 ;
V_3 -> V_2 . V_33 = V_41 ;
if ( F_32 ( V_3 , & V_42 ) ) {
V_16 = F_33 ( & V_43 ) ;
if ( V_16 < 0 ) {
F_27 ( V_36 L_2
L_3 ) ;
goto V_44;
}
}
V_16 = F_24 ( V_3 ) ;
if ( V_16 < 0 )
goto V_45;
return 0 ;
V_45:
if ( F_32 ( V_3 , & V_42 ) )
F_34 ( & V_43 ) ;
V_44:
return V_16 ;
}
void F_35 ( struct V_3 * V_3 )
{
F_29 ( V_3 ) ;
if ( F_32 ( V_3 , & V_42 ) )
F_34 ( & V_43 ) ;
}
