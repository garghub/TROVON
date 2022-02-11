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
static void F_14 ( struct V_3 * V_4 )
{
T_1 V_30 ;
V_30 = F_6 ( V_31 ) ;
if ( F_15 ( V_30 & V_32 ,
L_4 , V_30 ) )
F_8 ( V_31 , V_32 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
F_8 ( V_22 , 0 ) ;
F_14 ( V_4 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_8 ( V_24 , ( 1 << 16 ) | 0 ) ;
F_14 ( V_4 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
unsigned long V_25 ;
F_12 ( & V_4 -> V_26 , V_25 ) ;
if ( -- V_4 -> V_27 == 0 )
V_4 -> V_28 . V_33 ( V_4 ) ;
F_13 ( & V_4 -> V_26 , V_25 ) ;
}
int F_19 ( struct V_3 * V_4 )
{
int V_34 = 0 ;
if ( V_4 -> V_35 < V_36 ) {
int V_37 = 500 ;
T_1 V_38 = F_6 ( V_39 ) ;
while ( V_38 <= V_36 && V_37 -- ) {
F_7 ( 10 ) ;
V_38 = F_6 ( V_39 ) ;
}
if ( F_20 ( V_37 < 0 && V_38 <= V_36 ) )
++ V_34 ;
V_4 -> V_35 = V_38 ;
}
V_4 -> V_35 -- ;
return V_34 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_40 ) ;
if ( F_24 ( V_2 , V_41 ) ) {
int error = F_25 ( V_2 ) ;
if ( error ) {
F_26 ( & V_2 -> V_40 -> V_2 ,
L_5 ) ;
return error ;
}
F_27 ( V_2 ) ;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
V_4 -> V_42 = 0 ;
F_30 () ;
F_31 ( V_2 , 1 ) ;
F_32 () ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_43 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_34 ( L_6 , V_2 ) ;
F_34 ( L_7 ) ;
return - V_44 ;
}
if ( V_43 . V_45 == V_46 )
return 0 ;
if ( V_2 -> V_47 == V_48 )
return 0 ;
error = F_21 ( V_2 ) ;
if ( error )
return error ;
if ( V_43 . V_45 == V_49 ) {
F_35 ( V_2 -> V_40 ) ;
F_36 ( V_2 -> V_40 , V_50 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_24 ( V_2 , V_41 ) ) {
F_38 ( & V_2 -> V_51 ) ;
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_51 ) ;
}
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_24 ( V_2 , V_41 ) ) {
F_38 ( & V_2 -> V_51 ) ;
V_4 -> V_52 . V_53 = 0 ;
error = F_43 ( V_2 ) ;
F_40 ( & V_2 -> V_51 ) ;
if ( F_44 ( V_2 ) )
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_38 ( & V_2 -> V_54 . V_55 ) ;
F_48 ( V_2 ) ;
F_40 ( & V_2 -> V_54 . V_55 ) ;
if ( F_49 ( V_2 ) )
F_50 ( V_2 ) ;
}
F_51 ( V_2 ) ;
V_4 -> V_42 = 0 ;
F_30 () ;
F_31 ( V_2 , 0 ) ;
F_32 () ;
return error ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_34 ;
if ( V_2 -> V_47 == V_48 )
return 0 ;
if ( F_53 ( V_2 -> V_40 ) )
return - V_56 ;
F_54 ( V_2 -> V_40 ) ;
V_34 = F_37 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , T_3 V_57 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_57 ( V_2 ) )
return - V_44 ;
F_58 ( V_58 , F_59 ( V_58 ) | V_59 ) ;
F_9 ( V_58 ) ;
if ( F_60 ( V_2 ) || F_61 ( V_2 ) ) {
F_58 ( V_60 ,
V_61 |
V_62 |
V_63 ) ;
F_9 ( V_60 ) ;
F_62 ( 1 ) ;
F_58 ( V_60 , 0 ) ;
F_9 ( V_60 ) ;
}
F_62 ( 1 ) ;
F_58 ( V_58 , F_59 ( V_58 ) & ~ V_59 ) ;
F_9 ( V_58 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_3 V_64 ;
F_64 ( V_2 -> V_40 , V_65 , & V_64 ) ;
return V_64 & 0x1 ;
}
static int F_65 ( struct V_1 * V_2 , T_3 V_57 )
{
T_3 V_64 ;
F_64 ( V_2 -> V_40 , V_65 , & V_64 ) ;
F_66 ( V_2 -> V_40 , V_65 , V_64 | V_57 | 0x1 ) ;
return F_67 ( F_63 ( V_2 ) , 500 ) ;
}
static int F_68 ( struct V_1 * V_2 , T_3 V_57 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_64 = F_59 ( V_66 + V_67 ) ;
F_58 ( V_66 + V_67 , V_64 | V_57 | 0x1 ) ;
return F_67 ( F_59 ( V_66 + V_67 ) & 0x1 , 500 ) ;
}
static int F_69 ( struct V_1 * V_2 , T_3 V_57 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_34 ;
unsigned long V_25 ;
F_12 ( & V_4 -> V_26 , V_25 ) ;
F_8 ( V_68 , V_69 ) ;
V_34 = F_67 ( ( F_6 ( V_68 ) & V_69 ) == 0 , 500 ) ;
if ( V_4 -> V_27 )
V_4 -> V_28 . V_29 ( V_4 ) ;
else
V_4 -> V_28 . V_33 ( V_4 ) ;
V_4 -> V_35 = F_6 ( V_39 ) ;
F_13 ( & V_4 -> V_26 , V_25 ) ;
return V_34 ;
}
int F_70 ( struct V_1 * V_2 , T_3 V_57 )
{
T_4 * V_4 = V_2 -> V_5 ;
bool V_70 = true ;
int V_34 ;
if ( ! V_71 )
return 0 ;
if ( ! F_71 ( & V_2 -> V_51 ) )
return - V_72 ;
F_72 ( V_2 ) ;
V_34 = - V_44 ;
if ( F_73 () - V_4 -> V_73 < 5 ) {
F_34 ( L_8 ) ;
} else switch ( F_74 ( V_2 ) -> V_74 ) {
case 7 :
case 6 :
V_34 = F_69 ( V_2 , V_57 ) ;
break;
case 5 :
V_34 = F_68 ( V_2 , V_57 ) ;
break;
case 4 :
V_34 = F_65 ( V_2 , V_57 ) ;
break;
case 2 :
V_34 = F_56 ( V_2 , V_57 ) ;
break;
}
V_4 -> V_73 = F_73 () ;
if ( V_34 ) {
F_34 ( L_9 ) ;
F_40 ( & V_2 -> V_51 ) ;
return V_34 ;
}
if ( F_24 ( V_2 , V_41 ) ||
! V_4 -> V_52 . V_53 ) {
V_4 -> V_52 . V_53 = 0 ;
F_75 ( V_2 ) ;
V_4 -> V_75 [ V_76 ] . F_76 ( & V_4 -> V_75 [ V_76 ] ) ;
if ( F_77 ( V_2 ) )
V_4 -> V_75 [ V_77 ] . F_76 ( & V_4 -> V_75 [ V_77 ] ) ;
if ( F_78 ( V_2 ) )
V_4 -> V_75 [ V_78 ] . F_76 ( & V_4 -> V_75 [ V_78 ] ) ;
F_79 ( V_2 ) ;
F_40 ( & V_2 -> V_51 ) ;
F_27 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_38 ( & V_2 -> V_51 ) ;
}
F_40 ( & V_2 -> V_51 ) ;
if ( V_70 ) {
F_38 ( & V_2 -> V_54 . V_55 ) ;
F_48 ( V_2 ) ;
F_40 ( & V_2 -> V_54 . V_55 ) ;
}
return 0 ;
}
static int T_5
F_80 ( struct V_6 * V_40 , const struct V_79 * V_80 )
{
if ( F_81 ( V_40 -> V_81 ) )
return - V_44 ;
return F_82 ( V_40 , V_80 , & V_82 ) ;
}
static void
F_83 ( struct V_6 * V_40 )
{
struct V_1 * V_2 = F_84 ( V_40 ) ;
F_85 ( V_2 ) ;
}
static int F_86 ( struct V_12 * V_2 )
{
struct V_6 * V_40 = F_87 ( V_2 ) ;
struct V_1 * V_83 = F_84 ( V_40 ) ;
int error ;
if ( ! V_83 || ! V_83 -> V_5 ) {
F_26 ( V_2 , L_7 ) ;
return - V_44 ;
}
if ( V_83 -> V_47 == V_48 )
return 0 ;
error = F_21 ( V_83 ) ;
if ( error )
return error ;
F_35 ( V_40 ) ;
F_36 ( V_40 , V_50 ) ;
return 0 ;
}
static int F_88 ( struct V_12 * V_2 )
{
struct V_6 * V_40 = F_87 ( V_2 ) ;
struct V_1 * V_83 = F_84 ( V_40 ) ;
return F_52 ( V_83 ) ;
}
static int F_89 ( struct V_12 * V_2 )
{
struct V_6 * V_40 = F_87 ( V_2 ) ;
struct V_1 * V_83 = F_84 ( V_40 ) ;
if ( ! V_83 || ! V_83 -> V_5 ) {
F_26 ( V_2 , L_7 ) ;
return - V_44 ;
}
return F_21 ( V_83 ) ;
}
static int F_90 ( struct V_12 * V_2 )
{
struct V_6 * V_40 = F_87 ( V_2 ) ;
struct V_1 * V_83 = F_84 ( V_40 ) ;
return F_37 ( V_83 ) ;
}
static int F_91 ( struct V_12 * V_2 )
{
struct V_6 * V_40 = F_87 ( V_2 ) ;
struct V_1 * V_83 = F_84 ( V_40 ) ;
return F_21 ( V_83 ) ;
}
static int T_6 F_92 ( void )
{
if ( ! V_84 ) {
F_34 ( L_10 ) ;
return - V_44 ;
}
V_82 . V_85 = V_86 ;
#if F_93 ( V_87 )
if ( V_88 != 0 )
V_82 . V_89 |= V_41 ;
#endif
if ( V_88 == 1 )
V_82 . V_89 |= V_41 ;
#ifdef F_94
if ( F_95 () && V_88 == - 1 )
V_82 . V_89 &= ~ V_41 ;
#endif
if ( ! ( V_82 . V_89 & V_41 ) )
V_82 . V_90 = NULL ;
return F_96 ( & V_82 , & V_91 ) ;
}
static void T_7 F_97 ( void )
{
F_98 ( & V_82 , & V_91 ) ;
}
