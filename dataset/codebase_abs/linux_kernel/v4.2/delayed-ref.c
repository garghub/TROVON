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
int F_25 ( struct V_42 * V_43 ,
struct V_28 * V_29 ,
T_1 V_44 )
{
struct V_45 * V_46 ;
int V_47 = 0 ;
F_16 ( & V_43 -> V_48 ) ;
if ( ! F_26 ( & V_43 -> V_49 ) ) {
V_46 = F_27 ( & V_43 -> V_49 ,
struct V_45 , V_39 ) ;
if ( V_44 >= V_46 -> V_44 ) {
F_28 ( L_1 ,
( V_50 ) ( V_44 >> 32 ) , ( V_50 ) V_44 ,
( V_50 ) ( V_46 -> V_44 >> 32 ) , ( V_50 ) V_46 -> V_44 ,
V_29 ) ;
V_47 = 1 ;
}
}
F_14 ( & V_43 -> V_48 ) ;
return V_47 ;
}
struct V_12 *
F_29 ( struct V_25 * V_26 )
{
struct V_28 * V_29 ;
struct V_12 * V_27 ;
T_1 V_51 ;
bool V_52 = false ;
V_29 = & V_26 -> V_30 -> V_29 ;
V_53:
V_51 = V_29 -> V_54 ;
V_27 = F_7 ( & V_29 -> V_38 , V_51 , 1 ) ;
if ( ! V_27 && ! V_52 ) {
V_29 -> V_54 = 0 ;
V_51 = 0 ;
V_52 = true ;
V_27 = F_7 ( & V_29 -> V_38 , V_51 , 1 ) ;
if ( ! V_27 )
return NULL ;
} else if ( ! V_27 && V_52 ) {
return NULL ;
}
while ( V_27 -> V_55 ) {
struct V_14 * V_8 ;
V_8 = F_8 ( & V_27 -> V_20 ) ;
if ( ! V_8 ) {
if ( V_52 )
return NULL ;
V_29 -> V_54 = 0 ;
V_51 = 0 ;
V_52 = true ;
goto V_53;
}
V_27 = F_4 ( V_8 , struct V_12 ,
V_20 ) ;
}
V_27 -> V_55 = 1 ;
F_30 ( V_29 -> V_56 == 0 ) ;
V_29 -> V_56 -- ;
V_29 -> V_54 = V_27 -> V_8 . V_19 +
V_27 -> V_8 . V_57 ;
return V_27 ;
}
static int
F_31 ( struct V_25 * V_26 ,
struct V_28 * V_5 ,
struct V_12 * V_58 ,
struct V_36 * V_37 )
{
struct V_36 * V_59 ;
int V_60 ;
int V_47 = 0 ;
F_16 ( & V_58 -> V_31 ) ;
if ( F_26 ( & V_58 -> V_61 ) )
goto V_62;
V_59 = F_32 ( V_58 -> V_61 . V_63 , struct V_36 ,
V_39 ) ;
if ( V_59 -> type != V_37 -> type || V_59 -> V_64 != V_37 -> V_64 ||
V_59 -> V_44 != V_37 -> V_44 )
goto V_62;
if ( ( V_59 -> type == V_4 ||
V_59 -> type == V_65 ) &&
F_1 ( F_33 ( V_59 ) ,
F_33 ( V_37 ) ,
V_37 -> type ) )
goto V_62;
if ( ( V_59 -> type == V_9 ||
V_59 -> type == V_66 ) &&
F_2 ( F_34 ( V_59 ) ,
F_34 ( V_37 ) ) )
goto V_62;
V_47 = 1 ;
if ( V_59 -> V_67 == V_37 -> V_67 ) {
V_60 = V_37 -> V_68 ;
} else {
if ( V_59 -> V_68 < V_37 -> V_68 ) {
V_59 -> V_67 = V_37 -> V_67 ;
V_60 = - V_59 -> V_68 ;
V_59 -> V_68 = V_37 -> V_68 ;
} else
V_60 = - V_37 -> V_68 ;
}
V_59 -> V_68 += V_60 ;
if ( V_59 -> V_68 == 0 )
F_19 ( V_26 , V_5 , V_58 , V_59 ) ;
F_14 ( & V_58 -> V_31 ) ;
return V_47 ;
V_62:
F_35 ( & V_37 -> V_39 , & V_58 -> V_61 ) ;
F_13 ( & V_5 -> V_40 ) ;
V_26 -> V_41 ++ ;
F_14 ( & V_58 -> V_31 ) ;
return V_47 ;
}
static T_2 void
F_36 ( struct V_28 * V_29 ,
struct V_36 * V_69 ,
struct V_36 * V_70 )
{
struct V_12 * V_71 ;
struct V_12 * V_37 ;
int V_72 ;
V_71 = F_21 ( V_69 ) ;
V_37 = F_21 ( V_70 ) ;
F_37 ( V_71 -> V_73 != V_37 -> V_73 ) ;
F_16 ( & V_71 -> V_31 ) ;
if ( V_37 -> V_74 ) {
V_71 -> V_74 = V_37 -> V_74 ;
V_69 -> V_57 = V_70 -> V_57 ;
}
if ( V_37 -> V_75 ) {
if ( ! V_71 -> V_75 ) {
V_71 -> V_75 = V_37 -> V_75 ;
} else {
if ( V_37 -> V_75 -> V_76 ) {
memcpy ( & V_71 -> V_75 -> V_77 ,
& V_37 -> V_75 -> V_77 ,
sizeof( V_37 -> V_75 -> V_77 ) ) ;
V_71 -> V_75 -> V_76 = 1 ;
}
if ( V_37 -> V_75 -> V_78 ) {
V_71 -> V_75 -> V_79 |=
V_37 -> V_75 -> V_79 ;
V_71 -> V_75 -> V_78 = 1 ;
}
F_38 ( V_37 -> V_75 ) ;
}
}
V_72 = V_71 -> V_80 ;
V_69 -> V_68 += V_70 -> V_68 ;
V_71 -> V_80 += V_70 -> V_68 ;
if ( V_71 -> V_73 ) {
if ( V_71 -> V_80 >= 0 && V_72 < 0 )
V_29 -> V_81 -= V_69 -> V_57 ;
if ( V_71 -> V_80 < 0 && V_72 >= 0 )
V_29 -> V_81 += V_69 -> V_57 ;
}
F_14 ( & V_71 -> V_31 ) ;
}
T_2 void
F_39 ( struct V_42 * V_43 ,
struct V_25 * V_26 ,
struct V_12 * V_82 ,
struct V_36 * V_37 , T_1 V_19 ,
T_1 V_57 , T_1 V_6 , T_1 V_83 , int V_84 ,
int V_67 , int V_64 )
{
struct V_1 * V_85 ;
struct V_28 * V_29 ;
T_1 V_44 = 0 ;
int V_47 ;
if ( V_67 == V_86 )
V_67 = V_87 ;
if ( F_40 ( V_83 ) )
V_44 = F_41 ( & V_43 -> V_88 ) ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_42 ( & V_37 -> V_33 , 1 ) ;
V_37 -> V_19 = V_19 ;
V_37 -> V_57 = V_57 ;
V_37 -> V_68 = 1 ;
V_37 -> V_67 = V_67 ;
V_37 -> V_89 = 0 ;
V_37 -> V_34 = 1 ;
V_37 -> V_64 = V_64 ;
V_37 -> V_44 = V_44 ;
V_85 = F_33 ( V_37 ) ;
V_85 -> V_6 = V_6 ;
V_85 -> V_5 = V_83 ;
if ( V_6 )
V_37 -> type = V_65 ;
else
V_37 -> type = V_4 ;
V_85 -> V_84 = V_84 ;
F_43 ( V_37 , V_85 , V_67 ) ;
V_47 = F_31 ( V_26 , V_29 , V_82 , V_37 ) ;
if ( V_47 > 0 )
F_44 ( V_90 , V_85 ) ;
}
static T_2 void
F_45 ( struct V_42 * V_43 ,
struct V_25 * V_26 ,
struct V_12 * V_82 ,
struct V_36 * V_37 , T_1 V_19 ,
T_1 V_57 , T_1 V_6 , T_1 V_83 , T_1 V_91 ,
T_1 V_11 , int V_67 , int V_64 )
{
struct V_7 * V_85 ;
struct V_28 * V_29 ;
T_1 V_44 = 0 ;
int V_47 ;
if ( V_67 == V_86 )
V_67 = V_87 ;
V_29 = & V_26 -> V_30 -> V_29 ;
if ( F_40 ( V_83 ) )
V_44 = F_41 ( & V_43 -> V_88 ) ;
F_42 ( & V_37 -> V_33 , 1 ) ;
V_37 -> V_19 = V_19 ;
V_37 -> V_57 = V_57 ;
V_37 -> V_68 = 1 ;
V_37 -> V_67 = V_67 ;
V_37 -> V_89 = 0 ;
V_37 -> V_34 = 1 ;
V_37 -> V_64 = V_64 ;
V_37 -> V_44 = V_44 ;
V_85 = F_34 ( V_37 ) ;
V_85 -> V_6 = V_6 ;
V_85 -> V_5 = V_83 ;
if ( V_6 )
V_37 -> type = V_66 ;
else
V_37 -> type = V_9 ;
V_85 -> V_10 = V_91 ;
V_85 -> V_11 = V_11 ;
F_46 ( V_37 , V_85 , V_67 ) ;
V_47 = F_31 ( V_26 , V_29 , V_82 , V_37 ) ;
if ( V_47 > 0 )
F_44 ( V_92 , V_85 ) ;
}
int F_47 ( struct V_42 * V_43 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_57 , T_1 V_6 ,
T_1 V_83 , int V_84 , int V_67 ,
struct V_93 * V_75 ,
int V_64 )
{
struct V_1 * V_37 ;
struct V_12 * V_82 ;
struct V_28 * V_29 ;
struct V_94 * V_95 = NULL ;
if ( ! F_40 ( V_83 ) || ! V_43 -> V_96 )
V_64 = 0 ;
F_37 ( V_75 && V_75 -> V_73 ) ;
V_37 = F_48 ( V_90 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_82 = F_48 ( V_99 , V_97 ) ;
if ( ! V_82 )
goto V_100;
if ( V_43 -> V_96 && F_40 ( V_83 ) ) {
V_95 = F_49 ( sizeof( * V_95 ) , V_97 ) ;
if ( ! V_95 )
goto V_101;
}
V_82 -> V_75 = V_75 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
V_82 = F_50 ( V_43 , V_26 , & V_82 -> V_8 , V_95 ,
V_19 , V_57 , V_67 , 0 ) ;
F_39 ( V_43 , V_26 , V_82 , & V_37 -> V_8 , V_19 ,
V_57 , V_6 , V_83 , V_84 , V_67 ,
V_64 ) ;
F_14 ( & V_29 -> V_31 ) ;
return 0 ;
V_101:
F_44 ( V_99 , V_82 ) ;
V_100:
F_44 ( V_90 , V_37 ) ;
return - V_98 ;
}
int F_51 ( struct V_42 * V_43 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_57 ,
T_1 V_6 , T_1 V_83 ,
T_1 V_91 , T_1 V_11 , int V_67 ,
struct V_93 * V_75 ,
int V_64 )
{
struct V_7 * V_37 ;
struct V_12 * V_82 ;
struct V_28 * V_29 ;
struct V_94 * V_95 = NULL ;
if ( ! F_40 ( V_83 ) || ! V_43 -> V_96 )
V_64 = 0 ;
F_37 ( V_75 && ! V_75 -> V_73 ) ;
V_37 = F_48 ( V_92 , V_97 ) ;
if ( ! V_37 )
return - V_98 ;
V_82 = F_48 ( V_99 , V_97 ) ;
if ( ! V_82 ) {
F_44 ( V_92 , V_37 ) ;
return - V_98 ;
}
if ( V_43 -> V_96 && F_40 ( V_83 ) ) {
V_95 = F_49 ( sizeof( * V_95 ) , V_97 ) ;
if ( ! V_95 ) {
F_44 ( V_92 , V_37 ) ;
F_44 ( V_99 ,
V_82 ) ;
return - V_98 ;
}
}
V_82 -> V_75 = V_75 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
V_82 = F_50 ( V_43 , V_26 , & V_82 -> V_8 , V_95 ,
V_19 , V_57 , V_67 , 1 ) ;
F_45 ( V_43 , V_26 , V_82 , & V_37 -> V_8 , V_19 ,
V_57 , V_6 , V_83 , V_91 , V_11 ,
V_67 , V_64 ) ;
F_14 ( & V_29 -> V_31 ) ;
return 0 ;
}
int F_52 ( struct V_42 * V_43 ,
struct V_25 * V_26 ,
T_1 V_19 , T_1 V_57 ,
struct V_93 * V_75 )
{
struct V_12 * V_82 ;
struct V_28 * V_29 ;
V_82 = F_48 ( V_99 , V_97 ) ;
if ( ! V_82 )
return - V_98 ;
V_82 -> V_75 = V_75 ;
V_29 = & V_26 -> V_30 -> V_29 ;
F_16 ( & V_29 -> V_31 ) ;
F_50 ( V_43 , V_26 , & V_82 -> V_8 , NULL , V_19 ,
V_57 , V_102 ,
V_75 -> V_73 ) ;
F_14 ( & V_29 -> V_31 ) ;
return 0 ;
}
struct V_12 *
F_53 ( struct V_25 * V_26 , T_1 V_19 )
{
struct V_28 * V_29 ;
V_29 = & V_26 -> V_30 -> V_29 ;
return F_7 ( & V_29 -> V_38 , V_19 , 0 ) ;
}
void F_54 ( void )
{
if ( V_99 )
F_55 ( V_99 ) ;
if ( V_90 )
F_55 ( V_90 ) ;
if ( V_92 )
F_55 ( V_92 ) ;
if ( V_103 )
F_55 ( V_103 ) ;
}
int F_56 ( void )
{
V_99 = F_57 (
L_2 ,
sizeof( struct V_12 ) , 0 ,
V_104 | V_105 , NULL ) ;
if ( ! V_99 )
goto V_106;
V_90 = F_57 (
L_3 ,
sizeof( struct V_1 ) , 0 ,
V_104 | V_105 , NULL ) ;
if ( ! V_90 )
goto V_106;
V_92 = F_57 (
L_4 ,
sizeof( struct V_7 ) , 0 ,
V_104 | V_105 , NULL ) ;
if ( ! V_92 )
goto V_106;
V_103 = F_57 (
L_5 ,
sizeof( struct V_93 ) , 0 ,
V_104 | V_105 , NULL ) ;
if ( ! V_103 )
goto V_106;
return 0 ;
V_106:
F_54 () ;
return - V_98 ;
}
