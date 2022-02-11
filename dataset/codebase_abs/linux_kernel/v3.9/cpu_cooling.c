static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 , NULL , 0 , 0 , V_5 ) ;
F_4 ( & V_4 ) ;
if ( F_5 ( V_3 < 0 ) )
return V_3 ;
* V_2 = V_3 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( & V_4 ) ;
F_7 ( V_1 , V_2 ) ;
F_4 ( & V_4 ) ;
}
static int F_8 ( int V_6 )
{
struct V_7 V_8 ;
return ! F_9 ( & V_8 , V_6 ) ;
}
static unsigned int F_10 ( unsigned int V_6 , unsigned long V_9 )
{
int V_3 = 0 , V_10 = 0 ;
unsigned long V_11 ;
bool V_12 = false ;
struct V_13 * V_14 =
F_11 ( V_6 ) ;
if ( ! V_14 )
return V_3 ;
while ( V_14 [ V_10 ] . V_15 != V_16 ) {
if ( V_14 [ V_10 ] . V_15 == V_17 )
continue;
if ( ( V_14 [ V_10 + 1 ] . V_15 != V_16 ) &&
( V_14 [ V_10 + 1 ] . V_15 < V_14 [ V_10 ] . V_15 )
&& ! V_12 ) {
V_12 = true ;
}
if ( V_12 && V_10 == V_9 )
return V_14 [ V_10 ] . V_15 ;
V_10 ++ ;
}
V_10 -- ;
if ( V_9 > V_10 || V_12 )
return V_3 ;
V_11 = V_10 - V_9 ;
while ( V_10 >= 0 ) {
if ( V_14 [ V_10 ] . V_15 == V_17 )
continue;
if ( V_10 == V_11 )
return V_14 [ V_10 ] . V_15 ;
V_10 -- ;
}
return V_3 ;
}
static int F_12 ( struct V_18 * V_19 ,
unsigned long V_20 )
{
unsigned int V_21 , V_22 ;
struct V_23 * V_24 = & V_19 -> V_25 ;
unsigned int V_6 = F_13 ( V_24 ) ;
if ( V_19 -> V_26 == V_20 )
return 0 ;
V_22 = F_10 ( V_6 , V_20 ) ;
if ( ! V_22 )
return - V_27 ;
V_19 -> V_26 = V_20 ;
V_19 -> V_28 = V_22 ;
V_29 = V_19 ;
F_14 (cpuid, maskPtr) {
if ( F_8 ( V_21 ) )
F_15 ( V_21 ) ;
}
V_29 = V_30 ;
return 0 ;
}
static int F_16 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_7 * V_8 = V_34 ;
unsigned long V_35 = 0 ;
if ( V_33 != V_36 || V_29 == V_30 )
return 0 ;
if ( F_17 ( V_8 -> V_6 , & V_29 -> V_25 ) )
V_35 = V_29 -> V_28 ;
if ( V_35 > V_8 -> V_37 . V_38 )
V_35 = V_8 -> V_37 . V_38 ;
if ( V_8 -> V_38 != V_35 )
F_18 ( V_8 , 0 , V_35 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_40 ,
unsigned long * V_41 )
{
struct V_18 * V_19 = V_40 -> V_42 ;
struct V_23 * V_24 = & V_19 -> V_25 ;
unsigned int V_6 ;
struct V_13 * V_14 ;
unsigned long V_43 = 0 ;
int V_10 = 0 ;
V_6 = F_13 ( V_24 ) ;
V_14 = F_11 ( V_6 ) ;
if ( ! V_14 ) {
* V_41 = 0 ;
return 0 ;
}
for ( V_10 = 0 ; ( V_14 [ V_10 ] . V_15 != V_16 ) ; V_10 ++ ) {
if ( V_14 [ V_10 ] . V_15 == V_17 )
continue;
V_43 ++ ;
}
if ( V_43 > 0 ) {
* V_41 = -- V_43 ;
return 0 ;
}
return - V_27 ;
}
static int F_20 ( struct V_39 * V_40 ,
unsigned long * V_41 )
{
struct V_18 * V_19 = V_40 -> V_42 ;
* V_41 = V_19 -> V_26 ;
return 0 ;
}
static int F_21 ( struct V_39 * V_40 ,
unsigned long V_41 )
{
struct V_18 * V_19 = V_40 -> V_42 ;
return F_12 ( V_19 , V_41 ) ;
}
struct V_39 * F_22 (
const struct V_23 * V_44 )
{
struct V_39 * V_45 ;
struct V_18 * V_46 = NULL ;
unsigned int V_47 = 0 , V_38 = 0 ;
char V_48 [ V_49 ] ;
int V_3 = 0 , V_10 ;
struct V_7 V_8 ;
F_14 (i, clip_cpus) {
if ( ! F_9 ( & V_8 , V_10 ) )
continue;
if ( V_47 == 0 && V_38 == 0 ) {
V_47 = V_8 . V_50 . V_51 ;
V_38 = V_8 . V_50 . V_35 ;
} else {
if ( V_47 != V_8 . V_50 . V_51 ||
V_38 != V_8 . V_50 . V_35 )
return F_23 ( - V_27 ) ;
}
}
V_46 = F_24 ( sizeof( struct V_18 ) ,
V_5 ) ;
if ( ! V_46 )
return F_23 ( - V_52 ) ;
F_25 ( & V_46 -> V_25 , V_44 ) ;
V_3 = F_1 ( & V_53 , & V_46 -> V_2 ) ;
if ( V_3 ) {
F_26 ( V_46 ) ;
return F_23 ( - V_27 ) ;
}
sprintf ( V_48 , L_1 , V_46 -> V_2 ) ;
V_45 = F_27 ( V_48 , V_46 ,
& V_54 ) ;
if ( ! V_45 ) {
F_6 ( & V_53 , V_46 -> V_2 ) ;
F_26 ( V_46 ) ;
return F_23 ( - V_27 ) ;
}
V_46 -> V_45 = V_45 ;
V_46 -> V_26 = 0 ;
F_2 ( & V_4 ) ;
if ( V_55 == 0 )
F_28 ( & V_56 ,
V_57 ) ;
V_55 ++ ;
F_4 ( & V_4 ) ;
return V_45 ;
}
void F_29 ( struct V_39 * V_40 )
{
struct V_18 * V_46 = V_40 -> V_42 ;
F_2 ( & V_4 ) ;
V_55 -- ;
if ( V_55 == 0 ) {
F_30 ( & V_56 ,
V_57 ) ;
}
F_4 ( & V_4 ) ;
F_31 ( V_46 -> V_45 ) ;
F_6 ( & V_53 , V_46 -> V_2 ) ;
F_26 ( V_46 ) ;
}
