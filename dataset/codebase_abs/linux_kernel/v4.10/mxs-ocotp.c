static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
unsigned int V_5 = 0 ;
while ( V_3 -- ) {
V_5 = F_2 ( V_2 -> V_6 ) ;
if ( ! ( V_5 & ( V_7 | V_8 ) ) )
break;
F_3 () ;
}
if ( V_5 & V_7 )
return - V_9 ;
else if ( V_5 & V_8 )
return - V_10 ;
return 0 ;
}
static int F_4 ( void * V_11 , unsigned int V_12 ,
void * V_13 , T_1 V_14 )
{
struct V_1 * V_2 = V_11 ;
T_2 * V_15 = V_13 ;
int V_16 ;
V_16 = F_5 ( V_2 -> V_17 ) ;
if ( V_16 )
return V_16 ;
F_6 ( V_8 , V_2 -> V_6 + V_18 ) ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 )
goto V_19;
F_6 ( V_20 , V_2 -> V_6 + V_21 ) ;
F_7 ( 1 ) ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 )
goto V_22;
while ( V_14 ) {
if ( ( V_12 < V_23 ) || ( V_12 % 16 ) ) {
* V_15 ++ = 0 ;
} else {
* V_15 ++ = F_2 ( V_2 -> V_6 + V_12 ) ;
}
V_14 -= 4 ;
V_12 += 4 ;
}
V_22:
F_6 ( V_20 , V_2 -> V_6 + V_18 ) ;
V_19:
F_8 ( V_2 -> V_17 ) ;
return V_16 ;
}
static int F_9 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_25 -> V_27 ;
const struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
const struct V_32 * V_33 ;
int V_16 ;
V_33 = F_10 ( V_27 -> V_34 -> V_35 , V_27 ) ;
if ( ! V_33 || ! V_33 -> V_29 )
return - V_36 ;
V_2 = F_11 ( V_27 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
V_31 = F_12 ( V_25 , V_39 , 0 ) ;
V_2 -> V_6 = F_13 ( V_27 , V_31 ) ;
if ( F_14 ( V_2 -> V_6 ) )
return F_15 ( V_2 -> V_6 ) ;
V_2 -> V_17 = F_16 ( & V_25 -> V_27 , NULL ) ;
if ( F_14 ( V_2 -> V_17 ) )
return F_15 ( V_2 -> V_17 ) ;
V_16 = F_17 ( V_2 -> V_17 ) ;
if ( V_16 < 0 ) {
F_18 ( V_27 , L_1 , V_16 ) ;
return V_16 ;
}
V_29 = V_33 -> V_29 ;
V_40 . V_41 = V_29 -> V_41 ;
V_40 . V_42 = V_2 ;
V_40 . V_27 = V_27 ;
V_2 -> V_43 = F_19 ( & V_40 ) ;
if ( F_14 ( V_2 -> V_43 ) ) {
V_16 = F_15 ( V_2 -> V_43 ) ;
goto V_44;
}
F_20 ( V_25 , V_2 ) ;
return 0 ;
V_44:
F_21 ( V_2 -> V_17 ) ;
return V_16 ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_23 ( V_25 ) ;
F_21 ( V_2 -> V_17 ) ;
return F_24 ( V_2 -> V_43 ) ;
}
