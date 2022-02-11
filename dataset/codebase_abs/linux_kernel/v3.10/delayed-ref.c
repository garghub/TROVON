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
static int F_3 ( struct V_12 * V_2 ,
struct V_12 * V_3 ,
bool V_13 )
{
if ( V_3 -> V_14 < V_2 -> V_14 )
return - 1 ;
if ( V_3 -> V_14 > V_2 -> V_14 )
return 1 ;
if ( V_3 -> V_15 && V_2 -> V_15 )
return 0 ;
if ( V_2 -> V_15 )
return - 1 ;
if ( V_3 -> V_15 )
return 1 ;
if ( V_3 -> type < V_2 -> type )
return - 1 ;
if ( V_3 -> type > V_2 -> type )
return 1 ;
if ( V_13 ) {
if ( V_3 -> V_16 < V_2 -> V_16 )
return - 1 ;
if ( V_3 -> V_16 > V_2 -> V_16 )
return 1 ;
}
if ( V_3 -> type == V_4 ||
V_3 -> type == V_17 ) {
return F_1 ( F_4 ( V_2 ) ,
F_4 ( V_3 ) ,
V_3 -> type ) ;
} else if ( V_3 -> type == V_9 ||
V_3 -> type == V_18 ) {
return F_2 ( F_5 ( V_2 ) ,
F_5 ( V_3 ) ) ;
}
F_6 () ;
return 0 ;
}
static struct V_12 * F_7 ( struct V_19 * V_5 ,
struct V_20 * V_8 )
{
struct V_20 * * V_21 = & V_5 -> V_20 ;
struct V_20 * V_22 = NULL ;
struct V_12 * V_23 ;
struct V_12 * V_24 ;
int V_25 ;
V_24 = F_8 ( V_8 , struct V_12 , V_20 ) ;
while ( * V_21 ) {
V_22 = * V_21 ;
V_23 = F_8 ( V_22 , struct V_12 ,
V_20 ) ;
V_25 = F_3 ( V_23 , V_24 , 1 ) ;
if ( V_25 < 0 )
V_21 = & ( * V_21 ) -> V_26 ;
else if ( V_25 > 0 )
V_21 = & ( * V_21 ) -> V_27 ;
else
return V_23 ;
}
F_9 ( V_8 , V_22 , V_21 ) ;
F_10 ( V_8 , V_5 ) ;
return NULL ;
}
static struct V_12 * F_11 ( struct V_19 * V_5 ,
T_1 V_14 ,
struct V_12 * * V_28 ,
int V_29 )
{
struct V_20 * V_30 ;
struct V_12 * V_23 ;
int V_25 = 0 ;
V_31:
V_30 = V_5 -> V_20 ;
V_23 = NULL ;
while ( V_30 ) {
V_23 = F_8 ( V_30 , struct V_12 , V_20 ) ;
F_12 ( ! V_23 -> V_32 ) ;
if ( V_28 )
* V_28 = V_23 ;
if ( V_14 < V_23 -> V_14 )
V_25 = - 1 ;
else if ( V_14 > V_23 -> V_14 )
V_25 = 1 ;
else if ( ! F_13 ( V_23 ) )
V_25 = 1 ;
else
V_25 = 0 ;
if ( V_25 < 0 )
V_30 = V_30 -> V_26 ;
else if ( V_25 > 0 )
V_30 = V_30 -> V_27 ;
else
return V_23 ;
}
if ( V_23 && V_29 ) {
if ( V_25 > 0 ) {
V_30 = F_14 ( & V_23 -> V_20 ) ;
if ( ! V_30 )
V_30 = F_15 ( V_5 ) ;
V_23 = F_8 ( V_30 , struct V_12 ,
V_20 ) ;
V_14 = V_23 -> V_14 ;
V_29 = 0 ;
goto V_31;
}
return V_23 ;
}
return NULL ;
}
int F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_17 ( & V_38 -> V_40 ) ;
if ( F_18 ( & V_36 -> V_41 ) )
return 0 ;
F_19 ( & V_36 -> V_8 . V_42 ) ;
F_20 ( & V_38 -> V_40 ) ;
F_21 ( & V_36 -> V_41 ) ;
F_22 ( & V_38 -> V_40 ) ;
if ( ! V_36 -> V_8 . V_32 ) {
F_23 ( & V_36 -> V_41 ) ;
F_24 ( & V_36 -> V_8 ) ;
return - V_43 ;
}
F_24 ( & V_36 -> V_8 ) ;
return 0 ;
}
static void inline F_25 ( struct V_33 * V_34 ,
struct V_37 * V_38 ,
struct V_12 * V_44 )
{
F_26 ( & V_44 -> V_20 , & V_38 -> V_5 ) ;
V_44 -> V_32 = 0 ;
F_24 ( V_44 ) ;
V_38 -> V_45 -- ;
if ( V_34 -> V_46 )
V_34 -> V_46 -- ;
}
static int F_27 ( struct V_33 * V_34 ,
struct V_37 * V_38 ,
struct V_12 * V_44 , T_1 V_16 )
{
struct V_20 * V_8 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
V_8 = F_28 ( & V_44 -> V_20 ) ;
while ( V_8 ) {
struct V_12 * V_50 ;
V_50 = F_8 ( V_8 , struct V_12 , V_20 ) ;
V_8 = F_28 ( V_8 ) ;
if ( V_50 -> V_14 != V_44 -> V_14 )
break;
if ( V_16 && V_50 -> V_16 >= V_16 )
break;
if ( F_3 ( V_44 , V_50 , 0 ) )
continue;
if ( V_44 -> V_51 == V_50 -> V_51 ) {
V_48 = V_50 -> V_52 ;
} else {
if ( V_44 -> V_52 < V_50 -> V_52 ) {
struct V_12 * V_53 ;
V_53 = V_44 ;
V_44 = V_50 ;
V_50 = V_53 ;
V_49 = 1 ;
}
V_48 = - V_50 -> V_52 ;
}
V_47 ++ ;
F_25 ( V_34 , V_38 , V_50 ) ;
V_44 -> V_52 += V_48 ;
if ( V_44 -> V_52 == 0 ) {
F_25 ( V_34 , V_38 , V_44 ) ;
break;
} else {
F_12 ( V_44 -> type == V_4 ||
V_44 -> type == V_17 ) ;
}
if ( V_49 )
break;
V_8 = F_28 ( & V_44 -> V_20 ) ;
}
return V_47 ;
}
void F_29 ( struct V_33 * V_34 ,
struct V_54 * V_55 ,
struct V_37 * V_38 ,
struct V_35 * V_36 )
{
struct V_20 * V_8 ;
T_1 V_16 = 0 ;
F_22 ( & V_55 -> V_56 ) ;
if ( ! F_30 ( & V_55 -> V_57 ) ) {
struct V_58 * V_59 ;
V_59 = F_31 ( & V_55 -> V_57 ,
struct V_58 , V_60 ) ;
V_16 = V_59 -> V_16 ;
}
F_20 ( & V_55 -> V_56 ) ;
V_8 = F_28 ( & V_36 -> V_8 . V_20 ) ;
while ( V_8 ) {
struct V_12 * V_44 ;
V_44 = F_8 ( V_8 , struct V_12 ,
V_20 ) ;
if ( V_44 -> V_14 != V_36 -> V_8 . V_14 )
break;
if ( V_16 && V_44 -> V_16 >= V_16 )
break;
if ( F_27 ( V_34 , V_38 , V_44 , V_16 ) )
V_8 = F_28 ( & V_36 -> V_8 . V_20 ) ;
else
V_8 = F_28 ( V_8 ) ;
}
}
int F_32 ( struct V_54 * V_55 ,
struct V_37 * V_38 ,
T_1 V_16 )
{
struct V_58 * V_59 ;
int V_61 = 0 ;
F_22 ( & V_55 -> V_56 ) ;
if ( ! F_30 ( & V_55 -> V_57 ) ) {
V_59 = F_31 ( & V_55 -> V_57 ,
struct V_58 , V_60 ) ;
if ( V_16 >= V_59 -> V_16 ) {
F_33 ( L_1 ,
( V_62 ) ( V_16 >> 32 ) , ( V_62 ) V_16 ,
( V_62 ) ( V_59 -> V_16 >> 32 ) , ( V_62 ) V_59 -> V_16 ,
V_38 ) ;
V_61 = 1 ;
}
}
F_20 ( & V_55 -> V_56 ) ;
return V_61 ;
}
int F_34 ( struct V_33 * V_34 ,
struct V_63 * V_64 , T_1 V_65 )
{
int V_66 = 0 ;
struct V_37 * V_38 ;
struct V_20 * V_8 ;
struct V_12 * V_44 ;
struct V_35 * V_36 ;
V_38 = & V_34 -> V_39 -> V_38 ;
if ( V_65 == 0 ) {
V_8 = F_15 ( & V_38 -> V_5 ) ;
} else {
V_44 = NULL ;
F_11 ( & V_38 -> V_5 , V_65 + 1 , & V_44 , 1 ) ;
if ( V_44 ) {
V_8 = & V_44 -> V_20 ;
} else
V_8 = F_15 ( & V_38 -> V_5 ) ;
}
V_31:
while ( V_8 && V_66 < 32 ) {
V_44 = F_8 ( V_8 , struct V_12 , V_20 ) ;
if ( F_13 ( V_44 ) ) {
V_36 = F_35 ( V_44 ) ;
if ( F_30 ( & V_36 -> V_64 ) ) {
F_36 ( & V_36 -> V_64 , V_64 ) ;
V_38 -> V_67 =
V_36 -> V_8 . V_14 ;
V_66 ++ ;
F_12 ( V_38 -> V_68 == 0 ) ;
V_38 -> V_68 -- ;
} else if ( V_66 ) {
break;
}
}
V_8 = F_14 ( V_8 ) ;
}
if ( V_66 ) {
return 0 ;
} else if ( V_65 ) {
V_65 = 0 ;
V_8 = F_15 ( & V_38 -> V_5 ) ;
goto V_31;
}
return 1 ;
}
void F_37 ( struct V_63 * V_64 )
{
struct V_63 * V_69 , * V_70 ;
F_38 (pos, q, cluster)
F_39 ( V_69 ) ;
}
static T_2 void
F_40 ( struct V_33 * V_34 ,
struct V_37 * V_38 ,
struct V_12 * V_71 ,
struct V_12 * V_72 )
{
if ( V_72 -> V_51 != V_71 -> V_51 ) {
V_71 -> V_52 -- ;
if ( V_71 -> V_52 == 0 )
F_25 ( V_34 , V_38 , V_71 ) ;
else
F_12 ( V_71 -> type == V_4 ||
V_71 -> type == V_17 ) ;
} else {
F_12 ( V_71 -> type == V_4 ||
V_71 -> type == V_17 ) ;
V_71 -> V_52 += V_72 -> V_52 ;
}
}
static T_2 void
F_41 ( struct V_12 * V_71 ,
struct V_12 * V_72 )
{
struct V_35 * V_73 ;
struct V_35 * V_44 ;
V_73 = F_35 ( V_71 ) ;
V_44 = F_35 ( V_72 ) ;
F_42 ( V_73 -> V_74 != V_44 -> V_74 ) ;
if ( V_44 -> V_75 ) {
V_73 -> V_75 = V_44 -> V_75 ;
V_71 -> V_76 = V_72 -> V_76 ;
}
if ( V_44 -> V_77 ) {
if ( ! V_73 -> V_77 ) {
V_73 -> V_77 = V_44 -> V_77 ;
} else {
if ( V_44 -> V_77 -> V_78 ) {
memcpy ( & V_73 -> V_77 -> V_79 ,
& V_44 -> V_77 -> V_79 ,
sizeof( V_44 -> V_77 -> V_79 ) ) ;
V_73 -> V_77 -> V_78 = 1 ;
}
if ( V_44 -> V_77 -> V_80 ) {
V_73 -> V_77 -> V_81 |=
V_44 -> V_77 -> V_81 ;
V_73 -> V_77 -> V_80 = 1 ;
}
F_43 ( V_44 -> V_77 ) ;
}
}
V_71 -> V_52 += V_72 -> V_52 ;
}
static T_2 void F_44 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
struct V_12 * V_44 ,
T_1 V_14 , T_1 V_76 ,
int V_51 , int V_74 )
{
struct V_12 * V_71 ;
struct V_35 * V_82 = NULL ;
struct V_37 * V_38 ;
int V_83 = 1 ;
int V_75 = 0 ;
if ( V_51 == V_84 )
V_83 = 0 ;
else if ( V_51 == V_85 )
V_83 = - 1 ;
if ( V_51 == V_86 )
V_75 = 1 ;
else
V_75 = 0 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_45 ( & V_44 -> V_42 , 1 ) ;
V_44 -> V_14 = V_14 ;
V_44 -> V_76 = V_76 ;
V_44 -> V_52 = V_83 ;
V_44 -> type = 0 ;
V_44 -> V_51 = 0 ;
V_44 -> V_15 = 1 ;
V_44 -> V_32 = 1 ;
V_44 -> V_16 = 0 ;
V_82 = F_35 ( V_44 ) ;
V_82 -> V_75 = V_75 ;
V_82 -> V_74 = V_74 ;
F_46 ( & V_82 -> V_64 ) ;
F_47 ( & V_82 -> V_41 ) ;
F_48 ( V_44 , V_82 , V_51 ) ;
V_71 = F_7 ( & V_38 -> V_5 , & V_44 -> V_20 ) ;
if ( V_71 ) {
F_41 ( V_71 , V_44 ) ;
F_49 ( V_87 , V_82 ) ;
} else {
V_38 -> V_88 ++ ;
V_38 -> V_68 ++ ;
V_38 -> V_45 ++ ;
V_34 -> V_46 ++ ;
}
}
static T_2 void F_50 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
struct V_12 * V_44 ,
T_1 V_14 , T_1 V_76 , T_1 V_6 ,
T_1 V_89 , int V_90 , int V_51 ,
int V_91 )
{
struct V_12 * V_71 ;
struct V_1 * V_92 ;
struct V_37 * V_38 ;
T_1 V_16 = 0 ;
if ( V_51 == V_86 )
V_51 = V_93 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_45 ( & V_44 -> V_42 , 1 ) ;
V_44 -> V_14 = V_14 ;
V_44 -> V_76 = V_76 ;
V_44 -> V_52 = 1 ;
V_44 -> V_51 = V_51 ;
V_44 -> V_15 = 0 ;
V_44 -> V_32 = 1 ;
if ( F_51 ( V_91 , V_89 ) )
V_16 = F_52 ( V_55 , & V_34 -> V_94 ) ;
V_44 -> V_16 = V_16 ;
V_92 = F_4 ( V_44 ) ;
V_92 -> V_6 = V_6 ;
V_92 -> V_5 = V_89 ;
if ( V_6 )
V_44 -> type = V_17 ;
else
V_44 -> type = V_4 ;
V_92 -> V_90 = V_90 ;
F_53 ( V_44 , V_92 , V_51 ) ;
V_71 = F_7 ( & V_38 -> V_5 , & V_44 -> V_20 ) ;
if ( V_71 ) {
F_40 ( V_34 , V_38 , V_71 , V_44 ) ;
F_49 ( V_95 , V_92 ) ;
} else {
V_38 -> V_45 ++ ;
V_34 -> V_46 ++ ;
}
}
static T_2 void F_54 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
struct V_12 * V_44 ,
T_1 V_14 , T_1 V_76 , T_1 V_6 ,
T_1 V_89 , T_1 V_96 , T_1 V_11 ,
int V_51 , int V_91 )
{
struct V_12 * V_71 ;
struct V_7 * V_92 ;
struct V_37 * V_38 ;
T_1 V_16 = 0 ;
if ( V_51 == V_86 )
V_51 = V_93 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_45 ( & V_44 -> V_42 , 1 ) ;
V_44 -> V_14 = V_14 ;
V_44 -> V_76 = V_76 ;
V_44 -> V_52 = 1 ;
V_44 -> V_51 = V_51 ;
V_44 -> V_15 = 0 ;
V_44 -> V_32 = 1 ;
if ( F_51 ( V_91 , V_89 ) )
V_16 = F_52 ( V_55 , & V_34 -> V_94 ) ;
V_44 -> V_16 = V_16 ;
V_92 = F_5 ( V_44 ) ;
V_92 -> V_6 = V_6 ;
V_92 -> V_5 = V_89 ;
if ( V_6 )
V_44 -> type = V_18 ;
else
V_44 -> type = V_9 ;
V_92 -> V_10 = V_96 ;
V_92 -> V_11 = V_11 ;
F_55 ( V_44 , V_92 , V_51 ) ;
V_71 = F_7 ( & V_38 -> V_5 , & V_44 -> V_20 ) ;
if ( V_71 ) {
F_40 ( V_34 , V_38 , V_71 , V_44 ) ;
F_49 ( V_97 , V_92 ) ;
} else {
V_38 -> V_45 ++ ;
V_34 -> V_46 ++ ;
}
}
int F_56 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
T_1 V_14 , T_1 V_76 , T_1 V_6 ,
T_1 V_89 , int V_90 , int V_51 ,
struct V_98 * V_77 ,
int V_91 )
{
struct V_1 * V_44 ;
struct V_35 * V_82 ;
struct V_37 * V_38 ;
F_42 ( V_77 && V_77 -> V_74 ) ;
V_44 = F_57 ( V_95 , V_99 ) ;
if ( ! V_44 )
return - V_100 ;
V_82 = F_57 ( V_87 , V_99 ) ;
if ( ! V_82 ) {
F_49 ( V_95 , V_44 ) ;
return - V_100 ;
}
V_82 -> V_77 = V_77 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_22 ( & V_38 -> V_40 ) ;
F_44 ( V_55 , V_34 , & V_82 -> V_8 , V_14 ,
V_76 , V_51 , 0 ) ;
F_50 ( V_55 , V_34 , & V_44 -> V_8 , V_14 ,
V_76 , V_6 , V_89 , V_90 , V_51 ,
V_91 ) ;
F_20 ( & V_38 -> V_40 ) ;
if ( F_51 ( V_91 , V_89 ) )
F_58 ( V_34 , & V_44 -> V_8 , V_77 ) ;
return 0 ;
}
int F_59 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
T_1 V_14 , T_1 V_76 ,
T_1 V_6 , T_1 V_89 ,
T_1 V_96 , T_1 V_11 , int V_51 ,
struct V_98 * V_77 ,
int V_91 )
{
struct V_7 * V_44 ;
struct V_35 * V_82 ;
struct V_37 * V_38 ;
F_42 ( V_77 && ! V_77 -> V_74 ) ;
V_44 = F_57 ( V_97 , V_99 ) ;
if ( ! V_44 )
return - V_100 ;
V_82 = F_57 ( V_87 , V_99 ) ;
if ( ! V_82 ) {
F_49 ( V_97 , V_44 ) ;
return - V_100 ;
}
V_82 -> V_77 = V_77 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_22 ( & V_38 -> V_40 ) ;
F_44 ( V_55 , V_34 , & V_82 -> V_8 , V_14 ,
V_76 , V_51 , 1 ) ;
F_54 ( V_55 , V_34 , & V_44 -> V_8 , V_14 ,
V_76 , V_6 , V_89 , V_96 , V_11 ,
V_51 , V_91 ) ;
F_20 ( & V_38 -> V_40 ) ;
if ( F_51 ( V_91 , V_89 ) )
F_58 ( V_34 , & V_44 -> V_8 , V_77 ) ;
return 0 ;
}
int F_60 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
T_1 V_14 , T_1 V_76 ,
struct V_98 * V_77 )
{
struct V_35 * V_82 ;
struct V_37 * V_38 ;
V_82 = F_57 ( V_87 , V_99 ) ;
if ( ! V_82 )
return - V_100 ;
V_82 -> V_77 = V_77 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_22 ( & V_38 -> V_40 ) ;
F_44 ( V_55 , V_34 , & V_82 -> V_8 , V_14 ,
V_76 , V_84 ,
V_77 -> V_74 ) ;
F_20 ( & V_38 -> V_40 ) ;
return 0 ;
}
struct V_35 *
F_61 ( struct V_33 * V_34 , T_1 V_14 )
{
struct V_12 * V_44 ;
struct V_37 * V_38 ;
V_38 = & V_34 -> V_39 -> V_38 ;
V_44 = F_11 ( & V_38 -> V_5 , V_14 , NULL , 0 ) ;
if ( V_44 )
return F_35 ( V_44 ) ;
return NULL ;
}
void F_62 ( void )
{
if ( V_87 )
F_63 ( V_87 ) ;
if ( V_95 )
F_63 ( V_95 ) ;
if ( V_97 )
F_63 ( V_97 ) ;
if ( V_101 )
F_63 ( V_101 ) ;
}
int F_64 ( void )
{
V_87 = F_65 (
L_2 ,
sizeof( struct V_35 ) , 0 ,
V_102 | V_103 , NULL ) ;
if ( ! V_87 )
goto V_104;
V_95 = F_65 (
L_3 ,
sizeof( struct V_1 ) , 0 ,
V_102 | V_103 , NULL ) ;
if ( ! V_95 )
goto V_104;
V_97 = F_65 (
L_4 ,
sizeof( struct V_7 ) , 0 ,
V_102 | V_103 , NULL ) ;
if ( ! V_97 )
goto V_104;
V_101 = F_65 (
L_5 ,
sizeof( struct V_98 ) , 0 ,
V_102 | V_103 , NULL ) ;
if ( ! V_101 )
goto V_104;
return 0 ;
V_104:
F_62 () ;
return - V_100 ;
}
