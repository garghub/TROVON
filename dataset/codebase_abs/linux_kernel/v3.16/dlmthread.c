void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 , V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 , & V_4 ) ;
V_8:
F_5 ( V_9 ) ;
if ( V_2 -> V_10 & V_3 ) {
F_6 ( & V_2 -> V_6 ) ;
F_7 () ;
F_8 ( & V_2 -> V_6 ) ;
goto V_8;
}
F_9 ( & V_2 -> V_7 , & V_4 ) ;
F_10 ( V_11 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( & V_2 -> V_12 ) &&
F_12 ( & V_2 -> V_13 ) &&
F_12 ( & V_2 -> V_14 ) )
return 0 ;
return 1 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_15 ;
F_3 ( & V_2 -> V_6 ) ;
if ( F_11 ( V_2 ) )
return 0 ;
if ( V_2 -> V_16 )
return 0 ;
if ( ! F_12 ( & V_2 -> V_17 ) || V_2 -> V_10 & V_18 )
return 0 ;
if ( V_2 -> V_10 & V_19 )
return 0 ;
V_15 = F_14 ( V_2 -> V_20 , V_21 , 0 ) ;
if ( V_15 < V_21 )
return 0 ;
return 1 ;
}
void F_15 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
F_3 ( & V_23 -> V_6 ) ;
F_3 ( & V_2 -> V_6 ) ;
if ( F_13 ( V_2 ) ) {
if ( F_12 ( & V_2 -> V_24 ) ) {
F_16 ( 0 , L_1 ,
V_23 -> V_25 , V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 ) ;
V_2 -> V_28 = V_29 ;
F_17 ( V_2 ) ;
F_18 ( & V_2 -> V_24 , & V_23 -> V_30 ) ;
V_23 -> V_31 ++ ;
}
} else if ( ! F_12 ( & V_2 -> V_24 ) ) {
F_16 ( 0 , L_2 ,
V_23 -> V_25 , V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 ) ;
F_19 ( & V_2 -> V_24 ) ;
F_20 ( V_2 ) ;
V_23 -> V_31 -- ;
}
}
void F_21 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
F_8 ( & V_23 -> V_6 ) ;
F_8 ( & V_2 -> V_6 ) ;
F_15 ( V_23 , V_2 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_23 -> V_6 ) ;
}
static void F_22 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
int V_32 ;
int V_33 = 0 ;
F_3 ( & V_23 -> V_6 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_32 = ( V_2 -> V_34 == V_23 -> V_35 ) ;
F_16 ( 0 , L_3 , V_23 -> V_25 ,
V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 , V_32 ) ;
if ( ! V_32 ) {
V_2 -> V_10 |= V_36 ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_23 -> V_6 ) ;
F_8 ( & V_2 -> V_6 ) ;
F_1 ( V_2 , V_37 ) ;
F_6 ( & V_2 -> V_6 ) ;
V_33 = F_23 ( V_23 , V_2 ) ;
if ( V_33 < 0 ) {
if ( ! F_24 ( V_33 ) )
F_25 () ;
}
F_8 ( & V_23 -> V_6 ) ;
F_8 ( & V_2 -> V_6 ) ;
}
if ( ! F_12 ( & V_2 -> V_24 ) ) {
F_16 ( 0 , L_4 ,
V_23 -> V_25 , V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 , V_32 ) ;
F_19 ( & V_2 -> V_24 ) ;
F_20 ( V_2 ) ;
V_23 -> V_31 -- ;
}
if ( ! F_13 ( V_2 ) ) {
F_16 ( V_38 , L_5 ,
V_23 -> V_25 , V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 ) ;
F_26 ( V_2 ) ;
F_25 () ;
}
F_27 ( V_23 , V_2 ) ;
if ( ! V_32 ) {
V_2 -> V_10 &= ~ V_36 ;
F_6 ( & V_2 -> V_6 ) ;
F_28 ( & V_2 -> V_7 ) ;
} else
F_6 ( & V_2 -> V_6 ) ;
}
static void F_29 ( struct V_22 * V_23 ,
int V_39 )
{
unsigned int V_40 , V_41 ;
unsigned long V_42 ;
struct V_1 * V_43 ;
F_8 ( & V_23 -> V_6 ) ;
V_40 = V_23 -> V_31 ;
while( V_40 && ! F_12 ( & V_23 -> V_30 ) ) {
V_40 -- ;
V_43 = F_30 ( V_23 -> V_30 . V_44 ,
struct V_1 , V_24 ) ;
F_8 ( & V_43 -> V_6 ) ;
V_42 = V_43 -> V_28 +
F_31 ( V_45 ) ;
if ( ! V_39 && F_32 ( V_42 , V_29 ) ) {
F_6 ( & V_43 -> V_6 ) ;
break;
}
V_41 = F_13 ( V_43 ) ;
if ( ! V_41 ||
( V_43 -> V_10 & V_46 ) ||
( V_43 -> V_47 != 0 ) ) {
F_16 ( 0 , L_6
L_7 ,
V_23 -> V_25 , V_43 -> V_26 . V_27 ,
V_43 -> V_26 . V_25 ,
! V_41 , V_43 -> V_10 ,
V_43 -> V_47 ) ;
F_33 ( & V_43 -> V_24 , & V_23 -> V_30 ) ;
F_6 ( & V_43 -> V_6 ) ;
continue;
}
F_17 ( V_43 ) ;
F_22 ( V_23 , V_43 ) ;
F_20 ( V_43 ) ;
F_34 ( & V_23 -> V_6 ) ;
}
F_6 ( & V_23 -> V_6 ) ;
}
static void F_35 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_48 * V_49 , * V_50 ;
int V_51 = 1 ;
F_3 ( & V_23 -> V_52 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_36 ( ( V_2 -> V_10 & ( V_46 |
V_19 |
V_53 ) ) ) ;
V_13:
if ( F_12 ( & V_2 -> V_13 ) )
goto V_14;
F_16 ( 0 , L_8 , V_23 -> V_25 ,
V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 ) ;
V_50 = F_30 ( V_2 -> V_13 . V_44 , struct V_48 , V_54 ) ;
if ( V_50 -> V_55 . V_56 == V_57 ) {
F_16 ( V_38 , L_9 ,
V_23 -> V_25 , V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 ) ;
F_25 () ;
}
F_37 (lock, &res->granted, list) {
if ( V_49 == V_50 )
continue;
if ( ! F_38 ( V_49 -> V_55 . type ,
V_50 -> V_55 . V_56 ) ) {
V_51 = 0 ;
if ( V_49 -> V_55 . V_58 == V_57 ) {
F_39 ( V_2 ) ;
F_40 ( V_23 , V_49 ) ;
}
if ( V_49 -> V_55 . V_58 < V_50 -> V_55 . V_56 )
V_49 -> V_55 . V_58 =
V_50 -> V_55 . V_56 ;
}
}
F_37 (lock, &res->converting, list) {
if ( V_49 == V_50 )
continue;
if ( ! F_38 ( V_49 -> V_55 . type ,
V_50 -> V_55 . V_56 ) ) {
V_51 = 0 ;
if ( V_49 -> V_55 . V_58 == V_57 ) {
F_39 ( V_2 ) ;
F_40 ( V_23 , V_49 ) ;
}
if ( V_49 -> V_55 . V_58 < V_50 -> V_55 . V_56 )
V_49 -> V_55 . V_58 =
V_50 -> V_55 . V_56 ;
}
}
if ( V_51 ) {
F_8 ( & V_50 -> V_6 ) ;
F_36 ( V_50 -> V_55 . V_58 != V_57 ) ;
F_16 ( 0 , L_10
L_11 , V_23 -> V_25 , V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_25 ,
F_41 ( F_42 ( V_50 -> V_55 . V_59 ) ) ,
F_43 ( F_42 ( V_50 -> V_55 . V_59 ) ) ,
V_50 -> V_55 . type ,
V_50 -> V_55 . V_56 , V_50 -> V_55 . V_60 ) ;
V_50 -> V_55 . type = V_50 -> V_55 . V_56 ;
V_50 -> V_55 . V_56 = V_57 ;
F_33 ( & V_50 -> V_54 , & V_2 -> V_12 ) ;
F_36 ( ! V_50 -> V_61 ) ;
V_50 -> V_61 -> V_62 = V_63 ;
F_6 ( & V_50 -> V_6 ) ;
F_39 ( V_2 ) ;
F_44 ( V_23 , V_50 ) ;
goto V_13;
}
V_14:
if ( F_12 ( & V_2 -> V_14 ) )
goto V_64;
V_50 = F_30 ( V_2 -> V_14 . V_44 , struct V_48 , V_54 ) ;
F_37 (lock, &res->granted, list) {
if ( V_49 == V_50 )
continue;
if ( ! F_38 ( V_49 -> V_55 . type , V_50 -> V_55 . type ) ) {
V_51 = 0 ;
if ( V_49 -> V_55 . V_58 == V_57 ) {
F_39 ( V_2 ) ;
F_40 ( V_23 , V_49 ) ;
}
if ( V_49 -> V_55 . V_58 < V_50 -> V_55 . type )
V_49 -> V_55 . V_58 = V_50 -> V_55 . type ;
}
}
F_37 (lock, &res->converting, list) {
if ( V_49 == V_50 )
continue;
if ( ! F_38 ( V_49 -> V_55 . type , V_50 -> V_55 . type ) ) {
V_51 = 0 ;
if ( V_49 -> V_55 . V_58 == V_57 ) {
F_39 ( V_2 ) ;
F_40 ( V_23 , V_49 ) ;
}
if ( V_49 -> V_55 . V_58 < V_50 -> V_55 . type )
V_49 -> V_55 . V_58 = V_50 -> V_55 . type ;
}
}
if ( V_51 ) {
F_8 ( & V_50 -> V_6 ) ;
F_36 ( V_50 -> V_55 . V_58 != V_57 ) ;
F_16 ( 0 , L_12
L_13 , V_23 -> V_25 , V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_25 ,
F_41 ( F_42 ( V_50 -> V_55 . V_59 ) ) ,
F_43 ( F_42 ( V_50 -> V_55 . V_59 ) ) ,
V_50 -> V_55 . type , V_50 -> V_55 . V_60 ) ;
F_33 ( & V_50 -> V_54 , & V_2 -> V_12 ) ;
F_36 ( ! V_50 -> V_61 ) ;
V_50 -> V_61 -> V_62 = V_63 ;
F_6 ( & V_50 -> V_6 ) ;
F_39 ( V_2 ) ;
F_44 ( V_23 , V_50 ) ;
goto V_13;
}
V_64:
return;
}
void F_45 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
if ( V_2 ) {
F_8 ( & V_23 -> V_6 ) ;
F_8 ( & V_2 -> V_6 ) ;
F_46 ( V_23 , V_2 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_23 -> V_6 ) ;
}
F_28 ( & V_23 -> V_65 ) ;
}
void F_46 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
F_3 ( & V_23 -> V_6 ) ;
F_3 ( & V_2 -> V_6 ) ;
if ( ( V_2 -> V_34 == V_23 -> V_35 ) ) {
if ( V_2 -> V_10 & ( V_46 |
V_66 ) )
return;
if ( F_12 ( & V_2 -> V_17 ) ) {
F_17 ( V_2 ) ;
F_18 ( & V_2 -> V_17 , & V_23 -> V_67 ) ;
V_2 -> V_10 |= V_18 ;
}
}
F_16 ( 0 , L_14 , V_23 -> V_25 , V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_25 ) ;
}
int F_47 ( struct V_22 * V_23 )
{
F_16 ( 0 , L_15 ) ;
V_23 -> V_68 = F_48 ( V_69 , V_23 , L_16 ) ;
if ( F_49 ( V_23 -> V_68 ) ) {
F_50 ( F_51 ( V_23 -> V_68 ) ) ;
V_23 -> V_68 = NULL ;
return - V_70 ;
}
return 0 ;
}
void F_52 ( struct V_22 * V_23 )
{
if ( V_23 -> V_68 ) {
F_16 ( V_71 , L_17 ) ;
F_53 ( V_23 -> V_68 ) ;
V_23 -> V_68 = NULL ;
}
}
static int F_54 ( struct V_22 * V_23 )
{
int V_72 ;
F_8 ( & V_23 -> V_6 ) ;
V_72 = F_12 ( & V_23 -> V_67 ) ;
F_6 ( & V_23 -> V_6 ) ;
return V_72 ;
}
static void F_55 ( struct V_22 * V_23 )
{
int V_33 ;
struct V_48 * V_49 ;
struct V_1 * V_2 ;
T_1 V_73 ;
F_8 ( & V_23 -> V_52 ) ;
while ( ! F_12 ( & V_23 -> V_74 ) ) {
V_49 = F_30 ( V_23 -> V_74 . V_44 ,
struct V_48 , V_75 ) ;
F_56 ( V_49 ) ;
V_2 = V_49 -> V_43 ;
F_16 ( 0 , L_18
L_13 , V_23 -> V_25 , V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_25 ,
F_41 ( F_42 ( V_49 -> V_55 . V_59 ) ) ,
F_43 ( F_42 ( V_49 -> V_55 . V_59 ) ) ,
V_49 -> V_55 . type , V_49 -> V_55 . V_60 ) ;
F_36 ( ! V_49 -> V_76 ) ;
F_19 ( & V_49 -> V_75 ) ;
F_57 ( V_49 ) ;
F_6 ( & V_23 -> V_52 ) ;
if ( V_49 -> V_55 . V_60 != V_23 -> V_35 ) {
V_33 = F_58 ( V_23 , V_2 , V_49 ) ;
if ( V_33 < 0 )
F_50 ( V_33 ) ;
} else
F_59 ( V_23 , V_2 , V_49 ) ;
F_8 ( & V_23 -> V_52 ) ;
if ( ! F_12 ( & V_49 -> V_75 ) ) {
F_16 ( 0 , L_19
L_20 , V_23 -> V_25 , V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_25 ) ;
} else
V_49 -> V_76 = 0 ;
F_57 ( V_49 ) ;
F_60 ( V_23 , V_2 ) ;
}
while ( ! F_12 ( & V_23 -> V_77 ) ) {
V_49 = F_30 ( V_23 -> V_77 . V_44 ,
struct V_48 , V_78 ) ;
F_56 ( V_49 ) ;
V_2 = V_49 -> V_43 ;
F_36 ( ! V_49 -> V_79 ) ;
F_8 ( & V_49 -> V_6 ) ;
F_36 ( V_49 -> V_55 . V_58 <= V_57 ) ;
V_73 = V_49 -> V_55 . V_58 ;
V_49 -> V_55 . V_58 = V_57 ;
F_6 ( & V_49 -> V_6 ) ;
F_19 ( & V_49 -> V_78 ) ;
F_57 ( V_49 ) ;
F_6 ( & V_23 -> V_52 ) ;
F_16 ( 0 , L_21
L_22 ,
V_23 -> V_25 , V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 ,
F_41 ( F_42 ( V_49 -> V_55 . V_59 ) ) ,
F_43 ( F_42 ( V_49 -> V_55 . V_59 ) ) ,
V_73 , V_49 -> V_55 . V_60 ) ;
if ( V_49 -> V_55 . V_60 != V_23 -> V_35 ) {
V_33 = F_61 ( V_23 , V_2 , V_49 , V_73 ) ;
if ( V_33 < 0 )
F_50 ( V_33 ) ;
} else
F_62 ( V_23 , V_2 , V_49 , V_73 ) ;
F_8 ( & V_23 -> V_52 ) ;
if ( ! F_12 ( & V_49 -> V_78 ) ) {
F_16 ( 0 , L_23
L_20 , V_23 -> V_25 , V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_25 ) ;
} else
V_49 -> V_79 = 0 ;
F_57 ( V_49 ) ;
F_60 ( V_23 , V_2 ) ;
}
F_28 ( & V_23 -> V_80 ) ;
F_6 ( & V_23 -> V_52 ) ;
}
static int V_69 ( void * V_81 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 = V_81 ;
unsigned long V_82 = F_31 ( V_83 ) ;
F_16 ( 0 , L_24 , V_23 -> V_25 ) ;
while ( ! F_63 () ) {
int V_84 = V_85 ;
F_29 ( V_23 , F_64 ( V_23 ) ) ;
F_8 ( & V_23 -> V_6 ) ;
while ( ! F_12 ( & V_23 -> V_67 ) ) {
int V_86 = 0 ;
V_2 = F_30 ( V_23 -> V_67 . V_44 ,
struct V_1 , V_17 ) ;
F_36 ( ! V_2 ) ;
F_17 ( V_2 ) ;
F_8 ( & V_2 -> V_6 ) ;
F_19 ( & V_2 -> V_17 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_23 -> V_6 ) ;
F_20 ( V_2 ) ;
F_8 ( & V_23 -> V_52 ) ;
F_8 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_34 != V_23 -> V_35 ) {
F_26 ( V_2 ) ;
F_16 ( V_38 , L_25
L_26 , V_23 -> V_25 ,
! ! ( V_2 -> V_10 & V_53 ) ,
! ! ( V_2 -> V_10 & V_46 ) ,
! ! ( V_2 -> V_10 & V_19 ) ,
! ! ( V_2 -> V_10 & V_18 ) ) ;
}
F_36 ( V_2 -> V_34 != V_23 -> V_35 ) ;
F_36 ( V_2 -> V_10 & V_46 ) ;
if ( V_2 -> V_10 & ( V_53 |
V_19 ) ) {
V_2 -> V_10 &= ~ V_18 ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_23 -> V_52 ) ;
F_16 ( 0 , L_27
L_28 , V_23 -> V_25 ,
V_2 -> V_26 . V_27 , V_2 -> V_26 . V_25 ,
V_2 -> V_10 ) ;
V_86 = 1 ;
goto V_87;
}
F_35 ( V_23 , V_2 ) ;
V_2 -> V_10 &= ~ V_18 ;
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_23 -> V_52 ) ;
F_21 ( V_23 , V_2 ) ;
V_87:
F_8 ( & V_23 -> V_6 ) ;
if ( V_86 ) {
F_8 ( & V_2 -> V_6 ) ;
F_46 ( V_23 , V_2 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
F_20 ( V_2 ) ;
if ( ! -- V_84 ) {
F_16 ( 0 , L_29 ,
V_23 -> V_25 ) ;
break;
}
}
F_6 ( & V_23 -> V_6 ) ;
F_55 ( V_23 ) ;
if ( ! V_84 ) {
F_65 () ;
continue;
}
F_66 ( V_23 -> V_65 ,
! F_54 ( V_23 ) ||
F_63 () ,
V_82 ) ;
}
F_16 ( 0 , L_30 ) ;
return 0 ;
}
