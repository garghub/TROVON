static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , V_3 ) ;
if ( V_1 )
F_3 ( & V_1 -> V_4 , 1 ) ;
return V_1 ;
}
static struct V_1 * F_4 ( unsigned long V_5 ,
struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_10 ;
int V_11 ;
V_10 = F_1 () ;
if ( ! V_10 )
return F_5 ( - V_12 ) ;
V_10 -> V_13 = F_6 ( V_5 , V_7 -> V_1 -> V_13 , V_9 ) ;
if ( F_7 ( V_10 -> V_13 ) ) {
V_11 = F_8 ( V_10 -> V_13 ) ;
goto V_14;
}
V_10 -> V_15 = F_9 ( V_5 , V_7 ) ;
if ( F_7 ( V_10 -> V_15 ) ) {
V_11 = F_8 ( V_10 -> V_15 ) ;
goto V_16;
}
V_10 -> V_17 = F_10 ( V_5 , V_7 ) ;
if ( F_7 ( V_10 -> V_17 ) ) {
V_11 = F_8 ( V_10 -> V_17 ) ;
goto V_18;
}
V_10 -> V_19 = F_11 ( V_5 , F_12 ( V_7 ) ) ;
if ( F_7 ( V_10 -> V_19 ) ) {
V_11 = F_8 ( V_10 -> V_19 ) ;
goto V_20;
}
V_10 -> V_21 = F_13 ( V_5 , V_7 -> V_1 -> V_21 ) ;
if ( F_7 ( V_10 -> V_21 ) ) {
V_11 = F_8 ( V_10 -> V_21 ) ;
goto V_22;
}
return V_10 ;
V_22:
if ( V_10 -> V_19 )
F_14 ( V_10 -> V_19 ) ;
V_20:
if ( V_10 -> V_17 )
F_15 ( V_10 -> V_17 ) ;
V_18:
if ( V_10 -> V_15 )
F_16 ( V_10 -> V_15 ) ;
V_16:
if ( V_10 -> V_13 )
F_17 ( V_10 -> V_13 ) ;
V_14:
F_18 ( V_2 , V_10 ) ;
return F_5 ( V_11 ) ;
}
int F_19 ( unsigned long V_5 , struct V_6 * V_7 )
{
struct V_1 * V_23 = V_7 -> V_1 ;
struct V_1 * V_24 ;
int V_11 = 0 ;
if ( ! V_23 )
return 0 ;
F_20 ( V_23 ) ;
if ( ! ( V_5 & ( V_25 | V_26 | V_27 |
V_28 | V_29 ) ) )
return 0 ;
if ( ! F_21 ( V_30 ) ) {
V_11 = - V_31 ;
goto V_32;
}
if ( ( V_5 & V_27 ) && ( V_5 & V_33 ) ) {
V_11 = - V_34 ;
goto V_32;
}
V_24 = F_4 ( V_5 , V_7 , V_7 -> V_35 ) ;
if ( F_7 ( V_24 ) ) {
V_11 = F_8 ( V_24 ) ;
goto V_32;
}
V_7 -> V_1 = V_24 ;
V_32:
F_22 ( V_23 ) ;
return V_11 ;
}
void F_23 ( struct V_1 * V_36 )
{
if ( V_36 -> V_13 )
F_17 ( V_36 -> V_13 ) ;
if ( V_36 -> V_15 )
F_16 ( V_36 -> V_15 ) ;
if ( V_36 -> V_17 )
F_15 ( V_36 -> V_17 ) ;
if ( V_36 -> V_19 )
F_14 ( V_36 -> V_19 ) ;
F_24 ( V_36 -> V_21 ) ;
F_18 ( V_2 , V_36 ) ;
}
int F_25 ( unsigned long V_37 ,
struct V_1 * * V_10 , struct V_8 * V_9 )
{
int V_11 = 0 ;
if ( ! ( V_37 & ( V_25 | V_26 | V_27 |
V_29 ) ) )
return 0 ;
if ( ! F_21 ( V_30 ) )
return - V_31 ;
* V_10 = F_4 ( V_37 , V_38 ,
V_9 ? V_9 : V_38 -> V_35 ) ;
if ( F_7 ( * V_10 ) ) {
V_11 = F_8 ( * V_10 ) ;
goto V_32;
}
V_32:
return V_11 ;
}
void F_26 ( struct V_6 * V_39 , struct V_1 * V_40 )
{
struct V_1 * V_36 ;
F_27 () ;
V_36 = V_39 -> V_1 ;
F_28 ( V_39 -> V_1 , V_40 ) ;
if ( V_36 && F_29 ( & V_36 -> V_4 ) ) {
F_30 () ;
F_23 ( V_36 ) ;
}
}
void F_31 ( struct V_6 * V_39 )
{
F_26 ( V_39 , NULL ) ;
}
int T_1 F_32 ( void )
{
V_2 = F_33 ( V_1 , V_41 ) ;
return 0 ;
}
