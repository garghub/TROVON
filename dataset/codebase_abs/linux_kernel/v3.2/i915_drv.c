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
void F_5 ( struct V_3 * V_4 )
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
int V_20 ;
V_20 = 0 ;
while ( V_20 ++ < 50 && ( F_6 ( V_23 ) & 1 ) )
F_7 ( 10 ) ;
F_8 ( V_24 , ( 1 << 16 ) | 1 ) ;
F_9 ( V_24 ) ;
V_20 = 0 ;
while ( V_20 ++ < 50 && ( F_6 ( V_23 ) & 1 ) == 0 )
F_7 ( 10 ) ;
}
void F_11 ( struct V_3 * V_4 )
{
F_12 ( ! F_13 ( & V_4 -> V_2 -> V_25 ) ) ;
if ( F_14 ( 1 , & V_4 -> V_26 ) == 1 )
V_4 -> V_27 . V_28 ( V_4 ) ;
}
void F_15 ( struct V_3 * V_4 )
{
F_8 ( V_22 , 0 ) ;
F_9 ( V_22 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
F_8 ( V_24 , ( 1 << 16 ) | 0 ) ;
F_9 ( V_24 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_12 ( ! F_13 ( & V_4 -> V_2 -> V_25 ) ) ;
if ( F_18 ( & V_4 -> V_26 ) )
V_4 -> V_27 . V_29 ( V_4 ) ;
}
void F_19 ( struct V_3 * V_4 )
{
if ( V_4 -> V_30 < V_31 ) {
int V_32 = 500 ;
T_1 V_33 = F_6 ( V_34 ) ;
while ( V_33 <= V_31 && V_32 -- ) {
F_7 ( 10 ) ;
V_33 = F_6 ( V_34 ) ;
}
F_12 ( V_32 < 0 && V_33 <= V_31 ) ;
V_4 -> V_30 = V_33 ;
}
V_4 -> V_30 -- ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_35 ) ;
if ( F_23 ( V_2 , V_36 ) ) {
int error = F_24 ( V_2 ) ;
if ( error ) {
F_25 ( & V_2 -> V_35 -> V_2 ,
L_4 ) ;
return error ;
}
F_26 ( V_2 ) ;
}
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
V_4 -> V_37 = 0 ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , T_2 V_38 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_30 ( L_5 , V_2 ) ;
F_30 ( L_6 ) ;
return - V_39 ;
}
if ( V_38 . V_40 == V_41 )
return 0 ;
if ( V_2 -> V_42 == V_43 )
return 0 ;
error = F_20 ( V_2 ) ;
if ( error )
return error ;
if ( V_38 . V_40 == V_44 ) {
F_31 ( V_2 -> V_35 ) ;
F_32 ( V_2 -> V_35 , V_45 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_23 ( V_2 , V_36 ) ) {
F_34 ( & V_2 -> V_25 ) ;
F_35 ( V_2 ) ;
F_36 ( & V_2 -> V_25 ) ;
}
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( F_23 ( V_2 , V_36 ) ) {
F_34 ( & V_2 -> V_25 ) ;
V_4 -> V_46 . V_47 = 0 ;
error = F_39 ( V_2 ) ;
F_36 ( & V_2 -> V_25 ) ;
if ( F_40 ( V_2 ) )
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( F_45 ( V_2 ) )
F_46 ( V_2 ) ;
}
F_47 ( V_2 ) ;
V_4 -> V_37 = 0 ;
return error ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_48 ;
if ( V_2 -> V_42 == V_43 )
return 0 ;
if ( F_49 ( V_2 -> V_35 ) )
return - V_49 ;
F_50 ( V_2 -> V_35 ) ;
V_48 = F_33 ( V_2 ) ;
if ( V_48 )
return V_48 ;
F_51 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , T_3 V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_53 ( V_2 ) )
return - V_39 ;
F_54 ( V_51 , F_55 ( V_51 ) | V_52 ) ;
F_9 ( V_51 ) ;
if ( F_56 ( V_2 ) || F_57 ( V_2 ) ) {
F_54 ( V_53 ,
V_54 |
V_55 |
V_56 ) ;
F_9 ( V_53 ) ;
F_58 ( 1 ) ;
F_54 ( V_53 , 0 ) ;
F_9 ( V_53 ) ;
}
F_58 ( 1 ) ;
F_54 ( V_51 , F_55 ( V_51 ) & ~ V_52 ) ;
F_9 ( V_51 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
T_3 V_57 ;
F_60 ( V_2 -> V_35 , V_58 , & V_57 ) ;
return V_57 & 0x1 ;
}
static int F_61 ( struct V_1 * V_2 , T_3 V_50 )
{
T_3 V_57 ;
F_60 ( V_2 -> V_35 , V_58 , & V_57 ) ;
F_62 ( V_2 -> V_35 , V_58 , V_57 | V_50 | 0x1 ) ;
return F_63 ( F_59 ( V_2 ) , 500 ) ;
}
static int F_64 ( struct V_1 * V_2 , T_3 V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_57 = F_55 ( V_59 + V_60 ) ;
F_54 ( V_59 + V_60 , V_57 | V_50 | 0x1 ) ;
return F_63 ( F_55 ( V_59 + V_60 ) & 0x1 , 500 ) ;
}
static int F_65 ( struct V_1 * V_2 , T_3 V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_54 ( V_61 , V_62 ) ;
return F_63 ( ( F_55 ( V_61 ) & V_62 ) == 0 , 500 ) ;
}
int F_66 ( struct V_1 * V_2 , T_3 V_50 )
{
T_4 * V_4 = V_2 -> V_5 ;
bool V_63 = true ;
int V_48 ;
if ( ! V_64 )
return 0 ;
if ( ! F_67 ( & V_2 -> V_25 ) )
return - V_65 ;
F_68 ( V_2 ) ;
V_48 = - V_39 ;
if ( F_69 () - V_4 -> V_66 < 5 ) {
F_30 ( L_7 ) ;
} else switch ( F_70 ( V_2 ) -> V_67 ) {
case 7 :
case 6 :
V_48 = F_65 ( V_2 , V_50 ) ;
if ( F_71 ( & V_4 -> V_26 ) )
F_5 ( V_4 ) ;
break;
case 5 :
V_48 = F_64 ( V_2 , V_50 ) ;
break;
case 4 :
V_48 = F_61 ( V_2 , V_50 ) ;
break;
case 2 :
V_48 = F_52 ( V_2 , V_50 ) ;
break;
}
V_4 -> V_66 = F_69 () ;
if ( V_48 ) {
F_30 ( L_8 ) ;
F_36 ( & V_2 -> V_25 ) ;
return V_48 ;
}
if ( F_23 ( V_2 , V_36 ) ||
! V_4 -> V_46 . V_47 ) {
V_4 -> V_46 . V_47 = 0 ;
V_4 -> V_68 [ V_69 ] . F_72 ( & V_4 -> V_68 [ V_69 ] ) ;
if ( F_73 ( V_2 ) )
V_4 -> V_68 [ V_70 ] . F_72 ( & V_4 -> V_68 [ V_70 ] ) ;
if ( F_74 ( V_2 ) )
V_4 -> V_68 [ V_71 ] . F_72 ( & V_4 -> V_68 [ V_71 ] ) ;
F_36 ( & V_2 -> V_25 ) ;
F_26 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_34 ( & V_2 -> V_25 ) ;
}
F_36 ( & V_2 -> V_25 ) ;
if ( V_63 ) {
F_34 ( & V_2 -> V_72 . V_73 ) ;
F_44 ( V_2 ) ;
F_36 ( & V_2 -> V_72 . V_73 ) ;
}
return 0 ;
}
static int T_5
F_75 ( struct V_6 * V_35 , const struct V_74 * V_75 )
{
if ( F_76 ( V_35 -> V_76 ) )
return - V_39 ;
return F_77 ( V_35 , V_75 , & V_77 ) ;
}
static void
F_78 ( struct V_6 * V_35 )
{
struct V_1 * V_2 = F_79 ( V_35 ) ;
F_80 ( V_2 ) ;
}
static int F_81 ( struct V_12 * V_2 )
{
struct V_6 * V_35 = F_82 ( V_2 ) ;
struct V_1 * V_78 = F_79 ( V_35 ) ;
int error ;
if ( ! V_78 || ! V_78 -> V_5 ) {
F_25 ( V_2 , L_6 ) ;
return - V_39 ;
}
if ( V_78 -> V_42 == V_43 )
return 0 ;
error = F_20 ( V_78 ) ;
if ( error )
return error ;
F_31 ( V_35 ) ;
F_32 ( V_35 , V_45 ) ;
return 0 ;
}
static int F_83 ( struct V_12 * V_2 )
{
struct V_6 * V_35 = F_82 ( V_2 ) ;
struct V_1 * V_78 = F_79 ( V_35 ) ;
return F_48 ( V_78 ) ;
}
static int F_84 ( struct V_12 * V_2 )
{
struct V_6 * V_35 = F_82 ( V_2 ) ;
struct V_1 * V_78 = F_79 ( V_35 ) ;
if ( ! V_78 || ! V_78 -> V_5 ) {
F_25 ( V_2 , L_6 ) ;
return - V_39 ;
}
return F_20 ( V_78 ) ;
}
static int F_85 ( struct V_12 * V_2 )
{
struct V_6 * V_35 = F_82 ( V_2 ) ;
struct V_1 * V_78 = F_79 ( V_35 ) ;
return F_33 ( V_78 ) ;
}
static int F_86 ( struct V_12 * V_2 )
{
struct V_6 * V_35 = F_82 ( V_2 ) ;
struct V_1 * V_78 = F_79 ( V_35 ) ;
return F_20 ( V_78 ) ;
}
static int T_6 F_87 ( void )
{
if ( ! V_79 ) {
F_30 ( L_9 ) ;
return - V_39 ;
}
V_77 . V_80 = V_81 ;
#if F_88 ( V_82 )
if ( V_83 != 0 )
V_77 . V_84 |= V_36 ;
#endif
if ( V_83 == 1 )
V_77 . V_84 |= V_36 ;
#ifdef F_89
if ( F_90 () && V_83 == - 1 )
V_77 . V_84 &= ~ V_36 ;
#endif
if ( ! ( V_77 . V_84 & V_36 ) )
V_77 . V_85 = NULL ;
return F_91 ( & V_77 , & V_86 ) ;
}
static void T_7 F_92 ( void )
{
F_93 ( & V_77 , & V_86 ) ;
}
