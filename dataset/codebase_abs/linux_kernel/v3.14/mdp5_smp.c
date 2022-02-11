int F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 , int V_4 )
{
struct V_5 * V_6 = & V_1 -> V_7 [ V_3 ] ;
int V_8 , V_9 , V_10 , V_11 , V_12 = V_1 -> V_13 ;
unsigned long V_14 ;
F_2 ( & V_15 , V_14 ) ;
V_10 = V_12 - F_3 ( V_1 -> V_16 , V_12 ) ;
if ( V_4 > V_10 ) {
V_9 = - V_17 ;
goto V_18;
}
V_11 = F_3 ( V_6 -> V_19 , V_12 ) ;
if ( V_4 > V_11 ) {
for ( V_8 = V_11 ; V_8 < V_4 ; V_8 ++ ) {
int V_20 = F_4 ( V_1 -> V_16 , V_12 ) ;
F_5 ( V_20 , V_6 -> V_19 ) ;
F_5 ( V_20 , V_1 -> V_16 ) ;
}
} else {
for ( V_8 = V_11 ; V_8 > V_4 ; V_8 -- ) {
int V_20 = F_6 ( V_6 -> V_19 , V_12 ) ;
F_7 ( V_20 , V_6 -> V_19 ) ;
}
}
V_18:
F_8 ( & V_15 , V_14 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_1 ,
enum V_2 V_3 , T_1 * V_21 )
{
int V_12 = V_1 -> V_13 ;
T_2 V_20 , V_22 ;
F_10 (blk, *assigned, cnt) {
int V_23 = V_20 / 3 ;
int V_24 = V_20 % 3 ;
V_22 = F_11 ( V_1 , F_12 ( V_23 ) ) ;
switch ( V_24 ) {
case 0 :
V_22 &= ~ V_25 ;
V_22 |= F_13 ( V_3 ) ;
break;
case 1 :
V_22 &= ~ V_26 ;
V_22 |= F_14 ( V_3 ) ;
break;
case 2 :
V_22 &= ~ V_27 ;
V_22 |= F_15 ( V_3 ) ;
break;
}
F_16 ( V_1 , F_12 ( V_23 ) , V_22 ) ;
F_16 ( V_1 , F_17 ( V_23 ) , V_22 ) ;
}
}
void F_18 ( struct V_1 * V_1 , enum V_2 V_3 )
{
struct V_5 * V_6 = & V_1 -> V_7 [ V_3 ] ;
int V_12 = V_1 -> V_13 ;
T_1 V_21 ;
F_19 ( V_21 , V_6 -> V_28 , V_6 -> V_19 , V_12 ) ;
F_9 ( V_1 , V_3 , & V_21 ) ;
}
void F_20 ( struct V_1 * V_1 , enum V_2 V_3 )
{
struct V_5 * V_6 = & V_1 -> V_7 [ V_3 ] ;
int V_12 = V_1 -> V_13 ;
T_1 V_29 ;
if ( F_21 ( V_29 , V_6 -> V_28 , V_6 -> V_19 , V_12 ) ) {
unsigned long V_14 ;
F_2 ( & V_15 , V_14 ) ;
F_21 ( V_1 -> V_16 , V_1 -> V_16 ,
V_29 , V_12 ) ;
F_8 ( & V_15 , V_14 ) ;
F_9 ( V_1 , V_30 , & V_29 ) ;
}
F_22 ( V_6 -> V_28 , V_6 -> V_19 , V_12 ) ;
}
