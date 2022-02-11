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
static T_3 F_31 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
struct V_46 * V_47 = & V_22 -> V_48 ;
int V_31 , V_9 , V_30 ;
int V_56 = 0 ;
int V_57 = 0 ;
V_31 = 1 << ( 20 - V_35 ) ;
V_37 = F_32 ( V_37 , L_16 , & V_38 ) ;
V_9 = F_23 ( V_37 , V_38 , & V_30 , V_31 ) ;
if ( V_9 )
return V_9 ;
if ( V_30 < 0 || V_30 > V_41 ) {
F_24 ( L_17 ,
F_33 ( V_5 , NULL , 0 ) ,
V_41 >> ( 20 - V_35 ) ) ;
return - V_42 ;
}
if ( V_22 -> V_58 == NULL )
return - V_59 ;
F_19 ( & V_22 -> V_32 ) ;
V_56 = V_30 - V_47 -> V_52 ;
F_20 ( & V_22 -> V_32 ) ;
if ( V_56 >= 0 ) {
F_34 ( V_56 , & V_47 -> V_53 ) ;
GOTO ( V_60 , V_9 = 0 ) ;
}
V_56 = - V_56 ;
while ( V_56 > 0 ) {
int V_61 ;
do {
int V_62 , V_63 ;
V_62 = F_30 ( & V_47 -> V_53 ) ;
if ( V_62 == 0 )
break;
V_63 = V_62 > V_56 ? V_62 - V_56 : 0 ;
V_9 = F_35 ( & V_47 -> V_53 , V_62 , V_63 ) ;
if ( F_36 ( V_62 == V_9 ) ) {
V_56 -= V_62 - V_63 ;
V_57 += V_62 - V_63 ;
break;
}
} while ( 1 );
if ( V_56 <= 0 )
break;
V_61 = V_56 << 1 ;
V_9 = F_37 ( NULL , V_22 -> V_58 ,
sizeof( V_64 ) ,
V_64 ,
sizeof( V_61 ) , & V_61 , NULL ) ;
if ( V_9 < 0 )
break;
}
V_60:
if ( V_9 >= 0 ) {
F_19 ( & V_22 -> V_32 ) ;
V_47 -> V_52 = V_30 ;
F_20 ( & V_22 -> V_32 ) ;
V_9 = V_38 ;
} else {
F_34 ( V_57 , & V_47 -> V_53 ) ;
}
return V_9 ;
}
static int F_38 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 , ( V_22 -> V_23 & V_65 ) ? 1 : 0 ) ;
}
static T_3 F_39 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_66 , V_9 ;
if ( ! V_22 -> V_58 )
return - V_67 ;
V_9 = F_40 ( V_37 , V_38 , & V_66 ) ;
if ( V_9 )
return V_9 ;
if ( V_66 )
V_22 -> V_23 |= V_65 ;
else
V_22 -> V_23 &= ~ V_65 ;
V_9 = F_37 ( NULL , V_22 -> V_58 , sizeof( V_68 ) ,
V_68 , sizeof( V_66 ) , & V_66 , NULL ) ;
if ( V_9 )
F_41 ( L_18 , V_9 ) ;
return V_38 ;
}
static int F_42 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_5 ( V_2 , L_19 , F_12 ( V_5 ) -> V_69 ) ;
}
static T_3 F_43 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
int V_9 , V_66 ;
V_9 = F_40 ( V_37 , V_38 , & V_66 ) ;
if ( V_9 )
return V_9 ;
F_12 ( V_5 ) -> V_69 = V_66 ;
return V_38 ;
}
static int F_44 ( struct V_1 * V_2 , enum V_70 type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( F_12 ( V_5 ) -> V_71 == type ) {
return F_5 ( V_2 , L_20 ,
F_12 ( V_5 ) -> V_72 ) ;
} else if ( F_12 ( V_5 ) -> V_71 == V_73 ) {
return F_5 ( V_2 , L_21 ) ;
} else {
return F_5 ( V_2 , L_22 ) ;
}
}
static int F_45 ( const char * V_37 , unsigned long V_38 , void * V_74 ,
enum V_70 type )
{
struct V_4 * V_5 = V_74 ;
int V_9 , V_75 ;
V_9 = F_40 ( V_37 , V_38 , & V_75 ) ;
if ( V_9 )
return V_9 ;
F_12 ( V_5 ) -> V_72 = V_75 ;
if ( V_75 == 0 )
F_12 ( V_5 ) -> V_71 = V_73 ;
else
F_12 ( V_5 ) -> V_71 = type ;
F_46 ( F_12 ( V_5 ) -> V_76 ) ;
return V_38 ;
}
static int F_47 ( struct V_1 * V_2 , void * V_3 )
{
return F_44 ( V_2 , V_77 ) ;
}
static T_3 F_48 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_1 * V_78 = V_36 -> V_40 ;
return F_45 ( V_37 , V_38 , V_78 -> V_6 , V_77 ) ;
}
static int F_49 ( struct V_1 * V_2 , void * V_3 )
{
return F_44 ( V_2 , V_79 ) ;
}
static T_3 F_50 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_1 * V_78 = V_36 -> V_40 ;
return F_45 ( V_37 , V_38 , V_78 -> V_6 , V_79 ) ;
}
static int F_51 ( struct V_1 * V_2 , void * V_3 )
{
return F_44 ( V_2 , V_80 ) ;
}
static T_3 F_52 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_1 * V_78 = V_36 -> V_40 ;
return F_45 ( V_37 , V_38 , V_78 -> V_6 , V_80 ) ;
}
static int F_53 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 , V_22 -> V_81 ) ;
}
static T_3 F_54 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_66 , V_9 ;
V_9 = F_40 ( V_37 , V_38 , & V_66 ) ;
if ( V_9 )
return V_9 ;
if ( V_66 >= 0 && V_66 <= V_82 )
V_22 -> V_81 = V_66 ;
else
F_24 ( L_23
L_24 , V_66 , V_82 ) ;
return V_38 ;
}
static int F_55 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 ,
V_22 -> V_23 & V_83 ? 1 : 0 ) ;
}
static T_3 F_56 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_66 , V_9 ;
V_9 = F_40 ( V_37 , V_38 , & V_66 ) ;
if ( V_9 )
return V_9 ;
if ( V_66 )
V_22 -> V_23 |= V_83 ;
else
V_22 -> V_23 &= ~ V_83 ;
return V_38 ;
}
static int F_57 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 ,
L_25
L_26
L_27 ,
F_30 ( & V_22 -> V_84 ) ,
F_30 ( & V_22 -> V_85 ) ,
F_30 ( & V_22 -> V_86 ) ) ;
}
static int F_58 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
return F_5 ( V_2 , L_1 ,
( V_22 -> V_23 & V_87 ) ? 1 : 0 ) ;
}
static T_3 F_59 ( struct V_36 * V_36 , const char * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_36 -> V_40 ) -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
int V_66 , V_9 ;
V_9 = F_40 ( V_37 , V_38 , & V_66 ) ;
if ( V_9 )
return V_9 ;
if ( V_66 )
V_22 -> V_23 |= V_87 ;
else
V_22 -> V_23 &= ~ V_87 ;
return V_38 ;
}
static int F_60 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
unsigned int V_88 ;
int V_9 ;
V_9 = F_61 ( V_22 , & V_88 ) ;
if ( V_9 )
return V_9 ;
return F_5 ( V_2 , L_1 , V_88 ) ;
}
static int F_62 ( struct V_1 * V_2 , void * V_3 )
{
const char * V_89 [] = V_90 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_91 = F_12 ( V_5 ) -> V_23 ;
int V_92 = 0 ;
while ( V_91 != 0 ) {
if ( F_63 ( V_89 ) <= V_92 ) {
F_24 ( L_28
L_29 , F_33 ( V_5 , NULL , 0 ) ) ;
return - V_93 ;
}
if ( V_91 & 0x1 )
F_5 ( V_2 , L_30 , V_89 [ V_92 ] ) ;
V_91 >>= 1 ;
++ V_92 ;
}
F_5 ( V_2 , L_31 ) ;
return 0 ;
}
void F_64 ( struct V_21 * V_22 , int V_94 , int V_38 )
{
if ( ! V_22 -> V_76 )
return;
if ( V_22 -> V_71 == V_73 )
F_65 ( V_22 -> V_76 , V_94 , V_38 ) ;
else if ( V_22 -> V_71 == V_77 &&
V_22 -> V_72 == V_95 -> V_75 )
F_65 ( V_22 -> V_76 , V_94 , V_38 ) ;
else if ( V_22 -> V_71 == V_79 &&
V_22 -> V_72 == V_95 -> V_96 -> V_75 )
F_65 ( V_22 -> V_76 , V_94 , V_38 ) ;
else if ( V_22 -> V_71 == V_80 &&
V_22 -> V_72 ==
F_66 ( & V_97 , F_67 () ) )
F_65 ( V_22 -> V_76 , V_94 , V_38 ) ;
}
int F_68 ( struct V_98 * V_96 ,
struct V_4 * V_5 , char * V_99 , char * V_100 )
{
struct V_101 V_102 [ 2 ] ;
struct V_103 * V_104 = F_69 ( V_5 ) ;
struct V_21 * V_22 = F_12 ( V_5 ) ;
struct V_105 * V_106 ;
struct V_98 * V_107 ;
char V_26 [ V_108 + 1 ] , * V_109 ;
int V_110 , V_111 , V_112 , V_9 ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
V_26 [ V_108 ] = '\0' ;
V_102 [ 0 ] . V_26 = V_26 ;
F_2 ( V_22 != NULL ) ;
F_2 ( V_100 != NULL ) ;
F_2 ( V_99 != NULL ) ;
V_112 = strlen ( V_104 -> V_113 -> V_114 ) ;
V_109 = strrchr ( V_104 -> V_113 -> V_114 , '-' ) ;
if ( V_109 && ( strcmp ( V_109 , L_32 ) == 0 ) )
V_112 -= 7 ;
snprintf ( V_26 , V_108 , L_33 , V_112 ,
V_104 -> V_113 -> V_114 , V_5 ) ;
V_22 -> V_115 = F_70 ( V_26 , V_96 , NULL , NULL ) ;
if ( F_71 ( V_22 -> V_115 ) ) {
V_110 = F_72 ( V_22 -> V_115 ) ;
V_22 -> V_115 = NULL ;
return V_110 ;
}
V_9 = F_73 ( V_22 -> V_115 , L_34 , 0444 ,
& V_116 , V_22 ) ;
if ( V_9 )
F_41 ( L_35 ) ;
V_9 = F_73 ( V_22 -> V_115 , L_36 , 0644 ,
& V_117 , V_22 ) ;
if ( V_9 )
F_41 ( L_37 ) ;
V_9 = F_73 ( V_22 -> V_115 , L_38 ,
0644 , & V_118 , V_22 ) ;
if ( V_9 )
F_41 ( L_39 ) ;
V_9 = F_73 ( V_22 -> V_115 , L_40 , 0644 ,
& V_119 , V_22 ) ;
if ( V_9 )
F_41 ( L_41 ) ;
V_22 -> V_76 = F_74 ( V_120 ,
V_121 ) ;
if ( V_22 -> V_76 == NULL )
GOTO ( V_60 , V_110 = - V_122 ) ;
for ( V_111 = 0 ; V_111 < V_120 ; V_111 ++ ) {
T_1 type = V_123 [ V_111 ] . type ;
void * V_109 = NULL ;
if ( type & V_124 )
V_109 = L_42 ;
else if ( type & V_125 )
V_109 = L_43 ;
else if ( type & V_126 )
V_109 = L_44 ;
F_75 ( V_22 -> V_76 ,
V_123 [ V_111 ] . V_127 ,
( type & V_128 ) ,
V_123 [ V_111 ] . V_129 , V_109 ) ;
}
V_110 = F_76 ( V_22 -> V_115 , L_45 , V_22 -> V_76 ) ;
if ( V_110 )
GOTO ( V_60 , V_110 ) ;
V_22 -> V_130 = F_74 ( F_63 ( V_131 ) ,
V_121 ) ;
if ( V_22 -> V_130 == NULL )
GOTO ( V_60 , V_110 = - V_122 ) ;
for ( V_111 = 0 ; V_111 < F_63 ( V_131 ) ; V_111 ++ )
F_75 ( V_22 -> V_130 , V_111 , 0 ,
V_131 [ V_111 ] , L_44 ) ;
V_110 = F_76 ( V_22 -> V_115 , L_46 ,
V_22 -> V_130 ) ;
if ( V_110 )
GOTO ( V_60 , V_110 ) ;
V_110 = F_77 ( V_22 -> V_115 , V_132 , V_5 ) ;
if ( V_110 )
GOTO ( V_60 , V_110 ) ;
V_106 = F_78 ( V_100 ) ;
F_2 ( V_106 != NULL ) ;
F_2 ( V_106 -> V_133 == V_134 ) ;
F_2 ( V_106 -> V_135 -> V_136 != NULL ) ;
V_107 = F_79 ( V_106 -> V_135 -> V_136 , V_22 -> V_115 ) ;
if ( V_107 == NULL )
GOTO ( V_60 , V_110 = - V_122 ) ;
snprintf ( V_26 , V_108 , L_47 ) ;
V_102 [ 0 ] . V_137 = & V_138 ;
V_110 = F_77 ( V_107 , V_102 , V_106 ) ;
if ( V_110 )
GOTO ( V_60 , V_110 ) ;
snprintf ( V_26 , V_108 , L_48 ) ;
V_102 [ 0 ] . V_137 = & V_139 ;
V_110 = F_77 ( V_107 , V_102 , V_106 ) ;
if ( V_110 )
GOTO ( V_60 , V_110 ) ;
V_106 = F_78 ( V_99 ) ;
F_2 ( V_106 != NULL ) ;
F_2 ( V_106 -> V_133 == V_134 ) ;
F_2 ( V_106 -> V_135 -> V_136 != NULL ) ;
V_107 = F_79 ( V_106 -> V_135 -> V_136 , V_22 -> V_115 ) ;
if ( V_107 == NULL )
GOTO ( V_60 , V_110 = - V_122 ) ;
snprintf ( V_26 , V_108 , L_47 ) ;
V_102 [ 0 ] . V_137 = & V_138 ;
V_110 = F_77 ( V_107 , V_102 , V_106 ) ;
if ( V_110 )
GOTO ( V_60 , V_110 ) ;
snprintf ( V_26 , V_108 , L_48 ) ;
V_102 [ 0 ] . V_137 = & V_139 ;
V_110 = F_77 ( V_107 , V_102 , V_106 ) ;
V_60:
if ( V_110 ) {
F_80 ( & V_22 -> V_115 ) ;
F_81 ( & V_22 -> V_130 ) ;
F_81 ( & V_22 -> V_76 ) ;
}
return V_110 ;
}
void F_82 ( struct V_21 * V_22 )
{
if ( V_22 -> V_115 ) {
F_80 ( & V_22 -> V_115 ) ;
F_81 ( & V_22 -> V_130 ) ;
F_81 ( & V_22 -> V_76 ) ;
}
}
static void F_83 ( struct V_140 * V_141 ,
struct V_1 * V_78 , int V_142 )
{
unsigned long V_143 = 0 , V_144 = 0 , V_145 , V_146 ;
unsigned long V_147 , V_148 , V_149 , V_150 ;
char * V_151 = L_49 ;
int V_92 , V_152 = 10 ;
struct V_153 * V_154 = & V_141 -> V_155 [ V_142 ] ;
V_145 = 0 ;
V_146 = 0 ;
V_147 = 0 ;
for( V_92 = 0 ; V_92 < V_156 ; V_92 ++ ) {
V_143 += V_154 -> V_157 . V_158 [ V_92 ] ;
V_144 += V_154 -> V_159 . V_158 [ V_92 ] ;
}
for( V_92 = 0 ; V_92 < V_156 ; V_92 ++ ) {
V_149 = V_154 -> V_157 . V_158 [ V_92 ] ;
V_150 = V_154 -> V_159 . V_158 [ V_92 ] ;
V_145 += V_149 ;
V_146 += V_150 ;
V_148 = 1 << ( V_92 + V_160 - V_152 ) ;
F_5 ( V_78 , L_50
L_51 , V_147 , * V_151 , V_148 , * V_151 ,
( V_92 == V_156 - 1 ) ? '+' : ' ' ,
V_149 , F_84 ( V_149 , V_143 ) , F_84 ( V_145 , V_143 ) ,
V_150 , F_84 ( V_150 , V_144 ) , F_84 ( V_146 , V_144 ) ) ;
V_147 = V_148 ;
if ( V_147 == 1 << 10 ) {
V_147 = 1 ;
V_152 += 10 ;
V_151 ++ ;
}
if ( V_145 == V_143 && V_146 == V_144 )
break;
}
}
static int F_85 ( struct V_1 * V_78 , void * V_3 )
{
struct V_161 V_162 ;
struct V_21 * V_22 = V_78 -> V_6 ;
struct V_140 * V_141 = & V_22 -> V_140 ;
int V_163 ;
F_86 ( & V_162 ) ;
if ( ! V_22 -> V_164 ) {
F_5 ( V_78 , L_52
L_53
L_54 ) ;
return 0 ;
}
F_5 ( V_78 , L_55 ,
V_162 . V_165 , V_162 . V_166 ) ;
F_5 ( V_78 , L_56 , L_57 , L_58 , L_59 ) ;
F_5 ( V_78 , L_60 ,
L_61 , L_62 , L_63 , L_64 ,
L_62 , L_63 , L_64 ) ;
F_19 ( & V_22 -> V_167 ) ;
for ( V_163 = 0 ; V_163 < V_168 ; V_163 ++ ) {
if ( V_141 -> V_155 [ V_163 ] . V_75 != 0 ) {
F_5 ( V_78 , L_65 ,
V_141 -> V_155 [ V_163 ] . V_75 ) ;
F_83 ( V_141 , V_78 , V_163 ) ;
}
}
F_20 ( & V_22 -> V_167 ) ;
return 0 ;
}
static T_3 F_87 ( struct V_36 * V_36 ,
const char * V_169 , T_4 V_112 ,
T_5 * V_39 )
{
struct V_1 * V_78 = V_36 -> V_40 ;
struct V_21 * V_22 = V_78 -> V_6 ;
struct V_140 * V_141 = & V_22 -> V_140 ;
int V_92 ;
int V_170 = 1 , V_9 = 0 ;
V_9 = F_40 ( V_169 , V_112 , & V_170 ) ;
if ( V_9 < 0 && ( strcmp ( V_169 , L_66 ) == 0 ||
strcmp ( V_169 , L_67 ) == 0 ) )
V_170 = 0 ;
if ( V_170 == 0 )
V_22 -> V_164 = 0 ;
else
V_22 -> V_164 = 1 ;
F_19 ( & V_22 -> V_167 ) ;
for ( V_92 = 0 ; V_92 < V_168 ; V_92 ++ ) {
V_141 -> V_155 [ V_92 ] . V_75 = 0 ;
F_88 ( & V_141 -> V_155 [ V_92 ] . V_157 ) ;
F_88 ( & V_141 -> V_155 [ V_92 ] . V_159 ) ;
}
F_20 ( & V_22 -> V_167 ) ;
return V_112 ;
}
static int F_89 ( struct V_1 * V_78 , void * V_3 )
{
struct V_161 V_162 ;
struct V_21 * V_22 = V_78 -> V_6 ;
struct V_140 * V_141 = & V_22 -> V_140 ;
F_86 ( & V_162 ) ;
if ( ! V_22 -> V_164 ) {
F_5 ( V_78 , L_52
L_53
L_54 ) ;
return 0 ;
}
F_5 ( V_78 , L_55 ,
V_162 . V_165 , V_162 . V_166 ) ;
F_5 ( V_78 , L_56 , L_57 , L_58 , L_59 ) ;
F_5 ( V_78 , L_60 ,
L_61 , L_62 , L_63 , L_64 ,
L_62 , L_63 , L_64 ) ;
F_19 ( & V_22 -> V_32 ) ;
F_83 ( V_141 , V_78 , V_168 ) ;
F_20 ( & V_22 -> V_32 ) ;
return 0 ;
}
static T_3 F_90 ( struct V_36 * V_36 , const char * V_169 ,
T_4 V_112 , T_5 * V_39 )
{
struct V_1 * V_78 = V_36 -> V_40 ;
struct V_21 * V_22 = V_78 -> V_6 ;
struct V_140 * V_141 = & V_22 -> V_140 ;
int V_92 ;
int V_170 = 1 , V_9 = 0 ;
V_9 = F_40 ( V_169 , V_112 , & V_170 ) ;
if ( V_9 < 0 && ( strcmp ( V_169 , L_66 ) == 0 ||
strcmp ( V_169 , L_67 ) == 0 ) )
V_170 = 0 ;
if ( V_170 == 0 )
V_22 -> V_164 = 0 ;
else
V_22 -> V_164 = 1 ;
F_19 ( & V_22 -> V_167 ) ;
for ( V_92 = 0 ; V_92 <= V_168 ; V_92 ++ ) {
V_141 -> V_155 [ V_92 ] . V_75 = 0 ;
F_88 ( & V_141 -> V_155 [ V_92 ] . V_157 ) ;
F_88 ( & V_141 -> V_155 [ V_92 ] . V_159 ) ;
}
F_20 ( & V_22 -> V_167 ) ;
return V_112 ;
}
void F_91 ( struct V_21 * V_22 , T_6 V_75 ,
struct V_171 * V_36 , T_5 V_172 ,
T_4 V_38 , int V_173 )
{
int V_92 , V_174 = - 1 ;
struct V_175 * V_176 ;
struct V_175 * V_177 ;
int * V_178 = & V_22 -> V_179 ;
int * V_180 = & V_22 -> V_181 ;
struct V_140 * V_141 = & V_22 -> V_140 ;
if( ! V_22 -> V_164 )
return;
V_176 = V_22 -> V_175 ;
V_177 = V_22 -> V_182 ;
F_19 ( & V_22 -> V_167 ) ;
for( V_92 = 0 ; V_92 < V_168 ; V_92 ++ ) {
if( V_141 -> V_155 [ V_92 ] . V_75 == V_75 ) {
V_174 = V_92 ;
break;
}
}
if ( V_174 == - 1 ) {
V_22 -> V_183 =
( V_22 -> V_183 + 1 ) % V_168 ;
V_174 = V_22 -> V_183 ;
V_141 -> V_155 [ V_174 ] . V_75 = V_75 ;
F_88 ( & V_141 -> V_155 [ V_174 ] . V_157 ) ;
F_88 ( & V_141 -> V_155 [ V_174 ] . V_159 ) ;
}
for( V_92 = 0 ; ( V_38 >= ( 1 << V_160 << V_92 ) ) &&
( V_92 < ( V_156 - 1 ) ) ; V_92 ++ ) ;
if ( V_173 == 0 ) {
V_141 -> V_155 [ V_174 ] . V_157 . V_158 [ V_92 ] ++ ;
V_141 -> V_155 [ V_168 ] . V_157 . V_158 [ V_92 ] ++ ;
} else {
V_141 -> V_155 [ V_174 ] . V_159 . V_158 [ V_92 ] ++ ;
V_141 -> V_155 [ V_168 ] . V_159 . V_158 [ V_92 ] ++ ;
}
F_20 ( & V_22 -> V_167 ) ;
F_19 ( & V_22 -> V_184 ) ;
for ( V_92 = 0 ; V_92 < V_168 ; V_92 ++ ) {
if ( V_176 [ V_92 ] . V_185 == V_75 ) {
if ( V_176 [ V_92 ] . V_186 != V_36 ) {
V_176 [ V_92 ] . V_187 = V_172 ;
V_176 [ V_92 ] . V_188 = V_172 + V_38 ;
V_176 [ V_92 ] . V_189 = V_38 ;
V_176 [ V_92 ] . V_190 = V_38 ;
V_176 [ V_92 ] . V_191 = 0 ;
V_176 [ V_92 ] . V_186 = V_36 ;
F_20 ( & V_22 -> V_184 ) ;
return;
}
if ( V_176 [ V_92 ] . V_188 != V_172 ) {
* V_178 =
( * V_178 + 1 ) % V_192 ;
V_177 [ * V_178 ] . V_193 = V_176 [ V_92 ] . V_193 ;
V_177 [ * V_178 ] . V_185 = V_75 ;
V_177 [ * V_178 ] . V_187 =
V_176 [ V_92 ] . V_187 ;
V_177 [ * V_178 ] . V_194 =
V_176 [ V_92 ] . V_188 ;
V_177 [ * V_178 ] . V_189 =
V_176 [ V_92 ] . V_189 ;
V_177 [ * V_178 ] . V_190 =
V_176 [ V_92 ] . V_190 ;
V_177 [ * V_178 ] . V_191 =
V_176 [ V_92 ] . V_191 ;
V_176 [ V_92 ] . V_193 = V_173 ;
V_176 [ V_92 ] . V_187 = V_172 ;
V_176 [ V_92 ] . V_189 = V_38 ;
V_176 [ V_92 ] . V_190 = V_38 ;
V_176 [ V_92 ] . V_191 = V_172 -
V_176 [ V_92 ] . V_188 ;
}
if( V_176 [ V_92 ] . V_189 > V_38 )
V_176 [ V_92 ] . V_189 = V_38 ;
if( V_176 [ V_92 ] . V_190 < V_38 )
V_176 [ V_92 ] . V_190 = V_38 ;
V_176 [ V_92 ] . V_188 = V_172 + V_38 ;
F_20 ( & V_22 -> V_184 ) ;
return;
}
}
* V_180 = ( * V_180 + 1 ) % V_168 ;
V_176 [ * V_180 ] . V_185 = V_75 ;
V_176 [ * V_180 ] . V_193 = V_173 ;
V_176 [ * V_180 ] . V_187 = V_172 ;
V_176 [ * V_180 ] . V_188 = V_172 + V_38 ;
V_176 [ * V_180 ] . V_189 = V_38 ;
V_176 [ * V_180 ] . V_190 = V_38 ;
V_176 [ * V_180 ] . V_191 = 0 ;
V_176 [ * V_180 ] . V_186 = V_36 ;
F_20 ( & V_22 -> V_184 ) ;
}
static int F_92 ( struct V_1 * V_78 , void * V_3 )
{
struct V_161 V_162 ;
struct V_21 * V_22 = V_78 -> V_6 ;
struct V_175 * V_177 = V_22 -> V_182 ;
struct V_175 * V_176 = V_22 -> V_175 ;
int V_92 ;
F_86 ( & V_162 ) ;
if ( ! V_22 -> V_164 ) {
F_5 ( V_78 , L_52
L_53
L_54 ) ;
return 0 ;
}
F_19 ( & V_22 -> V_184 ) ;
F_5 ( V_78 , L_55 ,
V_162 . V_165 , V_162 . V_166 ) ;
F_5 ( V_78 , L_68 ,
L_69 , L_70 , L_71 , L_72 ,
L_73 , L_74 , L_75 ) ;
for( V_92 = 0 ; V_92 < V_192 ; V_92 ++ ) {
if ( V_177 [ V_92 ] . V_185 != 0 )
F_5 ( V_78 ,
L_76 ,
V_177 [ V_92 ] . V_193 == V_195 ? 'R' : 'W' ,
V_177 [ V_92 ] . V_185 ,
V_177 [ V_92 ] . V_187 ,
V_177 [ V_92 ] . V_194 ,
( unsigned long ) V_177 [ V_92 ] . V_189 ,
( unsigned long ) V_177 [ V_92 ] . V_190 ,
V_177 [ V_92 ] . V_191 ) ;
}
for( V_92 = 0 ; V_92 < V_168 ; V_92 ++ ) {
if ( V_176 [ V_92 ] . V_185 != 0 )
F_5 ( V_78 ,
L_76 ,
V_176 [ V_92 ] . V_193 == V_195 ? 'R' : 'W' ,
V_176 [ V_92 ] . V_185 ,
V_176 [ V_92 ] . V_187 ,
V_176 [ V_92 ] . V_188 ,
( unsigned long ) V_176 [ V_92 ] . V_189 ,
( unsigned long ) V_176 [ V_92 ] . V_190 ,
V_176 [ V_92 ] . V_191 ) ;
}
F_20 ( & V_22 -> V_184 ) ;
return 0 ;
}
static T_3 F_93 ( struct V_36 * V_36 , const char * V_169 ,
T_4 V_112 , T_5 * V_39 )
{
struct V_1 * V_78 = V_36 -> V_40 ;
struct V_21 * V_22 = V_78 -> V_6 ;
struct V_175 * V_196 = V_22 -> V_175 ;
struct V_175 * V_197 = V_22 -> V_182 ;
int V_170 = 1 , V_9 = 0 ;
V_9 = F_40 ( V_169 , V_112 , & V_170 ) ;
if ( V_9 < 0 && ( strcmp ( V_169 , L_66 ) == 0 ||
strcmp ( V_169 , L_67 ) == 0 ) )
V_170 = 0 ;
if ( V_170 == 0 )
V_22 -> V_164 = 0 ;
else
V_22 -> V_164 = 1 ;
F_19 ( & V_22 -> V_184 ) ;
V_22 -> V_181 = 0 ;
V_22 -> V_179 = 0 ;
memset ( V_196 , 0 , sizeof( struct V_175 ) *
V_168 ) ;
memset ( V_197 , 0 , sizeof( struct V_175 ) *
V_192 ) ;
F_20 ( & V_22 -> V_184 ) ;
return V_112 ;
}
void F_94 ( struct V_198 * V_102 )
{
V_102 -> V_199 = NULL ;
V_102 -> V_200 = V_132 ;
}
