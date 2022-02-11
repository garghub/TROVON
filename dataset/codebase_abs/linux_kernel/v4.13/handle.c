static T_1 T_2 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
unsigned int V_8 , V_9 ;
for ( V_8 = 0 ; V_5 && V_3 && V_8 < V_2 -> V_6 . V_10 ; V_8 ++ ) {
V_5 = V_2 -> V_6 . V_7 + V_8 ;
for ( V_9 = 0 ; V_5 -> V_11 [ V_9 ] ; V_9 ++ ) {
if ( V_5 -> V_11 [ V_9 ] != V_3 )
continue;
return V_5 -> V_3 ;
}
}
return 0 ;
}
static unsigned int T_2 F_2 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
T_1 V_3 ,
unsigned int * V_14 ,
unsigned int * V_15 )
{
struct V_16 * V_17 = V_2 -> V_6 . V_18 ;
unsigned int V_19 , V_20 ;
unsigned long V_21 , V_22 ;
while ( V_17 && V_3 && * V_14 < V_2 -> V_6 . V_23 ) {
V_17 = V_2 -> V_6 . V_18 + * V_14 ;
for (; * V_15 < F_3 ( V_17 -> V_11 ) ; ( * V_15 ) ++ ) {
if ( V_17 -> V_11 [ * V_15 ] != V_3 )
continue;
if ( V_17 -> V_24 && V_17 -> V_25 ) {
V_19 = V_26 ;
V_20 = V_27 ;
V_21 = V_17 -> V_25 ;
V_22 = V_17 -> V_24 ;
} else {
V_19 = V_28 ;
if ( V_17 -> V_24 ) {
V_20 = V_29 ;
V_21 = V_17 -> V_24 ;
V_22 = V_17 -> V_24 ;
} else {
V_20 = V_30 ;
V_21 = V_17 -> V_25 ;
V_22 = V_17 -> V_25 ;
}
}
V_19 += ( V_17 -> V_31 >> 3 ) - 1 ;
return F_4 ( V_19 , V_20 ,
F_5 ( V_13 , V_21 ) ,
F_5 ( V_13 , V_22 ) ,
1 ,
( V_17 -> V_31 - 1 ) - * V_15 ) ;
}
* V_15 = 0 ;
( * V_14 ) ++ ;
}
return 0 ;
}
unsigned int T_2
F_6 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 V_3 , int V_32 )
{
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
unsigned int V_33 ;
V_33 = F_2 ( V_2 , V_13 , V_3 , & V_8 , & V_9 ) ;
if ( V_33 )
return V_33 ;
if ( V_32 )
return F_6 ( V_2 , V_13 , F_1 ( V_2 , V_3 ) , 0 ) ;
return 0 ;
}
static unsigned int T_2 F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
T_1 V_3 ,
unsigned int * V_14 ,
unsigned int * V_15 )
{
struct V_34 * V_35 = V_2 -> V_6 . V_36 ;
unsigned int V_19 , V_37 , V_20 , V_38 ;
unsigned long V_21 , V_22 ;
while ( V_35 && V_3 && * V_14 < V_2 -> V_6 . V_39 ) {
V_35 = V_2 -> V_6 . V_36 + * V_14 ;
for (; * V_15 < F_3 ( V_35 -> V_11 ) ; ( * V_15 ) ++ ) {
if ( V_35 -> V_11 [ * V_15 ] != V_3 )
continue;
if ( V_35 -> V_24 && V_35 -> V_25 ) {
V_19 = V_26 ;
V_20 = V_40 ;
V_21 = V_35 -> V_24 ;
V_22 = V_35 -> V_25 ;
} else {
V_19 = V_28 ;
V_20 = V_41 ;
if ( ! V_35 -> V_24 )
F_8 () ;
V_21 = V_35 -> V_24 ;
V_22 = V_35 -> V_24 ;
}
V_19 += ( V_35 -> V_31 >> 3 ) - 1 ;
V_37 = * V_15 + 1 ;
F_9 ( V_37 * V_35 -> V_42 > V_35 -> V_31 ) ;
V_38 = V_35 -> V_31 - ( V_37 * V_35 -> V_42 ) ;
return F_4 ( V_19 , V_20 ,
F_5 ( V_13 , V_21 ) ,
F_5 ( V_13 , V_22 ) ,
V_35 -> V_42 , V_38 ) ;
}
* V_15 = 0 ;
( * V_14 ) ++ ;
}
return 0 ;
}
unsigned int T_2
F_10 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 V_3 , int V_32 )
{
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
unsigned int V_33 ;
V_33 = F_7 ( V_2 , V_13 , V_3 , & V_8 , & V_9 ) ;
if ( V_33 )
return V_33 ;
if ( V_32 )
return F_10 ( V_2 , V_13 , F_1 ( V_2 , V_3 ) , 0 ) ;
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_1 V_3 )
{
struct V_16 * V_17 = V_2 -> V_6 . V_43 ;
unsigned int V_8 , V_9 , V_19 , V_20 ;
unsigned long V_21 , V_22 ;
for ( V_8 = 0 ; V_17 && V_3 && V_8 < V_2 -> V_6 . V_44 ; V_8 ++ ) {
V_17 = V_2 -> V_6 . V_43 + V_8 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_17 -> V_11 ) ; V_9 ++ ) {
if ( V_17 -> V_11 [ V_9 ] != V_3 )
continue;
V_19 = V_28 ;
V_20 = V_29 ;
V_21 = V_17 -> V_24 ;
V_22 = V_17 -> V_24 ;
V_19 += ( V_17 -> V_31 >> 3 ) - 1 ;
return F_4 ( V_19 , V_20 ,
F_5 ( V_13 , V_21 ) ,
F_5 ( V_13 , V_22 ) ,
1 ,
( V_17 -> V_31 - 1 ) - V_9 ) ;
}
}
return 0 ;
}
static void F_12 ( struct V_12 * V_13 ,
unsigned long V_45 , int V_46 )
{
unsigned long V_47 ;
unsigned int V_48 ;
unsigned long ( * V_19 ) ( unsigned long , unsigned long ,
unsigned long (*) ( unsigned long , unsigned long ,
unsigned long ) ,
unsigned int ) ;
if ( V_46 ) {
for ( V_48 = 0 ; V_48 < F_13 ( V_13 , F_14 ( V_45 ) ) ; V_48 ++ ) {
V_47 = F_15 ( V_13 , F_14 ( V_45 ) , V_48 ) ;
V_19 = V_49 [ F_16 ( V_45 ) ] ;
V_19 ( V_47 , V_45 , V_50 [ F_17 ( V_45 ) ] , 0 ) ;
}
} else {
for ( V_48 = 0 ; V_48 < F_13 ( V_13 , F_18 ( V_45 ) ) ; V_48 ++ ) {
V_47 = F_15 ( V_13 , F_18 ( V_45 ) , V_48 ) ;
V_19 = V_51 [ F_16 ( V_45 ) ] ;
V_19 ( V_47 , V_45 , V_50 [ F_17 ( V_45 ) ] , 0 ) ;
}
}
}
void T_2 F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
T_1 V_3 , int V_52 )
{
unsigned int V_8 , V_9 , V_53 ;
V_8 = V_9 = 0 ;
do {
V_53 = F_2 ( V_2 , V_13 , V_3 , & V_8 , & V_9 ) ;
if ( V_53 )
F_12 ( V_13 , V_53 , V_52 ) ;
V_9 ++ ;
} while ( V_53 );
V_8 = V_9 = 0 ;
do {
V_53 = F_7 ( V_2 , V_13 , V_3 , & V_8 , & V_9 ) ;
if ( V_53 )
F_12 ( V_13 , V_53 , V_52 ) ;
V_9 ++ ;
} while ( V_53 );
}
unsigned int T_2
F_20 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 V_3 )
{
struct V_54 * V_55 = V_2 -> V_6 . V_56 ;
unsigned int V_8 , V_9 , V_19 , V_38 ;
for ( V_8 = 0 ; V_55 && V_3 && V_8 < V_2 -> V_6 . V_57 ; V_8 ++ ) {
V_55 = V_2 -> V_6 . V_56 + V_8 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_55 -> V_11 ) ; V_9 ++ ) {
if ( V_55 -> V_11 [ V_9 ] != V_3 )
continue;
V_19 = V_28 ;
V_19 += ( V_55 -> V_31 >> 3 ) - 1 ;
F_9 ( ( V_9 + 1 ) * V_55 -> V_42 > V_55 -> V_31 ) ;
V_38 = V_55 -> V_31 - ( ( V_9 + 1 ) * V_55 -> V_42 ) ;
return F_4 ( V_19 , 0 , F_5 ( V_13 , V_55 -> V_58 ) ,
0 , V_55 -> V_42 , V_38 ) ;
}
}
return 0 ;
}
void F_21 ( unsigned int V_59 , struct V_1 * V_2 ,
struct V_12 * V_13 , T_1 V_60 )
{
unsigned long V_61 ;
if ( ! V_2 -> V_6 . V_43 )
return;
F_22 ( & V_62 , V_61 ) ;
V_63 [ V_59 ] = F_11 ( V_2 , V_13 , V_60 ) ;
F_23 ( & V_62 , V_61 ) ;
}
unsigned long F_24 ( unsigned int V_59 )
{
return V_63 [ V_59 ] ;
}
