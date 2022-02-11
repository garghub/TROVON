static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , int type )
{
if ( type == V_4 ) {
if ( V_3 -> V_5 < V_2 -> V_5 )
return - 1 ;
if ( V_3 -> V_5 > V_2 -> V_5 )
return 1 ;
} else {
if ( V_3 -> V_6 < V_2 -> V_6 )
return - 1 ;
if ( V_3 -> V_6 > V_2 -> V_6 )
return 1 ;
}
return 0 ;
}
static int F_2 ( struct V_7 * V_2 ,
struct V_7 * V_3 )
{
if ( V_3 -> V_8 . type == V_9 ) {
if ( V_3 -> V_5 < V_2 -> V_5 )
return - 1 ;
if ( V_3 -> V_5 > V_2 -> V_5 )
return 1 ;
if ( V_3 -> V_10 < V_2 -> V_10 )
return - 1 ;
if ( V_3 -> V_10 > V_2 -> V_10 )
return 1 ;
if ( V_3 -> V_11 < V_2 -> V_11 )
return - 1 ;
if ( V_3 -> V_11 > V_2 -> V_11 )
return 1 ;
} else {
if ( V_3 -> V_6 < V_2 -> V_6 )
return - 1 ;
if ( V_3 -> V_6 > V_2 -> V_6 )
return 1 ;
}
return 0 ;
}
static struct V_12 * F_3 ( struct V_13 * V_5 ,
struct V_14 * V_8 )
{
struct V_14 * * V_15 = & V_5 -> V_14 ;
struct V_14 * V_16 = NULL ;
struct V_12 * V_17 ;
struct V_12 * V_18 ;
T_1 V_19 ;
V_18 = F_4 ( V_8 , struct V_12 , V_20 ) ;
V_19 = V_18 -> V_8 . V_19 ;
while ( * V_15 ) {
V_16 = * V_15 ;
V_17 = F_4 ( V_16 , struct V_12 ,
V_20 ) ;
if ( V_19 < V_17 -> V_8 . V_19 )
V_15 = & ( * V_15 ) -> V_21 ;
else if ( V_19 > V_17 -> V_8 . V_19 )
V_15 = & ( * V_15 ) -> V_22 ;
else
return V_17 ;
}
F_5 ( V_8 , V_16 , V_15 ) ;
F_6 ( V_8 , V_5 ) ;
return NULL ;
}
static struct V_12 *
F_7 ( struct V_13 * V_5 , T_1 V_19 ,
int V_23 )
{
struct V_14 * V_24 ;
struct V_12 * V_17 ;
V_24 = V_5 -> V_14 ;
V_17 = NULL ;
while ( V_24 ) {
V_17 = F_4 ( V_24 , struct V_12 , V_20 ) ;
if ( V_19 < V_17 -> V_8 . V_19 )
V_24 = V_24 -> V_21 ;
else if ( V_19 > V_17 -> V_8 . V_19 )
V_24 = V_24 -> V_22 ;
else
return V_17 ;
}
if ( V_17 && V_23 ) {
if ( V_19 > V_17 -> V_8 . V_19 ) {
V_24 = F_8 ( & V_17 -> V_20 ) ;
if ( ! V_24 )
V_24 = F_9 ( V_5 ) ;
V_17 = F_4 ( V_24 , struct V_12 ,
V_20 ) ;
return V_17 ;
}
return V_17 ;
}
return NULL ;
}
int F_10 ( struct V_25 * V_26 ,
struct V_12 * V_27 )
{
struct V_28 * V_29 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_11 ( & V_29 -> V_31 ) ;
if ( F_12 ( & V_27 -> V_32 ) )
return 0 ;
F_13 ( & V_27 -> V_8 . V_33 ) ;
F_14 ( & V_29 -> V_31 ) ;
F_15 ( & V_27 -> V_32 ) ;
F_16 ( & V_29 -> V_31 ) ;
if ( ! V_27 -> V_8 . V_34 ) {
F_17 ( & V_27 -> V_32 ) ;
F_18 ( & V_27 -> V_8 ) ;
return - V_35 ;
}
F_18 ( & V_27 -> V_8 ) ;
return 0 ;
}
static inline void F_19 ( struct V_25 * V_26 ,
struct V_28 * V_29 ,
struct V_12 * V_27 ,
struct V_36 * V_37 )
{
if ( F_20 ( V_37 ) ) {
V_27 = F_21 ( V_37 ) ;
F_22 ( & V_27 -> V_20 , & V_29 -> V_38 ) ;
} else {
F_11 ( & V_27 -> V_31 ) ;
F_23 ( & V_37 -> V_39 ) ;
}
V_37 -> V_34 = 0 ;
F_18 ( V_37 ) ;
F_24 ( & V_29 -> V_40 ) ;
if ( V_26 -> V_41 )
V_26 -> V_41 -- ;
}
static bool F_25 ( struct V_25 * V_26 ,
struct V_28 * V_29 ,
struct V_12 * V_27 ,
struct V_36 * V_37 ,
T_1 V_42 )
{
struct V_36 * V_43 ;
bool V_44 = false ;
V_43 = F_26 ( & V_27 -> V_45 , struct V_36 ,
V_39 ) ;
while ( ! V_44 && & V_43 -> V_39 != & V_27 -> V_45 ) {
int V_46 ;
struct V_36 * V_47 ;
V_47 = F_27 ( V_43 , V_39 ) ;
if ( V_43 == V_37 )
goto V_43;
if ( V_42 && V_43 -> V_42 >= V_42 )
goto V_43;
if ( V_43 -> type != V_37 -> type )
goto V_43;
if ( ( V_37 -> type == V_4 ||
V_37 -> type == V_48 ) &&
F_1 ( F_28 ( V_37 ) ,
F_28 ( V_43 ) ,
V_37 -> type ) )
goto V_43;
if ( ( V_37 -> type == V_9 ||
V_37 -> type == V_49 ) &&
F_2 ( F_29 ( V_37 ) ,
F_29 ( V_43 ) ) )
goto V_43;
if ( V_37 -> V_50 == V_43 -> V_50 ) {
V_46 = V_43 -> V_51 ;
} else {
if ( V_37 -> V_51 < V_43 -> V_51 ) {
F_30 ( V_37 , V_43 ) ;
V_44 = true ;
}
V_46 = - V_43 -> V_51 ;
}
F_19 ( V_26 , V_29 , V_27 , V_43 ) ;
V_37 -> V_51 += V_46 ;
if ( V_37 -> V_51 == 0 ) {
F_19 ( V_26 , V_29 , V_27 , V_37 ) ;
V_44 = true ;
} else {
F_31 ( V_37 -> type == V_4 ||
V_37 -> type == V_48 ) ;
}
V_43:
V_43 = V_47 ;
}
return V_44 ;
}
void F_32 ( struct V_25 * V_26 ,
struct V_52 * V_53 ,
struct V_28 * V_29 ,
struct V_12 * V_27 )
{
struct V_36 * V_37 ;
T_1 V_42 = 0 ;
F_11 ( & V_27 -> V_31 ) ;
if ( F_33 ( & V_27 -> V_45 ) )
return;
if ( V_27 -> V_54 )
return;
F_16 ( & V_53 -> V_55 ) ;
if ( ! F_33 ( & V_53 -> V_56 ) ) {
struct V_57 * V_58 ;
V_58 = F_26 ( & V_53 -> V_56 ,
struct V_57 , V_39 ) ;
V_42 = V_58 -> V_42 ;
}
F_14 ( & V_53 -> V_55 ) ;
V_37 = F_26 ( & V_27 -> V_45 , struct V_36 ,
V_39 ) ;
while ( & V_37 -> V_39 != & V_27 -> V_45 ) {
if ( V_42 && V_37 -> V_42 >= V_42 )
goto V_43;
if ( F_25 ( V_26 , V_29 , V_27 , V_37 , V_42 ) ) {
if ( F_33 ( & V_27 -> V_45 ) )
break;
V_37 = F_26 ( & V_27 -> V_45 ,
struct V_36 ,
V_39 ) ;
continue;
}
V_43:
V_37 = F_27 ( V_37 , V_39 ) ;
}
}
int F_34 ( struct V_52 * V_53 ,
struct V_28 * V_29 ,
T_1 V_42 )
{
struct V_57 * V_58 ;
int V_59 = 0 ;
F_16 ( & V_53 -> V_55 ) ;
if ( ! F_33 ( & V_53 -> V_56 ) ) {
V_58 = F_26 ( & V_53 -> V_56 ,
struct V_57 , V_39 ) ;
if ( V_42 >= V_58 -> V_42 ) {
F_35 ( L_1 ,
( V_60 ) ( V_42 >> 32 ) , ( V_60 ) V_42 ,
( V_60 ) ( V_58 -> V_42 >> 32 ) , ( V_60 ) V_58 -> V_42 ,
V_29 ) ;
V_59 = 1 ;
}
}
F_14 ( & V_53 -> V_55 ) ;
return V_59 ;
}
struct V_12 *
F_36 ( struct V_25 * V_26 )
{
struct V_28 * V_29 ;
struct V_12 * V_27 ;
T_1 V_61 ;
bool V_62 = false ;
V_29 = & V_26 -> V_30 -> V_29 ;
V_63:
V_61 = V_29 -> V_64 ;
V_27 = F_7 ( & V_29 -> V_38 , V_61 , 1 ) ;
if ( ! V_27 && ! V_62 ) {
V_29 -> V_64 = 0 ;
V_61 = 0 ;
V_62 = true ;
V_27 = F_7 ( & V_29 -> V_38 , V_61 , 1 ) ;
if ( ! V_27 )
return NULL ;
} else if ( ! V_27 && V_62 ) {
return NULL ;
}
while ( V_27 -> V_65 ) {
struct V_14 * V_8 ;
V_8 = F_8 ( & V_27 -> V_20 ) ;
if ( ! V_8 ) {
if ( V_62 )
return NULL ;
V_29 -> V_64 = 0 ;
V_61 = 0 ;
V_62 = true ;
goto V_63;
}
V_27 = F_4 ( V_8 , struct V_12 ,
V_20 ) ;
}
V_27 -> V_65 = 1 ;
F_31 ( V_29 -> V_66 == 0 ) ;
V_29 -> V_66 -- ;
V_29 -> V_64 = V_27 -> V_8 . V_19 +
V_27 -> V_8 . V_67 ;
return V_27 ;
}
static int
F_37 ( struct V_25 * V_26 ,
struct V_28 * V_5 ,
struct V_12 * V_68 ,
struct V_36 * V_37 )
{
struct V_36 * V_69 ;
int V_46 ;
int V_59 = 0 ;
F_16 ( & V_68 -> V_31 ) ;
if ( F_33 ( & V_68 -> V_45 ) )
goto V_70;
V_69 = F_38 ( V_68 -> V_45 . V_71 , struct V_36 ,
V_39 ) ;
if ( V_69 -> type != V_37 -> type || V_69 -> V_42 != V_37 -> V_42 )
goto V_70;
if ( ( V_69 -> type == V_4 ||
V_69 -> type == V_48 ) &&
F_1 ( F_28 ( V_69 ) ,
F_28 ( V_37 ) ,
V_37 -> type ) )
goto V_70;
if ( ( V_69 -> type == V_9 ||
V_69 -> type == V_49 ) &&
F_2 ( F_29 ( V_69 ) ,
F_29 ( V_37 ) ) )
goto V_70;
V_59 = 1 ;
if ( V_69 -> V_50 == V_37 -> V_50 ) {
V_46 = V_37 -> V_51 ;
} else {
if ( V_69 -> V_51 < V_37 -> V_51 ) {
V_69 -> V_50 = V_37 -> V_50 ;
V_46 = - V_69 -> V_51 ;
V_69 -> V_51 = V_37 -> V_51 ;
} else
V_46 = - V_37 -> V_51 ;
}
V_69 -> V_51 += V_46 ;
if ( V_69 -> V_51 == 0 )
F_19 ( V_26 , V_5 , V_68 , V_69 ) ;
F_14 ( & V_68 -> V_31 ) ;
return V_59 ;
V_70:
F_39 ( & V_37 -> V_39 , & V_68 -> V_45 ) ;
F_13 ( & V_5 -> V_40 ) ;
V_26 -> V_41 ++ ;
F_14 ( & V_68 -> V_31 ) ;
return V_59 ;
}
static T_2 void
F_40 ( struct V_28 * V_29 ,
struct V_36 * V_72 ,
struct V_36 * V_73 )
{
struct V_12 * V_74 ;
struct V_12 * V_37 ;
int V_75 ;
V_74 = F_21 ( V_72 ) ;
V_37 = F_21 ( V_73 ) ;
F_41 ( V_74 -> V_54 != V_37 -> V_54 ) ;
F_16 ( & V_74 -> V_31 ) ;
if ( V_37 -> V_76 ) {
V_74 -> V_76 = V_37 -> V_76 ;
V_72 -> V_67 = V_73 -> V_67 ;
}
if ( V_37 -> V_77 ) {
if ( ! V_74 -> V_77 ) {
V_74 -> V_77 = V_37 -> V_77 ;
} else {
if ( V_37 -> V_77 -> V_78 ) {
memcpy ( & V_74 -> V_77 -> V_79 ,
& V_37 -> V_77 -> V_79 ,
sizeof( V_37 -> V_77 -> V_79 ) ) ;
V_74 -> V_77 -> V_78 = true ;
}
if ( V_37 -> V_77 -> V_80 ) {
V_74 -> V_77 -> V_81 |=
V_37 -> V_77 -> V_81 ;
V_74 -> V_77 -> V_80 = true ;
}
F_42 ( V_37 -> V_77 ) ;
}
}
V_75 = V_74 -> V_82 ;
V_72 -> V_51 += V_73 -> V_51 ;
V_74 -> V_82 += V_73 -> V_51 ;
if ( V_74 -> V_54 ) {
if ( V_74 -> V_82 >= 0 && V_75 < 0 )
V_29 -> V_83 -= V_72 -> V_67 ;
if ( V_74 -> V_82 < 0 && V_75 >= 0 )
V_29 -> V_83 += V_72 -> V_67 ;
}
F_14 ( & V_74 -> V_31 ) ;
}
T_2 void
F_43 ( struct V_52 * V_53 ,
struct V_25 * V_26 ,
struct V_12 * V_84 ,
struct V_36 * V_37 , T_1 V_19 ,
T_1 V_67 , T_1 V_6 , T_1 V_85 , int V_86 ,
int V_50 )
{
struct V_1 * V_87 ;
struct V_28 * V_29 ;
T_1 V_42 = 0 ;
int V_59 ;
if ( V_50 == V_88 )
V_50 = V_89 ;
if ( F_44 ( V_85 ) )
V_42 = F_45 ( & V_53 -> V_90 ) ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_46 ( & V_37 -> V_33 , 1 ) ;
V_37 -> V_19 = V_19 ;
V_37 -> V_67 = V_67 ;
V_37 -> V_51 = 1 ;
V_37 -> V_50 = V_50 ;
V_37 -> V_91 = 0 ;
V_37 -> V_34 = 1 ;
V_37 -> V_42 = V_42 ;
V_87 = F_28 ( V_37 ) ;
V_87 -> V_6 = V_6 ;
V_87 -> V_5 = V_85 ;
if ( V_6 )
V_37 -> type = V_48 ;
else
V_37 -> type = V_4 ;
V_87 -> V_86 = V_86 ;
F_47 ( V_37 , V_87 , V_50 ) ;
V_59 = F_37 ( V_26 , V_29 , V_84 , V_37 ) ;
if ( V_59 > 0 )
F_48 ( V_92 , V_87 ) ;
}
static T_2 void
F_49 ( struct V_52 * V_53 ,
struct V_25 * V_26 ,
struct V_12 * V_84 ,
struct V_36 * V_37 , T_1 V_19 ,
T_1 V_67 , T_1 V_6 , T_1 V_85 , T_1 V_93 ,
T_1 V_11 , int V_50 )
{
struct V_7 * V_87 ;
struct V_28 * V_29 ;
T_1 V_42 = 0 ;
int V_59 ;
if ( V_50 == V_88 )
V_50 = V_89 ;
V_29 = & V_26 -> V_30 -> V_29 ;
if ( F_44 ( V_85 ) )
V_42 = F_45 ( & V_53 -> V_90 ) ;
F_46 ( & V_37 -> V_33 , 1 ) ;
V_37 -> V_19 = V_19 ;
V_37 -> V_67 = V_67 ;
V_37 -> V_51 = 1 ;
V_37 -> V_50 = V_50 ;
V_37 -> V_91 = 0 ;
V_37 -> V_34 = 1 ;
V_37 -> V_42 = V_42 ;
V_87 = F_29 ( V_37 ) ;
V_87 -> V_6 = V_6 ;
V_87 -> V_5 = V_85 ;
if ( V_6 )
V_37 -> type = V_49 ;
else
V_37 -> type = V_9 ;
V_87 -> V_10 = V_93 ;
V_87 -> V_11 = V_11 ;
F_50 ( V_37 , V_87 , V_50 ) ;
V_59 = F_37 ( V_26 , V_29 , V_84 , V_37 ) ;
if ( V_59 > 0 )
F_48 ( V_94 , V_87 ) ;
}
int F_51 ( struct V_52 * V_53 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_67 , T_1 V_6 ,
T_1 V_85 , int V_86 , int V_50 ,
struct V_95 * V_77 )
{
struct V_1 * V_37 ;
struct V_12 * V_84 ;
struct V_28 * V_29 ;
struct V_96 * V_97 = NULL ;
F_41 ( V_77 && V_77 -> V_54 ) ;
V_37 = F_52 ( V_92 , V_98 ) ;
if ( ! V_37 )
return - V_99 ;
V_84 = F_52 ( V_100 , V_98 ) ;
if ( ! V_84 )
goto V_101;
if ( V_53 -> V_102 && F_44 ( V_85 ) ) {
V_97 = F_53 ( sizeof( * V_97 ) , V_98 ) ;
if ( ! V_97 )
goto V_103;
}
V_84 -> V_77 = V_77 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
V_84 = F_54 ( V_53 , V_26 , & V_84 -> V_8 , V_97 ,
V_19 , V_67 , 0 , 0 , V_50 , 0 ) ;
F_43 ( V_53 , V_26 , V_84 , & V_37 -> V_8 , V_19 ,
V_67 , V_6 , V_85 , V_86 , V_50 ) ;
F_14 ( & V_29 -> V_31 ) ;
return 0 ;
V_103:
F_48 ( V_100 , V_84 ) ;
V_101:
F_48 ( V_92 , V_37 ) ;
return - V_99 ;
}
int F_55 ( struct V_52 * V_53 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_67 ,
T_1 V_6 , T_1 V_85 ,
T_1 V_93 , T_1 V_11 , T_1 V_104 , int V_50 ,
struct V_95 * V_77 )
{
struct V_7 * V_37 ;
struct V_12 * V_84 ;
struct V_28 * V_29 ;
struct V_96 * V_97 = NULL ;
F_41 ( V_77 && ! V_77 -> V_54 ) ;
V_37 = F_52 ( V_94 , V_98 ) ;
if ( ! V_37 )
return - V_99 ;
V_84 = F_52 ( V_100 , V_98 ) ;
if ( ! V_84 ) {
F_48 ( V_94 , V_37 ) ;
return - V_99 ;
}
if ( V_53 -> V_102 && F_44 ( V_85 ) ) {
V_97 = F_53 ( sizeof( * V_97 ) , V_98 ) ;
if ( ! V_97 ) {
F_48 ( V_94 , V_37 ) ;
F_48 ( V_100 ,
V_84 ) ;
return - V_99 ;
}
}
V_84 -> V_77 = V_77 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
V_84 = F_54 ( V_53 , V_26 , & V_84 -> V_8 , V_97 ,
V_19 , V_67 , V_85 , V_104 ,
V_50 , 1 ) ;
F_49 ( V_53 , V_26 , V_84 , & V_37 -> V_8 , V_19 ,
V_67 , V_6 , V_85 , V_93 , V_11 ,
V_50 ) ;
F_14 ( & V_29 -> V_31 ) ;
return 0 ;
}
int F_56 ( struct V_52 * V_53 ,
struct V_25 * V_26 ,
T_1 V_85 , T_1 V_19 , T_1 V_67 )
{
struct V_28 * V_29 ;
struct V_12 * V_105 ;
int V_59 = 0 ;
if ( ! V_53 -> V_102 || ! F_44 ( V_85 ) )
return 0 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
V_105 = F_7 ( & V_29 -> V_38 , V_19 , 0 ) ;
if ( ! V_105 ) {
V_59 = - V_106 ;
goto V_107;
}
F_31 ( V_105 -> V_108 || V_105 -> V_109 ) ;
V_105 -> V_109 = V_85 ;
V_105 -> V_108 = V_67 ;
V_107:
F_14 ( & V_29 -> V_31 ) ;
return V_59 ;
}
int F_57 ( struct V_52 * V_53 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_67 ,
struct V_95 * V_77 )
{
struct V_12 * V_84 ;
struct V_28 * V_29 ;
V_84 = F_52 ( V_100 , V_98 ) ;
if ( ! V_84 )
return - V_99 ;
V_84 -> V_77 = V_77 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
F_54 ( V_53 , V_26 , & V_84 -> V_8 , NULL , V_19 ,
V_67 , 0 , 0 , V_110 ,
V_77 -> V_54 ) ;
F_14 ( & V_29 -> V_31 ) ;
return 0 ;
}
struct V_12 *
F_58 ( struct V_25 * V_26 , T_1 V_19 )
{
struct V_28 * V_29 ;
V_29 = & V_26 -> V_30 -> V_29 ;
return F_7 ( & V_29 -> V_38 , V_19 , 0 ) ;
}
void F_59 ( void )
{
if ( V_100 )
F_60 ( V_100 ) ;
if ( V_92 )
F_60 ( V_92 ) ;
if ( V_94 )
F_60 ( V_94 ) ;
if ( V_111 )
F_60 ( V_111 ) ;
}
int F_61 ( void )
{
V_100 = F_62 (
L_2 ,
sizeof( struct V_12 ) , 0 ,
V_112 | V_113 , NULL ) ;
if ( ! V_100 )
goto V_114;
V_92 = F_62 (
L_3 ,
sizeof( struct V_1 ) , 0 ,
V_112 | V_113 , NULL ) ;
if ( ! V_92 )
goto V_114;
V_94 = F_62 (
L_4 ,
sizeof( struct V_7 ) , 0 ,
V_112 | V_113 , NULL ) ;
if ( ! V_94 )
goto V_114;
V_111 = F_62 (
L_5 ,
sizeof( struct V_95 ) , 0 ,
V_112 | V_113 , NULL ) ;
if ( ! V_111 )
goto V_114;
return 0 ;
V_114:
F_59 () ;
return - V_99 ;
}
