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
if ( V_11 -> V_16 . V_17 )
V_11 -> V_16 . V_17 ( V_7 ) ;
V_7 -> V_14 |= V_15 ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_18 * V_12 = V_7 -> V_12 ;
struct V_10 * V_11 = V_12 -> V_13 -> type ;
F_10 ( & V_2 -> V_19 ) ;
F_10 ( V_12 -> V_20 ) ;
F_11 ( & V_2 -> V_21 , V_7 -> V_12 -> V_22 ) ;
F_12 ( & V_7 -> V_23 ) ;
F_13 ( & V_7 -> V_24 ) ;
if ( F_14 ( V_2 -> V_25 ) == V_7 )
F_15 ( V_2 -> V_25 , NULL ) ;
F_8 ( V_7 ) ;
V_7 -> V_9 = V_11 -> V_26 ;
F_16 ( & V_7 -> V_8 , F_5 ) ;
}
static void F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_6 ( V_28 , struct V_1 ,
V_29 ) ;
unsigned long V_14 ;
F_18 ( & V_2 -> V_19 , V_14 , 1 ) ;
while ( ! F_19 ( & V_2 -> V_30 ) ) {
struct V_6 * V_7 = F_20 ( V_2 -> V_30 . V_31 ,
struct V_6 , V_23 ) ;
struct V_18 * V_12 = V_7 -> V_12 ;
if ( F_21 ( V_12 -> V_20 ) ) {
F_9 ( V_7 ) ;
F_22 ( V_12 -> V_20 ) ;
} else {
F_23 ( & V_2 -> V_19 , V_14 ) ;
F_24 () ;
F_18 ( & V_2 -> V_19 , V_14 , 1 ) ;
}
}
F_23 ( & V_2 -> V_19 , V_14 ) ;
F_7 ( V_32 , V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
bool V_33 = false ;
if ( V_2 == NULL )
return;
F_2 ( F_3 ( & V_2 -> V_3 ) <= 0 ) ;
if ( F_26 ( & V_2 -> V_3 ) ) {
F_27 ( & V_2 -> V_19 , V_14 ) ;
if ( ! F_19 ( & V_2 -> V_30 ) )
F_28 ( & V_2 -> V_29 ) ;
else
V_33 = true ;
F_23 ( & V_2 -> V_19 , V_14 ) ;
}
if ( V_33 )
F_7 ( V_32 , V_2 ) ;
}
void F_29 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_36 * V_37 ;
unsigned long V_14 ;
F_30 ( V_35 ) ;
V_2 = V_35 -> V_1 ;
V_35 -> V_1 = NULL ;
F_31 ( V_35 ) ;
if ( ! F_32 ( & V_2 -> V_38 ) ) {
F_25 ( V_2 ) ;
return;
}
V_39:
F_18 ( & V_2 -> V_19 , V_14 , 1 ) ;
F_33 (icq, n, &ioc->icq_list, ioc_node) {
if ( V_7 -> V_14 & V_15 )
continue;
if ( F_21 ( V_7 -> V_12 -> V_20 ) ) {
F_8 ( V_7 ) ;
F_22 ( V_7 -> V_12 -> V_20 ) ;
} else {
F_23 ( & V_2 -> V_19 , V_14 ) ;
F_24 () ;
goto V_39;
}
}
F_23 ( & V_2 -> V_19 , V_14 ) ;
F_25 ( V_2 ) ;
}
void F_34 ( struct V_18 * V_12 )
{
F_10 ( V_12 -> V_20 ) ;
while ( ! F_35 ( & V_12 -> V_30 ) ) {
struct V_6 * V_7 = F_36 ( V_12 -> V_30 . V_40 ,
struct V_6 , V_24 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_37 ( & V_2 -> V_19 ) ;
F_9 ( V_7 ) ;
F_22 ( & V_2 -> V_19 ) ;
}
}
void F_38 ( struct V_34 * V_35 , T_1 V_41 ,
int V_42 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( V_32 , V_41 | V_43 ,
V_42 ) ;
if ( F_40 ( ! V_2 ) )
return;
F_41 ( & V_2 -> V_3 , 1 ) ;
F_42 ( & V_2 -> V_38 , 1 ) ;
F_43 ( & V_2 -> V_19 ) ;
F_44 ( & V_2 -> V_21 , V_44 | V_45 ) ;
F_45 ( & V_2 -> V_30 ) ;
F_46 ( & V_2 -> V_29 , F_17 ) ;
F_30 ( V_35 ) ;
if ( ! V_35 -> V_1 &&
( V_35 == V_46 || ! ( V_35 -> V_14 & V_47 ) ) )
V_35 -> V_1 = V_2 ;
else
F_7 ( V_32 , V_2 ) ;
F_31 ( V_35 ) ;
}
struct V_1 * F_47 ( struct V_34 * V_35 ,
T_1 V_41 , int V_42 )
{
struct V_1 * V_2 ;
F_48 ( V_41 & V_48 ) ;
do {
F_30 ( V_35 ) ;
V_2 = V_35 -> V_1 ;
if ( F_49 ( V_2 ) ) {
F_1 ( V_2 ) ;
F_31 ( V_35 ) ;
return V_2 ;
}
F_31 ( V_35 ) ;
} while ( F_50 ( V_35 , V_41 , V_42 ) );
return NULL ;
}
struct V_6 * F_51 ( struct V_1 * V_2 , struct V_18 * V_12 )
{
struct V_6 * V_7 ;
F_10 ( V_12 -> V_20 ) ;
F_52 () ;
V_7 = F_53 ( V_2 -> V_25 ) ;
if ( V_7 && V_7 -> V_12 == V_12 )
goto V_49;
V_7 = F_54 ( & V_2 -> V_21 , V_12 -> V_22 ) ;
if ( V_7 && V_7 -> V_12 == V_12 )
F_15 ( V_2 -> V_25 , V_7 ) ;
else
V_7 = NULL ;
V_49:
F_55 () ;
return V_7 ;
}
struct V_6 * F_56 ( struct V_18 * V_12 , T_1 V_50 )
{
struct V_10 * V_11 = V_12 -> V_13 -> type ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_2 = F_50 ( V_46 , V_50 , V_12 -> V_42 ) ;
if ( ! V_2 )
return NULL ;
V_7 = F_39 ( V_11 -> V_26 , V_50 | V_43 ,
V_12 -> V_42 ) ;
if ( ! V_7 )
return NULL ;
if ( F_57 ( V_50 ) < 0 ) {
F_7 ( V_11 -> V_26 , V_7 ) ;
return NULL ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_12 = V_12 ;
F_58 ( & V_7 -> V_24 ) ;
F_59 ( & V_7 -> V_23 ) ;
F_60 ( V_12 -> V_20 ) ;
F_37 ( & V_2 -> V_19 ) ;
if ( F_49 ( ! F_61 ( & V_2 -> V_21 , V_12 -> V_22 , V_7 ) ) ) {
F_62 ( & V_7 -> V_23 , & V_2 -> V_30 ) ;
F_63 ( & V_7 -> V_24 , & V_12 -> V_30 ) ;
if ( V_11 -> V_16 . V_51 )
V_11 -> V_16 . V_51 ( V_7 ) ;
} else {
F_7 ( V_11 -> V_26 , V_7 ) ;
V_7 = F_51 ( V_2 , V_12 ) ;
if ( ! V_7 )
F_64 ( V_52 L_1 ) ;
}
F_22 ( & V_2 -> V_19 ) ;
F_65 ( V_12 -> V_20 ) ;
F_66 () ;
return V_7 ;
}
void F_67 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_6 * V_7 ;
struct V_36 * V_37 ;
F_33 (icq, n, &ioc->icq_list, ioc_node)
V_7 -> V_14 |= V_14 ;
}
void F_68 ( struct V_1 * V_2 , int V_53 )
{
unsigned long V_14 ;
F_27 ( & V_2 -> V_19 , V_14 ) ;
V_2 -> V_53 = V_53 ;
F_67 ( V_2 , V_54 ) ;
F_23 ( & V_2 -> V_19 , V_14 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
F_27 ( & V_2 -> V_19 , V_14 ) ;
F_67 ( V_2 , V_55 ) ;
F_23 ( & V_2 -> V_19 , V_14 ) ;
}
unsigned F_70 ( struct V_6 * V_7 )
{
unsigned int V_56 = 0 ;
unsigned long V_14 ;
if ( F_40 ( V_7 -> V_14 & V_57 ) ) {
F_27 ( & V_7 -> V_2 -> V_19 , V_14 ) ;
V_56 = V_7 -> V_14 & V_57 ;
V_7 -> V_14 &= ~ V_57 ;
F_23 ( & V_7 -> V_2 -> V_19 , V_14 ) ;
}
return V_56 ;
}
static int T_2 F_71 ( void )
{
V_32 = F_72 ( L_2 ,
sizeof( struct V_1 ) , 0 , V_58 , NULL ) ;
return 0 ;
}
