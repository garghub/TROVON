static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_5 -> V_6 -> V_7 ) == 0 )
return - V_8 ;
if ( V_3 )
F_4 ( V_5 -> V_6 -> V_9 ) ;
else
F_5 ( V_5 -> V_6 -> V_9 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_15 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_16 ;
bool V_17 ;
int V_18 ;
V_18 = F_8 ( V_14 , 10 , & V_16 ) ;
if ( V_18 )
goto V_19;
if ( V_16 > 100000 ) {
V_18 = - V_8 ;
goto V_19;
}
V_17 = F_9 () & V_5 -> V_6 -> V_9 ;
if ( V_17 )
F_5 ( V_5 -> V_6 -> V_9 ) ;
if ( ! V_16 )
goto V_19;
V_16 = F_10 () / V_16 ;
if ( V_16 <= 4 || V_16 <= V_5 -> V_20 ) {
V_18 = - V_8 ;
goto V_19;
}
F_11 ( V_5 -> V_6 -> V_7 , V_16 ) ;
F_12 ( V_5 -> V_6 -> V_7 , V_16 - V_5 -> V_20 ) ;
if ( V_17 )
F_4 ( V_5 -> V_6 -> V_9 ) ;
V_19:
return V_18 ? V_18 : V_15 ;
}
static T_1 F_13 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_21 = F_3 ( V_5 -> V_6 -> V_7 ) ;
unsigned long V_16 ;
if ( V_21 == 0 )
V_16 = 0 ;
else
V_16 = F_10 () / F_3 ( V_5 -> V_6 -> V_7 ) ;
return sprintf ( V_14 , L_1 , V_16 ) ;
}
static T_3 F_14 ( int V_22 , void * V_23 )
{
struct V_4 * V_5 = V_23 ;
F_15 ( V_5 -> V_6 -> V_7 ) ;
F_16 ( V_5 -> V_2 , 0 ) ;
return V_24 ;
}
static int F_17 ( int V_22 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ )
if ( V_27 [ V_25 ] . V_22 == V_22 )
return V_25 ;
return - V_28 ;
}
static int F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_11 . V_33 ;
struct V_4 * V_5 ;
unsigned int V_34 ;
int V_18 ;
V_5 = F_19 ( sizeof( * V_5 ) , V_35 ) ;
if ( V_5 == NULL ) {
V_18 = - V_36 ;
goto V_37;
}
V_5 -> V_22 = F_20 ( V_30 , 0 ) ;
if ( ! V_5 -> V_22 ) {
F_21 ( & V_30 -> V_11 , L_2 ) ;
V_18 = - V_28 ;
goto V_38;
}
V_18 = F_17 ( V_5 -> V_22 ) ;
if ( V_18 < 0 )
goto V_38;
V_5 -> V_39 = V_18 ;
V_5 -> V_6 = & V_27 [ V_5 -> V_39 ] ;
V_5 -> V_2 = F_22 ( L_3 , V_5 -> V_39 ) ;
if ( ! V_5 -> V_2 ) {
V_18 = - V_36 ;
goto V_38;
}
V_5 -> V_2 -> V_40 = & V_41 ;
V_5 -> V_2 -> V_11 . V_42 = V_43 ;
F_23 ( V_5 -> V_2 , V_5 ) ;
V_18 = F_24 ( V_5 -> V_2 ) ;
if ( V_18 )
goto V_44;
V_18 = F_25 ( V_5 -> V_22 , F_14 ,
0 , V_5 -> V_2 -> V_45 , V_5 ) ;
if ( V_18 ) {
F_21 ( & V_30 -> V_11 ,
L_4 , V_5 -> V_22 ) ;
goto V_46;
}
V_34 = V_47 | V_48 | V_49 ;
if ( V_32 && V_32 -> V_50 ) {
unsigned long long V_16 ;
V_5 -> V_50 = true ;
V_18 = F_26 ( V_5 -> V_6 -> V_51 , V_5 -> V_2 -> V_45 ) ;
if ( V_18 )
goto V_52;
V_16 = ( unsigned long long ) F_10 () * V_32 -> V_53 ;
F_27 ( V_16 , V_54 ) ;
V_5 -> V_20 = V_16 ;
if ( V_32 -> V_55 )
V_34 |= V_56 ;
} else {
V_5 -> V_20 = 1 ;
V_34 |= V_57 ;
}
F_28 ( V_5 -> V_6 -> V_7 , V_34 ) ;
F_29 ( & V_30 -> V_11 , L_5 ,
V_5 -> V_39 , V_5 -> V_22 ) ;
F_30 ( V_30 , V_5 ) ;
return 0 ;
V_52:
F_31 ( V_5 -> V_22 , V_5 ) ;
V_46:
F_32 ( V_5 -> V_2 ) ;
V_44:
F_33 ( V_5 -> V_2 ) ;
V_38:
F_34 ( V_5 ) ;
V_37:
return V_18 ;
}
static int F_35 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_36 ( V_30 ) ;
F_5 ( V_5 -> V_6 -> V_9 ) ;
if ( V_5 -> V_50 )
F_37 ( V_5 -> V_6 -> V_51 ) ;
F_31 ( V_5 -> V_22 , V_5 ) ;
F_32 ( V_5 -> V_2 ) ;
F_33 ( V_5 -> V_2 ) ;
F_34 ( V_5 ) ;
return 0 ;
}
