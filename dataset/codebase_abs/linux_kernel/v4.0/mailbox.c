static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
if ( V_2 -> V_7 == V_8 ) {
F_3 ( & V_2 -> V_6 , V_5 ) ;
return - V_9 ;
}
V_4 = V_2 -> V_10 ;
V_2 -> V_11 [ V_4 ] = V_3 ;
V_2 -> V_7 ++ ;
if ( V_4 == V_8 - 1 )
V_2 -> V_10 = 0 ;
else
V_2 -> V_10 ++ ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned V_12 , V_4 ;
unsigned long V_5 ;
void * V_13 ;
int V_14 = - V_15 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
if ( ! V_2 -> V_7 || V_2 -> V_16 )
goto exit;
V_12 = V_2 -> V_7 ;
V_4 = V_2 -> V_10 ;
if ( V_4 >= V_12 )
V_4 -= V_12 ;
else
V_4 += V_8 - V_12 ;
V_13 = V_2 -> V_11 [ V_4 ] ;
if ( V_2 -> V_17 -> V_18 )
V_2 -> V_17 -> V_18 ( V_2 -> V_17 , V_13 ) ;
V_14 = V_2 -> V_19 -> V_20 -> V_21 ( V_2 , V_13 ) ;
if ( ! V_14 ) {
V_2 -> V_16 = V_13 ;
V_2 -> V_7 -- ;
}
exit:
F_3 ( & V_2 -> V_6 , V_5 ) ;
if ( ! V_14 && ( V_2 -> V_22 & V_23 ) )
F_5 ( ( unsigned long ) V_2 -> V_19 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_24 )
{
unsigned long V_5 ;
void * V_3 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_3 = V_2 -> V_16 ;
V_2 -> V_16 = NULL ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
F_4 ( V_2 ) ;
if ( V_3 && V_2 -> V_17 -> V_25 )
V_2 -> V_17 -> V_25 ( V_2 -> V_17 , V_3 , V_24 ) ;
if ( V_2 -> V_17 -> V_26 )
F_7 ( & V_2 -> V_27 ) ;
}
static void F_5 ( unsigned long V_13 )
{
struct V_28 * V_19 = (struct V_28 * ) V_13 ;
bool V_29 , V_30 = false ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_1 * V_2 = & V_19 -> V_33 [ V_31 ] ;
if ( V_2 -> V_16 && V_2 -> V_17 ) {
V_29 = V_2 -> V_19 -> V_20 -> V_34 ( V_2 ) ;
if ( V_29 )
F_6 ( V_2 , 0 ) ;
else
V_30 = true ;
}
}
if ( V_30 )
F_8 ( & V_19 -> V_35 , V_36 +
F_9 ( V_19 -> V_37 ) ) ;
}
void F_10 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_2 -> V_17 -> V_38 )
V_2 -> V_17 -> V_38 ( V_2 -> V_17 , V_3 ) ;
}
void F_11 ( struct V_1 * V_2 , int V_24 )
{
if ( F_12 ( ! ( V_2 -> V_22 & V_39 ) ) ) {
F_13 ( V_2 -> V_19 -> V_40 ,
L_1 ) ;
return;
}
F_6 ( V_2 , V_24 ) ;
}
void F_14 ( struct V_1 * V_2 , int V_24 )
{
if ( F_12 ( ! ( V_2 -> V_22 & V_41 ) ) ) {
F_13 ( V_2 -> V_19 -> V_40 , L_2 ) ;
return;
}
F_6 ( V_2 , V_24 ) ;
}
bool F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 -> V_20 -> V_42 )
return V_2 -> V_19 -> V_20 -> V_42 ( V_2 ) ;
return false ;
}
int F_16 ( struct V_1 * V_2 , void * V_3 )
{
int V_43 ;
if ( ! V_2 || ! V_2 -> V_17 )
return - V_44 ;
V_43 = F_1 ( V_2 , V_3 ) ;
if ( V_43 < 0 ) {
F_13 ( V_2 -> V_19 -> V_40 , L_3 ) ;
return V_43 ;
}
F_4 ( V_2 ) ;
if ( V_2 -> V_17 -> V_26 && V_2 -> V_16 ) {
unsigned long V_45 ;
int V_46 ;
if ( ! V_2 -> V_17 -> V_47 )
V_45 = F_9 ( 3600000 ) ;
else
V_45 = F_9 ( V_2 -> V_17 -> V_47 ) ;
V_46 = F_17 ( & V_2 -> V_27 , V_45 ) ;
if ( V_46 == 0 ) {
V_43 = - V_48 ;
F_6 ( V_2 , - V_48 ) ;
}
}
return V_43 ;
}
struct V_1 * F_18 ( struct V_49 * V_17 , int V_50 )
{
struct V_51 * V_40 = V_17 -> V_40 ;
struct V_28 * V_19 ;
struct V_52 V_53 ;
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_46 ;
if ( ! V_40 || ! V_40 -> V_54 ) {
F_19 ( L_4 , V_55 ) ;
return F_20 ( - V_56 ) ;
}
F_21 ( & V_57 ) ;
if ( F_22 ( V_40 -> V_54 , L_5 ,
L_6 , V_50 , & V_53 ) ) {
F_23 ( V_40 , L_7 , V_55 ) ;
F_24 ( & V_57 ) ;
return F_20 ( - V_56 ) ;
}
V_2 = NULL ;
F_25 (mbox, &mbox_cons, node)
if ( V_19 -> V_40 -> V_54 == V_53 . V_58 ) {
V_2 = V_19 -> V_59 ( V_19 , & V_53 ) ;
break;
}
F_26 ( V_53 . V_58 ) ;
if ( ! V_2 || V_2 -> V_17 || ! F_27 ( V_19 -> V_40 -> V_60 -> V_61 ) ) {
F_23 ( V_40 , L_8 , V_55 ) ;
F_24 ( & V_57 ) ;
return F_20 ( - V_15 ) ;
}
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = V_17 ;
F_28 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_22 == V_23 && V_17 -> V_62 )
V_2 -> V_22 |= V_41 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_46 = V_2 -> V_19 -> V_20 -> V_63 ( V_2 ) ;
if ( V_46 ) {
F_13 ( V_40 , L_9 , V_46 ) ;
F_29 ( V_2 ) ;
V_2 = F_20 ( V_46 ) ;
}
F_24 ( & V_57 ) ;
return V_2 ;
}
void F_29 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
if ( ! V_2 || ! V_2 -> V_17 )
return;
V_2 -> V_19 -> V_20 -> V_64 ( V_2 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_17 = NULL ;
V_2 -> V_16 = NULL ;
if ( V_2 -> V_22 == ( V_23 | V_41 ) )
V_2 -> V_22 = V_23 ;
F_30 ( V_2 -> V_19 -> V_40 -> V_60 -> V_61 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static struct V_1 *
F_31 ( struct V_28 * V_19 ,
const struct V_52 * V_65 )
{
int V_66 = V_65 -> args [ 0 ] ;
if ( V_66 >= V_19 -> V_32 )
return NULL ;
return & V_19 -> V_33 [ V_66 ] ;
}
int F_32 ( struct V_28 * V_19 )
{
int V_31 , V_29 ;
if ( ! V_19 || ! V_19 -> V_40 || ! V_19 -> V_20 || ! V_19 -> V_32 )
return - V_44 ;
if ( V_19 -> V_67 )
V_29 = V_39 ;
else if ( V_19 -> V_68 )
V_29 = V_23 ;
else
V_29 = V_41 ;
if ( V_29 == V_23 ) {
V_19 -> V_35 . V_69 = & F_5 ;
V_19 -> V_35 . V_13 = ( unsigned long ) V_19 ;
F_33 ( & V_19 -> V_35 ) ;
}
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ ) {
struct V_1 * V_2 = & V_19 -> V_33 [ V_31 ] ;
V_2 -> V_17 = NULL ;
V_2 -> V_19 = V_19 ;
V_2 -> V_22 = V_29 ;
F_34 ( & V_2 -> V_6 ) ;
}
if ( ! V_19 -> V_59 )
V_19 -> V_59 = F_31 ;
F_21 ( & V_57 ) ;
F_35 ( & V_19 -> V_70 , & V_71 ) ;
F_24 ( & V_57 ) ;
return 0 ;
}
void F_36 ( struct V_28 * V_19 )
{
int V_31 ;
if ( ! V_19 )
return;
F_21 ( & V_57 ) ;
F_37 ( & V_19 -> V_70 ) ;
for ( V_31 = 0 ; V_31 < V_19 -> V_32 ; V_31 ++ )
F_29 ( & V_19 -> V_33 [ V_31 ] ) ;
if ( V_19 -> V_68 )
F_38 ( & V_19 -> V_35 ) ;
F_24 ( & V_57 ) ;
}
