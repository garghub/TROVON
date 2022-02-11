static int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_2 * V_8 = V_3 ;
F_2 ( & V_2 -> V_9 ) ;
F_3 ( & V_6 -> V_10 , 0 , V_8 -> V_11 >> V_12 ) ;
V_6 -> V_13 = 1 ;
V_6 -> V_14 = V_8 -> V_15 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_1 , V_8 -> V_15 , V_8 -> V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_4 * V_16 ,
void * V_3 , int V_17 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_3 * V_18 = V_3 ;
int V_19 = 0 , V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_5 = V_16 -> V_24 ;
unsigned long V_15 ;
F_2 ( & V_2 -> V_9 ) ;
if ( 0 == ( ( V_17 == 0 ) ? V_6 -> V_13 :
V_6 -> V_25 ) ) {
F_7
( L_2 ) ;
F_4 ( & V_2 -> V_9 ) ;
return - V_26 ;
}
V_22 = F_8 ( sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 ) {
V_19 = - V_28 ;
goto V_29;
}
V_18 -> V_11 = ( V_18 -> V_11 + V_30 ) >> V_12 ;
if ( V_17 == V_31 ) {
V_19 = F_9 ( & V_6 -> V_32 ,
& V_22 -> V_33 ,
V_18 -> V_11 ) ;
V_15 = V_22 -> V_33 . V_34 ;
} else {
#if F_10 ( V_35 ) || F_10 ( V_36 )
V_22 -> V_37 . V_11 = V_18 -> V_11 ;
F_11 ( & V_22 -> V_37 ) ;
if ( V_22 -> V_37 . V_11 == 0 )
V_19 = - V_28 ;
V_15 = V_22 -> V_37 . V_15 ;
#else
V_19 = F_9 ( & V_6 -> V_10 ,
& V_22 -> V_33 ,
V_18 -> V_11 ) ;
V_15 = V_22 -> V_33 . V_34 ;
#endif
}
if ( V_19 )
goto V_29;
V_19 = F_12 ( & V_6 -> V_38 , V_22 , 1 , 0 , V_27 ) ;
if ( V_19 < 0 )
goto V_39;
V_20 = V_19 ;
F_13 ( & V_22 -> V_40 , & V_5 -> V_41 ) ;
F_4 ( & V_2 -> V_9 ) ;
V_18 -> V_15 = ( ( V_17 == 0 ) ?
V_6 -> V_14 : V_6 -> V_42 ) +
( V_15 << V_12 ) ;
V_18 -> free = V_20 ;
V_18 -> V_11 = V_18 -> V_11 << V_12 ;
return 0 ;
V_39:
F_14 ( & V_22 -> V_33 ) ;
V_29:
F_15 ( V_22 ) ;
F_4 ( & V_2 -> V_9 ) ;
V_18 -> V_15 = 0 ;
V_18 -> V_11 = 0 ;
V_18 -> free = 0 ;
F_5 ( L_3 , V_17 , V_18 -> V_11 ,
V_18 -> V_15 ) ;
return V_19 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_3 * V_18 = V_3 ;
struct V_21 * V_43 ;
F_2 ( & V_2 -> V_9 ) ;
V_43 = F_17 ( & V_6 -> V_38 , V_18 -> free ) ;
if ( V_43 == NULL ) {
F_4 ( & V_2 -> V_9 ) ;
return - V_26 ;
}
F_18 ( & V_6 -> V_38 , V_18 -> free ) ;
F_19 ( & V_43 -> V_40 ) ;
if ( F_20 ( & V_43 -> V_33 ) )
F_14 ( & V_43 -> V_33 ) ;
#if F_10 ( V_35 ) || F_10 ( V_36 )
else
F_21 ( V_43 -> V_37 . V_15 ) ;
#endif
F_15 ( V_43 ) ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_4 , V_18 -> free ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
return F_6 ( V_2 , V_5 , V_3 , V_44 ) ;
}
static int F_23 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_4 * V_45 = V_3 ;
V_6 = V_2 -> V_7 ;
F_2 ( & V_2 -> V_9 ) ;
F_3 ( & V_6 -> V_32 , 0 , V_45 -> V_11 >> V_12 ) ;
V_6 -> V_25 = 1 ;
V_6 -> V_42 = V_45 -> V_15 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_1 , V_45 -> V_15 , V_45 -> V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
return F_6 ( V_2 , V_5 , V_3 , V_31 ) ;
}
static T_5 * F_25 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
T_5 * V_48 ;
F_26 (entry, &dev->maplist, head) {
V_48 = V_47 -> V_48 ;
if ( ! V_48 )
continue;
if ( V_48 -> type == V_49 )
return V_48 ;
}
return NULL ;
}
int F_27 ( struct V_1 * V_2 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_6 V_50 ;
unsigned long V_51 ;
int V_52 ;
if ( V_6 -> V_53 )
return 0 ;
if ( V_6 -> V_54 == NULL ) {
V_6 -> V_54 = F_25 ( V_2 ) ;
if ( V_6 -> V_54 == NULL ) {
F_7 ( L_5 ) ;
return 0 ;
}
}
if ( V_6 -> V_55 != V_56 )
return 0 ;
V_51 = V_57 + ( V_58 * 3 ) ;
for ( V_52 = 0 ; V_52 < 4 ; ++ V_52 ) {
do {
V_50 = F_28 ( 0x85cc ) ;
} while ( ! F_29 ( V_57 , V_51 ) &&
( ( V_50 & 0x80000000 ) != 0x80000000 ) );
}
if ( F_29 ( V_57 , V_51 ) ) {
F_7 ( L_6
L_7 ) ;
V_6 -> V_53 = 1 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
T_1 * V_6 = V_2 -> V_7 ;
if ( ! V_6 )
return;
F_2 ( & V_2 -> V_9 ) ;
if ( V_6 -> V_13 ) {
F_31 ( & V_6 -> V_10 ) ;
V_6 -> V_13 = 0 ;
}
if ( V_6 -> V_25 ) {
F_31 ( & V_6 -> V_32 ) ;
V_6 -> V_25 = 0 ;
}
V_6 -> V_54 = NULL ;
F_4 ( & V_2 -> V_9 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_4 * V_16 )
{
struct V_23 * V_5 = V_16 -> V_24 ;
struct V_21 * V_47 , * V_59 ;
if ( ! ( V_2 -> V_60 && V_16 -> V_60 -> V_61 . V_62 ) )
return;
F_33 ( & V_16 -> V_60 -> V_61 ) ;
F_2 ( & V_2 -> V_9 ) ;
if ( F_34 ( & V_5 -> V_41 ) ) {
F_4 ( & V_2 -> V_9 ) ;
F_35 ( & V_16 -> V_60 -> V_61 ) ;
return;
}
F_27 ( V_2 ) ;
F_36 (entry, next, &file_priv->obj_list,
owner_list) {
F_19 ( & V_47 -> V_40 ) ;
if ( F_20 ( & V_47 -> V_33 ) )
F_14 ( & V_47 -> V_33 ) ;
#if F_10 ( V_35 ) || F_10 ( V_36 )
else
F_21 ( V_47 -> V_37 . V_15 ) ;
#endif
F_15 ( V_47 ) ;
}
F_4 ( & V_2 -> V_9 ) ;
F_35 ( & V_16 -> V_60 -> V_61 ) ;
return;
}
