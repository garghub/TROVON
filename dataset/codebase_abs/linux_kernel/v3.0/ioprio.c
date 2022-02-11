int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
const struct V_7 * V_7 = F_2 () , * V_8 ;
F_3 () ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 -> V_9 != V_7 -> V_10 &&
V_8 -> V_9 != V_7 -> V_9 && ! F_5 ( V_11 ) ) {
F_6 () ;
return - V_12 ;
}
F_6 () ;
V_4 = F_7 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
F_8 ( V_2 ) ;
do {
V_6 = V_2 -> V_5 ;
F_9 () ;
if ( V_6 )
break;
V_6 = F_10 ( V_13 , - 1 ) ;
if ( ! V_6 ) {
V_4 = - V_14 ;
break;
}
V_2 -> V_5 = V_6 ;
} while ( 1 );
if ( ! V_4 ) {
V_6 -> V_3 = V_3 ;
V_6 -> V_15 = 1 ;
}
F_11 ( V_2 ) ;
return V_4 ;
}
static int F_12 ( struct V_1 * V_16 )
{
int V_17 ;
V_17 = F_13 ( V_16 ) ;
if ( V_17 )
goto V_18;
V_17 = F_14 ( V_19 , V_20 ) ;
if ( V_16 -> V_5 )
V_17 = V_16 -> V_5 -> V_3 ;
V_18:
return V_17 ;
}
int F_15 ( unsigned short V_21 , unsigned short V_22 )
{
unsigned short V_23 = F_16 ( V_21 ) ;
unsigned short V_24 = F_16 ( V_22 ) ;
if ( V_23 == V_19 )
V_23 = V_25 ;
if ( V_24 == V_19 )
V_24 = V_25 ;
if ( V_23 == V_24 )
return F_17 ( V_21 , V_22 ) ;
if ( V_23 > V_24 )
return V_22 ;
else
return V_21 ;
}
