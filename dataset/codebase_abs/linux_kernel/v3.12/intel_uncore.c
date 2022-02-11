static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_2 ( V_2 -> V_4 ) )
V_3 = V_5 ;
else
V_3 = V_6 ;
if ( F_3 ( ( F_4 ( V_2 , V_7 ) & V_3 ) == 0 , 500 ) )
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_8 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( ( F_4 ( V_2 , V_10 ) & 1 ) == 0 ,
V_11 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_8 , 1 ) ;
F_8 ( V_2 , V_9 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_10 ) & 1 ) ,
V_11 ) )
F_5 ( L_3 ) ;
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_12 , F_12 ( 0xffff ) ) ;
F_8 ( V_2 , V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_13 ;
if ( F_2 ( V_2 -> V_4 ) )
V_13 = V_14 ;
else
V_13 = V_15 ;
if ( F_10 ( ( F_4 ( V_2 , V_13 ) & V_16 ) == 0 ,
V_11 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_12 ,
F_14 ( V_16 ) ) ;
F_8 ( V_2 , V_9 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_13 ) & V_16 ) ,
V_11 ) )
F_5 ( L_3 ) ;
F_1 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_17 ;
V_17 = F_4 ( V_2 , V_18 ) ;
if ( F_16 ( V_17 & V_19 ,
L_4 , V_17 ) )
F_7 ( V_2 , V_18 , V_19 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_8 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
F_15 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_12 ,
F_12 ( V_16 ) ) ;
F_8 ( V_2 , V_9 ) ;
F_15 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
if ( V_2 -> V_21 . V_22 < V_23 ) {
int V_24 = 500 ;
T_1 V_25 = F_4 ( V_2 , V_26 ) ;
while ( V_25 <= V_23 && V_24 -- ) {
F_20 ( 10 ) ;
V_25 = F_4 ( V_2 , V_26 ) ;
}
if ( F_21 ( V_24 < 0 && V_25 <= V_23 ) )
++ V_20 ;
V_2 -> V_21 . V_22 = V_25 ;
}
V_2 -> V_21 . V_22 -- ;
return V_20 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_27 ,
F_12 ( 0xffff ) ) ;
F_8 ( V_2 , V_28 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( F_10 ( ( F_4 ( V_2 , V_28 ) & V_16 ) == 0 ,
V_11 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_27 ,
F_14 ( V_16 ) ) ;
F_7 ( V_2 , V_29 ,
F_14 ( V_16 ) ) ;
if ( F_10 ( ( F_4 ( V_2 , V_28 ) & V_16 ) ,
V_11 ) )
F_5 ( L_5 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_30 ) &
V_16 ) ,
V_11 ) )
F_5 ( L_6 ) ;
F_1 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_27 ,
F_12 ( V_16 ) ) ;
F_7 ( V_2 , V_29 ,
F_12 ( V_16 ) ) ;
F_15 ( V_2 ) ;
}
void F_25 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
if ( F_26 ( V_4 ) )
F_7 ( V_2 , V_33 , V_34 ) ;
}
void F_27 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
if ( F_28 ( V_4 ) ) {
V_2 -> V_21 . V_35 . V_36 = F_23 ;
V_2 -> V_21 . V_35 . V_37 = F_24 ;
} else if ( F_2 ( V_4 ) ) {
V_2 -> V_21 . V_35 . V_36 = F_13 ;
V_2 -> V_21 . V_35 . V_37 = F_18 ;
} else if ( F_29 ( V_4 ) ) {
T_1 V_38 ;
F_30 ( & V_4 -> V_39 ) ;
F_13 ( V_2 ) ;
V_38 = F_4 ( V_2 , V_9 ) ;
F_18 ( V_2 ) ;
F_31 ( & V_4 -> V_39 ) ;
if ( V_38 & V_40 ) {
V_2 -> V_21 . V_35 . V_36 =
F_13 ;
V_2 -> V_21 . V_35 . V_37 =
F_18 ;
} else {
F_32 ( L_7 ) ;
F_32 ( L_8 ) ;
V_2 -> V_21 . V_35 . V_36 =
F_9 ;
V_2 -> V_21 . V_35 . V_37 =
F_17 ;
}
} else if ( F_33 ( V_4 ) ) {
V_2 -> V_21 . V_35 . V_36 =
F_9 ;
V_2 -> V_21 . V_35 . V_37 =
F_17 ;
}
}
static void F_34 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
if ( F_28 ( V_4 ) ) {
F_22 ( V_2 ) ;
} else if ( F_35 ( V_4 ) -> V_41 >= 6 ) {
F_6 ( V_2 ) ;
if ( F_29 ( V_4 ) || F_2 ( V_4 ) )
F_11 ( V_2 ) ;
}
}
void F_36 ( struct V_31 * V_4 )
{
F_34 ( V_4 ) ;
F_37 ( V_4 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
F_39 ( & V_2 -> V_21 . V_43 , V_42 ) ;
if ( V_2 -> V_21 . V_44 ++ == 0 )
V_2 -> V_21 . V_35 . V_36 ( V_2 ) ;
F_40 ( & V_2 -> V_21 . V_43 , V_42 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
F_39 ( & V_2 -> V_21 . V_43 , V_42 ) ;
if ( -- V_2 -> V_21 . V_44 == 0 )
V_2 -> V_21 . V_35 . V_37 ( V_2 ) ;
F_40 ( & V_2 -> V_21 . V_43 , V_42 ) ;
}
static void
F_42 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_45 , 0 ) ;
}
static void
F_43 ( struct V_1 * V_2 , T_1 V_46 )
{
if ( F_26 ( V_2 -> V_4 ) &&
( F_4 ( V_2 , V_33 ) & V_34 ) ) {
F_5 ( L_9 ,
V_46 ) ;
F_7 ( V_2 , V_33 , V_34 ) ;
}
}
static void
F_44 ( struct V_1 * V_2 , T_1 V_46 )
{
if ( F_26 ( V_2 -> V_4 ) &&
( F_4 ( V_2 , V_33 ) & V_34 ) ) {
F_5 ( L_10 , V_46 ) ;
F_7 ( V_2 , V_33 , V_34 ) ;
}
}
int F_45 ( struct V_31 * V_4 ,
void * V_47 , struct V_48 * V_49 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
struct V_50 * V_46 = V_47 ;
struct V_51 const * V_52 = V_53 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < F_46 ( V_53 ) ; V_54 ++ , V_52 ++ ) {
if ( V_52 -> V_55 == V_46 -> V_55 &&
( 1 << F_35 ( V_4 ) -> V_41 & V_52 -> V_56 ) )
break;
}
if ( V_54 == F_46 ( V_53 ) )
return - V_57 ;
switch ( V_52 -> V_58 ) {
case 8 :
V_46 -> V_59 = F_47 ( V_46 -> V_55 ) ;
break;
case 4 :
V_46 -> V_59 = F_48 ( V_46 -> V_55 ) ;
break;
case 2 :
V_46 -> V_59 = F_49 ( V_46 -> V_55 ) ;
break;
case 1 :
V_46 -> V_59 = F_50 ( V_46 -> V_55 ) ;
break;
default:
F_21 ( 1 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_51 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
if ( F_52 ( V_4 ) )
return - V_60 ;
F_53 ( V_61 , F_48 ( V_61 ) | V_62 ) ;
F_54 ( V_61 ) ;
if ( F_55 ( V_4 ) || F_56 ( V_4 ) ) {
F_53 ( V_63 ,
V_64 |
V_65 |
V_66 ) ;
F_54 ( V_63 ) ;
F_57 ( 1 ) ;
F_53 ( V_63 , 0 ) ;
F_54 ( V_63 ) ;
}
F_57 ( 1 ) ;
F_53 ( V_61 , F_48 ( V_61 ) & ~ V_62 ) ;
F_54 ( V_61 ) ;
return 0 ;
}
static int F_58 ( struct V_31 * V_4 )
{
T_2 V_67 ;
F_59 ( V_4 -> V_68 , V_69 , & V_67 ) ;
return ( V_67 & V_70 ) == 0 ;
}
static int F_60 ( struct V_31 * V_4 )
{
int V_20 ;
F_61 ( V_4 -> V_68 , V_69 ,
V_71 | V_70 ) ;
V_20 = F_62 ( F_58 ( V_4 ) , 500 ) ;
if ( V_20 )
return V_20 ;
F_61 ( V_4 -> V_68 , V_69 ,
V_72 | V_70 ) ;
V_20 = F_62 ( F_58 ( V_4 ) , 500 ) ;
if ( V_20 )
return V_20 ;
F_61 ( V_4 -> V_68 , V_69 , 0 ) ;
return 0 ;
}
static int F_63 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
T_1 V_67 ;
int V_20 ;
V_67 = F_48 ( V_73 + V_74 ) ;
V_67 &= ~ V_75 ;
F_53 ( V_73 + V_74 ,
V_67 | V_71 | V_70 ) ;
V_20 = F_62 ( F_48 ( V_73 + V_74 ) & 0x1 , 500 ) ;
if ( V_20 )
return V_20 ;
V_67 = F_48 ( V_73 + V_74 ) ;
V_67 &= ~ V_75 ;
F_53 ( V_73 + V_74 ,
V_67 | V_72 | V_70 ) ;
return F_62 ( F_48 ( V_73 + V_74 ) & 0x1 , 500 ) ;
}
static int F_64 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
int V_20 ;
unsigned long V_42 ;
F_39 ( & V_2 -> V_21 . V_43 , V_42 ) ;
F_7 ( V_2 , V_76 , V_77 ) ;
V_20 = F_62 ( ( F_4 ( V_2 , V_76 ) & V_77 ) == 0 , 500 ) ;
F_34 ( V_4 ) ;
if ( V_2 -> V_21 . V_44 )
V_2 -> V_21 . V_35 . V_36 ( V_2 ) ;
else
V_2 -> V_21 . V_35 . V_37 ( V_2 ) ;
V_2 -> V_21 . V_22 = F_4 ( V_2 , V_26 ) ;
F_40 ( & V_2 -> V_21 . V_43 , V_42 ) ;
return V_20 ;
}
int F_65 ( struct V_31 * V_4 )
{
switch ( F_35 ( V_4 ) -> V_41 ) {
case 7 :
case 6 : return F_64 ( V_4 ) ;
case 5 : return F_63 ( V_4 ) ;
case 4 : return F_60 ( V_4 ) ;
case 2 : return F_51 ( V_4 ) ;
default: return - V_60 ;
}
}
void F_66 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
if ( F_26 ( V_4 ) )
F_7 ( V_2 , V_33 , V_34 ) ;
}
void F_67 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_32 ;
if ( F_26 ( V_4 ) &&
( F_4 ( V_2 , V_33 ) & V_34 ) ) {
F_5 ( L_11 ) ;
F_7 ( V_2 , V_33 , V_34 ) ;
}
}
