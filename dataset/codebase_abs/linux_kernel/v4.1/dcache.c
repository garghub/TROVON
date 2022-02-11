void F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 =
F_2 ( F_3 ( V_1 -> V_3 ) ) -> V_4 ;
F_4 ( F_3 ( V_1 ) ) ;
V_1 -> V_5 = ( void * ) V_2 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned int V_6 )
{
struct V_7 * V_7 ;
int V_8 = 0 ;
struct V_9 * V_10 ;
if ( V_6 & V_11 )
return - V_12 ;
V_7 = F_3 ( V_1 ) ;
V_10 = F_6 ( V_1 -> V_13 ) ;
F_7 ( V_1 , V_1 -> V_14 . V_15 ,
V_1 -> V_14 . V_16 ) ;
if ( V_7 == NULL ) {
unsigned long V_2 = ( unsigned long ) V_1 -> V_5 ;
unsigned long V_17 ;
F_8 ( & V_1 -> V_18 ) ;
V_17 = F_2 ( F_3 ( V_1 -> V_3 ) ) -> V_4 ;
F_9 ( & V_1 -> V_18 ) ;
F_10 ( V_1 -> V_14 . V_15 ,
V_1 -> V_14 . V_16 ,
V_17 , V_2 ) ;
if ( V_2 != V_17 )
goto V_19;
goto V_20;
}
F_4 ( ! V_10 ) ;
if ( V_7 == V_10 -> V_21 || F_11 ( V_7 ) )
goto V_19;
F_8 ( & F_2 ( V_7 ) -> V_22 ) ;
if ( F_2 ( V_7 ) -> V_23 & V_24 ) {
F_9 ( & F_2 ( V_7 ) -> V_22 ) ;
F_12 (
( unsigned long long ) F_2 ( V_7 ) -> V_25 ) ;
goto V_19;
}
F_9 ( & F_2 ( V_7 ) -> V_22 ) ;
if ( V_7 -> V_26 == 0 ) {
F_13 (
( unsigned long long ) F_2 ( V_7 ) -> V_25 ,
F_14 ( V_7 -> V_27 ) ) ;
goto V_19;
}
if ( ! V_1 -> V_5 ) {
F_15 (
( unsigned long long ) F_2 ( V_7 ) -> V_25 ) ;
goto V_19;
}
V_20:
V_8 = 1 ;
V_19:
F_16 ( V_8 ) ;
return V_8 ;
}
static int F_17 ( struct V_1 * V_1 ,
T_1 V_28 ,
int V_29 )
{
struct V_7 * V_30 ;
if ( ! V_1 -> V_5 )
return 0 ;
if ( ! V_1 -> V_3 )
return 0 ;
if ( V_29 && F_18 ( V_1 ) )
return 0 ;
V_30 = F_3 ( V_1 -> V_3 ) ;
if ( ! V_30 )
return 0 ;
if ( F_2 ( V_30 ) -> V_25 != V_28 )
return 0 ;
return 1 ;
}
struct V_1 * F_19 ( struct V_7 * V_7 ,
T_1 V_28 ,
int V_29 )
{
struct V_1 * V_1 ;
F_8 ( & V_7 -> V_31 ) ;
F_20 (dentry, &inode->i_dentry, d_u.d_alias) {
F_8 ( & V_1 -> V_18 ) ;
if ( F_17 ( V_1 , V_28 , V_29 ) ) {
F_21 ( V_1 -> V_14 . V_15 ,
V_1 -> V_14 . V_16 ) ;
F_22 ( V_1 ) ;
F_9 ( & V_1 -> V_18 ) ;
F_9 ( & V_7 -> V_31 ) ;
return V_1 ;
}
F_9 ( & V_1 -> V_18 ) ;
}
F_9 ( & V_7 -> V_31 ) ;
return NULL ;
}
int F_23 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
T_1 V_28 )
{
int V_8 ;
struct V_1 * V_32 ;
struct V_33 * V_34 = V_1 -> V_5 ;
F_24 ( V_1 -> V_14 . V_15 , V_1 -> V_14 . V_16 ,
( unsigned long long ) V_28 , V_34 ) ;
if ( ! V_7 )
return 0 ;
if ( F_25 ( V_1 ) && V_1 -> V_5 ) {
V_1 -> V_5 = V_34 = NULL ;
}
if ( V_34 ) {
F_26 ( V_34 -> V_35 != V_28 ,
L_1 ,
V_1 ,
( unsigned long long ) V_28 ,
( unsigned long long ) V_34 -> V_35 ) ;
return 0 ;
}
V_32 = F_19 ( V_7 , V_28 , 0 ) ;
if ( V_32 ) {
V_34 = V_32 -> V_5 ;
F_26 ( ! V_34 , L_2 ,
( unsigned long long ) V_28 ,
( unsigned long long ) F_2 ( V_7 ) -> V_25 ) ;
F_26 ( V_34 -> V_35 != V_28 ,
L_1 ,
V_1 ,
( unsigned long long ) V_28 ,
( unsigned long long ) V_34 -> V_35 ) ;
F_27 ( V_34 -> V_36 . V_37 ,
( unsigned long long ) V_28 ,
( unsigned long long ) F_2 ( V_7 ) -> V_25 ) ;
goto V_38;
}
V_34 = F_28 ( sizeof( * V_34 ) , V_39 ) ;
if ( ! V_34 ) {
V_8 = - V_40 ;
F_29 ( V_8 ) ;
return V_8 ;
}
V_34 -> V_41 = 0 ;
V_34 -> V_42 = F_30 ( V_7 ) ;
V_34 -> V_35 = V_28 ;
F_31 ( V_34 , V_28 , V_7 ) ;
V_38:
F_8 ( & V_43 ) ;
V_1 -> V_5 = V_34 ;
V_34 -> V_41 ++ ;
F_9 ( & V_43 ) ;
V_8 = V_33 ( V_1 , 0 ) ;
if ( ! V_8 )
F_32 ( V_1 , 0 ) ;
else
F_29 ( V_8 ) ;
if ( V_8 < 0 && ! V_32 ) {
F_33 ( & V_34 -> V_36 ) ;
F_4 ( V_34 -> V_41 != 1 ) ;
F_8 ( & V_43 ) ;
V_1 -> V_5 = NULL ;
F_9 ( & V_43 ) ;
F_34 ( V_34 ) ;
F_35 ( V_7 ) ;
}
F_36 ( V_32 ) ;
return V_8 ;
}
static void F_37 ( struct V_9 * V_10 ,
struct V_33 * V_34 )
{
F_35 ( V_34 -> V_42 ) ;
F_38 ( V_10 , & V_34 -> V_36 ) ;
F_33 ( & V_34 -> V_36 ) ;
F_34 ( V_34 ) ;
}
void F_39 ( struct V_9 * V_10 ,
struct V_33 * V_34 )
{
int V_44 = 0 ;
F_4 ( V_34 -> V_41 == 0 ) ;
F_8 ( & V_43 ) ;
V_34 -> V_41 -- ;
V_44 = ! V_34 -> V_41 ;
F_9 ( & V_43 ) ;
if ( V_44 )
F_37 ( V_10 , V_34 ) ;
}
static void F_40 ( struct V_1 * V_1 , struct V_7 * V_7 )
{
struct V_33 * V_34 = V_1 -> V_5 ;
if ( ! V_34 ) {
if ( ! ( V_1 -> V_45 & V_46 ) &&
! F_18 ( V_1 ) ) {
unsigned long long V_47 = 0ULL ;
if ( V_7 )
V_47 = ( unsigned long long ) F_2 ( V_7 ) -> V_25 ;
F_41 ( V_48 , L_3
L_4 ,
V_47 , V_1 -> V_45 , V_1 ) ;
}
goto V_49;
}
F_26 ( V_34 -> V_41 == 0 , L_5 ,
V_1 , V_34 -> V_41 ) ;
F_39 ( F_6 ( V_1 -> V_13 ) , V_34 ) ;
V_49:
F_35 ( V_7 ) ;
}
void F_42 ( struct V_1 * V_1 , struct V_1 * V_50 ,
struct V_7 * V_51 , struct V_7 * V_52 )
{
int V_8 ;
struct V_9 * V_10 = F_6 ( V_51 -> V_53 ) ;
struct V_7 * V_7 = F_3 ( V_1 ) ;
if ( V_51 == V_52 )
goto V_54;
F_39 ( V_10 , V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
V_8 = F_23 ( V_1 , V_7 , F_2 ( V_52 ) -> V_25 ) ;
if ( V_8 )
F_29 ( V_8 ) ;
V_54:
F_43 ( V_1 , V_50 ) ;
}
