static int F_1 (
struct V_1 * V_2 ,
struct V_3 V_4 [] ,
unsigned int * V_5 )
{
unsigned int V_6 = * V_5 ;
if ( ( * V_5 + V_7 ) > V_8 ) {
return - V_9 ;
}
F_2 ( & V_4 [ V_6 ] ) ;
F_3 ( & V_4 [ V_6 ] , V_2 -> V_10 , V_11 ) ;
F_4 ( & V_4 [ V_6 ] , V_12 ) ;
F_5 ( & V_4 [ V_6 ] , V_13 ) ;
F_6 ( & V_4 [ V_6 ] , V_14 ) ;
F_7 ( & V_4 [ V_6 ] , V_15 ) ;
F_8 ( & V_4 [ V_6 ] , V_16 ) ;
V_6 ++ ;
F_2 ( & V_4 [ V_6 ] ) ;
F_3 ( & V_4 [ V_6 ] , V_2 -> V_17 , V_18 ) ;
F_5 ( & V_4 [ V_6 ] , V_13 ) ;
F_6 ( & V_4 [ V_6 ] , V_14 ) ;
F_4 ( & V_4 [ V_6 ] , V_19 ) ;
F_7 ( & V_4 [ V_6 ] , V_15 ) ;
F_8 ( & V_4 [ V_6 ] , V_16 ) ;
V_6 ++ ;
F_2 ( & V_4 [ V_6 ] ) ;
F_9 ( & V_4 [ V_6 ] , 0 , V_18 ) ;
F_10 ( & V_4 [ V_6 ] , V_2 -> V_20 , V_18 ) ;
F_6 ( & V_4 [ V_6 ] , V_21 ) ;
V_6 ++ ;
F_2 ( & V_4 [ V_6 ] ) ;
F_9 ( & V_4 [ V_6 ] , 0 , V_22 ) ;
F_10 ( & V_4 [ V_6 ] , V_2 -> V_20 , V_22 ) ;
F_6 ( & V_4 [ V_6 ] , V_21 ) ;
V_6 ++ ;
* V_5 = V_6 ;
V_2 -> V_23 = V_24 ;
return 0 ;
}
int F_11 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
struct V_3 V_4 [ V_8 ] ;
unsigned int V_5 = 0 ;
int V_28 ;
F_12 ( V_2 -> V_29 , V_24 ) ;
V_2 -> V_10 = V_2 -> V_20 ;
V_2 -> V_17 = V_2 -> V_20 + V_11 ;
F_2 ( & V_4 [ V_5 ] ) ;
F_13 ( & V_4 [ V_5 ] , V_30 , V_2 -> V_31 ,
V_24 , V_32 ) ;
F_10 ( & V_4 [ V_5 ] , V_2 -> V_20 ,
V_24 ) ;
F_6 ( & V_4 [ V_5 ] , V_33 ) ;
V_5 ++ ;
V_28 = F_1 ( V_2 , V_4 , & V_5 ) ;
if ( F_14 ( V_28 != 0 ) )
return V_28 ;
return F_15 ( V_26 , V_4 , V_5 ) ;
}
void F_16 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
struct V_34 * V_34 = & V_26 -> V_35 -> V_36 ;
if ( ! V_2 )
return;
if ( V_2 -> V_29 ) {
memset ( V_2 -> V_29 , 0 , V_24 ) ;
F_17 ( V_34 , V_24 ,
V_2 -> V_29 ,
V_2 -> V_31 ) ;
}
V_2 -> V_20 = V_37 ;
F_18 ( V_2 ) ;
}
int F_19 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_34 * V_34 = & V_26 -> V_35 -> V_36 ;
int V_28 ;
V_26 -> V_27 = F_20 ( sizeof( * V_26 -> V_27 ) ,
V_38 ) ;
if ( ! V_26 -> V_27 ) {
F_21 ( L_1
L_2 , sizeof( * V_26 -> V_27 ) ) ;
V_28 = - V_39 ;
goto V_40;
}
V_2 = V_26 -> V_27 ;
V_2 -> V_29 = F_22 ( V_34 , V_24 ,
& V_2 -> V_31 ,
V_38 ) ;
if ( ! V_2 -> V_29 ) {
F_21 ( L_3
L_4 , V_24 ) ;
V_28 = - V_39 ;
goto V_40;
}
V_2 -> V_20 = F_23 ( V_26 , V_22 ) ;
if ( V_2 -> V_20 == V_37 ) {
F_21 ( L_5 ) ;
V_28 = - V_39 ;
goto V_40;
}
return F_11 ( V_26 ) ;
V_40:
F_16 ( V_26 ) ;
return V_28 ;
}
int F_24 (
struct V_25 * V_26 ,
T_1 V_41 [] ,
unsigned int V_42 ,
unsigned int V_43 ,
struct V_3 V_4 [] ,
unsigned int * V_5 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
unsigned int V_6 = * V_5 ;
unsigned int V_44 ;
if ( ( V_43 != V_18 ) &&
( V_43 != V_45 ) ) {
return - V_9 ;
}
if ( ( V_42 + 1 ) > V_8 ) {
return - V_9 ;
}
if ( V_42 > V_46 ) {
return - V_9 ;
}
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
F_2 ( & V_4 [ V_6 ] ) ;
F_3 ( & V_4 [ V_6 ] , ( V_2 -> V_20 +
V_2 -> V_23 ) ,
V_43 ) ;
F_25 ( & V_4 [ V_6 ] , V_41 [ V_44 ] , V_43 ,
V_32 , 0 ) ;
F_6 ( & V_4 [ V_6 ] , V_33 ) ;
V_6 ++ ;
}
F_2 ( & V_4 [ V_6 ] ) ;
F_26 ( & V_4 [ V_6 ] , 0 , 0xfffff0 ) ;
F_27 ( & V_4 [ V_6 ] , 0 , 0 , 1 ) ;
V_6 ++ ;
* V_5 = V_6 ;
V_2 -> V_23 += V_43 ;
if ( ( V_22 - V_2 -> V_23 ) < V_18 ) {
F_28 ( L_6 ) ;
return F_1 ( V_2 , V_4 , V_5 ) ;
}
return 0 ;
}
