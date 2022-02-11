static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
int V_7 = 0 ;
int V_8 = V_9 |
( V_3 -> V_10 == V_11 ? V_12 : V_13 ) ;
F_2 ( ! F_3 ( V_1 ) ) ;
F_2 ( ! F_4 ( V_1 ) ) ;
V_6 = F_5 ( V_1 ) ;
V_5 = V_6 ;
do {
if ( ! F_6 ( V_5 ) )
continue;
if ( V_3 -> V_10 != V_14 ) {
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
} while ( ( V_5 = V_5 -> V_15 ) != V_6 );
F_2 ( F_13 ( V_1 ) ) ;
F_14 ( V_1 ) ;
do {
struct V_4 * V_16 = V_5 -> V_15 ;
if ( F_15 ( V_5 ) ) {
F_16 ( V_8 , V_5 ) ;
V_7 ++ ;
}
V_5 = V_16 ;
} while ( V_5 != V_6 );
F_17 ( V_1 ) ;
if ( V_7 == 0 )
F_18 ( V_1 ) ;
return 0 ;
}
void F_19 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_20 ( V_18 ) ;
int error ;
F_21 ( V_20 ) ;
error = F_22 ( V_20 ) ;
if ( error )
F_23 ( V_18 -> V_21 ) ;
}
struct V_4 * F_24 ( struct V_17 * V_18 , T_1 V_22 , int V_23 )
{
struct V_19 * V_20 = F_20 ( V_18 ) ;
struct V_24 * V_25 = V_18 -> V_21 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
unsigned int V_26 ;
unsigned long V_27 ;
unsigned int V_28 ;
V_26 = V_29 - V_25 -> V_30 . V_31 ;
V_27 = V_22 >> V_26 ;
V_28 = V_22 - ( V_27 << V_26 ) ;
if ( V_23 ) {
for (; ; ) {
V_1 = F_25 ( V_20 , V_27 ) ;
if ( V_1 )
break;
F_26 () ;
}
} else {
V_1 = F_27 ( V_20 , V_27 ) ;
if ( ! V_1 )
return NULL ;
}
if ( ! F_4 ( V_1 ) )
F_28 ( V_1 , V_25 -> V_30 . V_32 , 0 ) ;
for ( V_5 = F_5 ( V_1 ) ; V_28 -- ; V_5 = V_5 -> V_15 )
;
F_29 ( V_5 ) ;
if ( ! F_6 ( V_5 ) )
F_30 ( V_5 , V_25 -> V_33 , V_22 ) ;
F_17 ( V_1 ) ;
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
return V_5 ;
}
static void F_33 ( struct V_4 * V_5 )
{
struct V_34 * V_35 = (struct V_34 * ) V_5 -> V_36 ;
F_7 ( V_5 ) ;
F_34 ( V_5 ) ;
F_35 ( V_5 ) ;
F_12 ( V_5 ) ;
V_35 -> V_37 = F_36 ( V_38 ) ;
}
struct V_4 * F_37 ( struct V_17 * V_18 , T_1 V_22 )
{
struct V_4 * V_5 ;
V_5 = F_24 ( V_18 , V_22 , V_39 ) ;
F_33 ( V_5 ) ;
return V_5 ;
}
int F_38 ( struct V_17 * V_18 , T_1 V_22 , int V_40 ,
struct V_4 * * V_41 )
{
struct V_24 * V_25 = V_18 -> V_21 ;
struct V_4 * V_5 ;
if ( F_39 ( F_40 ( V_42 , & V_25 -> V_43 ) ) )
return - V_44 ;
* V_41 = V_5 = F_24 ( V_18 , V_22 , V_39 ) ;
F_7 ( V_5 ) ;
if ( F_41 ( V_5 ) ) {
F_12 ( V_5 ) ;
return 0 ;
}
V_5 -> V_45 = V_46 ;
F_29 ( V_5 ) ;
F_16 ( V_47 | V_9 , V_5 ) ;
if ( ! ( V_40 & V_48 ) )
return 0 ;
F_42 ( V_5 ) ;
if ( F_39 ( ! F_41 ( V_5 ) ) ) {
struct V_49 * V_50 = V_51 -> V_52 ;
if ( V_50 && V_50 -> V_53 )
F_43 ( V_25 , V_5 ) ;
F_44 ( V_5 ) ;
return - V_44 ;
}
return 0 ;
}
int F_45 ( struct V_24 * V_25 , struct V_4 * V_5 )
{
if ( F_39 ( F_40 ( V_42 , & V_25 -> V_43 ) ) )
return - V_44 ;
F_42 ( V_5 ) ;
if ( ! F_41 ( V_5 ) ) {
struct V_49 * V_50 = V_51 -> V_52 ;
if ( V_50 && V_50 -> V_53 )
F_43 ( V_25 , V_5 ) ;
return - V_44 ;
}
if ( F_39 ( F_40 ( V_42 , & V_25 -> V_43 ) ) )
return - V_44 ;
return 0 ;
}
void F_46 ( struct V_17 * V_18 , struct V_4 * V_5 ,
int V_54 )
{
struct V_55 * V_56 ;
if ( V_54 )
F_47 ( V_5 -> V_57 ) ;
if ( V_5 -> V_58 ) {
if ( V_54 )
F_17 ( V_5 -> V_57 ) ;
return;
}
V_56 = F_48 ( V_59 , V_60 | V_61 ) ;
V_56 -> V_62 = V_5 ;
V_56 -> V_63 = V_18 ;
F_49 ( & V_56 -> V_64 ) ;
if ( V_54 )
F_50 ( & V_56 -> V_65 , & V_66 ) ;
else
F_50 ( & V_56 -> V_65 , & V_67 ) ;
V_5 -> V_58 = V_56 ;
if ( V_54 )
F_17 ( V_5 -> V_57 ) ;
}
void F_51 ( struct V_4 * V_5 , struct V_49 * V_50 , int V_54 )
{
struct V_19 * V_20 = V_5 -> V_57 -> V_20 ;
struct V_24 * V_25 = F_52 ( V_20 ) ;
struct V_55 * V_56 = V_5 -> V_58 ;
if ( F_53 ( V_5 ) ) {
F_54 ( V_56 , 0 ) ;
F_55 ( & V_25 -> V_68 ) ;
F_56 ( & V_56 -> V_65 . V_69 ) ;
if ( V_54 ) {
F_57 ( V_25 , V_25 -> V_70 ) ;
V_25 -> V_70 -- ;
V_50 -> V_71 ++ ;
} else {
F_57 ( V_25 , V_25 -> V_72 ) ;
V_25 -> V_72 -- ;
V_50 -> V_73 ++ ;
}
V_50 -> V_53 = 1 ;
F_44 ( V_5 ) ;
}
if ( V_56 ) {
F_58 ( & V_25 -> V_74 ) ;
if ( V_56 -> V_75 ) {
F_59 ( V_56 ) ;
V_5 -> V_58 = NULL ;
V_56 -> V_62 = NULL ;
V_56 -> V_76 = V_5 -> V_77 ;
F_60 ( V_25 , V_56 ) ;
}
F_61 ( & V_25 -> V_74 ) ;
}
F_34 ( V_5 ) ;
F_62 ( V_5 ) ;
}
void F_63 ( struct V_78 * V_79 , T_1 V_80 , T_2 V_81 )
{
struct V_24 * V_25 = F_64 ( & V_79 -> V_82 ) ;
struct V_4 * V_5 ;
while ( V_81 ) {
V_5 = F_24 ( V_79 -> V_83 , V_80 , V_84 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_65 ( V_25 ) ;
F_51 ( V_5 , V_51 -> V_52 , 1 ) ;
F_66 ( V_25 ) ;
F_12 ( V_5 ) ;
F_44 ( V_5 ) ;
}
V_80 ++ ;
V_81 -- ;
}
}
int F_67 ( struct V_78 * V_79 , int V_85 , T_1 V_86 ,
int V_87 , struct V_4 * * V_41 )
{
struct V_24 * V_25 = F_64 ( & V_79 -> V_82 ) ;
struct V_17 * V_18 = V_79 -> V_83 ;
struct V_4 * V_5 ;
int V_88 = 0 ;
if ( V_87 ) {
F_2 ( V_85 == 0 ) ;
V_5 = F_37 ( V_18 , V_86 ) ;
F_68 ( V_79 -> V_83 , V_5 , 1 ) ;
F_69 ( V_5 , V_89 , V_90 ) ;
F_70 ( V_5 , sizeof( struct V_34 ) ) ;
} else {
T_2 V_91 = V_85 ? V_89 : V_92 ;
V_88 = F_38 ( V_18 , V_86 , V_48 , & V_5 ) ;
if ( V_88 == 0 && F_71 ( V_25 , V_5 , V_91 ) ) {
F_44 ( V_5 ) ;
V_88 = - V_44 ;
}
}
* V_41 = V_5 ;
return V_88 ;
}
struct V_4 * F_72 ( struct V_17 * V_18 , T_1 V_93 , T_2 V_94 )
{
struct V_24 * V_25 = V_18 -> V_21 ;
struct V_4 * V_95 , * V_5 ;
T_2 V_96 = F_73 ( V_25 , V_97 ) >>
V_25 -> V_30 . V_31 ;
F_2 ( ! V_94 ) ;
if ( V_96 < 1 )
V_96 = 1 ;
if ( V_94 > V_96 )
V_94 = V_96 ;
V_95 = F_24 ( V_18 , V_93 , V_39 ) ;
if ( F_41 ( V_95 ) )
goto V_98;
if ( ! F_74 ( V_95 ) )
F_75 ( V_47 | V_9 , 1 , & V_95 ) ;
V_93 ++ ;
V_94 -- ;
while ( V_94 ) {
V_5 = F_24 ( V_18 , V_93 , V_39 ) ;
if ( ! F_41 ( V_5 ) && ! F_74 ( V_5 ) )
F_75 ( V_99 , 1 , & V_5 ) ;
F_44 ( V_5 ) ;
V_93 ++ ;
V_94 -- ;
if ( ! F_74 ( V_95 ) && F_41 ( V_95 ) )
goto V_98;
}
F_42 ( V_95 ) ;
V_98:
return V_95 ;
}
