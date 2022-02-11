static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , enum V_6 V_7 )
{
V_4 -> V_8 = F_2 ( V_2 , V_7 , V_5 ) ;
if ( ! V_4 -> V_8 )
return - V_9 ;
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_10 , unsigned int V_11 )
{
return F_4 ( V_2 , & V_4 -> V_12 , V_10 ,
V_11 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
unsigned int V_15 , V_16 , V_17 = V_4 -> V_12 . V_10 ;
unsigned int V_18 = F_6 ( V_17 ) ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
V_4 -> V_19 [ V_15 ] = F_7 ( V_20 , V_21 ) ;
if ( ! V_4 -> V_19 [ V_15 ] ) {
F_8 ( L_1 ) ;
return - V_22 ;
}
}
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
V_14 = V_4 -> V_19 [ V_15 ] ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ ) {
V_14 -> V_5 = V_15 * V_23 + V_16 ;
V_14 -> V_24 = ( V_25 * ) V_4 -> V_12 . V_26 +
V_4 -> V_12 . V_11 * V_14 -> V_5 ;
if ( V_14 -> V_5 + 1 == V_17 ) {
V_14 -> V_27 = V_4 -> V_19 [ 0 ] ;
break;
} else if ( V_16 + 1 == V_23 ) {
V_14 -> V_27 = V_4 -> V_19 [ V_15 + 1 ] ;
} else {
V_14 -> V_27 = V_14 + 1 ;
V_14 ++ ;
}
}
}
V_4 -> V_28 = V_4 -> V_29 = V_4 -> V_19 [ 0 ] ;
return 0 ;
}
void F_9 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned int V_15 ;
V_2 = V_4 -> V_2 ;
F_10 ( V_2 , & V_4 -> V_12 ) ;
for ( V_15 = 0 ; V_15 < V_30 ; V_15 ++ ) {
F_11 ( V_4 -> V_19 [ V_15 ] ) ;
V_4 -> V_19 [ V_15 ] = NULL ;
}
V_4 -> V_8 = NULL ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_10 , unsigned int V_11 )
{
int V_31 ;
V_4 -> V_5 = 0 ;
V_4 -> V_2 = V_2 ;
V_31 = F_1 ( V_2 , V_4 , 0 , V_32 ) ;
if ( V_31 ) {
F_8 ( L_2 ) ;
return V_31 ;
}
F_13 ( V_4 ) ;
V_31 = F_3 ( V_2 , V_4 , 0 , V_10 , V_11 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_10 , unsigned int V_11 )
{
int V_31 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_2 ;
V_31 = F_1 ( V_2 , V_4 , V_5 , V_33 ) ;
if ( V_31 ) {
F_8 ( L_3 , V_5 ) ;
return V_31 ;
}
F_13 ( V_4 ) ;
V_31 = F_3 ( V_2 , V_4 , V_5 , V_10 , V_11 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_5 ( V_4 ) ;
if ( V_31 ) {
F_9 ( V_4 ) ;
return V_31 ;
}
return 0 ;
}
void F_15 ( struct V_3 * V_4 , unsigned int V_34 ,
unsigned int V_35 , unsigned int V_36 ,
unsigned int V_37 ,
unsigned int V_38 )
{
T_1 V_39 ;
unsigned int V_17 = V_4 -> V_12 . V_10 ;
V_39 = ( T_1 ) V_4 -> V_12 . V_40 | V_41 ;
F_16 ( V_39 , & V_4 -> V_8 -> V_42 ) ;
F_17 ( V_17 , & V_4 -> V_8 -> V_43 ) ;
F_17 ( V_35 , & V_4 -> V_8 -> V_35 ) ;
F_17 ( V_36 , & V_4 -> V_8 -> V_36 ) ;
F_17 ( V_34 , & V_4 -> V_8 -> V_34 ) ;
F_17 ( V_37 , & V_4 -> V_8 -> V_37 ) ;
F_17 ( V_38 , & V_4 -> V_8 -> V_38 ) ;
F_17 ( 0 , & V_4 -> V_8 -> V_44 ) ;
V_4 -> V_28 = V_4 -> V_29 =
& V_4 -> V_19 [ V_35 / F_18 ( V_17 ) ]
[ V_35 % F_18 ( V_17 ) ] ;
}
void F_19 ( struct V_3 * V_4 , unsigned int V_34 ,
unsigned int V_37 ,
unsigned int V_38 )
{
F_15 ( V_4 , V_34 , 0 , 0 , V_37 ,
V_38 ) ;
}
unsigned int F_20 ( struct V_3 * V_4 )
{
return F_21 ( & V_4 -> V_8 -> V_44 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
F_17 ( 1 , & V_4 -> V_8 -> V_45 ) ;
}
int F_13 ( struct V_3 * V_4 )
{
unsigned int V_46 ;
F_17 ( 0 , & V_4 -> V_8 -> V_45 ) ;
for ( V_46 = 0 ; V_46 < 100 ; V_46 ++ ) {
if ( ! ( F_21 ( & V_4 -> V_8 -> V_47 ) ) )
return 0 ;
F_23 ( 1 ) ;
}
F_8 ( L_4 , V_4 -> V_5 ) ;
return - V_48 ;
}
void F_24 ( struct V_3 * V_4 ,
void (* F_25)( struct V_3 * V_4 , struct V_13 * V_14 ) )
{
struct V_13 * V_14 ;
F_26 ( F_21 ( & V_4 -> V_8 -> V_45 ) ) ;
V_14 = V_4 -> V_29 ;
while ( F_27 ( V_4 ) > 0 ) {
(* F_25)( V_4 , V_14 ) ;
V_14 = V_4 -> V_29 = V_14 -> V_27 ;
V_4 -> V_12 . V_49 ++ ;
}
V_4 -> V_28 = V_4 -> V_29 = V_4 -> V_19 [ 0 ] ;
F_17 ( 0 , & V_4 -> V_8 -> V_35 ) ;
F_17 ( 0 , & V_4 -> V_8 -> V_36 ) ;
F_17 ( 0 , & V_4 -> V_8 -> V_44 ) ;
F_28 ( & V_4 -> V_12 ) ;
}
