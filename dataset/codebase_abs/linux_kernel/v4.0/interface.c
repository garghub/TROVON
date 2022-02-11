static struct V_1 * F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned V_14 , V_15 ;
void * V_16 ;
char * V_17 ;
V_11 = F_2 ( V_3 , struct V_10 , V_11 ) ;
F_3 ( L_1 , V_11 -> V_11 . V_18 , V_5 ) ;
V_7 = F_4 ( sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
goto V_20;
V_9 = F_5 ( V_21 , V_19 ) ;
if ( ! V_9 )
goto V_22;
F_6 ( V_9 -> V_23 , == , NULL ) ;
F_7 ( F_8 ( V_24 , & V_9 -> V_25 ) ) ;
F_9 ( & V_9 -> V_26 , 1 ) ;
F_10 ( & V_9 -> V_27 , V_5 , & V_11 -> V_11 ) ;
V_9 -> type = V_5 -> V_28 -> type ;
V_16 = F_4 ( ( 2 + 512 ) + 3 , V_19 ) ;
if ( ! V_16 )
goto V_29;
V_14 = V_5 -> V_28 -> V_30 ( V_5 -> V_31 , V_16 + 2 , 512 ) ;
F_6 ( V_14 , < , 512 ) ;
* ( V_32 * ) V_16 = V_14 ;
( ( char * ) V_16 ) [ V_14 + 2 ] = 0 ;
( ( char * ) V_16 ) [ V_14 + 3 ] = 0 ;
( ( char * ) V_16 ) [ V_14 + 4 ] = 0 ;
V_17 = F_11 ( V_16 , V_14 + 2 , V_9 -> type ) ;
if ( ! V_17 )
goto V_33;
V_13 = V_16 ;
V_15 = 0 ;
if ( V_5 -> V_28 -> V_34 ) {
V_15 = V_5 -> V_28 -> V_34 ( V_5 -> V_31 ,
V_13 -> V_35 , 511 ) ;
F_6 ( V_15 , < , 511 ) ;
}
V_13 -> V_36 = V_15 + 1 ;
V_13 -> type = V_5 -> V_28 -> type ;
V_7 -> V_13 = V_13 ;
V_7 -> V_17 = V_17 ;
V_9 -> V_7 = V_7 ;
F_12 ( L_2 , & V_9 -> V_27 , V_7 ) ;
return & V_9 -> V_27 ;
V_33:
F_13 ( V_16 ) ;
V_29:
F_7 ( F_8 ( V_24 , & V_9 -> V_25 ) ) ;
F_14 ( V_21 , V_9 ) ;
F_15 ( & V_11 -> V_11 ) ;
V_22:
F_13 ( V_7 ) ;
V_20:
F_12 ( L_3 ) ;
return F_16 ( - V_37 ) ;
}
static int F_17 ( struct V_1 * V_38 )
{
struct V_6 * V_7 ;
struct V_8 * V_39 , * V_9 ;
struct V_10 * V_11 ;
const struct V_40 * V_41 ;
int V_42 ;
F_3 ( L_4 , V_38 -> V_43 ) ;
V_11 = F_2 ( V_38 -> V_11 , struct V_10 , V_11 ) ;
V_39 = F_2 ( V_38 -> V_39 ,
struct V_8 , V_27 ) ;
V_9 = F_2 ( V_38 , struct V_8 , V_27 ) ;
V_7 = V_9 -> V_7 ;
F_6 ( V_7 , != , NULL ) ;
F_18 ( V_11 , & V_41 ) ;
V_42 = F_19 ( V_39 , V_9 ,
V_7 -> V_17 ,
V_7 -> V_13 ) ;
F_20 ( V_11 , V_41 ) ;
if ( V_42 == 0 &&
V_9 -> V_27 . V_5 -> V_28 -> type != V_44 )
F_21 ( & V_9 -> V_27 ) ;
if ( V_42 < 0 && V_42 != - V_45 ) {
if ( V_42 != - V_46 )
F_22 ( L_5 , V_42 ) ;
F_23 ( & V_9 -> V_27 ) ;
}
F_12 ( L_6 , V_42 ) ;
return V_42 ;
}
static void F_24 ( struct V_1 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_38 , struct V_8 , V_27 ) ;
F_3 ( L_7 , V_9 -> V_27 . V_43 , V_9 -> V_7 ) ;
if ( V_9 -> V_7 ) {
F_13 ( V_9 -> V_7 -> V_17 ) ;
F_13 ( V_9 -> V_7 -> V_13 ) ;
F_13 ( V_9 -> V_7 ) ;
V_9 -> V_7 = NULL ;
}
}
static
struct V_1 * F_25 ( struct V_1 * V_38 )
{
struct V_8 * V_9 =
F_2 ( V_38 , struct V_8 , V_27 ) ;
F_3 ( L_8 , V_38 -> V_43 , F_26 ( & V_9 -> V_26 ) ) ;
#ifdef F_27
ASSERT ( ( F_26 ( & V_9 -> V_26 ) & 0xffff0000 ) != 0x6b6b0000 ) ;
#endif
F_28 ( & V_9 -> V_26 ) ;
return & V_9 -> V_27 ;
}
static void F_29 ( struct V_1 * V_38 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
struct V_4 * V_5 ;
const struct V_40 * V_41 ;
unsigned V_15 ;
F_3 ( L_4 , V_38 -> V_43 ) ;
V_9 = F_2 ( V_38 , struct V_8 , V_27 ) ;
V_11 = F_2 ( V_9 -> V_27 . V_11 , struct V_10 ,
V_11 ) ;
if ( ! F_30 ( V_38 ) ) {
F_12 ( L_9 ) ;
return;
}
V_5 = V_9 -> V_27 . V_5 ;
if ( ! V_5 -> V_28 -> V_34 ) {
F_31 ( V_38 ) ;
F_12 ( L_10 ) ;
return;
}
V_13 = F_4 ( 2 + 512 + 3 , V_19 ) ;
if ( ! V_13 ) {
F_31 ( V_38 ) ;
F_12 ( L_11 ) ;
return;
}
V_15 = V_5 -> V_28 -> V_34 ( V_5 -> V_31 , V_13 -> V_35 , 511 ) ;
F_31 ( V_38 ) ;
F_6 ( V_15 , < , 511 ) ;
V_13 -> V_36 = V_15 + 1 ;
V_13 -> type = V_5 -> V_28 -> type ;
F_18 ( V_11 , & V_41 ) ;
F_32 ( V_9 , V_13 ) ;
F_20 ( V_11 , V_41 ) ;
F_13 ( V_13 ) ;
F_12 ( L_12 ) ;
}
static void F_33 ( struct V_1 * V_38 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
const struct V_40 * V_41 ;
ASSERT ( V_38 ) ;
V_9 = F_2 ( V_38 , struct V_8 , V_27 ) ;
F_3 ( L_8 ,
V_9 -> V_27 . V_43 , F_26 ( & V_9 -> V_26 ) ) ;
V_11 = F_2 ( V_9 -> V_27 . V_11 ,
struct V_10 , V_11 ) ;
#ifdef F_27
ASSERT ( ( F_26 ( & V_9 -> V_26 ) & 0xffff0000 ) != 0x6b6b0000 ) ;
#endif
if ( V_9 -> V_47 ) {
if ( F_8 ( V_48 , & V_9 -> V_27 . V_25 ) &&
V_38 != V_11 -> V_11 . V_49
) {
F_34 ( L_13 , V_9 -> V_27 . V_43 ) ;
F_18 ( V_11 , & V_41 ) ;
F_35 ( V_11 , V_9 ) ;
F_20 ( V_11 , V_41 ) ;
}
if ( V_9 -> V_23 != V_9 -> V_47 )
F_36 ( V_9 -> V_23 ) ;
V_9 -> V_23 = NULL ;
}
if ( F_8 ( V_24 , & V_9 -> V_25 ) ) {
F_37 ( & V_11 -> V_50 ) ;
if ( ! F_38 ( V_24 ,
& V_9 -> V_25 ) )
F_39 () ;
F_40 ( & V_9 -> V_51 , & V_11 -> V_52 ) ;
F_41 ( & V_9 -> V_25 , V_24 ) ;
F_42 ( & V_11 -> V_50 ) ;
}
F_36 ( V_9 -> V_47 ) ;
V_9 -> V_47 = NULL ;
F_12 ( L_12 ) ;
}
static void F_43 ( struct V_1 * V_38 )
{
struct V_8 * V_9 ;
struct V_2 * V_11 ;
ASSERT ( V_38 ) ;
V_9 = F_2 ( V_38 , struct V_8 , V_27 ) ;
F_3 ( L_8 ,
V_9 -> V_27 . V_43 , F_26 ( & V_9 -> V_26 ) ) ;
#ifdef F_27
ASSERT ( ( F_26 ( & V_9 -> V_26 ) & 0xffff0000 ) != 0x6b6b0000 ) ;
#endif
F_44 ( V_9 -> V_27 . V_39 ,
V_9 -> V_27 . V_39 -> V_53 , > , 0 ) ;
if ( F_45 ( & V_9 -> V_26 ) ) {
F_34 ( L_14 , V_9 -> V_27 . V_43 ) ;
ASSERT ( ! F_8 ( V_24 , & V_9 -> V_25 ) ) ;
F_6 ( V_9 -> V_27 . V_39 , == , NULL ) ;
F_6 ( V_9 -> V_23 , == , NULL ) ;
F_6 ( V_9 -> V_47 , == , NULL ) ;
F_6 ( V_9 -> V_27 . V_54 , == , 0 ) ;
F_6 ( V_9 -> V_27 . V_53 , == , 0 ) ;
if ( V_9 -> V_7 ) {
F_13 ( V_9 -> V_7 -> V_17 ) ;
F_13 ( V_9 -> V_7 -> V_13 ) ;
F_13 ( V_9 -> V_7 ) ;
V_9 -> V_7 = NULL ;
}
V_11 = V_9 -> V_27 . V_11 ;
F_46 ( & V_9 -> V_27 ) ;
F_14 ( V_21 , V_9 ) ;
F_15 ( V_11 ) ;
}
F_12 ( L_12 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_10 * V_11 ;
const struct V_40 * V_41 ;
int V_42 ;
F_3 ( L_15 , V_3 ) ;
V_11 = F_2 ( V_3 , struct V_10 , V_11 ) ;
F_18 ( V_11 , & V_41 ) ;
F_48 ( & V_11 -> V_55 -> V_56 -> V_57 ) ;
V_42 = F_49 ( V_11 -> V_55 -> V_56 ) ;
F_50 ( & V_11 -> V_55 -> V_56 -> V_57 ) ;
F_20 ( V_11 , V_41 ) ;
if ( V_42 == - V_58 )
F_51 ( V_11 ,
L_16
L_17 ,
V_42 ) ;
}
static bool F_52 ( struct V_59 * V_60 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
const struct V_40 * V_41 ;
int V_42 ;
F_3 ( L_4 , V_60 -> V_9 -> V_43 ) ;
V_9 = F_2 ( V_60 -> V_9 , struct V_8 , V_27 ) ;
V_11 = F_2 ( V_9 -> V_27 . V_11 ,
struct V_10 , V_11 ) ;
F_18 ( V_11 , & V_41 ) ;
V_42 = F_53 ( V_9 ) ;
F_20 ( V_11 , V_41 ) ;
F_12 ( L_18 , V_42 ) ;
return V_42 ;
}
static int F_21 ( struct V_1 * V_38 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
const struct V_40 * V_41 ;
struct V_61 V_62 ;
T_1 V_63 ;
T_2 V_64 ;
int V_42 ;
V_38 -> V_5 -> V_28 -> V_65 ( V_38 -> V_5 -> V_31 , & V_63 ) ;
F_3 ( L_19 ,
V_38 -> V_43 , ( unsigned long long ) V_63 ) ;
V_9 = F_2 ( V_38 , struct V_8 , V_27 ) ;
V_11 = F_2 ( V_9 -> V_27 . V_11 ,
struct V_10 , V_11 ) ;
if ( V_63 == V_9 -> V_66 )
return 0 ;
if ( ! V_9 -> V_23 )
return - V_46 ;
ASSERT ( F_54 ( V_9 -> V_23 ) ) ;
F_55 ( & V_9 -> V_27 , V_63 ) ;
V_64 = F_56 ( V_9 -> V_23 -> V_67 ) ;
if ( V_64 == V_63 )
return 0 ;
F_18 ( V_11 , & V_41 ) ;
F_57 ( & V_9 -> V_23 -> V_67 -> V_68 ) ;
if ( V_64 & ~ V_69 && V_63 > V_64 ) {
F_34 ( L_20 , V_64 ) ;
V_62 . V_70 = V_71 ;
V_62 . V_72 = V_64 & V_69 ;
V_42 = F_58 ( V_9 -> V_23 , & V_62 , NULL ) ;
if ( V_42 < 0 )
goto V_73;
}
V_62 . V_70 = V_71 ;
V_62 . V_72 = V_63 ;
V_42 = F_58 ( V_9 -> V_23 , & V_62 , NULL ) ;
V_73:
F_59 ( & V_9 -> V_23 -> V_67 -> V_68 ) ;
F_20 ( V_11 , V_41 ) ;
if ( V_42 == - V_58 ) {
F_55 ( & V_9 -> V_27 , 0 ) ;
F_60 ( V_9 , L_21 ) ;
V_42 = - V_46 ;
}
F_12 ( L_18 , V_42 ) ;
return V_42 ;
}
static void F_61 ( struct V_59 * V_60 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
const struct V_40 * V_41 ;
struct V_74 V_74 ;
T_1 V_63 ;
int V_42 ;
V_9 = F_2 ( V_60 -> V_9 , struct V_8 , V_27 ) ;
V_11 = F_2 ( V_9 -> V_27 . V_11 ,
struct V_10 , V_11 ) ;
V_60 -> V_9 -> V_5 -> V_28 -> V_65 ( V_60 -> V_9 -> V_5 -> V_31 ,
& V_63 ) ;
F_3 ( L_19 ,
V_60 -> V_9 -> V_43 , ( unsigned long long ) V_63 ) ;
if ( V_9 -> V_23 ) {
ASSERT ( F_54 ( V_9 -> V_23 ) ) ;
F_55 ( & V_9 -> V_27 , V_63 ) ;
V_74 . V_47 = V_9 -> V_23 ;
V_74 . V_55 = V_11 -> V_55 ;
F_18 ( V_11 , & V_41 ) ;
V_42 = F_62 ( & V_74 , 0 ) ;
if ( V_42 == 0 )
V_42 = F_62 ( & V_74 , V_63 ) ;
F_20 ( V_11 , V_41 ) ;
if ( V_42 != 0 ) {
F_55 ( & V_9 -> V_27 , 0 ) ;
if ( V_42 == - V_58 )
F_60 ( V_9 ,
L_22 ) ;
}
}
F_63 ( V_60 , true ) ;
F_12 ( L_12 ) ;
}
static void F_64 ( struct V_2 * V_11 )
{
F_3 ( L_12 ) ;
}
