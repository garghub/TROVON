static void F_1 ( int V_1 , int type )
{
if ( type & V_2 )
F_2 ( V_3 + V_1 , 0x20 , 0x20 ) ;
else
F_2 ( V_3 + V_1 , 0x00 , 0x20 ) ;
if ( type & V_4 )
F_2 ( V_3 + V_1 , 0x10 , 0x10 ) ;
else
F_2 ( V_3 + V_1 , 0x00 , 0x10 ) ;
}
static int F_3 ( struct V_5 * V_6 , unsigned V_7 )
{
if ( V_7 > 8 ) {
F_4 ( L_1 ) ;
return - 1 ;
}
return F_2 ( V_3 + V_7 ,
V_8 , V_8 ) ;
}
static int F_5 ( struct V_5 * V_6 ,
unsigned V_7 , int V_9 )
{
int V_10 = 0 ;
if ( V_7 < 8 )
V_10 = F_2 ( V_3 + V_7 ,
V_11 | ( V_9 ? V_12 : 0 ) ,
V_11 | V_12 | V_8 ) ;
else if ( V_7 < 16 )
V_10 = F_2 ( V_13 + V_7 - 8 ,
V_14 | ( V_9 ? V_15 : 0 ) ,
V_14 | V_15 | V_16 ) ;
else if ( V_7 > 15 && V_7 < 24 )
V_10 = F_2 ( V_17 ,
V_9 ? 1 << ( V_7 - 16 ) : 0 ,
1 << ( V_7 - 16 ) ) ;
else {
F_4 ( L_2 , V_7 ) ;
F_6 ( 1 ) ;
}
return V_10 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned V_7 )
{
T_1 V_18 ;
int V_19 ;
if ( V_7 > 8 )
return - V_20 ;
V_19 = F_8 ( V_3 + V_7 , & V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_18 & V_21 ;
}
static void F_9 ( struct V_5 * V_6 , unsigned V_7 , int V_9 )
{
if ( V_7 < 8 )
F_2 ( V_3 + V_7 ,
V_11 | ( V_9 ? V_12 : 0 ) ,
V_11 | V_12 ) ;
else if ( V_7 < 16 )
F_2 ( V_13 + V_7 - 8 ,
V_14 | ( V_9 ? V_15 : 0 ) ,
V_14 | V_15 | V_16 ) ;
else if ( V_7 > 15 && V_7 < 24 )
F_2 ( V_17 ,
V_9 ? 1 << ( V_7 - 16 ) : 0 ,
1 << ( V_7 - 16 ) ) ;
}
static int F_10 ( struct V_22 * V_23 , unsigned type )
{
struct V_24 * V_25 = F_11 ( V_23 ) ;
T_2 V_1 = V_23 -> V_26 - V_25 -> V_27 ;
if ( V_1 >= V_25 -> V_6 . V_28 )
return - V_29 ;
V_25 -> V_30 = type ;
V_25 -> V_31 = V_1 | V_32 ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , unsigned V_7 )
{
struct V_24 * V_25 = F_13 ( V_6 , struct V_24 , V_6 ) ;
return V_25 -> V_27 + V_7 ;
}
static void F_14 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_11 ( V_23 ) ;
F_15 ( & V_25 -> V_33 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_11 ( V_23 ) ;
if ( V_25 -> V_31 ) {
unsigned int V_1 = V_25 -> V_31 & ~ V_32 ;
F_1 ( V_1 , V_25 -> V_30 ) ;
V_25 -> V_31 = 0 ;
}
F_17 ( & V_25 -> V_33 ) ;
}
static void F_18 ( struct V_22 * V_23 ) { }
static void F_19 ( struct V_22 * V_23 ) { }
static T_3 F_20 ( int V_26 , void * V_23 )
{
struct V_24 * V_25 = V_23 ;
T_1 V_34 = * ( ( T_1 * ) V_25 -> V_35 + 4 ) ;
int V_1 ;
T_3 V_19 = V_36 ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
if ( V_34 & ( 1 << V_1 ) ) {
F_21 ( L_3 , V_1 ) ;
F_22 ( V_25 -> V_27 + V_1 ) ;
V_19 = V_37 ;
}
}
return V_19 ;
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = & V_39 -> V_41 ;
int V_26 = F_24 ( V_39 , 0 ) ;
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_24 * V_25 ;
int V_45 ;
int V_46 ;
if ( V_26 < 0 ) {
F_25 ( V_41 , L_4 ) ;
return - V_29 ;
}
if ( ! V_43 || ! V_43 -> V_47 || ! V_43 -> V_27 ) {
F_25 ( V_41 , L_5 ) ;
return - V_29 ;
}
V_25 = F_26 ( sizeof( * V_25 ) , V_48 ) ;
if ( ! V_25 )
return - V_49 ;
F_27 ( V_41 , V_25 ) ;
V_25 -> V_26 = V_26 ;
V_25 -> V_35 = F_28 ( V_43 -> V_35 , 8 ) ;
if ( ! V_25 -> V_35 ) {
F_4 ( L_6 ) ;
V_45 = - V_29 ;
goto V_50;
}
V_25 -> V_27 = V_43 -> V_27 ;
V_25 -> V_6 . V_51 = L_7 ;
V_25 -> V_6 . V_52 = F_3 ;
V_25 -> V_6 . V_53 = F_5 ;
V_25 -> V_6 . V_54 = F_7 ;
V_25 -> V_6 . V_55 = F_9 ;
V_25 -> V_6 . V_56 = F_12 ;
V_25 -> V_6 . V_57 = V_43 -> V_47 ;
V_25 -> V_6 . V_28 = V_58 ;
V_25 -> V_6 . V_59 = 1 ;
V_25 -> V_6 . V_41 = V_41 ;
F_29 ( & V_25 -> V_33 ) ;
V_25 -> V_6 . V_41 = V_41 ;
V_45 = F_30 ( & V_25 -> V_6 ) ;
if ( V_45 ) {
F_4 ( L_8 ) ;
goto V_60;
}
V_45 = F_31 ( V_25 -> V_26 , F_20 , 0 , L_9 , V_25 ) ;
if ( V_45 ) {
F_32 ( L_10 ) ;
goto V_61;
}
for ( V_46 = 0 ; V_46 < 8 ; V_46 ++ ) {
F_33 ( V_46 + V_25 -> V_27 ,
& V_62 ,
V_63 ,
L_11 ) ;
F_34 ( V_46 + V_25 -> V_27 , V_25 ) ;
}
return 0 ;
V_61:
if ( F_35 ( & V_25 -> V_6 ) )
F_4 ( L_12 ) ;
V_60:
F_36 ( V_25 -> V_35 ) ;
V_50:
F_37 ( V_25 ) ;
return V_45 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_64 ) ;
}
