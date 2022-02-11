static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
V_4:
if ( F_2 ( F_3 ( V_1 , V_5 ) == 0 ) )
return - V_6 ;
F_4 ( & V_7 ) ;
V_3 = F_5 ( V_1 , NULL , V_2 ) ;
F_6 ( & V_7 ) ;
if ( F_2 ( V_3 == - V_8 ) )
goto V_4;
else if ( F_2 ( V_3 ) )
return V_3 ;
* V_2 = * V_2 & V_9 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 , int V_2 )
{
F_4 ( & V_7 ) ;
F_8 ( V_1 , V_2 ) ;
F_6 ( & V_7 ) ;
}
static int F_9 ( int V_10 )
{
struct V_11 V_12 ;
return ! F_10 ( & V_12 , V_10 ) ;
}
static unsigned int F_11 ( unsigned int V_10 , unsigned long V_13 )
{
int V_14 = 0 , V_15 = 0 ;
unsigned long V_16 ;
bool V_17 = false ;
struct V_18 * V_19 =
F_12 ( V_10 ) ;
if ( ! V_19 )
return V_14 ;
while ( V_19 [ V_15 ] . V_20 != V_21 ) {
if ( V_19 [ V_15 ] . V_20 == V_22 )
continue;
if ( ( V_19 [ V_15 + 1 ] . V_20 != V_21 ) &&
( V_19 [ V_15 + 1 ] . V_20 < V_19 [ V_15 ] . V_20 )
&& ! V_17 ) {
V_17 = true ;
}
if ( V_17 && V_15 == V_13 )
return V_19 [ V_15 ] . V_20 ;
V_15 ++ ;
}
V_15 -- ;
if ( V_13 > V_15 || V_17 )
return V_14 ;
V_16 = V_15 - V_13 ;
while ( V_15 >= 0 ) {
if ( V_19 [ V_15 ] . V_20 == V_22 )
continue;
if ( V_15 == V_16 )
return V_19 [ V_15 ] . V_20 ;
V_15 -- ;
}
return V_14 ;
}
static int F_13 ( struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_26 , V_27 ;
struct V_28 * V_29 = & V_24 -> V_30 ;
unsigned int V_10 = F_14 ( V_29 ) ;
if ( V_24 -> V_31 == V_25 )
return 0 ;
V_27 = F_11 ( V_10 , V_25 ) ;
if ( ! V_27 )
return - V_32 ;
V_24 -> V_31 = V_25 ;
V_24 -> V_33 = V_27 ;
V_34 = V_24 ;
F_15 (cpuid, maskPtr) {
if ( F_9 ( V_26 ) )
F_16 ( V_26 ) ;
}
V_34 = V_35 ;
return 0 ;
}
static int F_17 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
struct V_11 * V_12 = V_39 ;
unsigned long V_40 = 0 ;
if ( V_38 != V_41 || V_34 == V_35 )
return 0 ;
if ( F_18 ( V_12 -> V_10 , & V_34 -> V_30 ) )
V_40 = V_34 -> V_33 ;
if ( V_40 > V_12 -> V_42 . V_43 )
V_40 = V_12 -> V_42 . V_43 ;
if ( V_12 -> V_43 != V_40 )
F_19 ( V_12 , 0 , V_40 ) ;
return 0 ;
}
static int F_20 ( struct V_44 * V_45 ,
unsigned long * V_46 )
{
struct V_23 * V_24 = V_45 -> V_47 ;
struct V_28 * V_29 = & V_24 -> V_30 ;
unsigned int V_10 ;
struct V_18 * V_19 ;
unsigned long V_48 = 0 ;
int V_15 = 0 ;
V_10 = F_14 ( V_29 ) ;
V_19 = F_12 ( V_10 ) ;
if ( ! V_19 ) {
* V_46 = 0 ;
return 0 ;
}
for ( V_15 = 0 ; ( V_19 [ V_15 ] . V_20 != V_21 ) ; V_15 ++ ) {
if ( V_19 [ V_15 ] . V_20 == V_22 )
continue;
V_48 ++ ;
}
if ( V_48 > 0 ) {
* V_46 = -- V_48 ;
return 0 ;
}
return - V_32 ;
}
static int F_21 ( struct V_44 * V_45 ,
unsigned long * V_46 )
{
struct V_23 * V_24 = V_45 -> V_47 ;
* V_46 = V_24 -> V_31 ;
return 0 ;
}
static int F_22 ( struct V_44 * V_45 ,
unsigned long V_46 )
{
struct V_23 * V_24 = V_45 -> V_47 ;
return F_13 ( V_24 , V_46 ) ;
}
struct V_44 * F_23 (
const struct V_28 * V_49 )
{
struct V_44 * V_50 ;
struct V_23 * V_51 = NULL ;
unsigned int V_52 = 0 , V_43 = 0 ;
char V_53 [ V_54 ] ;
int V_14 = 0 , V_15 ;
struct V_11 V_12 ;
F_15 (i, clip_cpus) {
if ( ! F_10 ( & V_12 , V_15 ) )
continue;
if ( V_52 == 0 && V_43 == 0 ) {
V_52 = V_12 . V_55 . V_56 ;
V_43 = V_12 . V_55 . V_40 ;
} else {
if ( V_52 != V_12 . V_55 . V_56 ||
V_43 != V_12 . V_55 . V_40 )
return F_24 ( - V_32 ) ;
}
}
V_51 = F_25 ( sizeof( struct V_23 ) ,
V_5 ) ;
if ( ! V_51 )
return F_24 ( - V_6 ) ;
F_26 ( & V_51 -> V_30 , V_49 ) ;
V_14 = F_1 ( & V_57 , & V_51 -> V_2 ) ;
if ( V_14 ) {
F_27 ( V_51 ) ;
return F_24 ( - V_32 ) ;
}
sprintf ( V_53 , L_1 , V_51 -> V_2 ) ;
V_50 = F_28 ( V_53 , V_51 ,
& V_58 ) ;
if ( ! V_50 ) {
F_7 ( & V_57 , V_51 -> V_2 ) ;
F_27 ( V_51 ) ;
return F_24 ( - V_32 ) ;
}
V_51 -> V_50 = V_50 ;
V_51 -> V_31 = 0 ;
F_4 ( & V_7 ) ;
if ( V_59 == 0 )
F_29 ( & V_60 ,
V_61 ) ;
V_59 ++ ;
F_6 ( & V_7 ) ;
return V_50 ;
}
void F_30 ( struct V_44 * V_45 )
{
struct V_23 * V_51 = V_45 -> V_47 ;
F_4 ( & V_7 ) ;
V_59 -- ;
if ( V_59 == 0 ) {
F_31 ( & V_60 ,
V_61 ) ;
}
F_6 ( & V_7 ) ;
F_32 ( V_51 -> V_50 ) ;
F_7 ( & V_57 , V_51 -> V_2 ) ;
F_27 ( V_51 ) ;
}
