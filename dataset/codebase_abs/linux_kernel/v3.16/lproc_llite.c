static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 V_8 ;
int V_9 ;
F_2 ( V_5 != NULL ) ;
V_9 = F_3 ( V_5 , & V_8 ,
F_4 ( - V_10 ) ,
V_11 ) ;
if ( ! V_9 )
V_9 = F_5 ( V_2 , L_1 , V_8 . V_12 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 V_8 ;
int V_9 ;
F_2 ( V_5 != NULL ) ;
V_9 = F_3 ( V_5 , & V_8 ,
F_4 ( - V_10 ) ,
V_11 ) ;
if ( ! V_9 ) {
T_1 V_13 = V_8 . V_12 >> 10 ;
T_2 V_14 = V_8 . V_15 ;
while ( V_13 >>= 1 )
V_14 <<= 1 ;
V_9 = F_5 ( V_2 , V_16 L_2 , V_14 ) ;
}
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 V_8 ;
int V_9 ;
F_2 ( V_5 != NULL ) ;
V_9 = F_3 ( V_5 , & V_8 ,
F_4 ( - V_10 ) ,
V_11 ) ;
if ( ! V_9 ) {
T_1 V_13 = V_8 . V_12 >> 10 ;
T_2 V_14 = V_8 . V_17 ;
while ( V_13 >>= 1 )
V_14 <<= 1 ;
V_9 = F_5 ( V_2 , V_16 L_2 , V_14 ) ;
}
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 V_8 ;
int V_9 ;
F_2 ( V_5 != NULL ) ;
V_9 = F_3 ( V_5 , & V_8 ,
F_4 ( - V_10 ) ,
V_11 ) ;
if ( ! V_9 ) {
T_1 V_13 = V_8 . V_12 >> 10 ;
T_2 V_14 = V_8 . V_18 ;
while ( V_13 >>= 1 )
V_14 <<= 1 ;
V_9 = F_5 ( V_2 , V_16 L_2 , V_14 ) ;
}
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 V_8 ;
int V_9 ;
F_2 ( V_5 != NULL ) ;
V_9 = F_3 ( V_5 , & V_8 ,
F_4 ( - V_10 ) ,
V_11 ) ;
if ( ! V_9 )
V_9 = F_5 ( V_2 , V_16 L_2 , V_8 . V_19 ) ;
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 V_8 ;
int V_9 ;
F_2 ( V_5 != NULL ) ;
V_9 = F_3 ( V_5 , & V_8 ,
F_4 ( - V_10 ) ,
V_11 ) ;
if ( ! V_9 )
V_9 = F_5 ( V_2 , V_16 L_2 , V_8 . V_20 ) ;
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_3 )
{
struct V_21 * V_22 = F_12 ( (struct V_4 * ) V_2 -> V_6 ) ;
int V_9 ;
F_2 ( V_22 != NULL ) ;
if ( V_22 -> V_23 & V_24 )
V_9 = F_5 ( V_2 , L_3 ) ;
else
V_9 = F_5 ( V_2 , L_4 ) ;
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
F_2 ( V_5 != NULL ) ;
return F_5 ( V_2 , L_5 , V_5 -> V_25 -> V_26 ) ;
}
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
F_2 ( V_5 != NULL ) ;
return F_5 ( V_2 , L_5 , F_12 ( V_5 ) -> V_27 . V_28 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_16 ( F_17 ( F_12 ( V_5 ) -> V_29 ) , V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
long V_30 ;
int V_31 ;
F_19 ( & V_22 -> V_32 ) ;
V_30 = V_22 -> V_33 . V_34 ;
F_20 ( & V_22 -> V_32 ) ;
V_31 = 1 << ( 20 - V_35 ) ;
return F_21 ( V_2 , V_30 , V_31 ) ;
}
static T_3 F_22 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_31 , V_9 , V_30 ;
V_31 = 1 << ( 20 - V_35 ) ;
V_9 = F_23 ( V_37 , V_38 , & V_30 , V_31 ) ;
if ( V_9 )
return V_9 ;
if ( V_30 < 0 || V_30 > V_41 / 2 ) {
F_24 ( L_6 ,
V_41 >> ( 20 - V_35 + 1 ) ) ;
return - V_42 ;
}
F_19 ( & V_22 -> V_32 ) ;
V_22 -> V_33 . V_34 = V_30 ;
F_20 ( & V_22 -> V_32 ) ;
return V_38 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
long V_30 ;
int V_31 ;
F_19 ( & V_22 -> V_32 ) ;
V_30 = V_22 -> V_33 . V_43 ;
F_20 ( & V_22 -> V_32 ) ;
V_31 = 1 << ( 20 - V_35 ) ;
return F_21 ( V_2 , V_30 , V_31 ) ;
}
static T_3 F_26 ( struct V_36 * V_36 ,
const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_31 , V_9 , V_30 ;
V_31 = 1 << ( 20 - V_35 ) ;
V_9 = F_23 ( V_37 , V_38 , & V_30 , V_31 ) ;
if ( V_9 )
return V_9 ;
if ( V_30 < 0 ||
V_30 > V_22 -> V_33 . V_34 ) {
F_24 ( L_7
L_8 ,
V_22 -> V_33 . V_34 ) ;
return - V_42 ;
}
F_19 ( & V_22 -> V_32 ) ;
V_22 -> V_33 . V_43 = V_30 ;
F_20 ( & V_22 -> V_32 ) ;
return V_38 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_44 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
long V_30 ;
int V_31 ;
F_19 ( & V_22 -> V_32 ) ;
V_30 = V_22 -> V_33 . V_45 ;
F_20 ( & V_22 -> V_32 ) ;
V_31 = 1 << ( 20 - V_35 ) ;
return F_21 ( V_2 , V_30 , V_31 ) ;
}
static T_3 F_28 ( struct V_36 * V_36 ,
const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_31 , V_9 , V_30 ;
V_31 = 1 << ( 20 - V_35 ) ;
V_9 = F_23 ( V_37 , V_38 , & V_30 , V_31 ) ;
if ( V_9 )
return V_9 ;
if ( V_30 < 0 ||
V_30 > V_22 -> V_33 . V_43 ) {
F_24 ( L_9
L_10 ,
V_22 -> V_33 . V_43 >> ( 20 - V_35 ) ) ;
return - V_42 ;
}
F_19 ( & V_22 -> V_32 ) ;
V_22 -> V_33 . V_45 = V_30 ;
F_20 ( & V_22 -> V_32 ) ;
return V_38 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
struct V_46 * V_47 = & V_22 -> V_48 ;
int V_49 = 20 - V_35 ;
int V_50 ;
int V_51 ;
V_50 = V_47 -> V_52 >> V_49 ;
V_51 = F_30 ( & V_47 -> V_53 ) >> V_49 ;
return F_5 ( V_2 ,
L_11
L_12
L_13
L_14
L_15 ,
F_30 ( & V_47 -> V_54 ) ,
V_50 ,
V_50 - V_51 ,
V_51 ,
V_47 -> V_55 ) ;
}
static T_3 F_31 ( struct V_36 * V_36 ,
const char T_6 * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
struct V_46 * V_47 = & V_22 -> V_48 ;
int V_31 , V_9 , V_30 ;
int V_56 = 0 ;
int V_57 = 0 ;
char V_58 [ 128 ] ;
if ( V_38 >= sizeof( V_58 ) )
return - V_59 ;
if ( F_32 ( V_58 , V_37 , V_38 ) )
return - V_60 ;
V_58 [ V_38 ] = 0 ;
V_31 = 1 << ( 20 - V_35 ) ;
V_37 += F_33 ( V_58 , L_16 , & V_38 ) -
V_58 ;
V_9 = F_23 ( V_37 , V_38 , & V_30 , V_31 ) ;
if ( V_9 )
return V_9 ;
if ( V_30 < 0 || V_30 > V_41 ) {
F_24 ( L_17 ,
F_34 ( V_5 , NULL , 0 ) ,
V_41 >> ( 20 - V_35 ) ) ;
return - V_42 ;
}
if ( V_22 -> V_61 == NULL )
return - V_62 ;
F_19 ( & V_22 -> V_32 ) ;
V_56 = V_30 - V_47 -> V_52 ;
F_20 ( & V_22 -> V_32 ) ;
if ( V_56 >= 0 ) {
F_35 ( V_56 , & V_47 -> V_53 ) ;
GOTO ( V_63 , V_9 = 0 ) ;
}
V_56 = - V_56 ;
while ( V_56 > 0 ) {
int V_64 ;
do {
int V_65 , V_66 ;
V_65 = F_30 ( & V_47 -> V_53 ) ;
if ( V_65 == 0 )
break;
V_66 = V_65 > V_56 ? V_65 - V_56 : 0 ;
V_9 = F_36 ( & V_47 -> V_53 , V_65 , V_66 ) ;
if ( F_37 ( V_65 == V_9 ) ) {
V_56 -= V_65 - V_66 ;
V_57 += V_65 - V_66 ;
break;
}
} while ( 1 );
if ( V_56 <= 0 )
break;
V_64 = V_56 << 1 ;
V_9 = F_38 ( NULL , V_22 -> V_61 ,
sizeof( V_67 ) ,
V_67 ,
sizeof( V_64 ) , & V_64 , NULL ) ;
if ( V_9 < 0 )
break;
}
V_63:
if ( V_9 >= 0 ) {
F_19 ( & V_22 -> V_32 ) ;
V_47 -> V_52 = V_30 ;
F_20 ( & V_22 -> V_32 ) ;
V_9 = V_38 ;
} else {
F_35 ( V_57 , & V_47 -> V_53 ) ;
}
return V_9 ;
}
static int F_39 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 , ( V_22 -> V_23 & V_68 ) ? 1 : 0 ) ;
}
static T_3 F_40 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_69 , V_9 ;
if ( ! V_22 -> V_61 )
return - V_70 ;
V_9 = F_41 ( V_37 , V_38 , & V_69 ) ;
if ( V_9 )
return V_9 ;
if ( V_69 )
V_22 -> V_23 |= V_68 ;
else
V_22 -> V_23 &= ~ V_68 ;
V_9 = F_38 ( NULL , V_22 -> V_61 , sizeof( V_71 ) ,
V_71 , sizeof( V_69 ) , & V_69 , NULL ) ;
if ( V_9 )
F_42 ( L_18 , V_9 ) ;
return V_38 ;
}
static int F_43 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_5 ( V_2 , L_19 , F_12 ( V_5 ) -> V_72 ) ;
}
static T_3 F_44 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
int V_9 , V_69 ;
V_9 = F_41 ( V_37 , V_38 , & V_69 ) ;
if ( V_9 )
return V_9 ;
F_12 ( V_5 ) -> V_72 = V_69 ;
return V_38 ;
}
static int F_45 ( struct V_1 * V_2 , enum V_73 type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_12 ( V_5 ) -> V_74 == type ) {
return F_5 ( V_2 , L_20 ,
F_12 ( V_5 ) -> V_75 ) ;
} else if ( F_12 ( V_5 ) -> V_74 == V_76 ) {
return F_5 ( V_2 , L_21 ) ;
} else {
return F_5 ( V_2 , L_22 ) ;
}
}
static int F_46 ( const char * V_37 , unsigned long V_38 , void * V_77 ,
enum V_73 type )
{
struct V_4 * V_5 = V_77 ;
int V_9 , V_78 ;
V_9 = F_41 ( V_37 , V_38 , & V_78 ) ;
if ( V_9 )
return V_9 ;
F_12 ( V_5 ) -> V_75 = V_78 ;
if ( V_78 == 0 )
F_12 ( V_5 ) -> V_74 = V_76 ;
else
F_12 ( V_5 ) -> V_74 = type ;
F_47 ( F_12 ( V_5 ) -> V_79 ) ;
return V_38 ;
}
static int F_48 ( struct V_1 * V_2 , void * V_3 )
{
return F_45 ( V_2 , V_80 ) ;
}
static T_3 F_49 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_1 * V_81 = V_36 -> V_40 ;
return F_46 ( V_37 , V_38 , V_81 -> V_6 , V_80 ) ;
}
static int F_50 ( struct V_1 * V_2 , void * V_3 )
{
return F_45 ( V_2 , V_82 ) ;
}
static T_3 F_51 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_1 * V_81 = V_36 -> V_40 ;
return F_46 ( V_37 , V_38 , V_81 -> V_6 , V_82 ) ;
}
static int F_52 ( struct V_1 * V_2 , void * V_3 )
{
return F_45 ( V_2 , V_83 ) ;
}
static T_3 F_53 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_1 * V_81 = V_36 -> V_40 ;
return F_46 ( V_37 , V_38 , V_81 -> V_6 , V_83 ) ;
}
static int F_54 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 , V_22 -> V_84 ) ;
}
static T_3 F_55 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_69 , V_9 ;
V_9 = F_41 ( V_37 , V_38 , & V_69 ) ;
if ( V_9 )
return V_9 ;
if ( V_69 >= 0 && V_69 <= V_85 )
V_22 -> V_84 = V_69 ;
else
F_24 ( L_23
L_24 , V_69 , V_85 ) ;
return V_38 ;
}
static int F_56 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 ,
V_22 -> V_23 & V_86 ? 1 : 0 ) ;
}
static T_3 F_57 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_69 , V_9 ;
V_9 = F_41 ( V_37 , V_38 , & V_69 ) ;
if ( V_9 )
return V_9 ;
if ( V_69 )
V_22 -> V_23 |= V_86 ;
else
V_22 -> V_23 &= ~ V_86 ;
return V_38 ;
}
static int F_58 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 ,
L_25
L_26
L_27 ,
F_30 ( & V_22 -> V_87 ) ,
F_30 ( & V_22 -> V_88 ) ,
F_30 ( & V_22 -> V_89 ) ) ;
}
static int F_59 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 ,
( V_22 -> V_23 & V_90 ) ? 1 : 0 ) ;
}
static T_3 F_60 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_69 , V_9 ;
V_9 = F_41 ( V_37 , V_38 , & V_69 ) ;
if ( V_9 )
return V_9 ;
if ( V_69 )
V_22 -> V_23 |= V_90 ;
else
V_22 -> V_23 &= ~ V_90 ;
return V_38 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
unsigned int V_91 ;
int V_9 ;
V_9 = F_62 ( V_22 , & V_91 ) ;
if ( V_9 )
return V_9 ;
return F_5 ( V_2 , L_1 , V_91 ) ;
}
static int F_63 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
unsigned int V_91 ;
int V_9 ;
V_9 = F_64 ( V_22 , & V_91 ) ;
if ( V_9 )
return V_9 ;
return F_5 ( V_2 , L_1 , V_91 ) ;
}
static int F_65 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
unsigned int V_92 ;
int V_9 ;
V_9 = F_66 ( V_22 , & V_92 ) ;
if ( V_9 )
return V_9 ;
return F_5 ( V_2 , L_1 , V_92 ) ;
}
static int F_67 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
unsigned int V_92 ;
int V_9 ;
V_9 = F_68 ( V_22 , & V_92 ) ;
if ( V_9 )
return V_9 ;
return F_5 ( V_2 , L_1 , V_92 ) ;
}
static int F_69 ( struct V_1 * V_2 , void * V_3 )
{
const char * V_93 [] = V_94 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_95 = F_12 ( V_5 ) -> V_23 ;
int V_96 = 0 ;
while ( V_95 != 0 ) {
if ( F_70 ( V_93 ) <= V_96 ) {
F_24 ( L_28
L_29 , F_34 ( V_5 , NULL , 0 ) ) ;
return - V_59 ;
}
if ( V_95 & 0x1 )
F_5 ( V_2 , L_30 , V_93 [ V_96 ] ) ;
V_95 >>= 1 ;
++ V_96 ;
}
F_5 ( V_2 , L_31 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_9 ;
V_9 = F_5 ( V_2 , L_1 , V_22 -> V_97 ) ;
return V_9 ;
}
static T_3 F_72 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_1 * V_81 = V_36 -> V_40 ;
struct V_4 * V_5 = V_81 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_69 , V_9 ;
V_9 = F_41 ( V_37 , V_38 , & V_69 ) ;
if ( V_9 )
return V_9 ;
if ( V_69 != 0 && V_69 != 1 )
return - V_42 ;
if ( V_69 == 1 && ! ( V_22 -> V_23 & V_98 ) )
return - V_99 ;
V_22 -> V_97 = V_69 ;
return V_38 ;
}
void F_73 ( struct V_21 * V_22 , int V_100 , int V_38 )
{
if ( ! V_22 -> V_79 )
return;
if ( V_22 -> V_74 == V_76 )
F_74 ( V_22 -> V_79 , V_100 , V_38 ) ;
else if ( V_22 -> V_74 == V_80 &&
V_22 -> V_75 == V_101 -> V_78 )
F_74 ( V_22 -> V_79 , V_100 , V_38 ) ;
else if ( V_22 -> V_74 == V_82 &&
V_22 -> V_75 == V_101 -> V_102 -> V_78 )
F_74 ( V_22 -> V_79 , V_100 , V_38 ) ;
else if ( V_22 -> V_74 == V_83 &&
V_22 -> V_75 ==
F_75 ( & V_103 , F_76 () ) )
F_74 ( V_22 -> V_79 , V_100 , V_38 ) ;
}
int F_77 ( struct V_104 * V_102 ,
struct V_4 * V_5 , char * V_105 , char * V_106 )
{
struct V_107 V_108 [ 2 ] ;
struct V_109 * V_110 = F_78 ( V_5 ) ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
struct V_111 * V_112 ;
struct V_104 * V_113 ;
char V_26 [ V_114 + 1 ] , * V_115 ;
int V_116 , V_117 , V_118 , V_9 ;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
V_26 [ V_114 ] = '\0' ;
V_108 [ 0 ] . V_26 = V_26 ;
F_2 ( V_22 != NULL ) ;
F_2 ( V_106 != NULL ) ;
F_2 ( V_105 != NULL ) ;
V_118 = strlen ( V_110 -> V_119 -> V_120 ) ;
V_115 = strrchr ( V_110 -> V_119 -> V_120 , '-' ) ;
if ( V_115 && ( strcmp ( V_115 , L_32 ) == 0 ) )
V_118 -= 7 ;
snprintf ( V_26 , V_114 , L_33 , V_118 ,
V_110 -> V_119 -> V_120 , V_5 ) ;
V_22 -> V_121 = F_79 ( V_26 , V_102 , NULL , NULL ) ;
if ( F_80 ( V_22 -> V_121 ) ) {
V_116 = F_81 ( V_22 -> V_121 ) ;
V_22 -> V_121 = NULL ;
return V_116 ;
}
V_9 = F_82 ( V_22 -> V_121 , L_34 , 0444 ,
& V_122 , V_22 ) ;
if ( V_9 )
F_42 ( L_35 ) ;
V_9 = F_82 ( V_22 -> V_121 , L_36 , 0644 ,
& V_123 , V_22 ) ;
if ( V_9 )
F_42 ( L_37 ) ;
V_9 = F_82 ( V_22 -> V_121 , L_38 ,
0644 , & V_124 , V_22 ) ;
if ( V_9 )
F_42 ( L_39 ) ;
V_9 = F_82 ( V_22 -> V_121 , L_40 , 0644 ,
& V_125 , V_22 ) ;
if ( V_9 )
F_42 ( L_41 ) ;
V_22 -> V_79 = F_83 ( V_126 ,
V_127 ) ;
if ( V_22 -> V_79 == NULL )
GOTO ( V_63 , V_116 = - V_128 ) ;
for ( V_117 = 0 ; V_117 < V_126 ; V_117 ++ ) {
T_1 type = V_129 [ V_117 ] . type ;
void * V_115 = NULL ;
if ( type & V_130 )
V_115 = L_42 ;
else if ( type & V_131 )
V_115 = L_43 ;
else if ( type & V_132 )
V_115 = L_44 ;
F_84 ( V_22 -> V_79 ,
V_129 [ V_117 ] . V_133 ,
( type & V_134 ) ,
V_129 [ V_117 ] . V_135 , V_115 ) ;
}
V_116 = F_85 ( V_22 -> V_121 , L_45 , V_22 -> V_79 ) ;
if ( V_116 )
GOTO ( V_63 , V_116 ) ;
V_22 -> V_136 = F_83 ( F_70 ( V_137 ) ,
V_127 ) ;
if ( V_22 -> V_136 == NULL )
GOTO ( V_63 , V_116 = - V_128 ) ;
for ( V_117 = 0 ; V_117 < F_70 ( V_137 ) ; V_117 ++ )
F_84 ( V_22 -> V_136 , V_117 , 0 ,
V_137 [ V_117 ] , L_44 ) ;
V_116 = F_85 ( V_22 -> V_121 , L_46 ,
V_22 -> V_136 ) ;
if ( V_116 )
GOTO ( V_63 , V_116 ) ;
V_116 = F_86 ( V_22 -> V_121 , V_138 , V_5 ) ;
if ( V_116 )
GOTO ( V_63 , V_116 ) ;
V_112 = F_87 ( V_106 ) ;
F_2 ( V_112 != NULL ) ;
F_2 ( V_112 -> V_139 == V_140 ) ;
F_2 ( V_112 -> V_141 -> V_142 != NULL ) ;
V_113 = F_88 ( V_112 -> V_141 -> V_142 , V_22 -> V_121 ) ;
if ( V_113 == NULL )
GOTO ( V_63 , V_116 = - V_128 ) ;
snprintf ( V_26 , V_114 , L_47 ) ;
V_108 [ 0 ] . V_143 = & V_144 ;
V_116 = F_86 ( V_113 , V_108 , V_112 ) ;
if ( V_116 )
GOTO ( V_63 , V_116 ) ;
snprintf ( V_26 , V_114 , L_48 ) ;
V_108 [ 0 ] . V_143 = & V_145 ;
V_116 = F_86 ( V_113 , V_108 , V_112 ) ;
if ( V_116 )
GOTO ( V_63 , V_116 ) ;
V_112 = F_87 ( V_105 ) ;
F_2 ( V_112 != NULL ) ;
F_2 ( V_112 -> V_139 == V_140 ) ;
F_2 ( V_112 -> V_141 -> V_142 != NULL ) ;
V_113 = F_88 ( V_112 -> V_141 -> V_142 , V_22 -> V_121 ) ;
if ( V_113 == NULL )
GOTO ( V_63 , V_116 = - V_128 ) ;
snprintf ( V_26 , V_114 , L_47 ) ;
V_108 [ 0 ] . V_143 = & V_144 ;
V_116 = F_86 ( V_113 , V_108 , V_112 ) ;
if ( V_116 )
GOTO ( V_63 , V_116 ) ;
snprintf ( V_26 , V_114 , L_48 ) ;
V_108 [ 0 ] . V_143 = & V_145 ;
V_116 = F_86 ( V_113 , V_108 , V_112 ) ;
V_63:
if ( V_116 ) {
F_89 ( & V_22 -> V_121 ) ;
F_90 ( & V_22 -> V_136 ) ;
F_90 ( & V_22 -> V_79 ) ;
}
return V_116 ;
}
void F_91 ( struct V_21 * V_22 )
{
if ( V_22 -> V_121 ) {
F_89 ( & V_22 -> V_121 ) ;
F_90 ( & V_22 -> V_136 ) ;
F_90 ( & V_22 -> V_79 ) ;
}
}
static void F_92 ( struct V_146 * V_147 ,
struct V_1 * V_81 , int V_148 )
{
unsigned long V_149 = 0 , V_150 = 0 , V_151 , V_152 ;
unsigned long V_153 , V_154 , V_155 , V_156 ;
char * V_157 = L_49 ;
int V_96 , V_158 = 10 ;
struct V_159 * V_160 = & V_147 -> V_161 [ V_148 ] ;
V_151 = 0 ;
V_152 = 0 ;
V_153 = 0 ;
for( V_96 = 0 ; V_96 < V_162 ; V_96 ++ ) {
V_149 += V_160 -> V_163 . V_164 [ V_96 ] ;
V_150 += V_160 -> V_165 . V_164 [ V_96 ] ;
}
for( V_96 = 0 ; V_96 < V_162 ; V_96 ++ ) {
V_155 = V_160 -> V_163 . V_164 [ V_96 ] ;
V_156 = V_160 -> V_165 . V_164 [ V_96 ] ;
V_151 += V_155 ;
V_152 += V_156 ;
V_154 = 1 << ( V_96 + V_166 - V_158 ) ;
F_5 ( V_81 , L_50
L_51 , V_153 , * V_157 , V_154 , * V_157 ,
( V_96 == V_162 - 1 ) ? '+' : ' ' ,
V_155 , F_93 ( V_155 , V_149 ) , F_93 ( V_151 , V_149 ) ,
V_156 , F_93 ( V_156 , V_150 ) , F_93 ( V_152 , V_150 ) ) ;
V_153 = V_154 ;
if ( V_153 == 1 << 10 ) {
V_153 = 1 ;
V_158 += 10 ;
V_157 ++ ;
}
if ( V_151 == V_149 && V_152 == V_150 )
break;
}
}
static int F_94 ( struct V_1 * V_81 , void * V_3 )
{
struct V_167 V_168 ;
struct V_21 * V_22 = V_81 -> V_6 ;
struct V_146 * V_147 = & V_22 -> V_146 ;
int V_169 ;
F_95 ( & V_168 ) ;
if ( ! V_22 -> V_170 ) {
F_5 ( V_81 , L_52
L_53
L_54 ) ;
return 0 ;
}
F_5 ( V_81 , L_55 ,
V_168 . V_171 , ( unsigned long ) V_168 . V_172 ) ;
F_5 ( V_81 , L_56 , L_57 , L_58 , L_59 ) ;
F_5 ( V_81 , L_60 ,
L_61 , L_62 , L_63 , L_64 ,
L_62 , L_63 , L_64 ) ;
F_19 ( & V_22 -> V_173 ) ;
for ( V_169 = 0 ; V_169 < V_174 ; V_169 ++ ) {
if ( V_147 -> V_161 [ V_169 ] . V_78 != 0 ) {
F_5 ( V_81 , L_65 ,
V_147 -> V_161 [ V_169 ] . V_78 ) ;
F_92 ( V_147 , V_81 , V_169 ) ;
}
}
F_20 ( & V_22 -> V_173 ) ;
return 0 ;
}
static T_3 F_96 ( struct V_36 * V_36 ,
const char T_6 * V_175 ,
T_4 V_118 ,
T_5 * V_39 )
{
struct V_1 * V_81 = V_36 -> V_40 ;
struct V_21 * V_22 = V_81 -> V_6 ;
struct V_146 * V_147 = & V_22 -> V_146 ;
int V_96 ;
int V_176 = 1 , V_9 = 0 ;
if ( V_118 == 0 )
return - V_59 ;
V_9 = F_41 ( V_175 , V_118 , & V_176 ) ;
if ( V_9 < 0 && V_118 < 16 ) {
char V_58 [ 16 ] ;
if ( F_32 ( V_58 , V_175 , V_118 ) )
return - V_60 ;
V_58 [ V_118 ] = 0 ;
if ( V_58 [ V_118 - 1 ] == '\n' )
V_58 [ V_118 - 1 ] = 0 ;
if ( strcmp ( V_58 , L_66 ) == 0 ||
strcmp ( V_58 , L_67 ) == 0 )
V_176 = 0 ;
}
if ( V_176 == 0 )
V_22 -> V_170 = 0 ;
else
V_22 -> V_170 = 1 ;
F_19 ( & V_22 -> V_173 ) ;
for ( V_96 = 0 ; V_96 < V_174 ; V_96 ++ ) {
V_147 -> V_161 [ V_96 ] . V_78 = 0 ;
F_97 ( & V_147 -> V_161 [ V_96 ] . V_163 ) ;
F_97 ( & V_147 -> V_161 [ V_96 ] . V_165 ) ;
}
F_20 ( & V_22 -> V_173 ) ;
return V_118 ;
}
static int F_98 ( struct V_1 * V_81 , void * V_3 )
{
struct V_167 V_168 ;
struct V_21 * V_22 = V_81 -> V_6 ;
struct V_146 * V_147 = & V_22 -> V_146 ;
F_95 ( & V_168 ) ;
if ( ! V_22 -> V_170 ) {
F_5 ( V_81 , L_52
L_53
L_54 ) ;
return 0 ;
}
F_5 ( V_81 , L_55 ,
V_168 . V_171 , ( unsigned long ) V_168 . V_172 ) ;
F_5 ( V_81 , L_56 , L_57 , L_58 , L_59 ) ;
F_5 ( V_81 , L_60 ,
L_61 , L_62 , L_63 , L_64 ,
L_62 , L_63 , L_64 ) ;
F_19 ( & V_22 -> V_32 ) ;
F_92 ( V_147 , V_81 , V_174 ) ;
F_20 ( & V_22 -> V_32 ) ;
return 0 ;
}
static T_3 F_99 ( struct V_36 * V_36 ,
const char T_6 * V_175 ,
T_4 V_118 , T_5 * V_39 )
{
struct V_1 * V_81 = V_36 -> V_40 ;
struct V_21 * V_22 = V_81 -> V_6 ;
struct V_146 * V_147 = & V_22 -> V_146 ;
int V_96 ;
int V_176 = 1 , V_9 = 0 ;
if ( V_118 == 0 )
return - V_59 ;
V_9 = F_41 ( V_175 , V_118 , & V_176 ) ;
if ( V_9 < 0 && V_118 < 16 ) {
char V_58 [ 16 ] ;
if ( F_32 ( V_58 , V_175 , V_118 ) )
return - V_60 ;
V_58 [ V_118 ] = 0 ;
if ( V_58 [ V_118 - 1 ] == '\n' )
V_58 [ V_118 - 1 ] = 0 ;
if ( strcmp ( V_58 , L_66 ) == 0 ||
strcmp ( V_58 , L_67 ) == 0 )
V_176 = 0 ;
}
if ( V_176 == 0 )
V_22 -> V_170 = 0 ;
else
V_22 -> V_170 = 1 ;
F_19 ( & V_22 -> V_173 ) ;
for ( V_96 = 0 ; V_96 <= V_174 ; V_96 ++ ) {
V_147 -> V_161 [ V_96 ] . V_78 = 0 ;
F_97 ( & V_147 -> V_161 [ V_96 ] . V_163 ) ;
F_97 ( & V_147 -> V_161 [ V_96 ] . V_165 ) ;
}
F_20 ( & V_22 -> V_173 ) ;
return V_118 ;
}
void F_100 ( struct V_21 * V_22 , T_7 V_78 ,
struct V_177 * V_36 , T_5 V_178 ,
T_4 V_38 , int V_179 )
{
int V_96 , V_180 = - 1 ;
struct V_181 * V_182 ;
struct V_181 * V_183 ;
int * V_184 = & V_22 -> V_185 ;
int * V_186 = & V_22 -> V_187 ;
struct V_146 * V_147 = & V_22 -> V_146 ;
if( ! V_22 -> V_170 )
return;
V_182 = V_22 -> V_181 ;
V_183 = V_22 -> V_188 ;
F_19 ( & V_22 -> V_173 ) ;
for( V_96 = 0 ; V_96 < V_174 ; V_96 ++ ) {
if( V_147 -> V_161 [ V_96 ] . V_78 == V_78 ) {
V_180 = V_96 ;
break;
}
}
if ( V_180 == - 1 ) {
V_22 -> V_189 =
( V_22 -> V_189 + 1 ) % V_174 ;
V_180 = V_22 -> V_189 ;
V_147 -> V_161 [ V_180 ] . V_78 = V_78 ;
F_97 ( & V_147 -> V_161 [ V_180 ] . V_163 ) ;
F_97 ( & V_147 -> V_161 [ V_180 ] . V_165 ) ;
}
for( V_96 = 0 ; ( V_38 >= ( 1 << V_166 << V_96 ) ) &&
( V_96 < ( V_162 - 1 ) ) ; V_96 ++ ) ;
if ( V_179 == 0 ) {
V_147 -> V_161 [ V_180 ] . V_163 . V_164 [ V_96 ] ++ ;
V_147 -> V_161 [ V_174 ] . V_163 . V_164 [ V_96 ] ++ ;
} else {
V_147 -> V_161 [ V_180 ] . V_165 . V_164 [ V_96 ] ++ ;
V_147 -> V_161 [ V_174 ] . V_165 . V_164 [ V_96 ] ++ ;
}
F_20 ( & V_22 -> V_173 ) ;
F_19 ( & V_22 -> V_190 ) ;
for ( V_96 = 0 ; V_96 < V_174 ; V_96 ++ ) {
if ( V_182 [ V_96 ] . V_191 == V_78 ) {
if ( V_182 [ V_96 ] . V_192 != V_36 ) {
V_182 [ V_96 ] . V_193 = V_178 ;
V_182 [ V_96 ] . V_194 = V_178 + V_38 ;
V_182 [ V_96 ] . V_195 = V_38 ;
V_182 [ V_96 ] . V_196 = V_38 ;
V_182 [ V_96 ] . V_197 = 0 ;
V_182 [ V_96 ] . V_192 = V_36 ;
F_20 ( & V_22 -> V_190 ) ;
return;
}
if ( V_182 [ V_96 ] . V_194 != V_178 ) {
* V_184 =
( * V_184 + 1 ) % V_198 ;
V_183 [ * V_184 ] . V_199 = V_182 [ V_96 ] . V_199 ;
V_183 [ * V_184 ] . V_191 = V_78 ;
V_183 [ * V_184 ] . V_193 =
V_182 [ V_96 ] . V_193 ;
V_183 [ * V_184 ] . V_200 =
V_182 [ V_96 ] . V_194 ;
V_183 [ * V_184 ] . V_195 =
V_182 [ V_96 ] . V_195 ;
V_183 [ * V_184 ] . V_196 =
V_182 [ V_96 ] . V_196 ;
V_183 [ * V_184 ] . V_197 =
V_182 [ V_96 ] . V_197 ;
V_182 [ V_96 ] . V_199 = V_179 ;
V_182 [ V_96 ] . V_193 = V_178 ;
V_182 [ V_96 ] . V_195 = V_38 ;
V_182 [ V_96 ] . V_196 = V_38 ;
V_182 [ V_96 ] . V_197 = V_178 -
V_182 [ V_96 ] . V_194 ;
}
if( V_182 [ V_96 ] . V_195 > V_38 )
V_182 [ V_96 ] . V_195 = V_38 ;
if( V_182 [ V_96 ] . V_196 < V_38 )
V_182 [ V_96 ] . V_196 = V_38 ;
V_182 [ V_96 ] . V_194 = V_178 + V_38 ;
F_20 ( & V_22 -> V_190 ) ;
return;
}
}
* V_186 = ( * V_186 + 1 ) % V_174 ;
V_182 [ * V_186 ] . V_191 = V_78 ;
V_182 [ * V_186 ] . V_199 = V_179 ;
V_182 [ * V_186 ] . V_193 = V_178 ;
V_182 [ * V_186 ] . V_194 = V_178 + V_38 ;
V_182 [ * V_186 ] . V_195 = V_38 ;
V_182 [ * V_186 ] . V_196 = V_38 ;
V_182 [ * V_186 ] . V_197 = 0 ;
V_182 [ * V_186 ] . V_192 = V_36 ;
F_20 ( & V_22 -> V_190 ) ;
}
static int F_101 ( struct V_1 * V_81 , void * V_3 )
{
struct V_167 V_168 ;
struct V_21 * V_22 = V_81 -> V_6 ;
struct V_181 * V_183 = V_22 -> V_188 ;
struct V_181 * V_182 = V_22 -> V_181 ;
int V_96 ;
F_95 ( & V_168 ) ;
if ( ! V_22 -> V_170 ) {
F_5 ( V_81 , L_52
L_53
L_54 ) ;
return 0 ;
}
F_19 ( & V_22 -> V_190 ) ;
F_5 ( V_81 , L_55 ,
V_168 . V_171 , ( unsigned long ) V_168 . V_172 ) ;
F_5 ( V_81 , L_68 ,
L_69 , L_70 , L_71 , L_72 ,
L_73 , L_74 , L_75 ) ;
for( V_96 = 0 ; V_96 < V_198 ; V_96 ++ ) {
if ( V_183 [ V_96 ] . V_191 != 0 )
F_5 ( V_81 ,
L_76 ,
V_183 [ V_96 ] . V_199 == V_201 ? 'R' : 'W' ,
V_183 [ V_96 ] . V_191 ,
V_183 [ V_96 ] . V_193 ,
V_183 [ V_96 ] . V_200 ,
( unsigned long ) V_183 [ V_96 ] . V_195 ,
( unsigned long ) V_183 [ V_96 ] . V_196 ,
V_183 [ V_96 ] . V_197 ) ;
}
for( V_96 = 0 ; V_96 < V_174 ; V_96 ++ ) {
if ( V_182 [ V_96 ] . V_191 != 0 )
F_5 ( V_81 ,
L_76 ,
V_182 [ V_96 ] . V_199 == V_201 ? 'R' : 'W' ,
V_182 [ V_96 ] . V_191 ,
V_182 [ V_96 ] . V_193 ,
V_182 [ V_96 ] . V_194 ,
( unsigned long ) V_182 [ V_96 ] . V_195 ,
( unsigned long ) V_182 [ V_96 ] . V_196 ,
V_182 [ V_96 ] . V_197 ) ;
}
F_20 ( & V_22 -> V_190 ) ;
return 0 ;
}
static T_3 F_102 ( struct V_36 * V_36 ,
const char T_6 * V_175 ,
T_4 V_118 , T_5 * V_39 )
{
struct V_1 * V_81 = V_36 -> V_40 ;
struct V_21 * V_22 = V_81 -> V_6 ;
struct V_181 * V_202 = V_22 -> V_181 ;
struct V_181 * V_203 = V_22 -> V_188 ;
int V_176 = 1 , V_9 = 0 ;
if ( V_118 == 0 )
return - V_59 ;
V_9 = F_41 ( V_175 , V_118 , & V_176 ) ;
if ( V_9 < 0 && V_118 < 16 ) {
char V_58 [ 16 ] ;
if ( F_32 ( V_58 , V_175 , V_118 ) )
return - V_60 ;
V_58 [ V_118 ] = 0 ;
if ( V_58 [ V_118 - 1 ] == '\n' )
V_58 [ V_118 - 1 ] = 0 ;
if ( strcmp ( V_58 , L_66 ) == 0 ||
strcmp ( V_58 , L_67 ) == 0 )
V_176 = 0 ;
}
if ( V_176 == 0 )
V_22 -> V_170 = 0 ;
else
V_22 -> V_170 = 1 ;
F_19 ( & V_22 -> V_190 ) ;
V_22 -> V_187 = 0 ;
V_22 -> V_185 = 0 ;
memset ( V_202 , 0 , sizeof( struct V_181 ) *
V_174 ) ;
memset ( V_203 , 0 , sizeof( struct V_181 ) *
V_198 ) ;
F_20 ( & V_22 -> V_190 ) ;
return V_118 ;
}
void F_103 ( struct V_204 * V_108 )
{
V_108 -> V_205 = NULL ;
V_108 -> V_206 = V_138 ;
}
