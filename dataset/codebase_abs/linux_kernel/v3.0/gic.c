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
unsigned int V_39 = F_15 ( V_34 ) ;
T_2 V_25 , V_9 , V_40 ;
if ( V_39 >= 8 )
return - V_26 ;
V_9 = 0xff << V_38 ;
V_40 = 1 << ( V_39 + V_38 ) ;
F_6 ( & V_10 ) ;
V_2 -> V_41 = V_39 ;
V_25 = F_12 ( V_36 ) & ~ V_9 ;
F_7 ( V_25 | V_40 , V_36 ) ;
F_8 ( & V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_42 )
{
int V_43 = - V_32 ;
if ( V_12 . V_44 )
V_43 = V_12 . V_44 ( V_2 , V_42 ) ;
return V_43 ;
}
static void F_17 ( unsigned int V_7 , struct V_45 * V_46 )
{
struct V_3 * V_47 = F_18 ( V_7 ) ;
struct V_48 * V_49 = F_19 ( V_7 ) ;
unsigned int V_50 , F_4 ;
unsigned long V_51 ;
F_20 ( V_49 , V_46 ) ;
F_6 ( & V_10 ) ;
V_51 = F_12 ( V_47 -> V_6 + V_52 ) ;
F_8 ( & V_10 ) ;
F_4 = ( V_51 & 0x3ff ) ;
if ( F_4 == 1023 )
goto V_53;
V_50 = F_4 + V_47 -> V_8 ;
if ( F_21 ( F_4 < 32 || F_4 > 1020 || V_50 >= V_54 ) )
F_22 ( V_50 , V_46 ) ;
else
F_23 ( V_50 ) ;
V_53:
F_24 ( V_49 , V_46 ) ;
}
void T_3 F_25 ( unsigned int V_55 , unsigned int V_7 )
{
if ( V_55 >= V_56 )
F_26 () ;
if ( F_27 ( V_7 , & V_4 [ V_55 ] ) != 0 )
F_26 () ;
F_28 ( V_7 , F_17 ) ;
}
static void T_3 F_29 ( struct V_3 * V_57 ,
unsigned int V_58 )
{
unsigned int V_59 , V_60 , V_61 ;
void T_1 * V_18 = V_57 -> V_5 ;
T_2 V_33 = 1 << F_30 () ;
V_33 |= V_33 << 8 ;
V_33 |= V_33 << 16 ;
F_7 ( 0 , V_18 + V_62 ) ;
V_59 = F_12 ( V_18 + V_63 ) & 0x1f ;
V_59 = ( V_59 + 1 ) * 32 ;
if ( V_59 > 1020 )
V_59 = 1020 ;
for ( V_61 = 32 ; V_61 < V_59 ; V_61 += 16 )
F_7 ( 0 , V_18 + V_30 + V_61 * 4 / 16 ) ;
for ( V_61 = 32 ; V_61 < V_59 ; V_61 += 4 )
F_7 ( V_33 , V_18 + V_37 + V_61 * 4 / 4 ) ;
for ( V_61 = 32 ; V_61 < V_59 ; V_61 += 4 )
F_7 ( 0xa0a0a0a0 , V_18 + V_64 + V_61 * 4 / 4 ) ;
for ( V_61 = 32 ; V_61 < V_59 ; V_61 += 32 )
F_7 ( 0xffffffff , V_18 + V_11 + V_61 * 4 / 32 ) ;
V_60 = V_57 -> V_8 + V_59 ;
if ( F_31 ( V_60 > V_54 ) )
V_60 = V_54 ;
for ( V_61 = V_58 ; V_61 < V_60 ; V_61 ++ ) {
F_32 ( V_61 , & V_65 , V_66 ) ;
F_33 ( V_61 , V_57 ) ;
F_34 ( V_61 , V_67 | V_68 ) ;
}
F_7 ( 1 , V_18 + V_62 ) ;
}
static void T_4 F_35 ( struct V_3 * V_57 )
{
void T_1 * V_5 = V_57 -> V_5 ;
void T_1 * V_18 = V_57 -> V_6 ;
int V_61 ;
F_7 ( 0xffff0000 , V_5 + V_11 ) ;
F_7 ( 0x0000ffff , V_5 + V_15 ) ;
for ( V_61 = 0 ; V_61 < 32 ; V_61 += 4 )
F_7 ( 0xa0a0a0a0 , V_5 + V_64 + V_61 * 4 / 4 ) ;
F_7 ( 0xf0 , V_18 + V_69 ) ;
F_7 ( 1 , V_18 + V_70 ) ;
}
void T_3 F_36 ( unsigned int V_55 , unsigned int V_58 ,
void T_1 * V_5 , void T_1 * V_6 )
{
struct V_3 * V_57 ;
F_37 ( V_55 >= V_56 ) ;
V_57 = & V_4 [ V_55 ] ;
V_57 -> V_5 = V_5 ;
V_57 -> V_6 = V_6 ;
V_57 -> V_8 = ( V_58 - 1 ) & ~ 31 ;
if ( V_55 == 0 )
V_71 = V_6 ;
F_29 ( V_57 , V_58 ) ;
F_35 ( V_57 ) ;
}
void T_4 F_38 ( unsigned int V_55 )
{
F_37 ( V_55 >= V_56 ) ;
F_35 ( & V_4 [ V_55 ] ) ;
}
void T_4 F_39 ( unsigned int V_7 )
{
unsigned long V_72 ;
F_40 ( V_72 ) ;
F_41 ( V_7 , V_73 ) ;
F_9 ( F_42 ( V_7 ) ) ;
F_43 ( V_72 ) ;
}
void F_44 ( const struct V_33 * V_9 , unsigned int V_7 )
{
unsigned long V_74 = * F_45 ( * V_9 ) ;
F_46 () ;
F_7 ( V_74 << 16 | V_7 , V_4 [ 0 ] . V_5 + V_75 ) ;
}
