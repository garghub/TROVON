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
unsigned long V_25 ;
F_12 ( & V_4 -> V_26 , V_25 ) ;
if ( V_4 -> V_27 ++ == 0 )
V_4 -> V_28 . V_29 ( V_4 ) ;
F_13 ( & V_4 -> V_26 , V_25 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
F_8 ( V_22 , 0 ) ;
F_9 ( V_22 ) ;
}
void F_15 ( struct V_3 * V_4 )
{
F_8 ( V_24 , ( 1 << 16 ) | 0 ) ;
F_9 ( V_24 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
unsigned long V_25 ;
F_12 ( & V_4 -> V_26 , V_25 ) ;
if ( -- V_4 -> V_27 == 0 )
V_4 -> V_28 . V_30 ( V_4 ) ;
F_13 ( & V_4 -> V_26 , V_25 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
if ( V_4 -> V_31 < V_32 ) {
int V_33 = 500 ;
T_1 V_34 = F_6 ( V_35 ) ;
while ( V_34 <= V_32 && V_33 -- ) {
F_7 ( 10 ) ;
V_34 = F_6 ( V_35 ) ;
}
F_18 ( V_33 < 0 && V_34 <= V_32 ) ;
V_4 -> V_31 = V_34 ;
}
V_4 -> V_31 -- ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_20 ( V_2 ) ;
F_21 ( V_2 -> V_36 ) ;
if ( F_22 ( V_2 , V_37 ) ) {
int error = F_23 ( V_2 ) ;
if ( error ) {
F_24 ( & V_2 -> V_36 -> V_2 ,
L_4 ) ;
return error ;
}
F_25 ( V_2 ) ;
}
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
V_4 -> V_38 = 0 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_39 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_29 ( L_5 , V_2 ) ;
F_29 ( L_6 ) ;
return - V_40 ;
}
if ( V_39 . V_41 == V_42 )
return 0 ;
if ( V_2 -> V_43 == V_44 )
return 0 ;
error = F_19 ( V_2 ) ;
if ( error )
return error ;
if ( V_39 . V_41 == V_45 ) {
F_30 ( V_2 -> V_36 ) ;
F_31 ( V_2 -> V_36 , V_46 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_22 ( V_2 , V_37 ) ) {
F_33 ( & V_2 -> V_47 ) ;
F_34 ( V_2 ) ;
F_35 ( & V_2 -> V_47 ) ;
}
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( F_22 ( V_2 , V_37 ) ) {
F_33 ( & V_2 -> V_47 ) ;
V_4 -> V_48 . V_49 = 0 ;
error = F_38 ( V_2 ) ;
F_35 ( & V_2 -> V_47 ) ;
if ( F_39 ( V_2 ) )
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( F_44 ( V_2 ) )
F_45 ( V_2 ) ;
}
F_46 ( V_2 ) ;
V_4 -> V_38 = 0 ;
return error ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_43 == V_44 )
return 0 ;
if ( F_48 ( V_2 -> V_36 ) )
return - V_51 ;
F_49 ( V_2 -> V_36 ) ;
V_50 = F_32 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_50 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_3 V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_52 ( V_2 ) )
return - V_40 ;
F_53 ( V_53 , F_54 ( V_53 ) | V_54 ) ;
F_9 ( V_53 ) ;
if ( F_55 ( V_2 ) || F_56 ( V_2 ) ) {
F_53 ( V_55 ,
V_56 |
V_57 |
V_58 ) ;
F_9 ( V_55 ) ;
F_57 ( 1 ) ;
F_53 ( V_55 , 0 ) ;
F_9 ( V_55 ) ;
}
F_57 ( 1 ) ;
F_53 ( V_53 , F_54 ( V_53 ) & ~ V_54 ) ;
F_9 ( V_53 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_3 V_59 ;
F_59 ( V_2 -> V_36 , V_60 , & V_59 ) ;
return V_59 & 0x1 ;
}
static int F_60 ( struct V_1 * V_2 , T_3 V_52 )
{
T_3 V_59 ;
F_59 ( V_2 -> V_36 , V_60 , & V_59 ) ;
F_61 ( V_2 -> V_36 , V_60 , V_59 | V_52 | 0x1 ) ;
return F_62 ( F_58 ( V_2 ) , 500 ) ;
}
static int F_63 ( struct V_1 * V_2 , T_3 V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_59 = F_54 ( V_61 + V_62 ) ;
F_53 ( V_61 + V_62 , V_59 | V_52 | 0x1 ) ;
return F_62 ( F_54 ( V_61 + V_62 ) & 0x1 , 500 ) ;
}
static int F_64 ( struct V_1 * V_2 , T_3 V_52 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_50 ;
unsigned long V_25 ;
F_12 ( & V_4 -> V_26 , V_25 ) ;
F_8 ( V_63 , V_64 ) ;
V_50 = F_62 ( ( F_6 ( V_63 ) & V_64 ) == 0 , 500 ) ;
if ( V_4 -> V_27 )
V_4 -> V_28 . V_29 ( V_4 ) ;
else
V_4 -> V_28 . V_30 ( V_4 ) ;
V_4 -> V_31 = F_6 ( V_35 ) ;
F_13 ( & V_4 -> V_26 , V_25 ) ;
return V_50 ;
}
int F_65 ( struct V_1 * V_2 , T_3 V_52 )
{
T_4 * V_4 = V_2 -> V_5 ;
bool V_65 = true ;
int V_50 ;
if ( ! V_66 )
return 0 ;
if ( ! F_66 ( & V_2 -> V_47 ) )
return - V_67 ;
F_67 ( V_2 ) ;
V_50 = - V_40 ;
if ( F_68 () - V_4 -> V_68 < 5 ) {
F_29 ( L_7 ) ;
} else switch ( F_69 ( V_2 ) -> V_69 ) {
case 7 :
case 6 :
V_50 = F_64 ( V_2 , V_52 ) ;
break;
case 5 :
V_50 = F_63 ( V_2 , V_52 ) ;
break;
case 4 :
V_50 = F_60 ( V_2 , V_52 ) ;
break;
case 2 :
V_50 = F_51 ( V_2 , V_52 ) ;
break;
}
V_4 -> V_68 = F_68 () ;
if ( V_50 ) {
F_29 ( L_8 ) ;
F_35 ( & V_2 -> V_47 ) ;
return V_50 ;
}
if ( F_22 ( V_2 , V_37 ) ||
! V_4 -> V_48 . V_49 ) {
V_4 -> V_48 . V_49 = 0 ;
V_4 -> V_70 [ V_71 ] . F_70 ( & V_4 -> V_70 [ V_71 ] ) ;
if ( F_71 ( V_2 ) )
V_4 -> V_70 [ V_72 ] . F_70 ( & V_4 -> V_70 [ V_72 ] ) ;
if ( F_72 ( V_2 ) )
V_4 -> V_70 [ V_73 ] . F_70 ( & V_4 -> V_70 [ V_73 ] ) ;
F_35 ( & V_2 -> V_47 ) ;
F_25 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_33 ( & V_2 -> V_47 ) ;
}
F_35 ( & V_2 -> V_47 ) ;
if ( V_65 ) {
F_33 ( & V_2 -> V_74 . V_75 ) ;
F_43 ( V_2 ) ;
F_35 ( & V_2 -> V_74 . V_75 ) ;
}
return 0 ;
}
static int T_5
F_73 ( struct V_6 * V_36 , const struct V_76 * V_77 )
{
if ( F_74 ( V_36 -> V_78 ) )
return - V_40 ;
return F_75 ( V_36 , V_77 , & V_79 ) ;
}
static void
F_76 ( struct V_6 * V_36 )
{
struct V_1 * V_2 = F_77 ( V_36 ) ;
F_78 ( V_2 ) ;
}
static int F_79 ( struct V_12 * V_2 )
{
struct V_6 * V_36 = F_80 ( V_2 ) ;
struct V_1 * V_80 = F_77 ( V_36 ) ;
int error ;
if ( ! V_80 || ! V_80 -> V_5 ) {
F_24 ( V_2 , L_6 ) ;
return - V_40 ;
}
if ( V_80 -> V_43 == V_44 )
return 0 ;
error = F_19 ( V_80 ) ;
if ( error )
return error ;
F_30 ( V_36 ) ;
F_31 ( V_36 , V_46 ) ;
return 0 ;
}
static int F_81 ( struct V_12 * V_2 )
{
struct V_6 * V_36 = F_80 ( V_2 ) ;
struct V_1 * V_80 = F_77 ( V_36 ) ;
return F_47 ( V_80 ) ;
}
static int F_82 ( struct V_12 * V_2 )
{
struct V_6 * V_36 = F_80 ( V_2 ) ;
struct V_1 * V_80 = F_77 ( V_36 ) ;
if ( ! V_80 || ! V_80 -> V_5 ) {
F_24 ( V_2 , L_6 ) ;
return - V_40 ;
}
return F_19 ( V_80 ) ;
}
static int F_83 ( struct V_12 * V_2 )
{
struct V_6 * V_36 = F_80 ( V_2 ) ;
struct V_1 * V_80 = F_77 ( V_36 ) ;
return F_32 ( V_80 ) ;
}
static int F_84 ( struct V_12 * V_2 )
{
struct V_6 * V_36 = F_80 ( V_2 ) ;
struct V_1 * V_80 = F_77 ( V_36 ) ;
return F_19 ( V_80 ) ;
}
static int T_6 F_85 ( void )
{
if ( ! V_81 ) {
F_29 ( L_9 ) ;
return - V_40 ;
}
V_79 . V_82 = V_83 ;
#if F_86 ( V_84 )
if ( V_85 != 0 )
V_79 . V_86 |= V_37 ;
#endif
if ( V_85 == 1 )
V_79 . V_86 |= V_37 ;
#ifdef F_87
if ( F_88 () && V_85 == - 1 )
V_79 . V_86 &= ~ V_37 ;
#endif
if ( ! ( V_79 . V_86 & V_37 ) )
V_79 . V_87 = NULL ;
return F_89 ( & V_79 , & V_88 ) ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_79 , & V_88 ) ;
}
