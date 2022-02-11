static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
if ( V_3 -> V_4 < V_2 -> V_4 )
return - 1 ;
if ( V_3 -> V_4 > V_2 -> V_4 )
return 1 ;
if ( V_3 -> V_5 < V_2 -> V_5 )
return - 1 ;
if ( V_3 -> V_5 > V_2 -> V_5 )
return 1 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_2 ,
struct V_6 * V_3 )
{
if ( V_3 -> V_7 . type == V_8 ) {
if ( V_3 -> V_4 < V_2 -> V_4 )
return - 1 ;
if ( V_3 -> V_4 > V_2 -> V_4 )
return 1 ;
if ( V_3 -> V_9 < V_2 -> V_9 )
return - 1 ;
if ( V_3 -> V_9 > V_2 -> V_9 )
return 1 ;
if ( V_3 -> V_10 < V_2 -> V_10 )
return - 1 ;
if ( V_3 -> V_10 > V_2 -> V_10 )
return 1 ;
} else {
if ( V_3 -> V_5 < V_2 -> V_5 )
return - 1 ;
if ( V_3 -> V_5 > V_2 -> V_5 )
return 1 ;
}
return 0 ;
}
static int F_3 ( struct V_11 * V_2 ,
struct V_11 * V_3 ,
bool V_12 )
{
if ( V_3 -> V_13 < V_2 -> V_13 )
return - 1 ;
if ( V_3 -> V_13 > V_2 -> V_13 )
return 1 ;
if ( V_3 -> V_14 && V_2 -> V_14 )
return 0 ;
if ( V_2 -> V_14 )
return - 1 ;
if ( V_3 -> V_14 )
return 1 ;
if ( V_3 -> type < V_2 -> type )
return - 1 ;
if ( V_3 -> type > V_2 -> type )
return 1 ;
if ( V_12 ) {
if ( V_3 -> V_15 < V_2 -> V_15 )
return - 1 ;
if ( V_3 -> V_15 > V_2 -> V_15 )
return 1 ;
}
if ( V_3 -> type == V_16 ||
V_3 -> type == V_17 ) {
return F_1 ( F_4 ( V_2 ) ,
F_4 ( V_3 ) ) ;
} else if ( V_3 -> type == V_8 ||
V_3 -> type == V_18 ) {
return F_2 ( F_5 ( V_2 ) ,
F_5 ( V_3 ) ) ;
}
F_6 () ;
return 0 ;
}
static struct V_11 * F_7 ( struct V_19 * V_4 ,
struct V_20 * V_7 )
{
struct V_20 * * V_21 = & V_4 -> V_20 ;
struct V_20 * V_22 = NULL ;
struct V_11 * V_23 ;
struct V_11 * V_24 ;
int V_25 ;
V_24 = F_8 ( V_7 , struct V_11 , V_20 ) ;
while ( * V_21 ) {
V_22 = * V_21 ;
V_23 = F_8 ( V_22 , struct V_11 ,
V_20 ) ;
V_25 = F_3 ( V_23 , V_24 , 1 ) ;
if ( V_25 < 0 )
V_21 = & ( * V_21 ) -> V_26 ;
else if ( V_25 > 0 )
V_21 = & ( * V_21 ) -> V_27 ;
else
return V_23 ;
}
F_9 ( V_7 , V_22 , V_21 ) ;
F_10 ( V_7 , V_4 ) ;
return NULL ;
}
static struct V_11 * F_11 ( struct V_19 * V_4 ,
T_1 V_13 ,
struct V_11 * * V_28 ,
int V_29 )
{
struct V_20 * V_30 ;
struct V_11 * V_23 ;
int V_25 = 0 ;
V_31:
V_30 = V_4 -> V_20 ;
V_23 = NULL ;
while ( V_30 ) {
V_23 = F_8 ( V_30 , struct V_11 , V_20 ) ;
F_12 ( ! V_23 -> V_32 ) ;
if ( V_28 )
* V_28 = V_23 ;
if ( V_13 < V_23 -> V_13 )
V_25 = - 1 ;
else if ( V_13 > V_23 -> V_13 )
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
V_30 = F_15 ( V_4 ) ;
V_23 = F_8 ( V_30 , struct V_11 ,
V_20 ) ;
V_13 = V_23 -> V_13 ;
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
F_19 ( & V_36 -> V_7 . V_42 ) ;
F_20 ( & V_38 -> V_40 ) ;
F_21 ( & V_36 -> V_41 ) ;
F_22 ( & V_38 -> V_40 ) ;
if ( ! V_36 -> V_7 . V_32 ) {
F_23 ( & V_36 -> V_41 ) ;
F_24 ( & V_36 -> V_7 ) ;
return - V_43 ;
}
F_24 ( & V_36 -> V_7 ) ;
return 0 ;
}
static void inline F_25 ( struct V_33 * V_34 ,
struct V_37 * V_38 ,
struct V_11 * V_44 )
{
F_26 ( & V_44 -> V_20 , & V_38 -> V_4 ) ;
V_44 -> V_32 = 0 ;
F_24 ( V_44 ) ;
V_38 -> V_45 -- ;
if ( V_34 -> V_46 )
V_34 -> V_46 -- ;
}
static int F_27 ( struct V_33 * V_34 ,
struct V_37 * V_38 ,
struct V_11 * V_44 , T_1 V_15 )
{
struct V_20 * V_7 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
V_7 = F_28 ( & V_44 -> V_20 ) ;
while ( V_7 ) {
struct V_11 * V_50 ;
V_50 = F_8 ( V_7 , struct V_11 , V_20 ) ;
V_7 = F_28 ( V_7 ) ;
if ( V_50 -> V_13 != V_44 -> V_13 )
break;
if ( V_15 && V_50 -> V_15 >= V_15 )
break;
if ( F_3 ( V_44 , V_50 , 0 ) )
continue;
if ( V_44 -> V_51 == V_50 -> V_51 ) {
V_48 = V_50 -> V_52 ;
} else {
if ( V_44 -> V_52 < V_50 -> V_52 ) {
struct V_11 * V_53 ;
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
F_12 ( V_44 -> type == V_16 ||
V_44 -> type == V_17 ) ;
}
if ( V_49 )
break;
V_7 = F_28 ( & V_44 -> V_20 ) ;
}
return V_47 ;
}
void F_29 ( struct V_33 * V_34 ,
struct V_54 * V_55 ,
struct V_37 * V_38 ,
struct V_35 * V_36 )
{
struct V_20 * V_7 ;
T_1 V_15 = 0 ;
F_22 ( & V_55 -> V_56 ) ;
if ( ! F_30 ( & V_55 -> V_57 ) ) {
struct V_58 * V_59 ;
V_59 = F_31 ( & V_55 -> V_57 ,
struct V_58 , V_60 ) ;
V_15 = V_59 -> V_15 ;
}
F_20 ( & V_55 -> V_56 ) ;
V_7 = F_28 ( & V_36 -> V_7 . V_20 ) ;
while ( V_7 ) {
struct V_11 * V_44 ;
V_44 = F_8 ( V_7 , struct V_11 ,
V_20 ) ;
if ( V_44 -> V_13 != V_36 -> V_7 . V_13 )
break;
if ( V_15 && V_44 -> V_15 >= V_15 )
break;
if ( F_27 ( V_34 , V_38 , V_44 , V_15 ) )
V_7 = F_28 ( & V_36 -> V_7 . V_20 ) ;
else
V_7 = F_28 ( V_7 ) ;
}
}
int F_32 ( struct V_54 * V_55 ,
struct V_37 * V_38 ,
T_1 V_15 )
{
struct V_58 * V_59 ;
int V_61 = 0 ;
F_22 ( & V_55 -> V_56 ) ;
if ( ! F_30 ( & V_55 -> V_57 ) ) {
V_59 = F_31 ( & V_55 -> V_57 ,
struct V_58 , V_60 ) ;
if ( V_15 >= V_59 -> V_15 ) {
F_33 ( L_1
L_2 , V_15 , V_59 -> V_15 , V_38 ) ;
V_61 = 1 ;
}
}
F_20 ( & V_55 -> V_56 ) ;
return V_61 ;
}
int F_34 ( struct V_33 * V_34 ,
struct V_62 * V_63 , T_1 V_64 )
{
int V_65 = 0 ;
struct V_37 * V_38 ;
struct V_20 * V_7 ;
struct V_11 * V_44 ;
struct V_35 * V_36 ;
V_38 = & V_34 -> V_39 -> V_38 ;
if ( V_64 == 0 ) {
V_7 = F_15 ( & V_38 -> V_4 ) ;
} else {
V_44 = NULL ;
F_11 ( & V_38 -> V_4 , V_64 + 1 , & V_44 , 1 ) ;
if ( V_44 ) {
V_7 = & V_44 -> V_20 ;
} else
V_7 = F_15 ( & V_38 -> V_4 ) ;
}
V_31:
while ( V_7 && V_65 < 32 ) {
V_44 = F_8 ( V_7 , struct V_11 , V_20 ) ;
if ( F_13 ( V_44 ) ) {
V_36 = F_35 ( V_44 ) ;
if ( F_30 ( & V_36 -> V_63 ) ) {
F_36 ( & V_36 -> V_63 , V_63 ) ;
V_38 -> V_66 =
V_36 -> V_7 . V_13 ;
V_65 ++ ;
F_12 ( V_38 -> V_67 == 0 ) ;
V_38 -> V_67 -- ;
} else if ( V_65 ) {
break;
}
}
V_7 = F_14 ( V_7 ) ;
}
if ( V_65 ) {
return 0 ;
} else if ( V_64 ) {
V_64 = 0 ;
V_7 = F_15 ( & V_38 -> V_4 ) ;
goto V_31;
}
return 1 ;
}
static T_2 void
F_37 ( struct V_33 * V_34 ,
struct V_37 * V_38 ,
struct V_11 * V_68 ,
struct V_11 * V_69 )
{
if ( V_69 -> V_51 != V_68 -> V_51 ) {
V_68 -> V_52 -- ;
if ( V_68 -> V_52 == 0 )
F_25 ( V_34 , V_38 , V_68 ) ;
else
F_12 ( V_68 -> type == V_16 ||
V_68 -> type == V_17 ) ;
} else {
F_12 ( V_68 -> type == V_16 ||
V_68 -> type == V_17 ) ;
V_68 -> V_52 += V_69 -> V_52 ;
}
}
static T_2 void
F_38 ( struct V_11 * V_68 ,
struct V_11 * V_69 )
{
struct V_35 * V_70 ;
struct V_35 * V_44 ;
V_70 = F_35 ( V_68 ) ;
V_44 = F_35 ( V_69 ) ;
F_39 ( V_70 -> V_71 != V_44 -> V_71 ) ;
if ( V_44 -> V_72 ) {
V_70 -> V_72 = V_44 -> V_72 ;
V_68 -> V_73 = V_69 -> V_73 ;
}
if ( V_44 -> V_74 ) {
if ( ! V_70 -> V_74 ) {
V_70 -> V_74 = V_44 -> V_74 ;
} else {
if ( V_44 -> V_74 -> V_75 ) {
memcpy ( & V_70 -> V_74 -> V_76 ,
& V_44 -> V_74 -> V_76 ,
sizeof( V_44 -> V_74 -> V_76 ) ) ;
V_70 -> V_74 -> V_75 = 1 ;
}
if ( V_44 -> V_74 -> V_77 ) {
V_70 -> V_74 -> V_78 |=
V_44 -> V_74 -> V_78 ;
V_70 -> V_74 -> V_77 = 1 ;
}
F_40 ( V_44 -> V_74 ) ;
}
}
V_68 -> V_52 += V_69 -> V_52 ;
}
static T_2 void F_41 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
struct V_11 * V_44 ,
T_1 V_13 , T_1 V_73 ,
int V_51 , int V_71 )
{
struct V_11 * V_68 ;
struct V_35 * V_79 = NULL ;
struct V_37 * V_38 ;
int V_80 = 1 ;
int V_72 = 0 ;
if ( V_51 == V_81 )
V_80 = 0 ;
else if ( V_51 == V_82 )
V_80 = - 1 ;
if ( V_51 == V_83 )
V_72 = 1 ;
else
V_72 = 0 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_42 ( & V_44 -> V_42 , 1 ) ;
V_44 -> V_13 = V_13 ;
V_44 -> V_73 = V_73 ;
V_44 -> V_52 = V_80 ;
V_44 -> type = 0 ;
V_44 -> V_51 = 0 ;
V_44 -> V_14 = 1 ;
V_44 -> V_32 = 1 ;
V_44 -> V_15 = 0 ;
V_79 = F_35 ( V_44 ) ;
V_79 -> V_72 = V_72 ;
V_79 -> V_71 = V_71 ;
F_43 ( & V_79 -> V_63 ) ;
F_44 ( & V_79 -> V_41 ) ;
F_45 ( V_44 , V_79 , V_51 ) ;
V_68 = F_7 ( & V_38 -> V_4 , & V_44 -> V_20 ) ;
if ( V_68 ) {
F_38 ( V_68 , V_44 ) ;
F_40 ( V_79 ) ;
} else {
V_38 -> V_84 ++ ;
V_38 -> V_67 ++ ;
V_38 -> V_45 ++ ;
V_34 -> V_46 ++ ;
}
}
static T_2 void F_46 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
struct V_11 * V_44 ,
T_1 V_13 , T_1 V_73 , T_1 V_5 ,
T_1 V_85 , int V_86 , int V_51 ,
int V_87 )
{
struct V_11 * V_68 ;
struct V_1 * V_88 ;
struct V_37 * V_38 ;
T_1 V_15 = 0 ;
if ( V_51 == V_83 )
V_51 = V_89 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_42 ( & V_44 -> V_42 , 1 ) ;
V_44 -> V_13 = V_13 ;
V_44 -> V_73 = V_73 ;
V_44 -> V_52 = 1 ;
V_44 -> V_51 = V_51 ;
V_44 -> V_14 = 0 ;
V_44 -> V_32 = 1 ;
if ( F_47 ( V_87 , V_85 ) )
V_15 = F_48 ( V_55 , & V_34 -> V_90 ) ;
V_44 -> V_15 = V_15 ;
V_88 = F_4 ( V_44 ) ;
V_88 -> V_5 = V_5 ;
V_88 -> V_4 = V_85 ;
if ( V_5 )
V_44 -> type = V_17 ;
else
V_44 -> type = V_16 ;
V_88 -> V_86 = V_86 ;
F_49 ( V_44 , V_88 , V_51 ) ;
V_68 = F_7 ( & V_38 -> V_4 , & V_44 -> V_20 ) ;
if ( V_68 ) {
F_37 ( V_34 , V_38 , V_68 , V_44 ) ;
F_40 ( V_88 ) ;
} else {
V_38 -> V_45 ++ ;
V_34 -> V_46 ++ ;
}
}
static T_2 void F_50 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
struct V_11 * V_44 ,
T_1 V_13 , T_1 V_73 , T_1 V_5 ,
T_1 V_85 , T_1 V_91 , T_1 V_10 ,
int V_51 , int V_87 )
{
struct V_11 * V_68 ;
struct V_6 * V_88 ;
struct V_37 * V_38 ;
T_1 V_15 = 0 ;
if ( V_51 == V_83 )
V_51 = V_89 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_42 ( & V_44 -> V_42 , 1 ) ;
V_44 -> V_13 = V_13 ;
V_44 -> V_73 = V_73 ;
V_44 -> V_52 = 1 ;
V_44 -> V_51 = V_51 ;
V_44 -> V_14 = 0 ;
V_44 -> V_32 = 1 ;
if ( F_47 ( V_87 , V_85 ) )
V_15 = F_48 ( V_55 , & V_34 -> V_90 ) ;
V_44 -> V_15 = V_15 ;
V_88 = F_5 ( V_44 ) ;
V_88 -> V_5 = V_5 ;
V_88 -> V_4 = V_85 ;
if ( V_5 )
V_44 -> type = V_18 ;
else
V_44 -> type = V_8 ;
V_88 -> V_9 = V_91 ;
V_88 -> V_10 = V_10 ;
F_51 ( V_44 , V_88 , V_51 ) ;
V_68 = F_7 ( & V_38 -> V_4 , & V_44 -> V_20 ) ;
if ( V_68 ) {
F_37 ( V_34 , V_38 , V_68 , V_44 ) ;
F_40 ( V_88 ) ;
} else {
V_38 -> V_45 ++ ;
V_34 -> V_46 ++ ;
}
}
int F_52 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
T_1 V_13 , T_1 V_73 , T_1 V_5 ,
T_1 V_85 , int V_86 , int V_51 ,
struct V_92 * V_74 ,
int V_87 )
{
struct V_1 * V_44 ;
struct V_35 * V_79 ;
struct V_37 * V_38 ;
F_39 ( V_74 && V_74 -> V_71 ) ;
V_44 = F_53 ( sizeof( * V_44 ) , V_93 ) ;
if ( ! V_44 )
return - V_94 ;
V_79 = F_53 ( sizeof( * V_79 ) , V_93 ) ;
if ( ! V_79 ) {
F_40 ( V_44 ) ;
return - V_94 ;
}
V_79 -> V_74 = V_74 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_22 ( & V_38 -> V_40 ) ;
F_41 ( V_55 , V_34 , & V_79 -> V_7 , V_13 ,
V_73 , V_51 , 0 ) ;
F_46 ( V_55 , V_34 , & V_44 -> V_7 , V_13 ,
V_73 , V_5 , V_85 , V_86 , V_51 ,
V_87 ) ;
F_20 ( & V_38 -> V_40 ) ;
if ( F_47 ( V_87 , V_85 ) )
F_54 ( V_34 , & V_44 -> V_7 , V_74 ) ;
return 0 ;
}
int F_55 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
T_1 V_13 , T_1 V_73 ,
T_1 V_5 , T_1 V_85 ,
T_1 V_91 , T_1 V_10 , int V_51 ,
struct V_92 * V_74 ,
int V_87 )
{
struct V_6 * V_44 ;
struct V_35 * V_79 ;
struct V_37 * V_38 ;
F_39 ( V_74 && ! V_74 -> V_71 ) ;
V_44 = F_53 ( sizeof( * V_44 ) , V_93 ) ;
if ( ! V_44 )
return - V_94 ;
V_79 = F_53 ( sizeof( * V_79 ) , V_93 ) ;
if ( ! V_79 ) {
F_40 ( V_44 ) ;
return - V_94 ;
}
V_79 -> V_74 = V_74 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_22 ( & V_38 -> V_40 ) ;
F_41 ( V_55 , V_34 , & V_79 -> V_7 , V_13 ,
V_73 , V_51 , 1 ) ;
F_50 ( V_55 , V_34 , & V_44 -> V_7 , V_13 ,
V_73 , V_5 , V_85 , V_91 , V_10 ,
V_51 , V_87 ) ;
F_20 ( & V_38 -> V_40 ) ;
if ( F_47 ( V_87 , V_85 ) )
F_54 ( V_34 , & V_44 -> V_7 , V_74 ) ;
return 0 ;
}
int F_56 ( struct V_54 * V_55 ,
struct V_33 * V_34 ,
T_1 V_13 , T_1 V_73 ,
struct V_92 * V_74 )
{
struct V_35 * V_79 ;
struct V_37 * V_38 ;
V_79 = F_53 ( sizeof( * V_79 ) , V_93 ) ;
if ( ! V_79 )
return - V_94 ;
V_79 -> V_74 = V_74 ;
V_38 = & V_34 -> V_39 -> V_38 ;
F_22 ( & V_38 -> V_40 ) ;
F_41 ( V_55 , V_34 , & V_79 -> V_7 , V_13 ,
V_73 , V_81 ,
V_74 -> V_71 ) ;
F_20 ( & V_38 -> V_40 ) ;
return 0 ;
}
struct V_35 *
F_57 ( struct V_33 * V_34 , T_1 V_13 )
{
struct V_11 * V_44 ;
struct V_37 * V_38 ;
V_38 = & V_34 -> V_39 -> V_38 ;
V_44 = F_11 ( & V_38 -> V_4 , V_13 , NULL , 0 ) ;
if ( V_44 )
return F_35 ( V_44 ) ;
return NULL ;
}
