void F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 =
F_2 ( V_1 -> V_3 -> V_4 ) -> V_5 ;
F_3 ( V_1 -> V_4 ) ;
V_1 -> V_6 = ( void * ) V_2 ;
}
static int F_4 ( struct V_1 * V_1 ,
struct V_7 * V_8 )
{
struct V_9 * V_9 ;
int V_10 = 0 ;
struct V_11 * V_12 ;
if ( V_8 && V_8 -> V_13 & V_14 )
return - V_15 ;
V_9 = V_1 -> V_4 ;
V_12 = F_5 ( V_1 -> V_16 ) ;
F_6 ( V_1 , V_1 -> V_17 . V_18 ,
V_1 -> V_17 . V_19 ) ;
if ( V_9 == NULL ) {
unsigned long V_2 = ( unsigned long ) V_1 -> V_6 ;
unsigned long V_20 =
F_2 ( V_1 -> V_3 -> V_4 ) -> V_5 ;
F_7 ( V_1 -> V_17 . V_18 ,
V_1 -> V_17 . V_19 ,
V_20 , V_2 ) ;
if ( V_2 != V_20 )
goto V_21;
goto V_22;
}
F_3 ( ! V_12 ) ;
if ( V_9 == V_12 -> V_23 || F_8 ( V_9 ) )
goto V_21;
F_9 ( & F_2 ( V_9 ) -> V_24 ) ;
if ( F_2 ( V_9 ) -> V_25 & V_26 ) {
F_10 ( & F_2 ( V_9 ) -> V_24 ) ;
F_11 (
( unsigned long long ) F_2 ( V_9 ) -> V_27 ) ;
goto V_21;
}
F_10 ( & F_2 ( V_9 ) -> V_24 ) ;
if ( V_9 -> V_28 == 0 ) {
F_12 (
( unsigned long long ) F_2 ( V_9 ) -> V_27 ,
F_13 ( V_9 -> V_29 ) ) ;
goto V_21;
}
if ( ! V_1 -> V_6 ) {
F_14 (
( unsigned long long ) F_2 ( V_9 ) -> V_27 ) ;
goto V_21;
}
V_22:
V_10 = 1 ;
V_21:
F_15 ( V_10 ) ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_1 ,
T_1 V_30 ,
int V_31 )
{
struct V_9 * V_32 ;
if ( ! V_1 -> V_6 )
return 0 ;
if ( ! V_1 -> V_3 )
return 0 ;
if ( V_31 && F_17 ( V_1 ) )
return 0 ;
V_32 = V_1 -> V_3 -> V_4 ;
if ( ! V_32 )
return 0 ;
if ( F_2 ( V_32 ) -> V_27 != V_30 )
return 0 ;
return 1 ;
}
struct V_1 * F_18 ( struct V_9 * V_9 ,
T_1 V_30 ,
int V_31 )
{
struct V_33 * V_34 ;
struct V_1 * V_1 = NULL ;
F_9 ( & V_9 -> V_35 ) ;
F_19 (p, &inode->i_dentry) {
V_1 = F_20 ( V_34 , struct V_1 , V_36 ) ;
F_9 ( & V_1 -> V_37 ) ;
if ( F_16 ( V_1 , V_30 , V_31 ) ) {
F_21 ( V_1 -> V_17 . V_18 ,
V_1 -> V_17 . V_19 ) ;
F_22 ( V_1 ) ;
F_10 ( & V_1 -> V_37 ) ;
break;
}
F_10 ( & V_1 -> V_37 ) ;
V_1 = NULL ;
}
F_10 ( & V_9 -> V_35 ) ;
return V_1 ;
}
int F_23 ( struct V_1 * V_1 ,
struct V_9 * V_9 ,
T_1 V_30 )
{
int V_10 ;
struct V_1 * V_38 ;
struct V_39 * V_40 = V_1 -> V_6 ;
F_24 ( V_1 -> V_17 . V_18 , V_1 -> V_17 . V_19 ,
( unsigned long long ) V_30 , V_40 ) ;
if ( ! V_9 )
return 0 ;
if ( ! V_1 -> V_4 && V_1 -> V_6 ) {
V_1 -> V_6 = V_40 = NULL ;
}
if ( V_40 ) {
F_25 ( V_40 -> V_41 != V_30 ,
L_1 ,
V_1 -> V_17 . V_18 , V_1 -> V_17 . V_19 ,
( unsigned long long ) V_30 ,
( unsigned long long ) V_40 -> V_41 ) ;
return 0 ;
}
V_38 = F_18 ( V_9 , V_30 , 0 ) ;
if ( V_38 ) {
V_40 = V_38 -> V_6 ;
F_25 ( ! V_40 , L_2 ,
( unsigned long long ) V_30 ,
( unsigned long long ) F_2 ( V_9 ) -> V_27 ) ;
F_25 ( V_40 -> V_41 != V_30 ,
L_1 ,
V_1 -> V_17 . V_18 , V_1 -> V_17 . V_19 ,
( unsigned long long ) V_30 ,
( unsigned long long ) V_40 -> V_41 ) ;
F_26 ( V_40 -> V_42 . V_43 ,
( unsigned long long ) V_30 ,
( unsigned long long ) F_2 ( V_9 ) -> V_27 ) ;
goto V_44;
}
V_40 = F_27 ( sizeof( * V_40 ) , V_45 ) ;
if ( ! V_40 ) {
V_10 = - V_46 ;
F_28 ( V_10 ) ;
return V_10 ;
}
V_40 -> V_47 = 0 ;
V_40 -> V_48 = F_29 ( V_9 ) ;
V_40 -> V_41 = V_30 ;
F_30 ( V_40 , V_30 , V_9 ) ;
V_44:
F_9 ( & V_49 ) ;
V_1 -> V_6 = V_40 ;
V_40 -> V_47 ++ ;
F_10 ( & V_49 ) ;
V_10 = V_39 ( V_1 , 0 ) ;
if ( ! V_10 )
F_31 ( V_1 , 0 ) ;
else
F_28 ( V_10 ) ;
if ( V_10 < 0 && ! V_38 ) {
F_32 ( & V_40 -> V_42 ) ;
F_3 ( V_40 -> V_47 != 1 ) ;
F_9 ( & V_49 ) ;
V_1 -> V_6 = NULL ;
F_10 ( & V_49 ) ;
F_33 ( V_40 ) ;
F_34 ( V_9 ) ;
}
F_35 ( V_38 ) ;
return V_10 ;
}
static void F_36 ( struct V_11 * V_12 , int V_50 )
{
struct V_39 * V_40 ;
F_9 ( & V_51 ) ;
while ( V_12 -> V_52 && ( V_50 < 0 || V_50 -- ) ) {
V_40 = V_12 -> V_52 ;
V_12 -> V_52 = V_40 -> V_53 ;
F_10 ( & V_51 ) ;
F_34 ( V_40 -> V_48 ) ;
F_33 ( V_40 ) ;
F_9 ( & V_51 ) ;
}
F_10 ( & V_51 ) ;
}
void F_37 ( struct V_54 * V_55 )
{
struct V_11 * V_12 = F_38 ( V_55 , struct V_11 ,
V_56 ) ;
F_36 ( V_12 , V_57 ) ;
F_9 ( & V_51 ) ;
if ( V_12 -> V_52 &&
! F_39 ( V_12 , V_58 ) )
F_40 ( V_59 , & V_12 -> V_56 ) ;
F_10 ( & V_51 ) ;
}
void F_41 ( struct V_11 * V_12 )
{
F_36 ( V_12 , - 1 ) ;
}
static void F_42 ( struct V_11 * V_12 ,
struct V_39 * V_40 )
{
F_43 ( V_12 , & V_40 -> V_42 ) ;
F_32 ( & V_40 -> V_42 ) ;
F_9 ( & V_51 ) ;
if ( ! V_12 -> V_52 &&
! F_39 ( V_12 , V_58 ) )
F_40 ( V_59 , & V_12 -> V_56 ) ;
V_40 -> V_53 = V_12 -> V_52 ;
V_12 -> V_52 = V_40 ;
F_10 ( & V_51 ) ;
}
void F_44 ( struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_60 ;
F_3 ( V_40 -> V_47 == 0 ) ;
F_9 ( & V_49 ) ;
V_40 -> V_47 -- ;
V_60 = ! V_40 -> V_47 ;
F_10 ( & V_49 ) ;
if ( V_60 )
F_42 ( V_12 , V_40 ) ;
}
static void F_45 ( struct V_1 * V_1 , struct V_9 * V_9 )
{
struct V_39 * V_40 = V_1 -> V_6 ;
if ( ! V_40 ) {
if ( ! ( V_1 -> V_61 & V_62 ) &&
! F_17 ( V_1 ) ) {
unsigned long long V_63 = 0ULL ;
if ( V_9 )
V_63 = ( unsigned long long ) F_2 ( V_9 ) -> V_27 ;
F_46 ( V_64 , L_3
L_4 ,
V_63 , V_1 -> V_61 , V_1 -> V_17 . V_18 ,
V_1 -> V_17 . V_19 ) ;
}
goto V_65;
}
F_25 ( V_40 -> V_47 == 0 , L_5 ,
V_1 -> V_17 . V_18 , V_1 -> V_17 . V_19 ,
V_40 -> V_47 ) ;
F_44 ( F_5 ( V_1 -> V_16 ) , V_40 ) ;
V_65:
F_34 ( V_9 ) ;
}
void F_47 ( struct V_1 * V_1 , struct V_1 * V_66 ,
struct V_9 * V_67 , struct V_9 * V_68 )
{
int V_10 ;
struct V_11 * V_12 = F_5 ( V_67 -> V_69 ) ;
struct V_9 * V_9 = V_1 -> V_4 ;
if ( V_67 == V_68 )
goto V_70;
F_44 ( V_12 , V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
V_10 = F_23 ( V_1 , V_9 , F_2 ( V_68 ) -> V_27 ) ;
if ( V_10 )
F_28 ( V_10 ) ;
V_70:
F_48 ( V_1 , V_66 ) ;
}
