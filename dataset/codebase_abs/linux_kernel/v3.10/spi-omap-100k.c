static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 -> V_6 + V_7 ) ;
V_3 |= V_8 ;
F_4 ( V_3 , V_5 -> V_6 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 -> V_6 + V_7 ) ;
V_3 &= ~ V_8 ;
F_4 ( V_3 , V_5 -> V_6 + V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_9 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_9 <= 8 ) {
V_10 <<= 8 ;
V_9 = 16 ;
}
F_1 ( V_2 ) ;
F_4 ( V_10 , V_5 -> V_6 + V_11 ) ;
F_4 ( F_7 ( 0 ) |
F_8 ( V_9 ) |
V_12 ,
V_5 -> V_6 + V_13 ) ;
while( ( F_3 ( V_5 -> V_6 + V_14 ) & V_15 ) != V_15 ) ;
F_9 ( 1000 ) ;
F_5 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_9 )
{
int V_16 , V_17 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_9 <= 8 )
V_9 = 16 ;
F_1 ( V_2 ) ;
F_4 ( F_7 ( 0 ) |
F_8 ( V_9 ) |
V_18 ,
V_5 -> V_6 + V_13 ) ;
while( ( F_3 ( V_5 -> V_6 + V_14 ) & V_19 ) != V_19 ) ;
F_9 ( 1000 ) ;
V_17 = F_3 ( V_5 -> V_6 + V_20 ) ;
V_16 = F_3 ( V_5 -> V_6 + V_21 ) ;
F_5 ( V_2 ) ;
return V_17 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_4 ( V_22 |
V_23 |
F_12 ( 0 ) , V_5 -> V_6 + V_7 ) ;
F_4 ( V_24 |
V_25 |
V_26 , V_5 -> V_6 + V_27 ) ;
}
static void F_13 ( struct V_4 * V_5 , int V_28 )
{
if ( V_28 )
F_4 ( 0x05fc , V_5 -> V_6 + V_13 ) ;
else
F_4 ( 0x05fd , V_5 -> V_6 + V_13 ) ;
}
static unsigned
F_14 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_4 * V_5 ;
struct V_33 * V_34 = V_30 -> V_35 ;
unsigned int V_36 , V_37 ;
int V_38 ;
V_5 = F_2 ( V_30 -> V_2 ) ;
V_36 = V_32 -> V_9 ;
V_37 = V_36 ;
V_38 = V_34 -> V_38 ;
if ( V_38 <= 8 ) {
T_1 * V_39 ;
const T_1 * V_40 ;
V_39 = V_32 -> V_41 ;
V_40 = V_32 -> V_42 ;
do {
V_37 -= 1 ;
if ( V_32 -> V_42 != NULL )
F_6 ( V_30 -> V_2 , V_38 , * V_40 ++ ) ;
if ( V_32 -> V_41 != NULL )
* V_39 ++ = F_10 ( V_30 -> V_2 , V_38 ) ;
} while( V_37 );
} else if ( V_38 <= 16 ) {
T_2 * V_39 ;
const T_2 * V_40 ;
V_39 = V_32 -> V_41 ;
V_40 = V_32 -> V_42 ;
do {
V_37 -= 2 ;
if ( V_32 -> V_42 != NULL )
F_6 ( V_30 -> V_2 , V_38 , * V_40 ++ ) ;
if ( V_32 -> V_41 != NULL )
* V_39 ++ = F_10 ( V_30 -> V_2 , V_38 ) ;
} while( V_37 );
} else if ( V_38 <= 32 ) {
T_3 * V_39 ;
const T_3 * V_40 ;
V_39 = V_32 -> V_41 ;
V_40 = V_32 -> V_42 ;
do {
V_37 -= 4 ;
if ( V_32 -> V_42 != NULL )
F_6 ( V_30 -> V_2 , V_38 , * V_40 ) ;
if ( V_32 -> V_41 != NULL )
* V_39 = F_10 ( V_30 -> V_2 , V_38 ) ;
} while( V_37 );
}
return V_36 - V_37 ;
}
static int F_15 ( struct V_29 * V_30 ,
struct V_31 * V_43 )
{
struct V_4 * V_5 = F_2 ( V_30 -> V_2 ) ;
struct V_33 * V_34 = V_30 -> V_35 ;
T_1 V_38 = V_30 -> V_44 ;
if ( V_43 != NULL && V_43 -> V_44 )
V_38 = V_43 -> V_44 ;
if ( ! V_38 )
V_38 = 8 ;
if ( V_30 -> V_44 > 32 )
return - V_45 ;
V_34 -> V_38 = V_38 ;
F_4 ( 0x3e , V_5 -> V_6 + V_7 ) ;
F_4 ( 0x00 , V_5 -> V_6 + V_14 ) ;
F_4 ( 0x3e , V_5 -> V_6 + V_13 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 )
{
int V_46 ;
struct V_4 * V_5 ;
struct V_33 * V_34 = V_30 -> V_35 ;
if ( V_30 -> V_44 < 4 || V_30 -> V_44 > 32 ) {
F_17 ( & V_30 -> V_47 , L_1 ,
V_30 -> V_44 ) ;
return - V_45 ;
}
V_5 = F_2 ( V_30 -> V_2 ) ;
if ( ! V_34 ) {
V_34 = F_18 ( sizeof *V_34 , V_48 ) ;
if ( ! V_34 )
return - V_49 ;
V_34 -> V_6 = V_5 -> V_6 + V_30 -> V_50 * 0x14 ;
V_30 -> V_35 = V_34 ;
}
F_11 ( V_30 -> V_2 ) ;
F_19 ( V_5 -> V_51 ) ;
F_19 ( V_5 -> V_52 ) ;
V_46 = F_15 ( V_30 , NULL ) ;
F_20 ( V_5 -> V_51 ) ;
F_20 ( V_5 -> V_52 ) ;
return V_46 ;
}
static void F_21 ( struct V_53 * V_54 )
{
struct V_4 * V_5 ;
int V_55 = 0 ;
V_5 = F_22 ( V_54 , struct V_4 , V_54 ) ;
F_23 ( & V_5 -> V_56 ) ;
F_19 ( V_5 -> V_51 ) ;
F_19 ( V_5 -> V_52 ) ;
while ( ! F_24 ( & V_5 -> V_57 ) ) {
struct V_58 * V_59 ;
struct V_29 * V_30 ;
struct V_31 * V_43 = NULL ;
int V_60 = 0 ;
struct V_33 * V_34 ;
int V_61 = 0 ;
V_59 = F_22 ( V_5 -> V_57 . V_62 , struct V_58 ,
V_63 ) ;
F_25 ( & V_59 -> V_63 ) ;
F_26 ( & V_5 -> V_56 ) ;
V_30 = V_59 -> V_30 ;
V_34 = V_30 -> V_35 ;
F_27 (t, &m->transfers, transfer_list) {
if ( V_43 -> V_42 == NULL && V_43 -> V_41 == NULL && V_43 -> V_9 ) {
V_55 = - V_45 ;
break;
}
if ( V_61 || V_43 -> V_64 || V_43 -> V_44 ) {
V_61 = 1 ;
V_55 = F_15 ( V_30 , V_43 ) ;
if ( V_55 < 0 )
break;
if ( ! V_43 -> V_64 && ! V_43 -> V_44 )
V_61 = 0 ;
}
if ( ! V_60 ) {
F_13 ( V_5 , 1 ) ;
V_60 = 1 ;
}
if ( V_43 -> V_9 ) {
unsigned V_36 ;
V_36 = F_14 ( V_30 , V_43 ) ;
V_59 -> V_65 += V_36 ;
if ( V_36 != V_43 -> V_9 ) {
V_55 = - V_66 ;
break;
}
}
if ( V_43 -> V_67 )
F_9 ( V_43 -> V_67 ) ;
if ( V_43 -> V_68 ) {
F_13 ( V_5 , 0 ) ;
V_60 = 0 ;
}
}
if ( V_61 ) {
V_61 = 0 ;
V_55 = F_15 ( V_30 , NULL ) ;
}
if ( V_60 )
F_13 ( V_5 , 0 ) ;
V_59 -> V_55 = V_55 ;
V_59 -> V_69 ( V_59 -> V_70 ) ;
F_23 ( & V_5 -> V_56 ) ;
}
F_20 ( V_5 -> V_51 ) ;
F_20 ( V_5 -> V_52 ) ;
F_26 ( & V_5 -> V_56 ) ;
if ( V_55 < 0 )
F_28 ( V_71 L_2 , V_55 ) ;
}
static int F_29 ( struct V_29 * V_30 , struct V_58 * V_59 )
{
struct V_4 * V_5 ;
unsigned long V_72 ;
struct V_31 * V_43 ;
V_59 -> V_65 = 0 ;
V_59 -> V_55 = - V_73 ;
V_5 = F_2 ( V_30 -> V_2 ) ;
if ( V_5 -> V_74 == V_75 )
return - V_76 ;
if ( F_24 ( & V_59 -> V_77 ) || ! V_59 -> V_69 )
return - V_45 ;
F_27 (t, &m->transfers, transfer_list) {
const void * V_42 = V_43 -> V_42 ;
void * V_41 = V_43 -> V_41 ;
unsigned V_9 = V_43 -> V_9 ;
if ( V_43 -> V_64 > V_78
|| ( V_9 && ! ( V_41 || V_42 ) )
|| ( V_43 -> V_44 &&
( V_43 -> V_44 < 4
|| V_43 -> V_44 > 32 ) ) ) {
F_17 ( & V_30 -> V_47 , L_3 ,
V_43 -> V_64 ,
V_9 ,
V_42 ? L_4 : L_5 ,
V_41 ? L_6 : L_5 ,
V_43 -> V_44 ) ;
return - V_45 ;
}
if ( V_43 -> V_64 && V_43 -> V_64 < V_78 / ( 1 << 16 ) ) {
F_17 ( & V_30 -> V_47 , L_7 ,
V_43 -> V_64 ,
V_78 / ( 1 << 16 ) ) ;
return - V_45 ;
}
}
F_30 ( & V_5 -> V_56 , V_72 ) ;
F_31 ( & V_59 -> V_63 , & V_5 -> V_57 ) ;
F_32 ( V_79 , & V_5 -> V_54 ) ;
F_33 ( & V_5 -> V_56 , V_72 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_35 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_55 = 0 ;
if ( ! V_81 -> V_82 )
return - V_45 ;
V_2 = F_36 ( & V_81 -> V_47 , sizeof *V_5 ) ;
if ( V_2 == NULL ) {
F_17 ( & V_81 -> V_47 , L_8 ) ;
return - V_49 ;
}
if ( V_81 -> V_82 != - 1 )
V_2 -> V_83 = V_81 -> V_82 ;
V_2 -> V_84 = F_16 ;
V_2 -> V_85 = F_29 ;
V_2 -> V_86 = NULL ;
V_2 -> V_87 = 2 ;
V_2 -> V_88 = V_89 ;
F_37 ( & V_81 -> V_47 , V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_6 = ( void V_90 * ) V_81 -> V_47 . V_91 ;
F_38 ( & V_5 -> V_54 , F_21 ) ;
F_39 ( & V_5 -> V_56 ) ;
F_40 ( & V_5 -> V_57 ) ;
V_5 -> V_51 = F_41 ( & V_81 -> V_47 , L_9 ) ;
if ( F_42 ( V_5 -> V_51 ) ) {
F_17 ( & V_81 -> V_47 , L_10 ) ;
V_55 = F_43 ( V_5 -> V_51 ) ;
goto V_92;
}
V_5 -> V_52 = F_41 ( & V_81 -> V_47 , L_11 ) ;
if ( F_42 ( V_5 -> V_52 ) ) {
F_17 ( & V_81 -> V_47 , L_12 ) ;
V_55 = F_43 ( V_5 -> V_52 ) ;
goto V_93;
}
if ( F_34 ( V_5 ) < 0 )
goto V_94;
V_55 = F_44 ( V_2 ) ;
if ( V_55 < 0 )
goto V_94;
V_5 -> V_74 = V_95 ;
return V_55 ;
V_94:
F_45 ( V_5 -> V_52 ) ;
V_93:
F_45 ( V_5 -> V_51 ) ;
V_92:
F_46 ( V_2 ) ;
return V_55 ;
}
static int F_47 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_96 * V_97 ;
unsigned V_98 = 500 ;
unsigned long V_72 ;
int V_55 = 0 ;
V_2 = F_48 ( & V_81 -> V_47 ) ;
V_5 = F_2 ( V_2 ) ;
F_30 ( & V_5 -> V_56 , V_72 ) ;
V_5 -> V_74 = V_75 ;
while ( ! F_24 ( & V_5 -> V_57 ) && V_98 -- ) {
F_33 ( & V_5 -> V_56 , V_72 ) ;
F_49 ( 10 ) ;
F_30 ( & V_5 -> V_56 , V_72 ) ;
}
if ( ! F_24 ( & V_5 -> V_57 ) )
V_55 = - V_99 ;
F_33 ( & V_5 -> V_56 , V_72 ) ;
if ( V_55 != 0 )
return V_55 ;
F_45 ( V_5 -> V_52 ) ;
F_45 ( V_5 -> V_51 ) ;
V_97 = F_50 ( V_81 , V_100 , 0 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int T_4 F_52 ( void )
{
V_79 = F_53 (
V_101 . V_102 . V_103 ) ;
if ( V_79 == NULL )
return - 1 ;
return F_54 ( & V_101 , F_35 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_101 ) ;
F_57 ( V_79 ) ;
}
