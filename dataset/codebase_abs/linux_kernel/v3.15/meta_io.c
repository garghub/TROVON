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
if ( V_23 == NULL )
V_23 = & V_25 -> V_30 ;
V_27 = V_31 - V_25 -> V_32 . V_33 ;
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
F_24 ( V_1 , V_25 -> V_32 . V_34 , 0 ) ;
for ( V_5 = F_5 ( V_1 ) ; V_29 -- ; V_5 = V_5 -> V_16 )
;
F_25 ( V_5 ) ;
if ( ! F_6 ( V_5 ) )
F_26 ( V_5 , V_25 -> V_35 , V_20 ) ;
F_17 ( V_1 ) ;
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
return V_5 ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_36 * V_37 = (struct V_36 * ) V_5 -> V_38 ;
F_7 ( V_5 ) ;
F_30 ( V_5 ) ;
F_31 ( V_5 ) ;
F_12 ( V_5 ) ;
V_37 -> V_39 = F_32 ( V_40 ) ;
}
struct V_4 * F_33 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_4 * V_5 ;
V_5 = F_19 ( V_19 , V_20 , V_41 ) ;
F_29 ( V_5 ) ;
return V_5 ;
}
int F_34 ( struct V_18 * V_19 , T_1 V_20 , int V_42 ,
struct V_4 * * V_43 )
{
struct V_24 * V_25 = V_19 -> V_26 ;
struct V_4 * V_5 ;
if ( F_35 ( F_36 ( V_44 , & V_25 -> V_45 ) ) ) {
* V_43 = NULL ;
return - V_46 ;
}
* V_43 = V_5 = F_19 ( V_19 , V_20 , V_41 ) ;
F_7 ( V_5 ) ;
if ( F_37 ( V_5 ) ) {
F_12 ( V_5 ) ;
return 0 ;
}
V_5 -> V_47 = V_48 ;
F_25 ( V_5 ) ;
F_16 ( V_49 | V_9 | V_10 , V_5 ) ;
if ( ! ( V_42 & V_50 ) )
return 0 ;
F_38 ( V_5 ) ;
if ( F_35 ( ! F_37 ( V_5 ) ) ) {
struct V_51 * V_52 = V_53 -> V_54 ;
if ( V_52 && V_52 -> V_55 )
F_39 ( V_25 , V_5 ) ;
F_40 ( V_5 ) ;
* V_43 = NULL ;
return - V_46 ;
}
return 0 ;
}
int F_41 ( struct V_24 * V_25 , struct V_4 * V_5 )
{
if ( F_35 ( F_36 ( V_44 , & V_25 -> V_45 ) ) )
return - V_46 ;
F_38 ( V_5 ) ;
if ( ! F_37 ( V_5 ) ) {
struct V_51 * V_52 = V_53 -> V_54 ;
if ( V_52 && V_52 -> V_55 )
F_39 ( V_25 , V_5 ) ;
return - V_46 ;
}
if ( F_35 ( F_36 ( V_44 , & V_25 -> V_45 ) ) )
return - V_46 ;
return 0 ;
}
void F_42 ( struct V_4 * V_5 , struct V_51 * V_52 , int V_56 )
{
struct V_22 * V_23 = V_5 -> V_57 -> V_23 ;
struct V_24 * V_25 = F_43 ( V_23 ) ;
struct V_58 * V_59 = V_5 -> V_60 ;
int V_61 = 0 ;
if ( F_44 ( V_5 ) ) {
F_45 ( V_59 , 0 ) ;
F_46 ( & V_25 -> V_62 ) ;
F_47 ( & V_59 -> V_63 ) ;
if ( V_56 )
V_52 -> V_64 ++ ;
else
V_52 -> V_65 ++ ;
V_52 -> V_55 = 1 ;
V_61 = 1 ;
F_40 ( V_5 ) ;
}
if ( V_59 ) {
F_48 ( & V_25 -> V_66 ) ;
if ( V_59 -> V_67 ) {
F_49 ( V_25 , V_59 ) ;
} else if ( V_61 ) {
V_5 -> V_60 = NULL ;
F_50 ( V_68 , V_59 ) ;
}
F_51 ( & V_25 -> V_66 ) ;
}
F_30 ( V_5 ) ;
F_52 ( V_5 ) ;
}
void F_53 ( struct V_69 * V_70 , T_1 V_71 , T_2 V_72 )
{
struct V_24 * V_25 = F_54 ( & V_70 -> V_73 ) ;
struct V_4 * V_5 ;
while ( V_72 ) {
V_5 = F_19 ( V_70 -> V_74 , V_71 , V_75 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_55 ( V_25 ) ;
F_42 ( V_5 , V_53 -> V_54 , 1 ) ;
F_56 ( V_25 ) ;
F_12 ( V_5 ) ;
F_40 ( V_5 ) ;
}
V_71 ++ ;
V_72 -- ;
}
}
int F_57 ( struct V_69 * V_70 , int V_76 , T_1 V_77 ,
struct V_4 * * V_43 )
{
struct V_24 * V_25 = F_54 ( & V_70 -> V_73 ) ;
struct V_18 * V_19 = V_70 -> V_74 ;
struct V_4 * V_5 ;
int V_78 = 0 ;
T_2 V_79 = V_76 ? V_80 : V_81 ;
V_78 = F_34 ( V_19 , V_77 , V_50 , & V_5 ) ;
if ( V_78 == 0 && F_58 ( V_25 , V_5 , V_79 ) ) {
F_40 ( V_5 ) ;
V_78 = - V_46 ;
}
* V_43 = V_5 ;
return V_78 ;
}
struct V_4 * F_59 ( struct V_18 * V_19 , T_1 V_82 , T_2 V_83 )
{
struct V_24 * V_25 = V_19 -> V_26 ;
struct V_4 * V_84 , * V_5 ;
T_2 V_85 = F_60 ( V_25 , V_86 ) >>
V_25 -> V_32 . V_33 ;
F_2 ( ! V_83 ) ;
if ( V_85 < 1 )
V_85 = 1 ;
if ( V_83 > V_85 )
V_83 = V_85 ;
V_84 = F_19 ( V_19 , V_82 , V_41 ) ;
if ( F_37 ( V_84 ) )
goto V_87;
if ( ! F_61 ( V_84 ) )
F_62 ( V_49 | V_9 , 1 , & V_84 ) ;
V_82 ++ ;
V_83 -- ;
while ( V_83 ) {
V_5 = F_19 ( V_19 , V_82 , V_41 ) ;
if ( ! F_37 ( V_5 ) && ! F_61 ( V_5 ) )
F_62 ( V_88 | V_9 , 1 , & V_5 ) ;
F_40 ( V_5 ) ;
V_82 ++ ;
V_83 -- ;
if ( ! F_61 ( V_84 ) && F_37 ( V_84 ) )
goto V_87;
}
F_38 ( V_84 ) ;
V_87:
return V_84 ;
}
