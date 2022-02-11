static void F_1 ( int V_1 )
{
struct V_2 * V_2 , * V_3 = V_1 ? & V_4 : & V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
int V_9 ;
for ( V_7 = V_10 ; V_7 -> V_2 ; V_7 ++ ) {
V_2 = V_7 -> V_2 ;
if ( V_2 -> V_11 & V_12 ) {
V_9 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_9 , L_1 ,
V_2 -> V_13 ) ;
}
}
V_8 = F_4 ( F_5 ( V_14 ) ) ;
if ( V_1 )
V_8 |= V_15 ;
else
V_8 &= ~ V_15 ;
F_6 ( V_8 , F_5 ( V_14 ) ) ;
}
static int F_7 ( unsigned int V_16 )
{
struct V_17 * V_18 ;
if ( ! V_19 )
return - V_20 ;
V_18 = (struct V_17 * ) V_21 . V_22 [ V_16 ] . V_16 ;
return F_8 ( V_19 , V_18 -> V_23 , V_18 -> V_24 ) ;
}
static int F_9 ( void )
{
V_19 = F_10 ( NULL , L_2 ) ;
if ( F_3 ( F_11 ( V_19 ) , L_3
L_4 ) ) {
return F_12 ( V_19 ) ;
}
return 0 ;
}
int F_13 ( char * V_25 )
{
int V_26 ;
if ( V_25 )
F_14 ( L_5 , V_27 . V_13 ,
V_25 , NULL ) ;
for ( V_26 = 0 ; V_26 < F_15 ( V_28 ) ; V_26 ++ ) {
if ( V_28 [ V_26 ] . V_29 <= V_30 ) {
V_21 . V_22 = & V_28 [ V_26 ] ;
break;
}
}
return F_16 ( & V_27 ) ;
}
static int F_17 ( struct V_2 * V_2 , unsigned long V_31 )
{
int V_26 , V_9 = 0 , V_32 ;
unsigned int V_33 = ( unsigned int ) - 1 ;
struct V_34 * V_35 = V_21 . V_22 ;
V_31 /= 1000 ;
for ( V_26 = 0 ; V_35 [ V_26 ] . V_29 != V_36 ; V_26 ++ ) {
V_32 = V_35 [ V_26 ] . V_29 - V_31 ;
if ( V_32 < 0 )
V_32 = - V_32 ;
if ( V_32 < V_33 ) {
V_33 = V_32 ;
V_9 = V_35 [ V_26 ] . V_29 ;
}
}
return V_9 * 1000 ;
}
static int F_18 ( struct V_2 * V_2 , unsigned long V_16 )
{
struct V_2 * V_37 = & V_38 ;
return F_19 ( V_37 , V_16 ) ;
}
static int F_20 ( struct V_2 * V_2 , unsigned long V_16 )
{
unsigned int V_39 , V_40 , V_41 ;
struct V_17 * V_18 ;
struct V_42 * V_43 = V_2 -> V_42 ;
int V_9 ;
V_18 = (struct V_17 * ) V_21 . V_22 [ V_16 ] . V_16 ;
V_39 = V_18 -> V_39 ;
V_40 = V_18 -> V_40 ;
V_41 = V_18 -> V_41 ;
V_9 = F_21 ( V_43 , V_39 , V_40 , V_41 ) ;
if ( F_22 ( V_9 ) )
return V_9 ;
return 0 ;
}
int T_1 F_13 ( char * V_25 )
{
return 0 ;
}
static int F_18 ( struct V_2 * V_2 , unsigned long V_31 )
{
return - V_44 ;
}
static int F_20 ( struct V_2 * V_2 , unsigned long V_45 )
{
return - V_44 ;
}
static int F_17 ( struct V_2 * V_2 , unsigned long V_31 )
{
return V_2 -> V_31 ;
}
int T_1 F_23 ( struct V_46 * V_47 )
{
int V_9 ;
struct V_48 * V_49 = V_47 -> V_50 . V_51 ;
V_9 = F_24 ( V_52 ) ;
if ( V_9 )
return V_9 ;
V_49 -> V_53 = F_25 () ;
V_49 -> V_54 = F_26 ( V_55 ) ;
V_49 -> V_56 = V_57 ;
V_49 -> V_58 = F_27 ( V_59 , V_60 ) ;
if ( ! V_49 -> V_58 )
return - V_61 ;
V_49 -> V_62 = F_27 ( V_63 , V_60 ) ;
if ( ! V_49 -> V_62 ) {
V_9 = - V_61 ;
goto V_64;
}
V_49 -> V_65 = F_27 ( V_66 , V_60 ) ;
if ( ! V_49 -> V_65 ) {
V_9 = - V_61 ;
goto V_67;
}
return F_16 ( V_47 ) ;
V_67:
F_28 ( V_49 -> V_62 ) ;
V_64:
F_28 ( V_49 -> V_58 ) ;
return V_9 ;
}
int T_1 F_29 ( void )
{
return F_16 ( & V_68 ) ;
}
int T_1 F_30 ( struct V_69
* V_70 )
{
V_71 . V_50 . V_51 = V_70 ;
return F_16 ( & V_71 ) ;
}
int T_1 F_31 ( struct V_72
* V_73 )
{
V_74 . V_50 . V_51 = V_73 ;
return F_16 ( & V_74 ) ;
}
void T_1 F_32 ( void )
{
unsigned int V_8 ;
F_33 ( & V_75 ) ;
V_76 = F_27 ( V_77 , V_60 ) ;
if ( F_3 ( ! V_76 , L_6 ) )
return;
V_78 = F_27 ( V_79 , V_60 ) ;
if ( F_3 ( ! V_78 , L_7 ) )
return;
F_1 ( 1 ) ;
V_8 = F_4 ( F_5 ( V_80 ) ) ;
V_8 &= ~ V_81 ;
F_6 ( V_8 , F_5 ( V_80 ) ) ;
V_8 = F_4 ( F_5 ( V_14 ) ) ;
V_8 &= ~ V_82 ;
F_6 ( V_8 , F_5 ( V_14 ) ) ;
}
