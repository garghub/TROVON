void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_5 )
{
const struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return;
for ( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
unsigned long V_13 ;
int V_14 ;
V_13 = F_3 ( V_12 [ V_10 ] . V_15 , 0 ) ;
V_14 = F_4 ( V_2 , V_5 , & V_13 ) ;
if ( V_14 == - V_16 || V_14 == - V_17 )
continue;
if ( V_14 ) {
F_5 ( V_4 , L_1 , V_10 ) ;
continue;
}
F_6 ( V_4 , L_2 ) ;
F_6 ( V_4 , V_12 [ V_10 ] . V_18 ) ;
if ( V_12 [ V_10 ] . V_19 &&
F_7 ( V_13 ) != 0 )
F_5 ( V_4 , L_3 ,
F_7 ( V_13 ) ,
V_12 [ V_10 ] . V_19 ) ;
}
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_20 )
{
const struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return;
for ( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
unsigned long V_13 ;
int V_14 ;
V_13 = F_3 ( V_12 [ V_10 ] . V_15 , 0 ) ;
V_14 = F_9 ( F_10 ( V_2 -> V_21 ) , V_20 ,
& V_13 ) ;
if ( V_14 == - V_16 || V_14 == - V_17 )
continue;
if ( V_14 ) {
F_5 ( V_4 , L_1 , V_10 ) ;
continue;
}
F_6 ( V_4 , L_2 ) ;
F_6 ( V_4 , V_12 [ V_10 ] . V_18 ) ;
if ( V_12 [ V_10 ] . V_19 && V_13 != 0 )
F_5 ( V_4 , L_3 ,
F_7 ( V_13 ) ,
V_12 [ V_10 ] . V_19 ) ;
}
}
void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_13 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
if ( F_12 ( V_13 ) != V_12 [ V_10 ] . V_15 )
continue;
F_5 ( V_4 , L_4 , V_12 [ V_10 ] . V_18 ,
F_7 ( V_13 ) ) ;
}
}
int F_13 ( struct V_22 * V_23 ,
unsigned long * * V_24 ,
unsigned int * V_25 )
{
unsigned long * V_26 ;
unsigned int V_27 = 0 ;
int V_14 ;
int V_10 ;
T_1 V_28 ;
if ( ! V_23 )
return - V_16 ;
V_26 = F_14 ( sizeof( * V_26 ) * F_2 ( V_29 ) , V_30 ) ;
if ( ! V_26 )
return - V_31 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_29 ) ; V_10 ++ ) {
struct V_32 * V_33 = & V_29 [ V_10 ] ;
V_14 = F_15 ( V_23 , V_33 -> V_34 , & V_28 ) ;
if ( V_14 == - V_16 )
continue;
if ( V_14 )
V_28 = V_33 -> V_35 ;
F_16 ( L_5 , V_33 -> V_34 , V_28 ) ;
V_26 [ V_27 ] = F_3 ( V_33 -> V_15 , V_28 ) ;
V_27 ++ ;
}
V_14 = 0 ;
if ( V_27 == 0 ) {
* V_24 = NULL ;
* V_25 = 0 ;
goto V_36;
}
* V_24 = F_14 ( V_27 * sizeof( unsigned long ) , V_30 ) ;
if ( ! * V_24 ) {
V_14 = - V_31 ;
goto V_36;
}
memcpy ( * V_24 , V_26 , V_27 * sizeof( unsigned long ) ) ;
* V_25 = V_27 ;
V_36:
F_17 ( V_26 ) ;
return V_14 ;
}
