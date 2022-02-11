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
V_21 = (struct V_20 * ) V_24 . V_25 [ V_19 ] . V_26 ;
return F_12 ( V_22 , V_21 -> V_27 , V_21 -> V_28 ) ;
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
int F_17 ( char * V_29 )
{
int V_30 ;
if ( V_29 )
F_18 ( L_5 , V_31 . V_16 ,
V_29 , NULL ) ;
for ( V_30 = 0 ; V_30 < F_19 ( V_32 ) ; V_30 ++ ) {
if ( V_32 [ V_30 ] . V_33 <= V_34 ) {
V_24 . V_25 = & V_32 [ V_30 ] ;
break;
}
}
return F_20 ( & V_31 ) ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_35 )
{
int V_12 = 0 , V_36 ;
unsigned int V_37 = ( unsigned int ) - 1 ;
struct V_38 * V_39 = V_24 . V_25 ;
struct V_38 * V_40 ;
V_35 /= 1000 ;
F_22 (pos, table) {
V_36 = V_40 -> V_33 - V_35 ;
if ( V_36 < 0 )
V_36 = - V_36 ;
if ( V_36 < V_37 ) {
V_37 = V_36 ;
V_12 = V_40 -> V_33 ;
}
}
return V_12 * 1000 ;
}
static int F_23 ( struct V_1 * V_1 , unsigned long V_19 )
{
struct V_1 * V_41 = & V_42 ;
return F_24 ( V_41 , V_19 ) ;
}
static int F_25 ( struct V_1 * V_1 , unsigned long V_19 )
{
unsigned int V_43 , V_44 , V_45 ;
struct V_20 * V_21 ;
struct V_46 * V_47 = V_1 -> V_46 ;
int V_12 ;
V_21 = (struct V_20 * ) V_24 . V_25 [ V_19 ] . V_26 ;
V_43 = V_21 -> V_43 ;
V_44 = V_21 -> V_44 ;
V_45 = V_21 -> V_45 ;
V_12 = F_26 ( V_47 , V_43 , V_44 , V_45 ) ;
if ( F_27 ( V_12 ) )
return V_12 ;
return 0 ;
}
int T_2 F_17 ( char * V_29 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , unsigned long V_35 )
{
return - V_48 ;
}
static int F_25 ( struct V_1 * V_1 , unsigned long V_49 )
{
return - V_48 ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_35 )
{
return V_1 -> V_35 ;
}
int T_2 F_28 ( struct V_50 * V_51 )
{
int V_12 ;
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
V_12 = F_29 ( V_56 ) ;
if ( V_12 )
return V_12 ;
V_53 -> V_57 = F_30 () ;
V_53 -> V_58 = F_31 ( V_59 ) ;
V_53 -> V_60 = V_61 ;
V_53 -> V_62 = F_32 ( V_63 , V_64 ) ;
if ( ! V_53 -> V_62 )
return - V_65 ;
V_53 -> V_66 = F_32 ( V_67 , V_64 ) ;
if ( ! V_53 -> V_66 ) {
V_12 = - V_65 ;
goto V_68;
}
V_53 -> V_69 = F_32 ( V_70 , V_64 ) ;
if ( ! V_53 -> V_69 ) {
V_12 = - V_65 ;
goto V_71;
}
return F_20 ( V_51 ) ;
V_71:
F_33 ( V_53 -> V_66 ) ;
V_68:
F_33 ( V_53 -> V_62 ) ;
return V_12 ;
}
int T_2 F_34 ( void )
{
return F_20 ( & V_72 ) ;
}
int T_2 F_35 ( struct V_73
* V_74 )
{
V_75 . V_54 . V_55 = V_74 ;
return F_20 ( & V_75 ) ;
}
int T_2 F_36 ( struct V_76
* V_77 )
{
V_78 . V_54 . V_55 = V_77 ;
return F_20 ( & V_78 ) ;
}
int T_2 F_37 ( void )
{
return F_38 ( & V_79 ) ;
}
void T_2 F_39 ( void )
{
unsigned int V_11 ;
F_40 ( & V_80 ) ;
V_81 = F_32 ( V_82 , V_64 ) ;
if ( F_8 ( ! V_81 , L_6 ) )
return;
V_83 = F_32 ( V_84 , V_64 ) ;
if ( F_8 ( ! V_83 , L_7 ) )
return;
F_6 ( 1 ) ;
V_11 = F_9 ( F_3 ( V_85 ) ) ;
V_11 &= ~ V_86 ;
F_10 ( V_11 , F_3 ( V_85 ) ) ;
V_11 = F_9 ( F_3 ( V_17 ) ) ;
V_11 &= ~ V_87 ;
F_10 ( V_11 , F_3 ( V_17 ) ) ;
}
