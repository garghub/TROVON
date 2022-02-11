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
if ( ! F_24 ( & V_37 -> V_40 ) )
F_23 ( & V_37 -> V_40 ) ;
}
V_37 -> V_34 = 0 ;
F_18 ( V_37 ) ;
F_25 ( & V_29 -> V_41 ) ;
if ( V_26 -> V_42 )
V_26 -> V_42 -- ;
}
static bool F_26 ( struct V_25 * V_26 ,
struct V_28 * V_29 ,
struct V_12 * V_27 ,
struct V_36 * V_37 ,
T_1 V_43 )
{
struct V_36 * V_44 ;
bool V_45 = false ;
V_44 = F_27 ( & V_27 -> V_46 , struct V_36 ,
V_39 ) ;
while ( ! V_45 && & V_44 -> V_39 != & V_27 -> V_46 ) {
int V_47 ;
struct V_36 * V_48 ;
V_48 = F_28 ( V_44 , V_39 ) ;
if ( V_44 == V_37 )
goto V_44;
if ( V_43 && V_44 -> V_43 >= V_43 )
goto V_44;
if ( V_44 -> type != V_37 -> type )
goto V_44;
if ( ( V_37 -> type == V_4 ||
V_37 -> type == V_49 ) &&
F_1 ( F_29 ( V_37 ) ,
F_29 ( V_44 ) ,
V_37 -> type ) )
goto V_44;
if ( ( V_37 -> type == V_9 ||
V_37 -> type == V_50 ) &&
F_2 ( F_30 ( V_37 ) ,
F_30 ( V_44 ) ) )
goto V_44;
if ( V_37 -> V_51 == V_44 -> V_51 ) {
V_47 = V_44 -> V_52 ;
} else {
if ( V_37 -> V_52 < V_44 -> V_52 ) {
F_31 ( V_37 , V_44 ) ;
V_45 = true ;
}
V_47 = - V_44 -> V_52 ;
}
F_19 ( V_26 , V_29 , V_27 , V_44 ) ;
V_37 -> V_52 += V_47 ;
if ( V_37 -> V_52 == 0 ) {
F_19 ( V_26 , V_29 , V_27 , V_37 ) ;
V_45 = true ;
} else {
F_32 ( V_37 -> type == V_4 ||
V_37 -> type == V_49 ) ;
}
V_44:
V_44 = V_48 ;
}
return V_45 ;
}
void F_33 ( struct V_25 * V_26 ,
struct V_53 * V_54 ,
struct V_28 * V_29 ,
struct V_12 * V_27 )
{
struct V_36 * V_37 ;
T_1 V_43 = 0 ;
F_11 ( & V_27 -> V_31 ) ;
if ( F_24 ( & V_27 -> V_46 ) )
return;
if ( V_27 -> V_55 )
return;
F_16 ( & V_54 -> V_56 ) ;
if ( ! F_24 ( & V_54 -> V_57 ) ) {
struct V_58 * V_59 ;
V_59 = F_27 ( & V_54 -> V_57 ,
struct V_58 , V_39 ) ;
V_43 = V_59 -> V_43 ;
}
F_14 ( & V_54 -> V_56 ) ;
V_37 = F_27 ( & V_27 -> V_46 , struct V_36 ,
V_39 ) ;
while ( & V_37 -> V_39 != & V_27 -> V_46 ) {
if ( V_43 && V_37 -> V_43 >= V_43 )
goto V_44;
if ( F_26 ( V_26 , V_29 , V_27 , V_37 , V_43 ) ) {
if ( F_24 ( & V_27 -> V_46 ) )
break;
V_37 = F_27 ( & V_27 -> V_46 ,
struct V_36 ,
V_39 ) ;
continue;
}
V_44:
V_37 = F_28 ( V_37 , V_39 ) ;
}
}
int F_34 ( struct V_53 * V_54 ,
struct V_28 * V_29 ,
T_1 V_43 )
{
struct V_58 * V_59 ;
int V_60 = 0 ;
F_16 ( & V_54 -> V_56 ) ;
if ( ! F_24 ( & V_54 -> V_57 ) ) {
V_59 = F_27 ( & V_54 -> V_57 ,
struct V_58 , V_39 ) ;
if ( V_43 >= V_59 -> V_43 ) {
F_35 ( V_54 ,
L_1 ,
( V_61 ) ( V_43 >> 32 ) , ( V_61 ) V_43 ,
( V_61 ) ( V_59 -> V_43 >> 32 ) , ( V_61 ) V_59 -> V_43 ,
V_29 ) ;
V_60 = 1 ;
}
}
F_14 ( & V_54 -> V_56 ) ;
return V_60 ;
}
struct V_12 *
F_36 ( struct V_25 * V_26 )
{
struct V_28 * V_29 ;
struct V_12 * V_27 ;
T_1 V_62 ;
bool V_63 = false ;
V_29 = & V_26 -> V_30 -> V_29 ;
V_64:
V_62 = V_29 -> V_65 ;
V_27 = F_7 ( & V_29 -> V_38 , V_62 , 1 ) ;
if ( ! V_27 && ! V_63 ) {
V_29 -> V_65 = 0 ;
V_62 = 0 ;
V_63 = true ;
V_27 = F_7 ( & V_29 -> V_38 , V_62 , 1 ) ;
if ( ! V_27 )
return NULL ;
} else if ( ! V_27 && V_63 ) {
return NULL ;
}
while ( V_27 -> V_66 ) {
struct V_14 * V_8 ;
V_8 = F_8 ( & V_27 -> V_20 ) ;
if ( ! V_8 ) {
if ( V_63 )
return NULL ;
V_29 -> V_65 = 0 ;
V_62 = 0 ;
V_63 = true ;
goto V_64;
}
V_27 = F_4 ( V_8 , struct V_12 ,
V_20 ) ;
}
V_27 -> V_66 = 1 ;
F_32 ( V_29 -> V_67 == 0 ) ;
V_29 -> V_67 -- ;
V_29 -> V_65 = V_27 -> V_8 . V_19 +
V_27 -> V_8 . V_68 ;
return V_27 ;
}
static int
F_37 ( struct V_25 * V_26 ,
struct V_28 * V_5 ,
struct V_12 * V_69 ,
struct V_36 * V_37 )
{
struct V_36 * V_70 ;
int V_47 ;
int V_60 = 0 ;
F_16 ( & V_69 -> V_31 ) ;
if ( F_24 ( & V_69 -> V_46 ) )
goto V_71;
V_70 = F_38 ( V_69 -> V_46 . V_72 , struct V_36 ,
V_39 ) ;
if ( V_70 -> type != V_37 -> type || V_70 -> V_43 != V_37 -> V_43 )
goto V_71;
if ( ( V_70 -> type == V_4 ||
V_70 -> type == V_49 ) &&
F_1 ( F_29 ( V_70 ) ,
F_29 ( V_37 ) ,
V_37 -> type ) )
goto V_71;
if ( ( V_70 -> type == V_9 ||
V_70 -> type == V_50 ) &&
F_2 ( F_30 ( V_70 ) ,
F_30 ( V_37 ) ) )
goto V_71;
V_60 = 1 ;
if ( V_70 -> V_51 == V_37 -> V_51 ) {
V_47 = V_37 -> V_52 ;
} else {
if ( V_70 -> V_52 < V_37 -> V_52 ) {
V_70 -> V_51 = V_37 -> V_51 ;
V_47 = - V_70 -> V_52 ;
V_70 -> V_52 = V_37 -> V_52 ;
if ( V_37 -> V_51 == V_73 )
F_39 ( & V_70 -> V_40 ,
& V_69 -> V_74 ) ;
else if ( V_37 -> V_51 == V_75 ) {
ASSERT ( ! F_24 ( & V_70 -> V_40 ) ) ;
F_23 ( & V_70 -> V_40 ) ;
} else {
ASSERT ( 0 ) ;
}
} else
V_47 = - V_37 -> V_52 ;
}
V_70 -> V_52 += V_47 ;
if ( V_70 -> V_52 == 0 )
F_19 ( V_26 , V_5 , V_69 , V_70 ) ;
F_14 ( & V_69 -> V_31 ) ;
return V_60 ;
V_71:
F_39 ( & V_37 -> V_39 , & V_69 -> V_46 ) ;
if ( V_37 -> V_51 == V_73 )
F_39 ( & V_37 -> V_40 , & V_69 -> V_74 ) ;
F_13 ( & V_5 -> V_41 ) ;
V_26 -> V_42 ++ ;
F_14 ( & V_69 -> V_31 ) ;
return V_60 ;
}
static T_2 void
F_40 ( struct V_28 * V_29 ,
struct V_36 * V_76 ,
struct V_36 * V_77 )
{
struct V_12 * V_78 ;
struct V_12 * V_37 ;
int V_79 ;
V_78 = F_21 ( V_76 ) ;
V_37 = F_21 ( V_77 ) ;
F_41 ( V_78 -> V_55 != V_37 -> V_55 ) ;
F_16 ( & V_78 -> V_31 ) ;
if ( V_37 -> V_80 ) {
V_78 -> V_80 = V_37 -> V_80 ;
V_76 -> V_68 = V_77 -> V_68 ;
}
if ( V_37 -> V_81 ) {
if ( ! V_78 -> V_81 ) {
V_78 -> V_81 = V_37 -> V_81 ;
} else {
if ( V_37 -> V_81 -> V_82 ) {
memcpy ( & V_78 -> V_81 -> V_83 ,
& V_37 -> V_81 -> V_83 ,
sizeof( V_37 -> V_81 -> V_83 ) ) ;
V_78 -> V_81 -> V_82 = true ;
}
if ( V_37 -> V_81 -> V_84 ) {
V_78 -> V_81 -> V_85 |=
V_37 -> V_81 -> V_85 ;
V_78 -> V_81 -> V_84 = true ;
}
F_42 ( V_37 -> V_81 ) ;
}
}
V_79 = V_78 -> V_86 ;
V_76 -> V_52 += V_77 -> V_52 ;
V_78 -> V_86 += V_77 -> V_52 ;
if ( V_78 -> V_55 ) {
if ( V_78 -> V_86 >= 0 && V_79 < 0 )
V_29 -> V_87 -= V_76 -> V_68 ;
if ( V_78 -> V_86 < 0 && V_79 >= 0 )
V_29 -> V_87 += V_76 -> V_68 ;
}
F_14 ( & V_78 -> V_31 ) ;
}
T_2 void
F_43 ( struct V_53 * V_54 ,
struct V_25 * V_26 ,
struct V_12 * V_88 ,
struct V_36 * V_37 , T_1 V_19 ,
T_1 V_68 , T_1 V_6 , T_1 V_89 , int V_90 ,
int V_51 )
{
struct V_1 * V_91 ;
struct V_28 * V_29 ;
T_1 V_43 = 0 ;
int V_60 ;
if ( V_51 == V_92 )
V_51 = V_73 ;
if ( F_44 ( V_89 ) )
V_43 = F_45 ( & V_54 -> V_93 ) ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_46 ( & V_37 -> V_33 , 1 ) ;
V_37 -> V_19 = V_19 ;
V_37 -> V_68 = V_68 ;
V_37 -> V_52 = 1 ;
V_37 -> V_51 = V_51 ;
V_37 -> V_94 = 0 ;
V_37 -> V_34 = 1 ;
V_37 -> V_43 = V_43 ;
F_47 ( & V_37 -> V_39 ) ;
F_47 ( & V_37 -> V_40 ) ;
V_91 = F_29 ( V_37 ) ;
V_91 -> V_6 = V_6 ;
V_91 -> V_5 = V_89 ;
if ( V_6 )
V_37 -> type = V_49 ;
else
V_37 -> type = V_4 ;
V_91 -> V_90 = V_90 ;
F_48 ( V_54 , V_37 , V_91 , V_51 ) ;
V_60 = F_37 ( V_26 , V_29 , V_88 , V_37 ) ;
if ( V_60 > 0 )
F_49 ( V_95 , V_91 ) ;
}
static T_2 void
F_50 ( struct V_53 * V_54 ,
struct V_25 * V_26 ,
struct V_12 * V_88 ,
struct V_36 * V_37 , T_1 V_19 ,
T_1 V_68 , T_1 V_6 , T_1 V_89 , T_1 V_96 ,
T_1 V_11 , int V_51 )
{
struct V_7 * V_91 ;
struct V_28 * V_29 ;
T_1 V_43 = 0 ;
int V_60 ;
if ( V_51 == V_92 )
V_51 = V_73 ;
V_29 = & V_26 -> V_30 -> V_29 ;
if ( F_44 ( V_89 ) )
V_43 = F_45 ( & V_54 -> V_93 ) ;
F_46 ( & V_37 -> V_33 , 1 ) ;
V_37 -> V_19 = V_19 ;
V_37 -> V_68 = V_68 ;
V_37 -> V_52 = 1 ;
V_37 -> V_51 = V_51 ;
V_37 -> V_94 = 0 ;
V_37 -> V_34 = 1 ;
V_37 -> V_43 = V_43 ;
F_47 ( & V_37 -> V_39 ) ;
F_47 ( & V_37 -> V_40 ) ;
V_91 = F_30 ( V_37 ) ;
V_91 -> V_6 = V_6 ;
V_91 -> V_5 = V_89 ;
if ( V_6 )
V_37 -> type = V_50 ;
else
V_37 -> type = V_9 ;
V_91 -> V_10 = V_96 ;
V_91 -> V_11 = V_11 ;
F_51 ( V_54 , V_37 , V_91 , V_51 ) ;
V_60 = F_37 ( V_26 , V_29 , V_88 , V_37 ) ;
if ( V_60 > 0 )
F_49 ( V_97 , V_91 ) ;
}
int F_52 ( struct V_53 * V_54 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_68 , T_1 V_6 ,
T_1 V_89 , int V_90 , int V_51 ,
struct V_98 * V_81 )
{
struct V_1 * V_37 ;
struct V_12 * V_88 ;
struct V_28 * V_29 ;
struct V_99 * V_100 = NULL ;
int V_101 ;
F_41 ( V_81 && V_81 -> V_55 ) ;
V_37 = F_53 ( V_95 , V_102 ) ;
if ( ! V_37 )
return - V_103 ;
V_88 = F_53 ( V_104 , V_102 ) ;
if ( ! V_88 )
goto V_105;
if ( F_54 ( V_106 , & V_54 -> V_107 ) &&
F_44 ( V_89 ) ) {
V_100 = F_55 ( sizeof( * V_100 ) , V_102 ) ;
if ( ! V_100 )
goto V_108;
}
V_88 -> V_81 = V_81 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
V_88 = F_56 ( V_54 , V_26 , & V_88 -> V_8 , V_100 ,
V_19 , V_68 , 0 , 0 , V_51 , 0 ,
& V_101 ) ;
F_43 ( V_54 , V_26 , V_88 , & V_37 -> V_8 , V_19 ,
V_68 , V_6 , V_89 , V_90 , V_51 ) ;
F_14 ( & V_29 -> V_31 ) ;
if ( V_101 )
return F_57 ( V_54 , V_100 ) ;
return 0 ;
V_108:
F_49 ( V_104 , V_88 ) ;
V_105:
F_49 ( V_95 , V_37 ) ;
return - V_103 ;
}
int F_58 ( struct V_53 * V_54 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_68 ,
T_1 V_6 , T_1 V_89 ,
T_1 V_96 , T_1 V_11 , T_1 V_109 , int V_51 )
{
struct V_7 * V_37 ;
struct V_12 * V_88 ;
struct V_28 * V_29 ;
struct V_99 * V_100 = NULL ;
int V_101 ;
V_37 = F_53 ( V_97 , V_102 ) ;
if ( ! V_37 )
return - V_103 ;
V_88 = F_53 ( V_104 , V_102 ) ;
if ( ! V_88 ) {
F_49 ( V_97 , V_37 ) ;
return - V_103 ;
}
if ( F_54 ( V_106 , & V_54 -> V_107 ) &&
F_44 ( V_89 ) ) {
V_100 = F_55 ( sizeof( * V_100 ) , V_102 ) ;
if ( ! V_100 ) {
F_49 ( V_97 , V_37 ) ;
F_49 ( V_104 ,
V_88 ) ;
return - V_103 ;
}
}
V_88 -> V_81 = NULL ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
V_88 = F_56 ( V_54 , V_26 , & V_88 -> V_8 , V_100 ,
V_19 , V_68 , V_89 , V_109 ,
V_51 , 1 , & V_101 ) ;
F_50 ( V_54 , V_26 , V_88 , & V_37 -> V_8 , V_19 ,
V_68 , V_6 , V_89 , V_96 , V_11 ,
V_51 ) ;
F_14 ( & V_29 -> V_31 ) ;
if ( V_101 )
return F_57 ( V_54 , V_100 ) ;
return 0 ;
}
int F_59 ( struct V_53 * V_54 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_68 ,
struct V_98 * V_81 )
{
struct V_12 * V_88 ;
struct V_28 * V_29 ;
V_88 = F_53 ( V_104 , V_102 ) ;
if ( ! V_88 )
return - V_103 ;
V_88 -> V_81 = V_81 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
F_56 ( V_54 , V_26 , & V_88 -> V_8 , NULL , V_19 ,
V_68 , 0 , 0 , V_110 ,
V_81 -> V_55 , NULL ) ;
F_14 ( & V_29 -> V_31 ) ;
return 0 ;
}
struct V_12 *
F_60 ( struct V_28 * V_29 , T_1 V_19 )
{
return F_7 ( & V_29 -> V_38 , V_19 , 0 ) ;
}
void F_61 ( void )
{
F_62 ( V_104 ) ;
F_62 ( V_95 ) ;
F_62 ( V_97 ) ;
F_62 ( V_111 ) ;
}
int F_63 ( void )
{
V_104 = F_64 (
L_2 ,
sizeof( struct V_12 ) , 0 ,
V_112 , NULL ) ;
if ( ! V_104 )
goto V_113;
V_95 = F_64 (
L_3 ,
sizeof( struct V_1 ) , 0 ,
V_112 , NULL ) ;
if ( ! V_95 )
goto V_113;
V_97 = F_64 (
L_4 ,
sizeof( struct V_7 ) , 0 ,
V_112 , NULL ) ;
if ( ! V_97 )
goto V_113;
V_111 = F_64 (
L_5 ,
sizeof( struct V_98 ) , 0 ,
V_112 , NULL ) ;
if ( ! V_111 )
goto V_113;
return 0 ;
V_113:
F_61 () ;
return - V_103 ;
}
