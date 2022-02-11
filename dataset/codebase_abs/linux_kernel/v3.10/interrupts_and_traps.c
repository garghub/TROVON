static unsigned long F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 & 0x0000FFFF ) | ( V_2 & 0xFFFF0000 ) ;
}
static int F_2 ( T_1 V_1 , T_1 V_2 )
{
return ( V_2 >> 8 ) & 0xF ;
}
static bool F_3 ( T_1 V_1 , T_1 V_2 )
{
return ( V_2 & 0x8000 ) ;
}
static void F_4 ( struct V_3 * V_4 , unsigned long * V_5 , T_1 V_6 )
{
* V_5 -= 4 ;
F_5 ( V_4 , * V_5 , T_1 , V_6 ) ;
}
static void F_6 ( struct V_3 * V_4 , T_1 V_1 , T_1 V_2 ,
bool V_7 )
{
unsigned long V_5 , V_8 ;
T_1 V_9 , V_10 , V_11 ;
unsigned long V_12 ;
if ( ( V_4 -> V_13 -> V_10 & 0x3 ) != V_14 ) {
V_12 = V_4 -> V_15 ;
V_10 = V_4 -> V_16 ;
V_8 = V_5 = F_7 ( V_4 , V_12 ) ;
F_4 ( V_4 , & V_5 , V_4 -> V_13 -> V_10 ) ;
F_4 ( V_4 , & V_5 , V_4 -> V_13 -> V_17 ) ;
} else {
V_12 = V_4 -> V_13 -> V_17 ;
V_10 = V_4 -> V_13 -> V_10 ;
V_8 = V_5 = F_7 ( V_4 , V_12 ) ;
}
V_9 = V_4 -> V_13 -> V_9 ;
if ( F_8 ( V_11 , & V_4 -> V_18 -> V_19 -> V_20 ) == 0
&& ! ( V_11 & V_21 ) )
V_9 &= ~ V_21 ;
F_4 ( V_4 , & V_5 , V_9 ) ;
F_4 ( V_4 , & V_5 , V_4 -> V_13 -> V_22 ) ;
F_4 ( V_4 , & V_5 , V_4 -> V_13 -> V_23 ) ;
if ( V_7 )
F_4 ( V_4 , & V_5 , V_4 -> V_13 -> V_24 ) ;
V_4 -> V_13 -> V_10 = V_10 ;
V_4 -> V_13 -> V_17 = V_12 + ( V_5 - V_8 ) ;
V_4 -> V_13 -> V_22 = ( V_25 | V_14 ) ;
V_4 -> V_13 -> V_23 = F_1 ( V_1 , V_2 ) ;
if ( F_2 ( V_1 , V_2 ) == 0xE )
if ( F_9 ( 0 , & V_4 -> V_18 -> V_19 -> V_20 ) )
F_10 ( V_4 , L_1 ) ;
}
unsigned int F_11 ( struct V_3 * V_4 , bool * V_26 )
{
unsigned int V_27 ;
F_12 ( V_28 , V_29 ) ;
if ( ! V_4 -> V_18 -> V_19 )
return V_29 ;
if ( F_13 ( & V_28 , V_4 -> V_18 -> V_19 -> V_30 ,
sizeof( V_28 ) ) )
return V_29 ;
F_14 ( V_28 , V_4 -> V_31 , V_28 , V_29 ) ;
V_27 = F_15 ( V_28 , V_29 ) ;
* V_26 = F_16 ( V_28 , V_29 , V_27 + 1 ) ;
return V_27 ;
}
void F_17 ( struct V_3 * V_4 , unsigned int V_27 , bool V_26 )
{
struct V_32 * V_33 ;
F_18 ( V_27 >= V_29 ) ;
if ( V_4 -> V_13 -> V_23 >= V_4 -> V_18 -> V_34 &&
( V_4 -> V_13 -> V_23 < V_4 -> V_18 -> V_35 ) )
return;
if ( V_4 -> V_36 ) {
if ( F_9 ( V_21 , & V_4 -> V_18 -> V_19 -> V_20 ) )
F_10 ( V_4 , L_2 ) ;
V_4 -> V_36 = 0 ;
} else {
T_1 V_20 ;
if ( F_8 ( V_20 , & V_4 -> V_18 -> V_19 -> V_20 ) )
V_20 = 0 ;
if ( ! V_20 ) {
F_9 ( V_21 ,
& V_4 -> V_18 -> V_19 -> V_37 ) ;
return;
}
}
V_33 = & V_4 -> V_38 . V_33 [ V_39 + V_27 ] ;
if ( F_3 ( V_33 -> V_40 , V_33 -> V_41 ) ) {
F_19 ( V_27 , V_4 -> V_31 ) ;
F_6 ( V_4 , V_33 -> V_40 , V_33 -> V_41 , false ) ;
}
F_20 ( V_4 ) ;
if ( ! V_26 )
F_9 ( 0 , & V_4 -> V_18 -> V_19 -> V_37 ) ;
}
void F_21 ( struct V_3 * V_4 , unsigned int V_27 )
{
F_22 ( V_27 , V_4 -> V_31 ) ;
if ( ! F_23 ( V_4 -> V_42 ) )
F_24 ( V_4 -> V_42 ) ;
}
static bool F_25 ( unsigned int V_43 )
{
return V_43 == V_44 || V_43 == V_45 ;
}
bool F_26 ( struct V_46 * V_18 )
{
T_1 V_47 ;
if ( F_8 ( V_47 , & V_18 -> V_19 -> V_48 ) )
return false ;
return F_25 ( V_47 ) ;
}
int F_27 ( void )
{
if ( V_45 != V_44 ) {
if ( F_28 ( V_45 , V_49 ) ||
F_29 ( V_45 ) ) {
F_30 ( V_50 L_3 ,
V_45 ) ;
return - V_51 ;
}
F_22 ( V_45 , V_49 ) ;
}
return 0 ;
}
void F_31 ( void )
{
if ( V_45 != V_44 )
F_19 ( V_45 , V_49 ) ;
}
static bool V_7 ( unsigned int V_52 )
{
return ( V_52 == 8 || ( V_52 >= 10 && V_52 <= 14 ) || V_52 == 17 ) ;
}
bool F_32 ( struct V_3 * V_4 , unsigned int V_43 )
{
if ( V_43 >= F_33 ( V_4 -> V_38 . V_33 ) )
return false ;
if ( ! F_3 ( V_4 -> V_38 . V_33 [ V_43 ] . V_40 , V_4 -> V_38 . V_33 [ V_43 ] . V_41 ) )
return false ;
F_6 ( V_4 , V_4 -> V_38 . V_33 [ V_43 ] . V_40 ,
V_4 -> V_38 . V_33 [ V_43 ] . V_41 , V_7 ( V_43 ) ) ;
return true ;
}
static bool F_34 ( unsigned int V_43 )
{
if ( V_43 >= V_39 && ! F_25 ( V_43 ) )
return false ;
return V_43 != 14 && V_43 != 13 && V_43 != 7 && V_43 != V_53 ;
}
void F_35 ( struct V_3 * V_4 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_18 -> V_55 ; V_54 ++ )
F_36 ( V_4 , V_4 -> V_15 - 1 - V_54 * V_56 ) ;
}
void F_37 ( struct V_3 * V_4 , T_1 V_57 , T_1 V_17 , unsigned int V_58 )
{
if ( ( V_57 & 0x3 ) != V_14 )
F_10 ( V_4 , L_4 , V_57 ) ;
if ( V_58 > 2 )
F_10 ( V_4 , L_5 , V_58 ) ;
V_4 -> V_16 = V_57 ;
V_4 -> V_15 = V_17 ;
V_4 -> V_18 -> V_55 = V_58 ;
F_35 ( V_4 ) ;
}
static void F_38 ( struct V_3 * V_4 , struct V_32 * V_52 ,
unsigned int V_43 , T_1 V_1 , T_1 V_2 )
{
T_2 type = F_2 ( V_1 , V_2 ) ;
if ( ! F_3 ( V_1 , V_2 ) ) {
V_52 -> V_40 = V_52 -> V_41 = 0 ;
return;
}
if ( type != 0xE && type != 0xF )
F_10 ( V_4 , L_6 , type ) ;
V_52 -> V_40 = ( ( V_25 | V_14 ) << 16 ) | ( V_1 & 0x0000FFFF ) ;
V_52 -> V_41 = ( V_2 & 0xFFFFEF00 ) ;
}
void F_39 ( struct V_3 * V_4 , unsigned int V_43 , T_1 V_1 , T_1 V_2 )
{
if ( V_43 == 2 || V_43 == 8 || V_43 == 15 || V_43 == V_53 )
return;
V_4 -> V_59 |= V_60 ;
if ( V_43 >= F_33 ( V_4 -> V_38 . V_33 ) )
F_10 ( V_4 , L_7 , V_43 ) ;
else
F_38 ( V_4 , & V_4 -> V_38 . V_33 [ V_43 ] , V_43 , V_1 , V_2 ) ;
}
static void F_40 ( struct V_32 * V_33 ,
int V_52 ,
const unsigned long V_61 ,
const struct V_32 * V_62 )
{
T_1 V_63 = 0x8e00 ;
if ( V_52 == V_53 )
V_63 |= ( V_14 << 13 ) ;
else if ( V_62 )
V_63 |= ( V_62 -> V_41 & 0x6000 ) ;
V_33 -> V_40 = ( V_64 << 16 ) | ( V_61 & 0x0000FFFF ) ;
V_33 -> V_41 = ( V_61 & 0xFFFF0000 ) | V_63 ;
}
void F_41 ( struct V_65 * V_66 ,
const unsigned long * V_67 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < F_33 ( V_66 -> V_68 ) ; V_54 ++ )
F_40 ( & V_66 -> V_68 [ V_54 ] , V_54 , V_67 [ V_54 ] , NULL ) ;
}
void F_42 ( const struct V_3 * V_4 , struct V_32 * V_33 ,
const unsigned long * V_67 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < F_33 ( V_4 -> V_38 . V_33 ) ; V_54 ++ ) {
const struct V_32 * V_69 = & V_4 -> V_38 . V_33 [ V_54 ] ;
if ( ! F_34 ( V_54 ) )
continue;
if ( F_2 ( V_69 -> V_40 , V_69 -> V_41 ) == 0xF )
V_33 [ V_54 ] = * V_69 ;
else
F_40 ( & V_33 [ V_54 ] , V_54 , V_67 [ V_54 ] , V_69 ) ;
}
}
void F_43 ( struct V_3 * V_4 , unsigned long V_70 )
{
T_3 V_71 ;
if ( F_44 ( V_70 == 0 ) ) {
F_45 ( & V_4 -> V_72 ) ;
return;
}
V_71 = F_46 ( F_47 () , V_70 ) ;
F_48 ( & V_4 -> V_72 , V_71 , V_73 ) ;
}
static enum V_74 F_49 ( struct V_75 * V_76 )
{
struct V_3 * V_4 = F_50 ( V_76 , struct V_3 , V_72 ) ;
F_21 ( V_4 , 0 ) ;
return V_77 ;
}
void F_51 ( struct V_3 * V_4 )
{
F_52 ( & V_4 -> V_72 , V_78 , V_73 ) ;
V_4 -> V_72 . V_79 = F_49 ;
}
