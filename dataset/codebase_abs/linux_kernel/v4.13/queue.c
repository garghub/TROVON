static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 && ( F_2 ( V_6 -> V_8 ) || F_3 ( V_6 ) ) )
return V_9 ;
V_4 -> V_10 |= V_11 ;
return V_12 ;
}
static int F_4 ( void * V_13 )
{
struct V_5 * V_6 = V_13 ;
struct V_1 * V_2 = V_6 -> V_14 ;
struct V_15 * V_16 = & V_6 -> V_8 -> V_17 -> V_18 ;
V_19 -> V_20 |= V_21 ;
F_5 ( & V_6 -> V_22 ) ;
do {
struct V_3 * V_4 ;
F_6 ( V_2 -> V_23 ) ;
F_7 ( V_24 ) ;
V_4 = F_8 ( V_2 ) ;
V_6 -> V_25 = false ;
V_16 -> V_26 = false ;
V_16 -> V_27 = false ;
if ( ! V_4 ) {
if ( V_6 -> V_28 )
V_16 -> V_26 = true ;
else
V_6 -> V_25 = true ;
}
F_9 ( V_2 -> V_23 ) ;
if ( V_4 || V_6 -> V_28 ) {
F_7 ( V_29 ) ;
F_10 ( V_6 , V_4 ) ;
F_11 () ;
} else {
if ( F_12 () ) {
F_7 ( V_29 ) ;
break;
}
F_13 ( & V_6 -> V_22 ) ;
F_14 () ;
F_5 ( & V_6 -> V_22 ) ;
}
} while ( 1 );
F_13 ( & V_6 -> V_22 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
if ( ! V_6 ) {
while ( ( V_4 = F_8 ( V_2 ) ) != NULL ) {
V_4 -> V_10 |= V_30 ;
F_16 ( V_4 , V_31 ) ;
}
return;
}
V_16 = & V_6 -> V_8 -> V_17 -> V_18 ;
if ( V_16 -> V_26 ) {
V_16 -> V_27 = true ;
F_17 ( & V_16 -> V_32 ) ;
}
if ( V_6 -> V_25 )
F_18 ( V_6 -> V_33 ) ;
}
static struct V_34 * F_19 ( int V_35 , T_1 V_36 )
{
struct V_34 * V_37 ;
V_37 = F_20 ( V_35 , sizeof( * V_37 ) , V_36 ) ;
if ( V_37 )
F_21 ( V_37 , V_35 ) ;
return V_37 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_38 * V_8 )
{
unsigned V_39 ;
V_39 = F_23 ( V_8 ) ;
if ( ! V_39 )
return;
F_24 ( V_40 , V_2 ) ;
F_25 ( V_2 , V_39 ) ;
V_2 -> V_41 . V_42 = V_8 -> V_43 << 9 ;
if ( V_8 -> V_43 > V_39 )
V_2 -> V_41 . V_42 = 0 ;
if ( F_26 ( V_8 ) )
F_24 ( V_44 , V_2 ) ;
}
static unsigned int F_27 ( struct V_45 * V_17 )
{
unsigned int V_46 = V_47 ;
if ( V_17 -> V_48 != 1 || ( V_17 -> V_49 & V_50 ) )
return 0 ;
if ( V_46 > V_17 -> V_51 )
V_46 = V_17 -> V_51 ;
if ( V_46 > V_17 -> V_52 )
V_46 = V_17 -> V_52 ;
if ( V_46 > V_17 -> V_53 * 512 )
V_46 = V_17 -> V_53 * 512 ;
if ( V_46 <= 512 )
return 0 ;
return V_46 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_36 )
{
struct V_54 * V_55 = F_29 ( V_4 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_38 * V_8 = V_6 -> V_8 ;
struct V_45 * V_17 = V_8 -> V_17 ;
if ( V_8 -> V_46 ) {
V_55 -> V_56 = F_30 ( V_8 -> V_46 , V_36 ) ;
if ( ! V_55 -> V_56 )
return - V_57 ;
if ( V_8 -> V_46 > 512 ) {
V_55 -> V_37 = F_19 ( 1 , V_36 ) ;
if ( ! V_55 -> V_37 )
return - V_57 ;
V_55 -> V_58 = F_19 ( V_8 -> V_46 / 512 ,
V_36 ) ;
if ( ! V_55 -> V_58 )
return - V_57 ;
}
} else {
V_55 -> V_56 = NULL ;
V_55 -> V_58 = NULL ;
V_55 -> V_37 = F_19 ( V_17 -> V_48 , V_36 ) ;
if ( ! V_55 -> V_37 )
return - V_57 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_54 * V_55 = F_29 ( V_4 ) ;
F_32 ( V_55 -> V_58 ) ;
V_55 -> V_58 = NULL ;
F_32 ( V_55 -> V_56 ) ;
V_55 -> V_56 = NULL ;
F_32 ( V_55 -> V_37 ) ;
V_55 -> V_37 = NULL ;
}
int F_33 ( struct V_5 * V_6 , struct V_38 * V_8 ,
T_2 * V_59 , const char * V_60 )
{
struct V_45 * V_17 = V_8 -> V_17 ;
T_3 V_61 = V_62 ;
int V_63 = - V_57 ;
if ( F_34 ( V_17 ) -> V_64 && * F_34 ( V_17 ) -> V_64 )
V_61 = ( T_3 ) F_35 ( F_34 ( V_17 ) ) << V_65 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_14 = F_36 ( V_66 ) ;
if ( ! V_6 -> V_14 )
return - V_57 ;
V_6 -> V_14 -> V_23 = V_59 ;
V_6 -> V_14 -> V_67 = F_15 ;
V_6 -> V_14 -> V_68 = F_28 ;
V_6 -> V_14 -> V_69 = F_31 ;
V_6 -> V_14 -> V_70 = sizeof( struct V_54 ) ;
V_6 -> V_14 -> V_7 = V_6 ;
V_6 -> V_28 = 0 ;
V_63 = F_37 ( V_6 -> V_14 ) ;
if ( V_63 ) {
F_38 ( V_6 -> V_14 ) ;
return V_63 ;
}
F_39 ( V_6 -> V_14 , F_1 ) ;
F_24 ( V_71 , V_6 -> V_14 ) ;
F_40 ( V_72 , V_6 -> V_14 ) ;
if ( F_41 ( V_8 ) )
F_22 ( V_6 -> V_14 , V_8 ) ;
V_8 -> V_46 = F_27 ( V_17 ) ;
if ( V_8 -> V_46 ) {
F_42 ( V_6 -> V_14 , V_8 -> V_46 / 512 ) ;
F_43 ( V_6 -> V_14 , V_8 -> V_46 / 512 ) ;
F_44 ( V_6 -> V_14 , V_8 -> V_46 ) ;
} else {
F_45 ( V_6 -> V_14 , V_61 ) ;
F_42 ( V_6 -> V_14 ,
F_46 ( V_17 -> V_53 , V_17 -> V_51 / 512 ) ) ;
F_43 ( V_6 -> V_14 , V_17 -> V_48 ) ;
F_44 ( V_6 -> V_14 , V_17 -> V_52 ) ;
}
F_47 ( & V_6 -> V_22 , 1 ) ;
V_6 -> V_33 = F_48 ( F_4 , V_6 , L_1 ,
V_17 -> V_73 , V_60 ? V_60 : L_2 ) ;
if ( F_49 ( V_6 -> V_33 ) ) {
V_63 = F_50 ( V_6 -> V_33 ) ;
goto V_74;
}
return 0 ;
V_74:
F_38 ( V_6 -> V_14 ) ;
return V_63 ;
}
void F_51 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
F_52 ( V_6 ) ;
F_53 ( V_6 -> V_33 ) ;
F_54 ( V_2 -> V_23 , V_20 ) ;
V_2 -> V_7 = NULL ;
F_55 ( V_2 ) ;
F_56 ( V_2 -> V_23 , V_20 ) ;
V_6 -> V_8 = NULL ;
}
void F_57 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
if ( ! V_6 -> V_75 ) {
V_6 -> V_75 |= true ;
F_54 ( V_2 -> V_23 , V_20 ) ;
F_58 ( V_2 ) ;
F_56 ( V_2 -> V_23 , V_20 ) ;
F_5 ( & V_6 -> V_22 ) ;
}
}
void F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
if ( V_6 -> V_75 ) {
V_6 -> V_75 = false ;
F_13 ( & V_6 -> V_22 ) ;
F_54 ( V_2 -> V_23 , V_20 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 -> V_23 , V_20 ) ;
}
}
unsigned int F_59 ( struct V_5 * V_6 , struct V_54 * V_76 )
{
unsigned int V_35 ;
T_4 V_77 ;
struct V_34 * V_37 ;
struct V_3 * V_4 = F_60 ( V_76 ) ;
int V_78 ;
if ( ! V_76 -> V_56 )
return F_61 ( V_6 -> V_14 , V_4 , V_76 -> V_37 ) ;
V_35 = F_61 ( V_6 -> V_14 , V_4 , V_76 -> V_58 ) ;
V_76 -> V_79 = V_35 ;
V_77 = 0 ;
F_62 (mqrq->bounce_sg, sg, sg_len, i)
V_77 += V_37 -> V_80 ;
F_63 ( V_76 -> V_37 , V_76 -> V_56 , V_77 ) ;
return 1 ;
}
void F_64 ( struct V_54 * V_76 )
{
if ( ! V_76 -> V_56 )
return;
if ( F_65 ( F_60 ( V_76 ) ) != V_81 )
return;
F_66 ( V_76 -> V_58 , V_76 -> V_79 ,
V_76 -> V_56 , V_76 -> V_37 [ 0 ] . V_80 ) ;
}
void F_67 ( struct V_54 * V_76 )
{
if ( ! V_76 -> V_56 )
return;
if ( F_65 ( F_60 ( V_76 ) ) != V_82 )
return;
F_68 ( V_76 -> V_58 , V_76 -> V_79 ,
V_76 -> V_56 , V_76 -> V_37 [ 0 ] . V_80 ) ;
}
