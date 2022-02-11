void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_4 , V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 ;
int V_12 ;
F_3 () ;
V_7 = F_4 ( V_3 -> V_2 . V_13 ) ;
if ( V_7 == NULL )
goto V_14;
V_9 = F_5 ( V_2 ) ;
if ( V_9 == NULL )
goto V_14;
V_4 = F_6 ( & V_9 -> V_15 , 0 ) ;
if ( ! F_7 ( V_2 ) || F_8 ( V_2 ) || ! V_4 )
goto V_14;
V_5 = V_9 -> V_5 ;
if ( ! ( ( V_4 | V_5 ) & V_9 -> V_16 ) )
goto V_14;
V_11 . V_2 = V_2 ;
V_11 . V_17 = 0 ;
V_11 . V_18 = 0 ;
V_12 = V_7 -> V_19 ( V_4 | V_5 , & V_11 ) ;
if ( F_9 ( V_12 >= 0 && ! V_5 ) )
goto V_14;
F_10 ( & V_2 -> V_20 ) ;
if ( V_12 < 0 )
V_9 -> V_5 |= V_4 ;
else
V_9 -> V_5 &= ~ V_5 ;
F_11 ( & V_2 -> V_20 ) ;
V_14:
F_12 () ;
}
int F_13 ( struct V_3 * V_3 ,
struct V_6 * V_21 )
{
int V_12 ;
struct V_6 * V_7 ;
F_14 ( & V_22 ) ;
V_7 = F_15 ( V_3 -> V_2 . V_13 ,
F_16 ( & V_22 ) ) ;
if ( V_7 != NULL ) {
V_12 = - V_23 ;
goto V_14;
}
F_17 ( V_3 -> V_2 . V_13 , V_21 ) ;
V_12 = 0 ;
V_14:
F_18 ( & V_22 ) ;
return V_12 ;
}
void F_19 ( struct V_3 * V_3 ,
struct V_6 * V_21 )
{
struct V_6 * V_7 ;
F_14 ( & V_22 ) ;
V_7 = F_15 ( V_3 -> V_2 . V_13 ,
F_16 ( & V_22 ) ) ;
F_20 ( V_7 != V_21 ) ;
F_21 ( V_3 -> V_2 . V_13 , NULL ) ;
F_18 ( & V_22 ) ;
}
int F_22 ( struct V_3 * V_3 ,
struct V_24 * V_21 )
{
int V_12 ;
struct V_24 * V_7 ;
F_14 ( & V_22 ) ;
V_7 = F_15 ( V_3 -> V_2 . V_25 ,
F_16 ( & V_22 ) ) ;
if ( V_7 != NULL ) {
V_12 = - V_23 ;
goto V_14;
}
F_17 ( V_3 -> V_2 . V_25 , V_21 ) ;
V_12 = 0 ;
V_14:
F_18 ( & V_22 ) ;
return V_12 ;
}
void F_23 ( struct V_3 * V_3 ,
struct V_24 * V_21 )
{
struct V_24 * V_7 ;
F_14 ( & V_22 ) ;
V_7 = F_15 ( V_3 -> V_2 . V_25 ,
F_16 ( & V_22 ) ) ;
F_20 ( V_7 != V_21 ) ;
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
F_26 ( V_3 , L_1 , V_27 ) ;
if ( ! V_3 -> V_2 . V_34 ) {
F_27 ( V_35 L_2 ) ;
goto V_36;
}
return 0 ;
V_36:
F_28 ( V_27 ) ;
V_30:
return - V_37 ;
}
static void F_29 ( struct V_3 * V_3 )
{
struct V_26 * V_27 ;
V_27 = V_3 -> V_2 . V_34 -> V_38 ;
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
int V_12 ;
V_3 -> V_2 . V_32 = V_39 ;
V_3 -> V_2 . V_33 = V_40 ;
if ( F_32 ( V_3 , & V_41 ) ) {
V_12 = F_33 ( & V_42 ) ;
if ( V_12 < 0 ) {
F_27 ( V_35 L_3
L_4 ) ;
goto V_43;
}
}
V_12 = F_24 ( V_3 ) ;
if ( V_12 < 0 )
goto V_44;
return 0 ;
V_44:
if ( F_32 ( V_3 , & V_41 ) )
F_34 ( & V_42 ) ;
V_43:
return V_12 ;
}
void F_35 ( struct V_3 * V_3 )
{
F_29 ( V_3 ) ;
if ( F_32 ( V_3 , & V_41 ) )
F_34 ( & V_42 ) ;
}
