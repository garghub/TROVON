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
static struct V_5 * F_6 ( struct V_6 * V_7 , T_1 V_3 ,
struct V_5 * * V_13 )
{
struct V_5 * V_14 = V_7 -> V_5 ;
struct V_5 * V_15 = NULL ;
struct V_5 * V_16 ;
struct V_1 * V_2 ;
struct V_1 * V_17 = NULL ;
while ( V_14 ) {
V_2 = F_3 ( V_14 , struct V_1 , V_5 ) ;
V_15 = V_14 ;
V_17 = V_2 ;
if ( V_3 < V_2 -> V_3 )
V_14 = V_14 -> V_11 ;
else if ( V_3 >= F_1 ( V_2 ) )
V_14 = V_14 -> V_12 ;
else
return V_14 ;
}
if ( ! V_13 )
return NULL ;
while ( V_15 && V_3 >= F_1 ( V_17 ) ) {
V_16 = F_7 ( V_15 ) ;
if ( ! V_16 )
break;
V_17 = F_3 ( V_16 , struct V_1 ,
V_5 ) ;
if ( V_3 < F_1 ( V_17 ) )
break;
V_15 = V_16 ;
}
if ( V_15 )
V_17 = F_3 ( V_15 , struct V_1 ,
V_5 ) ;
while ( V_15 && V_3 < F_1 ( V_17 ) ) {
V_16 = F_8 ( V_15 ) ;
if ( ! V_16 )
break;
V_17 = F_3 ( V_16 , struct V_1 ,
V_5 ) ;
V_15 = V_16 ;
}
* V_13 = V_15 ;
return NULL ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 < V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
if ( V_3 + V_4 <= V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static inline struct V_5 * F_11 ( struct V_18 * V_19 ,
T_1 V_3 )
{
struct V_6 * V_7 = & V_19 -> V_19 ;
struct V_5 * V_15 = NULL ;
struct V_5 * V_20 ;
struct V_1 * V_2 ;
if ( V_19 -> V_21 ) {
V_2 = F_3 ( V_19 -> V_21 , struct V_1 ,
V_5 ) ;
if ( F_9 ( V_2 , V_3 ) )
return V_19 -> V_21 ;
}
V_20 = F_6 ( V_7 , V_3 , & V_15 ) ;
if ( ! V_20 )
V_20 = V_15 ;
if ( V_20 )
V_19 -> V_21 = V_20 ;
return V_20 ;
}
static int F_12 ( struct V_22 * V_22 , T_1 V_3 ,
T_1 V_23 , T_1 V_4 , T_1 V_24 ,
int type , int V_25 , int V_26 )
{
struct V_18 * V_19 ;
struct V_5 * V_8 ;
struct V_1 * V_2 ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return - V_29 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_30 = V_4 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_26 = V_26 ;
if ( type != V_31 && type != V_32 )
F_15 ( type , & V_2 -> V_33 ) ;
if ( V_25 )
F_15 ( V_34 , & V_2 -> V_33 ) ;
F_16 ( & V_2 -> V_35 , 1 ) ;
F_17 ( & V_2 -> V_36 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_18 ( & V_2 -> V_38 ) ;
F_19 ( V_22 , V_2 ) ;
F_20 ( & V_19 -> V_39 ) ;
V_8 = F_2 ( & V_19 -> V_19 , V_3 ,
& V_2 -> V_5 ) ;
F_21 ( V_8 ) ;
F_22 ( & V_19 -> V_39 ) ;
F_20 ( & F_13 ( V_22 ) -> V_7 -> V_40 -> V_41 ) ;
F_23 ( & V_2 -> V_38 ,
& F_13 ( V_22 ) -> V_7 -> V_40 -> V_42 ) ;
F_22 ( & F_13 ( V_22 ) -> V_7 -> V_40 -> V_41 ) ;
F_21 ( V_8 ) ;
return 0 ;
}
int F_24 ( struct V_22 * V_22 , T_1 V_3 ,
T_1 V_23 , T_1 V_4 , T_1 V_24 , int type )
{
return F_12 ( V_22 , V_3 , V_23 , V_4 ,
V_24 , type , 0 ,
V_43 ) ;
}
int F_25 ( struct V_22 * V_22 , T_1 V_3 ,
T_1 V_23 , T_1 V_4 , T_1 V_24 , int type )
{
return F_12 ( V_22 , V_3 , V_23 , V_4 ,
V_24 , type , 1 ,
V_43 ) ;
}
int F_26 ( struct V_22 * V_22 , T_1 V_3 ,
T_1 V_23 , T_1 V_4 , T_1 V_24 ,
int type , int V_26 )
{
return F_12 ( V_22 , V_3 , V_23 , V_4 ,
V_24 , type , 0 ,
V_26 ) ;
}
int F_27 ( struct V_22 * V_22 ,
struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_18 * V_19 ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
F_20 ( & V_19 -> V_39 ) ;
F_23 ( & V_45 -> V_37 , & V_2 -> V_37 ) ;
F_22 ( & V_19 -> V_39 ) ;
return 0 ;
}
int F_28 ( struct V_22 * V_22 ,
struct V_1 * * V_46 ,
T_1 * V_3 , T_1 V_47 )
{
struct V_18 * V_19 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_20 ;
T_1 V_48 ;
T_1 V_49 ;
T_1 V_50 ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
F_20 ( & V_19 -> V_39 ) ;
V_8 = F_11 ( V_19 , * V_3 ) ;
if ( ! V_8 ) {
V_20 = 1 ;
goto V_51;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_9 ( V_2 , * V_3 ) ) {
V_20 = 1 ;
goto V_51;
}
V_49 = F_29 ( * V_3 , V_2 -> V_3 ) ;
V_48 = F_30 ( * V_3 + V_47 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_48 ;
if ( V_49 > V_48 ) {
F_31 ( V_52 L_1 ,
( unsigned long long ) V_49 ,
( unsigned long long ) V_48 ) ;
}
V_50 = V_48 - V_49 ;
if ( V_50 > V_2 -> V_30 ) {
F_31 ( V_52 L_2 ,
( unsigned long long ) V_2 -> V_30 ,
( unsigned long long ) V_50 ) ;
}
V_2 -> V_30 -= V_50 ;
if ( V_2 -> V_30 == 0 )
V_20 = F_32 ( V_31 , & V_2 -> V_33 ) ;
else
V_20 = 1 ;
V_51:
if ( ! V_20 && V_46 && V_2 ) {
* V_46 = V_2 ;
F_33 ( & V_2 -> V_35 ) ;
}
F_22 ( & V_19 -> V_39 ) ;
return V_20 == 0 ;
}
int F_34 ( struct V_22 * V_22 ,
struct V_1 * * V_46 ,
T_1 V_3 , T_1 V_47 )
{
struct V_18 * V_19 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_20 ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
F_20 ( & V_19 -> V_39 ) ;
V_8 = F_11 ( V_19 , V_3 ) ;
if ( ! V_8 ) {
V_20 = 1 ;
goto V_51;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_9 ( V_2 , V_3 ) ) {
V_20 = 1 ;
goto V_51;
}
if ( V_47 > V_2 -> V_30 ) {
F_31 ( V_52 L_2 ,
( unsigned long long ) V_2 -> V_30 ,
( unsigned long long ) V_47 ) ;
}
V_2 -> V_30 -= V_47 ;
if ( V_2 -> V_30 == 0 )
V_20 = F_32 ( V_31 , & V_2 -> V_33 ) ;
else
V_20 = 1 ;
V_51:
if ( ! V_20 && V_46 && V_2 ) {
* V_46 = V_2 ;
F_33 ( & V_2 -> V_35 ) ;
}
F_22 ( & V_19 -> V_39 ) ;
return V_20 == 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
struct V_44 * V_45 ;
F_36 ( V_2 -> V_22 , V_2 ) ;
if ( F_37 ( & V_2 -> V_35 ) ) {
while ( ! F_38 ( & V_2 -> V_37 ) ) {
V_54 = V_2 -> V_37 . V_55 ;
V_45 = F_39 ( V_54 , struct V_44 , V_37 ) ;
F_40 ( & V_45 -> V_37 ) ;
F_41 ( V_45 ) ;
}
F_41 ( V_2 ) ;
}
return 0 ;
}
static int F_42 ( struct V_22 * V_22 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_56 * V_7 = F_13 ( V_22 ) -> V_7 ;
struct V_5 * V_8 ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
V_8 = & V_2 -> V_5 ;
F_43 ( V_8 , & V_19 -> V_19 ) ;
V_19 -> V_21 = NULL ;
F_15 ( V_32 , & V_2 -> V_33 ) ;
F_20 ( & V_7 -> V_40 -> V_41 ) ;
F_44 ( & V_2 -> V_38 ) ;
F_45 ( V_22 , V_2 ) ;
if ( F_46 ( & V_19 -> V_19 ) &&
! F_47 ( V_22 -> V_57 , V_58 ) ) {
F_44 ( & F_13 ( V_22 ) -> V_59 ) ;
}
F_22 ( & V_7 -> V_40 -> V_41 ) ;
return 0 ;
}
int F_48 ( struct V_22 * V_22 ,
struct V_1 * V_2 )
{
struct V_18 * V_19 ;
int V_20 ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
F_20 ( & V_19 -> V_39 ) ;
V_20 = F_42 ( V_22 , V_2 ) ;
F_22 ( & V_19 -> V_39 ) ;
F_49 ( & V_2 -> V_36 ) ;
return V_20 ;
}
int F_50 ( struct V_56 * V_7 ,
int V_60 , int V_61 )
{
struct V_53 V_62 ;
struct V_53 * V_54 ;
struct V_1 * V_63 ;
struct V_22 * V_22 ;
F_18 ( & V_62 ) ;
F_20 ( & V_7 -> V_40 -> V_41 ) ;
F_51 ( & V_7 -> V_40 -> V_42 , & V_62 ) ;
while ( ! F_38 ( & V_62 ) ) {
V_54 = V_62 . V_55 ;
V_63 = F_39 ( V_54 , struct V_1 ,
V_38 ) ;
if ( V_60 &&
! F_52 ( V_64 , & V_63 -> V_33 ) &&
! F_52 ( V_65 , & V_63 -> V_33 ) ) {
F_53 ( & V_63 -> V_38 ,
& V_7 -> V_40 -> V_42 ) ;
F_54 ( & V_7 -> V_40 -> V_41 ) ;
continue;
}
F_44 ( & V_63 -> V_38 ) ;
F_33 ( & V_63 -> V_35 ) ;
V_22 = F_55 ( V_63 -> V_22 ) ;
F_22 ( & V_7 -> V_40 -> V_41 ) ;
if ( V_22 ) {
F_56 ( V_22 , V_63 , 1 ) ;
F_35 ( V_63 ) ;
if ( V_61 )
F_57 ( V_22 ) ;
else
F_58 ( V_22 ) ;
} else {
F_35 ( V_63 ) ;
}
F_20 ( & V_7 -> V_40 -> V_41 ) ;
}
F_22 ( & V_7 -> V_40 -> V_41 ) ;
return 0 ;
}
int F_59 ( struct V_56 * V_7 , int V_36 )
{
struct V_66 * V_66 ;
struct V_22 * V_22 ;
struct V_53 V_62 ;
F_18 ( & V_62 ) ;
F_60 ( & V_7 -> V_40 -> V_67 ) ;
F_20 ( & V_7 -> V_40 -> V_41 ) ;
V_68:
F_51 ( & V_7 -> V_40 -> V_59 , & V_62 ) ;
while ( ! F_38 ( & V_62 ) ) {
V_66 = F_39 ( V_62 . V_55 , struct V_66 ,
V_59 ) ;
V_22 = & V_66 -> V_69 ;
F_44 ( & V_66 -> V_59 ) ;
V_22 = F_55 ( V_22 ) ;
if ( ! V_36 && V_22 ) {
F_23 ( & F_13 ( V_22 ) -> V_59 ,
& V_7 -> V_40 -> V_59 ) ;
}
F_22 ( & V_7 -> V_40 -> V_41 ) ;
if ( V_22 ) {
if ( V_36 )
F_61 ( V_22 , 0 , ( T_1 ) - 1 ) ;
else
F_62 ( V_22 -> V_57 ) ;
F_57 ( V_22 ) ;
}
F_63 () ;
F_20 ( & V_7 -> V_40 -> V_41 ) ;
}
if ( V_36 && ! F_38 ( & V_7 -> V_40 -> V_59 ) )
goto V_68;
F_22 ( & V_7 -> V_40 -> V_41 ) ;
F_64 ( & V_7 -> V_40 -> V_67 ) ;
return 0 ;
}
void F_56 ( struct V_22 * V_22 ,
struct V_1 * V_2 ,
int V_36 )
{
T_1 V_23 = V_2 -> V_3 ;
T_1 V_70 = V_23 + V_2 -> V_4 - 1 ;
F_65 ( V_22 , V_2 ) ;
if ( ! F_52 ( V_34 , & V_2 -> V_33 ) )
F_66 ( V_22 -> V_57 , V_23 , V_70 ) ;
if ( V_36 ) {
F_67 ( V_2 -> V_36 , F_52 ( V_32 ,
& V_2 -> V_33 ) ) ;
}
}
int F_61 ( struct V_22 * V_22 , T_1 V_23 , T_1 V_4 )
{
T_1 V_70 ;
T_1 V_71 ;
struct V_1 * V_63 ;
int V_72 ;
if ( V_23 + V_4 < V_23 ) {
V_71 = F_68 ( V_73 ) ;
} else {
V_71 = V_23 + V_4 - 1 ;
if ( V_71 > F_68 ( V_73 ) )
V_71 = F_68 ( V_73 ) ;
}
V_68:
F_66 ( V_22 -> V_57 , V_23 , V_71 ) ;
F_66 ( V_22 -> V_57 , V_23 , V_71 ) ;
F_69 ( V_22 -> V_57 , V_23 , V_71 ) ;
V_70 = V_71 ;
V_72 = 0 ;
while ( 1 ) {
V_63 = F_70 ( V_22 , V_70 ) ;
if ( ! V_63 )
break;
if ( V_63 -> V_3 > V_71 ) {
F_35 ( V_63 ) ;
break;
}
if ( V_63 -> V_3 + V_63 -> V_4 < V_23 ) {
F_35 ( V_63 ) ;
break;
}
V_72 ++ ;
F_56 ( V_22 , V_63 , 1 ) ;
V_70 = V_63 -> V_3 ;
F_35 ( V_63 ) ;
if ( V_70 == 0 || V_70 == V_23 )
break;
V_70 -- ;
}
if ( V_72 || F_71 ( & F_13 ( V_22 ) -> V_74 , V_23 , V_71 ,
V_75 , 0 , NULL ) ) {
F_72 ( 1 ) ;
goto V_68;
}
return 0 ;
}
struct V_1 * F_73 ( struct V_22 * V_22 ,
T_1 V_3 )
{
struct V_18 * V_19 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
F_20 ( & V_19 -> V_39 ) ;
V_8 = F_11 ( V_19 , V_3 ) ;
if ( ! V_8 )
goto V_51;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_9 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_33 ( & V_2 -> V_35 ) ;
V_51:
F_22 ( & V_19 -> V_39 ) ;
return V_2 ;
}
struct V_1 * F_74 ( struct V_22 * V_22 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_18 * V_19 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
F_20 ( & V_19 -> V_39 ) ;
V_8 = F_11 ( V_19 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_11 ( V_19 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_51;
}
while ( 1 ) {
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_10 ( V_2 , V_3 , V_4 ) )
break;
if ( V_2 -> V_3 >= V_3 + V_4 ) {
V_2 = NULL ;
break;
}
V_2 = NULL ;
V_8 = F_7 ( V_8 ) ;
if ( ! V_8 )
break;
}
V_51:
if ( V_2 )
F_33 ( & V_2 -> V_35 ) ;
F_22 ( & V_19 -> V_39 ) ;
return V_2 ;
}
struct V_1 *
F_70 ( struct V_22 * V_22 , T_1 V_3 )
{
struct V_18 * V_19 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_19 = & F_13 ( V_22 ) -> V_27 ;
F_20 ( & V_19 -> V_39 ) ;
V_8 = F_11 ( V_19 , V_3 ) ;
if ( ! V_8 )
goto V_51;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_33 ( & V_2 -> V_35 ) ;
V_51:
F_22 ( & V_19 -> V_39 ) ;
return V_2 ;
}
int F_75 ( struct V_22 * V_22 , T_1 V_76 ,
struct V_1 * V_63 )
{
struct V_18 * V_19 = & F_13 ( V_22 ) -> V_27 ;
struct V_77 * V_74 = & F_13 ( V_22 ) -> V_74 ;
T_1 V_78 ;
T_1 V_79 ;
T_1 V_80 ;
T_1 V_81 = F_76 ( V_22 ) ;
struct V_5 * V_8 ;
struct V_5 * V_15 = NULL ;
struct V_1 * V_16 ;
int V_20 = 1 ;
if ( V_63 )
V_76 = F_1 ( V_63 ) ;
else
V_76 = F_77 ( V_76 , F_13 ( V_22 ) -> V_7 -> V_82 ) ;
F_20 ( & V_19 -> V_39 ) ;
V_78 = F_13 ( V_22 ) -> V_78 ;
if ( V_78 > V_81 ) {
F_13 ( V_22 ) -> V_78 = V_81 ;
V_20 = 0 ;
goto V_51;
}
if ( V_78 == V_81 || V_76 <= V_78 ) {
goto V_51;
}
if ( F_71 ( V_74 , V_78 , V_76 - 1 ,
V_75 , 0 , NULL ) ) {
goto V_51;
}
if ( V_63 ) {
V_8 = F_8 ( & V_63 -> V_5 ) ;
} else {
V_15 = F_11 ( V_19 , V_76 ) ;
if ( V_15 ) {
V_16 = F_3 ( V_15 , struct V_1 ,
V_5 ) ;
F_21 ( F_9 ( V_16 , V_76 ) ) ;
}
V_8 = V_15 ;
}
while ( V_8 ) {
V_16 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( V_16 -> V_3 + V_16 -> V_4 <= V_78 )
break;
if ( V_16 -> V_3 >= V_81 )
break;
if ( V_16 -> V_3 >= V_78 )
goto V_51;
V_8 = F_8 ( V_8 ) ;
}
V_79 = F_78 ( T_1 , V_76 , V_81 ) ;
if ( V_63 ) {
V_8 = F_7 ( & V_63 -> V_5 ) ;
} else {
if ( V_15 )
V_8 = F_7 ( V_15 ) ;
else
V_8 = F_79 ( & V_19 -> V_19 ) ;
}
V_80 = 0 ;
if ( V_8 ) {
V_16 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( V_16 -> V_3 > V_76 )
V_80 = V_16 -> V_3 ;
} else {
V_80 = V_81 ;
}
if ( V_80 > V_76 &&
! F_71 ( V_74 , V_76 , V_80 - 1 ,
V_75 , 0 , NULL ) ) {
V_79 = F_78 ( T_1 , V_80 , V_81 ) ;
}
F_13 ( V_22 ) -> V_78 = V_79 ;
V_20 = 0 ;
V_51:
if ( V_63 )
F_42 ( V_22 , V_63 ) ;
F_22 ( & V_19 -> V_39 ) ;
if ( V_63 )
F_49 ( & V_63 -> V_36 ) ;
return V_20 ;
}
int F_80 ( struct V_22 * V_22 , T_1 V_76 , T_1 V_83 ,
T_2 * V_45 )
{
struct V_44 * V_84 ;
struct V_85 * V_86 ;
struct V_1 * V_63 ;
struct V_18 * V_19 = & F_13 ( V_22 ) -> V_27 ;
unsigned long V_87 ;
unsigned long V_88 ;
T_2 V_82 = F_13 ( V_22 ) -> V_7 -> V_82 ;
int V_20 = 1 ;
V_63 = F_73 ( V_22 , V_76 ) ;
if ( ! V_63 )
return 1 ;
F_20 ( & V_19 -> V_39 ) ;
F_81 (ordered_sum, &ordered->list, list) {
if ( V_83 >= V_84 -> V_89 ) {
V_87 = V_84 -> V_4 / V_82 ;
V_86 = V_84 -> V_90 ;
for ( V_88 = 0 ; V_88 < V_87 ; V_88 ++ ) {
if ( V_86 [ V_88 ] . V_89 == V_83 ) {
* V_45 = V_86 [ V_88 ] . V_45 ;
V_20 = 0 ;
goto V_51;
}
}
}
}
V_51:
F_22 ( & V_19 -> V_39 ) ;
F_35 ( V_63 ) ;
return V_20 ;
}
int F_82 ( struct V_91 * V_92 ,
struct V_56 * V_7 ,
struct V_22 * V_22 )
{
T_1 V_93 ;
V_93 = F_29 ( F_13 ( V_22 ) -> V_94 , F_13 ( V_22 ) -> V_95 ) ;
if ( V_93 < V_7 -> V_40 -> V_96 )
return 0 ;
if ( V_92 && V_7 -> V_40 -> V_97 -> V_98 ) {
F_61 ( V_22 , 0 , ( T_1 ) - 1 ) ;
return 0 ;
}
F_20 ( & V_7 -> V_40 -> V_41 ) ;
if ( F_38 ( & F_13 ( V_22 ) -> V_59 ) ) {
F_23 ( & F_13 ( V_22 ) -> V_59 ,
& V_7 -> V_40 -> V_59 ) ;
}
F_22 ( & V_7 -> V_40 -> V_41 ) ;
return 0 ;
}
