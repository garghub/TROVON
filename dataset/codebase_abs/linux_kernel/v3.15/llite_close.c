void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 |= V_10 ;
if ( V_4 != NULL && F_4 ( & V_4 -> V_11 ) )
F_5 ( & V_4 -> V_11 ,
& V_2 -> V_12 ) ;
F_6 ( & V_6 -> V_8 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_13 = 0 ;
F_3 ( & V_6 -> V_8 ) ;
if ( V_4 != NULL && ! F_4 ( & V_4 -> V_11 ) ) {
F_8 ( & V_4 -> V_11 ) ;
V_13 = 1 ;
}
F_6 ( & V_6 -> V_8 ) ;
if ( V_13 )
F_9 ( V_2 -> V_7 , 0 ) ;
}
void F_9 ( struct V_14 * V_14 , unsigned long V_15 )
{
struct V_5 * V_6 = F_2 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( F_2 ( V_14 ) -> V_16 ) ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 |= V_15 ;
if ( ( V_6 -> V_9 & V_17 ) &&
F_4 ( & V_2 -> V_12 ) ) {
struct V_18 * V_19 = F_11 ( V_14 ) -> V_20 ;
if ( V_6 -> V_9 & V_21 )
F_12 ( L_1
L_2 ,
V_14 -> V_22 , V_14 -> V_23 ,
V_6 -> V_9 ) ;
F_3 ( & V_19 -> V_24 ) ;
F_13 ( F_4 ( & V_6 -> V_25 ) ) ;
F_14 ( V_26 , L_3 ,
V_14 -> V_22 , V_14 -> V_23 ) ;
F_15 ( & V_6 -> V_25 , & V_19 -> V_27 ) ;
V_6 -> V_9 &= ~ V_17 ;
F_16 ( & V_19 -> V_28 ) ;
F_6 ( & V_19 -> V_24 ) ;
}
F_6 ( & V_6 -> V_8 ) ;
}
void F_17 ( struct V_14 * V_14 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_14 ) ;
V_30 -> V_31 |= V_32 ;
if ( V_6 -> V_9 & V_21 )
F_18 ( L_1
L_2 , V_14 -> V_22 , V_14 -> V_23 ,
V_6 -> V_9 ) ;
if ( ! F_19 ( V_14 ) ) {
V_30 -> V_33 . V_34 |= V_35 | V_36 |
V_37 | V_38 | V_39 ;
}
}
void F_20 ( struct V_14 * V_14 , struct V_29 * V_30 ,
struct V_40 * * V_41 , unsigned long V_15 )
{
struct V_5 * V_6 = F_2 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( F_2 ( V_14 ) -> V_16 ) ;
F_3 ( & V_6 -> V_8 ) ;
if ( ! ( F_4 ( & V_2 -> V_12 ) ) ) {
if ( ! ( V_6 -> V_9 & V_42 ) ) {
F_13 ( * V_41 != NULL ) ;
F_13 ( V_6 -> V_43 == NULL ) ;
V_6 -> V_9 |= V_42 ;
V_6 -> V_43 = * V_41 ;
F_6 ( & V_6 -> V_8 ) ;
V_14 = F_21 ( V_14 ) ;
F_13 ( V_14 ) ;
GOTO ( V_44 , 0 ) ;
}
if ( V_15 & V_17 ) {
F_13 ( ! ( V_6 -> V_9 & V_17 ) ) ;
V_6 -> V_9 |= V_17 ;
F_6 ( & V_6 -> V_8 ) ;
V_14 = F_21 ( V_14 ) ;
F_13 ( V_14 ) ;
GOTO ( V_44 , 0 ) ;
}
}
F_14 ( V_26 , L_4 V_45 L_5 V_46 L_6 ,
F_2 ( V_14 ) -> V_47 , F_22 ( & V_6 -> V_48 ) ) ;
V_30 -> V_31 |= V_49 ;
if ( V_15 & V_17 ) {
F_13 ( V_6 -> V_9 & V_10 ) ;
F_13 ( ! ( V_6 -> V_9 & V_17 ) ) ;
* V_41 = V_6 -> V_43 ;
V_6 -> V_43 = NULL ;
V_6 -> V_9 &= ~ V_42 ;
} else {
if ( ! ( V_6 -> V_9 & V_10 ) ) {
F_6 ( & V_6 -> V_8 ) ;
GOTO ( V_44 , 0 ) ;
}
if ( V_6 -> V_9 & V_42 ) {
F_6 ( & V_6 -> V_8 ) ;
GOTO ( V_44 , 0 ) ;
}
}
F_13 ( F_4 ( & V_2 -> V_12 ) ) ;
V_6 -> V_9 &= ~ V_10 ;
F_6 ( & V_6 -> V_8 ) ;
F_17 ( V_14 , V_30 ) ;
V_44:
return;
}
int F_23 ( struct V_14 * V_14 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_14 ) ;
struct V_50 * V_51 = NULL ;
T_1 V_52 ;
struct V_53 * V_54 ;
int V_13 ;
F_13 ( V_30 != NULL ) ;
if ( V_6 -> V_9 & V_21 )
F_18 ( L_1
L_2 , V_14 -> V_22 , V_14 -> V_23 ,
V_6 -> V_9 ) ;
F_24 ( V_54 ) ;
if ( ! V_54 ) {
F_18 ( L_7 ) ;
return - V_55 ;
}
V_52 = V_30 -> V_31 ;
V_30 -> V_31 = V_32 ;
if ( V_6 -> V_47 == V_30 -> V_56 ) {
V_13 = F_25 ( V_14 , V_54 , V_30 -> V_56 ,
V_52 & V_57 ) ;
if ( V_13 ) {
V_54 -> V_58 = 0 ;
if ( V_13 != - V_59 )
F_18 ( L_8
L_9
L_10 , V_13 , V_14 -> V_22 ,
V_14 -> V_23 ) ;
} else {
F_14 ( V_26 , L_11 V_46 L_6 ,
F_22 ( & V_6 -> V_48 ) ) ;
}
F_26 ( V_30 , V_54 , V_54 -> V_58 ) ;
}
V_13 = F_27 ( F_11 ( V_14 ) -> V_60 , V_30 ,
NULL , 0 , NULL , 0 , & V_51 , NULL ) ;
F_28 ( V_51 ) ;
F_29 ( V_54 ) ;
return V_13 ;
}
static void F_30 ( struct V_14 * V_14 ,
struct V_29 * V_30 ,
struct V_40 * * V_41 )
{
F_20 ( V_14 , V_30 , V_41 , V_17 ) ;
if ( * V_41 == NULL )
return;
F_31 ( V_14 , V_30 , & ( * V_41 ) -> V_61 ) ;
F_32 ( V_30 , V_14 , NULL , NULL ,
0 , 0 , V_62 , NULL ) ;
}
static void F_33 ( struct V_14 * V_14 )
{
struct V_40 * V_41 = NULL ;
struct V_29 * V_30 ;
int V_13 ;
F_13 ( F_34 ( F_35 ( V_14 ) ) ) ;
F_36 ( V_30 ) ;
if ( V_30 == NULL ) {
F_18 ( L_12 ) ;
return;
}
F_30 ( V_14 , V_30 , & V_41 ) ;
if ( V_41 == NULL )
GOTO ( V_44 , 0 ) ;
V_13 = F_37 ( F_11 ( V_14 ) -> V_60 , V_30 , NULL ) ;
if ( V_13 == - V_63 ) {
V_13 = F_23 ( V_14 , V_30 ) ;
} else if ( V_13 ) {
F_18 ( L_13 ,
V_14 -> V_22 , V_13 ) ;
}
V_44:
F_38 ( V_30 ) ;
if ( V_41 ) {
F_39 ( F_11 ( V_14 ) -> V_60 , V_41 ) ;
F_40 ( V_41 ) ;
}
}
static struct V_5 * F_41 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = NULL ;
F_3 ( & V_19 -> V_24 ) ;
if ( ! F_4 ( & V_19 -> V_27 ) ) {
V_6 = F_42 ( V_19 -> V_27 . V_64 , struct V_5 ,
V_25 ) ;
F_8 ( & V_6 -> V_25 ) ;
} else if ( F_43 ( & V_19 -> V_65 ) )
V_6 = F_44 ( - V_66 ) ;
F_6 ( & V_19 -> V_24 ) ;
return V_6 ;
}
static int F_45 ( void * V_67 )
{
struct V_18 * V_19 = V_67 ;
F_46 ( & V_19 -> V_68 ) ;
while ( 1 ) {
struct V_69 V_70 = { 0 } ;
struct V_5 * V_6 ;
struct V_14 * V_14 ;
F_47 ( V_19 -> V_28 ,
( V_6 = F_41 ( V_19 ) ) != NULL ,
& V_70 ) ;
if ( F_48 ( V_6 ) )
break;
V_14 = F_49 ( V_6 ) ;
F_14 ( V_71 , L_14 ,
V_14 -> V_22 , V_14 -> V_23 ) ;
F_33 ( V_14 ) ;
F_50 ( V_14 ) ;
}
F_14 ( V_71 , L_15 ) ;
F_46 ( & V_19 -> V_68 ) ;
return 0 ;
}
int F_51 ( struct V_18 * * V_72 )
{
struct V_18 * V_19 ;
struct V_73 * V_74 ;
if ( F_52 ( V_75 ) )
return - V_76 ;
F_53 ( V_19 , sizeof( * V_19 ) ) ;
if ( V_19 == NULL )
return - V_55 ;
F_54 ( & V_19 -> V_24 ) ;
F_55 ( & V_19 -> V_27 ) ;
F_56 ( & V_19 -> V_28 ) ;
F_57 ( & V_19 -> V_68 ) ;
V_74 = F_58 ( F_45 , V_19 , L_16 ) ;
if ( F_48 ( V_74 ) ) {
F_59 ( V_19 , sizeof( * V_19 ) ) ;
return F_60 ( V_74 ) ;
}
F_61 ( & V_19 -> V_68 ) ;
* V_72 = V_19 ;
return 0 ;
}
void F_62 ( struct V_18 * V_19 )
{
F_57 ( & V_19 -> V_68 ) ;
F_63 ( & V_19 -> V_65 ) ;
F_16 ( & V_19 -> V_28 ) ;
F_61 ( & V_19 -> V_68 ) ;
F_59 ( V_19 , sizeof( * V_19 ) ) ;
}
