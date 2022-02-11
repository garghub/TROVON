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
F_8 ( V_11 ) -> V_17 = V_18 ;
F_8 ( V_11 ) -> V_19 = V_20 ;
}
V_13 = F_9 ( V_21 , F_8 ( V_11 ) -> V_19 , V_9 ) ;
memcpy ( F_10 ( V_11 , V_13 ) , V_8 , V_13 ) ;
V_9 -= V_13 ;
V_8 += V_13 ;
F_8 ( V_11 ) -> V_19 -= V_13 ;
if ( V_11 -> V_13 == V_20 ) {
F_8 ( V_11 ) -> V_19 = F_11 ( V_11 ) -> V_22 ;
if ( F_12 ( V_11 ) < F_8 ( V_11 ) -> V_19 ) {
F_3 ( V_11 ) ;
V_11 = NULL ;
V_12 = - V_23 ;
break;
}
}
if ( F_8 ( V_11 ) -> V_19 == 0 ) {
V_2 -> V_24 ( V_2 -> V_25 , V_11 ) ;
V_11 = NULL ;
}
}
V_2 -> V_5 = V_11 ;
F_13 ( & V_2 -> V_4 ) ;
return V_12 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_8 , int V_9 )
{
struct V_10 * V_11 ;
int V_12 = 0 ;
F_6 ( & V_2 -> V_4 ) ;
V_11 = V_2 -> V_6 ;
while ( V_9 ) {
int V_13 ;
if ( ! V_11 ) {
V_11 = F_7 ( V_26 , V_15 ) ;
if ( ! V_11 ) {
V_12 = - V_16 ;
break;
}
F_8 ( V_11 ) -> V_17 = V_27 ;
F_8 ( V_11 ) -> V_19 = V_28 ;
}
V_13 = F_9 ( V_21 , F_8 ( V_11 ) -> V_19 , V_9 ) ;
memcpy ( F_10 ( V_11 , V_13 ) , V_8 , V_13 ) ;
V_9 -= V_13 ;
V_8 += V_13 ;
F_8 ( V_11 ) -> V_19 -= V_13 ;
if ( V_11 -> V_13 == V_28 ) {
T_1 V_29 = F_15 ( V_11 ) -> V_29 ;
F_8 ( V_11 ) -> V_19 = F_16 ( V_29 ) ;
if ( F_12 ( V_11 ) < F_8 ( V_11 ) -> V_19 ) {
F_3 ( V_11 ) ;
V_11 = NULL ;
V_12 = - V_23 ;
break;
}
}
if ( F_8 ( V_11 ) -> V_19 == 0 ) {
F_17 ( V_2 -> V_25 , V_11 ) ;
V_11 = NULL ;
}
}
V_2 -> V_6 = V_11 ;
F_13 ( & V_2 -> V_4 ) ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_8 , int V_9 )
{
struct V_10 * V_11 ;
int V_12 = 0 ;
F_6 ( & V_2 -> V_4 ) ;
V_11 = V_2 -> V_7 ;
while ( V_9 ) {
int V_13 ;
if ( ! V_11 ) {
V_11 = F_7 ( V_30 , V_15 ) ;
if ( ! V_11 ) {
V_12 = - V_16 ;
break;
}
F_8 ( V_11 ) -> V_17 = V_31 ;
F_8 ( V_11 ) -> V_19 = V_32 ;
}
V_13 = F_9 ( V_21 , F_8 ( V_11 ) -> V_19 , V_9 ) ;
memcpy ( F_10 ( V_11 , V_13 ) , V_8 , V_13 ) ;
V_9 -= V_13 ;
V_8 += V_13 ;
F_8 ( V_11 ) -> V_19 -= V_13 ;
if ( V_11 -> V_13 == V_32 ) {
F_8 ( V_11 ) -> V_19 = F_19 ( V_11 ) -> V_29 ;
if ( F_12 ( V_11 ) < F_8 ( V_11 ) -> V_19 ) {
F_3 ( V_11 ) ;
V_11 = NULL ;
V_12 = - V_23 ;
break;
}
}
if ( F_8 ( V_11 ) -> V_19 == 0 ) {
F_17 ( V_2 -> V_25 , V_11 ) ;
V_11 = NULL ;
}
}
V_2 -> V_7 = V_11 ;
F_13 ( & V_2 -> V_4 ) ;
return V_12 ;
}
static void F_20 ( struct V_33 * V_33 )
{
struct V_34 * V_25 = V_33 -> V_35 ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
return;
if ( V_33 -> V_37 == 0 ) {
V_25 -> V_40 . V_41 += V_33 -> V_38 ;
if ( F_5 ( V_2 , V_33 -> V_42 ,
V_33 -> V_38 ) < 0 ) {
F_24 ( L_2 , V_25 -> V_36 ) ;
V_25 -> V_40 . V_43 ++ ;
}
} else if ( V_33 -> V_37 == - V_44 ) {
return;
}
if ( ! F_23 ( V_45 , & V_2 -> V_3 ) )
return;
F_25 ( V_2 -> V_46 ) ;
F_26 ( V_33 , & V_2 -> V_47 ) ;
V_12 = F_27 ( V_33 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_3 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
}
static int F_29 ( struct V_34 * V_25 , T_2 V_50 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned char * V_51 ;
unsigned int V_52 ;
int V_12 , V_53 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! V_2 -> V_54 )
return - V_49 ;
V_33 = F_30 ( 0 , V_50 ) ;
if ( ! V_33 )
return - V_16 ;
V_53 = F_31 ( V_2 -> V_54 -> V_55 ) ;
V_51 = F_32 ( V_53 , V_50 ) ;
if ( ! V_51 ) {
F_33 ( V_33 ) ;
return - V_16 ;
}
V_52 = F_34 ( V_2 -> V_46 , V_2 -> V_54 -> V_56 ) ;
F_35 ( V_33 , V_2 -> V_46 , V_52 , V_51 , V_53 ,
F_20 , V_25 , V_2 -> V_54 -> V_57 ) ;
V_33 -> V_58 |= V_59 ;
F_26 ( V_33 , & V_2 -> V_47 ) ;
V_12 = F_27 ( V_33 , V_50 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_5 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
F_33 ( V_33 ) ;
return V_12 ;
}
static void F_36 ( struct V_33 * V_33 )
{
struct V_34 * V_25 = V_33 -> V_35 ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
return;
if ( V_33 -> V_37 == 0 ) {
V_25 -> V_40 . V_41 += V_33 -> V_38 ;
if ( V_2 -> V_60 ( V_2 , V_33 -> V_42 ,
V_33 -> V_38 ) < 0 ) {
F_24 ( L_6 , V_25 -> V_36 ) ;
V_25 -> V_40 . V_43 ++ ;
}
} else if ( V_33 -> V_37 == - V_44 ) {
return;
}
if ( ! F_23 ( V_61 , & V_2 -> V_3 ) )
return;
F_26 ( V_33 , & V_2 -> V_62 ) ;
F_25 ( V_2 -> V_46 ) ;
V_12 = F_27 ( V_33 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_3 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
}
static int F_37 ( struct V_34 * V_25 , T_2 V_50 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned char * V_51 ;
unsigned int V_52 ;
int V_12 , V_53 = V_26 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! V_2 -> V_63 )
return - V_49 ;
V_33 = F_30 ( 0 , V_50 ) ;
if ( ! V_33 )
return - V_16 ;
V_51 = F_32 ( V_53 , V_50 ) ;
if ( ! V_51 ) {
F_33 ( V_33 ) ;
return - V_16 ;
}
V_52 = F_38 ( V_2 -> V_46 , V_2 -> V_63 -> V_56 ) ;
F_39 ( V_33 , V_2 -> V_46 , V_52 , V_51 , V_53 ,
F_36 , V_25 ) ;
V_33 -> V_58 |= V_59 ;
F_25 ( V_2 -> V_46 ) ;
F_26 ( V_33 , & V_2 -> V_62 ) ;
V_12 = F_27 ( V_33 , V_50 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_5 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
F_33 ( V_33 ) ;
return V_12 ;
}
static void F_40 ( struct V_33 * V_33 )
{
struct V_34 * V_25 = V_33 -> V_35 ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_64 , V_12 ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
return;
if ( V_33 -> V_37 == 0 ) {
for ( V_64 = 0 ; V_64 < V_33 -> V_65 ; V_64 ++ ) {
unsigned int V_66 = V_33 -> V_67 [ V_64 ] . V_66 ;
unsigned int V_68 = V_33 -> V_67 [ V_64 ] . V_38 ;
if ( V_33 -> V_67 [ V_64 ] . V_37 )
continue;
V_25 -> V_40 . V_41 += V_68 ;
if ( F_18 ( V_2 , V_33 -> V_42 + V_66 ,
V_68 ) < 0 ) {
F_24 ( L_7 , V_25 -> V_36 ) ;
V_25 -> V_40 . V_43 ++ ;
}
}
} else if ( V_33 -> V_37 == - V_44 ) {
return;
}
if ( ! F_23 ( V_69 , & V_2 -> V_3 ) )
return;
F_26 ( V_33 , & V_2 -> V_70 ) ;
V_12 = F_27 ( V_33 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_3 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
}
static inline void F_41 ( struct V_33 * V_33 , int V_13 , int V_71 )
{
int V_64 , V_66 = 0 ;
F_22 ( L_8 , V_13 , V_71 ) ;
for ( V_64 = 0 ; V_64 < V_72 && V_13 >= V_71 ;
V_64 ++ , V_66 += V_71 , V_13 -= V_71 ) {
V_33 -> V_67 [ V_64 ] . V_66 = V_66 ;
V_33 -> V_67 [ V_64 ] . V_68 = V_71 ;
}
if ( V_13 && V_64 < V_72 ) {
V_33 -> V_67 [ V_64 ] . V_66 = V_66 ;
V_33 -> V_67 [ V_64 ] . V_68 = V_13 ;
V_64 ++ ;
}
V_33 -> V_65 = V_64 ;
}
static int F_42 ( struct V_34 * V_25 , T_2 V_50 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned char * V_51 ;
unsigned int V_52 ;
int V_12 , V_53 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! V_2 -> V_73 )
return - V_49 ;
V_33 = F_30 ( V_72 , V_50 ) ;
if ( ! V_33 )
return - V_16 ;
V_53 = F_31 ( V_2 -> V_73 -> V_55 ) *
V_72 ;
V_51 = F_32 ( V_53 , V_50 ) ;
if ( ! V_51 ) {
F_33 ( V_33 ) ;
return - V_16 ;
}
V_52 = F_43 ( V_2 -> V_46 , V_2 -> V_73 -> V_56 ) ;
F_35 ( V_33 , V_2 -> V_46 , V_52 , V_51 , V_53 , F_40 ,
V_25 , V_2 -> V_73 -> V_57 ) ;
V_33 -> V_58 = V_59 | V_74 ;
F_41 ( V_33 , V_53 ,
F_31 ( V_2 -> V_73 -> V_55 ) ) ;
F_26 ( V_33 , & V_2 -> V_70 ) ;
V_12 = F_27 ( V_33 , V_50 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_5 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
F_33 ( V_33 ) ;
return V_12 ;
}
static void F_44 ( struct V_33 * V_33 )
{
struct V_34 * V_25 = V_33 -> V_35 ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( V_33 -> V_37 == 0 ) {
struct V_10 * V_11 ;
V_11 = F_7 ( V_33 -> V_38 , V_15 ) ;
if ( V_11 ) {
memcpy ( F_10 ( V_11 , V_33 -> V_38 ) ,
V_33 -> V_42 , V_33 -> V_38 ) ;
F_45 ( V_25 , V_11 ) ;
}
} else if ( V_33 -> V_37 == - V_44 ) {
return;
}
if ( ! F_23 ( V_75 , & V_2 -> V_3 ) )
return;
F_26 ( V_33 , & V_2 -> V_76 ) ;
F_25 ( V_2 -> V_46 ) ;
V_12 = F_27 ( V_33 , V_15 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_3 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
}
static int F_46 ( struct V_34 * V_25 , T_2 V_50 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned char * V_51 ;
unsigned int V_52 ;
int V_12 , V_53 = V_26 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! V_2 -> V_77 )
return - V_49 ;
V_33 = F_30 ( 0 , V_50 ) ;
if ( ! V_33 )
return - V_16 ;
V_51 = F_32 ( V_53 , V_50 ) ;
if ( ! V_51 ) {
F_33 ( V_33 ) ;
return - V_16 ;
}
V_52 = F_38 ( V_2 -> V_46 , V_2 -> V_77 -> V_56 ) ;
F_39 ( V_33 , V_2 -> V_46 , V_52 , V_51 , V_53 ,
F_44 , V_25 ) ;
V_33 -> V_58 |= V_59 ;
F_25 ( V_2 -> V_46 ) ;
F_26 ( V_33 , & V_2 -> V_76 ) ;
V_12 = F_27 ( V_33 , V_50 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_5 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_28 ( V_33 ) ;
}
F_33 ( V_33 ) ;
return V_12 ;
}
static void F_47 ( struct V_33 * V_33 )
{
struct V_10 * V_11 = V_33 -> V_35 ;
struct V_34 * V_25 = (struct V_34 * ) V_11 -> V_78 ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
goto V_79;
if ( ! V_33 -> V_37 )
V_25 -> V_40 . V_80 += V_33 -> V_81 ;
else
V_25 -> V_40 . V_82 ++ ;
V_79:
F_6 ( & V_2 -> V_83 ) ;
V_2 -> V_84 -- ;
F_13 ( & V_2 -> V_83 ) ;
F_48 ( V_33 -> V_85 ) ;
F_3 ( V_11 ) ;
}
static void F_49 ( struct V_33 * V_33 )
{
struct V_10 * V_11 = V_33 -> V_35 ;
struct V_34 * V_25 = (struct V_34 * ) V_11 -> V_78 ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
goto V_79;
if ( ! V_33 -> V_37 )
V_25 -> V_40 . V_80 += V_33 -> V_81 ;
else
V_25 -> V_40 . V_82 ++ ;
V_79:
F_48 ( V_33 -> V_85 ) ;
F_3 ( V_11 ) ;
}
static int F_50 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( V_2 -> V_86 ) {
V_12 = V_2 -> V_86 ( V_25 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_12 = F_51 ( V_2 -> V_87 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_87 -> V_88 = 1 ;
if ( F_52 ( V_45 , & V_2 -> V_3 ) )
goto V_79;
V_12 = F_29 ( V_25 , V_89 ) ;
if ( V_12 < 0 )
goto V_90;
V_12 = F_37 ( V_25 , V_89 ) ;
if ( V_12 < 0 ) {
F_53 ( & V_2 -> V_47 ) ;
goto V_90;
}
F_54 ( V_61 , & V_2 -> V_3 ) ;
F_37 ( V_25 , V_89 ) ;
if ( V_2 -> V_91 ) {
if ( ! F_46 ( V_25 , V_89 ) )
F_54 ( V_75 , & V_2 -> V_3 ) ;
}
V_79:
F_55 ( V_2 -> V_87 ) ;
return 0 ;
V_90:
F_56 ( V_45 , & V_2 -> V_3 ) ;
F_55 ( V_2 -> V_87 ) ;
return V_12 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_47 ) ;
F_53 ( & V_2 -> V_62 ) ;
F_53 ( & V_2 -> V_70 ) ;
F_53 ( & V_2 -> V_76 ) ;
}
static int F_58 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
F_59 ( & V_2 -> V_92 ) ;
F_59 ( & V_2 -> V_93 ) ;
F_56 ( V_69 , & V_2 -> V_3 ) ;
F_56 ( V_61 , & V_2 -> V_3 ) ;
F_56 ( V_45 , & V_2 -> V_3 ) ;
F_56 ( V_75 , & V_2 -> V_3 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
V_12 = F_51 ( V_2 -> V_87 ) ;
if ( V_12 < 0 )
goto V_90;
V_2 -> V_87 -> V_88 = 0 ;
F_55 ( V_2 -> V_87 ) ;
V_90:
F_60 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_61 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_22 ( L_4 , V_25 -> V_36 ) ;
F_53 ( & V_2 -> V_95 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_33 * F_62 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_96 * V_97 ;
struct V_33 * V_33 ;
unsigned int V_52 ;
V_33 = F_30 ( 0 , V_89 ) ;
if ( ! V_33 )
return F_63 ( - V_16 ) ;
V_97 = F_32 ( sizeof( * V_97 ) , V_89 ) ;
if ( ! V_97 ) {
F_33 ( V_33 ) ;
return F_63 ( - V_16 ) ;
}
V_97 -> V_98 = V_2 -> V_99 ;
V_97 -> V_100 = V_2 -> V_101 ;
V_97 -> V_102 = 0 ;
V_97 -> V_103 = 0 ;
V_97 -> V_104 = F_64 ( V_11 -> V_13 ) ;
V_52 = F_65 ( V_2 -> V_46 , 0x00 ) ;
F_66 ( V_33 , V_2 -> V_46 , V_52 , ( void * ) V_97 ,
V_11 -> V_2 , V_11 -> V_13 , F_47 , V_11 ) ;
V_11 -> V_78 = ( void * ) V_25 ;
return V_33 ;
}
static struct V_33 * F_67 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned int V_52 ;
if ( ! V_2 -> V_105 )
return F_63 ( - V_49 ) ;
V_33 = F_30 ( 0 , V_89 ) ;
if ( ! V_33 )
return F_63 ( - V_16 ) ;
V_52 = F_68 ( V_2 -> V_46 , V_2 -> V_105 -> V_56 ) ;
F_39 ( V_33 , V_2 -> V_46 , V_52 ,
V_11 -> V_2 , V_11 -> V_13 , F_47 , V_11 ) ;
V_11 -> V_78 = ( void * ) V_25 ;
return V_33 ;
}
static struct V_33 * F_69 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned int V_52 ;
if ( ! V_2 -> V_106 )
return F_63 ( - V_49 ) ;
V_33 = F_30 ( V_72 , V_89 ) ;
if ( ! V_33 )
return F_63 ( - V_16 ) ;
V_52 = F_70 ( V_2 -> V_46 , V_2 -> V_106 -> V_56 ) ;
F_35 ( V_33 , V_2 -> V_46 , V_52 ,
V_11 -> V_2 , V_11 -> V_13 , F_49 ,
V_11 , V_2 -> V_106 -> V_57 ) ;
V_33 -> V_58 = V_74 ;
F_41 ( V_33 , V_11 -> V_13 ,
F_31 ( V_2 -> V_106 -> V_55 ) ) ;
V_11 -> V_78 = ( void * ) V_25 ;
return V_33 ;
}
static int F_71 ( struct V_34 * V_25 , struct V_33 * V_33 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_26 ( V_33 , & V_2 -> V_95 ) ;
V_12 = F_27 ( V_33 , V_89 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_5 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_48 ( V_33 -> V_85 ) ;
F_28 ( V_33 ) ;
} else {
F_25 ( V_2 -> V_46 ) ;
}
F_33 ( V_33 ) ;
return V_12 ;
}
static int F_72 ( struct V_34 * V_25 , struct V_33 * V_33 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
unsigned long V_3 ;
bool V_107 ;
F_2 ( & V_2 -> V_83 , V_3 ) ;
V_107 = F_23 ( V_108 , & V_2 -> V_3 ) ;
if ( ! V_107 )
V_2 -> V_84 ++ ;
F_4 ( & V_2 -> V_83 , V_3 ) ;
if ( ! V_107 )
return F_71 ( V_25 , V_33 ) ;
F_26 ( V_33 , & V_2 -> V_94 ) ;
F_73 ( & V_2 -> V_93 ) ;
F_33 ( V_33 ) ;
return 0 ;
}
static int F_74 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_33 * V_33 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
switch ( F_8 ( V_11 ) -> V_17 ) {
case V_109 :
V_33 = F_62 ( V_25 , V_11 ) ;
if ( F_75 ( V_33 ) )
return F_76 ( V_33 ) ;
V_25 -> V_40 . V_110 ++ ;
return F_72 ( V_25 , V_33 ) ;
case V_27 :
V_33 = F_67 ( V_25 , V_11 ) ;
if ( F_75 ( V_33 ) )
return F_76 ( V_33 ) ;
V_25 -> V_40 . V_111 ++ ;
return F_72 ( V_25 , V_33 ) ;
case V_31 :
if ( F_77 ( V_25 , V_112 ) < 1 )
return - V_49 ;
V_33 = F_69 ( V_25 , V_11 ) ;
if ( F_75 ( V_33 ) )
return F_76 ( V_33 ) ;
V_25 -> V_40 . V_113 ++ ;
return F_71 ( V_25 , V_33 ) ;
}
return - V_23 ;
}
static void F_78 ( struct V_34 * V_25 , unsigned int V_114 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_22 ( L_9 , V_25 -> V_36 , V_114 ) ;
if ( F_77 ( V_25 , V_112 ) != V_2 -> V_115 ) {
V_2 -> V_115 = F_77 ( V_25 , V_112 ) ;
F_73 ( & V_2 -> V_92 ) ;
}
}
static inline int F_79 ( struct V_34 * V_25 , int V_116 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_117 * V_87 = V_2 -> V_118 ;
struct V_119 * V_120 ;
int V_64 , V_12 ;
if ( ! V_2 -> V_118 )
return - V_49 ;
V_12 = F_80 ( V_2 -> V_46 , 1 , V_116 ) ;
if ( V_12 < 0 ) {
F_24 ( L_10 , V_25 -> V_36 , - V_12 ) ;
return V_12 ;
}
V_2 -> V_121 = V_116 ;
V_2 -> V_106 = NULL ;
V_2 -> V_73 = NULL ;
for ( V_64 = 0 ; V_64 < V_87 -> V_122 -> V_123 . V_124 ; V_64 ++ ) {
V_120 = & V_87 -> V_122 -> V_125 [ V_64 ] . V_123 ;
if ( ! V_2 -> V_106 && F_81 ( V_120 ) ) {
V_2 -> V_106 = V_120 ;
continue;
}
if ( ! V_2 -> V_73 && F_82 ( V_120 ) ) {
V_2 -> V_73 = V_120 ;
continue;
}
}
if ( ! V_2 -> V_106 || ! V_2 -> V_73 ) {
F_24 ( L_11 , V_25 -> V_36 ) ;
return - V_49 ;
}
return 0 ;
}
static void F_83 ( struct V_126 * V_92 )
{
struct V_1 * V_2 = F_84 ( V_92 , struct V_1 , V_92 ) ;
struct V_34 * V_25 = V_2 -> V_25 ;
int V_127 ;
int V_12 ;
if ( V_2 -> V_115 > 0 ) {
if ( ! F_23 ( V_128 , & V_2 -> V_3 ) ) {
V_12 = F_51 ( V_2 -> V_118 ? V_2 -> V_118 : V_2 -> V_87 ) ;
if ( V_12 < 0 ) {
F_56 ( V_69 , & V_2 -> V_3 ) ;
F_53 ( & V_2 -> V_70 ) ;
return;
}
F_54 ( V_128 , & V_2 -> V_3 ) ;
}
if ( V_25 -> V_129 & 0x0020 ) {
static const int V_130 [ 3 ] = { 2 , 4 , 5 } ;
V_127 = V_130 [ V_2 -> V_115 - 1 ] ;
} else {
V_127 = V_2 -> V_115 ;
}
if ( V_2 -> V_121 != V_127 ) {
unsigned long V_3 ;
F_56 ( V_69 , & V_2 -> V_3 ) ;
F_53 ( & V_2 -> V_70 ) ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
if ( F_79 ( V_25 , V_127 ) < 0 )
return;
}
if ( ! F_52 ( V_69 , & V_2 -> V_3 ) ) {
if ( F_42 ( V_25 , V_89 ) < 0 )
F_56 ( V_69 , & V_2 -> V_3 ) ;
else
F_42 ( V_25 , V_89 ) ;
}
} else {
F_56 ( V_69 , & V_2 -> V_3 ) ;
F_53 ( & V_2 -> V_70 ) ;
F_79 ( V_25 , 0 ) ;
if ( F_85 ( V_128 , & V_2 -> V_3 ) )
F_55 ( V_2 -> V_118 ? V_2 -> V_118 : V_2 -> V_87 ) ;
}
}
static void F_86 ( struct V_126 * V_92 )
{
struct V_1 * V_2 = F_84 ( V_92 , struct V_1 , V_93 ) ;
int V_12 ;
V_12 = F_51 ( V_2 -> V_87 ) ;
if ( V_12 < 0 )
return;
F_55 ( V_2 -> V_87 ) ;
}
static int F_87 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
T_3 V_131 = 0x00 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_88 ( V_25 , 0xfc3b , 1 , & V_131 , V_132 ) ;
if ( F_75 ( V_11 ) )
F_24 ( L_12 , - F_76 ( V_11 ) ) ;
else
F_3 ( V_11 ) ;
return 0 ;
}
static int F_89 ( struct V_34 * V_25 )
{
struct V_133 * V_134 ;
struct V_10 * V_11 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_88 ( V_25 , V_135 , 0 , NULL ,
V_132 ) ;
if ( F_75 ( V_11 ) ) {
int V_12 = F_76 ( V_11 ) ;
F_24 ( L_13 , V_25 -> V_36 , V_12 ) ;
return V_12 ;
}
if ( V_11 -> V_13 != sizeof( struct V_133 ) ) {
F_24 ( L_14 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_136 ;
}
V_134 = (struct V_133 * ) V_11 -> V_2 ;
if ( F_31 ( V_134 -> V_137 ) != 10 ||
F_31 ( V_134 -> V_138 ) == 0x0c5c ) {
F_56 ( V_139 , & V_25 -> V_140 ) ;
F_54 ( V_141 , & V_25 -> V_140 ) ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static const struct V_142 * F_90 ( struct V_34 * V_25 ,
struct V_143 * V_144 )
{
const struct V_142 * V_145 ;
char V_146 [ 64 ] ;
int V_147 ;
snprintf ( V_146 , sizeof( V_146 ) ,
L_15 ,
V_144 -> V_148 , V_144 -> V_149 , V_144 -> V_150 ,
V_144 -> V_151 , V_144 -> V_152 , V_144 -> V_153 ,
V_144 -> V_154 , V_144 -> V_155 ) ;
V_147 = F_91 ( & V_145 , V_146 , & V_25 -> V_78 ) ;
if ( V_147 < 0 ) {
if ( V_147 == - V_156 ) {
F_24 ( L_16 ,
V_25 -> V_36 , V_147 ) ;
return NULL ;
}
F_24 ( L_17 ,
V_25 -> V_36 , V_146 , V_147 ) ;
snprintf ( V_146 , sizeof( V_146 ) , L_18 ,
V_144 -> V_148 , V_144 -> V_149 ) ;
if ( F_91 ( & V_145 , V_146 , & V_25 -> V_78 ) < 0 ) {
F_24 ( L_19 ,
V_25 -> V_36 , V_146 ) ;
return NULL ;
}
}
F_92 ( L_20 , V_25 -> V_36 , V_146 ) ;
return V_145 ;
}
static int F_93 ( struct V_34 * V_25 ,
const struct V_142 * V_145 ,
const T_3 * * V_157 , int * V_158 )
{
struct V_10 * V_11 ;
struct V_159 * V_160 ;
const T_3 * V_161 ;
struct F_11 * V_114 = NULL ;
const T_3 * V_162 = NULL ;
int V_163 = V_145 -> V_53 - ( * V_157 - V_145 -> V_2 ) ;
if ( V_163 > V_164 && * V_157 [ 0 ] != 0x01 ) {
F_24 ( L_21 , V_25 -> V_36 ) ;
return - V_156 ;
}
( * V_157 ) ++ ;
V_163 -- ;
V_160 = (struct V_159 * ) ( * V_157 ) ;
* V_157 += sizeof( * V_160 ) ;
V_163 -= sizeof( * V_160 ) ;
if ( V_163 < V_160 -> V_22 ) {
F_24 ( L_22 , V_25 -> V_36 ) ;
return - V_165 ;
}
if ( * V_158 && F_31 ( V_160 -> V_166 ) == 0xfc8e )
* V_158 = 0 ;
V_161 = * V_157 ;
* V_157 += V_160 -> V_22 ;
V_163 -= V_160 -> V_22 ;
while ( V_163 > V_20 && * V_157 [ 0 ] == 0x02 ) {
( * V_157 ) ++ ;
V_163 -- ;
V_114 = (struct F_11 * ) ( * V_157 ) ;
* V_157 += sizeof( * V_114 ) ;
V_163 -= sizeof( * V_114 ) ;
if ( V_163 < V_114 -> V_22 ) {
F_24 ( L_23 ,
V_25 -> V_36 ) ;
return - V_165 ;
}
V_162 = * V_157 ;
* V_157 += V_114 -> V_22 ;
V_163 -= V_114 -> V_22 ;
}
if ( ! V_114 || ! V_162 || V_163 < 0 ) {
F_24 ( L_24 , V_25 -> V_36 ) ;
return - V_165 ;
}
V_11 = F_94 ( V_25 , F_31 ( V_160 -> V_166 ) , V_160 -> V_22 ,
V_161 , V_114 -> V_114 , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_25 ,
V_25 -> V_36 , V_160 -> V_166 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
if ( V_11 -> V_13 != V_114 -> V_22 ) {
F_24 ( L_26 , V_25 -> V_36 ,
F_31 ( V_160 -> V_166 ) ) ;
F_3 ( V_11 ) ;
return - V_165 ;
}
if ( memcmp ( V_11 -> V_2 , V_162 , V_114 -> V_22 ) ) {
F_24 ( L_27 ,
V_25 -> V_36 , F_31 ( V_160 -> V_166 ) ) ;
F_3 ( V_11 ) ;
return - V_165 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_95 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
const struct V_142 * V_145 ;
const T_3 * V_157 ;
int V_158 ;
struct V_143 * V_144 ;
const T_3 V_167 [] = { 0x01 , 0x00 } ;
const T_3 V_168 [] = { 0x00 , 0x00 } ;
const T_3 V_169 [] = { 0x00 , 0x01 } ;
const T_3 V_170 [] = { 0x00 , 0x02 } ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_88 ( V_25 , V_171 , 0 , NULL , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_28 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
F_3 ( V_11 ) ;
V_11 = F_88 ( V_25 , 0xfc05 , 0 , NULL , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_29 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_144 ) ) {
F_24 ( L_30 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_136 ;
}
V_144 = (struct V_143 * ) V_11 -> V_2 ;
F_92 ( L_31 ,
V_25 -> V_36 , V_144 -> V_148 , V_144 -> V_149 ,
V_144 -> V_150 , V_144 -> V_151 , V_144 -> V_152 ,
V_144 -> V_153 , V_144 -> V_154 , V_144 -> V_155 ,
V_144 -> V_172 ) ;
if ( V_144 -> V_172 ) {
F_92 ( L_32 ,
V_25 -> V_36 , V_144 -> V_172 ) ;
F_3 ( V_11 ) ;
goto V_173;
}
V_145 = F_90 ( V_25 , V_144 ) ;
if ( ! V_145 ) {
F_3 ( V_11 ) ;
goto V_173;
}
V_157 = V_145 -> V_2 ;
F_3 ( V_11 ) ;
V_11 = F_88 ( V_25 , 0xfc11 , 2 , V_167 , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_33 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
F_96 ( V_145 ) ;
return F_76 ( V_11 ) ;
}
F_3 ( V_11 ) ;
V_158 = 1 ;
while ( V_145 -> V_53 > V_157 - V_145 -> V_2 ) {
int V_147 ;
V_147 = F_93 ( V_25 , V_145 , & V_157 ,
& V_158 ) ;
if ( V_147 < 0 )
goto V_174;
}
F_96 ( V_145 ) ;
if ( V_158 )
goto V_175;
V_11 = F_88 ( V_25 , 0xfc11 , sizeof( V_170 ) ,
V_170 , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_34 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_92 ( L_35 ,
V_25 -> V_36 ) ;
goto V_173;
V_175:
V_11 = F_88 ( V_25 , 0xfc11 , sizeof( V_168 ) , V_168 ,
V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_34 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_92 ( L_36 , V_25 -> V_36 ) ;
goto V_173;
V_174:
F_96 ( V_145 ) ;
V_11 = F_88 ( V_25 , 0xfc11 , sizeof( V_169 ) ,
V_169 , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_34 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_92 ( L_37 ,
V_25 -> V_36 ) ;
V_173:
F_97 ( V_25 , false ) ;
F_98 ( V_25 ) ;
return 0 ;
}
static int F_99 ( struct V_34 * V_25 , T_4 V_166 )
{
struct V_10 * V_11 ;
struct F_11 * V_176 ;
struct V_177 * V_114 ;
V_11 = F_7 ( sizeof( * V_176 ) + sizeof( * V_114 ) + 1 , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_176 = (struct F_11 * ) F_10 ( V_11 , sizeof( * V_176 ) ) ;
V_176 -> V_114 = V_178 ;
V_176 -> V_22 = sizeof( * V_114 ) + 1 ;
V_114 = (struct V_177 * ) F_10 ( V_11 , sizeof( * V_114 ) ) ;
V_114 -> V_179 = 0x01 ;
V_114 -> V_166 = F_100 ( V_166 ) ;
* F_10 ( V_11 , 1 ) = 0x00 ;
F_8 ( V_11 ) -> V_17 = V_18 ;
return F_17 ( V_25 , V_11 ) ;
}
static int F_101 ( struct V_1 * V_2 , void * V_8 ,
int V_9 )
{
if ( F_23 ( V_180 , & V_2 -> V_3 ) )
return F_5 ( V_2 , V_8 , V_9 ) ;
return F_14 ( V_2 , V_8 , V_9 ) ;
}
static void F_102 ( struct V_1 * V_2 , const void * V_181 ,
unsigned int V_13 )
{
const struct V_182 * V_114 = V_181 ;
if ( V_13 != sizeof( * V_114 ) )
return;
if ( F_85 ( V_183 , & V_2 -> V_3 ) ) {
F_103 () ;
F_104 ( & V_2 -> V_3 , V_183 ) ;
}
}
static void F_105 ( struct V_1 * V_2 ,
const void * V_181 , unsigned int V_13 )
{
const struct V_184 * V_114 = V_181 ;
if ( V_13 != sizeof( * V_114 ) )
return;
if ( V_114 -> V_185 )
F_54 ( V_186 , & V_2 -> V_3 ) ;
if ( F_85 ( V_187 , & V_2 -> V_3 ) &&
F_23 ( V_188 , & V_2 -> V_3 ) ) {
F_103 () ;
F_104 ( & V_2 -> V_3 , V_187 ) ;
}
}
static int F_106 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
if ( F_23 ( V_180 , & V_2 -> V_3 ) ) {
struct F_11 * V_176 = ( void * ) V_11 -> V_2 ;
if ( V_11 -> V_13 > V_20 && V_176 -> V_114 == 0xff &&
V_176 -> V_22 > 0 ) {
const void * V_181 = V_11 -> V_2 + V_20 + 1 ;
unsigned int V_13 = V_11 -> V_13 - V_20 - 1 ;
switch ( V_11 -> V_2 [ 2 ] ) {
case 0x02 :
F_102 ( V_2 , V_181 , V_13 ) ;
break;
case 0x06 :
F_105 ( V_2 , V_181 , V_13 ) ;
break;
}
}
}
return F_17 ( V_25 , V_11 ) ;
}
static int F_107 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
switch ( F_8 ( V_11 ) -> V_17 ) {
case V_109 :
if ( F_23 ( V_180 , & V_2 -> V_3 ) ) {
struct V_159 * V_160 = ( void * ) V_11 -> V_2 ;
T_4 V_166 = F_31 ( V_160 -> V_166 ) ;
if ( V_166 == 0xfc09 )
V_33 = F_67 ( V_25 , V_11 ) ;
else
V_33 = F_62 ( V_25 , V_11 ) ;
if ( V_166 == 0xfc01 )
F_99 ( V_25 , V_166 ) ;
} else {
V_33 = F_62 ( V_25 , V_11 ) ;
}
if ( F_75 ( V_33 ) )
return F_76 ( V_33 ) ;
V_25 -> V_40 . V_110 ++ ;
return F_72 ( V_25 , V_33 ) ;
case V_27 :
V_33 = F_67 ( V_25 , V_11 ) ;
if ( F_75 ( V_33 ) )
return F_76 ( V_33 ) ;
V_25 -> V_40 . V_111 ++ ;
return F_72 ( V_25 , V_33 ) ;
case V_31 :
if ( F_77 ( V_25 , V_112 ) < 1 )
return - V_49 ;
V_33 = F_69 ( V_25 , V_11 ) ;
if ( F_75 ( V_33 ) )
return F_76 ( V_33 ) ;
V_25 -> V_40 . V_113 ++ ;
return F_71 ( V_25 , V_33 ) ;
}
return - V_23 ;
}
static int F_108 ( struct V_34 * V_25 )
{
static const T_3 V_189 [] = { 0x00 , 0x01 , 0x00 , 0x01 ,
0x00 , 0x08 , 0x04 , 0x00 } ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_10 * V_11 ;
struct V_143 * V_144 ;
struct V_190 * V_191 ;
const struct V_142 * V_145 ;
const T_3 * V_157 ;
T_5 V_192 ;
char V_146 [ 64 ] ;
T_6 V_193 , V_194 , V_195 ;
unsigned long long V_196 ;
int V_12 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_193 = F_109 () ;
V_11 = F_88 ( V_25 , 0xfc05 , 0 , NULL , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_38 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_144 ) ) {
F_24 ( L_39 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_23 ;
}
V_144 = (struct V_143 * ) V_11 -> V_2 ;
if ( V_144 -> V_148 != 0x37 ) {
F_24 ( L_40 ,
V_25 -> V_36 , V_144 -> V_148 ) ;
F_3 ( V_11 ) ;
return - V_156 ;
}
if ( V_144 -> V_149 != 0x0b ) {
F_24 ( L_41 ,
V_25 -> V_36 , V_144 -> V_149 ) ;
F_3 ( V_11 ) ;
return - V_156 ;
}
F_110 ( V_25 , V_144 ) ;
if ( V_144 -> V_151 == 0x23 ) {
F_3 ( V_11 ) ;
F_56 ( V_180 , & V_2 -> V_3 ) ;
F_98 ( V_25 ) ;
return 0 ;
}
if ( V_144 -> V_151 != 0x06 ) {
F_24 ( L_42 ,
V_25 -> V_36 , V_144 -> V_151 ) ;
F_3 ( V_11 ) ;
return - V_49 ;
}
F_3 ( V_11 ) ;
V_11 = F_88 ( V_25 , 0xfc0d , 0 , NULL , V_132 ) ;
if ( F_75 ( V_11 ) ) {
F_24 ( L_43 ,
V_25 -> V_36 , F_76 ( V_11 ) ) ;
return F_76 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_191 ) ) {
F_24 ( L_44 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_23 ;
}
V_191 = (struct V_190 * ) V_11 -> V_2 ;
F_92 ( L_45 , V_25 -> V_36 ,
F_31 ( V_191 -> V_197 ) ) ;
F_92 ( L_46 , V_25 -> V_36 ,
V_191 -> V_198 ? L_47 : L_48 ) ;
F_92 ( L_49 , V_25 -> V_36 ,
V_191 -> V_199 ? L_47 : L_48 ) ;
F_92 ( L_50 , V_25 -> V_36 ,
V_191 -> V_200 ? L_47 : L_48 ) ;
F_92 ( L_51 , V_25 -> V_36 ,
V_191 -> V_201 ? L_47 : L_48 ) ;
F_92 ( L_52 , V_25 -> V_36 ,
V_191 -> V_202 , V_191 -> V_203 ,
2000 + V_191 -> V_204 ) ;
if ( V_191 -> V_205 != 0x00 ) {
F_24 ( L_53 ,
V_25 -> V_36 , V_191 -> V_205 ) ;
F_3 ( V_11 ) ;
return - V_156 ;
}
if ( ! F_111 ( & V_191 -> V_206 , V_207 ) ) {
F_92 ( L_54 , V_25 -> V_36 ) ;
F_54 ( V_208 , & V_25 -> V_140 ) ;
}
snprintf ( V_146 , sizeof( V_146 ) , L_55 ,
F_31 ( V_191 -> V_197 ) ) ;
V_12 = F_91 ( & V_145 , V_146 , & V_25 -> V_78 ) ;
if ( V_12 < 0 ) {
F_24 ( L_56 ,
V_25 -> V_36 , V_12 ) ;
F_3 ( V_11 ) ;
return V_12 ;
}
F_92 ( L_57 , V_25 -> V_36 , V_146 ) ;
snprintf ( V_146 , sizeof( V_146 ) , L_58 ,
F_31 ( V_191 -> V_197 ) ) ;
F_3 ( V_11 ) ;
if ( V_145 -> V_53 < 644 ) {
F_24 ( L_59 ,
V_25 -> V_36 , V_145 -> V_53 ) ;
V_12 = - V_209 ;
goto V_79;
}
F_54 ( V_187 , & V_2 -> V_3 ) ;
V_12 = F_112 ( V_25 , 0x00 , 128 , V_145 -> V_2 ) ;
if ( V_12 < 0 ) {
F_24 ( L_60 ,
V_25 -> V_36 , V_12 ) ;
goto V_79;
}
V_12 = F_112 ( V_25 , 0x03 , 256 , V_145 -> V_2 + 128 ) ;
if ( V_12 < 0 ) {
F_24 ( L_61 ,
V_25 -> V_36 , V_12 ) ;
goto V_79;
}
V_12 = F_112 ( V_25 , 0x02 , 256 , V_145 -> V_2 + 388 ) ;
if ( V_12 < 0 ) {
F_24 ( L_62 ,
V_25 -> V_36 , V_12 ) ;
goto V_79;
}
V_157 = V_145 -> V_2 + 644 ;
V_192 = 0 ;
while ( V_157 - V_145 -> V_2 < V_145 -> V_53 ) {
struct V_159 * V_160 = ( void * ) ( V_157 + V_192 ) ;
V_192 += sizeof( * V_160 ) + V_160 -> V_22 ;
if ( ! ( V_192 % 4 ) ) {
V_12 = F_112 ( V_25 , 0x01 , V_192 , V_157 ) ;
if ( V_12 < 0 ) {
F_24 ( L_63 ,
V_25 -> V_36 , V_12 ) ;
goto V_79;
}
V_157 += V_192 ;
V_192 = 0 ;
}
}
F_54 ( V_188 , & V_2 -> V_3 ) ;
F_92 ( L_64 , V_25 -> V_36 ) ;
V_12 = F_113 ( & V_2 -> V_3 , V_187 ,
V_210 ,
F_114 ( 5000 ) ) ;
if ( V_12 == 1 ) {
F_24 ( L_65 , V_25 -> V_36 ) ;
V_12 = - V_211 ;
goto V_79;
}
if ( V_12 ) {
F_24 ( L_66 , V_25 -> V_36 ) ;
V_12 = - V_212 ;
goto V_79;
}
if ( F_23 ( V_186 , & V_2 -> V_3 ) ) {
F_24 ( L_67 , V_25 -> V_36 ) ;
V_12 = - V_213 ;
goto V_79;
}
V_195 = F_109 () ;
V_194 = F_115 ( V_195 , V_193 ) ;
V_196 = ( unsigned long long ) F_116 ( V_194 ) >> 10 ;
F_92 ( L_68 , V_25 -> V_36 , V_196 ) ;
V_79:
F_96 ( V_145 ) ;
if ( V_12 < 0 )
return V_12 ;
V_193 = F_109 () ;
F_54 ( V_183 , & V_2 -> V_3 ) ;
V_11 = F_88 ( V_25 , 0xfc01 , sizeof( V_189 ) , V_189 ,
V_132 ) ;
if ( F_75 ( V_11 ) )
return F_76 ( V_11 ) ;
F_3 ( V_11 ) ;
F_92 ( L_69 , V_25 -> V_36 ) ;
V_12 = F_113 ( & V_2 -> V_3 , V_183 ,
V_210 ,
F_114 ( 1000 ) ) ;
if ( V_12 == 1 ) {
F_24 ( L_70 , V_25 -> V_36 ) ;
return - V_211 ;
}
if ( V_12 ) {
F_24 ( L_71 , V_25 -> V_36 ) ;
return - V_212 ;
}
V_195 = F_109 () ;
V_194 = F_115 ( V_195 , V_193 ) ;
V_196 = ( unsigned long long ) F_116 ( V_194 ) >> 10 ;
F_92 ( L_72 , V_25 -> V_36 , V_196 ) ;
F_56 ( V_180 , & V_2 -> V_3 ) ;
F_117 ( V_25 , V_146 ) ;
F_118 ( V_25 , false ) ;
return 0 ;
}
static int F_119 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
long V_147 ;
V_11 = F_88 ( V_25 , 0xfc3f , 0 , NULL , V_132 ) ;
if ( F_75 ( V_11 ) ) {
V_147 = F_76 ( V_11 ) ;
F_24 ( L_73 ,
V_25 -> V_36 , V_147 ) ;
return V_147 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_120 ( struct V_34 * V_25 ,
const T_7 * V_214 )
{
struct V_10 * V_11 ;
T_3 V_51 [ 8 ] ;
long V_147 ;
V_51 [ 0 ] = 0xfe ;
V_51 [ 1 ] = sizeof( T_7 ) ;
memcpy ( V_51 + 2 , V_214 , sizeof( T_7 ) ) ;
V_11 = F_88 ( V_25 , 0xfc22 , sizeof( V_51 ) , V_51 , V_132 ) ;
if ( F_75 ( V_11 ) ) {
V_147 = F_76 ( V_11 ) ;
F_24 ( L_74 ,
V_25 -> V_36 , V_147 ) ;
return V_147 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_121 ( struct V_34 * V_25 ,
const T_7 * V_214 )
{
struct V_10 * V_11 ;
T_3 V_51 [ 10 ] ;
long V_147 ;
V_51 [ 0 ] = 0x01 ;
V_51 [ 1 ] = 0x01 ;
V_51 [ 2 ] = 0x00 ;
V_51 [ 3 ] = sizeof( T_7 ) ;
memcpy ( V_51 + 4 , V_214 , sizeof( T_7 ) ) ;
V_11 = F_88 ( V_25 , 0xfc0b , sizeof( V_51 ) , V_51 , V_132 ) ;
if ( F_75 ( V_11 ) ) {
V_147 = F_76 ( V_11 ) ;
F_24 ( L_75 ,
V_25 -> V_36 , V_147 ) ;
return V_147 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_122 ( struct V_34 * V_25 , T_3 V_215 ,
void * V_2 , T_8 V_53 )
{
struct V_1 * V_216 = F_21 ( V_25 ) ;
struct V_217 * V_46 = V_216 -> V_46 ;
int V_52 , V_12 ;
T_3 * V_51 ;
V_51 = F_32 ( V_53 , V_89 ) ;
if ( ! V_51 )
return - V_16 ;
V_52 = F_123 ( V_46 , 0 ) ;
V_12 = F_124 ( V_46 , V_52 , V_215 , V_218 | V_219 ,
0 , 0 , V_51 , V_53 , V_220 ) ;
if ( V_12 < 0 ) {
F_24 ( L_76 , V_25 -> V_36 , V_12 ) ;
goto V_79;
}
memcpy ( V_2 , V_51 , V_53 ) ;
V_79:
F_48 ( V_51 ) ;
return V_12 ;
}
static int F_125 ( struct V_34 * V_25 ,
const struct V_142 * V_142 ,
T_9 V_221 )
{
struct V_1 * V_216 = F_21 ( V_25 ) ;
struct V_217 * V_46 = V_216 -> V_46 ;
T_9 V_9 , V_53 , V_222 = 0 ;
int V_52 , V_13 , V_12 ;
T_3 * V_51 ;
V_51 = F_32 ( V_223 , V_89 ) ;
if ( ! V_51 )
return - V_16 ;
V_9 = V_142 -> V_53 ;
V_53 = F_9 ( T_9 , V_9 , V_221 ) ;
memcpy ( V_51 , V_142 -> V_2 , V_53 ) ;
V_52 = F_65 ( V_46 , 0 ) ;
V_12 = F_124 ( V_46 , V_52 , V_224 , V_218 ,
0 , 0 , V_51 , V_53 , V_220 ) ;
if ( V_12 < 0 ) {
F_24 ( L_77 , V_25 -> V_36 , V_12 ) ;
goto V_79;
}
V_222 += V_53 ;
V_9 -= V_53 ;
while ( V_9 ) {
V_53 = F_9 ( T_9 , V_9 , V_223 ) ;
memcpy ( V_51 , V_142 -> V_2 + V_222 , V_53 ) ;
V_52 = F_68 ( V_46 , 0x02 ) ;
V_12 = F_126 ( V_46 , V_52 , V_51 , V_53 , & V_13 ,
V_225 ) ;
if ( V_12 < 0 ) {
F_24 ( L_78 ,
V_25 -> V_36 , V_222 , V_142 -> V_53 , V_12 ) ;
break;
}
if ( V_53 != V_13 ) {
F_24 ( L_79 , V_25 -> V_36 ) ;
V_12 = - V_23 ;
break;
}
V_222 += V_53 ;
V_9 -= V_53 ;
}
V_79:
F_48 ( V_51 ) ;
return V_12 ;
}
static int F_127 ( struct V_34 * V_25 ,
struct V_226 * V_144 ,
const struct V_227 * V_228 )
{
struct V_229 * V_230 ;
const struct V_142 * V_145 ;
T_5 V_231 , V_232 ;
T_8 V_233 , V_234 ;
char V_146 [ 64 ] ;
int V_12 ;
V_231 = F_128 ( V_144 -> V_235 ) ;
V_232 = F_128 ( V_144 -> V_236 ) ;
snprintf ( V_146 , sizeof( V_146 ) , L_80 , V_231 ) ;
V_12 = F_91 ( & V_145 , V_146 , & V_25 -> V_78 ) ;
if ( V_12 ) {
F_24 ( L_81 ,
V_25 -> V_36 , V_146 , V_12 ) ;
return V_12 ;
}
F_92 ( L_82 , V_25 -> V_36 , V_146 ) ;
V_230 = (struct V_229 * ) ( V_145 -> V_2 + V_228 -> V_237 ) ;
V_233 = F_31 ( V_230 -> V_235 ) ;
V_234 = F_31 ( V_230 -> V_236 ) ;
F_92 ( L_83
L_84 , V_25 -> V_36 , V_233 , V_234 , V_231 ,
V_232 ) ;
if ( V_233 != V_231 || V_234 <= V_232 ) {
F_24 ( L_85 ,
V_25 -> V_36 ) ;
V_12 = - V_156 ;
goto V_79;
}
V_12 = F_125 ( V_25 , V_145 , V_228 -> V_238 ) ;
V_79:
F_96 ( V_145 ) ;
return V_12 ;
}
static int F_129 ( struct V_34 * V_25 ,
struct V_226 * V_144 ,
const struct V_227 * V_228 )
{
const struct V_142 * V_145 ;
char V_146 [ 64 ] ;
int V_12 ;
snprintf ( V_146 , sizeof( V_146 ) , L_86 ,
F_128 ( V_144 -> V_235 ) ) ;
V_12 = F_91 ( & V_145 , V_146 , & V_25 -> V_78 ) ;
if ( V_12 ) {
F_24 ( L_87 ,
V_25 -> V_36 , V_146 , V_12 ) ;
return V_12 ;
}
F_92 ( L_88 , V_25 -> V_36 , V_146 ) ;
V_12 = F_125 ( V_25 , V_145 , V_228 -> V_239 ) ;
F_96 ( V_145 ) ;
return V_12 ;
}
static int F_130 ( struct V_34 * V_25 )
{
const struct V_227 * V_228 = NULL ;
struct V_226 V_144 ;
T_5 V_231 ;
T_3 V_37 ;
int V_64 , V_12 ;
V_12 = F_122 ( V_25 , V_240 , & V_144 ,
sizeof( V_144 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_231 = F_128 ( V_144 . V_235 ) ;
for ( V_64 = 0 ; V_64 < F_131 ( V_241 ) ; V_64 ++ ) {
if ( V_231 == V_241 [ V_64 ] . V_235 )
V_228 = & V_241 [ V_64 ] ;
}
if ( ! V_228 ) {
F_24 ( L_89 , V_25 -> V_36 ,
V_231 ) ;
return - V_49 ;
}
V_12 = F_122 ( V_25 , V_242 , & V_37 ,
sizeof( V_37 ) ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_37 & V_243 ) ) {
V_12 = F_127 ( V_25 , & V_144 , V_228 ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( ! ( V_37 & V_244 ) ) {
V_12 = F_129 ( V_25 , & V_144 , V_228 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static inline int F_132 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_117 * V_87 = V_2 -> V_91 ;
int V_64 ;
if ( ! V_2 -> V_91 )
return - V_49 ;
V_2 -> V_245 = NULL ;
V_2 -> V_77 = NULL ;
for ( V_64 = 0 ; V_64 < V_87 -> V_122 -> V_123 . V_124 ; V_64 ++ ) {
struct V_119 * V_120 ;
V_120 = & V_87 -> V_122 -> V_125 [ V_64 ] . V_123 ;
if ( ! V_2 -> V_245 && F_133 ( V_120 ) ) {
V_2 -> V_245 = V_120 ;
continue;
}
if ( ! V_2 -> V_77 && F_134 ( V_120 ) ) {
V_2 -> V_77 = V_120 ;
continue;
}
}
if ( ! V_2 -> V_245 || ! V_2 -> V_77 ) {
F_24 ( L_90 , V_25 -> V_36 ) ;
return - V_49 ;
}
return 0 ;
}
static struct V_33 * F_135 ( struct V_34 * V_25 , bool V_246 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_10 * V_11 ;
struct V_33 * V_33 ;
unsigned int V_52 ;
if ( ! V_2 -> V_245 )
return F_63 ( - V_49 ) ;
V_33 = F_30 ( 0 , V_89 ) ;
if ( ! V_33 )
return F_63 ( - V_16 ) ;
V_11 = F_7 ( 2 , V_89 ) ;
if ( ! V_11 ) {
F_33 ( V_33 ) ;
return F_63 ( - V_16 ) ;
}
* F_10 ( V_11 , 1 ) = 0xf0 ;
* F_10 ( V_11 , 1 ) = V_246 ;
V_52 = F_68 ( V_2 -> V_46 , V_2 -> V_245 -> V_56 ) ;
F_39 ( V_33 , V_2 -> V_46 , V_52 ,
V_11 -> V_2 , V_11 -> V_13 , F_47 , V_11 ) ;
V_11 -> V_78 = ( void * ) V_25 ;
return V_33 ;
}
static int F_136 ( struct V_34 * V_25 , bool V_246 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
if ( ! V_2 -> V_91 )
return - V_49 ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
return - V_247 ;
V_33 = F_135 ( V_25 , V_246 ) ;
if ( F_75 ( V_33 ) )
return F_76 ( V_33 ) ;
return F_72 ( V_25 , V_33 ) ;
}
static int F_137 ( struct V_117 * V_87 ,
const struct V_248 * V_249 )
{
struct V_119 * V_120 ;
struct V_1 * V_2 ;
struct V_34 * V_25 ;
unsigned V_250 ;
int V_64 , V_12 ;
F_22 ( L_91 , V_87 , V_249 ) ;
if ( V_87 -> V_122 -> V_123 . V_251 != 0 ) {
if ( ! ( V_249 -> V_252 & V_253 ) )
return - V_49 ;
if ( V_87 -> V_122 -> V_123 . V_251 != 2 )
return - V_49 ;
}
V_250 = V_87 -> V_122 -> V_123 . V_251 ;
if ( ! V_249 -> V_252 ) {
const struct V_248 * V_254 ;
V_254 = F_138 ( V_87 , V_255 ) ;
if ( V_254 )
V_249 = V_254 ;
}
if ( V_249 -> V_252 == V_256 )
return - V_49 ;
if ( V_249 -> V_252 & V_257 ) {
struct V_217 * V_46 = F_139 ( V_87 ) ;
if ( F_31 ( V_46 -> V_258 . V_259 ) <= 0x0001 )
return - V_49 ;
}
V_2 = F_140 ( & V_87 -> V_78 , sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return - V_16 ;
for ( V_64 = 0 ; V_64 < V_87 -> V_122 -> V_123 . V_124 ; V_64 ++ ) {
V_120 = & V_87 -> V_122 -> V_125 [ V_64 ] . V_123 ;
if ( ! V_2 -> V_54 && F_141 ( V_120 ) ) {
V_2 -> V_54 = V_120 ;
continue;
}
if ( ! V_2 -> V_105 && F_133 ( V_120 ) ) {
V_2 -> V_105 = V_120 ;
continue;
}
if ( ! V_2 -> V_63 && F_134 ( V_120 ) ) {
V_2 -> V_63 = V_120 ;
continue;
}
}
if ( ! V_2 -> V_54 || ! V_2 -> V_105 || ! V_2 -> V_63 )
return - V_49 ;
if ( V_249 -> V_252 & V_260 ) {
V_2 -> V_99 = V_261 | 0x01 ;
V_2 -> V_101 = 0x2b ;
} else {
V_2 -> V_99 = V_261 ;
V_2 -> V_101 = 0x00 ;
}
V_2 -> V_46 = F_139 ( V_87 ) ;
V_2 -> V_87 = V_87 ;
F_142 ( & V_2 -> V_92 , F_83 ) ;
F_142 ( & V_2 -> V_93 , F_86 ) ;
F_143 ( & V_2 -> V_94 ) ;
F_143 ( & V_2 -> V_95 ) ;
F_144 ( & V_2 -> V_83 ) ;
F_143 ( & V_2 -> V_47 ) ;
F_143 ( & V_2 -> V_62 ) ;
F_143 ( & V_2 -> V_70 ) ;
F_143 ( & V_2 -> V_76 ) ;
F_144 ( & V_2 -> V_4 ) ;
if ( V_249 -> V_252 & V_262 ) {
V_2 -> V_24 = F_106 ;
V_2 -> V_60 = F_101 ;
F_54 ( V_180 , & V_2 -> V_3 ) ;
} else {
V_2 -> V_24 = F_17 ;
V_2 -> V_60 = F_14 ;
}
V_25 = F_145 () ;
if ( ! V_25 )
return - V_16 ;
V_25 -> V_263 = V_264 ;
F_146 ( V_25 , V_2 ) ;
if ( V_249 -> V_252 & V_260 )
V_25 -> V_265 = V_266 ;
else
V_25 -> V_265 = V_267 ;
V_2 -> V_25 = V_25 ;
F_147 ( V_25 , & V_87 -> V_78 ) ;
V_25 -> V_268 = F_50 ;
V_25 -> V_269 = F_58 ;
V_25 -> V_270 = F_61 ;
V_25 -> V_271 = F_74 ;
V_25 -> V_272 = F_78 ;
if ( V_249 -> V_252 & V_273 )
F_54 ( V_141 , & V_25 -> V_140 ) ;
if ( V_249 -> V_252 & V_274 )
V_25 -> V_275 = F_87 ;
#ifdef F_148
if ( V_249 -> V_252 & V_276 ) {
V_25 -> V_137 = 15 ;
V_25 -> V_275 = V_277 ;
V_25 -> V_278 = F_136 ;
V_25 -> V_279 = V_280 ;
V_2 -> V_91 = F_149 ( V_2 -> V_46 , V_250 + 2 ) ;
}
if ( V_249 -> V_252 & V_281 ) {
V_25 -> V_137 = 15 ;
V_25 -> V_275 = V_282 ;
V_25 -> V_278 = F_136 ;
V_2 -> V_91 = F_149 ( V_2 -> V_46 , V_250 + 2 ) ;
}
#endif
if ( V_249 -> V_252 & V_283 ) {
V_25 -> V_137 = 2 ;
V_25 -> V_275 = F_95 ;
V_25 -> V_284 = F_119 ;
V_25 -> V_278 = V_285 ;
V_25 -> V_279 = V_286 ;
F_54 ( V_287 , & V_25 -> V_140 ) ;
F_54 ( V_288 , & V_25 -> V_140 ) ;
F_54 ( V_289 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_262 ) {
V_25 -> V_137 = 2 ;
V_25 -> V_271 = F_107 ;
V_25 -> V_275 = F_108 ;
V_25 -> V_290 = V_291 ;
V_25 -> V_278 = V_292 ;
V_25 -> V_279 = V_286 ;
F_54 ( V_287 , & V_25 -> V_140 ) ;
F_54 ( V_289 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_293 )
V_25 -> V_279 = F_120 ;
if ( V_249 -> V_252 & V_294 ) {
F_54 ( V_295 , & V_25 -> V_140 ) ;
F_54 ( V_296 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_297 ) {
V_25 -> V_137 = 2 ;
F_54 ( V_298 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_257 ) {
V_25 -> V_279 = F_121 ;
F_54 ( V_288 , & V_25 -> V_140 ) ;
F_54 ( V_287 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_299 ) {
V_2 -> V_86 = F_130 ;
V_25 -> V_279 = F_121 ;
}
#ifdef F_150
if ( V_249 -> V_252 & V_300 ) {
V_25 -> V_275 = V_301 ;
F_54 ( V_302 , & V_2 -> V_3 ) ;
}
#endif
if ( V_249 -> V_252 & V_260 ) {
V_2 -> V_118 = NULL ;
} else {
V_2 -> V_118 = F_149 ( V_2 -> V_46 , V_250 + 1 ) ;
}
if ( ! V_303 )
F_54 ( V_139 , & V_25 -> V_140 ) ;
if ( V_304 || V_249 -> V_252 & V_305 ) {
if ( ! V_306 )
F_54 ( V_307 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_308 )
V_2 -> V_118 = NULL ;
if ( V_249 -> V_252 & V_309 ) {
V_2 -> V_99 = V_218 ;
F_54 ( V_139 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_310 ) {
struct V_217 * V_46 = V_2 -> V_46 ;
T_8 V_259 = F_31 ( V_46 -> V_258 . V_259 ) ;
if ( V_259 < 0x117 )
F_54 ( V_139 , & V_25 -> V_140 ) ;
if ( V_259 <= 0x100 || V_259 == 0x134 )
V_25 -> V_275 = F_89 ;
F_54 ( V_288 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_311 ) {
struct V_217 * V_46 = V_2 -> V_46 ;
if ( F_31 ( V_46 -> V_258 . V_259 ) > 0x997 )
F_54 ( V_298 , & V_25 -> V_140 ) ;
}
if ( V_249 -> V_252 & V_297 ) {
V_12 = F_80 ( V_2 -> V_46 , 0 , 0 ) ;
if ( V_12 < 0 ) {
F_24 ( L_92 , V_12 ) ;
F_151 ( V_25 ) ;
return V_12 ;
}
}
if ( V_2 -> V_118 ) {
V_12 = F_152 ( & V_312 ,
V_2 -> V_118 , V_2 ) ;
if ( V_12 < 0 ) {
F_151 ( V_25 ) ;
return V_12 ;
}
}
#ifdef F_148
if ( V_2 -> V_91 ) {
if ( ! F_152 ( & V_312 ,
V_2 -> V_91 , V_2 ) )
F_132 ( V_25 ) ;
else
V_2 -> V_91 = NULL ;
}
#endif
V_12 = F_153 ( V_25 ) ;
if ( V_12 < 0 ) {
F_151 ( V_25 ) ;
return V_12 ;
}
F_154 ( V_87 , V_2 ) ;
return 0 ;
}
static void F_155 ( struct V_117 * V_87 )
{
struct V_1 * V_2 = F_156 ( V_87 ) ;
struct V_34 * V_25 ;
F_22 ( L_93 , V_87 ) ;
if ( ! V_2 )
return;
V_25 = V_2 -> V_25 ;
F_154 ( V_2 -> V_87 , NULL ) ;
if ( V_2 -> V_118 )
F_154 ( V_2 -> V_118 , NULL ) ;
if ( V_2 -> V_91 )
F_154 ( V_2 -> V_91 , NULL ) ;
F_157 ( V_25 ) ;
if ( V_87 == V_2 -> V_87 ) {
if ( V_2 -> V_118 )
F_158 ( & V_312 , V_2 -> V_118 ) ;
if ( V_2 -> V_91 )
F_158 ( & V_312 , V_2 -> V_91 ) ;
} else if ( V_87 == V_2 -> V_118 ) {
if ( V_2 -> V_91 )
F_158 ( & V_312 , V_2 -> V_91 ) ;
F_158 ( & V_312 , V_2 -> V_87 ) ;
} else if ( V_87 == V_2 -> V_91 ) {
F_158 ( & V_312 , V_2 -> V_87 ) ;
if ( V_2 -> V_118 )
F_158 ( & V_312 , V_2 -> V_118 ) ;
}
F_151 ( V_25 ) ;
}
static int F_159 ( struct V_117 * V_87 , T_10 V_313 )
{
struct V_1 * V_2 = F_156 ( V_87 ) ;
F_22 ( L_93 , V_87 ) ;
if ( V_2 -> V_314 ++ )
return 0 ;
F_160 ( & V_2 -> V_83 ) ;
if ( ! ( F_161 ( V_313 ) && V_2 -> V_84 ) ) {
F_54 ( V_108 , & V_2 -> V_3 ) ;
F_162 ( & V_2 -> V_83 ) ;
} else {
F_162 ( & V_2 -> V_83 ) ;
V_2 -> V_314 -- ;
return - V_315 ;
}
F_59 ( & V_2 -> V_92 ) ;
F_57 ( V_2 ) ;
F_53 ( & V_2 -> V_95 ) ;
if ( F_23 ( V_302 , & V_2 -> V_3 ) &&
! F_163 ( & V_2 -> V_46 -> V_78 ) )
V_2 -> V_46 -> V_316 = 1 ;
return 0 ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_33 * V_33 ;
int V_12 ;
while ( ( V_33 = F_165 ( & V_2 -> V_94 ) ) ) {
V_12 = F_27 ( V_33 , V_15 ) ;
if ( V_12 < 0 )
break;
V_2 -> V_84 ++ ;
}
F_60 ( & V_2 -> V_94 ) ;
}
static int F_166 ( struct V_117 * V_87 )
{
struct V_1 * V_2 = F_156 ( V_87 ) ;
struct V_34 * V_25 = V_2 -> V_25 ;
int V_12 = 0 ;
F_22 ( L_93 , V_87 ) ;
if ( -- V_2 -> V_314 )
return 0 ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
goto V_79;
if ( F_23 ( V_45 , & V_2 -> V_3 ) ) {
V_12 = F_29 ( V_25 , V_317 ) ;
if ( V_12 < 0 ) {
F_56 ( V_45 , & V_2 -> V_3 ) ;
goto V_90;
}
}
if ( F_23 ( V_61 , & V_2 -> V_3 ) ) {
V_12 = F_37 ( V_25 , V_317 ) ;
if ( V_12 < 0 ) {
F_56 ( V_61 , & V_2 -> V_3 ) ;
goto V_90;
}
F_37 ( V_25 , V_317 ) ;
}
if ( F_23 ( V_69 , & V_2 -> V_3 ) ) {
if ( F_42 ( V_25 , V_317 ) < 0 )
F_56 ( V_69 , & V_2 -> V_3 ) ;
else
F_42 ( V_25 , V_317 ) ;
}
F_160 ( & V_2 -> V_83 ) ;
F_164 ( V_2 ) ;
F_56 ( V_108 , & V_2 -> V_3 ) ;
F_162 ( & V_2 -> V_83 ) ;
F_73 ( & V_2 -> V_92 ) ;
return 0 ;
V_90:
F_60 ( & V_2 -> V_94 ) ;
V_79:
F_160 ( & V_2 -> V_83 ) ;
F_56 ( V_108 , & V_2 -> V_3 ) ;
F_162 ( & V_2 -> V_83 ) ;
return V_12 ;
}
