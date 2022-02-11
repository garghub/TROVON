unsigned long F_1 ( unsigned long V_1 , struct V_2 * V_3 ,
enum V_4 V_5 )
{
unsigned long V_6 ;
if ( V_7 . V_5 < 0 || ! ( V_7 . V_5 & ( 2 - F_2 () ) ) )
return V_1 ;
if ( ! ( V_8 -> V_5 & V_9 ) )
return V_1 ;
if ( ! ( ( V_5 & V_10 ) || V_3 ) )
return V_1 ;
V_6 = V_1 ;
if ( ! ( V_5 & V_11 ) )
V_6 += V_7 . V_12 ;
V_6 &= ~ V_7 . V_12 ;
return V_6 ;
}
static int T_1 F_3 ( char * V_13 )
{
if ( V_7 . V_5 < 0 )
return 1 ;
if ( * V_13 == 0 )
return 1 ;
if ( * V_13 == '=' )
V_13 ++ ;
if ( ! strcmp ( V_13 , L_1 ) )
V_7 . V_5 = V_14 ;
else if ( ! strcmp ( V_13 , L_2 ) )
V_7 . V_5 = V_15 ;
else if ( ! strcmp ( V_13 , L_3 ) )
V_7 . V_5 = 0 ;
else if ( ! strcmp ( V_13 , L_4 ) )
V_7 . V_5 = V_14 | V_15 ;
else
return 0 ;
return 1 ;
}
static void F_4 ( unsigned long V_5 , unsigned long * V_16 ,
unsigned long * V_17 )
{
if ( ! F_5 ( V_18 ) && ( V_5 & V_19 ) ) {
unsigned long V_20 ;
* V_16 = 0x40000000 ;
* V_17 = 0x80000000 ;
if ( V_8 -> V_5 & V_9 ) {
V_20 = F_6 ( * V_16 , * V_16 + 0x02000000 , 0 ) ;
if ( V_20 )
* V_16 = V_20 ;
}
} else {
* V_16 = V_21 ;
* V_17 = V_22 ;
}
}
unsigned long
F_7 ( struct V_2 * V_3 , unsigned long V_1 ,
unsigned long V_23 , unsigned long V_24 , unsigned long V_5 )
{
struct V_25 * V_26 = V_8 -> V_26 ;
struct V_27 * V_28 ;
unsigned long V_29 ;
unsigned long V_16 , V_17 ;
if ( V_5 & V_30 )
return V_1 ;
F_4 ( V_5 , & V_16 , & V_17 ) ;
if ( V_23 > V_17 )
return - V_31 ;
if ( V_1 ) {
V_1 = F_8 ( V_1 ) ;
V_28 = F_9 ( V_26 , V_1 ) ;
if ( V_17 - V_23 >= V_1 &&
( ! V_28 || V_1 + V_23 <= V_28 -> V_32 ) )
return V_1 ;
}
if ( ( ( V_5 & V_19 ) || F_5 ( V_18 ) )
&& V_23 <= V_26 -> V_33 ) {
V_26 -> V_33 = 0 ;
V_26 -> V_34 = V_16 ;
}
V_1 = V_26 -> V_34 ;
if ( V_1 < V_16 )
V_1 = V_16 ;
V_29 = V_1 ;
V_35:
V_1 = F_1 ( V_1 , V_3 , 0 ) ;
for ( V_28 = F_9 ( V_26 , V_1 ) ; ; V_28 = V_28 -> V_36 ) {
if ( V_17 - V_23 < V_1 ) {
if ( V_29 != V_16 ) {
V_29 = V_1 = V_16 ;
V_26 -> V_33 = 0 ;
goto V_35;
}
return - V_31 ;
}
if ( ! V_28 || V_1 + V_23 <= V_28 -> V_32 ) {
V_26 -> V_34 = V_1 + V_23 ;
return V_1 ;
}
if ( V_1 + V_26 -> V_33 < V_28 -> V_32 )
V_26 -> V_33 = V_28 -> V_32 - V_1 ;
V_1 = V_28 -> V_37 ;
V_1 = F_1 ( V_1 , V_3 , 0 ) ;
}
}
unsigned long
F_10 ( struct V_2 * V_3 , const unsigned long V_38 ,
const unsigned long V_23 , const unsigned long V_24 ,
const unsigned long V_5 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 = V_8 -> V_26 ;
unsigned long V_1 = V_38 ;
if ( V_23 > V_22 )
return - V_31 ;
if ( V_5 & V_30 )
return V_1 ;
if ( ! F_5 ( V_18 ) && ( V_5 & V_19 ) )
goto V_39;
if ( V_1 ) {
V_1 = F_8 ( V_1 ) ;
V_28 = F_9 ( V_26 , V_1 ) ;
if ( V_22 - V_23 >= V_1 &&
( ! V_28 || V_1 + V_23 <= V_28 -> V_32 ) )
return V_1 ;
}
if ( V_23 <= V_26 -> V_33 ) {
V_26 -> V_33 = 0 ;
V_26 -> V_34 = V_26 -> V_40 ;
}
V_1 = V_26 -> V_34 ;
if ( V_1 > V_23 ) {
unsigned long V_6 = F_1 ( V_1 - V_23 , V_3 ,
V_11 ) ;
V_28 = F_9 ( V_26 , V_6 ) ;
if ( ! V_28 || V_6 + V_23 <= V_28 -> V_32 )
return V_26 -> V_34 = V_6 ;
}
if ( V_26 -> V_40 < V_23 )
goto V_39;
V_1 = V_26 -> V_40 - V_23 ;
do {
V_1 = F_1 ( V_1 , V_3 , V_11 ) ;
V_28 = F_9 ( V_26 , V_1 ) ;
if ( ! V_28 || V_1 + V_23 <= V_28 -> V_32 )
return V_26 -> V_34 = V_1 ;
if ( V_1 + V_26 -> V_33 < V_28 -> V_32 )
V_26 -> V_33 = V_28 -> V_32 - V_1 ;
V_1 = V_28 -> V_32 - V_23 ;
} while ( V_23 < V_28 -> V_32 );
V_39:
V_26 -> V_33 = ~ 0UL ;
V_26 -> V_34 = V_21 ;
V_1 = F_7 ( V_3 , V_38 , V_23 , V_24 , V_5 ) ;
V_26 -> V_34 = V_26 -> V_40 ;
V_26 -> V_33 = ~ 0UL ;
return V_1 ;
}
