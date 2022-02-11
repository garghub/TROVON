static void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static unsigned long F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_4 )
{
unsigned long V_7 ;
V_7 = F_3 ( V_2 , V_4 ) ;
V_7 |= V_6 ;
F_1 ( V_2 , V_7 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_4 )
{
unsigned long V_7 ;
V_7 = F_3 ( V_2 , V_4 ) ;
V_7 &= ~ V_6 ;
F_1 ( V_2 , V_7 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_8 , V_9 ) ;
F_6 ( V_2 , V_8 , V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_10 = 100000 ;
while ( F_3 ( V_2 , V_11 ) & V_12 ) {
F_9 ( 10 ) ;
if ( V_10 -- < 0 )
return - V_13 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_10 = 100000 ;
while ( ! ( F_3 ( V_2 , V_11 ) & V_14 ) ) {
F_9 ( 10 ) ;
if ( V_10 -- < 0 )
return - V_13 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_19 , V_20 = 0 ;
int V_21 = V_18 -> V_22 ;
int V_23 ;
unsigned char * V_3 ;
unsigned long V_7 ;
long V_24 ;
if ( V_18 -> V_22 )
F_5 ( V_2 , V_25 , V_11 ) ;
V_3 = ( unsigned char * ) V_18 -> V_26 ;
while ( V_21 > 0 ) {
V_23 = F_12 ( V_27 , V_21 ) ;
for ( V_19 = 0 ; V_19 < V_23 &&
! ( F_3 ( V_2 , V_28 ) &
V_29 ) &&
! ( F_3 ( V_2 , V_11 ) & V_30 ) ;
V_19 ++ )
F_1 ( V_2 , ( unsigned long ) V_3 [ V_19 ] , V_31 ) ;
if ( F_3 ( V_2 , V_28 ) & V_29 ) {
F_5 ( V_2 , V_29 , V_28 ) ;
V_20 = - V_32 ;
break;
}
V_23 = V_19 ;
V_21 -= V_23 ;
V_3 += V_23 ;
if ( V_21 > 0 ) {
V_2 -> V_33 &= ~ V_14 ;
F_5 ( V_2 , V_14 , V_28 ) ;
V_24 = F_13 ( V_2 -> V_34 ,
V_2 -> V_33 & V_14 ,
V_35 ) ;
if ( V_24 == 0 && ! ( V_2 -> V_33 & V_14 ) ) {
F_14 ( V_36 L_1 , V_37 ) ;
return - V_13 ;
}
}
}
if ( F_15 ( & V_18 -> V_38 , & V_16 -> V_39 ) ) {
V_7 = F_3 ( V_2 , V_11 ) ;
V_7 = V_7 & ~ ( V_40 | V_41 ) ;
F_1 ( V_2 , V_7 , V_11 ) ;
F_5 ( V_2 , V_25 , V_11 ) ;
V_2 -> V_33 &= ~ V_14 ;
F_5 ( V_2 , V_14 , V_28 ) ;
V_24 = F_13 ( V_2 -> V_34 ,
V_2 -> V_33 & V_14 ,
V_35 ) ;
if ( V_24 == 0 && ( V_2 -> V_33 & V_14 ) ) {
F_14 ( V_36 L_1 , V_37 ) ;
return - V_13 ;
}
}
return V_20 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_19 ;
int V_21 = V_18 -> V_22 ;
int V_23 ;
unsigned char * V_3 ;
unsigned long V_7 ;
long V_24 ;
if ( V_18 -> V_22 > V_42 )
F_1 ( V_2 , V_42 , V_43 ) ;
else
F_1 ( V_2 , V_18 -> V_22 , V_43 ) ;
V_7 = F_3 ( V_2 , V_11 ) ;
V_7 = V_7 & ~ ( V_40 | V_41 ) ;
F_1 ( V_2 , V_7 , V_11 ) ;
F_5 ( V_2 , V_25 , V_11 ) ;
F_10 ( V_2 ) ;
V_3 = ( unsigned char * ) V_18 -> V_44 ;
while ( V_21 > 0 ) {
if ( V_21 >= V_27 ) {
V_2 -> V_33 &= ~ V_45 ;
F_5 ( V_2 , V_45 , V_28 ) ;
V_24 = F_13 ( V_2 -> V_34 ,
V_2 -> V_33 & V_45 ,
V_46 ) ;
if ( V_24 == 0 &&
F_3 ( V_2 , V_11 ) & V_12 ) {
F_14 ( V_36 L_1 , V_37 ) ;
return - V_13 ;
}
}
V_23 = F_12 ( V_27 , V_21 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
if ( F_8 ( V_2 ) )
break;
V_3 [ V_19 ] = ( unsigned char ) F_3 ( V_2 , V_47 ) ;
}
V_21 -= V_23 ;
V_3 += V_23 ;
}
if ( V_18 -> V_22 > V_42 ) {
F_7 ( V_2 ) ;
F_1 ( V_2 , 1 , V_43 ) ;
} else {
F_1 ( V_2 , 0 , V_43 ) ;
}
return 0 ;
}
static void F_17 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_18 ( V_49 , struct V_1 , V_50 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
unsigned long V_51 ;
int V_24 ;
F_19 ( L_2 , V_37 ) ;
F_20 ( & V_2 -> V_52 , V_51 ) ;
while ( ! F_21 ( & V_2 -> V_53 ) ) {
V_16 = F_22 ( V_2 -> V_53 . V_54 , struct V_15 , V_53 ) ;
F_23 ( & V_16 -> V_53 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
F_25 (t, &mesg->transfers, transfer_list) {
F_19 ( L_3 ,
V_18 -> V_26 , V_18 -> V_44 ) ;
F_19 ( L_4 ,
V_18 -> V_22 , V_18 -> V_55 ) ;
if ( V_18 -> V_26 ) {
V_24 = F_11 ( V_2 , V_16 , V_18 ) ;
if ( V_24 < 0 )
goto error;
}
if ( V_18 -> V_44 ) {
V_24 = F_16 ( V_2 , V_16 , V_18 ) ;
if ( V_24 < 0 )
goto error;
}
V_16 -> V_56 += V_18 -> V_22 ;
}
F_20 ( & V_2 -> V_52 , V_51 ) ;
V_16 -> V_57 = 0 ;
V_16 -> V_58 ( V_16 -> V_59 ) ;
}
F_7 ( V_2 ) ;
F_5 ( V_2 , V_40 , V_11 ) ;
F_9 ( 100 ) ;
F_6 ( V_2 , V_25 | V_41 | V_40 ,
V_11 ) ;
F_7 ( V_2 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
return;
error:
V_16 -> V_57 = V_24 ;
V_16 -> V_58 ( V_16 -> V_59 ) ;
F_6 ( V_2 , V_25 | V_41 | V_40 ,
V_11 ) ;
F_7 ( V_2 ) ;
}
static int F_26 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_27 ( V_61 -> V_62 ) ;
if ( ! V_61 -> V_63 )
V_61 -> V_63 = 8 ;
F_19 ( L_2 , V_37 ) ;
F_1 ( V_2 , 0xfe , V_11 ) ;
F_1 ( V_2 , 0x00 , V_11 ) ;
F_1 ( V_2 , 0x00 , V_43 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 , F_3 ( V_2 , V_9 ) | 0x07 , V_9 ) ;
F_9 ( 10 ) ;
return 0 ;
}
static int F_28 ( struct V_60 * V_61 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_27 ( V_61 -> V_62 ) ;
unsigned long V_51 ;
F_19 ( L_2 , V_37 ) ;
F_19 ( L_5 , V_61 -> V_64 ) ;
F_20 ( & V_2 -> V_52 , V_51 ) ;
V_16 -> V_56 = 0 ;
V_16 -> V_57 = - V_65 ;
F_6 ( V_2 , V_25 , V_11 ) ;
F_29 ( & V_16 -> V_53 , & V_2 -> V_53 ) ;
F_30 ( V_2 -> V_66 , & V_2 -> V_50 ) ;
F_24 ( & V_2 -> V_52 , V_51 ) ;
return 0 ;
}
static void F_31 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_27 ( V_61 -> V_62 ) ;
F_19 ( L_2 , V_37 ) ;
F_6 ( V_2 , V_25 | V_41 | V_40 ,
V_11 ) ;
}
static T_1 F_32 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
unsigned long V_33 ;
V_33 = F_3 ( V_2 , V_11 ) ;
if ( V_33 & V_14 )
V_2 -> V_33 |= V_14 ;
if ( V_33 & V_30 )
V_2 -> V_33 |= V_30 ;
if ( V_33 & V_12 )
V_2 -> V_33 |= V_12 ;
if ( V_33 & V_45 )
V_2 -> V_33 |= V_45 ;
if ( V_2 -> V_33 ) {
F_6 ( V_2 , V_2 -> V_33 , V_28 ) ;
F_33 ( & V_2 -> V_34 ) ;
}
return V_69 ;
}
static int T_2 F_34 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_35 ( & V_71 -> V_72 ) ;
F_36 ( V_2 -> V_62 ) ;
F_37 ( V_2 -> V_66 ) ;
F_38 ( V_2 -> V_67 , V_2 ) ;
F_39 ( V_2 -> V_5 ) ;
return 0 ;
}
static int T_3 F_40 ( struct V_70 * V_71 )
{
struct V_73 * V_74 ;
struct V_75 * V_62 ;
struct V_1 * V_2 ;
int V_24 , V_67 ;
V_74 = F_41 ( V_71 , V_76 , 0 ) ;
if ( F_42 ( V_74 == NULL ) ) {
F_43 ( & V_71 -> V_72 , L_6 ) ;
return - V_77 ;
}
V_67 = F_44 ( V_71 , 0 ) ;
if ( V_67 < 0 ) {
F_43 ( & V_71 -> V_72 , L_7 ) ;
return - V_78 ;
}
V_62 = F_45 ( & V_71 -> V_72 , sizeof( struct V_1 ) ) ;
if ( V_62 == NULL ) {
F_43 ( & V_71 -> V_72 , L_8 ) ;
return - V_79 ;
}
V_2 = F_27 ( V_62 ) ;
F_46 ( & V_71 -> V_72 , V_2 ) ;
V_2 -> V_67 = V_67 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_5 = F_47 ( V_74 -> V_80 , F_48 ( V_74 ) ) ;
if ( V_2 -> V_5 == NULL ) {
F_43 ( & V_71 -> V_72 , L_9 ) ;
V_24 = - V_79 ;
goto V_81;
}
F_49 ( & V_2 -> V_53 ) ;
F_50 ( & V_2 -> V_52 ) ;
F_51 ( & V_2 -> V_50 , F_17 ) ;
F_52 ( & V_2 -> V_34 ) ;
V_2 -> V_66 = F_53 (
F_54 ( V_62 -> V_72 . V_82 ) ) ;
if ( V_2 -> V_66 == NULL ) {
F_43 ( & V_71 -> V_72 , L_10 ) ;
V_24 = - V_83 ;
goto V_84;
}
V_24 = F_55 ( V_67 , F_32 , V_85 , L_11 , V_2 ) ;
if ( V_24 < 0 ) {
F_43 ( & V_71 -> V_72 , L_12 ) ;
goto V_86;
}
V_62 -> V_87 = 2 ;
V_62 -> V_88 = V_71 -> V_89 ;
V_62 -> V_90 = F_26 ;
V_62 -> V_91 = F_28 ;
V_62 -> V_92 = F_31 ;
V_24 = F_56 ( V_62 ) ;
if ( V_24 < 0 ) {
F_14 ( V_36 L_13 ) ;
goto V_93;
}
return 0 ;
V_93:
F_38 ( V_67 , V_2 ) ;
V_86:
F_37 ( V_2 -> V_66 ) ;
V_84:
F_39 ( V_2 -> V_5 ) ;
V_81:
F_57 ( V_62 ) ;
return V_24 ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_94 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_94 ) ;
}
