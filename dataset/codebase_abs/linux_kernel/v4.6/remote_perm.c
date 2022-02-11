static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 ) ;
if ( V_2 )
F_3 ( & V_2 -> V_5 ) ;
return V_2 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_5 ( & V_2 -> V_5 ) )
F_6 ( & V_2 -> V_5 ) ;
F_7 ( V_3 , V_2 ) ;
}
static struct V_6 * F_8 ( void )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( V_9 , V_10 ) ;
if ( ! V_7 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
F_9 ( V_7 + V_8 ) ;
return V_7 ;
}
void F_10 ( struct V_6 * V_7 )
{
int V_8 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
if ( ! V_7 )
return;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
F_11 (lrp, next, hash + i, lrp_list)
F_4 ( V_2 ) ;
F_7 ( V_9 , V_7 ) ;
}
static inline int F_12 ( T_1 V_14 )
{
return V_14 & ( V_11 - 1 ) ;
}
static int F_13 ( struct V_15 * V_16 , int V_17 )
{
struct V_6 * V_18 ;
struct V_1 * V_2 ;
int V_19 = 0 , V_20 ;
if ( ! V_16 -> V_21 )
return - V_22 ;
V_18 = V_16 -> V_21 +
F_12 ( F_14 ( & V_23 , F_15 () ) ) ;
F_16 ( & V_16 -> V_24 ) ;
F_17 (lrp, head, lrp_list) {
if ( V_2 -> V_25 != F_14 ( & V_23 , F_15 () ) )
continue;
if ( V_2 -> V_26 != F_18 ( & V_23 , F_19 () ) )
continue;
if ( V_2 -> V_27 != F_14 ( & V_23 , F_20 () ) )
continue;
if ( V_2 -> V_28 != F_18 ( & V_23 , F_21 () ) )
continue;
V_19 = 1 ;
break;
}
if ( ! V_19 ) {
V_20 = - V_22 ;
goto V_29;
}
F_22 ( V_30 , L_1 ,
V_2 -> V_25 , V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_28 ,
V_2 -> V_31 ) ;
V_20 = ( ( V_2 -> V_31 & V_17 ) == V_17 ) ? 0 : - V_32 ;
V_29:
F_23 ( & V_16 -> V_24 ) ;
return V_20 ;
}
int F_24 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
struct V_15 * V_16 = F_25 ( V_33 ) ;
struct V_1 * V_2 = NULL , * V_36 = NULL ;
struct V_6 * V_18 , * V_37 = NULL ;
F_26 ( F_27 ( V_33 ) -> V_38 & V_39 ) ;
#if 0
if (perm->rp_uid != current->uid ||
perm->rp_gid != current->gid ||
perm->rp_fsuid != current->fsuid ||
perm->rp_fsgid != current->fsgid) {
CDEBUG(D_SEC,
"remote perm user %u/%u/%u/%u != current %u/%u/%u/%u\n",
perm->rp_uid, perm->rp_gid, perm->rp_fsuid,
perm->rp_fsgid, current->uid, current->gid,
current->fsuid, current->fsgid);
return -EAGAIN;
}
#endif
if ( ! V_16 -> V_21 ) {
V_37 = F_8 () ;
if ( ! V_37 ) {
F_28 ( L_2 ) ;
return - V_40 ;
}
}
F_16 ( & V_16 -> V_24 ) ;
if ( ! V_16 -> V_21 )
V_16 -> V_21 = V_37 ;
else
F_10 ( V_37 ) ;
V_18 = V_16 -> V_21 + F_12 ( V_35 -> V_41 ) ;
V_42:
F_17 (tmp, head, lrp_list) {
if ( V_36 -> V_25 != V_35 -> V_41 )
continue;
if ( V_36 -> V_26 != V_35 -> V_43 )
continue;
if ( V_36 -> V_27 != V_35 -> V_44 )
continue;
if ( V_36 -> V_28 != V_35 -> V_45 )
continue;
F_4 ( V_2 ) ;
V_2 = V_36 ;
break;
}
if ( ! V_2 ) {
F_23 ( & V_16 -> V_24 ) ;
V_2 = F_1 () ;
if ( ! V_2 ) {
F_28 ( L_3 ) ;
return - V_40 ;
}
F_16 ( & V_16 -> V_24 ) ;
goto V_42;
}
V_2 -> V_31 = V_35 -> V_46 ;
if ( V_2 != V_36 ) {
V_2 -> V_25 = V_35 -> V_41 ;
V_2 -> V_26 = V_35 -> V_43 ;
V_2 -> V_27 = V_35 -> V_44 ;
V_2 -> V_28 = V_35 -> V_45 ;
F_29 ( & V_2 -> V_5 , V_18 ) ;
}
V_16 -> V_47 = F_30 () ;
F_23 ( & V_16 -> V_24 ) ;
F_22 ( V_30 , L_4 ,
V_2 , V_2 -> V_25 , V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_28 ,
V_2 -> V_31 ) ;
return 0 ;
}
int F_31 ( struct V_33 * V_33 , int V_17 )
{
struct V_15 * V_16 = F_25 ( V_33 ) ;
struct V_48 * V_49 = F_27 ( V_33 ) ;
struct V_50 * V_51 = NULL ;
struct V_34 * V_35 ;
unsigned long V_52 ;
int V_8 = 0 , V_20 ;
do {
V_52 = V_16 -> V_47 ;
V_20 = F_13 ( V_16 , V_17 ) ;
if ( ! V_20 || ( V_20 != - V_22 && V_8 ) )
break;
F_32 () ;
F_33 ( & V_16 -> V_53 ) ;
if ( V_52 != V_16 -> V_47 ) {
V_20 = F_13 ( V_16 , V_17 ) ;
if ( ! V_20 || ( V_20 != - V_22 && V_8 ) ) {
F_34 ( & V_16 -> V_53 ) ;
break;
}
}
if ( V_8 ++ > 5 ) {
F_28 ( L_5 ) ;
F_35 () ;
}
V_20 = F_36 ( V_49 -> V_54 , F_37 ( V_33 ) ,
F_38 ( V_33 ) , & V_51 ) ;
if ( V_20 ) {
F_34 ( & V_16 -> V_53 ) ;
break;
}
V_35 = F_39 ( & V_51 -> V_55 , & V_56 ,
V_57 ) ;
if ( F_40 ( ! V_35 ) ) {
F_34 ( & V_16 -> V_53 ) ;
V_20 = - V_58 ;
break;
}
V_20 = F_24 ( V_33 , V_35 ) ;
F_34 ( & V_16 -> V_53 ) ;
if ( V_20 == - V_40 )
break;
F_41 ( V_51 ) ;
V_51 = NULL ;
} while ( 1 );
F_41 ( V_51 ) ;
return V_20 ;
}
