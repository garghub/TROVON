static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 , 0 ) ;
F_2 ( & V_2 -> V_5 , 0 ) ;
F_3 ( & V_2 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_9 ;
F_5 ( V_2 ) ;
F_6 (pos, n, &set->set_list) {
struct V_10 * V_11 = F_7 ( V_8 ,
struct V_10 ,
V_12 ) ;
F_8 ( & V_11 -> V_12 ) ;
F_9 ( V_11 -> V_13 . V_14 ) ;
F_9 ( V_11 ) ;
}
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_10 * V_11 , int V_15 )
{
F_11 ( & V_2 -> V_4 ) ;
if ( V_15 == 0 )
F_11 ( & V_2 -> V_5 ) ;
}
static void F_12 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
F_13 ( & V_11 -> V_12 , & V_2 -> V_6 ) ;
V_2 -> V_3 ++ ;
V_11 -> V_16 = V_2 ;
}
static int F_14 ( struct V_17 * V_18 , int V_19 )
{
int V_15 ;
struct V_20 * V_21 ;
F_15 ( & V_18 -> V_22 ) ;
V_21 = V_18 -> V_23 [ V_19 ] ;
V_15 = ! V_21 || V_21 -> V_24 ||
( V_21 -> V_25 &&
F_16 ( V_21 -> V_25 ) -> V_26 ) ;
F_17 ( & V_18 -> V_22 ) ;
return V_15 ;
}
static int F_18 ( struct V_17 * V_18 , int V_27 )
{
T_1 V_28 ;
struct V_29 V_30 ;
struct V_20 * V_21 ;
int V_15 = 0 ;
F_15 ( & V_18 -> V_22 ) ;
V_21 = V_18 -> V_23 [ V_27 ] ;
if ( F_19 ( ! V_21 ) ) {
V_15 = 0 ;
goto V_31;
}
if ( F_20 ( V_21 -> V_24 ) ) {
V_15 = 1 ;
goto V_31;
}
if ( V_21 -> V_25 && F_16 ( V_21 -> V_25 ) -> V_26 ) {
V_15 = 0 ;
goto V_31;
}
F_17 ( & V_18 -> V_22 ) ;
F_21 ( & V_28 ) ;
V_30 = F_22 ( F_23 ( V_32 ) ,
F_23 ( 1 ) , NULL , NULL ) ;
V_15 = F_24 ( V_28 , F_14 ( V_18 , V_27 ) , & V_30 ) ;
if ( V_21 -> V_24 )
return 1 ;
return 0 ;
V_31:
F_17 ( & V_18 -> V_22 ) ;
return V_15 ;
}
static int F_25 ( struct V_33 * V_34 , struct V_35 * V_36 ,
int V_37 )
{
if ( V_37 ) {
T_2 V_38 = F_26 ( & V_34 -> V_39 . V_18 ,
V_40 , 0 ) ;
if ( V_36 -> V_41 != V_42 )
F_27 ( V_36 -> V_41 , V_38 ) ;
if ( V_36 -> V_43 != V_42 )
F_27 ( V_36 -> V_43 , V_38 ) ;
F_28 ( & V_34 -> V_44 ) ;
memcpy ( & V_34 -> V_45 , V_36 , sizeof( * V_36 ) ) ;
V_34 -> V_46 = F_29 () ;
F_30 ( & V_34 -> V_44 ) ;
return 0 ;
}
return - V_47 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_32 ( & V_2 -> V_4 ) ) {
V_15 = F_25 ( V_2 -> V_48 , V_2 -> V_49 -> V_14 ,
F_32 ( & V_2 -> V_5 ) ) ;
}
F_4 ( V_2 ) ;
return V_15 ;
}
static void F_33 ( struct V_35 * V_36 ,
struct V_35 * V_50 ,
int V_37 )
{
int V_51 = 0 , V_52 = 0 ;
T_3 V_53 ;
if ( V_37 == 0 ) {
memcpy ( V_36 , V_50 , sizeof( * V_50 ) ) ;
} else {
if ( V_36 -> V_54 != V_50 -> V_54 ) {
V_53 = V_36 -> V_54 | V_50 -> V_54 ;
for ( V_51 = 0 ; V_51 <= 64 ; ++ V_51 ) {
if ( V_53 & 1 ) {
if ( V_52 )
break;
V_52 = 1 ;
V_51 = 0 ;
}
V_53 >>= 1 ;
}
}
if ( V_36 -> V_54 < V_50 -> V_54 ) {
V_36 -> V_54 = V_50 -> V_54 ;
V_36 -> V_55 >>= V_51 ;
V_36 -> V_56 >>= V_51 ;
V_36 -> V_57 >>= V_51 ;
} else if ( V_51 != 0 ) {
V_50 -> V_55 >>= V_51 ;
V_50 -> V_56 >>= V_51 ;
V_50 -> V_57 >>= V_51 ;
}
V_36 -> V_55 += V_50 -> V_55 ;
V_36 -> V_56 += V_50 -> V_56 ;
V_36 -> V_57 += V_50 -> V_57 ;
F_34 ( V_36 -> V_41 , V_50 -> V_41 ) ;
F_34 ( V_36 -> V_43 , V_50 -> V_43 ) ;
}
}
static int F_35 ( void * V_58 , int V_15 )
{
struct V_59 * V_60 = V_58 ;
struct V_10 * V_61 ;
struct V_1 * V_2 ;
struct V_35 * V_36 , * V_50 ;
struct V_17 * V_18 ;
struct V_20 * V_21 ;
struct V_33 * V_62 , * V_63 ;
int V_37 ;
V_61 = F_36 ( V_60 , struct V_10 , V_13 ) ;
V_2 = V_61 -> V_16 ;
V_62 = V_2 -> V_48 ;
V_18 = & V_62 -> V_39 . V_18 ;
V_36 = V_2 -> V_49 -> V_14 ;
V_50 = V_60 -> V_14 ;
V_37 = F_32 ( & V_2 -> V_5 ) ;
F_10 ( V_2 , V_61 , V_15 ) ;
if ( V_15 )
goto V_31;
F_37 ( V_62 ) ;
V_21 = V_18 -> V_23 [ V_61 -> V_64 ] ;
if ( ! V_21 || ! V_21 -> V_24 )
goto V_65;
V_63 = F_38 ( V_21 -> V_25 ) ;
F_28 ( & V_63 -> V_44 ) ;
memcpy ( & V_63 -> V_45 , V_50 , sizeof( * V_50 ) ) ;
if ( ( V_60 -> V_66 & V_67 ) == 0 )
V_63 -> V_46 = F_29 () ;
F_30 ( & V_63 -> V_44 ) ;
V_65:
F_33 ( V_36 , V_50 , V_37 ) ;
F_39 ( V_62 ) ;
V_31:
return 0 ;
}
int F_40 ( struct V_33 * V_34 , struct V_59 * V_60 ,
struct V_1 * * V_68 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = & V_34 -> V_39 . V_18 ;
int V_15 = 0 , V_69 ;
V_2 = F_41 ( sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
F_1 ( V_2 ) ;
V_2 -> V_48 = V_34 ;
V_2 -> V_49 = V_60 ;
for ( V_69 = 0 ; V_69 < V_18 -> V_72 . V_73 ; V_69 ++ ) {
struct V_10 * V_11 ;
if ( ! V_18 -> V_23 [ V_69 ] ||
( V_60 -> V_66 & V_74 &&
! V_18 -> V_23 [ V_69 ] -> V_24 ) ) {
F_42 ( V_75 , L_1 , V_69 ) ;
continue;
}
if ( ! V_18 -> V_23 [ V_69 ] -> V_25 ) {
F_42 ( V_75 , L_2 , V_69 ) ;
continue;
}
if ( ! V_18 -> V_23 [ V_69 ] -> V_24 )
F_18 ( V_18 , V_69 ) ;
V_11 = F_41 ( sizeof( * V_11 ) , V_70 ) ;
if ( ! V_11 ) {
V_15 = - V_71 ;
goto V_76;
}
V_11 -> V_13 . V_14 = F_41 ( sizeof( * V_11 -> V_13 . V_14 ) ,
V_70 ) ;
if ( ! V_11 -> V_13 . V_14 ) {
F_9 ( V_11 ) ;
V_15 = - V_71 ;
goto V_76;
}
V_11 -> V_64 = V_69 ;
V_11 -> V_13 . V_77 = F_35 ;
V_11 -> V_13 . V_66 = V_60 -> V_66 ;
F_12 ( V_11 , V_2 ) ;
}
if ( ! V_2 -> V_3 ) {
V_15 = - V_47 ;
goto V_76;
}
* V_68 = V_2 ;
return V_15 ;
V_76:
F_31 ( V_2 ) ;
return V_15 ;
}
