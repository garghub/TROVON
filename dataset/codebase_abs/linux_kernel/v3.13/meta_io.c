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
struct V_4 * F_19 ( struct V_18 * V_19 , T_1 V_20 , int V_21 )
{
struct V_22 * V_23 = F_20 ( V_19 ) ;
struct V_24 * V_25 = V_19 -> V_26 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
unsigned int V_27 ;
unsigned long V_28 ;
unsigned int V_29 ;
V_27 = V_30 - V_25 -> V_31 . V_32 ;
V_28 = V_20 >> V_27 ;
V_29 = V_20 - ( V_28 << V_27 ) ;
if ( V_21 ) {
for (; ; ) {
V_1 = F_21 ( V_23 , V_28 ) ;
if ( V_1 )
break;
F_22 () ;
}
} else {
V_1 = F_23 ( V_23 , V_28 ) ;
if ( ! V_1 )
return NULL ;
}
if ( ! F_4 ( V_1 ) )
F_24 ( V_1 , V_25 -> V_31 . V_33 , 0 ) ;
for ( V_5 = F_5 ( V_1 ) ; V_29 -- ; V_5 = V_5 -> V_16 )
;
F_25 ( V_5 ) ;
if ( ! F_6 ( V_5 ) )
F_26 ( V_5 , V_25 -> V_34 , V_20 ) ;
F_17 ( V_1 ) ;
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
return V_5 ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_35 * V_36 = (struct V_35 * ) V_5 -> V_37 ;
F_7 ( V_5 ) ;
F_30 ( V_5 ) ;
F_31 ( V_5 ) ;
F_12 ( V_5 ) ;
V_36 -> V_38 = F_32 ( V_39 ) ;
}
struct V_4 * F_33 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_4 * V_5 ;
V_5 = F_19 ( V_19 , V_20 , V_40 ) ;
F_29 ( V_5 ) ;
return V_5 ;
}
int F_34 ( struct V_18 * V_19 , T_1 V_20 , int V_41 ,
struct V_4 * * V_42 )
{
struct V_24 * V_25 = V_19 -> V_26 ;
struct V_4 * V_5 ;
if ( F_35 ( F_36 ( V_43 , & V_25 -> V_44 ) ) ) {
* V_42 = NULL ;
return - V_45 ;
}
* V_42 = V_5 = F_19 ( V_19 , V_20 , V_40 ) ;
F_7 ( V_5 ) ;
if ( F_37 ( V_5 ) ) {
F_12 ( V_5 ) ;
return 0 ;
}
V_5 -> V_46 = V_47 ;
F_25 ( V_5 ) ;
F_16 ( V_48 | V_9 | V_10 , V_5 ) ;
if ( ! ( V_41 & V_49 ) )
return 0 ;
F_38 ( V_5 ) ;
if ( F_35 ( ! F_37 ( V_5 ) ) ) {
struct V_50 * V_51 = V_52 -> V_53 ;
if ( V_51 && V_51 -> V_54 )
F_39 ( V_25 , V_5 ) ;
F_40 ( V_5 ) ;
* V_42 = NULL ;
return - V_45 ;
}
return 0 ;
}
int F_41 ( struct V_24 * V_25 , struct V_4 * V_5 )
{
if ( F_35 ( F_36 ( V_43 , & V_25 -> V_44 ) ) )
return - V_45 ;
F_38 ( V_5 ) ;
if ( ! F_37 ( V_5 ) ) {
struct V_50 * V_51 = V_52 -> V_53 ;
if ( V_51 && V_51 -> V_54 )
F_39 ( V_25 , V_5 ) ;
return - V_45 ;
}
if ( F_35 ( F_36 ( V_43 , & V_25 -> V_44 ) ) )
return - V_45 ;
return 0 ;
}
void F_42 ( struct V_4 * V_5 , struct V_50 * V_51 , int V_55 )
{
struct V_22 * V_23 = V_5 -> V_56 -> V_23 ;
struct V_24 * V_25 = F_43 ( V_23 ) ;
struct V_57 * V_58 = V_5 -> V_59 ;
int V_60 = 0 ;
if ( F_44 ( V_5 ) ) {
F_45 ( V_58 , 0 ) ;
F_46 ( & V_25 -> V_61 ) ;
F_47 ( & V_58 -> V_62 ) ;
if ( V_55 ) {
F_48 ( V_25 , V_25 -> V_63 ) ;
V_25 -> V_63 -- ;
V_51 -> V_64 ++ ;
} else {
F_48 ( V_25 , V_25 -> V_65 ) ;
V_25 -> V_65 -- ;
V_51 -> V_66 ++ ;
}
V_51 -> V_54 = 1 ;
V_60 = 1 ;
F_40 ( V_5 ) ;
}
if ( V_58 ) {
F_49 ( & V_25 -> V_67 ) ;
if ( V_58 -> V_68 ) {
F_50 ( V_25 , V_58 ) ;
} else if ( V_60 ) {
V_5 -> V_59 = NULL ;
F_51 ( V_69 , V_58 ) ;
}
F_52 ( & V_25 -> V_67 ) ;
}
F_30 ( V_5 ) ;
F_53 ( V_5 ) ;
}
void F_54 ( struct V_70 * V_71 , T_1 V_72 , T_2 V_73 )
{
struct V_24 * V_25 = F_55 ( & V_71 -> V_74 ) ;
struct V_4 * V_5 ;
while ( V_73 ) {
V_5 = F_19 ( V_71 -> V_75 , V_72 , V_76 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_56 ( V_25 ) ;
F_42 ( V_5 , V_52 -> V_53 , 1 ) ;
F_57 ( V_25 ) ;
F_12 ( V_5 ) ;
F_40 ( V_5 ) ;
}
V_72 ++ ;
V_73 -- ;
}
}
int F_58 ( struct V_70 * V_71 , int V_77 , T_1 V_78 ,
struct V_4 * * V_42 )
{
struct V_24 * V_25 = F_55 ( & V_71 -> V_74 ) ;
struct V_18 * V_19 = V_71 -> V_75 ;
struct V_4 * V_5 ;
int V_79 = 0 ;
T_2 V_80 = V_77 ? V_81 : V_82 ;
V_79 = F_34 ( V_19 , V_78 , V_49 , & V_5 ) ;
if ( V_79 == 0 && F_59 ( V_25 , V_5 , V_80 ) ) {
F_40 ( V_5 ) ;
V_79 = - V_45 ;
}
* V_42 = V_5 ;
return V_79 ;
}
struct V_4 * F_60 ( struct V_18 * V_19 , T_1 V_83 , T_2 V_84 )
{
struct V_24 * V_25 = V_19 -> V_26 ;
struct V_4 * V_85 , * V_5 ;
T_2 V_86 = F_61 ( V_25 , V_87 ) >>
V_25 -> V_31 . V_32 ;
F_2 ( ! V_84 ) ;
if ( V_86 < 1 )
V_86 = 1 ;
if ( V_84 > V_86 )
V_84 = V_86 ;
V_85 = F_19 ( V_19 , V_83 , V_40 ) ;
if ( F_37 ( V_85 ) )
goto V_88;
if ( ! F_62 ( V_85 ) )
F_63 ( V_48 | V_9 , 1 , & V_85 ) ;
V_83 ++ ;
V_84 -- ;
while ( V_84 ) {
V_5 = F_19 ( V_19 , V_83 , V_40 ) ;
if ( ! F_37 ( V_5 ) && ! F_62 ( V_5 ) )
F_63 ( V_89 | V_9 , 1 , & V_5 ) ;
F_40 ( V_5 ) ;
V_83 ++ ;
V_84 -- ;
if ( ! F_62 ( V_85 ) && F_37 ( V_85 ) )
goto V_88;
}
F_38 ( V_85 ) ;
V_88:
return V_85 ;
}
