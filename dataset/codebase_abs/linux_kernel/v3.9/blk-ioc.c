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
void F_29 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
struct V_6 * V_7 ;
if ( ! F_30 ( & V_2 -> V_34 ) ) {
F_25 ( V_2 ) ;
return;
}
V_35:
F_18 ( & V_2 -> V_19 , V_14 , 1 ) ;
F_31 (icq, &ioc->icq_list, ioc_node) {
if ( V_7 -> V_14 & V_15 )
continue;
if ( F_21 ( V_7 -> V_12 -> V_20 ) ) {
F_8 ( V_7 ) ;
F_22 ( V_7 -> V_12 -> V_20 ) ;
} else {
F_23 ( & V_2 -> V_19 , V_14 ) ;
F_24 () ;
goto V_35;
}
}
F_23 ( & V_2 -> V_19 , V_14 ) ;
F_25 ( V_2 ) ;
}
void F_32 ( struct V_36 * V_37 )
{
struct V_1 * V_2 ;
F_33 ( V_37 ) ;
V_2 = V_37 -> V_1 ;
V_37 -> V_1 = NULL ;
F_34 ( V_37 ) ;
F_35 ( & V_2 -> V_38 ) ;
F_29 ( V_2 ) ;
}
void F_36 ( struct V_18 * V_12 )
{
F_10 ( V_12 -> V_20 ) ;
while ( ! F_37 ( & V_12 -> V_30 ) ) {
struct V_6 * V_7 = F_38 ( V_12 -> V_30 . V_39 ,
struct V_6 , V_24 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
F_39 ( & V_2 -> V_19 ) ;
F_9 ( V_7 ) ;
F_22 ( & V_2 -> V_19 ) ;
}
}
int F_40 ( struct V_36 * V_37 , T_1 V_40 , int V_41 )
{
struct V_1 * V_2 ;
int V_42 ;
V_2 = F_41 ( V_32 , V_40 | V_43 ,
V_41 ) ;
if ( F_42 ( ! V_2 ) )
return - V_44 ;
F_43 ( & V_2 -> V_3 , 1 ) ;
F_44 ( & V_2 -> V_38 , 1 ) ;
F_44 ( & V_2 -> V_34 , 1 ) ;
F_45 ( & V_2 -> V_19 ) ;
F_46 ( & V_2 -> V_21 , V_45 | V_46 ) ;
F_47 ( & V_2 -> V_30 ) ;
F_48 ( & V_2 -> V_29 , F_17 ) ;
F_33 ( V_37 ) ;
if ( ! V_37 -> V_1 &&
( V_37 == V_47 || ! ( V_37 -> V_14 & V_48 ) ) )
V_37 -> V_1 = V_2 ;
else
F_7 ( V_32 , V_2 ) ;
V_42 = V_37 -> V_1 ? 0 : - V_49 ;
F_34 ( V_37 ) ;
return V_42 ;
}
struct V_1 * F_49 ( struct V_36 * V_37 ,
T_1 V_40 , int V_41 )
{
struct V_1 * V_2 ;
F_50 ( V_40 & V_50 ) ;
do {
F_33 ( V_37 ) ;
V_2 = V_37 -> V_1 ;
if ( F_51 ( V_2 ) ) {
F_1 ( V_2 ) ;
F_34 ( V_37 ) ;
return V_2 ;
}
F_34 ( V_37 ) ;
} while ( ! F_40 ( V_37 , V_40 , V_41 ) );
return NULL ;
}
struct V_6 * F_52 ( struct V_1 * V_2 , struct V_18 * V_12 )
{
struct V_6 * V_7 ;
F_10 ( V_12 -> V_20 ) ;
F_53 () ;
V_7 = F_54 ( V_2 -> V_25 ) ;
if ( V_7 && V_7 -> V_12 == V_12 )
goto V_51;
V_7 = F_55 ( & V_2 -> V_21 , V_12 -> V_22 ) ;
if ( V_7 && V_7 -> V_12 == V_12 )
F_15 ( V_2 -> V_25 , V_7 ) ;
else
V_7 = NULL ;
V_51:
F_56 () ;
return V_7 ;
}
struct V_6 * F_57 ( struct V_1 * V_2 , struct V_18 * V_12 ,
T_1 V_52 )
{
struct V_10 * V_11 = V_12 -> V_13 -> type ;
struct V_6 * V_7 ;
V_7 = F_41 ( V_11 -> V_26 , V_52 | V_43 ,
V_12 -> V_41 ) ;
if ( ! V_7 )
return NULL ;
if ( F_58 ( V_52 ) < 0 ) {
F_7 ( V_11 -> V_26 , V_7 ) ;
return NULL ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_12 = V_12 ;
F_59 ( & V_7 -> V_24 ) ;
F_60 ( & V_7 -> V_23 ) ;
F_61 ( V_12 -> V_20 ) ;
F_39 ( & V_2 -> V_19 ) ;
if ( F_51 ( ! F_62 ( & V_2 -> V_21 , V_12 -> V_22 , V_7 ) ) ) {
F_63 ( & V_7 -> V_23 , & V_2 -> V_30 ) ;
F_64 ( & V_7 -> V_24 , & V_12 -> V_30 ) ;
if ( V_11 -> V_16 . V_53 )
V_11 -> V_16 . V_53 ( V_7 ) ;
} else {
F_7 ( V_11 -> V_26 , V_7 ) ;
V_7 = F_52 ( V_2 , V_12 ) ;
if ( ! V_7 )
F_65 ( V_54 L_1 ) ;
}
F_22 ( & V_2 -> V_19 ) ;
F_66 ( V_12 -> V_20 ) ;
F_67 () ;
return V_7 ;
}
static int T_2 F_68 ( void )
{
V_32 = F_69 ( L_2 ,
sizeof( struct V_1 ) , 0 , V_55 , NULL ) ;
return 0 ;
}
