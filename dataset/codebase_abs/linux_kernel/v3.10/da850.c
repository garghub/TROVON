static void F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( F_3 ( V_3 ) ) ;
V_2 |= V_4 ;
F_4 ( V_2 , F_3 ( V_3 ) ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( F_3 ( V_3 ) ) ;
V_2 &= ~ V_4 ;
F_4 ( V_2 , F_3 ( V_3 ) ) ;
}
static void F_6 ( int V_5 )
{
struct V_1 * V_1 , * V_6 = V_5 ? & V_7 : & V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 ;
int V_12 ;
for ( V_10 = V_13 ; V_10 -> V_1 ; V_10 ++ ) {
V_1 = V_10 -> V_1 ;
if ( V_1 -> V_14 & V_15 ) {
V_12 = F_7 ( V_1 , V_6 ) ;
F_8 ( V_12 , L_1 ,
V_1 -> V_16 ) ;
}
}
V_11 = F_9 ( F_3 ( V_17 ) ) ;
if ( V_5 )
V_11 |= V_18 ;
else
V_11 &= ~ V_18 ;
F_10 ( V_11 , F_3 ( V_17 ) ) ;
}
static int F_11 ( unsigned int V_19 )
{
struct V_20 * V_21 ;
if ( ! V_22 )
return - V_23 ;
V_21 = (struct V_20 * ) V_24 . V_25 [ V_19 ] . V_19 ;
return F_12 ( V_22 , V_21 -> V_26 , V_21 -> V_27 ) ;
}
static int F_13 ( void )
{
V_22 = F_14 ( NULL , L_2 ) ;
if ( F_8 ( F_15 ( V_22 ) , L_3
L_4 ) ) {
return F_16 ( V_22 ) ;
}
return 0 ;
}
int F_17 ( char * V_28 )
{
int V_29 ;
if ( V_28 )
F_18 ( L_5 , V_30 . V_16 ,
V_28 , NULL ) ;
for ( V_29 = 0 ; V_29 < F_19 ( V_31 ) ; V_29 ++ ) {
if ( V_31 [ V_29 ] . V_32 <= V_33 ) {
V_24 . V_25 = & V_31 [ V_29 ] ;
break;
}
}
return F_20 ( & V_30 ) ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_34 )
{
int V_29 , V_12 = 0 , V_35 ;
unsigned int V_36 = ( unsigned int ) - 1 ;
struct V_37 * V_38 = V_24 . V_25 ;
V_34 /= 1000 ;
for ( V_29 = 0 ; V_38 [ V_29 ] . V_32 != V_39 ; V_29 ++ ) {
V_35 = V_38 [ V_29 ] . V_32 - V_34 ;
if ( V_35 < 0 )
V_35 = - V_35 ;
if ( V_35 < V_36 ) {
V_36 = V_35 ;
V_12 = V_38 [ V_29 ] . V_32 ;
}
}
return V_12 * 1000 ;
}
static int F_22 ( struct V_1 * V_1 , unsigned long V_19 )
{
struct V_1 * V_40 = & V_41 ;
return F_23 ( V_40 , V_19 ) ;
}
static int F_24 ( struct V_1 * V_1 , unsigned long V_19 )
{
unsigned int V_42 , V_43 , V_44 ;
struct V_20 * V_21 ;
struct V_45 * V_46 = V_1 -> V_45 ;
int V_12 ;
V_21 = (struct V_20 * ) V_24 . V_25 [ V_19 ] . V_19 ;
V_42 = V_21 -> V_42 ;
V_43 = V_21 -> V_43 ;
V_44 = V_21 -> V_44 ;
V_12 = F_25 ( V_46 , V_42 , V_43 , V_44 ) ;
if ( F_26 ( V_12 ) )
return V_12 ;
return 0 ;
}
int T_2 F_17 ( char * V_28 )
{
return 0 ;
}
static int F_22 ( struct V_1 * V_1 , unsigned long V_34 )
{
return - V_47 ;
}
static int F_24 ( struct V_1 * V_1 , unsigned long V_48 )
{
return - V_47 ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_34 )
{
return V_1 -> V_34 ;
}
int T_2 F_27 ( struct V_49 * V_50 )
{
int V_12 ;
struct V_51 * V_52 = V_50 -> V_53 . V_54 ;
V_12 = F_28 ( V_55 ) ;
if ( V_12 )
return V_12 ;
V_52 -> V_56 = F_29 () ;
V_52 -> V_57 = F_30 ( V_58 ) ;
V_52 -> V_59 = V_60 ;
V_52 -> V_61 = F_31 ( V_62 , V_63 ) ;
if ( ! V_52 -> V_61 )
return - V_64 ;
V_52 -> V_65 = F_31 ( V_66 , V_63 ) ;
if ( ! V_52 -> V_65 ) {
V_12 = - V_64 ;
goto V_67;
}
V_52 -> V_68 = F_31 ( V_69 , V_63 ) ;
if ( ! V_52 -> V_68 ) {
V_12 = - V_64 ;
goto V_70;
}
return F_20 ( V_50 ) ;
V_70:
F_32 ( V_52 -> V_65 ) ;
V_67:
F_32 ( V_52 -> V_61 ) ;
return V_12 ;
}
int T_2 F_33 ( void )
{
return F_20 ( & V_71 ) ;
}
int T_2 F_34 ( struct V_72
* V_73 )
{
V_74 . V_53 . V_54 = V_73 ;
return F_20 ( & V_74 ) ;
}
int T_2 F_35 ( struct V_75
* V_76 )
{
V_77 . V_53 . V_54 = V_76 ;
return F_20 ( & V_77 ) ;
}
void T_2 F_36 ( void )
{
unsigned int V_11 ;
F_37 ( & V_78 ) ;
V_79 = F_31 ( V_80 , V_63 ) ;
if ( F_8 ( ! V_79 , L_6 ) )
return;
V_81 = F_31 ( V_82 , V_63 ) ;
if ( F_8 ( ! V_81 , L_7 ) )
return;
F_6 ( 1 ) ;
V_11 = F_9 ( F_3 ( V_83 ) ) ;
V_11 &= ~ V_84 ;
F_10 ( V_11 , F_3 ( V_83 ) ) ;
V_11 = F_9 ( F_3 ( V_17 ) ) ;
V_11 &= ~ V_85 ;
F_10 ( V_11 , F_3 ( V_17 ) ) ;
}
