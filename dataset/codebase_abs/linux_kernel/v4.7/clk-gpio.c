static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , 1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 -> V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 -> V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ) ;
return 0 ;
}
static struct V_1 * F_9 ( struct V_7 * V_8 , const char * V_9 ,
const char * const * V_10 , T_1 V_11 , unsigned V_12 ,
bool V_13 , unsigned long V_14 ,
const struct V_15 * V_16 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
struct V_17 V_18 = {} ;
unsigned long V_19 ;
int V_20 ;
if ( V_8 )
V_3 = F_10 ( V_8 , sizeof( * V_3 ) , V_21 ) ;
else
V_3 = F_11 ( sizeof( * V_3 ) , V_21 ) ;
if ( ! V_3 )
return F_12 ( - V_22 ) ;
if ( V_13 )
V_19 = V_23 | V_24 ;
else
V_19 = V_25 ;
if ( V_8 )
V_20 = F_13 ( V_8 , V_12 , V_19 , V_9 ) ;
else
V_20 = F_14 ( V_12 , V_19 , V_9 ) ;
if ( V_20 ) {
if ( V_20 != - V_26 )
F_15 ( L_1 ,
V_27 , V_9 , V_12 ) ;
if ( ! V_8 )
F_16 ( V_3 ) ;
return F_12 ( V_20 ) ;
}
V_18 . V_9 = V_9 ;
V_18 . V_28 = V_16 ;
V_18 . V_14 = V_14 | V_29 ;
V_18 . V_10 = V_10 ;
V_18 . V_11 = V_11 ;
V_3 -> V_5 = F_17 ( V_12 ) ;
V_3 -> V_2 . V_18 = & V_18 ;
V_2 = & V_3 -> V_2 ;
if ( V_8 )
V_20 = F_18 ( V_8 , V_2 ) ;
else
V_20 = F_19 ( NULL , V_2 ) ;
if ( ! V_20 )
return V_2 ;
if ( ! V_8 ) {
F_20 ( V_3 -> V_5 ) ;
F_16 ( V_3 ) ;
}
return F_12 ( V_20 ) ;
}
struct V_1 * F_21 ( struct V_7 * V_8 , const char * V_9 ,
const char * V_30 , unsigned V_12 , bool V_13 ,
unsigned long V_14 )
{
return F_9 ( V_8 , V_9 ,
( V_30 ? & V_30 : NULL ) ,
( V_30 ? 1 : 0 ) , V_12 , V_13 , V_14 ,
& V_31 ) ;
}
struct V_4 * F_22 ( struct V_7 * V_8 , const char * V_9 ,
const char * V_30 , unsigned V_12 , bool V_13 ,
unsigned long V_14 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_8 , V_9 , V_30 , V_12 , V_13 ,
V_14 ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
return V_2 -> V_4 ;
}
struct V_1 * F_25 ( struct V_7 * V_8 , const char * V_9 ,
const char * const * V_10 , T_1 V_11 , unsigned V_12 ,
bool V_13 , unsigned long V_14 )
{
if ( V_11 != 2 ) {
F_15 ( L_2 , V_9 ) ;
return F_12 ( - V_32 ) ;
}
return F_9 ( V_8 , V_9 , V_10 , V_11 ,
V_12 , V_13 , V_14 , & V_33 ) ;
}
struct V_4 * F_26 ( struct V_7 * V_8 , const char * V_9 ,
const char * const * V_10 , T_1 V_11 , unsigned V_12 ,
bool V_13 , unsigned long V_14 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_8 , V_9 , V_10 , V_11 ,
V_12 , V_13 , V_14 ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
return V_2 -> V_4 ;
}
static int F_27 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_8 . V_38 ;
const char * * V_10 , * V_39 ;
unsigned int V_11 ;
int V_12 ;
enum V_40 V_41 ;
struct V_4 * V_4 ;
bool V_13 , V_42 ;
V_11 = F_28 ( V_37 ) ;
if ( V_11 ) {
V_10 = F_29 ( & V_35 -> V_8 , V_11 ,
sizeof( char * ) , V_21 ) ;
if ( ! V_10 )
return - V_22 ;
F_30 ( V_37 , V_10 , V_11 ) ;
} else {
V_10 = NULL ;
}
V_42 = F_31 ( V_37 , L_3 ) ;
V_39 = V_42 ? L_4 : L_5 ;
V_12 = F_32 ( V_37 , V_39 , 0 , & V_41 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_26 )
F_33 ( L_6 ,
V_37 -> V_9 , V_27 ) ;
else
F_15 ( L_7 ,
V_37 -> V_9 , V_27 ,
V_39 ) ;
return V_12 ;
}
V_13 = V_41 & V_43 ;
if ( V_42 )
V_4 = F_26 ( & V_35 -> V_8 , V_37 -> V_9 ,
V_10 , V_11 , V_12 , V_13 , 0 ) ;
else
V_4 = F_22 ( & V_35 -> V_8 , V_37 -> V_9 ,
V_10 ? V_10 [ 0 ] : NULL , V_12 ,
V_13 , 0 ) ;
if ( F_23 ( V_4 ) )
return F_34 ( V_4 ) ;
return F_35 ( V_37 , V_44 , V_4 ) ;
}
