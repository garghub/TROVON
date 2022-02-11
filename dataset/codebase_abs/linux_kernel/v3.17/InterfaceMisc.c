static int F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 == TRUE ) {
F_2 ( V_2 -> V_3 , V_5 , 0 , 0 ,
L_1 ) ;
return - V_6 ;
}
if ( ( V_2 -> V_3 -> V_7 == TRUE ) &&
( V_2 -> V_3 -> V_8 >= V_9 ) ) {
F_2 ( V_2 -> V_3 , V_10 , V_11 ,
V_12 ,
L_2 ) ;
return - V_13 ;
}
if ( V_2 -> V_14 == TRUE || V_2 -> V_15 == TRUE ) {
F_2 ( V_2 -> V_3 , V_10 , V_11 ,
V_12 ,
L_3 ) ;
return - V_13 ;
}
return 0 ;
}
int F_3 ( struct V_1 * V_16 ,
unsigned int V_17 ,
void * V_18 ,
int V_19 )
{
int V_20 ;
int V_21 = 0 ;
if ( ! V_16 )
return - V_22 ;
V_21 = F_1 ( V_16 ) ;
if ( V_21 )
return V_21 ;
V_16 -> V_3 -> V_23 = TRUE ;
V_20 = F_4 ( V_16 -> V_24 ,
F_5 ( V_16 -> V_24 , 0 ) ,
0x02 ,
0xC2 ,
( V_17 & 0xFFFF ) ,
( ( V_17 >> 16 ) & 0xFFFF ) ,
V_18 ,
V_19 ,
5000 ) ;
if ( - V_6 == V_20 )
V_16 -> V_3 -> V_4 = TRUE ;
if ( V_20 < 0 )
F_2 ( V_16 -> V_3 , V_10 , V_11 ,
V_12 , L_4 , V_20 ) ;
else
F_2 ( V_16 -> V_3 , V_10 , V_11 ,
V_12 , L_5 , V_20 ) ;
V_16 -> V_3 -> V_23 = false ;
return V_20 ;
}
int F_6 ( struct V_1 * V_16 ,
unsigned int V_17 ,
void * V_18 ,
int V_19 )
{
int V_25 = 0 ;
int V_21 = 0 ;
if ( ! V_16 )
return - V_22 ;
V_21 = F_1 ( V_16 ) ;
if ( V_21 )
return V_21 ;
V_16 -> V_3 -> V_23 = TRUE ;
V_25 = F_4 ( V_16 -> V_24 ,
F_7 ( V_16 -> V_24 , 0 ) ,
0x01 ,
0x42 ,
( V_17 & 0xFFFF ) ,
( ( V_17 >> 16 ) & 0xFFFF ) ,
V_18 ,
V_19 ,
5000 ) ;
if ( - V_6 == V_25 )
V_16 -> V_3 -> V_4 = TRUE ;
if ( V_25 < 0 ) {
F_2 ( V_16 -> V_3 , V_10 , V_26 ,
V_12 , L_6 , V_25 ) ;
V_16 -> V_3 -> V_23 = false ;
return V_25 ;
} else {
V_16 -> V_3 -> V_23 = false ;
F_2 ( V_16 -> V_3 , V_10 , V_26 ,
V_12 , L_7 , V_25 ) ;
return V_27 ;
}
}
int F_8 ( void * V_28 ,
unsigned int V_17 ,
void * V_18 ,
int V_19 )
{
return F_3 ( (struct V_1 * ) V_28 , V_17 , V_18 ,
V_19 ) ;
}
int F_9 ( void * V_28 ,
unsigned int V_17 ,
void * V_18 ,
int V_19 )
{
return F_6 ( (struct V_1 * ) V_28 , V_17 , V_18 ,
V_19 ) ;
}
int F_10 ( struct V_29 * V_30 )
{
struct V_1 * V_16 =
(struct V_1 * ) ( V_30 -> V_31 ) ;
int V_32 = V_27 ;
F_11 ( V_16 ) ;
V_32 = F_12 ( V_16 -> V_24 ,
V_16 -> V_33 . V_34 ) ;
if ( V_32 != V_27 )
F_2 ( V_30 , V_10 , V_35 ,
V_12 ,
L_8 ,
V_32 ) ;
V_32 = F_12 ( V_16 -> V_24 ,
V_16 -> V_36 . V_37 ) ;
if ( V_32 != V_27 )
F_2 ( V_30 , V_10 , V_35 ,
V_12 ,
L_9 ,
V_32 ) ;
V_32 = F_12 ( V_16 -> V_24 ,
V_16 -> V_38 . V_39 ) ;
if ( V_32 != V_27 )
F_2 ( V_30 , V_10 , V_35 ,
V_12 ,
L_10 ,
V_32 ) ;
return V_32 ;
}
void F_11 ( struct V_1 * V_16 )
{
struct V_40 * V_41 = NULL ;
unsigned int V_42 ;
if ( V_16 -> V_43 ) {
if ( V_16 -> V_43 -> V_32 == - V_44 )
F_13 ( V_16 -> V_43 ) ;
}
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
V_41 = V_16 -> V_46 [ V_42 ] . V_40 ;
if ( V_41 ) {
if ( V_41 -> V_32 == - V_44 )
F_13 ( V_41 ) ;
}
}
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ ) {
V_41 = V_16 -> V_48 [ V_42 ] . V_40 ;
if ( V_41 ) {
if ( V_41 -> V_32 == - V_44 )
F_13 ( V_41 ) ;
}
}
F_14 ( & V_16 -> V_49 , 0 ) ;
F_14 ( & V_16 -> V_50 , 0 ) ;
F_14 ( & V_16 -> V_51 , 0 ) ;
F_14 ( & V_16 -> V_52 , 0 ) ;
}
void F_15 ( struct V_53 * V_54 )
{
struct V_1 * V_16 = NULL ;
struct V_55 * V_56 = NULL ;
V_16 = F_16 ( V_54 , struct V_1 ,
V_57 ) ;
V_56 = V_16 -> V_58 ;
if ( V_16 -> V_14 == false )
F_17 ( V_56 ) ;
}
