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
unsigned int V_11 ;
unsigned long V_12 ;
if ( V_2 -> V_5 -> V_13 == 0 )
V_11 = V_2 -> V_14 ;
else
V_11 = 2 ;
F_10 ( & V_4 -> V_15 , V_12 ) ;
if ( V_10 )
F_11 ( & V_4 -> V_16 , V_11 , V_2 ) ;
else
F_11 ( & V_4 -> V_16 , V_11 , NULL ) ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
int V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned int V_11 ;
unsigned long V_12 ;
if ( V_2 -> V_5 -> V_13 == 0 )
V_11 = V_2 -> V_14 ;
else
V_11 = 2 ;
F_10 ( & V_4 -> V_15 , V_12 ) ;
if ( V_10 )
F_11 ( & V_4 -> V_17 , V_11 , V_2 ) ;
else
F_11 ( & V_4 -> V_17 , V_11 , NULL ) ;
F_12 ( & V_4 -> V_15 , V_12 ) ;
}
static void F_14 ( struct V_3 * V_4 ,
struct V_18 * V_5 , bool V_19 )
{
struct V_1 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 2 ; ++ V_23 ) {
V_22 = & V_5 -> V_24 [ V_23 ] ;
F_15 (subs, &str->substreams, list) {
if ( ! V_19 ) {
snprintf ( V_20 -> V_25 , sizeof( V_20 -> V_25 ) ,
L_1 ,
V_4 -> V_26 -> V_27 ,
V_20 -> V_14 + 1 ) ;
} else {
snprintf ( V_20 -> V_25 , sizeof( V_20 -> V_25 ) ,
L_2 ,
V_4 -> V_26 -> V_27 ) ;
}
}
}
}
static int F_16 ( struct V_3 * V_4 , unsigned int V_28 ,
unsigned int V_29 , bool V_19 )
{
static const struct V_30 V_31 = {
. V_32 = F_1 ,
. V_33 = F_7 ,
. V_34 = F_9 ,
} ;
static const struct V_30 V_35 = {
. V_32 = F_1 ,
. V_33 = F_7 ,
. V_34 = F_13 ,
} ;
const char * V_36 ;
struct V_18 * V_5 ;
int V_7 ;
V_7 = F_17 ( V_4 -> V_26 , V_4 -> V_26 -> V_37 , V_19 ,
V_28 , V_29 , & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 -> V_6 = V_4 ;
if ( ! V_19 )
V_36 = L_2 ;
else
V_36 = L_3 ;
snprintf ( V_5 -> V_25 , sizeof( V_5 -> V_25 ) , V_36 ,
V_4 -> V_26 -> V_27 ) ;
F_18 ( V_5 , V_38 , & V_35 ) ;
F_18 ( V_5 , V_39 , & V_31 ) ;
V_5 -> V_40 |= V_41 |
V_42 |
V_43 ;
F_14 ( V_4 , V_5 , V_19 ) ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 )
{
int V_7 ;
V_7 = F_16 ( V_4 , V_44 , V_45 ,
false ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_4 -> V_19 )
V_7 = F_16 ( V_4 , 1 , 1 , true ) ;
return V_7 ;
}
