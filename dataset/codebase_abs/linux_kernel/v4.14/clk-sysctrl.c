static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 -> V_6 [ 0 ] , V_5 -> V_7 [ 0 ] ,
V_5 -> V_8 [ 0 ] ) ;
if ( ! V_3 && V_5 -> V_9 )
F_4 ( V_5 -> V_9 , V_5 -> V_9 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_6 ( V_5 -> V_6 [ 0 ] , V_5 -> V_7 [ 0 ] ) )
F_7 ( V_5 -> V_10 , L_1 ,
V_11 , F_8 ( V_2 ) ) ;
}
static unsigned long F_9 ( struct V_1 * V_2 ,
unsigned long V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_13 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_15 = V_5 -> V_16 ;
int V_3 = 0 ;
if ( V_5 -> V_6 [ V_15 ] ) {
V_3 = F_6 ( V_5 -> V_6 [ V_15 ] ,
V_5 -> V_7 [ V_15 ] ) ;
if ( V_3 )
return V_3 ;
}
if ( V_5 -> V_6 [ V_14 ] ) {
V_3 = F_3 ( V_5 -> V_6 [ V_14 ] ,
V_5 -> V_7 [ V_14 ] ,
V_5 -> V_8 [ V_14 ] ) ;
if ( V_3 ) {
if ( V_5 -> V_6 [ V_15 ] )
F_3 ( V_5 -> V_6 [ V_15 ] ,
V_5 -> V_7 [ V_15 ] ,
V_5 -> V_8 [ V_15 ] ) ;
return V_3 ;
}
}
V_5 -> V_16 = V_14 ;
return V_3 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_16 ;
}
static struct V_5 * F_12 ( struct V_17 * V_10 ,
const char * V_18 ,
const char * * V_19 ,
T_1 V_20 ,
T_2 * V_6 ,
T_1 * V_7 ,
T_1 * V_8 ,
unsigned long V_13 ,
unsigned long V_9 ,
unsigned long V_21 ,
const struct V_22 * V_23 )
{
struct V_4 * V_5 ;
struct V_24 V_25 ;
struct V_5 * V_26 ;
int V_27 ;
if ( ! V_10 )
return F_13 ( - V_28 ) ;
if ( ! V_18 || ( V_20 > V_29 ) ) {
F_7 ( V_10 , L_2 ) ;
return F_13 ( - V_28 ) ;
}
V_5 = F_14 ( V_10 , sizeof( struct V_4 ) , V_30 ) ;
if ( ! V_5 ) {
F_7 ( V_10 , L_3 ) ;
return F_13 ( - V_31 ) ;
}
V_5 -> V_6 [ 0 ] = V_6 [ 0 ] ;
V_5 -> V_8 [ 0 ] = V_8 [ 0 ] ;
V_5 -> V_7 [ 0 ] = V_7 [ 0 ] ;
for ( V_27 = 1 ; V_27 < V_20 ; V_27 ++ ) {
V_5 -> V_6 [ V_27 ] = V_6 [ V_27 ] ;
V_5 -> V_8 [ V_27 ] = V_8 [ V_27 ] ;
V_5 -> V_7 [ V_27 ] = V_7 [ V_27 ] ;
}
V_5 -> V_16 = 0 ;
V_5 -> V_13 = V_13 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_10 = V_10 ;
V_25 . V_18 = V_18 ;
V_25 . V_32 = V_23 ;
V_25 . V_21 = V_21 ;
V_25 . V_19 = V_19 ;
V_25 . V_20 = V_20 ;
V_5 -> V_2 . V_33 = & V_25 ;
V_26 = F_15 ( V_5 -> V_10 , & V_5 -> V_2 ) ;
if ( F_16 ( V_26 ) )
F_7 ( V_10 , L_4 ) ;
return V_26 ;
}
struct V_5 * F_17 ( struct V_17 * V_10 ,
const char * V_18 ,
const char * V_34 ,
T_2 V_6 ,
T_1 V_7 ,
T_1 V_8 ,
unsigned long V_9 ,
unsigned long V_21 )
{
const char * * V_19 = ( V_34 ? & V_34 : NULL ) ;
T_1 V_20 = ( V_34 ? 1 : 0 ) ;
return F_12 ( V_10 , V_18 , V_19 , V_20 ,
& V_6 , & V_7 , & V_8 , 0 , V_9 ,
V_21 , & V_35 ) ;
}
struct V_5 * F_18 ( struct V_17 * V_10 ,
const char * V_18 ,
const char * V_34 ,
T_2 V_6 ,
T_1 V_7 ,
T_1 V_8 ,
unsigned long V_13 ,
unsigned long V_9 ,
unsigned long V_21 )
{
const char * * V_19 = ( V_34 ? & V_34 : NULL ) ;
T_1 V_20 = ( V_34 ? 1 : 0 ) ;
return F_12 ( V_10 , V_18 , V_19 , V_20 ,
& V_6 , & V_7 , & V_8 ,
V_13 , V_9 , V_21 ,
& V_36 ) ;
}
struct V_5 * F_19 ( struct V_17 * V_10 ,
const char * V_18 ,
const char * * V_19 ,
T_1 V_20 ,
T_2 * V_6 ,
T_1 * V_7 ,
T_1 * V_8 ,
unsigned long V_21 )
{
return F_12 ( V_10 , V_18 , V_19 , V_20 ,
V_6 , V_7 , V_8 , 0 , 0 , V_21 ,
& V_37 ) ;
}
