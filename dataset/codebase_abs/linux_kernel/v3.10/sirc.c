static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = 1 << ( V_2 -> V_4 - V_5 ) ;
F_2 ( V_3 , V_6 . V_7 ) ;
V_8 &= ~ V_3 ;
return;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = 1 << ( V_2 -> V_4 - V_5 ) ;
F_2 ( V_3 , V_6 . V_9 ) ;
V_8 |= V_3 ;
return;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = 1 << ( V_2 -> V_4 - V_5 ) ;
F_2 ( V_3 , V_6 . V_10 ) ;
return;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_11 )
{
unsigned int V_3 ;
V_3 = 1 << ( V_2 -> V_4 - V_5 ) ;
if ( V_11 )
V_12 |= V_3 ;
else
V_12 &= ~ V_3 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_13 )
{
unsigned int V_3 ;
unsigned int V_14 ;
V_3 = 1 << ( V_2 -> V_4 - V_5 ) ;
V_14 = F_7 ( V_6 . V_15 ) ;
if ( V_13 & ( V_16 | V_17 ) )
V_14 |= V_3 ;
else
V_14 &= ~ V_3 ;
F_2 ( V_14 , V_6 . V_15 ) ;
V_14 = F_7 ( V_6 . V_18 ) ;
if ( V_13 & ( V_19 | V_17 ) ) {
V_14 |= V_3 ;
F_8 ( V_2 -> V_4 , V_20 ) ;
} else {
V_14 &= ~ V_3 ;
F_8 ( V_2 -> V_4 , V_21 ) ;
}
F_2 ( V_14 , V_6 . V_18 ) ;
return 0 ;
}
static void F_9 ( unsigned int V_4 , struct V_22 * V_23 )
{
unsigned int V_24 = 0 ;
unsigned int V_25 ;
unsigned int V_26 ;
while ( ( V_24 < F_10 ( V_27 ) ) &&
( V_27 [ V_24 ] . V_28 != V_4 ) )
V_24 ++ ;
V_26 = F_7 ( V_27 [ V_24 ] . V_29 ) ;
V_26 &= V_30 ;
if ( V_26 == 0 )
return;
for ( V_25 = 0 ;
( V_25 < V_31 ) && ( ( V_26 & ( 1U << V_25 ) ) == 0 ) ;
V_25 ++ )
;
F_11 ( V_25 + V_5 ) ;
V_23 -> V_1 . V_32 -> V_33 ( & V_23 -> V_1 ) ;
}
void T_1 F_12 ( void )
{
int V_34 ;
V_8 = 0 ;
V_12 = 0 ;
for ( V_34 = V_5 ; V_34 < V_35 ; V_34 ++ ) {
F_13 ( V_34 , & V_36 , V_20 ) ;
F_14 ( V_34 , V_37 ) ;
}
for ( V_34 = 0 ; V_34 < F_10 ( V_27 ) ; V_34 ++ ) {
F_15 ( V_27 [ V_34 ] . V_28 ,
F_9 ) ;
F_16 ( V_27 [ V_34 ] . V_28 , 1 ) ;
}
return;
}
