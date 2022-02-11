static inline T_1 F_1 ( unsigned int V_1 , T_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_1 V_5 ;
V_4 = F_2 ( F_3 () ) ;
V_5 = F_4 ( V_1 ) . V_6 [ V_7 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_8 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_9 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_10 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_11 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_12 ] ;
V_3 = V_4 - V_5 ;
if ( V_2 )
* V_2 = F_5 ( V_4 ) ;
return F_5 ( V_3 ) ;
}
static inline T_2 F_6 ( unsigned int V_1 , T_2 * V_2 )
{
T_1 V_3 = F_7 ( V_1 , NULL ) ;
if ( V_3 == - 1ULL )
return F_1 ( V_1 , V_2 ) ;
else
V_3 += F_8 ( V_1 , V_2 ) ;
return V_3 ;
}
static int
F_9 ( struct V_13 * V_14 , unsigned long V_15 ,
void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_19 * V_20 = & F_10 ( V_21 ,
V_18 -> V_1 ) ;
struct V_22 * V_23 ;
if ( ! V_20 -> V_24 )
return 0 ;
V_23 = V_20 -> V_25 ;
if ( V_20 -> V_26 > V_23 -> V_27
|| V_20 -> V_26 < V_23 -> V_28 )
V_20 -> V_26 = V_18 -> V_29 ;
return 0 ;
}
static T_3 F_11 ( struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
return sprintf ( V_34 , L_1 , V_35 ) ;
}
static T_3 F_12 ( struct V_30 * V_36 ,
struct V_32 * V_37 ,
const char * V_34 , T_4 V_38 )
{
unsigned int V_39 ;
int V_40 ;
V_40 = sscanf ( V_34 , L_2 , & V_39 ) ;
if ( V_40 != 1 || V_39 > V_41 || V_39 < 1 )
return - V_42 ;
V_43 . V_44 = V_39 ;
return V_38 ;
}
static T_3 F_13 ( struct V_30 * V_36 , struct V_32 * V_37 ,
const char * V_34 , T_4 V_38 )
{
unsigned int V_39 ;
int V_40 ;
V_40 = sscanf ( V_34 , L_2 , & V_39 ) ;
if ( V_40 != 1 )
return - V_42 ;
V_43 . V_45 = V_27 ( V_39 , V_35 ) ;
return V_38 ;
}
static T_3 F_14 ( struct V_30 * V_36 , struct V_32 * V_37 ,
const char * V_34 , T_4 V_38 )
{
unsigned int V_39 ;
int V_40 ;
V_40 = sscanf ( V_34 , L_2 , & V_39 ) ;
if ( V_40 != 1 || V_39 > 100 ||
V_39 <= V_43 . V_46 )
return - V_42 ;
V_43 . V_47 = V_39 ;
return V_38 ;
}
static T_3 F_15 ( struct V_30 * V_36 , struct V_32 * V_37 ,
const char * V_34 , T_4 V_38 )
{
unsigned int V_39 ;
int V_40 ;
V_40 = sscanf ( V_34 , L_2 , & V_39 ) ;
if ( V_40 != 1 || V_39 < 11 || V_39 > 100 ||
V_39 >= V_43 . V_47 )
return - V_42 ;
V_43 . V_46 = V_39 ;
return V_38 ;
}
static T_3 F_16 ( struct V_30 * V_36 , struct V_32 * V_37 ,
const char * V_34 , T_4 V_38 )
{
unsigned int V_39 ;
int V_40 ;
unsigned int V_48 ;
V_40 = sscanf ( V_34 , L_2 , & V_39 ) ;
if ( V_40 != 1 )
return - V_42 ;
if ( V_39 > 1 )
V_39 = 1 ;
if ( V_39 == V_43 . V_49 )
return V_38 ;
V_43 . V_49 = V_39 ;
F_17 (j) {
struct V_19 * V_50 ;
V_50 = & F_10 ( V_21 , V_48 ) ;
V_50 -> V_51 = F_6 ( V_48 ,
& V_50 -> V_52 ) ;
if ( V_43 . V_49 )
V_50 -> V_53 = F_4 ( V_48 ) . V_6 [ V_12 ] ;
}
return V_38 ;
}
static T_3 F_18 ( struct V_30 * V_36 , struct V_32 * V_37 ,
const char * V_34 , T_4 V_38 )
{
unsigned int V_39 ;
int V_40 ;
V_40 = sscanf ( V_34 , L_2 , & V_39 ) ;
if ( V_40 != 1 )
return - V_42 ;
if ( V_39 > 100 )
V_39 = 100 ;
V_43 . V_54 = V_39 ;
return V_38 ;
}
static void F_19 ( struct V_19 * V_20 )
{
unsigned int V_55 = 0 ;
unsigned int V_56 = 0 ;
unsigned int V_57 ;
struct V_22 * V_23 ;
unsigned int V_48 ;
V_23 = V_20 -> V_25 ;
F_20 (j, policy->cpus) {
struct V_19 * V_58 ;
T_2 V_4 , V_59 ;
unsigned int V_3 , V_60 ;
V_58 = & F_10 ( V_21 , V_48 ) ;
V_59 = F_6 ( V_48 , & V_4 ) ;
V_60 = ( unsigned int )
( V_4 - V_58 -> V_52 ) ;
V_58 -> V_52 = V_4 ;
V_3 = ( unsigned int )
( V_59 - V_58 -> V_51 ) ;
V_58 -> V_51 = V_59 ;
if ( V_43 . V_49 ) {
T_1 V_61 ;
unsigned long V_62 ;
V_61 = F_4 ( V_48 ) . V_6 [ V_12 ] -
V_58 -> V_53 ;
V_62 = ( unsigned long )
F_21 ( V_61 ) ;
V_58 -> V_53 = F_4 ( V_48 ) . V_6 [ V_12 ] ;
V_3 += F_5 ( V_62 ) ;
}
if ( F_22 ( ! V_60 || V_60 < V_3 ) )
continue;
V_55 = 100 * ( V_60 - V_3 ) / V_60 ;
if ( V_55 > V_56 )
V_56 = V_55 ;
}
if ( V_43 . V_54 == 0 )
return;
if ( V_56 > V_43 . V_47 ) {
V_20 -> V_63 = 0 ;
if ( V_20 -> V_26 == V_23 -> V_27 )
return;
V_57 = ( V_43 . V_54 * V_23 -> V_27 ) / 100 ;
if ( F_22 ( V_57 == 0 ) )
V_57 = 5 ;
V_20 -> V_26 += V_57 ;
if ( V_20 -> V_26 > V_23 -> V_27 )
V_20 -> V_26 = V_23 -> V_27 ;
F_23 ( V_23 , V_20 -> V_26 ,
V_64 ) ;
return;
}
if ( V_56 < ( V_43 . V_46 - 10 ) ) {
V_57 = ( V_43 . V_54 * V_23 -> V_27 ) / 100 ;
V_20 -> V_26 -= V_57 ;
if ( V_20 -> V_26 < V_23 -> V_28 )
V_20 -> V_26 = V_23 -> V_28 ;
if ( V_23 -> V_65 == V_23 -> V_28 )
return;
F_23 ( V_23 , V_20 -> V_26 ,
V_64 ) ;
return;
}
}
static void F_24 ( struct V_66 * V_67 )
{
struct V_19 * V_50 =
F_25 ( V_67 , struct V_19 , V_67 . V_67 ) ;
unsigned int V_1 = V_50 -> V_1 ;
int V_68 = F_26 ( V_43 . V_45 ) ;
V_68 -= V_69 % V_68 ;
F_27 ( & V_50 -> V_70 ) ;
F_19 ( V_50 ) ;
F_28 ( V_1 , & V_50 -> V_67 , V_68 ) ;
F_29 ( & V_50 -> V_70 ) ;
}
static inline void F_30 ( struct V_19 * V_50 )
{
int V_68 = F_26 ( V_43 . V_45 ) ;
V_68 -= V_69 % V_68 ;
V_50 -> V_24 = 1 ;
F_31 ( & V_50 -> V_67 , F_24 ) ;
F_28 ( V_50 -> V_1 , & V_50 -> V_67 , V_68 ) ;
}
static inline void F_32 ( struct V_19 * V_50 )
{
V_50 -> V_24 = 0 ;
F_33 ( & V_50 -> V_67 ) ;
}
static int F_34 ( struct V_22 * V_23 ,
unsigned int V_71 )
{
unsigned int V_1 = V_23 -> V_1 ;
struct V_19 * V_20 ;
unsigned int V_48 ;
int V_72 ;
V_20 = & F_10 ( V_21 , V_1 ) ;
switch ( V_71 ) {
case V_73 :
if ( ( ! F_35 ( V_1 ) ) || ( ! V_23 -> V_65 ) )
return - V_42 ;
F_27 ( & V_74 ) ;
F_20 (j, policy->cpus) {
struct V_19 * V_58 ;
V_58 = & F_10 ( V_21 , V_48 ) ;
V_58 -> V_25 = V_23 ;
V_58 -> V_51 = F_6 ( V_48 ,
& V_58 -> V_52 ) ;
if ( V_43 . V_49 )
V_58 -> V_53 =
F_4 ( V_48 ) . V_6 [ V_12 ] ;
}
V_20 -> V_63 = 0 ;
V_20 -> V_26 = V_23 -> V_65 ;
F_36 ( & V_20 -> V_70 ) ;
V_75 ++ ;
if ( V_75 == 1 ) {
unsigned int V_76 ;
V_76 = V_23 -> V_77 . V_78 / 1000 ;
if ( V_76 == 0 )
V_76 = 1 ;
V_72 = F_37 ( V_79 ,
& V_80 ) ;
if ( V_72 ) {
F_29 ( & V_74 ) ;
return V_72 ;
}
V_35 =
V_81 * F_5 ( 10 ) ;
V_35 = V_27 ( V_35 ,
V_82 * V_76 ) ;
V_43 . V_45 =
V_27 ( V_35 ,
V_76 * V_83 ) ;
F_38 (
& V_84 ,
V_85 ) ;
}
F_29 ( & V_74 ) ;
F_30 ( V_20 ) ;
break;
case V_86 :
F_32 ( V_20 ) ;
F_27 ( & V_74 ) ;
V_75 -- ;
F_39 ( & V_20 -> V_70 ) ;
if ( V_75 == 0 )
F_40 (
& V_84 ,
V_85 ) ;
F_29 ( & V_74 ) ;
if ( ! V_75 )
F_41 ( V_79 ,
& V_80 ) ;
break;
case V_87 :
F_27 ( & V_20 -> V_70 ) ;
if ( V_23 -> V_27 < V_20 -> V_25 -> V_65 )
F_23 (
V_20 -> V_25 ,
V_23 -> V_27 , V_64 ) ;
else if ( V_23 -> V_28 > V_20 -> V_25 -> V_65 )
F_23 (
V_20 -> V_25 ,
V_23 -> V_28 , V_88 ) ;
F_29 ( & V_20 -> V_70 ) ;
break;
}
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_89 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_89 ) ;
}
