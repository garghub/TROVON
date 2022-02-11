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
if ( ! V_1 || ! ( V_1 -> V_22 & 1 << V_6 ) )
return - V_23 ;
if ( V_6 < 0 || V_6 >= V_24 || ! V_8 )
return - V_25 ;
memset ( V_8 , 0 , sizeof *V_8 ) ;
F_10 ( & V_1 -> V_26 , V_20 ) ;
if ( V_1 -> V_27 [ V_6 ] )
V_21 = - V_28 ;
else {
F_11 ( V_1 -> V_29 ) ;
V_8 -> V_30 = F_5 ( V_1 , V_6 ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_31 = F_12 ( V_1 -> V_29 ) ;
V_1 -> V_27 [ V_6 ] = V_8 ;
V_1 -> V_32 [ V_6 ] = NULL ;
F_1 ( V_1 , V_33 , 1 << V_6 ) ;
F_1 ( V_1 , V_34 , 1 << V_6 ) ;
}
F_13 ( & V_1 -> V_26 , V_20 ) ;
return V_21 ;
}
static int F_14 ( struct V_7 * V_8 )
{
int V_6 ;
if ( ! V_1 )
return - V_23 ;
if ( ! V_8 )
return - V_25 ;
V_6 = V_8 -> V_6 ;
if ( V_6 < 0 || V_6 >= V_24 || V_1 -> V_27 [ V_6 ] != V_8 )
return - V_25 ;
return V_6 ;
}
int F_15 ( struct V_7 * V_8 )
{
unsigned long V_20 ;
int V_35 ;
F_10 ( & V_1 -> V_26 , V_20 ) ;
V_35 = F_14 ( V_8 ) ;
if ( V_35 >= 0 ) {
V_1 -> V_27 [ V_35 ] = NULL ;
V_1 -> V_32 [ V_35 ] = NULL ;
F_1 ( V_1 , V_33 , 1 << V_35 ) ;
F_1 ( V_1 , V_34 , 1 << V_35 ) ;
F_16 ( V_1 -> V_29 ) ;
V_35 = 0 ;
}
F_13 ( & V_1 -> V_26 , V_20 ) ;
return V_35 ;
}
int F_17 ( struct V_7 * V_8 , int V_36 )
{
unsigned long V_20 ;
int V_35 ;
F_10 ( & V_1 -> V_26 , V_20 ) ;
V_35 = F_14 ( V_8 ) ;
if ( V_35 >= 0 ) {
F_1 ( V_1 , V_36 ? V_37 : V_33 , 1 << V_35 ) ;
V_35 = 0 ;
F_6 ( V_8 , V_36 ? L_3 : L_4 ) ;
}
F_13 ( & V_1 -> V_26 , V_20 ) ;
return V_35 ;
}
int F_18 ( unsigned V_38 , unsigned div )
{
unsigned long V_20 ;
T_1 V_39 ;
T_1 V_4 = ( V_38 << 8 ) | div ;
int V_40 = - V_28 ;
if ( V_38 >= 10 || div == 0 || div > 255 )
return - V_25 ;
F_10 ( & V_1 -> V_26 , V_20 ) ;
V_39 = F_3 ( V_1 , V_13 ) ;
if ( ( V_39 & 0xffff ) == 0 ) {
V_39 |= V_4 ;
V_40 = V_41 ;
} else if ( ( V_39 & ( 0xffff << 16 ) ) == 0 ) {
V_39 |= V_4 << 16 ;
V_40 = V_42 ;
}
if ( V_40 > 0 )
F_1 ( V_1 , V_13 , V_39 ) ;
F_13 ( & V_1 -> V_26 , V_20 ) ;
return V_40 ;
}
void F_19 ( unsigned V_29 )
{
unsigned long V_20 ;
T_1 V_39 ;
F_10 ( & V_1 -> V_26 , V_20 ) ;
V_39 = F_3 ( V_1 , V_13 ) ;
if ( V_29 == V_41 )
F_1 ( V_1 , V_13 , V_39 & ~ ( 0xffff << 0 ) ) ;
if ( V_29 == V_42 )
F_1 ( V_1 , V_13 , V_39 & ~ ( 0xffff << 16 ) ) ;
F_13 ( & V_1 -> V_26 , V_20 ) ;
}
int F_20 ( struct V_7 * V_8 ,
void (* V_32)( struct V_7 * V_8 ) )
{
unsigned long V_20 ;
int V_35 ;
F_10 ( & V_1 -> V_26 , V_20 ) ;
V_35 = F_14 ( V_8 ) ;
if ( V_35 >= 0 ) {
V_1 -> V_32 [ V_35 ] = V_32 ;
F_1 ( V_1 , V_32 ? V_43 : V_34 , 1 << V_35 ) ;
V_35 = 0 ;
}
F_13 ( & V_1 -> V_26 , V_20 ) ;
return V_35 ;
}
static T_3 F_21 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
T_3 V_46 = V_47 ;
T_1 V_48 ;
int V_6 ;
F_22 ( & V_2 -> V_26 ) ;
V_48 = F_3 ( V_1 , V_49 ) ;
while ( V_48 ) {
struct V_7 * V_8 ;
void (* V_32)( struct V_7 * V_8 );
V_6 = F_23 ( V_48 ) - 1 ;
V_48 &= ~ ( 1 << V_6 ) ;
V_8 = V_1 -> V_27 [ V_6 ] ;
V_32 = V_1 -> V_32 [ V_6 ] ;
if ( V_32 && V_8 ) {
F_24 ( & V_2 -> V_26 ) ;
V_32 ( V_8 ) ;
F_22 ( & V_2 -> V_26 ) ;
V_46 = V_50 ;
}
}
F_24 ( & V_2 -> V_26 ) ;
return V_46 ;
}
static int T_4 F_25 ( struct V_51 * V_12 )
{
struct V_52 * V_53 = F_26 ( V_12 , V_54 , 0 ) ;
int V_55 = F_27 ( V_12 , 0 ) ;
T_1 * V_56 = V_12 -> V_11 . V_57 ;
struct V_1 * V_2 ;
int V_21 = - V_58 ;
if ( V_1 )
return - V_28 ;
if ( ! V_53 || V_55 < 0 || ! V_56 || ! * V_56 )
return - V_23 ;
if ( * V_56 & ~ ( ( 1 << V_24 ) - 1 ) ) {
F_28 ( & V_12 -> V_11 , L_5 ,
* V_56 , V_24 ) ;
return - V_25 ;
}
V_2 = F_29 ( sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
F_30 ( & V_2 -> V_26 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_22 = * V_56 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_5 = F_31 ( V_53 -> V_61 , F_32 ( V_53 ) ) ;
if ( ! V_2 -> V_5 )
goto V_62;
V_2 -> V_29 = F_33 ( & V_12 -> V_11 , L_6 ) ;
if ( F_34 ( V_2 -> V_29 ) ) {
V_21 = F_35 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
goto V_62;
}
V_21 = F_36 ( V_55 , F_21 , 0 , V_12 -> V_63 , V_2 ) ;
if ( V_21 < 0 )
goto V_62;
V_1 = V_2 ;
F_37 ( V_12 , V_2 ) ;
return 0 ;
V_62:
if ( V_2 -> V_29 )
F_38 ( V_2 -> V_29 ) ;
if ( V_2 -> V_5 )
F_39 ( V_2 -> V_5 ) ;
F_40 ( V_2 ) ;
return V_21 ;
}
static int T_5 F_41 ( struct V_51 * V_12 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
if ( V_2 != V_1 )
return - V_25 ;
F_11 ( V_1 -> V_29 ) ;
F_1 ( V_1 , V_33 , ( 1 << V_24 ) - 1 ) ;
F_1 ( V_1 , V_34 , ( 1 << V_24 ) - 1 ) ;
F_16 ( V_1 -> V_29 ) ;
V_1 = NULL ;
F_43 ( V_2 -> V_55 , V_2 ) ;
F_38 ( V_2 -> V_29 ) ;
F_39 ( V_2 -> V_5 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
