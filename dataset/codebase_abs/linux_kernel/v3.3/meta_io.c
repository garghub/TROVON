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
if ( F_39 ( F_40 ( V_43 , & V_26 -> V_44 ) ) )
return - V_45 ;
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
void F_46 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int V_55 )
{
struct V_56 * V_57 ;
if ( V_55 )
F_47 ( V_5 -> V_58 ) ;
if ( V_5 -> V_59 ) {
if ( V_55 )
F_17 ( V_5 -> V_58 ) ;
return;
}
V_57 = F_48 ( V_60 , V_61 | V_62 ) ;
V_57 -> V_63 = V_5 ;
V_57 -> V_64 = V_19 ;
F_49 ( & V_57 -> V_65 ) ;
if ( V_55 )
F_50 ( & V_57 -> V_66 , & V_67 ) ;
else
F_50 ( & V_57 -> V_66 , & V_68 ) ;
V_5 -> V_59 = V_57 ;
if ( V_55 )
F_17 ( V_5 -> V_58 ) ;
}
void F_51 ( struct V_4 * V_5 , struct V_50 * V_51 , int V_55 )
{
struct V_20 * V_21 = V_5 -> V_58 -> V_21 ;
struct V_25 * V_26 = F_52 ( V_21 ) ;
struct V_56 * V_57 = V_5 -> V_59 ;
if ( F_53 ( V_5 ) ) {
F_54 ( V_57 , 0 ) ;
F_55 ( & V_26 -> V_69 ) ;
F_56 ( & V_57 -> V_66 . V_70 ) ;
if ( V_55 ) {
F_57 ( V_26 , V_26 -> V_71 ) ;
V_26 -> V_71 -- ;
V_51 -> V_72 ++ ;
} else {
F_57 ( V_26 , V_26 -> V_73 ) ;
V_26 -> V_73 -- ;
V_51 -> V_74 ++ ;
}
V_51 -> V_54 = 1 ;
F_44 ( V_5 ) ;
}
if ( V_57 ) {
F_58 ( & V_26 -> V_75 ) ;
if ( V_57 -> V_76 ) {
F_59 ( V_57 ) ;
V_5 -> V_59 = NULL ;
V_57 -> V_63 = NULL ;
V_57 -> V_77 = V_5 -> V_78 ;
F_60 ( V_26 , V_57 ) ;
}
F_61 ( & V_26 -> V_75 ) ;
}
F_34 ( V_5 ) ;
F_62 ( V_5 ) ;
}
void F_63 ( struct V_79 * V_80 , T_1 V_81 , T_2 V_82 )
{
struct V_25 * V_26 = F_64 ( & V_80 -> V_83 ) ;
struct V_4 * V_5 ;
while ( V_82 ) {
V_5 = F_24 ( V_80 -> V_84 , V_81 , V_85 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_65 ( V_26 ) ;
F_51 ( V_5 , V_52 -> V_53 , 1 ) ;
F_66 ( V_26 ) ;
F_12 ( V_5 ) ;
F_44 ( V_5 ) ;
}
V_81 ++ ;
V_82 -- ;
}
}
int F_67 ( struct V_79 * V_80 , int V_86 , T_1 V_87 ,
int V_88 , struct V_4 * * V_42 )
{
struct V_25 * V_26 = F_64 ( & V_80 -> V_83 ) ;
struct V_18 * V_19 = V_80 -> V_84 ;
struct V_4 * V_5 ;
int V_89 = 0 ;
if ( V_88 ) {
F_2 ( V_86 == 0 ) ;
V_5 = F_37 ( V_19 , V_87 ) ;
F_68 ( V_80 -> V_84 , V_5 , 1 ) ;
F_69 ( V_5 , V_90 , V_91 ) ;
F_70 ( V_5 , sizeof( struct V_35 ) ) ;
} else {
T_2 V_92 = V_86 ? V_90 : V_93 ;
V_89 = F_38 ( V_19 , V_87 , V_49 , & V_5 ) ;
if ( V_89 == 0 && F_71 ( V_26 , V_5 , V_92 ) ) {
F_44 ( V_5 ) ;
V_89 = - V_45 ;
}
}
* V_42 = V_5 ;
return V_89 ;
}
struct V_4 * F_72 ( struct V_18 * V_19 , T_1 V_94 , T_2 V_95 )
{
struct V_25 * V_26 = V_19 -> V_22 ;
struct V_4 * V_96 , * V_5 ;
T_2 V_97 = F_73 ( V_26 , V_98 ) >>
V_26 -> V_31 . V_32 ;
F_2 ( ! V_95 ) ;
if ( V_97 < 1 )
V_97 = 1 ;
if ( V_95 > V_97 )
V_95 = V_97 ;
V_96 = F_24 ( V_19 , V_94 , V_40 ) ;
if ( F_41 ( V_96 ) )
goto V_99;
if ( ! F_74 ( V_96 ) )
F_75 ( V_48 | V_9 , 1 , & V_96 ) ;
V_94 ++ ;
V_95 -- ;
while ( V_95 ) {
V_5 = F_24 ( V_19 , V_94 , V_40 ) ;
if ( ! F_41 ( V_5 ) && ! F_74 ( V_5 ) )
F_75 ( V_100 | V_9 , 1 , & V_5 ) ;
F_44 ( V_5 ) ;
V_94 ++ ;
V_95 -- ;
if ( ! F_74 ( V_96 ) && F_41 ( V_96 ) )
goto V_99;
}
F_42 ( V_96 ) ;
V_99:
return V_96 ;
}
