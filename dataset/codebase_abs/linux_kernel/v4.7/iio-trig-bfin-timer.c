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
struct V_12 * V_13 ,
const char * V_14 , T_2 V_15 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_16 ;
bool V_17 ;
int V_18 ;
V_18 = F_8 ( V_14 , 10 , & V_16 ) ;
if ( V_18 )
return V_18 ;
if ( V_16 > 100000 )
return - V_8 ;
V_17 = F_9 () & V_5 -> V_6 -> V_9 ;
if ( V_17 )
F_5 ( V_5 -> V_6 -> V_9 ) ;
if ( ! V_16 )
return V_15 ;
V_16 = F_10 () / V_16 ;
if ( V_16 <= 4 || V_16 <= V_5 -> V_19 )
return - V_8 ;
F_11 ( V_5 -> V_6 -> V_7 , V_16 ) ;
F_12 ( V_5 -> V_6 -> V_7 , V_16 - V_5 -> V_19 ) ;
if ( V_17 )
F_4 ( V_5 -> V_6 -> V_9 ) ;
return V_15 ;
}
static T_1 F_13 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_20 = F_3 ( V_5 -> V_6 -> V_7 ) ;
unsigned long V_16 ;
if ( ! V_20 )
V_16 = 0 ;
else
V_16 = F_10 () / F_3 ( V_5 -> V_6 -> V_7 ) ;
return sprintf ( V_14 , L_1 , V_16 ) ;
}
static T_3 F_14 ( int V_21 , void * V_22 )
{
struct V_4 * V_5 = V_22 ;
F_15 ( V_5 -> V_6 -> V_7 ) ;
F_16 ( V_5 -> V_2 ) ;
return V_23 ;
}
static int F_17 ( int V_21 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
if ( V_26 [ V_24 ] . V_21 == V_21 )
return V_24 ;
return - V_27 ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_30 * V_31 ;
struct V_4 * V_5 ;
unsigned int V_32 ;
int V_18 ;
V_5 = F_19 ( & V_29 -> V_11 , sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 )
return - V_34 ;
V_5 -> V_21 = F_20 ( V_29 , 0 ) ;
if ( ! V_5 -> V_21 ) {
F_21 ( & V_29 -> V_11 , L_2 ) ;
return - V_27 ;
}
V_18 = F_17 ( V_5 -> V_21 ) ;
if ( V_18 < 0 )
return V_18 ;
V_5 -> V_35 = V_18 ;
V_5 -> V_6 = & V_26 [ V_5 -> V_35 ] ;
V_5 -> V_2 = F_22 ( L_3 , V_5 -> V_35 ) ;
if ( ! V_5 -> V_2 )
return - V_34 ;
V_5 -> V_2 -> V_36 = & V_37 ;
V_5 -> V_2 -> V_11 . V_38 = V_39 ;
F_23 ( V_5 -> V_2 , V_5 ) ;
V_18 = F_24 ( V_5 -> V_2 ) ;
if ( V_18 )
goto V_40;
V_18 = F_25 ( V_5 -> V_21 , F_14 ,
0 , V_5 -> V_2 -> V_41 , V_5 ) ;
if ( V_18 ) {
F_21 ( & V_29 -> V_11 ,
L_4 , V_5 -> V_21 ) ;
goto V_42;
}
V_32 = V_43 | V_44 | V_45 ;
V_31 = F_26 ( & V_29 -> V_11 ) ;
if ( V_31 && V_31 -> V_46 ) {
unsigned long long V_16 ;
V_5 -> V_46 = true ;
V_18 = F_27 ( V_5 -> V_6 -> V_47 , V_5 -> V_2 -> V_41 ) ;
if ( V_18 )
goto V_48;
V_16 = ( unsigned long long ) F_10 () * V_31 -> V_49 ;
F_28 ( V_16 , V_50 ) ;
V_5 -> V_19 = V_16 ;
if ( V_31 -> V_51 )
V_32 |= V_52 ;
} else {
V_5 -> V_19 = 1 ;
V_32 |= V_53 ;
}
F_29 ( V_5 -> V_6 -> V_7 , V_32 ) ;
F_30 ( & V_29 -> V_11 , L_5 ,
V_5 -> V_35 , V_5 -> V_21 ) ;
F_31 ( V_29 , V_5 ) ;
return 0 ;
V_48:
F_32 ( V_5 -> V_21 , V_5 ) ;
V_42:
F_33 ( V_5 -> V_2 ) ;
V_40:
F_34 ( V_5 -> V_2 ) ;
return V_18 ;
}
static int F_35 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_36 ( V_29 ) ;
F_5 ( V_5 -> V_6 -> V_9 ) ;
if ( V_5 -> V_46 )
F_37 ( V_5 -> V_6 -> V_47 ) ;
F_32 ( V_5 -> V_21 , V_5 ) ;
F_33 ( V_5 -> V_2 ) ;
F_34 ( V_5 -> V_2 ) ;
return 0 ;
}
