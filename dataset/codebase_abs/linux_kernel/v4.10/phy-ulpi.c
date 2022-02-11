static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_4 |
V_5 ;
if ( V_2 -> V_3 & V_6 )
V_3 |= V_7 ;
if ( V_2 -> V_3 & V_8 )
V_3 &= ~ V_4 ;
if ( V_2 -> V_3 & V_9 )
V_3 &= ~ V_5 ;
if ( V_2 -> V_3 & V_10 )
V_3 |= V_11 ;
return F_2 ( V_2 , V_3 , V_12 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
if ( V_2 -> V_3 & V_13 )
V_3 |= V_14 ;
else if ( V_2 -> V_3 & V_15 )
V_3 |= V_16 ;
else if ( V_2 -> V_3 & V_17 )
V_3 |= V_18 ;
else
V_3 |= V_19 ;
if ( V_2 -> V_3 & V_20 )
V_3 |= V_21 ;
if ( V_2 -> V_3 & V_22 )
V_3 |= V_23 ;
else if ( V_2 -> V_3 & V_24 )
V_3 |= V_25 ;
else if ( V_2 -> V_3 & V_26 )
V_3 |= V_27 ;
else
V_3 |= V_28 ;
V_3 |= V_29 ;
return F_2 ( V_2 , V_3 , V_30 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
if ( V_2 -> V_3 & V_31 )
V_3 |= V_32 ;
if ( V_2 -> V_3 & V_33 )
V_3 |= V_34 ;
if ( V_2 -> V_3 & V_35 )
V_3 |= V_36 ;
if ( V_2 -> V_3 & V_37 )
V_3 |= V_38 ;
return F_2 ( V_2 , V_3 , V_39 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_4 ( V_2 ) ;
if ( V_40 )
return V_40 ;
return F_3 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_40 , V_41 ;
unsigned int V_42 = 0x55 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
V_40 = F_2 ( V_2 , V_42 , V_43 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_7 ( V_2 , V_43 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_40 != V_42 ) {
F_8 ( L_1 ) ;
return - V_44 ;
}
V_42 = V_42 << 1 ;
}
F_9 ( L_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_41 , V_45 , V_46 , V_40 ;
T_1 V_47 = 0 ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
V_40 = F_7 ( V_2 , V_48 - V_41 ) ;
if ( V_40 < 0 )
return V_40 ;
V_47 = ( V_47 << 8 ) | V_40 ;
}
V_45 = V_47 & 0xffff ;
V_46 = V_47 >> 16 ;
F_9 ( L_3 , V_45 , V_46 ) ;
for ( V_41 = 0 ; V_41 < F_11 ( V_49 ) ; V_41 ++ ) {
if ( V_49 [ V_41 ] . V_50 == F_12 ( V_45 , V_46 ) ) {
F_9 ( L_4 ,
V_49 [ V_41 ] . V_51 ) ;
break;
}
}
V_40 = F_6 ( V_2 ) ;
if ( V_40 )
return V_40 ;
return F_5 ( V_2 ) ;
}
static int F_13 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
struct V_1 * V_2 = V_53 -> V_1 ;
unsigned int V_3 = F_7 ( V_2 , V_39 ) ;
if ( ! V_55 ) {
V_53 -> V_55 = NULL ;
return 0 ;
}
V_53 -> V_55 = V_55 ;
V_3 &= ~ ( V_56 |
V_57 |
V_58 ) ;
if ( V_2 -> V_3 & V_59 )
V_3 |= V_56 ;
else if ( V_2 -> V_3 & V_60 )
V_3 |= V_57 ;
else if ( V_2 -> V_3 & V_61 )
V_3 |= V_58 ;
return F_2 ( V_2 , V_3 , V_39 ) ;
}
static int F_14 ( struct V_52 * V_53 , bool V_62 )
{
struct V_1 * V_2 = V_53 -> V_1 ;
unsigned int V_3 = F_7 ( V_2 , V_12 ) ;
V_3 &= ~ ( V_63 | V_64 ) ;
if ( V_62 ) {
if ( V_2 -> V_3 & V_65 )
V_3 |= V_63 ;
if ( V_2 -> V_3 & V_66 )
V_3 |= V_64 ;
}
return F_2 ( V_2 , V_3 , V_12 ) ;
}
struct V_1 *
F_15 ( struct V_67 * V_68 ,
unsigned int V_3 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return NULL ;
V_53 = F_16 ( sizeof( * V_53 ) , V_69 ) ;
if ( ! V_53 ) {
F_17 ( V_2 ) ;
return NULL ;
}
V_2 -> V_70 = L_5 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_71 = V_68 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_72 = F_10 ;
V_53 -> V_1 = V_2 ;
V_53 -> V_73 = F_13 ;
V_53 -> V_74 = F_14 ;
return V_2 ;
}
