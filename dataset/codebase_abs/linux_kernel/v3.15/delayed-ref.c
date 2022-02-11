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
int V_30 )
{
struct V_20 * V_31 ;
struct V_28 * V_23 ;
V_31 = V_5 -> V_20 ;
V_23 = NULL ;
while ( V_31 ) {
V_23 = F_8 ( V_31 , struct V_28 , V_29 ) ;
if ( V_14 < V_23 -> V_8 . V_14 )
V_31 = V_31 -> V_26 ;
else if ( V_14 > V_23 -> V_8 . V_14 )
V_31 = V_31 -> V_27 ;
else
return V_23 ;
}
if ( V_23 && V_30 ) {
if ( V_14 > V_23 -> V_8 . V_14 ) {
V_31 = F_13 ( & V_23 -> V_29 ) ;
if ( ! V_31 )
V_31 = F_14 ( V_5 ) ;
V_23 = F_8 ( V_31 , struct V_28 ,
V_29 ) ;
return V_23 ;
}
return V_23 ;
}
return NULL ;
}
int F_15 ( struct V_32 * V_33 ,
struct V_28 * V_34 )
{
struct V_35 * V_36 ;
V_36 = & V_33 -> V_37 -> V_36 ;
F_16 ( & V_36 -> V_38 ) ;
if ( F_17 ( & V_34 -> V_39 ) )
return 0 ;
F_18 ( & V_34 -> V_8 . V_40 ) ;
F_19 ( & V_36 -> V_38 ) ;
F_20 ( & V_34 -> V_39 ) ;
F_21 ( & V_36 -> V_38 ) ;
if ( ! V_34 -> V_8 . V_41 ) {
F_22 ( & V_34 -> V_39 ) ;
F_23 ( & V_34 -> V_8 ) ;
return - V_42 ;
}
F_23 ( & V_34 -> V_8 ) ;
return 0 ;
}
static inline void F_24 ( struct V_32 * V_33 ,
struct V_35 * V_36 ,
struct V_28 * V_34 ,
struct V_12 * V_43 )
{
if ( F_25 ( V_43 ) ) {
V_34 = F_26 ( V_43 ) ;
F_27 ( & V_34 -> V_29 , & V_36 -> V_44 ) ;
} else {
F_16 ( & V_34 -> V_38 ) ;
F_27 ( & V_43 -> V_20 , & V_34 -> V_45 ) ;
}
V_43 -> V_41 = 0 ;
F_23 ( V_43 ) ;
F_28 ( & V_36 -> V_46 ) ;
if ( V_33 -> V_47 )
V_33 -> V_47 -- ;
}
static int F_29 ( struct V_32 * V_33 ,
struct V_35 * V_36 ,
struct V_28 * V_34 ,
struct V_12 * V_43 , T_1 V_16 )
{
struct V_20 * V_8 ;
int V_48 = 0 ;
int V_49 = 0 ;
V_8 = F_13 ( & V_43 -> V_20 ) ;
while ( ! V_49 && V_8 ) {
struct V_12 * V_50 ;
V_50 = F_8 ( V_8 , struct V_12 , V_20 ) ;
V_8 = F_13 ( V_8 ) ;
if ( V_16 && V_50 -> V_16 >= V_16 )
break;
if ( F_3 ( V_43 , V_50 , 0 ) )
continue;
if ( V_43 -> V_51 == V_50 -> V_51 ) {
V_48 = V_50 -> V_52 ;
} else {
if ( V_43 -> V_52 < V_50 -> V_52 ) {
struct V_12 * V_53 ;
V_53 = V_43 ;
V_43 = V_50 ;
V_50 = V_53 ;
V_49 = 1 ;
}
V_48 = - V_50 -> V_52 ;
}
F_24 ( V_33 , V_36 , V_34 , V_50 ) ;
V_43 -> V_52 += V_48 ;
if ( V_43 -> V_52 == 0 ) {
F_24 ( V_33 , V_36 , V_34 , V_43 ) ;
V_49 = 1 ;
} else {
F_30 ( V_43 -> type == V_4 ||
V_43 -> type == V_17 ) ;
}
}
return V_49 ;
}
void F_31 ( struct V_32 * V_33 ,
struct V_54 * V_55 ,
struct V_35 * V_36 ,
struct V_28 * V_34 )
{
struct V_20 * V_8 ;
T_1 V_16 = 0 ;
F_16 ( & V_34 -> V_38 ) ;
if ( V_34 -> V_56 )
return;
F_21 ( & V_55 -> V_57 ) ;
if ( ! F_32 ( & V_55 -> V_58 ) ) {
struct V_59 * V_60 ;
V_60 = F_33 ( & V_55 -> V_58 ,
struct V_59 , V_61 ) ;
V_16 = V_60 -> V_16 ;
}
F_19 ( & V_55 -> V_57 ) ;
V_8 = F_14 ( & V_34 -> V_45 ) ;
while ( V_8 ) {
struct V_12 * V_43 ;
V_43 = F_8 ( V_8 , struct V_12 ,
V_20 ) ;
if ( V_16 && V_43 -> V_16 >= V_16 )
break;
if ( F_29 ( V_33 , V_36 , V_34 , V_43 , V_16 ) )
V_8 = F_14 ( & V_34 -> V_45 ) ;
else
V_8 = F_13 ( & V_43 -> V_20 ) ;
}
}
int F_34 ( struct V_54 * V_55 ,
struct V_35 * V_36 ,
T_1 V_16 )
{
struct V_59 * V_60 ;
int V_62 = 0 ;
F_21 ( & V_55 -> V_57 ) ;
if ( ! F_32 ( & V_55 -> V_58 ) ) {
V_60 = F_33 ( & V_55 -> V_58 ,
struct V_59 , V_61 ) ;
if ( V_16 >= V_60 -> V_16 ) {
F_35 ( L_1 ,
( V_63 ) ( V_16 >> 32 ) , ( V_63 ) V_16 ,
( V_63 ) ( V_60 -> V_16 >> 32 ) , ( V_63 ) V_60 -> V_16 ,
V_36 ) ;
V_62 = 1 ;
}
}
F_19 ( & V_55 -> V_57 ) ;
return V_62 ;
}
struct V_28 *
F_36 ( struct V_32 * V_33 )
{
struct V_35 * V_36 ;
struct V_28 * V_34 ;
T_1 V_64 ;
bool V_65 = false ;
V_36 = & V_33 -> V_37 -> V_36 ;
V_66:
V_64 = V_36 -> V_67 ;
V_34 = F_12 ( & V_36 -> V_44 , V_64 , 1 ) ;
if ( ! V_34 && ! V_65 ) {
V_36 -> V_67 = 0 ;
V_64 = 0 ;
V_65 = true ;
V_34 = F_12 ( & V_36 -> V_44 , V_64 , 1 ) ;
if ( ! V_34 )
return NULL ;
} else if ( ! V_34 && V_65 ) {
return NULL ;
}
while ( V_34 -> V_68 ) {
struct V_20 * V_8 ;
V_8 = F_13 ( & V_34 -> V_29 ) ;
if ( ! V_8 ) {
if ( V_65 )
return NULL ;
V_36 -> V_67 = 0 ;
V_64 = 0 ;
V_65 = true ;
goto V_66;
}
V_34 = F_8 ( V_8 , struct V_28 ,
V_29 ) ;
}
V_34 -> V_68 = 1 ;
F_30 ( V_36 -> V_69 == 0 ) ;
V_36 -> V_69 -- ;
V_36 -> V_67 = V_34 -> V_8 . V_14 +
V_34 -> V_8 . V_70 ;
return V_34 ;
}
static T_2 void
F_37 ( struct V_32 * V_33 ,
struct V_35 * V_36 ,
struct V_28 * V_34 ,
struct V_12 * V_71 ,
struct V_12 * V_72 )
{
if ( V_72 -> V_51 != V_71 -> V_51 ) {
V_71 -> V_52 -- ;
if ( V_71 -> V_52 == 0 )
F_24 ( V_33 , V_36 , V_34 , V_71 ) ;
else
F_30 ( V_71 -> type == V_4 ||
V_71 -> type == V_17 ) ;
} else {
F_30 ( V_71 -> type == V_4 ||
V_71 -> type == V_17 ) ;
V_71 -> V_52 += V_72 -> V_52 ;
}
}
static T_2 void
F_38 ( struct V_12 * V_71 ,
struct V_12 * V_72 )
{
struct V_28 * V_73 ;
struct V_28 * V_43 ;
V_73 = F_26 ( V_71 ) ;
V_43 = F_26 ( V_72 ) ;
F_39 ( V_73 -> V_56 != V_43 -> V_56 ) ;
F_21 ( & V_73 -> V_38 ) ;
if ( V_43 -> V_74 ) {
V_73 -> V_74 = V_43 -> V_74 ;
V_71 -> V_70 = V_72 -> V_70 ;
}
if ( V_43 -> V_75 ) {
if ( ! V_73 -> V_75 ) {
V_73 -> V_75 = V_43 -> V_75 ;
} else {
if ( V_43 -> V_75 -> V_76 ) {
memcpy ( & V_73 -> V_75 -> V_77 ,
& V_43 -> V_75 -> V_77 ,
sizeof( V_43 -> V_75 -> V_77 ) ) ;
V_73 -> V_75 -> V_76 = 1 ;
}
if ( V_43 -> V_75 -> V_78 ) {
V_73 -> V_75 -> V_79 |=
V_43 -> V_75 -> V_79 ;
V_73 -> V_75 -> V_78 = 1 ;
}
F_40 ( V_43 -> V_75 ) ;
}
}
V_71 -> V_52 += V_72 -> V_52 ;
F_19 ( & V_73 -> V_38 ) ;
}
T_2 void
F_41 ( struct V_54 * V_55 ,
struct V_32 * V_33 ,
struct V_28 * V_80 ,
struct V_12 * V_43 , T_1 V_14 ,
T_1 V_70 , T_1 V_6 , T_1 V_45 , int V_81 ,
int V_51 , int V_82 )
{
struct V_12 * V_71 ;
struct V_1 * V_83 ;
struct V_35 * V_36 ;
T_1 V_16 = 0 ;
if ( V_51 == V_84 )
V_51 = V_85 ;
V_36 = & V_33 -> V_37 -> V_36 ;
F_42 ( & V_43 -> V_40 , 1 ) ;
V_43 -> V_14 = V_14 ;
V_43 -> V_70 = V_70 ;
V_43 -> V_52 = 1 ;
V_43 -> V_51 = V_51 ;
V_43 -> V_15 = 0 ;
V_43 -> V_41 = 1 ;
if ( F_43 ( V_82 , V_45 ) )
V_16 = F_44 ( V_55 , & V_33 -> V_86 ) ;
V_43 -> V_16 = V_16 ;
V_83 = F_4 ( V_43 ) ;
V_83 -> V_6 = V_6 ;
V_83 -> V_5 = V_45 ;
if ( V_6 )
V_43 -> type = V_17 ;
else
V_43 -> type = V_4 ;
V_83 -> V_81 = V_81 ;
F_45 ( V_43 , V_83 , V_51 ) ;
F_21 ( & V_80 -> V_38 ) ;
V_71 = F_7 ( & V_80 -> V_45 , & V_43 -> V_20 ) ;
if ( V_71 ) {
F_37 ( V_33 , V_36 , V_80 , V_71 ,
V_43 ) ;
F_46 ( V_87 , V_83 ) ;
} else {
F_18 ( & V_36 -> V_46 ) ;
V_33 -> V_47 ++ ;
}
F_19 ( & V_80 -> V_38 ) ;
}
static T_2 void
F_47 ( struct V_54 * V_55 ,
struct V_32 * V_33 ,
struct V_28 * V_80 ,
struct V_12 * V_43 , T_1 V_14 ,
T_1 V_70 , T_1 V_6 , T_1 V_45 , T_1 V_88 ,
T_1 V_11 , int V_51 , int V_82 )
{
struct V_12 * V_71 ;
struct V_7 * V_83 ;
struct V_35 * V_36 ;
T_1 V_16 = 0 ;
if ( V_51 == V_84 )
V_51 = V_85 ;
V_36 = & V_33 -> V_37 -> V_36 ;
F_42 ( & V_43 -> V_40 , 1 ) ;
V_43 -> V_14 = V_14 ;
V_43 -> V_70 = V_70 ;
V_43 -> V_52 = 1 ;
V_43 -> V_51 = V_51 ;
V_43 -> V_15 = 0 ;
V_43 -> V_41 = 1 ;
if ( F_43 ( V_82 , V_45 ) )
V_16 = F_44 ( V_55 , & V_33 -> V_86 ) ;
V_43 -> V_16 = V_16 ;
V_83 = F_5 ( V_43 ) ;
V_83 -> V_6 = V_6 ;
V_83 -> V_5 = V_45 ;
if ( V_6 )
V_43 -> type = V_18 ;
else
V_43 -> type = V_9 ;
V_83 -> V_10 = V_88 ;
V_83 -> V_11 = V_11 ;
F_48 ( V_43 , V_83 , V_51 ) ;
F_21 ( & V_80 -> V_38 ) ;
V_71 = F_7 ( & V_80 -> V_45 , & V_43 -> V_20 ) ;
if ( V_71 ) {
F_37 ( V_33 , V_36 , V_80 , V_71 ,
V_43 ) ;
F_46 ( V_89 , V_83 ) ;
} else {
F_18 ( & V_36 -> V_46 ) ;
V_33 -> V_47 ++ ;
}
F_19 ( & V_80 -> V_38 ) ;
}
int F_49 ( struct V_54 * V_55 ,
struct V_32 * V_33 ,
T_1 V_14 , T_1 V_70 , T_1 V_6 ,
T_1 V_45 , int V_81 , int V_51 ,
struct V_90 * V_75 ,
int V_82 )
{
struct V_1 * V_43 ;
struct V_28 * V_80 ;
struct V_35 * V_36 ;
F_39 ( V_75 && V_75 -> V_56 ) ;
V_43 = F_50 ( V_87 , V_91 ) ;
if ( ! V_43 )
return - V_92 ;
V_80 = F_50 ( V_93 , V_91 ) ;
if ( ! V_80 ) {
F_46 ( V_87 , V_43 ) ;
return - V_92 ;
}
V_80 -> V_75 = V_75 ;
V_36 = & V_33 -> V_37 -> V_36 ;
F_21 ( & V_36 -> V_38 ) ;
V_80 = F_51 ( V_55 , V_33 , & V_80 -> V_8 ,
V_14 , V_70 , V_51 , 0 ) ;
F_41 ( V_55 , V_33 , V_80 , & V_43 -> V_8 , V_14 ,
V_70 , V_6 , V_45 , V_81 , V_51 ,
V_82 ) ;
F_19 ( & V_36 -> V_38 ) ;
if ( F_43 ( V_82 , V_45 ) )
F_52 ( V_33 , & V_43 -> V_8 , V_75 ) ;
return 0 ;
}
int F_53 ( struct V_54 * V_55 ,
struct V_32 * V_33 ,
T_1 V_14 , T_1 V_70 ,
T_1 V_6 , T_1 V_45 ,
T_1 V_88 , T_1 V_11 , int V_51 ,
struct V_90 * V_75 ,
int V_82 )
{
struct V_7 * V_43 ;
struct V_28 * V_80 ;
struct V_35 * V_36 ;
F_39 ( V_75 && ! V_75 -> V_56 ) ;
V_43 = F_50 ( V_89 , V_91 ) ;
if ( ! V_43 )
return - V_92 ;
V_80 = F_50 ( V_93 , V_91 ) ;
if ( ! V_80 ) {
F_46 ( V_89 , V_43 ) ;
return - V_92 ;
}
V_80 -> V_75 = V_75 ;
V_36 = & V_33 -> V_37 -> V_36 ;
F_21 ( & V_36 -> V_38 ) ;
V_80 = F_51 ( V_55 , V_33 , & V_80 -> V_8 ,
V_14 , V_70 , V_51 , 1 ) ;
F_47 ( V_55 , V_33 , V_80 , & V_43 -> V_8 , V_14 ,
V_70 , V_6 , V_45 , V_88 , V_11 ,
V_51 , V_82 ) ;
F_19 ( & V_36 -> V_38 ) ;
if ( F_43 ( V_82 , V_45 ) )
F_52 ( V_33 , & V_43 -> V_8 , V_75 ) ;
return 0 ;
}
int F_54 ( struct V_54 * V_55 ,
struct V_32 * V_33 ,
T_1 V_14 , T_1 V_70 ,
struct V_90 * V_75 )
{
struct V_28 * V_80 ;
struct V_35 * V_36 ;
V_80 = F_50 ( V_93 , V_91 ) ;
if ( ! V_80 )
return - V_92 ;
V_80 -> V_75 = V_75 ;
V_36 = & V_33 -> V_37 -> V_36 ;
F_21 ( & V_36 -> V_38 ) ;
F_51 ( V_55 , V_33 , & V_80 -> V_8 , V_14 ,
V_70 , V_94 ,
V_75 -> V_56 ) ;
F_19 ( & V_36 -> V_38 ) ;
return 0 ;
}
struct V_28 *
F_55 ( struct V_32 * V_33 , T_1 V_14 )
{
struct V_35 * V_36 ;
V_36 = & V_33 -> V_37 -> V_36 ;
return F_12 ( & V_36 -> V_44 , V_14 , 0 ) ;
}
void F_56 ( void )
{
if ( V_93 )
F_57 ( V_93 ) ;
if ( V_87 )
F_57 ( V_87 ) ;
if ( V_89 )
F_57 ( V_89 ) ;
if ( V_95 )
F_57 ( V_95 ) ;
}
int F_58 ( void )
{
V_93 = F_59 (
L_2 ,
sizeof( struct V_28 ) , 0 ,
V_96 | V_97 , NULL ) ;
if ( ! V_93 )
goto V_98;
V_87 = F_59 (
L_3 ,
sizeof( struct V_1 ) , 0 ,
V_96 | V_97 , NULL ) ;
if ( ! V_87 )
goto V_98;
V_89 = F_59 (
L_4 ,
sizeof( struct V_7 ) , 0 ,
V_96 | V_97 , NULL ) ;
if ( ! V_89 )
goto V_98;
V_95 = F_59 (
L_5 ,
sizeof( struct V_90 ) , 0 ,
V_96 | V_97 , NULL ) ;
if ( ! V_95 )
goto V_98;
return 0 ;
V_98:
F_56 () ;
return - V_92 ;
}
