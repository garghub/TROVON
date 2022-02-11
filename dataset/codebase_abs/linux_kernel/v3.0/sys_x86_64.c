static void F_1 ( unsigned long V_1 , unsigned long * V_2 ,
unsigned long * V_3 )
{
if ( ! F_2 ( V_4 ) && ( V_1 & V_5 ) ) {
unsigned long V_6 ;
* V_2 = 0x40000000 ;
* V_3 = 0x80000000 ;
if ( V_7 -> V_1 & V_8 ) {
V_6 = F_3 ( * V_2 , * V_2 + 0x02000000 , 0 ) ;
if ( V_6 )
* V_2 = V_6 ;
}
} else {
* V_2 = V_9 ;
* V_3 = V_10 ;
}
}
unsigned long
F_4 ( struct V_11 * V_12 , unsigned long V_13 ,
unsigned long V_14 , unsigned long V_15 , unsigned long V_1 )
{
struct V_16 * V_17 = V_7 -> V_17 ;
struct V_18 * V_19 ;
unsigned long V_20 ;
unsigned long V_2 , V_3 ;
if ( V_1 & V_21 )
return V_13 ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( V_14 > V_3 )
return - V_22 ;
if ( V_13 ) {
V_13 = F_5 ( V_13 ) ;
V_19 = F_6 ( V_17 , V_13 ) ;
if ( V_3 - V_14 >= V_13 &&
( ! V_19 || V_13 + V_14 <= V_19 -> V_23 ) )
return V_13 ;
}
if ( ( ( V_1 & V_5 ) || F_2 ( V_4 ) )
&& V_14 <= V_17 -> V_24 ) {
V_17 -> V_24 = 0 ;
V_17 -> V_25 = V_2 ;
}
V_13 = V_17 -> V_25 ;
if ( V_13 < V_2 )
V_13 = V_2 ;
V_20 = V_13 ;
V_26:
for ( V_19 = F_6 ( V_17 , V_13 ) ; ; V_19 = V_19 -> V_27 ) {
if ( V_3 - V_14 < V_13 ) {
if ( V_20 != V_2 ) {
V_20 = V_13 = V_2 ;
V_17 -> V_24 = 0 ;
goto V_26;
}
return - V_22 ;
}
if ( ! V_19 || V_13 + V_14 <= V_19 -> V_23 ) {
V_17 -> V_25 = V_13 + V_14 ;
return V_13 ;
}
if ( V_13 + V_17 -> V_24 < V_19 -> V_23 )
V_17 -> V_24 = V_19 -> V_23 - V_13 ;
V_13 = V_19 -> V_28 ;
}
}
unsigned long
F_7 ( struct V_11 * V_12 , const unsigned long V_29 ,
const unsigned long V_14 , const unsigned long V_15 ,
const unsigned long V_1 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 = V_7 -> V_17 ;
unsigned long V_13 = V_29 ;
if ( V_14 > V_10 )
return - V_22 ;
if ( V_1 & V_21 )
return V_13 ;
if ( ! F_2 ( V_4 ) && ( V_1 & V_5 ) )
goto V_30;
if ( V_13 ) {
V_13 = F_5 ( V_13 ) ;
V_19 = F_6 ( V_17 , V_13 ) ;
if ( V_10 - V_14 >= V_13 &&
( ! V_19 || V_13 + V_14 <= V_19 -> V_23 ) )
return V_13 ;
}
if ( V_14 <= V_17 -> V_24 ) {
V_17 -> V_24 = 0 ;
V_17 -> V_25 = V_17 -> V_31 ;
}
V_13 = V_17 -> V_25 ;
if ( V_13 > V_14 ) {
V_19 = F_6 ( V_17 , V_13 - V_14 ) ;
if ( ! V_19 || V_13 <= V_19 -> V_23 )
return V_17 -> V_25 = V_13 - V_14 ;
}
if ( V_17 -> V_31 < V_14 )
goto V_30;
V_13 = V_17 -> V_31 - V_14 ;
do {
V_19 = F_6 ( V_17 , V_13 ) ;
if ( ! V_19 || V_13 + V_14 <= V_19 -> V_23 )
return V_17 -> V_25 = V_13 ;
if ( V_13 + V_17 -> V_24 < V_19 -> V_23 )
V_17 -> V_24 = V_19 -> V_23 - V_13 ;
V_13 = V_19 -> V_23 - V_14 ;
} while ( V_14 < V_19 -> V_23 );
V_30:
V_17 -> V_24 = ~ 0UL ;
V_17 -> V_25 = V_9 ;
V_13 = F_4 ( V_12 , V_29 , V_14 , V_15 , V_1 ) ;
V_17 -> V_25 = V_17 -> V_31 ;
V_17 -> V_24 = ~ 0UL ;
return V_13 ;
}
