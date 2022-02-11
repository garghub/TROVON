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
static int F_4 ( void * V_11 , const void * V_12 , T_1 V_13 ,
void * V_14 , T_1 V_15 )
{
struct V_1 * V_2 = V_11 ;
unsigned int V_16 = * ( V_17 * ) V_12 ;
V_17 * V_18 = V_14 ;
int V_19 ;
V_19 = F_5 ( V_2 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_8 , V_2 -> V_6 + V_21 ) ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 )
goto V_22;
F_6 ( V_23 , V_2 -> V_6 + V_24 ) ;
F_7 ( 1 ) ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 )
goto V_25;
while ( V_15 >= V_13 ) {
if ( ( V_16 < V_26 ) || ( V_16 % 16 ) ) {
* V_18 = 0 ;
} else {
* V_18 = F_2 ( V_2 -> V_6 + V_16 ) ;
}
V_18 ++ ;
V_15 -= V_13 ;
V_16 += V_13 ;
}
V_25:
F_6 ( V_23 , V_2 -> V_6 + V_21 ) ;
V_22:
F_8 ( V_2 -> V_20 ) ;
return V_19 ;
}
static int F_9 ( void * V_11 , const void * V_27 , T_1 V_28 )
{
return 0 ;
}
static bool F_10 ( struct V_29 * V_30 , unsigned int V_12 )
{
return false ;
}
static int F_11 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = & V_32 -> V_30 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
const struct V_35 * V_36 ;
struct V_37 * V_37 ;
const struct V_38 * V_39 ;
int V_19 ;
V_36 = F_12 ( V_30 -> V_40 -> V_41 , V_30 ) ;
if ( ! V_36 || ! V_36 -> V_27 )
return - V_42 ;
V_2 = F_13 ( V_30 , sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_34 = F_14 ( V_32 , V_45 , 0 ) ;
V_2 -> V_6 = F_15 ( V_30 , V_34 ) ;
if ( F_16 ( V_2 -> V_6 ) )
return F_17 ( V_2 -> V_6 ) ;
V_2 -> V_20 = F_18 ( & V_32 -> V_30 , NULL ) ;
if ( F_16 ( V_2 -> V_20 ) )
return F_17 ( V_2 -> V_20 ) ;
V_19 = F_19 ( V_2 -> V_20 ) ;
if ( V_19 < 0 ) {
F_20 ( V_30 , L_1 , V_19 ) ;
return V_19 ;
}
V_39 = V_36 -> V_27 ;
V_46 . V_47 = V_39 ;
V_46 . V_48 = V_39 -> V_49 [ 0 ] . V_50 ;
V_37 = F_21 ( V_30 , & V_51 , V_2 , & V_46 ) ;
if ( F_16 ( V_37 ) ) {
F_20 ( V_30 , L_2 ) ;
V_19 = F_17 ( V_37 ) ;
goto V_52;
}
V_53 . V_30 = V_30 ;
V_2 -> V_54 = F_22 ( & V_53 ) ;
if ( F_16 ( V_2 -> V_54 ) ) {
V_19 = F_17 ( V_2 -> V_54 ) ;
goto V_52;
}
F_23 ( V_32 , V_2 ) ;
return 0 ;
V_52:
F_24 ( V_2 -> V_20 ) ;
return V_19 ;
}
static int F_25 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_26 ( V_32 ) ;
F_24 ( V_2 -> V_20 ) ;
return F_27 ( V_2 -> V_54 ) ;
}
