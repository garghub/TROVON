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
static int F_84 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
T_3 V_128 = 0x00 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_85 ( V_25 , 0xfc3b , 1 , & V_128 , V_129 ) ;
if ( F_73 ( V_11 ) )
F_24 ( L_12 , - F_74 ( V_11 ) ) ;
else
F_3 ( V_11 ) ;
return 0 ;
}
static int F_86 ( struct V_34 * V_25 )
{
struct V_130 * V_131 ;
struct V_10 * V_11 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_85 ( V_25 , V_132 , 0 , NULL ,
V_129 ) ;
if ( F_73 ( V_11 ) ) {
int V_12 = F_74 ( V_11 ) ;
F_24 ( L_13 , V_25 -> V_36 , V_12 ) ;
return V_12 ;
}
if ( V_11 -> V_13 != sizeof( struct V_130 ) ) {
F_24 ( L_14 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_133 ;
}
V_131 = (struct V_130 * ) V_11 -> V_2 ;
if ( F_31 ( V_131 -> V_134 ) != 10 ) {
F_53 ( V_135 , & V_25 -> V_136 ) ;
F_51 ( V_137 , & V_25 -> V_136 ) ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static const struct V_138 * F_87 ( struct V_34 * V_25 ,
struct V_139 * V_140 )
{
const struct V_138 * V_141 ;
char V_142 [ 64 ] ;
int V_143 ;
snprintf ( V_142 , sizeof( V_142 ) ,
L_15 ,
V_140 -> V_144 , V_140 -> V_145 , V_140 -> V_146 ,
V_140 -> V_147 , V_140 -> V_148 , V_140 -> V_149 ,
V_140 -> V_150 , V_140 -> V_151 ) ;
V_143 = F_88 ( & V_141 , V_142 , & V_25 -> V_75 ) ;
if ( V_143 < 0 ) {
if ( V_143 == - V_152 ) {
F_24 ( L_16 ,
V_25 -> V_36 , V_143 ) ;
return NULL ;
}
F_24 ( L_17 ,
V_25 -> V_36 , V_142 , V_143 ) ;
snprintf ( V_142 , sizeof( V_142 ) , L_18 ,
V_140 -> V_144 , V_140 -> V_145 ) ;
if ( F_88 ( & V_141 , V_142 , & V_25 -> V_75 ) < 0 ) {
F_24 ( L_19 ,
V_25 -> V_36 , V_142 ) ;
return NULL ;
}
}
F_89 ( L_20 , V_25 -> V_36 , V_142 ) ;
return V_141 ;
}
static int F_90 ( struct V_34 * V_25 ,
const struct V_138 * V_141 ,
const T_3 * * V_153 , int * V_154 )
{
struct V_10 * V_11 ;
struct V_155 * V_156 ;
const T_3 * V_157 ;
struct F_11 * V_111 = NULL ;
const T_3 * V_158 = NULL ;
int V_159 = V_141 -> V_53 - ( * V_153 - V_141 -> V_2 ) ;
if ( V_159 > V_160 && * V_153 [ 0 ] != 0x01 ) {
F_24 ( L_21 , V_25 -> V_36 ) ;
return - V_152 ;
}
( * V_153 ) ++ ;
V_159 -- ;
V_156 = (struct V_155 * ) ( * V_153 ) ;
* V_153 += sizeof( * V_156 ) ;
V_159 -= sizeof( * V_156 ) ;
if ( V_159 < V_156 -> V_22 ) {
F_24 ( L_22 , V_25 -> V_36 ) ;
return - V_161 ;
}
if ( * V_154 && F_31 ( V_156 -> V_162 ) == 0xfc8e )
* V_154 = 0 ;
V_157 = * V_153 ;
* V_153 += V_156 -> V_22 ;
V_159 -= V_156 -> V_22 ;
while ( V_159 > V_20 && * V_153 [ 0 ] == 0x02 ) {
( * V_153 ) ++ ;
V_159 -- ;
V_111 = (struct F_11 * ) ( * V_153 ) ;
* V_153 += sizeof( * V_111 ) ;
V_159 -= sizeof( * V_111 ) ;
if ( V_159 < V_111 -> V_22 ) {
F_24 ( L_23 ,
V_25 -> V_36 ) ;
return - V_161 ;
}
V_158 = * V_153 ;
* V_153 += V_111 -> V_22 ;
V_159 -= V_111 -> V_22 ;
}
if ( ! V_111 || ! V_158 || V_159 < 0 ) {
F_24 ( L_24 , V_25 -> V_36 ) ;
return - V_161 ;
}
V_11 = F_91 ( V_25 , F_31 ( V_156 -> V_162 ) , V_156 -> V_22 ,
V_157 , V_111 -> V_111 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_25 ,
V_25 -> V_36 , V_156 -> V_162 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != V_111 -> V_22 ) {
F_24 ( L_26 , V_25 -> V_36 ,
F_31 ( V_156 -> V_162 ) ) ;
F_3 ( V_11 ) ;
return - V_161 ;
}
if ( memcmp ( V_11 -> V_2 , V_158 , V_111 -> V_22 ) ) {
F_24 ( L_27 ,
V_25 -> V_36 , F_31 ( V_156 -> V_162 ) ) ;
F_3 ( V_11 ) ;
return - V_161 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_92 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
const struct V_138 * V_141 ;
const T_3 * V_153 ;
int V_154 ;
struct V_139 * V_140 ;
const T_3 V_163 [] = { 0x01 , 0x00 } ;
const T_3 V_164 [] = { 0x00 , 0x00 } ;
const T_3 V_165 [] = { 0x00 , 0x01 } ;
const T_3 V_166 [] = { 0x00 , 0x02 } ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_11 = F_85 ( V_25 , V_167 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_28 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
V_11 = F_85 ( V_25 , 0xfc05 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_29 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_140 ) ) {
F_24 ( L_30 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_133 ;
}
V_140 = (struct V_139 * ) V_11 -> V_2 ;
F_89 ( L_31 ,
V_25 -> V_36 , V_140 -> V_144 , V_140 -> V_145 ,
V_140 -> V_146 , V_140 -> V_147 , V_140 -> V_148 ,
V_140 -> V_149 , V_140 -> V_150 , V_140 -> V_151 ,
V_140 -> V_168 ) ;
if ( V_140 -> V_168 ) {
F_89 ( L_32 ,
V_25 -> V_36 , V_140 -> V_168 ) ;
F_3 ( V_11 ) ;
F_93 ( V_25 ) ;
return 0 ;
}
V_141 = F_87 ( V_25 , V_140 ) ;
if ( ! V_141 ) {
F_3 ( V_11 ) ;
F_93 ( V_25 ) ;
return 0 ;
}
V_153 = V_141 -> V_2 ;
F_3 ( V_11 ) ;
V_11 = F_85 ( V_25 , 0xfc11 , 2 , V_163 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_33 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
F_94 ( V_141 ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
V_154 = 1 ;
while ( V_141 -> V_53 > V_153 - V_141 -> V_2 ) {
int V_143 ;
V_143 = F_90 ( V_25 , V_141 , & V_153 ,
& V_154 ) ;
if ( V_143 < 0 )
goto V_169;
}
F_94 ( V_141 ) ;
if ( V_154 )
goto V_170;
V_11 = F_85 ( V_25 , 0xfc11 , sizeof( V_166 ) ,
V_166 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_34 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_89 ( L_35 ,
V_25 -> V_36 ) ;
F_93 ( V_25 ) ;
return 0 ;
V_170:
V_11 = F_85 ( V_25 , 0xfc11 , sizeof( V_164 ) , V_164 ,
V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_34 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_89 ( L_36 , V_25 -> V_36 ) ;
F_93 ( V_25 ) ;
return 0 ;
V_169:
F_94 ( V_141 ) ;
V_11 = F_85 ( V_25 , 0xfc11 , sizeof( V_165 ) ,
V_165 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_34 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
F_3 ( V_11 ) ;
F_89 ( L_37 ,
V_25 -> V_36 ) ;
F_93 ( V_25 ) ;
return 0 ;
}
static int F_95 ( struct V_34 * V_25 , T_4 V_162 )
{
struct V_10 * V_11 ;
struct F_11 * V_171 ;
struct V_172 * V_111 ;
V_11 = F_7 ( sizeof( * V_171 ) + sizeof( * V_111 ) + 1 , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_171 = (struct F_11 * ) F_10 ( V_11 , sizeof( * V_171 ) ) ;
V_171 -> V_111 = V_173 ;
V_171 -> V_22 = sizeof( * V_111 ) + 1 ;
V_111 = (struct V_172 * ) F_10 ( V_11 , sizeof( * V_111 ) ) ;
V_111 -> V_174 = 0x01 ;
V_111 -> V_162 = F_96 ( V_162 ) ;
* F_10 ( V_11 , 1 ) = 0x00 ;
F_8 ( V_11 ) -> V_17 = V_18 ;
return F_17 ( V_25 , V_11 ) ;
}
static int F_97 ( struct V_1 * V_2 , void * V_8 ,
int V_9 )
{
if ( F_23 ( V_175 , & V_2 -> V_3 ) )
return F_5 ( V_2 , V_8 , V_9 ) ;
return F_14 ( V_2 , V_8 , V_9 ) ;
}
static void F_98 ( struct V_1 * V_2 , const void * V_176 ,
unsigned int V_13 )
{
const struct V_177 * V_111 = V_176 ;
if ( V_13 != sizeof( * V_111 ) )
return;
if ( F_56 ( V_178 , & V_2 -> V_3 ) ) {
F_99 () ;
F_100 ( & V_2 -> V_3 , V_178 ) ;
}
}
static void F_101 ( struct V_1 * V_2 ,
const void * V_176 , unsigned int V_13 )
{
const struct V_179 * V_111 = V_176 ;
if ( V_13 != sizeof( * V_111 ) )
return;
if ( V_111 -> V_180 )
F_51 ( V_181 , & V_2 -> V_3 ) ;
if ( F_56 ( V_182 , & V_2 -> V_3 ) &&
F_23 ( V_183 , & V_2 -> V_3 ) ) {
F_99 () ;
F_100 ( & V_2 -> V_3 , V_182 ) ;
}
}
static int F_102 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
if ( F_23 ( V_175 , & V_2 -> V_3 ) ) {
struct F_11 * V_171 = ( void * ) V_11 -> V_2 ;
if ( V_11 -> V_13 > V_20 && V_171 -> V_111 == 0xff &&
V_171 -> V_22 > 0 ) {
const void * V_176 = V_11 -> V_2 + V_20 + 1 ;
unsigned int V_13 = V_11 -> V_13 - V_20 - 1 ;
switch ( V_11 -> V_2 [ 2 ] ) {
case 0x02 :
F_98 ( V_2 , V_176 , V_13 ) ;
break;
case 0x06 :
F_101 ( V_2 , V_176 , V_13 ) ;
break;
}
}
}
return F_17 ( V_25 , V_11 ) ;
}
static int F_103 ( struct V_34 * V_25 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_33 * V_33 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
return - V_105 ;
switch ( F_8 ( V_11 ) -> V_17 ) {
case V_106 :
if ( F_23 ( V_175 , & V_2 -> V_3 ) ) {
struct V_155 * V_156 = ( void * ) V_11 -> V_2 ;
T_4 V_162 = F_31 ( V_156 -> V_162 ) ;
if ( V_162 == 0xfc09 )
V_33 = F_65 ( V_25 , V_11 ) ;
else
V_33 = F_60 ( V_25 , V_11 ) ;
if ( V_162 == 0xfc01 )
F_95 ( V_25 , V_162 ) ;
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
static int F_104 ( struct V_34 * V_25 , T_3 V_184 ,
T_5 V_22 , const void * V_185 )
{
while ( V_22 > 0 ) {
struct V_10 * V_11 ;
T_3 V_157 [ 253 ] , V_186 = ( V_22 > 252 ) ? 252 : V_22 ;
V_157 [ 0 ] = V_184 ;
memcpy ( V_157 + 1 , V_185 , V_186 ) ;
V_11 = F_85 ( V_25 , 0xfc09 , V_186 + 1 ,
V_157 , V_129 ) ;
if ( F_73 ( V_11 ) )
return F_74 ( V_11 ) ;
F_3 ( V_11 ) ;
V_22 -= V_186 ;
V_185 += V_186 ;
}
return 0 ;
}
static void F_105 ( struct V_34 * V_25 ,
struct V_139 * V_140 )
{
const char * V_187 ;
switch ( V_140 -> V_147 ) {
case 0x06 :
V_187 = L_38 ;
break;
case 0x23 :
V_187 = L_39 ;
break;
default:
return;
}
F_89 ( L_40 , V_25 -> V_36 ,
V_187 , V_140 -> V_148 >> 4 , V_140 -> V_148 & 0x0f ,
V_140 -> V_149 , V_140 -> V_150 , 2000 + V_140 -> V_151 ) ;
}
static int F_106 ( struct V_34 * V_25 )
{
static const T_3 V_188 [] = { 0x00 , 0x01 , 0x00 , 0x01 ,
0x00 , 0x08 , 0x04 , 0x00 } ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_10 * V_11 ;
struct V_139 * V_140 ;
struct V_189 * V_190 ;
const struct V_138 * V_141 ;
const T_3 * V_153 ;
T_5 V_191 ;
char V_142 [ 64 ] ;
T_6 V_192 , V_193 , V_194 ;
unsigned long long V_195 ;
int V_12 ;
F_22 ( L_4 , V_25 -> V_36 ) ;
V_192 = F_107 () ;
V_11 = F_85 ( V_25 , 0xfc05 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_41 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_140 ) ) {
F_24 ( L_42 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_23 ;
}
V_140 = (struct V_139 * ) V_11 -> V_2 ;
if ( V_140 -> V_144 != 0x37 ) {
F_24 ( L_43 ,
V_25 -> V_36 , V_140 -> V_144 ) ;
F_3 ( V_11 ) ;
return - V_152 ;
}
if ( V_140 -> V_145 != 0x0b ) {
F_24 ( L_44 ,
V_25 -> V_36 , V_140 -> V_145 ) ;
F_3 ( V_11 ) ;
return - V_152 ;
}
F_105 ( V_25 , V_140 ) ;
if ( V_140 -> V_147 == 0x23 ) {
F_3 ( V_11 ) ;
F_53 ( V_175 , & V_2 -> V_3 ) ;
F_93 ( V_25 ) ;
return 0 ;
}
if ( V_140 -> V_147 != 0x06 ) {
F_24 ( L_45 ,
V_25 -> V_36 , V_140 -> V_147 ) ;
F_3 ( V_11 ) ;
return - V_49 ;
}
F_3 ( V_11 ) ;
V_11 = F_85 ( V_25 , 0xfc0d , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_46 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return F_74 ( V_11 ) ;
}
if ( V_11 -> V_13 != sizeof( * V_190 ) ) {
F_24 ( L_47 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return - V_23 ;
}
V_190 = (struct V_189 * ) V_11 -> V_2 ;
F_89 ( L_48 , V_25 -> V_36 ,
F_31 ( V_190 -> V_196 ) ) ;
F_89 ( L_49 , V_25 -> V_36 ,
V_190 -> V_197 ? L_50 : L_51 ) ;
F_89 ( L_52 , V_25 -> V_36 ,
V_190 -> V_198 , V_190 -> V_199 ,
2000 + V_190 -> V_200 ) ;
if ( V_190 -> V_201 != 0x00 ) {
F_24 ( L_53 ,
V_25 -> V_36 , V_190 -> V_201 ) ;
F_3 ( V_11 ) ;
return - V_152 ;
}
if ( ! F_108 ( & V_190 -> V_202 , V_203 ) ) {
F_89 ( L_54 , V_25 -> V_36 ) ;
F_51 ( V_204 , & V_25 -> V_136 ) ;
}
snprintf ( V_142 , sizeof( V_142 ) , L_55 ,
F_31 ( V_190 -> V_196 ) ) ;
V_12 = F_88 ( & V_141 , V_142 , & V_25 -> V_75 ) ;
if ( V_12 < 0 ) {
F_24 ( L_56 ,
V_25 -> V_36 , V_12 ) ;
F_3 ( V_11 ) ;
return V_12 ;
}
F_89 ( L_57 , V_25 -> V_36 , V_142 ) ;
snprintf ( V_142 , sizeof( V_142 ) , L_58 ,
F_31 ( V_190 -> V_196 ) ) ;
F_3 ( V_11 ) ;
if ( V_141 -> V_53 < 644 ) {
F_24 ( L_59 ,
V_25 -> V_36 , V_141 -> V_53 ) ;
V_12 = - V_205 ;
goto V_76;
}
F_51 ( V_182 , & V_2 -> V_3 ) ;
V_12 = F_104 ( V_25 , 0x00 , 128 , V_141 -> V_2 ) ;
if ( V_12 < 0 ) {
F_24 ( L_60 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_12 = F_104 ( V_25 , 0x03 , 256 , V_141 -> V_2 + 128 ) ;
if ( V_12 < 0 ) {
F_24 ( L_61 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_12 = F_104 ( V_25 , 0x02 , 256 , V_141 -> V_2 + 388 ) ;
if ( V_12 < 0 ) {
F_24 ( L_62 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_153 = V_141 -> V_2 + 644 ;
V_191 = 0 ;
while ( V_153 - V_141 -> V_2 < V_141 -> V_53 ) {
struct V_155 * V_156 = ( void * ) ( V_153 + V_191 ) ;
V_191 += sizeof( * V_156 ) + V_156 -> V_22 ;
if ( ! ( V_191 % 4 ) ) {
V_12 = F_104 ( V_25 , 0x01 , V_191 ,
V_153 ) ;
if ( V_12 < 0 ) {
F_24 ( L_63 ,
V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_153 += V_191 ;
V_191 = 0 ;
}
}
F_51 ( V_183 , & V_2 -> V_3 ) ;
F_89 ( L_64 , V_25 -> V_36 ) ;
V_12 = F_109 ( & V_2 -> V_3 , V_182 ,
V_206 ,
F_110 ( 5000 ) ) ;
if ( V_12 == 1 ) {
F_24 ( L_65 , V_25 -> V_36 ) ;
V_12 = - V_207 ;
goto V_76;
}
if ( V_12 ) {
F_24 ( L_66 , V_25 -> V_36 ) ;
V_12 = - V_208 ;
goto V_76;
}
if ( F_23 ( V_181 , & V_2 -> V_3 ) ) {
F_24 ( L_67 , V_25 -> V_36 ) ;
V_12 = - V_209 ;
goto V_76;
}
V_194 = F_107 () ;
V_193 = F_111 ( V_194 , V_192 ) ;
V_195 = ( unsigned long long ) F_112 ( V_193 ) >> 10 ;
F_89 ( L_68 , V_25 -> V_36 , V_195 ) ;
V_76:
F_94 ( V_141 ) ;
if ( V_12 < 0 )
return V_12 ;
V_192 = F_107 () ;
F_51 ( V_178 , & V_2 -> V_3 ) ;
V_11 = F_85 ( V_25 , 0xfc01 , sizeof( V_188 ) , V_188 ,
V_129 ) ;
if ( F_73 ( V_11 ) )
return F_74 ( V_11 ) ;
F_3 ( V_11 ) ;
F_89 ( L_69 , V_25 -> V_36 ) ;
V_12 = F_109 ( & V_2 -> V_3 , V_178 ,
V_206 ,
F_110 ( 1000 ) ) ;
if ( V_12 == 1 ) {
F_24 ( L_70 , V_25 -> V_36 ) ;
return - V_207 ;
}
if ( V_12 ) {
F_24 ( L_71 , V_25 -> V_36 ) ;
return - V_208 ;
}
V_194 = F_107 () ;
V_193 = F_111 ( V_194 , V_192 ) ;
V_195 = ( unsigned long long ) F_112 ( V_193 ) >> 10 ;
F_89 ( L_72 , V_25 -> V_36 , V_195 ) ;
F_53 ( V_175 , & V_2 -> V_3 ) ;
V_12 = F_113 ( & V_141 , V_142 , & V_25 -> V_75 ) ;
if ( V_12 < 0 )
return 0 ;
F_89 ( L_73 , V_25 -> V_36 , V_142 ) ;
V_153 = V_141 -> V_2 ;
while ( V_141 -> V_53 > V_153 - V_141 -> V_2 ) {
T_3 V_210 = V_153 [ 0 ] + sizeof( T_3 ) ;
V_11 = F_85 ( V_25 , 0xfc8b , V_210 , V_153 ,
V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_74 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
F_94 ( V_141 ) ;
return F_74 ( V_11 ) ;
}
V_153 += V_210 ;
F_3 ( V_11 ) ;
}
F_94 ( V_141 ) ;
F_89 ( L_75 , V_25 -> V_36 ) ;
return 0 ;
}
static void F_114 ( struct V_34 * V_25 , T_3 V_211 )
{
struct V_10 * V_11 ;
T_3 type = 0x00 ;
F_24 ( L_76 , V_25 -> V_36 , V_211 ) ;
V_11 = F_85 ( V_25 , V_167 , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_77 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return;
}
F_3 ( V_11 ) ;
V_11 = F_85 ( V_25 , 0xfc22 , 1 , & type , V_129 ) ;
if ( F_73 ( V_11 ) ) {
F_24 ( L_78 ,
V_25 -> V_36 , F_74 ( V_11 ) ) ;
return;
}
if ( V_11 -> V_13 != 13 ) {
F_24 ( L_79 , V_25 -> V_36 ) ;
F_3 ( V_11 ) ;
return;
}
F_24 ( L_80 , V_25 -> V_36 , ( char * ) ( V_11 -> V_2 + 1 ) ) ;
F_3 ( V_11 ) ;
}
static int F_115 ( struct V_34 * V_25 )
{
struct V_10 * V_11 ;
long V_143 ;
V_11 = F_85 ( V_25 , 0xfc3f , 0 , NULL , V_129 ) ;
if ( F_73 ( V_11 ) ) {
V_143 = F_74 ( V_11 ) ;
F_24 ( L_81 ,
V_25 -> V_36 , V_143 ) ;
return V_143 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_116 ( struct V_34 * V_25 ,
const T_7 * V_212 )
{
struct V_10 * V_11 ;
T_3 V_51 [ 8 ] ;
long V_143 ;
V_51 [ 0 ] = 0xfe ;
V_51 [ 1 ] = sizeof( T_7 ) ;
memcpy ( V_51 + 2 , V_212 , sizeof( T_7 ) ) ;
V_11 = F_85 ( V_25 , 0xfc22 , sizeof( V_51 ) , V_51 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
V_143 = F_74 ( V_11 ) ;
F_24 ( L_82 ,
V_25 -> V_36 , V_143 ) ;
return V_143 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_117 ( struct V_34 * V_25 ,
const T_7 * V_212 )
{
struct V_10 * V_11 ;
T_3 V_51 [ 10 ] ;
long V_143 ;
V_51 [ 0 ] = 0x01 ;
V_51 [ 1 ] = 0x01 ;
V_51 [ 2 ] = 0x00 ;
V_51 [ 3 ] = sizeof( T_7 ) ;
memcpy ( V_51 + 4 , V_212 , sizeof( T_7 ) ) ;
V_11 = F_85 ( V_25 , 0xfc0b , sizeof( V_51 ) , V_51 , V_129 ) ;
if ( F_73 ( V_11 ) ) {
V_143 = F_74 ( V_11 ) ;
F_24 ( L_83 ,
V_25 -> V_36 , V_143 ) ;
return V_143 ;
}
F_3 ( V_11 ) ;
return 0 ;
}
static int F_118 ( struct V_34 * V_25 , T_3 V_213 ,
void * V_2 , T_8 V_53 )
{
struct V_1 * V_214 = F_21 ( V_25 ) ;
struct V_215 * V_46 = V_214 -> V_46 ;
int V_52 , V_12 ;
T_3 * V_51 ;
V_51 = F_32 ( V_53 , V_86 ) ;
if ( ! V_51 )
return - V_16 ;
V_52 = F_119 ( V_46 , 0 ) ;
V_12 = F_120 ( V_46 , V_52 , V_213 , V_216 | V_217 ,
0 , 0 , V_51 , V_53 , V_218 ) ;
if ( V_12 < 0 ) {
F_24 ( L_84 , V_25 -> V_36 , V_12 ) ;
goto V_76;
}
memcpy ( V_2 , V_51 , V_53 ) ;
V_76:
F_45 ( V_51 ) ;
return V_12 ;
}
static int F_121 ( struct V_34 * V_25 ,
const struct V_138 * V_138 ,
T_9 V_219 )
{
struct V_1 * V_214 = F_21 ( V_25 ) ;
struct V_215 * V_46 = V_214 -> V_46 ;
T_9 V_9 , V_53 , V_220 = 0 ;
int V_52 , V_13 , V_12 ;
T_3 * V_51 ;
V_51 = F_32 ( V_221 , V_86 ) ;
if ( ! V_51 )
return - V_16 ;
V_9 = V_138 -> V_53 ;
V_53 = F_9 ( T_9 , V_9 , V_219 ) ;
memcpy ( V_51 , V_138 -> V_2 , V_53 ) ;
V_52 = F_63 ( V_46 , 0 ) ;
V_12 = F_120 ( V_46 , V_52 , V_222 , V_216 ,
0 , 0 , V_51 , V_53 , V_218 ) ;
if ( V_12 < 0 ) {
F_24 ( L_85 , V_25 -> V_36 , V_12 ) ;
goto V_76;
}
V_220 += V_53 ;
V_9 -= V_53 ;
while ( V_9 ) {
V_53 = F_9 ( T_9 , V_9 , V_221 ) ;
memcpy ( V_51 , V_138 -> V_2 + V_220 , V_53 ) ;
V_52 = F_66 ( V_46 , 0x02 ) ;
V_12 = F_122 ( V_46 , V_52 , V_51 , V_53 , & V_13 ,
V_223 ) ;
if ( V_12 < 0 ) {
F_24 ( L_86 ,
V_25 -> V_36 , V_220 , V_138 -> V_53 , V_12 ) ;
break;
}
if ( V_53 != V_13 ) {
F_24 ( L_87 , V_25 -> V_36 ) ;
V_12 = - V_23 ;
break;
}
V_220 += V_53 ;
V_9 -= V_53 ;
}
V_76:
F_45 ( V_51 ) ;
return V_12 ;
}
static int F_123 ( struct V_34 * V_25 ,
struct V_224 * V_140 ,
const struct V_225 * V_226 )
{
struct V_227 * V_228 ;
const struct V_138 * V_141 ;
T_5 V_229 , V_230 ;
T_8 V_231 , V_232 ;
char V_142 [ 64 ] ;
int V_12 ;
V_229 = F_124 ( V_140 -> V_233 ) ;
V_230 = F_124 ( V_140 -> V_234 ) ;
snprintf ( V_142 , sizeof( V_142 ) , L_88 , V_229 ) ;
V_12 = F_88 ( & V_141 , V_142 , & V_25 -> V_75 ) ;
if ( V_12 ) {
F_24 ( L_89 ,
V_25 -> V_36 , V_142 , V_12 ) ;
return V_12 ;
}
F_89 ( L_90 , V_25 -> V_36 , V_142 ) ;
V_228 = (struct V_227 * ) ( V_141 -> V_2 + V_226 -> V_235 ) ;
V_231 = F_31 ( V_228 -> V_233 ) ;
V_232 = F_31 ( V_228 -> V_234 ) ;
F_89 ( L_91
L_92 , V_25 -> V_36 , V_231 , V_232 , V_229 ,
V_230 ) ;
if ( V_231 != V_229 || V_232 <= V_230 ) {
F_24 ( L_93 ,
V_25 -> V_36 ) ;
V_12 = - V_152 ;
goto V_76;
}
V_12 = F_121 ( V_25 , V_141 , V_226 -> V_236 ) ;
V_76:
F_94 ( V_141 ) ;
return V_12 ;
}
static int F_125 ( struct V_34 * V_25 ,
struct V_224 * V_140 ,
const struct V_225 * V_226 )
{
const struct V_138 * V_141 ;
char V_142 [ 64 ] ;
int V_12 ;
snprintf ( V_142 , sizeof( V_142 ) , L_94 ,
F_124 ( V_140 -> V_233 ) ) ;
V_12 = F_88 ( & V_141 , V_142 , & V_25 -> V_75 ) ;
if ( V_12 ) {
F_24 ( L_95 ,
V_25 -> V_36 , V_142 , V_12 ) ;
return V_12 ;
}
F_89 ( L_96 , V_25 -> V_36 , V_142 ) ;
V_12 = F_121 ( V_25 , V_141 , V_226 -> V_237 ) ;
F_94 ( V_141 ) ;
return V_12 ;
}
static int F_126 ( struct V_34 * V_25 )
{
const struct V_225 * V_226 = NULL ;
struct V_224 V_140 ;
T_5 V_229 ;
T_3 V_37 ;
int V_64 , V_12 ;
V_12 = F_118 ( V_25 , V_238 , & V_140 ,
sizeof( V_140 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_229 = F_124 ( V_140 . V_233 ) ;
for ( V_64 = 0 ; V_64 < F_127 ( V_239 ) ; V_64 ++ ) {
if ( V_229 == V_239 [ V_64 ] . V_233 )
V_226 = & V_239 [ V_64 ] ;
}
if ( ! V_226 ) {
F_24 ( L_97 , V_25 -> V_36 ,
V_229 ) ;
return - V_49 ;
}
V_12 = F_118 ( V_25 , V_240 , & V_37 ,
sizeof( V_37 ) ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_37 & V_241 ) ) {
V_12 = F_123 ( V_25 , & V_140 , V_226 ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( ! ( V_37 & V_242 ) ) {
V_12 = F_125 ( V_25 , & V_140 , V_226 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_128 ( struct V_114 * V_84 ,
const struct V_243 * V_244 )
{
struct V_116 * V_117 ;
struct V_1 * V_2 ;
struct V_34 * V_25 ;
int V_64 , V_12 ;
F_22 ( L_98 , V_84 , V_244 ) ;
if ( V_84 -> V_119 -> V_120 . V_245 != 0 )
return - V_49 ;
if ( ! V_244 -> V_246 ) {
const struct V_243 * V_247 ;
V_247 = F_129 ( V_84 , V_248 ) ;
if ( V_247 )
V_244 = V_247 ;
}
if ( V_244 -> V_246 == V_249 )
return - V_49 ;
if ( V_244 -> V_246 & V_250 ) {
struct V_215 * V_46 = F_130 ( V_84 ) ;
if ( F_31 ( V_46 -> V_251 . V_252 ) <= 0x0001 )
return - V_49 ;
}
V_2 = F_131 ( & V_84 -> V_75 , sizeof( * V_2 ) , V_86 ) ;
if ( ! V_2 )
return - V_16 ;
for ( V_64 = 0 ; V_64 < V_84 -> V_119 -> V_120 . V_121 ; V_64 ++ ) {
V_117 = & V_84 -> V_119 -> V_122 [ V_64 ] . V_120 ;
if ( ! V_2 -> V_54 && F_132 ( V_117 ) ) {
V_2 -> V_54 = V_117 ;
continue;
}
if ( ! V_2 -> V_101 && F_133 ( V_117 ) ) {
V_2 -> V_101 = V_117 ;
continue;
}
if ( ! V_2 -> V_63 && F_134 ( V_117 ) ) {
V_2 -> V_63 = V_117 ;
continue;
}
}
if ( ! V_2 -> V_54 || ! V_2 -> V_101 || ! V_2 -> V_63 )
return - V_49 ;
if ( V_244 -> V_246 & V_253 ) {
V_2 -> V_95 = V_254 | 0x01 ;
V_2 -> V_97 = 0x2b ;
} else {
V_2 -> V_95 = V_254 ;
V_2 -> V_97 = 0x00 ;
}
V_2 -> V_46 = F_130 ( V_84 ) ;
V_2 -> V_84 = V_84 ;
F_135 ( & V_2 -> V_88 , F_81 ) ;
F_135 ( & V_2 -> V_89 , F_83 ) ;
F_136 ( & V_2 -> V_90 ) ;
F_136 ( & V_2 -> V_91 ) ;
F_137 ( & V_2 -> V_80 ) ;
F_136 ( & V_2 -> V_47 ) ;
F_136 ( & V_2 -> V_62 ) ;
F_136 ( & V_2 -> V_70 ) ;
F_137 ( & V_2 -> V_4 ) ;
if ( V_244 -> V_246 & V_255 ) {
V_2 -> V_24 = F_102 ;
V_2 -> V_60 = F_97 ;
F_51 ( V_175 , & V_2 -> V_3 ) ;
} else {
V_2 -> V_24 = F_17 ;
V_2 -> V_60 = F_14 ;
}
V_25 = F_138 () ;
if ( ! V_25 )
return - V_16 ;
V_25 -> V_256 = V_257 ;
F_139 ( V_25 , V_2 ) ;
if ( V_244 -> V_246 & V_253 )
V_25 -> V_258 = V_259 ;
else
V_25 -> V_258 = V_260 ;
V_2 -> V_25 = V_25 ;
F_140 ( V_25 , & V_84 -> V_75 ) ;
V_25 -> V_261 = F_47 ;
V_25 -> V_262 = F_55 ;
V_25 -> V_263 = F_59 ;
V_25 -> V_264 = F_72 ;
V_25 -> V_265 = F_76 ;
if ( V_244 -> V_246 & V_266 )
V_25 -> V_267 = F_84 ;
#ifdef F_141
if ( V_244 -> V_246 & V_268 ) {
V_25 -> V_267 = V_269 ;
V_25 -> V_270 = V_271 ;
}
if ( V_244 -> V_246 & V_272 )
V_25 -> V_267 = V_273 ;
#endif
if ( V_244 -> V_246 & V_274 ) {
V_25 -> V_267 = F_92 ;
V_25 -> V_275 = F_115 ;
V_25 -> V_270 = V_276 ;
F_51 ( V_277 , & V_25 -> V_136 ) ;
F_51 ( V_278 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_255 ) {
V_25 -> V_264 = F_103 ;
V_25 -> V_267 = F_106 ;
V_25 -> V_279 = F_114 ;
V_25 -> V_270 = V_276 ;
F_51 ( V_277 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_280 )
V_25 -> V_270 = F_116 ;
if ( V_244 -> V_246 & V_281 ) {
F_51 ( V_282 , & V_25 -> V_136 ) ;
F_51 ( V_283 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_284 )
F_51 ( V_285 , & V_25 -> V_136 ) ;
if ( V_244 -> V_246 & V_250 ) {
V_25 -> V_270 = F_117 ;
F_51 ( V_278 , & V_25 -> V_136 ) ;
F_51 ( V_277 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_286 ) {
V_2 -> V_83 = F_126 ;
V_25 -> V_270 = F_117 ;
}
#ifdef F_142
if ( V_244 -> V_246 & V_287 ) {
V_25 -> V_267 = V_288 ;
F_51 ( V_289 , & V_2 -> V_3 ) ;
}
#endif
if ( V_244 -> V_246 & V_253 ) {
V_2 -> V_115 = NULL ;
} else {
V_2 -> V_115 = F_143 ( V_2 -> V_46 , 1 ) ;
}
if ( ! V_290 )
F_51 ( V_135 , & V_25 -> V_136 ) ;
if ( V_291 || V_244 -> V_246 & V_292 ) {
if ( ! V_293 )
F_51 ( V_294 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_295 )
V_2 -> V_115 = NULL ;
if ( V_244 -> V_246 & V_296 ) {
V_2 -> V_95 = V_216 ;
F_51 ( V_135 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_297 ) {
struct V_215 * V_46 = V_2 -> V_46 ;
T_8 V_252 = F_31 ( V_46 -> V_251 . V_252 ) ;
if ( V_252 < 0x117 )
F_51 ( V_135 , & V_25 -> V_136 ) ;
if ( V_252 <= 0x100 )
V_25 -> V_267 = F_86 ;
F_51 ( V_278 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_298 ) {
struct V_215 * V_46 = V_2 -> V_46 ;
if ( F_31 ( V_46 -> V_251 . V_252 ) > 0x997 )
F_51 ( V_285 , & V_25 -> V_136 ) ;
}
if ( V_244 -> V_246 & V_284 ) {
V_12 = F_78 ( V_2 -> V_46 , 0 , 0 ) ;
if ( V_12 < 0 ) {
F_24 ( L_99 , V_12 ) ;
F_144 ( V_25 ) ;
return V_12 ;
}
}
if ( V_2 -> V_115 ) {
V_12 = F_145 ( & V_299 ,
V_2 -> V_115 , V_2 ) ;
if ( V_12 < 0 ) {
F_144 ( V_25 ) ;
return V_12 ;
}
}
V_12 = F_146 ( V_25 ) ;
if ( V_12 < 0 ) {
F_144 ( V_25 ) ;
return V_12 ;
}
F_147 ( V_84 , V_2 ) ;
return 0 ;
}
static void F_148 ( struct V_114 * V_84 )
{
struct V_1 * V_2 = F_149 ( V_84 ) ;
struct V_34 * V_25 ;
F_22 ( L_100 , V_84 ) ;
if ( ! V_2 )
return;
V_25 = V_2 -> V_25 ;
F_147 ( V_2 -> V_84 , NULL ) ;
if ( V_2 -> V_115 )
F_147 ( V_2 -> V_115 , NULL ) ;
F_150 ( V_25 ) ;
if ( V_84 == V_2 -> V_115 )
F_151 ( & V_299 , V_2 -> V_84 ) ;
else if ( V_2 -> V_115 )
F_151 ( & V_299 , V_2 -> V_115 ) ;
F_144 ( V_25 ) ;
}
static int F_152 ( struct V_114 * V_84 , T_10 V_300 )
{
struct V_1 * V_2 = F_149 ( V_84 ) ;
F_22 ( L_100 , V_84 ) ;
if ( V_2 -> V_301 ++ )
return 0 ;
F_153 ( & V_2 -> V_80 ) ;
if ( ! ( F_154 ( V_300 ) && V_2 -> V_81 ) ) {
F_51 ( V_104 , & V_2 -> V_3 ) ;
F_155 ( & V_2 -> V_80 ) ;
} else {
F_155 ( & V_2 -> V_80 ) ;
V_2 -> V_301 -- ;
return - V_105 ;
}
F_57 ( & V_2 -> V_88 ) ;
F_54 ( V_2 ) ;
F_50 ( & V_2 -> V_91 ) ;
if ( F_23 ( V_289 , & V_2 -> V_3 ) &&
! F_156 ( & V_2 -> V_46 -> V_75 ) )
V_2 -> V_46 -> V_302 = 1 ;
return 0 ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_33 * V_33 ;
int V_12 ;
while ( ( V_33 = F_158 ( & V_2 -> V_90 ) ) ) {
V_12 = F_27 ( V_33 , V_15 ) ;
if ( V_12 < 0 )
break;
V_2 -> V_81 ++ ;
}
F_58 ( & V_2 -> V_90 ) ;
}
static int F_159 ( struct V_114 * V_84 )
{
struct V_1 * V_2 = F_149 ( V_84 ) ;
struct V_34 * V_25 = V_2 -> V_25 ;
int V_12 = 0 ;
F_22 ( L_100 , V_84 ) ;
if ( -- V_2 -> V_301 )
return 0 ;
if ( ! F_23 ( V_39 , & V_25 -> V_3 ) )
goto V_76;
if ( F_23 ( V_45 , & V_2 -> V_3 ) ) {
V_12 = F_29 ( V_25 , V_303 ) ;
if ( V_12 < 0 ) {
F_53 ( V_45 , & V_2 -> V_3 ) ;
goto V_87;
}
}
if ( F_23 ( V_61 , & V_2 -> V_3 ) ) {
V_12 = F_37 ( V_25 , V_303 ) ;
if ( V_12 < 0 ) {
F_53 ( V_61 , & V_2 -> V_3 ) ;
goto V_87;
}
F_37 ( V_25 , V_303 ) ;
}
if ( F_23 ( V_69 , & V_2 -> V_3 ) ) {
if ( F_42 ( V_25 , V_303 ) < 0 )
F_53 ( V_69 , & V_2 -> V_3 ) ;
else
F_42 ( V_25 , V_303 ) ;
}
F_153 ( & V_2 -> V_80 ) ;
F_157 ( V_2 ) ;
F_53 ( V_104 , & V_2 -> V_3 ) ;
F_155 ( & V_2 -> V_80 ) ;
F_71 ( & V_2 -> V_88 ) ;
return 0 ;
V_87:
F_58 ( & V_2 -> V_90 ) ;
V_76:
F_153 ( & V_2 -> V_80 ) ;
F_53 ( V_104 , & V_2 -> V_3 ) ;
F_155 ( & V_2 -> V_80 ) ;
return V_12 ;
}
