static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_2 -> V_5 )
return ! ( V_3 & V_6 ) ;
else
return ! ! ( V_3 & V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 |= V_9 ;
F_5 ( V_3 , V_2 -> V_4 ) ;
return 0 ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 &= ~ V_9 ;
F_5 ( V_3 , V_2 -> V_4 ) ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
return V_3 & V_9 ;
}
static unsigned long F_8 ( struct V_7 * V_8 ,
unsigned long V_10 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_11 , V_12 , V_3 ;
long long V_13 ;
if ( F_1 ( V_2 ) )
return V_10 ;
V_13 = V_10 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_12 = ( V_3 >> 8 ) & 0xff ;
if ( V_12 )
F_9 ( V_13 , V_12 ) ;
V_11 = V_3 >> 16 ;
if ( V_11 )
V_13 *= V_11 ;
return V_13 ;
}
static T_2 F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( F_1 ( V_2 ) )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_12 ( V_8 ) ;
T_1 V_3 = F_2 ( V_15 -> V_2 -> V_4 + V_16 ) ;
V_3 &= ~ ( 1 << V_15 -> V_17 ) ;
F_5 ( V_3 , V_15 -> V_2 -> V_4 + V_16 ) ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_12 ( V_8 ) ;
T_1 V_3 = F_2 ( V_15 -> V_2 -> V_4 + V_16 ) ;
V_3 |= 1 << V_15 -> V_17 ;
F_5 ( V_3 , V_15 -> V_2 -> V_4 + V_16 ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_12 ( V_8 ) ;
T_1 V_3 = F_2 ( V_15 -> V_2 -> V_4 + V_16 ) ;
return ! ( V_3 & ( 1 << V_15 -> V_17 ) ) ;
}
static unsigned long F_15 ( struct V_7 * V_8 ,
unsigned long V_10 )
{
struct V_14 * V_15 = F_12 ( V_8 ) ;
T_1 V_18 ;
long long V_13 ;
if ( ! V_15 -> div )
return 32768 ;
if ( F_1 ( V_15 -> V_2 ) )
return V_10 ;
V_13 = V_10 ;
if ( V_15 -> V_19 ) {
T_1 V_3 , V_20 , V_21 , V_22 ;
V_3 = F_2 ( V_15 -> V_19 ) ;
V_20 = ( V_3 >> 24 ) & 0xf ;
V_21 = V_3 & 0xffffff ;
V_22 = ( V_20 * 10000000 ) + V_21 ;
V_13 *= 10000000 ;
F_9 ( V_13 , V_22 ) ;
V_13 *= 8 ;
}
V_18 = F_2 ( V_15 -> div ) & 0xff ;
F_9 ( V_13 , V_18 ) ;
return V_13 ;
}
static struct V_23 * T_3 F_16 ( struct V_1 * V_2 ,
void T_4 * V_19 ,
void T_4 * div ,
int V_17 ,
const char * V_24 ,
const char * V_25 ,
struct V_23 * V_26 )
{
struct V_27 * V_28 ;
struct V_14 * V_15 ;
V_28 = F_17 ( sizeof( * V_28 ) , V_29 ) ;
if ( ! V_28 )
return F_18 ( - V_30 ) ;
V_28 -> V_31 = & V_32 ;
V_28 -> V_24 = V_24 ;
V_28 -> V_33 = & V_25 ;
V_28 -> V_34 = 1 ;
V_15 = F_17 ( sizeof( * V_15 ) , V_29 ) ;
if ( ! V_15 )
goto free;
V_15 -> V_2 = V_2 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_19 = V_19 ;
V_15 -> div = div ;
V_15 -> V_24 = V_24 ;
V_15 -> V_8 . V_28 = V_28 ;
V_15 -> V_35 = V_26 ;
return F_19 ( NULL , & V_15 -> V_8 ) ;
free:
F_20 ( V_15 ) ;
F_20 ( V_28 ) ;
return F_18 ( - V_30 ) ;
}
static void T_3 F_21 ( struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = NULL ;
const char * V_38 [ 2 ] ;
struct V_23 * V_26 ;
int V_39 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return;
V_2 -> V_40 . V_41 = F_17 ( sizeof( struct V_23 * ) *
V_42 + 1 ,
V_29 ) ;
if ( ! V_2 -> V_40 . V_41 )
goto free;
V_28 = F_17 ( sizeof( * V_28 ) , V_29 ) ;
if ( ! V_28 )
goto free;
V_28 -> V_31 = & V_43 ;
V_28 -> V_24 = V_37 -> V_24 ;
V_28 -> V_34 = F_22 ( V_37 ) ;
if ( V_28 -> V_34 != 2 ) {
F_23 ( L_1 , V_37 -> V_24 ) ;
goto free;
}
V_38 [ 0 ] = F_24 ( V_37 , 0 ) ;
V_38 [ 1 ] = F_24 ( V_37 , 1 ) ;
V_28 -> V_33 = V_38 ;
V_2 -> V_44 = F_25 ( V_37 , 0 ) ;
if ( F_26 ( V_2 -> V_44 ) ) {
F_23 ( L_2 , V_37 -> V_24 ) ;
goto free;
}
V_2 -> V_45 = F_25 ( V_37 , 1 ) ;
if ( F_26 ( V_2 -> V_45 ) ) {
F_23 ( L_3 , V_37 -> V_24 ) ;
goto free;
}
V_2 -> V_4 = F_27 ( V_37 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_23 ( L_4 , V_37 -> V_24 ) ;
goto free;
}
if ( F_28 ( V_2 -> V_4 ) )
V_2 -> V_5 = true ;
V_2 -> V_24 = V_37 -> V_24 ;
V_2 -> V_8 . V_28 = V_28 ;
V_26 = F_19 ( NULL , & V_2 -> V_8 ) ;
if ( F_26 ( V_26 ) )
goto V_46;
V_2 -> V_40 . V_41 [ 0 ] = V_26 ;
V_2 -> V_40 . V_47 ++ ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ ) {
const char * V_48 ;
void T_4 * V_19 , * div ;
struct V_23 * V_49 ;
int V_50 ;
T_1 V_3 ;
if ( F_29 ( V_37 , L_5 ,
V_39 , & V_48 ) )
continue;
if ( F_30 ( V_37 , L_6 , V_39 ,
& V_50 ) )
V_50 = V_39 ;
V_19 = V_2 -> V_4 + ( V_50 * 8 ) ;
div = V_19 + 4 ;
if ( F_31 ( V_19 ) ) {
V_19 = 0 ;
div = 0 ;
} else {
V_3 = F_2 ( V_19 ) ;
if ( ! V_3 )
V_19 = 0 ;
}
V_49 = F_16 ( V_2 , V_19 , div , V_50 ,
V_48 , V_37 -> V_24 ,
V_26 ) ;
if ( F_26 ( V_49 ) )
continue;
V_2 -> V_40 . V_41 [ V_50 ] = V_49 ;
V_2 -> V_40 . V_47 ++ ;
F_32 ( V_49 , V_48 , NULL ) ;
}
F_33 ( V_37 , V_51 , & V_2 -> V_40 ) ;
F_20 ( V_28 ) ;
return;
V_46:
F_34 ( V_2 -> V_4 ) ;
free:
if ( V_2 -> V_45 )
F_35 ( V_2 -> V_45 ) ;
if ( V_2 -> V_44 )
F_35 ( V_2 -> V_44 ) ;
F_20 ( V_2 -> V_40 . V_41 ) ;
F_20 ( V_2 ) ;
F_20 ( V_28 ) ;
}
