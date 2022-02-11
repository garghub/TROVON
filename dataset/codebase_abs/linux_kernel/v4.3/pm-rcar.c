static int F_1 ( const struct V_1 * V_2 , bool V_3 )
{
unsigned int V_4 , V_5 ;
int V_6 ;
if ( V_3 ) {
V_4 = V_7 ;
V_5 = V_8 ;
} else {
V_4 = V_9 ;
V_5 = V_10 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
if ( F_2 ( V_12 + V_13 ) & F_3 ( V_4 ) )
break;
F_4 ( V_14 ) ;
}
if ( V_6 == V_11 )
return - V_15 ;
F_5 ( F_3 ( V_2 -> V_16 ) ,
V_12 + V_2 -> V_17 + V_5 ) ;
return 0 ;
}
static int F_6 ( const struct V_1 * V_2 , bool V_3 )
{
unsigned int V_18 = F_3 ( V_2 -> V_19 ) ;
unsigned int V_20 = F_3 ( V_2 -> V_16 ) ;
unsigned int V_21 ;
unsigned long V_22 ;
int V_23 = 0 ;
int V_6 ;
F_7 ( & V_24 , V_22 ) ;
F_5 ( V_18 , V_12 + V_25 ) ;
for ( V_6 = 0 ; V_6 < V_26 ; V_6 ++ ) {
V_23 = F_1 ( V_2 , V_3 ) ;
if ( V_23 )
goto V_27;
V_21 = F_2 ( V_12 +
V_2 -> V_17 + V_28 ) ;
if ( ! ( V_21 & V_20 ) )
break;
F_4 ( V_29 ) ;
}
if ( V_6 == V_26 ) {
V_23 = - V_30 ;
goto V_27;
}
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ ) {
if ( F_2 ( V_12 + V_32 ) & V_18 )
break;
F_4 ( V_33 ) ;
}
if ( V_6 == V_31 )
V_23 = - V_30 ;
F_5 ( V_18 , V_12 + V_25 ) ;
V_27:
F_8 ( & V_24 , V_22 ) ;
F_9 ( L_1 ,
V_2 -> V_19 , F_2 ( V_12 + V_32 ) , V_23 ) ;
return V_23 ;
}
int F_10 ( const struct V_1 * V_2 )
{
return F_6 ( V_2 , false ) ;
}
int F_11 ( const struct V_1 * V_2 )
{
return F_6 ( V_2 , true ) ;
}
bool F_12 ( const struct V_1 * V_2 )
{
unsigned int V_34 ;
V_34 = F_2 ( V_12 + V_2 -> V_17 + V_35 ) ;
if ( V_34 & F_3 ( V_2 -> V_16 ) )
return true ;
return false ;
}
void T_1 * F_13 ( T_2 V_36 )
{
V_12 = F_14 ( V_36 , V_37 ) ;
if ( ! V_12 )
F_15 ( L_2 ) ;
return V_12 ;
}
