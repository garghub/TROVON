static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_2 ( V_5 -> V_7 -> V_8 ) == 0 )
return - V_9 ;
if ( V_3 )
F_3 ( V_5 -> V_7 -> V_10 ) ;
else
F_4 ( V_5 -> V_7 -> V_10 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 , const char * V_15 , T_2 V_16 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_17 ;
bool V_18 ;
int V_19 ;
V_19 = F_7 ( V_15 , 10 , & V_17 ) ;
if ( V_19 )
goto V_20;
if ( V_17 > 100000 ) {
V_19 = - V_9 ;
goto V_20;
}
V_18 = F_8 () & V_5 -> V_7 -> V_10 ;
if ( V_18 )
F_4 ( V_5 -> V_7 -> V_10 ) ;
if ( ! V_17 )
goto V_20;
V_17 = F_9 () / V_17 ;
if ( V_17 <= 4 || V_17 <= V_5 -> V_21 ) {
V_19 = - V_9 ;
goto V_20;
}
F_10 ( V_5 -> V_7 -> V_8 , V_17 ) ;
F_11 ( V_5 -> V_7 -> V_8 , V_17 - V_5 -> V_21 ) ;
if ( V_18 )
F_3 ( V_5 -> V_7 -> V_10 ) ;
V_20:
return V_19 ? V_19 : V_16 ;
}
static T_1 F_12 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_22 = F_2 ( V_5 -> V_7 -> V_8 ) ;
unsigned long V_17 ;
if ( V_22 == 0 )
V_17 = 0 ;
else
V_17 = F_9 () / F_2 ( V_5 -> V_7 -> V_8 ) ;
return sprintf ( V_15 , L_1 , V_17 ) ;
}
static T_3 F_13 ( int V_23 , void * V_24 )
{
struct V_4 * V_5 = V_24 ;
F_14 ( V_5 -> V_7 -> V_8 ) ;
F_15 ( V_5 -> V_2 , 0 ) ;
return V_25 ;
}
static int F_16 ( int V_23 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
if ( V_28 [ V_26 ] . V_23 == V_23 )
return V_26 ;
return - V_29 ;
}
static int T_4 F_17 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_12 . V_34 ;
struct V_4 * V_5 ;
unsigned int V_35 ;
int V_19 ;
V_5 = F_18 ( sizeof( * V_5 ) , V_36 ) ;
if ( V_5 == NULL ) {
V_19 = - V_37 ;
goto V_38;
}
V_5 -> V_23 = F_19 ( V_31 , 0 ) ;
if ( ! V_5 -> V_23 ) {
F_20 ( & V_31 -> V_12 , L_2 ) ;
V_19 = - V_29 ;
goto V_39;
}
V_19 = F_16 ( V_5 -> V_23 ) ;
if ( V_19 < 0 )
goto V_39;
V_5 -> V_40 = V_19 ;
V_5 -> V_7 = & V_28 [ V_5 -> V_40 ] ;
V_5 -> V_2 = F_21 ( L_3 , V_5 -> V_40 ) ;
if ( ! V_5 -> V_2 ) {
V_19 = - V_37 ;
goto V_39;
}
V_5 -> V_2 -> V_6 = V_5 ;
V_5 -> V_2 -> V_41 = & V_42 ;
V_5 -> V_2 -> V_12 . V_43 = V_44 ;
V_19 = F_22 ( V_5 -> V_2 ) ;
if ( V_19 )
goto V_45;
V_19 = F_23 ( V_5 -> V_23 , F_13 ,
0 , V_5 -> V_2 -> V_46 , V_5 ) ;
if ( V_19 ) {
F_20 ( & V_31 -> V_12 ,
L_4 , V_5 -> V_23 ) ;
goto V_47;
}
V_35 = V_48 | V_49 | V_50 ;
if ( V_33 && V_33 -> V_51 ) {
unsigned long long V_17 ;
V_5 -> V_51 = true ;
V_19 = F_24 ( V_5 -> V_7 -> V_52 , V_5 -> V_2 -> V_46 ) ;
if ( V_19 )
goto V_53;
V_17 = ( unsigned long long ) F_9 () * V_33 -> V_54 ;
F_25 ( V_17 , V_55 ) ;
V_5 -> V_21 = V_17 ;
if ( V_33 -> V_56 )
V_35 |= V_57 ;
} else {
V_5 -> V_21 = 1 ;
V_35 |= V_58 ;
}
F_26 ( V_5 -> V_7 -> V_8 , V_35 ) ;
F_27 ( & V_31 -> V_12 , L_5 ,
V_5 -> V_40 , V_5 -> V_23 ) ;
F_28 ( V_31 , V_5 ) ;
return 0 ;
V_53:
F_29 ( V_5 -> V_23 , V_5 ) ;
V_47:
F_30 ( V_5 -> V_2 ) ;
V_45:
F_31 ( V_5 -> V_2 ) ;
V_39:
F_32 ( V_5 ) ;
V_38:
return V_19 ;
}
static int T_5 F_33 ( struct V_30 * V_31 )
{
struct V_4 * V_5 = F_34 ( V_31 ) ;
F_4 ( V_5 -> V_7 -> V_10 ) ;
if ( V_5 -> V_51 )
F_35 ( V_5 -> V_7 -> V_52 ) ;
F_29 ( V_5 -> V_23 , V_5 ) ;
F_30 ( V_5 -> V_2 ) ;
F_31 ( V_5 -> V_2 ) ;
F_32 ( V_5 ) ;
return 0 ;
}
