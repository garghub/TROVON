static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
int V_7 = 0 ;
int V_8 = V_9 | V_10 |
( V_3 -> V_11 == V_12 ? V_13 : V_14 ) ;
F_2 ( ! F_3 ( V_1 ) ) ;
F_2 ( ! F_4 ( V_1 ) ) ;
V_6 = F_5 ( V_1 ) ;
V_5 = V_6 ;
do {
if ( ! F_6 ( V_5 ) )
continue;
if ( V_3 -> V_11 != V_15 ) {
F_7 ( V_5 ) ;
} else if ( ! F_8 ( V_5 ) ) {
F_9 ( V_3 , V_1 ) ;
continue;
}
if ( F_10 ( V_5 ) ) {
F_11 ( V_5 ) ;
} else {
F_12 ( V_5 ) ;
}
} while ( ( V_5 = V_5 -> V_16 ) != V_6 );
F_2 ( F_13 ( V_1 ) ) ;
F_14 ( V_1 ) ;
do {
struct V_4 * V_17 = V_5 -> V_16 ;
if ( F_15 ( V_5 ) ) {
F_16 ( V_8 , V_5 ) ;
V_7 ++ ;
}
V_5 = V_17 ;
} while ( V_5 != V_6 );
F_17 ( V_1 ) ;
if ( V_7 == 0 )
F_18 ( V_1 ) ;
return 0 ;
}
void F_19 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_20 ( V_19 ) ;
int error ;
F_21 ( V_21 ) ;
error = F_22 ( V_21 ) ;
if ( error )
F_23 ( V_19 -> V_22 ) ;
}
struct V_4 * F_24 ( struct V_18 * V_19 , T_1 V_23 , int V_24 )
{
struct V_20 * V_21 = F_20 ( V_19 ) ;
struct V_25 * V_26 = V_19 -> V_22 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
unsigned int V_27 ;
unsigned long V_28 ;
unsigned int V_29 ;
V_27 = V_30 - V_26 -> V_31 . V_32 ;
V_28 = V_23 >> V_27 ;
V_29 = V_23 - ( V_28 << V_27 ) ;
if ( V_24 ) {
for (; ; ) {
V_1 = F_25 ( V_21 , V_28 ) ;
if ( V_1 )
break;
F_26 () ;
}
} else {
V_1 = F_27 ( V_21 , V_28 ) ;
if ( ! V_1 )
return NULL ;
}
if ( ! F_4 ( V_1 ) )
F_28 ( V_1 , V_26 -> V_31 . V_33 , 0 ) ;
for ( V_5 = F_5 ( V_1 ) ; V_29 -- ; V_5 = V_5 -> V_16 )
;
F_29 ( V_5 ) ;
if ( ! F_6 ( V_5 ) )
F_30 ( V_5 , V_26 -> V_34 , V_23 ) ;
F_17 ( V_1 ) ;
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
return V_5 ;
}
static void F_33 ( struct V_4 * V_5 )
{
struct V_35 * V_36 = (struct V_35 * ) V_5 -> V_37 ;
F_7 ( V_5 ) ;
F_34 ( V_5 ) ;
F_35 ( V_5 ) ;
F_12 ( V_5 ) ;
V_36 -> V_38 = F_36 ( V_39 ) ;
}
struct V_4 * F_37 ( struct V_18 * V_19 , T_1 V_23 )
{
struct V_4 * V_5 ;
V_5 = F_24 ( V_19 , V_23 , V_40 ) ;
F_33 ( V_5 ) ;
return V_5 ;
}
int F_38 ( struct V_18 * V_19 , T_1 V_23 , int V_41 ,
struct V_4 * * V_42 )
{
struct V_25 * V_26 = V_19 -> V_22 ;
struct V_4 * V_5 ;
if ( F_39 ( F_40 ( V_43 , & V_26 -> V_44 ) ) ) {
* V_42 = NULL ;
return - V_45 ;
}
* V_42 = V_5 = F_24 ( V_19 , V_23 , V_40 ) ;
F_7 ( V_5 ) ;
if ( F_41 ( V_5 ) ) {
F_12 ( V_5 ) ;
return 0 ;
}
V_5 -> V_46 = V_47 ;
F_29 ( V_5 ) ;
F_16 ( V_48 | V_9 | V_10 , V_5 ) ;
if ( ! ( V_41 & V_49 ) )
return 0 ;
F_42 ( V_5 ) ;
if ( F_39 ( ! F_41 ( V_5 ) ) ) {
struct V_50 * V_51 = V_52 -> V_53 ;
if ( V_51 && V_51 -> V_54 )
F_43 ( V_26 , V_5 ) ;
F_44 ( V_5 ) ;
* V_42 = NULL ;
return - V_45 ;
}
return 0 ;
}
int F_45 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
if ( F_39 ( F_40 ( V_43 , & V_26 -> V_44 ) ) )
return - V_45 ;
F_42 ( V_5 ) ;
if ( ! F_41 ( V_5 ) ) {
struct V_50 * V_51 = V_52 -> V_53 ;
if ( V_51 && V_51 -> V_54 )
F_43 ( V_26 , V_5 ) ;
return - V_45 ;
}
if ( F_39 ( F_40 ( V_43 , & V_26 -> V_44 ) ) )
return - V_45 ;
return 0 ;
}
void F_46 ( struct V_4 * V_5 , struct V_50 * V_51 , int V_55 )
{
struct V_20 * V_21 = V_5 -> V_56 -> V_21 ;
struct V_25 * V_26 = F_47 ( V_21 ) ;
struct V_57 * V_58 = V_5 -> V_59 ;
if ( F_48 ( V_5 ) ) {
F_49 ( V_58 , 0 ) ;
F_50 ( & V_26 -> V_60 ) ;
F_51 ( & V_58 -> V_61 ) ;
if ( V_55 ) {
F_52 ( V_26 , V_26 -> V_62 ) ;
V_26 -> V_62 -- ;
V_51 -> V_63 ++ ;
} else {
F_52 ( V_26 , V_26 -> V_64 ) ;
V_26 -> V_64 -- ;
V_51 -> V_65 ++ ;
}
V_51 -> V_54 = 1 ;
F_44 ( V_5 ) ;
}
if ( V_58 ) {
F_53 ( & V_26 -> V_66 ) ;
if ( V_58 -> V_67 ) {
F_54 ( V_26 , V_58 ) ;
}
F_55 ( & V_26 -> V_66 ) ;
}
F_34 ( V_5 ) ;
F_56 ( V_5 ) ;
}
void F_57 ( struct V_68 * V_69 , T_1 V_70 , T_2 V_71 )
{
struct V_25 * V_26 = F_58 ( & V_69 -> V_72 ) ;
struct V_4 * V_5 ;
while ( V_71 ) {
V_5 = F_24 ( V_69 -> V_73 , V_70 , V_74 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_59 ( V_26 ) ;
F_46 ( V_5 , V_52 -> V_53 , 1 ) ;
F_60 ( V_26 ) ;
F_12 ( V_5 ) ;
F_44 ( V_5 ) ;
}
V_70 ++ ;
V_71 -- ;
}
}
int F_61 ( struct V_68 * V_69 , int V_75 , T_1 V_76 ,
struct V_4 * * V_42 )
{
struct V_25 * V_26 = F_58 ( & V_69 -> V_72 ) ;
struct V_18 * V_19 = V_69 -> V_73 ;
struct V_4 * V_5 ;
int V_77 = 0 ;
T_2 V_78 = V_75 ? V_79 : V_80 ;
V_77 = F_38 ( V_19 , V_76 , V_49 , & V_5 ) ;
if ( V_77 == 0 && F_62 ( V_26 , V_5 , V_78 ) ) {
F_44 ( V_5 ) ;
V_77 = - V_45 ;
}
* V_42 = V_5 ;
return V_77 ;
}
struct V_4 * F_63 ( struct V_18 * V_19 , T_1 V_81 , T_2 V_82 )
{
struct V_25 * V_26 = V_19 -> V_22 ;
struct V_4 * V_83 , * V_5 ;
T_2 V_84 = F_64 ( V_26 , V_85 ) >>
V_26 -> V_31 . V_32 ;
F_2 ( ! V_82 ) ;
if ( V_84 < 1 )
V_84 = 1 ;
if ( V_82 > V_84 )
V_82 = V_84 ;
V_83 = F_24 ( V_19 , V_81 , V_40 ) ;
if ( F_41 ( V_83 ) )
goto V_86;
if ( ! F_65 ( V_83 ) )
F_66 ( V_48 | V_9 , 1 , & V_83 ) ;
V_81 ++ ;
V_82 -- ;
while ( V_82 ) {
V_5 = F_24 ( V_19 , V_81 , V_40 ) ;
if ( ! F_41 ( V_5 ) && ! F_65 ( V_5 ) )
F_66 ( V_87 | V_9 , 1 , & V_5 ) ;
F_44 ( V_5 ) ;
V_81 ++ ;
V_82 -- ;
if ( ! F_65 ( V_83 ) && F_41 ( V_83 ) )
goto V_86;
}
F_42 ( V_83 ) ;
V_86:
return V_83 ;
}
