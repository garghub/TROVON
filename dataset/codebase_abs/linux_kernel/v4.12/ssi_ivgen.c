static int F_1 (
struct V_1 * V_2 ,
T_1 V_3 [] ,
unsigned int * V_4 )
{
unsigned int V_5 = * V_4 ;
if ( ( * V_4 + V_6 ) > V_7 ) {
return - V_8 ;
}
F_2 ( & V_3 [ V_5 ] ) ;
F_3 ( & V_3 [ V_5 ] , V_2 -> V_9 , V_10 ) ;
F_4 ( & V_3 [ V_5 ] , V_11 ) ;
F_5 ( & V_3 [ V_5 ] , V_12 ) ;
F_6 ( & V_3 [ V_5 ] , V_13 ) ;
F_7 ( & V_3 [ V_5 ] , V_14 ) ;
F_8 ( & V_3 [ V_5 ] , V_15 ) ;
V_5 ++ ;
F_2 ( & V_3 [ V_5 ] ) ;
F_3 ( & V_3 [ V_5 ] , V_2 -> V_16 , V_17 ) ;
F_5 ( & V_3 [ V_5 ] , V_12 ) ;
F_6 ( & V_3 [ V_5 ] , V_13 ) ;
F_4 ( & V_3 [ V_5 ] , V_18 ) ;
F_7 ( & V_3 [ V_5 ] , V_14 ) ;
F_8 ( & V_3 [ V_5 ] , V_15 ) ;
V_5 ++ ;
F_2 ( & V_3 [ V_5 ] ) ;
F_9 ( & V_3 [ V_5 ] , 0 , V_17 ) ;
F_10 ( & V_3 [ V_5 ] , V_2 -> V_19 , V_17 ) ;
F_6 ( & V_3 [ V_5 ] , V_20 ) ;
V_5 ++ ;
F_2 ( & V_3 [ V_5 ] ) ;
F_9 ( & V_3 [ V_5 ] , 0 , V_21 ) ;
F_10 ( & V_3 [ V_5 ] , V_2 -> V_19 , V_21 ) ;
F_6 ( & V_3 [ V_5 ] , V_20 ) ;
V_5 ++ ;
* V_4 = V_5 ;
V_2 -> V_22 = V_23 ;
return 0 ;
}
int F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
T_1 V_3 [ V_7 ] ;
unsigned int V_4 = 0 ;
int V_27 ;
F_12 ( V_2 -> V_28 , V_23 ) ;
V_2 -> V_9 = V_2 -> V_19 ;
V_2 -> V_16 = V_2 -> V_19 + V_10 ;
F_2 ( & V_3 [ V_4 ] ) ;
F_13 ( & V_3 [ V_4 ] , V_29 ,
V_2 -> V_30 , V_23 ,
V_31 ) ;
F_10 ( & V_3 [ V_4 ] , V_2 -> V_19 ,
V_23 ) ;
F_6 ( & V_3 [ V_4 ] , V_32 ) ;
V_4 ++ ;
V_27 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( F_14 ( V_27 != 0 ) ) {
return V_27 ;
}
return F_15 ( V_25 , V_3 , V_4 ) ;
}
void F_16 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_33 * V_33 = & ( V_25 -> V_34 -> V_35 ) ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_28 != NULL ) {
memset ( V_2 -> V_28 , 0 , V_23 ) ;
F_17 ( V_2 -> V_30 ) ;
F_18 ( V_33 , V_23 ,
V_2 -> V_28 , V_2 -> V_30 ) ;
}
V_2 -> V_19 = V_36 ;
F_19 ( V_2 ) ;
}
int F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_33 * V_33 = & V_25 -> V_34 -> V_35 ;
int V_27 ;
V_25 -> V_26 = F_21 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_25 -> V_26 ) {
F_22 ( L_1
L_2 , sizeof( struct V_1 ) ) ;
V_27 = - V_38 ;
goto V_39;
}
V_2 = V_25 -> V_26 ;
V_2 -> V_28 = F_23 ( V_33 , V_23 ,
& V_2 -> V_30 , V_37 ) ;
if ( ! V_2 -> V_28 ) {
F_22 ( L_3
L_4 , V_23 ) ;
V_27 = - V_38 ;
goto V_39;
}
F_24 ( V_2 -> V_30 ,
V_23 ) ;
V_2 -> V_19 = F_25 ( V_25 , V_21 ) ;
if ( V_2 -> V_19 == V_36 ) {
F_22 ( L_5 ) ;
V_27 = - V_38 ;
goto V_39;
}
return F_11 ( V_25 ) ;
V_39:
F_16 ( V_25 ) ;
return V_27 ;
}
int F_26 (
struct V_24 * V_25 ,
T_2 V_40 [] ,
unsigned int V_41 ,
unsigned int V_42 ,
T_1 V_3 [] ,
unsigned int * V_4 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
unsigned int V_5 = * V_4 ;
unsigned int V_43 ;
if ( ( V_42 != V_17 ) &&
( V_42 != V_44 ) ) {
return - V_8 ;
}
if ( ( V_41 + 1 ) > V_7 ) {
return - V_8 ;
}
if ( V_41 > V_45 ) {
return - V_8 ;
}
for ( V_43 = 0 ; V_43 < V_41 ; V_43 ++ ) {
F_2 ( & V_3 [ V_5 ] ) ;
F_3 ( & V_3 [ V_5 ] ,
V_2 -> V_19 + V_2 -> V_22 ,
V_42 ) ;
F_27 ( & V_3 [ V_5 ] , V_40 [ V_43 ] ,
V_42 , V_31 , 0 ) ;
F_6 ( & V_3 [ V_5 ] , V_32 ) ;
V_5 ++ ;
}
F_2 ( & V_3 [ V_5 ] ) ;
F_28 ( & V_3 [ V_5 ] , 0 , 0xfffff0 ) ;
F_29 ( & V_3 [ V_5 ] , 0 , 0 , 1 ) ;
V_5 ++ ;
* V_4 = V_5 ;
V_2 -> V_22 += V_42 ;
if ( ( V_21 - V_2 -> V_22 ) < V_17 ) {
F_30 ( L_6 ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
return 0 ;
}
