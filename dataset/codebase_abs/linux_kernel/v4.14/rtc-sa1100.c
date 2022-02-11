static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
unsigned long V_8 = 0 ;
F_3 ( & V_4 -> V_9 ) ;
V_7 = F_4 ( V_4 -> V_7 ) ;
F_5 ( 0 , V_4 -> V_7 ) ;
if ( V_7 & ( V_10 | V_11 ) ) {
F_5 ( ( V_12 | V_13 ) & ( V_7 >> 2 ) , V_4 -> V_7 ) ;
} else {
F_5 ( V_12 | V_13 , V_4 -> V_7 ) ;
}
if ( V_7 & V_12 )
V_7 &= ~ V_10 ;
F_5 ( V_7 & ( V_10 | V_11 ) , V_4 -> V_7 ) ;
if ( V_7 & V_12 )
V_8 |= V_14 | V_15 ;
if ( V_7 & V_13 )
V_8 |= V_16 | V_15 ;
F_6 ( V_6 , 1 , V_8 ) ;
F_7 ( & V_4 -> V_9 ) ;
return V_17 ;
}
static int F_8 ( struct V_18 * V_19 , unsigned int V_20 )
{
T_2 V_7 ;
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_9 ( & V_4 -> V_9 ) ;
V_7 = F_4 ( V_4 -> V_7 ) ;
if ( V_20 )
V_7 |= V_10 ;
else
V_7 &= ~ V_10 ;
F_5 ( V_7 , V_4 -> V_7 ) ;
F_10 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_12 ( F_4 ( V_4 -> V_23 ) , V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
unsigned long time ;
int V_24 ;
V_24 = F_14 ( V_22 , & time ) ;
if ( V_24 == 0 )
F_5 ( time , V_4 -> V_23 ) ;
return V_24 ;
}
static int F_15 ( struct V_18 * V_19 , struct V_25 * V_26 )
{
T_2 V_7 ;
struct V_3 * V_4 = F_2 ( V_19 ) ;
V_7 = F_4 ( V_4 -> V_7 ) ;
V_26 -> V_20 = ( V_7 & V_10 ) ? 1 : 0 ;
V_26 -> V_27 = ( V_7 & V_12 ) ? 1 : 0 ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 , struct V_25 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
unsigned long time ;
int V_24 ;
F_9 ( & V_4 -> V_9 ) ;
V_24 = F_14 ( & V_26 -> time , & time ) ;
if ( V_24 != 0 )
goto V_28;
F_5 ( F_4 ( V_4 -> V_7 ) &
( V_11 | V_10 | V_12 ) , V_4 -> V_7 ) ;
F_5 ( time , V_4 -> V_29 ) ;
if ( V_26 -> V_20 )
F_5 ( F_4 ( V_4 -> V_7 ) | V_10 , V_4 -> V_7 ) ;
else
F_5 ( F_4 ( V_4 -> V_7 ) & ~ V_10 , V_4 -> V_7 ) ;
V_28:
F_10 ( & V_4 -> V_9 ) ;
return V_24 ;
}
static int F_17 ( struct V_18 * V_19 , struct V_30 * V_31 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_18 ( V_31 , L_1 , F_4 ( V_4 -> V_32 ) ) ;
F_18 ( V_31 , L_2 , F_4 ( V_4 -> V_7 ) ) ;
return 0 ;
}
int F_19 ( struct V_33 * V_34 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_24 ;
F_20 ( & V_4 -> V_9 ) ;
V_4 -> V_35 = F_21 ( & V_34 -> V_19 , NULL ) ;
if ( F_22 ( V_4 -> V_35 ) ) {
F_23 ( & V_34 -> V_19 , L_3 ) ;
return F_24 ( V_4 -> V_35 ) ;
}
V_24 = F_25 ( V_4 -> V_35 ) ;
if ( V_24 )
return V_24 ;
if ( F_4 ( V_4 -> V_32 ) == 0 ) {
F_5 ( V_36 + ( V_37 << 16 ) , V_4 -> V_32 ) ;
F_26 ( & V_34 -> V_19 , L_4
L_5 ) ;
F_5 ( 0 , V_4 -> V_23 ) ;
}
V_6 = F_27 ( & V_34 -> V_19 , V_34 -> V_38 , & V_39 ,
V_40 ) ;
if ( F_22 ( V_6 ) ) {
F_28 ( V_4 -> V_35 ) ;
return F_24 ( V_6 ) ;
}
V_4 -> V_6 = V_6 ;
V_6 -> V_41 = V_42 ;
F_29 ( V_6 , NULL , V_42 ) ;
F_5 ( V_12 | V_13 , V_4 -> V_7 ) ;
return 0 ;
}
static int F_30 ( struct V_33 * V_34 )
{
struct V_3 * V_4 ;
struct V_43 * V_44 ;
void T_3 * V_45 ;
int V_46 , V_47 ;
int V_24 ;
V_46 = F_31 ( V_34 , L_6 ) ;
V_47 = F_31 ( V_34 , L_7 ) ;
if ( V_46 < 0 || V_47 < 0 )
return - V_48 ;
V_4 = F_32 ( & V_34 -> V_19 , sizeof( struct V_3 ) , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_46 = V_46 ;
V_4 -> V_47 = V_47 ;
V_24 = F_33 ( & V_34 -> V_19 , V_46 , F_1 , 0 ,
L_6 , & V_34 -> V_19 ) ;
if ( V_24 ) {
F_23 ( & V_34 -> V_19 , L_8 , V_46 ) ;
return V_24 ;
}
V_24 = F_33 ( & V_34 -> V_19 , V_47 , F_1 , 0 ,
L_9 , & V_34 -> V_19 ) ;
if ( V_24 ) {
F_23 ( & V_34 -> V_19 , L_8 , V_47 ) ;
return V_24 ;
}
V_44 = F_34 ( V_34 , V_51 , 0 ) ;
V_45 = F_35 ( & V_34 -> V_19 , V_44 ) ;
if ( F_22 ( V_45 ) )
return F_24 ( V_45 ) ;
if ( F_36 ( V_52 ) ||
F_37 ( V_34 -> V_19 . V_53 , L_10 ) ) {
V_4 -> V_23 = V_45 + 0x04 ;
V_4 -> V_7 = V_45 + 0x10 ;
V_4 -> V_29 = V_45 + 0x00 ;
V_4 -> V_32 = V_45 + 0x08 ;
} else {
V_4 -> V_23 = V_45 + 0x0 ;
V_4 -> V_7 = V_45 + 0x8 ;
V_4 -> V_29 = V_45 + 0x4 ;
V_4 -> V_32 = V_45 + 0xc ;
}
F_38 ( V_34 , V_4 ) ;
F_39 ( & V_34 -> V_19 , 1 ) ;
return F_19 ( V_34 , V_4 ) ;
}
static int F_40 ( struct V_33 * V_34 )
{
struct V_3 * V_4 = F_41 ( V_34 ) ;
if ( V_4 ) {
F_9 ( & V_4 -> V_9 ) ;
F_5 ( 0 , V_4 -> V_7 ) ;
F_10 ( & V_4 -> V_9 ) ;
F_28 ( V_4 -> V_35 ) ;
}
return 0 ;
}
static int F_42 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
if ( F_43 ( V_19 ) )
F_44 ( V_4 -> V_47 ) ;
return 0 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
if ( F_43 ( V_19 ) )
F_46 ( V_4 -> V_47 ) ;
return 0 ;
}
