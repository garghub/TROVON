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
struct V_10 * V_11 = V_33 -> V_35 ;
struct V_34 * V_25 = (struct V_34 * ) V_11 -> V_75 ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
goto V_76;
if ( ! V_33 -> V_37 )
V_25 -> V_40 . V_77 += V_33 -> V_78 ;
else
V_25 -> V_40 . V_79 ++ ;
V_76:
F_6 ( & V_2 -> V_80 ) ;
V_2 -> V_81 -- ;
F_13 ( & V_2 -> V_80 ) ;
F_45 ( V_33 -> V_82 ) ;
F_3 ( V_11 ) ;
}
static void F_46 ( struct V_33 * V_33 )
{
struct V_10 * V_11 = V_33 -> V_35 ;
struct V_34 * V_25 = (struct V_34 * ) V_11 -> V_75 ;
F_22 ( L_1 , V_25 -> V_36 , V_33 , V_33 -> V_37 ,
V_33 -> V_38 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
goto V_76;
if ( ! V_33 -> V_37 )
V_25 -> V_40 . V_77 += V_33 -> V_78 ;
else
V_25 -> V_40 . V_79 ++ ;
V_76:
F_45 ( V_33 -> V_82 ) ;
F_3 ( V_11 ) ;
}
static int F_47 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( V_2 -> V_83 ) {
V_12 = V_2 -> V_83 ( V_25 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_12 = F_48 ( V_2 -> V_84 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_84 -> V_85 = 1 ;
if ( F_49 ( V_39 , & V_25 -> V_3 ) )
goto V_76;
if ( F_49 ( V_45 , & V_2 -> V_3 ) )
goto V_76;
V_12 = F_29 ( V_25 , V_86 ) ;
if ( V_12 < 0 )
goto V_87;
V_12 = F_37 ( V_25 , V_86 ) ;
if ( V_12 < 0 ) {
F_50 ( & V_2 -> V_47 ) ;
goto V_87;
}
F_51 ( V_61 , & V_2 -> V_3 ) ;
F_37 ( V_25 , V_86 ) ;
V_76:
F_52 ( V_2 -> V_84 ) ;
return 0 ;
V_87:
F_53 ( V_45 , & V_2 -> V_3 ) ;
F_53 ( V_39 , & V_25 -> V_3 ) ;
F_52 ( V_2 -> V_84 ) ;
return V_12 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_47 ) ;
F_50 ( & V_2 -> V_62 ) ;
F_50 ( & V_2 -> V_70 ) ;
}
static int F_55 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! F_56 ( V_39 , & V_25 -> V_3 ) )
return 0 ;
F_57 ( & V_2 -> V_88 ) ;
F_57 ( & V_2 -> V_89 ) ;
F_53 ( V_69 , & V_2 -> V_3 ) ;
F_53 ( V_61 , & V_2 -> V_3 ) ;
F_53 ( V_45 , & V_2 -> V_3 ) ;
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
V_12 = F_48 ( V_2 -> V_84 ) ;
if ( V_12 < 0 )
goto V_87;
V_2 -> V_84 -> V_85 = 0 ;
F_52 ( V_2 -> V_84 ) ;
V_87:
F_58 ( & V_2 -> V_90 ) ;
return 0 ;
}
static int F_59 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_22 ( L_4 , V_25 -> V_36 ) ;
F_50 ( & V_2 -> V_91 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static struct V_33 * F_60 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_92 * V_93 ;
struct V_33 * V_33 ;
unsigned int V_52 ;
V_33 = F_30 ( 0 , V_86 ) ;
if ( ! V_33 )
return F_61 ( - V_16 ) ;
V_93 = F_32 ( sizeof( * V_93 ) , V_86 ) ;
if ( ! V_93 ) {
F_33 ( V_33 ) ;
return F_61 ( - V_16 ) ;
}
V_93 -> V_94 = V_2 -> V_95 ;
V_93 -> V_96 = V_2 -> V_97 ;
V_93 -> V_98 = 0 ;
V_93 -> V_99 = 0 ;
V_93 -> V_100 = F_62 ( V_11 -> V_13 ) ;
V_52 = F_63 ( V_2 -> V_46 , 0x00 ) ;
F_64 ( V_33 , V_2 -> V_46 , V_52 , ( void * ) V_93 ,
V_11 -> V_2 , V_11 -> V_13 , F_44 , V_11 ) ;
V_11 -> V_75 = ( void * ) V_25 ;
return V_33 ;
}
static struct V_33 * F_65 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned int V_52 ;
if ( ! V_2 -> V_101 )
return F_61 ( - V_49 ) ;
V_33 = F_30 ( 0 , V_86 ) ;
if ( ! V_33 )
return F_61 ( - V_16 ) ;
V_52 = F_66 ( V_2 -> V_46 , V_2 -> V_101 -> V_56 ) ;
F_39 ( V_33 , V_2 -> V_46 , V_52 ,
V_11 -> V_2 , V_11 -> V_13 , F_44 , V_11 ) ;
V_11 -> V_75 = ( void * ) V_25 ;
return V_33 ;
}
static struct V_33 * F_67 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
unsigned int V_52 ;
if ( ! V_2 -> V_102 )
return F_61 ( - V_49 ) ;
V_33 = F_30 ( V_72 , V_86 ) ;
if ( ! V_33 )
return F_61 ( - V_16 ) ;
V_52 = F_68 ( V_2 -> V_46 , V_2 -> V_102 -> V_56 ) ;
F_35 ( V_33 , V_2 -> V_46 , V_52 ,
V_11 -> V_2 , V_11 -> V_13 , F_46 ,
V_11 , V_2 -> V_102 -> V_57 ) ;
V_33 -> V_58 = V_74 ;
F_41 ( V_33 , V_11 -> V_13 ,
F_31 ( V_2 -> V_102 -> V_55 ) ) ;
V_11 -> V_75 = ( void * ) V_25 ;
return V_33 ;
}
static int F_69 ( struct V_34 * V_25 , struct V_33 * V_33 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_12 ;
F_26 ( V_33 , & V_2 -> V_91 ) ;
V_12 = F_27 ( V_33 , V_86 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_48 && V_12 != - V_49 )
F_24 ( L_5 ,
V_25 -> V_36 , V_33 , - V_12 ) ;
F_45 ( V_33 -> V_82 ) ;
F_28 ( V_33 ) ;
} else {
F_25 ( V_2 -> V_46 ) ;
}
F_33 ( V_33 ) ;
return V_12 ;
}
static int F_70 ( struct V_34 * V_25 , struct V_33 * V_33 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
unsigned long V_3 ;
bool V_103 ;
F_2 ( & V_2 -> V_80 , V_3 ) ;
V_103 = F_23 ( V_104 , & V_2 -> V_3 ) ;
if ( ! V_103 )
V_2 -> V_81 ++ ;
F_4 ( & V_2 -> V_80 , V_3 ) ;
if ( ! V_103 )
return F_69 ( V_25 , V_33 ) ;
F_26 ( V_33 , & V_2 -> V_90 ) ;
F_71 ( & V_2 -> V_89 ) ;
F_33 ( V_33 ) ;
return 0 ;
}
static int F_72 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_33 * V_33 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
return - V_105 ;
switch ( F_8 ( V_11 ) -> V_17 ) {
case V_106 :
V_33 = F_60 ( V_25 , V_11 ) ;
if ( F_73 ( V_33 ) )
return F_74 ( V_33 ) ;
V_25 -> V_40 . V_107 ++ ;
return F_70 ( V_25 , V_33 ) ;
case V_27 :
V_33 = F_65 ( V_25 , V_11 ) ;
if ( F_73 ( V_33 ) )
return F_74 ( V_33 ) ;
V_25 -> V_40 . V_108 ++ ;
return F_70 ( V_25 , V_33 ) ;
case V_31 :
if ( F_75 ( V_25 , V_109 ) < 1 )
return - V_49 ;
V_33 = F_67 ( V_25 , V_11 ) ;
if ( F_73 ( V_33 ) )
return F_74 ( V_33 ) ;
V_25 -> V_40 . V_110 ++ ;
return F_69 ( V_25 , V_33 ) ;
}
return - V_23 ;
}
static void F_76 ( struct V_34 * V_25 , unsigned int V_111 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_22 ( L_9 , V_25 -> V_36 , V_111 ) ;
if ( F_75 ( V_25 , V_109 ) != V_2 -> V_112 ) {
V_2 -> V_112 = F_75 ( V_25 , V_109 ) ;
F_71 ( & V_2 -> V_88 ) ;
}
}
static inline int F_77 ( struct V_34 * V_25 , int V_113 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_114 * V_84 = V_2 -> V_115 ;
struct V_116 * V_117 ;
int V_64 , V_12 ;
if ( ! V_2 -> V_115 )
return - V_49 ;
V_12 = F_78 ( V_2 -> V_46 , 1 , V_113 ) ;
if ( V_12 < 0 ) {
F_24 ( L_10 , V_25 -> V_36 , - V_12 ) ;
return V_12 ;
}
V_2 -> V_118 = V_113 ;
V_2 -> V_102 = NULL ;
V_2 -> V_73 = NULL ;
for ( V_64 = 0 ; V_64 < V_84 -> V_119 -> V_120 . V_121 ; V_64 ++ ) {
V_117 = & V_84 -> V_119 -> V_122 [ V_64 ] . V_120 ;
if ( ! V_2 -> V_102 && F_79 ( V_117 ) ) {
V_2 -> V_102 = V_117 ;
continue;
}
if ( ! V_2 -> V_73 && F_80 ( V_117 ) ) {
V_2 -> V_73 = V_117 ;
continue;
}
}
if ( ! V_2 -> V_102 || ! V_2 -> V_73 ) {
F_24 ( L_11 , V_25 -> V_36 ) ;
return - V_49 ;
}
return 0 ;
}
static void F_81 ( struct V_123 * V_88 )
{
struct V_1 * V_2 = F_82 ( V_88 , struct V_1 , V_88 ) ;
struct V_34 * V_25 = V_2 -> V_25 ;
int V_124 ;
int V_12 ;
if ( V_2 -> V_112 > 0 ) {
if ( ! F_23 ( V_125 , & V_2 -> V_3 ) ) {
V_12 = F_48 ( V_2 -> V_115 ? V_2 -> V_115 : V_2 -> V_84 ) ;
if ( V_12 < 0 ) {
F_53 ( V_69 , & V_2 -> V_3 ) ;
F_50 ( & V_2 -> V_70 ) ;
return;
}
F_51 ( V_125 , & V_2 -> V_3 ) ;
}
if ( V_25 -> V_126 & 0x0020 ) {
static const int V_127 [ 3 ] = { 2 , 4 , 5 } ;
V_124 = V_127 [ V_2 -> V_112 - 1 ] ;
} else {
V_124 = V_2 -> V_112 ;
}
if ( V_2 -> V_118 != V_124 ) {
F_53 ( V_69 , & V_2 -> V_3 ) ;
F_50 ( & V_2 -> V_70 ) ;
if ( F_77 ( V_25 , V_124 ) < 0 )
return;
}
if ( ! F_49 ( V_69 , & V_2 -> V_3 ) ) {
if ( F_42 ( V_25 , V_86 ) < 0 )
F_53 ( V_69 , & V_2 -> V_3 ) ;
else
F_42 ( V_25 , V_86 ) ;
}
} else {
F_53 ( V_69 , & V_2 -> V_3 ) ;
F_50 ( & V_2 -> V_70 ) ;
F_77 ( V_25 , 0 ) ;
if ( F_56 ( V_125 , & V_2 -> V_3 ) )
F_52 ( V_2 -> V_115 ? V_2 -> V_115 : V_2 -> V_84 ) ;
}
}
static void F_83 ( struct V_123 * V_88 )
{
struct V_1 * V_2 = F_82 ( V_88 , struct V_1 , V_89 ) ;
int V_12 ;
V_12 = F_48 ( V_2 -> V_84 ) ;
if ( V_12 < 0 )
return;
F_52 ( V_2 -> V_84 ) ;
}
static struct V_10 * F_84 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
V_11 = F_85 ( V_25 , V_128 , 0 , NULL ,
V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_12 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return V_11 ;
}
if ( V_11 -> V_13 != sizeof( struct V_130 ) ) {
F_24 ( L_13 ,
V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return F_61 ( - V_131 ) ;
}
return V_11 ;
}
static int F_86 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
T_3 V_132 = 0x00 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_85 ( V_25 , 0xfc3b , 1 , & V_132 , V_129 ) ;
if ( F_73 ( V_11 ) )
F_24 ( L_14 , - F_74 ( V_11 ) ) ;
else
F_3 ( V_11 ) ;
return 0 ;
}
static int F_87 ( struct V_34 * V_25 )
{
struct V_130 * V_133 ;
struct V_10 * V_11 ;
int V_134 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_84 ( V_25 ) ;
if ( F_73 ( V_11 ) )
return - F_74 ( V_11 ) ;
V_133 = (struct V_130 * ) V_11 -> V_2 ;
if ( ! V_133 -> V_37 ) {
if ( F_31 ( V_133 -> V_135 ) != 10 ) {
F_53 ( V_136 , & V_25 -> V_137 ) ;
F_51 ( V_138 ,
& V_25 -> V_137 ) ;
}
}
V_134 = - F_88 ( V_133 -> V_37 ) ;
F_3 ( V_11 ) ;
return V_134 ;
}
static int F_89 ( struct V_34 * V_25 , T_3 * V_139 )
{
struct V_140 * V_141 ;
struct V_10 * V_11 ;
int V_134 ;
V_11 = F_85 ( V_25 , 0xfc6d , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_15 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_141 ) ) {
F_24 ( L_16 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_131 ;
}
V_141 = (struct V_140 * ) V_11 -> V_2 ;
F_90 ( L_17 ,
V_25 -> V_36 , V_141 -> V_37 , V_141 -> V_139 ) ;
V_134 = V_141 -> V_37 ;
if ( V_134 == 0 )
* V_139 = V_141 -> V_139 ;
F_3 ( V_11 ) ;
return V_134 ;
}
static int F_91 ( struct V_34 * V_25 , T_4 V_142 ,
const struct V_143 * V_144 ,
unsigned char * * V_145 )
{
const T_3 V_146 [] = { 0x51 , 0x04 , 0xfd , 0x77 } ;
struct V_147 * V_148 ;
unsigned char * V_51 ;
int V_64 , V_134 , V_13 ;
T_5 V_149 ;
T_3 V_150 , V_68 , V_2 , V_141 = 0 ;
int V_151 = - 1 ;
const unsigned char * V_152 , * V_153 ;
const unsigned char * V_154 , * V_155 ;
T_6 V_156 = 0 ;
T_4 V_157 , V_158 ;
const T_4 V_159 [] = {
V_160 ,
V_161 ,
V_162 ,
V_163
} ;
V_134 = F_89 ( V_25 , & V_141 ) ;
if ( V_134 )
return - F_88 ( V_134 ) ;
V_149 = sizeof( struct V_147 ) + sizeof( V_146 ) + 3 ;
if ( V_144 -> V_53 < V_149 )
return - V_164 ;
V_152 = V_144 -> V_2 + V_144 -> V_53 - sizeof( V_146 ) ;
if ( memcmp ( V_152 , V_146 , sizeof( V_146 ) ) != 0 ) {
F_24 ( L_18 , V_25 -> V_36 ) ;
return - V_164 ;
}
while ( V_152 >= V_144 -> V_2 + ( sizeof( struct V_147 ) + 3 ) ) {
V_150 = * -- V_152 ;
V_68 = * -- V_152 ;
V_2 = * -- V_152 ;
F_22 ( L_19 , V_150 , V_68 , V_2 ) ;
if ( V_150 == 0xff )
break;
if ( V_68 == 0 ) {
F_24 ( L_20 ,
V_25 -> V_36 ) ;
return - V_164 ;
}
if ( V_150 == 0 && V_68 == 1 ) {
V_151 = V_2 ;
break;
}
V_152 -= V_68 ;
}
if ( V_151 < 0 ) {
F_24 ( L_21 , V_25 -> V_36 ) ;
return - V_164 ;
}
if ( V_151 >= F_92 ( V_159 ) ) {
F_24 ( L_22 , V_25 -> V_36 , V_151 ) ;
return - V_164 ;
}
if ( V_142 != V_159 [ V_151 ] ) {
F_24 ( L_23 , V_25 -> V_36 ,
V_159 [ V_151 ] , V_142 ) ;
return - V_164 ;
}
V_148 = (struct V_147 * ) V_144 -> V_2 ;
if ( memcmp ( V_148 -> V_165 , V_166 , 8 ) != 0 ) {
F_24 ( L_24 , V_25 -> V_36 ) ;
return - V_164 ;
}
V_158 = F_31 ( V_148 -> V_158 ) ;
F_22 ( L_25 ,
F_93 ( V_148 -> V_167 ) , V_158 ) ;
V_149 += 8 * V_158 ;
if ( V_144 -> V_53 < V_149 )
return - V_164 ;
V_153 = V_144 -> V_2 + sizeof( struct V_147 ) ;
V_154 = V_153 + ( sizeof( T_4 ) * V_158 ) ;
V_155 = V_154 + ( sizeof( T_4 ) * V_158 ) ;
for ( V_64 = 0 ; V_64 < V_158 ; V_64 ++ ) {
T_4 V_168 = F_94 ( V_153 +
( V_64 * sizeof( T_4 ) ) ) ;
if ( V_168 == V_141 + 1 ) {
V_157 = F_94 ( V_154 +
( V_64 * sizeof( T_4 ) ) ) ;
V_156 = F_95 ( V_155 +
( V_64 * sizeof( T_6 ) ) ) ;
break;
}
}
if ( ! V_156 ) {
F_24 ( L_26 ,
V_25 -> V_36 , V_141 ) ;
return - V_164 ;
}
F_22 ( L_27 , V_157 , V_156 , V_64 ) ;
V_149 = V_156 + V_157 ;
if ( V_144 -> V_53 < V_149 )
return - V_164 ;
V_13 = V_157 ;
V_51 = F_96 ( V_144 -> V_2 + V_156 , V_157 , V_86 ) ;
if ( ! V_51 )
return - V_16 ;
memcpy ( V_51 + V_157 - 4 , & V_148 -> V_167 , 4 ) ;
* V_145 = V_51 ;
return V_13 ;
}
static int F_97 ( struct V_34 * V_25 ,
const unsigned char * V_2 , int V_169 )
{
struct V_170 * V_171 ;
int V_172 = V_169 / V_173 + 1 ;
int V_174 = V_173 ;
int V_134 = 0 ;
int V_64 ;
V_171 = F_32 ( sizeof( struct V_170 ) , V_86 ) ;
if ( ! V_171 )
return - V_16 ;
for ( V_64 = 0 ; V_64 < V_172 ; V_64 ++ ) {
struct V_175 * V_176 ;
struct V_10 * V_11 ;
F_22 ( L_28 , V_64 , V_172 ) ;
V_171 -> V_177 = V_64 ;
if ( V_64 == ( V_172 - 1 ) ) {
V_171 -> V_177 |= 0x80 ;
V_174 = V_169 % V_173 ;
}
memcpy ( V_171 -> V_2 , V_2 , V_174 ) ;
V_11 = F_85 ( V_25 , 0xfc20 , V_174 + 1 , V_171 ,
V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_29 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
V_134 = - F_74 ( V_11 ) ;
goto V_178;
}
if ( V_11 -> V_13 != sizeof( * V_176 ) ) {
F_24 ( L_30 ,
V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
V_134 = - V_131 ;
goto V_178;
}
V_176 = (struct V_175 * ) V_11 -> V_2 ;
if ( V_176 -> V_37 != 0 ) {
F_3 ( V_11 ) ;
V_134 = F_88 ( V_176 -> V_37 ) ;
goto V_178;
}
F_3 ( V_11 ) ;
V_2 += V_173 ;
}
V_178:
F_45 ( V_171 ) ;
return V_134 ;
}
static int F_98 ( struct V_34 * V_25 )
{
struct V_1 * V_2 = F_99 ( & V_25 -> V_75 ) ;
struct V_179 * V_46 = F_100 ( V_2 -> V_84 ) ;
const struct V_143 * V_144 ;
int V_134 ;
F_90 ( L_31 , V_25 -> V_36 ) ;
V_134 = F_101 ( & V_144 , L_32 , & V_46 -> V_75 ) ;
if ( V_134 < 0 ) {
F_24 ( L_33 , V_25 -> V_36 ) ;
return V_134 ;
}
if ( V_144 -> V_53 < 8 ) {
V_134 = - V_164 ;
goto V_178;
}
if ( ! memcmp ( V_144 -> V_2 , V_166 , 8 ) ) {
F_24 ( L_34 , V_25 -> V_36 ) ;
V_134 = - V_164 ;
goto V_178;
}
V_134 = F_97 ( V_25 , V_144 -> V_2 , V_144 -> V_53 ) ;
V_178:
F_102 ( V_144 ) ;
return V_134 ;
}
static int F_103 ( struct V_34 * V_25 , T_4 V_142 ,
const char * V_180 )
{
struct V_1 * V_2 = F_99 ( & V_25 -> V_75 ) ;
struct V_179 * V_46 = F_100 ( V_2 -> V_84 ) ;
unsigned char * V_181 = NULL ;
const struct V_143 * V_144 ;
int V_134 ;
F_90 ( L_35 , V_25 -> V_36 , V_180 ) ;
V_134 = F_101 ( & V_144 , V_180 , & V_46 -> V_75 ) ;
if ( V_134 < 0 ) {
F_24 ( L_36 , V_25 -> V_36 , V_180 ) ;
return V_134 ;
}
V_134 = F_91 ( V_25 , V_142 , V_144 , & V_181 ) ;
if ( V_134 < 0 )
goto V_178;
V_134 = F_97 ( V_25 , V_181 , V_134 ) ;
F_45 ( V_181 ) ;
if ( V_134 < 0 )
goto V_178;
V_178:
F_102 ( V_144 ) ;
return V_134 ;
}
static int F_104 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
struct V_130 * V_182 ;
T_4 V_142 ;
V_11 = F_84 ( V_25 ) ;
if ( F_73 ( V_11 ) )
return - F_74 ( V_11 ) ;
V_182 = (struct V_130 * ) V_11 -> V_2 ;
F_90 ( L_37
L_38 , V_25 -> V_36 , V_182 -> V_183 , V_182 -> V_184 ,
V_182 -> V_185 , V_182 -> V_142 ) ;
V_142 = F_31 ( V_182 -> V_142 ) ;
F_3 ( V_11 ) ;
switch ( V_142 ) {
case V_160 :
case V_186 :
return F_98 ( V_25 ) ;
case V_161 :
return F_103 ( V_25 , V_142 ,
L_39 ) ;
case V_162 :
return F_103 ( V_25 , V_142 ,
L_40 ) ;
case V_163 :
return F_103 ( V_25 , V_142 ,
L_41 ) ;
default:
F_90 ( L_42 ) ;
return 0 ;
}
}
static const struct V_143 * F_105 ( struct V_34 * V_25 ,
struct V_187 * V_188 )
{
const struct V_143 * V_144 ;
char V_189 [ 64 ] ;
int V_134 ;
snprintf ( V_189 , sizeof( V_189 ) ,
L_43 ,
V_188 -> V_190 , V_188 -> V_191 , V_188 -> V_192 ,
V_188 -> V_193 , V_188 -> V_194 , V_188 -> V_195 ,
V_188 -> V_196 , V_188 -> V_197 ) ;
V_134 = F_101 ( & V_144 , V_189 , & V_25 -> V_75 ) ;
if ( V_134 < 0 ) {
if ( V_134 == - V_164 ) {
F_24 ( L_44 ,
V_25 -> V_36 , V_134 ) ;
return NULL ;
}
F_24 ( L_45 ,
V_25 -> V_36 , V_189 , V_134 ) ;
snprintf ( V_189 , sizeof( V_189 ) , L_46 ,
V_188 -> V_190 , V_188 -> V_191 ) ;
if ( F_101 ( & V_144 , V_189 , & V_25 -> V_75 ) < 0 ) {
F_24 ( L_47 ,
V_25 -> V_36 , V_189 ) ;
return NULL ;
}
}
F_90 ( L_48 , V_25 -> V_36 , V_189 ) ;
return V_144 ;
}
static int F_106 ( struct V_34 * V_25 ,
const struct V_143 * V_144 ,
const T_3 * * V_198 , int * V_199 )
{
struct V_10 * V_11 ;
struct V_200 * V_201 ;
const T_3 * V_202 ;
struct F_11 * V_111 = NULL ;
const T_3 * V_203 = NULL ;
int V_204 = V_144 -> V_53 - ( * V_198 - V_144 -> V_2 ) ;
if ( V_204 > V_205 && * V_198 [ 0 ] != 0x01 ) {
F_24 ( L_49 , V_25 -> V_36 ) ;
return - V_164 ;
}
( * V_198 ) ++ ;
V_204 -- ;
V_201 = (struct V_200 * ) ( * V_198 ) ;
* V_198 += sizeof( * V_201 ) ;
V_204 -= sizeof( * V_201 ) ;
if ( V_204 < V_201 -> V_22 ) {
F_24 ( L_50 , V_25 -> V_36 ) ;
return - V_206 ;
}
if ( * V_199 && F_31 ( V_201 -> V_150 ) == 0xfc8e )
* V_199 = 0 ;
V_202 = * V_198 ;
* V_198 += V_201 -> V_22 ;
V_204 -= V_201 -> V_22 ;
while ( V_204 > V_20 && * V_198 [ 0 ] == 0x02 ) {
( * V_198 ) ++ ;
V_204 -- ;
V_111 = (struct F_11 * ) ( * V_198 ) ;
* V_198 += sizeof( * V_111 ) ;
V_204 -= sizeof( * V_111 ) ;
if ( V_204 < V_111 -> V_22 ) {
F_24 ( L_51 ,
V_25 -> V_36 ) ;
return - V_206 ;
}
V_203 = * V_198 ;
* V_198 += V_111 -> V_22 ;
V_204 -= V_111 -> V_22 ;
}
if ( ! V_111 || ! V_203 || V_204 < 0 ) {
F_24 ( L_52 , V_25 -> V_36 ) ;
return - V_206 ;
}
V_11 = F_107 ( V_25 , F_31 ( V_201 -> V_150 ) , V_201 -> V_22 ,
V_202 , V_111 -> V_111 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_53 ,
V_25 -> V_36 , V_201 -> V_150 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != V_111 -> V_22 ) {
F_24 ( L_54 , V_25 -> V_36 ,
F_31 ( V_201 -> V_150 ) ) ;
F_3 ( V_11 ) ;
return - V_206 ;
}
if ( memcmp ( V_11 -> V_2 , V_203 , V_111 -> V_22 ) ) {
F_24 ( L_55 ,
V_25 -> V_36 , F_31 ( V_201 -> V_150 ) ) ;
F_3 ( V_11 ) ;
return - V_206 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_108 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
const struct V_143 * V_144 ;
const T_3 * V_198 ;
int V_199 ;
struct V_187 * V_188 ;
const T_3 V_207 [] = { 0x01 , 0x00 } ;
const T_3 V_208 [] = { 0x00 , 0x00 } ;
const T_3 V_209 [] = { 0x00 , 0x01 } ;
const T_3 V_210 [] = { 0x00 , 0x02 } ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_85 ( V_25 , V_211 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_56 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
V_11 = F_85 ( V_25 , 0xfc05 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_57 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_188 ) ) {
F_24 ( L_58 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_131 ;
}
V_188 = (struct V_187 * ) V_11 -> V_2 ;
if ( V_188 -> V_37 ) {
F_24 ( L_59 , V_25 -> V_36 ,
V_188 -> V_37 ) ;
F_3 ( V_11 ) ;
return - F_88 ( V_188 -> V_37 ) ;
}
F_90 ( L_60 ,
V_25 -> V_36 , V_188 -> V_190 , V_188 -> V_191 ,
V_188 -> V_192 , V_188 -> V_193 , V_188 -> V_194 ,
V_188 -> V_195 , V_188 -> V_196 , V_188 -> V_197 ,
V_188 -> V_212 ) ;
if ( V_188 -> V_212 ) {
F_90 ( L_61 ,
V_25 -> V_36 , V_188 -> V_212 ) ;
F_3 ( V_11 ) ;
F_109 ( V_25 ) ;
return 0 ;
}
V_144 = F_105 ( V_25 , V_188 ) ;
if ( ! V_144 ) {
F_3 ( V_11 ) ;
F_109 ( V_25 ) ;
return 0 ;
}
V_198 = V_144 -> V_2 ;
V_11 = F_85 ( V_25 , 0xfc11 , 2 , V_207 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_62 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
F_102 ( V_144 ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_2 [ 0 ] ) {
T_3 V_213 = V_11 -> V_2 [ 0 ] ;
F_24 ( L_63 ,
V_25 -> V_36 , V_213 ) ;
F_3 ( V_11 ) ;
F_102 ( V_144 ) ;
return - F_88 ( V_213 ) ;
}
F_3 ( V_11 ) ;
V_199 = 1 ;
while ( V_144 -> V_53 > V_198 - V_144 -> V_2 ) {
int V_134 ;
V_134 = F_106 ( V_25 , V_144 , & V_198 ,
& V_199 ) ;
if ( V_134 < 0 )
goto V_214;
}
F_102 ( V_144 ) ;
if ( V_199 )
goto V_215;
V_11 = F_85 ( V_25 , 0xfc11 , sizeof( V_210 ) ,
V_210 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_64 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_90 ( L_65 ,
V_25 -> V_36 ) ;
F_109 ( V_25 ) ;
return 0 ;
V_215:
V_11 = F_85 ( V_25 , 0xfc11 , sizeof( V_208 ) , V_208 ,
V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_64 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_90 ( L_66 , V_25 -> V_36 ) ;
F_109 ( V_25 ) ;
return 0 ;
V_214:
F_102 ( V_144 ) ;
V_11 = F_85 ( V_25 , 0xfc11 , sizeof( V_209 ) ,
V_209 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_64 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_90 ( L_67 ,
V_25 -> V_36 ) ;
F_109 ( V_25 ) ;
return 0 ;
}
static int F_110 ( struct V_34 * V_25 , T_7 V_150 )
{
struct V_10 * V_11 ;
struct F_11 * V_216 ;
struct V_217 * V_111 ;
V_11 = F_7 ( sizeof( * V_216 ) + sizeof( * V_111 ) + 1 , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_216 = (struct F_11 * ) F_10 ( V_11 , sizeof( * V_216 ) ) ;
V_216 -> V_111 = V_218 ;
V_216 -> V_22 = sizeof( * V_111 ) + 1 ;
V_111 = (struct V_217 * ) F_10 ( V_11 , sizeof( * V_111 ) ) ;
V_111 -> V_219 = 0x01 ;
V_111 -> V_150 = F_111 ( V_150 ) ;
* F_10 ( V_11 , 1 ) = 0x00 ;
F_8 ( V_11 ) -> V_17 = V_18 ;
return F_17 ( V_25 , V_11 ) ;
}
static int F_112 ( struct V_1 * V_2 , void * V_8 ,
int V_9 )
{
if ( F_23 ( V_220 , & V_2 -> V_3 ) )
return F_5 ( V_2 , V_8 , V_9 ) ;
return F_14 ( V_2 , V_8 , V_9 ) ;
}
static void F_113 ( struct V_1 * V_2 , const void * V_221 ,
unsigned int V_13 )
{
const struct V_222 * V_111 = V_221 ;
if ( V_13 != sizeof( * V_111 ) )
return;
if ( F_56 ( V_223 , & V_2 -> V_3 ) ) {
F_114 () ;
F_115 ( & V_2 -> V_3 , V_223 ) ;
}
}
static void F_116 ( struct V_1 * V_2 ,
const void * V_221 , unsigned int V_13 )
{
const struct V_224 * V_111 = V_221 ;
if ( V_13 != sizeof( * V_111 ) )
return;
if ( V_111 -> V_225 )
F_51 ( V_226 , & V_2 -> V_3 ) ;
if ( F_56 ( V_227 , & V_2 -> V_3 ) &&
F_23 ( V_228 , & V_2 -> V_3 ) ) {
F_114 () ;
F_115 ( & V_2 -> V_3 , V_227 ) ;
}
}
static int F_117 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
if ( F_23 ( V_220 , & V_2 -> V_3 ) ) {
struct F_11 * V_216 = ( void * ) V_11 -> V_2 ;
if ( V_11 -> V_13 > V_20 && V_216 -> V_111 == 0xff &&
V_216 -> V_22 > 0 ) {
const void * V_221 = V_11 -> V_2 + V_20 + 1 ;
unsigned int V_13 = V_11 -> V_13 - V_20 - 1 ;
switch ( V_11 -> V_2 [ 2 ] ) {
case 0x02 :
F_113 ( V_2 , V_221 , V_13 ) ;
break;
case 0x06 :
F_116 ( V_2 , V_221 , V_13 ) ;
break;
}
}
}
return F_17 ( V_25 , V_11 ) ;
}
static int F_118 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
return - V_105 ;
switch ( F_8 ( V_11 ) -> V_17 ) {
case V_106 :
if ( F_23 ( V_220 , & V_2 -> V_3 ) ) {
struct V_200 * V_201 = ( void * ) V_11 -> V_2 ;
T_7 V_150 = F_31 ( V_201 -> V_150 ) ;
if ( V_150 == 0xfc09 )
V_33 = F_65 ( V_25 , V_11 ) ;
else
V_33 = F_60 ( V_25 , V_11 ) ;
if ( V_150 == 0xfc01 )
F_110 ( V_25 , V_150 ) ;
} else {
V_33 = F_60 ( V_25 , V_11 ) ;
}
if ( F_73 ( V_33 ) )
return F_74 ( V_33 ) ;
V_25 -> V_40 . V_107 ++ ;
return F_70 ( V_25 , V_33 ) ;
case V_27 :
V_33 = F_65 ( V_25 , V_11 ) ;
if ( F_73 ( V_33 ) )
return F_74 ( V_33 ) ;
V_25 -> V_40 . V_108 ++ ;
return F_70 ( V_25 , V_33 ) ;
case V_31 :
if ( F_75 ( V_25 , V_109 ) < 1 )
return - V_49 ;
V_33 = F_67 ( V_25 , V_11 ) ;
if ( F_73 ( V_33 ) )
return F_74 ( V_33 ) ;
V_25 -> V_40 . V_110 ++ ;
return F_69 ( V_25 , V_33 ) ;
}
return - V_23 ;
}
static int F_119 ( struct V_34 * V_25 , T_3 V_229 ,
T_6 V_22 , const void * V_230 )
{
while ( V_22 > 0 ) {
struct V_10 * V_11 ;
T_3 V_202 [ 253 ] , V_231 = ( V_22 > 252 ) ? 252 : V_22 ;
V_202 [ 0 ] = V_229 ;
memcpy ( V_202 + 1 , V_230 , V_231 ) ;
V_11 = F_85 ( V_25 , 0xfc09 , V_231 + 1 ,
V_202 , V_129 ) ;
if ( F_73 ( V_11 ) )
return F_74 ( V_11 ) ;
F_3 ( V_11 ) ;
V_22 -= V_231 ;
V_230 += V_231 ;
}
return 0 ;
}
static void F_120 ( struct V_34 * V_25 ,
struct V_187 * V_188 )
{
const char * V_232 ;
switch ( V_188 -> V_193 ) {
case 0x06 :
V_232 = L_68 ;
break;
case 0x23 :
V_232 = L_69 ;
break;
default:
return;
}
F_90 ( L_70 , V_25 -> V_36 ,
V_232 , V_188 -> V_194 >> 4 , V_188 -> V_194 & 0x0f ,
V_188 -> V_195 , V_188 -> V_196 , 2000 + V_188 -> V_197 ) ;
}
static int F_121 ( struct V_34 * V_25 )
{
static const T_3 V_233 [] = { 0x00 , 0x01 , 0x00 , 0x01 ,
0x00 , 0x08 , 0x04 , 0x00 } ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_10 * V_11 ;
struct V_187 * V_188 ;
struct V_234 * V_235 ;
const struct V_143 * V_144 ;
const T_3 * V_198 ;
char V_189 [ 64 ] ;
T_8 V_236 , V_237 , V_238 ;
unsigned long long V_239 ;
int V_12 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_236 = F_122 () ;
V_11 = F_85 ( V_25 , 0xfc05 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_71 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_188 ) ) {
F_24 ( L_72 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_23 ;
}
V_188 = (struct V_187 * ) V_11 -> V_2 ;
if ( V_188 -> V_37 ) {
F_24 ( L_73 ,
V_25 -> V_36 , V_188 -> V_37 ) ;
V_12 = - F_88 ( V_188 -> V_37 ) ;
F_3 ( V_11 ) ;
return V_12 ;
}
if ( V_188 -> V_190 != 0x37 ) {
F_24 ( L_74 ,
V_25 -> V_36 , V_188 -> V_190 ) ;
F_3 ( V_11 ) ;
return - V_164 ;
}
if ( V_188 -> V_191 != 0x0b ) {
F_24 ( L_75 ,
V_25 -> V_36 , V_188 -> V_191 ) ;
F_3 ( V_11 ) ;
return - V_164 ;
}
F_120 ( V_25 , V_188 ) ;
if ( V_188 -> V_193 == 0x23 ) {
F_3 ( V_11 ) ;
F_53 ( V_220 , & V_2 -> V_3 ) ;
F_109 ( V_25 ) ;
return 0 ;
}
if ( V_188 -> V_193 != 0x06 ) {
F_24 ( L_76 ,
V_25 -> V_36 , V_188 -> V_193 ) ;
F_3 ( V_11 ) ;
return - V_49 ;
}
F_3 ( V_11 ) ;
V_11 = F_85 ( V_25 , 0xfc0d , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_77 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_235 ) ) {
F_24 ( L_78 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_23 ;
}
V_235 = (struct V_234 * ) V_11 -> V_2 ;
if ( V_235 -> V_37 ) {
F_24 ( L_79 ,
V_25 -> V_36 , V_235 -> V_37 ) ;
V_12 = - F_88 ( V_235 -> V_37 ) ;
F_3 ( V_11 ) ;
return V_12 ;
}
F_90 ( L_80 , V_25 -> V_36 ,
F_31 ( V_235 -> V_240 ) ) ;
F_90 ( L_81 , V_25 -> V_36 ,
V_235 -> V_241 ? L_82 : L_83 ) ;
F_90 ( L_84 , V_25 -> V_36 ,
V_235 -> V_242 , V_235 -> V_243 ,
2000 + V_235 -> V_244 ) ;
if ( V_235 -> V_245 != 0x00 ) {
F_24 ( L_85 ,
V_25 -> V_36 , V_235 -> V_245 ) ;
F_3 ( V_11 ) ;
return - V_164 ;
}
if ( ! F_123 ( & V_235 -> V_246 , V_247 ) ) {
F_90 ( L_86 , V_25 -> V_36 ) ;
F_51 ( V_248 , & V_25 -> V_137 ) ;
}
snprintf ( V_189 , sizeof( V_189 ) , L_87 ,
F_31 ( V_235 -> V_240 ) ) ;
V_12 = F_101 ( & V_144 , V_189 , & V_25 -> V_75 ) ;
if ( V_12 < 0 ) {
F_24 ( L_88 ,
V_25 -> V_36 , V_12 ) ;
F_3 ( V_11 ) ;
return V_12 ;
}
F_90 ( L_89 , V_25 -> V_36 , V_189 ) ;
F_3 ( V_11 ) ;
if ( V_144 -> V_53 < 644 ) {
F_24 ( L_90 ,
V_25 -> V_36 , V_144 -> V_53 ) ;
V_12 = - V_249 ;
goto V_76;
}
F_51 ( V_227 , & V_2 -> V_3 ) ;
V_12 = F_119 ( V_25 , 0x00 , 128 , V_144 -> V_2 ) ;
if ( V_12 < 0 ) {
F_24 ( L_91 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_12 = F_119 ( V_25 , 0x03 , 256 , V_144 -> V_2 + 128 ) ;
if ( V_12 < 0 ) {
F_24 ( L_92 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_12 = F_119 ( V_25 , 0x02 , 256 , V_144 -> V_2 + 388 ) ;
if ( V_12 < 0 ) {
F_24 ( L_93 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_198 = V_144 -> V_2 + 644 ;
while ( V_198 - V_144 -> V_2 < V_144 -> V_53 ) {
struct V_200 * V_201 = ( void * ) V_198 ;
T_3 V_250 ;
V_250 = sizeof( * V_201 ) + V_201 -> V_22 ;
V_12 = F_119 ( V_25 , 0x01 , V_250 , V_198 ) ;
if ( V_12 < 0 ) {
F_24 ( L_94 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_198 += V_250 ;
}
F_51 ( V_228 , & V_2 -> V_3 ) ;
F_90 ( L_95 , V_25 -> V_36 ) ;
V_12 = F_124 ( & V_2 -> V_3 , V_227 ,
V_251 ,
F_125 ( 5000 ) ) ;
if ( V_12 == 1 ) {
F_24 ( L_96 , V_25 -> V_36 ) ;
V_12 = - V_252 ;
goto V_76;
}
if ( V_12 ) {
F_24 ( L_97 , V_25 -> V_36 ) ;
V_12 = - V_253 ;
goto V_76;
}
if ( F_23 ( V_226 , & V_2 -> V_3 ) ) {
F_24 ( L_98 , V_25 -> V_36 ) ;
V_12 = - V_254 ;
goto V_76;
}
V_238 = F_122 () ;
V_237 = F_126 ( V_238 , V_236 ) ;
V_239 = ( unsigned long long ) F_127 ( V_237 ) >> 10 ;
F_90 ( L_99 , V_25 -> V_36 , V_239 ) ;
V_76:
F_102 ( V_144 ) ;
if ( V_12 < 0 )
return V_12 ;
V_236 = F_122 () ;
F_51 ( V_223 , & V_2 -> V_3 ) ;
V_11 = F_85 ( V_25 , 0xfc01 , sizeof( V_233 ) , V_233 ,
V_129 ) ;
if ( F_73 ( V_11 ) )
return F_74 ( V_11 ) ;
F_3 ( V_11 ) ;
F_90 ( L_100 , V_25 -> V_36 ) ;
V_12 = F_124 ( & V_2 -> V_3 , V_223 ,
V_251 ,
F_125 ( 1000 ) ) ;
if ( V_12 == 1 ) {
F_24 ( L_101 , V_25 -> V_36 ) ;
return - V_252 ;
}
if ( V_12 ) {
F_24 ( L_102 , V_25 -> V_36 ) ;
return - V_253 ;
}
V_238 = F_122 () ;
V_237 = F_126 ( V_238 , V_236 ) ;
V_239 = ( unsigned long long ) F_127 ( V_237 ) >> 10 ;
F_90 ( L_103 , V_25 -> V_36 , V_239 ) ;
F_53 ( V_220 , & V_2 -> V_3 ) ;
return 0 ;
}
static void F_128 ( struct V_34 * V_25 , T_3 V_255 )
{
struct V_10 * V_11 ;
T_3 type = 0x00 ;
F_24 ( L_104 , V_25 -> V_36 , V_255 ) ;
V_11 = F_85 ( V_25 , V_211 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_105 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return;
}
F_3 ( V_11 ) ;
V_11 = F_85 ( V_25 , 0xfc22 , 1 , & type , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_106 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return;
}
if ( V_11 -> V_13 != 13 ) {
F_24 ( L_107 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return;
}
if ( V_11 -> V_2 [ 0 ] != 0x00 ) {
F_24 ( L_108 ,
V_25 -> V_36 , V_11 -> V_2 [ 0 ] ) ;
F_3 ( V_11 ) ;
return;
}
F_24 ( L_109 , V_25 -> V_36 , ( char * ) ( V_11 -> V_2 + 1 ) ) ;
F_3 ( V_11 ) ;
}
static int F_129 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
long V_134 ;
V_11 = F_85 ( V_25 , 0xfc3f , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
V_134 = F_74 ( V_11 ) ;
F_24 ( L_110 ,
V_25 -> V_36 , V_134 ) ;
return V_134 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_130 ( struct V_34 * V_25 ,
const T_9 * V_256 )
{
struct V_10 * V_11 ;
T_3 V_51 [ 8 ] ;
long V_134 ;
V_51 [ 0 ] = 0xfe ;
V_51 [ 1 ] = sizeof( T_9 ) ;
memcpy ( V_51 + 2 , V_256 , sizeof( T_9 ) ) ;
V_11 = F_85 ( V_25 , 0xfc22 , sizeof( V_51 ) , V_51 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
V_134 = F_74 ( V_11 ) ;
F_24 ( L_111 ,
V_25 -> V_36 , V_134 ) ;
return V_134 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_131 ( struct V_34 * V_25 ,
const T_9 * V_256 )
{
struct V_10 * V_11 ;
T_3 V_51 [ 10 ] ;
long V_134 ;
V_51 [ 0 ] = 0x01 ;
V_51 [ 1 ] = 0x01 ;
V_51 [ 2 ] = 0x00 ;
V_51 [ 3 ] = sizeof( T_9 ) ;
memcpy ( V_51 + 4 , V_256 , sizeof( T_9 ) ) ;
V_11 = F_85 ( V_25 , 0xfc0b , sizeof( V_51 ) , V_51 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
V_134 = F_74 ( V_11 ) ;
F_24 ( L_112 ,
V_25 -> V_36 , V_134 ) ;
return V_134 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_132 ( struct V_34 * V_25 , T_3 V_257 ,
void * V_2 , T_4 V_53 )
{
struct V_1 * V_258 = F_21 ( V_25 ) ;
struct V_179 * V_46 = V_258 -> V_46 ;
int V_52 , V_12 ;
T_3 * V_51 ;
V_51 = F_32 ( V_53 , V_86 ) ;
if ( ! V_51 )
return - V_16 ;
V_52 = F_133 ( V_46 , 0 ) ;
V_12 = F_134 ( V_46 , V_52 , V_257 , V_259 | V_260 ,
0 , 0 , V_51 , V_53 , V_261 ) ;
if ( V_12 < 0 ) {
F_24 ( L_113 , V_25 -> V_36 , V_12 ) ;
goto V_76;
}
memcpy ( V_2 , V_51 , V_53 ) ;
V_76:
F_45 ( V_51 ) ;
return V_12 ;
}
static int F_135 ( struct V_34 * V_25 ,
const struct V_143 * V_143 ,
T_5 V_262 )
{
struct V_1 * V_258 = F_21 ( V_25 ) ;
struct V_179 * V_46 = V_258 -> V_46 ;
T_5 V_9 , V_53 , V_263 = 0 ;
int V_52 , V_13 , V_12 ;
T_3 * V_51 ;
V_51 = F_32 ( V_264 , V_86 ) ;
if ( ! V_51 )
return - V_16 ;
V_9 = V_143 -> V_53 ;
V_53 = F_9 ( T_5 , V_9 , V_262 ) ;
memcpy ( V_51 , V_143 -> V_2 , V_53 ) ;
V_52 = F_63 ( V_46 , 0 ) ;
V_12 = F_134 ( V_46 , V_52 , V_265 , V_259 ,
0 , 0 , V_51 , V_53 , V_261 ) ;
if ( V_12 < 0 ) {
F_24 ( L_114 , V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_263 += V_53 ;
V_9 -= V_53 ;
while ( V_9 ) {
V_53 = F_9 ( T_5 , V_9 , V_264 ) ;
memcpy ( V_51 , V_143 -> V_2 + V_263 , V_53 ) ;
V_52 = F_66 ( V_46 , 0x02 ) ;
V_12 = F_136 ( V_46 , V_52 , V_51 , V_53 , & V_13 ,
V_266 ) ;
if ( V_12 < 0 ) {
F_24 ( L_115 ,
V_25 -> V_36 , V_263 , V_143 -> V_53 , V_12 ) ;
break;
}
if ( V_53 != V_13 ) {
F_24 ( L_116 , V_25 -> V_36 ) ;
V_12 = - V_23 ;
break;
}
V_263 += V_53 ;
V_9 -= V_53 ;
}
V_76:
F_45 ( V_51 ) ;
return V_12 ;
}
static int F_137 ( struct V_34 * V_25 ,
struct V_267 * V_188 ,
const struct V_268 * V_269 )
{
struct V_270 * V_271 ;
const struct V_143 * V_144 ;
T_6 V_272 , V_273 ;
T_4 V_274 , V_275 ;
char V_189 [ 64 ] ;
int V_12 ;
V_272 = F_93 ( V_188 -> V_141 ) ;
V_273 = F_93 ( V_188 -> V_276 ) ;
snprintf ( V_189 , sizeof( V_189 ) , L_117 , V_272 ) ;
V_12 = F_101 ( & V_144 , V_189 , & V_25 -> V_75 ) ;
if ( V_12 ) {
F_24 ( L_118 ,
V_25 -> V_36 , V_189 , V_12 ) ;
return V_12 ;
}
F_90 ( L_119 , V_25 -> V_36 , V_189 ) ;
V_271 = (struct V_270 * ) ( V_144 -> V_2 + V_269 -> V_277 ) ;
V_274 = F_31 ( V_271 -> V_141 ) ;
V_275 = F_31 ( V_271 -> V_276 ) ;
F_90 ( L_120
L_121 , V_25 -> V_36 , V_274 , V_275 , V_272 ,
V_273 ) ;
if ( V_274 != V_272 || V_275 <= V_273 ) {
F_24 ( L_122 ,
V_25 -> V_36 ) ;
V_12 = - V_164 ;
goto V_76;
}
V_12 = F_135 ( V_25 , V_144 , V_269 -> V_278 ) ;
V_76:
F_102 ( V_144 ) ;
return V_12 ;
}
static int F_138 ( struct V_34 * V_25 ,
struct V_267 * V_188 ,
const struct V_268 * V_269 )
{
const struct V_143 * V_144 ;
char V_189 [ 64 ] ;
int V_12 ;
snprintf ( V_189 , sizeof( V_189 ) , L_123 ,
F_93 ( V_188 -> V_141 ) ) ;
V_12 = F_101 ( & V_144 , V_189 , & V_25 -> V_75 ) ;
if ( V_12 ) {
F_24 ( L_124 ,
V_25 -> V_36 , V_189 , V_12 ) ;
return V_12 ;
}
F_90 ( L_125 , V_25 -> V_36 , V_189 ) ;
V_12 = F_135 ( V_25 , V_144 , V_269 -> V_279 ) ;
F_102 ( V_144 ) ;
return V_12 ;
}
static int F_139 ( struct V_34 * V_25 )
{
const struct V_268 * V_269 = NULL ;
struct V_267 V_188 ;
T_6 V_272 ;
T_3 V_37 ;
int V_64 , V_12 ;
V_12 = F_132 ( V_25 , V_280 , & V_188 ,
sizeof( V_188 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_272 = F_93 ( V_188 . V_141 ) ;
for ( V_64 = 0 ; V_64 < F_92 ( V_281 ) ; V_64 ++ ) {
if ( V_272 == V_281 [ V_64 ] . V_141 )
V_269 = & V_281 [ V_64 ] ;
}
if ( ! V_269 ) {
F_24 ( L_126 , V_25 -> V_36 ,
V_272 ) ;
return - V_49 ;
}
V_12 = F_132 ( V_25 , V_282 , & V_37 ,
sizeof( V_37 ) ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_37 & V_283 ) ) {
V_12 = F_137 ( V_25 , & V_188 , V_269 ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( ! ( V_37 & V_284 ) ) {
V_12 = F_138 ( V_25 , & V_188 , V_269 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_140 ( struct V_114 * V_84 ,
const struct V_285 * V_286 )
{
struct V_116 * V_117 ;
struct V_1 * V_2 ;
struct V_34 * V_25 ;
int V_64 , V_12 ;
F_22 ( L_127 , V_84 , V_286 ) ;
if ( V_84 -> V_119 -> V_120 . V_287 != 0 )
return - V_49 ;
if ( ! V_286 -> V_288 ) {
const struct V_285 * V_289 ;
V_289 = F_141 ( V_84 , V_290 ) ;
if ( V_289 )
V_286 = V_289 ;
}
if ( V_286 -> V_288 == V_291 )
return - V_49 ;
if ( V_286 -> V_288 & V_292 ) {
struct V_179 * V_46 = F_100 ( V_84 ) ;
if ( F_31 ( V_46 -> V_293 . V_294 ) <= 0x0001 )
return - V_49 ;
}
V_2 = F_142 ( & V_84 -> V_75 , sizeof( * V_2 ) , V_86 ) ;
if ( ! V_2 )
return - V_16 ;
for ( V_64 = 0 ; V_64 < V_84 -> V_119 -> V_120 . V_121 ; V_64 ++ ) {
V_117 = & V_84 -> V_119 -> V_122 [ V_64 ] . V_120 ;
if ( ! V_2 -> V_54 && F_143 ( V_117 ) ) {
V_2 -> V_54 = V_117 ;
continue;
}
if ( ! V_2 -> V_101 && F_144 ( V_117 ) ) {
V_2 -> V_101 = V_117 ;
continue;
}
if ( ! V_2 -> V_63 && F_145 ( V_117 ) ) {
V_2 -> V_63 = V_117 ;
continue;
}
}
if ( ! V_2 -> V_54 || ! V_2 -> V_101 || ! V_2 -> V_63 )
return - V_49 ;
if ( V_286 -> V_288 & V_295 ) {
V_2 -> V_95 = V_296 | 0x01 ;
V_2 -> V_97 = 0x2b ;
} else {
V_2 -> V_95 = V_296 ;
V_2 -> V_97 = 0x00 ;
}
V_2 -> V_46 = F_100 ( V_84 ) ;
V_2 -> V_84 = V_84 ;
F_146 ( & V_2 -> V_88 , F_81 ) ;
F_146 ( & V_2 -> V_89 , F_83 ) ;
F_147 ( & V_2 -> V_90 ) ;
F_147 ( & V_2 -> V_91 ) ;
F_148 ( & V_2 -> V_80 ) ;
F_147 ( & V_2 -> V_47 ) ;
F_147 ( & V_2 -> V_62 ) ;
F_147 ( & V_2 -> V_70 ) ;
F_148 ( & V_2 -> V_4 ) ;
if ( V_286 -> V_288 & V_297 ) {
V_2 -> V_24 = F_117 ;
V_2 -> V_60 = F_112 ;
F_51 ( V_220 , & V_2 -> V_3 ) ;
} else {
V_2 -> V_24 = F_17 ;
V_2 -> V_60 = F_14 ;
}
V_25 = F_149 () ;
if ( ! V_25 )
return - V_16 ;
V_25 -> V_298 = V_299 ;
F_150 ( V_25 , V_2 ) ;
if ( V_286 -> V_288 & V_295 )
V_25 -> V_300 = V_301 ;
else
V_25 -> V_300 = V_302 ;
V_2 -> V_25 = V_25 ;
F_151 ( V_25 , & V_84 -> V_75 ) ;
V_25 -> V_303 = F_47 ;
V_25 -> V_304 = F_55 ;
V_25 -> V_305 = F_59 ;
V_25 -> V_306 = F_72 ;
V_25 -> V_307 = F_76 ;
if ( V_286 -> V_288 & V_308 )
V_25 -> V_309 = F_86 ;
#ifdef F_152
if ( V_286 -> V_288 & V_310 ) {
V_25 -> V_309 = V_311 ;
V_25 -> V_312 = V_313 ;
}
if ( V_286 -> V_288 & V_314 )
V_25 -> V_309 = V_315 ;
#endif
if ( V_286 -> V_288 & V_316 ) {
V_25 -> V_309 = F_108 ;
V_25 -> V_317 = F_129 ;
V_25 -> V_312 = V_318 ;
F_51 ( V_319 , & V_25 -> V_137 ) ;
F_51 ( V_320 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_297 ) {
V_25 -> V_306 = F_118 ;
V_25 -> V_309 = F_121 ;
V_25 -> V_321 = F_128 ;
V_25 -> V_312 = V_318 ;
F_51 ( V_319 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_322 )
V_25 -> V_312 = F_130 ;
if ( V_286 -> V_288 & V_323 ) {
F_51 ( V_324 , & V_25 -> V_137 ) ;
F_51 ( V_325 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_326 )
F_51 ( V_327 , & V_25 -> V_137 ) ;
if ( V_286 -> V_288 & V_292 ) {
V_25 -> V_312 = F_131 ;
F_51 ( V_320 , & V_25 -> V_137 ) ;
F_51 ( V_319 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_328 ) {
V_2 -> V_83 = F_139 ;
V_25 -> V_312 = F_131 ;
}
if ( V_286 -> V_288 & V_329 )
V_25 -> V_309 = F_104 ;
if ( V_286 -> V_288 & V_295 ) {
V_2 -> V_115 = NULL ;
} else {
V_2 -> V_115 = F_153 ( V_2 -> V_46 , 1 ) ;
}
if ( ! V_330 )
F_51 ( V_136 , & V_25 -> V_137 ) ;
if ( V_331 || V_286 -> V_288 & V_332 ) {
if ( ! V_333 )
F_51 ( V_334 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_335 )
V_2 -> V_115 = NULL ;
if ( V_286 -> V_288 & V_336 ) {
V_2 -> V_95 = V_259 ;
F_51 ( V_136 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_337 ) {
struct V_179 * V_46 = V_2 -> V_46 ;
T_4 V_294 = F_31 ( V_46 -> V_293 . V_294 ) ;
if ( V_294 < 0x117 )
F_51 ( V_136 , & V_25 -> V_137 ) ;
if ( V_294 <= 0x100 )
V_25 -> V_309 = F_87 ;
F_51 ( V_320 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_338 ) {
struct V_179 * V_46 = V_2 -> V_46 ;
if ( F_31 ( V_46 -> V_293 . V_294 ) > 0x997 )
F_51 ( V_327 , & V_25 -> V_137 ) ;
}
if ( V_286 -> V_288 & V_326 ) {
V_12 = F_78 ( V_2 -> V_46 , 0 , 0 ) ;
if ( V_12 < 0 ) {
F_24 ( L_128 , V_12 ) ;
F_154 ( V_25 ) ;
return V_12 ;
}
}
if ( V_2 -> V_115 ) {
V_12 = F_155 ( & V_339 ,
V_2 -> V_115 , V_2 ) ;
if ( V_12 < 0 ) {
F_154 ( V_25 ) ;
return V_12 ;
}
}
V_12 = F_156 ( V_25 ) ;
if ( V_12 < 0 ) {
F_154 ( V_25 ) ;
return V_12 ;
}
F_157 ( V_84 , V_2 ) ;
return 0 ;
}
static void F_158 ( struct V_114 * V_84 )
{
struct V_1 * V_2 = F_159 ( V_84 ) ;
struct V_34 * V_25 ;
F_22 ( L_129 , V_84 ) ;
if ( ! V_2 )
return;
V_25 = V_2 -> V_25 ;
F_157 ( V_2 -> V_84 , NULL ) ;
if ( V_2 -> V_115 )
F_157 ( V_2 -> V_115 , NULL ) ;
F_160 ( V_25 ) ;
if ( V_84 == V_2 -> V_115 )
F_161 ( & V_339 , V_2 -> V_84 ) ;
else if ( V_2 -> V_115 )
F_161 ( & V_339 , V_2 -> V_115 ) ;
F_154 ( V_25 ) ;
}
static int F_162 ( struct V_114 * V_84 , T_10 V_340 )
{
struct V_1 * V_2 = F_159 ( V_84 ) ;
F_22 ( L_129 , V_84 ) ;
if ( V_2 -> V_341 ++ )
return 0 ;
F_163 ( & V_2 -> V_80 ) ;
if ( ! ( F_164 ( V_340 ) && V_2 -> V_81 ) ) {
F_51 ( V_104 , & V_2 -> V_3 ) ;
F_165 ( & V_2 -> V_80 ) ;
} else {
F_165 ( & V_2 -> V_80 ) ;
V_2 -> V_341 -- ;
return - V_105 ;
}
F_57 ( & V_2 -> V_88 ) ;
F_54 ( V_2 ) ;
F_50 ( & V_2 -> V_91 ) ;
return 0 ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_33 * V_33 ;
int V_12 ;
while ( ( V_33 = F_167 ( & V_2 -> V_90 ) ) ) {
V_12 = F_27 ( V_33 , V_15 ) ;
if ( V_12 < 0 )
break;
V_2 -> V_81 ++ ;
}
F_58 ( & V_2 -> V_90 ) ;
}
static int F_168 ( struct V_114 * V_84 )
{
struct V_1 * V_2 = F_159 ( V_84 ) ;
struct V_34 * V_25 = V_2 -> V_25 ;
int V_12 = 0 ;
F_22 ( L_129 , V_84 ) ;
if ( -- V_2 -> V_341 )
return 0 ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
goto V_76;
if ( F_23 ( V_45 , & V_2 -> V_3 ) ) {
V_12 = F_29 ( V_25 , V_342 ) ;
if ( V_12 < 0 ) {
F_53 ( V_45 , & V_2 -> V_3 ) ;
goto V_87;
}
}
if ( F_23 ( V_61 , & V_2 -> V_3 ) ) {
V_12 = F_37 ( V_25 , V_342 ) ;
if ( V_12 < 0 ) {
F_53 ( V_61 , & V_2 -> V_3 ) ;
goto V_87;
}
F_37 ( V_25 , V_342 ) ;
}
if ( F_23 ( V_69 , & V_2 -> V_3 ) ) {
if ( F_42 ( V_25 , V_342 ) < 0 )
F_53 ( V_69 , & V_2 -> V_3 ) ;
else
F_42 ( V_25 , V_342 ) ;
}
F_163 ( & V_2 -> V_80 ) ;
F_166 ( V_2 ) ;
F_53 ( V_104 , & V_2 -> V_3 ) ;
F_165 ( & V_2 -> V_80 ) ;
F_71 ( & V_2 -> V_88 ) ;
return 0 ;
V_87:
F_58 ( & V_2 -> V_90 ) ;
V_76:
F_163 ( & V_2 -> V_80 ) ;
F_53 ( V_104 , & V_2 -> V_3 ) ;
F_165 ( & V_2 -> V_80 ) ;
return V_12 ;
}
