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
static void F_6 ( struct V_3 * V_4 , bool V_7 )
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
}
static void F_9 ( struct V_3 * V_4 , T_1 V_1 , T_1 V_2 )
{
if ( ( V_4 -> V_13 -> V_10 & 0x3 ) != V_14 )
V_4 -> V_13 -> V_10 = V_4 -> V_15 ;
V_4 -> V_13 -> V_22 = ( V_25 | V_14 ) ;
V_4 -> V_13 -> V_23 = F_1 ( V_1 , V_2 ) ;
V_4 -> V_13 -> V_9 &=
~ ( V_26 | V_27 | V_28 | V_29 ) ;
if ( F_2 ( V_1 , V_2 ) == 0xE )
if ( F_10 ( 0 , & V_4 -> V_18 -> V_19 -> V_20 ) )
F_11 ( V_4 , L_1 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
unsigned long V_30 = F_7 ( V_4 , V_4 -> V_13 -> V_17 ) ;
V_4 -> V_13 -> V_9 = F_13 ( V_4 , V_30 + 8 , T_1 ) ;
V_4 -> V_13 -> V_9 &=
~ ( V_26 | V_27 | V_28 | V_29 ) ;
}
unsigned int F_14 ( struct V_3 * V_4 , bool * V_31 )
{
unsigned int V_32 ;
F_15 ( V_33 , V_34 ) ;
if ( ! V_4 -> V_18 -> V_19 )
return V_34 ;
if ( F_16 ( & V_33 , V_4 -> V_18 -> V_19 -> V_35 ,
sizeof( V_33 ) ) )
return V_34 ;
F_17 ( V_33 , V_4 -> V_36 , V_33 , V_34 ) ;
V_32 = F_18 ( V_33 , V_34 ) ;
* V_31 = F_19 ( V_33 , V_34 , V_32 + 1 ) ;
return V_32 ;
}
void F_20 ( struct V_3 * V_4 , unsigned int V_32 , bool V_31 )
{
struct V_37 * V_38 ;
F_21 ( V_32 >= V_34 ) ;
if ( V_4 -> V_39 ) {
if ( F_10 ( V_21 , & V_4 -> V_18 -> V_19 -> V_20 ) )
F_11 ( V_4 , L_2 ) ;
V_4 -> V_39 = 0 ;
} else {
T_1 V_20 ;
if ( F_8 ( V_20 , & V_4 -> V_18 -> V_19 -> V_20 ) )
V_20 = 0 ;
if ( ! V_20 ) {
F_10 ( V_21 ,
& V_4 -> V_18 -> V_19 -> V_40 ) ;
return;
}
}
V_38 = & V_4 -> V_41 . V_38 [ V_42 + V_32 ] ;
if ( F_3 ( V_38 -> V_43 , V_38 -> V_44 ) ) {
F_22 ( V_32 , V_4 -> V_36 ) ;
if ( V_4 -> V_13 -> V_23 == V_4 -> V_18 -> V_45 ) {
F_12 ( V_4 ) ;
} else {
F_6 ( V_4 , false ) ;
}
F_9 ( V_4 , V_38 -> V_43 , V_38 -> V_44 ) ;
}
F_23 ( V_4 ) ;
if ( ! V_31 )
F_10 ( 0 , & V_4 -> V_18 -> V_19 -> V_40 ) ;
}
void F_24 ( struct V_3 * V_4 , unsigned int V_32 )
{
F_25 ( V_32 , V_4 -> V_36 ) ;
if ( ! F_26 ( V_4 -> V_46 ) )
F_27 ( V_4 -> V_46 ) ;
}
static bool F_28 ( unsigned int V_47 )
{
return V_47 == V_48 || V_47 == V_49 ;
}
bool F_29 ( struct V_50 * V_18 )
{
T_1 V_51 ;
if ( F_8 ( V_51 , & V_18 -> V_19 -> V_52 ) )
return false ;
return F_28 ( V_51 ) ;
}
int F_30 ( void )
{
if ( V_49 != V_48 ) {
if ( F_31 ( V_49 , V_53 ) ||
F_32 ( V_49 ) ) {
F_33 ( V_54 L_3 ,
V_49 ) ;
return - V_55 ;
}
F_25 ( V_49 , V_53 ) ;
}
return 0 ;
}
void F_34 ( void )
{
if ( V_49 != V_48 )
F_22 ( V_49 , V_53 ) ;
}
static bool V_7 ( unsigned int V_56 )
{
return ( V_56 == 8 || ( V_56 >= 10 && V_56 <= 14 ) || V_56 == 17 ) ;
}
bool F_35 ( struct V_3 * V_4 , unsigned int V_47 )
{
if ( V_47 >= F_36 ( V_4 -> V_41 . V_38 ) )
return false ;
if ( ! F_3 ( V_4 -> V_41 . V_38 [ V_47 ] . V_43 , V_4 -> V_41 . V_38 [ V_47 ] . V_44 ) )
return false ;
F_6 ( V_4 , V_7 ( V_47 ) ) ;
F_9 ( V_4 , V_4 -> V_41 . V_38 [ V_47 ] . V_43 ,
V_4 -> V_41 . V_38 [ V_47 ] . V_44 ) ;
return true ;
}
static bool F_37 ( unsigned int V_47 )
{
if ( V_47 >= V_42 && ! F_28 ( V_47 ) )
return false ;
return V_47 != 14 && V_47 != 13 && V_47 != 7 && V_47 != V_57 ;
}
void F_38 ( struct V_3 * V_4 )
{
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < V_4 -> V_18 -> V_59 ; V_58 ++ )
F_39 ( V_4 , V_4 -> V_15 - 1 - V_58 * V_60 ) ;
}
void F_40 ( struct V_3 * V_4 , T_1 V_61 , T_1 V_17 , unsigned int V_62 )
{
if ( ( V_61 & 0x3 ) != V_14 )
F_11 ( V_4 , L_4 , V_61 ) ;
if ( V_62 > 2 )
F_11 ( V_4 , L_5 , V_62 ) ;
V_4 -> V_16 = V_61 ;
V_4 -> V_15 = V_17 ;
V_4 -> V_18 -> V_59 = V_62 ;
F_38 ( V_4 ) ;
}
static void F_41 ( struct V_3 * V_4 , struct V_37 * V_56 ,
unsigned int V_47 , T_1 V_1 , T_1 V_2 )
{
T_2 type = F_2 ( V_1 , V_2 ) ;
if ( ! F_3 ( V_1 , V_2 ) ) {
V_56 -> V_43 = V_56 -> V_44 = 0 ;
return;
}
if ( type != 0xE && type != 0xF )
F_11 ( V_4 , L_6 , type ) ;
V_56 -> V_43 = ( ( V_25 | V_14 ) << 16 ) | ( V_1 & 0x0000FFFF ) ;
V_56 -> V_44 = ( V_2 & 0xFFFFEF00 ) ;
}
void F_42 ( struct V_3 * V_4 , unsigned int V_47 , T_1 V_1 , T_1 V_2 )
{
if ( V_47 == 2 || V_47 == 8 || V_47 == 15 || V_47 == V_57 )
return;
V_4 -> V_63 |= V_64 ;
if ( V_47 >= F_36 ( V_4 -> V_41 . V_38 ) )
F_11 ( V_4 , L_7 , V_47 ) ;
else
F_41 ( V_4 , & V_4 -> V_41 . V_38 [ V_47 ] , V_47 , V_1 , V_2 ) ;
}
static void F_43 ( struct V_37 * V_38 ,
int V_56 ,
const unsigned long V_65 ,
const struct V_37 * V_66 )
{
T_1 V_67 = 0x8e00 ;
if ( V_56 == V_57 )
V_67 |= ( V_14 << 13 ) ;
else if ( V_66 )
V_67 |= ( V_66 -> V_44 & 0x6000 ) ;
V_38 -> V_43 = ( V_68 << 16 ) | ( V_65 & 0x0000FFFF ) ;
V_38 -> V_44 = ( V_65 & 0xFFFF0000 ) | V_67 ;
}
void F_44 ( struct V_69 * V_70 ,
const unsigned long * V_71 )
{
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < F_36 ( V_70 -> V_72 ) ; V_58 ++ )
F_43 ( & V_70 -> V_72 [ V_58 ] , V_58 , V_71 [ V_58 ] , NULL ) ;
}
void F_45 ( const struct V_3 * V_4 , struct V_37 * V_38 ,
const unsigned long * V_71 )
{
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < F_36 ( V_4 -> V_41 . V_38 ) ; V_58 ++ ) {
const struct V_37 * V_73 = & V_4 -> V_41 . V_38 [ V_58 ] ;
if ( ! F_37 ( V_58 ) )
continue;
if ( F_2 ( V_73 -> V_43 , V_73 -> V_44 ) == 0xF )
V_38 [ V_58 ] = * V_73 ;
else
F_43 ( & V_38 [ V_58 ] , V_58 , V_71 [ V_58 ] , V_73 ) ;
}
}
void F_46 ( struct V_3 * V_4 , unsigned long V_74 )
{
T_3 V_75 ;
if ( F_47 ( V_74 == 0 ) ) {
F_48 ( & V_4 -> V_76 ) ;
return;
}
V_75 = F_49 ( F_50 () , V_74 ) ;
F_51 ( & V_4 -> V_76 , V_75 , V_77 ) ;
}
static enum V_78 F_52 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_53 ( V_80 , struct V_3 , V_76 ) ;
F_24 ( V_4 , 0 ) ;
return V_81 ;
}
void F_54 ( struct V_3 * V_4 )
{
F_55 ( & V_4 -> V_76 , V_82 , V_77 ) ;
V_4 -> V_76 . V_83 = F_52 ;
}
