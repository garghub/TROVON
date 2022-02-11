static int F_1 ( struct V_1 * V_2 , unsigned int type )
{
T_1 V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_6 = V_5 -> V_6 [ V_3 ] ;
void T_3 * V_7 ;
T_4 V_8 , V_9 , V_10 ;
unsigned long V_11 ;
int V_12 ;
V_7 = V_5 -> V_13 [ V_6 ] ;
V_9 = V_5 -> V_14 [ V_3 ] ;
V_8 = V_3 & 0x1f ;
F_2 ( & V_5 -> V_15 , V_11 ) ;
V_10 = F_3 ( V_7 + V_9 * 4 ) ;
if ( type == V_16 || type == V_17 ) {
if ( type == V_16 )
type = V_18 ;
else
type = V_19 ;
V_10 |= ( 1 << V_8 ) ;
} else {
V_10 &= ~ ( 1 << V_8 ) ;
}
F_4 ( V_10 , V_7 + V_9 * 4 ) ;
V_2 = V_2 -> V_20 ;
V_12 = V_2 -> V_21 -> V_22 ( V_2 , type ) ;
F_5 ( & V_5 -> V_15 , V_11 ) ;
return V_12 ;
}
static int F_6 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned long * V_3 ,
unsigned int * type )
{
if ( F_7 ( V_26 -> V_27 ) ) {
if ( V_26 -> V_28 != 3 )
return - V_29 ;
if ( V_26 -> V_30 [ 0 ] != 0 )
return - V_29 ;
* V_3 = V_26 -> V_30 [ 1 ] ;
* type = V_26 -> V_30 [ 2 ] & V_31 ;
return 0 ;
}
return - V_29 ;
}
static int F_8 ( struct V_23 * V_32 , unsigned int V_33 ,
unsigned int V_34 , void * V_35 )
{
int V_36 ;
T_1 V_3 ;
struct V_25 * V_26 = V_35 ;
struct V_25 V_37 = * V_26 ;
if ( V_26 -> V_28 != 3 )
return - V_29 ;
if ( V_26 -> V_30 [ 0 ] )
return - V_29 ;
V_3 = V_26 -> V_30 [ 1 ] ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ )
F_9 ( V_32 , V_33 + V_36 , V_3 + V_36 ,
& V_38 ,
V_32 -> V_39 ) ;
V_37 . V_27 = V_32 -> V_40 -> V_27 ;
return F_10 ( V_32 , V_33 , V_34 , & V_37 ) ;
}
static int T_5 F_11 ( struct V_41 * V_42 ,
struct V_41 * V_40 )
{
struct V_23 * V_32 , * V_43 ;
struct V_4 * V_5 ;
int V_12 , V_44 , V_45 = 0 , V_46 = 0 , V_36 = 0 ;
V_43 = F_12 ( V_40 ) ;
if ( ! V_43 ) {
F_13 ( L_1 ) ;
return - V_29 ;
}
V_5 = F_14 ( sizeof( * V_5 ) , V_47 ) ;
if ( ! V_5 )
return - V_48 ;
while ( F_15 ( V_42 , V_36 ++ , NULL , NULL ) )
V_46 ++ ;
if ( V_46 == 0 ) {
F_13 ( L_2 ) ;
V_12 = - V_29 ;
goto V_49;
}
V_5 -> V_50 = F_16 ( V_46 ,
sizeof( * V_5 -> V_50 ) ,
V_47 ) ;
if ( ! V_5 -> V_50 ) {
V_12 = - V_48 ;
goto V_49;
}
V_5 -> V_13 = F_16 ( V_46 ,
sizeof( * V_5 -> V_13 ) ,
V_47 ) ;
if ( ! V_5 -> V_13 ) {
V_12 = - V_48 ;
goto V_51;
}
for ( V_36 = 0 ; V_36 < V_46 ; V_36 ++ ) {
struct V_52 V_53 ;
V_12 = F_17 ( V_42 , V_36 , & V_53 ) ;
V_44 = F_18 ( & V_53 ) ;
V_45 += V_44 * 8 ;
V_5 -> V_50 [ V_36 ] = V_44 / 4 ;
V_5 -> V_13 [ V_36 ] = F_19 ( V_42 , V_36 ) ;
if ( V_12 || ! V_5 -> V_13 [ V_36 ] ) {
F_13 ( L_3 , V_42 , V_36 ) ;
V_12 = - V_54 ;
goto V_55;
}
}
V_5 -> V_6 = F_16 ( V_45 ,
sizeof( * V_5 -> V_6 ) ,
V_47 ) ;
if ( ! V_5 -> V_6 ) {
V_12 = - V_48 ;
goto V_55;
}
V_5 -> V_14 = F_16 ( V_45 ,
sizeof( * V_5 -> V_14 ) ,
V_47 ) ;
if ( ! V_5 -> V_14 ) {
V_12 = - V_48 ;
goto V_56;
}
for ( V_36 = 0 ; V_36 < V_45 ; V_36 ++ ) {
T_4 V_57 = V_36 / 32 , V_58 ;
for ( V_58 = 0 ; V_57 >= V_5 -> V_50 [ V_58 ] ; V_58 ++ )
V_57 -= V_5 -> V_50 [ V_58 ] ;
V_5 -> V_6 [ V_36 ] = V_58 ;
V_5 -> V_14 [ V_36 ] = V_57 ;
}
V_32 = F_20 ( V_43 , 0 , V_45 , V_42 ,
& V_59 , V_5 ) ;
if ( ! V_32 ) {
V_12 = - V_48 ;
goto V_60;
}
F_21 ( & V_5 -> V_15 ) ;
return 0 ;
V_60:
F_22 ( V_5 -> V_14 ) ;
V_56:
F_22 ( V_5 -> V_6 ) ;
V_55:
for ( V_36 = 0 ; V_36 < V_46 ; V_36 ++ )
if ( V_5 -> V_13 [ V_36 ] )
F_23 ( V_5 -> V_13 [ V_36 ] ) ;
F_22 ( V_5 -> V_13 ) ;
V_51:
F_22 ( V_5 -> V_50 ) ;
V_49:
F_22 ( V_5 ) ;
return V_12 ;
}
