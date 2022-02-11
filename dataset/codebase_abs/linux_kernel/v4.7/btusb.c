static inline void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
F_3 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_8 , int V_9 )
{
struct V_10 * V_11 ;
int V_12 = 0 ;
F_6 ( & V_2 -> V_4 ) ;
V_11 = V_2 -> V_5 ;
while ( V_9 ) {
int V_13 ;
if ( ! V_11 ) {
V_11 = F_7 ( V_14 , V_15 ) ;
if ( ! V_11 ) {
V_12 = - V_16 ;
break;
}
F_8 ( V_11 ) = V_17 ;
F_9 ( V_11 ) = V_18 ;
}
V_13 = F_10 ( V_19 , F_9 ( V_11 ) , V_9 ) ;
memcpy ( F_11 ( V_11 , V_13 ) , V_8 , V_13 ) ;
V_9 -= V_13 ;
V_8 += V_13 ;
F_9 ( V_11 ) -= V_13 ;
if ( V_11 -> V_13 == V_18 ) {
F_9 ( V_11 ) = F_12 ( V_11 ) -> V_20 ;
if ( F_13 ( V_11 ) < F_9 ( V_11 ) ) {
F_3 ( V_11 ) ;
V_11 = NULL ;
V_12 = - V_21 ;
break;
}
}
if ( ! F_9 ( V_11 ) ) {
V_2 -> V_22 ( V_2 -> V_23 , V_11 ) ;
V_11 = NULL ;
}
}
V_2 -> V_5 = V_11 ;
F_14 ( & V_2 -> V_4 ) ;
return V_12 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_8 , int V_9 )
{
struct V_10 * V_11 ;
int V_12 = 0 ;
F_6 ( & V_2 -> V_4 ) ;
V_11 = V_2 -> V_6 ;
while ( V_9 ) {
int V_13 ;
if ( ! V_11 ) {
V_11 = F_7 ( V_24 , V_15 ) ;
if ( ! V_11 ) {
V_12 = - V_16 ;
break;
}
F_8 ( V_11 ) = V_25 ;
F_9 ( V_11 ) = V_26 ;
}
V_13 = F_10 ( V_19 , F_9 ( V_11 ) , V_9 ) ;
memcpy ( F_11 ( V_11 , V_13 ) , V_8 , V_13 ) ;
V_9 -= V_13 ;
V_8 += V_13 ;
F_9 ( V_11 ) -= V_13 ;
if ( V_11 -> V_13 == V_26 ) {
T_1 V_27 = F_16 ( V_11 ) -> V_27 ;
F_9 ( V_11 ) = F_17 ( V_27 ) ;
if ( F_13 ( V_11 ) < F_9 ( V_11 ) ) {
F_3 ( V_11 ) ;
V_11 = NULL ;
V_12 = - V_21 ;
break;
}
}
if ( ! F_9 ( V_11 ) ) {
F_18 ( V_2 -> V_23 , V_11 ) ;
V_11 = NULL ;
}
}
V_2 -> V_6 = V_11 ;
F_14 ( & V_2 -> V_4 ) ;
return V_12 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_8 , int V_9 )
{
struct V_10 * V_11 ;
int V_12 = 0 ;
F_6 ( & V_2 -> V_4 ) ;
V_11 = V_2 -> V_7 ;
while ( V_9 ) {
int V_13 ;
if ( ! V_11 ) {
V_11 = F_7 ( V_28 , V_15 ) ;
if ( ! V_11 ) {
V_12 = - V_16 ;
break;
}
F_8 ( V_11 ) = V_29 ;
F_9 ( V_11 ) = V_30 ;
}
V_13 = F_10 ( V_19 , F_9 ( V_11 ) , V_9 ) ;
memcpy ( F_11 ( V_11 , V_13 ) , V_8 , V_13 ) ;
V_9 -= V_13 ;
V_8 += V_13 ;
F_9 ( V_11 ) -= V_13 ;
if ( V_11 -> V_13 == V_30 ) {
F_9 ( V_11 ) = F_20 ( V_11 ) -> V_27 ;
if ( F_13 ( V_11 ) < F_9 ( V_11 ) ) {
F_3 ( V_11 ) ;
V_11 = NULL ;
V_12 = - V_21 ;
break;
}
}
if ( ! F_9 ( V_11 ) ) {
F_18 ( V_2 -> V_23 , V_11 ) ;
V_11 = NULL ;
}
}
V_2 -> V_7 = V_11 ;
F_14 ( & V_2 -> V_4 ) ;
return V_12 ;
}
static void F_21 ( struct V_31 * V_31 )
{
struct V_32 * V_23 = V_31 -> V_33 ;
struct V_1 * V_2 = F_22 ( V_23 ) ;
int V_12 ;
F_23 ( L_1 , V_23 -> V_34 , V_31 , V_31 -> V_35 ,
V_31 -> V_36 ) ;
if ( ! F_24 ( V_37 , & V_23 -> V_3 ) )
return;
if ( V_31 -> V_35 == 0 ) {
V_23 -> V_38 . V_39 += V_31 -> V_36 ;
if ( F_5 ( V_2 , V_31 -> V_40 ,
V_31 -> V_36 ) < 0 ) {
F_25 ( L_2 , V_23 -> V_34 ) ;
V_23 -> V_38 . V_41 ++ ;
}
} else if ( V_31 -> V_35 == - V_42 ) {
return;
}
if ( ! F_24 ( V_43 , & V_2 -> V_3 ) )
return;
F_26 ( V_2 -> V_44 ) ;
F_27 ( V_31 , & V_2 -> V_45 ) ;
V_12 = F_28 ( V_31 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_3 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
}
static int F_30 ( struct V_32 * V_23 , T_2 V_48 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
unsigned char * V_49 ;
unsigned int V_50 ;
int V_12 , V_51 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
if ( ! V_2 -> V_52 )
return - V_47 ;
V_31 = F_31 ( 0 , V_48 ) ;
if ( ! V_31 )
return - V_16 ;
V_51 = F_32 ( V_2 -> V_52 -> V_53 ) ;
V_49 = F_33 ( V_51 , V_48 ) ;
if ( ! V_49 ) {
F_34 ( V_31 ) ;
return - V_16 ;
}
V_50 = F_35 ( V_2 -> V_44 , V_2 -> V_52 -> V_54 ) ;
F_36 ( V_31 , V_2 -> V_44 , V_50 , V_49 , V_51 ,
F_21 , V_23 , V_2 -> V_52 -> V_55 ) ;
V_31 -> V_56 |= V_57 ;
F_27 ( V_31 , & V_2 -> V_45 ) ;
V_12 = F_28 ( V_31 , V_48 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_5 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
F_34 ( V_31 ) ;
return V_12 ;
}
static void F_37 ( struct V_31 * V_31 )
{
struct V_32 * V_23 = V_31 -> V_33 ;
struct V_1 * V_2 = F_22 ( V_23 ) ;
int V_12 ;
F_23 ( L_1 , V_23 -> V_34 , V_31 , V_31 -> V_35 ,
V_31 -> V_36 ) ;
if ( ! F_24 ( V_37 , & V_23 -> V_3 ) )
return;
if ( V_31 -> V_35 == 0 ) {
V_23 -> V_38 . V_39 += V_31 -> V_36 ;
if ( V_2 -> V_58 ( V_2 , V_31 -> V_40 ,
V_31 -> V_36 ) < 0 ) {
F_25 ( L_6 , V_23 -> V_34 ) ;
V_23 -> V_38 . V_41 ++ ;
}
} else if ( V_31 -> V_35 == - V_42 ) {
return;
}
if ( ! F_24 ( V_59 , & V_2 -> V_3 ) )
return;
F_27 ( V_31 , & V_2 -> V_60 ) ;
F_26 ( V_2 -> V_44 ) ;
V_12 = F_28 ( V_31 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_3 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
}
static int F_38 ( struct V_32 * V_23 , T_2 V_48 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
unsigned char * V_49 ;
unsigned int V_50 ;
int V_12 , V_51 = V_24 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
if ( ! V_2 -> V_61 )
return - V_47 ;
V_31 = F_31 ( 0 , V_48 ) ;
if ( ! V_31 )
return - V_16 ;
V_49 = F_33 ( V_51 , V_48 ) ;
if ( ! V_49 ) {
F_34 ( V_31 ) ;
return - V_16 ;
}
V_50 = F_39 ( V_2 -> V_44 , V_2 -> V_61 -> V_54 ) ;
F_40 ( V_31 , V_2 -> V_44 , V_50 , V_49 , V_51 ,
F_37 , V_23 ) ;
V_31 -> V_56 |= V_57 ;
F_26 ( V_2 -> V_44 ) ;
F_27 ( V_31 , & V_2 -> V_60 ) ;
V_12 = F_28 ( V_31 , V_48 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_5 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
F_34 ( V_31 ) ;
return V_12 ;
}
static void F_41 ( struct V_31 * V_31 )
{
struct V_32 * V_23 = V_31 -> V_33 ;
struct V_1 * V_2 = F_22 ( V_23 ) ;
int V_62 , V_12 ;
F_23 ( L_1 , V_23 -> V_34 , V_31 , V_31 -> V_35 ,
V_31 -> V_36 ) ;
if ( ! F_24 ( V_37 , & V_23 -> V_3 ) )
return;
if ( V_31 -> V_35 == 0 ) {
for ( V_62 = 0 ; V_62 < V_31 -> V_63 ; V_62 ++ ) {
unsigned int V_64 = V_31 -> V_65 [ V_62 ] . V_64 ;
unsigned int V_66 = V_31 -> V_65 [ V_62 ] . V_36 ;
if ( V_31 -> V_65 [ V_62 ] . V_35 )
continue;
V_23 -> V_38 . V_39 += V_66 ;
if ( F_19 ( V_2 , V_31 -> V_40 + V_64 ,
V_66 ) < 0 ) {
F_25 ( L_7 , V_23 -> V_34 ) ;
V_23 -> V_38 . V_41 ++ ;
}
}
} else if ( V_31 -> V_35 == - V_42 ) {
return;
}
if ( ! F_24 ( V_67 , & V_2 -> V_3 ) )
return;
F_27 ( V_31 , & V_2 -> V_68 ) ;
V_12 = F_28 ( V_31 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_3 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
}
static inline void F_42 ( struct V_31 * V_31 , int V_13 , int V_69 )
{
int V_62 , V_64 = 0 ;
F_23 ( L_8 , V_13 , V_69 ) ;
for ( V_62 = 0 ; V_62 < V_70 && V_13 >= V_69 ;
V_62 ++ , V_64 += V_69 , V_13 -= V_69 ) {
V_31 -> V_65 [ V_62 ] . V_64 = V_64 ;
V_31 -> V_65 [ V_62 ] . V_66 = V_69 ;
}
if ( V_13 && V_62 < V_70 ) {
V_31 -> V_65 [ V_62 ] . V_64 = V_64 ;
V_31 -> V_65 [ V_62 ] . V_66 = V_13 ;
V_62 ++ ;
}
V_31 -> V_63 = V_62 ;
}
static int F_43 ( struct V_32 * V_23 , T_2 V_48 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
unsigned char * V_49 ;
unsigned int V_50 ;
int V_12 , V_51 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
if ( ! V_2 -> V_71 )
return - V_47 ;
V_31 = F_31 ( V_70 , V_48 ) ;
if ( ! V_31 )
return - V_16 ;
V_51 = F_32 ( V_2 -> V_71 -> V_53 ) *
V_70 ;
V_49 = F_33 ( V_51 , V_48 ) ;
if ( ! V_49 ) {
F_34 ( V_31 ) ;
return - V_16 ;
}
V_50 = F_44 ( V_2 -> V_44 , V_2 -> V_71 -> V_54 ) ;
F_36 ( V_31 , V_2 -> V_44 , V_50 , V_49 , V_51 , F_41 ,
V_23 , V_2 -> V_71 -> V_55 ) ;
V_31 -> V_56 = V_57 | V_72 ;
F_42 ( V_31 , V_51 ,
F_32 ( V_2 -> V_71 -> V_53 ) ) ;
F_27 ( V_31 , & V_2 -> V_68 ) ;
V_12 = F_28 ( V_31 , V_48 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_5 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
F_34 ( V_31 ) ;
return V_12 ;
}
static void F_45 ( struct V_31 * V_31 )
{
struct V_32 * V_23 = V_31 -> V_33 ;
struct V_1 * V_2 = F_22 ( V_23 ) ;
int V_12 ;
F_23 ( L_1 , V_23 -> V_34 , V_31 , V_31 -> V_35 ,
V_31 -> V_36 ) ;
if ( V_31 -> V_35 == 0 ) {
struct V_10 * V_11 ;
V_11 = F_7 ( V_31 -> V_36 , V_15 ) ;
if ( V_11 ) {
memcpy ( F_11 ( V_11 , V_31 -> V_36 ) ,
V_31 -> V_40 , V_31 -> V_36 ) ;
F_46 ( V_23 , V_11 ) ;
}
} else if ( V_31 -> V_35 == - V_42 ) {
return;
}
if ( ! F_24 ( V_73 , & V_2 -> V_3 ) )
return;
F_27 ( V_31 , & V_2 -> V_74 ) ;
F_26 ( V_2 -> V_44 ) ;
V_12 = F_28 ( V_31 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_3 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
}
static int F_47 ( struct V_32 * V_23 , T_2 V_48 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
unsigned char * V_49 ;
unsigned int V_50 ;
int V_12 , V_51 = V_24 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
if ( ! V_2 -> V_75 )
return - V_47 ;
V_31 = F_31 ( 0 , V_48 ) ;
if ( ! V_31 )
return - V_16 ;
V_49 = F_33 ( V_51 , V_48 ) ;
if ( ! V_49 ) {
F_34 ( V_31 ) ;
return - V_16 ;
}
V_50 = F_39 ( V_2 -> V_44 , V_2 -> V_75 -> V_54 ) ;
F_40 ( V_31 , V_2 -> V_44 , V_50 , V_49 , V_51 ,
F_45 , V_23 ) ;
V_31 -> V_56 |= V_57 ;
F_26 ( V_2 -> V_44 ) ;
F_27 ( V_31 , & V_2 -> V_74 ) ;
V_12 = F_28 ( V_31 , V_48 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_5 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_29 ( V_31 ) ;
}
F_34 ( V_31 ) ;
return V_12 ;
}
static void F_48 ( struct V_31 * V_31 )
{
struct V_10 * V_11 = V_31 -> V_33 ;
struct V_32 * V_23 = (struct V_32 * ) V_11 -> V_76 ;
struct V_1 * V_2 = F_22 ( V_23 ) ;
F_23 ( L_1 , V_23 -> V_34 , V_31 , V_31 -> V_35 ,
V_31 -> V_36 ) ;
if ( ! F_24 ( V_37 , & V_23 -> V_3 ) )
goto V_77;
if ( ! V_31 -> V_35 )
V_23 -> V_38 . V_78 += V_31 -> V_79 ;
else
V_23 -> V_38 . V_80 ++ ;
V_77:
F_6 ( & V_2 -> V_81 ) ;
V_2 -> V_82 -- ;
F_14 ( & V_2 -> V_81 ) ;
F_49 ( V_31 -> V_83 ) ;
F_3 ( V_11 ) ;
}
static void F_50 ( struct V_31 * V_31 )
{
struct V_10 * V_11 = V_31 -> V_33 ;
struct V_32 * V_23 = (struct V_32 * ) V_11 -> V_76 ;
F_23 ( L_1 , V_23 -> V_34 , V_31 , V_31 -> V_35 ,
V_31 -> V_36 ) ;
if ( ! F_24 ( V_37 , & V_23 -> V_3 ) )
goto V_77;
if ( ! V_31 -> V_35 )
V_23 -> V_38 . V_78 += V_31 -> V_79 ;
else
V_23 -> V_38 . V_80 ++ ;
V_77:
F_49 ( V_31 -> V_83 ) ;
F_3 ( V_11 ) ;
}
static int F_51 ( struct V_32 * V_23 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
int V_12 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
if ( V_2 -> V_84 ) {
V_12 = V_2 -> V_84 ( V_23 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_12 = F_52 ( V_2 -> V_85 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_85 -> V_86 = 1 ;
if ( F_53 ( V_43 , & V_2 -> V_3 ) )
goto V_77;
V_12 = F_30 ( V_23 , V_87 ) ;
if ( V_12 < 0 )
goto V_88;
V_12 = F_38 ( V_23 , V_87 ) ;
if ( V_12 < 0 ) {
F_54 ( & V_2 -> V_45 ) ;
goto V_88;
}
F_55 ( V_59 , & V_2 -> V_3 ) ;
F_38 ( V_23 , V_87 ) ;
if ( V_2 -> V_89 ) {
if ( ! F_47 ( V_23 , V_87 ) )
F_55 ( V_73 , & V_2 -> V_3 ) ;
}
V_77:
F_56 ( V_2 -> V_85 ) ;
return 0 ;
V_88:
F_57 ( V_43 , & V_2 -> V_3 ) ;
F_56 ( V_2 -> V_85 ) ;
return V_12 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_45 ) ;
F_54 ( & V_2 -> V_60 ) ;
F_54 ( & V_2 -> V_68 ) ;
F_54 ( & V_2 -> V_74 ) ;
}
static int F_59 ( struct V_32 * V_23 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
int V_12 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
F_60 ( & V_2 -> V_90 ) ;
F_60 ( & V_2 -> V_91 ) ;
F_57 ( V_67 , & V_2 -> V_3 ) ;
F_57 ( V_59 , & V_2 -> V_3 ) ;
F_57 ( V_43 , & V_2 -> V_3 ) ;
F_57 ( V_73 , & V_2 -> V_3 ) ;
F_58 ( V_2 ) ;
F_1 ( V_2 ) ;
V_12 = F_52 ( V_2 -> V_85 ) ;
if ( V_12 < 0 )
goto V_88;
V_2 -> V_85 -> V_86 = 0 ;
F_56 ( V_2 -> V_85 ) ;
V_88:
F_61 ( & V_2 -> V_92 ) ;
return 0 ;
}
static int F_62 ( struct V_32 * V_23 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
F_23 ( L_4 , V_23 -> V_34 ) ;
F_54 ( & V_2 -> V_93 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_31 * F_63 ( struct V_32 * V_23 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_94 * V_95 ;
struct V_31 * V_31 ;
unsigned int V_50 ;
V_31 = F_31 ( 0 , V_87 ) ;
if ( ! V_31 )
return F_64 ( - V_16 ) ;
V_95 = F_33 ( sizeof( * V_95 ) , V_87 ) ;
if ( ! V_95 ) {
F_34 ( V_31 ) ;
return F_64 ( - V_16 ) ;
}
V_95 -> V_96 = V_2 -> V_97 ;
V_95 -> V_98 = V_2 -> V_99 ;
V_95 -> V_100 = 0 ;
V_95 -> V_101 = 0 ;
V_95 -> V_102 = F_65 ( V_11 -> V_13 ) ;
V_50 = F_66 ( V_2 -> V_44 , 0x00 ) ;
F_67 ( V_31 , V_2 -> V_44 , V_50 , ( void * ) V_95 ,
V_11 -> V_2 , V_11 -> V_13 , F_48 , V_11 ) ;
V_11 -> V_76 = ( void * ) V_23 ;
return V_31 ;
}
static struct V_31 * F_68 ( struct V_32 * V_23 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
unsigned int V_50 ;
if ( ! V_2 -> V_103 )
return F_64 ( - V_47 ) ;
V_31 = F_31 ( 0 , V_87 ) ;
if ( ! V_31 )
return F_64 ( - V_16 ) ;
V_50 = F_69 ( V_2 -> V_44 , V_2 -> V_103 -> V_54 ) ;
F_40 ( V_31 , V_2 -> V_44 , V_50 ,
V_11 -> V_2 , V_11 -> V_13 , F_48 , V_11 ) ;
V_11 -> V_76 = ( void * ) V_23 ;
return V_31 ;
}
static struct V_31 * F_70 ( struct V_32 * V_23 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
unsigned int V_50 ;
if ( ! V_2 -> V_104 )
return F_64 ( - V_47 ) ;
V_31 = F_31 ( V_70 , V_87 ) ;
if ( ! V_31 )
return F_64 ( - V_16 ) ;
V_50 = F_71 ( V_2 -> V_44 , V_2 -> V_104 -> V_54 ) ;
F_36 ( V_31 , V_2 -> V_44 , V_50 ,
V_11 -> V_2 , V_11 -> V_13 , F_50 ,
V_11 , V_2 -> V_104 -> V_55 ) ;
V_31 -> V_56 = V_72 ;
F_42 ( V_31 , V_11 -> V_13 ,
F_32 ( V_2 -> V_104 -> V_53 ) ) ;
V_11 -> V_76 = ( void * ) V_23 ;
return V_31 ;
}
static int F_72 ( struct V_32 * V_23 , struct V_31 * V_31 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
int V_12 ;
F_27 ( V_31 , & V_2 -> V_93 ) ;
V_12 = F_28 ( V_31 , V_87 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_46 && V_12 != - V_47 )
F_25 ( L_5 ,
V_23 -> V_34 , V_31 , - V_12 ) ;
F_49 ( V_31 -> V_83 ) ;
F_29 ( V_31 ) ;
} else {
F_26 ( V_2 -> V_44 ) ;
}
F_34 ( V_31 ) ;
return V_12 ;
}
static int F_73 ( struct V_32 * V_23 , struct V_31 * V_31 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
unsigned long V_3 ;
bool V_105 ;
F_2 ( & V_2 -> V_81 , V_3 ) ;
V_105 = F_24 ( V_106 , & V_2 -> V_3 ) ;
if ( ! V_105 )
V_2 -> V_82 ++ ;
F_4 ( & V_2 -> V_81 , V_3 ) ;
if ( ! V_105 )
return F_72 ( V_23 , V_31 ) ;
F_27 ( V_31 , & V_2 -> V_92 ) ;
F_74 ( & V_2 -> V_91 ) ;
F_34 ( V_31 ) ;
return 0 ;
}
static int F_75 ( struct V_32 * V_23 , struct V_10 * V_11 )
{
struct V_31 * V_31 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
switch ( F_8 ( V_11 ) ) {
case V_107 :
V_31 = F_63 ( V_23 , V_11 ) ;
if ( F_76 ( V_31 ) )
return F_77 ( V_31 ) ;
V_23 -> V_38 . V_108 ++ ;
return F_73 ( V_23 , V_31 ) ;
case V_25 :
V_31 = F_68 ( V_23 , V_11 ) ;
if ( F_76 ( V_31 ) )
return F_77 ( V_31 ) ;
V_23 -> V_38 . V_109 ++ ;
return F_73 ( V_23 , V_31 ) ;
case V_29 :
if ( F_78 ( V_23 , V_110 ) < 1 )
return - V_47 ;
V_31 = F_70 ( V_23 , V_11 ) ;
if ( F_76 ( V_31 ) )
return F_77 ( V_31 ) ;
V_23 -> V_38 . V_111 ++ ;
return F_72 ( V_23 , V_31 ) ;
}
return - V_21 ;
}
static void F_79 ( struct V_32 * V_23 , unsigned int V_112 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
F_23 ( L_9 , V_23 -> V_34 , V_112 ) ;
if ( F_78 ( V_23 , V_110 ) != V_2 -> V_113 ) {
V_2 -> V_113 = F_78 ( V_23 , V_110 ) ;
F_74 ( & V_2 -> V_90 ) ;
}
}
static inline int F_80 ( struct V_32 * V_23 , int V_114 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_115 * V_85 = V_2 -> V_116 ;
struct V_117 * V_118 ;
int V_62 , V_12 ;
if ( ! V_2 -> V_116 )
return - V_47 ;
V_12 = F_81 ( V_2 -> V_44 , 1 , V_114 ) ;
if ( V_12 < 0 ) {
F_25 ( L_10 , V_23 -> V_34 , - V_12 ) ;
return V_12 ;
}
V_2 -> V_119 = V_114 ;
V_2 -> V_104 = NULL ;
V_2 -> V_71 = NULL ;
for ( V_62 = 0 ; V_62 < V_85 -> V_120 -> V_121 . V_122 ; V_62 ++ ) {
V_118 = & V_85 -> V_120 -> V_123 [ V_62 ] . V_121 ;
if ( ! V_2 -> V_104 && F_82 ( V_118 ) ) {
V_2 -> V_104 = V_118 ;
continue;
}
if ( ! V_2 -> V_71 && F_83 ( V_118 ) ) {
V_2 -> V_71 = V_118 ;
continue;
}
}
if ( ! V_2 -> V_104 || ! V_2 -> V_71 ) {
F_25 ( L_11 , V_23 -> V_34 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_84 ( struct V_124 * V_90 )
{
struct V_1 * V_2 = F_85 ( V_90 , struct V_1 , V_90 ) ;
struct V_32 * V_23 = V_2 -> V_23 ;
int V_125 ;
int V_12 ;
if ( V_2 -> V_113 > 0 ) {
if ( ! F_24 ( V_126 , & V_2 -> V_3 ) ) {
V_12 = F_52 ( V_2 -> V_116 ? V_2 -> V_116 : V_2 -> V_85 ) ;
if ( V_12 < 0 ) {
F_57 ( V_67 , & V_2 -> V_3 ) ;
F_54 ( & V_2 -> V_68 ) ;
return;
}
F_55 ( V_126 , & V_2 -> V_3 ) ;
}
if ( V_23 -> V_127 & 0x0020 ) {
static const int V_128 [ 3 ] = { 2 , 4 , 5 } ;
V_125 = V_128 [ V_2 -> V_113 - 1 ] ;
} else {
V_125 = V_2 -> V_113 ;
}
if ( V_2 -> V_119 != V_125 ) {
unsigned long V_3 ;
F_57 ( V_67 , & V_2 -> V_3 ) ;
F_54 ( & V_2 -> V_68 ) ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
if ( F_80 ( V_23 , V_125 ) < 0 )
return;
}
if ( ! F_53 ( V_67 , & V_2 -> V_3 ) ) {
if ( F_43 ( V_23 , V_87 ) < 0 )
F_57 ( V_67 , & V_2 -> V_3 ) ;
else
F_43 ( V_23 , V_87 ) ;
}
} else {
F_57 ( V_67 , & V_2 -> V_3 ) ;
F_54 ( & V_2 -> V_68 ) ;
F_80 ( V_23 , 0 ) ;
if ( F_86 ( V_126 , & V_2 -> V_3 ) )
F_56 ( V_2 -> V_116 ? V_2 -> V_116 : V_2 -> V_85 ) ;
}
}
static void F_87 ( struct V_124 * V_90 )
{
struct V_1 * V_2 = F_85 ( V_90 , struct V_1 , V_91 ) ;
int V_12 ;
V_12 = F_52 ( V_2 -> V_85 ) ;
if ( V_12 < 0 )
return;
F_56 ( V_2 -> V_85 ) ;
}
static int F_88 ( struct V_32 * V_23 )
{
struct V_10 * V_11 ;
T_3 V_129 = 0x00 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
V_11 = F_89 ( V_23 , 0xfc3b , 1 , & V_129 , V_130 ) ;
if ( F_76 ( V_11 ) )
F_25 ( L_12 , - F_77 ( V_11 ) ) ;
else
F_3 ( V_11 ) ;
return 0 ;
}
static int F_90 ( struct V_32 * V_23 )
{
struct V_131 * V_132 ;
struct V_10 * V_11 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
V_11 = F_89 ( V_23 , V_133 , 0 , NULL ,
V_130 ) ;
if ( F_76 ( V_11 ) ) {
int V_12 = F_77 ( V_11 ) ;
F_25 ( L_13 , V_23 -> V_34 , V_12 ) ;
return V_12 ;
}
if ( V_11 -> V_13 != sizeof( struct V_131 ) ) {
F_25 ( L_14 , V_23 -> V_34 ) ;
F_3 ( V_11 ) ;
return - V_134 ;
}
V_132 = (struct V_131 * ) V_11 -> V_2 ;
if ( F_32 ( V_132 -> V_135 ) != 10 ||
F_32 ( V_132 -> V_136 ) == 0x0c5c ) {
F_57 ( V_137 , & V_23 -> V_138 ) ;
F_55 ( V_139 , & V_23 -> V_138 ) ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static const struct V_140 * F_91 ( struct V_32 * V_23 ,
struct V_141 * V_142 )
{
const struct V_140 * V_143 ;
char V_144 [ 64 ] ;
int V_145 ;
snprintf ( V_144 , sizeof( V_144 ) ,
L_15 ,
V_142 -> V_146 , V_142 -> V_147 , V_142 -> V_148 ,
V_142 -> V_149 , V_142 -> V_150 , V_142 -> V_151 ,
V_142 -> V_152 , V_142 -> V_153 ) ;
V_145 = F_92 ( & V_143 , V_144 , & V_23 -> V_76 ) ;
if ( V_145 < 0 ) {
if ( V_145 == - V_154 ) {
F_25 ( L_16 ,
V_23 -> V_34 , V_145 ) ;
return NULL ;
}
F_25 ( L_17 ,
V_23 -> V_34 , V_144 , V_145 ) ;
snprintf ( V_144 , sizeof( V_144 ) , L_18 ,
V_142 -> V_146 , V_142 -> V_147 ) ;
if ( F_92 ( & V_143 , V_144 , & V_23 -> V_76 ) < 0 ) {
F_25 ( L_19 ,
V_23 -> V_34 , V_144 ) ;
return NULL ;
}
}
F_93 ( L_20 , V_23 -> V_34 , V_144 ) ;
return V_143 ;
}
static int F_94 ( struct V_32 * V_23 ,
const struct V_140 * V_143 ,
const T_3 * * V_155 , int * V_156 )
{
struct V_10 * V_11 ;
struct V_157 * V_158 ;
const T_3 * V_159 ;
struct F_12 * V_112 = NULL ;
const T_3 * V_160 = NULL ;
int V_161 = V_143 -> V_51 - ( * V_155 - V_143 -> V_2 ) ;
if ( V_161 > V_162 && * V_155 [ 0 ] != 0x01 ) {
F_25 ( L_21 , V_23 -> V_34 ) ;
return - V_154 ;
}
( * V_155 ) ++ ;
V_161 -- ;
V_158 = (struct V_157 * ) ( * V_155 ) ;
* V_155 += sizeof( * V_158 ) ;
V_161 -= sizeof( * V_158 ) ;
if ( V_161 < V_158 -> V_20 ) {
F_25 ( L_22 , V_23 -> V_34 ) ;
return - V_163 ;
}
if ( * V_156 && F_32 ( V_158 -> V_164 ) == 0xfc8e )
* V_156 = 0 ;
V_159 = * V_155 ;
* V_155 += V_158 -> V_20 ;
V_161 -= V_158 -> V_20 ;
while ( V_161 > V_18 && * V_155 [ 0 ] == 0x02 ) {
( * V_155 ) ++ ;
V_161 -- ;
V_112 = (struct F_12 * ) ( * V_155 ) ;
* V_155 += sizeof( * V_112 ) ;
V_161 -= sizeof( * V_112 ) ;
if ( V_161 < V_112 -> V_20 ) {
F_25 ( L_23 ,
V_23 -> V_34 ) ;
return - V_163 ;
}
V_160 = * V_155 ;
* V_155 += V_112 -> V_20 ;
V_161 -= V_112 -> V_20 ;
}
if ( ! V_112 || ! V_160 || V_161 < 0 ) {
F_25 ( L_24 , V_23 -> V_34 ) ;
return - V_163 ;
}
V_11 = F_95 ( V_23 , F_32 ( V_158 -> V_164 ) , V_158 -> V_20 ,
V_159 , V_112 -> V_112 , V_130 ) ;
if ( F_76 ( V_11 ) ) {
F_25 ( L_25 ,
V_23 -> V_34 , V_158 -> V_164 , F_77 ( V_11 ) ) ;
return F_77 ( V_11 ) ;
}
if ( V_11 -> V_13 != V_112 -> V_20 ) {
F_25 ( L_26 , V_23 -> V_34 ,
F_32 ( V_158 -> V_164 ) ) ;
F_3 ( V_11 ) ;
return - V_163 ;
}
if ( memcmp ( V_11 -> V_2 , V_160 , V_112 -> V_20 ) ) {
F_25 ( L_27 ,
V_23 -> V_34 , F_32 ( V_158 -> V_164 ) ) ;
F_3 ( V_11 ) ;
return - V_163 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_96 ( struct V_32 * V_23 )
{
struct V_10 * V_11 ;
const struct V_140 * V_143 ;
const T_3 * V_155 ;
int V_156 , V_12 ;
struct V_141 V_142 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
V_11 = F_89 ( V_23 , V_165 , 0 , NULL , V_130 ) ;
if ( F_76 ( V_11 ) ) {
F_25 ( L_28 ,
V_23 -> V_34 , F_77 ( V_11 ) ) ;
return F_77 ( V_11 ) ;
}
F_3 ( V_11 ) ;
V_12 = F_97 ( V_23 , & V_142 ) ;
if ( V_12 )
return V_12 ;
F_93 ( L_29 ,
V_23 -> V_34 , V_142 . V_146 , V_142 . V_147 , V_142 . V_148 ,
V_142 . V_149 , V_142 . V_150 , V_142 . V_151 ,
V_142 . V_152 , V_142 . V_153 , V_142 . V_166 ) ;
if ( V_142 . V_166 ) {
F_93 ( L_30 ,
V_23 -> V_34 , V_142 . V_166 ) ;
goto V_167;
}
V_143 = F_91 ( V_23 , & V_142 ) ;
if ( ! V_143 )
goto V_167;
V_155 = V_143 -> V_2 ;
V_12 = F_98 ( V_23 ) ;
if ( V_12 ) {
F_99 ( V_143 ) ;
return V_12 ;
}
V_156 = 1 ;
while ( V_143 -> V_51 > V_155 - V_143 -> V_2 ) {
int V_145 ;
V_145 = F_94 ( V_23 , V_143 , & V_155 ,
& V_156 ) ;
if ( V_145 < 0 )
goto V_168;
}
F_99 ( V_143 ) ;
if ( V_156 )
goto V_169;
V_12 = F_100 ( V_23 , true , true ) ;
if ( V_12 )
return V_12 ;
F_93 ( L_31 ,
V_23 -> V_34 ) ;
goto V_167;
V_169:
V_12 = F_100 ( V_23 , false , false ) ;
if ( V_12 )
return V_12 ;
F_93 ( L_32 , V_23 -> V_34 ) ;
goto V_167;
V_168:
F_99 ( V_143 ) ;
V_12 = F_100 ( V_23 , true , false ) ;
if ( V_12 )
return V_12 ;
F_93 ( L_33 ,
V_23 -> V_34 ) ;
V_167:
F_101 ( V_23 , false ) ;
F_102 ( V_23 ) ;
return 0 ;
}
static int F_103 ( struct V_32 * V_23 , T_4 V_164 )
{
struct V_10 * V_11 ;
struct F_12 * V_170 ;
struct V_171 * V_112 ;
V_11 = F_7 ( sizeof( * V_170 ) + sizeof( * V_112 ) + 1 , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_170 = (struct F_12 * ) F_11 ( V_11 , sizeof( * V_170 ) ) ;
V_170 -> V_112 = V_172 ;
V_170 -> V_20 = sizeof( * V_112 ) + 1 ;
V_112 = (struct V_171 * ) F_11 ( V_11 , sizeof( * V_112 ) ) ;
V_112 -> V_173 = 0x01 ;
V_112 -> V_164 = F_104 ( V_164 ) ;
* F_11 ( V_11 , 1 ) = 0x00 ;
F_8 ( V_11 ) = V_17 ;
return F_18 ( V_23 , V_11 ) ;
}
static int F_105 ( struct V_1 * V_2 , void * V_8 ,
int V_9 )
{
if ( F_24 ( V_174 , & V_2 -> V_3 ) )
return F_5 ( V_2 , V_8 , V_9 ) ;
return F_15 ( V_2 , V_8 , V_9 ) ;
}
static void F_106 ( struct V_1 * V_2 , const void * V_175 ,
unsigned int V_13 )
{
const struct V_176 * V_112 = V_175 ;
if ( V_13 != sizeof( * V_112 ) )
return;
if ( F_86 ( V_177 , & V_2 -> V_3 ) ) {
F_107 () ;
F_108 ( & V_2 -> V_3 , V_177 ) ;
}
}
static void F_109 ( struct V_1 * V_2 ,
const void * V_175 , unsigned int V_13 )
{
const struct V_178 * V_112 = V_175 ;
if ( V_13 != sizeof( * V_112 ) )
return;
if ( V_112 -> V_179 )
F_55 ( V_180 , & V_2 -> V_3 ) ;
if ( F_86 ( V_181 , & V_2 -> V_3 ) &&
F_24 ( V_182 , & V_2 -> V_3 ) ) {
F_107 () ;
F_108 ( & V_2 -> V_3 , V_181 ) ;
}
}
static int F_110 ( struct V_32 * V_23 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
if ( F_24 ( V_174 , & V_2 -> V_3 ) ) {
struct F_12 * V_170 = ( void * ) V_11 -> V_2 ;
if ( V_11 -> V_13 > V_18 && V_170 -> V_112 == 0xff &&
V_170 -> V_20 > 0 ) {
const void * V_175 = V_11 -> V_2 + V_18 + 1 ;
unsigned int V_13 = V_11 -> V_13 - V_18 - 1 ;
switch ( V_11 -> V_2 [ 2 ] ) {
case 0x02 :
F_106 ( V_2 , V_175 , V_13 ) ;
break;
case 0x06 :
F_109 ( V_2 , V_175 , V_13 ) ;
break;
}
}
}
return F_18 ( V_23 , V_11 ) ;
}
static int F_111 ( struct V_32 * V_23 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
switch ( F_8 ( V_11 ) ) {
case V_107 :
if ( F_24 ( V_174 , & V_2 -> V_3 ) ) {
struct V_157 * V_158 = ( void * ) V_11 -> V_2 ;
T_4 V_164 = F_32 ( V_158 -> V_164 ) ;
if ( V_164 == 0xfc09 )
V_31 = F_68 ( V_23 , V_11 ) ;
else
V_31 = F_63 ( V_23 , V_11 ) ;
if ( V_164 == 0xfc01 )
F_103 ( V_23 , V_164 ) ;
} else {
V_31 = F_63 ( V_23 , V_11 ) ;
}
if ( F_76 ( V_31 ) )
return F_77 ( V_31 ) ;
V_23 -> V_38 . V_108 ++ ;
return F_73 ( V_23 , V_31 ) ;
case V_25 :
V_31 = F_68 ( V_23 , V_11 ) ;
if ( F_76 ( V_31 ) )
return F_77 ( V_31 ) ;
V_23 -> V_38 . V_109 ++ ;
return F_73 ( V_23 , V_31 ) ;
case V_29 :
if ( F_78 ( V_23 , V_110 ) < 1 )
return - V_47 ;
V_31 = F_70 ( V_23 , V_11 ) ;
if ( F_76 ( V_31 ) )
return F_77 ( V_31 ) ;
V_23 -> V_38 . V_111 ++ ;
return F_72 ( V_23 , V_31 ) ;
}
return - V_21 ;
}
static int F_112 ( struct V_32 * V_23 )
{
static const T_3 V_183 [] = { 0x00 , 0x01 , 0x00 , 0x01 ,
0x00 , 0x08 , 0x04 , 0x00 } ;
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_10 * V_11 ;
struct V_141 V_142 ;
struct V_184 * V_185 ;
const struct V_140 * V_143 ;
const T_3 * V_155 ;
T_5 V_186 ;
char V_144 [ 64 ] ;
T_6 V_187 , V_188 , V_189 ;
unsigned long long V_190 ;
int V_12 ;
F_23 ( L_4 , V_23 -> V_34 ) ;
V_187 = F_113 () ;
V_12 = F_97 ( V_23 , & V_142 ) ;
if ( V_12 )
return V_12 ;
if ( V_142 . V_146 != 0x37 ) {
F_25 ( L_34 ,
V_23 -> V_34 , V_142 . V_146 ) ;
return - V_154 ;
}
if ( V_142 . V_147 != 0x0b && V_142 . V_147 != 0x0c ) {
F_25 ( L_35 ,
V_23 -> V_34 , V_142 . V_147 ) ;
return - V_154 ;
}
F_114 ( V_23 , & V_142 ) ;
if ( V_142 . V_149 == 0x23 ) {
F_57 ( V_174 , & V_2 -> V_3 ) ;
F_102 ( V_23 ) ;
return 0 ;
}
if ( V_142 . V_149 != 0x06 ) {
F_25 ( L_36 ,
V_23 -> V_34 , V_142 . V_149 ) ;
return - V_47 ;
}
V_11 = F_89 ( V_23 , 0xfc0d , 0 , NULL , V_130 ) ;
if ( F_76 ( V_11 ) ) {
F_25 ( L_37 ,
V_23 -> V_34 , F_77 ( V_11 ) ) ;
return F_77 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_185 ) ) {
F_25 ( L_38 , V_23 -> V_34 ) ;
F_3 ( V_11 ) ;
return - V_21 ;
}
V_185 = (struct V_184 * ) V_11 -> V_2 ;
F_93 ( L_39 , V_23 -> V_34 ,
F_32 ( V_185 -> V_191 ) ) ;
F_93 ( L_40 , V_23 -> V_34 ,
V_185 -> V_192 ? L_41 : L_42 ) ;
F_93 ( L_43 , V_23 -> V_34 ,
V_185 -> V_193 ? L_41 : L_42 ) ;
F_93 ( L_44 , V_23 -> V_34 ,
V_185 -> V_194 ? L_41 : L_42 ) ;
F_93 ( L_45 , V_23 -> V_34 ,
V_185 -> V_195 ? L_41 : L_42 ) ;
F_93 ( L_46 , V_23 -> V_34 ,
V_185 -> V_196 , V_185 -> V_197 ,
2000 + V_185 -> V_198 ) ;
if ( V_185 -> V_199 != 0x00 ) {
F_25 ( L_47 ,
V_23 -> V_34 , V_185 -> V_199 ) ;
F_3 ( V_11 ) ;
return - V_154 ;
}
if ( ! F_115 ( & V_185 -> V_200 , V_201 ) ) {
F_93 ( L_48 , V_23 -> V_34 ) ;
F_55 ( V_202 , & V_23 -> V_138 ) ;
}
snprintf ( V_144 , sizeof( V_144 ) , L_49 ,
F_32 ( V_185 -> V_191 ) ) ;
V_12 = F_92 ( & V_143 , V_144 , & V_23 -> V_76 ) ;
if ( V_12 < 0 ) {
F_25 ( L_50 ,
V_23 -> V_34 , V_12 ) ;
F_3 ( V_11 ) ;
return V_12 ;
}
F_93 ( L_51 , V_23 -> V_34 , V_144 ) ;
snprintf ( V_144 , sizeof( V_144 ) , L_52 ,
F_32 ( V_185 -> V_191 ) ) ;
F_3 ( V_11 ) ;
if ( V_143 -> V_51 < 644 ) {
F_25 ( L_53 ,
V_23 -> V_34 , V_143 -> V_51 ) ;
V_12 = - V_203 ;
goto V_77;
}
F_55 ( V_181 , & V_2 -> V_3 ) ;
V_12 = F_116 ( V_23 , 0x00 , 128 , V_143 -> V_2 ) ;
if ( V_12 < 0 ) {
F_25 ( L_54 ,
V_23 -> V_34 , V_12 ) ;
goto V_77;
}
V_12 = F_116 ( V_23 , 0x03 , 256 , V_143 -> V_2 + 128 ) ;
if ( V_12 < 0 ) {
F_25 ( L_55 ,
V_23 -> V_34 , V_12 ) ;
goto V_77;
}
V_12 = F_116 ( V_23 , 0x02 , 256 , V_143 -> V_2 + 388 ) ;
if ( V_12 < 0 ) {
F_25 ( L_56 ,
V_23 -> V_34 , V_12 ) ;
goto V_77;
}
V_155 = V_143 -> V_2 + 644 ;
V_186 = 0 ;
while ( V_155 - V_143 -> V_2 < V_143 -> V_51 ) {
struct V_157 * V_158 = ( void * ) ( V_155 + V_186 ) ;
V_186 += sizeof( * V_158 ) + V_158 -> V_20 ;
if ( ! ( V_186 % 4 ) ) {
V_12 = F_116 ( V_23 , 0x01 , V_186 , V_155 ) ;
if ( V_12 < 0 ) {
F_25 ( L_57 ,
V_23 -> V_34 , V_12 ) ;
goto V_77;
}
V_155 += V_186 ;
V_186 = 0 ;
}
}
F_55 ( V_182 , & V_2 -> V_3 ) ;
F_93 ( L_58 , V_23 -> V_34 ) ;
V_12 = F_117 ( & V_2 -> V_3 , V_181 ,
V_204 ,
F_118 ( 5000 ) ) ;
if ( V_12 == 1 ) {
F_25 ( L_59 , V_23 -> V_34 ) ;
V_12 = - V_205 ;
goto V_77;
}
if ( V_12 ) {
F_25 ( L_60 , V_23 -> V_34 ) ;
V_12 = - V_206 ;
goto V_77;
}
if ( F_24 ( V_180 , & V_2 -> V_3 ) ) {
F_25 ( L_61 , V_23 -> V_34 ) ;
V_12 = - V_207 ;
goto V_77;
}
V_189 = F_113 () ;
V_188 = F_119 ( V_189 , V_187 ) ;
V_190 = ( unsigned long long ) F_120 ( V_188 ) >> 10 ;
F_93 ( L_62 , V_23 -> V_34 , V_190 ) ;
V_77:
F_99 ( V_143 ) ;
if ( V_12 < 0 )
return V_12 ;
V_187 = F_113 () ;
F_55 ( V_177 , & V_2 -> V_3 ) ;
V_11 = F_89 ( V_23 , 0xfc01 , sizeof( V_183 ) , V_183 ,
V_130 ) ;
if ( F_76 ( V_11 ) )
return F_77 ( V_11 ) ;
F_3 ( V_11 ) ;
F_93 ( L_63 , V_23 -> V_34 ) ;
V_12 = F_117 ( & V_2 -> V_3 , V_177 ,
V_204 ,
F_118 ( 1000 ) ) ;
if ( V_12 == 1 ) {
F_25 ( L_64 , V_23 -> V_34 ) ;
return - V_205 ;
}
if ( V_12 ) {
F_25 ( L_65 , V_23 -> V_34 ) ;
return - V_206 ;
}
V_189 = F_113 () ;
V_188 = F_119 ( V_189 , V_187 ) ;
V_190 = ( unsigned long long ) F_120 ( V_188 ) >> 10 ;
F_93 ( L_66 , V_23 -> V_34 , V_190 ) ;
F_57 ( V_174 , & V_2 -> V_3 ) ;
F_121 ( V_23 , V_144 ) ;
F_122 ( V_23 , false ) ;
return 0 ;
}
static int F_123 ( struct V_32 * V_23 )
{
struct V_10 * V_11 ;
long V_145 ;
V_11 = F_89 ( V_23 , 0xfc3f , 0 , NULL , V_130 ) ;
if ( F_76 ( V_11 ) ) {
V_145 = F_77 ( V_11 ) ;
F_25 ( L_67 ,
V_23 -> V_34 , V_145 ) ;
return V_145 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_124 ( struct V_32 * V_23 ,
const T_7 * V_208 )
{
struct V_10 * V_11 ;
T_3 V_49 [ 8 ] ;
long V_145 ;
V_49 [ 0 ] = 0xfe ;
V_49 [ 1 ] = sizeof( T_7 ) ;
memcpy ( V_49 + 2 , V_208 , sizeof( T_7 ) ) ;
V_11 = F_89 ( V_23 , 0xfc22 , sizeof( V_49 ) , V_49 , V_130 ) ;
if ( F_76 ( V_11 ) ) {
V_145 = F_77 ( V_11 ) ;
F_25 ( L_68 ,
V_23 -> V_34 , V_145 ) ;
return V_145 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_125 ( struct V_32 * V_23 ,
const T_7 * V_208 )
{
struct V_10 * V_11 ;
T_3 V_49 [ 10 ] ;
long V_145 ;
V_49 [ 0 ] = 0x01 ;
V_49 [ 1 ] = 0x01 ;
V_49 [ 2 ] = 0x00 ;
V_49 [ 3 ] = sizeof( T_7 ) ;
memcpy ( V_49 + 4 , V_208 , sizeof( T_7 ) ) ;
V_11 = F_89 ( V_23 , 0xfc0b , sizeof( V_49 ) , V_49 , V_130 ) ;
if ( F_76 ( V_11 ) ) {
V_145 = F_77 ( V_11 ) ;
F_25 ( L_69 ,
V_23 -> V_34 , V_145 ) ;
return V_145 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_126 ( struct V_32 * V_23 , T_3 V_209 ,
void * V_2 , T_8 V_51 )
{
struct V_1 * V_210 = F_22 ( V_23 ) ;
struct V_211 * V_44 = V_210 -> V_44 ;
int V_50 , V_12 ;
T_3 * V_49 ;
V_49 = F_33 ( V_51 , V_87 ) ;
if ( ! V_49 )
return - V_16 ;
V_50 = F_127 ( V_44 , 0 ) ;
V_12 = F_128 ( V_44 , V_50 , V_209 , V_212 | V_213 ,
0 , 0 , V_49 , V_51 , V_214 ) ;
if ( V_12 < 0 ) {
F_25 ( L_70 , V_23 -> V_34 , V_12 ) ;
goto V_77;
}
memcpy ( V_2 , V_49 , V_51 ) ;
V_77:
F_49 ( V_49 ) ;
return V_12 ;
}
static int F_129 ( struct V_32 * V_23 ,
const struct V_140 * V_140 ,
T_9 V_215 )
{
struct V_1 * V_210 = F_22 ( V_23 ) ;
struct V_211 * V_44 = V_210 -> V_44 ;
T_9 V_9 , V_51 , V_216 = 0 ;
int V_50 , V_13 , V_12 ;
T_3 * V_49 ;
V_49 = F_33 ( V_217 , V_87 ) ;
if ( ! V_49 )
return - V_16 ;
V_9 = V_140 -> V_51 ;
V_51 = F_10 ( T_9 , V_9 , V_215 ) ;
memcpy ( V_49 , V_140 -> V_2 , V_51 ) ;
V_50 = F_66 ( V_44 , 0 ) ;
V_12 = F_128 ( V_44 , V_50 , V_218 , V_212 ,
0 , 0 , V_49 , V_51 , V_214 ) ;
if ( V_12 < 0 ) {
F_25 ( L_71 , V_23 -> V_34 , V_12 ) ;
goto V_77;
}
V_216 += V_51 ;
V_9 -= V_51 ;
while ( V_9 ) {
V_51 = F_10 ( T_9 , V_9 , V_217 ) ;
memcpy ( V_49 , V_140 -> V_2 + V_216 , V_51 ) ;
V_50 = F_69 ( V_44 , 0x02 ) ;
V_12 = F_130 ( V_44 , V_50 , V_49 , V_51 , & V_13 ,
V_219 ) ;
if ( V_12 < 0 ) {
F_25 ( L_72 ,
V_23 -> V_34 , V_216 , V_140 -> V_51 , V_12 ) ;
break;
}
if ( V_51 != V_13 ) {
F_25 ( L_73 , V_23 -> V_34 ) ;
V_12 = - V_21 ;
break;
}
V_216 += V_51 ;
V_9 -= V_51 ;
}
V_77:
F_49 ( V_49 ) ;
return V_12 ;
}
static int F_131 ( struct V_32 * V_23 ,
struct V_220 * V_142 ,
const struct V_221 * V_222 )
{
struct V_223 * V_224 ;
const struct V_140 * V_143 ;
T_5 V_225 , V_226 ;
T_8 V_227 , V_228 ;
char V_144 [ 64 ] ;
int V_12 ;
V_225 = F_132 ( V_142 -> V_229 ) ;
V_226 = F_132 ( V_142 -> V_230 ) ;
snprintf ( V_144 , sizeof( V_144 ) , L_74 , V_225 ) ;
V_12 = F_92 ( & V_143 , V_144 , & V_23 -> V_76 ) ;
if ( V_12 ) {
F_25 ( L_75 ,
V_23 -> V_34 , V_144 , V_12 ) ;
return V_12 ;
}
F_93 ( L_76 , V_23 -> V_34 , V_144 ) ;
V_224 = (struct V_223 * ) ( V_143 -> V_2 + V_222 -> V_231 ) ;
V_227 = F_32 ( V_224 -> V_229 ) ;
V_228 = F_32 ( V_224 -> V_230 ) ;
F_93 ( L_77
L_78 , V_23 -> V_34 , V_227 , V_228 , V_225 ,
V_226 ) ;
if ( V_227 != V_225 || V_228 <= V_226 ) {
F_25 ( L_79 ,
V_23 -> V_34 ) ;
V_12 = - V_154 ;
goto V_77;
}
V_12 = F_129 ( V_23 , V_143 , V_222 -> V_232 ) ;
V_77:
F_99 ( V_143 ) ;
return V_12 ;
}
static int F_133 ( struct V_32 * V_23 ,
struct V_220 * V_142 ,
const struct V_221 * V_222 )
{
const struct V_140 * V_143 ;
char V_144 [ 64 ] ;
int V_12 ;
snprintf ( V_144 , sizeof( V_144 ) , L_80 ,
F_132 ( V_142 -> V_229 ) ) ;
V_12 = F_92 ( & V_143 , V_144 , & V_23 -> V_76 ) ;
if ( V_12 ) {
F_25 ( L_81 ,
V_23 -> V_34 , V_144 , V_12 ) ;
return V_12 ;
}
F_93 ( L_82 , V_23 -> V_34 , V_144 ) ;
V_12 = F_129 ( V_23 , V_143 , V_222 -> V_233 ) ;
F_99 ( V_143 ) ;
return V_12 ;
}
static int F_134 ( struct V_32 * V_23 )
{
const struct V_221 * V_222 = NULL ;
struct V_220 V_142 ;
T_5 V_225 ;
T_3 V_35 ;
int V_62 , V_12 ;
V_12 = F_126 ( V_23 , V_234 , & V_142 ,
sizeof( V_142 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_225 = F_132 ( V_142 . V_229 ) ;
for ( V_62 = 0 ; V_62 < F_135 ( V_235 ) ; V_62 ++ ) {
if ( V_225 == V_235 [ V_62 ] . V_229 )
V_222 = & V_235 [ V_62 ] ;
}
if ( ! V_222 ) {
F_25 ( L_83 , V_23 -> V_34 ,
V_225 ) ;
return - V_47 ;
}
V_12 = F_126 ( V_23 , V_236 , & V_35 ,
sizeof( V_35 ) ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_35 & V_237 ) ) {
V_12 = F_131 ( V_23 , & V_142 , V_222 ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( ! ( V_35 & V_238 ) ) {
V_12 = F_133 ( V_23 , & V_142 , V_222 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static inline int F_136 ( struct V_32 * V_23 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_115 * V_85 = V_2 -> V_89 ;
int V_62 ;
if ( ! V_2 -> V_89 )
return - V_47 ;
V_2 -> V_239 = NULL ;
V_2 -> V_75 = NULL ;
for ( V_62 = 0 ; V_62 < V_85 -> V_120 -> V_121 . V_122 ; V_62 ++ ) {
struct V_117 * V_118 ;
V_118 = & V_85 -> V_120 -> V_123 [ V_62 ] . V_121 ;
if ( ! V_2 -> V_239 && F_137 ( V_118 ) ) {
V_2 -> V_239 = V_118 ;
continue;
}
if ( ! V_2 -> V_75 && F_138 ( V_118 ) ) {
V_2 -> V_75 = V_118 ;
continue;
}
}
if ( ! V_2 -> V_239 || ! V_2 -> V_75 ) {
F_25 ( L_84 , V_23 -> V_34 ) ;
return - V_47 ;
}
return 0 ;
}
static struct V_31 * F_139 ( struct V_32 * V_23 , bool V_240 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_10 * V_11 ;
struct V_31 * V_31 ;
unsigned int V_50 ;
if ( ! V_2 -> V_239 )
return F_64 ( - V_47 ) ;
V_31 = F_31 ( 0 , V_87 ) ;
if ( ! V_31 )
return F_64 ( - V_16 ) ;
V_11 = F_7 ( 2 , V_87 ) ;
if ( ! V_11 ) {
F_34 ( V_31 ) ;
return F_64 ( - V_16 ) ;
}
* F_11 ( V_11 , 1 ) = 0xf0 ;
* F_11 ( V_11 , 1 ) = V_240 ;
V_50 = F_69 ( V_2 -> V_44 , V_2 -> V_239 -> V_54 ) ;
F_40 ( V_31 , V_2 -> V_44 , V_50 ,
V_11 -> V_2 , V_11 -> V_13 , F_48 , V_11 ) ;
V_11 -> V_76 = ( void * ) V_23 ;
return V_31 ;
}
static int F_140 ( struct V_32 * V_23 , bool V_240 )
{
struct V_1 * V_2 = F_22 ( V_23 ) ;
struct V_31 * V_31 ;
if ( ! V_2 -> V_89 )
return - V_47 ;
if ( ! F_24 ( V_37 , & V_23 -> V_3 ) )
return - V_241 ;
V_31 = F_139 ( V_23 , V_240 ) ;
if ( F_76 ( V_31 ) )
return F_77 ( V_31 ) ;
return F_73 ( V_23 , V_31 ) ;
}
static int F_141 ( struct V_115 * V_85 ,
const struct V_242 * V_243 )
{
struct V_117 * V_118 ;
struct V_1 * V_2 ;
struct V_32 * V_23 ;
unsigned V_244 ;
int V_62 , V_12 ;
F_23 ( L_85 , V_85 , V_243 ) ;
if ( V_85 -> V_120 -> V_121 . V_245 != 0 ) {
if ( ! ( V_243 -> V_246 & V_247 ) )
return - V_47 ;
if ( V_85 -> V_120 -> V_121 . V_245 != 2 )
return - V_47 ;
}
V_244 = V_85 -> V_120 -> V_121 . V_245 ;
if ( ! V_243 -> V_246 ) {
const struct V_242 * V_248 ;
V_248 = F_142 ( V_85 , V_249 ) ;
if ( V_248 )
V_243 = V_248 ;
}
if ( V_243 -> V_246 == V_250 )
return - V_47 ;
if ( V_243 -> V_246 & V_251 ) {
struct V_211 * V_44 = F_143 ( V_85 ) ;
if ( F_32 ( V_44 -> V_252 . V_253 ) <= 0x0001 )
return - V_47 ;
}
V_2 = F_144 ( & V_85 -> V_76 , sizeof( * V_2 ) , V_87 ) ;
if ( ! V_2 )
return - V_16 ;
for ( V_62 = 0 ; V_62 < V_85 -> V_120 -> V_121 . V_122 ; V_62 ++ ) {
V_118 = & V_85 -> V_120 -> V_123 [ V_62 ] . V_121 ;
if ( ! V_2 -> V_52 && F_145 ( V_118 ) ) {
V_2 -> V_52 = V_118 ;
continue;
}
if ( ! V_2 -> V_103 && F_137 ( V_118 ) ) {
V_2 -> V_103 = V_118 ;
continue;
}
if ( ! V_2 -> V_61 && F_138 ( V_118 ) ) {
V_2 -> V_61 = V_118 ;
continue;
}
}
if ( ! V_2 -> V_52 || ! V_2 -> V_103 || ! V_2 -> V_61 )
return - V_47 ;
if ( V_243 -> V_246 & V_254 ) {
V_2 -> V_97 = V_255 | 0x01 ;
V_2 -> V_99 = 0x2b ;
} else {
V_2 -> V_97 = V_255 ;
V_2 -> V_99 = 0x00 ;
}
V_2 -> V_44 = F_143 ( V_85 ) ;
V_2 -> V_85 = V_85 ;
F_146 ( & V_2 -> V_90 , F_84 ) ;
F_146 ( & V_2 -> V_91 , F_87 ) ;
F_147 ( & V_2 -> V_92 ) ;
F_147 ( & V_2 -> V_93 ) ;
F_148 ( & V_2 -> V_81 ) ;
F_147 ( & V_2 -> V_45 ) ;
F_147 ( & V_2 -> V_60 ) ;
F_147 ( & V_2 -> V_68 ) ;
F_147 ( & V_2 -> V_74 ) ;
F_148 ( & V_2 -> V_4 ) ;
if ( V_243 -> V_246 & V_256 ) {
V_2 -> V_22 = F_110 ;
V_2 -> V_58 = F_105 ;
F_55 ( V_174 , & V_2 -> V_3 ) ;
} else {
V_2 -> V_22 = F_18 ;
V_2 -> V_58 = F_15 ;
}
V_23 = F_149 () ;
if ( ! V_23 )
return - V_16 ;
V_23 -> V_257 = V_258 ;
F_150 ( V_23 , V_2 ) ;
if ( V_243 -> V_246 & V_254 )
V_23 -> V_259 = V_260 ;
else
V_23 -> V_259 = V_261 ;
V_2 -> V_23 = V_23 ;
F_151 ( V_23 , & V_85 -> V_76 ) ;
V_23 -> V_262 = F_51 ;
V_23 -> V_263 = F_59 ;
V_23 -> V_264 = F_62 ;
V_23 -> V_265 = F_75 ;
V_23 -> V_266 = F_79 ;
if ( V_243 -> V_246 & V_267 )
F_55 ( V_139 , & V_23 -> V_138 ) ;
if ( V_243 -> V_246 & V_268 )
V_23 -> V_269 = F_88 ;
#ifdef F_152
if ( V_243 -> V_246 & V_270 ) {
V_23 -> V_135 = 15 ;
V_23 -> V_269 = V_271 ;
V_23 -> V_272 = F_140 ;
V_23 -> V_273 = V_274 ;
V_2 -> V_89 = F_153 ( V_2 -> V_44 , V_244 + 2 ) ;
}
if ( V_243 -> V_246 & V_275 ) {
V_23 -> V_135 = 15 ;
V_23 -> V_269 = V_276 ;
V_23 -> V_272 = F_140 ;
V_2 -> V_89 = F_153 ( V_2 -> V_44 , V_244 + 2 ) ;
}
#endif
if ( V_243 -> V_246 & V_277 ) {
V_23 -> V_135 = 2 ;
V_23 -> V_269 = F_96 ;
V_23 -> V_278 = F_123 ;
V_23 -> V_272 = V_279 ;
V_23 -> V_273 = V_280 ;
F_55 ( V_281 , & V_23 -> V_138 ) ;
F_55 ( V_282 , & V_23 -> V_138 ) ;
F_55 ( V_283 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_256 ) {
V_23 -> V_135 = 2 ;
V_23 -> V_265 = F_111 ;
V_23 -> V_269 = F_112 ;
V_23 -> V_284 = V_285 ;
V_23 -> V_272 = V_286 ;
V_23 -> V_273 = V_280 ;
F_55 ( V_281 , & V_23 -> V_138 ) ;
F_55 ( V_283 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_287 )
V_23 -> V_273 = F_124 ;
if ( V_243 -> V_246 & V_288 ) {
F_55 ( V_289 , & V_23 -> V_138 ) ;
F_55 ( V_290 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_291 ) {
V_23 -> V_135 = 2 ;
F_55 ( V_292 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_251 ) {
V_23 -> V_273 = F_125 ;
F_55 ( V_282 , & V_23 -> V_138 ) ;
F_55 ( V_281 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_293 ) {
V_2 -> V_84 = F_134 ;
V_23 -> V_273 = F_125 ;
}
#ifdef F_154
if ( V_243 -> V_246 & V_294 ) {
V_23 -> V_269 = V_295 ;
F_55 ( V_296 , & V_2 -> V_3 ) ;
}
#endif
if ( V_243 -> V_246 & V_254 ) {
V_2 -> V_116 = NULL ;
} else {
V_2 -> V_116 = F_153 ( V_2 -> V_44 , V_244 + 1 ) ;
}
if ( ! V_297 )
F_55 ( V_137 , & V_23 -> V_138 ) ;
if ( V_298 || V_243 -> V_246 & V_299 ) {
if ( ! V_300 )
F_55 ( V_301 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_302 )
V_2 -> V_116 = NULL ;
if ( V_243 -> V_246 & V_303 ) {
V_2 -> V_97 = V_212 ;
F_55 ( V_137 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_304 ) {
struct V_211 * V_44 = V_2 -> V_44 ;
T_8 V_253 = F_32 ( V_44 -> V_252 . V_253 ) ;
if ( V_253 < 0x117 )
F_55 ( V_137 , & V_23 -> V_138 ) ;
if ( V_253 <= 0x100 || V_253 == 0x134 )
V_23 -> V_269 = F_90 ;
F_55 ( V_282 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_305 ) {
struct V_211 * V_44 = V_2 -> V_44 ;
if ( F_32 ( V_44 -> V_252 . V_253 ) > 0x997 )
F_55 ( V_292 , & V_23 -> V_138 ) ;
}
if ( V_243 -> V_246 & V_291 ) {
V_12 = F_81 ( V_2 -> V_44 , 0 , 0 ) ;
if ( V_12 < 0 ) {
F_25 ( L_86 , V_12 ) ;
F_155 ( V_23 ) ;
return V_12 ;
}
}
if ( V_2 -> V_116 ) {
V_12 = F_156 ( & V_306 ,
V_2 -> V_116 , V_2 ) ;
if ( V_12 < 0 ) {
F_155 ( V_23 ) ;
return V_12 ;
}
}
#ifdef F_152
if ( V_2 -> V_89 ) {
if ( ! F_156 ( & V_306 ,
V_2 -> V_89 , V_2 ) )
F_136 ( V_23 ) ;
else
V_2 -> V_89 = NULL ;
}
#endif
V_12 = F_157 ( V_23 ) ;
if ( V_12 < 0 ) {
F_155 ( V_23 ) ;
return V_12 ;
}
F_158 ( V_85 , V_2 ) ;
return 0 ;
}
static void F_159 ( struct V_115 * V_85 )
{
struct V_1 * V_2 = F_160 ( V_85 ) ;
struct V_32 * V_23 ;
F_23 ( L_87 , V_85 ) ;
if ( ! V_2 )
return;
V_23 = V_2 -> V_23 ;
F_158 ( V_2 -> V_85 , NULL ) ;
if ( V_2 -> V_116 )
F_158 ( V_2 -> V_116 , NULL ) ;
if ( V_2 -> V_89 )
F_158 ( V_2 -> V_89 , NULL ) ;
F_161 ( V_23 ) ;
if ( V_85 == V_2 -> V_85 ) {
if ( V_2 -> V_116 )
F_162 ( & V_306 , V_2 -> V_116 ) ;
if ( V_2 -> V_89 )
F_162 ( & V_306 , V_2 -> V_89 ) ;
} else if ( V_85 == V_2 -> V_116 ) {
if ( V_2 -> V_89 )
F_162 ( & V_306 , V_2 -> V_89 ) ;
F_162 ( & V_306 , V_2 -> V_85 ) ;
} else if ( V_85 == V_2 -> V_89 ) {
F_162 ( & V_306 , V_2 -> V_85 ) ;
if ( V_2 -> V_116 )
F_162 ( & V_306 , V_2 -> V_116 ) ;
}
F_155 ( V_23 ) ;
}
static int F_163 ( struct V_115 * V_85 , T_10 V_307 )
{
struct V_1 * V_2 = F_160 ( V_85 ) ;
F_23 ( L_87 , V_85 ) ;
if ( V_2 -> V_308 ++ )
return 0 ;
F_164 ( & V_2 -> V_81 ) ;
if ( ! ( F_165 ( V_307 ) && V_2 -> V_82 ) ) {
F_55 ( V_106 , & V_2 -> V_3 ) ;
F_166 ( & V_2 -> V_81 ) ;
} else {
F_166 ( & V_2 -> V_81 ) ;
V_2 -> V_308 -- ;
return - V_309 ;
}
F_60 ( & V_2 -> V_90 ) ;
F_58 ( V_2 ) ;
F_54 ( & V_2 -> V_93 ) ;
if ( F_24 ( V_296 , & V_2 -> V_3 ) &&
! F_167 ( & V_2 -> V_44 -> V_76 ) )
V_2 -> V_44 -> V_310 = 1 ;
return 0 ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_31 * V_31 ;
int V_12 ;
while ( ( V_31 = F_169 ( & V_2 -> V_92 ) ) ) {
V_12 = F_28 ( V_31 , V_15 ) ;
if ( V_12 < 0 )
break;
V_2 -> V_82 ++ ;
}
F_61 ( & V_2 -> V_92 ) ;
}
static int F_170 ( struct V_115 * V_85 )
{
struct V_1 * V_2 = F_160 ( V_85 ) ;
struct V_32 * V_23 = V_2 -> V_23 ;
int V_12 = 0 ;
F_23 ( L_87 , V_85 ) ;
if ( -- V_2 -> V_308 )
return 0 ;
if ( ! F_24 ( V_37 , & V_23 -> V_3 ) )
goto V_77;
if ( F_24 ( V_43 , & V_2 -> V_3 ) ) {
V_12 = F_30 ( V_23 , V_311 ) ;
if ( V_12 < 0 ) {
F_57 ( V_43 , & V_2 -> V_3 ) ;
goto V_88;
}
}
if ( F_24 ( V_59 , & V_2 -> V_3 ) ) {
V_12 = F_38 ( V_23 , V_311 ) ;
if ( V_12 < 0 ) {
F_57 ( V_59 , & V_2 -> V_3 ) ;
goto V_88;
}
F_38 ( V_23 , V_311 ) ;
}
if ( F_24 ( V_67 , & V_2 -> V_3 ) ) {
if ( F_43 ( V_23 , V_311 ) < 0 )
F_57 ( V_67 , & V_2 -> V_3 ) ;
else
F_43 ( V_23 , V_311 ) ;
}
F_164 ( & V_2 -> V_81 ) ;
F_168 ( V_2 ) ;
F_57 ( V_106 , & V_2 -> V_3 ) ;
F_166 ( & V_2 -> V_81 ) ;
F_74 ( & V_2 -> V_90 ) ;
return 0 ;
V_88:
F_61 ( & V_2 -> V_92 ) ;
V_77:
F_164 ( & V_2 -> V_81 ) ;
F_57 ( V_106 , & V_2 -> V_3 ) ;
F_166 ( & V_2 -> V_81 ) ;
return V_12 ;
}
