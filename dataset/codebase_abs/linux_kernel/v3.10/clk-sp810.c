static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_5 = F_3 ( V_4 -> V_6 -> V_7 + V_8 ) ;
return ! ! ( V_5 & ( 1 << F_4 ( V_4 -> V_9 ) ) ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_6 = V_4 -> V_6 ;
T_2 V_5 , V_12 = F_4 ( V_4 -> V_9 ) ;
unsigned long V_13 = 0 ;
if ( F_6 ( V_10 > 1 ) )
return - V_14 ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
V_5 = F_3 ( V_6 -> V_7 + V_8 ) ;
V_5 &= ~ ( 1 << V_12 ) ;
V_5 |= V_10 << V_12 ;
F_8 ( V_5 , V_6 -> V_7 + V_8 ) ;
F_9 ( & V_6 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_6 = V_4 -> V_6 ;
struct V_16 * V_17 = F_11 ( V_2 -> V_16 ) ;
struct V_16 * V_18 ;
if ( ! V_6 -> V_19 )
V_6 -> V_19 = F_12 ( V_6 -> V_20 , V_6 -> V_21 ) ;
if ( ! V_6 -> V_22 )
V_6 -> V_22 = F_12 ( V_6 -> V_20 , V_6 -> V_23 ) ;
if ( F_6 ( F_13 ( V_6 -> V_19 ) || F_13 ( V_6 -> V_22 ) ) )
return - V_24 ;
if ( F_14 ( V_6 -> V_19 ) > F_14 ( V_6 -> V_22 ) )
V_18 = V_6 -> V_19 ;
else
V_18 = V_6 -> V_22 ;
if ( V_17 != V_18 ) {
F_15 ( V_18 ) ;
F_16 ( V_2 -> V_16 , V_18 ) ;
F_17 ( V_17 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_6 = V_4 -> V_6 ;
F_19 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_19 ) ;
}
struct V_16 * F_20 ( struct V_25 * V_26 ,
void * V_27 )
{
struct V_11 * V_6 = V_27 ;
if ( F_6 ( V_26 -> V_28 != 1 || V_26 -> args [ 0 ] >
F_21 ( V_6 -> V_4 ) ) )
return NULL ;
return V_6 -> V_4 [ V_26 -> args [ 0 ] ] . V_16 ;
}
void T_3 F_22 ( struct V_29 * V_20 )
{
struct V_11 * V_6 = F_23 ( sizeof( * V_6 ) , V_30 ) ;
const char * V_31 [ 2 ] ;
char V_32 [ 12 ] ;
struct V_33 V_34 ;
int V_35 ;
if ( ! V_6 ) {
F_24 ( L_1 ) ;
return;
}
V_6 -> V_21 = F_25 ( V_20 , L_2 ,
L_3 ) ;
V_31 [ 0 ] = F_26 ( V_20 , V_6 -> V_21 ) ;
V_6 -> V_23 = F_25 ( V_20 , L_2 ,
L_4 ) ;
V_31 [ 1 ] = F_26 ( V_20 , V_6 -> V_23 ) ;
if ( V_31 [ 0 ] <= 0 || V_31 [ 1 ] <= 0 ) {
F_27 ( L_5 ) ;
return;
}
V_6 -> V_20 = V_20 ;
V_6 -> V_7 = F_28 ( V_20 , 0 ) ;
F_29 ( & V_6 -> V_15 ) ;
V_34 . V_32 = V_32 ;
V_34 . V_36 = & V_37 ;
V_34 . V_13 = V_38 ;
V_34 . V_31 = V_31 ;
V_34 . V_39 = F_21 ( V_31 ) ;
for ( V_35 = 0 ; V_35 < F_21 ( V_6 -> V_4 ) ; V_35 ++ ) {
snprintf ( V_32 , F_21 ( V_32 ) , L_6 , V_35 ) ;
V_6 -> V_4 [ V_35 ] . V_6 = V_6 ;
V_6 -> V_4 [ V_35 ] . V_9 = V_35 ;
V_6 -> V_4 [ V_35 ] . V_2 . V_34 = & V_34 ;
V_6 -> V_4 [ V_35 ] . V_16 = F_30 ( NULL ,
& V_6 -> V_4 [ V_35 ] . V_2 ) ;
F_6 ( F_13 ( V_6 -> V_4 [ V_35 ] . V_16 ) ) ;
}
F_31 ( V_20 , F_20 , V_6 ) ;
}
