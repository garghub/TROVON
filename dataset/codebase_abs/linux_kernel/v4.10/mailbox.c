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
F_5 ( & V_2 -> V_19 -> V_24 , 0 , V_25 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_26 )
{
unsigned long V_5 ;
void * V_3 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_3 = V_2 -> V_16 ;
V_2 -> V_16 = NULL ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
F_4 ( V_2 ) ;
if ( V_3 && V_2 -> V_17 -> V_27 )
V_2 -> V_17 -> V_27 ( V_2 -> V_17 , V_3 , V_26 ) ;
if ( V_2 -> V_17 -> V_28 )
F_7 ( & V_2 -> V_29 ) ;
}
static enum V_30 F_8 ( struct V_31 * V_31 )
{
struct V_32 * V_19 =
F_9 ( V_31 , struct V_32 , V_24 ) ;
bool V_33 , V_34 = false ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_19 -> V_36 ; V_35 ++ ) {
struct V_1 * V_2 = & V_19 -> V_37 [ V_35 ] ;
if ( V_2 -> V_16 && V_2 -> V_17 ) {
V_33 = V_2 -> V_19 -> V_20 -> V_38 ( V_2 ) ;
if ( V_33 )
F_6 ( V_2 , 0 ) ;
else
V_34 = true ;
}
}
if ( V_34 ) {
F_10 ( V_31 , F_11 ( V_19 -> V_39 ) ) ;
return V_40 ;
}
return V_41 ;
}
void F_12 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_2 -> V_17 -> V_42 )
V_2 -> V_17 -> V_42 ( V_2 -> V_17 , V_3 ) ;
}
void F_13 ( struct V_1 * V_2 , int V_26 )
{
if ( F_14 ( ! ( V_2 -> V_22 & V_43 ) ) ) {
F_15 ( V_2 -> V_19 -> V_44 ,
L_1 ) ;
return;
}
F_6 ( V_2 , V_26 ) ;
}
void F_16 ( struct V_1 * V_2 , int V_26 )
{
if ( F_14 ( ! ( V_2 -> V_22 & V_45 ) ) ) {
F_15 ( V_2 -> V_19 -> V_44 , L_2 ) ;
return;
}
F_6 ( V_2 , V_26 ) ;
}
bool F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 -> V_20 -> V_46 )
return V_2 -> V_19 -> V_20 -> V_46 ( V_2 ) ;
return false ;
}
int F_18 ( struct V_1 * V_2 , void * V_3 )
{
int V_47 ;
if ( ! V_2 || ! V_2 -> V_17 )
return - V_48 ;
V_47 = F_1 ( V_2 , V_3 ) ;
if ( V_47 < 0 ) {
F_15 ( V_2 -> V_19 -> V_44 , L_3 ) ;
return V_47 ;
}
F_4 ( V_2 ) ;
if ( V_2 -> V_17 -> V_28 && V_2 -> V_16 ) {
unsigned long V_49 ;
int V_50 ;
if ( ! V_2 -> V_17 -> V_51 )
V_49 = F_19 ( 3600000 ) ;
else
V_49 = F_19 ( V_2 -> V_17 -> V_51 ) ;
V_50 = F_20 ( & V_2 -> V_29 , V_49 ) ;
if ( V_50 == 0 ) {
V_47 = - V_52 ;
F_6 ( V_2 , - V_52 ) ;
}
}
return V_47 ;
}
struct V_1 * F_21 ( struct V_53 * V_17 , int V_54 )
{
struct V_55 * V_44 = V_17 -> V_44 ;
struct V_32 * V_19 ;
struct V_56 V_57 ;
struct V_1 * V_2 ;
unsigned long V_5 ;
int V_50 ;
if ( ! V_44 || ! V_44 -> V_58 ) {
F_22 ( L_4 , V_59 ) ;
return F_23 ( - V_60 ) ;
}
F_24 ( & V_61 ) ;
if ( F_25 ( V_44 -> V_58 , L_5 ,
L_6 , V_54 , & V_57 ) ) {
F_26 ( V_44 , L_7 , V_59 ) ;
F_27 ( & V_61 ) ;
return F_23 ( - V_60 ) ;
}
V_2 = F_23 ( - V_62 ) ;
F_28 (mbox, &mbox_cons, node)
if ( V_19 -> V_44 -> V_58 == V_57 . V_63 ) {
V_2 = V_19 -> V_64 ( V_19 , & V_57 ) ;
break;
}
F_29 ( V_57 . V_63 ) ;
if ( F_30 ( V_2 ) ) {
F_27 ( & V_61 ) ;
return V_2 ;
}
if ( V_2 -> V_17 || ! F_31 ( V_19 -> V_44 -> V_65 -> V_66 ) ) {
F_26 ( V_44 , L_8 , V_59 ) ;
F_27 ( & V_61 ) ;
return F_23 ( - V_15 ) ;
}
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = V_17 ;
F_32 ( & V_2 -> V_29 ) ;
if ( V_2 -> V_22 == V_23 && V_17 -> V_67 )
V_2 -> V_22 |= V_45 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_50 = V_2 -> V_19 -> V_20 -> V_68 ( V_2 ) ;
if ( V_50 ) {
F_15 ( V_44 , L_9 , V_50 ) ;
F_33 ( V_2 ) ;
V_2 = F_23 ( V_50 ) ;
}
F_27 ( & V_61 ) ;
return V_2 ;
}
struct V_1 * F_34 ( struct V_53 * V_17 ,
const char * V_69 )
{
struct V_70 * V_63 = V_17 -> V_44 -> V_58 ;
struct V_71 * V_72 ;
const char * V_73 ;
int V_54 = 0 ;
if ( ! V_63 ) {
F_15 ( V_17 -> V_44 , L_10 , V_59 ) ;
return F_23 ( - V_48 ) ;
}
if ( ! F_35 ( V_63 , L_11 , NULL ) ) {
F_15 ( V_17 -> V_44 ,
L_12 , V_59 ) ;
return F_23 ( - V_48 ) ;
}
F_36 (np, L_11 , prop, mbox_name) {
if ( ! strncmp ( V_69 , V_73 , strlen ( V_69 ) ) )
break;
V_54 ++ ;
}
return F_21 ( V_17 , V_54 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
if ( ! V_2 || ! V_2 -> V_17 )
return;
V_2 -> V_19 -> V_20 -> V_74 ( V_2 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_17 = NULL ;
V_2 -> V_16 = NULL ;
if ( V_2 -> V_22 == ( V_23 | V_45 ) )
V_2 -> V_22 = V_23 ;
F_37 ( V_2 -> V_19 -> V_44 -> V_65 -> V_66 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static struct V_1 *
F_38 ( struct V_32 * V_19 ,
const struct V_56 * V_75 )
{
int V_76 = V_75 -> args [ 0 ] ;
if ( V_76 >= V_19 -> V_36 )
return F_23 ( - V_48 ) ;
return & V_19 -> V_37 [ V_76 ] ;
}
int F_39 ( struct V_32 * V_19 )
{
int V_35 , V_33 ;
if ( ! V_19 || ! V_19 -> V_44 || ! V_19 -> V_20 || ! V_19 -> V_36 )
return - V_48 ;
if ( V_19 -> V_77 )
V_33 = V_43 ;
else if ( V_19 -> V_78 )
V_33 = V_23 ;
else
V_33 = V_45 ;
if ( V_33 == V_23 ) {
F_40 ( & V_19 -> V_24 , V_79 ,
V_25 ) ;
V_19 -> V_24 . V_80 = F_8 ;
}
for ( V_35 = 0 ; V_35 < V_19 -> V_36 ; V_35 ++ ) {
struct V_1 * V_2 = & V_19 -> V_37 [ V_35 ] ;
V_2 -> V_17 = NULL ;
V_2 -> V_19 = V_19 ;
V_2 -> V_22 = V_33 ;
F_41 ( & V_2 -> V_6 ) ;
}
if ( ! V_19 -> V_64 )
V_19 -> V_64 = F_38 ;
F_24 ( & V_61 ) ;
F_42 ( & V_19 -> V_81 , & V_82 ) ;
F_27 ( & V_61 ) ;
return 0 ;
}
void F_43 ( struct V_32 * V_19 )
{
int V_35 ;
if ( ! V_19 )
return;
F_24 ( & V_61 ) ;
F_44 ( & V_19 -> V_81 ) ;
for ( V_35 = 0 ; V_35 < V_19 -> V_36 ; V_35 ++ )
F_33 ( & V_19 -> V_37 [ V_35 ] ) ;
if ( V_19 -> V_78 )
F_45 ( & V_19 -> V_24 ) ;
F_27 ( & V_61 ) ;
}
