static inline int
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 ) {
F_3 ( & V_2 -> V_3 ) ;
return 0 ;
}
if ( ! F_4 ( & V_2 -> V_5 ) ) {
F_3 ( & V_2 -> V_3 ) ;
return 0 ;
}
F_3 ( & V_2 -> V_3 ) ;
return 1 ;
}
void
F_5 ( struct V_1 * V_2 , T_1 * V_6 )
{
F_6 ( ! F_7 () ) ;
F_6 ( ! V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_3 ) ;
F_6 ( V_6 -> V_7 ) ;
if ( V_6 -> V_8 ) {
F_6 ( ! F_4 ( & V_6 -> V_9 ) ) ;
F_8 ( & V_6 -> V_9 ) ;
F_6 ( V_2 -> V_10 > 0 ) ;
V_2 -> V_10 -- ;
}
F_6 ( F_4 ( & V_6 -> V_9 ) ) ;
V_6 -> V_8 = 1 ;
F_3 ( & V_2 -> V_3 ) ;
}
int
F_9 ( struct V_1 * V_2 , T_1 * V_6 )
{
int V_11 ;
F_6 ( ! F_7 () ) ;
F_6 ( ! V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_3 ) ;
V_11 = ! ( V_6 -> V_7 ) ;
if ( V_6 -> V_8 ) {
F_6 ( ! F_4 ( & V_6 -> V_9 ) ) ;
F_8 ( & V_6 -> V_9 ) ;
F_6 ( V_2 -> V_10 > 0 ) ;
V_2 -> V_10 -- ;
V_6 -> V_8 = 0 ;
}
F_6 ( F_4 ( & V_6 -> V_9 ) ) ;
F_3 ( & V_2 -> V_3 ) ;
return V_11 ;
}
void
F_10 ( struct V_1 * V_2 , T_1 * V_6 )
{
F_6 ( ! F_7 () ) ;
F_6 ( ! V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_6 -> V_8 ) {
F_6 ( F_4 ( & V_6 -> V_9 ) ) ;
V_6 -> V_8 = 1 ;
V_2 -> V_10 ++ ;
if ( ! V_6 -> V_7 ) {
F_11 ( & V_6 -> V_9 , & V_2 -> V_5 ) ;
F_12 ( & V_2 -> V_12 ) ;
} else {
F_13 ( & V_6 -> V_9 , & V_2 -> V_13 ) ;
}
}
F_6 ( ! F_4 ( & V_6 -> V_9 ) ) ;
F_3 ( & V_2 -> V_3 ) ;
}
static int F_14 ( void * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_15 () ;
if ( V_2 -> V_15 )
if ( F_16 ( V_2 -> V_15 , V_2 -> V_16 ) != 0 )
F_17 ( L_1 ,
V_2 -> V_17 , V_2 -> V_16 ) ;
F_2 ( & V_18 . V_19 ) ;
F_6 ( V_2 -> V_20 == 1 ) ;
V_2 -> V_20 -- ;
V_2 -> V_21 ++ ;
F_3 ( & V_18 . V_19 ) ;
F_2 ( & V_2 -> V_3 ) ;
while ( ! V_2 -> V_4 ) {
int V_22 = 0 ;
int V_11 ;
T_1 * V_6 ;
while ( ! F_4 ( & V_2 -> V_5 ) &&
V_22 < V_23 ) {
V_6 = F_18 ( V_2 -> V_5 . V_24 , T_1 ,
V_9 ) ;
F_6 ( V_6 -> V_8 && ! V_6 -> V_7 ) ;
F_8 ( & V_6 -> V_9 ) ;
F_6 ( V_2 -> V_10 > 0 ) ;
V_2 -> V_10 -- ;
V_6 -> V_7 = 1 ;
V_6 -> V_8 = 0 ;
F_3 ( & V_2 -> V_3 ) ;
V_22 ++ ;
V_11 = (* V_6 -> V_25 ) ( V_6 ) ;
F_2 ( & V_2 -> V_3 ) ;
if ( V_11 != 0 )
continue;
V_6 -> V_7 = 0 ;
if ( F_4 ( & V_6 -> V_9 ) )
continue;
F_6 ( V_6 -> V_8 ) ;
F_19 ( & V_6 -> V_9 , & V_2 -> V_5 ) ;
}
if ( ! F_4 ( & V_2 -> V_5 ) ) {
F_3 ( & V_2 -> V_3 ) ;
F_20 () ;
F_2 ( & V_2 -> V_3 ) ;
continue;
}
F_3 ( & V_2 -> V_3 ) ;
V_11 = F_21 ( V_2 -> V_12 ,
! F_1 ( V_2 ) ) ;
F_2 ( & V_2 -> V_3 ) ;
}
F_3 ( & V_2 -> V_3 ) ;
F_2 ( & V_18 . V_19 ) ;
V_2 -> V_21 -- ;
F_3 ( & V_18 . V_19 ) ;
return 0 ;
}
void
F_22 ( struct V_1 * V_2 )
{
int V_26 ;
F_6 ( V_18 . V_27 ) ;
F_6 ( ! V_18 . V_28 ) ;
F_2 ( & V_18 . V_19 ) ;
if ( V_2 -> V_4 ) {
F_23 ( V_29 , L_2 ,
V_2 -> V_17 ) ;
F_3 ( & V_18 . V_19 ) ;
return;
}
F_6 ( ! F_4 ( & V_2 -> V_30 ) ) ;
V_2 -> V_4 = 1 ;
F_3 ( & V_18 . V_19 ) ;
V_26 = 2 ;
F_24 ( & V_2 -> V_12 ) ;
F_2 ( & V_18 . V_19 ) ;
while ( V_2 -> V_21 > 0 ) {
F_23 ( F_25 ( ++ V_26 ) ? V_31 : V_32 ,
L_3 ,
V_2 -> V_21 , V_2 -> V_17 ) ;
F_3 ( & V_18 . V_19 ) ;
F_26 ( V_33 ) ;
F_27 ( F_28 ( 1 ) / 20 ) ;
F_2 ( & V_18 . V_19 ) ;
}
F_29 ( & V_2 -> V_30 ) ;
F_3 ( & V_18 . V_19 ) ;
F_6 ( V_2 -> V_10 == 0 ) ;
F_30 ( V_2 , sizeof( * V_2 ) ) ;
}
int
F_31 ( char * V_34 , struct V_35 * V_36 ,
int V_37 , int V_38 , struct V_1 * * V_39 )
{
struct V_1 * V_2 ;
int V_11 ;
F_6 ( V_18 . V_27 ) ;
F_6 ( ! V_18 . V_28 ) ;
F_6 ( ! V_36 || V_37 == V_40 ||
( V_37 >= 0 && V_37 < F_32 ( V_36 ) ) ) ;
F_33 ( V_2 , sizeof( * V_2 ) ) ;
if ( ! V_2 )
return - V_41 ;
if ( strlen ( V_34 ) > sizeof( V_2 -> V_17 ) - 1 ) {
F_30 ( V_2 , sizeof( * V_2 ) ) ;
return - V_42 ;
}
strncpy ( V_2 -> V_17 , V_34 , sizeof( V_2 -> V_17 ) ) ;
V_2 -> V_15 = V_36 ;
V_2 -> V_16 = V_37 ;
F_34 ( & V_2 -> V_3 ) ;
F_35 ( & V_2 -> V_12 ) ;
F_36 ( & V_2 -> V_5 ) ;
F_36 ( & V_2 -> V_13 ) ;
F_36 ( & V_2 -> V_30 ) ;
V_11 = 0 ;
while ( V_38 > 0 ) {
char V_34 [ 16 ] ;
struct V_43 * V_44 ;
F_2 ( & V_18 . V_19 ) ;
while ( V_2 -> V_20 > 0 ) {
F_3 ( & V_18 . V_19 ) ;
F_37 () ;
F_2 ( & V_18 . V_19 ) ;
}
V_2 -> V_20 ++ ;
F_3 ( & V_18 . V_19 ) ;
if ( V_2 -> V_15 && V_2 -> V_16 >= 0 ) {
snprintf ( V_34 , sizeof( V_34 ) , L_4 ,
V_2 -> V_17 , V_2 -> V_16 ,
V_2 -> V_21 ) ;
} else {
snprintf ( V_34 , sizeof( V_34 ) , L_5 ,
V_2 -> V_17 , V_2 -> V_21 ) ;
}
V_44 = F_38 ( F_14 , V_2 , L_6 , V_34 ) ;
if ( ! F_39 ( V_44 ) ) {
V_38 -- ;
continue;
}
V_11 = F_40 ( V_44 ) ;
F_41 ( L_7 ,
V_34 , V_11 ) ;
F_2 ( & V_18 . V_19 ) ;
F_13 ( & V_2 -> V_30 , & V_18 . V_45 ) ;
V_2 -> V_20 -- ;
F_3 ( & V_18 . V_19 ) ;
F_22 ( V_2 ) ;
return V_11 ;
}
F_2 ( & V_18 . V_19 ) ;
F_13 ( & V_2 -> V_30 , & V_18 . V_45 ) ;
F_3 ( & V_18 . V_19 ) ;
* V_39 = V_2 ;
return 0 ;
}
int
F_42 ( void )
{
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
F_34 ( & V_18 . V_19 ) ;
F_36 ( & V_18 . V_45 ) ;
V_18 . V_27 = 1 ;
return 0 ;
}
void
F_43 ( void )
{
struct V_1 * V_2 ;
struct V_1 * V_46 ;
F_2 ( & V_18 . V_19 ) ;
V_18 . V_28 = 1 ;
F_3 ( & V_18 . V_19 ) ;
F_44 (sched, &cfs_wi_data.wi_scheds, ws_list) {
V_2 -> V_4 = 1 ;
F_24 ( & V_2 -> V_12 ) ;
}
F_44 (sched, &cfs_wi_data.wi_scheds, ws_list) {
F_2 ( & V_18 . V_19 ) ;
while ( V_2 -> V_21 != 0 ) {
F_3 ( & V_18 . V_19 ) ;
F_26 ( V_33 ) ;
F_27 ( F_28 ( 1 ) / 20 ) ;
F_2 ( & V_18 . V_19 ) ;
}
F_3 ( & V_18 . V_19 ) ;
}
F_45 (sched, temp, &cfs_wi_data.wi_scheds, ws_list) {
F_29 ( & V_2 -> V_30 ) ;
F_30 ( V_2 , sizeof( * V_2 ) ) ;
}
V_18 . V_28 = 0 ;
V_18 . V_27 = 0 ;
}
