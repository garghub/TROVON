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
F_14 ( V_26 , L_4 V_45 L_5 ,
F_2 ( V_14 ) -> V_46 , F_22 ( & V_6 -> V_47 ) ) ;
V_30 -> V_31 |= V_48 ;
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
struct V_49 * V_50 = NULL ;
T_1 V_51 ;
struct V_52 * V_53 ;
int V_13 ;
F_13 ( V_30 != NULL ) ;
if ( V_6 -> V_9 & V_21 )
F_18 ( L_1
L_2 , V_14 -> V_22 , V_14 -> V_23 ,
V_6 -> V_9 ) ;
F_24 ( V_53 ) ;
if ( ! V_53 ) {
F_18 ( L_6 ) ;
return - V_54 ;
}
V_51 = V_30 -> V_31 ;
V_30 -> V_31 = V_32 ;
if ( V_6 -> V_46 == V_30 -> V_55 ) {
V_13 = F_25 ( V_14 , V_53 , V_30 -> V_55 ,
V_51 & V_56 ) ;
if ( V_13 ) {
V_53 -> V_57 = 0 ;
if ( V_13 != - V_58 )
F_18 ( L_7
L_8
L_9 , V_13 , V_14 -> V_22 ,
V_14 -> V_23 ) ;
} else {
F_14 ( V_26 , L_10 V_45 L_5 ,
F_22 ( & V_6 -> V_47 ) ) ;
}
F_26 ( V_30 , V_53 , V_53 -> V_57 ) ;
}
V_13 = F_27 ( F_11 ( V_14 ) -> V_59 , V_30 ,
NULL , 0 , NULL , 0 , & V_50 , NULL ) ;
F_28 ( V_50 ) ;
F_29 ( V_53 ) ;
return V_13 ;
}
static void F_30 ( struct V_14 * V_14 ,
struct V_29 * V_30 ,
struct V_40 * * V_41 )
{
F_20 ( V_14 , V_30 , V_41 , V_17 ) ;
if ( * V_41 == NULL )
return;
F_31 ( V_14 , V_30 , & ( * V_41 ) -> V_60 ) ;
F_32 ( V_30 , V_14 , NULL , NULL ,
0 , 0 , V_61 , NULL ) ;
}
static void F_33 ( struct V_14 * V_14 )
{
struct V_40 * V_41 = NULL ;
struct V_29 * V_30 ;
int V_13 ;
F_13 ( F_34 ( F_35 ( V_14 ) ) ) ;
F_36 ( V_30 ) ;
if ( V_30 == NULL ) {
F_18 ( L_11 ) ;
return;
}
F_30 ( V_14 , V_30 , & V_41 ) ;
if ( V_41 == NULL )
GOTO ( V_44 , 0 ) ;
V_13 = F_37 ( F_11 ( V_14 ) -> V_59 , V_30 , NULL ) ;
if ( V_13 == - V_62 ) {
V_13 = F_23 ( V_14 , V_30 ) ;
} else if ( V_13 ) {
F_18 ( L_12 ,
V_14 -> V_22 , V_13 ) ;
}
V_44:
F_38 ( V_30 ) ;
if ( V_41 ) {
F_39 ( F_11 ( V_14 ) -> V_59 , V_41 ) ;
F_40 ( V_41 ) ;
}
}
static struct V_5 * F_41 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = NULL ;
F_3 ( & V_19 -> V_24 ) ;
if ( ! F_4 ( & V_19 -> V_27 ) ) {
V_6 = F_42 ( V_19 -> V_27 . V_63 , struct V_5 ,
V_25 ) ;
F_8 ( & V_6 -> V_25 ) ;
} else if ( F_43 ( & V_19 -> V_64 ) )
V_6 = F_44 ( - V_65 ) ;
F_6 ( & V_19 -> V_24 ) ;
return V_6 ;
}
static int F_45 ( void * V_66 )
{
struct V_18 * V_19 = V_66 ;
F_46 ( & V_19 -> V_67 ) ;
while ( 1 ) {
struct V_68 V_69 = { 0 } ;
struct V_5 * V_6 ;
struct V_14 * V_14 ;
F_47 ( V_19 -> V_28 ,
( V_6 = F_41 ( V_19 ) ) != NULL ,
& V_69 ) ;
if ( F_48 ( V_6 ) )
break;
V_14 = F_49 ( V_6 ) ;
F_14 ( V_70 , L_13 ,
V_14 -> V_22 , V_14 -> V_23 ) ;
F_33 ( V_14 ) ;
F_50 ( V_14 ) ;
}
F_14 ( V_70 , L_14 ) ;
F_46 ( & V_19 -> V_67 ) ;
return 0 ;
}
int F_51 ( struct V_18 * * V_71 )
{
struct V_18 * V_19 ;
struct V_72 * V_73 ;
if ( F_52 ( V_74 ) )
return - V_75 ;
F_53 ( V_19 , sizeof( * V_19 ) ) ;
if ( V_19 == NULL )
return - V_54 ;
F_54 ( & V_19 -> V_24 ) ;
F_55 ( & V_19 -> V_27 ) ;
F_56 ( & V_19 -> V_28 ) ;
F_57 ( & V_19 -> V_67 ) ;
V_73 = F_58 ( F_45 , V_19 , L_15 ) ;
if ( F_48 ( V_73 ) ) {
F_59 ( V_19 , sizeof( * V_19 ) ) ;
return F_60 ( V_73 ) ;
}
F_61 ( & V_19 -> V_67 ) ;
* V_71 = V_19 ;
return 0 ;
}
void F_62 ( struct V_18 * V_19 )
{
F_57 ( & V_19 -> V_67 ) ;
F_63 ( & V_19 -> V_64 ) ;
F_16 ( & V_19 -> V_28 ) ;
F_61 ( & V_19 -> V_67 ) ;
F_59 ( V_19 , sizeof( * V_19 ) ) ;
}
