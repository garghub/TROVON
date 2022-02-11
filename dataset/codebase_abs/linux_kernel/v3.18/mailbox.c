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
int V_14 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
if ( ! V_2 -> V_7 || V_2 -> V_15 )
goto exit;
V_12 = V_2 -> V_7 ;
V_4 = V_2 -> V_10 ;
if ( V_4 >= V_12 )
V_4 -= V_12 ;
else
V_4 += V_8 - V_12 ;
V_13 = V_2 -> V_11 [ V_4 ] ;
V_14 = V_2 -> V_16 -> V_17 -> V_18 ( V_2 , V_13 ) ;
if ( ! V_14 ) {
V_2 -> V_15 = V_13 ;
V_2 -> V_7 -- ;
}
exit:
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_19 )
{
unsigned long V_5 ;
void * V_3 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_3 = V_2 -> V_15 ;
V_2 -> V_15 = NULL ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
F_4 ( V_2 ) ;
if ( V_3 && V_2 -> V_20 -> V_21 )
V_2 -> V_20 -> V_21 ( V_2 -> V_20 , V_3 , V_19 ) ;
if ( V_2 -> V_20 -> V_22 )
F_6 ( & V_2 -> V_23 ) ;
}
static void F_7 ( unsigned long V_13 )
{
struct V_24 * V_16 = (struct V_24 * ) V_13 ;
bool V_25 , V_26 = false ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_16 -> V_28 ; V_27 ++ ) {
struct V_1 * V_2 = & V_16 -> V_29 [ V_27 ] ;
if ( V_2 -> V_15 && V_2 -> V_20 ) {
V_26 = true ;
V_25 = V_2 -> V_16 -> V_17 -> V_30 ( V_2 ) ;
if ( V_25 )
F_5 ( V_2 , 0 ) ;
}
}
if ( V_26 )
F_8 ( & V_16 -> V_31 , V_32 +
F_9 ( V_16 -> V_33 ) ) ;
}
void F_10 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_2 -> V_20 -> V_34 )
V_2 -> V_20 -> V_34 ( V_2 -> V_20 , V_3 ) ;
}
void F_11 ( struct V_1 * V_2 , int V_19 )
{
if ( F_12 ( ! ( V_2 -> V_35 & V_36 ) ) ) {
F_13 ( V_2 -> V_16 -> V_37 ,
L_1 ) ;
return;
}
F_5 ( V_2 , V_19 ) ;
}
void F_14 ( struct V_1 * V_2 , int V_19 )
{
if ( F_12 ( ! ( V_2 -> V_35 & V_38 ) ) ) {
F_13 ( V_2 -> V_16 -> V_37 , L_2 ) ;
return;
}
F_5 ( V_2 , V_19 ) ;
}
bool F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_17 -> V_39 )
return V_2 -> V_16 -> V_17 -> V_39 ( V_2 ) ;
return false ;
}
int F_16 ( struct V_1 * V_2 , void * V_3 )
{
int V_40 ;
if ( ! V_2 || ! V_2 -> V_20 )
return - V_41 ;
V_40 = F_1 ( V_2 , V_3 ) ;
if ( V_40 < 0 ) {
F_13 ( V_2 -> V_16 -> V_37 , L_3 ) ;
return V_40 ;
}
F_4 ( V_2 ) ;
if ( V_2 -> V_35 == V_42 )
F_7 ( ( unsigned long ) V_2 -> V_16 ) ;
if ( V_2 -> V_20 -> V_22 && V_2 -> V_15 ) {
unsigned long V_43 ;
int V_44 ;
if ( ! V_2 -> V_20 -> V_45 )
V_43 = F_9 ( 3600000 ) ;
else
V_43 = F_9 ( V_2 -> V_20 -> V_45 ) ;
V_44 = F_17 ( & V_2 -> V_23 , V_43 ) ;
if ( V_44 == 0 ) {
V_40 = - V_46 ;
F_5 ( V_2 , - V_46 ) ;
}
}
return V_40 ;
}
struct V_1 * F_18 ( struct V_47 * V_20 , int V_48 )
{
struct V_49 * V_37 = V_20 -> V_37 ;
struct V_24 * V_16 ;
struct V_50 V_51 ;
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_44 ;
if ( ! V_37 || ! V_37 -> V_52 ) {
F_19 ( L_4 , V_53 ) ;
return F_20 ( - V_54 ) ;
}
F_21 ( & V_55 ) ;
if ( F_22 ( V_37 -> V_52 , L_5 ,
L_6 , V_48 , & V_51 ) ) {
F_23 ( V_37 , L_7 , V_53 ) ;
F_24 ( & V_55 ) ;
return F_20 ( - V_54 ) ;
}
V_2 = NULL ;
F_25 (mbox, &mbox_cons, node)
if ( V_16 -> V_37 -> V_52 == V_51 . V_56 ) {
V_2 = V_16 -> V_57 ( V_16 , & V_51 ) ;
break;
}
F_26 ( V_51 . V_56 ) ;
if ( ! V_2 || V_2 -> V_20 || ! F_27 ( V_16 -> V_37 -> V_58 -> V_59 ) ) {
F_23 ( V_37 , L_8 , V_53 ) ;
F_24 ( & V_55 ) ;
return F_20 ( - V_60 ) ;
}
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_15 = NULL ;
V_2 -> V_20 = V_20 ;
F_28 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_35 == V_42 && V_20 -> V_61 )
V_2 -> V_35 |= V_38 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_44 = V_2 -> V_16 -> V_17 -> V_62 ( V_2 ) ;
if ( V_44 ) {
F_13 ( V_37 , L_9 , V_44 ) ;
F_29 ( V_2 ) ;
V_2 = F_20 ( V_44 ) ;
}
F_24 ( & V_55 ) ;
return V_2 ;
}
void F_29 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
if ( ! V_2 || ! V_2 -> V_20 )
return;
V_2 -> V_16 -> V_17 -> V_63 ( V_2 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_35 == ( V_42 | V_38 ) )
V_2 -> V_35 = V_42 ;
F_30 ( V_2 -> V_16 -> V_37 -> V_58 -> V_59 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static struct V_1 *
F_31 ( struct V_24 * V_16 ,
const struct V_50 * V_64 )
{
int V_65 = V_64 -> args [ 0 ] ;
if ( V_65 >= V_16 -> V_28 )
return NULL ;
return & V_16 -> V_29 [ V_65 ] ;
}
int F_32 ( struct V_24 * V_16 )
{
int V_27 , V_25 ;
if ( ! V_16 || ! V_16 -> V_37 || ! V_16 -> V_17 || ! V_16 -> V_28 )
return - V_41 ;
if ( V_16 -> V_66 )
V_25 = V_36 ;
else if ( V_16 -> V_67 )
V_25 = V_42 ;
else
V_25 = V_38 ;
if ( V_25 == V_42 ) {
V_16 -> V_31 . V_68 = & F_7 ;
V_16 -> V_31 . V_13 = ( unsigned long ) V_16 ;
F_33 ( & V_16 -> V_31 ) ;
}
for ( V_27 = 0 ; V_27 < V_16 -> V_28 ; V_27 ++ ) {
struct V_1 * V_2 = & V_16 -> V_29 [ V_27 ] ;
V_2 -> V_20 = NULL ;
V_2 -> V_16 = V_16 ;
V_2 -> V_35 = V_25 ;
F_34 ( & V_2 -> V_6 ) ;
}
if ( ! V_16 -> V_57 )
V_16 -> V_57 = F_31 ;
F_21 ( & V_55 ) ;
F_35 ( & V_16 -> V_69 , & V_70 ) ;
F_24 ( & V_55 ) ;
return 0 ;
}
void F_36 ( struct V_24 * V_16 )
{
int V_27 ;
if ( ! V_16 )
return;
F_21 ( & V_55 ) ;
F_37 ( & V_16 -> V_69 ) ;
for ( V_27 = 0 ; V_27 < V_16 -> V_28 ; V_27 ++ )
F_29 ( & V_16 -> V_29 [ V_27 ] ) ;
if ( V_16 -> V_67 )
F_38 ( & V_16 -> V_31 ) ;
F_24 ( & V_55 ) ;
}
