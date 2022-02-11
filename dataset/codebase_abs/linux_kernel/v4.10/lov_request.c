static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 , 0 ) ;
F_2 ( & V_2 -> V_5 , 0 ) ;
F_2 ( & V_2 -> V_6 , 0 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_2 ( & V_2 -> V_8 , 1 ) ;
F_4 ( & V_2 -> V_9 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_12 ;
F_6 ( V_2 ) ;
F_7 (pos, n, &set->set_list) {
struct V_13 * V_14 = F_8 ( V_11 ,
struct V_13 ,
V_15 ) ;
F_9 ( & V_14 -> V_15 ) ;
F_10 ( V_14 -> V_16 . V_17 ) ;
F_10 ( V_14 ) ;
}
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_18 )
{
int V_19 = F_12 ( & V_2 -> V_4 ) ;
F_13 ( V_20 , L_1 , V_19 , V_2 -> V_3 ) ;
if ( V_19 == V_2 -> V_3 ) {
if ( V_18 )
return 1 ;
if ( F_14 ( & V_2 -> V_6 ) == 1 )
return 1 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 , int V_21 )
{
V_14 -> V_22 = 1 ;
V_14 -> V_23 = V_21 ;
F_16 ( & V_2 -> V_4 ) ;
if ( V_21 == 0 )
F_16 ( & V_2 -> V_5 ) ;
F_17 ( & V_2 -> V_9 ) ;
}
static void F_18 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
F_19 ( & V_14 -> V_15 , & V_2 -> V_7 ) ;
V_2 -> V_3 ++ ;
V_14 -> V_24 = V_2 ;
}
static int F_20 ( struct V_25 * V_26 , int V_27 )
{
int V_21 ;
struct V_28 * V_29 ;
F_21 ( & V_26 -> V_30 ) ;
V_29 = V_26 -> V_31 [ V_27 ] ;
V_21 = ! V_29 || V_29 -> V_32 ||
( V_29 -> V_33 &&
F_22 ( V_29 -> V_33 ) -> V_34 ) ;
F_23 ( & V_26 -> V_30 ) ;
return V_21 ;
}
static int F_24 ( struct V_25 * V_26 , int V_35 )
{
T_1 V_36 ;
struct V_37 V_38 ;
struct V_28 * V_29 ;
int V_21 = 0 ;
F_21 ( & V_26 -> V_30 ) ;
V_29 = V_26 -> V_31 [ V_35 ] ;
if ( F_25 ( ! V_29 ) ) {
V_21 = 0 ;
goto V_39;
}
if ( F_26 ( V_29 -> V_32 ) ) {
V_21 = 1 ;
goto V_39;
}
if ( V_29 -> V_33 && F_22 ( V_29 -> V_33 ) -> V_34 ) {
V_21 = 0 ;
goto V_39;
}
F_23 ( & V_26 -> V_30 ) ;
F_4 ( & V_36 ) ;
V_38 = F_27 ( F_28 ( V_40 ) ,
F_28 ( 1 ) , NULL , NULL ) ;
V_21 = F_29 ( V_36 , F_20 ( V_26 , V_35 ) , & V_38 ) ;
if ( V_29 -> V_32 )
return 1 ;
return 0 ;
V_39:
F_23 ( & V_26 -> V_30 ) ;
return V_21 ;
}
int F_30 ( struct V_41 * V_42 , struct V_43 * V_44 ,
int V_45 )
{
if ( V_45 ) {
T_2 V_46 = F_31 ( & V_42 -> V_47 . V_26 ,
V_48 , 0 ) ;
if ( V_44 -> V_49 != V_50 )
F_32 ( V_44 -> V_49 , V_46 ) ;
if ( V_44 -> V_51 != V_50 )
F_32 ( V_44 -> V_51 , V_46 ) ;
F_33 ( & V_42 -> V_52 ) ;
memcpy ( & V_42 -> V_53 , V_44 , sizeof( * V_44 ) ) ;
V_42 -> V_54 = F_34 () ;
F_35 ( & V_42 -> V_52 ) ;
return 0 ;
}
return - V_55 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_12 ( & V_2 -> V_4 ) ) {
V_21 = F_30 ( V_2 -> V_56 , V_2 -> V_57 -> V_17 ,
F_12 ( & V_2 -> V_5 ) ) ;
}
F_37 ( V_2 ) ;
return V_21 ;
}
static void F_38 ( struct V_43 * V_44 ,
struct V_43 * V_58 ,
int V_45 )
{
int V_59 = 0 , V_60 = 0 ;
T_3 V_61 ;
if ( V_45 == 0 ) {
memcpy ( V_44 , V_58 , sizeof( * V_58 ) ) ;
} else {
if ( V_44 -> V_62 != V_58 -> V_62 ) {
V_61 = V_44 -> V_62 | V_58 -> V_62 ;
for ( V_59 = 0 ; V_59 <= 64 ; ++ V_59 ) {
if ( V_61 & 1 ) {
if ( V_60 )
break;
V_60 = 1 ;
V_59 = 0 ;
}
V_61 >>= 1 ;
}
}
if ( V_44 -> V_62 < V_58 -> V_62 ) {
V_44 -> V_62 = V_58 -> V_62 ;
V_44 -> V_63 >>= V_59 ;
V_44 -> V_64 >>= V_59 ;
V_44 -> V_65 >>= V_59 ;
} else if ( V_59 != 0 ) {
V_58 -> V_63 >>= V_59 ;
V_58 -> V_64 >>= V_59 ;
V_58 -> V_65 >>= V_59 ;
}
V_44 -> V_63 += V_58 -> V_63 ;
V_44 -> V_64 += V_58 -> V_64 ;
V_44 -> V_65 += V_58 -> V_65 ;
F_39 ( V_44 -> V_49 , V_58 -> V_49 ) ;
F_39 ( V_44 -> V_51 , V_58 -> V_51 ) ;
}
}
static int F_40 ( void * V_66 , int V_21 )
{
struct V_67 * V_68 = V_66 ;
struct V_13 * V_69 ;
struct V_1 * V_2 ;
struct V_43 * V_44 , * V_58 ;
struct V_25 * V_26 ;
struct V_28 * V_29 ;
struct V_41 * V_70 , * V_71 ;
int V_45 ;
V_69 = F_41 ( V_68 , struct V_13 , V_16 ) ;
V_2 = V_69 -> V_24 ;
V_70 = V_2 -> V_56 ;
V_26 = & V_70 -> V_47 . V_26 ;
V_44 = V_2 -> V_57 -> V_17 ;
V_58 = V_68 -> V_17 ;
V_45 = F_12 ( & V_2 -> V_5 ) ;
F_15 ( V_2 , V_69 , V_21 ) ;
if ( V_21 )
goto V_39;
F_42 ( V_70 ) ;
V_29 = V_26 -> V_31 [ V_69 -> V_72 ] ;
if ( ! V_29 || ! V_29 -> V_32 )
goto V_73;
V_71 = F_43 ( V_29 -> V_33 ) ;
F_33 ( & V_71 -> V_52 ) ;
memcpy ( & V_71 -> V_53 , V_58 , sizeof( * V_58 ) ) ;
if ( ( V_68 -> V_74 & V_75 ) == 0 )
V_71 -> V_54 = F_34 () ;
F_35 ( & V_71 -> V_52 ) ;
V_73:
F_38 ( V_44 , V_58 , V_45 ) ;
F_44 ( V_70 ) ;
V_39:
if ( V_2 -> V_57 -> V_74 & V_76 &&
F_11 ( V_2 , 0 ) ) {
F_45 ( NULL , V_2 , V_2 -> V_3 !=
F_12 ( & V_2 -> V_5 ) ) ;
}
return 0 ;
}
int F_46 ( struct V_41 * V_42 , struct V_67 * V_68 ,
struct V_1 * * V_77 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 = & V_42 -> V_47 . V_26 ;
int V_21 = 0 , V_78 ;
V_2 = F_47 ( sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return - V_80 ;
F_1 ( V_2 ) ;
V_2 -> V_56 = V_42 ;
V_2 -> V_57 = V_68 ;
for ( V_78 = 0 ; V_78 < V_26 -> V_81 . V_82 ; V_78 ++ ) {
struct V_13 * V_14 ;
if ( ! V_26 -> V_31 [ V_78 ] ||
( V_68 -> V_74 & V_83 &&
! V_26 -> V_31 [ V_78 ] -> V_32 ) ) {
F_13 ( V_84 , L_2 , V_78 ) ;
continue;
}
if ( ! V_26 -> V_31 [ V_78 ] -> V_32 )
F_24 ( V_26 , V_78 ) ;
if ( ! V_26 -> V_31 [ V_78 ] -> V_33 ) {
F_13 ( V_84 , L_3 , V_78 ) ;
continue;
}
V_14 = F_47 ( sizeof( * V_14 ) , V_79 ) ;
if ( ! V_14 ) {
V_21 = - V_80 ;
goto V_85;
}
V_14 -> V_16 . V_17 = F_47 ( sizeof( * V_14 -> V_16 . V_17 ) ,
V_79 ) ;
if ( ! V_14 -> V_16 . V_17 ) {
F_10 ( V_14 ) ;
V_21 = - V_80 ;
goto V_85;
}
V_14 -> V_72 = V_78 ;
V_14 -> V_16 . V_86 = F_40 ;
V_14 -> V_16 . V_74 = V_68 -> V_74 ;
F_18 ( V_14 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_21 = - V_55 ;
goto V_85;
}
* V_77 = V_2 ;
return V_21 ;
V_85:
F_36 ( V_2 ) ;
return V_21 ;
}
