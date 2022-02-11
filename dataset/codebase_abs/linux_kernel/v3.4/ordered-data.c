static T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 + V_2 -> V_4 < V_2 -> V_3 )
return ( T_1 ) - 1 ;
return V_2 -> V_3 + V_2 -> V_4 ;
}
static struct V_5 * F_2 ( struct V_6 * V_7 , T_1 V_3 ,
struct V_5 * V_8 )
{
struct V_5 * * V_9 = & V_7 -> V_5 ;
struct V_5 * V_10 = NULL ;
struct V_1 * V_2 ;
while ( * V_9 ) {
V_10 = * V_9 ;
V_2 = F_3 ( V_10 , struct V_1 , V_5 ) ;
if ( V_3 < V_2 -> V_3 )
V_9 = & ( * V_9 ) -> V_11 ;
else if ( V_3 >= F_1 ( V_2 ) )
V_9 = & ( * V_9 ) -> V_12 ;
else
return V_10 ;
}
F_4 ( V_8 , V_10 , V_9 ) ;
F_5 ( V_8 , V_7 ) ;
return NULL ;
}
static void F_6 ( struct V_13 * V_13 , int V_14 ,
T_1 V_15 )
{
struct V_16 * V_17 = F_7 ( V_13 -> V_18 ) ;
F_8 ( V_17 , V_14 , L_1
L_2 , ( unsigned long long ) V_15 ) ;
}
static struct V_5 * F_9 ( struct V_6 * V_7 , T_1 V_3 ,
struct V_5 * * V_19 )
{
struct V_5 * V_20 = V_7 -> V_5 ;
struct V_5 * V_21 = NULL ;
struct V_5 * V_22 ;
struct V_1 * V_2 ;
struct V_1 * V_23 = NULL ;
while ( V_20 ) {
V_2 = F_3 ( V_20 , struct V_1 , V_5 ) ;
V_21 = V_20 ;
V_23 = V_2 ;
if ( V_3 < V_2 -> V_3 )
V_20 = V_20 -> V_11 ;
else if ( V_3 >= F_1 ( V_2 ) )
V_20 = V_20 -> V_12 ;
else
return V_20 ;
}
if ( ! V_19 )
return NULL ;
while ( V_21 && V_3 >= F_1 ( V_23 ) ) {
V_22 = F_10 ( V_21 ) ;
if ( ! V_22 )
break;
V_23 = F_3 ( V_22 , struct V_1 ,
V_5 ) ;
if ( V_3 < F_1 ( V_23 ) )
break;
V_21 = V_22 ;
}
if ( V_21 )
V_23 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
while ( V_21 && V_3 < F_1 ( V_23 ) ) {
V_22 = F_11 ( V_21 ) ;
if ( ! V_22 )
break;
V_23 = F_3 ( V_22 , struct V_1 ,
V_5 ) ;
V_21 = V_22 ;
}
* V_19 = V_21 ;
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 < V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
if ( V_3 + V_4 <= V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static inline struct V_5 * F_14 ( struct V_24 * V_25 ,
T_1 V_3 )
{
struct V_6 * V_7 = & V_25 -> V_25 ;
struct V_5 * V_21 = NULL ;
struct V_5 * V_26 ;
struct V_1 * V_2 ;
if ( V_25 -> V_27 ) {
V_2 = F_3 ( V_25 -> V_27 , struct V_1 ,
V_5 ) ;
if ( F_12 ( V_2 , V_3 ) )
return V_25 -> V_27 ;
}
V_26 = F_9 ( V_7 , V_3 , & V_21 ) ;
if ( ! V_26 )
V_26 = V_21 ;
if ( V_26 )
V_25 -> V_27 = V_26 ;
return V_26 ;
}
static int F_15 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_30 , int V_31 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_35 = V_4 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_31 = V_31 ;
if ( type != V_36 && type != V_37 )
F_18 ( type , & V_2 -> V_38 ) ;
if ( V_30 )
F_18 ( V_39 , & V_2 -> V_38 ) ;
F_19 ( & V_2 -> V_40 , 1 ) ;
F_20 ( & V_2 -> V_41 ) ;
F_21 ( & V_2 -> V_42 ) ;
F_21 ( & V_2 -> V_43 ) ;
F_22 ( V_13 , V_2 ) ;
F_23 ( & V_25 -> V_44 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_45 , V_3 ) ;
F_24 ( & V_25 -> V_44 ) ;
F_23 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_46 ) ;
F_25 ( & V_2 -> V_43 ,
& F_16 ( V_13 ) -> V_7 -> V_17 -> V_47 ) ;
F_24 ( & F_16 ( V_13 ) -> V_7 -> V_17 -> V_46 ) ;
return 0 ;
}
int F_26 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_48 ) ;
}
int F_27 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_48 ) ;
}
int F_28 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_31 )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_31 ) ;
}
void F_29 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_23 ( & V_25 -> V_44 ) ;
F_25 ( & V_50 -> V_42 , & V_2 -> V_42 ) ;
F_24 ( & V_25 -> V_44 ) ;
}
int F_30 ( struct V_13 * V_13 ,
struct V_1 * * V_51 ,
T_1 * V_3 , T_1 V_52 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
T_1 V_53 ;
T_1 V_54 ;
T_1 V_55 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_23 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_56;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_56;
}
V_54 = F_31 ( * V_3 , V_2 -> V_3 ) ;
V_53 = F_32 ( * V_3 + V_52 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_53 ;
if ( V_54 > V_53 ) {
F_33 ( V_57 L_3 ,
( unsigned long long ) V_54 ,
( unsigned long long ) V_53 ) ;
}
V_55 = V_53 - V_54 ;
if ( V_55 > V_2 -> V_35 ) {
F_33 ( V_57 L_4 ,
( unsigned long long ) V_2 -> V_35 ,
( unsigned long long ) V_55 ) ;
}
V_2 -> V_35 -= V_55 ;
if ( V_2 -> V_35 == 0 )
V_26 = F_34 ( V_36 , & V_2 -> V_38 ) ;
else
V_26 = 1 ;
V_56:
if ( ! V_26 && V_51 && V_2 ) {
* V_51 = V_2 ;
F_35 ( & V_2 -> V_40 ) ;
}
F_24 ( & V_25 -> V_44 ) ;
return V_26 == 0 ;
}
int F_36 ( struct V_13 * V_13 ,
struct V_1 * * V_51 ,
T_1 V_3 , T_1 V_52 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_23 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_56;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_56;
}
if ( V_52 > V_2 -> V_35 ) {
F_33 ( V_57 L_4 ,
( unsigned long long ) V_2 -> V_35 ,
( unsigned long long ) V_52 ) ;
}
V_2 -> V_35 -= V_52 ;
if ( V_2 -> V_35 == 0 )
V_26 = F_34 ( V_36 , & V_2 -> V_38 ) ;
else
V_26 = 1 ;
V_56:
if ( ! V_26 && V_51 && V_2 ) {
* V_51 = V_2 ;
F_35 ( & V_2 -> V_40 ) ;
}
F_24 ( & V_25 -> V_44 ) ;
return V_26 == 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_58 * V_59 ;
struct V_49 * V_50 ;
F_38 ( V_2 -> V_13 , V_2 ) ;
if ( F_39 ( & V_2 -> V_40 ) ) {
while ( ! F_40 ( & V_2 -> V_42 ) ) {
V_59 = V_2 -> V_42 . V_60 ;
V_50 = F_41 ( V_59 , struct V_49 , V_42 ) ;
F_42 ( & V_50 -> V_42 ) ;
F_43 ( V_50 ) ;
}
F_43 ( V_2 ) ;
}
}
static void F_44 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_61 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
V_8 = & V_2 -> V_5 ;
F_45 ( V_8 , & V_25 -> V_25 ) ;
V_25 -> V_27 = NULL ;
F_18 ( V_37 , & V_2 -> V_38 ) ;
F_23 ( & V_7 -> V_17 -> V_46 ) ;
F_46 ( & V_2 -> V_43 ) ;
F_47 ( V_13 , V_2 ) ;
if ( F_48 ( & V_25 -> V_25 ) &&
! F_49 ( V_13 -> V_62 , V_63 ) ) {
F_46 ( & F_16 ( V_13 ) -> V_64 ) ;
}
F_24 ( & V_7 -> V_17 -> V_46 ) ;
}
void F_50 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_23 ( & V_25 -> V_44 ) ;
F_44 ( V_13 , V_2 ) ;
F_24 ( & V_25 -> V_44 ) ;
F_51 ( & V_2 -> V_41 ) ;
}
void F_52 ( struct V_61 * V_7 ,
int V_65 , int V_66 )
{
struct V_58 V_67 ;
struct V_58 * V_59 ;
struct V_1 * V_68 ;
struct V_13 * V_13 ;
F_21 ( & V_67 ) ;
F_23 ( & V_7 -> V_17 -> V_46 ) ;
F_53 ( & V_7 -> V_17 -> V_47 , & V_67 ) ;
while ( ! F_40 ( & V_67 ) ) {
V_59 = V_67 . V_60 ;
V_68 = F_41 ( V_59 , struct V_1 ,
V_43 ) ;
if ( V_65 &&
! F_54 ( V_69 , & V_68 -> V_38 ) &&
! F_54 ( V_70 , & V_68 -> V_38 ) ) {
F_55 ( & V_68 -> V_43 ,
& V_7 -> V_17 -> V_47 ) ;
F_56 ( & V_7 -> V_17 -> V_46 ) ;
continue;
}
F_46 ( & V_68 -> V_43 ) ;
F_35 ( & V_68 -> V_40 ) ;
V_13 = F_57 ( V_68 -> V_13 ) ;
F_24 ( & V_7 -> V_17 -> V_46 ) ;
if ( V_13 ) {
F_58 ( V_13 , V_68 , 1 ) ;
F_37 ( V_68 ) ;
if ( V_66 )
F_59 ( V_13 ) ;
else
F_60 ( V_13 ) ;
} else {
F_37 ( V_68 ) ;
}
F_23 ( & V_7 -> V_17 -> V_46 ) ;
}
F_24 ( & V_7 -> V_17 -> V_46 ) ;
}
void F_61 ( struct V_61 * V_7 , int V_41 )
{
struct V_71 * V_71 ;
struct V_13 * V_13 ;
struct V_58 V_67 ;
F_21 ( & V_67 ) ;
F_62 ( & V_7 -> V_17 -> V_72 ) ;
F_23 ( & V_7 -> V_17 -> V_46 ) ;
V_73:
F_53 ( & V_7 -> V_17 -> V_64 , & V_67 ) ;
while ( ! F_40 ( & V_67 ) ) {
V_71 = F_41 ( V_67 . V_60 , struct V_71 ,
V_64 ) ;
V_13 = & V_71 -> V_74 ;
F_46 ( & V_71 -> V_64 ) ;
V_13 = F_57 ( V_13 ) ;
if ( ! V_41 && V_13 ) {
F_25 ( & F_16 ( V_13 ) -> V_64 ,
& V_7 -> V_17 -> V_64 ) ;
}
F_24 ( & V_7 -> V_17 -> V_46 ) ;
if ( V_13 ) {
if ( V_41 )
F_63 ( V_13 , 0 , ( T_1 ) - 1 ) ;
else
F_64 ( V_13 -> V_62 ) ;
F_59 ( V_13 ) ;
}
F_65 () ;
F_23 ( & V_7 -> V_17 -> V_46 ) ;
}
if ( V_41 && ! F_40 ( & V_7 -> V_17 -> V_64 ) )
goto V_73;
F_24 ( & V_7 -> V_17 -> V_46 ) ;
F_66 ( & V_7 -> V_17 -> V_72 ) ;
}
void F_58 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_41 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_75 = V_28 + V_2 -> V_4 - 1 ;
F_67 ( V_13 , V_2 ) ;
if ( ! F_54 ( V_39 , & V_2 -> V_38 ) )
F_68 ( V_13 -> V_62 , V_28 , V_75 ) ;
if ( V_41 ) {
F_69 ( V_2 -> V_41 , F_54 ( V_37 ,
& V_2 -> V_38 ) ) ;
}
}
void F_63 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
T_1 V_75 ;
T_1 V_76 ;
struct V_1 * V_68 ;
int V_77 ;
if ( V_28 + V_4 < V_28 ) {
V_76 = F_70 ( V_78 ) ;
} else {
V_76 = V_28 + V_4 - 1 ;
if ( V_76 > F_70 ( V_78 ) )
V_76 = F_70 ( V_78 ) ;
}
V_73:
F_68 ( V_13 -> V_62 , V_28 , V_76 ) ;
F_68 ( V_13 -> V_62 , V_28 , V_76 ) ;
F_71 ( V_13 -> V_62 , V_28 , V_76 ) ;
V_75 = V_76 ;
V_77 = 0 ;
while ( 1 ) {
V_68 = F_72 ( V_13 , V_75 ) ;
if ( ! V_68 )
break;
if ( V_68 -> V_3 > V_76 ) {
F_37 ( V_68 ) ;
break;
}
if ( V_68 -> V_3 + V_68 -> V_4 < V_28 ) {
F_37 ( V_68 ) ;
break;
}
V_77 ++ ;
F_58 ( V_13 , V_68 , 1 ) ;
V_75 = V_68 -> V_3 ;
F_37 ( V_68 ) ;
if ( V_75 == 0 || V_75 == V_28 )
break;
V_75 -- ;
}
if ( V_77 || F_73 ( & F_16 ( V_13 ) -> V_79 , V_28 , V_76 ,
V_80 , 0 , NULL ) ) {
F_74 ( 1 ) ;
goto V_73;
}
}
struct V_1 * F_75 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_23 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_56;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_35 ( & V_2 -> V_40 ) ;
V_56:
F_24 ( & V_25 -> V_44 ) ;
return V_2 ;
}
struct V_1 * F_76 ( struct V_13 * V_13 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_23 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_56;
}
while ( 1 ) {
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_13 ( V_2 , V_3 , V_4 ) )
break;
if ( V_2 -> V_3 >= V_3 + V_4 ) {
V_2 = NULL ;
break;
}
V_2 = NULL ;
V_8 = F_10 ( V_8 ) ;
if ( ! V_8 )
break;
}
V_56:
if ( V_2 )
F_35 ( & V_2 -> V_40 ) ;
F_24 ( & V_25 -> V_44 ) ;
return V_2 ;
}
struct V_1 *
F_72 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_32 ;
F_23 ( & V_25 -> V_44 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_56;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_35 ( & V_2 -> V_40 ) ;
V_56:
F_24 ( & V_25 -> V_44 ) ;
return V_2 ;
}
int F_77 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_68 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
struct V_81 * V_79 = & F_16 ( V_13 ) -> V_79 ;
T_1 V_82 ;
T_1 V_83 ;
T_1 V_84 ;
T_1 V_85 = F_78 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
if ( V_68 )
V_15 = F_1 ( V_68 ) ;
else
V_15 = F_79 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_86 ) ;
F_23 ( & V_25 -> V_44 ) ;
V_82 = F_16 ( V_13 ) -> V_82 ;
if ( V_82 > V_85 ) {
F_16 ( V_13 ) -> V_82 = V_85 ;
V_26 = 0 ;
goto V_56;
}
if ( V_82 == V_85 || V_15 <= V_82 ) {
goto V_56;
}
if ( F_73 ( V_79 , V_82 , V_15 - 1 ,
V_80 , 0 , NULL ) ) {
goto V_56;
}
if ( V_68 ) {
V_8 = F_11 ( & V_68 -> V_5 ) ;
} else {
V_21 = F_14 ( V_25 , V_15 ) ;
if ( V_21 ) {
V_22 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
F_80 ( F_12 ( V_22 , V_15 ) ) ;
}
V_8 = V_21 ;
}
while ( V_8 ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_82 )
break;
if ( V_22 -> V_3 >= V_85 )
break;
if ( V_22 -> V_3 >= V_82 )
goto V_56;
V_8 = F_11 ( V_8 ) ;
}
V_83 = F_81 ( T_1 , V_15 , V_85 ) ;
if ( V_68 ) {
V_8 = F_10 ( & V_68 -> V_5 ) ;
} else {
if ( V_21 )
V_8 = F_10 ( V_21 ) ;
else
V_8 = F_82 ( & V_25 -> V_25 ) ;
}
V_84 = 0 ;
if ( V_8 ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( V_22 -> V_3 > V_15 )
V_84 = V_22 -> V_3 ;
} else {
V_84 = V_85 ;
}
if ( V_84 > V_15 &&
! F_73 ( V_79 , V_15 , V_84 - 1 ,
V_80 , 0 , NULL ) ) {
V_83 = F_81 ( T_1 , V_84 , V_85 ) ;
}
F_16 ( V_13 ) -> V_82 = V_83 ;
V_26 = 0 ;
V_56:
if ( V_68 )
F_44 ( V_13 , V_68 ) ;
F_24 ( & V_25 -> V_44 ) ;
if ( V_68 )
F_51 ( & V_68 -> V_41 ) ;
return V_26 ;
}
int F_83 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_87 ,
T_2 * V_50 )
{
struct V_49 * V_88 ;
struct V_89 * V_90 ;
struct V_1 * V_68 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_32 ;
unsigned long V_91 ;
unsigned long V_92 ;
T_2 V_86 = F_16 ( V_13 ) -> V_7 -> V_86 ;
int V_26 = 1 ;
V_68 = F_75 ( V_13 , V_15 ) ;
if ( ! V_68 )
return 1 ;
F_23 ( & V_25 -> V_44 ) ;
F_84 (ordered_sum, &ordered->list, list) {
if ( V_87 >= V_88 -> V_93 ) {
V_91 = V_88 -> V_4 / V_86 ;
V_90 = V_88 -> V_94 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
if ( V_90 [ V_92 ] . V_93 == V_87 ) {
* V_50 = V_90 [ V_92 ] . V_50 ;
V_26 = 0 ;
goto V_56;
}
}
}
}
V_56:
F_24 ( & V_25 -> V_44 ) ;
F_37 ( V_68 ) ;
return V_26 ;
}
void F_85 ( struct V_95 * V_96 ,
struct V_61 * V_7 , struct V_13 * V_13 )
{
T_1 V_97 ;
V_97 = F_31 ( F_16 ( V_13 ) -> V_98 , F_16 ( V_13 ) -> V_99 ) ;
if ( V_97 < V_7 -> V_17 -> V_100 )
return;
if ( V_96 && V_7 -> V_17 -> V_101 -> V_102 ) {
F_63 ( V_13 , 0 , ( T_1 ) - 1 ) ;
return;
}
F_23 ( & V_7 -> V_17 -> V_46 ) ;
if ( F_40 ( & F_16 ( V_13 ) -> V_64 ) ) {
F_25 ( & F_16 ( V_13 ) -> V_64 ,
& V_7 -> V_17 -> V_64 ) ;
}
F_24 ( & V_7 -> V_17 -> V_46 ) ;
}
