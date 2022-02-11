static int F_1 ( struct V_1 * V_1 , struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( F_3 ( V_4 ) ) ;
if ( V_2 == & V_5 ) {
V_3 &= ~ V_6 ;
} else if ( V_2 == & V_7 ) {
V_3 |= V_6 ;
} else {
F_4 ( L_1 ) ;
return - V_8 ;
}
F_5 ( V_3 , F_3 ( V_4 ) ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
T_1 V_3 ;
V_3 = F_2 ( F_3 ( V_9 ) ) ;
V_3 |= V_10 ;
F_5 ( V_3 , F_3 ( V_9 ) ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
T_1 V_3 ;
V_3 = F_2 ( F_3 ( V_9 ) ) ;
V_3 &= ~ V_10 ;
F_5 ( V_3 , F_3 ( V_9 ) ) ;
}
static int F_8 ( unsigned int V_11 )
{
struct V_12 * V_13 ;
if ( ! V_14 )
return - V_15 ;
V_13 = (struct V_12 * ) V_16 . V_17 [ V_11 ] . V_18 ;
return F_9 ( V_14 , V_13 -> V_19 , V_13 -> V_20 ) ;
}
static int F_10 ( void )
{
V_14 = F_11 ( NULL , L_2 ) ;
if ( F_12 ( F_13 ( V_14 ) , L_3
L_4 ) ) {
return F_14 ( V_14 ) ;
}
return 0 ;
}
int F_15 ( char * V_21 )
{
int V_22 ;
if ( V_21 )
F_16 ( L_5 , V_23 . V_24 ,
V_21 , NULL ) ;
for ( V_22 = 0 ; V_22 < F_17 ( V_25 ) ; V_22 ++ ) {
if ( V_25 [ V_22 ] . V_26 <= V_27 ) {
V_16 . V_17 = & V_25 [ V_22 ] ;
break;
}
}
return F_18 ( & V_23 ) ;
}
static int F_19 ( struct V_1 * V_1 , unsigned long V_28 )
{
int V_29 = 0 , V_30 ;
unsigned int V_31 = ( unsigned int ) - 1 ;
struct V_32 * V_33 = V_16 . V_17 ;
struct V_32 * V_34 ;
V_28 /= 1000 ;
F_20 (pos, table) {
V_30 = V_34 -> V_26 - V_28 ;
if ( V_30 < 0 )
V_30 = - V_30 ;
if ( V_30 < V_31 ) {
V_31 = V_30 ;
V_29 = V_34 -> V_26 ;
}
}
return V_29 * 1000 ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_11 )
{
struct V_1 * V_35 = & V_36 ;
return F_22 ( V_35 , V_11 ) ;
}
static int F_23 ( struct V_1 * V_1 , unsigned long V_11 )
{
unsigned int V_37 , V_38 , V_39 ;
struct V_12 * V_13 ;
struct V_40 * V_41 = V_1 -> V_40 ;
int V_29 ;
V_13 = (struct V_12 * ) V_16 . V_17 [ V_11 ] . V_18 ;
V_37 = V_13 -> V_37 ;
V_38 = V_13 -> V_38 ;
V_39 = V_13 -> V_39 ;
V_29 = F_24 ( V_41 , V_37 , V_38 , V_39 ) ;
if ( F_25 ( V_29 ) )
return V_29 ;
return 0 ;
}
int T_2 F_15 ( char * V_21 )
{
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_28 )
{
return - V_8 ;
}
static int F_23 ( struct V_1 * V_1 , unsigned long V_42 )
{
return - V_8 ;
}
static int F_19 ( struct V_1 * V_1 , unsigned long V_28 )
{
return V_1 -> V_28 ;
}
int T_2 F_26 ( void )
{
return F_18 ( & V_43 ) ;
}
int T_2 F_27 ( struct V_44
* V_45 )
{
V_46 . V_47 . V_48 = V_45 ;
return F_18 ( & V_46 ) ;
}
int T_2 F_28 ( struct V_49
* V_50 )
{
V_51 . V_47 . V_48 = V_50 ;
return F_18 ( & V_51 ) ;
}
int T_2 F_29 ( void )
{
return F_30 ( & V_52 ) ;
}
void T_2 F_31 ( void )
{
unsigned int V_53 ;
F_32 ( & V_54 ) ;
V_55 = F_33 ( V_56 , V_57 ) ;
if ( F_12 ( ! V_55 , L_6 ) )
return;
V_58 = F_33 ( V_59 , V_57 ) ;
if ( F_12 ( ! V_58 , L_7 ) )
return;
V_53 = F_34 ( F_3 ( V_60 ) ) ;
V_53 &= ~ V_61 ;
F_35 ( V_53 , F_3 ( V_60 ) ) ;
V_53 = F_34 ( F_3 ( V_4 ) ) ;
V_53 &= ~ V_62 ;
F_35 ( V_53 , F_3 ( V_4 ) ) ;
F_36 ( V_54 . V_63 ) ;
}
