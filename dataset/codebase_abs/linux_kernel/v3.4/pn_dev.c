static struct V_1 * F_1 ( struct V_2 * V_2 )
{
F_2 ( ! V_2 ) ;
return F_3 ( V_2 , V_3 ) ;
}
struct V_4 * V_4 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
return & V_5 -> V_6 ;
}
static struct V_7 * F_4 ( struct V_8 * V_9 )
{
struct V_4 * V_6 = V_4 ( F_5 ( V_9 ) ) ;
struct V_7 * V_10 = F_6 ( sizeof( * V_10 ) , V_11 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_12 = V_9 ;
F_7 ( V_10 -> V_13 , 64 ) ;
F_2 ( ! F_8 ( & V_6 -> V_14 ) ) ;
F_9 ( & V_10 -> V_15 , & V_6 -> V_15 ) ;
return V_10 ;
}
static struct V_7 * F_10 ( struct V_8 * V_9 )
{
struct V_4 * V_6 = V_4 ( F_5 ( V_9 ) ) ;
struct V_7 * V_10 ;
F_2 ( ! F_8 ( & V_6 -> V_14 ) ) ;
F_11 (pnd, &pndevs->list, list) {
if ( V_10 -> V_12 == V_9 )
return V_10 ;
}
return NULL ;
}
static struct V_7 * F_12 ( struct V_8 * V_9 )
{
struct V_4 * V_6 = V_4 ( F_5 ( V_9 ) ) ;
struct V_7 * V_10 ;
F_13 (pnd, &pndevs->list, list) {
if ( V_10 -> V_12 == V_9 )
return V_10 ;
}
return NULL ;
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_4 * V_6 = V_4 ( F_5 ( V_9 ) ) ;
struct V_7 * V_10 ;
F_15 () ;
F_16 ( & V_6 -> V_14 ) ;
V_10 = F_10 ( V_9 ) ;
if ( V_10 )
F_17 ( & V_10 -> V_15 ) ;
F_18 ( & V_6 -> V_14 ) ;
if ( V_10 ) {
T_1 V_16 ;
F_19 (addr, pnd->addrs, 64 )
F_20 ( V_17 , V_9 , V_16 ) ;
F_21 ( V_10 ) ;
}
}
struct V_8 * F_22 ( struct V_2 * V_2 )
{
struct V_4 * V_6 = V_4 ( V_2 ) ;
struct V_7 * V_10 ;
struct V_8 * V_9 = NULL ;
F_23 () ;
F_13 (pnd, &pndevs->list, list) {
V_9 = V_10 -> V_12 ;
F_2 ( ! V_9 ) ;
if ( ( V_9 -> V_18 == V_19 ) &&
( ( V_10 -> V_12 -> V_20 & V_21 ) ) == V_21 )
break;
V_9 = NULL ;
}
if ( V_9 )
F_24 ( V_9 ) ;
F_25 () ;
return V_9 ;
}
int F_26 ( struct V_8 * V_9 , T_1 V_16 )
{
struct V_4 * V_6 = V_4 ( F_5 ( V_9 ) ) ;
struct V_7 * V_10 ;
int V_22 = 0 ;
F_16 ( & V_6 -> V_14 ) ;
V_10 = F_10 ( V_9 ) ;
if ( V_10 == NULL )
V_10 = F_4 ( V_9 ) ;
if ( F_27 ( V_10 == NULL ) )
V_22 = - V_23 ;
else if ( F_28 ( V_16 >> 2 , V_10 -> V_13 ) )
V_22 = - V_24 ;
F_18 ( & V_6 -> V_14 ) ;
return V_22 ;
}
int F_29 ( struct V_8 * V_9 , T_1 V_16 )
{
struct V_4 * V_6 = V_4 ( F_5 ( V_9 ) ) ;
struct V_7 * V_10 ;
int V_22 = 0 ;
F_16 ( & V_6 -> V_14 ) ;
V_10 = F_10 ( V_9 ) ;
if ( ! V_10 || ! F_30 ( V_16 >> 2 , V_10 -> V_13 ) ) {
V_22 = - V_25 ;
V_10 = NULL ;
} else if ( F_31 ( V_10 -> V_13 , 64 ) )
F_17 ( & V_10 -> V_15 ) ;
else
V_10 = NULL ;
F_18 ( & V_6 -> V_14 ) ;
if ( V_10 )
F_32 ( V_10 , V_26 ) ;
return V_22 ;
}
T_1 F_33 ( struct V_8 * V_9 , T_1 V_27 )
{
struct V_7 * V_10 ;
T_1 V_28 ;
F_23 () ;
V_10 = F_12 ( V_9 ) ;
if ( V_10 ) {
F_2 ( F_31 ( V_10 -> V_13 , 64 ) ) ;
if ( F_34 ( V_27 >> 2 , V_10 -> V_13 ) )
V_28 = V_27 ;
else
V_28 = F_35 ( V_10 -> V_13 , 64 ) << 2 ;
} else
V_28 = V_29 ;
F_25 () ;
if ( V_28 == V_29 ) {
struct V_8 * V_30 ;
V_30 = F_22 ( F_5 ( V_9 ) ) ;
if ( V_30 ) {
if ( V_30 != V_9 )
V_28 = F_33 ( V_30 , V_27 ) ;
F_36 ( V_30 ) ;
}
}
return V_28 ;
}
int F_37 ( struct V_2 * V_2 , T_1 V_16 )
{
struct V_4 * V_6 = V_4 ( V_2 ) ;
struct V_7 * V_10 ;
int V_22 = - V_25 ;
F_23 () ;
F_13 (pnd, &pndevs->list, list) {
if ( ( V_10 -> V_12 -> V_18 != V_19 ) ||
( ( V_10 -> V_12 -> V_20 & V_21 ) ) != V_21 )
continue;
if ( F_34 ( V_16 >> 2 , V_10 -> V_13 ) ) {
V_22 = 0 ;
goto V_31;
}
}
V_31:
F_25 () ;
return V_22 ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_32 V_33 ;
int V_34 ;
if ( ! V_9 -> V_35 -> V_36 )
return - V_37 ;
V_34 = V_9 -> V_35 -> V_36 ( V_9 , (struct V_38 * ) & V_33 ,
V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
F_15 () ;
V_34 = F_26 ( V_9 , V_33 . V_40 . V_41 ) ;
if ( V_34 )
return V_34 ;
F_20 ( V_42 , V_9 ,
V_33 . V_40 . V_41 ) ;
return 0 ;
}
static void F_39 ( struct V_8 * V_9 )
{
struct V_1 * V_5 = F_1 ( F_5 ( V_9 ) ) ;
unsigned V_43 ;
F_40 ( V_44 , 64 ) ;
F_7 ( V_44 , 64 ) ;
F_16 ( & V_5 -> V_45 . V_14 ) ;
for ( V_43 = 0 ; V_43 < 64 ; V_43 ++ )
if ( V_9 == V_5 -> V_45 . V_46 [ V_43 ] ) {
F_41 ( V_5 -> V_45 . V_46 [ V_43 ] , NULL ) ;
F_42 ( V_43 , V_44 ) ;
}
F_18 ( & V_5 -> V_45 . V_14 ) ;
if ( F_31 ( V_44 , 64 ) )
return;
F_43 () ;
F_19 (i, deleted, 64 ) {
F_44 ( V_47 , V_9 , V_43 ) ;
F_36 ( V_9 ) ;
}
}
static int F_45 ( struct V_48 * V_49 , unsigned long V_50 ,
void * V_51 )
{
struct V_8 * V_9 = V_51 ;
switch ( V_50 ) {
case V_52 :
if ( V_9 -> type == V_53 )
F_38 ( V_9 ) ;
break;
case V_54 :
F_14 ( V_9 ) ;
F_39 ( V_9 ) ;
break;
}
return 0 ;
}
static int T_2 F_46 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
if ( ! F_47 ( V_2 , L_1 , 0 , & V_55 ) )
return - V_23 ;
F_48 ( & V_5 -> V_6 . V_15 ) ;
F_49 ( & V_5 -> V_6 . V_14 ) ;
F_49 ( & V_5 -> V_45 . V_14 ) ;
return 0 ;
}
static void T_3 F_50 ( struct V_2 * V_2 )
{
F_51 ( V_2 , L_1 ) ;
}
int T_4 F_52 ( void )
{
int V_22 = F_53 ( & V_56 ) ;
if ( V_22 )
return V_22 ;
F_47 ( & V_57 , L_2 , 0 , & V_58 ) ;
F_54 ( & V_59 ) ;
V_22 = F_55 () ;
if ( V_22 )
F_56 () ;
return V_22 ;
}
void F_56 ( void )
{
F_57 ( V_60 ) ;
F_58 ( & V_59 ) ;
F_59 ( & V_56 ) ;
F_51 ( & V_57 , L_2 ) ;
}
int F_60 ( struct V_8 * V_9 , T_1 V_27 )
{
struct V_1 * V_5 = F_1 ( F_5 ( V_9 ) ) ;
struct V_61 * V_45 = & V_5 -> V_45 ;
int V_22 = - V_24 ;
V_27 = V_27 >> 2 ;
F_16 ( & V_45 -> V_14 ) ;
if ( V_45 -> V_46 [ V_27 ] == NULL ) {
F_61 ( V_45 -> V_46 [ V_27 ] , V_9 ) ;
F_24 ( V_9 ) ;
V_22 = 0 ;
}
F_18 ( & V_45 -> V_14 ) ;
return V_22 ;
}
int F_62 ( struct V_8 * V_9 , T_1 V_27 )
{
struct V_1 * V_5 = F_1 ( F_5 ( V_9 ) ) ;
struct V_61 * V_45 = & V_5 -> V_45 ;
V_27 = V_27 >> 2 ;
F_16 ( & V_45 -> V_14 ) ;
if ( V_9 == V_45 -> V_46 [ V_27 ] )
F_41 ( V_45 -> V_46 [ V_27 ] , NULL ) ;
else
V_9 = NULL ;
F_18 ( & V_45 -> V_14 ) ;
if ( ! V_9 )
return - V_62 ;
F_43 () ;
F_36 ( V_9 ) ;
return 0 ;
}
struct V_8 * F_63 ( struct V_2 * V_2 , T_1 V_27 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
struct V_61 * V_45 = & V_5 -> V_45 ;
struct V_8 * V_9 ;
V_27 >>= 2 ;
V_9 = F_64 ( V_45 -> V_46 [ V_27 ] ) ;
return V_9 ;
}
struct V_8 * F_65 ( struct V_2 * V_2 , T_1 V_27 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
struct V_61 * V_45 = & V_5 -> V_45 ;
struct V_8 * V_9 ;
V_27 >>= 2 ;
F_23 () ;
V_9 = F_64 ( V_45 -> V_46 [ V_27 ] ) ;
if ( V_9 )
F_24 ( V_9 ) ;
F_25 () ;
if ( ! V_9 )
V_9 = F_22 ( V_2 ) ;
return V_9 ;
}
