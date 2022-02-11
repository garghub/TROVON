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
V_12 -> V_23 = F_12 ( V_5 , V_9 ,
V_7 -> V_1 -> V_23 ) ;
if ( F_7 ( V_12 -> V_23 ) ) {
V_13 = F_8 ( V_12 -> V_23 ) ;
goto V_24;
}
V_12 -> V_25 = F_13 ( V_5 , V_9 , V_7 -> V_1 -> V_25 ) ;
if ( F_7 ( V_12 -> V_25 ) ) {
V_13 = F_8 ( V_12 -> V_25 ) ;
goto V_26;
}
return V_12 ;
V_26:
F_14 ( V_12 -> V_23 ) ;
V_24:
if ( V_12 -> V_21 )
F_15 ( V_12 -> V_21 ) ;
V_22:
if ( V_12 -> V_19 )
F_16 ( V_12 -> V_19 ) ;
V_20:
if ( V_12 -> V_17 )
F_17 ( V_12 -> V_17 ) ;
V_18:
if ( V_12 -> V_15 )
F_18 ( V_12 -> V_15 ) ;
V_16:
F_19 ( V_2 , V_12 ) ;
return F_5 ( V_13 ) ;
}
int F_20 ( unsigned long V_5 , struct V_6 * V_7 )
{
struct V_1 * V_27 = V_7 -> V_1 ;
struct V_8 * V_9 = F_21 ( V_7 , V_9 ) ;
struct V_1 * V_28 ;
if ( F_22 ( ! ( V_5 & ( V_29 | V_30 | V_31 |
V_32 | V_33 |
V_34 ) ) ) ) {
F_23 ( V_27 ) ;
return 0 ;
}
if ( ! F_24 ( V_9 , V_35 ) )
return - V_36 ;
if ( ( V_5 & ( V_31 | V_37 ) ) ==
( V_31 | V_37 ) )
return - V_38 ;
V_28 = F_4 ( V_5 , V_7 , V_9 , V_7 -> V_39 ) ;
if ( F_7 ( V_28 ) )
return F_8 ( V_28 ) ;
V_7 -> V_1 = V_28 ;
return 0 ;
}
void F_25 ( struct V_1 * V_40 )
{
if ( V_40 -> V_15 )
F_18 ( V_40 -> V_15 ) ;
if ( V_40 -> V_17 )
F_17 ( V_40 -> V_17 ) ;
if ( V_40 -> V_19 )
F_16 ( V_40 -> V_19 ) ;
if ( V_40 -> V_21 )
F_15 ( V_40 -> V_21 ) ;
F_14 ( V_40 -> V_23 ) ;
F_26 ( V_40 -> V_25 ) ;
F_19 ( V_2 , V_40 ) ;
}
int F_27 ( unsigned long V_41 ,
struct V_1 * * V_12 , struct V_42 * V_43 , struct V_10 * V_11 )
{
struct V_8 * V_9 ;
int V_13 = 0 ;
if ( ! ( V_41 & ( V_29 | V_30 | V_31 |
V_33 | V_32 | V_34 ) ) )
return 0 ;
V_9 = V_43 ? V_43 -> V_9 : F_28 () ;
if ( ! F_24 ( V_9 , V_35 ) )
return - V_36 ;
* V_12 = F_4 ( V_41 , V_44 , V_9 ,
V_11 ? V_11 : V_44 -> V_39 ) ;
if ( F_7 ( * V_12 ) ) {
V_13 = F_8 ( * V_12 ) ;
goto V_45;
}
V_45:
return V_13 ;
}
void F_29 ( struct V_6 * V_46 , struct V_1 * V_47 )
{
struct V_1 * V_40 ;
F_30 () ;
F_31 ( V_46 ) ;
V_40 = V_46 -> V_1 ;
V_46 -> V_1 = V_47 ;
F_32 ( V_46 ) ;
if ( V_40 && F_33 ( & V_40 -> V_4 ) )
F_25 ( V_40 ) ;
}
void F_34 ( struct V_6 * V_46 )
{
F_29 ( V_46 , NULL ) ;
}
int T_1 F_35 ( void )
{
V_2 = F_36 ( V_1 , V_48 ) ;
return 0 ;
}
