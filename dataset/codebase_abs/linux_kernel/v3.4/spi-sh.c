static void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
if ( V_2 -> V_5 == 8 )
F_2 ( V_3 , V_2 -> V_6 + ( V_4 >> 2 ) ) ;
else if ( V_2 -> V_5 == 32 )
F_3 ( V_3 , V_2 -> V_6 + V_4 ) ;
}
static unsigned long F_4 ( struct V_1 * V_2 , unsigned long V_4 )
{
if ( V_2 -> V_5 == 8 )
return F_5 ( V_2 -> V_6 + ( V_4 >> 2 ) ) ;
else if ( V_2 -> V_5 == 32 )
return F_6 ( V_2 -> V_6 + V_4 ) ;
else
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long V_4 )
{
unsigned long V_8 ;
V_8 = F_4 ( V_2 , V_4 ) ;
V_8 |= V_7 ;
F_1 ( V_2 , V_8 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long V_4 )
{
unsigned long V_8 ;
V_8 = F_4 ( V_2 , V_4 ) ;
V_8 &= ~ V_7 ;
F_1 ( V_2 , V_8 , V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_9 , V_10 ) ;
F_8 ( V_2 , V_9 , V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_11 = 100000 ;
while ( F_4 ( V_2 , V_12 ) & V_13 ) {
F_11 ( 10 ) ;
if ( V_11 -- < 0 )
return - V_14 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_11 = 100000 ;
while ( ! ( F_4 ( V_2 , V_12 ) & V_15 ) ) {
F_11 ( 10 ) ;
if ( V_11 -- < 0 )
return - V_14 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_18 * V_19 )
{
int V_20 , V_21 = 0 ;
int V_22 = V_19 -> V_23 ;
int V_24 ;
unsigned char * V_3 ;
unsigned long V_8 ;
long V_25 ;
if ( V_19 -> V_23 )
F_7 ( V_2 , V_26 , V_12 ) ;
V_3 = ( unsigned char * ) V_19 -> V_27 ;
while ( V_22 > 0 ) {
V_24 = F_14 ( V_28 , V_22 ) ;
for ( V_20 = 0 ; V_20 < V_24 &&
! ( F_4 ( V_2 , V_29 ) &
V_30 ) &&
! ( F_4 ( V_2 , V_12 ) & V_31 ) ;
V_20 ++ )
F_1 ( V_2 , ( unsigned long ) V_3 [ V_20 ] , V_32 ) ;
if ( F_4 ( V_2 , V_29 ) & V_30 ) {
F_7 ( V_2 , V_30 , V_29 ) ;
V_21 = - V_33 ;
break;
}
V_24 = V_20 ;
V_22 -= V_24 ;
V_3 += V_24 ;
if ( V_22 > 0 ) {
V_2 -> V_34 &= ~ V_15 ;
F_7 ( V_2 , V_15 , V_29 ) ;
V_25 = F_15 ( V_2 -> V_35 ,
V_2 -> V_34 & V_15 ,
V_36 ) ;
if ( V_25 == 0 && ! ( V_2 -> V_34 & V_15 ) ) {
F_16 ( V_37 L_1 , V_38 ) ;
return - V_14 ;
}
}
}
if ( F_17 ( & V_19 -> V_39 , & V_17 -> V_40 ) ) {
V_8 = F_4 ( V_2 , V_12 ) ;
V_8 = V_8 & ~ ( V_41 | V_42 ) ;
F_1 ( V_2 , V_8 , V_12 ) ;
F_7 ( V_2 , V_26 , V_12 ) ;
V_2 -> V_34 &= ~ V_15 ;
F_7 ( V_2 , V_15 , V_29 ) ;
V_25 = F_15 ( V_2 -> V_35 ,
V_2 -> V_34 & V_15 ,
V_36 ) ;
if ( V_25 == 0 && ( V_2 -> V_34 & V_15 ) ) {
F_16 ( V_37 L_1 , V_38 ) ;
return - V_14 ;
}
}
return V_21 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_18 * V_19 )
{
int V_20 ;
int V_22 = V_19 -> V_23 ;
int V_24 ;
unsigned char * V_3 ;
unsigned long V_8 ;
long V_25 ;
if ( V_19 -> V_23 > V_43 )
F_1 ( V_2 , V_43 , V_44 ) ;
else
F_1 ( V_2 , V_19 -> V_23 , V_44 ) ;
V_8 = F_4 ( V_2 , V_12 ) ;
V_8 = V_8 & ~ ( V_41 | V_42 ) ;
F_1 ( V_2 , V_8 , V_12 ) ;
F_7 ( V_2 , V_26 , V_12 ) ;
F_12 ( V_2 ) ;
V_3 = ( unsigned char * ) V_19 -> V_45 ;
while ( V_22 > 0 ) {
if ( V_22 >= V_28 ) {
V_2 -> V_34 &= ~ V_46 ;
F_7 ( V_2 , V_46 , V_29 ) ;
V_25 = F_15 ( V_2 -> V_35 ,
V_2 -> V_34 & V_46 ,
V_47 ) ;
if ( V_25 == 0 &&
F_4 ( V_2 , V_12 ) & V_13 ) {
F_16 ( V_37 L_1 , V_38 ) ;
return - V_14 ;
}
}
V_24 = F_14 ( V_28 , V_22 ) ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
if ( F_10 ( V_2 ) )
break;
V_3 [ V_20 ] = ( unsigned char ) F_4 ( V_2 , V_48 ) ;
}
V_22 -= V_24 ;
V_3 += V_24 ;
}
if ( V_19 -> V_23 > V_43 ) {
F_9 ( V_2 ) ;
F_1 ( V_2 , 1 , V_44 ) ;
} else {
F_1 ( V_2 , 0 , V_44 ) ;
}
return 0 ;
}
static void F_19 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_20 ( V_50 , struct V_1 , V_51 ) ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
unsigned long V_52 ;
int V_25 ;
F_21 ( L_2 , V_38 ) ;
F_22 ( & V_2 -> V_53 , V_52 ) ;
while ( ! F_23 ( & V_2 -> V_54 ) ) {
V_17 = F_24 ( V_2 -> V_54 . V_55 , struct V_16 , V_54 ) ;
F_25 ( & V_17 -> V_54 ) ;
F_26 ( & V_2 -> V_53 , V_52 ) ;
F_27 (t, &mesg->transfers, transfer_list) {
F_21 ( L_3 ,
V_19 -> V_27 , V_19 -> V_45 ) ;
F_21 ( L_4 ,
V_19 -> V_23 , V_19 -> V_56 ) ;
if ( V_19 -> V_27 ) {
V_25 = F_13 ( V_2 , V_17 , V_19 ) ;
if ( V_25 < 0 )
goto error;
}
if ( V_19 -> V_45 ) {
V_25 = F_18 ( V_2 , V_17 , V_19 ) ;
if ( V_25 < 0 )
goto error;
}
V_17 -> V_57 += V_19 -> V_23 ;
}
F_22 ( & V_2 -> V_53 , V_52 ) ;
V_17 -> V_58 = 0 ;
V_17 -> V_59 ( V_17 -> V_60 ) ;
}
F_9 ( V_2 ) ;
F_7 ( V_2 , V_41 , V_12 ) ;
F_11 ( 100 ) ;
F_8 ( V_2 , V_26 | V_42 | V_41 ,
V_12 ) ;
F_9 ( V_2 ) ;
F_26 ( & V_2 -> V_53 , V_52 ) ;
return;
error:
V_17 -> V_58 = V_25 ;
V_17 -> V_59 ( V_17 -> V_60 ) ;
F_8 ( V_2 , V_26 | V_42 | V_41 ,
V_12 ) ;
F_9 ( V_2 ) ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_62 -> V_63 ) ;
if ( ! V_62 -> V_64 )
V_62 -> V_64 = 8 ;
F_21 ( L_2 , V_38 ) ;
F_1 ( V_2 , 0xfe , V_12 ) ;
F_1 ( V_2 , 0x00 , V_12 ) ;
F_1 ( V_2 , 0x00 , V_44 ) ;
F_9 ( V_2 ) ;
F_1 ( V_2 , F_4 ( V_2 , V_10 ) | 0x07 , V_10 ) ;
F_11 ( 10 ) ;
return 0 ;
}
static int F_30 ( struct V_61 * V_62 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_29 ( V_62 -> V_63 ) ;
unsigned long V_52 ;
F_21 ( L_2 , V_38 ) ;
F_21 ( L_5 , V_62 -> V_65 ) ;
F_22 ( & V_2 -> V_53 , V_52 ) ;
V_17 -> V_57 = 0 ;
V_17 -> V_58 = - V_66 ;
F_8 ( V_2 , V_26 , V_12 ) ;
F_31 ( & V_17 -> V_54 , & V_2 -> V_54 ) ;
F_32 ( V_2 -> V_67 , & V_2 -> V_51 ) ;
F_26 ( & V_2 -> V_53 , V_52 ) ;
return 0 ;
}
static void F_33 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_62 -> V_63 ) ;
F_21 ( L_2 , V_38 ) ;
F_8 ( V_2 , V_26 | V_42 | V_41 ,
V_12 ) ;
}
static T_1 F_34 ( int V_68 , void * V_69 )
{
struct V_1 * V_2 = (struct V_1 * ) V_69 ;
unsigned long V_34 ;
V_34 = F_4 ( V_2 , V_12 ) ;
if ( V_34 & V_15 )
V_2 -> V_34 |= V_15 ;
if ( V_34 & V_31 )
V_2 -> V_34 |= V_31 ;
if ( V_34 & V_13 )
V_2 -> V_34 |= V_13 ;
if ( V_34 & V_46 )
V_2 -> V_34 |= V_46 ;
if ( V_2 -> V_34 ) {
F_8 ( V_2 , V_2 -> V_34 , V_29 ) ;
F_35 ( & V_2 -> V_35 ) ;
}
return V_70 ;
}
static int T_2 F_36 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_37 ( & V_72 -> V_73 ) ;
F_38 ( V_2 -> V_63 ) ;
F_39 ( V_2 -> V_67 ) ;
F_40 ( V_2 -> V_68 , V_2 ) ;
F_41 ( V_2 -> V_6 ) ;
return 0 ;
}
static int T_3 F_42 ( struct V_71 * V_72 )
{
struct V_74 * V_75 ;
struct V_76 * V_63 ;
struct V_1 * V_2 ;
int V_25 , V_68 ;
V_75 = F_43 ( V_72 , V_77 , 0 ) ;
if ( F_44 ( V_75 == NULL ) ) {
F_45 ( & V_72 -> V_73 , L_6 ) ;
return - V_78 ;
}
V_68 = F_46 ( V_72 , 0 ) ;
if ( V_68 < 0 ) {
F_45 ( & V_72 -> V_73 , L_7 ) ;
return - V_79 ;
}
V_63 = F_47 ( & V_72 -> V_73 , sizeof( struct V_1 ) ) ;
if ( V_63 == NULL ) {
F_45 ( & V_72 -> V_73 , L_8 ) ;
return - V_80 ;
}
V_2 = F_29 ( V_63 ) ;
F_48 ( & V_72 -> V_73 , V_2 ) ;
switch ( V_75 -> V_52 & V_81 ) {
case V_82 :
V_2 -> V_5 = 8 ;
break;
case V_83 :
V_2 -> V_5 = 32 ;
break;
default:
F_45 ( & V_72 -> V_73 , L_9 ) ;
V_25 = - V_79 ;
goto V_84;
}
V_2 -> V_68 = V_68 ;
V_2 -> V_63 = V_63 ;
V_2 -> V_6 = F_49 ( V_75 -> V_85 , F_50 ( V_75 ) ) ;
if ( V_2 -> V_6 == NULL ) {
F_45 ( & V_72 -> V_73 , L_10 ) ;
V_25 = - V_80 ;
goto V_84;
}
F_51 ( & V_2 -> V_54 ) ;
F_52 ( & V_2 -> V_53 ) ;
F_53 ( & V_2 -> V_51 , F_19 ) ;
F_54 ( & V_2 -> V_35 ) ;
V_2 -> V_67 = F_55 (
F_56 ( V_63 -> V_73 . V_86 ) ) ;
if ( V_2 -> V_67 == NULL ) {
F_45 ( & V_72 -> V_73 , L_11 ) ;
V_25 = - V_87 ;
goto V_88;
}
V_25 = F_57 ( V_68 , F_34 , 0 , L_12 , V_2 ) ;
if ( V_25 < 0 ) {
F_45 ( & V_72 -> V_73 , L_13 ) ;
goto V_89;
}
V_63 -> V_90 = 2 ;
V_63 -> V_91 = V_72 -> V_92 ;
V_63 -> V_93 = F_28 ;
V_63 -> V_94 = F_30 ;
V_63 -> V_95 = F_33 ;
V_25 = F_58 ( V_63 ) ;
if ( V_25 < 0 ) {
F_16 ( V_37 L_14 ) ;
goto V_96;
}
return 0 ;
V_96:
F_40 ( V_68 , V_2 ) ;
V_89:
F_39 ( V_2 -> V_67 ) ;
V_88:
F_41 ( V_2 -> V_6 ) ;
V_84:
F_59 ( V_63 ) ;
return V_25 ;
}
