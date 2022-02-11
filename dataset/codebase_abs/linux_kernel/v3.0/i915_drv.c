void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_8 << 8 , NULL ) ;
if ( V_7 ) {
if ( V_7 -> V_9 == V_10 ) {
int V_11 ;
V_11 = V_7 -> V_12 & V_13 ;
if ( V_11 == V_14 ) {
V_4 -> V_15 = V_16 ;
F_3 ( L_1 ) ;
} else if ( V_11 == V_17 ) {
V_4 -> V_15 = V_18 ;
F_3 ( L_2 ) ;
} else if ( V_11 == V_19 ) {
V_4 -> V_15 = V_18 ;
F_3 ( L_3 ) ;
}
}
F_4 ( V_7 ) ;
}
}
static void F_5 ( struct V_3 * V_4 )
{
int V_20 ;
V_20 = 0 ;
while ( V_20 ++ < 50 && ( F_6 ( V_21 ) & 1 ) )
F_7 ( 10 ) ;
F_8 ( V_22 , 1 ) ;
F_9 ( V_22 ) ;
V_20 = 0 ;
while ( V_20 ++ < 50 && ( F_6 ( V_21 ) & 1 ) == 0 )
F_7 ( 10 ) ;
}
void F_10 ( struct V_3 * V_4 )
{
F_11 ( ! F_12 ( & V_4 -> V_2 -> V_23 ) ) ;
if ( F_13 ( 1 , & V_4 -> V_24 ) == 1 )
F_5 ( V_4 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_8 ( V_22 , 0 ) ;
F_9 ( V_22 ) ;
}
void F_15 ( struct V_3 * V_4 )
{
F_11 ( ! F_12 ( & V_4 -> V_2 -> V_23 ) ) ;
if ( F_16 ( & V_4 -> V_24 ) )
F_14 ( V_4 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
int V_25 = 500 ;
T_1 V_26 = F_6 ( V_27 ) ;
while ( V_26 < 20 && V_25 -- ) {
F_7 ( 10 ) ;
V_26 = F_6 ( V_27 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_28 ) ;
if ( F_21 ( V_2 , V_29 ) ) {
int error = F_22 ( V_2 ) ;
if ( error ) {
F_23 ( & V_2 -> V_28 -> V_2 ,
L_4 ) ;
return error ;
}
F_24 ( V_2 ) ;
}
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
V_4 -> V_30 = 0 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , T_2 V_31 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_28 ( L_5 , V_2 ) ;
F_28 ( L_6 ) ;
return - V_32 ;
}
if ( V_31 . V_33 == V_34 )
return 0 ;
if ( V_2 -> V_35 == V_36 )
return 0 ;
error = F_18 ( V_2 ) ;
if ( error )
return error ;
if ( V_31 . V_33 == V_37 ) {
F_29 ( V_2 -> V_28 ) ;
F_30 ( V_2 -> V_28 , V_38 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_21 ( V_2 , V_29 ) ) {
F_32 ( & V_2 -> V_23 ) ;
F_33 ( V_2 ) ;
F_34 ( & V_2 -> V_23 ) ;
}
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( F_21 ( V_2 , V_29 ) ) {
F_32 ( & V_2 -> V_23 ) ;
V_4 -> V_39 . V_40 = 0 ;
error = F_37 ( V_2 ) ;
F_34 ( & V_2 -> V_23 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( F_41 ( V_2 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
V_4 -> V_30 = 0 ;
return error ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_41 ;
if ( V_2 -> V_35 == V_36 )
return 0 ;
if ( F_45 ( V_2 -> V_28 ) )
return - V_42 ;
F_46 ( V_2 -> V_28 ) ;
V_41 = F_31 ( V_2 ) ;
if ( V_41 )
return V_41 ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , T_3 V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_49 ( V_2 ) )
return - V_32 ;
F_50 ( V_44 , F_51 ( V_44 ) | V_45 ) ;
F_9 ( V_44 ) ;
if ( F_52 ( V_2 ) || F_53 ( V_2 ) ) {
F_50 ( V_46 ,
V_47 |
V_48 |
V_49 ) ;
F_9 ( V_46 ) ;
F_54 ( 1 ) ;
F_50 ( V_46 , 0 ) ;
F_9 ( V_46 ) ;
}
F_54 ( 1 ) ;
F_50 ( V_44 , F_51 ( V_44 ) & ~ V_45 ) ;
F_9 ( V_44 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_3 V_50 ;
F_56 ( V_2 -> V_28 , V_51 , & V_50 ) ;
return V_50 & 0x1 ;
}
static int F_57 ( struct V_1 * V_2 , T_3 V_43 )
{
T_3 V_50 ;
F_56 ( V_2 -> V_28 , V_51 , & V_50 ) ;
F_58 ( V_2 -> V_28 , V_51 , V_50 | V_43 | 0x1 ) ;
return F_59 ( F_55 ( V_2 ) , 500 ) ;
}
static int F_60 ( struct V_1 * V_2 , T_3 V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_50 = F_51 ( V_52 + V_53 ) ;
F_50 ( V_52 + V_53 , V_50 | V_43 | 0x1 ) ;
return F_59 ( F_51 ( V_52 + V_53 ) & 0x1 , 500 ) ;
}
static int F_61 ( struct V_1 * V_2 , T_3 V_43 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_50 ( V_54 , V_55 ) ;
return F_59 ( ( F_51 ( V_54 ) & V_55 ) == 0 , 500 ) ;
}
int F_62 ( struct V_1 * V_2 , T_3 V_43 )
{
T_4 * V_4 = V_2 -> V_5 ;
bool V_56 = true ;
int V_41 ;
if ( ! V_57 )
return 0 ;
if ( ! F_63 ( & V_2 -> V_23 ) )
return - V_58 ;
F_64 ( V_2 ) ;
V_41 = - V_32 ;
if ( F_65 () - V_4 -> V_59 < 5 ) {
F_28 ( L_7 ) ;
} else switch ( F_66 ( V_2 ) -> V_60 ) {
case 7 :
case 6 :
V_41 = F_61 ( V_2 , V_43 ) ;
if ( F_67 ( & V_4 -> V_24 ) )
F_5 ( V_4 ) ;
break;
case 5 :
V_41 = F_60 ( V_2 , V_43 ) ;
break;
case 4 :
V_41 = F_57 ( V_2 , V_43 ) ;
break;
case 2 :
V_41 = F_48 ( V_2 , V_43 ) ;
break;
}
V_4 -> V_59 = F_65 () ;
if ( V_41 ) {
F_28 ( L_8 ) ;
F_34 ( & V_2 -> V_23 ) ;
return V_41 ;
}
if ( F_21 ( V_2 , V_29 ) ||
! V_4 -> V_39 . V_40 ) {
V_4 -> V_39 . V_40 = 0 ;
V_4 -> V_61 [ V_62 ] . F_68 ( & V_4 -> V_61 [ V_62 ] ) ;
if ( F_69 ( V_2 ) )
V_4 -> V_61 [ V_63 ] . F_68 ( & V_4 -> V_61 [ V_63 ] ) ;
if ( F_70 ( V_2 ) )
V_4 -> V_61 [ V_64 ] . F_68 ( & V_4 -> V_61 [ V_64 ] ) ;
F_34 ( & V_2 -> V_23 ) ;
F_24 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_32 ( & V_2 -> V_23 ) ;
}
F_34 ( & V_2 -> V_23 ) ;
if ( V_56 ) {
F_32 ( & V_2 -> V_65 . V_66 ) ;
F_40 ( V_2 ) ;
F_34 ( & V_2 -> V_65 . V_66 ) ;
}
return 0 ;
}
static int T_5
F_71 ( struct V_6 * V_28 , const struct V_67 * V_68 )
{
if ( F_72 ( V_28 -> V_69 ) )
return - V_32 ;
return F_73 ( V_28 , V_68 , & V_70 ) ;
}
static void
F_74 ( struct V_6 * V_28 )
{
struct V_1 * V_2 = F_75 ( V_28 ) ;
F_76 ( V_2 ) ;
}
static int F_77 ( struct V_12 * V_2 )
{
struct V_6 * V_28 = F_78 ( V_2 ) ;
struct V_1 * V_71 = F_75 ( V_28 ) ;
int error ;
if ( ! V_71 || ! V_71 -> V_5 ) {
F_23 ( V_2 , L_6 ) ;
return - V_32 ;
}
if ( V_71 -> V_35 == V_36 )
return 0 ;
error = F_18 ( V_71 ) ;
if ( error )
return error ;
F_29 ( V_28 ) ;
F_30 ( V_28 , V_38 ) ;
return 0 ;
}
static int F_79 ( struct V_12 * V_2 )
{
struct V_6 * V_28 = F_78 ( V_2 ) ;
struct V_1 * V_71 = F_75 ( V_28 ) ;
return F_44 ( V_71 ) ;
}
static int F_80 ( struct V_12 * V_2 )
{
struct V_6 * V_28 = F_78 ( V_2 ) ;
struct V_1 * V_71 = F_75 ( V_28 ) ;
if ( ! V_71 || ! V_71 -> V_5 ) {
F_23 ( V_2 , L_6 ) ;
return - V_32 ;
}
return F_18 ( V_71 ) ;
}
static int F_81 ( struct V_12 * V_2 )
{
struct V_6 * V_28 = F_78 ( V_2 ) ;
struct V_1 * V_71 = F_75 ( V_28 ) ;
return F_31 ( V_71 ) ;
}
static int F_82 ( struct V_12 * V_2 )
{
struct V_6 * V_28 = F_78 ( V_2 ) ;
struct V_1 * V_71 = F_75 ( V_28 ) ;
return F_18 ( V_71 ) ;
}
static int T_6 F_83 ( void )
{
if ( ! V_72 ) {
F_28 ( L_9 ) ;
return - V_32 ;
}
V_70 . V_73 = V_74 ;
#if F_84 ( V_75 )
if ( V_76 != 0 )
V_70 . V_77 |= V_29 ;
#endif
if ( V_76 == 1 )
V_70 . V_77 |= V_29 ;
#ifdef F_85
if ( F_86 () && V_76 == - 1 )
V_70 . V_77 &= ~ V_29 ;
#endif
if ( ! ( V_70 . V_77 & V_29 ) )
V_70 . V_78 = NULL ;
return F_87 ( & V_70 , & V_79 ) ;
}
static void T_7 F_88 ( void )
{
F_89 ( & V_70 , & V_79 ) ;
}
