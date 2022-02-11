static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
if ( V_3 -> V_4 . type == V_5 ) {
if ( V_3 -> V_6 < V_2 -> V_6 )
return - 1 ;
if ( V_3 -> V_6 > V_2 -> V_6 )
return 1 ;
} else {
if ( V_3 -> V_7 < V_2 -> V_7 )
return - 1 ;
if ( V_3 -> V_7 > V_2 -> V_7 )
return 1 ;
}
return 0 ;
}
static int F_2 ( struct V_8 * V_2 ,
struct V_8 * V_3 )
{
if ( V_3 -> V_4 . type == V_9 ) {
if ( V_3 -> V_6 < V_2 -> V_6 )
return - 1 ;
if ( V_3 -> V_6 > V_2 -> V_6 )
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
if ( V_3 -> V_7 < V_2 -> V_7 )
return - 1 ;
if ( V_3 -> V_7 > V_2 -> V_7 )
return 1 ;
}
return 0 ;
}
static int F_3 ( struct V_12 * V_2 ,
struct V_12 * V_3 )
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
if ( V_3 -> V_15 < V_2 -> V_15 )
return - 1 ;
if ( V_3 -> V_15 > V_2 -> V_15 )
return 1 ;
if ( V_3 -> type == V_5 ||
V_3 -> type == V_16 ) {
return F_1 ( F_4 ( V_2 ) ,
F_4 ( V_3 ) ) ;
} else if ( V_3 -> type == V_9 ||
V_3 -> type == V_17 ) {
return F_2 ( F_5 ( V_2 ) ,
F_5 ( V_3 ) ) ;
}
F_6 () ;
return 0 ;
}
static struct V_12 * F_7 ( struct V_18 * V_6 ,
struct V_19 * V_4 )
{
struct V_19 * * V_20 = & V_6 -> V_19 ;
struct V_19 * V_21 = NULL ;
struct V_12 * V_22 ;
struct V_12 * V_23 ;
int V_24 ;
V_23 = F_8 ( V_4 , struct V_12 , V_19 ) ;
while ( * V_20 ) {
V_21 = * V_20 ;
V_22 = F_8 ( V_21 , struct V_12 ,
V_19 ) ;
V_24 = F_3 ( V_22 , V_23 ) ;
if ( V_24 < 0 )
V_20 = & ( * V_20 ) -> V_25 ;
else if ( V_24 > 0 )
V_20 = & ( * V_20 ) -> V_26 ;
else
return V_22 ;
}
F_9 ( V_4 , V_21 , V_20 ) ;
F_10 ( V_4 , V_6 ) ;
return NULL ;
}
static struct V_12 * F_11 ( struct V_18 * V_6 ,
T_1 V_13 ,
struct V_12 * * V_27 ,
int V_28 )
{
struct V_19 * V_29 ;
struct V_12 * V_22 ;
int V_24 = 0 ;
V_30:
V_29 = V_6 -> V_19 ;
V_22 = NULL ;
while ( V_29 ) {
V_22 = F_8 ( V_29 , struct V_12 , V_19 ) ;
F_12 ( ! V_22 -> V_31 ) ;
if ( V_27 )
* V_27 = V_22 ;
if ( V_13 < V_22 -> V_13 )
V_24 = - 1 ;
else if ( V_13 > V_22 -> V_13 )
V_24 = 1 ;
else if ( ! F_13 ( V_22 ) )
V_24 = 1 ;
else
V_24 = 0 ;
if ( V_24 < 0 )
V_29 = V_29 -> V_25 ;
else if ( V_24 > 0 )
V_29 = V_29 -> V_26 ;
else
return V_22 ;
}
if ( V_22 && V_28 ) {
if ( V_24 > 0 ) {
V_29 = F_14 ( & V_22 -> V_19 ) ;
if ( ! V_29 )
V_29 = F_15 ( V_6 ) ;
V_22 = F_8 ( V_29 , struct V_12 ,
V_19 ) ;
V_13 = V_22 -> V_13 ;
V_28 = 0 ;
goto V_30;
}
return V_22 ;
}
return NULL ;
}
int F_16 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 ;
V_37 = & V_33 -> V_38 -> V_37 ;
F_17 ( & V_37 -> V_39 ) ;
if ( F_18 ( & V_35 -> V_40 ) )
return 0 ;
F_19 ( & V_35 -> V_4 . V_41 ) ;
F_20 ( & V_37 -> V_39 ) ;
F_21 ( & V_35 -> V_40 ) ;
F_22 ( & V_37 -> V_39 ) ;
if ( ! V_35 -> V_4 . V_31 ) {
F_23 ( & V_35 -> V_40 ) ;
F_24 ( & V_35 -> V_4 ) ;
return - V_42 ;
}
F_24 ( & V_35 -> V_4 ) ;
return 0 ;
}
int F_25 ( struct V_36 * V_37 ,
T_1 V_15 )
{
struct V_43 * V_44 ;
F_17 ( & V_37 -> V_39 ) ;
if ( F_26 ( & V_37 -> V_45 ) )
return 0 ;
V_44 = F_27 ( & V_37 -> V_45 , struct V_43 , V_46 ) ;
if ( V_15 >= V_44 -> V_15 ) {
F_28 ( L_1 ,
V_15 , V_44 -> V_15 , V_37 ) ;
return 1 ;
}
return 0 ;
}
int F_29 ( struct V_32 * V_33 ,
struct V_47 * V_48 , T_1 V_49 )
{
int V_50 = 0 ;
struct V_36 * V_37 ;
struct V_19 * V_4 ;
struct V_12 * V_51 ;
struct V_34 * V_35 ;
V_37 = & V_33 -> V_38 -> V_37 ;
if ( V_49 == 0 ) {
V_4 = F_15 ( & V_37 -> V_6 ) ;
} else {
V_51 = NULL ;
F_11 ( & V_37 -> V_6 , V_49 + 1 , & V_51 , 1 ) ;
if ( V_51 ) {
V_4 = & V_51 -> V_19 ;
} else
V_4 = F_15 ( & V_37 -> V_6 ) ;
}
V_30:
while ( V_4 && V_50 < 32 ) {
V_51 = F_8 ( V_4 , struct V_12 , V_19 ) ;
if ( F_13 ( V_51 ) ) {
V_35 = F_30 ( V_51 ) ;
if ( F_26 ( & V_35 -> V_48 ) ) {
F_31 ( & V_35 -> V_48 , V_48 ) ;
V_37 -> V_52 =
V_35 -> V_4 . V_13 ;
V_50 ++ ;
F_12 ( V_37 -> V_53 == 0 ) ;
V_37 -> V_53 -- ;
} else if ( V_50 ) {
break;
}
}
V_4 = F_14 ( V_4 ) ;
}
if ( V_50 ) {
return 0 ;
} else if ( V_49 ) {
V_49 = 0 ;
V_4 = F_15 ( & V_37 -> V_6 ) ;
goto V_30;
}
return 1 ;
}
static T_2 void
F_32 ( struct V_32 * V_33 ,
struct V_36 * V_37 ,
struct V_12 * V_54 ,
struct V_12 * V_55 )
{
if ( V_55 -> V_56 != V_54 -> V_56 ) {
V_54 -> V_57 -- ;
if ( V_54 -> V_57 == 0 ) {
F_33 ( & V_54 -> V_19 ,
& V_37 -> V_6 ) ;
V_54 -> V_31 = 0 ;
F_24 ( V_54 ) ;
V_37 -> V_58 -- ;
if ( V_33 -> V_59 )
V_33 -> V_59 -- ;
} else {
F_12 ( V_54 -> type == V_5 ||
V_54 -> type == V_16 ) ;
}
} else {
F_12 ( V_54 -> type == V_5 ||
V_54 -> type == V_16 ) ;
V_54 -> V_57 += V_55 -> V_57 ;
}
}
static T_2 void
F_34 ( struct V_12 * V_54 ,
struct V_12 * V_55 )
{
struct V_34 * V_60 ;
struct V_34 * V_51 ;
V_60 = F_30 ( V_54 ) ;
V_51 = F_30 ( V_55 ) ;
F_35 ( V_60 -> V_61 != V_51 -> V_61 ) ;
if ( V_51 -> V_62 ) {
V_60 -> V_62 = V_51 -> V_62 ;
V_54 -> V_63 = V_55 -> V_63 ;
}
if ( V_51 -> V_64 ) {
if ( ! V_60 -> V_64 ) {
V_60 -> V_64 = V_51 -> V_64 ;
} else {
if ( V_51 -> V_64 -> V_65 ) {
memcpy ( & V_60 -> V_64 -> V_66 ,
& V_51 -> V_64 -> V_66 ,
sizeof( V_51 -> V_64 -> V_66 ) ) ;
V_60 -> V_64 -> V_65 = 1 ;
}
if ( V_51 -> V_64 -> V_67 ) {
V_60 -> V_64 -> V_68 |=
V_51 -> V_64 -> V_68 ;
V_60 -> V_64 -> V_67 = 1 ;
}
F_36 ( V_51 -> V_64 ) ;
}
}
V_54 -> V_57 += V_55 -> V_57 ;
}
static T_2 void F_37 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
struct V_12 * V_51 ,
T_1 V_13 , T_1 V_63 ,
int V_56 , int V_61 )
{
struct V_12 * V_54 ;
struct V_34 * V_71 = NULL ;
struct V_36 * V_37 ;
int V_72 = 1 ;
int V_62 = 0 ;
if ( V_56 == V_73 )
V_72 = 0 ;
else if ( V_56 == V_74 )
V_72 = - 1 ;
if ( V_56 == V_75 )
V_62 = 1 ;
else
V_62 = 0 ;
V_37 = & V_33 -> V_38 -> V_37 ;
F_38 ( & V_51 -> V_41 , 1 ) ;
V_51 -> V_13 = V_13 ;
V_51 -> V_63 = V_63 ;
V_51 -> V_57 = V_72 ;
V_51 -> type = 0 ;
V_51 -> V_56 = 0 ;
V_51 -> V_14 = 1 ;
V_51 -> V_31 = 1 ;
V_51 -> V_15 = 0 ;
V_71 = F_30 ( V_51 ) ;
V_71 -> V_62 = V_62 ;
V_71 -> V_61 = V_61 ;
F_39 ( & V_71 -> V_48 ) ;
F_40 ( & V_71 -> V_40 ) ;
F_41 ( V_51 , V_71 , V_56 ) ;
V_54 = F_7 ( & V_37 -> V_6 , & V_51 -> V_19 ) ;
if ( V_54 ) {
F_34 ( V_54 , V_51 ) ;
F_36 ( V_71 ) ;
} else {
V_37 -> V_76 ++ ;
V_37 -> V_53 ++ ;
V_37 -> V_58 ++ ;
V_33 -> V_59 ++ ;
}
}
static T_2 void F_42 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
struct V_12 * V_51 ,
T_1 V_13 , T_1 V_63 , T_1 V_7 ,
T_1 V_77 , int V_78 , int V_56 ,
int V_79 )
{
struct V_12 * V_54 ;
struct V_1 * V_80 ;
struct V_36 * V_37 ;
T_1 V_15 = 0 ;
if ( V_56 == V_75 )
V_56 = V_81 ;
V_37 = & V_33 -> V_38 -> V_37 ;
F_38 ( & V_51 -> V_41 , 1 ) ;
V_51 -> V_13 = V_13 ;
V_51 -> V_63 = V_63 ;
V_51 -> V_57 = 1 ;
V_51 -> V_56 = V_56 ;
V_51 -> V_14 = 0 ;
V_51 -> V_31 = 1 ;
if ( F_43 ( V_79 , V_77 ) )
V_15 = F_44 ( V_37 ) ;
V_51 -> V_15 = V_15 ;
V_80 = F_4 ( V_51 ) ;
V_80 -> V_7 = V_7 ;
V_80 -> V_6 = V_77 ;
if ( V_7 )
V_51 -> type = V_16 ;
else
V_51 -> type = V_5 ;
V_80 -> V_78 = V_78 ;
F_45 ( V_51 , V_80 , V_56 ) ;
V_54 = F_7 ( & V_37 -> V_6 , & V_51 -> V_19 ) ;
if ( V_54 ) {
F_32 ( V_33 , V_37 , V_54 , V_51 ) ;
F_36 ( V_80 ) ;
} else {
V_37 -> V_58 ++ ;
V_33 -> V_59 ++ ;
}
}
static T_2 void F_46 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
struct V_12 * V_51 ,
T_1 V_13 , T_1 V_63 , T_1 V_7 ,
T_1 V_77 , T_1 V_82 , T_1 V_11 ,
int V_56 , int V_79 )
{
struct V_12 * V_54 ;
struct V_8 * V_80 ;
struct V_36 * V_37 ;
T_1 V_15 = 0 ;
if ( V_56 == V_75 )
V_56 = V_81 ;
V_37 = & V_33 -> V_38 -> V_37 ;
F_38 ( & V_51 -> V_41 , 1 ) ;
V_51 -> V_13 = V_13 ;
V_51 -> V_63 = V_63 ;
V_51 -> V_57 = 1 ;
V_51 -> V_56 = V_56 ;
V_51 -> V_14 = 0 ;
V_51 -> V_31 = 1 ;
if ( F_43 ( V_79 , V_77 ) )
V_15 = F_44 ( V_37 ) ;
V_51 -> V_15 = V_15 ;
V_80 = F_5 ( V_51 ) ;
V_80 -> V_7 = V_7 ;
V_80 -> V_6 = V_77 ;
if ( V_7 )
V_51 -> type = V_17 ;
else
V_51 -> type = V_9 ;
V_80 -> V_10 = V_82 ;
V_80 -> V_11 = V_11 ;
F_47 ( V_51 , V_80 , V_56 ) ;
V_54 = F_7 ( & V_37 -> V_6 , & V_51 -> V_19 ) ;
if ( V_54 ) {
F_32 ( V_33 , V_37 , V_54 , V_51 ) ;
F_36 ( V_80 ) ;
} else {
V_37 -> V_58 ++ ;
V_33 -> V_59 ++ ;
}
}
int F_48 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
T_1 V_13 , T_1 V_63 , T_1 V_7 ,
T_1 V_77 , int V_78 , int V_56 ,
struct V_83 * V_64 ,
int V_79 )
{
struct V_1 * V_51 ;
struct V_34 * V_71 ;
struct V_36 * V_37 ;
F_35 ( V_64 && V_64 -> V_61 ) ;
V_51 = F_49 ( sizeof( * V_51 ) , V_84 ) ;
if ( ! V_51 )
return - V_85 ;
V_71 = F_49 ( sizeof( * V_71 ) , V_84 ) ;
if ( ! V_71 ) {
F_36 ( V_51 ) ;
return - V_85 ;
}
V_71 -> V_64 = V_64 ;
V_37 = & V_33 -> V_38 -> V_37 ;
F_22 ( & V_37 -> V_39 ) ;
F_37 ( V_70 , V_33 , & V_71 -> V_4 , V_13 ,
V_63 , V_56 , 0 ) ;
F_42 ( V_70 , V_33 , & V_51 -> V_4 , V_13 ,
V_63 , V_7 , V_77 , V_78 , V_56 ,
V_79 ) ;
if ( ! F_43 ( V_79 , V_77 ) &&
F_50 ( & V_37 -> V_86 ) )
F_51 ( & V_37 -> V_86 ) ;
F_20 ( & V_37 -> V_39 ) ;
return 0 ;
}
int F_52 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
T_1 V_13 , T_1 V_63 ,
T_1 V_7 , T_1 V_77 ,
T_1 V_82 , T_1 V_11 , int V_56 ,
struct V_83 * V_64 ,
int V_79 )
{
struct V_8 * V_51 ;
struct V_34 * V_71 ;
struct V_36 * V_37 ;
F_35 ( V_64 && ! V_64 -> V_61 ) ;
V_51 = F_49 ( sizeof( * V_51 ) , V_84 ) ;
if ( ! V_51 )
return - V_85 ;
V_71 = F_49 ( sizeof( * V_71 ) , V_84 ) ;
if ( ! V_71 ) {
F_36 ( V_51 ) ;
return - V_85 ;
}
V_71 -> V_64 = V_64 ;
V_37 = & V_33 -> V_38 -> V_37 ;
F_22 ( & V_37 -> V_39 ) ;
F_37 ( V_70 , V_33 , & V_71 -> V_4 , V_13 ,
V_63 , V_56 , 1 ) ;
F_46 ( V_70 , V_33 , & V_51 -> V_4 , V_13 ,
V_63 , V_7 , V_77 , V_82 , V_11 ,
V_56 , V_79 ) ;
if ( ! F_43 ( V_79 , V_77 ) &&
F_50 ( & V_37 -> V_86 ) )
F_51 ( & V_37 -> V_86 ) ;
F_20 ( & V_37 -> V_39 ) ;
return 0 ;
}
int F_53 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
T_1 V_13 , T_1 V_63 ,
struct V_83 * V_64 )
{
struct V_34 * V_71 ;
struct V_36 * V_37 ;
V_71 = F_49 ( sizeof( * V_71 ) , V_84 ) ;
if ( ! V_71 )
return - V_85 ;
V_71 -> V_64 = V_64 ;
V_37 = & V_33 -> V_38 -> V_37 ;
F_22 ( & V_37 -> V_39 ) ;
F_37 ( V_70 , V_33 , & V_71 -> V_4 , V_13 ,
V_63 , V_73 ,
V_64 -> V_61 ) ;
if ( F_50 ( & V_37 -> V_86 ) )
F_51 ( & V_37 -> V_86 ) ;
F_20 ( & V_37 -> V_39 ) ;
return 0 ;
}
struct V_34 *
F_54 ( struct V_32 * V_33 , T_1 V_13 )
{
struct V_12 * V_51 ;
struct V_36 * V_37 ;
V_37 = & V_33 -> V_38 -> V_37 ;
V_51 = F_11 ( & V_37 -> V_6 , V_13 , NULL , 0 ) ;
if ( V_51 )
return F_30 ( V_51 ) ;
return NULL ;
}
