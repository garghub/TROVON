static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 = V_2 -> V_10 . V_11 ;
unsigned int V_12 = F_2 ( V_9 ) ;
V_6 = V_2 -> V_6 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
V_2 -> V_13 [ V_7 ] = F_3 ( V_14 , V_15 ) ;
if ( ! V_2 -> V_13 [ V_7 ] ) {
F_4 ( V_16 L_1 ) ;
return - V_17 ;
}
}
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
V_4 = V_2 -> V_13 [ V_7 ] ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
V_4 -> V_19 = V_7 * V_18 + V_8 ;
V_4 -> V_20 = ( V_21 * ) V_2 -> V_10 . V_22 +
V_2 -> V_10 . V_23 * V_4 -> V_19 ;
if ( V_4 -> V_19 + 1 == V_9 ) {
V_4 -> V_24 = V_2 -> V_13 [ 0 ] ;
break;
} else if ( V_8 + 1 == V_18 ) {
V_4 -> V_24 = V_2 -> V_13 [ V_7 + 1 ] ;
} else {
V_4 -> V_24 = V_4 + 1 ;
V_4 ++ ;
}
}
}
V_2 -> V_25 = V_2 -> V_26 = V_2 -> V_13 [ 0 ] ;
V_2 -> V_27 = 0 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
V_6 = V_2 -> V_6 ;
F_6 ( V_6 , & V_2 -> V_10 ) ;
for ( V_7 = 0 ; V_7 < V_28 ; V_7 ++ ) {
F_7 ( V_2 -> V_13 [ V_7 ] ) ;
V_2 -> V_13 [ V_7 ] = NULL ;
}
V_2 -> V_29 = NULL ;
}
int F_8 ( struct V_5 * V_6 , struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_11 , unsigned int V_23 )
{
int V_30 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_29 = F_9 ( V_6 , V_31 , V_19 ) ;
if ( ! V_2 -> V_29 ) {
F_4 ( V_16 L_2 , V_19 ) ;
return - V_32 ;
}
F_10 ( V_2 ) ;
V_30 = F_11 ( V_6 , & V_2 -> V_10 , V_11 , V_23 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_1 ( V_2 ) ;
if ( V_30 ) {
F_5 ( V_2 ) ;
return V_30 ;
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 , unsigned int V_33 ,
unsigned int V_34 ,
unsigned int V_35 )
{
T_1 V_36 ;
T_2 V_37 ;
V_36 = ( T_1 ) V_2 -> V_10 . V_38 | V_39 ;
F_13 ( V_36 , & V_2 -> V_29 -> V_40 ) ;
F_14 ( V_2 -> V_10 . V_11 , & V_2 -> V_29 -> V_41 ) ;
F_14 ( V_33 , & V_2 -> V_29 -> V_33 ) ;
F_14 ( V_34 , & V_2 -> V_29 -> V_34 ) ;
F_14 ( V_35 , & V_2 -> V_29 -> V_35 ) ;
F_14 ( 0 , & V_2 -> V_29 -> V_42 ) ;
F_14 ( 0 , & V_2 -> V_29 -> V_43 ) ;
V_37 = F_15 ( & V_2 -> V_29 -> V_37 ) ;
V_2 -> V_25 = V_2 -> V_26 =
& V_2 -> V_13 [ V_37 / V_18 ]
[ V_37 % V_18 ] ;
F_14 ( V_37 , & V_2 -> V_29 -> V_44 ) ;
V_2 -> V_27 = 0 ;
}
unsigned int F_16 ( struct V_1 * V_2 )
{
return F_15 ( & V_2 -> V_29 -> V_43 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_14 ( 1 , & V_2 -> V_29 -> V_45 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
unsigned int V_46 ;
F_14 ( 0 , & V_2 -> V_29 -> V_45 ) ;
for ( V_46 = 0 ; V_46 < 100 ; V_46 ++ ) {
if ( ! ( F_15 ( & V_2 -> V_29 -> V_47 ) ) )
return 0 ;
F_18 ( 1 ) ;
}
F_4 ( V_16 L_3 , V_2 -> V_19 ) ;
return - V_48 ;
}
void F_19 ( struct V_1 * V_2 ,
void (* F_20)( struct V_1 * V_2 , struct V_3 * V_4 ) )
{
struct V_3 * V_4 ;
T_2 V_37 ;
F_21 ( F_15 ( & V_2 -> V_29 -> V_45 ) ) ;
V_4 = V_2 -> V_26 ;
while ( F_22 ( V_2 ) > 0 ) {
(* F_20)( V_2 , V_4 ) ;
V_4 = V_2 -> V_26 = V_4 -> V_24 ;
V_2 -> V_10 . V_49 ++ ;
}
V_37 = F_15 ( & V_2 -> V_29 -> V_37 ) ;
V_2 -> V_25 = V_2 -> V_26 =
& V_2 -> V_13 [ V_37 / V_18 ]
[ V_37 % V_18 ] ;
F_14 ( V_37 , & V_2 -> V_29 -> V_44 ) ;
V_2 -> V_27 = 0 ;
F_23 ( & V_2 -> V_10 ) ;
}
