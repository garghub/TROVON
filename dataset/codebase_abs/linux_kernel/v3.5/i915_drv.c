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
V_4 -> V_17 = 2 ;
F_3 ( L_1 ) ;
} else if ( V_11 == V_18 ) {
V_4 -> V_15 = V_19 ;
V_4 -> V_17 = 2 ;
F_3 ( L_2 ) ;
} else if ( V_11 == V_20 ) {
V_4 -> V_15 = V_19 ;
V_4 -> V_17 = 2 ;
F_3 ( L_3 ) ;
} else if ( V_11 == V_21 ) {
V_4 -> V_15 = V_22 ;
V_4 -> V_17 = 0 ;
F_3 ( L_4 ) ;
}
F_4 ( V_4 -> V_17 > V_23 ) ;
}
F_5 ( V_7 ) ;
}
}
bool F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) -> V_24 < 6 )
return 0 ;
if ( V_25 >= 0 )
return V_25 ;
#ifdef F_8
if ( F_7 ( V_2 ) -> V_24 == 6 && V_26 )
return false ;
#endif
return 1 ;
}
void F_9 ( struct V_3 * V_4 )
{
int V_27 ;
V_27 = 0 ;
while ( V_27 ++ < 50 && ( F_10 ( V_28 ) & 1 ) )
F_11 ( 10 ) ;
F_12 ( V_29 , 1 ) ;
F_13 ( V_29 ) ;
V_27 = 0 ;
while ( V_27 ++ < 50 && ( F_10 ( V_28 ) & 1 ) == 0 )
F_11 ( 10 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
int V_27 ;
V_27 = 0 ;
while ( V_27 ++ < 50 && ( F_10 ( V_30 ) & 1 ) )
F_11 ( 10 ) ;
F_12 ( V_31 , F_15 ( 1 ) ) ;
F_13 ( V_31 ) ;
V_27 = 0 ;
while ( V_27 ++ < 50 && ( F_10 ( V_30 ) & 1 ) == 0 )
F_11 ( 10 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
unsigned long V_32 ;
F_17 ( & V_4 -> V_33 , V_32 ) ;
if ( V_4 -> V_34 ++ == 0 )
V_4 -> V_35 . V_36 ( V_4 ) ;
F_18 ( & V_4 -> V_33 , V_32 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
T_1 V_37 ;
V_37 = F_10 ( V_38 ) ;
if ( F_20 ( V_37 & V_39 ,
L_5 , V_37 ) )
F_12 ( V_38 , V_39 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
F_12 ( V_29 , 0 ) ;
F_19 ( V_4 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
F_12 ( V_31 , F_23 ( 1 ) ) ;
F_19 ( V_4 ) ;
}
void F_24 ( struct V_3 * V_4 )
{
unsigned long V_32 ;
F_17 ( & V_4 -> V_33 , V_32 ) ;
if ( -- V_4 -> V_34 == 0 )
V_4 -> V_35 . V_40 ( V_4 ) ;
F_18 ( & V_4 -> V_33 , V_32 ) ;
}
int F_25 ( struct V_3 * V_4 )
{
int V_41 = 0 ;
if ( V_4 -> V_42 < V_43 ) {
int V_44 = 500 ;
T_1 V_45 = F_10 ( V_46 ) ;
while ( V_45 <= V_43 && V_44 -- ) {
F_11 ( 10 ) ;
V_45 = F_10 ( V_46 ) ;
}
if ( F_26 ( V_44 < 0 && V_45 <= V_43 ) )
++ V_41 ;
V_4 -> V_42 = V_45 ;
}
V_4 -> V_42 -- ;
return V_41 ;
}
void F_27 ( struct V_3 * V_4 )
{
int V_27 ;
V_27 = 0 ;
if ( ( F_28 ( 0x130094 ) & 0xa1 ) == 0xa1 )
return;
F_12 ( V_47 , 0xffffffff ) ;
F_13 ( V_47 ) ;
V_27 = 0 ;
while ( V_27 ++ < 50 && ( F_10 ( V_48 ) & 1 ) == 0 )
F_11 ( 10 ) ;
}
void F_29 ( struct V_3 * V_4 )
{
F_12 ( V_47 , 0xffff0000 ) ;
F_13 ( V_47 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_31 ( V_2 ) ;
F_32 ( V_2 -> V_49 ) ;
if ( F_33 ( V_2 , V_50 ) ) {
int error = F_34 ( V_2 ) ;
if ( error ) {
F_35 ( & V_2 -> V_49 -> V_2 ,
L_6 ) ;
return error ;
}
F_36 ( V_2 ) ;
}
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
V_4 -> V_51 = 0 ;
F_39 () ;
F_40 ( V_2 , 1 ) ;
F_41 () ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 , T_2 V_52 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_43 ( L_7 , V_2 ) ;
F_43 ( L_8 ) ;
return - V_53 ;
}
if ( V_52 . V_54 == V_55 )
return 0 ;
if ( V_2 -> V_56 == V_57 )
return 0 ;
error = F_30 ( V_2 ) ;
if ( error )
return error ;
if ( V_52 . V_54 == V_58 ) {
F_44 ( V_2 -> V_49 ) ;
F_45 ( V_2 -> V_49 , V_59 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_33 ( V_2 , V_50 ) ) {
F_47 ( & V_2 -> V_60 ) ;
F_48 ( V_2 ) ;
F_49 ( & V_2 -> V_60 ) ;
}
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( F_33 ( V_2 , V_50 ) ) {
if ( F_52 ( V_2 ) )
F_53 ( V_2 ) ;
F_47 ( & V_2 -> V_60 ) ;
V_4 -> V_61 . V_62 = 0 ;
error = F_54 ( V_2 ) ;
F_49 ( & V_2 -> V_60 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_47 ( & V_2 -> V_63 . V_64 ) ;
F_58 ( V_2 ) ;
F_49 ( & V_2 -> V_63 . V_64 ) ;
}
F_59 ( V_2 ) ;
V_4 -> V_51 = 0 ;
F_39 () ;
F_40 ( V_2 , 0 ) ;
F_41 () ;
return error ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_41 ;
if ( V_2 -> V_56 == V_57 )
return 0 ;
if ( F_61 ( V_2 -> V_49 ) )
return - V_65 ;
F_62 ( V_2 -> V_49 ) ;
V_41 = F_46 ( V_2 ) ;
if ( V_41 )
return V_41 ;
F_63 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_65 ( V_2 ) )
return - V_53 ;
F_66 ( V_66 , F_28 ( V_66 ) | V_67 ) ;
F_13 ( V_66 ) ;
if ( F_67 ( V_2 ) || F_68 ( V_2 ) ) {
F_66 ( V_68 ,
V_69 |
V_70 |
V_71 ) ;
F_13 ( V_68 ) ;
F_69 ( 1 ) ;
F_66 ( V_68 , 0 ) ;
F_13 ( V_68 ) ;
}
F_69 ( 1 ) ;
F_66 ( V_66 , F_28 ( V_66 ) & ~ V_67 ) ;
F_13 ( V_66 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
T_3 V_72 ;
F_71 ( V_2 -> V_49 , V_73 , & V_72 ) ;
return ( V_72 & V_74 ) == 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_41 ;
T_3 V_72 ;
F_71 ( V_2 -> V_49 , V_73 , & V_72 ) ;
F_73 ( V_2 -> V_49 , V_73 ,
V_72 | V_75 |
V_74 ) ;
V_41 = F_74 ( F_70 ( V_2 ) , 500 ) ;
if ( V_41 )
return V_41 ;
F_71 ( V_2 -> V_49 , V_73 , & V_72 ) ;
F_73 ( V_2 -> V_49 , V_73 ,
V_72 | V_76 |
V_74 ) ;
return F_74 ( F_70 ( V_2 ) , 500 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_72 ;
int V_41 ;
V_72 = F_28 ( V_77 + V_78 ) ;
F_66 ( V_77 + V_78 ,
V_72 | V_75 | V_74 ) ;
V_41 = F_74 ( F_28 ( V_77 + V_78 ) & 0x1 , 500 ) ;
if ( V_41 )
return V_41 ;
V_72 = F_28 ( V_77 + V_78 ) ;
F_66 ( V_77 + V_78 ,
V_72 | V_76 | V_74 ) ;
return F_74 ( F_28 ( V_77 + V_78 ) & 0x1 , 500 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_41 ;
unsigned long V_32 ;
F_17 ( & V_4 -> V_33 , V_32 ) ;
F_12 ( V_79 , V_80 ) ;
V_41 = F_74 ( ( F_10 ( V_79 ) & V_80 ) == 0 , 500 ) ;
if ( V_4 -> V_34 )
V_4 -> V_35 . V_36 ( V_4 ) ;
else
V_4 -> V_35 . V_40 ( V_4 ) ;
V_4 -> V_42 = F_10 ( V_46 ) ;
F_18 ( & V_4 -> V_33 , V_32 ) ;
return V_41 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_41 = - V_53 ;
switch ( F_7 ( V_2 ) -> V_24 ) {
case 7 :
case 6 :
V_41 = F_76 ( V_2 ) ;
break;
case 5 :
V_41 = F_75 ( V_2 ) ;
break;
case 4 :
V_41 = F_72 ( V_2 ) ;
break;
case 2 :
V_41 = F_64 ( V_2 ) ;
break;
}
if ( V_4 -> V_81 ) {
F_78 ( L_9 ) ;
V_4 -> V_81 = 0 ;
if ( V_41 == - V_53 ) {
F_43 ( L_10
L_11 ) ;
V_41 = 0 ;
}
}
return V_41 ;
}
int F_79 ( struct V_1 * V_2 )
{
T_4 * V_4 = V_2 -> V_5 ;
int V_41 ;
if ( ! V_82 )
return 0 ;
if ( ! F_80 ( & V_2 -> V_60 ) )
return - V_83 ;
V_4 -> V_81 = 0 ;
F_81 ( V_2 ) ;
V_41 = - V_53 ;
if ( F_82 () - V_4 -> V_84 < 5 )
F_43 ( L_12 ) ;
else
V_41 = F_77 ( V_2 ) ;
V_4 -> V_84 = F_82 () ;
if ( V_41 ) {
F_43 ( L_13 ) ;
F_49 ( & V_2 -> V_60 ) ;
return V_41 ;
}
if ( F_33 ( V_2 , V_50 ) ||
! V_4 -> V_61 . V_62 ) {
struct V_85 * V_86 ;
int V_87 ;
V_4 -> V_61 . V_62 = 0 ;
F_83 ( V_2 ) ;
F_84 (ring, dev_priv, i)
V_86 -> V_88 ( V_86 ) ;
F_85 ( V_2 ) ;
F_49 ( & V_2 -> V_60 ) ;
if ( F_33 ( V_2 , V_50 ) )
F_55 ( V_2 ) ;
F_36 ( V_2 ) ;
F_57 ( V_2 ) ;
} else {
F_49 ( & V_2 -> V_60 ) ;
}
return 0 ;
}
static int T_5
F_86 ( struct V_6 * V_49 , const struct V_89 * V_90 )
{
if ( F_87 ( V_49 -> V_91 ) )
return - V_53 ;
return F_88 ( V_49 , V_90 , & V_92 ) ;
}
static void
F_89 ( struct V_6 * V_49 )
{
struct V_1 * V_2 = F_90 ( V_49 ) ;
F_91 ( V_2 ) ;
}
static int F_92 ( struct V_12 * V_2 )
{
struct V_6 * V_49 = F_93 ( V_2 ) ;
struct V_1 * V_93 = F_90 ( V_49 ) ;
int error ;
if ( ! V_93 || ! V_93 -> V_5 ) {
F_35 ( V_2 , L_8 ) ;
return - V_53 ;
}
if ( V_93 -> V_56 == V_57 )
return 0 ;
error = F_30 ( V_93 ) ;
if ( error )
return error ;
F_44 ( V_49 ) ;
F_45 ( V_49 , V_59 ) ;
return 0 ;
}
static int F_94 ( struct V_12 * V_2 )
{
struct V_6 * V_49 = F_93 ( V_2 ) ;
struct V_1 * V_93 = F_90 ( V_49 ) ;
return F_60 ( V_93 ) ;
}
static int F_95 ( struct V_12 * V_2 )
{
struct V_6 * V_49 = F_93 ( V_2 ) ;
struct V_1 * V_93 = F_90 ( V_49 ) ;
if ( ! V_93 || ! V_93 -> V_5 ) {
F_35 ( V_2 , L_8 ) ;
return - V_53 ;
}
return F_30 ( V_93 ) ;
}
static int F_96 ( struct V_12 * V_2 )
{
struct V_6 * V_49 = F_93 ( V_2 ) ;
struct V_1 * V_93 = F_90 ( V_49 ) ;
return F_46 ( V_93 ) ;
}
static int F_97 ( struct V_12 * V_2 )
{
struct V_6 * V_49 = F_93 ( V_2 ) ;
struct V_1 * V_93 = F_90 ( V_49 ) ;
return F_30 ( V_93 ) ;
}
static int T_6 F_98 ( void )
{
if ( ! V_94 ) {
F_43 ( L_14 ) ;
return - V_53 ;
}
V_92 . V_95 = V_96 ;
#if F_99 ( V_97 )
if ( V_98 != 0 )
V_92 . V_99 |= V_50 ;
#endif
if ( V_98 == 1 )
V_92 . V_99 |= V_50 ;
#ifdef F_100
if ( F_101 () && V_98 == - 1 )
V_92 . V_99 &= ~ V_50 ;
#endif
if ( ! ( V_92 . V_99 & V_50 ) )
V_92 . V_100 = NULL ;
return F_102 ( & V_92 , & V_101 ) ;
}
static void T_7 F_103 ( void )
{
F_104 ( & V_92 , & V_101 ) ;
}
