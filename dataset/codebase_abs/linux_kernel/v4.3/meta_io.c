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
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
unsigned int V_28 ;
unsigned long V_29 ;
unsigned int V_30 ;
if ( V_23 == NULL )
V_23 = & V_25 -> V_31 ;
V_28 = V_32 - V_25 -> V_33 . V_34 ;
V_29 = V_20 >> V_28 ;
V_30 = V_20 - ( V_29 << V_28 ) ;
if ( V_21 ) {
for (; ; ) {
V_1 = F_21 ( V_23 , V_29 ) ;
if ( V_1 )
break;
F_22 () ;
}
} else {
V_1 = F_23 ( V_23 , V_29 ,
V_35 | V_36 ) ;
if ( ! V_1 )
return NULL ;
}
if ( ! F_4 ( V_1 ) )
F_24 ( V_1 , V_25 -> V_33 . V_37 , 0 ) ;
for ( V_5 = F_5 ( V_1 ) ; V_30 -- ; V_5 = V_5 -> V_16 )
;
F_25 ( V_5 ) ;
if ( ! F_6 ( V_5 ) )
F_26 ( V_5 , V_25 -> V_38 , V_20 ) ;
F_17 ( V_1 ) ;
F_27 ( V_1 ) ;
return V_5 ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_39 * V_40 = (struct V_39 * ) V_5 -> V_41 ;
F_7 ( V_5 ) ;
F_29 ( V_5 ) ;
F_30 ( V_5 ) ;
F_12 ( V_5 ) ;
V_40 -> V_42 = F_31 ( V_43 ) ;
}
struct V_4 * F_32 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_4 * V_5 ;
V_5 = F_19 ( V_19 , V_20 , V_44 ) ;
F_28 ( V_5 ) ;
return V_5 ;
}
int F_33 ( struct V_18 * V_19 , T_1 V_20 , int V_45 ,
struct V_4 * * V_46 )
{
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_4 * V_5 ;
if ( F_34 ( F_35 ( V_47 , & V_25 -> V_48 ) ) ) {
* V_46 = NULL ;
return - V_49 ;
}
* V_46 = V_5 = F_19 ( V_19 , V_20 , V_44 ) ;
F_7 ( V_5 ) ;
if ( F_36 ( V_5 ) ) {
F_12 ( V_5 ) ;
return 0 ;
}
V_5 -> V_50 = V_51 ;
F_25 ( V_5 ) ;
F_16 ( V_52 | V_9 | V_10 , V_5 ) ;
if ( ! ( V_45 & V_53 ) )
return 0 ;
F_37 ( V_5 ) ;
if ( F_34 ( ! F_36 ( V_5 ) ) ) {
struct V_54 * V_55 = V_56 -> V_57 ;
if ( V_55 && V_55 -> V_58 )
F_38 ( V_25 , V_5 ) ;
F_39 ( V_5 ) ;
* V_46 = NULL ;
return - V_49 ;
}
return 0 ;
}
int F_40 ( struct V_24 * V_25 , struct V_4 * V_5 )
{
if ( F_34 ( F_35 ( V_47 , & V_25 -> V_48 ) ) )
return - V_49 ;
F_37 ( V_5 ) ;
if ( ! F_36 ( V_5 ) ) {
struct V_54 * V_55 = V_56 -> V_57 ;
if ( V_55 && V_55 -> V_58 )
F_38 ( V_25 , V_5 ) ;
return - V_49 ;
}
if ( F_34 ( F_35 ( V_47 , & V_25 -> V_48 ) ) )
return - V_49 ;
return 0 ;
}
void F_41 ( struct V_4 * V_5 , struct V_54 * V_55 , int V_59 )
{
struct V_22 * V_23 = V_5 -> V_60 -> V_23 ;
struct V_24 * V_25 = F_42 ( V_23 ) ;
struct V_61 * V_62 = V_5 -> V_63 ;
int V_64 = 0 ;
if ( F_43 ( V_5 ) ) {
F_44 ( V_62 , 0 ) ;
F_45 ( & V_25 -> V_65 ) ;
F_46 ( & V_62 -> V_66 ) ;
if ( V_59 )
V_55 -> V_67 ++ ;
else
V_55 -> V_68 ++ ;
V_55 -> V_58 = 1 ;
V_64 = 1 ;
F_39 ( V_5 ) ;
}
if ( V_62 ) {
F_47 ( & V_25 -> V_69 ) ;
if ( V_62 -> V_70 ) {
F_48 ( V_25 , V_62 ) ;
} else if ( V_64 ) {
V_5 -> V_63 = NULL ;
F_49 ( V_71 , V_62 ) ;
}
F_50 ( & V_25 -> V_69 ) ;
}
F_29 ( V_5 ) ;
F_51 ( V_5 ) ;
}
void F_52 ( struct V_72 * V_73 , T_1 V_74 , T_2 V_75 )
{
struct V_24 * V_25 = F_53 ( & V_73 -> V_76 ) ;
struct V_4 * V_5 ;
while ( V_75 ) {
V_5 = F_19 ( V_73 -> V_77 , V_74 , V_78 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_54 ( V_25 ) ;
F_41 ( V_5 , V_56 -> V_57 , 1 ) ;
F_55 ( V_25 ) ;
F_12 ( V_5 ) ;
F_39 ( V_5 ) ;
}
V_74 ++ ;
V_75 -- ;
}
}
int F_56 ( struct V_72 * V_73 , int V_79 , T_1 V_80 ,
struct V_4 * * V_46 )
{
struct V_24 * V_25 = F_53 ( & V_73 -> V_76 ) ;
struct V_18 * V_19 = V_73 -> V_77 ;
struct V_4 * V_5 ;
int V_81 = 0 ;
T_2 V_82 = V_79 ? V_83 : V_84 ;
V_81 = F_33 ( V_19 , V_80 , V_53 , & V_5 ) ;
if ( V_81 == 0 && F_57 ( V_25 , V_5 , V_82 ) ) {
F_39 ( V_5 ) ;
V_81 = - V_49 ;
}
* V_46 = V_5 ;
return V_81 ;
}
struct V_4 * F_58 ( struct V_18 * V_19 , T_1 V_85 , T_2 V_86 )
{
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_4 * V_87 , * V_5 ;
T_2 V_88 = F_59 ( V_25 , V_89 ) >>
V_25 -> V_33 . V_34 ;
F_2 ( ! V_86 ) ;
if ( V_88 < 1 )
V_88 = 1 ;
if ( V_86 > V_88 )
V_86 = V_88 ;
V_87 = F_19 ( V_19 , V_85 , V_44 ) ;
if ( F_36 ( V_87 ) )
goto V_90;
if ( ! F_60 ( V_87 ) )
F_61 ( V_52 | V_9 , 1 , & V_87 ) ;
V_85 ++ ;
V_86 -- ;
while ( V_86 ) {
V_5 = F_19 ( V_19 , V_85 , V_44 ) ;
if ( ! F_36 ( V_5 ) && ! F_60 ( V_5 ) )
F_61 ( V_91 | V_9 , 1 , & V_5 ) ;
F_39 ( V_5 ) ;
V_85 ++ ;
V_86 -- ;
if ( ! F_60 ( V_87 ) && F_36 ( V_87 ) )
goto V_90;
}
F_37 ( V_87 ) ;
V_90:
return V_87 ;
}
