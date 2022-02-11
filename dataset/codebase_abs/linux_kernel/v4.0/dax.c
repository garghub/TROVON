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
static T_3 F_14 ( int V_26 , struct V_1 * V_1 , struct V_27 * V_28 ,
T_2 V_29 , T_2 V_23 , T_4 V_30 ,
struct V_15 * V_16 )
{
T_3 V_31 = 0 ;
T_2 V_22 = V_29 ;
T_2 V_32 = V_29 ;
T_2 V_33 = V_29 ;
void * V_10 ;
bool V_34 = false ;
if ( V_26 != V_35 )
V_23 = F_15 ( V_23 , F_16 ( V_1 ) ) ;
while ( V_22 < V_23 ) {
unsigned V_36 ;
if ( V_22 == V_32 ) {
unsigned V_17 = V_1 -> V_9 ;
T_1 V_2 = V_22 >> V_17 ;
unsigned V_21 = V_22 - ( V_2 << V_17 ) ;
long V_3 ;
if ( V_22 == V_33 ) {
V_16 -> V_20 = F_17 ( V_23 - V_22 ) ;
V_16 -> V_25 = 0 ;
V_31 = V_30 ( V_1 , V_2 , V_16 ,
V_26 == V_35 ) ;
if ( V_31 )
break;
if ( ! F_13 ( V_16 ) )
V_16 -> V_20 = 1 << V_17 ;
V_33 = V_22 - V_21 + V_16 -> V_20 ;
} else {
unsigned V_37 = V_16 -> V_20 -
( V_33 - ( V_22 - V_21 ) ) ;
V_16 -> V_18 += V_37 >> V_17 ;
V_16 -> V_20 -= V_37 ;
}
V_34 = ( V_26 != V_35 ) && ! F_10 ( V_16 ) ;
if ( V_34 ) {
V_10 = NULL ;
V_3 = V_16 -> V_20 - V_21 ;
} else {
V_31 = F_8 ( V_16 , & V_10 , V_17 ) ;
if ( V_31 < 0 )
break;
if ( F_12 ( V_16 ) || F_18 ( V_16 ) )
F_9 ( V_10 , V_31 , V_21 , V_22 ,
V_23 ) ;
V_10 += V_21 ;
V_3 = V_31 - V_21 ;
}
V_32 = F_15 ( V_22 + V_3 , V_23 ) ;
}
if ( V_26 == V_35 )
V_36 = F_19 ( V_10 , V_32 - V_22 , V_28 ) ;
else if ( ! V_34 )
V_36 = F_20 ( V_10 , V_32 - V_22 , V_28 ) ;
else
V_36 = F_21 ( V_32 - V_22 , V_28 ) ;
if ( ! V_36 )
break;
V_22 += V_36 ;
V_10 += V_36 ;
}
return ( V_22 == V_29 ) ? V_31 : V_22 - V_29 ;
}
T_3 F_22 ( int V_26 , struct V_38 * V_39 , struct V_1 * V_1 ,
struct V_27 * V_28 , T_2 V_22 ,
T_4 V_30 , T_5 V_40 , int V_41 )
{
struct V_15 V_16 ;
T_3 V_31 = - V_42 ;
T_2 V_23 = V_22 + F_23 ( V_28 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( ( V_41 & V_43 ) && ( V_26 == V_44 ) ) {
struct V_45 * V_46 = V_1 -> V_47 ;
F_24 ( & V_1 -> V_48 ) ;
V_31 = F_25 ( V_46 , V_22 , V_23 - 1 ) ;
if ( V_31 ) {
F_26 ( & V_1 -> V_48 ) ;
goto V_49;
}
}
F_27 ( & V_1 -> V_50 ) ;
V_31 = F_14 ( V_26 , V_1 , V_28 , V_22 , V_23 , V_30 , & V_16 ) ;
if ( ( V_41 & V_43 ) && ( V_26 == V_44 ) )
F_26 ( & V_1 -> V_48 ) ;
if ( ( V_31 > 0 ) && V_40 )
V_40 ( V_39 , V_22 , V_31 , V_16 . V_51 ) ;
F_28 ( V_1 ) ;
V_49:
return V_31 ;
}
static int F_29 ( struct V_45 * V_46 , struct V_52 * V_52 ,
struct V_53 * V_54 )
{
unsigned long V_3 ;
struct V_1 * V_1 = V_46 -> V_55 ;
if ( ! V_52 )
V_52 = F_30 ( V_46 , V_54 -> V_56 ,
V_57 | V_58 ) ;
if ( ! V_52 )
return V_59 ;
V_3 = ( F_16 ( V_1 ) + V_14 - 1 ) >> V_60 ;
if ( V_54 -> V_56 >= V_3 ) {
F_31 ( V_52 ) ;
F_32 ( V_52 ) ;
return V_61 ;
}
V_54 -> V_52 = V_52 ;
return V_62 ;
}
static int F_33 ( struct V_52 * V_63 , struct V_15 * V_16 ,
unsigned V_17 , unsigned long V_64 )
{
void * V_65 , * V_66 ;
if ( F_8 ( V_16 , & V_65 , V_17 ) < 0 )
return - V_67 ;
V_66 = F_34 ( V_63 ) ;
F_35 ( V_66 , V_65 , V_64 , V_63 ) ;
F_36 ( V_66 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , struct V_15 * V_16 ,
struct V_68 * V_69 , struct V_53 * V_54 )
{
struct V_45 * V_46 = V_1 -> V_47 ;
T_1 V_8 = V_16 -> V_18 << ( V_1 -> V_9 - 9 ) ;
unsigned long V_64 = ( unsigned long ) V_54 -> V_70 ;
void * V_10 ;
unsigned long V_11 ;
T_6 V_3 ;
int error ;
F_38 ( V_46 ) ;
V_3 = ( F_16 ( V_1 ) + V_14 - 1 ) >> V_60 ;
if ( F_39 ( V_54 -> V_56 >= V_3 ) ) {
error = - V_67 ;
goto V_49;
}
error = F_3 ( V_16 -> V_19 , V_8 , & V_10 , & V_11 , V_16 -> V_20 ) ;
if ( error < 0 )
goto V_49;
if ( error < V_14 ) {
error = - V_67 ;
goto V_49;
}
if ( F_12 ( V_16 ) || F_18 ( V_16 ) )
F_6 ( V_10 ) ;
error = F_40 ( V_69 , V_64 , V_11 ) ;
V_49:
F_41 ( V_46 ) ;
if ( V_16 -> V_71 )
V_16 -> V_71 ( V_16 , 1 ) ;
return error ;
}
static int F_42 ( struct V_68 * V_69 , struct V_53 * V_54 ,
T_4 V_30 )
{
struct V_72 * V_72 = V_69 -> V_73 ;
struct V_45 * V_46 = V_72 -> V_74 ;
struct V_1 * V_1 = V_46 -> V_55 ;
struct V_52 * V_52 ;
struct V_15 V_16 ;
unsigned long V_64 = ( unsigned long ) V_54 -> V_70 ;
unsigned V_17 = V_1 -> V_9 ;
T_1 V_2 ;
T_6 V_3 ;
int error ;
int V_75 = 0 ;
V_3 = ( F_16 ( V_1 ) + V_14 - 1 ) >> V_60 ;
if ( V_54 -> V_56 >= V_3 )
return V_61 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_2 = ( T_1 ) V_54 -> V_56 << ( V_60 - V_17 ) ;
V_16 . V_20 = V_14 ;
V_76:
V_52 = F_43 ( V_46 , V_54 -> V_56 ) ;
if ( V_52 ) {
if ( ! F_44 ( V_52 , V_69 -> V_77 , V_54 -> V_41 ) ) {
F_32 ( V_52 ) ;
return V_78 ;
}
if ( F_39 ( V_52 -> V_46 != V_46 ) ) {
F_31 ( V_52 ) ;
F_32 ( V_52 ) ;
goto V_76;
}
V_3 = ( F_16 ( V_1 ) + V_14 - 1 ) >> V_60 ;
if ( F_39 ( V_54 -> V_56 >= V_3 ) ) {
error = - V_67 ;
goto F_31;
}
}
error = V_30 ( V_1 , V_2 , & V_16 , 0 ) ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_67 ;
if ( error )
goto F_31;
if ( ! F_11 ( & V_16 ) && ! F_12 ( & V_16 ) && ! V_54 -> V_79 ) {
if ( V_54 -> V_41 & V_80 ) {
error = V_30 ( V_1 , V_2 , & V_16 , 1 ) ;
F_45 ( V_81 ) ;
F_46 ( V_69 -> V_77 , V_81 ) ;
V_75 = V_82 ;
if ( ! error && ( V_16 . V_20 < V_14 ) )
error = - V_67 ;
if ( error )
goto F_31;
} else {
return F_29 ( V_46 , V_52 , V_54 ) ;
}
}
if ( V_54 -> V_79 ) {
struct V_52 * V_83 = V_54 -> V_79 ;
if ( F_10 ( & V_16 ) )
error = F_33 ( V_83 , & V_16 , V_17 , V_64 ) ;
else
F_47 ( V_83 , V_64 ) ;
if ( error )
goto F_31;
V_54 -> V_52 = V_52 ;
if ( ! V_52 ) {
F_38 ( V_46 ) ;
V_3 = ( F_16 ( V_1 ) + V_14 - 1 ) >>
V_60 ;
if ( V_54 -> V_56 >= V_3 ) {
F_41 ( V_46 ) ;
error = - V_67 ;
goto V_49;
}
}
return V_62 ;
}
if ( ! V_52 && V_75 )
V_52 = F_48 ( V_46 , V_54 -> V_56 ) ;
if ( V_52 ) {
F_49 ( V_46 , V_54 -> V_56 << V_60 ,
V_84 , 0 ) ;
F_50 ( V_52 ) ;
F_31 ( V_52 ) ;
F_32 ( V_52 ) ;
}
error = F_37 ( V_1 , & V_16 , V_69 , V_54 ) ;
V_49:
if ( error == - V_85 )
return V_59 | V_75 ;
if ( ( error < 0 ) && ( error != - V_86 ) )
return V_61 | V_75 ;
return V_87 | V_75 ;
F_31:
if ( V_52 ) {
F_31 ( V_52 ) ;
F_32 ( V_52 ) ;
}
goto V_49;
}
int F_51 ( struct V_68 * V_69 , struct V_53 * V_54 ,
T_4 V_30 )
{
int V_88 ;
struct V_89 * V_90 = F_52 ( V_69 -> V_73 ) -> V_6 ;
if ( V_54 -> V_41 & V_80 ) {
F_53 ( V_90 ) ;
F_54 ( V_69 -> V_73 ) ;
}
V_88 = F_42 ( V_69 , V_54 , V_30 ) ;
if ( V_54 -> V_41 & V_80 )
F_55 ( V_90 ) ;
return V_88 ;
}
int F_56 ( struct V_1 * V_1 , T_2 V_91 , unsigned V_92 ,
T_4 V_30 )
{
struct V_15 V_16 ;
T_6 V_93 = V_91 >> V_94 ;
unsigned V_95 = V_91 & ( V_84 - 1 ) ;
int V_96 ;
if ( ! V_92 )
return 0 ;
F_4 ( ( V_95 + V_92 ) > V_84 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_20 = V_84 ;
V_96 = V_30 ( V_1 , V_93 , & V_16 , 0 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( F_10 ( & V_16 ) ) {
void * V_10 ;
V_96 = F_8 ( & V_16 , & V_10 , V_1 -> V_9 ) ;
if ( V_96 < 0 )
return V_96 ;
memset ( V_10 + V_95 , 0 , V_92 ) ;
}
return 0 ;
}
int F_57 ( struct V_1 * V_1 , T_2 V_91 , T_4 V_30 )
{
unsigned V_92 = F_58 ( V_91 ) - V_91 ;
return F_56 ( V_1 , V_91 , V_92 , V_30 ) ;
}
