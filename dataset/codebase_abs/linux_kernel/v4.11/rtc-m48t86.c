static unsigned char F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 ;
F_3 ( V_3 , V_5 -> V_7 ) ;
V_6 = F_4 ( V_5 -> V_8 ) ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned char V_6 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_3 , V_5 -> V_7 ) ;
F_3 ( V_6 , V_5 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned char V_11 ;
V_11 = F_1 ( V_2 , V_12 ) ;
if ( V_11 & V_13 ) {
V_10 -> V_14 = F_1 ( V_2 , V_15 ) ;
V_10 -> V_16 = F_1 ( V_2 , V_17 ) ;
V_10 -> V_18 = F_1 ( V_2 , V_19 ) & 0x3f ;
V_10 -> V_20 = F_1 ( V_2 , V_21 ) ;
V_10 -> V_22 = F_1 ( V_2 , V_23 ) - 1 ;
V_10 -> V_24 = F_1 ( V_2 , V_25 ) + 100 ;
V_10 -> V_26 = F_1 ( V_2 , V_27 ) ;
} else {
V_10 -> V_14 = F_7 ( F_1 ( V_2 , V_15 ) ) ;
V_10 -> V_16 = F_7 ( F_1 ( V_2 , V_17 ) ) ;
V_10 -> V_18 = F_7 ( F_1 ( V_2 , V_19 ) &
0x3f ) ;
V_10 -> V_20 = F_7 ( F_1 ( V_2 , V_21 ) ) ;
V_10 -> V_22 = F_7 ( F_1 ( V_2 , V_23 ) ) - 1 ;
V_10 -> V_24 = F_7 ( F_1 ( V_2 , V_25 ) ) + 100 ;
V_10 -> V_26 = F_7 ( F_1 ( V_2 , V_27 ) ) ;
}
if ( ! ( V_11 & V_28 ) )
if ( F_1 ( V_2 , V_19 ) & 0x80 )
V_10 -> V_18 += 12 ;
return F_8 ( V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned char V_11 ;
V_11 = F_1 ( V_2 , V_12 ) ;
V_11 |= V_29 | V_28 ;
F_5 ( V_2 , V_11 , V_12 ) ;
if ( V_11 & V_13 ) {
F_5 ( V_2 , V_10 -> V_14 , V_15 ) ;
F_5 ( V_2 , V_10 -> V_16 , V_17 ) ;
F_5 ( V_2 , V_10 -> V_18 , V_19 ) ;
F_5 ( V_2 , V_10 -> V_20 , V_21 ) ;
F_5 ( V_2 , V_10 -> V_22 + 1 , V_23 ) ;
F_5 ( V_2 , V_10 -> V_24 % 100 , V_25 ) ;
F_5 ( V_2 , V_10 -> V_26 , V_27 ) ;
} else {
F_5 ( V_2 , F_10 ( V_10 -> V_14 ) , V_15 ) ;
F_5 ( V_2 , F_10 ( V_10 -> V_16 ) , V_17 ) ;
F_5 ( V_2 , F_10 ( V_10 -> V_18 ) , V_19 ) ;
F_5 ( V_2 , F_10 ( V_10 -> V_20 ) , V_21 ) ;
F_5 ( V_2 , F_10 ( V_10 -> V_22 + 1 ) , V_23 ) ;
F_5 ( V_2 , F_10 ( V_10 -> V_24 % 100 ) , V_25 ) ;
F_5 ( V_2 , F_10 ( V_10 -> V_26 ) , V_27 ) ;
}
V_11 &= ~ V_29 ;
F_5 ( V_2 , V_11 , V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
unsigned char V_11 ;
V_11 = F_1 ( V_2 , V_12 ) ;
F_12 ( V_31 , L_1 ,
( V_11 & V_13 ) ? L_2 : L_3 ) ;
V_11 = F_1 ( V_2 , V_32 ) ;
F_12 ( V_31 , L_4 ,
( V_11 & V_33 ) ? L_5 : L_6 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_39 ,
char * V_40 , T_2 V_41 , T_3 V_42 )
{
struct V_1 * V_2 = F_14 ( V_37 ) ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
V_40 [ V_43 ] = F_1 ( V_2 , F_15 ( V_41 + V_43 ) ) ;
return V_42 ;
}
static T_1 F_16 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_39 ,
char * V_40 , T_2 V_41 , T_3 V_42 )
{
struct V_1 * V_2 = F_14 ( V_37 ) ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
F_5 ( V_2 , V_40 [ V_43 ] , F_15 ( V_41 + V_43 ) ) ;
return V_42 ;
}
static bool F_17 ( struct V_44 * V_45 )
{
unsigned int V_46 = F_15 ( V_47 - 2 ) ;
unsigned int V_48 = F_15 ( V_47 - 1 ) ;
unsigned char V_49 , V_50 ;
V_49 = F_1 ( & V_45 -> V_2 , V_46 ) ;
V_50 = F_1 ( & V_45 -> V_2 , V_48 ) ;
F_5 ( & V_45 -> V_2 , 0x00 , V_46 ) ;
F_5 ( & V_45 -> V_2 , 0x55 , V_48 ) ;
if ( F_1 ( & V_45 -> V_2 , V_48 ) == 0x55 ) {
F_5 ( & V_45 -> V_2 , 0xaa , V_48 ) ;
if ( F_1 ( & V_45 -> V_2 , V_48 ) == 0xaa &&
F_1 ( & V_45 -> V_2 , V_46 ) == 0x00 ) {
F_5 ( & V_45 -> V_2 , V_49 , V_46 ) ;
F_5 ( & V_45 -> V_2 , V_50 , V_48 ) ;
return true ;
}
}
return false ;
}
static int F_18 ( struct V_44 * V_45 )
{
struct V_4 * V_5 ;
struct V_51 * V_52 ;
unsigned char V_11 ;
V_5 = F_19 ( & V_45 -> V_2 , sizeof( * V_5 ) , V_53 ) ;
if ( ! V_5 )
return - V_54 ;
V_52 = F_20 ( V_45 , V_55 , 0 ) ;
if ( ! V_52 )
return - V_56 ;
V_5 -> V_7 = F_21 ( & V_45 -> V_2 , V_52 ) ;
if ( F_22 ( V_5 -> V_7 ) )
return F_23 ( V_5 -> V_7 ) ;
V_52 = F_20 ( V_45 , V_55 , 1 ) ;
if ( ! V_52 )
return - V_56 ;
V_5 -> V_8 = F_21 ( & V_45 -> V_2 , V_52 ) ;
if ( F_22 ( V_5 -> V_8 ) )
return F_23 ( V_5 -> V_8 ) ;
F_24 ( & V_45 -> V_2 , V_5 ) ;
if ( ! F_17 ( V_45 ) ) {
F_25 ( & V_45 -> V_2 , L_7 ) ;
return - V_56 ;
}
V_5 -> V_57 = F_26 ( & V_45 -> V_2 , L_8 ,
& V_58 , V_59 ) ;
if ( F_22 ( V_5 -> V_57 ) )
return F_23 ( V_5 -> V_57 ) ;
V_11 = F_1 ( & V_45 -> V_2 , V_32 ) ;
F_25 ( & V_45 -> V_2 , L_9 ,
( V_11 & V_33 ) ? L_5 : L_6 ) ;
if ( F_27 ( & V_45 -> V_2 , & V_60 ) )
F_28 ( & V_45 -> V_2 , L_10 ) ;
return 0 ;
}
static int F_29 ( struct V_44 * V_45 )
{
F_30 ( & V_45 -> V_2 , & V_60 ) ;
return 0 ;
}
