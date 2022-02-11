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
unsigned long V_18 ;
F_7 ( & V_1 -> V_19 ) ;
V_18 = F_2 ( V_1 -> V_3 -> V_4 ) -> V_5 ;
F_8 ( & V_1 -> V_19 ) ;
F_9 ( V_1 -> V_15 . V_16 ,
V_1 -> V_15 . V_17 ,
V_18 , V_2 ) ;
if ( V_2 != V_18 )
goto V_20;
goto V_21;
}
F_3 ( ! V_11 ) ;
if ( V_8 == V_11 -> V_22 || F_10 ( V_8 ) )
goto V_20;
F_7 ( & F_2 ( V_8 ) -> V_23 ) ;
if ( F_2 ( V_8 ) -> V_24 & V_25 ) {
F_8 ( & F_2 ( V_8 ) -> V_23 ) ;
F_11 (
( unsigned long long ) F_2 ( V_8 ) -> V_26 ) ;
goto V_20;
}
F_8 ( & F_2 ( V_8 ) -> V_23 ) ;
if ( V_8 -> V_27 == 0 ) {
F_12 (
( unsigned long long ) F_2 ( V_8 ) -> V_26 ,
F_13 ( V_8 -> V_28 ) ) ;
goto V_20;
}
if ( ! V_1 -> V_6 ) {
F_14 (
( unsigned long long ) F_2 ( V_8 ) -> V_26 ) ;
goto V_20;
}
V_21:
V_9 = 1 ;
V_20:
F_15 ( V_9 ) ;
return V_9 ;
}
static int F_16 ( struct V_1 * V_1 ,
T_1 V_29 ,
int V_30 )
{
struct V_8 * V_31 ;
if ( ! V_1 -> V_6 )
return 0 ;
if ( ! V_1 -> V_3 )
return 0 ;
if ( V_30 && F_17 ( V_1 ) )
return 0 ;
V_31 = V_1 -> V_3 -> V_4 ;
if ( ! V_31 )
return 0 ;
if ( F_2 ( V_31 ) -> V_26 != V_29 )
return 0 ;
return 1 ;
}
struct V_1 * F_18 ( struct V_8 * V_8 ,
T_1 V_29 ,
int V_30 )
{
struct V_1 * V_1 ;
F_7 ( & V_8 -> V_32 ) ;
F_19 (dentry, &inode->i_dentry, d_alias) {
F_7 ( & V_1 -> V_19 ) ;
if ( F_16 ( V_1 , V_29 , V_30 ) ) {
F_20 ( V_1 -> V_15 . V_16 ,
V_1 -> V_15 . V_17 ) ;
F_21 ( V_1 ) ;
F_8 ( & V_1 -> V_19 ) ;
F_8 ( & V_8 -> V_32 ) ;
return V_1 ;
}
F_8 ( & V_1 -> V_19 ) ;
}
F_8 ( & V_8 -> V_32 ) ;
return NULL ;
}
int F_22 ( struct V_1 * V_1 ,
struct V_8 * V_8 ,
T_1 V_29 )
{
int V_9 ;
struct V_1 * V_33 ;
struct V_34 * V_35 = V_1 -> V_6 ;
F_23 ( V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
( unsigned long long ) V_29 , V_35 ) ;
if ( ! V_8 )
return 0 ;
if ( ! V_1 -> V_4 && V_1 -> V_6 ) {
V_1 -> V_6 = V_35 = NULL ;
}
if ( V_35 ) {
F_24 ( V_35 -> V_36 != V_29 ,
L_1 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
( unsigned long long ) V_29 ,
( unsigned long long ) V_35 -> V_36 ) ;
return 0 ;
}
V_33 = F_18 ( V_8 , V_29 , 0 ) ;
if ( V_33 ) {
V_35 = V_33 -> V_6 ;
F_24 ( ! V_35 , L_2 ,
( unsigned long long ) V_29 ,
( unsigned long long ) F_2 ( V_8 ) -> V_26 ) ;
F_24 ( V_35 -> V_36 != V_29 ,
L_1 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
( unsigned long long ) V_29 ,
( unsigned long long ) V_35 -> V_36 ) ;
F_25 ( V_35 -> V_37 . V_38 ,
( unsigned long long ) V_29 ,
( unsigned long long ) F_2 ( V_8 ) -> V_26 ) ;
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
V_35 -> V_36 = V_29 ;
F_29 ( V_35 , V_29 , V_8 ) ;
V_39:
F_7 ( & V_44 ) ;
V_1 -> V_6 = V_35 ;
V_35 -> V_42 ++ ;
F_8 ( & V_44 ) ;
V_9 = V_34 ( V_1 , 0 ) ;
if ( ! V_9 )
F_30 ( V_1 , 0 ) ;
else
F_27 ( V_9 ) ;
if ( V_9 < 0 && ! V_33 ) {
F_31 ( & V_35 -> V_37 ) ;
F_3 ( V_35 -> V_42 != 1 ) ;
F_7 ( & V_44 ) ;
V_1 -> V_6 = NULL ;
F_8 ( & V_44 ) ;
F_32 ( V_35 ) ;
F_33 ( V_8 ) ;
}
F_34 ( V_33 ) ;
return V_9 ;
}
static void F_35 ( struct V_10 * V_11 ,
struct V_34 * V_35 )
{
F_33 ( V_35 -> V_43 ) ;
F_36 ( V_11 , & V_35 -> V_37 ) ;
F_31 ( & V_35 -> V_37 ) ;
F_32 ( V_35 ) ;
}
void F_37 ( struct V_10 * V_11 ,
struct V_34 * V_35 )
{
int V_45 = 0 ;
F_3 ( V_35 -> V_42 == 0 ) ;
F_7 ( & V_44 ) ;
V_35 -> V_42 -- ;
V_45 = ! V_35 -> V_42 ;
F_8 ( & V_44 ) ;
if ( V_45 )
F_35 ( V_11 , V_35 ) ;
}
static void F_38 ( struct V_1 * V_1 , struct V_8 * V_8 )
{
struct V_34 * V_35 = V_1 -> V_6 ;
if ( ! V_35 ) {
if ( ! ( V_1 -> V_46 & V_47 ) &&
! F_17 ( V_1 ) ) {
unsigned long long V_48 = 0ULL ;
if ( V_8 )
V_48 = ( unsigned long long ) F_2 ( V_8 ) -> V_26 ;
F_39 ( V_49 , L_3
L_4 ,
V_48 , V_1 -> V_46 , V_1 -> V_15 . V_16 ,
V_1 -> V_15 . V_17 ) ;
}
goto V_50;
}
F_24 ( V_35 -> V_42 == 0 , L_5 ,
V_1 -> V_15 . V_16 , V_1 -> V_15 . V_17 ,
V_35 -> V_42 ) ;
F_37 ( F_5 ( V_1 -> V_14 ) , V_35 ) ;
V_50:
F_33 ( V_8 ) ;
}
void F_40 ( struct V_1 * V_1 , struct V_1 * V_51 ,
struct V_8 * V_52 , struct V_8 * V_53 )
{
int V_9 ;
struct V_10 * V_11 = F_5 ( V_52 -> V_54 ) ;
struct V_8 * V_8 = V_1 -> V_4 ;
if ( V_52 == V_53 )
goto V_55;
F_37 ( V_11 , V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
V_9 = F_22 ( V_1 , V_8 , F_2 ( V_53 ) -> V_26 ) ;
if ( V_9 )
F_27 ( V_9 ) ;
V_55:
F_41 ( V_1 , V_51 ) ;
}
