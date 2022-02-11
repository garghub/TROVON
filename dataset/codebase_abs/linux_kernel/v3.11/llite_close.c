void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
V_8 ;
F_3 ( & V_6 -> V_9 ) ;
V_6 -> V_10 |= V_11 ;
if ( V_4 != NULL && F_4 ( & V_4 -> V_12 ) )
F_5 ( & V_4 -> V_12 ,
& V_2 -> V_13 ) ;
F_6 ( & V_6 -> V_9 ) ;
EXIT ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_14 = 0 ;
V_8 ;
F_3 ( & V_6 -> V_9 ) ;
if ( V_4 != NULL && ! F_4 ( & V_4 -> V_12 ) ) {
F_8 ( & V_4 -> V_12 ) ;
V_14 = 1 ;
}
F_6 ( & V_6 -> V_9 ) ;
if ( V_14 )
F_9 ( V_2 -> V_7 , 0 ) ;
EXIT ;
}
void F_9 ( struct V_15 * V_15 , unsigned long V_16 )
{
struct V_5 * V_6 = F_2 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( F_2 ( V_15 ) -> V_17 ) ;
V_8 ;
F_3 ( & V_6 -> V_9 ) ;
V_6 -> V_10 |= V_16 ;
if ( ( V_6 -> V_10 & V_18 ) &&
F_4 ( & V_2 -> V_13 ) ) {
struct V_19 * V_20 = F_11 ( V_15 ) -> V_21 ;
if ( V_6 -> V_10 & V_22 )
F_12 ( L_1
L_2 ,
V_15 -> V_23 , V_15 -> V_24 ,
V_6 -> V_10 ) ;
F_3 ( & V_20 -> V_25 ) ;
F_13 ( F_4 ( & V_6 -> V_26 ) ) ;
F_14 ( V_27 , L_3 ,
V_15 -> V_23 , V_15 -> V_24 ) ;
F_15 ( & V_6 -> V_26 , & V_20 -> V_28 ) ;
V_6 -> V_10 &= ~ V_18 ;
F_16 ( & V_20 -> V_29 ) ;
F_6 ( & V_20 -> V_25 ) ;
}
F_6 ( & V_6 -> V_9 ) ;
EXIT ;
}
void F_17 ( struct V_15 * V_15 , struct V_30 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_15 ) ;
V_8 ;
V_31 -> V_32 |= V_33 ;
if ( V_6 -> V_10 & V_22 )
F_18 ( L_1
L_2 , V_15 -> V_23 , V_15 -> V_24 ,
V_6 -> V_10 ) ;
if ( ! F_19 ( V_15 ) ) {
V_31 -> V_34 . V_35 |= V_36 | V_37 |
V_38 | V_39 | V_40 ;
}
EXIT ;
}
void F_20 ( struct V_15 * V_15 , struct V_30 * V_31 ,
struct V_41 * * V_42 , unsigned long V_16 )
{
struct V_5 * V_6 = F_2 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( F_2 ( V_15 ) -> V_17 ) ;
V_8 ;
F_3 ( & V_6 -> V_9 ) ;
if ( ! ( F_4 ( & V_2 -> V_13 ) ) ) {
if ( ! ( V_6 -> V_10 & V_43 ) ) {
F_13 ( * V_42 != NULL ) ;
F_13 ( V_6 -> V_44 == NULL ) ;
V_6 -> V_10 |= V_43 ;
V_6 -> V_44 = * V_42 ;
F_6 ( & V_6 -> V_9 ) ;
V_15 = F_21 ( V_15 ) ;
F_13 ( V_15 ) ;
GOTO ( V_45 , 0 ) ;
}
if ( V_16 & V_18 ) {
F_13 ( ! ( V_6 -> V_10 & V_18 ) ) ;
V_6 -> V_10 |= V_18 ;
F_6 ( & V_6 -> V_9 ) ;
V_15 = F_21 ( V_15 ) ;
F_13 ( V_15 ) ;
GOTO ( V_45 , 0 ) ;
}
}
F_14 ( V_27 , L_4 V_46 L_5 V_47 L_6 ,
F_2 ( V_15 ) -> V_48 , F_22 ( & V_6 -> V_49 ) ) ;
V_31 -> V_32 |= V_50 ;
if ( V_16 & V_18 ) {
F_13 ( V_6 -> V_10 & V_11 ) ;
F_13 ( ! ( V_6 -> V_10 & V_18 ) ) ;
* V_42 = V_6 -> V_44 ;
V_6 -> V_44 = NULL ;
V_6 -> V_10 &= ~ V_43 ;
} else {
if ( ! ( V_6 -> V_10 & V_11 ) ) {
F_6 ( & V_6 -> V_9 ) ;
GOTO ( V_45 , 0 ) ;
}
if ( V_6 -> V_10 & V_43 ) {
F_6 ( & V_6 -> V_9 ) ;
GOTO ( V_45 , 0 ) ;
}
}
F_13 ( F_4 ( & V_2 -> V_13 ) ) ;
V_6 -> V_10 &= ~ V_11 ;
F_6 ( & V_6 -> V_9 ) ;
F_17 ( V_15 , V_31 ) ;
EXIT ;
V_45:
return;
}
int F_23 ( struct V_15 * V_15 , struct V_30 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_15 ) ;
struct V_51 * V_52 = NULL ;
T_1 V_53 ;
struct V_54 * V_55 ;
int V_14 ;
V_8 ;
F_13 ( V_31 != NULL ) ;
if ( V_6 -> V_10 & V_22 )
F_18 ( L_1
L_2 , V_15 -> V_23 , V_15 -> V_24 ,
V_6 -> V_10 ) ;
F_24 ( V_55 ) ;
if ( ! V_55 ) {
F_18 ( L_7 ) ;
RETURN ( - V_56 ) ;
}
V_53 = V_31 -> V_32 ;
V_31 -> V_32 = V_33 ;
if ( V_6 -> V_48 == V_31 -> V_57 ) {
V_14 = F_25 ( V_15 , V_55 , V_31 -> V_57 ,
V_53 & V_58 ) ;
if ( V_14 ) {
V_55 -> V_59 = 0 ;
if ( V_14 != - V_60 )
F_18 ( L_8
L_9
L_10 , V_14 , V_15 -> V_23 ,
V_15 -> V_24 ) ;
} else {
F_14 ( V_27 , L_11 V_47 L_6 ,
F_22 ( & V_6 -> V_49 ) ) ;
}
F_26 ( V_31 , V_55 , V_55 -> V_59 ) ;
}
V_14 = F_27 ( F_11 ( V_15 ) -> V_61 , V_31 ,
NULL , 0 , NULL , 0 , & V_52 , NULL ) ;
F_28 ( V_52 ) ;
F_29 ( V_55 ) ;
RETURN ( V_14 ) ;
}
static void F_30 ( struct V_15 * V_15 ,
struct V_30 * V_31 ,
struct V_41 * * V_42 )
{
F_20 ( V_15 , V_31 , V_42 , V_18 ) ;
if ( * V_42 == NULL )
return;
F_31 ( V_15 , V_31 , & ( * V_42 ) -> V_62 ) ;
F_32 ( V_31 , V_15 , NULL , NULL ,
0 , 0 , V_63 , NULL ) ;
}
static void F_33 ( struct V_15 * V_15 )
{
struct V_41 * V_42 = NULL ;
struct V_30 * V_31 ;
int V_14 ;
V_8 ;
F_13 ( F_34 ( F_35 ( V_15 ) ) ) ;
F_36 ( V_31 ) ;
if ( V_31 == NULL ) {
F_18 ( L_12 ) ;
EXIT ;
return;
}
F_30 ( V_15 , V_31 , & V_42 ) ;
if ( V_42 == NULL )
GOTO ( V_45 , 0 ) ;
V_14 = F_37 ( F_11 ( V_15 ) -> V_61 , V_31 , NULL ) ;
if ( V_14 == - V_64 ) {
V_14 = F_23 ( V_15 , V_31 ) ;
} else if ( V_14 ) {
F_18 ( L_13 ,
V_15 -> V_23 , V_14 ) ;
}
V_45:
F_38 ( V_31 ) ;
if ( V_42 ) {
F_39 ( F_11 ( V_15 ) -> V_61 , V_42 ) ;
F_40 ( V_42 ) ;
}
EXIT ;
}
static struct V_5 * F_41 ( struct V_19 * V_20 )
{
struct V_5 * V_6 = NULL ;
F_3 ( & V_20 -> V_25 ) ;
if ( ! F_4 ( & V_20 -> V_28 ) ) {
V_6 = F_42 ( V_20 -> V_28 . V_65 , struct V_5 ,
V_26 ) ;
F_8 ( & V_6 -> V_26 ) ;
} else if ( F_43 ( & V_20 -> V_66 ) )
V_6 = F_44 ( - V_67 ) ;
F_6 ( & V_20 -> V_25 ) ;
return V_6 ;
}
static int F_45 ( void * V_68 )
{
struct V_19 * V_20 = V_68 ;
V_8 ;
F_46 ( & V_20 -> V_69 ) ;
while ( 1 ) {
struct V_70 V_71 = { 0 } ;
struct V_5 * V_6 ;
struct V_15 * V_15 ;
F_47 ( V_20 -> V_29 ,
( V_6 = F_41 ( V_20 ) ) != NULL ,
& V_71 ) ;
if ( F_48 ( V_6 ) )
break;
V_15 = F_49 ( V_6 ) ;
F_14 ( V_72 , L_14 ,
V_15 -> V_23 , V_15 -> V_24 ) ;
F_33 ( V_15 ) ;
F_50 ( V_15 ) ;
}
F_14 ( V_72 , L_15 ) ;
F_46 ( & V_20 -> V_69 ) ;
RETURN ( 0 ) ;
}
int F_51 ( struct V_19 * * V_73 )
{
struct V_19 * V_20 ;
T_2 * V_74 ;
if ( F_52 ( V_75 ) )
return - V_76 ;
F_53 ( V_20 , sizeof( * V_20 ) ) ;
if ( V_20 == NULL )
return - V_56 ;
F_54 ( & V_20 -> V_25 ) ;
F_55 ( & V_20 -> V_28 ) ;
F_56 ( & V_20 -> V_29 ) ;
F_57 ( & V_20 -> V_69 ) ;
V_74 = F_58 ( F_45 , V_20 , L_16 ) ;
if ( F_48 ( V_74 ) ) {
F_59 ( V_20 , sizeof( * V_20 ) ) ;
return F_60 ( V_74 ) ;
}
F_61 ( & V_20 -> V_69 ) ;
* V_73 = V_20 ;
return 0 ;
}
void F_62 ( struct V_19 * V_20 )
{
F_57 ( & V_20 -> V_69 ) ;
F_63 ( & V_20 -> V_66 ) ;
F_16 ( & V_20 -> V_29 ) ;
F_61 ( & V_20 -> V_69 ) ;
F_59 ( V_20 , sizeof( * V_20 ) ) ;
}
