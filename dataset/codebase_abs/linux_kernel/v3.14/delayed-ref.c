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
static struct V_28 * F_11 ( struct V_19 * V_5 ,
struct V_20 * V_8 )
{
struct V_20 * * V_21 = & V_5 -> V_20 ;
struct V_20 * V_22 = NULL ;
struct V_28 * V_23 ;
struct V_28 * V_24 ;
T_1 V_14 ;
V_24 = F_8 ( V_8 , struct V_28 , V_29 ) ;
V_14 = V_24 -> V_8 . V_14 ;
while ( * V_21 ) {
V_22 = * V_21 ;
V_23 = F_8 ( V_22 , struct V_28 ,
V_29 ) ;
if ( V_14 < V_23 -> V_8 . V_14 )
V_21 = & ( * V_21 ) -> V_26 ;
else if ( V_14 > V_23 -> V_8 . V_14 )
V_21 = & ( * V_21 ) -> V_27 ;
else
return V_23 ;
}
F_9 ( V_8 , V_22 , V_21 ) ;
F_10 ( V_8 , V_5 ) ;
return NULL ;
}
static struct V_28 *
F_12 ( struct V_19 * V_5 , T_1 V_14 ,
struct V_28 * * V_30 , int V_31 )
{
struct V_20 * V_32 ;
struct V_28 * V_23 ;
int V_25 = 0 ;
V_33:
V_32 = V_5 -> V_20 ;
V_23 = NULL ;
while ( V_32 ) {
V_23 = F_8 ( V_32 , struct V_28 , V_29 ) ;
if ( V_30 )
* V_30 = V_23 ;
if ( V_14 < V_23 -> V_8 . V_14 )
V_25 = - 1 ;
else if ( V_14 > V_23 -> V_8 . V_14 )
V_25 = 1 ;
else
V_25 = 0 ;
if ( V_25 < 0 )
V_32 = V_32 -> V_26 ;
else if ( V_25 > 0 )
V_32 = V_32 -> V_27 ;
else
return V_23 ;
}
if ( V_23 && V_31 ) {
if ( V_25 > 0 ) {
V_32 = F_13 ( & V_23 -> V_29 ) ;
if ( ! V_32 )
V_32 = F_14 ( V_5 ) ;
V_23 = F_8 ( V_32 , struct V_28 ,
V_29 ) ;
V_14 = V_23 -> V_8 . V_14 ;
V_31 = 0 ;
goto V_33;
}
return V_23 ;
}
return NULL ;
}
int F_15 ( struct V_34 * V_35 ,
struct V_28 * V_36 )
{
struct V_37 * V_38 ;
V_38 = & V_35 -> V_39 -> V_38 ;
F_16 ( & V_38 -> V_40 ) ;
if ( F_17 ( & V_36 -> V_41 ) )
return 0 ;
F_18 ( & V_36 -> V_8 . V_42 ) ;
F_19 ( & V_38 -> V_40 ) ;
F_20 ( & V_36 -> V_41 ) ;
F_21 ( & V_38 -> V_40 ) ;
if ( ! V_36 -> V_8 . V_43 ) {
F_22 ( & V_36 -> V_41 ) ;
F_23 ( & V_36 -> V_8 ) ;
return - V_44 ;
}
F_23 ( & V_36 -> V_8 ) ;
return 0 ;
}
static inline void F_24 ( struct V_34 * V_35 ,
struct V_37 * V_38 ,
struct V_28 * V_36 ,
struct V_12 * V_45 )
{
if ( F_25 ( V_45 ) ) {
V_36 = F_26 ( V_45 ) ;
F_27 ( & V_36 -> V_29 , & V_38 -> V_46 ) ;
} else {
F_16 ( & V_36 -> V_40 ) ;
F_27 ( & V_45 -> V_20 , & V_36 -> V_47 ) ;
}
V_45 -> V_43 = 0 ;
F_23 ( V_45 ) ;
F_28 ( & V_38 -> V_48 ) ;
if ( V_35 -> V_49 )
V_35 -> V_49 -- ;
}
static int F_29 ( struct V_34 * V_35 ,
struct V_37 * V_38 ,
struct V_28 * V_36 ,
struct V_12 * V_45 , T_1 V_16 )
{
struct V_20 * V_8 ;
int V_50 = 0 ;
int V_51 = 0 ;
V_8 = F_13 ( & V_45 -> V_20 ) ;
while ( ! V_51 && V_8 ) {
struct V_12 * V_52 ;
V_52 = F_8 ( V_8 , struct V_12 , V_20 ) ;
V_8 = F_13 ( V_8 ) ;
if ( V_16 && V_52 -> V_16 >= V_16 )
break;
if ( F_3 ( V_45 , V_52 , 0 ) )
continue;
if ( V_45 -> V_53 == V_52 -> V_53 ) {
V_50 = V_52 -> V_54 ;
} else {
if ( V_45 -> V_54 < V_52 -> V_54 ) {
struct V_12 * V_55 ;
V_55 = V_45 ;
V_45 = V_52 ;
V_52 = V_55 ;
V_51 = 1 ;
}
V_50 = - V_52 -> V_54 ;
}
F_24 ( V_35 , V_38 , V_36 , V_52 ) ;
V_45 -> V_54 += V_50 ;
if ( V_45 -> V_54 == 0 ) {
F_24 ( V_35 , V_38 , V_36 , V_45 ) ;
V_51 = 1 ;
} else {
F_30 ( V_45 -> type == V_4 ||
V_45 -> type == V_17 ) ;
}
}
return V_51 ;
}
void F_31 ( struct V_34 * V_35 ,
struct V_56 * V_57 ,
struct V_37 * V_38 ,
struct V_28 * V_36 )
{
struct V_20 * V_8 ;
T_1 V_16 = 0 ;
F_16 ( & V_36 -> V_40 ) ;
if ( V_36 -> V_58 )
return;
F_21 ( & V_57 -> V_59 ) ;
if ( ! F_32 ( & V_57 -> V_60 ) ) {
struct V_61 * V_62 ;
V_62 = F_33 ( & V_57 -> V_60 ,
struct V_61 , V_63 ) ;
V_16 = V_62 -> V_16 ;
}
F_19 ( & V_57 -> V_59 ) ;
V_8 = F_14 ( & V_36 -> V_47 ) ;
while ( V_8 ) {
struct V_12 * V_45 ;
V_45 = F_8 ( V_8 , struct V_12 ,
V_20 ) ;
if ( V_16 && V_45 -> V_16 >= V_16 )
break;
if ( F_29 ( V_35 , V_38 , V_36 , V_45 , V_16 ) )
V_8 = F_14 ( & V_36 -> V_47 ) ;
else
V_8 = F_13 ( & V_45 -> V_20 ) ;
}
}
int F_34 ( struct V_56 * V_57 ,
struct V_37 * V_38 ,
T_1 V_16 )
{
struct V_61 * V_62 ;
int V_64 = 0 ;
F_21 ( & V_57 -> V_59 ) ;
if ( ! F_32 ( & V_57 -> V_60 ) ) {
V_62 = F_33 ( & V_57 -> V_60 ,
struct V_61 , V_63 ) ;
if ( V_16 >= V_62 -> V_16 ) {
F_35 ( L_1 ,
( V_65 ) ( V_16 >> 32 ) , ( V_65 ) V_16 ,
( V_65 ) ( V_62 -> V_16 >> 32 ) , ( V_65 ) V_62 -> V_16 ,
V_38 ) ;
V_64 = 1 ;
}
}
F_19 ( & V_57 -> V_59 ) ;
return V_64 ;
}
struct V_28 *
F_36 ( struct V_34 * V_35 )
{
struct V_37 * V_38 ;
struct V_28 * V_36 ;
T_1 V_66 ;
bool V_67 = false ;
V_38 = & V_35 -> V_39 -> V_38 ;
V_33:
V_66 = V_38 -> V_68 ;
V_36 = F_12 ( & V_38 -> V_46 , V_66 , NULL , 1 ) ;
if ( ! V_36 && ! V_67 ) {
V_38 -> V_68 = 0 ;
V_66 = 0 ;
V_67 = true ;
V_36 = F_12 ( & V_38 -> V_46 , V_66 , NULL , 1 ) ;
if ( ! V_36 )
return NULL ;
} else if ( ! V_36 && V_67 ) {
return NULL ;
}
while ( V_36 -> V_69 ) {
struct V_20 * V_8 ;
V_8 = F_13 ( & V_36 -> V_29 ) ;
if ( ! V_8 ) {
if ( V_67 )
return NULL ;
V_38 -> V_68 = 0 ;
V_66 = 0 ;
V_67 = true ;
goto V_33;
}
V_36 = F_8 ( V_8 , struct V_28 ,
V_29 ) ;
}
V_36 -> V_69 = 1 ;
F_30 ( V_38 -> V_70 == 0 ) ;
V_38 -> V_70 -- ;
V_38 -> V_68 = V_36 -> V_8 . V_14 +
V_36 -> V_8 . V_71 ;
return V_36 ;
}
static T_2 void
F_37 ( struct V_34 * V_35 ,
struct V_37 * V_38 ,
struct V_28 * V_36 ,
struct V_12 * V_72 ,
struct V_12 * V_73 )
{
if ( V_73 -> V_53 != V_72 -> V_53 ) {
V_72 -> V_54 -- ;
if ( V_72 -> V_54 == 0 )
F_24 ( V_35 , V_38 , V_36 , V_72 ) ;
else
F_30 ( V_72 -> type == V_4 ||
V_72 -> type == V_17 ) ;
} else {
F_30 ( V_72 -> type == V_4 ||
V_72 -> type == V_17 ) ;
V_72 -> V_54 += V_73 -> V_54 ;
}
}
static T_2 void
F_38 ( struct V_12 * V_72 ,
struct V_12 * V_73 )
{
struct V_28 * V_74 ;
struct V_28 * V_45 ;
V_74 = F_26 ( V_72 ) ;
V_45 = F_26 ( V_73 ) ;
F_39 ( V_74 -> V_58 != V_45 -> V_58 ) ;
if ( V_45 -> V_75 ) {
V_74 -> V_75 = V_45 -> V_75 ;
V_72 -> V_71 = V_73 -> V_71 ;
}
if ( V_45 -> V_76 ) {
if ( ! V_74 -> V_76 ) {
V_74 -> V_76 = V_45 -> V_76 ;
} else {
if ( V_45 -> V_76 -> V_77 ) {
memcpy ( & V_74 -> V_76 -> V_78 ,
& V_45 -> V_76 -> V_78 ,
sizeof( V_45 -> V_76 -> V_78 ) ) ;
V_74 -> V_76 -> V_77 = 1 ;
}
if ( V_45 -> V_76 -> V_79 ) {
V_74 -> V_76 -> V_80 |=
V_45 -> V_76 -> V_80 ;
V_74 -> V_76 -> V_79 = 1 ;
}
F_40 ( V_45 -> V_76 ) ;
}
}
F_21 ( & V_74 -> V_40 ) ;
V_72 -> V_54 += V_73 -> V_54 ;
F_19 ( & V_74 -> V_40 ) ;
}
T_2 void
F_41 ( struct V_56 * V_57 ,
struct V_34 * V_35 ,
struct V_28 * V_81 ,
struct V_12 * V_45 , T_1 V_14 ,
T_1 V_71 , T_1 V_6 , T_1 V_47 , int V_82 ,
int V_53 , int V_83 )
{
struct V_12 * V_72 ;
struct V_1 * V_84 ;
struct V_37 * V_38 ;
T_1 V_16 = 0 ;
if ( V_53 == V_85 )
V_53 = V_86 ;
V_38 = & V_35 -> V_39 -> V_38 ;
F_42 ( & V_45 -> V_42 , 1 ) ;
V_45 -> V_14 = V_14 ;
V_45 -> V_71 = V_71 ;
V_45 -> V_54 = 1 ;
V_45 -> V_53 = V_53 ;
V_45 -> V_15 = 0 ;
V_45 -> V_43 = 1 ;
if ( F_43 ( V_83 , V_47 ) )
V_16 = F_44 ( V_57 , & V_35 -> V_87 ) ;
V_45 -> V_16 = V_16 ;
V_84 = F_4 ( V_45 ) ;
V_84 -> V_6 = V_6 ;
V_84 -> V_5 = V_47 ;
if ( V_6 )
V_45 -> type = V_17 ;
else
V_45 -> type = V_4 ;
V_84 -> V_82 = V_82 ;
F_45 ( V_45 , V_84 , V_53 ) ;
F_21 ( & V_81 -> V_40 ) ;
V_72 = F_7 ( & V_81 -> V_47 , & V_45 -> V_20 ) ;
if ( V_72 ) {
F_37 ( V_35 , V_38 , V_81 , V_72 ,
V_45 ) ;
F_46 ( V_88 , V_84 ) ;
} else {
F_18 ( & V_38 -> V_48 ) ;
V_35 -> V_49 ++ ;
}
F_19 ( & V_81 -> V_40 ) ;
}
static T_2 void
F_47 ( struct V_56 * V_57 ,
struct V_34 * V_35 ,
struct V_28 * V_81 ,
struct V_12 * V_45 , T_1 V_14 ,
T_1 V_71 , T_1 V_6 , T_1 V_47 , T_1 V_89 ,
T_1 V_11 , int V_53 , int V_83 )
{
struct V_12 * V_72 ;
struct V_7 * V_84 ;
struct V_37 * V_38 ;
T_1 V_16 = 0 ;
if ( V_53 == V_85 )
V_53 = V_86 ;
V_38 = & V_35 -> V_39 -> V_38 ;
F_42 ( & V_45 -> V_42 , 1 ) ;
V_45 -> V_14 = V_14 ;
V_45 -> V_71 = V_71 ;
V_45 -> V_54 = 1 ;
V_45 -> V_53 = V_53 ;
V_45 -> V_15 = 0 ;
V_45 -> V_43 = 1 ;
if ( F_43 ( V_83 , V_47 ) )
V_16 = F_44 ( V_57 , & V_35 -> V_87 ) ;
V_45 -> V_16 = V_16 ;
V_84 = F_5 ( V_45 ) ;
V_84 -> V_6 = V_6 ;
V_84 -> V_5 = V_47 ;
if ( V_6 )
V_45 -> type = V_18 ;
else
V_45 -> type = V_9 ;
V_84 -> V_10 = V_89 ;
V_84 -> V_11 = V_11 ;
F_48 ( V_45 , V_84 , V_53 ) ;
F_21 ( & V_81 -> V_40 ) ;
V_72 = F_7 ( & V_81 -> V_47 , & V_45 -> V_20 ) ;
if ( V_72 ) {
F_37 ( V_35 , V_38 , V_81 , V_72 ,
V_45 ) ;
F_46 ( V_90 , V_84 ) ;
} else {
F_18 ( & V_38 -> V_48 ) ;
V_35 -> V_49 ++ ;
}
F_19 ( & V_81 -> V_40 ) ;
}
int F_49 ( struct V_56 * V_57 ,
struct V_34 * V_35 ,
T_1 V_14 , T_1 V_71 , T_1 V_6 ,
T_1 V_47 , int V_82 , int V_53 ,
struct V_91 * V_76 ,
int V_83 )
{
struct V_1 * V_45 ;
struct V_28 * V_81 ;
struct V_37 * V_38 ;
F_39 ( V_76 && V_76 -> V_58 ) ;
V_45 = F_50 ( V_88 , V_92 ) ;
if ( ! V_45 )
return - V_93 ;
V_81 = F_50 ( V_94 , V_92 ) ;
if ( ! V_81 ) {
F_46 ( V_88 , V_45 ) ;
return - V_93 ;
}
V_81 -> V_76 = V_76 ;
V_38 = & V_35 -> V_39 -> V_38 ;
F_21 ( & V_38 -> V_40 ) ;
V_81 = F_51 ( V_57 , V_35 , & V_81 -> V_8 ,
V_14 , V_71 , V_53 , 0 ) ;
F_41 ( V_57 , V_35 , V_81 , & V_45 -> V_8 , V_14 ,
V_71 , V_6 , V_47 , V_82 , V_53 ,
V_83 ) ;
F_19 ( & V_38 -> V_40 ) ;
if ( F_43 ( V_83 , V_47 ) )
F_52 ( V_35 , & V_45 -> V_8 , V_76 ) ;
return 0 ;
}
int F_53 ( struct V_56 * V_57 ,
struct V_34 * V_35 ,
T_1 V_14 , T_1 V_71 ,
T_1 V_6 , T_1 V_47 ,
T_1 V_89 , T_1 V_11 , int V_53 ,
struct V_91 * V_76 ,
int V_83 )
{
struct V_7 * V_45 ;
struct V_28 * V_81 ;
struct V_37 * V_38 ;
F_39 ( V_76 && ! V_76 -> V_58 ) ;
V_45 = F_50 ( V_90 , V_92 ) ;
if ( ! V_45 )
return - V_93 ;
V_81 = F_50 ( V_94 , V_92 ) ;
if ( ! V_81 ) {
F_46 ( V_90 , V_45 ) ;
return - V_93 ;
}
V_81 -> V_76 = V_76 ;
V_38 = & V_35 -> V_39 -> V_38 ;
F_21 ( & V_38 -> V_40 ) ;
V_81 = F_51 ( V_57 , V_35 , & V_81 -> V_8 ,
V_14 , V_71 , V_53 , 1 ) ;
F_47 ( V_57 , V_35 , V_81 , & V_45 -> V_8 , V_14 ,
V_71 , V_6 , V_47 , V_89 , V_11 ,
V_53 , V_83 ) ;
F_19 ( & V_38 -> V_40 ) ;
if ( F_43 ( V_83 , V_47 ) )
F_52 ( V_35 , & V_45 -> V_8 , V_76 ) ;
return 0 ;
}
int F_54 ( struct V_56 * V_57 ,
struct V_34 * V_35 ,
T_1 V_14 , T_1 V_71 ,
struct V_91 * V_76 )
{
struct V_28 * V_81 ;
struct V_37 * V_38 ;
V_81 = F_50 ( V_94 , V_92 ) ;
if ( ! V_81 )
return - V_93 ;
V_81 -> V_76 = V_76 ;
V_38 = & V_35 -> V_39 -> V_38 ;
F_21 ( & V_38 -> V_40 ) ;
F_51 ( V_57 , V_35 , & V_81 -> V_8 , V_14 ,
V_71 , V_95 ,
V_76 -> V_58 ) ;
F_19 ( & V_38 -> V_40 ) ;
return 0 ;
}
struct V_28 *
F_55 ( struct V_34 * V_35 , T_1 V_14 )
{
struct V_37 * V_38 ;
V_38 = & V_35 -> V_39 -> V_38 ;
return F_12 ( & V_38 -> V_46 , V_14 , NULL , 0 ) ;
}
void F_56 ( void )
{
if ( V_94 )
F_57 ( V_94 ) ;
if ( V_88 )
F_57 ( V_88 ) ;
if ( V_90 )
F_57 ( V_90 ) ;
if ( V_96 )
F_57 ( V_96 ) ;
}
int F_58 ( void )
{
V_94 = F_59 (
L_2 ,
sizeof( struct V_28 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_94 )
goto V_99;
V_88 = F_59 (
L_3 ,
sizeof( struct V_1 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_88 )
goto V_99;
V_90 = F_59 (
L_4 ,
sizeof( struct V_7 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_90 )
goto V_99;
V_96 = F_59 (
L_5 ,
sizeof( struct V_91 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_96 )
goto V_99;
return 0 ;
V_99:
F_56 () ;
return - V_93 ;
}
