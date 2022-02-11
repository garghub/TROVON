static void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 , V_3 , V_2 -> V_6 ) ;
if ( V_3 == 0 )
F_3 ( V_2 -> V_5 ) ;
else
F_4 ( V_2 -> V_5 ) ;
}
static void F_5 ( struct V_7 * V_8 ,
enum V_9 V_10 )
{
struct V_1 * V_2 =
F_6 ( V_8 , struct V_1 , V_11 ) ;
unsigned int V_12 = V_2 -> V_11 . V_13 ;
unsigned long long V_4 = V_2 -> V_6 ;
V_4 *= V_10 ;
F_7 ( V_4 , V_12 ) ;
if ( V_2 -> V_14 )
V_4 = V_2 -> V_6 - V_4 ;
V_2 -> V_4 = V_4 ;
F_1 ( V_2 ) ;
}
static int F_8 ( struct V_7 * V_8 ,
enum V_9 V_10 )
{
F_5 ( V_8 , V_10 ) ;
return 0 ;
}
static inline T_1 F_9 ( int V_15 )
{
return sizeof( struct V_16 ) +
( sizeof( struct V_1 ) * V_15 ) ;
}
static void F_10 ( struct V_16 * V_17 )
{
while ( V_17 -> V_15 -- )
F_11 ( & V_17 -> V_18 [ V_17 -> V_15 ] . V_11 ) ;
}
static int F_12 ( struct V_19 * V_20 , struct V_16 * V_17 ,
struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_25 = & V_17 -> V_18 [ V_17 -> V_15 ] ;
struct V_26 V_27 ;
int V_28 ;
V_25 -> V_14 = V_22 -> V_14 ;
V_25 -> V_11 . V_29 = V_22 -> V_29 ;
V_25 -> V_11 . V_30 = V_22 -> V_30 ;
V_25 -> V_11 . V_10 = V_31 ;
V_25 -> V_11 . V_13 = V_22 -> V_13 ;
V_25 -> V_11 . V_32 = V_33 ;
if ( V_24 )
V_25 -> V_5 = F_13 ( V_20 , V_24 , NULL ) ;
else
V_25 -> V_5 = F_14 ( V_20 , V_22 -> V_29 ) ;
if ( F_15 ( V_25 -> V_5 ) ) {
V_28 = F_16 ( V_25 -> V_5 ) ;
F_17 ( V_20 , L_1 ,
V_22 -> V_29 , V_28 ) ;
return V_28 ;
}
V_25 -> V_34 = F_18 ( V_25 -> V_5 ) ;
if ( ! V_25 -> V_34 )
V_25 -> V_11 . V_35 = F_5 ;
else
V_25 -> V_11 . V_36 = F_8 ;
F_19 ( V_25 -> V_5 ) ;
F_20 ( V_25 -> V_5 , & V_27 ) ;
V_25 -> V_6 = V_27 . V_6 ;
if ( ! V_25 -> V_6 && ( V_22 -> V_37 > 0 ) )
V_25 -> V_6 = V_22 -> V_37 ;
V_28 = F_21 ( V_20 , & V_25 -> V_11 ) ;
if ( V_28 == 0 ) {
V_17 -> V_15 ++ ;
F_5 ( & V_25 -> V_11 , V_25 -> V_11 . V_10 ) ;
} else {
F_17 ( V_20 , L_2 ,
V_22 -> V_29 , V_28 ) ;
}
return V_28 ;
}
static int F_22 ( struct V_19 * V_20 , struct V_16 * V_17 )
{
struct V_23 * V_24 ;
struct V_21 V_22 ;
int V_28 = 0 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_23 (dev->of_node, child) {
V_22 . V_29 = F_24 ( V_24 , L_3 , NULL ) ? :
V_24 -> V_29 ;
V_22 . V_30 = F_24 ( V_24 ,
L_4 , NULL ) ;
V_22 . V_14 = F_25 ( V_24 , L_5 ) ;
F_26 ( V_24 , L_6 ,
& V_22 . V_13 ) ;
V_28 = F_12 ( V_20 , V_17 , & V_22 , V_24 ) ;
if ( V_28 ) {
F_27 ( V_24 ) ;
break;
}
}
return V_28 ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_29 ( & V_39 -> V_20 ) ;
struct V_16 * V_17 ;
int V_42 , V_43 ;
int V_28 = 0 ;
if ( V_41 )
V_42 = V_41 -> V_15 ;
else
V_42 = F_30 ( V_39 -> V_20 . V_44 ) ;
if ( ! V_42 )
return - V_45 ;
V_17 = F_31 ( & V_39 -> V_20 , F_9 ( V_42 ) ,
V_46 ) ;
if ( ! V_17 )
return - V_47 ;
if ( V_41 ) {
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_28 = F_12 ( & V_39 -> V_20 , V_17 , & V_41 -> V_18 [ V_43 ] ,
NULL ) ;
if ( V_28 )
break;
}
} else {
V_28 = F_22 ( & V_39 -> V_20 , V_17 ) ;
}
if ( V_28 ) {
F_10 ( V_17 ) ;
return V_28 ;
}
F_32 ( V_39 , V_17 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
struct V_16 * V_17 = F_34 ( V_39 ) ;
F_10 ( V_17 ) ;
return 0 ;
}
