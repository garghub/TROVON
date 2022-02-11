static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_6 ( V_5 -> V_10 + V_11 ) ;
V_7 |= V_12 ;
F_7 ( V_7 , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
F_9 ( V_5 -> V_10 + 0x200 , 0 ,
V_13 [ 0 ] . V_14 & 0xfffe ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_7 = F_6 ( V_5 -> V_10 + V_11 ) ;
V_7 &= ~ V_12 ;
F_7 ( V_7 , V_5 -> V_10 + V_11 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
F_11 ( V_5 -> V_8 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_15 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_13 ( V_5 -> V_10 + 0x200 , 0 , V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_15 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_15 ( V_5 -> V_10 + 0x200 , 0 , V_15 ) ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_5 * V_5 = F_17 ( V_17 ) ;
unsigned int V_18 ;
unsigned int V_19 , V_20 ;
V_20 = V_5 -> V_20 ;
while ( ( V_18 = F_6 ( V_5 -> V_10 + V_21 ) &
~ F_6 ( V_5 -> V_10 + V_22 ) ) )
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ )
if ( V_18 & ( 1 << V_19 ) )
F_18 ( V_20 + V_19 ) ;
}
static void F_19 ( struct V_24 * V_25 )
{
struct V_5 * V_5 = F_20 ( V_25 ) ;
unsigned long V_6 ;
T_1 V_26 ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_26 = F_6 ( V_5 -> V_10 + V_22 ) ;
V_26 |= 1 << ( V_25 -> V_27 - V_5 -> V_20 ) ;
F_7 ( V_26 , V_5 -> V_10 + V_22 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
}
static void F_21 ( struct V_24 * V_25 )
{
struct V_5 * V_5 = F_20 ( V_25 ) ;
unsigned long V_6 ;
T_1 V_26 ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
V_26 = F_6 ( V_5 -> V_10 + V_22 ) ;
V_26 &= ~ ( 1 << ( V_25 -> V_27 - V_5 -> V_20 ) ) ;
F_7 ( V_26 , V_5 -> V_10 + V_22 ) ;
F_8 ( & V_5 -> V_9 , V_6 ) ;
}
static void F_22 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_27 , V_20 ;
V_20 = V_5 -> V_20 ;
for ( V_27 = V_20 ; V_27 < V_20 + V_23 ; V_27 ++ ) {
F_23 ( V_27 , & V_28 , V_29 ) ;
F_24 ( V_27 , V_5 ) ;
}
F_25 ( V_5 -> V_27 , V_30 ) ;
F_26 ( V_5 -> V_27 , F_16 , V_5 ) ;
}
static void F_27 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_27 , V_20 ;
V_20 = V_5 -> V_20 ;
F_26 ( V_5 -> V_27 , NULL , NULL ) ;
for ( V_27 = V_20 ; V_27 < V_20 + V_23 ; V_27 ++ ) {
F_28 ( V_27 , NULL ) ;
F_24 ( V_27 , NULL ) ;
}
}
static int F_29 ( struct V_1 * V_3 , T_2 V_15 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
struct V_31 * V_32 = F_30 ( & V_3 -> V_3 ) ;
if ( V_32 && V_32 -> V_33 )
V_32 -> V_33 ( V_3 ) ;
F_11 ( V_5 -> V_34 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
struct V_31 * V_32 = F_30 ( & V_3 -> V_3 ) ;
F_4 ( V_5 -> V_34 ) ;
if ( V_32 && V_32 -> V_35 )
V_32 -> V_35 ( V_3 ) ;
F_9 ( V_5 -> V_10 + 0x200 , 0 ,
V_13 [ 0 ] . V_14 & 0xfffe ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_3 )
{
struct V_31 * V_32 = F_30 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 ;
struct V_36 * V_37 , * V_38 ;
int V_39 ;
if ( ! V_32 )
return - V_40 ;
V_37 = F_33 ( V_3 , V_41 , 0 ) ;
if ( ! V_37 )
return - V_40 ;
V_5 = F_34 ( sizeof *V_5 , V_42 ) ;
if ( ! V_5 )
return - V_43 ;
F_35 ( & V_5 -> V_9 ) ;
F_36 ( V_3 , V_5 ) ;
V_39 = F_37 ( V_3 , 0 ) ;
if ( V_39 >= 0 )
V_5 -> V_27 = V_39 ;
else
goto V_44;
V_5 -> V_20 = V_32 -> V_20 ;
V_5 -> V_8 = F_38 ( & V_3 -> V_3 , L_1 ) ;
if ( F_39 ( V_5 -> V_8 ) ) {
V_39 = F_40 ( V_5 -> V_8 ) ;
goto V_45;
}
V_5 -> V_34 = F_38 ( & V_3 -> V_3 , L_2 ) ;
if ( F_39 ( V_5 -> V_34 ) ) {
V_39 = F_40 ( V_5 -> V_34 ) ;
goto V_46;
}
V_38 = & V_5 -> V_38 ;
V_38 -> V_47 = L_3 ;
V_38 -> V_14 = V_37 -> V_14 ;
V_38 -> V_48 = V_37 -> V_14 + 0xff ;
V_38 -> V_6 = V_41 ;
V_39 = F_41 ( V_37 , V_38 ) ;
if ( V_39 )
goto V_49;
V_5 -> V_10 = F_42 ( V_38 -> V_14 , F_43 ( V_38 ) ) ;
if ( ! V_5 -> V_10 ) {
V_39 = - V_43 ;
goto V_50;
}
F_4 ( V_5 -> V_34 ) ;
if ( V_32 -> V_51 )
V_32 -> V_51 ( V_3 ) ;
F_7 ( 0xbf , V_5 -> V_10 + V_22 ) ;
F_44 ( V_52 L_4 ,
V_3 -> V_47 , F_6 ( V_5 -> V_10 + V_53 ) ,
( unsigned long ) V_37 -> V_14 , V_5 -> V_27 ) ;
F_22 ( V_3 ) ;
V_54 [ V_55 ] . V_56 = V_32 -> V_57 ;
V_54 [ V_55 ] . V_58 = sizeof( * V_32 -> V_57 ) ;
V_39 = F_45 ( & V_3 -> V_3 , V_3 -> V_59 ,
V_54 , F_46 ( V_54 ) ,
V_37 , V_5 -> V_20 , NULL ) ;
if ( ! V_39 )
return 0 ;
F_27 ( V_3 ) ;
F_47 ( V_5 -> V_10 ) ;
V_50:
F_48 ( & V_5 -> V_38 ) ;
V_49:
F_49 ( V_5 -> V_34 ) ;
V_46:
F_49 ( V_5 -> V_8 ) ;
V_45:
V_44:
F_50 ( V_5 ) ;
return V_39 ;
}
static int F_51 ( struct V_1 * V_3 )
{
struct V_31 * V_32 = F_30 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_39 ;
V_39 = V_32 -> V_60 ( V_3 ) ;
F_11 ( V_5 -> V_34 ) ;
F_49 ( V_5 -> V_34 ) ;
F_11 ( V_5 -> V_8 ) ;
F_49 ( V_5 -> V_8 ) ;
F_27 ( V_3 ) ;
F_47 ( V_5 -> V_10 ) ;
F_48 ( & V_5 -> V_38 ) ;
F_52 ( & V_3 -> V_3 ) ;
F_50 ( V_5 ) ;
return V_39 ;
}
