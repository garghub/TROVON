static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
int V_8 ;
V_8 = F_4 ( V_5 -> V_9 ) ;
if ( V_8 )
return V_8 ;
F_5 ( & V_5 -> V_10 , V_6 ) ;
V_7 = F_6 ( V_5 -> V_11 + V_12 ) ;
V_7 |= V_13 ;
F_7 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_10 , V_6 ) ;
F_9 ( V_5 -> V_11 + 0x200 , 0 ,
V_14 [ 0 ] . V_15 & 0xfffe ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_5 ( & V_5 -> V_10 , V_6 ) ;
V_7 = F_6 ( V_5 -> V_11 + V_12 ) ;
V_7 &= ~ V_13 ;
F_7 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_10 , V_6 ) ;
F_11 ( V_5 -> V_9 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_16 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_13 ( V_5 -> V_11 + 0x200 , 0 , V_16 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_16 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_15 ( V_5 -> V_11 + 0x200 , 0 , V_16 ) ;
}
static void F_16 ( struct V_17 * V_18 )
{
struct V_5 * V_5 = F_17 ( V_18 ) ;
unsigned int V_19 ;
unsigned int V_20 , V_21 ;
V_21 = V_5 -> V_21 ;
while ( ( V_19 = F_6 ( V_5 -> V_11 + V_22 ) &
~ F_6 ( V_5 -> V_11 + V_23 ) ) )
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ )
if ( V_19 & ( 1 << V_20 ) )
F_18 ( V_21 + V_20 ) ;
}
static void F_19 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_20 ( V_26 ) ;
unsigned long V_6 ;
T_1 V_27 ;
F_5 ( & V_5 -> V_10 , V_6 ) ;
V_27 = F_6 ( V_5 -> V_11 + V_23 ) ;
V_27 |= 1 << ( V_26 -> V_28 - V_5 -> V_21 ) ;
F_7 ( V_27 , V_5 -> V_11 + V_23 ) ;
F_8 ( & V_5 -> V_10 , V_6 ) ;
}
static void F_21 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_20 ( V_26 ) ;
unsigned long V_6 ;
T_1 V_27 ;
F_5 ( & V_5 -> V_10 , V_6 ) ;
V_27 = F_6 ( V_5 -> V_11 + V_23 ) ;
V_27 &= ~ ( 1 << ( V_26 -> V_28 - V_5 -> V_21 ) ) ;
F_7 ( V_27 , V_5 -> V_11 + V_23 ) ;
F_8 ( & V_5 -> V_10 , V_6 ) ;
}
static void F_22 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_28 , V_21 ;
V_21 = V_5 -> V_21 ;
for ( V_28 = V_21 ; V_28 < V_21 + V_24 ; V_28 ++ ) {
F_23 ( V_28 , & V_29 , V_30 ) ;
F_24 ( V_28 , V_5 ) ;
}
F_25 ( V_5 -> V_28 , V_31 ) ;
F_26 ( V_5 -> V_28 , F_16 , V_5 ) ;
}
static void F_27 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_28 , V_21 ;
V_21 = V_5 -> V_21 ;
F_26 ( V_5 -> V_28 , NULL , NULL ) ;
for ( V_28 = V_21 ; V_28 < V_21 + V_24 ; V_28 ++ ) {
F_28 ( V_28 , NULL ) ;
F_24 ( V_28 , NULL ) ;
}
}
static int F_29 ( struct V_1 * V_3 , T_2 V_16 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
struct V_32 * V_33 = F_30 ( & V_3 -> V_3 ) ;
if ( V_33 && V_33 -> V_34 )
V_33 -> V_34 ( V_3 ) ;
F_11 ( V_5 -> V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
struct V_32 * V_33 = F_30 ( & V_3 -> V_3 ) ;
int V_8 ;
V_8 = F_4 ( V_5 -> V_35 ) ;
if ( V_8 )
return V_8 ;
if ( V_33 && V_33 -> V_36 )
V_33 -> V_36 ( V_3 ) ;
F_9 ( V_5 -> V_11 + 0x200 , 0 ,
V_14 [ 0 ] . V_15 & 0xfffe ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_3 )
{
struct V_32 * V_33 = F_30 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 ;
struct V_37 * V_38 , * V_39 ;
int V_8 ;
if ( ! V_33 )
return - V_40 ;
V_38 = F_33 ( V_3 , V_41 , 0 ) ;
if ( ! V_38 )
return - V_40 ;
V_5 = F_34 ( sizeof *V_5 , V_42 ) ;
if ( ! V_5 )
return - V_43 ;
F_35 ( & V_5 -> V_10 ) ;
F_36 ( V_3 , V_5 ) ;
V_8 = F_37 ( V_3 , 0 ) ;
if ( V_8 >= 0 )
V_5 -> V_28 = V_8 ;
else
goto V_44;
V_5 -> V_21 = V_33 -> V_21 ;
V_5 -> V_9 = F_38 ( & V_3 -> V_3 , L_1 ) ;
if ( F_39 ( V_5 -> V_9 ) ) {
V_8 = F_40 ( V_5 -> V_9 ) ;
goto V_45;
}
V_5 -> V_35 = F_38 ( & V_3 -> V_3 , L_2 ) ;
if ( F_39 ( V_5 -> V_35 ) ) {
V_8 = F_40 ( V_5 -> V_35 ) ;
goto V_46;
}
V_39 = & V_5 -> V_39 ;
V_39 -> V_47 = L_3 ;
V_39 -> V_15 = V_38 -> V_15 ;
V_39 -> V_48 = V_38 -> V_15 + 0xff ;
V_39 -> V_6 = V_41 ;
V_8 = F_41 ( V_38 , V_39 ) ;
if ( V_8 )
goto V_49;
V_5 -> V_11 = F_42 ( V_39 -> V_15 , F_43 ( V_39 ) ) ;
if ( ! V_5 -> V_11 ) {
V_8 = - V_43 ;
goto V_50;
}
V_8 = F_4 ( V_5 -> V_35 ) ;
if ( V_8 )
goto V_51;
if ( V_33 -> V_52 )
V_33 -> V_52 ( V_3 ) ;
F_7 ( 0xbf , V_5 -> V_11 + V_23 ) ;
F_44 ( V_53 L_4 ,
V_3 -> V_47 , F_6 ( V_5 -> V_11 + V_54 ) ,
( unsigned long ) V_38 -> V_15 , V_5 -> V_28 ) ;
F_22 ( V_3 ) ;
V_55 [ V_56 ] . V_57 = V_33 -> V_58 ;
V_55 [ V_56 ] . V_59 = sizeof( * V_33 -> V_58 ) ;
V_8 = F_45 ( & V_3 -> V_3 , V_3 -> V_60 ,
V_55 , F_46 ( V_55 ) ,
V_38 , V_5 -> V_21 , NULL ) ;
if ( ! V_8 )
return 0 ;
F_27 ( V_3 ) ;
F_11 ( V_5 -> V_35 ) ;
V_51:
F_47 ( V_5 -> V_11 ) ;
V_50:
F_48 ( & V_5 -> V_39 ) ;
V_49:
F_49 ( V_5 -> V_35 ) ;
V_46:
F_49 ( V_5 -> V_9 ) ;
V_45:
V_44:
F_50 ( V_5 ) ;
return V_8 ;
}
static int F_51 ( struct V_1 * V_3 )
{
struct V_32 * V_33 = F_30 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_8 ;
V_8 = V_33 -> V_61 ( V_3 ) ;
F_11 ( V_5 -> V_35 ) ;
F_49 ( V_5 -> V_35 ) ;
F_11 ( V_5 -> V_9 ) ;
F_49 ( V_5 -> V_9 ) ;
F_27 ( V_3 ) ;
F_47 ( V_5 -> V_11 ) ;
F_48 ( & V_5 -> V_39 ) ;
F_52 ( & V_3 -> V_3 ) ;
F_50 ( V_5 ) ;
return V_8 ;
}
