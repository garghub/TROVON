static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 [ 4 ] ;
T_1 V_6 , V_7 ;
bool V_8 = V_4 -> V_9 & ( V_10 & V_11 ) ;
bool V_12 = V_4 -> V_9 & ( V_13 & V_11 ) ;
T_2 * V_14 = V_4 -> V_15 ;
int V_16 ;
if ( V_12 )
V_7 = 4 ;
else
V_7 = V_4 -> V_17 + 4 ;
if ( V_7 > V_18 )
return - V_19 ;
V_5 [ 0 ] = ( V_4 -> V_20 >> 16 ) & 0xf ;
if ( V_12 )
V_5 [ 0 ] |= F_2 ( 4 ) ;
V_5 [ 1 ] = ( V_4 -> V_20 >> 8 ) & 0xff ;
V_5 [ 2 ] = V_4 -> V_20 & 0xff ;
V_5 [ 3 ] = ( V_4 -> V_17 - 1 ) & 0xff ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
V_6 = ( V_16 < 4 ) ? V_5 [ V_16 ] : V_14 [ V_16 - 4 ] ;
V_6 = F_3 ( V_6 ) ;
if ( V_16 == 0 )
V_6 |= V_21 ;
F_4 ( V_2 -> V_22 + V_23 , V_6 ) ;
}
V_6 = 0 ;
if ( ! V_8 )
V_6 |= V_24 ;
V_6 |= V_25 ;
F_4 ( V_2 -> V_22 + V_26 , V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 * V_27 ;
int V_16 ;
T_1 V_7 = V_4 -> V_17 ;
F_4 ( V_2 -> V_22 + V_23 ,
V_21 | V_28 ) ;
V_27 = V_4 -> V_15 ;
V_5 = F_6 ( V_2 -> V_22 + V_23 ) ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
V_5 = F_6 ( V_2 -> V_22 + V_23 ) ;
V_27 [ V_16 ] = ( T_2 ) ( ( V_5 >> 8 ) & 0xff ) ;
}
return 0 ;
}
static T_3 F_7 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_8 ( V_30 ) ;
T_3 V_31 ;
unsigned long V_32 ;
bool V_8 = V_4 -> V_9 & ( V_10 & V_11 ) ;
bool V_12 = V_4 -> V_9 & ( V_13 & V_11 ) ;
if ( ( V_4 -> V_17 == 0 ) || ( V_4 -> V_15 == NULL ) ) {
V_4 -> V_33 = V_8 ?
V_34 : V_35 ;
return V_4 -> V_17 ;
}
if ( ( V_8 && ( V_4 -> V_17 > V_36 ) ) ||
( V_4 -> V_17 > V_37 ) ) {
F_9 ( L_1 ,
V_38 , V_4 -> V_17 , V_4 -> V_9 ) ;
return - V_19 ;
}
F_10 ( & V_2 -> V_39 ) ;
V_2 -> V_40 = false ;
F_11 ( & V_2 -> V_41 ) ;
V_31 = F_1 ( V_2 , V_4 ) ;
if ( V_31 < 0 )
goto V_42;
F_12 ( L_2 ) ;
V_32 = F_13 ( & V_2 -> V_41 ,
F_14 ( 300 ) ) ;
if ( ! V_32 ) {
F_4 ( V_2 -> V_22 + V_26 , 0 ) ;
F_15 ( V_2 , 1 ) ;
F_9 ( L_3 , V_38 ) ;
V_31 = - V_43 ;
goto V_42;
}
F_12 ( L_4 ) ;
if ( ! V_2 -> V_40 ) {
if ( V_12 ) {
V_31 = F_5 ( V_2 , V_4 ) ;
if ( V_31 < 0 )
goto V_42;
}
V_4 -> V_33 = V_8 ?
V_34 : V_35 ;
} else {
V_4 -> V_33 = V_8 ?
V_44 : V_45 ;
F_16 ( 100 ) ;
}
V_31 = V_4 -> V_17 ;
V_42:
F_17 ( & V_2 -> V_39 ) ;
return V_31 ;
}
void * F_18 ( struct V_46 * V_47 , void T_4 * V_48 ,
struct V_29 * * V_30 )
{
struct V_1 * V_2 = NULL ;
int V_31 ;
F_12 ( L_5 ) ;
V_2 = F_19 ( V_47 , sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_22 = V_48 ;
F_20 ( & V_2 -> V_39 ) ;
F_21 ( & V_2 -> V_41 ) ;
V_2 -> V_30 . V_50 = L_6 ;
V_2 -> V_30 . V_47 = V_47 ;
V_2 -> V_30 . V_51 = F_7 ;
V_31 = F_22 ( & V_2 -> V_30 ) ;
if ( V_31 ) {
F_9 ( L_7 , V_38 , V_31 ) ;
F_23 ( & V_2 -> V_39 ) ;
}
if ( V_30 && V_2 )
* V_30 = & V_2 -> V_30 ;
return V_2 ;
}
void F_24 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
if ( V_2 ) {
F_25 ( & V_2 -> V_30 ) ;
F_23 ( & V_2 -> V_39 ) ;
}
}
T_5 F_26 ( struct V_1 * V_2 , T_1 V_52 )
{
if ( V_52 & V_53 ) {
F_12 ( L_8 , V_52 ) ;
F_4 ( V_2 -> V_22 + V_26 , 0 ) ;
if ( V_52 & V_54 )
V_2 -> V_40 = true ;
else
V_2 -> V_40 = false ;
F_27 ( & V_2 -> V_41 ) ;
}
return V_55 ;
}
void F_15 ( struct V_1 * V_2 , int V_56 )
{
T_1 V_5 ;
F_12 ( L_9 , V_56 ) ;
V_5 = F_6 ( V_2 -> V_22 + V_57 ) ;
if ( V_56 ) {
V_5 |= V_58 ;
F_4 ( V_2 -> V_22 + V_57 , V_5 ) ;
F_28 () ;
F_29 ( 500 , 1000 ) ;
V_5 &= ~ V_58 ;
V_5 |= V_59 ;
F_4 ( V_2 -> V_22 + V_57 , V_5 ) ;
} else {
V_5 &= ~ V_59 ;
F_4 ( V_2 -> V_22 + V_57 , V_5 ) ;
}
}
