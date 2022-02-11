void F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 =
F_2 ( V_1 -> V_3 -> V_4 ) -> V_5 ;
F_3 ( V_1 -> V_4 ) ;
V_1 -> V_6 = ( void * ) V_2 ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_7 )
{
struct V_8 * V_8 ;
int V_9 = 0 ;
struct V_10 * V_11 ;
if ( V_7 & V_12 )
return - V_13 ;
V_8 = V_1 -> V_4 ;
V_11 = F_5 ( V_1 -> V_14 ) ;
F_6 ( V_1 , V_1 -> V_15 . V_16 ,
V_1 -> V_15 . V_17 ) ;
if ( V_8 == NULL ) {
unsigned long V_2 = ( unsigned long ) V_1 -> V_6 ;
unsigned long V_18 =
F_2 ( V_1 -> V_3 -> V_4 ) -> V_5 ;
F_7 ( V_1 -> V_15 . V_16 ,
V_1 -> V_15 . V_17 ,
V_18 , V_2 ) ;
if ( V_2 != V_18 )
goto V_19;
goto V_20;
}
F_3 ( ! V_11 ) ;
if ( V_8 == V_11 -> V_21 || F_8 ( V_8 ) )
goto V_19;
F_9 ( & F_2 ( V_8 ) -> V_22 ) ;
if ( F_2 ( V_8 ) -> V_23 & V_24 ) {
F_10 ( & F_2 ( V_8 ) -> V_22 ) ;
F_11 (
( unsigned long long ) F_2 ( V_8 ) -> V_25 ) ;
goto V_19;
}
F_10 ( & F_2 ( V_8 ) -> V_22 ) ;
if ( V_8 -> V_26 == 0 ) {
F_12 (
( unsigned long long ) F_2 ( V_8 ) -> V_25 ,
F_13 ( V_8 -> V_27 ) ) ;
goto V_19;
}
if ( ! V_1 -> V_6 ) {
F_14 (
( unsigned long long ) F_2 ( V_8 ) -> V_25 ) ;
goto V_19;
}
V_20:
V_9 = 1 ;
V_19:
F_15 ( V_9 ) ;
return V_9 ;
}
static int F_16 ( struct V_1 * V_1 ,
T_1 V_28 ,
int V_29 )
{
struct V_8 * V_30 ;
if ( ! V_1 -> V_6 )
return 0 ;
if ( ! V_1 -> V_3 )
return 0 ;
if ( V_29 && F_17 ( V_1 ) )
return 0 ;
V_30 = V_1 -> V_3 -> V_4 ;
if ( ! V_30 )
return 0 ;
if ( F_2 ( V_30 ) -> V_25 != V_28 )
return 0 ;
return 1 ;
}
struct V_1 * F_18 ( struct V_8 * V_8 ,
T_1 V_28 ,
int V_29 )
{
struct V_1 * V_1 ;
F_9 ( & V_8 -> V_31 ) ;
F_19 (dentry, &inode->i_dentry, d_alias) {
F_9 ( & V_1 -> V_32 ) ;
if ( F_16 ( V_1 , V_28 , V_29 ) ) {
F_20 ( V_1 -> V_15 . V_16 ,
V_1 -> V_15 . V_17 ) ;
F_21 ( V_1 ) ;
F_10 ( & V_1 -> V_32 ) ;
F_10 ( & V_8 -> V_31 ) ;
return V_1 ;
}
F_10 ( & V_1 -> V_32 ) ;
}
F_10 ( & V_8 -> V_31 ) ;
return NULL ;
}
int F_22 ( struct V_1 * V_1 ,
struct V_8 * V_8 ,
T_1 V_28 )
{
int V_9 ;
struct V_1 * V_33 ;
struct V_34 * V_35 = V_1 -> V_6 ;
F_23 ( V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
( unsigned long long ) V_28 , V_35 ) ;
if ( ! V_8 )
return 0 ;
if ( ! V_1 -> V_4 && V_1 -> V_6 ) {
V_1 -> V_6 = V_35 = NULL ;
}
if ( V_35 ) {
F_24 ( V_35 -> V_36 != V_28 ,
L_1 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
( unsigned long long ) V_28 ,
( unsigned long long ) V_35 -> V_36 ) ;
return 0 ;
}
V_33 = F_18 ( V_8 , V_28 , 0 ) ;
if ( V_33 ) {
V_35 = V_33 -> V_6 ;
F_24 ( ! V_35 , L_2 ,
( unsigned long long ) V_28 ,
( unsigned long long ) F_2 ( V_8 ) -> V_25 ) ;
F_24 ( V_35 -> V_36 != V_28 ,
L_1 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
( unsigned long long ) V_28 ,
( unsigned long long ) V_35 -> V_36 ) ;
F_25 ( V_35 -> V_37 . V_38 ,
( unsigned long long ) V_28 ,
( unsigned long long ) F_2 ( V_8 ) -> V_25 ) ;
goto V_39;
}
V_35 = F_26 ( sizeof( * V_35 ) , V_40 ) ;
if ( ! V_35 ) {
V_9 = - V_41 ;
F_27 ( V_9 ) ;
return V_9 ;
}
V_35 -> V_42 = 0 ;
V_35 -> V_43 = F_28 ( V_8 ) ;
V_35 -> V_36 = V_28 ;
F_29 ( V_35 , V_28 , V_8 ) ;
V_39:
F_9 ( & V_44 ) ;
V_1 -> V_6 = V_35 ;
V_35 -> V_42 ++ ;
F_10 ( & V_44 ) ;
V_9 = V_34 ( V_1 , 0 ) ;
if ( ! V_9 )
F_30 ( V_1 , 0 ) ;
else
F_27 ( V_9 ) ;
if ( V_9 < 0 && ! V_33 ) {
F_31 ( & V_35 -> V_37 ) ;
F_3 ( V_35 -> V_42 != 1 ) ;
F_9 ( & V_44 ) ;
V_1 -> V_6 = NULL ;
F_10 ( & V_44 ) ;
F_32 ( V_35 ) ;
F_33 ( V_8 ) ;
}
F_34 ( V_33 ) ;
return V_9 ;
}
static void F_35 ( struct V_10 * V_11 , int V_45 )
{
struct V_34 * V_35 ;
F_9 ( & V_46 ) ;
while ( V_11 -> V_47 && ( V_45 < 0 || V_45 -- ) ) {
V_35 = V_11 -> V_47 ;
V_11 -> V_47 = V_35 -> V_48 ;
F_10 ( & V_46 ) ;
F_33 ( V_35 -> V_43 ) ;
F_32 ( V_35 ) ;
F_9 ( & V_46 ) ;
}
F_10 ( & V_46 ) ;
}
void F_36 ( struct V_49 * V_50 )
{
struct V_10 * V_11 = F_37 ( V_50 , struct V_10 ,
V_51 ) ;
F_35 ( V_11 , V_52 ) ;
F_9 ( & V_46 ) ;
if ( V_11 -> V_47 &&
! F_38 ( V_11 , V_53 ) )
F_39 ( V_54 , & V_11 -> V_51 ) ;
F_10 ( & V_46 ) ;
}
void F_40 ( struct V_10 * V_11 )
{
F_35 ( V_11 , - 1 ) ;
}
static void F_41 ( struct V_10 * V_11 ,
struct V_34 * V_35 )
{
F_42 ( V_11 , & V_35 -> V_37 ) ;
F_31 ( & V_35 -> V_37 ) ;
F_9 ( & V_46 ) ;
if ( ! V_11 -> V_47 &&
! F_38 ( V_11 , V_53 ) )
F_39 ( V_54 , & V_11 -> V_51 ) ;
V_35 -> V_48 = V_11 -> V_47 ;
V_11 -> V_47 = V_35 ;
F_10 ( & V_46 ) ;
}
void F_43 ( struct V_10 * V_11 ,
struct V_34 * V_35 )
{
int V_55 ;
F_3 ( V_35 -> V_42 == 0 ) ;
F_9 ( & V_44 ) ;
V_35 -> V_42 -- ;
V_55 = ! V_35 -> V_42 ;
F_10 ( & V_44 ) ;
if ( V_55 )
F_41 ( V_11 , V_35 ) ;
}
static void F_44 ( struct V_1 * V_1 , struct V_8 * V_8 )
{
struct V_34 * V_35 = V_1 -> V_6 ;
if ( ! V_35 ) {
if ( ! ( V_1 -> V_56 & V_57 ) &&
! F_17 ( V_1 ) ) {
unsigned long long V_58 = 0ULL ;
if ( V_8 )
V_58 = ( unsigned long long ) F_2 ( V_8 ) -> V_25 ;
F_45 ( V_59 , L_3
L_4 ,
V_58 , V_1 -> V_56 , V_1 -> V_15 . V_16 ,
V_1 -> V_15 . V_17 ) ;
}
goto V_60;
}
F_24 ( V_35 -> V_42 == 0 , L_5 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
V_35 -> V_42 ) ;
F_43 ( F_5 ( V_1 -> V_14 ) , V_35 ) ;
V_60:
F_33 ( V_8 ) ;
}
void F_46 ( struct V_1 * V_1 , struct V_1 * V_61 ,
struct V_8 * V_62 , struct V_8 * V_63 )
{
int V_9 ;
struct V_10 * V_11 = F_5 ( V_62 -> V_64 ) ;
struct V_8 * V_8 = V_1 -> V_4 ;
if ( V_62 == V_63 )
goto V_65;
F_43 ( V_11 , V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
V_9 = F_22 ( V_1 , V_8 , F_2 ( V_63 ) -> V_25 ) ;
if ( V_9 )
F_27 ( V_9 ) ;
V_65:
F_47 ( V_1 , V_61 ) ;
}
