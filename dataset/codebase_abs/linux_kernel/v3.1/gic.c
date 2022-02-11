static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_2 -> V_7 - V_4 -> V_8 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_2 V_9 = 1 << ( V_2 -> V_7 % 32 ) ;
F_6 ( & V_10 ) ;
F_7 ( V_9 , F_1 ( V_2 ) + V_11 + ( F_4 ( V_2 ) / 32 ) * 4 ) ;
if ( V_12 . V_13 )
V_12 . V_13 ( V_2 ) ;
F_8 ( & V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_2 V_9 = 1 << ( V_2 -> V_7 % 32 ) ;
F_6 ( & V_10 ) ;
if ( V_12 . V_14 )
V_12 . V_14 ( V_2 ) ;
F_7 ( V_9 , F_1 ( V_2 ) + V_15 + ( F_4 ( V_2 ) / 32 ) * 4 ) ;
F_8 ( & V_10 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_12 . V_16 ) {
F_6 ( & V_10 ) ;
V_12 . V_16 ( V_2 ) ;
F_8 ( & V_10 ) ;
}
F_7 ( F_4 ( V_2 ) , F_3 ( V_2 ) + V_17 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int type )
{
void T_1 * V_18 = F_1 ( V_2 ) ;
unsigned int V_19 = F_4 ( V_2 ) ;
T_2 V_20 = 1 << ( V_19 % 32 ) ;
T_2 V_21 = ( V_19 / 32 ) * 4 ;
T_2 V_22 = 0x2 << ( ( V_19 % 16 ) * 2 ) ;
T_2 V_23 = ( V_19 / 16 ) * 4 ;
bool V_24 = false ;
T_2 V_25 ;
if ( V_19 < 16 )
return - V_26 ;
if ( type != V_27 && type != V_28 )
return - V_26 ;
F_6 ( & V_10 ) ;
if ( V_12 . V_29 )
V_12 . V_29 ( V_2 , type ) ;
V_25 = F_12 ( V_18 + V_30 + V_23 ) ;
if ( type == V_27 )
V_25 &= ~ V_22 ;
else if ( type == V_28 )
V_25 |= V_22 ;
if ( F_12 ( V_18 + V_15 + V_21 ) & V_20 ) {
F_7 ( V_20 , V_18 + V_11 + V_21 ) ;
V_24 = true ;
}
F_7 ( V_25 , V_18 + V_30 + V_23 ) ;
if ( V_24 )
F_7 ( V_20 , V_18 + V_15 + V_21 ) ;
F_8 ( & V_10 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
if ( V_12 . V_31 )
return V_12 . V_31 ( V_2 ) ;
return - V_32 ;
}
static int F_14 ( struct V_1 * V_2 , const struct V_33 * V_34 ,
bool V_35 )
{
void T_1 * V_36 = F_1 ( V_2 ) + V_37 + ( F_4 ( V_2 ) & ~ 3 ) ;
unsigned int V_38 = ( V_2 -> V_7 % 4 ) * 8 ;
unsigned int V_39 = F_15 ( V_34 , V_40 ) ;
T_2 V_25 , V_9 , V_41 ;
if ( V_39 >= 8 || V_39 >= V_42 )
return - V_26 ;
V_9 = 0xff << V_38 ;
V_41 = 1 << ( V_39 + V_38 ) ;
F_6 ( & V_10 ) ;
V_25 = F_12 ( V_36 ) & ~ V_9 ;
F_7 ( V_25 | V_41 , V_36 ) ;
F_8 ( & V_10 ) ;
return V_43 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_44 )
{
int V_45 = - V_32 ;
if ( V_12 . V_46 )
V_45 = V_12 . V_46 ( V_2 , V_44 ) ;
return V_45 ;
}
static void F_17 ( unsigned int V_7 , struct V_47 * V_48 )
{
struct V_3 * V_49 = F_18 ( V_7 ) ;
struct V_50 * V_51 = F_19 ( V_7 ) ;
unsigned int V_52 , F_4 ;
unsigned long V_53 ;
F_20 ( V_51 , V_48 ) ;
F_6 ( & V_10 ) ;
V_53 = F_12 ( V_49 -> V_6 + V_54 ) ;
F_8 ( & V_10 ) ;
F_4 = ( V_53 & 0x3ff ) ;
if ( F_4 == 1023 )
goto V_55;
V_52 = F_4 + V_49 -> V_8 ;
if ( F_21 ( F_4 < 32 || F_4 > 1020 || V_52 >= V_56 ) )
F_22 ( V_52 , V_48 ) ;
else
F_23 ( V_52 ) ;
V_55:
F_24 ( V_51 , V_48 ) ;
}
void T_3 F_25 ( unsigned int V_57 , unsigned int V_7 )
{
if ( V_57 >= V_58 )
F_26 () ;
if ( F_27 ( V_7 , & V_4 [ V_57 ] ) != 0 )
F_26 () ;
F_28 ( V_7 , F_17 ) ;
}
static void T_3 F_29 ( struct V_3 * V_59 ,
unsigned int V_60 )
{
unsigned int V_61 , V_62 , V_63 ;
void T_1 * V_18 = V_59 -> V_5 ;
T_2 V_33 = 1 << F_30 () ;
V_33 |= V_33 << 8 ;
V_33 |= V_33 << 16 ;
F_7 ( 0 , V_18 + V_64 ) ;
V_61 = F_12 ( V_18 + V_65 ) & 0x1f ;
V_61 = ( V_61 + 1 ) * 32 ;
if ( V_61 > 1020 )
V_61 = 1020 ;
for ( V_63 = 32 ; V_63 < V_61 ; V_63 += 16 )
F_7 ( 0 , V_18 + V_30 + V_63 * 4 / 16 ) ;
for ( V_63 = 32 ; V_63 < V_61 ; V_63 += 4 )
F_7 ( V_33 , V_18 + V_37 + V_63 * 4 / 4 ) ;
for ( V_63 = 32 ; V_63 < V_61 ; V_63 += 4 )
F_7 ( 0xa0a0a0a0 , V_18 + V_66 + V_63 * 4 / 4 ) ;
for ( V_63 = 32 ; V_63 < V_61 ; V_63 += 32 )
F_7 ( 0xffffffff , V_18 + V_11 + V_63 * 4 / 32 ) ;
V_62 = V_59 -> V_8 + V_61 ;
if ( F_31 ( V_62 > V_56 ) )
V_62 = V_56 ;
for ( V_63 = V_60 ; V_63 < V_62 ; V_63 ++ ) {
F_32 ( V_63 , & V_67 , V_68 ) ;
F_33 ( V_63 , V_59 ) ;
F_34 ( V_63 , V_69 | V_70 ) ;
}
F_7 ( 1 , V_18 + V_64 ) ;
}
static void T_4 F_35 ( struct V_3 * V_59 )
{
void T_1 * V_5 = V_59 -> V_5 ;
void T_1 * V_18 = V_59 -> V_6 ;
int V_63 ;
F_7 ( 0xffff0000 , V_5 + V_11 ) ;
F_7 ( 0x0000ffff , V_5 + V_15 ) ;
for ( V_63 = 0 ; V_63 < 32 ; V_63 += 4 )
F_7 ( 0xa0a0a0a0 , V_5 + V_66 + V_63 * 4 / 4 ) ;
F_7 ( 0xf0 , V_18 + V_71 ) ;
F_7 ( 1 , V_18 + V_72 ) ;
}
void T_3 F_36 ( unsigned int V_57 , unsigned int V_60 ,
void T_1 * V_5 , void T_1 * V_6 )
{
struct V_3 * V_59 ;
F_37 ( V_57 >= V_58 ) ;
V_59 = & V_4 [ V_57 ] ;
V_59 -> V_5 = V_5 ;
V_59 -> V_6 = V_6 ;
V_59 -> V_8 = ( V_60 - 1 ) & ~ 31 ;
if ( V_57 == 0 )
V_73 = V_6 ;
F_29 ( V_59 , V_60 ) ;
F_35 ( V_59 ) ;
}
void T_4 F_38 ( unsigned int V_57 )
{
F_37 ( V_57 >= V_58 ) ;
F_35 ( & V_4 [ V_57 ] ) ;
}
void T_4 F_39 ( unsigned int V_7 )
{
unsigned long V_74 ;
F_40 ( V_74 ) ;
F_41 ( V_7 , V_75 ) ;
F_9 ( F_42 ( V_7 ) ) ;
F_43 ( V_74 ) ;
}
void F_44 ( const struct V_33 * V_9 , unsigned int V_7 )
{
unsigned long V_76 = * F_45 ( * V_9 ) ;
F_46 () ;
F_7 ( V_76 << 16 | V_7 , V_4 [ 0 ] . V_5 + V_77 ) ;
}
