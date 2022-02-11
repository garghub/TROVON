int F_1 ( struct V_1 * V_1 , T_1 V_2 , long V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_1 V_8 = V_2 << ( V_1 -> V_9 - 9 ) ;
F_2 () ;
do {
void * V_10 ;
unsigned long V_11 ;
long V_12 ;
V_12 = F_3 ( V_5 , V_8 , & V_10 , & V_11 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_4 ( V_3 < V_12 ) ;
while ( V_12 > 0 ) {
unsigned V_13 = V_14 - F_5 ( V_10 ) ;
if ( V_13 > V_12 )
V_13 = V_12 ;
if ( V_13 < V_14 )
memset ( V_10 , 0 , V_13 ) ;
else
F_6 ( V_10 ) ;
V_10 += V_13 ;
V_3 -= V_13 ;
V_12 -= V_13 ;
F_4 ( V_13 & 511 ) ;
V_8 += V_13 / 512 ;
F_7 () ;
}
} while ( V_3 );
return 0 ;
}
static long F_8 ( struct V_15 * V_16 , void * * V_10 , unsigned V_17 )
{
unsigned long V_11 ;
T_1 V_8 = V_16 -> V_18 << ( V_17 - 9 ) ;
return F_3 ( V_16 -> V_19 , V_8 , V_10 , & V_11 , V_16 -> V_20 ) ;
}
static void F_9 ( void * V_10 , unsigned V_3 , unsigned V_21 , T_2 V_22 ,
T_2 V_23 )
{
T_2 V_24 = V_23 - V_22 + V_21 ;
if ( V_21 > 0 )
memset ( V_10 , 0 , V_21 ) ;
if ( V_24 < V_3 )
memset ( V_10 + V_24 , 0 , V_3 - V_24 ) ;
}
static bool F_10 ( struct V_15 * V_16 )
{
return F_11 ( V_16 ) && ! F_12 ( V_16 ) ;
}
static bool F_13 ( struct V_15 * V_16 )
{
return V_16 -> V_25 != 0 ;
}
static T_3 F_14 ( struct V_1 * V_1 , struct V_26 * V_27 ,
T_2 V_28 , T_2 V_23 , T_4 V_29 ,
struct V_15 * V_16 )
{
T_3 V_30 = 0 ;
T_2 V_22 = V_28 ;
T_2 V_31 = V_28 ;
T_2 V_32 = V_28 ;
void * V_10 ;
bool V_33 = false ;
if ( F_15 ( V_27 ) != V_34 )
V_23 = F_16 ( V_23 , F_17 ( V_1 ) ) ;
while ( V_22 < V_23 ) {
unsigned V_35 ;
if ( V_22 == V_31 ) {
unsigned V_17 = V_1 -> V_9 ;
T_1 V_2 = V_22 >> V_17 ;
unsigned V_21 = V_22 - ( V_2 << V_17 ) ;
long V_3 ;
if ( V_22 == V_32 ) {
V_16 -> V_20 = F_18 ( V_23 - V_22 ) ;
V_16 -> V_25 = 0 ;
V_30 = V_29 ( V_1 , V_2 , V_16 ,
F_15 ( V_27 ) == V_34 ) ;
if ( V_30 )
break;
if ( ! F_13 ( V_16 ) )
V_16 -> V_20 = 1 << V_17 ;
V_32 = V_22 - V_21 + V_16 -> V_20 ;
} else {
unsigned V_36 = V_16 -> V_20 -
( V_32 - ( V_22 - V_21 ) ) ;
V_16 -> V_18 += V_36 >> V_17 ;
V_16 -> V_20 -= V_36 ;
}
V_33 = F_15 ( V_27 ) != V_34 && ! F_10 ( V_16 ) ;
if ( V_33 ) {
V_10 = NULL ;
V_3 = V_16 -> V_20 - V_21 ;
} else {
V_30 = F_8 ( V_16 , & V_10 , V_17 ) ;
if ( V_30 < 0 )
break;
if ( F_12 ( V_16 ) || F_19 ( V_16 ) )
F_9 ( V_10 , V_30 , V_21 , V_22 ,
V_23 ) ;
V_10 += V_21 ;
V_3 = V_30 - V_21 ;
}
V_31 = F_16 ( V_22 + V_3 , V_23 ) ;
}
if ( F_15 ( V_27 ) == V_34 )
V_35 = F_20 ( V_10 , V_31 - V_22 , V_27 ) ;
else if ( ! V_33 )
V_35 = F_21 ( V_10 , V_31 - V_22 , V_27 ) ;
else
V_35 = F_22 ( V_31 - V_22 , V_27 ) ;
if ( ! V_35 )
break;
V_22 += V_35 ;
V_10 += V_35 ;
}
return ( V_22 == V_28 ) ? V_30 : V_22 - V_28 ;
}
T_3 F_23 ( struct V_37 * V_38 , struct V_1 * V_1 ,
struct V_26 * V_27 , T_2 V_22 , T_4 V_29 ,
T_5 V_39 , int V_40 )
{
struct V_15 V_16 ;
T_3 V_30 = - V_41 ;
T_2 V_23 = V_22 + F_24 ( V_27 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( ( V_40 & V_42 ) && F_15 ( V_27 ) == V_43 ) {
struct V_44 * V_45 = V_1 -> V_46 ;
F_25 ( & V_1 -> V_47 ) ;
V_30 = F_26 ( V_45 , V_22 , V_23 - 1 ) ;
if ( V_30 ) {
F_27 ( & V_1 -> V_47 ) ;
goto V_48;
}
}
F_28 ( V_1 ) ;
V_30 = F_14 ( V_1 , V_27 , V_22 , V_23 , V_29 , & V_16 ) ;
if ( ( V_40 & V_42 ) && F_15 ( V_27 ) == V_43 )
F_27 ( & V_1 -> V_47 ) ;
if ( ( V_30 > 0 ) && V_39 )
V_39 ( V_38 , V_22 , V_30 , V_16 . V_49 ) ;
F_29 ( V_1 ) ;
V_48:
return V_30 ;
}
static int F_30 ( struct V_44 * V_45 , struct V_50 * V_50 ,
struct V_51 * V_52 )
{
unsigned long V_3 ;
struct V_1 * V_1 = V_45 -> V_53 ;
if ( ! V_50 )
V_50 = F_31 ( V_45 , V_52 -> V_54 ,
V_55 | V_56 ) ;
if ( ! V_50 )
return V_57 ;
V_3 = ( F_17 ( V_1 ) + V_14 - 1 ) >> V_58 ;
if ( V_52 -> V_54 >= V_3 ) {
F_32 ( V_50 ) ;
F_33 ( V_50 ) ;
return V_59 ;
}
V_52 -> V_50 = V_50 ;
return V_60 ;
}
static int F_34 ( struct V_50 * V_61 , struct V_15 * V_16 ,
unsigned V_17 , unsigned long V_62 )
{
void * V_63 , * V_64 ;
if ( F_8 ( V_16 , & V_63 , V_17 ) < 0 )
return - V_65 ;
V_64 = F_35 ( V_61 ) ;
F_36 ( V_64 , V_63 , V_62 , V_61 ) ;
F_37 ( V_64 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , struct V_15 * V_16 ,
struct V_66 * V_67 , struct V_51 * V_52 )
{
struct V_44 * V_45 = V_1 -> V_46 ;
T_1 V_8 = V_16 -> V_18 << ( V_1 -> V_9 - 9 ) ;
unsigned long V_62 = ( unsigned long ) V_52 -> V_68 ;
void * V_10 ;
unsigned long V_11 ;
T_6 V_3 ;
int error ;
F_39 ( V_45 ) ;
V_3 = ( F_17 ( V_1 ) + V_14 - 1 ) >> V_58 ;
if ( F_40 ( V_52 -> V_54 >= V_3 ) ) {
error = - V_65 ;
goto V_48;
}
error = F_3 ( V_16 -> V_19 , V_8 , & V_10 , & V_11 , V_16 -> V_20 ) ;
if ( error < 0 )
goto V_48;
if ( error < V_14 ) {
error = - V_65 ;
goto V_48;
}
if ( F_12 ( V_16 ) || F_19 ( V_16 ) )
F_6 ( V_10 ) ;
error = F_41 ( V_67 , V_62 , V_11 ) ;
V_48:
F_42 ( V_45 ) ;
if ( V_16 -> V_69 )
V_16 -> V_69 ( V_16 , 1 ) ;
return error ;
}
static int F_43 ( struct V_66 * V_67 , struct V_51 * V_52 ,
T_4 V_29 )
{
struct V_70 * V_70 = V_67 -> V_71 ;
struct V_44 * V_45 = V_70 -> V_72 ;
struct V_1 * V_1 = V_45 -> V_53 ;
struct V_50 * V_50 ;
struct V_15 V_16 ;
unsigned long V_62 = ( unsigned long ) V_52 -> V_68 ;
unsigned V_17 = V_1 -> V_9 ;
T_1 V_2 ;
T_6 V_3 ;
int error ;
int V_73 = 0 ;
V_3 = ( F_17 ( V_1 ) + V_14 - 1 ) >> V_58 ;
if ( V_52 -> V_54 >= V_3 )
return V_59 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_2 = ( T_1 ) V_52 -> V_54 << ( V_58 - V_17 ) ;
V_16 . V_20 = V_14 ;
V_74:
V_50 = F_44 ( V_45 , V_52 -> V_54 ) ;
if ( V_50 ) {
if ( ! F_45 ( V_50 , V_67 -> V_75 , V_52 -> V_40 ) ) {
F_33 ( V_50 ) ;
return V_76 ;
}
if ( F_40 ( V_50 -> V_45 != V_45 ) ) {
F_32 ( V_50 ) ;
F_33 ( V_50 ) ;
goto V_74;
}
V_3 = ( F_17 ( V_1 ) + V_14 - 1 ) >> V_58 ;
if ( F_40 ( V_52 -> V_54 >= V_3 ) ) {
error = - V_65 ;
goto F_32;
}
}
error = V_29 ( V_1 , V_2 , & V_16 , 0 ) ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_65 ;
if ( error )
goto F_32;
if ( ! F_11 ( & V_16 ) && ! F_12 ( & V_16 ) && ! V_52 -> V_77 ) {
if ( V_52 -> V_40 & V_78 ) {
error = V_29 ( V_1 , V_2 , & V_16 , 1 ) ;
F_46 ( V_79 ) ;
F_47 ( V_67 -> V_75 , V_79 ) ;
V_73 = V_80 ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_65 ;
if ( error )
goto F_32;
} else {
return F_30 ( V_45 , V_50 , V_52 ) ;
}
}
if ( V_52 -> V_77 ) {
struct V_50 * V_81 = V_52 -> V_77 ;
if ( F_10 ( & V_16 ) )
error = F_34 ( V_81 , & V_16 , V_17 , V_62 ) ;
else
F_48 ( V_81 , V_62 ) ;
if ( error )
goto F_32;
V_52 -> V_50 = V_50 ;
if ( ! V_50 ) {
F_39 ( V_45 ) ;
V_3 = ( F_17 ( V_1 ) + V_14 - 1 ) >>
V_58 ;
if ( V_52 -> V_54 >= V_3 ) {
F_42 ( V_45 ) ;
error = - V_65 ;
goto V_48;
}
}
return V_60 ;
}
if ( ! V_50 && V_73 )
V_50 = F_49 ( V_45 , V_52 -> V_54 ) ;
if ( V_50 ) {
F_50 ( V_45 , V_52 -> V_54 << V_58 ,
V_82 , 0 ) ;
F_51 ( V_50 ) ;
F_32 ( V_50 ) ;
F_33 ( V_50 ) ;
}
error = F_38 ( V_1 , & V_16 , V_67 , V_52 ) ;
V_48:
if ( error == - V_83 )
return V_57 | V_73 ;
if ( ( error < 0 ) && ( error != - V_84 ) )
return V_59 | V_73 ;
return V_85 | V_73 ;
F_32:
if ( V_50 ) {
F_32 ( V_50 ) ;
F_33 ( V_50 ) ;
}
goto V_48;
}
int F_52 ( struct V_66 * V_67 , struct V_51 * V_52 ,
T_4 V_29 )
{
int V_86 ;
struct V_87 * V_88 = F_53 ( V_67 -> V_71 ) -> V_6 ;
if ( V_52 -> V_40 & V_78 ) {
F_54 ( V_88 ) ;
F_55 ( V_67 -> V_71 ) ;
}
V_86 = F_43 ( V_67 , V_52 , V_29 ) ;
if ( V_52 -> V_40 & V_78 )
F_56 ( V_88 ) ;
return V_86 ;
}
int F_57 ( struct V_66 * V_67 , struct V_51 * V_52 )
{
struct V_87 * V_88 = F_53 ( V_67 -> V_71 ) -> V_6 ;
F_54 ( V_88 ) ;
F_55 ( V_67 -> V_71 ) ;
F_56 ( V_88 ) ;
return V_85 ;
}
int F_58 ( struct V_1 * V_1 , T_2 V_89 , unsigned V_90 ,
T_4 V_29 )
{
struct V_15 V_16 ;
T_6 V_91 = V_89 >> V_92 ;
unsigned V_93 = V_89 & ( V_82 - 1 ) ;
int V_94 ;
if ( ! V_90 )
return 0 ;
F_4 ( ( V_93 + V_90 ) > V_82 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_20 = V_82 ;
V_94 = V_29 ( V_1 , V_91 , & V_16 , 0 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( F_10 ( & V_16 ) ) {
void * V_10 ;
V_94 = F_8 ( & V_16 , & V_10 , V_1 -> V_9 ) ;
if ( V_94 < 0 )
return V_94 ;
memset ( V_10 + V_93 , 0 , V_90 ) ;
}
return 0 ;
}
int F_59 ( struct V_1 * V_1 , T_2 V_89 , T_4 V_29 )
{
unsigned V_90 = F_60 ( V_89 ) - V_89 ;
return F_58 ( V_1 , V_89 , V_90 , V_29 ) ;
}
