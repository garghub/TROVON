int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
void * V_4 ,
int V_5 )
{
int V_6 ;
if ( ! V_2 )
return - V_7 ;
if ( V_2 -> V_8 -> V_9 == TRUE ) {
F_2 ( V_2 -> V_8 , V_10 , 0 , 0 , L_1 ) ;
return - V_11 ;
}
if ( ( V_2 -> V_8 -> V_12 == TRUE ) && ( V_2 -> V_8 -> V_13 >= V_14 ) ) {
F_2 ( V_2 -> V_8 , V_15 , V_16 , V_17 , L_2 ) ;
return - V_18 ;
}
if ( V_2 -> V_19 == TRUE || V_2 -> V_20 == TRUE ) {
F_2 ( V_2 -> V_8 , V_15 , V_16 , V_17 , L_3 ) ;
return - V_18 ;
}
V_2 -> V_8 -> V_21 = TRUE ;
V_6 = F_3 ( V_2 -> V_22 ,
F_4 ( V_2 -> V_22 , 0 ) ,
0x02 ,
0xC2 ,
( V_3 & 0xFFFF ) ,
( ( V_3 >> 16 ) & 0xFFFF ) ,
V_4 ,
V_5 ,
5000 ) ;
if ( - V_11 == V_6 )
V_2 -> V_8 -> V_9 = TRUE ;
if ( V_6 < 0 )
F_2 ( V_2 -> V_8 , V_15 , V_16 , V_17 , L_4 , V_6 ) ;
else
F_2 ( V_2 -> V_8 , V_15 , V_16 , V_17 , L_5 , V_6 ) ;
V_2 -> V_8 -> V_21 = false ;
return V_6 ;
}
int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 ,
void * V_4 ,
int V_5 )
{
int V_23 = 0 ;
if ( ! V_2 )
return - V_7 ;
if ( V_2 -> V_8 -> V_9 == TRUE ) {
F_2 ( V_2 -> V_8 , V_10 , 0 , 0 , L_1 ) ;
return - V_11 ;
}
if ( ( V_2 -> V_8 -> V_12 == TRUE ) && ( V_2 -> V_8 -> V_13 >= V_14 ) ) {
F_2 ( V_2 -> V_8 , V_15 , V_24 , V_17 , L_6 ) ;
return - V_18 ;
}
if ( V_2 -> V_19 == TRUE || V_2 -> V_20 == TRUE ) {
F_2 ( V_2 -> V_8 , V_15 , V_24 , V_17 , L_3 ) ;
return - V_18 ;
}
V_2 -> V_8 -> V_21 = TRUE ;
V_23 = F_3 ( V_2 -> V_22 ,
F_6 ( V_2 -> V_22 , 0 ) ,
0x01 ,
0x42 ,
( V_3 & 0xFFFF ) ,
( ( V_3 >> 16 ) & 0xFFFF ) ,
V_4 ,
V_5 ,
5000 ) ;
if ( - V_11 == V_23 )
V_2 -> V_8 -> V_9 = TRUE ;
if ( V_23 < 0 ) {
F_2 ( V_2 -> V_8 , V_15 , V_24 , V_17 , L_7 , V_23 ) ;
V_2 -> V_8 -> V_21 = false ;
return V_23 ;
} else {
V_2 -> V_8 -> V_21 = false ;
F_2 ( V_2 -> V_8 , V_15 , V_24 , V_17 , L_8 , V_23 ) ;
return V_25 ;
}
}
int F_7 ( void * V_26 ,
unsigned int V_3 ,
void * V_4 ,
int V_5 )
{
return F_1 ( (struct V_1 * ) V_26 , V_3 , V_4 , V_5 ) ;
}
int F_8 ( void * V_26 ,
unsigned int V_3 ,
void * V_4 ,
int V_5 )
{
return F_5 ( (struct V_1 * ) V_26 , V_3 , V_4 , V_5 ) ;
}
int F_9 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_28 -> V_29 ) ;
int V_30 = V_25 ;
F_10 ( V_2 ) ;
V_30 = F_11 ( V_2 -> V_22 , V_2 -> V_31 . V_32 ) ;
if ( V_30 != V_25 )
F_2 ( V_28 , V_15 , V_33 , V_17 , L_9 , V_30 ) ;
V_30 = F_11 ( V_2 -> V_22 , V_2 -> V_34 . V_35 ) ;
if ( V_30 != V_25 )
F_2 ( V_28 , V_15 , V_33 , V_17 , L_10 , V_30 ) ;
V_30 = F_11 ( V_2 -> V_22 , V_2 -> V_36 . V_37 ) ;
if ( V_30 != V_25 )
F_2 ( V_28 , V_15 , V_33 , V_17 , L_11 , V_30 ) ;
return V_30 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = NULL ;
unsigned int V_40 ;
if ( V_2 -> V_41 ) {
if ( V_2 -> V_41 -> V_30 == - V_42 )
F_12 ( V_2 -> V_41 ) ;
}
for ( V_40 = 0 ; V_40 < V_43 ; V_40 ++ ) {
V_39 = V_2 -> V_44 [ V_40 ] . V_38 ;
if ( V_39 ) {
if ( V_39 -> V_30 == - V_42 )
F_12 ( V_39 ) ;
}
}
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
V_39 = V_2 -> V_46 [ V_40 ] . V_38 ;
if ( V_39 ) {
if ( V_39 -> V_30 == - V_42 )
F_12 ( V_39 ) ;
}
}
F_13 ( & V_2 -> V_47 , 0 ) ;
F_13 ( & V_2 -> V_48 , 0 ) ;
F_13 ( & V_2 -> V_49 , 0 ) ;
F_13 ( & V_2 -> V_50 , 0 ) ;
}
void F_14 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = NULL ;
struct V_53 * V_54 = NULL ;
V_2 = F_15 ( V_52 , struct V_1 , V_55 ) ;
V_54 = V_2 -> V_56 ;
if ( V_2 -> V_19 == false )
F_16 ( V_54 ) ;
}
