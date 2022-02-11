static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , V_3 ) ;
if ( V_1 )
F_3 ( & V_1 -> V_4 , 1 ) ;
return V_1 ;
}
static struct V_1 * F_4 ( unsigned long V_5 ,
struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_12 ;
int V_13 ;
V_12 = F_1 () ;
if ( ! V_12 )
return F_5 ( - V_14 ) ;
V_12 -> V_15 = F_6 ( V_5 , V_7 -> V_1 -> V_15 , V_9 , V_11 ) ;
if ( F_7 ( V_12 -> V_15 ) ) {
V_13 = F_8 ( V_12 -> V_15 ) ;
goto V_16;
}
V_12 -> V_17 = F_9 ( V_5 , V_9 , V_7 -> V_1 -> V_17 ) ;
if ( F_7 ( V_12 -> V_17 ) ) {
V_13 = F_8 ( V_12 -> V_17 ) ;
goto V_18;
}
V_12 -> V_19 = F_10 ( V_5 , V_9 , V_7 -> V_1 -> V_19 ) ;
if ( F_7 ( V_12 -> V_19 ) ) {
V_13 = F_8 ( V_12 -> V_19 ) ;
goto V_20;
}
V_12 -> V_21 =
F_11 ( V_5 , V_9 , V_7 -> V_1 -> V_21 ) ;
if ( F_7 ( V_12 -> V_21 ) ) {
V_13 = F_8 ( V_12 -> V_21 ) ;
goto V_22;
}
V_12 -> V_23 = F_12 ( V_5 , V_9 , V_7 -> V_1 -> V_23 ) ;
if ( F_7 ( V_12 -> V_23 ) ) {
V_13 = F_8 ( V_12 -> V_23 ) ;
goto V_24;
}
return V_12 ;
V_24:
if ( V_12 -> V_21 )
F_13 ( V_12 -> V_21 ) ;
V_22:
if ( V_12 -> V_19 )
F_14 ( V_12 -> V_19 ) ;
V_20:
if ( V_12 -> V_17 )
F_15 ( V_12 -> V_17 ) ;
V_18:
if ( V_12 -> V_15 )
F_16 ( V_12 -> V_15 ) ;
V_16:
F_17 ( V_2 , V_12 ) ;
return F_5 ( V_13 ) ;
}
int F_18 ( unsigned long V_5 , struct V_6 * V_7 )
{
struct V_1 * V_25 = V_7 -> V_1 ;
struct V_8 * V_9 = F_19 ( V_7 , V_9 ) ;
struct V_1 * V_26 ;
if ( F_20 ( ! ( V_5 & ( V_27 | V_28 | V_29 |
V_30 | V_31 ) ) ) ) {
F_21 ( V_25 ) ;
return 0 ;
}
if ( ! F_22 ( V_9 , V_32 ) )
return - V_33 ;
if ( ( V_5 & ( V_29 | V_34 ) ) ==
( V_29 | V_34 ) )
return - V_35 ;
V_26 = F_4 ( V_5 , V_7 , V_9 , V_7 -> V_36 ) ;
if ( F_7 ( V_26 ) )
return F_8 ( V_26 ) ;
V_7 -> V_1 = V_26 ;
return 0 ;
}
void F_23 ( struct V_1 * V_37 )
{
if ( V_37 -> V_15 )
F_16 ( V_37 -> V_15 ) ;
if ( V_37 -> V_17 )
F_15 ( V_37 -> V_17 ) ;
if ( V_37 -> V_19 )
F_14 ( V_37 -> V_19 ) ;
if ( V_37 -> V_21 )
F_13 ( V_37 -> V_21 ) ;
F_24 ( V_37 -> V_23 ) ;
F_17 ( V_2 , V_37 ) ;
}
int F_25 ( unsigned long V_38 ,
struct V_1 * * V_12 , struct V_39 * V_40 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
int V_13 = 0 ;
if ( ! ( V_38 & ( V_27 | V_28 | V_29 |
V_31 | V_30 ) ) )
return 0 ;
V_9 = V_40 ? V_40 -> V_9 : F_26 () ;
if ( ! F_22 ( V_9 , V_32 ) )
return - V_33 ;
* V_12 = F_4 ( V_38 , V_41 , V_9 ,
V_11 ? V_11 : V_41 -> V_36 ) ;
if ( F_7 ( * V_12 ) ) {
V_13 = F_8 ( * V_12 ) ;
goto V_42;
}
V_42:
return V_13 ;
}
void F_27 ( struct V_6 * V_43 , struct V_1 * V_44 )
{
struct V_1 * V_37 ;
F_28 () ;
V_37 = V_43 -> V_1 ;
F_29 ( V_43 -> V_1 , V_44 ) ;
if ( V_37 && F_30 ( & V_37 -> V_4 ) ) {
F_31 () ;
F_23 ( V_37 ) ;
}
}
void F_32 ( struct V_6 * V_43 )
{
F_27 ( V_43 , NULL ) ;
}
int T_1 F_33 ( void )
{
V_2 = F_34 ( V_1 , V_45 ) ;
return 0 ;
}
