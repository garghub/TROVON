void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x0100 , V_4 -> V_5 + V_6 ) ;
F_3 ( 0x0000 , V_4 -> V_5 + V_7 ) ;
F_3 ( 0x0000 , V_4 -> V_5 + V_8 ) ;
F_3 ( 0x0000 , V_4 -> V_5 + V_9 ) ;
F_3 ( 0x00FF , V_4 -> V_5 + V_10 ) ;
F_3 ( 0x0000 , V_4 -> V_5 + V_11 ) ;
F_3 ( 0x0000 , V_4 -> V_5 + V_10 ) ;
}
static void F_4 ( struct V_3 * V_4 ,
unsigned V_12 , int V_13 )
{
unsigned short V_14 ;
V_14 = F_5 ( V_4 -> V_5 + V_15 ) ;
if ( V_13 )
V_14 |= 1 << ( V_12 + 1 ) ;
else
V_14 &= ~ ( 1 << ( V_12 + 1 ) ) ;
F_3 ( V_14 , V_4 -> V_5 + V_15 ) ;
}
static void F_6 ( struct V_16 * V_17 , unsigned V_12 , int V_13 )
{
struct V_3 * V_4 = F_7 ( V_17 , struct V_3 , V_18 ) ;
unsigned long V_19 ;
F_8 ( & V_4 -> V_20 , V_19 ) ;
F_4 ( V_4 , V_12 , V_13 ) ;
F_9 ( & V_4 -> V_20 , V_19 ) ;
}
static int F_10 ( struct V_16 * V_17 , unsigned V_12 )
{
struct V_3 * V_4 = F_7 ( V_17 , struct V_3 , V_18 ) ;
return F_5 ( V_4 -> V_5 + V_21 ) & ( 1 << ( V_12 + 1 ) ) ;
}
static int F_11 ( struct V_16 * V_17 ,
unsigned V_12 )
{
struct V_3 * V_4 = F_7 ( V_17 , struct V_3 , V_18 ) ;
unsigned long V_19 ;
unsigned short V_22 ;
F_8 ( & V_4 -> V_20 , V_19 ) ;
V_22 = F_5 ( V_4 -> V_5 + V_23 ) ;
V_22 &= ~ ( 1 << ( V_12 + 1 ) ) ;
F_3 ( V_22 , V_4 -> V_5 + V_23 ) ;
F_9 ( & V_4 -> V_20 , V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 ,
unsigned V_12 , int V_13 )
{
struct V_3 * V_4 = F_7 ( V_17 , struct V_3 , V_18 ) ;
unsigned long V_19 ;
unsigned short V_22 ;
F_8 ( & V_4 -> V_20 , V_19 ) ;
F_4 ( V_4 , V_12 , V_13 ) ;
V_22 = F_5 ( V_4 -> V_5 + V_23 ) ;
V_22 |= 1 << ( V_12 + 1 ) ;
F_3 ( V_22 , V_4 -> V_5 + V_23 ) ;
F_9 ( & V_4 -> V_20 , V_19 ) ;
return 0 ;
}
unsigned short F_13 ( struct V_1 * V_2 , unsigned short V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_5 ( V_4 -> V_5 + V_24 ) ;
}
void F_14 ( struct V_1 * V_2 , unsigned short V_24 , unsigned short V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_25 , V_4 -> V_5 + V_24 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
unsigned short V_26 ;
V_26 = F_5 ( V_4 -> V_5 + V_6 ) ;
if ( ( V_26 & 0x100 ) == 0 )
F_3 ( 0x0101 , V_4 -> V_5 + V_6 ) ;
}
static int F_16 ( struct V_27 * V_2 , T_1 V_28 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
F_15 ( V_4 ) ;
V_4 -> V_29 = F_5 ( V_4 -> V_5 + V_15 ) ;
F_3 ( ( V_4 -> V_29 & ~ V_4 -> V_30 ) | V_4 -> V_31 , V_4 -> V_5 + V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_27 * V_2 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
F_15 ( V_4 ) ;
F_3 ( V_4 -> V_29 , V_4 -> V_5 + V_15 ) ;
return 0 ;
}
static int F_19 ( struct V_27 * V_32 )
{
struct V_3 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 = F_20 ( V_32 , V_38 , 0 ) ;
int V_39 ;
if ( ! V_37 )
return - V_40 ;
V_33 = F_21 ( sizeof( struct V_3 ) , V_41 ) ;
if ( ! V_33 )
return - V_42 ;
F_22 ( & V_33 -> V_20 ) ;
V_35 = V_32 -> V_2 . V_43 ;
V_33 -> V_5 = F_23 ( V_37 -> V_44 , F_24 ( V_37 ) ) ;
if ( ! V_33 -> V_5 ) {
V_39 = - V_42 ;
goto V_45;
}
F_25 ( V_32 , V_33 ) ;
F_26 ( L_1 , ( unsigned int ) V_37 -> V_44 , V_33 -> V_5 ) ;
F_3 ( 0x0140 , V_33 -> V_5 + V_6 ) ;
F_1 ( & V_32 -> V_2 ) ;
F_3 ( 0x0000 , V_33 -> V_5 + V_46 ) ;
F_3 ( V_35 -> V_47 & 0xffff , V_33 -> V_5 + V_23 ) ;
F_3 ( V_35 -> V_48 & 0xffff , V_33 -> V_5 + V_15 ) ;
V_33 -> V_30 = V_35 -> V_30 ;
V_33 -> V_31 = V_35 -> V_31 ;
V_33 -> V_18 . V_5 = - 1 ;
if ( V_35 -> V_49 != 0 ) {
V_33 -> V_18 . V_50 = F_27 ( & V_32 -> V_2 ) ;
V_33 -> V_18 . V_5 = V_35 -> V_49 ;
V_33 -> V_18 . V_51 = 12 ;
V_33 -> V_18 . V_52 = F_6 ;
V_33 -> V_18 . V_53 = F_10 ;
V_33 -> V_18 . V_54 = F_11 ;
V_33 -> V_18 . V_55 = F_12 ;
V_39 = F_28 ( & V_33 -> V_18 ) ;
if ( V_39 )
goto V_56;
}
return 0 ;
V_56:
F_25 ( V_32 , NULL ) ;
V_45:
F_29 ( V_33 -> V_5 ) ;
F_30 ( V_33 ) ;
return V_39 ;
}
static int F_31 ( struct V_27 * V_32 )
{
struct V_3 * V_4 = F_17 ( V_32 ) ;
if ( ! V_4 )
return - V_40 ;
if ( V_4 -> V_18 . V_5 != - 1 )
F_32 ( & V_4 -> V_18 ) ;
F_25 ( V_32 , NULL ) ;
F_29 ( V_4 -> V_5 ) ;
F_30 ( V_4 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_57 ) ;
}
