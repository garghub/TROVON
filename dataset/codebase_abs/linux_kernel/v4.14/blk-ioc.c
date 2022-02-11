void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) <= 0 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 , struct V_6 , V_8 ) ;
F_7 ( V_7 -> V_9 , V_7 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_12 -> V_13 -> type ;
if ( V_7 -> V_14 & V_15 )
return;
if ( V_11 -> V_16 && V_11 -> V_17 . V_18 . V_19 )
V_11 -> V_17 . V_18 . V_19 ( V_7 ) ;
else if ( ! V_11 -> V_16 && V_11 -> V_17 . V_20 . V_21 )
V_11 -> V_17 . V_20 . V_21 ( V_7 ) ;
V_7 -> V_14 |= V_15 ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_22 * V_12 = V_7 -> V_12 ;
struct V_10 * V_11 = V_12 -> V_13 -> type ;
F_10 ( & V_2 -> V_23 ) ;
F_11 ( & V_2 -> V_24 , V_7 -> V_12 -> V_25 ) ;
F_12 ( & V_7 -> V_26 ) ;
F_13 ( & V_7 -> V_27 ) ;
if ( F_14 ( V_2 -> V_28 ) == V_7 )
F_15 ( V_2 -> V_28 , NULL ) ;
F_8 ( V_7 ) ;
V_7 -> V_9 = V_11 -> V_29 ;
F_16 ( & V_7 -> V_8 , F_5 ) ;
}
static void F_17 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_6 ( V_31 , struct V_1 ,
V_32 ) ;
unsigned long V_14 ;
F_18 ( & V_2 -> V_23 , V_14 , 1 ) ;
while ( ! F_19 ( & V_2 -> V_33 ) ) {
struct V_6 * V_7 = F_20 ( V_2 -> V_33 . V_34 ,
struct V_6 , V_26 ) ;
struct V_22 * V_12 = V_7 -> V_12 ;
if ( F_21 ( V_12 -> V_35 ) ) {
F_9 ( V_7 ) ;
F_22 ( V_12 -> V_35 ) ;
} else {
F_23 ( & V_2 -> V_23 , V_14 ) ;
F_24 () ;
F_18 ( & V_2 -> V_23 , V_14 , 1 ) ;
}
}
F_23 ( & V_2 -> V_23 , V_14 ) ;
F_7 ( V_36 , V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
bool V_37 = false ;
if ( V_2 == NULL )
return;
F_2 ( F_3 ( & V_2 -> V_3 ) <= 0 ) ;
if ( F_26 ( & V_2 -> V_3 ) ) {
F_27 ( & V_2 -> V_23 , V_14 ) ;
if ( ! F_19 ( & V_2 -> V_33 ) )
F_28 ( V_38 ,
& V_2 -> V_32 ) ;
else
V_37 = true ;
F_23 ( & V_2 -> V_23 , V_14 ) ;
}
if ( V_37 )
F_7 ( V_36 , V_2 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
unsigned long V_14 ;
struct V_6 * V_7 ;
if ( ! F_30 ( & V_2 -> V_39 ) ) {
F_25 ( V_2 ) ;
return;
}
V_40:
F_18 ( & V_2 -> V_23 , V_14 , 1 ) ;
F_31 (icq, &ioc->icq_list, ioc_node) {
if ( V_7 -> V_14 & V_15 )
continue;
V_11 = V_7 -> V_12 -> V_13 -> type ;
if ( V_11 -> V_16 ) {
F_8 ( V_7 ) ;
} else {
if ( F_21 ( V_7 -> V_12 -> V_35 ) ) {
F_8 ( V_7 ) ;
F_22 ( V_7 -> V_12 -> V_35 ) ;
} else {
F_23 ( & V_2 -> V_23 , V_14 ) ;
F_24 () ;
goto V_40;
}
}
}
F_23 ( & V_2 -> V_23 , V_14 ) ;
F_25 ( V_2 ) ;
}
void F_32 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
F_33 ( V_42 ) ;
V_2 = V_42 -> V_1 ;
V_42 -> V_1 = NULL ;
F_34 ( V_42 ) ;
F_35 ( & V_2 -> V_43 ) ;
F_29 ( V_2 ) ;
}
static void F_36 ( struct V_44 * V_33 )
{
unsigned long V_14 ;
while ( ! F_37 ( V_33 ) ) {
struct V_6 * V_7 = F_38 ( V_33 -> V_45 ,
struct V_6 , V_27 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_27 ( & V_2 -> V_23 , V_14 ) ;
F_9 ( V_7 ) ;
F_23 ( & V_2 -> V_23 , V_14 ) ;
}
}
void F_39 ( struct V_22 * V_12 )
{
F_40 ( V_33 ) ;
F_41 ( V_12 -> V_35 ) ;
F_42 ( & V_12 -> V_33 , & V_33 ) ;
if ( V_12 -> V_46 ) {
F_43 ( V_12 -> V_35 ) ;
F_36 ( & V_33 ) ;
} else {
F_36 ( & V_33 ) ;
F_43 ( V_12 -> V_35 ) ;
}
}
int F_44 ( struct V_41 * V_42 , T_1 V_47 , int V_48 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_45 ( V_36 , V_47 | V_50 ,
V_48 ) ;
if ( F_46 ( ! V_2 ) )
return - V_51 ;
F_47 ( & V_2 -> V_3 , 1 ) ;
F_48 ( & V_2 -> V_43 , 1 ) ;
F_48 ( & V_2 -> V_39 , 1 ) ;
F_49 ( & V_2 -> V_23 ) ;
F_50 ( & V_2 -> V_24 , V_52 | V_53 ) ;
F_51 ( & V_2 -> V_33 ) ;
F_52 ( & V_2 -> V_32 , F_17 ) ;
F_33 ( V_42 ) ;
if ( ! V_42 -> V_1 &&
( V_42 == V_54 || ! ( V_42 -> V_14 & V_55 ) ) )
V_42 -> V_1 = V_2 ;
else
F_7 ( V_36 , V_2 ) ;
V_49 = V_42 -> V_1 ? 0 : - V_56 ;
F_34 ( V_42 ) ;
return V_49 ;
}
struct V_1 * F_53 ( struct V_41 * V_42 ,
T_1 V_47 , int V_48 )
{
struct V_1 * V_2 ;
F_54 ( F_55 ( V_47 ) ) ;
do {
F_33 ( V_42 ) ;
V_2 = V_42 -> V_1 ;
if ( F_56 ( V_2 ) ) {
F_1 ( V_2 ) ;
F_34 ( V_42 ) ;
return V_2 ;
}
F_34 ( V_42 ) ;
} while ( ! F_44 ( V_42 , V_47 , V_48 ) );
return NULL ;
}
struct V_6 * F_57 ( struct V_1 * V_2 , struct V_22 * V_12 )
{
struct V_6 * V_7 ;
F_10 ( V_12 -> V_35 ) ;
F_58 () ;
V_7 = F_59 ( V_2 -> V_28 ) ;
if ( V_7 && V_7 -> V_12 == V_12 )
goto V_57;
V_7 = F_60 ( & V_2 -> V_24 , V_12 -> V_25 ) ;
if ( V_7 && V_7 -> V_12 == V_12 )
F_15 ( V_2 -> V_28 , V_7 ) ;
else
V_7 = NULL ;
V_57:
F_61 () ;
return V_7 ;
}
struct V_6 * F_62 ( struct V_1 * V_2 , struct V_22 * V_12 ,
T_1 V_58 )
{
struct V_10 * V_11 = V_12 -> V_13 -> type ;
struct V_6 * V_7 ;
V_7 = F_45 ( V_11 -> V_29 , V_58 | V_50 ,
V_12 -> V_48 ) ;
if ( ! V_7 )
return NULL ;
if ( F_63 ( V_58 ) < 0 ) {
F_7 ( V_11 -> V_29 , V_7 ) ;
return NULL ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_12 = V_12 ;
F_64 ( & V_7 -> V_27 ) ;
F_65 ( & V_7 -> V_26 ) ;
F_41 ( V_12 -> V_35 ) ;
F_66 ( & V_2 -> V_23 ) ;
if ( F_56 ( ! F_67 ( & V_2 -> V_24 , V_12 -> V_25 , V_7 ) ) ) {
F_68 ( & V_7 -> V_26 , & V_2 -> V_33 ) ;
F_69 ( & V_7 -> V_27 , & V_12 -> V_33 ) ;
if ( V_11 -> V_16 && V_11 -> V_17 . V_18 . V_59 )
V_11 -> V_17 . V_18 . V_59 ( V_7 ) ;
else if ( ! V_11 -> V_16 && V_11 -> V_17 . V_20 . V_60 )
V_11 -> V_17 . V_20 . V_60 ( V_7 ) ;
} else {
F_7 ( V_11 -> V_29 , V_7 ) ;
V_7 = F_57 ( V_2 , V_12 ) ;
if ( ! V_7 )
F_70 ( V_61 L_1 ) ;
}
F_22 ( & V_2 -> V_23 ) ;
F_43 ( V_12 -> V_35 ) ;
F_71 () ;
return V_7 ;
}
static int T_2 F_72 ( void )
{
V_36 = F_73 ( L_2 ,
sizeof( struct V_1 ) , 0 , V_62 , NULL ) ;
return 0 ;
}
