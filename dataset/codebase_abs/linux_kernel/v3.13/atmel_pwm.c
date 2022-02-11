static inline void F_1 ( const struct V_1 * V_2 , unsigned V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( const struct V_1 * V_2 , unsigned V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void T_2 * F_5 ( const struct V_1 * V_2 , int V_6 )
{
return V_2 -> V_5 + 0x200 + V_6 * 0x20 ;
}
static void F_6 ( struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = & V_1 -> V_12 -> V_11 ;
F_7 ( V_11 , L_1 ,
V_9 ,
F_3 ( V_1 , V_13 ) ,
F_3 ( V_1 , V_14 ) ,
F_3 ( V_1 , V_15 ) ) ;
F_7 ( V_11 ,
L_2 ,
V_8 -> V_6 ,
F_8 ( V_8 , V_16 ) ,
F_8 ( V_8 , V_17 ) ,
F_8 ( V_8 , V_18 ) ,
F_8 ( V_8 , V_19 ) ) ;
}
int F_9 ( int V_6 , struct V_7 * V_8 )
{
unsigned long V_20 ;
int V_21 = 0 ;
if ( ! V_1 )
return - V_22 ;
if ( ! ( V_1 -> V_23 & 1 << V_6 ) )
return - V_24 ;
if ( V_6 < 0 || V_6 >= V_25 || ! V_8 )
return - V_26 ;
memset ( V_8 , 0 , sizeof *V_8 ) ;
F_10 ( & V_1 -> V_27 , V_20 ) ;
if ( V_1 -> V_28 [ V_6 ] )
V_21 = - V_29 ;
else {
F_11 ( V_1 -> V_30 ) ;
V_8 -> V_31 = F_5 ( V_1 , V_6 ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_32 = F_12 ( V_1 -> V_30 ) ;
V_1 -> V_28 [ V_6 ] = V_8 ;
V_1 -> V_33 [ V_6 ] = NULL ;
F_1 ( V_1 , V_34 , 1 << V_6 ) ;
F_1 ( V_1 , V_35 , 1 << V_6 ) ;
}
F_13 ( & V_1 -> V_27 , V_20 ) ;
return V_21 ;
}
static int F_14 ( struct V_7 * V_8 )
{
int V_6 ;
if ( ! V_1 )
return - V_24 ;
if ( ! V_8 )
return - V_26 ;
V_6 = V_8 -> V_6 ;
if ( V_6 < 0 || V_6 >= V_25 || V_1 -> V_28 [ V_6 ] != V_8 )
return - V_26 ;
return V_6 ;
}
int F_15 ( struct V_7 * V_8 )
{
unsigned long V_20 ;
int V_36 ;
F_10 ( & V_1 -> V_27 , V_20 ) ;
V_36 = F_14 ( V_8 ) ;
if ( V_36 >= 0 ) {
V_1 -> V_28 [ V_36 ] = NULL ;
V_1 -> V_33 [ V_36 ] = NULL ;
F_1 ( V_1 , V_34 , 1 << V_36 ) ;
F_1 ( V_1 , V_35 , 1 << V_36 ) ;
F_16 ( V_1 -> V_30 ) ;
V_36 = 0 ;
}
F_13 ( & V_1 -> V_27 , V_20 ) ;
return V_36 ;
}
int F_17 ( struct V_7 * V_8 , int V_37 )
{
unsigned long V_20 ;
int V_36 ;
F_10 ( & V_1 -> V_27 , V_20 ) ;
V_36 = F_14 ( V_8 ) ;
if ( V_36 >= 0 ) {
F_1 ( V_1 , V_37 ? V_38 : V_34 , 1 << V_36 ) ;
V_36 = 0 ;
F_6 ( V_8 , V_37 ? L_3 : L_4 ) ;
}
F_13 ( & V_1 -> V_27 , V_20 ) ;
return V_36 ;
}
int F_18 ( unsigned V_39 , unsigned div )
{
unsigned long V_20 ;
T_1 V_40 ;
T_1 V_4 = ( V_39 << 8 ) | div ;
int V_41 = - V_29 ;
if ( V_39 >= 10 || div == 0 || div > 255 )
return - V_26 ;
F_10 ( & V_1 -> V_27 , V_20 ) ;
V_40 = F_3 ( V_1 , V_13 ) ;
if ( ( V_40 & 0xffff ) == 0 ) {
V_40 |= V_4 ;
V_41 = V_42 ;
} else if ( ( V_40 & ( 0xffff << 16 ) ) == 0 ) {
V_40 |= V_4 << 16 ;
V_41 = V_43 ;
}
if ( V_41 > 0 )
F_1 ( V_1 , V_13 , V_40 ) ;
F_13 ( & V_1 -> V_27 , V_20 ) ;
return V_41 ;
}
void F_19 ( unsigned V_30 )
{
unsigned long V_20 ;
T_1 V_40 ;
F_10 ( & V_1 -> V_27 , V_20 ) ;
V_40 = F_3 ( V_1 , V_13 ) ;
if ( V_30 == V_42 )
F_1 ( V_1 , V_13 , V_40 & ~ ( 0xffff << 0 ) ) ;
if ( V_30 == V_43 )
F_1 ( V_1 , V_13 , V_40 & ~ ( 0xffff << 16 ) ) ;
F_13 ( & V_1 -> V_27 , V_20 ) ;
}
int F_20 ( struct V_7 * V_8 ,
void (* V_33)( struct V_7 * V_8 ) )
{
unsigned long V_20 ;
int V_36 ;
F_10 ( & V_1 -> V_27 , V_20 ) ;
V_36 = F_14 ( V_8 ) ;
if ( V_36 >= 0 ) {
V_1 -> V_33 [ V_36 ] = V_33 ;
F_1 ( V_1 , V_33 ? V_44 : V_35 , 1 << V_36 ) ;
V_36 = 0 ;
}
F_13 ( & V_1 -> V_27 , V_20 ) ;
return V_36 ;
}
static T_3 F_21 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
T_3 V_47 = V_48 ;
T_1 V_49 ;
int V_6 ;
F_22 ( & V_2 -> V_27 ) ;
V_49 = F_3 ( V_1 , V_50 ) ;
while ( V_49 ) {
struct V_7 * V_8 ;
void (* V_33)( struct V_7 * V_8 );
V_6 = F_23 ( V_49 ) - 1 ;
V_49 &= ~ ( 1 << V_6 ) ;
V_8 = V_1 -> V_28 [ V_6 ] ;
V_33 = V_1 -> V_33 [ V_6 ] ;
if ( V_33 && V_8 ) {
F_24 ( & V_2 -> V_27 ) ;
V_33 ( V_8 ) ;
F_22 ( & V_2 -> V_27 ) ;
V_47 = V_51 ;
}
}
F_24 ( & V_2 -> V_27 ) ;
return V_47 ;
}
static int T_4 F_25 ( struct V_52 * V_12 )
{
struct V_53 * V_54 = F_26 ( V_12 , V_55 , 0 ) ;
int V_56 = F_27 ( V_12 , 0 ) ;
T_1 * V_57 = V_12 -> V_11 . V_58 ;
struct V_1 * V_2 ;
int V_21 = - V_59 ;
if ( V_1 )
return - V_29 ;
if ( ! V_54 || V_56 < 0 || ! V_57 || ! * V_57 )
return - V_24 ;
if ( * V_57 & ~ ( ( 1 << V_25 ) - 1 ) ) {
F_28 ( & V_12 -> V_11 , L_5 ,
* V_57 , V_25 ) ;
return - V_26 ;
}
V_2 = F_29 ( sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
return - V_61 ;
F_30 ( & V_2 -> V_27 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_23 = * V_57 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_5 = F_31 ( V_54 -> V_62 , F_32 ( V_54 ) ) ;
if ( ! V_2 -> V_5 )
goto V_63;
V_2 -> V_30 = F_33 ( & V_12 -> V_11 , L_6 ) ;
if ( F_34 ( V_2 -> V_30 ) ) {
V_21 = F_35 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
goto V_63;
}
V_21 = F_36 ( V_56 , F_21 , 0 , V_12 -> V_64 , V_2 ) ;
if ( V_21 < 0 )
goto V_63;
V_1 = V_2 ;
F_37 ( V_12 , V_2 ) ;
return 0 ;
V_63:
if ( V_2 -> V_30 )
F_38 ( V_2 -> V_30 ) ;
if ( V_2 -> V_5 )
F_39 ( V_2 -> V_5 ) ;
F_40 ( V_2 ) ;
return V_21 ;
}
static int T_5 F_41 ( struct V_52 * V_12 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
if ( V_2 != V_1 )
return - V_26 ;
F_11 ( V_1 -> V_30 ) ;
F_1 ( V_1 , V_34 , ( 1 << V_25 ) - 1 ) ;
F_1 ( V_1 , V_35 , ( 1 << V_25 ) - 1 ) ;
F_16 ( V_1 -> V_30 ) ;
V_1 = NULL ;
F_43 ( V_2 -> V_56 , V_2 ) ;
F_38 ( V_2 -> V_30 ) ;
F_39 ( V_2 -> V_5 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
