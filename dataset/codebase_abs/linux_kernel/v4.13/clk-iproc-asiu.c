static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
if ( V_4 -> V_8 . V_9 == V_10 )
return 0 ;
V_7 = F_3 ( V_6 -> V_11 + V_4 -> V_8 . V_9 ) ;
V_7 |= ( 1 << V_4 -> V_8 . V_12 ) ;
F_4 ( V_7 , V_6 -> V_11 + V_4 -> V_8 . V_9 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
if ( V_4 -> V_8 . V_9 == V_10 )
return;
V_7 = F_3 ( V_6 -> V_11 + V_4 -> V_8 . V_9 ) ;
V_7 &= ~ ( 1 << V_4 -> V_8 . V_12 ) ;
F_4 ( V_7 , V_6 -> V_11 + V_4 -> V_8 . V_9 ) ;
}
static unsigned long F_6 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
unsigned int V_14 , V_15 ;
if ( V_13 == 0 ) {
V_4 -> V_16 = 0 ;
return 0 ;
}
V_7 = F_3 ( V_6 -> V_17 + V_4 -> div . V_9 ) ;
if ( ( V_7 & ( 1 << V_4 -> div . V_12 ) ) == 0 ) {
V_4 -> V_16 = V_13 ;
return V_13 ;
}
V_14 = ( V_7 >> V_4 -> div . V_18 ) & F_7 ( V_4 -> div . V_19 ) ;
V_14 ++ ;
V_15 = ( V_7 >> V_4 -> div . V_20 ) & F_7 ( V_4 -> div . V_21 ) ;
V_15 ++ ;
V_4 -> V_16 = V_13 / ( V_14 + V_15 ) ;
F_8 ( L_1 ,
V_22 , V_4 -> V_16 , V_13 , V_14 , V_15 ) ;
return V_4 -> V_16 ;
}
static long F_9 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long * V_13 )
{
unsigned int div ;
if ( V_16 == 0 || * V_13 == 0 )
return - V_23 ;
if ( V_16 == * V_13 )
return * V_13 ;
div = F_10 ( * V_13 , V_16 ) ;
if ( div < 2 )
return * V_13 ;
return * V_13 / div ;
}
static int F_11 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int div , V_14 , V_15 ;
T_1 V_7 ;
if ( V_16 == 0 || V_13 == 0 )
return - V_23 ;
if ( V_16 == V_13 ) {
V_7 = F_3 ( V_6 -> V_17 + V_4 -> div . V_9 ) ;
V_7 &= ~ ( 1 << V_4 -> div . V_12 ) ;
F_4 ( V_7 , V_6 -> V_17 + V_4 -> div . V_9 ) ;
return 0 ;
}
div = F_10 ( V_13 , V_16 ) ;
if ( div < 2 )
return - V_23 ;
V_14 = V_15 = div >> 1 ;
V_14 -- ;
V_15 -- ;
V_7 = F_3 ( V_6 -> V_17 + V_4 -> div . V_9 ) ;
V_7 |= 1 << V_4 -> div . V_12 ;
if ( V_14 ) {
V_7 &= ~ ( F_7 ( V_4 -> div . V_19 )
<< V_4 -> div . V_18 ) ;
V_7 |= V_14 << V_4 -> div . V_18 ;
} else {
V_7 &= ~ ( F_7 ( V_4 -> div . V_19 )
<< V_4 -> div . V_18 ) ;
}
if ( V_15 ) {
V_7 &= ~ ( F_7 ( V_4 -> div . V_21 ) << V_4 -> div . V_20 ) ;
V_7 |= V_15 << V_4 -> div . V_20 ;
} else {
V_7 &= ~ ( F_7 ( V_4 -> div . V_21 ) << V_4 -> div . V_20 ) ;
}
F_4 ( V_7 , V_6 -> V_17 + V_4 -> div . V_9 ) ;
return 0 ;
}
void T_2 F_12 ( struct V_24 * V_25 ,
const struct V_26 * div ,
const struct V_27 * V_8 ,
unsigned int V_28 )
{
int V_29 , V_30 ;
struct V_5 * V_6 ;
if ( F_13 ( ! V_8 || ! div ) )
return;
V_6 = F_14 ( sizeof( * V_6 ) , V_31 ) ;
if ( F_13 ( ! V_6 ) )
return;
V_6 -> V_32 = F_14 ( sizeof( * V_6 -> V_32 -> V_33 ) * V_28 +
sizeof( * V_6 -> V_32 ) , V_31 ) ;
if ( F_13 ( ! V_6 -> V_32 ) )
goto V_34;
V_6 -> V_32 -> V_35 = V_28 ;
V_6 -> V_36 = F_15 ( V_28 , sizeof( * V_6 -> V_36 ) , V_31 ) ;
if ( F_13 ( ! V_6 -> V_36 ) )
goto V_37;
V_6 -> V_17 = F_16 ( V_25 , 0 ) ;
if ( F_13 ( ! V_6 -> V_17 ) )
goto V_38;
V_6 -> V_11 = F_16 ( V_25 , 1 ) ;
if ( F_13 ( ! V_6 -> V_11 ) )
goto V_39;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
struct V_40 V_41 ;
const char * V_42 ;
struct V_3 * V_43 ;
const char * V_44 ;
V_30 = F_17 ( V_25 , L_2 ,
V_29 , & V_44 ) ;
if ( F_13 ( V_30 ) )
goto V_45;
V_43 = & V_6 -> V_36 [ V_29 ] ;
V_43 -> V_46 = V_44 ;
V_43 -> V_6 = V_6 ;
V_43 -> div = div [ V_29 ] ;
V_43 -> V_8 = V_8 [ V_29 ] ;
V_41 . V_46 = V_44 ;
V_41 . V_47 = & V_48 ;
V_41 . V_49 = 0 ;
V_42 = F_18 ( V_25 , 0 ) ;
V_41 . V_50 = ( V_42 ? & V_42 : NULL ) ;
V_41 . V_51 = ( V_42 ? 1 : 0 ) ;
V_43 -> V_2 . V_41 = & V_41 ;
V_30 = F_19 ( NULL , & V_43 -> V_2 ) ;
if ( F_13 ( V_30 ) )
goto V_45;
V_6 -> V_32 -> V_33 [ V_29 ] = & V_43 -> V_2 ;
}
V_30 = F_20 ( V_25 , V_52 ,
V_6 -> V_32 ) ;
if ( F_13 ( V_30 ) )
goto V_45;
return;
V_45:
while ( -- V_29 >= 0 )
F_21 ( V_6 -> V_32 -> V_33 [ V_29 ] ) ;
F_22 ( V_6 -> V_11 ) ;
V_39:
F_22 ( V_6 -> V_17 ) ;
V_38:
F_23 ( V_6 -> V_36 ) ;
V_37:
F_23 ( V_6 -> V_32 ) ;
V_34:
F_23 ( V_6 ) ;
}
