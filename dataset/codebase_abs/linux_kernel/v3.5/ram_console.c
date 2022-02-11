static void
F_1 ( struct V_1 * V_1 , const char * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
F_2 ( V_5 , V_2 , V_3 ) ;
}
void F_3 ( int V_7 )
{
if ( V_7 )
V_8 . V_9 |= V_10 ;
else
V_8 . V_9 &= ~ V_10 ;
}
static int T_1 F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 . V_16 ;
struct V_4 * V_5 ;
V_5 = F_5 ( & V_12 -> V_15 , true ) ;
if ( F_6 ( V_5 ) )
return F_7 ( V_5 ) ;
if ( V_14 ) {
V_17 = F_8 ( V_14 -> V_17 , V_18 ) ;
if ( V_17 )
V_19 = strlen ( V_17 ) ;
}
V_20 = V_5 ;
V_8 . V_6 = V_5 ;
F_9 ( & V_8 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_21 , F_4 ) ;
}
static T_2 F_12 ( struct V_22 * V_22 , char T_3 * V_23 ,
T_4 V_24 , T_5 * V_25 )
{
T_5 V_26 = * V_25 ;
T_2 V_3 ;
struct V_4 * V_5 = V_20 ;
T_4 V_27 = F_13 ( V_5 ) ;
const char * V_28 = F_14 ( V_5 ) ;
char * V_29 ;
int V_30 ;
if ( V_31 && ! F_15 ( V_32 ) )
return - V_33 ;
if ( V_26 < V_27 ) {
V_3 = F_16 ( V_24 , ( T_4 ) ( V_27 - V_26 ) ) ;
if ( F_17 ( V_23 , V_28 + V_26 , V_3 ) )
return - V_34 ;
goto V_35;
}
V_26 -= V_27 ;
V_3 = F_18 ( V_5 , NULL , 0 ) ;
if ( V_26 < V_3 ) {
V_29 = F_19 ( V_3 , V_18 ) ;
if ( ! V_29 )
return - V_36 ;
F_18 ( V_5 , V_29 , V_3 + 1 ) ;
V_3 = F_16 ( V_24 , ( T_4 ) ( V_3 - V_26 ) ) ;
V_30 = F_17 ( V_23 , V_29 + V_26 , V_3 ) ;
F_20 ( V_29 ) ;
if ( V_30 )
return - V_34 ;
goto V_35;
}
V_26 -= V_3 ;
if ( V_26 < V_19 ) {
V_3 = F_16 ( V_24 , ( T_4 ) ( V_19 - V_26 ) ) ;
if ( F_17 ( V_23 , V_17 + V_26 , V_3 ) )
return - V_34 ;
goto V_35;
}
return 0 ;
V_35:
* V_25 += V_3 ;
return V_3 ;
}
static int T_1 F_21 ( void )
{
struct V_37 * V_38 ;
struct V_4 * V_5 = V_20 ;
if ( ! V_5 )
return 0 ;
if ( F_13 ( V_5 ) == 0 )
return 0 ;
V_38 = F_22 ( L_1 , V_39 | V_40 , NULL ) ;
if ( ! V_38 ) {
F_23 ( V_41 L_2 ) ;
F_24 ( V_5 ) ;
return 0 ;
}
V_38 -> V_42 = & V_43 ;
V_38 -> V_44 = F_13 ( V_5 ) +
F_18 ( V_5 , NULL , 0 ) +
V_19 ;
return 0 ;
}
