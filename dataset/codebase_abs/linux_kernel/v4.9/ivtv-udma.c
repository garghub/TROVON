void F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 )
{
V_2 -> V_5 = V_3 & V_6 ;
V_2 -> V_7 = V_3 & ~ V_6 ;
V_2 -> V_8 = 1 + ( ( V_3 + V_4 - 1 ) & ~ V_6 ) ;
V_2 -> V_3 = ( V_3 & V_6 ) >> V_9 ;
V_2 -> V_10 = ( ( V_3 + V_4 - 1 ) & V_6 ) >> V_9 ;
V_2 -> V_11 = V_2 -> V_10 - V_2 -> V_3 + 1 ;
if ( V_2 -> V_11 == 1 ) V_2 -> V_8 -= V_2 -> V_7 ;
}
int F_2 ( struct V_12 * V_13 , struct V_1 * V_2 , int V_14 )
{
int V_15 , V_7 ;
unsigned long V_16 ;
if ( V_14 < 0 )
return V_14 ;
V_7 = V_2 -> V_7 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_11 ; V_15 ++ ) {
unsigned int V_17 = ( V_15 == V_2 -> V_11 - 1 ) ?
V_2 -> V_8 : V_18 - V_7 ;
if ( F_3 ( V_13 -> V_19 [ V_14 ] ) ) {
void * V_20 ;
if ( V_13 -> V_21 [ V_14 ] == NULL )
V_13 -> V_21 [ V_14 ] = F_4 ( V_22 ) ;
if ( V_13 -> V_21 [ V_14 ] == NULL )
return - 1 ;
F_5 ( V_16 ) ;
V_20 = F_6 ( V_13 -> V_19 [ V_14 ] ) + V_7 ;
memcpy ( F_7 ( V_13 -> V_21 [ V_14 ] ) + V_7 , V_20 , V_17 ) ;
F_8 ( V_20 ) ;
F_9 ( V_16 ) ;
F_10 ( & V_13 -> V_23 [ V_14 ] , V_13 -> V_21 [ V_14 ] , V_17 , V_7 ) ;
}
else {
F_10 ( & V_13 -> V_23 [ V_14 ] , V_13 -> V_19 [ V_14 ] , V_17 , V_7 ) ;
}
V_7 = 0 ;
V_14 ++ ;
}
return V_14 ;
}
void F_11 ( struct V_12 * V_13 , T_1 V_24 , T_1 V_25 , T_1 V_26 ) {
int V_15 ;
struct V_27 * V_28 ;
for ( V_15 = 0 , V_28 = V_13 -> V_23 ; V_15 < V_13 -> V_29 ; V_15 ++ , V_28 = F_12 ( V_28 ) ) {
V_13 -> V_30 [ V_15 ] . V_4 = F_13 ( F_14 ( V_28 ) ) ;
V_13 -> V_30 [ V_15 ] . V_20 = F_13 ( F_15 ( V_28 ) ) ;
V_13 -> V_30 [ V_15 ] . V_31 = F_13 ( V_24 ) ;
V_24 += F_14 ( V_28 ) ;
V_26 -= F_14 ( V_28 ) ;
if ( V_26 == 0 )
V_24 = V_25 ;
}
}
void F_16 ( struct V_32 * V_33 )
{
if ( V_33 -> V_34 . V_35 == 0 ) {
V_33 -> V_34 . V_35 = F_17 ( V_33 -> V_36 , V_33 -> V_34 . V_30 ,
sizeof( V_33 -> V_34 . V_30 ) , V_37 ) ;
F_18 ( V_33 ) ;
}
}
int F_19 ( struct V_32 * V_33 , unsigned long V_38 ,
void T_2 * V_39 , int V_40 )
{
struct V_1 V_41 ;
struct V_12 * V_13 = & V_33 -> V_34 ;
int V_15 , V_42 ;
F_20 ( L_1 , ( unsigned int ) V_38 ) ;
if ( V_13 -> V_29 || V_13 -> V_11 ) {
F_21 ( L_2 ,
V_13 -> V_29 , V_13 -> V_11 ) ;
return - V_43 ;
}
F_1 ( & V_41 , ( unsigned long ) V_39 , V_40 ) ;
if ( V_41 . V_11 <= 0 ) {
F_21 ( L_3 ,
V_41 . V_11 , V_40 , V_41 . V_7 ) ;
return - V_44 ;
}
V_42 = F_22 ( V_41 . V_5 , V_41 . V_11 ,
V_13 -> V_19 , V_45 ) ;
if ( V_41 . V_11 != V_42 ) {
F_21 ( L_4 ,
V_42 , V_41 . V_11 ) ;
if ( V_42 >= 0 ) {
for ( V_15 = 0 ; V_15 < V_42 ; V_15 ++ )
F_23 ( V_13 -> V_19 [ V_15 ] ) ;
return - V_44 ;
}
return V_42 ;
}
V_13 -> V_11 = V_41 . V_11 ;
if ( F_2 ( V_13 , & V_41 , 0 ) < 0 ) {
for ( V_15 = 0 ; V_15 < V_13 -> V_11 ; V_15 ++ ) {
F_23 ( V_13 -> V_19 [ V_15 ] ) ;
}
V_13 -> V_11 = 0 ;
return - V_46 ;
}
V_13 -> V_29 = F_24 ( V_33 -> V_36 , V_13 -> V_23 , V_13 -> V_11 , V_37 ) ;
F_11 ( V_13 , V_38 , 0 , - 1 ) ;
V_13 -> V_30 [ V_13 -> V_29 - 1 ] . V_4 |= F_13 ( 0x80000000 ) ;
F_25 ( V_33 ) ;
return V_13 -> V_11 ;
}
void F_26 ( struct V_32 * V_33 )
{
struct V_12 * V_13 = & V_33 -> V_34 ;
int V_15 ;
F_27 ( L_5 ) ;
if ( V_13 -> V_11 == 0 )
return;
if ( V_13 -> V_29 ) {
F_28 ( V_33 -> V_36 , V_13 -> V_23 , V_13 -> V_11 , V_37 ) ;
V_13 -> V_29 = 0 ;
}
F_18 ( V_33 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_11 ; V_15 ++ ) {
F_23 ( V_13 -> V_19 [ V_15 ] ) ;
}
V_13 -> V_11 = 0 ;
}
void F_29 ( struct V_32 * V_33 )
{
int V_15 ;
if ( V_33 -> V_34 . V_35 ) {
F_30 ( V_33 -> V_36 , V_33 -> V_34 . V_35 ,
sizeof( V_33 -> V_34 . V_30 ) , V_37 ) ;
}
if ( V_33 -> V_34 . V_29 ) {
F_28 ( V_33 -> V_36 , V_33 -> V_34 . V_23 , V_33 -> V_34 . V_11 , V_37 ) ;
}
for ( V_15 = 0 ; V_15 < V_47 ; V_15 ++ ) {
if ( V_33 -> V_34 . V_21 [ V_15 ] )
F_31 ( V_33 -> V_34 . V_21 [ V_15 ] ) ;
}
}
void F_32 ( struct V_32 * V_33 )
{
F_20 ( L_6 ) ;
F_33 ( V_33 -> V_34 . V_35 , V_48 ) ;
F_34 ( F_35 ( V_49 ) | 0x01 , V_49 ) ;
F_36 ( V_50 , & V_33 -> V_51 ) ;
F_36 ( V_52 , & V_33 -> V_51 ) ;
F_37 ( V_53 , & V_33 -> V_51 ) ;
}
void F_38 ( struct V_32 * V_33 )
{
unsigned long V_16 ;
F_39 ( & V_33 -> V_54 , V_16 ) ;
if ( ! F_40 ( V_50 , & V_33 -> V_51 ) )
F_32 ( V_33 ) ;
else
F_36 ( V_53 , & V_33 -> V_51 ) ;
F_41 ( & V_33 -> V_54 , V_16 ) ;
}
