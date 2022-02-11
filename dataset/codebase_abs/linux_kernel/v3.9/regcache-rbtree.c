static inline void F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 )
{
* V_5 = V_4 -> V_7 ;
* V_6 = V_4 -> V_7 + ( ( V_4 -> V_8 - 1 ) * V_2 -> V_9 ) ;
}
static unsigned int F_2 (
struct V_3 * V_4 , unsigned int V_10 ,
unsigned int V_11 )
{
return F_3 ( V_4 -> V_12 , V_10 , V_11 ) ;
}
static void F_4 ( struct V_3 * V_4 ,
unsigned int V_10 , unsigned int V_13 ,
unsigned int V_11 )
{
F_5 ( V_4 -> V_12 , V_10 , V_13 , V_11 ) ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned int V_7 , V_20 ;
V_4 = V_16 -> V_21 ;
if ( V_4 ) {
F_1 ( V_2 , V_4 , & V_7 ,
& V_20 ) ;
if ( V_14 >= V_7 && V_14 <= V_20 )
return V_4 ;
}
V_19 = V_16 -> V_22 . V_18 ;
while ( V_19 ) {
V_4 = F_7 ( V_19 , struct V_3 , V_19 ) ;
F_1 ( V_2 , V_4 , & V_7 ,
& V_20 ) ;
if ( V_14 >= V_7 && V_14 <= V_20 ) {
V_16 -> V_21 = V_4 ;
return V_4 ;
} else if ( V_14 > V_20 ) {
V_19 = V_19 -> V_23 ;
} else if ( V_14 < V_7 ) {
V_19 = V_19 -> V_24 ;
}
}
return NULL ;
}
static int F_8 ( struct V_1 * V_2 , struct V_25 * V_22 ,
struct V_3 * V_4 )
{
struct V_18 * * V_26 , * V_27 ;
struct V_3 * V_28 ;
unsigned int V_29 , V_30 ;
unsigned int V_7 ;
V_27 = NULL ;
V_26 = & V_22 -> V_18 ;
while ( * V_26 ) {
V_28 = F_7 ( * V_26 , struct V_3 ,
V_19 ) ;
F_1 ( V_2 , V_28 , & V_29 ,
& V_30 ) ;
V_7 = V_4 -> V_7 ;
V_27 = * V_26 ;
if ( V_7 >= V_29 &&
V_7 <= V_30 )
return 0 ;
else if ( V_7 > V_30 )
V_26 = & ( ( * V_26 ) -> V_23 ) ;
else if ( V_7 < V_29 )
V_26 = & ( ( * V_26 ) -> V_24 ) ;
}
F_9 ( & V_4 -> V_19 , V_27 , V_26 ) ;
F_10 ( & V_4 -> V_19 , V_22 ) ;
return 1 ;
}
static int F_11 ( struct V_31 * V_32 , void * V_33 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_35 ;
struct V_18 * V_19 ;
unsigned int V_5 , V_6 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_38 , V_39 ;
V_2 -> V_40 ( V_2 ) ;
for ( V_19 = F_12 ( & V_16 -> V_22 ) ; V_19 != NULL ;
V_19 = F_13 ( V_19 ) ) {
V_35 = F_7 ( V_19 , struct V_3 , V_19 ) ;
F_1 ( V_2 , V_35 , & V_5 , & V_6 ) ;
V_38 = ( ( V_6 - V_5 ) / V_2 -> V_9 ) + 1 ;
F_14 ( V_32 , L_1 , V_5 , V_6 , V_38 ) ;
V_36 ++ ;
V_37 += V_38 ;
}
if ( V_36 )
V_39 = V_37 / V_36 ;
else
V_39 = 0 ;
F_14 ( V_32 , L_2 ,
V_36 , V_37 , V_39 ) ;
V_2 -> V_41 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
return F_16 ( V_43 , F_11 , V_42 -> V_44 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( L_3 , 0400 , V_2 -> V_45 , V_2 , & V_46 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_47 ;
int V_48 ;
V_2 -> V_17 = F_20 ( sizeof *V_16 , V_49 ) ;
if ( ! V_2 -> V_17 )
return - V_50 ;
V_16 = V_2 -> V_17 ;
V_16 -> V_22 = V_51 ;
V_16 -> V_21 = NULL ;
for ( V_47 = 0 ; V_47 < V_2 -> V_52 ; V_47 ++ ) {
V_48 = F_21 ( V_2 ,
V_2 -> V_53 [ V_47 ] . V_14 ,
V_2 -> V_53 [ V_47 ] . V_54 ) ;
if ( V_48 )
goto V_55;
}
F_17 ( V_2 ) ;
return 0 ;
V_55:
F_22 ( V_2 ) ;
return V_48 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_18 * V_56 ;
struct V_15 * V_16 ;
struct V_3 * V_57 ;
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
return 0 ;
V_56 = F_12 ( & V_16 -> V_22 ) ;
while ( V_56 ) {
V_57 = F_23 ( V_56 , struct V_3 , V_19 ) ;
V_56 = F_13 ( & V_57 -> V_19 ) ;
F_24 ( & V_57 -> V_19 , & V_16 -> V_22 ) ;
F_25 ( V_57 -> V_12 ) ;
F_25 ( V_57 ) ;
}
F_25 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int * V_58 )
{
struct V_3 * V_4 ;
unsigned int V_59 ;
V_4 = F_6 ( V_2 , V_14 ) ;
if ( V_4 ) {
V_59 = ( V_14 - V_4 -> V_7 ) / V_2 -> V_9 ;
* V_58 = F_2 ( V_4 , V_59 ,
V_2 -> V_60 ) ;
} else {
return - V_61 ;
}
return 0 ;
}
static int F_27 ( struct V_3 * V_4 ,
unsigned int V_62 , unsigned int V_14 ,
unsigned int V_58 , unsigned int V_11 )
{
T_1 * V_63 ;
V_63 = F_28 ( V_4 -> V_12 ,
( V_4 -> V_8 + 1 ) * V_11 , V_49 ) ;
if ( ! V_63 )
return - V_50 ;
memmove ( V_63 + ( V_62 + 1 ) * V_11 ,
V_63 + V_62 * V_11 ,
( V_4 -> V_8 - V_62 ) * V_11 ) ;
V_4 -> V_12 = V_63 ;
V_4 -> V_8 ++ ;
if ( ! V_62 )
V_4 -> V_7 = V_14 ;
F_4 ( V_4 , V_62 , V_58 , V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_58 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 , * V_28 ;
struct V_18 * V_19 ;
unsigned int V_13 ;
unsigned int V_59 ;
unsigned int V_62 ;
int V_47 ;
int V_48 ;
V_16 = V_2 -> V_17 ;
V_4 = F_6 ( V_2 , V_14 ) ;
if ( V_4 ) {
V_59 = ( V_14 - V_4 -> V_7 ) / V_2 -> V_9 ;
V_13 = F_2 ( V_4 , V_59 ,
V_2 -> V_60 ) ;
if ( V_13 == V_58 )
return 0 ;
F_4 ( V_4 , V_59 , V_58 ,
V_2 -> V_60 ) ;
} else {
for ( V_19 = F_12 ( & V_16 -> V_22 ) ; V_19 ;
V_19 = F_13 ( V_19 ) ) {
V_28 = F_23 ( V_19 , struct V_3 ,
V_19 ) ;
for ( V_47 = 0 ; V_47 < V_28 -> V_8 ; V_47 ++ ) {
V_59 = V_28 -> V_7 +
( V_47 * V_2 -> V_9 ) ;
if ( abs ( V_59 - V_14 ) != V_2 -> V_9 )
continue;
if ( V_59 + V_2 -> V_9 == V_14 )
V_62 = V_47 + 1 ;
else
V_62 = V_47 ;
V_48 = F_27 ( V_28 , V_62 ,
V_14 , V_58 ,
V_2 -> V_60 ) ;
if ( V_48 )
return V_48 ;
V_16 -> V_21 = V_28 ;
return 0 ;
}
}
V_4 = F_29 ( sizeof *V_4 , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_8 = 1 ;
V_4 -> V_7 = V_14 ;
V_4 -> V_12 = F_20 ( V_4 -> V_8 * V_2 -> V_60 ,
V_49 ) ;
if ( ! V_4 -> V_12 ) {
F_25 ( V_4 ) ;
return - V_50 ;
}
F_4 ( V_4 , 0 , V_58 , V_2 -> V_60 ) ;
F_8 ( V_2 , & V_16 -> V_22 , V_4 ) ;
V_16 -> V_21 = V_4 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_64 ,
unsigned int V_65 )
{
struct V_15 * V_16 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned int V_66 ;
unsigned int V_13 ;
int V_48 ;
int V_47 , V_5 , V_67 ;
V_16 = V_2 -> V_17 ;
for ( V_19 = F_12 ( & V_16 -> V_22 ) ; V_19 ; V_19 = F_13 ( V_19 ) ) {
V_4 = F_23 ( V_19 , struct V_3 , V_19 ) ;
if ( V_4 -> V_7 < V_64 )
continue;
if ( V_4 -> V_7 > V_65 )
break;
if ( V_4 -> V_7 + V_4 -> V_8 < V_64 )
continue;
if ( V_64 > V_4 -> V_7 )
V_5 = V_64 - V_4 -> V_7 ;
else
V_5 = 0 ;
if ( V_65 < V_4 -> V_7 + V_4 -> V_8 )
V_67 = V_65 - V_4 -> V_7 + 1 ;
else
V_67 = V_4 -> V_8 ;
for ( V_47 = V_5 ; V_47 < V_67 ; V_47 ++ ) {
V_66 = V_4 -> V_7 + ( V_47 * V_2 -> V_9 ) ;
V_13 = F_2 ( V_4 , V_47 ,
V_2 -> V_60 ) ;
V_48 = F_31 ( V_2 , V_66 ) ;
if ( V_48 >= 0 && V_13 == V_2 -> V_53 [ V_48 ] . V_54 )
continue;
V_2 -> V_68 = 1 ;
V_48 = F_32 ( V_2 , V_66 , V_13 ) ;
V_2 -> V_68 = 0 ;
if ( V_48 )
return V_48 ;
F_33 ( V_2 -> V_69 , L_4 ,
V_66 , V_13 ) ;
}
}
return 0 ;
}
