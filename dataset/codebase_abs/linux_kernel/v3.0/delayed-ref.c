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
if ( V_3 -> type == V_5 ||
V_3 -> type == V_15 ) {
return F_1 ( F_4 ( V_2 ) ,
F_4 ( V_3 ) ) ;
} else if ( V_3 -> type == V_9 ||
V_3 -> type == V_16 ) {
return F_2 ( F_5 ( V_2 ) ,
F_5 ( V_3 ) ) ;
}
F_6 () ;
return 0 ;
}
static struct V_12 * F_7 ( struct V_17 * V_6 ,
struct V_18 * V_4 )
{
struct V_18 * * V_19 = & V_6 -> V_18 ;
struct V_18 * V_20 = NULL ;
struct V_12 * V_21 ;
struct V_12 * V_22 ;
int V_23 ;
V_22 = F_8 ( V_4 , struct V_12 , V_18 ) ;
while ( * V_19 ) {
V_20 = * V_19 ;
V_21 = F_8 ( V_20 , struct V_12 ,
V_18 ) ;
V_23 = F_3 ( V_21 , V_22 ) ;
if ( V_23 < 0 )
V_19 = & ( * V_19 ) -> V_24 ;
else if ( V_23 > 0 )
V_19 = & ( * V_19 ) -> V_25 ;
else
return V_21 ;
}
F_9 ( V_4 , V_20 , V_19 ) ;
F_10 ( V_4 , V_6 ) ;
return NULL ;
}
static struct V_12 * F_11 ( struct V_17 * V_6 ,
T_1 V_13 ,
struct V_12 * * V_26 )
{
struct V_18 * V_27 = V_6 -> V_18 ;
struct V_12 * V_21 ;
int V_23 ;
while ( V_27 ) {
V_21 = F_8 ( V_27 , struct V_12 , V_18 ) ;
F_12 ( ! V_21 -> V_28 ) ;
if ( V_26 )
* V_26 = V_21 ;
if ( V_13 < V_21 -> V_13 )
V_23 = - 1 ;
else if ( V_13 > V_21 -> V_13 )
V_23 = 1 ;
else if ( ! F_13 ( V_21 ) )
V_23 = 1 ;
else
V_23 = 0 ;
if ( V_23 < 0 )
V_27 = V_27 -> V_24 ;
else if ( V_23 > 0 )
V_27 = V_27 -> V_25 ;
else
return V_21 ;
}
return NULL ;
}
int F_14 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = & V_30 -> V_35 -> V_34 ;
F_15 ( & V_34 -> V_36 ) ;
if ( F_16 ( & V_32 -> V_37 ) )
return 0 ;
F_17 ( & V_32 -> V_4 . V_38 ) ;
F_18 ( & V_34 -> V_36 ) ;
F_19 ( & V_32 -> V_37 ) ;
F_20 ( & V_34 -> V_36 ) ;
if ( ! V_32 -> V_4 . V_28 ) {
F_21 ( & V_32 -> V_37 ) ;
F_22 ( & V_32 -> V_4 ) ;
return - V_39 ;
}
F_22 ( & V_32 -> V_4 ) ;
return 0 ;
}
int F_23 ( struct V_29 * V_30 ,
struct V_40 * V_41 , T_1 V_42 )
{
int V_43 = 0 ;
struct V_33 * V_34 ;
struct V_18 * V_4 ;
struct V_12 * V_44 ;
struct V_31 * V_32 ;
V_34 = & V_30 -> V_35 -> V_34 ;
if ( V_42 == 0 ) {
V_4 = F_24 ( & V_34 -> V_6 ) ;
} else {
V_44 = NULL ;
F_11 ( & V_34 -> V_6 , V_42 , & V_44 ) ;
if ( V_44 ) {
struct V_12 * V_45 ;
V_4 = F_25 ( & V_44 -> V_18 ) ;
while ( V_4 ) {
V_45 = F_8 ( V_4 ,
struct V_12 ,
V_18 ) ;
if ( V_45 -> V_13 < V_42 )
break;
V_44 = V_45 ;
V_4 = F_25 ( & V_44 -> V_18 ) ;
}
V_4 = & V_44 -> V_18 ;
} else
V_4 = F_24 ( & V_34 -> V_6 ) ;
}
V_46:
while ( V_4 && V_43 < 32 ) {
V_44 = F_8 ( V_4 , struct V_12 , V_18 ) ;
if ( F_13 ( V_44 ) ) {
V_32 = F_26 ( V_44 ) ;
if ( F_27 ( & V_32 -> V_41 ) ) {
F_28 ( & V_32 -> V_41 , V_41 ) ;
V_34 -> V_47 =
V_32 -> V_4 . V_13 ;
V_43 ++ ;
F_12 ( V_34 -> V_48 == 0 ) ;
V_34 -> V_48 -- ;
} else if ( V_43 ) {
break;
}
}
V_4 = F_29 ( V_4 ) ;
}
if ( V_43 ) {
return 0 ;
} else if ( V_42 ) {
V_42 = 0 ;
V_4 = F_24 ( & V_34 -> V_6 ) ;
goto V_46;
}
return 1 ;
}
static T_2 void
F_30 ( struct V_29 * V_30 ,
struct V_33 * V_34 ,
struct V_12 * V_49 ,
struct V_12 * V_50 )
{
if ( V_50 -> V_51 != V_49 -> V_51 ) {
V_49 -> V_52 -- ;
if ( V_49 -> V_52 == 0 ) {
F_31 ( & V_49 -> V_18 ,
& V_34 -> V_6 ) ;
V_49 -> V_28 = 0 ;
F_22 ( V_49 ) ;
V_34 -> V_53 -- ;
if ( V_30 -> V_54 )
V_30 -> V_54 -- ;
} else {
F_12 ( V_49 -> type == V_5 ||
V_49 -> type == V_15 ) ;
}
} else {
F_12 ( V_49 -> type == V_5 ||
V_49 -> type == V_15 ) ;
V_49 -> V_52 += V_50 -> V_52 ;
}
}
static T_2 void
F_32 ( struct V_12 * V_49 ,
struct V_12 * V_50 )
{
struct V_31 * V_55 ;
struct V_31 * V_44 ;
V_55 = F_26 ( V_49 ) ;
V_44 = F_26 ( V_50 ) ;
F_33 ( V_55 -> V_56 != V_44 -> V_56 ) ;
if ( V_44 -> V_57 ) {
V_55 -> V_57 = V_44 -> V_57 ;
V_49 -> V_58 = V_50 -> V_58 ;
}
if ( V_44 -> V_59 ) {
if ( ! V_55 -> V_59 ) {
V_55 -> V_59 = V_44 -> V_59 ;
} else {
if ( V_44 -> V_59 -> V_60 ) {
memcpy ( & V_55 -> V_59 -> V_61 ,
& V_44 -> V_59 -> V_61 ,
sizeof( V_44 -> V_59 -> V_61 ) ) ;
V_55 -> V_59 -> V_60 = 1 ;
}
if ( V_44 -> V_59 -> V_62 ) {
V_55 -> V_59 -> V_63 |=
V_44 -> V_59 -> V_63 ;
V_55 -> V_59 -> V_62 = 1 ;
}
F_34 ( V_44 -> V_59 ) ;
}
}
V_49 -> V_52 += V_50 -> V_52 ;
}
static T_2 int F_35 ( struct V_29 * V_30 ,
struct V_12 * V_44 ,
T_1 V_13 , T_1 V_58 ,
int V_51 , int V_56 )
{
struct V_12 * V_49 ;
struct V_31 * V_64 = NULL ;
struct V_33 * V_34 ;
int V_65 = 1 ;
int V_57 = 0 ;
if ( V_51 == V_66 )
V_65 = 0 ;
else if ( V_51 == V_67 )
V_65 = - 1 ;
if ( V_51 == V_68 )
V_57 = 1 ;
else
V_57 = 0 ;
V_34 = & V_30 -> V_35 -> V_34 ;
F_36 ( & V_44 -> V_38 , 1 ) ;
V_44 -> V_13 = V_13 ;
V_44 -> V_58 = V_58 ;
V_44 -> V_52 = V_65 ;
V_44 -> type = 0 ;
V_44 -> V_51 = 0 ;
V_44 -> V_14 = 1 ;
V_44 -> V_28 = 1 ;
V_64 = F_26 ( V_44 ) ;
V_64 -> V_57 = V_57 ;
V_64 -> V_56 = V_56 ;
F_37 ( & V_64 -> V_41 ) ;
F_38 ( & V_64 -> V_37 ) ;
F_39 ( V_44 , V_64 , V_51 ) ;
V_49 = F_7 ( & V_34 -> V_6 , & V_44 -> V_18 ) ;
if ( V_49 ) {
F_32 ( V_49 , V_44 ) ;
F_34 ( V_44 ) ;
} else {
V_34 -> V_69 ++ ;
V_34 -> V_48 ++ ;
V_34 -> V_53 ++ ;
V_30 -> V_54 ++ ;
}
return 0 ;
}
static T_2 int F_40 ( struct V_29 * V_30 ,
struct V_12 * V_44 ,
T_1 V_13 , T_1 V_58 , T_1 V_7 ,
T_1 V_70 , int V_71 , int V_51 )
{
struct V_12 * V_49 ;
struct V_1 * V_72 ;
struct V_33 * V_34 ;
if ( V_51 == V_68 )
V_51 = V_73 ;
V_34 = & V_30 -> V_35 -> V_34 ;
F_36 ( & V_44 -> V_38 , 1 ) ;
V_44 -> V_13 = V_13 ;
V_44 -> V_58 = V_58 ;
V_44 -> V_52 = 1 ;
V_44 -> V_51 = V_51 ;
V_44 -> V_14 = 0 ;
V_44 -> V_28 = 1 ;
V_72 = F_4 ( V_44 ) ;
if ( V_7 ) {
V_72 -> V_7 = V_7 ;
V_44 -> type = V_15 ;
} else {
V_72 -> V_6 = V_70 ;
V_44 -> type = V_5 ;
}
V_72 -> V_71 = V_71 ;
F_41 ( V_44 , V_72 , V_51 ) ;
V_49 = F_7 ( & V_34 -> V_6 , & V_44 -> V_18 ) ;
if ( V_49 ) {
F_30 ( V_30 , V_34 , V_49 , V_44 ) ;
F_34 ( V_44 ) ;
} else {
V_34 -> V_53 ++ ;
V_30 -> V_54 ++ ;
}
return 0 ;
}
static T_2 int F_42 ( struct V_29 * V_30 ,
struct V_12 * V_44 ,
T_1 V_13 , T_1 V_58 , T_1 V_7 ,
T_1 V_70 , T_1 V_74 , T_1 V_11 ,
int V_51 )
{
struct V_12 * V_49 ;
struct V_8 * V_72 ;
struct V_33 * V_34 ;
if ( V_51 == V_68 )
V_51 = V_73 ;
V_34 = & V_30 -> V_35 -> V_34 ;
F_36 ( & V_44 -> V_38 , 1 ) ;
V_44 -> V_13 = V_13 ;
V_44 -> V_58 = V_58 ;
V_44 -> V_52 = 1 ;
V_44 -> V_51 = V_51 ;
V_44 -> V_14 = 0 ;
V_44 -> V_28 = 1 ;
V_72 = F_5 ( V_44 ) ;
if ( V_7 ) {
V_72 -> V_7 = V_7 ;
V_44 -> type = V_16 ;
} else {
V_72 -> V_6 = V_70 ;
V_44 -> type = V_9 ;
}
V_72 -> V_10 = V_74 ;
V_72 -> V_11 = V_11 ;
F_43 ( V_44 , V_72 , V_51 ) ;
V_49 = F_7 ( & V_34 -> V_6 , & V_44 -> V_18 ) ;
if ( V_49 ) {
F_30 ( V_30 , V_34 , V_49 , V_44 ) ;
F_34 ( V_44 ) ;
} else {
V_34 -> V_53 ++ ;
V_30 -> V_54 ++ ;
}
return 0 ;
}
int F_44 ( struct V_29 * V_30 ,
T_1 V_13 , T_1 V_58 , T_1 V_7 ,
T_1 V_70 , int V_71 , int V_51 ,
struct V_75 * V_59 )
{
struct V_1 * V_44 ;
struct V_31 * V_64 ;
struct V_33 * V_34 ;
int V_76 ;
F_33 ( V_59 && V_59 -> V_56 ) ;
V_44 = F_45 ( sizeof( * V_44 ) , V_77 ) ;
if ( ! V_44 )
return - V_78 ;
V_64 = F_45 ( sizeof( * V_64 ) , V_77 ) ;
if ( ! V_64 ) {
F_34 ( V_44 ) ;
return - V_78 ;
}
V_64 -> V_59 = V_59 ;
V_34 = & V_30 -> V_35 -> V_34 ;
F_20 ( & V_34 -> V_36 ) ;
V_76 = F_35 ( V_30 , & V_64 -> V_4 , V_13 , V_58 ,
V_51 , 0 ) ;
F_33 ( V_76 ) ;
V_76 = F_40 ( V_30 , & V_44 -> V_4 , V_13 , V_58 ,
V_7 , V_70 , V_71 , V_51 ) ;
F_33 ( V_76 ) ;
F_18 ( & V_34 -> V_36 ) ;
return 0 ;
}
int F_46 ( struct V_29 * V_30 ,
T_1 V_13 , T_1 V_58 ,
T_1 V_7 , T_1 V_70 ,
T_1 V_74 , T_1 V_11 , int V_51 ,
struct V_75 * V_59 )
{
struct V_8 * V_44 ;
struct V_31 * V_64 ;
struct V_33 * V_34 ;
int V_76 ;
F_33 ( V_59 && ! V_59 -> V_56 ) ;
V_44 = F_45 ( sizeof( * V_44 ) , V_77 ) ;
if ( ! V_44 )
return - V_78 ;
V_64 = F_45 ( sizeof( * V_64 ) , V_77 ) ;
if ( ! V_64 ) {
F_34 ( V_44 ) ;
return - V_78 ;
}
V_64 -> V_59 = V_59 ;
V_34 = & V_30 -> V_35 -> V_34 ;
F_20 ( & V_34 -> V_36 ) ;
V_76 = F_35 ( V_30 , & V_64 -> V_4 , V_13 , V_58 ,
V_51 , 1 ) ;
F_33 ( V_76 ) ;
V_76 = F_42 ( V_30 , & V_44 -> V_4 , V_13 , V_58 ,
V_7 , V_70 , V_74 , V_11 , V_51 ) ;
F_33 ( V_76 ) ;
F_18 ( & V_34 -> V_36 ) ;
return 0 ;
}
int F_47 ( struct V_29 * V_30 ,
T_1 V_13 , T_1 V_58 ,
struct V_75 * V_59 )
{
struct V_31 * V_64 ;
struct V_33 * V_34 ;
int V_76 ;
V_64 = F_45 ( sizeof( * V_64 ) , V_77 ) ;
if ( ! V_64 )
return - V_78 ;
V_64 -> V_59 = V_59 ;
V_34 = & V_30 -> V_35 -> V_34 ;
F_20 ( & V_34 -> V_36 ) ;
V_76 = F_35 ( V_30 , & V_64 -> V_4 , V_13 ,
V_58 , V_66 ,
V_59 -> V_56 ) ;
F_33 ( V_76 ) ;
F_18 ( & V_34 -> V_36 ) ;
return 0 ;
}
struct V_31 *
F_48 ( struct V_29 * V_30 , T_1 V_13 )
{
struct V_12 * V_44 ;
struct V_33 * V_34 ;
V_34 = & V_30 -> V_35 -> V_34 ;
V_44 = F_11 ( & V_34 -> V_6 , V_13 , NULL ) ;
if ( V_44 )
return F_26 ( V_44 ) ;
return NULL ;
}
