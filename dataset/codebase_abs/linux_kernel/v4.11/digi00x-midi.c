static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 ++ ;
V_7 = F_4 ( V_4 , 0 ) ;
F_5 ( & V_4 -> V_8 ) ;
if ( V_7 < 0 )
F_6 ( V_4 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 -- ;
F_8 ( V_4 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned long V_11 ;
F_10 ( & V_4 -> V_12 , V_11 ) ;
if ( V_10 )
F_11 ( & V_4 -> V_13 , V_2 -> V_14 ,
V_2 ) ;
else
F_11 ( & V_4 -> V_13 , V_2 -> V_14 ,
NULL ) ;
F_12 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
int V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned long V_11 ;
F_10 ( & V_4 -> V_12 , V_11 ) ;
if ( V_10 )
F_11 ( & V_4 -> V_15 , V_2 -> V_14 ,
V_2 ) ;
else
F_11 ( & V_4 -> V_15 , V_2 -> V_14 ,
NULL ) ;
F_12 ( & V_4 -> V_12 , V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_17 ( & V_4 -> V_16 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
int V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned long V_11 ;
F_10 ( & V_4 -> V_12 , V_11 ) ;
if ( V_10 )
V_4 -> V_17 = V_2 ;
else
V_4 -> V_17 = NULL ;
F_12 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
int V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned long V_11 ;
F_10 ( & V_4 -> V_12 , V_11 ) ;
if ( V_10 )
F_20 ( & V_4 -> V_16 , V_2 ) ;
F_12 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
bool V_20 )
{
struct V_1 * V_21 ;
F_22 (subs, &str->substreams, list) {
if ( ! V_20 )
snprintf ( V_21 -> V_22 , sizeof( V_21 -> V_22 ) ,
L_1 ,
V_4 -> V_23 -> V_24 , V_21 -> V_14 + 1 ) ;
else
snprintf ( V_21 -> V_22 , sizeof( V_21 -> V_22 ) ,
L_2 ,
V_4 -> V_23 -> V_24 ) ;
}
}
int F_23 ( struct V_3 * V_4 )
{
static const struct V_25 V_26 = {
. V_27 = F_1 ,
. V_28 = F_7 ,
. V_29 = F_9 ,
} ;
static const struct V_25 V_30 = {
. V_27 = F_1 ,
. V_28 = F_7 ,
. V_29 = F_13 ,
} ;
static const struct V_25 V_31 = {
. V_27 = F_14 ,
. V_28 = F_15 ,
. V_29 = F_18 ,
} ;
static const struct V_25 V_32 = {
. V_27 = F_14 ,
. V_28 = F_16 ,
. V_29 = F_19 ,
} ;
struct V_33 * V_5 [ 2 ] ;
struct V_18 * V_19 ;
unsigned int V_34 ;
int V_7 ;
V_7 = F_24 ( V_4 -> V_23 , V_4 -> V_23 -> V_35 , 0 ,
V_36 , V_37 , & V_5 [ 0 ] ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 [ 0 ] -> V_22 , sizeof( V_5 [ 0 ] -> V_22 ) ,
L_3 , V_4 -> V_23 -> V_24 ) ;
F_25 ( V_5 [ 0 ] , V_38 ,
& V_26 ) ;
F_25 ( V_5 [ 0 ] , V_39 ,
& V_30 ) ;
V_7 = F_24 ( V_4 -> V_23 , V_4 -> V_23 -> V_35 , 1 ,
1 , 1 , & V_5 [ 1 ] ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 [ 1 ] -> V_22 , sizeof( V_5 [ 1 ] -> V_22 ) ,
L_2 , V_4 -> V_23 -> V_24 ) ;
F_25 ( V_5 [ 1 ] , V_38 ,
& V_31 ) ;
F_25 ( V_5 [ 1 ] , V_39 ,
& V_32 ) ;
for ( V_34 = 0 ; V_34 < F_26 ( V_5 ) ; V_34 ++ ) {
V_5 [ V_34 ] -> V_6 = V_4 ;
V_5 [ V_34 ] -> V_40 |= V_41 ;
V_19 = & V_5 [ V_34 ] -> V_42 [ V_38 ] ;
F_21 ( V_4 , V_19 , V_34 ) ;
V_5 [ V_34 ] -> V_40 |= V_43 ;
V_19 = & V_5 [ V_34 ] -> V_42 [ V_39 ] ;
F_21 ( V_4 , V_19 , V_34 ) ;
V_5 [ V_34 ] -> V_40 |= V_44 ;
}
return 0 ;
}
