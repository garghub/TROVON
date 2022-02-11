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
T_1 V_17 , V_18 , V_19 = 0 , V_20 ;
const struct V_8 * V_21 ;
unsigned long V_22 = 0 ;
unsigned long V_13 ;
for ( V_21 = V_12 ; V_21 -> V_5 ; V_21 ++ ) {
if ( ! ( V_21 -> V_13 & V_14 ) )
continue;
if ( V_21 -> V_15 != V_16 )
continue;
if ( V_21 -> V_5 <= V_7 ) {
V_22 = V_21 -> V_5 ;
break;
}
}
if ( ! V_22 ) {
F_4 ( V_23 L_1 ,
V_7 / 1000000 ) ;
return - V_11 ;
}
V_4 = V_21 ;
V_17 = F_5 () ;
if ( V_21 -> V_24 == V_17 / 2 ) {
F_6 ( V_25 , 1 ) ;
} else if ( V_21 -> V_24 == V_17 * 2 ) {
F_6 ( V_26 , 1 ) ;
} else if ( V_21 -> V_24 != V_17 ) {
F_7 ( V_13 ) ;
if ( V_21 -> V_24 == V_21 -> V_15 )
V_19 = 1 ;
if ( ( V_21 -> V_27 & V_28 ) ==
V_26 )
V_18 = V_26 ;
else
V_18 = V_25 ;
F_8 ( V_21 -> V_29 , V_30 , V_31 ) ;
F_8 ( V_21 -> V_32 ,
V_33 , V_31 ) ;
F_8 ( V_21 -> V_34 , V_35 , V_31 ) ;
V_20 = F_9 ( V_36 , V_37 ) & V_38 ;
F_8 ( V_21 -> V_39 | V_20 , V_36 ,
V_37 ) ;
if ( F_10 () )
F_8 ( V_21 -> V_40 ,
V_41 , V_31 ) ;
F_6 ( V_26 , 1 ) ;
F_11 ( V_21 -> V_42 , V_21 -> V_43 ,
V_19 ) ;
F_12 ( F_13 () ) ;
F_6 ( V_18 , 0 ) ;
F_14 ( V_13 ) ;
}
return 0 ;
}
void F_15 ( void )
{
const struct V_8 * V_21 = NULL ;
unsigned long V_7 ;
V_7 = F_5 () ;
for ( V_21 = V_12 ; V_21 -> V_5 ; V_21 ++ ) {
if ( ! ( V_21 -> V_13 & V_14 ) )
continue;
if ( V_21 -> V_15 != V_16 )
continue;
if ( V_21 -> V_24 <= V_7 )
break;
}
V_4 = V_21 ;
}
void F_16 ( void )
{
struct V_2 * V_44 ;
V_44 = F_17 ( NULL , L_2 ) ;
if ( F_18 ( V_44 ) ) {
F_19 ( 1 , L_3 ) ;
} else {
V_16 = F_20 ( V_44 ) ;
F_21 ( V_44 ) ;
}
}
