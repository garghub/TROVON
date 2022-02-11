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
V_5 = F_2 ( V_30 -> V_2 ) ;
if ( ! V_34 ) {
V_34 = F_17 ( sizeof *V_34 , V_47 ) ;
if ( ! V_34 )
return - V_48 ;
V_34 -> V_6 = V_5 -> V_6 + V_30 -> V_49 * 0x14 ;
V_30 -> V_35 = V_34 ;
}
F_11 ( V_30 -> V_2 ) ;
F_18 ( V_5 -> V_50 ) ;
F_18 ( V_5 -> V_51 ) ;
V_46 = F_15 ( V_30 , NULL ) ;
F_19 ( V_5 -> V_50 ) ;
F_19 ( V_5 -> V_51 ) ;
return V_46 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_18 ( V_5 -> V_50 ) ;
F_18 ( V_5 -> V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_53 -> V_30 ;
struct V_31 * V_43 = NULL ;
int V_54 = 0 ;
int V_55 = 0 ;
int V_56 = 0 ;
F_22 (t, &m->transfers, transfer_list) {
if ( V_43 -> V_42 == NULL && V_43 -> V_41 == NULL && V_43 -> V_9 ) {
V_56 = - V_45 ;
break;
}
if ( V_55 || V_43 -> V_57 || V_43 -> V_44 ) {
V_55 = 1 ;
V_56 = F_15 ( V_30 , V_43 ) ;
if ( V_56 < 0 )
break;
if ( ! V_43 -> V_57 && ! V_43 -> V_44 )
V_55 = 0 ;
}
if ( ! V_54 ) {
F_13 ( V_5 , 1 ) ;
V_54 = 1 ;
}
if ( V_43 -> V_9 ) {
unsigned V_36 ;
V_36 = F_14 ( V_30 , V_43 ) ;
V_53 -> V_58 += V_36 ;
if ( V_36 != V_43 -> V_9 ) {
V_56 = - V_59 ;
break;
}
}
if ( V_43 -> V_60 )
F_9 ( V_43 -> V_60 ) ;
if ( V_43 -> V_61 ) {
F_13 ( V_5 , 0 ) ;
V_54 = 0 ;
}
}
if ( V_55 ) {
V_55 = 0 ;
V_56 = F_15 ( V_30 , NULL ) ;
}
if ( V_54 )
F_13 ( V_5 , 0 ) ;
V_53 -> V_56 = V_56 ;
F_23 ( V_2 ) ;
return V_56 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_19 ( V_5 -> V_50 ) ;
F_19 ( V_5 -> V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_56 = 0 ;
if ( ! V_63 -> V_64 )
return - V_45 ;
V_2 = F_26 ( & V_63 -> V_65 , sizeof *V_5 ) ;
if ( V_2 == NULL ) {
F_27 ( & V_63 -> V_65 , L_1 ) ;
return - V_48 ;
}
if ( V_63 -> V_64 != - 1 )
V_2 -> V_66 = V_63 -> V_64 ;
V_2 -> V_67 = F_16 ;
V_2 -> V_68 = F_21 ;
V_2 -> V_69 = F_20 ;
V_2 -> V_70 = F_24 ;
V_2 -> V_71 = NULL ;
V_2 -> V_72 = 2 ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = F_28 ( 4 , 32 ) ;
V_2 -> V_76 = V_77 / ( 1 << 16 ) ;
V_2 -> V_78 = V_77 ;
F_29 ( V_63 , V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_6 = ( void V_79 * ) F_30 ( & V_63 -> V_65 ) ;
V_5 -> V_50 = F_31 ( & V_63 -> V_65 , L_2 ) ;
if ( F_32 ( V_5 -> V_50 ) ) {
F_27 ( & V_63 -> V_65 , L_3 ) ;
V_56 = F_33 ( V_5 -> V_50 ) ;
goto V_80;
}
V_5 -> V_51 = F_31 ( & V_63 -> V_65 , L_4 ) ;
if ( F_32 ( V_5 -> V_51 ) ) {
F_27 ( & V_63 -> V_65 , L_5 ) ;
V_56 = F_33 ( V_5 -> V_51 ) ;
goto V_80;
}
V_56 = F_34 ( & V_63 -> V_65 , V_2 ) ;
if ( V_56 < 0 )
goto V_80;
V_5 -> V_81 = V_82 ;
return V_56 ;
V_80:
F_35 ( V_2 ) ;
return V_56 ;
}
