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
if ( V_3 -> V_16 > V_2 -> V_16 )
return 1 ;
if ( V_3 -> V_16 < V_2 -> V_16 )
return - 1 ;
if ( V_13 ) {
if ( V_3 -> V_17 < V_2 -> V_17 )
return - 1 ;
if ( V_3 -> V_17 > V_2 -> V_17 )
return 1 ;
}
if ( V_3 -> type == V_4 ||
V_3 -> type == V_18 ) {
return F_1 ( F_4 ( V_2 ) ,
F_4 ( V_3 ) ,
V_3 -> type ) ;
} else if ( V_3 -> type == V_9 ||
V_3 -> type == V_19 ) {
return F_2 ( F_5 ( V_2 ) ,
F_5 ( V_3 ) ) ;
}
F_6 () ;
return 0 ;
}
static struct V_12 * F_7 ( struct V_20 * V_5 ,
struct V_21 * V_8 )
{
struct V_21 * * V_22 = & V_5 -> V_21 ;
struct V_21 * V_23 = NULL ;
struct V_12 * V_24 ;
struct V_12 * V_25 ;
int V_26 ;
V_25 = F_8 ( V_8 , struct V_12 , V_21 ) ;
while ( * V_22 ) {
V_23 = * V_22 ;
V_24 = F_8 ( V_23 , struct V_12 ,
V_21 ) ;
V_26 = F_3 ( V_24 , V_25 , 1 ) ;
if ( V_26 < 0 )
V_22 = & ( * V_22 ) -> V_27 ;
else if ( V_26 > 0 )
V_22 = & ( * V_22 ) -> V_28 ;
else
return V_24 ;
}
F_9 ( V_8 , V_23 , V_22 ) ;
F_10 ( V_8 , V_5 ) ;
return NULL ;
}
static struct V_29 * F_11 ( struct V_20 * V_5 ,
struct V_21 * V_8 )
{
struct V_21 * * V_22 = & V_5 -> V_21 ;
struct V_21 * V_23 = NULL ;
struct V_29 * V_24 ;
struct V_29 * V_25 ;
T_1 V_14 ;
V_25 = F_8 ( V_8 , struct V_29 , V_30 ) ;
V_14 = V_25 -> V_8 . V_14 ;
while ( * V_22 ) {
V_23 = * V_22 ;
V_24 = F_8 ( V_23 , struct V_29 ,
V_30 ) ;
if ( V_14 < V_24 -> V_8 . V_14 )
V_22 = & ( * V_22 ) -> V_27 ;
else if ( V_14 > V_24 -> V_8 . V_14 )
V_22 = & ( * V_22 ) -> V_28 ;
else
return V_24 ;
}
F_9 ( V_8 , V_23 , V_22 ) ;
F_10 ( V_8 , V_5 ) ;
return NULL ;
}
static struct V_29 *
F_12 ( struct V_20 * V_5 , T_1 V_14 ,
int V_31 )
{
struct V_21 * V_32 ;
struct V_29 * V_24 ;
V_32 = V_5 -> V_21 ;
V_24 = NULL ;
while ( V_32 ) {
V_24 = F_8 ( V_32 , struct V_29 , V_30 ) ;
if ( V_14 < V_24 -> V_8 . V_14 )
V_32 = V_32 -> V_27 ;
else if ( V_14 > V_24 -> V_8 . V_14 )
V_32 = V_32 -> V_28 ;
else
return V_24 ;
}
if ( V_24 && V_31 ) {
if ( V_14 > V_24 -> V_8 . V_14 ) {
V_32 = F_13 ( & V_24 -> V_30 ) ;
if ( ! V_32 )
V_32 = F_14 ( V_5 ) ;
V_24 = F_8 ( V_32 , struct V_29 ,
V_30 ) ;
return V_24 ;
}
return V_24 ;
}
return NULL ;
}
int F_15 ( struct V_33 * V_34 ,
struct V_29 * V_35 )
{
struct V_36 * V_37 ;
V_37 = & V_34 -> V_38 -> V_37 ;
F_16 ( & V_37 -> V_39 ) ;
if ( F_17 ( & V_35 -> V_40 ) )
return 0 ;
F_18 ( & V_35 -> V_8 . V_41 ) ;
F_19 ( & V_37 -> V_39 ) ;
F_20 ( & V_35 -> V_40 ) ;
F_21 ( & V_37 -> V_39 ) ;
if ( ! V_35 -> V_8 . V_42 ) {
F_22 ( & V_35 -> V_40 ) ;
F_23 ( & V_35 -> V_8 ) ;
return - V_43 ;
}
F_23 ( & V_35 -> V_8 ) ;
return 0 ;
}
static inline void F_24 ( struct V_33 * V_34 ,
struct V_36 * V_37 ,
struct V_29 * V_35 ,
struct V_12 * V_44 )
{
if ( F_25 ( V_44 ) ) {
V_35 = F_26 ( V_44 ) ;
F_27 ( & V_35 -> V_30 , & V_37 -> V_45 ) ;
} else {
F_16 ( & V_35 -> V_39 ) ;
F_27 ( & V_44 -> V_21 , & V_35 -> V_46 ) ;
}
V_44 -> V_42 = 0 ;
F_23 ( V_44 ) ;
F_28 ( & V_37 -> V_47 ) ;
if ( V_34 -> V_48 )
V_34 -> V_48 -- ;
}
static int F_29 ( struct V_33 * V_34 ,
struct V_36 * V_37 ,
struct V_29 * V_35 ,
struct V_12 * V_44 , T_1 V_17 )
{
struct V_21 * V_8 ;
int V_49 = 0 ;
int V_50 = 0 ;
V_8 = F_13 ( & V_44 -> V_21 ) ;
while ( ! V_50 && V_8 ) {
struct V_12 * V_51 ;
V_51 = F_8 ( V_8 , struct V_12 , V_21 ) ;
V_8 = F_13 ( V_8 ) ;
if ( V_17 && V_51 -> V_17 >= V_17 )
break;
if ( F_3 ( V_44 , V_51 , 0 ) )
continue;
if ( V_44 -> V_52 == V_51 -> V_52 ) {
V_49 = V_51 -> V_53 ;
} else {
if ( V_44 -> V_53 < V_51 -> V_53 ) {
struct V_12 * V_54 ;
V_54 = V_44 ;
V_44 = V_51 ;
V_51 = V_54 ;
V_50 = 1 ;
}
V_49 = - V_51 -> V_53 ;
}
F_24 ( V_34 , V_37 , V_35 , V_51 ) ;
V_44 -> V_53 += V_49 ;
if ( V_44 -> V_53 == 0 ) {
F_24 ( V_34 , V_37 , V_35 , V_44 ) ;
V_50 = 1 ;
} else {
F_30 ( V_44 -> type == V_4 ||
V_44 -> type == V_18 ) ;
}
}
return V_50 ;
}
void F_31 ( struct V_33 * V_34 ,
struct V_55 * V_56 ,
struct V_36 * V_37 ,
struct V_29 * V_35 )
{
struct V_21 * V_8 ;
T_1 V_17 = 0 ;
F_16 ( & V_35 -> V_39 ) ;
if ( V_35 -> V_57 )
return;
F_21 ( & V_56 -> V_58 ) ;
if ( ! F_32 ( & V_56 -> V_59 ) ) {
struct V_60 * V_61 ;
V_61 = F_33 ( & V_56 -> V_59 ,
struct V_60 , V_62 ) ;
V_17 = V_61 -> V_17 ;
}
F_19 ( & V_56 -> V_58 ) ;
V_8 = F_14 ( & V_35 -> V_46 ) ;
while ( V_8 ) {
struct V_12 * V_44 ;
V_44 = F_8 ( V_8 , struct V_12 ,
V_21 ) ;
if ( V_17 && V_44 -> V_17 >= V_17 )
break;
if ( F_29 ( V_34 , V_37 , V_35 , V_44 , V_17 ) )
V_8 = F_14 ( & V_35 -> V_46 ) ;
else
V_8 = F_13 ( & V_44 -> V_21 ) ;
}
}
int F_34 ( struct V_55 * V_56 ,
struct V_36 * V_37 ,
T_1 V_17 )
{
struct V_60 * V_61 ;
int V_63 = 0 ;
F_21 ( & V_56 -> V_58 ) ;
if ( ! F_32 ( & V_56 -> V_59 ) ) {
V_61 = F_33 ( & V_56 -> V_59 ,
struct V_60 , V_62 ) ;
if ( V_17 >= V_61 -> V_17 ) {
F_35 ( L_1 ,
( V_64 ) ( V_17 >> 32 ) , ( V_64 ) V_17 ,
( V_64 ) ( V_61 -> V_17 >> 32 ) , ( V_64 ) V_61 -> V_17 ,
V_37 ) ;
V_63 = 1 ;
}
}
F_19 ( & V_56 -> V_58 ) ;
return V_63 ;
}
struct V_29 *
F_36 ( struct V_33 * V_34 )
{
struct V_36 * V_37 ;
struct V_29 * V_35 ;
T_1 V_65 ;
bool V_66 = false ;
V_37 = & V_34 -> V_38 -> V_37 ;
V_67:
V_65 = V_37 -> V_68 ;
V_35 = F_12 ( & V_37 -> V_45 , V_65 , 1 ) ;
if ( ! V_35 && ! V_66 ) {
V_37 -> V_68 = 0 ;
V_65 = 0 ;
V_66 = true ;
V_35 = F_12 ( & V_37 -> V_45 , V_65 , 1 ) ;
if ( ! V_35 )
return NULL ;
} else if ( ! V_35 && V_66 ) {
return NULL ;
}
while ( V_35 -> V_69 ) {
struct V_21 * V_8 ;
V_8 = F_13 ( & V_35 -> V_30 ) ;
if ( ! V_8 ) {
if ( V_66 )
return NULL ;
V_37 -> V_68 = 0 ;
V_65 = 0 ;
V_66 = true ;
goto V_67;
}
V_35 = F_8 ( V_8 , struct V_29 ,
V_30 ) ;
}
V_35 -> V_69 = 1 ;
F_30 ( V_37 -> V_70 == 0 ) ;
V_37 -> V_70 -- ;
V_37 -> V_68 = V_35 -> V_8 . V_14 +
V_35 -> V_8 . V_71 ;
return V_35 ;
}
static T_2 void
F_37 ( struct V_33 * V_34 ,
struct V_36 * V_37 ,
struct V_29 * V_35 ,
struct V_12 * V_72 ,
struct V_12 * V_73 )
{
if ( V_73 -> V_52 != V_72 -> V_52 ) {
V_72 -> V_53 -- ;
if ( V_72 -> V_53 == 0 )
F_24 ( V_34 , V_37 , V_35 , V_72 ) ;
else
F_30 ( V_72 -> type == V_4 ||
V_72 -> type == V_18 ) ;
} else {
F_30 ( V_72 -> type == V_4 ||
V_72 -> type == V_18 ) ;
V_72 -> V_53 += V_73 -> V_53 ;
}
}
static T_2 void
F_38 ( struct V_12 * V_72 ,
struct V_12 * V_73 )
{
struct V_29 * V_74 ;
struct V_29 * V_44 ;
V_74 = F_26 ( V_72 ) ;
V_44 = F_26 ( V_73 ) ;
F_39 ( V_74 -> V_57 != V_44 -> V_57 ) ;
F_21 ( & V_74 -> V_39 ) ;
if ( V_44 -> V_75 ) {
V_74 -> V_75 = V_44 -> V_75 ;
V_72 -> V_71 = V_73 -> V_71 ;
}
if ( V_44 -> V_76 ) {
if ( ! V_74 -> V_76 ) {
V_74 -> V_76 = V_44 -> V_76 ;
} else {
if ( V_44 -> V_76 -> V_77 ) {
memcpy ( & V_74 -> V_76 -> V_78 ,
& V_44 -> V_76 -> V_78 ,
sizeof( V_44 -> V_76 -> V_78 ) ) ;
V_74 -> V_76 -> V_77 = 1 ;
}
if ( V_44 -> V_76 -> V_79 ) {
V_74 -> V_76 -> V_80 |=
V_44 -> V_76 -> V_80 ;
V_74 -> V_76 -> V_79 = 1 ;
}
F_40 ( V_44 -> V_76 ) ;
}
}
V_72 -> V_53 += V_73 -> V_53 ;
F_19 ( & V_74 -> V_39 ) ;
}
T_2 void
F_41 ( struct V_55 * V_56 ,
struct V_33 * V_34 ,
struct V_29 * V_81 ,
struct V_12 * V_44 , T_1 V_14 ,
T_1 V_71 , T_1 V_6 , T_1 V_46 , int V_82 ,
int V_52 , int V_16 )
{
struct V_12 * V_72 ;
struct V_1 * V_83 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
if ( V_52 == V_84 )
V_52 = V_85 ;
if ( F_42 ( V_46 ) )
V_17 = F_43 ( & V_56 -> V_86 ) ;
V_37 = & V_34 -> V_38 -> V_37 ;
F_44 ( & V_44 -> V_41 , 1 ) ;
V_44 -> V_14 = V_14 ;
V_44 -> V_71 = V_71 ;
V_44 -> V_53 = 1 ;
V_44 -> V_52 = V_52 ;
V_44 -> V_15 = 0 ;
V_44 -> V_42 = 1 ;
V_44 -> V_16 = V_16 ;
V_44 -> V_17 = V_17 ;
V_83 = F_4 ( V_44 ) ;
V_83 -> V_6 = V_6 ;
V_83 -> V_5 = V_46 ;
if ( V_6 )
V_44 -> type = V_18 ;
else
V_44 -> type = V_4 ;
V_83 -> V_82 = V_82 ;
F_45 ( V_44 , V_83 , V_52 ) ;
F_21 ( & V_81 -> V_39 ) ;
V_72 = F_7 ( & V_81 -> V_46 , & V_44 -> V_21 ) ;
if ( V_72 ) {
F_37 ( V_34 , V_37 , V_81 , V_72 ,
V_44 ) ;
F_46 ( V_87 , V_83 ) ;
} else {
F_18 ( & V_37 -> V_47 ) ;
V_34 -> V_48 ++ ;
}
F_19 ( & V_81 -> V_39 ) ;
}
static T_2 void
F_47 ( struct V_55 * V_56 ,
struct V_33 * V_34 ,
struct V_29 * V_81 ,
struct V_12 * V_44 , T_1 V_14 ,
T_1 V_71 , T_1 V_6 , T_1 V_46 , T_1 V_88 ,
T_1 V_11 , int V_52 , int V_16 )
{
struct V_12 * V_72 ;
struct V_7 * V_83 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
if ( V_52 == V_84 )
V_52 = V_85 ;
V_37 = & V_34 -> V_38 -> V_37 ;
if ( F_42 ( V_46 ) )
V_17 = F_43 ( & V_56 -> V_86 ) ;
F_44 ( & V_44 -> V_41 , 1 ) ;
V_44 -> V_14 = V_14 ;
V_44 -> V_71 = V_71 ;
V_44 -> V_53 = 1 ;
V_44 -> V_52 = V_52 ;
V_44 -> V_15 = 0 ;
V_44 -> V_42 = 1 ;
V_44 -> V_16 = V_16 ;
V_44 -> V_17 = V_17 ;
V_83 = F_5 ( V_44 ) ;
V_83 -> V_6 = V_6 ;
V_83 -> V_5 = V_46 ;
if ( V_6 )
V_44 -> type = V_19 ;
else
V_44 -> type = V_9 ;
V_83 -> V_10 = V_88 ;
V_83 -> V_11 = V_11 ;
F_48 ( V_44 , V_83 , V_52 ) ;
F_21 ( & V_81 -> V_39 ) ;
V_72 = F_7 ( & V_81 -> V_46 , & V_44 -> V_21 ) ;
if ( V_72 ) {
F_37 ( V_34 , V_37 , V_81 , V_72 ,
V_44 ) ;
F_46 ( V_89 , V_83 ) ;
} else {
F_18 ( & V_37 -> V_47 ) ;
V_34 -> V_48 ++ ;
}
F_19 ( & V_81 -> V_39 ) ;
}
int F_49 ( struct V_55 * V_56 ,
struct V_33 * V_34 ,
T_1 V_14 , T_1 V_71 , T_1 V_6 ,
T_1 V_46 , int V_82 , int V_52 ,
struct V_90 * V_76 ,
int V_16 )
{
struct V_1 * V_44 ;
struct V_29 * V_81 ;
struct V_36 * V_37 ;
if ( ! F_42 ( V_46 ) || ! V_56 -> V_91 )
V_16 = 0 ;
F_39 ( V_76 && V_76 -> V_57 ) ;
V_44 = F_50 ( V_87 , V_92 ) ;
if ( ! V_44 )
return - V_93 ;
V_81 = F_50 ( V_94 , V_92 ) ;
if ( ! V_81 ) {
F_46 ( V_87 , V_44 ) ;
return - V_93 ;
}
V_81 -> V_76 = V_76 ;
V_37 = & V_34 -> V_38 -> V_37 ;
F_21 ( & V_37 -> V_39 ) ;
V_81 = F_51 ( V_56 , V_34 , & V_81 -> V_8 ,
V_14 , V_71 , V_52 , 0 ) ;
F_41 ( V_56 , V_34 , V_81 , & V_44 -> V_8 , V_14 ,
V_71 , V_6 , V_46 , V_82 , V_52 ,
V_16 ) ;
F_19 ( & V_37 -> V_39 ) ;
return 0 ;
}
int F_52 ( struct V_55 * V_56 ,
struct V_33 * V_34 ,
T_1 V_14 , T_1 V_71 ,
T_1 V_6 , T_1 V_46 ,
T_1 V_88 , T_1 V_11 , int V_52 ,
struct V_90 * V_76 ,
int V_16 )
{
struct V_7 * V_44 ;
struct V_29 * V_81 ;
struct V_36 * V_37 ;
if ( ! F_42 ( V_46 ) || ! V_56 -> V_91 )
V_16 = 0 ;
F_39 ( V_76 && ! V_76 -> V_57 ) ;
V_44 = F_50 ( V_89 , V_92 ) ;
if ( ! V_44 )
return - V_93 ;
V_81 = F_50 ( V_94 , V_92 ) ;
if ( ! V_81 ) {
F_46 ( V_89 , V_44 ) ;
return - V_93 ;
}
V_81 -> V_76 = V_76 ;
V_37 = & V_34 -> V_38 -> V_37 ;
F_21 ( & V_37 -> V_39 ) ;
V_81 = F_51 ( V_56 , V_34 , & V_81 -> V_8 ,
V_14 , V_71 , V_52 , 1 ) ;
F_47 ( V_56 , V_34 , V_81 , & V_44 -> V_8 , V_14 ,
V_71 , V_6 , V_46 , V_88 , V_11 ,
V_52 , V_16 ) ;
F_19 ( & V_37 -> V_39 ) ;
return 0 ;
}
int F_53 ( struct V_55 * V_56 ,
struct V_33 * V_34 ,
T_1 V_14 , T_1 V_71 ,
struct V_90 * V_76 )
{
struct V_29 * V_81 ;
struct V_36 * V_37 ;
V_81 = F_50 ( V_94 , V_92 ) ;
if ( ! V_81 )
return - V_93 ;
V_81 -> V_76 = V_76 ;
V_37 = & V_34 -> V_38 -> V_37 ;
F_21 ( & V_37 -> V_39 ) ;
F_51 ( V_56 , V_34 , & V_81 -> V_8 , V_14 ,
V_71 , V_95 ,
V_76 -> V_57 ) ;
F_19 ( & V_37 -> V_39 ) ;
return 0 ;
}
struct V_29 *
F_54 ( struct V_33 * V_34 , T_1 V_14 )
{
struct V_36 * V_37 ;
V_37 = & V_34 -> V_38 -> V_37 ;
return F_12 ( & V_37 -> V_45 , V_14 , 0 ) ;
}
void F_55 ( void )
{
if ( V_94 )
F_56 ( V_94 ) ;
if ( V_87 )
F_56 ( V_87 ) ;
if ( V_89 )
F_56 ( V_89 ) ;
if ( V_96 )
F_56 ( V_96 ) ;
}
int F_57 ( void )
{
V_94 = F_58 (
L_2 ,
sizeof( struct V_29 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_94 )
goto V_99;
V_87 = F_58 (
L_3 ,
sizeof( struct V_1 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_87 )
goto V_99;
V_89 = F_58 (
L_4 ,
sizeof( struct V_7 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_89 )
goto V_99;
V_96 = F_58 (
L_5 ,
sizeof( struct V_90 ) , 0 ,
V_97 | V_98 , NULL ) ;
if ( ! V_96 )
goto V_99;
return 0 ;
V_99:
F_55 () ;
return - V_93 ;
}
