static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 | V_5 ) ;
if ( V_2 )
F_3 ( & V_2 -> V_6 ) ;
return V_2 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( ! F_5 ( & V_2 -> V_6 ) )
F_6 ( & V_2 -> V_6 ) ;
F_7 ( V_3 , V_2 ) ;
}
static struct V_7 * F_8 ( void )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( V_10 , V_11 | V_5 ) ;
if ( ! V_8 )
return NULL ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
F_9 ( V_8 + V_9 ) ;
return V_8 ;
}
void F_10 ( struct V_7 * V_8 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
if ( ! V_8 )
return;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
F_11 (lrp, next, hash + i, lrp_list)
F_4 ( V_2 ) ;
F_7 ( V_10 , V_8 ) ;
}
static inline int F_12 ( T_1 V_15 )
{
return V_15 & ( V_12 - 1 ) ;
}
static int F_13 ( struct V_16 * V_17 , int V_18 )
{
struct V_7 * V_19 ;
struct V_1 * V_2 ;
int V_20 = 0 , V_21 ;
if ( ! V_17 -> V_22 )
return - V_23 ;
V_19 = V_17 -> V_22 +
F_12 ( F_14 ( & V_24 , F_15 () ) ) ;
F_16 ( & V_17 -> V_25 ) ;
F_17 (lrp, head, lrp_list) {
if ( V_2 -> V_26 != F_14 ( & V_24 , F_15 () ) )
continue;
if ( V_2 -> V_27 != F_18 ( & V_24 , F_19 () ) )
continue;
if ( V_2 -> V_28 != F_14 ( & V_24 , F_20 () ) )
continue;
if ( V_2 -> V_29 != F_18 ( & V_24 , F_21 () ) )
continue;
V_20 = 1 ;
break;
}
if ( ! V_20 ) {
V_21 = - V_23 ;
goto V_30;
}
F_22 ( V_31 , L_1 ,
V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_28 , V_2 -> V_29 ,
V_2 -> V_32 ) ;
V_21 = ( ( V_2 -> V_32 & V_18 ) == V_18 ) ? 0 : - V_33 ;
V_30:
F_23 ( & V_17 -> V_25 ) ;
return V_21 ;
}
int F_24 ( struct V_34 * V_34 , struct V_35 * V_36 )
{
struct V_16 * V_17 = F_25 ( V_34 ) ;
struct V_1 * V_2 = NULL , * V_37 = NULL ;
struct V_7 * V_19 , * V_38 = NULL ;
F_26 ( F_27 ( V_34 ) -> V_39 & V_40 ) ;
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
if ( ! V_17 -> V_22 ) {
V_38 = F_8 () ;
if ( ! V_38 ) {
F_28 ( L_2 ) ;
return - V_41 ;
}
}
F_16 ( & V_17 -> V_25 ) ;
if ( ! V_17 -> V_22 )
V_17 -> V_22 = V_38 ;
else
F_10 ( V_38 ) ;
V_19 = V_17 -> V_22 + F_12 ( V_36 -> V_42 ) ;
V_43:
F_17 (tmp, head, lrp_list) {
if ( V_37 -> V_26 != V_36 -> V_42 )
continue;
if ( V_37 -> V_27 != V_36 -> V_44 )
continue;
if ( V_37 -> V_28 != V_36 -> V_45 )
continue;
if ( V_37 -> V_29 != V_36 -> V_46 )
continue;
F_4 ( V_2 ) ;
V_2 = V_37 ;
break;
}
if ( ! V_2 ) {
F_23 ( & V_17 -> V_25 ) ;
V_2 = F_1 () ;
if ( ! V_2 ) {
F_28 ( L_3 ) ;
return - V_41 ;
}
F_16 ( & V_17 -> V_25 ) ;
goto V_43;
}
V_2 -> V_32 = V_36 -> V_47 ;
if ( V_2 != V_37 ) {
V_2 -> V_26 = V_36 -> V_42 ;
V_2 -> V_27 = V_36 -> V_44 ;
V_2 -> V_28 = V_36 -> V_45 ;
V_2 -> V_29 = V_36 -> V_46 ;
F_29 ( & V_2 -> V_6 , V_19 ) ;
}
V_17 -> V_48 = F_30 () ;
F_23 ( & V_17 -> V_25 ) ;
F_22 ( V_31 , L_4 ,
V_2 , V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_28 , V_2 -> V_29 ,
V_2 -> V_32 ) ;
return 0 ;
}
int F_31 ( struct V_34 * V_34 , int V_18 )
{
struct V_16 * V_17 = F_25 ( V_34 ) ;
struct V_49 * V_50 = F_27 ( V_34 ) ;
struct V_51 * V_52 = NULL ;
struct V_35 * V_36 ;
unsigned long V_53 ;
int V_9 = 0 , V_21 ;
do {
V_53 = V_17 -> V_48 ;
V_21 = F_13 ( V_17 , V_18 ) ;
if ( ! V_21 || ( V_21 != - V_23 && V_9 ) )
break;
F_32 () ;
F_33 ( & V_17 -> V_54 ) ;
if ( V_53 != V_17 -> V_48 ) {
V_21 = F_13 ( V_17 , V_18 ) ;
if ( ! V_21 || ( V_21 != - V_23 && V_9 ) ) {
F_34 ( & V_17 -> V_54 ) ;
break;
}
}
if ( V_9 ++ > 5 ) {
F_28 ( L_5 ) ;
F_35 () ;
}
V_21 = F_36 ( V_50 -> V_55 , F_37 ( V_34 ) ,
F_38 ( V_34 ) , & V_52 ) ;
if ( V_21 ) {
F_34 ( & V_17 -> V_54 ) ;
break;
}
V_36 = F_39 ( & V_52 -> V_56 , & V_57 ,
V_58 ) ;
if ( F_40 ( ! V_36 ) ) {
F_34 ( & V_17 -> V_54 ) ;
V_21 = - V_59 ;
break;
}
V_21 = F_24 ( V_34 , V_36 ) ;
F_34 ( & V_17 -> V_54 ) ;
if ( V_21 == - V_41 )
break;
F_41 ( V_52 ) ;
V_52 = NULL ;
} while ( 1 );
F_41 ( V_52 ) ;
return V_21 ;
}
