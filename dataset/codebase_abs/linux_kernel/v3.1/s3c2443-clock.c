static int F_1 ( void T_1 * V_1 , struct V_2 * V_2 , int V_3 )
{
T_2 V_4 = V_2 -> V_4 ;
T_2 V_5 = F_2 ( V_1 ) ;
if ( V_3 )
V_5 |= V_4 ;
else
V_5 &= ~ V_4 ;
F_3 ( V_5 , V_1 ) ;
return 0 ;
}
int F_4 ( struct V_2 * V_2 , int V_3 )
{
return F_1 ( V_6 , V_2 , V_3 ) ;
}
int F_5 ( struct V_2 * V_2 , int V_3 )
{
return F_1 ( V_7 , V_2 , V_3 ) ;
}
int F_6 ( struct V_2 * V_2 , int V_3 )
{
return F_1 ( V_8 , V_2 , V_3 ) ;
}
static unsigned long F_7 ( struct V_2 * V_2 )
{
unsigned long V_9 = F_8 ( V_2 -> V_10 ) ;
unsigned long div = F_2 ( V_11 ) ;
div &= V_12 ;
div >>= ( V_13 - 1 ) ;
return V_9 / ( div + 1 ) ;
}
static unsigned long F_9 ( struct V_2 * V_2 )
{
unsigned long V_14 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_15 = F_2 ( V_11 ) ;
V_15 &= V_16 ;
V_15 >>= V_17 ;
return V_14 / ( V_15 + 1 ) ;
}
static inline unsigned long F_10 ( unsigned long V_18 )
{
V_18 &= V_19 ;
return V_18 + 1 ;
}
void T_3 F_11 ( T_4 V_20 ,
T_5 V_21 )
{
unsigned long V_22 = F_2 ( V_23 ) ;
unsigned long V_24 = F_2 ( V_25 ) ;
unsigned long V_15 = F_2 ( V_11 ) ;
struct V_2 * V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
unsigned long V_29 ;
unsigned long V_30 ;
unsigned long V_31 ;
int V_32 ;
V_26 = F_12 ( NULL , L_1 ) ;
V_27 = F_8 ( V_26 ) ;
F_13 ( V_26 ) ;
V_28 = V_20 ( V_24 , V_27 ) ;
V_33 . V_2 . V_14 = V_28 ;
V_29 = V_28 / V_21 ( V_15 ) ;
V_30 = F_9 ( & V_34 ) ;
V_30 /= F_10 ( V_15 ) ;
V_31 = V_30 / ( ( V_15 & V_35 ) ? 2 : 1 ) ;
F_14 ( V_29 , V_30 , V_31 ) ;
F_15 ( L_2 ,
( V_24 & V_36 ) ? L_3 : L_4 ,
F_16 ( V_28 ) , F_16 ( V_29 ) ,
F_16 ( V_30 ) , F_16 ( V_31 ) ) ;
for ( V_32 = 0 ; V_32 < F_17 ( V_37 ) ; V_32 ++ )
F_18 ( & V_37 [ V_32 ] , true ) ;
if ( F_8 ( & V_38 . V_2 ) != ( 48 * 1000 * 1000 ) ) {
F_15 ( V_39 L_5 ) ;
F_19 ( & V_38 . V_2 , 48 * 1000 * 1000 ) ;
}
F_15 ( L_6 ,
( V_22 & V_36 ) ? L_3 : L_4 ,
F_16 ( F_8 ( & V_40 ) ) ,
F_16 ( F_8 ( & V_41 ) ) ) ;
}
void T_6 F_20 ( int V_27 , T_4 V_20 ,
T_5 V_21 )
{
int V_32 ;
V_42 . V_10 = & V_34 ;
V_43 . V_10 = & V_34 ;
V_41 . V_10 = & V_38 . V_2 ;
V_40 . V_10 = & V_44 . V_2 ;
F_21 ( V_27 ) ;
F_22 ( V_45 , F_17 ( V_45 ) ) ;
for ( V_32 = 0 ; V_32 < F_17 ( V_46 ) ; V_32 ++ )
F_23 ( V_46 [ V_32 ] , 1 ) ;
F_23 ( V_37 , F_17 ( V_37 ) ) ;
F_24 ( V_47 , F_17 ( V_47 ) ) ;
F_24 ( V_48 , F_17 ( V_48 ) ) ;
F_25 ( V_48 , F_17 ( V_48 ) ) ;
F_11 ( V_20 , V_21 ) ;
}
