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
static struct V_16 * F_10 ( struct V_17 * V_18 ,
void * V_19 )
{
struct V_11 * V_6 = V_19 ;
if ( F_6 ( V_18 -> V_20 != 1 ||
V_18 -> args [ 0 ] >= F_11 ( V_6 -> V_4 ) ) )
return NULL ;
return V_6 -> V_4 [ V_18 -> args [ 0 ] ] . V_16 ;
}
static void T_3 F_12 ( struct V_21 * V_22 )
{
struct V_11 * V_6 = F_13 ( sizeof( * V_6 ) , V_23 ) ;
const char * V_24 [ 2 ] ;
int V_25 = F_11 ( V_24 ) ;
char V_26 [ 12 ] ;
struct V_27 V_28 ;
static int V_29 ;
int V_30 ;
bool V_31 ;
if ( ! V_6 )
return;
if ( F_14 ( V_22 , V_24 , V_25 ) != V_25 ) {
F_15 ( L_1 ) ;
F_16 ( V_6 ) ;
return;
}
V_6 -> V_22 = V_22 ;
V_6 -> V_7 = F_17 ( V_22 , 0 ) ;
F_18 ( & V_6 -> V_15 ) ;
V_28 . V_26 = V_26 ;
V_28 . V_32 = & V_33 ;
V_28 . V_13 = V_34 ;
V_28 . V_24 = V_24 ;
V_28 . V_35 = V_25 ;
V_31 = ! F_19 ( V_22 , L_2 , NULL ) ;
for ( V_30 = 0 ; V_30 < F_11 ( V_6 -> V_4 ) ; V_30 ++ ) {
snprintf ( V_26 , sizeof( V_26 ) , L_3 , V_29 , V_30 ) ;
V_6 -> V_4 [ V_30 ] . V_6 = V_6 ;
V_6 -> V_4 [ V_30 ] . V_9 = V_30 ;
V_6 -> V_4 [ V_30 ] . V_2 . V_28 = & V_28 ;
if ( V_31 )
V_28 . V_32 -> V_36 ( & V_6 -> V_4 [ V_30 ] . V_2 , 1 ) ;
V_6 -> V_4 [ V_30 ] . V_16 = F_20 ( NULL ,
& V_6 -> V_4 [ V_30 ] . V_2 ) ;
F_6 ( F_21 ( V_6 -> V_4 [ V_30 ] . V_16 ) ) ;
}
F_22 ( V_22 , F_10 , V_6 ) ;
V_29 ++ ;
}
