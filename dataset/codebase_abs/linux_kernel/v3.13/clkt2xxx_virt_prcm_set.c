unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return V_4 -> V_5 ;
}
long F_2 ( struct V_1 * V_6 , unsigned long V_7 ,
unsigned long * V_3 )
{
const struct V_8 * V_9 ;
long V_10 ;
V_10 = - V_11 ;
for ( V_9 = V_12 ; V_9 -> V_5 ; V_9 ++ ) {
if ( ! ( V_9 -> V_13 & V_14 ) )
continue;
if ( V_9 -> V_15 != V_16 )
continue;
V_10 = V_9 -> V_5 ;
if ( V_9 -> V_5 <= V_7 )
break;
}
return V_10 ;
}
int F_3 ( struct V_1 * V_6 , unsigned long V_7 ,
unsigned long V_3 )
{
T_1 V_17 , V_18 , V_19 = 0 ;
const struct V_8 * V_20 ;
unsigned long V_21 = 0 ;
unsigned long V_13 ;
for ( V_20 = V_12 ; V_20 -> V_5 ; V_20 ++ ) {
if ( ! ( V_20 -> V_13 & V_14 ) )
continue;
if ( V_20 -> V_15 != V_16 )
continue;
if ( V_20 -> V_5 <= V_7 ) {
V_21 = V_20 -> V_5 ;
break;
}
}
if ( ! V_21 ) {
F_4 ( V_22 L_1 ,
V_7 / 1000000 ) ;
return - V_11 ;
}
V_4 = V_20 ;
V_17 = F_5 () ;
if ( V_20 -> V_23 == V_17 / 2 ) {
F_6 ( V_24 , 1 ) ;
} else if ( V_20 -> V_23 == V_17 * 2 ) {
F_6 ( V_25 , 1 ) ;
} else if ( V_20 -> V_23 != V_17 ) {
F_7 ( V_13 ) ;
if ( V_20 -> V_23 == V_20 -> V_15 )
V_19 = 1 ;
if ( ( V_20 -> V_26 & V_27 ) ==
V_25 )
V_18 = V_25 ;
else
V_18 = V_24 ;
F_8 ( V_20 -> V_28 ,
V_20 -> V_29 ,
V_20 -> V_30 ,
V_20 -> V_31 ,
V_20 -> V_32 ) ;
F_6 ( V_25 , 1 ) ;
F_9 ( V_20 -> V_33 , V_20 -> V_34 ,
V_19 ) ;
F_10 ( F_11 () ) ;
F_6 ( V_18 , 0 ) ;
F_12 ( V_13 ) ;
}
return 0 ;
}
void F_13 ( void )
{
const struct V_8 * V_20 = NULL ;
unsigned long V_7 ;
V_7 = F_5 () ;
for ( V_20 = V_12 ; V_20 -> V_5 ; V_20 ++ ) {
if ( ! ( V_20 -> V_13 & V_14 ) )
continue;
if ( V_20 -> V_15 != V_16 )
continue;
if ( V_20 -> V_23 <= V_7 )
break;
}
V_4 = V_20 ;
}
void F_14 ( void )
{
struct V_2 * V_35 ;
V_35 = F_15 ( NULL , L_2 ) ;
if ( F_16 ( V_35 ) ) {
F_17 ( 1 , L_3 ) ;
} else {
V_16 = F_18 ( V_35 ) ;
F_19 ( V_35 ) ;
}
}
